static inline void snd_cmipci_write(struct cmipci *cm, unsigned int cmd, unsigned int data)
{
outl(data, cm->iobase + cmd);
}
static inline unsigned int snd_cmipci_read(struct cmipci *cm, unsigned int cmd)
{
return inl(cm->iobase + cmd);
}
static inline void snd_cmipci_write_w(struct cmipci *cm, unsigned int cmd, unsigned short data)
{
outw(data, cm->iobase + cmd);
}
static inline unsigned short snd_cmipci_read_w(struct cmipci *cm, unsigned int cmd)
{
return inw(cm->iobase + cmd);
}
static inline void snd_cmipci_write_b(struct cmipci *cm, unsigned int cmd, unsigned char data)
{
outb(data, cm->iobase + cmd);
}
static inline unsigned char snd_cmipci_read_b(struct cmipci *cm, unsigned int cmd)
{
return inb(cm->iobase + cmd);
}
static int snd_cmipci_set_bit(struct cmipci *cm, unsigned int cmd, unsigned int flag)
{
unsigned int val, oval;
val = oval = inl(cm->iobase + cmd);
val |= flag;
if (val == oval)
return 0;
outl(val, cm->iobase + cmd);
return 1;
}
static int snd_cmipci_clear_bit(struct cmipci *cm, unsigned int cmd, unsigned int flag)
{
unsigned int val, oval;
val = oval = inl(cm->iobase + cmd);
val &= ~flag;
if (val == oval)
return 0;
outl(val, cm->iobase + cmd);
return 1;
}
static int snd_cmipci_set_bit_b(struct cmipci *cm, unsigned int cmd, unsigned char flag)
{
unsigned char val, oval;
val = oval = inb(cm->iobase + cmd);
val |= flag;
if (val == oval)
return 0;
outb(val, cm->iobase + cmd);
return 1;
}
static int snd_cmipci_clear_bit_b(struct cmipci *cm, unsigned int cmd, unsigned char flag)
{
unsigned char val, oval;
val = oval = inb(cm->iobase + cmd);
val &= ~flag;
if (val == oval)
return 0;
outb(val, cm->iobase + cmd);
return 1;
}
static unsigned int snd_cmipci_rate_freq(unsigned int rate)
{
unsigned int i;
for (i = 0; i < ARRAY_SIZE(rates); i++) {
if (rates[i] == rate)
return i;
}
snd_BUG();
return 0;
}
static int snd_cmipci_pll_rmn(unsigned int rate, unsigned int adcmult, int *r, int *m, int *n)
{
unsigned int delta, tolerance;
int xm, xn, xr;
for (*r = 0; rate < CM_MAXIMUM_RATE/adcmult; *r += (1<<5))
rate <<= 1;
*n = -1;
if (*r > 0xff)
goto out;
tolerance = rate*CM_TOLERANCE_RATE;
for (xn = (1+2); xn < (0x1f+2); xn++) {
for (xm = (1+2); xm < (0xff+2); xm++) {
xr = ((CM_REFFREQ_XIN/adcmult) * xm) / xn;
if (xr < rate)
delta = rate - xr;
else
delta = xr - rate;
if (delta < tolerance) {
tolerance = delta;
*m = xm - 2;
*n = xn - 2;
}
}
}
out:
return (*n > -1);
}
static void snd_cmipci_set_pll(struct cmipci *cm, unsigned int rate, unsigned int slot)
{
unsigned int reg = CM_REG_PLL + slot;
snd_cmipci_write_b(cm, reg, rate>>8);
snd_cmipci_write_b(cm, reg, rate&0xff);
}
static int snd_cmipci_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *hw_params)
{
return snd_pcm_lib_malloc_pages(substream, params_buffer_bytes(hw_params));
}
static int snd_cmipci_playback2_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *hw_params)
{
struct cmipci *cm = snd_pcm_substream_chip(substream);
if (params_channels(hw_params) > 2) {
mutex_lock(&cm->open_mutex);
if (cm->opened[CM_CH_PLAY]) {
mutex_unlock(&cm->open_mutex);
return -EBUSY;
}
cm->opened[CM_CH_PLAY] = CM_OPEN_PLAYBACK_MULTI;
mutex_unlock(&cm->open_mutex);
}
return snd_pcm_lib_malloc_pages(substream, params_buffer_bytes(hw_params));
}
static void snd_cmipci_ch_reset(struct cmipci *cm, int ch)
{
int reset = CM_RST_CH0 << (cm->channel[ch].ch);
snd_cmipci_write(cm, CM_REG_FUNCTRL0, cm->ctrl | reset);
snd_cmipci_write(cm, CM_REG_FUNCTRL0, cm->ctrl & ~reset);
udelay(10);
}
static int snd_cmipci_hw_free(struct snd_pcm_substream *substream)
{
return snd_pcm_lib_free_pages(substream);
}
static int set_dac_channels(struct cmipci *cm, struct cmipci_pcm *rec, int channels)
{
if (channels > 2) {
if (!cm->can_multi_ch || !rec->ch)
return -EINVAL;
if (rec->fmt != 0x03)
return -EINVAL;
}
if (cm->can_multi_ch) {
spin_lock_irq(&cm->reg_lock);
if (channels > 2) {
snd_cmipci_set_bit(cm, CM_REG_LEGACY_CTRL, CM_NXCHG);
snd_cmipci_set_bit(cm, CM_REG_MISC_CTRL, CM_XCHGDAC);
} else {
snd_cmipci_clear_bit(cm, CM_REG_LEGACY_CTRL, CM_NXCHG);
snd_cmipci_clear_bit(cm, CM_REG_MISC_CTRL, CM_XCHGDAC);
}
if (channels == 8)
snd_cmipci_set_bit(cm, CM_REG_EXT_MISC, CM_CHB3D8C);
else
snd_cmipci_clear_bit(cm, CM_REG_EXT_MISC, CM_CHB3D8C);
if (channels == 6) {
snd_cmipci_set_bit(cm, CM_REG_CHFORMAT, CM_CHB3D5C);
snd_cmipci_set_bit(cm, CM_REG_LEGACY_CTRL, CM_CHB3D6C);
} else {
snd_cmipci_clear_bit(cm, CM_REG_CHFORMAT, CM_CHB3D5C);
snd_cmipci_clear_bit(cm, CM_REG_LEGACY_CTRL, CM_CHB3D6C);
}
if (channels == 4)
snd_cmipci_set_bit(cm, CM_REG_CHFORMAT, CM_CHB3D);
else
snd_cmipci_clear_bit(cm, CM_REG_CHFORMAT, CM_CHB3D);
spin_unlock_irq(&cm->reg_lock);
}
return 0;
}
static int snd_cmipci_pcm_prepare(struct cmipci *cm, struct cmipci_pcm *rec,
struct snd_pcm_substream *substream)
{
unsigned int reg, freq, freq_ext, val;
unsigned int period_size;
struct snd_pcm_runtime *runtime = substream->runtime;
rec->fmt = 0;
rec->shift = 0;
if (snd_pcm_format_width(runtime->format) >= 16) {
rec->fmt |= 0x02;
if (snd_pcm_format_width(runtime->format) > 16)
rec->shift++;
}
if (runtime->channels > 1)
rec->fmt |= 0x01;
if (rec->is_dac && set_dac_channels(cm, rec, runtime->channels) < 0) {
snd_printd("cannot set dac channels\n");
return -EINVAL;
}
rec->offset = runtime->dma_addr;
rec->dma_size = runtime->buffer_size << rec->shift;
period_size = runtime->period_size << rec->shift;
if (runtime->channels > 2) {
rec->dma_size = (rec->dma_size * runtime->channels) / 2;
period_size = (period_size * runtime->channels) / 2;
}
spin_lock_irq(&cm->reg_lock);
reg = rec->ch ? CM_REG_CH1_FRAME1 : CM_REG_CH0_FRAME1;
snd_cmipci_write(cm, reg, rec->offset);
reg = rec->ch ? CM_REG_CH1_FRAME2 : CM_REG_CH0_FRAME2;
snd_cmipci_write_w(cm, reg, rec->dma_size - 1);
snd_cmipci_write_w(cm, reg + 2, period_size - 1);
val = rec->ch ? CM_CHADC1 : CM_CHADC0;
if (rec->is_dac)
cm->ctrl &= ~val;
else
cm->ctrl |= val;
snd_cmipci_write(cm, CM_REG_FUNCTRL0, cm->ctrl);
freq = 0;
freq_ext = 0;
if (runtime->rate > 48000)
switch (runtime->rate) {
case 88200: freq_ext = CM_CH0_SRATE_88K; break;
case 96000: freq_ext = CM_CH0_SRATE_96K; break;
case 128000: freq_ext = CM_CH0_SRATE_128K; break;
default: snd_BUG(); break;
}
else
freq = snd_cmipci_rate_freq(runtime->rate);
val = snd_cmipci_read(cm, CM_REG_FUNCTRL1);
if (rec->ch) {
val &= ~CM_DSFC_MASK;
val |= (freq << CM_DSFC_SHIFT) & CM_DSFC_MASK;
} else {
val &= ~CM_ASFC_MASK;
val |= (freq << CM_ASFC_SHIFT) & CM_ASFC_MASK;
}
snd_cmipci_write(cm, CM_REG_FUNCTRL1, val);
val = snd_cmipci_read(cm, CM_REG_CHFORMAT);
if (rec->ch) {
val &= ~CM_CH1FMT_MASK;
val |= rec->fmt << CM_CH1FMT_SHIFT;
} else {
val &= ~CM_CH0FMT_MASK;
val |= rec->fmt << CM_CH0FMT_SHIFT;
}
if (cm->can_96k) {
val &= ~(CM_CH0_SRATE_MASK << (rec->ch * 2));
val |= freq_ext << (rec->ch * 2);
}
snd_cmipci_write(cm, CM_REG_CHFORMAT, val);
if (!rec->is_dac && cm->chip_version) {
if (runtime->rate > 44100)
snd_cmipci_set_bit(cm, CM_REG_EXT_MISC, CM_ADC48K44K);
else
snd_cmipci_clear_bit(cm, CM_REG_EXT_MISC, CM_ADC48K44K);
}
rec->running = 0;
spin_unlock_irq(&cm->reg_lock);
return 0;
}
static int snd_cmipci_pcm_trigger(struct cmipci *cm, struct cmipci_pcm *rec,
int cmd)
{
unsigned int inthld, chen, reset, pause;
int result = 0;
inthld = CM_CH0_INT_EN << rec->ch;
chen = CM_CHEN0 << rec->ch;
reset = CM_RST_CH0 << rec->ch;
pause = CM_PAUSE0 << rec->ch;
spin_lock(&cm->reg_lock);
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
rec->running = 1;
snd_cmipci_set_bit(cm, CM_REG_INT_HLDCLR, inthld);
cm->ctrl |= chen;
snd_cmipci_write(cm, CM_REG_FUNCTRL0, cm->ctrl);
break;
case SNDRV_PCM_TRIGGER_STOP:
rec->running = 0;
snd_cmipci_clear_bit(cm, CM_REG_INT_HLDCLR, inthld);
cm->ctrl &= ~chen;
snd_cmipci_write(cm, CM_REG_FUNCTRL0, cm->ctrl | reset);
snd_cmipci_write(cm, CM_REG_FUNCTRL0, cm->ctrl & ~reset);
rec->needs_silencing = rec->is_dac;
break;
case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
case SNDRV_PCM_TRIGGER_SUSPEND:
cm->ctrl |= pause;
snd_cmipci_write(cm, CM_REG_FUNCTRL0, cm->ctrl);
break;
case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
case SNDRV_PCM_TRIGGER_RESUME:
cm->ctrl &= ~pause;
snd_cmipci_write(cm, CM_REG_FUNCTRL0, cm->ctrl);
break;
default:
result = -EINVAL;
break;
}
spin_unlock(&cm->reg_lock);
return result;
}
static snd_pcm_uframes_t snd_cmipci_pcm_pointer(struct cmipci *cm, struct cmipci_pcm *rec,
struct snd_pcm_substream *substream)
{
size_t ptr;
unsigned int reg, rem, tries;
if (!rec->running)
return 0;
#if 1
reg = rec->ch ? CM_REG_CH1_FRAME2 : CM_REG_CH0_FRAME2;
for (tries = 0; tries < 3; tries++) {
rem = snd_cmipci_read_w(cm, reg);
if (rem < rec->dma_size)
goto ok;
}
printk(KERN_ERR "cmipci: invalid PCM pointer: %#x\n", rem);
return SNDRV_PCM_POS_XRUN;
ok:
ptr = (rec->dma_size - (rem + 1)) >> rec->shift;
#else
reg = rec->ch ? CM_REG_CH1_FRAME1 : CM_REG_CH0_FRAME1;
ptr = snd_cmipci_read(cm, reg) - rec->offset;
ptr = bytes_to_frames(substream->runtime, ptr);
#endif
if (substream->runtime->channels > 2)
ptr = (ptr * 2) / substream->runtime->channels;
return ptr;
}
static int snd_cmipci_playback_trigger(struct snd_pcm_substream *substream,
int cmd)
{
struct cmipci *cm = snd_pcm_substream_chip(substream);
return snd_cmipci_pcm_trigger(cm, &cm->channel[CM_CH_PLAY], cmd);
}
static snd_pcm_uframes_t snd_cmipci_playback_pointer(struct snd_pcm_substream *substream)
{
struct cmipci *cm = snd_pcm_substream_chip(substream);
return snd_cmipci_pcm_pointer(cm, &cm->channel[CM_CH_PLAY], substream);
}
static int snd_cmipci_capture_trigger(struct snd_pcm_substream *substream,
int cmd)
{
struct cmipci *cm = snd_pcm_substream_chip(substream);
return snd_cmipci_pcm_trigger(cm, &cm->channel[CM_CH_CAPT], cmd);
}
static snd_pcm_uframes_t snd_cmipci_capture_pointer(struct snd_pcm_substream *substream)
{
struct cmipci *cm = snd_pcm_substream_chip(substream);
return snd_cmipci_pcm_pointer(cm, &cm->channel[CM_CH_CAPT], substream);
}
static int snd_cmipci_spdif_default_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_IEC958;
uinfo->count = 1;
return 0;
}
static int snd_cmipci_spdif_default_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct cmipci *chip = snd_kcontrol_chip(kcontrol);
int i;
spin_lock_irq(&chip->reg_lock);
for (i = 0; i < 4; i++)
ucontrol->value.iec958.status[i] = (chip->dig_status >> (i * 8)) & 0xff;
spin_unlock_irq(&chip->reg_lock);
return 0;
}
static int snd_cmipci_spdif_default_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct cmipci *chip = snd_kcontrol_chip(kcontrol);
int i, change;
unsigned int val;
val = 0;
spin_lock_irq(&chip->reg_lock);
for (i = 0; i < 4; i++)
val |= (unsigned int)ucontrol->value.iec958.status[i] << (i * 8);
change = val != chip->dig_status;
chip->dig_status = val;
spin_unlock_irq(&chip->reg_lock);
return change;
}
static int snd_cmipci_spdif_mask_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_IEC958;
uinfo->count = 1;
return 0;
}
static int snd_cmipci_spdif_mask_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
ucontrol->value.iec958.status[0] = 0xff;
ucontrol->value.iec958.status[1] = 0xff;
ucontrol->value.iec958.status[2] = 0xff;
ucontrol->value.iec958.status[3] = 0xff;
return 0;
}
static int snd_cmipci_spdif_stream_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_IEC958;
uinfo->count = 1;
return 0;
}
static int snd_cmipci_spdif_stream_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct cmipci *chip = snd_kcontrol_chip(kcontrol);
int i;
spin_lock_irq(&chip->reg_lock);
for (i = 0; i < 4; i++)
ucontrol->value.iec958.status[i] = (chip->dig_pcm_status >> (i * 8)) & 0xff;
spin_unlock_irq(&chip->reg_lock);
return 0;
}
static int snd_cmipci_spdif_stream_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct cmipci *chip = snd_kcontrol_chip(kcontrol);
int i, change;
unsigned int val;
val = 0;
spin_lock_irq(&chip->reg_lock);
for (i = 0; i < 4; i++)
val |= (unsigned int)ucontrol->value.iec958.status[i] << (i * 8);
change = val != chip->dig_pcm_status;
chip->dig_pcm_status = val;
spin_unlock_irq(&chip->reg_lock);
return change;
}
static int save_mixer_state(struct cmipci *cm)
{
if (! cm->mixer_insensitive) {
struct snd_ctl_elem_value *val;
unsigned int i;
val = kmalloc(sizeof(*val), GFP_ATOMIC);
if (!val)
return -ENOMEM;
for (i = 0; i < CM_SAVED_MIXERS; i++) {
struct snd_kcontrol *ctl = cm->mixer_res_ctl[i];
if (ctl) {
int event;
memset(val, 0, sizeof(*val));
ctl->get(ctl, val);
cm->mixer_res_status[i] = val->value.integer.value[0];
val->value.integer.value[0] = cm_saved_mixer[i].toggle_on;
event = SNDRV_CTL_EVENT_MASK_INFO;
if (cm->mixer_res_status[i] != val->value.integer.value[0]) {
ctl->put(ctl, val);
event |= SNDRV_CTL_EVENT_MASK_VALUE;
}
ctl->vd[0].access |= SNDRV_CTL_ELEM_ACCESS_INACTIVE;
snd_ctl_notify(cm->card, event, &ctl->id);
}
}
kfree(val);
cm->mixer_insensitive = 1;
}
return 0;
}
static void restore_mixer_state(struct cmipci *cm)
{
if (cm->mixer_insensitive) {
struct snd_ctl_elem_value *val;
unsigned int i;
val = kmalloc(sizeof(*val), GFP_KERNEL);
if (!val)
return;
cm->mixer_insensitive = 0;
for (i = 0; i < CM_SAVED_MIXERS; i++) {
struct snd_kcontrol *ctl = cm->mixer_res_ctl[i];
if (ctl) {
int event;
memset(val, 0, sizeof(*val));
ctl->vd[0].access &= ~SNDRV_CTL_ELEM_ACCESS_INACTIVE;
ctl->get(ctl, val);
event = SNDRV_CTL_EVENT_MASK_INFO;
if (val->value.integer.value[0] != cm->mixer_res_status[i]) {
val->value.integer.value[0] = cm->mixer_res_status[i];
ctl->put(ctl, val);
event |= SNDRV_CTL_EVENT_MASK_VALUE;
}
snd_ctl_notify(cm->card, event, &ctl->id);
}
}
kfree(val);
}
}
static void setup_ac3(struct cmipci *cm, struct snd_pcm_substream *subs, int do_ac3, int rate)
{
if (do_ac3) {
snd_cmipci_set_bit(cm, CM_REG_CHFORMAT, CM_AC3EN1);
snd_cmipci_set_bit(cm, CM_REG_MISC_CTRL, CM_AC3EN2);
if (cm->can_ac3_hw) {
snd_cmipci_set_bit(cm, CM_REG_CHFORMAT, CM_SPD24SEL);
snd_cmipci_clear_bit(cm, CM_REG_MISC_CTRL, CM_SPD32SEL);
} else {
snd_cmipci_set_bit(cm, CM_REG_MISC_CTRL, CM_SPD32SEL);
if (cm->chip_version == 33) {
if (rate >= 48000) {
snd_cmipci_set_bit(cm, CM_REG_CHFORMAT, CM_PLAYBACK_SRATE_176K);
} else {
snd_cmipci_clear_bit(cm, CM_REG_CHFORMAT, CM_PLAYBACK_SRATE_176K);
}
}
}
} else {
snd_cmipci_clear_bit(cm, CM_REG_CHFORMAT, CM_AC3EN1);
snd_cmipci_clear_bit(cm, CM_REG_MISC_CTRL, CM_AC3EN2);
if (cm->can_ac3_hw) {
if (snd_pcm_format_width(subs->runtime->format) > 16) {
snd_cmipci_set_bit(cm, CM_REG_MISC_CTRL, CM_SPD32SEL);
snd_cmipci_set_bit(cm, CM_REG_CHFORMAT, CM_SPD24SEL);
} else {
snd_cmipci_clear_bit(cm, CM_REG_MISC_CTRL, CM_SPD32SEL);
snd_cmipci_clear_bit(cm, CM_REG_CHFORMAT, CM_SPD24SEL);
}
} else {
snd_cmipci_clear_bit(cm, CM_REG_MISC_CTRL, CM_SPD32SEL);
snd_cmipci_clear_bit(cm, CM_REG_CHFORMAT, CM_SPD24SEL);
snd_cmipci_clear_bit(cm, CM_REG_CHFORMAT, CM_PLAYBACK_SRATE_176K);
}
}
}
static int setup_spdif_playback(struct cmipci *cm, struct snd_pcm_substream *subs, int up, int do_ac3)
{
int rate, err;
rate = subs->runtime->rate;
if (up && do_ac3)
if ((err = save_mixer_state(cm)) < 0)
return err;
spin_lock_irq(&cm->reg_lock);
cm->spdif_playback_avail = up;
if (up) {
if (cm->spdif_playback_enabled)
snd_cmipci_set_bit(cm, CM_REG_FUNCTRL1, CM_PLAYBACK_SPDF);
setup_ac3(cm, subs, do_ac3, rate);
if (rate == 48000 || rate == 96000)
snd_cmipci_set_bit(cm, CM_REG_MISC_CTRL, CM_SPDIF48K | CM_SPDF_AC97);
else
snd_cmipci_clear_bit(cm, CM_REG_MISC_CTRL, CM_SPDIF48K | CM_SPDF_AC97);
if (rate > 48000)
snd_cmipci_set_bit(cm, CM_REG_CHFORMAT, CM_DBLSPDS);
else
snd_cmipci_clear_bit(cm, CM_REG_CHFORMAT, CM_DBLSPDS);
} else {
snd_cmipci_clear_bit(cm, CM_REG_CHFORMAT, CM_DBLSPDS);
snd_cmipci_clear_bit(cm, CM_REG_FUNCTRL1, CM_PLAYBACK_SPDF);
setup_ac3(cm, subs, 0, 0);
}
spin_unlock_irq(&cm->reg_lock);
return 0;
}
static int snd_cmipci_playback_prepare(struct snd_pcm_substream *substream)
{
struct cmipci *cm = snd_pcm_substream_chip(substream);
int rate = substream->runtime->rate;
int err, do_spdif, do_ac3 = 0;
do_spdif = (rate >= 44100 && rate <= 96000 &&
substream->runtime->format == SNDRV_PCM_FORMAT_S16_LE &&
substream->runtime->channels == 2);
if (do_spdif && cm->can_ac3_hw)
do_ac3 = cm->dig_pcm_status & IEC958_AES0_NONAUDIO;
if ((err = setup_spdif_playback(cm, substream, do_spdif, do_ac3)) < 0)
return err;
return snd_cmipci_pcm_prepare(cm, &cm->channel[CM_CH_PLAY], substream);
}
static int snd_cmipci_playback_spdif_prepare(struct snd_pcm_substream *substream)
{
struct cmipci *cm = snd_pcm_substream_chip(substream);
int err, do_ac3;
if (cm->can_ac3_hw)
do_ac3 = cm->dig_pcm_status & IEC958_AES0_NONAUDIO;
else
do_ac3 = 1;
if ((err = setup_spdif_playback(cm, substream, 1, do_ac3)) < 0)
return err;
return snd_cmipci_pcm_prepare(cm, &cm->channel[CM_CH_PLAY], substream);
}
static void snd_cmipci_silence_hack(struct cmipci *cm, struct cmipci_pcm *rec)
{
struct snd_pcm_runtime *runtime = rec->substream->runtime;
unsigned int reg, val;
if (rec->needs_silencing && runtime && runtime->dma_area) {
memset(runtime->dma_area, 0, PAGE_SIZE);
reg = rec->ch ? CM_REG_CH1_FRAME2 : CM_REG_CH0_FRAME2;
val = ((PAGE_SIZE / 4) - 1) | (((PAGE_SIZE / 4) / 2 - 1) << 16);
snd_cmipci_write(cm, reg, val);
if (runtime->channels > 2)
set_dac_channels(cm, rec, 2);
spin_lock_irq(&cm->reg_lock);
val = snd_cmipci_read(cm, CM_REG_FUNCTRL1);
val &= ~(CM_ASFC_MASK << (rec->ch * 3));
val |= (4 << CM_ASFC_SHIFT) << (rec->ch * 3);
snd_cmipci_write(cm, CM_REG_FUNCTRL1, val);
val = snd_cmipci_read(cm, CM_REG_CHFORMAT);
val &= ~(CM_CH0FMT_MASK << (rec->ch * 2));
val |= (3 << CM_CH0FMT_SHIFT) << (rec->ch * 2);
if (cm->can_96k)
val &= ~(CM_CH0_SRATE_MASK << (rec->ch * 2));
snd_cmipci_write(cm, CM_REG_CHFORMAT, val);
cm->ctrl |= CM_CHEN0 << rec->ch;
snd_cmipci_write(cm, CM_REG_FUNCTRL0, cm->ctrl);
spin_unlock_irq(&cm->reg_lock);
msleep(1);
spin_lock_irq(&cm->reg_lock);
cm->ctrl &= ~(CM_CHEN0 << rec->ch);
val = CM_RST_CH0 << rec->ch;
snd_cmipci_write(cm, CM_REG_FUNCTRL0, cm->ctrl | val);
snd_cmipci_write(cm, CM_REG_FUNCTRL0, cm->ctrl & ~val);
spin_unlock_irq(&cm->reg_lock);
rec->needs_silencing = 0;
}
}
static int snd_cmipci_playback_hw_free(struct snd_pcm_substream *substream)
{
struct cmipci *cm = snd_pcm_substream_chip(substream);
setup_spdif_playback(cm, substream, 0, 0);
restore_mixer_state(cm);
snd_cmipci_silence_hack(cm, &cm->channel[0]);
return snd_cmipci_hw_free(substream);
}
static int snd_cmipci_playback2_hw_free(struct snd_pcm_substream *substream)
{
struct cmipci *cm = snd_pcm_substream_chip(substream);
snd_cmipci_silence_hack(cm, &cm->channel[1]);
return snd_cmipci_hw_free(substream);
}
static int snd_cmipci_capture_prepare(struct snd_pcm_substream *substream)
{
struct cmipci *cm = snd_pcm_substream_chip(substream);
return snd_cmipci_pcm_prepare(cm, &cm->channel[CM_CH_CAPT], substream);
}
static int snd_cmipci_capture_spdif_prepare(struct snd_pcm_substream *substream)
{
struct cmipci *cm = snd_pcm_substream_chip(substream);
spin_lock_irq(&cm->reg_lock);
snd_cmipci_set_bit(cm, CM_REG_FUNCTRL1, CM_CAPTURE_SPDF);
if (cm->can_96k) {
if (substream->runtime->rate > 48000)
snd_cmipci_set_bit(cm, CM_REG_CHFORMAT, CM_DBLSPDS);
else
snd_cmipci_clear_bit(cm, CM_REG_CHFORMAT, CM_DBLSPDS);
}
if (snd_pcm_format_width(substream->runtime->format) > 16)
snd_cmipci_set_bit(cm, CM_REG_MISC_CTRL, CM_SPD32SEL);
else
snd_cmipci_clear_bit(cm, CM_REG_MISC_CTRL, CM_SPD32SEL);
spin_unlock_irq(&cm->reg_lock);
return snd_cmipci_pcm_prepare(cm, &cm->channel[CM_CH_CAPT], substream);
}
static int snd_cmipci_capture_spdif_hw_free(struct snd_pcm_substream *subs)
{
struct cmipci *cm = snd_pcm_substream_chip(subs);
spin_lock_irq(&cm->reg_lock);
snd_cmipci_clear_bit(cm, CM_REG_FUNCTRL1, CM_CAPTURE_SPDF);
snd_cmipci_clear_bit(cm, CM_REG_MISC_CTRL, CM_SPD32SEL);
spin_unlock_irq(&cm->reg_lock);
return snd_cmipci_hw_free(subs);
}
static irqreturn_t snd_cmipci_interrupt(int irq, void *dev_id)
{
struct cmipci *cm = dev_id;
unsigned int status, mask = 0;
status = snd_cmipci_read(cm, CM_REG_INT_STATUS);
if (!(status & CM_INTR))
return IRQ_NONE;
spin_lock(&cm->reg_lock);
if (status & CM_CHINT0)
mask |= CM_CH0_INT_EN;
if (status & CM_CHINT1)
mask |= CM_CH1_INT_EN;
snd_cmipci_clear_bit(cm, CM_REG_INT_HLDCLR, mask);
snd_cmipci_set_bit(cm, CM_REG_INT_HLDCLR, mask);
spin_unlock(&cm->reg_lock);
if (cm->rmidi && (status & CM_UARTINT))
snd_mpu401_uart_interrupt(irq, cm->rmidi->private_data);
if (cm->pcm) {
if ((status & CM_CHINT0) && cm->channel[0].running)
snd_pcm_period_elapsed(cm->channel[0].substream);
if ((status & CM_CHINT1) && cm->channel[1].running)
snd_pcm_period_elapsed(cm->channel[1].substream);
}
return IRQ_HANDLED;
}
static int open_device_check(struct cmipci *cm, int mode, struct snd_pcm_substream *subs)
{
int ch = mode & CM_OPEN_CH_MASK;
mutex_lock(&cm->open_mutex);
if (cm->opened[ch]) {
mutex_unlock(&cm->open_mutex);
return -EBUSY;
}
cm->opened[ch] = mode;
cm->channel[ch].substream = subs;
if (! (mode & CM_OPEN_DAC)) {
cm->channel[ch].is_dac = 0;
spin_lock_irq(&cm->reg_lock);
snd_cmipci_clear_bit(cm, CM_REG_MISC_CTRL, CM_ENDBDAC);
spin_unlock_irq(&cm->reg_lock);
}
mutex_unlock(&cm->open_mutex);
return 0;
}
static void close_device_check(struct cmipci *cm, int mode)
{
int ch = mode & CM_OPEN_CH_MASK;
mutex_lock(&cm->open_mutex);
if (cm->opened[ch] == mode) {
if (cm->channel[ch].substream) {
snd_cmipci_ch_reset(cm, ch);
cm->channel[ch].running = 0;
cm->channel[ch].substream = NULL;
}
cm->opened[ch] = 0;
if (! cm->channel[ch].is_dac) {
cm->channel[ch].is_dac = 1;
spin_lock_irq(&cm->reg_lock);
snd_cmipci_set_bit(cm, CM_REG_MISC_CTRL, CM_ENDBDAC);
spin_unlock_irq(&cm->reg_lock);
}
}
mutex_unlock(&cm->open_mutex);
}
static int snd_cmipci_playback_open(struct snd_pcm_substream *substream)
{
struct cmipci *cm = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
int err;
if ((err = open_device_check(cm, CM_OPEN_PLAYBACK, substream)) < 0)
return err;
runtime->hw = snd_cmipci_playback;
if (cm->chip_version == 68) {
runtime->hw.rates |= SNDRV_PCM_RATE_88200 |
SNDRV_PCM_RATE_96000;
runtime->hw.rate_max = 96000;
} else if (cm->chip_version == 55) {
err = snd_pcm_hw_constraint_list(runtime, 0,
SNDRV_PCM_HW_PARAM_RATE, &hw_constraints_rates);
if (err < 0)
return err;
runtime->hw.rates |= SNDRV_PCM_RATE_KNOT;
runtime->hw.rate_max = 128000;
}
snd_pcm_hw_constraint_minmax(runtime, SNDRV_PCM_HW_PARAM_BUFFER_SIZE, 0, 0x10000);
cm->dig_pcm_status = cm->dig_status;
return 0;
}
static int snd_cmipci_capture_open(struct snd_pcm_substream *substream)
{
struct cmipci *cm = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
int err;
if ((err = open_device_check(cm, CM_OPEN_CAPTURE, substream)) < 0)
return err;
runtime->hw = snd_cmipci_capture;
if (cm->chip_version == 68) {
runtime->hw.rate_min = 41000;
runtime->hw.rates = SNDRV_PCM_RATE_44100 | SNDRV_PCM_RATE_48000;
} else if (cm->chip_version == 55) {
err = snd_pcm_hw_constraint_list(runtime, 0,
SNDRV_PCM_HW_PARAM_RATE, &hw_constraints_rates);
if (err < 0)
return err;
runtime->hw.rates |= SNDRV_PCM_RATE_KNOT;
runtime->hw.rate_max = 128000;
}
snd_pcm_hw_constraint_minmax(runtime, SNDRV_PCM_HW_PARAM_BUFFER_SIZE, 0, 0x10000);
return 0;
}
static int snd_cmipci_playback2_open(struct snd_pcm_substream *substream)
{
struct cmipci *cm = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
int err;
if ((err = open_device_check(cm, CM_OPEN_PLAYBACK2, substream)) < 0)
return err;
runtime->hw = snd_cmipci_playback2;
mutex_lock(&cm->open_mutex);
if (! cm->opened[CM_CH_PLAY]) {
if (cm->can_multi_ch) {
runtime->hw.channels_max = cm->max_channels;
if (cm->max_channels == 4)
snd_pcm_hw_constraint_list(runtime, 0, SNDRV_PCM_HW_PARAM_CHANNELS, &hw_constraints_channels_4);
else if (cm->max_channels == 6)
snd_pcm_hw_constraint_list(runtime, 0, SNDRV_PCM_HW_PARAM_CHANNELS, &hw_constraints_channels_6);
else if (cm->max_channels == 8)
snd_pcm_hw_constraint_list(runtime, 0, SNDRV_PCM_HW_PARAM_CHANNELS, &hw_constraints_channels_8);
}
}
mutex_unlock(&cm->open_mutex);
if (cm->chip_version == 68) {
runtime->hw.rates |= SNDRV_PCM_RATE_88200 |
SNDRV_PCM_RATE_96000;
runtime->hw.rate_max = 96000;
} else if (cm->chip_version == 55) {
err = snd_pcm_hw_constraint_list(runtime, 0,
SNDRV_PCM_HW_PARAM_RATE, &hw_constraints_rates);
if (err < 0)
return err;
runtime->hw.rates |= SNDRV_PCM_RATE_KNOT;
runtime->hw.rate_max = 128000;
}
snd_pcm_hw_constraint_minmax(runtime, SNDRV_PCM_HW_PARAM_BUFFER_SIZE, 0, 0x10000);
return 0;
}
static int snd_cmipci_playback_spdif_open(struct snd_pcm_substream *substream)
{
struct cmipci *cm = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
int err;
if ((err = open_device_check(cm, CM_OPEN_SPDIF_PLAYBACK, substream)) < 0)
return err;
if (cm->can_ac3_hw) {
runtime->hw = snd_cmipci_playback_spdif;
if (cm->chip_version >= 37) {
runtime->hw.formats |= SNDRV_PCM_FMTBIT_S32_LE;
snd_pcm_hw_constraint_msbits(runtime, 0, 32, 24);
}
if (cm->can_96k) {
runtime->hw.rates |= SNDRV_PCM_RATE_88200 |
SNDRV_PCM_RATE_96000;
runtime->hw.rate_max = 96000;
}
} else {
runtime->hw = snd_cmipci_playback_iec958_subframe;
}
snd_pcm_hw_constraint_minmax(runtime, SNDRV_PCM_HW_PARAM_BUFFER_SIZE, 0, 0x40000);
cm->dig_pcm_status = cm->dig_status;
return 0;
}
static int snd_cmipci_capture_spdif_open(struct snd_pcm_substream *substream)
{
struct cmipci *cm = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
int err;
if ((err = open_device_check(cm, CM_OPEN_SPDIF_CAPTURE, substream)) < 0)
return err;
runtime->hw = snd_cmipci_capture_spdif;
if (cm->can_96k && !(cm->chip_version == 68)) {
runtime->hw.rates |= SNDRV_PCM_RATE_88200 |
SNDRV_PCM_RATE_96000;
runtime->hw.rate_max = 96000;
}
snd_pcm_hw_constraint_minmax(runtime, SNDRV_PCM_HW_PARAM_BUFFER_SIZE, 0, 0x40000);
return 0;
}
static int snd_cmipci_playback_close(struct snd_pcm_substream *substream)
{
struct cmipci *cm = snd_pcm_substream_chip(substream);
close_device_check(cm, CM_OPEN_PLAYBACK);
return 0;
}
static int snd_cmipci_capture_close(struct snd_pcm_substream *substream)
{
struct cmipci *cm = snd_pcm_substream_chip(substream);
close_device_check(cm, CM_OPEN_CAPTURE);
return 0;
}
static int snd_cmipci_playback2_close(struct snd_pcm_substream *substream)
{
struct cmipci *cm = snd_pcm_substream_chip(substream);
close_device_check(cm, CM_OPEN_PLAYBACK2);
close_device_check(cm, CM_OPEN_PLAYBACK_MULTI);
return 0;
}
static int snd_cmipci_playback_spdif_close(struct snd_pcm_substream *substream)
{
struct cmipci *cm = snd_pcm_substream_chip(substream);
close_device_check(cm, CM_OPEN_SPDIF_PLAYBACK);
return 0;
}
static int snd_cmipci_capture_spdif_close(struct snd_pcm_substream *substream)
{
struct cmipci *cm = snd_pcm_substream_chip(substream);
close_device_check(cm, CM_OPEN_SPDIF_CAPTURE);
return 0;
}
static int snd_cmipci_pcm_new(struct cmipci *cm, int device)
{
struct snd_pcm *pcm;
int err;
err = snd_pcm_new(cm->card, cm->card->driver, device, 1, 1, &pcm);
if (err < 0)
return err;
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_PLAYBACK, &snd_cmipci_playback_ops);
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_CAPTURE, &snd_cmipci_capture_ops);
pcm->private_data = cm;
pcm->info_flags = 0;
strcpy(pcm->name, "C-Media PCI DAC/ADC");
cm->pcm = pcm;
snd_pcm_lib_preallocate_pages_for_all(pcm, SNDRV_DMA_TYPE_DEV,
snd_dma_pci_data(cm->pci), 64*1024, 128*1024);
return 0;
}
static int snd_cmipci_pcm2_new(struct cmipci *cm, int device)
{
struct snd_pcm *pcm;
int err;
err = snd_pcm_new(cm->card, cm->card->driver, device, 1, 0, &pcm);
if (err < 0)
return err;
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_PLAYBACK, &snd_cmipci_playback2_ops);
pcm->private_data = cm;
pcm->info_flags = 0;
strcpy(pcm->name, "C-Media PCI 2nd DAC");
cm->pcm2 = pcm;
snd_pcm_lib_preallocate_pages_for_all(pcm, SNDRV_DMA_TYPE_DEV,
snd_dma_pci_data(cm->pci), 64*1024, 128*1024);
return 0;
}
static int snd_cmipci_pcm_spdif_new(struct cmipci *cm, int device)
{
struct snd_pcm *pcm;
int err;
err = snd_pcm_new(cm->card, cm->card->driver, device, 1, 1, &pcm);
if (err < 0)
return err;
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_PLAYBACK, &snd_cmipci_playback_spdif_ops);
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_CAPTURE, &snd_cmipci_capture_spdif_ops);
pcm->private_data = cm;
pcm->info_flags = 0;
strcpy(pcm->name, "C-Media PCI IEC958");
cm->pcm_spdif = pcm;
snd_pcm_lib_preallocate_pages_for_all(pcm, SNDRV_DMA_TYPE_DEV,
snd_dma_pci_data(cm->pci), 64*1024, 128*1024);
err = snd_pcm_add_chmap_ctls(pcm, SNDRV_PCM_STREAM_PLAYBACK,
snd_pcm_alt_chmaps, cm->max_channels, 0,
NULL);
if (err < 0)
return err;
return 0;
}
static void snd_cmipci_mixer_write(struct cmipci *s, unsigned char idx, unsigned char data)
{
outb(idx, s->iobase + CM_REG_SB16_ADDR);
outb(data, s->iobase + CM_REG_SB16_DATA);
}
static unsigned char snd_cmipci_mixer_read(struct cmipci *s, unsigned char idx)
{
unsigned char v;
outb(idx, s->iobase + CM_REG_SB16_ADDR);
v = inb(s->iobase + CM_REG_SB16_DATA);
return v;
}
static void cmipci_sb_reg_decode(struct cmipci_sb_reg *r, unsigned long val)
{
r->left_reg = val & 0xff;
r->right_reg = (val >> 8) & 0xff;
r->left_shift = (val >> 16) & 0x07;
r->right_shift = (val >> 19) & 0x07;
r->invert = (val >> 22) & 1;
r->stereo = (val >> 23) & 1;
r->mask = (val >> 24) & 0xff;
}
static int snd_cmipci_info_volume(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
struct cmipci_sb_reg reg;
cmipci_sb_reg_decode(&reg, kcontrol->private_value);
uinfo->type = reg.mask == 1 ? SNDRV_CTL_ELEM_TYPE_BOOLEAN : SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = reg.stereo + 1;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = reg.mask;
return 0;
}
static int snd_cmipci_get_volume(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct cmipci *cm = snd_kcontrol_chip(kcontrol);
struct cmipci_sb_reg reg;
int val;
cmipci_sb_reg_decode(&reg, kcontrol->private_value);
spin_lock_irq(&cm->reg_lock);
val = (snd_cmipci_mixer_read(cm, reg.left_reg) >> reg.left_shift) & reg.mask;
if (reg.invert)
val = reg.mask - val;
ucontrol->value.integer.value[0] = val;
if (reg.stereo) {
val = (snd_cmipci_mixer_read(cm, reg.right_reg) >> reg.right_shift) & reg.mask;
if (reg.invert)
val = reg.mask - val;
ucontrol->value.integer.value[1] = val;
}
spin_unlock_irq(&cm->reg_lock);
return 0;
}
static int snd_cmipci_put_volume(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct cmipci *cm = snd_kcontrol_chip(kcontrol);
struct cmipci_sb_reg reg;
int change;
int left, right, oleft, oright;
cmipci_sb_reg_decode(&reg, kcontrol->private_value);
left = ucontrol->value.integer.value[0] & reg.mask;
if (reg.invert)
left = reg.mask - left;
left <<= reg.left_shift;
if (reg.stereo) {
right = ucontrol->value.integer.value[1] & reg.mask;
if (reg.invert)
right = reg.mask - right;
right <<= reg.right_shift;
} else
right = 0;
spin_lock_irq(&cm->reg_lock);
oleft = snd_cmipci_mixer_read(cm, reg.left_reg);
left |= oleft & ~(reg.mask << reg.left_shift);
change = left != oleft;
if (reg.stereo) {
if (reg.left_reg != reg.right_reg) {
snd_cmipci_mixer_write(cm, reg.left_reg, left);
oright = snd_cmipci_mixer_read(cm, reg.right_reg);
} else
oright = left;
right |= oright & ~(reg.mask << reg.right_shift);
change |= right != oright;
snd_cmipci_mixer_write(cm, reg.right_reg, right);
} else
snd_cmipci_mixer_write(cm, reg.left_reg, left);
spin_unlock_irq(&cm->reg_lock);
return change;
}
static int snd_cmipci_info_input_sw(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_BOOLEAN;
uinfo->count = 4;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = 1;
return 0;
}
static int snd_cmipci_get_input_sw(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct cmipci *cm = snd_kcontrol_chip(kcontrol);
struct cmipci_sb_reg reg;
int val1, val2;
cmipci_sb_reg_decode(&reg, kcontrol->private_value);
spin_lock_irq(&cm->reg_lock);
val1 = snd_cmipci_mixer_read(cm, reg.left_reg);
val2 = snd_cmipci_mixer_read(cm, reg.right_reg);
spin_unlock_irq(&cm->reg_lock);
ucontrol->value.integer.value[0] = (val1 >> reg.left_shift) & 1;
ucontrol->value.integer.value[1] = (val2 >> reg.left_shift) & 1;
ucontrol->value.integer.value[2] = (val1 >> reg.right_shift) & 1;
ucontrol->value.integer.value[3] = (val2 >> reg.right_shift) & 1;
return 0;
}
static int snd_cmipci_put_input_sw(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct cmipci *cm = snd_kcontrol_chip(kcontrol);
struct cmipci_sb_reg reg;
int change;
int val1, val2, oval1, oval2;
cmipci_sb_reg_decode(&reg, kcontrol->private_value);
spin_lock_irq(&cm->reg_lock);
oval1 = snd_cmipci_mixer_read(cm, reg.left_reg);
oval2 = snd_cmipci_mixer_read(cm, reg.right_reg);
val1 = oval1 & ~((1 << reg.left_shift) | (1 << reg.right_shift));
val2 = oval2 & ~((1 << reg.left_shift) | (1 << reg.right_shift));
val1 |= (ucontrol->value.integer.value[0] & 1) << reg.left_shift;
val2 |= (ucontrol->value.integer.value[1] & 1) << reg.left_shift;
val1 |= (ucontrol->value.integer.value[2] & 1) << reg.right_shift;
val2 |= (ucontrol->value.integer.value[3] & 1) << reg.right_shift;
change = val1 != oval1 || val2 != oval2;
snd_cmipci_mixer_write(cm, reg.left_reg, val1);
snd_cmipci_mixer_write(cm, reg.right_reg, val2);
spin_unlock_irq(&cm->reg_lock);
return change;
}
static int snd_cmipci_info_native_mixer(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
struct cmipci_sb_reg reg;
cmipci_sb_reg_decode(&reg, kcontrol->private_value);
uinfo->type = reg.mask == 1 ? SNDRV_CTL_ELEM_TYPE_BOOLEAN : SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = reg.stereo + 1;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = reg.mask;
return 0;
}
static int snd_cmipci_get_native_mixer(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct cmipci *cm = snd_kcontrol_chip(kcontrol);
struct cmipci_sb_reg reg;
unsigned char oreg, val;
cmipci_sb_reg_decode(&reg, kcontrol->private_value);
spin_lock_irq(&cm->reg_lock);
oreg = inb(cm->iobase + reg.left_reg);
val = (oreg >> reg.left_shift) & reg.mask;
if (reg.invert)
val = reg.mask - val;
ucontrol->value.integer.value[0] = val;
if (reg.stereo) {
val = (oreg >> reg.right_shift) & reg.mask;
if (reg.invert)
val = reg.mask - val;
ucontrol->value.integer.value[1] = val;
}
spin_unlock_irq(&cm->reg_lock);
return 0;
}
static int snd_cmipci_put_native_mixer(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct cmipci *cm = snd_kcontrol_chip(kcontrol);
struct cmipci_sb_reg reg;
unsigned char oreg, nreg, val;
cmipci_sb_reg_decode(&reg, kcontrol->private_value);
spin_lock_irq(&cm->reg_lock);
oreg = inb(cm->iobase + reg.left_reg);
val = ucontrol->value.integer.value[0] & reg.mask;
if (reg.invert)
val = reg.mask - val;
nreg = oreg & ~(reg.mask << reg.left_shift);
nreg |= (val << reg.left_shift);
if (reg.stereo) {
val = ucontrol->value.integer.value[1] & reg.mask;
if (reg.invert)
val = reg.mask - val;
nreg &= ~(reg.mask << reg.right_shift);
nreg |= (val << reg.right_shift);
}
outb(nreg, cm->iobase + reg.left_reg);
spin_unlock_irq(&cm->reg_lock);
return (nreg != oreg);
}
static int snd_cmipci_get_native_mixer_sensitive(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
return snd_cmipci_get_native_mixer(kcontrol, ucontrol);
}
static int snd_cmipci_put_native_mixer_sensitive(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct cmipci *cm = snd_kcontrol_chip(kcontrol);
if (cm->mixer_insensitive) {
return 0;
}
return snd_cmipci_put_native_mixer(kcontrol, ucontrol);
}
static int _snd_cmipci_uswitch_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol,
struct cmipci_switch_args *args)
{
unsigned int val;
struct cmipci *cm = snd_kcontrol_chip(kcontrol);
spin_lock_irq(&cm->reg_lock);
if (args->ac3_sensitive && cm->mixer_insensitive) {
ucontrol->value.integer.value[0] = 0;
spin_unlock_irq(&cm->reg_lock);
return 0;
}
if (args->is_byte)
val = inb(cm->iobase + args->reg);
else
val = snd_cmipci_read(cm, args->reg);
ucontrol->value.integer.value[0] = ((val & args->mask) == args->mask_on) ? 1 : 0;
spin_unlock_irq(&cm->reg_lock);
return 0;
}
static int snd_cmipci_uswitch_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct cmipci_switch_args *args;
args = (struct cmipci_switch_args *)kcontrol->private_value;
if (snd_BUG_ON(!args))
return -EINVAL;
return _snd_cmipci_uswitch_get(kcontrol, ucontrol, args);
}
static int _snd_cmipci_uswitch_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol,
struct cmipci_switch_args *args)
{
unsigned int val;
int change;
struct cmipci *cm = snd_kcontrol_chip(kcontrol);
spin_lock_irq(&cm->reg_lock);
if (args->ac3_sensitive && cm->mixer_insensitive) {
spin_unlock_irq(&cm->reg_lock);
return 0;
}
if (args->is_byte)
val = inb(cm->iobase + args->reg);
else
val = snd_cmipci_read(cm, args->reg);
change = (val & args->mask) != (ucontrol->value.integer.value[0] ?
args->mask_on : (args->mask & ~args->mask_on));
if (change) {
val &= ~args->mask;
if (ucontrol->value.integer.value[0])
val |= args->mask_on;
else
val |= (args->mask & ~args->mask_on);
if (args->is_byte)
outb((unsigned char)val, cm->iobase + args->reg);
else
snd_cmipci_write(cm, args->reg, val);
}
spin_unlock_irq(&cm->reg_lock);
return change;
}
static int snd_cmipci_uswitch_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct cmipci_switch_args *args;
args = (struct cmipci_switch_args *)kcontrol->private_value;
if (snd_BUG_ON(!args))
return -EINVAL;
return _snd_cmipci_uswitch_put(kcontrol, ucontrol, args);
}
static int snd_cmipci_spdout_enable_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
int changed;
changed = _snd_cmipci_uswitch_get(kcontrol, ucontrol, &cmipci_switch_arg_spdif_enable);
changed |= _snd_cmipci_uswitch_get(kcontrol, ucontrol, &cmipci_switch_arg_spdo2dac);
return changed;
}
static int snd_cmipci_spdout_enable_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct cmipci *chip = snd_kcontrol_chip(kcontrol);
int changed;
changed = _snd_cmipci_uswitch_put(kcontrol, ucontrol, &cmipci_switch_arg_spdif_enable);
changed |= _snd_cmipci_uswitch_put(kcontrol, ucontrol, &cmipci_switch_arg_spdo2dac);
if (changed) {
if (ucontrol->value.integer.value[0]) {
if (chip->spdif_playback_avail)
snd_cmipci_set_bit(chip, CM_REG_FUNCTRL1, CM_PLAYBACK_SPDF);
} else {
if (chip->spdif_playback_avail)
snd_cmipci_clear_bit(chip, CM_REG_FUNCTRL1, CM_PLAYBACK_SPDF);
}
}
chip->spdif_playback_enabled = ucontrol->value.integer.value[0];
return changed;
}
static int snd_cmipci_line_in_mode_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
struct cmipci *cm = snd_kcontrol_chip(kcontrol);
static const char *const texts[3] = {
"Line-In", "Rear Output", "Bass Output"
};
return snd_ctl_enum_info(uinfo, 1,
cm->chip_version >= 39 ? 3 : 2, texts);
}
static inline unsigned int get_line_in_mode(struct cmipci *cm)
{
unsigned int val;
if (cm->chip_version >= 39) {
val = snd_cmipci_read(cm, CM_REG_LEGACY_CTRL);
if (val & (CM_CENTR2LIN | CM_BASE2LIN))
return 2;
}
val = snd_cmipci_read_b(cm, CM_REG_MIXER1);
if (val & CM_REAR2LIN)
return 1;
return 0;
}
static int snd_cmipci_line_in_mode_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct cmipci *cm = snd_kcontrol_chip(kcontrol);
spin_lock_irq(&cm->reg_lock);
ucontrol->value.enumerated.item[0] = get_line_in_mode(cm);
spin_unlock_irq(&cm->reg_lock);
return 0;
}
static int snd_cmipci_line_in_mode_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct cmipci *cm = snd_kcontrol_chip(kcontrol);
int change;
spin_lock_irq(&cm->reg_lock);
if (ucontrol->value.enumerated.item[0] == 2)
change = snd_cmipci_set_bit(cm, CM_REG_LEGACY_CTRL, CM_CENTR2LIN | CM_BASE2LIN);
else
change = snd_cmipci_clear_bit(cm, CM_REG_LEGACY_CTRL, CM_CENTR2LIN | CM_BASE2LIN);
if (ucontrol->value.enumerated.item[0] == 1)
change |= snd_cmipci_set_bit_b(cm, CM_REG_MIXER1, CM_REAR2LIN);
else
change |= snd_cmipci_clear_bit_b(cm, CM_REG_MIXER1, CM_REAR2LIN);
spin_unlock_irq(&cm->reg_lock);
return change;
}
static int snd_cmipci_mic_in_mode_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
static const char *const texts[2] = { "Mic-In", "Center/LFE Output" };
return snd_ctl_enum_info(uinfo, 1, 2, texts);
}
static int snd_cmipci_mic_in_mode_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct cmipci *cm = snd_kcontrol_chip(kcontrol);
spin_lock_irq(&cm->reg_lock);
ucontrol->value.enumerated.item[0] =
(snd_cmipci_read_b(cm, CM_REG_MISC) & CM_SPDIF_INVERSE) ? 1 : 0;
spin_unlock_irq(&cm->reg_lock);
return 0;
}
static int snd_cmipci_mic_in_mode_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct cmipci *cm = snd_kcontrol_chip(kcontrol);
int change;
spin_lock_irq(&cm->reg_lock);
if (ucontrol->value.enumerated.item[0])
change = snd_cmipci_set_bit_b(cm, CM_REG_MISC, CM_SPDIF_INVERSE);
else
change = snd_cmipci_clear_bit_b(cm, CM_REG_MISC, CM_SPDIF_INVERSE);
spin_unlock_irq(&cm->reg_lock);
return change;
}
static int snd_cmipci_mixer_new(struct cmipci *cm, int pcm_spdif_device)
{
struct snd_card *card;
struct snd_kcontrol_new *sw;
struct snd_kcontrol *kctl;
unsigned int idx;
int err;
if (snd_BUG_ON(!cm || !cm->card))
return -EINVAL;
card = cm->card;
strcpy(card->mixername, "CMedia PCI");
spin_lock_irq(&cm->reg_lock);
snd_cmipci_mixer_write(cm, 0x00, 0x00);
spin_unlock_irq(&cm->reg_lock);
for (idx = 0; idx < ARRAY_SIZE(snd_cmipci_mixers); idx++) {
if (cm->chip_version == 68) {
if (!strcmp(snd_cmipci_mixers[idx].name,
"PCM Playback Volume"))
continue;
}
if ((err = snd_ctl_add(card, snd_ctl_new1(&snd_cmipci_mixers[idx], cm))) < 0)
return err;
}
sw = snd_cmipci_mixer_switches;
for (idx = 0; idx < ARRAY_SIZE(snd_cmipci_mixer_switches); idx++, sw++) {
err = snd_ctl_add(cm->card, snd_ctl_new1(sw, cm));
if (err < 0)
return err;
}
if (! cm->can_multi_ch) {
err = snd_ctl_add(cm->card, snd_ctl_new1(&snd_cmipci_nomulti_switch, cm));
if (err < 0)
return err;
}
if (cm->device == PCI_DEVICE_ID_CMEDIA_CM8738 ||
cm->device == PCI_DEVICE_ID_CMEDIA_CM8738B) {
sw = snd_cmipci_8738_mixer_switches;
for (idx = 0; idx < ARRAY_SIZE(snd_cmipci_8738_mixer_switches); idx++, sw++) {
err = snd_ctl_add(cm->card, snd_ctl_new1(sw, cm));
if (err < 0)
return err;
}
if (cm->can_ac3_hw) {
if ((err = snd_ctl_add(card, kctl = snd_ctl_new1(&snd_cmipci_spdif_default, cm))) < 0)
return err;
kctl->id.device = pcm_spdif_device;
if ((err = snd_ctl_add(card, kctl = snd_ctl_new1(&snd_cmipci_spdif_mask, cm))) < 0)
return err;
kctl->id.device = pcm_spdif_device;
if ((err = snd_ctl_add(card, kctl = snd_ctl_new1(&snd_cmipci_spdif_stream, cm))) < 0)
return err;
kctl->id.device = pcm_spdif_device;
}
if (cm->chip_version <= 37) {
sw = snd_cmipci_old_mixer_switches;
for (idx = 0; idx < ARRAY_SIZE(snd_cmipci_old_mixer_switches); idx++, sw++) {
err = snd_ctl_add(cm->card, snd_ctl_new1(sw, cm));
if (err < 0)
return err;
}
}
}
if (cm->chip_version >= 39) {
sw = snd_cmipci_extra_mixer_switches;
for (idx = 0; idx < ARRAY_SIZE(snd_cmipci_extra_mixer_switches); idx++, sw++) {
err = snd_ctl_add(cm->card, snd_ctl_new1(sw, cm));
if (err < 0)
return err;
}
}
if (cm->chip_version < 39) {
err = snd_ctl_add(cm->card,
snd_ctl_new1(&snd_cmipci_modem_switch, cm));
if (err < 0)
return err;
}
for (idx = 0; idx < CM_SAVED_MIXERS; idx++) {
struct snd_ctl_elem_id elem_id;
struct snd_kcontrol *ctl;
memset(&elem_id, 0, sizeof(elem_id));
elem_id.iface = SNDRV_CTL_ELEM_IFACE_MIXER;
strcpy(elem_id.name, cm_saved_mixer[idx].name);
ctl = snd_ctl_find_id(cm->card, &elem_id);
if (ctl)
cm->mixer_res_ctl[idx] = ctl;
}
return 0;
}
static void snd_cmipci_proc_read(struct snd_info_entry *entry,
struct snd_info_buffer *buffer)
{
struct cmipci *cm = entry->private_data;
int i, v;
snd_iprintf(buffer, "%s\n", cm->card->longname);
for (i = 0; i < 0x94; i++) {
if (i == 0x28)
i = 0x90;
v = inb(cm->iobase + i);
if (i % 4 == 0)
snd_iprintf(buffer, "\n%02x:", i);
snd_iprintf(buffer, " %02x", v);
}
snd_iprintf(buffer, "\n");
}
static void snd_cmipci_proc_init(struct cmipci *cm)
{
struct snd_info_entry *entry;
if (! snd_card_proc_new(cm->card, "cmipci", &entry))
snd_info_set_text_ops(entry, cm, snd_cmipci_proc_read);
}
static inline void snd_cmipci_proc_init(struct cmipci *cm) {}
static void query_chip(struct cmipci *cm)
{
unsigned int detect;
detect = snd_cmipci_read(cm, CM_REG_INT_HLDCLR) & CM_CHIP_MASK2;
if (! detect) {
detect = snd_cmipci_read(cm, CM_REG_CHFORMAT) & CM_CHIP_MASK1;
switch (detect) {
case 0:
cm->chip_version = 33;
if (cm->do_soft_ac3)
cm->can_ac3_sw = 1;
else
cm->can_ac3_hw = 1;
break;
case CM_CHIP_037:
cm->chip_version = 37;
cm->can_ac3_hw = 1;
break;
default:
cm->chip_version = 39;
cm->can_ac3_hw = 1;
break;
}
cm->max_channels = 2;
} else {
if (detect & CM_CHIP_039) {
cm->chip_version = 39;
if (detect & CM_CHIP_039_6CH)
cm->max_channels = 6;
else
cm->max_channels = 4;
} else if (detect & CM_CHIP_8768) {
cm->chip_version = 68;
cm->max_channels = 8;
cm->can_96k = 1;
} else {
cm->chip_version = 55;
cm->max_channels = 6;
cm->can_96k = 1;
}
cm->can_ac3_hw = 1;
cm->can_multi_ch = 1;
}
}
static int snd_cmipci_create_gameport(struct cmipci *cm, int dev)
{
static int ports[] = { 0x201, 0x200, 0 };
struct gameport *gp;
struct resource *r = NULL;
int i, io_port = 0;
if (joystick_port[dev] == 0)
return -ENODEV;
if (joystick_port[dev] == 1) {
for (i = 0; ports[i]; i++) {
io_port = ports[i];
r = request_region(io_port, 1, "CMIPCI gameport");
if (r)
break;
}
} else {
io_port = joystick_port[dev];
r = request_region(io_port, 1, "CMIPCI gameport");
}
if (!r) {
printk(KERN_WARNING "cmipci: cannot reserve joystick ports\n");
return -EBUSY;
}
cm->gameport = gp = gameport_allocate_port();
if (!gp) {
printk(KERN_ERR "cmipci: cannot allocate memory for gameport\n");
release_and_free_resource(r);
return -ENOMEM;
}
gameport_set_name(gp, "C-Media Gameport");
gameport_set_phys(gp, "pci%s/gameport0", pci_name(cm->pci));
gameport_set_dev_parent(gp, &cm->pci->dev);
gp->io = io_port;
gameport_set_port_data(gp, r);
snd_cmipci_set_bit(cm, CM_REG_FUNCTRL1, CM_JYSTK_EN);
gameport_register_port(cm->gameport);
return 0;
}
static void snd_cmipci_free_gameport(struct cmipci *cm)
{
if (cm->gameport) {
struct resource *r = gameport_get_port_data(cm->gameport);
gameport_unregister_port(cm->gameport);
cm->gameport = NULL;
snd_cmipci_clear_bit(cm, CM_REG_FUNCTRL1, CM_JYSTK_EN);
release_and_free_resource(r);
}
}
static inline int snd_cmipci_create_gameport(struct cmipci *cm, int dev) { return -ENOSYS; }
static inline void snd_cmipci_free_gameport(struct cmipci *cm) { }
static int snd_cmipci_free(struct cmipci *cm)
{
if (cm->irq >= 0) {
snd_cmipci_clear_bit(cm, CM_REG_MISC_CTRL, CM_FM_EN);
snd_cmipci_clear_bit(cm, CM_REG_LEGACY_CTRL, CM_ENSPDOUT);
snd_cmipci_write(cm, CM_REG_INT_HLDCLR, 0);
snd_cmipci_ch_reset(cm, CM_CH_PLAY);
snd_cmipci_ch_reset(cm, CM_CH_CAPT);
snd_cmipci_write(cm, CM_REG_FUNCTRL0, 0);
snd_cmipci_write(cm, CM_REG_FUNCTRL1, 0);
snd_cmipci_mixer_write(cm, 0, 0);
free_irq(cm->irq, cm);
}
snd_cmipci_free_gameport(cm);
pci_release_regions(cm->pci);
pci_disable_device(cm->pci);
kfree(cm);
return 0;
}
static int snd_cmipci_dev_free(struct snd_device *device)
{
struct cmipci *cm = device->device_data;
return snd_cmipci_free(cm);
}
static int snd_cmipci_create_fm(struct cmipci *cm, long fm_port)
{
long iosynth;
unsigned int val;
struct snd_opl3 *opl3;
int err;
if (!fm_port)
goto disable_fm;
if (cm->chip_version >= 39) {
iosynth = cm->iobase + CM_REG_FM_PCI;
err = snd_opl3_create(cm->card, iosynth, iosynth + 2,
OPL3_HW_OPL3, 1, &opl3);
} else {
err = -EIO;
}
if (err < 0) {
val = snd_cmipci_read(cm, CM_REG_LEGACY_CTRL) & ~CM_FMSEL_MASK;
iosynth = fm_port;
switch (iosynth) {
case 0x3E8: val |= CM_FMSEL_3E8; break;
case 0x3E0: val |= CM_FMSEL_3E0; break;
case 0x3C8: val |= CM_FMSEL_3C8; break;
case 0x388: val |= CM_FMSEL_388; break;
default:
goto disable_fm;
}
snd_cmipci_write(cm, CM_REG_LEGACY_CTRL, val);
snd_cmipci_set_bit(cm, CM_REG_MISC_CTRL, CM_FM_EN);
if (snd_opl3_create(cm->card, iosynth, iosynth + 2,
OPL3_HW_OPL3, 0, &opl3) < 0) {
printk(KERN_ERR "cmipci: no OPL device at %#lx, "
"skipping...\n", iosynth);
goto disable_fm;
}
}
if ((err = snd_opl3_hwdep_new(opl3, 0, 1, NULL)) < 0) {
printk(KERN_ERR "cmipci: cannot create OPL3 hwdep\n");
return err;
}
return 0;
disable_fm:
snd_cmipci_clear_bit(cm, CM_REG_LEGACY_CTRL, CM_FMSEL_MASK);
snd_cmipci_clear_bit(cm, CM_REG_MISC_CTRL, CM_FM_EN);
return 0;
}
static int snd_cmipci_create(struct snd_card *card, struct pci_dev *pci,
int dev, struct cmipci **rcmipci)
{
struct cmipci *cm;
int err;
static struct snd_device_ops ops = {
.dev_free = snd_cmipci_dev_free,
};
unsigned int val;
long iomidi = 0;
int integrated_midi = 0;
char modelstr[16];
int pcm_index, pcm_spdif_index;
static DEFINE_PCI_DEVICE_TABLE(intel_82437vx) = {
{ PCI_DEVICE(PCI_VENDOR_ID_INTEL, PCI_DEVICE_ID_INTEL_82437VX) },
{ },
};
*rcmipci = NULL;
if ((err = pci_enable_device(pci)) < 0)
return err;
cm = kzalloc(sizeof(*cm), GFP_KERNEL);
if (cm == NULL) {
pci_disable_device(pci);
return -ENOMEM;
}
spin_lock_init(&cm->reg_lock);
mutex_init(&cm->open_mutex);
cm->device = pci->device;
cm->card = card;
cm->pci = pci;
cm->irq = -1;
cm->channel[0].ch = 0;
cm->channel[1].ch = 1;
cm->channel[0].is_dac = cm->channel[1].is_dac = 1;
if ((err = pci_request_regions(pci, card->driver)) < 0) {
kfree(cm);
pci_disable_device(pci);
return err;
}
cm->iobase = pci_resource_start(pci, 0);
if (request_irq(pci->irq, snd_cmipci_interrupt,
IRQF_SHARED, KBUILD_MODNAME, cm)) {
snd_printk(KERN_ERR "unable to grab IRQ %d\n", pci->irq);
snd_cmipci_free(cm);
return -EBUSY;
}
cm->irq = pci->irq;
pci_set_master(cm->pci);
cm->chip_version = 0;
cm->max_channels = 2;
cm->do_soft_ac3 = soft_ac3[dev];
if (pci->device != PCI_DEVICE_ID_CMEDIA_CM8338A &&
pci->device != PCI_DEVICE_ID_CMEDIA_CM8338B)
query_chip(cm);
if (cm->can_multi_ch)
sprintf(cm->card->driver + strlen(cm->card->driver),
"-MC%d", cm->max_channels);
else if (cm->can_ac3_sw)
strcpy(cm->card->driver + strlen(cm->card->driver), "-SWIEC");
cm->dig_status = SNDRV_PCM_DEFAULT_CON_SPDIF;
cm->dig_pcm_status = SNDRV_PCM_DEFAULT_CON_SPDIF;
#if CM_CH_PLAY == 1
cm->ctrl = CM_CHADC0;
#else
cm->ctrl = CM_CHADC1;
#endif
snd_cmipci_set_bit(cm, CM_REG_MISC_CTRL, CM_RESET);
snd_cmipci_clear_bit(cm, CM_REG_MISC_CTRL, CM_RESET);
snd_cmipci_write(cm, CM_REG_INT_HLDCLR, 0);
snd_cmipci_ch_reset(cm, CM_CH_PLAY);
snd_cmipci_ch_reset(cm, CM_CH_CAPT);
snd_cmipci_write(cm, CM_REG_FUNCTRL0, 0);
snd_cmipci_write(cm, CM_REG_FUNCTRL1, 0);
snd_cmipci_write(cm, CM_REG_CHFORMAT, 0);
snd_cmipci_set_bit(cm, CM_REG_MISC_CTRL, CM_ENDBDAC|CM_N4SPK3D);
#if CM_CH_PLAY == 1
snd_cmipci_set_bit(cm, CM_REG_MISC_CTRL, CM_XCHGDAC);
#else
snd_cmipci_clear_bit(cm, CM_REG_MISC_CTRL, CM_XCHGDAC);
#endif
if (cm->chip_version) {
snd_cmipci_write_b(cm, CM_REG_EXT_MISC, 0x20);
snd_cmipci_write_b(cm, CM_REG_EXT_MISC + 1, 0x09);
}
snd_cmipci_set_bit(cm, CM_REG_FUNCTRL1, CM_BREQ);
switch (pci->device) {
case PCI_DEVICE_ID_CMEDIA_CM8738:
case PCI_DEVICE_ID_CMEDIA_CM8738B:
if (!pci_dev_present(intel_82437vx))
snd_cmipci_set_bit(cm, CM_REG_MISC_CTRL, CM_TXVX);
break;
default:
break;
}
if (cm->chip_version < 68) {
val = pci->device < 0x110 ? 8338 : 8738;
} else {
switch (snd_cmipci_read_b(cm, CM_REG_INT_HLDCLR + 3) & 0x03) {
case 0:
val = 8769;
break;
case 2:
val = 8762;
break;
default:
switch ((pci->subsystem_vendor << 16) |
pci->subsystem_device) {
case 0x13f69761:
case 0x584d3741:
case 0x584d3751:
case 0x584d3761:
case 0x584d3771:
case 0x72848384:
val = 8770;
break;
default:
val = 8768;
break;
}
}
}
sprintf(card->shortname, "C-Media CMI%d", val);
if (cm->chip_version < 68)
sprintf(modelstr, " (model %d)", cm->chip_version);
else
modelstr[0] = '\0';
sprintf(card->longname, "%s%s at %#lx, irq %i",
card->shortname, modelstr, cm->iobase, cm->irq);
if ((err = snd_device_new(card, SNDRV_DEV_LOWLEVEL, cm, &ops)) < 0) {
snd_cmipci_free(cm);
return err;
}
if (cm->chip_version >= 39) {
val = snd_cmipci_read_b(cm, CM_REG_MPU_PCI + 1);
if (val != 0x00 && val != 0xff) {
iomidi = cm->iobase + CM_REG_MPU_PCI;
integrated_midi = 1;
}
}
if (!integrated_midi) {
val = 0;
iomidi = mpu_port[dev];
switch (iomidi) {
case 0x320: val = CM_VMPU_320; break;
case 0x310: val = CM_VMPU_310; break;
case 0x300: val = CM_VMPU_300; break;
case 0x330: val = CM_VMPU_330; break;
default:
iomidi = 0; break;
}
if (iomidi > 0) {
snd_cmipci_write(cm, CM_REG_LEGACY_CTRL, val);
snd_cmipci_set_bit(cm, CM_REG_FUNCTRL1, CM_UART_EN);
if (inb(iomidi + 1) == 0xff) {
snd_printk(KERN_ERR "cannot enable MPU-401 port"
" at %#lx\n", iomidi);
snd_cmipci_clear_bit(cm, CM_REG_FUNCTRL1,
CM_UART_EN);
iomidi = 0;
}
}
}
if (cm->chip_version < 68) {
err = snd_cmipci_create_fm(cm, fm_port[dev]);
if (err < 0)
return err;
}
snd_cmipci_mixer_write(cm, 0, 0);
snd_cmipci_proc_init(cm);
pcm_index = pcm_spdif_index = 0;
if ((err = snd_cmipci_pcm_new(cm, pcm_index)) < 0)
return err;
pcm_index++;
if ((err = snd_cmipci_pcm2_new(cm, pcm_index)) < 0)
return err;
pcm_index++;
if (cm->can_ac3_hw || cm->can_ac3_sw) {
pcm_spdif_index = pcm_index;
if ((err = snd_cmipci_pcm_spdif_new(cm, pcm_index)) < 0)
return err;
}
if ((err = snd_cmipci_mixer_new(cm, pcm_spdif_index)) < 0)
return err;
if (iomidi > 0) {
if ((err = snd_mpu401_uart_new(card, 0, MPU401_HW_CMIPCI,
iomidi,
(integrated_midi ?
MPU401_INFO_INTEGRATED : 0) |
MPU401_INFO_IRQ_HOOK,
-1, &cm->rmidi)) < 0) {
printk(KERN_ERR "cmipci: no UART401 device at 0x%lx\n", iomidi);
}
}
#ifdef USE_VAR48KRATE
for (val = 0; val < ARRAY_SIZE(rates); val++)
snd_cmipci_set_pll(cm, rates[val], val);
snd_cmipci_set_bit(cm, CM_REG_MISC_CTRL, CM_SPDIF48K|CM_SPDF_AC97);
#endif
if (snd_cmipci_create_gameport(cm, dev) < 0)
snd_cmipci_clear_bit(cm, CM_REG_FUNCTRL1, CM_JYSTK_EN);
snd_card_set_dev(card, &pci->dev);
*rcmipci = cm;
return 0;
}
static int snd_cmipci_probe(struct pci_dev *pci,
const struct pci_device_id *pci_id)
{
static int dev;
struct snd_card *card;
struct cmipci *cm;
int err;
if (dev >= SNDRV_CARDS)
return -ENODEV;
if (! enable[dev]) {
dev++;
return -ENOENT;
}
err = snd_card_create(index[dev], id[dev], THIS_MODULE, 0, &card);
if (err < 0)
return err;
switch (pci->device) {
case PCI_DEVICE_ID_CMEDIA_CM8738:
case PCI_DEVICE_ID_CMEDIA_CM8738B:
strcpy(card->driver, "CMI8738");
break;
case PCI_DEVICE_ID_CMEDIA_CM8338A:
case PCI_DEVICE_ID_CMEDIA_CM8338B:
strcpy(card->driver, "CMI8338");
break;
default:
strcpy(card->driver, "CMIPCI");
break;
}
if ((err = snd_cmipci_create(card, pci, dev, &cm)) < 0) {
snd_card_free(card);
return err;
}
card->private_data = cm;
if ((err = snd_card_register(card)) < 0) {
snd_card_free(card);
return err;
}
pci_set_drvdata(pci, card);
dev++;
return 0;
}
static void snd_cmipci_remove(struct pci_dev *pci)
{
snd_card_free(pci_get_drvdata(pci));
pci_set_drvdata(pci, NULL);
}
static int snd_cmipci_suspend(struct device *dev)
{
struct pci_dev *pci = to_pci_dev(dev);
struct snd_card *card = dev_get_drvdata(dev);
struct cmipci *cm = card->private_data;
int i;
snd_power_change_state(card, SNDRV_CTL_POWER_D3hot);
snd_pcm_suspend_all(cm->pcm);
snd_pcm_suspend_all(cm->pcm2);
snd_pcm_suspend_all(cm->pcm_spdif);
for (i = 0; i < ARRAY_SIZE(saved_regs); i++)
cm->saved_regs[i] = snd_cmipci_read(cm, saved_regs[i]);
for (i = 0; i < ARRAY_SIZE(saved_mixers); i++)
cm->saved_mixers[i] = snd_cmipci_mixer_read(cm, saved_mixers[i]);
snd_cmipci_write(cm, CM_REG_INT_HLDCLR, 0);
pci_disable_device(pci);
pci_save_state(pci);
pci_set_power_state(pci, PCI_D3hot);
return 0;
}
static int snd_cmipci_resume(struct device *dev)
{
struct pci_dev *pci = to_pci_dev(dev);
struct snd_card *card = dev_get_drvdata(dev);
struct cmipci *cm = card->private_data;
int i;
pci_set_power_state(pci, PCI_D0);
pci_restore_state(pci);
if (pci_enable_device(pci) < 0) {
printk(KERN_ERR "cmipci: pci_enable_device failed, "
"disabling device\n");
snd_card_disconnect(card);
return -EIO;
}
pci_set_master(pci);
snd_cmipci_write(cm, CM_REG_INT_HLDCLR, 0);
snd_cmipci_ch_reset(cm, CM_CH_PLAY);
snd_cmipci_ch_reset(cm, CM_CH_CAPT);
snd_cmipci_mixer_write(cm, 0, 0);
for (i = 0; i < ARRAY_SIZE(saved_regs); i++)
snd_cmipci_write(cm, saved_regs[i], cm->saved_regs[i]);
for (i = 0; i < ARRAY_SIZE(saved_mixers); i++)
snd_cmipci_mixer_write(cm, saved_mixers[i], cm->saved_mixers[i]);
snd_power_change_state(card, SNDRV_CTL_POWER_D0);
return 0;
}
