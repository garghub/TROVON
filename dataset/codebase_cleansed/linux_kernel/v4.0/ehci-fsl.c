static int usb_hcd_fsl_probe(const struct hc_driver *driver,
struct platform_device *pdev)
{
struct fsl_usb2_platform_data *pdata;
struct usb_hcd *hcd;
struct resource *res;
int irq;
int retval;
pr_debug("initializing FSL-SOC USB Controller\n");
pdata = dev_get_platdata(&pdev->dev);
if (!pdata) {
dev_err(&pdev->dev,
"No platform data for %s.\n", dev_name(&pdev->dev));
return -ENODEV;
}
if (!((pdata->operating_mode == FSL_USB2_DR_HOST) ||
(pdata->operating_mode == FSL_USB2_MPH_HOST) ||
(pdata->operating_mode == FSL_USB2_DR_OTG))) {
dev_err(&pdev->dev,
"Non Host Mode configured for %s. Wrong driver linked.\n",
dev_name(&pdev->dev));
return -ENODEV;
}
res = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
if (!res) {
dev_err(&pdev->dev,
"Found HC with no IRQ. Check %s setup!\n",
dev_name(&pdev->dev));
return -ENODEV;
}
irq = res->start;
hcd = usb_create_hcd(driver, &pdev->dev, dev_name(&pdev->dev));
if (!hcd) {
retval = -ENOMEM;
goto err1;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
hcd->regs = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(hcd->regs)) {
retval = PTR_ERR(hcd->regs);
goto err2;
}
hcd->rsrc_start = res->start;
hcd->rsrc_len = resource_size(res);
pdata->regs = hcd->regs;
if (pdata->power_budget)
hcd->power_budget = pdata->power_budget;
if (pdata->init && pdata->init(pdev)) {
retval = -ENODEV;
goto err2;
}
if (pdata->have_sysif_regs && pdata->controller_ver < FSL_USB_VER_1_6)
setbits32(hcd->regs + FSL_SOC_USB_CTRL, 0x4);
retval = usb_add_hcd(hcd, irq, IRQF_SHARED);
if (retval != 0)
goto err2;
device_wakeup_enable(hcd->self.controller);
#ifdef CONFIG_USB_OTG
if (pdata->operating_mode == FSL_USB2_DR_OTG) {
struct ehci_hcd *ehci = hcd_to_ehci(hcd);
hcd->usb_phy = usb_get_phy(USB_PHY_TYPE_USB2);
dev_dbg(&pdev->dev, "hcd=0x%p ehci=0x%p, phy=0x%p\n",
hcd, ehci, hcd->usb_phy);
if (!IS_ERR_OR_NULL(hcd->usb_phy)) {
retval = otg_set_host(hcd->usb_phy->otg,
&ehci_to_hcd(ehci)->self);
if (retval) {
usb_put_phy(hcd->usb_phy);
goto err2;
}
} else {
dev_err(&pdev->dev, "can't find phy\n");
retval = -ENODEV;
goto err2;
}
}
#endif
return retval;
err2:
usb_put_hcd(hcd);
err1:
dev_err(&pdev->dev, "init %s fail, %d\n", dev_name(&pdev->dev), retval);
if (pdata->exit)
pdata->exit(pdev);
return retval;
}
static void usb_hcd_fsl_remove(struct usb_hcd *hcd,
struct platform_device *pdev)
{
struct fsl_usb2_platform_data *pdata = dev_get_platdata(&pdev->dev);
if (!IS_ERR_OR_NULL(hcd->usb_phy)) {
otg_set_host(hcd->usb_phy->otg, NULL);
usb_put_phy(hcd->usb_phy);
}
usb_remove_hcd(hcd);
if (pdata->exit)
pdata->exit(pdev);
usb_put_hcd(hcd);
}
static int ehci_fsl_setup_phy(struct usb_hcd *hcd,
enum fsl_usb2_phy_modes phy_mode,
unsigned int port_offset)
{
u32 portsc;
struct ehci_hcd *ehci = hcd_to_ehci(hcd);
void __iomem *non_ehci = hcd->regs;
struct device *dev = hcd->self.controller;
struct fsl_usb2_platform_data *pdata = dev_get_platdata(dev);
if (pdata->controller_ver < 0) {
dev_warn(hcd->self.controller, "Could not get controller version\n");
return -ENODEV;
}
portsc = ehci_readl(ehci, &ehci->regs->port_status[port_offset]);
portsc &= ~(PORT_PTS_MSK | PORT_PTS_PTW);
switch (phy_mode) {
case FSL_USB2_PHY_ULPI:
if (pdata->have_sysif_regs && pdata->controller_ver) {
clrbits32(non_ehci + FSL_SOC_USB_CTRL, UTMI_PHY_EN);
setbits32(non_ehci + FSL_SOC_USB_CTRL,
ULPI_PHY_CLK_SEL | USB_CTRL_USB_EN);
}
portsc |= PORT_PTS_ULPI;
break;
case FSL_USB2_PHY_SERIAL:
portsc |= PORT_PTS_SERIAL;
break;
case FSL_USB2_PHY_UTMI_WIDE:
portsc |= PORT_PTS_PTW;
case FSL_USB2_PHY_UTMI:
if (pdata->have_sysif_regs && pdata->controller_ver) {
setbits32(non_ehci + FSL_SOC_USB_CTRL, UTMI_PHY_EN);
mdelay(FSL_UTMI_PHY_DLY);
}
if (pdata->have_sysif_regs)
setbits32(non_ehci + FSL_SOC_USB_CTRL,
CTRL_UTMI_PHY_EN);
portsc |= PORT_PTS_UTMI;
break;
case FSL_USB2_PHY_NONE:
break;
}
if (pdata->have_sysif_regs &&
pdata->controller_ver > FSL_USB_VER_1_6 &&
(phy_mode == FSL_USB2_PHY_ULPI)) {
if (!(spin_event_timeout(in_be32(non_ehci + FSL_SOC_USB_CTRL) &
PHY_CLK_VALID, FSL_USB_PHY_CLK_TIMEOUT, 0) ||
in_be32(non_ehci + FSL_SOC_USB_PRICTRL))) {
dev_warn(hcd->self.controller, "USB PHY clock invalid\n");
return -EINVAL;
}
}
ehci_writel(ehci, portsc, &ehci->regs->port_status[port_offset]);
if (phy_mode != FSL_USB2_PHY_ULPI && pdata->have_sysif_regs)
setbits32(non_ehci + FSL_SOC_USB_CTRL, USB_CTRL_USB_EN);
return 0;
}
static int ehci_fsl_usb_setup(struct ehci_hcd *ehci)
{
struct usb_hcd *hcd = ehci_to_hcd(ehci);
struct fsl_usb2_platform_data *pdata;
void __iomem *non_ehci = hcd->regs;
pdata = dev_get_platdata(hcd->self.controller);
if (pdata->have_sysif_regs) {
out_be32(non_ehci + FSL_SOC_USB_SNOOP1, 0x0 | SNOOP_SIZE_2GB);
out_be32(non_ehci + FSL_SOC_USB_SNOOP2, 0x80000000 | SNOOP_SIZE_2GB);
}
if ((pdata->operating_mode == FSL_USB2_DR_HOST) ||
(pdata->operating_mode == FSL_USB2_DR_OTG))
if (ehci_fsl_setup_phy(hcd, pdata->phy_mode, 0))
return -EINVAL;
if (pdata->operating_mode == FSL_USB2_MPH_HOST) {
unsigned int chip, rev, svr;
svr = mfspr(SPRN_SVR);
chip = svr >> 16;
rev = (svr >> 4) & 0xf;
if ((rev == 1) && (chip >= 0x8050) && (chip <= 0x8055))
ehci->has_fsl_port_bug = 1;
if (pdata->port_enables & FSL_USB2_PORT0_ENABLED)
if (ehci_fsl_setup_phy(hcd, pdata->phy_mode, 0))
return -EINVAL;
if (pdata->port_enables & FSL_USB2_PORT1_ENABLED)
if (ehci_fsl_setup_phy(hcd, pdata->phy_mode, 1))
return -EINVAL;
}
if (pdata->have_sysif_regs) {
#ifdef CONFIG_FSL_SOC_BOOKE
out_be32(non_ehci + FSL_SOC_USB_PRICTRL, 0x00000008);
out_be32(non_ehci + FSL_SOC_USB_AGECNTTHRSH, 0x00000080);
#else
out_be32(non_ehci + FSL_SOC_USB_PRICTRL, 0x0000000c);
out_be32(non_ehci + FSL_SOC_USB_AGECNTTHRSH, 0x00000040);
#endif
out_be32(non_ehci + FSL_SOC_USB_SICTRL, 0x00000001);
}
return 0;
}
static int ehci_fsl_reinit(struct ehci_hcd *ehci)
{
if (ehci_fsl_usb_setup(ehci))
return -EINVAL;
return 0;
}
static int ehci_fsl_setup(struct usb_hcd *hcd)
{
struct ehci_hcd *ehci = hcd_to_ehci(hcd);
int retval;
struct fsl_usb2_platform_data *pdata;
struct device *dev;
dev = hcd->self.controller;
pdata = dev_get_platdata(hcd->self.controller);
ehci->big_endian_desc = pdata->big_endian_desc;
ehci->big_endian_mmio = pdata->big_endian_mmio;
ehci->caps = hcd->regs + 0x100;
#ifdef CONFIG_PPC_83xx
ehci->need_oc_pp_cycle = 1;
#endif
hcd->has_tt = 1;
retval = ehci_setup(hcd);
if (retval)
return retval;
if (of_device_is_compatible(dev->parent->of_node,
"fsl,mpc5121-usb2-dr")) {
ehci_writel(ehci, SBUSCFG_INCR8,
hcd->regs + FSL_SOC_USB_SBUSCFG);
}
retval = ehci_fsl_reinit(ehci);
return retval;
}
static int ehci_fsl_mpc512x_drv_suspend(struct device *dev)
{
struct usb_hcd *hcd = dev_get_drvdata(dev);
struct ehci_hcd *ehci = hcd_to_ehci(hcd);
struct fsl_usb2_platform_data *pdata = dev_get_platdata(dev);
u32 tmp;
#ifdef CONFIG_DYNAMIC_DEBUG
u32 mode = ehci_readl(ehci, hcd->regs + FSL_SOC_USB_USBMODE);
mode &= USBMODE_CM_MASK;
tmp = ehci_readl(ehci, hcd->regs + 0x140);
dev_dbg(dev, "suspend=%d already_suspended=%d "
"mode=%d usbcmd %08x\n", pdata->suspended,
pdata->already_suspended, mode, tmp);
#endif
if (pdata->suspended) {
dev_dbg(dev, "already suspended, leaving early\n");
pdata->already_suspended = 1;
return 0;
}
dev_dbg(dev, "suspending...\n");
ehci->rh_state = EHCI_RH_SUSPENDED;
dev->power.power_state = PMSG_SUSPEND;
clear_bit(HCD_FLAG_HW_ACCESSIBLE, &hcd->flags);
tmp = ehci_readl(ehci, &ehci->regs->command);
tmp &= ~CMD_RUN;
ehci_writel(ehci, tmp, &ehci->regs->command);
pdata->pm_command = ehci_readl(ehci, &ehci->regs->command);
pdata->pm_command &= ~CMD_RUN;
pdata->pm_status = ehci_readl(ehci, &ehci->regs->status);
pdata->pm_intr_enable = ehci_readl(ehci, &ehci->regs->intr_enable);
pdata->pm_frame_index = ehci_readl(ehci, &ehci->regs->frame_index);
pdata->pm_segment = ehci_readl(ehci, &ehci->regs->segment);
pdata->pm_frame_list = ehci_readl(ehci, &ehci->regs->frame_list);
pdata->pm_async_next = ehci_readl(ehci, &ehci->regs->async_next);
pdata->pm_configured_flag =
ehci_readl(ehci, &ehci->regs->configured_flag);
pdata->pm_portsc = ehci_readl(ehci, &ehci->regs->port_status[0]);
pdata->pm_usbgenctrl = ehci_readl(ehci,
hcd->regs + FSL_SOC_USB_USBGENCTRL);
pdata->pm_portsc &= cpu_to_hc32(ehci, ~PORT_RWC_BITS);
pdata->suspended = 1;
tmp = ehci_readl(ehci, &ehci->regs->port_status[0]);
tmp &= ~PORT_POWER;
ehci_writel(ehci, tmp, &ehci->regs->port_status[0]);
return 0;
}
static int ehci_fsl_mpc512x_drv_resume(struct device *dev)
{
struct usb_hcd *hcd = dev_get_drvdata(dev);
struct ehci_hcd *ehci = hcd_to_ehci(hcd);
struct fsl_usb2_platform_data *pdata = dev_get_platdata(dev);
u32 tmp;
dev_dbg(dev, "suspend=%d already_suspended=%d\n",
pdata->suspended, pdata->already_suspended);
if (pdata->already_suspended) {
dev_dbg(dev, "already suspended, leaving early\n");
pdata->already_suspended = 0;
return 0;
}
if (!pdata->suspended) {
dev_dbg(dev, "not suspended, leaving early\n");
return 0;
}
pdata->suspended = 0;
dev_dbg(dev, "resuming...\n");
tmp = USBMODE_CM_HOST | (pdata->es ? USBMODE_ES : 0);
ehci_writel(ehci, tmp, hcd->regs + FSL_SOC_USB_USBMODE);
ehci_writel(ehci, pdata->pm_usbgenctrl,
hcd->regs + FSL_SOC_USB_USBGENCTRL);
ehci_writel(ehci, ISIPHYCTRL_PXE | ISIPHYCTRL_PHYE,
hcd->regs + FSL_SOC_USB_ISIPHYCTRL);
ehci_writel(ehci, SBUSCFG_INCR8, hcd->regs + FSL_SOC_USB_SBUSCFG);
ehci_writel(ehci, pdata->pm_command, &ehci->regs->command);
ehci_writel(ehci, pdata->pm_intr_enable, &ehci->regs->intr_enable);
ehci_writel(ehci, pdata->pm_frame_index, &ehci->regs->frame_index);
ehci_writel(ehci, pdata->pm_segment, &ehci->regs->segment);
ehci_writel(ehci, pdata->pm_frame_list, &ehci->regs->frame_list);
ehci_writel(ehci, pdata->pm_async_next, &ehci->regs->async_next);
ehci_writel(ehci, pdata->pm_configured_flag,
&ehci->regs->configured_flag);
ehci_writel(ehci, pdata->pm_portsc, &ehci->regs->port_status[0]);
set_bit(HCD_FLAG_HW_ACCESSIBLE, &hcd->flags);
ehci->rh_state = EHCI_RH_RUNNING;
dev->power.power_state = PMSG_ON;
tmp = ehci_readl(ehci, &ehci->regs->command);
tmp |= CMD_RUN;
ehci_writel(ehci, tmp, &ehci->regs->command);
usb_hcd_resume_root_hub(hcd);
return 0;
}
static inline int ehci_fsl_mpc512x_drv_suspend(struct device *dev)
{
return 0;
}
static inline int ehci_fsl_mpc512x_drv_resume(struct device *dev)
{
return 0;
}
static struct ehci_fsl *hcd_to_ehci_fsl(struct usb_hcd *hcd)
{
struct ehci_hcd *ehci = hcd_to_ehci(hcd);
return container_of(ehci, struct ehci_fsl, ehci);
}
static int ehci_fsl_drv_suspend(struct device *dev)
{
struct usb_hcd *hcd = dev_get_drvdata(dev);
struct ehci_fsl *ehci_fsl = hcd_to_ehci_fsl(hcd);
void __iomem *non_ehci = hcd->regs;
if (of_device_is_compatible(dev->parent->of_node,
"fsl,mpc5121-usb2-dr")) {
return ehci_fsl_mpc512x_drv_suspend(dev);
}
ehci_prepare_ports_for_controller_suspend(hcd_to_ehci(hcd),
device_may_wakeup(dev));
if (!fsl_deep_sleep())
return 0;
ehci_fsl->usb_ctrl = in_be32(non_ehci + FSL_SOC_USB_CTRL);
return 0;
}
static int ehci_fsl_drv_resume(struct device *dev)
{
struct usb_hcd *hcd = dev_get_drvdata(dev);
struct ehci_fsl *ehci_fsl = hcd_to_ehci_fsl(hcd);
struct ehci_hcd *ehci = hcd_to_ehci(hcd);
void __iomem *non_ehci = hcd->regs;
if (of_device_is_compatible(dev->parent->of_node,
"fsl,mpc5121-usb2-dr")) {
return ehci_fsl_mpc512x_drv_resume(dev);
}
ehci_prepare_ports_for_controller_resume(ehci);
if (!fsl_deep_sleep())
return 0;
usb_root_hub_lost_power(hcd->self.root_hub);
out_be32(non_ehci + FSL_SOC_USB_CTRL, ehci_fsl->usb_ctrl);
ehci_reset(ehci);
ehci_fsl_reinit(ehci);
return 0;
}
static int ehci_fsl_drv_restore(struct device *dev)
{
struct usb_hcd *hcd = dev_get_drvdata(dev);
usb_root_hub_lost_power(hcd->self.root_hub);
return 0;
}
static int ehci_start_port_reset(struct usb_hcd *hcd, unsigned port)
{
struct ehci_hcd *ehci = hcd_to_ehci(hcd);
u32 status;
if (!port)
return -EINVAL;
port--;
status = readl(&ehci->regs->port_status[port]);
if (!(status & PORT_CONNECT))
return -ENODEV;
if (ehci_is_TDI(ehci)) {
writel(PORT_RESET |
(status & ~(PORT_CSC | PORT_PEC | PORT_OCC)),
&ehci->regs->port_status[port]);
} else {
writel(PORT_RESET, &ehci->regs->port_status[port]);
}
return 0;
}
static int ehci_fsl_drv_probe(struct platform_device *pdev)
{
if (usb_disabled())
return -ENODEV;
return usb_hcd_fsl_probe(&ehci_fsl_hc_driver, pdev);
}
static int ehci_fsl_drv_remove(struct platform_device *pdev)
{
struct usb_hcd *hcd = platform_get_drvdata(pdev);
usb_hcd_fsl_remove(hcd, pdev);
return 0;
}
