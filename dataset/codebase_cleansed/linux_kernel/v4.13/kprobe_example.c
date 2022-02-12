static int handler_pre(struct kprobe *p, struct pt_regs *regs)
{
#ifdef CONFIG_X86
pr_info("<%s> pre_handler: p->addr = 0x%p, ip = %lx, flags = 0x%lx\n",
p->symbol_name, p->addr, regs->ip, regs->flags);
#endif
#ifdef CONFIG_PPC
pr_info("<%s> pre_handler: p->addr = 0x%p, nip = 0x%lx, msr = 0x%lx\n",
p->symbol_name, p->addr, regs->nip, regs->msr);
#endif
#ifdef CONFIG_MIPS
pr_info("<%s> pre_handler: p->addr = 0x%p, epc = 0x%lx, status = 0x%lx\n",
p->symbol_name, p->addr, regs->cp0_epc, regs->cp0_status);
#endif
#ifdef CONFIG_TILEGX
pr_info("<%s> pre_handler: p->addr = 0x%p, pc = 0x%lx, ex1 = 0x%lx\n",
p->symbol_name, p->addr, regs->pc, regs->ex1);
#endif
#ifdef CONFIG_ARM64
pr_info("<%s> pre_handler: p->addr = 0x%p, pc = 0x%lx,"
" pstate = 0x%lx\n",
p->symbol_name, p->addr, (long)regs->pc, (long)regs->pstate);
#endif
return 0;
}
static void handler_post(struct kprobe *p, struct pt_regs *regs,
unsigned long flags)
{
#ifdef CONFIG_X86
pr_info("<%s> post_handler: p->addr = 0x%p, flags = 0x%lx\n",
p->symbol_name, p->addr, regs->flags);
#endif
#ifdef CONFIG_PPC
pr_info("<%s> post_handler: p->addr = 0x%p, msr = 0x%lx\n",
p->symbol_name, p->addr, regs->msr);
#endif
#ifdef CONFIG_MIPS
pr_info("<%s> post_handler: p->addr = 0x%p, status = 0x%lx\n",
p->symbol_name, p->addr, regs->cp0_status);
#endif
#ifdef CONFIG_TILEGX
pr_info("<%s> post_handler: p->addr = 0x%p, ex1 = 0x%lx\n",
p->symbol_name, p->addr, regs->ex1);
#endif
#ifdef CONFIG_ARM64
pr_info("<%s> post_handler: p->addr = 0x%p, pstate = 0x%lx\n",
p->symbol_name, p->addr, (long)regs->pstate);
#endif
}
static int handler_fault(struct kprobe *p, struct pt_regs *regs, int trapnr)
{
pr_info("fault_handler: p->addr = 0x%p, trap #%dn", p->addr, trapnr);
return 0;
}
static int __init kprobe_init(void)
{
int ret;
kp.pre_handler = handler_pre;
kp.post_handler = handler_post;
kp.fault_handler = handler_fault;
ret = register_kprobe(&kp);
if (ret < 0) {
pr_err("register_kprobe failed, returned %d\n", ret);
return ret;
}
pr_info("Planted kprobe at %p\n", kp.addr);
return 0;
}
static void __exit kprobe_exit(void)
{
unregister_kprobe(&kp);
pr_info("kprobe at %p unregistered\n", kp.addr);
}
