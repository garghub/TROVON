static void ohci_octeon_hw_start(void)
{
union cvmx_uctlx_ohci_ctl ohci_ctl;
octeon2_usb_clocks_start();
ohci_ctl.u64 = cvmx_read_csr(CVMX_UCTLX_OHCI_CTL(0));
ohci_ctl.s.l2c_addr_msb = 0;
ohci_ctl.s.l2c_buff_emod = 1;
ohci_ctl.s.l2c_desc_emod = 1;
cvmx_write_csr(CVMX_UCTLX_OHCI_CTL(0), ohci_ctl.u64);
}
static void ohci_octeon_hw_stop(void)
{
octeon2_usb_clocks_stop();
}
static int ohci_octeon_start(struct usb_hcd *hcd)
{
struct ohci_hcd *ohci = hcd_to_ohci(hcd);
int ret;
ret = ohci_init(ohci);
if (ret < 0)
return ret;
ret = ohci_run(ohci);
if (ret < 0) {
ohci_err(ohci, "can't start %s", hcd->self.bus_name);
ohci_stop(hcd);
return ret;
}
return 0;
}
static int ohci_octeon_drv_probe(struct platform_device *pdev)
{
struct usb_hcd *hcd;
struct ohci_hcd *ohci;
void *reg_base;
struct resource *res_mem;
int irq;
int ret;
if (usb_disabled())
return -ENODEV;
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(&pdev->dev, "No irq assigned\n");
return -ENODEV;
}
res_mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (res_mem == NULL) {
dev_err(&pdev->dev, "No register space assigned\n");
return -ENODEV;
}
pdev->dev.coherent_dma_mask = DMA_BIT_MASK(32);
pdev->dev.dma_mask = &pdev->dev.coherent_dma_mask;
hcd = usb_create_hcd(&ohci_octeon_hc_driver, &pdev->dev, "octeon");
if (!hcd)
return -ENOMEM;
hcd->rsrc_start = res_mem->start;
hcd->rsrc_len = resource_size(res_mem);
if (!request_mem_region(hcd->rsrc_start, hcd->rsrc_len,
OCTEON_OHCI_HCD_NAME)) {
dev_err(&pdev->dev, "request_mem_region failed\n");
ret = -EBUSY;
goto err1;
}
reg_base = ioremap(hcd->rsrc_start, hcd->rsrc_len);
if (!reg_base) {
dev_err(&pdev->dev, "ioremap failed\n");
ret = -ENOMEM;
goto err2;
}
ohci_octeon_hw_start();
hcd->regs = reg_base;
ohci = hcd_to_ohci(hcd);
#ifdef __BIG_ENDIAN
ohci->flags |= OHCI_QUIRK_BE_MMIO;
#endif
ohci_hcd_init(ohci);
ret = usb_add_hcd(hcd, irq, IRQF_SHARED);
if (ret) {
dev_dbg(&pdev->dev, "failed to add hcd with err %d\n", ret);
goto err3;
}
platform_set_drvdata(pdev, hcd);
return 0;
err3:
ohci_octeon_hw_stop();
iounmap(hcd->regs);
err2:
release_mem_region(hcd->rsrc_start, hcd->rsrc_len);
err1:
usb_put_hcd(hcd);
return ret;
}
static int ohci_octeon_drv_remove(struct platform_device *pdev)
{
struct usb_hcd *hcd = platform_get_drvdata(pdev);
usb_remove_hcd(hcd);
ohci_octeon_hw_stop();
iounmap(hcd->regs);
release_mem_region(hcd->rsrc_start, hcd->rsrc_len);
usb_put_hcd(hcd);
return 0;
}
