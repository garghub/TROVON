static void snd_es1938_mixer_write(struct es1938 *chip, unsigned char reg, unsigned char val)
{
unsigned long flags;
spin_lock_irqsave(&chip->mixer_lock, flags);
outb(reg, SLSB_REG(chip, MIXERADDR));
outb(val, SLSB_REG(chip, MIXERDATA));
spin_unlock_irqrestore(&chip->mixer_lock, flags);
#ifdef REG_DEBUG
snd_printk(KERN_DEBUG "Mixer reg %02x set to %02x\n", reg, val);
#endif
}
static int snd_es1938_mixer_read(struct es1938 *chip, unsigned char reg)
{
int data;
unsigned long flags;
spin_lock_irqsave(&chip->mixer_lock, flags);
outb(reg, SLSB_REG(chip, MIXERADDR));
data = inb(SLSB_REG(chip, MIXERDATA));
spin_unlock_irqrestore(&chip->mixer_lock, flags);
#ifdef REG_DEBUG
snd_printk(KERN_DEBUG "Mixer reg %02x now is %02x\n", reg, data);
#endif
return data;
}
static int snd_es1938_mixer_bits(struct es1938 *chip, unsigned char reg,
unsigned char mask, unsigned char val)
{
unsigned long flags;
unsigned char old, new, oval;
spin_lock_irqsave(&chip->mixer_lock, flags);
outb(reg, SLSB_REG(chip, MIXERADDR));
old = inb(SLSB_REG(chip, MIXERDATA));
oval = old & mask;
if (val != oval) {
new = (old & ~mask) | (val & mask);
outb(new, SLSB_REG(chip, MIXERDATA));
#ifdef REG_DEBUG
snd_printk(KERN_DEBUG "Mixer reg %02x was %02x, set to %02x\n",
reg, old, new);
#endif
}
spin_unlock_irqrestore(&chip->mixer_lock, flags);
return oval;
}
static void snd_es1938_write_cmd(struct es1938 *chip, unsigned char cmd)
{
int i;
unsigned char v;
for (i = 0; i < WRITE_LOOP_TIMEOUT; i++) {
if (!(v = inb(SLSB_REG(chip, READSTATUS)) & 0x80)) {
outb(cmd, SLSB_REG(chip, WRITEDATA));
return;
}
}
printk(KERN_ERR "snd_es1938_write_cmd timeout (0x02%x/0x02%x)\n", cmd, v);
}
static int snd_es1938_get_byte(struct es1938 *chip)
{
int i;
unsigned char v;
for (i = GET_LOOP_TIMEOUT; i; i--)
if ((v = inb(SLSB_REG(chip, STATUS))) & 0x80)
return inb(SLSB_REG(chip, READDATA));
snd_printk(KERN_ERR "get_byte timeout: status 0x02%x\n", v);
return -ENODEV;
}
static void snd_es1938_write(struct es1938 *chip, unsigned char reg, unsigned char val)
{
unsigned long flags;
spin_lock_irqsave(&chip->reg_lock, flags);
snd_es1938_write_cmd(chip, reg);
snd_es1938_write_cmd(chip, val);
spin_unlock_irqrestore(&chip->reg_lock, flags);
#ifdef REG_DEBUG
snd_printk(KERN_DEBUG "Reg %02x set to %02x\n", reg, val);
#endif
}
static unsigned char snd_es1938_read(struct es1938 *chip, unsigned char reg)
{
unsigned char val;
unsigned long flags;
spin_lock_irqsave(&chip->reg_lock, flags);
snd_es1938_write_cmd(chip, ESS_CMD_READREG);
snd_es1938_write_cmd(chip, reg);
val = snd_es1938_get_byte(chip);
spin_unlock_irqrestore(&chip->reg_lock, flags);
#ifdef REG_DEBUG
snd_printk(KERN_DEBUG "Reg %02x now is %02x\n", reg, val);
#endif
return val;
}
static int snd_es1938_bits(struct es1938 *chip, unsigned char reg, unsigned char mask,
unsigned char val)
{
unsigned long flags;
unsigned char old, new, oval;
spin_lock_irqsave(&chip->reg_lock, flags);
snd_es1938_write_cmd(chip, ESS_CMD_READREG);
snd_es1938_write_cmd(chip, reg);
old = snd_es1938_get_byte(chip);
oval = old & mask;
if (val != oval) {
snd_es1938_write_cmd(chip, reg);
new = (old & ~mask) | (val & mask);
snd_es1938_write_cmd(chip, new);
#ifdef REG_DEBUG
snd_printk(KERN_DEBUG "Reg %02x was %02x, set to %02x\n",
reg, old, new);
#endif
}
spin_unlock_irqrestore(&chip->reg_lock, flags);
return oval;
}
static void snd_es1938_reset(struct es1938 *chip)
{
int i;
outb(3, SLSB_REG(chip, RESET));
inb(SLSB_REG(chip, RESET));
outb(0, SLSB_REG(chip, RESET));
for (i = 0; i < RESET_LOOP_TIMEOUT; i++) {
if (inb(SLSB_REG(chip, STATUS)) & 0x80) {
if (inb(SLSB_REG(chip, READDATA)) == 0xaa)
goto __next;
}
}
snd_printk(KERN_ERR "ESS Solo-1 reset failed\n");
__next:
snd_es1938_write_cmd(chip, ESS_CMD_ENABLEEXT);
snd_es1938_write(chip, ESS_CMD_DMATYPE, 2);
snd_es1938_mixer_write(chip, ESSSB_IREG_AUDIO2MODE, 0x32);
snd_es1938_bits(chip, ESS_CMD_IRQCONTROL, 0xf0, 0x50);
snd_es1938_bits(chip, ESS_CMD_DRQCONTROL, 0xf0, 0x50);
snd_es1938_write_cmd(chip, ESS_CMD_ENABLEAUDIO1);
snd_es1938_mixer_write(chip, 0x54, 0x8f);
snd_es1938_mixer_write(chip, 0x56, 0x95);
snd_es1938_mixer_write(chip, 0x58, 0x94);
snd_es1938_mixer_write(chip, 0x5a, 0x80);
}
static void snd_es1938_reset_fifo(struct es1938 *chip)
{
outb(2, SLSB_REG(chip, RESET));
outb(0, SLSB_REG(chip, RESET));
}
static void snd_es1938_rate_set(struct es1938 *chip,
struct snd_pcm_substream *substream,
int mode)
{
unsigned int bits, div0;
struct snd_pcm_runtime *runtime = substream->runtime;
if (runtime->rate_num == clocks[0].num)
bits = 128 - runtime->rate_den;
else
bits = 256 - runtime->rate_den;
div0 = 256 - 7160000*20/(8*82*runtime->rate);
if (mode == DAC2) {
snd_es1938_mixer_write(chip, 0x70, bits);
snd_es1938_mixer_write(chip, 0x72, div0);
} else {
snd_es1938_write(chip, 0xA1, bits);
snd_es1938_write(chip, 0xA2, div0);
}
}
static void snd_es1938_playback1_setdma(struct es1938 *chip)
{
outb(0x00, SLIO_REG(chip, AUDIO2MODE));
outl(chip->dma2_start, SLIO_REG(chip, AUDIO2DMAADDR));
outw(0, SLIO_REG(chip, AUDIO2DMACOUNT));
outw(chip->dma2_size, SLIO_REG(chip, AUDIO2DMACOUNT));
}
static void snd_es1938_playback2_setdma(struct es1938 *chip)
{
outb(0xc4, SLDM_REG(chip, DMACOMMAND));
outb(0, SLDM_REG(chip, DMACLEAR));
outb(1, SLDM_REG(chip, DMAMASK));
outb(0x18, SLDM_REG(chip, DMAMODE));
outl(chip->dma1_start, SLDM_REG(chip, DMAADDR));
outw(chip->dma1_size - 1, SLDM_REG(chip, DMACOUNT));
outb(0, SLDM_REG(chip, DMAMASK));
}
static void snd_es1938_capture_setdma(struct es1938 *chip)
{
outb(0xc4, SLDM_REG(chip, DMACOMMAND));
outb(0, SLDM_REG(chip, DMACLEAR));
outb(1, SLDM_REG(chip, DMAMASK));
outb(0x14, SLDM_REG(chip, DMAMODE));
outl(chip->dma1_start, SLDM_REG(chip, DMAADDR));
chip->last_capture_dmaaddr = chip->dma1_start;
outw(chip->dma1_size - 1, SLDM_REG(chip, DMACOUNT));
outb(0, SLDM_REG(chip, DMAMASK));
}
static int snd_es1938_capture_trigger(struct snd_pcm_substream *substream,
int cmd)
{
struct es1938 *chip = snd_pcm_substream_chip(substream);
int val;
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
case SNDRV_PCM_TRIGGER_RESUME:
val = 0x0f;
chip->active |= ADC1;
break;
case SNDRV_PCM_TRIGGER_STOP:
case SNDRV_PCM_TRIGGER_SUSPEND:
val = 0x00;
chip->active &= ~ADC1;
break;
default:
return -EINVAL;
}
snd_es1938_write(chip, ESS_CMD_DMACONTROL, val);
return 0;
}
static int snd_es1938_playback1_trigger(struct snd_pcm_substream *substream,
int cmd)
{
struct es1938 *chip = snd_pcm_substream_chip(substream);
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
case SNDRV_PCM_TRIGGER_RESUME:
snd_es1938_mixer_write(chip, ESSSB_IREG_AUDIO2CONTROL1, 0x92);
udelay(10);
snd_es1938_mixer_write(chip, ESSSB_IREG_AUDIO2CONTROL1, 0x93);
outb(0x0a, SLIO_REG(chip, AUDIO2MODE));
chip->active |= DAC2;
break;
case SNDRV_PCM_TRIGGER_STOP:
case SNDRV_PCM_TRIGGER_SUSPEND:
outb(0, SLIO_REG(chip, AUDIO2MODE));
snd_es1938_mixer_write(chip, ESSSB_IREG_AUDIO2CONTROL1, 0);
chip->active &= ~DAC2;
break;
default:
return -EINVAL;
}
return 0;
}
static int snd_es1938_playback2_trigger(struct snd_pcm_substream *substream,
int cmd)
{
struct es1938 *chip = snd_pcm_substream_chip(substream);
int val;
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
case SNDRV_PCM_TRIGGER_RESUME:
val = 5;
chip->active |= DAC1;
break;
case SNDRV_PCM_TRIGGER_STOP:
case SNDRV_PCM_TRIGGER_SUSPEND:
val = 0;
chip->active &= ~DAC1;
break;
default:
return -EINVAL;
}
snd_es1938_write(chip, ESS_CMD_DMACONTROL, val);
return 0;
}
static int snd_es1938_playback_trigger(struct snd_pcm_substream *substream,
int cmd)
{
switch (substream->number) {
case 0:
return snd_es1938_playback1_trigger(substream, cmd);
case 1:
return snd_es1938_playback2_trigger(substream, cmd);
}
snd_BUG();
return -EINVAL;
}
static int snd_es1938_capture_prepare(struct snd_pcm_substream *substream)
{
struct es1938 *chip = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
int u, is8, mono;
unsigned int size = snd_pcm_lib_buffer_bytes(substream);
unsigned int count = snd_pcm_lib_period_bytes(substream);
chip->dma1_size = size;
chip->dma1_start = runtime->dma_addr;
mono = (runtime->channels > 1) ? 0 : 1;
is8 = snd_pcm_format_width(runtime->format) == 16 ? 0 : 1;
u = snd_pcm_format_unsigned(runtime->format);
chip->dma1_shift = 2 - mono - is8;
snd_es1938_reset_fifo(chip);
snd_es1938_bits(chip, ESS_CMD_ANALOGCONTROL, 0x03, (mono ? 2 : 1));
snd_es1938_rate_set(chip, substream, ADC1);
count = 0x10000 - count;
snd_es1938_write(chip, ESS_CMD_DMACNTRELOADL, count & 0xff);
snd_es1938_write(chip, ESS_CMD_DMACNTRELOADH, count >> 8);
snd_es1938_write(chip, ESS_CMD_SETFORMAT2, u ? 0x51 : 0x71);
snd_es1938_write(chip, ESS_CMD_SETFORMAT2, 0x90 |
(u ? 0x00 : 0x20) |
(is8 ? 0x00 : 0x04) |
(mono ? 0x40 : 0x08));
snd_es1938_capture_setdma(chip);
return 0;
}
static int snd_es1938_playback1_prepare(struct snd_pcm_substream *substream)
{
struct es1938 *chip = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
int u, is8, mono;
unsigned int size = snd_pcm_lib_buffer_bytes(substream);
unsigned int count = snd_pcm_lib_period_bytes(substream);
chip->dma2_size = size;
chip->dma2_start = runtime->dma_addr;
mono = (runtime->channels > 1) ? 0 : 1;
is8 = snd_pcm_format_width(runtime->format) == 16 ? 0 : 1;
u = snd_pcm_format_unsigned(runtime->format);
chip->dma2_shift = 2 - mono - is8;
snd_es1938_reset_fifo(chip);
snd_es1938_rate_set(chip, substream, DAC2);
count >>= 1;
count = 0x10000 - count;
snd_es1938_mixer_write(chip, ESSSB_IREG_AUDIO2TCOUNTL, count & 0xff);
snd_es1938_mixer_write(chip, ESSSB_IREG_AUDIO2TCOUNTH, count >> 8);
snd_es1938_mixer_write(chip, ESSSB_IREG_AUDIO2CONTROL2, 0x40 | (u ? 0 : 4) |
(mono ? 0 : 2) | (is8 ? 0 : 1));
snd_es1938_playback1_setdma(chip);
return 0;
}
static int snd_es1938_playback2_prepare(struct snd_pcm_substream *substream)
{
struct es1938 *chip = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
int u, is8, mono;
unsigned int size = snd_pcm_lib_buffer_bytes(substream);
unsigned int count = snd_pcm_lib_period_bytes(substream);
chip->dma1_size = size;
chip->dma1_start = runtime->dma_addr;
mono = (runtime->channels > 1) ? 0 : 1;
is8 = snd_pcm_format_width(runtime->format) == 16 ? 0 : 1;
u = snd_pcm_format_unsigned(runtime->format);
chip->dma1_shift = 2 - mono - is8;
count = 0x10000 - count;
snd_es1938_reset_fifo(chip);
snd_es1938_bits(chip, ESS_CMD_ANALOGCONTROL, 0x03, (mono ? 2 : 1));
snd_es1938_rate_set(chip, substream, DAC1);
snd_es1938_write(chip, ESS_CMD_DMACNTRELOADL, count & 0xff);
snd_es1938_write(chip, ESS_CMD_DMACNTRELOADH, count >> 8);
snd_es1938_write(chip, ESS_CMD_SETFORMAT, u ? 0x80 : 0x00);
snd_es1938_write(chip, ESS_CMD_SETFORMAT, u ? 0x51 : 0x71);
snd_es1938_write(chip, ESS_CMD_SETFORMAT2,
0x90 | (mono ? 0x40 : 0x08) |
(is8 ? 0x00 : 0x04) | (u ? 0x00 : 0x20));
snd_es1938_playback2_setdma(chip);
return 0;
}
static int snd_es1938_playback_prepare(struct snd_pcm_substream *substream)
{
switch (substream->number) {
case 0:
return snd_es1938_playback1_prepare(substream);
case 1:
return snd_es1938_playback2_prepare(substream);
}
snd_BUG();
return -EINVAL;
}
static snd_pcm_uframes_t snd_es1938_capture_pointer(struct snd_pcm_substream *substream)
{
struct es1938 *chip = snd_pcm_substream_chip(substream);
size_t ptr;
#if 0
size_t old, new;
old = inw(SLDM_REG(chip, DMACOUNT));
while ((new = inw(SLDM_REG(chip, DMACOUNT))) != old)
old = new;
ptr = chip->dma1_size - 1 - new;
#else
size_t count;
unsigned int diff;
ptr = inl(SLDM_REG(chip, DMAADDR));
count = inw(SLDM_REG(chip, DMACOUNT));
diff = chip->dma1_start + chip->dma1_size - ptr - count;
if (diff > 3 || ptr < chip->dma1_start
|| ptr >= chip->dma1_start+chip->dma1_size)
ptr = chip->last_capture_dmaaddr;
else
chip->last_capture_dmaaddr = ptr;
ptr -= chip->dma1_start;
#endif
return ptr >> chip->dma1_shift;
}
static snd_pcm_uframes_t snd_es1938_playback1_pointer(struct snd_pcm_substream *substream)
{
struct es1938 *chip = snd_pcm_substream_chip(substream);
size_t ptr;
#if 1
ptr = chip->dma2_size - inw(SLIO_REG(chip, AUDIO2DMACOUNT));
#else
ptr = inl(SLIO_REG(chip, AUDIO2DMAADDR)) - chip->dma2_start;
#endif
return ptr >> chip->dma2_shift;
}
static snd_pcm_uframes_t snd_es1938_playback2_pointer(struct snd_pcm_substream *substream)
{
struct es1938 *chip = snd_pcm_substream_chip(substream);
size_t ptr;
size_t old, new;
#if 1
old = inw(SLDM_REG(chip, DMACOUNT));
while ((new = inw(SLDM_REG(chip, DMACOUNT))) != old)
old = new;
ptr = chip->dma1_size - 1 - new;
#else
ptr = inl(SLDM_REG(chip, DMAADDR)) - chip->dma1_start;
#endif
return ptr >> chip->dma1_shift;
}
static snd_pcm_uframes_t snd_es1938_playback_pointer(struct snd_pcm_substream *substream)
{
switch (substream->number) {
case 0:
return snd_es1938_playback1_pointer(substream);
case 1:
return snd_es1938_playback2_pointer(substream);
}
snd_BUG();
return -EINVAL;
}
static int snd_es1938_capture_copy(struct snd_pcm_substream *substream,
int channel,
snd_pcm_uframes_t pos,
void __user *dst,
snd_pcm_uframes_t count)
{
struct snd_pcm_runtime *runtime = substream->runtime;
struct es1938 *chip = snd_pcm_substream_chip(substream);
pos <<= chip->dma1_shift;
count <<= chip->dma1_shift;
if (snd_BUG_ON(pos + count > chip->dma1_size))
return -EINVAL;
if (pos + count < chip->dma1_size) {
if (copy_to_user(dst, runtime->dma_area + pos + 1, count))
return -EFAULT;
} else {
if (copy_to_user(dst, runtime->dma_area + pos + 1, count - 1))
return -EFAULT;
if (put_user(runtime->dma_area[0], ((unsigned char __user *)dst) + count - 1))
return -EFAULT;
}
return 0;
}
static int snd_es1938_pcm_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *hw_params)
{
int err;
if ((err = snd_pcm_lib_malloc_pages(substream, params_buffer_bytes(hw_params))) < 0)
return err;
return 0;
}
static int snd_es1938_pcm_hw_free(struct snd_pcm_substream *substream)
{
return snd_pcm_lib_free_pages(substream);
}
static int snd_es1938_capture_open(struct snd_pcm_substream *substream)
{
struct es1938 *chip = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
if (chip->playback2_substream)
return -EAGAIN;
chip->capture_substream = substream;
runtime->hw = snd_es1938_capture;
snd_pcm_hw_constraint_ratnums(runtime, 0, SNDRV_PCM_HW_PARAM_RATE,
&hw_constraints_clocks);
snd_pcm_hw_constraint_minmax(runtime, SNDRV_PCM_HW_PARAM_BUFFER_BYTES, 0, 0xff00);
return 0;
}
static int snd_es1938_playback_open(struct snd_pcm_substream *substream)
{
struct es1938 *chip = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
switch (substream->number) {
case 0:
chip->playback1_substream = substream;
break;
case 1:
if (chip->capture_substream)
return -EAGAIN;
chip->playback2_substream = substream;
break;
default:
snd_BUG();
return -EINVAL;
}
runtime->hw = snd_es1938_playback;
snd_pcm_hw_constraint_ratnums(runtime, 0, SNDRV_PCM_HW_PARAM_RATE,
&hw_constraints_clocks);
snd_pcm_hw_constraint_minmax(runtime, SNDRV_PCM_HW_PARAM_BUFFER_BYTES, 0, 0xff00);
return 0;
}
static int snd_es1938_capture_close(struct snd_pcm_substream *substream)
{
struct es1938 *chip = snd_pcm_substream_chip(substream);
chip->capture_substream = NULL;
return 0;
}
static int snd_es1938_playback_close(struct snd_pcm_substream *substream)
{
struct es1938 *chip = snd_pcm_substream_chip(substream);
switch (substream->number) {
case 0:
chip->playback1_substream = NULL;
break;
case 1:
chip->playback2_substream = NULL;
break;
default:
snd_BUG();
return -EINVAL;
}
return 0;
}
static int __devinit snd_es1938_new_pcm(struct es1938 *chip, int device)
{
struct snd_pcm *pcm;
int err;
if ((err = snd_pcm_new(chip->card, "es-1938-1946", device, 2, 1, &pcm)) < 0)
return err;
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_PLAYBACK, &snd_es1938_playback_ops);
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_CAPTURE, &snd_es1938_capture_ops);
pcm->private_data = chip;
pcm->info_flags = 0;
strcpy(pcm->name, "ESS Solo-1");
snd_pcm_lib_preallocate_pages_for_all(pcm, SNDRV_DMA_TYPE_DEV,
snd_dma_pci_data(chip->pci), 64*1024, 64*1024);
chip->pcm = pcm;
return 0;
}
static int snd_es1938_info_mux(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
static char *texts[8] = {
"Mic", "Mic Master", "CD", "AOUT",
"Mic1", "Mix", "Line", "Master"
};
uinfo->type = SNDRV_CTL_ELEM_TYPE_ENUMERATED;
uinfo->count = 1;
uinfo->value.enumerated.items = 8;
if (uinfo->value.enumerated.item > 7)
uinfo->value.enumerated.item = 7;
strcpy(uinfo->value.enumerated.name, texts[uinfo->value.enumerated.item]);
return 0;
}
static int snd_es1938_get_mux(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct es1938 *chip = snd_kcontrol_chip(kcontrol);
ucontrol->value.enumerated.item[0] = snd_es1938_mixer_read(chip, 0x1c) & 0x07;
return 0;
}
static int snd_es1938_put_mux(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct es1938 *chip = snd_kcontrol_chip(kcontrol);
unsigned char val = ucontrol->value.enumerated.item[0];
if (val > 7)
return -EINVAL;
return snd_es1938_mixer_bits(chip, 0x1c, 0x07, val) != val;
}
static int snd_es1938_get_spatializer_enable(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct es1938 *chip = snd_kcontrol_chip(kcontrol);
unsigned char val = snd_es1938_mixer_read(chip, 0x50);
ucontrol->value.integer.value[0] = !!(val & 8);
return 0;
}
static int snd_es1938_put_spatializer_enable(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct es1938 *chip = snd_kcontrol_chip(kcontrol);
unsigned char oval, nval;
int change;
nval = ucontrol->value.integer.value[0] ? 0x0c : 0x04;
oval = snd_es1938_mixer_read(chip, 0x50) & 0x0c;
change = nval != oval;
if (change) {
snd_es1938_mixer_write(chip, 0x50, nval & ~0x04);
snd_es1938_mixer_write(chip, 0x50, nval);
}
return change;
}
static int snd_es1938_info_hw_volume(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = 2;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = 63;
return 0;
}
static int snd_es1938_get_hw_volume(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct es1938 *chip = snd_kcontrol_chip(kcontrol);
ucontrol->value.integer.value[0] = snd_es1938_mixer_read(chip, 0x61) & 0x3f;
ucontrol->value.integer.value[1] = snd_es1938_mixer_read(chip, 0x63) & 0x3f;
return 0;
}
static int snd_es1938_get_hw_switch(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct es1938 *chip = snd_kcontrol_chip(kcontrol);
ucontrol->value.integer.value[0] = !(snd_es1938_mixer_read(chip, 0x61) & 0x40);
ucontrol->value.integer.value[1] = !(snd_es1938_mixer_read(chip, 0x63) & 0x40);
return 0;
}
static void snd_es1938_hwv_free(struct snd_kcontrol *kcontrol)
{
struct es1938 *chip = snd_kcontrol_chip(kcontrol);
chip->master_volume = NULL;
chip->master_switch = NULL;
chip->hw_volume = NULL;
chip->hw_switch = NULL;
}
static int snd_es1938_reg_bits(struct es1938 *chip, unsigned char reg,
unsigned char mask, unsigned char val)
{
if (reg < 0xa0)
return snd_es1938_mixer_bits(chip, reg, mask, val);
else
return snd_es1938_bits(chip, reg, mask, val);
}
static int snd_es1938_reg_read(struct es1938 *chip, unsigned char reg)
{
if (reg < 0xa0)
return snd_es1938_mixer_read(chip, reg);
else
return snd_es1938_read(chip, reg);
}
static int snd_es1938_info_single(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
int mask = (kcontrol->private_value >> 16) & 0xff;
uinfo->type = mask == 1 ? SNDRV_CTL_ELEM_TYPE_BOOLEAN : SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = 1;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = mask;
return 0;
}
static int snd_es1938_get_single(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct es1938 *chip = snd_kcontrol_chip(kcontrol);
int reg = kcontrol->private_value & 0xff;
int shift = (kcontrol->private_value >> 8) & 0xff;
int mask = (kcontrol->private_value >> 16) & 0xff;
int invert = (kcontrol->private_value >> 24) & 0xff;
int val;
val = snd_es1938_reg_read(chip, reg);
ucontrol->value.integer.value[0] = (val >> shift) & mask;
if (invert)
ucontrol->value.integer.value[0] = mask - ucontrol->value.integer.value[0];
return 0;
}
static int snd_es1938_put_single(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct es1938 *chip = snd_kcontrol_chip(kcontrol);
int reg = kcontrol->private_value & 0xff;
int shift = (kcontrol->private_value >> 8) & 0xff;
int mask = (kcontrol->private_value >> 16) & 0xff;
int invert = (kcontrol->private_value >> 24) & 0xff;
unsigned char val;
val = (ucontrol->value.integer.value[0] & mask);
if (invert)
val = mask - val;
mask <<= shift;
val <<= shift;
return snd_es1938_reg_bits(chip, reg, mask, val) != val;
}
static int snd_es1938_info_double(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
int mask = (kcontrol->private_value >> 24) & 0xff;
uinfo->type = mask == 1 ? SNDRV_CTL_ELEM_TYPE_BOOLEAN : SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = 2;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = mask;
return 0;
}
static int snd_es1938_get_double(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct es1938 *chip = snd_kcontrol_chip(kcontrol);
int left_reg = kcontrol->private_value & 0xff;
int right_reg = (kcontrol->private_value >> 8) & 0xff;
int shift_left = (kcontrol->private_value >> 16) & 0x07;
int shift_right = (kcontrol->private_value >> 19) & 0x07;
int mask = (kcontrol->private_value >> 24) & 0xff;
int invert = (kcontrol->private_value >> 22) & 1;
unsigned char left, right;
left = snd_es1938_reg_read(chip, left_reg);
if (left_reg != right_reg)
right = snd_es1938_reg_read(chip, right_reg);
else
right = left;
ucontrol->value.integer.value[0] = (left >> shift_left) & mask;
ucontrol->value.integer.value[1] = (right >> shift_right) & mask;
if (invert) {
ucontrol->value.integer.value[0] = mask - ucontrol->value.integer.value[0];
ucontrol->value.integer.value[1] = mask - ucontrol->value.integer.value[1];
}
return 0;
}
static int snd_es1938_put_double(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct es1938 *chip = snd_kcontrol_chip(kcontrol);
int left_reg = kcontrol->private_value & 0xff;
int right_reg = (kcontrol->private_value >> 8) & 0xff;
int shift_left = (kcontrol->private_value >> 16) & 0x07;
int shift_right = (kcontrol->private_value >> 19) & 0x07;
int mask = (kcontrol->private_value >> 24) & 0xff;
int invert = (kcontrol->private_value >> 22) & 1;
int change;
unsigned char val1, val2, mask1, mask2;
val1 = ucontrol->value.integer.value[0] & mask;
val2 = ucontrol->value.integer.value[1] & mask;
if (invert) {
val1 = mask - val1;
val2 = mask - val2;
}
val1 <<= shift_left;
val2 <<= shift_right;
mask1 = mask << shift_left;
mask2 = mask << shift_right;
if (left_reg != right_reg) {
change = 0;
if (snd_es1938_reg_bits(chip, left_reg, mask1, val1) != val1)
change = 1;
if (snd_es1938_reg_bits(chip, right_reg, mask2, val2) != val2)
change = 1;
} else {
change = (snd_es1938_reg_bits(chip, left_reg, mask1 | mask2,
val1 | val2) != (val1 | val2));
}
return change;
}
static void snd_es1938_chip_init(struct es1938 *chip)
{
snd_es1938_reset(chip);
pci_set_master(chip->pci);
pci_write_config_word(chip->pci, SL_PCI_LEGACYCONTROL, 0x805f);
pci_write_config_word(chip->pci, SL_PCI_DDMACONTROL, chip->ddma_port | 1);
pci_write_config_dword(chip->pci, SL_PCI_CONFIG, 0);
outb(0xf0, SLIO_REG(chip, IRQCONTROL));
outb(0, SLDM_REG(chip, DMACLEAR));
}
static int es1938_suspend(struct device *dev)
{
struct pci_dev *pci = to_pci_dev(dev);
struct snd_card *card = dev_get_drvdata(dev);
struct es1938 *chip = card->private_data;
unsigned char *s, *d;
snd_power_change_state(card, SNDRV_CTL_POWER_D3hot);
snd_pcm_suspend_all(chip->pcm);
for (s = saved_regs, d = chip->saved_regs; *s; s++, d++)
*d = snd_es1938_reg_read(chip, *s);
outb(0x00, SLIO_REG(chip, IRQCONTROL));
if (chip->irq >= 0) {
free_irq(chip->irq, chip);
chip->irq = -1;
}
pci_disable_device(pci);
pci_save_state(pci);
pci_set_power_state(pci, PCI_D3hot);
return 0;
}
static int es1938_resume(struct device *dev)
{
struct pci_dev *pci = to_pci_dev(dev);
struct snd_card *card = dev_get_drvdata(dev);
struct es1938 *chip = card->private_data;
unsigned char *s, *d;
pci_set_power_state(pci, PCI_D0);
pci_restore_state(pci);
if (pci_enable_device(pci) < 0) {
printk(KERN_ERR "es1938: pci_enable_device failed, "
"disabling device\n");
snd_card_disconnect(card);
return -EIO;
}
if (request_irq(pci->irq, snd_es1938_interrupt,
IRQF_SHARED, KBUILD_MODNAME, chip)) {
printk(KERN_ERR "es1938: unable to grab IRQ %d, "
"disabling device\n", pci->irq);
snd_card_disconnect(card);
return -EIO;
}
chip->irq = pci->irq;
snd_es1938_chip_init(chip);
for (s = saved_regs, d = chip->saved_regs; *s; s++, d++) {
if (*s < 0xa0)
snd_es1938_mixer_write(chip, *s, *d);
else
snd_es1938_write(chip, *s, *d);
}
snd_power_change_state(card, SNDRV_CTL_POWER_D0);
return 0;
}
static int __devinit snd_es1938_create_gameport(struct es1938 *chip)
{
struct gameport *gp;
chip->gameport = gp = gameport_allocate_port();
if (!gp) {
printk(KERN_ERR "es1938: cannot allocate memory for gameport\n");
return -ENOMEM;
}
gameport_set_name(gp, "ES1938");
gameport_set_phys(gp, "pci%s/gameport0", pci_name(chip->pci));
gameport_set_dev_parent(gp, &chip->pci->dev);
gp->io = chip->game_port;
gameport_register_port(gp);
return 0;
}
static void snd_es1938_free_gameport(struct es1938 *chip)
{
if (chip->gameport) {
gameport_unregister_port(chip->gameport);
chip->gameport = NULL;
}
}
static inline int snd_es1938_create_gameport(struct es1938 *chip) { return -ENOSYS; }
static inline void snd_es1938_free_gameport(struct es1938 *chip) { }
static int snd_es1938_free(struct es1938 *chip)
{
outb(0x00, SLIO_REG(chip, IRQCONTROL));
if (chip->rmidi)
snd_es1938_mixer_bits(chip, ESSSB_IREG_MPU401CONTROL, 0x40, 0);
snd_es1938_free_gameport(chip);
if (chip->irq >= 0)
free_irq(chip->irq, chip);
pci_release_regions(chip->pci);
pci_disable_device(chip->pci);
kfree(chip);
return 0;
}
static int snd_es1938_dev_free(struct snd_device *device)
{
struct es1938 *chip = device->device_data;
return snd_es1938_free(chip);
}
static int __devinit snd_es1938_create(struct snd_card *card,
struct pci_dev * pci,
struct es1938 ** rchip)
{
struct es1938 *chip;
int err;
static struct snd_device_ops ops = {
.dev_free = snd_es1938_dev_free,
};
*rchip = NULL;
if ((err = pci_enable_device(pci)) < 0)
return err;
if (pci_set_dma_mask(pci, DMA_BIT_MASK(24)) < 0 ||
pci_set_consistent_dma_mask(pci, DMA_BIT_MASK(24)) < 0) {
snd_printk(KERN_ERR "architecture does not support 24bit PCI busmaster DMA\n");
pci_disable_device(pci);
return -ENXIO;
}
chip = kzalloc(sizeof(*chip), GFP_KERNEL);
if (chip == NULL) {
pci_disable_device(pci);
return -ENOMEM;
}
spin_lock_init(&chip->reg_lock);
spin_lock_init(&chip->mixer_lock);
chip->card = card;
chip->pci = pci;
chip->irq = -1;
if ((err = pci_request_regions(pci, "ESS Solo-1")) < 0) {
kfree(chip);
pci_disable_device(pci);
return err;
}
chip->io_port = pci_resource_start(pci, 0);
chip->sb_port = pci_resource_start(pci, 1);
chip->vc_port = pci_resource_start(pci, 2);
chip->mpu_port = pci_resource_start(pci, 3);
chip->game_port = pci_resource_start(pci, 4);
if (request_irq(pci->irq, snd_es1938_interrupt, IRQF_SHARED,
KBUILD_MODNAME, chip)) {
snd_printk(KERN_ERR "unable to grab IRQ %d\n", pci->irq);
snd_es1938_free(chip);
return -EBUSY;
}
chip->irq = pci->irq;
#ifdef ES1938_DDEBUG
snd_printk(KERN_DEBUG "create: io: 0x%lx, sb: 0x%lx, vc: 0x%lx, mpu: 0x%lx, game: 0x%lx\n",
chip->io_port, chip->sb_port, chip->vc_port, chip->mpu_port, chip->game_port);
#endif
chip->ddma_port = chip->vc_port + 0x00;
snd_es1938_chip_init(chip);
if ((err = snd_device_new(card, SNDRV_DEV_LOWLEVEL, chip, &ops)) < 0) {
snd_es1938_free(chip);
return err;
}
snd_card_set_dev(card, &pci->dev);
*rchip = chip;
return 0;
}
static irqreturn_t snd_es1938_interrupt(int irq, void *dev_id)
{
struct es1938 *chip = dev_id;
unsigned char status, audiostatus;
int handled = 0;
status = inb(SLIO_REG(chip, IRQCONTROL));
#if 0
printk(KERN_DEBUG "Es1938debug - interrupt status: =0x%x\n", status);
#endif
if (status & 0x10) {
#if 0
printk(KERN_DEBUG
"Es1938debug - AUDIO channel 1 interrupt\n");
printk(KERN_DEBUG
"Es1938debug - AUDIO channel 1 DMAC DMA count: %u\n",
inw(SLDM_REG(chip, DMACOUNT)));
printk(KERN_DEBUG
"Es1938debug - AUDIO channel 1 DMAC DMA base: %u\n",
inl(SLDM_REG(chip, DMAADDR)));
printk(KERN_DEBUG
"Es1938debug - AUDIO channel 1 DMAC DMA status: 0x%x\n",
inl(SLDM_REG(chip, DMASTATUS)));
#endif
handled = 1;
audiostatus = inb(SLSB_REG(chip, STATUS));
if (chip->active & ADC1)
snd_pcm_period_elapsed(chip->capture_substream);
else if (chip->active & DAC1)
snd_pcm_period_elapsed(chip->playback2_substream);
}
if (status & 0x20) {
#if 0
printk(KERN_DEBUG
"Es1938debug - AUDIO channel 2 interrupt\n");
printk(KERN_DEBUG
"Es1938debug - AUDIO channel 2 DMAC DMA count: %u\n",
inw(SLIO_REG(chip, AUDIO2DMACOUNT)));
printk(KERN_DEBUG
"Es1938debug - AUDIO channel 2 DMAC DMA base: %u\n",
inl(SLIO_REG(chip, AUDIO2DMAADDR)));
#endif
handled = 1;
snd_es1938_mixer_bits(chip, ESSSB_IREG_AUDIO2CONTROL2, 0x80, 0);
if (chip->active & DAC2)
snd_pcm_period_elapsed(chip->playback1_substream);
}
if (status & 0x40) {
int split = snd_es1938_mixer_read(chip, 0x64) & 0x80;
handled = 1;
snd_ctl_notify(chip->card, SNDRV_CTL_EVENT_MASK_VALUE, &chip->hw_switch->id);
snd_ctl_notify(chip->card, SNDRV_CTL_EVENT_MASK_VALUE, &chip->hw_volume->id);
if (!split) {
snd_ctl_notify(chip->card, SNDRV_CTL_EVENT_MASK_VALUE,
&chip->master_switch->id);
snd_ctl_notify(chip->card, SNDRV_CTL_EVENT_MASK_VALUE,
&chip->master_volume->id);
}
snd_es1938_mixer_write(chip, 0x66, 0x00);
}
if (status & 0x80) {
if (chip->rmidi) {
handled = 1;
snd_mpu401_uart_interrupt(irq, chip->rmidi->private_data);
}
}
return IRQ_RETVAL(handled);
}
static int __devinit snd_es1938_mixer(struct es1938 *chip)
{
struct snd_card *card;
unsigned int idx;
int err;
card = chip->card;
strcpy(card->mixername, "ESS Solo-1");
for (idx = 0; idx < ARRAY_SIZE(snd_es1938_controls); idx++) {
struct snd_kcontrol *kctl;
kctl = snd_ctl_new1(&snd_es1938_controls[idx], chip);
switch (idx) {
case 0:
chip->master_volume = kctl;
kctl->private_free = snd_es1938_hwv_free;
break;
case 1:
chip->master_switch = kctl;
kctl->private_free = snd_es1938_hwv_free;
break;
case 2:
chip->hw_volume = kctl;
kctl->private_free = snd_es1938_hwv_free;
break;
case 3:
chip->hw_switch = kctl;
kctl->private_free = snd_es1938_hwv_free;
break;
}
if ((err = snd_ctl_add(card, kctl)) < 0)
return err;
}
return 0;
}
static int __devinit snd_es1938_probe(struct pci_dev *pci,
const struct pci_device_id *pci_id)
{
static int dev;
struct snd_card *card;
struct es1938 *chip;
struct snd_opl3 *opl3;
int idx, err;
if (dev >= SNDRV_CARDS)
return -ENODEV;
if (!enable[dev]) {
dev++;
return -ENOENT;
}
err = snd_card_create(index[dev], id[dev], THIS_MODULE, 0, &card);
if (err < 0)
return err;
for (idx = 0; idx < 5; idx++) {
if (pci_resource_start(pci, idx) == 0 ||
!(pci_resource_flags(pci, idx) & IORESOURCE_IO)) {
snd_card_free(card);
return -ENODEV;
}
}
if ((err = snd_es1938_create(card, pci, &chip)) < 0) {
snd_card_free(card);
return err;
}
card->private_data = chip;
strcpy(card->driver, "ES1938");
strcpy(card->shortname, "ESS ES1938 (Solo-1)");
sprintf(card->longname, "%s rev %i, irq %i",
card->shortname,
chip->revision,
chip->irq);
if ((err = snd_es1938_new_pcm(chip, 0)) < 0) {
snd_card_free(card);
return err;
}
if ((err = snd_es1938_mixer(chip)) < 0) {
snd_card_free(card);
return err;
}
if (snd_opl3_create(card,
SLSB_REG(chip, FMLOWADDR),
SLSB_REG(chip, FMHIGHADDR),
OPL3_HW_OPL3, 1, &opl3) < 0) {
printk(KERN_ERR "es1938: OPL3 not detected at 0x%lx\n",
SLSB_REG(chip, FMLOWADDR));
} else {
if ((err = snd_opl3_timer_new(opl3, 0, 1)) < 0) {
snd_card_free(card);
return err;
}
if ((err = snd_opl3_hwdep_new(opl3, 0, 1, NULL)) < 0) {
snd_card_free(card);
return err;
}
}
if (snd_mpu401_uart_new(card, 0, MPU401_HW_MPU401,
chip->mpu_port,
MPU401_INFO_INTEGRATED | MPU401_INFO_IRQ_HOOK,
-1, &chip->rmidi) < 0) {
printk(KERN_ERR "es1938: unable to initialize MPU-401\n");
} else {
snd_es1938_mixer_bits(chip, ESSSB_IREG_MPU401CONTROL, 0x40, 0x40);
}
snd_es1938_create_gameport(chip);
if ((err = snd_card_register(card)) < 0) {
snd_card_free(card);
return err;
}
pci_set_drvdata(pci, card);
dev++;
return 0;
}
static void __devexit snd_es1938_remove(struct pci_dev *pci)
{
snd_card_free(pci_get_drvdata(pci));
pci_set_drvdata(pci, NULL);
}
