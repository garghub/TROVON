static unsigned long collie_read_bat(struct collie_bat *bat)
{
unsigned long value = 0;
if (bat->gpio_bat < 0 || bat->adc_bat < 0)
return 0;
mutex_lock(&bat_lock);
gpio_set_value(bat->gpio_bat, 1);
msleep(5);
ucb1x00_adc_enable(ucb);
value = ucb1x00_adc_read(ucb, bat->adc_bat, UCB_SYNC);
ucb1x00_adc_disable(ucb);
gpio_set_value(bat->gpio_bat, 0);
mutex_unlock(&bat_lock);
value = value * 1000000 / bat->adc_bat_divider;
return value;
}
static unsigned long collie_read_temp(struct collie_bat *bat)
{
unsigned long value = 0;
if (bat->gpio_temp < 0 || bat->adc_temp < 0)
return 0;
mutex_lock(&bat_lock);
gpio_set_value(bat->gpio_temp, 1);
msleep(5);
ucb1x00_adc_enable(ucb);
value = ucb1x00_adc_read(ucb, bat->adc_temp, UCB_SYNC);
ucb1x00_adc_disable(ucb);
gpio_set_value(bat->gpio_temp, 0);
mutex_unlock(&bat_lock);
value = value * 10000 / bat->adc_temp_divider;
return value;
}
static int collie_bat_get_property(struct power_supply *psy,
enum power_supply_property psp,
union power_supply_propval *val)
{
int ret = 0;
struct collie_bat *bat = container_of(psy, struct collie_bat, psy);
if (bat->is_present && !bat->is_present(bat)
&& psp != POWER_SUPPLY_PROP_PRESENT) {
return -ENODEV;
}
switch (psp) {
case POWER_SUPPLY_PROP_STATUS:
val->intval = bat->status;
break;
case POWER_SUPPLY_PROP_TECHNOLOGY:
val->intval = bat->technology;
break;
case POWER_SUPPLY_PROP_VOLTAGE_NOW:
val->intval = collie_read_bat(bat);
break;
case POWER_SUPPLY_PROP_VOLTAGE_MAX:
if (bat->full_chrg == -1)
val->intval = bat->bat_max;
else
val->intval = bat->full_chrg;
break;
case POWER_SUPPLY_PROP_VOLTAGE_MAX_DESIGN:
val->intval = bat->bat_max;
break;
case POWER_SUPPLY_PROP_VOLTAGE_MIN_DESIGN:
val->intval = bat->bat_min;
break;
case POWER_SUPPLY_PROP_TEMP:
val->intval = collie_read_temp(bat);
break;
case POWER_SUPPLY_PROP_PRESENT:
val->intval = bat->is_present ? bat->is_present(bat) : 1;
break;
default:
ret = -EINVAL;
break;
}
return ret;
}
static void collie_bat_external_power_changed(struct power_supply *psy)
{
schedule_work(&bat_work);
}
static irqreturn_t collie_bat_gpio_isr(int irq, void *data)
{
pr_info("collie_bat_gpio irq\n");
schedule_work(&bat_work);
return IRQ_HANDLED;
}
static void collie_bat_update(struct collie_bat *bat)
{
int old;
struct power_supply *psy = &bat->psy;
mutex_lock(&bat->work_lock);
old = bat->status;
if (bat->is_present && !bat->is_present(bat)) {
printk(KERN_NOTICE "%s not present\n", psy->name);
bat->status = POWER_SUPPLY_STATUS_UNKNOWN;
bat->full_chrg = -1;
} else if (power_supply_am_i_supplied(psy)) {
if (bat->status == POWER_SUPPLY_STATUS_DISCHARGING) {
gpio_set_value(bat->gpio_charge_on, 1);
mdelay(15);
}
if (gpio_get_value(bat->gpio_full)) {
if (old == POWER_SUPPLY_STATUS_CHARGING ||
bat->full_chrg == -1)
bat->full_chrg = collie_read_bat(bat);
gpio_set_value(bat->gpio_charge_on, 0);
bat->status = POWER_SUPPLY_STATUS_FULL;
} else {
gpio_set_value(bat->gpio_charge_on, 1);
bat->status = POWER_SUPPLY_STATUS_CHARGING;
}
} else {
gpio_set_value(bat->gpio_charge_on, 0);
bat->status = POWER_SUPPLY_STATUS_DISCHARGING;
}
if (old != bat->status)
power_supply_changed(psy);
mutex_unlock(&bat->work_lock);
}
static void collie_bat_work(struct work_struct *work)
{
collie_bat_update(&collie_bat_main);
}
static int collie_bat_suspend(struct ucb1x00_dev *dev, pm_message_t state)
{
flush_work(&bat_work);
return 0;
}
static int collie_bat_resume(struct ucb1x00_dev *dev)
{
schedule_work(&bat_work);
return 0;
}
static int __devinit collie_bat_probe(struct ucb1x00_dev *dev)
{
int ret;
if (!machine_is_collie())
return -ENODEV;
ucb = dev->ucb;
ret = gpio_request_array(collie_batt_gpios,
ARRAY_SIZE(collie_batt_gpios));
if (ret)
return ret;
mutex_init(&collie_bat_main.work_lock);
INIT_WORK(&bat_work, collie_bat_work);
ret = power_supply_register(&dev->ucb->dev, &collie_bat_main.psy);
if (ret)
goto err_psy_reg_main;
ret = power_supply_register(&dev->ucb->dev, &collie_bat_bu.psy);
if (ret)
goto err_psy_reg_bu;
ret = request_irq(gpio_to_irq(COLLIE_GPIO_CO),
collie_bat_gpio_isr,
IRQF_TRIGGER_RISING | IRQF_TRIGGER_FALLING,
"main full", &collie_bat_main);
if (!ret) {
schedule_work(&bat_work);
return 0;
}
power_supply_unregister(&collie_bat_bu.psy);
err_psy_reg_bu:
power_supply_unregister(&collie_bat_main.psy);
err_psy_reg_main:
cancel_work_sync(&bat_work);
gpio_free_array(collie_batt_gpios, ARRAY_SIZE(collie_batt_gpios));
return ret;
}
static void __devexit collie_bat_remove(struct ucb1x00_dev *dev)
{
free_irq(gpio_to_irq(COLLIE_GPIO_CO), &collie_bat_main);
power_supply_unregister(&collie_bat_bu.psy);
power_supply_unregister(&collie_bat_main.psy);
cancel_work_sync(&bat_work);
gpio_free_array(collie_batt_gpios, ARRAY_SIZE(collie_batt_gpios));
}
static int __init collie_bat_init(void)
{
return ucb1x00_register_driver(&collie_bat_driver);
}
static void __exit collie_bat_exit(void)
{
ucb1x00_unregister_driver(&collie_bat_driver);
}
