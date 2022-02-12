static int pxa27x_ohci_select_pmm(struct pxa27x_ohci *pxa_ohci, int mode)
{
uint32_t uhcrhda = __raw_readl(pxa_ohci->mmio_base + UHCRHDA);
uint32_t uhcrhdb = __raw_readl(pxa_ohci->mmio_base + UHCRHDB);
switch (mode) {
case PMM_NPS_MODE:
uhcrhda |= RH_A_NPS;
break;
case PMM_GLOBAL_MODE:
uhcrhda &= ~(RH_A_NPS & RH_A_PSM);
break;
case PMM_PERPORT_MODE:
uhcrhda &= ~(RH_A_NPS);
uhcrhda |= RH_A_PSM;
uhcrhdb |= (0x7<<17);
break;
default:
printk( KERN_ERR
"Invalid mode %d, set to non-power switch mode.\n",
mode );
uhcrhda |= RH_A_NPS;
}
__raw_writel(uhcrhda, pxa_ohci->mmio_base + UHCRHDA);
__raw_writel(uhcrhdb, pxa_ohci->mmio_base + UHCRHDB);
return 0;
}
static int pxa27x_ohci_set_vbus_power(struct pxa27x_ohci *pxa_ohci,
unsigned int port, bool enable)
{
struct regulator *vbus = pxa_ohci->vbus[port];
int ret = 0;
if (IS_ERR_OR_NULL(vbus))
return 0;
if (enable && !pxa_ohci->vbus_enabled[port])
ret = regulator_enable(vbus);
else if (!enable && pxa_ohci->vbus_enabled[port])
ret = regulator_disable(vbus);
if (ret < 0)
return ret;
pxa_ohci->vbus_enabled[port] = enable;
return 0;
}
static int pxa27x_ohci_hub_control(struct usb_hcd *hcd, u16 typeReq, u16 wValue,
u16 wIndex, char *buf, u16 wLength)
{
struct pxa27x_ohci *pxa_ohci = to_pxa27x_ohci(hcd);
int ret;
switch (typeReq) {
case SetPortFeature:
case ClearPortFeature:
if (!wIndex || wIndex > 3)
return -EPIPE;
if (wValue != USB_PORT_FEAT_POWER)
break;
ret = pxa27x_ohci_set_vbus_power(pxa_ohci, wIndex - 1,
typeReq == SetPortFeature);
if (ret)
return ret;
break;
}
return ohci_hub_control(hcd, typeReq, wValue, wIndex, buf, wLength);
}
static inline void pxa27x_setup_hc(struct pxa27x_ohci *pxa_ohci,
struct pxaohci_platform_data *inf)
{
uint32_t uhchr = __raw_readl(pxa_ohci->mmio_base + UHCHR);
uint32_t uhcrhda = __raw_readl(pxa_ohci->mmio_base + UHCRHDA);
if (inf->flags & ENABLE_PORT1)
uhchr &= ~UHCHR_SSEP1;
if (inf->flags & ENABLE_PORT2)
uhchr &= ~UHCHR_SSEP2;
if (inf->flags & ENABLE_PORT3)
uhchr &= ~UHCHR_SSEP3;
if (inf->flags & POWER_CONTROL_LOW)
uhchr |= UHCHR_PCPL;
if (inf->flags & POWER_SENSE_LOW)
uhchr |= UHCHR_PSPL;
if (inf->flags & NO_OC_PROTECTION)
uhcrhda |= UHCRHDA_NOCP;
else
uhcrhda &= ~UHCRHDA_NOCP;
if (inf->flags & OC_MODE_PERPORT)
uhcrhda |= UHCRHDA_OCPM;
else
uhcrhda &= ~UHCRHDA_OCPM;
if (inf->power_on_delay) {
uhcrhda &= ~UHCRHDA_POTPGT(0xff);
uhcrhda |= UHCRHDA_POTPGT(inf->power_on_delay / 2);
}
__raw_writel(uhchr, pxa_ohci->mmio_base + UHCHR);
__raw_writel(uhcrhda, pxa_ohci->mmio_base + UHCRHDA);
}
static inline void pxa27x_reset_hc(struct pxa27x_ohci *pxa_ohci)
{
uint32_t uhchr = __raw_readl(pxa_ohci->mmio_base + UHCHR);
__raw_writel(uhchr | UHCHR_FHR, pxa_ohci->mmio_base + UHCHR);
udelay(11);
__raw_writel(uhchr & ~UHCHR_FHR, pxa_ohci->mmio_base + UHCHR);
}
static int pxa27x_start_hc(struct pxa27x_ohci *pxa_ohci, struct device *dev)
{
int retval = 0;
struct pxaohci_platform_data *inf;
uint32_t uhchr;
struct usb_hcd *hcd = dev_get_drvdata(dev);
inf = dev_get_platdata(dev);
clk_prepare_enable(pxa_ohci->clk);
pxa27x_reset_hc(pxa_ohci);
uhchr = __raw_readl(pxa_ohci->mmio_base + UHCHR) | UHCHR_FSBIR;
__raw_writel(uhchr, pxa_ohci->mmio_base + UHCHR);
while (__raw_readl(pxa_ohci->mmio_base + UHCHR) & UHCHR_FSBIR)
cpu_relax();
pxa27x_setup_hc(pxa_ohci, inf);
if (inf->init)
retval = inf->init(dev);
if (retval < 0)
return retval;
if (cpu_is_pxa3xx())
pxa3xx_u2d_start_hc(&hcd->self);
uhchr = __raw_readl(pxa_ohci->mmio_base + UHCHR) & ~UHCHR_SSE;
__raw_writel(uhchr, pxa_ohci->mmio_base + UHCHR);
__raw_writel(UHCHIE_UPRIE | UHCHIE_RWIE, pxa_ohci->mmio_base + UHCHIE);
pxa27x_clear_otgph();
return 0;
}
static void pxa27x_stop_hc(struct pxa27x_ohci *pxa_ohci, struct device *dev)
{
struct pxaohci_platform_data *inf;
struct usb_hcd *hcd = dev_get_drvdata(dev);
uint32_t uhccoms;
inf = dev_get_platdata(dev);
if (cpu_is_pxa3xx())
pxa3xx_u2d_stop_hc(&hcd->self);
if (inf->exit)
inf->exit(dev);
pxa27x_reset_hc(pxa_ohci);
uhccoms = __raw_readl(pxa_ohci->mmio_base + UHCCOMS) | 0x01;
__raw_writel(uhccoms, pxa_ohci->mmio_base + UHCCOMS);
udelay(10);
clk_disable_unprepare(pxa_ohci->clk);
}
static int ohci_pxa_of_init(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct pxaohci_platform_data *pdata;
u32 tmp;
int ret;
if (!np)
return 0;
ret = dma_coerce_mask_and_coherent(&pdev->dev, DMA_BIT_MASK(32));
if (ret)
return ret;
pdata = devm_kzalloc(&pdev->dev, sizeof(*pdata), GFP_KERNEL);
if (!pdata)
return -ENOMEM;
if (of_get_property(np, "marvell,enable-port1", NULL))
pdata->flags |= ENABLE_PORT1;
if (of_get_property(np, "marvell,enable-port2", NULL))
pdata->flags |= ENABLE_PORT2;
if (of_get_property(np, "marvell,enable-port3", NULL))
pdata->flags |= ENABLE_PORT3;
if (of_get_property(np, "marvell,port-sense-low", NULL))
pdata->flags |= POWER_SENSE_LOW;
if (of_get_property(np, "marvell,power-control-low", NULL))
pdata->flags |= POWER_CONTROL_LOW;
if (of_get_property(np, "marvell,no-oc-protection", NULL))
pdata->flags |= NO_OC_PROTECTION;
if (of_get_property(np, "marvell,oc-mode-perport", NULL))
pdata->flags |= OC_MODE_PERPORT;
if (!of_property_read_u32(np, "marvell,power-on-delay", &tmp))
pdata->power_on_delay = tmp;
if (!of_property_read_u32(np, "marvell,port-mode", &tmp))
pdata->port_mode = tmp;
if (!of_property_read_u32(np, "marvell,power-budget", &tmp))
pdata->power_budget = tmp;
pdev->dev.platform_data = pdata;
return 0;
}
static int ohci_pxa_of_init(struct platform_device *pdev)
{
return 0;
}
int usb_hcd_pxa27x_probe (const struct hc_driver *driver, struct platform_device *pdev)
{
int retval, irq;
struct usb_hcd *hcd;
struct pxaohci_platform_data *inf;
struct pxa27x_ohci *pxa_ohci;
struct ohci_hcd *ohci;
struct resource *r;
struct clk *usb_clk;
unsigned int i;
retval = ohci_pxa_of_init(pdev);
if (retval)
return retval;
inf = dev_get_platdata(&pdev->dev);
if (!inf)
return -ENODEV;
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
pr_err("no resource of IORESOURCE_IRQ");
return -ENXIO;
}
usb_clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(usb_clk))
return PTR_ERR(usb_clk);
hcd = usb_create_hcd (driver, &pdev->dev, "pxa27x");
if (!hcd)
return -ENOMEM;
r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
hcd->regs = devm_ioremap_resource(&pdev->dev, r);
if (IS_ERR(hcd->regs)) {
retval = PTR_ERR(hcd->regs);
goto err;
}
hcd->rsrc_start = r->start;
hcd->rsrc_len = resource_size(r);
pxa_ohci = to_pxa27x_ohci(hcd);
pxa_ohci->clk = usb_clk;
pxa_ohci->mmio_base = (void __iomem *)hcd->regs;
for (i = 0; i < 3; ++i) {
char name[6];
if (!(inf->flags & (ENABLE_PORT1 << i)))
continue;
sprintf(name, "vbus%u", i + 1);
pxa_ohci->vbus[i] = devm_regulator_get(&pdev->dev, name);
}
retval = pxa27x_start_hc(pxa_ohci, &pdev->dev);
if (retval < 0) {
pr_debug("pxa27x_start_hc failed");
goto err;
}
pxa27x_ohci_select_pmm(pxa_ohci, inf->port_mode);
if (inf->power_budget)
hcd->power_budget = inf->power_budget;
ohci = hcd_to_ohci(hcd);
ohci->num_ports = 3;
retval = usb_add_hcd(hcd, irq, 0);
if (retval == 0) {
device_wakeup_enable(hcd->self.controller);
return retval;
}
pxa27x_stop_hc(pxa_ohci, &pdev->dev);
err:
usb_put_hcd(hcd);
return retval;
}
void usb_hcd_pxa27x_remove (struct usb_hcd *hcd, struct platform_device *pdev)
{
struct pxa27x_ohci *pxa_ohci = to_pxa27x_ohci(hcd);
unsigned int i;
usb_remove_hcd(hcd);
pxa27x_stop_hc(pxa_ohci, &pdev->dev);
for (i = 0; i < 3; ++i)
pxa27x_ohci_set_vbus_power(pxa_ohci, i, false);
usb_put_hcd(hcd);
}
static int ohci_hcd_pxa27x_drv_probe(struct platform_device *pdev)
{
pr_debug ("In ohci_hcd_pxa27x_drv_probe");
if (usb_disabled())
return -ENODEV;
return usb_hcd_pxa27x_probe(&ohci_pxa27x_hc_driver, pdev);
}
static int ohci_hcd_pxa27x_drv_remove(struct platform_device *pdev)
{
struct usb_hcd *hcd = platform_get_drvdata(pdev);
usb_hcd_pxa27x_remove(hcd, pdev);
return 0;
}
static int ohci_hcd_pxa27x_drv_suspend(struct device *dev)
{
struct usb_hcd *hcd = dev_get_drvdata(dev);
struct pxa27x_ohci *pxa_ohci = to_pxa27x_ohci(hcd);
struct ohci_hcd *ohci = hcd_to_ohci(hcd);
bool do_wakeup = device_may_wakeup(dev);
int ret;
if (time_before(jiffies, ohci->next_statechange))
msleep(5);
ohci->next_statechange = jiffies;
ret = ohci_suspend(hcd, do_wakeup);
if (ret)
return ret;
pxa27x_stop_hc(pxa_ohci, dev);
return ret;
}
static int ohci_hcd_pxa27x_drv_resume(struct device *dev)
{
struct usb_hcd *hcd = dev_get_drvdata(dev);
struct pxa27x_ohci *pxa_ohci = to_pxa27x_ohci(hcd);
struct pxaohci_platform_data *inf = dev_get_platdata(dev);
struct ohci_hcd *ohci = hcd_to_ohci(hcd);
int status;
if (time_before(jiffies, ohci->next_statechange))
msleep(5);
ohci->next_statechange = jiffies;
status = pxa27x_start_hc(pxa_ohci, dev);
if (status < 0)
return status;
pxa27x_ohci_select_pmm(pxa_ohci, inf->port_mode);
ohci_resume(hcd, false);
return 0;
}
static int __init ohci_pxa27x_init(void)
{
if (usb_disabled())
return -ENODEV;
pr_info("%s: " DRIVER_DESC "\n", hcd_name);
ohci_init_driver(&ohci_pxa27x_hc_driver, &pxa27x_overrides);
ohci_pxa27x_hc_driver.hub_control = pxa27x_ohci_hub_control;
return platform_driver_register(&ohci_hcd_pxa27x_driver);
}
static void __exit ohci_pxa27x_cleanup(void)
{
platform_driver_unregister(&ohci_hcd_pxa27x_driver);
}
