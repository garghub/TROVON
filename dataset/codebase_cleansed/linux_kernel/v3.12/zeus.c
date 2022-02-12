static inline int zeus_irq_to_bitmask(unsigned int irq)
{
return zeus_isa_irq_map[irq - PXA_ISA_IRQ(0)];
}
static inline int zeus_bit_to_irq(int bit)
{
return zeus_isa_irqs[bit] + PXA_ISA_IRQ(0);
}
static void zeus_ack_irq(struct irq_data *d)
{
__raw_writew(zeus_irq_to_bitmask(d->irq), ZEUS_CPLD_ISA_IRQ);
}
static void zeus_mask_irq(struct irq_data *d)
{
zeus_irq_enabled_mask &= ~(zeus_irq_to_bitmask(d->irq));
}
static void zeus_unmask_irq(struct irq_data *d)
{
zeus_irq_enabled_mask |= zeus_irq_to_bitmask(d->irq);
}
static inline unsigned long zeus_irq_pending(void)
{
return __raw_readw(ZEUS_CPLD_ISA_IRQ) & zeus_irq_enabled_mask;
}
static void zeus_irq_handler(unsigned int irq, struct irq_desc *desc)
{
unsigned long pending;
pending = zeus_irq_pending();
do {
desc->irq_data.chip->irq_ack(&desc->irq_data);
if (likely(pending)) {
irq = zeus_bit_to_irq(__ffs(pending));
generic_handle_irq(irq);
}
pending = zeus_irq_pending();
} while (pending);
}
static void __init zeus_init_irq(void)
{
int level;
int isa_irq;
pxa27x_init_irq();
irq_set_irq_type(gpio_to_irq(ZEUS_AC97_GPIO), IRQ_TYPE_EDGE_RISING);
irq_set_irq_type(gpio_to_irq(ZEUS_WAKEUP_GPIO), IRQ_TYPE_EDGE_RISING);
irq_set_irq_type(gpio_to_irq(ZEUS_PTT_GPIO), IRQ_TYPE_EDGE_RISING);
irq_set_irq_type(gpio_to_irq(ZEUS_EXTGPIO_GPIO),
IRQ_TYPE_EDGE_FALLING);
irq_set_irq_type(gpio_to_irq(ZEUS_CAN_GPIO), IRQ_TYPE_EDGE_FALLING);
for (level = 0; level < ARRAY_SIZE(zeus_isa_irqs); level++) {
isa_irq = zeus_bit_to_irq(level);
irq_set_chip_and_handler(isa_irq, &zeus_irq_chip,
handle_edge_irq);
set_irq_flags(isa_irq, IRQF_VALID | IRQF_PROBE);
}
irq_set_irq_type(gpio_to_irq(ZEUS_ISA_GPIO), IRQ_TYPE_EDGE_RISING);
irq_set_chained_handler(gpio_to_irq(ZEUS_ISA_GPIO), zeus_irq_handler);
}
static void zeus_cf_reset(int state)
{
u16 cpld_state = __raw_readw(ZEUS_CPLD_CONTROL);
if (state)
cpld_state |= ZEUS_CPLD_CONTROL_CF_RST;
else
cpld_state &= ~ZEUS_CPLD_CONTROL_CF_RST;
__raw_writew(cpld_state, ZEUS_CPLD_CONTROL);
}
static int zeus_ohci_init(struct device *dev)
{
int err;
if ((err = gpio_request(ZEUS_USB2_PWREN_GPIO, "USB2_PWREN"))) {
dev_err(dev, "Can't request USB2_PWREN\n");
return err;
}
if ((err = gpio_direction_output(ZEUS_USB2_PWREN_GPIO, 1))) {
gpio_free(ZEUS_USB2_PWREN_GPIO);
dev_err(dev, "Can't enable USB2_PWREN\n");
return err;
}
UP2OCR = UP2OCR_HXOE | UP2OCR_HXS | UP2OCR_DMPDE | UP2OCR_DPPDE;
return 0;
}
static void zeus_ohci_exit(struct device *dev)
{
gpio_direction_output(ZEUS_USB2_PWREN_GPIO, 0);
gpio_free(ZEUS_USB2_PWREN_GPIO);
}
static void zeus_lcd_power(int on, struct fb_var_screeninfo *si)
{
gpio_set_value(ZEUS_LCD_EN_GPIO, on);
}
static void zeus_backlight_power(int on)
{
gpio_set_value(ZEUS_BKLEN_GPIO, on);
}
static int zeus_setup_fb_gpios(void)
{
int err;
if ((err = gpio_request(ZEUS_LCD_EN_GPIO, "LCD_EN")))
goto out_err;
if ((err = gpio_direction_output(ZEUS_LCD_EN_GPIO, 0)))
goto out_err_lcd;
if ((err = gpio_request(ZEUS_BKLEN_GPIO, "BKLEN")))
goto out_err_lcd;
if ((err = gpio_direction_output(ZEUS_BKLEN_GPIO, 0)))
goto out_err_bkl;
return 0;
out_err_bkl:
gpio_free(ZEUS_BKLEN_GPIO);
out_err_lcd:
gpio_free(ZEUS_LCD_EN_GPIO);
out_err:
return err;
}
static void zeus_udc_command(int cmd)
{
switch (cmd) {
case PXA2XX_UDC_CMD_DISCONNECT:
pr_info("zeus: disconnecting USB client\n");
UP2OCR = UP2OCR_HXOE | UP2OCR_HXS | UP2OCR_DMPDE | UP2OCR_DPPDE;
break;
case PXA2XX_UDC_CMD_CONNECT:
pr_info("zeus: connecting USB client\n");
UP2OCR = UP2OCR_HXOE | UP2OCR_DPPUE;
break;
}
}
static void zeus_power_off(void)
{
local_irq_disable();
cpu_suspend(PWRMODE_DEEPSLEEP, pxa27x_finish_suspend);
}
static void zeus_get_power_status(struct apm_power_info *info)
{
info->ac_line_status = APM_AC_ONLINE;
info->battery_status = APM_BATTERY_STATUS_NOT_PRESENT;
info->battery_flag = APM_BATTERY_FLAG_NOT_PRESENT;
}
static inline void zeus_setup_apm(void)
{
apm_get_power_status = zeus_get_power_status;
}
static inline void zeus_setup_apm(void)
{
}
static int zeus_get_pcb_info(struct i2c_client *client, unsigned gpio,
unsigned ngpio, void *context)
{
int i;
u8 pcb_info = 0;
for (i = 0; i < 8; i++) {
int pcb_bit = gpio + i + 8;
if (gpio_request(pcb_bit, "pcb info")) {
dev_err(&client->dev, "Can't request pcb info %d\n", i);
continue;
}
if (gpio_direction_input(pcb_bit)) {
dev_err(&client->dev, "Can't read pcb info %d\n", i);
gpio_free(pcb_bit);
continue;
}
pcb_info |= !!gpio_get_value(pcb_bit) << i;
gpio_free(pcb_bit);
}
dev_info(&client->dev, "Zeus PCB version %d issue %d\n",
pcb_info >> 4, pcb_info & 0xf);
return 0;
}
static void __init zeus_init(void)
{
u16 dm9000_msc = DM9K_MSC_VALUE;
u32 msc0, msc1;
system_rev = __raw_readw(ZEUS_CPLD_VERSION);
pr_info("Zeus CPLD V%dI%d\n", (system_rev & 0xf0) >> 4, (system_rev & 0x0f));
msc0 = (__raw_readl(MSC0) & 0x0000ffff) | (dm9000_msc << 16);
msc1 = (__raw_readl(MSC1) & 0xffff0000) | dm9000_msc;
__raw_writel(msc0, MSC0);
__raw_writel(msc1, MSC1);
pm_power_off = zeus_power_off;
zeus_setup_apm();
pxa2xx_mfp_config(ARRAY_AND_SIZE(zeus_pin_config));
platform_add_devices(zeus_devices, ARRAY_SIZE(zeus_devices));
pxa_set_ohci_info(&zeus_ohci_platform_data);
if (zeus_setup_fb_gpios())
pr_err("Failed to setup fb gpios\n");
else
pxa_set_fb_info(NULL, &zeus_fb_info);
pxa_set_mci_info(&zeus_mci_platform_data);
pxa_set_udc_info(&zeus_udc_info);
pxa_set_ac97_info(&zeus_ac97_info);
pxa_set_i2c_info(NULL);
i2c_register_board_info(0, ARRAY_AND_SIZE(zeus_i2c_devices));
pxa2xx_set_spi_info(3, &pxa2xx_spi_ssp3_master_info);
spi_register_board_info(zeus_spi_board_info, ARRAY_SIZE(zeus_spi_board_info));
}
static void __init zeus_map_io(void)
{
pxa27x_map_io();
iotable_init(zeus_io_desc, ARRAY_SIZE(zeus_io_desc));
PMCR = PSPR = 0;
OSCC |= OSCC_OON;
PCFR = PCFR_OPDE | PCFR_DC_EN | PCFR_FS | PCFR_FP;
}
