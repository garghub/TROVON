int balloon3_has(enum balloon3_features feature)
{
return (balloon3_features_present & (1 << feature)) ? 1 : 0;
}
int __init parse_balloon3_features(char *arg)
{
if (!arg)
return 0;
return kstrtoul(arg, 0, &balloon3_features_present);
}
static void __init balloon3_cf_init(void)
{
if (!balloon3_has(BALLOON3_FEATURE_CF))
return;
pxa2xx_mfp_config(ARRAY_AND_SIZE(balloon3_cf_pin_config));
}
static inline void balloon3_cf_init(void) {}
static void __init balloon3_nor_init(void)
{
platform_device_register(&balloon3_flash);
}
static inline void balloon3_nor_init(void) {}
static void __init balloon3_ts_init(void)
{
if (!balloon3_has(BALLOON3_FEATURE_AUDIO))
return;
pxa2xx_mfp_config(ARRAY_AND_SIZE(balloon3_ac97_pin_config));
pxa_set_ac97_info(NULL);
platform_device_register(&balloon3_ucb1400_device);
}
static inline void balloon3_ts_init(void) {}
static void balloon3_backlight_power(int on)
{
gpio_set_value(BALLOON3_GPIO_RUN_BACKLIGHT, on);
}
static void __init balloon3_lcd_init(void)
{
int ret;
if (!balloon3_has(BALLOON3_FEATURE_TOPPOLY))
return;
pxa2xx_mfp_config(ARRAY_AND_SIZE(balloon3_lcd_pin_config));
ret = gpio_request(BALLOON3_GPIO_RUN_BACKLIGHT, "BKL-ON");
if (ret) {
pr_err("Requesting BKL-ON GPIO failed!\n");
goto err;
}
ret = gpio_direction_output(BALLOON3_GPIO_RUN_BACKLIGHT, 1);
if (ret) {
pr_err("Setting BKL-ON GPIO direction failed!\n");
goto err2;
}
balloon3_lcd_screen.pxafb_backlight_power = balloon3_backlight_power;
pxa_set_fb_info(NULL, &balloon3_lcd_screen);
return;
err2:
gpio_free(BALLOON3_GPIO_RUN_BACKLIGHT);
err:
return;
}
static inline void balloon3_lcd_init(void) {}
static void __init balloon3_mmc_init(void)
{
pxa2xx_mfp_config(ARRAY_AND_SIZE(balloon3_mmc_pin_config));
pxa_set_mci_info(&balloon3_mci_platform_data);
}
static inline void balloon3_mmc_init(void) {}
static void balloon3_udc_command(int cmd)
{
if (cmd == PXA2XX_UDC_CMD_CONNECT)
UP2OCR |= UP2OCR_DPPUE | UP2OCR_DPPUBE;
else if (cmd == PXA2XX_UDC_CMD_DISCONNECT)
UP2OCR &= ~UP2OCR_DPPUE;
}
static int balloon3_udc_is_connected(void)
{
return 1;
}
static void __init balloon3_udc_init(void)
{
pxa_set_udc_info(&balloon3_udc_info);
}
static inline void balloon3_udc_init(void) {}
static void __init balloon3_irda_init(void)
{
pxa_set_ficp_info(&balloon3_ficp_platform_data);
}
static inline void balloon3_irda_init(void) {}
static void __init balloon3_uhc_init(void)
{
if (!balloon3_has(BALLOON3_FEATURE_OHCI))
return;
pxa2xx_mfp_config(ARRAY_AND_SIZE(balloon3_uhc_pin_config));
pxa_set_ohci_info(&balloon3_ohci_info);
}
static inline void balloon3_uhc_init(void) {}
static void __init balloon3_leds_init(void)
{
pxa2xx_mfp_config(ARRAY_AND_SIZE(balloon3_led_pin_config));
platform_device_register(&balloon3_leds);
platform_device_register(&balloon3_pcf_leds);
}
static inline void balloon3_leds_init(void) {}
static void balloon3_mask_irq(struct irq_data *d)
{
int balloon3_irq = (d->irq - BALLOON3_IRQ(0));
balloon3_irq_enabled &= ~(1 << balloon3_irq);
__raw_writel(~balloon3_irq_enabled, BALLOON3_INT_CONTROL_REG);
}
static void balloon3_unmask_irq(struct irq_data *d)
{
int balloon3_irq = (d->irq - BALLOON3_IRQ(0));
balloon3_irq_enabled |= (1 << balloon3_irq);
__raw_writel(~balloon3_irq_enabled, BALLOON3_INT_CONTROL_REG);
}
static void balloon3_irq_handler(unsigned int irq, struct irq_desc *desc)
{
unsigned long pending = __raw_readl(BALLOON3_INT_CONTROL_REG) &
balloon3_irq_enabled;
do {
if (desc->irq_data.chip->irq_ack) {
struct irq_data *d;
d = irq_get_irq_data(BALLOON3_AUX_NIRQ);
desc->irq_data.chip->irq_ack(d);
}
while (pending) {
irq = BALLOON3_IRQ(0) + __ffs(pending);
generic_handle_irq(irq);
pending &= pending - 1;
}
pending = __raw_readl(BALLOON3_INT_CONTROL_REG) &
balloon3_irq_enabled;
} while (pending);
}
static void __init balloon3_init_irq(void)
{
int irq;
pxa27x_init_irq();
for (irq = BALLOON3_IRQ(0); irq <= BALLOON3_IRQ(7); irq++) {
irq_set_chip_and_handler(irq, &balloon3_irq_chip,
handle_level_irq);
set_irq_flags(irq, IRQF_VALID | IRQF_PROBE);
}
irq_set_chained_handler(BALLOON3_AUX_NIRQ, balloon3_irq_handler);
irq_set_irq_type(BALLOON3_AUX_NIRQ, IRQ_TYPE_EDGE_FALLING);
pr_debug("%s: chained handler installed - irq %d automatically "
"enabled\n", __func__, BALLOON3_AUX_NIRQ);
}
static void __init balloon3_i2c_init(void)
{
pxa_set_i2c_info(NULL);
i2c_register_board_info(0, ARRAY_AND_SIZE(balloon3_i2c_devs));
}
static inline void balloon3_i2c_init(void) {}
static void balloon3_nand_cmd_ctl(struct mtd_info *mtd, int cmd, unsigned int ctrl)
{
struct nand_chip *this = mtd->priv;
uint8_t balloon3_ctl_set = 0, balloon3_ctl_clr = 0;
if (ctrl & NAND_CTRL_CHANGE) {
if (ctrl & NAND_CLE)
balloon3_ctl_set |= BALLOON3_NAND_CONTROL_FLCLE;
else
balloon3_ctl_clr |= BALLOON3_NAND_CONTROL_FLCLE;
if (ctrl & NAND_ALE)
balloon3_ctl_set |= BALLOON3_NAND_CONTROL_FLALE;
else
balloon3_ctl_clr |= BALLOON3_NAND_CONTROL_FLALE;
if (balloon3_ctl_clr)
__raw_writel(balloon3_ctl_clr,
BALLOON3_NAND_CONTROL_REG);
if (balloon3_ctl_set)
__raw_writel(balloon3_ctl_set,
BALLOON3_NAND_CONTROL_REG +
BALLOON3_FPGA_SETnCLR);
}
if (cmd != NAND_CMD_NONE)
writeb(cmd, this->IO_ADDR_W);
}
static void balloon3_nand_select_chip(struct mtd_info *mtd, int chip)
{
if (chip < 0 || chip > 3)
return;
__raw_writew(
BALLOON3_NAND_CONTROL_FLCE0 | BALLOON3_NAND_CONTROL_FLCE1 |
BALLOON3_NAND_CONTROL_FLCE2 | BALLOON3_NAND_CONTROL_FLCE3,
BALLOON3_NAND_CONTROL_REG + BALLOON3_FPGA_SETnCLR);
__raw_writew(BALLOON3_NAND_CONTROL_FLCE0 << chip,
BALLOON3_NAND_CONTROL_REG);
}
static int balloon3_nand_dev_ready(struct mtd_info *mtd)
{
return __raw_readl(BALLOON3_NAND_STAT_REG) & BALLOON3_NAND_STAT_RNB;
}
static int balloon3_nand_probe(struct platform_device *pdev)
{
uint16_t ver;
int ret;
__raw_writew(BALLOON3_NAND_CONTROL2_16BIT,
BALLOON3_NAND_CONTROL2_REG + BALLOON3_FPGA_SETnCLR);
ver = __raw_readw(BALLOON3_FPGA_VER);
if (ver < 0x4f08)
pr_warn("The FPGA code, version 0x%04x, is too old. "
"NAND support might be broken in this version!", ver);
ret = gpio_request(BALLOON3_GPIO_RUN_NAND, "NAND");
if (ret)
goto err1;
ret = gpio_direction_output(BALLOON3_GPIO_RUN_NAND, 1);
if (ret)
goto err2;
gpio_set_value(BALLOON3_GPIO_RUN_NAND, 1);
__raw_writel(
BALLOON3_NAND_CONTROL_FLCE0 | BALLOON3_NAND_CONTROL_FLCE1 |
BALLOON3_NAND_CONTROL_FLCE2 | BALLOON3_NAND_CONTROL_FLCE3 |
BALLOON3_NAND_CONTROL_FLWP,
BALLOON3_NAND_CONTROL_REG + BALLOON3_FPGA_SETnCLR);
return 0;
err2:
gpio_free(BALLOON3_GPIO_RUN_NAND);
err1:
return ret;
}
static void balloon3_nand_remove(struct platform_device *pdev)
{
gpio_set_value(BALLOON3_GPIO_RUN_NAND, 0);
gpio_free(BALLOON3_GPIO_RUN_NAND);
}
static void __init balloon3_nand_init(void)
{
platform_device_register(&balloon3_nand);
}
static inline void balloon3_nand_init(void) {}
static void __init balloon3_pmic_init(void)
{
pxa27x_set_i2c_power_info(NULL);
i2c_register_board_info(1, ARRAY_AND_SIZE(balloon3_pi2c_board_info));
}
static inline void balloon3_pmic_init(void) {}
static void __init balloon3_init(void)
{
ARB_CNTRL = ARB_CORE_PARK | 0x234;
pxa2xx_mfp_config(ARRAY_AND_SIZE(balloon3_pin_config));
pxa_set_ffuart_info(NULL);
pxa_set_btuart_info(NULL);
pxa_set_stuart_info(NULL);
balloon3_i2c_init();
balloon3_irda_init();
balloon3_lcd_init();
balloon3_leds_init();
balloon3_mmc_init();
balloon3_nand_init();
balloon3_nor_init();
balloon3_pmic_init();
balloon3_ts_init();
balloon3_udc_init();
balloon3_uhc_init();
balloon3_cf_init();
}
static void __init balloon3_map_io(void)
{
pxa27x_map_io();
iotable_init(balloon3_io_desc, ARRAY_SIZE(balloon3_io_desc));
}
