void user_disable_single_step(struct task_struct *child)
{
unsigned char exr;
exr = h8300_get_reg(child, PT_EXR);
exr &= ~EXR_TRACE;
h8300_put_reg(child, PT_EXR, exr);
}
void user_enable_single_step(struct task_struct *child)
{
unsigned char exr;
exr = h8300_get_reg(child, PT_EXR);
exr |= EXR_TRACE;
h8300_put_reg(child, PT_EXR, exr);
}
asmlinkage void trace_trap(unsigned long bp)
{
(void)bp;
force_sig(SIGTRAP, current);
}
