static unsigned int user_getsp32(unsigned int sp, int is_first)
{
unsigned int stack_frame[2];
void __user *p = compat_ptr(sp);
if (!access_ok(VERIFY_READ, p, sizeof(stack_frame)))
return 0;
if (__copy_from_user_inatomic(stack_frame, p, sizeof(stack_frame)))
return 0;
if (!is_first)
oprofile_add_trace(STACK_LR32(stack_frame));
return STACK_SP(stack_frame);
}
static unsigned long user_getsp64(unsigned long sp, int is_first)
{
unsigned long stack_frame[3];
if (!access_ok(VERIFY_READ, (void __user *)sp, sizeof(stack_frame)))
return 0;
if (__copy_from_user_inatomic(stack_frame, (void __user *)sp,
sizeof(stack_frame)))
return 0;
if (!is_first)
oprofile_add_trace(STACK_LR64(stack_frame));
return STACK_SP(stack_frame);
}
static unsigned long kernel_getsp(unsigned long sp, int is_first)
{
unsigned long *stack_frame = (unsigned long *)sp;
if (!validate_sp(sp, current, STACK_FRAME_OVERHEAD))
return 0;
if (!is_first)
oprofile_add_trace(STACK_LR(stack_frame));
return STACK_SP(stack_frame);
}
void op_powerpc_backtrace(struct pt_regs * const regs, unsigned int depth)
{
unsigned long sp = regs->gpr[1];
int first_frame = 1;
depth += 1;
if (!user_mode(regs)) {
while (depth--) {
sp = kernel_getsp(sp, first_frame);
if (!sp)
break;
first_frame = 0;
}
} else {
pagefault_disable();
#ifdef CONFIG_PPC64
if (!is_32bit_task()) {
while (depth--) {
sp = user_getsp64(sp, first_frame);
if (!sp)
break;
first_frame = 0;
}
pagefault_enable();
return;
}
#endif
while (depth--) {
sp = user_getsp32(sp, first_frame);
if (!sp)
break;
first_frame = 0;
}
pagefault_enable();
}
}
