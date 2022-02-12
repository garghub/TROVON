__init void scan_elf_aux( char **envp)
{
long page_size = 0;
elf_auxv_t * auxv;
while ( *envp++ != NULL) ;
for ( auxv = (elf_auxv_t *)envp; auxv->a_type != AT_NULL; auxv++) {
switch ( auxv->a_type ) {
case AT_SYSINFO:
__kernel_vsyscall = auxv->a_un.a_val;
if (__kernel_vsyscall < (unsigned long) envp)
__kernel_vsyscall = 0;
break;
case AT_SYSINFO_EHDR:
vsyscall_ehdr = auxv->a_un.a_val;
if (vsyscall_ehdr < (unsigned long) envp)
vsyscall_ehdr = 0;
break;
case AT_HWCAP:
elf_aux_hwcap = auxv->a_un.a_val;
break;
case AT_PLATFORM:
elf_aux_platform =
(char *) (long) auxv->a_un.a_val;
break;
case AT_PAGESZ:
page_size = auxv->a_un.a_val;
break;
}
}
if ( ! __kernel_vsyscall || ! vsyscall_ehdr ||
! elf_aux_hwcap || ! elf_aux_platform ||
! page_size || (vsyscall_ehdr % page_size) ) {
__kernel_vsyscall = 0;
vsyscall_ehdr = 0;
elf_aux_hwcap = 0;
elf_aux_platform = "i586";
}
else {
vsyscall_end = vsyscall_ehdr + page_size;
}
}
