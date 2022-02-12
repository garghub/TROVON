unsigned long extract_bytes(u64 data, unsigned int offset,
unsigned int num)
{
return (data >> (offset * 8)) & GENMASK_ULL(num * 8 - 1, 0);
}
u64 update_64bit_reg(u64 reg, unsigned int offset, unsigned int len,
unsigned long val)
{
int lower = (offset & 4) * 8;
int upper = lower + 8 * len - 1;
reg &= ~GENMASK_ULL(upper, lower);
val &= GENMASK_ULL(len * 8 - 1, 0);
return reg | ((u64)val << lower);
}
bool vgic_has_its(struct kvm *kvm)
{
struct vgic_dist *dist = &kvm->arch.vgic;
if (dist->vgic_model != KVM_DEV_TYPE_ARM_VGIC_V3)
return false;
return dist->has_its;
}
static unsigned long vgic_mmio_read_v3_misc(struct kvm_vcpu *vcpu,
gpa_t addr, unsigned int len)
{
u32 value = 0;
switch (addr & 0x0c) {
case GICD_CTLR:
if (vcpu->kvm->arch.vgic.enabled)
value |= GICD_CTLR_ENABLE_SS_G1;
value |= GICD_CTLR_ARE_NS | GICD_CTLR_DS;
break;
case GICD_TYPER:
value = vcpu->kvm->arch.vgic.nr_spis + VGIC_NR_PRIVATE_IRQS;
value = (value >> 5) - 1;
if (vgic_has_its(vcpu->kvm)) {
value |= (INTERRUPT_ID_BITS_ITS - 1) << 19;
value |= GICD_TYPER_LPIS;
} else {
value |= (INTERRUPT_ID_BITS_SPIS - 1) << 19;
}
break;
case GICD_IIDR:
value = (PRODUCT_ID_KVM << 24) | (IMPLEMENTER_ARM << 0);
break;
default:
return 0;
}
return value;
}
static void vgic_mmio_write_v3_misc(struct kvm_vcpu *vcpu,
gpa_t addr, unsigned int len,
unsigned long val)
{
struct vgic_dist *dist = &vcpu->kvm->arch.vgic;
bool was_enabled = dist->enabled;
switch (addr & 0x0c) {
case GICD_CTLR:
dist->enabled = val & GICD_CTLR_ENABLE_SS_G1;
if (!was_enabled && dist->enabled)
vgic_kick_vcpus(vcpu->kvm);
break;
case GICD_TYPER:
case GICD_IIDR:
return;
}
}
static unsigned long vgic_mmio_read_irouter(struct kvm_vcpu *vcpu,
gpa_t addr, unsigned int len)
{
int intid = VGIC_ADDR_TO_INTID(addr, 64);
struct vgic_irq *irq = vgic_get_irq(vcpu->kvm, NULL, intid);
unsigned long ret = 0;
if (!irq)
return 0;
if (!(addr & 4))
ret = extract_bytes(READ_ONCE(irq->mpidr), addr & 7, len);
vgic_put_irq(vcpu->kvm, irq);
return ret;
}
static void vgic_mmio_write_irouter(struct kvm_vcpu *vcpu,
gpa_t addr, unsigned int len,
unsigned long val)
{
int intid = VGIC_ADDR_TO_INTID(addr, 64);
struct vgic_irq *irq;
if (addr & 4)
return;
irq = vgic_get_irq(vcpu->kvm, NULL, intid);
if (!irq)
return;
spin_lock(&irq->irq_lock);
irq->mpidr = val & GENMASK(23, 0);
irq->target_vcpu = kvm_mpidr_to_vcpu(vcpu->kvm, irq->mpidr);
spin_unlock(&irq->irq_lock);
vgic_put_irq(vcpu->kvm, irq);
}
static unsigned long vgic_mmio_read_v3r_ctlr(struct kvm_vcpu *vcpu,
gpa_t addr, unsigned int len)
{
struct vgic_cpu *vgic_cpu = &vcpu->arch.vgic_cpu;
return vgic_cpu->lpis_enabled ? GICR_CTLR_ENABLE_LPIS : 0;
}
static void vgic_mmio_write_v3r_ctlr(struct kvm_vcpu *vcpu,
gpa_t addr, unsigned int len,
unsigned long val)
{
struct vgic_cpu *vgic_cpu = &vcpu->arch.vgic_cpu;
bool was_enabled = vgic_cpu->lpis_enabled;
if (!vgic_has_its(vcpu->kvm))
return;
vgic_cpu->lpis_enabled = val & GICR_CTLR_ENABLE_LPIS;
if (!was_enabled && vgic_cpu->lpis_enabled)
vgic_enable_lpis(vcpu);
}
static unsigned long vgic_mmio_read_v3r_typer(struct kvm_vcpu *vcpu,
gpa_t addr, unsigned int len)
{
unsigned long mpidr = kvm_vcpu_get_mpidr_aff(vcpu);
int target_vcpu_id = vcpu->vcpu_id;
u64 value;
value = (u64)(mpidr & GENMASK(23, 0)) << 32;
value |= ((target_vcpu_id & 0xffff) << 8);
if (target_vcpu_id == atomic_read(&vcpu->kvm->online_vcpus) - 1)
value |= GICR_TYPER_LAST;
if (vgic_has_its(vcpu->kvm))
value |= GICR_TYPER_PLPIS;
return extract_bytes(value, addr & 7, len);
}
static unsigned long vgic_mmio_read_v3r_iidr(struct kvm_vcpu *vcpu,
gpa_t addr, unsigned int len)
{
return (PRODUCT_ID_KVM << 24) | (IMPLEMENTER_ARM << 0);
}
static unsigned long vgic_mmio_read_v3_idregs(struct kvm_vcpu *vcpu,
gpa_t addr, unsigned int len)
{
switch (addr & 0xffff) {
case GICD_PIDR2:
return 0x3b;
}
return 0;
}
static unsigned long vgic_v3_uaccess_read_pending(struct kvm_vcpu *vcpu,
gpa_t addr, unsigned int len)
{
u32 intid = VGIC_ADDR_TO_INTID(addr, 1);
u32 value = 0;
int i;
for (i = 0; i < len * 8; i++) {
struct vgic_irq *irq = vgic_get_irq(vcpu->kvm, vcpu, intid + i);
if (irq->pending_latch)
value |= (1U << i);
vgic_put_irq(vcpu->kvm, irq);
}
return value;
}
static void vgic_v3_uaccess_write_pending(struct kvm_vcpu *vcpu,
gpa_t addr, unsigned int len,
unsigned long val)
{
u32 intid = VGIC_ADDR_TO_INTID(addr, 1);
int i;
for (i = 0; i < len * 8; i++) {
struct vgic_irq *irq = vgic_get_irq(vcpu->kvm, vcpu, intid + i);
spin_lock(&irq->irq_lock);
if (test_bit(i, &val)) {
irq->pending_latch = true;
vgic_queue_irq_unlock(vcpu->kvm, irq);
} else {
irq->pending_latch = false;
spin_unlock(&irq->irq_lock);
}
vgic_put_irq(vcpu->kvm, irq);
}
}
u64 vgic_sanitise_shareability(u64 field)
{
switch (field) {
case GIC_BASER_OuterShareable:
return GIC_BASER_InnerShareable;
default:
return field;
}
}
u64 vgic_sanitise_inner_cacheability(u64 field)
{
switch (field) {
case GIC_BASER_CACHE_nCnB:
case GIC_BASER_CACHE_nC:
return GIC_BASER_CACHE_RaWb;
default:
return field;
}
}
u64 vgic_sanitise_outer_cacheability(u64 field)
{
switch (field) {
case GIC_BASER_CACHE_SameAsInner:
case GIC_BASER_CACHE_nC:
return field;
default:
return GIC_BASER_CACHE_nC;
}
}
u64 vgic_sanitise_field(u64 reg, u64 field_mask, int field_shift,
u64 (*sanitise_fn)(u64))
{
u64 field = (reg & field_mask) >> field_shift;
field = sanitise_fn(field) << field_shift;
return (reg & ~field_mask) | field;
}
static u64 vgic_sanitise_pendbaser(u64 reg)
{
reg = vgic_sanitise_field(reg, GICR_PENDBASER_SHAREABILITY_MASK,
GICR_PENDBASER_SHAREABILITY_SHIFT,
vgic_sanitise_shareability);
reg = vgic_sanitise_field(reg, GICR_PENDBASER_INNER_CACHEABILITY_MASK,
GICR_PENDBASER_INNER_CACHEABILITY_SHIFT,
vgic_sanitise_inner_cacheability);
reg = vgic_sanitise_field(reg, GICR_PENDBASER_OUTER_CACHEABILITY_MASK,
GICR_PENDBASER_OUTER_CACHEABILITY_SHIFT,
vgic_sanitise_outer_cacheability);
reg &= ~PENDBASER_RES0_MASK;
reg &= ~GENMASK_ULL(51, 48);
return reg;
}
static u64 vgic_sanitise_propbaser(u64 reg)
{
reg = vgic_sanitise_field(reg, GICR_PROPBASER_SHAREABILITY_MASK,
GICR_PROPBASER_SHAREABILITY_SHIFT,
vgic_sanitise_shareability);
reg = vgic_sanitise_field(reg, GICR_PROPBASER_INNER_CACHEABILITY_MASK,
GICR_PROPBASER_INNER_CACHEABILITY_SHIFT,
vgic_sanitise_inner_cacheability);
reg = vgic_sanitise_field(reg, GICR_PROPBASER_OUTER_CACHEABILITY_MASK,
GICR_PROPBASER_OUTER_CACHEABILITY_SHIFT,
vgic_sanitise_outer_cacheability);
reg &= ~PROPBASER_RES0_MASK;
reg &= ~GENMASK_ULL(51, 48);
return reg;
}
static unsigned long vgic_mmio_read_propbase(struct kvm_vcpu *vcpu,
gpa_t addr, unsigned int len)
{
struct vgic_dist *dist = &vcpu->kvm->arch.vgic;
return extract_bytes(dist->propbaser, addr & 7, len);
}
static void vgic_mmio_write_propbase(struct kvm_vcpu *vcpu,
gpa_t addr, unsigned int len,
unsigned long val)
{
struct vgic_dist *dist = &vcpu->kvm->arch.vgic;
struct vgic_cpu *vgic_cpu = &vcpu->arch.vgic_cpu;
u64 old_propbaser, propbaser;
if (vgic_cpu->lpis_enabled)
return;
do {
old_propbaser = dist->propbaser;
propbaser = old_propbaser;
propbaser = update_64bit_reg(propbaser, addr & 4, len, val);
propbaser = vgic_sanitise_propbaser(propbaser);
} while (cmpxchg64(&dist->propbaser, old_propbaser,
propbaser) != old_propbaser);
}
static unsigned long vgic_mmio_read_pendbase(struct kvm_vcpu *vcpu,
gpa_t addr, unsigned int len)
{
struct vgic_cpu *vgic_cpu = &vcpu->arch.vgic_cpu;
return extract_bytes(vgic_cpu->pendbaser, addr & 7, len);
}
static void vgic_mmio_write_pendbase(struct kvm_vcpu *vcpu,
gpa_t addr, unsigned int len,
unsigned long val)
{
struct vgic_cpu *vgic_cpu = &vcpu->arch.vgic_cpu;
u64 old_pendbaser, pendbaser;
if (vgic_cpu->lpis_enabled)
return;
do {
old_pendbaser = vgic_cpu->pendbaser;
pendbaser = old_pendbaser;
pendbaser = update_64bit_reg(pendbaser, addr & 4, len, val);
pendbaser = vgic_sanitise_pendbaser(pendbaser);
} while (cmpxchg64(&vgic_cpu->pendbaser, old_pendbaser,
pendbaser) != old_pendbaser);
}
unsigned int vgic_v3_init_dist_iodev(struct vgic_io_device *dev)
{
dev->regions = vgic_v3_dist_registers;
dev->nr_regions = ARRAY_SIZE(vgic_v3_dist_registers);
kvm_iodevice_init(&dev->dev, &kvm_io_gic_ops);
return SZ_64K;
}
int vgic_register_redist_iodev(struct kvm_vcpu *vcpu)
{
struct kvm *kvm = vcpu->kvm;
struct vgic_dist *vgic = &kvm->arch.vgic;
struct vgic_io_device *rd_dev = &vcpu->arch.vgic_cpu.rd_iodev;
struct vgic_io_device *sgi_dev = &vcpu->arch.vgic_cpu.sgi_iodev;
gpa_t rd_base, sgi_base;
int ret;
if (IS_VGIC_ADDR_UNDEF(vgic->vgic_redist_base))
return 0;
if (!vgic_v3_check_base(kvm))
return -EINVAL;
rd_base = vgic->vgic_redist_base + vgic->vgic_redist_free_offset;
sgi_base = rd_base + SZ_64K;
kvm_iodevice_init(&rd_dev->dev, &kvm_io_gic_ops);
rd_dev->base_addr = rd_base;
rd_dev->iodev_type = IODEV_REDIST;
rd_dev->regions = vgic_v3_rdbase_registers;
rd_dev->nr_regions = ARRAY_SIZE(vgic_v3_rdbase_registers);
rd_dev->redist_vcpu = vcpu;
mutex_lock(&kvm->slots_lock);
ret = kvm_io_bus_register_dev(kvm, KVM_MMIO_BUS, rd_base,
SZ_64K, &rd_dev->dev);
mutex_unlock(&kvm->slots_lock);
if (ret)
return ret;
kvm_iodevice_init(&sgi_dev->dev, &kvm_io_gic_ops);
sgi_dev->base_addr = sgi_base;
sgi_dev->iodev_type = IODEV_REDIST;
sgi_dev->regions = vgic_v3_sgibase_registers;
sgi_dev->nr_regions = ARRAY_SIZE(vgic_v3_sgibase_registers);
sgi_dev->redist_vcpu = vcpu;
mutex_lock(&kvm->slots_lock);
ret = kvm_io_bus_register_dev(kvm, KVM_MMIO_BUS, sgi_base,
SZ_64K, &sgi_dev->dev);
if (ret) {
kvm_io_bus_unregister_dev(kvm, KVM_MMIO_BUS,
&rd_dev->dev);
goto out;
}
vgic->vgic_redist_free_offset += 2 * SZ_64K;
out:
mutex_unlock(&kvm->slots_lock);
return ret;
}
static void vgic_unregister_redist_iodev(struct kvm_vcpu *vcpu)
{
struct vgic_io_device *rd_dev = &vcpu->arch.vgic_cpu.rd_iodev;
struct vgic_io_device *sgi_dev = &vcpu->arch.vgic_cpu.sgi_iodev;
kvm_io_bus_unregister_dev(vcpu->kvm, KVM_MMIO_BUS, &rd_dev->dev);
kvm_io_bus_unregister_dev(vcpu->kvm, KVM_MMIO_BUS, &sgi_dev->dev);
}
static int vgic_register_all_redist_iodevs(struct kvm *kvm)
{
struct kvm_vcpu *vcpu;
int c, ret = 0;
kvm_for_each_vcpu(c, vcpu, kvm) {
ret = vgic_register_redist_iodev(vcpu);
if (ret)
break;
}
if (ret) {
mutex_lock(&kvm->slots_lock);
for (c--; c >= 0; c--) {
vcpu = kvm_get_vcpu(kvm, c);
vgic_unregister_redist_iodev(vcpu);
}
mutex_unlock(&kvm->slots_lock);
}
return ret;
}
int vgic_v3_set_redist_base(struct kvm *kvm, u64 addr)
{
struct vgic_dist *vgic = &kvm->arch.vgic;
int ret;
ret = vgic_check_ioaddr(kvm, &vgic->vgic_redist_base, addr, SZ_64K);
if (ret)
return ret;
vgic->vgic_redist_base = addr;
if (!vgic_v3_check_base(kvm)) {
vgic->vgic_redist_base = VGIC_ADDR_UNDEF;
return -EINVAL;
}
ret = vgic_register_all_redist_iodevs(kvm);
if (ret)
return ret;
return 0;
}
int vgic_v3_has_attr_regs(struct kvm_device *dev, struct kvm_device_attr *attr)
{
const struct vgic_register_region *region;
struct vgic_io_device iodev;
struct vgic_reg_attr reg_attr;
struct kvm_vcpu *vcpu;
gpa_t addr;
int ret;
ret = vgic_v3_parse_attr(dev, attr, &reg_attr);
if (ret)
return ret;
vcpu = reg_attr.vcpu;
addr = reg_attr.addr;
switch (attr->group) {
case KVM_DEV_ARM_VGIC_GRP_DIST_REGS:
iodev.regions = vgic_v3_dist_registers;
iodev.nr_regions = ARRAY_SIZE(vgic_v3_dist_registers);
iodev.base_addr = 0;
break;
case KVM_DEV_ARM_VGIC_GRP_REDIST_REGS:{
iodev.regions = vgic_v3_rdbase_registers;
iodev.nr_regions = ARRAY_SIZE(vgic_v3_rdbase_registers);
iodev.base_addr = 0;
break;
}
case KVM_DEV_ARM_VGIC_GRP_CPU_SYSREGS: {
u64 reg, id;
id = (attr->attr & KVM_DEV_ARM_VGIC_SYSREG_INSTR_MASK);
return vgic_v3_has_cpu_sysregs_attr(vcpu, 0, id, &reg);
}
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
static int match_mpidr(u64 sgi_aff, u16 sgi_cpu_mask, struct kvm_vcpu *vcpu)
{
unsigned long affinity;
int level0;
affinity = kvm_vcpu_get_mpidr_aff(vcpu);
level0 = MPIDR_AFFINITY_LEVEL(affinity, 0);
affinity &= ~MPIDR_LEVEL_MASK;
if (sgi_aff != affinity)
return -1;
if (!(sgi_cpu_mask & BIT(level0)))
return -1;
return level0;
}
void vgic_v3_dispatch_sgi(struct kvm_vcpu *vcpu, u64 reg)
{
struct kvm *kvm = vcpu->kvm;
struct kvm_vcpu *c_vcpu;
u16 target_cpus;
u64 mpidr;
int sgi, c;
int vcpu_id = vcpu->vcpu_id;
bool broadcast;
sgi = (reg & ICC_SGI1R_SGI_ID_MASK) >> ICC_SGI1R_SGI_ID_SHIFT;
broadcast = reg & BIT_ULL(ICC_SGI1R_IRQ_ROUTING_MODE_BIT);
target_cpus = (reg & ICC_SGI1R_TARGET_LIST_MASK) >> ICC_SGI1R_TARGET_LIST_SHIFT;
mpidr = SGI_AFFINITY_LEVEL(reg, 3);
mpidr |= SGI_AFFINITY_LEVEL(reg, 2);
mpidr |= SGI_AFFINITY_LEVEL(reg, 1);
kvm_for_each_vcpu(c, c_vcpu, kvm) {
struct vgic_irq *irq;
if (!broadcast && target_cpus == 0)
break;
if (broadcast && c == vcpu_id)
continue;
if (!broadcast) {
int level0;
level0 = match_mpidr(mpidr, target_cpus, c_vcpu);
if (level0 == -1)
continue;
target_cpus &= ~BIT(level0);
}
irq = vgic_get_irq(vcpu->kvm, c_vcpu, sgi);
spin_lock(&irq->irq_lock);
irq->pending_latch = true;
vgic_queue_irq_unlock(vcpu->kvm, irq);
vgic_put_irq(vcpu->kvm, irq);
}
}
int vgic_v3_dist_uaccess(struct kvm_vcpu *vcpu, bool is_write,
int offset, u32 *val)
{
struct vgic_io_device dev = {
.regions = vgic_v3_dist_registers,
.nr_regions = ARRAY_SIZE(vgic_v3_dist_registers),
};
return vgic_uaccess(vcpu, &dev, is_write, offset, val);
}
int vgic_v3_redist_uaccess(struct kvm_vcpu *vcpu, bool is_write,
int offset, u32 *val)
{
struct vgic_io_device rd_dev = {
.regions = vgic_v3_rdbase_registers,
.nr_regions = ARRAY_SIZE(vgic_v3_rdbase_registers),
};
struct vgic_io_device sgi_dev = {
.regions = vgic_v3_sgibase_registers,
.nr_regions = ARRAY_SIZE(vgic_v3_sgibase_registers),
};
if (offset >= SZ_64K)
return vgic_uaccess(vcpu, &sgi_dev, is_write, offset - SZ_64K,
val);
else
return vgic_uaccess(vcpu, &rd_dev, is_write, offset, val);
}
int vgic_v3_line_level_info_uaccess(struct kvm_vcpu *vcpu, bool is_write,
u32 intid, u64 *val)
{
if (intid % 32)
return -EINVAL;
if (is_write)
vgic_write_irq_line_level_info(vcpu, intid, *val);
else
*val = vgic_read_irq_line_level_info(vcpu, intid);
return 0;
}
