static unsigned char __snd_opl3sa2_read(struct snd_opl3sa2 *chip, unsigned char reg)
{
unsigned char result;
#if 0
outb(0x1d, port);
printk(KERN_DEBUG "read [0x%lx] = 0x%x\n", port, inb(port));
#endif
outb(reg, chip->port);
result = inb(chip->port + 1);
#if 0
printk(KERN_DEBUG "read [0x%lx] = 0x%x [0x%x]\n",
port, result, inb(port));
#endif
return result;
}
static unsigned char snd_opl3sa2_read(struct snd_opl3sa2 *chip, unsigned char reg)
{
unsigned long flags;
unsigned char result;
spin_lock_irqsave(&chip->reg_lock, flags);
result = __snd_opl3sa2_read(chip, reg);
spin_unlock_irqrestore(&chip->reg_lock, flags);
return result;
}
static void __snd_opl3sa2_write(struct snd_opl3sa2 *chip, unsigned char reg, unsigned char value)
{
#if 0
outb(0x1d, port);
#endif
outb(reg, chip->port);
outb(value, chip->port + 1);
chip->ctlregs[reg] = value;
}
static void snd_opl3sa2_write(struct snd_opl3sa2 *chip, unsigned char reg, unsigned char value)
{
unsigned long flags;
spin_lock_irqsave(&chip->reg_lock, flags);
__snd_opl3sa2_write(chip, reg, value);
spin_unlock_irqrestore(&chip->reg_lock, flags);
}
static int __devinit snd_opl3sa2_detect(struct snd_card *card)
{
struct snd_opl3sa2 *chip = card->private_data;
unsigned long port;
unsigned char tmp, tmp1;
char str[2];
port = chip->port;
if ((chip->res_port = request_region(port, 2, "OPL3-SA control")) == NULL) {
snd_printk(KERN_ERR PFX "can't grab port 0x%lx\n", port);
return -EBUSY;
}
chip->version = 0;
tmp = snd_opl3sa2_read(chip, OPL3SA2_MISC);
if (tmp == 0xff) {
snd_printd("OPL3-SA [0x%lx] detect = 0x%x\n", port, tmp);
return -ENODEV;
}
switch (tmp & 0x07) {
case 0x01:
chip->version = 2;
break;
default:
chip->version = 3;
break;
}
str[0] = chip->version + '0';
str[1] = 0;
strcat(card->shortname, str);
snd_opl3sa2_write(chip, OPL3SA2_MISC, tmp ^ 7);
if ((tmp1 = snd_opl3sa2_read(chip, OPL3SA2_MISC)) != tmp) {
snd_printd("OPL3-SA [0x%lx] detect (1) = 0x%x (0x%x)\n", port, tmp, tmp1);
return -ENODEV;
}
tmp = snd_opl3sa2_read(chip, OPL3SA2_MIC);
snd_opl3sa2_write(chip, OPL3SA2_MIC, 0x8a);
if (((tmp1 = snd_opl3sa2_read(chip, OPL3SA2_MIC)) & 0x9f) != 0x8a) {
snd_printd("OPL3-SA [0x%lx] detect (2) = 0x%x (0x%x)\n", port, tmp, tmp1);
return -ENODEV;
}
snd_opl3sa2_write(chip, OPL3SA2_MIC, 0x9f);
snd_opl3sa2_write(chip, OPL3SA2_PM_CTRL, OPL3SA2_PM_D0);
if (chip->version > 2) {
snd_opl3sa2_write(chip, OPL3SA2_SYS_CTRL, (chip->ymode << 4));
} else {
snd_opl3sa2_write(chip, OPL3SA2_SYS_CTRL, 0x00);
}
snd_opl3sa2_write(chip, OPL3SA2_IRQ_CONFIG, 0x0d);
if (chip->single_dma) {
snd_opl3sa2_write(chip, OPL3SA2_DMA_CONFIG, 0x03);
} else {
snd_opl3sa2_write(chip, OPL3SA2_DMA_CONFIG, 0x21);
}
snd_opl3sa2_write(chip, OPL3SA2_MISC, 0x80 | (tmp & 7));
if (chip->version > 2) {
snd_opl3sa2_write(chip, OPL3SA3_DGTL_DOWN, 0x00);
snd_opl3sa2_write(chip, OPL3SA3_ANLG_DOWN, 0x00);
}
return 0;
}
static irqreturn_t snd_opl3sa2_interrupt(int irq, void *dev_id)
{
unsigned short status;
struct snd_card *card = dev_id;
struct snd_opl3sa2 *chip;
int handled = 0;
if (card == NULL)
return IRQ_NONE;
chip = card->private_data;
status = snd_opl3sa2_read(chip, OPL3SA2_IRQ_STATUS);
if (status & 0x20) {
handled = 1;
snd_opl3_interrupt(chip->synth);
}
if ((status & 0x10) && chip->rmidi != NULL) {
handled = 1;
snd_mpu401_uart_interrupt(irq, chip->rmidi->private_data);
}
if (status & 0x07) {
handled = 1;
snd_wss_interrupt(irq, chip->wss);
}
if (status & 0x40) {
handled = 1;
snd_opl3sa2_read(chip, OPL3SA2_MASTER_RIGHT);
snd_opl3sa2_read(chip, OPL3SA2_MASTER_LEFT);
if (chip->master_switch && chip->master_volume) {
snd_ctl_notify(card, SNDRV_CTL_EVENT_MASK_VALUE,
&chip->master_switch->id);
snd_ctl_notify(card, SNDRV_CTL_EVENT_MASK_VALUE,
&chip->master_volume->id);
}
}
return IRQ_RETVAL(handled);
}
static int snd_opl3sa2_get_single(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_opl3sa2 *chip = snd_kcontrol_chip(kcontrol);
unsigned long flags;
int reg = kcontrol->private_value & 0xff;
int shift = (kcontrol->private_value >> 8) & 0xff;
int mask = (kcontrol->private_value >> 16) & 0xff;
int invert = (kcontrol->private_value >> 24) & 0xff;
spin_lock_irqsave(&chip->reg_lock, flags);
ucontrol->value.integer.value[0] = (chip->ctlregs[reg] >> shift) & mask;
spin_unlock_irqrestore(&chip->reg_lock, flags);
if (invert)
ucontrol->value.integer.value[0] = mask - ucontrol->value.integer.value[0];
return 0;
}
static int snd_opl3sa2_put_single(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_opl3sa2 *chip = snd_kcontrol_chip(kcontrol);
unsigned long flags;
int reg = kcontrol->private_value & 0xff;
int shift = (kcontrol->private_value >> 8) & 0xff;
int mask = (kcontrol->private_value >> 16) & 0xff;
int invert = (kcontrol->private_value >> 24) & 0xff;
int change;
unsigned short val, oval;
val = (ucontrol->value.integer.value[0] & mask);
if (invert)
val = mask - val;
val <<= shift;
spin_lock_irqsave(&chip->reg_lock, flags);
oval = chip->ctlregs[reg];
val = (oval & ~(mask << shift)) | val;
change = val != oval;
__snd_opl3sa2_write(chip, reg, val);
spin_unlock_irqrestore(&chip->reg_lock, flags);
return change;
}
static int snd_opl3sa2_get_double(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_opl3sa2 *chip = snd_kcontrol_chip(kcontrol);
unsigned long flags;
int left_reg = kcontrol->private_value & 0xff;
int right_reg = (kcontrol->private_value >> 8) & 0xff;
int shift_left = (kcontrol->private_value >> 16) & 0x07;
int shift_right = (kcontrol->private_value >> 19) & 0x07;
int mask = (kcontrol->private_value >> 24) & 0xff;
int invert = (kcontrol->private_value >> 22) & 1;
spin_lock_irqsave(&chip->reg_lock, flags);
ucontrol->value.integer.value[0] = (chip->ctlregs[left_reg] >> shift_left) & mask;
ucontrol->value.integer.value[1] = (chip->ctlregs[right_reg] >> shift_right) & mask;
spin_unlock_irqrestore(&chip->reg_lock, flags);
if (invert) {
ucontrol->value.integer.value[0] = mask - ucontrol->value.integer.value[0];
ucontrol->value.integer.value[1] = mask - ucontrol->value.integer.value[1];
}
return 0;
}
static int snd_opl3sa2_put_double(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_opl3sa2 *chip = snd_kcontrol_chip(kcontrol);
unsigned long flags;
int left_reg = kcontrol->private_value & 0xff;
int right_reg = (kcontrol->private_value >> 8) & 0xff;
int shift_left = (kcontrol->private_value >> 16) & 0x07;
int shift_right = (kcontrol->private_value >> 19) & 0x07;
int mask = (kcontrol->private_value >> 24) & 0xff;
int invert = (kcontrol->private_value >> 22) & 1;
int change;
unsigned short val1, val2, oval1, oval2;
val1 = ucontrol->value.integer.value[0] & mask;
val2 = ucontrol->value.integer.value[1] & mask;
if (invert) {
val1 = mask - val1;
val2 = mask - val2;
}
val1 <<= shift_left;
val2 <<= shift_right;
spin_lock_irqsave(&chip->reg_lock, flags);
if (left_reg != right_reg) {
oval1 = chip->ctlregs[left_reg];
oval2 = chip->ctlregs[right_reg];
val1 = (oval1 & ~(mask << shift_left)) | val1;
val2 = (oval2 & ~(mask << shift_right)) | val2;
change = val1 != oval1 || val2 != oval2;
__snd_opl3sa2_write(chip, left_reg, val1);
__snd_opl3sa2_write(chip, right_reg, val2);
} else {
oval1 = chip->ctlregs[left_reg];
val1 = (oval1 & ~((mask << shift_left) | (mask << shift_right))) | val1 | val2;
change = val1 != oval1;
__snd_opl3sa2_write(chip, left_reg, val1);
}
spin_unlock_irqrestore(&chip->reg_lock, flags);
return change;
}
static void snd_opl3sa2_master_free(struct snd_kcontrol *kcontrol)
{
struct snd_opl3sa2 *chip = snd_kcontrol_chip(kcontrol);
chip->master_switch = NULL;
chip->master_volume = NULL;
}
static int __devinit snd_opl3sa2_mixer(struct snd_card *card)
{
struct snd_opl3sa2 *chip = card->private_data;
struct snd_ctl_elem_id id1, id2;
struct snd_kcontrol *kctl;
unsigned int idx;
int err;
memset(&id1, 0, sizeof(id1));
memset(&id2, 0, sizeof(id2));
id1.iface = id2.iface = SNDRV_CTL_ELEM_IFACE_MIXER;
strcpy(id1.name, "Aux Playback Switch");
strcpy(id2.name, "CD Playback Switch");
if ((err = snd_ctl_rename_id(card, &id1, &id2)) < 0) {
snd_printk(KERN_ERR "Cannot rename opl3sa2 control\n");
return err;
}
strcpy(id1.name, "Aux Playback Volume");
strcpy(id2.name, "CD Playback Volume");
if ((err = snd_ctl_rename_id(card, &id1, &id2)) < 0) {
snd_printk(KERN_ERR "Cannot rename opl3sa2 control\n");
return err;
}
strcpy(id1.name, "Aux Playback Switch"); id1.index = 1;
strcpy(id2.name, "FM Playback Switch");
if ((err = snd_ctl_rename_id(card, &id1, &id2)) < 0) {
snd_printk(KERN_ERR "Cannot rename opl3sa2 control\n");
return err;
}
strcpy(id1.name, "Aux Playback Volume");
strcpy(id2.name, "FM Playback Volume");
if ((err = snd_ctl_rename_id(card, &id1, &id2)) < 0) {
snd_printk(KERN_ERR "Cannot rename opl3sa2 control\n");
return err;
}
for (idx = 0; idx < ARRAY_SIZE(snd_opl3sa2_controls); idx++) {
if ((err = snd_ctl_add(card, kctl = snd_ctl_new1(&snd_opl3sa2_controls[idx], chip))) < 0)
return err;
switch (idx) {
case 0: chip->master_switch = kctl; kctl->private_free = snd_opl3sa2_master_free; break;
case 1: chip->master_volume = kctl; kctl->private_free = snd_opl3sa2_master_free; break;
}
}
if (chip->version > 2) {
for (idx = 0; idx < ARRAY_SIZE(snd_opl3sa2_tone_controls); idx++)
if ((err = snd_ctl_add(card, snd_ctl_new1(&snd_opl3sa2_tone_controls[idx], chip))) < 0)
return err;
}
return 0;
}
static int snd_opl3sa2_suspend(struct snd_card *card, pm_message_t state)
{
if (card) {
struct snd_opl3sa2 *chip = card->private_data;
snd_power_change_state(card, SNDRV_CTL_POWER_D3hot);
chip->wss->suspend(chip->wss);
snd_opl3sa2_write(chip, OPL3SA2_PM_CTRL, OPL3SA2_PM_D3);
}
return 0;
}
static int snd_opl3sa2_resume(struct snd_card *card)
{
struct snd_opl3sa2 *chip;
int i;
if (!card)
return 0;
chip = card->private_data;
snd_opl3sa2_write(chip, OPL3SA2_PM_CTRL, OPL3SA2_PM_D0);
for (i = 2; i <= 0x0a; i++) {
if (i != OPL3SA2_IRQ_STATUS)
snd_opl3sa2_write(chip, i, chip->ctlregs[i]);
}
if (chip->version > 2) {
for (i = 0x12; i <= 0x16; i++)
snd_opl3sa2_write(chip, i, chip->ctlregs[i]);
}
chip->wss->resume(chip->wss);
snd_power_change_state(card, SNDRV_CTL_POWER_D0);
return 0;
}
static int __devinit snd_opl3sa2_pnp(int dev, struct snd_opl3sa2 *chip,
struct pnp_dev *pdev)
{
if (pnp_activate_dev(pdev) < 0) {
snd_printk(KERN_ERR "PnP configure failure (out of resources?)\n");
return -EBUSY;
}
sb_port[dev] = pnp_port_start(pdev, 0);
wss_port[dev] = pnp_port_start(pdev, 1);
fm_port[dev] = pnp_port_start(pdev, 2);
midi_port[dev] = pnp_port_start(pdev, 3);
port[dev] = pnp_port_start(pdev, 4);
dma1[dev] = pnp_dma(pdev, 0);
dma2[dev] = pnp_dma(pdev, 1);
irq[dev] = pnp_irq(pdev, 0);
snd_printdd("%sPnP OPL3-SA: sb port=0x%lx, wss port=0x%lx, fm port=0x%lx, midi port=0x%lx\n",
pnp_device_is_pnpbios(pdev) ? "BIOS" : "ISA", sb_port[dev], wss_port[dev], fm_port[dev], midi_port[dev]);
snd_printdd("%sPnP OPL3-SA: control port=0x%lx, dma1=%i, dma2=%i, irq=%i\n",
pnp_device_is_pnpbios(pdev) ? "BIOS" : "ISA", port[dev], dma1[dev], dma2[dev], irq[dev]);
return 0;
}
static void snd_opl3sa2_free(struct snd_card *card)
{
struct snd_opl3sa2 *chip = card->private_data;
if (chip->irq >= 0)
free_irq(chip->irq, card);
release_and_free_resource(chip->res_port);
}
static int snd_opl3sa2_card_new(int dev, struct snd_card **cardp)
{
struct snd_card *card;
struct snd_opl3sa2 *chip;
int err;
err = snd_card_create(index[dev], id[dev], THIS_MODULE,
sizeof(struct snd_opl3sa2), &card);
if (err < 0)
return err;
strcpy(card->driver, "OPL3SA2");
strcpy(card->shortname, "Yamaha OPL3-SA");
chip = card->private_data;
spin_lock_init(&chip->reg_lock);
chip->irq = -1;
card->private_free = snd_opl3sa2_free;
*cardp = card;
return 0;
}
static int __devinit snd_opl3sa2_probe(struct snd_card *card, int dev)
{
int xirq, xdma1, xdma2;
struct snd_opl3sa2 *chip;
struct snd_wss *wss;
struct snd_opl3 *opl3;
int err;
chip = card->private_data;
chip->ymode = opl3sa3_ymode[dev] & 0x03 ;
chip->port = port[dev];
xirq = irq[dev];
xdma1 = dma1[dev];
xdma2 = dma2[dev];
if (xdma2 < 0)
chip->single_dma = 1;
err = snd_opl3sa2_detect(card);
if (err < 0)
return err;
err = request_irq(xirq, snd_opl3sa2_interrupt, IRQF_DISABLED,
"OPL3-SA2", card);
if (err) {
snd_printk(KERN_ERR PFX "can't grab IRQ %d\n", xirq);
return -ENODEV;
}
chip->irq = xirq;
err = snd_wss_create(card,
wss_port[dev] + 4, -1,
xirq, xdma1, xdma2,
WSS_HW_OPL3SA2, WSS_HWSHARE_IRQ, &wss);
if (err < 0) {
snd_printd("Oops, WSS not detected at 0x%lx\n", wss_port[dev] + 4);
return err;
}
chip->wss = wss;
err = snd_wss_pcm(wss, 0, NULL);
if (err < 0)
return err;
err = snd_wss_mixer(wss);
if (err < 0)
return err;
err = snd_opl3sa2_mixer(card);
if (err < 0)
return err;
err = snd_wss_timer(wss, 0, NULL);
if (err < 0)
return err;
if (fm_port[dev] >= 0x340 && fm_port[dev] < 0x400) {
if ((err = snd_opl3_create(card, fm_port[dev],
fm_port[dev] + 2,
OPL3_HW_OPL3, 0, &opl3)) < 0)
return err;
if ((err = snd_opl3_timer_new(opl3, 1, 2)) < 0)
return err;
if ((err = snd_opl3_hwdep_new(opl3, 0, 1, &chip->synth)) < 0)
return err;
}
if (midi_port[dev] >= 0x300 && midi_port[dev] < 0x340) {
if ((err = snd_mpu401_uart_new(card, 0, MPU401_HW_OPL3SA2,
midi_port[dev], 0,
xirq, 0, &chip->rmidi)) < 0)
return err;
}
sprintf(card->longname, "%s at 0x%lx, irq %d, dma %d",
card->shortname, chip->port, xirq, xdma1);
if (xdma2 >= 0)
sprintf(card->longname + strlen(card->longname), "&%d", xdma2);
return snd_card_register(card);
}
static int __devinit snd_opl3sa2_pnp_detect(struct pnp_dev *pdev,
const struct pnp_device_id *id)
{
static int dev;
int err;
struct snd_card *card;
if (pnp_device_is_isapnp(pdev))
return -ENOENT;
for (; dev < SNDRV_CARDS; dev++) {
if (enable[dev] && isapnp[dev])
break;
}
if (dev >= SNDRV_CARDS)
return -ENODEV;
err = snd_opl3sa2_card_new(dev, &card);
if (err < 0)
return err;
if ((err = snd_opl3sa2_pnp(dev, card->private_data, pdev)) < 0) {
snd_card_free(card);
return err;
}
snd_card_set_dev(card, &pdev->dev);
if ((err = snd_opl3sa2_probe(card, dev)) < 0) {
snd_card_free(card);
return err;
}
pnp_set_drvdata(pdev, card);
dev++;
return 0;
}
static void __devexit snd_opl3sa2_pnp_remove(struct pnp_dev * pdev)
{
snd_card_free(pnp_get_drvdata(pdev));
pnp_set_drvdata(pdev, NULL);
}
static int snd_opl3sa2_pnp_suspend(struct pnp_dev *pdev, pm_message_t state)
{
return snd_opl3sa2_suspend(pnp_get_drvdata(pdev), state);
}
static int snd_opl3sa2_pnp_resume(struct pnp_dev *pdev)
{
return snd_opl3sa2_resume(pnp_get_drvdata(pdev));
}
static int __devinit snd_opl3sa2_pnp_cdetect(struct pnp_card_link *pcard,
const struct pnp_card_device_id *id)
{
static int dev;
struct pnp_dev *pdev;
int err;
struct snd_card *card;
pdev = pnp_request_card_device(pcard, id->devs[0].id, NULL);
if (pdev == NULL) {
snd_printk(KERN_ERR PFX "can't get pnp device from id '%s'\n",
id->devs[0].id);
return -EBUSY;
}
for (; dev < SNDRV_CARDS; dev++) {
if (enable[dev] && isapnp[dev])
break;
}
if (dev >= SNDRV_CARDS)
return -ENODEV;
err = snd_opl3sa2_card_new(dev, &card);
if (err < 0)
return err;
if ((err = snd_opl3sa2_pnp(dev, card->private_data, pdev)) < 0) {
snd_card_free(card);
return err;
}
snd_card_set_dev(card, &pdev->dev);
if ((err = snd_opl3sa2_probe(card, dev)) < 0) {
snd_card_free(card);
return err;
}
pnp_set_card_drvdata(pcard, card);
dev++;
return 0;
}
static void __devexit snd_opl3sa2_pnp_cremove(struct pnp_card_link * pcard)
{
snd_card_free(pnp_get_card_drvdata(pcard));
pnp_set_card_drvdata(pcard, NULL);
}
static int snd_opl3sa2_pnp_csuspend(struct pnp_card_link *pcard, pm_message_t state)
{
return snd_opl3sa2_suspend(pnp_get_card_drvdata(pcard), state);
}
static int snd_opl3sa2_pnp_cresume(struct pnp_card_link *pcard)
{
return snd_opl3sa2_resume(pnp_get_card_drvdata(pcard));
}
static int __devinit snd_opl3sa2_isa_match(struct device *pdev,
unsigned int dev)
{
if (!enable[dev])
return 0;
#ifdef CONFIG_PNP
if (isapnp[dev])
return 0;
#endif
if (port[dev] == SNDRV_AUTO_PORT) {
snd_printk(KERN_ERR PFX "specify port\n");
return 0;
}
if (wss_port[dev] == SNDRV_AUTO_PORT) {
snd_printk(KERN_ERR PFX "specify wss_port\n");
return 0;
}
if (fm_port[dev] == SNDRV_AUTO_PORT) {
snd_printk(KERN_ERR PFX "specify fm_port\n");
return 0;
}
if (midi_port[dev] == SNDRV_AUTO_PORT) {
snd_printk(KERN_ERR PFX "specify midi_port\n");
return 0;
}
return 1;
}
static int __devinit snd_opl3sa2_isa_probe(struct device *pdev,
unsigned int dev)
{
struct snd_card *card;
int err;
err = snd_opl3sa2_card_new(dev, &card);
if (err < 0)
return err;
snd_card_set_dev(card, pdev);
if ((err = snd_opl3sa2_probe(card, dev)) < 0) {
snd_card_free(card);
return err;
}
dev_set_drvdata(pdev, card);
return 0;
}
static int __devexit snd_opl3sa2_isa_remove(struct device *devptr,
unsigned int dev)
{
snd_card_free(dev_get_drvdata(devptr));
dev_set_drvdata(devptr, NULL);
return 0;
}
static int snd_opl3sa2_isa_suspend(struct device *dev, unsigned int n,
pm_message_t state)
{
return snd_opl3sa2_suspend(dev_get_drvdata(dev), state);
}
static int snd_opl3sa2_isa_resume(struct device *dev, unsigned int n)
{
return snd_opl3sa2_resume(dev_get_drvdata(dev));
}
static int __init alsa_card_opl3sa2_init(void)
{
int err;
err = isa_register_driver(&snd_opl3sa2_isa_driver, SNDRV_CARDS);
#ifdef CONFIG_PNP
if (!err)
isa_registered = 1;
err = pnp_register_driver(&opl3sa2_pnp_driver);
if (!err)
pnp_registered = 1;
err = pnp_register_card_driver(&opl3sa2_pnpc_driver);
if (!err)
pnpc_registered = 1;
if (isa_registered || pnp_registered)
err = 0;
#endif
return err;
}
static void __exit alsa_card_opl3sa2_exit(void)
{
#ifdef CONFIG_PNP
if (pnpc_registered)
pnp_unregister_card_driver(&opl3sa2_pnpc_driver);
if (pnp_registered)
pnp_unregister_driver(&opl3sa2_pnp_driver);
if (isa_registered)
#endif
isa_unregister_driver(&snd_opl3sa2_isa_driver);
}
