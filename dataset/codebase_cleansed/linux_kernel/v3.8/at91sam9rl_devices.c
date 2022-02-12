void __init at91_add_device_hdmac(void)
{
platform_device_register(&at_hdmac_device);
}
void __init at91_add_device_hdmac(void) {}
void __init at91_add_device_usba(struct usba_platform_data *data)
{
usba_udc_data.pdata.vbus_pin = -EINVAL;
usba_udc_data.pdata.num_ep = ARRAY_SIZE(usba_udc_ep);
memcpy(usba_udc_data.ep, usba_udc_ep, sizeof(usba_udc_ep));
if (data && gpio_is_valid(data->vbus_pin)) {
at91_set_gpio_input(data->vbus_pin, 0);
at91_set_deglitch(data->vbus_pin, 1);
usba_udc_data.pdata.vbus_pin = data->vbus_pin;
}
platform_device_register(&at91_usba_udc_device);
}
void __init at91_add_device_usba(struct usba_platform_data *data) {}
void __init at91_add_device_mci(short mmc_id, struct mci_platform_data *data)
{
if (!data)
return;
if (data->slot[0].bus_width) {
if (gpio_is_valid(data->slot[0].detect_pin)) {
at91_set_gpio_input(data->slot[0].detect_pin, 1);
at91_set_deglitch(data->slot[0].detect_pin, 1);
}
if (gpio_is_valid(data->slot[0].wp_pin))
at91_set_gpio_input(data->slot[0].wp_pin, 1);
at91_set_A_periph(AT91_PIN_PA2, 0);
at91_set_A_periph(AT91_PIN_PA1, 1);
at91_set_A_periph(AT91_PIN_PA0, 1);
if (data->slot[0].bus_width == 4) {
at91_set_A_periph(AT91_PIN_PA3, 1);
at91_set_A_periph(AT91_PIN_PA4, 1);
at91_set_A_periph(AT91_PIN_PA5, 1);
}
mmc_data = *data;
platform_device_register(&at91sam9rl_mmc_device);
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
at91_set_A_periph(AT91_PIN_PB4, 0);
at91_set_A_periph(AT91_PIN_PB5, 0);
nand_data = *data;
platform_device_register(&atmel_nand_device);
}
void __init at91_add_device_nand(struct atmel_nand_data *data) {}
void __init at91_add_device_i2c(struct i2c_board_info *devices, int nr_devices)
{
at91_set_GPIO_periph(AT91_PIN_PA23, 1);
at91_set_multi_drive(AT91_PIN_PA23, 1);
at91_set_GPIO_periph(AT91_PIN_PA24, 1);
at91_set_multi_drive(AT91_PIN_PA24, 1);
i2c_register_board_info(0, devices, nr_devices);
platform_device_register(&at91sam9rl_twi_device);
}
void __init at91_add_device_i2c(struct i2c_board_info *devices, int nr_devices)
{
at91_set_A_periph(AT91_PIN_PA23, 0);
at91_set_multi_drive(AT91_PIN_PA23, 1);
at91_set_A_periph(AT91_PIN_PA24, 0);
at91_set_multi_drive(AT91_PIN_PA24, 1);
i2c_register_board_info(0, devices, nr_devices);
platform_device_register(&at91sam9rl_twi_device);
}
void __init at91_add_device_i2c(struct i2c_board_info *devices, int nr_devices) {}
void __init at91_add_device_spi(struct spi_board_info *devices, int nr_devices)
{
int i;
unsigned long cs_pin;
at91_set_A_periph(AT91_PIN_PA25, 0);
at91_set_A_periph(AT91_PIN_PA26, 0);
at91_set_A_periph(AT91_PIN_PA27, 0);
for (i = 0; i < nr_devices; i++) {
if (devices[i].controller_data)
cs_pin = (unsigned long) devices[i].controller_data;
else
cs_pin = spi_standard_cs[devices[i].chip_select];
if (!gpio_is_valid(cs_pin))
continue;
at91_set_gpio_output(cs_pin, 1);
devices[i].controller_data = (void *) cs_pin;
}
spi_register_board_info(devices, nr_devices);
platform_device_register(&at91sam9rl_spi_device);
}
void __init at91_add_device_spi(struct spi_board_info *devices, int nr_devices) {}
void __init at91_add_device_ac97(struct ac97c_platform_data *data)
{
if (!data)
return;
at91_set_A_periph(AT91_PIN_PD1, 0);
at91_set_A_periph(AT91_PIN_PD2, 0);
at91_set_A_periph(AT91_PIN_PD3, 0);
at91_set_A_periph(AT91_PIN_PD4, 0);
if (gpio_is_valid(data->reset_pin))
at91_set_gpio_output(data->reset_pin, 0);
ac97_data = *data;
platform_device_register(&at91sam9rl_ac97_device);
}
void __init at91_add_device_ac97(struct ac97c_platform_data *data) {}
void __init at91_add_device_lcdc(struct atmel_lcdfb_info *data)
{
if (!data) {
return;
}
at91_set_B_periph(AT91_PIN_PC1, 0);
at91_set_A_periph(AT91_PIN_PC5, 0);
at91_set_A_periph(AT91_PIN_PC6, 0);
at91_set_A_periph(AT91_PIN_PC7, 0);
at91_set_A_periph(AT91_PIN_PC3, 0);
at91_set_B_periph(AT91_PIN_PC9, 0);
at91_set_B_periph(AT91_PIN_PC10, 0);
at91_set_B_periph(AT91_PIN_PC11, 0);
at91_set_B_periph(AT91_PIN_PC12, 0);
at91_set_B_periph(AT91_PIN_PC13, 0);
at91_set_B_periph(AT91_PIN_PC15, 0);
at91_set_B_periph(AT91_PIN_PC16, 0);
at91_set_B_periph(AT91_PIN_PC17, 0);
at91_set_B_periph(AT91_PIN_PC18, 0);
at91_set_B_periph(AT91_PIN_PC19, 0);
at91_set_B_periph(AT91_PIN_PC20, 0);
at91_set_B_periph(AT91_PIN_PC21, 0);
at91_set_B_periph(AT91_PIN_PC22, 0);
at91_set_B_periph(AT91_PIN_PC23, 0);
at91_set_B_periph(AT91_PIN_PC24, 0);
at91_set_B_periph(AT91_PIN_PC25, 0);
lcdc_data = *data;
platform_device_register(&at91_lcdc_device);
}
void __init at91_add_device_lcdc(struct atmel_lcdfb_info *data) {}
static void __init at91_add_device_tc(void)
{
platform_device_register(&at91sam9rl_tcb_device);
}
static void __init at91_add_device_tc(void) { }
void __init at91_add_device_tsadcc(struct at91_tsadcc_data *data)
{
if (!data)
return;
at91_set_A_periph(AT91_PIN_PA17, 0);
at91_set_A_periph(AT91_PIN_PA18, 0);
at91_set_A_periph(AT91_PIN_PA19, 0);
at91_set_A_periph(AT91_PIN_PA20, 0);
tsadcc_data = *data;
platform_device_register(&at91sam9rl_tsadcc_device);
}
void __init at91_add_device_tsadcc(struct at91_tsadcc_data *data) {}
static void __init at91_add_device_rtc(void)
{
platform_device_register(&at91sam9rl_rtc_device);
}
static void __init at91_add_device_rtc(void) {}
static void __init at91_add_device_rtt_rtc(void)
{
at91sam9rl_rtt_device.name = "rtc-at91sam9";
at91sam9rl_rtt_device.num_resources = 3;
rtt_resources[1].start = AT91SAM9RL_BASE_GPBR +
4 * CONFIG_RTC_DRV_AT91SAM9_GPBR;
rtt_resources[1].end = rtt_resources[1].start + 3;
rtt_resources[2].start = NR_IRQS_LEGACY + AT91_ID_SYS;
rtt_resources[2].end = NR_IRQS_LEGACY + AT91_ID_SYS;
}
static void __init at91_add_device_rtt_rtc(void)
{
at91sam9rl_rtt_device.num_resources = 1;
}
static void __init at91_add_device_rtt(void)
{
at91_add_device_rtt_rtc();
platform_device_register(&at91sam9rl_rtt_device);
}
static void __init at91_add_device_watchdog(void)
{
platform_device_register(&at91sam9rl_wdt_device);
}
static void __init at91_add_device_watchdog(void) {}
void __init at91_add_device_pwm(u32 mask)
{
if (mask & (1 << AT91_PWM0))
at91_set_B_periph(AT91_PIN_PB8, 1);
if (mask & (1 << AT91_PWM1))
at91_set_B_periph(AT91_PIN_PB9, 1);
if (mask & (1 << AT91_PWM2))
at91_set_B_periph(AT91_PIN_PD5, 1);
if (mask & (1 << AT91_PWM3))
at91_set_B_periph(AT91_PIN_PD8, 1);
pwm_mask = mask;
platform_device_register(&at91sam9rl_pwm0_device);
}
void __init at91_add_device_pwm(u32 mask) {}
static inline void configure_ssc0_pins(unsigned pins)
{
if (pins & ATMEL_SSC_TF)
at91_set_A_periph(AT91_PIN_PC0, 1);
if (pins & ATMEL_SSC_TK)
at91_set_A_periph(AT91_PIN_PC1, 1);
if (pins & ATMEL_SSC_TD)
at91_set_A_periph(AT91_PIN_PA15, 1);
if (pins & ATMEL_SSC_RD)
at91_set_A_periph(AT91_PIN_PA16, 1);
if (pins & ATMEL_SSC_RK)
at91_set_B_periph(AT91_PIN_PA10, 1);
if (pins & ATMEL_SSC_RF)
at91_set_B_periph(AT91_PIN_PA22, 1);
}
static inline void configure_ssc1_pins(unsigned pins)
{
if (pins & ATMEL_SSC_TF)
at91_set_B_periph(AT91_PIN_PA29, 1);
if (pins & ATMEL_SSC_TK)
at91_set_B_periph(AT91_PIN_PA30, 1);
if (pins & ATMEL_SSC_TD)
at91_set_B_periph(AT91_PIN_PA13, 1);
if (pins & ATMEL_SSC_RD)
at91_set_B_periph(AT91_PIN_PA14, 1);
if (pins & ATMEL_SSC_RK)
at91_set_B_periph(AT91_PIN_PA9, 1);
if (pins & ATMEL_SSC_RF)
at91_set_B_periph(AT91_PIN_PA8, 1);
}
void __init at91_add_device_ssc(unsigned id, unsigned pins)
{
struct platform_device *pdev;
switch (id) {
case AT91SAM9RL_ID_SSC0:
pdev = &at91sam9rl_ssc0_device;
configure_ssc0_pins(pins);
break;
case AT91SAM9RL_ID_SSC1:
pdev = &at91sam9rl_ssc1_device;
configure_ssc1_pins(pins);
break;
default:
return;
}
platform_device_register(pdev);
}
void __init at91_add_device_ssc(unsigned id, unsigned pins) {}
static inline void configure_dbgu_pins(void)
{
at91_set_A_periph(AT91_PIN_PA21, 0);
at91_set_A_periph(AT91_PIN_PA22, 1);
}
static inline void configure_usart0_pins(unsigned pins)
{
at91_set_A_periph(AT91_PIN_PA6, 1);
at91_set_A_periph(AT91_PIN_PA7, 0);
if (pins & ATMEL_UART_RTS)
at91_set_A_periph(AT91_PIN_PA9, 0);
if (pins & ATMEL_UART_CTS)
at91_set_A_periph(AT91_PIN_PA10, 0);
if (pins & ATMEL_UART_DSR)
at91_set_A_periph(AT91_PIN_PD14, 0);
if (pins & ATMEL_UART_DTR)
at91_set_A_periph(AT91_PIN_PD15, 0);
if (pins & ATMEL_UART_DCD)
at91_set_A_periph(AT91_PIN_PD16, 0);
if (pins & ATMEL_UART_RI)
at91_set_A_periph(AT91_PIN_PD17, 0);
}
static inline void configure_usart1_pins(unsigned pins)
{
at91_set_A_periph(AT91_PIN_PA11, 1);
at91_set_A_periph(AT91_PIN_PA12, 0);
if (pins & ATMEL_UART_RTS)
at91_set_B_periph(AT91_PIN_PA18, 0);
if (pins & ATMEL_UART_CTS)
at91_set_B_periph(AT91_PIN_PA19, 0);
}
static inline void configure_usart2_pins(unsigned pins)
{
at91_set_A_periph(AT91_PIN_PA13, 1);
at91_set_A_periph(AT91_PIN_PA14, 0);
if (pins & ATMEL_UART_RTS)
at91_set_A_periph(AT91_PIN_PA29, 0);
if (pins & ATMEL_UART_CTS)
at91_set_A_periph(AT91_PIN_PA30, 0);
}
static inline void configure_usart3_pins(unsigned pins)
{
at91_set_A_periph(AT91_PIN_PB0, 1);
at91_set_A_periph(AT91_PIN_PB1, 0);
if (pins & ATMEL_UART_RTS)
at91_set_B_periph(AT91_PIN_PD4, 0);
if (pins & ATMEL_UART_CTS)
at91_set_B_periph(AT91_PIN_PD3, 0);
}
void __init at91_register_uart(unsigned id, unsigned portnr, unsigned pins)
{
struct platform_device *pdev;
struct atmel_uart_data *pdata;
switch (id) {
case 0:
pdev = &at91sam9rl_dbgu_device;
configure_dbgu_pins();
break;
case AT91SAM9RL_ID_US0:
pdev = &at91sam9rl_uart0_device;
configure_usart0_pins(pins);
break;
case AT91SAM9RL_ID_US1:
pdev = &at91sam9rl_uart1_device;
configure_usart1_pins(pins);
break;
case AT91SAM9RL_ID_US2:
pdev = &at91sam9rl_uart2_device;
configure_usart2_pins(pins);
break;
case AT91SAM9RL_ID_US3:
pdev = &at91sam9rl_uart3_device;
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
at91_add_device_hdmac();
at91_add_device_rtc();
at91_add_device_rtt();
at91_add_device_watchdog();
at91_add_device_tc();
return 0;
}
