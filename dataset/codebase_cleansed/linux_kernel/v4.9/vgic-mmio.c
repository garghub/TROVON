unsigned long vgic_mmio_read_raz(struct kvm_vcpu *vcpu,
gpa_t addr, unsigned int len)
{
return 0;
}
unsigned long vgic_mmio_read_rao(struct kvm_vcpu *vcpu,
gpa_t addr, unsigned int len)
{
return -1UL;
}
void vgic_mmio_write_wi(struct kvm_vcpu *vcpu, gpa_t addr,
unsigned int len, unsigned long val)
{
}
unsigned long vgic_mmio_read_enable(struct kvm_vcpu *vcpu,
gpa_t addr, unsigned int len)
{
u32 intid = VGIC_ADDR_TO_INTID(addr, 1);
u32 value = 0;
int i;
for (i = 0; i < len * 8; i++) {
struct vgic_irq *irq = vgic_get_irq(vcpu->kvm, vcpu, intid + i);
if (irq->enabled)
value |= (1U << i);
vgic_put_irq(vcpu->kvm, irq);
}
return value;
}
void vgic_mmio_write_senable(struct kvm_vcpu *vcpu,
gpa_t addr, unsigned int len,
unsigned long val)
{
u32 intid = VGIC_ADDR_TO_INTID(addr, 1);
int i;
for_each_set_bit(i, &val, len * 8) {
struct vgic_irq *irq = vgic_get_irq(vcpu->kvm, vcpu, intid + i);
spin_lock(&irq->irq_lock);
irq->enabled = true;
vgic_queue_irq_unlock(vcpu->kvm, irq);
vgic_put_irq(vcpu->kvm, irq);
}
}
void vgic_mmio_write_cenable(struct kvm_vcpu *vcpu,
gpa_t addr, unsigned int len,
unsigned long val)
{
u32 intid = VGIC_ADDR_TO_INTID(addr, 1);
int i;
for_each_set_bit(i, &val, len * 8) {
struct vgic_irq *irq = vgic_get_irq(vcpu->kvm, vcpu, intid + i);
spin_lock(&irq->irq_lock);
irq->enabled = false;
spin_unlock(&irq->irq_lock);
vgic_put_irq(vcpu->kvm, irq);
}
}
unsigned long vgic_mmio_read_pending(struct kvm_vcpu *vcpu,
gpa_t addr, unsigned int len)
{
u32 intid = VGIC_ADDR_TO_INTID(addr, 1);
u32 value = 0;
int i;
for (i = 0; i < len * 8; i++) {
struct vgic_irq *irq = vgic_get_irq(vcpu->kvm, vcpu, intid + i);
if (irq->pending)
value |= (1U << i);
vgic_put_irq(vcpu->kvm, irq);
}
return value;
}
void vgic_mmio_write_spending(struct kvm_vcpu *vcpu,
gpa_t addr, unsigned int len,
unsigned long val)
{
u32 intid = VGIC_ADDR_TO_INTID(addr, 1);
int i;
for_each_set_bit(i, &val, len * 8) {
struct vgic_irq *irq = vgic_get_irq(vcpu->kvm, vcpu, intid + i);
spin_lock(&irq->irq_lock);
irq->pending = true;
if (irq->config == VGIC_CONFIG_LEVEL)
irq->soft_pending = true;
vgic_queue_irq_unlock(vcpu->kvm, irq);
vgic_put_irq(vcpu->kvm, irq);
}
}
void vgic_mmio_write_cpending(struct kvm_vcpu *vcpu,
gpa_t addr, unsigned int len,
unsigned long val)
{
u32 intid = VGIC_ADDR_TO_INTID(addr, 1);
int i;
for_each_set_bit(i, &val, len * 8) {
struct vgic_irq *irq = vgic_get_irq(vcpu->kvm, vcpu, intid + i);
spin_lock(&irq->irq_lock);
if (irq->config == VGIC_CONFIG_LEVEL) {
irq->soft_pending = false;
irq->pending = irq->line_level;
} else {
irq->pending = false;
}
spin_unlock(&irq->irq_lock);
vgic_put_irq(vcpu->kvm, irq);
}
}
unsigned long vgic_mmio_read_active(struct kvm_vcpu *vcpu,
gpa_t addr, unsigned int len)
{
u32 intid = VGIC_ADDR_TO_INTID(addr, 1);
u32 value = 0;
int i;
for (i = 0; i < len * 8; i++) {
struct vgic_irq *irq = vgic_get_irq(vcpu->kvm, vcpu, intid + i);
if (irq->active)
value |= (1U << i);
vgic_put_irq(vcpu->kvm, irq);
}
return value;
}
static void vgic_mmio_change_active(struct kvm_vcpu *vcpu, struct vgic_irq *irq,
bool new_active_state)
{
spin_lock(&irq->irq_lock);
while (irq->vcpu &&
irq->vcpu->cpu != -1)
cond_resched_lock(&irq->irq_lock);
irq->active = new_active_state;
if (new_active_state)
vgic_queue_irq_unlock(vcpu->kvm, irq);
else
spin_unlock(&irq->irq_lock);
}
static void vgic_change_active_prepare(struct kvm_vcpu *vcpu, u32 intid)
{
if (intid < VGIC_NR_PRIVATE_IRQS)
kvm_arm_halt_vcpu(vcpu);
else
kvm_arm_halt_guest(vcpu->kvm);
}
static void vgic_change_active_finish(struct kvm_vcpu *vcpu, u32 intid)
{
if (intid < VGIC_NR_PRIVATE_IRQS)
kvm_arm_resume_vcpu(vcpu);
else
kvm_arm_resume_guest(vcpu->kvm);
}
void vgic_mmio_write_cactive(struct kvm_vcpu *vcpu,
gpa_t addr, unsigned int len,
unsigned long val)
{
u32 intid = VGIC_ADDR_TO_INTID(addr, 1);
int i;
vgic_change_active_prepare(vcpu, intid);
for_each_set_bit(i, &val, len * 8) {
struct vgic_irq *irq = vgic_get_irq(vcpu->kvm, vcpu, intid + i);
vgic_mmio_change_active(vcpu, irq, false);
vgic_put_irq(vcpu->kvm, irq);
}
vgic_change_active_finish(vcpu, intid);
}
void vgic_mmio_write_sactive(struct kvm_vcpu *vcpu,
gpa_t addr, unsigned int len,
unsigned long val)
{
u32 intid = VGIC_ADDR_TO_INTID(addr, 1);
int i;
vgic_change_active_prepare(vcpu, intid);
for_each_set_bit(i, &val, len * 8) {
struct vgic_irq *irq = vgic_get_irq(vcpu->kvm, vcpu, intid + i);
vgic_mmio_change_active(vcpu, irq, true);
vgic_put_irq(vcpu->kvm, irq);
}
vgic_change_active_finish(vcpu, intid);
}
unsigned long vgic_mmio_read_priority(struct kvm_vcpu *vcpu,
gpa_t addr, unsigned int len)
{
u32 intid = VGIC_ADDR_TO_INTID(addr, 8);
int i;
u64 val = 0;
for (i = 0; i < len; i++) {
struct vgic_irq *irq = vgic_get_irq(vcpu->kvm, vcpu, intid + i);
val |= (u64)irq->priority << (i * 8);
vgic_put_irq(vcpu->kvm, irq);
}
return val;
}
void vgic_mmio_write_priority(struct kvm_vcpu *vcpu,
gpa_t addr, unsigned int len,
unsigned long val)
{
u32 intid = VGIC_ADDR_TO_INTID(addr, 8);
int i;
for (i = 0; i < len; i++) {
struct vgic_irq *irq = vgic_get_irq(vcpu->kvm, vcpu, intid + i);
spin_lock(&irq->irq_lock);
irq->priority = (val >> (i * 8)) & GENMASK(7, 8 - VGIC_PRI_BITS);
spin_unlock(&irq->irq_lock);
vgic_put_irq(vcpu->kvm, irq);
}
}
unsigned long vgic_mmio_read_config(struct kvm_vcpu *vcpu,
gpa_t addr, unsigned int len)
{
u32 intid = VGIC_ADDR_TO_INTID(addr, 2);
u32 value = 0;
int i;
for (i = 0; i < len * 4; i++) {
struct vgic_irq *irq = vgic_get_irq(vcpu->kvm, vcpu, intid + i);
if (irq->config == VGIC_CONFIG_EDGE)
value |= (2U << (i * 2));
vgic_put_irq(vcpu->kvm, irq);
}
return value;
}
void vgic_mmio_write_config(struct kvm_vcpu *vcpu,
gpa_t addr, unsigned int len,
unsigned long val)
{
u32 intid = VGIC_ADDR_TO_INTID(addr, 2);
int i;
for (i = 0; i < len * 4; i++) {
struct vgic_irq *irq;
if (intid + i < VGIC_NR_PRIVATE_IRQS)
continue;
irq = vgic_get_irq(vcpu->kvm, vcpu, intid + i);
spin_lock(&irq->irq_lock);
if (test_bit(i * 2 + 1, &val)) {
irq->config = VGIC_CONFIG_EDGE;
} else {
irq->config = VGIC_CONFIG_LEVEL;
irq->pending = irq->line_level | irq->soft_pending;
}
spin_unlock(&irq->irq_lock);
vgic_put_irq(vcpu->kvm, irq);
}
}
static int match_region(const void *key, const void *elt)
{
const unsigned int offset = (unsigned long)key;
const struct vgic_register_region *region = elt;
if (offset < region->reg_offset)
return -1;
if (offset >= region->reg_offset + region->len)
return 1;
return 0;
}
static const struct vgic_register_region *
vgic_find_mmio_region(const struct vgic_register_region *region, int nr_regions,
unsigned int offset)
{
return bsearch((void *)(uintptr_t)offset, region, nr_regions,
sizeof(region[0]), match_region);
}
unsigned long vgic_data_mmio_bus_to_host(const void *val, unsigned int len)
{
unsigned long data = kvm_mmio_read_buf(val, len);
switch (len) {
case 1:
return data;
case 2:
return le16_to_cpu(data);
case 4:
return le32_to_cpu(data);
default:
return le64_to_cpu(data);
}
}
void vgic_data_host_to_mmio_bus(void *buf, unsigned int len,
unsigned long data)
{
switch (len) {
case 1:
break;
case 2:
data = cpu_to_le16(data);
break;
case 4:
data = cpu_to_le32(data);
break;
default:
data = cpu_to_le64(data);
}
kvm_mmio_write_buf(buf, len, data);
}
static
struct vgic_io_device *kvm_to_vgic_iodev(const struct kvm_io_device *dev)
{
return container_of(dev, struct vgic_io_device, dev);
}
static bool check_region(const struct kvm *kvm,
const struct vgic_register_region *region,
gpa_t addr, int len)
{
int flags, nr_irqs = kvm->arch.vgic.nr_spis + VGIC_NR_PRIVATE_IRQS;
switch (len) {
case sizeof(u8):
flags = VGIC_ACCESS_8bit;
break;
case sizeof(u32):
flags = VGIC_ACCESS_32bit;
break;
case sizeof(u64):
flags = VGIC_ACCESS_64bit;
break;
default:
return false;
}
if ((region->access_flags & flags) && IS_ALIGNED(addr, len)) {
if (!region->bits_per_irq)
return true;
return VGIC_ADDR_TO_INTID(addr, region->bits_per_irq) < nr_irqs;
}
return false;
}
static int dispatch_mmio_read(struct kvm_vcpu *vcpu, struct kvm_io_device *dev,
gpa_t addr, int len, void *val)
{
struct vgic_io_device *iodev = kvm_to_vgic_iodev(dev);
const struct vgic_register_region *region;
unsigned long data = 0;
region = vgic_find_mmio_region(iodev->regions, iodev->nr_regions,
addr - iodev->base_addr);
if (!region || !check_region(vcpu->kvm, region, addr, len)) {
memset(val, 0, len);
return 0;
}
switch (iodev->iodev_type) {
case IODEV_CPUIF:
data = region->read(vcpu, addr, len);
break;
case IODEV_DIST:
data = region->read(vcpu, addr, len);
break;
case IODEV_REDIST:
data = region->read(iodev->redist_vcpu, addr, len);
break;
case IODEV_ITS:
data = region->its_read(vcpu->kvm, iodev->its, addr, len);
break;
}
vgic_data_host_to_mmio_bus(val, len, data);
return 0;
}
static int dispatch_mmio_write(struct kvm_vcpu *vcpu, struct kvm_io_device *dev,
gpa_t addr, int len, const void *val)
{
struct vgic_io_device *iodev = kvm_to_vgic_iodev(dev);
const struct vgic_register_region *region;
unsigned long data = vgic_data_mmio_bus_to_host(val, len);
region = vgic_find_mmio_region(iodev->regions, iodev->nr_regions,
addr - iodev->base_addr);
if (!region || !check_region(vcpu->kvm, region, addr, len))
return 0;
switch (iodev->iodev_type) {
case IODEV_CPUIF:
region->write(vcpu, addr, len, data);
break;
case IODEV_DIST:
region->write(vcpu, addr, len, data);
break;
case IODEV_REDIST:
region->write(iodev->redist_vcpu, addr, len, data);
break;
case IODEV_ITS:
region->its_write(vcpu->kvm, iodev->its, addr, len, data);
break;
}
return 0;
}
int vgic_register_dist_iodev(struct kvm *kvm, gpa_t dist_base_address,
enum vgic_type type)
{
struct vgic_io_device *io_device = &kvm->arch.vgic.dist_iodev;
int ret = 0;
unsigned int len;
switch (type) {
case VGIC_V2:
len = vgic_v2_init_dist_iodev(io_device);
break;
case VGIC_V3:
len = vgic_v3_init_dist_iodev(io_device);
break;
default:
BUG_ON(1);
}
io_device->base_addr = dist_base_address;
io_device->iodev_type = IODEV_DIST;
io_device->redist_vcpu = NULL;
mutex_lock(&kvm->slots_lock);
ret = kvm_io_bus_register_dev(kvm, KVM_MMIO_BUS, dist_base_address,
len, &io_device->dev);
mutex_unlock(&kvm->slots_lock);
return ret;
}
