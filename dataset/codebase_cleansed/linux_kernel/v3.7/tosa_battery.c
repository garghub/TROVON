static unsigned long tosa_read_bat(struct tosa_bat *bat)
{
unsigned long value = 0;
if (bat->gpio_bat < 0 || bat->adc_bat < 0)
return 0;
mutex_lock(&bat_lock);
gpio_set_value(bat->gpio_bat, 1);
msleep(5);
value = wm97xx_read_aux_adc(dev_get_drvdata(bat->psy.dev->parent),
bat->adc_bat);
gpio_set_value(bat->gpio_bat, 0);
mutex_unlock(&bat_lock);
value = value * 1000000 / bat->adc_bat_divider;
return value;
}
static unsigned long tosa_read_temp(struct tosa_bat *bat)
{
unsigned long value = 0;
if (bat->gpio_temp < 0 || bat->adc_temp < 0)
return 0;
mutex_lock(&bat_lock);
gpio_set_value(bat->gpio_temp, 1);
msleep(5);
value = wm97xx_read_aux_adc(dev_get_drvdata(bat->psy.dev->parent),
bat->adc_temp);
gpio_set_value(bat->gpio_temp, 0);
mutex_unlock(&bat_lock);
value = value * 10000 / bat->adc_temp_divider;
return value;
}
static int tosa_bat_get_property(struct power_supply *psy,
enum power_supply_property psp,
union power_supply_propval *val)
{
int ret = 0;
struct tosa_bat *bat = container_of(psy, struct tosa_bat, psy);
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
val->intval = tosa_read_bat(bat);
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
val->intval = tosa_read_temp(bat);
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
static bool tosa_jacket_bat_is_present(struct tosa_bat *bat)
{
return gpio_get_value(TOSA_GPIO_JACKET_DETECT) == 0;
}
static void tosa_bat_external_power_changed(struct power_supply *psy)
{
schedule_work(&bat_work);
}
static irqreturn_t tosa_bat_gpio_isr(int irq, void *data)
{
pr_info("tosa_bat_gpio irq: %d\n", gpio_get_value(irq_to_gpio(irq)));
schedule_work(&bat_work);
return IRQ_HANDLED;
}
static void tosa_bat_update(struct tosa_bat *bat)
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
gpio_set_value(bat->gpio_charge_off, 0);
mdelay(15);
}
if (gpio_get_value(bat->gpio_full)) {
if (old == POWER_SUPPLY_STATUS_CHARGING ||
bat->full_chrg == -1)
bat->full_chrg = tosa_read_bat(bat);
gpio_set_value(bat->gpio_charge_off, 1);
bat->status = POWER_SUPPLY_STATUS_FULL;
} else {
gpio_set_value(bat->gpio_charge_off, 0);
bat->status = POWER_SUPPLY_STATUS_CHARGING;
}
} else {
gpio_set_value(bat->gpio_charge_off, 1);
bat->status = POWER_SUPPLY_STATUS_DISCHARGING;
}
if (old != bat->status)
power_supply_changed(psy);
mutex_unlock(&bat->work_lock);
}
static void tosa_bat_work(struct work_struct *work)
{
tosa_bat_update(&tosa_bat_main);
tosa_bat_update(&tosa_bat_jacket);
}
static int tosa_bat_suspend(struct platform_device *dev, pm_message_t state)
{
flush_work(&bat_work);
return 0;
}
static int tosa_bat_resume(struct platform_device *dev)
{
schedule_work(&bat_work);
return 0;
}
static int __devinit tosa_bat_probe(struct platform_device *dev)
{
int ret;
if (!machine_is_tosa())
return -ENODEV;
ret = gpio_request_array(tosa_bat_gpios, ARRAY_SIZE(tosa_bat_gpios));
if (ret)
return ret;
mutex_init(&tosa_bat_main.work_lock);
mutex_init(&tosa_bat_jacket.work_lock);
INIT_WORK(&bat_work, tosa_bat_work);
ret = power_supply_register(&dev->dev, &tosa_bat_main.psy);
if (ret)
goto err_psy_reg_main;
ret = power_supply_register(&dev->dev, &tosa_bat_jacket.psy);
if (ret)
goto err_psy_reg_jacket;
ret = power_supply_register(&dev->dev, &tosa_bat_bu.psy);
if (ret)
goto err_psy_reg_bu;
ret = request_irq(gpio_to_irq(TOSA_GPIO_BAT0_CRG),
tosa_bat_gpio_isr,
IRQF_TRIGGER_RISING | IRQF_TRIGGER_FALLING,
"main full", &tosa_bat_main);
if (ret)
goto err_req_main;
ret = request_irq(gpio_to_irq(TOSA_GPIO_BAT1_CRG),
tosa_bat_gpio_isr,
IRQF_TRIGGER_RISING | IRQF_TRIGGER_FALLING,
"jacket full", &tosa_bat_jacket);
if (ret)
goto err_req_jacket;
ret = request_irq(gpio_to_irq(TOSA_GPIO_JACKET_DETECT),
tosa_bat_gpio_isr,
IRQF_TRIGGER_RISING | IRQF_TRIGGER_FALLING,
"jacket detect", &tosa_bat_jacket);
if (!ret) {
schedule_work(&bat_work);
return 0;
}
free_irq(gpio_to_irq(TOSA_GPIO_BAT1_CRG), &tosa_bat_jacket);
err_req_jacket:
free_irq(gpio_to_irq(TOSA_GPIO_BAT0_CRG), &tosa_bat_main);
err_req_main:
power_supply_unregister(&tosa_bat_bu.psy);
err_psy_reg_bu:
power_supply_unregister(&tosa_bat_jacket.psy);
err_psy_reg_jacket:
power_supply_unregister(&tosa_bat_main.psy);
err_psy_reg_main:
cancel_work_sync(&bat_work);
gpio_free_array(tosa_bat_gpios, ARRAY_SIZE(tosa_bat_gpios));
return ret;
}
static int __devexit tosa_bat_remove(struct platform_device *dev)
{
free_irq(gpio_to_irq(TOSA_GPIO_JACKET_DETECT), &tosa_bat_jacket);
free_irq(gpio_to_irq(TOSA_GPIO_BAT1_CRG), &tosa_bat_jacket);
free_irq(gpio_to_irq(TOSA_GPIO_BAT0_CRG), &tosa_bat_main);
power_supply_unregister(&tosa_bat_bu.psy);
power_supply_unregister(&tosa_bat_jacket.psy);
power_supply_unregister(&tosa_bat_main.psy);
cancel_work_sync(&bat_work);
gpio_free_array(tosa_bat_gpios, ARRAY_SIZE(tosa_bat_gpios));
return 0;
}
