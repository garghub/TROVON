int pci_iov_virtfn_bus(struct pci_dev *dev, int vf_id)
{
if (!dev->is_physfn)
return -EINVAL;
return dev->bus->number + ((dev->devfn + dev->sriov->offset +
dev->sriov->stride * vf_id) >> 8);
}
int pci_iov_virtfn_devfn(struct pci_dev *dev, int vf_id)
{
if (!dev->is_physfn)
return -EINVAL;
return (dev->devfn + dev->sriov->offset +
dev->sriov->stride * vf_id) & 0xff;
}
static inline void pci_iov_set_numvfs(struct pci_dev *dev, int nr_virtfn)
{
struct pci_sriov *iov = dev->sriov;
pci_write_config_word(dev, iov->pos + PCI_SRIOV_NUM_VF, nr_virtfn);
pci_read_config_word(dev, iov->pos + PCI_SRIOV_VF_OFFSET, &iov->offset);
pci_read_config_word(dev, iov->pos + PCI_SRIOV_VF_STRIDE, &iov->stride);
}
static int compute_max_vf_buses(struct pci_dev *dev)
{
struct pci_sriov *iov = dev->sriov;
int nr_virtfn, busnr, rc = 0;
for (nr_virtfn = iov->total_VFs; nr_virtfn; nr_virtfn--) {
pci_iov_set_numvfs(dev, nr_virtfn);
if (!iov->offset || (nr_virtfn > 1 && !iov->stride)) {
rc = -EIO;
goto out;
}
busnr = pci_iov_virtfn_bus(dev, nr_virtfn - 1);
if (busnr > iov->max_VF_buses)
iov->max_VF_buses = busnr;
}
out:
pci_iov_set_numvfs(dev, 0);
return rc;
}
static struct pci_bus *virtfn_add_bus(struct pci_bus *bus, int busnr)
{
struct pci_bus *child;
if (bus->number == busnr)
return bus;
child = pci_find_bus(pci_domain_nr(bus), busnr);
if (child)
return child;
child = pci_add_new_bus(bus, NULL, busnr);
if (!child)
return NULL;
pci_bus_insert_busn_res(child, busnr, busnr);
return child;
}
static void virtfn_remove_bus(struct pci_bus *physbus, struct pci_bus *virtbus)
{
if (physbus != virtbus && list_empty(&virtbus->devices))
pci_remove_bus(virtbus);
}
resource_size_t pci_iov_resource_size(struct pci_dev *dev, int resno)
{
if (!dev->is_physfn)
return 0;
return dev->sriov->barsz[resno - PCI_IOV_RESOURCES];
}
int pci_iov_add_virtfn(struct pci_dev *dev, int id, int reset)
{
int i;
int rc = -ENOMEM;
u64 size;
char buf[VIRTFN_ID_LEN];
struct pci_dev *virtfn;
struct resource *res;
struct pci_sriov *iov = dev->sriov;
struct pci_bus *bus;
bus = virtfn_add_bus(dev->bus, pci_iov_virtfn_bus(dev, id));
if (!bus)
goto failed;
virtfn = pci_alloc_dev(bus);
if (!virtfn)
goto failed0;
virtfn->devfn = pci_iov_virtfn_devfn(dev, id);
virtfn->vendor = dev->vendor;
pci_read_config_word(dev, iov->pos + PCI_SRIOV_VF_DID, &virtfn->device);
rc = pci_setup_device(virtfn);
if (rc)
goto failed0;
virtfn->dev.parent = dev->dev.parent;
virtfn->physfn = pci_dev_get(dev);
virtfn->is_virtfn = 1;
virtfn->multifunction = 0;
for (i = 0; i < PCI_SRIOV_NUM_BARS; i++) {
res = &dev->resource[i + PCI_IOV_RESOURCES];
if (!res->parent)
continue;
virtfn->resource[i].name = pci_name(virtfn);
virtfn->resource[i].flags = res->flags;
size = pci_iov_resource_size(dev, i + PCI_IOV_RESOURCES);
virtfn->resource[i].start = res->start + size * id;
virtfn->resource[i].end = virtfn->resource[i].start + size - 1;
rc = request_resource(res, &virtfn->resource[i]);
BUG_ON(rc);
}
if (reset)
__pci_reset_function(virtfn);
pci_device_add(virtfn, virtfn->bus);
pci_bus_add_device(virtfn);
sprintf(buf, "virtfn%u", id);
rc = sysfs_create_link(&dev->dev.kobj, &virtfn->dev.kobj, buf);
if (rc)
goto failed1;
rc = sysfs_create_link(&virtfn->dev.kobj, &dev->dev.kobj, "physfn");
if (rc)
goto failed2;
kobject_uevent(&virtfn->dev.kobj, KOBJ_CHANGE);
return 0;
failed2:
sysfs_remove_link(&dev->dev.kobj, buf);
failed1:
pci_dev_put(dev);
pci_stop_and_remove_bus_device(virtfn);
failed0:
virtfn_remove_bus(dev->bus, bus);
failed:
return rc;
}
void pci_iov_remove_virtfn(struct pci_dev *dev, int id, int reset)
{
char buf[VIRTFN_ID_LEN];
struct pci_dev *virtfn;
virtfn = pci_get_domain_bus_and_slot(pci_domain_nr(dev->bus),
pci_iov_virtfn_bus(dev, id),
pci_iov_virtfn_devfn(dev, id));
if (!virtfn)
return;
if (reset) {
device_release_driver(&virtfn->dev);
__pci_reset_function(virtfn);
}
sprintf(buf, "virtfn%u", id);
sysfs_remove_link(&dev->dev.kobj, buf);
if (virtfn->dev.kobj.sd)
sysfs_remove_link(&virtfn->dev.kobj, "physfn");
pci_stop_and_remove_bus_device(virtfn);
virtfn_remove_bus(dev->bus, virtfn->bus);
pci_dev_put(virtfn);
pci_dev_put(dev);
}
int __weak pcibios_sriov_enable(struct pci_dev *pdev, u16 num_vfs)
{
return 0;
}
int __weak pcibios_sriov_disable(struct pci_dev *pdev)
{
return 0;
}
static int sriov_enable(struct pci_dev *dev, int nr_virtfn)
{
int rc;
int i;
int nres;
u16 initial;
struct resource *res;
struct pci_dev *pdev;
struct pci_sriov *iov = dev->sriov;
int bars = 0;
int bus;
if (!nr_virtfn)
return 0;
if (iov->num_VFs)
return -EINVAL;
pci_read_config_word(dev, iov->pos + PCI_SRIOV_INITIAL_VF, &initial);
if (initial > iov->total_VFs ||
(!(iov->cap & PCI_SRIOV_CAP_VFM) && (initial != iov->total_VFs)))
return -EIO;
if (nr_virtfn < 0 || nr_virtfn > iov->total_VFs ||
(!(iov->cap & PCI_SRIOV_CAP_VFM) && (nr_virtfn > initial)))
return -EINVAL;
nres = 0;
for (i = 0; i < PCI_SRIOV_NUM_BARS; i++) {
bars |= (1 << (i + PCI_IOV_RESOURCES));
res = &dev->resource[i + PCI_IOV_RESOURCES];
if (res->parent)
nres++;
}
if (nres != iov->nres) {
dev_err(&dev->dev, "not enough MMIO resources for SR-IOV\n");
return -ENOMEM;
}
bus = pci_iov_virtfn_bus(dev, nr_virtfn - 1);
if (bus > dev->bus->busn_res.end) {
dev_err(&dev->dev, "can't enable %d VFs (bus %02x out of range of %pR)\n",
nr_virtfn, bus, &dev->bus->busn_res);
return -ENOMEM;
}
if (pci_enable_resources(dev, bars)) {
dev_err(&dev->dev, "SR-IOV: IOV BARS not allocated\n");
return -ENOMEM;
}
if (iov->link != dev->devfn) {
pdev = pci_get_slot(dev->bus, iov->link);
if (!pdev)
return -ENODEV;
if (!pdev->is_physfn) {
pci_dev_put(pdev);
return -ENOSYS;
}
rc = sysfs_create_link(&dev->dev.kobj,
&pdev->dev.kobj, "dep_link");
pci_dev_put(pdev);
if (rc)
return rc;
}
iov->initial_VFs = initial;
if (nr_virtfn < initial)
initial = nr_virtfn;
rc = pcibios_sriov_enable(dev, initial);
if (rc) {
dev_err(&dev->dev, "failure %d from pcibios_sriov_enable()\n", rc);
goto err_pcibios;
}
pci_iov_set_numvfs(dev, nr_virtfn);
iov->ctrl |= PCI_SRIOV_CTRL_VFE | PCI_SRIOV_CTRL_MSE;
pci_cfg_access_lock(dev);
pci_write_config_word(dev, iov->pos + PCI_SRIOV_CTRL, iov->ctrl);
msleep(100);
pci_cfg_access_unlock(dev);
for (i = 0; i < initial; i++) {
rc = pci_iov_add_virtfn(dev, i, 0);
if (rc)
goto failed;
}
kobject_uevent(&dev->dev.kobj, KOBJ_CHANGE);
iov->num_VFs = nr_virtfn;
return 0;
failed:
while (i--)
pci_iov_remove_virtfn(dev, i, 0);
pcibios_sriov_disable(dev);
err_pcibios:
iov->ctrl &= ~(PCI_SRIOV_CTRL_VFE | PCI_SRIOV_CTRL_MSE);
pci_cfg_access_lock(dev);
pci_write_config_word(dev, iov->pos + PCI_SRIOV_CTRL, iov->ctrl);
ssleep(1);
pci_cfg_access_unlock(dev);
if (iov->link != dev->devfn)
sysfs_remove_link(&dev->dev.kobj, "dep_link");
pci_iov_set_numvfs(dev, 0);
return rc;
}
static void sriov_disable(struct pci_dev *dev)
{
int i;
struct pci_sriov *iov = dev->sriov;
if (!iov->num_VFs)
return;
for (i = 0; i < iov->num_VFs; i++)
pci_iov_remove_virtfn(dev, i, 0);
pcibios_sriov_disable(dev);
iov->ctrl &= ~(PCI_SRIOV_CTRL_VFE | PCI_SRIOV_CTRL_MSE);
pci_cfg_access_lock(dev);
pci_write_config_word(dev, iov->pos + PCI_SRIOV_CTRL, iov->ctrl);
ssleep(1);
pci_cfg_access_unlock(dev);
if (iov->link != dev->devfn)
sysfs_remove_link(&dev->dev.kobj, "dep_link");
iov->num_VFs = 0;
pci_iov_set_numvfs(dev, 0);
}
static int sriov_init(struct pci_dev *dev, int pos)
{
int i, bar64;
int rc;
int nres;
u32 pgsz;
u16 ctrl, total;
struct pci_sriov *iov;
struct resource *res;
struct pci_dev *pdev;
pci_read_config_word(dev, pos + PCI_SRIOV_CTRL, &ctrl);
if (ctrl & PCI_SRIOV_CTRL_VFE) {
pci_write_config_word(dev, pos + PCI_SRIOV_CTRL, 0);
ssleep(1);
}
ctrl = 0;
list_for_each_entry(pdev, &dev->bus->devices, bus_list)
if (pdev->is_physfn)
goto found;
pdev = NULL;
if (pci_ari_enabled(dev->bus))
ctrl |= PCI_SRIOV_CTRL_ARI;
found:
pci_write_config_word(dev, pos + PCI_SRIOV_CTRL, ctrl);
pci_read_config_word(dev, pos + PCI_SRIOV_TOTAL_VF, &total);
if (!total)
return 0;
pci_read_config_dword(dev, pos + PCI_SRIOV_SUP_PGSIZE, &pgsz);
i = PAGE_SHIFT > 12 ? PAGE_SHIFT - 12 : 0;
pgsz &= ~((1 << i) - 1);
if (!pgsz)
return -EIO;
pgsz &= ~(pgsz - 1);
pci_write_config_dword(dev, pos + PCI_SRIOV_SYS_PGSIZE, pgsz);
iov = kzalloc(sizeof(*iov), GFP_KERNEL);
if (!iov)
return -ENOMEM;
nres = 0;
for (i = 0; i < PCI_SRIOV_NUM_BARS; i++) {
res = &dev->resource[i + PCI_IOV_RESOURCES];
if (res->flags & IORESOURCE_PCI_FIXED)
bar64 = (res->flags & IORESOURCE_MEM_64) ? 1 : 0;
else
bar64 = __pci_read_base(dev, pci_bar_unknown, res,
pos + PCI_SRIOV_BAR + i * 4);
if (!res->flags)
continue;
if (resource_size(res) & (PAGE_SIZE - 1)) {
rc = -EIO;
goto failed;
}
iov->barsz[i] = resource_size(res);
res->end = res->start + resource_size(res) * total - 1;
dev_info(&dev->dev, "VF(n) BAR%d space: %pR (contains BAR%d for %d VFs)\n",
i, res, i, total);
i += bar64;
nres++;
}
iov->pos = pos;
iov->nres = nres;
iov->ctrl = ctrl;
iov->total_VFs = total;
iov->pgsz = pgsz;
iov->self = dev;
iov->drivers_autoprobe = true;
pci_read_config_dword(dev, pos + PCI_SRIOV_CAP, &iov->cap);
pci_read_config_byte(dev, pos + PCI_SRIOV_FUNC_LINK, &iov->link);
if (pci_pcie_type(dev) == PCI_EXP_TYPE_RC_END)
iov->link = PCI_DEVFN(PCI_SLOT(dev->devfn), iov->link);
if (pdev)
iov->dev = pci_dev_get(pdev);
else
iov->dev = dev;
dev->sriov = iov;
dev->is_physfn = 1;
rc = compute_max_vf_buses(dev);
if (rc)
goto fail_max_buses;
return 0;
fail_max_buses:
dev->sriov = NULL;
dev->is_physfn = 0;
failed:
for (i = 0; i < PCI_SRIOV_NUM_BARS; i++) {
res = &dev->resource[i + PCI_IOV_RESOURCES];
res->flags = 0;
}
kfree(iov);
return rc;
}
static void sriov_release(struct pci_dev *dev)
{
BUG_ON(dev->sriov->num_VFs);
if (dev != dev->sriov->dev)
pci_dev_put(dev->sriov->dev);
kfree(dev->sriov);
dev->sriov = NULL;
}
static void sriov_restore_state(struct pci_dev *dev)
{
int i;
u16 ctrl;
struct pci_sriov *iov = dev->sriov;
pci_read_config_word(dev, iov->pos + PCI_SRIOV_CTRL, &ctrl);
if (ctrl & PCI_SRIOV_CTRL_VFE)
return;
for (i = PCI_IOV_RESOURCES; i <= PCI_IOV_RESOURCE_END; i++)
pci_update_resource(dev, i);
pci_write_config_dword(dev, iov->pos + PCI_SRIOV_SYS_PGSIZE, iov->pgsz);
pci_iov_set_numvfs(dev, iov->num_VFs);
pci_write_config_word(dev, iov->pos + PCI_SRIOV_CTRL, iov->ctrl);
if (iov->ctrl & PCI_SRIOV_CTRL_VFE)
msleep(100);
}
int pci_iov_init(struct pci_dev *dev)
{
int pos;
if (!pci_is_pcie(dev))
return -ENODEV;
pos = pci_find_ext_capability(dev, PCI_EXT_CAP_ID_SRIOV);
if (pos)
return sriov_init(dev, pos);
return -ENODEV;
}
void pci_iov_release(struct pci_dev *dev)
{
if (dev->is_physfn)
sriov_release(dev);
}
void pci_iov_update_resource(struct pci_dev *dev, int resno)
{
struct pci_sriov *iov = dev->is_physfn ? dev->sriov : NULL;
struct resource *res = dev->resource + resno;
int vf_bar = resno - PCI_IOV_RESOURCES;
struct pci_bus_region region;
u16 cmd;
u32 new;
int reg;
if (!iov)
return;
pci_read_config_word(dev, iov->pos + PCI_SRIOV_CTRL, &cmd);
if ((cmd & PCI_SRIOV_CTRL_VFE) && (cmd & PCI_SRIOV_CTRL_MSE)) {
dev_WARN(&dev->dev, "can't update enabled VF BAR%d %pR\n",
vf_bar, res);
return;
}
if (!res->flags)
return;
if (res->flags & IORESOURCE_UNSET)
return;
if (res->flags & IORESOURCE_PCI_FIXED)
return;
pcibios_resource_to_bus(dev->bus, &region, res);
new = region.start;
new |= res->flags & ~PCI_BASE_ADDRESS_MEM_MASK;
reg = iov->pos + PCI_SRIOV_BAR + 4 * vf_bar;
pci_write_config_dword(dev, reg, new);
if (res->flags & IORESOURCE_MEM_64) {
new = region.start >> 16 >> 16;
pci_write_config_dword(dev, reg + 4, new);
}
}
resource_size_t __weak pcibios_iov_resource_alignment(struct pci_dev *dev,
int resno)
{
return pci_iov_resource_size(dev, resno);
}
resource_size_t pci_sriov_resource_alignment(struct pci_dev *dev, int resno)
{
return pcibios_iov_resource_alignment(dev, resno);
}
void pci_restore_iov_state(struct pci_dev *dev)
{
if (dev->is_physfn)
sriov_restore_state(dev);
}
int pci_iov_bus_range(struct pci_bus *bus)
{
int max = 0;
struct pci_dev *dev;
list_for_each_entry(dev, &bus->devices, bus_list) {
if (!dev->is_physfn)
continue;
if (dev->sriov->max_VF_buses > max)
max = dev->sriov->max_VF_buses;
}
return max ? max - bus->number : 0;
}
int pci_enable_sriov(struct pci_dev *dev, int nr_virtfn)
{
might_sleep();
if (!dev->is_physfn)
return -ENOSYS;
return sriov_enable(dev, nr_virtfn);
}
void pci_disable_sriov(struct pci_dev *dev)
{
might_sleep();
if (!dev->is_physfn)
return;
sriov_disable(dev);
}
int pci_num_vf(struct pci_dev *dev)
{
if (!dev->is_physfn)
return 0;
return dev->sriov->num_VFs;
}
int pci_vfs_assigned(struct pci_dev *dev)
{
struct pci_dev *vfdev;
unsigned int vfs_assigned = 0;
unsigned short dev_id;
if (!dev->is_physfn)
return 0;
pci_read_config_word(dev, dev->sriov->pos + PCI_SRIOV_VF_DID, &dev_id);
vfdev = pci_get_device(dev->vendor, dev_id, NULL);
while (vfdev) {
if (vfdev->is_virtfn && (vfdev->physfn == dev) &&
pci_is_dev_assigned(vfdev))
vfs_assigned++;
vfdev = pci_get_device(dev->vendor, dev_id, vfdev);
}
return vfs_assigned;
}
int pci_sriov_set_totalvfs(struct pci_dev *dev, u16 numvfs)
{
if (!dev->is_physfn)
return -ENOSYS;
if (numvfs > dev->sriov->total_VFs)
return -EINVAL;
if (dev->sriov->ctrl & PCI_SRIOV_CTRL_VFE)
return -EBUSY;
else
dev->sriov->driver_max_VFs = numvfs;
return 0;
}
int pci_sriov_get_totalvfs(struct pci_dev *dev)
{
if (!dev->is_physfn)
return 0;
if (dev->sriov->driver_max_VFs)
return dev->sriov->driver_max_VFs;
return dev->sriov->total_VFs;
}
