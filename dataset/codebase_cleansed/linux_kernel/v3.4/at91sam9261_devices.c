void __init at91_add_device_usbh(struct at91_usbh_data *data)
{
int i;
if (!data)
return;
for (i = 0; i < data->ports; i++) {
if (data->overcurrent_pin[i])
at91_set_gpio_input(data->overcurrent_pin[i], 1);
}
usbh_data = *data;
platform_device_register(&at91sam9261_usbh_device);
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
platform_device_register(&at91sam9261_udc_device);
}
void __init at91_add_device_udc(struct at91_udc_data *data) {}
void __init at91_add_device_mmc(short mmc_id, struct at91_mmc_data *data)
{
if (!data)
return;
if (gpio_is_valid(data->det_pin)) {
at91_set_gpio_input(data->det_pin, 1);
at91_set_deglitch(data->det_pin, 1);
}
if (gpio_is_valid(data->wp_pin))
at91_set_gpio_input(data->wp_pin, 1);
if (gpio_is_valid(data->vcc_pin))
at91_set_gpio_output(data->vcc_pin, 0);
at91_set_B_periph(AT91_PIN_PA2, 0);
at91_set_B_periph(AT91_PIN_PA1, 1);
at91_set_B_periph(AT91_PIN_PA0, 1);
if (data->wire4) {
at91_set_B_periph(AT91_PIN_PA4, 1);
at91_set_B_periph(AT91_PIN_PA5, 1);
at91_set_B_periph(AT91_PIN_PA6, 1);
}
mmc_data = *data;
platform_device_register(&at91sam9261_mmc_device);
}
void __init at91_add_device_mmc(short mmc_id, struct at91_mmc_data *data) {}
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
at91_set_A_periph(AT91_PIN_PC0, 0);
at91_set_A_periph(AT91_PIN_PC1, 0);
nand_data = *data;
platform_device_register(&atmel_nand_device);
}
void __init at91_add_device_nand(struct atmel_nand_data *data) {}
void __init at91_add_device_i2c(struct i2c_board_info *devices, int nr_devices)
{
at91_set_GPIO_periph(AT91_PIN_PA7, 1);
at91_set_multi_drive(AT91_PIN_PA7, 1);
at91_set_GPIO_periph(AT91_PIN_PA8, 1);
at91_set_multi_drive(AT91_PIN_PA8, 1);
i2c_register_board_info(0, devices, nr_devices);
platform_device_register(&at91sam9261_twi_device);
}
void __init at91_add_device_i2c(struct i2c_board_info *devices, int nr_devices)
{
at91_set_A_periph(AT91_PIN_PA7, 0);
at91_set_multi_drive(AT91_PIN_PA7, 1);
at91_set_A_periph(AT91_PIN_PA8, 0);
at91_set_multi_drive(AT91_PIN_PA8, 1);
i2c_register_board_info(0, devices, nr_devices);
platform_device_register(&at91sam9261_twi_device);
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
platform_device_register(&at91sam9261_spi0_device);
}
if (enable_spi1) {
at91_set_A_periph(AT91_PIN_PB30, 0);
at91_set_A_periph(AT91_PIN_PB31, 0);
at91_set_A_periph(AT91_PIN_PB29, 0);
platform_device_register(&at91sam9261_spi1_device);
}
}
void __init at91_add_device_spi(struct spi_board_info *devices, int nr_devices) {}
void __init at91_add_device_lcdc(struct atmel_lcdfb_info *data)
{
if (!data) {
return;
}
#if defined(CONFIG_FB_ATMEL_STN)
at91_set_A_periph(AT91_PIN_PB0, 0);
at91_set_A_periph(AT91_PIN_PB1, 0);
at91_set_A_periph(AT91_PIN_PB2, 0);
at91_set_A_periph(AT91_PIN_PB3, 0);
at91_set_A_periph(AT91_PIN_PB4, 0);
at91_set_A_periph(AT91_PIN_PB5, 0);
at91_set_A_periph(AT91_PIN_PB6, 0);
at91_set_A_periph(AT91_PIN_PB7, 0);
at91_set_A_periph(AT91_PIN_PB8, 0);
#else
at91_set_A_periph(AT91_PIN_PB1, 0);
at91_set_A_periph(AT91_PIN_PB2, 0);
at91_set_A_periph(AT91_PIN_PB3, 0);
at91_set_A_periph(AT91_PIN_PB4, 0);
at91_set_A_periph(AT91_PIN_PB7, 0);
at91_set_A_periph(AT91_PIN_PB8, 0);
at91_set_A_periph(AT91_PIN_PB9, 0);
at91_set_A_periph(AT91_PIN_PB10, 0);
at91_set_A_periph(AT91_PIN_PB11, 0);
at91_set_A_periph(AT91_PIN_PB12, 0);
at91_set_A_periph(AT91_PIN_PB15, 0);
at91_set_A_periph(AT91_PIN_PB16, 0);
at91_set_A_periph(AT91_PIN_PB17, 0);
at91_set_A_periph(AT91_PIN_PB18, 0);
at91_set_A_periph(AT91_PIN_PB19, 0);
at91_set_A_periph(AT91_PIN_PB20, 0);
at91_set_B_periph(AT91_PIN_PB23, 0);
at91_set_B_periph(AT91_PIN_PB24, 0);
at91_set_B_periph(AT91_PIN_PB25, 0);
at91_set_B_periph(AT91_PIN_PB26, 0);
at91_set_B_periph(AT91_PIN_PB27, 0);
at91_set_B_periph(AT91_PIN_PB28, 0);
#endif
if (ARRAY_SIZE(lcdc_resources) > 2) {
void __iomem *fb;
struct resource *fb_res = &lcdc_resources[2];
size_t fb_len = resource_size(fb_res);
fb = ioremap(fb_res->start, fb_len);
if (fb) {
memset(fb, 0, fb_len);
iounmap(fb);
}
}
lcdc_data = *data;
platform_device_register(&at91_lcdc_device);
}
void __init at91_add_device_lcdc(struct atmel_lcdfb_info *data) {}
static void __init at91_add_device_tc(void)
{
platform_device_register(&at91sam9261_tcb_device);
}
static void __init at91_add_device_tc(void) { }
static void __init at91_add_device_rtt_rtc(void)
{
at91sam9261_rtt_device.name = "rtc-at91sam9";
at91sam9261_rtt_device.num_resources = 2;
rtt_resources[1].start = AT91SAM9261_BASE_GPBR +
4 * CONFIG_RTC_DRV_AT91SAM9_GPBR;
rtt_resources[1].end = rtt_resources[1].start + 3;
}
static void __init at91_add_device_rtt_rtc(void)
{
at91sam9261_rtt_device.num_resources = 1;
}
static void __init at91_add_device_rtt(void)
{
at91_add_device_rtt_rtc();
platform_device_register(&at91sam9261_rtt_device);
}
static void __init at91_add_device_watchdog(void)
{
platform_device_register(&at91sam9261_wdt_device);
}
static void __init at91_add_device_watchdog(void) {}
static inline void configure_ssc0_pins(unsigned pins)
{
if (pins & ATMEL_SSC_TF)
at91_set_A_periph(AT91_PIN_PB21, 1);
if (pins & ATMEL_SSC_TK)
at91_set_A_periph(AT91_PIN_PB22, 1);
if (pins & ATMEL_SSC_TD)
at91_set_A_periph(AT91_PIN_PB23, 1);
if (pins & ATMEL_SSC_RD)
at91_set_A_periph(AT91_PIN_PB24, 1);
if (pins & ATMEL_SSC_RK)
at91_set_A_periph(AT91_PIN_PB25, 1);
if (pins & ATMEL_SSC_RF)
at91_set_A_periph(AT91_PIN_PB26, 1);
}
static inline void configure_ssc1_pins(unsigned pins)
{
if (pins & ATMEL_SSC_TF)
at91_set_B_periph(AT91_PIN_PA17, 1);
if (pins & ATMEL_SSC_TK)
at91_set_B_periph(AT91_PIN_PA18, 1);
if (pins & ATMEL_SSC_TD)
at91_set_B_periph(AT91_PIN_PA19, 1);
if (pins & ATMEL_SSC_RD)
at91_set_B_periph(AT91_PIN_PA20, 1);
if (pins & ATMEL_SSC_RK)
at91_set_B_periph(AT91_PIN_PA21, 1);
if (pins & ATMEL_SSC_RF)
at91_set_B_periph(AT91_PIN_PA22, 1);
}
static inline void configure_ssc2_pins(unsigned pins)
{
if (pins & ATMEL_SSC_TF)
at91_set_B_periph(AT91_PIN_PC25, 1);
if (pins & ATMEL_SSC_TK)
at91_set_B_periph(AT91_PIN_PC26, 1);
if (pins & ATMEL_SSC_TD)
at91_set_B_periph(AT91_PIN_PC27, 1);
if (pins & ATMEL_SSC_RD)
at91_set_B_periph(AT91_PIN_PC28, 1);
if (pins & ATMEL_SSC_RK)
at91_set_B_periph(AT91_PIN_PC29, 1);
if (pins & ATMEL_SSC_RF)
at91_set_B_periph(AT91_PIN_PC30, 1);
}
void __init at91_add_device_ssc(unsigned id, unsigned pins)
{
struct platform_device *pdev;
switch (id) {
case AT91SAM9261_ID_SSC0:
pdev = &at91sam9261_ssc0_device;
configure_ssc0_pins(pins);
break;
case AT91SAM9261_ID_SSC1:
pdev = &at91sam9261_ssc1_device;
configure_ssc1_pins(pins);
break;
case AT91SAM9261_ID_SSC2:
pdev = &at91sam9261_ssc2_device;
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
at91_set_A_periph(AT91_PIN_PA9, 0);
at91_set_A_periph(AT91_PIN_PA10, 1);
}
static inline void configure_usart0_pins(unsigned pins)
{
at91_set_A_periph(AT91_PIN_PC8, 1);
at91_set_A_periph(AT91_PIN_PC9, 0);
if (pins & ATMEL_UART_RTS)
at91_set_A_periph(AT91_PIN_PC10, 0);
if (pins & ATMEL_UART_CTS)
at91_set_A_periph(AT91_PIN_PC11, 0);
}
static inline void configure_usart1_pins(unsigned pins)
{
at91_set_A_periph(AT91_PIN_PC12, 1);
at91_set_A_periph(AT91_PIN_PC13, 0);
if (pins & ATMEL_UART_RTS)
at91_set_B_periph(AT91_PIN_PA12, 0);
if (pins & ATMEL_UART_CTS)
at91_set_B_periph(AT91_PIN_PA13, 0);
}
static inline void configure_usart2_pins(unsigned pins)
{
at91_set_A_periph(AT91_PIN_PC15, 0);
at91_set_A_periph(AT91_PIN_PC14, 1);
if (pins & ATMEL_UART_RTS)
at91_set_B_periph(AT91_PIN_PA15, 0);
if (pins & ATMEL_UART_CTS)
at91_set_B_periph(AT91_PIN_PA16, 0);
}
void __init at91_register_uart(unsigned id, unsigned portnr, unsigned pins)
{
struct platform_device *pdev;
struct atmel_uart_data *pdata;
switch (id) {
case 0:
pdev = &at91sam9261_dbgu_device;
configure_dbgu_pins();
break;
case AT91SAM9261_ID_US0:
pdev = &at91sam9261_uart0_device;
configure_usart0_pins(pins);
break;
case AT91SAM9261_ID_US1:
pdev = &at91sam9261_uart1_device;
configure_usart1_pins(pins);
break;
case AT91SAM9261_ID_US2:
pdev = &at91sam9261_uart2_device;
configure_usart2_pins(pins);
break;
default:
return;
}
pdata = pdev->dev.platform_data;
pdata->num = portnr;
if (portnr < ATMEL_MAX_UART)
at91_uarts[portnr] = pdev;
}
void __init at91_set_serial_console(unsigned portnr)
{
if (portnr < ATMEL_MAX_UART) {
atmel_default_console_device = at91_uarts[portnr];
at91sam9261_set_console_clock(at91_uarts[portnr]->id);
}
}
void __init at91_add_device_serial(void)
{
int i;
for (i = 0; i < ATMEL_MAX_UART; i++) {
if (at91_uarts[i])
platform_device_register(at91_uarts[i]);
}
if (!atmel_default_console_device)
printk(KERN_INFO "AT91: No default serial console defined.\n");
}
void __init at91_register_uart(unsigned id, unsigned portnr, unsigned pins) {}
void __init at91_set_serial_console(unsigned portnr) {}
void __init at91_add_device_serial(void) {}
static int __init at91_add_standard_devices(void)
{
at91_add_device_rtt();
at91_add_device_watchdog();
at91_add_device_tc();
return 0;
}
