int kvm_arch_vcpu_setup(struct kvm_vcpu *vcpu)
{
return 0;
}
static u64 core_reg_offset_from_id(u64 id)
{
return id & ~(KVM_REG_ARCH_MASK | KVM_REG_SIZE_MASK | KVM_REG_ARM_CORE);
}
static int get_core_reg(struct kvm_vcpu *vcpu, const struct kvm_one_reg *reg)
{
u32 __user *uaddr = (u32 __user *)(long)reg->addr;
struct kvm_regs *regs = &vcpu->arch.regs;
u64 off;
if (KVM_REG_SIZE(reg->id) != 4)
return -ENOENT;
off = core_reg_offset_from_id(reg->id);
if (off >= sizeof(*regs) / KVM_REG_SIZE(reg->id))
return -ENOENT;
return put_user(((u32 *)regs)[off], uaddr);
}
static int set_core_reg(struct kvm_vcpu *vcpu, const struct kvm_one_reg *reg)
{
u32 __user *uaddr = (u32 __user *)(long)reg->addr;
struct kvm_regs *regs = &vcpu->arch.regs;
u64 off, val;
if (KVM_REG_SIZE(reg->id) != 4)
return -ENOENT;
off = core_reg_offset_from_id(reg->id);
if (off >= sizeof(*regs) / KVM_REG_SIZE(reg->id))
return -ENOENT;
if (get_user(val, uaddr) != 0)
return -EFAULT;
if (off == KVM_REG_ARM_CORE_REG(usr_regs.ARM_cpsr)) {
unsigned long mode = val & MODE_MASK;
switch (mode) {
case USR_MODE:
case FIQ_MODE:
case IRQ_MODE:
case SVC_MODE:
case ABT_MODE:
case UND_MODE:
break;
default:
return -EINVAL;
}
}
((u32 *)regs)[off] = val;
return 0;
}
int kvm_arch_vcpu_ioctl_get_regs(struct kvm_vcpu *vcpu, struct kvm_regs *regs)
{
return -EINVAL;
}
int kvm_arch_vcpu_ioctl_set_regs(struct kvm_vcpu *vcpu, struct kvm_regs *regs)
{
return -EINVAL;
}
static unsigned long num_core_regs(void)
{
return sizeof(struct kvm_regs) / sizeof(u32);
}
unsigned long kvm_arm_num_regs(struct kvm_vcpu *vcpu)
{
return num_core_regs() + kvm_arm_num_coproc_regs(vcpu);
}
int kvm_arm_copy_reg_indices(struct kvm_vcpu *vcpu, u64 __user *uindices)
{
unsigned int i;
const u64 core_reg = KVM_REG_ARM | KVM_REG_SIZE_U32 | KVM_REG_ARM_CORE;
for (i = 0; i < sizeof(struct kvm_regs)/sizeof(u32); i++) {
if (put_user(core_reg | i, uindices))
return -EFAULT;
uindices++;
}
return kvm_arm_copy_coproc_indices(vcpu, uindices);
}
int kvm_arm_get_reg(struct kvm_vcpu *vcpu, const struct kvm_one_reg *reg)
{
if ((reg->id & ~KVM_REG_SIZE_MASK) >> 32 != KVM_REG_ARM >> 32)
return -EINVAL;
if ((reg->id & KVM_REG_ARM_COPROC_MASK) == KVM_REG_ARM_CORE)
return get_core_reg(vcpu, reg);
return kvm_arm_coproc_get_reg(vcpu, reg);
}
int kvm_arm_set_reg(struct kvm_vcpu *vcpu, const struct kvm_one_reg *reg)
{
if ((reg->id & ~KVM_REG_SIZE_MASK) >> 32 != KVM_REG_ARM >> 32)
return -EINVAL;
if ((reg->id & KVM_REG_ARM_COPROC_MASK) == KVM_REG_ARM_CORE)
return set_core_reg(vcpu, reg);
return kvm_arm_coproc_set_reg(vcpu, reg);
}
int kvm_arch_vcpu_ioctl_get_sregs(struct kvm_vcpu *vcpu,
struct kvm_sregs *sregs)
{
return -EINVAL;
}
int kvm_arch_vcpu_ioctl_set_sregs(struct kvm_vcpu *vcpu,
struct kvm_sregs *sregs)
{
return -EINVAL;
}
int __attribute_const__ kvm_target_cpu(void)
{
unsigned long implementor = read_cpuid_implementor();
unsigned long part_number = read_cpuid_part_number();
if (implementor != ARM_CPU_IMP_ARM)
return -EINVAL;
switch (part_number) {
case ARM_CPU_PART_CORTEX_A15:
return KVM_ARM_TARGET_CORTEX_A15;
default:
return -EINVAL;
}
}
int kvm_vcpu_set_target(struct kvm_vcpu *vcpu,
const struct kvm_vcpu_init *init)
{
unsigned int i;
if (init->target != kvm_target_cpu())
return -EINVAL;
vcpu->arch.target = init->target;
bitmap_zero(vcpu->arch.features, KVM_VCPU_MAX_FEATURES);
for (i = 0; i < sizeof(init->features) * 8; i++) {
if (test_bit(i, (void *)init->features)) {
if (i >= KVM_VCPU_MAX_FEATURES)
return -ENOENT;
set_bit(i, vcpu->arch.features);
}
}
return kvm_reset_vcpu(vcpu);
}
int kvm_arch_vcpu_ioctl_get_fpu(struct kvm_vcpu *vcpu, struct kvm_fpu *fpu)
{
return -EINVAL;
}
int kvm_arch_vcpu_ioctl_set_fpu(struct kvm_vcpu *vcpu, struct kvm_fpu *fpu)
{
return -EINVAL;
}
int kvm_arch_vcpu_ioctl_translate(struct kvm_vcpu *vcpu,
struct kvm_translation *tr)
{
return -EINVAL;
}
