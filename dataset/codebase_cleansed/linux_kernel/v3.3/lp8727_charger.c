static int lp8727_i2c_read(struct lp8727_chg *pchg, u8 reg, u8 *data, u8 len)
{
s32 ret;
mutex_lock(&pchg->xfer_lock);
ret = i2c_smbus_read_i2c_block_data(pchg->client, reg, len, data);
mutex_unlock(&pchg->xfer_lock);
return (ret != len) ? -EIO : 0;
}
static int lp8727_i2c_write(struct lp8727_chg *pchg, u8 reg, u8 *data, u8 len)
{
s32 ret;
mutex_lock(&pchg->xfer_lock);
ret = i2c_smbus_write_i2c_block_data(pchg->client, reg, len, data);
mutex_unlock(&pchg->xfer_lock);
return ret;
}
static inline int lp8727_i2c_read_byte(struct lp8727_chg *pchg, u8 reg,
u8 *data)
{
return lp8727_i2c_read(pchg, reg, data, 1);
}
static inline int lp8727_i2c_write_byte(struct lp8727_chg *pchg, u8 reg,
u8 *data)
{
return lp8727_i2c_write(pchg, reg, data, 1);
}
static int lp8727_is_charger_attached(const char *name, int id)
{
if (name) {
if (!strcmp(name, "ac"))
return (id == ID_TA || id == ID_DEDICATED_CHG) ? 1 : 0;
else if (!strcmp(name, "usb"))
return (id == ID_USB_CHG) ? 1 : 0;
}
return (id >= ID_TA && id <= ID_USB_CHG) ? 1 : 0;
}
static void lp8727_init_device(struct lp8727_chg *pchg)
{
u8 val;
val = ID200_EN | ADC_EN | CP_EN;
if (lp8727_i2c_write_byte(pchg, CTRL1, &val))
dev_err(pchg->dev, "i2c write err : addr=0x%.2x\n", CTRL1);
val = INT_EN | CHGDET_EN;
if (lp8727_i2c_write_byte(pchg, CTRL2, &val))
dev_err(pchg->dev, "i2c write err : addr=0x%.2x\n", CTRL2);
}
static int lp8727_is_dedicated_charger(struct lp8727_chg *pchg)
{
u8 val;
lp8727_i2c_read_byte(pchg, STATUS1, &val);
return (val & DCPORT);
}
static int lp8727_is_usb_charger(struct lp8727_chg *pchg)
{
u8 val;
lp8727_i2c_read_byte(pchg, STATUS1, &val);
return (val & CHPORT);
}
static void lp8727_ctrl_switch(struct lp8727_chg *pchg, u8 sw)
{
u8 val = sw;
lp8727_i2c_write_byte(pchg, SWCTRL, &val);
}
static void lp8727_id_detection(struct lp8727_chg *pchg, u8 id, int vbusin)
{
u8 devid = ID_NONE;
u8 swctrl = SW_DM1_HiZ | SW_DP2_HiZ;
switch (id) {
case 0x5:
devid = ID_TA;
pchg->chg_parm = &pchg->pdata->ac;
break;
case 0xB:
if (lp8727_is_dedicated_charger(pchg)) {
pchg->chg_parm = &pchg->pdata->ac;
devid = ID_DEDICATED_CHG;
} else if (lp8727_is_usb_charger(pchg)) {
pchg->chg_parm = &pchg->pdata->usb;
devid = ID_USB_CHG;
swctrl = SW_DM1_DM | SW_DP2_DP;
} else if (vbusin) {
devid = ID_USB_DS;
swctrl = SW_DM1_DM | SW_DP2_DP;
}
break;
default:
devid = ID_NONE;
pchg->chg_parm = NULL;
break;
}
pchg->devid = devid;
lp8727_ctrl_switch(pchg, swctrl);
}
static void lp8727_enable_chgdet(struct lp8727_chg *pchg)
{
u8 val;
lp8727_i2c_read_byte(pchg, CTRL2, &val);
val |= CHGDET_EN;
lp8727_i2c_write_byte(pchg, CTRL2, &val);
}
static void lp8727_delayed_func(struct work_struct *_work)
{
u8 intstat[2], idno, vbus;
struct lp8727_chg *pchg =
container_of(_work, struct lp8727_chg, work.work);
if (lp8727_i2c_read(pchg, INT1, intstat, 2)) {
dev_err(pchg->dev, "can not read INT registers\n");
return;
}
idno = intstat[0] & IDNO;
vbus = intstat[0] & VBUS;
lp8727_id_detection(pchg, idno, vbus);
lp8727_enable_chgdet(pchg);
power_supply_changed(&pchg->psy->ac);
power_supply_changed(&pchg->psy->usb);
power_supply_changed(&pchg->psy->batt);
}
static irqreturn_t lp8727_isr_func(int irq, void *ptr)
{
struct lp8727_chg *pchg = ptr;
unsigned long delay = msecs_to_jiffies(DEBOUNCE_MSEC);
queue_delayed_work(pchg->irqthread, &pchg->work, delay);
return IRQ_HANDLED;
}
static void lp8727_intr_config(struct lp8727_chg *pchg)
{
INIT_DELAYED_WORK(&pchg->work, lp8727_delayed_func);
pchg->irqthread = create_singlethread_workqueue("lp8727-irqthd");
if (!pchg->irqthread)
dev_err(pchg->dev, "can not create thread for lp8727\n");
if (request_threaded_irq(pchg->client->irq,
NULL,
lp8727_isr_func,
IRQF_TRIGGER_FALLING, "lp8727_irq", pchg)) {
dev_err(pchg->dev, "lp8727 irq can not be registered\n");
}
}
static int lp8727_charger_get_property(struct power_supply *psy,
enum power_supply_property psp,
union power_supply_propval *val)
{
struct lp8727_chg *pchg = dev_get_drvdata(psy->dev->parent);
if (psp == POWER_SUPPLY_PROP_ONLINE)
val->intval = lp8727_is_charger_attached(psy->name,
pchg->devid);
return 0;
}
static int lp8727_battery_get_property(struct power_supply *psy,
enum power_supply_property psp,
union power_supply_propval *val)
{
struct lp8727_chg *pchg = dev_get_drvdata(psy->dev->parent);
u8 read;
switch (psp) {
case POWER_SUPPLY_PROP_STATUS:
if (lp8727_is_charger_attached(psy->name, pchg->devid)) {
lp8727_i2c_read_byte(pchg, STATUS1, &read);
if (((read & CHGSTAT) >> 4) == EOC)
val->intval = POWER_SUPPLY_STATUS_FULL;
else
val->intval = POWER_SUPPLY_STATUS_CHARGING;
} else {
val->intval = POWER_SUPPLY_STATUS_DISCHARGING;
}
break;
case POWER_SUPPLY_PROP_HEALTH:
lp8727_i2c_read_byte(pchg, STATUS2, &read);
read = (read & TEMP_STAT) >> 5;
if (read >= 0x1 && read <= 0x3)
val->intval = POWER_SUPPLY_HEALTH_OVERHEAT;
else
val->intval = POWER_SUPPLY_HEALTH_GOOD;
break;
case POWER_SUPPLY_PROP_PRESENT:
if (pchg->pdata->get_batt_present)
val->intval = pchg->pdata->get_batt_present();
break;
case POWER_SUPPLY_PROP_VOLTAGE_NOW:
if (pchg->pdata->get_batt_level)
val->intval = pchg->pdata->get_batt_level();
break;
case POWER_SUPPLY_PROP_CAPACITY:
if (pchg->pdata->get_batt_capacity)
val->intval = pchg->pdata->get_batt_capacity();
break;
case POWER_SUPPLY_PROP_TEMP:
if (pchg->pdata->get_batt_temp)
val->intval = pchg->pdata->get_batt_temp();
break;
default:
break;
}
return 0;
}
static void lp8727_charger_changed(struct power_supply *psy)
{
struct lp8727_chg *pchg = dev_get_drvdata(psy->dev->parent);
u8 val;
u8 eoc_level, ichg;
if (lp8727_is_charger_attached(psy->name, pchg->devid)) {
if (pchg->chg_parm) {
eoc_level = pchg->chg_parm->eoc_level;
ichg = pchg->chg_parm->ichg;
val = (ichg << 4) | eoc_level;
lp8727_i2c_write_byte(pchg, CHGCTRL2, &val);
}
}
}
static int lp8727_register_psy(struct lp8727_chg *pchg)
{
struct lp8727_psy *psy;
psy = kzalloc(sizeof(*psy), GFP_KERNEL);
if (!psy)
goto err_mem;
pchg->psy = psy;
psy->ac.name = "ac";
psy->ac.type = POWER_SUPPLY_TYPE_MAINS;
psy->ac.properties = lp8727_charger_prop;
psy->ac.num_properties = ARRAY_SIZE(lp8727_charger_prop);
psy->ac.get_property = lp8727_charger_get_property;
psy->ac.supplied_to = battery_supplied_to;
psy->ac.num_supplicants = ARRAY_SIZE(battery_supplied_to);
if (power_supply_register(pchg->dev, &psy->ac))
goto err_psy;
psy->usb.name = "usb";
psy->usb.type = POWER_SUPPLY_TYPE_USB;
psy->usb.properties = lp8727_charger_prop;
psy->usb.num_properties = ARRAY_SIZE(lp8727_charger_prop);
psy->usb.get_property = lp8727_charger_get_property;
psy->usb.supplied_to = battery_supplied_to;
psy->usb.num_supplicants = ARRAY_SIZE(battery_supplied_to);
if (power_supply_register(pchg->dev, &psy->usb))
goto err_psy;
psy->batt.name = "main_batt";
psy->batt.type = POWER_SUPPLY_TYPE_BATTERY;
psy->batt.properties = lp8727_battery_prop;
psy->batt.num_properties = ARRAY_SIZE(lp8727_battery_prop);
psy->batt.get_property = lp8727_battery_get_property;
psy->batt.external_power_changed = lp8727_charger_changed;
if (power_supply_register(pchg->dev, &psy->batt))
goto err_psy;
return 0;
err_mem:
return -ENOMEM;
err_psy:
kfree(psy);
return -EPERM;
}
static void lp8727_unregister_psy(struct lp8727_chg *pchg)
{
struct lp8727_psy *psy = pchg->psy;
if (!psy)
return;
power_supply_unregister(&psy->ac);
power_supply_unregister(&psy->usb);
power_supply_unregister(&psy->batt);
kfree(psy);
}
static int lp8727_probe(struct i2c_client *cl, const struct i2c_device_id *id)
{
struct lp8727_chg *pchg;
int ret;
if (!i2c_check_functionality(cl->adapter, I2C_FUNC_SMBUS_I2C_BLOCK))
return -EIO;
pchg = kzalloc(sizeof(*pchg), GFP_KERNEL);
if (!pchg)
return -ENOMEM;
pchg->client = cl;
pchg->dev = &cl->dev;
pchg->pdata = cl->dev.platform_data;
i2c_set_clientdata(cl, pchg);
mutex_init(&pchg->xfer_lock);
lp8727_init_device(pchg);
lp8727_intr_config(pchg);
ret = lp8727_register_psy(pchg);
if (ret)
dev_err(pchg->dev,
"can not register power supplies. err=%d", ret);
return 0;
}
static int __devexit lp8727_remove(struct i2c_client *cl)
{
struct lp8727_chg *pchg = i2c_get_clientdata(cl);
lp8727_unregister_psy(pchg);
free_irq(pchg->client->irq, pchg);
flush_workqueue(pchg->irqthread);
destroy_workqueue(pchg->irqthread);
kfree(pchg);
return 0;
}
static int __init lp8727_init(void)
{
return i2c_add_driver(&lp8727_driver);
}
static void __exit lp8727_exit(void)
{
i2c_del_driver(&lp8727_driver);
}
