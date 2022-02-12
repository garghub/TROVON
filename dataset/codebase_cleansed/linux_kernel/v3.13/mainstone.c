static void mainstone_mask_irq(struct irq_data *d)
{
int mainstone_irq = (d->irq - MAINSTONE_IRQ(0));
MST_INTMSKENA = (mainstone_irq_enabled &= ~(1 << mainstone_irq));
}
static void mainstone_unmask_irq(struct irq_data *d)
{
int mainstone_irq = (d->irq - MAINSTONE_IRQ(0));
MST_INTSETCLR &= ~(1 << mainstone_irq);
MST_INTMSKENA = (mainstone_irq_enabled |= (1 << mainstone_irq));
}
static void mainstone_irq_handler(unsigned int irq, struct irq_desc *desc)
{
unsigned long pending = MST_INTSETCLR & mainstone_irq_enabled;
do {
desc->irq_data.chip->irq_ack(&desc->irq_data);
if (likely(pending)) {
irq = MAINSTONE_IRQ(0) + __ffs(pending);
generic_handle_irq(irq);
}
pending = MST_INTSETCLR & mainstone_irq_enabled;
} while (pending);
}
static void __init mainstone_init_irq(void)
{
int irq;
pxa27x_init_irq();
for(irq = MAINSTONE_IRQ(0); irq <= MAINSTONE_IRQ(15); irq++) {
irq_set_chip_and_handler(irq, &mainstone_irq_chip,
handle_level_irq);
if (irq == MAINSTONE_IRQ(10) || irq == MAINSTONE_IRQ(14))
set_irq_flags(irq, IRQF_VALID | IRQF_PROBE | IRQF_NOAUTOEN);
else
set_irq_flags(irq, IRQF_VALID | IRQF_PROBE);
}
set_irq_flags(MAINSTONE_IRQ(8), 0);
set_irq_flags(MAINSTONE_IRQ(12), 0);
MST_INTMSKENA = 0;
MST_INTSETCLR = 0;
irq_set_chained_handler(PXA_GPIO_TO_IRQ(0), mainstone_irq_handler);
irq_set_irq_type(PXA_GPIO_TO_IRQ(0), IRQ_TYPE_EDGE_FALLING);
}
static void mainstone_irq_resume(void)
{
MST_INTMSKENA = mainstone_irq_enabled;
}
static int __init mainstone_irq_device_init(void)
{
if (machine_is_mainstone())
register_syscore_ops(&mainstone_irq_syscore_ops);
return 0;
}
static int mst_audio_startup(struct snd_pcm_substream *substream, void *priv)
{
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
MST_MSCWR2 &= ~MST_MSCWR2_AC97_SPKROFF;
return 0;
}
static void mst_audio_shutdown(struct snd_pcm_substream *substream, void *priv)
{
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
MST_MSCWR2 |= MST_MSCWR2_AC97_SPKROFF;
}
static void mst_audio_suspend(void *priv)
{
mst_audio_suspend_mask = MST_MSCWR2;
MST_MSCWR2 |= MST_MSCWR2_AC97_SPKROFF;
}
static void mst_audio_resume(void *priv)
{
MST_MSCWR2 &= mst_audio_suspend_mask | ~MST_MSCWR2_AC97_SPKROFF;
}
static void __init mainstone_backlight_register(void)
{
int ret = platform_device_register(&mainstone_backlight_device);
if (ret)
printk(KERN_ERR "mainstone: failed to register backlight device: %d\n", ret);
}
static int mainstone_mci_init(struct device *dev, irq_handler_t mstone_detect_int, void *data)
{
int err;
MST_MSCWR1 &= ~MST_MSCWR1_MS_SEL;
err = request_irq(MAINSTONE_MMC_IRQ, mstone_detect_int, IRQF_DISABLED,
"MMC card detect", data);
if (err)
printk(KERN_ERR "mainstone_mci_init: MMC/SD: can't request MMC card detect IRQ\n");
return err;
}
static int mainstone_mci_setpower(struct device *dev, unsigned int vdd)
{
struct pxamci_platform_data* p_d = dev->platform_data;
if (( 1 << vdd) & p_d->ocr_mask) {
printk(KERN_DEBUG "%s: on\n", __func__);
MST_MSCWR1 |= MST_MSCWR1_MMC_ON;
MST_MSCWR1 &= ~MST_MSCWR1_MS_SEL;
} else {
printk(KERN_DEBUG "%s: off\n", __func__);
MST_MSCWR1 &= ~MST_MSCWR1_MMC_ON;
}
return 0;
}
static void mainstone_mci_exit(struct device *dev, void *data)
{
free_irq(MAINSTONE_MMC_IRQ, data);
}
static void mainstone_irda_transceiver_mode(struct device *dev, int mode)
{
unsigned long flags;
local_irq_save(flags);
if (mode & IR_SIRMODE) {
MST_MSCWR1 &= ~MST_MSCWR1_IRDA_FIR;
} else if (mode & IR_FIRMODE) {
MST_MSCWR1 |= MST_MSCWR1_IRDA_FIR;
}
pxa2xx_transceiver_mode(dev, mode);
if (mode & IR_OFF) {
MST_MSCWR1 = (MST_MSCWR1 & ~MST_MSCWR1_IRDA_MASK) | MST_MSCWR1_IRDA_OFF;
} else {
MST_MSCWR1 = (MST_MSCWR1 & ~MST_MSCWR1_IRDA_MASK) | MST_MSCWR1_IRDA_FULL;
}
local_irq_restore(flags);
}
static void __init mainstone_init_keypad(void)
{
pxa_set_keypad_info(&mainstone_keypad_info);
}
static inline void mainstone_init_keypad(void) {}
static void __init mainstone_init(void)
{
int SW7 = 0;
pxa2xx_mfp_config(ARRAY_AND_SIZE(mainstone_pin_config));
pxa_set_ffuart_info(NULL);
pxa_set_btuart_info(NULL);
pxa_set_stuart_info(NULL);
mst_flash_data[0].width = (__raw_readl(BOOT_DEF) & 1) ? 2 : 4;
mst_flash_data[1].width = 4;
mst_flash_data[SW7].name = "processor-flash";
mst_flash_data[SW7 ^ 1].name = "mainboard-flash";
printk(KERN_NOTICE "Mainstone configured to boot from %s\n",
mst_flash_data[0].name);
ARB_CNTRL = ARB_CORE_PARK | 0x234;
platform_add_devices(platform_devices, ARRAY_SIZE(platform_devices));
if (0)
mainstone_pxafb_info.modes = &toshiba_ltm04c380k_mode;
else
mainstone_pxafb_info.modes = &toshiba_ltm035a776c_mode;
pxa_set_fb_info(NULL, &mainstone_pxafb_info);
mainstone_backlight_register();
pxa_set_mci_info(&mainstone_mci_platform_data);
pxa_set_ficp_info(&mainstone_ficp_platform_data);
pxa_set_ohci_info(&mainstone_ohci_platform_data);
pxa_set_i2c_info(NULL);
pxa_set_ac97_info(&mst_audio_ops);
mainstone_init_keypad();
}
static void __init mainstone_map_io(void)
{
pxa27x_map_io();
iotable_init(mainstone_io_desc, ARRAY_SIZE(mainstone_io_desc));
PSLR |= 0xF04;
PCFR = 0x66;
}
static void mainstone_led_set(struct led_classdev *cdev,
enum led_brightness b)
{
struct mainstone_led *led = container_of(cdev,
struct mainstone_led, cdev);
u32 reg = MST_LEDCTRL;
if (b != LED_OFF)
reg |= led->mask;
else
reg &= ~led->mask;
MST_LEDCTRL = reg;
}
static enum led_brightness mainstone_led_get(struct led_classdev *cdev)
{
struct mainstone_led *led = container_of(cdev,
struct mainstone_led, cdev);
u32 reg = MST_LEDCTRL;
return (reg & led->mask) ? LED_FULL : LED_OFF;
}
static int __init mainstone_leds_init(void)
{
int i;
if (!machine_is_mainstone())
return -ENODEV;
MST_LEDCTRL |= 0xff;
for (i = 0; i < ARRAY_SIZE(mainstone_leds); i++) {
struct mainstone_led *led;
led = kzalloc(sizeof(*led), GFP_KERNEL);
if (!led)
break;
led->cdev.name = mainstone_leds[i].name;
led->cdev.brightness_set = mainstone_led_set;
led->cdev.brightness_get = mainstone_led_get;
led->cdev.default_trigger = mainstone_leds[i].trigger;
led->mask = BIT(i);
if (led_classdev_register(NULL, &led->cdev) < 0) {
kfree(led);
break;
}
}
return 0;
}
