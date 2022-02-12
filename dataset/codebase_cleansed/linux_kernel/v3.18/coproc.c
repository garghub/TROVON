static inline void vcpu_cp15_reg64_set(struct kvm_vcpu *vcpu,
const struct coproc_reg *r,
u64 val)
{
vcpu->arch.cp15[r->reg] = val & 0xffffffff;
vcpu->arch.cp15[r->reg + 1] = val >> 32;
}
static inline u64 vcpu_cp15_reg64_get(struct kvm_vcpu *vcpu,
const struct coproc_reg *r)
{
u64 val;
val = vcpu->arch.cp15[r->reg + 1];
val = val << 32;
val = val | vcpu->arch.cp15[r->reg];
return val;
}
int kvm_handle_cp10_id(struct kvm_vcpu *vcpu, struct kvm_run *run)
{
kvm_inject_undefined(vcpu);
return 1;
}
int kvm_handle_cp_0_13_access(struct kvm_vcpu *vcpu, struct kvm_run *run)
{
kvm_inject_undefined(vcpu);
return 1;
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
static void reset_mpidr(struct kvm_vcpu *vcpu, const struct coproc_reg *r)
{
vcpu->arch.cp15[c0_MPIDR] = ((read_cpuid_mpidr() & MPIDR_SMP_BITMASK) |
((vcpu->vcpu_id >> 2) << MPIDR_LEVEL_BITS) |
(vcpu->vcpu_id & 3));
}
static bool access_actlr(struct kvm_vcpu *vcpu,
const struct coproc_params *p,
const struct coproc_reg *r)
{
if (p->is_write)
return ignore_write(vcpu, p);
*vcpu_reg(vcpu, p->Rt1) = vcpu->arch.cp15[c1_ACTLR];
return true;
}
static bool access_cbar(struct kvm_vcpu *vcpu,
const struct coproc_params *p,
const struct coproc_reg *r)
{
if (p->is_write)
return write_to_read_only(vcpu, p);
return read_zero(vcpu, p);
}
static bool access_l2ctlr(struct kvm_vcpu *vcpu,
const struct coproc_params *p,
const struct coproc_reg *r)
{
if (p->is_write)
return ignore_write(vcpu, p);
*vcpu_reg(vcpu, p->Rt1) = vcpu->arch.cp15[c9_L2CTLR];
return true;
}
static void reset_l2ctlr(struct kvm_vcpu *vcpu, const struct coproc_reg *r)
{
u32 l2ctlr, ncores;
asm volatile("mrc p15, 1, %0, c9, c0, 2\n" : "=r" (l2ctlr));
l2ctlr &= ~(3 << 24);
ncores = atomic_read(&vcpu->kvm->online_vcpus) - 1;
ncores -= (vcpu->vcpu_id & ~3);
ncores = min(ncores, 3U);
l2ctlr |= (ncores & 3) << 24;
vcpu->arch.cp15[c9_L2CTLR] = l2ctlr;
}
static void reset_actlr(struct kvm_vcpu *vcpu, const struct coproc_reg *r)
{
u32 actlr;
asm volatile("mrc p15, 0, %0, c1, c0, 1\n" : "=r" (actlr));
if (atomic_read(&vcpu->kvm->online_vcpus) > 1)
actlr |= 1U << 6;
else
actlr &= ~(1U << 6);
vcpu->arch.cp15[c1_ACTLR] = actlr;
}
static bool access_l2ectlr(struct kvm_vcpu *vcpu,
const struct coproc_params *p,
const struct coproc_reg *r)
{
if (p->is_write)
return ignore_write(vcpu, p);
*vcpu_reg(vcpu, p->Rt1) = 0;
return true;
}
static bool access_dcsw(struct kvm_vcpu *vcpu,
const struct coproc_params *p,
const struct coproc_reg *r)
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
val = *vcpu_reg(vcpu, p->Rt1);
switch (p->CRm) {
case 6:
case 14:
asm volatile("mcr p15, 0, %0, c7, c14, 2" : : "r" (val));
break;
case 10:
asm volatile("mcr p15, 0, %0, c7, c10, 2" : : "r" (val));
break;
}
done:
put_cpu();
return true;
}
static bool access_vm_reg(struct kvm_vcpu *vcpu,
const struct coproc_params *p,
const struct coproc_reg *r)
{
BUG_ON(!p->is_write);
vcpu->arch.cp15[r->reg] = *vcpu_reg(vcpu, p->Rt1);
if (p->is_64bit)
vcpu->arch.cp15[r->reg + 1] = *vcpu_reg(vcpu, p->Rt2);
return true;
}
bool access_sctlr(struct kvm_vcpu *vcpu,
const struct coproc_params *p,
const struct coproc_reg *r)
{
access_vm_reg(vcpu, p, r);
if (vcpu_has_cache_enabled(vcpu)) {
vcpu->arch.hcr &= ~HCR_TVM;
stage2_flush_vm(vcpu->kvm);
}
return true;
}
static bool pm_fake(struct kvm_vcpu *vcpu,
const struct coproc_params *p,
const struct coproc_reg *r)
{
if (p->is_write)
return ignore_write(vcpu, p);
else
return read_zero(vcpu, p);
}
void kvm_register_target_coproc_table(struct kvm_coproc_target_table *table)
{
unsigned int i;
for (i = 1; i < table->num; i++)
BUG_ON(cmp_reg(&table->table[i-1],
&table->table[i]) >= 0);
target_tables[table->target] = table;
}
static const struct coproc_reg *get_target_table(unsigned target, size_t *num)
{
struct kvm_coproc_target_table *table;
table = target_tables[target];
*num = table->num;
return table->table;
}
static const struct coproc_reg *find_reg(const struct coproc_params *params,
const struct coproc_reg table[],
unsigned int num)
{
unsigned int i;
for (i = 0; i < num; i++) {
const struct coproc_reg *r = &table[i];
if (params->is_64bit != r->is_64)
continue;
if (params->CRn != r->CRn)
continue;
if (params->CRm != r->CRm)
continue;
if (params->Op1 != r->Op1)
continue;
if (params->Op2 != r->Op2)
continue;
return r;
}
return NULL;
}
static int emulate_cp15(struct kvm_vcpu *vcpu,
const struct coproc_params *params)
{
size_t num;
const struct coproc_reg *table, *r;
trace_kvm_emulate_cp15_imp(params->Op1, params->Rt1, params->CRn,
params->CRm, params->Op2, params->is_write);
table = get_target_table(vcpu->arch.target, &num);
r = find_reg(params, table, num);
if (!r)
r = find_reg(params, cp15_regs, ARRAY_SIZE(cp15_regs));
if (likely(r)) {
BUG_ON(!r->access);
if (likely(r->access(vcpu, params, r))) {
kvm_skip_instr(vcpu, kvm_vcpu_trap_il_is32bit(vcpu));
return 1;
}
} else {
kvm_err("Unsupported guest CP15 access at: %08lx\n",
*vcpu_pc(vcpu));
print_cp_instr(params);
}
kvm_inject_undefined(vcpu);
return 1;
}
int kvm_handle_cp15_64(struct kvm_vcpu *vcpu, struct kvm_run *run)
{
struct coproc_params params;
params.CRn = (kvm_vcpu_get_hsr(vcpu) >> 1) & 0xf;
params.Rt1 = (kvm_vcpu_get_hsr(vcpu) >> 5) & 0xf;
params.is_write = ((kvm_vcpu_get_hsr(vcpu) & 1) == 0);
params.is_64bit = true;
params.Op1 = (kvm_vcpu_get_hsr(vcpu) >> 16) & 0xf;
params.Op2 = 0;
params.Rt2 = (kvm_vcpu_get_hsr(vcpu) >> 10) & 0xf;
params.CRm = 0;
return emulate_cp15(vcpu, &params);
}
static void reset_coproc_regs(struct kvm_vcpu *vcpu,
const struct coproc_reg *table, size_t num)
{
unsigned long i;
for (i = 0; i < num; i++)
if (table[i].reset)
table[i].reset(vcpu, &table[i]);
}
int kvm_handle_cp15_32(struct kvm_vcpu *vcpu, struct kvm_run *run)
{
struct coproc_params params;
params.CRm = (kvm_vcpu_get_hsr(vcpu) >> 1) & 0xf;
params.Rt1 = (kvm_vcpu_get_hsr(vcpu) >> 5) & 0xf;
params.is_write = ((kvm_vcpu_get_hsr(vcpu) & 1) == 0);
params.is_64bit = false;
params.CRn = (kvm_vcpu_get_hsr(vcpu) >> 10) & 0xf;
params.Op1 = (kvm_vcpu_get_hsr(vcpu) >> 14) & 0x7;
params.Op2 = (kvm_vcpu_get_hsr(vcpu) >> 17) & 0x7;
params.Rt2 = 0;
return emulate_cp15(vcpu, &params);
}
static bool index_to_params(u64 id, struct coproc_params *params)
{
switch (id & KVM_REG_SIZE_MASK) {
case KVM_REG_SIZE_U32:
if (id & ~(KVM_REG_ARCH_MASK | KVM_REG_SIZE_MASK
| KVM_REG_ARM_COPROC_MASK
| KVM_REG_ARM_32_CRN_MASK
| KVM_REG_ARM_CRM_MASK
| KVM_REG_ARM_OPC1_MASK
| KVM_REG_ARM_32_OPC2_MASK))
return false;
params->is_64bit = false;
params->CRn = ((id & KVM_REG_ARM_32_CRN_MASK)
>> KVM_REG_ARM_32_CRN_SHIFT);
params->CRm = ((id & KVM_REG_ARM_CRM_MASK)
>> KVM_REG_ARM_CRM_SHIFT);
params->Op1 = ((id & KVM_REG_ARM_OPC1_MASK)
>> KVM_REG_ARM_OPC1_SHIFT);
params->Op2 = ((id & KVM_REG_ARM_32_OPC2_MASK)
>> KVM_REG_ARM_32_OPC2_SHIFT);
return true;
case KVM_REG_SIZE_U64:
if (id & ~(KVM_REG_ARCH_MASK | KVM_REG_SIZE_MASK
| KVM_REG_ARM_COPROC_MASK
| KVM_REG_ARM_CRM_MASK
| KVM_REG_ARM_OPC1_MASK))
return false;
params->is_64bit = true;
params->CRn = ((id & KVM_REG_ARM_CRM_MASK)
>> KVM_REG_ARM_CRM_SHIFT);
params->Op1 = ((id & KVM_REG_ARM_OPC1_MASK)
>> KVM_REG_ARM_OPC1_SHIFT);
params->Op2 = 0;
params->CRm = 0;
return true;
default:
return false;
}
}
static const struct coproc_reg *index_to_coproc_reg(struct kvm_vcpu *vcpu,
u64 id)
{
size_t num;
const struct coproc_reg *table, *r;
struct coproc_params params;
if ((id & KVM_REG_ARM_COPROC_MASK) >> KVM_REG_ARM_COPROC_SHIFT != 15)
return NULL;
if (!index_to_params(id, &params))
return NULL;
table = get_target_table(vcpu->arch.target, &num);
r = find_reg(&params, table, num);
if (!r)
r = find_reg(&params, cp15_regs, ARRAY_SIZE(cp15_regs));
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
static int get_invariant_cp15(u64 id, void __user *uaddr)
{
struct coproc_params params;
const struct coproc_reg *r;
int ret;
if (!index_to_params(id, &params))
return -ENOENT;
r = find_reg(&params, invariant_cp15, ARRAY_SIZE(invariant_cp15));
if (!r)
return -ENOENT;
ret = -ENOENT;
if (KVM_REG_SIZE(id) == 4) {
u32 val = r->val;
ret = reg_to_user(uaddr, &val, id);
} else if (KVM_REG_SIZE(id) == 8) {
ret = reg_to_user(uaddr, &r->val, id);
}
return ret;
}
static int set_invariant_cp15(u64 id, void __user *uaddr)
{
struct coproc_params params;
const struct coproc_reg *r;
int err;
u64 val;
if (!index_to_params(id, &params))
return -ENOENT;
r = find_reg(&params, invariant_cp15, ARRAY_SIZE(invariant_cp15));
if (!r)
return -ENOENT;
err = -ENOENT;
if (KVM_REG_SIZE(id) == 4) {
u32 val32;
err = reg_from_user(&val32, uaddr, id);
if (!err)
val = val32;
} else if (KVM_REG_SIZE(id) == 8) {
err = reg_from_user(&val, uaddr, id);
}
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
static u32 get_ccsidr(u32 csselr)
{
u32 ccsidr;
local_irq_disable();
asm volatile("mcr p15, 2, %0, c0, c0, 0" : : "r" (csselr));
isb();
asm volatile("mrc p15, 1, %0, c0, c0, 0" : "=r" (ccsidr));
local_irq_enable();
return ccsidr;
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
static unsigned int num_fp_regs(void)
{
if (((fmrx(MVFR0) & MVFR0_A_SIMD_MASK) >> MVFR0_A_SIMD_BIT) == 2)
return 32;
else
return 16;
}
static unsigned int num_vfp_regs(void)
{
return num_fp_regs() + ARRAY_SIZE(vfp_sysregs);
}
static int copy_vfp_regids(u64 __user *uindices)
{
unsigned int i;
const u64 u32reg = KVM_REG_ARM | KVM_REG_SIZE_U32 | KVM_REG_ARM_VFP;
const u64 u64reg = KVM_REG_ARM | KVM_REG_SIZE_U64 | KVM_REG_ARM_VFP;
for (i = 0; i < num_fp_regs(); i++) {
if (put_user((u64reg | KVM_REG_ARM_VFP_BASE_REG) + i,
uindices))
return -EFAULT;
uindices++;
}
for (i = 0; i < ARRAY_SIZE(vfp_sysregs); i++) {
if (put_user(u32reg | vfp_sysregs[i], uindices))
return -EFAULT;
uindices++;
}
return num_vfp_regs();
}
static int vfp_get_reg(const struct kvm_vcpu *vcpu, u64 id, void __user *uaddr)
{
u32 vfpid = (id & KVM_REG_ARM_VFP_MASK);
u32 val;
if (id & ~(KVM_REG_ARCH_MASK|KVM_REG_SIZE_MASK|KVM_REG_ARM_COPROC_MASK
| ((1 << KVM_REG_ARM_COPROC_SHIFT)-1)))
return -ENOENT;
if (vfpid < num_fp_regs()) {
if (KVM_REG_SIZE(id) != 8)
return -ENOENT;
return reg_to_user(uaddr, &vcpu->arch.vfp_guest.fpregs[vfpid],
id);
}
if (KVM_REG_SIZE(id) != 4)
return -ENOENT;
switch (vfpid) {
case KVM_REG_ARM_VFP_FPEXC:
return reg_to_user(uaddr, &vcpu->arch.vfp_guest.fpexc, id);
case KVM_REG_ARM_VFP_FPSCR:
return reg_to_user(uaddr, &vcpu->arch.vfp_guest.fpscr, id);
case KVM_REG_ARM_VFP_FPINST:
return reg_to_user(uaddr, &vcpu->arch.vfp_guest.fpinst, id);
case KVM_REG_ARM_VFP_FPINST2:
return reg_to_user(uaddr, &vcpu->arch.vfp_guest.fpinst2, id);
case KVM_REG_ARM_VFP_MVFR0:
val = fmrx(MVFR0);
return reg_to_user(uaddr, &val, id);
case KVM_REG_ARM_VFP_MVFR1:
val = fmrx(MVFR1);
return reg_to_user(uaddr, &val, id);
case KVM_REG_ARM_VFP_FPSID:
val = fmrx(FPSID);
return reg_to_user(uaddr, &val, id);
default:
return -ENOENT;
}
}
static int vfp_set_reg(struct kvm_vcpu *vcpu, u64 id, const void __user *uaddr)
{
u32 vfpid = (id & KVM_REG_ARM_VFP_MASK);
u32 val;
if (id & ~(KVM_REG_ARCH_MASK|KVM_REG_SIZE_MASK|KVM_REG_ARM_COPROC_MASK
| ((1 << KVM_REG_ARM_COPROC_SHIFT)-1)))
return -ENOENT;
if (vfpid < num_fp_regs()) {
if (KVM_REG_SIZE(id) != 8)
return -ENOENT;
return reg_from_user(&vcpu->arch.vfp_guest.fpregs[vfpid],
uaddr, id);
}
if (KVM_REG_SIZE(id) != 4)
return -ENOENT;
switch (vfpid) {
case KVM_REG_ARM_VFP_FPEXC:
return reg_from_user(&vcpu->arch.vfp_guest.fpexc, uaddr, id);
case KVM_REG_ARM_VFP_FPSCR:
return reg_from_user(&vcpu->arch.vfp_guest.fpscr, uaddr, id);
case KVM_REG_ARM_VFP_FPINST:
return reg_from_user(&vcpu->arch.vfp_guest.fpinst, uaddr, id);
case KVM_REG_ARM_VFP_FPINST2:
return reg_from_user(&vcpu->arch.vfp_guest.fpinst2, uaddr, id);
case KVM_REG_ARM_VFP_MVFR0:
if (reg_from_user(&val, uaddr, id))
return -EFAULT;
if (val != fmrx(MVFR0))
return -EINVAL;
return 0;
case KVM_REG_ARM_VFP_MVFR1:
if (reg_from_user(&val, uaddr, id))
return -EFAULT;
if (val != fmrx(MVFR1))
return -EINVAL;
return 0;
case KVM_REG_ARM_VFP_FPSID:
if (reg_from_user(&val, uaddr, id))
return -EFAULT;
if (val != fmrx(FPSID))
return -EINVAL;
return 0;
default:
return -ENOENT;
}
}
static unsigned int num_vfp_regs(void)
{
return 0;
}
static int copy_vfp_regids(u64 __user *uindices)
{
return 0;
}
static int vfp_get_reg(const struct kvm_vcpu *vcpu, u64 id, void __user *uaddr)
{
return -ENOENT;
}
static int vfp_set_reg(struct kvm_vcpu *vcpu, u64 id, const void __user *uaddr)
{
return -ENOENT;
}
int kvm_arm_coproc_get_reg(struct kvm_vcpu *vcpu, const struct kvm_one_reg *reg)
{
const struct coproc_reg *r;
void __user *uaddr = (void __user *)(long)reg->addr;
int ret;
if ((reg->id & KVM_REG_ARM_COPROC_MASK) == KVM_REG_ARM_DEMUX)
return demux_c15_get(reg->id, uaddr);
if ((reg->id & KVM_REG_ARM_COPROC_MASK) == KVM_REG_ARM_VFP)
return vfp_get_reg(vcpu, reg->id, uaddr);
r = index_to_coproc_reg(vcpu, reg->id);
if (!r)
return get_invariant_cp15(reg->id, uaddr);
ret = -ENOENT;
if (KVM_REG_SIZE(reg->id) == 8) {
u64 val;
val = vcpu_cp15_reg64_get(vcpu, r);
ret = reg_to_user(uaddr, &val, reg->id);
} else if (KVM_REG_SIZE(reg->id) == 4) {
ret = reg_to_user(uaddr, &vcpu->arch.cp15[r->reg], reg->id);
}
return ret;
}
int kvm_arm_coproc_set_reg(struct kvm_vcpu *vcpu, const struct kvm_one_reg *reg)
{
const struct coproc_reg *r;
void __user *uaddr = (void __user *)(long)reg->addr;
int ret;
if ((reg->id & KVM_REG_ARM_COPROC_MASK) == KVM_REG_ARM_DEMUX)
return demux_c15_set(reg->id, uaddr);
if ((reg->id & KVM_REG_ARM_COPROC_MASK) == KVM_REG_ARM_VFP)
return vfp_set_reg(vcpu, reg->id, uaddr);
r = index_to_coproc_reg(vcpu, reg->id);
if (!r)
return set_invariant_cp15(reg->id, uaddr);
ret = -ENOENT;
if (KVM_REG_SIZE(reg->id) == 8) {
u64 val;
ret = reg_from_user(&val, uaddr, reg->id);
if (!ret)
vcpu_cp15_reg64_set(vcpu, r, val);
} else if (KVM_REG_SIZE(reg->id) == 4) {
ret = reg_from_user(&vcpu->arch.cp15[r->reg], uaddr, reg->id);
}
return ret;
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
static u64 cp15_to_index(const struct coproc_reg *reg)
{
u64 val = KVM_REG_ARM | (15 << KVM_REG_ARM_COPROC_SHIFT);
if (reg->is_64) {
val |= KVM_REG_SIZE_U64;
val |= (reg->Op1 << KVM_REG_ARM_OPC1_SHIFT);
val |= (reg->CRn << KVM_REG_ARM_CRM_SHIFT);
} else {
val |= KVM_REG_SIZE_U32;
val |= (reg->Op1 << KVM_REG_ARM_OPC1_SHIFT);
val |= (reg->Op2 << KVM_REG_ARM_32_OPC2_SHIFT);
val |= (reg->CRm << KVM_REG_ARM_CRM_SHIFT);
val |= (reg->CRn << KVM_REG_ARM_32_CRN_SHIFT);
}
return val;
}
static bool copy_reg_to_user(const struct coproc_reg *reg, u64 __user **uind)
{
if (!*uind)
return true;
if (put_user(cp15_to_index(reg), *uind))
return false;
(*uind)++;
return true;
}
static int walk_cp15(struct kvm_vcpu *vcpu, u64 __user *uind)
{
const struct coproc_reg *i1, *i2, *end1, *end2;
unsigned int total = 0;
size_t num;
i1 = get_target_table(vcpu->arch.target, &num);
end1 = i1 + num;
i2 = cp15_regs;
end2 = cp15_regs + ARRAY_SIZE(cp15_regs);
BUG_ON(i1 == end1 || i2 == end2);
while (i1 || i2) {
int cmp = cmp_reg(i1, i2);
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
unsigned long kvm_arm_num_coproc_regs(struct kvm_vcpu *vcpu)
{
return ARRAY_SIZE(invariant_cp15)
+ num_demux_regs()
+ num_vfp_regs()
+ walk_cp15(vcpu, (u64 __user *)NULL);
}
int kvm_arm_copy_coproc_indices(struct kvm_vcpu *vcpu, u64 __user *uindices)
{
unsigned int i;
int err;
for (i = 0; i < ARRAY_SIZE(invariant_cp15); i++) {
if (put_user(cp15_to_index(&invariant_cp15[i]), uindices))
return -EFAULT;
uindices++;
}
err = walk_cp15(vcpu, uindices);
if (err < 0)
return err;
uindices += err;
err = copy_vfp_regids(uindices);
if (err < 0)
return err;
uindices += err;
return write_demux_regids(uindices);
}
void kvm_coproc_table_init(void)
{
unsigned int i;
for (i = 1; i < ARRAY_SIZE(cp15_regs); i++)
BUG_ON(cmp_reg(&cp15_regs[i-1], &cp15_regs[i]) >= 0);
for (i = 0; i < ARRAY_SIZE(invariant_cp15); i++)
invariant_cp15[i].reset(NULL, &invariant_cp15[i]);
asm volatile("mrc p15, 1, %0, c0, c0, 1" : "=r" (cache_levels));
for (i = 0; i < 7; i++)
if (((cache_levels >> (i*3)) & 7) == 0)
break;
cache_levels &= (1 << (i*3))-1;
}
void kvm_reset_coprocs(struct kvm_vcpu *vcpu)
{
size_t num;
const struct coproc_reg *table;
memset(vcpu->arch.cp15, 0x42, sizeof(vcpu->arch.cp15));
reset_coproc_regs(vcpu, cp15_regs, ARRAY_SIZE(cp15_regs));
table = get_target_table(vcpu->arch.target, &num);
reset_coproc_regs(vcpu, table, num);
for (num = 1; num < NR_CP15_REGS; num++)
if (vcpu->arch.cp15[num] == 0x42424242)
panic("Didn't reset vcpu->arch.cp15[%zi]", num);
}
