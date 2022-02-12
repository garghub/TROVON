static bool handle_mmio_rao_wi(struct kvm_vcpu *vcpu,
struct kvm_exit_mmio *mmio, phys_addr_t offset)
{
u32 reg = 0xffffffff;
vgic_reg_access(mmio, &reg, offset,
ACCESS_READ_VALUE | ACCESS_WRITE_IGNORED);
return false;
}
static bool handle_mmio_ctlr(struct kvm_vcpu *vcpu,
struct kvm_exit_mmio *mmio, phys_addr_t offset)
{
u32 reg = 0;
if (vcpu->kvm->arch.vgic.enabled)
reg = GICD_CTLR_ENABLE_SS_G1;
reg |= GICD_CTLR_ARE_NS | GICD_CTLR_DS;
vgic_reg_access(mmio, &reg, offset,
ACCESS_READ_VALUE | ACCESS_WRITE_VALUE);
if (mmio->is_write) {
vcpu->kvm->arch.vgic.enabled = !!(reg & GICD_CTLR_ENABLE_SS_G1);
vgic_update_state(vcpu->kvm);
return true;
}
return false;
}
static bool handle_mmio_typer(struct kvm_vcpu *vcpu,
struct kvm_exit_mmio *mmio, phys_addr_t offset)
{
u32 reg;
reg = (min(vcpu->kvm->arch.vgic.nr_irqs, 1024) >> 5) - 1;
reg |= (INTERRUPT_ID_BITS - 1) << 19;
vgic_reg_access(mmio, &reg, offset,
ACCESS_READ_VALUE | ACCESS_WRITE_IGNORED);
return false;
}
static bool handle_mmio_iidr(struct kvm_vcpu *vcpu,
struct kvm_exit_mmio *mmio, phys_addr_t offset)
{
u32 reg;
reg = (PRODUCT_ID_KVM << 24) | (IMPLEMENTER_ARM << 0);
vgic_reg_access(mmio, &reg, offset,
ACCESS_READ_VALUE | ACCESS_WRITE_IGNORED);
return false;
}
static bool handle_mmio_set_enable_reg_dist(struct kvm_vcpu *vcpu,
struct kvm_exit_mmio *mmio,
phys_addr_t offset)
{
if (likely(offset >= VGIC_NR_PRIVATE_IRQS / 8))
return vgic_handle_enable_reg(vcpu->kvm, mmio, offset,
vcpu->vcpu_id,
ACCESS_WRITE_SETBIT);
vgic_reg_access(mmio, NULL, offset,
ACCESS_READ_RAZ | ACCESS_WRITE_IGNORED);
return false;
}
static bool handle_mmio_clear_enable_reg_dist(struct kvm_vcpu *vcpu,
struct kvm_exit_mmio *mmio,
phys_addr_t offset)
{
if (likely(offset >= VGIC_NR_PRIVATE_IRQS / 8))
return vgic_handle_enable_reg(vcpu->kvm, mmio, offset,
vcpu->vcpu_id,
ACCESS_WRITE_CLEARBIT);
vgic_reg_access(mmio, NULL, offset,
ACCESS_READ_RAZ | ACCESS_WRITE_IGNORED);
return false;
}
static bool handle_mmio_set_pending_reg_dist(struct kvm_vcpu *vcpu,
struct kvm_exit_mmio *mmio,
phys_addr_t offset)
{
if (likely(offset >= VGIC_NR_PRIVATE_IRQS / 8))
return vgic_handle_set_pending_reg(vcpu->kvm, mmio, offset,
vcpu->vcpu_id);
vgic_reg_access(mmio, NULL, offset,
ACCESS_READ_RAZ | ACCESS_WRITE_IGNORED);
return false;
}
static bool handle_mmio_clear_pending_reg_dist(struct kvm_vcpu *vcpu,
struct kvm_exit_mmio *mmio,
phys_addr_t offset)
{
if (likely(offset >= VGIC_NR_PRIVATE_IRQS / 8))
return vgic_handle_clear_pending_reg(vcpu->kvm, mmio, offset,
vcpu->vcpu_id);
vgic_reg_access(mmio, NULL, offset,
ACCESS_READ_RAZ | ACCESS_WRITE_IGNORED);
return false;
}
static bool handle_mmio_set_active_reg_dist(struct kvm_vcpu *vcpu,
struct kvm_exit_mmio *mmio,
phys_addr_t offset)
{
if (likely(offset >= VGIC_NR_PRIVATE_IRQS / 8))
return vgic_handle_set_active_reg(vcpu->kvm, mmio, offset,
vcpu->vcpu_id);
vgic_reg_access(mmio, NULL, offset,
ACCESS_READ_RAZ | ACCESS_WRITE_IGNORED);
return false;
}
static bool handle_mmio_clear_active_reg_dist(struct kvm_vcpu *vcpu,
struct kvm_exit_mmio *mmio,
phys_addr_t offset)
{
if (likely(offset >= VGIC_NR_PRIVATE_IRQS / 8))
return vgic_handle_clear_active_reg(vcpu->kvm, mmio, offset,
vcpu->vcpu_id);
vgic_reg_access(mmio, NULL, offset,
ACCESS_READ_RAZ | ACCESS_WRITE_IGNORED);
return false;
}
static bool handle_mmio_priority_reg_dist(struct kvm_vcpu *vcpu,
struct kvm_exit_mmio *mmio,
phys_addr_t offset)
{
u32 *reg;
if (unlikely(offset < VGIC_NR_PRIVATE_IRQS)) {
vgic_reg_access(mmio, NULL, offset,
ACCESS_READ_RAZ | ACCESS_WRITE_IGNORED);
return false;
}
reg = vgic_bytemap_get_reg(&vcpu->kvm->arch.vgic.irq_priority,
vcpu->vcpu_id, offset);
vgic_reg_access(mmio, reg, offset,
ACCESS_READ_VALUE | ACCESS_WRITE_VALUE);
return false;
}
static bool handle_mmio_cfg_reg_dist(struct kvm_vcpu *vcpu,
struct kvm_exit_mmio *mmio,
phys_addr_t offset)
{
u32 *reg;
if (unlikely(offset < VGIC_NR_PRIVATE_IRQS / 4)) {
vgic_reg_access(mmio, NULL, offset,
ACCESS_READ_RAZ | ACCESS_WRITE_IGNORED);
return false;
}
reg = vgic_bitmap_get_reg(&vcpu->kvm->arch.vgic.irq_cfg,
vcpu->vcpu_id, offset >> 1);
return vgic_handle_cfg_reg(reg, mmio, offset);
}
static u32 compress_mpidr(unsigned long mpidr)
{
u32 ret;
ret = MPIDR_AFFINITY_LEVEL(mpidr, 0);
ret |= MPIDR_AFFINITY_LEVEL(mpidr, 1) << 8;
ret |= MPIDR_AFFINITY_LEVEL(mpidr, 2) << 16;
ret |= MPIDR_AFFINITY_LEVEL(mpidr, 3) << 24;
return ret;
}
static unsigned long uncompress_mpidr(u32 value)
{
unsigned long mpidr;
mpidr = ((value >> 0) & 0xFF) << MPIDR_LEVEL_SHIFT(0);
mpidr |= ((value >> 8) & 0xFF) << MPIDR_LEVEL_SHIFT(1);
mpidr |= ((value >> 16) & 0xFF) << MPIDR_LEVEL_SHIFT(2);
mpidr |= (u64)((value >> 24) & 0xFF) << MPIDR_LEVEL_SHIFT(3);
return mpidr;
}
static bool handle_mmio_route_reg(struct kvm_vcpu *vcpu,
struct kvm_exit_mmio *mmio,
phys_addr_t offset)
{
struct kvm *kvm = vcpu->kvm;
struct vgic_dist *dist = &kvm->arch.vgic;
int spi;
u32 reg;
int vcpu_id;
unsigned long *bmap, mpidr;
if ((offset & 4)) {
vgic_reg_access(mmio, NULL, offset,
ACCESS_READ_RAZ | ACCESS_WRITE_IGNORED);
return false;
}
spi = offset / 8;
mpidr = uncompress_mpidr(dist->irq_spi_mpidr[spi]);
reg = mpidr;
vgic_reg_access(mmio, &reg, offset,
ACCESS_READ_VALUE | ACCESS_WRITE_VALUE);
if (!mmio->is_write)
return false;
vcpu = kvm_mpidr_to_vcpu(kvm, mpidr);
if (likely(vcpu)) {
vcpu_id = vcpu->vcpu_id;
bmap = vgic_bitmap_get_shared_map(&dist->irq_spi_target[vcpu_id]);
__clear_bit(spi, bmap);
}
dist->irq_spi_mpidr[spi] = compress_mpidr(reg);
vcpu = kvm_mpidr_to_vcpu(kvm, reg & MPIDR_HWID_BITMASK);
if (likely(vcpu)) {
vcpu_id = vcpu->vcpu_id;
dist->irq_spi_cpu[spi] = vcpu_id;
bmap = vgic_bitmap_get_shared_map(&dist->irq_spi_target[vcpu_id]);
__set_bit(spi, bmap);
} else {
dist->irq_spi_cpu[spi] = VCPU_NOT_ALLOCATED;
}
vgic_update_state(kvm);
return true;
}
static bool handle_mmio_idregs(struct kvm_vcpu *vcpu,
struct kvm_exit_mmio *mmio,
phys_addr_t offset)
{
u32 reg = 0;
switch (offset + GICD_IDREGS) {
case GICD_PIDR2:
reg = 0x3b;
break;
}
vgic_reg_access(mmio, &reg, offset,
ACCESS_READ_VALUE | ACCESS_WRITE_IGNORED);
return false;
}
static bool handle_mmio_ctlr_redist(struct kvm_vcpu *vcpu,
struct kvm_exit_mmio *mmio,
phys_addr_t offset)
{
vgic_reg_access(mmio, NULL, offset,
ACCESS_READ_RAZ | ACCESS_WRITE_IGNORED);
return false;
}
static bool handle_mmio_typer_redist(struct kvm_vcpu *vcpu,
struct kvm_exit_mmio *mmio,
phys_addr_t offset)
{
u32 reg;
u64 mpidr;
struct kvm_vcpu *redist_vcpu = mmio->private;
int target_vcpu_id = redist_vcpu->vcpu_id;
if ((offset & ~3) == 4) {
mpidr = kvm_vcpu_get_mpidr_aff(redist_vcpu);
reg = compress_mpidr(mpidr);
vgic_reg_access(mmio, &reg, offset,
ACCESS_READ_VALUE | ACCESS_WRITE_IGNORED);
return false;
}
reg = redist_vcpu->vcpu_id << 8;
if (target_vcpu_id == atomic_read(&vcpu->kvm->online_vcpus) - 1)
reg |= GICR_TYPER_LAST;
vgic_reg_access(mmio, &reg, offset,
ACCESS_READ_VALUE | ACCESS_WRITE_IGNORED);
return false;
}
static bool handle_mmio_set_enable_reg_redist(struct kvm_vcpu *vcpu,
struct kvm_exit_mmio *mmio,
phys_addr_t offset)
{
struct kvm_vcpu *redist_vcpu = mmio->private;
return vgic_handle_enable_reg(vcpu->kvm, mmio, offset,
redist_vcpu->vcpu_id,
ACCESS_WRITE_SETBIT);
}
static bool handle_mmio_clear_enable_reg_redist(struct kvm_vcpu *vcpu,
struct kvm_exit_mmio *mmio,
phys_addr_t offset)
{
struct kvm_vcpu *redist_vcpu = mmio->private;
return vgic_handle_enable_reg(vcpu->kvm, mmio, offset,
redist_vcpu->vcpu_id,
ACCESS_WRITE_CLEARBIT);
}
static bool handle_mmio_set_active_reg_redist(struct kvm_vcpu *vcpu,
struct kvm_exit_mmio *mmio,
phys_addr_t offset)
{
struct kvm_vcpu *redist_vcpu = mmio->private;
return vgic_handle_set_active_reg(vcpu->kvm, mmio, offset,
redist_vcpu->vcpu_id);
}
static bool handle_mmio_clear_active_reg_redist(struct kvm_vcpu *vcpu,
struct kvm_exit_mmio *mmio,
phys_addr_t offset)
{
struct kvm_vcpu *redist_vcpu = mmio->private;
return vgic_handle_clear_active_reg(vcpu->kvm, mmio, offset,
redist_vcpu->vcpu_id);
}
static bool handle_mmio_set_pending_reg_redist(struct kvm_vcpu *vcpu,
struct kvm_exit_mmio *mmio,
phys_addr_t offset)
{
struct kvm_vcpu *redist_vcpu = mmio->private;
return vgic_handle_set_pending_reg(vcpu->kvm, mmio, offset,
redist_vcpu->vcpu_id);
}
static bool handle_mmio_clear_pending_reg_redist(struct kvm_vcpu *vcpu,
struct kvm_exit_mmio *mmio,
phys_addr_t offset)
{
struct kvm_vcpu *redist_vcpu = mmio->private;
return vgic_handle_clear_pending_reg(vcpu->kvm, mmio, offset,
redist_vcpu->vcpu_id);
}
static bool handle_mmio_priority_reg_redist(struct kvm_vcpu *vcpu,
struct kvm_exit_mmio *mmio,
phys_addr_t offset)
{
struct kvm_vcpu *redist_vcpu = mmio->private;
u32 *reg;
reg = vgic_bytemap_get_reg(&vcpu->kvm->arch.vgic.irq_priority,
redist_vcpu->vcpu_id, offset);
vgic_reg_access(mmio, reg, offset,
ACCESS_READ_VALUE | ACCESS_WRITE_VALUE);
return false;
}
static bool handle_mmio_cfg_reg_redist(struct kvm_vcpu *vcpu,
struct kvm_exit_mmio *mmio,
phys_addr_t offset)
{
struct kvm_vcpu *redist_vcpu = mmio->private;
u32 *reg = vgic_bitmap_get_reg(&vcpu->kvm->arch.vgic.irq_cfg,
redist_vcpu->vcpu_id, offset >> 1);
return vgic_handle_cfg_reg(reg, mmio, offset);
}
static bool vgic_v3_queue_sgi(struct kvm_vcpu *vcpu, int irq)
{
if (vgic_queue_irq(vcpu, 0, irq)) {
vgic_dist_irq_clear_pending(vcpu, irq);
vgic_cpu_irq_clear(vcpu, irq);
return true;
}
return false;
}
static int vgic_v3_map_resources(struct kvm *kvm,
const struct vgic_params *params)
{
int ret = 0;
struct vgic_dist *dist = &kvm->arch.vgic;
gpa_t rdbase = dist->vgic_redist_base;
struct vgic_io_device *iodevs = NULL;
int i;
if (!irqchip_in_kernel(kvm))
return 0;
mutex_lock(&kvm->lock);
if (vgic_ready(kvm))
goto out;
if (IS_VGIC_ADDR_UNDEF(dist->vgic_dist_base) ||
IS_VGIC_ADDR_UNDEF(dist->vgic_redist_base)) {
kvm_err("Need to set vgic distributor addresses first\n");
ret = -ENXIO;
goto out;
}
if (!vgic_initialized(kvm)) {
ret = -EBUSY;
goto out;
}
ret = vgic_register_kvm_io_dev(kvm, dist->vgic_dist_base,
GIC_V3_DIST_SIZE, vgic_v3_dist_ranges,
-1, &dist->dist_iodev);
if (ret)
goto out;
iodevs = kcalloc(dist->nr_cpus, sizeof(iodevs[0]), GFP_KERNEL);
if (!iodevs) {
ret = -ENOMEM;
goto out_unregister;
}
for (i = 0; i < dist->nr_cpus; i++) {
ret = vgic_register_kvm_io_dev(kvm, rdbase,
SZ_128K, vgic_redist_ranges,
i, &iodevs[i]);
if (ret)
goto out_unregister;
rdbase += GIC_V3_REDIST_SIZE;
}
dist->redist_iodevs = iodevs;
dist->ready = true;
goto out;
out_unregister:
kvm_io_bus_unregister_dev(kvm, KVM_MMIO_BUS, &dist->dist_iodev.dev);
if (iodevs) {
for (i = 0; i < dist->nr_cpus; i++) {
if (iodevs[i].dev.ops)
kvm_io_bus_unregister_dev(kvm, KVM_MMIO_BUS,
&iodevs[i].dev);
}
}
out:
if (ret)
kvm_vgic_destroy(kvm);
mutex_unlock(&kvm->lock);
return ret;
}
static int vgic_v3_init_model(struct kvm *kvm)
{
int i;
u32 mpidr;
struct vgic_dist *dist = &kvm->arch.vgic;
int nr_spis = dist->nr_irqs - VGIC_NR_PRIVATE_IRQS;
dist->irq_spi_mpidr = kcalloc(nr_spis, sizeof(dist->irq_spi_mpidr[0]),
GFP_KERNEL);
if (!dist->irq_spi_mpidr)
return -ENOMEM;
mpidr = compress_mpidr(kvm_vcpu_get_mpidr_aff(kvm_get_vcpu(kvm, 0)));
for (i = VGIC_NR_PRIVATE_IRQS; i < dist->nr_irqs; i++) {
dist->irq_spi_cpu[i - VGIC_NR_PRIVATE_IRQS] = 0;
dist->irq_spi_mpidr[i - VGIC_NR_PRIVATE_IRQS] = mpidr;
vgic_bitmap_set_irq_val(dist->irq_spi_target, 0, i, 1);
}
return 0;
}
static void vgic_v3_add_sgi_source(struct kvm_vcpu *vcpu, int irq, int source)
{
}
void vgic_v3_init_emulation(struct kvm *kvm)
{
struct vgic_dist *dist = &kvm->arch.vgic;
dist->vm_ops.queue_sgi = vgic_v3_queue_sgi;
dist->vm_ops.add_sgi_source = vgic_v3_add_sgi_source;
dist->vm_ops.init_model = vgic_v3_init_model;
dist->vm_ops.map_resources = vgic_v3_map_resources;
kvm->arch.max_vcpus = KVM_MAX_VCPUS;
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
struct vgic_dist *dist = &kvm->arch.vgic;
u16 target_cpus;
u64 mpidr;
int sgi, c;
int vcpu_id = vcpu->vcpu_id;
bool broadcast;
int updated = 0;
sgi = (reg & ICC_SGI1R_SGI_ID_MASK) >> ICC_SGI1R_SGI_ID_SHIFT;
broadcast = reg & BIT(ICC_SGI1R_IRQ_ROUTING_MODE_BIT);
target_cpus = (reg & ICC_SGI1R_TARGET_LIST_MASK) >> ICC_SGI1R_TARGET_LIST_SHIFT;
mpidr = SGI_AFFINITY_LEVEL(reg, 3);
mpidr |= SGI_AFFINITY_LEVEL(reg, 2);
mpidr |= SGI_AFFINITY_LEVEL(reg, 1);
spin_lock(&dist->lock);
kvm_for_each_vcpu(c, c_vcpu, kvm) {
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
vgic_dist_irq_set_pending(c_vcpu, sgi);
updated = 1;
kvm_debug("SGI%d from CPU%d to CPU%d\n", sgi, vcpu_id, c);
}
if (updated)
vgic_update_state(vcpu->kvm);
spin_unlock(&dist->lock);
if (updated)
vgic_kick_vcpus(vcpu->kvm);
}
static int vgic_v3_create(struct kvm_device *dev, u32 type)
{
return kvm_vgic_create(dev->kvm, type);
}
static void vgic_v3_destroy(struct kvm_device *dev)
{
kfree(dev);
}
static int vgic_v3_set_attr(struct kvm_device *dev,
struct kvm_device_attr *attr)
{
int ret;
ret = vgic_set_common_attr(dev, attr);
if (ret != -ENXIO)
return ret;
switch (attr->group) {
case KVM_DEV_ARM_VGIC_GRP_DIST_REGS:
case KVM_DEV_ARM_VGIC_GRP_CPU_REGS:
return -ENXIO;
}
return -ENXIO;
}
static int vgic_v3_get_attr(struct kvm_device *dev,
struct kvm_device_attr *attr)
{
int ret;
ret = vgic_get_common_attr(dev, attr);
if (ret != -ENXIO)
return ret;
switch (attr->group) {
case KVM_DEV_ARM_VGIC_GRP_DIST_REGS:
case KVM_DEV_ARM_VGIC_GRP_CPU_REGS:
return -ENXIO;
}
return -ENXIO;
}
static int vgic_v3_has_attr(struct kvm_device *dev,
struct kvm_device_attr *attr)
{
switch (attr->group) {
case KVM_DEV_ARM_VGIC_GRP_ADDR:
switch (attr->attr) {
case KVM_VGIC_V2_ADDR_TYPE_DIST:
case KVM_VGIC_V2_ADDR_TYPE_CPU:
return -ENXIO;
case KVM_VGIC_V3_ADDR_TYPE_DIST:
case KVM_VGIC_V3_ADDR_TYPE_REDIST:
return 0;
}
break;
case KVM_DEV_ARM_VGIC_GRP_DIST_REGS:
case KVM_DEV_ARM_VGIC_GRP_CPU_REGS:
return -ENXIO;
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
