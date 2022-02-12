void arch_uprobe_copy_ixol(struct page *page, unsigned long vaddr,
void *src, unsigned long len)
{
void *xol_page_kaddr = kmap_atomic(page);
void *dst = xol_page_kaddr + (vaddr & ~PAGE_MASK);
memcpy(dst, src, len);
sync_icache_aliases(dst, len);
kunmap_atomic(xol_page_kaddr);
}
unsigned long uprobe_get_swbp_addr(struct pt_regs *regs)
{
return instruction_pointer(regs);
}
int arch_uprobe_analyze_insn(struct arch_uprobe *auprobe, struct mm_struct *mm,
unsigned long addr)
{
probe_opcode_t insn;
if (mm->context.flags & MMCF_AARCH32)
return -ENOTSUPP;
else if (!IS_ALIGNED(addr, AARCH64_INSN_SIZE))
return -EINVAL;
insn = *(probe_opcode_t *)(&auprobe->insn[0]);
switch (arm_probe_decode_insn(insn, &auprobe->api)) {
case INSN_REJECTED:
return -EINVAL;
case INSN_GOOD_NO_SLOT:
auprobe->simulate = true;
break;
default:
break;
}
return 0;
}
int arch_uprobe_pre_xol(struct arch_uprobe *auprobe, struct pt_regs *regs)
{
struct uprobe_task *utask = current->utask;
current->thread.fault_code = UPROBE_INV_FAULT_CODE;
instruction_pointer_set(regs, utask->xol_vaddr);
user_enable_single_step(current);
return 0;
}
int arch_uprobe_post_xol(struct arch_uprobe *auprobe, struct pt_regs *regs)
{
struct uprobe_task *utask = current->utask;
WARN_ON_ONCE(current->thread.fault_code != UPROBE_INV_FAULT_CODE);
instruction_pointer_set(regs, utask->vaddr + 4);
user_disable_single_step(current);
return 0;
}
bool arch_uprobe_xol_was_trapped(struct task_struct *t)
{
if (t->thread.fault_code != UPROBE_INV_FAULT_CODE)
return true;
return false;
}
bool arch_uprobe_skip_sstep(struct arch_uprobe *auprobe, struct pt_regs *regs)
{
probe_opcode_t insn;
unsigned long addr;
if (!auprobe->simulate)
return false;
insn = *(probe_opcode_t *)(&auprobe->insn[0]);
addr = instruction_pointer(regs);
if (auprobe->api.handler)
auprobe->api.handler(insn, addr, regs);
return true;
}
void arch_uprobe_abort_xol(struct arch_uprobe *auprobe, struct pt_regs *regs)
{
struct uprobe_task *utask = current->utask;
instruction_pointer_set(regs, utask->vaddr);
user_disable_single_step(current);
}
bool arch_uretprobe_is_alive(struct return_instance *ret, enum rp_check ctx,
struct pt_regs *regs)
{
if (ctx == RP_CHECK_CHAIN_CALL)
return regs->sp <= ret->stack;
else
return regs->sp < ret->stack;
}
unsigned long
arch_uretprobe_hijack_return_addr(unsigned long trampoline_vaddr,
struct pt_regs *regs)
{
unsigned long orig_ret_vaddr;
orig_ret_vaddr = procedure_link_pointer(regs);
procedure_link_pointer_set(regs, trampoline_vaddr);
return orig_ret_vaddr;
}
int arch_uprobe_exception_notify(struct notifier_block *self,
unsigned long val, void *data)
{
return NOTIFY_DONE;
}
static int uprobe_breakpoint_handler(struct pt_regs *regs,
unsigned int esr)
{
if (user_mode(regs) && uprobe_pre_sstep_notifier(regs))
return DBG_HOOK_HANDLED;
return DBG_HOOK_ERROR;
}
static int uprobe_single_step_handler(struct pt_regs *regs,
unsigned int esr)
{
struct uprobe_task *utask = current->utask;
if (user_mode(regs)) {
WARN_ON(utask &&
(instruction_pointer(regs) != utask->xol_vaddr + 4));
if (uprobe_post_sstep_notifier(regs))
return DBG_HOOK_HANDLED;
}
return DBG_HOOK_ERROR;
}
static int __init arch_init_uprobes(void)
{
register_break_hook(&uprobes_break_hook);
register_step_hook(&uprobes_step_hook);
return 0;
}
