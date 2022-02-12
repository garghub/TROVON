static unsigned int snd_es1371_wait_src_ready(struct ensoniq * ensoniq)
{
unsigned int t, r = 0;
for (t = 0; t < POLL_COUNT; t++) {
r = inl(ES_REG(ensoniq, 1371_SMPRATE));
if ((r & ES_1371_SRC_RAM_BUSY) == 0)
return r;
cond_resched();
}
dev_err(ensoniq->card->dev, "wait src ready timeout 0x%lx [0x%x]\n",
ES_REG(ensoniq, 1371_SMPRATE), r);
return 0;
}
static unsigned int snd_es1371_src_read(struct ensoniq * ensoniq, unsigned short reg)
{
unsigned int temp, i, orig, r;
temp = orig = snd_es1371_wait_src_ready(ensoniq);
r = temp & (ES_1371_SRC_DISABLE | ES_1371_DIS_P1 |
ES_1371_DIS_P2 | ES_1371_DIS_R1);
r |= ES_1371_SRC_RAM_ADDRO(reg) | 0x10000;
outl(r, ES_REG(ensoniq, 1371_SMPRATE));
temp = snd_es1371_wait_src_ready(ensoniq);
if ((temp & 0x00870000) != 0x00010000) {
for (i = 0; i < POLL_COUNT; i++) {
temp = inl(ES_REG(ensoniq, 1371_SMPRATE));
if ((temp & 0x00870000) == 0x00010000)
break;
}
}
r = orig & (ES_1371_SRC_DISABLE | ES_1371_DIS_P1 |
ES_1371_DIS_P2 | ES_1371_DIS_R1);
r |= ES_1371_SRC_RAM_ADDRO(reg);
outl(r, ES_REG(ensoniq, 1371_SMPRATE));
return temp;
}
static void snd_es1371_src_write(struct ensoniq * ensoniq,
unsigned short reg, unsigned short data)
{
unsigned int r;
r = snd_es1371_wait_src_ready(ensoniq) &
(ES_1371_SRC_DISABLE | ES_1371_DIS_P1 |
ES_1371_DIS_P2 | ES_1371_DIS_R1);
r |= ES_1371_SRC_RAM_ADDRO(reg) | ES_1371_SRC_RAM_DATAO(data);
outl(r | ES_1371_SRC_RAM_WE, ES_REG(ensoniq, 1371_SMPRATE));
}
static void snd_es1370_codec_write(struct snd_ak4531 *ak4531,
unsigned short reg, unsigned short val)
{
struct ensoniq *ensoniq = ak4531->private_data;
unsigned long end_time = jiffies + HZ / 10;
#if 0
dev_dbg(ensoniq->card->dev,
"CODEC WRITE: reg = 0x%x, val = 0x%x (0x%x), creg = 0x%x\n",
reg, val, ES_1370_CODEC_WRITE(reg, val), ES_REG(ensoniq, 1370_CODEC));
#endif
do {
if (!(inl(ES_REG(ensoniq, STATUS)) & ES_1370_CSTAT)) {
outw(ES_1370_CODEC_WRITE(reg, val), ES_REG(ensoniq, 1370_CODEC));
return;
}
schedule_timeout_uninterruptible(1);
} while (time_after(end_time, jiffies));
dev_err(ensoniq->card->dev, "codec write timeout, status = 0x%x\n",
inl(ES_REG(ensoniq, STATUS)));
}
static inline bool is_ev1938(struct ensoniq *ensoniq)
{
return ensoniq->pci->device == 0x8938;
}
static void snd_es1371_codec_write(struct snd_ac97 *ac97,
unsigned short reg, unsigned short val)
{
struct ensoniq *ensoniq = ac97->private_data;
unsigned int t, x, flag;
flag = is_ev1938(ensoniq) ? EV_1938_CODEC_MAGIC : 0;
mutex_lock(&ensoniq->src_mutex);
for (t = 0; t < POLL_COUNT; t++) {
if (!(inl(ES_REG(ensoniq, 1371_CODEC)) & ES_1371_CODEC_WIP)) {
x = snd_es1371_wait_src_ready(ensoniq);
outl((x & (ES_1371_SRC_DISABLE | ES_1371_DIS_P1 |
ES_1371_DIS_P2 | ES_1371_DIS_R1)) | 0x00010000,
ES_REG(ensoniq, 1371_SMPRATE));
for (t = 0; t < POLL_COUNT; t++) {
if ((inl(ES_REG(ensoniq, 1371_SMPRATE)) & 0x00870000) ==
0x00000000)
break;
}
for (t = 0; t < POLL_COUNT; t++) {
if ((inl(ES_REG(ensoniq, 1371_SMPRATE)) & 0x00870000) ==
0x00010000)
break;
}
outl(ES_1371_CODEC_WRITE(reg, val) | flag,
ES_REG(ensoniq, 1371_CODEC));
snd_es1371_wait_src_ready(ensoniq);
outl(x, ES_REG(ensoniq, 1371_SMPRATE));
mutex_unlock(&ensoniq->src_mutex);
return;
}
}
mutex_unlock(&ensoniq->src_mutex);
dev_err(ensoniq->card->dev, "codec write timeout at 0x%lx [0x%x]\n",
ES_REG(ensoniq, 1371_CODEC), inl(ES_REG(ensoniq, 1371_CODEC)));
}
static unsigned short snd_es1371_codec_read(struct snd_ac97 *ac97,
unsigned short reg)
{
struct ensoniq *ensoniq = ac97->private_data;
unsigned int t, x, flag, fail = 0;
flag = is_ev1938(ensoniq) ? EV_1938_CODEC_MAGIC : 0;
__again:
mutex_lock(&ensoniq->src_mutex);
for (t = 0; t < POLL_COUNT; t++) {
if (!(inl(ES_REG(ensoniq, 1371_CODEC)) & ES_1371_CODEC_WIP)) {
x = snd_es1371_wait_src_ready(ensoniq);
outl((x & (ES_1371_SRC_DISABLE | ES_1371_DIS_P1 |
ES_1371_DIS_P2 | ES_1371_DIS_R1)) | 0x00010000,
ES_REG(ensoniq, 1371_SMPRATE));
for (t = 0; t < POLL_COUNT; t++) {
if ((inl(ES_REG(ensoniq, 1371_SMPRATE)) & 0x00870000) ==
0x00000000)
break;
}
for (t = 0; t < POLL_COUNT; t++) {
if ((inl(ES_REG(ensoniq, 1371_SMPRATE)) & 0x00870000) ==
0x00010000)
break;
}
outl(ES_1371_CODEC_READS(reg) | flag,
ES_REG(ensoniq, 1371_CODEC));
snd_es1371_wait_src_ready(ensoniq);
outl(x, ES_REG(ensoniq, 1371_SMPRATE));
for (t = 0; t < POLL_COUNT; t++) {
if (!(inl(ES_REG(ensoniq, 1371_CODEC)) & ES_1371_CODEC_WIP))
break;
}
for (t = 0; t < POLL_COUNT; t++) {
if ((x = inl(ES_REG(ensoniq, 1371_CODEC))) & ES_1371_CODEC_RDY) {
if (is_ev1938(ensoniq)) {
for (t = 0; t < 100; t++)
inl(ES_REG(ensoniq, CONTROL));
x = inl(ES_REG(ensoniq, 1371_CODEC));
}
mutex_unlock(&ensoniq->src_mutex);
return ES_1371_CODEC_READ(x);
}
}
mutex_unlock(&ensoniq->src_mutex);
if (++fail > 10) {
dev_err(ensoniq->card->dev,
"codec read timeout (final) at 0x%lx, reg = 0x%x [0x%x]\n",
ES_REG(ensoniq, 1371_CODEC), reg,
inl(ES_REG(ensoniq, 1371_CODEC)));
return 0;
}
goto __again;
}
}
mutex_unlock(&ensoniq->src_mutex);
dev_err(ensoniq->card->dev, "codec read timeout at 0x%lx [0x%x]\n",
ES_REG(ensoniq, 1371_CODEC), inl(ES_REG(ensoniq, 1371_CODEC)));
return 0;
}
static void snd_es1371_codec_wait(struct snd_ac97 *ac97)
{
msleep(750);
snd_es1371_codec_read(ac97, AC97_RESET);
snd_es1371_codec_read(ac97, AC97_VENDOR_ID1);
snd_es1371_codec_read(ac97, AC97_VENDOR_ID2);
msleep(50);
}
static void snd_es1371_adc_rate(struct ensoniq * ensoniq, unsigned int rate)
{
unsigned int n, truncm, freq, result;
mutex_lock(&ensoniq->src_mutex);
n = rate / 3000;
if ((1 << n) & ((1 << 15) | (1 << 13) | (1 << 11) | (1 << 9)))
n--;
truncm = (21 * n - 1) | 1;
freq = ((48000UL << 15) / rate) * n;
result = (48000UL << 15) / (freq / n);
if (rate >= 24000) {
if (truncm > 239)
truncm = 239;
snd_es1371_src_write(ensoniq, ES_SMPREG_ADC + ES_SMPREG_TRUNC_N,
(((239 - truncm) >> 1) << 9) | (n << 4));
} else {
if (truncm > 119)
truncm = 119;
snd_es1371_src_write(ensoniq, ES_SMPREG_ADC + ES_SMPREG_TRUNC_N,
0x8000 | (((119 - truncm) >> 1) << 9) | (n << 4));
}
snd_es1371_src_write(ensoniq, ES_SMPREG_ADC + ES_SMPREG_INT_REGS,
(snd_es1371_src_read(ensoniq, ES_SMPREG_ADC +
ES_SMPREG_INT_REGS) & 0x00ff) |
((freq >> 5) & 0xfc00));
snd_es1371_src_write(ensoniq, ES_SMPREG_ADC + ES_SMPREG_VFREQ_FRAC, freq & 0x7fff);
snd_es1371_src_write(ensoniq, ES_SMPREG_VOL_ADC, n << 8);
snd_es1371_src_write(ensoniq, ES_SMPREG_VOL_ADC + 1, n << 8);
mutex_unlock(&ensoniq->src_mutex);
}
static void snd_es1371_dac1_rate(struct ensoniq * ensoniq, unsigned int rate)
{
unsigned int freq, r;
mutex_lock(&ensoniq->src_mutex);
freq = ((rate << 15) + 1500) / 3000;
r = (snd_es1371_wait_src_ready(ensoniq) & (ES_1371_SRC_DISABLE |
ES_1371_DIS_P2 | ES_1371_DIS_R1)) |
ES_1371_DIS_P1;
outl(r, ES_REG(ensoniq, 1371_SMPRATE));
snd_es1371_src_write(ensoniq, ES_SMPREG_DAC1 + ES_SMPREG_INT_REGS,
(snd_es1371_src_read(ensoniq, ES_SMPREG_DAC1 +
ES_SMPREG_INT_REGS) & 0x00ff) |
((freq >> 5) & 0xfc00));
snd_es1371_src_write(ensoniq, ES_SMPREG_DAC1 + ES_SMPREG_VFREQ_FRAC, freq & 0x7fff);
r = (snd_es1371_wait_src_ready(ensoniq) & (ES_1371_SRC_DISABLE |
ES_1371_DIS_P2 | ES_1371_DIS_R1));
outl(r, ES_REG(ensoniq, 1371_SMPRATE));
mutex_unlock(&ensoniq->src_mutex);
}
static void snd_es1371_dac2_rate(struct ensoniq * ensoniq, unsigned int rate)
{
unsigned int freq, r;
mutex_lock(&ensoniq->src_mutex);
freq = ((rate << 15) + 1500) / 3000;
r = (snd_es1371_wait_src_ready(ensoniq) & (ES_1371_SRC_DISABLE |
ES_1371_DIS_P1 | ES_1371_DIS_R1)) |
ES_1371_DIS_P2;
outl(r, ES_REG(ensoniq, 1371_SMPRATE));
snd_es1371_src_write(ensoniq, ES_SMPREG_DAC2 + ES_SMPREG_INT_REGS,
(snd_es1371_src_read(ensoniq, ES_SMPREG_DAC2 +
ES_SMPREG_INT_REGS) & 0x00ff) |
((freq >> 5) & 0xfc00));
snd_es1371_src_write(ensoniq, ES_SMPREG_DAC2 + ES_SMPREG_VFREQ_FRAC,
freq & 0x7fff);
r = (snd_es1371_wait_src_ready(ensoniq) & (ES_1371_SRC_DISABLE |
ES_1371_DIS_P1 | ES_1371_DIS_R1));
outl(r, ES_REG(ensoniq, 1371_SMPRATE));
mutex_unlock(&ensoniq->src_mutex);
}
static int snd_ensoniq_trigger(struct snd_pcm_substream *substream, int cmd)
{
struct ensoniq *ensoniq = snd_pcm_substream_chip(substream);
switch (cmd) {
case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
{
unsigned int what = 0;
struct snd_pcm_substream *s;
snd_pcm_group_for_each_entry(s, substream) {
if (s == ensoniq->playback1_substream) {
what |= ES_P1_PAUSE;
snd_pcm_trigger_done(s, substream);
} else if (s == ensoniq->playback2_substream) {
what |= ES_P2_PAUSE;
snd_pcm_trigger_done(s, substream);
} else if (s == ensoniq->capture_substream)
return -EINVAL;
}
spin_lock(&ensoniq->reg_lock);
if (cmd == SNDRV_PCM_TRIGGER_PAUSE_PUSH)
ensoniq->sctrl |= what;
else
ensoniq->sctrl &= ~what;
outl(ensoniq->sctrl, ES_REG(ensoniq, SERIAL));
spin_unlock(&ensoniq->reg_lock);
break;
}
case SNDRV_PCM_TRIGGER_START:
case SNDRV_PCM_TRIGGER_STOP:
{
unsigned int what = 0;
struct snd_pcm_substream *s;
snd_pcm_group_for_each_entry(s, substream) {
if (s == ensoniq->playback1_substream) {
what |= ES_DAC1_EN;
snd_pcm_trigger_done(s, substream);
} else if (s == ensoniq->playback2_substream) {
what |= ES_DAC2_EN;
snd_pcm_trigger_done(s, substream);
} else if (s == ensoniq->capture_substream) {
what |= ES_ADC_EN;
snd_pcm_trigger_done(s, substream);
}
}
spin_lock(&ensoniq->reg_lock);
if (cmd == SNDRV_PCM_TRIGGER_START)
ensoniq->ctrl |= what;
else
ensoniq->ctrl &= ~what;
outl(ensoniq->ctrl, ES_REG(ensoniq, CONTROL));
spin_unlock(&ensoniq->reg_lock);
break;
}
default:
return -EINVAL;
}
return 0;
}
static int snd_ensoniq_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *hw_params)
{
return snd_pcm_lib_malloc_pages(substream, params_buffer_bytes(hw_params));
}
static int snd_ensoniq_hw_free(struct snd_pcm_substream *substream)
{
return snd_pcm_lib_free_pages(substream);
}
static int snd_ensoniq_playback1_prepare(struct snd_pcm_substream *substream)
{
struct ensoniq *ensoniq = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
unsigned int mode = 0;
ensoniq->p1_dma_size = snd_pcm_lib_buffer_bytes(substream);
ensoniq->p1_period_size = snd_pcm_lib_period_bytes(substream);
if (snd_pcm_format_width(runtime->format) == 16)
mode |= 0x02;
if (runtime->channels > 1)
mode |= 0x01;
spin_lock_irq(&ensoniq->reg_lock);
ensoniq->ctrl &= ~ES_DAC1_EN;
#ifdef CHIP1371
if (runtime->rate == 48000)
ensoniq->ctrl |= ES_1373_BYPASS_P1;
else
ensoniq->ctrl &= ~ES_1373_BYPASS_P1;
#endif
outl(ensoniq->ctrl, ES_REG(ensoniq, CONTROL));
outl(ES_MEM_PAGEO(ES_PAGE_DAC), ES_REG(ensoniq, MEM_PAGE));
outl(runtime->dma_addr, ES_REG(ensoniq, DAC1_FRAME));
outl((ensoniq->p1_dma_size >> 2) - 1, ES_REG(ensoniq, DAC1_SIZE));
ensoniq->sctrl &= ~(ES_P1_LOOP_SEL | ES_P1_PAUSE | ES_P1_SCT_RLD | ES_P1_MODEM);
ensoniq->sctrl |= ES_P1_INT_EN | ES_P1_MODEO(mode);
outl(ensoniq->sctrl, ES_REG(ensoniq, SERIAL));
outl((ensoniq->p1_period_size >> snd_ensoniq_sample_shift[mode]) - 1,
ES_REG(ensoniq, DAC1_COUNT));
#ifdef CHIP1370
ensoniq->ctrl &= ~ES_1370_WTSRSELM;
switch (runtime->rate) {
case 5512: ensoniq->ctrl |= ES_1370_WTSRSEL(0); break;
case 11025: ensoniq->ctrl |= ES_1370_WTSRSEL(1); break;
case 22050: ensoniq->ctrl |= ES_1370_WTSRSEL(2); break;
case 44100: ensoniq->ctrl |= ES_1370_WTSRSEL(3); break;
default: snd_BUG();
}
#endif
outl(ensoniq->ctrl, ES_REG(ensoniq, CONTROL));
spin_unlock_irq(&ensoniq->reg_lock);
#ifndef CHIP1370
snd_es1371_dac1_rate(ensoniq, runtime->rate);
#endif
return 0;
}
static int snd_ensoniq_playback2_prepare(struct snd_pcm_substream *substream)
{
struct ensoniq *ensoniq = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
unsigned int mode = 0;
ensoniq->p2_dma_size = snd_pcm_lib_buffer_bytes(substream);
ensoniq->p2_period_size = snd_pcm_lib_period_bytes(substream);
if (snd_pcm_format_width(runtime->format) == 16)
mode |= 0x02;
if (runtime->channels > 1)
mode |= 0x01;
spin_lock_irq(&ensoniq->reg_lock);
ensoniq->ctrl &= ~ES_DAC2_EN;
outl(ensoniq->ctrl, ES_REG(ensoniq, CONTROL));
outl(ES_MEM_PAGEO(ES_PAGE_DAC), ES_REG(ensoniq, MEM_PAGE));
outl(runtime->dma_addr, ES_REG(ensoniq, DAC2_FRAME));
outl((ensoniq->p2_dma_size >> 2) - 1, ES_REG(ensoniq, DAC2_SIZE));
ensoniq->sctrl &= ~(ES_P2_LOOP_SEL | ES_P2_PAUSE | ES_P2_DAC_SEN |
ES_P2_END_INCM | ES_P2_ST_INCM | ES_P2_MODEM);
ensoniq->sctrl |= ES_P2_INT_EN | ES_P2_MODEO(mode) |
ES_P2_END_INCO(mode & 2 ? 2 : 1) | ES_P2_ST_INCO(0);
outl(ensoniq->sctrl, ES_REG(ensoniq, SERIAL));
outl((ensoniq->p2_period_size >> snd_ensoniq_sample_shift[mode]) - 1,
ES_REG(ensoniq, DAC2_COUNT));
#ifdef CHIP1370
if (!(ensoniq->u.es1370.pclkdiv_lock & ES_MODE_CAPTURE)) {
ensoniq->ctrl &= ~ES_1370_PCLKDIVM;
ensoniq->ctrl |= ES_1370_PCLKDIVO(ES_1370_SRTODIV(runtime->rate));
ensoniq->u.es1370.pclkdiv_lock |= ES_MODE_PLAY2;
}
#endif
outl(ensoniq->ctrl, ES_REG(ensoniq, CONTROL));
spin_unlock_irq(&ensoniq->reg_lock);
#ifndef CHIP1370
snd_es1371_dac2_rate(ensoniq, runtime->rate);
#endif
return 0;
}
static int snd_ensoniq_capture_prepare(struct snd_pcm_substream *substream)
{
struct ensoniq *ensoniq = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
unsigned int mode = 0;
ensoniq->c_dma_size = snd_pcm_lib_buffer_bytes(substream);
ensoniq->c_period_size = snd_pcm_lib_period_bytes(substream);
if (snd_pcm_format_width(runtime->format) == 16)
mode |= 0x02;
if (runtime->channels > 1)
mode |= 0x01;
spin_lock_irq(&ensoniq->reg_lock);
ensoniq->ctrl &= ~ES_ADC_EN;
outl(ensoniq->ctrl, ES_REG(ensoniq, CONTROL));
outl(ES_MEM_PAGEO(ES_PAGE_ADC), ES_REG(ensoniq, MEM_PAGE));
outl(runtime->dma_addr, ES_REG(ensoniq, ADC_FRAME));
outl((ensoniq->c_dma_size >> 2) - 1, ES_REG(ensoniq, ADC_SIZE));
ensoniq->sctrl &= ~(ES_R1_LOOP_SEL | ES_R1_MODEM);
ensoniq->sctrl |= ES_R1_INT_EN | ES_R1_MODEO(mode);
outl(ensoniq->sctrl, ES_REG(ensoniq, SERIAL));
outl((ensoniq->c_period_size >> snd_ensoniq_sample_shift[mode]) - 1,
ES_REG(ensoniq, ADC_COUNT));
#ifdef CHIP1370
if (!(ensoniq->u.es1370.pclkdiv_lock & ES_MODE_PLAY2)) {
ensoniq->ctrl &= ~ES_1370_PCLKDIVM;
ensoniq->ctrl |= ES_1370_PCLKDIVO(ES_1370_SRTODIV(runtime->rate));
ensoniq->u.es1370.pclkdiv_lock |= ES_MODE_CAPTURE;
}
#endif
outl(ensoniq->ctrl, ES_REG(ensoniq, CONTROL));
spin_unlock_irq(&ensoniq->reg_lock);
#ifndef CHIP1370
snd_es1371_adc_rate(ensoniq, runtime->rate);
#endif
return 0;
}
static snd_pcm_uframes_t snd_ensoniq_playback1_pointer(struct snd_pcm_substream *substream)
{
struct ensoniq *ensoniq = snd_pcm_substream_chip(substream);
size_t ptr;
spin_lock(&ensoniq->reg_lock);
if (inl(ES_REG(ensoniq, CONTROL)) & ES_DAC1_EN) {
outl(ES_MEM_PAGEO(ES_PAGE_DAC), ES_REG(ensoniq, MEM_PAGE));
ptr = ES_REG_FCURR_COUNTI(inl(ES_REG(ensoniq, DAC1_SIZE)));
ptr = bytes_to_frames(substream->runtime, ptr);
} else {
ptr = 0;
}
spin_unlock(&ensoniq->reg_lock);
return ptr;
}
static snd_pcm_uframes_t snd_ensoniq_playback2_pointer(struct snd_pcm_substream *substream)
{
struct ensoniq *ensoniq = snd_pcm_substream_chip(substream);
size_t ptr;
spin_lock(&ensoniq->reg_lock);
if (inl(ES_REG(ensoniq, CONTROL)) & ES_DAC2_EN) {
outl(ES_MEM_PAGEO(ES_PAGE_DAC), ES_REG(ensoniq, MEM_PAGE));
ptr = ES_REG_FCURR_COUNTI(inl(ES_REG(ensoniq, DAC2_SIZE)));
ptr = bytes_to_frames(substream->runtime, ptr);
} else {
ptr = 0;
}
spin_unlock(&ensoniq->reg_lock);
return ptr;
}
static snd_pcm_uframes_t snd_ensoniq_capture_pointer(struct snd_pcm_substream *substream)
{
struct ensoniq *ensoniq = snd_pcm_substream_chip(substream);
size_t ptr;
spin_lock(&ensoniq->reg_lock);
if (inl(ES_REG(ensoniq, CONTROL)) & ES_ADC_EN) {
outl(ES_MEM_PAGEO(ES_PAGE_ADC), ES_REG(ensoniq, MEM_PAGE));
ptr = ES_REG_FCURR_COUNTI(inl(ES_REG(ensoniq, ADC_SIZE)));
ptr = bytes_to_frames(substream->runtime, ptr);
} else {
ptr = 0;
}
spin_unlock(&ensoniq->reg_lock);
return ptr;
}
static int snd_ensoniq_playback1_open(struct snd_pcm_substream *substream)
{
struct ensoniq *ensoniq = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
ensoniq->mode |= ES_MODE_PLAY1;
ensoniq->playback1_substream = substream;
runtime->hw = snd_ensoniq_playback1;
snd_pcm_set_sync(substream);
spin_lock_irq(&ensoniq->reg_lock);
if (ensoniq->spdif && ensoniq->playback2_substream == NULL)
ensoniq->spdif_stream = ensoniq->spdif_default;
spin_unlock_irq(&ensoniq->reg_lock);
#ifdef CHIP1370
snd_pcm_hw_constraint_list(runtime, 0, SNDRV_PCM_HW_PARAM_RATE,
&snd_es1370_hw_constraints_rates);
#else
snd_pcm_hw_constraint_ratdens(runtime, 0, SNDRV_PCM_HW_PARAM_RATE,
&snd_es1371_hw_constraints_dac_clock);
#endif
return 0;
}
static int snd_ensoniq_playback2_open(struct snd_pcm_substream *substream)
{
struct ensoniq *ensoniq = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
ensoniq->mode |= ES_MODE_PLAY2;
ensoniq->playback2_substream = substream;
runtime->hw = snd_ensoniq_playback2;
snd_pcm_set_sync(substream);
spin_lock_irq(&ensoniq->reg_lock);
if (ensoniq->spdif && ensoniq->playback1_substream == NULL)
ensoniq->spdif_stream = ensoniq->spdif_default;
spin_unlock_irq(&ensoniq->reg_lock);
#ifdef CHIP1370
snd_pcm_hw_constraint_ratnums(runtime, 0, SNDRV_PCM_HW_PARAM_RATE,
&snd_es1370_hw_constraints_clock);
#else
snd_pcm_hw_constraint_ratdens(runtime, 0, SNDRV_PCM_HW_PARAM_RATE,
&snd_es1371_hw_constraints_dac_clock);
#endif
return 0;
}
static int snd_ensoniq_capture_open(struct snd_pcm_substream *substream)
{
struct ensoniq *ensoniq = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
ensoniq->mode |= ES_MODE_CAPTURE;
ensoniq->capture_substream = substream;
runtime->hw = snd_ensoniq_capture;
snd_pcm_set_sync(substream);
#ifdef CHIP1370
snd_pcm_hw_constraint_ratnums(runtime, 0, SNDRV_PCM_HW_PARAM_RATE,
&snd_es1370_hw_constraints_clock);
#else
snd_pcm_hw_constraint_ratnums(runtime, 0, SNDRV_PCM_HW_PARAM_RATE,
&snd_es1371_hw_constraints_adc_clock);
#endif
return 0;
}
static int snd_ensoniq_playback1_close(struct snd_pcm_substream *substream)
{
struct ensoniq *ensoniq = snd_pcm_substream_chip(substream);
ensoniq->playback1_substream = NULL;
ensoniq->mode &= ~ES_MODE_PLAY1;
return 0;
}
static int snd_ensoniq_playback2_close(struct snd_pcm_substream *substream)
{
struct ensoniq *ensoniq = snd_pcm_substream_chip(substream);
ensoniq->playback2_substream = NULL;
spin_lock_irq(&ensoniq->reg_lock);
#ifdef CHIP1370
ensoniq->u.es1370.pclkdiv_lock &= ~ES_MODE_PLAY2;
#endif
ensoniq->mode &= ~ES_MODE_PLAY2;
spin_unlock_irq(&ensoniq->reg_lock);
return 0;
}
static int snd_ensoniq_capture_close(struct snd_pcm_substream *substream)
{
struct ensoniq *ensoniq = snd_pcm_substream_chip(substream);
ensoniq->capture_substream = NULL;
spin_lock_irq(&ensoniq->reg_lock);
#ifdef CHIP1370
ensoniq->u.es1370.pclkdiv_lock &= ~ES_MODE_CAPTURE;
#endif
ensoniq->mode &= ~ES_MODE_CAPTURE;
spin_unlock_irq(&ensoniq->reg_lock);
return 0;
}
static int snd_ensoniq_pcm(struct ensoniq *ensoniq, int device)
{
struct snd_pcm *pcm;
int err;
err = snd_pcm_new(ensoniq->card, CHIP_NAME "/1", device, 1, 1, &pcm);
if (err < 0)
return err;
#ifdef CHIP1370
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_PLAYBACK, &snd_ensoniq_playback2_ops);
#else
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_PLAYBACK, &snd_ensoniq_playback1_ops);
#endif
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_CAPTURE, &snd_ensoniq_capture_ops);
pcm->private_data = ensoniq;
pcm->info_flags = 0;
strcpy(pcm->name, CHIP_NAME " DAC2/ADC");
ensoniq->pcm1 = pcm;
snd_pcm_lib_preallocate_pages_for_all(pcm, SNDRV_DMA_TYPE_DEV,
snd_dma_pci_data(ensoniq->pci), 64*1024, 128*1024);
#ifdef CHIP1370
err = snd_pcm_add_chmap_ctls(pcm, SNDRV_PCM_STREAM_PLAYBACK,
surround_map, 2, 0, NULL);
#else
err = snd_pcm_add_chmap_ctls(pcm, SNDRV_PCM_STREAM_PLAYBACK,
snd_pcm_std_chmaps, 2, 0, NULL);
#endif
return err;
}
static int snd_ensoniq_pcm2(struct ensoniq *ensoniq, int device)
{
struct snd_pcm *pcm;
int err;
err = snd_pcm_new(ensoniq->card, CHIP_NAME "/2", device, 1, 0, &pcm);
if (err < 0)
return err;
#ifdef CHIP1370
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_PLAYBACK, &snd_ensoniq_playback1_ops);
#else
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_PLAYBACK, &snd_ensoniq_playback2_ops);
#endif
pcm->private_data = ensoniq;
pcm->info_flags = 0;
strcpy(pcm->name, CHIP_NAME " DAC1");
ensoniq->pcm2 = pcm;
snd_pcm_lib_preallocate_pages_for_all(pcm, SNDRV_DMA_TYPE_DEV,
snd_dma_pci_data(ensoniq->pci), 64*1024, 128*1024);
#ifdef CHIP1370
err = snd_pcm_add_chmap_ctls(pcm, SNDRV_PCM_STREAM_PLAYBACK,
snd_pcm_std_chmaps, 2, 0, NULL);
#else
err = snd_pcm_add_chmap_ctls(pcm, SNDRV_PCM_STREAM_PLAYBACK,
surround_map, 2, 0, NULL);
#endif
return err;
}
static int snd_ens1373_spdif_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_IEC958;
uinfo->count = 1;
return 0;
}
static int snd_ens1373_spdif_default_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct ensoniq *ensoniq = snd_kcontrol_chip(kcontrol);
spin_lock_irq(&ensoniq->reg_lock);
ucontrol->value.iec958.status[0] = (ensoniq->spdif_default >> 0) & 0xff;
ucontrol->value.iec958.status[1] = (ensoniq->spdif_default >> 8) & 0xff;
ucontrol->value.iec958.status[2] = (ensoniq->spdif_default >> 16) & 0xff;
ucontrol->value.iec958.status[3] = (ensoniq->spdif_default >> 24) & 0xff;
spin_unlock_irq(&ensoniq->reg_lock);
return 0;
}
static int snd_ens1373_spdif_default_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct ensoniq *ensoniq = snd_kcontrol_chip(kcontrol);
unsigned int val;
int change;
val = ((u32)ucontrol->value.iec958.status[0] << 0) |
((u32)ucontrol->value.iec958.status[1] << 8) |
((u32)ucontrol->value.iec958.status[2] << 16) |
((u32)ucontrol->value.iec958.status[3] << 24);
spin_lock_irq(&ensoniq->reg_lock);
change = ensoniq->spdif_default != val;
ensoniq->spdif_default = val;
if (change && ensoniq->playback1_substream == NULL &&
ensoniq->playback2_substream == NULL)
outl(val, ES_REG(ensoniq, CHANNEL_STATUS));
spin_unlock_irq(&ensoniq->reg_lock);
return change;
}
static int snd_ens1373_spdif_mask_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
ucontrol->value.iec958.status[0] = 0xff;
ucontrol->value.iec958.status[1] = 0xff;
ucontrol->value.iec958.status[2] = 0xff;
ucontrol->value.iec958.status[3] = 0xff;
return 0;
}
static int snd_ens1373_spdif_stream_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct ensoniq *ensoniq = snd_kcontrol_chip(kcontrol);
spin_lock_irq(&ensoniq->reg_lock);
ucontrol->value.iec958.status[0] = (ensoniq->spdif_stream >> 0) & 0xff;
ucontrol->value.iec958.status[1] = (ensoniq->spdif_stream >> 8) & 0xff;
ucontrol->value.iec958.status[2] = (ensoniq->spdif_stream >> 16) & 0xff;
ucontrol->value.iec958.status[3] = (ensoniq->spdif_stream >> 24) & 0xff;
spin_unlock_irq(&ensoniq->reg_lock);
return 0;
}
static int snd_ens1373_spdif_stream_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct ensoniq *ensoniq = snd_kcontrol_chip(kcontrol);
unsigned int val;
int change;
val = ((u32)ucontrol->value.iec958.status[0] << 0) |
((u32)ucontrol->value.iec958.status[1] << 8) |
((u32)ucontrol->value.iec958.status[2] << 16) |
((u32)ucontrol->value.iec958.status[3] << 24);
spin_lock_irq(&ensoniq->reg_lock);
change = ensoniq->spdif_stream != val;
ensoniq->spdif_stream = val;
if (change && (ensoniq->playback1_substream != NULL ||
ensoniq->playback2_substream != NULL))
outl(val, ES_REG(ensoniq, CHANNEL_STATUS));
spin_unlock_irq(&ensoniq->reg_lock);
return change;
}
static int snd_es1371_spdif_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct ensoniq *ensoniq = snd_kcontrol_chip(kcontrol);
spin_lock_irq(&ensoniq->reg_lock);
ucontrol->value.integer.value[0] = ensoniq->ctrl & ES_1373_SPDIF_THRU ? 1 : 0;
spin_unlock_irq(&ensoniq->reg_lock);
return 0;
}
static int snd_es1371_spdif_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct ensoniq *ensoniq = snd_kcontrol_chip(kcontrol);
unsigned int nval1, nval2;
int change;
nval1 = ucontrol->value.integer.value[0] ? ES_1373_SPDIF_THRU : 0;
nval2 = ucontrol->value.integer.value[0] ? ES_1373_SPDIF_EN : 0;
spin_lock_irq(&ensoniq->reg_lock);
change = (ensoniq->ctrl & ES_1373_SPDIF_THRU) != nval1;
ensoniq->ctrl &= ~ES_1373_SPDIF_THRU;
ensoniq->ctrl |= nval1;
ensoniq->cssr &= ~ES_1373_SPDIF_EN;
ensoniq->cssr |= nval2;
outl(ensoniq->ctrl, ES_REG(ensoniq, CONTROL));
outl(ensoniq->cssr, ES_REG(ensoniq, STATUS));
spin_unlock_irq(&ensoniq->reg_lock);
return change;
}
static int snd_es1373_rear_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct ensoniq *ensoniq = snd_kcontrol_chip(kcontrol);
int val = 0;
spin_lock_irq(&ensoniq->reg_lock);
if ((ensoniq->cssr & (ES_1373_REAR_BIT27|ES_1373_REAR_BIT26|
ES_1373_REAR_BIT24)) == ES_1373_REAR_BIT26)
val = 1;
ucontrol->value.integer.value[0] = val;
spin_unlock_irq(&ensoniq->reg_lock);
return 0;
}
static int snd_es1373_rear_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct ensoniq *ensoniq = snd_kcontrol_chip(kcontrol);
unsigned int nval1;
int change;
nval1 = ucontrol->value.integer.value[0] ?
ES_1373_REAR_BIT26 : (ES_1373_REAR_BIT27|ES_1373_REAR_BIT24);
spin_lock_irq(&ensoniq->reg_lock);
change = (ensoniq->cssr & (ES_1373_REAR_BIT27|
ES_1373_REAR_BIT26|ES_1373_REAR_BIT24)) != nval1;
ensoniq->cssr &= ~(ES_1373_REAR_BIT27|ES_1373_REAR_BIT26|ES_1373_REAR_BIT24);
ensoniq->cssr |= nval1;
outl(ensoniq->cssr, ES_REG(ensoniq, STATUS));
spin_unlock_irq(&ensoniq->reg_lock);
return change;
}
static int snd_es1373_line_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct ensoniq *ensoniq = snd_kcontrol_chip(kcontrol);
int val = 0;
spin_lock_irq(&ensoniq->reg_lock);
if (ensoniq->ctrl & ES_1371_GPIO_OUT(4))
val = 1;
ucontrol->value.integer.value[0] = val;
spin_unlock_irq(&ensoniq->reg_lock);
return 0;
}
static int snd_es1373_line_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct ensoniq *ensoniq = snd_kcontrol_chip(kcontrol);
int changed;
unsigned int ctrl;
spin_lock_irq(&ensoniq->reg_lock);
ctrl = ensoniq->ctrl;
if (ucontrol->value.integer.value[0])
ensoniq->ctrl |= ES_1371_GPIO_OUT(4);
else
ensoniq->ctrl &= ~ES_1371_GPIO_OUT(4);
changed = (ctrl != ensoniq->ctrl);
if (changed)
outl(ensoniq->ctrl, ES_REG(ensoniq, CONTROL));
spin_unlock_irq(&ensoniq->reg_lock);
return changed;
}
static void snd_ensoniq_mixer_free_ac97(struct snd_ac97 *ac97)
{
struct ensoniq *ensoniq = ac97->private_data;
ensoniq->u.es1371.ac97 = NULL;
}
static int es1371_quirk_lookup(struct ensoniq *ensoniq,
struct es1371_quirk *list)
{
while (list->vid != (unsigned short)PCI_ANY_ID) {
if (ensoniq->pci->vendor == list->vid &&
ensoniq->pci->device == list->did &&
ensoniq->rev == list->rev)
return 1;
list++;
}
return 0;
}
static int snd_ensoniq_1371_mixer(struct ensoniq *ensoniq,
int has_spdif, int has_line)
{
struct snd_card *card = ensoniq->card;
struct snd_ac97_bus *pbus;
struct snd_ac97_template ac97;
int err;
static struct snd_ac97_bus_ops ops = {
.write = snd_es1371_codec_write,
.read = snd_es1371_codec_read,
.wait = snd_es1371_codec_wait,
};
if ((err = snd_ac97_bus(card, 0, &ops, NULL, &pbus)) < 0)
return err;
memset(&ac97, 0, sizeof(ac97));
ac97.private_data = ensoniq;
ac97.private_free = snd_ensoniq_mixer_free_ac97;
ac97.pci = ensoniq->pci;
ac97.scaps = AC97_SCAP_AUDIO;
if ((err = snd_ac97_mixer(pbus, &ac97, &ensoniq->u.es1371.ac97)) < 0)
return err;
if (has_spdif > 0 ||
(!has_spdif && es1371_quirk_lookup(ensoniq, es1371_spdif_present))) {
struct snd_kcontrol *kctl;
int i, is_spdif = 0;
ensoniq->spdif_default = ensoniq->spdif_stream =
SNDRV_PCM_DEFAULT_CON_SPDIF;
outl(ensoniq->spdif_default, ES_REG(ensoniq, CHANNEL_STATUS));
if (ensoniq->u.es1371.ac97->ext_id & AC97_EI_SPDIF)
is_spdif++;
for (i = 0; i < ARRAY_SIZE(snd_es1371_mixer_spdif); i++) {
kctl = snd_ctl_new1(&snd_es1371_mixer_spdif[i], ensoniq);
if (!kctl)
return -ENOMEM;
kctl->id.index = is_spdif;
err = snd_ctl_add(card, kctl);
if (err < 0)
return err;
}
}
if (ensoniq->u.es1371.ac97->ext_id & AC97_EI_SDAC) {
ensoniq->cssr &= ~(ES_1373_REAR_BIT27|ES_1373_REAR_BIT24);
ensoniq->cssr |= ES_1373_REAR_BIT26;
err = snd_ctl_add(card, snd_ctl_new1(&snd_ens1373_rear, ensoniq));
if (err < 0)
return err;
}
if (has_line > 0 ||
snd_pci_quirk_lookup(ensoniq->pci, ens1373_line_quirk)) {
err = snd_ctl_add(card, snd_ctl_new1(&snd_ens1373_line,
ensoniq));
if (err < 0)
return err;
}
return 0;
}
static int snd_ensoniq_control_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct ensoniq *ensoniq = snd_kcontrol_chip(kcontrol);
int mask = kcontrol->private_value;
spin_lock_irq(&ensoniq->reg_lock);
ucontrol->value.integer.value[0] = ensoniq->ctrl & mask ? 1 : 0;
spin_unlock_irq(&ensoniq->reg_lock);
return 0;
}
static int snd_ensoniq_control_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct ensoniq *ensoniq = snd_kcontrol_chip(kcontrol);
int mask = kcontrol->private_value;
unsigned int nval;
int change;
nval = ucontrol->value.integer.value[0] ? mask : 0;
spin_lock_irq(&ensoniq->reg_lock);
change = (ensoniq->ctrl & mask) != nval;
ensoniq->ctrl &= ~mask;
ensoniq->ctrl |= nval;
outl(ensoniq->ctrl, ES_REG(ensoniq, CONTROL));
spin_unlock_irq(&ensoniq->reg_lock);
return change;
}
static void snd_ensoniq_mixer_free_ak4531(struct snd_ak4531 *ak4531)
{
struct ensoniq *ensoniq = ak4531->private_data;
ensoniq->u.es1370.ak4531 = NULL;
}
static int snd_ensoniq_1370_mixer(struct ensoniq *ensoniq)
{
struct snd_card *card = ensoniq->card;
struct snd_ak4531 ak4531;
unsigned int idx;
int err;
outw(ES_1370_CODEC_WRITE(AK4531_RESET, 0x02), ES_REG(ensoniq, 1370_CODEC));
inw(ES_REG(ensoniq, 1370_CODEC));
udelay(100);
outw(ES_1370_CODEC_WRITE(AK4531_RESET, 0x03), ES_REG(ensoniq, 1370_CODEC));
inw(ES_REG(ensoniq, 1370_CODEC));
udelay(100);
memset(&ak4531, 0, sizeof(ak4531));
ak4531.write = snd_es1370_codec_write;
ak4531.private_data = ensoniq;
ak4531.private_free = snd_ensoniq_mixer_free_ak4531;
if ((err = snd_ak4531_mixer(card, &ak4531, &ensoniq->u.es1370.ak4531)) < 0)
return err;
for (idx = 0; idx < ES1370_CONTROLS; idx++) {
err = snd_ctl_add(card, snd_ctl_new1(&snd_es1370_controls[idx], ensoniq));
if (err < 0)
return err;
}
return 0;
}
static int snd_ensoniq_get_joystick_port(struct ensoniq *ensoniq, int dev)
{
switch (joystick_port[dev]) {
case 0:
case 1:
case 0x200:
case 0x208:
case 0x210:
case 0x218:
return joystick_port[dev];
default:
dev_err(ensoniq->card->dev,
"invalid joystick port %#x", joystick_port[dev]);
return 0;
}
}
static int snd_ensoniq_get_joystick_port(struct ensoniq *ensoniq, int dev)
{
return joystick[dev] ? 0x200 : 0;
}
static int snd_ensoniq_create_gameport(struct ensoniq *ensoniq, int dev)
{
struct gameport *gp;
int io_port;
io_port = snd_ensoniq_get_joystick_port(ensoniq, dev);
switch (io_port) {
case 0:
return -ENOSYS;
case 1:
for (io_port = 0x200; io_port <= 0x218; io_port += 8)
if (request_region(io_port, 8, "ens137x: gameport"))
break;
if (io_port > 0x218) {
dev_warn(ensoniq->card->dev,
"no gameport ports available\n");
return -EBUSY;
}
break;
default:
if (!request_region(io_port, 8, "ens137x: gameport")) {
dev_warn(ensoniq->card->dev,
"gameport io port %#x in use\n",
io_port);
return -EBUSY;
}
break;
}
ensoniq->gameport = gp = gameport_allocate_port();
if (!gp) {
dev_err(ensoniq->card->dev,
"cannot allocate memory for gameport\n");
release_region(io_port, 8);
return -ENOMEM;
}
gameport_set_name(gp, "ES137x");
gameport_set_phys(gp, "pci%s/gameport0", pci_name(ensoniq->pci));
gameport_set_dev_parent(gp, &ensoniq->pci->dev);
gp->io = io_port;
ensoniq->ctrl |= ES_JYSTK_EN;
#ifdef CHIP1371
ensoniq->ctrl &= ~ES_1371_JOY_ASELM;
ensoniq->ctrl |= ES_1371_JOY_ASEL((io_port - 0x200) / 8);
#endif
outl(ensoniq->ctrl, ES_REG(ensoniq, CONTROL));
gameport_register_port(ensoniq->gameport);
return 0;
}
static void snd_ensoniq_free_gameport(struct ensoniq *ensoniq)
{
if (ensoniq->gameport) {
int port = ensoniq->gameport->io;
gameport_unregister_port(ensoniq->gameport);
ensoniq->gameport = NULL;
ensoniq->ctrl &= ~ES_JYSTK_EN;
outl(ensoniq->ctrl, ES_REG(ensoniq, CONTROL));
release_region(port, 8);
}
}
static inline int snd_ensoniq_create_gameport(struct ensoniq *ensoniq, long port) { return -ENOSYS; }
static inline void snd_ensoniq_free_gameport(struct ensoniq *ensoniq) { }
static void snd_ensoniq_proc_read(struct snd_info_entry *entry,
struct snd_info_buffer *buffer)
{
struct ensoniq *ensoniq = entry->private_data;
snd_iprintf(buffer, "Ensoniq AudioPCI " CHIP_NAME "\n\n");
snd_iprintf(buffer, "Joystick enable : %s\n",
ensoniq->ctrl & ES_JYSTK_EN ? "on" : "off");
#ifdef CHIP1370
snd_iprintf(buffer, "MIC +5V bias : %s\n",
ensoniq->ctrl & ES_1370_XCTL1 ? "on" : "off");
snd_iprintf(buffer, "Line In to AOUT : %s\n",
ensoniq->ctrl & ES_1370_XCTL0 ? "on" : "off");
#else
snd_iprintf(buffer, "Joystick port : 0x%x\n",
(ES_1371_JOY_ASELI(ensoniq->ctrl) * 8) + 0x200);
#endif
}
static void snd_ensoniq_proc_init(struct ensoniq *ensoniq)
{
struct snd_info_entry *entry;
if (! snd_card_proc_new(ensoniq->card, "audiopci", &entry))
snd_info_set_text_ops(entry, ensoniq, snd_ensoniq_proc_read);
}
static int snd_ensoniq_free(struct ensoniq *ensoniq)
{
snd_ensoniq_free_gameport(ensoniq);
if (ensoniq->irq < 0)
goto __hw_end;
#ifdef CHIP1370
outl(ES_1370_SERR_DISABLE, ES_REG(ensoniq, CONTROL));
outl(0, ES_REG(ensoniq, SERIAL));
#else
outl(0, ES_REG(ensoniq, CONTROL));
outl(0, ES_REG(ensoniq, SERIAL));
#endif
if (ensoniq->irq >= 0)
synchronize_irq(ensoniq->irq);
pci_set_power_state(ensoniq->pci, PCI_D3hot);
__hw_end:
#ifdef CHIP1370
if (ensoniq->dma_bug.area)
snd_dma_free_pages(&ensoniq->dma_bug);
#endif
if (ensoniq->irq >= 0)
free_irq(ensoniq->irq, ensoniq);
pci_release_regions(ensoniq->pci);
pci_disable_device(ensoniq->pci);
kfree(ensoniq);
return 0;
}
static int snd_ensoniq_dev_free(struct snd_device *device)
{
struct ensoniq *ensoniq = device->device_data;
return snd_ensoniq_free(ensoniq);
}
static void snd_ensoniq_chip_init(struct ensoniq *ensoniq)
{
#ifdef CHIP1371
int idx;
#endif
#ifdef CHIP1370
outl(ensoniq->ctrl, ES_REG(ensoniq, CONTROL));
outl(ensoniq->sctrl, ES_REG(ensoniq, SERIAL));
outl(ES_MEM_PAGEO(ES_PAGE_ADC), ES_REG(ensoniq, MEM_PAGE));
outl(ensoniq->dma_bug.addr, ES_REG(ensoniq, PHANTOM_FRAME));
outl(0, ES_REG(ensoniq, PHANTOM_COUNT));
#else
outl(ensoniq->ctrl, ES_REG(ensoniq, CONTROL));
outl(ensoniq->sctrl, ES_REG(ensoniq, SERIAL));
outl(0, ES_REG(ensoniq, 1371_LEGACY));
if (es1371_quirk_lookup(ensoniq, es1371_ac97_reset_hack)) {
outl(ensoniq->cssr, ES_REG(ensoniq, STATUS));
msleep(20);
}
outl(ensoniq->ctrl | ES_1371_SYNC_RES, ES_REG(ensoniq, CONTROL));
inl(ES_REG(ensoniq, CONTROL));
udelay(20);
outl(ensoniq->ctrl, ES_REG(ensoniq, CONTROL));
snd_es1371_wait_src_ready(ensoniq);
outl(ES_1371_SRC_DISABLE, ES_REG(ensoniq, 1371_SMPRATE));
for (idx = 0; idx < 0x80; idx++)
snd_es1371_src_write(ensoniq, idx, 0);
snd_es1371_src_write(ensoniq, ES_SMPREG_DAC1 + ES_SMPREG_TRUNC_N, 16 << 4);
snd_es1371_src_write(ensoniq, ES_SMPREG_DAC1 + ES_SMPREG_INT_REGS, 16 << 10);
snd_es1371_src_write(ensoniq, ES_SMPREG_DAC2 + ES_SMPREG_TRUNC_N, 16 << 4);
snd_es1371_src_write(ensoniq, ES_SMPREG_DAC2 + ES_SMPREG_INT_REGS, 16 << 10);
snd_es1371_src_write(ensoniq, ES_SMPREG_VOL_ADC, 1 << 12);
snd_es1371_src_write(ensoniq, ES_SMPREG_VOL_ADC + 1, 1 << 12);
snd_es1371_src_write(ensoniq, ES_SMPREG_VOL_DAC1, 1 << 12);
snd_es1371_src_write(ensoniq, ES_SMPREG_VOL_DAC1 + 1, 1 << 12);
snd_es1371_src_write(ensoniq, ES_SMPREG_VOL_DAC2, 1 << 12);
snd_es1371_src_write(ensoniq, ES_SMPREG_VOL_DAC2 + 1, 1 << 12);
snd_es1371_adc_rate(ensoniq, 22050);
snd_es1371_dac1_rate(ensoniq, 22050);
snd_es1371_dac2_rate(ensoniq, 22050);
snd_es1371_wait_src_ready(ensoniq);
outl(0, ES_REG(ensoniq, 1371_SMPRATE));
outl(ES_1371_CODEC_WRITE(0, 0), ES_REG(ensoniq, 1371_CODEC));
#endif
outb(ensoniq->uartc = 0x00, ES_REG(ensoniq, UART_CONTROL));
outb(0x00, ES_REG(ensoniq, UART_RES));
outl(ensoniq->cssr, ES_REG(ensoniq, STATUS));
synchronize_irq(ensoniq->irq);
}
static int snd_ensoniq_suspend(struct device *dev)
{
struct snd_card *card = dev_get_drvdata(dev);
struct ensoniq *ensoniq = card->private_data;
snd_power_change_state(card, SNDRV_CTL_POWER_D3hot);
snd_pcm_suspend_all(ensoniq->pcm1);
snd_pcm_suspend_all(ensoniq->pcm2);
#ifdef CHIP1371
snd_ac97_suspend(ensoniq->u.es1371.ac97);
#else
outw(ES_1370_CODEC_WRITE(AK4531_RESET, 0x02), ES_REG(ensoniq, 1370_CODEC));
inw(ES_REG(ensoniq, 1370_CODEC));
udelay(100);
outw(ES_1370_CODEC_WRITE(AK4531_RESET, 0x03), ES_REG(ensoniq, 1370_CODEC));
inw(ES_REG(ensoniq, 1370_CODEC));
udelay(100);
snd_ak4531_suspend(ensoniq->u.es1370.ak4531);
#endif
return 0;
}
static int snd_ensoniq_resume(struct device *dev)
{
struct snd_card *card = dev_get_drvdata(dev);
struct ensoniq *ensoniq = card->private_data;
snd_ensoniq_chip_init(ensoniq);
#ifdef CHIP1371
snd_ac97_resume(ensoniq->u.es1371.ac97);
#else
snd_ak4531_resume(ensoniq->u.es1370.ak4531);
#endif
snd_power_change_state(card, SNDRV_CTL_POWER_D0);
return 0;
}
static int snd_ensoniq_create(struct snd_card *card,
struct pci_dev *pci,
struct ensoniq **rensoniq)
{
struct ensoniq *ensoniq;
int err;
static struct snd_device_ops ops = {
.dev_free = snd_ensoniq_dev_free,
};
*rensoniq = NULL;
if ((err = pci_enable_device(pci)) < 0)
return err;
ensoniq = kzalloc(sizeof(*ensoniq), GFP_KERNEL);
if (ensoniq == NULL) {
pci_disable_device(pci);
return -ENOMEM;
}
spin_lock_init(&ensoniq->reg_lock);
mutex_init(&ensoniq->src_mutex);
ensoniq->card = card;
ensoniq->pci = pci;
ensoniq->irq = -1;
if ((err = pci_request_regions(pci, "Ensoniq AudioPCI")) < 0) {
kfree(ensoniq);
pci_disable_device(pci);
return err;
}
ensoniq->port = pci_resource_start(pci, 0);
if (request_irq(pci->irq, snd_audiopci_interrupt, IRQF_SHARED,
KBUILD_MODNAME, ensoniq)) {
dev_err(card->dev, "unable to grab IRQ %d\n", pci->irq);
snd_ensoniq_free(ensoniq);
return -EBUSY;
}
ensoniq->irq = pci->irq;
#ifdef CHIP1370
if (snd_dma_alloc_pages(SNDRV_DMA_TYPE_DEV, snd_dma_pci_data(pci),
16, &ensoniq->dma_bug) < 0) {
dev_err(card->dev, "unable to allocate space for phantom area - dma_bug\n");
snd_ensoniq_free(ensoniq);
return -EBUSY;
}
#endif
pci_set_master(pci);
ensoniq->rev = pci->revision;
#ifdef CHIP1370
#if 0
ensoniq->ctrl = ES_1370_CDC_EN | ES_1370_SERR_DISABLE |
ES_1370_PCLKDIVO(ES_1370_SRTODIV(8000));
#else
ensoniq->ctrl = ES_1370_CDC_EN | ES_1370_PCLKDIVO(ES_1370_SRTODIV(8000));
#endif
ensoniq->sctrl = 0;
#else
ensoniq->ctrl = 0;
ensoniq->sctrl = 0;
ensoniq->cssr = 0;
if (snd_pci_quirk_lookup(pci, es1371_amplifier_hack))
ensoniq->ctrl |= ES_1371_GPIO_OUT(1);
if (es1371_quirk_lookup(ensoniq, es1371_ac97_reset_hack))
ensoniq->cssr |= ES_1371_ST_AC97_RST;
#endif
snd_ensoniq_chip_init(ensoniq);
if ((err = snd_device_new(card, SNDRV_DEV_LOWLEVEL, ensoniq, &ops)) < 0) {
snd_ensoniq_free(ensoniq);
return err;
}
snd_ensoniq_proc_init(ensoniq);
*rensoniq = ensoniq;
return 0;
}
static void snd_ensoniq_midi_interrupt(struct ensoniq * ensoniq)
{
struct snd_rawmidi *rmidi = ensoniq->rmidi;
unsigned char status, mask, byte;
if (rmidi == NULL)
return;
spin_lock(&ensoniq->reg_lock);
mask = ensoniq->uartm & ES_MODE_INPUT ? ES_RXRDY : 0;
while (mask) {
status = inb(ES_REG(ensoniq, UART_STATUS));
if ((status & mask) == 0)
break;
byte = inb(ES_REG(ensoniq, UART_DATA));
snd_rawmidi_receive(ensoniq->midi_input, &byte, 1);
}
spin_unlock(&ensoniq->reg_lock);
spin_lock(&ensoniq->reg_lock);
mask = ensoniq->uartm & ES_MODE_OUTPUT ? ES_TXRDY : 0;
while (mask) {
status = inb(ES_REG(ensoniq, UART_STATUS));
if ((status & mask) == 0)
break;
if (snd_rawmidi_transmit(ensoniq->midi_output, &byte, 1) != 1) {
ensoniq->uartc &= ~ES_TXINTENM;
outb(ensoniq->uartc, ES_REG(ensoniq, UART_CONTROL));
mask &= ~ES_TXRDY;
} else {
outb(byte, ES_REG(ensoniq, UART_DATA));
}
}
spin_unlock(&ensoniq->reg_lock);
}
static int snd_ensoniq_midi_input_open(struct snd_rawmidi_substream *substream)
{
struct ensoniq *ensoniq = substream->rmidi->private_data;
spin_lock_irq(&ensoniq->reg_lock);
ensoniq->uartm |= ES_MODE_INPUT;
ensoniq->midi_input = substream;
if (!(ensoniq->uartm & ES_MODE_OUTPUT)) {
outb(ES_CNTRL(3), ES_REG(ensoniq, UART_CONTROL));
outb(ensoniq->uartc = 0, ES_REG(ensoniq, UART_CONTROL));
outl(ensoniq->ctrl |= ES_UART_EN, ES_REG(ensoniq, CONTROL));
}
spin_unlock_irq(&ensoniq->reg_lock);
return 0;
}
static int snd_ensoniq_midi_input_close(struct snd_rawmidi_substream *substream)
{
struct ensoniq *ensoniq = substream->rmidi->private_data;
spin_lock_irq(&ensoniq->reg_lock);
if (!(ensoniq->uartm & ES_MODE_OUTPUT)) {
outb(ensoniq->uartc = 0, ES_REG(ensoniq, UART_CONTROL));
outl(ensoniq->ctrl &= ~ES_UART_EN, ES_REG(ensoniq, CONTROL));
} else {
outb(ensoniq->uartc &= ~ES_RXINTEN, ES_REG(ensoniq, UART_CONTROL));
}
ensoniq->midi_input = NULL;
ensoniq->uartm &= ~ES_MODE_INPUT;
spin_unlock_irq(&ensoniq->reg_lock);
return 0;
}
static int snd_ensoniq_midi_output_open(struct snd_rawmidi_substream *substream)
{
struct ensoniq *ensoniq = substream->rmidi->private_data;
spin_lock_irq(&ensoniq->reg_lock);
ensoniq->uartm |= ES_MODE_OUTPUT;
ensoniq->midi_output = substream;
if (!(ensoniq->uartm & ES_MODE_INPUT)) {
outb(ES_CNTRL(3), ES_REG(ensoniq, UART_CONTROL));
outb(ensoniq->uartc = 0, ES_REG(ensoniq, UART_CONTROL));
outl(ensoniq->ctrl |= ES_UART_EN, ES_REG(ensoniq, CONTROL));
}
spin_unlock_irq(&ensoniq->reg_lock);
return 0;
}
static int snd_ensoniq_midi_output_close(struct snd_rawmidi_substream *substream)
{
struct ensoniq *ensoniq = substream->rmidi->private_data;
spin_lock_irq(&ensoniq->reg_lock);
if (!(ensoniq->uartm & ES_MODE_INPUT)) {
outb(ensoniq->uartc = 0, ES_REG(ensoniq, UART_CONTROL));
outl(ensoniq->ctrl &= ~ES_UART_EN, ES_REG(ensoniq, CONTROL));
} else {
outb(ensoniq->uartc &= ~ES_TXINTENM, ES_REG(ensoniq, UART_CONTROL));
}
ensoniq->midi_output = NULL;
ensoniq->uartm &= ~ES_MODE_OUTPUT;
spin_unlock_irq(&ensoniq->reg_lock);
return 0;
}
static void snd_ensoniq_midi_input_trigger(struct snd_rawmidi_substream *substream, int up)
{
unsigned long flags;
struct ensoniq *ensoniq = substream->rmidi->private_data;
int idx;
spin_lock_irqsave(&ensoniq->reg_lock, flags);
if (up) {
if ((ensoniq->uartc & ES_RXINTEN) == 0) {
for (idx = 0; idx < 32; idx++)
inb(ES_REG(ensoniq, UART_DATA));
ensoniq->uartc |= ES_RXINTEN;
outb(ensoniq->uartc, ES_REG(ensoniq, UART_CONTROL));
}
} else {
if (ensoniq->uartc & ES_RXINTEN) {
ensoniq->uartc &= ~ES_RXINTEN;
outb(ensoniq->uartc, ES_REG(ensoniq, UART_CONTROL));
}
}
spin_unlock_irqrestore(&ensoniq->reg_lock, flags);
}
static void snd_ensoniq_midi_output_trigger(struct snd_rawmidi_substream *substream, int up)
{
unsigned long flags;
struct ensoniq *ensoniq = substream->rmidi->private_data;
unsigned char byte;
spin_lock_irqsave(&ensoniq->reg_lock, flags);
if (up) {
if (ES_TXINTENI(ensoniq->uartc) == 0) {
ensoniq->uartc |= ES_TXINTENO(1);
while (ES_TXINTENI(ensoniq->uartc) == 1 &&
(inb(ES_REG(ensoniq, UART_STATUS)) & ES_TXRDY)) {
if (snd_rawmidi_transmit(substream, &byte, 1) != 1) {
ensoniq->uartc &= ~ES_TXINTENM;
} else {
outb(byte, ES_REG(ensoniq, UART_DATA));
}
}
outb(ensoniq->uartc, ES_REG(ensoniq, UART_CONTROL));
}
} else {
if (ES_TXINTENI(ensoniq->uartc) == 1) {
ensoniq->uartc &= ~ES_TXINTENM;
outb(ensoniq->uartc, ES_REG(ensoniq, UART_CONTROL));
}
}
spin_unlock_irqrestore(&ensoniq->reg_lock, flags);
}
static int snd_ensoniq_midi(struct ensoniq *ensoniq, int device)
{
struct snd_rawmidi *rmidi;
int err;
if ((err = snd_rawmidi_new(ensoniq->card, "ES1370/1", device, 1, 1, &rmidi)) < 0)
return err;
strcpy(rmidi->name, CHIP_NAME);
snd_rawmidi_set_ops(rmidi, SNDRV_RAWMIDI_STREAM_OUTPUT, &snd_ensoniq_midi_output);
snd_rawmidi_set_ops(rmidi, SNDRV_RAWMIDI_STREAM_INPUT, &snd_ensoniq_midi_input);
rmidi->info_flags |= SNDRV_RAWMIDI_INFO_OUTPUT | SNDRV_RAWMIDI_INFO_INPUT |
SNDRV_RAWMIDI_INFO_DUPLEX;
rmidi->private_data = ensoniq;
ensoniq->rmidi = rmidi;
return 0;
}
static irqreturn_t snd_audiopci_interrupt(int irq, void *dev_id)
{
struct ensoniq *ensoniq = dev_id;
unsigned int status, sctrl;
if (ensoniq == NULL)
return IRQ_NONE;
status = inl(ES_REG(ensoniq, STATUS));
if (!(status & ES_INTR))
return IRQ_NONE;
spin_lock(&ensoniq->reg_lock);
sctrl = ensoniq->sctrl;
if (status & ES_DAC1)
sctrl &= ~ES_P1_INT_EN;
if (status & ES_DAC2)
sctrl &= ~ES_P2_INT_EN;
if (status & ES_ADC)
sctrl &= ~ES_R1_INT_EN;
outl(sctrl, ES_REG(ensoniq, SERIAL));
outl(ensoniq->sctrl, ES_REG(ensoniq, SERIAL));
spin_unlock(&ensoniq->reg_lock);
if (status & ES_UART)
snd_ensoniq_midi_interrupt(ensoniq);
if ((status & ES_DAC2) && ensoniq->playback2_substream)
snd_pcm_period_elapsed(ensoniq->playback2_substream);
if ((status & ES_ADC) && ensoniq->capture_substream)
snd_pcm_period_elapsed(ensoniq->capture_substream);
if ((status & ES_DAC1) && ensoniq->playback1_substream)
snd_pcm_period_elapsed(ensoniq->playback1_substream);
return IRQ_HANDLED;
}
static int snd_audiopci_probe(struct pci_dev *pci,
const struct pci_device_id *pci_id)
{
static int dev;
struct snd_card *card;
struct ensoniq *ensoniq;
int err, pcm_devs[2];
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
if ((err = snd_ensoniq_create(card, pci, &ensoniq)) < 0) {
snd_card_free(card);
return err;
}
card->private_data = ensoniq;
pcm_devs[0] = 0; pcm_devs[1] = 1;
#ifdef CHIP1370
if ((err = snd_ensoniq_1370_mixer(ensoniq)) < 0) {
snd_card_free(card);
return err;
}
#endif
#ifdef CHIP1371
if ((err = snd_ensoniq_1371_mixer(ensoniq, spdif[dev], lineio[dev])) < 0) {
snd_card_free(card);
return err;
}
#endif
if ((err = snd_ensoniq_pcm(ensoniq, 0)) < 0) {
snd_card_free(card);
return err;
}
if ((err = snd_ensoniq_pcm2(ensoniq, 1)) < 0) {
snd_card_free(card);
return err;
}
if ((err = snd_ensoniq_midi(ensoniq, 0)) < 0) {
snd_card_free(card);
return err;
}
snd_ensoniq_create_gameport(ensoniq, dev);
strcpy(card->driver, DRIVER_NAME);
strcpy(card->shortname, "Ensoniq AudioPCI");
sprintf(card->longname, "%s %s at 0x%lx, irq %i",
card->shortname,
card->driver,
ensoniq->port,
ensoniq->irq);
if ((err = snd_card_register(card)) < 0) {
snd_card_free(card);
return err;
}
pci_set_drvdata(pci, card);
dev++;
return 0;
}
static void snd_audiopci_remove(struct pci_dev *pci)
{
snd_card_free(pci_get_drvdata(pci));
}
