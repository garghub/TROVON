static int nwfpe_notify(struct notifier_block *self, unsigned long cmd, void *v)
{
struct thread_info *thread = v;
if (cmd == THREAD_NOTIFY_FLUSH)
nwfpe_init_fpa(&thread->fpstate);
return NOTIFY_DONE;
}
static int __init fpe_init(void)
{
if (sizeof(FPA11) > sizeof(union fp_state)) {
printk(KERN_ERR "nwfpe: bad structure size\n");
return -EINVAL;
}
if (sizeof(FPREG) != 12) {
printk(KERN_ERR "nwfpe: bad register size\n");
return -EINVAL;
}
if (fpe_type[0] && strcmp(fpe_type, "nwfpe"))
return 0;
printk(KERN_WARNING "NetWinder Floating Point Emulator V0.97 ("
NWFPE_BITS " precision)\n");
thread_register_notifier(&nwfpe_notifier_block);
orig_fp_enter = kern_fp_enter;
kern_fp_enter = nwfpe_enter;
return 0;
}
static void __exit fpe_exit(void)
{
thread_unregister_notifier(&nwfpe_notifier_block);
kern_fp_enter = orig_fp_enter;
}
void float_raise(signed char flags)
{
register unsigned int fpsr, cumulativeTraps;
#ifdef CONFIG_DEBUG_USER
if (flags & debug)
printk(KERN_DEBUG
"NWFPE: %s[%d] takes exception %08x at %pf from %08lx\n",
current->comm, current->pid, flags,
__builtin_return_address(0), GET_USERREG()->ARM_pc);
#endif
fpsr = readFPSR();
cumulativeTraps = 0;
if ((!(fpsr & BIT_IXE)) && (flags & BIT_IXC))
cumulativeTraps |= BIT_IXC;
if ((!(fpsr & BIT_UFE)) && (flags & BIT_UFC))
cumulativeTraps |= BIT_UFC;
if ((!(fpsr & BIT_OFE)) && (flags & BIT_OFC))
cumulativeTraps |= BIT_OFC;
if ((!(fpsr & BIT_DZE)) && (flags & BIT_DZC))
cumulativeTraps |= BIT_DZC;
if ((!(fpsr & BIT_IOE)) && (flags & BIT_IOC))
cumulativeTraps |= BIT_IOC;
if (cumulativeTraps)
writeFPSR(fpsr | cumulativeTraps);
if (fpsr & (flags << 16))
fp_send_sig(SIGFPE, current, 1);
}
