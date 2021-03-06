static inline struct soundscape *get_card_soundscape(struct snd_card *c)
{
return (struct soundscape *) (c->private_data);
}
static struct snd_dma_buffer *get_dmabuf(struct snd_dma_buffer *buf,
unsigned long size)
{
if (buf) {
if (snd_dma_alloc_pages_fallback(SNDRV_DMA_TYPE_DEV,
snd_dma_isa_data(),
size, buf) < 0) {
snd_printk(KERN_ERR "sscape: Failed to allocate "
"%lu bytes for DMA\n",
size);
return NULL;
}
}
return buf;
}
static void free_dmabuf(struct snd_dma_buffer *buf)
{
if (buf && buf->area)
snd_dma_free_pages(buf);
}
static inline void sscape_write_unsafe(unsigned io_base, enum GA_REG reg,
unsigned char val)
{
outb(reg, ODIE_ADDR_IO(io_base));
outb(val, ODIE_DATA_IO(io_base));
}
static void sscape_write(struct soundscape *s, enum GA_REG reg,
unsigned char val)
{
unsigned long flags;
spin_lock_irqsave(&s->lock, flags);
sscape_write_unsafe(s->io_base, reg, val);
spin_unlock_irqrestore(&s->lock, flags);
}
static inline unsigned char sscape_read_unsafe(unsigned io_base,
enum GA_REG reg)
{
outb(reg, ODIE_ADDR_IO(io_base));
return inb(ODIE_DATA_IO(io_base));
}
static inline void set_host_mode_unsafe(unsigned io_base)
{
outb(0x0, HOST_CTRL_IO(io_base));
}
static inline void set_midi_mode_unsafe(unsigned io_base)
{
outb(0x3, HOST_CTRL_IO(io_base));
}
static inline int host_read_unsafe(unsigned io_base)
{
int data = -1;
if ((inb(HOST_CTRL_IO(io_base)) & RX_READY) != 0)
data = inb(HOST_DATA_IO(io_base));
return data;
}
static int host_read_ctrl_unsafe(unsigned io_base, unsigned timeout)
{
int data;
while (((data = host_read_unsafe(io_base)) < 0) && (timeout != 0)) {
udelay(100);
--timeout;
}
return data;
}
static inline int host_write_unsafe(unsigned io_base, unsigned char data)
{
if ((inb(HOST_CTRL_IO(io_base)) & TX_READY) != 0) {
outb(data, HOST_DATA_IO(io_base));
return 1;
}
return 0;
}
static int host_write_ctrl_unsafe(unsigned io_base, unsigned char data,
unsigned timeout)
{
int err;
while (!(err = host_write_unsafe(io_base, data)) && (timeout != 0)) {
udelay(100);
--timeout;
}
return err;
}
static inline int verify_mpu401(const struct snd_mpu401 *mpu)
{
return ((inb(MPU401C(mpu)) & 0xc0) == 0x80);
}
static inline void initialise_mpu401(const struct snd_mpu401 *mpu)
{
outb(0, MPU401D(mpu));
}
static void activate_ad1845_unsafe(unsigned io_base)
{
unsigned char val = sscape_read_unsafe(io_base, GA_HMCTL_REG);
sscape_write_unsafe(io_base, GA_HMCTL_REG, (val & 0xcf) | 0x10);
sscape_write_unsafe(io_base, GA_CDCFG_REG, 0x80);
}
static void soundscape_free(struct snd_card *c)
{
struct soundscape *sscape = get_card_soundscape(c);
release_and_free_resource(sscape->io_res);
release_and_free_resource(sscape->wss_res);
free_dma(sscape->chip->dma1);
}
static void sscape_start_dma_unsafe(unsigned io_base, enum GA_REG reg)
{
sscape_write_unsafe(io_base, reg,
sscape_read_unsafe(io_base, reg) | 0x01);
sscape_write_unsafe(io_base, reg,
sscape_read_unsafe(io_base, reg) & 0xfe);
}
static int sscape_wait_dma_unsafe(unsigned io_base, enum GA_REG reg,
unsigned timeout)
{
while (!(sscape_read_unsafe(io_base, reg) & 0x01) && (timeout != 0)) {
udelay(100);
--timeout;
}
return sscape_read_unsafe(io_base, reg) & 0x01;
}
static int obp_startup_ack(struct soundscape *s, unsigned timeout)
{
unsigned long end_time = jiffies + msecs_to_jiffies(timeout);
do {
unsigned long flags;
int x;
spin_lock_irqsave(&s->lock, flags);
x = host_read_unsafe(s->io_base);
spin_unlock_irqrestore(&s->lock, flags);
if (x == 0xfe || x == 0xff)
return 1;
msleep(10);
} while (time_before(jiffies, end_time));
return 0;
}
static int host_startup_ack(struct soundscape *s, unsigned timeout)
{
unsigned long end_time = jiffies + msecs_to_jiffies(timeout);
do {
unsigned long flags;
int x;
spin_lock_irqsave(&s->lock, flags);
x = host_read_unsafe(s->io_base);
spin_unlock_irqrestore(&s->lock, flags);
if (x == 0xfe)
return 1;
msleep(10);
} while (time_before(jiffies, end_time));
return 0;
}
static int upload_dma_data(struct soundscape *s, const unsigned char *data,
size_t size)
{
unsigned long flags;
struct snd_dma_buffer dma;
int ret;
unsigned char val;
if (!get_dmabuf(&dma, PAGE_ALIGN(32 * 1024)))
return -ENOMEM;
spin_lock_irqsave(&s->lock, flags);
val = sscape_read_unsafe(s->io_base, GA_HMCTL_REG);
sscape_write_unsafe(s->io_base, GA_HMCTL_REG, val & 0x3f);
val = (s->chip->dma1 << 4) | DMA_8BIT;
sscape_write_unsafe(s->io_base, GA_DMAA_REG, val);
sscape_write_unsafe(s->io_base, GA_DMAB_REG, 0x20);
val = sscape_read_unsafe(s->io_base, GA_HMCTL_REG);
sscape_write_unsafe(s->io_base, GA_HMCTL_REG, val | 0x80);
while (size != 0) {
unsigned long len;
len = min(size, dma.bytes);
memcpy(dma.area, data, len);
data += len;
size -= len;
snd_dma_program(s->chip->dma1, dma.addr, len, DMA_MODE_WRITE);
sscape_start_dma_unsafe(s->io_base, GA_DMAA_REG);
if (!sscape_wait_dma_unsafe(s->io_base, GA_DMAA_REG, 5000)) {
spin_unlock_irqrestore(&s->lock, flags);
snd_printk(KERN_ERR
"sscape: DMA upload has timed out\n");
ret = -EAGAIN;
goto _release_dma;
}
}
set_host_mode_unsafe(s->io_base);
outb(0x0, s->io_base);
val = sscape_read_unsafe(s->io_base, GA_HMCTL_REG);
sscape_write_unsafe(s->io_base, GA_HMCTL_REG, val | 0x40);
spin_unlock_irqrestore(&s->lock, flags);
ret = 0;
if (!obp_startup_ack(s, 5000)) {
snd_printk(KERN_ERR "sscape: No response "
"from on-board processor after upload\n");
ret = -EAGAIN;
} else if (!host_startup_ack(s, 5000)) {
snd_printk(KERN_ERR
"sscape: SoundScape failed to initialise\n");
ret = -EAGAIN;
}
_release_dma:
sscape_write(s, GA_DMAA_REG, (s->ic_type == IC_OPUS ? 0x40 : 0x70));
free_dmabuf(&dma);
return ret;
}
static int sscape_upload_bootblock(struct snd_card *card)
{
struct soundscape *sscape = get_card_soundscape(card);
unsigned long flags;
const struct firmware *init_fw = NULL;
int data = 0;
int ret;
ret = request_firmware(&init_fw, "scope.cod", card->dev);
if (ret < 0) {
snd_printk(KERN_ERR "sscape: Error loading scope.cod");
return ret;
}
ret = upload_dma_data(sscape, init_fw->data, init_fw->size);
release_firmware(init_fw);
spin_lock_irqsave(&sscape->lock, flags);
if (ret == 0)
data = host_read_ctrl_unsafe(sscape->io_base, 100);
if (data & 0x10)
sscape_write_unsafe(sscape->io_base, GA_SMCFGA_REG, 0x2f);
spin_unlock_irqrestore(&sscape->lock, flags);
data &= 0xf;
if (ret == 0 && data > 7) {
snd_printk(KERN_ERR
"sscape: timeout reading firmware version\n");
ret = -EAGAIN;
}
return (ret == 0) ? data : ret;
}
static int sscape_upload_microcode(struct snd_card *card, int version)
{
struct soundscape *sscape = get_card_soundscape(card);
const struct firmware *init_fw = NULL;
char name[14];
int err;
snprintf(name, sizeof(name), "sndscape.co%d", version);
err = request_firmware(&init_fw, name, card->dev);
if (err < 0) {
snd_printk(KERN_ERR "sscape: Error loading sndscape.co%d",
version);
return err;
}
err = upload_dma_data(sscape, init_fw->data, init_fw->size);
if (err == 0)
snd_printk(KERN_INFO "sscape: MIDI firmware loaded %d KBs\n",
init_fw->size >> 10);
release_firmware(init_fw);
return err;
}
static int sscape_midi_info(struct snd_kcontrol *ctl,
struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = 1;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = 127;
return 0;
}
static int sscape_midi_get(struct snd_kcontrol *kctl,
struct snd_ctl_elem_value *uctl)
{
struct snd_wss *chip = snd_kcontrol_chip(kctl);
struct snd_card *card = chip->card;
register struct soundscape *s = get_card_soundscape(card);
unsigned long flags;
spin_lock_irqsave(&s->lock, flags);
uctl->value.integer.value[0] = s->midi_vol;
spin_unlock_irqrestore(&s->lock, flags);
return 0;
}
static int sscape_midi_put(struct snd_kcontrol *kctl,
struct snd_ctl_elem_value *uctl)
{
struct snd_wss *chip = snd_kcontrol_chip(kctl);
struct snd_card *card = chip->card;
struct soundscape *s = get_card_soundscape(card);
unsigned long flags;
int change;
unsigned char new_val;
spin_lock_irqsave(&s->lock, flags);
new_val = uctl->value.integer.value[0] & 127;
set_host_mode_unsafe(s->io_base);
if (s->midi_vol == new_val) {
change = 0;
goto __skip_change;
}
change = host_write_ctrl_unsafe(s->io_base, CMD_SET_MIDI_VOL, 100)
&& host_write_ctrl_unsafe(s->io_base, new_val, 100)
&& host_write_ctrl_unsafe(s->io_base, CMD_XXX_MIDI_VOL, 100)
&& host_write_ctrl_unsafe(s->io_base, new_val, 100);
s->midi_vol = new_val;
__skip_change:
set_midi_mode_unsafe(s->io_base);
spin_unlock_irqrestore(&s->lock, flags);
return change;
}
static unsigned get_irq_config(int sscape_type, int irq)
{
static const int valid_irq[] = { 9, 5, 7, 10 };
static const int old_irq[] = { 9, 7, 5, 15 };
unsigned cfg;
if (sscape_type == MEDIA_FX) {
for (cfg = 0; cfg < ARRAY_SIZE(old_irq); ++cfg)
if (irq == old_irq[cfg])
return cfg;
} else {
for (cfg = 0; cfg < ARRAY_SIZE(valid_irq); ++cfg)
if (irq == valid_irq[cfg])
return cfg;
}
return INVALID_IRQ;
}
static int detect_sscape(struct soundscape *s, long wss_io)
{
unsigned long flags;
unsigned d;
int retval = 0;
spin_lock_irqsave(&s->lock, flags);
if ((inb(HOST_CTRL_IO(s->io_base)) & 0x78) != 0)
goto _done;
d = inb(ODIE_ADDR_IO(s->io_base)) & 0xf0;
if ((d & 0x80) != 0)
goto _done;
if (d == 0)
s->ic_type = IC_ODIE;
else if ((d & 0x60) != 0)
s->ic_type = IC_OPUS;
else
goto _done;
outb(0xfa, ODIE_ADDR_IO(s->io_base));
if ((inb(ODIE_ADDR_IO(s->io_base)) & 0x9f) != 0x0a)
goto _done;
outb(0xfe, ODIE_ADDR_IO(s->io_base));
if ((inb(ODIE_ADDR_IO(s->io_base)) & 0x9f) != 0x0e)
goto _done;
outb(0xfe, ODIE_ADDR_IO(s->io_base));
d = inb(ODIE_DATA_IO(s->io_base));
if (s->type != SSCAPE_VIVO && (d & 0x9f) != 0x0e)
goto _done;
if (s->ic_type == IC_OPUS)
activate_ad1845_unsafe(s->io_base);
if (s->type == SSCAPE_VIVO)
wss_io += 4;
d = sscape_read_unsafe(s->io_base, GA_HMCTL_REG);
sscape_write_unsafe(s->io_base, GA_HMCTL_REG, d | 0xc0);
for (d = 0; d < 500; d++) {
if ((inb(wss_io) & 0x80) == 0)
break;
spin_unlock_irqrestore(&s->lock, flags);
msleep(1);
spin_lock_irqsave(&s->lock, flags);
}
if ((inb(wss_io) & 0x80) != 0)
goto _done;
if (inb(wss_io + 2) == 0xff)
goto _done;
d = sscape_read_unsafe(s->io_base, GA_HMCTL_REG) & 0x3f;
sscape_write_unsafe(s->io_base, GA_HMCTL_REG, d);
if ((inb(wss_io) & 0x80) != 0)
s->type = MEDIA_FX;
d = sscape_read_unsafe(s->io_base, GA_HMCTL_REG);
sscape_write_unsafe(s->io_base, GA_HMCTL_REG, d | 0xc0);
for (d = 0; d < 500; d++) {
if ((inb(wss_io) & 0x80) == 0)
break;
spin_unlock_irqrestore(&s->lock, flags);
msleep(1);
spin_lock_irqsave(&s->lock, flags);
}
retval = 1;
_done:
spin_unlock_irqrestore(&s->lock, flags);
return retval;
}
static int mpu401_open(struct snd_mpu401 *mpu)
{
if (!verify_mpu401(mpu)) {
snd_printk(KERN_ERR "sscape: MIDI disabled, "
"please load firmware\n");
return -ENODEV;
}
return 0;
}
static int create_mpu401(struct snd_card *card, int devnum,
unsigned long port, int irq)
{
struct soundscape *sscape = get_card_soundscape(card);
struct snd_rawmidi *rawmidi;
int err;
err = snd_mpu401_uart_new(card, devnum, MPU401_HW_MPU401, port,
MPU401_INFO_INTEGRATED, irq, &rawmidi);
if (err == 0) {
struct snd_mpu401 *mpu = rawmidi->private_data;
mpu->open_input = mpu401_open;
mpu->open_output = mpu401_open;
mpu->private_data = sscape;
initialise_mpu401(mpu);
}
return err;
}
static int create_ad1845(struct snd_card *card, unsigned port,
int irq, int dma1, int dma2)
{
register struct soundscape *sscape = get_card_soundscape(card);
struct snd_wss *chip;
int err;
int codec_type = WSS_HW_DETECT;
switch (sscape->type) {
case MEDIA_FX:
case SSCAPE:
if (sscape->ic_type != IC_OPUS)
codec_type = WSS_HW_AD1848;
break;
case SSCAPE_VIVO:
port += 4;
break;
default:
break;
}
err = snd_wss_create(card, port, -1, irq, dma1, dma2,
codec_type, WSS_HWSHARE_DMA1, &chip);
if (!err) {
unsigned long flags;
struct snd_pcm *pcm;
if (sscape->type != SSCAPE_VIVO) {
snd_wss_mce_up(chip);
spin_lock_irqsave(&chip->reg_lock, flags);
snd_wss_out(chip, AD1845_CLOCK, 0x20);
spin_unlock_irqrestore(&chip->reg_lock, flags);
snd_wss_mce_down(chip);
}
err = snd_wss_pcm(chip, 0, &pcm);
if (err < 0) {
snd_printk(KERN_ERR "sscape: No PCM device "
"for AD1845 chip\n");
goto _error;
}
err = snd_wss_mixer(chip);
if (err < 0) {
snd_printk(KERN_ERR "sscape: No mixer device "
"for AD1845 chip\n");
goto _error;
}
if (chip->hardware != WSS_HW_AD1848) {
err = snd_wss_timer(chip, 0, NULL);
if (err < 0) {
snd_printk(KERN_ERR "sscape: No timer device "
"for AD1845 chip\n");
goto _error;
}
}
if (sscape->type != SSCAPE_VIVO) {
err = snd_ctl_add(card,
snd_ctl_new1(&midi_mixer_ctl, chip));
if (err < 0) {
snd_printk(KERN_ERR "sscape: Could not create "
"MIDI mixer control\n");
goto _error;
}
}
sscape->chip = chip;
}
_error:
return err;
}
static int create_sscape(int dev, struct snd_card *card)
{
struct soundscape *sscape = get_card_soundscape(card);
unsigned dma_cfg;
unsigned irq_cfg;
unsigned mpu_irq_cfg;
struct resource *io_res;
struct resource *wss_res;
unsigned long flags;
int err;
int val;
const char *name;
io_res = request_region(port[dev], 8, "SoundScape");
if (!io_res) {
snd_printk(KERN_ERR
"sscape: can't grab port 0x%lx\n", port[dev]);
return -EBUSY;
}
wss_res = NULL;
if (sscape->type == SSCAPE_VIVO) {
wss_res = request_region(wss_port[dev], 4, "SoundScape");
if (!wss_res) {
snd_printk(KERN_ERR "sscape: can't grab port 0x%lx\n",
wss_port[dev]);
err = -EBUSY;
goto _release_region;
}
}
err = request_dma(dma[dev], "SoundScape");
if (err < 0) {
snd_printk(KERN_ERR "sscape: can't grab DMA %d\n", dma[dev]);
goto _release_region;
}
spin_lock_init(&sscape->lock);
sscape->io_res = io_res;
sscape->wss_res = wss_res;
sscape->io_base = port[dev];
if (!detect_sscape(sscape, wss_port[dev])) {
printk(KERN_ERR "sscape: hardware not detected at 0x%x\n",
sscape->io_base);
err = -ENODEV;
goto _release_dma;
}
switch (sscape->type) {
case MEDIA_FX:
name = "MediaFX/SoundFX";
break;
case SSCAPE:
name = "Soundscape";
break;
case SSCAPE_PNP:
name = "Soundscape PnP";
break;
case SSCAPE_VIVO:
name = "Soundscape VIVO";
break;
default:
name = "unknown Soundscape";
break;
}
printk(KERN_INFO "sscape: %s card detected at 0x%x, using IRQ %d, DMA %d\n",
name, sscape->io_base, irq[dev], dma[dev]);
irq_cfg = get_irq_config(sscape->type, irq[dev]);
if (irq_cfg == INVALID_IRQ) {
snd_printk(KERN_ERR "sscape: Invalid IRQ %d\n", irq[dev]);
err = -ENXIO;
goto _release_dma;
}
mpu_irq_cfg = get_irq_config(sscape->type, mpu_irq[dev]);
if (mpu_irq_cfg == INVALID_IRQ) {
snd_printk(KERN_ERR "sscape: Invalid IRQ %d\n", mpu_irq[dev]);
err = -ENXIO;
goto _release_dma;
}
spin_lock_irqsave(&sscape->lock, flags);
sscape_write_unsafe(sscape->io_base, GA_SMCFGA_REG, 0x2e);
sscape_write_unsafe(sscape->io_base, GA_SMCFGB_REG, 0x00);
sscape_write_unsafe(sscape->io_base, GA_DMACFG_REG, 0x50);
dma_cfg = (sscape->ic_type == IC_OPUS ? 0x40 : 0x70);
sscape_write_unsafe(sscape->io_base, GA_DMAA_REG, dma_cfg);
sscape_write_unsafe(sscape->io_base, GA_DMAB_REG, 0x20);
mpu_irq_cfg |= mpu_irq_cfg << 2;
val = sscape_read_unsafe(sscape->io_base, GA_HMCTL_REG) & 0xF7;
if (joystick[dev])
val |= 8;
sscape_write_unsafe(sscape->io_base, GA_HMCTL_REG, val | 0x10);
sscape_write_unsafe(sscape->io_base, GA_INTCFG_REG, 0xf0 | mpu_irq_cfg);
sscape_write_unsafe(sscape->io_base,
GA_CDCFG_REG, 0x09 | DMA_8BIT
| (dma[dev] << 4) | (irq_cfg << 1));
sscape_write_unsafe(sscape->io_base, GA_INTENA_REG, 0x80);
spin_unlock_irqrestore(&sscape->lock, flags);
err = create_ad1845(card, wss_port[dev], irq[dev],
dma[dev], dma2[dev]);
if (err < 0) {
snd_printk(KERN_ERR
"sscape: No AD1845 device at 0x%lx, IRQ %d\n",
wss_port[dev], irq[dev]);
goto _release_dma;
}
strcpy(card->driver, "SoundScape");
strcpy(card->shortname, name);
snprintf(card->longname, sizeof(card->longname),
"%s at 0x%lx, IRQ %d, DMA1 %d, DMA2 %d\n",
name, sscape->chip->port, sscape->chip->irq,
sscape->chip->dma1, sscape->chip->dma2);
#define MIDI_DEVNUM 0
if (sscape->type != SSCAPE_VIVO) {
err = sscape_upload_bootblock(card);
if (err >= 0)
err = sscape_upload_microcode(card, err);
if (err == 0) {
err = create_mpu401(card, MIDI_DEVNUM, port[dev],
mpu_irq[dev]);
if (err < 0) {
snd_printk(KERN_ERR "sscape: Failed to create "
"MPU-401 device at 0x%lx\n",
port[dev]);
goto _release_dma;
}
spin_lock_irqsave(&sscape->lock, flags);
sscape->midi_vol = 0;
host_write_ctrl_unsafe(sscape->io_base,
CMD_SET_MIDI_VOL, 100);
host_write_ctrl_unsafe(sscape->io_base,
sscape->midi_vol, 100);
host_write_ctrl_unsafe(sscape->io_base,
CMD_XXX_MIDI_VOL, 100);
host_write_ctrl_unsafe(sscape->io_base,
sscape->midi_vol, 100);
host_write_ctrl_unsafe(sscape->io_base,
CMD_SET_EXTMIDI, 100);
host_write_ctrl_unsafe(sscape->io_base,
0, 100);
host_write_ctrl_unsafe(sscape->io_base, CMD_ACK, 100);
set_midi_mode_unsafe(sscape->io_base);
spin_unlock_irqrestore(&sscape->lock, flags);
}
}
card->private_free = soundscape_free;
return 0;
_release_dma:
free_dma(dma[dev]);
_release_region:
release_and_free_resource(wss_res);
release_and_free_resource(io_res);
return err;
}
static int snd_sscape_match(struct device *pdev, unsigned int i)
{
if (port[i] == SNDRV_AUTO_PORT)
return 0;
if (irq[i] == SNDRV_AUTO_IRQ ||
mpu_irq[i] == SNDRV_AUTO_IRQ ||
dma[i] == SNDRV_AUTO_DMA) {
printk(KERN_INFO
"sscape: insufficient parameters, "
"need IO, IRQ, MPU-IRQ and DMA\n");
return 0;
}
return 1;
}
static int snd_sscape_probe(struct device *pdev, unsigned int dev)
{
struct snd_card *card;
struct soundscape *sscape;
int ret;
ret = snd_card_new(pdev, index[dev], id[dev], THIS_MODULE,
sizeof(struct soundscape), &card);
if (ret < 0)
return ret;
sscape = get_card_soundscape(card);
sscape->type = SSCAPE;
dma[dev] &= 0x03;
ret = create_sscape(dev, card);
if (ret < 0)
goto _release_card;
ret = snd_card_register(card);
if (ret < 0) {
snd_printk(KERN_ERR "sscape: Failed to register sound card\n");
goto _release_card;
}
dev_set_drvdata(pdev, card);
return 0;
_release_card:
snd_card_free(card);
return ret;
}
static int snd_sscape_remove(struct device *devptr, unsigned int dev)
{
snd_card_free(dev_get_drvdata(devptr));
return 0;
}
static inline int get_next_autoindex(int i)
{
while (i < SNDRV_CARDS && port[i] != SNDRV_AUTO_PORT)
++i;
return i;
}
static int sscape_pnp_detect(struct pnp_card_link *pcard,
const struct pnp_card_device_id *pid)
{
static int idx = 0;
struct pnp_dev *dev;
struct snd_card *card;
struct soundscape *sscape;
int ret;
idx = get_next_autoindex(idx);
if (idx >= SNDRV_CARDS)
return -ENOSPC;
dev = pnp_request_card_device(pcard, pid->devs[0].id, NULL);
if (!dev)
return -ENODEV;
if (!pnp_is_active(dev)) {
if (pnp_activate_dev(dev) < 0) {
snd_printk(KERN_INFO "sscape: device is inactive\n");
return -EBUSY;
}
}
ret = snd_card_new(&pcard->card->dev,
index[idx], id[idx], THIS_MODULE,
sizeof(struct soundscape), &card);
if (ret < 0)
return ret;
sscape = get_card_soundscape(card);
if (!strncmp("ENS4081", pid->id, 7))
sscape->type = SSCAPE_VIVO;
else
sscape->type = SSCAPE_PNP;
port[idx] = pnp_port_start(dev, 0);
irq[idx] = pnp_irq(dev, 0);
mpu_irq[idx] = pnp_irq(dev, 1);
dma[idx] = pnp_dma(dev, 0) & 0x03;
if (sscape->type == SSCAPE_PNP) {
dma2[idx] = dma[idx];
wss_port[idx] = CODEC_IO(port[idx]);
} else {
wss_port[idx] = pnp_port_start(dev, 1);
dma2[idx] = pnp_dma(dev, 1);
}
ret = create_sscape(idx, card);
if (ret < 0)
goto _release_card;
ret = snd_card_register(card);
if (ret < 0) {
snd_printk(KERN_ERR "sscape: Failed to register sound card\n");
goto _release_card;
}
pnp_set_card_drvdata(pcard, card);
++idx;
return 0;
_release_card:
snd_card_free(card);
return ret;
}
static void sscape_pnp_remove(struct pnp_card_link *pcard)
{
snd_card_free(pnp_get_card_drvdata(pcard));
pnp_set_card_drvdata(pcard, NULL);
}
static int __init sscape_init(void)
{
int err;
err = isa_register_driver(&snd_sscape_driver, SNDRV_CARDS);
#ifdef CONFIG_PNP
if (!err)
isa_registered = 1;
err = pnp_register_card_driver(&sscape_pnpc_driver);
if (!err)
pnp_registered = 1;
if (isa_registered)
err = 0;
#endif
return err;
}
static void __exit sscape_exit(void)
{
#ifdef CONFIG_PNP
if (pnp_registered)
pnp_unregister_card_driver(&sscape_pnpc_driver);
if (isa_registered)
#endif
isa_unregister_driver(&snd_sscape_driver);
}
