static inline long kvm_vz_read_gc0_ebase(void)
{
if (sizeof(long) == 8 && cpu_has_ebase_wg)
return read_gc0_ebase_64();
else
return read_gc0_ebase();
}
static inline void kvm_vz_write_gc0_ebase(long v)
{
if (sizeof(long) == 8 &&
(cpu_has_mips64r6 || cpu_has_ebase_wg)) {
write_gc0_ebase_64(v | MIPS_EBASE_WG);
write_gc0_ebase_64(v);
} else {
write_gc0_ebase(v | MIPS_EBASE_WG);
write_gc0_ebase(v);
}
}
static inline unsigned int kvm_vz_config_guest_wrmask(struct kvm_vcpu *vcpu)
{
return CONF_CM_CMASK;
}
static inline unsigned int kvm_vz_config1_guest_wrmask(struct kvm_vcpu *vcpu)
{
return 0;
}
static inline unsigned int kvm_vz_config2_guest_wrmask(struct kvm_vcpu *vcpu)
{
return 0;
}
static inline unsigned int kvm_vz_config3_guest_wrmask(struct kvm_vcpu *vcpu)
{
return MIPS_CONF3_ISA_OE;
}
static inline unsigned int kvm_vz_config4_guest_wrmask(struct kvm_vcpu *vcpu)
{
return MIPS_CONF4_VFTLBPAGESIZE;
}
static inline unsigned int kvm_vz_config5_guest_wrmask(struct kvm_vcpu *vcpu)
{
unsigned int mask = MIPS_CONF5_K | MIPS_CONF5_CV | MIPS_CONF5_SBRI;
if (kvm_mips_guest_has_msa(&vcpu->arch))
mask |= MIPS_CONF5_MSAEN;
if (kvm_mips_guest_has_fpu(&vcpu->arch)) {
if (cpu_has_ufr)
mask |= MIPS_CONF5_UFR;
if (cpu_has_fre)
mask |= MIPS_CONF5_FRE | MIPS_CONF5_UFE;
}
return mask;
}
static inline unsigned int kvm_vz_config_user_wrmask(struct kvm_vcpu *vcpu)
{
return kvm_vz_config_guest_wrmask(vcpu) | MIPS_CONF_M;
}
static inline unsigned int kvm_vz_config1_user_wrmask(struct kvm_vcpu *vcpu)
{
unsigned int mask = kvm_vz_config1_guest_wrmask(vcpu) | MIPS_CONF_M;
if (kvm_mips_guest_can_have_fpu(&vcpu->arch))
mask |= MIPS_CONF1_FP;
return mask;
}
static inline unsigned int kvm_vz_config2_user_wrmask(struct kvm_vcpu *vcpu)
{
return kvm_vz_config2_guest_wrmask(vcpu) | MIPS_CONF_M;
}
static inline unsigned int kvm_vz_config3_user_wrmask(struct kvm_vcpu *vcpu)
{
unsigned int mask = kvm_vz_config3_guest_wrmask(vcpu) | MIPS_CONF_M |
MIPS_CONF3_ULRI | MIPS_CONF3_CTXTC;
if (kvm_mips_guest_can_have_msa(&vcpu->arch))
mask |= MIPS_CONF3_MSA;
return mask;
}
static inline unsigned int kvm_vz_config4_user_wrmask(struct kvm_vcpu *vcpu)
{
return kvm_vz_config4_guest_wrmask(vcpu) | MIPS_CONF_M;
}
static inline unsigned int kvm_vz_config5_user_wrmask(struct kvm_vcpu *vcpu)
{
return kvm_vz_config5_guest_wrmask(vcpu) | MIPS_CONF5_MRP;
}
static gpa_t kvm_vz_gva_to_gpa_cb(gva_t gva)
{
return gva;
}
static void kvm_vz_queue_irq(struct kvm_vcpu *vcpu, unsigned int priority)
{
set_bit(priority, &vcpu->arch.pending_exceptions);
clear_bit(priority, &vcpu->arch.pending_exceptions_clr);
}
static void kvm_vz_dequeue_irq(struct kvm_vcpu *vcpu, unsigned int priority)
{
clear_bit(priority, &vcpu->arch.pending_exceptions);
set_bit(priority, &vcpu->arch.pending_exceptions_clr);
}
static void kvm_vz_queue_timer_int_cb(struct kvm_vcpu *vcpu)
{
kvm_vz_queue_irq(vcpu, MIPS_EXC_INT_TIMER);
}
static void kvm_vz_dequeue_timer_int_cb(struct kvm_vcpu *vcpu)
{
kvm_vz_dequeue_irq(vcpu, MIPS_EXC_INT_TIMER);
}
static void kvm_vz_queue_io_int_cb(struct kvm_vcpu *vcpu,
struct kvm_mips_interrupt *irq)
{
int intr = (int)irq->irq;
switch (intr) {
case 2:
kvm_vz_queue_irq(vcpu, MIPS_EXC_INT_IO);
break;
case 3:
kvm_vz_queue_irq(vcpu, MIPS_EXC_INT_IPI_1);
break;
case 4:
kvm_vz_queue_irq(vcpu, MIPS_EXC_INT_IPI_2);
break;
default:
break;
}
}
static void kvm_vz_dequeue_io_int_cb(struct kvm_vcpu *vcpu,
struct kvm_mips_interrupt *irq)
{
int intr = (int)irq->irq;
switch (intr) {
case -2:
kvm_vz_dequeue_irq(vcpu, MIPS_EXC_INT_IO);
break;
case -3:
kvm_vz_dequeue_irq(vcpu, MIPS_EXC_INT_IPI_1);
break;
case -4:
kvm_vz_dequeue_irq(vcpu, MIPS_EXC_INT_IPI_2);
break;
default:
break;
}
}
static int kvm_vz_irq_deliver_cb(struct kvm_vcpu *vcpu, unsigned int priority,
u32 cause)
{
u32 irq = (priority < MIPS_EXC_MAX) ?
kvm_vz_priority_to_irq[priority] : 0;
switch (priority) {
case MIPS_EXC_INT_TIMER:
set_gc0_cause(C_TI);
break;
case MIPS_EXC_INT_IO:
case MIPS_EXC_INT_IPI_1:
case MIPS_EXC_INT_IPI_2:
if (cpu_has_guestctl2)
set_c0_guestctl2(irq);
else
set_gc0_cause(irq);
break;
default:
break;
}
clear_bit(priority, &vcpu->arch.pending_exceptions);
return 1;
}
static int kvm_vz_irq_clear_cb(struct kvm_vcpu *vcpu, unsigned int priority,
u32 cause)
{
u32 irq = (priority < MIPS_EXC_MAX) ?
kvm_vz_priority_to_irq[priority] : 0;
switch (priority) {
case MIPS_EXC_INT_TIMER:
if (cpu_has_guestctl2) {
if (!(read_c0_guestctl2() & (irq << 14)))
clear_c0_guestctl2(irq);
} else {
clear_gc0_cause(irq);
}
break;
case MIPS_EXC_INT_IO:
case MIPS_EXC_INT_IPI_1:
case MIPS_EXC_INT_IPI_2:
if (cpu_has_guestctl2) {
if (!(read_c0_guestctl2() & (irq << 14)))
clear_c0_guestctl2(irq);
} else {
clear_gc0_cause(irq);
}
break;
default:
break;
}
clear_bit(priority, &vcpu->arch.pending_exceptions_clr);
return 1;
}
static bool kvm_vz_should_use_htimer(struct kvm_vcpu *vcpu)
{
if (kvm_mips_count_disabled(vcpu))
return false;
if (mips_hpt_frequency != vcpu->arch.count_hz)
return false;
if (current_cpu_data.gtoffset_mask != 0xffffffff)
return false;
return true;
}
static void _kvm_vz_restore_stimer(struct kvm_vcpu *vcpu, u32 compare,
u32 cause)
{
write_c0_gtoffset(compare - read_c0_count());
back_to_back_c0_hazard();
write_gc0_cause(cause);
}
static void _kvm_vz_restore_htimer(struct kvm_vcpu *vcpu,
u32 compare, u32 cause)
{
u32 start_count, after_count;
ktime_t freeze_time;
unsigned long flags;
local_irq_save(flags);
freeze_time = kvm_mips_freeze_hrtimer(vcpu, &start_count);
write_c0_gtoffset(start_count - read_c0_count());
local_irq_restore(flags);
back_to_back_c0_hazard();
write_gc0_cause(cause);
back_to_back_c0_hazard();
after_count = read_gc0_count();
if (after_count - start_count > compare - start_count - 1)
kvm_vz_queue_irq(vcpu, MIPS_EXC_INT_TIMER);
}
static void kvm_vz_restore_timer(struct kvm_vcpu *vcpu)
{
struct mips_coproc *cop0 = vcpu->arch.cop0;
u32 cause, compare;
compare = kvm_read_sw_gc0_compare(cop0);
cause = kvm_read_sw_gc0_cause(cop0);
write_gc0_compare(compare);
_kvm_vz_restore_stimer(vcpu, compare, cause);
}
void kvm_vz_acquire_htimer(struct kvm_vcpu *vcpu)
{
u32 gctl0;
gctl0 = read_c0_guestctl0();
if (!(gctl0 & MIPS_GCTL0_GT) && kvm_vz_should_use_htimer(vcpu)) {
write_c0_guestctl0(gctl0 | MIPS_GCTL0_GT);
_kvm_vz_restore_htimer(vcpu, read_gc0_compare(),
read_gc0_cause());
}
}
static void _kvm_vz_save_htimer(struct kvm_vcpu *vcpu,
u32 *out_compare, u32 *out_cause)
{
u32 cause, compare, before_count, end_count;
ktime_t before_time;
compare = read_gc0_compare();
*out_compare = compare;
before_time = ktime_get();
before_count = read_gc0_count();
back_to_back_c0_hazard();
cause = read_gc0_cause();
*out_cause = cause;
back_to_back_c0_hazard();
end_count = read_gc0_count();
if (end_count - before_count > compare - before_count - 1)
kvm_vz_queue_irq(vcpu, MIPS_EXC_INT_TIMER);
kvm_mips_restore_hrtimer(vcpu, before_time, end_count, -0x10000);
}
static void kvm_vz_save_timer(struct kvm_vcpu *vcpu)
{
struct mips_coproc *cop0 = vcpu->arch.cop0;
u32 gctl0, compare, cause;
gctl0 = read_c0_guestctl0();
if (gctl0 & MIPS_GCTL0_GT) {
write_c0_guestctl0(gctl0 & ~MIPS_GCTL0_GT);
_kvm_vz_save_htimer(vcpu, &compare, &cause);
} else {
compare = read_gc0_compare();
cause = read_gc0_cause();
}
kvm_write_sw_gc0_cause(cop0, cause);
kvm_write_sw_gc0_compare(cop0, compare);
}
void kvm_vz_lose_htimer(struct kvm_vcpu *vcpu)
{
u32 gctl0, compare, cause;
preempt_disable();
gctl0 = read_c0_guestctl0();
if (gctl0 & MIPS_GCTL0_GT) {
write_c0_guestctl0(gctl0 & ~MIPS_GCTL0_GT);
_kvm_vz_save_htimer(vcpu, &compare, &cause);
_kvm_vz_restore_stimer(vcpu, compare, cause);
}
preempt_enable();
}
static bool is_eva_access(union mips_instruction inst)
{
if (inst.spec3_format.opcode != spec3_op)
return false;
switch (inst.spec3_format.func) {
case lwle_op:
case lwre_op:
case cachee_op:
case sbe_op:
case she_op:
case sce_op:
case swe_op:
case swle_op:
case swre_op:
case prefe_op:
case lbue_op:
case lhue_op:
case lbe_op:
case lhe_op:
case lle_op:
case lwe_op:
return true;
default:
return false;
}
}
static bool is_eva_am_mapped(struct kvm_vcpu *vcpu, unsigned int am, bool eu)
{
u32 am_lookup;
int err;
am_lookup = 0x70080000 << am;
if ((s32)am_lookup < 0) {
if (!eu || !(read_gc0_status() & ST0_ERL))
return true;
} else {
am_lookup <<= 8;
if ((s32)am_lookup < 0) {
union mips_instruction inst;
unsigned int status;
u32 *opc;
status = read_gc0_status();
if (!(status & (ST0_EXL | ST0_ERL)) &&
(status & ST0_KSU))
return true;
opc = (u32 *)vcpu->arch.pc;
if (vcpu->arch.host_cp0_cause & CAUSEF_BD)
opc += 1;
err = kvm_get_badinstr(opc, vcpu, &inst.word);
if (!err && is_eva_access(inst))
return true;
}
}
return false;
}
static int kvm_vz_gva_to_gpa(struct kvm_vcpu *vcpu, unsigned long gva,
unsigned long *gpa)
{
u32 gva32 = gva;
unsigned long segctl;
if ((long)gva == (s32)gva32) {
if (cpu_guest_has_segments) {
unsigned long mask, pa;
switch (gva32 >> 29) {
case 0:
case 1:
segctl = read_gc0_segctl2() >> 16;
mask = (unsigned long)0xfc0000000ull;
break;
case 2:
case 3:
segctl = read_gc0_segctl2();
mask = (unsigned long)0xfc0000000ull;
break;
case 4:
segctl = read_gc0_segctl1() >> 16;
mask = (unsigned long)0xfe0000000ull;
break;
case 5:
segctl = read_gc0_segctl1();
mask = (unsigned long)0xfe0000000ull;
break;
case 6:
segctl = read_gc0_segctl0() >> 16;
mask = (unsigned long)0xfe0000000ull;
break;
case 7:
segctl = read_gc0_segctl0();
mask = (unsigned long)0xfe0000000ull;
break;
default:
unreachable();
}
if (is_eva_am_mapped(vcpu, (segctl >> 4) & 0x7,
segctl & 0x0008))
goto tlb_mapped;
pa = (segctl << 20) & mask;
pa |= gva32 & ~mask;
*gpa = pa;
return 0;
} else if ((s32)gva32 < (s32)0xc0000000) {
*gpa = gva32 & 0x1fffffff;
return 0;
}
#ifdef CONFIG_64BIT
} else if ((gva & 0xc000000000000000) == 0x8000000000000000) {
if (cpu_guest_has_segments) {
segctl = read_gc0_segctl2();
if (segctl & (1ull << (56 + ((gva >> 59) & 0x7)))) {
segctl = read_gc0_segctl1();
if (is_eva_am_mapped(vcpu, (segctl >> 59) & 0x7,
0))
goto tlb_mapped;
}
}
*gpa = gva & 0x07ffffffffffffff;
return 0;
#endif
}
tlb_mapped:
return kvm_vz_guest_tlb_lookup(vcpu, gva, gpa);
}
static int kvm_vz_badvaddr_to_gpa(struct kvm_vcpu *vcpu, unsigned long badvaddr,
unsigned long *gpa)
{
unsigned int gexccode = (vcpu->arch.host_cp0_guestctl0 &
MIPS_GCTL0_GEXC) >> MIPS_GCTL0_GEXC_SHIFT;
if (likely(gexccode == MIPS_GCTL0_GEXC_GPA)) {
*gpa = badvaddr;
return 0;
}
if (WARN(gexccode != MIPS_GCTL0_GEXC_GVA,
"Unexpected gexccode %#x\n", gexccode))
return -EINVAL;
return kvm_vz_gva_to_gpa(vcpu, badvaddr, gpa);
}
static int kvm_trap_vz_no_handler(struct kvm_vcpu *vcpu)
{
u32 *opc = (u32 *) vcpu->arch.pc;
u32 cause = vcpu->arch.host_cp0_cause;
u32 exccode = (cause & CAUSEF_EXCCODE) >> CAUSEB_EXCCODE;
unsigned long badvaddr = vcpu->arch.host_cp0_badvaddr;
u32 inst = 0;
if (cause & CAUSEF_BD)
opc += 1;
kvm_get_badinstr(opc, vcpu, &inst);
kvm_err("Exception Code: %d not handled @ PC: %p, inst: 0x%08x BadVaddr: %#lx Status: %#x\n",
exccode, opc, inst, badvaddr,
read_gc0_status());
kvm_arch_vcpu_dump_regs(vcpu);
vcpu->run->exit_reason = KVM_EXIT_INTERNAL_ERROR;
return RESUME_HOST;
}
static unsigned long mips_process_maar(unsigned int op, unsigned long val)
{
unsigned long mask = 0xfffff000 | MIPS_MAAR_S | MIPS_MAAR_VL;
if (read_gc0_pagegrain() & PG_ELPA)
mask |= 0x00ffffff00000000ull;
if (cpu_guest_has_mvh)
mask |= MIPS_MAAR_VH;
if (op == mtc_op) {
val &= ~MIPS_MAAR_VH;
} else if (op == dmtc_op) {
val &= ~MIPS_MAAR_VH;
if (val & MIPS_MAAR_VL)
val |= MIPS_MAAR_VH;
}
return val & mask;
}
static void kvm_write_maari(struct kvm_vcpu *vcpu, unsigned long val)
{
struct mips_coproc *cop0 = vcpu->arch.cop0;
val &= MIPS_MAARI_INDEX;
if (val == MIPS_MAARI_INDEX)
kvm_write_sw_gc0_maari(cop0, ARRAY_SIZE(vcpu->arch.maar) - 1);
else if (val < ARRAY_SIZE(vcpu->arch.maar))
kvm_write_sw_gc0_maari(cop0, val);
}
static enum emulation_result kvm_vz_gpsi_cop0(union mips_instruction inst,
u32 *opc, u32 cause,
struct kvm_run *run,
struct kvm_vcpu *vcpu)
{
struct mips_coproc *cop0 = vcpu->arch.cop0;
enum emulation_result er = EMULATE_DONE;
u32 rt, rd, sel;
unsigned long curr_pc;
unsigned long val;
curr_pc = vcpu->arch.pc;
er = update_pc(vcpu, cause);
if (er == EMULATE_FAIL)
return er;
if (inst.co_format.co) {
switch (inst.co_format.func) {
case wait_op:
er = kvm_mips_emul_wait(vcpu);
break;
default:
er = EMULATE_FAIL;
}
} else {
rt = inst.c0r_format.rt;
rd = inst.c0r_format.rd;
sel = inst.c0r_format.sel;
switch (inst.c0r_format.rs) {
case dmfc_op:
case mfc_op:
#ifdef CONFIG_KVM_MIPS_DEBUG_COP0_COUNTERS
cop0->stat[rd][sel]++;
#endif
if (rd == MIPS_CP0_COUNT &&
sel == 0) {
val = kvm_mips_read_count(vcpu);
} else if (rd == MIPS_CP0_COMPARE &&
sel == 0) {
val = read_gc0_compare();
} else if (rd == MIPS_CP0_LLADDR &&
sel == 0) {
if (cpu_guest_has_rw_llb)
val = read_gc0_lladdr() &
MIPS_LLADDR_LLB;
else
val = 0;
} else if (rd == MIPS_CP0_LLADDR &&
sel == 1 &&
cpu_guest_has_maar &&
!cpu_guest_has_dyn_maar) {
BUG_ON(kvm_read_sw_gc0_maari(cop0) >=
ARRAY_SIZE(vcpu->arch.maar));
val = vcpu->arch.maar[
kvm_read_sw_gc0_maari(cop0)];
} else if ((rd == MIPS_CP0_PRID &&
(sel == 0 ||
sel == 2 ||
sel == 3)) ||
(rd == MIPS_CP0_STATUS &&
(sel == 2 ||
sel == 3)) ||
(rd == MIPS_CP0_CONFIG &&
(sel == 7)) ||
(rd == MIPS_CP0_LLADDR &&
(sel == 2) &&
cpu_guest_has_maar &&
!cpu_guest_has_dyn_maar) ||
(rd == MIPS_CP0_ERRCTL &&
(sel == 0))) {
val = cop0->reg[rd][sel];
} else {
val = 0;
er = EMULATE_FAIL;
}
if (er != EMULATE_FAIL) {
if (inst.c0r_format.rs == mfc_op)
val = (int)val;
vcpu->arch.gprs[rt] = val;
}
trace_kvm_hwr(vcpu, (inst.c0r_format.rs == mfc_op) ?
KVM_TRACE_MFC0 : KVM_TRACE_DMFC0,
KVM_TRACE_COP0(rd, sel), val);
break;
case dmtc_op:
case mtc_op:
#ifdef CONFIG_KVM_MIPS_DEBUG_COP0_COUNTERS
cop0->stat[rd][sel]++;
#endif
val = vcpu->arch.gprs[rt];
trace_kvm_hwr(vcpu, (inst.c0r_format.rs == mtc_op) ?
KVM_TRACE_MTC0 : KVM_TRACE_DMTC0,
KVM_TRACE_COP0(rd, sel), val);
if (rd == MIPS_CP0_COUNT &&
sel == 0) {
kvm_vz_lose_htimer(vcpu);
kvm_mips_write_count(vcpu, vcpu->arch.gprs[rt]);
} else if (rd == MIPS_CP0_COMPARE &&
sel == 0) {
kvm_mips_write_compare(vcpu,
vcpu->arch.gprs[rt],
true);
} else if (rd == MIPS_CP0_LLADDR &&
sel == 0) {
if (cpu_guest_has_rw_llb &&
!(val & MIPS_LLADDR_LLB))
write_gc0_lladdr(0);
} else if (rd == MIPS_CP0_LLADDR &&
sel == 1 &&
cpu_guest_has_maar &&
!cpu_guest_has_dyn_maar) {
val = mips_process_maar(inst.c0r_format.rs,
val);
BUG_ON(kvm_read_sw_gc0_maari(cop0) >=
ARRAY_SIZE(vcpu->arch.maar));
vcpu->arch.maar[kvm_read_sw_gc0_maari(cop0)] =
val;
} else if (rd == MIPS_CP0_LLADDR &&
(sel == 2) &&
cpu_guest_has_maar &&
!cpu_guest_has_dyn_maar) {
kvm_write_maari(vcpu, val);
} else if (rd == MIPS_CP0_ERRCTL &&
(sel == 0)) {
} else {
er = EMULATE_FAIL;
}
break;
default:
er = EMULATE_FAIL;
break;
}
}
if (er == EMULATE_FAIL) {
kvm_err("[%#lx]%s: unsupported cop0 instruction 0x%08x\n",
curr_pc, __func__, inst.word);
vcpu->arch.pc = curr_pc;
}
return er;
}
static enum emulation_result kvm_vz_gpsi_cache(union mips_instruction inst,
u32 *opc, u32 cause,
struct kvm_run *run,
struct kvm_vcpu *vcpu)
{
enum emulation_result er = EMULATE_DONE;
u32 cache, op_inst, op, base;
s16 offset;
struct kvm_vcpu_arch *arch = &vcpu->arch;
unsigned long va, curr_pc;
curr_pc = vcpu->arch.pc;
er = update_pc(vcpu, cause);
if (er == EMULATE_FAIL)
return er;
base = inst.i_format.rs;
op_inst = inst.i_format.rt;
if (cpu_has_mips_r6)
offset = inst.spec3_format.simmediate;
else
offset = inst.i_format.simmediate;
cache = op_inst & CacheOp_Cache;
op = op_inst & CacheOp_Op;
va = arch->gprs[base] + offset;
kvm_debug("CACHE (cache: %#x, op: %#x, base[%d]: %#lx, offset: %#x\n",
cache, op, base, arch->gprs[base], offset);
if (cache != Cache_I && cache != Cache_D)
return EMULATE_DONE;
switch (op_inst) {
case Index_Invalidate_I:
flush_icache_line_indexed(va);
return EMULATE_DONE;
case Index_Writeback_Inv_D:
flush_dcache_line_indexed(va);
return EMULATE_DONE;
case Hit_Invalidate_I:
case Hit_Invalidate_D:
case Hit_Writeback_Inv_D:
if (boot_cpu_type() == CPU_CAVIUM_OCTEON3) {
local_flush_icache_range(0, 0);
return EMULATE_DONE;
}
break;
default:
break;
};
kvm_err("@ %#lx/%#lx CACHE (cache: %#x, op: %#x, base[%d]: %#lx, offset: %#x\n",
curr_pc, vcpu->arch.gprs[31], cache, op, base, arch->gprs[base],
offset);
vcpu->arch.pc = curr_pc;
return EMULATE_FAIL;
}
static enum emulation_result kvm_trap_vz_handle_gpsi(u32 cause, u32 *opc,
struct kvm_vcpu *vcpu)
{
enum emulation_result er = EMULATE_DONE;
struct kvm_vcpu_arch *arch = &vcpu->arch;
struct kvm_run *run = vcpu->run;
union mips_instruction inst;
int rd, rt, sel;
int err;
if (cause & CAUSEF_BD)
opc += 1;
err = kvm_get_badinstr(opc, vcpu, &inst.word);
if (err)
return EMULATE_FAIL;
switch (inst.r_format.opcode) {
case cop0_op:
er = kvm_vz_gpsi_cop0(inst, opc, cause, run, vcpu);
break;
#ifndef CONFIG_CPU_MIPSR6
case cache_op:
trace_kvm_exit(vcpu, KVM_TRACE_EXIT_CACHE);
er = kvm_vz_gpsi_cache(inst, opc, cause, run, vcpu);
break;
#endif
case spec3_op:
switch (inst.spec3_format.func) {
#ifdef CONFIG_CPU_MIPSR6
case cache6_op:
trace_kvm_exit(vcpu, KVM_TRACE_EXIT_CACHE);
er = kvm_vz_gpsi_cache(inst, opc, cause, run, vcpu);
break;
#endif
case rdhwr_op:
if (inst.r_format.rs || (inst.r_format.re >> 3))
goto unknown;
rd = inst.r_format.rd;
rt = inst.r_format.rt;
sel = inst.r_format.re & 0x7;
switch (rd) {
case MIPS_HWR_CC:
arch->gprs[rt] =
(long)(int)kvm_mips_read_count(vcpu);
break;
default:
trace_kvm_hwr(vcpu, KVM_TRACE_RDHWR,
KVM_TRACE_HWR(rd, sel), 0);
goto unknown;
};
trace_kvm_hwr(vcpu, KVM_TRACE_RDHWR,
KVM_TRACE_HWR(rd, sel), arch->gprs[rt]);
er = update_pc(vcpu, cause);
break;
default:
goto unknown;
};
break;
unknown:
default:
kvm_err("GPSI exception not supported (%p/%#x)\n",
opc, inst.word);
kvm_arch_vcpu_dump_regs(vcpu);
er = EMULATE_FAIL;
break;
}
return er;
}
static enum emulation_result kvm_trap_vz_handle_gsfc(u32 cause, u32 *opc,
struct kvm_vcpu *vcpu)
{
enum emulation_result er = EMULATE_DONE;
struct kvm_vcpu_arch *arch = &vcpu->arch;
union mips_instruction inst;
int err;
if (cause & CAUSEF_BD)
opc += 1;
err = kvm_get_badinstr(opc, vcpu, &inst.word);
if (err)
return EMULATE_FAIL;
if (inst.c0r_format.opcode == cop0_op &&
inst.c0r_format.rs == mtc_op &&
inst.c0r_format.z == 0) {
int rt = inst.c0r_format.rt;
int rd = inst.c0r_format.rd;
int sel = inst.c0r_format.sel;
unsigned int val = arch->gprs[rt];
unsigned int old_val, change;
trace_kvm_hwr(vcpu, KVM_TRACE_MTC0, KVM_TRACE_COP0(rd, sel),
val);
if ((rd == MIPS_CP0_STATUS) && (sel == 0)) {
if (!kvm_mips_guest_has_fpu(&vcpu->arch))
val &= ~(ST0_CU1 | ST0_FR);
if (!(boot_cpu_data.fpu_id & MIPS_FPIR_F64))
val &= ~ST0_FR;
old_val = read_gc0_status();
change = val ^ old_val;
if (change & ST0_FR) {
kvm_drop_fpu(vcpu);
}
if (change & ST0_CU1 && !(val & ST0_FR) &&
vcpu->arch.aux_inuse & KVM_MIPS_AUX_MSA)
kvm_lose_fpu(vcpu);
write_gc0_status(val);
} else if ((rd == MIPS_CP0_CAUSE) && (sel == 0)) {
u32 old_cause = read_gc0_cause();
u32 change = old_cause ^ val;
if (change & CAUSEF_DC) {
if (val & CAUSEF_DC) {
kvm_vz_lose_htimer(vcpu);
kvm_mips_count_disable_cause(vcpu);
} else {
kvm_mips_count_enable_cause(vcpu);
}
}
change &= (CAUSEF_DC | CAUSEF_IV | CAUSEF_WP |
CAUSEF_IP0 | CAUSEF_IP1);
change &= ~CAUSEF_WP | old_cause;
write_gc0_cause(old_cause ^ change);
} else if ((rd == MIPS_CP0_STATUS) && (sel == 1)) {
write_gc0_intctl(val);
} else if ((rd == MIPS_CP0_CONFIG) && (sel == 5)) {
old_val = read_gc0_config5();
change = val ^ old_val;
preempt_disable();
if (change & MIPS_CONF5_FRE &&
vcpu->arch.aux_inuse & KVM_MIPS_AUX_FPU)
change_c0_config5(MIPS_CONF5_FRE, val);
preempt_enable();
val = old_val ^
(change & kvm_vz_config5_guest_wrmask(vcpu));
write_gc0_config5(val);
} else {
kvm_err("Handle GSFC, unsupported field change @ %p: %#x\n",
opc, inst.word);
er = EMULATE_FAIL;
}
if (er != EMULATE_FAIL)
er = update_pc(vcpu, cause);
} else {
kvm_err("Handle GSFC, unrecognized instruction @ %p: %#x\n",
opc, inst.word);
er = EMULATE_FAIL;
}
return er;
}
static enum emulation_result kvm_trap_vz_handle_ghfc(u32 cause, u32 *opc,
struct kvm_vcpu *vcpu)
{
trace_kvm_guest_mode_change(vcpu);
return EMULATE_DONE;
}
static enum emulation_result kvm_trap_vz_handle_hc(u32 cause, u32 *opc,
struct kvm_vcpu *vcpu)
{
enum emulation_result er;
union mips_instruction inst;
unsigned long curr_pc;
int err;
if (cause & CAUSEF_BD)
opc += 1;
err = kvm_get_badinstr(opc, vcpu, &inst.word);
if (err)
return EMULATE_FAIL;
curr_pc = vcpu->arch.pc;
er = update_pc(vcpu, cause);
if (er == EMULATE_FAIL)
return er;
er = kvm_mips_emul_hypcall(vcpu, inst);
if (er == EMULATE_FAIL)
vcpu->arch.pc = curr_pc;
return er;
}
static enum emulation_result kvm_trap_vz_no_handler_guest_exit(u32 gexccode,
u32 cause,
u32 *opc,
struct kvm_vcpu *vcpu)
{
u32 inst;
if (cause & CAUSEF_BD)
opc += 1;
kvm_get_badinstr(opc, vcpu, &inst);
kvm_err("Guest Exception Code: %d not yet handled @ PC: %p, inst: 0x%08x Status: %#x\n",
gexccode, opc, inst, read_gc0_status());
return EMULATE_FAIL;
}
static int kvm_trap_vz_handle_guest_exit(struct kvm_vcpu *vcpu)
{
u32 *opc = (u32 *) vcpu->arch.pc;
u32 cause = vcpu->arch.host_cp0_cause;
enum emulation_result er = EMULATE_DONE;
u32 gexccode = (vcpu->arch.host_cp0_guestctl0 &
MIPS_GCTL0_GEXC) >> MIPS_GCTL0_GEXC_SHIFT;
int ret = RESUME_GUEST;
trace_kvm_exit(vcpu, KVM_TRACE_EXIT_GEXCCODE_BASE + gexccode);
switch (gexccode) {
case MIPS_GCTL0_GEXC_GPSI:
++vcpu->stat.vz_gpsi_exits;
er = kvm_trap_vz_handle_gpsi(cause, opc, vcpu);
break;
case MIPS_GCTL0_GEXC_GSFC:
++vcpu->stat.vz_gsfc_exits;
er = kvm_trap_vz_handle_gsfc(cause, opc, vcpu);
break;
case MIPS_GCTL0_GEXC_HC:
++vcpu->stat.vz_hc_exits;
er = kvm_trap_vz_handle_hc(cause, opc, vcpu);
break;
case MIPS_GCTL0_GEXC_GRR:
++vcpu->stat.vz_grr_exits;
er = kvm_trap_vz_no_handler_guest_exit(gexccode, cause, opc,
vcpu);
break;
case MIPS_GCTL0_GEXC_GVA:
++vcpu->stat.vz_gva_exits;
er = kvm_trap_vz_no_handler_guest_exit(gexccode, cause, opc,
vcpu);
break;
case MIPS_GCTL0_GEXC_GHFC:
++vcpu->stat.vz_ghfc_exits;
er = kvm_trap_vz_handle_ghfc(cause, opc, vcpu);
break;
case MIPS_GCTL0_GEXC_GPA:
++vcpu->stat.vz_gpa_exits;
er = kvm_trap_vz_no_handler_guest_exit(gexccode, cause, opc,
vcpu);
break;
default:
++vcpu->stat.vz_resvd_exits;
er = kvm_trap_vz_no_handler_guest_exit(gexccode, cause, opc,
vcpu);
break;
}
if (er == EMULATE_DONE) {
ret = RESUME_GUEST;
} else if (er == EMULATE_HYPERCALL) {
ret = kvm_mips_handle_hypcall(vcpu);
} else {
vcpu->run->exit_reason = KVM_EXIT_INTERNAL_ERROR;
ret = RESUME_HOST;
}
return ret;
}
static int kvm_trap_vz_handle_cop_unusable(struct kvm_vcpu *vcpu)
{
struct kvm_run *run = vcpu->run;
u32 cause = vcpu->arch.host_cp0_cause;
enum emulation_result er = EMULATE_FAIL;
int ret = RESUME_GUEST;
if (((cause & CAUSEF_CE) >> CAUSEB_CE) == 1) {
if (WARN_ON(!kvm_mips_guest_has_fpu(&vcpu->arch) ||
vcpu->arch.aux_inuse & KVM_MIPS_AUX_FPU)) {
preempt_enable();
return EMULATE_FAIL;
}
kvm_own_fpu(vcpu);
er = EMULATE_DONE;
}
switch (er) {
case EMULATE_DONE:
ret = RESUME_GUEST;
break;
case EMULATE_FAIL:
run->exit_reason = KVM_EXIT_INTERNAL_ERROR;
ret = RESUME_HOST;
break;
default:
BUG();
}
return ret;
}
static int kvm_trap_vz_handle_msa_disabled(struct kvm_vcpu *vcpu)
{
struct kvm_run *run = vcpu->run;
if (!kvm_mips_guest_has_msa(&vcpu->arch) ||
(read_gc0_status() & (ST0_CU1 | ST0_FR)) == ST0_CU1 ||
!(read_gc0_config5() & MIPS_CONF5_MSAEN) ||
vcpu->arch.aux_inuse & KVM_MIPS_AUX_MSA) {
run->exit_reason = KVM_EXIT_INTERNAL_ERROR;
return RESUME_HOST;
}
kvm_own_msa(vcpu);
return RESUME_GUEST;
}
static int kvm_trap_vz_handle_tlb_ld_miss(struct kvm_vcpu *vcpu)
{
struct kvm_run *run = vcpu->run;
u32 *opc = (u32 *) vcpu->arch.pc;
u32 cause = vcpu->arch.host_cp0_cause;
ulong badvaddr = vcpu->arch.host_cp0_badvaddr;
union mips_instruction inst;
enum emulation_result er = EMULATE_DONE;
int err, ret = RESUME_GUEST;
if (kvm_mips_handle_vz_root_tlb_fault(badvaddr, vcpu, false)) {
if (kvm_is_ifetch_fault(&vcpu->arch)) {
run->exit_reason = KVM_EXIT_INTERNAL_ERROR;
return RESUME_HOST;
}
if (cause & CAUSEF_BD)
opc += 1;
err = kvm_get_badinstr(opc, vcpu, &inst.word);
if (err) {
run->exit_reason = KVM_EXIT_INTERNAL_ERROR;
return RESUME_HOST;
}
er = kvm_mips_emulate_load(inst, cause, run, vcpu);
if (er == EMULATE_FAIL) {
kvm_err("Guest Emulate Load from MMIO space failed: PC: %p, BadVaddr: %#lx\n",
opc, badvaddr);
run->exit_reason = KVM_EXIT_INTERNAL_ERROR;
}
}
if (er == EMULATE_DONE) {
ret = RESUME_GUEST;
} else if (er == EMULATE_DO_MMIO) {
run->exit_reason = KVM_EXIT_MMIO;
ret = RESUME_HOST;
} else {
run->exit_reason = KVM_EXIT_INTERNAL_ERROR;
ret = RESUME_HOST;
}
return ret;
}
static int kvm_trap_vz_handle_tlb_st_miss(struct kvm_vcpu *vcpu)
{
struct kvm_run *run = vcpu->run;
u32 *opc = (u32 *) vcpu->arch.pc;
u32 cause = vcpu->arch.host_cp0_cause;
ulong badvaddr = vcpu->arch.host_cp0_badvaddr;
union mips_instruction inst;
enum emulation_result er = EMULATE_DONE;
int err;
int ret = RESUME_GUEST;
if (kvm_vz_badvaddr_to_gpa(vcpu, badvaddr, &badvaddr))
return RESUME_GUEST;
vcpu->arch.host_cp0_badvaddr = badvaddr;
if (kvm_mips_handle_vz_root_tlb_fault(badvaddr, vcpu, true)) {
if (cause & CAUSEF_BD)
opc += 1;
err = kvm_get_badinstr(opc, vcpu, &inst.word);
if (err) {
run->exit_reason = KVM_EXIT_INTERNAL_ERROR;
return RESUME_HOST;
}
er = kvm_mips_emulate_store(inst, cause, run, vcpu);
if (er == EMULATE_FAIL) {
kvm_err("Guest Emulate Store to MMIO space failed: PC: %p, BadVaddr: %#lx\n",
opc, badvaddr);
run->exit_reason = KVM_EXIT_INTERNAL_ERROR;
}
}
if (er == EMULATE_DONE) {
ret = RESUME_GUEST;
} else if (er == EMULATE_DO_MMIO) {
run->exit_reason = KVM_EXIT_MMIO;
ret = RESUME_HOST;
} else {
run->exit_reason = KVM_EXIT_INTERNAL_ERROR;
ret = RESUME_HOST;
}
return ret;
}
static unsigned long kvm_vz_num_regs(struct kvm_vcpu *vcpu)
{
unsigned long ret;
ret = ARRAY_SIZE(kvm_vz_get_one_regs);
if (cpu_guest_has_userlocal)
++ret;
if (cpu_guest_has_badinstr)
++ret;
if (cpu_guest_has_badinstrp)
++ret;
if (cpu_guest_has_contextconfig)
ret += ARRAY_SIZE(kvm_vz_get_one_regs_contextconfig);
if (cpu_guest_has_segments)
ret += ARRAY_SIZE(kvm_vz_get_one_regs_segments);
if (cpu_guest_has_htw)
ret += ARRAY_SIZE(kvm_vz_get_one_regs_htw);
if (cpu_guest_has_maar && !cpu_guest_has_dyn_maar)
ret += 1 + ARRAY_SIZE(vcpu->arch.maar);
ret += __arch_hweight8(cpu_data[0].guest.kscratch_mask);
return ret;
}
static int kvm_vz_copy_reg_indices(struct kvm_vcpu *vcpu, u64 __user *indices)
{
u64 index;
unsigned int i;
if (copy_to_user(indices, kvm_vz_get_one_regs,
sizeof(kvm_vz_get_one_regs)))
return -EFAULT;
indices += ARRAY_SIZE(kvm_vz_get_one_regs);
if (cpu_guest_has_userlocal) {
index = KVM_REG_MIPS_CP0_USERLOCAL;
if (copy_to_user(indices, &index, sizeof(index)))
return -EFAULT;
++indices;
}
if (cpu_guest_has_badinstr) {
index = KVM_REG_MIPS_CP0_BADINSTR;
if (copy_to_user(indices, &index, sizeof(index)))
return -EFAULT;
++indices;
}
if (cpu_guest_has_badinstrp) {
index = KVM_REG_MIPS_CP0_BADINSTRP;
if (copy_to_user(indices, &index, sizeof(index)))
return -EFAULT;
++indices;
}
if (cpu_guest_has_contextconfig) {
if (copy_to_user(indices, kvm_vz_get_one_regs_contextconfig,
sizeof(kvm_vz_get_one_regs_contextconfig)))
return -EFAULT;
indices += ARRAY_SIZE(kvm_vz_get_one_regs_contextconfig);
}
if (cpu_guest_has_segments) {
if (copy_to_user(indices, kvm_vz_get_one_regs_segments,
sizeof(kvm_vz_get_one_regs_segments)))
return -EFAULT;
indices += ARRAY_SIZE(kvm_vz_get_one_regs_segments);
}
if (cpu_guest_has_htw) {
if (copy_to_user(indices, kvm_vz_get_one_regs_htw,
sizeof(kvm_vz_get_one_regs_htw)))
return -EFAULT;
indices += ARRAY_SIZE(kvm_vz_get_one_regs_htw);
}
if (cpu_guest_has_maar && !cpu_guest_has_dyn_maar) {
for (i = 0; i < ARRAY_SIZE(vcpu->arch.maar); ++i) {
index = KVM_REG_MIPS_CP0_MAAR(i);
if (copy_to_user(indices, &index, sizeof(index)))
return -EFAULT;
++indices;
}
index = KVM_REG_MIPS_CP0_MAARI;
if (copy_to_user(indices, &index, sizeof(index)))
return -EFAULT;
++indices;
}
for (i = 0; i < 6; ++i) {
if (!cpu_guest_has_kscr(i + 2))
continue;
if (copy_to_user(indices, &kvm_vz_get_one_regs_kscratch[i],
sizeof(kvm_vz_get_one_regs_kscratch[i])))
return -EFAULT;
++indices;
}
return 0;
}
static inline s64 entrylo_kvm_to_user(unsigned long v)
{
s64 mask, ret = v;
if (BITS_PER_LONG == 32) {
mask = MIPS_ENTRYLO_RI | MIPS_ENTRYLO_XI;
ret &= ~mask;
ret |= ((s64)v & mask) << 32;
}
return ret;
}
static inline unsigned long entrylo_user_to_kvm(s64 v)
{
unsigned long mask, ret = v;
if (BITS_PER_LONG == 32) {
mask = MIPS_ENTRYLO_RI | MIPS_ENTRYLO_XI;
ret &= ~mask;
ret |= (v >> 32) & mask;
}
return ret;
}
static int kvm_vz_get_one_reg(struct kvm_vcpu *vcpu,
const struct kvm_one_reg *reg,
s64 *v)
{
struct mips_coproc *cop0 = vcpu->arch.cop0;
unsigned int idx;
switch (reg->id) {
case KVM_REG_MIPS_CP0_INDEX:
*v = (long)read_gc0_index();
break;
case KVM_REG_MIPS_CP0_ENTRYLO0:
*v = entrylo_kvm_to_user(read_gc0_entrylo0());
break;
case KVM_REG_MIPS_CP0_ENTRYLO1:
*v = entrylo_kvm_to_user(read_gc0_entrylo1());
break;
case KVM_REG_MIPS_CP0_CONTEXT:
*v = (long)read_gc0_context();
break;
case KVM_REG_MIPS_CP0_CONTEXTCONFIG:
if (!cpu_guest_has_contextconfig)
return -EINVAL;
*v = read_gc0_contextconfig();
break;
case KVM_REG_MIPS_CP0_USERLOCAL:
if (!cpu_guest_has_userlocal)
return -EINVAL;
*v = read_gc0_userlocal();
break;
#ifdef CONFIG_64BIT
case KVM_REG_MIPS_CP0_XCONTEXTCONFIG:
if (!cpu_guest_has_contextconfig)
return -EINVAL;
*v = read_gc0_xcontextconfig();
break;
#endif
case KVM_REG_MIPS_CP0_PAGEMASK:
*v = (long)read_gc0_pagemask();
break;
case KVM_REG_MIPS_CP0_PAGEGRAIN:
*v = (long)read_gc0_pagegrain();
break;
case KVM_REG_MIPS_CP0_SEGCTL0:
if (!cpu_guest_has_segments)
return -EINVAL;
*v = read_gc0_segctl0();
break;
case KVM_REG_MIPS_CP0_SEGCTL1:
if (!cpu_guest_has_segments)
return -EINVAL;
*v = read_gc0_segctl1();
break;
case KVM_REG_MIPS_CP0_SEGCTL2:
if (!cpu_guest_has_segments)
return -EINVAL;
*v = read_gc0_segctl2();
break;
case KVM_REG_MIPS_CP0_PWBASE:
if (!cpu_guest_has_htw)
return -EINVAL;
*v = read_gc0_pwbase();
break;
case KVM_REG_MIPS_CP0_PWFIELD:
if (!cpu_guest_has_htw)
return -EINVAL;
*v = read_gc0_pwfield();
break;
case KVM_REG_MIPS_CP0_PWSIZE:
if (!cpu_guest_has_htw)
return -EINVAL;
*v = read_gc0_pwsize();
break;
case KVM_REG_MIPS_CP0_WIRED:
*v = (long)read_gc0_wired();
break;
case KVM_REG_MIPS_CP0_PWCTL:
if (!cpu_guest_has_htw)
return -EINVAL;
*v = read_gc0_pwctl();
break;
case KVM_REG_MIPS_CP0_HWRENA:
*v = (long)read_gc0_hwrena();
break;
case KVM_REG_MIPS_CP0_BADVADDR:
*v = (long)read_gc0_badvaddr();
break;
case KVM_REG_MIPS_CP0_BADINSTR:
if (!cpu_guest_has_badinstr)
return -EINVAL;
*v = read_gc0_badinstr();
break;
case KVM_REG_MIPS_CP0_BADINSTRP:
if (!cpu_guest_has_badinstrp)
return -EINVAL;
*v = read_gc0_badinstrp();
break;
case KVM_REG_MIPS_CP0_COUNT:
*v = kvm_mips_read_count(vcpu);
break;
case KVM_REG_MIPS_CP0_ENTRYHI:
*v = (long)read_gc0_entryhi();
break;
case KVM_REG_MIPS_CP0_COMPARE:
*v = (long)read_gc0_compare();
break;
case KVM_REG_MIPS_CP0_STATUS:
*v = (long)read_gc0_status();
break;
case KVM_REG_MIPS_CP0_INTCTL:
*v = read_gc0_intctl();
break;
case KVM_REG_MIPS_CP0_CAUSE:
*v = (long)read_gc0_cause();
break;
case KVM_REG_MIPS_CP0_EPC:
*v = (long)read_gc0_epc();
break;
case KVM_REG_MIPS_CP0_PRID:
switch (boot_cpu_type()) {
case CPU_CAVIUM_OCTEON3:
*v = read_gc0_prid();
break;
default:
*v = (long)kvm_read_c0_guest_prid(cop0);
break;
};
break;
case KVM_REG_MIPS_CP0_EBASE:
*v = kvm_vz_read_gc0_ebase();
break;
case KVM_REG_MIPS_CP0_CONFIG:
*v = read_gc0_config();
break;
case KVM_REG_MIPS_CP0_CONFIG1:
if (!cpu_guest_has_conf1)
return -EINVAL;
*v = read_gc0_config1();
break;
case KVM_REG_MIPS_CP0_CONFIG2:
if (!cpu_guest_has_conf2)
return -EINVAL;
*v = read_gc0_config2();
break;
case KVM_REG_MIPS_CP0_CONFIG3:
if (!cpu_guest_has_conf3)
return -EINVAL;
*v = read_gc0_config3();
break;
case KVM_REG_MIPS_CP0_CONFIG4:
if (!cpu_guest_has_conf4)
return -EINVAL;
*v = read_gc0_config4();
break;
case KVM_REG_MIPS_CP0_CONFIG5:
if (!cpu_guest_has_conf5)
return -EINVAL;
*v = read_gc0_config5();
break;
case KVM_REG_MIPS_CP0_MAAR(0) ... KVM_REG_MIPS_CP0_MAAR(0x3f):
if (!cpu_guest_has_maar || cpu_guest_has_dyn_maar)
return -EINVAL;
idx = reg->id - KVM_REG_MIPS_CP0_MAAR(0);
if (idx >= ARRAY_SIZE(vcpu->arch.maar))
return -EINVAL;
*v = vcpu->arch.maar[idx];
break;
case KVM_REG_MIPS_CP0_MAARI:
if (!cpu_guest_has_maar || cpu_guest_has_dyn_maar)
return -EINVAL;
*v = kvm_read_sw_gc0_maari(vcpu->arch.cop0);
break;
#ifdef CONFIG_64BIT
case KVM_REG_MIPS_CP0_XCONTEXT:
*v = read_gc0_xcontext();
break;
#endif
case KVM_REG_MIPS_CP0_ERROREPC:
*v = (long)read_gc0_errorepc();
break;
case KVM_REG_MIPS_CP0_KSCRATCH1 ... KVM_REG_MIPS_CP0_KSCRATCH6:
idx = reg->id - KVM_REG_MIPS_CP0_KSCRATCH1 + 2;
if (!cpu_guest_has_kscr(idx))
return -EINVAL;
switch (idx) {
case 2:
*v = (long)read_gc0_kscratch1();
break;
case 3:
*v = (long)read_gc0_kscratch2();
break;
case 4:
*v = (long)read_gc0_kscratch3();
break;
case 5:
*v = (long)read_gc0_kscratch4();
break;
case 6:
*v = (long)read_gc0_kscratch5();
break;
case 7:
*v = (long)read_gc0_kscratch6();
break;
}
break;
case KVM_REG_MIPS_COUNT_CTL:
*v = vcpu->arch.count_ctl;
break;
case KVM_REG_MIPS_COUNT_RESUME:
*v = ktime_to_ns(vcpu->arch.count_resume);
break;
case KVM_REG_MIPS_COUNT_HZ:
*v = vcpu->arch.count_hz;
break;
default:
return -EINVAL;
}
return 0;
}
static int kvm_vz_set_one_reg(struct kvm_vcpu *vcpu,
const struct kvm_one_reg *reg,
s64 v)
{
struct mips_coproc *cop0 = vcpu->arch.cop0;
unsigned int idx;
int ret = 0;
unsigned int cur, change;
switch (reg->id) {
case KVM_REG_MIPS_CP0_INDEX:
write_gc0_index(v);
break;
case KVM_REG_MIPS_CP0_ENTRYLO0:
write_gc0_entrylo0(entrylo_user_to_kvm(v));
break;
case KVM_REG_MIPS_CP0_ENTRYLO1:
write_gc0_entrylo1(entrylo_user_to_kvm(v));
break;
case KVM_REG_MIPS_CP0_CONTEXT:
write_gc0_context(v);
break;
case KVM_REG_MIPS_CP0_CONTEXTCONFIG:
if (!cpu_guest_has_contextconfig)
return -EINVAL;
write_gc0_contextconfig(v);
break;
case KVM_REG_MIPS_CP0_USERLOCAL:
if (!cpu_guest_has_userlocal)
return -EINVAL;
write_gc0_userlocal(v);
break;
#ifdef CONFIG_64BIT
case KVM_REG_MIPS_CP0_XCONTEXTCONFIG:
if (!cpu_guest_has_contextconfig)
return -EINVAL;
write_gc0_xcontextconfig(v);
break;
#endif
case KVM_REG_MIPS_CP0_PAGEMASK:
write_gc0_pagemask(v);
break;
case KVM_REG_MIPS_CP0_PAGEGRAIN:
write_gc0_pagegrain(v);
break;
case KVM_REG_MIPS_CP0_SEGCTL0:
if (!cpu_guest_has_segments)
return -EINVAL;
write_gc0_segctl0(v);
break;
case KVM_REG_MIPS_CP0_SEGCTL1:
if (!cpu_guest_has_segments)
return -EINVAL;
write_gc0_segctl1(v);
break;
case KVM_REG_MIPS_CP0_SEGCTL2:
if (!cpu_guest_has_segments)
return -EINVAL;
write_gc0_segctl2(v);
break;
case KVM_REG_MIPS_CP0_PWBASE:
if (!cpu_guest_has_htw)
return -EINVAL;
write_gc0_pwbase(v);
break;
case KVM_REG_MIPS_CP0_PWFIELD:
if (!cpu_guest_has_htw)
return -EINVAL;
write_gc0_pwfield(v);
break;
case KVM_REG_MIPS_CP0_PWSIZE:
if (!cpu_guest_has_htw)
return -EINVAL;
write_gc0_pwsize(v);
break;
case KVM_REG_MIPS_CP0_WIRED:
change_gc0_wired(MIPSR6_WIRED_WIRED, v);
break;
case KVM_REG_MIPS_CP0_PWCTL:
if (!cpu_guest_has_htw)
return -EINVAL;
write_gc0_pwctl(v);
break;
case KVM_REG_MIPS_CP0_HWRENA:
write_gc0_hwrena(v);
break;
case KVM_REG_MIPS_CP0_BADVADDR:
write_gc0_badvaddr(v);
break;
case KVM_REG_MIPS_CP0_BADINSTR:
if (!cpu_guest_has_badinstr)
return -EINVAL;
write_gc0_badinstr(v);
break;
case KVM_REG_MIPS_CP0_BADINSTRP:
if (!cpu_guest_has_badinstrp)
return -EINVAL;
write_gc0_badinstrp(v);
break;
case KVM_REG_MIPS_CP0_COUNT:
kvm_mips_write_count(vcpu, v);
break;
case KVM_REG_MIPS_CP0_ENTRYHI:
write_gc0_entryhi(v);
break;
case KVM_REG_MIPS_CP0_COMPARE:
kvm_mips_write_compare(vcpu, v, false);
break;
case KVM_REG_MIPS_CP0_STATUS:
write_gc0_status(v);
break;
case KVM_REG_MIPS_CP0_INTCTL:
write_gc0_intctl(v);
break;
case KVM_REG_MIPS_CP0_CAUSE:
if ((read_gc0_cause() ^ v) & CAUSEF_DC) {
if (v & CAUSEF_DC) {
kvm_mips_count_disable_cause(vcpu);
change_gc0_cause((u32)~CAUSEF_DC, v);
} else {
change_gc0_cause((u32)~CAUSEF_DC, v);
kvm_mips_count_enable_cause(vcpu);
}
} else {
write_gc0_cause(v);
}
break;
case KVM_REG_MIPS_CP0_EPC:
write_gc0_epc(v);
break;
case KVM_REG_MIPS_CP0_PRID:
switch (boot_cpu_type()) {
case CPU_CAVIUM_OCTEON3:
break;
default:
kvm_write_c0_guest_prid(cop0, v);
break;
};
break;
case KVM_REG_MIPS_CP0_EBASE:
kvm_vz_write_gc0_ebase(v);
break;
case KVM_REG_MIPS_CP0_CONFIG:
cur = read_gc0_config();
change = (cur ^ v) & kvm_vz_config_user_wrmask(vcpu);
if (change) {
v = cur ^ change;
write_gc0_config(v);
}
break;
case KVM_REG_MIPS_CP0_CONFIG1:
if (!cpu_guest_has_conf1)
break;
cur = read_gc0_config1();
change = (cur ^ v) & kvm_vz_config1_user_wrmask(vcpu);
if (change) {
v = cur ^ change;
write_gc0_config1(v);
}
break;
case KVM_REG_MIPS_CP0_CONFIG2:
if (!cpu_guest_has_conf2)
break;
cur = read_gc0_config2();
change = (cur ^ v) & kvm_vz_config2_user_wrmask(vcpu);
if (change) {
v = cur ^ change;
write_gc0_config2(v);
}
break;
case KVM_REG_MIPS_CP0_CONFIG3:
if (!cpu_guest_has_conf3)
break;
cur = read_gc0_config3();
change = (cur ^ v) & kvm_vz_config3_user_wrmask(vcpu);
if (change) {
v = cur ^ change;
write_gc0_config3(v);
}
break;
case KVM_REG_MIPS_CP0_CONFIG4:
if (!cpu_guest_has_conf4)
break;
cur = read_gc0_config4();
change = (cur ^ v) & kvm_vz_config4_user_wrmask(vcpu);
if (change) {
v = cur ^ change;
write_gc0_config4(v);
}
break;
case KVM_REG_MIPS_CP0_CONFIG5:
if (!cpu_guest_has_conf5)
break;
cur = read_gc0_config5();
change = (cur ^ v) & kvm_vz_config5_user_wrmask(vcpu);
if (change) {
v = cur ^ change;
write_gc0_config5(v);
}
break;
case KVM_REG_MIPS_CP0_MAAR(0) ... KVM_REG_MIPS_CP0_MAAR(0x3f):
if (!cpu_guest_has_maar || cpu_guest_has_dyn_maar)
return -EINVAL;
idx = reg->id - KVM_REG_MIPS_CP0_MAAR(0);
if (idx >= ARRAY_SIZE(vcpu->arch.maar))
return -EINVAL;
vcpu->arch.maar[idx] = mips_process_maar(dmtc_op, v);
break;
case KVM_REG_MIPS_CP0_MAARI:
if (!cpu_guest_has_maar || cpu_guest_has_dyn_maar)
return -EINVAL;
kvm_write_maari(vcpu, v);
break;
#ifdef CONFIG_64BIT
case KVM_REG_MIPS_CP0_XCONTEXT:
write_gc0_xcontext(v);
break;
#endif
case KVM_REG_MIPS_CP0_ERROREPC:
write_gc0_errorepc(v);
break;
case KVM_REG_MIPS_CP0_KSCRATCH1 ... KVM_REG_MIPS_CP0_KSCRATCH6:
idx = reg->id - KVM_REG_MIPS_CP0_KSCRATCH1 + 2;
if (!cpu_guest_has_kscr(idx))
return -EINVAL;
switch (idx) {
case 2:
write_gc0_kscratch1(v);
break;
case 3:
write_gc0_kscratch2(v);
break;
case 4:
write_gc0_kscratch3(v);
break;
case 5:
write_gc0_kscratch4(v);
break;
case 6:
write_gc0_kscratch5(v);
break;
case 7:
write_gc0_kscratch6(v);
break;
}
break;
case KVM_REG_MIPS_COUNT_CTL:
ret = kvm_mips_set_count_ctl(vcpu, v);
break;
case KVM_REG_MIPS_COUNT_RESUME:
ret = kvm_mips_set_count_resume(vcpu, v);
break;
case KVM_REG_MIPS_COUNT_HZ:
ret = kvm_mips_set_count_hz(vcpu, v);
break;
default:
return -EINVAL;
}
return ret;
}
static void kvm_vz_get_new_guestid(unsigned long cpu, struct kvm_vcpu *vcpu)
{
unsigned long guestid = guestid_cache(cpu);
if (!(++guestid & GUESTID_MASK)) {
if (cpu_has_vtag_icache)
flush_icache_all();
if (!guestid)
guestid = GUESTID_FIRST_VERSION;
++guestid;
kvm_vz_local_flush_roottlb_all_guests();
kvm_vz_local_flush_guesttlb_all();
}
guestid_cache(cpu) = guestid;
}
static int kvm_vz_check_requests(struct kvm_vcpu *vcpu, int cpu)
{
int ret = 0;
int i;
if (!vcpu->requests)
return 0;
if (kvm_check_request(KVM_REQ_TLB_FLUSH, vcpu)) {
if (cpu_has_guestid) {
for_each_possible_cpu(i)
vcpu->arch.vzguestid[i] = 0;
ret = 1;
}
}
return ret;
}
static void kvm_vz_vcpu_save_wired(struct kvm_vcpu *vcpu)
{
unsigned int wired = read_gc0_wired();
struct kvm_mips_tlb *tlbs;
int i;
wired &= MIPSR6_WIRED_WIRED;
if (wired > vcpu->arch.wired_tlb_limit) {
tlbs = krealloc(vcpu->arch.wired_tlb, wired *
sizeof(*vcpu->arch.wired_tlb), GFP_ATOMIC);
if (WARN_ON(!tlbs)) {
wired = vcpu->arch.wired_tlb_limit;
} else {
vcpu->arch.wired_tlb = tlbs;
vcpu->arch.wired_tlb_limit = wired;
}
}
if (wired)
kvm_vz_save_guesttlb(vcpu->arch.wired_tlb, 0, wired);
for (i = wired; i < vcpu->arch.wired_tlb_used; ++i) {
vcpu->arch.wired_tlb[i].tlb_hi = UNIQUE_GUEST_ENTRYHI(i);
vcpu->arch.wired_tlb[i].tlb_lo[0] = 0;
vcpu->arch.wired_tlb[i].tlb_lo[1] = 0;
vcpu->arch.wired_tlb[i].tlb_mask = 0;
}
vcpu->arch.wired_tlb_used = wired;
}
static void kvm_vz_vcpu_load_wired(struct kvm_vcpu *vcpu)
{
if (vcpu->arch.wired_tlb)
kvm_vz_load_guesttlb(vcpu->arch.wired_tlb, 0,
vcpu->arch.wired_tlb_used);
}
static void kvm_vz_vcpu_load_tlb(struct kvm_vcpu *vcpu, int cpu)
{
struct kvm *kvm = vcpu->kvm;
struct mm_struct *gpa_mm = &kvm->arch.gpa_mm;
bool migrated;
migrated = (vcpu->arch.last_exec_cpu != cpu);
vcpu->arch.last_exec_cpu = cpu;
if (cpu_has_guestid) {
if (migrated ||
(vcpu->arch.vzguestid[cpu] ^ guestid_cache(cpu)) &
GUESTID_VERSION_MASK) {
kvm_vz_get_new_guestid(cpu, vcpu);
vcpu->arch.vzguestid[cpu] = guestid_cache(cpu);
trace_kvm_guestid_change(vcpu,
vcpu->arch.vzguestid[cpu]);
}
change_c0_guestctl1(GUESTID_MASK, vcpu->arch.vzguestid[cpu]);
} else {
if (migrated || last_exec_vcpu[cpu] != vcpu)
kvm_vz_local_flush_guesttlb_all();
last_exec_vcpu[cpu] = vcpu;
if (cpumask_test_and_clear_cpu(cpu, &kvm->arch.asid_flush_mask)
|| (cpu_context(cpu, gpa_mm) ^ asid_cache(cpu)) &
asid_version_mask(cpu))
get_new_mmu_context(gpa_mm, cpu);
}
}
static int kvm_vz_vcpu_load(struct kvm_vcpu *vcpu, int cpu)
{
struct mips_coproc *cop0 = vcpu->arch.cop0;
bool migrated, all;
migrated = (vcpu->arch.last_sched_cpu != cpu);
all = migrated || (last_vcpu[cpu] != vcpu);
last_vcpu[cpu] = vcpu;
kvm_restore_gc0_wired(cop0);
if (current->flags & PF_VCPU) {
tlbw_use_hazard();
kvm_vz_vcpu_load_tlb(vcpu, cpu);
kvm_vz_vcpu_load_wired(vcpu);
}
kvm_vz_restore_timer(vcpu);
if (kvm_trace_guest_mode_change)
set_c0_guestctl0(MIPS_GCTL0_MC);
else
clear_c0_guestctl0(MIPS_GCTL0_MC);
if (!all)
return 0;
kvm_restore_gc0_config(cop0);
if (cpu_guest_has_conf1)
kvm_restore_gc0_config1(cop0);
if (cpu_guest_has_conf2)
kvm_restore_gc0_config2(cop0);
if (cpu_guest_has_conf3)
kvm_restore_gc0_config3(cop0);
if (cpu_guest_has_conf4)
kvm_restore_gc0_config4(cop0);
if (cpu_guest_has_conf5)
kvm_restore_gc0_config5(cop0);
if (cpu_guest_has_conf6)
kvm_restore_gc0_config6(cop0);
if (cpu_guest_has_conf7)
kvm_restore_gc0_config7(cop0);
kvm_restore_gc0_index(cop0);
kvm_restore_gc0_entrylo0(cop0);
kvm_restore_gc0_entrylo1(cop0);
kvm_restore_gc0_context(cop0);
if (cpu_guest_has_contextconfig)
kvm_restore_gc0_contextconfig(cop0);
#ifdef CONFIG_64BIT
kvm_restore_gc0_xcontext(cop0);
if (cpu_guest_has_contextconfig)
kvm_restore_gc0_xcontextconfig(cop0);
#endif
kvm_restore_gc0_pagemask(cop0);
kvm_restore_gc0_pagegrain(cop0);
kvm_restore_gc0_hwrena(cop0);
kvm_restore_gc0_badvaddr(cop0);
kvm_restore_gc0_entryhi(cop0);
kvm_restore_gc0_status(cop0);
kvm_restore_gc0_intctl(cop0);
kvm_restore_gc0_epc(cop0);
kvm_vz_write_gc0_ebase(kvm_read_sw_gc0_ebase(cop0));
if (cpu_guest_has_userlocal)
kvm_restore_gc0_userlocal(cop0);
kvm_restore_gc0_errorepc(cop0);
if (cpu_guest_has_conf4) {
if (cpu_guest_has_kscr(2))
kvm_restore_gc0_kscratch1(cop0);
if (cpu_guest_has_kscr(3))
kvm_restore_gc0_kscratch2(cop0);
if (cpu_guest_has_kscr(4))
kvm_restore_gc0_kscratch3(cop0);
if (cpu_guest_has_kscr(5))
kvm_restore_gc0_kscratch4(cop0);
if (cpu_guest_has_kscr(6))
kvm_restore_gc0_kscratch5(cop0);
if (cpu_guest_has_kscr(7))
kvm_restore_gc0_kscratch6(cop0);
}
if (cpu_guest_has_badinstr)
kvm_restore_gc0_badinstr(cop0);
if (cpu_guest_has_badinstrp)
kvm_restore_gc0_badinstrp(cop0);
if (cpu_guest_has_segments) {
kvm_restore_gc0_segctl0(cop0);
kvm_restore_gc0_segctl1(cop0);
kvm_restore_gc0_segctl2(cop0);
}
if (cpu_guest_has_htw) {
kvm_restore_gc0_pwbase(cop0);
kvm_restore_gc0_pwfield(cop0);
kvm_restore_gc0_pwsize(cop0);
kvm_restore_gc0_pwctl(cop0);
}
if (cpu_has_guestctl2)
write_c0_guestctl2(
cop0->reg[MIPS_CP0_GUESTCTL2][MIPS_CP0_GUESTCTL2_SEL]);
if (cpu_guest_has_rw_llb)
write_gc0_lladdr(0);
return 0;
}
static int kvm_vz_vcpu_put(struct kvm_vcpu *vcpu, int cpu)
{
struct mips_coproc *cop0 = vcpu->arch.cop0;
if (current->flags & PF_VCPU)
kvm_vz_vcpu_save_wired(vcpu);
kvm_lose_fpu(vcpu);
kvm_save_gc0_index(cop0);
kvm_save_gc0_entrylo0(cop0);
kvm_save_gc0_entrylo1(cop0);
kvm_save_gc0_context(cop0);
if (cpu_guest_has_contextconfig)
kvm_save_gc0_contextconfig(cop0);
#ifdef CONFIG_64BIT
kvm_save_gc0_xcontext(cop0);
if (cpu_guest_has_contextconfig)
kvm_save_gc0_xcontextconfig(cop0);
#endif
kvm_save_gc0_pagemask(cop0);
kvm_save_gc0_pagegrain(cop0);
kvm_save_gc0_wired(cop0);
clear_gc0_wired(MIPSR6_WIRED_WIRED);
kvm_save_gc0_hwrena(cop0);
kvm_save_gc0_badvaddr(cop0);
kvm_save_gc0_entryhi(cop0);
kvm_save_gc0_status(cop0);
kvm_save_gc0_intctl(cop0);
kvm_save_gc0_epc(cop0);
kvm_write_sw_gc0_ebase(cop0, kvm_vz_read_gc0_ebase());
if (cpu_guest_has_userlocal)
kvm_save_gc0_userlocal(cop0);
kvm_save_gc0_config(cop0);
if (cpu_guest_has_conf1)
kvm_save_gc0_config1(cop0);
if (cpu_guest_has_conf2)
kvm_save_gc0_config2(cop0);
if (cpu_guest_has_conf3)
kvm_save_gc0_config3(cop0);
if (cpu_guest_has_conf4)
kvm_save_gc0_config4(cop0);
if (cpu_guest_has_conf5)
kvm_save_gc0_config5(cop0);
if (cpu_guest_has_conf6)
kvm_save_gc0_config6(cop0);
if (cpu_guest_has_conf7)
kvm_save_gc0_config7(cop0);
kvm_save_gc0_errorepc(cop0);
if (cpu_guest_has_conf4) {
if (cpu_guest_has_kscr(2))
kvm_save_gc0_kscratch1(cop0);
if (cpu_guest_has_kscr(3))
kvm_save_gc0_kscratch2(cop0);
if (cpu_guest_has_kscr(4))
kvm_save_gc0_kscratch3(cop0);
if (cpu_guest_has_kscr(5))
kvm_save_gc0_kscratch4(cop0);
if (cpu_guest_has_kscr(6))
kvm_save_gc0_kscratch5(cop0);
if (cpu_guest_has_kscr(7))
kvm_save_gc0_kscratch6(cop0);
}
if (cpu_guest_has_badinstr)
kvm_save_gc0_badinstr(cop0);
if (cpu_guest_has_badinstrp)
kvm_save_gc0_badinstrp(cop0);
if (cpu_guest_has_segments) {
kvm_save_gc0_segctl0(cop0);
kvm_save_gc0_segctl1(cop0);
kvm_save_gc0_segctl2(cop0);
}
if (cpu_guest_has_htw &&
kvm_read_sw_gc0_config3(cop0) & MIPS_CONF3_PW) {
kvm_save_gc0_pwbase(cop0);
kvm_save_gc0_pwfield(cop0);
kvm_save_gc0_pwsize(cop0);
kvm_save_gc0_pwctl(cop0);
}
kvm_vz_save_timer(vcpu);
if (cpu_has_guestctl2)
cop0->reg[MIPS_CP0_GUESTCTL2][MIPS_CP0_GUESTCTL2_SEL] =
read_c0_guestctl2();
return 0;
}
static unsigned int kvm_vz_resize_guest_vtlb(unsigned int size)
{
unsigned int config4 = 0, ret = 0, limit;
if (cpu_guest_has_conf1)
change_gc0_config1(MIPS_CONF1_TLBS,
(size - 1) << MIPS_CONF1_TLBS_SHIFT);
if (cpu_guest_has_conf4) {
config4 = read_gc0_config4();
if (cpu_has_mips_r6 || (config4 & MIPS_CONF4_MMUEXTDEF) ==
MIPS_CONF4_MMUEXTDEF_VTLBSIZEEXT) {
config4 &= ~MIPS_CONF4_VTLBSIZEEXT;
config4 |= ((size - 1) >> MIPS_CONF1_TLBS_SIZE) <<
MIPS_CONF4_VTLBSIZEEXT_SHIFT;
} else if ((config4 & MIPS_CONF4_MMUEXTDEF) ==
MIPS_CONF4_MMUEXTDEF_MMUSIZEEXT) {
config4 &= ~MIPS_CONF4_MMUSIZEEXT;
config4 |= ((size - 1) >> MIPS_CONF1_TLBS_SIZE) <<
MIPS_CONF4_MMUSIZEEXT_SHIFT;
}
write_gc0_config4(config4);
}
if (cpu_has_mips_r6) {
limit = (read_c0_wired() & MIPSR6_WIRED_LIMIT) >>
MIPSR6_WIRED_LIMIT_SHIFT;
if (size - 1 <= limit)
limit = 0;
write_gc0_wired(limit << MIPSR6_WIRED_LIMIT_SHIFT);
}
back_to_back_c0_hazard();
if (cpu_guest_has_conf1)
ret = (read_gc0_config1() & MIPS_CONF1_TLBS) >>
MIPS_CONF1_TLBS_SHIFT;
if (config4) {
if (cpu_has_mips_r6 || (config4 & MIPS_CONF4_MMUEXTDEF) ==
MIPS_CONF4_MMUEXTDEF_VTLBSIZEEXT)
ret |= ((config4 & MIPS_CONF4_VTLBSIZEEXT) >>
MIPS_CONF4_VTLBSIZEEXT_SHIFT) <<
MIPS_CONF1_TLBS_SIZE;
else if ((config4 & MIPS_CONF4_MMUEXTDEF) ==
MIPS_CONF4_MMUEXTDEF_MMUSIZEEXT)
ret |= ((config4 & MIPS_CONF4_MMUSIZEEXT) >>
MIPS_CONF4_MMUSIZEEXT_SHIFT) <<
MIPS_CONF1_TLBS_SIZE;
}
return ret + 1;
}
static int kvm_vz_hardware_enable(void)
{
unsigned int mmu_size, guest_mmu_size, ftlb_size;
u64 guest_cvmctl, cvmvmconfig;
switch (current_cpu_type()) {
case CPU_CAVIUM_OCTEON3:
guest_cvmctl = read_gc0_cvmctl();
guest_cvmctl &= ~CVMCTL_IPTI;
guest_cvmctl |= 7ull << CVMCTL_IPTI_SHIFT;
guest_cvmctl &= ~CVMCTL_IPPCI;
guest_cvmctl |= 6ull << CVMCTL_IPPCI_SHIFT;
write_gc0_cvmctl(guest_cvmctl);
cvmvmconfig = read_c0_cvmvmconfig();
cvmvmconfig |= CVMVMCONF_DGHT;
mmu_size = ((cvmvmconfig & CVMVMCONF_MMUSIZEM1)
>> CVMVMCONF_MMUSIZEM1_S) + 1;
guest_mmu_size = mmu_size / 2;
mmu_size -= guest_mmu_size;
cvmvmconfig &= ~CVMVMCONF_RMMUSIZEM1;
cvmvmconfig |= mmu_size - 1;
write_c0_cvmvmconfig(cvmvmconfig);
current_cpu_data.tlbsize = mmu_size;
current_cpu_data.tlbsizevtlb = mmu_size;
current_cpu_data.guest.tlbsize = guest_mmu_size;
kvm_vz_local_flush_guesttlb_all();
break;
default:
mmu_size = current_cpu_data.tlbsizevtlb;
ftlb_size = current_cpu_data.tlbsize - mmu_size;
guest_mmu_size = kvm_vz_resize_guest_vtlb(mmu_size);
current_cpu_data.guest.tlbsize = guest_mmu_size + ftlb_size;
kvm_vz_local_flush_guesttlb_all();
guest_mmu_size = mmu_size - num_wired_entries() - 2;
guest_mmu_size = kvm_vz_resize_guest_vtlb(guest_mmu_size);
current_cpu_data.guest.tlbsize = guest_mmu_size + ftlb_size;
if (cmpxchg(&kvm_vz_guest_vtlb_size, 0, guest_mmu_size) &&
WARN(guest_mmu_size != kvm_vz_guest_vtlb_size,
"Available guest VTLB size mismatch"))
return -EINVAL;
break;
}
write_c0_guestctl0(MIPS_GCTL0_CP0 |
(MIPS_GCTL0_AT_GUEST << MIPS_GCTL0_AT_SHIFT) |
MIPS_GCTL0_CG | MIPS_GCTL0_CF);
if (cpu_has_guestctl0ext)
set_c0_guestctl0ext(MIPS_GCTL0EXT_CGI);
if (cpu_has_guestid) {
write_c0_guestctl1(0);
kvm_vz_local_flush_roottlb_all_guests();
GUESTID_MASK = current_cpu_data.guestid_mask;
GUESTID_FIRST_VERSION = GUESTID_MASK + 1;
GUESTID_VERSION_MASK = ~GUESTID_MASK;
current_cpu_data.guestid_cache = GUESTID_FIRST_VERSION;
}
if (cpu_has_guestctl2)
clear_c0_guestctl2(0x3f << 10);
return 0;
}
static void kvm_vz_hardware_disable(void)
{
u64 cvmvmconfig;
unsigned int mmu_size;
kvm_vz_local_flush_guesttlb_all();
switch (current_cpu_type()) {
case CPU_CAVIUM_OCTEON3:
cvmvmconfig = read_c0_cvmvmconfig();
mmu_size = ((cvmvmconfig & CVMVMCONF_MMUSIZEM1)
>> CVMVMCONF_MMUSIZEM1_S) + 1;
cvmvmconfig &= ~CVMVMCONF_RMMUSIZEM1;
cvmvmconfig |= mmu_size - 1;
write_c0_cvmvmconfig(cvmvmconfig);
current_cpu_data.tlbsize = mmu_size;
current_cpu_data.tlbsizevtlb = mmu_size;
current_cpu_data.guest.tlbsize = 0;
local_flush_tlb_all();
break;
}
if (cpu_has_guestid) {
write_c0_guestctl1(0);
kvm_vz_local_flush_roottlb_all_guests();
}
}
static int kvm_vz_check_extension(struct kvm *kvm, long ext)
{
int r;
switch (ext) {
case KVM_CAP_MIPS_VZ:
r = 1;
break;
#ifdef CONFIG_64BIT
case KVM_CAP_MIPS_64BIT:
r = 2;
break;
#endif
default:
r = 0;
break;
}
return r;
}
static int kvm_vz_vcpu_init(struct kvm_vcpu *vcpu)
{
int i;
for_each_possible_cpu(i)
vcpu->arch.vzguestid[i] = 0;
return 0;
}
static void kvm_vz_vcpu_uninit(struct kvm_vcpu *vcpu)
{
int cpu;
for_each_possible_cpu(cpu) {
if (last_vcpu[cpu] == vcpu)
last_vcpu[cpu] = NULL;
if (last_exec_vcpu[cpu] == vcpu)
last_exec_vcpu[cpu] = NULL;
}
}
static int kvm_vz_vcpu_setup(struct kvm_vcpu *vcpu)
{
struct mips_coproc *cop0 = vcpu->arch.cop0;
unsigned long count_hz = 100*1000*1000;
if (mips_hpt_frequency && mips_hpt_frequency <= NSEC_PER_SEC)
count_hz = mips_hpt_frequency;
kvm_mips_init_count(vcpu, count_hz);
if (cpu_has_mips_r6)
kvm_write_sw_gc0_pagegrain(cop0, PG_RIE | PG_XIE | PG_IEC);
if (cpu_has_mips_r6)
kvm_write_sw_gc0_wired(cop0,
read_gc0_wired() & MIPSR6_WIRED_LIMIT);
kvm_write_sw_gc0_status(cop0, ST0_BEV | ST0_ERL);
if (cpu_has_mips_r6)
kvm_change_sw_gc0_status(cop0, ST0_FR, read_gc0_status());
kvm_write_sw_gc0_intctl(cop0, read_gc0_intctl() &
(INTCTLF_IPFDC | INTCTLF_IPPCI | INTCTLF_IPTI));
kvm_write_sw_gc0_prid(cop0, boot_cpu_data.processor_id);
kvm_write_sw_gc0_ebase(cop0, (s32)0x80000000 | vcpu->vcpu_id);
kvm_save_gc0_config(cop0);
kvm_change_sw_gc0_config(cop0, CONF_CM_CMASK,
_page_cachable_default >> _CACHE_SHIFT);
kvm_change_sw_gc0_config(cop0, MIPS_CONF_MT, read_c0_config());
if (cpu_guest_has_conf1) {
kvm_set_sw_gc0_config(cop0, MIPS_CONF_M);
kvm_save_gc0_config1(cop0);
kvm_clear_sw_gc0_config1(cop0, MIPS_CONF1_C2 |
MIPS_CONF1_MD |
MIPS_CONF1_PC |
MIPS_CONF1_WR |
MIPS_CONF1_CA |
MIPS_CONF1_FP);
}
if (cpu_guest_has_conf2) {
kvm_set_sw_gc0_config1(cop0, MIPS_CONF_M);
kvm_save_gc0_config2(cop0);
}
if (cpu_guest_has_conf3) {
kvm_set_sw_gc0_config2(cop0, MIPS_CONF_M);
kvm_save_gc0_config3(cop0);
kvm_clear_sw_gc0_config3(cop0, MIPS_CONF3_ISA_OE);
kvm_clear_sw_gc0_config3(cop0, MIPS_CONF3_MSA |
MIPS_CONF3_BPG |
MIPS_CONF3_ULRI |
MIPS_CONF3_DSP |
MIPS_CONF3_CTXTC |
MIPS_CONF3_ITL |
MIPS_CONF3_LPA |
MIPS_CONF3_VEIC |
MIPS_CONF3_VINT |
MIPS_CONF3_SP |
MIPS_CONF3_CDMM |
MIPS_CONF3_MT |
MIPS_CONF3_SM |
MIPS_CONF3_TL);
}
if (cpu_guest_has_conf4) {
kvm_set_sw_gc0_config3(cop0, MIPS_CONF_M);
kvm_save_gc0_config4(cop0);
}
if (cpu_guest_has_conf5) {
kvm_set_sw_gc0_config4(cop0, MIPS_CONF_M);
kvm_save_gc0_config5(cop0);
kvm_clear_sw_gc0_config5(cop0, MIPS_CONF5_K |
MIPS_CONF5_CV |
MIPS_CONF5_MSAEN |
MIPS_CONF5_UFE |
MIPS_CONF5_FRE |
MIPS_CONF5_SBRI |
MIPS_CONF5_UFR);
kvm_clear_sw_gc0_config5(cop0, MIPS_CONF5_MRP);
}
if (cpu_guest_has_contextconfig) {
kvm_write_sw_gc0_contextconfig(cop0, 0x007ffff0);
#ifdef CONFIG_64BIT
kvm_write_sw_gc0_xcontextconfig(cop0,
((1ull << (cpu_vmbits - 13)) - 1) << 4);
#endif
}
if (cpu_guest_has_segments) {
kvm_write_sw_gc0_segctl0(cop0, 0x00200010);
kvm_write_sw_gc0_segctl1(cop0, 0x00000002 |
(_page_cachable_default >> _CACHE_SHIFT) <<
(16 + MIPS_SEGCFG_C_SHIFT));
kvm_write_sw_gc0_segctl2(cop0, 0x00380438);
}
if (cpu_guest_has_htw && cpu_has_mips_r6) {
kvm_write_sw_gc0_pwfield(cop0, 0x0c30c302);
kvm_write_sw_gc0_pwsize(cop0, 1 << MIPS_PWSIZE_PTW_SHIFT);
}
if (cpu_has_guestctl2)
cop0->reg[MIPS_CP0_GUESTCTL2][MIPS_CP0_GUESTCTL2_SEL] = 0;
vcpu->arch.pc = CKSEG1ADDR(0x1fc00000);
return 0;
}
static void kvm_vz_flush_shadow_all(struct kvm *kvm)
{
if (cpu_has_guestid) {
kvm_flush_remote_tlbs(kvm);
} else {
cpumask_setall(&kvm->arch.asid_flush_mask);
kvm_flush_remote_tlbs(kvm);
}
}
static void kvm_vz_flush_shadow_memslot(struct kvm *kvm,
const struct kvm_memory_slot *slot)
{
kvm_vz_flush_shadow_all(kvm);
}
static void kvm_vz_vcpu_reenter(struct kvm_run *run, struct kvm_vcpu *vcpu)
{
int cpu = smp_processor_id();
int preserve_guest_tlb;
preserve_guest_tlb = kvm_vz_check_requests(vcpu, cpu);
if (preserve_guest_tlb)
kvm_vz_vcpu_save_wired(vcpu);
kvm_vz_vcpu_load_tlb(vcpu, cpu);
if (preserve_guest_tlb)
kvm_vz_vcpu_load_wired(vcpu);
}
static int kvm_vz_vcpu_run(struct kvm_run *run, struct kvm_vcpu *vcpu)
{
int cpu = smp_processor_id();
int r;
kvm_vz_acquire_htimer(vcpu);
kvm_mips_deliver_interrupts(vcpu, read_gc0_cause());
kvm_vz_check_requests(vcpu, cpu);
kvm_vz_vcpu_load_tlb(vcpu, cpu);
kvm_vz_vcpu_load_wired(vcpu);
r = vcpu->arch.vcpu_run(run, vcpu);
kvm_vz_vcpu_save_wired(vcpu);
return r;
}
int kvm_mips_emulation_init(struct kvm_mips_callbacks **install_callbacks)
{
if (!cpu_has_vz)
return -ENODEV;
if (WARN(pgd_reg == -1,
"pgd_reg not allocated even though cpu_has_vz\n"))
return -ENODEV;
pr_info("Starting KVM with MIPS VZ extensions\n");
*install_callbacks = &kvm_vz_callbacks;
return 0;
}
