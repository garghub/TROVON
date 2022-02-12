static int snd_card_sb16_pnp(int dev, struct snd_card_sb16 *acard,
struct pnp_card_link *card,
const struct pnp_card_device_id *id)
{
struct pnp_dev *pdev;
int err;
acard->dev = pnp_request_card_device(card, id->devs[0].id, NULL);
if (acard->dev == NULL)
return -ENODEV;
#ifdef SNDRV_SBAWE_EMU8000
acard->devwt = pnp_request_card_device(card, id->devs[1].id, acard->dev);
#endif
pdev = acard->dev;
err = pnp_activate_dev(pdev);
if (err < 0) {
snd_printk(KERN_ERR PFX "AUDIO pnp configure failure\n");
return err;
}
port[dev] = pnp_port_start(pdev, 0);
mpu_port[dev] = pnp_port_start(pdev, 1);
fm_port[dev] = pnp_port_start(pdev, 2);
dma8[dev] = pnp_dma(pdev, 0);
dma16[dev] = pnp_dma(pdev, 1);
irq[dev] = pnp_irq(pdev, 0);
snd_printdd("pnp SB16: port=0x%lx, mpu port=0x%lx, fm port=0x%lx\n",
port[dev], mpu_port[dev], fm_port[dev]);
snd_printdd("pnp SB16: dma1=%i, dma2=%i, irq=%i\n",
dma8[dev], dma16[dev], irq[dev]);
#ifdef SNDRV_SBAWE_EMU8000
pdev = acard->devwt;
if (pdev != NULL) {
err = pnp_activate_dev(pdev);
if (err < 0) {
goto __wt_error;
}
awe_port[dev] = pnp_port_start(pdev, 0);
snd_printdd("pnp SB16: wavetable port=0x%llx\n",
(unsigned long long)pnp_port_start(pdev, 0));
} else {
__wt_error:
if (pdev) {
pnp_release_card_device(pdev);
snd_printk(KERN_ERR PFX "WaveTable pnp configure failure\n");
}
acard->devwt = NULL;
awe_port[dev] = -1;
}
#endif
return 0;
}
static void snd_sb16_free(struct snd_card *card)
{
struct snd_card_sb16 *acard = card->private_data;
if (acard == NULL)
return;
release_and_free_resource(acard->fm_res);
}
static int snd_sb16_card_new(int dev, struct snd_card **cardp)
{
struct snd_card *card;
int err;
err = snd_card_create(index[dev], id[dev], THIS_MODULE,
sizeof(struct snd_card_sb16), &card);
if (err < 0)
return err;
card->private_free = snd_sb16_free;
*cardp = card;
return 0;
}
static int snd_sb16_probe(struct snd_card *card, int dev)
{
int xirq, xdma8, xdma16;
struct snd_sb *chip;
struct snd_card_sb16 *acard = card->private_data;
struct snd_opl3 *opl3;
struct snd_hwdep *synth = NULL;
#ifdef CONFIG_SND_SB16_CSP
struct snd_hwdep *xcsp = NULL;
#endif
unsigned long flags;
int err;
xirq = irq[dev];
xdma8 = dma8[dev];
xdma16 = dma16[dev];
if ((err = snd_sbdsp_create(card,
port[dev],
xirq,
snd_sb16dsp_interrupt,
xdma8,
xdma16,
SB_HW_AUTO,
&chip)) < 0)
return err;
acard->chip = chip;
if (chip->hardware != SB_HW_16) {
snd_printk(KERN_ERR PFX "SB 16 chip was not detected at 0x%lx\n", port[dev]);
return -ENODEV;
}
chip->mpu_port = mpu_port[dev];
if (! is_isapnp_selected(dev) && (err = snd_sb16dsp_configure(chip)) < 0)
return err;
if ((err = snd_sb16dsp_pcm(chip, 0, &chip->pcm)) < 0)
return err;
strcpy(card->driver,
#ifdef SNDRV_SBAWE_EMU8000
awe_port[dev] > 0 ? "SB AWE" :
#endif
"SB16");
strcpy(card->shortname, chip->name);
sprintf(card->longname, "%s at 0x%lx, irq %i, dma ",
chip->name,
chip->port,
xirq);
if (xdma8 >= 0)
sprintf(card->longname + strlen(card->longname), "%d", xdma8);
if (xdma16 >= 0)
sprintf(card->longname + strlen(card->longname), "%s%d",
xdma8 >= 0 ? "&" : "", xdma16);
if (chip->mpu_port > 0 && chip->mpu_port != SNDRV_AUTO_PORT) {
if ((err = snd_mpu401_uart_new(card, 0, MPU401_HW_SB,
chip->mpu_port,
MPU401_INFO_IRQ_HOOK, -1,
&chip->rmidi)) < 0)
return err;
chip->rmidi_callback = snd_mpu401_uart_interrupt;
}
#ifdef SNDRV_SBAWE_EMU8000
if (awe_port[dev] == SNDRV_AUTO_PORT)
awe_port[dev] = 0;
#endif
if (fm_port[dev] > 0 && fm_port[dev] != SNDRV_AUTO_PORT) {
if (snd_opl3_create(card, fm_port[dev], fm_port[dev] + 2,
OPL3_HW_OPL3,
acard->fm_res != NULL || fm_port[dev] == port[dev],
&opl3) < 0) {
snd_printk(KERN_ERR PFX "no OPL device at 0x%lx-0x%lx\n",
fm_port[dev], fm_port[dev] + 2);
} else {
#ifdef SNDRV_SBAWE_EMU8000
int seqdev = awe_port[dev] > 0 ? 2 : 1;
#else
int seqdev = 1;
#endif
if ((err = snd_opl3_hwdep_new(opl3, 0, seqdev, &synth)) < 0)
return err;
}
}
if ((err = snd_sbmixer_new(chip)) < 0)
return err;
#ifdef CONFIG_SND_SB16_CSP
if ((chip->hardware == SB_HW_16) && csp[dev]) {
snd_sb_csp_new(chip, synth != NULL ? 1 : 0, &xcsp);
if (xcsp) {
chip->csp = xcsp->private_data;
chip->hardware = SB_HW_16CSP;
} else {
snd_printk(KERN_INFO PFX "warning - CSP chip not detected on soundcard #%i\n", dev + 1);
}
}
#endif
#ifdef SNDRV_SBAWE_EMU8000
if (awe_port[dev] > 0) {
if ((err = snd_emu8000_new(card, 1, awe_port[dev],
seq_ports[dev], NULL)) < 0) {
snd_printk(KERN_ERR PFX "fatal error - EMU-8000 synthesizer not detected at 0x%lx\n", awe_port[dev]);
return err;
}
}
#endif
spin_lock_irqsave(&chip->mixer_lock, flags);
snd_sbmixer_write(chip, SB_DSP4_MIC_AGC,
(snd_sbmixer_read(chip, SB_DSP4_MIC_AGC) & 0x01) |
(mic_agc[dev] ? 0x00 : 0x01));
spin_unlock_irqrestore(&chip->mixer_lock, flags);
if ((err = snd_card_register(card)) < 0)
return err;
return 0;
}
static int snd_sb16_suspend(struct snd_card *card, pm_message_t state)
{
struct snd_card_sb16 *acard = card->private_data;
struct snd_sb *chip = acard->chip;
snd_power_change_state(card, SNDRV_CTL_POWER_D3hot);
snd_pcm_suspend_all(chip->pcm);
snd_sbmixer_suspend(chip);
return 0;
}
static int snd_sb16_resume(struct snd_card *card)
{
struct snd_card_sb16 *acard = card->private_data;
struct snd_sb *chip = acard->chip;
snd_sbdsp_reset(chip);
snd_sbmixer_resume(chip);
snd_power_change_state(card, SNDRV_CTL_POWER_D0);
return 0;
}
static int snd_sb16_isa_probe1(int dev, struct device *pdev)
{
struct snd_card_sb16 *acard;
struct snd_card *card;
int err;
err = snd_sb16_card_new(dev, &card);
if (err < 0)
return err;
acard = card->private_data;
fm_port[dev] = port[dev];
acard->fm_res = request_region(0x388, 4, "SoundBlaster FM");
#ifdef SNDRV_SBAWE_EMU8000
awe_port[dev] = port[dev] + 0x400;
#endif
snd_card_set_dev(card, pdev);
if ((err = snd_sb16_probe(card, dev)) < 0) {
snd_card_free(card);
return err;
}
dev_set_drvdata(pdev, card);
return 0;
}
static int snd_sb16_isa_match(struct device *pdev, unsigned int dev)
{
return enable[dev] && !is_isapnp_selected(dev);
}
static int snd_sb16_isa_probe(struct device *pdev, unsigned int dev)
{
int err;
static int possible_irqs[] = {5, 9, 10, 7, -1};
static int possible_dmas8[] = {1, 3, 0, -1};
static int possible_dmas16[] = {5, 6, 7, -1};
if (irq[dev] == SNDRV_AUTO_IRQ) {
if ((irq[dev] = snd_legacy_find_free_irq(possible_irqs)) < 0) {
snd_printk(KERN_ERR PFX "unable to find a free IRQ\n");
return -EBUSY;
}
}
if (dma8[dev] == SNDRV_AUTO_DMA) {
if ((dma8[dev] = snd_legacy_find_free_dma(possible_dmas8)) < 0) {
snd_printk(KERN_ERR PFX "unable to find a free 8-bit DMA\n");
return -EBUSY;
}
}
if (dma16[dev] == SNDRV_AUTO_DMA) {
if ((dma16[dev] = snd_legacy_find_free_dma(possible_dmas16)) < 0) {
snd_printk(KERN_ERR PFX "unable to find a free 16-bit DMA\n");
return -EBUSY;
}
}
if (port[dev] != SNDRV_AUTO_PORT)
return snd_sb16_isa_probe1(dev, pdev);
else {
static int possible_ports[] = {0x220, 0x240, 0x260, 0x280};
int i;
for (i = 0; i < ARRAY_SIZE(possible_ports); i++) {
port[dev] = possible_ports[i];
err = snd_sb16_isa_probe1(dev, pdev);
if (! err)
return 0;
}
return err;
}
}
static int snd_sb16_isa_remove(struct device *pdev, unsigned int dev)
{
snd_card_free(dev_get_drvdata(pdev));
return 0;
}
static int snd_sb16_isa_suspend(struct device *dev, unsigned int n,
pm_message_t state)
{
return snd_sb16_suspend(dev_get_drvdata(dev), state);
}
static int snd_sb16_isa_resume(struct device *dev, unsigned int n)
{
return snd_sb16_resume(dev_get_drvdata(dev));
}
static int snd_sb16_pnp_detect(struct pnp_card_link *pcard,
const struct pnp_card_device_id *pid)
{
static int dev;
struct snd_card *card;
int res;
for ( ; dev < SNDRV_CARDS; dev++) {
if (!enable[dev] || !isapnp[dev])
continue;
res = snd_sb16_card_new(dev, &card);
if (res < 0)
return res;
snd_card_set_dev(card, &pcard->card->dev);
if ((res = snd_card_sb16_pnp(dev, card->private_data, pcard, pid)) < 0 ||
(res = snd_sb16_probe(card, dev)) < 0) {
snd_card_free(card);
return res;
}
pnp_set_card_drvdata(pcard, card);
dev++;
return 0;
}
return -ENODEV;
}
static void snd_sb16_pnp_remove(struct pnp_card_link *pcard)
{
snd_card_free(pnp_get_card_drvdata(pcard));
pnp_set_card_drvdata(pcard, NULL);
}
static int snd_sb16_pnp_suspend(struct pnp_card_link *pcard, pm_message_t state)
{
return snd_sb16_suspend(pnp_get_card_drvdata(pcard), state);
}
static int snd_sb16_pnp_resume(struct pnp_card_link *pcard)
{
return snd_sb16_resume(pnp_get_card_drvdata(pcard));
}
static int __init alsa_card_sb16_init(void)
{
int err;
err = isa_register_driver(&snd_sb16_isa_driver, SNDRV_CARDS);
#ifdef CONFIG_PNP
if (!err)
isa_registered = 1;
err = pnp_register_card_driver(&sb16_pnpc_driver);
if (!err)
pnp_registered = 1;
if (isa_registered)
err = 0;
#endif
return err;
}
static void __exit alsa_card_sb16_exit(void)
{
#ifdef CONFIG_PNP
if (pnp_registered)
pnp_unregister_card_driver(&sb16_pnpc_driver);
if (isa_registered)
#endif
isa_unregister_driver(&snd_sb16_isa_driver);
}
