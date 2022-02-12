long h8300_get_reg(struct task_struct *task, int regno)
{
switch (regno) {
case PT_USP:
return task->thread.usp + sizeof(long)*2 + 2;
case PT_CCR:
case PT_EXR:
return *(unsigned short *)(task->thread.esp0 + h8300_register_offset[regno]);
default:
return *(unsigned long *)(task->thread.esp0 + h8300_register_offset[regno]);
}
}
int h8300_put_reg(struct task_struct *task, int regno, unsigned long data)
{
unsigned short oldccr;
switch (regno) {
case PT_USP:
task->thread.usp = data - sizeof(long)*2 - 2;
case PT_CCR:
oldccr = *(unsigned short *)(task->thread.esp0 + h8300_register_offset[regno]);
oldccr &= ~CCR_MASK;
data &= CCR_MASK;
data |= oldccr;
*(unsigned short *)(task->thread.esp0 + h8300_register_offset[regno]) = data;
break;
case PT_EXR:
return -EIO;
default:
*(unsigned long *)(task->thread.esp0 + h8300_register_offset[regno]) = data;
break;
}
return 0;
}
void user_disable_single_step(struct task_struct *child)
{
*(unsigned short *)(child->thread.esp0 + h8300_register_offset[PT_EXR]) &= ~EXR_TRACE;
}
void user_enable_single_step(struct task_struct *child)
{
*(unsigned short *)(child->thread.esp0 + h8300_register_offset[PT_EXR]) |= EXR_TRACE;
}
asmlinkage void trace_trap(unsigned long bp)
{
(void)bp;
force_sig(SIGTRAP,current);
}
