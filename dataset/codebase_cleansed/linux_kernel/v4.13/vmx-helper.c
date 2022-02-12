int enter_vmx_usercopy(void)
{
if (in_interrupt())
return 0;
preempt_disable();
pagefault_disable();
enable_kernel_altivec();
return 1;
}
int exit_vmx_usercopy(void)
{
disable_kernel_altivec();
pagefault_enable();
preempt_enable();
return 0;
}
int enter_vmx_copy(void)
{
if (in_interrupt())
return 0;
preempt_disable();
enable_kernel_altivec();
return 1;
}
void *exit_vmx_copy(void *dest)
{
disable_kernel_altivec();
preempt_enable();
return dest;
}
