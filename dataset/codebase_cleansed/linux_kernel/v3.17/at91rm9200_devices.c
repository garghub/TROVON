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
platform_device_register(&at91rm9200_usbh_device);
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
if (gpio_is_valid(data->pullup_pin))
at91_set_gpio_output(data->pullup_pin, 0);
udc_data = *data;
platform_device_register(&at91rm9200_udc_device);
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
at91_set_A_periph(AT91_PIN_PA16, 0);
at91_set_A_periph(AT91_PIN_PA15, 0);
at91_set_A_periph(AT91_PIN_PA14, 0);
at91_set_A_periph(AT91_PIN_PA13, 0);
at91_set_A_periph(AT91_PIN_PA12, 0);
at91_set_A_periph(AT91_PIN_PA11, 0);
at91_set_A_periph(AT91_PIN_PA10, 0);
at91_set_A_periph(AT91_PIN_PA9, 0);
at91_set_A_periph(AT91_PIN_PA8, 0);
at91_set_A_periph(AT91_PIN_PA7, 0);
if (!data->is_rmii) {
at91_set_B_periph(AT91_PIN_PB19, 0);
at91_set_B_periph(AT91_PIN_PB18, 0);
at91_set_B_periph(AT91_PIN_PB17, 0);
at91_set_B_periph(AT91_PIN_PB16, 0);
at91_set_B_periph(AT91_PIN_PB15, 0);
at91_set_B_periph(AT91_PIN_PB14, 0);
at91_set_B_periph(AT91_PIN_PB13, 0);
at91_set_B_periph(AT91_PIN_PB12, 0);
}
eth_data = *data;
platform_device_register(&at91rm9200_eth_device);
}
void __init at91_add_device_eth(struct macb_platform_data *data) {}
void __init at91_add_device_cf(struct at91_cf_data *data)
{
unsigned int csa;
if (!data)
return;
data->chipselect = 4;
csa = at91_ramc_read(0, AT91_EBI_CSA);
at91_ramc_write(0, AT91_EBI_CSA, csa | AT91_EBI_CS4A_SMC_COMPACTFLASH);
at91_ramc_write(0, AT91_SMC_CSR(4),
AT91_SMC_ACSS_STD
| AT91_SMC_DBW_16
| AT91_SMC_BAT
| AT91_SMC_WSEN
| AT91_SMC_NWS_(32)
| AT91_SMC_RWSETUP_(6)
| AT91_SMC_RWHOLD_(4)
);
if (gpio_is_valid(data->irq_pin)) {
at91_set_gpio_input(data->irq_pin, 1);
at91_set_deglitch(data->irq_pin, 1);
}
at91_set_gpio_input(data->det_pin, 1);
at91_set_deglitch(data->det_pin, 1);
if (gpio_is_valid(data->vcc_pin))
at91_set_gpio_output(data->vcc_pin, 0);
at91_set_gpio_output(data->rst_pin, 0);
at91_set_A_periph(AT91_PIN_PC9, 0);
at91_set_A_periph(AT91_PIN_PC10, 0);
at91_set_A_periph(AT91_PIN_PC11, 0);
at91_set_A_periph(AT91_PIN_PC12, 0);
at91_set_A_periph(AT91_PIN_PC6, 1);
cf_data = *data;
platform_device_register(&at91rm9200_cf_device);
}
void __init at91_add_device_cf(struct at91_cf_data *data) {}
void __init at91_add_device_mci(short mmc_id, struct mci_platform_data *data)
{
unsigned int i;
unsigned int slot_count = 0;
if (!data)
return;
for (i = 0; i < ATMCI_MAX_NR_SLOTS; i++) {
if (!data->slot[i].bus_width)
continue;
if (gpio_is_valid(data->slot[i].detect_pin)) {
at91_set_gpio_input(data->slot[i].detect_pin, 1);
at91_set_deglitch(data->slot[i].detect_pin, 1);
}
if (gpio_is_valid(data->slot[i].wp_pin))
at91_set_gpio_input(data->slot[i].wp_pin, 1);
switch (i) {
case 0:
at91_set_A_periph(AT91_PIN_PA28, 1);
at91_set_A_periph(AT91_PIN_PA29, 1);
if (data->slot[i].bus_width == 4) {
at91_set_B_periph(AT91_PIN_PB3, 1);
at91_set_B_periph(AT91_PIN_PB4, 1);
at91_set_B_periph(AT91_PIN_PB5, 1);
}
slot_count++;
break;
case 1:
at91_set_B_periph(AT91_PIN_PA8, 1);
at91_set_B_periph(AT91_PIN_PA9, 1);
if (data->slot[i].bus_width == 4) {
at91_set_B_periph(AT91_PIN_PA10, 1);
at91_set_B_periph(AT91_PIN_PA11, 1);
at91_set_B_periph(AT91_PIN_PA12, 1);
}
slot_count++;
break;
default:
printk(KERN_ERR
"AT91: SD/MMC slot %d not available\n", i);
break;
}
if (slot_count) {
at91_set_A_periph(AT91_PIN_PA27, 0);
mmc_data = *data;
platform_device_register(&at91rm9200_mmc_device);
}
}
}
void __init at91_add_device_mci(short mmc_id, struct mci_platform_data *data) {}
void __init at91_add_device_nand(struct atmel_nand_data *data)
{
unsigned int csa;
if (!data)
return;
csa = at91_ramc_read(0, AT91_EBI_CSA);
at91_ramc_write(0, AT91_EBI_CSA, csa | AT91_EBI_CS3A_SMC_SMARTMEDIA);
at91_ramc_write(0, AT91_SMC_CSR(3), AT91_SMC_ACSS_STD | AT91_SMC_DBW_8 | AT91_SMC_WSEN
| AT91_SMC_NWS_(5)
| AT91_SMC_TDF_(1)
| AT91_SMC_RWSETUP_(0)
| AT91_SMC_RWHOLD_(1)
);
if (gpio_is_valid(data->enable_pin))
at91_set_gpio_output(data->enable_pin, 1);
if (gpio_is_valid(data->rdy_pin))
at91_set_gpio_input(data->rdy_pin, 1);
if (gpio_is_valid(data->det_pin))
at91_set_gpio_input(data->det_pin, 1);
at91_set_A_periph(AT91_PIN_PC1, 0);
at91_set_A_periph(AT91_PIN_PC3, 0);
nand_data = *data;
platform_device_register(&at91rm9200_nand_device);
}
void __init at91_add_device_nand(struct atmel_nand_data *data) {}
void __init at91_add_device_i2c(struct i2c_board_info *devices, int nr_devices)
{
at91_set_GPIO_periph(AT91_PIN_PA25, 1);
at91_set_multi_drive(AT91_PIN_PA25, 1);
at91_set_GPIO_periph(AT91_PIN_PA26, 1);
at91_set_multi_drive(AT91_PIN_PA26, 1);
i2c_register_board_info(0, devices, nr_devices);
platform_device_register(&at91rm9200_twi_device);
}
void __init at91_add_device_i2c(struct i2c_board_info *devices, int nr_devices)
{
at91_set_A_periph(AT91_PIN_PA25, 0);
at91_set_multi_drive(AT91_PIN_PA25, 1);
at91_set_A_periph(AT91_PIN_PA26, 0);
at91_set_multi_drive(AT91_PIN_PA26, 1);
i2c_register_board_info(0, devices, nr_devices);
platform_device_register(&at91rm9200_twi_device);
}
void __init at91_add_device_i2c(struct i2c_board_info *devices, int nr_devices) {}
void __init at91_add_device_spi(struct spi_board_info *devices, int nr_devices)
{
int i;
unsigned long cs_pin;
at91_set_A_periph(AT91_PIN_PA0, 0);
at91_set_A_periph(AT91_PIN_PA1, 0);
at91_set_A_periph(AT91_PIN_PA2, 0);
for (i = 0; i < nr_devices; i++) {
if (devices[i].controller_data)
cs_pin = (unsigned long) devices[i].controller_data;
else
cs_pin = spi_standard_cs[devices[i].chip_select];
if (devices[i].chip_select == 0)
at91_set_A_periph(cs_pin, 0);
else
at91_set_gpio_output(cs_pin, 1);
devices[i].controller_data = (void *) cs_pin;
}
spi_register_board_info(devices, nr_devices);
platform_device_register(&at91rm9200_spi_device);
}
void __init at91_add_device_spi(struct spi_board_info *devices, int nr_devices) {}
static void __init at91_add_device_tc(void)
{
platform_device_register(&at91rm9200_tcb0_device);
platform_device_register(&at91rm9200_tcb1_device);
}
static void __init at91_add_device_tc(void) { }
static void __init at91_add_device_rtc(void)
{
platform_device_register(&at91rm9200_rtc_device);
}
static void __init at91_add_device_rtc(void) {}
static void __init at91_add_device_watchdog(void)
{
platform_device_register(&at91rm9200_wdt_device);
}
static void __init at91_add_device_watchdog(void) {}
static inline void configure_ssc0_pins(unsigned pins)
{
if (pins & ATMEL_SSC_TF)
at91_set_A_periph(AT91_PIN_PB0, 1);
if (pins & ATMEL_SSC_TK)
at91_set_A_periph(AT91_PIN_PB1, 1);
if (pins & ATMEL_SSC_TD)
at91_set_A_periph(AT91_PIN_PB2, 1);
if (pins & ATMEL_SSC_RD)
at91_set_A_periph(AT91_PIN_PB3, 1);
if (pins & ATMEL_SSC_RK)
at91_set_A_periph(AT91_PIN_PB4, 1);
if (pins & ATMEL_SSC_RF)
at91_set_A_periph(AT91_PIN_PB5, 1);
}
static inline void configure_ssc1_pins(unsigned pins)
{
if (pins & ATMEL_SSC_TF)
at91_set_A_periph(AT91_PIN_PB6, 1);
if (pins & ATMEL_SSC_TK)
at91_set_A_periph(AT91_PIN_PB7, 1);
if (pins & ATMEL_SSC_TD)
at91_set_A_periph(AT91_PIN_PB8, 1);
if (pins & ATMEL_SSC_RD)
at91_set_A_periph(AT91_PIN_PB9, 1);
if (pins & ATMEL_SSC_RK)
at91_set_A_periph(AT91_PIN_PB10, 1);
if (pins & ATMEL_SSC_RF)
at91_set_A_periph(AT91_PIN_PB11, 1);
}
static inline void configure_ssc2_pins(unsigned pins)
{
if (pins & ATMEL_SSC_TF)
at91_set_A_periph(AT91_PIN_PB12, 1);
if (pins & ATMEL_SSC_TK)
at91_set_A_periph(AT91_PIN_PB13, 1);
if (pins & ATMEL_SSC_TD)
at91_set_A_periph(AT91_PIN_PB14, 1);
if (pins & ATMEL_SSC_RD)
at91_set_A_periph(AT91_PIN_PB15, 1);
if (pins & ATMEL_SSC_RK)
at91_set_A_periph(AT91_PIN_PB16, 1);
if (pins & ATMEL_SSC_RF)
at91_set_A_periph(AT91_PIN_PB17, 1);
}
void __init at91_add_device_ssc(unsigned id, unsigned pins)
{
struct platform_device *pdev;
switch (id) {
case AT91RM9200_ID_SSC0:
pdev = &at91rm9200_ssc0_device;
configure_ssc0_pins(pins);
break;
case AT91RM9200_ID_SSC1:
pdev = &at91rm9200_ssc1_device;
configure_ssc1_pins(pins);
break;
case AT91RM9200_ID_SSC2:
pdev = &at91rm9200_ssc2_device;
configure_ssc2_pins(pins);
break;
default:
return;
}
platform_device_register(pdev);
}
void __init at91_add_device_ssc(unsigned id, unsigned pins) {}
static inline void configure_dbgu_pins(void)
{
at91_set_A_periph(AT91_PIN_PA30, 0);
at91_set_A_periph(AT91_PIN_PA31, 1);
}
static inline void configure_usart0_pins(unsigned pins)
{
at91_set_A_periph(AT91_PIN_PA17, 1);
at91_set_A_periph(AT91_PIN_PA18, 0);
if (pins & ATMEL_UART_CTS)
at91_set_A_periph(AT91_PIN_PA20, 0);
if (pins & ATMEL_UART_RTS) {
gpiod_add_lookup_table(&uart0_gpios_table);
}
}
static inline void configure_usart1_pins(unsigned pins)
{
at91_set_A_periph(AT91_PIN_PB20, 1);
at91_set_A_periph(AT91_PIN_PB21, 0);
if (pins & ATMEL_UART_RI)
at91_set_A_periph(AT91_PIN_PB18, 0);
if (pins & ATMEL_UART_DTR)
at91_set_A_periph(AT91_PIN_PB19, 0);
if (pins & ATMEL_UART_DCD)
at91_set_A_periph(AT91_PIN_PB23, 0);
if (pins & ATMEL_UART_CTS)
at91_set_A_periph(AT91_PIN_PB24, 0);
if (pins & ATMEL_UART_DSR)
at91_set_A_periph(AT91_PIN_PB25, 0);
if (pins & ATMEL_UART_RTS)
at91_set_A_periph(AT91_PIN_PB26, 0);
}
static inline void configure_usart2_pins(unsigned pins)
{
at91_set_A_periph(AT91_PIN_PA22, 0);
at91_set_A_periph(AT91_PIN_PA23, 1);
if (pins & ATMEL_UART_CTS)
at91_set_B_periph(AT91_PIN_PA30, 0);
if (pins & ATMEL_UART_RTS)
at91_set_B_periph(AT91_PIN_PA31, 0);
}
static inline void configure_usart3_pins(unsigned pins)
{
at91_set_B_periph(AT91_PIN_PA5, 1);
at91_set_B_periph(AT91_PIN_PA6, 0);
if (pins & ATMEL_UART_CTS)
at91_set_B_periph(AT91_PIN_PB1, 0);
if (pins & ATMEL_UART_RTS)
at91_set_B_periph(AT91_PIN_PB0, 0);
}
void __init at91_register_uart(unsigned id, unsigned portnr, unsigned pins)
{
struct platform_device *pdev;
struct atmel_uart_data *pdata;
switch (id) {
case 0:
pdev = &at91rm9200_dbgu_device;
configure_dbgu_pins();
break;
case AT91RM9200_ID_US0:
pdev = &at91rm9200_uart0_device;
configure_usart0_pins(pins);
break;
case AT91RM9200_ID_US1:
pdev = &at91rm9200_uart1_device;
configure_usart1_pins(pins);
break;
case AT91RM9200_ID_US2:
pdev = &at91rm9200_uart2_device;
configure_usart2_pins(pins);
break;
case AT91RM9200_ID_US3:
pdev = &at91rm9200_uart3_device;
configure_usart3_pins(pins);
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
static int __init at91_add_standard_devices(void)
{
at91_add_device_rtc();
at91_add_device_watchdog();
at91_add_device_tc();
return 0;
}
