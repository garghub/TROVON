static int __devinit snd_pcsp_create(struct snd_card *card)
{
static struct snd_device_ops ops = { };
struct timespec tp;
int err;
int div, min_div, order;
if (!nopcm) {
hrtimer_get_res(CLOCK_MONOTONIC, &tp);
if (tp.tv_sec || tp.tv_nsec > PCSP_MAX_PERIOD_NS) {
printk(KERN_ERR "PCSP: Timer resolution is not sufficient "
"(%linS)\n", tp.tv_nsec);
printk(KERN_ERR "PCSP: Make sure you have HPET and ACPI "
"enabled.\n");
printk(KERN_ERR "PCSP: Turned into nopcm mode.\n");
nopcm = 1;
}
}
if (loops_per_jiffy >= PCSP_MIN_LPJ && tp.tv_nsec <= PCSP_MIN_PERIOD_NS)
min_div = MIN_DIV;
else
min_div = MAX_DIV;
#if PCSP_DEBUG
printk(KERN_DEBUG "PCSP: lpj=%li, min_div=%i, res=%li\n",
loops_per_jiffy, min_div, tp.tv_nsec);
#endif
div = MAX_DIV / min_div;
order = fls(div) - 1;
pcsp_chip.max_treble = min(order, PCSP_MAX_TREBLE);
pcsp_chip.treble = min(pcsp_chip.max_treble, PCSP_DEFAULT_TREBLE);
pcsp_chip.playback_ptr = 0;
pcsp_chip.period_ptr = 0;
atomic_set(&pcsp_chip.timer_active, 0);
pcsp_chip.enable = 1;
pcsp_chip.pcspkr = 1;
spin_lock_init(&pcsp_chip.substream_lock);
pcsp_chip.card = card;
pcsp_chip.port = 0x61;
pcsp_chip.irq = -1;
pcsp_chip.dma = -1;
err = snd_device_new(card, SNDRV_DEV_LOWLEVEL, &pcsp_chip, &ops);
if (err < 0)
return err;
return 0;
}
static int __devinit snd_card_pcsp_probe(int devnum, struct device *dev)
{
struct snd_card *card;
int err;
if (devnum != 0)
return -EINVAL;
hrtimer_init(&pcsp_chip.timer, CLOCK_MONOTONIC, HRTIMER_MODE_REL);
pcsp_chip.timer.function = pcsp_do_timer;
err = snd_card_create(index, id, THIS_MODULE, 0, &card);
if (err < 0)
return err;
err = snd_pcsp_create(card);
if (err < 0) {
snd_card_free(card);
return err;
}
if (!nopcm) {
err = snd_pcsp_new_pcm(&pcsp_chip);
if (err < 0) {
snd_card_free(card);
return err;
}
}
err = snd_pcsp_new_mixer(&pcsp_chip, nopcm);
if (err < 0) {
snd_card_free(card);
return err;
}
snd_card_set_dev(pcsp_chip.card, dev);
strcpy(card->driver, "PC-Speaker");
strcpy(card->shortname, "pcsp");
sprintf(card->longname, "Internal PC-Speaker at port 0x%x",
pcsp_chip.port);
err = snd_card_register(card);
if (err < 0) {
snd_card_free(card);
return err;
}
return 0;
}
static int __devinit alsa_card_pcsp_init(struct device *dev)
{
int err;
err = snd_card_pcsp_probe(0, dev);
if (err) {
printk(KERN_ERR "PC-Speaker initialization failed.\n");
return err;
}
#ifdef CONFIG_DEBUG_PAGEALLOC
printk(KERN_WARNING "PCSP: CONFIG_DEBUG_PAGEALLOC is enabled, "
"which may make the sound noisy.\n");
#endif
return 0;
}
static void __devexit alsa_card_pcsp_exit(struct snd_pcsp *chip)
{
snd_card_free(chip->card);
}
static int __devinit pcsp_probe(struct platform_device *dev)
{
int err;
err = pcspkr_input_init(&pcsp_chip.input_dev, &dev->dev);
if (err < 0)
return err;
err = alsa_card_pcsp_init(&dev->dev);
if (err < 0) {
pcspkr_input_remove(pcsp_chip.input_dev);
return err;
}
platform_set_drvdata(dev, &pcsp_chip);
return 0;
}
static int __devexit pcsp_remove(struct platform_device *dev)
{
struct snd_pcsp *chip = platform_get_drvdata(dev);
alsa_card_pcsp_exit(chip);
pcspkr_input_remove(chip->input_dev);
platform_set_drvdata(dev, NULL);
return 0;
}
static void pcsp_stop_beep(struct snd_pcsp *chip)
{
pcsp_sync_stop(chip);
pcspkr_stop_sound();
}
static int pcsp_suspend(struct platform_device *dev, pm_message_t state)
{
struct snd_pcsp *chip = platform_get_drvdata(dev);
pcsp_stop_beep(chip);
snd_pcm_suspend_all(chip->pcm);
return 0;
}
static void pcsp_shutdown(struct platform_device *dev)
{
struct snd_pcsp *chip = platform_get_drvdata(dev);
pcsp_stop_beep(chip);
}
static int __init pcsp_init(void)
{
if (!enable)
return -ENODEV;
return platform_driver_register(&pcsp_platform_driver);
}
static void __exit pcsp_exit(void)
{
platform_driver_unregister(&pcsp_platform_driver);
}
