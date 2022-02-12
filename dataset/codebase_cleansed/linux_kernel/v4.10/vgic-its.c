static struct vgic_irq *vgic_add_lpi(struct kvm *kvm, u32 intid)
{
struct vgic_dist *dist = &kvm->arch.vgic;
struct vgic_irq *irq = vgic_get_irq(kvm, NULL, intid), *oldirq;
if (irq)
return irq;
irq = kzalloc(sizeof(struct vgic_irq), GFP_KERNEL);
if (!irq)
return ERR_PTR(-ENOMEM);
INIT_LIST_HEAD(&irq->lpi_list);
INIT_LIST_HEAD(&irq->ap_list);
spin_lock_init(&irq->irq_lock);
irq->config = VGIC_CONFIG_EDGE;
kref_init(&irq->refcount);
irq->intid = intid;
spin_lock(&dist->lpi_list_lock);
list_for_each_entry(oldirq, &dist->lpi_list_head, lpi_list) {
if (oldirq->intid != intid)
continue;
kfree(irq);
irq = oldirq;
vgic_get_irq_kref(irq);
goto out_unlock;
}
list_add_tail(&irq->lpi_list, &dist->lpi_list_head);
dist->lpi_list_count++;
out_unlock:
spin_unlock(&dist->lpi_list_lock);
return irq;
}
static struct its_device *find_its_device(struct vgic_its *its, u32 device_id)
{
struct its_device *device;
list_for_each_entry(device, &its->device_list, dev_list)
if (device_id == device->device_id)
return device;
return NULL;
}
static struct its_itte *find_itte(struct vgic_its *its, u32 device_id,
u32 event_id)
{
struct its_device *device;
struct its_itte *itte;
device = find_its_device(its, device_id);
if (device == NULL)
return NULL;
list_for_each_entry(itte, &device->itt_head, itte_list)
if (itte->event_id == event_id)
return itte;
return NULL;
}
static struct its_collection *find_collection(struct vgic_its *its, int coll_id)
{
struct its_collection *collection;
list_for_each_entry(collection, &its->collection_list, coll_list) {
if (coll_id == collection->collection_id)
return collection;
}
return NULL;
}
static int update_lpi_config(struct kvm *kvm, struct vgic_irq *irq,
struct kvm_vcpu *filter_vcpu)
{
u64 propbase = PROPBASER_ADDRESS(kvm->arch.vgic.propbaser);
u8 prop;
int ret;
ret = kvm_read_guest(kvm, propbase + irq->intid - GIC_LPI_OFFSET,
&prop, 1);
if (ret)
return ret;
spin_lock(&irq->irq_lock);
if (!filter_vcpu || filter_vcpu == irq->target_vcpu) {
irq->priority = LPI_PROP_PRIORITY(prop);
irq->enabled = LPI_PROP_ENABLE_BIT(prop);
vgic_queue_irq_unlock(kvm, irq);
} else {
spin_unlock(&irq->irq_lock);
}
return 0;
}
static int vgic_copy_lpi_list(struct kvm *kvm, u32 **intid_ptr)
{
struct vgic_dist *dist = &kvm->arch.vgic;
struct vgic_irq *irq;
u32 *intids;
int irq_count = dist->lpi_list_count, i = 0;
intids = kmalloc_array(irq_count, sizeof(intids[0]), GFP_KERNEL);
if (!intids)
return -ENOMEM;
spin_lock(&dist->lpi_list_lock);
list_for_each_entry(irq, &dist->lpi_list_head, lpi_list) {
intids[i] = irq->intid;
if (++i == irq_count)
break;
}
spin_unlock(&dist->lpi_list_lock);
*intid_ptr = intids;
return irq_count;
}
static void update_affinity_itte(struct kvm *kvm, struct its_itte *itte)
{
struct kvm_vcpu *vcpu;
if (!its_is_collection_mapped(itte->collection))
return;
vcpu = kvm_get_vcpu(kvm, itte->collection->target_addr);
spin_lock(&itte->irq->irq_lock);
itte->irq->target_vcpu = vcpu;
spin_unlock(&itte->irq->irq_lock);
}
static void update_affinity_collection(struct kvm *kvm, struct vgic_its *its,
struct its_collection *coll)
{
struct its_device *device;
struct its_itte *itte;
for_each_lpi_its(device, itte, its) {
if (!itte->collection || coll != itte->collection)
continue;
update_affinity_itte(kvm, itte);
}
}
static u32 max_lpis_propbaser(u64 propbaser)
{
int nr_idbits = (propbaser & 0x1f) + 1;
return 1U << min(nr_idbits, INTERRUPT_ID_BITS_ITS);
}
static int its_sync_lpi_pending_table(struct kvm_vcpu *vcpu)
{
gpa_t pendbase = PENDBASER_ADDRESS(vcpu->arch.vgic_cpu.pendbaser);
struct vgic_irq *irq;
int last_byte_offset = -1;
int ret = 0;
u32 *intids;
int nr_irqs, i;
nr_irqs = vgic_copy_lpi_list(vcpu->kvm, &intids);
if (nr_irqs < 0)
return nr_irqs;
for (i = 0; i < nr_irqs; i++) {
int byte_offset, bit_nr;
u8 pendmask;
byte_offset = intids[i] / BITS_PER_BYTE;
bit_nr = intids[i] % BITS_PER_BYTE;
if (byte_offset != last_byte_offset) {
ret = kvm_read_guest(vcpu->kvm, pendbase + byte_offset,
&pendmask, 1);
if (ret) {
kfree(intids);
return ret;
}
last_byte_offset = byte_offset;
}
irq = vgic_get_irq(vcpu->kvm, NULL, intids[i]);
spin_lock(&irq->irq_lock);
irq->pending = pendmask & (1U << bit_nr);
vgic_queue_irq_unlock(vcpu->kvm, irq);
vgic_put_irq(vcpu->kvm, irq);
}
kfree(intids);
return ret;
}
static unsigned long vgic_mmio_read_its_ctlr(struct kvm *vcpu,
struct vgic_its *its,
gpa_t addr, unsigned int len)
{
u32 reg = 0;
mutex_lock(&its->cmd_lock);
if (its->creadr == its->cwriter)
reg |= GITS_CTLR_QUIESCENT;
if (its->enabled)
reg |= GITS_CTLR_ENABLE;
mutex_unlock(&its->cmd_lock);
return reg;
}
static void vgic_mmio_write_its_ctlr(struct kvm *kvm, struct vgic_its *its,
gpa_t addr, unsigned int len,
unsigned long val)
{
its->enabled = !!(val & GITS_CTLR_ENABLE);
}
static unsigned long vgic_mmio_read_its_typer(struct kvm *kvm,
struct vgic_its *its,
gpa_t addr, unsigned int len)
{
u64 reg = GITS_TYPER_PLPIS;
reg |= 0x0f << GITS_TYPER_DEVBITS_SHIFT;
reg |= 0x0f << GITS_TYPER_IDBITS_SHIFT;
return extract_bytes(reg, addr & 7, len);
}
static unsigned long vgic_mmio_read_its_iidr(struct kvm *kvm,
struct vgic_its *its,
gpa_t addr, unsigned int len)
{
return (PRODUCT_ID_KVM << 24) | (IMPLEMENTER_ARM << 0);
}
static unsigned long vgic_mmio_read_its_idregs(struct kvm *kvm,
struct vgic_its *its,
gpa_t addr, unsigned int len)
{
switch (addr & 0xffff) {
case GITS_PIDR0:
return 0x92;
case GITS_PIDR1:
return 0xb4;
case GITS_PIDR2:
return GIC_PIDR2_ARCH_GICv3 | 0x0b;
case GITS_PIDR4:
return 0x40;
case GITS_CIDR0:
return 0x0d;
case GITS_CIDR1:
return 0xf0;
case GITS_CIDR2:
return 0x05;
case GITS_CIDR3:
return 0xb1;
}
return 0;
}
static int vgic_its_trigger_msi(struct kvm *kvm, struct vgic_its *its,
u32 devid, u32 eventid)
{
struct kvm_vcpu *vcpu;
struct its_itte *itte;
if (!its->enabled)
return -EBUSY;
itte = find_itte(its, devid, eventid);
if (!itte || !its_is_collection_mapped(itte->collection))
return E_ITS_INT_UNMAPPED_INTERRUPT;
vcpu = kvm_get_vcpu(kvm, itte->collection->target_addr);
if (!vcpu)
return E_ITS_INT_UNMAPPED_INTERRUPT;
if (!vcpu->arch.vgic_cpu.lpis_enabled)
return -EBUSY;
spin_lock(&itte->irq->irq_lock);
itte->irq->pending = true;
vgic_queue_irq_unlock(kvm, itte->irq);
return 0;
}
static struct vgic_io_device *vgic_get_its_iodev(struct kvm_io_device *dev)
{
struct vgic_io_device *iodev;
if (dev->ops != &kvm_io_gic_ops)
return NULL;
iodev = container_of(dev, struct vgic_io_device, dev);
if (iodev->iodev_type != IODEV_ITS)
return NULL;
return iodev;
}
int vgic_its_inject_msi(struct kvm *kvm, struct kvm_msi *msi)
{
u64 address;
struct kvm_io_device *kvm_io_dev;
struct vgic_io_device *iodev;
int ret;
if (!vgic_has_its(kvm))
return -ENODEV;
if (!(msi->flags & KVM_MSI_VALID_DEVID))
return -EINVAL;
address = (u64)msi->address_hi << 32 | msi->address_lo;
kvm_io_dev = kvm_io_bus_get_dev(kvm, KVM_MMIO_BUS, address);
if (!kvm_io_dev)
return -EINVAL;
iodev = vgic_get_its_iodev(kvm_io_dev);
if (!iodev)
return -EINVAL;
mutex_lock(&iodev->its->its_lock);
ret = vgic_its_trigger_msi(kvm, iodev->its, msi->devid, msi->data);
mutex_unlock(&iodev->its->its_lock);
if (ret < 0)
return ret;
if (ret)
return 0;
else
return 1;
}
static void its_free_itte(struct kvm *kvm, struct its_itte *itte)
{
list_del(&itte->itte_list);
if (itte->irq)
vgic_put_irq(kvm, itte->irq);
kfree(itte);
}
static u64 its_cmd_mask_field(u64 *its_cmd, int word, int shift, int size)
{
return (le64_to_cpu(its_cmd[word]) >> shift) & (BIT_ULL(size) - 1);
}
static int vgic_its_cmd_handle_discard(struct kvm *kvm, struct vgic_its *its,
u64 *its_cmd)
{
u32 device_id = its_cmd_get_deviceid(its_cmd);
u32 event_id = its_cmd_get_id(its_cmd);
struct its_itte *itte;
itte = find_itte(its, device_id, event_id);
if (itte && itte->collection) {
its_free_itte(kvm, itte);
return 0;
}
return E_ITS_DISCARD_UNMAPPED_INTERRUPT;
}
static int vgic_its_cmd_handle_movi(struct kvm *kvm, struct vgic_its *its,
u64 *its_cmd)
{
u32 device_id = its_cmd_get_deviceid(its_cmd);
u32 event_id = its_cmd_get_id(its_cmd);
u32 coll_id = its_cmd_get_collection(its_cmd);
struct kvm_vcpu *vcpu;
struct its_itte *itte;
struct its_collection *collection;
itte = find_itte(its, device_id, event_id);
if (!itte)
return E_ITS_MOVI_UNMAPPED_INTERRUPT;
if (!its_is_collection_mapped(itte->collection))
return E_ITS_MOVI_UNMAPPED_COLLECTION;
collection = find_collection(its, coll_id);
if (!its_is_collection_mapped(collection))
return E_ITS_MOVI_UNMAPPED_COLLECTION;
itte->collection = collection;
vcpu = kvm_get_vcpu(kvm, collection->target_addr);
spin_lock(&itte->irq->irq_lock);
itte->irq->target_vcpu = vcpu;
spin_unlock(&itte->irq->irq_lock);
return 0;
}
static bool vgic_its_check_id(struct vgic_its *its, u64 baser, int id)
{
int l1_tbl_size = GITS_BASER_NR_PAGES(baser) * SZ_64K;
int index;
u64 indirect_ptr;
gfn_t gfn;
int esz = GITS_BASER_ENTRY_SIZE(baser);
if (!(baser & GITS_BASER_INDIRECT)) {
phys_addr_t addr;
if (id >= (l1_tbl_size / esz))
return false;
addr = BASER_ADDRESS(baser) + id * esz;
gfn = addr >> PAGE_SHIFT;
return kvm_is_visible_gfn(its->dev->kvm, gfn);
}
index = id / (SZ_64K / esz);
if (index >= (l1_tbl_size / sizeof(u64)))
return false;
if (kvm_read_guest(its->dev->kvm,
BASER_ADDRESS(baser) + index * sizeof(indirect_ptr),
&indirect_ptr, sizeof(indirect_ptr)))
return false;
indirect_ptr = le64_to_cpu(indirect_ptr);
if (!(indirect_ptr & BIT_ULL(63)))
return false;
indirect_ptr &= GENMASK_ULL(51, 16);
index = id % (SZ_64K / esz);
indirect_ptr += index * esz;
gfn = indirect_ptr >> PAGE_SHIFT;
return kvm_is_visible_gfn(its->dev->kvm, gfn);
}
static int vgic_its_alloc_collection(struct vgic_its *its,
struct its_collection **colp,
u32 coll_id)
{
struct its_collection *collection;
if (!vgic_its_check_id(its, its->baser_coll_table, coll_id))
return E_ITS_MAPC_COLLECTION_OOR;
collection = kzalloc(sizeof(*collection), GFP_KERNEL);
collection->collection_id = coll_id;
collection->target_addr = COLLECTION_NOT_MAPPED;
list_add_tail(&collection->coll_list, &its->collection_list);
*colp = collection;
return 0;
}
static void vgic_its_free_collection(struct vgic_its *its, u32 coll_id)
{
struct its_collection *collection;
struct its_device *device;
struct its_itte *itte;
collection = find_collection(its, coll_id);
if (!collection)
return;
for_each_lpi_its(device, itte, its)
if (itte->collection &&
itte->collection->collection_id == coll_id)
itte->collection = NULL;
list_del(&collection->coll_list);
kfree(collection);
}
static int vgic_its_cmd_handle_mapi(struct kvm *kvm, struct vgic_its *its,
u64 *its_cmd)
{
u32 device_id = its_cmd_get_deviceid(its_cmd);
u32 event_id = its_cmd_get_id(its_cmd);
u32 coll_id = its_cmd_get_collection(its_cmd);
struct its_itte *itte;
struct its_device *device;
struct its_collection *collection, *new_coll = NULL;
int lpi_nr;
struct vgic_irq *irq;
device = find_its_device(its, device_id);
if (!device)
return E_ITS_MAPTI_UNMAPPED_DEVICE;
if (its_cmd_get_command(its_cmd) == GITS_CMD_MAPTI)
lpi_nr = its_cmd_get_physical_id(its_cmd);
else
lpi_nr = event_id;
if (lpi_nr < GIC_LPI_OFFSET ||
lpi_nr >= max_lpis_propbaser(kvm->arch.vgic.propbaser))
return E_ITS_MAPTI_PHYSICALID_OOR;
if (find_itte(its, device_id, event_id))
return 0;
collection = find_collection(its, coll_id);
if (!collection) {
int ret = vgic_its_alloc_collection(its, &collection, coll_id);
if (ret)
return ret;
new_coll = collection;
}
itte = kzalloc(sizeof(struct its_itte), GFP_KERNEL);
if (!itte) {
if (new_coll)
vgic_its_free_collection(its, coll_id);
return -ENOMEM;
}
itte->event_id = event_id;
list_add_tail(&itte->itte_list, &device->itt_head);
itte->collection = collection;
itte->lpi = lpi_nr;
irq = vgic_add_lpi(kvm, lpi_nr);
if (IS_ERR(irq)) {
if (new_coll)
vgic_its_free_collection(its, coll_id);
its_free_itte(kvm, itte);
return PTR_ERR(irq);
}
itte->irq = irq;
update_affinity_itte(kvm, itte);
update_lpi_config(kvm, itte->irq, NULL);
return 0;
}
static void vgic_its_unmap_device(struct kvm *kvm, struct its_device *device)
{
struct its_itte *itte, *temp;
list_for_each_entry_safe(itte, temp, &device->itt_head, itte_list)
its_free_itte(kvm, itte);
list_del(&device->dev_list);
kfree(device);
}
static int vgic_its_cmd_handle_mapd(struct kvm *kvm, struct vgic_its *its,
u64 *its_cmd)
{
u32 device_id = its_cmd_get_deviceid(its_cmd);
bool valid = its_cmd_get_validbit(its_cmd);
struct its_device *device;
if (!vgic_its_check_id(its, its->baser_device_table, device_id))
return E_ITS_MAPD_DEVICE_OOR;
device = find_its_device(its, device_id);
if (device)
vgic_its_unmap_device(kvm, device);
if (!valid)
return 0;
device = kzalloc(sizeof(struct its_device), GFP_KERNEL);
if (!device)
return -ENOMEM;
device->device_id = device_id;
INIT_LIST_HEAD(&device->itt_head);
list_add_tail(&device->dev_list, &its->device_list);
return 0;
}
static int vgic_its_cmd_handle_mapc(struct kvm *kvm, struct vgic_its *its,
u64 *its_cmd)
{
u16 coll_id;
u32 target_addr;
struct its_collection *collection;
bool valid;
valid = its_cmd_get_validbit(its_cmd);
coll_id = its_cmd_get_collection(its_cmd);
target_addr = its_cmd_get_target_addr(its_cmd);
if (target_addr >= atomic_read(&kvm->online_vcpus))
return E_ITS_MAPC_PROCNUM_OOR;
if (!valid) {
vgic_its_free_collection(its, coll_id);
} else {
collection = find_collection(its, coll_id);
if (!collection) {
int ret;
ret = vgic_its_alloc_collection(its, &collection,
coll_id);
if (ret)
return ret;
collection->target_addr = target_addr;
} else {
collection->target_addr = target_addr;
update_affinity_collection(kvm, its, collection);
}
}
return 0;
}
static int vgic_its_cmd_handle_clear(struct kvm *kvm, struct vgic_its *its,
u64 *its_cmd)
{
u32 device_id = its_cmd_get_deviceid(its_cmd);
u32 event_id = its_cmd_get_id(its_cmd);
struct its_itte *itte;
itte = find_itte(its, device_id, event_id);
if (!itte)
return E_ITS_CLEAR_UNMAPPED_INTERRUPT;
itte->irq->pending = false;
return 0;
}
static int vgic_its_cmd_handle_inv(struct kvm *kvm, struct vgic_its *its,
u64 *its_cmd)
{
u32 device_id = its_cmd_get_deviceid(its_cmd);
u32 event_id = its_cmd_get_id(its_cmd);
struct its_itte *itte;
itte = find_itte(its, device_id, event_id);
if (!itte)
return E_ITS_INV_UNMAPPED_INTERRUPT;
return update_lpi_config(kvm, itte->irq, NULL);
}
static int vgic_its_cmd_handle_invall(struct kvm *kvm, struct vgic_its *its,
u64 *its_cmd)
{
u32 coll_id = its_cmd_get_collection(its_cmd);
struct its_collection *collection;
struct kvm_vcpu *vcpu;
struct vgic_irq *irq;
u32 *intids;
int irq_count, i;
collection = find_collection(its, coll_id);
if (!its_is_collection_mapped(collection))
return E_ITS_INVALL_UNMAPPED_COLLECTION;
vcpu = kvm_get_vcpu(kvm, collection->target_addr);
irq_count = vgic_copy_lpi_list(kvm, &intids);
if (irq_count < 0)
return irq_count;
for (i = 0; i < irq_count; i++) {
irq = vgic_get_irq(kvm, NULL, intids[i]);
if (!irq)
continue;
update_lpi_config(kvm, irq, vcpu);
vgic_put_irq(kvm, irq);
}
kfree(intids);
return 0;
}
static int vgic_its_cmd_handle_movall(struct kvm *kvm, struct vgic_its *its,
u64 *its_cmd)
{
struct vgic_dist *dist = &kvm->arch.vgic;
u32 target1_addr = its_cmd_get_target_addr(its_cmd);
u32 target2_addr = its_cmd_mask_field(its_cmd, 3, 16, 32);
struct kvm_vcpu *vcpu1, *vcpu2;
struct vgic_irq *irq;
if (target1_addr >= atomic_read(&kvm->online_vcpus) ||
target2_addr >= atomic_read(&kvm->online_vcpus))
return E_ITS_MOVALL_PROCNUM_OOR;
if (target1_addr == target2_addr)
return 0;
vcpu1 = kvm_get_vcpu(kvm, target1_addr);
vcpu2 = kvm_get_vcpu(kvm, target2_addr);
spin_lock(&dist->lpi_list_lock);
list_for_each_entry(irq, &dist->lpi_list_head, lpi_list) {
spin_lock(&irq->irq_lock);
if (irq->target_vcpu == vcpu1)
irq->target_vcpu = vcpu2;
spin_unlock(&irq->irq_lock);
}
spin_unlock(&dist->lpi_list_lock);
return 0;
}
static int vgic_its_cmd_handle_int(struct kvm *kvm, struct vgic_its *its,
u64 *its_cmd)
{
u32 msi_data = its_cmd_get_id(its_cmd);
u64 msi_devid = its_cmd_get_deviceid(its_cmd);
return vgic_its_trigger_msi(kvm, its, msi_devid, msi_data);
}
static int vgic_its_handle_command(struct kvm *kvm, struct vgic_its *its,
u64 *its_cmd)
{
int ret = -ENODEV;
mutex_lock(&its->its_lock);
switch (its_cmd_get_command(its_cmd)) {
case GITS_CMD_MAPD:
ret = vgic_its_cmd_handle_mapd(kvm, its, its_cmd);
break;
case GITS_CMD_MAPC:
ret = vgic_its_cmd_handle_mapc(kvm, its, its_cmd);
break;
case GITS_CMD_MAPI:
ret = vgic_its_cmd_handle_mapi(kvm, its, its_cmd);
break;
case GITS_CMD_MAPTI:
ret = vgic_its_cmd_handle_mapi(kvm, its, its_cmd);
break;
case GITS_CMD_MOVI:
ret = vgic_its_cmd_handle_movi(kvm, its, its_cmd);
break;
case GITS_CMD_DISCARD:
ret = vgic_its_cmd_handle_discard(kvm, its, its_cmd);
break;
case GITS_CMD_CLEAR:
ret = vgic_its_cmd_handle_clear(kvm, its, its_cmd);
break;
case GITS_CMD_MOVALL:
ret = vgic_its_cmd_handle_movall(kvm, its, its_cmd);
break;
case GITS_CMD_INT:
ret = vgic_its_cmd_handle_int(kvm, its, its_cmd);
break;
case GITS_CMD_INV:
ret = vgic_its_cmd_handle_inv(kvm, its, its_cmd);
break;
case GITS_CMD_INVALL:
ret = vgic_its_cmd_handle_invall(kvm, its, its_cmd);
break;
case GITS_CMD_SYNC:
ret = 0;
break;
}
mutex_unlock(&its->its_lock);
return ret;
}
static u64 vgic_sanitise_its_baser(u64 reg)
{
reg = vgic_sanitise_field(reg, GITS_BASER_SHAREABILITY_MASK,
GITS_BASER_SHAREABILITY_SHIFT,
vgic_sanitise_shareability);
reg = vgic_sanitise_field(reg, GITS_BASER_INNER_CACHEABILITY_MASK,
GITS_BASER_INNER_CACHEABILITY_SHIFT,
vgic_sanitise_inner_cacheability);
reg = vgic_sanitise_field(reg, GITS_BASER_OUTER_CACHEABILITY_MASK,
GITS_BASER_OUTER_CACHEABILITY_SHIFT,
vgic_sanitise_outer_cacheability);
reg &= ~GENMASK_ULL(15, 12);
reg = (reg & ~GITS_BASER_PAGE_SIZE_MASK) | GITS_BASER_PAGE_SIZE_64K;
return reg;
}
static u64 vgic_sanitise_its_cbaser(u64 reg)
{
reg = vgic_sanitise_field(reg, GITS_CBASER_SHAREABILITY_MASK,
GITS_CBASER_SHAREABILITY_SHIFT,
vgic_sanitise_shareability);
reg = vgic_sanitise_field(reg, GITS_CBASER_INNER_CACHEABILITY_MASK,
GITS_CBASER_INNER_CACHEABILITY_SHIFT,
vgic_sanitise_inner_cacheability);
reg = vgic_sanitise_field(reg, GITS_CBASER_OUTER_CACHEABILITY_MASK,
GITS_CBASER_OUTER_CACHEABILITY_SHIFT,
vgic_sanitise_outer_cacheability);
reg &= ~(GENMASK_ULL(51, 48) | GENMASK_ULL(15, 12));
return reg;
}
static unsigned long vgic_mmio_read_its_cbaser(struct kvm *kvm,
struct vgic_its *its,
gpa_t addr, unsigned int len)
{
return extract_bytes(its->cbaser, addr & 7, len);
}
static void vgic_mmio_write_its_cbaser(struct kvm *kvm, struct vgic_its *its,
gpa_t addr, unsigned int len,
unsigned long val)
{
if (its->enabled)
return;
mutex_lock(&its->cmd_lock);
its->cbaser = update_64bit_reg(its->cbaser, addr & 7, len, val);
its->cbaser = vgic_sanitise_its_cbaser(its->cbaser);
its->creadr = 0;
its->cwriter = its->creadr;
mutex_unlock(&its->cmd_lock);
}
static void vgic_mmio_write_its_cwriter(struct kvm *kvm, struct vgic_its *its,
gpa_t addr, unsigned int len,
unsigned long val)
{
gpa_t cbaser;
u64 cmd_buf[4];
u32 reg;
if (!its)
return;
mutex_lock(&its->cmd_lock);
reg = update_64bit_reg(its->cwriter, addr & 7, len, val);
reg = ITS_CMD_OFFSET(reg);
if (reg >= ITS_CMD_BUFFER_SIZE(its->cbaser)) {
mutex_unlock(&its->cmd_lock);
return;
}
its->cwriter = reg;
cbaser = CBASER_ADDRESS(its->cbaser);
while (its->cwriter != its->creadr) {
int ret = kvm_read_guest(kvm, cbaser + its->creadr,
cmd_buf, ITS_CMD_SIZE);
if (!ret)
vgic_its_handle_command(kvm, its, cmd_buf);
its->creadr += ITS_CMD_SIZE;
if (its->creadr == ITS_CMD_BUFFER_SIZE(its->cbaser))
its->creadr = 0;
}
mutex_unlock(&its->cmd_lock);
}
static unsigned long vgic_mmio_read_its_cwriter(struct kvm *kvm,
struct vgic_its *its,
gpa_t addr, unsigned int len)
{
return extract_bytes(its->cwriter, addr & 0x7, len);
}
static unsigned long vgic_mmio_read_its_creadr(struct kvm *kvm,
struct vgic_its *its,
gpa_t addr, unsigned int len)
{
return extract_bytes(its->creadr, addr & 0x7, len);
}
static unsigned long vgic_mmio_read_its_baser(struct kvm *kvm,
struct vgic_its *its,
gpa_t addr, unsigned int len)
{
u64 reg;
switch (BASER_INDEX(addr)) {
case 0:
reg = its->baser_device_table;
break;
case 1:
reg = its->baser_coll_table;
break;
default:
reg = 0;
break;
}
return extract_bytes(reg, addr & 7, len);
}
static void vgic_mmio_write_its_baser(struct kvm *kvm,
struct vgic_its *its,
gpa_t addr, unsigned int len,
unsigned long val)
{
u64 entry_size, device_type;
u64 reg, *regptr, clearbits = 0;
if (its->enabled)
return;
switch (BASER_INDEX(addr)) {
case 0:
regptr = &its->baser_device_table;
entry_size = 8;
device_type = GITS_BASER_TYPE_DEVICE;
break;
case 1:
regptr = &its->baser_coll_table;
entry_size = 8;
device_type = GITS_BASER_TYPE_COLLECTION;
clearbits = GITS_BASER_INDIRECT;
break;
default:
return;
}
reg = update_64bit_reg(*regptr, addr & 7, len, val);
reg &= ~GITS_BASER_RO_MASK;
reg &= ~clearbits;
reg |= (entry_size - 1) << GITS_BASER_ENTRY_SIZE_SHIFT;
reg |= device_type << GITS_BASER_TYPE_SHIFT;
reg = vgic_sanitise_its_baser(reg);
*regptr = reg;
}
static void its_mmio_write_wi(struct kvm *kvm, struct vgic_its *its,
gpa_t addr, unsigned int len, unsigned long val)
{
}
void vgic_enable_lpis(struct kvm_vcpu *vcpu)
{
if (!(vcpu->arch.vgic_cpu.pendbaser & GICR_PENDBASER_PTZ))
its_sync_lpi_pending_table(vcpu);
}
static int vgic_register_its_iodev(struct kvm *kvm, struct vgic_its *its)
{
struct vgic_io_device *iodev = &its->iodev;
int ret;
if (!its->initialized)
return -EBUSY;
if (IS_VGIC_ADDR_UNDEF(its->vgic_its_base))
return -ENXIO;
iodev->regions = its_registers;
iodev->nr_regions = ARRAY_SIZE(its_registers);
kvm_iodevice_init(&iodev->dev, &kvm_io_gic_ops);
iodev->base_addr = its->vgic_its_base;
iodev->iodev_type = IODEV_ITS;
iodev->its = its;
mutex_lock(&kvm->slots_lock);
ret = kvm_io_bus_register_dev(kvm, KVM_MMIO_BUS, iodev->base_addr,
KVM_VGIC_V3_ITS_SIZE, &iodev->dev);
mutex_unlock(&kvm->slots_lock);
return ret;
}
static int vgic_its_create(struct kvm_device *dev, u32 type)
{
struct vgic_its *its;
if (type != KVM_DEV_TYPE_ARM_VGIC_ITS)
return -ENODEV;
its = kzalloc(sizeof(struct vgic_its), GFP_KERNEL);
if (!its)
return -ENOMEM;
mutex_init(&its->its_lock);
mutex_init(&its->cmd_lock);
its->vgic_its_base = VGIC_ADDR_UNDEF;
INIT_LIST_HEAD(&its->device_list);
INIT_LIST_HEAD(&its->collection_list);
dev->kvm->arch.vgic.has_its = true;
its->initialized = false;
its->enabled = false;
its->dev = dev;
its->baser_device_table = INITIAL_BASER_VALUE |
((u64)GITS_BASER_TYPE_DEVICE << GITS_BASER_TYPE_SHIFT);
its->baser_coll_table = INITIAL_BASER_VALUE |
((u64)GITS_BASER_TYPE_COLLECTION << GITS_BASER_TYPE_SHIFT);
dev->kvm->arch.vgic.propbaser = INITIAL_PROPBASER_VALUE;
dev->private = its;
return 0;
}
static void vgic_its_destroy(struct kvm_device *kvm_dev)
{
struct kvm *kvm = kvm_dev->kvm;
struct vgic_its *its = kvm_dev->private;
struct its_device *dev;
struct its_itte *itte;
struct list_head *dev_cur, *dev_temp;
struct list_head *cur, *temp;
if (!its->device_list.next)
return;
mutex_lock(&its->its_lock);
list_for_each_safe(dev_cur, dev_temp, &its->device_list) {
dev = container_of(dev_cur, struct its_device, dev_list);
list_for_each_safe(cur, temp, &dev->itt_head) {
itte = (container_of(cur, struct its_itte, itte_list));
its_free_itte(kvm, itte);
}
list_del(dev_cur);
kfree(dev);
}
list_for_each_safe(cur, temp, &its->collection_list) {
list_del(cur);
kfree(container_of(cur, struct its_collection, coll_list));
}
mutex_unlock(&its->its_lock);
kfree(its);
}
static int vgic_its_has_attr(struct kvm_device *dev,
struct kvm_device_attr *attr)
{
switch (attr->group) {
case KVM_DEV_ARM_VGIC_GRP_ADDR:
switch (attr->attr) {
case KVM_VGIC_ITS_ADDR_TYPE:
return 0;
}
break;
case KVM_DEV_ARM_VGIC_GRP_CTRL:
switch (attr->attr) {
case KVM_DEV_ARM_VGIC_CTRL_INIT:
return 0;
}
break;
}
return -ENXIO;
}
static int vgic_its_set_attr(struct kvm_device *dev,
struct kvm_device_attr *attr)
{
struct vgic_its *its = dev->private;
int ret;
switch (attr->group) {
case KVM_DEV_ARM_VGIC_GRP_ADDR: {
u64 __user *uaddr = (u64 __user *)(long)attr->addr;
unsigned long type = (unsigned long)attr->attr;
u64 addr;
if (type != KVM_VGIC_ITS_ADDR_TYPE)
return -ENODEV;
if (copy_from_user(&addr, uaddr, sizeof(addr)))
return -EFAULT;
ret = vgic_check_ioaddr(dev->kvm, &its->vgic_its_base,
addr, SZ_64K);
if (ret)
return ret;
its->vgic_its_base = addr;
return 0;
}
case KVM_DEV_ARM_VGIC_GRP_CTRL:
switch (attr->attr) {
case KVM_DEV_ARM_VGIC_CTRL_INIT:
its->initialized = true;
return 0;
}
break;
}
return -ENXIO;
}
static int vgic_its_get_attr(struct kvm_device *dev,
struct kvm_device_attr *attr)
{
switch (attr->group) {
case KVM_DEV_ARM_VGIC_GRP_ADDR: {
struct vgic_its *its = dev->private;
u64 addr = its->vgic_its_base;
u64 __user *uaddr = (u64 __user *)(long)attr->addr;
unsigned long type = (unsigned long)attr->attr;
if (type != KVM_VGIC_ITS_ADDR_TYPE)
return -ENODEV;
if (copy_to_user(uaddr, &addr, sizeof(addr)))
return -EFAULT;
break;
default:
return -ENXIO;
}
}
return 0;
}
int kvm_vgic_register_its_device(void)
{
return kvm_register_device_ops(&kvm_arm_vgic_its_ops,
KVM_DEV_TYPE_ARM_VGIC_ITS);
}
int vgic_register_its_iodevs(struct kvm *kvm)
{
struct kvm_device *dev;
int ret = 0;
list_for_each_entry(dev, &kvm->devices, vm_node) {
if (dev->ops != &kvm_arm_vgic_its_ops)
continue;
ret = vgic_register_its_iodev(kvm, dev->private);
if (ret)
return ret;
}
return ret;
}
