static int __init setup_unaligned_printk(char *str)
{
long val;
if (strict_strtol(str, 0, &val) != 0)
return 0;
unaligned_printk = val;
pr_info("Printk for each unaligned data accesses is %s\n",
unaligned_printk ? "enabled" : "disabled");
return 1;
}
static inline tile_bundle_bits set_BrOff_X1(tile_bundle_bits n, s32 offset)
{
tile_bundle_bits result;
tile_bundle_bits mask = create_BrOff_X1(-1);
result = n & (~mask);
result |= create_BrOff_X1(offset);
return result;
}
static inline tile_bundle_bits move_X1(tile_bundle_bits n, int dest, int src)
{
tile_bundle_bits result;
tile_bundle_bits op;
result = n & (~TILE_X1_MASK);
op = create_Opcode_X1(SPECIAL_0_OPCODE_X1) |
create_RRROpcodeExtension_X1(OR_SPECIAL_0_OPCODE_X1) |
create_Dest_X1(dest) |
create_SrcB_X1(TREG_ZERO) |
create_SrcA_X1(src) ;
result |= op;
return result;
}
static inline tile_bundle_bits nop_X1(tile_bundle_bits n)
{
return move_X1(n, TREG_ZERO, TREG_ZERO);
}
static inline tile_bundle_bits addi_X1(
tile_bundle_bits n, int dest, int src, int imm)
{
n &= ~TILE_X1_MASK;
n |= (create_SrcA_X1(src) |
create_Dest_X1(dest) |
create_Imm8_X1(imm) |
create_S_X1(0) |
create_Opcode_X1(IMM_0_OPCODE_X1) |
create_ImmOpcodeExtension_X1(ADDI_IMM_0_OPCODE_X1));
return n;
}
static tile_bundle_bits rewrite_load_store_unaligned(
struct single_step_state *state,
tile_bundle_bits bundle,
struct pt_regs *regs,
enum mem_op mem_op,
int size, int sign_ext)
{
unsigned char __user *addr;
int val_reg, addr_reg, err, val;
if (bundle & TILEPRO_BUNDLE_Y_ENCODING_MASK) {
addr_reg = get_SrcA_Y2(bundle);
val_reg = get_SrcBDest_Y2(bundle);
} else if (mem_op == MEMOP_LOAD || mem_op == MEMOP_LOAD_POSTINCR) {
addr_reg = get_SrcA_X1(bundle);
val_reg = get_Dest_X1(bundle);
} else {
addr_reg = get_SrcA_X1(bundle);
val_reg = get_SrcB_X1(bundle);
}
if ((val_reg >= PTREGS_NR_GPRS &&
(val_reg != TREG_ZERO ||
mem_op == MEMOP_LOAD ||
mem_op == MEMOP_LOAD_POSTINCR)) ||
addr_reg >= PTREGS_NR_GPRS)
return bundle;
addr = (void __user *)regs->regs[addr_reg];
if (((unsigned long)addr % size) == 0)
return bundle;
#ifndef __LITTLE_ENDIAN
# error We assume little-endian representation with copy_xx_user size 2 here
#endif
if (mem_op == MEMOP_LOAD || mem_op == MEMOP_LOAD_POSTINCR) {
unsigned short val_16;
switch (size) {
case 2:
err = copy_from_user(&val_16, addr, sizeof(val_16));
val = sign_ext ? ((short)val_16) : val_16;
break;
case 4:
err = copy_from_user(&val, addr, sizeof(val));
break;
default:
BUG();
}
if (err == 0) {
state->update_reg = val_reg;
state->update_value = val;
state->update = 1;
}
} else {
val = (val_reg == TREG_ZERO) ? 0 : regs->regs[val_reg];
err = copy_to_user(addr, &val, size);
}
if (err) {
siginfo_t info = {
.si_signo = SIGSEGV,
.si_code = SEGV_MAPERR,
.si_addr = addr
};
trace_unhandled_signal("segfault", regs,
(unsigned long)addr, SIGSEGV);
force_sig_info(info.si_signo, &info, current);
return (tile_bundle_bits) 0;
}
if (unaligned_fixup == 0) {
siginfo_t info = {
.si_signo = SIGBUS,
.si_code = BUS_ADRALN,
.si_addr = addr
};
trace_unhandled_signal("unaligned trap", regs,
(unsigned long)addr, SIGBUS);
force_sig_info(info.si_signo, &info, current);
return (tile_bundle_bits) 0;
}
if (unaligned_printk || unaligned_fixup_count == 0) {
pr_info("Process %d/%s: PC %#lx: Fixup of"
" unaligned %s at %#lx.\n",
current->pid, current->comm, regs->pc,
(mem_op == MEMOP_LOAD ||
mem_op == MEMOP_LOAD_POSTINCR) ?
"load" : "store",
(unsigned long)addr);
if (!unaligned_printk) {
#define P pr_info
P("\n");
P("Unaligned fixups in the kernel will slow your application considerably.\n");
P("To find them, write a \"1\" to /proc/sys/tile/unaligned_fixup/printk,\n");
P("which requests the kernel show all unaligned fixups, or write a \"0\"\n");
P("to /proc/sys/tile/unaligned_fixup/enabled, in which case each unaligned\n");
P("access will become a SIGBUS you can debug. No further warnings will be\n");
P("shown so as to avoid additional slowdown, but you can track the number\n");
P("of fixups performed via /proc/sys/tile/unaligned_fixup/count.\n");
P("Use the tile-addr2line command (see \"info addr2line\") to decode PCs.\n");
P("\n");
#undef P
}
}
++unaligned_fixup_count;
if (bundle & TILEPRO_BUNDLE_Y_ENCODING_MASK) {
bundle &= ~(create_SrcBDest_Y2(-1) |
create_Opcode_Y2(-1));
bundle |= (create_SrcBDest_Y2(TREG_ZERO) |
create_Opcode_Y2(LW_OPCODE_Y2));
} else if (mem_op == MEMOP_LOAD_POSTINCR) {
bundle = addi_X1(bundle, addr_reg, addr_reg,
get_Imm8_X1(bundle));
} else if (mem_op == MEMOP_STORE_POSTINCR) {
bundle = addi_X1(bundle, addr_reg, addr_reg,
get_Dest_Imm8_X1(bundle));
} else {
bundle &= ~(create_Opcode_X1(-1) |
create_UnShOpcodeExtension_X1(-1) |
create_UnOpcodeExtension_X1(-1));
bundle |= (create_Opcode_X1(SHUN_0_OPCODE_X1) |
create_UnShOpcodeExtension_X1(
UN_0_SHUN_0_OPCODE_X1) |
create_UnOpcodeExtension_X1(
NOP_UN_0_SHUN_0_OPCODE_X1));
}
return bundle;
}
void single_step_execve(void)
{
struct thread_info *ti = current_thread_info();
kfree(ti->step_state);
ti->step_state = NULL;
}
void single_step_once(struct pt_regs *regs)
{
extern tile_bundle_bits __single_step_ill_insn;
extern tile_bundle_bits __single_step_j_insn;
extern tile_bundle_bits __single_step_addli_insn;
extern tile_bundle_bits __single_step_auli_insn;
struct thread_info *info = (void *)current_thread_info();
struct single_step_state *state = info->step_state;
int is_single_step = test_ti_thread_flag(info, TIF_SINGLESTEP);
tile_bundle_bits __user *buffer, *pc;
tile_bundle_bits bundle;
int temp_reg;
int target_reg = TREG_LR;
int err;
enum mem_op mem_op = MEMOP_NONE;
int size = 0, sign_ext = 0;
asm(
" .pushsection .rodata.single_step\n"
" .align 8\n"
" .globl __single_step_ill_insn\n"
"__single_step_ill_insn:\n"
" ill\n"
" .globl __single_step_addli_insn\n"
"__single_step_addli_insn:\n"
" { nop; addli r0, zero, 0 }\n"
" .globl __single_step_auli_insn\n"
"__single_step_auli_insn:\n"
" { nop; auli r0, r0, 0 }\n"
" .globl __single_step_j_insn\n"
"__single_step_j_insn:\n"
" j .\n"
" .popsection\n"
);
local_irq_enable();
if (state == NULL) {
state = kmalloc(sizeof(struct single_step_state), GFP_KERNEL);
if (state == NULL) {
pr_err("Out of kernel memory trying to single-step\n");
return;
}
down_write(&current->mm->mmap_sem);
buffer = (void __user *) do_mmap(NULL, 0, 64,
PROT_EXEC | PROT_READ | PROT_WRITE,
MAP_PRIVATE | MAP_ANONYMOUS,
0);
up_write(&current->mm->mmap_sem);
if (IS_ERR((void __force *)buffer)) {
kfree(state);
pr_err("Out of kernel pages trying to single-step\n");
return;
}
state->buffer = buffer;
state->is_enabled = 0;
info->step_state = state;
BUG_ON(get_Opcode_X1(__single_step_addli_insn) !=
ADDLI_OPCODE_X1);
BUG_ON(get_Opcode_X1(__single_step_auli_insn) !=
AULI_OPCODE_X1);
BUG_ON(get_SrcA_X1(__single_step_addli_insn) != TREG_ZERO);
BUG_ON(get_Dest_X1(__single_step_addli_insn) != 0);
BUG_ON(get_JOffLong_X1(__single_step_j_insn) != 0);
}
if (regs->faultnum == INT_SWINT_1)
regs->pc -= 8;
pc = (tile_bundle_bits __user *)(regs->pc);
if (get_user(bundle, pc) != 0) {
pr_err("Couldn't read instruction at %p trying to step\n", pc);
return;
}
state->orig_pc = (unsigned long)pc;
state->next_pc = (unsigned long)(pc + 1);
state->branch_next_pc = 0;
state->update = 0;
if (!(bundle & TILEPRO_BUNDLE_Y_ENCODING_MASK)) {
int opcode = get_Opcode_X1(bundle);
switch (opcode) {
case BRANCH_OPCODE_X1:
{
s32 offset = signExtend17(get_BrOff_X1(bundle));
state->branch_next_pc = (unsigned long)(pc + offset);
bundle = set_BrOff_X1(bundle, 2);
}
break;
case JALB_OPCODE_X1:
case JALF_OPCODE_X1:
state->update = 1;
state->next_pc =
(unsigned long) (pc + get_JOffLong_X1(bundle));
break;
case JB_OPCODE_X1:
case JF_OPCODE_X1:
state->next_pc =
(unsigned long) (pc + get_JOffLong_X1(bundle));
bundle = nop_X1(bundle);
break;
case SPECIAL_0_OPCODE_X1:
switch (get_RRROpcodeExtension_X1(bundle)) {
case JALRP_SPECIAL_0_OPCODE_X1:
case JALR_SPECIAL_0_OPCODE_X1:
state->update = 1;
state->next_pc =
regs->regs[get_SrcA_X1(bundle)];
break;
case JRP_SPECIAL_0_OPCODE_X1:
case JR_SPECIAL_0_OPCODE_X1:
state->next_pc =
regs->regs[get_SrcA_X1(bundle)];
bundle = nop_X1(bundle);
break;
case LNK_SPECIAL_0_OPCODE_X1:
state->update = 1;
target_reg = get_Dest_X1(bundle);
break;
case SH_SPECIAL_0_OPCODE_X1:
mem_op = MEMOP_STORE;
size = 2;
break;
case SW_SPECIAL_0_OPCODE_X1:
mem_op = MEMOP_STORE;
size = 4;
break;
}
break;
case SHUN_0_OPCODE_X1:
if (get_UnShOpcodeExtension_X1(bundle) ==
UN_0_SHUN_0_OPCODE_X1) {
switch (get_UnOpcodeExtension_X1(bundle)) {
case LH_UN_0_SHUN_0_OPCODE_X1:
mem_op = MEMOP_LOAD;
size = 2;
sign_ext = 1;
break;
case LH_U_UN_0_SHUN_0_OPCODE_X1:
mem_op = MEMOP_LOAD;
size = 2;
sign_ext = 0;
break;
case LW_UN_0_SHUN_0_OPCODE_X1:
mem_op = MEMOP_LOAD;
size = 4;
break;
case IRET_UN_0_SHUN_0_OPCODE_X1:
{
unsigned long ex0_0 = __insn_mfspr(
SPR_EX_CONTEXT_0_0);
unsigned long ex0_1 = __insn_mfspr(
SPR_EX_CONTEXT_0_1);
if (EX1_PL(ex0_1) == USER_PL) {
state->next_pc = ex0_0;
regs->ex1 = ex0_1;
bundle = nop_X1(bundle);
}
}
}
}
break;
#if CHIP_HAS_WH64()
case IMM_0_OPCODE_X1:
switch (get_ImmOpcodeExtension_X1(bundle)) {
case LWADD_IMM_0_OPCODE_X1:
mem_op = MEMOP_LOAD_POSTINCR;
size = 4;
break;
case LHADD_IMM_0_OPCODE_X1:
mem_op = MEMOP_LOAD_POSTINCR;
size = 2;
sign_ext = 1;
break;
case LHADD_U_IMM_0_OPCODE_X1:
mem_op = MEMOP_LOAD_POSTINCR;
size = 2;
sign_ext = 0;
break;
case SWADD_IMM_0_OPCODE_X1:
mem_op = MEMOP_STORE_POSTINCR;
size = 4;
break;
case SHADD_IMM_0_OPCODE_X1:
mem_op = MEMOP_STORE_POSTINCR;
size = 2;
break;
default:
break;
}
break;
#endif
}
if (state->update) {
u32 mask = (u32) ~((1ULL << get_Dest_X0(bundle)) |
(1ULL << get_SrcA_X0(bundle)) |
(1ULL << get_SrcB_X0(bundle)) |
(1ULL << target_reg));
temp_reg = __builtin_ctz(mask);
state->update_reg = temp_reg;
state->update_value = regs->regs[temp_reg];
regs->regs[temp_reg] = (unsigned long) (pc+1);
regs->flags |= PT_FLAGS_RESTORE_REGS;
bundle = move_X1(bundle, target_reg, temp_reg);
}
} else {
int opcode = get_Opcode_Y2(bundle);
switch (opcode) {
case LH_OPCODE_Y2:
mem_op = MEMOP_LOAD;
size = 2;
sign_ext = 1;
break;
case LH_U_OPCODE_Y2:
mem_op = MEMOP_LOAD;
size = 2;
sign_ext = 0;
break;
case LW_OPCODE_Y2:
mem_op = MEMOP_LOAD;
size = 4;
break;
case SH_OPCODE_Y2:
mem_op = MEMOP_STORE;
size = 2;
break;
case SW_OPCODE_Y2:
mem_op = MEMOP_STORE;
size = 4;
break;
}
}
if (mem_op != MEMOP_NONE && unaligned_fixup >= 0) {
bundle = rewrite_load_store_unaligned(state, bundle, regs,
mem_op, size, sign_ext);
if (bundle == 0)
return;
}
buffer = state->buffer;
err = __put_user(bundle, buffer++);
if (is_single_step) {
err |= __put_user(__single_step_ill_insn, buffer++);
err |= __put_user(__single_step_ill_insn, buffer++);
} else {
long delta;
if (state->update) {
int ha16;
bundle = __single_step_addli_insn;
bundle |= create_Dest_X1(state->update_reg);
bundle |= create_Imm16_X1(state->update_value);
err |= __put_user(bundle, buffer++);
bundle = __single_step_auli_insn;
bundle |= create_Dest_X1(state->update_reg);
bundle |= create_SrcA_X1(state->update_reg);
ha16 = (state->update_value + 0x8000) >> 16;
bundle |= create_Imm16_X1(ha16);
err |= __put_user(bundle, buffer++);
state->update = 0;
}
delta = ((regs->pc + TILE_BUNDLE_SIZE_IN_BYTES) -
(unsigned long)buffer) >>
TILE_LOG2_BUNDLE_ALIGNMENT_IN_BYTES;
bundle = __single_step_j_insn;
bundle |= create_JOffLong_X1(delta);
err |= __put_user(bundle, buffer++);
}
if (err) {
pr_err("Fault when writing to single-step buffer\n");
return;
}
__flush_icache_range((unsigned long)state->buffer,
(unsigned long)buffer);
state->is_enabled = is_single_step;
regs->pc = (unsigned long)state->buffer;
if (regs->faultnum == INT_SWINT_1)
regs->pc += 8;
}
void gx_singlestep_handle(struct pt_regs *regs, int fault_num)
{
unsigned long *ss_pc = &__get_cpu_var(ss_saved_pc);
struct thread_info *info = (void *)current_thread_info();
int is_single_step = test_ti_thread_flag(info, TIF_SINGLESTEP);
unsigned long control = __insn_mfspr(SPR_SINGLE_STEP_CONTROL_K);
if (is_single_step == 0) {
__insn_mtspr(SPR_SINGLE_STEP_EN_K_K, 0);
} else if ((*ss_pc != regs->pc) ||
(!(control & SPR_SINGLE_STEP_CONTROL_1__CANCELED_MASK))) {
ptrace_notify(SIGTRAP);
control |= SPR_SINGLE_STEP_CONTROL_1__CANCELED_MASK;
control |= SPR_SINGLE_STEP_CONTROL_1__INHIBIT_MASK;
__insn_mtspr(SPR_SINGLE_STEP_CONTROL_K, control);
}
}
void single_step_once(struct pt_regs *regs)
{
unsigned long *ss_pc = &__get_cpu_var(ss_saved_pc);
unsigned long control = __insn_mfspr(SPR_SINGLE_STEP_CONTROL_K);
*ss_pc = regs->pc;
control |= SPR_SINGLE_STEP_CONTROL_1__CANCELED_MASK;
control |= SPR_SINGLE_STEP_CONTROL_1__INHIBIT_MASK;
__insn_mtspr(SPR_SINGLE_STEP_CONTROL_K, control);
__insn_mtspr(SPR_SINGLE_STEP_EN_K_K, 1 << USER_PL);
}
void single_step_execve(void)
{
}
