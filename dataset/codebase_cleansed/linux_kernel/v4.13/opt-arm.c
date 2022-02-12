int arch_prepared_optinsn(struct arch_optimized_insn *optinsn)
{
return optinsn->insn != NULL;
}
int arch_check_optimized_kprobe(struct optimized_kprobe *op)
{
return 0;
}
static int can_optimize(struct kprobe *kp)
{
if (kp->ainsn.stack_space < 0)
return 0;
if (kp->ainsn.stack_space > 255 - sizeof(struct pt_regs))
return 0;
return 1;
}
static void
__arch_remove_optimized_kprobe(struct optimized_kprobe *op, int dirty)
{
if (op->optinsn.insn) {
free_optinsn_slot(op->optinsn.insn, dirty);
op->optinsn.insn = NULL;
}
}
static void
optimized_callback(struct optimized_kprobe *op, struct pt_regs *regs)
{
unsigned long flags;
struct kprobe *p = &op->kp;
struct kprobe_ctlblk *kcb = get_kprobe_ctlblk();
regs->ARM_pc = (unsigned long)op->kp.addr;
regs->ARM_ORIG_r0 = ~0UL;
local_irq_save(flags);
if (kprobe_running()) {
kprobes_inc_nmissed_count(&op->kp);
} else {
__this_cpu_write(current_kprobe, &op->kp);
kcb->kprobe_status = KPROBE_HIT_ACTIVE;
opt_pre_handler(&op->kp, regs);
__this_cpu_write(current_kprobe, NULL);
}
if (!p->ainsn.kprobe_direct_exec)
op->kp.ainsn.insn_singlestep(p->opcode, &p->ainsn, regs);
local_irq_restore(flags);
}
int arch_prepare_optimized_kprobe(struct optimized_kprobe *op, struct kprobe *orig)
{
kprobe_opcode_t *code;
unsigned long rel_chk;
unsigned long val;
unsigned long stack_protect = sizeof(struct pt_regs);
if (!can_optimize(orig))
return -EILSEQ;
code = get_optinsn_slot();
if (!code)
return -ENOMEM;
rel_chk = (unsigned long)((long)code -
(long)orig->addr + 8) & 0xfe000003;
if ((rel_chk != 0) && (rel_chk != 0xfe000000)) {
free_optinsn_slot(code, 0);
return -ERANGE;
}
memcpy(code, &optprobe_template_entry,
TMPL_END_IDX * sizeof(kprobe_opcode_t));
BUG_ON(orig->ainsn.stack_space < 0);
stack_protect += orig->ainsn.stack_space;
BUG_ON(stack_protect > 255);
code[TMPL_SUB_SP] = __opcode_to_mem_arm(0xe24dd000 | stack_protect);
code[TMPL_ADD_SP] = __opcode_to_mem_arm(0xe28d3000 | stack_protect);
val = (unsigned long)op;
code[TMPL_VAL_IDX] = val;
val = (unsigned long)optimized_callback;
code[TMPL_CALL_IDX] = val;
orig->ainsn.kprobe_direct_exec = false;
if (can_kprobe_direct_exec(orig->ainsn.register_usage_flags)) {
kprobe_opcode_t final_branch = arm_gen_branch(
(unsigned long)(&code[TMPL_RESTORE_END]),
(unsigned long)(op->kp.addr) + 4);
if (final_branch != 0) {
code[TMPL_RESTORE_BEGIN] = __opcode_to_mem_arm(0xe89d7fff);
code[TMPL_RESTORE_ORIGN_INSN] = __opcode_to_mem_arm(orig->opcode);
code[TMPL_RESTORE_END] = __opcode_to_mem_arm(final_branch);
orig->ainsn.kprobe_direct_exec = true;
}
}
flush_icache_range((unsigned long)code,
(unsigned long)(&code[TMPL_END_IDX]));
op->optinsn.insn = code;
return 0;
}
void __kprobes arch_optimize_kprobes(struct list_head *oplist)
{
struct optimized_kprobe *op, *tmp;
list_for_each_entry_safe(op, tmp, oplist, list) {
unsigned long insn;
WARN_ON(kprobe_disabled(&op->kp));
memcpy(op->optinsn.copied_insn, op->kp.addr,
RELATIVEJUMP_SIZE);
insn = arm_gen_branch((unsigned long)op->kp.addr,
(unsigned long)op->optinsn.insn);
BUG_ON(insn == 0);
insn = (__mem_to_opcode_arm(
op->optinsn.copied_insn[0]) & 0xf0000000) |
(insn & 0x0fffffff);
kprobes_remove_breakpoint(op->kp.addr, insn);
list_del_init(&op->list);
}
}
void arch_unoptimize_kprobe(struct optimized_kprobe *op)
{
arch_arm_kprobe(&op->kp);
}
void arch_unoptimize_kprobes(struct list_head *oplist,
struct list_head *done_list)
{
struct optimized_kprobe *op, *tmp;
list_for_each_entry_safe(op, tmp, oplist, list) {
arch_unoptimize_kprobe(op);
list_move(&op->list, done_list);
}
}
int arch_within_optimized_kprobe(struct optimized_kprobe *op,
unsigned long addr)
{
return ((unsigned long)op->kp.addr <= addr &&
(unsigned long)op->kp.addr + RELATIVEJUMP_SIZE > addr);
}
void arch_remove_optimized_kprobe(struct optimized_kprobe *op)
{
__arch_remove_optimized_kprobe(op, 1);
}
