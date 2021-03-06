static unsigned long vgic_mmio_read_v2_misc(struct kvm_vcpu *vcpu,
gpa_t addr, unsigned int len)
{
u32 value;
switch (addr & 0x0c) {
case GIC_DIST_CTRL:
value = vcpu->kvm->arch.vgic.enabled ? GICD_ENABLE : 0;
break;
case GIC_DIST_CTR:
value = vcpu->kvm->arch.vgic.nr_spis + VGIC_NR_PRIVATE_IRQS;
value = (value >> 5) - 1;
value |= (atomic_read(&vcpu->kvm->online_vcpus) - 1) << 5;
break;
case GIC_DIST_IIDR:
value = (PRODUCT_ID_KVM << 24) | (IMPLEMENTER_ARM << 0);
break;
default:
return 0;
}
return value;
}
static void vgic_mmio_write_v2_misc(struct kvm_vcpu *vcpu,
gpa_t addr, unsigned int len,
unsigned long val)
{
struct vgic_dist *dist = &vcpu->kvm->arch.vgic;
bool was_enabled = dist->enabled;
switch (addr & 0x0c) {
case GIC_DIST_CTRL:
dist->enabled = val & GICD_ENABLE;
if (!was_enabled && dist->enabled)
vgic_kick_vcpus(vcpu->kvm);
break;
case GIC_DIST_CTR:
case GIC_DIST_IIDR:
return;
}
}
static void vgic_mmio_write_sgir(struct kvm_vcpu *source_vcpu,
gpa_t addr, unsigned int len,
unsigned long val)
{
int nr_vcpus = atomic_read(&source_vcpu->kvm->online_vcpus);
int intid = val & 0xf;
int targets = (val >> 16) & 0xff;
int mode = (val >> 24) & 0x03;
int c;
struct kvm_vcpu *vcpu;
switch (mode) {
case 0x0:
break;
case 0x1:
targets = (1U << nr_vcpus) - 1;
targets &= ~(1U << source_vcpu->vcpu_id);
break;
case 0x2:
targets = (1U << source_vcpu->vcpu_id);
break;
case 0x3:
return;
}
kvm_for_each_vcpu(c, vcpu, source_vcpu->kvm) {
struct vgic_irq *irq;
if (!(targets & (1U << c)))
continue;
irq = vgic_get_irq(source_vcpu->kvm, vcpu, intid);
spin_lock(&irq->irq_lock);
irq->pending_latch = true;
irq->source |= 1U << source_vcpu->vcpu_id;
vgic_queue_irq_unlock(source_vcpu->kvm, irq);
vgic_put_irq(source_vcpu->kvm, irq);
}
}
static unsigned long vgic_mmio_read_target(struct kvm_vcpu *vcpu,
gpa_t addr, unsigned int len)
{
u32 intid = VGIC_ADDR_TO_INTID(addr, 8);
int i;
u64 val = 0;
for (i = 0; i < len; i++) {
struct vgic_irq *irq = vgic_get_irq(vcpu->kvm, vcpu, intid + i);
val |= (u64)irq->targets << (i * 8);
vgic_put_irq(vcpu->kvm, irq);
}
return val;
}
static void vgic_mmio_write_target(struct kvm_vcpu *vcpu,
gpa_t addr, unsigned int len,
unsigned long val)
{
u32 intid = VGIC_ADDR_TO_INTID(addr, 8);
u8 cpu_mask = GENMASK(atomic_read(&vcpu->kvm->online_vcpus) - 1, 0);
int i;
if (intid < VGIC_NR_PRIVATE_IRQS)
return;
for (i = 0; i < len; i++) {
struct vgic_irq *irq = vgic_get_irq(vcpu->kvm, NULL, intid + i);
int target;
spin_lock(&irq->irq_lock);
irq->targets = (val >> (i * 8)) & cpu_mask;
target = irq->targets ? __ffs(irq->targets) : 0;
irq->target_vcpu = kvm_get_vcpu(vcpu->kvm, target);
spin_unlock(&irq->irq_lock);
vgic_put_irq(vcpu->kvm, irq);
}
}
static unsigned long vgic_mmio_read_sgipend(struct kvm_vcpu *vcpu,
gpa_t addr, unsigned int len)
{
u32 intid = addr & 0x0f;
int i;
u64 val = 0;
for (i = 0; i < len; i++) {
struct vgic_irq *irq = vgic_get_irq(vcpu->kvm, vcpu, intid + i);
val |= (u64)irq->source << (i * 8);
vgic_put_irq(vcpu->kvm, irq);
}
return val;
}
static void vgic_mmio_write_sgipendc(struct kvm_vcpu *vcpu,
gpa_t addr, unsigned int len,
unsigned long val)
{
u32 intid = addr & 0x0f;
int i;
for (i = 0; i < len; i++) {
struct vgic_irq *irq = vgic_get_irq(vcpu->kvm, vcpu, intid + i);
spin_lock(&irq->irq_lock);
irq->source &= ~((val >> (i * 8)) & 0xff);
if (!irq->source)
irq->pending_latch = false;
spin_unlock(&irq->irq_lock);
vgic_put_irq(vcpu->kvm, irq);
}
}
static void vgic_mmio_write_sgipends(struct kvm_vcpu *vcpu,
gpa_t addr, unsigned int len,
unsigned long val)
{
u32 intid = addr & 0x0f;
int i;
for (i = 0; i < len; i++) {
struct vgic_irq *irq = vgic_get_irq(vcpu->kvm, vcpu, intid + i);
spin_lock(&irq->irq_lock);
irq->source |= (val >> (i * 8)) & 0xff;
if (irq->source) {
irq->pending_latch = true;
vgic_queue_irq_unlock(vcpu->kvm, irq);
} else {
spin_unlock(&irq->irq_lock);
}
vgic_put_irq(vcpu->kvm, irq);
}
}
static unsigned long vgic_mmio_read_vcpuif(struct kvm_vcpu *vcpu,
gpa_t addr, unsigned int len)
{
struct vgic_vmcr vmcr;
u32 val;
vgic_get_vmcr(vcpu, &vmcr);
switch (addr & 0xff) {
case GIC_CPU_CTRL:
val = vmcr.grpen0 << GIC_CPU_CTRL_EnableGrp0_SHIFT;
val |= vmcr.grpen1 << GIC_CPU_CTRL_EnableGrp1_SHIFT;
val |= vmcr.ackctl << GIC_CPU_CTRL_AckCtl_SHIFT;
val |= vmcr.fiqen << GIC_CPU_CTRL_FIQEn_SHIFT;
val |= vmcr.cbpr << GIC_CPU_CTRL_CBPR_SHIFT;
val |= vmcr.eoim << GIC_CPU_CTRL_EOImodeNS_SHIFT;
break;
case GIC_CPU_PRIMASK:
val = (vmcr.pmr & GICV_PMR_PRIORITY_MASK) >>
GICV_PMR_PRIORITY_SHIFT;
break;
case GIC_CPU_BINPOINT:
val = vmcr.bpr;
break;
case GIC_CPU_ALIAS_BINPOINT:
val = vmcr.abpr;
break;
case GIC_CPU_IDENT:
val = ((PRODUCT_ID_KVM << 20) |
(GICC_ARCH_VERSION_V2 << 16) |
IMPLEMENTER_ARM);
break;
default:
return 0;
}
return val;
}
static void vgic_mmio_write_vcpuif(struct kvm_vcpu *vcpu,
gpa_t addr, unsigned int len,
unsigned long val)
{
struct vgic_vmcr vmcr;
vgic_get_vmcr(vcpu, &vmcr);
switch (addr & 0xff) {
case GIC_CPU_CTRL:
vmcr.grpen0 = !!(val & GIC_CPU_CTRL_EnableGrp0);
vmcr.grpen1 = !!(val & GIC_CPU_CTRL_EnableGrp1);
vmcr.ackctl = !!(val & GIC_CPU_CTRL_AckCtl);
vmcr.fiqen = !!(val & GIC_CPU_CTRL_FIQEn);
vmcr.cbpr = !!(val & GIC_CPU_CTRL_CBPR);
vmcr.eoim = !!(val & GIC_CPU_CTRL_EOImodeNS);
break;
case GIC_CPU_PRIMASK:
vmcr.pmr = (val << GICV_PMR_PRIORITY_SHIFT) &
GICV_PMR_PRIORITY_MASK;
break;
case GIC_CPU_BINPOINT:
vmcr.bpr = val;
break;
case GIC_CPU_ALIAS_BINPOINT:
vmcr.abpr = val;
break;
}
vgic_set_vmcr(vcpu, &vmcr);
}
unsigned int vgic_v2_init_dist_iodev(struct vgic_io_device *dev)
{
dev->regions = vgic_v2_dist_registers;
dev->nr_regions = ARRAY_SIZE(vgic_v2_dist_registers);
kvm_iodevice_init(&dev->dev, &kvm_io_gic_ops);
return SZ_4K;
}
int vgic_v2_has_attr_regs(struct kvm_device *dev, struct kvm_device_attr *attr)
{
const struct vgic_register_region *region;
struct vgic_io_device iodev;
struct vgic_reg_attr reg_attr;
struct kvm_vcpu *vcpu;
gpa_t addr;
int ret;
ret = vgic_v2_parse_attr(dev, attr, &reg_attr);
if (ret)
return ret;
vcpu = reg_attr.vcpu;
addr = reg_attr.addr;
switch (attr->group) {
case KVM_DEV_ARM_VGIC_GRP_DIST_REGS:
iodev.regions = vgic_v2_dist_registers;
iodev.nr_regions = ARRAY_SIZE(vgic_v2_dist_registers);
iodev.base_addr = 0;
break;
case KVM_DEV_ARM_VGIC_GRP_CPU_REGS:
iodev.regions = vgic_v2_cpu_registers;
iodev.nr_regions = ARRAY_SIZE(vgic_v2_cpu_registers);
iodev.base_addr = 0;
break;
default:
return -ENXIO;
}
if (addr & 3)
return -ENXIO;
region = vgic_get_mmio_region(vcpu, &iodev, addr, sizeof(u32));
if (!region)
return -ENXIO;
return 0;
}
int vgic_v2_cpuif_uaccess(struct kvm_vcpu *vcpu, bool is_write,
int offset, u32 *val)
{
struct vgic_io_device dev = {
.regions = vgic_v2_cpu_registers,
.nr_regions = ARRAY_SIZE(vgic_v2_cpu_registers),
.iodev_type = IODEV_CPUIF,
};
return vgic_uaccess(vcpu, &dev, is_write, offset, val);
}
int vgic_v2_dist_uaccess(struct kvm_vcpu *vcpu, bool is_write,
int offset, u32 *val)
{
struct vgic_io_device dev = {
.regions = vgic_v2_dist_registers,
.nr_regions = ARRAY_SIZE(vgic_v2_dist_registers),
.iodev_type = IODEV_DIST,
};
return vgic_uaccess(vcpu, &dev, is_write, offset, val);
}
