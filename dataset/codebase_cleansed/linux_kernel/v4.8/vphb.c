static int cxl_dma_set_mask(struct pci_dev *pdev, u64 dma_mask)
{
if (dma_mask < DMA_BIT_MASK(64)) {
pr_info("%s only 64bit DMA supported on CXL", __func__);
return -EIO;
}
*(pdev->dev.dma_mask) = dma_mask;
return 0;
}
static int cxl_pci_probe_mode(struct pci_bus *bus)
{
return PCI_PROBE_NORMAL;
}
static int cxl_setup_msi_irqs(struct pci_dev *pdev, int nvec, int type)
{
return -ENODEV;
}
static void cxl_teardown_msi_irqs(struct pci_dev *pdev)
{
}
static bool cxl_pci_enable_device_hook(struct pci_dev *dev)
{
struct pci_controller *phb;
struct cxl_afu *afu;
phb = pci_bus_to_host(dev->bus);
afu = (struct cxl_afu *)phb->private_data;
if (!cxl_ops->link_ok(afu->adapter, afu)) {
dev_warn(&dev->dev, "%s: Device link is down, refusing to enable AFU\n", __func__);
return false;
}
set_dma_ops(&dev->dev, &dma_direct_ops);
set_dma_offset(&dev->dev, PAGE_OFFSET);
return _cxl_pci_associate_default_context(dev, afu);
}
static resource_size_t cxl_pci_window_alignment(struct pci_bus *bus,
unsigned long type)
{
return 1;
}
static void cxl_pci_reset_secondary_bus(struct pci_dev *dev)
{
}
static int cxl_pcie_cfg_record(u8 bus, u8 devfn)
{
return (bus << 8) + devfn;
}
static int cxl_pcie_config_info(struct pci_bus *bus, unsigned int devfn,
struct cxl_afu **_afu, int *_record)
{
struct pci_controller *phb;
struct cxl_afu *afu;
int record;
phb = pci_bus_to_host(bus);
if (phb == NULL)
return PCIBIOS_DEVICE_NOT_FOUND;
afu = (struct cxl_afu *)phb->private_data;
record = cxl_pcie_cfg_record(bus->number, devfn);
if (record > afu->crs_num)
return PCIBIOS_DEVICE_NOT_FOUND;
*_afu = afu;
*_record = record;
return 0;
}
static int cxl_pcie_read_config(struct pci_bus *bus, unsigned int devfn,
int offset, int len, u32 *val)
{
int rc, record;
struct cxl_afu *afu;
u8 val8;
u16 val16;
u32 val32;
rc = cxl_pcie_config_info(bus, devfn, &afu, &record);
if (rc)
return rc;
switch (len) {
case 1:
rc = cxl_ops->afu_cr_read8(afu, record, offset, &val8);
*val = val8;
break;
case 2:
rc = cxl_ops->afu_cr_read16(afu, record, offset, &val16);
*val = val16;
break;
case 4:
rc = cxl_ops->afu_cr_read32(afu, record, offset, &val32);
*val = val32;
break;
default:
WARN_ON(1);
}
if (rc)
return PCIBIOS_DEVICE_NOT_FOUND;
return PCIBIOS_SUCCESSFUL;
}
static int cxl_pcie_write_config(struct pci_bus *bus, unsigned int devfn,
int offset, int len, u32 val)
{
int rc, record;
struct cxl_afu *afu;
rc = cxl_pcie_config_info(bus, devfn, &afu, &record);
if (rc)
return rc;
switch (len) {
case 1:
rc = cxl_ops->afu_cr_write8(afu, record, offset, val & 0xff);
break;
case 2:
rc = cxl_ops->afu_cr_write16(afu, record, offset, val & 0xffff);
break;
case 4:
rc = cxl_ops->afu_cr_write32(afu, record, offset, val);
break;
default:
WARN_ON(1);
}
if (rc)
return PCIBIOS_SET_FAILED;
return PCIBIOS_SUCCESSFUL;
}
int cxl_pci_vphb_add(struct cxl_afu *afu)
{
struct pci_controller *phb;
struct device_node *vphb_dn;
struct device *parent;
if (!afu->crs_num)
return 0;
parent = afu->adapter->dev.parent;
vphb_dn = parent->of_node;
phb = pcibios_alloc_controller(vphb_dn);
if (!phb)
return -ENODEV;
phb->parent = parent;
phb->ops = &cxl_pcie_pci_ops;
phb->cfg_addr = NULL;
phb->cfg_data = NULL;
phb->private_data = afu;
phb->controller_ops = cxl_pci_controller_ops;
pcibios_scan_phb(phb);
if (phb->bus == NULL)
return -ENXIO;
pci_set_host_bridge_release(to_pci_host_bridge(phb->bus->bridge),
pcibios_free_controller_deferred,
(void *) phb);
pcibios_claim_one_bus(phb->bus);
pci_bus_add_devices(phb->bus);
afu->phb = phb;
return 0;
}
void cxl_pci_vphb_remove(struct cxl_afu *afu)
{
struct pci_controller *phb;
if (!afu || !afu->phb)
return;
phb = afu->phb;
afu->phb = NULL;
pci_remove_root_bus(phb->bus);
}
static bool _cxl_pci_is_vphb_device(struct pci_controller *phb)
{
return (phb->ops == &cxl_pcie_pci_ops);
}
bool cxl_pci_is_vphb_device(struct pci_dev *dev)
{
struct pci_controller *phb;
phb = pci_bus_to_host(dev->bus);
return _cxl_pci_is_vphb_device(phb);
}
struct cxl_afu *cxl_pci_to_afu(struct pci_dev *dev)
{
struct pci_controller *phb;
phb = pci_bus_to_host(dev->bus);
if (_cxl_pci_is_vphb_device(phb))
return (struct cxl_afu *)phb->private_data;
if (pnv_pci_on_cxl_phb(dev))
return pnv_cxl_phb_to_afu(phb);
return ERR_PTR(-ENODEV);
}
unsigned int cxl_pci_to_cfg_record(struct pci_dev *dev)
{
return cxl_pcie_cfg_record(dev->bus->number, dev->devfn);
}
