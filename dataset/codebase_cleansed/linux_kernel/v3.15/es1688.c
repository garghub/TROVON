static int snd_es1688_match(struct device *dev, unsigned int n)
{
return enable[n] && !is_isapnp_selected(n);
}
static int snd_es1688_legacy_create(struct snd_card *card,
struct device *dev, unsigned int n)
{
struct snd_es1688 *chip = card->private_data;
static long possible_ports[] = {0x220, 0x240, 0x260};
static int possible_irqs[] = {5, 9, 10, 7, -1};
static int possible_dmas[] = {1, 3, 0, -1};
int i, error;
if (irq[n] == SNDRV_AUTO_IRQ) {
irq[n] = snd_legacy_find_free_irq(possible_irqs);
if (irq[n] < 0) {
dev_err(dev, "unable to find a free IRQ\n");
return -EBUSY;
}
}
if (dma8[n] == SNDRV_AUTO_DMA) {
dma8[n] = snd_legacy_find_free_dma(possible_dmas);
if (dma8[n] < 0) {
dev_err(dev, "unable to find a free DMA\n");
return -EBUSY;
}
}
if (port[n] != SNDRV_AUTO_PORT)
return snd_es1688_create(card, chip, port[n], mpu_port[n],
irq[n], mpu_irq[n], dma8[n], ES1688_HW_AUTO);
i = 0;
do {
port[n] = possible_ports[i];
error = snd_es1688_create(card, chip, port[n], mpu_port[n],
irq[n], mpu_irq[n], dma8[n], ES1688_HW_AUTO);
} while (error < 0 && ++i < ARRAY_SIZE(possible_ports));
return error;
}
static int snd_es1688_probe(struct snd_card *card, unsigned int n)
{
struct snd_es1688 *chip = card->private_data;
struct snd_opl3 *opl3;
struct snd_pcm *pcm;
int error;
error = snd_es1688_pcm(card, chip, 0, &pcm);
if (error < 0)
return error;
error = snd_es1688_mixer(card, chip);
if (error < 0)
return error;
strlcpy(card->driver, "ES1688", sizeof(card->driver));
strlcpy(card->shortname, pcm->name, sizeof(card->shortname));
snprintf(card->longname, sizeof(card->longname),
"%s at 0x%lx, irq %i, dma %i", pcm->name, chip->port,
chip->irq, chip->dma8);
if (fm_port[n] == SNDRV_AUTO_PORT)
fm_port[n] = port[n];
if (fm_port[n] > 0) {
if (snd_opl3_create(card, fm_port[n], fm_port[n] + 2,
OPL3_HW_OPL3, 0, &opl3) < 0)
dev_warn(card->dev,
"opl3 not detected at 0x%lx\n", fm_port[n]);
else {
error = snd_opl3_hwdep_new(opl3, 0, 1, NULL);
if (error < 0)
return error;
}
}
if (mpu_irq[n] >= 0 && mpu_irq[n] != SNDRV_AUTO_IRQ &&
chip->mpu_port > 0) {
error = snd_mpu401_uart_new(card, 0, MPU401_HW_ES1688,
chip->mpu_port, 0,
mpu_irq[n], NULL);
if (error < 0)
return error;
}
return snd_card_register(card);
}
static int snd_es1688_isa_probe(struct device *dev, unsigned int n)
{
struct snd_card *card;
int error;
error = snd_card_new(dev, index[n], id[n], THIS_MODULE,
sizeof(struct snd_es1688), &card);
if (error < 0)
return error;
error = snd_es1688_legacy_create(card, dev, n);
if (error < 0)
goto out;
error = snd_es1688_probe(card, n);
if (error < 0)
goto out;
dev_set_drvdata(dev, card);
return 0;
out:
snd_card_free(card);
return error;
}
static int snd_es1688_isa_remove(struct device *dev, unsigned int n)
{
snd_card_free(dev_get_drvdata(dev));
return 0;
}
static int snd_card_es968_pnp(struct snd_card *card, unsigned int n,
struct pnp_card_link *pcard,
const struct pnp_card_device_id *pid)
{
struct snd_es1688 *chip = card->private_data;
struct pnp_dev *pdev;
int error;
pdev = pnp_request_card_device(pcard, pid->devs[0].id, NULL);
if (pdev == NULL)
return -ENODEV;
error = pnp_activate_dev(pdev);
if (error < 0) {
snd_printk(KERN_ERR "ES968 pnp configure failure\n");
return error;
}
port[n] = pnp_port_start(pdev, 0);
dma8[n] = pnp_dma(pdev, 0);
irq[n] = pnp_irq(pdev, 0);
return snd_es1688_create(card, chip, port[n], mpu_port[n], irq[n],
mpu_irq[n], dma8[n], ES1688_HW_AUTO);
}
static int snd_es968_pnp_detect(struct pnp_card_link *pcard,
const struct pnp_card_device_id *pid)
{
struct snd_card *card;
static unsigned int dev;
int error;
struct snd_es1688 *chip;
if (snd_es968_pnp_is_probed)
return -EBUSY;
for ( ; dev < SNDRV_CARDS; dev++) {
if (enable[dev] && isapnp[dev])
break;
}
if (dev == SNDRV_CARDS)
return -ENODEV;
error = snd_card_new(&pcard->card->dev,
index[dev], id[dev], THIS_MODULE,
sizeof(struct snd_es1688), &card);
if (error < 0)
return error;
chip = card->private_data;
error = snd_card_es968_pnp(card, dev, pcard, pid);
if (error < 0) {
snd_card_free(card);
return error;
}
error = snd_es1688_probe(card, dev);
if (error < 0)
return error;
pnp_set_card_drvdata(pcard, card);
snd_es968_pnp_is_probed = 1;
return 0;
}
static void snd_es968_pnp_remove(struct pnp_card_link *pcard)
{
snd_card_free(pnp_get_card_drvdata(pcard));
pnp_set_card_drvdata(pcard, NULL);
snd_es968_pnp_is_probed = 0;
}
static int snd_es968_pnp_suspend(struct pnp_card_link *pcard,
pm_message_t state)
{
struct snd_card *card = pnp_get_card_drvdata(pcard);
struct snd_es1688 *chip = card->private_data;
snd_power_change_state(card, SNDRV_CTL_POWER_D3hot);
snd_pcm_suspend_all(chip->pcm);
return 0;
}
static int snd_es968_pnp_resume(struct pnp_card_link *pcard)
{
struct snd_card *card = pnp_get_card_drvdata(pcard);
struct snd_es1688 *chip = card->private_data;
snd_es1688_reset(chip);
snd_power_change_state(card, SNDRV_CTL_POWER_D0);
return 0;
}
static int __init alsa_card_es1688_init(void)
{
#ifdef CONFIG_PNP
pnp_register_card_driver(&es968_pnpc_driver);
if (snd_es968_pnp_is_probed)
return 0;
pnp_unregister_card_driver(&es968_pnpc_driver);
#endif
return isa_register_driver(&snd_es1688_driver, SNDRV_CARDS);
}
static void __exit alsa_card_es1688_exit(void)
{
if (!snd_es968_pnp_is_probed) {
isa_unregister_driver(&snd_es1688_driver);
return;
}
#ifdef CONFIG_PNP
pnp_unregister_card_driver(&es968_pnpc_driver);
#endif
}
