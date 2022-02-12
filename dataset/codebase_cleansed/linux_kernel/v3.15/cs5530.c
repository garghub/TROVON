static int snd_cs5530_free(struct snd_cs5530 *chip)
{
pci_release_regions(chip->pci);
pci_disable_device(chip->pci);
kfree(chip);
return 0;
}
static int snd_cs5530_dev_free(struct snd_device *device)
{
struct snd_cs5530 *chip = device->device_data;
return snd_cs5530_free(chip);
}
static void snd_cs5530_remove(struct pci_dev *pci)
{
snd_card_free(pci_get_drvdata(pci));
}
static u8 snd_cs5530_mixer_read(unsigned long io, u8 reg)
{
outb(reg, io + 4);
udelay(20);
reg = inb(io + 5);
udelay(20);
return reg;
}
static int snd_cs5530_create(struct snd_card *card,
struct pci_dev *pci,
struct snd_cs5530 **rchip)
{
struct snd_cs5530 *chip;
unsigned long sb_base;
u8 irq, dma8, dma16 = 0;
u16 map;
void __iomem *mem;
int err;
static struct snd_device_ops ops = {
.dev_free = snd_cs5530_dev_free,
};
*rchip = NULL;
err = pci_enable_device(pci);
if (err < 0)
return err;
chip = kzalloc(sizeof(*chip), GFP_KERNEL);
if (chip == NULL) {
pci_disable_device(pci);
return -ENOMEM;
}
chip->card = card;
chip->pci = pci;
err = pci_request_regions(pci, "CS5530");
if (err < 0) {
kfree(chip);
pci_disable_device(pci);
return err;
}
chip->pci_base = pci_resource_start(pci, 0);
mem = pci_ioremap_bar(pci, 0);
if (mem == NULL) {
snd_cs5530_free(chip);
return -EBUSY;
}
map = readw(mem + 0x18);
iounmap(mem);
sb_base = 0x220 + 0x20 * (map & 3);
if (map & (1<<2))
dev_info(card->dev, "XpressAudio at 0x%lx\n", sb_base);
else {
dev_err(card->dev, "Could not find XpressAudio!\n");
snd_cs5530_free(chip);
return -ENODEV;
}
if (map & (1<<5))
dev_info(card->dev, "MPU at 0x300\n");
else if (map & (1<<6))
dev_info(card->dev, "MPU at 0x330\n");
irq = snd_cs5530_mixer_read(sb_base, 0x80) & 0x0F;
dma8 = snd_cs5530_mixer_read(sb_base, 0x81);
if (dma8 & 0x20)
dma16 = 5;
else if (dma8 & 0x40)
dma16 = 6;
else if (dma8 & 0x80)
dma16 = 7;
else {
dev_err(card->dev, "No 16bit DMA enabled\n");
snd_cs5530_free(chip);
return -ENODEV;
}
if (dma8 & 0x01)
dma8 = 0;
else if (dma8 & 02)
dma8 = 1;
else if (dma8 & 0x08)
dma8 = 3;
else {
dev_err(card->dev, "No 8bit DMA enabled\n");
snd_cs5530_free(chip);
return -ENODEV;
}
if (irq & 1)
irq = 9;
else if (irq & 2)
irq = 5;
else if (irq & 4)
irq = 7;
else if (irq & 8)
irq = 10;
else {
dev_err(card->dev, "SoundBlaster IRQ not set\n");
snd_cs5530_free(chip);
return -ENODEV;
}
dev_info(card->dev, "IRQ: %d DMA8: %d DMA16: %d\n", irq, dma8, dma16);
err = snd_sbdsp_create(card, sb_base, irq, snd_sb16dsp_interrupt, dma8,
dma16, SB_HW_CS5530, &chip->sb);
if (err < 0) {
dev_err(card->dev, "Could not create SoundBlaster\n");
snd_cs5530_free(chip);
return err;
}
err = snd_sb16dsp_pcm(chip->sb, 0, &chip->sb->pcm);
if (err < 0) {
dev_err(card->dev, "Could not create PCM\n");
snd_cs5530_free(chip);
return err;
}
err = snd_sbmixer_new(chip->sb);
if (err < 0) {
dev_err(card->dev, "Could not create Mixer\n");
snd_cs5530_free(chip);
return err;
}
err = snd_device_new(card, SNDRV_DEV_LOWLEVEL, chip, &ops);
if (err < 0) {
snd_cs5530_free(chip);
return err;
}
*rchip = chip;
return 0;
}
static int snd_cs5530_probe(struct pci_dev *pci,
const struct pci_device_id *pci_id)
{
static int dev;
struct snd_card *card;
struct snd_cs5530 *chip = NULL;
int err;
if (dev >= SNDRV_CARDS)
return -ENODEV;
if (!enable[dev]) {
dev++;
return -ENOENT;
}
err = snd_card_new(&pci->dev, index[dev], id[dev], THIS_MODULE,
0, &card);
if (err < 0)
return err;
err = snd_cs5530_create(card, pci, &chip);
if (err < 0) {
snd_card_free(card);
return err;
}
strcpy(card->driver, "CS5530");
strcpy(card->shortname, "CS5530 Audio");
sprintf(card->longname, "%s at 0x%lx", card->shortname, chip->pci_base);
err = snd_card_register(card);
if (err < 0) {
snd_card_free(card);
return err;
}
pci_set_drvdata(pci, card);
dev++;
return 0;
}
