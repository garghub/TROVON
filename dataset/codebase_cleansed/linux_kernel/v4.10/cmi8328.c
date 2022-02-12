static u8 snd_cmi8328_cfg_read(u16 port, u8 reg)
{
outb(0x43, port + 3);
outb(0x21, port + 3);
outb(reg, port + 3);
return inb(port);
}
static void snd_cmi8328_cfg_write(u16 port, u8 reg, u8 val)
{
outb(0x43, port + 3);
outb(0x21, port + 3);
outb(reg, port + 3);
outb(val, port + 3);
}
static void snd_cmi8328_cfg_save(u16 port, u8 cfg[])
{
cfg[0] = snd_cmi8328_cfg_read(port, CFG1);
cfg[1] = snd_cmi8328_cfg_read(port, CFG2);
cfg[2] = snd_cmi8328_cfg_read(port, CFG3);
}
static void snd_cmi8328_cfg_restore(u16 port, u8 cfg[])
{
snd_cmi8328_cfg_write(port, CFG1, cfg[0]);
snd_cmi8328_cfg_write(port, CFG2, cfg[1]);
snd_cmi8328_cfg_write(port, CFG3, cfg[2]);
}
static int snd_cmi8328_mixer(struct snd_wss *chip)
{
struct snd_card *card;
struct snd_ctl_elem_id id1, id2;
int err;
card = chip->card;
memset(&id1, 0, sizeof(id1));
memset(&id2, 0, sizeof(id2));
id1.iface = id2.iface = SNDRV_CTL_ELEM_IFACE_MIXER;
strcpy(id1.name, "Aux Playback Switch");
strcpy(id2.name, "CD Playback Switch");
err = snd_ctl_rename_id(card, &id1, &id2);
if (err < 0) {
snd_printk(KERN_ERR "error renaming control\n");
return err;
}
strcpy(id1.name, "Aux Playback Volume");
strcpy(id2.name, "CD Playback Volume");
err = snd_ctl_rename_id(card, &id1, &id2);
if (err < 0) {
snd_printk(KERN_ERR "error renaming control\n");
return err;
}
strcpy(id1.name, "Aux Playback Switch");
id1.index = 1;
strcpy(id2.name, "Synth Playback Switch");
err = snd_ctl_rename_id(card, &id1, &id2);
if (err < 0) {
snd_printk(KERN_ERR "error renaming control\n");
return err;
}
strcpy(id1.name, "Aux Playback Volume");
id1.index = 1;
strcpy(id2.name, "Synth Playback Volume");
err = snd_ctl_rename_id(card, &id1, &id2);
if (err < 0) {
snd_printk(KERN_ERR "error renaming control\n");
return err;
}
return 0;
}
int array_find(int array[], int item)
{
int i;
for (i = 0; array[i] != -1; i++)
if (array[i] == item)
return i;
return -1;
}
int array_find_l(long array[], long item)
{
int i;
for (i = 0; array[i] != -1; i++)
if (array[i] == item)
return i;
return -1;
}
static int snd_cmi8328_probe(struct device *pdev, unsigned int ndev)
{
struct snd_card *card;
struct snd_opl3 *opl3;
struct snd_cmi8328 *cmi;
#ifdef SUPPORT_JOYSTICK
struct resource *res;
#endif
int err, pos;
static long mpu_ports[] = { 0x330, 0x300, 0x310, 0x320, 0x332, 0x334,
0x336, -1 };
static u8 mpu_port_bits[] = { 3, 0, 1, 2, 4, 5, 6 };
static int mpu_irqs[] = { 9, 7, 5, 3, -1 };
static u8 mpu_irq_bits[] = { 3, 2, 1, 0 };
static int irqs[] = { 9, 10, 11, 7, -1 };
static u8 irq_bits[] = { 2, 3, 4, 1 };
static int dma1s[] = { 3, 1, 0, -1 };
static u8 dma_bits[] = { 3, 2, 1 };
static int dma2s[][2] = { {1, -1}, {0, -1}, {-1, -1}, {0, -1} };
u16 port = cmi8328_ports[ndev];
u8 val;
if (snd_cmi8328_cfg_read(port, CFG1) == 0xff)
return -ENODEV;
snd_cmi8328_cfg_write(port, CFG1, CFG1_SB_DISABLE);
if (snd_cmi8328_cfg_read(port, CFG1) != CFG1_SB_DISABLE)
return -ENODEV;
snd_cmi8328_cfg_write(port, CFG2, 0);
snd_cmi8328_cfg_write(port, CFG3, 0);
if (irq[ndev] == SNDRV_AUTO_IRQ) {
irq[ndev] = snd_legacy_find_free_irq(irqs);
if (irq[ndev] < 0) {
snd_printk(KERN_ERR "unable to find a free IRQ\n");
return -EBUSY;
}
}
if (dma1[ndev] == SNDRV_AUTO_DMA) {
dma1[ndev] = snd_legacy_find_free_dma(dma1s);
if (dma1[ndev] < 0) {
snd_printk(KERN_ERR "unable to find a free DMA1\n");
return -EBUSY;
}
}
if (dma2[ndev] == SNDRV_AUTO_DMA) {
dma2[ndev] = snd_legacy_find_free_dma(dma2s[dma1[ndev] % 4]);
if (dma2[ndev] < 0) {
snd_printk(KERN_WARNING "unable to find a free DMA2, full-duplex will not work\n");
dma2[ndev] = -1;
}
}
pos = array_find(irqs, irq[ndev]);
if (pos < 0) {
snd_printk(KERN_ERR "invalid IRQ %d\n", irq[ndev]);
return -EINVAL;
}
val = irq_bits[pos] << 3;
pos = array_find(dma1s, dma1[ndev]);
if (pos < 0) {
snd_printk(KERN_ERR "invalid DMA1 %d\n", dma1[ndev]);
return -EINVAL;
}
val |= dma_bits[pos];
if (dma2[ndev] >= 0 && dma1[ndev] != dma2[ndev]) {
pos = array_find(dma2s[dma1[ndev]], dma2[ndev]);
if (pos < 0) {
snd_printk(KERN_ERR "invalid DMA2 %d\n", dma2[ndev]);
return -EINVAL;
}
val |= 0x04;
}
outb(val, port);
err = snd_card_new(pdev, index[ndev], id[ndev], THIS_MODULE,
sizeof(struct snd_cmi8328), &card);
if (err < 0)
return err;
cmi = card->private_data;
cmi->card = card;
cmi->port = port;
cmi->wss_cfg = val;
err = snd_wss_create(card, port + 4, -1, irq[ndev], dma1[ndev],
dma2[ndev], WSS_HW_DETECT, 0, &cmi->wss);
if (err < 0)
goto error;
err = snd_wss_pcm(cmi->wss, 0);
if (err < 0)
goto error;
err = snd_wss_mixer(cmi->wss);
if (err < 0)
goto error;
err = snd_cmi8328_mixer(cmi->wss);
if (err < 0)
goto error;
if (snd_wss_timer(cmi->wss, 0) < 0)
snd_printk(KERN_WARNING "error initializing WSS timer\n");
if (mpuport[ndev] == SNDRV_AUTO_PORT) {
mpuport[ndev] = snd_legacy_find_free_ioport(mpu_ports, 2);
if (mpuport[ndev] < 0)
snd_printk(KERN_ERR "unable to find a free MPU401 port\n");
}
if (mpuirq[ndev] == SNDRV_AUTO_IRQ) {
mpuirq[ndev] = snd_legacy_find_free_irq(mpu_irqs);
if (mpuirq[ndev] < 0)
snd_printk(KERN_ERR "unable to find a free MPU401 IRQ\n");
}
if (mpuport[ndev] > 0 && mpuirq[ndev] > 0) {
val = CFG2_MPU_ENABLE;
pos = array_find_l(mpu_ports, mpuport[ndev]);
if (pos < 0)
snd_printk(KERN_WARNING "invalid MPU401 port 0x%lx\n",
mpuport[ndev]);
else {
val |= mpu_port_bits[pos] << 5;
pos = array_find(mpu_irqs, mpuirq[ndev]);
if (pos < 0)
snd_printk(KERN_WARNING "invalid MPU401 IRQ %d\n",
mpuirq[ndev]);
else {
val |= mpu_irq_bits[pos] << 3;
snd_cmi8328_cfg_write(port, CFG2, val);
if (snd_mpu401_uart_new(card, 0,
MPU401_HW_MPU401, mpuport[ndev],
0, mpuirq[ndev], NULL) < 0)
snd_printk(KERN_ERR "error initializing MPU401\n");
}
}
}
if (snd_opl3_create(card, 0x388, 0x38a, OPL3_HW_AUTO, 0, &opl3) < 0)
snd_printk(KERN_ERR "error initializing OPL3\n");
else
if (snd_opl3_hwdep_new(opl3, 0, 1, NULL) < 0)
snd_printk(KERN_WARNING "error initializing OPL3 hwdep\n");
strcpy(card->driver, "CMI8328");
strcpy(card->shortname, "C-Media CMI8328");
sprintf(card->longname, "%s at 0x%lx, irq %d, dma %d,%d",
card->shortname, cmi->wss->port, irq[ndev], dma1[ndev],
(dma2[ndev] >= 0) ? dma2[ndev] : dma1[ndev]);
dev_set_drvdata(pdev, card);
err = snd_card_register(card);
if (err < 0)
goto error;
#ifdef SUPPORT_JOYSTICK
if (!gameport[ndev])
return 0;
res = request_region(0x200, 8, "CMI8328 gameport");
if (!res)
snd_printk(KERN_WARNING "unable to allocate gameport I/O port\n");
else {
struct gameport *gp = cmi->gameport = gameport_allocate_port();
if (!cmi->gameport)
release_and_free_resource(res);
else {
gameport_set_name(gp, "CMI8328 Gameport");
gameport_set_phys(gp, "%s/gameport0", dev_name(pdev));
gameport_set_dev_parent(gp, pdev);
gp->io = 0x200;
gameport_set_port_data(gp, res);
snd_cmi8328_cfg_write(port, CFG1,
CFG1_SB_DISABLE | CFG1_GAMEPORT);
gameport_register_port(gp);
}
}
#endif
return 0;
error:
snd_card_free(card);
return err;
}
static int snd_cmi8328_remove(struct device *pdev, unsigned int dev)
{
struct snd_card *card = dev_get_drvdata(pdev);
struct snd_cmi8328 *cmi = card->private_data;
#ifdef SUPPORT_JOYSTICK
if (cmi->gameport) {
struct resource *res = gameport_get_port_data(cmi->gameport);
gameport_unregister_port(cmi->gameport);
release_and_free_resource(res);
}
#endif
snd_cmi8328_cfg_write(cmi->port, CFG1, CFG1_SB_DISABLE);
snd_cmi8328_cfg_write(cmi->port, CFG2, 0);
snd_cmi8328_cfg_write(cmi->port, CFG3, 0);
snd_card_free(card);
return 0;
}
static int snd_cmi8328_suspend(struct device *pdev, unsigned int n,
pm_message_t state)
{
struct snd_card *card = dev_get_drvdata(pdev);
struct snd_cmi8328 *cmi;
if (!card)
return 0;
cmi = card->private_data;
snd_cmi8328_cfg_save(cmi->port, cmi->cfg);
snd_power_change_state(card, SNDRV_CTL_POWER_D3hot);
snd_pcm_suspend_all(cmi->wss->pcm);
cmi->wss->suspend(cmi->wss);
return 0;
}
static int snd_cmi8328_resume(struct device *pdev, unsigned int n)
{
struct snd_card *card = dev_get_drvdata(pdev);
struct snd_cmi8328 *cmi;
if (!card)
return 0;
cmi = card->private_data;
snd_cmi8328_cfg_restore(cmi->port, cmi->cfg);
outb(cmi->wss_cfg, cmi->port);
cmi->wss->resume(cmi->wss);
snd_power_change_state(card, SNDRV_CTL_POWER_D0);
return 0;
}
