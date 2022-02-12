void __init at91_add_device_usbh(struct at91_usbh_data *data)
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
at91_set_A_periph(AT91_PIN_PE21, 0);
at91_set_B_periph(AT91_PIN_PC25, 0);
at91_set_A_periph(AT91_PIN_PE25, 0);
at91_set_A_periph(AT91_PIN_PE26, 0);
at91_set_A_periph(AT91_PIN_PE27, 0);
at91_set_A_periph(AT91_PIN_PE28, 0);
at91_set_A_periph(AT91_PIN_PE23, 0);
at91_set_A_periph(AT91_PIN_PE24, 0);
at91_set_A_periph(AT91_PIN_PE30, 0);
at91_set_A_periph(AT91_PIN_PE29, 0);
if (!data->is_rmii) {
at91_set_A_periph(AT91_PIN_PE22, 0);
at91_set_B_periph(AT91_PIN_PC26, 0);
at91_set_B_periph(AT91_PIN_PC22, 0);
at91_set_B_periph(AT91_PIN_PC23, 0);
at91_set_B_periph(AT91_PIN_PC27, 0);
at91_set_B_periph(AT91_PIN_PC20, 0);
at91_set_B_periph(AT91_PIN_PC21, 0);
at91_set_B_periph(AT91_PIN_PC24, 0);
}
eth_data = *data;
platform_device_register(&at91sam9263_eth_device);
}
void __init at91_add_device_eth(struct macb_platform_data *data) {}
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
at91_set_gpio_input(data->slot[i].detect_pin,
1);
at91_set_deglitch(data->slot[i].detect_pin,
1);
}
if (gpio_is_valid(data->slot[i].wp_pin))
at91_set_gpio_input(data->slot[i].wp_pin, 1);
if (mmc_id == 0) {
switch (i) {
case 0:
at91_set_A_periph(AT91_PIN_PA1, 1);
at91_set_A_periph(AT91_PIN_PA0, 1);
if (data->slot[i].bus_width == 4) {
at91_set_A_periph(AT91_PIN_PA3, 1);
at91_set_A_periph(AT91_PIN_PA4, 1);
at91_set_A_periph(AT91_PIN_PA5, 1);
}
slot_count++;
break;
case 1:
at91_set_A_periph(AT91_PIN_PA16, 1);
at91_set_A_periph(AT91_PIN_PA17, 1);
if (data->slot[i].bus_width == 4) {
at91_set_A_periph(AT91_PIN_PA18, 1);
at91_set_A_periph(AT91_PIN_PA19, 1);
at91_set_A_periph(AT91_PIN_PA20, 1);
}
slot_count++;
break;
default:
printk(KERN_ERR
"AT91: SD/MMC slot %d not available\n", i);
break;
}
if (slot_count) {
at91_set_A_periph(AT91_PIN_PA12, 0);
mmc0_data = *data;
platform_device_register(&at91sam9263_mmc0_device);
}
} else if (mmc_id == 1) {
switch (i) {
case 0:
at91_set_A_periph(AT91_PIN_PA7, 1);
at91_set_A_periph(AT91_PIN_PA8, 1);
if (data->slot[i].bus_width == 4) {
at91_set_A_periph(AT91_PIN_PA9, 1);
at91_set_A_periph(AT91_PIN_PA10, 1);
at91_set_A_periph(AT91_PIN_PA11, 1);
}
slot_count++;
break;
case 1:
at91_set_A_periph(AT91_PIN_PA21, 1);
at91_set_A_periph(AT91_PIN_PA22, 1);
if (data->slot[i].bus_width == 4) {
at91_set_A_periph(AT91_PIN_PA23, 1);
at91_set_A_periph(AT91_PIN_PA24, 1);
at91_set_A_periph(AT91_PIN_PA25, 1);
}
slot_count++;
break;
default:
printk(KERN_ERR
"AT91: SD/MMC slot %d not available\n", i);
break;
}
if (slot_count) {
at91_set_A_periph(AT91_PIN_PA6, 0);
mmc1_data = *data;
platform_device_register(&at91sam9263_mmc1_device);
}
}
}
}
void __init at91_add_device_mci(short mmc_id, struct mci_platform_data *data) {}
void __init at91_add_device_cf(struct at91_cf_data *data)
{
unsigned long ebi0_csa;
struct platform_device *pdev;
if (!data)
return;
ebi0_csa = at91_matrix_read(AT91_MATRIX_EBI0CSA);
switch (data->chipselect) {
case 4:
at91_set_A_periph(AT91_PIN_PD6, 0);
ebi0_csa |= AT91_MATRIX_EBI0_CS4A_SMC_CF1;
cf0_data = *data;
pdev = &cf0_device;
break;
case 5:
at91_set_A_periph(AT91_PIN_PD7, 0);
ebi0_csa |= AT91_MATRIX_EBI0_CS5A_SMC_CF2;
cf1_data = *data;
pdev = &cf1_device;
break;
default:
printk(KERN_ERR "AT91 CF: bad chip-select requested (%u)\n",
data->chipselect);
return;
}
at91_matrix_write(AT91_MATRIX_EBI0CSA, ebi0_csa);
if (gpio_is_valid(data->det_pin)) {
at91_set_gpio_input(data->det_pin, 1);
at91_set_deglitch(data->det_pin, 1);
}
if (gpio_is_valid(data->irq_pin)) {
at91_set_gpio_input(data->irq_pin, 1);
at91_set_deglitch(data->irq_pin, 1);
}
if (gpio_is_valid(data->vcc_pin))
at91_set_gpio_output(data->vcc_pin, 0);
at91_set_A_periph(AT91_PIN_PD5, 1);
at91_set_A_periph(AT91_PIN_PD8, 0);
at91_set_A_periph(AT91_PIN_PD9, 0);
at91_set_A_periph(AT91_PIN_PD14, 0);
pdev->name = (data->flags & AT91_CF_TRUE_IDE) ? "pata_at91" : "at91_cf";
platform_device_register(pdev);
}
void __init at91_add_device_cf(struct at91_cf_data *data) {}
void __init at91_add_device_nand(struct atmel_nand_data *data)
{
unsigned long csa;
if (!data)
return;
csa = at91_matrix_read(AT91_MATRIX_EBI0CSA);
at91_matrix_write(AT91_MATRIX_EBI0CSA, csa | AT91_MATRIX_EBI0_CS3A_SMC_SMARTMEDIA);
if (gpio_is_valid(data->enable_pin))
at91_set_gpio_output(data->enable_pin, 1);
if (gpio_is_valid(data->rdy_pin))
at91_set_gpio_input(data->rdy_pin, 1);
if (gpio_is_valid(data->det_pin))
at91_set_gpio_input(data->det_pin, 1);
nand_data = *data;
platform_device_register(&at91sam9263_nand_device);
}
void __init at91_add_device_nand(struct atmel_nand_data *data) {}
void __init at91_add_device_i2c(struct i2c_board_info *devices, int nr_devices)
{
at91_set_GPIO_periph(AT91_PIN_PB4, 1);
at91_set_multi_drive(AT91_PIN_PB4, 1);
at91_set_GPIO_periph(AT91_PIN_PB5, 1);
at91_set_multi_drive(AT91_PIN_PB5, 1);
i2c_register_board_info(0, devices, nr_devices);
platform_device_register(&at91sam9263_twi_device);
}
void __init at91_add_device_i2c(struct i2c_board_info *devices, int nr_devices)
{
at91_set_A_periph(AT91_PIN_PB4, 0);
at91_set_multi_drive(AT91_PIN_PB4, 1);
at91_set_A_periph(AT91_PIN_PB5, 0);
at91_set_multi_drive(AT91_PIN_PB5, 1);
i2c_register_board_info(0, devices, nr_devices);
platform_device_register(&at91sam9263_twi_device);
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
at91_set_B_periph(AT91_PIN_PA0, 0);
at91_set_B_periph(AT91_PIN_PA1, 0);
at91_set_B_periph(AT91_PIN_PA2, 0);
platform_device_register(&at91sam9263_spi0_device);
}
if (enable_spi1) {
at91_set_A_periph(AT91_PIN_PB12, 0);
at91_set_A_periph(AT91_PIN_PB13, 0);
at91_set_A_periph(AT91_PIN_PB14, 0);
platform_device_register(&at91sam9263_spi1_device);
}
}
void __init at91_add_device_spi(struct spi_board_info *devices, int nr_devices) {}
void __init at91_add_device_ac97(struct ac97c_platform_data *data)
{
if (!data)
return;
at91_set_A_periph(AT91_PIN_PB0, 0);
at91_set_A_periph(AT91_PIN_PB1, 0);
at91_set_A_periph(AT91_PIN_PB2, 0);
at91_set_A_periph(AT91_PIN_PB3, 0);
if (gpio_is_valid(data->reset_pin))
at91_set_gpio_output(data->reset_pin, 0);
ac97_data = *data;
platform_device_register(&at91sam9263_ac97_device);
}
void __init at91_add_device_ac97(struct ac97c_platform_data *data) {}
void __init at91_add_device_can(struct at91_can_data *data)
{
at91_set_A_periph(AT91_PIN_PA13, 0);
at91_set_A_periph(AT91_PIN_PA14, 0);
at91sam9263_can_device.dev.platform_data = data;
platform_device_register(&at91sam9263_can_device);
}
void __init at91_add_device_can(struct at91_can_data *data) {}
void __init at91_add_device_lcdc(struct atmel_lcdfb_info *data)
{
if (!data)
return;
at91_set_A_periph(AT91_PIN_PC1, 0);
at91_set_A_periph(AT91_PIN_PC2, 0);
at91_set_A_periph(AT91_PIN_PC3, 0);
at91_set_B_periph(AT91_PIN_PB9, 0);
at91_set_A_periph(AT91_PIN_PC6, 0);
at91_set_A_periph(AT91_PIN_PC7, 0);
at91_set_A_periph(AT91_PIN_PC8, 0);
at91_set_A_periph(AT91_PIN_PC9, 0);
at91_set_A_periph(AT91_PIN_PC10, 0);
at91_set_A_periph(AT91_PIN_PC11, 0);
at91_set_A_periph(AT91_PIN_PC14, 0);
at91_set_A_periph(AT91_PIN_PC15, 0);
at91_set_A_periph(AT91_PIN_PC16, 0);
at91_set_B_periph(AT91_PIN_PC12, 0);
at91_set_A_periph(AT91_PIN_PC18, 0);
at91_set_A_periph(AT91_PIN_PC19, 0);
at91_set_A_periph(AT91_PIN_PC22, 0);
at91_set_A_periph(AT91_PIN_PC23, 0);
at91_set_A_periph(AT91_PIN_PC24, 0);
at91_set_B_periph(AT91_PIN_PC17, 0);
at91_set_A_periph(AT91_PIN_PC26, 0);
at91_set_A_periph(AT91_PIN_PC27, 0);
lcdc_data = *data;
platform_device_register(&at91_lcdc_device);
}
void __init at91_add_device_lcdc(struct atmel_lcdfb_info *data) {}
void __init at91_add_device_isi(struct isi_platform_data *data,
bool use_pck_as_mck)
{
at91_set_A_periph(AT91_PIN_PE0, 0);
at91_set_A_periph(AT91_PIN_PE1, 0);
at91_set_A_periph(AT91_PIN_PE2, 0);
at91_set_A_periph(AT91_PIN_PE3, 0);
at91_set_A_periph(AT91_PIN_PE4, 0);
at91_set_A_periph(AT91_PIN_PE5, 0);
at91_set_A_periph(AT91_PIN_PE6, 0);
at91_set_A_periph(AT91_PIN_PE7, 0);
at91_set_A_periph(AT91_PIN_PE8, 0);
at91_set_A_periph(AT91_PIN_PE9, 0);
at91_set_A_periph(AT91_PIN_PE10, 0);
at91_set_B_periph(AT91_PIN_PE12, 0);
at91_set_B_periph(AT91_PIN_PE13, 0);
at91_set_B_periph(AT91_PIN_PE14, 0);
at91_set_B_periph(AT91_PIN_PE15, 0);
if (use_pck_as_mck) {
at91_set_B_periph(AT91_PIN_PE11, 0);
}
}
void __init at91_add_device_isi(struct isi_platform_data *data,
bool use_pck_as_mck) {}
static void __init at91_add_device_tc(void)
{
#if defined(CONFIG_OF)
struct device_node *np;
np = of_find_matching_node(NULL, tcb_ids);
if (np) {
of_node_put(np);
return;
}
#endif
platform_device_register(&at91sam9263_tcb_device);
}
static void __init at91_add_device_tc(void) { }
static void __init at91_add_device_rtt_rtc(void)
{
struct platform_device *pdev;
struct resource *r;
switch (CONFIG_RTC_DRV_AT91SAM9_RTT) {
case 0:
at91sam9263_rtt0_device.num_resources = 3;
at91sam9263_rtt1_device.num_resources = 1;
pdev = &at91sam9263_rtt0_device;
r = rtt0_resources;
break;
case 1:
at91sam9263_rtt0_device.num_resources = 1;
at91sam9263_rtt1_device.num_resources = 3;
pdev = &at91sam9263_rtt1_device;
r = rtt1_resources;
break;
default:
pr_err("at91sam9263: only supports 2 RTT (%d)\n",
CONFIG_RTC_DRV_AT91SAM9_RTT);
return;
}
pdev->name = "rtc-at91sam9";
r[1].start = AT91SAM9263_BASE_GPBR + 4 * CONFIG_RTC_DRV_AT91SAM9_GPBR;
r[1].end = r[1].start + 3;
r[2].start = NR_IRQS_LEGACY + AT91_ID_SYS;
r[2].end = NR_IRQS_LEGACY + AT91_ID_SYS;
}
static void __init at91_add_device_rtt_rtc(void)
{
at91sam9263_rtt0_device.num_resources = 1;
at91sam9263_rtt1_device.num_resources = 1;
}
static void __init at91_add_device_rtt(void)
{
at91_add_device_rtt_rtc();
platform_device_register(&at91sam9263_rtt0_device);
platform_device_register(&at91sam9263_rtt1_device);
}
static void __init at91_add_device_watchdog(void)
{
platform_device_register(&at91sam9263_wdt_device);
}
static void __init at91_add_device_watchdog(void) {}
void __init at91_add_device_pwm(u32 mask)
{
if (mask & (1 << AT91_PWM0))
at91_set_B_periph(AT91_PIN_PB7, 1);
if (mask & (1 << AT91_PWM1))
at91_set_B_periph(AT91_PIN_PB8, 1);
if (mask & (1 << AT91_PWM2))
at91_set_B_periph(AT91_PIN_PC29, 1);
if (mask & (1 << AT91_PWM3))
at91_set_B_periph(AT91_PIN_PB29, 1);
pwm_mask = mask;
platform_device_register(&at91sam9263_pwm0_device);
}
void __init at91_add_device_pwm(u32 mask) {}
static inline void configure_ssc0_pins(unsigned pins)
{
if (pins & ATMEL_SSC_TF)
at91_set_B_periph(AT91_PIN_PB0, 1);
if (pins & ATMEL_SSC_TK)
at91_set_B_periph(AT91_PIN_PB1, 1);
if (pins & ATMEL_SSC_TD)
at91_set_B_periph(AT91_PIN_PB2, 1);
if (pins & ATMEL_SSC_RD)
at91_set_B_periph(AT91_PIN_PB3, 1);
if (pins & ATMEL_SSC_RK)
at91_set_B_periph(AT91_PIN_PB4, 1);
if (pins & ATMEL_SSC_RF)
at91_set_B_periph(AT91_PIN_PB5, 1);
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
void __init at91_add_device_ssc(unsigned id, unsigned pins)
{
struct platform_device *pdev;
switch (id) {
case AT91SAM9263_ID_SSC0:
pdev = &at91sam9263_ssc0_device;
configure_ssc0_pins(pins);
break;
case AT91SAM9263_ID_SSC1:
pdev = &at91sam9263_ssc1_device;
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
at91_set_A_periph(AT91_PIN_PC30, 0);
at91_set_A_periph(AT91_PIN_PC31, 1);
}
static inline void configure_usart0_pins(unsigned pins)
{
at91_set_A_periph(AT91_PIN_PA26, 1);
at91_set_A_periph(AT91_PIN_PA27, 0);
if (pins & ATMEL_UART_RTS)
at91_set_A_periph(AT91_PIN_PA28, 0);
if (pins & ATMEL_UART_CTS)
at91_set_A_periph(AT91_PIN_PA29, 0);
}
static inline void configure_usart1_pins(unsigned pins)
{
at91_set_A_periph(AT91_PIN_PD0, 1);
at91_set_A_periph(AT91_PIN_PD1, 0);
if (pins & ATMEL_UART_RTS)
at91_set_B_periph(AT91_PIN_PD7, 0);
if (pins & ATMEL_UART_CTS)
at91_set_B_periph(AT91_PIN_PD8, 0);
}
static inline void configure_usart2_pins(unsigned pins)
{
at91_set_A_periph(AT91_PIN_PD2, 1);
at91_set_A_periph(AT91_PIN_PD3, 0);
if (pins & ATMEL_UART_RTS)
at91_set_B_periph(AT91_PIN_PD5, 0);
if (pins & ATMEL_UART_CTS)
at91_set_B_periph(AT91_PIN_PD6, 0);
}
void __init at91_register_uart(unsigned id, unsigned portnr, unsigned pins)
{
struct platform_device *pdev;
struct atmel_uart_data *pdata;
switch (id) {
case 0:
pdev = &at91sam9263_dbgu_device;
configure_dbgu_pins();
break;
case AT91SAM9263_ID_US0:
pdev = &at91sam9263_uart0_device;
configure_usart0_pins(pins);
break;
case AT91SAM9263_ID_US1:
pdev = &at91sam9263_uart1_device;
configure_usart1_pins(pins);
break;
case AT91SAM9263_ID_US2:
pdev = &at91sam9263_uart2_device;
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
if (of_have_populated_dt())
return 0;
at91_add_device_rtt();
at91_add_device_watchdog();
at91_add_device_tc();
return 0;
}
