unsigned long kvm_compute_return_epc(struct kvm_vcpu *vcpu,
unsigned long instpc)
{
unsigned int dspcontrol;
union mips_instruction insn;
struct kvm_vcpu_arch *arch = &vcpu->arch;
long epc = instpc;
long nextpc = KVM_INVALID_INST;
if (epc & 3)
goto unaligned;
insn.word = kvm_get_inst((uint32_t *) epc, vcpu);
if (insn.word == KVM_INVALID_INST)
return KVM_INVALID_INST;
switch (insn.i_format.opcode) {
case spec_op:
switch (insn.r_format.func) {
case jalr_op:
arch->gprs[insn.r_format.rd] = epc + 8;
case jr_op:
nextpc = arch->gprs[insn.r_format.rs];
break;
}
break;
case bcond_op:
switch (insn.i_format.rt) {
case bltz_op:
case bltzl_op:
if ((long)arch->gprs[insn.i_format.rs] < 0)
epc = epc + 4 + (insn.i_format.simmediate << 2);
else
epc += 8;
nextpc = epc;
break;
case bgez_op:
case bgezl_op:
if ((long)arch->gprs[insn.i_format.rs] >= 0)
epc = epc + 4 + (insn.i_format.simmediate << 2);
else
epc += 8;
nextpc = epc;
break;
case bltzal_op:
case bltzall_op:
arch->gprs[31] = epc + 8;
if ((long)arch->gprs[insn.i_format.rs] < 0)
epc = epc + 4 + (insn.i_format.simmediate << 2);
else
epc += 8;
nextpc = epc;
break;
case bgezal_op:
case bgezall_op:
arch->gprs[31] = epc + 8;
if ((long)arch->gprs[insn.i_format.rs] >= 0)
epc = epc + 4 + (insn.i_format.simmediate << 2);
else
epc += 8;
nextpc = epc;
break;
case bposge32_op:
if (!cpu_has_dsp)
goto sigill;
dspcontrol = rddsp(0x01);
if (dspcontrol >= 32) {
epc = epc + 4 + (insn.i_format.simmediate << 2);
} else
epc += 8;
nextpc = epc;
break;
}
break;
case jal_op:
arch->gprs[31] = instpc + 8;
case j_op:
epc += 4;
epc >>= 28;
epc <<= 28;
epc |= (insn.j_format.target << 2);
nextpc = epc;
break;
case beq_op:
case beql_op:
if (arch->gprs[insn.i_format.rs] ==
arch->gprs[insn.i_format.rt])
epc = epc + 4 + (insn.i_format.simmediate << 2);
else
epc += 8;
nextpc = epc;
break;
case bne_op:
case bnel_op:
if (arch->gprs[insn.i_format.rs] !=
arch->gprs[insn.i_format.rt])
epc = epc + 4 + (insn.i_format.simmediate << 2);
else
epc += 8;
nextpc = epc;
break;
case blez_op:
case blezl_op:
if ((long)arch->gprs[insn.i_format.rs] <= 0)
epc = epc + 4 + (insn.i_format.simmediate << 2);
else
epc += 8;
nextpc = epc;
break;
case bgtz_op:
case bgtzl_op:
if ((long)arch->gprs[insn.i_format.rs] > 0)
epc = epc + 4 + (insn.i_format.simmediate << 2);
else
epc += 8;
nextpc = epc;
break;
case cop1_op:
printk("%s: unsupported cop1_op\n", __func__);
break;
}
return nextpc;
unaligned:
printk("%s: unaligned epc\n", __func__);
return nextpc;
sigill:
printk("%s: DSP branch but not DSP ASE\n", __func__);
return nextpc;
}
enum emulation_result update_pc(struct kvm_vcpu *vcpu, uint32_t cause)
{
unsigned long branch_pc;
enum emulation_result er = EMULATE_DONE;
if (cause & CAUSEF_BD) {
branch_pc = kvm_compute_return_epc(vcpu, vcpu->arch.pc);
if (branch_pc == KVM_INVALID_INST) {
er = EMULATE_FAIL;
} else {
vcpu->arch.pc = branch_pc;
kvm_debug("BD update_pc(): New PC: %#lx\n", vcpu->arch.pc);
}
} else
vcpu->arch.pc += 4;
kvm_debug("update_pc(): New PC: %#lx\n", vcpu->arch.pc);
return er;
}
static inline int kvm_mips_count_disabled(struct kvm_vcpu *vcpu)
{
struct mips_coproc *cop0 = vcpu->arch.cop0;
return (vcpu->arch.count_ctl & KVM_REG_MIPS_COUNT_CTL_DC) ||
(kvm_read_c0_guest_cause(cop0) & CAUSEF_DC);
}
static uint32_t kvm_mips_ktime_to_count(struct kvm_vcpu *vcpu, ktime_t now)
{
s64 now_ns, periods;
u64 delta;
now_ns = ktime_to_ns(now);
delta = now_ns + vcpu->arch.count_dyn_bias;
if (delta >= vcpu->arch.count_period) {
periods = div64_s64(now_ns, vcpu->arch.count_period);
vcpu->arch.count_dyn_bias = -periods * vcpu->arch.count_period;
delta = now_ns + vcpu->arch.count_dyn_bias;
}
return div_u64(delta * vcpu->arch.count_hz, NSEC_PER_SEC);
}
static inline ktime_t kvm_mips_count_time(struct kvm_vcpu *vcpu)
{
if (unlikely(vcpu->arch.count_ctl & KVM_REG_MIPS_COUNT_CTL_DC))
return vcpu->arch.count_resume;
return ktime_get();
}
static uint32_t kvm_mips_read_count_running(struct kvm_vcpu *vcpu, ktime_t now)
{
ktime_t expires;
int running;
expires = hrtimer_get_expires(&vcpu->arch.comparecount_timer);
if (ktime_compare(now, expires) >= 0) {
running = hrtimer_cancel(&vcpu->arch.comparecount_timer);
kvm_mips_callbacks->queue_timer_int(vcpu);
if (running) {
expires = ktime_add_ns(expires,
vcpu->arch.count_period);
hrtimer_start(&vcpu->arch.comparecount_timer, expires,
HRTIMER_MODE_ABS);
}
}
return vcpu->arch.count_bias + kvm_mips_ktime_to_count(vcpu, now);
}
uint32_t kvm_mips_read_count(struct kvm_vcpu *vcpu)
{
struct mips_coproc *cop0 = vcpu->arch.cop0;
if (kvm_mips_count_disabled(vcpu))
return kvm_read_c0_guest_count(cop0);
return kvm_mips_read_count_running(vcpu, ktime_get());
}
static ktime_t kvm_mips_freeze_hrtimer(struct kvm_vcpu *vcpu,
uint32_t *count)
{
ktime_t now;
hrtimer_cancel(&vcpu->arch.comparecount_timer);
now = ktime_get();
*count = kvm_mips_read_count_running(vcpu, now);
return now;
}
static void kvm_mips_resume_hrtimer(struct kvm_vcpu *vcpu,
ktime_t now, uint32_t count)
{
struct mips_coproc *cop0 = vcpu->arch.cop0;
uint32_t compare;
u64 delta;
ktime_t expire;
compare = kvm_read_c0_guest_compare(cop0);
delta = (u64)(uint32_t)(compare - count - 1) + 1;
delta = div_u64(delta * NSEC_PER_SEC, vcpu->arch.count_hz);
expire = ktime_add_ns(now, delta);
hrtimer_cancel(&vcpu->arch.comparecount_timer);
hrtimer_start(&vcpu->arch.comparecount_timer, expire, HRTIMER_MODE_ABS);
}
static void kvm_mips_update_hrtimer(struct kvm_vcpu *vcpu)
{
ktime_t now;
uint32_t count;
now = kvm_mips_freeze_hrtimer(vcpu, &count);
kvm_mips_resume_hrtimer(vcpu, now, count);
}
void kvm_mips_write_count(struct kvm_vcpu *vcpu, uint32_t count)
{
struct mips_coproc *cop0 = vcpu->arch.cop0;
ktime_t now;
now = kvm_mips_count_time(vcpu);
vcpu->arch.count_bias = count - kvm_mips_ktime_to_count(vcpu, now);
if (kvm_mips_count_disabled(vcpu))
kvm_write_c0_guest_count(cop0, count);
else
kvm_mips_resume_hrtimer(vcpu, now, count);
}
void kvm_mips_init_count(struct kvm_vcpu *vcpu)
{
vcpu->arch.count_hz = 100*1000*1000;
vcpu->arch.count_period = div_u64((u64)NSEC_PER_SEC << 32,
vcpu->arch.count_hz);
vcpu->arch.count_dyn_bias = 0;
kvm_mips_write_count(vcpu, 0);
}
int kvm_mips_set_count_hz(struct kvm_vcpu *vcpu, s64 count_hz)
{
struct mips_coproc *cop0 = vcpu->arch.cop0;
int dc;
ktime_t now;
u32 count;
if (count_hz <= 0 || count_hz > NSEC_PER_SEC)
return -EINVAL;
if (vcpu->arch.count_hz == count_hz)
return 0;
dc = kvm_mips_count_disabled(vcpu);
if (dc) {
now = kvm_mips_count_time(vcpu);
count = kvm_read_c0_guest_count(cop0);
} else {
now = kvm_mips_freeze_hrtimer(vcpu, &count);
}
vcpu->arch.count_hz = count_hz;
vcpu->arch.count_period = div_u64((u64)NSEC_PER_SEC << 32, count_hz);
vcpu->arch.count_dyn_bias = 0;
vcpu->arch.count_bias = count - kvm_mips_ktime_to_count(vcpu, now);
if (!dc)
kvm_mips_resume_hrtimer(vcpu, now, count);
return 0;
}
void kvm_mips_write_compare(struct kvm_vcpu *vcpu, uint32_t compare)
{
struct mips_coproc *cop0 = vcpu->arch.cop0;
if (kvm_read_c0_guest_compare(cop0) == compare)
return;
kvm_write_c0_guest_compare(cop0, compare);
if (!kvm_mips_count_disabled(vcpu))
kvm_mips_update_hrtimer(vcpu);
}
static ktime_t kvm_mips_count_disable(struct kvm_vcpu *vcpu)
{
struct mips_coproc *cop0 = vcpu->arch.cop0;
uint32_t count;
ktime_t now;
hrtimer_cancel(&vcpu->arch.comparecount_timer);
now = ktime_get();
count = kvm_mips_read_count_running(vcpu, now);
kvm_write_c0_guest_count(cop0, count);
return now;
}
void kvm_mips_count_disable_cause(struct kvm_vcpu *vcpu)
{
struct mips_coproc *cop0 = vcpu->arch.cop0;
kvm_set_c0_guest_cause(cop0, CAUSEF_DC);
if (!(vcpu->arch.count_ctl & KVM_REG_MIPS_COUNT_CTL_DC))
kvm_mips_count_disable(vcpu);
}
void kvm_mips_count_enable_cause(struct kvm_vcpu *vcpu)
{
struct mips_coproc *cop0 = vcpu->arch.cop0;
uint32_t count;
kvm_clear_c0_guest_cause(cop0, CAUSEF_DC);
count = kvm_read_c0_guest_count(cop0);
kvm_mips_write_count(vcpu, count);
}
int kvm_mips_set_count_ctl(struct kvm_vcpu *vcpu, s64 count_ctl)
{
struct mips_coproc *cop0 = vcpu->arch.cop0;
s64 changed = count_ctl ^ vcpu->arch.count_ctl;
s64 delta;
ktime_t expire, now;
uint32_t count, compare;
if (changed & ~(s64)(KVM_REG_MIPS_COUNT_CTL_DC))
return -EINVAL;
vcpu->arch.count_ctl = count_ctl;
if (changed & KVM_REG_MIPS_COUNT_CTL_DC) {
if (kvm_read_c0_guest_cause(cop0) & CAUSEF_DC) {
if (count_ctl & KVM_REG_MIPS_COUNT_CTL_DC)
vcpu->arch.count_resume = ktime_get();
} else if (count_ctl & KVM_REG_MIPS_COUNT_CTL_DC) {
vcpu->arch.count_resume = kvm_mips_count_disable(vcpu);
} else {
count = kvm_read_c0_guest_count(cop0);
compare = kvm_read_c0_guest_compare(cop0);
delta = (u64)(uint32_t)(compare - count - 1) + 1;
delta = div_u64(delta * NSEC_PER_SEC,
vcpu->arch.count_hz);
expire = ktime_add_ns(vcpu->arch.count_resume, delta);
now = ktime_get();
if (ktime_compare(now, expire) >= 0)
kvm_mips_callbacks->queue_timer_int(vcpu);
count = kvm_mips_read_count_running(vcpu, now);
kvm_mips_resume_hrtimer(vcpu, now, count);
}
}
return 0;
}
int kvm_mips_set_count_resume(struct kvm_vcpu *vcpu, s64 count_resume)
{
if (count_resume < 0 || count_resume > ktime_to_ns(ktime_get()))
return -EINVAL;
vcpu->arch.count_resume = ns_to_ktime(count_resume);
return 0;
}
enum hrtimer_restart kvm_mips_count_timeout(struct kvm_vcpu *vcpu)
{
hrtimer_add_expires_ns(&vcpu->arch.comparecount_timer,
vcpu->arch.count_period);
return HRTIMER_RESTART;
}
enum emulation_result kvm_mips_emul_eret(struct kvm_vcpu *vcpu)
{
struct mips_coproc *cop0 = vcpu->arch.cop0;
enum emulation_result er = EMULATE_DONE;
if (kvm_read_c0_guest_status(cop0) & ST0_EXL) {
kvm_debug("[%#lx] ERET to %#lx\n", vcpu->arch.pc,
kvm_read_c0_guest_epc(cop0));
kvm_clear_c0_guest_status(cop0, ST0_EXL);
vcpu->arch.pc = kvm_read_c0_guest_epc(cop0);
} else if (kvm_read_c0_guest_status(cop0) & ST0_ERL) {
kvm_clear_c0_guest_status(cop0, ST0_ERL);
vcpu->arch.pc = kvm_read_c0_guest_errorepc(cop0);
} else {
printk("[%#lx] ERET when MIPS_SR_EXL|MIPS_SR_ERL == 0\n",
vcpu->arch.pc);
er = EMULATE_FAIL;
}
return er;
}
enum emulation_result kvm_mips_emul_wait(struct kvm_vcpu *vcpu)
{
enum emulation_result er = EMULATE_DONE;
kvm_debug("[%#lx] !!!WAIT!!! (%#lx)\n", vcpu->arch.pc,
vcpu->arch.pending_exceptions);
++vcpu->stat.wait_exits;
trace_kvm_exit(vcpu, WAIT_EXITS);
if (!vcpu->arch.pending_exceptions) {
vcpu->arch.wait = 1;
kvm_vcpu_block(vcpu);
if (kvm_check_request(KVM_REQ_UNHALT, vcpu)) {
clear_bit(KVM_REQ_UNHALT, &vcpu->requests);
vcpu->run->exit_reason = KVM_EXIT_IRQ_WINDOW_OPEN;
}
}
return er;
}
enum emulation_result kvm_mips_emul_tlbr(struct kvm_vcpu *vcpu)
{
struct mips_coproc *cop0 = vcpu->arch.cop0;
enum emulation_result er = EMULATE_FAIL;
uint32_t pc = vcpu->arch.pc;
printk("[%#x] COP0_TLBR [%ld]\n", pc, kvm_read_c0_guest_index(cop0));
return er;
}
enum emulation_result kvm_mips_emul_tlbwi(struct kvm_vcpu *vcpu)
{
struct mips_coproc *cop0 = vcpu->arch.cop0;
int index = kvm_read_c0_guest_index(cop0);
enum emulation_result er = EMULATE_DONE;
struct kvm_mips_tlb *tlb = NULL;
uint32_t pc = vcpu->arch.pc;
if (index < 0 || index >= KVM_MIPS_GUEST_TLB_SIZE) {
printk("%s: illegal index: %d\n", __func__, index);
printk
("[%#x] COP0_TLBWI [%d] (entryhi: %#lx, entrylo0: %#lx entrylo1: %#lx, mask: %#lx)\n",
pc, index, kvm_read_c0_guest_entryhi(cop0),
kvm_read_c0_guest_entrylo0(cop0),
kvm_read_c0_guest_entrylo1(cop0),
kvm_read_c0_guest_pagemask(cop0));
index = (index & ~0x80000000) % KVM_MIPS_GUEST_TLB_SIZE;
}
tlb = &vcpu->arch.guest_tlb[index];
#if 1
kvm_mips_host_tlb_inv(vcpu, tlb->tlb_hi);
#endif
tlb->tlb_mask = kvm_read_c0_guest_pagemask(cop0);
tlb->tlb_hi = kvm_read_c0_guest_entryhi(cop0);
tlb->tlb_lo0 = kvm_read_c0_guest_entrylo0(cop0);
tlb->tlb_lo1 = kvm_read_c0_guest_entrylo1(cop0);
kvm_debug
("[%#x] COP0_TLBWI [%d] (entryhi: %#lx, entrylo0: %#lx entrylo1: %#lx, mask: %#lx)\n",
pc, index, kvm_read_c0_guest_entryhi(cop0),
kvm_read_c0_guest_entrylo0(cop0), kvm_read_c0_guest_entrylo1(cop0),
kvm_read_c0_guest_pagemask(cop0));
return er;
}
enum emulation_result kvm_mips_emul_tlbwr(struct kvm_vcpu *vcpu)
{
struct mips_coproc *cop0 = vcpu->arch.cop0;
enum emulation_result er = EMULATE_DONE;
struct kvm_mips_tlb *tlb = NULL;
uint32_t pc = vcpu->arch.pc;
int index;
#if 1
get_random_bytes(&index, sizeof(index));
index &= (KVM_MIPS_GUEST_TLB_SIZE - 1);
#else
index = jiffies % KVM_MIPS_GUEST_TLB_SIZE;
#endif
if (index < 0 || index >= KVM_MIPS_GUEST_TLB_SIZE) {
printk("%s: illegal index: %d\n", __func__, index);
return EMULATE_FAIL;
}
tlb = &vcpu->arch.guest_tlb[index];
#if 1
kvm_mips_host_tlb_inv(vcpu, tlb->tlb_hi);
#endif
tlb->tlb_mask = kvm_read_c0_guest_pagemask(cop0);
tlb->tlb_hi = kvm_read_c0_guest_entryhi(cop0);
tlb->tlb_lo0 = kvm_read_c0_guest_entrylo0(cop0);
tlb->tlb_lo1 = kvm_read_c0_guest_entrylo1(cop0);
kvm_debug
("[%#x] COP0_TLBWR[%d] (entryhi: %#lx, entrylo0: %#lx entrylo1: %#lx)\n",
pc, index, kvm_read_c0_guest_entryhi(cop0),
kvm_read_c0_guest_entrylo0(cop0),
kvm_read_c0_guest_entrylo1(cop0));
return er;
}
enum emulation_result kvm_mips_emul_tlbp(struct kvm_vcpu *vcpu)
{
struct mips_coproc *cop0 = vcpu->arch.cop0;
long entryhi = kvm_read_c0_guest_entryhi(cop0);
enum emulation_result er = EMULATE_DONE;
uint32_t pc = vcpu->arch.pc;
int index = -1;
index = kvm_mips_guest_tlb_lookup(vcpu, entryhi);
kvm_write_c0_guest_index(cop0, index);
kvm_debug("[%#x] COP0_TLBP (entryhi: %#lx), index: %d\n", pc, entryhi,
index);
return er;
}
enum emulation_result
kvm_mips_emulate_CP0(uint32_t inst, uint32_t *opc, uint32_t cause,
struct kvm_run *run, struct kvm_vcpu *vcpu)
{
struct mips_coproc *cop0 = vcpu->arch.cop0;
enum emulation_result er = EMULATE_DONE;
int32_t rt, rd, copz, sel, co_bit, op;
uint32_t pc = vcpu->arch.pc;
unsigned long curr_pc;
curr_pc = vcpu->arch.pc;
er = update_pc(vcpu, cause);
if (er == EMULATE_FAIL) {
return er;
}
copz = (inst >> 21) & 0x1f;
rt = (inst >> 16) & 0x1f;
rd = (inst >> 11) & 0x1f;
sel = inst & 0x7;
co_bit = (inst >> 25) & 1;
if (co_bit) {
op = (inst) & 0xff;
switch (op) {
case tlbr_op:
er = kvm_mips_emul_tlbr(vcpu);
break;
case tlbwi_op:
er = kvm_mips_emul_tlbwi(vcpu);
break;
case tlbwr_op:
er = kvm_mips_emul_tlbwr(vcpu);
break;
case tlbp_op:
er = kvm_mips_emul_tlbp(vcpu);
break;
case rfe_op:
printk("!!!COP0_RFE!!!\n");
break;
case eret_op:
er = kvm_mips_emul_eret(vcpu);
goto dont_update_pc;
break;
case wait_op:
er = kvm_mips_emul_wait(vcpu);
break;
}
} else {
switch (copz) {
case mfc_op:
#ifdef CONFIG_KVM_MIPS_DEBUG_COP0_COUNTERS
cop0->stat[rd][sel]++;
#endif
if ((rd == MIPS_CP0_COUNT) && (sel == 0)) {
vcpu->arch.gprs[rt] = kvm_mips_read_count(vcpu);
} else if ((rd == MIPS_CP0_ERRCTL) && (sel == 0)) {
vcpu->arch.gprs[rt] = 0x0;
#ifdef CONFIG_KVM_MIPS_DYN_TRANS
kvm_mips_trans_mfc0(inst, opc, vcpu);
#endif
}
else {
vcpu->arch.gprs[rt] = cop0->reg[rd][sel];
#ifdef CONFIG_KVM_MIPS_DYN_TRANS
kvm_mips_trans_mfc0(inst, opc, vcpu);
#endif
}
kvm_debug
("[%#x] MFCz[%d][%d], vcpu->arch.gprs[%d]: %#lx\n",
pc, rd, sel, rt, vcpu->arch.gprs[rt]);
break;
case dmfc_op:
vcpu->arch.gprs[rt] = cop0->reg[rd][sel];
break;
case mtc_op:
#ifdef CONFIG_KVM_MIPS_DEBUG_COP0_COUNTERS
cop0->stat[rd][sel]++;
#endif
if ((rd == MIPS_CP0_TLB_INDEX)
&& (vcpu->arch.gprs[rt] >=
KVM_MIPS_GUEST_TLB_SIZE)) {
printk("Invalid TLB Index: %ld",
vcpu->arch.gprs[rt]);
er = EMULATE_FAIL;
break;
}
#define C0_EBASE_CORE_MASK 0xff
if ((rd == MIPS_CP0_PRID) && (sel == 1)) {
kvm_change_c0_guest_ebase(cop0,
~(C0_EBASE_CORE_MASK),
vcpu->arch.gprs[rt]);
printk("MTCz, cop0->reg[EBASE]: %#lx\n",
kvm_read_c0_guest_ebase(cop0));
} else if (rd == MIPS_CP0_TLB_HI && sel == 0) {
uint32_t nasid =
vcpu->arch.gprs[rt] & ASID_MASK;
if ((KSEGX(vcpu->arch.gprs[rt]) != CKSEG0)
&&
((kvm_read_c0_guest_entryhi(cop0) &
ASID_MASK) != nasid)) {
kvm_debug
("MTCz, change ASID from %#lx to %#lx\n",
kvm_read_c0_guest_entryhi(cop0) &
ASID_MASK,
vcpu->arch.gprs[rt] & ASID_MASK);
kvm_mips_flush_host_tlb(1);
}
kvm_write_c0_guest_entryhi(cop0,
vcpu->arch.gprs[rt]);
}
else if ((rd == MIPS_CP0_COUNT) && (sel == 0)) {
kvm_mips_write_count(vcpu, vcpu->arch.gprs[rt]);
goto done;
} else if ((rd == MIPS_CP0_COMPARE) && (sel == 0)) {
kvm_debug("[%#x] MTCz, COMPARE %#lx <- %#lx\n",
pc, kvm_read_c0_guest_compare(cop0),
vcpu->arch.gprs[rt]);
kvm_mips_callbacks->dequeue_timer_int(vcpu);
kvm_mips_write_compare(vcpu,
vcpu->arch.gprs[rt]);
} else if ((rd == MIPS_CP0_STATUS) && (sel == 0)) {
kvm_write_c0_guest_status(cop0,
vcpu->arch.gprs[rt]);
kvm_clear_c0_guest_status(cop0,
(ST0_CU1 | ST0_NMI));
#ifdef CONFIG_KVM_MIPS_DYN_TRANS
kvm_mips_trans_mtc0(inst, opc, vcpu);
#endif
} else if ((rd == MIPS_CP0_CAUSE) && (sel == 0)) {
uint32_t old_cause, new_cause;
old_cause = kvm_read_c0_guest_cause(cop0);
new_cause = vcpu->arch.gprs[rt];
kvm_change_c0_guest_cause(cop0, 0x08800300,
new_cause);
if ((old_cause ^ new_cause) & CAUSEF_DC) {
if (new_cause & CAUSEF_DC)
kvm_mips_count_disable_cause(vcpu);
else
kvm_mips_count_enable_cause(vcpu);
}
} else {
cop0->reg[rd][sel] = vcpu->arch.gprs[rt];
#ifdef CONFIG_KVM_MIPS_DYN_TRANS
kvm_mips_trans_mtc0(inst, opc, vcpu);
#endif
}
kvm_debug("[%#x] MTCz, cop0->reg[%d][%d]: %#lx\n", pc,
rd, sel, cop0->reg[rd][sel]);
break;
case dmtc_op:
printk
("!!!!!!![%#lx]dmtc_op: rt: %d, rd: %d, sel: %d!!!!!!\n",
vcpu->arch.pc, rt, rd, sel);
er = EMULATE_FAIL;
break;
case mfmcz_op:
#ifdef KVM_MIPS_DEBUG_COP0_COUNTERS
cop0->stat[MIPS_CP0_STATUS][0]++;
#endif
if (rt != 0) {
vcpu->arch.gprs[rt] =
kvm_read_c0_guest_status(cop0);
}
if (inst & 0x20) {
kvm_debug("[%#lx] mfmcz_op: EI\n",
vcpu->arch.pc);
kvm_set_c0_guest_status(cop0, ST0_IE);
} else {
kvm_debug("[%#lx] mfmcz_op: DI\n",
vcpu->arch.pc);
kvm_clear_c0_guest_status(cop0, ST0_IE);
}
break;
case wrpgpr_op:
{
uint32_t css =
cop0->reg[MIPS_CP0_STATUS][2] & 0xf;
uint32_t pss =
(cop0->reg[MIPS_CP0_STATUS][2] >> 6) & 0xf;
if (css || pss) {
er = EMULATE_FAIL;
break;
}
kvm_debug("WRPGPR[%d][%d] = %#lx\n", pss, rd,
vcpu->arch.gprs[rt]);
vcpu->arch.gprs[rd] = vcpu->arch.gprs[rt];
}
break;
default:
printk
("[%#lx]MachEmulateCP0: unsupported COP0, copz: 0x%x\n",
vcpu->arch.pc, copz);
er = EMULATE_FAIL;
break;
}
}
done:
if (er == EMULATE_FAIL) {
vcpu->arch.pc = curr_pc;
}
dont_update_pc:
return er;
}
enum emulation_result
kvm_mips_emulate_store(uint32_t inst, uint32_t cause,
struct kvm_run *run, struct kvm_vcpu *vcpu)
{
enum emulation_result er = EMULATE_DO_MMIO;
int32_t op, base, rt, offset;
uint32_t bytes;
void *data = run->mmio.data;
unsigned long curr_pc;
curr_pc = vcpu->arch.pc;
er = update_pc(vcpu, cause);
if (er == EMULATE_FAIL)
return er;
rt = (inst >> 16) & 0x1f;
base = (inst >> 21) & 0x1f;
offset = inst & 0xffff;
op = (inst >> 26) & 0x3f;
switch (op) {
case sb_op:
bytes = 1;
if (bytes > sizeof(run->mmio.data)) {
kvm_err("%s: bad MMIO length: %d\n", __func__,
run->mmio.len);
}
run->mmio.phys_addr =
kvm_mips_callbacks->gva_to_gpa(vcpu->arch.
host_cp0_badvaddr);
if (run->mmio.phys_addr == KVM_INVALID_ADDR) {
er = EMULATE_FAIL;
break;
}
run->mmio.len = bytes;
run->mmio.is_write = 1;
vcpu->mmio_needed = 1;
vcpu->mmio_is_write = 1;
*(u8 *) data = vcpu->arch.gprs[rt];
kvm_debug("OP_SB: eaddr: %#lx, gpr: %#lx, data: %#x\n",
vcpu->arch.host_cp0_badvaddr, vcpu->arch.gprs[rt],
*(uint8_t *) data);
break;
case sw_op:
bytes = 4;
if (bytes > sizeof(run->mmio.data)) {
kvm_err("%s: bad MMIO length: %d\n", __func__,
run->mmio.len);
}
run->mmio.phys_addr =
kvm_mips_callbacks->gva_to_gpa(vcpu->arch.
host_cp0_badvaddr);
if (run->mmio.phys_addr == KVM_INVALID_ADDR) {
er = EMULATE_FAIL;
break;
}
run->mmio.len = bytes;
run->mmio.is_write = 1;
vcpu->mmio_needed = 1;
vcpu->mmio_is_write = 1;
*(uint32_t *) data = vcpu->arch.gprs[rt];
kvm_debug("[%#lx] OP_SW: eaddr: %#lx, gpr: %#lx, data: %#x\n",
vcpu->arch.pc, vcpu->arch.host_cp0_badvaddr,
vcpu->arch.gprs[rt], *(uint32_t *) data);
break;
case sh_op:
bytes = 2;
if (bytes > sizeof(run->mmio.data)) {
kvm_err("%s: bad MMIO length: %d\n", __func__,
run->mmio.len);
}
run->mmio.phys_addr =
kvm_mips_callbacks->gva_to_gpa(vcpu->arch.
host_cp0_badvaddr);
if (run->mmio.phys_addr == KVM_INVALID_ADDR) {
er = EMULATE_FAIL;
break;
}
run->mmio.len = bytes;
run->mmio.is_write = 1;
vcpu->mmio_needed = 1;
vcpu->mmio_is_write = 1;
*(uint16_t *) data = vcpu->arch.gprs[rt];
kvm_debug("[%#lx] OP_SH: eaddr: %#lx, gpr: %#lx, data: %#x\n",
vcpu->arch.pc, vcpu->arch.host_cp0_badvaddr,
vcpu->arch.gprs[rt], *(uint32_t *) data);
break;
default:
printk("Store not yet supported");
er = EMULATE_FAIL;
break;
}
if (er == EMULATE_FAIL) {
vcpu->arch.pc = curr_pc;
}
return er;
}
enum emulation_result
kvm_mips_emulate_load(uint32_t inst, uint32_t cause,
struct kvm_run *run, struct kvm_vcpu *vcpu)
{
enum emulation_result er = EMULATE_DO_MMIO;
int32_t op, base, rt, offset;
uint32_t bytes;
rt = (inst >> 16) & 0x1f;
base = (inst >> 21) & 0x1f;
offset = inst & 0xffff;
op = (inst >> 26) & 0x3f;
vcpu->arch.pending_load_cause = cause;
vcpu->arch.io_gpr = rt;
switch (op) {
case lw_op:
bytes = 4;
if (bytes > sizeof(run->mmio.data)) {
kvm_err("%s: bad MMIO length: %d\n", __func__,
run->mmio.len);
er = EMULATE_FAIL;
break;
}
run->mmio.phys_addr =
kvm_mips_callbacks->gva_to_gpa(vcpu->arch.
host_cp0_badvaddr);
if (run->mmio.phys_addr == KVM_INVALID_ADDR) {
er = EMULATE_FAIL;
break;
}
run->mmio.len = bytes;
run->mmio.is_write = 0;
vcpu->mmio_needed = 1;
vcpu->mmio_is_write = 0;
break;
case lh_op:
case lhu_op:
bytes = 2;
if (bytes > sizeof(run->mmio.data)) {
kvm_err("%s: bad MMIO length: %d\n", __func__,
run->mmio.len);
er = EMULATE_FAIL;
break;
}
run->mmio.phys_addr =
kvm_mips_callbacks->gva_to_gpa(vcpu->arch.
host_cp0_badvaddr);
if (run->mmio.phys_addr == KVM_INVALID_ADDR) {
er = EMULATE_FAIL;
break;
}
run->mmio.len = bytes;
run->mmio.is_write = 0;
vcpu->mmio_needed = 1;
vcpu->mmio_is_write = 0;
if (op == lh_op)
vcpu->mmio_needed = 2;
else
vcpu->mmio_needed = 1;
break;
case lbu_op:
case lb_op:
bytes = 1;
if (bytes > sizeof(run->mmio.data)) {
kvm_err("%s: bad MMIO length: %d\n", __func__,
run->mmio.len);
er = EMULATE_FAIL;
break;
}
run->mmio.phys_addr =
kvm_mips_callbacks->gva_to_gpa(vcpu->arch.
host_cp0_badvaddr);
if (run->mmio.phys_addr == KVM_INVALID_ADDR) {
er = EMULATE_FAIL;
break;
}
run->mmio.len = bytes;
run->mmio.is_write = 0;
vcpu->mmio_is_write = 0;
if (op == lb_op)
vcpu->mmio_needed = 2;
else
vcpu->mmio_needed = 1;
break;
default:
printk("Load not yet supported");
er = EMULATE_FAIL;
break;
}
return er;
}
int kvm_mips_sync_icache(unsigned long va, struct kvm_vcpu *vcpu)
{
unsigned long offset = (va & ~PAGE_MASK);
struct kvm *kvm = vcpu->kvm;
unsigned long pa;
gfn_t gfn;
pfn_t pfn;
gfn = va >> PAGE_SHIFT;
if (gfn >= kvm->arch.guest_pmap_npages) {
printk("%s: Invalid gfn: %#llx\n", __func__, gfn);
kvm_mips_dump_host_tlbs();
kvm_arch_vcpu_dump_regs(vcpu);
return -1;
}
pfn = kvm->arch.guest_pmap[gfn];
pa = (pfn << PAGE_SHIFT) | offset;
printk("%s: va: %#lx, unmapped: %#x\n", __func__, va, CKSEG0ADDR(pa));
local_flush_icache_range(CKSEG0ADDR(pa), 32);
return 0;
}
enum emulation_result
kvm_mips_emulate_cache(uint32_t inst, uint32_t *opc, uint32_t cause,
struct kvm_run *run, struct kvm_vcpu *vcpu)
{
struct mips_coproc *cop0 = vcpu->arch.cop0;
extern void (*r4k_blast_dcache) (void);
extern void (*r4k_blast_icache) (void);
enum emulation_result er = EMULATE_DONE;
int32_t offset, cache, op_inst, op, base;
struct kvm_vcpu_arch *arch = &vcpu->arch;
unsigned long va;
unsigned long curr_pc;
curr_pc = vcpu->arch.pc;
er = update_pc(vcpu, cause);
if (er == EMULATE_FAIL)
return er;
base = (inst >> 21) & 0x1f;
op_inst = (inst >> 16) & 0x1f;
offset = inst & 0xffff;
cache = (inst >> 16) & 0x3;
op = (inst >> 18) & 0x7;
va = arch->gprs[base] + offset;
kvm_debug("CACHE (cache: %#x, op: %#x, base[%d]: %#lx, offset: %#x\n",
cache, op, base, arch->gprs[base], offset);
if (op == MIPS_CACHE_OP_INDEX_INV) {
kvm_debug
("@ %#lx/%#lx CACHE (cache: %#x, op: %#x, base[%d]: %#lx, offset: %#x\n",
vcpu->arch.pc, vcpu->arch.gprs[31], cache, op, base,
arch->gprs[base], offset);
if (cache == MIPS_CACHE_DCACHE)
r4k_blast_dcache();
else if (cache == MIPS_CACHE_ICACHE)
r4k_blast_icache();
else {
printk("%s: unsupported CACHE INDEX operation\n",
__func__);
return EMULATE_FAIL;
}
#ifdef CONFIG_KVM_MIPS_DYN_TRANS
kvm_mips_trans_cache_index(inst, opc, vcpu);
#endif
goto done;
}
preempt_disable();
if (KVM_GUEST_KSEGX(va) == KVM_GUEST_KSEG0) {
if (kvm_mips_host_tlb_lookup(vcpu, va) < 0) {
kvm_mips_handle_kseg0_tlb_fault(va, vcpu);
}
} else if ((KVM_GUEST_KSEGX(va) < KVM_GUEST_KSEG0) ||
KVM_GUEST_KSEGX(va) == KVM_GUEST_KSEG23) {
int index;
if (kvm_mips_host_tlb_lookup(vcpu, va) >= 0) {
goto skip_fault;
}
index = kvm_mips_guest_tlb_lookup(vcpu, (va & VPN2_MASK) |
(kvm_read_c0_guest_entryhi
(cop0) & ASID_MASK));
if (index < 0) {
vcpu->arch.host_cp0_entryhi = (va & VPN2_MASK);
vcpu->arch.host_cp0_badvaddr = va;
er = kvm_mips_emulate_tlbmiss_ld(cause, NULL, run,
vcpu);
preempt_enable();
goto dont_update_pc;
} else {
struct kvm_mips_tlb *tlb = &vcpu->arch.guest_tlb[index];
if (!TLB_IS_VALID(*tlb, va)) {
er = kvm_mips_emulate_tlbinv_ld(cause, NULL,
run, vcpu);
preempt_enable();
goto dont_update_pc;
} else {
kvm_mips_handle_mapped_seg_tlb_fault(vcpu, tlb,
NULL,
NULL);
}
}
} else {
printk
("INVALID CACHE INDEX/ADDRESS (cache: %#x, op: %#x, base[%d]: %#lx, offset: %#x\n",
cache, op, base, arch->gprs[base], offset);
er = EMULATE_FAIL;
preempt_enable();
goto dont_update_pc;
}
skip_fault:
if (cache == MIPS_CACHE_DCACHE
&& (op == MIPS_CACHE_OP_FILL_WB_INV
|| op == MIPS_CACHE_OP_HIT_INV)) {
flush_dcache_line(va);
#ifdef CONFIG_KVM_MIPS_DYN_TRANS
kvm_mips_trans_cache_va(inst, opc, vcpu);
#endif
} else if (op == MIPS_CACHE_OP_HIT_INV && cache == MIPS_CACHE_ICACHE) {
flush_dcache_line(va);
flush_icache_line(va);
#ifdef CONFIG_KVM_MIPS_DYN_TRANS
kvm_mips_trans_cache_va(inst, opc, vcpu);
#endif
} else {
printk
("NO-OP CACHE (cache: %#x, op: %#x, base[%d]: %#lx, offset: %#x\n",
cache, op, base, arch->gprs[base], offset);
er = EMULATE_FAIL;
preempt_enable();
goto dont_update_pc;
}
preempt_enable();
dont_update_pc:
vcpu->arch.pc = curr_pc;
done:
return er;
}
enum emulation_result
kvm_mips_emulate_inst(unsigned long cause, uint32_t *opc,
struct kvm_run *run, struct kvm_vcpu *vcpu)
{
enum emulation_result er = EMULATE_DONE;
uint32_t inst;
if (cause & CAUSEF_BD) {
opc += 1;
}
inst = kvm_get_inst(opc, vcpu);
switch (((union mips_instruction)inst).r_format.opcode) {
case cop0_op:
er = kvm_mips_emulate_CP0(inst, opc, cause, run, vcpu);
break;
case sb_op:
case sh_op:
case sw_op:
er = kvm_mips_emulate_store(inst, cause, run, vcpu);
break;
case lb_op:
case lbu_op:
case lhu_op:
case lh_op:
case lw_op:
er = kvm_mips_emulate_load(inst, cause, run, vcpu);
break;
case cache_op:
++vcpu->stat.cache_exits;
trace_kvm_exit(vcpu, CACHE_EXITS);
er = kvm_mips_emulate_cache(inst, opc, cause, run, vcpu);
break;
default:
printk("Instruction emulation not supported (%p/%#x)\n", opc,
inst);
kvm_arch_vcpu_dump_regs(vcpu);
er = EMULATE_FAIL;
break;
}
return er;
}
enum emulation_result
kvm_mips_emulate_syscall(unsigned long cause, uint32_t *opc,
struct kvm_run *run, struct kvm_vcpu *vcpu)
{
struct mips_coproc *cop0 = vcpu->arch.cop0;
struct kvm_vcpu_arch *arch = &vcpu->arch;
enum emulation_result er = EMULATE_DONE;
if ((kvm_read_c0_guest_status(cop0) & ST0_EXL) == 0) {
kvm_write_c0_guest_epc(cop0, arch->pc);
kvm_set_c0_guest_status(cop0, ST0_EXL);
if (cause & CAUSEF_BD)
kvm_set_c0_guest_cause(cop0, CAUSEF_BD);
else
kvm_clear_c0_guest_cause(cop0, CAUSEF_BD);
kvm_debug("Delivering SYSCALL @ pc %#lx\n", arch->pc);
kvm_change_c0_guest_cause(cop0, (0xff),
(T_SYSCALL << CAUSEB_EXCCODE));
arch->pc = KVM_GUEST_KSEG0 + 0x180;
} else {
printk("Trying to deliver SYSCALL when EXL is already set\n");
er = EMULATE_FAIL;
}
return er;
}
enum emulation_result
kvm_mips_emulate_tlbmiss_ld(unsigned long cause, uint32_t *opc,
struct kvm_run *run, struct kvm_vcpu *vcpu)
{
struct mips_coproc *cop0 = vcpu->arch.cop0;
struct kvm_vcpu_arch *arch = &vcpu->arch;
enum emulation_result er = EMULATE_DONE;
unsigned long entryhi = (vcpu->arch. host_cp0_badvaddr & VPN2_MASK) |
(kvm_read_c0_guest_entryhi(cop0) & ASID_MASK);
if ((kvm_read_c0_guest_status(cop0) & ST0_EXL) == 0) {
kvm_write_c0_guest_epc(cop0, arch->pc);
kvm_set_c0_guest_status(cop0, ST0_EXL);
if (cause & CAUSEF_BD)
kvm_set_c0_guest_cause(cop0, CAUSEF_BD);
else
kvm_clear_c0_guest_cause(cop0, CAUSEF_BD);
kvm_debug("[EXL == 0] delivering TLB MISS @ pc %#lx\n",
arch->pc);
arch->pc = KVM_GUEST_KSEG0 + 0x0;
} else {
kvm_debug("[EXL == 1] delivering TLB MISS @ pc %#lx\n",
arch->pc);
arch->pc = KVM_GUEST_KSEG0 + 0x180;
}
kvm_change_c0_guest_cause(cop0, (0xff),
(T_TLB_LD_MISS << CAUSEB_EXCCODE));
kvm_write_c0_guest_badvaddr(cop0, vcpu->arch.host_cp0_badvaddr);
kvm_write_c0_guest_entryhi(cop0, entryhi);
kvm_mips_flush_host_tlb(1);
return er;
}
enum emulation_result
kvm_mips_emulate_tlbinv_ld(unsigned long cause, uint32_t *opc,
struct kvm_run *run, struct kvm_vcpu *vcpu)
{
struct mips_coproc *cop0 = vcpu->arch.cop0;
struct kvm_vcpu_arch *arch = &vcpu->arch;
enum emulation_result er = EMULATE_DONE;
unsigned long entryhi =
(vcpu->arch.host_cp0_badvaddr & VPN2_MASK) |
(kvm_read_c0_guest_entryhi(cop0) & ASID_MASK);
if ((kvm_read_c0_guest_status(cop0) & ST0_EXL) == 0) {
kvm_write_c0_guest_epc(cop0, arch->pc);
kvm_set_c0_guest_status(cop0, ST0_EXL);
if (cause & CAUSEF_BD)
kvm_set_c0_guest_cause(cop0, CAUSEF_BD);
else
kvm_clear_c0_guest_cause(cop0, CAUSEF_BD);
kvm_debug("[EXL == 0] delivering TLB INV @ pc %#lx\n",
arch->pc);
arch->pc = KVM_GUEST_KSEG0 + 0x180;
} else {
kvm_debug("[EXL == 1] delivering TLB MISS @ pc %#lx\n",
arch->pc);
arch->pc = KVM_GUEST_KSEG0 + 0x180;
}
kvm_change_c0_guest_cause(cop0, (0xff),
(T_TLB_LD_MISS << CAUSEB_EXCCODE));
kvm_write_c0_guest_badvaddr(cop0, vcpu->arch.host_cp0_badvaddr);
kvm_write_c0_guest_entryhi(cop0, entryhi);
kvm_mips_flush_host_tlb(1);
return er;
}
enum emulation_result
kvm_mips_emulate_tlbmiss_st(unsigned long cause, uint32_t *opc,
struct kvm_run *run, struct kvm_vcpu *vcpu)
{
struct mips_coproc *cop0 = vcpu->arch.cop0;
struct kvm_vcpu_arch *arch = &vcpu->arch;
enum emulation_result er = EMULATE_DONE;
unsigned long entryhi = (vcpu->arch.host_cp0_badvaddr & VPN2_MASK) |
(kvm_read_c0_guest_entryhi(cop0) & ASID_MASK);
if ((kvm_read_c0_guest_status(cop0) & ST0_EXL) == 0) {
kvm_write_c0_guest_epc(cop0, arch->pc);
kvm_set_c0_guest_status(cop0, ST0_EXL);
if (cause & CAUSEF_BD)
kvm_set_c0_guest_cause(cop0, CAUSEF_BD);
else
kvm_clear_c0_guest_cause(cop0, CAUSEF_BD);
kvm_debug("[EXL == 0] Delivering TLB MISS @ pc %#lx\n",
arch->pc);
arch->pc = KVM_GUEST_KSEG0 + 0x0;
} else {
kvm_debug("[EXL == 1] Delivering TLB MISS @ pc %#lx\n",
arch->pc);
arch->pc = KVM_GUEST_KSEG0 + 0x180;
}
kvm_change_c0_guest_cause(cop0, (0xff),
(T_TLB_ST_MISS << CAUSEB_EXCCODE));
kvm_write_c0_guest_badvaddr(cop0, vcpu->arch.host_cp0_badvaddr);
kvm_write_c0_guest_entryhi(cop0, entryhi);
kvm_mips_flush_host_tlb(1);
return er;
}
enum emulation_result
kvm_mips_emulate_tlbinv_st(unsigned long cause, uint32_t *opc,
struct kvm_run *run, struct kvm_vcpu *vcpu)
{
struct mips_coproc *cop0 = vcpu->arch.cop0;
struct kvm_vcpu_arch *arch = &vcpu->arch;
enum emulation_result er = EMULATE_DONE;
unsigned long entryhi = (vcpu->arch.host_cp0_badvaddr & VPN2_MASK) |
(kvm_read_c0_guest_entryhi(cop0) & ASID_MASK);
if ((kvm_read_c0_guest_status(cop0) & ST0_EXL) == 0) {
kvm_write_c0_guest_epc(cop0, arch->pc);
kvm_set_c0_guest_status(cop0, ST0_EXL);
if (cause & CAUSEF_BD)
kvm_set_c0_guest_cause(cop0, CAUSEF_BD);
else
kvm_clear_c0_guest_cause(cop0, CAUSEF_BD);
kvm_debug("[EXL == 0] Delivering TLB MISS @ pc %#lx\n",
arch->pc);
arch->pc = KVM_GUEST_KSEG0 + 0x180;
} else {
kvm_debug("[EXL == 1] Delivering TLB MISS @ pc %#lx\n",
arch->pc);
arch->pc = KVM_GUEST_KSEG0 + 0x180;
}
kvm_change_c0_guest_cause(cop0, (0xff),
(T_TLB_ST_MISS << CAUSEB_EXCCODE));
kvm_write_c0_guest_badvaddr(cop0, vcpu->arch.host_cp0_badvaddr);
kvm_write_c0_guest_entryhi(cop0, entryhi);
kvm_mips_flush_host_tlb(1);
return er;
}
enum emulation_result
kvm_mips_handle_tlbmod(unsigned long cause, uint32_t *opc,
struct kvm_run *run, struct kvm_vcpu *vcpu)
{
enum emulation_result er = EMULATE_DONE;
#ifdef DEBUG
struct mips_coproc *cop0 = vcpu->arch.cop0;
unsigned long entryhi = (vcpu->arch.host_cp0_badvaddr & VPN2_MASK) |
(kvm_read_c0_guest_entryhi(cop0) & ASID_MASK);
int index;
index = kvm_mips_guest_tlb_lookup(vcpu, entryhi);
if (index < 0) {
kvm_mips_host_tlb_inv(vcpu, vcpu->arch.host_cp0_badvaddr);
kvm_err("%s: host got TLBMOD for %#lx but entry not present in Guest TLB\n",
__func__, entryhi);
kvm_mips_dump_guest_tlbs(vcpu);
kvm_mips_dump_host_tlbs();
return EMULATE_FAIL;
}
#endif
er = kvm_mips_emulate_tlbmod(cause, opc, run, vcpu);
return er;
}
enum emulation_result
kvm_mips_emulate_tlbmod(unsigned long cause, uint32_t *opc,
struct kvm_run *run, struct kvm_vcpu *vcpu)
{
struct mips_coproc *cop0 = vcpu->arch.cop0;
unsigned long entryhi = (vcpu->arch.host_cp0_badvaddr & VPN2_MASK) |
(kvm_read_c0_guest_entryhi(cop0) & ASID_MASK);
struct kvm_vcpu_arch *arch = &vcpu->arch;
enum emulation_result er = EMULATE_DONE;
if ((kvm_read_c0_guest_status(cop0) & ST0_EXL) == 0) {
kvm_write_c0_guest_epc(cop0, arch->pc);
kvm_set_c0_guest_status(cop0, ST0_EXL);
if (cause & CAUSEF_BD)
kvm_set_c0_guest_cause(cop0, CAUSEF_BD);
else
kvm_clear_c0_guest_cause(cop0, CAUSEF_BD);
kvm_debug("[EXL == 0] Delivering TLB MOD @ pc %#lx\n",
arch->pc);
arch->pc = KVM_GUEST_KSEG0 + 0x180;
} else {
kvm_debug("[EXL == 1] Delivering TLB MOD @ pc %#lx\n",
arch->pc);
arch->pc = KVM_GUEST_KSEG0 + 0x180;
}
kvm_change_c0_guest_cause(cop0, (0xff), (T_TLB_MOD << CAUSEB_EXCCODE));
kvm_write_c0_guest_badvaddr(cop0, vcpu->arch.host_cp0_badvaddr);
kvm_write_c0_guest_entryhi(cop0, entryhi);
kvm_mips_flush_host_tlb(1);
return er;
}
enum emulation_result
kvm_mips_emulate_fpu_exc(unsigned long cause, uint32_t *opc,
struct kvm_run *run, struct kvm_vcpu *vcpu)
{
struct mips_coproc *cop0 = vcpu->arch.cop0;
struct kvm_vcpu_arch *arch = &vcpu->arch;
enum emulation_result er = EMULATE_DONE;
if ((kvm_read_c0_guest_status(cop0) & ST0_EXL) == 0) {
kvm_write_c0_guest_epc(cop0, arch->pc);
kvm_set_c0_guest_status(cop0, ST0_EXL);
if (cause & CAUSEF_BD)
kvm_set_c0_guest_cause(cop0, CAUSEF_BD);
else
kvm_clear_c0_guest_cause(cop0, CAUSEF_BD);
}
arch->pc = KVM_GUEST_KSEG0 + 0x180;
kvm_change_c0_guest_cause(cop0, (0xff),
(T_COP_UNUSABLE << CAUSEB_EXCCODE));
kvm_change_c0_guest_cause(cop0, (CAUSEF_CE), (0x1 << CAUSEB_CE));
return er;
}
enum emulation_result
kvm_mips_emulate_ri_exc(unsigned long cause, uint32_t *opc,
struct kvm_run *run, struct kvm_vcpu *vcpu)
{
struct mips_coproc *cop0 = vcpu->arch.cop0;
struct kvm_vcpu_arch *arch = &vcpu->arch;
enum emulation_result er = EMULATE_DONE;
if ((kvm_read_c0_guest_status(cop0) & ST0_EXL) == 0) {
kvm_write_c0_guest_epc(cop0, arch->pc);
kvm_set_c0_guest_status(cop0, ST0_EXL);
if (cause & CAUSEF_BD)
kvm_set_c0_guest_cause(cop0, CAUSEF_BD);
else
kvm_clear_c0_guest_cause(cop0, CAUSEF_BD);
kvm_debug("Delivering RI @ pc %#lx\n", arch->pc);
kvm_change_c0_guest_cause(cop0, (0xff),
(T_RES_INST << CAUSEB_EXCCODE));
arch->pc = KVM_GUEST_KSEG0 + 0x180;
} else {
kvm_err("Trying to deliver RI when EXL is already set\n");
er = EMULATE_FAIL;
}
return er;
}
enum emulation_result
kvm_mips_emulate_bp_exc(unsigned long cause, uint32_t *opc,
struct kvm_run *run, struct kvm_vcpu *vcpu)
{
struct mips_coproc *cop0 = vcpu->arch.cop0;
struct kvm_vcpu_arch *arch = &vcpu->arch;
enum emulation_result er = EMULATE_DONE;
if ((kvm_read_c0_guest_status(cop0) & ST0_EXL) == 0) {
kvm_write_c0_guest_epc(cop0, arch->pc);
kvm_set_c0_guest_status(cop0, ST0_EXL);
if (cause & CAUSEF_BD)
kvm_set_c0_guest_cause(cop0, CAUSEF_BD);
else
kvm_clear_c0_guest_cause(cop0, CAUSEF_BD);
kvm_debug("Delivering BP @ pc %#lx\n", arch->pc);
kvm_change_c0_guest_cause(cop0, (0xff),
(T_BREAK << CAUSEB_EXCCODE));
arch->pc = KVM_GUEST_KSEG0 + 0x180;
} else {
printk("Trying to deliver BP when EXL is already set\n");
er = EMULATE_FAIL;
}
return er;
}
enum emulation_result
kvm_mips_handle_ri(unsigned long cause, uint32_t *opc,
struct kvm_run *run, struct kvm_vcpu *vcpu)
{
struct mips_coproc *cop0 = vcpu->arch.cop0;
struct kvm_vcpu_arch *arch = &vcpu->arch;
enum emulation_result er = EMULATE_DONE;
unsigned long curr_pc;
uint32_t inst;
curr_pc = vcpu->arch.pc;
er = update_pc(vcpu, cause);
if (er == EMULATE_FAIL)
return er;
if (cause & CAUSEF_BD)
opc += 1;
inst = kvm_get_inst(opc, vcpu);
if (inst == KVM_INVALID_INST) {
printk("%s: Cannot get inst @ %p\n", __func__, opc);
return EMULATE_FAIL;
}
if ((inst & OPCODE) == SPEC3 && (inst & FUNC) == RDHWR) {
int usermode = !KVM_GUEST_KERNEL_MODE(vcpu);
int rd = (inst & RD) >> 11;
int rt = (inst & RT) >> 16;
if (usermode && !(kvm_read_c0_guest_hwrena(cop0) & BIT(rd))) {
kvm_debug("RDHWR %#x disallowed by HWREna @ %p\n",
rd, opc);
goto emulate_ri;
}
switch (rd) {
case 0:
arch->gprs[rt] = 0;
break;
case 1:
arch->gprs[rt] = min(current_cpu_data.dcache.linesz,
current_cpu_data.icache.linesz);
break;
case 2:
arch->gprs[rt] = kvm_mips_read_count(vcpu);
break;
case 3:
switch (current_cpu_data.cputype) {
case CPU_20KC:
case CPU_25KF:
arch->gprs[rt] = 1;
break;
default:
arch->gprs[rt] = 2;
}
break;
case 29:
arch->gprs[rt] = kvm_read_c0_guest_userlocal(cop0);
break;
default:
kvm_debug("RDHWR %#x not supported @ %p\n", rd, opc);
goto emulate_ri;
}
} else {
kvm_debug("Emulate RI not supported @ %p: %#x\n", opc, inst);
goto emulate_ri;
}
return EMULATE_DONE;
emulate_ri:
vcpu->arch.pc = curr_pc;
return kvm_mips_emulate_ri_exc(cause, opc, run, vcpu);
}
enum emulation_result
kvm_mips_complete_mmio_load(struct kvm_vcpu *vcpu, struct kvm_run *run)
{
unsigned long *gpr = &vcpu->arch.gprs[vcpu->arch.io_gpr];
enum emulation_result er = EMULATE_DONE;
unsigned long curr_pc;
if (run->mmio.len > sizeof(*gpr)) {
printk("Bad MMIO length: %d", run->mmio.len);
er = EMULATE_FAIL;
goto done;
}
curr_pc = vcpu->arch.pc;
er = update_pc(vcpu, vcpu->arch.pending_load_cause);
if (er == EMULATE_FAIL)
return er;
switch (run->mmio.len) {
case 4:
*gpr = *(int32_t *) run->mmio.data;
break;
case 2:
if (vcpu->mmio_needed == 2)
*gpr = *(int16_t *) run->mmio.data;
else
*gpr = *(int16_t *) run->mmio.data;
break;
case 1:
if (vcpu->mmio_needed == 2)
*gpr = *(int8_t *) run->mmio.data;
else
*gpr = *(u8 *) run->mmio.data;
break;
}
if (vcpu->arch.pending_load_cause & CAUSEF_BD)
kvm_debug
("[%#lx] Completing %d byte BD Load to gpr %d (0x%08lx) type %d\n",
vcpu->arch.pc, run->mmio.len, vcpu->arch.io_gpr, *gpr,
vcpu->mmio_needed);
done:
return er;
}
static enum emulation_result
kvm_mips_emulate_exc(unsigned long cause, uint32_t *opc,
struct kvm_run *run, struct kvm_vcpu *vcpu)
{
uint32_t exccode = (cause >> CAUSEB_EXCCODE) & 0x1f;
struct mips_coproc *cop0 = vcpu->arch.cop0;
struct kvm_vcpu_arch *arch = &vcpu->arch;
enum emulation_result er = EMULATE_DONE;
if ((kvm_read_c0_guest_status(cop0) & ST0_EXL) == 0) {
kvm_write_c0_guest_epc(cop0, arch->pc);
kvm_set_c0_guest_status(cop0, ST0_EXL);
if (cause & CAUSEF_BD)
kvm_set_c0_guest_cause(cop0, CAUSEF_BD);
else
kvm_clear_c0_guest_cause(cop0, CAUSEF_BD);
kvm_change_c0_guest_cause(cop0, (0xff),
(exccode << CAUSEB_EXCCODE));
arch->pc = KVM_GUEST_KSEG0 + 0x180;
kvm_write_c0_guest_badvaddr(cop0, vcpu->arch.host_cp0_badvaddr);
kvm_debug("Delivering EXC %d @ pc %#lx, badVaddr: %#lx\n",
exccode, kvm_read_c0_guest_epc(cop0),
kvm_read_c0_guest_badvaddr(cop0));
} else {
printk("Trying to deliver EXC when EXL is already set\n");
er = EMULATE_FAIL;
}
return er;
}
enum emulation_result
kvm_mips_check_privilege(unsigned long cause, uint32_t *opc,
struct kvm_run *run, struct kvm_vcpu *vcpu)
{
enum emulation_result er = EMULATE_DONE;
uint32_t exccode = (cause >> CAUSEB_EXCCODE) & 0x1f;
unsigned long badvaddr = vcpu->arch.host_cp0_badvaddr;
int usermode = !KVM_GUEST_KERNEL_MODE(vcpu);
if (usermode) {
switch (exccode) {
case T_INT:
case T_SYSCALL:
case T_BREAK:
case T_RES_INST:
break;
case T_COP_UNUSABLE:
if (((cause & CAUSEF_CE) >> CAUSEB_CE) == 0)
er = EMULATE_PRIV_FAIL;
break;
case T_TLB_MOD:
break;
case T_TLB_LD_MISS:
if (badvaddr >= (unsigned long) KVM_GUEST_KSEG0) {
printk("%s: LD MISS @ %#lx\n", __func__,
badvaddr);
cause &= ~0xff;
cause |= (T_ADDR_ERR_LD << CAUSEB_EXCCODE);
er = EMULATE_PRIV_FAIL;
}
break;
case T_TLB_ST_MISS:
if (badvaddr >= (unsigned long) KVM_GUEST_KSEG0) {
printk("%s: ST MISS @ %#lx\n", __func__,
badvaddr);
cause &= ~0xff;
cause |= (T_ADDR_ERR_ST << CAUSEB_EXCCODE);
er = EMULATE_PRIV_FAIL;
}
break;
case T_ADDR_ERR_ST:
printk("%s: address error ST @ %#lx\n", __func__,
badvaddr);
if ((badvaddr & PAGE_MASK) == KVM_GUEST_COMMPAGE_ADDR) {
cause &= ~0xff;
cause |= (T_TLB_ST_MISS << CAUSEB_EXCCODE);
}
er = EMULATE_PRIV_FAIL;
break;
case T_ADDR_ERR_LD:
printk("%s: address error LD @ %#lx\n", __func__,
badvaddr);
if ((badvaddr & PAGE_MASK) == KVM_GUEST_COMMPAGE_ADDR) {
cause &= ~0xff;
cause |= (T_TLB_LD_MISS << CAUSEB_EXCCODE);
}
er = EMULATE_PRIV_FAIL;
break;
default:
er = EMULATE_PRIV_FAIL;
break;
}
}
if (er == EMULATE_PRIV_FAIL) {
kvm_mips_emulate_exc(cause, opc, run, vcpu);
}
return er;
}
enum emulation_result
kvm_mips_handle_tlbmiss(unsigned long cause, uint32_t *opc,
struct kvm_run *run, struct kvm_vcpu *vcpu)
{
enum emulation_result er = EMULATE_DONE;
uint32_t exccode = (cause >> CAUSEB_EXCCODE) & 0x1f;
unsigned long va = vcpu->arch.host_cp0_badvaddr;
int index;
kvm_debug("kvm_mips_handle_tlbmiss: badvaddr: %#lx, entryhi: %#lx\n",
vcpu->arch.host_cp0_badvaddr, vcpu->arch.host_cp0_entryhi);
index = kvm_mips_guest_tlb_lookup(vcpu,
(va & VPN2_MASK) |
(kvm_read_c0_guest_entryhi
(vcpu->arch.cop0) & ASID_MASK));
if (index < 0) {
if (exccode == T_TLB_LD_MISS) {
er = kvm_mips_emulate_tlbmiss_ld(cause, opc, run, vcpu);
} else if (exccode == T_TLB_ST_MISS) {
er = kvm_mips_emulate_tlbmiss_st(cause, opc, run, vcpu);
} else {
printk("%s: invalid exc code: %d\n", __func__, exccode);
er = EMULATE_FAIL;
}
} else {
struct kvm_mips_tlb *tlb = &vcpu->arch.guest_tlb[index];
if (!TLB_IS_VALID(*tlb, va)) {
if (exccode == T_TLB_LD_MISS) {
er = kvm_mips_emulate_tlbinv_ld(cause, opc, run,
vcpu);
} else if (exccode == T_TLB_ST_MISS) {
er = kvm_mips_emulate_tlbinv_st(cause, opc, run,
vcpu);
} else {
printk("%s: invalid exc code: %d\n", __func__,
exccode);
er = EMULATE_FAIL;
}
} else {
kvm_debug
("Injecting hi: %#lx, lo0: %#lx, lo1: %#lx into shadow host TLB\n",
tlb->tlb_hi, tlb->tlb_lo0, tlb->tlb_lo1);
kvm_mips_handle_mapped_seg_tlb_fault(vcpu, tlb, NULL,
NULL);
}
}
return er;
}
