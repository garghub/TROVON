static void spitz_charger_init(void)
{
gpio_request_array(ARRAY_AND_SIZE(spitz_charger_gpios));
}
static void spitz_measure_temp(int on)
{
gpio_set_value(SPITZ_GPIO_ADC_TEMP_ON, on);
}
static void spitz_charge(int on)
{
if (on) {
if (sharpsl_pm.flags & SHARPSL_SUSPENDED) {
gpio_set_value(SPITZ_GPIO_JK_B, 1);
gpio_set_value(SPITZ_GPIO_CHRG_ON, 0);
} else {
gpio_set_value(SPITZ_GPIO_JK_B, 0);
gpio_set_value(SPITZ_GPIO_CHRG_ON, 0);
}
} else {
gpio_set_value(SPITZ_GPIO_JK_B, 0);
gpio_set_value(SPITZ_GPIO_CHRG_ON, 1);
}
}
static void spitz_discharge(int on)
{
gpio_set_value(SPITZ_GPIO_JK_A, on);
}
static void spitz_discharge1(int on)
{
gpio_set_value(SPITZ_GPIO_LED_GREEN, on);
}
static void spitz_presuspend(void)
{
spitz_last_ac_status = sharpsl_pm.machinfo->read_devdata(SHARPSL_STATUS_ACIN);
PGSR0 = 0x00144018;
PGSR1 = 0x00EF0000;
if (machine_is_akita()) {
PGSR2 = 0x2121C000;
PGSR3 = 0x00600400;
} else {
PGSR2 = 0x0121C000;
PGSR3 = 0x00600000;
}
PGSR0 &= ~SPITZ_GPIO_G0_STROBE_BIT;
PGSR1 &= ~SPITZ_GPIO_G1_STROBE_BIT;
PGSR2 &= ~SPITZ_GPIO_G2_STROBE_BIT;
PGSR3 &= ~SPITZ_GPIO_G3_STROBE_BIT;
PGSR2 |= GPIO_bit(SPITZ_GPIO_KEY_STROBE0);
pxa2xx_mfp_config(&gpio18_config, 1);
gpio_request_one(18, GPIOF_OUT_INIT_HIGH, "Unknown");
gpio_free(18);
PRER = GPIO_bit(SPITZ_GPIO_KEY_INT);
PFER = GPIO_bit(SPITZ_GPIO_KEY_INT) | GPIO_bit(SPITZ_GPIO_RESET);
PWER = GPIO_bit(SPITZ_GPIO_KEY_INT) | GPIO_bit(SPITZ_GPIO_RESET) | PWER_RTC;
PKWR = GPIO_bit(SPITZ_GPIO_SYNC) | GPIO_bit(SPITZ_GPIO_KEY_INT) | GPIO_bit(SPITZ_GPIO_RESET);
PKSR = 0xffffffff;
PSLR |= PSLR_SL_ROD;
PCFR = PCFR_GPR_EN | PCFR_OPDE;
}
static void spitz_postsuspend(void)
{
}
static int spitz_should_wakeup(unsigned int resume_on_alarm)
{
int is_resume = 0;
int acin = sharpsl_pm.machinfo->read_devdata(SHARPSL_STATUS_ACIN);
if (spitz_last_ac_status != acin) {
if (acin) {
sharpsl_pm.flags |= SHARPSL_DO_OFFLINE_CHRG;
dev_dbg(sharpsl_pm.dev, "AC Inserted\n");
} else {
dev_dbg(sharpsl_pm.dev, "AC Removed\n");
sharpsl_pm_led(SHARPSL_LED_OFF);
sharpsl_pm.machinfo->charge(0);
sharpsl_pm.charge_mode = CHRG_OFF;
}
spitz_last_ac_status = acin;
return 0;
}
if (PEDR & GPIO_bit(SPITZ_GPIO_KEY_INT))
is_resume |= GPIO_bit(SPITZ_GPIO_KEY_INT);
if (PKSR & GPIO_bit(SPITZ_GPIO_SYNC))
is_resume |= GPIO_bit(SPITZ_GPIO_SYNC);
if (resume_on_alarm && (PEDR & PWER_RTC))
is_resume |= PWER_RTC;
dev_dbg(sharpsl_pm.dev, "is_resume: %x\n", is_resume);
return is_resume;
}
static unsigned long spitz_charger_wakeup(void)
{
unsigned long ret;
ret = ((!gpio_get_value(SPITZ_GPIO_KEY_INT)
<< GPIO_bit(SPITZ_GPIO_KEY_INT))
| gpio_get_value(SPITZ_GPIO_SYNC));
return ret;
}
unsigned long spitzpm_read_devdata(int type)
{
switch (type) {
case SHARPSL_STATUS_ACIN:
return !gpio_get_value(SPITZ_GPIO_AC_IN);
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
static int __devinit spitzpm_init(void)
{
int ret;
if (!machine_is_spitz() && !machine_is_akita()
&& !machine_is_borzoi())
return -ENODEV;
spitzpm_device = platform_device_alloc("sharpsl-pm", -1);
if (!spitzpm_device)
return -ENOMEM;
spitzpm_device->dev.platform_data = &spitz_pm_machinfo;
ret = platform_device_add(spitzpm_device);
if (ret)
platform_device_put(spitzpm_device);
return ret;
}
static void spitzpm_exit(void)
{
platform_device_unregister(spitzpm_device);
}
