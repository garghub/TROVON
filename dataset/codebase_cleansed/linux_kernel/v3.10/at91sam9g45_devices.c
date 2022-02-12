void __init at91_add_device_hdmac(void)
{
platform_device_register(&at_hdmac_device);
}
void __init at91_add_device_hdmac(void) {}
void __init at91_add_device_usbh_ohci(struct at91_usbh_data *data)
{
int i;
if (!data)
return;
for (i = 0; i < data->ports; i++) {
if (gpio_is_valid(data->vbus_pin[i]))
at91_set_gpio_output(data->vbus_pin[i],
data->vbus_pin_active_low[i]);
}
for (i = 0; i < data->ports; i++) {
if (gpio_is_valid(data->overcurrent_pin[i]))
at91_set_gpio_input(data->overcurrent_pin[i], 1);
}
usbh_ohci_data = *data;
platform_device_register(&at91_usbh_ohci_device);
}
void __init at91_add_device_usbh_ohci(struct at91_usbh_data *data) {}
void __init at91_add_device_usbh_ehci(struct at91_usbh_data *data)
{
int i;
if (!data)
return;
for (i = 0; i < data->ports; i++) {
if (gpio_is_valid(data->vbus_pin[i]))
at91_set_gpio_output(data->vbus_pin[i],
data->vbus_pin_active_low[i]);
}
usbh_ehci_data = *data;
platform_device_register(&at91_usbh_ehci_device);
}
void __init at91_add_device_usbh_ehci(struct at91_usbh_data *data) {}
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
void __init at91_add_device_eth(struct macb_platform_data *data)
{
if (!data)
return;
if (gpio_is_valid(data->phy_irq_pin)) {
at91_set_gpio_input(data->phy_irq_pin, 0);
at91_set_deglitch(data->phy_irq_pin, 1);
}
at91_set_A_periph(AT91_PIN_PA17, 0);
at91_set_A_periph(AT91_PIN_PA15, 0);
at91_set_A_periph(AT91_PIN_PA12, 0);
at91_set_A_periph(AT91_PIN_PA13, 0);
at91_set_A_periph(AT91_PIN_PA16, 0);
at91_set_A_periph(AT91_PIN_PA14, 0);
at91_set_A_periph(AT91_PIN_PA10, 0);
at91_set_A_periph(AT91_PIN_PA11, 0);
at91_set_A_periph(AT91_PIN_PA19, 0);
at91_set_A_periph(AT91_PIN_PA18, 0);
if (!data->is_rmii) {
at91_set_B_periph(AT91_PIN_PA29, 0);
at91_set_B_periph(AT91_PIN_PA30, 0);
at91_set_B_periph(AT91_PIN_PA8, 0);
at91_set_B_periph(AT91_PIN_PA9, 0);
at91_set_B_periph(AT91_PIN_PA28, 0);
at91_set_B_periph(AT91_PIN_PA6, 0);
at91_set_B_periph(AT91_PIN_PA7, 0);
at91_set_B_periph(AT91_PIN_PA27, 0);
}
eth_data = *data;
platform_device_register(&at91sam9g45_eth_device);
}
void __init at91_add_device_eth(struct macb_platform_data *data) {}
void __init at91_add_device_mci(short mmc_id, struct mci_platform_data *data)
{
if (!data)
return;
if (!data->slot[0].bus_width)
return;
#if defined(CONFIG_AT_HDMAC) || defined(CONFIG_AT_HDMAC_MODULE)
{
struct at_dma_slave *atslave;
struct mci_dma_data *alt_atslave;
alt_atslave = kzalloc(sizeof(struct mci_dma_data), GFP_KERNEL);
atslave = &alt_atslave->sdata;
atslave->dma_dev = &at_hdmac_device.dev;
atslave->cfg = ATC_FIFOCFG_HALFFIFO
| ATC_SRC_H2SEL_HW | ATC_DST_H2SEL_HW;
if (mmc_id == 0)
atslave->cfg |= ATC_SRC_PER(AT_DMA_ID_MCI0)
| ATC_DST_PER(AT_DMA_ID_MCI0);
else
atslave->cfg |= ATC_SRC_PER(AT_DMA_ID_MCI1)
| ATC_DST_PER(AT_DMA_ID_MCI1);
data->dma_slave = alt_atslave;
}
#endif
if (gpio_is_valid(data->slot[0].detect_pin)) {
at91_set_gpio_input(data->slot[0].detect_pin, 1);
at91_set_deglitch(data->slot[0].detect_pin, 1);
}
if (gpio_is_valid(data->slot[0].wp_pin))
at91_set_gpio_input(data->slot[0].wp_pin, 1);
if (mmc_id == 0) {
at91_set_A_periph(AT91_PIN_PA0, 0);
at91_set_A_periph(AT91_PIN_PA1, 1);
at91_set_A_periph(AT91_PIN_PA2, 1);
if (data->slot[0].bus_width == 4) {
at91_set_A_periph(AT91_PIN_PA3, 1);
at91_set_A_periph(AT91_PIN_PA4, 1);
at91_set_A_periph(AT91_PIN_PA5, 1);
if (data->slot[0].bus_width == 8) {
at91_set_A_periph(AT91_PIN_PA6, 1);
at91_set_A_periph(AT91_PIN_PA7, 1);
at91_set_A_periph(AT91_PIN_PA8, 1);
at91_set_A_periph(AT91_PIN_PA9, 1);
}
}
mmc0_data = *data;
platform_device_register(&at91sam9g45_mmc0_device);
} else {
at91_set_A_periph(AT91_PIN_PA31, 0);
at91_set_A_periph(AT91_PIN_PA22, 1);
at91_set_A_periph(AT91_PIN_PA23, 1);
if (data->slot[0].bus_width == 4) {
at91_set_A_periph(AT91_PIN_PA24, 1);
at91_set_A_periph(AT91_PIN_PA25, 1);
at91_set_A_periph(AT91_PIN_PA26, 1);
if (data->slot[0].bus_width == 8) {
at91_set_A_periph(AT91_PIN_PA27, 1);
at91_set_A_periph(AT91_PIN_PA28, 1);
at91_set_A_periph(AT91_PIN_PA29, 1);
at91_set_A_periph(AT91_PIN_PA30, 1);
}
}
mmc1_data = *data;
platform_device_register(&at91sam9g45_mmc1_device);
}
}
void __init at91_add_device_mci(short mmc_id, struct mci_platform_data *data) {}
void __init at91_add_device_nand(struct atmel_nand_data *data)
{
unsigned long csa;
if (!data)
return;
csa = at91_matrix_read(AT91_MATRIX_EBICSA);
at91_matrix_write(AT91_MATRIX_EBICSA, csa | AT91_MATRIX_EBI_CS3A_SMC_SMARTMEDIA);
if (gpio_is_valid(data->enable_pin))
at91_set_gpio_output(data->enable_pin, 1);
if (gpio_is_valid(data->rdy_pin))
at91_set_gpio_input(data->rdy_pin, 1);
if (gpio_is_valid(data->det_pin))
at91_set_gpio_input(data->det_pin, 1);
nand_data = *data;
platform_device_register(&at91sam9g45_nand_device);
}
void __init at91_add_device_nand(struct atmel_nand_data *data) {}
void __init at91_add_device_i2c(short i2c_id, struct i2c_board_info *devices, int nr_devices)
{
i2c_register_board_info(i2c_id, devices, nr_devices);
if (i2c_id == 0) {
at91_set_GPIO_periph(AT91_PIN_PA20, 1);
at91_set_multi_drive(AT91_PIN_PA20, 1);
at91_set_GPIO_periph(AT91_PIN_PA21, 1);
at91_set_multi_drive(AT91_PIN_PA21, 1);
platform_device_register(&at91sam9g45_twi0_device);
} else {
at91_set_GPIO_periph(AT91_PIN_PB10, 1);
at91_set_multi_drive(AT91_PIN_PB10, 1);
at91_set_GPIO_periph(AT91_PIN_PB11, 1);
at91_set_multi_drive(AT91_PIN_PB11, 1);
platform_device_register(&at91sam9g45_twi1_device);
}
}
void __init at91_add_device_i2c(short i2c_id, struct i2c_board_info *devices, int nr_devices)
{
i2c_register_board_info(i2c_id, devices, nr_devices);
if (i2c_id == 0) {
at91_set_A_periph(AT91_PIN_PA20, 0);
at91_set_A_periph(AT91_PIN_PA21, 0);
platform_device_register(&at91sam9g45_twi0_device);
} else {
at91_set_A_periph(AT91_PIN_PB10, 0);
at91_set_A_periph(AT91_PIN_PB11, 0);
platform_device_register(&at91sam9g45_twi1_device);
}
}
void __init at91_add_device_i2c(short i2c_id, struct i2c_board_info *devices, int nr_devices) {}
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
at91_set_A_periph(AT91_PIN_PB0, 0);
at91_set_A_periph(AT91_PIN_PB1, 0);
at91_set_A_periph(AT91_PIN_PB2, 0);
platform_device_register(&at91sam9g45_spi0_device);
}
if (enable_spi1) {
at91_set_A_periph(AT91_PIN_PB14, 0);
at91_set_A_periph(AT91_PIN_PB15, 0);
at91_set_A_periph(AT91_PIN_PB16, 0);
platform_device_register(&at91sam9g45_spi1_device);
}
}
void __init at91_add_device_spi(struct spi_board_info *devices, int nr_devices) {}
void __init at91_add_device_ac97(struct ac97c_platform_data *data)
{
if (!data)
return;
at91_set_A_periph(AT91_PIN_PD8, 0);
at91_set_A_periph(AT91_PIN_PD9, 0);
at91_set_A_periph(AT91_PIN_PD7, 0);
at91_set_A_periph(AT91_PIN_PD6, 0);
if (gpio_is_valid(data->reset_pin))
at91_set_gpio_output(data->reset_pin, 0);
ac97_data = *data;
platform_device_register(&at91sam9g45_ac97_device);
}
void __init at91_add_device_ac97(struct ac97c_platform_data *data) {}
void __init at91_add_device_isi(struct isi_platform_data *data,
bool use_pck_as_mck)
{
struct clk *pck;
struct clk *parent;
if (!data)
return;
isi_data = *data;
at91_set_A_periph(AT91_PIN_PB20, 0);
at91_set_A_periph(AT91_PIN_PB21, 0);
at91_set_A_periph(AT91_PIN_PB22, 0);
at91_set_A_periph(AT91_PIN_PB23, 0);
at91_set_A_periph(AT91_PIN_PB24, 0);
at91_set_A_periph(AT91_PIN_PB25, 0);
at91_set_A_periph(AT91_PIN_PB26, 0);
at91_set_A_periph(AT91_PIN_PB27, 0);
at91_set_A_periph(AT91_PIN_PB28, 0);
at91_set_A_periph(AT91_PIN_PB30, 0);
at91_set_A_periph(AT91_PIN_PB29, 0);
at91_set_B_periph(AT91_PIN_PB8, 0);
at91_set_B_periph(AT91_PIN_PB9, 0);
at91_set_B_periph(AT91_PIN_PB10, 0);
at91_set_B_periph(AT91_PIN_PB11, 0);
platform_device_register(&at91sam9g45_isi_device);
if (use_pck_as_mck) {
at91_set_B_periph(AT91_PIN_PB31, 0);
pck = clk_get(NULL, "pck1");
parent = clk_get(NULL, "plla");
BUG_ON(IS_ERR(pck) || IS_ERR(parent));
if (clk_set_parent(pck, parent)) {
pr_err("Failed to set PCK's parent\n");
} else {
isi_mck_lookups[0].clk = pck;
clkdev_add_table(isi_mck_lookups,
ARRAY_SIZE(isi_mck_lookups));
}
clk_put(pck);
clk_put(parent);
}
}
void __init at91_add_device_isi(struct isi_platform_data *data,
bool use_pck_as_mck) {}
void __init at91_add_device_lcdc(struct atmel_lcdfb_info *data)
{
if (!data)
return;
if (cpu_is_at91sam9g45es())
at91_lcdc_device.name = "at91sam9g45es-lcdfb";
else
at91_lcdc_device.name = "at91sam9g45-lcdfb";
at91_set_A_periph(AT91_PIN_PE0, 0);
at91_set_A_periph(AT91_PIN_PE2, 0);
at91_set_A_periph(AT91_PIN_PE3, 0);
at91_set_A_periph(AT91_PIN_PE4, 0);
at91_set_A_periph(AT91_PIN_PE5, 0);
at91_set_A_periph(AT91_PIN_PE6, 0);
at91_set_A_periph(AT91_PIN_PE7, 0);
at91_set_A_periph(AT91_PIN_PE8, 0);
at91_set_A_periph(AT91_PIN_PE9, 0);
at91_set_A_periph(AT91_PIN_PE10, 0);
at91_set_A_periph(AT91_PIN_PE11, 0);
at91_set_A_periph(AT91_PIN_PE12, 0);
at91_set_A_periph(AT91_PIN_PE13, 0);
at91_set_A_periph(AT91_PIN_PE14, 0);
at91_set_A_periph(AT91_PIN_PE15, 0);
at91_set_A_periph(AT91_PIN_PE16, 0);
at91_set_A_periph(AT91_PIN_PE17, 0);
at91_set_A_periph(AT91_PIN_PE18, 0);
at91_set_A_periph(AT91_PIN_PE19, 0);
at91_set_A_periph(AT91_PIN_PE20, 0);
at91_set_A_periph(AT91_PIN_PE21, 0);
at91_set_A_periph(AT91_PIN_PE22, 0);
at91_set_A_periph(AT91_PIN_PE23, 0);
at91_set_A_periph(AT91_PIN_PE24, 0);
at91_set_A_periph(AT91_PIN_PE25, 0);
at91_set_A_periph(AT91_PIN_PE26, 0);
at91_set_A_periph(AT91_PIN_PE27, 0);
at91_set_A_periph(AT91_PIN_PE28, 0);
at91_set_A_periph(AT91_PIN_PE29, 0);
at91_set_A_periph(AT91_PIN_PE30, 0);
lcdc_data = *data;
platform_device_register(&at91_lcdc_device);
}
void __init at91_add_device_lcdc(struct atmel_lcdfb_info *data) {}
static void __init at91_add_device_tc(void)
{
platform_device_register(&at91sam9g45_tcb0_device);
platform_device_register(&at91sam9g45_tcb1_device);
}
static void __init at91_add_device_tc(void) { }
static void __init at91_add_device_rtc(void)
{
platform_device_register(&at91sam9g45_rtc_device);
}
static void __init at91_add_device_rtc(void) {}
void __init at91_add_device_tsadcc(struct at91_tsadcc_data *data)
{
if (!data)
return;
at91_set_gpio_input(AT91_PIN_PD20, 0);
at91_set_gpio_input(AT91_PIN_PD21, 0);
at91_set_gpio_input(AT91_PIN_PD22, 0);
at91_set_gpio_input(AT91_PIN_PD23, 0);
tsadcc_data = *data;
platform_device_register(&at91sam9g45_tsadcc_device);
}
void __init at91_add_device_tsadcc(struct at91_tsadcc_data *data) {}
void __init at91_add_device_adc(struct at91_adc_data *data)
{
if (!data)
return;
if (test_bit(0, &data->channels_used))
at91_set_gpio_input(AT91_PIN_PD20, 0);
if (test_bit(1, &data->channels_used))
at91_set_gpio_input(AT91_PIN_PD21, 0);
if (test_bit(2, &data->channels_used))
at91_set_gpio_input(AT91_PIN_PD22, 0);
if (test_bit(3, &data->channels_used))
at91_set_gpio_input(AT91_PIN_PD23, 0);
if (test_bit(4, &data->channels_used))
at91_set_gpio_input(AT91_PIN_PD24, 0);
if (test_bit(5, &data->channels_used))
at91_set_gpio_input(AT91_PIN_PD25, 0);
if (test_bit(6, &data->channels_used))
at91_set_gpio_input(AT91_PIN_PD26, 0);
if (test_bit(7, &data->channels_used))
at91_set_gpio_input(AT91_PIN_PD27, 0);
if (data->use_external_triggers)
at91_set_A_periph(AT91_PIN_PD28, 0);
data->num_channels = 8;
data->startup_time = 40;
data->registers = &at91_adc_register_g45;
data->trigger_number = 4;
data->trigger_list = at91_adc_triggers;
adc_data = *data;
platform_device_register(&at91_adc_device);
}
void __init at91_add_device_adc(struct at91_adc_data *data) {}
static void __init at91_add_device_rtt_rtc(void)
{
at91sam9g45_rtt_device.name = "rtc-at91sam9";
at91sam9g45_rtt_device.num_resources = 3;
rtt_resources[1].start = AT91SAM9G45_BASE_GPBR +
4 * CONFIG_RTC_DRV_AT91SAM9_GPBR;
rtt_resources[1].end = rtt_resources[1].start + 3;
rtt_resources[2].start = NR_IRQS_LEGACY + AT91_ID_SYS;
rtt_resources[2].end = NR_IRQS_LEGACY + AT91_ID_SYS;
}
static void __init at91_add_device_rtt_rtc(void)
{
at91sam9g45_rtt_device.num_resources = 1;
}
static void __init at91_add_device_rtt(void)
{
at91_add_device_rtt_rtc();
platform_device_register(&at91sam9g45_rtt_device);
}
static void __init at91_add_device_trng(void)
{
platform_device_register(&at91sam9g45_trng_device);
}
static void __init at91_add_device_trng(void) {}
static void __init at91_add_device_watchdog(void)
{
platform_device_register(&at91sam9g45_wdt_device);
}
static void __init at91_add_device_watchdog(void) {}
void __init at91_add_device_pwm(u32 mask)
{
if (mask & (1 << AT91_PWM0))
at91_set_B_periph(AT91_PIN_PD24, 1);
if (mask & (1 << AT91_PWM1))
at91_set_B_periph(AT91_PIN_PD31, 1);
if (mask & (1 << AT91_PWM2))
at91_set_B_periph(AT91_PIN_PD26, 1);
if (mask & (1 << AT91_PWM3))
at91_set_B_periph(AT91_PIN_PD0, 1);
pwm_mask = mask;
platform_device_register(&at91sam9g45_pwm0_device);
}
void __init at91_add_device_pwm(u32 mask) {}
static inline void configure_ssc0_pins(unsigned pins)
{
if (pins & ATMEL_SSC_TF)
at91_set_A_periph(AT91_PIN_PD1, 1);
if (pins & ATMEL_SSC_TK)
at91_set_A_periph(AT91_PIN_PD0, 1);
if (pins & ATMEL_SSC_TD)
at91_set_A_periph(AT91_PIN_PD2, 1);
if (pins & ATMEL_SSC_RD)
at91_set_A_periph(AT91_PIN_PD3, 1);
if (pins & ATMEL_SSC_RK)
at91_set_A_periph(AT91_PIN_PD4, 1);
if (pins & ATMEL_SSC_RF)
at91_set_A_periph(AT91_PIN_PD5, 1);
}
static inline void configure_ssc1_pins(unsigned pins)
{
if (pins & ATMEL_SSC_TF)
at91_set_A_periph(AT91_PIN_PD14, 1);
if (pins & ATMEL_SSC_TK)
at91_set_A_periph(AT91_PIN_PD12, 1);
if (pins & ATMEL_SSC_TD)
at91_set_A_periph(AT91_PIN_PD10, 1);
if (pins & ATMEL_SSC_RD)
at91_set_A_periph(AT91_PIN_PD11, 1);
if (pins & ATMEL_SSC_RK)
at91_set_A_periph(AT91_PIN_PD13, 1);
if (pins & ATMEL_SSC_RF)
at91_set_A_periph(AT91_PIN_PD15, 1);
}
void __init at91_add_device_ssc(unsigned id, unsigned pins)
{
struct platform_device *pdev;
switch (id) {
case AT91SAM9G45_ID_SSC0:
pdev = &at91sam9g45_ssc0_device;
configure_ssc0_pins(pins);
break;
case AT91SAM9G45_ID_SSC1:
pdev = &at91sam9g45_ssc1_device;
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
at91_set_A_periph(AT91_PIN_PB12, 0);
at91_set_A_periph(AT91_PIN_PB13, 1);
}
static inline void configure_usart0_pins(unsigned pins)
{
at91_set_A_periph(AT91_PIN_PB19, 1);
at91_set_A_periph(AT91_PIN_PB18, 0);
if (pins & ATMEL_UART_RTS)
at91_set_B_periph(AT91_PIN_PB17, 0);
if (pins & ATMEL_UART_CTS)
at91_set_B_periph(AT91_PIN_PB15, 0);
}
static inline void configure_usart1_pins(unsigned pins)
{
at91_set_A_periph(AT91_PIN_PB4, 1);
at91_set_A_periph(AT91_PIN_PB5, 0);
if (pins & ATMEL_UART_RTS)
at91_set_A_periph(AT91_PIN_PD16, 0);
if (pins & ATMEL_UART_CTS)
at91_set_A_periph(AT91_PIN_PD17, 0);
}
static inline void configure_usart2_pins(unsigned pins)
{
at91_set_A_periph(AT91_PIN_PB6, 1);
at91_set_A_periph(AT91_PIN_PB7, 0);
if (pins & ATMEL_UART_RTS)
at91_set_B_periph(AT91_PIN_PC9, 0);
if (pins & ATMEL_UART_CTS)
at91_set_B_periph(AT91_PIN_PC11, 0);
}
static inline void configure_usart3_pins(unsigned pins)
{
at91_set_A_periph(AT91_PIN_PB8, 1);
at91_set_A_periph(AT91_PIN_PB9, 0);
if (pins & ATMEL_UART_RTS)
at91_set_B_periph(AT91_PIN_PA23, 0);
if (pins & ATMEL_UART_CTS)
at91_set_B_periph(AT91_PIN_PA24, 0);
}
void __init at91_register_uart(unsigned id, unsigned portnr, unsigned pins)
{
struct platform_device *pdev;
struct atmel_uart_data *pdata;
switch (id) {
case 0:
pdev = &at91sam9g45_dbgu_device;
configure_dbgu_pins();
break;
case AT91SAM9G45_ID_US0:
pdev = &at91sam9g45_uart0_device;
configure_usart0_pins(pins);
break;
case AT91SAM9G45_ID_US1:
pdev = &at91sam9g45_uart1_device;
configure_usart1_pins(pins);
break;
case AT91SAM9G45_ID_US2:
pdev = &at91sam9g45_uart2_device;
configure_usart2_pins(pins);
break;
case AT91SAM9G45_ID_US3:
pdev = &at91sam9g45_uart3_device;
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
static void __init at91_add_device_sha(void)
{
platform_device_register(&at91sam9g45_sha_device);
}
static void __init at91_add_device_sha(void) {}
static void __init at91_add_device_tdes(void)
{
platform_device_register(&at91sam9g45_tdes_device);
}
static void __init at91_add_device_tdes(void) {}
static void __init at91_add_device_aes(void)
{
struct at_dma_slave *atslave;
atslave = &alt_atslave.txdata;
atslave->dma_dev = &at_hdmac_device.dev;
atslave->cfg = ATC_FIFOCFG_ENOUGHSPACE | ATC_SRC_H2SEL_HW |
ATC_SRC_PER(AT_DMA_ID_AES_RX);
atslave = &alt_atslave.rxdata;
atslave->dma_dev = &at_hdmac_device.dev;
atslave->cfg = ATC_FIFOCFG_ENOUGHSPACE | ATC_DST_H2SEL_HW |
ATC_DST_PER(AT_DMA_ID_AES_TX);
aes_data.dma_slave = &alt_atslave;
platform_device_register(&at91sam9g45_aes_device);
}
static void __init at91_add_device_aes(void) {}
static int __init at91_add_standard_devices(void)
{
if (of_have_populated_dt())
return 0;
at91_add_device_hdmac();
at91_add_device_rtc();
at91_add_device_rtt();
at91_add_device_trng();
at91_add_device_watchdog();
at91_add_device_tc();
at91_add_device_sha();
at91_add_device_tdes();
at91_add_device_aes();
return 0;
}
