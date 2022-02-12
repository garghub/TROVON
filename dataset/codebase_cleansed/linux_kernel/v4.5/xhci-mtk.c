static int xhci_mtk_host_enable(struct xhci_hcd_mtk *mtk)
{
struct mu3c_ippc_regs __iomem *ippc = mtk->ippc_regs;
u32 value, check_val;
int ret;
int i;
value = readl(&ippc->ip_pw_ctr1);
value &= ~CTRL1_IP_HOST_PDN;
writel(value, &ippc->ip_pw_ctr1);
for (i = 0; i < mtk->num_u3_ports; i++) {
value = readl(&ippc->u3_ctrl_p[i]);
value &= ~(CTRL_U3_PORT_PDN | CTRL_U3_PORT_DIS);
value |= CTRL_U3_PORT_HOST_SEL;
writel(value, &ippc->u3_ctrl_p[i]);
}
for (i = 0; i < mtk->num_u2_ports; i++) {
value = readl(&ippc->u2_ctrl_p[i]);
value &= ~(CTRL_U2_PORT_PDN | CTRL_U2_PORT_DIS);
value |= CTRL_U2_PORT_HOST_SEL;
writel(value, &ippc->u2_ctrl_p[i]);
}
check_val = STS1_SYSPLL_STABLE | STS1_REF_RST |
STS1_SYS125_RST | STS1_XHCI_RST;
ret = readl_poll_timeout(&ippc->ip_pw_sts1, value,
(check_val == (value & check_val)), 100, 20000);
if (ret) {
dev_err(mtk->dev, "clocks are not stable (0x%x)\n", value);
return ret;
}
return 0;
}
static int xhci_mtk_host_disable(struct xhci_hcd_mtk *mtk)
{
struct mu3c_ippc_regs __iomem *ippc = mtk->ippc_regs;
u32 value;
int ret;
int i;
for (i = 0; i < mtk->num_u3_ports; i++) {
value = readl(&ippc->u3_ctrl_p[i]);
value |= CTRL_U3_PORT_PDN;
writel(value, &ippc->u3_ctrl_p[i]);
}
for (i = 0; i < mtk->num_u2_ports; i++) {
value = readl(&ippc->u2_ctrl_p[i]);
value |= CTRL_U2_PORT_PDN;
writel(value, &ippc->u2_ctrl_p[i]);
}
value = readl(&ippc->ip_pw_ctr1);
value |= CTRL1_IP_HOST_PDN;
writel(value, &ippc->ip_pw_ctr1);
ret = readl_poll_timeout(&ippc->ip_pw_sts1, value,
(value & STS1_IP_SLEEP_STS), 100, 100000);
if (ret) {
dev_err(mtk->dev, "ip sleep failed!!!\n");
return ret;
}
return 0;
}
static int xhci_mtk_ssusb_config(struct xhci_hcd_mtk *mtk)
{
struct mu3c_ippc_regs __iomem *ippc = mtk->ippc_regs;
u32 value;
value = readl(&ippc->ip_pw_ctr0);
value |= CTRL0_IP_SW_RST;
writel(value, &ippc->ip_pw_ctr0);
udelay(1);
value = readl(&ippc->ip_pw_ctr0);
value &= ~CTRL0_IP_SW_RST;
writel(value, &ippc->ip_pw_ctr0);
value = readl(&ippc->ip_pw_ctr2);
value |= CTRL2_IP_DEV_PDN;
writel(value, &ippc->ip_pw_ctr2);
value = readl(&ippc->ip_xhci_cap);
mtk->num_u3_ports = CAP_U3_PORT_NUM(value);
mtk->num_u2_ports = CAP_U2_PORT_NUM(value);
dev_dbg(mtk->dev, "%s u2p:%d, u3p:%d\n", __func__,
mtk->num_u2_ports, mtk->num_u3_ports);
return xhci_mtk_host_enable(mtk);
}
static int xhci_mtk_clks_enable(struct xhci_hcd_mtk *mtk)
{
int ret;
ret = clk_prepare_enable(mtk->sys_clk);
if (ret) {
dev_err(mtk->dev, "failed to enable sys_clk\n");
goto sys_clk_err;
}
if (mtk->wakeup_src) {
ret = clk_prepare_enable(mtk->wk_deb_p0);
if (ret) {
dev_err(mtk->dev, "failed to enable wk_deb_p0\n");
goto usb_p0_err;
}
ret = clk_prepare_enable(mtk->wk_deb_p1);
if (ret) {
dev_err(mtk->dev, "failed to enable wk_deb_p1\n");
goto usb_p1_err;
}
}
return 0;
usb_p1_err:
clk_disable_unprepare(mtk->wk_deb_p0);
usb_p0_err:
clk_disable_unprepare(mtk->sys_clk);
sys_clk_err:
return -EINVAL;
}
static void xhci_mtk_clks_disable(struct xhci_hcd_mtk *mtk)
{
if (mtk->wakeup_src) {
clk_disable_unprepare(mtk->wk_deb_p1);
clk_disable_unprepare(mtk->wk_deb_p0);
}
clk_disable_unprepare(mtk->sys_clk);
}
static void usb_wakeup_ip_sleep_en(struct xhci_hcd_mtk *mtk)
{
u32 tmp;
struct regmap *pericfg = mtk->pericfg;
regmap_read(pericfg, PERI_WK_CTRL1, &tmp);
tmp &= ~UWK_CTL1_IS_P;
tmp &= ~(UWK_CTL1_IS_C(0xf));
tmp |= UWK_CTL1_IS_C(0x8);
regmap_write(pericfg, PERI_WK_CTRL1, tmp);
regmap_write(pericfg, PERI_WK_CTRL1, tmp | UWK_CTL1_IS_E);
regmap_read(pericfg, PERI_WK_CTRL1, &tmp);
dev_dbg(mtk->dev, "%s(): WK_CTRL1[P6,E25,C26:29]=%#x\n",
__func__, tmp);
}
static void usb_wakeup_ip_sleep_dis(struct xhci_hcd_mtk *mtk)
{
u32 tmp;
regmap_read(mtk->pericfg, PERI_WK_CTRL1, &tmp);
tmp &= ~UWK_CTL1_IS_E;
regmap_write(mtk->pericfg, PERI_WK_CTRL1, tmp);
}
static void usb_wakeup_line_state_en(struct xhci_hcd_mtk *mtk)
{
u32 tmp;
struct regmap *pericfg = mtk->pericfg;
regmap_read(pericfg, PERI_WK_CTRL1, &tmp);
tmp &= ~UWK_CTL1_0P_LS_P;
tmp &= ~(UWK_CTL1_0P_LS_C(0xf));
tmp |= UWK_CTL1_0P_LS_C(0x8);
regmap_write(pericfg, PERI_WK_CTRL1, tmp);
regmap_read(pericfg, PERI_WK_CTRL1, &tmp);
regmap_write(pericfg, PERI_WK_CTRL1, tmp | UWK_CTL1_0P_LS_E);
regmap_read(pericfg, PERI_WK_CTRL0, &tmp);
tmp &= ~(UWK_CTL1_1P_LS_C(0xf));
tmp |= UWK_CTL1_1P_LS_C(0x8);
regmap_write(pericfg, PERI_WK_CTRL0, tmp);
regmap_write(pericfg, PERI_WK_CTRL0, tmp | UWK_CTL1_1P_LS_E);
}
static void usb_wakeup_line_state_dis(struct xhci_hcd_mtk *mtk)
{
u32 tmp;
struct regmap *pericfg = mtk->pericfg;
regmap_read(pericfg, PERI_WK_CTRL1, &tmp);
tmp &= ~UWK_CTL1_0P_LS_E;
regmap_write(pericfg, PERI_WK_CTRL1, tmp);
regmap_read(pericfg, PERI_WK_CTRL0, &tmp);
tmp &= ~UWK_CTL1_1P_LS_E;
regmap_write(pericfg, PERI_WK_CTRL0, tmp);
}
static void usb_wakeup_enable(struct xhci_hcd_mtk *mtk)
{
if (mtk->wakeup_src == SSUSB_WK_IP_SLEEP)
usb_wakeup_ip_sleep_en(mtk);
else if (mtk->wakeup_src == SSUSB_WK_LINE_STATE)
usb_wakeup_line_state_en(mtk);
}
static void usb_wakeup_disable(struct xhci_hcd_mtk *mtk)
{
if (mtk->wakeup_src == SSUSB_WK_IP_SLEEP)
usb_wakeup_ip_sleep_dis(mtk);
else if (mtk->wakeup_src == SSUSB_WK_LINE_STATE)
usb_wakeup_line_state_dis(mtk);
}
static int usb_wakeup_of_property_parse(struct xhci_hcd_mtk *mtk,
struct device_node *dn)
{
struct device *dev = mtk->dev;
of_property_read_u32(dn, "mediatek,wakeup-src", &mtk->wakeup_src);
if (!mtk->wakeup_src)
return 0;
mtk->wk_deb_p0 = devm_clk_get(dev, "wakeup_deb_p0");
if (IS_ERR(mtk->wk_deb_p0)) {
dev_err(dev, "fail to get wakeup_deb_p0\n");
return PTR_ERR(mtk->wk_deb_p0);
}
mtk->wk_deb_p1 = devm_clk_get(dev, "wakeup_deb_p1");
if (IS_ERR(mtk->wk_deb_p1)) {
dev_err(dev, "fail to get wakeup_deb_p1\n");
return PTR_ERR(mtk->wk_deb_p1);
}
mtk->pericfg = syscon_regmap_lookup_by_phandle(dn,
"mediatek,syscon-wakeup");
if (IS_ERR(mtk->pericfg)) {
dev_err(dev, "fail to get pericfg regs\n");
return PTR_ERR(mtk->pericfg);
}
return 0;
}
static int xhci_mtk_phy_init(struct xhci_hcd_mtk *mtk)
{
int i;
int ret;
for (i = 0; i < mtk->num_phys; i++) {
ret = phy_init(mtk->phys[i]);
if (ret)
goto exit_phy;
}
return 0;
exit_phy:
for (; i > 0; i--)
phy_exit(mtk->phys[i - 1]);
return ret;
}
static int xhci_mtk_phy_exit(struct xhci_hcd_mtk *mtk)
{
int i;
for (i = 0; i < mtk->num_phys; i++)
phy_exit(mtk->phys[i]);
return 0;
}
static int xhci_mtk_phy_power_on(struct xhci_hcd_mtk *mtk)
{
int i;
int ret;
for (i = 0; i < mtk->num_phys; i++) {
ret = phy_power_on(mtk->phys[i]);
if (ret)
goto power_off_phy;
}
return 0;
power_off_phy:
for (; i > 0; i--)
phy_power_off(mtk->phys[i - 1]);
return ret;
}
static void xhci_mtk_phy_power_off(struct xhci_hcd_mtk *mtk)
{
unsigned int i;
for (i = 0; i < mtk->num_phys; i++)
phy_power_off(mtk->phys[i]);
}
static int xhci_mtk_ldos_enable(struct xhci_hcd_mtk *mtk)
{
int ret;
ret = regulator_enable(mtk->vbus);
if (ret) {
dev_err(mtk->dev, "failed to enable vbus\n");
return ret;
}
ret = regulator_enable(mtk->vusb33);
if (ret) {
dev_err(mtk->dev, "failed to enable vusb33\n");
regulator_disable(mtk->vbus);
return ret;
}
return 0;
}
static void xhci_mtk_ldos_disable(struct xhci_hcd_mtk *mtk)
{
regulator_disable(mtk->vbus);
regulator_disable(mtk->vusb33);
}
static void xhci_mtk_quirks(struct device *dev, struct xhci_hcd *xhci)
{
struct usb_hcd *hcd = xhci_to_hcd(xhci);
struct xhci_hcd_mtk *mtk = hcd_to_mtk(hcd);
xhci->quirks |= XHCI_PLAT;
xhci->quirks |= XHCI_MTK_HOST;
xhci->quirks |= XHCI_SPURIOUS_SUCCESS;
if (mtk->lpm_support)
xhci->quirks |= XHCI_LPM_SUPPORT;
}
static int xhci_mtk_setup(struct usb_hcd *hcd)
{
struct xhci_hcd_mtk *mtk = hcd_to_mtk(hcd);
int ret;
if (usb_hcd_is_primary_hcd(hcd)) {
ret = xhci_mtk_ssusb_config(mtk);
if (ret)
return ret;
ret = xhci_mtk_sch_init(mtk);
if (ret)
return ret;
}
return xhci_gen_setup(hcd, xhci_mtk_quirks);
}
static int xhci_mtk_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct device_node *node = dev->of_node;
struct xhci_hcd_mtk *mtk;
const struct hc_driver *driver;
struct xhci_hcd *xhci;
struct resource *res;
struct usb_hcd *hcd;
struct phy *phy;
int phy_num;
int ret = -ENODEV;
int irq;
if (usb_disabled())
return -ENODEV;
driver = &xhci_mtk_hc_driver;
mtk = devm_kzalloc(dev, sizeof(*mtk), GFP_KERNEL);
if (!mtk)
return -ENOMEM;
mtk->dev = dev;
mtk->vbus = devm_regulator_get(dev, "vbus");
if (IS_ERR(mtk->vbus)) {
dev_err(dev, "fail to get vbus\n");
return PTR_ERR(mtk->vbus);
}
mtk->vusb33 = devm_regulator_get(dev, "vusb33");
if (IS_ERR(mtk->vusb33)) {
dev_err(dev, "fail to get vusb33\n");
return PTR_ERR(mtk->vusb33);
}
mtk->sys_clk = devm_clk_get(dev, "sys_ck");
if (IS_ERR(mtk->sys_clk)) {
dev_err(dev, "fail to get sys_ck\n");
return PTR_ERR(mtk->sys_clk);
}
mtk->lpm_support = of_property_read_bool(node, "usb3-lpm-capable");
ret = usb_wakeup_of_property_parse(mtk, node);
if (ret)
return ret;
mtk->num_phys = of_count_phandle_with_args(node,
"phys", "#phy-cells");
if (mtk->num_phys > 0) {
mtk->phys = devm_kcalloc(dev, mtk->num_phys,
sizeof(*mtk->phys), GFP_KERNEL);
if (!mtk->phys)
return -ENOMEM;
} else {
mtk->num_phys = 0;
}
pm_runtime_enable(dev);
pm_runtime_get_sync(dev);
device_enable_async_suspend(dev);
ret = xhci_mtk_ldos_enable(mtk);
if (ret)
goto disable_pm;
ret = xhci_mtk_clks_enable(mtk);
if (ret)
goto disable_ldos;
irq = platform_get_irq(pdev, 0);
if (irq < 0)
goto disable_clk;
ret = dma_set_coherent_mask(dev, DMA_BIT_MASK(32));
if (ret)
goto disable_clk;
if (!dev->dma_mask)
dev->dma_mask = &dev->coherent_dma_mask;
else
dma_set_mask(dev, DMA_BIT_MASK(32));
hcd = usb_create_hcd(driver, dev, dev_name(dev));
if (!hcd) {
ret = -ENOMEM;
goto disable_clk;
}
mtk->hcd = platform_get_drvdata(pdev);
platform_set_drvdata(pdev, mtk);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
hcd->regs = devm_ioremap_resource(dev, res);
if (IS_ERR(hcd->regs)) {
ret = PTR_ERR(hcd->regs);
goto put_usb2_hcd;
}
hcd->rsrc_start = res->start;
hcd->rsrc_len = resource_size(res);
res = platform_get_resource(pdev, IORESOURCE_MEM, 1);
mtk->ippc_regs = devm_ioremap_resource(dev, res);
if (IS_ERR(mtk->ippc_regs)) {
ret = PTR_ERR(mtk->ippc_regs);
goto put_usb2_hcd;
}
for (phy_num = 0; phy_num < mtk->num_phys; phy_num++) {
phy = devm_of_phy_get_by_index(dev, node, phy_num);
if (IS_ERR(phy)) {
ret = PTR_ERR(phy);
goto put_usb2_hcd;
}
mtk->phys[phy_num] = phy;
}
ret = xhci_mtk_phy_init(mtk);
if (ret)
goto put_usb2_hcd;
ret = xhci_mtk_phy_power_on(mtk);
if (ret)
goto exit_phys;
device_init_wakeup(dev, true);
xhci = hcd_to_xhci(hcd);
xhci->main_hcd = hcd;
xhci->shared_hcd = usb_create_shared_hcd(driver, dev,
dev_name(dev), hcd);
if (!xhci->shared_hcd) {
ret = -ENOMEM;
goto power_off_phys;
}
if (HCC_MAX_PSA(xhci->hcc_params) >= 4)
xhci->shared_hcd->can_do_streams = 1;
ret = usb_add_hcd(hcd, irq, IRQF_SHARED);
if (ret)
goto put_usb3_hcd;
ret = usb_add_hcd(xhci->shared_hcd, irq, IRQF_SHARED);
if (ret)
goto dealloc_usb2_hcd;
return 0;
dealloc_usb2_hcd:
usb_remove_hcd(hcd);
put_usb3_hcd:
xhci_mtk_sch_exit(mtk);
usb_put_hcd(xhci->shared_hcd);
power_off_phys:
xhci_mtk_phy_power_off(mtk);
device_init_wakeup(dev, false);
exit_phys:
xhci_mtk_phy_exit(mtk);
put_usb2_hcd:
usb_put_hcd(hcd);
disable_clk:
xhci_mtk_clks_disable(mtk);
disable_ldos:
xhci_mtk_ldos_disable(mtk);
disable_pm:
pm_runtime_put_sync(dev);
pm_runtime_disable(dev);
return ret;
}
static int xhci_mtk_remove(struct platform_device *dev)
{
struct xhci_hcd_mtk *mtk = platform_get_drvdata(dev);
struct usb_hcd *hcd = mtk->hcd;
struct xhci_hcd *xhci = hcd_to_xhci(hcd);
usb_remove_hcd(xhci->shared_hcd);
xhci_mtk_phy_power_off(mtk);
xhci_mtk_phy_exit(mtk);
device_init_wakeup(&dev->dev, false);
usb_remove_hcd(hcd);
usb_put_hcd(xhci->shared_hcd);
usb_put_hcd(hcd);
xhci_mtk_sch_exit(mtk);
xhci_mtk_clks_disable(mtk);
xhci_mtk_ldos_disable(mtk);
pm_runtime_put_sync(&dev->dev);
pm_runtime_disable(&dev->dev);
return 0;
}
static int xhci_mtk_suspend(struct device *dev)
{
struct xhci_hcd_mtk *mtk = dev_get_drvdata(dev);
struct usb_hcd *hcd = mtk->hcd;
struct xhci_hcd *xhci = hcd_to_xhci(hcd);
xhci_dbg(xhci, "%s: stop port polling\n", __func__);
clear_bit(HCD_FLAG_POLL_RH, &hcd->flags);
del_timer_sync(&hcd->rh_timer);
clear_bit(HCD_FLAG_POLL_RH, &xhci->shared_hcd->flags);
del_timer_sync(&xhci->shared_hcd->rh_timer);
xhci_mtk_host_disable(mtk);
xhci_mtk_phy_power_off(mtk);
xhci_mtk_clks_disable(mtk);
usb_wakeup_enable(mtk);
return 0;
}
static int xhci_mtk_resume(struct device *dev)
{
struct xhci_hcd_mtk *mtk = dev_get_drvdata(dev);
struct usb_hcd *hcd = mtk->hcd;
struct xhci_hcd *xhci = hcd_to_xhci(hcd);
usb_wakeup_disable(mtk);
xhci_mtk_clks_enable(mtk);
xhci_mtk_phy_power_on(mtk);
xhci_mtk_host_enable(mtk);
xhci_dbg(xhci, "%s: restart port polling\n", __func__);
set_bit(HCD_FLAG_POLL_RH, &hcd->flags);
usb_hcd_poll_rh_status(hcd);
set_bit(HCD_FLAG_POLL_RH, &xhci->shared_hcd->flags);
usb_hcd_poll_rh_status(xhci->shared_hcd);
return 0;
}
static int __init xhci_mtk_init(void)
{
xhci_init_driver(&xhci_mtk_hc_driver, &xhci_mtk_overrides);
return platform_driver_register(&mtk_xhci_driver);
}
static void __exit xhci_mtk_exit(void)
{
platform_driver_unregister(&mtk_xhci_driver);
}
