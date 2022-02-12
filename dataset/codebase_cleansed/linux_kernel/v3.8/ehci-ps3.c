static void ps3_ehci_setup_insnreg(struct ehci_hcd *ehci)
{
enum ps3_ehci_hc_insnreg {
ps3_ehci_hc_insnreg01 = 0x084,
ps3_ehci_hc_insnreg02 = 0x088,
ps3_ehci_hc_insnreg03 = 0x08c,
};
writel_be(0x01000020, (void __iomem *)ehci->regs +
ps3_ehci_hc_insnreg01);
writel_be(0x00000001, (void __iomem *)ehci->regs +
ps3_ehci_hc_insnreg03);
}
static int ps3_ehci_hc_reset(struct usb_hcd *hcd)
{
int result;
struct ehci_hcd *ehci = hcd_to_ehci(hcd);
ehci->big_endian_mmio = 1;
ehci->caps = hcd->regs;
result = ehci_setup(hcd);
if (result)
return result;
ps3_ehci_setup_insnreg(ehci);
return result;
}
static int ps3_ehci_probe(struct ps3_system_bus_device *dev)
{
int result;
struct usb_hcd *hcd;
unsigned int virq;
static u64 dummy_mask = DMA_BIT_MASK(32);
if (usb_disabled()) {
result = -ENODEV;
goto fail_start;
}
result = ps3_open_hv_device(dev);
if (result) {
dev_dbg(&dev->core, "%s:%d: ps3_open_hv_device failed\n",
__func__, __LINE__);
goto fail_open;
}
result = ps3_dma_region_create(dev->d_region);
if (result) {
dev_dbg(&dev->core, "%s:%d: ps3_dma_region_create failed: "
"(%d)\n", __func__, __LINE__, result);
BUG_ON("check region type");
goto fail_dma_region;
}
result = ps3_mmio_region_create(dev->m_region);
if (result) {
dev_dbg(&dev->core, "%s:%d: ps3_map_mmio_region failed\n",
__func__, __LINE__);
result = -EPERM;
goto fail_mmio_region;
}
dev_dbg(&dev->core, "%s:%d: mmio mapped_addr %lxh\n", __func__,
__LINE__, dev->m_region->lpar_addr);
result = ps3_io_irq_setup(PS3_BINDING_CPU_ANY, dev->interrupt_id, &virq);
if (result) {
dev_dbg(&dev->core, "%s:%d: ps3_construct_io_irq(%d) failed.\n",
__func__, __LINE__, virq);
result = -EPERM;
goto fail_irq;
}
dev->core.dma_mask = &dummy_mask;
hcd = usb_create_hcd(&ps3_ehci_hc_driver, &dev->core, dev_name(&dev->core));
if (!hcd) {
dev_dbg(&dev->core, "%s:%d: usb_create_hcd failed\n", __func__,
__LINE__);
result = -ENOMEM;
goto fail_create_hcd;
}
hcd->rsrc_start = dev->m_region->lpar_addr;
hcd->rsrc_len = dev->m_region->len;
if (!request_mem_region(hcd->rsrc_start, hcd->rsrc_len, hcd_name))
dev_dbg(&dev->core, "%s:%d: request_mem_region failed\n",
__func__, __LINE__);
hcd->regs = ioremap(dev->m_region->lpar_addr, dev->m_region->len);
if (!hcd->regs) {
dev_dbg(&dev->core, "%s:%d: ioremap failed\n", __func__,
__LINE__);
result = -EPERM;
goto fail_ioremap;
}
dev_dbg(&dev->core, "%s:%d: hcd->rsrc_start %lxh\n", __func__, __LINE__,
(unsigned long)hcd->rsrc_start);
dev_dbg(&dev->core, "%s:%d: hcd->rsrc_len %lxh\n", __func__, __LINE__,
(unsigned long)hcd->rsrc_len);
dev_dbg(&dev->core, "%s:%d: hcd->regs %lxh\n", __func__, __LINE__,
(unsigned long)hcd->regs);
dev_dbg(&dev->core, "%s:%d: virq %lu\n", __func__, __LINE__,
(unsigned long)virq);
ps3_system_bus_set_drvdata(dev, hcd);
result = usb_add_hcd(hcd, virq, 0);
if (result) {
dev_dbg(&dev->core, "%s:%d: usb_add_hcd failed (%d)\n",
__func__, __LINE__, result);
goto fail_add_hcd;
}
return result;
fail_add_hcd:
iounmap(hcd->regs);
fail_ioremap:
release_mem_region(hcd->rsrc_start, hcd->rsrc_len);
usb_put_hcd(hcd);
fail_create_hcd:
ps3_io_irq_destroy(virq);
fail_irq:
ps3_free_mmio_region(dev->m_region);
fail_mmio_region:
ps3_dma_region_free(dev->d_region);
fail_dma_region:
ps3_close_hv_device(dev);
fail_open:
fail_start:
return result;
}
static int ps3_ehci_remove(struct ps3_system_bus_device *dev)
{
unsigned int tmp;
struct usb_hcd *hcd = ps3_system_bus_get_drvdata(dev);
BUG_ON(!hcd);
dev_dbg(&dev->core, "%s:%d: regs %p\n", __func__, __LINE__, hcd->regs);
dev_dbg(&dev->core, "%s:%d: irq %u\n", __func__, __LINE__, hcd->irq);
tmp = hcd->irq;
ehci_shutdown(hcd);
usb_remove_hcd(hcd);
ps3_system_bus_set_drvdata(dev, NULL);
BUG_ON(!hcd->regs);
iounmap(hcd->regs);
release_mem_region(hcd->rsrc_start, hcd->rsrc_len);
usb_put_hcd(hcd);
ps3_io_irq_destroy(tmp);
ps3_free_mmio_region(dev->m_region);
ps3_dma_region_free(dev->d_region);
ps3_close_hv_device(dev);
return 0;
}
static int __init ps3_ehci_driver_register(struct ps3_system_bus_driver *drv)
{
return firmware_has_feature(FW_FEATURE_PS3_LV1)
? ps3_system_bus_driver_register(drv)
: 0;
}
static void ps3_ehci_driver_unregister(struct ps3_system_bus_driver *drv)
{
if (firmware_has_feature(FW_FEATURE_PS3_LV1))
ps3_system_bus_driver_unregister(drv);
}
