static void ehci_octeon_start(void)
{
union cvmx_uctlx_ehci_ctl ehci_ctl;
octeon2_usb_clocks_start();
ehci_ctl.u64 = cvmx_read_csr(CVMX_UCTLX_EHCI_CTL(0));
ehci_ctl.s.ehci_64b_addr_en = 1;
ehci_ctl.s.l2c_addr_msb = 0;
ehci_ctl.s.l2c_buff_emod = 1;
ehci_ctl.s.l2c_desc_emod = 1;
cvmx_write_csr(CVMX_UCTLX_EHCI_CTL(0), ehci_ctl.u64);
}
static void ehci_octeon_stop(void)
{
octeon2_usb_clocks_stop();
}
static int ehci_octeon_drv_probe(struct platform_device *pdev)
{
struct usb_hcd *hcd;
struct ehci_hcd *ehci;
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
pdev->dev.dma_mask = &ehci_octeon_dma_mask;
ret = dma_set_coherent_mask(&pdev->dev, DMA_BIT_MASK(32));
if (ret)
return ret;
hcd = usb_create_hcd(&ehci_octeon_hc_driver, &pdev->dev, "octeon");
if (!hcd)
return -ENOMEM;
hcd->rsrc_start = res_mem->start;
hcd->rsrc_len = resource_size(res_mem);
hcd->regs = devm_ioremap_resource(&pdev->dev, res_mem);
if (IS_ERR(hcd->regs)) {
ret = PTR_ERR(hcd->regs);
goto err1;
}
ehci_octeon_start();
ehci = hcd_to_ehci(hcd);
#ifdef __BIG_ENDIAN
ehci->big_endian_mmio = 1;
#endif
ehci->caps = hcd->regs;
ret = usb_add_hcd(hcd, irq, IRQF_SHARED);
if (ret) {
dev_dbg(&pdev->dev, "failed to add hcd with err %d\n", ret);
goto err2;
}
device_wakeup_enable(hcd->self.controller);
platform_set_drvdata(pdev, hcd);
return 0;
err2:
ehci_octeon_stop();
err1:
usb_put_hcd(hcd);
return ret;
}
static int ehci_octeon_drv_remove(struct platform_device *pdev)
{
struct usb_hcd *hcd = platform_get_drvdata(pdev);
usb_remove_hcd(hcd);
ehci_octeon_stop();
usb_put_hcd(hcd);
return 0;
}
