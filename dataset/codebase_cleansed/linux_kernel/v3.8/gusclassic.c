static int snd_gusclassic_match(struct device *dev, unsigned int n)
{
return enable[n];
}
static int snd_gusclassic_create(struct snd_card *card,
struct device *dev, unsigned int n,
struct snd_gus_card **rgus)
{
static long possible_ports[] = {0x220, 0x230, 0x240, 0x250, 0x260};
static int possible_irqs[] = {5, 11, 12, 9, 7, 15, 3, 4, -1};
static int possible_dmas[] = {5, 6, 7, 1, 3, -1};
int i, error;
if (irq[n] == SNDRV_AUTO_IRQ) {
irq[n] = snd_legacy_find_free_irq(possible_irqs);
if (irq[n] < 0) {
dev_err(dev, "unable to find a free IRQ\n");
return -EBUSY;
}
}
if (dma1[n] == SNDRV_AUTO_DMA) {
dma1[n] = snd_legacy_find_free_dma(possible_dmas);
if (dma1[n] < 0) {
dev_err(dev, "unable to find a free DMA1\n");
return -EBUSY;
}
}
if (dma2[n] == SNDRV_AUTO_DMA) {
dma2[n] = snd_legacy_find_free_dma(possible_dmas);
if (dma2[n] < 0) {
dev_err(dev, "unable to find a free DMA2\n");
return -EBUSY;
}
}
if (port[n] != SNDRV_AUTO_PORT)
return snd_gus_create(card, port[n], irq[n], dma1[n], dma2[n],
0, channels[n], pcm_channels[n], 0, rgus);
i = 0;
do {
port[n] = possible_ports[i];
error = snd_gus_create(card, port[n], irq[n], dma1[n], dma2[n],
0, channels[n], pcm_channels[n], 0, rgus);
} while (error < 0 && ++i < ARRAY_SIZE(possible_ports));
return error;
}
static int snd_gusclassic_detect(struct snd_gus_card *gus)
{
unsigned char d;
snd_gf1_i_write8(gus, SNDRV_GF1_GB_RESET, 0);
if (((d = snd_gf1_i_look8(gus, SNDRV_GF1_GB_RESET)) & 0x07) != 0) {
snd_printdd("[0x%lx] check 1 failed - 0x%x\n", gus->gf1.port, d);
return -ENODEV;
}
udelay(160);
snd_gf1_i_write8(gus, SNDRV_GF1_GB_RESET, 1);
udelay(160);
if (((d = snd_gf1_i_look8(gus, SNDRV_GF1_GB_RESET)) & 0x07) != 1) {
snd_printdd("[0x%lx] check 2 failed - 0x%x\n", gus->gf1.port, d);
return -ENODEV;
}
return 0;
}
static int snd_gusclassic_probe(struct device *dev, unsigned int n)
{
struct snd_card *card;
struct snd_gus_card *gus;
int error;
error = snd_card_create(index[n], id[n], THIS_MODULE, 0, &card);
if (error < 0)
return error;
if (pcm_channels[n] < 2)
pcm_channels[n] = 2;
error = snd_gusclassic_create(card, dev, n, &gus);
if (error < 0)
goto out;
error = snd_gusclassic_detect(gus);
if (error < 0)
goto out;
gus->joystick_dac = joystick_dac[n];
error = snd_gus_initialize(gus);
if (error < 0)
goto out;
error = -ENODEV;
if (gus->max_flag || gus->ess_flag) {
dev_err(dev, "GUS Classic or ACE soundcard was "
"not detected at 0x%lx\n", gus->gf1.port);
goto out;
}
error = snd_gf1_new_mixer(gus);
if (error < 0)
goto out;
error = snd_gf1_pcm_new(gus, 0, 0, NULL);
if (error < 0)
goto out;
if (!gus->ace_flag) {
error = snd_gf1_rawmidi_new(gus, 0, NULL);
if (error < 0)
goto out;
}
sprintf(card->longname + strlen(card->longname),
" at 0x%lx, irq %d, dma %d",
gus->gf1.port, gus->gf1.irq, gus->gf1.dma1);
if (gus->gf1.dma2 >= 0)
sprintf(card->longname + strlen(card->longname),
"&%d", gus->gf1.dma2);
snd_card_set_dev(card, dev);
error = snd_card_register(card);
if (error < 0)
goto out;
dev_set_drvdata(dev, card);
return 0;
out: snd_card_free(card);
return error;
}
static int snd_gusclassic_remove(struct device *dev, unsigned int n)
{
snd_card_free(dev_get_drvdata(dev));
dev_set_drvdata(dev, NULL);
return 0;
}
static int __init alsa_card_gusclassic_init(void)
{
return isa_register_driver(&snd_gusclassic_driver, SNDRV_CARDS);
}
static void __exit alsa_card_gusclassic_exit(void)
{
isa_unregister_driver(&snd_gusclassic_driver);
}
