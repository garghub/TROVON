static void axp288_extcon_log_rsi(struct axp288_extcon_info *info)
{
char **rsi;
unsigned int val, i, clear_mask = 0;
int ret;
ret = regmap_read(info->regmap, AXP288_PS_BOOT_REASON_REG, &val);
for (i = 0, rsi = axp288_pwr_up_down_info; *rsi; rsi++, i++) {
if (val & BIT(i)) {
dev_dbg(info->dev, "%s\n", *rsi);
clear_mask |= BIT(i);
}
}
regmap_write(info->regmap, AXP288_PS_BOOT_REASON_REG, clear_mask);
}
static int axp288_handle_chrg_det_event(struct axp288_extcon_info *info)
{
static bool notify_otg, notify_charger;
static unsigned int cable;
int ret, stat, cfg, pwr_stat;
u8 chrg_type;
bool vbus_attach = false;
ret = regmap_read(info->regmap, AXP288_PS_STAT_REG, &pwr_stat);
if (ret < 0) {
dev_err(info->dev, "failed to read vbus status\n");
return ret;
}
vbus_attach = (pwr_stat & PS_STAT_VBUS_PRESENT);
if (!vbus_attach)
goto notify_otg;
ret = regmap_read(info->regmap, AXP288_BC_GLOBAL_REG, &cfg);
if (ret < 0)
goto dev_det_ret;
if (cfg & BC_GLOBAL_DET_STAT) {
dev_dbg(info->dev, "can't complete the charger detection\n");
goto dev_det_ret;
}
ret = regmap_read(info->regmap, AXP288_BC_DET_STAT_REG, &stat);
if (ret < 0)
goto dev_det_ret;
chrg_type = (stat & DET_STAT_MASK) >> DET_STAT_SHIFT;
switch (chrg_type) {
case DET_STAT_SDP:
dev_dbg(info->dev, "sdp cable is connecetd\n");
notify_otg = true;
notify_charger = true;
cable = EXTCON_CHG_USB_SDP;
break;
case DET_STAT_CDP:
dev_dbg(info->dev, "cdp cable is connecetd\n");
notify_otg = true;
notify_charger = true;
cable = EXTCON_CHG_USB_CDP;
break;
case DET_STAT_DCP:
dev_dbg(info->dev, "dcp cable is connecetd\n");
notify_charger = true;
cable = EXTCON_CHG_USB_DCP;
break;
default:
dev_warn(info->dev,
"disconnect or unknown or ID event\n");
}
notify_otg:
if (notify_otg) {
if (info->pdata->gpio_mux_cntl)
gpiod_set_value(info->pdata->gpio_mux_cntl,
vbus_attach ? EXTCON_GPIO_MUX_SEL_SOC
: EXTCON_GPIO_MUX_SEL_PMIC);
atomic_notifier_call_chain(&info->otg->notifier,
vbus_attach ? USB_EVENT_VBUS : USB_EVENT_NONE, NULL);
}
if (notify_charger)
extcon_set_cable_state_(info->edev, cable, vbus_attach);
if (!vbus_attach)
notify_otg = notify_charger = false;
return 0;
dev_det_ret:
if (ret < 0)
dev_err(info->dev, "failed to detect BC Mod\n");
return ret;
}
static irqreturn_t axp288_extcon_isr(int irq, void *data)
{
struct axp288_extcon_info *info = data;
int ret;
ret = axp288_handle_chrg_det_event(info);
if (ret < 0)
dev_err(info->dev, "failed to handle the interrupt\n");
return IRQ_HANDLED;
}
static void axp288_extcon_enable_irq(struct axp288_extcon_info *info)
{
regmap_write(info->regmap, AXP288_PWRSRC_IRQ_CFG_REG,
PWRSRC_IRQ_CFG_MASK);
regmap_update_bits(info->regmap, AXP288_BC_GLOBAL_REG,
BC_GLOBAL_RUN, 0);
regmap_write(info->regmap, AXP288_BC12_IRQ_CFG_REG, BC12_IRQ_CFG_MASK);
regmap_update_bits(info->regmap, AXP288_BC_GLOBAL_REG,
BC_GLOBAL_RUN, BC_GLOBAL_RUN);
}
static int axp288_extcon_probe(struct platform_device *pdev)
{
struct axp288_extcon_info *info;
struct axp20x_dev *axp20x = dev_get_drvdata(pdev->dev.parent);
int ret, i, pirq, gpio;
info = devm_kzalloc(&pdev->dev, sizeof(*info), GFP_KERNEL);
if (!info)
return -ENOMEM;
info->dev = &pdev->dev;
info->regmap = axp20x->regmap;
info->regmap_irqc = axp20x->regmap_irqc;
info->pdata = pdev->dev.platform_data;
if (!info->pdata) {
if (!device_property_present(&pdev->dev,
"axp288_extcon_data\n"))
dev_err(&pdev->dev, "failed to get platform data\n");
return -ENODEV;
}
platform_set_drvdata(pdev, info);
axp288_extcon_log_rsi(info);
info->edev = devm_extcon_dev_allocate(&pdev->dev,
axp288_extcon_cables);
if (IS_ERR(info->edev)) {
dev_err(&pdev->dev, "failed to allocate memory for extcon\n");
return PTR_ERR(info->edev);
}
ret = devm_extcon_dev_register(&pdev->dev, info->edev);
if (ret) {
dev_err(&pdev->dev, "failed to register extcon device\n");
return ret;
}
info->otg = devm_usb_get_phy(&pdev->dev, USB_PHY_TYPE_USB2);
if (IS_ERR(info->otg)) {
dev_err(&pdev->dev, "failed to get otg transceiver\n");
return PTR_ERR(info->otg);
}
if (info->pdata->gpio_mux_cntl) {
gpio = desc_to_gpio(info->pdata->gpio_mux_cntl);
ret = devm_gpio_request(&pdev->dev, gpio, "USB_MUX");
if (ret < 0) {
dev_err(&pdev->dev,
"failed to request the gpio=%d\n", gpio);
return ret;
}
gpiod_direction_output(info->pdata->gpio_mux_cntl,
EXTCON_GPIO_MUX_SEL_PMIC);
}
for (i = 0; i < EXTCON_IRQ_END; i++) {
pirq = platform_get_irq(pdev, i);
info->irq[i] = regmap_irq_get_virq(info->regmap_irqc, pirq);
if (info->irq[i] < 0) {
dev_err(&pdev->dev,
"failed to get virtual interrupt=%d\n", pirq);
ret = info->irq[i];
return ret;
}
ret = devm_request_threaded_irq(&pdev->dev, info->irq[i],
NULL, axp288_extcon_isr,
IRQF_ONESHOT | IRQF_NO_SUSPEND,
pdev->name, info);
if (ret) {
dev_err(&pdev->dev, "failed to request interrupt=%d\n",
info->irq[i]);
return ret;
}
}
axp288_extcon_enable_irq(info);
return 0;
}
