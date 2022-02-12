int enter_vmx_copy(void)
{
if (in_interrupt())
return 0;
pagefault_disable();
enable_kernel_altivec();
return 1;
}
int exit_vmx_copy(void)
{
pagefault_enable();
return 0;
}
