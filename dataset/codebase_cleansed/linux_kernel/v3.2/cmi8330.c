static int __devinit cmi8330_add_sb_mixers(struct snd_sb *chip)
{
int idx, err;
unsigned long flags;
spin_lock_irqsave(&chip->mixer_lock, flags);
snd_sbmixer_write(chip, 0x00, 0x00);
spin_unlock_irqrestore(&chip->mixer_lock, flags);
for (idx = 0; idx < ARRAY_SIZE(cmi8330_sb_init_values); idx++) {
spin_lock_irqsave(&chip->mixer_lock, flags);
snd_sbmixer_write(chip, cmi8330_sb_init_values[idx][0],
cmi8330_sb_init_values[idx][1]);
spin_unlock_irqrestore(&chip->mixer_lock, flags);
}
for (idx = 0; idx < ARRAY_SIZE(cmi8330_sb_mixers); idx++) {
if ((err = snd_sbmixer_add_ctl_elem(chip, &cmi8330_sb_mixers[idx])) < 0)
return err;
}
return 0;
}
static int __devinit snd_cmi8330_mixer(struct snd_card *card, struct snd_cmi8330 *acard)
{
unsigned int idx;
int err;
strcpy(card->mixername, (acard->type == CMI8329) ? "CMI8329" : "CMI8330/C3D");
for (idx = 0; idx < ARRAY_SIZE(snd_cmi8330_controls); idx++) {
err = snd_ctl_add(card,
snd_ctl_new1(&snd_cmi8330_controls[idx],
acard->wss));
if (err < 0)
return err;
}
#ifdef ENABLE_SB_MIXER
if ((err = cmi8330_add_sb_mixers(acard->sb)) < 0)
return err;
#endif
return 0;
}
static int __devinit snd_cmi8330_pnp(int dev, struct snd_cmi8330 *acard,
struct pnp_card_link *card,
const struct pnp_card_device_id *id)
{
struct pnp_dev *pdev;
int err;
acard->type = (id->devs[3].id[0]) ? CMI8329 : CMI8330;
acard->cap = pnp_request_card_device(card, id->devs[0].id, NULL);
if (acard->cap == NULL)
return -EBUSY;
acard->play = pnp_request_card_device(card, id->devs[1].id, NULL);
if (acard->play == NULL)
return -EBUSY;
acard->mpu = pnp_request_card_device(card, id->devs[2].id, NULL);
if (acard->mpu == NULL)
return -EBUSY;
pdev = acard->cap;
err = pnp_activate_dev(pdev);
if (err < 0) {
snd_printk(KERN_ERR "AD1848 PnP configure failure\n");
return -EBUSY;
}
wssport[dev] = pnp_port_start(pdev, 0);
wssdma[dev] = pnp_dma(pdev, 0);
wssirq[dev] = pnp_irq(pdev, 0);
if (pnp_port_start(pdev, 1))
fmport[dev] = pnp_port_start(pdev, 1);
pdev = acard->play;
err = pnp_activate_dev(pdev);
if (err < 0) {
snd_printk(KERN_ERR "SB16 PnP configure failure\n");
return -EBUSY;
}
sbport[dev] = pnp_port_start(pdev, 0);
sbdma8[dev] = pnp_dma(pdev, 0);
sbdma16[dev] = pnp_dma(pdev, 1);
sbirq[dev] = pnp_irq(pdev, 0);
if (fmport[dev] == SNDRV_AUTO_PORT) {
if (pnp_port_start(pdev, 1))
fmport[dev] = pnp_port_start(pdev, 1);
else
fmport[dev] = 0x388;
}
pdev = acard->mpu;
err = pnp_activate_dev(pdev);
if (err < 0)
snd_printk(KERN_ERR "MPU-401 PnP configure failure: will be disabled\n");
else {
mpuport[dev] = pnp_port_start(pdev, 0);
mpuirq[dev] = pnp_irq(pdev, 0);
}
return 0;
}
static int snd_cmi8330_playback_open(struct snd_pcm_substream *substream)
{
struct snd_cmi8330 *chip = snd_pcm_substream_chip(substream);
substream->private_data = chip->streams[SNDRV_PCM_STREAM_PLAYBACK].private_data;
return chip->streams[SNDRV_PCM_STREAM_PLAYBACK].open(substream);
}
static int snd_cmi8330_capture_open(struct snd_pcm_substream *substream)
{
struct snd_cmi8330 *chip = snd_pcm_substream_chip(substream);
substream->private_data = chip->streams[SNDRV_PCM_STREAM_CAPTURE].private_data;
return chip->streams[SNDRV_PCM_STREAM_CAPTURE].open(substream);
}
static int __devinit snd_cmi8330_pcm(struct snd_card *card, struct snd_cmi8330 *chip)
{
struct snd_pcm *pcm;
const struct snd_pcm_ops *ops;
int err;
static snd_pcm_open_callback_t cmi_open_callbacks[2] = {
snd_cmi8330_playback_open,
snd_cmi8330_capture_open
};
if ((err = snd_pcm_new(card, (chip->type == CMI8329) ? "CMI8329" : "CMI8330", 0, 1, 1, &pcm)) < 0)
return err;
strcpy(pcm->name, (chip->type == CMI8329) ? "CMI8329" : "CMI8330");
pcm->private_data = chip;
ops = snd_sb16dsp_get_pcm_ops(CMI_SB_STREAM);
chip->streams[CMI_SB_STREAM].ops = *ops;
chip->streams[CMI_SB_STREAM].open = ops->open;
chip->streams[CMI_SB_STREAM].ops.open = cmi_open_callbacks[CMI_SB_STREAM];
chip->streams[CMI_SB_STREAM].private_data = chip->sb;
ops = snd_wss_get_pcm_ops(CMI_AD_STREAM);
chip->streams[CMI_AD_STREAM].ops = *ops;
chip->streams[CMI_AD_STREAM].open = ops->open;
chip->streams[CMI_AD_STREAM].ops.open = cmi_open_callbacks[CMI_AD_STREAM];
chip->streams[CMI_AD_STREAM].private_data = chip->wss;
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_PLAYBACK, &chip->streams[SNDRV_PCM_STREAM_PLAYBACK].ops);
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_CAPTURE, &chip->streams[SNDRV_PCM_STREAM_CAPTURE].ops);
snd_pcm_lib_preallocate_pages_for_all(pcm, SNDRV_DMA_TYPE_DEV,
snd_dma_isa_data(),
64*1024, 128*1024);
chip->pcm = pcm;
return 0;
}
static int snd_cmi8330_suspend(struct snd_card *card)
{
struct snd_cmi8330 *acard = card->private_data;
snd_power_change_state(card, SNDRV_CTL_POWER_D3hot);
snd_pcm_suspend_all(acard->pcm);
acard->wss->suspend(acard->wss);
snd_sbmixer_suspend(acard->sb);
return 0;
}
static int snd_cmi8330_resume(struct snd_card *card)
{
struct snd_cmi8330 *acard = card->private_data;
snd_sbdsp_reset(acard->sb);
snd_sbmixer_suspend(acard->sb);
acard->wss->resume(acard->wss);
snd_power_change_state(card, SNDRV_CTL_POWER_D0);
return 0;
}
static int snd_cmi8330_card_new(int dev, struct snd_card **cardp)
{
struct snd_card *card;
struct snd_cmi8330 *acard;
int err;
err = snd_card_create(index[dev], id[dev], THIS_MODULE,
sizeof(struct snd_cmi8330), &card);
if (err < 0) {
snd_printk(KERN_ERR PFX "could not get a new card\n");
return err;
}
acard = card->private_data;
acard->card = card;
*cardp = card;
return 0;
}
static int __devinit snd_cmi8330_probe(struct snd_card *card, int dev)
{
struct snd_cmi8330 *acard;
int i, err;
struct snd_opl3 *opl3;
acard = card->private_data;
err = snd_wss_create(card, wssport[dev] + 4, -1,
wssirq[dev],
wssdma[dev], -1,
WSS_HW_DETECT, 0, &acard->wss);
if (err < 0) {
snd_printk(KERN_ERR PFX "AD1848 device busy??\n");
return err;
}
if (acard->wss->hardware != WSS_HW_CMI8330) {
snd_printk(KERN_ERR PFX "AD1848 not found during probe\n");
return -ENODEV;
}
if ((err = snd_sbdsp_create(card, sbport[dev],
sbirq[dev],
snd_sb16dsp_interrupt,
sbdma8[dev],
sbdma16[dev],
SB_HW_AUTO, &acard->sb)) < 0) {
snd_printk(KERN_ERR PFX "SB16 device busy??\n");
return err;
}
if (acard->sb->hardware != SB_HW_16) {
snd_printk(KERN_ERR PFX "SB16 not found during probe\n");
return err;
}
snd_wss_out(acard->wss, CS4231_MISC_INFO, 0x40);
for (i = CMI8330_RMUX3D; i <= CMI8330_CDINGAIN; i++)
snd_wss_out(acard->wss, i,
snd_cmi8330_image[i - CMI8330_RMUX3D]);
if ((err = snd_cmi8330_mixer(card, acard)) < 0) {
snd_printk(KERN_ERR PFX "failed to create mixers\n");
return err;
}
if ((err = snd_cmi8330_pcm(card, acard)) < 0) {
snd_printk(KERN_ERR PFX "failed to create pcms\n");
return err;
}
if (fmport[dev] != SNDRV_AUTO_PORT) {
if (snd_opl3_create(card,
fmport[dev], fmport[dev] + 2,
OPL3_HW_AUTO, 0, &opl3) < 0) {
snd_printk(KERN_ERR PFX
"no OPL device at 0x%lx-0x%lx ?\n",
fmport[dev], fmport[dev] + 2);
} else {
err = snd_opl3_hwdep_new(opl3, 0, 1, NULL);
if (err < 0)
return err;
}
}
if (mpuport[dev] != SNDRV_AUTO_PORT) {
if (snd_mpu401_uart_new(card, 0, MPU401_HW_MPU401,
mpuport[dev], 0, mpuirq[dev],
NULL) < 0)
printk(KERN_ERR PFX "no MPU-401 device at 0x%lx.\n",
mpuport[dev]);
}
strcpy(card->driver, (acard->type == CMI8329) ? "CMI8329" : "CMI8330/C3D");
strcpy(card->shortname, (acard->type == CMI8329) ? "C-Media CMI8329" : "C-Media CMI8330/C3D");
sprintf(card->longname, "%s at 0x%lx, irq %d, dma %d",
card->shortname,
acard->wss->port,
wssirq[dev],
wssdma[dev]);
return snd_card_register(card);
}
static int __devinit snd_cmi8330_isa_match(struct device *pdev,
unsigned int dev)
{
if (!enable[dev] || is_isapnp_selected(dev))
return 0;
if (wssport[dev] == SNDRV_AUTO_PORT) {
snd_printk(KERN_ERR PFX "specify wssport\n");
return 0;
}
if (sbport[dev] == SNDRV_AUTO_PORT) {
snd_printk(KERN_ERR PFX "specify sbport\n");
return 0;
}
return 1;
}
static int __devinit snd_cmi8330_isa_probe(struct device *pdev,
unsigned int dev)
{
struct snd_card *card;
int err;
err = snd_cmi8330_card_new(dev, &card);
if (err < 0)
return err;
snd_card_set_dev(card, pdev);
if ((err = snd_cmi8330_probe(card, dev)) < 0) {
snd_card_free(card);
return err;
}
dev_set_drvdata(pdev, card);
return 0;
}
static int __devexit snd_cmi8330_isa_remove(struct device *devptr,
unsigned int dev)
{
snd_card_free(dev_get_drvdata(devptr));
dev_set_drvdata(devptr, NULL);
return 0;
}
static int snd_cmi8330_isa_suspend(struct device *dev, unsigned int n,
pm_message_t state)
{
return snd_cmi8330_suspend(dev_get_drvdata(dev));
}
static int snd_cmi8330_isa_resume(struct device *dev, unsigned int n)
{
return snd_cmi8330_resume(dev_get_drvdata(dev));
}
static int __devinit snd_cmi8330_pnp_detect(struct pnp_card_link *pcard,
const struct pnp_card_device_id *pid)
{
static int dev;
struct snd_card *card;
int res;
for ( ; dev < SNDRV_CARDS; dev++) {
if (enable[dev] && isapnp[dev])
break;
}
if (dev >= SNDRV_CARDS)
return -ENODEV;
res = snd_cmi8330_card_new(dev, &card);
if (res < 0)
return res;
if ((res = snd_cmi8330_pnp(dev, card->private_data, pcard, pid)) < 0) {
snd_printk(KERN_ERR PFX "PnP detection failed\n");
snd_card_free(card);
return res;
}
snd_card_set_dev(card, &pcard->card->dev);
if ((res = snd_cmi8330_probe(card, dev)) < 0) {
snd_card_free(card);
return res;
}
pnp_set_card_drvdata(pcard, card);
dev++;
return 0;
}
static void __devexit snd_cmi8330_pnp_remove(struct pnp_card_link * pcard)
{
snd_card_free(pnp_get_card_drvdata(pcard));
pnp_set_card_drvdata(pcard, NULL);
}
static int snd_cmi8330_pnp_suspend(struct pnp_card_link *pcard, pm_message_t state)
{
return snd_cmi8330_suspend(pnp_get_card_drvdata(pcard));
}
static int snd_cmi8330_pnp_resume(struct pnp_card_link *pcard)
{
return snd_cmi8330_resume(pnp_get_card_drvdata(pcard));
}
static int __init alsa_card_cmi8330_init(void)
{
int err;
err = isa_register_driver(&snd_cmi8330_driver, SNDRV_CARDS);
#ifdef CONFIG_PNP
if (!err)
isa_registered = 1;
err = pnp_register_card_driver(&cmi8330_pnpc_driver);
if (!err)
pnp_registered = 1;
if (isa_registered)
err = 0;
#endif
return err;
}
static void __exit alsa_card_cmi8330_exit(void)
{
#ifdef CONFIG_PNP
if (pnp_registered)
pnp_unregister_card_driver(&cmi8330_pnpc_driver);
if (isa_registered)
#endif
isa_unregister_driver(&snd_cmi8330_driver);
}
