static int vio_cmo_num_OF_devs(void)
{
struct device_node *node_vroot;
int count = 0;
node_vroot = of_find_node_by_name(NULL, "vdevice");
if (node_vroot) {
struct device_node *of_node;
struct property *prop;
for_each_child_of_node(node_vroot, of_node) {
prop = of_find_property(of_node, "ibm,my-dma-window",
NULL);
if (prop)
count++;
}
}
of_node_put(node_vroot);
return count;
}
static inline int vio_cmo_alloc(struct vio_dev *viodev, size_t size)
{
unsigned long flags;
size_t reserve_free = 0;
size_t excess_free = 0;
int ret = -ENOMEM;
spin_lock_irqsave(&vio_cmo.lock, flags);
if (viodev->cmo.entitled > viodev->cmo.allocated)
reserve_free = viodev->cmo.entitled - viodev->cmo.allocated;
if (vio_cmo.spare >= VIO_CMO_MIN_ENT)
excess_free = vio_cmo.excess.free;
if ((reserve_free + excess_free) >= size) {
vio_cmo.curr += size;
if (vio_cmo.curr > vio_cmo.high)
vio_cmo.high = vio_cmo.curr;
viodev->cmo.allocated += size;
size -= min(reserve_free, size);
vio_cmo.excess.free -= size;
ret = 0;
}
spin_unlock_irqrestore(&vio_cmo.lock, flags);
return ret;
}
static inline void vio_cmo_dealloc(struct vio_dev *viodev, size_t size)
{
unsigned long flags;
size_t spare_needed = 0;
size_t excess_freed = 0;
size_t reserve_freed = size;
size_t tmp;
int balance = 0;
spin_lock_irqsave(&vio_cmo.lock, flags);
vio_cmo.curr -= size;
if (viodev->cmo.allocated > viodev->cmo.entitled) {
excess_freed = min(reserve_freed, (viodev->cmo.allocated -
viodev->cmo.entitled));
reserve_freed -= excess_freed;
}
viodev->cmo.allocated -= (reserve_freed + excess_freed);
spare_needed = VIO_CMO_MIN_ENT - vio_cmo.spare;
if (spare_needed && excess_freed) {
tmp = min(excess_freed, spare_needed);
vio_cmo.excess.size -= tmp;
vio_cmo.reserve.size += tmp;
vio_cmo.spare += tmp;
excess_freed -= tmp;
spare_needed -= tmp;
balance = 1;
}
if (spare_needed && reserve_freed) {
tmp = min3(spare_needed, reserve_freed, (viodev->cmo.entitled - VIO_CMO_MIN_ENT));
vio_cmo.spare += tmp;
viodev->cmo.entitled -= tmp;
reserve_freed -= tmp;
spare_needed -= tmp;
balance = 1;
}
if (excess_freed && (vio_cmo.desired > vio_cmo.reserve.size)) {
tmp = min(excess_freed, (vio_cmo.desired - vio_cmo.reserve.size));
vio_cmo.excess.size -= tmp;
vio_cmo.reserve.size += tmp;
excess_freed -= tmp;
balance = 1;
}
if (excess_freed)
vio_cmo.excess.free += excess_freed;
if (balance)
schedule_delayed_work(&vio_cmo.balance_q, VIO_CMO_BALANCE_DELAY);
spin_unlock_irqrestore(&vio_cmo.lock, flags);
}
int vio_cmo_entitlement_update(size_t new_entitlement)
{
struct vio_dev *viodev;
struct vio_cmo_dev_entry *dev_ent;
unsigned long flags;
size_t avail, delta, tmp;
spin_lock_irqsave(&vio_cmo.lock, flags);
if (new_entitlement > vio_cmo.entitled) {
delta = new_entitlement - vio_cmo.entitled;
if (vio_cmo.spare < VIO_CMO_MIN_ENT) {
tmp = min(delta, (VIO_CMO_MIN_ENT - vio_cmo.spare));
vio_cmo.spare += tmp;
vio_cmo.reserve.size += tmp;
delta -= tmp;
}
vio_cmo.entitled += delta;
vio_cmo.excess.size += delta;
vio_cmo.excess.free += delta;
goto out;
}
delta = vio_cmo.entitled - new_entitlement;
avail = vio_cmo.excess.free;
list_for_each_entry(dev_ent, &vio_cmo.device_list, list) {
if (avail >= delta)
break;
viodev = dev_ent->viodev;
if ((viodev->cmo.entitled > viodev->cmo.allocated) &&
(viodev->cmo.entitled > VIO_CMO_MIN_ENT))
avail += viodev->cmo.entitled -
max_t(size_t, viodev->cmo.allocated,
VIO_CMO_MIN_ENT);
}
if (delta <= avail) {
vio_cmo.entitled -= delta;
tmp = min(vio_cmo.excess.free, delta);
vio_cmo.excess.size -= tmp;
vio_cmo.excess.free -= tmp;
delta -= tmp;
list_for_each_entry(dev_ent, &vio_cmo.device_list, list) {
if (!delta)
break;
viodev = dev_ent->viodev;
tmp = 0;
if ((viodev->cmo.entitled > viodev->cmo.allocated) &&
(viodev->cmo.entitled > VIO_CMO_MIN_ENT))
tmp = viodev->cmo.entitled -
max_t(size_t, viodev->cmo.allocated,
VIO_CMO_MIN_ENT);
viodev->cmo.entitled -= min(tmp, delta);
delta -= min(tmp, delta);
}
} else {
spin_unlock_irqrestore(&vio_cmo.lock, flags);
return -ENOMEM;
}
out:
schedule_delayed_work(&vio_cmo.balance_q, 0);
spin_unlock_irqrestore(&vio_cmo.lock, flags);
return 0;
}
static void vio_cmo_balance(struct work_struct *work)
{
struct vio_cmo *cmo;
struct vio_dev *viodev;
struct vio_cmo_dev_entry *dev_ent;
unsigned long flags;
size_t avail = 0, level, chunk, need;
int devcount = 0, fulfilled;
cmo = container_of(work, struct vio_cmo, balance_q.work);
spin_lock_irqsave(&vio_cmo.lock, flags);
cmo->min = vio_cmo_num_OF_devs() * VIO_CMO_MIN_ENT;
BUG_ON(cmo->min > cmo->entitled);
cmo->spare = min_t(size_t, VIO_CMO_MIN_ENT, (cmo->entitled - cmo->min));
cmo->min += cmo->spare;
cmo->desired = cmo->min;
avail = cmo->entitled - cmo->spare;
list_for_each_entry(dev_ent, &vio_cmo.device_list, list) {
viodev = dev_ent->viodev;
devcount++;
viodev->cmo.entitled = VIO_CMO_MIN_ENT;
cmo->desired += (viodev->cmo.desired - VIO_CMO_MIN_ENT);
avail -= max_t(size_t, viodev->cmo.allocated, VIO_CMO_MIN_ENT);
}
level = VIO_CMO_MIN_ENT;
while (avail) {
fulfilled = 0;
list_for_each_entry(dev_ent, &vio_cmo.device_list, list) {
viodev = dev_ent->viodev;
if (viodev->cmo.desired <= level) {
fulfilled++;
continue;
}
chunk = min_t(size_t, avail, VIO_CMO_BALANCE_CHUNK);
chunk = min(chunk, (viodev->cmo.desired -
viodev->cmo.entitled));
viodev->cmo.entitled += chunk;
need = max(viodev->cmo.allocated, viodev->cmo.entitled)-
max(viodev->cmo.allocated, level);
avail -= need;
}
if (fulfilled == devcount)
break;
level += VIO_CMO_BALANCE_CHUNK;
}
cmo->reserve.size = cmo->min;
cmo->excess.free = 0;
cmo->excess.size = 0;
need = 0;
list_for_each_entry(dev_ent, &vio_cmo.device_list, list) {
viodev = dev_ent->viodev;
if (viodev->cmo.entitled)
cmo->reserve.size += (viodev->cmo.entitled -
VIO_CMO_MIN_ENT);
if (viodev->cmo.allocated > viodev->cmo.entitled)
need += viodev->cmo.allocated - viodev->cmo.entitled;
}
cmo->excess.size = cmo->entitled - cmo->reserve.size;
cmo->excess.free = cmo->excess.size - need;
cancel_delayed_work(to_delayed_work(work));
spin_unlock_irqrestore(&vio_cmo.lock, flags);
}
static void *vio_dma_iommu_alloc_coherent(struct device *dev, size_t size,
dma_addr_t *dma_handle, gfp_t flag,
struct dma_attrs *attrs)
{
struct vio_dev *viodev = to_vio_dev(dev);
void *ret;
if (vio_cmo_alloc(viodev, roundup(size, PAGE_SIZE))) {
atomic_inc(&viodev->cmo.allocs_failed);
return NULL;
}
ret = dma_iommu_ops.alloc(dev, size, dma_handle, flag, attrs);
if (unlikely(ret == NULL)) {
vio_cmo_dealloc(viodev, roundup(size, PAGE_SIZE));
atomic_inc(&viodev->cmo.allocs_failed);
}
return ret;
}
static void vio_dma_iommu_free_coherent(struct device *dev, size_t size,
void *vaddr, dma_addr_t dma_handle,
struct dma_attrs *attrs)
{
struct vio_dev *viodev = to_vio_dev(dev);
dma_iommu_ops.free(dev, size, vaddr, dma_handle, attrs);
vio_cmo_dealloc(viodev, roundup(size, PAGE_SIZE));
}
static dma_addr_t vio_dma_iommu_map_page(struct device *dev, struct page *page,
unsigned long offset, size_t size,
enum dma_data_direction direction,
struct dma_attrs *attrs)
{
struct vio_dev *viodev = to_vio_dev(dev);
dma_addr_t ret = DMA_ERROR_CODE;
if (vio_cmo_alloc(viodev, roundup(size, IOMMU_PAGE_SIZE))) {
atomic_inc(&viodev->cmo.allocs_failed);
return ret;
}
ret = dma_iommu_ops.map_page(dev, page, offset, size, direction, attrs);
if (unlikely(dma_mapping_error(dev, ret))) {
vio_cmo_dealloc(viodev, roundup(size, IOMMU_PAGE_SIZE));
atomic_inc(&viodev->cmo.allocs_failed);
}
return ret;
}
static void vio_dma_iommu_unmap_page(struct device *dev, dma_addr_t dma_handle,
size_t size,
enum dma_data_direction direction,
struct dma_attrs *attrs)
{
struct vio_dev *viodev = to_vio_dev(dev);
dma_iommu_ops.unmap_page(dev, dma_handle, size, direction, attrs);
vio_cmo_dealloc(viodev, roundup(size, IOMMU_PAGE_SIZE));
}
static int vio_dma_iommu_map_sg(struct device *dev, struct scatterlist *sglist,
int nelems, enum dma_data_direction direction,
struct dma_attrs *attrs)
{
struct vio_dev *viodev = to_vio_dev(dev);
struct scatterlist *sgl;
int ret, count = 0;
size_t alloc_size = 0;
for (sgl = sglist; count < nelems; count++, sgl++)
alloc_size += roundup(sgl->length, IOMMU_PAGE_SIZE);
if (vio_cmo_alloc(viodev, alloc_size)) {
atomic_inc(&viodev->cmo.allocs_failed);
return 0;
}
ret = dma_iommu_ops.map_sg(dev, sglist, nelems, direction, attrs);
if (unlikely(!ret)) {
vio_cmo_dealloc(viodev, alloc_size);
atomic_inc(&viodev->cmo.allocs_failed);
return ret;
}
for (sgl = sglist, count = 0; count < ret; count++, sgl++)
alloc_size -= roundup(sgl->dma_length, IOMMU_PAGE_SIZE);
if (alloc_size)
vio_cmo_dealloc(viodev, alloc_size);
return ret;
}
static void vio_dma_iommu_unmap_sg(struct device *dev,
struct scatterlist *sglist, int nelems,
enum dma_data_direction direction,
struct dma_attrs *attrs)
{
struct vio_dev *viodev = to_vio_dev(dev);
struct scatterlist *sgl;
size_t alloc_size = 0;
int count = 0;
for (sgl = sglist; count < nelems; count++, sgl++)
alloc_size += roundup(sgl->dma_length, IOMMU_PAGE_SIZE);
dma_iommu_ops.unmap_sg(dev, sglist, nelems, direction, attrs);
vio_cmo_dealloc(viodev, alloc_size);
}
static int vio_dma_iommu_dma_supported(struct device *dev, u64 mask)
{
return dma_iommu_ops.dma_supported(dev, mask);
}
static u64 vio_dma_get_required_mask(struct device *dev)
{
return dma_iommu_ops.get_required_mask(dev);
}
void vio_cmo_set_dev_desired(struct vio_dev *viodev, size_t desired)
{
unsigned long flags;
struct vio_cmo_dev_entry *dev_ent;
int found = 0;
if (!firmware_has_feature(FW_FEATURE_CMO))
return;
spin_lock_irqsave(&vio_cmo.lock, flags);
if (desired < VIO_CMO_MIN_ENT)
desired = VIO_CMO_MIN_ENT;
list_for_each_entry(dev_ent, &vio_cmo.device_list, list)
if (viodev == dev_ent->viodev) {
found = 1;
break;
}
if (!found) {
spin_unlock_irqrestore(&vio_cmo.lock, flags);
return;
}
if (desired >= viodev->cmo.desired) {
vio_cmo.desired += desired - viodev->cmo.desired;
viodev->cmo.desired = desired;
} else {
vio_cmo.desired -= viodev->cmo.desired - desired;
viodev->cmo.desired = desired;
if (viodev->cmo.entitled > desired) {
vio_cmo.reserve.size -= viodev->cmo.entitled - desired;
vio_cmo.excess.size += viodev->cmo.entitled - desired;
if (viodev->cmo.allocated < viodev->cmo.entitled)
vio_cmo.excess.free += viodev->cmo.entitled -
max(viodev->cmo.allocated, desired);
viodev->cmo.entitled = desired;
}
}
schedule_delayed_work(&vio_cmo.balance_q, 0);
spin_unlock_irqrestore(&vio_cmo.lock, flags);
}
static int vio_cmo_bus_probe(struct vio_dev *viodev)
{
struct vio_cmo_dev_entry *dev_ent;
struct device *dev = &viodev->dev;
struct vio_driver *viodrv = to_vio_driver(dev->driver);
unsigned long flags;
size_t size;
bool dma_capable = false;
switch (viodev->family) {
case VDEVICE:
if (of_get_property(viodev->dev.of_node,
"ibm,my-dma-window", NULL))
dma_capable = true;
break;
case PFO:
dma_capable = false;
break;
default:
dev_warn(dev, "unknown device family: %d\n", viodev->family);
BUG();
break;
}
if (dma_capable) {
if (!viodrv->get_desired_dma) {
dev_err(dev, "%s: device driver does not support CMO\n",
__func__);
return -EINVAL;
}
viodev->cmo.desired = IOMMU_PAGE_ALIGN(viodrv->get_desired_dma(viodev));
if (viodev->cmo.desired < VIO_CMO_MIN_ENT)
viodev->cmo.desired = VIO_CMO_MIN_ENT;
size = VIO_CMO_MIN_ENT;
dev_ent = kmalloc(sizeof(struct vio_cmo_dev_entry),
GFP_KERNEL);
if (!dev_ent)
return -ENOMEM;
dev_ent->viodev = viodev;
spin_lock_irqsave(&vio_cmo.lock, flags);
list_add(&dev_ent->list, &vio_cmo.device_list);
} else {
viodev->cmo.desired = 0;
size = 0;
spin_lock_irqsave(&vio_cmo.lock, flags);
}
if (vio_cmo.min == ((vio_cmo_num_OF_devs() + 1) *
VIO_CMO_MIN_ENT)) {
if (size)
vio_cmo.desired += (viodev->cmo.desired -
VIO_CMO_MIN_ENT);
} else {
size_t tmp;
tmp = vio_cmo.spare + vio_cmo.excess.free;
if (tmp < size) {
dev_err(dev, "%s: insufficient free "
"entitlement to add device. "
"Need %lu, have %lu\n", __func__,
size, (vio_cmo.spare + tmp));
spin_unlock_irqrestore(&vio_cmo.lock, flags);
return -ENOMEM;
}
tmp = min(size, vio_cmo.excess.free);
vio_cmo.excess.free -= tmp;
vio_cmo.excess.size -= tmp;
vio_cmo.reserve.size += tmp;
vio_cmo.spare -= size - tmp;
vio_cmo.min += size;
vio_cmo.desired += viodev->cmo.desired;
}
spin_unlock_irqrestore(&vio_cmo.lock, flags);
return 0;
}
static void vio_cmo_bus_remove(struct vio_dev *viodev)
{
struct vio_cmo_dev_entry *dev_ent;
unsigned long flags;
size_t tmp;
spin_lock_irqsave(&vio_cmo.lock, flags);
if (viodev->cmo.allocated) {
dev_err(&viodev->dev, "%s: device had %lu bytes of IO "
"allocated after remove operation.\n",
__func__, viodev->cmo.allocated);
BUG();
}
list_for_each_entry(dev_ent, &vio_cmo.device_list, list)
if (viodev == dev_ent->viodev) {
list_del(&dev_ent->list);
kfree(dev_ent);
break;
}
if (viodev->cmo.entitled) {
vio_cmo.desired -= (viodev->cmo.desired - VIO_CMO_MIN_ENT);
viodev->cmo.entitled -= VIO_CMO_MIN_ENT;
if (viodev->cmo.entitled && (vio_cmo.spare < VIO_CMO_MIN_ENT)) {
tmp = min(viodev->cmo.entitled, (VIO_CMO_MIN_ENT -
vio_cmo.spare));
vio_cmo.spare += tmp;
viodev->cmo.entitled -= tmp;
}
vio_cmo.excess.size += viodev->cmo.entitled;
vio_cmo.excess.free += viodev->cmo.entitled;
vio_cmo.reserve.size -= viodev->cmo.entitled;
viodev->cmo.entitled = VIO_CMO_MIN_ENT;
viodev->cmo.desired = VIO_CMO_MIN_ENT;
atomic_set(&viodev->cmo.allocs_failed, 0);
}
spin_unlock_irqrestore(&vio_cmo.lock, flags);
}
static void vio_cmo_set_dma_ops(struct vio_dev *viodev)
{
set_dma_ops(&viodev->dev, &vio_dma_mapping_ops);
}
static void vio_cmo_bus_init(void)
{
struct hvcall_mpp_data mpp_data;
int err;
memset(&vio_cmo, 0, sizeof(struct vio_cmo));
spin_lock_init(&vio_cmo.lock);
INIT_LIST_HEAD(&vio_cmo.device_list);
INIT_DELAYED_WORK(&vio_cmo.balance_q, vio_cmo_balance);
err = h_get_mpp(&mpp_data);
if (err != H_SUCCESS) {
printk(KERN_ERR "%s: unable to determine system IO "\
"entitlement. (%d)\n", __func__, err);
vio_cmo.entitled = 0;
} else {
vio_cmo.entitled = mpp_data.entitled_mem;
}
vio_cmo.spare = VIO_CMO_MIN_ENT;
vio_cmo.reserve.size = vio_cmo.spare;
vio_cmo.reserve.size += (vio_cmo_num_OF_devs() *
VIO_CMO_MIN_ENT);
if (vio_cmo.reserve.size > vio_cmo.entitled) {
printk(KERN_ERR "%s: insufficient system entitlement\n",
__func__);
panic("%s: Insufficient system entitlement", __func__);
}
vio_cmo.excess.size = vio_cmo.entitled - vio_cmo.reserve.size;
vio_cmo.excess.free = vio_cmo.excess.size;
vio_cmo.min = vio_cmo.reserve.size;
vio_cmo.desired = vio_cmo.reserve.size;
}
static ssize_t viodev_cmo_allocs_failed_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct vio_dev *viodev = to_vio_dev(dev);
return sprintf(buf, "%d\n", atomic_read(&viodev->cmo.allocs_failed));
}
static ssize_t viodev_cmo_allocs_failed_reset(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
struct vio_dev *viodev = to_vio_dev(dev);
atomic_set(&viodev->cmo.allocs_failed, 0);
return count;
}
static ssize_t viodev_cmo_desired_set(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
struct vio_dev *viodev = to_vio_dev(dev);
size_t new_desired;
int ret;
ret = strict_strtoul(buf, 10, &new_desired);
if (ret)
return ret;
vio_cmo_set_dev_desired(viodev, new_desired);
return count;
}
static ssize_t viobus_cmo_high_reset(struct bus_type *bt, const char *buf,
size_t count)
{
unsigned long flags;
spin_lock_irqsave(&vio_cmo.lock, flags);
vio_cmo.high = vio_cmo.curr;
spin_unlock_irqrestore(&vio_cmo.lock, flags);
return count;
}
static void vio_cmo_sysfs_init(void)
{
vio_bus_type.dev_attrs = vio_cmo_dev_attrs;
vio_bus_type.bus_attrs = vio_cmo_bus_attrs;
}
int vio_cmo_entitlement_update(size_t new_entitlement) { return 0; }
void vio_cmo_set_dev_desired(struct vio_dev *viodev, size_t desired) {}
static int vio_cmo_bus_probe(struct vio_dev *viodev) { return 0; }
static void vio_cmo_bus_remove(struct vio_dev *viodev) {}
static void vio_cmo_set_dma_ops(struct vio_dev *viodev) {}
static void vio_cmo_bus_init(void) {}
static void vio_cmo_sysfs_init(void) { }
int vio_h_cop_sync(struct vio_dev *vdev, struct vio_pfo_op *op)
{
struct device *dev = &vdev->dev;
unsigned long deadline = 0;
long hret = 0;
int ret = 0;
if (op->timeout)
deadline = jiffies + msecs_to_jiffies(op->timeout);
while (true) {
hret = plpar_hcall_norets(H_COP, op->flags,
vdev->resource_id,
op->in, op->inlen, op->out,
op->outlen, op->csbcpb);
if (hret == H_SUCCESS ||
(hret != H_NOT_ENOUGH_RESOURCES &&
hret != H_BUSY && hret != H_RESOURCE) ||
(op->timeout && time_after(deadline, jiffies)))
break;
dev_dbg(dev, "%s: hcall ret(%ld), retrying.\n", __func__, hret);
}
switch (hret) {
case H_SUCCESS:
ret = 0;
break;
case H_OP_MODE:
case H_TOO_BIG:
ret = -E2BIG;
break;
case H_RESCINDED:
ret = -EACCES;
break;
case H_HARDWARE:
ret = -EPERM;
break;
case H_NOT_ENOUGH_RESOURCES:
case H_RESOURCE:
case H_BUSY:
ret = -EBUSY;
break;
default:
ret = -EINVAL;
break;
}
if (ret)
dev_dbg(dev, "%s: Sync h_cop_op failure (ret:%d) (hret:%ld)\n",
__func__, ret, hret);
op->hcall_err = hret;
return ret;
}
static struct iommu_table *vio_build_iommu_table(struct vio_dev *dev)
{
const unsigned char *dma_window;
struct iommu_table *tbl;
unsigned long offset, size;
dma_window = of_get_property(dev->dev.of_node,
"ibm,my-dma-window", NULL);
if (!dma_window)
return NULL;
tbl = kzalloc(sizeof(*tbl), GFP_KERNEL);
if (tbl == NULL)
return NULL;
of_parse_dma_window(dev->dev.of_node, dma_window,
&tbl->it_index, &offset, &size);
tbl->it_size = size >> IOMMU_PAGE_SHIFT;
tbl->it_offset = offset >> IOMMU_PAGE_SHIFT;
tbl->it_busno = 0;
tbl->it_type = TCE_VB;
tbl->it_blocksize = 16;
return iommu_init_table(tbl, -1);
}
static const struct vio_device_id *vio_match_device(
const struct vio_device_id *ids, const struct vio_dev *dev)
{
while (ids->type[0] != '\0') {
if ((strncmp(dev->type, ids->type, strlen(ids->type)) == 0) &&
of_device_is_compatible(dev->dev.of_node,
ids->compat))
return ids;
ids++;
}
return NULL;
}
static int vio_bus_probe(struct device *dev)
{
struct vio_dev *viodev = to_vio_dev(dev);
struct vio_driver *viodrv = to_vio_driver(dev->driver);
const struct vio_device_id *id;
int error = -ENODEV;
if (!viodrv->probe)
return error;
id = vio_match_device(viodrv->id_table, viodev);
if (id) {
memset(&viodev->cmo, 0, sizeof(viodev->cmo));
if (firmware_has_feature(FW_FEATURE_CMO)) {
error = vio_cmo_bus_probe(viodev);
if (error)
return error;
}
error = viodrv->probe(viodev, id);
if (error && firmware_has_feature(FW_FEATURE_CMO))
vio_cmo_bus_remove(viodev);
}
return error;
}
static int vio_bus_remove(struct device *dev)
{
struct vio_dev *viodev = to_vio_dev(dev);
struct vio_driver *viodrv = to_vio_driver(dev->driver);
struct device *devptr;
int ret = 1;
devptr = get_device(dev);
if (viodrv->remove)
ret = viodrv->remove(viodev);
if (!ret && firmware_has_feature(FW_FEATURE_CMO))
vio_cmo_bus_remove(viodev);
put_device(devptr);
return ret;
}
int __vio_register_driver(struct vio_driver *viodrv, struct module *owner,
const char *mod_name)
{
pr_debug("%s: driver %s registering\n", __func__, viodrv->name);
viodrv->driver.name = viodrv->name;
viodrv->driver.pm = viodrv->pm;
viodrv->driver.bus = &vio_bus_type;
viodrv->driver.owner = owner;
viodrv->driver.mod_name = mod_name;
return driver_register(&viodrv->driver);
}
void vio_unregister_driver(struct vio_driver *viodrv)
{
driver_unregister(&viodrv->driver);
}
static void __devinit vio_dev_release(struct device *dev)
{
struct iommu_table *tbl = get_iommu_table_base(dev);
if (tbl)
iommu_free_table(tbl, dev->of_node ?
dev->of_node->full_name : dev_name(dev));
of_node_put(dev->of_node);
kfree(to_vio_dev(dev));
}
struct vio_dev *vio_register_device_node(struct device_node *of_node)
{
struct vio_dev *viodev;
struct device_node *parent_node;
const unsigned int *unit_address;
const unsigned int *pfo_resid = NULL;
enum vio_dev_family family;
const char *of_node_name = of_node->name ? of_node->name : "<unknown>";
parent_node = of_get_parent(of_node);
if (parent_node) {
if (!strcmp(parent_node->full_name, "/ibm,platform-facilities"))
family = PFO;
else if (!strcmp(parent_node->full_name, "/vdevice"))
family = VDEVICE;
else {
pr_warn("%s: parent(%s) of %s not recognized.\n",
__func__,
parent_node->full_name,
of_node_name);
of_node_put(parent_node);
return NULL;
}
of_node_put(parent_node);
} else {
pr_warn("%s: could not determine the parent of node %s.\n",
__func__, of_node_name);
return NULL;
}
if (family == PFO) {
if (of_get_property(of_node, "interrupt-controller", NULL)) {
pr_debug("%s: Skipping the interrupt controller %s.\n",
__func__, of_node_name);
return NULL;
}
}
viodev = kzalloc(sizeof(struct vio_dev), GFP_KERNEL);
if (viodev == NULL) {
pr_warn("%s: allocation failure for VIO device.\n", __func__);
return NULL;
}
viodev->family = family;
if (viodev->family == VDEVICE) {
if (of_node->type != NULL)
viodev->type = of_node->type;
else {
pr_warn("%s: node %s is missing the 'device_type' "
"property.\n", __func__, of_node_name);
goto out;
}
unit_address = of_get_property(of_node, "reg", NULL);
if (unit_address == NULL) {
pr_warn("%s: node %s missing 'reg'\n",
__func__, of_node_name);
goto out;
}
dev_set_name(&viodev->dev, "%x", *unit_address);
viodev->irq = irq_of_parse_and_map(of_node, 0);
viodev->unit_address = *unit_address;
} else {
pfo_resid = of_get_property(of_node, "ibm,resource-id", NULL);
if (pfo_resid != NULL)
viodev->resource_id = *pfo_resid;
unit_address = NULL;
dev_set_name(&viodev->dev, "%s", of_node_name);
viodev->type = of_node_name;
viodev->irq = 0;
}
viodev->name = of_node->name;
viodev->dev.of_node = of_node_get(of_node);
if (firmware_has_feature(FW_FEATURE_CMO))
vio_cmo_set_dma_ops(viodev);
else
set_dma_ops(&viodev->dev, &dma_iommu_ops);
set_iommu_table_base(&viodev->dev, vio_build_iommu_table(viodev));
set_dev_node(&viodev->dev, of_node_to_nid(of_node));
viodev->dev.parent = &vio_bus_device.dev;
viodev->dev.bus = &vio_bus_type;
viodev->dev.release = vio_dev_release;
dma_set_mask(&viodev->dev, DMA_BIT_MASK(64));
dma_set_coherent_mask(&viodev->dev, DMA_BIT_MASK(64));
if (device_register(&viodev->dev)) {
printk(KERN_ERR "%s: failed to register device %s\n",
__func__, dev_name(&viodev->dev));
put_device(&viodev->dev);
return NULL;
}
return viodev;
out:
kfree(viodev);
return NULL;
}
static void vio_bus_scan_register_devices(char *root_name)
{
struct device_node *node_root, *node_child;
if (!root_name)
return;
node_root = of_find_node_by_name(NULL, root_name);
if (node_root) {
node_child = of_get_next_child(node_root, NULL);
while (node_child) {
vio_register_device_node(node_child);
node_child = of_get_next_child(node_root, node_child);
}
of_node_put(node_root);
}
}
static int __init vio_bus_init(void)
{
int err;
if (firmware_has_feature(FW_FEATURE_CMO))
vio_cmo_sysfs_init();
err = bus_register(&vio_bus_type);
if (err) {
printk(KERN_ERR "failed to register VIO bus\n");
return err;
}
err = device_register(&vio_bus_device.dev);
if (err) {
printk(KERN_WARNING "%s: device_register returned %i\n",
__func__, err);
return err;
}
if (firmware_has_feature(FW_FEATURE_CMO))
vio_cmo_bus_init();
vio_bus_scan_register_devices("vdevice");
vio_bus_scan_register_devices("ibm,platform-facilities");
return 0;
}
static ssize_t name_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
return sprintf(buf, "%s\n", to_vio_dev(dev)->name);
}
static ssize_t devspec_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct device_node *of_node = dev->of_node;
return sprintf(buf, "%s\n", of_node ? of_node->full_name : "none");
}
static ssize_t modalias_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
const struct vio_dev *vio_dev = to_vio_dev(dev);
struct device_node *dn;
const char *cp;
dn = dev->of_node;
if (!dn)
return -ENODEV;
cp = of_get_property(dn, "compatible", NULL);
if (!cp)
return -ENODEV;
return sprintf(buf, "vio:T%sS%s\n", vio_dev->type, cp);
}
void __devinit vio_unregister_device(struct vio_dev *viodev)
{
device_unregister(&viodev->dev);
}
static int vio_bus_match(struct device *dev, struct device_driver *drv)
{
const struct vio_dev *vio_dev = to_vio_dev(dev);
struct vio_driver *vio_drv = to_vio_driver(drv);
const struct vio_device_id *ids = vio_drv->id_table;
return (ids != NULL) && (vio_match_device(ids, vio_dev) != NULL);
}
static int vio_hotplug(struct device *dev, struct kobj_uevent_env *env)
{
const struct vio_dev *vio_dev = to_vio_dev(dev);
struct device_node *dn;
const char *cp;
dn = dev->of_node;
if (!dn)
return -ENODEV;
cp = of_get_property(dn, "compatible", NULL);
if (!cp)
return -ENODEV;
add_uevent_var(env, "MODALIAS=vio:T%sS%s", vio_dev->type, cp);
return 0;
}
const void *vio_get_attribute(struct vio_dev *vdev, char *which, int *length)
{
return of_get_property(vdev->dev.of_node, which, length);
}
static struct vio_dev *vio_find_name(const char *name)
{
struct device *found;
found = bus_find_device_by_name(&vio_bus_type, NULL, name);
if (!found)
return NULL;
return to_vio_dev(found);
}
struct vio_dev *vio_find_node(struct device_node *vnode)
{
const uint32_t *unit_address;
char kobj_name[20];
struct device_node *vnode_parent;
const char *dev_type;
vnode_parent = of_get_parent(vnode);
if (!vnode_parent)
return NULL;
dev_type = of_get_property(vnode_parent, "device_type", NULL);
of_node_put(vnode_parent);
if (!dev_type)
return NULL;
if (!strcmp(dev_type, "vdevice")) {
unit_address = of_get_property(vnode, "reg", NULL);
if (!unit_address)
return NULL;
snprintf(kobj_name, sizeof(kobj_name), "%x", *unit_address);
} else if (!strcmp(dev_type, "ibm,platform-facilities"))
snprintf(kobj_name, sizeof(kobj_name), "%s", vnode->name);
else
return NULL;
return vio_find_name(kobj_name);
}
int vio_enable_interrupts(struct vio_dev *dev)
{
int rc = h_vio_signal(dev->unit_address, VIO_IRQ_ENABLE);
if (rc != H_SUCCESS)
printk(KERN_ERR "vio: Error 0x%x enabling interrupts\n", rc);
return rc;
}
int vio_disable_interrupts(struct vio_dev *dev)
{
int rc = h_vio_signal(dev->unit_address, VIO_IRQ_DISABLE);
if (rc != H_SUCCESS)
printk(KERN_ERR "vio: Error 0x%x disabling interrupts\n", rc);
return rc;
}
