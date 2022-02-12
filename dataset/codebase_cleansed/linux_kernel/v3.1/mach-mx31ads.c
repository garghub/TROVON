static int __init mxc_init_extuart(void)
{
return platform_device_register(&serial_device);
}
static inline void mxc_init_imx_uart(void)
{
mxc_iomux_setup_multiple_pins(uart_pins, ARRAY_SIZE(uart_pins), "uart-0");
imx31_add_imx_uart0(&uart_pdata);
}
static void mx31ads_expio_irq_handler(u32 irq, struct irq_desc *desc)
{
u32 imr_val;
u32 int_valid;
u32 expio_irq;
imr_val = __raw_readw(PBC_INTMASK_SET_REG);
int_valid = __raw_readw(PBC_INTSTATUS_REG) & imr_val;
expio_irq = MXC_EXP_IO_BASE;
for (; int_valid != 0; int_valid >>= 1, expio_irq++) {
if ((int_valid & 1) == 0)
continue;
generic_handle_irq(expio_irq);
}
}
static void expio_mask_irq(struct irq_data *d)
{
u32 expio = MXC_IRQ_TO_EXPIO(d->irq);
__raw_writew(1 << expio, PBC_INTMASK_CLEAR_REG);
__raw_readw(PBC_INTMASK_CLEAR_REG);
}
static void expio_ack_irq(struct irq_data *d)
{
u32 expio = MXC_IRQ_TO_EXPIO(d->irq);
__raw_writew(1 << expio, PBC_INTSTATUS_REG);
}
static void expio_unmask_irq(struct irq_data *d)
{
u32 expio = MXC_IRQ_TO_EXPIO(d->irq);
__raw_writew(1 << expio, PBC_INTMASK_SET_REG);
}
static void __init mx31ads_init_expio(void)
{
int i;
printk(KERN_INFO "MX31ADS EXPIO(CPLD) hardware\n");
mxc_iomux_alloc_pin(IOMUX_MODE(MX31_PIN_GPIO1_4, IOMUX_CONFIG_GPIO), "expio");
__raw_writew(0xFFFF, PBC_INTMASK_CLEAR_REG);
__raw_writew(0xFFFF, PBC_INTSTATUS_REG);
for (i = MXC_EXP_IO_BASE; i < (MXC_EXP_IO_BASE + MXC_MAX_EXP_IO_LINES);
i++) {
irq_set_chip_and_handler(i, &expio_irq_chip, handle_level_irq);
set_irq_flags(i, IRQF_VALID);
}
irq_set_irq_type(EXPIO_PARENT_INT, IRQ_TYPE_LEVEL_HIGH);
irq_set_chained_handler(EXPIO_PARENT_INT, mx31ads_expio_irq_handler);
}
static int mx31_wm8350_init(struct wm8350 *wm8350)
{
wm8350_gpio_config(wm8350, 0, WM8350_GPIO_DIR_IN,
WM8350_GPIO0_PWR_ON_IN, WM8350_GPIO_ACTIVE_LOW,
WM8350_GPIO_PULL_UP, WM8350_GPIO_INVERT_OFF,
WM8350_GPIO_DEBOUNCE_ON);
wm8350_gpio_config(wm8350, 3, WM8350_GPIO_DIR_IN,
WM8350_GPIO3_PWR_OFF_IN, WM8350_GPIO_ACTIVE_HIGH,
WM8350_GPIO_PULL_DOWN, WM8350_GPIO_INVERT_OFF,
WM8350_GPIO_DEBOUNCE_ON);
wm8350_gpio_config(wm8350, 4, WM8350_GPIO_DIR_IN,
WM8350_GPIO4_MR_IN, WM8350_GPIO_ACTIVE_HIGH,
WM8350_GPIO_PULL_DOWN, WM8350_GPIO_INVERT_OFF,
WM8350_GPIO_DEBOUNCE_OFF);
wm8350_gpio_config(wm8350, 7, WM8350_GPIO_DIR_IN,
WM8350_GPIO7_HIBERNATE_IN, WM8350_GPIO_ACTIVE_HIGH,
WM8350_GPIO_PULL_DOWN, WM8350_GPIO_INVERT_OFF,
WM8350_GPIO_DEBOUNCE_OFF);
wm8350_gpio_config(wm8350, 6, WM8350_GPIO_DIR_OUT,
WM8350_GPIO6_SDOUT_OUT, WM8350_GPIO_ACTIVE_HIGH,
WM8350_GPIO_PULL_NONE, WM8350_GPIO_INVERT_OFF,
WM8350_GPIO_DEBOUNCE_OFF);
wm8350_gpio_config(wm8350, 8, WM8350_GPIO_DIR_OUT,
WM8350_GPIO8_VCC_FAULT_OUT, WM8350_GPIO_ACTIVE_LOW,
WM8350_GPIO_PULL_NONE, WM8350_GPIO_INVERT_OFF,
WM8350_GPIO_DEBOUNCE_OFF);
wm8350_gpio_config(wm8350, 9, WM8350_GPIO_DIR_OUT,
WM8350_GPIO9_BATT_FAULT_OUT, WM8350_GPIO_ACTIVE_LOW,
WM8350_GPIO_PULL_NONE, WM8350_GPIO_INVERT_OFF,
WM8350_GPIO_DEBOUNCE_OFF);
wm8350_register_regulator(wm8350, WM8350_DCDC_1, &sw1a_data);
wm8350_register_regulator(wm8350, WM8350_DCDC_3, &viohi_data);
wm8350_register_regulator(wm8350, WM8350_DCDC_4, &violo_data);
wm8350_register_regulator(wm8350, WM8350_DCDC_6, &sw2a_data);
wm8350_register_regulator(wm8350, WM8350_LDO_1, &ldo1_data);
wm8350_register_regulator(wm8350, WM8350_LDO_2, &ldo2_data);
wm8350_register_regulator(wm8350, WM8350_LDO_3, &vdig_data);
wm8350_register_regulator(wm8350, WM8350_LDO_4, &ldo4_data);
wm8350_dcdc_set_slot(wm8350, WM8350_DCDC_5, 1, 1,
WM8350_DC5_ERRACT_SHUTDOWN_CONV);
wm8350_isink_set_flash(wm8350, WM8350_ISINK_A,
WM8350_ISINK_FLASH_DISABLE,
WM8350_ISINK_FLASH_TRIG_BIT,
WM8350_ISINK_FLASH_DUR_32MS,
WM8350_ISINK_FLASH_ON_INSTANT,
WM8350_ISINK_FLASH_OFF_INSTANT,
WM8350_ISINK_FLASH_MODE_EN);
wm8350_dcdc25_set_mode(wm8350, WM8350_DCDC_5,
WM8350_ISINK_MODE_BOOST,
WM8350_ISINK_ILIM_NORMAL,
WM8350_DC5_RMP_20V,
WM8350_DC5_FBSRC_ISINKA);
wm8350_register_led(wm8350, 0, WM8350_DCDC_5, WM8350_ISINK_A,
&wm8350_led_data);
wm8350->codec.platform_data = &imx32ads_wm8350_setup;
regulator_has_full_constraints();
return 0;
}
static void __init mxc_init_i2c(void)
{
i2c_register_board_info(1, mx31ads_i2c1_devices,
ARRAY_SIZE(mx31ads_i2c1_devices));
mxc_iomux_mode(IOMUX_MODE(MX31_PIN_CSPI2_MOSI, IOMUX_CONFIG_ALT1));
mxc_iomux_mode(IOMUX_MODE(MX31_PIN_CSPI2_MISO, IOMUX_CONFIG_ALT1));
imx31_add_imx_i2c1(NULL);
}
static void __init mxc_init_audio(void)
{
imx31_add_imx_ssi(0, NULL);
mxc_iomux_setup_multiple_pins(ssi_pins, ARRAY_SIZE(ssi_pins), "ssi");
}
static void __init mx31ads_map_io(void)
{
mx31_map_io();
iotable_init(mx31ads_io_desc, ARRAY_SIZE(mx31ads_io_desc));
}
static void __init mx31ads_init_irq(void)
{
mx31_init_irq();
mx31ads_init_expio();
}
static void __init mx31ads_init(void)
{
imx31_soc_init();
mxc_init_extuart();
mxc_init_imx_uart();
mxc_init_i2c();
mxc_init_audio();
}
static void __init mx31ads_timer_init(void)
{
mx31_clocks_init(26000000);
}
