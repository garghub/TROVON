static u32 get_ccsidr(u32 csselr)
{
u32 ccsidr;
local_irq_disable();
write_sysreg(csselr, csselr_el1);
isb();
ccsidr = read_sysreg(ccsidr_el1);
local_irq_enable();
return ccsidr;
}
static bool access_dcsw(struct kvm_vcpu *vcpu,
struct sys_reg_params *p,
const struct sys_reg_desc *r)
{
if (!p->is_write)
return read_from_write_only(vcpu, p);
kvm_set_way_flush(vcpu);
return true;
}
static bool access_vm_reg(struct kvm_vcpu *vcpu,
struct sys_reg_params *p,
const struct sys_reg_desc *r)
{
bool was_enabled = vcpu_has_cache_enabled(vcpu);
BUG_ON(!p->is_write);
if (!p->is_aarch32) {
vcpu_sys_reg(vcpu, r->reg) = p->regval;
} else {
if (!p->is_32bit)
vcpu_cp15_64_high(vcpu, r->reg) = upper_32_bits(p->regval);
vcpu_cp15_64_low(vcpu, r->reg) = lower_32_bits(p->regval);
}
kvm_toggle_cache(vcpu, was_enabled);
return true;
}
static bool access_gic_sgi(struct kvm_vcpu *vcpu,
struct sys_reg_params *p,
const struct sys_reg_desc *r)
{
if (!p->is_write)
return read_from_write_only(vcpu, p);
vgic_v3_dispatch_sgi(vcpu, p->regval);
return true;
}
static bool access_gic_sre(struct kvm_vcpu *vcpu,
struct sys_reg_params *p,
const struct sys_reg_desc *r)
{
if (p->is_write)
return ignore_write(vcpu, p);
p->regval = vcpu->arch.vgic_cpu.vgic_v3.vgic_sre;
return true;
}
static bool trap_raz_wi(struct kvm_vcpu *vcpu,
struct sys_reg_params *p,
const struct sys_reg_desc *r)
{
if (p->is_write)
return ignore_write(vcpu, p);
else
return read_zero(vcpu, p);
}
static bool trap_oslsr_el1(struct kvm_vcpu *vcpu,
struct sys_reg_params *p,
const struct sys_reg_desc *r)
{
if (p->is_write) {
return ignore_write(vcpu, p);
} else {
p->regval = (1 << 3);
return true;
}
}
static bool trap_dbgauthstatus_el1(struct kvm_vcpu *vcpu,
struct sys_reg_params *p,
const struct sys_reg_desc *r)
{
if (p->is_write) {
return ignore_write(vcpu, p);
} else {
p->regval = read_sysreg(dbgauthstatus_el1);
return true;
}
}
static bool trap_debug_regs(struct kvm_vcpu *vcpu,
struct sys_reg_params *p,
const struct sys_reg_desc *r)
{
if (p->is_write) {
vcpu_sys_reg(vcpu, r->reg) = p->regval;
vcpu->arch.debug_flags |= KVM_ARM64_DEBUG_DIRTY;
} else {
p->regval = vcpu_sys_reg(vcpu, r->reg);
}
trace_trap_reg(__func__, r->reg, p->is_write, p->regval);
return true;
}
static void reg_to_dbg(struct kvm_vcpu *vcpu,
struct sys_reg_params *p,
u64 *dbg_reg)
{
u64 val = p->regval;
if (p->is_32bit) {
val &= 0xffffffffUL;
val |= ((*dbg_reg >> 32) << 32);
}
*dbg_reg = val;
vcpu->arch.debug_flags |= KVM_ARM64_DEBUG_DIRTY;
}
static void dbg_to_reg(struct kvm_vcpu *vcpu,
struct sys_reg_params *p,
u64 *dbg_reg)
{
p->regval = *dbg_reg;
if (p->is_32bit)
p->regval &= 0xffffffffUL;
}
static bool trap_bvr(struct kvm_vcpu *vcpu,
struct sys_reg_params *p,
const struct sys_reg_desc *rd)
{
u64 *dbg_reg = &vcpu->arch.vcpu_debug_state.dbg_bvr[rd->reg];
if (p->is_write)
reg_to_dbg(vcpu, p, dbg_reg);
else
dbg_to_reg(vcpu, p, dbg_reg);
trace_trap_reg(__func__, rd->reg, p->is_write, *dbg_reg);
return true;
}
static int set_bvr(struct kvm_vcpu *vcpu, const struct sys_reg_desc *rd,
const struct kvm_one_reg *reg, void __user *uaddr)
{
__u64 *r = &vcpu->arch.vcpu_debug_state.dbg_bvr[rd->reg];
if (copy_from_user(r, uaddr, KVM_REG_SIZE(reg->id)) != 0)
return -EFAULT;
return 0;
}
static int get_bvr(struct kvm_vcpu *vcpu, const struct sys_reg_desc *rd,
const struct kvm_one_reg *reg, void __user *uaddr)
{
__u64 *r = &vcpu->arch.vcpu_debug_state.dbg_bvr[rd->reg];
if (copy_to_user(uaddr, r, KVM_REG_SIZE(reg->id)) != 0)
return -EFAULT;
return 0;
}
static void reset_bvr(struct kvm_vcpu *vcpu,
const struct sys_reg_desc *rd)
{
vcpu->arch.vcpu_debug_state.dbg_bvr[rd->reg] = rd->val;
}
static bool trap_bcr(struct kvm_vcpu *vcpu,
struct sys_reg_params *p,
const struct sys_reg_desc *rd)
{
u64 *dbg_reg = &vcpu->arch.vcpu_debug_state.dbg_bcr[rd->reg];
if (p->is_write)
reg_to_dbg(vcpu, p, dbg_reg);
else
dbg_to_reg(vcpu, p, dbg_reg);
trace_trap_reg(__func__, rd->reg, p->is_write, *dbg_reg);
return true;
}
static int set_bcr(struct kvm_vcpu *vcpu, const struct sys_reg_desc *rd,
const struct kvm_one_reg *reg, void __user *uaddr)
{
__u64 *r = &vcpu->arch.vcpu_debug_state.dbg_bcr[rd->reg];
if (copy_from_user(r, uaddr, KVM_REG_SIZE(reg->id)) != 0)
return -EFAULT;
return 0;
}
static int get_bcr(struct kvm_vcpu *vcpu, const struct sys_reg_desc *rd,
const struct kvm_one_reg *reg, void __user *uaddr)
{
__u64 *r = &vcpu->arch.vcpu_debug_state.dbg_bcr[rd->reg];
if (copy_to_user(uaddr, r, KVM_REG_SIZE(reg->id)) != 0)
return -EFAULT;
return 0;
}
static void reset_bcr(struct kvm_vcpu *vcpu,
const struct sys_reg_desc *rd)
{
vcpu->arch.vcpu_debug_state.dbg_bcr[rd->reg] = rd->val;
}
static bool trap_wvr(struct kvm_vcpu *vcpu,
struct sys_reg_params *p,
const struct sys_reg_desc *rd)
{
u64 *dbg_reg = &vcpu->arch.vcpu_debug_state.dbg_wvr[rd->reg];
if (p->is_write)
reg_to_dbg(vcpu, p, dbg_reg);
else
dbg_to_reg(vcpu, p, dbg_reg);
trace_trap_reg(__func__, rd->reg, p->is_write,
vcpu->arch.vcpu_debug_state.dbg_wvr[rd->reg]);
return true;
}
static int set_wvr(struct kvm_vcpu *vcpu, const struct sys_reg_desc *rd,
const struct kvm_one_reg *reg, void __user *uaddr)
{
__u64 *r = &vcpu->arch.vcpu_debug_state.dbg_wvr[rd->reg];
if (copy_from_user(r, uaddr, KVM_REG_SIZE(reg->id)) != 0)
return -EFAULT;
return 0;
}
static int get_wvr(struct kvm_vcpu *vcpu, const struct sys_reg_desc *rd,
const struct kvm_one_reg *reg, void __user *uaddr)
{
__u64 *r = &vcpu->arch.vcpu_debug_state.dbg_wvr[rd->reg];
if (copy_to_user(uaddr, r, KVM_REG_SIZE(reg->id)) != 0)
return -EFAULT;
return 0;
}
static void reset_wvr(struct kvm_vcpu *vcpu,
const struct sys_reg_desc *rd)
{
vcpu->arch.vcpu_debug_state.dbg_wvr[rd->reg] = rd->val;
}
static bool trap_wcr(struct kvm_vcpu *vcpu,
struct sys_reg_params *p,
const struct sys_reg_desc *rd)
{
u64 *dbg_reg = &vcpu->arch.vcpu_debug_state.dbg_wcr[rd->reg];
if (p->is_write)
reg_to_dbg(vcpu, p, dbg_reg);
else
dbg_to_reg(vcpu, p, dbg_reg);
trace_trap_reg(__func__, rd->reg, p->is_write, *dbg_reg);
return true;
}
static int set_wcr(struct kvm_vcpu *vcpu, const struct sys_reg_desc *rd,
const struct kvm_one_reg *reg, void __user *uaddr)
{
__u64 *r = &vcpu->arch.vcpu_debug_state.dbg_wcr[rd->reg];
if (copy_from_user(r, uaddr, KVM_REG_SIZE(reg->id)) != 0)
return -EFAULT;
return 0;
}
static int get_wcr(struct kvm_vcpu *vcpu, const struct sys_reg_desc *rd,
const struct kvm_one_reg *reg, void __user *uaddr)
{
__u64 *r = &vcpu->arch.vcpu_debug_state.dbg_wcr[rd->reg];
if (copy_to_user(uaddr, r, KVM_REG_SIZE(reg->id)) != 0)
return -EFAULT;
return 0;
}
static void reset_wcr(struct kvm_vcpu *vcpu,
const struct sys_reg_desc *rd)
{
vcpu->arch.vcpu_debug_state.dbg_wcr[rd->reg] = rd->val;
}
static void reset_amair_el1(struct kvm_vcpu *vcpu, const struct sys_reg_desc *r)
{
vcpu_sys_reg(vcpu, AMAIR_EL1) = read_sysreg(amair_el1);
}
static void reset_mpidr(struct kvm_vcpu *vcpu, const struct sys_reg_desc *r)
{
u64 mpidr;
mpidr = (vcpu->vcpu_id & 0x0f) << MPIDR_LEVEL_SHIFT(0);
mpidr |= ((vcpu->vcpu_id >> 4) & 0xff) << MPIDR_LEVEL_SHIFT(1);
mpidr |= ((vcpu->vcpu_id >> 12) & 0xff) << MPIDR_LEVEL_SHIFT(2);
vcpu_sys_reg(vcpu, MPIDR_EL1) = (1ULL << 31) | mpidr;
}
static void reset_pmcr(struct kvm_vcpu *vcpu, const struct sys_reg_desc *r)
{
u64 pmcr, val;
pmcr = read_sysreg(pmcr_el0);
val = ((pmcr & ~ARMV8_PMU_PMCR_MASK)
| (ARMV8_PMU_PMCR_MASK & 0xdecafbad)) & (~ARMV8_PMU_PMCR_E);
vcpu_sys_reg(vcpu, PMCR_EL0) = val;
}
static bool pmu_access_el0_disabled(struct kvm_vcpu *vcpu)
{
u64 reg = vcpu_sys_reg(vcpu, PMUSERENR_EL0);
return !((reg & ARMV8_PMU_USERENR_EN) || vcpu_mode_priv(vcpu));
}
static bool pmu_write_swinc_el0_disabled(struct kvm_vcpu *vcpu)
{
u64 reg = vcpu_sys_reg(vcpu, PMUSERENR_EL0);
return !((reg & (ARMV8_PMU_USERENR_SW | ARMV8_PMU_USERENR_EN))
|| vcpu_mode_priv(vcpu));
}
static bool pmu_access_cycle_counter_el0_disabled(struct kvm_vcpu *vcpu)
{
u64 reg = vcpu_sys_reg(vcpu, PMUSERENR_EL0);
return !((reg & (ARMV8_PMU_USERENR_CR | ARMV8_PMU_USERENR_EN))
|| vcpu_mode_priv(vcpu));
}
static bool pmu_access_event_counter_el0_disabled(struct kvm_vcpu *vcpu)
{
u64 reg = vcpu_sys_reg(vcpu, PMUSERENR_EL0);
return !((reg & (ARMV8_PMU_USERENR_ER | ARMV8_PMU_USERENR_EN))
|| vcpu_mode_priv(vcpu));
}
static bool access_pmcr(struct kvm_vcpu *vcpu, struct sys_reg_params *p,
const struct sys_reg_desc *r)
{
u64 val;
if (!kvm_arm_pmu_v3_ready(vcpu))
return trap_raz_wi(vcpu, p, r);
if (pmu_access_el0_disabled(vcpu))
return false;
if (p->is_write) {
val = vcpu_sys_reg(vcpu, PMCR_EL0);
val &= ~ARMV8_PMU_PMCR_MASK;
val |= p->regval & ARMV8_PMU_PMCR_MASK;
vcpu_sys_reg(vcpu, PMCR_EL0) = val;
kvm_pmu_handle_pmcr(vcpu, val);
} else {
val = vcpu_sys_reg(vcpu, PMCR_EL0)
& ~(ARMV8_PMU_PMCR_P | ARMV8_PMU_PMCR_C);
p->regval = val;
}
return true;
}
static bool access_pmselr(struct kvm_vcpu *vcpu, struct sys_reg_params *p,
const struct sys_reg_desc *r)
{
if (!kvm_arm_pmu_v3_ready(vcpu))
return trap_raz_wi(vcpu, p, r);
if (pmu_access_event_counter_el0_disabled(vcpu))
return false;
if (p->is_write)
vcpu_sys_reg(vcpu, PMSELR_EL0) = p->regval;
else
p->regval = vcpu_sys_reg(vcpu, PMSELR_EL0)
& ARMV8_PMU_COUNTER_MASK;
return true;
}
static bool access_pmceid(struct kvm_vcpu *vcpu, struct sys_reg_params *p,
const struct sys_reg_desc *r)
{
u64 pmceid;
if (!kvm_arm_pmu_v3_ready(vcpu))
return trap_raz_wi(vcpu, p, r);
BUG_ON(p->is_write);
if (pmu_access_el0_disabled(vcpu))
return false;
if (!(p->Op2 & 1))
pmceid = read_sysreg(pmceid0_el0);
else
pmceid = read_sysreg(pmceid1_el0);
p->regval = pmceid;
return true;
}
static bool pmu_counter_idx_valid(struct kvm_vcpu *vcpu, u64 idx)
{
u64 pmcr, val;
pmcr = vcpu_sys_reg(vcpu, PMCR_EL0);
val = (pmcr >> ARMV8_PMU_PMCR_N_SHIFT) & ARMV8_PMU_PMCR_N_MASK;
if (idx >= val && idx != ARMV8_PMU_CYCLE_IDX)
return false;
return true;
}
static bool access_pmu_evcntr(struct kvm_vcpu *vcpu,
struct sys_reg_params *p,
const struct sys_reg_desc *r)
{
u64 idx;
if (!kvm_arm_pmu_v3_ready(vcpu))
return trap_raz_wi(vcpu, p, r);
if (r->CRn == 9 && r->CRm == 13) {
if (r->Op2 == 2) {
if (pmu_access_event_counter_el0_disabled(vcpu))
return false;
idx = vcpu_sys_reg(vcpu, PMSELR_EL0)
& ARMV8_PMU_COUNTER_MASK;
} else if (r->Op2 == 0) {
if (pmu_access_cycle_counter_el0_disabled(vcpu))
return false;
idx = ARMV8_PMU_CYCLE_IDX;
} else {
return false;
}
} else if (r->CRn == 0 && r->CRm == 9) {
if (pmu_access_event_counter_el0_disabled(vcpu))
return false;
idx = ARMV8_PMU_CYCLE_IDX;
} else if (r->CRn == 14 && (r->CRm & 12) == 8) {
if (pmu_access_event_counter_el0_disabled(vcpu))
return false;
idx = ((r->CRm & 3) << 3) | (r->Op2 & 7);
} else {
return false;
}
if (!pmu_counter_idx_valid(vcpu, idx))
return false;
if (p->is_write) {
if (pmu_access_el0_disabled(vcpu))
return false;
kvm_pmu_set_counter_value(vcpu, idx, p->regval);
} else {
p->regval = kvm_pmu_get_counter_value(vcpu, idx);
}
return true;
}
static bool access_pmu_evtyper(struct kvm_vcpu *vcpu, struct sys_reg_params *p,
const struct sys_reg_desc *r)
{
u64 idx, reg;
if (!kvm_arm_pmu_v3_ready(vcpu))
return trap_raz_wi(vcpu, p, r);
if (pmu_access_el0_disabled(vcpu))
return false;
if (r->CRn == 9 && r->CRm == 13 && r->Op2 == 1) {
idx = vcpu_sys_reg(vcpu, PMSELR_EL0) & ARMV8_PMU_COUNTER_MASK;
reg = PMEVTYPER0_EL0 + idx;
} else if (r->CRn == 14 && (r->CRm & 12) == 12) {
idx = ((r->CRm & 3) << 3) | (r->Op2 & 7);
if (idx == ARMV8_PMU_CYCLE_IDX)
reg = PMCCFILTR_EL0;
else
reg = PMEVTYPER0_EL0 + idx;
} else {
BUG();
}
if (!pmu_counter_idx_valid(vcpu, idx))
return false;
if (p->is_write) {
kvm_pmu_set_counter_event_type(vcpu, p->regval, idx);
vcpu_sys_reg(vcpu, reg) = p->regval & ARMV8_PMU_EVTYPE_MASK;
} else {
p->regval = vcpu_sys_reg(vcpu, reg) & ARMV8_PMU_EVTYPE_MASK;
}
return true;
}
static bool access_pmcnten(struct kvm_vcpu *vcpu, struct sys_reg_params *p,
const struct sys_reg_desc *r)
{
u64 val, mask;
if (!kvm_arm_pmu_v3_ready(vcpu))
return trap_raz_wi(vcpu, p, r);
if (pmu_access_el0_disabled(vcpu))
return false;
mask = kvm_pmu_valid_counter_mask(vcpu);
if (p->is_write) {
val = p->regval & mask;
if (r->Op2 & 0x1) {
vcpu_sys_reg(vcpu, PMCNTENSET_EL0) |= val;
kvm_pmu_enable_counter(vcpu, val);
} else {
vcpu_sys_reg(vcpu, PMCNTENSET_EL0) &= ~val;
kvm_pmu_disable_counter(vcpu, val);
}
} else {
p->regval = vcpu_sys_reg(vcpu, PMCNTENSET_EL0) & mask;
}
return true;
}
static bool access_pminten(struct kvm_vcpu *vcpu, struct sys_reg_params *p,
const struct sys_reg_desc *r)
{
u64 mask = kvm_pmu_valid_counter_mask(vcpu);
if (!kvm_arm_pmu_v3_ready(vcpu))
return trap_raz_wi(vcpu, p, r);
if (!vcpu_mode_priv(vcpu))
return false;
if (p->is_write) {
u64 val = p->regval & mask;
if (r->Op2 & 0x1)
vcpu_sys_reg(vcpu, PMINTENSET_EL1) |= val;
else
vcpu_sys_reg(vcpu, PMINTENSET_EL1) &= ~val;
} else {
p->regval = vcpu_sys_reg(vcpu, PMINTENSET_EL1) & mask;
}
return true;
}
static bool access_pmovs(struct kvm_vcpu *vcpu, struct sys_reg_params *p,
const struct sys_reg_desc *r)
{
u64 mask = kvm_pmu_valid_counter_mask(vcpu);
if (!kvm_arm_pmu_v3_ready(vcpu))
return trap_raz_wi(vcpu, p, r);
if (pmu_access_el0_disabled(vcpu))
return false;
if (p->is_write) {
if (r->CRm & 0x2)
kvm_pmu_overflow_set(vcpu, p->regval & mask);
else
vcpu_sys_reg(vcpu, PMOVSSET_EL0) &= ~(p->regval & mask);
} else {
p->regval = vcpu_sys_reg(vcpu, PMOVSSET_EL0) & mask;
}
return true;
}
static bool access_pmswinc(struct kvm_vcpu *vcpu, struct sys_reg_params *p,
const struct sys_reg_desc *r)
{
u64 mask;
if (!kvm_arm_pmu_v3_ready(vcpu))
return trap_raz_wi(vcpu, p, r);
if (pmu_write_swinc_el0_disabled(vcpu))
return false;
if (p->is_write) {
mask = kvm_pmu_valid_counter_mask(vcpu);
kvm_pmu_software_increment(vcpu, p->regval & mask);
return true;
}
return false;
}
static bool access_pmuserenr(struct kvm_vcpu *vcpu, struct sys_reg_params *p,
const struct sys_reg_desc *r)
{
if (!kvm_arm_pmu_v3_ready(vcpu))
return trap_raz_wi(vcpu, p, r);
if (p->is_write) {
if (!vcpu_mode_priv(vcpu))
return false;
vcpu_sys_reg(vcpu, PMUSERENR_EL0) = p->regval
& ARMV8_PMU_USERENR_MASK;
} else {
p->regval = vcpu_sys_reg(vcpu, PMUSERENR_EL0)
& ARMV8_PMU_USERENR_MASK;
}
return true;
}
static bool trap_dbgidr(struct kvm_vcpu *vcpu,
struct sys_reg_params *p,
const struct sys_reg_desc *r)
{
if (p->is_write) {
return ignore_write(vcpu, p);
} else {
u64 dfr = read_system_reg(SYS_ID_AA64DFR0_EL1);
u64 pfr = read_system_reg(SYS_ID_AA64PFR0_EL1);
u32 el3 = !!cpuid_feature_extract_unsigned_field(pfr, ID_AA64PFR0_EL3_SHIFT);
p->regval = ((((dfr >> ID_AA64DFR0_WRPS_SHIFT) & 0xf) << 28) |
(((dfr >> ID_AA64DFR0_BRPS_SHIFT) & 0xf) << 24) |
(((dfr >> ID_AA64DFR0_CTX_CMPS_SHIFT) & 0xf) << 20)
| (6 << 16) | (el3 << 14) | (el3 << 12));
return true;
}
}
static bool trap_debug32(struct kvm_vcpu *vcpu,
struct sys_reg_params *p,
const struct sys_reg_desc *r)
{
if (p->is_write) {
vcpu_cp14(vcpu, r->reg) = p->regval;
vcpu->arch.debug_flags |= KVM_ARM64_DEBUG_DIRTY;
} else {
p->regval = vcpu_cp14(vcpu, r->reg);
}
return true;
}
static bool trap_xvr(struct kvm_vcpu *vcpu,
struct sys_reg_params *p,
const struct sys_reg_desc *rd)
{
u64 *dbg_reg = &vcpu->arch.vcpu_debug_state.dbg_bvr[rd->reg];
if (p->is_write) {
u64 val = *dbg_reg;
val &= 0xffffffffUL;
val |= p->regval << 32;
*dbg_reg = val;
vcpu->arch.debug_flags |= KVM_ARM64_DEBUG_DIRTY;
} else {
p->regval = *dbg_reg >> 32;
}
trace_trap_reg(__func__, rd->reg, p->is_write, *dbg_reg);
return true;
}
void kvm_register_target_sys_reg_table(unsigned int target,
struct kvm_sys_reg_target_table *table)
{
target_tables[target] = table;
}
static const struct sys_reg_desc *get_target_table(unsigned target,
bool mode_is_64,
size_t *num)
{
struct kvm_sys_reg_target_table *table;
table = target_tables[target];
if (mode_is_64) {
*num = table->table64.num;
return table->table64.table;
} else {
*num = table->table32.num;
return table->table32.table;
}
}
static int match_sys_reg(const void *key, const void *elt)
{
const unsigned long pval = (unsigned long)key;
const struct sys_reg_desc *r = elt;
return pval - reg_to_match_value(r);
}
static const struct sys_reg_desc *find_reg(const struct sys_reg_params *params,
const struct sys_reg_desc table[],
unsigned int num)
{
unsigned long pval = reg_to_match_value(params);
return bsearch((void *)pval, table, num, sizeof(table[0]), match_sys_reg);
}
int kvm_handle_cp14_load_store(struct kvm_vcpu *vcpu, struct kvm_run *run)
{
kvm_inject_undefined(vcpu);
return 1;
}
static int emulate_cp(struct kvm_vcpu *vcpu,
struct sys_reg_params *params,
const struct sys_reg_desc *table,
size_t num)
{
const struct sys_reg_desc *r;
if (!table)
return -1;
r = find_reg(params, table, num);
if (r) {
BUG_ON(!r->access);
if (likely(r->access(vcpu, params, r))) {
kvm_skip_instr(vcpu, kvm_vcpu_trap_il_is32bit(vcpu));
return 0;
}
}
return -1;
}
static void unhandled_cp_access(struct kvm_vcpu *vcpu,
struct sys_reg_params *params)
{
u8 hsr_ec = kvm_vcpu_trap_get_class(vcpu);
int cp = -1;
switch(hsr_ec) {
case ESR_ELx_EC_CP15_32:
case ESR_ELx_EC_CP15_64:
cp = 15;
break;
case ESR_ELx_EC_CP14_MR:
case ESR_ELx_EC_CP14_64:
cp = 14;
break;
default:
WARN_ON(1);
}
kvm_err("Unsupported guest CP%d access at: %08lx\n",
cp, *vcpu_pc(vcpu));
print_sys_reg_instr(params);
kvm_inject_undefined(vcpu);
}
static int kvm_handle_cp_64(struct kvm_vcpu *vcpu,
const struct sys_reg_desc *global,
size_t nr_global,
const struct sys_reg_desc *target_specific,
size_t nr_specific)
{
struct sys_reg_params params;
u32 hsr = kvm_vcpu_get_hsr(vcpu);
int Rt = (hsr >> 5) & 0xf;
int Rt2 = (hsr >> 10) & 0xf;
params.is_aarch32 = true;
params.is_32bit = false;
params.CRm = (hsr >> 1) & 0xf;
params.is_write = ((hsr & 1) == 0);
params.Op0 = 0;
params.Op1 = (hsr >> 16) & 0xf;
params.Op2 = 0;
params.CRn = 0;
if (params.is_write) {
params.regval = vcpu_get_reg(vcpu, Rt) & 0xffffffff;
params.regval |= vcpu_get_reg(vcpu, Rt2) << 32;
}
if (!emulate_cp(vcpu, &params, target_specific, nr_specific))
goto out;
if (!emulate_cp(vcpu, &params, global, nr_global))
goto out;
unhandled_cp_access(vcpu, &params);
out:
if (!params.is_write) {
vcpu_set_reg(vcpu, Rt, lower_32_bits(params.regval));
vcpu_set_reg(vcpu, Rt2, upper_32_bits(params.regval));
}
return 1;
}
static int kvm_handle_cp_32(struct kvm_vcpu *vcpu,
const struct sys_reg_desc *global,
size_t nr_global,
const struct sys_reg_desc *target_specific,
size_t nr_specific)
{
struct sys_reg_params params;
u32 hsr = kvm_vcpu_get_hsr(vcpu);
int Rt = (hsr >> 5) & 0xf;
params.is_aarch32 = true;
params.is_32bit = true;
params.CRm = (hsr >> 1) & 0xf;
params.regval = vcpu_get_reg(vcpu, Rt);
params.is_write = ((hsr & 1) == 0);
params.CRn = (hsr >> 10) & 0xf;
params.Op0 = 0;
params.Op1 = (hsr >> 14) & 0x7;
params.Op2 = (hsr >> 17) & 0x7;
if (!emulate_cp(vcpu, &params, target_specific, nr_specific) ||
!emulate_cp(vcpu, &params, global, nr_global)) {
if (!params.is_write)
vcpu_set_reg(vcpu, Rt, params.regval);
return 1;
}
unhandled_cp_access(vcpu, &params);
return 1;
}
int kvm_handle_cp15_64(struct kvm_vcpu *vcpu, struct kvm_run *run)
{
const struct sys_reg_desc *target_specific;
size_t num;
target_specific = get_target_table(vcpu->arch.target, false, &num);
return kvm_handle_cp_64(vcpu,
cp15_64_regs, ARRAY_SIZE(cp15_64_regs),
target_specific, num);
}
int kvm_handle_cp15_32(struct kvm_vcpu *vcpu, struct kvm_run *run)
{
const struct sys_reg_desc *target_specific;
size_t num;
target_specific = get_target_table(vcpu->arch.target, false, &num);
return kvm_handle_cp_32(vcpu,
cp15_regs, ARRAY_SIZE(cp15_regs),
target_specific, num);
}
int kvm_handle_cp14_64(struct kvm_vcpu *vcpu, struct kvm_run *run)
{
return kvm_handle_cp_64(vcpu,
cp14_64_regs, ARRAY_SIZE(cp14_64_regs),
NULL, 0);
}
int kvm_handle_cp14_32(struct kvm_vcpu *vcpu, struct kvm_run *run)
{
return kvm_handle_cp_32(vcpu,
cp14_regs, ARRAY_SIZE(cp14_regs),
NULL, 0);
}
static int emulate_sys_reg(struct kvm_vcpu *vcpu,
struct sys_reg_params *params)
{
size_t num;
const struct sys_reg_desc *table, *r;
table = get_target_table(vcpu->arch.target, true, &num);
r = find_reg(params, table, num);
if (!r)
r = find_reg(params, sys_reg_descs, ARRAY_SIZE(sys_reg_descs));
if (likely(r)) {
BUG_ON(!r->access);
if (likely(r->access(vcpu, params, r))) {
kvm_skip_instr(vcpu, kvm_vcpu_trap_il_is32bit(vcpu));
return 1;
}
} else {
kvm_err("Unsupported guest sys_reg access at: %lx\n",
*vcpu_pc(vcpu));
print_sys_reg_instr(params);
}
kvm_inject_undefined(vcpu);
return 1;
}
static void reset_sys_reg_descs(struct kvm_vcpu *vcpu,
const struct sys_reg_desc *table, size_t num)
{
unsigned long i;
for (i = 0; i < num; i++)
if (table[i].reset)
table[i].reset(vcpu, &table[i]);
}
int kvm_handle_sys_reg(struct kvm_vcpu *vcpu, struct kvm_run *run)
{
struct sys_reg_params params;
unsigned long esr = kvm_vcpu_get_hsr(vcpu);
int Rt = (esr >> 5) & 0x1f;
int ret;
trace_kvm_handle_sys_reg(esr);
params.is_aarch32 = false;
params.is_32bit = false;
params.Op0 = (esr >> 20) & 3;
params.Op1 = (esr >> 14) & 0x7;
params.CRn = (esr >> 10) & 0xf;
params.CRm = (esr >> 1) & 0xf;
params.Op2 = (esr >> 17) & 0x7;
params.regval = vcpu_get_reg(vcpu, Rt);
params.is_write = !(esr & 1);
ret = emulate_sys_reg(vcpu, &params);
if (!params.is_write)
vcpu_set_reg(vcpu, Rt, params.regval);
return ret;
}
static bool index_to_params(u64 id, struct sys_reg_params *params)
{
switch (id & KVM_REG_SIZE_MASK) {
case KVM_REG_SIZE_U64:
if (id & ~(KVM_REG_ARCH_MASK | KVM_REG_SIZE_MASK
| KVM_REG_ARM_COPROC_MASK
| KVM_REG_ARM64_SYSREG_OP0_MASK
| KVM_REG_ARM64_SYSREG_OP1_MASK
| KVM_REG_ARM64_SYSREG_CRN_MASK
| KVM_REG_ARM64_SYSREG_CRM_MASK
| KVM_REG_ARM64_SYSREG_OP2_MASK))
return false;
params->Op0 = ((id & KVM_REG_ARM64_SYSREG_OP0_MASK)
>> KVM_REG_ARM64_SYSREG_OP0_SHIFT);
params->Op1 = ((id & KVM_REG_ARM64_SYSREG_OP1_MASK)
>> KVM_REG_ARM64_SYSREG_OP1_SHIFT);
params->CRn = ((id & KVM_REG_ARM64_SYSREG_CRN_MASK)
>> KVM_REG_ARM64_SYSREG_CRN_SHIFT);
params->CRm = ((id & KVM_REG_ARM64_SYSREG_CRM_MASK)
>> KVM_REG_ARM64_SYSREG_CRM_SHIFT);
params->Op2 = ((id & KVM_REG_ARM64_SYSREG_OP2_MASK)
>> KVM_REG_ARM64_SYSREG_OP2_SHIFT);
return true;
default:
return false;
}
}
static const struct sys_reg_desc *index_to_sys_reg_desc(struct kvm_vcpu *vcpu,
u64 id)
{
size_t num;
const struct sys_reg_desc *table, *r;
struct sys_reg_params params;
if ((id & KVM_REG_ARM_COPROC_MASK) != KVM_REG_ARM64_SYSREG)
return NULL;
if (!index_to_params(id, &params))
return NULL;
table = get_target_table(vcpu->arch.target, true, &num);
r = find_reg(&params, table, num);
if (!r)
r = find_reg(&params, sys_reg_descs, ARRAY_SIZE(sys_reg_descs));
if (r && !r->reg)
r = NULL;
return r;
}
static int reg_from_user(u64 *val, const void __user *uaddr, u64 id)
{
if (copy_from_user(val, uaddr, KVM_REG_SIZE(id)) != 0)
return -EFAULT;
return 0;
}
static int reg_to_user(void __user *uaddr, const u64 *val, u64 id)
{
if (copy_to_user(uaddr, val, KVM_REG_SIZE(id)) != 0)
return -EFAULT;
return 0;
}
static int get_invariant_sys_reg(u64 id, void __user *uaddr)
{
struct sys_reg_params params;
const struct sys_reg_desc *r;
if (!index_to_params(id, &params))
return -ENOENT;
r = find_reg(&params, invariant_sys_regs, ARRAY_SIZE(invariant_sys_regs));
if (!r)
return -ENOENT;
return reg_to_user(uaddr, &r->val, id);
}
static int set_invariant_sys_reg(u64 id, void __user *uaddr)
{
struct sys_reg_params params;
const struct sys_reg_desc *r;
int err;
u64 val = 0;
if (!index_to_params(id, &params))
return -ENOENT;
r = find_reg(&params, invariant_sys_regs, ARRAY_SIZE(invariant_sys_regs));
if (!r)
return -ENOENT;
err = reg_from_user(&val, uaddr, id);
if (err)
return err;
if (r->val != val)
return -EINVAL;
return 0;
}
static bool is_valid_cache(u32 val)
{
u32 level, ctype;
if (val >= CSSELR_MAX)
return false;
level = (val >> 1);
ctype = (cache_levels >> (level * 3)) & 7;
switch (ctype) {
case 0:
return false;
case 1:
return (val & 1);
case 2:
case 4:
return !(val & 1);
case 3:
return true;
default:
return false;
}
}
static int demux_c15_get(u64 id, void __user *uaddr)
{
u32 val;
u32 __user *uval = uaddr;
if (id & ~(KVM_REG_ARCH_MASK|KVM_REG_SIZE_MASK|KVM_REG_ARM_COPROC_MASK
| ((1 << KVM_REG_ARM_COPROC_SHIFT)-1)))
return -ENOENT;
switch (id & KVM_REG_ARM_DEMUX_ID_MASK) {
case KVM_REG_ARM_DEMUX_ID_CCSIDR:
if (KVM_REG_SIZE(id) != 4)
return -ENOENT;
val = (id & KVM_REG_ARM_DEMUX_VAL_MASK)
>> KVM_REG_ARM_DEMUX_VAL_SHIFT;
if (!is_valid_cache(val))
return -ENOENT;
return put_user(get_ccsidr(val), uval);
default:
return -ENOENT;
}
}
static int demux_c15_set(u64 id, void __user *uaddr)
{
u32 val, newval;
u32 __user *uval = uaddr;
if (id & ~(KVM_REG_ARCH_MASK|KVM_REG_SIZE_MASK|KVM_REG_ARM_COPROC_MASK
| ((1 << KVM_REG_ARM_COPROC_SHIFT)-1)))
return -ENOENT;
switch (id & KVM_REG_ARM_DEMUX_ID_MASK) {
case KVM_REG_ARM_DEMUX_ID_CCSIDR:
if (KVM_REG_SIZE(id) != 4)
return -ENOENT;
val = (id & KVM_REG_ARM_DEMUX_VAL_MASK)
>> KVM_REG_ARM_DEMUX_VAL_SHIFT;
if (!is_valid_cache(val))
return -ENOENT;
if (get_user(newval, uval))
return -EFAULT;
if (newval != get_ccsidr(val))
return -EINVAL;
return 0;
default:
return -ENOENT;
}
}
int kvm_arm_sys_reg_get_reg(struct kvm_vcpu *vcpu, const struct kvm_one_reg *reg)
{
const struct sys_reg_desc *r;
void __user *uaddr = (void __user *)(unsigned long)reg->addr;
if ((reg->id & KVM_REG_ARM_COPROC_MASK) == KVM_REG_ARM_DEMUX)
return demux_c15_get(reg->id, uaddr);
if (KVM_REG_SIZE(reg->id) != sizeof(__u64))
return -ENOENT;
r = index_to_sys_reg_desc(vcpu, reg->id);
if (!r)
return get_invariant_sys_reg(reg->id, uaddr);
if (r->get_user)
return (r->get_user)(vcpu, r, reg, uaddr);
return reg_to_user(uaddr, &vcpu_sys_reg(vcpu, r->reg), reg->id);
}
int kvm_arm_sys_reg_set_reg(struct kvm_vcpu *vcpu, const struct kvm_one_reg *reg)
{
const struct sys_reg_desc *r;
void __user *uaddr = (void __user *)(unsigned long)reg->addr;
if ((reg->id & KVM_REG_ARM_COPROC_MASK) == KVM_REG_ARM_DEMUX)
return demux_c15_set(reg->id, uaddr);
if (KVM_REG_SIZE(reg->id) != sizeof(__u64))
return -ENOENT;
r = index_to_sys_reg_desc(vcpu, reg->id);
if (!r)
return set_invariant_sys_reg(reg->id, uaddr);
if (r->set_user)
return (r->set_user)(vcpu, r, reg, uaddr);
return reg_from_user(&vcpu_sys_reg(vcpu, r->reg), uaddr, reg->id);
}
static unsigned int num_demux_regs(void)
{
unsigned int i, count = 0;
for (i = 0; i < CSSELR_MAX; i++)
if (is_valid_cache(i))
count++;
return count;
}
static int write_demux_regids(u64 __user *uindices)
{
u64 val = KVM_REG_ARM64 | KVM_REG_SIZE_U32 | KVM_REG_ARM_DEMUX;
unsigned int i;
val |= KVM_REG_ARM_DEMUX_ID_CCSIDR;
for (i = 0; i < CSSELR_MAX; i++) {
if (!is_valid_cache(i))
continue;
if (put_user(val | i, uindices))
return -EFAULT;
uindices++;
}
return 0;
}
static u64 sys_reg_to_index(const struct sys_reg_desc *reg)
{
return (KVM_REG_ARM64 | KVM_REG_SIZE_U64 |
KVM_REG_ARM64_SYSREG |
(reg->Op0 << KVM_REG_ARM64_SYSREG_OP0_SHIFT) |
(reg->Op1 << KVM_REG_ARM64_SYSREG_OP1_SHIFT) |
(reg->CRn << KVM_REG_ARM64_SYSREG_CRN_SHIFT) |
(reg->CRm << KVM_REG_ARM64_SYSREG_CRM_SHIFT) |
(reg->Op2 << KVM_REG_ARM64_SYSREG_OP2_SHIFT));
}
static bool copy_reg_to_user(const struct sys_reg_desc *reg, u64 __user **uind)
{
if (!*uind)
return true;
if (put_user(sys_reg_to_index(reg), *uind))
return false;
(*uind)++;
return true;
}
static int walk_sys_regs(struct kvm_vcpu *vcpu, u64 __user *uind)
{
const struct sys_reg_desc *i1, *i2, *end1, *end2;
unsigned int total = 0;
size_t num;
i1 = get_target_table(vcpu->arch.target, true, &num);
end1 = i1 + num;
i2 = sys_reg_descs;
end2 = sys_reg_descs + ARRAY_SIZE(sys_reg_descs);
BUG_ON(i1 == end1 || i2 == end2);
while (i1 || i2) {
int cmp = cmp_sys_reg(i1, i2);
if (cmp <= 0) {
if (i1->reg) {
if (!copy_reg_to_user(i1, &uind))
return -EFAULT;
total++;
}
} else {
if (i2->reg) {
if (!copy_reg_to_user(i2, &uind))
return -EFAULT;
total++;
}
}
if (cmp <= 0 && ++i1 == end1)
i1 = NULL;
if (cmp >= 0 && ++i2 == end2)
i2 = NULL;
}
return total;
}
unsigned long kvm_arm_num_sys_reg_descs(struct kvm_vcpu *vcpu)
{
return ARRAY_SIZE(invariant_sys_regs)
+ num_demux_regs()
+ walk_sys_regs(vcpu, (u64 __user *)NULL);
}
int kvm_arm_copy_sys_reg_indices(struct kvm_vcpu *vcpu, u64 __user *uindices)
{
unsigned int i;
int err;
for (i = 0; i < ARRAY_SIZE(invariant_sys_regs); i++) {
if (put_user(sys_reg_to_index(&invariant_sys_regs[i]), uindices))
return -EFAULT;
uindices++;
}
err = walk_sys_regs(vcpu, uindices);
if (err < 0)
return err;
uindices += err;
return write_demux_regids(uindices);
}
static int check_sysreg_table(const struct sys_reg_desc *table, unsigned int n)
{
unsigned int i;
for (i = 1; i < n; i++) {
if (cmp_sys_reg(&table[i-1], &table[i]) >= 0) {
kvm_err("sys_reg table %p out of order (%d)\n", table, i - 1);
return 1;
}
}
return 0;
}
void kvm_sys_reg_table_init(void)
{
unsigned int i;
struct sys_reg_desc clidr;
BUG_ON(check_sysreg_table(sys_reg_descs, ARRAY_SIZE(sys_reg_descs)));
BUG_ON(check_sysreg_table(cp14_regs, ARRAY_SIZE(cp14_regs)));
BUG_ON(check_sysreg_table(cp14_64_regs, ARRAY_SIZE(cp14_64_regs)));
BUG_ON(check_sysreg_table(cp15_regs, ARRAY_SIZE(cp15_regs)));
BUG_ON(check_sysreg_table(cp15_64_regs, ARRAY_SIZE(cp15_64_regs)));
BUG_ON(check_sysreg_table(invariant_sys_regs, ARRAY_SIZE(invariant_sys_regs)));
for (i = 0; i < ARRAY_SIZE(invariant_sys_regs); i++)
invariant_sys_regs[i].reset(NULL, &invariant_sys_regs[i]);
get_clidr_el1(NULL, &clidr);
cache_levels = clidr.val;
for (i = 0; i < 7; i++)
if (((cache_levels >> (i*3)) & 7) == 0)
break;
cache_levels &= (1 << (i*3))-1;
}
void kvm_reset_sys_regs(struct kvm_vcpu *vcpu)
{
size_t num;
const struct sys_reg_desc *table;
memset(&vcpu->arch.ctxt.sys_regs, 0x42, sizeof(vcpu->arch.ctxt.sys_regs));
reset_sys_reg_descs(vcpu, sys_reg_descs, ARRAY_SIZE(sys_reg_descs));
table = get_target_table(vcpu->arch.target, true, &num);
reset_sys_reg_descs(vcpu, table, num);
for (num = 1; num < NR_SYS_REGS; num++)
if (vcpu_sys_reg(vcpu, num) == 0x4242424242424242)
panic("Didn't reset vcpu_sys_reg(%zi)", num);
}
