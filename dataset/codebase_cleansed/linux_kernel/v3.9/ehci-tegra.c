static void tegra_ehci_power_up(struct usb_hcd *hcd)
{
struct tegra_ehci_hcd *tegra = dev_get_drvdata(hcd->self.controller);
clk_prepare_enable(tegra->clk);
usb_phy_set_suspend(hcd->phy, 0);
tegra->host_resumed = 1;
}
static void tegra_ehci_power_down(struct usb_hcd *hcd)
{
struct tegra_ehci_hcd *tegra = dev_get_drvdata(hcd->self.controller);
tegra->host_resumed = 0;
usb_phy_set_suspend(hcd->phy, 1);
clk_disable_unprepare(tegra->clk);
}
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
struct tegra_ehci_hcd *tegra = dev_get_drvdata(hcd->self.controller);
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
if (handshake(ehci, status_reg, PORT_SUSPEND,
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
if (handshake(ehci, status_reg, PORT_RESUME, 0, 2000))
pr_err("%s: timeout waiting for RESUME\n", __func__);
if (handshake(ehci, status_reg, PORT_SUSPEND, 0, 2000))
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
static void tegra_ehci_restart(struct usb_hcd *hcd)
{
struct ehci_hcd *ehci = hcd_to_ehci(hcd);
ehci_reset(ehci);
ehci_writel(ehci, ehci->periodic_dma, &ehci->regs->frame_list);
ehci_writel(ehci, (u32)ehci->async->qh_dma, &ehci->regs->async_next);
ehci->command &= ~(CMD_LRESET|CMD_IAAD|CMD_PSE|CMD_ASE|CMD_RESET);
ehci->command |= CMD_RUN;
ehci_writel(ehci, ehci->command, &ehci->regs->command);
down_write(&ehci_cf_port_reset_rwsem);
ehci_writel(ehci, FLAG_CF, &ehci->regs->configured_flag);
ehci_readl(ehci, &ehci->regs->command);
up_write(&ehci_cf_port_reset_rwsem);
}
static void tegra_ehci_shutdown(struct usb_hcd *hcd)
{
struct tegra_ehci_hcd *tegra = dev_get_drvdata(hcd->self.controller);
if (!tegra->host_resumed)
tegra_ehci_power_up(hcd);
ehci_shutdown(hcd);
}
static int tegra_ehci_setup(struct usb_hcd *hcd)
{
struct ehci_hcd *ehci = hcd_to_ehci(hcd);
ehci->caps = hcd->regs + 0x100;
hcd->has_tt = 1;
return ehci_setup(hcd);
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
static int setup_vbus_gpio(struct platform_device *pdev,
struct tegra_ehci_platform_data *pdata)
{
int err = 0;
int gpio;
gpio = pdata->vbus_gpio;
if (!gpio_is_valid(gpio))
gpio = of_get_named_gpio(pdev->dev.of_node,
"nvidia,vbus-gpio", 0);
if (!gpio_is_valid(gpio))
return 0;
err = gpio_request(gpio, "vbus_gpio");
if (err) {
dev_err(&pdev->dev, "can't request vbus gpio %d", gpio);
return err;
}
err = gpio_direction_output(gpio, 1);
if (err) {
dev_err(&pdev->dev, "can't enable vbus\n");
return err;
}
return err;
}
static int controller_suspend(struct device *dev)
{
struct tegra_ehci_hcd *tegra =
platform_get_drvdata(to_platform_device(dev));
struct ehci_hcd *ehci = tegra->ehci;
struct usb_hcd *hcd = ehci_to_hcd(ehci);
struct ehci_regs __iomem *hw = ehci->regs;
unsigned long flags;
if (time_before(jiffies, ehci->next_statechange))
msleep(10);
ehci_halt(ehci);
spin_lock_irqsave(&ehci->lock, flags);
tegra->port_speed = (readl(&hw->port_status[0]) >> 26) & 0x3;
clear_bit(HCD_FLAG_HW_ACCESSIBLE, &hcd->flags);
spin_unlock_irqrestore(&ehci->lock, flags);
tegra_ehci_power_down(hcd);
return 0;
}
static int controller_resume(struct device *dev)
{
struct tegra_ehci_hcd *tegra =
platform_get_drvdata(to_platform_device(dev));
struct ehci_hcd *ehci = tegra->ehci;
struct usb_hcd *hcd = ehci_to_hcd(ehci);
struct ehci_regs __iomem *hw = ehci->regs;
unsigned long val;
set_bit(HCD_FLAG_HW_ACCESSIBLE, &hcd->flags);
tegra_ehci_power_up(hcd);
if (tegra->port_speed > TEGRA_USB_PHY_PORT_SPEED_HIGH) {
msleep(10);
goto restart;
}
tegra_ehci_phy_restore_start(hcd->phy, tegra->port_speed);
tdi_reset(ehci);
val = readl(&hw->port_status[0]);
val |= PORT_POWER;
writel(val, &hw->port_status[0]);
udelay(10);
if (!readl(&hw->async_next)) {
val = readl(&hw->port_status[0]);
val &= ~PORT_TEST(~0);
if (tegra->port_speed == TEGRA_USB_PHY_PORT_SPEED_HIGH)
val |= PORT_TEST_FORCE;
else if (tegra->port_speed == TEGRA_USB_PHY_PORT_SPEED_FULL)
val |= PORT_TEST(6);
else if (tegra->port_speed == TEGRA_USB_PHY_PORT_SPEED_LOW)
val |= PORT_TEST(7);
writel(val, &hw->port_status[0]);
udelay(10);
val = readl(&hw->port_status[0]);
val &= ~PORT_TEST(~0);
writel(val, &hw->port_status[0]);
udelay(10);
}
if (handshake(ehci, &hw->port_status[0], PORT_CONNECT,
PORT_CONNECT, 2000)) {
pr_err("%s: timeout waiting for PORT_CONNECT\n", __func__);
goto restart;
}
if (handshake(ehci, &hw->port_status[0], PORT_PE,
PORT_PE, 2000)) {
pr_err("%s: timeout waiting for USB_PORTSC1_PE\n", __func__);
goto restart;
}
val = readl(&hw->status);
val |= STS_PCD;
writel(val, &hw->status);
val = readl(&hw->port_status[0]);
if ((val & PORT_POWER) && (val & PORT_PE)) {
val |= PORT_SUSPEND;
writel(val, &hw->port_status[0]);
if (handshake(ehci, &hw->port_status[0], PORT_SUSPEND,
PORT_SUSPEND, 1000)) {
pr_err("%s: timeout waiting for PORT_SUSPEND\n",
__func__);
goto restart;
}
}
tegra_ehci_phy_restore_end(hcd->phy);
goto done;
restart:
if (tegra->port_speed <= TEGRA_USB_PHY_PORT_SPEED_HIGH)
tegra_ehci_phy_restore_end(hcd->phy);
tegra_ehci_restart(hcd);
done:
tegra_usb_phy_preresume(hcd->phy);
tegra->port_resuming = 1;
return 0;
}
static int tegra_ehci_suspend(struct device *dev)
{
struct tegra_ehci_hcd *tegra =
platform_get_drvdata(to_platform_device(dev));
struct usb_hcd *hcd = ehci_to_hcd(tegra->ehci);
int rc = 0;
if (HCD_HW_ACCESSIBLE(hcd))
rc = controller_suspend(dev);
return rc;
}
static int tegra_ehci_resume(struct device *dev)
{
int rc;
rc = controller_resume(dev);
if (rc == 0) {
pm_runtime_disable(dev);
pm_runtime_set_active(dev);
pm_runtime_enable(dev);
}
return rc;
}
static int tegra_ehci_runtime_suspend(struct device *dev)
{
return controller_suspend(dev);
}
static int tegra_ehci_runtime_resume(struct device *dev)
{
return controller_resume(dev);
}
void tegra_ehci_set_pts(struct usb_phy *x, u8 pts_val)
{
unsigned long val;
struct usb_hcd *hcd = bus_to_hcd(x->otg->host);
void __iomem *base = hcd->regs;
val = readl(base + TEGRA_USB_PORTSC1) & ~TEGRA_PORTSC1_RWC_BITS;
val &= ~TEGRA_USB_PORTSC1_PTS(3);
val |= TEGRA_USB_PORTSC1_PTS(pts_val & 3);
writel(val, base + TEGRA_USB_PORTSC1);
}
void tegra_ehci_set_phcd(struct usb_phy *x, bool enable)
{
unsigned long val;
struct usb_hcd *hcd = bus_to_hcd(x->otg->host);
void __iomem *base = hcd->regs;
val = readl(base + TEGRA_USB_PORTSC1) & ~TEGRA_PORTSC1_RWC_BITS;
if (enable)
val |= TEGRA_USB_PORTSC1_PHCD;
else
val &= ~TEGRA_USB_PORTSC1_PHCD;
writel(val, base + TEGRA_USB_PORTSC1);
}
static int tegra_ehci_probe(struct platform_device *pdev)
{
struct resource *res;
struct usb_hcd *hcd;
struct tegra_ehci_hcd *tegra;
struct tegra_ehci_platform_data *pdata;
int err = 0;
int irq;
int instance = pdev->id;
struct usb_phy *u_phy;
pdata = pdev->dev.platform_data;
if (!pdata) {
dev_err(&pdev->dev, "Platform data missing\n");
return -EINVAL;
}
if (!pdev->dev.dma_mask)
pdev->dev.dma_mask = &tegra_ehci_dma_mask;
setup_vbus_gpio(pdev, pdata);
tegra = devm_kzalloc(&pdev->dev, sizeof(struct tegra_ehci_hcd),
GFP_KERNEL);
if (!tegra)
return -ENOMEM;
hcd = usb_create_hcd(&tegra_ehci_hc_driver, &pdev->dev,
dev_name(&pdev->dev));
if (!hcd) {
dev_err(&pdev->dev, "Unable to create HCD\n");
return -ENOMEM;
}
platform_set_drvdata(pdev, tegra);
tegra->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(tegra->clk)) {
dev_err(&pdev->dev, "Can't get ehci clock\n");
err = PTR_ERR(tegra->clk);
goto fail_clk;
}
err = clk_prepare_enable(tegra->clk);
if (err)
goto fail_clk;
tegra->needs_double_reset = of_property_read_bool(pdev->dev.of_node,
"nvidia,needs-double-reset");
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(&pdev->dev, "Failed to get I/O memory\n");
err = -ENXIO;
goto fail_io;
}
hcd->rsrc_start = res->start;
hcd->rsrc_len = resource_size(res);
hcd->regs = devm_ioremap(&pdev->dev, res->start, resource_size(res));
if (!hcd->regs) {
dev_err(&pdev->dev, "Failed to remap I/O memory\n");
err = -ENOMEM;
goto fail_io;
}
if (instance < 0) {
switch (res->start) {
case TEGRA_USB_BASE:
instance = 0;
break;
case TEGRA_USB2_BASE:
instance = 1;
break;
case TEGRA_USB3_BASE:
instance = 2;
break;
default:
err = -ENODEV;
dev_err(&pdev->dev, "unknown usb instance\n");
goto fail_io;
}
}
tegra->phy = tegra_usb_phy_open(&pdev->dev, instance, hcd->regs,
pdata->phy_config,
TEGRA_USB_PHY_MODE_HOST);
if (IS_ERR(tegra->phy)) {
dev_err(&pdev->dev, "Failed to open USB phy\n");
err = -ENXIO;
goto fail_io;
}
hcd->phy = u_phy = &tegra->phy->u_phy;
usb_phy_init(hcd->phy);
u_phy->otg = devm_kzalloc(&pdev->dev, sizeof(struct usb_otg),
GFP_KERNEL);
if (!u_phy->otg) {
dev_err(&pdev->dev, "Failed to alloc memory for otg\n");
err = -ENOMEM;
goto fail_io;
}
u_phy->otg->host = hcd_to_bus(hcd);
err = usb_phy_set_suspend(hcd->phy, 0);
if (err) {
dev_err(&pdev->dev, "Failed to power on the phy\n");
goto fail;
}
tegra->host_resumed = 1;
tegra->ehci = hcd_to_ehci(hcd);
irq = platform_get_irq(pdev, 0);
if (!irq) {
dev_err(&pdev->dev, "Failed to get IRQ\n");
err = -ENODEV;
goto fail;
}
#ifdef CONFIG_USB_OTG_UTILS
if (pdata->operating_mode == TEGRA_USB_OTG) {
tegra->transceiver =
devm_usb_get_phy(&pdev->dev, USB_PHY_TYPE_USB2);
if (!IS_ERR_OR_NULL(tegra->transceiver))
otg_set_host(tegra->transceiver->otg, &hcd->self);
}
#endif
err = usb_add_hcd(hcd, irq, IRQF_SHARED);
if (err) {
dev_err(&pdev->dev, "Failed to add USB HCD\n");
goto fail;
}
pm_runtime_set_active(&pdev->dev);
pm_runtime_get_noresume(&pdev->dev);
pm_runtime_forbid(&pdev->dev);
pm_runtime_enable(&pdev->dev);
pm_runtime_put_sync(&pdev->dev);
return err;
fail:
#ifdef CONFIG_USB_OTG_UTILS
if (!IS_ERR_OR_NULL(tegra->transceiver))
otg_set_host(tegra->transceiver->otg, NULL);
#endif
usb_phy_shutdown(hcd->phy);
fail_io:
clk_disable_unprepare(tegra->clk);
fail_clk:
usb_put_hcd(hcd);
return err;
}
static int tegra_ehci_remove(struct platform_device *pdev)
{
struct tegra_ehci_hcd *tegra = platform_get_drvdata(pdev);
struct usb_hcd *hcd = ehci_to_hcd(tegra->ehci);
pm_runtime_get_sync(&pdev->dev);
pm_runtime_disable(&pdev->dev);
pm_runtime_put_noidle(&pdev->dev);
#ifdef CONFIG_USB_OTG_UTILS
if (!IS_ERR_OR_NULL(tegra->transceiver))
otg_set_host(tegra->transceiver->otg, NULL);
#endif
usb_phy_shutdown(hcd->phy);
usb_remove_hcd(hcd);
usb_put_hcd(hcd);
clk_disable_unprepare(tegra->clk);
return 0;
}
static void tegra_ehci_hcd_shutdown(struct platform_device *pdev)
{
struct tegra_ehci_hcd *tegra = platform_get_drvdata(pdev);
struct usb_hcd *hcd = ehci_to_hcd(tegra->ehci);
if (hcd->driver->shutdown)
hcd->driver->shutdown(hcd);
}
