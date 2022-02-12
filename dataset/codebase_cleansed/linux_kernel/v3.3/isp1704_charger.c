static void isp1704_charger_set_power(struct isp1704_charger *isp, bool on)
{
struct isp1704_charger_data *board = isp->dev->platform_data;
if (board && board->set_power)
board->set_power(on);
}
static inline int isp1704_charger_type(struct isp1704_charger *isp)
{
u8 reg;
u8 func_ctrl;
u8 otg_ctrl;
int type = POWER_SUPPLY_TYPE_USB_DCP;
func_ctrl = otg_io_read(isp->otg, ULPI_FUNC_CTRL);
otg_ctrl = otg_io_read(isp->otg, ULPI_OTG_CTRL);
reg = ULPI_OTG_CTRL_DM_PULLDOWN | ULPI_OTG_CTRL_DP_PULLDOWN;
otg_io_write(isp->otg, ULPI_CLR(ULPI_OTG_CTRL), reg);
otg_io_write(isp->otg, ULPI_CLR(ULPI_FUNC_CTRL),
ULPI_FUNC_CTRL_XCVRSEL_MASK);
otg_io_write(isp->otg, ULPI_SET(ULPI_FUNC_CTRL),
ULPI_FUNC_CTRL_FULL_SPEED);
reg = ULPI_FUNC_CTRL_TERMSELECT | ULPI_FUNC_CTRL_RESET;
otg_io_write(isp->otg, ULPI_SET(ULPI_FUNC_CTRL), reg);
usleep_range(1000, 2000);
reg = otg_io_read(isp->otg, ULPI_DEBUG);
if ((reg & 3) != 3)
type = POWER_SUPPLY_TYPE_USB_CDP;
otg_io_write(isp->otg, ULPI_FUNC_CTRL, func_ctrl);
otg_io_write(isp->otg, ULPI_OTG_CTRL, otg_ctrl);
return type;
}
static inline int isp1704_charger_verify(struct isp1704_charger *isp)
{
int ret = 0;
u8 r;
r = otg_io_read(isp->otg, ULPI_FUNC_CTRL);
r |= ULPI_FUNC_CTRL_RESET;
otg_io_write(isp->otg, ULPI_FUNC_CTRL, r);
usleep_range(1000, 2000);
r &= ~(ULPI_FUNC_CTRL_RESET | ULPI_FUNC_CTRL_OPMODE_MASK);
otg_io_write(isp->otg, ULPI_FUNC_CTRL, r);
r = ULPI_OTG_CTRL_DP_PULLDOWN | ULPI_OTG_CTRL_DM_PULLDOWN;
otg_io_write(isp->otg, ULPI_CLR(ULPI_OTG_CTRL), r);
r = ULPI_FUNC_CTRL_TERMSELECT | ULPI_FUNC_CTRL_RESET;
otg_io_write(isp->otg, ULPI_SET(ULPI_FUNC_CTRL), r);
usleep_range(1000, 2000);
if (!otg_io_read(isp->otg, ULPI_DEBUG)) {
otg_io_write(isp->otg, ULPI_CLR(ULPI_FUNC_CTRL),
ULPI_FUNC_CTRL_TERMSELECT);
return 1;
}
otg_io_write(isp->otg, ULPI_SET(ISP1704_PWR_CTRL),
ISP1704_PWR_CTRL_DP_WKPU_EN);
otg_io_write(isp->otg, ULPI_CLR(ULPI_FUNC_CTRL),
ULPI_FUNC_CTRL_TERMSELECT);
otg_io_write(isp->otg, ULPI_SET(ULPI_OTG_CTRL),
ULPI_OTG_CTRL_DM_PULLDOWN);
if (!(otg_io_read(isp->otg, ULPI_DEBUG)))
ret = 1;
otg_io_write(isp->otg, ULPI_CLR(ISP1704_PWR_CTRL),
ISP1704_PWR_CTRL_DP_WKPU_EN);
return ret;
}
static inline int isp1704_charger_detect(struct isp1704_charger *isp)
{
unsigned long timeout;
u8 pwr_ctrl;
int ret = 0;
pwr_ctrl = otg_io_read(isp->otg, ISP1704_PWR_CTRL);
otg_io_write(isp->otg, ISP1704_PWR_CTRL,
ISP1704_PWR_CTRL_SWCTRL);
otg_io_write(isp->otg, ULPI_SET(ISP1704_PWR_CTRL),
ISP1704_PWR_CTRL_SWCTRL
| ISP1704_PWR_CTRL_DPVSRC_EN);
usleep_range(1000, 2000);
timeout = jiffies + msecs_to_jiffies(300);
do {
if (otg_io_read(isp->otg, ISP1704_PWR_CTRL)
& ISP1704_PWR_CTRL_VDAT_DET) {
ret = isp1704_charger_verify(isp);
break;
}
} while (!time_after(jiffies, timeout) && isp->online);
otg_io_write(isp->otg, ISP1704_PWR_CTRL, pwr_ctrl);
return ret;
}
static void isp1704_charger_work(struct work_struct *data)
{
int detect;
unsigned long event;
unsigned power;
struct isp1704_charger *isp =
container_of(data, struct isp1704_charger, work);
static DEFINE_MUTEX(lock);
event = isp->event;
power = isp->max_power;
mutex_lock(&lock);
if (event != USB_EVENT_NONE)
isp1704_charger_set_power(isp, 1);
switch (event) {
case USB_EVENT_VBUS:
isp->online = true;
detect = isp1704_charger_detect(isp);
if (detect) {
isp->present = detect;
isp->psy.type = isp1704_charger_type(isp);
}
switch (isp->psy.type) {
case POWER_SUPPLY_TYPE_USB_DCP:
isp->current_max = 1800;
break;
case POWER_SUPPLY_TYPE_USB_CDP:
isp->current_max = 500;
case POWER_SUPPLY_TYPE_USB:
default:
if (isp->otg->gadget)
usb_gadget_connect(isp->otg->gadget);
}
break;
case USB_EVENT_NONE:
isp->online = false;
isp->current_max = 0;
isp->present = 0;
isp->current_max = 0;
isp->psy.type = POWER_SUPPLY_TYPE_USB;
if (isp->otg->gadget)
usb_gadget_disconnect(isp->otg->gadget);
isp1704_charger_set_power(isp, 0);
break;
case USB_EVENT_ENUMERATED:
if (isp->present)
isp->current_max = 1800;
else
isp->current_max = power;
break;
default:
goto out;
}
power_supply_changed(&isp->psy);
out:
mutex_unlock(&lock);
}
static int isp1704_notifier_call(struct notifier_block *nb,
unsigned long event, void *power)
{
struct isp1704_charger *isp =
container_of(nb, struct isp1704_charger, nb);
isp->event = event;
if (power)
isp->max_power = *((unsigned *)power);
schedule_work(&isp->work);
return NOTIFY_OK;
}
static int isp1704_charger_get_property(struct power_supply *psy,
enum power_supply_property psp,
union power_supply_propval *val)
{
struct isp1704_charger *isp =
container_of(psy, struct isp1704_charger, psy);
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
ret = otg_io_write(isp->otg, ULPI_SCRATCH, 0xaa);
if (ret < 0)
return ret;
ret = otg_io_read(isp->otg, ULPI_SCRATCH);
if (ret < 0)
return ret;
if (ret != 0xaa)
return -ENODEV;
vendor = otg_io_read(isp->otg, ULPI_VENDOR_ID_LOW);
vendor |= otg_io_read(isp->otg, ULPI_VENDOR_ID_HIGH) << 8;
if (vendor != NXP_VENDOR_ID)
return -ENODEV;
product = otg_io_read(isp->otg, ULPI_PRODUCT_ID_LOW);
product |= otg_io_read(isp->otg, ULPI_PRODUCT_ID_HIGH) << 8;
for (i = 0; i < ARRAY_SIZE(isp170x_id); i++) {
if (product == isp170x_id[i]) {
sprintf(isp->model, "isp%x", product);
return product;
}
}
dev_err(isp->dev, "product id %x not matching known ids", product);
return -ENODEV;
}
static int __devinit isp1704_charger_probe(struct platform_device *pdev)
{
struct isp1704_charger *isp;
int ret = -ENODEV;
isp = kzalloc(sizeof *isp, GFP_KERNEL);
if (!isp)
return -ENOMEM;
isp->otg = otg_get_transceiver();
if (!isp->otg)
goto fail0;
isp->dev = &pdev->dev;
platform_set_drvdata(pdev, isp);
isp1704_charger_set_power(isp, 1);
ret = isp1704_test_ulpi(isp);
if (ret < 0)
goto fail1;
isp->psy.name = "isp1704";
isp->psy.type = POWER_SUPPLY_TYPE_USB;
isp->psy.properties = power_props;
isp->psy.num_properties = ARRAY_SIZE(power_props);
isp->psy.get_property = isp1704_charger_get_property;
ret = power_supply_register(isp->dev, &isp->psy);
if (ret)
goto fail1;
INIT_WORK(&isp->work, isp1704_charger_work);
isp->nb.notifier_call = isp1704_notifier_call;
ret = otg_register_notifier(isp->otg, &isp->nb);
if (ret)
goto fail2;
dev_info(isp->dev, "registered with product id %s\n", isp->model);
if (isp->otg->gadget)
usb_gadget_disconnect(isp->otg->gadget);
ret = otg_io_read(isp->otg, ULPI_USB_INT_STS);
isp1704_charger_set_power(isp, 0);
if ((ret & ULPI_INT_VBUS_VALID) && !isp->otg->default_a) {
isp->event = USB_EVENT_VBUS;
schedule_work(&isp->work);
}
return 0;
fail2:
power_supply_unregister(&isp->psy);
fail1:
otg_put_transceiver(isp->otg);
fail0:
kfree(isp);
dev_err(&pdev->dev, "failed to register isp1704 with error %d\n", ret);
return ret;
}
static int __devexit isp1704_charger_remove(struct platform_device *pdev)
{
struct isp1704_charger *isp = platform_get_drvdata(pdev);
otg_unregister_notifier(isp->otg, &isp->nb);
power_supply_unregister(&isp->psy);
otg_put_transceiver(isp->otg);
isp1704_charger_set_power(isp, 0);
kfree(isp);
return 0;
}
