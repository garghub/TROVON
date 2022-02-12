static void corgi_charger_init(void)
{
gpio_request_array(ARRAY_AND_SIZE(charger_gpios));
}
static void corgi_measure_temp(int on)
{
gpio_set_value(CORGI_GPIO_ADC_TEMP_ON, on);
}
static void corgi_charge(int on)
{
if (on) {
if (machine_is_corgi() && (sharpsl_pm.flags & SHARPSL_SUSPENDED)) {
gpio_set_value(CORGI_GPIO_CHRG_ON, 0);
gpio_set_value(CORGI_GPIO_CHRG_UKN, 1);
} else {
gpio_set_value(CORGI_GPIO_CHRG_ON, 1);
gpio_set_value(CORGI_GPIO_CHRG_UKN, 0);
}
} else {
gpio_set_value(CORGI_GPIO_CHRG_ON, 0);
gpio_set_value(CORGI_GPIO_CHRG_UKN, 0);
}
}
static void corgi_discharge(int on)
{
gpio_set_value(CORGI_GPIO_DISCHARGE_ON, on);
}
static void corgi_presuspend(void)
{
}
static void corgi_postsuspend(void)
{
}
static int corgi_should_wakeup(unsigned int resume_on_alarm)
{
int is_resume = 0;
dev_dbg(sharpsl_pm.dev, "PEDR = %x, GPIO_AC_IN = %d, "
"GPIO_CHRG_FULL = %d, GPIO_KEY_INT = %d, GPIO_WAKEUP = %d\n",
PEDR, gpio_get_value(CORGI_GPIO_AC_IN),
gpio_get_value(CORGI_GPIO_CHRG_FULL),
gpio_get_value(CORGI_GPIO_KEY_INT),
gpio_get_value(CORGI_GPIO_WAKEUP));
if ((PEDR & GPIO_bit(CORGI_GPIO_AC_IN))) {
if (sharpsl_pm.machinfo->read_devdata(SHARPSL_STATUS_ACIN)) {
dev_dbg(sharpsl_pm.dev, "ac insert\n");
sharpsl_pm.flags |= SHARPSL_DO_OFFLINE_CHRG;
} else {
dev_dbg(sharpsl_pm.dev, "ac remove\n");
sharpsl_pm_led(SHARPSL_LED_OFF);
sharpsl_pm.machinfo->charge(0);
sharpsl_pm.charge_mode = CHRG_OFF;
}
}
if ((PEDR & GPIO_bit(CORGI_GPIO_CHRG_FULL)))
dev_dbg(sharpsl_pm.dev, "Charge full interrupt\n");
if (PEDR & GPIO_bit(CORGI_GPIO_KEY_INT))
is_resume |= GPIO_bit(CORGI_GPIO_KEY_INT);
if (PEDR & GPIO_bit(CORGI_GPIO_WAKEUP))
is_resume |= GPIO_bit(CORGI_GPIO_WAKEUP);
if (resume_on_alarm && (PEDR & PWER_RTC))
is_resume |= PWER_RTC;
dev_dbg(sharpsl_pm.dev, "is_resume: %x\n",is_resume);
return is_resume;
}
static bool corgi_charger_wakeup(void)
{
return !gpio_get_value(CORGI_GPIO_AC_IN) ||
!gpio_get_value(CORGI_GPIO_KEY_INT) ||
!gpio_get_value(CORGI_GPIO_WAKEUP);
}
unsigned long corgipm_read_devdata(int type)
{
switch(type) {
case SHARPSL_STATUS_ACIN:
return !gpio_get_value(CORGI_GPIO_AC_IN);
case SHARPSL_STATUS_LOCK:
return gpio_get_value(sharpsl_pm.machinfo->gpio_batlock);
case SHARPSL_STATUS_CHRGFULL:
return gpio_get_value(sharpsl_pm.machinfo->gpio_batfull);
case SHARPSL_STATUS_FATAL:
return gpio_get_value(sharpsl_pm.machinfo->gpio_fatal);
case SHARPSL_ACIN_VOLT:
return sharpsl_pm_pxa_read_max1111(MAX1111_ACIN_VOLT);
case SHARPSL_BATT_TEMP:
return sharpsl_pm_pxa_read_max1111(MAX1111_BATT_TEMP);
case SHARPSL_BATT_VOLT:
default:
return sharpsl_pm_pxa_read_max1111(MAX1111_BATT_VOLT);
}
}
static int corgipm_init(void)
{
int ret;
if (!machine_is_corgi() && !machine_is_shepherd()
&& !machine_is_husky())
return -ENODEV;
corgipm_device = platform_device_alloc("sharpsl-pm", -1);
if (!corgipm_device)
return -ENOMEM;
if (!machine_is_corgi())
corgi_pm_machinfo.batfull_irq = 1;
corgipm_device->dev.platform_data = &corgi_pm_machinfo;
ret = platform_device_add(corgipm_device);
if (ret)
platform_device_put(corgipm_device);
return ret;
}
static void corgipm_exit(void)
{
platform_device_unregister(corgipm_device);
}
