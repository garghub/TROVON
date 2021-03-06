void ptrace_disable(struct task_struct *child)
{
}
static int genregs32_get(struct task_struct *target,
const struct user_regset *regset,
unsigned int pos, unsigned int count,
void *kbuf, void __user *ubuf)
{
const struct pt_regs *regs = target->thread.kregs;
unsigned long __user *reg_window;
unsigned long *k = kbuf;
unsigned long __user *u = ubuf;
unsigned long reg;
if (target == current)
flush_user_windows();
pos /= sizeof(reg);
count /= sizeof(reg);
if (kbuf) {
for (; count > 0 && pos < 16; count--)
*k++ = regs->u_regs[pos++];
reg_window = (unsigned long __user *) regs->u_regs[UREG_I6];
reg_window -= 16;
for (; count > 0 && pos < 32; count--) {
if (get_user(*k++, &reg_window[pos++]))
return -EFAULT;
}
} else {
for (; count > 0 && pos < 16; count--) {
if (put_user(regs->u_regs[pos++], u++))
return -EFAULT;
}
reg_window = (unsigned long __user *) regs->u_regs[UREG_I6];
reg_window -= 16;
for (; count > 0 && pos < 32; count--) {
if (get_user(reg, &reg_window[pos++]) ||
put_user(reg, u++))
return -EFAULT;
}
}
while (count > 0) {
switch (pos) {
case 32:
reg = regs->psr;
break;
case 33:
reg = regs->pc;
break;
case 34:
reg = regs->npc;
break;
case 35:
reg = regs->y;
break;
case 36:
case 37:
reg = 0;
break;
default:
goto finish;
}
if (kbuf)
*k++ = reg;
else if (put_user(reg, u++))
return -EFAULT;
pos++;
count--;
}
finish:
pos *= sizeof(reg);
count *= sizeof(reg);
return user_regset_copyout_zero(&pos, &count, &kbuf, &ubuf,
38 * sizeof(reg), -1);
}
static int genregs32_set(struct task_struct *target,
const struct user_regset *regset,
unsigned int pos, unsigned int count,
const void *kbuf, const void __user *ubuf)
{
struct pt_regs *regs = target->thread.kregs;
unsigned long __user *reg_window;
const unsigned long *k = kbuf;
const unsigned long __user *u = ubuf;
unsigned long reg;
if (target == current)
flush_user_windows();
pos /= sizeof(reg);
count /= sizeof(reg);
if (kbuf) {
for (; count > 0 && pos < 16; count--)
regs->u_regs[pos++] = *k++;
reg_window = (unsigned long __user *) regs->u_regs[UREG_I6];
reg_window -= 16;
for (; count > 0 && pos < 32; count--) {
if (put_user(*k++, &reg_window[pos++]))
return -EFAULT;
}
} else {
for (; count > 0 && pos < 16; count--) {
if (get_user(reg, u++))
return -EFAULT;
regs->u_regs[pos++] = reg;
}
reg_window = (unsigned long __user *) regs->u_regs[UREG_I6];
reg_window -= 16;
for (; count > 0 && pos < 32; count--) {
if (get_user(reg, u++) ||
put_user(reg, &reg_window[pos++]))
return -EFAULT;
}
}
while (count > 0) {
unsigned long psr;
if (kbuf)
reg = *k++;
else if (get_user(reg, u++))
return -EFAULT;
switch (pos) {
case 32:
psr = regs->psr;
psr &= ~(PSR_ICC | PSR_SYSCALL);
psr |= (reg & (PSR_ICC | PSR_SYSCALL));
regs->psr = psr;
break;
case 33:
regs->pc = reg;
break;
case 34:
regs->npc = reg;
break;
case 35:
regs->y = reg;
break;
case 36:
case 37:
break;
default:
goto finish;
}
pos++;
count--;
}
finish:
pos *= sizeof(reg);
count *= sizeof(reg);
return user_regset_copyin_ignore(&pos, &count, &kbuf, &ubuf,
38 * sizeof(reg), -1);
}
static int fpregs32_get(struct task_struct *target,
const struct user_regset *regset,
unsigned int pos, unsigned int count,
void *kbuf, void __user *ubuf)
{
const unsigned long *fpregs = target->thread.float_regs;
int ret = 0;
#if 0
if (target == current)
save_and_clear_fpu();
#endif
ret = user_regset_copyout(&pos, &count, &kbuf, &ubuf,
fpregs,
0, 32 * sizeof(u32));
if (!ret)
ret = user_regset_copyout_zero(&pos, &count, &kbuf, &ubuf,
32 * sizeof(u32),
33 * sizeof(u32));
if (!ret)
ret = user_regset_copyout(&pos, &count, &kbuf, &ubuf,
&target->thread.fsr,
33 * sizeof(u32),
34 * sizeof(u32));
if (!ret) {
unsigned long val;
val = (1 << 8) | (8 << 16);
ret = user_regset_copyout(&pos, &count, &kbuf, &ubuf,
&val,
34 * sizeof(u32),
35 * sizeof(u32));
}
if (!ret)
ret = user_regset_copyout_zero(&pos, &count, &kbuf, &ubuf,
35 * sizeof(u32), -1);
return ret;
}
static int fpregs32_set(struct task_struct *target,
const struct user_regset *regset,
unsigned int pos, unsigned int count,
const void *kbuf, const void __user *ubuf)
{
unsigned long *fpregs = target->thread.float_regs;
int ret;
#if 0
if (target == current)
save_and_clear_fpu();
#endif
ret = user_regset_copyin(&pos, &count, &kbuf, &ubuf,
fpregs,
0, 32 * sizeof(u32));
if (!ret)
user_regset_copyin_ignore(&pos, &count, &kbuf, &ubuf,
32 * sizeof(u32),
33 * sizeof(u32));
if (!ret && count > 0) {
ret = user_regset_copyin(&pos, &count, &kbuf, &ubuf,
&target->thread.fsr,
33 * sizeof(u32),
34 * sizeof(u32));
}
if (!ret)
ret = user_regset_copyin_ignore(&pos, &count, &kbuf, &ubuf,
34 * sizeof(u32), -1);
return ret;
}
const struct user_regset_view *task_user_regset_view(struct task_struct *task)
{
return &user_sparc32_view;
}
long arch_ptrace(struct task_struct *child, long request,
unsigned long addr, unsigned long data)
{
unsigned long addr2 = current->thread.kregs->u_regs[UREG_I4];
void __user *addr2p;
const struct user_regset_view *view;
struct pt_regs __user *pregs;
struct fps __user *fps;
int ret;
view = task_user_regset_view(current);
addr2p = (void __user *) addr2;
pregs = (struct pt_regs __user *) addr;
fps = (struct fps __user *) addr;
switch(request) {
case PTRACE_GETREGS: {
ret = copy_regset_to_user(child, view, REGSET_GENERAL,
32 * sizeof(u32),
4 * sizeof(u32),
&pregs->psr);
if (!ret)
copy_regset_to_user(child, view, REGSET_GENERAL,
1 * sizeof(u32),
15 * sizeof(u32),
&pregs->u_regs[0]);
break;
}
case PTRACE_SETREGS: {
ret = copy_regset_from_user(child, view, REGSET_GENERAL,
32 * sizeof(u32),
4 * sizeof(u32),
&pregs->psr);
if (!ret)
copy_regset_from_user(child, view, REGSET_GENERAL,
1 * sizeof(u32),
15 * sizeof(u32),
&pregs->u_regs[0]);
break;
}
case PTRACE_GETFPREGS: {
ret = copy_regset_to_user(child, view, REGSET_FP,
0 * sizeof(u32),
32 * sizeof(u32),
&fps->regs[0]);
if (!ret)
ret = copy_regset_to_user(child, view, REGSET_FP,
33 * sizeof(u32),
1 * sizeof(u32),
&fps->fsr);
if (!ret) {
if (__put_user(0, &fps->fpqd) ||
__put_user(0, &fps->flags) ||
__put_user(0, &fps->extra) ||
clear_user(fps->fpq, sizeof(fps->fpq)))
ret = -EFAULT;
}
break;
}
case PTRACE_SETFPREGS: {
ret = copy_regset_from_user(child, view, REGSET_FP,
0 * sizeof(u32),
32 * sizeof(u32),
&fps->regs[0]);
if (!ret)
ret = copy_regset_from_user(child, view, REGSET_FP,
33 * sizeof(u32),
1 * sizeof(u32),
&fps->fsr);
break;
}
case PTRACE_READTEXT:
case PTRACE_READDATA:
ret = ptrace_readdata(child, addr, addr2p, data);
if (ret == data)
ret = 0;
else if (ret >= 0)
ret = -EIO;
break;
case PTRACE_WRITETEXT:
case PTRACE_WRITEDATA:
ret = ptrace_writedata(child, addr2p, addr, data);
if (ret == data)
ret = 0;
else if (ret >= 0)
ret = -EIO;
break;
default:
if (request == PTRACE_SPARC_DETACH)
request = PTRACE_DETACH;
ret = ptrace_request(child, request, addr, data);
break;
}
return ret;
}
asmlinkage int syscall_trace(struct pt_regs *regs, int syscall_exit_p)
{
int ret = 0;
if (test_thread_flag(TIF_SYSCALL_TRACE)) {
if (syscall_exit_p)
tracehook_report_syscall_exit(regs, 0);
else
ret = tracehook_report_syscall_entry(regs);
}
return ret;
}
