static void tegra_ehci_power_up(struct usb_hcd *hcd)
{
struct tegra_ehci_hcd *tegra = dev_get_drvdata(hcd->self.controller);
clk_enable(tegra->emc_clk);
clk_enable(tegra->clk);
tegra_usb_phy_power_on(tegra->phy);
tegra->host_resumed = 1;
}
static void tegra_ehci_power_down(struct usb_hcd *hcd)
{
struct tegra_ehci_hcd *tegra = dev_get_drvdata(hcd->self.controller);
tegra->host_resumed = 0;
tegra_usb_phy_power_off(tegra->phy);
clk_disable(tegra->clk);
clk_disable(tegra->emc_clk);
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
if (typeReq == ClearPortFeature && wValue == USB_PORT_FEAT_ENABLE) {
temp = ehci_readl(ehci, status_reg) & ~PORT_RWC_BITS;
ehci_writel(ehci, temp & ~PORT_PE, status_reg);
goto done;
}
else if (typeReq == GetPortStatus) {
temp = ehci_readl(ehci, status_reg);
if (tegra->port_resuming && !(temp & PORT_SUSPEND)) {
tegra->port_resuming = 0;
tegra_usb_phy_postresume(tegra->phy);
}
}
else if (typeReq == SetPortFeature && wValue == USB_PORT_FEAT_SUSPEND) {
temp = ehci_readl(ehci, status_reg);
if ((temp & PORT_PE) == 0 || (temp & PORT_RESET) != 0) {
retval = -EPIPE;
goto done;
}
temp &= ~PORT_WKCONN_E;
temp |= PORT_WKDISC_E | PORT_WKOC_E;
ehci_writel(ehci, temp | PORT_SUSPEND, status_reg);
if (handshake(ehci, status_reg, PORT_SUSPEND,
PORT_SUSPEND, 5000))
pr_err("%s: timeout waiting for SUSPEND\n", __func__);
set_bit((wIndex & 0xff) - 1, &ehci->suspended_ports);
goto done;
}
if (tegra->phy->instance == 0 &&
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
tegra_usb_phy_preresume(tegra->phy);
ehci->reset_done[wIndex-1] = jiffies + msecs_to_jiffies(25);
temp &= ~(PORT_RWC_BITS | PORT_WAKE_BITS);
ehci_writel(ehci, temp | PORT_RESUME, status_reg);
spin_unlock_irqrestore(&ehci->lock, flags);
msleep(20);
spin_lock_irqsave(&ehci->lock, flags);
if (handshake(ehci, status_reg, PORT_RESUME, 0, 2000))
pr_err("%s: timeout waiting for RESUME\n", __func__);
if (handshake(ehci, status_reg, PORT_SUSPEND, 0, 2000))
pr_err("%s: timeout waiting for SUSPEND\n", __func__);
ehci->reset_done[wIndex-1] = 0;
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
static int tegra_usb_suspend(struct usb_hcd *hcd)
{
struct tegra_ehci_hcd *tegra = dev_get_drvdata(hcd->self.controller);
struct ehci_regs __iomem *hw = tegra->ehci->regs;
unsigned long flags;
spin_lock_irqsave(&tegra->ehci->lock, flags);
tegra->port_speed = (readl(&hw->port_status[0]) >> 26) & 0x3;
ehci_halt(tegra->ehci);
clear_bit(HCD_FLAG_HW_ACCESSIBLE, &hcd->flags);
spin_unlock_irqrestore(&tegra->ehci->lock, flags);
tegra_ehci_power_down(hcd);
return 0;
}
static int tegra_usb_resume(struct usb_hcd *hcd)
{
struct tegra_ehci_hcd *tegra = dev_get_drvdata(hcd->self.controller);
struct ehci_hcd *ehci = hcd_to_ehci(hcd);
struct ehci_regs __iomem *hw = ehci->regs;
unsigned long val;
set_bit(HCD_FLAG_HW_ACCESSIBLE, &hcd->flags);
tegra_ehci_power_up(hcd);
if (tegra->port_speed > TEGRA_USB_PHY_PORT_SPEED_HIGH) {
msleep(10);
goto restart;
}
tegra_ehci_phy_restore_start(tegra->phy, tegra->port_speed);
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
tegra_ehci_phy_restore_end(tegra->phy);
return 0;
restart:
if (tegra->port_speed <= TEGRA_USB_PHY_PORT_SPEED_HIGH)
tegra_ehci_phy_restore_end(tegra->phy);
tegra_ehci_restart(hcd);
return 0;
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
int retval;
ehci->caps = hcd->regs + 0x100;
ehci->regs = hcd->regs + 0x100 +
HC_LENGTH(ehci, readl(&ehci->caps->hc_capbase));
dbg_hcs_params(ehci, "reset");
dbg_hcc_params(ehci, "reset");
ehci->hcs_params = readl(&ehci->caps->hcs_params);
hcd->has_tt = 1;
ehci_reset(ehci);
retval = ehci_halt(ehci);
if (retval)
return retval;
retval = ehci_init(hcd);
if (retval)
return retval;
ehci->sbrn = 0x20;
ehci_port_power(ehci, 1);
return retval;
}
static int tegra_ehci_bus_suspend(struct usb_hcd *hcd)
{
struct tegra_ehci_hcd *tegra = dev_get_drvdata(hcd->self.controller);
int error_status = 0;
error_status = ehci_bus_suspend(hcd);
if (!error_status && tegra->power_down_on_bus_suspend) {
tegra_usb_suspend(hcd);
tegra->bus_suspended = 1;
}
return error_status;
}
static int tegra_ehci_bus_resume(struct usb_hcd *hcd)
{
struct tegra_ehci_hcd *tegra = dev_get_drvdata(hcd->self.controller);
if (tegra->bus_suspended && tegra->power_down_on_bus_suspend) {
tegra_usb_resume(hcd);
tegra->bus_suspended = 0;
}
tegra_usb_phy_preresume(tegra->phy);
tegra->port_resuming = 1;
return ehci_bus_resume(hcd);
}
static void free_temp_buffer(struct urb *urb)
{
enum dma_data_direction dir;
struct temp_buffer *temp;
if (!(urb->transfer_flags & URB_ALIGNED_TEMP_BUFFER))
return;
dir = usb_urb_dir_in(urb) ? DMA_FROM_DEVICE : DMA_TO_DEVICE;
temp = container_of(urb->transfer_buffer, struct temp_buffer,
data);
if (dir == DMA_FROM_DEVICE)
memcpy(temp->old_xfer_buffer, temp->data,
urb->transfer_buffer_length);
urb->transfer_buffer = temp->old_xfer_buffer;
kfree(temp->kmalloc_ptr);
urb->transfer_flags &= ~URB_ALIGNED_TEMP_BUFFER;
}
static int alloc_temp_buffer(struct urb *urb, gfp_t mem_flags)
{
enum dma_data_direction dir;
struct temp_buffer *temp, *kmalloc_ptr;
size_t kmalloc_size;
if (urb->num_sgs || urb->sg ||
urb->transfer_buffer_length == 0 ||
!((uintptr_t)urb->transfer_buffer & (TEGRA_USB_DMA_ALIGN - 1)))
return 0;
dir = usb_urb_dir_in(urb) ? DMA_FROM_DEVICE : DMA_TO_DEVICE;
kmalloc_size = urb->transfer_buffer_length +
sizeof(struct temp_buffer) + TEGRA_USB_DMA_ALIGN - 1;
kmalloc_ptr = kmalloc(kmalloc_size, mem_flags);
if (!kmalloc_ptr)
return -ENOMEM;
temp = PTR_ALIGN(kmalloc_ptr + 1, TEGRA_USB_DMA_ALIGN) - 1;
temp->kmalloc_ptr = kmalloc_ptr;
temp->old_xfer_buffer = urb->transfer_buffer;
if (dir == DMA_TO_DEVICE)
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
ret = alloc_temp_buffer(urb, mem_flags);
if (ret)
return ret;
ret = usb_hcd_map_urb_for_dma(hcd, urb, mem_flags);
if (ret)
free_temp_buffer(urb);
return ret;
}
static void tegra_ehci_unmap_urb_for_dma(struct usb_hcd *hcd, struct urb *urb)
{
usb_hcd_unmap_urb_for_dma(hcd, urb);
free_temp_buffer(urb);
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
pdata = pdev->dev.platform_data;
if (!pdata) {
dev_err(&pdev->dev, "Platform data missing\n");
return -EINVAL;
}
tegra = kzalloc(sizeof(struct tegra_ehci_hcd), GFP_KERNEL);
if (!tegra)
return -ENOMEM;
hcd = usb_create_hcd(&tegra_ehci_hc_driver, &pdev->dev,
dev_name(&pdev->dev));
if (!hcd) {
dev_err(&pdev->dev, "Unable to create HCD\n");
err = -ENOMEM;
goto fail_hcd;
}
platform_set_drvdata(pdev, tegra);
tegra->clk = clk_get(&pdev->dev, NULL);
if (IS_ERR(tegra->clk)) {
dev_err(&pdev->dev, "Can't get ehci clock\n");
err = PTR_ERR(tegra->clk);
goto fail_clk;
}
err = clk_enable(tegra->clk);
if (err)
goto fail_clken;
tegra->emc_clk = clk_get(&pdev->dev, "emc");
if (IS_ERR(tegra->emc_clk)) {
dev_err(&pdev->dev, "Can't get emc clock\n");
err = PTR_ERR(tegra->emc_clk);
goto fail_emc_clk;
}
clk_enable(tegra->emc_clk);
clk_set_rate(tegra->emc_clk, 400000000);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(&pdev->dev, "Failed to get I/O memory\n");
err = -ENXIO;
goto fail_io;
}
hcd->rsrc_start = res->start;
hcd->rsrc_len = resource_size(res);
hcd->regs = ioremap(res->start, resource_size(res));
if (!hcd->regs) {
dev_err(&pdev->dev, "Failed to remap I/O memory\n");
err = -ENOMEM;
goto fail_io;
}
tegra->phy = tegra_usb_phy_open(instance, hcd->regs, pdata->phy_config,
TEGRA_USB_PHY_MODE_HOST);
if (IS_ERR(tegra->phy)) {
dev_err(&pdev->dev, "Failed to open USB phy\n");
err = -ENXIO;
goto fail_phy;
}
err = tegra_usb_phy_power_on(tegra->phy);
if (err) {
dev_err(&pdev->dev, "Failed to power on the phy\n");
goto fail;
}
tegra->host_resumed = 1;
tegra->power_down_on_bus_suspend = pdata->power_down_on_bus_suspend;
tegra->ehci = hcd_to_ehci(hcd);
irq = platform_get_irq(pdev, 0);
if (!irq) {
dev_err(&pdev->dev, "Failed to get IRQ\n");
err = -ENODEV;
goto fail;
}
set_irq_flags(irq, IRQF_VALID);
#ifdef CONFIG_USB_OTG_UTILS
if (pdata->operating_mode == TEGRA_USB_OTG) {
tegra->transceiver = otg_get_transceiver();
if (tegra->transceiver)
otg_set_host(tegra->transceiver, &hcd->self);
}
#endif
err = usb_add_hcd(hcd, irq, IRQF_DISABLED | IRQF_SHARED);
if (err) {
dev_err(&pdev->dev, "Failed to add USB HCD\n");
goto fail;
}
return err;
fail:
#ifdef CONFIG_USB_OTG_UTILS
if (tegra->transceiver) {
otg_set_host(tegra->transceiver, NULL);
otg_put_transceiver(tegra->transceiver);
}
#endif
tegra_usb_phy_close(tegra->phy);
fail_phy:
iounmap(hcd->regs);
fail_io:
clk_disable(tegra->emc_clk);
clk_put(tegra->emc_clk);
fail_emc_clk:
clk_disable(tegra->clk);
fail_clken:
clk_put(tegra->clk);
fail_clk:
usb_put_hcd(hcd);
fail_hcd:
kfree(tegra);
return err;
}
static int tegra_ehci_resume(struct platform_device *pdev)
{
struct tegra_ehci_hcd *tegra = platform_get_drvdata(pdev);
struct usb_hcd *hcd = ehci_to_hcd(tegra->ehci);
if (tegra->bus_suspended)
return 0;
return tegra_usb_resume(hcd);
}
static int tegra_ehci_suspend(struct platform_device *pdev, pm_message_t state)
{
struct tegra_ehci_hcd *tegra = platform_get_drvdata(pdev);
struct usb_hcd *hcd = ehci_to_hcd(tegra->ehci);
if (tegra->bus_suspended)
return 0;
if (time_before(jiffies, tegra->ehci->next_statechange))
msleep(10);
return tegra_usb_suspend(hcd);
}
static int tegra_ehci_remove(struct platform_device *pdev)
{
struct tegra_ehci_hcd *tegra = platform_get_drvdata(pdev);
struct usb_hcd *hcd = ehci_to_hcd(tegra->ehci);
if (tegra == NULL || hcd == NULL)
return -EINVAL;
#ifdef CONFIG_USB_OTG_UTILS
if (tegra->transceiver) {
otg_set_host(tegra->transceiver, NULL);
otg_put_transceiver(tegra->transceiver);
}
#endif
usb_remove_hcd(hcd);
usb_put_hcd(hcd);
tegra_usb_phy_close(tegra->phy);
iounmap(hcd->regs);
clk_disable(tegra->clk);
clk_put(tegra->clk);
clk_disable(tegra->emc_clk);
clk_put(tegra->emc_clk);
kfree(tegra);
return 0;
}
static void tegra_ehci_hcd_shutdown(struct platform_device *pdev)
{
struct tegra_ehci_hcd *tegra = platform_get_drvdata(pdev);
struct usb_hcd *hcd = ehci_to_hcd(tegra->ehci);
if (hcd->driver->shutdown)
hcd->driver->shutdown(hcd);
}
