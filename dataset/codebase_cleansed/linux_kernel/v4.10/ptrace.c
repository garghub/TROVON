void ptrace_disable(struct task_struct *task)
{
clear_tsk_thread_flag(task, TIF_SINGLESTEP);
clear_tsk_thread_flag(task, TIF_BLOCKSTEP);
pa_psw(task)->r = 0;
pa_psw(task)->t = 0;
pa_psw(task)->h = 0;
pa_psw(task)->l = 0;
}
void user_disable_single_step(struct task_struct *task)
{
ptrace_disable(task);
}
void user_enable_single_step(struct task_struct *task)
{
clear_tsk_thread_flag(task, TIF_BLOCKSTEP);
set_tsk_thread_flag(task, TIF_SINGLESTEP);
if (pa_psw(task)->n) {
struct siginfo si;
task_regs(task)->iaoq[0] = task_regs(task)->iaoq[1];
task_regs(task)->iasq[0] = task_regs(task)->iasq[1];
task_regs(task)->iaoq[1] = task_regs(task)->iaoq[0] + 4;
pa_psw(task)->n = 0;
pa_psw(task)->x = 0;
pa_psw(task)->y = 0;
pa_psw(task)->z = 0;
pa_psw(task)->b = 0;
ptrace_disable(task);
si.si_code = TRAP_TRACE;
si.si_addr = (void __user *) (task_regs(task)->iaoq[0] & ~3);
si.si_signo = SIGTRAP;
si.si_errno = 0;
force_sig_info(SIGTRAP, &si, task);
return;
}
pa_psw(task)->r = 1;
pa_psw(task)->t = 0;
pa_psw(task)->h = 0;
pa_psw(task)->l = 0;
}
void user_enable_block_step(struct task_struct *task)
{
clear_tsk_thread_flag(task, TIF_SINGLESTEP);
set_tsk_thread_flag(task, TIF_BLOCKSTEP);
pa_psw(task)->r = 0;
pa_psw(task)->t = 1;
pa_psw(task)->h = 0;
pa_psw(task)->l = 0;
}
long arch_ptrace(struct task_struct *child, long request,
unsigned long addr, unsigned long data)
{
unsigned long __user *datap = (unsigned long __user *)data;
unsigned long tmp;
long ret = -EIO;
switch (request) {
case PTRACE_PEEKUSR:
if ((addr & (sizeof(unsigned long)-1)) ||
addr >= sizeof(struct pt_regs))
break;
tmp = *(unsigned long *) ((char *) task_regs(child) + addr);
ret = put_user(tmp, datap);
break;
case PTRACE_POKEUSR:
if (addr == PT_PSW) {
data &= USER_PSW_BITS;
task_regs(child)->gr[0] &= ~USER_PSW_BITS;
task_regs(child)->gr[0] |= data;
ret = 0;
break;
}
if ((addr & (sizeof(unsigned long)-1)) ||
addr >= sizeof(struct pt_regs))
break;
if ((addr >= PT_GR1 && addr <= PT_GR31) ||
addr == PT_IAOQ0 || addr == PT_IAOQ1 ||
(addr >= PT_FR0 && addr <= PT_FR31 + 4) ||
addr == PT_SAR) {
*(unsigned long *) ((char *) task_regs(child) + addr) = data;
ret = 0;
}
break;
case PTRACE_GETREGS:
return copy_regset_to_user(child,
task_user_regset_view(current),
REGSET_GENERAL,
0, sizeof(struct user_regs_struct),
datap);
case PTRACE_SETREGS:
return copy_regset_from_user(child,
task_user_regset_view(current),
REGSET_GENERAL,
0, sizeof(struct user_regs_struct),
datap);
case PTRACE_GETFPREGS:
return copy_regset_to_user(child,
task_user_regset_view(current),
REGSET_FP,
0, sizeof(struct user_fp_struct),
datap);
case PTRACE_SETFPREGS:
return copy_regset_from_user(child,
task_user_regset_view(current),
REGSET_FP,
0, sizeof(struct user_fp_struct),
datap);
default:
ret = ptrace_request(child, request, addr, data);
break;
}
return ret;
}
static compat_ulong_t translate_usr_offset(compat_ulong_t offset)
{
if (offset < 0)
return sizeof(struct pt_regs);
else if (offset <= 32*4)
return offset * 2 + 4;
else if (offset <= 32*4+32*8)
return offset + 32*4;
else if (offset < sizeof(struct pt_regs)/2 + 32*4)
return offset * 2 + 4 - 32*8;
else
return sizeof(struct pt_regs);
}
long compat_arch_ptrace(struct task_struct *child, compat_long_t request,
compat_ulong_t addr, compat_ulong_t data)
{
compat_uint_t tmp;
long ret = -EIO;
switch (request) {
case PTRACE_PEEKUSR:
if (addr & (sizeof(compat_uint_t)-1))
break;
addr = translate_usr_offset(addr);
if (addr >= sizeof(struct pt_regs))
break;
tmp = *(compat_uint_t *) ((char *) task_regs(child) + addr);
ret = put_user(tmp, (compat_uint_t *) (unsigned long) data);
break;
case PTRACE_POKEUSR:
if (addr == PT_PSW) {
ret = arch_ptrace(child, request, addr, data);
} else {
if (addr & (sizeof(compat_uint_t)-1))
break;
addr = translate_usr_offset(addr);
if (addr >= sizeof(struct pt_regs))
break;
if (addr >= PT_FR0 && addr <= PT_FR31 + 4) {
*(__u64 *) ((char *) task_regs(child) + addr) = data;
ret = 0;
}
else if ((addr >= PT_GR1+4 && addr <= PT_GR31+4) ||
addr == PT_IAOQ0+4 || addr == PT_IAOQ1+4 ||
addr == PT_SAR+4) {
*(__u32 *) ((char *) task_regs(child) + addr - 4) = 0;
*(__u32 *) ((char *) task_regs(child) + addr) = data;
ret = 0;
}
}
break;
default:
ret = compat_ptrace_request(child, request, addr, data);
break;
}
return ret;
}
long do_syscall_trace_enter(struct pt_regs *regs)
{
if (test_thread_flag(TIF_SYSCALL_TRACE) &&
tracehook_report_syscall_entry(regs)) {
regs->gr[20] = -1UL;
goto out;
}
if (secure_computing(NULL) == -1)
return -1;
#ifdef CONFIG_HAVE_SYSCALL_TRACEPOINTS
if (unlikely(test_thread_flag(TIF_SYSCALL_TRACEPOINT)))
trace_sys_enter(regs, regs->gr[20]);
#endif
#ifdef CONFIG_64BIT
if (!is_compat_task())
audit_syscall_entry(regs->gr[20], regs->gr[26], regs->gr[25],
regs->gr[24], regs->gr[23]);
else
#endif
audit_syscall_entry(regs->gr[20] & 0xffffffff,
regs->gr[26] & 0xffffffff,
regs->gr[25] & 0xffffffff,
regs->gr[24] & 0xffffffff,
regs->gr[23] & 0xffffffff);
out:
return (int) ((u32) regs->gr[20]);
}
void do_syscall_trace_exit(struct pt_regs *regs)
{
int stepping = test_thread_flag(TIF_SINGLESTEP) ||
test_thread_flag(TIF_BLOCKSTEP);
audit_syscall_exit(regs);
#ifdef CONFIG_HAVE_SYSCALL_TRACEPOINTS
if (unlikely(test_thread_flag(TIF_SYSCALL_TRACEPOINT)))
trace_sys_exit(regs, regs->gr[20]);
#endif
if (stepping || test_thread_flag(TIF_SYSCALL_TRACE))
tracehook_report_syscall_exit(regs, stepping);
}
static int fpr_get(struct task_struct *target,
const struct user_regset *regset,
unsigned int pos, unsigned int count,
void *kbuf, void __user *ubuf)
{
struct pt_regs *regs = task_regs(target);
__u64 *k = kbuf;
__u64 __user *u = ubuf;
__u64 reg;
pos /= sizeof(reg);
count /= sizeof(reg);
if (kbuf)
for (; count > 0 && pos < ELF_NFPREG; --count)
*k++ = regs->fr[pos++];
else
for (; count > 0 && pos < ELF_NFPREG; --count)
if (__put_user(regs->fr[pos++], u++))
return -EFAULT;
kbuf = k;
ubuf = u;
pos *= sizeof(reg);
count *= sizeof(reg);
return user_regset_copyout_zero(&pos, &count, &kbuf, &ubuf,
ELF_NFPREG * sizeof(reg), -1);
}
static int fpr_set(struct task_struct *target,
const struct user_regset *regset,
unsigned int pos, unsigned int count,
const void *kbuf, const void __user *ubuf)
{
struct pt_regs *regs = task_regs(target);
const __u64 *k = kbuf;
const __u64 __user *u = ubuf;
__u64 reg;
pos /= sizeof(reg);
count /= sizeof(reg);
if (kbuf)
for (; count > 0 && pos < ELF_NFPREG; --count)
regs->fr[pos++] = *k++;
else
for (; count > 0 && pos < ELF_NFPREG; --count) {
if (__get_user(reg, u++))
return -EFAULT;
regs->fr[pos++] = reg;
}
kbuf = k;
ubuf = u;
pos *= sizeof(reg);
count *= sizeof(reg);
return user_regset_copyin_ignore(&pos, &count, &kbuf, &ubuf,
ELF_NFPREG * sizeof(reg), -1);
}
static unsigned long get_reg(struct pt_regs *regs, int num)
{
switch (num) {
case RI(gr[0]) ... RI(gr[31]): return regs->gr[num - RI(gr[0])];
case RI(sr[0]) ... RI(sr[7]): return regs->sr[num - RI(sr[0])];
case RI(iasq[0]): return regs->iasq[0];
case RI(iasq[1]): return regs->iasq[1];
case RI(iaoq[0]): return regs->iaoq[0];
case RI(iaoq[1]): return regs->iaoq[1];
case RI(sar): return regs->sar;
case RI(iir): return regs->iir;
case RI(isr): return regs->isr;
case RI(ior): return regs->ior;
case RI(ipsw): return regs->ipsw;
case RI(cr27): return regs->cr27;
case RI(cr0): return mfctl(0);
case RI(cr24): return mfctl(24);
case RI(cr25): return mfctl(25);
case RI(cr26): return mfctl(26);
case RI(cr28): return mfctl(28);
case RI(cr29): return mfctl(29);
case RI(cr30): return mfctl(30);
case RI(cr31): return mfctl(31);
case RI(cr8): return mfctl(8);
case RI(cr9): return mfctl(9);
case RI(cr12): return mfctl(12);
case RI(cr13): return mfctl(13);
case RI(cr10): return mfctl(10);
case RI(cr15): return mfctl(15);
default: return 0;
}
}
static void set_reg(struct pt_regs *regs, int num, unsigned long val)
{
switch (num) {
case RI(gr[0]):
val &= USER_PSW_BITS;
regs->gr[0] &= ~USER_PSW_BITS;
regs->gr[0] |= val;
return;
case RI(gr[1]) ... RI(gr[31]):
regs->gr[num - RI(gr[0])] = val;
return;
case RI(iaoq[0]):
case RI(iaoq[1]):
regs->iaoq[num - RI(iaoq[0])] = val;
return;
case RI(sar): regs->sar = val;
return;
default: return;
#if 0
case RI(sr[0]) ... RI(sr[7]): return regs->sr[num - RI(sr[0])];
case RI(iasq[0]): return regs->iasq[0];
case RI(iasq[1]): return regs->iasq[1];
case RI(iir): return regs->iir;
case RI(isr): return regs->isr;
case RI(ior): return regs->ior;
case RI(ipsw): return regs->ipsw;
case RI(cr27): return regs->cr27;
case cr0, cr24, cr25, cr26, cr27, cr28, cr29, cr30, cr31;
case cr8, cr9, cr12, cr13, cr10, cr15;
#endif
}
}
static int gpr_get(struct task_struct *target,
const struct user_regset *regset,
unsigned int pos, unsigned int count,
void *kbuf, void __user *ubuf)
{
struct pt_regs *regs = task_regs(target);
unsigned long *k = kbuf;
unsigned long __user *u = ubuf;
unsigned long reg;
pos /= sizeof(reg);
count /= sizeof(reg);
if (kbuf)
for (; count > 0 && pos < ELF_NGREG; --count)
*k++ = get_reg(regs, pos++);
else
for (; count > 0 && pos < ELF_NGREG; --count)
if (__put_user(get_reg(regs, pos++), u++))
return -EFAULT;
kbuf = k;
ubuf = u;
pos *= sizeof(reg);
count *= sizeof(reg);
return user_regset_copyout_zero(&pos, &count, &kbuf, &ubuf,
ELF_NGREG * sizeof(reg), -1);
}
static int gpr_set(struct task_struct *target,
const struct user_regset *regset,
unsigned int pos, unsigned int count,
const void *kbuf, const void __user *ubuf)
{
struct pt_regs *regs = task_regs(target);
const unsigned long *k = kbuf;
const unsigned long __user *u = ubuf;
unsigned long reg;
pos /= sizeof(reg);
count /= sizeof(reg);
if (kbuf)
for (; count > 0 && pos < ELF_NGREG; --count)
set_reg(regs, pos++, *k++);
else
for (; count > 0 && pos < ELF_NGREG; --count) {
if (__get_user(reg, u++))
return -EFAULT;
set_reg(regs, pos++, reg);
}
kbuf = k;
ubuf = u;
pos *= sizeof(reg);
count *= sizeof(reg);
return user_regset_copyin_ignore(&pos, &count, &kbuf, &ubuf,
ELF_NGREG * sizeof(reg), -1);
}
static int gpr32_get(struct task_struct *target,
const struct user_regset *regset,
unsigned int pos, unsigned int count,
void *kbuf, void __user *ubuf)
{
struct pt_regs *regs = task_regs(target);
compat_ulong_t *k = kbuf;
compat_ulong_t __user *u = ubuf;
compat_ulong_t reg;
pos /= sizeof(reg);
count /= sizeof(reg);
if (kbuf)
for (; count > 0 && pos < ELF_NGREG; --count)
*k++ = get_reg(regs, pos++);
else
for (; count > 0 && pos < ELF_NGREG; --count)
if (__put_user((compat_ulong_t) get_reg(regs, pos++), u++))
return -EFAULT;
kbuf = k;
ubuf = u;
pos *= sizeof(reg);
count *= sizeof(reg);
return user_regset_copyout_zero(&pos, &count, &kbuf, &ubuf,
ELF_NGREG * sizeof(reg), -1);
}
static int gpr32_set(struct task_struct *target,
const struct user_regset *regset,
unsigned int pos, unsigned int count,
const void *kbuf, const void __user *ubuf)
{
struct pt_regs *regs = task_regs(target);
const compat_ulong_t *k = kbuf;
const compat_ulong_t __user *u = ubuf;
compat_ulong_t reg;
pos /= sizeof(reg);
count /= sizeof(reg);
if (kbuf)
for (; count > 0 && pos < ELF_NGREG; --count)
set_reg(regs, pos++, *k++);
else
for (; count > 0 && pos < ELF_NGREG; --count) {
if (__get_user(reg, u++))
return -EFAULT;
set_reg(regs, pos++, reg);
}
kbuf = k;
ubuf = u;
pos *= sizeof(reg);
count *= sizeof(reg);
return user_regset_copyin_ignore(&pos, &count, &kbuf, &ubuf,
ELF_NGREG * sizeof(reg), -1);
}
const struct user_regset_view *task_user_regset_view(struct task_struct *task)
{
BUILD_BUG_ON(sizeof(struct user_regs_struct)/sizeof(long) != ELF_NGREG);
BUILD_BUG_ON(sizeof(struct user_fp_struct)/sizeof(__u64) != ELF_NFPREG);
#ifdef CONFIG_64BIT
if (is_compat_task())
return &user_parisc_compat_view;
#endif
return &user_parisc_native_view;
}
