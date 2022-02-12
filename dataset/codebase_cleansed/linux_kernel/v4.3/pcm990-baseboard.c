static u8 pcm990_cpld_readb(unsigned int reg)
{
return readb(pcm990_cpld_base + reg);
}
static void pcm990_cpld_writeb(u8 value, unsigned int reg)
{
writeb(value, pcm990_cpld_base + reg);
}
static void pcm990_lcd_power(int on, struct fb_var_screeninfo *var)
{
if (on) {
pcm990_cpld_writeb(PCM990_CTRL_LCDPWR + PCM990_CTRL_LCDON,
PCM990_CTRL_REG3);
} else {
pcm990_cpld_writeb(0, PCM990_CTRL_REG3);
}
}
static void pcm990_mask_ack_irq(struct irq_data *d)
{
int pcm990_irq = (d->irq - PCM027_IRQ(0));
pcm990_irq_enabled &= ~(1 << pcm990_irq);
pcm990_cpld_writeb(pcm990_irq_enabled, PCM990_CTRL_INTMSKENA);
}
static void pcm990_unmask_irq(struct irq_data *d)
{
int pcm990_irq = (d->irq - PCM027_IRQ(0));
u8 val;
pcm990_irq_enabled |= (1 << pcm990_irq);
val = pcm990_cpld_readb(PCM990_CTRL_INTSETCLR);
val |= 1 << pcm990_irq;
pcm990_cpld_writeb(val, PCM990_CTRL_INTSETCLR);
pcm990_cpld_writeb(pcm990_irq_enabled, PCM990_CTRL_INTMSKENA);
}
static void pcm990_irq_handler(struct irq_desc *desc)
{
unsigned int irq;
unsigned long pending;
pending = ~pcm990_cpld_readb(PCM990_CTRL_INTSETCLR);
pending &= pcm990_irq_enabled;
do {
desc->irq_data.chip->irq_ack(&desc->irq_data);
if (likely(pending)) {
irq = PCM027_IRQ(0) + __ffs(pending);
generic_handle_irq(irq);
}
pending = ~pcm990_cpld_readb(PCM990_CTRL_INTSETCLR);
pending &= pcm990_irq_enabled;
} while (pending);
}
static void __init pcm990_init_irq(void)
{
int irq;
for (irq = PCM027_IRQ(0); irq <= PCM027_IRQ(3); irq++) {
irq_set_chip_and_handler(irq, &pcm990_irq_chip,
handle_level_irq);
irq_clear_status_flags(irq, IRQ_NOREQUEST | IRQ_NOPROBE);
}
pcm990_cpld_writeb(0x0, PCM990_CTRL_INTMSKENA);
pcm990_cpld_writeb(0xff, PCM990_CTRL_INTSETCLR);
irq_set_chained_handler(PCM990_CTRL_INT_IRQ, pcm990_irq_handler);
irq_set_irq_type(PCM990_CTRL_INT_IRQ, PCM990_CTRL_INT_IRQ_EDGE);
}
static int pcm990_mci_init(struct device *dev, irq_handler_t mci_detect_int,
void *data)
{
int err;
err = request_irq(PCM027_MMCDET_IRQ, mci_detect_int, 0,
"MMC card detect", data);
if (err)
printk(KERN_ERR "pcm990_mci_init: MMC/SD: can't request MMC "
"card detect IRQ\n");
return err;
}
static int pcm990_mci_setpower(struct device *dev, unsigned int vdd)
{
struct pxamci_platform_data *p_d = dev->platform_data;
u8 val;
val = pcm990_cpld_readb(PCM990_CTRL_REG5);
if ((1 << vdd) & p_d->ocr_mask)
val |= PCM990_CTRL_MMC2PWR;
else
val &= ~PCM990_CTRL_MMC2PWR;
pcm990_cpld_writeb(PCM990_CTRL_MMC2PWR, PCM990_CTRL_REG5);
return 0;
}
static void pcm990_mci_exit(struct device *dev, void *data)
{
free_irq(PCM027_MMCDET_IRQ, data);
}
static int pcm990_camera_set_bus_param(struct soc_camera_link *link,
unsigned long flags)
{
if (gpio_bus_switch < 0) {
if (flags == SOCAM_DATAWIDTH_10)
return 0;
else
return -EINVAL;
}
if (flags & SOCAM_DATAWIDTH_8)
gpio_set_value_cansleep(gpio_bus_switch, 1);
else
gpio_set_value_cansleep(gpio_bus_switch, 0);
return 0;
}
static unsigned long pcm990_camera_query_bus_param(struct soc_camera_link *link)
{
int ret;
if (gpio_bus_switch < 0) {
ret = gpio_request(PXA_NR_BUILTIN_GPIO, "camera");
if (!ret) {
gpio_bus_switch = PXA_NR_BUILTIN_GPIO;
gpio_direction_output(gpio_bus_switch, 0);
}
}
if (gpio_bus_switch >= 0)
return SOCAM_DATAWIDTH_8 | SOCAM_DATAWIDTH_10;
else
return SOCAM_DATAWIDTH_10;
}
static void pcm990_camera_free_bus(struct soc_camera_link *link)
{
if (gpio_bus_switch < 0)
return;
gpio_free(gpio_bus_switch);
gpio_bus_switch = -EINVAL;
}
void __init pcm990_baseboard_init(void)
{
pxa2xx_mfp_config(ARRAY_AND_SIZE(pcm990_pin_config));
pcm990_cpld_base = ioremap(PCM990_CTRL_PHYS, PCM990_CTRL_SIZE);
if (!pcm990_cpld_base) {
pr_err("pcm990: failed to ioremap cpld\n");
return;
}
pcm990_init_irq();
#ifndef CONFIG_PCM990_DISPLAY_NONE
pxa_set_fb_info(NULL, &pcm990_fbinfo);
#endif
platform_device_register(&pcm990_backlight_device);
pxa_set_mci_info(&pcm990_mci_platform_data);
pxa_set_ohci_info(&pcm990_ohci_platform_data);
pxa_set_i2c_info(NULL);
pxa_set_ac97_info(NULL);
#if defined(CONFIG_VIDEO_PXA27x) || defined(CONFIG_VIDEO_PXA27x_MODULE)
pxa2xx_mfp_config(ARRAY_AND_SIZE(pcm990_camera_pin_config));
pxa_set_camera_info(&pcm990_pxacamera_platform_data);
i2c_register_board_info(0, ARRAY_AND_SIZE(pcm990_i2c_devices));
platform_device_register(&pcm990_camera[0]);
platform_device_register(&pcm990_camera[1]);
#endif
printk(KERN_INFO "PCM-990 Evaluation baseboard initialized\n");
}
