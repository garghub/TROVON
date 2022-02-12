static gpa_t kvm_trap_emul_gva_to_gpa_cb(gva_t gva)
{
gpa_t gpa;
gva_t kseg = KSEGX(gva);
if ((kseg == CKSEG0) || (kseg == CKSEG1))
gpa = CPHYSADDR(gva);
else {
kvm_err("%s: cannot find GPA for GVA: %#lx\n", __func__, gva);
kvm_mips_dump_host_tlbs();
gpa = KVM_INVALID_ADDR;
}
kvm_debug("%s: gva %#lx, gpa: %#llx\n", __func__, gva, gpa);
return gpa;
}
static int kvm_trap_emul_handle_cop_unusable(struct kvm_vcpu *vcpu)
{
struct mips_coproc *cop0 = vcpu->arch.cop0;
struct kvm_run *run = vcpu->run;
u32 __user *opc = (u32 __user *) vcpu->arch.pc;
u32 cause = vcpu->arch.host_cp0_cause;
enum emulation_result er = EMULATE_DONE;
int ret = RESUME_GUEST;
if (((cause & CAUSEF_CE) >> CAUSEB_CE) == 1) {
if (!kvm_mips_guest_has_fpu(&vcpu->arch) ||
(kvm_read_c0_guest_status(cop0) & ST0_CU1) == 0) {
er = kvm_mips_emulate_fpu_exc(cause, opc, run, vcpu);
} else {
kvm_own_fpu(vcpu);
er = EMULATE_DONE;
}
} else {
er = kvm_mips_emulate_inst(cause, opc, run, vcpu);
}
switch (er) {
case EMULATE_DONE:
ret = RESUME_GUEST;
break;
case EMULATE_FAIL:
run->exit_reason = KVM_EXIT_INTERNAL_ERROR;
ret = RESUME_HOST;
break;
case EMULATE_WAIT:
run->exit_reason = KVM_EXIT_INTR;
ret = RESUME_HOST;
break;
default:
BUG();
}
return ret;
}
static int kvm_trap_emul_handle_tlb_mod(struct kvm_vcpu *vcpu)
{
struct kvm_run *run = vcpu->run;
u32 __user *opc = (u32 __user *) vcpu->arch.pc;
unsigned long badvaddr = vcpu->arch.host_cp0_badvaddr;
u32 cause = vcpu->arch.host_cp0_cause;
enum emulation_result er = EMULATE_DONE;
int ret = RESUME_GUEST;
if (KVM_GUEST_KSEGX(badvaddr) < KVM_GUEST_KSEG0
|| KVM_GUEST_KSEGX(badvaddr) == KVM_GUEST_KSEG23) {
kvm_debug("USER/KSEG23 ADDR TLB MOD fault: cause %#x, PC: %p, BadVaddr: %#lx\n",
cause, opc, badvaddr);
er = kvm_mips_handle_tlbmod(cause, opc, run, vcpu);
if (er == EMULATE_DONE)
ret = RESUME_GUEST;
else {
run->exit_reason = KVM_EXIT_INTERNAL_ERROR;
ret = RESUME_HOST;
}
} else if (KVM_GUEST_KSEGX(badvaddr) == KVM_GUEST_KSEG0) {
kvm_err("TLB MOD fault not handled, cause %#x, PC: %p, BadVaddr: %#lx\n",
cause, opc, badvaddr);
kvm_mips_dump_host_tlbs();
kvm_arch_vcpu_dump_regs(vcpu);
run->exit_reason = KVM_EXIT_INTERNAL_ERROR;
ret = RESUME_HOST;
} else {
kvm_err("Illegal TLB Mod fault address , cause %#x, PC: %p, BadVaddr: %#lx\n",
cause, opc, badvaddr);
kvm_mips_dump_host_tlbs();
kvm_arch_vcpu_dump_regs(vcpu);
run->exit_reason = KVM_EXIT_INTERNAL_ERROR;
ret = RESUME_HOST;
}
return ret;
}
static int kvm_trap_emul_handle_tlb_miss(struct kvm_vcpu *vcpu, bool store)
{
struct kvm_run *run = vcpu->run;
u32 __user *opc = (u32 __user *) vcpu->arch.pc;
unsigned long badvaddr = vcpu->arch.host_cp0_badvaddr;
u32 cause = vcpu->arch.host_cp0_cause;
enum emulation_result er = EMULATE_DONE;
int ret = RESUME_GUEST;
if (((badvaddr & PAGE_MASK) == KVM_GUEST_COMMPAGE_ADDR)
&& KVM_GUEST_KERNEL_MODE(vcpu)) {
if (kvm_mips_handle_commpage_tlb_fault(badvaddr, vcpu) < 0) {
run->exit_reason = KVM_EXIT_INTERNAL_ERROR;
ret = RESUME_HOST;
}
} else if (KVM_GUEST_KSEGX(badvaddr) < KVM_GUEST_KSEG0
|| KVM_GUEST_KSEGX(badvaddr) == KVM_GUEST_KSEG23) {
kvm_debug("USER ADDR TLB %s fault: cause %#x, PC: %p, BadVaddr: %#lx\n",
store ? "ST" : "LD", cause, opc, badvaddr);
er = kvm_mips_handle_tlbmiss(cause, opc, run, vcpu);
if (er == EMULATE_DONE)
ret = RESUME_GUEST;
else {
run->exit_reason = KVM_EXIT_INTERNAL_ERROR;
ret = RESUME_HOST;
}
} else if (KVM_GUEST_KSEGX(badvaddr) == KVM_GUEST_KSEG0) {
if (kvm_mips_handle_kseg0_tlb_fault
(vcpu->arch.host_cp0_badvaddr, vcpu) < 0) {
run->exit_reason = KVM_EXIT_INTERNAL_ERROR;
ret = RESUME_HOST;
}
} else if (KVM_GUEST_KERNEL_MODE(vcpu)
&& (KSEGX(badvaddr) == CKSEG0 || KSEGX(badvaddr) == CKSEG1)) {
kvm_debug("Emulate %s MMIO space\n",
store ? "Store to" : "Load from");
er = kvm_mips_emulate_inst(cause, opc, run, vcpu);
if (er == EMULATE_FAIL) {
kvm_err("Emulate %s MMIO space failed\n",
store ? "Store to" : "Load from");
run->exit_reason = KVM_EXIT_INTERNAL_ERROR;
ret = RESUME_HOST;
} else {
run->exit_reason = KVM_EXIT_MMIO;
ret = RESUME_HOST;
}
} else {
kvm_err("Illegal TLB %s fault address , cause %#x, PC: %p, BadVaddr: %#lx\n",
store ? "ST" : "LD", cause, opc, badvaddr);
kvm_mips_dump_host_tlbs();
kvm_arch_vcpu_dump_regs(vcpu);
run->exit_reason = KVM_EXIT_INTERNAL_ERROR;
ret = RESUME_HOST;
}
return ret;
}
static int kvm_trap_emul_handle_tlb_st_miss(struct kvm_vcpu *vcpu)
{
return kvm_trap_emul_handle_tlb_miss(vcpu, true);
}
static int kvm_trap_emul_handle_tlb_ld_miss(struct kvm_vcpu *vcpu)
{
return kvm_trap_emul_handle_tlb_miss(vcpu, false);
}
static int kvm_trap_emul_handle_addr_err_st(struct kvm_vcpu *vcpu)
{
struct kvm_run *run = vcpu->run;
u32 __user *opc = (u32 __user *) vcpu->arch.pc;
unsigned long badvaddr = vcpu->arch.host_cp0_badvaddr;
u32 cause = vcpu->arch.host_cp0_cause;
enum emulation_result er = EMULATE_DONE;
int ret = RESUME_GUEST;
if (KVM_GUEST_KERNEL_MODE(vcpu)
&& (KSEGX(badvaddr) == CKSEG0 || KSEGX(badvaddr) == CKSEG1)) {
kvm_debug("Emulate Store to MMIO space\n");
er = kvm_mips_emulate_inst(cause, opc, run, vcpu);
if (er == EMULATE_FAIL) {
kvm_err("Emulate Store to MMIO space failed\n");
run->exit_reason = KVM_EXIT_INTERNAL_ERROR;
ret = RESUME_HOST;
} else {
run->exit_reason = KVM_EXIT_MMIO;
ret = RESUME_HOST;
}
} else {
kvm_err("Address Error (STORE): cause %#x, PC: %p, BadVaddr: %#lx\n",
cause, opc, badvaddr);
run->exit_reason = KVM_EXIT_INTERNAL_ERROR;
ret = RESUME_HOST;
}
return ret;
}
static int kvm_trap_emul_handle_addr_err_ld(struct kvm_vcpu *vcpu)
{
struct kvm_run *run = vcpu->run;
u32 __user *opc = (u32 __user *) vcpu->arch.pc;
unsigned long badvaddr = vcpu->arch.host_cp0_badvaddr;
u32 cause = vcpu->arch.host_cp0_cause;
enum emulation_result er = EMULATE_DONE;
int ret = RESUME_GUEST;
if (KSEGX(badvaddr) == CKSEG0 || KSEGX(badvaddr) == CKSEG1) {
kvm_debug("Emulate Load from MMIO space @ %#lx\n", badvaddr);
er = kvm_mips_emulate_inst(cause, opc, run, vcpu);
if (er == EMULATE_FAIL) {
kvm_err("Emulate Load from MMIO space failed\n");
run->exit_reason = KVM_EXIT_INTERNAL_ERROR;
ret = RESUME_HOST;
} else {
run->exit_reason = KVM_EXIT_MMIO;
ret = RESUME_HOST;
}
} else {
kvm_err("Address Error (LOAD): cause %#x, PC: %p, BadVaddr: %#lx\n",
cause, opc, badvaddr);
run->exit_reason = KVM_EXIT_INTERNAL_ERROR;
ret = RESUME_HOST;
er = EMULATE_FAIL;
}
return ret;
}
static int kvm_trap_emul_handle_syscall(struct kvm_vcpu *vcpu)
{
struct kvm_run *run = vcpu->run;
u32 __user *opc = (u32 __user *) vcpu->arch.pc;
u32 cause = vcpu->arch.host_cp0_cause;
enum emulation_result er = EMULATE_DONE;
int ret = RESUME_GUEST;
er = kvm_mips_emulate_syscall(cause, opc, run, vcpu);
if (er == EMULATE_DONE)
ret = RESUME_GUEST;
else {
run->exit_reason = KVM_EXIT_INTERNAL_ERROR;
ret = RESUME_HOST;
}
return ret;
}
static int kvm_trap_emul_handle_res_inst(struct kvm_vcpu *vcpu)
{
struct kvm_run *run = vcpu->run;
u32 __user *opc = (u32 __user *) vcpu->arch.pc;
u32 cause = vcpu->arch.host_cp0_cause;
enum emulation_result er = EMULATE_DONE;
int ret = RESUME_GUEST;
er = kvm_mips_handle_ri(cause, opc, run, vcpu);
if (er == EMULATE_DONE)
ret = RESUME_GUEST;
else {
run->exit_reason = KVM_EXIT_INTERNAL_ERROR;
ret = RESUME_HOST;
}
return ret;
}
static int kvm_trap_emul_handle_break(struct kvm_vcpu *vcpu)
{
struct kvm_run *run = vcpu->run;
u32 __user *opc = (u32 __user *) vcpu->arch.pc;
u32 cause = vcpu->arch.host_cp0_cause;
enum emulation_result er = EMULATE_DONE;
int ret = RESUME_GUEST;
er = kvm_mips_emulate_bp_exc(cause, opc, run, vcpu);
if (er == EMULATE_DONE)
ret = RESUME_GUEST;
else {
run->exit_reason = KVM_EXIT_INTERNAL_ERROR;
ret = RESUME_HOST;
}
return ret;
}
static int kvm_trap_emul_handle_trap(struct kvm_vcpu *vcpu)
{
struct kvm_run *run = vcpu->run;
u32 __user *opc = (u32 __user *)vcpu->arch.pc;
u32 cause = vcpu->arch.host_cp0_cause;
enum emulation_result er = EMULATE_DONE;
int ret = RESUME_GUEST;
er = kvm_mips_emulate_trap_exc(cause, opc, run, vcpu);
if (er == EMULATE_DONE) {
ret = RESUME_GUEST;
} else {
run->exit_reason = KVM_EXIT_INTERNAL_ERROR;
ret = RESUME_HOST;
}
return ret;
}
static int kvm_trap_emul_handle_msa_fpe(struct kvm_vcpu *vcpu)
{
struct kvm_run *run = vcpu->run;
u32 __user *opc = (u32 __user *)vcpu->arch.pc;
u32 cause = vcpu->arch.host_cp0_cause;
enum emulation_result er = EMULATE_DONE;
int ret = RESUME_GUEST;
er = kvm_mips_emulate_msafpe_exc(cause, opc, run, vcpu);
if (er == EMULATE_DONE) {
ret = RESUME_GUEST;
} else {
run->exit_reason = KVM_EXIT_INTERNAL_ERROR;
ret = RESUME_HOST;
}
return ret;
}
static int kvm_trap_emul_handle_fpe(struct kvm_vcpu *vcpu)
{
struct kvm_run *run = vcpu->run;
u32 __user *opc = (u32 __user *)vcpu->arch.pc;
u32 cause = vcpu->arch.host_cp0_cause;
enum emulation_result er = EMULATE_DONE;
int ret = RESUME_GUEST;
er = kvm_mips_emulate_fpe_exc(cause, opc, run, vcpu);
if (er == EMULATE_DONE) {
ret = RESUME_GUEST;
} else {
run->exit_reason = KVM_EXIT_INTERNAL_ERROR;
ret = RESUME_HOST;
}
return ret;
}
static int kvm_trap_emul_handle_msa_disabled(struct kvm_vcpu *vcpu)
{
struct mips_coproc *cop0 = vcpu->arch.cop0;
struct kvm_run *run = vcpu->run;
u32 __user *opc = (u32 __user *) vcpu->arch.pc;
u32 cause = vcpu->arch.host_cp0_cause;
enum emulation_result er = EMULATE_DONE;
int ret = RESUME_GUEST;
if (!kvm_mips_guest_has_msa(&vcpu->arch) ||
(kvm_read_c0_guest_status(cop0) & (ST0_CU1 | ST0_FR)) == ST0_CU1) {
er = kvm_mips_emulate_ri_exc(cause, opc, run, vcpu);
} else if (!(kvm_read_c0_guest_config5(cop0) & MIPS_CONF5_MSAEN)) {
er = kvm_mips_emulate_msadis_exc(cause, opc, run, vcpu);
} else {
kvm_own_msa(vcpu);
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
static int kvm_trap_emul_vm_init(struct kvm *kvm)
{
return 0;
}
static int kvm_trap_emul_vcpu_init(struct kvm_vcpu *vcpu)
{
vcpu->arch.kscratch_enabled = 0xfc;
return 0;
}
static int kvm_trap_emul_vcpu_setup(struct kvm_vcpu *vcpu)
{
struct mips_coproc *cop0 = vcpu->arch.cop0;
u32 config, config1;
int vcpu_id = vcpu->vcpu_id;
#ifndef CONFIG_CPU_MIPSR6
kvm_write_c0_guest_prid(cop0, 0x00019300);
#else
kvm_write_c0_guest_prid(cop0, 0x00010000);
#endif
config = read_c0_config() & MIPS_CONF_AR;
config |= MIPS_CONF_M | CONF_CM_CACHABLE_NONCOHERENT | MIPS_CONF_MT_TLB;
#ifdef CONFIG_CPU_BIG_ENDIAN
config |= CONF_BE;
#endif
if (cpu_has_vtag_icache)
config |= MIPS_CONF_VI;
kvm_write_c0_guest_config(cop0, config);
config1 = (read_c0_config1() & ~0x7f);
config1 &= ~(0x3f << 25);
config1 |= ((KVM_MIPS_GUEST_TLB_SIZE - 1) << 25);
config1 &= ~(MIPS_CONF1_C2 | MIPS_CONF1_MD | MIPS_CONF1_PC |
MIPS_CONF1_WR | MIPS_CONF1_CA);
kvm_write_c0_guest_config1(cop0, config1);
kvm_write_c0_guest_config2(cop0, MIPS_CONF_M);
kvm_write_c0_guest_config3(cop0, MIPS_CONF_M | MIPS_CONF3_ULRI);
kvm_write_c0_guest_config4(cop0, MIPS_CONF_M);
kvm_write_c0_guest_config5(cop0, 0);
kvm_write_c0_guest_config7(cop0, (MIPS_CONF7_WII) | (1 << 10));
kvm_write_c0_guest_intctl(cop0, 0xFC000000);
kvm_write_c0_guest_ebase(cop0, KVM_GUEST_KSEG0 |
(vcpu_id & MIPS_EBASE_CPUNUM));
return 0;
}
static unsigned long kvm_trap_emul_num_regs(struct kvm_vcpu *vcpu)
{
return 0;
}
static int kvm_trap_emul_copy_reg_indices(struct kvm_vcpu *vcpu,
u64 __user *indices)
{
return 0;
}
static int kvm_trap_emul_get_one_reg(struct kvm_vcpu *vcpu,
const struct kvm_one_reg *reg,
s64 *v)
{
switch (reg->id) {
case KVM_REG_MIPS_CP0_COUNT:
*v = kvm_mips_read_count(vcpu);
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
static int kvm_trap_emul_set_one_reg(struct kvm_vcpu *vcpu,
const struct kvm_one_reg *reg,
s64 v)
{
struct mips_coproc *cop0 = vcpu->arch.cop0;
int ret = 0;
unsigned int cur, change;
switch (reg->id) {
case KVM_REG_MIPS_CP0_COUNT:
kvm_mips_write_count(vcpu, v);
break;
case KVM_REG_MIPS_CP0_COMPARE:
kvm_mips_write_compare(vcpu, v, false);
break;
case KVM_REG_MIPS_CP0_CAUSE:
if ((kvm_read_c0_guest_cause(cop0) ^ v) & CAUSEF_DC) {
if (v & CAUSEF_DC) {
kvm_mips_count_disable_cause(vcpu);
kvm_change_c0_guest_cause(cop0, ~CAUSEF_DC, v);
} else {
kvm_change_c0_guest_cause(cop0, ~CAUSEF_DC, v);
kvm_mips_count_enable_cause(vcpu);
}
} else {
kvm_write_c0_guest_cause(cop0, v);
}
break;
case KVM_REG_MIPS_CP0_CONFIG:
break;
case KVM_REG_MIPS_CP0_CONFIG1:
cur = kvm_read_c0_guest_config1(cop0);
change = (cur ^ v) & kvm_mips_config1_wrmask(vcpu);
if (change) {
v = cur ^ change;
kvm_write_c0_guest_config1(cop0, v);
}
break;
case KVM_REG_MIPS_CP0_CONFIG2:
break;
case KVM_REG_MIPS_CP0_CONFIG3:
cur = kvm_read_c0_guest_config3(cop0);
change = (cur ^ v) & kvm_mips_config3_wrmask(vcpu);
if (change) {
v = cur ^ change;
kvm_write_c0_guest_config3(cop0, v);
}
break;
case KVM_REG_MIPS_CP0_CONFIG4:
cur = kvm_read_c0_guest_config4(cop0);
change = (cur ^ v) & kvm_mips_config4_wrmask(vcpu);
if (change) {
v = cur ^ change;
kvm_write_c0_guest_config4(cop0, v);
}
break;
case KVM_REG_MIPS_CP0_CONFIG5:
cur = kvm_read_c0_guest_config5(cop0);
change = (cur ^ v) & kvm_mips_config5_wrmask(vcpu);
if (change) {
v = cur ^ change;
kvm_write_c0_guest_config5(cop0, v);
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
static int kvm_trap_emul_vcpu_get_regs(struct kvm_vcpu *vcpu)
{
kvm_lose_fpu(vcpu);
return 0;
}
static int kvm_trap_emul_vcpu_set_regs(struct kvm_vcpu *vcpu)
{
return 0;
}
int kvm_mips_emulation_init(struct kvm_mips_callbacks **install_callbacks)
{
*install_callbacks = &kvm_trap_emul_callbacks;
return 0;
}
