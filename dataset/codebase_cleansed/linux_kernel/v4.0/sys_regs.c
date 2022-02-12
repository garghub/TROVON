static u32 get_ccsidr(u32 csselr)
{
u32 ccsidr;
local_irq_disable();
asm volatile("msr csselr_el1, %x0" : : "r" (csselr));
isb();
asm volatile("mrs %0, ccsidr_el1" : "=r" (ccsidr));
local_irq_enable();
return ccsidr;
}
static bool access_dcsw(struct kvm_vcpu *vcpu,
const struct sys_reg_params *p,
const struct sys_reg_desc *r)
{
if (!p->is_write)
return read_from_write_only(vcpu, p);
kvm_set_way_flush(vcpu);
return true;
}
static bool access_vm_reg(struct kvm_vcpu *vcpu,
const struct sys_reg_params *p,
const struct sys_reg_desc *r)
{
unsigned long val;
bool was_enabled = vcpu_has_cache_enabled(vcpu);
BUG_ON(!p->is_write);
val = *vcpu_reg(vcpu, p->Rt);
if (!p->is_aarch32) {
vcpu_sys_reg(vcpu, r->reg) = val;
} else {
if (!p->is_32bit)
vcpu_cp15_64_high(vcpu, r->reg) = val >> 32;
vcpu_cp15_64_low(vcpu, r->reg) = val & 0xffffffffUL;
}
kvm_toggle_cache(vcpu, was_enabled);
return true;
}
static bool access_gic_sgi(struct kvm_vcpu *vcpu,
const struct sys_reg_params *p,
const struct sys_reg_desc *r)
{
u64 val;
if (!p->is_write)
return read_from_write_only(vcpu, p);
val = *vcpu_reg(vcpu, p->Rt);
vgic_v3_dispatch_sgi(vcpu, val);
return true;
}
static bool trap_raz_wi(struct kvm_vcpu *vcpu,
const struct sys_reg_params *p,
const struct sys_reg_desc *r)
{
if (p->is_write)
return ignore_write(vcpu, p);
else
return read_zero(vcpu, p);
}
static bool trap_oslsr_el1(struct kvm_vcpu *vcpu,
const struct sys_reg_params *p,
const struct sys_reg_desc *r)
{
if (p->is_write) {
return ignore_write(vcpu, p);
} else {
*vcpu_reg(vcpu, p->Rt) = (1 << 3);
return true;
}
}
static bool trap_dbgauthstatus_el1(struct kvm_vcpu *vcpu,
const struct sys_reg_params *p,
const struct sys_reg_desc *r)
{
if (p->is_write) {
return ignore_write(vcpu, p);
} else {
u32 val;
asm volatile("mrs %0, dbgauthstatus_el1" : "=r" (val));
*vcpu_reg(vcpu, p->Rt) = val;
return true;
}
}
static bool trap_debug_regs(struct kvm_vcpu *vcpu,
const struct sys_reg_params *p,
const struct sys_reg_desc *r)
{
if (p->is_write) {
vcpu_sys_reg(vcpu, r->reg) = *vcpu_reg(vcpu, p->Rt);
vcpu->arch.debug_flags |= KVM_ARM64_DEBUG_DIRTY;
} else {
*vcpu_reg(vcpu, p->Rt) = vcpu_sys_reg(vcpu, r->reg);
}
return true;
}
static void reset_amair_el1(struct kvm_vcpu *vcpu, const struct sys_reg_desc *r)
{
u64 amair;
asm volatile("mrs %0, amair_el1\n" : "=r" (amair));
vcpu_sys_reg(vcpu, AMAIR_EL1) = amair;
}
static void reset_mpidr(struct kvm_vcpu *vcpu, const struct sys_reg_desc *r)
{
u64 mpidr;
mpidr = (vcpu->vcpu_id & 0x0f) << MPIDR_LEVEL_SHIFT(0);
mpidr |= ((vcpu->vcpu_id >> 4) & 0xff) << MPIDR_LEVEL_SHIFT(1);
mpidr |= ((vcpu->vcpu_id >> 12) & 0xff) << MPIDR_LEVEL_SHIFT(2);
vcpu_sys_reg(vcpu, MPIDR_EL1) = (1ULL << 31) | mpidr;
}
static bool trap_dbgidr(struct kvm_vcpu *vcpu,
const struct sys_reg_params *p,
const struct sys_reg_desc *r)
{
if (p->is_write) {
return ignore_write(vcpu, p);
} else {
u64 dfr = read_cpuid(ID_AA64DFR0_EL1);
u64 pfr = read_cpuid(ID_AA64PFR0_EL1);
u32 el3 = !!((pfr >> 12) & 0xf);
*vcpu_reg(vcpu, p->Rt) = ((((dfr >> 20) & 0xf) << 28) |
(((dfr >> 12) & 0xf) << 24) |
(((dfr >> 28) & 0xf) << 20) |
(6 << 16) | (el3 << 14) | (el3 << 12));
return true;
}
}
static bool trap_debug32(struct kvm_vcpu *vcpu,
const struct sys_reg_params *p,
const struct sys_reg_desc *r)
{
if (p->is_write) {
vcpu_cp14(vcpu, r->reg) = *vcpu_reg(vcpu, p->Rt);
vcpu->arch.debug_flags |= KVM_ARM64_DEBUG_DIRTY;
} else {
*vcpu_reg(vcpu, p->Rt) = vcpu_cp14(vcpu, r->reg);
}
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
static const struct sys_reg_desc *find_reg(const struct sys_reg_params *params,
const struct sys_reg_desc table[],
unsigned int num)
{
unsigned int i;
for (i = 0; i < num; i++) {
const struct sys_reg_desc *r = &table[i];
if (params->Op0 != r->Op0)
continue;
if (params->Op1 != r->Op1)
continue;
if (params->CRn != r->CRn)
continue;
if (params->CRm != r->CRm)
continue;
if (params->Op2 != r->Op2)
continue;
return r;
}
return NULL;
}
int kvm_handle_cp14_load_store(struct kvm_vcpu *vcpu, struct kvm_run *run)
{
kvm_inject_undefined(vcpu);
return 1;
}
static int emulate_cp(struct kvm_vcpu *vcpu,
const struct sys_reg_params *params,
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
}
return 0;
}
return -1;
}
static void unhandled_cp_access(struct kvm_vcpu *vcpu,
struct sys_reg_params *params)
{
u8 hsr_ec = kvm_vcpu_trap_get_class(vcpu);
int cp;
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
WARN_ON((cp = -1));
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
int Rt2 = (hsr >> 10) & 0xf;
params.is_aarch32 = true;
params.is_32bit = false;
params.CRm = (hsr >> 1) & 0xf;
params.Rt = (hsr >> 5) & 0xf;
params.is_write = ((hsr & 1) == 0);
params.Op0 = 0;
params.Op1 = (hsr >> 16) & 0xf;
params.Op2 = 0;
params.CRn = 0;
if (params.is_write) {
u64 val = *vcpu_reg(vcpu, params.Rt);
val &= 0xffffffff;
val |= *vcpu_reg(vcpu, Rt2) << 32;
*vcpu_reg(vcpu, params.Rt) = val;
}
if (!emulate_cp(vcpu, &params, target_specific, nr_specific))
goto out;
if (!emulate_cp(vcpu, &params, global, nr_global))
goto out;
unhandled_cp_access(vcpu, &params);
out:
if (!params.is_write) {
u64 val = *vcpu_reg(vcpu, params.Rt);
val >>= 32;
*vcpu_reg(vcpu, Rt2) = val;
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
params.is_aarch32 = true;
params.is_32bit = true;
params.CRm = (hsr >> 1) & 0xf;
params.Rt = (hsr >> 5) & 0xf;
params.is_write = ((hsr & 1) == 0);
params.CRn = (hsr >> 10) & 0xf;
params.Op0 = 0;
params.Op1 = (hsr >> 14) & 0x7;
params.Op2 = (hsr >> 17) & 0x7;
if (!emulate_cp(vcpu, &params, target_specific, nr_specific))
return 1;
if (!emulate_cp(vcpu, &params, global, nr_global))
return 1;
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
const struct sys_reg_params *params)
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
params.is_aarch32 = false;
params.is_32bit = false;
params.Op0 = (esr >> 20) & 3;
params.Op1 = (esr >> 14) & 0x7;
params.CRn = (esr >> 10) & 0xf;
params.CRm = (esr >> 1) & 0xf;
params.Op2 = (esr >> 17) & 0x7;
params.Rt = (esr >> 5) & 0x1f;
params.is_write = !(esr & 1);
return emulate_sys_reg(vcpu, &params);
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
