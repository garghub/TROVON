static void digsy_mtc_op_prepare(void *p)
{
gpio_set_value(GPIO_EEPROM_OE, 0);
}
static void digsy_mtc_op_finish(void *p)
{
gpio_set_value(GPIO_EEPROM_OE, 1);
}
static int __init digsy_mtc_eeprom_devices_init(void)
{
int ret;
ret = gpio_request_one(GPIO_EEPROM_OE, GPIOF_OUT_INIT_HIGH,
"93xx46 EEPROMs OE");
if (ret) {
pr_err("can't request gpio %d\n", GPIO_EEPROM_OE);
return ret;
}
spi_register_board_info(digsy_mtc_eeprom_info,
ARRAY_SIZE(digsy_mtc_eeprom_info));
return platform_device_register(&digsy_mtc_eeprom);
}
