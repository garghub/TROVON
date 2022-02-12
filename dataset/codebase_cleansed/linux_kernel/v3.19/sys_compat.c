static long
__do_compat_cache_op(unsigned long start, unsigned long end)
{
long ret;
do {
unsigned long chunk = min(PAGE_SIZE, end - start);
if (fatal_signal_pending(current))
return 0;
ret = __flush_cache_user_range(start, start + chunk);
if (ret)
return ret;
cond_resched();
start += chunk;
} while (start < end);
return 0;
}
static inline long
do_compat_cache_op(unsigned long start, unsigned long end, int flags)
{
if (end < start || flags)
return -EINVAL;
if (!access_ok(VERIFY_READ, start, end - start))
return -EFAULT;
return __do_compat_cache_op(start, end);
}
long compat_arm_syscall(struct pt_regs *regs)
{
unsigned int no = regs->regs[7];
switch (no) {
case __ARM_NR_compat_cacheflush:
return do_compat_cache_op(regs->regs[0], regs->regs[1], regs->regs[2]);
case __ARM_NR_compat_set_tls:
current->thread.tp_value = regs->regs[0];
barrier();
asm ("msr tpidrro_el0, %0" : : "r" (regs->regs[0]));
return 0;
default:
return -ENOSYS;
}
}
