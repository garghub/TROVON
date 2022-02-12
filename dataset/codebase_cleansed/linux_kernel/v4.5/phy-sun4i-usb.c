static void sun4i_usb_phy0_update_iscr(struct phy *_phy, u32 clr, u32 set)
{
struct sun4i_usb_phy *phy = phy_get_drvdata(_phy);
struct sun4i_usb_phy_data *data = to_sun4i_usb_phy_data(phy);
u32 iscr;
iscr = readl(data->base + REG_ISCR);
iscr &= ~clr;
iscr |= set;
writel(iscr, data->base + REG_ISCR);
}
static void sun4i_usb_phy0_set_id_detect(struct phy *phy, u32 val)
{
if (val)
val = ISCR_FORCE_ID_HIGH;
else
val = ISCR_FORCE_ID_LOW;
sun4i_usb_phy0_update_iscr(phy, ISCR_FORCE_ID_MASK, val);
}
static void sun4i_usb_phy0_set_vbus_detect(struct phy *phy, u32 val)
{
if (val)
val = ISCR_FORCE_VBUS_HIGH;
else
val = ISCR_FORCE_VBUS_LOW;
sun4i_usb_phy0_update_iscr(phy, ISCR_FORCE_VBUS_MASK, val);
}
static void sun4i_usb_phy_write(struct sun4i_usb_phy *phy, u32 addr, u32 data,
int len)
{
struct sun4i_usb_phy_data *phy_data = to_sun4i_usb_phy_data(phy);
u32 temp, usbc_bit = BIT(phy->index * 2);
void *phyctl = phy_data->base + phy_data->cfg->phyctl_offset;
int i;
mutex_lock(&phy_data->mutex);
if (phy_data->cfg->type == sun8i_a33_phy) {
writel(0, phyctl);
}
for (i = 0; i < len; i++) {
temp = readl(phyctl);
temp &= ~(0xff << 8);
temp |= ((addr + i) << 8);
writel(temp, phyctl);
temp = readb(phyctl);
if (data & 0x1)
temp |= PHYCTL_DATA;
else
temp &= ~PHYCTL_DATA;
temp &= ~usbc_bit;
writeb(temp, phyctl);
temp = readb(phyctl);
temp |= usbc_bit;
writeb(temp, phyctl);
temp = readb(phyctl);
temp &= ~usbc_bit;
writeb(temp, phyctl);
data >>= 1;
}
mutex_unlock(&phy_data->mutex);
}
static void sun4i_usb_phy_passby(struct sun4i_usb_phy *phy, int enable)
{
u32 bits, reg_value;
if (!phy->pmu)
return;
bits = SUNXI_AHB_ICHR8_EN | SUNXI_AHB_INCR4_BURST_EN |
SUNXI_AHB_INCRX_ALIGN_EN | SUNXI_ULPI_BYPASS_EN;
reg_value = readl(phy->pmu);
if (enable)
reg_value |= bits;
else
reg_value &= ~bits;
writel(reg_value, phy->pmu);
}
static int sun4i_usb_phy_init(struct phy *_phy)
{
struct sun4i_usb_phy *phy = phy_get_drvdata(_phy);
struct sun4i_usb_phy_data *data = to_sun4i_usb_phy_data(phy);
int ret;
u32 val;
ret = clk_prepare_enable(phy->clk);
if (ret)
return ret;
ret = reset_control_deassert(phy->reset);
if (ret) {
clk_disable_unprepare(phy->clk);
return ret;
}
if (data->cfg->type == sun8i_h3_phy) {
if (phy->index == 0) {
val = readl(data->base + REG_PHY_UNK_H3);
writel(val & ~1, data->base + REG_PHY_UNK_H3);
}
val = readl(phy->pmu + REG_PMU_UNK_H3);
writel(val & ~2, phy->pmu + REG_PMU_UNK_H3);
} else {
if (phy->index == 0)
sun4i_usb_phy_write(phy, PHY_RES45_CAL_EN, 0x01, 1);
sun4i_usb_phy_write(phy, PHY_TX_AMPLITUDE_TUNE, 0x14, 5);
sun4i_usb_phy_write(phy, PHY_DISCON_TH_SEL,
data->cfg->disc_thresh, 2);
}
sun4i_usb_phy_passby(phy, 1);
if (phy->index == 0) {
data->phy0_init = true;
sun4i_usb_phy0_update_iscr(_phy, 0, ISCR_DPDM_PULLUP_EN);
sun4i_usb_phy0_update_iscr(_phy, 0, ISCR_ID_PULLUP_EN);
if (data->id_det_gpio) {
data->id_det = -1;
data->vbus_det = -1;
queue_delayed_work(system_wq, &data->detect, 0);
} else {
sun4i_usb_phy0_set_id_detect(_phy, 0);
sun4i_usb_phy0_set_vbus_detect(_phy, 1);
}
}
return 0;
}
static int sun4i_usb_phy_exit(struct phy *_phy)
{
struct sun4i_usb_phy *phy = phy_get_drvdata(_phy);
struct sun4i_usb_phy_data *data = to_sun4i_usb_phy_data(phy);
if (phy->index == 0) {
sun4i_usb_phy0_update_iscr(_phy, ISCR_DPDM_PULLUP_EN, 0);
sun4i_usb_phy0_update_iscr(_phy, ISCR_ID_PULLUP_EN, 0);
data->phy0_init = false;
}
sun4i_usb_phy_passby(phy, 0);
reset_control_assert(phy->reset);
clk_disable_unprepare(phy->clk);
return 0;
}
static int sun4i_usb_phy0_get_vbus_det(struct sun4i_usb_phy_data *data)
{
if (data->vbus_det_gpio)
return gpiod_get_value_cansleep(data->vbus_det_gpio);
if (data->vbus_power_supply) {
union power_supply_propval val;
int r;
r = power_supply_get_property(data->vbus_power_supply,
POWER_SUPPLY_PROP_PRESENT, &val);
if (r == 0)
return val.intval;
}
return 1;
}
static bool sun4i_usb_phy0_have_vbus_det(struct sun4i_usb_phy_data *data)
{
return data->vbus_det_gpio || data->vbus_power_supply;
}
static int sun4i_usb_phy_power_on(struct phy *_phy)
{
struct sun4i_usb_phy *phy = phy_get_drvdata(_phy);
struct sun4i_usb_phy_data *data = to_sun4i_usb_phy_data(phy);
int ret;
if (!phy->vbus || phy->regulator_on)
return 0;
if (phy->index == 0 && sun4i_usb_phy0_have_vbus_det(data) &&
data->vbus_det)
return 0;
ret = regulator_enable(phy->vbus);
if (ret)
return ret;
phy->regulator_on = true;
if (phy->index == 0 && data->vbus_det_gpio && data->phy0_poll)
mod_delayed_work(system_wq, &data->detect, DEBOUNCE_TIME);
return 0;
}
static int sun4i_usb_phy_power_off(struct phy *_phy)
{
struct sun4i_usb_phy *phy = phy_get_drvdata(_phy);
struct sun4i_usb_phy_data *data = to_sun4i_usb_phy_data(phy);
if (!phy->vbus || !phy->regulator_on)
return 0;
regulator_disable(phy->vbus);
phy->regulator_on = false;
if (phy->index == 0 && data->vbus_det_gpio && !data->phy0_poll)
mod_delayed_work(system_wq, &data->detect, POLL_TIME);
return 0;
}
void sun4i_usb_phy_set_squelch_detect(struct phy *_phy, bool enabled)
{
struct sun4i_usb_phy *phy = phy_get_drvdata(_phy);
sun4i_usb_phy_write(phy, PHY_SQUELCH_DETECT, enabled ? 0 : 2, 2);
}
static void sun4i_usb_phy0_id_vbus_det_scan(struct work_struct *work)
{
struct sun4i_usb_phy_data *data =
container_of(work, struct sun4i_usb_phy_data, detect.work);
struct phy *phy0 = data->phys[0].phy;
int id_det, vbus_det, id_notify = 0, vbus_notify = 0;
id_det = gpiod_get_value_cansleep(data->id_det_gpio);
vbus_det = sun4i_usb_phy0_get_vbus_det(data);
mutex_lock(&phy0->mutex);
if (!data->phy0_init) {
mutex_unlock(&phy0->mutex);
return;
}
if (id_det != data->id_det) {
if (!sun4i_usb_phy0_have_vbus_det(data) && id_det == 0) {
sun4i_usb_phy0_set_vbus_detect(phy0, 0);
msleep(200);
sun4i_usb_phy0_set_vbus_detect(phy0, 1);
}
sun4i_usb_phy0_set_id_detect(phy0, id_det);
data->id_det = id_det;
id_notify = 1;
}
if (vbus_det != data->vbus_det) {
sun4i_usb_phy0_set_vbus_detect(phy0, vbus_det);
data->vbus_det = vbus_det;
vbus_notify = 1;
}
mutex_unlock(&phy0->mutex);
if (id_notify) {
extcon_set_cable_state_(data->extcon, EXTCON_USB_HOST,
!id_det);
if (!sun4i_usb_phy0_have_vbus_det(data) && id_det == 1) {
mutex_lock(&phy0->mutex);
sun4i_usb_phy0_set_vbus_detect(phy0, 0);
msleep(1000);
sun4i_usb_phy0_set_vbus_detect(phy0, 1);
mutex_unlock(&phy0->mutex);
}
}
if (vbus_notify)
extcon_set_cable_state_(data->extcon, EXTCON_USB, vbus_det);
if (data->phy0_poll)
queue_delayed_work(system_wq, &data->detect, POLL_TIME);
}
static irqreturn_t sun4i_usb_phy0_id_vbus_det_irq(int irq, void *dev_id)
{
struct sun4i_usb_phy_data *data = dev_id;
mod_delayed_work(system_wq, &data->detect, DEBOUNCE_TIME);
return IRQ_HANDLED;
}
static int sun4i_usb_phy0_vbus_notify(struct notifier_block *nb,
unsigned long val, void *v)
{
struct sun4i_usb_phy_data *data =
container_of(nb, struct sun4i_usb_phy_data, vbus_power_nb);
struct power_supply *psy = v;
if (val == PSY_EVENT_PROP_CHANGED && psy == data->vbus_power_supply)
mod_delayed_work(system_wq, &data->detect, DEBOUNCE_TIME);
return NOTIFY_OK;
}
static struct phy *sun4i_usb_phy_xlate(struct device *dev,
struct of_phandle_args *args)
{
struct sun4i_usb_phy_data *data = dev_get_drvdata(dev);
if (args->args[0] >= data->cfg->num_phys)
return ERR_PTR(-ENODEV);
return data->phys[args->args[0]].phy;
}
static int sun4i_usb_phy_remove(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct sun4i_usb_phy_data *data = dev_get_drvdata(dev);
if (data->vbus_power_nb_registered)
power_supply_unreg_notifier(&data->vbus_power_nb);
if (data->id_det_irq >= 0)
devm_free_irq(dev, data->id_det_irq, data);
if (data->vbus_det_irq >= 0)
devm_free_irq(dev, data->vbus_det_irq, data);
cancel_delayed_work_sync(&data->detect);
return 0;
}
static int sun4i_usb_phy_probe(struct platform_device *pdev)
{
struct sun4i_usb_phy_data *data;
struct device *dev = &pdev->dev;
struct device_node *np = dev->of_node;
struct phy_provider *phy_provider;
struct resource *res;
int i, ret;
data = devm_kzalloc(dev, sizeof(*data), GFP_KERNEL);
if (!data)
return -ENOMEM;
mutex_init(&data->mutex);
INIT_DELAYED_WORK(&data->detect, sun4i_usb_phy0_id_vbus_det_scan);
dev_set_drvdata(dev, data);
data->cfg = of_device_get_match_data(dev);
if (!data->cfg)
return -EINVAL;
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "phy_ctrl");
data->base = devm_ioremap_resource(dev, res);
if (IS_ERR(data->base))
return PTR_ERR(data->base);
data->id_det_gpio = devm_gpiod_get_optional(dev, "usb0_id_det",
GPIOD_IN);
if (IS_ERR(data->id_det_gpio))
return PTR_ERR(data->id_det_gpio);
data->vbus_det_gpio = devm_gpiod_get_optional(dev, "usb0_vbus_det",
GPIOD_IN);
if (IS_ERR(data->vbus_det_gpio))
return PTR_ERR(data->vbus_det_gpio);
if (of_find_property(np, "usb0_vbus_power-supply", NULL)) {
data->vbus_power_supply = devm_power_supply_get_by_phandle(dev,
"usb0_vbus_power-supply");
if (IS_ERR(data->vbus_power_supply))
return PTR_ERR(data->vbus_power_supply);
if (!data->vbus_power_supply)
return -EPROBE_DEFER;
}
if (sun4i_usb_phy0_have_vbus_det(data) && !data->id_det_gpio) {
dev_err(dev, "usb0_id_det missing or invalid\n");
return -ENODEV;
}
if (data->id_det_gpio) {
data->extcon = devm_extcon_dev_allocate(dev,
sun4i_usb_phy0_cable);
if (IS_ERR(data->extcon))
return PTR_ERR(data->extcon);
ret = devm_extcon_dev_register(dev, data->extcon);
if (ret) {
dev_err(dev, "failed to register extcon: %d\n", ret);
return ret;
}
}
for (i = 0; i < data->cfg->num_phys; i++) {
struct sun4i_usb_phy *phy = data->phys + i;
char name[16];
snprintf(name, sizeof(name), "usb%d_vbus", i);
phy->vbus = devm_regulator_get_optional(dev, name);
if (IS_ERR(phy->vbus)) {
if (PTR_ERR(phy->vbus) == -EPROBE_DEFER)
return -EPROBE_DEFER;
phy->vbus = NULL;
}
if (data->cfg->dedicated_clocks)
snprintf(name, sizeof(name), "usb%d_phy", i);
else
strlcpy(name, "usb_phy", sizeof(name));
phy->clk = devm_clk_get(dev, name);
if (IS_ERR(phy->clk)) {
dev_err(dev, "failed to get clock %s\n", name);
return PTR_ERR(phy->clk);
}
snprintf(name, sizeof(name), "usb%d_reset", i);
phy->reset = devm_reset_control_get(dev, name);
if (IS_ERR(phy->reset)) {
dev_err(dev, "failed to get reset %s\n", name);
return PTR_ERR(phy->reset);
}
if (i) {
snprintf(name, sizeof(name), "pmu%d", i);
res = platform_get_resource_byname(pdev,
IORESOURCE_MEM, name);
phy->pmu = devm_ioremap_resource(dev, res);
if (IS_ERR(phy->pmu))
return PTR_ERR(phy->pmu);
}
phy->phy = devm_phy_create(dev, NULL, &sun4i_usb_phy_ops);
if (IS_ERR(phy->phy)) {
dev_err(dev, "failed to create PHY %d\n", i);
return PTR_ERR(phy->phy);
}
phy->index = i;
phy_set_drvdata(phy->phy, &data->phys[i]);
}
data->id_det_irq = gpiod_to_irq(data->id_det_gpio);
data->vbus_det_irq = gpiod_to_irq(data->vbus_det_gpio);
if ((data->id_det_gpio && data->id_det_irq < 0) ||
(data->vbus_det_gpio && data->vbus_det_irq < 0))
data->phy0_poll = true;
if (data->id_det_irq >= 0) {
ret = devm_request_irq(dev, data->id_det_irq,
sun4i_usb_phy0_id_vbus_det_irq,
IRQF_TRIGGER_RISING | IRQF_TRIGGER_FALLING,
"usb0-id-det", data);
if (ret) {
dev_err(dev, "Err requesting id-det-irq: %d\n", ret);
return ret;
}
}
if (data->vbus_det_irq >= 0) {
ret = devm_request_irq(dev, data->vbus_det_irq,
sun4i_usb_phy0_id_vbus_det_irq,
IRQF_TRIGGER_RISING | IRQF_TRIGGER_FALLING,
"usb0-vbus-det", data);
if (ret) {
dev_err(dev, "Err requesting vbus-det-irq: %d\n", ret);
data->vbus_det_irq = -1;
sun4i_usb_phy_remove(pdev);
return ret;
}
}
if (data->vbus_power_supply) {
data->vbus_power_nb.notifier_call = sun4i_usb_phy0_vbus_notify;
data->vbus_power_nb.priority = 0;
ret = power_supply_reg_notifier(&data->vbus_power_nb);
if (ret) {
sun4i_usb_phy_remove(pdev);
return ret;
}
data->vbus_power_nb_registered = true;
}
phy_provider = devm_of_phy_provider_register(dev, sun4i_usb_phy_xlate);
if (IS_ERR(phy_provider)) {
sun4i_usb_phy_remove(pdev);
return PTR_ERR(phy_provider);
}
return 0;
}
