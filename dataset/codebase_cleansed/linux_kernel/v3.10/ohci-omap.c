static inline int tps65010_set_gpio_out_value(unsigned gpio, unsigned value)
{
return 0;
}
static void omap_ohci_clock_power(int on)
{
if (on) {
clk_enable(usb_dc_ck);
clk_enable(usb_host_ck);
udelay(100);
} else {
clk_disable(usb_host_ck);
clk_disable(usb_dc_ck);
}
}
static int omap_ohci_transceiver_power(int on)
{
if (on) {
if (machine_is_omap_innovator() && cpu_is_omap1510())
__raw_writeb(__raw_readb(INNOVATOR_FPGA_CAM_USB_CONTROL)
| ((1 << 5) | (1 << 3)),
INNOVATOR_FPGA_CAM_USB_CONTROL);
else if (machine_is_omap_osk())
tps65010_set_gpio_out_value(GPIO1, LOW);
} else {
if (machine_is_omap_innovator() && cpu_is_omap1510())
__raw_writeb(__raw_readb(INNOVATOR_FPGA_CAM_USB_CONTROL)
& ~((1 << 5) | (1 << 3)),
INNOVATOR_FPGA_CAM_USB_CONTROL);
else if (machine_is_omap_osk())
tps65010_set_gpio_out_value(GPIO1, HIGH);
}
return 0;
}
static int omap_1510_local_bus_power(int on)
{
if (on) {
omap_writel((1 << 1) | (1 << 0), OMAP1510_LB_MMU_CTL);
udelay(200);
} else {
omap_writel(0, OMAP1510_LB_MMU_CTL);
}
return 0;
}
static int omap_1510_local_bus_init(void)
{
unsigned int tlb;
unsigned long lbaddr, physaddr;
omap_writel((omap_readl(OMAP1510_LB_CLOCK_DIV) & 0xfffffff8) | 0x4,
OMAP1510_LB_CLOCK_DIV);
for (tlb = 0; tlb < OMAP1510_LB_MEMSIZE; tlb++) {
lbaddr = tlb * 0x00100000 + OMAP1510_LB_OFFSET;
physaddr = tlb * 0x00100000 + PHYS_OFFSET;
omap_writel((lbaddr & 0x0fffffff) >> 22, OMAP1510_LB_MMU_CAM_H);
omap_writel(((lbaddr & 0x003ffc00) >> 6) | 0xc,
OMAP1510_LB_MMU_CAM_L);
omap_writel(physaddr >> 16, OMAP1510_LB_MMU_RAM_H);
omap_writel((physaddr & 0x0000fc00) | 0x300, OMAP1510_LB_MMU_RAM_L);
omap_writel(tlb << 4, OMAP1510_LB_MMU_LCK);
omap_writel(0x1, OMAP1510_LB_MMU_LD_TLB);
}
omap_writel(omap_readl(OMAP1510_LB_MMU_CTL) | (1 << 3), OMAP1510_LB_MMU_CTL);
udelay(200);
return 0;
}
static void start_hnp(struct ohci_hcd *ohci)
{
struct usb_hcd *hcd = ohci_to_hcd(ohci);
const unsigned port = hcd->self.otg_port - 1;
unsigned long flags;
u32 l;
otg_start_hnp(hcd->phy->otg);
local_irq_save(flags);
hcd->phy->state = OTG_STATE_A_SUSPEND;
writel (RH_PS_PSS, &ohci->regs->roothub.portstatus [port]);
l = omap_readl(OTG_CTRL);
l &= ~OTG_A_BUSREQ;
omap_writel(l, OTG_CTRL);
local_irq_restore(flags);
}
static int ohci_omap_init(struct usb_hcd *hcd)
{
struct ohci_hcd *ohci = hcd_to_ohci(hcd);
struct omap_usb_config *config = hcd->self.controller->platform_data;
int need_transceiver = (config->otg != 0);
int ret;
dev_dbg(hcd->self.controller, "starting USB Controller\n");
if (config->otg) {
ohci_to_hcd(ohci)->self.otg_port = config->otg;
ohci_to_hcd(ohci)->power_budget = 8;
}
need_transceiver = need_transceiver
|| machine_is_omap_h2() || machine_is_omap_h3();
if (config->ocpi_enable)
config->ocpi_enable();
#ifdef CONFIG_USB_OTG
if (need_transceiver) {
hcd->phy = usb_get_phy(USB_PHY_TYPE_USB2);
if (!IS_ERR_OR_NULL(hcd->phy)) {
int status = otg_set_host(hcd->phy->otg,
&ohci_to_hcd(ohci)->self);
dev_dbg(hcd->self.controller, "init %s phy, status %d\n",
hcd->phy->label, status);
if (status) {
usb_put_phy(hcd->phy);
return status;
}
} else {
dev_err(hcd->self.controller, "can't find phy\n");
return -ENODEV;
}
ohci->start_hnp = start_hnp;
}
#endif
omap_ohci_clock_power(1);
if (cpu_is_omap15xx()) {
omap_1510_local_bus_power(1);
omap_1510_local_bus_init();
}
if ((ret = ohci_init(ohci)) < 0)
return ret;
if (machine_is_omap_osk() || machine_is_omap_innovator()) {
u32 rh = roothub_a (ohci);
rh &= ~RH_A_NPS;
if (machine_is_omap_osk()) {
ohci_to_hcd(ohci)->power_budget = 250;
rh &= ~RH_A_NOCP;
omap_cfg_reg(W8_1610_GPIO9);
gpio_request(9, "OHCI overcurrent");
gpio_direction_input(9);
omap_cfg_reg(W4_USB_HIGHZ);
}
ohci_writel(ohci, rh, &ohci->regs->roothub.a);
ohci->flags &= ~OHCI_QUIRK_HUB_POWER;
} else if (machine_is_nokia770()) {
ohci_to_hcd(ohci)->power_budget = 0;
}
omap_ohci_transceiver_power(1);
return 0;
}
static void ohci_omap_stop(struct usb_hcd *hcd)
{
dev_dbg(hcd->self.controller, "stopping USB Controller\n");
ohci_stop(hcd);
omap_ohci_clock_power(0);
}
static int usb_hcd_omap_probe (const struct hc_driver *driver,
struct platform_device *pdev)
{
int retval, irq;
struct usb_hcd *hcd = 0;
struct ohci_hcd *ohci;
if (pdev->num_resources != 2) {
printk(KERN_ERR "hcd probe: invalid num_resources: %i\n",
pdev->num_resources);
return -ENODEV;
}
if (pdev->resource[0].flags != IORESOURCE_MEM
|| pdev->resource[1].flags != IORESOURCE_IRQ) {
printk(KERN_ERR "hcd probe: invalid resource type\n");
return -ENODEV;
}
usb_host_ck = clk_get(&pdev->dev, "usb_hhc_ck");
if (IS_ERR(usb_host_ck))
return PTR_ERR(usb_host_ck);
if (!cpu_is_omap15xx())
usb_dc_ck = clk_get(&pdev->dev, "usb_dc_ck");
else
usb_dc_ck = clk_get(&pdev->dev, "lb_ck");
if (IS_ERR(usb_dc_ck)) {
clk_put(usb_host_ck);
return PTR_ERR(usb_dc_ck);
}
hcd = usb_create_hcd (driver, &pdev->dev, dev_name(&pdev->dev));
if (!hcd) {
retval = -ENOMEM;
goto err0;
}
hcd->rsrc_start = pdev->resource[0].start;
hcd->rsrc_len = pdev->resource[0].end - pdev->resource[0].start + 1;
if (!request_mem_region(hcd->rsrc_start, hcd->rsrc_len, hcd_name)) {
dev_dbg(&pdev->dev, "request_mem_region failed\n");
retval = -EBUSY;
goto err1;
}
hcd->regs = ioremap(hcd->rsrc_start, hcd->rsrc_len);
if (!hcd->regs) {
dev_err(&pdev->dev, "can't ioremap OHCI HCD\n");
retval = -ENOMEM;
goto err2;
}
ohci = hcd_to_ohci(hcd);
ohci_hcd_init(ohci);
host_initialized = 0;
host_enabled = 1;
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
retval = -ENXIO;
goto err3;
}
retval = usb_add_hcd(hcd, irq, 0);
if (retval)
goto err3;
host_initialized = 1;
if (!host_enabled)
omap_ohci_clock_power(0);
return 0;
err3:
iounmap(hcd->regs);
err2:
release_mem_region(hcd->rsrc_start, hcd->rsrc_len);
err1:
usb_put_hcd(hcd);
err0:
clk_put(usb_dc_ck);
clk_put(usb_host_ck);
return retval;
}
static inline void
usb_hcd_omap_remove (struct usb_hcd *hcd, struct platform_device *pdev)
{
usb_remove_hcd(hcd);
if (!IS_ERR_OR_NULL(hcd->phy)) {
(void) otg_set_host(hcd->phy->otg, 0);
usb_put_phy(hcd->phy);
}
if (machine_is_omap_osk())
gpio_free(9);
iounmap(hcd->regs);
release_mem_region(hcd->rsrc_start, hcd->rsrc_len);
usb_put_hcd(hcd);
clk_put(usb_dc_ck);
clk_put(usb_host_ck);
}
static int
ohci_omap_start (struct usb_hcd *hcd)
{
struct omap_usb_config *config;
struct ohci_hcd *ohci = hcd_to_ohci (hcd);
int ret;
if (!host_enabled)
return 0;
config = hcd->self.controller->platform_data;
if (config->otg || config->rwc) {
ohci->hc_control = OHCI_CTRL_RWC;
writel(OHCI_CTRL_RWC, &ohci->regs->control);
}
if ((ret = ohci_run (ohci)) < 0) {
dev_err(hcd->self.controller, "can't start\n");
ohci_stop (hcd);
return ret;
}
return 0;
}
static int ohci_hcd_omap_drv_probe(struct platform_device *dev)
{
return usb_hcd_omap_probe(&ohci_omap_hc_driver, dev);
}
static int ohci_hcd_omap_drv_remove(struct platform_device *dev)
{
struct usb_hcd *hcd = platform_get_drvdata(dev);
usb_hcd_omap_remove(hcd, dev);
platform_set_drvdata(dev, NULL);
return 0;
}
static int ohci_omap_suspend(struct platform_device *dev, pm_message_t message)
{
struct ohci_hcd *ohci = hcd_to_ohci(platform_get_drvdata(dev));
if (time_before(jiffies, ohci->next_statechange))
msleep(5);
ohci->next_statechange = jiffies;
omap_ohci_clock_power(0);
return 0;
}
static int ohci_omap_resume(struct platform_device *dev)
{
struct usb_hcd *hcd = platform_get_drvdata(dev);
struct ohci_hcd *ohci = hcd_to_ohci(hcd);
if (time_before(jiffies, ohci->next_statechange))
msleep(5);
ohci->next_statechange = jiffies;
omap_ohci_clock_power(1);
ohci_resume(hcd, false);
return 0;
}
