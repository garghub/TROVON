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
irq->pending = true;
irq->source |= 1U << source_vcpu->vcpu_id;
vgic_queue_irq_unlock(source_vcpu->kvm, irq);
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
}
return val;
}
static void vgic_mmio_write_target(struct kvm_vcpu *vcpu,
gpa_t addr, unsigned int len,
unsigned long val)
{
u32 intid = VGIC_ADDR_TO_INTID(addr, 8);
int i;
if (intid < VGIC_NR_PRIVATE_IRQS)
return;
for (i = 0; i < len; i++) {
struct vgic_irq *irq = vgic_get_irq(vcpu->kvm, NULL, intid + i);
int target;
spin_lock(&irq->irq_lock);
irq->targets = (val >> (i * 8)) & 0xff;
target = irq->targets ? __ffs(irq->targets) : 0;
irq->target_vcpu = kvm_get_vcpu(vcpu->kvm, target);
spin_unlock(&irq->irq_lock);
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
irq->pending = false;
spin_unlock(&irq->irq_lock);
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
irq->pending = true;
vgic_queue_irq_unlock(vcpu->kvm, irq);
} else {
spin_unlock(&irq->irq_lock);
}
}
}
static void vgic_set_vmcr(struct kvm_vcpu *vcpu, struct vgic_vmcr *vmcr)
{
if (kvm_vgic_global_state.type == VGIC_V2)
vgic_v2_set_vmcr(vcpu, vmcr);
else
vgic_v3_set_vmcr(vcpu, vmcr);
}
static void vgic_get_vmcr(struct kvm_vcpu *vcpu, struct vgic_vmcr *vmcr)
{
if (kvm_vgic_global_state.type == VGIC_V2)
vgic_v2_get_vmcr(vcpu, vmcr);
else
vgic_v3_get_vmcr(vcpu, vmcr);
}
static unsigned long vgic_mmio_read_vcpuif(struct kvm_vcpu *vcpu,
gpa_t addr, unsigned int len)
{
struct vgic_vmcr vmcr;
u32 val;
vgic_get_vmcr(vcpu, &vmcr);
switch (addr & 0xff) {
case GIC_CPU_CTRL:
val = vmcr.ctlr;
break;
case GIC_CPU_PRIMASK:
val = vmcr.pmr;
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
vmcr.ctlr = val;
break;
case GIC_CPU_PRIMASK:
vmcr.pmr = val;
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
int nr_irqs = dev->kvm->arch.vgic.nr_spis + VGIC_NR_PRIVATE_IRQS;
const struct vgic_register_region *regions;
gpa_t addr;
int nr_regions, i, len;
addr = attr->attr & KVM_DEV_ARM_VGIC_OFFSET_MASK;
switch (attr->group) {
case KVM_DEV_ARM_VGIC_GRP_DIST_REGS:
regions = vgic_v2_dist_registers;
nr_regions = ARRAY_SIZE(vgic_v2_dist_registers);
break;
case KVM_DEV_ARM_VGIC_GRP_CPU_REGS:
regions = vgic_v2_cpu_registers;
nr_regions = ARRAY_SIZE(vgic_v2_cpu_registers);
break;
default:
return -ENXIO;
}
if (addr & 3)
return -ENXIO;
for (i = 0; i < nr_regions; i++) {
if (regions[i].bits_per_irq)
len = (regions[i].bits_per_irq * nr_irqs) / 8;
else
len = regions[i].len;
if (regions[i].reg_offset <= addr &&
regions[i].reg_offset + len > addr)
return 0;
}
return -ENXIO;
}
static int vgic_uaccess(struct kvm_vcpu *vcpu, struct vgic_io_device *dev,
bool is_write, int offset, u32 *val)
{
unsigned int len = 4;
u8 buf[4];
int ret;
if (is_write) {
vgic_data_host_to_mmio_bus(buf, len, *val);
ret = kvm_io_gic_ops.write(vcpu, &dev->dev, offset, len, buf);
} else {
ret = kvm_io_gic_ops.read(vcpu, &dev->dev, offset, len, buf);
if (!ret)
*val = vgic_data_mmio_bus_to_host(buf, len);
}
return ret;
}
int vgic_v2_cpuif_uaccess(struct kvm_vcpu *vcpu, bool is_write,
int offset, u32 *val)
{
struct vgic_io_device dev = {
.regions = vgic_v2_cpu_registers,
.nr_regions = ARRAY_SIZE(vgic_v2_cpu_registers),
};
return vgic_uaccess(vcpu, &dev, is_write, offset, val);
}
int vgic_v2_dist_uaccess(struct kvm_vcpu *vcpu, bool is_write,
int offset, u32 *val)
{
struct vgic_io_device dev = {
.regions = vgic_v2_dist_registers,
.nr_regions = ARRAY_SIZE(vgic_v2_dist_registers),
};
return vgic_uaccess(vcpu, &dev, is_write, offset, val);
}
