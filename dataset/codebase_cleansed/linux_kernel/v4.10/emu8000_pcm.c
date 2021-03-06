static int
emu8k_open_dram_for_pcm(struct snd_emu8000 *emu, int channels)
{
int i;
snd_emux_lock_voice(emu->emu, 0);
if (channels > 1)
snd_emux_lock_voice(emu->emu, 1);
for (i = channels + 1; i < EMU8000_DRAM_VOICES; i++) {
unsigned int mode = EMU8000_RAM_WRITE;
snd_emux_lock_voice(emu->emu, i);
#ifndef USE_NONINTERLEAVE
if (channels > 1 && (i & 1) != 0)
mode |= EMU8000_RAM_RIGHT;
#endif
snd_emu8000_dma_chan(emu, i, mode);
}
EMU8000_VTFT_WRITE(emu, 30, 0);
EMU8000_PSST_WRITE(emu, 30, 0x1d8);
EMU8000_CSL_WRITE(emu, 30, 0x1e0);
EMU8000_CCCA_WRITE(emu, 30, 0x1d8);
EMU8000_VTFT_WRITE(emu, 31, 0);
EMU8000_PSST_WRITE(emu, 31, 0x1d8);
EMU8000_CSL_WRITE(emu, 31, 0x1e0);
EMU8000_CCCA_WRITE(emu, 31, 0x1d8);
return 0;
}
static void
snd_emu8000_write_wait(struct snd_emu8000 *emu, int can_schedule)
{
while ((EMU8000_SMALW_READ(emu) & 0x80000000) != 0) {
if (can_schedule) {
schedule_timeout_interruptible(1);
if (signal_pending(current))
break;
}
}
}
static void
emu8k_close_dram(struct snd_emu8000 *emu)
{
int i;
for (i = 0; i < 2; i++)
snd_emux_unlock_voice(emu->emu, i);
for (; i < EMU8000_DRAM_VOICES; i++) {
snd_emu8000_dma_chan(emu, i, EMU8000_RAM_CLOSE);
snd_emux_unlock_voice(emu->emu, i);
}
}
static int calc_rate_offset(int hz)
{
return snd_sf_linear_to_log(hz, OFFSET_SAMPLERATE, SAMPLERATE_RATIO);
}
static inline int emu8k_get_curpos(struct snd_emu8k_pcm *rec, int ch)
{
int val = EMU8000_CCCA_READ(rec->emu, ch) & 0xfffffff;
val -= rec->loop_start[ch] - 1;
return val;
}
static void emu8k_pcm_timer_func(unsigned long data)
{
struct snd_emu8k_pcm *rec = (struct snd_emu8k_pcm *)data;
int ptr, delta;
spin_lock(&rec->timer_lock);
ptr = emu8k_get_curpos(rec, 0);
if (ptr < rec->last_ptr)
delta = ptr + rec->buf_size - rec->last_ptr;
else
delta = ptr - rec->last_ptr;
rec->period_pos += delta;
rec->last_ptr = ptr;
mod_timer(&rec->timer, jiffies + 1);
if (rec->period_pos >= (int)rec->period_size) {
rec->period_pos %= rec->period_size;
spin_unlock(&rec->timer_lock);
snd_pcm_period_elapsed(rec->substream);
return;
}
spin_unlock(&rec->timer_lock);
}
static int emu8k_pcm_open(struct snd_pcm_substream *subs)
{
struct snd_emu8000 *emu = snd_pcm_substream_chip(subs);
struct snd_emu8k_pcm *rec;
struct snd_pcm_runtime *runtime = subs->runtime;
rec = kzalloc(sizeof(*rec), GFP_KERNEL);
if (! rec)
return -ENOMEM;
rec->emu = emu;
rec->substream = subs;
runtime->private_data = rec;
spin_lock_init(&rec->timer_lock);
setup_timer(&rec->timer, emu8k_pcm_timer_func, (unsigned long)rec);
runtime->hw = emu8k_pcm_hw;
runtime->hw.buffer_bytes_max = emu->mem_size - LOOP_BLANK_SIZE * 3;
runtime->hw.period_bytes_max = runtime->hw.buffer_bytes_max / 2;
snd_pcm_hw_constraint_minmax(runtime, SNDRV_PCM_HW_PARAM_PERIOD_TIME,
(1000000 + HZ - 1) / HZ, UINT_MAX);
return 0;
}
static int emu8k_pcm_close(struct snd_pcm_substream *subs)
{
struct snd_emu8k_pcm *rec = subs->runtime->private_data;
kfree(rec);
subs->runtime->private_data = NULL;
return 0;
}
static int calc_pitch_target(int pitch)
{
int ptarget = 1 << (pitch >> 12);
if (pitch & 0x800) ptarget += (ptarget * 0x102e) / 0x2710;
if (pitch & 0x400) ptarget += (ptarget * 0x764) / 0x2710;
if (pitch & 0x200) ptarget += (ptarget * 0x389) / 0x2710;
ptarget += (ptarget >> 1);
if (ptarget > 0xffff) ptarget = 0xffff;
return ptarget;
}
static void setup_voice(struct snd_emu8k_pcm *rec, int ch)
{
struct snd_emu8000 *hw = rec->emu;
unsigned int temp;
EMU8000_DCYSUSV_WRITE(hw, ch, 0x0080);
EMU8000_VTFT_WRITE(hw, ch, 0x0000FFFF);
EMU8000_CVCF_WRITE(hw, ch, 0x0000FFFF);
EMU8000_PTRX_WRITE(hw, ch, 0);
EMU8000_CPF_WRITE(hw, ch, 0);
EMU8000_IP_WRITE(hw, ch, rec->pitch);
EMU8000_ENVVAL_WRITE(hw, ch, 0x8000);
EMU8000_ATKHLD_WRITE(hw, ch, 0x7f7f);
EMU8000_DCYSUS_WRITE(hw, ch, 0x7f7f);
EMU8000_ENVVOL_WRITE(hw, ch, 0x8000);
EMU8000_ATKHLDV_WRITE(hw, ch, 0x7f7f);
EMU8000_PEFE_WRITE(hw, ch, 0x0);
EMU8000_LFO1VAL_WRITE(hw, ch, 0x8000);
EMU8000_LFO2VAL_WRITE(hw, ch, 0x8000);
EMU8000_FMMOD_WRITE(hw, ch, 0);
EMU8000_TREMFRQ_WRITE(hw, ch, 0);
EMU8000_FM2FRQ2_WRITE(hw, ch, 0);
temp = rec->panning[ch];
temp = (temp <<24) | ((unsigned int)rec->loop_start[ch] - 1);
EMU8000_PSST_WRITE(hw, ch, temp);
temp = 0;
temp = (temp << 24) | ((unsigned int)rec->loop_start[ch] + rec->buf_size - 1);
EMU8000_CSL_WRITE(hw, ch, temp);
temp = 0;
temp = (temp << 28) | ((unsigned int)rec->loop_start[ch] - 1);
EMU8000_CCCA_WRITE(hw, ch, temp);
EMU8000_00A0_WRITE(hw, ch, 0);
EMU8000_0080_WRITE(hw, ch, 0);
}
static void start_voice(struct snd_emu8k_pcm *rec, int ch)
{
unsigned long flags;
struct snd_emu8000 *hw = rec->emu;
unsigned int temp, aux;
int pt = calc_pitch_target(rec->pitch);
EMU8000_IFATN_WRITE(hw, ch, 0xff00);
EMU8000_VTFT_WRITE(hw, ch, 0xffff);
EMU8000_CVCF_WRITE(hw, ch, 0xffff);
EMU8000_DCYSUSV_WRITE(hw, ch, 0x7f7f);
temp = 0;
if (rec->panning[ch] == 0)
aux = 0xff;
else
aux = (-rec->panning[ch]) & 0xff;
temp = (temp << 8) | (pt << 16) | aux;
EMU8000_PTRX_WRITE(hw, ch, temp);
EMU8000_CPF_WRITE(hw, ch, pt << 16);
spin_lock_irqsave(&rec->timer_lock, flags);
if (! rec->timer_running) {
mod_timer(&rec->timer, jiffies + 1);
rec->timer_running = 1;
}
spin_unlock_irqrestore(&rec->timer_lock, flags);
}
static void stop_voice(struct snd_emu8k_pcm *rec, int ch)
{
unsigned long flags;
struct snd_emu8000 *hw = rec->emu;
EMU8000_DCYSUSV_WRITE(hw, ch, 0x807F);
spin_lock_irqsave(&rec->timer_lock, flags);
if (rec->timer_running) {
del_timer(&rec->timer);
rec->timer_running = 0;
}
spin_unlock_irqrestore(&rec->timer_lock, flags);
}
static int emu8k_pcm_trigger(struct snd_pcm_substream *subs, int cmd)
{
struct snd_emu8k_pcm *rec = subs->runtime->private_data;
int ch;
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
for (ch = 0; ch < rec->voices; ch++)
start_voice(rec, ch);
rec->running = 1;
break;
case SNDRV_PCM_TRIGGER_STOP:
rec->running = 0;
for (ch = 0; ch < rec->voices; ch++)
stop_voice(rec, ch);
break;
default:
return -EINVAL;
}
return 0;
}
static int emu8k_transfer_block(struct snd_emu8000 *emu, int offset, unsigned short *buf, int count)
{
EMU8000_SMALW_WRITE(emu, offset);
while (count > 0) {
unsigned short sval;
CHECK_SCHEDULER();
if (get_user(sval, buf))
return -EFAULT;
EMU8000_SMLD_WRITE(emu, sval);
buf++;
count--;
}
return 0;
}
static int emu8k_pcm_copy(struct snd_pcm_substream *subs,
int voice,
snd_pcm_uframes_t pos,
void *src,
snd_pcm_uframes_t count)
{
struct snd_emu8k_pcm *rec = subs->runtime->private_data;
struct snd_emu8000 *emu = rec->emu;
snd_emu8000_write_wait(emu, 1);
if (voice == -1) {
unsigned short *buf = src;
int i, err;
count /= rec->voices;
for (i = 0; i < rec->voices; i++) {
err = emu8k_transfer_block(emu, pos + rec->loop_start[i], buf, count);
if (err < 0)
return err;
buf += count;
}
return 0;
} else {
return emu8k_transfer_block(emu, pos + rec->loop_start[voice], src, count);
}
}
static int emu8k_silence_block(struct snd_emu8000 *emu, int offset, int count)
{
EMU8000_SMALW_WRITE(emu, offset);
while (count > 0) {
CHECK_SCHEDULER();
EMU8000_SMLD_WRITE(emu, 0);
count--;
}
return 0;
}
static int emu8k_pcm_silence(struct snd_pcm_substream *subs,
int voice,
snd_pcm_uframes_t pos,
snd_pcm_uframes_t count)
{
struct snd_emu8k_pcm *rec = subs->runtime->private_data;
struct snd_emu8000 *emu = rec->emu;
snd_emu8000_write_wait(emu, 1);
if (voice == -1 && rec->voices == 1)
voice = 0;
if (voice == -1) {
int err;
err = emu8k_silence_block(emu, pos + rec->loop_start[0], count / 2);
if (err < 0)
return err;
return emu8k_silence_block(emu, pos + rec->loop_start[1], count / 2);
} else {
return emu8k_silence_block(emu, pos + rec->loop_start[voice], count);
}
}
static int emu8k_pcm_copy(struct snd_pcm_substream *subs,
int voice,
snd_pcm_uframes_t pos,
void __user *src,
snd_pcm_uframes_t count)
{
struct snd_emu8k_pcm *rec = subs->runtime->private_data;
struct snd_emu8000 *emu = rec->emu;
unsigned short __user *buf = src;
snd_emu8000_write_wait(emu, 1);
EMU8000_SMALW_WRITE(emu, pos + rec->loop_start[0]);
if (rec->voices > 1)
EMU8000_SMARW_WRITE(emu, pos + rec->loop_start[1]);
while (count-- > 0) {
unsigned short sval;
CHECK_SCHEDULER();
if (get_user(sval, buf))
return -EFAULT;
EMU8000_SMLD_WRITE(emu, sval);
buf++;
if (rec->voices > 1) {
CHECK_SCHEDULER();
if (get_user(sval, buf))
return -EFAULT;
EMU8000_SMRD_WRITE(emu, sval);
buf++;
}
}
return 0;
}
static int emu8k_pcm_silence(struct snd_pcm_substream *subs,
int voice,
snd_pcm_uframes_t pos,
snd_pcm_uframes_t count)
{
struct snd_emu8k_pcm *rec = subs->runtime->private_data;
struct snd_emu8000 *emu = rec->emu;
snd_emu8000_write_wait(emu, 1);
EMU8000_SMALW_WRITE(emu, rec->loop_start[0] + pos);
if (rec->voices > 1)
EMU8000_SMARW_WRITE(emu, rec->loop_start[1] + pos);
while (count-- > 0) {
CHECK_SCHEDULER();
EMU8000_SMLD_WRITE(emu, 0);
if (rec->voices > 1) {
CHECK_SCHEDULER();
EMU8000_SMRD_WRITE(emu, 0);
}
}
return 0;
}
static int emu8k_pcm_hw_params(struct snd_pcm_substream *subs,
struct snd_pcm_hw_params *hw_params)
{
struct snd_emu8k_pcm *rec = subs->runtime->private_data;
if (rec->block) {
snd_util_mem_free(rec->emu->memhdr, rec->block);
rec->block = NULL;
}
rec->allocated_bytes = params_buffer_bytes(hw_params) + LOOP_BLANK_SIZE * 4;
rec->block = snd_util_mem_alloc(rec->emu->memhdr, rec->allocated_bytes);
if (! rec->block)
return -ENOMEM;
rec->offset = EMU8000_DRAM_OFFSET + (rec->block->offset >> 1);
subs->dma_buffer.bytes = params_buffer_bytes(hw_params);
return 0;
}
static int emu8k_pcm_hw_free(struct snd_pcm_substream *subs)
{
struct snd_emu8k_pcm *rec = subs->runtime->private_data;
if (rec->block) {
int ch;
for (ch = 0; ch < rec->voices; ch++)
stop_voice(rec, ch);
if (rec->dram_opened)
emu8k_close_dram(rec->emu);
snd_util_mem_free(rec->emu->memhdr, rec->block);
rec->block = NULL;
}
return 0;
}
static int emu8k_pcm_prepare(struct snd_pcm_substream *subs)
{
struct snd_emu8k_pcm *rec = subs->runtime->private_data;
rec->pitch = 0xe000 + calc_rate_offset(subs->runtime->rate);
rec->last_ptr = 0;
rec->period_pos = 0;
rec->buf_size = subs->runtime->buffer_size;
rec->period_size = subs->runtime->period_size;
rec->voices = subs->runtime->channels;
rec->loop_start[0] = rec->offset + LOOP_BLANK_SIZE;
if (rec->voices > 1)
rec->loop_start[1] = rec->loop_start[0] + rec->buf_size + LOOP_BLANK_SIZE;
if (rec->voices > 1) {
rec->panning[0] = 0xff;
rec->panning[1] = 0x00;
} else
rec->panning[0] = 0x80;
if (! rec->dram_opened) {
int err, i, ch;
snd_emux_terminate_all(rec->emu->emu);
if ((err = emu8k_open_dram_for_pcm(rec->emu, rec->voices)) != 0)
return err;
rec->dram_opened = 1;
snd_emu8000_write_wait(rec->emu, 0);
EMU8000_SMALW_WRITE(rec->emu, rec->offset);
for (i = 0; i < LOOP_BLANK_SIZE; i++)
EMU8000_SMLD_WRITE(rec->emu, 0);
for (ch = 0; ch < rec->voices; ch++) {
EMU8000_SMALW_WRITE(rec->emu, rec->loop_start[ch] + rec->buf_size);
for (i = 0; i < LOOP_BLANK_SIZE; i++)
EMU8000_SMLD_WRITE(rec->emu, 0);
}
}
setup_voice(rec, 0);
if (rec->voices > 1)
setup_voice(rec, 1);
return 0;
}
static snd_pcm_uframes_t emu8k_pcm_pointer(struct snd_pcm_substream *subs)
{
struct snd_emu8k_pcm *rec = subs->runtime->private_data;
if (rec->running)
return emu8k_get_curpos(rec, 0);
return 0;
}
static void snd_emu8000_pcm_free(struct snd_pcm *pcm)
{
struct snd_emu8000 *emu = pcm->private_data;
emu->pcm = NULL;
}
int snd_emu8000_pcm_new(struct snd_card *card, struct snd_emu8000 *emu, int index)
{
struct snd_pcm *pcm;
int err;
if ((err = snd_pcm_new(card, "Emu8000 PCM", index, 1, 0, &pcm)) < 0)
return err;
pcm->private_data = emu;
pcm->private_free = snd_emu8000_pcm_free;
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_PLAYBACK, &emu8k_pcm_ops);
emu->pcm = pcm;
snd_device_register(card, pcm);
return 0;
}
