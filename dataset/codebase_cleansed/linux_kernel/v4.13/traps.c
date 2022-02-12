void __init trap_init(void)
{
}
static int __init setup_unaligned_fixup(char *str)
{
if (kstrtoint(str, 0, &unaligned_fixup) != 0)
return 0;
pr_info("Fixups for unaligned data accesses are %s\n",
unaligned_fixup >= 0 ?
(unaligned_fixup ? "enabled" : "disabled") :
"completely disabled");
return 1;
}
static int __init nodma(char *str)
{
pr_info("User-space DMA is disabled\n");
dma_disabled = 1;
return 1;
}
static int retry_gpv(unsigned int gpv_reason)
{
int mpl;
if (gpv_reason & IRET_ERROR)
return 0;
BUG_ON((gpv_reason & (MT_ERROR|MF_ERROR)) == 0);
mpl = (gpv_reason & SPR_INDEX) >> SPR_MPL_SHIFT;
if (mpl == INT_DMA_NOTIFY && !dma_disabled) {
printk(KERN_DEBUG "Process %d/%s is now enabled for DMA\n",
current->pid, current->comm);
BUG_ON(current->thread.tile_dma_state.enabled);
current->thread.tile_dma_state.enabled = 1;
grant_dma_mpls();
return 1;
}
return 0;
}
static int special_ill(tile_bundle_bits bundle, int *sigp, int *codep)
{
int sig, code, maxcode;
if (bundle == bpt_code) {
*sigp = SIGTRAP;
*codep = TRAP_BRKPT;
return 1;
}
#ifdef __tilegx__
if ((bundle & TILEGX_BUNDLE_MODE_MASK) != 0)
return 0;
if (get_Opcode_X1(bundle) != RRR_0_OPCODE_X1)
return 0;
if (get_RRROpcodeExtension_X1(bundle) != UNARY_RRR_0_OPCODE_X1)
return 0;
if (get_UnaryOpcodeExtension_X1(bundle) != ILL_UNARY_OPCODE_X1)
return 0;
#else
if (bundle & TILEPRO_BUNDLE_Y_ENCODING_MASK)
return 0;
if (get_Opcode_X1(bundle) != SHUN_0_OPCODE_X1)
return 0;
if (get_UnShOpcodeExtension_X1(bundle) != UN_0_SHUN_0_OPCODE_X1)
return 0;
if (get_UnOpcodeExtension_X1(bundle) != ILL_UN_0_SHUN_0_OPCODE_X1)
return 0;
#endif
if (get_Dest_X1(bundle) != 29 || get_SrcA_X1(bundle) != 37)
return 0;
if (get_Opcode_X0(bundle) != ADDLI_OPCODE_X0)
return 0;
if (get_Dest_X0(bundle) != TREG_ZERO)
return 0;
if (get_SrcA_X0(bundle) != TREG_ZERO)
return 0;
sig = get_Imm16_X0(bundle) & 0x3f;
switch (sig) {
case SIGILL:
maxcode = NSIGILL;
break;
case SIGFPE:
maxcode = NSIGFPE;
break;
case SIGSEGV:
maxcode = NSIGSEGV;
break;
case SIGBUS:
maxcode = NSIGBUS;
break;
case SIGTRAP:
maxcode = NSIGTRAP;
break;
default:
return 0;
}
code = (get_Imm16_X0(bundle) >> 6) & 0xf;
if (code <= 0 || code > maxcode)
return 0;
*sigp = sig;
*codep = code | __SI_FAULT;
return 1;
}
static int do_bpt(struct pt_regs *regs)
{
unsigned long bundle, bcode, bpt;
bundle = *(unsigned long *)instruction_pointer(regs);
bpt = bundle & ~((1ULL << 12) - 1);
if (bpt != TILE_BPT_BUNDLE)
return 0;
bcode = bundle & ((1ULL << 12) - 1);
switch (bcode) {
case 0:
notify_die(DIE_BREAK, "debug", regs, bundle,
INT_ILL, SIGTRAP);
break;
case DIE_COMPILED_BPT:
notify_die(DIE_COMPILED_BPT, "debug", regs, bundle,
INT_ILL, SIGTRAP);
break;
case DIE_SSTEPBP:
notify_die(DIE_SSTEPBP, "single_step", regs, bundle,
INT_ILL, SIGTRAP);
break;
default:
return 0;
}
return 1;
}
void __kprobes do_trap(struct pt_regs *regs, int fault_num,
unsigned long reason)
{
siginfo_t info = { 0 };
int signo, code;
unsigned long address = 0;
tile_bundle_bits instr;
int is_kernel = !user_mode(regs);
if (is_kernel && fault_num == INT_ILL && do_bpt(regs))
return;
if (!(regs->flags & PT_FLAGS_DISABLE_IRQ))
local_irq_enable();
if (is_kernel) {
const char *name;
char buf[100];
if (fixup_exception(regs))
return;
if (fault_num >= 0 &&
fault_num < ARRAY_SIZE(int_name) &&
int_name[fault_num] != NULL)
name = int_name[fault_num];
else
name = "Unknown interrupt";
if (fault_num == INT_GPV)
snprintf(buf, sizeof(buf), "; GPV_REASON %#lx", reason);
#ifdef __tilegx__
else if (fault_num == INT_ILL_TRANS)
snprintf(buf, sizeof(buf), "; address %#lx", reason);
#endif
else
buf[0] = '\0';
pr_alert("Kernel took bad trap %d (%s) at PC %#lx%s\n",
fault_num, name, regs->pc, buf);
show_regs(regs);
do_exit(SIGKILL);
}
switch (fault_num) {
case INT_MEM_ERROR:
signo = SIGBUS;
code = BUS_OBJERR;
break;
case INT_ILL:
if (copy_from_user(&instr, (void __user *)regs->pc,
sizeof(instr))) {
pr_err("Unreadable instruction for INT_ILL: %#lx\n",
regs->pc);
do_exit(SIGKILL);
}
if (!special_ill(instr, &signo, &code)) {
signo = SIGILL;
code = ILL_ILLOPC;
}
address = regs->pc;
break;
case INT_GPV:
#if CHIP_HAS_TILE_DMA()
if (retry_gpv(reason))
return;
#endif
case INT_UDN_ACCESS:
case INT_IDN_ACCESS:
#if CHIP_HAS_SN()
case INT_SN_ACCESS:
#endif
signo = SIGILL;
code = ILL_PRVREG;
address = regs->pc;
break;
case INT_SWINT_3:
case INT_SWINT_2:
case INT_SWINT_0:
signo = SIGILL;
code = ILL_ILLTRP;
address = regs->pc;
break;
case INT_UNALIGN_DATA:
#ifndef __tilegx__
if (unaligned_fixup >= 0) {
struct single_step_state *state =
current_thread_info()->step_state;
if (!state ||
(void __user *)(regs->pc) != state->buffer) {
single_step_once(regs);
return;
}
}
#endif
signo = SIGBUS;
code = BUS_ADRALN;
address = 0;
break;
case INT_DOUBLE_FAULT:
fault_num = reason;
signo = SIGILL;
code = ILL_DBLFLT;
address = regs->pc;
break;
#ifdef __tilegx__
case INT_ILL_TRANS: {
fill_ra_stack();
signo = SIGSEGV;
address = reason;
code = SEGV_MAPERR;
break;
}
#endif
default:
panic("Unexpected do_trap interrupt number %d", fault_num);
}
info.si_signo = signo;
info.si_code = code;
info.si_addr = (void __user *)address;
if (signo == SIGILL)
info.si_trapno = fault_num;
if (signo != SIGTRAP)
trace_unhandled_signal("trap", regs, address, signo);
force_sig_info(signo, &info, current);
}
void do_nmi(struct pt_regs *regs, int fault_num, unsigned long reason)
{
nmi_enter();
switch (reason) {
#ifdef arch_trigger_cpumask_backtrace
case TILE_NMI_DUMP_STACK:
nmi_cpu_backtrace(regs);
break;
#endif
default:
panic("Unexpected do_nmi type %ld", reason);
}
nmi_exit();
}
void kernel_double_fault(int dummy, ulong pc, ulong lr, ulong sp, ulong r52)
{
_dump_stack(dummy, pc, lr, sp, r52);
pr_emerg("Double fault: exiting\n");
machine_halt();
}
