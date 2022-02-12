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
ret = dma_coerce_mask_and_coherent(&pdev->dev, DMA_BIT_MASK(32));
if (ret)
return ret;
hcd = usb_create_hcd(&ohci_octeon_hc_driver, &pdev->dev, "octeon");
if (!hcd)
return -ENOMEM;
hcd->rsrc_start = res_mem->start;
hcd->rsrc_len = resource_size(res_mem);
reg_base = devm_ioremap_resource(&pdev->dev, res_mem);
if (IS_ERR(reg_base)) {
ret = PTR_ERR(reg_base);
goto err1;
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
goto err2;
}
device_wakeup_enable(hcd->self.controller);
platform_set_drvdata(pdev, hcd);
return 0;
err2:
ohci_octeon_hw_stop();
err1:
usb_put_hcd(hcd);
return ret;
}
static int ohci_octeon_drv_remove(struct platform_device *pdev)
{
struct usb_hcd *hcd = platform_get_drvdata(pdev);
usb_remove_hcd(hcd);
ohci_octeon_hw_stop();
usb_put_hcd(hcd);
return 0;
}
