static void ssusb_wakeup_ip_sleep_en(struct ssusb_mtk *ssusb)
{
u32 tmp;
struct regmap *pericfg = ssusb->pericfg;
regmap_read(pericfg, PERI_WK_CTRL1, &tmp);
tmp &= ~UWK_CTL1_IS_P;
tmp &= ~(UWK_CTL1_IS_C(0xf));
tmp |= UWK_CTL1_IS_C(0x8);
regmap_write(pericfg, PERI_WK_CTRL1, tmp);
regmap_write(pericfg, PERI_WK_CTRL1, tmp | UWK_CTL1_IS_E);
regmap_read(pericfg, PERI_WK_CTRL1, &tmp);
dev_dbg(ssusb->dev, "%s(): WK_CTRL1[P6,E25,C26:29]=%#x\n",
__func__, tmp);
}
static void ssusb_wakeup_ip_sleep_dis(struct ssusb_mtk *ssusb)
{
u32 tmp;
regmap_read(ssusb->pericfg, PERI_WK_CTRL1, &tmp);
tmp &= ~UWK_CTL1_IS_E;
regmap_write(ssusb->pericfg, PERI_WK_CTRL1, tmp);
}
int ssusb_wakeup_of_property_parse(struct ssusb_mtk *ssusb,
struct device_node *dn)
{
struct device *dev = ssusb->dev;
ssusb->wakeup_en = of_property_read_bool(dn, "mediatek,enable-wakeup");
if (!ssusb->wakeup_en)
return 0;
ssusb->wk_deb_p0 = devm_clk_get(dev, "wakeup_deb_p0");
if (IS_ERR(ssusb->wk_deb_p0)) {
dev_err(dev, "fail to get wakeup_deb_p0\n");
return PTR_ERR(ssusb->wk_deb_p0);
}
if (of_property_read_bool(dn, "wakeup_deb_p1")) {
ssusb->wk_deb_p1 = devm_clk_get(dev, "wakeup_deb_p1");
if (IS_ERR(ssusb->wk_deb_p1)) {
dev_err(dev, "fail to get wakeup_deb_p1\n");
return PTR_ERR(ssusb->wk_deb_p1);
}
}
ssusb->pericfg = syscon_regmap_lookup_by_phandle(dn,
"mediatek,syscon-wakeup");
if (IS_ERR(ssusb->pericfg)) {
dev_err(dev, "fail to get pericfg regs\n");
return PTR_ERR(ssusb->pericfg);
}
return 0;
}
static int ssusb_wakeup_clks_enable(struct ssusb_mtk *ssusb)
{
int ret;
ret = clk_prepare_enable(ssusb->wk_deb_p0);
if (ret) {
dev_err(ssusb->dev, "failed to enable wk_deb_p0\n");
goto usb_p0_err;
}
ret = clk_prepare_enable(ssusb->wk_deb_p1);
if (ret) {
dev_err(ssusb->dev, "failed to enable wk_deb_p1\n");
goto usb_p1_err;
}
return 0;
usb_p1_err:
clk_disable_unprepare(ssusb->wk_deb_p0);
usb_p0_err:
return -EINVAL;
}
static void ssusb_wakeup_clks_disable(struct ssusb_mtk *ssusb)
{
clk_disable_unprepare(ssusb->wk_deb_p1);
clk_disable_unprepare(ssusb->wk_deb_p0);
}
static void host_ports_num_get(struct ssusb_mtk *ssusb)
{
u32 xhci_cap;
xhci_cap = mtu3_readl(ssusb->ippc_base, U3D_SSUSB_IP_XHCI_CAP);
ssusb->u2_ports = SSUSB_IP_XHCI_U2_PORT_NUM(xhci_cap);
ssusb->u3_ports = SSUSB_IP_XHCI_U3_PORT_NUM(xhci_cap);
dev_dbg(ssusb->dev, "host - u2_ports:%d, u3_ports:%d\n",
ssusb->u2_ports, ssusb->u3_ports);
}
int ssusb_host_enable(struct ssusb_mtk *ssusb)
{
void __iomem *ibase = ssusb->ippc_base;
int num_u3p = ssusb->u3_ports;
int num_u2p = ssusb->u2_ports;
u32 check_clk;
u32 value;
int i;
mtu3_clrbits(ibase, U3D_SSUSB_IP_PW_CTRL1, SSUSB_IP_HOST_PDN);
for (i = 0; i < num_u3p; i++) {
value = mtu3_readl(ibase, SSUSB_U3_CTRL(i));
value &= ~(SSUSB_U3_PORT_PDN | SSUSB_U3_PORT_DIS);
value |= SSUSB_U3_PORT_HOST_SEL;
mtu3_writel(ibase, SSUSB_U3_CTRL(i), value);
}
for (i = 0; i < num_u2p; i++) {
value = mtu3_readl(ibase, SSUSB_U2_CTRL(i));
value &= ~(SSUSB_U2_PORT_PDN | SSUSB_U2_PORT_DIS);
value |= SSUSB_U2_PORT_HOST_SEL;
mtu3_writel(ibase, SSUSB_U2_CTRL(i), value);
}
check_clk = SSUSB_XHCI_RST_B_STS;
if (num_u3p)
check_clk = SSUSB_U3_MAC_RST_B_STS;
return ssusb_check_clocks(ssusb, check_clk);
}
int ssusb_host_disable(struct ssusb_mtk *ssusb, bool suspend)
{
void __iomem *ibase = ssusb->ippc_base;
int num_u3p = ssusb->u3_ports;
int num_u2p = ssusb->u2_ports;
u32 value;
int ret;
int i;
for (i = 0; i < num_u3p; i++) {
value = mtu3_readl(ibase, SSUSB_U3_CTRL(i));
value |= SSUSB_U3_PORT_PDN;
value |= suspend ? 0 : SSUSB_U3_PORT_DIS;
mtu3_writel(ibase, SSUSB_U3_CTRL(i), value);
}
for (i = 0; i < num_u2p; i++) {
value = mtu3_readl(ibase, SSUSB_U2_CTRL(i));
value |= SSUSB_U2_PORT_PDN;
value |= suspend ? 0 : SSUSB_U2_PORT_DIS;
mtu3_writel(ibase, SSUSB_U2_CTRL(i), value);
}
mtu3_setbits(ibase, U3D_SSUSB_IP_PW_CTRL1, SSUSB_IP_HOST_PDN);
if (!suspend)
return 0;
ret = readl_poll_timeout(ibase + U3D_SSUSB_IP_PW_STS1, value,
(value & SSUSB_IP_SLEEP_STS), 100, 100000);
if (ret)
dev_err(ssusb->dev, "ip sleep failed!!!\n");
return ret;
}
static void ssusb_host_setup(struct ssusb_mtk *ssusb)
{
host_ports_num_get(ssusb);
ssusb_host_enable(ssusb);
ssusb_set_vbus(&ssusb->otg_switch, 1);
}
static void ssusb_host_cleanup(struct ssusb_mtk *ssusb)
{
if (ssusb->is_host)
ssusb_set_vbus(&ssusb->otg_switch, 0);
ssusb_host_disable(ssusb, false);
}
int ssusb_host_init(struct ssusb_mtk *ssusb, struct device_node *parent_dn)
{
struct device *parent_dev = ssusb->dev;
int ret;
ssusb_host_setup(ssusb);
ret = of_platform_populate(parent_dn, NULL, NULL, parent_dev);
if (ret) {
dev_dbg(parent_dev, "failed to create child devices at %s\n",
parent_dn->full_name);
return ret;
}
dev_info(parent_dev, "xHCI platform device register success...\n");
return 0;
}
void ssusb_host_exit(struct ssusb_mtk *ssusb)
{
of_platform_depopulate(ssusb->dev);
ssusb_host_cleanup(ssusb);
}
int ssusb_wakeup_enable(struct ssusb_mtk *ssusb)
{
int ret = 0;
if (ssusb->wakeup_en) {
ret = ssusb_wakeup_clks_enable(ssusb);
ssusb_wakeup_ip_sleep_en(ssusb);
}
return ret;
}
void ssusb_wakeup_disable(struct ssusb_mtk *ssusb)
{
if (ssusb->wakeup_en) {
ssusb_wakeup_ip_sleep_dis(ssusb);
ssusb_wakeup_clks_disable(ssusb);
}
}
