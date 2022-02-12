static nokprobe_inline
int __skip_singlestep(struct kprobe *p, struct pt_regs *regs,
struct kprobe_ctlblk *kcb, unsigned long orig_nip)
{
regs->nip = (unsigned long)p->addr + MCOUNT_INSN_SIZE;
if (unlikely(p->post_handler)) {
kcb->kprobe_status = KPROBE_HIT_SSDONE;
p->post_handler(p, regs, 0);
}
__this_cpu_write(current_kprobe, NULL);
if (orig_nip)
regs->nip = orig_nip;
return 1;
}
int skip_singlestep(struct kprobe *p, struct pt_regs *regs,
struct kprobe_ctlblk *kcb)
{
if (kprobe_ftrace(p))
return __skip_singlestep(p, regs, kcb, 0);
else
return 0;
}
void kprobe_ftrace_handler(unsigned long nip, unsigned long parent_nip,
struct ftrace_ops *ops, struct pt_regs *regs)
{
struct kprobe *p;
struct kprobe_ctlblk *kcb;
unsigned long flags;
local_irq_save(flags);
hard_irq_disable();
p = get_kprobe((kprobe_opcode_t *)nip);
if (unlikely(!p) || kprobe_disabled(p))
goto end;
kcb = get_kprobe_ctlblk();
if (kprobe_running()) {
kprobes_inc_nmissed_count(p);
} else {
unsigned long orig_nip = regs->nip;
regs->nip -= MCOUNT_INSN_SIZE;
__this_cpu_write(current_kprobe, p);
kcb->kprobe_status = KPROBE_HIT_ACTIVE;
if (!p->pre_handler || !p->pre_handler(p, regs))
__skip_singlestep(p, regs, kcb, orig_nip);
}
end:
local_irq_restore(flags);
}
int arch_prepare_kprobe_ftrace(struct kprobe *p)
{
p->ainsn.insn = NULL;
p->ainsn.boostable = -1;
return 0;
}
