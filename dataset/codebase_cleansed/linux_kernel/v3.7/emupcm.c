static void snd_emu10k1_pcm_interrupt(struct snd_emu10k1 *emu,
struct snd_emu10k1_voice *voice)
{
struct snd_emu10k1_pcm *epcm;
if ((epcm = voice->epcm) == NULL)
return;
if (epcm->substream == NULL)
return;
#if 0
printk(KERN_DEBUG "IRQ: position = 0x%x, period = 0x%x, size = 0x%x\n",
epcm->substream->runtime->hw->pointer(emu, epcm->substream),
snd_pcm_lib_period_bytes(epcm->substream),
snd_pcm_lib_buffer_bytes(epcm->substream));
#endif
snd_pcm_period_elapsed(epcm->substream);
}
static void snd_emu10k1_pcm_ac97adc_interrupt(struct snd_emu10k1 *emu,
unsigned int status)
{
#if 0
if (status & IPR_ADCBUFHALFFULL) {
if (emu->pcm_capture_substream->runtime->mode == SNDRV_PCM_MODE_FRAME)
return;
}
#endif
snd_pcm_period_elapsed(emu->pcm_capture_substream);
}
static void snd_emu10k1_pcm_ac97mic_interrupt(struct snd_emu10k1 *emu,
unsigned int status)
{
#if 0
if (status & IPR_MICBUFHALFFULL) {
if (emu->pcm_capture_mic_substream->runtime->mode == SNDRV_PCM_MODE_FRAME)
return;
}
#endif
snd_pcm_period_elapsed(emu->pcm_capture_mic_substream);
}
static void snd_emu10k1_pcm_efx_interrupt(struct snd_emu10k1 *emu,
unsigned int status)
{
#if 0
if (status & IPR_EFXBUFHALFFULL) {
if (emu->pcm_capture_efx_substream->runtime->mode == SNDRV_PCM_MODE_FRAME)
return;
}
#endif
snd_pcm_period_elapsed(emu->pcm_capture_efx_substream);
}
static snd_pcm_uframes_t snd_emu10k1_efx_playback_pointer(struct snd_pcm_substream *substream)
{
struct snd_emu10k1 *emu = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
struct snd_emu10k1_pcm *epcm = runtime->private_data;
unsigned int ptr;
if (!epcm->running)
return 0;
ptr = snd_emu10k1_ptr_read(emu, CCCA, epcm->voices[0]->number) & 0x00ffffff;
ptr += runtime->buffer_size;
ptr -= epcm->ccca_start_addr;
ptr %= runtime->buffer_size;
return ptr;
}
static int snd_emu10k1_pcm_channel_alloc(struct snd_emu10k1_pcm * epcm, int voices)
{
int err, i;
if (epcm->voices[1] != NULL && voices < 2) {
snd_emu10k1_voice_free(epcm->emu, epcm->voices[1]);
epcm->voices[1] = NULL;
}
for (i = 0; i < voices; i++) {
if (epcm->voices[i] == NULL)
break;
}
if (i == voices)
return 0;
for (i = 0; i < ARRAY_SIZE(epcm->voices); i++) {
if (epcm->voices[i]) {
snd_emu10k1_voice_free(epcm->emu, epcm->voices[i]);
epcm->voices[i] = NULL;
}
}
err = snd_emu10k1_voice_alloc(epcm->emu,
epcm->type == PLAYBACK_EMUVOICE ? EMU10K1_PCM : EMU10K1_EFX,
voices,
&epcm->voices[0]);
if (err < 0)
return err;
epcm->voices[0]->epcm = epcm;
if (voices > 1) {
for (i = 1; i < voices; i++) {
epcm->voices[i] = &epcm->emu->voices[epcm->voices[0]->number + i];
epcm->voices[i]->epcm = epcm;
}
}
if (epcm->extra == NULL) {
err = snd_emu10k1_voice_alloc(epcm->emu,
epcm->type == PLAYBACK_EMUVOICE ? EMU10K1_PCM : EMU10K1_EFX,
1,
&epcm->extra);
if (err < 0) {
for (i = 0; i < voices; i++) {
snd_emu10k1_voice_free(epcm->emu, epcm->voices[i]);
epcm->voices[i] = NULL;
}
return err;
}
epcm->extra->epcm = epcm;
epcm->extra->interrupt = snd_emu10k1_pcm_interrupt;
}
return 0;
}
static unsigned int snd_emu10k1_capture_rate_reg(unsigned int rate)
{
switch (rate) {
case 8000: return ADCCR_SAMPLERATE_8;
case 11025: return ADCCR_SAMPLERATE_11;
case 16000: return ADCCR_SAMPLERATE_16;
case 22050: return ADCCR_SAMPLERATE_22;
case 24000: return ADCCR_SAMPLERATE_24;
case 32000: return ADCCR_SAMPLERATE_32;
case 44100: return ADCCR_SAMPLERATE_44;
case 48000: return ADCCR_SAMPLERATE_48;
default:
snd_BUG();
return ADCCR_SAMPLERATE_8;
}
}
static unsigned int snd_emu10k1_audigy_capture_rate_reg(unsigned int rate)
{
switch (rate) {
case 8000: return A_ADCCR_SAMPLERATE_8;
case 11025: return A_ADCCR_SAMPLERATE_11;
case 12000: return A_ADCCR_SAMPLERATE_12;
case 16000: return ADCCR_SAMPLERATE_16;
case 22050: return ADCCR_SAMPLERATE_22;
case 24000: return ADCCR_SAMPLERATE_24;
case 32000: return ADCCR_SAMPLERATE_32;
case 44100: return ADCCR_SAMPLERATE_44;
case 48000: return ADCCR_SAMPLERATE_48;
default:
snd_BUG();
return A_ADCCR_SAMPLERATE_8;
}
}
static unsigned int emu10k1_calc_pitch_target(unsigned int rate)
{
unsigned int pitch_target;
pitch_target = (rate << 8) / 375;
pitch_target = (pitch_target >> 1) + (pitch_target & 1);
return pitch_target;
}
static unsigned int emu10k1_select_interprom(unsigned int pitch_target)
{
if (pitch_target == PITCH_48000)
return CCCA_INTERPROM_0;
else if (pitch_target < PITCH_48000)
return CCCA_INTERPROM_1;
else if (pitch_target >= PITCH_96000)
return CCCA_INTERPROM_0;
else if (pitch_target >= PITCH_85000)
return CCCA_INTERPROM_6;
else if (pitch_target >= PITCH_80726)
return CCCA_INTERPROM_5;
else if (pitch_target >= PITCH_67882)
return CCCA_INTERPROM_4;
else if (pitch_target >= PITCH_57081)
return CCCA_INTERPROM_3;
else
return CCCA_INTERPROM_2;
}
static inline int emu10k1_ccis(int stereo, int w_16)
{
if (w_16) {
return stereo ? 24 : 26;
} else {
return stereo ? 24*2 : 26*2;
}
}
static void snd_emu10k1_pcm_init_voice(struct snd_emu10k1 *emu,
int master, int extra,
struct snd_emu10k1_voice *evoice,
unsigned int start_addr,
unsigned int end_addr,
struct snd_emu10k1_pcm_mixer *mix)
{
struct snd_pcm_substream *substream = evoice->epcm->substream;
struct snd_pcm_runtime *runtime = substream->runtime;
unsigned int silent_page, tmp;
int voice, stereo, w_16;
unsigned char attn, send_amount[8];
unsigned char send_routing[8];
unsigned long flags;
unsigned int pitch_target;
unsigned int ccis;
voice = evoice->number;
stereo = runtime->channels == 2;
w_16 = snd_pcm_format_width(runtime->format) == 16;
if (!extra && stereo) {
start_addr >>= 1;
end_addr >>= 1;
}
if (w_16) {
start_addr >>= 1;
end_addr >>= 1;
}
spin_lock_irqsave(&emu->reg_lock, flags);
if (extra) {
attn = 0;
memset(send_routing, 0, sizeof(send_routing));
send_routing[0] = 0;
send_routing[1] = 1;
send_routing[2] = 2;
send_routing[3] = 3;
memset(send_amount, 0, sizeof(send_amount));
} else {
tmp = stereo ? (master ? 1 : 2) : 0;
memcpy(send_routing, &mix->send_routing[tmp][0], 8);
memcpy(send_amount, &mix->send_volume[tmp][0], 8);
}
ccis = emu10k1_ccis(stereo, w_16);
if (master) {
evoice->epcm->ccca_start_addr = start_addr + ccis;
if (extra) {
start_addr += ccis;
end_addr += ccis + emu->delay_pcm_irq;
}
if (stereo && !extra) {
snd_emu10k1_ptr_write(emu, CPF, voice, CPF_STEREO_MASK);
snd_emu10k1_ptr_write(emu, CPF, (voice + 1), CPF_STEREO_MASK);
} else {
snd_emu10k1_ptr_write(emu, CPF, voice, 0);
}
}
if (emu->audigy) {
snd_emu10k1_ptr_write(emu, A_FXRT1, voice,
snd_emu10k1_compose_audigy_fxrt1(send_routing));
snd_emu10k1_ptr_write(emu, A_FXRT2, voice,
snd_emu10k1_compose_audigy_fxrt2(send_routing));
snd_emu10k1_ptr_write(emu, A_SENDAMOUNTS, voice,
((unsigned int)send_amount[4] << 24) |
((unsigned int)send_amount[5] << 16) |
((unsigned int)send_amount[6] << 8) |
(unsigned int)send_amount[7]);
} else
snd_emu10k1_ptr_write(emu, FXRT, voice,
snd_emu10k1_compose_send_routing(send_routing));
snd_emu10k1_ptr_write(emu, PTRX, voice, (send_amount[0] << 8) | send_amount[1]);
snd_emu10k1_ptr_write(emu, DSL, voice, end_addr | (send_amount[3] << 24));
snd_emu10k1_ptr_write(emu, PSST, voice,
(start_addr + (extra ? emu->delay_pcm_irq : 0)) |
(send_amount[2] << 24));
if (emu->card_capabilities->emu_model)
pitch_target = PITCH_48000;
else
pitch_target = emu10k1_calc_pitch_target(runtime->rate);
if (extra)
snd_emu10k1_ptr_write(emu, CCCA, voice, start_addr |
emu10k1_select_interprom(pitch_target) |
(w_16 ? 0 : CCCA_8BITSELECT));
else
snd_emu10k1_ptr_write(emu, CCCA, voice, (start_addr + ccis) |
emu10k1_select_interprom(pitch_target) |
(w_16 ? 0 : CCCA_8BITSELECT));
snd_emu10k1_ptr_write(emu, Z1, voice, 0);
snd_emu10k1_ptr_write(emu, Z2, voice, 0);
silent_page = ((unsigned int)emu->silent_page.addr << 1) | MAP_PTI_MASK;
snd_emu10k1_ptr_write(emu, MAPA, voice, silent_page);
snd_emu10k1_ptr_write(emu, MAPB, voice, silent_page);
snd_emu10k1_ptr_write(emu, CVCF, voice, 0xffff);
snd_emu10k1_ptr_write(emu, VTFT, voice, 0xffff);
snd_emu10k1_ptr_write(emu, ATKHLDM, voice, 0);
snd_emu10k1_ptr_write(emu, DCYSUSM, voice, 0x007f);
snd_emu10k1_ptr_write(emu, LFOVAL1, voice, 0x8000);
snd_emu10k1_ptr_write(emu, LFOVAL2, voice, 0x8000);
snd_emu10k1_ptr_write(emu, FMMOD, voice, 0);
snd_emu10k1_ptr_write(emu, TREMFRQ, voice, 0);
snd_emu10k1_ptr_write(emu, FM2FRQ2, voice, 0);
snd_emu10k1_ptr_write(emu, ENVVAL, voice, 0x8000);
snd_emu10k1_ptr_write(emu, ATKHLDV, voice, 0x7f7f);
snd_emu10k1_ptr_write(emu, ENVVOL, voice, 0x0000);
snd_emu10k1_ptr_write(emu, PEFE_FILTERAMOUNT, voice, 0x7f);
snd_emu10k1_ptr_write(emu, PEFE_PITCHAMOUNT, voice, 0);
spin_unlock_irqrestore(&emu->reg_lock, flags);
}
static int snd_emu10k1_playback_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *hw_params)
{
struct snd_emu10k1 *emu = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
struct snd_emu10k1_pcm *epcm = runtime->private_data;
int err;
if ((err = snd_emu10k1_pcm_channel_alloc(epcm, params_channels(hw_params))) < 0)
return err;
if ((err = snd_pcm_lib_malloc_pages(substream, params_buffer_bytes(hw_params))) < 0)
return err;
if (err > 0) {
int mapped;
if (epcm->memblk != NULL)
snd_emu10k1_free_pages(emu, epcm->memblk);
epcm->memblk = snd_emu10k1_alloc_pages(emu, substream);
epcm->start_addr = 0;
if (! epcm->memblk)
return -ENOMEM;
mapped = ((struct snd_emu10k1_memblk *)epcm->memblk)->mapped_page;
if (mapped < 0)
return -ENOMEM;
epcm->start_addr = mapped << PAGE_SHIFT;
}
return 0;
}
static int snd_emu10k1_playback_hw_free(struct snd_pcm_substream *substream)
{
struct snd_emu10k1 *emu = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
struct snd_emu10k1_pcm *epcm;
if (runtime->private_data == NULL)
return 0;
epcm = runtime->private_data;
if (epcm->extra) {
snd_emu10k1_voice_free(epcm->emu, epcm->extra);
epcm->extra = NULL;
}
if (epcm->voices[1]) {
snd_emu10k1_voice_free(epcm->emu, epcm->voices[1]);
epcm->voices[1] = NULL;
}
if (epcm->voices[0]) {
snd_emu10k1_voice_free(epcm->emu, epcm->voices[0]);
epcm->voices[0] = NULL;
}
if (epcm->memblk) {
snd_emu10k1_free_pages(emu, epcm->memblk);
epcm->memblk = NULL;
epcm->start_addr = 0;
}
snd_pcm_lib_free_pages(substream);
return 0;
}
static int snd_emu10k1_efx_playback_hw_free(struct snd_pcm_substream *substream)
{
struct snd_emu10k1 *emu = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
struct snd_emu10k1_pcm *epcm;
int i;
if (runtime->private_data == NULL)
return 0;
epcm = runtime->private_data;
if (epcm->extra) {
snd_emu10k1_voice_free(epcm->emu, epcm->extra);
epcm->extra = NULL;
}
for (i = 0; i < NUM_EFX_PLAYBACK; i++) {
if (epcm->voices[i]) {
snd_emu10k1_voice_free(epcm->emu, epcm->voices[i]);
epcm->voices[i] = NULL;
}
}
if (epcm->memblk) {
snd_emu10k1_free_pages(emu, epcm->memblk);
epcm->memblk = NULL;
epcm->start_addr = 0;
}
snd_pcm_lib_free_pages(substream);
return 0;
}
static int snd_emu10k1_playback_prepare(struct snd_pcm_substream *substream)
{
struct snd_emu10k1 *emu = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
struct snd_emu10k1_pcm *epcm = runtime->private_data;
unsigned int start_addr, end_addr;
start_addr = epcm->start_addr;
end_addr = snd_pcm_lib_period_bytes(substream);
if (runtime->channels == 2) {
start_addr >>= 1;
end_addr >>= 1;
}
end_addr += start_addr;
snd_emu10k1_pcm_init_voice(emu, 1, 1, epcm->extra,
start_addr, end_addr, NULL);
start_addr = epcm->start_addr;
end_addr = epcm->start_addr + snd_pcm_lib_buffer_bytes(substream);
snd_emu10k1_pcm_init_voice(emu, 1, 0, epcm->voices[0],
start_addr, end_addr,
&emu->pcm_mixer[substream->number]);
if (epcm->voices[1])
snd_emu10k1_pcm_init_voice(emu, 0, 0, epcm->voices[1],
start_addr, end_addr,
&emu->pcm_mixer[substream->number]);
return 0;
}
static int snd_emu10k1_efx_playback_prepare(struct snd_pcm_substream *substream)
{
struct snd_emu10k1 *emu = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
struct snd_emu10k1_pcm *epcm = runtime->private_data;
unsigned int start_addr, end_addr;
unsigned int channel_size;
int i;
start_addr = epcm->start_addr;
end_addr = epcm->start_addr + snd_pcm_lib_buffer_bytes(substream);
channel_size = ( end_addr - start_addr ) / NUM_EFX_PLAYBACK;
snd_emu10k1_pcm_init_voice(emu, 1, 1, epcm->extra,
start_addr, start_addr + (channel_size / 2), NULL);
snd_emu10k1_pcm_init_voice(emu, 1, 0, epcm->voices[0],
start_addr, start_addr + channel_size,
&emu->efx_pcm_mixer[0]);
start_addr += channel_size;
for (i = 1; i < NUM_EFX_PLAYBACK; i++) {
snd_emu10k1_pcm_init_voice(emu, 0, 0, epcm->voices[i],
start_addr, start_addr + channel_size,
&emu->efx_pcm_mixer[i]);
start_addr += channel_size;
}
return 0;
}
static int snd_emu10k1_capture_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *hw_params)
{
return snd_pcm_lib_malloc_pages(substream, params_buffer_bytes(hw_params));
}
static int snd_emu10k1_capture_hw_free(struct snd_pcm_substream *substream)
{
return snd_pcm_lib_free_pages(substream);
}
static int snd_emu10k1_capture_prepare(struct snd_pcm_substream *substream)
{
struct snd_emu10k1 *emu = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
struct snd_emu10k1_pcm *epcm = runtime->private_data;
int idx;
snd_emu10k1_ptr_write(emu, epcm->capture_bs_reg, 0, 0);
switch (epcm->type) {
case CAPTURE_AC97ADC:
snd_emu10k1_ptr_write(emu, ADCCR, 0, 0);
break;
case CAPTURE_EFX:
if (emu->audigy) {
snd_emu10k1_ptr_write(emu, A_FXWC1, 0, 0);
snd_emu10k1_ptr_write(emu, A_FXWC2, 0, 0);
} else
snd_emu10k1_ptr_write(emu, FXWC, 0, 0);
break;
default:
break;
}
snd_emu10k1_ptr_write(emu, epcm->capture_ba_reg, 0, runtime->dma_addr);
epcm->capture_bufsize = snd_pcm_lib_buffer_bytes(substream);
epcm->capture_bs_val = 0;
for (idx = 0; idx < 31; idx++) {
if (capture_period_sizes[idx] == epcm->capture_bufsize) {
epcm->capture_bs_val = idx + 1;
break;
}
}
if (epcm->capture_bs_val == 0) {
snd_BUG();
epcm->capture_bs_val++;
}
if (epcm->type == CAPTURE_AC97ADC) {
epcm->capture_cr_val = emu->audigy ? A_ADCCR_LCHANENABLE : ADCCR_LCHANENABLE;
if (runtime->channels > 1)
epcm->capture_cr_val |= emu->audigy ? A_ADCCR_RCHANENABLE : ADCCR_RCHANENABLE;
epcm->capture_cr_val |= emu->audigy ?
snd_emu10k1_audigy_capture_rate_reg(runtime->rate) :
snd_emu10k1_capture_rate_reg(runtime->rate);
}
return 0;
}
static void snd_emu10k1_playback_invalidate_cache(struct snd_emu10k1 *emu, int extra, struct snd_emu10k1_voice *evoice)
{
struct snd_pcm_runtime *runtime;
unsigned int voice, stereo, i, ccis, cra = 64, cs, sample;
if (evoice == NULL)
return;
runtime = evoice->epcm->substream->runtime;
voice = evoice->number;
stereo = (!extra && runtime->channels == 2);
sample = snd_pcm_format_width(runtime->format) == 16 ? 0 : 0x80808080;
ccis = emu10k1_ccis(stereo, sample == 0);
cs = (sample == 0) ? (32-ccis) : (64-ccis+1) >> 1;
if (cs > 16) cs = 16;
for (i = 0; i < cs; i++) {
snd_emu10k1_ptr_write(emu, CD0 + i, voice, sample);
if (stereo) {
snd_emu10k1_ptr_write(emu, CD0 + i, voice + 1, sample);
}
}
snd_emu10k1_ptr_write(emu, CCR_CACHEINVALIDSIZE, voice, 0);
snd_emu10k1_ptr_write(emu, CCR_READADDRESS, voice, cra);
if (stereo) {
snd_emu10k1_ptr_write(emu, CCR_CACHEINVALIDSIZE, voice + 1, 0);
snd_emu10k1_ptr_write(emu, CCR_READADDRESS, voice + 1, cra);
}
snd_emu10k1_ptr_write(emu, CCR_CACHEINVALIDSIZE, voice, ccis);
if (stereo) {
snd_emu10k1_ptr_write(emu, CCR_CACHEINVALIDSIZE, voice+1, ccis);
}
}
static void snd_emu10k1_playback_prepare_voice(struct snd_emu10k1 *emu, struct snd_emu10k1_voice *evoice,
int master, int extra,
struct snd_emu10k1_pcm_mixer *mix)
{
struct snd_pcm_substream *substream;
struct snd_pcm_runtime *runtime;
unsigned int attn, vattn;
unsigned int voice, tmp;
if (evoice == NULL)
return;
substream = evoice->epcm->substream;
runtime = substream->runtime;
voice = evoice->number;
attn = extra ? 0 : 0x00ff;
tmp = runtime->channels == 2 ? (master ? 1 : 2) : 0;
vattn = mix != NULL ? (mix->attn[tmp] << 16) : 0;
snd_emu10k1_ptr_write(emu, IFATN, voice, attn);
snd_emu10k1_ptr_write(emu, VTFT, voice, vattn | 0xffff);
snd_emu10k1_ptr_write(emu, CVCF, voice, vattn | 0xffff);
snd_emu10k1_ptr_write(emu, DCYSUSV, voice, 0x7f7f);
snd_emu10k1_voice_clear_loop_stop(emu, voice);
}
static void snd_emu10k1_playback_trigger_voice(struct snd_emu10k1 *emu, struct snd_emu10k1_voice *evoice, int master, int extra)
{
struct snd_pcm_substream *substream;
struct snd_pcm_runtime *runtime;
unsigned int voice, pitch, pitch_target;
if (evoice == NULL)
return;
substream = evoice->epcm->substream;
runtime = substream->runtime;
voice = evoice->number;
pitch = snd_emu10k1_rate_to_pitch(runtime->rate) >> 8;
if (emu->card_capabilities->emu_model)
pitch_target = PITCH_48000;
else
pitch_target = emu10k1_calc_pitch_target(runtime->rate);
snd_emu10k1_ptr_write(emu, PTRX_PITCHTARGET, voice, pitch_target);
if (master || evoice->epcm->type == PLAYBACK_EFX)
snd_emu10k1_ptr_write(emu, CPF_CURRENTPITCH, voice, pitch_target);
snd_emu10k1_ptr_write(emu, IP, voice, pitch);
if (extra)
snd_emu10k1_voice_intr_enable(emu, voice);
}
static void snd_emu10k1_playback_stop_voice(struct snd_emu10k1 *emu, struct snd_emu10k1_voice *evoice)
{
unsigned int voice;
if (evoice == NULL)
return;
voice = evoice->number;
snd_emu10k1_voice_intr_disable(emu, voice);
snd_emu10k1_ptr_write(emu, PTRX_PITCHTARGET, voice, 0);
snd_emu10k1_ptr_write(emu, CPF_CURRENTPITCH, voice, 0);
snd_emu10k1_ptr_write(emu, IFATN, voice, 0xffff);
snd_emu10k1_ptr_write(emu, VTFT, voice, 0xffff);
snd_emu10k1_ptr_write(emu, CVCF, voice, 0xffff);
snd_emu10k1_ptr_write(emu, IP, voice, 0);
}
static inline void snd_emu10k1_playback_mangle_extra(struct snd_emu10k1 *emu,
struct snd_emu10k1_pcm *epcm,
struct snd_pcm_substream *substream,
struct snd_pcm_runtime *runtime)
{
unsigned int ptr, period_pos;
period_pos = runtime->status->hw_ptr - runtime->hw_ptr_interrupt;
period_pos %= runtime->period_size;
ptr = snd_emu10k1_ptr_read(emu, CCCA, epcm->extra->number);
ptr &= ~0x00ffffff;
ptr |= epcm->ccca_start_addr + period_pos;
snd_emu10k1_ptr_write(emu, CCCA, epcm->extra->number, ptr);
}
static int snd_emu10k1_playback_trigger(struct snd_pcm_substream *substream,
int cmd)
{
struct snd_emu10k1 *emu = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
struct snd_emu10k1_pcm *epcm = runtime->private_data;
struct snd_emu10k1_pcm_mixer *mix;
int result = 0;
spin_lock(&emu->reg_lock);
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
snd_emu10k1_playback_invalidate_cache(emu, 1, epcm->extra);
snd_emu10k1_playback_invalidate_cache(emu, 0, epcm->voices[0]);
case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
case SNDRV_PCM_TRIGGER_RESUME:
if (cmd == SNDRV_PCM_TRIGGER_PAUSE_RELEASE)
snd_emu10k1_playback_mangle_extra(emu, epcm, substream, runtime);
mix = &emu->pcm_mixer[substream->number];
snd_emu10k1_playback_prepare_voice(emu, epcm->voices[0], 1, 0, mix);
snd_emu10k1_playback_prepare_voice(emu, epcm->voices[1], 0, 0, mix);
snd_emu10k1_playback_prepare_voice(emu, epcm->extra, 1, 1, NULL);
snd_emu10k1_playback_trigger_voice(emu, epcm->voices[0], 1, 0);
snd_emu10k1_playback_trigger_voice(emu, epcm->voices[1], 0, 0);
snd_emu10k1_playback_trigger_voice(emu, epcm->extra, 1, 1);
epcm->running = 1;
break;
case SNDRV_PCM_TRIGGER_STOP:
case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
case SNDRV_PCM_TRIGGER_SUSPEND:
epcm->running = 0;
snd_emu10k1_playback_stop_voice(emu, epcm->voices[0]);
snd_emu10k1_playback_stop_voice(emu, epcm->voices[1]);
snd_emu10k1_playback_stop_voice(emu, epcm->extra);
break;
default:
result = -EINVAL;
break;
}
spin_unlock(&emu->reg_lock);
return result;
}
static int snd_emu10k1_capture_trigger(struct snd_pcm_substream *substream,
int cmd)
{
struct snd_emu10k1 *emu = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
struct snd_emu10k1_pcm *epcm = runtime->private_data;
int result = 0;
spin_lock(&emu->reg_lock);
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
case SNDRV_PCM_TRIGGER_RESUME:
outl(epcm->capture_ipr, emu->port + IPR);
snd_emu10k1_intr_enable(emu, epcm->capture_inte);
switch (epcm->type) {
case CAPTURE_AC97ADC:
snd_emu10k1_ptr_write(emu, ADCCR, 0, epcm->capture_cr_val);
break;
case CAPTURE_EFX:
if (emu->audigy) {
snd_emu10k1_ptr_write(emu, A_FXWC1, 0, epcm->capture_cr_val);
snd_emu10k1_ptr_write(emu, A_FXWC2, 0, epcm->capture_cr_val2);
snd_printdd("cr_val=0x%x, cr_val2=0x%x\n", epcm->capture_cr_val, epcm->capture_cr_val2);
} else
snd_emu10k1_ptr_write(emu, FXWC, 0, epcm->capture_cr_val);
break;
default:
break;
}
snd_emu10k1_ptr_write(emu, epcm->capture_bs_reg, 0, epcm->capture_bs_val);
epcm->running = 1;
epcm->first_ptr = 1;
break;
case SNDRV_PCM_TRIGGER_STOP:
case SNDRV_PCM_TRIGGER_SUSPEND:
epcm->running = 0;
snd_emu10k1_intr_disable(emu, epcm->capture_inte);
outl(epcm->capture_ipr, emu->port + IPR);
snd_emu10k1_ptr_write(emu, epcm->capture_bs_reg, 0, 0);
switch (epcm->type) {
case CAPTURE_AC97ADC:
snd_emu10k1_ptr_write(emu, ADCCR, 0, 0);
break;
case CAPTURE_EFX:
if (emu->audigy) {
snd_emu10k1_ptr_write(emu, A_FXWC1, 0, 0);
snd_emu10k1_ptr_write(emu, A_FXWC2, 0, 0);
} else
snd_emu10k1_ptr_write(emu, FXWC, 0, 0);
break;
default:
break;
}
break;
default:
result = -EINVAL;
}
spin_unlock(&emu->reg_lock);
return result;
}
static snd_pcm_uframes_t snd_emu10k1_playback_pointer(struct snd_pcm_substream *substream)
{
struct snd_emu10k1 *emu = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
struct snd_emu10k1_pcm *epcm = runtime->private_data;
unsigned int ptr;
if (!epcm->running)
return 0;
ptr = snd_emu10k1_ptr_read(emu, CCCA, epcm->voices[0]->number) & 0x00ffffff;
#if 0
ptr += runtime->buffer_size;
ptr -= epcm->ccca_start_addr;
ptr %= runtime->buffer_size;
#else
if (ptr < epcm->ccca_start_addr)
ptr += runtime->buffer_size - epcm->ccca_start_addr;
else {
ptr -= epcm->ccca_start_addr;
if (ptr >= runtime->buffer_size)
ptr -= runtime->buffer_size;
}
#endif
return ptr;
}
static int snd_emu10k1_efx_playback_trigger(struct snd_pcm_substream *substream,
int cmd)
{
struct snd_emu10k1 *emu = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
struct snd_emu10k1_pcm *epcm = runtime->private_data;
int i;
int result = 0;
spin_lock(&emu->reg_lock);
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
for (i = 0; i < NUM_EFX_PLAYBACK; i++) {
snd_emu10k1_playback_invalidate_cache(emu, 0, epcm->voices[i]);
}
snd_emu10k1_playback_invalidate_cache(emu, 1, epcm->extra);
case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
case SNDRV_PCM_TRIGGER_RESUME:
snd_emu10k1_playback_prepare_voice(emu, epcm->extra, 1, 1, NULL);
snd_emu10k1_playback_prepare_voice(emu, epcm->voices[0], 0, 0,
&emu->efx_pcm_mixer[0]);
for (i = 1; i < NUM_EFX_PLAYBACK; i++)
snd_emu10k1_playback_prepare_voice(emu, epcm->voices[i], 0, 0,
&emu->efx_pcm_mixer[i]);
snd_emu10k1_playback_trigger_voice(emu, epcm->voices[0], 0, 0);
snd_emu10k1_playback_trigger_voice(emu, epcm->extra, 1, 1);
for (i = 1; i < NUM_EFX_PLAYBACK; i++)
snd_emu10k1_playback_trigger_voice(emu, epcm->voices[i], 0, 0);
epcm->running = 1;
break;
case SNDRV_PCM_TRIGGER_SUSPEND:
case SNDRV_PCM_TRIGGER_STOP:
case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
epcm->running = 0;
for (i = 0; i < NUM_EFX_PLAYBACK; i++) {
snd_emu10k1_playback_stop_voice(emu, epcm->voices[i]);
}
snd_emu10k1_playback_stop_voice(emu, epcm->extra);
break;
default:
result = -EINVAL;
break;
}
spin_unlock(&emu->reg_lock);
return result;
}
static snd_pcm_uframes_t snd_emu10k1_capture_pointer(struct snd_pcm_substream *substream)
{
struct snd_emu10k1 *emu = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
struct snd_emu10k1_pcm *epcm = runtime->private_data;
unsigned int ptr;
if (!epcm->running)
return 0;
if (epcm->first_ptr) {
udelay(50);
epcm->first_ptr = 0;
}
ptr = snd_emu10k1_ptr_read(emu, epcm->capture_idx_reg, 0) & 0x0000ffff;
return bytes_to_frames(runtime, ptr);
}
static void snd_emu10k1_pcm_mixer_notify1(struct snd_emu10k1 *emu, struct snd_kcontrol *kctl, int idx, int activate)
{
struct snd_ctl_elem_id id;
if (! kctl)
return;
if (activate)
kctl->vd[idx].access &= ~SNDRV_CTL_ELEM_ACCESS_INACTIVE;
else
kctl->vd[idx].access |= SNDRV_CTL_ELEM_ACCESS_INACTIVE;
snd_ctl_notify(emu->card, SNDRV_CTL_EVENT_MASK_VALUE |
SNDRV_CTL_EVENT_MASK_INFO,
snd_ctl_build_ioff(&id, kctl, idx));
}
static void snd_emu10k1_pcm_mixer_notify(struct snd_emu10k1 *emu, int idx, int activate)
{
snd_emu10k1_pcm_mixer_notify1(emu, emu->ctl_send_routing, idx, activate);
snd_emu10k1_pcm_mixer_notify1(emu, emu->ctl_send_volume, idx, activate);
snd_emu10k1_pcm_mixer_notify1(emu, emu->ctl_attn, idx, activate);
}
static void snd_emu10k1_pcm_efx_mixer_notify(struct snd_emu10k1 *emu, int idx, int activate)
{
snd_emu10k1_pcm_mixer_notify1(emu, emu->ctl_efx_send_routing, idx, activate);
snd_emu10k1_pcm_mixer_notify1(emu, emu->ctl_efx_send_volume, idx, activate);
snd_emu10k1_pcm_mixer_notify1(emu, emu->ctl_efx_attn, idx, activate);
}
static void snd_emu10k1_pcm_free_substream(struct snd_pcm_runtime *runtime)
{
kfree(runtime->private_data);
}
static int snd_emu10k1_efx_playback_close(struct snd_pcm_substream *substream)
{
struct snd_emu10k1 *emu = snd_pcm_substream_chip(substream);
struct snd_emu10k1_pcm_mixer *mix;
int i;
for (i = 0; i < NUM_EFX_PLAYBACK; i++) {
mix = &emu->efx_pcm_mixer[i];
mix->epcm = NULL;
snd_emu10k1_pcm_efx_mixer_notify(emu, i, 0);
}
return 0;
}
static int snd_emu10k1_efx_playback_open(struct snd_pcm_substream *substream)
{
struct snd_emu10k1 *emu = snd_pcm_substream_chip(substream);
struct snd_emu10k1_pcm *epcm;
struct snd_emu10k1_pcm_mixer *mix;
struct snd_pcm_runtime *runtime = substream->runtime;
int i;
epcm = kzalloc(sizeof(*epcm), GFP_KERNEL);
if (epcm == NULL)
return -ENOMEM;
epcm->emu = emu;
epcm->type = PLAYBACK_EFX;
epcm->substream = substream;
emu->pcm_playback_efx_substream = substream;
runtime->private_data = epcm;
runtime->private_free = snd_emu10k1_pcm_free_substream;
runtime->hw = snd_emu10k1_efx_playback;
for (i = 0; i < NUM_EFX_PLAYBACK; i++) {
mix = &emu->efx_pcm_mixer[i];
mix->send_routing[0][0] = i;
memset(&mix->send_volume, 0, sizeof(mix->send_volume));
mix->send_volume[0][0] = 255;
mix->attn[0] = 0xffff;
mix->epcm = epcm;
snd_emu10k1_pcm_efx_mixer_notify(emu, i, 1);
}
return 0;
}
static int snd_emu10k1_playback_open(struct snd_pcm_substream *substream)
{
struct snd_emu10k1 *emu = snd_pcm_substream_chip(substream);
struct snd_emu10k1_pcm *epcm;
struct snd_emu10k1_pcm_mixer *mix;
struct snd_pcm_runtime *runtime = substream->runtime;
int i, err;
epcm = kzalloc(sizeof(*epcm), GFP_KERNEL);
if (epcm == NULL)
return -ENOMEM;
epcm->emu = emu;
epcm->type = PLAYBACK_EMUVOICE;
epcm->substream = substream;
runtime->private_data = epcm;
runtime->private_free = snd_emu10k1_pcm_free_substream;
runtime->hw = snd_emu10k1_playback;
if ((err = snd_pcm_hw_constraint_integer(runtime, SNDRV_PCM_HW_PARAM_PERIODS)) < 0) {
kfree(epcm);
return err;
}
if ((err = snd_pcm_hw_constraint_minmax(runtime, SNDRV_PCM_HW_PARAM_BUFFER_BYTES, 256, UINT_MAX)) < 0) {
kfree(epcm);
return err;
}
err = snd_pcm_hw_rule_noresample(runtime, 48000);
if (err < 0) {
kfree(epcm);
return err;
}
mix = &emu->pcm_mixer[substream->number];
for (i = 0; i < 4; i++)
mix->send_routing[0][i] = mix->send_routing[1][i] = mix->send_routing[2][i] = i;
memset(&mix->send_volume, 0, sizeof(mix->send_volume));
mix->send_volume[0][0] = mix->send_volume[0][1] =
mix->send_volume[1][0] = mix->send_volume[2][1] = 255;
mix->attn[0] = mix->attn[1] = mix->attn[2] = 0xffff;
mix->epcm = epcm;
snd_emu10k1_pcm_mixer_notify(emu, substream->number, 1);
return 0;
}
static int snd_emu10k1_playback_close(struct snd_pcm_substream *substream)
{
struct snd_emu10k1 *emu = snd_pcm_substream_chip(substream);
struct snd_emu10k1_pcm_mixer *mix = &emu->pcm_mixer[substream->number];
mix->epcm = NULL;
snd_emu10k1_pcm_mixer_notify(emu, substream->number, 0);
return 0;
}
static int snd_emu10k1_capture_open(struct snd_pcm_substream *substream)
{
struct snd_emu10k1 *emu = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
struct snd_emu10k1_pcm *epcm;
epcm = kzalloc(sizeof(*epcm), GFP_KERNEL);
if (epcm == NULL)
return -ENOMEM;
epcm->emu = emu;
epcm->type = CAPTURE_AC97ADC;
epcm->substream = substream;
epcm->capture_ipr = IPR_ADCBUFFULL|IPR_ADCBUFHALFFULL;
epcm->capture_inte = INTE_ADCBUFENABLE;
epcm->capture_ba_reg = ADCBA;
epcm->capture_bs_reg = ADCBS;
epcm->capture_idx_reg = emu->audigy ? A_ADCIDX : ADCIDX;
runtime->private_data = epcm;
runtime->private_free = snd_emu10k1_pcm_free_substream;
runtime->hw = snd_emu10k1_capture;
emu->capture_interrupt = snd_emu10k1_pcm_ac97adc_interrupt;
emu->pcm_capture_substream = substream;
snd_pcm_hw_constraint_list(runtime, 0, SNDRV_PCM_HW_PARAM_PERIOD_BYTES, &hw_constraints_capture_period_sizes);
snd_pcm_hw_constraint_list(runtime, 0, SNDRV_PCM_HW_PARAM_RATE, &hw_constraints_capture_rates);
return 0;
}
static int snd_emu10k1_capture_close(struct snd_pcm_substream *substream)
{
struct snd_emu10k1 *emu = snd_pcm_substream_chip(substream);
emu->capture_interrupt = NULL;
emu->pcm_capture_substream = NULL;
return 0;
}
static int snd_emu10k1_capture_mic_open(struct snd_pcm_substream *substream)
{
struct snd_emu10k1 *emu = snd_pcm_substream_chip(substream);
struct snd_emu10k1_pcm *epcm;
struct snd_pcm_runtime *runtime = substream->runtime;
epcm = kzalloc(sizeof(*epcm), GFP_KERNEL);
if (epcm == NULL)
return -ENOMEM;
epcm->emu = emu;
epcm->type = CAPTURE_AC97MIC;
epcm->substream = substream;
epcm->capture_ipr = IPR_MICBUFFULL|IPR_MICBUFHALFFULL;
epcm->capture_inte = INTE_MICBUFENABLE;
epcm->capture_ba_reg = MICBA;
epcm->capture_bs_reg = MICBS;
epcm->capture_idx_reg = emu->audigy ? A_MICIDX : MICIDX;
substream->runtime->private_data = epcm;
substream->runtime->private_free = snd_emu10k1_pcm_free_substream;
runtime->hw = snd_emu10k1_capture;
runtime->hw.rates = SNDRV_PCM_RATE_8000;
runtime->hw.rate_min = runtime->hw.rate_max = 8000;
runtime->hw.channels_min = 1;
emu->capture_mic_interrupt = snd_emu10k1_pcm_ac97mic_interrupt;
emu->pcm_capture_mic_substream = substream;
snd_pcm_hw_constraint_list(runtime, 0, SNDRV_PCM_HW_PARAM_PERIOD_BYTES, &hw_constraints_capture_period_sizes);
return 0;
}
static int snd_emu10k1_capture_mic_close(struct snd_pcm_substream *substream)
{
struct snd_emu10k1 *emu = snd_pcm_substream_chip(substream);
emu->capture_interrupt = NULL;
emu->pcm_capture_mic_substream = NULL;
return 0;
}
static int snd_emu10k1_capture_efx_open(struct snd_pcm_substream *substream)
{
struct snd_emu10k1 *emu = snd_pcm_substream_chip(substream);
struct snd_emu10k1_pcm *epcm;
struct snd_pcm_runtime *runtime = substream->runtime;
int nefx = emu->audigy ? 64 : 32;
int idx;
epcm = kzalloc(sizeof(*epcm), GFP_KERNEL);
if (epcm == NULL)
return -ENOMEM;
epcm->emu = emu;
epcm->type = CAPTURE_EFX;
epcm->substream = substream;
epcm->capture_ipr = IPR_EFXBUFFULL|IPR_EFXBUFHALFFULL;
epcm->capture_inte = INTE_EFXBUFENABLE;
epcm->capture_ba_reg = FXBA;
epcm->capture_bs_reg = FXBS;
epcm->capture_idx_reg = FXIDX;
substream->runtime->private_data = epcm;
substream->runtime->private_free = snd_emu10k1_pcm_free_substream;
runtime->hw = snd_emu10k1_capture_efx;
runtime->hw.rates = SNDRV_PCM_RATE_48000;
runtime->hw.rate_min = runtime->hw.rate_max = 48000;
spin_lock_irq(&emu->reg_lock);
if (emu->card_capabilities->emu_model) {
#if 1
switch (emu->emu1010.internal_clock) {
case 0:
runtime->hw.rates = SNDRV_PCM_RATE_44100;
runtime->hw.rate_min = runtime->hw.rate_max = 44100;
runtime->hw.channels_min =
runtime->hw.channels_max = 16;
break;
case 1:
runtime->hw.rates = SNDRV_PCM_RATE_48000;
runtime->hw.rate_min = runtime->hw.rate_max = 48000;
runtime->hw.channels_min =
runtime->hw.channels_max = 16;
break;
}
#endif
#if 0
runtime->hw.rates = SNDRV_PCM_RATE_96000;
runtime->hw.rate_min = runtime->hw.rate_max = 96000;
runtime->hw.channels_min = runtime->hw.channels_max = 4;
#endif
#if 0
runtime->hw.rates = SNDRV_PCM_RATE_192000;
runtime->hw.rate_min = runtime->hw.rate_max = 192000;
runtime->hw.channels_min = runtime->hw.channels_max = 2;
#endif
runtime->hw.formats = SNDRV_PCM_FMTBIT_S32_LE;
} else {
runtime->hw.channels_min = runtime->hw.channels_max = 0;
for (idx = 0; idx < nefx; idx++) {
if (emu->efx_voices_mask[idx/32] & (1 << (idx%32))) {
runtime->hw.channels_min++;
runtime->hw.channels_max++;
}
}
}
epcm->capture_cr_val = emu->efx_voices_mask[0];
epcm->capture_cr_val2 = emu->efx_voices_mask[1];
spin_unlock_irq(&emu->reg_lock);
emu->capture_efx_interrupt = snd_emu10k1_pcm_efx_interrupt;
emu->pcm_capture_efx_substream = substream;
snd_pcm_hw_constraint_list(runtime, 0, SNDRV_PCM_HW_PARAM_PERIOD_BYTES, &hw_constraints_capture_period_sizes);
return 0;
}
static int snd_emu10k1_capture_efx_close(struct snd_pcm_substream *substream)
{
struct snd_emu10k1 *emu = snd_pcm_substream_chip(substream);
emu->capture_interrupt = NULL;
emu->pcm_capture_efx_substream = NULL;
return 0;
}
int __devinit snd_emu10k1_pcm(struct snd_emu10k1 * emu, int device, struct snd_pcm ** rpcm)
{
struct snd_pcm *pcm;
struct snd_pcm_substream *substream;
int err;
if (rpcm)
*rpcm = NULL;
if ((err = snd_pcm_new(emu->card, "emu10k1", device, 32, 1, &pcm)) < 0)
return err;
pcm->private_data = emu;
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_PLAYBACK, &snd_emu10k1_playback_ops);
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_CAPTURE, &snd_emu10k1_capture_ops);
pcm->info_flags = 0;
pcm->dev_subclass = SNDRV_PCM_SUBCLASS_GENERIC_MIX;
strcpy(pcm->name, "ADC Capture/Standard PCM Playback");
emu->pcm = pcm;
for (substream = pcm->streams[SNDRV_PCM_STREAM_PLAYBACK].substream; substream; substream = substream->next)
if ((err = snd_pcm_lib_preallocate_pages(substream, SNDRV_DMA_TYPE_DEV_SG, snd_dma_pci_data(emu->pci), 64*1024, 64*1024)) < 0)
return err;
for (substream = pcm->streams[SNDRV_PCM_STREAM_CAPTURE].substream; substream; substream = substream->next)
snd_pcm_lib_preallocate_pages(substream, SNDRV_DMA_TYPE_DEV, snd_dma_pci_data(emu->pci), 64*1024, 64*1024);
if (rpcm)
*rpcm = pcm;
return 0;
}
int __devinit snd_emu10k1_pcm_multi(struct snd_emu10k1 * emu, int device, struct snd_pcm ** rpcm)
{
struct snd_pcm *pcm;
struct snd_pcm_substream *substream;
int err;
if (rpcm)
*rpcm = NULL;
if ((err = snd_pcm_new(emu->card, "emu10k1", device, 1, 0, &pcm)) < 0)
return err;
pcm->private_data = emu;
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_PLAYBACK, &snd_emu10k1_efx_playback_ops);
pcm->info_flags = 0;
pcm->dev_subclass = SNDRV_PCM_SUBCLASS_GENERIC_MIX;
strcpy(pcm->name, "Multichannel Playback");
emu->pcm_multi = pcm;
for (substream = pcm->streams[SNDRV_PCM_STREAM_PLAYBACK].substream; substream; substream = substream->next)
if ((err = snd_pcm_lib_preallocate_pages(substream, SNDRV_DMA_TYPE_DEV_SG, snd_dma_pci_data(emu->pci), 64*1024, 64*1024)) < 0)
return err;
if (rpcm)
*rpcm = pcm;
return 0;
}
int __devinit snd_emu10k1_pcm_mic(struct snd_emu10k1 * emu, int device, struct snd_pcm ** rpcm)
{
struct snd_pcm *pcm;
int err;
if (rpcm)
*rpcm = NULL;
if ((err = snd_pcm_new(emu->card, "emu10k1 mic", device, 0, 1, &pcm)) < 0)
return err;
pcm->private_data = emu;
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_CAPTURE, &snd_emu10k1_capture_mic_ops);
pcm->info_flags = 0;
strcpy(pcm->name, "Mic Capture");
emu->pcm_mic = pcm;
snd_pcm_lib_preallocate_pages_for_all(pcm, SNDRV_DMA_TYPE_DEV, snd_dma_pci_data(emu->pci), 64*1024, 64*1024);
if (rpcm)
*rpcm = pcm;
return 0;
}
static int snd_emu10k1_pcm_efx_voices_mask_info(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_info *uinfo)
{
struct snd_emu10k1 *emu = snd_kcontrol_chip(kcontrol);
int nefx = emu->audigy ? 64 : 32;
uinfo->type = SNDRV_CTL_ELEM_TYPE_BOOLEAN;
uinfo->count = nefx;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = 1;
return 0;
}
static int snd_emu10k1_pcm_efx_voices_mask_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_emu10k1 *emu = snd_kcontrol_chip(kcontrol);
int nefx = emu->audigy ? 64 : 32;
int idx;
spin_lock_irq(&emu->reg_lock);
for (idx = 0; idx < nefx; idx++)
ucontrol->value.integer.value[idx] = (emu->efx_voices_mask[idx / 32] & (1 << (idx % 32))) ? 1 : 0;
spin_unlock_irq(&emu->reg_lock);
return 0;
}
static int snd_emu10k1_pcm_efx_voices_mask_put(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_emu10k1 *emu = snd_kcontrol_chip(kcontrol);
unsigned int nval[2], bits;
int nefx = emu->audigy ? 64 : 32;
int nefxb = emu->audigy ? 7 : 6;
int change, idx;
nval[0] = nval[1] = 0;
for (idx = 0, bits = 0; idx < nefx; idx++)
if (ucontrol->value.integer.value[idx]) {
nval[idx / 32] |= 1 << (idx % 32);
bits++;
}
for (idx = 0; idx < nefxb; idx++)
if (1 << idx == bits)
break;
if (idx >= nefxb)
return -EINVAL;
spin_lock_irq(&emu->reg_lock);
change = (nval[0] != emu->efx_voices_mask[0]) ||
(nval[1] != emu->efx_voices_mask[1]);
emu->efx_voices_mask[0] = nval[0];
emu->efx_voices_mask[1] = nval[1];
spin_unlock_irq(&emu->reg_lock);
return change;
}
static void snd_emu10k1_fx8010_playback_irq(struct snd_emu10k1 *emu, void *private_data)
{
struct snd_pcm_substream *substream = private_data;
snd_pcm_period_elapsed(substream);
}
static void snd_emu10k1_fx8010_playback_tram_poke1(unsigned short *dst_left,
unsigned short *dst_right,
unsigned short *src,
unsigned int count,
unsigned int tram_shift)
{
if ((tram_shift & 1) == 0) {
while (count--) {
*dst_left-- = *src++;
*dst_right-- = *src++;
}
} else {
while (count--) {
*dst_right-- = *src++;
*dst_left-- = *src++;
}
}
}
static void fx8010_pb_trans_copy(struct snd_pcm_substream *substream,
struct snd_pcm_indirect *rec, size_t bytes)
{
struct snd_emu10k1 *emu = snd_pcm_substream_chip(substream);
struct snd_emu10k1_fx8010_pcm *pcm = &emu->fx8010.pcm[substream->number];
unsigned int tram_size = pcm->buffer_size;
unsigned short *src = (unsigned short *)(substream->runtime->dma_area + rec->sw_data);
unsigned int frames = bytes >> 2, count;
unsigned int tram_pos = pcm->tram_pos;
unsigned int tram_shift = pcm->tram_shift;
while (frames > tram_pos) {
count = tram_pos + 1;
snd_emu10k1_fx8010_playback_tram_poke1((unsigned short *)emu->fx8010.etram_pages.area + tram_pos,
(unsigned short *)emu->fx8010.etram_pages.area + tram_pos + tram_size / 2,
src, count, tram_shift);
src += count * 2;
frames -= count;
tram_pos = (tram_size / 2) - 1;
tram_shift++;
}
snd_emu10k1_fx8010_playback_tram_poke1((unsigned short *)emu->fx8010.etram_pages.area + tram_pos,
(unsigned short *)emu->fx8010.etram_pages.area + tram_pos + tram_size / 2,
src, frames, tram_shift);
tram_pos -= frames;
pcm->tram_pos = tram_pos;
pcm->tram_shift = tram_shift;
}
static int snd_emu10k1_fx8010_playback_transfer(struct snd_pcm_substream *substream)
{
struct snd_emu10k1 *emu = snd_pcm_substream_chip(substream);
struct snd_emu10k1_fx8010_pcm *pcm = &emu->fx8010.pcm[substream->number];
snd_pcm_indirect_playback_transfer(substream, &pcm->pcm_rec, fx8010_pb_trans_copy);
return 0;
}
static int snd_emu10k1_fx8010_playback_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *hw_params)
{
return snd_pcm_lib_malloc_pages(substream, params_buffer_bytes(hw_params));
}
static int snd_emu10k1_fx8010_playback_hw_free(struct snd_pcm_substream *substream)
{
struct snd_emu10k1 *emu = snd_pcm_substream_chip(substream);
struct snd_emu10k1_fx8010_pcm *pcm = &emu->fx8010.pcm[substream->number];
unsigned int i;
for (i = 0; i < pcm->channels; i++)
snd_emu10k1_ptr_write(emu, TANKMEMADDRREGBASE + 0x80 + pcm->etram[i], 0, 0);
snd_pcm_lib_free_pages(substream);
return 0;
}
static int snd_emu10k1_fx8010_playback_prepare(struct snd_pcm_substream *substream)
{
struct snd_emu10k1 *emu = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
struct snd_emu10k1_fx8010_pcm *pcm = &emu->fx8010.pcm[substream->number];
unsigned int i;
memset(&pcm->pcm_rec, 0, sizeof(pcm->pcm_rec));
pcm->pcm_rec.hw_buffer_size = pcm->buffer_size * 2;
pcm->pcm_rec.sw_buffer_size = snd_pcm_lib_buffer_bytes(substream);
pcm->tram_pos = INITIAL_TRAM_POS(pcm->buffer_size);
pcm->tram_shift = 0;
snd_emu10k1_ptr_write(emu, emu->gpr_base + pcm->gpr_running, 0, 0);
snd_emu10k1_ptr_write(emu, emu->gpr_base + pcm->gpr_trigger, 0, 0);
snd_emu10k1_ptr_write(emu, emu->gpr_base + pcm->gpr_size, 0, runtime->buffer_size);
snd_emu10k1_ptr_write(emu, emu->gpr_base + pcm->gpr_ptr, 0, 0);
snd_emu10k1_ptr_write(emu, emu->gpr_base + pcm->gpr_count, 0, runtime->period_size);
snd_emu10k1_ptr_write(emu, emu->gpr_base + pcm->gpr_tmpcount, 0, runtime->period_size);
for (i = 0; i < pcm->channels; i++)
snd_emu10k1_ptr_write(emu, TANKMEMADDRREGBASE + 0x80 + pcm->etram[i], 0, (TANKMEMADDRREG_READ|TANKMEMADDRREG_ALIGN) + i * (runtime->buffer_size / pcm->channels));
return 0;
}
static int snd_emu10k1_fx8010_playback_trigger(struct snd_pcm_substream *substream, int cmd)
{
struct snd_emu10k1 *emu = snd_pcm_substream_chip(substream);
struct snd_emu10k1_fx8010_pcm *pcm = &emu->fx8010.pcm[substream->number];
int result = 0;
spin_lock(&emu->reg_lock);
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
case SNDRV_PCM_TRIGGER_RESUME:
#ifdef EMU10K1_SET_AC3_IEC958
{
int i;
for (i = 0; i < 3; i++) {
unsigned int bits;
bits = SPCS_CLKACCY_1000PPM | SPCS_SAMPLERATE_48 |
SPCS_CHANNELNUM_LEFT | SPCS_SOURCENUM_UNSPEC | SPCS_GENERATIONSTATUS |
0x00001200 | SPCS_EMPHASIS_NONE | SPCS_COPYRIGHT | SPCS_NOTAUDIODATA;
snd_emu10k1_ptr_write(emu, SPCS0 + i, 0, bits);
}
}
#endif
result = snd_emu10k1_fx8010_register_irq_handler(emu, snd_emu10k1_fx8010_playback_irq, pcm->gpr_running, substream, &pcm->irq);
if (result < 0)
goto __err;
snd_emu10k1_fx8010_playback_transfer(substream);
snd_emu10k1_ptr_write(emu, emu->gpr_base + pcm->gpr_trigger, 0, 1);
break;
case SNDRV_PCM_TRIGGER_STOP:
case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
case SNDRV_PCM_TRIGGER_SUSPEND:
snd_emu10k1_fx8010_unregister_irq_handler(emu, pcm->irq); pcm->irq = NULL;
snd_emu10k1_ptr_write(emu, emu->gpr_base + pcm->gpr_trigger, 0, 0);
pcm->tram_pos = INITIAL_TRAM_POS(pcm->buffer_size);
pcm->tram_shift = 0;
break;
default:
result = -EINVAL;
break;
}
__err:
spin_unlock(&emu->reg_lock);
return result;
}
static snd_pcm_uframes_t snd_emu10k1_fx8010_playback_pointer(struct snd_pcm_substream *substream)
{
struct snd_emu10k1 *emu = snd_pcm_substream_chip(substream);
struct snd_emu10k1_fx8010_pcm *pcm = &emu->fx8010.pcm[substream->number];
size_t ptr;
if (!snd_emu10k1_ptr_read(emu, emu->gpr_base + pcm->gpr_trigger, 0))
return 0;
ptr = snd_emu10k1_ptr_read(emu, emu->gpr_base + pcm->gpr_ptr, 0) << 2;
return snd_pcm_indirect_playback_pointer(substream, &pcm->pcm_rec, ptr);
}
static int snd_emu10k1_fx8010_playback_open(struct snd_pcm_substream *substream)
{
struct snd_emu10k1 *emu = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
struct snd_emu10k1_fx8010_pcm *pcm = &emu->fx8010.pcm[substream->number];
runtime->hw = snd_emu10k1_fx8010_playback;
runtime->hw.channels_min = runtime->hw.channels_max = pcm->channels;
runtime->hw.period_bytes_max = (pcm->buffer_size * 2) / 2;
spin_lock_irq(&emu->reg_lock);
if (pcm->valid == 0) {
spin_unlock_irq(&emu->reg_lock);
return -ENODEV;
}
pcm->opened = 1;
spin_unlock_irq(&emu->reg_lock);
return 0;
}
static int snd_emu10k1_fx8010_playback_close(struct snd_pcm_substream *substream)
{
struct snd_emu10k1 *emu = snd_pcm_substream_chip(substream);
struct snd_emu10k1_fx8010_pcm *pcm = &emu->fx8010.pcm[substream->number];
spin_lock_irq(&emu->reg_lock);
pcm->opened = 0;
spin_unlock_irq(&emu->reg_lock);
return 0;
}
int __devinit snd_emu10k1_pcm_efx(struct snd_emu10k1 * emu, int device, struct snd_pcm ** rpcm)
{
struct snd_pcm *pcm;
struct snd_kcontrol *kctl;
int err;
if (rpcm)
*rpcm = NULL;
if ((err = snd_pcm_new(emu->card, "emu10k1 efx", device, 8, 1, &pcm)) < 0)
return err;
pcm->private_data = emu;
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_PLAYBACK, &snd_emu10k1_fx8010_playback_ops);
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_CAPTURE, &snd_emu10k1_capture_efx_ops);
pcm->info_flags = 0;
strcpy(pcm->name, "Multichannel Capture/PT Playback");
emu->pcm_efx = pcm;
if (rpcm)
*rpcm = pcm;
if (emu->audigy) {
emu->efx_voices_mask[0] = 0;
if (emu->card_capabilities->emu_model)
emu->efx_voices_mask[1] = 0xffffffff;
else
emu->efx_voices_mask[1] = 0xffff;
} else {
emu->efx_voices_mask[0] = 0xffff0000;
emu->efx_voices_mask[1] = 0;
}
kctl = snd_ctl_new1(&snd_emu10k1_pcm_efx_voices_mask, emu);
if (!kctl)
return -ENOMEM;
kctl->id.device = device;
snd_ctl_add(emu->card, kctl);
snd_pcm_lib_preallocate_pages_for_all(pcm, SNDRV_DMA_TYPE_DEV, snd_dma_pci_data(emu->pci), 64*1024, 64*1024);
return 0;
}
