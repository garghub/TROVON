static int snd_bcm2835_free(struct bcm2835_chip *chip)
{
kfree(chip);
return 0;
}
static int snd_bcm2835_dev_free(struct snd_device *device)
{
return snd_bcm2835_free(device->device_data);
}
static int snd_bcm2835_create(struct snd_card *card,
struct platform_device *pdev,
struct bcm2835_chip **rchip)
{
struct bcm2835_chip *chip;
int err;
static struct snd_device_ops ops = {
.dev_free = snd_bcm2835_dev_free,
};
*rchip = NULL;
chip = kzalloc(sizeof(*chip), GFP_KERNEL);
if (!chip)
return -ENOMEM;
chip->card = card;
err = snd_device_new(card, SNDRV_DEV_LOWLEVEL, chip, &ops);
if (err < 0) {
snd_bcm2835_free(chip);
return err;
}
*rchip = chip;
return 0;
}
static int snd_bcm2835_alsa_probe_dt(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct bcm2835_chip *chip;
struct snd_card *card;
u32 numchans;
int err, i;
err = of_property_read_u32(dev->of_node, "brcm,pwm-channels",
&numchans);
if (err) {
dev_err(dev, "Failed to get DT property 'brcm,pwm-channels'");
return err;
}
if (numchans == 0 || numchans > MAX_SUBSTREAMS) {
numchans = MAX_SUBSTREAMS;
dev_warn(dev, "Illegal 'brcm,pwm-channels' value, will use %u\n",
numchans);
}
err = snd_card_new(&pdev->dev, -1, NULL, THIS_MODULE, 0, &card);
if (err) {
dev_err(dev, "Failed to create soundcard structure\n");
return err;
}
snd_card_set_dev(card, dev);
strcpy(card->driver, "bcm2835");
strcpy(card->shortname, "bcm2835 ALSA");
sprintf(card->longname, "%s", card->shortname);
err = snd_bcm2835_create(card, pdev, &chip);
if (err < 0) {
dev_err(dev, "Failed to create bcm2835 chip\n");
goto err_free;
}
err = snd_bcm2835_new_pcm(chip);
if (err < 0) {
dev_err(dev, "Failed to create new bcm2835 pcm device\n");
goto err_free;
}
err = snd_bcm2835_new_spdif_pcm(chip);
if (err < 0) {
dev_err(dev, "Failed to create new bcm2835 spdif pcm device\n");
goto err_free;
}
err = snd_bcm2835_new_ctl(chip);
if (err < 0) {
dev_err(dev, "Failed to create new bcm2835 ctl\n");
goto err_free;
}
for (i = 0; i < numchans; i++) {
chip->avail_substreams |= (1 << i);
chip->pdev[i] = pdev;
}
err = snd_card_register(card);
if (err) {
dev_err(dev, "Failed to register bcm2835 ALSA card\n");
goto err_free;
}
g_card = card;
g_chip = chip;
platform_set_drvdata(pdev, card);
audio_info("bcm2835 ALSA card created with %u channels\n", numchans);
return 0;
err_free:
snd_card_free(card);
return err;
}
static int snd_bcm2835_alsa_remove(struct platform_device *pdev)
{
int idx;
void *drv_data;
drv_data = platform_get_drvdata(pdev);
if (drv_data == (void *)g_card) {
snd_card_free((struct snd_card *)drv_data);
g_card = NULL;
g_chip = NULL;
} else {
idx = (int)(long)drv_data;
if (g_card) {
BUG_ON(!g_chip);
idx = (int)(long)drv_data;
BUG_ON(!idx || idx > MAX_SUBSTREAMS);
g_chip->avail_substreams &= ~(1 << idx);
BUG_ON(!g_chip->avail_substreams);
}
}
platform_set_drvdata(pdev, NULL);
return 0;
}
static int snd_bcm2835_alsa_suspend(struct platform_device *pdev,
pm_message_t state)
{
return 0;
}
static int snd_bcm2835_alsa_resume(struct platform_device *pdev)
{
return 0;
}
static int bcm2835_alsa_device_init(void)
{
int retval;
retval = platform_driver_register(&bcm2835_alsa0_driver);
if (retval)
pr_err("Error registering bcm2835_alsa0_driver %d .\n", retval);
return retval;
}
static void bcm2835_alsa_device_exit(void)
{
platform_driver_unregister(&bcm2835_alsa0_driver);
}
