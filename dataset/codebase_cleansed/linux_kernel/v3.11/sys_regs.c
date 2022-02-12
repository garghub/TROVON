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
static void do_dc_cisw(u32 val)
{
asm volatile("dc cisw, %x0" : : "r" (val));
dsb();
}
static void do_dc_csw(u32 val)
{
asm volatile("dc csw, %x0" : : "r" (val));
dsb();
}
static bool access_dcsw(struct kvm_vcpu *vcpu,
const struct sys_reg_params *p,
const struct sys_reg_desc *r)
{
unsigned long val;
int cpu;
if (!p->is_write)
return read_from_write_only(vcpu, p);
cpu = get_cpu();
cpumask_setall(&vcpu->arch.require_dcache_flush);
cpumask_clear_cpu(cpu, &vcpu->arch.require_dcache_flush);
if (cpu != vcpu->arch.last_pcpu) {
flush_cache_all();
goto done;
}
val = *vcpu_reg(vcpu, p->Rt);
switch (p->CRm) {
case 6:
case 14:
do_dc_cisw(val);
break;
case 10:
do_dc_csw(val);
break;
}
done:
put_cpu();
return true;
}
static bool pm_fake(struct kvm_vcpu *vcpu,
const struct sys_reg_params *p,
const struct sys_reg_desc *r)
{
if (p->is_write)
return ignore_write(vcpu, p);
else
return read_zero(vcpu, p);
}
static void reset_amair_el1(struct kvm_vcpu *vcpu, const struct sys_reg_desc *r)
{
u64 amair;
asm volatile("mrs %0, amair_el1\n" : "=r" (amair));
vcpu_sys_reg(vcpu, AMAIR_EL1) = amair;
}
static void reset_mpidr(struct kvm_vcpu *vcpu, const struct sys_reg_desc *r)
{
vcpu_sys_reg(vcpu, MPIDR_EL1) = (1UL << 31) | (vcpu->vcpu_id & 0xff);
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
int kvm_handle_cp14_access(struct kvm_vcpu *vcpu, struct kvm_run *run)
{
kvm_inject_undefined(vcpu);
return 1;
}
static void emulate_cp15(struct kvm_vcpu *vcpu,
const struct sys_reg_params *params)
{
size_t num;
const struct sys_reg_desc *table, *r;
table = get_target_table(vcpu->arch.target, false, &num);
r = find_reg(params, table, num);
if (!r)
r = find_reg(params, cp15_regs, ARRAY_SIZE(cp15_regs));
if (likely(r)) {
BUG_ON(!r->access);
if (likely(r->access(vcpu, params, r))) {
kvm_skip_instr(vcpu, kvm_vcpu_trap_il_is32bit(vcpu));
return;
}
}
kvm_err("Unsupported guest CP15 access at: %08lx\n", *vcpu_pc(vcpu));
print_sys_reg_instr(params);
kvm_inject_undefined(vcpu);
}
int kvm_handle_cp15_64(struct kvm_vcpu *vcpu, struct kvm_run *run)
{
struct sys_reg_params params;
u32 hsr = kvm_vcpu_get_hsr(vcpu);
int Rt2 = (hsr >> 10) & 0xf;
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
emulate_cp15(vcpu, &params);
if (!params.is_write) {
u64 val = *vcpu_reg(vcpu, params.Rt);
val >>= 32;
*vcpu_reg(vcpu, Rt2) = val;
}
return 1;
}
int kvm_handle_cp15_32(struct kvm_vcpu *vcpu, struct kvm_run *run)
{
struct sys_reg_params params;
u32 hsr = kvm_vcpu_get_hsr(vcpu);
params.CRm = (hsr >> 1) & 0xf;
params.Rt = (hsr >> 5) & 0xf;
params.is_write = ((hsr & 1) == 0);
params.CRn = (hsr >> 10) & 0xf;
params.Op0 = 0;
params.Op1 = (hsr >> 14) & 0x7;
params.Op2 = (hsr >> 17) & 0x7;
emulate_cp15(vcpu, &params);
return 1;
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
static int reg_from_user(void *val, const void __user *uaddr, u64 id)
{
if (copy_from_user(val, uaddr, KVM_REG_SIZE(id)) != 0)
return -EFAULT;
return 0;
}
static int reg_to_user(void __user *uaddr, const void *val, u64 id)
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
return -ENOENT;
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
u64 val = KVM_REG_ARM | KVM_REG_SIZE_U32 | KVM_REG_ARM_DEMUX;
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
void kvm_sys_reg_table_init(void)
{
unsigned int i;
struct sys_reg_desc clidr;
for (i = 1; i < ARRAY_SIZE(sys_reg_descs); i++)
BUG_ON(cmp_sys_reg(&sys_reg_descs[i-1], &sys_reg_descs[i]) >= 0);
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
