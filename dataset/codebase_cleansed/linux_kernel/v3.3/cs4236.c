static int __devinit snd_cs423x_pnp_init_wss(int dev, struct pnp_dev *pdev)
{
if (pnp_activate_dev(pdev) < 0) {
printk(KERN_ERR IDENT " WSS PnP configure failed for WSS (out of resources?)\n");
return -EBUSY;
}
port[dev] = pnp_port_start(pdev, 0);
if (fm_port[dev] > 0)
fm_port[dev] = pnp_port_start(pdev, 1);
sb_port[dev] = pnp_port_start(pdev, 2);
irq[dev] = pnp_irq(pdev, 0);
dma1[dev] = pnp_dma(pdev, 0);
dma2[dev] = pnp_dma(pdev, 1) == 4 ? -1 : (int)pnp_dma(pdev, 1);
snd_printdd("isapnp WSS: wss port=0x%lx, fm port=0x%lx, sb port=0x%lx\n",
port[dev], fm_port[dev], sb_port[dev]);
snd_printdd("isapnp WSS: irq=%i, dma1=%i, dma2=%i\n",
irq[dev], dma1[dev], dma2[dev]);
return 0;
}
static int __devinit snd_cs423x_pnp_init_ctrl(int dev, struct pnp_dev *pdev)
{
if (pnp_activate_dev(pdev) < 0) {
printk(KERN_ERR IDENT " CTRL PnP configure failed for WSS (out of resources?)\n");
return -EBUSY;
}
cport[dev] = pnp_port_start(pdev, 0);
snd_printdd("isapnp CTRL: control port=0x%lx\n", cport[dev]);
return 0;
}
static int __devinit snd_cs423x_pnp_init_mpu(int dev, struct pnp_dev *pdev)
{
if (pnp_activate_dev(pdev) < 0) {
printk(KERN_ERR IDENT " MPU401 PnP configure failed for WSS (out of resources?)\n");
mpu_port[dev] = SNDRV_AUTO_PORT;
mpu_irq[dev] = SNDRV_AUTO_IRQ;
} else {
mpu_port[dev] = pnp_port_start(pdev, 0);
if (mpu_irq[dev] >= 0 &&
pnp_irq_valid(pdev, 0) && pnp_irq(pdev, 0) >= 0) {
mpu_irq[dev] = pnp_irq(pdev, 0);
} else {
mpu_irq[dev] = -1;
}
}
snd_printdd("isapnp MPU: port=0x%lx, irq=%i\n", mpu_port[dev], mpu_irq[dev]);
return 0;
}
static int __devinit snd_card_cs423x_pnp(int dev, struct snd_card_cs4236 *acard,
struct pnp_dev *pdev,
struct pnp_dev *cdev)
{
acard->wss = pdev;
if (snd_cs423x_pnp_init_wss(dev, acard->wss) < 0)
return -EBUSY;
if (cdev)
cport[dev] = pnp_port_start(cdev, 0);
else
cport[dev] = -1;
return 0;
}
static int __devinit snd_card_cs423x_pnpc(int dev, struct snd_card_cs4236 *acard,
struct pnp_card_link *card,
const struct pnp_card_device_id *id)
{
acard->wss = pnp_request_card_device(card, id->devs[0].id, NULL);
if (acard->wss == NULL)
return -EBUSY;
acard->ctrl = pnp_request_card_device(card, id->devs[1].id, NULL);
if (acard->ctrl == NULL)
return -EBUSY;
if (id->devs[2].id[0]) {
acard->mpu = pnp_request_card_device(card, id->devs[2].id, NULL);
if (acard->mpu == NULL)
return -EBUSY;
}
if (snd_cs423x_pnp_init_wss(dev, acard->wss) < 0)
return -EBUSY;
if (acard->ctrl && cport[dev] > 0) {
if (snd_cs423x_pnp_init_ctrl(dev, acard->ctrl) < 0)
return -EBUSY;
}
if (acard->mpu && mpu_port[dev] > 0) {
if (snd_cs423x_pnp_init_mpu(dev, acard->mpu) < 0)
return -EBUSY;
}
return 0;
}
static void snd_card_cs4236_free(struct snd_card *card)
{
struct snd_card_cs4236 *acard = card->private_data;
release_and_free_resource(acard->res_sb_port);
}
static int snd_cs423x_card_new(int dev, struct snd_card **cardp)
{
struct snd_card *card;
int err;
err = snd_card_create(index[dev], id[dev], THIS_MODULE,
sizeof(struct snd_card_cs4236), &card);
if (err < 0)
return err;
card->private_free = snd_card_cs4236_free;
*cardp = card;
return 0;
}
static int __devinit snd_cs423x_probe(struct snd_card *card, int dev)
{
struct snd_card_cs4236 *acard;
struct snd_pcm *pcm;
struct snd_wss *chip;
struct snd_opl3 *opl3;
int err;
acard = card->private_data;
if (sb_port[dev] > 0 && sb_port[dev] != SNDRV_AUTO_PORT)
if ((acard->res_sb_port = request_region(sb_port[dev], 16, IDENT " SB")) == NULL) {
printk(KERN_ERR IDENT ": unable to register SB port at 0x%lx\n", sb_port[dev]);
return -EBUSY;
}
err = snd_cs4236_create(card, port[dev], cport[dev],
irq[dev],
dma1[dev], dma2[dev],
WSS_HW_DETECT3, 0, &chip);
if (err < 0)
return err;
acard->chip = chip;
if (chip->hardware & WSS_HW_CS4236B_MASK) {
err = snd_cs4236_pcm(chip, 0, &pcm);
if (err < 0)
return err;
err = snd_cs4236_mixer(chip);
if (err < 0)
return err;
} else {
err = snd_wss_pcm(chip, 0, &pcm);
if (err < 0)
return err;
err = snd_wss_mixer(chip);
if (err < 0)
return err;
}
strcpy(card->driver, pcm->name);
strcpy(card->shortname, pcm->name);
sprintf(card->longname, "%s at 0x%lx, irq %i, dma %i",
pcm->name,
chip->port,
irq[dev],
dma1[dev]);
if (dma2[dev] >= 0)
sprintf(card->longname + strlen(card->longname), "&%d", dma2[dev]);
err = snd_wss_timer(chip, 0, NULL);
if (err < 0)
return err;
if (fm_port[dev] > 0 && fm_port[dev] != SNDRV_AUTO_PORT) {
if (snd_opl3_create(card,
fm_port[dev], fm_port[dev] + 2,
OPL3_HW_OPL3_CS, 0, &opl3) < 0) {
printk(KERN_WARNING IDENT ": OPL3 not detected\n");
} else {
if ((err = snd_opl3_hwdep_new(opl3, 0, 1, NULL)) < 0)
return err;
}
}
if (mpu_port[dev] > 0 && mpu_port[dev] != SNDRV_AUTO_PORT) {
if (mpu_irq[dev] == SNDRV_AUTO_IRQ)
mpu_irq[dev] = -1;
if (snd_mpu401_uart_new(card, 0, MPU401_HW_CS4232,
mpu_port[dev], 0,
mpu_irq[dev], NULL) < 0)
printk(KERN_WARNING IDENT ": MPU401 not detected\n");
}
return snd_card_register(card);
}
static int __devinit snd_cs423x_isa_match(struct device *pdev,
unsigned int dev)
{
if (!enable[dev] || is_isapnp_selected(dev))
return 0;
if (port[dev] == SNDRV_AUTO_PORT) {
dev_err(pdev, "please specify port\n");
return 0;
}
if (cport[dev] == SNDRV_AUTO_PORT) {
dev_err(pdev, "please specify cport\n");
return 0;
}
if (irq[dev] == SNDRV_AUTO_IRQ) {
dev_err(pdev, "please specify irq\n");
return 0;
}
if (dma1[dev] == SNDRV_AUTO_DMA) {
dev_err(pdev, "please specify dma1\n");
return 0;
}
return 1;
}
static int __devinit snd_cs423x_isa_probe(struct device *pdev,
unsigned int dev)
{
struct snd_card *card;
int err;
err = snd_cs423x_card_new(dev, &card);
if (err < 0)
return err;
snd_card_set_dev(card, pdev);
if ((err = snd_cs423x_probe(card, dev)) < 0) {
snd_card_free(card);
return err;
}
dev_set_drvdata(pdev, card);
return 0;
}
static int __devexit snd_cs423x_isa_remove(struct device *pdev,
unsigned int dev)
{
snd_card_free(dev_get_drvdata(pdev));
dev_set_drvdata(pdev, NULL);
return 0;
}
static int snd_cs423x_suspend(struct snd_card *card)
{
struct snd_card_cs4236 *acard = card->private_data;
snd_power_change_state(card, SNDRV_CTL_POWER_D3hot);
acard->chip->suspend(acard->chip);
return 0;
}
static int snd_cs423x_resume(struct snd_card *card)
{
struct snd_card_cs4236 *acard = card->private_data;
acard->chip->resume(acard->chip);
snd_power_change_state(card, SNDRV_CTL_POWER_D0);
return 0;
}
static int snd_cs423x_isa_suspend(struct device *dev, unsigned int n,
pm_message_t state)
{
return snd_cs423x_suspend(dev_get_drvdata(dev));
}
static int snd_cs423x_isa_resume(struct device *dev, unsigned int n)
{
return snd_cs423x_resume(dev_get_drvdata(dev));
}
static int __devinit snd_cs423x_pnpbios_detect(struct pnp_dev *pdev,
const struct pnp_device_id *id)
{
static int dev;
int err;
struct snd_card *card;
struct pnp_dev *cdev;
char cid[PNP_ID_LEN];
if (pnp_device_is_isapnp(pdev))
return -ENOENT;
for (; dev < SNDRV_CARDS; dev++) {
if (enable[dev] && isapnp[dev])
break;
}
if (dev >= SNDRV_CARDS)
return -ENODEV;
strcpy(cid, pdev->id[0].id);
cid[5] = '1';
cdev = NULL;
list_for_each_entry(cdev, &(pdev->protocol->devices), protocol_list) {
if (!strcmp(cdev->id[0].id, cid))
break;
}
err = snd_cs423x_card_new(dev, &card);
if (err < 0)
return err;
err = snd_card_cs423x_pnp(dev, card->private_data, pdev, cdev);
if (err < 0) {
printk(KERN_ERR "PnP BIOS detection failed for " IDENT "\n");
snd_card_free(card);
return err;
}
snd_card_set_dev(card, &pdev->dev);
if ((err = snd_cs423x_probe(card, dev)) < 0) {
snd_card_free(card);
return err;
}
pnp_set_drvdata(pdev, card);
dev++;
return 0;
}
static void __devexit snd_cs423x_pnp_remove(struct pnp_dev *pdev)
{
snd_card_free(pnp_get_drvdata(pdev));
pnp_set_drvdata(pdev, NULL);
}
static int snd_cs423x_pnp_suspend(struct pnp_dev *pdev, pm_message_t state)
{
return snd_cs423x_suspend(pnp_get_drvdata(pdev));
}
static int snd_cs423x_pnp_resume(struct pnp_dev *pdev)
{
return snd_cs423x_resume(pnp_get_drvdata(pdev));
}
static int __devinit snd_cs423x_pnpc_detect(struct pnp_card_link *pcard,
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
res = snd_cs423x_card_new(dev, &card);
if (res < 0)
return res;
if ((res = snd_card_cs423x_pnpc(dev, card->private_data, pcard, pid)) < 0) {
printk(KERN_ERR "isapnp detection failed and probing for " IDENT
" is not supported\n");
snd_card_free(card);
return res;
}
snd_card_set_dev(card, &pcard->card->dev);
if ((res = snd_cs423x_probe(card, dev)) < 0) {
snd_card_free(card);
return res;
}
pnp_set_card_drvdata(pcard, card);
dev++;
return 0;
}
static void __devexit snd_cs423x_pnpc_remove(struct pnp_card_link * pcard)
{
snd_card_free(pnp_get_card_drvdata(pcard));
pnp_set_card_drvdata(pcard, NULL);
}
static int snd_cs423x_pnpc_suspend(struct pnp_card_link *pcard, pm_message_t state)
{
return snd_cs423x_suspend(pnp_get_card_drvdata(pcard));
}
static int snd_cs423x_pnpc_resume(struct pnp_card_link *pcard)
{
return snd_cs423x_resume(pnp_get_card_drvdata(pcard));
}
static int __init alsa_card_cs423x_init(void)
{
int err;
err = isa_register_driver(&cs423x_isa_driver, SNDRV_CARDS);
#ifdef CONFIG_PNP
if (!err)
isa_registered = 1;
err = pnp_register_driver(&cs423x_pnp_driver);
if (!err)
pnp_registered = 1;
err = pnp_register_card_driver(&cs423x_pnpc_driver);
if (!err)
pnpc_registered = 1;
if (pnp_registered)
err = 0;
if (isa_registered)
err = 0;
#endif
return err;
}
static void __exit alsa_card_cs423x_exit(void)
{
#ifdef CONFIG_PNP
if (pnpc_registered)
pnp_unregister_card_driver(&cs423x_pnpc_driver);
if (pnp_registered)
pnp_unregister_driver(&cs423x_pnp_driver);
if (isa_registered)
#endif
isa_unregister_driver(&cs423x_isa_driver);
}
