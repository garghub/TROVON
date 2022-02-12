static inline int isp1704_read(struct isp1704_charger *isp, u32 reg)
{
return usb_phy_io_read(isp->phy, reg);
}
static inline int isp1704_write(struct isp1704_charger *isp, u32 reg, u32 val)
{
return usb_phy_io_write(isp->phy, val, reg);
}
static void isp1704_charger_set_power(struct isp1704_charger *isp, bool on)
{
struct isp1704_charger_data *board = isp->dev->platform_data;
if (board && board->set_power)
board->set_power(on);
else if (board)
gpio_set_value(board->enable_gpio, on);
}
static inline int isp1704_charger_type(struct isp1704_charger *isp)
{
u8 reg;
u8 func_ctrl;
u8 otg_ctrl;
int type = POWER_SUPPLY_TYPE_USB_DCP;
func_ctrl = isp1704_read(isp, ULPI_FUNC_CTRL);
otg_ctrl = isp1704_read(isp, ULPI_OTG_CTRL);
reg = ULPI_OTG_CTRL_DM_PULLDOWN | ULPI_OTG_CTRL_DP_PULLDOWN;
isp1704_write(isp, ULPI_CLR(ULPI_OTG_CTRL), reg);
isp1704_write(isp, ULPI_CLR(ULPI_FUNC_CTRL),
ULPI_FUNC_CTRL_XCVRSEL_MASK);
isp1704_write(isp, ULPI_SET(ULPI_FUNC_CTRL),
ULPI_FUNC_CTRL_FULL_SPEED);
reg = ULPI_FUNC_CTRL_TERMSELECT | ULPI_FUNC_CTRL_RESET;
isp1704_write(isp, ULPI_SET(ULPI_FUNC_CTRL), reg);
usleep_range(1000, 2000);
reg = isp1704_read(isp, ULPI_DEBUG);
if ((reg & 3) != 3)
type = POWER_SUPPLY_TYPE_USB_CDP;
isp1704_write(isp, ULPI_FUNC_CTRL, func_ctrl);
isp1704_write(isp, ULPI_OTG_CTRL, otg_ctrl);
return type;
}
static inline int isp1704_charger_verify(struct isp1704_charger *isp)
{
int ret = 0;
u8 r;
r = isp1704_read(isp, ULPI_FUNC_CTRL);
r |= ULPI_FUNC_CTRL_RESET;
isp1704_write(isp, ULPI_FUNC_CTRL, r);
usleep_range(1000, 2000);
r &= ~(ULPI_FUNC_CTRL_RESET | ULPI_FUNC_CTRL_OPMODE_MASK);
isp1704_write(isp, ULPI_FUNC_CTRL, r);
r = ULPI_OTG_CTRL_DP_PULLDOWN | ULPI_OTG_CTRL_DM_PULLDOWN;
isp1704_write(isp, ULPI_CLR(ULPI_OTG_CTRL), r);
r = ULPI_FUNC_CTRL_TERMSELECT | ULPI_FUNC_CTRL_RESET;
isp1704_write(isp, ULPI_SET(ULPI_FUNC_CTRL), r);
usleep_range(1000, 2000);
if (!isp1704_read(isp, ULPI_DEBUG)) {
isp1704_write(isp, ULPI_CLR(ULPI_FUNC_CTRL),
ULPI_FUNC_CTRL_TERMSELECT);
return 1;
}
isp1704_write(isp, ULPI_SET(ISP1704_PWR_CTRL),
ISP1704_PWR_CTRL_DP_WKPU_EN);
isp1704_write(isp, ULPI_CLR(ULPI_FUNC_CTRL),
ULPI_FUNC_CTRL_TERMSELECT);
isp1704_write(isp, ULPI_SET(ULPI_OTG_CTRL),
ULPI_OTG_CTRL_DM_PULLDOWN);
if (!(isp1704_read(isp, ULPI_DEBUG)))
ret = 1;
isp1704_write(isp, ULPI_CLR(ISP1704_PWR_CTRL),
ISP1704_PWR_CTRL_DP_WKPU_EN);
return ret;
}
static inline int isp1704_charger_detect(struct isp1704_charger *isp)
{
unsigned long timeout;
u8 pwr_ctrl;
int ret = 0;
pwr_ctrl = isp1704_read(isp, ISP1704_PWR_CTRL);
isp1704_write(isp, ISP1704_PWR_CTRL,
ISP1704_PWR_CTRL_SWCTRL);
isp1704_write(isp, ULPI_SET(ISP1704_PWR_CTRL),
ISP1704_PWR_CTRL_SWCTRL
| ISP1704_PWR_CTRL_DPVSRC_EN);
usleep_range(1000, 2000);
timeout = jiffies + msecs_to_jiffies(300);
do {
if (isp1704_read(isp, ISP1704_PWR_CTRL)
& ISP1704_PWR_CTRL_VDAT_DET) {
ret = isp1704_charger_verify(isp);
break;
}
} while (!time_after(jiffies, timeout) && isp->online);
isp1704_write(isp, ISP1704_PWR_CTRL, pwr_ctrl);
return ret;
}
static inline int isp1704_charger_detect_dcp(struct isp1704_charger *isp)
{
if (isp1704_charger_detect(isp) &&
isp1704_charger_type(isp) == POWER_SUPPLY_TYPE_USB_DCP)
return true;
else
return false;
}
static void isp1704_charger_work(struct work_struct *data)
{
struct isp1704_charger *isp =
container_of(data, struct isp1704_charger, work);
static DEFINE_MUTEX(lock);
mutex_lock(&lock);
switch (isp->phy->last_event) {
case USB_EVENT_VBUS:
if (!isp->present) {
isp->online = true;
isp->present = 1;
isp1704_charger_set_power(isp, 1);
if (isp1704_charger_detect_dcp(isp)) {
isp->psy_desc.type = POWER_SUPPLY_TYPE_USB_DCP;
isp->current_max = 1800;
} else {
isp->psy_desc.type = POWER_SUPPLY_TYPE_USB;
isp->current_max = 500;
}
if (isp->phy->otg->gadget)
usb_gadget_connect(isp->phy->otg->gadget);
}
if (isp->psy_desc.type != POWER_SUPPLY_TYPE_USB_DCP) {
if (isp->current_max > 500)
isp->current_max = 500;
if (isp->current_max > 100)
isp->psy_desc.type = POWER_SUPPLY_TYPE_USB_CDP;
}
break;
case USB_EVENT_NONE:
isp->online = false;
isp->present = 0;
isp->current_max = 0;
isp->psy_desc.type = POWER_SUPPLY_TYPE_USB;
if (isp->phy->otg->gadget)
usb_gadget_disconnect(isp->phy->otg->gadget);
isp1704_charger_set_power(isp, 0);
break;
default:
goto out;
}
power_supply_changed(isp->psy);
out:
mutex_unlock(&lock);
}
static int isp1704_notifier_call(struct notifier_block *nb,
unsigned long val, void *v)
{
struct isp1704_charger *isp =
container_of(nb, struct isp1704_charger, nb);
schedule_work(&isp->work);
return NOTIFY_OK;
}
static int isp1704_charger_get_property(struct power_supply *psy,
enum power_supply_property psp,
union power_supply_propval *val)
{
struct isp1704_charger *isp = power_supply_get_drvdata(psy);
switch (psp) {
case POWER_SUPPLY_PROP_PRESENT:
val->intval = isp->present;
break;
case POWER_SUPPLY_PROP_ONLINE:
val->intval = isp->online;
break;
case POWER_SUPPLY_PROP_CURRENT_MAX:
val->intval = isp->current_max;
break;
case POWER_SUPPLY_PROP_MODEL_NAME:
val->strval = isp->model;
break;
case POWER_SUPPLY_PROP_MANUFACTURER:
val->strval = "NXP";
break;
default:
return -EINVAL;
}
return 0;
}
static inline int isp1704_test_ulpi(struct isp1704_charger *isp)
{
int vendor;
int product;
int i;
int ret = -ENODEV;
ret = isp1704_write(isp, ULPI_SCRATCH, 0xaa);
if (ret < 0)
return ret;
ret = isp1704_read(isp, ULPI_SCRATCH);
if (ret < 0)
return ret;
if (ret != 0xaa)
return -ENODEV;
vendor = isp1704_read(isp, ULPI_VENDOR_ID_LOW);
vendor |= isp1704_read(isp, ULPI_VENDOR_ID_HIGH) << 8;
if (vendor != NXP_VENDOR_ID)
return -ENODEV;
product = isp1704_read(isp, ULPI_PRODUCT_ID_LOW);
product |= isp1704_read(isp, ULPI_PRODUCT_ID_HIGH) << 8;
for (i = 0; i < ARRAY_SIZE(isp170x_id); i++) {
if (product == isp170x_id[i]) {
sprintf(isp->model, "isp%x", product);
return product;
}
}
dev_err(isp->dev, "product id %x not matching known ids", product);
return -ENODEV;
}
static int isp1704_charger_probe(struct platform_device *pdev)
{
struct isp1704_charger *isp;
int ret = -ENODEV;
struct power_supply_config psy_cfg = {};
struct isp1704_charger_data *pdata = dev_get_platdata(&pdev->dev);
struct device_node *np = pdev->dev.of_node;
if (np) {
int gpio = of_get_named_gpio(np, "nxp,enable-gpio", 0);
if (gpio < 0) {
dev_err(&pdev->dev, "missing DT GPIO nxp,enable-gpio\n");
return gpio;
}
pdata = devm_kzalloc(&pdev->dev,
sizeof(struct isp1704_charger_data), GFP_KERNEL);
pdata->enable_gpio = gpio;
dev_info(&pdev->dev, "init gpio %d\n", pdata->enable_gpio);
ret = devm_gpio_request_one(&pdev->dev, pdata->enable_gpio,
GPIOF_OUT_INIT_HIGH, "isp1704_reset");
if (ret) {
dev_err(&pdev->dev, "gpio request failed\n");
goto fail0;
}
}
if (!pdata) {
dev_err(&pdev->dev, "missing platform data!\n");
return -ENODEV;
}
isp = devm_kzalloc(&pdev->dev, sizeof(*isp), GFP_KERNEL);
if (!isp)
return -ENOMEM;
if (np)
isp->phy = devm_usb_get_phy_by_phandle(&pdev->dev, "usb-phy", 0);
else
isp->phy = devm_usb_get_phy(&pdev->dev, USB_PHY_TYPE_USB2);
if (IS_ERR(isp->phy)) {
ret = PTR_ERR(isp->phy);
dev_err(&pdev->dev, "usb_get_phy failed\n");
goto fail0;
}
isp->dev = &pdev->dev;
platform_set_drvdata(pdev, isp);
isp1704_charger_set_power(isp, 1);
ret = isp1704_test_ulpi(isp);
if (ret < 0) {
dev_err(&pdev->dev, "isp1704_test_ulpi failed\n");
goto fail1;
}
isp->psy_desc.name = "isp1704";
isp->psy_desc.type = POWER_SUPPLY_TYPE_USB;
isp->psy_desc.properties = power_props;
isp->psy_desc.num_properties = ARRAY_SIZE(power_props);
isp->psy_desc.get_property = isp1704_charger_get_property;
psy_cfg.drv_data = isp;
isp->psy = power_supply_register(isp->dev, &isp->psy_desc, &psy_cfg);
if (IS_ERR(isp->psy)) {
ret = PTR_ERR(isp->psy);
dev_err(&pdev->dev, "power_supply_register failed\n");
goto fail1;
}
INIT_WORK(&isp->work, isp1704_charger_work);
isp->nb.notifier_call = isp1704_notifier_call;
ret = usb_register_notifier(isp->phy, &isp->nb);
if (ret) {
dev_err(&pdev->dev, "usb_register_notifier failed\n");
goto fail2;
}
dev_info(isp->dev, "registered with product id %s\n", isp->model);
if (isp->phy->otg->gadget)
usb_gadget_disconnect(isp->phy->otg->gadget);
if (isp->phy->last_event == USB_EVENT_NONE)
isp1704_charger_set_power(isp, 0);
if (isp->phy->last_event == USB_EVENT_VBUS &&
!isp->phy->otg->default_a)
schedule_work(&isp->work);
return 0;
fail2:
power_supply_unregister(isp->psy);
fail1:
isp1704_charger_set_power(isp, 0);
fail0:
dev_err(&pdev->dev, "failed to register isp1704 with error %d\n", ret);
return ret;
}
static int isp1704_charger_remove(struct platform_device *pdev)
{
struct isp1704_charger *isp = platform_get_drvdata(pdev);
usb_unregister_notifier(isp->phy, &isp->nb);
power_supply_unregister(isp->psy);
isp1704_charger_set_power(isp, 0);
return 0;
}
