/*
 * Copyright (C) 2024 Andy Nguyen
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#ifndef __OFFSETS_H__
#define __OFFSETS_H__

#if (FIRMWARE == 700 || FIRMWARE == 701 || FIRMWARE == 702) // FW 7.00 / FW 7.01 / FW 7.02

#define kdlsym_addr_Xfast_syscall 0xffffffff822001c0

#define kdlsym_addr_printf 0xffffffff822bc730

#define kdlsym_addr_sysent 0xffffffff83325660

#define kdlsym_addr_amd_syscall_patch1 0xffffffff82200490
#define kdlsym_addr_amd_syscall_patch2 0xffffffff822004b5
#define kdlsym_addr_amd_syscall_patch3 0xffffffff822004b9
#define kdlsym_addr_amd_syscall_patch4 0xffffffff822004c2

#define kdlsym_addr_copyin_patch1 0xffffffff8222f287
#define kdlsym_addr_copyin_patch2 0xffffffff8222f293

#define kdlsym_addr_copyout_patch1 0xffffffff8222f192
#define kdlsym_addr_copyout_patch2 0xffffffff8222f19e

#define kdlsym_addr_copyinstr_patch1 0xffffffff8222f733
#define kdlsym_addr_copyinstr_patch2 0xffffffff8222f73f
#define kdlsym_addr_copyinstr_patch3 0xffffffff8222f770

#define kdlsym_addr_kernel_map 0xffffffff843c8ee0
#define kdlsym_addr_kmem_alloc 0xffffffff823170f0
#define kdlsym_addr_kmem_free 0xffffffff823172c0

#define kdlsym_addr_sceKernelSendNotificationRequest 0xffffffff8230c900
#define kdlsym_addr_vsprintf 0xffffffff822bca00
#define kdlsym_addr_snprintf 0xffffffff822bca30
#define kdlsym_addr_strlen 0xffffffff82293ff0


#elif (FIRMWARE == 750 || FIRMWARE == 751 || FIRMWARE == 755) // FW 7.50 / FW 7.51 / FW 7.55

#define kdlsym_addr_Xfast_syscall 0xffffffff822001c0

#define kdlsym_addr_printf 0xffffffff8246f740

#define kdlsym_addr_sysent 0xffffffff83322340

#define kdlsym_addr_amd_syscall_patch1 0xffffffff82200490
#define kdlsym_addr_amd_syscall_patch2 0xffffffff822004b5
#define kdlsym_addr_amd_syscall_patch3 0xffffffff822004b9
#define kdlsym_addr_amd_syscall_patch4 0xffffffff822004c2

#define kdlsym_addr_copyin_patch1 0xffffffff8248fa47
#define kdlsym_addr_copyin_patch2 0xffffffff8248fa53

#define kdlsym_addr_copyout_patch1 0xffffffff8248f952
#define kdlsym_addr_copyout_patch2 0xffffffff8248f95e

#define kdlsym_addr_copyinstr_patch1 0xffffffff8248fef3
#define kdlsym_addr_copyinstr_patch2 0xffffffff8248feff
#define kdlsym_addr_copyinstr_patch3 0xffffffff8248ff30

#define kdlsym_addr_kernel_map 0xffffffff843405b8
#define kdlsym_addr_kmem_alloc 0xffffffff823753e0
#define kdlsym_addr_kmem_free 0xffffffff823755b0

#define kdlsym_addr_sceKernelSendNotificationRequest 0xffffffff82659fb0
#define kdlsym_addr_vsprintf 0xffffffff8246fa10
#define kdlsym_addr_snprintf 0xffffffff8246fa40
#define kdlsym_addr_strlen 0xffffffff824e8bc0


#elif (FIRMWARE == 800 || FIRMWARE == 801 || FIRMWARE == 803) // FW 8.00 / 8.01 / 8.03

#define kdlsym_addr_Xfast_syscall 0xffffffff822001c0

#define kdlsym_addr_printf 0xffffffff82630ae0

#define kdlsym_addr_sysent 0xffffffff832fc4d0

#define kdlsym_addr_amd_syscall_patch1 0xffffffff82200490
#define kdlsym_addr_amd_syscall_patch2 0xffffffff822004b5
#define kdlsym_addr_amd_syscall_patch3 0xffffffff822004b9
#define kdlsym_addr_amd_syscall_patch4 0xffffffff822004c2

#define kdlsym_addr_copyin_patch1 0xffffffff8245e407
#define kdlsym_addr_copyin_patch2 0xffffffff8245e413

#define kdlsym_addr_copyout_patch1 0xffffffff8245e312
#define kdlsym_addr_copyout_patch2 0xffffffff8245e31e

#define kdlsym_addr_copyinstr_patch1 0xffffffff8245e8b3
#define kdlsym_addr_copyinstr_patch2 0xffffffff8245e8bf
#define kdlsym_addr_copyinstr_patch3 0xffffffff8245e8f0

#define kdlsym_addr_kernel_map 0xffffffff83d243e0
#define kdlsym_addr_kmem_alloc 0xffffffff8221b3f0
#define kdlsym_addr_kmem_free 0xffffffff8221b5c0

#define kdlsym_addr_sceKernelSendNotificationRequest 0xffffffff823778c0
#define kdlsym_addr_vsprintf 0xffffffff82630db0
#define kdlsym_addr_snprintf 0xffffffff82630de0
#define kdlsym_addr_strlen 0xffffffff824f6090


#elif (FIRMWARE == 850 || FIRMWARE == 852) // FW 8.50 / 8.52

#define kdlsym_addr_Xfast_syscall 0xffffffff822001c0

#define kdlsym_addr_printf 0xffffffff8235d570

#define kdlsym_addr_sysent 0xffffffff832fc5c0

#define kdlsym_addr_amd_syscall_patch1 0xffffffff82200490 // Identical to 9.00
#define kdlsym_addr_amd_syscall_patch2 0xffffffff822004b5 // Identical to 9.00
#define kdlsym_addr_amd_syscall_patch3 0xffffffff822004b9 // Identical to 9.00
#define kdlsym_addr_amd_syscall_patch4 0xffffffff822004c2 // Identical to 9.00

#define kdlsym_addr_copyin_patch1 0xffffffff825a4337
#define kdlsym_addr_copyin_patch2 0xffffffff825a4343

#define kdlsym_addr_copyout_patch1 0xffffffff825a4242
#define kdlsym_addr_copyout_patch2 0xffffffff825a424e

#define kdlsym_addr_copyinstr_patch1 0xffffffff825a47e3
#define kdlsym_addr_copyinstr_patch2 0xffffffff825a47ef
#define kdlsym_addr_copyinstr_patch3 0xffffffff825a4820

#define kdlsym_addr_kernel_map 0xffffffff83e64228
#define kdlsym_addr_kmem_alloc 0xffffffff824199a0
#define kdlsym_addr_kmem_free 0xffffffff82419b70

#define kdlsym_addr_sceKernelSendNotificationRequest 0xffffffff8221bf10
#define kdlsym_addr_vsprintf 0xffffffff8235d840
#define kdlsym_addr_snprintf 0xffffffff8235d870
#define kdlsym_addr_strlen 0xffffffff82470c40


#elif FIRMWARE == 900 // FW 9.00

#define kdlsym_addr_Xfast_syscall 0xffffffff822001c0

#define kdlsym_addr_printf 0xffffffff822b7a30

#define kdlsym_addr_sysent 0xffffffff83300310

#define kdlsym_addr_amd_syscall_patch1 0xffffffff82200490
#define kdlsym_addr_amd_syscall_patch2 0xffffffff822004b5
#define kdlsym_addr_amd_syscall_patch3 0xffffffff822004b9
#define kdlsym_addr_amd_syscall_patch4 0xffffffff822004c2

#define kdlsym_addr_copyin_patch1 0xffffffff824716f7
#define kdlsym_addr_copyin_patch2 0xffffffff82471703

#define kdlsym_addr_copyout_patch1 0xffffffff82471602
#define kdlsym_addr_copyout_patch2 0xffffffff8247160e

#define kdlsym_addr_copyinstr_patch1 0xffffffff82471ba3
#define kdlsym_addr_copyinstr_patch2 0xffffffff82471baf
#define kdlsym_addr_copyinstr_patch3 0xffffffff82471be0

#define kdlsym_addr_kernel_map 0xffffffff84468d48
#define kdlsym_addr_kmem_alloc 0xffffffff8257be70
#define kdlsym_addr_kmem_free 0xffffffff8257c040

#define kdlsym_addr_sceKernelSendNotificationRequest 0xffffffff825a1b30
#define kdlsym_addr_vsprintf 0xffffffff822b7d00
#define kdlsym_addr_snprintf 0xffffffff822b7d30
#define kdlsym_addr_strlen 0xffffffff8250f450


#elif (FIRMWARE == 903 || FIRMWARE == 904) // FW 9.03 / 9.04

#define kdlsym_addr_Xfast_syscall 0xffffffff822001c0 // Identical to 9.00

#define kdlsym_addr_printf 0xffffffff822b79e0

#define kdlsym_addr_sysent 0xffffffff832fc310

#define kdlsym_addr_amd_syscall_patch1 0xffffffff82200490 // Identical to 9.00
#define kdlsym_addr_amd_syscall_patch2 0xffffffff822004b5 // Identical to 9.00
#define kdlsym_addr_amd_syscall_patch3 0xffffffff822004b9 // Identical to 9.00
#define kdlsym_addr_amd_syscall_patch4 0xffffffff822004c2 // Identical to 9.00

#define kdlsym_addr_copyin_patch1 0xffffffff82471377
#define kdlsym_addr_copyin_patch2 0xffffffff82471383

#define kdlsym_addr_copyout_patch1 0xffffffff82471282
#define kdlsym_addr_copyout_patch2 0xffffffff8247128e

#define kdlsym_addr_copyinstr_patch1 0xffffffff82471823
#define kdlsym_addr_copyinstr_patch2 0xffffffff8247182f
#define kdlsym_addr_copyinstr_patch3 0xffffffff82471860

#define kdlsym_addr_kernel_map 0xffffffff84464d48
#define kdlsym_addr_kmem_alloc 0xffffffff8257a070
#define kdlsym_addr_kmem_free 0xffffffff8257a240

#define kdlsym_addr_sceKernelSendNotificationRequest 0xffffffff8259fd30
#define kdlsym_addr_vsprintf 0xffffffff822b7cb0
#define kdlsym_addr_snprintf 0xffffffff822b7ce0
#define kdlsym_addr_strlen 0xffffffff8250f0f0


#elif (FIRMWARE == 950 || FIRMWARE == 951 || FIRMWARE == 960) // FW 9.50 / 9.51 / 9.60

#define kdlsym_addr_Xfast_syscall 0xffffffff822001c0
#define kdlsym_addr_printf 0xffffffff82405470

#define kdlsym_addr_sysent 0xffffffff832f92f0

#define kdlsym_addr_amd_syscall_patch1 0xffffffff82200490
#define kdlsym_addr_amd_syscall_patch2 0xffffffff822004b5
#define kdlsym_addr_amd_syscall_patch3 0xffffffff822004b9
#define kdlsym_addr_amd_syscall_patch4 0xffffffff822004c2

#define kdlsym_addr_copyin_patch1 0xffffffff82401f07
#define kdlsym_addr_copyin_patch2 0xffffffff82401f13

#define kdlsym_addr_copyout_patch1 0xffffffff82401e12
#define kdlsym_addr_copyout_patch2 0xffffffff82401e1e

#define kdlsym_addr_copyinstr_patch1 0xffffffff824023b3
#define kdlsym_addr_copyinstr_patch2 0xffffffff824023bf
#define kdlsym_addr_copyinstr_patch3 0xffffffff824023f0

#define kdlsym_addr_kernel_map 0xffffffff84347830
#define kdlsym_addr_kmem_alloc 0xffffffff823889d0
#define kdlsym_addr_kmem_free 0xffffffff82388ba0

#define kdlsym_addr_sceKernelSendNotificationRequest 0xffffffff82663060
#define kdlsym_addr_vsprintf 0xffffffff82405740
#define kdlsym_addr_snprintf 0xffffffff82405770
#define kdlsym_addr_strlen 0xffffffff825f1980


#elif (FIRMWARE == 1000 || FIRMWARE == 1001) // FW 10.00 / 10.01

#define kdlsym_addr_Xfast_syscall 0xffffffff822001c0
#define kdlsym_addr_printf 0xffffffff822c50f0

#define kdlsym_addr_sysent 0xffffffff83302d90

#define kdlsym_addr_amd_syscall_patch1 0xffffffff82200490
#define kdlsym_addr_amd_syscall_patch2 0xffffffff822004b5
#define kdlsym_addr_amd_syscall_patch3 0xffffffff822004b9
#define kdlsym_addr_amd_syscall_patch4 0xffffffff822004c2

#define kdlsym_addr_copyin_patch1 0xffffffff82672f67
#define kdlsym_addr_copyin_patch2 0xffffffff82672f73

#define kdlsym_addr_copyout_patch1 0xffffffff82672e72
#define kdlsym_addr_copyout_patch2 0xffffffff82672e7e

#define kdlsym_addr_copyinstr_patch1 0xffffffff82673413
#define kdlsym_addr_copyinstr_patch2 0xffffffff8267341f
#define kdlsym_addr_copyinstr_patch3 0xffffffff82673450

#define kdlsym_addr_kernel_map 0xffffffff8447bef8
#define kdlsym_addr_kmem_alloc 0xffffffff8253b040
#define kdlsym_addr_kmem_free 0xffffffff8253b210

#define kdlsym_addr_sceKernelSendNotificationRequest 0xffffffff822f33d0
#define kdlsym_addr_vsprintf 0xffffffff822c53c0
#define kdlsym_addr_snprintf 0xffffffff822c53f0
#define kdlsym_addr_strlen 0xffffffff824e0340


#elif (FIRMWARE == 1050 || FIRMWARE == 1070 || FIRMWARE == 1071) // FW 10.50 / 10.70 / 10.71

#define kdlsym_addr_Xfast_syscall 0xffffffff822001c0
#define kdlsym_addr_printf 0xffffffff82650e80

#define kdlsym_addr_sysent 0xffffffff833029c0

#define kdlsym_addr_amd_syscall_patch1 0xffffffff82200490
#define kdlsym_addr_amd_syscall_patch2 0xffffffff822004b5
#define kdlsym_addr_amd_syscall_patch3 0xffffffff822004b9
#define kdlsym_addr_amd_syscall_patch4 0xffffffff822004c2

#define kdlsym_addr_copyin_patch1 0xffffffff822d75b7
#define kdlsym_addr_copyin_patch2 0xffffffff822d75c3

#define kdlsym_addr_copyout_patch1 0xffffffff822d74c2
#define kdlsym_addr_copyout_patch2 0xffffffff822d74ce

#define kdlsym_addr_copyinstr_patch1 0xffffffff822d7a63
#define kdlsym_addr_copyinstr_patch2 0xffffffff822d7a6f
#define kdlsym_addr_copyinstr_patch3 0xffffffff822d7aa0

#define kdlsym_addr_kernel_map 0xffffffff844a9250
#define kdlsym_addr_kmem_alloc 0xffffffff82628960
#define kdlsym_addr_kmem_free 0xffffffff82628b30

#define kdlsym_addr_sceKernelSendNotificationRequest 0xffffffff823d4950
#define kdlsym_addr_vsprintf 0xffffffff82651150
#define kdlsym_addr_snprintf 0xffffffff82651180
#define kdlsym_addr_strlen 0xffffffff82360da0


#elif FIRMWARE == 1100 // FW 11.00

#define kdlsym_addr_Xfast_syscall 0xffffffff822001c0
#define kdlsym_addr_printf 0xffffffff824fcbd0

#define kdlsym_addr_sysent 0xffffffff83301760

#define kdlsym_addr_amd_syscall_patch1 0xffffffff82200490
#define kdlsym_addr_amd_syscall_patch2 0xffffffff822004b5
#define kdlsym_addr_amd_syscall_patch3 0xffffffff822004b9
#define kdlsym_addr_amd_syscall_patch4 0xffffffff822004c2

#define kdlsym_addr_copyin_patch1 0xffffffff824de037
#define kdlsym_addr_copyin_patch2 0xffffffff824de043

#define kdlsym_addr_copyout_patch1 0xffffffff824ddf42
#define kdlsym_addr_copyout_patch2 0xffffffff824ddf4e

#define kdlsym_addr_copyinstr_patch1 0xffffffff824de4e3
#define kdlsym_addr_copyinstr_patch2 0xffffffff824de4ef
#define kdlsym_addr_copyinstr_patch3 0xffffffff824de520

#define kdlsym_addr_kernel_map 0xffffffff843ff130
#define kdlsym_addr_kmem_alloc 0xffffffff82445e10
#define kdlsym_addr_kmem_free 0xffffffff82445fe0

#define kdlsym_addr_sceKernelSendNotificationRequest 0xffffffff82479960
#define kdlsym_addr_vsprintf 0xffffffff824fcea0
#define kdlsym_addr_snprintf 0xffffffff824fced0
#define kdlsym_addr_strlen 0xffffffff8241dc40


#else

#error "Invalid firmware"

#endif

#define kdlsym(sym) (kaslr_offset + kdlsym_addr_##sym)

#endif
