static inline unsigned int byte_pos(struct loopback_pcm *dpcm, unsigned int x)
{
if (dpcm->pcm_rate_shift == NO_PITCH) {
x /= HZ;
} else {
x = div_u64(NO_PITCH * (unsigned long long)x,
HZ * (unsigned long long)dpcm->pcm_rate_shift);
}
return x - (x % dpcm->pcm_salign);
}
static inline unsigned int frac_pos(struct loopback_pcm *dpcm, unsigned int x)
{
if (dpcm->pcm_rate_shift == NO_PITCH) {
return x * HZ;
} else {
x = div_u64(dpcm->pcm_rate_shift * (unsigned long long)x * HZ,
NO_PITCH);
}
return x;
}
static inline struct loopback_setup *get_setup(struct loopback_pcm *dpcm)
{
int device = dpcm->substream->pstr->pcm->device;
if (dpcm->substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
device ^= 1;
return &dpcm->loopback->setup[dpcm->substream->number][device];
}
static inline unsigned int get_notify(struct loopback_pcm *dpcm)
{
return get_setup(dpcm)->notify;
}
static inline unsigned int get_rate_shift(struct loopback_pcm *dpcm)
{
return get_setup(dpcm)->rate_shift;
}
static void loopback_timer_start(struct loopback_pcm *dpcm)
{
unsigned long tick;
unsigned int rate_shift = get_rate_shift(dpcm);
if (rate_shift != dpcm->pcm_rate_shift) {
dpcm->pcm_rate_shift = rate_shift;
dpcm->period_size_frac = frac_pos(dpcm, dpcm->pcm_period_size);
}
if (dpcm->period_size_frac <= dpcm->irq_pos) {
dpcm->irq_pos %= dpcm->period_size_frac;
dpcm->period_update_pending = 1;
}
tick = dpcm->period_size_frac - dpcm->irq_pos;
tick = (tick + dpcm->pcm_bps - 1) / dpcm->pcm_bps;
dpcm->timer.expires = jiffies + tick;
add_timer(&dpcm->timer);
}
static inline void loopback_timer_stop(struct loopback_pcm *dpcm)
{
del_timer(&dpcm->timer);
dpcm->timer.expires = 0;
}
static int loopback_check_format(struct loopback_cable *cable, int stream)
{
struct snd_pcm_runtime *runtime, *cruntime;
struct loopback_setup *setup;
struct snd_card *card;
int check;
if (cable->valid != CABLE_VALID_BOTH) {
if (stream == SNDRV_PCM_STREAM_PLAYBACK)
goto __notify;
return 0;
}
runtime = cable->streams[SNDRV_PCM_STREAM_PLAYBACK]->
substream->runtime;
cruntime = cable->streams[SNDRV_PCM_STREAM_CAPTURE]->
substream->runtime;
check = runtime->format != cruntime->format ||
runtime->rate != cruntime->rate ||
runtime->channels != cruntime->channels;
if (!check)
return 0;
if (stream == SNDRV_PCM_STREAM_CAPTURE) {
return -EIO;
} else {
snd_pcm_stop(cable->streams[SNDRV_PCM_STREAM_CAPTURE]->
substream, SNDRV_PCM_STATE_DRAINING);
__notify:
runtime = cable->streams[SNDRV_PCM_STREAM_PLAYBACK]->
substream->runtime;
setup = get_setup(cable->streams[SNDRV_PCM_STREAM_PLAYBACK]);
card = cable->streams[SNDRV_PCM_STREAM_PLAYBACK]->loopback->card;
if (setup->format != runtime->format) {
snd_ctl_notify(card, SNDRV_CTL_EVENT_MASK_VALUE,
&setup->format_id);
setup->format = runtime->format;
}
if (setup->rate != runtime->rate) {
snd_ctl_notify(card, SNDRV_CTL_EVENT_MASK_VALUE,
&setup->rate_id);
setup->rate = runtime->rate;
}
if (setup->channels != runtime->channels) {
snd_ctl_notify(card, SNDRV_CTL_EVENT_MASK_VALUE,
&setup->channels_id);
setup->channels = runtime->channels;
}
}
return 0;
}
static void loopback_active_notify(struct loopback_pcm *dpcm)
{
snd_ctl_notify(dpcm->loopback->card,
SNDRV_CTL_EVENT_MASK_VALUE,
&get_setup(dpcm)->active_id);
}
static int loopback_trigger(struct snd_pcm_substream *substream, int cmd)
{
struct snd_pcm_runtime *runtime = substream->runtime;
struct loopback_pcm *dpcm = runtime->private_data;
struct loopback_cable *cable = dpcm->cable;
int err, stream = 1 << substream->stream;
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
err = loopback_check_format(cable, substream->stream);
if (err < 0)
return err;
dpcm->last_jiffies = jiffies;
dpcm->pcm_rate_shift = 0;
dpcm->last_drift = 0;
spin_lock(&cable->lock);
cable->running |= stream;
cable->pause &= ~stream;
spin_unlock(&cable->lock);
loopback_timer_start(dpcm);
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
loopback_active_notify(dpcm);
break;
case SNDRV_PCM_TRIGGER_STOP:
spin_lock(&cable->lock);
cable->running &= ~stream;
cable->pause &= ~stream;
spin_unlock(&cable->lock);
loopback_timer_stop(dpcm);
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
loopback_active_notify(dpcm);
break;
case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
spin_lock(&cable->lock);
cable->pause |= stream;
spin_unlock(&cable->lock);
loopback_timer_stop(dpcm);
break;
case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
spin_lock(&cable->lock);
dpcm->last_jiffies = jiffies;
cable->pause &= ~stream;
spin_unlock(&cable->lock);
loopback_timer_start(dpcm);
break;
default:
return -EINVAL;
}
return 0;
}
static void params_change_substream(struct loopback_pcm *dpcm,
struct snd_pcm_runtime *runtime)
{
struct snd_pcm_runtime *dst_runtime;
if (dpcm == NULL || dpcm->substream == NULL)
return;
dst_runtime = dpcm->substream->runtime;
if (dst_runtime == NULL)
return;
dst_runtime->hw = dpcm->cable->hw;
}
static void params_change(struct snd_pcm_substream *substream)
{
struct snd_pcm_runtime *runtime = substream->runtime;
struct loopback_pcm *dpcm = runtime->private_data;
struct loopback_cable *cable = dpcm->cable;
cable->hw.formats = (1ULL << runtime->format);
cable->hw.rate_min = runtime->rate;
cable->hw.rate_max = runtime->rate;
cable->hw.channels_min = runtime->channels;
cable->hw.channels_max = runtime->channels;
params_change_substream(cable->streams[SNDRV_PCM_STREAM_PLAYBACK],
runtime);
params_change_substream(cable->streams[SNDRV_PCM_STREAM_CAPTURE],
runtime);
}
static int loopback_prepare(struct snd_pcm_substream *substream)
{
struct snd_pcm_runtime *runtime = substream->runtime;
struct loopback_pcm *dpcm = runtime->private_data;
struct loopback_cable *cable = dpcm->cable;
int bps, salign;
salign = (snd_pcm_format_width(runtime->format) *
runtime->channels) / 8;
bps = salign * runtime->rate;
if (bps <= 0 || salign <= 0)
return -EINVAL;
dpcm->buf_pos = 0;
dpcm->pcm_buffer_size = frames_to_bytes(runtime, runtime->buffer_size);
if (substream->stream == SNDRV_PCM_STREAM_CAPTURE) {
dpcm->silent_size = dpcm->pcm_buffer_size;
snd_pcm_format_set_silence(runtime->format, runtime->dma_area,
runtime->buffer_size * runtime->channels);
}
dpcm->irq_pos = 0;
dpcm->period_update_pending = 0;
dpcm->pcm_bps = bps;
dpcm->pcm_salign = salign;
dpcm->pcm_period_size = frames_to_bytes(runtime, runtime->period_size);
mutex_lock(&dpcm->loopback->cable_lock);
if (!(cable->valid & ~(1 << substream->stream)) ||
(get_setup(dpcm)->notify &&
substream->stream == SNDRV_PCM_STREAM_PLAYBACK))
params_change(substream);
cable->valid |= 1 << substream->stream;
mutex_unlock(&dpcm->loopback->cable_lock);
return 0;
}
static void clear_capture_buf(struct loopback_pcm *dpcm, unsigned int bytes)
{
struct snd_pcm_runtime *runtime = dpcm->substream->runtime;
char *dst = runtime->dma_area;
unsigned int dst_off = dpcm->buf_pos;
if (dpcm->silent_size >= dpcm->pcm_buffer_size)
return;
if (dpcm->silent_size + bytes > dpcm->pcm_buffer_size)
bytes = dpcm->pcm_buffer_size - dpcm->silent_size;
for (;;) {
unsigned int size = bytes;
if (dst_off + size > dpcm->pcm_buffer_size)
size = dpcm->pcm_buffer_size - dst_off;
snd_pcm_format_set_silence(runtime->format, dst + dst_off,
bytes_to_frames(runtime, size) *
runtime->channels);
dpcm->silent_size += size;
bytes -= size;
if (!bytes)
break;
dst_off = 0;
}
}
static void copy_play_buf(struct loopback_pcm *play,
struct loopback_pcm *capt,
unsigned int bytes)
{
struct snd_pcm_runtime *runtime = play->substream->runtime;
char *src = runtime->dma_area;
char *dst = capt->substream->runtime->dma_area;
unsigned int src_off = play->buf_pos;
unsigned int dst_off = capt->buf_pos;
unsigned int clear_bytes = 0;
if (runtime->status->state == SNDRV_PCM_STATE_DRAINING &&
snd_pcm_playback_hw_avail(runtime) < runtime->buffer_size) {
snd_pcm_uframes_t appl_ptr, appl_ptr1, diff;
appl_ptr = appl_ptr1 = runtime->control->appl_ptr;
appl_ptr1 -= appl_ptr1 % runtime->buffer_size;
appl_ptr1 += play->buf_pos / play->pcm_salign;
if (appl_ptr < appl_ptr1)
appl_ptr1 -= runtime->buffer_size;
diff = (appl_ptr - appl_ptr1) * play->pcm_salign;
if (diff < bytes) {
clear_bytes = bytes - diff;
bytes = diff;
}
}
for (;;) {
unsigned int size = bytes;
if (src_off + size > play->pcm_buffer_size)
size = play->pcm_buffer_size - src_off;
if (dst_off + size > capt->pcm_buffer_size)
size = capt->pcm_buffer_size - dst_off;
memcpy(dst + dst_off, src + src_off, size);
capt->silent_size = 0;
bytes -= size;
if (!bytes)
break;
src_off = (src_off + size) % play->pcm_buffer_size;
dst_off = (dst_off + size) % capt->pcm_buffer_size;
}
if (clear_bytes > 0) {
clear_capture_buf(capt, clear_bytes);
capt->silent_size = 0;
}
}
static inline unsigned int bytepos_delta(struct loopback_pcm *dpcm,
unsigned int jiffies_delta)
{
unsigned long last_pos;
unsigned int delta;
last_pos = byte_pos(dpcm, dpcm->irq_pos);
dpcm->irq_pos += jiffies_delta * dpcm->pcm_bps;
delta = byte_pos(dpcm, dpcm->irq_pos) - last_pos;
if (delta >= dpcm->last_drift)
delta -= dpcm->last_drift;
dpcm->last_drift = 0;
if (dpcm->irq_pos >= dpcm->period_size_frac) {
dpcm->irq_pos %= dpcm->period_size_frac;
dpcm->period_update_pending = 1;
}
return delta;
}
static inline void bytepos_finish(struct loopback_pcm *dpcm,
unsigned int delta)
{
dpcm->buf_pos += delta;
dpcm->buf_pos %= dpcm->pcm_buffer_size;
}
static unsigned int loopback_pos_update(struct loopback_cable *cable)
{
struct loopback_pcm *dpcm_play =
cable->streams[SNDRV_PCM_STREAM_PLAYBACK];
struct loopback_pcm *dpcm_capt =
cable->streams[SNDRV_PCM_STREAM_CAPTURE];
unsigned long delta_play = 0, delta_capt = 0;
unsigned int running, count1, count2;
unsigned long flags;
spin_lock_irqsave(&cable->lock, flags);
running = cable->running ^ cable->pause;
if (running & (1 << SNDRV_PCM_STREAM_PLAYBACK)) {
delta_play = jiffies - dpcm_play->last_jiffies;
dpcm_play->last_jiffies += delta_play;
}
if (running & (1 << SNDRV_PCM_STREAM_CAPTURE)) {
delta_capt = jiffies - dpcm_capt->last_jiffies;
dpcm_capt->last_jiffies += delta_capt;
}
if (delta_play == 0 && delta_capt == 0)
goto unlock;
if (delta_play > delta_capt) {
count1 = bytepos_delta(dpcm_play, delta_play - delta_capt);
bytepos_finish(dpcm_play, count1);
delta_play = delta_capt;
} else if (delta_play < delta_capt) {
count1 = bytepos_delta(dpcm_capt, delta_capt - delta_play);
clear_capture_buf(dpcm_capt, count1);
bytepos_finish(dpcm_capt, count1);
delta_capt = delta_play;
}
if (delta_play == 0 && delta_capt == 0)
goto unlock;
count1 = bytepos_delta(dpcm_play, delta_play);
count2 = bytepos_delta(dpcm_capt, delta_capt);
if (count1 < count2) {
dpcm_capt->last_drift = count2 - count1;
count1 = count2;
} else if (count1 > count2) {
dpcm_play->last_drift = count1 - count2;
}
copy_play_buf(dpcm_play, dpcm_capt, count1);
bytepos_finish(dpcm_play, count1);
bytepos_finish(dpcm_capt, count1);
unlock:
spin_unlock_irqrestore(&cable->lock, flags);
return running;
}
static void loopback_timer_function(unsigned long data)
{
struct loopback_pcm *dpcm = (struct loopback_pcm *)data;
unsigned int running;
running = loopback_pos_update(dpcm->cable);
if (running & (1 << dpcm->substream->stream)) {
loopback_timer_start(dpcm);
if (dpcm->period_update_pending) {
dpcm->period_update_pending = 0;
snd_pcm_period_elapsed(dpcm->substream);
}
}
}
static snd_pcm_uframes_t loopback_pointer(struct snd_pcm_substream *substream)
{
struct snd_pcm_runtime *runtime = substream->runtime;
struct loopback_pcm *dpcm = runtime->private_data;
loopback_pos_update(dpcm->cable);
return bytes_to_frames(runtime, dpcm->buf_pos);
}
static void loopback_runtime_free(struct snd_pcm_runtime *runtime)
{
struct loopback_pcm *dpcm = runtime->private_data;
kfree(dpcm);
}
static int loopback_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
return snd_pcm_lib_alloc_vmalloc_buffer(substream,
params_buffer_bytes(params));
}
static int loopback_hw_free(struct snd_pcm_substream *substream)
{
struct snd_pcm_runtime *runtime = substream->runtime;
struct loopback_pcm *dpcm = runtime->private_data;
struct loopback_cable *cable = dpcm->cable;
mutex_lock(&dpcm->loopback->cable_lock);
cable->valid &= ~(1 << substream->stream);
mutex_unlock(&dpcm->loopback->cable_lock);
return snd_pcm_lib_free_vmalloc_buffer(substream);
}
static unsigned int get_cable_index(struct snd_pcm_substream *substream)
{
if (!substream->pcm->device)
return substream->stream;
else
return !substream->stream;
}
static int rule_format(struct snd_pcm_hw_params *params,
struct snd_pcm_hw_rule *rule)
{
struct snd_pcm_hardware *hw = rule->private;
struct snd_mask *maskp = hw_param_mask(params, rule->var);
maskp->bits[0] &= (u_int32_t)hw->formats;
maskp->bits[1] &= (u_int32_t)(hw->formats >> 32);
memset(maskp->bits + 2, 0, (SNDRV_MASK_MAX-64) / 8);
if (! maskp->bits[0] && ! maskp->bits[1])
return -EINVAL;
return 0;
}
static int rule_rate(struct snd_pcm_hw_params *params,
struct snd_pcm_hw_rule *rule)
{
struct snd_pcm_hardware *hw = rule->private;
struct snd_interval t;
t.min = hw->rate_min;
t.max = hw->rate_max;
t.openmin = t.openmax = 0;
t.integer = 0;
return snd_interval_refine(hw_param_interval(params, rule->var), &t);
}
static int rule_channels(struct snd_pcm_hw_params *params,
struct snd_pcm_hw_rule *rule)
{
struct snd_pcm_hardware *hw = rule->private;
struct snd_interval t;
t.min = hw->channels_min;
t.max = hw->channels_max;
t.openmin = t.openmax = 0;
t.integer = 0;
return snd_interval_refine(hw_param_interval(params, rule->var), &t);
}
static int loopback_open(struct snd_pcm_substream *substream)
{
struct snd_pcm_runtime *runtime = substream->runtime;
struct loopback *loopback = substream->private_data;
struct loopback_pcm *dpcm;
struct loopback_cable *cable;
int err = 0;
int dev = get_cable_index(substream);
mutex_lock(&loopback->cable_lock);
dpcm = kzalloc(sizeof(*dpcm), GFP_KERNEL);
if (!dpcm) {
err = -ENOMEM;
goto unlock;
}
dpcm->loopback = loopback;
dpcm->substream = substream;
setup_timer(&dpcm->timer, loopback_timer_function,
(unsigned long)dpcm);
cable = loopback->cables[substream->number][dev];
if (!cable) {
cable = kzalloc(sizeof(*cable), GFP_KERNEL);
if (!cable) {
kfree(dpcm);
err = -ENOMEM;
goto unlock;
}
spin_lock_init(&cable->lock);
cable->hw = loopback_pcm_hardware;
loopback->cables[substream->number][dev] = cable;
}
dpcm->cable = cable;
cable->streams[substream->stream] = dpcm;
snd_pcm_hw_constraint_integer(runtime, SNDRV_PCM_HW_PARAM_PERIODS);
err = snd_pcm_hw_rule_add(runtime, 0,
SNDRV_PCM_HW_PARAM_FORMAT,
rule_format, &runtime->hw,
SNDRV_PCM_HW_PARAM_FORMAT, -1);
if (err < 0)
goto unlock;
err = snd_pcm_hw_rule_add(runtime, 0,
SNDRV_PCM_HW_PARAM_RATE,
rule_rate, &runtime->hw,
SNDRV_PCM_HW_PARAM_RATE, -1);
if (err < 0)
goto unlock;
err = snd_pcm_hw_rule_add(runtime, 0,
SNDRV_PCM_HW_PARAM_CHANNELS,
rule_channels, &runtime->hw,
SNDRV_PCM_HW_PARAM_CHANNELS, -1);
if (err < 0)
goto unlock;
runtime->private_data = dpcm;
runtime->private_free = loopback_runtime_free;
if (get_notify(dpcm))
runtime->hw = loopback_pcm_hardware;
else
runtime->hw = cable->hw;
unlock:
mutex_unlock(&loopback->cable_lock);
return err;
}
static int loopback_close(struct snd_pcm_substream *substream)
{
struct loopback *loopback = substream->private_data;
struct loopback_pcm *dpcm = substream->runtime->private_data;
struct loopback_cable *cable;
int dev = get_cable_index(substream);
loopback_timer_stop(dpcm);
mutex_lock(&loopback->cable_lock);
cable = loopback->cables[substream->number][dev];
if (cable->streams[!substream->stream]) {
cable->streams[substream->stream] = NULL;
} else {
loopback->cables[substream->number][dev] = NULL;
kfree(cable);
}
mutex_unlock(&loopback->cable_lock);
return 0;
}
static int __devinit loopback_pcm_new(struct loopback *loopback,
int device, int substreams)
{
struct snd_pcm *pcm;
int err;
err = snd_pcm_new(loopback->card, "Loopback PCM", device,
substreams, substreams, &pcm);
if (err < 0)
return err;
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_PLAYBACK, &loopback_playback_ops);
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_CAPTURE, &loopback_capture_ops);
pcm->private_data = loopback;
pcm->info_flags = 0;
strcpy(pcm->name, "Loopback PCM");
loopback->pcm[device] = pcm;
return 0;
}
static int loopback_rate_shift_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = 1;
uinfo->value.integer.min = 80000;
uinfo->value.integer.max = 120000;
uinfo->value.integer.step = 1;
return 0;
}
static int loopback_rate_shift_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct loopback *loopback = snd_kcontrol_chip(kcontrol);
ucontrol->value.integer.value[0] =
loopback->setup[kcontrol->id.subdevice]
[kcontrol->id.device].rate_shift;
return 0;
}
static int loopback_rate_shift_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct loopback *loopback = snd_kcontrol_chip(kcontrol);
unsigned int val;
int change = 0;
val = ucontrol->value.integer.value[0];
if (val < 80000)
val = 80000;
if (val > 120000)
val = 120000;
mutex_lock(&loopback->cable_lock);
if (val != loopback->setup[kcontrol->id.subdevice]
[kcontrol->id.device].rate_shift) {
loopback->setup[kcontrol->id.subdevice]
[kcontrol->id.device].rate_shift = val;
change = 1;
}
mutex_unlock(&loopback->cable_lock);
return change;
}
static int loopback_notify_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct loopback *loopback = snd_kcontrol_chip(kcontrol);
ucontrol->value.integer.value[0] =
loopback->setup[kcontrol->id.subdevice]
[kcontrol->id.device].notify;
return 0;
}
static int loopback_notify_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct loopback *loopback = snd_kcontrol_chip(kcontrol);
unsigned int val;
int change = 0;
val = ucontrol->value.integer.value[0] ? 1 : 0;
if (val != loopback->setup[kcontrol->id.subdevice]
[kcontrol->id.device].notify) {
loopback->setup[kcontrol->id.subdevice]
[kcontrol->id.device].notify = val;
change = 1;
}
return change;
}
static int loopback_active_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct loopback *loopback = snd_kcontrol_chip(kcontrol);
struct loopback_cable *cable = loopback->cables
[kcontrol->id.subdevice][kcontrol->id.device ^ 1];
unsigned int val = 0;
if (cable != NULL)
val = (cable->running & (1 << SNDRV_PCM_STREAM_PLAYBACK)) ?
1 : 0;
ucontrol->value.integer.value[0] = val;
return 0;
}
static int loopback_format_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = 1;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = SNDRV_PCM_FORMAT_LAST;
uinfo->value.integer.step = 1;
return 0;
}
static int loopback_format_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct loopback *loopback = snd_kcontrol_chip(kcontrol);
ucontrol->value.integer.value[0] =
loopback->setup[kcontrol->id.subdevice]
[kcontrol->id.device].format;
return 0;
}
static int loopback_rate_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = 1;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = 192000;
uinfo->value.integer.step = 1;
return 0;
}
static int loopback_rate_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct loopback *loopback = snd_kcontrol_chip(kcontrol);
ucontrol->value.integer.value[0] =
loopback->setup[kcontrol->id.subdevice]
[kcontrol->id.device].rate;
return 0;
}
static int loopback_channels_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = 1;
uinfo->value.integer.min = 1;
uinfo->value.integer.max = 1024;
uinfo->value.integer.step = 1;
return 0;
}
static int loopback_channels_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct loopback *loopback = snd_kcontrol_chip(kcontrol);
ucontrol->value.integer.value[0] =
loopback->setup[kcontrol->id.subdevice]
[kcontrol->id.device].channels;
return 0;
}
static int __devinit loopback_mixer_new(struct loopback *loopback, int notify)
{
struct snd_card *card = loopback->card;
struct snd_pcm *pcm;
struct snd_kcontrol *kctl;
struct loopback_setup *setup;
int err, dev, substr, substr_count, idx;
strcpy(card->mixername, "Loopback Mixer");
for (dev = 0; dev < 2; dev++) {
pcm = loopback->pcm[dev];
substr_count =
pcm->streams[SNDRV_PCM_STREAM_CAPTURE].substream_count;
for (substr = 0; substr < substr_count; substr++) {
setup = &loopback->setup[substr][dev];
setup->notify = notify;
setup->rate_shift = NO_PITCH;
setup->format = SNDRV_PCM_FORMAT_S16_LE;
setup->rate = 48000;
setup->channels = 2;
for (idx = 0; idx < ARRAY_SIZE(loopback_controls);
idx++) {
kctl = snd_ctl_new1(&loopback_controls[idx],
loopback);
if (!kctl)
return -ENOMEM;
kctl->id.device = dev;
kctl->id.subdevice = substr;
switch (idx) {
case ACTIVE_IDX:
setup->active_id = kctl->id;
break;
case FORMAT_IDX:
setup->format_id = kctl->id;
break;
case RATE_IDX:
setup->rate_id = kctl->id;
break;
case CHANNELS_IDX:
setup->channels_id = kctl->id;
break;
default:
break;
}
err = snd_ctl_add(card, kctl);
if (err < 0)
return err;
}
}
}
return 0;
}
static void print_dpcm_info(struct snd_info_buffer *buffer,
struct loopback_pcm *dpcm,
const char *id)
{
snd_iprintf(buffer, " %s\n", id);
if (dpcm == NULL) {
snd_iprintf(buffer, " inactive\n");
return;
}
snd_iprintf(buffer, " buffer_size:\t%u\n", dpcm->pcm_buffer_size);
snd_iprintf(buffer, " buffer_pos:\t\t%u\n", dpcm->buf_pos);
snd_iprintf(buffer, " silent_size:\t%u\n", dpcm->silent_size);
snd_iprintf(buffer, " period_size:\t%u\n", dpcm->pcm_period_size);
snd_iprintf(buffer, " bytes_per_sec:\t%u\n", dpcm->pcm_bps);
snd_iprintf(buffer, " sample_align:\t%u\n", dpcm->pcm_salign);
snd_iprintf(buffer, " rate_shift:\t\t%u\n", dpcm->pcm_rate_shift);
snd_iprintf(buffer, " update_pending:\t%u\n",
dpcm->period_update_pending);
snd_iprintf(buffer, " irq_pos:\t\t%u\n", dpcm->irq_pos);
snd_iprintf(buffer, " period_frac:\t%u\n", dpcm->period_size_frac);
snd_iprintf(buffer, " last_jiffies:\t%lu (%lu)\n",
dpcm->last_jiffies, jiffies);
snd_iprintf(buffer, " timer_expires:\t%lu\n", dpcm->timer.expires);
}
static void print_substream_info(struct snd_info_buffer *buffer,
struct loopback *loopback,
int sub,
int num)
{
struct loopback_cable *cable = loopback->cables[sub][num];
snd_iprintf(buffer, "Cable %i substream %i:\n", num, sub);
if (cable == NULL) {
snd_iprintf(buffer, " inactive\n");
return;
}
snd_iprintf(buffer, " valid: %u\n", cable->valid);
snd_iprintf(buffer, " running: %u\n", cable->running);
snd_iprintf(buffer, " pause: %u\n", cable->pause);
print_dpcm_info(buffer, cable->streams[0], "Playback");
print_dpcm_info(buffer, cable->streams[1], "Capture");
}
static void print_cable_info(struct snd_info_entry *entry,
struct snd_info_buffer *buffer)
{
struct loopback *loopback = entry->private_data;
int sub, num;
mutex_lock(&loopback->cable_lock);
num = entry->name[strlen(entry->name)-1];
num = num == '0' ? 0 : 1;
for (sub = 0; sub < MAX_PCM_SUBSTREAMS; sub++)
print_substream_info(buffer, loopback, sub, num);
mutex_unlock(&loopback->cable_lock);
}
static int __devinit loopback_proc_new(struct loopback *loopback, int cidx)
{
char name[32];
struct snd_info_entry *entry;
int err;
snprintf(name, sizeof(name), "cable#%d", cidx);
err = snd_card_proc_new(loopback->card, name, &entry);
if (err < 0)
return err;
snd_info_set_text_ops(entry, loopback, print_cable_info);
return 0;
}
static int __devinit loopback_probe(struct platform_device *devptr)
{
struct snd_card *card;
struct loopback *loopback;
int dev = devptr->id;
int err;
err = snd_card_create(index[dev], id[dev], THIS_MODULE,
sizeof(struct loopback), &card);
if (err < 0)
return err;
loopback = card->private_data;
if (pcm_substreams[dev] < 1)
pcm_substreams[dev] = 1;
if (pcm_substreams[dev] > MAX_PCM_SUBSTREAMS)
pcm_substreams[dev] = MAX_PCM_SUBSTREAMS;
loopback->card = card;
mutex_init(&loopback->cable_lock);
err = loopback_pcm_new(loopback, 0, pcm_substreams[dev]);
if (err < 0)
goto __nodev;
err = loopback_pcm_new(loopback, 1, pcm_substreams[dev]);
if (err < 0)
goto __nodev;
err = loopback_mixer_new(loopback, pcm_notify[dev] ? 1 : 0);
if (err < 0)
goto __nodev;
loopback_proc_new(loopback, 0);
loopback_proc_new(loopback, 1);
strcpy(card->driver, "Loopback");
strcpy(card->shortname, "Loopback");
sprintf(card->longname, "Loopback %i", dev + 1);
err = snd_card_register(card);
if (!err) {
platform_set_drvdata(devptr, card);
return 0;
}
__nodev:
snd_card_free(card);
return err;
}
static int __devexit loopback_remove(struct platform_device *devptr)
{
snd_card_free(platform_get_drvdata(devptr));
platform_set_drvdata(devptr, NULL);
return 0;
}
static int loopback_suspend(struct device *pdev)
{
struct snd_card *card = dev_get_drvdata(pdev);
struct loopback *loopback = card->private_data;
snd_power_change_state(card, SNDRV_CTL_POWER_D3hot);
snd_pcm_suspend_all(loopback->pcm[0]);
snd_pcm_suspend_all(loopback->pcm[1]);
return 0;
}
static int loopback_resume(struct device *pdev)
{
struct snd_card *card = dev_get_drvdata(pdev);
snd_power_change_state(card, SNDRV_CTL_POWER_D0);
return 0;
}
static void loopback_unregister_all(void)
{
int i;
for (i = 0; i < ARRAY_SIZE(devices); ++i)
platform_device_unregister(devices[i]);
platform_driver_unregister(&loopback_driver);
}
static int __init alsa_card_loopback_init(void)
{
int i, err, cards;
err = platform_driver_register(&loopback_driver);
if (err < 0)
return err;
cards = 0;
for (i = 0; i < SNDRV_CARDS; i++) {
struct platform_device *device;
if (!enable[i])
continue;
device = platform_device_register_simple(SND_LOOPBACK_DRIVER,
i, NULL, 0);
if (IS_ERR(device))
continue;
if (!platform_get_drvdata(device)) {
platform_device_unregister(device);
continue;
}
devices[i] = device;
cards++;
}
if (!cards) {
#ifdef MODULE
printk(KERN_ERR "aloop: No loopback enabled\n");
#endif
loopback_unregister_all();
return -ENODEV;
}
return 0;
}
static void __exit alsa_card_loopback_exit(void)
{
loopback_unregister_all();
}
