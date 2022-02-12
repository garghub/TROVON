drm_dma_handle_t *drm_pci_alloc(struct drm_device * dev, size_t size, size_t align)
{
drm_dma_handle_t *dmah;
unsigned long addr;
size_t sz;
if (align > size)
return NULL;
dmah = kmalloc(sizeof(drm_dma_handle_t), GFP_KERNEL);
if (!dmah)
return NULL;
dmah->size = size;
dmah->vaddr = dma_alloc_coherent(&dev->pdev->dev, size, &dmah->busaddr, GFP_KERNEL | __GFP_COMP);
if (dmah->vaddr == NULL) {
kfree(dmah);
return NULL;
}
memset(dmah->vaddr, 0, size);
for (addr = (unsigned long)dmah->vaddr, sz = size;
sz > 0; addr += PAGE_SIZE, sz -= PAGE_SIZE) {
SetPageReserved(virt_to_page((void *)addr));
}
return dmah;
}
void __drm_legacy_pci_free(struct drm_device * dev, drm_dma_handle_t * dmah)
{
unsigned long addr;
size_t sz;
if (dmah->vaddr) {
for (addr = (unsigned long)dmah->vaddr, sz = dmah->size;
sz > 0; addr += PAGE_SIZE, sz -= PAGE_SIZE) {
ClearPageReserved(virt_to_page((void *)addr));
}
dma_free_coherent(&dev->pdev->dev, dmah->size, dmah->vaddr,
dmah->busaddr);
}
}
void drm_pci_free(struct drm_device * dev, drm_dma_handle_t * dmah)
{
__drm_legacy_pci_free(dev, dmah);
kfree(dmah);
}
static int drm_get_pci_domain(struct drm_device *dev)
{
#ifndef __alpha__
if (dev->if_version < 0x10004)
return 0;
#endif
return pci_domain_nr(dev->pdev->bus);
}
int drm_pci_set_busid(struct drm_device *dev, struct drm_master *master)
{
master->unique = kasprintf(GFP_KERNEL, "pci:%04x:%02x:%02x.%d",
drm_get_pci_domain(dev),
dev->pdev->bus->number,
PCI_SLOT(dev->pdev->devfn),
PCI_FUNC(dev->pdev->devfn));
if (!master->unique)
return -ENOMEM;
master->unique_len = strlen(master->unique);
return 0;
}
int drm_pci_set_unique(struct drm_device *dev,
struct drm_master *master,
struct drm_unique *u)
{
int domain, bus, slot, func, ret;
master->unique_len = u->unique_len;
master->unique = kmalloc(master->unique_len + 1, GFP_KERNEL);
if (!master->unique) {
ret = -ENOMEM;
goto err;
}
if (copy_from_user(master->unique, u->unique, master->unique_len)) {
ret = -EFAULT;
goto err;
}
master->unique[master->unique_len] = '\0';
ret = sscanf(master->unique, "PCI:%d:%d:%d", &bus, &slot, &func);
if (ret != 3) {
ret = -EINVAL;
goto err;
}
domain = bus >> 8;
bus &= 0xff;
if ((domain != drm_get_pci_domain(dev)) ||
(bus != dev->pdev->bus->number) ||
(slot != PCI_SLOT(dev->pdev->devfn)) ||
(func != PCI_FUNC(dev->pdev->devfn))) {
ret = -EINVAL;
goto err;
}
return 0;
err:
return ret;
}
static int drm_pci_irq_by_busid(struct drm_device *dev, struct drm_irq_busid *p)
{
if ((p->busnum >> 8) != drm_get_pci_domain(dev) ||
(p->busnum & 0xff) != dev->pdev->bus->number ||
p->devnum != PCI_SLOT(dev->pdev->devfn) || p->funcnum != PCI_FUNC(dev->pdev->devfn))
return -EINVAL;
p->irq = dev->pdev->irq;
DRM_DEBUG("%d:%d:%d => IRQ %d\n", p->busnum, p->devnum, p->funcnum,
p->irq);
return 0;
}
int drm_irq_by_busid(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct drm_irq_busid *p = data;
if (drm_core_check_feature(dev, DRIVER_MODESET))
return -EINVAL;
if (WARN_ON(!dev->pdev))
return -EINVAL;
if (!drm_core_check_feature(dev, DRIVER_HAVE_IRQ))
return -EINVAL;
return drm_pci_irq_by_busid(dev, p);
}
static void drm_pci_agp_init(struct drm_device *dev)
{
if (drm_core_check_feature(dev, DRIVER_USE_AGP)) {
if (drm_pci_device_is_agp(dev))
dev->agp = drm_agp_init(dev);
if (dev->agp) {
dev->agp->agp_mtrr = arch_phys_wc_add(
dev->agp->agp_info.aper_base,
dev->agp->agp_info.aper_size *
1024 * 1024);
}
}
}
void drm_pci_agp_destroy(struct drm_device *dev)
{
if (dev->agp) {
arch_phys_wc_del(dev->agp->agp_mtrr);
drm_legacy_agp_clear(dev);
kfree(dev->agp);
dev->agp = NULL;
}
}
int drm_get_pci_dev(struct pci_dev *pdev, const struct pci_device_id *ent,
struct drm_driver *driver)
{
struct drm_device *dev;
int ret;
DRM_DEBUG("\n");
dev = drm_dev_alloc(driver, &pdev->dev);
if (!dev)
return -ENOMEM;
ret = pci_enable_device(pdev);
if (ret)
goto err_free;
dev->pdev = pdev;
#ifdef __alpha__
dev->hose = pdev->sysdata;
#endif
if (drm_core_check_feature(dev, DRIVER_MODESET))
pci_set_drvdata(pdev, dev);
drm_pci_agp_init(dev);
ret = drm_dev_register(dev, ent->driver_data);
if (ret)
goto err_agp;
DRM_INFO("Initialized %s %d.%d.%d %s for %s on minor %d\n",
driver->name, driver->major, driver->minor, driver->patchlevel,
driver->date, pci_name(pdev), dev->primary->index);
if (!drm_core_check_feature(dev, DRIVER_MODESET))
list_add_tail(&dev->legacy_dev_list, &driver->legacy_dev_list);
return 0;
err_agp:
drm_pci_agp_destroy(dev);
pci_disable_device(pdev);
err_free:
drm_dev_unref(dev);
return ret;
}
int drm_pci_init(struct drm_driver *driver, struct pci_driver *pdriver)
{
struct pci_dev *pdev = NULL;
const struct pci_device_id *pid;
int i;
DRM_DEBUG("\n");
if (driver->driver_features & DRIVER_MODESET)
return pci_register_driver(pdriver);
INIT_LIST_HEAD(&driver->legacy_dev_list);
for (i = 0; pdriver->id_table[i].vendor != 0; i++) {
pid = &pdriver->id_table[i];
pdev = NULL;
while ((pdev =
pci_get_subsys(pid->vendor, pid->device, pid->subvendor,
pid->subdevice, pdev)) != NULL) {
if ((pdev->class & pid->class_mask) != pid->class)
continue;
pci_dev_get(pdev);
drm_get_pci_dev(pdev, pid, driver);
}
}
return 0;
}
int drm_pcie_get_speed_cap_mask(struct drm_device *dev, u32 *mask)
{
struct pci_dev *root;
u32 lnkcap, lnkcap2;
*mask = 0;
if (!dev->pdev)
return -EINVAL;
root = dev->pdev->bus->self;
if (root->vendor == PCI_VENDOR_ID_VIA ||
root->vendor == PCI_VENDOR_ID_SERVERWORKS)
return -EINVAL;
pcie_capability_read_dword(root, PCI_EXP_LNKCAP, &lnkcap);
pcie_capability_read_dword(root, PCI_EXP_LNKCAP2, &lnkcap2);
if (lnkcap2) {
if (lnkcap2 & PCI_EXP_LNKCAP2_SLS_2_5GB)
*mask |= DRM_PCIE_SPEED_25;
if (lnkcap2 & PCI_EXP_LNKCAP2_SLS_5_0GB)
*mask |= DRM_PCIE_SPEED_50;
if (lnkcap2 & PCI_EXP_LNKCAP2_SLS_8_0GB)
*mask |= DRM_PCIE_SPEED_80;
} else {
if (lnkcap & PCI_EXP_LNKCAP_SLS_2_5GB)
*mask |= DRM_PCIE_SPEED_25;
if (lnkcap & PCI_EXP_LNKCAP_SLS_5_0GB)
*mask |= (DRM_PCIE_SPEED_25 | DRM_PCIE_SPEED_50);
}
DRM_INFO("probing gen 2 caps for device %x:%x = %x/%x\n", root->vendor, root->device, lnkcap, lnkcap2);
return 0;
}
int drm_pcie_get_max_link_width(struct drm_device *dev, u32 *mlw)
{
struct pci_dev *root;
u32 lnkcap;
*mlw = 0;
if (!dev->pdev)
return -EINVAL;
root = dev->pdev->bus->self;
pcie_capability_read_dword(root, PCI_EXP_LNKCAP, &lnkcap);
*mlw = (lnkcap & PCI_EXP_LNKCAP_MLW) >> 4;
DRM_INFO("probing mlw for device %x:%x = %x\n", root->vendor, root->device, lnkcap);
return 0;
}
int drm_pci_init(struct drm_driver *driver, struct pci_driver *pdriver)
{
return -1;
}
void drm_pci_agp_destroy(struct drm_device *dev) {}
int drm_irq_by_busid(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
return -EINVAL;
}
int drm_pci_set_unique(struct drm_device *dev,
struct drm_master *master,
struct drm_unique *u)
{
return -EINVAL;
}
void drm_pci_exit(struct drm_driver *driver, struct pci_driver *pdriver)
{
struct drm_device *dev, *tmp;
DRM_DEBUG("\n");
if (driver->driver_features & DRIVER_MODESET) {
pci_unregister_driver(pdriver);
} else {
list_for_each_entry_safe(dev, tmp, &driver->legacy_dev_list,
legacy_dev_list) {
list_del(&dev->legacy_dev_list);
drm_put_dev(dev);
}
}
DRM_INFO("Module unloaded\n");
}
