static int __init vsyscall_setup(char *str)
{
if (str) {
if (!strcmp("emulate", str))
vsyscall_mode = EMULATE;
else if (!strcmp("native", str))
vsyscall_mode = NATIVE;
else if (!strcmp("none", str))
vsyscall_mode = NONE;
else
return -EINVAL;
return 0;
}
return -EINVAL;
}
void update_vsyscall_tz(void)
{
vsyscall_gtod_data.sys_tz = sys_tz;
}
void update_vsyscall(struct timekeeper *tk)
{
struct vsyscall_gtod_data *vdata = &vsyscall_gtod_data;
write_seqcount_begin(&vdata->seq);
vdata->clock.vclock_mode = tk->clock->archdata.vclock_mode;
vdata->clock.cycle_last = tk->clock->cycle_last;
vdata->clock.mask = tk->clock->mask;
vdata->clock.mult = tk->mult;
vdata->clock.shift = tk->shift;
vdata->wall_time_sec = tk->xtime_sec;
vdata->wall_time_snsec = tk->xtime_nsec;
vdata->monotonic_time_sec = tk->xtime_sec
+ tk->wall_to_monotonic.tv_sec;
vdata->monotonic_time_snsec = tk->xtime_nsec
+ (tk->wall_to_monotonic.tv_nsec
<< tk->shift);
while (vdata->monotonic_time_snsec >=
(((u64)NSEC_PER_SEC) << tk->shift)) {
vdata->monotonic_time_snsec -=
((u64)NSEC_PER_SEC) << tk->shift;
vdata->monotonic_time_sec++;
}
vdata->wall_time_coarse.tv_sec = tk->xtime_sec;
vdata->wall_time_coarse.tv_nsec = (long)(tk->xtime_nsec >> tk->shift);
vdata->monotonic_time_coarse = timespec_add(vdata->wall_time_coarse,
tk->wall_to_monotonic);
write_seqcount_end(&vdata->seq);
}
static void warn_bad_vsyscall(const char *level, struct pt_regs *regs,
const char *message)
{
if (!show_unhandled_signals)
return;
pr_notice_ratelimited("%s%s[%d] %s ip:%lx cs:%lx sp:%lx ax:%lx si:%lx di:%lx\n",
level, current->comm, task_pid_nr(current),
message, regs->ip, regs->cs,
regs->sp, regs->ax, regs->si, regs->di);
}
static int addr_to_vsyscall_nr(unsigned long addr)
{
int nr;
if ((addr & ~0xC00UL) != VSYSCALL_START)
return -EINVAL;
nr = (addr & 0xC00UL) >> 10;
if (nr >= 3)
return -EINVAL;
return nr;
}
static int vsyscall_seccomp(struct task_struct *tsk, int syscall_nr)
{
if (!seccomp_mode(&tsk->seccomp))
return 0;
task_pt_regs(tsk)->orig_ax = syscall_nr;
task_pt_regs(tsk)->ax = syscall_nr;
return __secure_computing(syscall_nr);
}
static bool write_ok_or_segv(unsigned long ptr, size_t size)
{
if (!access_ok(VERIFY_WRITE, (void __user *)ptr, size)) {
siginfo_t info;
struct thread_struct *thread = &current->thread;
thread->error_code = 6;
thread->cr2 = ptr;
thread->trap_nr = X86_TRAP_PF;
memset(&info, 0, sizeof(info));
info.si_signo = SIGSEGV;
info.si_errno = 0;
info.si_code = SEGV_MAPERR;
info.si_addr = (void __user *)ptr;
force_sig_info(SIGSEGV, &info, current);
return false;
} else {
return true;
}
}
bool emulate_vsyscall(struct pt_regs *regs, unsigned long address)
{
struct task_struct *tsk;
unsigned long caller;
int vsyscall_nr;
int prev_sig_on_uaccess_error;
long ret;
int skip;
WARN_ON_ONCE(address != regs->ip);
if (vsyscall_mode == NONE) {
warn_bad_vsyscall(KERN_INFO, regs,
"vsyscall attempted with vsyscall=none");
return false;
}
vsyscall_nr = addr_to_vsyscall_nr(address);
trace_emulate_vsyscall(vsyscall_nr);
if (vsyscall_nr < 0) {
warn_bad_vsyscall(KERN_WARNING, regs,
"misaligned vsyscall (exploit attempt or buggy program) -- look up the vsyscall kernel parameter if you need a workaround");
goto sigsegv;
}
if (get_user(caller, (unsigned long __user *)regs->sp) != 0) {
warn_bad_vsyscall(KERN_WARNING, regs,
"vsyscall with bad stack (exploit attempt?)");
goto sigsegv;
}
tsk = current;
prev_sig_on_uaccess_error = current_thread_info()->sig_on_uaccess_error;
current_thread_info()->sig_on_uaccess_error = 1;
ret = -EFAULT;
skip = 0;
switch (vsyscall_nr) {
case 0:
skip = vsyscall_seccomp(tsk, __NR_gettimeofday);
if (skip)
break;
if (!write_ok_or_segv(regs->di, sizeof(struct timeval)) ||
!write_ok_or_segv(regs->si, sizeof(struct timezone)))
break;
ret = sys_gettimeofday(
(struct timeval __user *)regs->di,
(struct timezone __user *)regs->si);
break;
case 1:
skip = vsyscall_seccomp(tsk, __NR_time);
if (skip)
break;
if (!write_ok_or_segv(regs->di, sizeof(time_t)))
break;
ret = sys_time((time_t __user *)regs->di);
break;
case 2:
skip = vsyscall_seccomp(tsk, __NR_getcpu);
if (skip)
break;
if (!write_ok_or_segv(regs->di, sizeof(unsigned)) ||
!write_ok_or_segv(regs->si, sizeof(unsigned)))
break;
ret = sys_getcpu((unsigned __user *)regs->di,
(unsigned __user *)regs->si,
NULL);
break;
}
current_thread_info()->sig_on_uaccess_error = prev_sig_on_uaccess_error;
if (skip) {
if ((long)regs->ax <= 0L)
goto do_ret;
goto done;
}
if (ret == -EFAULT) {
warn_bad_vsyscall(KERN_INFO, regs,
"vsyscall fault (exploit attempt?)");
if (WARN_ON_ONCE(!sigismember(&tsk->pending.signal, SIGBUS) &&
!sigismember(&tsk->pending.signal, SIGSEGV)))
goto sigsegv;
return true;
}
regs->ax = ret;
do_ret:
regs->ip = caller;
regs->sp += 8;
done:
return true;
sigsegv:
force_sig(SIGSEGV, current);
return true;
}
static void __cpuinit vsyscall_set_cpu(int cpu)
{
unsigned long d;
unsigned long node = 0;
#ifdef CONFIG_NUMA
node = cpu_to_node(cpu);
#endif
if (cpu_has(&cpu_data(cpu), X86_FEATURE_RDTSCP))
write_rdtscp_aux((node << 12) | cpu);
d = 0x0f40000000000ULL;
d |= cpu;
d |= (node & 0xf) << 12;
d |= (node >> 4) << 48;
write_gdt_entry(get_cpu_gdt_table(cpu), GDT_ENTRY_PER_CPU, &d, DESCTYPE_S);
}
static void __cpuinit cpu_vsyscall_init(void *arg)
{
vsyscall_set_cpu(raw_smp_processor_id());
}
static int __cpuinit
cpu_vsyscall_notifier(struct notifier_block *n, unsigned long action, void *arg)
{
long cpu = (long)arg;
if (action == CPU_ONLINE || action == CPU_ONLINE_FROZEN)
smp_call_function_single(cpu, cpu_vsyscall_init, NULL, 1);
return NOTIFY_DONE;
}
void __init map_vsyscall(void)
{
extern char __vsyscall_page;
unsigned long physaddr_vsyscall = __pa_symbol(&__vsyscall_page);
extern char __vvar_page;
unsigned long physaddr_vvar_page = __pa_symbol(&__vvar_page);
__set_fixmap(VSYSCALL_FIRST_PAGE, physaddr_vsyscall,
vsyscall_mode == NATIVE
? PAGE_KERNEL_VSYSCALL
: PAGE_KERNEL_VVAR);
BUILD_BUG_ON((unsigned long)__fix_to_virt(VSYSCALL_FIRST_PAGE) !=
(unsigned long)VSYSCALL_START);
__set_fixmap(VVAR_PAGE, physaddr_vvar_page, PAGE_KERNEL_VVAR);
BUILD_BUG_ON((unsigned long)__fix_to_virt(VVAR_PAGE) !=
(unsigned long)VVAR_ADDRESS);
}
static int __init vsyscall_init(void)
{
BUG_ON(VSYSCALL_ADDR(0) != __fix_to_virt(VSYSCALL_FIRST_PAGE));
on_each_cpu(cpu_vsyscall_init, NULL, 1);
hotcpu_notifier(cpu_vsyscall_notifier, 30);
return 0;
}
