static int build_via_table(struct viadev *dev, struct snd_pcm_substream *substream,
struct pci_dev *pci,
unsigned int periods, unsigned int fragsize)
{
unsigned int i, idx, ofs, rest;
struct via82xx *chip = snd_pcm_substream_chip(substream);
if (dev->table.area == NULL) {
if (snd_dma_alloc_pages(SNDRV_DMA_TYPE_DEV, snd_dma_pci_data(chip->pci),
PAGE_ALIGN(VIA_TABLE_SIZE * 2 * 8),
&dev->table) < 0)
return -ENOMEM;
}
if (! dev->idx_table) {
dev->idx_table = kmalloc(sizeof(*dev->idx_table) * VIA_TABLE_SIZE, GFP_KERNEL);
if (! dev->idx_table)
return -ENOMEM;
}
idx = 0;
ofs = 0;
for (i = 0; i < periods; i++) {
rest = fragsize;
do {
unsigned int r;
unsigned int flag;
unsigned int addr;
if (idx >= VIA_TABLE_SIZE) {
dev_err(&pci->dev, "too much table size!\n");
return -EINVAL;
}
addr = snd_pcm_sgbuf_get_addr(substream, ofs);
((u32 *)dev->table.area)[idx << 1] = cpu_to_le32(addr);
r = snd_pcm_sgbuf_get_chunk_size(substream, ofs, rest);
rest -= r;
if (! rest) {
if (i == periods - 1)
flag = VIA_TBL_BIT_EOL;
else
flag = VIA_TBL_BIT_FLAG;
} else
flag = 0;
((u32 *)dev->table.area)[(idx<<1) + 1] = cpu_to_le32(r | flag);
dev->idx_table[idx].offset = ofs;
dev->idx_table[idx].size = r;
ofs += r;
idx++;
} while (rest > 0);
}
dev->tbl_entries = idx;
dev->bufsize = periods * fragsize;
dev->bufsize2 = dev->bufsize / 2;
dev->fragsize = fragsize;
return 0;
}
static int clean_via_table(struct viadev *dev, struct snd_pcm_substream *substream,
struct pci_dev *pci)
{
if (dev->table.area) {
snd_dma_free_pages(&dev->table);
dev->table.area = NULL;
}
kfree(dev->idx_table);
dev->idx_table = NULL;
return 0;
}
static inline unsigned int snd_via82xx_codec_xread(struct via82xx *chip)
{
return inl(VIAREG(chip, AC97));
}
static inline void snd_via82xx_codec_xwrite(struct via82xx *chip, unsigned int val)
{
outl(val, VIAREG(chip, AC97));
}
static int snd_via82xx_codec_ready(struct via82xx *chip, int secondary)
{
unsigned int timeout = 1000;
unsigned int val;
while (timeout-- > 0) {
udelay(1);
if (!((val = snd_via82xx_codec_xread(chip)) & VIA_REG_AC97_BUSY))
return val & 0xffff;
}
dev_err(chip->card->dev, "codec_ready: codec %i is not ready [0x%x]\n",
secondary, snd_via82xx_codec_xread(chip));
return -EIO;
}
static int snd_via82xx_codec_valid(struct via82xx *chip, int secondary)
{
unsigned int timeout = 1000;
unsigned int val, val1;
unsigned int stat = !secondary ? VIA_REG_AC97_PRIMARY_VALID :
VIA_REG_AC97_SECONDARY_VALID;
while (timeout-- > 0) {
val = snd_via82xx_codec_xread(chip);
val1 = val & (VIA_REG_AC97_BUSY | stat);
if (val1 == stat)
return val & 0xffff;
udelay(1);
}
return -EIO;
}
static void snd_via82xx_codec_wait(struct snd_ac97 *ac97)
{
struct via82xx *chip = ac97->private_data;
int err;
err = snd_via82xx_codec_ready(chip, ac97->num);
if (!nodelay)
msleep(500);
}
static void snd_via82xx_codec_write(struct snd_ac97 *ac97,
unsigned short reg,
unsigned short val)
{
struct via82xx *chip = ac97->private_data;
unsigned int xval;
xval = !ac97->num ? VIA_REG_AC97_CODEC_ID_PRIMARY : VIA_REG_AC97_CODEC_ID_SECONDARY;
xval <<= VIA_REG_AC97_CODEC_ID_SHIFT;
xval |= reg << VIA_REG_AC97_CMD_SHIFT;
xval |= val << VIA_REG_AC97_DATA_SHIFT;
snd_via82xx_codec_xwrite(chip, xval);
snd_via82xx_codec_ready(chip, ac97->num);
}
static unsigned short snd_via82xx_codec_read(struct snd_ac97 *ac97, unsigned short reg)
{
struct via82xx *chip = ac97->private_data;
unsigned int xval, val = 0xffff;
int again = 0;
xval = ac97->num << VIA_REG_AC97_CODEC_ID_SHIFT;
xval |= ac97->num ? VIA_REG_AC97_SECONDARY_VALID : VIA_REG_AC97_PRIMARY_VALID;
xval |= VIA_REG_AC97_READ;
xval |= (reg & 0x7f) << VIA_REG_AC97_CMD_SHIFT;
while (1) {
if (again++ > 3) {
dev_err(chip->card->dev,
"codec_read: codec %i is not valid [0x%x]\n",
ac97->num, snd_via82xx_codec_xread(chip));
return 0xffff;
}
snd_via82xx_codec_xwrite(chip, xval);
udelay (20);
if (snd_via82xx_codec_valid(chip, ac97->num) >= 0) {
udelay(25);
val = snd_via82xx_codec_xread(chip);
break;
}
}
return val & 0xffff;
}
static void snd_via82xx_channel_reset(struct via82xx *chip, struct viadev *viadev)
{
outb(VIA_REG_CTRL_PAUSE | VIA_REG_CTRL_TERMINATE | VIA_REG_CTRL_RESET,
VIADEV_REG(viadev, OFFSET_CONTROL));
inb(VIADEV_REG(viadev, OFFSET_CONTROL));
udelay(50);
outb(0x00, VIADEV_REG(viadev, OFFSET_CONTROL));
outb(0x03, VIADEV_REG(viadev, OFFSET_STATUS));
outb(0x00, VIADEV_REG(viadev, OFFSET_TYPE));
viadev->lastpos = 0;
viadev->hwptr_done = 0;
}
static irqreturn_t snd_via686_interrupt(int irq, void *dev_id)
{
struct via82xx *chip = dev_id;
unsigned int status;
unsigned int i;
status = inl(VIAREG(chip, SGD_SHADOW));
if (! (status & chip->intr_mask)) {
if (chip->rmidi)
return snd_mpu401_uart_interrupt(irq, chip->rmidi->private_data);
return IRQ_NONE;
}
spin_lock(&chip->reg_lock);
for (i = 0; i < chip->num_devs; i++) {
struct viadev *viadev = &chip->devs[i];
unsigned char c_status = inb(VIADEV_REG(viadev, OFFSET_STATUS));
if (! (c_status & (VIA_REG_STAT_EOL|VIA_REG_STAT_FLAG|VIA_REG_STAT_STOPPED)))
continue;
if (viadev->substream && viadev->running) {
if (c_status & VIA_REG_STAT_EOL)
viadev->hwptr_done = 0;
else
viadev->hwptr_done += viadev->fragsize;
viadev->in_interrupt = c_status;
spin_unlock(&chip->reg_lock);
snd_pcm_period_elapsed(viadev->substream);
spin_lock(&chip->reg_lock);
viadev->in_interrupt = 0;
}
outb(c_status, VIADEV_REG(viadev, OFFSET_STATUS));
}
spin_unlock(&chip->reg_lock);
return IRQ_HANDLED;
}
static irqreturn_t snd_via8233_interrupt(int irq, void *dev_id)
{
struct via82xx *chip = dev_id;
unsigned int status;
unsigned int i;
int irqreturn = 0;
spin_lock(&chip->reg_lock);
status = inl(VIAREG(chip, SGD_SHADOW));
for (i = 0; i < chip->num_devs; i++) {
struct viadev *viadev = &chip->devs[i];
struct snd_pcm_substream *substream;
unsigned char c_status, shadow_status;
shadow_status = (status >> viadev->shadow_shift) &
(VIA8233_SHADOW_STAT_ACTIVE|VIA_REG_STAT_EOL|
VIA_REG_STAT_FLAG);
c_status = shadow_status & (VIA_REG_STAT_EOL|VIA_REG_STAT_FLAG);
if (!c_status)
continue;
substream = viadev->substream;
if (substream && viadev->running) {
if (c_status & VIA_REG_STAT_EOL)
viadev->hwptr_done = 0;
else
viadev->hwptr_done += viadev->fragsize;
viadev->in_interrupt = c_status;
if (shadow_status & VIA8233_SHADOW_STAT_ACTIVE)
viadev->in_interrupt |= VIA_REG_STAT_ACTIVE;
spin_unlock(&chip->reg_lock);
snd_pcm_period_elapsed(substream);
spin_lock(&chip->reg_lock);
viadev->in_interrupt = 0;
}
outb(c_status, VIADEV_REG(viadev, OFFSET_STATUS));
irqreturn = 1;
}
spin_unlock(&chip->reg_lock);
return IRQ_RETVAL(irqreturn);
}
static int snd_via82xx_pcm_trigger(struct snd_pcm_substream *substream, int cmd)
{
struct via82xx *chip = snd_pcm_substream_chip(substream);
struct viadev *viadev = substream->runtime->private_data;
unsigned char val;
if (chip->chip_type != TYPE_VIA686)
val = VIA_REG_CTRL_INT;
else
val = 0;
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
case SNDRV_PCM_TRIGGER_RESUME:
val |= VIA_REG_CTRL_START;
viadev->running = 1;
break;
case SNDRV_PCM_TRIGGER_STOP:
case SNDRV_PCM_TRIGGER_SUSPEND:
val = VIA_REG_CTRL_TERMINATE;
viadev->running = 0;
break;
case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
val |= VIA_REG_CTRL_PAUSE;
viadev->running = 0;
break;
case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
viadev->running = 1;
break;
default:
return -EINVAL;
}
outb(val, VIADEV_REG(viadev, OFFSET_CONTROL));
if (cmd == SNDRV_PCM_TRIGGER_STOP)
snd_via82xx_channel_reset(chip, viadev);
return 0;
}
static inline unsigned int calc_linear_pos(struct via82xx *chip,
struct viadev *viadev,
unsigned int idx,
unsigned int count)
{
unsigned int size, base, res;
size = viadev->idx_table[idx].size;
base = viadev->idx_table[idx].offset;
res = base + size - count;
if (res >= viadev->bufsize)
res -= viadev->bufsize;
if (size < count) {
dev_dbg(chip->card->dev,
"invalid via82xx_cur_ptr (size = %d, count = %d)\n",
(int)size, (int)count);
res = viadev->lastpos;
} else {
if (! count) {
int delta = res - viadev->lastpos;
if (delta < 0)
delta += viadev->bufsize;
if ((unsigned int)delta > viadev->fragsize)
res = base;
}
if (check_invalid_pos(viadev, res)) {
#ifdef POINTER_DEBUG
dev_dbg(chip->card->dev,
"fail: idx = %i/%i, lastpos = 0x%x, bufsize2 = 0x%x, offsize = 0x%x, size = 0x%x, count = 0x%x\n",
idx, viadev->tbl_entries,
viadev->lastpos, viadev->bufsize2,
viadev->idx_table[idx].offset,
viadev->idx_table[idx].size, count);
#endif
res = base + size;
if (check_invalid_pos(viadev, res)) {
dev_dbg(chip->card->dev,
"invalid via82xx_cur_ptr (2), using last valid pointer\n");
res = viadev->lastpos;
}
}
}
return res;
}
static snd_pcm_uframes_t snd_via686_pcm_pointer(struct snd_pcm_substream *substream)
{
struct via82xx *chip = snd_pcm_substream_chip(substream);
struct viadev *viadev = substream->runtime->private_data;
unsigned int idx, ptr, count, res;
if (snd_BUG_ON(!viadev->tbl_entries))
return 0;
if (!(inb(VIADEV_REG(viadev, OFFSET_STATUS)) & VIA_REG_STAT_ACTIVE))
return 0;
spin_lock(&chip->reg_lock);
count = inl(VIADEV_REG(viadev, OFFSET_CURR_COUNT)) & 0xffffff;
ptr = inl(VIADEV_REG(viadev, OFFSET_CURR_PTR));
if (ptr <= (unsigned int)viadev->table.addr)
idx = 0;
else
idx = ((ptr - (unsigned int)viadev->table.addr) / 8 - 1) % viadev->tbl_entries;
res = calc_linear_pos(chip, viadev, idx, count);
viadev->lastpos = res;
spin_unlock(&chip->reg_lock);
return bytes_to_frames(substream->runtime, res);
}
static snd_pcm_uframes_t snd_via8233_pcm_pointer(struct snd_pcm_substream *substream)
{
struct via82xx *chip = snd_pcm_substream_chip(substream);
struct viadev *viadev = substream->runtime->private_data;
unsigned int idx, count, res;
int status;
if (snd_BUG_ON(!viadev->tbl_entries))
return 0;
spin_lock(&chip->reg_lock);
count = inl(VIADEV_REG(viadev, OFFSET_CURR_COUNT));
status = viadev->in_interrupt;
if (!status)
status = inb(VIADEV_REG(viadev, OFFSET_STATUS));
if (chip->revision == VIA_REV_8251 && (status & VIA_REG_STAT_EOL))
snd_via82xx_pcm_trigger(substream, SNDRV_PCM_TRIGGER_START);
if (!(status & VIA_REG_STAT_ACTIVE)) {
res = 0;
goto unlock;
}
if (count & 0xffffff) {
idx = count >> 24;
if (idx >= viadev->tbl_entries) {
#ifdef POINTER_DEBUG
dev_dbg(chip->card->dev,
"fail: invalid idx = %i/%i\n", idx,
viadev->tbl_entries);
#endif
res = viadev->lastpos;
} else {
count &= 0xffffff;
res = calc_linear_pos(chip, viadev, idx, count);
}
} else {
res = viadev->hwptr_done;
if (!viadev->in_interrupt) {
if (status & VIA_REG_STAT_EOL) {
res = 0;
} else
if (status & VIA_REG_STAT_FLAG) {
res += viadev->fragsize;
}
}
}
unlock:
viadev->lastpos = res;
spin_unlock(&chip->reg_lock);
return bytes_to_frames(substream->runtime, res);
}
static int snd_via82xx_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *hw_params)
{
struct via82xx *chip = snd_pcm_substream_chip(substream);
struct viadev *viadev = substream->runtime->private_data;
int err;
err = snd_pcm_lib_malloc_pages(substream, params_buffer_bytes(hw_params));
if (err < 0)
return err;
err = build_via_table(viadev, substream, chip->pci,
params_periods(hw_params),
params_period_bytes(hw_params));
if (err < 0)
return err;
return 0;
}
static int snd_via82xx_hw_free(struct snd_pcm_substream *substream)
{
struct via82xx *chip = snd_pcm_substream_chip(substream);
struct viadev *viadev = substream->runtime->private_data;
clean_via_table(viadev, substream, chip->pci);
snd_pcm_lib_free_pages(substream);
return 0;
}
static void snd_via82xx_set_table_ptr(struct via82xx *chip, struct viadev *viadev)
{
snd_via82xx_codec_ready(chip, 0);
outl((u32)viadev->table.addr, VIADEV_REG(viadev, OFFSET_TABLE_PTR));
udelay(20);
snd_via82xx_codec_ready(chip, 0);
}
static void via686_setup_format(struct via82xx *chip, struct viadev *viadev,
struct snd_pcm_runtime *runtime)
{
snd_via82xx_channel_reset(chip, viadev);
snd_via82xx_set_table_ptr(chip, viadev);
outb(VIA_REG_TYPE_AUTOSTART |
(runtime->format == SNDRV_PCM_FORMAT_S16_LE ? VIA_REG_TYPE_16BIT : 0) |
(runtime->channels > 1 ? VIA_REG_TYPE_STEREO : 0) |
((viadev->reg_offset & 0x10) == 0 ? VIA_REG_TYPE_INT_LSAMPLE : 0) |
VIA_REG_TYPE_INT_EOL |
VIA_REG_TYPE_INT_FLAG, VIADEV_REG(viadev, OFFSET_TYPE));
}
static int snd_via686_playback_prepare(struct snd_pcm_substream *substream)
{
struct via82xx *chip = snd_pcm_substream_chip(substream);
struct viadev *viadev = substream->runtime->private_data;
struct snd_pcm_runtime *runtime = substream->runtime;
snd_ac97_set_rate(chip->ac97, AC97_PCM_FRONT_DAC_RATE, runtime->rate);
snd_ac97_set_rate(chip->ac97, AC97_SPDIF, runtime->rate);
via686_setup_format(chip, viadev, runtime);
return 0;
}
static int snd_via686_capture_prepare(struct snd_pcm_substream *substream)
{
struct via82xx *chip = snd_pcm_substream_chip(substream);
struct viadev *viadev = substream->runtime->private_data;
struct snd_pcm_runtime *runtime = substream->runtime;
snd_ac97_set_rate(chip->ac97, AC97_PCM_LR_ADC_RATE, runtime->rate);
via686_setup_format(chip, viadev, runtime);
return 0;
}
static int via_lock_rate(struct via_rate_lock *rec, int rate)
{
int changed = 0;
spin_lock_irq(&rec->lock);
if (rec->rate != rate) {
if (rec->rate && rec->used > 1)
changed = -EINVAL;
else {
rec->rate = rate;
changed = 1;
}
}
spin_unlock_irq(&rec->lock);
return changed;
}
static int snd_via8233_playback_prepare(struct snd_pcm_substream *substream)
{
struct via82xx *chip = snd_pcm_substream_chip(substream);
struct viadev *viadev = substream->runtime->private_data;
struct snd_pcm_runtime *runtime = substream->runtime;
int ac97_rate = chip->dxs_src ? 48000 : runtime->rate;
int rate_changed;
u32 rbits;
if ((rate_changed = via_lock_rate(&chip->rates[0], ac97_rate)) < 0)
return rate_changed;
if (rate_changed)
snd_ac97_set_rate(chip->ac97, AC97_PCM_FRONT_DAC_RATE,
chip->no_vra ? 48000 : runtime->rate);
if (chip->spdif_on && viadev->reg_offset == 0x30)
snd_ac97_set_rate(chip->ac97, AC97_SPDIF, runtime->rate);
if (runtime->rate == 48000)
rbits = 0xfffff;
else
rbits = (0x100000 / 48000) * runtime->rate +
((0x100000 % 48000) * runtime->rate) / 48000;
snd_BUG_ON(rbits & ~0xfffff);
snd_via82xx_channel_reset(chip, viadev);
snd_via82xx_set_table_ptr(chip, viadev);
outb(chip->playback_volume[viadev->reg_offset / 0x10][0],
VIADEV_REG(viadev, OFS_PLAYBACK_VOLUME_L));
outb(chip->playback_volume[viadev->reg_offset / 0x10][1],
VIADEV_REG(viadev, OFS_PLAYBACK_VOLUME_R));
outl((runtime->format == SNDRV_PCM_FORMAT_S16_LE ? VIA8233_REG_TYPE_16BIT : 0) |
(runtime->channels > 1 ? VIA8233_REG_TYPE_STEREO : 0) |
rbits |
0xff000000,
VIADEV_REG(viadev, OFFSET_STOP_IDX));
udelay(20);
snd_via82xx_codec_ready(chip, 0);
return 0;
}
static int snd_via8233_multi_prepare(struct snd_pcm_substream *substream)
{
struct via82xx *chip = snd_pcm_substream_chip(substream);
struct viadev *viadev = substream->runtime->private_data;
struct snd_pcm_runtime *runtime = substream->runtime;
unsigned int slots;
int fmt;
if (via_lock_rate(&chip->rates[0], runtime->rate) < 0)
return -EINVAL;
snd_ac97_set_rate(chip->ac97, AC97_PCM_FRONT_DAC_RATE, runtime->rate);
snd_ac97_set_rate(chip->ac97, AC97_PCM_SURR_DAC_RATE, runtime->rate);
snd_ac97_set_rate(chip->ac97, AC97_PCM_LFE_DAC_RATE, runtime->rate);
snd_ac97_set_rate(chip->ac97, AC97_SPDIF, runtime->rate);
snd_via82xx_channel_reset(chip, viadev);
snd_via82xx_set_table_ptr(chip, viadev);
fmt = (runtime->format == SNDRV_PCM_FORMAT_S16_LE) ?
VIA_REG_MULTPLAY_FMT_16BIT : VIA_REG_MULTPLAY_FMT_8BIT;
fmt |= runtime->channels << 4;
outb(fmt, VIADEV_REG(viadev, OFS_MULTPLAY_FORMAT));
#if 0
if (chip->revision == VIA_REV_8233A)
slots = 0;
else
#endif
{
switch (runtime->channels) {
case 1: slots = (1<<0) | (1<<4); break;
case 2: slots = (1<<0) | (2<<4); break;
case 3: slots = (1<<0) | (2<<4) | (5<<8); break;
case 4: slots = (1<<0) | (2<<4) | (3<<8) | (4<<12); break;
case 5: slots = (1<<0) | (2<<4) | (3<<8) | (4<<12) | (5<<16); break;
case 6: slots = (1<<0) | (2<<4) | (3<<8) | (4<<12) | (5<<16) | (6<<20); break;
default: slots = 0; break;
}
}
outl(0xff000000 | slots, VIADEV_REG(viadev, OFFSET_STOP_IDX));
udelay(20);
snd_via82xx_codec_ready(chip, 0);
return 0;
}
static int snd_via8233_capture_prepare(struct snd_pcm_substream *substream)
{
struct via82xx *chip = snd_pcm_substream_chip(substream);
struct viadev *viadev = substream->runtime->private_data;
struct snd_pcm_runtime *runtime = substream->runtime;
if (via_lock_rate(&chip->rates[1], runtime->rate) < 0)
return -EINVAL;
snd_ac97_set_rate(chip->ac97, AC97_PCM_LR_ADC_RATE, runtime->rate);
snd_via82xx_channel_reset(chip, viadev);
snd_via82xx_set_table_ptr(chip, viadev);
outb(VIA_REG_CAPTURE_FIFO_ENABLE, VIADEV_REG(viadev, OFS_CAPTURE_FIFO));
outl((runtime->format == SNDRV_PCM_FORMAT_S16_LE ? VIA8233_REG_TYPE_16BIT : 0) |
(runtime->channels > 1 ? VIA8233_REG_TYPE_STEREO : 0) |
0xff000000,
VIADEV_REG(viadev, OFFSET_STOP_IDX));
udelay(20);
snd_via82xx_codec_ready(chip, 0);
return 0;
}
static int snd_via82xx_pcm_open(struct via82xx *chip, struct viadev *viadev,
struct snd_pcm_substream *substream)
{
struct snd_pcm_runtime *runtime = substream->runtime;
int err;
struct via_rate_lock *ratep;
bool use_src = false;
runtime->hw = snd_via82xx_hw;
ratep = &chip->rates[viadev->direction];
spin_lock_irq(&ratep->lock);
ratep->used++;
if (chip->spdif_on && viadev->reg_offset == 0x30) {
runtime->hw.rates = chip->ac97->rates[AC97_RATES_SPDIF];
snd_pcm_limit_hw_rates(runtime);
} else if (chip->dxs_fixed && viadev->reg_offset < 0x40) {
runtime->hw.rates = SNDRV_PCM_RATE_48000;
runtime->hw.rate_min = runtime->hw.rate_max = 48000;
} else if (chip->dxs_src && viadev->reg_offset < 0x40) {
runtime->hw.rates = (SNDRV_PCM_RATE_CONTINUOUS |
SNDRV_PCM_RATE_8000_48000);
runtime->hw.rate_min = 8000;
runtime->hw.rate_max = 48000;
use_src = true;
} else if (! ratep->rate) {
int idx = viadev->direction ? AC97_RATES_ADC : AC97_RATES_FRONT_DAC;
runtime->hw.rates = chip->ac97->rates[idx];
snd_pcm_limit_hw_rates(runtime);
} else {
runtime->hw.rates = SNDRV_PCM_RATE_KNOT;
runtime->hw.rate_max = runtime->hw.rate_min = ratep->rate;
}
spin_unlock_irq(&ratep->lock);
if ((err = snd_pcm_hw_constraint_integer(runtime, SNDRV_PCM_HW_PARAM_PERIODS)) < 0)
return err;
if (use_src) {
err = snd_pcm_hw_rule_noresample(runtime, 48000);
if (err < 0)
return err;
}
runtime->private_data = viadev;
viadev->substream = substream;
return 0;
}
static int snd_via686_playback_open(struct snd_pcm_substream *substream)
{
struct via82xx *chip = snd_pcm_substream_chip(substream);
struct viadev *viadev = &chip->devs[chip->playback_devno + substream->number];
int err;
if ((err = snd_via82xx_pcm_open(chip, viadev, substream)) < 0)
return err;
return 0;
}
static int snd_via8233_playback_open(struct snd_pcm_substream *substream)
{
struct via82xx *chip = snd_pcm_substream_chip(substream);
struct viadev *viadev;
unsigned int stream;
int err;
viadev = &chip->devs[chip->playback_devno + substream->number];
if ((err = snd_via82xx_pcm_open(chip, viadev, substream)) < 0)
return err;
stream = viadev->reg_offset / 0x10;
if (chip->dxs_controls[stream]) {
chip->playback_volume[stream][0] =
VIA_DXS_MAX_VOLUME - (dxs_init_volume & 31);
chip->playback_volume[stream][1] =
VIA_DXS_MAX_VOLUME - (dxs_init_volume & 31);
chip->dxs_controls[stream]->vd[0].access &=
~SNDRV_CTL_ELEM_ACCESS_INACTIVE;
snd_ctl_notify(chip->card, SNDRV_CTL_EVENT_MASK_VALUE |
SNDRV_CTL_EVENT_MASK_INFO,
&chip->dxs_controls[stream]->id);
}
return 0;
}
static int snd_via8233_multi_open(struct snd_pcm_substream *substream)
{
struct via82xx *chip = snd_pcm_substream_chip(substream);
struct viadev *viadev = &chip->devs[chip->multi_devno];
int err;
static unsigned int channels[] = {
1, 2, 4, 6
};
static struct snd_pcm_hw_constraint_list hw_constraints_channels = {
.count = ARRAY_SIZE(channels),
.list = channels,
.mask = 0,
};
if ((err = snd_via82xx_pcm_open(chip, viadev, substream)) < 0)
return err;
substream->runtime->hw.channels_max = 6;
if (chip->revision == VIA_REV_8233A)
snd_pcm_hw_constraint_list(substream->runtime, 0,
SNDRV_PCM_HW_PARAM_CHANNELS,
&hw_constraints_channels);
return 0;
}
static int snd_via82xx_capture_open(struct snd_pcm_substream *substream)
{
struct via82xx *chip = snd_pcm_substream_chip(substream);
struct viadev *viadev = &chip->devs[chip->capture_devno + substream->pcm->device];
return snd_via82xx_pcm_open(chip, viadev, substream);
}
static int snd_via82xx_pcm_close(struct snd_pcm_substream *substream)
{
struct via82xx *chip = snd_pcm_substream_chip(substream);
struct viadev *viadev = substream->runtime->private_data;
struct via_rate_lock *ratep;
ratep = &chip->rates[viadev->direction];
spin_lock_irq(&ratep->lock);
ratep->used--;
if (! ratep->used)
ratep->rate = 0;
spin_unlock_irq(&ratep->lock);
if (! ratep->rate) {
if (! viadev->direction) {
snd_ac97_update_power(chip->ac97,
AC97_PCM_FRONT_DAC_RATE, 0);
snd_ac97_update_power(chip->ac97,
AC97_PCM_SURR_DAC_RATE, 0);
snd_ac97_update_power(chip->ac97,
AC97_PCM_LFE_DAC_RATE, 0);
} else
snd_ac97_update_power(chip->ac97,
AC97_PCM_LR_ADC_RATE, 0);
}
viadev->substream = NULL;
return 0;
}
static int snd_via8233_playback_close(struct snd_pcm_substream *substream)
{
struct via82xx *chip = snd_pcm_substream_chip(substream);
struct viadev *viadev = substream->runtime->private_data;
unsigned int stream;
stream = viadev->reg_offset / 0x10;
if (chip->dxs_controls[stream]) {
chip->dxs_controls[stream]->vd[0].access |=
SNDRV_CTL_ELEM_ACCESS_INACTIVE;
snd_ctl_notify(chip->card, SNDRV_CTL_EVENT_MASK_INFO,
&chip->dxs_controls[stream]->id);
}
return snd_via82xx_pcm_close(substream);
}
static void init_viadev(struct via82xx *chip, int idx, unsigned int reg_offset,
int shadow_pos, int direction)
{
chip->devs[idx].reg_offset = reg_offset;
chip->devs[idx].shadow_shift = shadow_pos * 4;
chip->devs[idx].direction = direction;
chip->devs[idx].port = chip->port + reg_offset;
}
static int snd_via8233_pcm_new(struct via82xx *chip)
{
struct snd_pcm *pcm;
struct snd_pcm_chmap *chmap;
int i, err;
chip->playback_devno = 0;
chip->multi_devno = 4;
chip->capture_devno = 5;
chip->num_devs = 7;
chip->intr_mask = 0x33033333;
err = snd_pcm_new(chip->card, chip->card->shortname, 0, 4, 1, &pcm);
if (err < 0)
return err;
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_PLAYBACK, &snd_via8233_playback_ops);
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_CAPTURE, &snd_via8233_capture_ops);
pcm->private_data = chip;
strcpy(pcm->name, chip->card->shortname);
chip->pcms[0] = pcm;
for (i = 0; i < 4; i++)
init_viadev(chip, i, 0x10 * i, i, 0);
init_viadev(chip, chip->capture_devno, VIA_REG_CAPTURE_8233_STATUS, 6, 1);
snd_pcm_lib_preallocate_pages_for_all(pcm, SNDRV_DMA_TYPE_DEV_SG,
snd_dma_pci_data(chip->pci),
64*1024, VIA_MAX_BUFSIZE);
err = snd_pcm_add_chmap_ctls(pcm, SNDRV_PCM_STREAM_PLAYBACK,
snd_pcm_std_chmaps, 2, 0,
&chmap);
if (err < 0)
return err;
err = snd_pcm_new(chip->card, chip->card->shortname, 1, 1, 1, &pcm);
if (err < 0)
return err;
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_PLAYBACK, &snd_via8233_multi_ops);
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_CAPTURE, &snd_via8233_capture_ops);
pcm->private_data = chip;
strcpy(pcm->name, chip->card->shortname);
chip->pcms[1] = pcm;
init_viadev(chip, chip->multi_devno, VIA_REG_MULTPLAY_STATUS, 4, 0);
init_viadev(chip, chip->capture_devno + 1, VIA_REG_CAPTURE_8233_STATUS + 0x10, 7, 1);
snd_pcm_lib_preallocate_pages_for_all(pcm, SNDRV_DMA_TYPE_DEV_SG,
snd_dma_pci_data(chip->pci),
64*1024, VIA_MAX_BUFSIZE);
err = snd_pcm_add_chmap_ctls(pcm, SNDRV_PCM_STREAM_PLAYBACK,
snd_pcm_alt_chmaps, 6, 0,
&chmap);
if (err < 0)
return err;
chip->ac97->chmaps[SNDRV_PCM_STREAM_PLAYBACK] = chmap;
return 0;
}
static int snd_via8233a_pcm_new(struct via82xx *chip)
{
struct snd_pcm *pcm;
struct snd_pcm_chmap *chmap;
int err;
chip->multi_devno = 0;
chip->playback_devno = 1;
chip->capture_devno = 2;
chip->num_devs = 3;
chip->intr_mask = 0x03033000;
err = snd_pcm_new(chip->card, chip->card->shortname, 0, 1, 1, &pcm);
if (err < 0)
return err;
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_PLAYBACK, &snd_via8233_multi_ops);
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_CAPTURE, &snd_via8233_capture_ops);
pcm->private_data = chip;
strcpy(pcm->name, chip->card->shortname);
chip->pcms[0] = pcm;
init_viadev(chip, chip->multi_devno, VIA_REG_MULTPLAY_STATUS, 4, 0);
init_viadev(chip, chip->capture_devno, VIA_REG_CAPTURE_8233_STATUS, 6, 1);
snd_pcm_lib_preallocate_pages_for_all(pcm, SNDRV_DMA_TYPE_DEV_SG,
snd_dma_pci_data(chip->pci),
64*1024, VIA_MAX_BUFSIZE);
err = snd_pcm_add_chmap_ctls(pcm, SNDRV_PCM_STREAM_PLAYBACK,
snd_pcm_alt_chmaps, 6, 0,
&chmap);
if (err < 0)
return err;
chip->ac97->chmaps[SNDRV_PCM_STREAM_PLAYBACK] = chmap;
if (! ac97_can_spdif(chip->ac97))
return 0;
err = snd_pcm_new(chip->card, chip->card->shortname, 1, 1, 0, &pcm);
if (err < 0)
return err;
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_PLAYBACK, &snd_via8233_playback_ops);
pcm->private_data = chip;
strcpy(pcm->name, chip->card->shortname);
chip->pcms[1] = pcm;
init_viadev(chip, chip->playback_devno, 0x30, 3, 0);
snd_pcm_lib_preallocate_pages_for_all(pcm, SNDRV_DMA_TYPE_DEV_SG,
snd_dma_pci_data(chip->pci),
64*1024, VIA_MAX_BUFSIZE);
return 0;
}
static int snd_via686_pcm_new(struct via82xx *chip)
{
struct snd_pcm *pcm;
int err;
chip->playback_devno = 0;
chip->capture_devno = 1;
chip->num_devs = 2;
chip->intr_mask = 0x77;
err = snd_pcm_new(chip->card, chip->card->shortname, 0, 1, 1, &pcm);
if (err < 0)
return err;
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_PLAYBACK, &snd_via686_playback_ops);
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_CAPTURE, &snd_via686_capture_ops);
pcm->private_data = chip;
strcpy(pcm->name, chip->card->shortname);
chip->pcms[0] = pcm;
init_viadev(chip, 0, VIA_REG_PLAYBACK_STATUS, 0, 0);
init_viadev(chip, 1, VIA_REG_CAPTURE_STATUS, 0, 1);
snd_pcm_lib_preallocate_pages_for_all(pcm, SNDRV_DMA_TYPE_DEV_SG,
snd_dma_pci_data(chip->pci),
64*1024, VIA_MAX_BUFSIZE);
return 0;
}
static int snd_via8233_capture_source_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
static char *texts[2] = {
"Input1", "Input2"
};
uinfo->type = SNDRV_CTL_ELEM_TYPE_ENUMERATED;
uinfo->count = 1;
uinfo->value.enumerated.items = 2;
if (uinfo->value.enumerated.item >= 2)
uinfo->value.enumerated.item = 1;
strcpy(uinfo->value.enumerated.name, texts[uinfo->value.enumerated.item]);
return 0;
}
static int snd_via8233_capture_source_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct via82xx *chip = snd_kcontrol_chip(kcontrol);
unsigned long port = chip->port + (kcontrol->id.index ? (VIA_REG_CAPTURE_CHANNEL + 0x10) : VIA_REG_CAPTURE_CHANNEL);
ucontrol->value.enumerated.item[0] = inb(port) & VIA_REG_CAPTURE_CHANNEL_MIC ? 1 : 0;
return 0;
}
static int snd_via8233_capture_source_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct via82xx *chip = snd_kcontrol_chip(kcontrol);
unsigned long port = chip->port + (kcontrol->id.index ? (VIA_REG_CAPTURE_CHANNEL + 0x10) : VIA_REG_CAPTURE_CHANNEL);
u8 val, oval;
spin_lock_irq(&chip->reg_lock);
oval = inb(port);
val = oval & ~VIA_REG_CAPTURE_CHANNEL_MIC;
if (ucontrol->value.enumerated.item[0])
val |= VIA_REG_CAPTURE_CHANNEL_MIC;
if (val != oval)
outb(val, port);
spin_unlock_irq(&chip->reg_lock);
return val != oval;
}
static int snd_via8233_dxs3_spdif_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct via82xx *chip = snd_kcontrol_chip(kcontrol);
u8 val;
pci_read_config_byte(chip->pci, VIA8233_SPDIF_CTRL, &val);
ucontrol->value.integer.value[0] = (val & VIA8233_SPDIF_DX3) ? 1 : 0;
return 0;
}
static int snd_via8233_dxs3_spdif_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct via82xx *chip = snd_kcontrol_chip(kcontrol);
u8 val, oval;
pci_read_config_byte(chip->pci, VIA8233_SPDIF_CTRL, &oval);
val = oval & ~VIA8233_SPDIF_DX3;
if (ucontrol->value.integer.value[0])
val |= VIA8233_SPDIF_DX3;
chip->spdif_on = ucontrol->value.integer.value[0] ? 1 : 0;
if (val != oval) {
pci_write_config_byte(chip->pci, VIA8233_SPDIF_CTRL, val);
return 1;
}
return 0;
}
static int snd_via8233_dxs_volume_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = 2;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = VIA_DXS_MAX_VOLUME;
return 0;
}
static int snd_via8233_dxs_volume_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct via82xx *chip = snd_kcontrol_chip(kcontrol);
unsigned int idx = kcontrol->id.subdevice;
ucontrol->value.integer.value[0] = VIA_DXS_MAX_VOLUME - chip->playback_volume[idx][0];
ucontrol->value.integer.value[1] = VIA_DXS_MAX_VOLUME - chip->playback_volume[idx][1];
return 0;
}
static int snd_via8233_pcmdxs_volume_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct via82xx *chip = snd_kcontrol_chip(kcontrol);
ucontrol->value.integer.value[0] = VIA_DXS_MAX_VOLUME - chip->playback_volume_c[0];
ucontrol->value.integer.value[1] = VIA_DXS_MAX_VOLUME - chip->playback_volume_c[1];
return 0;
}
static int snd_via8233_dxs_volume_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct via82xx *chip = snd_kcontrol_chip(kcontrol);
unsigned int idx = kcontrol->id.subdevice;
unsigned long port = chip->port + 0x10 * idx;
unsigned char val;
int i, change = 0;
for (i = 0; i < 2; i++) {
val = ucontrol->value.integer.value[i];
if (val > VIA_DXS_MAX_VOLUME)
val = VIA_DXS_MAX_VOLUME;
val = VIA_DXS_MAX_VOLUME - val;
change |= val != chip->playback_volume[idx][i];
if (change) {
chip->playback_volume[idx][i] = val;
outb(val, port + VIA_REG_OFS_PLAYBACK_VOLUME_L + i);
}
}
return change;
}
static int snd_via8233_pcmdxs_volume_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct via82xx *chip = snd_kcontrol_chip(kcontrol);
unsigned int idx;
unsigned char val;
int i, change = 0;
for (i = 0; i < 2; i++) {
val = ucontrol->value.integer.value[i];
if (val > VIA_DXS_MAX_VOLUME)
val = VIA_DXS_MAX_VOLUME;
val = VIA_DXS_MAX_VOLUME - val;
if (val != chip->playback_volume_c[i]) {
change = 1;
chip->playback_volume_c[i] = val;
for (idx = 0; idx < 4; idx++) {
unsigned long port = chip->port + 0x10 * idx;
chip->playback_volume[idx][i] = val;
outb(val, port + VIA_REG_OFS_PLAYBACK_VOLUME_L + i);
}
}
}
return change;
}
static void snd_via82xx_mixer_free_ac97_bus(struct snd_ac97_bus *bus)
{
struct via82xx *chip = bus->private_data;
chip->ac97_bus = NULL;
}
static void snd_via82xx_mixer_free_ac97(struct snd_ac97 *ac97)
{
struct via82xx *chip = ac97->private_data;
chip->ac97 = NULL;
}
static int snd_via82xx_mixer_new(struct via82xx *chip, const char *quirk_override)
{
struct snd_ac97_template ac97;
int err;
static struct snd_ac97_bus_ops ops = {
.write = snd_via82xx_codec_write,
.read = snd_via82xx_codec_read,
.wait = snd_via82xx_codec_wait,
};
if ((err = snd_ac97_bus(chip->card, 0, &ops, chip, &chip->ac97_bus)) < 0)
return err;
chip->ac97_bus->private_free = snd_via82xx_mixer_free_ac97_bus;
chip->ac97_bus->clock = chip->ac97_clock;
memset(&ac97, 0, sizeof(ac97));
ac97.private_data = chip;
ac97.private_free = snd_via82xx_mixer_free_ac97;
ac97.pci = chip->pci;
ac97.scaps = AC97_SCAP_SKIP_MODEM | AC97_SCAP_POWER_SAVE;
if ((err = snd_ac97_mixer(chip->ac97_bus, &ac97, &chip->ac97)) < 0)
return err;
snd_ac97_tune_hardware(chip->ac97, ac97_quirks, quirk_override);
if (chip->chip_type != TYPE_VIA686) {
snd_ac97_update_bits(chip->ac97, AC97_EXTENDED_STATUS, 0x03 << 4, 0x03 << 4);
}
return 0;
}
static int snd_via686_create_gameport(struct via82xx *chip, unsigned char *legacy)
{
struct gameport *gp;
struct resource *r;
if (!joystick)
return -ENODEV;
r = request_region(JOYSTICK_ADDR, 8, "VIA686 gameport");
if (!r) {
dev_warn(chip->card->dev, "cannot reserve joystick port %#x\n",
JOYSTICK_ADDR);
return -EBUSY;
}
chip->gameport = gp = gameport_allocate_port();
if (!gp) {
dev_err(chip->card->dev,
"cannot allocate memory for gameport\n");
release_and_free_resource(r);
return -ENOMEM;
}
gameport_set_name(gp, "VIA686 Gameport");
gameport_set_phys(gp, "pci%s/gameport0", pci_name(chip->pci));
gameport_set_dev_parent(gp, &chip->pci->dev);
gp->io = JOYSTICK_ADDR;
gameport_set_port_data(gp, r);
*legacy |= VIA_FUNC_ENABLE_GAME;
pci_write_config_byte(chip->pci, VIA_FUNC_ENABLE, *legacy);
gameport_register_port(chip->gameport);
return 0;
}
static void snd_via686_free_gameport(struct via82xx *chip)
{
if (chip->gameport) {
struct resource *r = gameport_get_port_data(chip->gameport);
gameport_unregister_port(chip->gameport);
chip->gameport = NULL;
release_and_free_resource(r);
}
}
static inline int snd_via686_create_gameport(struct via82xx *chip, unsigned char *legacy)
{
return -ENOSYS;
}
static inline void snd_via686_free_gameport(struct via82xx *chip) { }
static int snd_via8233_init_misc(struct via82xx *chip)
{
int i, err, caps;
unsigned char val;
caps = chip->chip_type == TYPE_VIA8233A ? 1 : 2;
for (i = 0; i < caps; i++) {
snd_via8233_capture_source.index = i;
err = snd_ctl_add(chip->card, snd_ctl_new1(&snd_via8233_capture_source, chip));
if (err < 0)
return err;
}
if (ac97_can_spdif(chip->ac97)) {
err = snd_ctl_add(chip->card, snd_ctl_new1(&snd_via8233_dxs3_spdif_control, chip));
if (err < 0)
return err;
}
if (chip->chip_type != TYPE_VIA8233A) {
struct snd_ctl_elem_id sid;
memset(&sid, 0, sizeof(sid));
strcpy(sid.name, "PCM Playback Volume");
sid.iface = SNDRV_CTL_ELEM_IFACE_MIXER;
if (! snd_ctl_find_id(chip->card, &sid)) {
dev_info(chip->card->dev,
"Using DXS as PCM Playback\n");
err = snd_ctl_add(chip->card, snd_ctl_new1(&snd_via8233_pcmdxs_volume_control, chip));
if (err < 0)
return err;
}
else
{
for (i = 0; i < 4; ++i) {
struct snd_kcontrol *kctl;
kctl = snd_ctl_new1(
&snd_via8233_dxs_volume_control, chip);
if (!kctl)
return -ENOMEM;
kctl->id.subdevice = i;
err = snd_ctl_add(chip->card, kctl);
if (err < 0)
return err;
chip->dxs_controls[i] = kctl;
}
}
}
pci_read_config_byte(chip->pci, VIA8233_SPDIF_CTRL, &val);
val = (val & ~VIA8233_SPDIF_SLOT_MASK) | VIA8233_SPDIF_SLOT_1011;
val &= ~VIA8233_SPDIF_DX3;
pci_write_config_byte(chip->pci, VIA8233_SPDIF_CTRL, val);
return 0;
}
static int snd_via686_init_misc(struct via82xx *chip)
{
unsigned char legacy, legacy_cfg;
int rev_h = 0;
legacy = chip->old_legacy;
legacy_cfg = chip->old_legacy_cfg;
legacy |= VIA_FUNC_MIDI_IRQMASK;
legacy &= ~VIA_FUNC_ENABLE_GAME;
if (chip->revision >= VIA_REV_686_H) {
rev_h = 1;
if (mpu_port >= 0x200) {
mpu_port &= 0xfffc;
pci_write_config_dword(chip->pci, 0x18, mpu_port | 0x01);
#ifdef CONFIG_PM_SLEEP
chip->mpu_port_saved = mpu_port;
#endif
} else {
mpu_port = pci_resource_start(chip->pci, 2);
}
} else {
switch (mpu_port) {
case 0x300:
case 0x310:
case 0x320:
case 0x330:
legacy_cfg &= ~(3 << 2);
legacy_cfg |= (mpu_port & 0x0030) >> 2;
break;
default:
if (legacy & VIA_FUNC_ENABLE_MIDI)
mpu_port = 0x300 + ((legacy_cfg & 0x000c) << 2);
break;
}
}
if (mpu_port >= 0x200 &&
(chip->mpu_res = request_region(mpu_port, 2, "VIA82xx MPU401"))
!= NULL) {
if (rev_h)
legacy |= VIA_FUNC_MIDI_PNP;
legacy |= VIA_FUNC_ENABLE_MIDI;
} else {
if (rev_h)
legacy &= ~VIA_FUNC_MIDI_PNP;
legacy &= ~VIA_FUNC_ENABLE_MIDI;
mpu_port = 0;
}
pci_write_config_byte(chip->pci, VIA_FUNC_ENABLE, legacy);
pci_write_config_byte(chip->pci, VIA_PNP_CONTROL, legacy_cfg);
if (chip->mpu_res) {
if (snd_mpu401_uart_new(chip->card, 0, MPU401_HW_VIA686A,
mpu_port, MPU401_INFO_INTEGRATED |
MPU401_INFO_IRQ_HOOK, -1,
&chip->rmidi) < 0) {
dev_warn(chip->card->dev,
"unable to initialize MPU-401 at 0x%lx, skipping\n",
mpu_port);
legacy &= ~VIA_FUNC_ENABLE_MIDI;
} else {
legacy &= ~VIA_FUNC_MIDI_IRQMASK;
}
pci_write_config_byte(chip->pci, VIA_FUNC_ENABLE, legacy);
}
snd_via686_create_gameport(chip, &legacy);
#ifdef CONFIG_PM_SLEEP
chip->legacy_saved = legacy;
chip->legacy_cfg_saved = legacy_cfg;
#endif
return 0;
}
static void snd_via82xx_proc_read(struct snd_info_entry *entry,
struct snd_info_buffer *buffer)
{
struct via82xx *chip = entry->private_data;
int i;
snd_iprintf(buffer, "%s\n\n", chip->card->longname);
for (i = 0; i < 0xa0; i += 4) {
snd_iprintf(buffer, "%02x: %08x\n", i, inl(chip->port + i));
}
}
static void snd_via82xx_proc_init(struct via82xx *chip)
{
struct snd_info_entry *entry;
if (! snd_card_proc_new(chip->card, "via82xx", &entry))
snd_info_set_text_ops(entry, chip, snd_via82xx_proc_read);
}
static int snd_via82xx_chip_init(struct via82xx *chip)
{
unsigned int val;
unsigned long end_time;
unsigned char pval;
#if 0
if (chip->chip_type == TYPE_VIA686)
pci_write_config_byte(chip->pci, VIA_FUNC_ENABLE, 0);
#endif
pci_read_config_byte(chip->pci, VIA_ACLINK_STAT, &pval);
if (! (pval & VIA_ACLINK_C00_READY)) {
pci_write_config_byte(chip->pci, VIA_ACLINK_CTRL,
VIA_ACLINK_CTRL_ENABLE |
VIA_ACLINK_CTRL_RESET |
VIA_ACLINK_CTRL_SYNC);
udelay(100);
#if 1
pci_write_config_byte(chip->pci, VIA_ACLINK_CTRL, 0x00);
udelay(100);
#else
pci_write_config_byte(chip->pci, VIA_ACLINK_CTRL,
VIA_ACLINK_CTRL_RESET|VIA_ACLINK_CTRL_SYNC);
udelay(2);
#endif
pci_write_config_byte(chip->pci, VIA_ACLINK_CTRL, VIA_ACLINK_CTRL_INIT);
udelay(100);
}
pci_read_config_byte(chip->pci, VIA_ACLINK_CTRL, &pval);
if ((pval & VIA_ACLINK_CTRL_INIT) != VIA_ACLINK_CTRL_INIT) {
pci_write_config_byte(chip->pci, VIA_ACLINK_CTRL, VIA_ACLINK_CTRL_INIT);
udelay(100);
}
end_time = jiffies + msecs_to_jiffies(750);
do {
pci_read_config_byte(chip->pci, VIA_ACLINK_STAT, &pval);
if (pval & VIA_ACLINK_C00_READY)
break;
schedule_timeout_uninterruptible(1);
} while (time_before(jiffies, end_time));
if ((val = snd_via82xx_codec_xread(chip)) & VIA_REG_AC97_BUSY)
dev_err(chip->card->dev,
"AC'97 codec is not ready [0x%x]\n", val);
#if 0
snd_via82xx_codec_xwrite(chip, VIA_REG_AC97_READ |
VIA_REG_AC97_SECONDARY_VALID |
(VIA_REG_AC97_CODEC_ID_SECONDARY << VIA_REG_AC97_CODEC_ID_SHIFT));
end_time = jiffies + msecs_to_jiffies(750);
snd_via82xx_codec_xwrite(chip, VIA_REG_AC97_READ |
VIA_REG_AC97_SECONDARY_VALID |
(VIA_REG_AC97_CODEC_ID_SECONDARY << VIA_REG_AC97_CODEC_ID_SHIFT));
do {
if ((val = snd_via82xx_codec_xread(chip)) & VIA_REG_AC97_SECONDARY_VALID) {
chip->ac97_secondary = 1;
goto __ac97_ok2;
}
schedule_timeout_uninterruptible(1);
} while (time_before(jiffies, end_time));
__ac97_ok2:
#endif
if (chip->chip_type == TYPE_VIA686) {
pci_write_config_byte(chip->pci, VIA_FM_NMI_CTRL, 0);
outl(0, VIAREG(chip, GPI_INTR));
}
if (chip->chip_type != TYPE_VIA686) {
struct pci_dev *pci;
pci = pci_get_device(0x1106, 0x3068, NULL);
if (pci) {
unsigned char data;
pci_read_config_byte(pci, 0x44, &data);
pci_write_config_byte(pci, 0x44, data | 0x40);
pci_dev_put(pci);
}
}
if (chip->chip_type != TYPE_VIA8233A) {
int i, idx;
for (idx = 0; idx < 4; idx++) {
unsigned long port = chip->port + 0x10 * idx;
for (i = 0; i < 2; i++) {
chip->playback_volume[idx][i]=chip->playback_volume_c[i];
outb(chip->playback_volume_c[i],
port + VIA_REG_OFS_PLAYBACK_VOLUME_L + i);
}
}
}
return 0;
}
static int snd_via82xx_suspend(struct device *dev)
{
struct pci_dev *pci = to_pci_dev(dev);
struct snd_card *card = dev_get_drvdata(dev);
struct via82xx *chip = card->private_data;
int i;
snd_power_change_state(card, SNDRV_CTL_POWER_D3hot);
for (i = 0; i < 2; i++)
snd_pcm_suspend_all(chip->pcms[i]);
for (i = 0; i < chip->num_devs; i++)
snd_via82xx_channel_reset(chip, &chip->devs[i]);
synchronize_irq(chip->irq);
snd_ac97_suspend(chip->ac97);
if (chip->chip_type != TYPE_VIA686) {
pci_read_config_byte(chip->pci, VIA8233_SPDIF_CTRL, &chip->spdif_ctrl_saved);
chip->capture_src_saved[0] = inb(chip->port + VIA_REG_CAPTURE_CHANNEL);
chip->capture_src_saved[1] = inb(chip->port + VIA_REG_CAPTURE_CHANNEL + 0x10);
}
pci_disable_device(pci);
pci_save_state(pci);
pci_set_power_state(pci, PCI_D3hot);
return 0;
}
static int snd_via82xx_resume(struct device *dev)
{
struct pci_dev *pci = to_pci_dev(dev);
struct snd_card *card = dev_get_drvdata(dev);
struct via82xx *chip = card->private_data;
int i;
pci_set_power_state(pci, PCI_D0);
pci_restore_state(pci);
if (pci_enable_device(pci) < 0) {
dev_err(dev, "pci_enable_device failed, disabling device\n");
snd_card_disconnect(card);
return -EIO;
}
pci_set_master(pci);
snd_via82xx_chip_init(chip);
if (chip->chip_type == TYPE_VIA686) {
if (chip->mpu_port_saved)
pci_write_config_dword(chip->pci, 0x18, chip->mpu_port_saved | 0x01);
pci_write_config_byte(chip->pci, VIA_FUNC_ENABLE, chip->legacy_saved);
pci_write_config_byte(chip->pci, VIA_PNP_CONTROL, chip->legacy_cfg_saved);
} else {
pci_write_config_byte(chip->pci, VIA8233_SPDIF_CTRL, chip->spdif_ctrl_saved);
outb(chip->capture_src_saved[0], chip->port + VIA_REG_CAPTURE_CHANNEL);
outb(chip->capture_src_saved[1], chip->port + VIA_REG_CAPTURE_CHANNEL + 0x10);
}
snd_ac97_resume(chip->ac97);
for (i = 0; i < chip->num_devs; i++)
snd_via82xx_channel_reset(chip, &chip->devs[i]);
snd_power_change_state(card, SNDRV_CTL_POWER_D0);
return 0;
}
static int snd_via82xx_free(struct via82xx *chip)
{
unsigned int i;
if (chip->irq < 0)
goto __end_hw;
for (i = 0; i < chip->num_devs; i++)
snd_via82xx_channel_reset(chip, &chip->devs[i]);
if (chip->irq >= 0)
free_irq(chip->irq, chip);
__end_hw:
release_and_free_resource(chip->mpu_res);
pci_release_regions(chip->pci);
if (chip->chip_type == TYPE_VIA686) {
snd_via686_free_gameport(chip);
pci_write_config_byte(chip->pci, VIA_FUNC_ENABLE, chip->old_legacy);
pci_write_config_byte(chip->pci, VIA_PNP_CONTROL, chip->old_legacy_cfg);
}
pci_disable_device(chip->pci);
kfree(chip);
return 0;
}
static int snd_via82xx_dev_free(struct snd_device *device)
{
struct via82xx *chip = device->device_data;
return snd_via82xx_free(chip);
}
static int snd_via82xx_create(struct snd_card *card,
struct pci_dev *pci,
int chip_type,
int revision,
unsigned int ac97_clock,
struct via82xx **r_via)
{
struct via82xx *chip;
int err;
static struct snd_device_ops ops = {
.dev_free = snd_via82xx_dev_free,
};
if ((err = pci_enable_device(pci)) < 0)
return err;
if ((chip = kzalloc(sizeof(*chip), GFP_KERNEL)) == NULL) {
pci_disable_device(pci);
return -ENOMEM;
}
chip->chip_type = chip_type;
chip->revision = revision;
spin_lock_init(&chip->reg_lock);
spin_lock_init(&chip->rates[0].lock);
spin_lock_init(&chip->rates[1].lock);
chip->card = card;
chip->pci = pci;
chip->irq = -1;
pci_read_config_byte(pci, VIA_FUNC_ENABLE, &chip->old_legacy);
pci_read_config_byte(pci, VIA_PNP_CONTROL, &chip->old_legacy_cfg);
pci_write_config_byte(chip->pci, VIA_FUNC_ENABLE,
chip->old_legacy & ~(VIA_FUNC_ENABLE_SB|VIA_FUNC_ENABLE_FM));
if ((err = pci_request_regions(pci, card->driver)) < 0) {
kfree(chip);
pci_disable_device(pci);
return err;
}
chip->port = pci_resource_start(pci, 0);
if (request_irq(pci->irq,
chip_type == TYPE_VIA8233 ?
snd_via8233_interrupt : snd_via686_interrupt,
IRQF_SHARED,
KBUILD_MODNAME, chip)) {
dev_err(card->dev, "unable to grab IRQ %d\n", pci->irq);
snd_via82xx_free(chip);
return -EBUSY;
}
chip->irq = pci->irq;
if (ac97_clock >= 8000 && ac97_clock <= 48000)
chip->ac97_clock = ac97_clock;
synchronize_irq(chip->irq);
if ((err = snd_via82xx_chip_init(chip)) < 0) {
snd_via82xx_free(chip);
return err;
}
if ((err = snd_device_new(card, SNDRV_DEV_LOWLEVEL, chip, &ops)) < 0) {
snd_via82xx_free(chip);
return err;
}
pci_set_master(pci);
*r_via = chip;
return 0;
}
static int check_dxs_list(struct pci_dev *pci, int revision)
{
const struct snd_pci_quirk *w;
w = snd_pci_quirk_lookup(pci, dxs_whitelist);
if (w) {
dev_dbg(&pci->dev, "DXS white list for %s found\n",
snd_pci_quirk_name(w));
return w->value;
}
if (revision >= VIA_REV_8235)
return VIA_DXS_SRC;
dev_info(&pci->dev, "Assuming DXS channels with 48k fixed sample rate.\n");
dev_info(&pci->dev, " Please try dxs_support=5 option\n");
dev_info(&pci->dev, " and report if it works on your machine.\n");
dev_info(&pci->dev, " For more details, read ALSA-Configuration.txt.\n");
return VIA_DXS_48K;
}
static int snd_via82xx_probe(struct pci_dev *pci,
const struct pci_device_id *pci_id)
{
struct snd_card *card;
struct via82xx *chip;
int chip_type = 0, card_type;
unsigned int i;
int err;
err = snd_card_new(&pci->dev, index, id, THIS_MODULE, 0, &card);
if (err < 0)
return err;
card_type = pci_id->driver_data;
switch (card_type) {
case TYPE_CARD_VIA686:
strcpy(card->driver, "VIA686A");
sprintf(card->shortname, "VIA 82C686A/B rev%x", pci->revision);
chip_type = TYPE_VIA686;
break;
case TYPE_CARD_VIA8233:
chip_type = TYPE_VIA8233;
sprintf(card->shortname, "VIA 823x rev%x", pci->revision);
for (i = 0; i < ARRAY_SIZE(via823x_cards); i++) {
if (pci->revision == via823x_cards[i].revision) {
chip_type = via823x_cards[i].type;
strcpy(card->shortname, via823x_cards[i].name);
break;
}
}
if (chip_type != TYPE_VIA8233A) {
if (dxs_support == VIA_DXS_AUTO)
dxs_support = check_dxs_list(pci, pci->revision);
if (dxs_support == VIA_DXS_DISABLE)
chip_type = TYPE_VIA8233A;
else
chip_type = TYPE_VIA8233;
}
if (chip_type == TYPE_VIA8233A)
strcpy(card->driver, "VIA8233A");
else if (pci->revision >= VIA_REV_8237)
strcpy(card->driver, "VIA8237");
else
strcpy(card->driver, "VIA8233");
break;
default:
dev_err(card->dev, "invalid card type %d\n", card_type);
err = -EINVAL;
goto __error;
}
if ((err = snd_via82xx_create(card, pci, chip_type, pci->revision,
ac97_clock, &chip)) < 0)
goto __error;
card->private_data = chip;
if ((err = snd_via82xx_mixer_new(chip, ac97_quirk)) < 0)
goto __error;
if (chip_type == TYPE_VIA686) {
if ((err = snd_via686_pcm_new(chip)) < 0 ||
(err = snd_via686_init_misc(chip)) < 0)
goto __error;
} else {
if (chip_type == TYPE_VIA8233A) {
if ((err = snd_via8233a_pcm_new(chip)) < 0)
goto __error;
} else {
if ((err = snd_via8233_pcm_new(chip)) < 0)
goto __error;
if (dxs_support == VIA_DXS_48K)
chip->dxs_fixed = 1;
else if (dxs_support == VIA_DXS_NO_VRA)
chip->no_vra = 1;
else if (dxs_support == VIA_DXS_SRC) {
chip->no_vra = 1;
chip->dxs_src = 1;
}
}
if ((err = snd_via8233_init_misc(chip)) < 0)
goto __error;
}
for (i = 0; i < chip->num_devs; i++)
snd_via82xx_channel_reset(chip, &chip->devs[i]);
snprintf(card->longname, sizeof(card->longname),
"%s with %s at %#lx, irq %d", card->shortname,
snd_ac97_get_short_name(chip->ac97), chip->port, chip->irq);
snd_via82xx_proc_init(chip);
if ((err = snd_card_register(card)) < 0) {
snd_card_free(card);
return err;
}
pci_set_drvdata(pci, card);
return 0;
__error:
snd_card_free(card);
return err;
}
static void snd_via82xx_remove(struct pci_dev *pci)
{
snd_card_free(pci_get_drvdata(pci));
}
