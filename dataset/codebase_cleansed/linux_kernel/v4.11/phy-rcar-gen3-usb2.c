static void rcar_gen3_phy_usb2_work(struct work_struct *work)
{
struct rcar_gen3_chan *ch = container_of(work, struct rcar_gen3_chan,
work);
if (ch->extcon_host) {
extcon_set_state_sync(ch->extcon, EXTCON_USB_HOST, true);
extcon_set_state_sync(ch->extcon, EXTCON_USB, false);
} else {
extcon_set_state_sync(ch->extcon, EXTCON_USB_HOST, false);
extcon_set_state_sync(ch->extcon, EXTCON_USB, true);
}
}
static void rcar_gen3_set_host_mode(struct rcar_gen3_chan *ch, int host)
{
void __iomem *usb2_base = ch->base;
u32 val = readl(usb2_base + USB2_COMMCTRL);
dev_vdbg(&ch->phy->dev, "%s: %08x, %d\n", __func__, val, host);
if (host)
val &= ~USB2_COMMCTRL_OTG_PERI;
else
val |= USB2_COMMCTRL_OTG_PERI;
writel(val, usb2_base + USB2_COMMCTRL);
}
static void rcar_gen3_set_linectrl(struct rcar_gen3_chan *ch, int dp, int dm)
{
void __iomem *usb2_base = ch->base;
u32 val = readl(usb2_base + USB2_LINECTRL1);
dev_vdbg(&ch->phy->dev, "%s: %08x, %d, %d\n", __func__, val, dp, dm);
val &= ~(USB2_LINECTRL1_DP_RPD | USB2_LINECTRL1_DM_RPD);
if (dp)
val |= USB2_LINECTRL1_DP_RPD;
if (dm)
val |= USB2_LINECTRL1_DM_RPD;
writel(val, usb2_base + USB2_LINECTRL1);
}
static void rcar_gen3_enable_vbus_ctrl(struct rcar_gen3_chan *ch, int vbus)
{
void __iomem *usb2_base = ch->base;
u32 val = readl(usb2_base + USB2_ADPCTRL);
dev_vdbg(&ch->phy->dev, "%s: %08x, %d\n", __func__, val, vbus);
if (vbus)
val |= USB2_ADPCTRL_DRVVBUS;
else
val &= ~USB2_ADPCTRL_DRVVBUS;
writel(val, usb2_base + USB2_ADPCTRL);
}
static void rcar_gen3_init_for_host(struct rcar_gen3_chan *ch)
{
rcar_gen3_set_linectrl(ch, 1, 1);
rcar_gen3_set_host_mode(ch, 1);
rcar_gen3_enable_vbus_ctrl(ch, 1);
ch->extcon_host = true;
schedule_work(&ch->work);
}
static void rcar_gen3_init_for_peri(struct rcar_gen3_chan *ch)
{
rcar_gen3_set_linectrl(ch, 0, 1);
rcar_gen3_set_host_mode(ch, 0);
rcar_gen3_enable_vbus_ctrl(ch, 0);
ch->extcon_host = false;
schedule_work(&ch->work);
}
static void rcar_gen3_init_for_b_host(struct rcar_gen3_chan *ch)
{
void __iomem *usb2_base = ch->base;
u32 val;
val = readl(usb2_base + USB2_LINECTRL1);
writel(val | USB2_LINECTRL1_OPMODE_NODRV, usb2_base + USB2_LINECTRL1);
rcar_gen3_set_linectrl(ch, 1, 1);
rcar_gen3_set_host_mode(ch, 1);
rcar_gen3_enable_vbus_ctrl(ch, 0);
val = readl(usb2_base + USB2_LINECTRL1);
writel(val & ~USB2_LINECTRL1_OPMODE_NODRV, usb2_base + USB2_LINECTRL1);
}
static void rcar_gen3_init_for_a_peri(struct rcar_gen3_chan *ch)
{
rcar_gen3_set_linectrl(ch, 0, 1);
rcar_gen3_set_host_mode(ch, 0);
rcar_gen3_enable_vbus_ctrl(ch, 1);
}
static void rcar_gen3_init_from_a_peri_to_a_host(struct rcar_gen3_chan *ch)
{
void __iomem *usb2_base = ch->base;
u32 val;
val = readl(usb2_base + USB2_OBINTEN);
writel(val & ~USB2_OBINT_BITS, usb2_base + USB2_OBINTEN);
rcar_gen3_enable_vbus_ctrl(ch, 0);
rcar_gen3_init_for_host(ch);
writel(val | USB2_OBINT_BITS, usb2_base + USB2_OBINTEN);
}
static bool rcar_gen3_check_id(struct rcar_gen3_chan *ch)
{
return !!(readl(ch->base + USB2_ADPCTRL) & USB2_ADPCTRL_IDDIG);
}
static void rcar_gen3_device_recognition(struct rcar_gen3_chan *ch)
{
if (!rcar_gen3_check_id(ch))
rcar_gen3_init_for_host(ch);
else
rcar_gen3_init_for_peri(ch);
}
static bool rcar_gen3_is_host(struct rcar_gen3_chan *ch)
{
return !(readl(ch->base + USB2_COMMCTRL) & USB2_COMMCTRL_OTG_PERI);
}
static ssize_t role_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct rcar_gen3_chan *ch = dev_get_drvdata(dev);
bool is_b_device, is_host, new_mode_is_host;
if (!ch->has_otg || !ch->phy->init_count)
return -EIO;
is_b_device = rcar_gen3_check_id(ch);
is_host = rcar_gen3_is_host(ch);
if (!strncmp(buf, "host", strlen("host")))
new_mode_is_host = true;
else if (!strncmp(buf, "peripheral", strlen("peripheral")))
new_mode_is_host = false;
else
return -EINVAL;
if (is_host == new_mode_is_host)
return -EINVAL;
if (new_mode_is_host) {
if (!is_b_device)
rcar_gen3_init_from_a_peri_to_a_host(ch);
else
rcar_gen3_init_for_b_host(ch);
} else {
if (!is_b_device)
rcar_gen3_init_for_a_peri(ch);
else
rcar_gen3_init_for_peri(ch);
}
return count;
}
static ssize_t role_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct rcar_gen3_chan *ch = dev_get_drvdata(dev);
if (!ch->has_otg || !ch->phy->init_count)
return -EIO;
return sprintf(buf, "%s\n", rcar_gen3_is_host(ch) ? "host" :
"peripheral");
}
static void rcar_gen3_init_otg(struct rcar_gen3_chan *ch)
{
void __iomem *usb2_base = ch->base;
u32 val;
val = readl(usb2_base + USB2_VBCTRL);
writel(val | USB2_VBCTRL_DRVVBUSSEL, usb2_base + USB2_VBCTRL);
writel(USB2_OBINT_BITS, usb2_base + USB2_OBINTSTA);
val = readl(usb2_base + USB2_OBINTEN);
writel(val | USB2_OBINT_BITS, usb2_base + USB2_OBINTEN);
val = readl(usb2_base + USB2_ADPCTRL);
writel(val | USB2_ADPCTRL_IDPULLUP, usb2_base + USB2_ADPCTRL);
val = readl(usb2_base + USB2_LINECTRL1);
rcar_gen3_set_linectrl(ch, 0, 0);
writel(val | USB2_LINECTRL1_DPRPD_EN | USB2_LINECTRL1_DMRPD_EN,
usb2_base + USB2_LINECTRL1);
rcar_gen3_device_recognition(ch);
}
static int rcar_gen3_phy_usb2_init(struct phy *p)
{
struct rcar_gen3_chan *channel = phy_get_drvdata(p);
void __iomem *usb2_base = channel->base;
writel(USB2_INT_ENABLE_INIT, usb2_base + USB2_INT_ENABLE);
writel(USB2_SPD_RSM_TIMSET_INIT, usb2_base + USB2_SPD_RSM_TIMSET);
writel(USB2_OC_TIMSET_INIT, usb2_base + USB2_OC_TIMSET);
if (channel->has_otg)
rcar_gen3_init_otg(channel);
return 0;
}
static int rcar_gen3_phy_usb2_exit(struct phy *p)
{
struct rcar_gen3_chan *channel = phy_get_drvdata(p);
writel(0, channel->base + USB2_INT_ENABLE);
return 0;
}
static int rcar_gen3_phy_usb2_power_on(struct phy *p)
{
struct rcar_gen3_chan *channel = phy_get_drvdata(p);
void __iomem *usb2_base = channel->base;
u32 val;
int ret;
if (channel->vbus) {
ret = regulator_enable(channel->vbus);
if (ret)
return ret;
}
val = readl(usb2_base + USB2_USBCTR);
val |= USB2_USBCTR_PLL_RST;
writel(val, usb2_base + USB2_USBCTR);
val &= ~USB2_USBCTR_PLL_RST;
writel(val, usb2_base + USB2_USBCTR);
return 0;
}
static int rcar_gen3_phy_usb2_power_off(struct phy *p)
{
struct rcar_gen3_chan *channel = phy_get_drvdata(p);
int ret = 0;
if (channel->vbus)
ret = regulator_disable(channel->vbus);
return ret;
}
static irqreturn_t rcar_gen3_phy_usb2_irq(int irq, void *_ch)
{
struct rcar_gen3_chan *ch = _ch;
void __iomem *usb2_base = ch->base;
u32 status = readl(usb2_base + USB2_OBINTSTA);
irqreturn_t ret = IRQ_NONE;
if (status & USB2_OBINT_BITS) {
dev_vdbg(&ch->phy->dev, "%s: %08x\n", __func__, status);
writel(USB2_OBINT_BITS, usb2_base + USB2_OBINTSTA);
rcar_gen3_device_recognition(ch);
ret = IRQ_HANDLED;
}
return ret;
}
static int rcar_gen3_phy_usb2_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct rcar_gen3_chan *channel;
struct phy_provider *provider;
struct resource *res;
int irq;
if (!dev->of_node) {
dev_err(dev, "This driver needs device tree\n");
return -EINVAL;
}
channel = devm_kzalloc(dev, sizeof(*channel), GFP_KERNEL);
if (!channel)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
channel->base = devm_ioremap_resource(dev, res);
if (IS_ERR(channel->base))
return PTR_ERR(channel->base);
irq = platform_get_irq(pdev, 0);
if (irq >= 0) {
int ret;
INIT_WORK(&channel->work, rcar_gen3_phy_usb2_work);
irq = devm_request_irq(dev, irq, rcar_gen3_phy_usb2_irq,
IRQF_SHARED, dev_name(dev), channel);
if (irq < 0)
dev_err(dev, "No irq handler (%d)\n", irq);
channel->has_otg = true;
channel->extcon = devm_extcon_dev_allocate(dev,
rcar_gen3_phy_cable);
if (IS_ERR(channel->extcon))
return PTR_ERR(channel->extcon);
ret = devm_extcon_dev_register(dev, channel->extcon);
if (ret < 0) {
dev_err(dev, "Failed to register extcon\n");
return ret;
}
}
channel->phy = devm_phy_create(dev, NULL, &rcar_gen3_phy_usb2_ops);
if (IS_ERR(channel->phy)) {
dev_err(dev, "Failed to create USB2 PHY\n");
return PTR_ERR(channel->phy);
}
channel->vbus = devm_regulator_get_optional(dev, "vbus");
if (IS_ERR(channel->vbus)) {
if (PTR_ERR(channel->vbus) == -EPROBE_DEFER)
return PTR_ERR(channel->vbus);
channel->vbus = NULL;
}
platform_set_drvdata(pdev, channel);
phy_set_drvdata(channel->phy, channel);
provider = devm_of_phy_provider_register(dev, of_phy_simple_xlate);
if (IS_ERR(provider)) {
dev_err(dev, "Failed to register PHY provider\n");
} else if (channel->has_otg) {
int ret;
ret = device_create_file(dev, &dev_attr_role);
if (ret < 0)
return ret;
}
return PTR_ERR_OR_ZERO(provider);
}
static int rcar_gen3_phy_usb2_remove(struct platform_device *pdev)
{
struct rcar_gen3_chan *channel = platform_get_drvdata(pdev);
if (channel->has_otg)
device_remove_file(&pdev->dev, &dev_attr_role);
return 0;
}
