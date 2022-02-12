static u8 *vgic_get_sgi_sources(struct vgic_dist *dist, int vcpu_id, int sgi)
{
return dist->irq_sgi_sources + vcpu_id * VGIC_NR_SGIS + sgi;
}
static bool handle_mmio_misc(struct kvm_vcpu *vcpu,
struct kvm_exit_mmio *mmio, phys_addr_t offset)
{
u32 reg;
u32 word_offset = offset & 3;
switch (offset & ~3) {
case 0:
reg = vcpu->kvm->arch.vgic.enabled;
vgic_reg_access(mmio, &reg, word_offset,
ACCESS_READ_VALUE | ACCESS_WRITE_VALUE);
if (mmio->is_write) {
vcpu->kvm->arch.vgic.enabled = reg & 1;
vgic_update_state(vcpu->kvm);
return true;
}
break;
case 4:
reg = (atomic_read(&vcpu->kvm->online_vcpus) - 1) << 5;
reg |= (vcpu->kvm->arch.vgic.nr_irqs >> 5) - 1;
vgic_reg_access(mmio, &reg, word_offset,
ACCESS_READ_VALUE | ACCESS_WRITE_IGNORED);
break;
case 8:
reg = (PRODUCT_ID_KVM << 24) | (IMPLEMENTER_ARM << 0);
vgic_reg_access(mmio, &reg, word_offset,
ACCESS_READ_VALUE | ACCESS_WRITE_IGNORED);
break;
}
return false;
}
static bool handle_mmio_set_enable_reg(struct kvm_vcpu *vcpu,
struct kvm_exit_mmio *mmio,
phys_addr_t offset)
{
return vgic_handle_enable_reg(vcpu->kvm, mmio, offset,
vcpu->vcpu_id, ACCESS_WRITE_SETBIT);
}
static bool handle_mmio_clear_enable_reg(struct kvm_vcpu *vcpu,
struct kvm_exit_mmio *mmio,
phys_addr_t offset)
{
return vgic_handle_enable_reg(vcpu->kvm, mmio, offset,
vcpu->vcpu_id, ACCESS_WRITE_CLEARBIT);
}
static bool handle_mmio_set_pending_reg(struct kvm_vcpu *vcpu,
struct kvm_exit_mmio *mmio,
phys_addr_t offset)
{
return vgic_handle_set_pending_reg(vcpu->kvm, mmio, offset,
vcpu->vcpu_id);
}
static bool handle_mmio_clear_pending_reg(struct kvm_vcpu *vcpu,
struct kvm_exit_mmio *mmio,
phys_addr_t offset)
{
return vgic_handle_clear_pending_reg(vcpu->kvm, mmio, offset,
vcpu->vcpu_id);
}
static bool handle_mmio_priority_reg(struct kvm_vcpu *vcpu,
struct kvm_exit_mmio *mmio,
phys_addr_t offset)
{
u32 *reg = vgic_bytemap_get_reg(&vcpu->kvm->arch.vgic.irq_priority,
vcpu->vcpu_id, offset);
vgic_reg_access(mmio, reg, offset,
ACCESS_READ_VALUE | ACCESS_WRITE_VALUE);
return false;
}
static u32 vgic_get_target_reg(struct kvm *kvm, int irq)
{
struct vgic_dist *dist = &kvm->arch.vgic;
int i;
u32 val = 0;
irq -= VGIC_NR_PRIVATE_IRQS;
for (i = 0; i < GICD_IRQS_PER_ITARGETSR; i++)
val |= 1 << (dist->irq_spi_cpu[irq + i] + i * 8);
return val;
}
static void vgic_set_target_reg(struct kvm *kvm, u32 val, int irq)
{
struct vgic_dist *dist = &kvm->arch.vgic;
struct kvm_vcpu *vcpu;
int i, c;
unsigned long *bmap;
u32 target;
irq -= VGIC_NR_PRIVATE_IRQS;
for (i = 0; i < GICD_IRQS_PER_ITARGETSR; i++) {
int shift = i * GICD_CPUTARGETS_BITS;
target = ffs((val >> shift) & 0xffU);
target = target ? (target - 1) : 0;
dist->irq_spi_cpu[irq + i] = target;
kvm_for_each_vcpu(c, vcpu, kvm) {
bmap = vgic_bitmap_get_shared_map(&dist->irq_spi_target[c]);
if (c == target)
set_bit(irq + i, bmap);
else
clear_bit(irq + i, bmap);
}
}
}
static bool handle_mmio_target_reg(struct kvm_vcpu *vcpu,
struct kvm_exit_mmio *mmio,
phys_addr_t offset)
{
u32 reg;
if (offset < 32) {
u32 roreg;
roreg = 1 << vcpu->vcpu_id;
roreg |= roreg << 8;
roreg |= roreg << 16;
vgic_reg_access(mmio, &roreg, offset,
ACCESS_READ_VALUE | ACCESS_WRITE_IGNORED);
return false;
}
reg = vgic_get_target_reg(vcpu->kvm, offset & ~3U);
vgic_reg_access(mmio, &reg, offset,
ACCESS_READ_VALUE | ACCESS_WRITE_VALUE);
if (mmio->is_write) {
vgic_set_target_reg(vcpu->kvm, reg, offset & ~3U);
vgic_update_state(vcpu->kvm);
return true;
}
return false;
}
static bool handle_mmio_cfg_reg(struct kvm_vcpu *vcpu,
struct kvm_exit_mmio *mmio, phys_addr_t offset)
{
u32 *reg;
reg = vgic_bitmap_get_reg(&vcpu->kvm->arch.vgic.irq_cfg,
vcpu->vcpu_id, offset >> 1);
return vgic_handle_cfg_reg(reg, mmio, offset);
}
static bool handle_mmio_sgi_reg(struct kvm_vcpu *vcpu,
struct kvm_exit_mmio *mmio, phys_addr_t offset)
{
u32 reg;
vgic_reg_access(mmio, &reg, offset,
ACCESS_READ_RAZ | ACCESS_WRITE_VALUE);
if (mmio->is_write) {
vgic_dispatch_sgi(vcpu, reg);
vgic_update_state(vcpu->kvm);
return true;
}
return false;
}
static bool read_set_clear_sgi_pend_reg(struct kvm_vcpu *vcpu,
struct kvm_exit_mmio *mmio,
phys_addr_t offset)
{
struct vgic_dist *dist = &vcpu->kvm->arch.vgic;
int sgi;
int min_sgi = (offset & ~0x3);
int max_sgi = min_sgi + 3;
int vcpu_id = vcpu->vcpu_id;
u32 reg = 0;
for (sgi = min_sgi; sgi <= max_sgi; sgi++) {
u8 sources = *vgic_get_sgi_sources(dist, vcpu_id, sgi);
reg |= ((u32)sources) << (8 * (sgi - min_sgi));
}
mmio_data_write(mmio, ~0, reg);
return false;
}
static bool write_set_clear_sgi_pend_reg(struct kvm_vcpu *vcpu,
struct kvm_exit_mmio *mmio,
phys_addr_t offset, bool set)
{
struct vgic_dist *dist = &vcpu->kvm->arch.vgic;
int sgi;
int min_sgi = (offset & ~0x3);
int max_sgi = min_sgi + 3;
int vcpu_id = vcpu->vcpu_id;
u32 reg;
bool updated = false;
reg = mmio_data_read(mmio, ~0);
for (sgi = min_sgi; sgi <= max_sgi; sgi++) {
u8 mask = reg >> (8 * (sgi - min_sgi));
u8 *src = vgic_get_sgi_sources(dist, vcpu_id, sgi);
if (set) {
if ((*src & mask) != mask)
updated = true;
*src |= mask;
} else {
if (*src & mask)
updated = true;
*src &= ~mask;
}
}
if (updated)
vgic_update_state(vcpu->kvm);
return updated;
}
static bool handle_mmio_sgi_set(struct kvm_vcpu *vcpu,
struct kvm_exit_mmio *mmio,
phys_addr_t offset)
{
if (!mmio->is_write)
return read_set_clear_sgi_pend_reg(vcpu, mmio, offset);
else
return write_set_clear_sgi_pend_reg(vcpu, mmio, offset, true);
}
static bool handle_mmio_sgi_clear(struct kvm_vcpu *vcpu,
struct kvm_exit_mmio *mmio,
phys_addr_t offset)
{
if (!mmio->is_write)
return read_set_clear_sgi_pend_reg(vcpu, mmio, offset);
else
return write_set_clear_sgi_pend_reg(vcpu, mmio, offset, false);
}
static bool vgic_v2_handle_mmio(struct kvm_vcpu *vcpu, struct kvm_run *run,
struct kvm_exit_mmio *mmio)
{
unsigned long base = vcpu->kvm->arch.vgic.vgic_dist_base;
if (!is_in_range(mmio->phys_addr, mmio->len, base,
KVM_VGIC_V2_DIST_SIZE))
return false;
if (mmio->len > 4) {
kvm_inject_dabt(vcpu, mmio->phys_addr);
return true;
}
return vgic_handle_mmio_range(vcpu, run, mmio, vgic_dist_ranges, base);
}
static void vgic_dispatch_sgi(struct kvm_vcpu *vcpu, u32 reg)
{
struct kvm *kvm = vcpu->kvm;
struct vgic_dist *dist = &kvm->arch.vgic;
int nrcpus = atomic_read(&kvm->online_vcpus);
u8 target_cpus;
int sgi, mode, c, vcpu_id;
vcpu_id = vcpu->vcpu_id;
sgi = reg & 0xf;
target_cpus = (reg >> 16) & 0xff;
mode = (reg >> 24) & 3;
switch (mode) {
case 0:
if (!target_cpus)
return;
break;
case 1:
target_cpus = ((1 << nrcpus) - 1) & ~(1 << vcpu_id) & 0xff;
break;
case 2:
target_cpus = 1 << vcpu_id;
break;
}
kvm_for_each_vcpu(c, vcpu, kvm) {
if (target_cpus & 1) {
vgic_dist_irq_set_pending(vcpu, sgi);
*vgic_get_sgi_sources(dist, c, sgi) |= 1 << vcpu_id;
kvm_debug("SGI%d from CPU%d to CPU%d\n",
sgi, vcpu_id, c);
}
target_cpus >>= 1;
}
}
static bool vgic_v2_queue_sgi(struct kvm_vcpu *vcpu, int irq)
{
struct vgic_dist *dist = &vcpu->kvm->arch.vgic;
unsigned long sources;
int vcpu_id = vcpu->vcpu_id;
int c;
sources = *vgic_get_sgi_sources(dist, vcpu_id, irq);
for_each_set_bit(c, &sources, dist->nr_cpus) {
if (vgic_queue_irq(vcpu, c, irq))
clear_bit(c, &sources);
}
*vgic_get_sgi_sources(dist, vcpu_id, irq) = sources;
if (!sources) {
vgic_dist_irq_clear_pending(vcpu, irq);
vgic_cpu_irq_clear(vcpu, irq);
return true;
}
return false;
}
static int vgic_v2_map_resources(struct kvm *kvm,
const struct vgic_params *params)
{
int ret = 0;
if (!irqchip_in_kernel(kvm))
return 0;
mutex_lock(&kvm->lock);
if (vgic_ready(kvm))
goto out;
if (IS_VGIC_ADDR_UNDEF(kvm->arch.vgic.vgic_dist_base) ||
IS_VGIC_ADDR_UNDEF(kvm->arch.vgic.vgic_cpu_base)) {
kvm_err("Need to set vgic cpu and dist addresses first\n");
ret = -ENXIO;
goto out;
}
ret = vgic_init(kvm);
if (ret) {
kvm_err("Unable to allocate maps\n");
goto out;
}
ret = kvm_phys_addr_ioremap(kvm, kvm->arch.vgic.vgic_cpu_base,
params->vcpu_base, KVM_VGIC_V2_CPU_SIZE,
true);
if (ret) {
kvm_err("Unable to remap VGIC CPU to VCPU\n");
goto out;
}
kvm->arch.vgic.ready = true;
out:
if (ret)
kvm_vgic_destroy(kvm);
mutex_unlock(&kvm->lock);
return ret;
}
static void vgic_v2_add_sgi_source(struct kvm_vcpu *vcpu, int irq, int source)
{
struct vgic_dist *dist = &vcpu->kvm->arch.vgic;
*vgic_get_sgi_sources(dist, vcpu->vcpu_id, irq) |= 1 << source;
}
static int vgic_v2_init_model(struct kvm *kvm)
{
int i;
for (i = VGIC_NR_PRIVATE_IRQS; i < kvm->arch.vgic.nr_irqs; i += 4)
vgic_set_target_reg(kvm, 0, i);
return 0;
}
void vgic_v2_init_emulation(struct kvm *kvm)
{
struct vgic_dist *dist = &kvm->arch.vgic;
dist->vm_ops.handle_mmio = vgic_v2_handle_mmio;
dist->vm_ops.queue_sgi = vgic_v2_queue_sgi;
dist->vm_ops.add_sgi_source = vgic_v2_add_sgi_source;
dist->vm_ops.init_model = vgic_v2_init_model;
dist->vm_ops.map_resources = vgic_v2_map_resources;
kvm->arch.max_vcpus = VGIC_V2_MAX_CPUS;
}
static bool handle_cpu_mmio_misc(struct kvm_vcpu *vcpu,
struct kvm_exit_mmio *mmio, phys_addr_t offset)
{
bool updated = false;
struct vgic_vmcr vmcr;
u32 *vmcr_field;
u32 reg;
vgic_get_vmcr(vcpu, &vmcr);
switch (offset & ~0x3) {
case GIC_CPU_CTRL:
vmcr_field = &vmcr.ctlr;
break;
case GIC_CPU_PRIMASK:
vmcr_field = &vmcr.pmr;
break;
case GIC_CPU_BINPOINT:
vmcr_field = &vmcr.bpr;
break;
case GIC_CPU_ALIAS_BINPOINT:
vmcr_field = &vmcr.abpr;
break;
default:
BUG();
}
if (!mmio->is_write) {
reg = *vmcr_field;
mmio_data_write(mmio, ~0, reg);
} else {
reg = mmio_data_read(mmio, ~0);
if (reg != *vmcr_field) {
*vmcr_field = reg;
vgic_set_vmcr(vcpu, &vmcr);
updated = true;
}
}
return updated;
}
static bool handle_mmio_abpr(struct kvm_vcpu *vcpu,
struct kvm_exit_mmio *mmio, phys_addr_t offset)
{
return handle_cpu_mmio_misc(vcpu, mmio, GIC_CPU_ALIAS_BINPOINT);
}
static bool handle_cpu_mmio_ident(struct kvm_vcpu *vcpu,
struct kvm_exit_mmio *mmio,
phys_addr_t offset)
{
u32 reg;
if (mmio->is_write)
return false;
reg = (PRODUCT_ID_KVM << 20) |
(GICC_ARCH_VERSION_V2 << 16) |
(IMPLEMENTER_ARM << 0);
mmio_data_write(mmio, ~0, reg);
return false;
}
static int vgic_attr_regs_access(struct kvm_device *dev,
struct kvm_device_attr *attr,
u32 *reg, bool is_write)
{
const struct kvm_mmio_range *r = NULL, *ranges;
phys_addr_t offset;
int ret, cpuid, c;
struct kvm_vcpu *vcpu, *tmp_vcpu;
struct vgic_dist *vgic;
struct kvm_exit_mmio mmio;
offset = attr->attr & KVM_DEV_ARM_VGIC_OFFSET_MASK;
cpuid = (attr->attr & KVM_DEV_ARM_VGIC_CPUID_MASK) >>
KVM_DEV_ARM_VGIC_CPUID_SHIFT;
mutex_lock(&dev->kvm->lock);
ret = vgic_init(dev->kvm);
if (ret)
goto out;
if (cpuid >= atomic_read(&dev->kvm->online_vcpus)) {
ret = -EINVAL;
goto out;
}
vcpu = kvm_get_vcpu(dev->kvm, cpuid);
vgic = &dev->kvm->arch.vgic;
mmio.len = 4;
mmio.is_write = is_write;
if (is_write)
mmio_data_write(&mmio, ~0, *reg);
switch (attr->group) {
case KVM_DEV_ARM_VGIC_GRP_DIST_REGS:
mmio.phys_addr = vgic->vgic_dist_base + offset;
ranges = vgic_dist_ranges;
break;
case KVM_DEV_ARM_VGIC_GRP_CPU_REGS:
mmio.phys_addr = vgic->vgic_cpu_base + offset;
ranges = vgic_cpu_ranges;
break;
default:
BUG();
}
r = vgic_find_range(ranges, &mmio, offset);
if (unlikely(!r || !r->handle_mmio)) {
ret = -ENXIO;
goto out;
}
spin_lock(&vgic->lock);
kvm_for_each_vcpu(c, tmp_vcpu, dev->kvm) {
if (unlikely(tmp_vcpu->cpu != -1)) {
ret = -EBUSY;
goto out_vgic_unlock;
}
}
kvm_for_each_vcpu(c, tmp_vcpu, dev->kvm)
vgic_unqueue_irqs(tmp_vcpu);
offset -= r->base;
r->handle_mmio(vcpu, &mmio, offset);
if (!is_write)
*reg = mmio_data_read(&mmio, ~0);
ret = 0;
out_vgic_unlock:
spin_unlock(&vgic->lock);
out:
mutex_unlock(&dev->kvm->lock);
return ret;
}
static int vgic_v2_create(struct kvm_device *dev, u32 type)
{
return kvm_vgic_create(dev->kvm, type);
}
static void vgic_v2_destroy(struct kvm_device *dev)
{
kfree(dev);
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
return vgic_attr_regs_access(dev, attr, &reg, true);
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
ret = vgic_attr_regs_access(dev, attr, &reg, false);
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
phys_addr_t offset;
switch (attr->group) {
case KVM_DEV_ARM_VGIC_GRP_ADDR:
switch (attr->attr) {
case KVM_VGIC_V2_ADDR_TYPE_DIST:
case KVM_VGIC_V2_ADDR_TYPE_CPU:
return 0;
}
break;
case KVM_DEV_ARM_VGIC_GRP_DIST_REGS:
offset = attr->attr & KVM_DEV_ARM_VGIC_OFFSET_MASK;
return vgic_has_attr_regs(vgic_dist_ranges, offset);
case KVM_DEV_ARM_VGIC_GRP_CPU_REGS:
offset = attr->attr & KVM_DEV_ARM_VGIC_OFFSET_MASK;
return vgic_has_attr_regs(vgic_cpu_ranges, offset);
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
