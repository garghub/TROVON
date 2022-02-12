void __init at91_add_device_usbh(struct at91_usbh_data *data)
{
int i;
if (!data)
return;
for (i = 0; i < data->ports; i++) {
if (gpio_is_valid(data->overcurrent_pin[i]))
at91_set_gpio_input(data->overcurrent_pin[i], 1);
}
usbh_data = *data;
platform_device_register(&at91_usbh_device);
}
void __init at91_add_device_usbh(struct at91_usbh_data *data) {}
void __init at91_add_device_udc(struct at91_udc_data *data)
{
if (!data)
return;
if (gpio_is_valid(data->vbus_pin)) {
at91_set_gpio_input(data->vbus_pin, 0);
at91_set_deglitch(data->vbus_pin, 1);
}
udc_data = *data;
platform_device_register(&at91_udc_device);
}
void __init at91_add_device_udc(struct at91_udc_data *data) {}
void __init at91_add_device_eth(struct macb_platform_data *data)
{
if (!data)
return;
if (gpio_is_valid(data->phy_irq_pin)) {
at91_set_gpio_input(data->phy_irq_pin, 0);
at91_set_deglitch(data->phy_irq_pin, 1);
}
at91_set_A_periph(AT91_PIN_PA19, 0);
at91_set_A_periph(AT91_PIN_PA17, 0);
at91_set_A_periph(AT91_PIN_PA14, 0);
at91_set_A_periph(AT91_PIN_PA15, 0);
at91_set_A_periph(AT91_PIN_PA18, 0);
at91_set_A_periph(AT91_PIN_PA16, 0);
at91_set_A_periph(AT91_PIN_PA12, 0);
at91_set_A_periph(AT91_PIN_PA13, 0);
at91_set_A_periph(AT91_PIN_PA21, 0);
at91_set_A_periph(AT91_PIN_PA20, 0);
if (!data->is_rmii) {
at91_set_B_periph(AT91_PIN_PA28, 0);
at91_set_B_periph(AT91_PIN_PA29, 0);
at91_set_B_periph(AT91_PIN_PA25, 0);
at91_set_B_periph(AT91_PIN_PA26, 0);
at91_set_B_periph(AT91_PIN_PA27, 0);
at91_set_B_periph(AT91_PIN_PA23, 0);
at91_set_B_periph(AT91_PIN_PA24, 0);
at91_set_B_periph(AT91_PIN_PA22, 0);
}
eth_data = *data;
platform_device_register(&at91sam9260_eth_device);
}
void __init at91_add_device_eth(struct macb_platform_data *data) {}
void __init at91_add_device_mci(short mmc_id, struct mci_platform_data *data)
{
unsigned int i;
unsigned int slot_count = 0;
if (!data)
return;
for (i = 0; i < ATMCI_MAX_NR_SLOTS; i++) {
if (data->slot[i].bus_width) {
if (gpio_is_valid(data->slot[i].detect_pin)) {
at91_set_gpio_input(data->slot[i].detect_pin, 1);
at91_set_deglitch(data->slot[i].detect_pin, 1);
}
if (gpio_is_valid(data->slot[i].wp_pin))
at91_set_gpio_input(data->slot[i].wp_pin, 1);
switch (i) {
case 0:
at91_set_A_periph(AT91_PIN_PA7, 1);
at91_set_A_periph(AT91_PIN_PA6, 1);
if (data->slot[i].bus_width == 4) {
at91_set_A_periph(AT91_PIN_PA9, 1);
at91_set_A_periph(AT91_PIN_PA10, 1);
at91_set_A_periph(AT91_PIN_PA11, 1);
}
slot_count++;
break;
case 1:
at91_set_B_periph(AT91_PIN_PA1, 1);
at91_set_B_periph(AT91_PIN_PA0, 1);
if (data->slot[i].bus_width == 4) {
at91_set_B_periph(AT91_PIN_PA5, 1);
at91_set_B_periph(AT91_PIN_PA4, 1);
at91_set_B_periph(AT91_PIN_PA3, 1);
}
slot_count++;
break;
default:
printk(KERN_ERR
"AT91: SD/MMC slot %d not available\n", i);
break;
}
}
}
if (slot_count) {
at91_set_A_periph(AT91_PIN_PA8, 0);
mmc_data = *data;
platform_device_register(&at91sam9260_mmc_device);
}
}
void __init at91_add_device_mci(short mmc_id, struct mci_platform_data *data) {}
void __init at91_add_device_nand(struct atmel_nand_data *data)
{
unsigned long csa;
if (!data)
return;
csa = at91_matrix_read(AT91_MATRIX_EBICSA);
at91_matrix_write(AT91_MATRIX_EBICSA, csa | AT91_MATRIX_CS3A_SMC_SMARTMEDIA);
if (gpio_is_valid(data->enable_pin))
at91_set_gpio_output(data->enable_pin, 1);
if (gpio_is_valid(data->rdy_pin))
at91_set_gpio_input(data->rdy_pin, 1);
if (gpio_is_valid(data->det_pin))
at91_set_gpio_input(data->det_pin, 1);
nand_data = *data;
platform_device_register(&at91sam9260_nand_device);
}
void __init at91_add_device_nand(struct atmel_nand_data *data) {}
void __init at91_add_device_i2c(struct i2c_board_info *devices, int nr_devices)
{
at91_set_GPIO_periph(AT91_PIN_PA23, 1);
at91_set_multi_drive(AT91_PIN_PA23, 1);
at91_set_GPIO_periph(AT91_PIN_PA24, 1);
at91_set_multi_drive(AT91_PIN_PA24, 1);
i2c_register_board_info(0, devices, nr_devices);
platform_device_register(&at91sam9260_twi_device);
}
void __init at91_add_device_i2c(struct i2c_board_info *devices, int nr_devices)
{
if (cpu_is_at91sam9g20()) {
at91sam9260_twi_device.name = "i2c-at91sam9g20";
} else {
at91sam9260_twi_device.name = "i2c-at91sam9260";
}
at91_set_A_periph(AT91_PIN_PA23, 0);
at91_set_multi_drive(AT91_PIN_PA23, 1);
at91_set_A_periph(AT91_PIN_PA24, 0);
at91_set_multi_drive(AT91_PIN_PA24, 1);
i2c_register_board_info(0, devices, nr_devices);
platform_device_register(&at91sam9260_twi_device);
}
void __init at91_add_device_i2c(struct i2c_board_info *devices, int nr_devices) {}
void __init at91_add_device_spi(struct spi_board_info *devices, int nr_devices)
{
int i;
unsigned long cs_pin;
short enable_spi0 = 0;
short enable_spi1 = 0;
for (i = 0; i < nr_devices; i++) {
if (devices[i].controller_data)
cs_pin = (unsigned long) devices[i].controller_data;
else if (devices[i].bus_num == 0)
cs_pin = spi0_standard_cs[devices[i].chip_select];
else
cs_pin = spi1_standard_cs[devices[i].chip_select];
if (!gpio_is_valid(cs_pin))
continue;
if (devices[i].bus_num == 0)
enable_spi0 = 1;
else
enable_spi1 = 1;
at91_set_gpio_output(cs_pin, 1);
devices[i].controller_data = (void *) cs_pin;
}
spi_register_board_info(devices, nr_devices);
if (enable_spi0) {
at91_set_A_periph(AT91_PIN_PA0, 0);
at91_set_A_periph(AT91_PIN_PA1, 0);
at91_set_A_periph(AT91_PIN_PA2, 0);
platform_device_register(&at91sam9260_spi0_device);
}
if (enable_spi1) {
at91_set_A_periph(AT91_PIN_PB0, 0);
at91_set_A_periph(AT91_PIN_PB1, 0);
at91_set_A_periph(AT91_PIN_PB2, 0);
platform_device_register(&at91sam9260_spi1_device);
}
}
void __init at91_add_device_spi(struct spi_board_info *devices, int nr_devices) {}
static void __init at91_add_device_tc(void)
{
platform_device_register(&at91sam9260_tcb0_device);
platform_device_register(&at91sam9260_tcb1_device);
}
static void __init at91_add_device_tc(void) { }
static void __init at91_add_device_rtt_rtc(void)
{
at91sam9260_rtt_device.name = "rtc-at91sam9";
at91sam9260_rtt_device.num_resources = 3;
rtt_resources[1].start = AT91SAM9260_BASE_GPBR +
4 * CONFIG_RTC_DRV_AT91SAM9_GPBR;
rtt_resources[1].end = rtt_resources[1].start + 3;
rtt_resources[2].start = NR_IRQS_LEGACY + AT91_ID_SYS;
rtt_resources[2].end = NR_IRQS_LEGACY + AT91_ID_SYS;
}
static void __init at91_add_device_rtt_rtc(void)
{
at91sam9260_rtt_device.num_resources = 1;
}
static void __init at91_add_device_rtt(void)
{
at91_add_device_rtt_rtc();
platform_device_register(&at91sam9260_rtt_device);
}
static void __init at91_add_device_watchdog(void)
{
platform_device_register(&at91sam9260_wdt_device);
}
static void __init at91_add_device_watchdog(void) {}
static inline void configure_ssc_pins(unsigned pins)
{
if (pins & ATMEL_SSC_TF)
at91_set_A_periph(AT91_PIN_PB17, 1);
if (pins & ATMEL_SSC_TK)
at91_set_A_periph(AT91_PIN_PB16, 1);
if (pins & ATMEL_SSC_TD)
at91_set_A_periph(AT91_PIN_PB18, 1);
if (pins & ATMEL_SSC_RD)
at91_set_A_periph(AT91_PIN_PB19, 1);
if (pins & ATMEL_SSC_RK)
at91_set_A_periph(AT91_PIN_PB20, 1);
if (pins & ATMEL_SSC_RF)
at91_set_A_periph(AT91_PIN_PB21, 1);
}
void __init at91_add_device_ssc(unsigned id, unsigned pins)
{
struct platform_device *pdev;
switch (id) {
case AT91SAM9260_ID_SSC:
pdev = &at91sam9260_ssc_device;
configure_ssc_pins(pins);
break;
default:
return;
}
platform_device_register(pdev);
}
void __init at91_add_device_ssc(unsigned id, unsigned pins) {}
static inline void configure_dbgu_pins(void)
{
at91_set_A_periph(AT91_PIN_PB14, 0);
at91_set_A_periph(AT91_PIN_PB15, 1);
}
static inline void configure_usart0_pins(unsigned pins)
{
at91_set_A_periph(AT91_PIN_PB4, 1);
at91_set_A_periph(AT91_PIN_PB5, 0);
if (pins & ATMEL_UART_RTS)
at91_set_A_periph(AT91_PIN_PB26, 0);
if (pins & ATMEL_UART_CTS)
at91_set_A_periph(AT91_PIN_PB27, 0);
if (pins & ATMEL_UART_DTR)
at91_set_A_periph(AT91_PIN_PB24, 0);
if (pins & ATMEL_UART_DSR)
at91_set_A_periph(AT91_PIN_PB22, 0);
if (pins & ATMEL_UART_DCD)
at91_set_A_periph(AT91_PIN_PB23, 0);
if (pins & ATMEL_UART_RI)
at91_set_A_periph(AT91_PIN_PB25, 0);
}
static inline void configure_usart1_pins(unsigned pins)
{
at91_set_A_periph(AT91_PIN_PB6, 1);
at91_set_A_periph(AT91_PIN_PB7, 0);
if (pins & ATMEL_UART_RTS)
at91_set_A_periph(AT91_PIN_PB28, 0);
if (pins & ATMEL_UART_CTS)
at91_set_A_periph(AT91_PIN_PB29, 0);
}
static inline void configure_usart2_pins(unsigned pins)
{
at91_set_A_periph(AT91_PIN_PB8, 1);
at91_set_A_periph(AT91_PIN_PB9, 0);
if (pins & ATMEL_UART_RTS)
at91_set_A_periph(AT91_PIN_PA4, 0);
if (pins & ATMEL_UART_CTS)
at91_set_A_periph(AT91_PIN_PA5, 0);
}
static inline void configure_usart3_pins(unsigned pins)
{
at91_set_A_periph(AT91_PIN_PB10, 1);
at91_set_A_periph(AT91_PIN_PB11, 0);
if (pins & ATMEL_UART_RTS)
at91_set_B_periph(AT91_PIN_PC8, 0);
if (pins & ATMEL_UART_CTS)
at91_set_B_periph(AT91_PIN_PC10, 0);
}
static inline void configure_usart4_pins(void)
{
at91_set_B_periph(AT91_PIN_PA31, 1);
at91_set_B_periph(AT91_PIN_PA30, 0);
}
static inline void configure_usart5_pins(void)
{
at91_set_A_periph(AT91_PIN_PB12, 1);
at91_set_A_periph(AT91_PIN_PB13, 0);
}
void __init at91_register_uart(unsigned id, unsigned portnr, unsigned pins)
{
struct platform_device *pdev;
struct atmel_uart_data *pdata;
switch (id) {
case 0:
pdev = &at91sam9260_dbgu_device;
configure_dbgu_pins();
break;
case AT91SAM9260_ID_US0:
pdev = &at91sam9260_uart0_device;
configure_usart0_pins(pins);
break;
case AT91SAM9260_ID_US1:
pdev = &at91sam9260_uart1_device;
configure_usart1_pins(pins);
break;
case AT91SAM9260_ID_US2:
pdev = &at91sam9260_uart2_device;
configure_usart2_pins(pins);
break;
case AT91SAM9260_ID_US3:
pdev = &at91sam9260_uart3_device;
configure_usart3_pins(pins);
break;
case AT91SAM9260_ID_US4:
pdev = &at91sam9260_uart4_device;
configure_usart4_pins();
break;
case AT91SAM9260_ID_US5:
pdev = &at91sam9260_uart5_device;
configure_usart5_pins();
break;
default:
return;
}
pdata = pdev->dev.platform_data;
pdata->num = portnr;
if (portnr < ATMEL_MAX_UART)
at91_uarts[portnr] = pdev;
}
void __init at91_add_device_serial(void)
{
int i;
for (i = 0; i < ATMEL_MAX_UART; i++) {
if (at91_uarts[i])
platform_device_register(at91_uarts[i]);
}
}
void __init at91_register_uart(unsigned id, unsigned portnr, unsigned pins) {}
void __init at91_add_device_serial(void) {}
void __init at91_add_device_cf(struct at91_cf_data *data)
{
struct platform_device *pdev;
unsigned long csa;
if (!data)
return;
csa = at91_matrix_read(AT91_MATRIX_EBICSA);
switch (data->chipselect) {
case 4:
at91_set_multi_drive(AT91_PIN_PC8, 0);
at91_set_A_periph(AT91_PIN_PC8, 0);
csa |= AT91_MATRIX_CS4A_SMC_CF1;
cf0_data = *data;
pdev = &cf0_device;
break;
case 5:
at91_set_multi_drive(AT91_PIN_PC9, 0);
at91_set_A_periph(AT91_PIN_PC9, 0);
csa |= AT91_MATRIX_CS5A_SMC_CF2;
cf1_data = *data;
pdev = &cf1_device;
break;
default:
printk(KERN_ERR "AT91 CF: bad chip-select requested (%u)\n",
data->chipselect);
return;
}
at91_matrix_write(AT91_MATRIX_EBICSA, csa);
if (gpio_is_valid(data->rst_pin)) {
at91_set_multi_drive(data->rst_pin, 0);
at91_set_gpio_output(data->rst_pin, 1);
}
if (gpio_is_valid(data->irq_pin)) {
at91_set_gpio_input(data->irq_pin, 0);
at91_set_deglitch(data->irq_pin, 1);
}
if (gpio_is_valid(data->det_pin)) {
at91_set_gpio_input(data->det_pin, 0);
at91_set_deglitch(data->det_pin, 1);
}
at91_set_B_periph(AT91_PIN_PC6, 0);
at91_set_B_periph(AT91_PIN_PC7, 0);
at91_set_A_periph(AT91_PIN_PC10, 0);
at91_set_A_periph(AT91_PIN_PC15, 1);
if (IS_ENABLED(CONFIG_PATA_AT91) && (data->flags & AT91_CF_TRUE_IDE))
pdev->name = "pata_at91";
else
pdev->name = "at91_cf";
platform_device_register(pdev);
}
void __init at91_add_device_cf(struct at91_cf_data * data) {}
void __init at91_add_device_adc(struct at91_adc_data *data)
{
if (!data)
return;
if (test_bit(0, &data->channels_used))
at91_set_A_periph(AT91_PIN_PC0, 0);
if (test_bit(1, &data->channels_used))
at91_set_A_periph(AT91_PIN_PC1, 0);
if (test_bit(2, &data->channels_used))
at91_set_A_periph(AT91_PIN_PC2, 0);
if (test_bit(3, &data->channels_used))
at91_set_A_periph(AT91_PIN_PC3, 0);
if (data->use_external_triggers)
at91_set_A_periph(AT91_PIN_PA22, 0);
data->startup_time = 10;
data->trigger_number = 4;
data->trigger_list = at91_adc_triggers;
adc_data = *data;
platform_device_register(&at91_adc_device);
}
void __init at91_add_device_adc(struct at91_adc_data *data) {}
static int __init at91_add_standard_devices(void)
{
if (of_have_populated_dt())
return 0;
at91_add_device_rtt();
at91_add_device_watchdog();
at91_add_device_tc();
return 0;
}
