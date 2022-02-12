static inline void snd_sonicvibes_setdmaa(struct sonicvibes * sonic,
unsigned int addr,
unsigned int count)
{
count--;
outl(addr, sonic->dmaa_port + SV_DMA_ADDR0);
outl(count, sonic->dmaa_port + SV_DMA_COUNT0);
outb(0x18, sonic->dmaa_port + SV_DMA_MODE);
#if 0
printk(KERN_DEBUG "program dmaa: addr = 0x%x, paddr = 0x%x\n",
addr, inl(sonic->dmaa_port + SV_DMA_ADDR0));
#endif
}
static inline void snd_sonicvibes_setdmac(struct sonicvibes * sonic,
unsigned int addr,
unsigned int count)
{
count >>= 1;
count--;
outl(addr, sonic->dmac_port + SV_DMA_ADDR0);
outl(count, sonic->dmac_port + SV_DMA_COUNT0);
outb(0x14, sonic->dmac_port + SV_DMA_MODE);
#if 0
printk(KERN_DEBUG "program dmac: addr = 0x%x, paddr = 0x%x\n",
addr, inl(sonic->dmac_port + SV_DMA_ADDR0));
#endif
}
static inline unsigned int snd_sonicvibes_getdmaa(struct sonicvibes * sonic)
{
return (inl(sonic->dmaa_port + SV_DMA_COUNT0) & 0xffffff) + 1;
}
static inline unsigned int snd_sonicvibes_getdmac(struct sonicvibes * sonic)
{
return ((inl(sonic->dmac_port + SV_DMA_COUNT0) & 0xffffff) + 1) << 1;
}
static void snd_sonicvibes_out1(struct sonicvibes * sonic,
unsigned char reg,
unsigned char value)
{
outb(reg, SV_REG(sonic, INDEX));
udelay(10);
outb(value, SV_REG(sonic, DATA));
udelay(10);
}
static void snd_sonicvibes_out(struct sonicvibes * sonic,
unsigned char reg,
unsigned char value)
{
unsigned long flags;
spin_lock_irqsave(&sonic->reg_lock, flags);
outb(reg, SV_REG(sonic, INDEX));
udelay(10);
outb(value, SV_REG(sonic, DATA));
udelay(10);
spin_unlock_irqrestore(&sonic->reg_lock, flags);
}
static unsigned char snd_sonicvibes_in1(struct sonicvibes * sonic, unsigned char reg)
{
unsigned char value;
outb(reg, SV_REG(sonic, INDEX));
udelay(10);
value = inb(SV_REG(sonic, DATA));
udelay(10);
return value;
}
static unsigned char snd_sonicvibes_in(struct sonicvibes * sonic, unsigned char reg)
{
unsigned long flags;
unsigned char value;
spin_lock_irqsave(&sonic->reg_lock, flags);
outb(reg, SV_REG(sonic, INDEX));
udelay(10);
value = inb(SV_REG(sonic, DATA));
udelay(10);
spin_unlock_irqrestore(&sonic->reg_lock, flags);
return value;
}
static void snd_sonicvibes_setfmt(struct sonicvibes * sonic,
unsigned char mask,
unsigned char value)
{
unsigned long flags;
spin_lock_irqsave(&sonic->reg_lock, flags);
outb(SV_MCE | SV_IREG_DMA_DATA_FMT, SV_REG(sonic, INDEX));
if (mask) {
sonic->format = inb(SV_REG(sonic, DATA));
udelay(10);
}
sonic->format = (sonic->format & mask) | value;
outb(sonic->format, SV_REG(sonic, DATA));
udelay(10);
outb(0, SV_REG(sonic, INDEX));
udelay(10);
spin_unlock_irqrestore(&sonic->reg_lock, flags);
}
static void snd_sonicvibes_pll(unsigned int rate,
unsigned int *res_r,
unsigned int *res_m,
unsigned int *res_n)
{
unsigned int r, m = 0, n = 0;
unsigned int xm, xn, xr, xd, metric = ~0U;
if (rate < 625000 / SV_ADCMULT)
rate = 625000 / SV_ADCMULT;
if (rate > 150000000 / SV_ADCMULT)
rate = 150000000 / SV_ADCMULT;
for (r = 0; rate < 75000000 / SV_ADCMULT; r += 0x20, rate <<= 1);
for (xn = 3; xn < 33; xn++)
for (xm = 3; xm < 257; xm++) {
xr = ((SV_REFFREQUENCY / SV_ADCMULT) * xm) / xn;
if (xr >= rate)
xd = xr - rate;
else
xd = rate - xr;
if (xd < metric) {
metric = xd;
m = xm - 2;
n = xn - 2;
}
}
*res_r = r;
*res_m = m;
*res_n = n;
#if 0
printk(KERN_DEBUG "metric = %i, xm = %i, xn = %i\n", metric, xm, xn);
printk(KERN_DEBUG "pll: m = 0x%x, r = 0x%x, n = 0x%x\n", reg, m, r, n);
#endif
}
static void snd_sonicvibes_setpll(struct sonicvibes * sonic,
unsigned char reg,
unsigned int rate)
{
unsigned long flags;
unsigned int r, m, n;
snd_sonicvibes_pll(rate, &r, &m, &n);
if (sonic != NULL) {
spin_lock_irqsave(&sonic->reg_lock, flags);
snd_sonicvibes_out1(sonic, reg, m);
snd_sonicvibes_out1(sonic, reg + 1, r | n);
spin_unlock_irqrestore(&sonic->reg_lock, flags);
}
}
static void snd_sonicvibes_set_adc_rate(struct sonicvibes * sonic, unsigned int rate)
{
unsigned long flags;
unsigned int div;
unsigned char clock;
div = 48000 / rate;
if (div > 8)
div = 8;
if ((48000 / div) == rate) {
clock = 0x10;
} else {
clock = 0x00;
snd_sonicvibes_setpll(sonic, SV_IREG_ADC_PLL, rate);
}
spin_lock_irqsave(&sonic->reg_lock, flags);
snd_sonicvibes_out1(sonic, SV_IREG_ADC_ALT_RATE, (div - 1) << 4);
snd_sonicvibes_out1(sonic, SV_IREG_ADC_CLOCK, clock);
spin_unlock_irqrestore(&sonic->reg_lock, flags);
}
static int snd_sonicvibes_hw_constraint_dac_rate(struct snd_pcm_hw_params *params,
struct snd_pcm_hw_rule *rule)
{
unsigned int rate, div, r, m, n;
if (hw_param_interval(params, SNDRV_PCM_HW_PARAM_RATE)->min ==
hw_param_interval(params, SNDRV_PCM_HW_PARAM_RATE)->max) {
rate = hw_param_interval(params, SNDRV_PCM_HW_PARAM_RATE)->min;
div = 48000 / rate;
if (div > 8)
div = 8;
if ((48000 / div) == rate) {
params->rate_num = rate;
params->rate_den = 1;
} else {
snd_sonicvibes_pll(rate, &r, &m, &n);
snd_BUG_ON(SV_REFFREQUENCY % 16);
snd_BUG_ON(SV_ADCMULT % 512);
params->rate_num = (SV_REFFREQUENCY/16) * (n+2) * r;
params->rate_den = (SV_ADCMULT/512) * (m+2);
}
}
return 0;
}
static void snd_sonicvibes_set_dac_rate(struct sonicvibes * sonic, unsigned int rate)
{
unsigned int div;
unsigned long flags;
div = (rate * 65536 + SV_FULLRATE / 2) / SV_FULLRATE;
if (div > 65535)
div = 65535;
spin_lock_irqsave(&sonic->reg_lock, flags);
snd_sonicvibes_out1(sonic, SV_IREG_PCM_RATE_HIGH, div >> 8);
snd_sonicvibes_out1(sonic, SV_IREG_PCM_RATE_LOW, div);
spin_unlock_irqrestore(&sonic->reg_lock, flags);
}
static int snd_sonicvibes_trigger(struct sonicvibes * sonic, int what, int cmd)
{
int result = 0;
spin_lock(&sonic->reg_lock);
if (cmd == SNDRV_PCM_TRIGGER_START) {
if (!(sonic->enable & what)) {
sonic->enable |= what;
snd_sonicvibes_out1(sonic, SV_IREG_PC_ENABLE, sonic->enable);
}
} else if (cmd == SNDRV_PCM_TRIGGER_STOP) {
if (sonic->enable & what) {
sonic->enable &= ~what;
snd_sonicvibes_out1(sonic, SV_IREG_PC_ENABLE, sonic->enable);
}
} else {
result = -EINVAL;
}
spin_unlock(&sonic->reg_lock);
return result;
}
static irqreturn_t snd_sonicvibes_interrupt(int irq, void *dev_id)
{
struct sonicvibes *sonic = dev_id;
unsigned char status;
status = inb(SV_REG(sonic, STATUS));
if (!(status & (SV_DMAA_IRQ | SV_DMAC_IRQ | SV_MIDI_IRQ)))
return IRQ_NONE;
if (status == 0xff) {
outb(sonic->irqmask = ~0, SV_REG(sonic, IRQMASK));
snd_printk(KERN_ERR "IRQ failure - interrupts disabled!!\n");
return IRQ_HANDLED;
}
if (sonic->pcm) {
if (status & SV_DMAA_IRQ)
snd_pcm_period_elapsed(sonic->playback_substream);
if (status & SV_DMAC_IRQ)
snd_pcm_period_elapsed(sonic->capture_substream);
}
if (sonic->rmidi) {
if (status & SV_MIDI_IRQ)
snd_mpu401_uart_interrupt(irq, sonic->rmidi->private_data);
}
if (status & SV_UD_IRQ) {
unsigned char udreg;
int vol, oleft, oright, mleft, mright;
spin_lock(&sonic->reg_lock);
udreg = snd_sonicvibes_in1(sonic, SV_IREG_UD_BUTTON);
vol = udreg & 0x3f;
if (!(udreg & 0x40))
vol = -vol;
oleft = mleft = snd_sonicvibes_in1(sonic, SV_IREG_LEFT_ANALOG);
oright = mright = snd_sonicvibes_in1(sonic, SV_IREG_RIGHT_ANALOG);
oleft &= 0x1f;
oright &= 0x1f;
oleft += vol;
if (oleft < 0)
oleft = 0;
if (oleft > 0x1f)
oleft = 0x1f;
oright += vol;
if (oright < 0)
oright = 0;
if (oright > 0x1f)
oright = 0x1f;
if (udreg & 0x80) {
mleft ^= 0x80;
mright ^= 0x80;
}
oleft |= mleft & 0x80;
oright |= mright & 0x80;
snd_sonicvibes_out1(sonic, SV_IREG_LEFT_ANALOG, oleft);
snd_sonicvibes_out1(sonic, SV_IREG_RIGHT_ANALOG, oright);
spin_unlock(&sonic->reg_lock);
snd_ctl_notify(sonic->card, SNDRV_CTL_EVENT_MASK_VALUE, &sonic->master_mute->id);
snd_ctl_notify(sonic->card, SNDRV_CTL_EVENT_MASK_VALUE, &sonic->master_volume->id);
}
return IRQ_HANDLED;
}
static int snd_sonicvibes_playback_trigger(struct snd_pcm_substream *substream,
int cmd)
{
struct sonicvibes *sonic = snd_pcm_substream_chip(substream);
return snd_sonicvibes_trigger(sonic, 1, cmd);
}
static int snd_sonicvibes_capture_trigger(struct snd_pcm_substream *substream,
int cmd)
{
struct sonicvibes *sonic = snd_pcm_substream_chip(substream);
return snd_sonicvibes_trigger(sonic, 2, cmd);
}
static int snd_sonicvibes_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *hw_params)
{
return snd_pcm_lib_malloc_pages(substream, params_buffer_bytes(hw_params));
}
static int snd_sonicvibes_hw_free(struct snd_pcm_substream *substream)
{
return snd_pcm_lib_free_pages(substream);
}
static int snd_sonicvibes_playback_prepare(struct snd_pcm_substream *substream)
{
struct sonicvibes *sonic = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
unsigned char fmt = 0;
unsigned int size = snd_pcm_lib_buffer_bytes(substream);
unsigned int count = snd_pcm_lib_period_bytes(substream);
sonic->p_dma_size = size;
count--;
if (runtime->channels > 1)
fmt |= 1;
if (snd_pcm_format_width(runtime->format) == 16)
fmt |= 2;
snd_sonicvibes_setfmt(sonic, ~3, fmt);
snd_sonicvibes_set_dac_rate(sonic, runtime->rate);
spin_lock_irq(&sonic->reg_lock);
snd_sonicvibes_setdmaa(sonic, runtime->dma_addr, size);
snd_sonicvibes_out1(sonic, SV_IREG_DMA_A_UPPER, count >> 8);
snd_sonicvibes_out1(sonic, SV_IREG_DMA_A_LOWER, count);
spin_unlock_irq(&sonic->reg_lock);
return 0;
}
static int snd_sonicvibes_capture_prepare(struct snd_pcm_substream *substream)
{
struct sonicvibes *sonic = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
unsigned char fmt = 0;
unsigned int size = snd_pcm_lib_buffer_bytes(substream);
unsigned int count = snd_pcm_lib_period_bytes(substream);
sonic->c_dma_size = size;
count >>= 1;
count--;
if (runtime->channels > 1)
fmt |= 0x10;
if (snd_pcm_format_width(runtime->format) == 16)
fmt |= 0x20;
snd_sonicvibes_setfmt(sonic, ~0x30, fmt);
snd_sonicvibes_set_adc_rate(sonic, runtime->rate);
spin_lock_irq(&sonic->reg_lock);
snd_sonicvibes_setdmac(sonic, runtime->dma_addr, size);
snd_sonicvibes_out1(sonic, SV_IREG_DMA_C_UPPER, count >> 8);
snd_sonicvibes_out1(sonic, SV_IREG_DMA_C_LOWER, count);
spin_unlock_irq(&sonic->reg_lock);
return 0;
}
static snd_pcm_uframes_t snd_sonicvibes_playback_pointer(struct snd_pcm_substream *substream)
{
struct sonicvibes *sonic = snd_pcm_substream_chip(substream);
size_t ptr;
if (!(sonic->enable & 1))
return 0;
ptr = sonic->p_dma_size - snd_sonicvibes_getdmaa(sonic);
return bytes_to_frames(substream->runtime, ptr);
}
static snd_pcm_uframes_t snd_sonicvibes_capture_pointer(struct snd_pcm_substream *substream)
{
struct sonicvibes *sonic = snd_pcm_substream_chip(substream);
size_t ptr;
if (!(sonic->enable & 2))
return 0;
ptr = sonic->c_dma_size - snd_sonicvibes_getdmac(sonic);
return bytes_to_frames(substream->runtime, ptr);
}
static int snd_sonicvibes_playback_open(struct snd_pcm_substream *substream)
{
struct sonicvibes *sonic = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
sonic->mode |= SV_MODE_PLAY;
sonic->playback_substream = substream;
runtime->hw = snd_sonicvibes_playback;
snd_pcm_hw_rule_add(runtime, 0, SNDRV_PCM_HW_PARAM_RATE, snd_sonicvibes_hw_constraint_dac_rate, NULL, SNDRV_PCM_HW_PARAM_RATE, -1);
return 0;
}
static int snd_sonicvibes_capture_open(struct snd_pcm_substream *substream)
{
struct sonicvibes *sonic = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
sonic->mode |= SV_MODE_CAPTURE;
sonic->capture_substream = substream;
runtime->hw = snd_sonicvibes_capture;
snd_pcm_hw_constraint_ratdens(runtime, 0, SNDRV_PCM_HW_PARAM_RATE,
&snd_sonicvibes_hw_constraints_adc_clock);
return 0;
}
static int snd_sonicvibes_playback_close(struct snd_pcm_substream *substream)
{
struct sonicvibes *sonic = snd_pcm_substream_chip(substream);
sonic->playback_substream = NULL;
sonic->mode &= ~SV_MODE_PLAY;
return 0;
}
static int snd_sonicvibes_capture_close(struct snd_pcm_substream *substream)
{
struct sonicvibes *sonic = snd_pcm_substream_chip(substream);
sonic->capture_substream = NULL;
sonic->mode &= ~SV_MODE_CAPTURE;
return 0;
}
static int __devinit snd_sonicvibes_pcm(struct sonicvibes * sonic, int device, struct snd_pcm ** rpcm)
{
struct snd_pcm *pcm;
int err;
if ((err = snd_pcm_new(sonic->card, "s3_86c617", device, 1, 1, &pcm)) < 0)
return err;
if (snd_BUG_ON(!pcm))
return -EINVAL;
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_PLAYBACK, &snd_sonicvibes_playback_ops);
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_CAPTURE, &snd_sonicvibes_capture_ops);
pcm->private_data = sonic;
pcm->info_flags = 0;
strcpy(pcm->name, "S3 SonicVibes");
sonic->pcm = pcm;
snd_pcm_lib_preallocate_pages_for_all(pcm, SNDRV_DMA_TYPE_DEV,
snd_dma_pci_data(sonic->pci), 64*1024, 128*1024);
if (rpcm)
*rpcm = pcm;
return 0;
}
static int snd_sonicvibes_info_mux(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_info *uinfo)
{
static char *texts[7] = {
"CD", "PCM", "Aux1", "Line", "Aux0", "Mic", "Mix"
};
uinfo->type = SNDRV_CTL_ELEM_TYPE_ENUMERATED;
uinfo->count = 2;
uinfo->value.enumerated.items = 7;
if (uinfo->value.enumerated.item >= 7)
uinfo->value.enumerated.item = 6;
strcpy(uinfo->value.enumerated.name, texts[uinfo->value.enumerated.item]);
return 0;
}
static int snd_sonicvibes_get_mux(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct sonicvibes *sonic = snd_kcontrol_chip(kcontrol);
spin_lock_irq(&sonic->reg_lock);
ucontrol->value.enumerated.item[0] = ((snd_sonicvibes_in1(sonic, SV_IREG_LEFT_ADC) & SV_RECSRC_OUT) >> 5) - 1;
ucontrol->value.enumerated.item[1] = ((snd_sonicvibes_in1(sonic, SV_IREG_RIGHT_ADC) & SV_RECSRC_OUT) >> 5) - 1;
spin_unlock_irq(&sonic->reg_lock);
return 0;
}
static int snd_sonicvibes_put_mux(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct sonicvibes *sonic = snd_kcontrol_chip(kcontrol);
unsigned short left, right, oval1, oval2;
int change;
if (ucontrol->value.enumerated.item[0] >= 7 ||
ucontrol->value.enumerated.item[1] >= 7)
return -EINVAL;
left = (ucontrol->value.enumerated.item[0] + 1) << 5;
right = (ucontrol->value.enumerated.item[1] + 1) << 5;
spin_lock_irq(&sonic->reg_lock);
oval1 = snd_sonicvibes_in1(sonic, SV_IREG_LEFT_ADC);
oval2 = snd_sonicvibes_in1(sonic, SV_IREG_RIGHT_ADC);
left = (oval1 & ~SV_RECSRC_OUT) | left;
right = (oval2 & ~SV_RECSRC_OUT) | right;
change = left != oval1 || right != oval2;
snd_sonicvibes_out1(sonic, SV_IREG_LEFT_ADC, left);
snd_sonicvibes_out1(sonic, SV_IREG_RIGHT_ADC, right);
spin_unlock_irq(&sonic->reg_lock);
return change;
}
static int snd_sonicvibes_info_single(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_info *uinfo)
{
int mask = (kcontrol->private_value >> 16) & 0xff;
uinfo->type = mask == 1 ? SNDRV_CTL_ELEM_TYPE_BOOLEAN : SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = 1;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = mask;
return 0;
}
static int snd_sonicvibes_get_single(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct sonicvibes *sonic = snd_kcontrol_chip(kcontrol);
int reg = kcontrol->private_value & 0xff;
int shift = (kcontrol->private_value >> 8) & 0xff;
int mask = (kcontrol->private_value >> 16) & 0xff;
int invert = (kcontrol->private_value >> 24) & 0xff;
spin_lock_irq(&sonic->reg_lock);
ucontrol->value.integer.value[0] = (snd_sonicvibes_in1(sonic, reg)>> shift) & mask;
spin_unlock_irq(&sonic->reg_lock);
if (invert)
ucontrol->value.integer.value[0] = mask - ucontrol->value.integer.value[0];
return 0;
}
static int snd_sonicvibes_put_single(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct sonicvibes *sonic = snd_kcontrol_chip(kcontrol);
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
spin_lock_irq(&sonic->reg_lock);
oval = snd_sonicvibes_in1(sonic, reg);
val = (oval & ~(mask << shift)) | val;
change = val != oval;
snd_sonicvibes_out1(sonic, reg, val);
spin_unlock_irq(&sonic->reg_lock);
return change;
}
static int snd_sonicvibes_info_double(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_info *uinfo)
{
int mask = (kcontrol->private_value >> 24) & 0xff;
uinfo->type = mask == 1 ? SNDRV_CTL_ELEM_TYPE_BOOLEAN : SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = 2;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = mask;
return 0;
}
static int snd_sonicvibes_get_double(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct sonicvibes *sonic = snd_kcontrol_chip(kcontrol);
int left_reg = kcontrol->private_value & 0xff;
int right_reg = (kcontrol->private_value >> 8) & 0xff;
int shift_left = (kcontrol->private_value >> 16) & 0x07;
int shift_right = (kcontrol->private_value >> 19) & 0x07;
int mask = (kcontrol->private_value >> 24) & 0xff;
int invert = (kcontrol->private_value >> 22) & 1;
spin_lock_irq(&sonic->reg_lock);
ucontrol->value.integer.value[0] = (snd_sonicvibes_in1(sonic, left_reg) >> shift_left) & mask;
ucontrol->value.integer.value[1] = (snd_sonicvibes_in1(sonic, right_reg) >> shift_right) & mask;
spin_unlock_irq(&sonic->reg_lock);
if (invert) {
ucontrol->value.integer.value[0] = mask - ucontrol->value.integer.value[0];
ucontrol->value.integer.value[1] = mask - ucontrol->value.integer.value[1];
}
return 0;
}
static int snd_sonicvibes_put_double(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct sonicvibes *sonic = snd_kcontrol_chip(kcontrol);
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
spin_lock_irq(&sonic->reg_lock);
oval1 = snd_sonicvibes_in1(sonic, left_reg);
oval2 = snd_sonicvibes_in1(sonic, right_reg);
val1 = (oval1 & ~(mask << shift_left)) | val1;
val2 = (oval2 & ~(mask << shift_right)) | val2;
change = val1 != oval1 || val2 != oval2;
snd_sonicvibes_out1(sonic, left_reg, val1);
snd_sonicvibes_out1(sonic, right_reg, val2);
spin_unlock_irq(&sonic->reg_lock);
return change;
}
static void snd_sonicvibes_master_free(struct snd_kcontrol *kcontrol)
{
struct sonicvibes *sonic = snd_kcontrol_chip(kcontrol);
sonic->master_mute = NULL;
sonic->master_volume = NULL;
}
static int __devinit snd_sonicvibes_mixer(struct sonicvibes * sonic)
{
struct snd_card *card;
struct snd_kcontrol *kctl;
unsigned int idx;
int err;
if (snd_BUG_ON(!sonic || !sonic->card))
return -EINVAL;
card = sonic->card;
strcpy(card->mixername, "S3 SonicVibes");
for (idx = 0; idx < ARRAY_SIZE(snd_sonicvibes_controls); idx++) {
if ((err = snd_ctl_add(card, kctl = snd_ctl_new1(&snd_sonicvibes_controls[idx], sonic))) < 0)
return err;
switch (idx) {
case 0:
case 1: kctl->private_free = snd_sonicvibes_master_free; break;
}
}
return 0;
}
static void snd_sonicvibes_proc_read(struct snd_info_entry *entry,
struct snd_info_buffer *buffer)
{
struct sonicvibes *sonic = entry->private_data;
unsigned char tmp;
tmp = sonic->srs_space & 0x0f;
snd_iprintf(buffer, "SRS 3D : %s\n",
sonic->srs_space & 0x80 ? "off" : "on");
snd_iprintf(buffer, "SRS Space : %s\n",
tmp == 0x00 ? "100%" :
tmp == 0x01 ? "75%" :
tmp == 0x02 ? "50%" :
tmp == 0x03 ? "25%" : "0%");
tmp = sonic->srs_center & 0x0f;
snd_iprintf(buffer, "SRS Center : %s\n",
tmp == 0x00 ? "100%" :
tmp == 0x01 ? "75%" :
tmp == 0x02 ? "50%" :
tmp == 0x03 ? "25%" : "0%");
tmp = sonic->wave_source & 0x03;
snd_iprintf(buffer, "WaveTable Source : %s\n",
tmp == 0x00 ? "on-board ROM" :
tmp == 0x01 ? "PCI bus" : "on-board ROM + PCI bus");
tmp = sonic->mpu_switch;
snd_iprintf(buffer, "Onboard synth : %s\n", tmp & 0x01 ? "on" : "off");
snd_iprintf(buffer, "Ext. Rx to synth : %s\n", tmp & 0x02 ? "on" : "off");
snd_iprintf(buffer, "MIDI to ext. Tx : %s\n", tmp & 0x04 ? "on" : "off");
}
static void __devinit snd_sonicvibes_proc_init(struct sonicvibes * sonic)
{
struct snd_info_entry *entry;
if (! snd_card_proc_new(sonic->card, "sonicvibes", &entry))
snd_info_set_text_ops(entry, sonic, snd_sonicvibes_proc_read);
}
static int __devinit snd_sonicvibes_create_gameport(struct sonicvibes *sonic)
{
struct gameport *gp;
sonic->gameport = gp = gameport_allocate_port();
if (!gp) {
printk(KERN_ERR "sonicvibes: cannot allocate memory for gameport\n");
return -ENOMEM;
}
gameport_set_name(gp, "SonicVibes Gameport");
gameport_set_phys(gp, "pci%s/gameport0", pci_name(sonic->pci));
gameport_set_dev_parent(gp, &sonic->pci->dev);
gp->io = sonic->game_port;
gameport_register_port(gp);
snd_ctl_add(sonic->card, snd_ctl_new1(&snd_sonicvibes_game_control, sonic));
return 0;
}
static void snd_sonicvibes_free_gameport(struct sonicvibes *sonic)
{
if (sonic->gameport) {
gameport_unregister_port(sonic->gameport);
sonic->gameport = NULL;
}
}
static inline int snd_sonicvibes_create_gameport(struct sonicvibes *sonic) { return -ENOSYS; }
static inline void snd_sonicvibes_free_gameport(struct sonicvibes *sonic) { }
static int snd_sonicvibes_free(struct sonicvibes *sonic)
{
snd_sonicvibes_free_gameport(sonic);
pci_write_config_dword(sonic->pci, 0x40, sonic->dmaa_port);
pci_write_config_dword(sonic->pci, 0x48, sonic->dmac_port);
if (sonic->irq >= 0)
free_irq(sonic->irq, sonic);
release_and_free_resource(sonic->res_dmaa);
release_and_free_resource(sonic->res_dmac);
pci_release_regions(sonic->pci);
pci_disable_device(sonic->pci);
kfree(sonic);
return 0;
}
static int snd_sonicvibes_dev_free(struct snd_device *device)
{
struct sonicvibes *sonic = device->device_data;
return snd_sonicvibes_free(sonic);
}
static int __devinit snd_sonicvibes_create(struct snd_card *card,
struct pci_dev *pci,
int reverb,
int mge,
struct sonicvibes ** rsonic)
{
struct sonicvibes *sonic;
unsigned int dmaa, dmac;
int err;
static struct snd_device_ops ops = {
.dev_free = snd_sonicvibes_dev_free,
};
*rsonic = NULL;
if ((err = pci_enable_device(pci)) < 0)
return err;
if (pci_set_dma_mask(pci, DMA_BIT_MASK(24)) < 0 ||
pci_set_consistent_dma_mask(pci, DMA_BIT_MASK(24)) < 0) {
snd_printk(KERN_ERR "architecture does not support 24bit PCI busmaster DMA\n");
pci_disable_device(pci);
return -ENXIO;
}
sonic = kzalloc(sizeof(*sonic), GFP_KERNEL);
if (sonic == NULL) {
pci_disable_device(pci);
return -ENOMEM;
}
spin_lock_init(&sonic->reg_lock);
sonic->card = card;
sonic->pci = pci;
sonic->irq = -1;
if ((err = pci_request_regions(pci, "S3 SonicVibes")) < 0) {
kfree(sonic);
pci_disable_device(pci);
return err;
}
sonic->sb_port = pci_resource_start(pci, 0);
sonic->enh_port = pci_resource_start(pci, 1);
sonic->synth_port = pci_resource_start(pci, 2);
sonic->midi_port = pci_resource_start(pci, 3);
sonic->game_port = pci_resource_start(pci, 4);
if (request_irq(pci->irq, snd_sonicvibes_interrupt, IRQF_SHARED,
KBUILD_MODNAME, sonic)) {
snd_printk(KERN_ERR "unable to grab IRQ %d\n", pci->irq);
snd_sonicvibes_free(sonic);
return -EBUSY;
}
sonic->irq = pci->irq;
pci_read_config_dword(pci, 0x40, &dmaa);
pci_read_config_dword(pci, 0x48, &dmac);
dmaio &= ~0x0f;
dmaa &= ~0x0f;
dmac &= ~0x0f;
if (!dmaa) {
dmaa = dmaio;
dmaio += 0x10;
snd_printk(KERN_INFO "BIOS did not allocate DDMA channel A i/o, allocated at 0x%x\n", dmaa);
}
if (!dmac) {
dmac = dmaio;
dmaio += 0x10;
snd_printk(KERN_INFO "BIOS did not allocate DDMA channel C i/o, allocated at 0x%x\n", dmac);
}
pci_write_config_dword(pci, 0x40, dmaa);
pci_write_config_dword(pci, 0x48, dmac);
if ((sonic->res_dmaa = request_region(dmaa, 0x10, "S3 SonicVibes DDMA-A")) == NULL) {
snd_sonicvibes_free(sonic);
snd_printk(KERN_ERR "unable to grab DDMA-A port at 0x%x-0x%x\n", dmaa, dmaa + 0x10 - 1);
return -EBUSY;
}
if ((sonic->res_dmac = request_region(dmac, 0x10, "S3 SonicVibes DDMA-C")) == NULL) {
snd_sonicvibes_free(sonic);
snd_printk(KERN_ERR "unable to grab DDMA-C port at 0x%x-0x%x\n", dmac, dmac + 0x10 - 1);
return -EBUSY;
}
pci_read_config_dword(pci, 0x40, &sonic->dmaa_port);
pci_read_config_dword(pci, 0x48, &sonic->dmac_port);
sonic->dmaa_port &= ~0x0f;
sonic->dmac_port &= ~0x0f;
pci_write_config_dword(pci, 0x40, sonic->dmaa_port | 9);
pci_write_config_dword(pci, 0x48, sonic->dmac_port | 9);
outb(SV_RESET, SV_REG(sonic, CONTROL));
udelay(100);
outb(0, SV_REG(sonic, CONTROL));
udelay(100);
outb(SV_ENHANCED | SV_INTA | (reverb ? SV_REVERB : 0), SV_REG(sonic, CONTROL));
inb(SV_REG(sonic, STATUS));
#if 1
snd_sonicvibes_out(sonic, SV_IREG_DRIVE_CTRL, 0);
#else
snd_sonicvibes_out(sonic, SV_IREG_DRIVE_CTRL, 0x40);
#endif
snd_sonicvibes_out(sonic, SV_IREG_PC_ENABLE, sonic->enable = 0);
outb(sonic->irqmask = ~(SV_DMAA_MASK | SV_DMAC_MASK | SV_UD_MASK), SV_REG(sonic, IRQMASK));
inb(SV_REG(sonic, STATUS));
snd_sonicvibes_out(sonic, SV_IREG_ADC_CLOCK, 0);
snd_sonicvibes_out(sonic, SV_IREG_ANALOG_POWER, 0);
snd_sonicvibes_out(sonic, SV_IREG_DIGITAL_POWER, 0);
snd_sonicvibes_setpll(sonic, SV_IREG_ADC_PLL, 8000);
snd_sonicvibes_out(sonic, SV_IREG_SRS_SPACE, sonic->srs_space = 0x80);
snd_sonicvibes_out(sonic, SV_IREG_SRS_CENTER, sonic->srs_center = 0x00);
snd_sonicvibes_out(sonic, SV_IREG_MPU401, sonic->mpu_switch = 0x05);
snd_sonicvibes_out(sonic, SV_IREG_WAVE_SOURCE, sonic->wave_source = 0x00);
snd_sonicvibes_out(sonic, SV_IREG_PCM_RATE_LOW, (8000 * 65536 / SV_FULLRATE) & 0xff);
snd_sonicvibes_out(sonic, SV_IREG_PCM_RATE_HIGH, ((8000 * 65536 / SV_FULLRATE) >> 8) & 0xff);
snd_sonicvibes_out(sonic, SV_IREG_LEFT_ADC, mge ? 0xd0 : 0xc0);
snd_sonicvibes_out(sonic, SV_IREG_RIGHT_ADC, 0xc0);
snd_sonicvibes_out(sonic, SV_IREG_LEFT_AUX1, 0x9f);
snd_sonicvibes_out(sonic, SV_IREG_RIGHT_AUX1, 0x9f);
snd_sonicvibes_out(sonic, SV_IREG_LEFT_CD, 0x9f);
snd_sonicvibes_out(sonic, SV_IREG_RIGHT_CD, 0x9f);
snd_sonicvibes_out(sonic, SV_IREG_LEFT_LINE, 0x9f);
snd_sonicvibes_out(sonic, SV_IREG_RIGHT_LINE, 0x9f);
snd_sonicvibes_out(sonic, SV_IREG_MIC, 0x8f);
snd_sonicvibes_out(sonic, SV_IREG_LEFT_SYNTH, 0x9f);
snd_sonicvibes_out(sonic, SV_IREG_RIGHT_SYNTH, 0x9f);
snd_sonicvibes_out(sonic, SV_IREG_LEFT_AUX2, 0x9f);
snd_sonicvibes_out(sonic, SV_IREG_RIGHT_AUX2, 0x9f);
snd_sonicvibes_out(sonic, SV_IREG_LEFT_ANALOG, 0x9f);
snd_sonicvibes_out(sonic, SV_IREG_RIGHT_ANALOG, 0x9f);
snd_sonicvibes_out(sonic, SV_IREG_LEFT_PCM, 0xbf);
snd_sonicvibes_out(sonic, SV_IREG_RIGHT_PCM, 0xbf);
snd_sonicvibes_out(sonic, SV_IREG_ADC_OUTPUT_CTRL, 0xfc);
#if 0
snd_sonicvibes_debug(sonic);
#endif
sonic->revision = snd_sonicvibes_in(sonic, SV_IREG_REVISION);
if ((err = snd_device_new(card, SNDRV_DEV_LOWLEVEL, sonic, &ops)) < 0) {
snd_sonicvibes_free(sonic);
return err;
}
snd_sonicvibes_proc_init(sonic);
snd_card_set_dev(card, &pci->dev);
*rsonic = sonic;
return 0;
}
static int snd_sonicvibes_midi_input_open(struct snd_mpu401 * mpu)
{
struct sonicvibes *sonic = mpu->private_data;
outb(sonic->irqmask &= ~SV_MIDI_MASK, SV_REG(sonic, IRQMASK));
return 0;
}
static void snd_sonicvibes_midi_input_close(struct snd_mpu401 * mpu)
{
struct sonicvibes *sonic = mpu->private_data;
outb(sonic->irqmask |= SV_MIDI_MASK, SV_REG(sonic, IRQMASK));
}
static int __devinit snd_sonicvibes_midi(struct sonicvibes * sonic,
struct snd_rawmidi *rmidi)
{
struct snd_mpu401 * mpu = rmidi->private_data;
struct snd_card *card = sonic->card;
struct snd_rawmidi_str *dir;
unsigned int idx;
int err;
mpu->private_data = sonic;
mpu->open_input = snd_sonicvibes_midi_input_open;
mpu->close_input = snd_sonicvibes_midi_input_close;
dir = &rmidi->streams[SNDRV_RAWMIDI_STREAM_OUTPUT];
for (idx = 0; idx < ARRAY_SIZE(snd_sonicvibes_midi_controls); idx++)
if ((err = snd_ctl_add(card, snd_ctl_new1(&snd_sonicvibes_midi_controls[idx], sonic))) < 0)
return err;
return 0;
}
static int __devinit snd_sonic_probe(struct pci_dev *pci,
const struct pci_device_id *pci_id)
{
static int dev;
struct snd_card *card;
struct sonicvibes *sonic;
struct snd_rawmidi *midi_uart;
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
if ((err = snd_sonicvibes_create(card, pci,
reverb[dev] ? 1 : 0,
mge[dev] ? 1 : 0,
&sonic)) < 0) {
snd_card_free(card);
return err;
}
strcpy(card->driver, "SonicVibes");
strcpy(card->shortname, "S3 SonicVibes");
sprintf(card->longname, "%s rev %i at 0x%llx, irq %i",
card->shortname,
sonic->revision,
(unsigned long long)pci_resource_start(pci, 1),
sonic->irq);
if ((err = snd_sonicvibes_pcm(sonic, 0, NULL)) < 0) {
snd_card_free(card);
return err;
}
if ((err = snd_sonicvibes_mixer(sonic)) < 0) {
snd_card_free(card);
return err;
}
if ((err = snd_mpu401_uart_new(card, 0, MPU401_HW_SONICVIBES,
sonic->midi_port,
MPU401_INFO_INTEGRATED |
MPU401_INFO_IRQ_HOOK,
-1, &midi_uart)) < 0) {
snd_card_free(card);
return err;
}
snd_sonicvibes_midi(sonic, midi_uart);
if ((err = snd_opl3_create(card, sonic->synth_port,
sonic->synth_port + 2,
OPL3_HW_OPL3_SV, 1, &opl3)) < 0) {
snd_card_free(card);
return err;
}
if ((err = snd_opl3_hwdep_new(opl3, 0, 1, NULL)) < 0) {
snd_card_free(card);
return err;
}
snd_sonicvibes_create_gameport(sonic);
if ((err = snd_card_register(card)) < 0) {
snd_card_free(card);
return err;
}
pci_set_drvdata(pci, card);
dev++;
return 0;
}
static void __devexit snd_sonic_remove(struct pci_dev *pci)
{
snd_card_free(pci_get_drvdata(pci));
pci_set_drvdata(pci, NULL);
}
