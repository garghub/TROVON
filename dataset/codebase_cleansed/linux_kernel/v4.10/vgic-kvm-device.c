int vgic_check_ioaddr(struct kvm *kvm, phys_addr_t *ioaddr,
phys_addr_t addr, phys_addr_t alignment)
{
if (addr & ~KVM_PHYS_MASK)
return -E2BIG;
if (!IS_ALIGNED(addr, alignment))
return -EINVAL;
if (!IS_VGIC_ADDR_UNDEF(*ioaddr))
return -EEXIST;
return 0;
}
int kvm_vgic_addr(struct kvm *kvm, unsigned long type, u64 *addr, bool write)
{
int r = 0;
struct vgic_dist *vgic = &kvm->arch.vgic;
int type_needed;
phys_addr_t *addr_ptr, alignment;
mutex_lock(&kvm->lock);
switch (type) {
case KVM_VGIC_V2_ADDR_TYPE_DIST:
type_needed = KVM_DEV_TYPE_ARM_VGIC_V2;
addr_ptr = &vgic->vgic_dist_base;
alignment = SZ_4K;
break;
case KVM_VGIC_V2_ADDR_TYPE_CPU:
type_needed = KVM_DEV_TYPE_ARM_VGIC_V2;
addr_ptr = &vgic->vgic_cpu_base;
alignment = SZ_4K;
break;
case KVM_VGIC_V3_ADDR_TYPE_DIST:
type_needed = KVM_DEV_TYPE_ARM_VGIC_V3;
addr_ptr = &vgic->vgic_dist_base;
alignment = SZ_64K;
break;
case KVM_VGIC_V3_ADDR_TYPE_REDIST:
type_needed = KVM_DEV_TYPE_ARM_VGIC_V3;
addr_ptr = &vgic->vgic_redist_base;
alignment = SZ_64K;
break;
default:
r = -ENODEV;
goto out;
}
if (vgic->vgic_model != type_needed) {
r = -ENODEV;
goto out;
}
if (write) {
r = vgic_check_ioaddr(kvm, addr_ptr, *addr, alignment);
if (!r)
*addr_ptr = *addr;
} else {
*addr = *addr_ptr;
}
out:
mutex_unlock(&kvm->lock);
return r;
}
static int vgic_set_common_attr(struct kvm_device *dev,
struct kvm_device_attr *attr)
{
int r;
switch (attr->group) {
case KVM_DEV_ARM_VGIC_GRP_ADDR: {
u64 __user *uaddr = (u64 __user *)(long)attr->addr;
u64 addr;
unsigned long type = (unsigned long)attr->attr;
if (copy_from_user(&addr, uaddr, sizeof(addr)))
return -EFAULT;
r = kvm_vgic_addr(dev->kvm, type, &addr, true);
return (r == -ENODEV) ? -ENXIO : r;
}
case KVM_DEV_ARM_VGIC_GRP_NR_IRQS: {
u32 __user *uaddr = (u32 __user *)(long)attr->addr;
u32 val;
int ret = 0;
if (get_user(val, uaddr))
return -EFAULT;
if (val < (VGIC_NR_PRIVATE_IRQS + 32) ||
val > VGIC_MAX_RESERVED ||
(val & 31))
return -EINVAL;
mutex_lock(&dev->kvm->lock);
if (vgic_ready(dev->kvm) || dev->kvm->arch.vgic.nr_spis)
ret = -EBUSY;
else
dev->kvm->arch.vgic.nr_spis =
val - VGIC_NR_PRIVATE_IRQS;
mutex_unlock(&dev->kvm->lock);
return ret;
}
case KVM_DEV_ARM_VGIC_GRP_CTRL: {
switch (attr->attr) {
case KVM_DEV_ARM_VGIC_CTRL_INIT:
mutex_lock(&dev->kvm->lock);
r = vgic_init(dev->kvm);
mutex_unlock(&dev->kvm->lock);
return r;
}
break;
}
}
return -ENXIO;
}
static int vgic_get_common_attr(struct kvm_device *dev,
struct kvm_device_attr *attr)
{
int r = -ENXIO;
switch (attr->group) {
case KVM_DEV_ARM_VGIC_GRP_ADDR: {
u64 __user *uaddr = (u64 __user *)(long)attr->addr;
u64 addr;
unsigned long type = (unsigned long)attr->attr;
r = kvm_vgic_addr(dev->kvm, type, &addr, false);
if (r)
return (r == -ENODEV) ? -ENXIO : r;
if (copy_to_user(uaddr, &addr, sizeof(addr)))
return -EFAULT;
break;
}
case KVM_DEV_ARM_VGIC_GRP_NR_IRQS: {
u32 __user *uaddr = (u32 __user *)(long)attr->addr;
r = put_user(dev->kvm->arch.vgic.nr_spis +
VGIC_NR_PRIVATE_IRQS, uaddr);
break;
}
}
return r;
}
static int vgic_create(struct kvm_device *dev, u32 type)
{
return kvm_vgic_create(dev->kvm, type);
}
static void vgic_destroy(struct kvm_device *dev)
{
kfree(dev);
}
int kvm_register_vgic_device(unsigned long type)
{
int ret = -ENODEV;
switch (type) {
case KVM_DEV_TYPE_ARM_VGIC_V2:
ret = kvm_register_device_ops(&kvm_arm_vgic_v2_ops,
KVM_DEV_TYPE_ARM_VGIC_V2);
break;
case KVM_DEV_TYPE_ARM_VGIC_V3:
ret = kvm_register_device_ops(&kvm_arm_vgic_v3_ops,
KVM_DEV_TYPE_ARM_VGIC_V3);
if (ret)
break;
ret = kvm_vgic_register_its_device();
break;
}
return ret;
}
static int parse_vgic_v2_attr(struct kvm_device *dev,
struct kvm_device_attr *attr,
struct vgic_reg_attr *reg_attr)
{
int cpuid;
cpuid = (attr->attr & KVM_DEV_ARM_VGIC_CPUID_MASK) >>
KVM_DEV_ARM_VGIC_CPUID_SHIFT;
if (cpuid >= atomic_read(&dev->kvm->online_vcpus))
return -EINVAL;
reg_attr->vcpu = kvm_get_vcpu(dev->kvm, cpuid);
reg_attr->addr = attr->attr & KVM_DEV_ARM_VGIC_OFFSET_MASK;
return 0;
}
static void unlock_vcpus(struct kvm *kvm, int vcpu_lock_idx)
{
struct kvm_vcpu *tmp_vcpu;
for (; vcpu_lock_idx >= 0; vcpu_lock_idx--) {
tmp_vcpu = kvm_get_vcpu(kvm, vcpu_lock_idx);
mutex_unlock(&tmp_vcpu->mutex);
}
}
static void unlock_all_vcpus(struct kvm *kvm)
{
unlock_vcpus(kvm, atomic_read(&kvm->online_vcpus) - 1);
}
static bool lock_all_vcpus(struct kvm *kvm)
{
struct kvm_vcpu *tmp_vcpu;
int c;
kvm_for_each_vcpu(c, tmp_vcpu, kvm) {
if (!mutex_trylock(&tmp_vcpu->mutex)) {
unlock_vcpus(kvm, c - 1);
return false;
}
}
return true;
}
static int vgic_attr_regs_access_v2(struct kvm_device *dev,
struct kvm_device_attr *attr,
u32 *reg, bool is_write)
{
struct vgic_reg_attr reg_attr;
gpa_t addr;
struct kvm_vcpu *vcpu;
int ret;
ret = parse_vgic_v2_attr(dev, attr, &reg_attr);
if (ret)
return ret;
vcpu = reg_attr.vcpu;
addr = reg_attr.addr;
mutex_lock(&dev->kvm->lock);
ret = vgic_init(dev->kvm);
if (ret)
goto out;
if (!lock_all_vcpus(dev->kvm)) {
ret = -EBUSY;
goto out;
}
switch (attr->group) {
case KVM_DEV_ARM_VGIC_GRP_CPU_REGS:
ret = vgic_v2_cpuif_uaccess(vcpu, is_write, addr, reg);
break;
case KVM_DEV_ARM_VGIC_GRP_DIST_REGS:
ret = vgic_v2_dist_uaccess(vcpu, is_write, addr, reg);
break;
default:
ret = -EINVAL;
break;
}
unlock_all_vcpus(dev->kvm);
out:
mutex_unlock(&dev->kvm->lock);
return ret;
}
static int vgic_v2_set_attr(struct kvm_device *dev,
struct kvm_device_attr *attr)
{
int ret;
ret = vgic_set_common_attr(dev, attr);
if (ret != -ENXIO)
return ret;
switch (attr->group) {
case KVM_DEV_ARM_VGIC_GRP_DIST_REGS:
case KVM_DEV_ARM_VGIC_GRP_CPU_REGS: {
u32 __user *uaddr = (u32 __user *)(long)attr->addr;
u32 reg;
if (get_user(reg, uaddr))
return -EFAULT;
return vgic_attr_regs_access_v2(dev, attr, &reg, true);
}
}
return -ENXIO;
}
static int vgic_v2_get_attr(struct kvm_device *dev,
struct kvm_device_attr *attr)
{
int ret;
ret = vgic_get_common_attr(dev, attr);
if (ret != -ENXIO)
return ret;
switch (attr->group) {
case KVM_DEV_ARM_VGIC_GRP_DIST_REGS:
case KVM_DEV_ARM_VGIC_GRP_CPU_REGS: {
u32 __user *uaddr = (u32 __user *)(long)attr->addr;
u32 reg = 0;
ret = vgic_attr_regs_access_v2(dev, attr, &reg, false);
if (ret)
return ret;
return put_user(reg, uaddr);
}
}
return -ENXIO;
}
static int vgic_v2_has_attr(struct kvm_device *dev,
struct kvm_device_attr *attr)
{
switch (attr->group) {
case KVM_DEV_ARM_VGIC_GRP_ADDR:
switch (attr->attr) {
case KVM_VGIC_V2_ADDR_TYPE_DIST:
case KVM_VGIC_V2_ADDR_TYPE_CPU:
return 0;
}
break;
case KVM_DEV_ARM_VGIC_GRP_DIST_REGS:
case KVM_DEV_ARM_VGIC_GRP_CPU_REGS:
return vgic_v2_has_attr_regs(dev, attr);
case KVM_DEV_ARM_VGIC_GRP_NR_IRQS:
return 0;
case KVM_DEV_ARM_VGIC_GRP_CTRL:
switch (attr->attr) {
case KVM_DEV_ARM_VGIC_CTRL_INIT:
return 0;
}
}
return -ENXIO;
}
static int vgic_v3_set_attr(struct kvm_device *dev,
struct kvm_device_attr *attr)
{
return vgic_set_common_attr(dev, attr);
}
static int vgic_v3_get_attr(struct kvm_device *dev,
struct kvm_device_attr *attr)
{
return vgic_get_common_attr(dev, attr);
}
static int vgic_v3_has_attr(struct kvm_device *dev,
struct kvm_device_attr *attr)
{
switch (attr->group) {
case KVM_DEV_ARM_VGIC_GRP_ADDR:
switch (attr->attr) {
case KVM_VGIC_V3_ADDR_TYPE_DIST:
case KVM_VGIC_V3_ADDR_TYPE_REDIST:
return 0;
}
break;
case KVM_DEV_ARM_VGIC_GRP_NR_IRQS:
return 0;
case KVM_DEV_ARM_VGIC_GRP_CTRL:
switch (attr->attr) {
case KVM_DEV_ARM_VGIC_CTRL_INIT:
return 0;
}
}
return -ENXIO;
}
