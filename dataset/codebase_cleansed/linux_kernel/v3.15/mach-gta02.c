static long gta02_panic_blink(int state)
{
long delay = 0;
char led;
led = (state) ? 1 : 0;
gpio_direction_output(GTA02_GPIO_AUX_LED, led);
return delay;
}
static void
gta02_configure_pmu_for_charger(struct pcf50633 *pcf, void *unused, int res)
{
int ma;
if (res < ((ADC_NOM_CHG_DETECT_USB + ADC_NOM_CHG_DETECT_1A) / 2)) {
pcf50633_gpio_set(pcf, PCF50633_GPO, 0);
ma = 1000;
} else
ma = 100;
pcf50633_mbc_usb_curlim_set(pcf, ma);
}
static void gta02_charger_worker(struct work_struct *work)
{
if (gta02_usb_vbus_draw) {
pcf50633_mbc_usb_curlim_set(gta02_pcf, gta02_usb_vbus_draw);
return;
}
#ifdef CONFIG_PCF50633_ADC
pcf50633_adc_async_read(gta02_pcf,
PCF50633_ADCC1_MUX_ADCIN1,
PCF50633_ADCC1_AVERAGE_16,
gta02_configure_pmu_for_charger,
NULL);
#else
pcf50633_mbc_usb_curlim_set(gta02_pcf, 100);
#endif
}
static void gta02_pmu_event_callback(struct pcf50633 *pcf, int irq)
{
if (irq == PCF50633_IRQ_USBINS) {
schedule_delayed_work(&gta02_charger_work,
GTA02_CHARGER_CONFIGURE_TIMEOUT);
return;
}
if (irq == PCF50633_IRQ_USBREM) {
cancel_delayed_work_sync(&gta02_charger_work);
gta02_usb_vbus_draw = 0;
}
}
static void gta02_udc_vbus_draw(unsigned int ma)
{
if (!gta02_pcf)
return;
gta02_usb_vbus_draw = ma;
schedule_delayed_work(&gta02_charger_work,
GTA02_CHARGER_CONFIGURE_TIMEOUT);
}
static void __init gta02_map_io(void)
{
s3c24xx_init_io(gta02_iodesc, ARRAY_SIZE(gta02_iodesc));
s3c24xx_init_clocks(12000000);
s3c24xx_init_uarts(gta02_uartcfgs, ARRAY_SIZE(gta02_uartcfgs));
samsung_set_timer_source(SAMSUNG_PWM3, SAMSUNG_PWM4);
}
static void gta02_pmu_attach_child_devices(struct pcf50633 *pcf)
{
int n;
gta02_pcf = pcf;
for (n = 0; n < ARRAY_SIZE(gta02_devices_pmu_children); n++)
gta02_devices_pmu_children[n]->dev.parent = pcf->dev;
platform_add_devices(gta02_devices_pmu_children,
ARRAY_SIZE(gta02_devices_pmu_children));
}
static void gta02_poweroff(void)
{
pcf50633_reg_set_bit_mask(gta02_pcf, PCF50633_REG_OOCSHDWN, 1, 1);
}
static void __init gta02_machine_init(void)
{
panic_blink = gta02_panic_blink;
s3c_pm_init();
#ifdef CONFIG_CHARGER_PCF50633
INIT_DELAYED_WORK(&gta02_charger_work, gta02_charger_worker);
#endif
s3c24xx_udc_set_platdata(&gta02_udc_cfg);
s3c24xx_ts_set_platdata(&gta02_ts_info);
s3c_ohci_set_platdata(&gta02_usb_info);
s3c_nand_set_platdata(&gta02_nand_info);
s3c_i2c0_set_platdata(NULL);
i2c_register_board_info(0, gta02_i2c_devs, ARRAY_SIZE(gta02_i2c_devs));
platform_add_devices(gta02_devices, ARRAY_SIZE(gta02_devices));
pm_power_off = gta02_poweroff;
regulator_has_full_constraints();
}
