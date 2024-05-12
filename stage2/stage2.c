/*
 * Copyright (C) 2024 Andy Nguyen
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

// clang-format off
#define _KERNEL
#include <stddef.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <sys/fcntl.h>
#include <sys/types.h>
#include <sys/sysent.h>
#include <sys/sysproto.h>
#include <sys/syscall.h>
#include <sys/pcpu.h>
#include <sys/proc.h>
#include <sys/filedesc.h>
#include <sys/stat.h>
#include <machine/specialreg.h>
#include "offsets.h"
// clang-format on

#define PS4_PAGE_SIZE 0x4000
#define ROUND_PG(x) (((x) + (PS4_PAGE_SIZE - 1)) & ~(PS4_PAGE_SIZE - 1))

//not only goldhen will exist , making my one
#define PAYLOAD_NAME "payload.bin"
#define PAYLOAD_EXT_PATH "/mnt/usb0/payload.bin" PAYLOAD_NAME
#define PAYLOAD_INT_PATH "/data/payloads/" PAYLOAD_NAME

// by OSM-Made
typedef struct {
  int type;
  int reqId;
  int priority;
  int msgId;
  int targetId;
  int userId;
  int unk1;
  int unk2;
  int appId;
  int errorNum;
  int unk3;
  unsigned char useIconImageUri;
  char message[1024];
  char iconUri[1024];
  char unk[1024];
} OrbisNotificationRequest;

struct sysent *sysents;

static inline uint64_t rdmsr(u_int msr) {
  uint32_t low, high;
  asm volatile("rdmsr" : "=a"(low), "=d"(high) : "c"(msr));
  return (low | ((uint64_t)high << 32));
}

static inline void load_cr0(u_long data) {
  asm volatile("movq %0, %%cr0" ::"r"(data));
}

static inline u_long rcr0(void) {
  u_long data;
  asm volatile("movq %%cr0, %0" : "=r"(data));
  return data;
}

static int ksys_open(struct thread *td, const char *path, int flags, int mode) {
  int (*sys_open)(struct thread *, struct open_args *) = (void *)sysents[SYS_open].sy_call;

  td->td_retval[0] = 0;

  struct open_args uap;
  uap.path = (char *)path;
  uap.flags = flags;
  uap.mode = mode;
  int error = sys_open(td, &uap);
  if (error) return -error;

  return td->td_retval[0];
}

static int ksys_read(struct thread *td, int fd, void *buf, size_t nbytes) {
  int (*sys_read)(struct thread *, struct read_args *) = (void *)sysents[SYS_read].sy_call;

  td->td_retval[0] = 0;

  struct read_args uap;
  uap.fd = fd;
  uap.buf = buf;
  uap.nbyte = nbytes;
  int error = sys_read(td, &uap);
  if (error) return -error;

  return td->td_retval[0];
}

static int ksys_write(struct thread *td, int fd, const void *buf, size_t nbytes) {
  int (*sys_write)(struct thread *, struct write_args *) = (void *)sysents[SYS_write].sy_call;

  td->td_retval[0] = 0;

  struct write_args uap;
  uap.fd = fd;
  uap.buf = buf;
  uap.nbyte = nbytes;
  int error = sys_write(td, &uap);
  if (error) return -error;

  return td->td_retval[0];
}

static int ksys_close(struct thread *td, int fd) {
  int (*sys_close)(struct thread *, struct close_args *) = (void *)sysents[SYS_close].sy_call;

  td->td_retval[0] = 0;

  struct close_args uap;
  uap.fd = fd;
  int error = sys_close(td, &uap);
  if (error) return -error;

  return td->td_retval[0];
}

static int ksys_lseek(struct thread *td, int fd, uint64_t offset, int whence) {
  int (*sys_lseek)(struct thread *, struct lseek_args *) = (void *)sysents[SYS_lseek].sy_call;

  td->td_retval[0] = 0;

  struct lseek_args uap;
  uap.fd = fd;
  uap.offset = offset;
  uap.whence = whence;
  int error = sys_lseek(td, &uap);
  if (error) return -error;

  return td->td_retval[0];
}

static int ksys_unlink(struct thread *td, const char *path) {
  int (*sys_unlink)(struct thread *, struct unlink_args *) = (void *)sysents[SYS_unlink].sy_call;

  td->td_retval[0] = 0;

  struct unlink_args uap;
  uap.path = (char *)path;
  int error = sys_unlink(td, &uap);
  if (error) return -error;

  return td->td_retval[0];
}

static int ksys_access(struct thread *td, struct access_args *uap) {
  int (*sys_access)(struct thread *, struct access_args *) = (void *)sysents[SYS_access].sy_call;

  td->td_retval[0] = 0;

  int error = sys_access(td, uap);
  if (error) return -error;

  return td->td_retval[0];
}

static int ksys_mkdir(struct thread *td, const char *path, int mode) {
  int (*sys_mkdir)(struct thread *, struct mkdir_args *) =
  (void *)sysents[SYS_mkdir].sy_call;

  td->td_retval[0] = 0;

  struct mkdir_args uap;
  uap.path = (char *)path;
  uap.mode = mode;
  int error = sys_mkdir(td, &uap);
  if (error) return -error;

  return td->td_retval[0];
}

static int ksys_stat(struct thread *td, const char *path, struct stat *ub) {
  int (*sys_stat)(struct thread *, struct stat_args *) = (void *)sysents[SYS_stat].sy_call;

  td->td_retval[0] = 0;

  struct stat_args uap;
  uap.path = (char *)path;
  uap.ub = ub;
  int error = sys_stat(td, &uap);
  if (error) return -error;

  return td->td_retval[0];
}

void notify(const char *fmt, ...)
{
  uint64_t kaslr_offset = rdmsr(MSR_LSTAR) - kdlsym_addr_Xfast_syscall;
  int (*sceKernelSendNotificationRequest)(int device, OrbisNotificationRequest* req, int size , int blocking) = (void *)kdlsym(sceKernelSendNotificationRequest);
  int (*vsprintf)(char *, const char *, va_list) = (void *)kdlsym(vsprintf);

  OrbisNotificationRequest buf;

  va_list args;
  va_start(args, fmt);
  vsprintf(buf.message, fmt, args);
  va_end(args);

  buf.type = 0;
  buf.unk3 = 0;
  buf.useIconImageUri = 0;
  buf.targetId = -1;

  sceKernelSendNotificationRequest(0, &buf, sizeof(buf), 0);
}

static void create_dir(struct thread *td, const char *dir) {
  uint64_t kaslr_offset = rdmsr(MSR_LSTAR) - kdlsym_addr_Xfast_syscall;
  int (*snprintf)(char *, size_t , const char *, ...) = (void *)kdlsym(snprintf);
  size_t (*strlen)(const char *) = (void *)kdlsym(strlen);

  char tmp[256];
  char *p = NULL;
  size_t len;

  snprintf(tmp, sizeof(tmp), "%s", dir);
  len = strlen(tmp);

  if (tmp[len - 1] == '/')
    tmp[len - 1] = 0;

  for (p = tmp + 1; *p; p++) {
    if (*p == '/') {
      *p = '\0';
      ksys_mkdir(td, tmp, S_IRWXU);
      *p = '/';
    }
  }

  if (dir[len - 1] == '/') {
    ksys_mkdir(td, tmp, S_IRWXU);
  }
}

int file_exists(struct thread *td, const char *path) {
    struct access_args uap;
    uap.path = (char *)path;
    uap.flags = F_OK;

    return ksys_access(td, &uap) == 0;
}

void file_copy(struct thread *td, char* src, char* dst) {
  uint64_t kaslr_offset = rdmsr(MSR_LSTAR) - kdlsym_addr_Xfast_syscall;
  int (*printf)(const char *format, ...) = (void *)kdlsym(printf);

  if (!file_exists(td, src)) {
    printf("[-] Error: Source file %s does not exist\n", src);
    return;
  }

  create_dir(td, PAYLOAD_INT_PATH);

  int src_fd = ksys_open(td, src, O_RDONLY, 0);
  if (src_fd < 0) {
    printf("[-] Error: Unable to open source file %s\n", src);
    return;
  }

  int dest_fd = ksys_open(td, dst, O_WRONLY | O_CREAT | O_TRUNC, 0644);
  if (dest_fd < 0) {
    printf("[-] Error: Unable to create destination file %s\n", dst);
    ksys_close(td, src_fd);
    return;
  }

  char buffer[1024];
  ssize_t bytes_read;
  ssize_t bytes_written;

  while ((bytes_read = ksys_read(td, src_fd, buffer, sizeof(buffer))) > 0) {
    bytes_written = ksys_write(td, dest_fd, buffer, bytes_read);
    if (bytes_written != bytes_read) {
      printf("[-] Error: Unable to write to destination file %s\n", dst);
      ksys_close(td, src_fd);
      ksys_close(td, dest_fd);
      return;
    }
  }

  if (bytes_read < 0) {
    printf("[-] Error: Unable to read from source file %s\n", src);
    ksys_close(td, src_fd);
    ksys_close(td, dest_fd);
    return;
  }

  ksys_close(td, src_fd);
  ksys_close(td, dest_fd);
}

void exec_payload(struct thread *td, char* payload_path) {
  void *file_buffer;
  size_t file_size;

  uint64_t kaslr_offset = rdmsr(MSR_LSTAR) - kdlsym_addr_Xfast_syscall;

  int (*printf)(const char *format, ...) = (void *)kdlsym(printf);
  void **kernel_map = (void **)kdlsym(kernel_map);
  void *(*kmem_alloc)(void *, uint64_t) = (void *)kdlsym(kmem_alloc);
  void *(*kmem_free)(void *, void *, uint64_t) = (void *)kdlsym(kmem_free);

  int fd = ksys_open(td, payload_path, O_RDONLY, 0);

  if (fd < 0) {
    printf("[-] Error opening the file %s\n", payload_path);
    return;
  }

  off_t file_offset = ksys_lseek(td, fd, 0, SEEK_END);
  ksys_lseek(td, fd, 0, SEEK_SET);

  if (file_offset <= 0) {
    printf("[-] Error getting payload size\n");
    ksys_close(td, fd);
    return;
  }

  file_size = file_offset;
  file_buffer = kmem_alloc(*kernel_map, ROUND_PG(file_size));

  if (file_buffer == NULL) {
    printf("[-] Error creating memory buffer\n");
    ksys_close(td, fd);
    return;
  }

  ssize_t bytes_read = ksys_read(td, fd, file_buffer, file_size);

  if (bytes_read != file_size) {
    printf("[-] Error reading the file\n");
    kmem_free(*kernel_map, file_buffer, ROUND_PG(file_size));
    ksys_close(td, fd);
    return;
  }

  ksys_close(td, fd);

  void (*entry_point)(void) = (void (*)(void))file_buffer;
  entry_point();

  notify("Payload successfully loaded!");
}

void inject_payload(struct thread *td) {
  uint64_t kaslr_offset = rdmsr(MSR_LSTAR) - kdlsym_addr_Xfast_syscall;
  int (*printf)(const char *format, ...) = (void *)kdlsym(printf);

  if (file_exists(td, PAYLOAD_EXT_PATH)) {
    // Updating internal payload copy
    if (file_exists(td, PAYLOAD_INT_PATH)) {
      int result = ksys_unlink(td, PAYLOAD_INT_PATH);

      if (result < 0) {
        printf("[-] Error deleting existing file %s\n", PAYLOAD_INT_PATH);
        return;
      }
    }

    file_copy(td, PAYLOAD_EXT_PATH, PAYLOAD_INT_PATH);
  }

  if (file_exists(td, PAYLOAD_INT_PATH)) {
    exec_payload(td, PAYLOAD_INT_PATH);
  }
}

void stage2(void) {
  uint64_t kaslr_offset = rdmsr(MSR_LSTAR) - kdlsym_addr_Xfast_syscall;

  int (*printf)(const char *format, ...) = (void *)kdlsym(printf);

  sysents = (struct sysent *)kdlsym(sysent);

  printf("stage2\n");

  // Disable write protection
  uint64_t cr0 = rcr0();
  load_cr0(cr0 & ~CR0_WP);

  // Allow syscalls everywhere
  *(uint32_t *)kdlsym(amd_syscall_patch1) = 0;
  *(uint16_t *)kdlsym(amd_syscall_patch2) = 0x9090;
  *(uint16_t *)kdlsym(amd_syscall_patch3) = 0x9090;
  *(uint8_t *)kdlsym(amd_syscall_patch4) = 0xeb;

  // Allow user and kernel addresses
  uint8_t nops[] = {0x90, 0x90, 0x90};

  *(uint16_t *)kdlsym(copyin_patch1) = 0x9090;
  memcpy((void *)kdlsym(copyin_patch2), nops, sizeof(nops));

  *(uint16_t *)kdlsym(copyout_patch1) = 0x9090;
  memcpy((void *)kdlsym(copyout_patch2), nops, sizeof(nops));

  *(uint16_t *)kdlsym(copyinstr_patch1) = 0x9090;
  memcpy((void *)kdlsym(copyinstr_patch2), nops, sizeof(nops));
  *(uint16_t *)kdlsym(copyinstr_patch3) = 0x9090;

  // Restore write protection
  load_cr0(cr0);

  // Send notification
  notify("PPPwned");

  // Inject payload
  struct thread *td = curthread;
  inject_payload(td);
}
