static void *__ppc_alloc_insn_page(void)
{
if (insn_page_in_use)
return NULL;
insn_page_in_use = true;
return &optinsn_slot;
}
static void __ppc_free_insn_page(void *page __maybe_unused)
{
insn_page_in_use = false;
}
static unsigned long can_optimize(struct kprobe *p)
{
struct pt_regs regs;
struct instruction_op op;
unsigned long nip = 0;
if (p->addr == (kprobe_opcode_t *)&kretprobe_trampoline)
return (unsigned long)p->addr + sizeof(kprobe_opcode_t);
if (!is_kernel_addr((unsigned long)p->addr))
return 0;
memset(&regs, 0, sizeof(struct pt_regs));
regs.nip = (unsigned long)p->addr;
regs.trap = 0x0;
regs.msr = MSR_KERNEL;
if (!is_conditional_branch(*p->ainsn.insn) &&
analyse_instr(&op, &regs, *p->ainsn.insn))
nip = regs.nip;
return nip;
}
static void optimized_callback(struct optimized_kprobe *op,
struct pt_regs *regs)
{
struct kprobe_ctlblk *kcb = get_kprobe_ctlblk();
unsigned long flags;
if (kprobe_disabled(&op->kp))
return;
local_irq_save(flags);
hard_irq_disable();
if (kprobe_running()) {
kprobes_inc_nmissed_count(&op->kp);
} else {
__this_cpu_write(current_kprobe, &op->kp);
regs->nip = (unsigned long)op->kp.addr;
kcb->kprobe_status = KPROBE_HIT_ACTIVE;
opt_pre_handler(&op->kp, regs);
__this_cpu_write(current_kprobe, NULL);
}
local_irq_restore(flags);
}
void arch_remove_optimized_kprobe(struct optimized_kprobe *op)
{
if (op->optinsn.insn) {
free_ppc_optinsn_slot(op->optinsn.insn, 1);
op->optinsn.insn = NULL;
}
}
void patch_imm32_load_insns(unsigned int val, kprobe_opcode_t *addr)
{
*addr++ = PPC_INST_ADDIS | ___PPC_RT(4) |
((val >> 16) & 0xffff);
*addr = PPC_INST_ORI | ___PPC_RA(4) | ___PPC_RS(4) |
(val & 0xffff);
}
void patch_imm64_load_insns(unsigned long val, kprobe_opcode_t *addr)
{
*addr++ = PPC_INST_ADDIS | ___PPC_RT(3) |
((val >> 48) & 0xffff);
*addr++ = PPC_INST_ORI | ___PPC_RA(3) | ___PPC_RS(3) |
((val >> 32) & 0xffff);
*addr++ = PPC_INST_RLDICR | ___PPC_RA(3) | ___PPC_RS(3) |
__PPC_SH64(32) | __PPC_ME64(31);
*addr++ = PPC_INST_ORIS | ___PPC_RA(3) | ___PPC_RS(3) |
((val >> 16) & 0xffff);
*addr = PPC_INST_ORI | ___PPC_RA(3) | ___PPC_RS(3) |
(val & 0xffff);
}
int arch_prepare_optimized_kprobe(struct optimized_kprobe *op, struct kprobe *p)
{
kprobe_opcode_t *buff, branch_op_callback, branch_emulate_step;
kprobe_opcode_t *op_callback_addr, *emulate_step_addr;
long b_offset;
unsigned long nip;
kprobe_ppc_optinsn_slots.insn_size = MAX_OPTINSN_SIZE;
nip = can_optimize(p);
if (!nip)
return -EILSEQ;
buff = get_ppc_optinsn_slot();
if (!buff)
return -ENOMEM;
b_offset = (unsigned long)buff - (unsigned long)p->addr;
if (!is_offset_in_branch_range(b_offset))
goto error;
b_offset = (unsigned long)(buff + TMPL_RET_IDX) -
(unsigned long)nip;
if (!is_offset_in_branch_range(b_offset))
goto error;
memcpy(buff, optprobe_template_entry,
TMPL_END_IDX * sizeof(kprobe_opcode_t));
patch_imm64_load_insns((unsigned long)op, buff + TMPL_OP_IDX);
kprobe_lookup_name("optimized_callback", op_callback_addr);
kprobe_lookup_name("emulate_step", emulate_step_addr);
if (!op_callback_addr || !emulate_step_addr) {
WARN(1, "kprobe_lookup_name() failed\n");
goto error;
}
branch_op_callback = create_branch((unsigned int *)buff + TMPL_CALL_HDLR_IDX,
(unsigned long)op_callback_addr,
BRANCH_SET_LINK);
branch_emulate_step = create_branch((unsigned int *)buff + TMPL_EMULATE_IDX,
(unsigned long)emulate_step_addr,
BRANCH_SET_LINK);
if (!branch_op_callback || !branch_emulate_step)
goto error;
buff[TMPL_CALL_HDLR_IDX] = branch_op_callback;
buff[TMPL_EMULATE_IDX] = branch_emulate_step;
patch_imm32_load_insns(*p->ainsn.insn, buff + TMPL_INSN_IDX);
buff[TMPL_RET_IDX] = create_branch((unsigned int *)buff + TMPL_RET_IDX,
(unsigned long)nip, 0);
flush_icache_range((unsigned long)buff,
(unsigned long)(&buff[TMPL_END_IDX]));
op->optinsn.insn = buff;
return 0;
error:
free_ppc_optinsn_slot(buff, 0);
return -ERANGE;
}
int arch_prepared_optinsn(struct arch_optimized_insn *optinsn)
{
return optinsn->insn != NULL;
}
int arch_check_optimized_kprobe(struct optimized_kprobe *op)
{
return 0;
}
void arch_optimize_kprobes(struct list_head *oplist)
{
struct optimized_kprobe *op;
struct optimized_kprobe *tmp;
list_for_each_entry_safe(op, tmp, oplist, list) {
memcpy(op->optinsn.copied_insn, op->kp.addr,
RELATIVEJUMP_SIZE);
patch_instruction(op->kp.addr,
create_branch((unsigned int *)op->kp.addr,
(unsigned long)op->optinsn.insn, 0));
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
struct optimized_kprobe *op;
struct optimized_kprobe *tmp;
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
