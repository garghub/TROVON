long arch_prctl(struct task_struct *task, int option,
unsigned long __user *arg2)
{
unsigned long *ptr = arg2, tmp;
long ret;
int pid = task->mm->context.id.u.pid;
switch (option) {
case ARCH_SET_FS:
case ARCH_SET_GS:
ret = restore_registers(pid, &current->thread.regs.regs);
if (ret)
return ret;
break;
case ARCH_GET_FS:
case ARCH_GET_GS:
ptr = &tmp;
}
ret = os_arch_prctl(pid, option, ptr);
if (ret)
return ret;
switch (option) {
case ARCH_SET_FS:
current->thread.arch.fs = (unsigned long) ptr;
ret = save_registers(pid, &current->thread.regs.regs);
break;
case ARCH_SET_GS:
ret = save_registers(pid, &current->thread.regs.regs);
break;
case ARCH_GET_FS:
ret = put_user(tmp, arg2);
break;
case ARCH_GET_GS:
ret = put_user(tmp, arg2);
break;
}
return ret;
}
void arch_switch_to(struct task_struct *to)
{
if ((to->thread.arch.fs == 0) || (to->mm == NULL))
return;
arch_prctl(to, ARCH_SET_FS, (void __user *) to->thread.arch.fs);
}
