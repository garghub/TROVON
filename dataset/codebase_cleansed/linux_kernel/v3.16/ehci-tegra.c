static int tegra_ehci_internal_port_reset(
struct ehci_hcd *ehci,
u32 __iomem *portsc_reg
)
{
u32 temp;
unsigned long flags;
int retval = 0;
int i, tries;
u32 saved_usbintr;
spin_lock_irqsave(&ehci->lock, flags);
saved_usbintr = ehci_readl(ehci, &ehci->regs->intr_enable);
ehci_writel(ehci, 0, &ehci->regs->intr_enable);
spin_unlock_irqrestore(&ehci->lock, flags);
for (i = 0; i < 2; i++) {
temp = ehci_readl(ehci, portsc_reg);
temp |= PORT_RESET;
ehci_writel(ehci, temp, portsc_reg);
mdelay(10);
temp &= ~PORT_RESET;
ehci_writel(ehci, temp, portsc_reg);
mdelay(1);
tries = 100;
do {
mdelay(1);
temp = ehci_readl(ehci, portsc_reg);
} while (!(temp & PORT_PE) && tries--);
if (temp & PORT_PE)
break;
}
if (i == 2)
retval = -ETIMEDOUT;
if (temp & PORT_CSC)
ehci_writel(ehci, PORT_CSC, portsc_reg);
temp = ehci_readl(ehci, &ehci->regs->status);
ehci_writel(ehci, temp, &ehci->regs->status);
ehci_writel(ehci, saved_usbintr, &ehci->regs->intr_enable);
return retval;
}
static int tegra_ehci_hub_control(
struct usb_hcd *hcd,
u16 typeReq,
u16 wValue,
u16 wIndex,
char *buf,
u16 wLength
)
{
struct ehci_hcd *ehci = hcd_to_ehci(hcd);
struct tegra_ehci_hcd *tegra = (struct tegra_ehci_hcd *)ehci->priv;
u32 __iomem *status_reg;
u32 temp;
unsigned long flags;
int retval = 0;
status_reg = &ehci->regs->port_status[(wIndex & 0xff) - 1];
spin_lock_irqsave(&ehci->lock, flags);
if (typeReq == GetPortStatus) {
temp = ehci_readl(ehci, status_reg);
if (tegra->port_resuming && !(temp & PORT_SUSPEND)) {
tegra->port_resuming = 0;
tegra_usb_phy_postresume(hcd->phy);
}
}
else if (typeReq == SetPortFeature && wValue == USB_PORT_FEAT_SUSPEND) {
temp = ehci_readl(ehci, status_reg);
if ((temp & PORT_PE) == 0 || (temp & PORT_RESET) != 0) {
retval = -EPIPE;
goto done;
}
temp &= ~(PORT_RWC_BITS | PORT_WKCONN_E);
temp |= PORT_WKDISC_E | PORT_WKOC_E;
ehci_writel(ehci, temp | PORT_SUSPEND, status_reg);
if (ehci_handshake(ehci, status_reg, PORT_SUSPEND,
PORT_SUSPEND, 5000))
pr_err("%s: timeout waiting for SUSPEND\n", __func__);
set_bit((wIndex & 0xff) - 1, &ehci->suspended_ports);
goto done;
}
if (tegra->needs_double_reset &&
(typeReq == SetPortFeature && wValue == USB_PORT_FEAT_RESET)) {
spin_unlock_irqrestore(&ehci->lock, flags);
return tegra_ehci_internal_port_reset(ehci, status_reg);
}
else if (typeReq == ClearPortFeature &&
wValue == USB_PORT_FEAT_SUSPEND) {
temp = ehci_readl(ehci, status_reg);
if ((temp & PORT_RESET) || !(temp & PORT_PE)) {
retval = -EPIPE;
goto done;
}
if (!(temp & PORT_SUSPEND))
goto done;
tegra_usb_phy_preresume(hcd->phy);
ehci->reset_done[wIndex-1] = jiffies + msecs_to_jiffies(25);
temp &= ~(PORT_RWC_BITS | PORT_WAKE_BITS);
ehci_writel(ehci, temp | PORT_RESUME, status_reg);
set_bit(wIndex-1, &ehci->resuming_ports);
spin_unlock_irqrestore(&ehci->lock, flags);
msleep(20);
spin_lock_irqsave(&ehci->lock, flags);
if (ehci_handshake(ehci, status_reg, PORT_RESUME, 0, 2000))
pr_err("%s: timeout waiting for RESUME\n", __func__);
if (ehci_handshake(ehci, status_reg, PORT_SUSPEND, 0, 2000))
pr_err("%s: timeout waiting for SUSPEND\n", __func__);
ehci->reset_done[wIndex-1] = 0;
clear_bit(wIndex-1, &ehci->resuming_ports);
tegra->port_resuming = 1;
goto done;
}
spin_unlock_irqrestore(&ehci->lock, flags);
return ehci_hub_control(hcd, typeReq, wValue, wIndex, buf, wLength);
done:
spin_unlock_irqrestore(&ehci->lock, flags);
return retval;
}
static void free_dma_aligned_buffer(struct urb *urb)
{
struct dma_aligned_buffer *temp;
if (!(urb->transfer_flags & URB_ALIGNED_TEMP_BUFFER))
return;
temp = container_of(urb->transfer_buffer,
struct dma_aligned_buffer, data);
if (usb_urb_dir_in(urb))
memcpy(temp->old_xfer_buffer, temp->data,
urb->transfer_buffer_length);
urb->transfer_buffer = temp->old_xfer_buffer;
kfree(temp->kmalloc_ptr);
urb->transfer_flags &= ~URB_ALIGNED_TEMP_BUFFER;
}
static int alloc_dma_aligned_buffer(struct urb *urb, gfp_t mem_flags)
{
struct dma_aligned_buffer *temp, *kmalloc_ptr;
size_t kmalloc_size;
if (urb->num_sgs || urb->sg ||
urb->transfer_buffer_length == 0 ||
!((uintptr_t)urb->transfer_buffer & (TEGRA_USB_DMA_ALIGN - 1)))
return 0;
kmalloc_size = urb->transfer_buffer_length +
sizeof(struct dma_aligned_buffer) + TEGRA_USB_DMA_ALIGN - 1;
kmalloc_ptr = kmalloc(kmalloc_size, mem_flags);
if (!kmalloc_ptr)
return -ENOMEM;
temp = PTR_ALIGN(kmalloc_ptr + 1, TEGRA_USB_DMA_ALIGN) - 1;
temp->kmalloc_ptr = kmalloc_ptr;
temp->old_xfer_buffer = urb->transfer_buffer;
if (usb_urb_dir_out(urb))
memcpy(temp->data, urb->transfer_buffer,
urb->transfer_buffer_length);
urb->transfer_buffer = temp->data;
urb->transfer_flags |= URB_ALIGNED_TEMP_BUFFER;
return 0;
}
static int tegra_ehci_map_urb_for_dma(struct usb_hcd *hcd, struct urb *urb,
gfp_t mem_flags)
{
int ret;
ret = alloc_dma_aligned_buffer(urb, mem_flags);
if (ret)
return ret;
ret = usb_hcd_map_urb_for_dma(hcd, urb, mem_flags);
if (ret)
free_dma_aligned_buffer(urb);
return ret;
}
static void tegra_ehci_unmap_urb_for_dma(struct usb_hcd *hcd, struct urb *urb)
{
usb_hcd_unmap_urb_for_dma(hcd, urb);
free_dma_aligned_buffer(urb);
}
static int tegra_ehci_probe(struct platform_device *pdev)
{
const struct of_device_id *match;
const struct tegra_ehci_soc_config *soc_config;
struct resource *res;
struct usb_hcd *hcd;
struct ehci_hcd *ehci;
struct tegra_ehci_hcd *tegra;
int err = 0;
int irq;
struct usb_phy *u_phy;
match = of_match_device(tegra_ehci_of_match, &pdev->dev);
if (!match) {
dev_err(&pdev->dev, "Error: No device match found\n");
return -ENODEV;
}
soc_config = match->data;
err = dma_coerce_mask_and_coherent(&pdev->dev, DMA_BIT_MASK(32));
if (err)
return err;
hcd = usb_create_hcd(&tegra_ehci_hc_driver, &pdev->dev,
dev_name(&pdev->dev));
if (!hcd) {
dev_err(&pdev->dev, "Unable to create HCD\n");
return -ENOMEM;
}
platform_set_drvdata(pdev, hcd);
ehci = hcd_to_ehci(hcd);
tegra = (struct tegra_ehci_hcd *)ehci->priv;
hcd->has_tt = 1;
tegra->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(tegra->clk)) {
dev_err(&pdev->dev, "Can't get ehci clock\n");
err = PTR_ERR(tegra->clk);
goto cleanup_hcd_create;
}
tegra->rst = devm_reset_control_get(&pdev->dev, "usb");
if (IS_ERR(tegra->rst)) {
dev_err(&pdev->dev, "Can't get ehci reset\n");
err = PTR_ERR(tegra->rst);
goto cleanup_hcd_create;
}
err = clk_prepare_enable(tegra->clk);
if (err)
goto cleanup_hcd_create;
reset_control_assert(tegra->rst);
udelay(1);
reset_control_deassert(tegra->rst);
u_phy = devm_usb_get_phy_by_phandle(&pdev->dev, "nvidia,phy", 0);
if (IS_ERR(u_phy)) {
err = PTR_ERR(u_phy);
goto cleanup_clk_en;
}
hcd->phy = u_phy;
tegra->needs_double_reset = of_property_read_bool(pdev->dev.of_node,
"nvidia,needs-double-reset");
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(&pdev->dev, "Failed to get I/O memory\n");
err = -ENXIO;
goto cleanup_clk_en;
}
hcd->rsrc_start = res->start;
hcd->rsrc_len = resource_size(res);
hcd->regs = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(hcd->regs)) {
err = PTR_ERR(hcd->regs);
goto cleanup_clk_en;
}
ehci->caps = hcd->regs + 0x100;
ehci->has_hostpc = soc_config->has_hostpc;
err = usb_phy_init(hcd->phy);
if (err) {
dev_err(&pdev->dev, "Failed to initialize phy\n");
goto cleanup_clk_en;
}
u_phy->otg = devm_kzalloc(&pdev->dev, sizeof(struct usb_otg),
GFP_KERNEL);
if (!u_phy->otg) {
dev_err(&pdev->dev, "Failed to alloc memory for otg\n");
err = -ENOMEM;
goto cleanup_phy;
}
u_phy->otg->host = hcd_to_bus(hcd);
err = usb_phy_set_suspend(hcd->phy, 0);
if (err) {
dev_err(&pdev->dev, "Failed to power on the phy\n");
goto cleanup_phy;
}
irq = platform_get_irq(pdev, 0);
if (!irq) {
dev_err(&pdev->dev, "Failed to get IRQ\n");
err = -ENODEV;
goto cleanup_phy;
}
otg_set_host(u_phy->otg, &hcd->self);
err = usb_add_hcd(hcd, irq, IRQF_SHARED);
if (err) {
dev_err(&pdev->dev, "Failed to add USB HCD\n");
goto cleanup_otg_set_host;
}
device_wakeup_enable(hcd->self.controller);
return err;
cleanup_otg_set_host:
otg_set_host(u_phy->otg, NULL);
cleanup_phy:
usb_phy_shutdown(hcd->phy);
cleanup_clk_en:
clk_disable_unprepare(tegra->clk);
cleanup_hcd_create:
usb_put_hcd(hcd);
return err;
}
static int tegra_ehci_remove(struct platform_device *pdev)
{
struct usb_hcd *hcd = platform_get_drvdata(pdev);
struct tegra_ehci_hcd *tegra =
(struct tegra_ehci_hcd *)hcd_to_ehci(hcd)->priv;
otg_set_host(hcd->phy->otg, NULL);
usb_phy_shutdown(hcd->phy);
usb_remove_hcd(hcd);
usb_put_hcd(hcd);
clk_disable_unprepare(tegra->clk);
return 0;
}
static void tegra_ehci_hcd_shutdown(struct platform_device *pdev)
{
struct usb_hcd *hcd = platform_get_drvdata(pdev);
if (hcd->driver->shutdown)
hcd->driver->shutdown(hcd);
}
static int tegra_ehci_reset(struct usb_hcd *hcd)
{
struct ehci_hcd *ehci = hcd_to_ehci(hcd);
int retval;
int txfifothresh;
retval = ehci_setup(hcd);
if (retval)
return retval;
txfifothresh = ehci->has_hostpc ? 0x10 : 10;
ehci_writel(ehci, txfifothresh << 16, &ehci->regs->txfill_tuning);
return 0;
}
static int __init ehci_tegra_init(void)
{
if (usb_disabled())
return -ENODEV;
pr_info(DRV_NAME ": " DRIVER_DESC "\n");
ehci_init_driver(&tegra_ehci_hc_driver, &tegra_overrides);
tegra_ehci_hc_driver.map_urb_for_dma = tegra_ehci_map_urb_for_dma;
tegra_ehci_hc_driver.unmap_urb_for_dma = tegra_ehci_unmap_urb_for_dma;
tegra_ehci_hc_driver.hub_control = tegra_ehci_hub_control;
return platform_driver_register(&tegra_ehci_driver);
}
static void __exit ehci_tegra_cleanup(void)
{
platform_driver_unregister(&tegra_ehci_driver);
}
