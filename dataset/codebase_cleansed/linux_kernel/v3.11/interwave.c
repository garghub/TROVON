static void snd_interwave_i2c_setlines(struct snd_i2c_bus *bus, int ctrl, int data)
{
unsigned long port = bus->private_value;
#if 0
printk(KERN_DEBUG "i2c_setlines - 0x%lx <- %i,%i\n", port, ctrl, data);
#endif
outb((data << 1) | ctrl, port);
udelay(10);
}
static int snd_interwave_i2c_getclockline(struct snd_i2c_bus *bus)
{
unsigned long port = bus->private_value;
unsigned char res;
res = inb(port) & 1;
#if 0
printk(KERN_DEBUG "i2c_getclockline - 0x%lx -> %i\n", port, res);
#endif
return res;
}
static int snd_interwave_i2c_getdataline(struct snd_i2c_bus *bus, int ack)
{
unsigned long port = bus->private_value;
unsigned char res;
if (ack)
udelay(10);
res = (inb(port) & 2) >> 1;
#if 0
printk(KERN_DEBUG "i2c_getdataline - 0x%lx -> %i\n", port, res);
#endif
return res;
}
static int snd_interwave_detect_stb(struct snd_interwave *iwcard,
struct snd_gus_card *gus, int dev,
struct snd_i2c_bus **rbus)
{
unsigned long port;
struct snd_i2c_bus *bus;
struct snd_card *card = iwcard->card;
char name[32];
int err;
*rbus = NULL;
port = port_tc[dev];
if (port == SNDRV_AUTO_PORT) {
port = 0x350;
if (gus->gf1.port == 0x250) {
port = 0x360;
}
while (port <= 0x380) {
if ((iwcard->i2c_res = request_region(port, 1, "InterWave (I2C bus)")) != NULL)
break;
port += 0x10;
}
} else {
iwcard->i2c_res = request_region(port, 1, "InterWave (I2C bus)");
}
if (iwcard->i2c_res == NULL) {
snd_printk(KERN_ERR "interwave: can't grab i2c bus port\n");
return -ENODEV;
}
sprintf(name, "InterWave-%i", card->number);
if ((err = snd_i2c_bus_create(card, name, NULL, &bus)) < 0)
return err;
bus->private_value = port;
bus->hw_ops.bit = &snd_interwave_i2c_bit_ops;
if ((err = snd_tea6330t_detect(bus, 0)) < 0)
return err;
*rbus = bus;
return 0;
}
static int snd_interwave_detect(struct snd_interwave *iwcard,
struct snd_gus_card *gus,
int dev
#ifdef SNDRV_STB
, struct snd_i2c_bus **rbus
#endif
)
{
unsigned long flags;
unsigned char rev1, rev2;
int d;
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
spin_lock_irqsave(&gus->reg_lock, flags);
rev1 = snd_gf1_look8(gus, SNDRV_GF1_GB_VERSION_NUMBER);
snd_gf1_write8(gus, SNDRV_GF1_GB_VERSION_NUMBER, ~rev1);
rev2 = snd_gf1_look8(gus, SNDRV_GF1_GB_VERSION_NUMBER);
snd_gf1_write8(gus, SNDRV_GF1_GB_VERSION_NUMBER, rev1);
spin_unlock_irqrestore(&gus->reg_lock, flags);
snd_printdd("[0x%lx] InterWave check - rev1=0x%x, rev2=0x%x\n", gus->gf1.port, rev1, rev2);
if ((rev1 & 0xf0) == (rev2 & 0xf0) &&
(rev1 & 0x0f) != (rev2 & 0x0f)) {
snd_printdd("[0x%lx] InterWave check - passed\n", gus->gf1.port);
gus->interwave = 1;
strcpy(gus->card->shortname, "AMD InterWave");
gus->revision = rev1 >> 4;
#ifndef SNDRV_STB
return 0;
#else
return snd_interwave_detect_stb(iwcard, gus, dev, rbus);
#endif
}
snd_printdd("[0x%lx] InterWave check - failed\n", gus->gf1.port);
return -ENODEV;
}
static irqreturn_t snd_interwave_interrupt(int irq, void *dev_id)
{
struct snd_interwave *iwcard = dev_id;
int loop, max = 5;
int handled = 0;
do {
loop = 0;
if (inb(iwcard->gus_status_reg)) {
handled = 1;
snd_gus_interrupt(irq, iwcard->gus);
loop++;
}
if (inb(iwcard->pcm_status_reg) & 0x01) {
handled = 1;
snd_wss_interrupt(irq, iwcard->wss);
loop++;
}
} while (loop && --max > 0);
return IRQ_RETVAL(handled);
}
static void snd_interwave_reset(struct snd_gus_card *gus)
{
snd_gf1_write8(gus, SNDRV_GF1_GB_RESET, 0x00);
udelay(160);
snd_gf1_write8(gus, SNDRV_GF1_GB_RESET, 0x01);
udelay(160);
}
static void snd_interwave_bank_sizes(struct snd_gus_card *gus, int *sizes)
{
unsigned int idx;
unsigned int local;
unsigned char d;
for (idx = 0; idx < 4; idx++) {
sizes[idx] = 0;
d = 0x55;
for (local = idx << 22;
local < (idx << 22) + 0x400000;
local += 0x40000, d++) {
snd_gf1_poke(gus, local, d);
snd_gf1_poke(gus, local + 1, d + 1);
#if 0
printk(KERN_DEBUG "d = 0x%x, local = 0x%x, "
"local + 1 = 0x%x, idx << 22 = 0x%x\n",
d,
snd_gf1_peek(gus, local),
snd_gf1_peek(gus, local + 1),
snd_gf1_peek(gus, idx << 22));
#endif
if (snd_gf1_peek(gus, local) != d ||
snd_gf1_peek(gus, local + 1) != d + 1 ||
snd_gf1_peek(gus, idx << 22) != 0x55)
break;
sizes[idx]++;
}
}
#if 0
printk(KERN_DEBUG "sizes: %i %i %i %i\n",
sizes[0], sizes[1], sizes[2], sizes[3]);
#endif
}
static void snd_interwave_detect_memory(struct snd_gus_card *gus)
{
static unsigned int lmc[13] =
{
0x00000001, 0x00000101, 0x01010101, 0x00000401,
0x04040401, 0x00040101, 0x04040101, 0x00000004,
0x00000404, 0x04040404, 0x00000010, 0x00001010,
0x10101010
};
int bank_pos, pages;
unsigned int i, lmct;
int psizes[4];
unsigned char iwave[8];
unsigned char csum;
snd_interwave_reset(gus);
snd_gf1_write8(gus, SNDRV_GF1_GB_GLOBAL_MODE, snd_gf1_read8(gus, SNDRV_GF1_GB_GLOBAL_MODE) | 0x01);
snd_gf1_write8(gus, SNDRV_GF1_GB_MEMORY_CONTROL, 0x01);
snd_gf1_write16(gus, SNDRV_GF1_GW_MEMORY_CONFIG, (snd_gf1_look16(gus, SNDRV_GF1_GW_MEMORY_CONFIG) & 0xff10) | 0x004c);
pages = 0;
snd_gf1_poke(gus, 0, 0x55);
snd_gf1_poke(gus, 1, 0xaa);
#if 1
if (snd_gf1_peek(gus, 0) == 0x55 && snd_gf1_peek(gus, 1) == 0xaa)
#else
if (0)
#endif
{
snd_interwave_bank_sizes(gus, psizes);
lmct = (psizes[3] << 24) | (psizes[2] << 16) |
(psizes[1] << 8) | psizes[0];
#if 0
printk(KERN_DEBUG "lmct = 0x%08x\n", lmct);
#endif
for (i = 0; i < ARRAY_SIZE(lmc); i++)
if (lmct == lmc[i]) {
#if 0
printk(KERN_DEBUG "found !!! %i\n", i);
#endif
snd_gf1_write16(gus, SNDRV_GF1_GW_MEMORY_CONFIG, (snd_gf1_look16(gus, SNDRV_GF1_GW_MEMORY_CONFIG) & 0xfff0) | i);
snd_interwave_bank_sizes(gus, psizes);
break;
}
if (i >= ARRAY_SIZE(lmc) && !gus->gf1.enh_mode)
snd_gf1_write16(gus, SNDRV_GF1_GW_MEMORY_CONFIG, (snd_gf1_look16(gus, SNDRV_GF1_GW_MEMORY_CONFIG) & 0xfff0) | 2);
for (i = 0; i < 4; i++) {
gus->gf1.mem_alloc.banks_8[i].address =
gus->gf1.mem_alloc.banks_16[i].address = i << 22;
gus->gf1.mem_alloc.banks_8[i].size =
gus->gf1.mem_alloc.banks_16[i].size = psizes[i] << 18;
pages += psizes[i];
}
}
pages <<= 18;
gus->gf1.memory = pages;
snd_gf1_write8(gus, SNDRV_GF1_GB_MEMORY_CONTROL, 0x03);
snd_gf1_write16(gus, SNDRV_GF1_GW_MEMORY_CONFIG, (snd_gf1_look16(gus, SNDRV_GF1_GW_MEMORY_CONFIG) & 0xff1f) | (4 << 5));
gus->gf1.rom_banks = 0;
gus->gf1.rom_memory = 0;
for (bank_pos = 0; bank_pos < 16L * 1024L * 1024L; bank_pos += 4L * 1024L * 1024L) {
for (i = 0; i < 8; ++i)
iwave[i] = snd_gf1_peek(gus, bank_pos + i);
#ifdef CONFIG_SND_DEBUG_ROM
printk(KERN_DEBUG "ROM at 0x%06x = %*phC\n", bank_pos,
8, iwave);
#endif
if (strncmp(iwave, "INTRWAVE", 8))
continue;
csum = 0;
for (i = 0; i < sizeof(struct rom_hdr); i++)
csum += snd_gf1_peek(gus, bank_pos + i);
#ifdef CONFIG_SND_DEBUG_ROM
printk(KERN_DEBUG "ROM checksum = 0x%x (computed)\n", csum);
#endif
if (csum != 0)
continue;
gus->gf1.rom_banks++;
gus->gf1.rom_present |= 1 << (bank_pos >> 22);
gus->gf1.rom_memory = snd_gf1_peek(gus, bank_pos + 40) |
(snd_gf1_peek(gus, bank_pos + 41) << 8) |
(snd_gf1_peek(gus, bank_pos + 42) << 16) |
(snd_gf1_peek(gus, bank_pos + 43) << 24);
}
#if 0
if (gus->gf1.rom_memory > 0) {
if (gus->gf1.rom_banks == 1 && gus->gf1.rom_present == 8)
gus->card->type = SNDRV_CARD_TYPE_IW_DYNASONIC;
}
#endif
snd_gf1_write8(gus, SNDRV_GF1_GB_MEMORY_CONTROL, 0x00);
if (!gus->gf1.enh_mode)
snd_interwave_reset(gus);
}
static void snd_interwave_init(int dev, struct snd_gus_card *gus)
{
unsigned long flags;
spin_lock_irqsave(&gus->reg_lock, flags);
snd_gf1_write8(gus, SNDRV_GF1_GB_SOUND_BLASTER_CONTROL, 0x00);
snd_gf1_write8(gus, SNDRV_GF1_GB_COMPATIBILITY, 0x1f);
snd_gf1_write8(gus, SNDRV_GF1_GB_DECODE_CONTROL, 0x49);
snd_gf1_write8(gus, SNDRV_GF1_GB_VERSION_NUMBER, 0x11);
snd_gf1_write8(gus, SNDRV_GF1_GB_MPU401_CONTROL_A, 0x00);
snd_gf1_write8(gus, SNDRV_GF1_GB_MPU401_CONTROL_B, 0x30);
snd_gf1_write8(gus, SNDRV_GF1_GB_EMULATION_IRQ, 0x00);
spin_unlock_irqrestore(&gus->reg_lock, flags);
gus->equal_irq = 1;
gus->codec_flag = 1;
gus->interwave = 1;
gus->max_flag = 1;
gus->joystick_dac = joystick_dac[dev];
}
static int snd_interwave_mixer(struct snd_wss *chip)
{
struct snd_card *card = chip->card;
struct snd_ctl_elem_id id1, id2;
unsigned int idx;
int err;
memset(&id1, 0, sizeof(id1));
memset(&id2, 0, sizeof(id2));
id1.iface = id2.iface = SNDRV_CTL_ELEM_IFACE_MIXER;
#if 0
strcpy(id1.name, "Mic Playback Switch");
if ((err = snd_ctl_remove_id(card, &id1)) < 0)
return err;
strcpy(id1.name, "Mic Playback Volume");
if ((err = snd_ctl_remove_id(card, &id1)) < 0)
return err;
#endif
for (idx = 0; idx < ARRAY_SIZE(snd_interwave_controls); idx++)
if ((err = snd_ctl_add(card, snd_ctl_new1(&snd_interwave_controls[idx], chip))) < 0)
return err;
snd_wss_out(chip, CS4231_LINE_LEFT_OUTPUT, 0x9f);
snd_wss_out(chip, CS4231_LINE_RIGHT_OUTPUT, 0x9f);
snd_wss_out(chip, CS4231_LEFT_MIC_INPUT, 0x9f);
snd_wss_out(chip, CS4231_RIGHT_MIC_INPUT, 0x9f);
strcpy(id1.name, "Aux Playback Switch");
strcpy(id2.name, "Synth Playback Switch");
if ((err = snd_ctl_rename_id(card, &id1, &id2)) < 0)
return err;
strcpy(id1.name, "Aux Playback Volume");
strcpy(id2.name, "Synth Playback Volume");
if ((err = snd_ctl_rename_id(card, &id1, &id2)) < 0)
return err;
strcpy(id1.name, "Aux Playback Switch"); id1.index = 1;
strcpy(id2.name, "CD Playback Switch");
if ((err = snd_ctl_rename_id(card, &id1, &id2)) < 0)
return err;
strcpy(id1.name, "Aux Playback Volume");
strcpy(id2.name, "CD Playback Volume");
if ((err = snd_ctl_rename_id(card, &id1, &id2)) < 0)
return err;
return 0;
}
static int snd_interwave_pnp(int dev, struct snd_interwave *iwcard,
struct pnp_card_link *card,
const struct pnp_card_device_id *id)
{
struct pnp_dev *pdev;
int err;
iwcard->dev = pnp_request_card_device(card, id->devs[0].id, NULL);
if (iwcard->dev == NULL)
return -EBUSY;
#ifdef SNDRV_STB
iwcard->devtc = pnp_request_card_device(card, id->devs[1].id, NULL);
if (iwcard->devtc == NULL)
return -EBUSY;
#endif
pdev = iwcard->dev;
err = pnp_activate_dev(pdev);
if (err < 0) {
snd_printk(KERN_ERR "InterWave PnP configure failure (out of resources?)\n");
return err;
}
if (pnp_port_start(pdev, 0) + 0x100 != pnp_port_start(pdev, 1) ||
pnp_port_start(pdev, 0) + 0x10c != pnp_port_start(pdev, 2)) {
snd_printk(KERN_ERR "PnP configure failure (wrong ports)\n");
return -ENOENT;
}
port[dev] = pnp_port_start(pdev, 0);
dma1[dev] = pnp_dma(pdev, 0);
if (dma2[dev] >= 0)
dma2[dev] = pnp_dma(pdev, 1);
irq[dev] = pnp_irq(pdev, 0);
snd_printdd("isapnp IW: sb port=0x%llx, gf1 port=0x%llx, codec port=0x%llx\n",
(unsigned long long)pnp_port_start(pdev, 0),
(unsigned long long)pnp_port_start(pdev, 1),
(unsigned long long)pnp_port_start(pdev, 2));
snd_printdd("isapnp IW: dma1=%i, dma2=%i, irq=%i\n", dma1[dev], dma2[dev], irq[dev]);
#ifdef SNDRV_STB
pdev = iwcard->devtc;
err = pnp_activate_dev(pdev);
if (err < 0) {
snd_printk(KERN_ERR "InterWave ToneControl PnP configure failure (out of resources?)\n");
return err;
}
port_tc[dev] = pnp_port_start(pdev, 0);
snd_printdd("isapnp IW: tone control port=0x%lx\n", port_tc[dev]);
#endif
return 0;
}
static void snd_interwave_free(struct snd_card *card)
{
struct snd_interwave *iwcard = card->private_data;
if (iwcard == NULL)
return;
#ifdef SNDRV_STB
release_and_free_resource(iwcard->i2c_res);
#endif
if (iwcard->irq >= 0)
free_irq(iwcard->irq, (void *)iwcard);
}
static int snd_interwave_card_new(int dev, struct snd_card **cardp)
{
struct snd_card *card;
struct snd_interwave *iwcard;
int err;
err = snd_card_create(index[dev], id[dev], THIS_MODULE,
sizeof(struct snd_interwave), &card);
if (err < 0)
return err;
iwcard = card->private_data;
iwcard->card = card;
iwcard->irq = -1;
card->private_free = snd_interwave_free;
*cardp = card;
return 0;
}
static int snd_interwave_probe(struct snd_card *card, int dev)
{
int xirq, xdma1, xdma2;
struct snd_interwave *iwcard = card->private_data;
struct snd_wss *wss;
struct snd_gus_card *gus;
#ifdef SNDRV_STB
struct snd_i2c_bus *i2c_bus;
#endif
struct snd_pcm *pcm;
char *str;
int err;
xirq = irq[dev];
xdma1 = dma1[dev];
xdma2 = dma2[dev];
if ((err = snd_gus_create(card,
port[dev],
-xirq, xdma1, xdma2,
0, 32,
pcm_channels[dev], effect[dev], &gus)) < 0)
return err;
if ((err = snd_interwave_detect(iwcard, gus, dev
#ifdef SNDRV_STB
, &i2c_bus
#endif
)) < 0)
return err;
iwcard->gus_status_reg = gus->gf1.reg_irqstat;
iwcard->pcm_status_reg = gus->gf1.port + 0x10c + 2;
snd_interwave_init(dev, gus);
snd_interwave_detect_memory(gus);
if ((err = snd_gus_initialize(gus)) < 0)
return err;
if (request_irq(xirq, snd_interwave_interrupt, 0,
"InterWave", iwcard)) {
snd_printk(KERN_ERR PFX "unable to grab IRQ %d\n", xirq);
return -EBUSY;
}
iwcard->irq = xirq;
err = snd_wss_create(card,
gus->gf1.port + 0x10c, -1, xirq,
xdma2 < 0 ? xdma1 : xdma2, xdma1,
WSS_HW_INTERWAVE,
WSS_HWSHARE_IRQ |
WSS_HWSHARE_DMA1 |
WSS_HWSHARE_DMA2,
&wss);
if (err < 0)
return err;
err = snd_wss_pcm(wss, 0, &pcm);
if (err < 0)
return err;
sprintf(pcm->name + strlen(pcm->name), " rev %c", gus->revision + 'A');
strcat(pcm->name, " (codec)");
err = snd_wss_timer(wss, 2, NULL);
if (err < 0)
return err;
err = snd_wss_mixer(wss);
if (err < 0)
return err;
if (pcm_channels[dev] > 0) {
err = snd_gf1_pcm_new(gus, 1, 1, NULL);
if (err < 0)
return err;
}
err = snd_interwave_mixer(wss);
if (err < 0)
return err;
#ifdef SNDRV_STB
{
struct snd_ctl_elem_id id1, id2;
memset(&id1, 0, sizeof(id1));
memset(&id2, 0, sizeof(id2));
id1.iface = id2.iface = SNDRV_CTL_ELEM_IFACE_MIXER;
strcpy(id1.name, "Master Playback Switch");
strcpy(id2.name, id1.name);
id2.index = 1;
if ((err = snd_ctl_rename_id(card, &id1, &id2)) < 0)
return err;
strcpy(id1.name, "Master Playback Volume");
strcpy(id2.name, id1.name);
if ((err = snd_ctl_rename_id(card, &id1, &id2)) < 0)
return err;
if ((err = snd_tea6330t_update_mixer(card, i2c_bus, 0, 1)) < 0)
return err;
}
#endif
gus->uart_enable = midi[dev];
if ((err = snd_gf1_rawmidi_new(gus, 0, NULL)) < 0)
return err;
#ifndef SNDRV_STB
str = "AMD InterWave";
if (gus->gf1.rom_banks == 1 && gus->gf1.rom_present == 8)
str = "Dynasonic 3-D";
#else
str = "InterWave STB";
#endif
strcpy(card->driver, str);
strcpy(card->shortname, str);
sprintf(card->longname, "%s at 0x%lx, irq %i, dma %d",
str,
gus->gf1.port,
xirq,
xdma1);
if (xdma2 >= 0)
sprintf(card->longname + strlen(card->longname), "&%d", xdma2);
err = snd_card_register(card);
if (err < 0)
return err;
iwcard->wss = wss;
iwcard->gus = gus;
return 0;
}
static int snd_interwave_isa_probe1(int dev, struct device *devptr)
{
struct snd_card *card;
int err;
err = snd_interwave_card_new(dev, &card);
if (err < 0)
return err;
snd_card_set_dev(card, devptr);
if ((err = snd_interwave_probe(card, dev)) < 0) {
snd_card_free(card);
return err;
}
dev_set_drvdata(devptr, card);
return 0;
}
static int snd_interwave_isa_match(struct device *pdev,
unsigned int dev)
{
if (!enable[dev])
return 0;
#ifdef CONFIG_PNP
if (isapnp[dev])
return 0;
#endif
return 1;
}
static int snd_interwave_isa_probe(struct device *pdev,
unsigned int dev)
{
int err;
static int possible_irqs[] = {5, 11, 12, 9, 7, 15, 3, -1};
static int possible_dmas[] = {0, 1, 3, 5, 6, 7, -1};
if (irq[dev] == SNDRV_AUTO_IRQ) {
if ((irq[dev] = snd_legacy_find_free_irq(possible_irqs)) < 0) {
snd_printk(KERN_ERR PFX "unable to find a free IRQ\n");
return -EBUSY;
}
}
if (dma1[dev] == SNDRV_AUTO_DMA) {
if ((dma1[dev] = snd_legacy_find_free_dma(possible_dmas)) < 0) {
snd_printk(KERN_ERR PFX "unable to find a free DMA1\n");
return -EBUSY;
}
}
if (dma2[dev] == SNDRV_AUTO_DMA) {
if ((dma2[dev] = snd_legacy_find_free_dma(possible_dmas)) < 0) {
snd_printk(KERN_ERR PFX "unable to find a free DMA2\n");
return -EBUSY;
}
}
if (port[dev] != SNDRV_AUTO_PORT)
return snd_interwave_isa_probe1(dev, pdev);
else {
static long possible_ports[] = {0x210, 0x220, 0x230, 0x240, 0x250, 0x260};
int i;
for (i = 0; i < ARRAY_SIZE(possible_ports); i++) {
port[dev] = possible_ports[i];
err = snd_interwave_isa_probe1(dev, pdev);
if (! err)
return 0;
}
return err;
}
}
static int snd_interwave_isa_remove(struct device *devptr, unsigned int dev)
{
snd_card_free(dev_get_drvdata(devptr));
return 0;
}
static int snd_interwave_pnp_detect(struct pnp_card_link *pcard,
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
res = snd_interwave_card_new(dev, &card);
if (res < 0)
return res;
if ((res = snd_interwave_pnp(dev, card->private_data, pcard, pid)) < 0) {
snd_card_free(card);
return res;
}
snd_card_set_dev(card, &pcard->card->dev);
if ((res = snd_interwave_probe(card, dev)) < 0) {
snd_card_free(card);
return res;
}
pnp_set_card_drvdata(pcard, card);
dev++;
return 0;
}
static void snd_interwave_pnp_remove(struct pnp_card_link *pcard)
{
snd_card_free(pnp_get_card_drvdata(pcard));
pnp_set_card_drvdata(pcard, NULL);
}
static int __init alsa_card_interwave_init(void)
{
int err;
err = isa_register_driver(&snd_interwave_driver, SNDRV_CARDS);
#ifdef CONFIG_PNP
if (!err)
isa_registered = 1;
err = pnp_register_card_driver(&interwave_pnpc_driver);
if (!err)
pnp_registered = 1;
if (isa_registered)
err = 0;
#endif
return err;
}
static void __exit alsa_card_interwave_exit(void)
{
#ifdef CONFIG_PNP
if (pnp_registered)
pnp_unregister_card_driver(&interwave_pnpc_driver);
if (isa_registered)
#endif
isa_unregister_driver(&snd_interwave_driver);
}
