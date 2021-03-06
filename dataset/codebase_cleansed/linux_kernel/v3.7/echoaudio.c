static int get_firmware(const struct firmware **fw_entry,
struct echoaudio *chip, const short fw_index)
{
int err;
char name[30];
#ifdef CONFIG_PM_SLEEP
if (chip->fw_cache[fw_index]) {
DE_ACT(("firmware requested: %s is cached\n", card_fw[fw_index].data));
*fw_entry = chip->fw_cache[fw_index];
return 0;
}
#endif
DE_ACT(("firmware requested: %s\n", card_fw[fw_index].data));
snprintf(name, sizeof(name), "ea/%s", card_fw[fw_index].data);
err = request_firmware(fw_entry, name, pci_device(chip));
if (err < 0)
snd_printk(KERN_ERR "get_firmware(): Firmware not available (%d)\n", err);
#ifdef CONFIG_PM_SLEEP
else
chip->fw_cache[fw_index] = *fw_entry;
#endif
return err;
}
static void free_firmware(const struct firmware *fw_entry)
{
#ifdef CONFIG_PM_SLEEP
DE_ACT(("firmware not released (kept in cache)\n"));
#else
release_firmware(fw_entry);
DE_ACT(("firmware released\n"));
#endif
}
static void free_firmware_cache(struct echoaudio *chip)
{
#ifdef CONFIG_PM_SLEEP
int i;
for (i = 0; i < 8 ; i++)
if (chip->fw_cache[i]) {
release_firmware(chip->fw_cache[i]);
DE_ACT(("release_firmware(%d)\n", i));
}
DE_ACT(("firmware_cache released\n"));
#endif
}
static void audiopipe_free(struct snd_pcm_runtime *runtime)
{
struct audiopipe *pipe = runtime->private_data;
if (pipe->sgpage.area)
snd_dma_free_pages(&pipe->sgpage);
kfree(pipe);
}
static int hw_rule_capture_format_by_channels(struct snd_pcm_hw_params *params,
struct snd_pcm_hw_rule *rule)
{
struct snd_interval *c = hw_param_interval(params,
SNDRV_PCM_HW_PARAM_CHANNELS);
struct snd_mask *f = hw_param_mask(params, SNDRV_PCM_HW_PARAM_FORMAT);
struct snd_mask fmt;
snd_mask_any(&fmt);
#ifndef ECHOCARD_HAS_STEREO_BIG_ENDIAN32
if (c->min == 2) {
fmt.bits[0] &= ~SNDRV_PCM_FMTBIT_S32_BE;
return snd_mask_refine(f, &fmt);
}
#endif
if (c->min > 2) {
fmt.bits[0] &= ~(SNDRV_PCM_FMTBIT_U8 | SNDRV_PCM_FMTBIT_S32_BE);
return snd_mask_refine(f, &fmt);
}
return 0;
}
static int hw_rule_capture_channels_by_format(struct snd_pcm_hw_params *params,
struct snd_pcm_hw_rule *rule)
{
struct snd_interval *c = hw_param_interval(params,
SNDRV_PCM_HW_PARAM_CHANNELS);
struct snd_mask *f = hw_param_mask(params, SNDRV_PCM_HW_PARAM_FORMAT);
struct snd_interval ch;
snd_interval_any(&ch);
if (f->bits[0] == SNDRV_PCM_FMTBIT_S32_BE) {
ch.min = 1;
#ifdef ECHOCARD_HAS_STEREO_BIG_ENDIAN32
ch.max = 2;
#else
ch.max = 1;
#endif
ch.integer = 1;
return snd_interval_refine(c, &ch);
}
if (f->bits[0] == SNDRV_PCM_FMTBIT_U8) {
ch.min = 1;
ch.max = 2;
ch.integer = 1;
return snd_interval_refine(c, &ch);
}
return 0;
}
static int hw_rule_playback_format_by_channels(struct snd_pcm_hw_params *params,
struct snd_pcm_hw_rule *rule)
{
struct snd_interval *c = hw_param_interval(params,
SNDRV_PCM_HW_PARAM_CHANNELS);
struct snd_mask *f = hw_param_mask(params, SNDRV_PCM_HW_PARAM_FORMAT);
struct snd_mask fmt;
u64 fmask;
snd_mask_any(&fmt);
fmask = fmt.bits[0] + ((u64)fmt.bits[1] << 32);
if (c->min > 2) {
fmask &= SNDRV_PCM_FMTBIT_S16_LE |
SNDRV_PCM_FMTBIT_S24_3LE |
SNDRV_PCM_FMTBIT_S32_LE;
} else if (c->max == 1)
fmask &= SNDRV_PCM_FMTBIT_S32_LE | SNDRV_PCM_FMTBIT_S32_BE;
#ifndef ECHOCARD_HAS_STEREO_BIG_ENDIAN32
else if (c->min == 2 && c->max == 2)
fmask &= ~SNDRV_PCM_FMTBIT_S32_BE;
#endif
else
return 0;
fmt.bits[0] &= (u32)fmask;
fmt.bits[1] &= (u32)(fmask >> 32);
return snd_mask_refine(f, &fmt);
}
static int hw_rule_playback_channels_by_format(struct snd_pcm_hw_params *params,
struct snd_pcm_hw_rule *rule)
{
struct snd_interval *c = hw_param_interval(params,
SNDRV_PCM_HW_PARAM_CHANNELS);
struct snd_mask *f = hw_param_mask(params, SNDRV_PCM_HW_PARAM_FORMAT);
struct snd_interval ch;
u64 fmask;
snd_interval_any(&ch);
ch.integer = 1;
fmask = f->bits[0] + ((u64)f->bits[1] << 32);
if (fmask == SNDRV_PCM_FMTBIT_S32_BE) {
ch.min = 1;
#ifdef ECHOCARD_HAS_STEREO_BIG_ENDIAN32
ch.max = 2;
#else
ch.max = 1;
#endif
} else if (fmask == SNDRV_PCM_FMTBIT_U8)
ch.min = ch.max = 2;
else if (!(fmask & ~(SNDRV_PCM_FMTBIT_S16_LE |
SNDRV_PCM_FMTBIT_S24_3LE)))
ch.min = 2;
else
return 0;
return snd_interval_refine(c, &ch);
}
static int hw_rule_sample_rate(struct snd_pcm_hw_params *params,
struct snd_pcm_hw_rule *rule)
{
struct snd_interval *rate = hw_param_interval(params,
SNDRV_PCM_HW_PARAM_RATE);
struct echoaudio *chip = rule->private;
struct snd_interval fixed;
if (!chip->can_set_rate) {
snd_interval_any(&fixed);
fixed.min = fixed.max = chip->sample_rate;
return snd_interval_refine(rate, &fixed);
}
return 0;
}
static int pcm_open(struct snd_pcm_substream *substream,
signed char max_channels)
{
struct echoaudio *chip;
struct snd_pcm_runtime *runtime;
struct audiopipe *pipe;
int err, i;
if (max_channels <= 0)
return -EAGAIN;
chip = snd_pcm_substream_chip(substream);
runtime = substream->runtime;
pipe = kzalloc(sizeof(struct audiopipe), GFP_KERNEL);
if (!pipe)
return -ENOMEM;
pipe->index = -1;
memcpy(&pipe->hw, &pcm_hardware_skel, sizeof(struct snd_pcm_hardware));
DE_HWP(("max_channels=%d\n", max_channels));
pipe->constr.list = channels_list;
pipe->constr.mask = 0;
for (i = 0; channels_list[i] <= max_channels; i++);
pipe->constr.count = i;
if (pipe->hw.channels_max > max_channels)
pipe->hw.channels_max = max_channels;
if (chip->digital_mode == DIGITAL_MODE_ADAT) {
pipe->hw.rate_max = 48000;
pipe->hw.rates &= SNDRV_PCM_RATE_8000_48000;
}
runtime->hw = pipe->hw;
runtime->private_data = pipe;
runtime->private_free = audiopipe_free;
snd_pcm_set_sync(substream);
if ((err = snd_pcm_hw_constraint_list(runtime, 0,
SNDRV_PCM_HW_PARAM_CHANNELS,
&pipe->constr)) < 0)
return err;
if ((err = snd_pcm_hw_constraint_integer(runtime,
SNDRV_PCM_HW_PARAM_PERIODS)) < 0)
return err;
if ((err = snd_pcm_hw_constraint_step(runtime, 0,
SNDRV_PCM_HW_PARAM_PERIOD_SIZE,
32)) < 0)
return err;
if ((err = snd_pcm_hw_constraint_step(runtime, 0,
SNDRV_PCM_HW_PARAM_BUFFER_SIZE,
32)) < 0)
return err;
if ((err = snd_pcm_hw_rule_add(substream->runtime, 0,
SNDRV_PCM_HW_PARAM_RATE,
hw_rule_sample_rate, chip,
SNDRV_PCM_HW_PARAM_RATE, -1)) < 0)
return err;
if ((err = snd_dma_alloc_pages(SNDRV_DMA_TYPE_DEV,
snd_dma_pci_data(chip->pci),
PAGE_SIZE, &pipe->sgpage)) < 0) {
DE_HWP(("s-g list allocation failed\n"));
return err;
}
return 0;
}
static int pcm_analog_in_open(struct snd_pcm_substream *substream)
{
struct echoaudio *chip = snd_pcm_substream_chip(substream);
int err;
DE_ACT(("pcm_analog_in_open\n"));
if ((err = pcm_open(substream, num_analog_busses_in(chip) -
substream->number)) < 0)
return err;
if ((err = snd_pcm_hw_rule_add(substream->runtime, 0,
SNDRV_PCM_HW_PARAM_CHANNELS,
hw_rule_capture_channels_by_format, NULL,
SNDRV_PCM_HW_PARAM_FORMAT, -1)) < 0)
return err;
if ((err = snd_pcm_hw_rule_add(substream->runtime, 0,
SNDRV_PCM_HW_PARAM_FORMAT,
hw_rule_capture_format_by_channels, NULL,
SNDRV_PCM_HW_PARAM_CHANNELS, -1)) < 0)
return err;
atomic_inc(&chip->opencount);
if (atomic_read(&chip->opencount) > 1 && chip->rate_set)
chip->can_set_rate=0;
DE_HWP(("pcm_analog_in_open cs=%d oc=%d r=%d\n",
chip->can_set_rate, atomic_read(&chip->opencount),
chip->sample_rate));
return 0;
}
static int pcm_analog_out_open(struct snd_pcm_substream *substream)
{
struct echoaudio *chip = snd_pcm_substream_chip(substream);
int max_channels, err;
#ifdef ECHOCARD_HAS_VMIXER
max_channels = num_pipes_out(chip);
#else
max_channels = num_analog_busses_out(chip);
#endif
DE_ACT(("pcm_analog_out_open\n"));
if ((err = pcm_open(substream, max_channels - substream->number)) < 0)
return err;
if ((err = snd_pcm_hw_rule_add(substream->runtime, 0,
SNDRV_PCM_HW_PARAM_CHANNELS,
hw_rule_playback_channels_by_format,
NULL,
SNDRV_PCM_HW_PARAM_FORMAT, -1)) < 0)
return err;
if ((err = snd_pcm_hw_rule_add(substream->runtime, 0,
SNDRV_PCM_HW_PARAM_FORMAT,
hw_rule_playback_format_by_channels,
NULL,
SNDRV_PCM_HW_PARAM_CHANNELS, -1)) < 0)
return err;
atomic_inc(&chip->opencount);
if (atomic_read(&chip->opencount) > 1 && chip->rate_set)
chip->can_set_rate=0;
DE_HWP(("pcm_analog_out_open cs=%d oc=%d r=%d\n",
chip->can_set_rate, atomic_read(&chip->opencount),
chip->sample_rate));
return 0;
}
static int pcm_digital_in_open(struct snd_pcm_substream *substream)
{
struct echoaudio *chip = snd_pcm_substream_chip(substream);
int err, max_channels;
DE_ACT(("pcm_digital_in_open\n"));
max_channels = num_digital_busses_in(chip) - substream->number;
mutex_lock(&chip->mode_mutex);
if (chip->digital_mode == DIGITAL_MODE_ADAT)
err = pcm_open(substream, max_channels);
else
err = pcm_open(substream, max_channels - ECHOCARD_HAS_ADAT);
if (err < 0)
goto din_exit;
if ((err = snd_pcm_hw_rule_add(substream->runtime, 0,
SNDRV_PCM_HW_PARAM_CHANNELS,
hw_rule_capture_channels_by_format, NULL,
SNDRV_PCM_HW_PARAM_FORMAT, -1)) < 0)
goto din_exit;
if ((err = snd_pcm_hw_rule_add(substream->runtime, 0,
SNDRV_PCM_HW_PARAM_FORMAT,
hw_rule_capture_format_by_channels, NULL,
SNDRV_PCM_HW_PARAM_CHANNELS, -1)) < 0)
goto din_exit;
atomic_inc(&chip->opencount);
if (atomic_read(&chip->opencount) > 1 && chip->rate_set)
chip->can_set_rate=0;
din_exit:
mutex_unlock(&chip->mode_mutex);
return err;
}
static int pcm_digital_out_open(struct snd_pcm_substream *substream)
{
struct echoaudio *chip = snd_pcm_substream_chip(substream);
int err, max_channels;
DE_ACT(("pcm_digital_out_open\n"));
max_channels = num_digital_busses_out(chip) - substream->number;
mutex_lock(&chip->mode_mutex);
if (chip->digital_mode == DIGITAL_MODE_ADAT)
err = pcm_open(substream, max_channels);
else
err = pcm_open(substream, max_channels - ECHOCARD_HAS_ADAT);
if (err < 0)
goto dout_exit;
if ((err = snd_pcm_hw_rule_add(substream->runtime, 0,
SNDRV_PCM_HW_PARAM_CHANNELS,
hw_rule_playback_channels_by_format,
NULL, SNDRV_PCM_HW_PARAM_FORMAT,
-1)) < 0)
goto dout_exit;
if ((err = snd_pcm_hw_rule_add(substream->runtime, 0,
SNDRV_PCM_HW_PARAM_FORMAT,
hw_rule_playback_format_by_channels,
NULL, SNDRV_PCM_HW_PARAM_CHANNELS,
-1)) < 0)
goto dout_exit;
atomic_inc(&chip->opencount);
if (atomic_read(&chip->opencount) > 1 && chip->rate_set)
chip->can_set_rate=0;
dout_exit:
mutex_unlock(&chip->mode_mutex);
return err;
}
static int pcm_close(struct snd_pcm_substream *substream)
{
struct echoaudio *chip = snd_pcm_substream_chip(substream);
int oc;
DE_ACT(("pcm_close\n"));
atomic_dec(&chip->opencount);
oc = atomic_read(&chip->opencount);
DE_ACT(("pcm_close oc=%d cs=%d rs=%d\n", oc,
chip->can_set_rate, chip->rate_set));
if (oc < 2)
chip->can_set_rate = 1;
if (oc == 0)
chip->rate_set = 0;
DE_ACT(("pcm_close2 oc=%d cs=%d rs=%d\n", oc,
chip->can_set_rate,chip->rate_set));
return 0;
}
static int init_engine(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *hw_params,
int pipe_index, int interleave)
{
struct echoaudio *chip;
int err, per, rest, page, edge, offs;
struct audiopipe *pipe;
chip = snd_pcm_substream_chip(substream);
pipe = (struct audiopipe *) substream->runtime->private_data;
spin_lock_irq(&chip->lock);
if (pipe->index >= 0) {
DE_HWP(("hwp_ie free(%d)\n", pipe->index));
err = free_pipes(chip, pipe);
snd_BUG_ON(err);
chip->substream[pipe->index] = NULL;
}
err = allocate_pipes(chip, pipe, pipe_index, interleave);
if (err < 0) {
spin_unlock_irq(&chip->lock);
DE_ACT((KERN_NOTICE "allocate_pipes(%d) err=%d\n",
pipe_index, err));
return err;
}
spin_unlock_irq(&chip->lock);
DE_ACT((KERN_NOTICE "allocate_pipes()=%d\n", pipe_index));
DE_HWP(("pcm_hw_params (bufsize=%dB periods=%d persize=%dB)\n",
params_buffer_bytes(hw_params), params_periods(hw_params),
params_period_bytes(hw_params)));
err = snd_pcm_lib_malloc_pages(substream,
params_buffer_bytes(hw_params));
if (err < 0) {
snd_printk(KERN_ERR "malloc_pages err=%d\n", err);
spin_lock_irq(&chip->lock);
free_pipes(chip, pipe);
spin_unlock_irq(&chip->lock);
pipe->index = -1;
return err;
}
sglist_init(chip, pipe);
edge = PAGE_SIZE;
for (offs = page = per = 0; offs < params_buffer_bytes(hw_params);
per++) {
rest = params_period_bytes(hw_params);
if (offs + rest > params_buffer_bytes(hw_params))
rest = params_buffer_bytes(hw_params) - offs;
while (rest) {
dma_addr_t addr;
addr = snd_pcm_sgbuf_get_addr(substream, offs);
if (rest <= edge - offs) {
sglist_add_mapping(chip, pipe, addr, rest);
sglist_add_irq(chip, pipe);
offs += rest;
rest = 0;
} else {
sglist_add_mapping(chip, pipe, addr,
edge - offs);
rest -= edge - offs;
offs = edge;
}
if (offs == edge) {
edge += PAGE_SIZE;
page++;
}
}
}
sglist_wrap(chip, pipe);
chip->last_period[pipe_index] = 0;
pipe->last_counter = 0;
pipe->position = 0;
smp_wmb();
chip->substream[pipe_index] = substream;
chip->rate_set = 1;
spin_lock_irq(&chip->lock);
set_sample_rate(chip, hw_params->rate_num / hw_params->rate_den);
spin_unlock_irq(&chip->lock);
DE_HWP(("pcm_hw_params ok\n"));
return 0;
}
static int pcm_analog_in_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *hw_params)
{
struct echoaudio *chip = snd_pcm_substream_chip(substream);
return init_engine(substream, hw_params, px_analog_in(chip) +
substream->number, params_channels(hw_params));
}
static int pcm_analog_out_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *hw_params)
{
return init_engine(substream, hw_params, substream->number,
params_channels(hw_params));
}
static int pcm_digital_in_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *hw_params)
{
struct echoaudio *chip = snd_pcm_substream_chip(substream);
return init_engine(substream, hw_params, px_digital_in(chip) +
substream->number, params_channels(hw_params));
}
static int pcm_digital_out_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *hw_params)
{
struct echoaudio *chip = snd_pcm_substream_chip(substream);
return init_engine(substream, hw_params, px_digital_out(chip) +
substream->number, params_channels(hw_params));
}
static int pcm_hw_free(struct snd_pcm_substream *substream)
{
struct echoaudio *chip;
struct audiopipe *pipe;
chip = snd_pcm_substream_chip(substream);
pipe = (struct audiopipe *) substream->runtime->private_data;
spin_lock_irq(&chip->lock);
if (pipe->index >= 0) {
DE_HWP(("pcm_hw_free(%d)\n", pipe->index));
free_pipes(chip, pipe);
chip->substream[pipe->index] = NULL;
pipe->index = -1;
}
spin_unlock_irq(&chip->lock);
DE_HWP(("pcm_hw_freed\n"));
snd_pcm_lib_free_pages(substream);
return 0;
}
static int pcm_prepare(struct snd_pcm_substream *substream)
{
struct echoaudio *chip = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
struct audioformat format;
int pipe_index = ((struct audiopipe *)runtime->private_data)->index;
DE_HWP(("Prepare rate=%d format=%d channels=%d\n",
runtime->rate, runtime->format, runtime->channels));
format.interleave = runtime->channels;
format.data_are_bigendian = 0;
format.mono_to_stereo = 0;
switch (runtime->format) {
case SNDRV_PCM_FORMAT_U8:
format.bits_per_sample = 8;
break;
case SNDRV_PCM_FORMAT_S16_LE:
format.bits_per_sample = 16;
break;
case SNDRV_PCM_FORMAT_S24_3LE:
format.bits_per_sample = 24;
break;
case SNDRV_PCM_FORMAT_S32_BE:
format.data_are_bigendian = 1;
case SNDRV_PCM_FORMAT_S32_LE:
format.bits_per_sample = 32;
break;
default:
DE_HWP(("Prepare error: unsupported format %d\n",
runtime->format));
return -EINVAL;
}
if (snd_BUG_ON(pipe_index >= px_num(chip)))
return -EINVAL;
if (snd_BUG_ON(!is_pipe_allocated(chip, pipe_index)))
return -EINVAL;
set_audio_format(chip, pipe_index, &format);
return 0;
}
static int pcm_trigger(struct snd_pcm_substream *substream, int cmd)
{
struct echoaudio *chip = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
struct audiopipe *pipe = runtime->private_data;
int i, err;
u32 channelmask = 0;
struct snd_pcm_substream *s;
snd_pcm_group_for_each_entry(s, substream) {
for (i = 0; i < DSP_MAXPIPES; i++) {
if (s == chip->substream[i]) {
channelmask |= 1 << i;
snd_pcm_trigger_done(s, substream);
}
}
}
spin_lock(&chip->lock);
switch (cmd) {
case SNDRV_PCM_TRIGGER_RESUME:
DE_ACT(("pcm_trigger resume\n"));
case SNDRV_PCM_TRIGGER_START:
case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
DE_ACT(("pcm_trigger start\n"));
for (i = 0; i < DSP_MAXPIPES; i++) {
if (channelmask & (1 << i)) {
pipe = chip->substream[i]->runtime->private_data;
switch (pipe->state) {
case PIPE_STATE_STOPPED:
chip->last_period[i] = 0;
pipe->last_counter = 0;
pipe->position = 0;
*pipe->dma_counter = 0;
case PIPE_STATE_PAUSED:
pipe->state = PIPE_STATE_STARTED;
break;
case PIPE_STATE_STARTED:
break;
}
}
}
err = start_transport(chip, channelmask,
chip->pipe_cyclic_mask);
break;
case SNDRV_PCM_TRIGGER_SUSPEND:
DE_ACT(("pcm_trigger suspend\n"));
case SNDRV_PCM_TRIGGER_STOP:
DE_ACT(("pcm_trigger stop\n"));
for (i = 0; i < DSP_MAXPIPES; i++) {
if (channelmask & (1 << i)) {
pipe = chip->substream[i]->runtime->private_data;
pipe->state = PIPE_STATE_STOPPED;
}
}
err = stop_transport(chip, channelmask);
break;
case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
DE_ACT(("pcm_trigger pause\n"));
for (i = 0; i < DSP_MAXPIPES; i++) {
if (channelmask & (1 << i)) {
pipe = chip->substream[i]->runtime->private_data;
pipe->state = PIPE_STATE_PAUSED;
}
}
err = pause_transport(chip, channelmask);
break;
default:
err = -EINVAL;
}
spin_unlock(&chip->lock);
return err;
}
static snd_pcm_uframes_t pcm_pointer(struct snd_pcm_substream *substream)
{
struct snd_pcm_runtime *runtime = substream->runtime;
struct audiopipe *pipe = runtime->private_data;
size_t cnt, bufsize, pos;
cnt = le32_to_cpu(*pipe->dma_counter);
pipe->position += cnt - pipe->last_counter;
pipe->last_counter = cnt;
bufsize = substream->runtime->buffer_size;
pos = bytes_to_frames(substream->runtime, pipe->position);
while (pos >= bufsize) {
pipe->position -= frames_to_bytes(substream->runtime, bufsize);
pos -= bufsize;
}
return pos;
}
static int snd_echo_preallocate_pages(struct snd_pcm *pcm, struct device *dev)
{
struct snd_pcm_substream *ss;
int stream, err;
for (stream = 0; stream < 2; stream++)
for (ss = pcm->streams[stream].substream; ss; ss = ss->next) {
err = snd_pcm_lib_preallocate_pages(ss, SNDRV_DMA_TYPE_DEV_SG,
dev,
ss->number ? 0 : 128<<10,
256<<10);
if (err < 0)
return err;
}
return 0;
}
static int __devinit snd_echo_new_pcm(struct echoaudio *chip)
{
struct snd_pcm *pcm;
int err;
#ifdef ECHOCARD_HAS_VMIXER
if ((err = snd_pcm_new(chip->card, "PCM", 0, num_pipes_out(chip),
num_analog_busses_in(chip), &pcm)) < 0)
return err;
pcm->private_data = chip;
chip->analog_pcm = pcm;
strcpy(pcm->name, chip->card->shortname);
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_PLAYBACK, &analog_playback_ops);
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_CAPTURE, &analog_capture_ops);
if ((err = snd_echo_preallocate_pages(pcm, snd_dma_pci_data(chip->pci))) < 0)
return err;
DE_INIT(("Analog PCM ok\n"));
#ifdef ECHOCARD_HAS_DIGITAL_IO
if ((err = snd_pcm_new(chip->card, "Digital PCM", 1, 0,
num_digital_busses_in(chip), &pcm)) < 0)
return err;
pcm->private_data = chip;
chip->digital_pcm = pcm;
strcpy(pcm->name, chip->card->shortname);
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_CAPTURE, &digital_capture_ops);
if ((err = snd_echo_preallocate_pages(pcm, snd_dma_pci_data(chip->pci))) < 0)
return err;
DE_INIT(("Digital PCM ok\n"));
#endif
#else
if ((err = snd_pcm_new(chip->card, "Analog PCM", 0,
num_analog_busses_out(chip),
num_analog_busses_in(chip), &pcm)) < 0)
return err;
pcm->private_data = chip;
chip->analog_pcm = pcm;
strcpy(pcm->name, chip->card->shortname);
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_PLAYBACK, &analog_playback_ops);
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_CAPTURE, &analog_capture_ops);
if ((err = snd_echo_preallocate_pages(pcm, snd_dma_pci_data(chip->pci))) < 0)
return err;
DE_INIT(("Analog PCM ok\n"));
#ifdef ECHOCARD_HAS_DIGITAL_IO
if ((err = snd_pcm_new(chip->card, "Digital PCM", 1,
num_digital_busses_out(chip),
num_digital_busses_in(chip), &pcm)) < 0)
return err;
pcm->private_data = chip;
chip->digital_pcm = pcm;
strcpy(pcm->name, chip->card->shortname);
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_PLAYBACK, &digital_playback_ops);
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_CAPTURE, &digital_capture_ops);
if ((err = snd_echo_preallocate_pages(pcm, snd_dma_pci_data(chip->pci))) < 0)
return err;
DE_INIT(("Digital PCM ok\n"));
#endif
#endif
return 0;
}
static int snd_echo_output_gain_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
struct echoaudio *chip;
chip = snd_kcontrol_chip(kcontrol);
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = num_busses_out(chip);
uinfo->value.integer.min = ECHOGAIN_MINOUT;
uinfo->value.integer.max = ECHOGAIN_MAXOUT;
return 0;
}
static int snd_echo_output_gain_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct echoaudio *chip;
int c;
chip = snd_kcontrol_chip(kcontrol);
for (c = 0; c < num_busses_out(chip); c++)
ucontrol->value.integer.value[c] = chip->output_gain[c];
return 0;
}
static int snd_echo_output_gain_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct echoaudio *chip;
int c, changed, gain;
changed = 0;
chip = snd_kcontrol_chip(kcontrol);
spin_lock_irq(&chip->lock);
for (c = 0; c < num_busses_out(chip); c++) {
gain = ucontrol->value.integer.value[c];
if (gain < ECHOGAIN_MINOUT || gain > ECHOGAIN_MAXOUT)
continue;
if (chip->output_gain[c] != gain) {
set_output_gain(chip, c, gain);
changed = 1;
}
}
if (changed)
update_output_line_level(chip);
spin_unlock_irq(&chip->lock);
return changed;
}
static int snd_echo_input_gain_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
struct echoaudio *chip;
chip = snd_kcontrol_chip(kcontrol);
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = num_analog_busses_in(chip);
uinfo->value.integer.min = ECHOGAIN_MININP;
uinfo->value.integer.max = ECHOGAIN_MAXINP;
return 0;
}
static int snd_echo_input_gain_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct echoaudio *chip;
int c;
chip = snd_kcontrol_chip(kcontrol);
for (c = 0; c < num_analog_busses_in(chip); c++)
ucontrol->value.integer.value[c] = chip->input_gain[c];
return 0;
}
static int snd_echo_input_gain_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct echoaudio *chip;
int c, gain, changed;
changed = 0;
chip = snd_kcontrol_chip(kcontrol);
spin_lock_irq(&chip->lock);
for (c = 0; c < num_analog_busses_in(chip); c++) {
gain = ucontrol->value.integer.value[c];
if (gain < ECHOGAIN_MININP || gain > ECHOGAIN_MAXINP)
continue;
if (chip->input_gain[c] != gain) {
set_input_gain(chip, c, gain);
changed = 1;
}
}
if (changed)
update_input_line_level(chip);
spin_unlock_irq(&chip->lock);
return changed;
}
static int snd_echo_output_nominal_info (struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
struct echoaudio *chip;
chip = snd_kcontrol_chip(kcontrol);
uinfo->type = SNDRV_CTL_ELEM_TYPE_BOOLEAN;
uinfo->count = num_analog_busses_out(chip);
uinfo->value.integer.min = 0;
uinfo->value.integer.max = 1;
return 0;
}
static int snd_echo_output_nominal_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct echoaudio *chip;
int c;
chip = snd_kcontrol_chip(kcontrol);
for (c = 0; c < num_analog_busses_out(chip); c++)
ucontrol->value.integer.value[c] = chip->nominal_level[c];
return 0;
}
static int snd_echo_output_nominal_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct echoaudio *chip;
int c, changed;
changed = 0;
chip = snd_kcontrol_chip(kcontrol);
spin_lock_irq(&chip->lock);
for (c = 0; c < num_analog_busses_out(chip); c++) {
if (chip->nominal_level[c] != ucontrol->value.integer.value[c]) {
set_nominal_level(chip, c,
ucontrol->value.integer.value[c]);
changed = 1;
}
}
if (changed)
update_output_line_level(chip);
spin_unlock_irq(&chip->lock);
return changed;
}
static int snd_echo_input_nominal_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
struct echoaudio *chip;
chip = snd_kcontrol_chip(kcontrol);
uinfo->type = SNDRV_CTL_ELEM_TYPE_BOOLEAN;
uinfo->count = num_analog_busses_in(chip);
uinfo->value.integer.min = 0;
uinfo->value.integer.max = 1;
return 0;
}
static int snd_echo_input_nominal_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct echoaudio *chip;
int c;
chip = snd_kcontrol_chip(kcontrol);
for (c = 0; c < num_analog_busses_in(chip); c++)
ucontrol->value.integer.value[c] =
chip->nominal_level[bx_analog_in(chip) + c];
return 0;
}
static int snd_echo_input_nominal_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct echoaudio *chip;
int c, changed;
changed = 0;
chip = snd_kcontrol_chip(kcontrol);
spin_lock_irq(&chip->lock);
for (c = 0; c < num_analog_busses_in(chip); c++) {
if (chip->nominal_level[bx_analog_in(chip) + c] !=
ucontrol->value.integer.value[c]) {
set_nominal_level(chip, bx_analog_in(chip) + c,
ucontrol->value.integer.value[c]);
changed = 1;
}
}
if (changed)
update_output_line_level(chip);
spin_unlock_irq(&chip->lock);
return changed;
}
static int snd_echo_mixer_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
struct echoaudio *chip;
chip = snd_kcontrol_chip(kcontrol);
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = 1;
uinfo->value.integer.min = ECHOGAIN_MINOUT;
uinfo->value.integer.max = ECHOGAIN_MAXOUT;
uinfo->dimen.d[0] = num_busses_out(chip);
uinfo->dimen.d[1] = num_busses_in(chip);
return 0;
}
static int snd_echo_mixer_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct echoaudio *chip;
chip = snd_kcontrol_chip(kcontrol);
ucontrol->value.integer.value[0] =
chip->monitor_gain[ucontrol->id.index / num_busses_in(chip)]
[ucontrol->id.index % num_busses_in(chip)];
return 0;
}
static int snd_echo_mixer_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct echoaudio *chip;
int changed, gain;
short out, in;
changed = 0;
chip = snd_kcontrol_chip(kcontrol);
out = ucontrol->id.index / num_busses_in(chip);
in = ucontrol->id.index % num_busses_in(chip);
gain = ucontrol->value.integer.value[0];
if (gain < ECHOGAIN_MINOUT || gain > ECHOGAIN_MAXOUT)
return -EINVAL;
if (chip->monitor_gain[out][in] != gain) {
spin_lock_irq(&chip->lock);
set_monitor_gain(chip, out, in, gain);
update_output_line_level(chip);
spin_unlock_irq(&chip->lock);
changed = 1;
}
return changed;
}
static int snd_echo_vmixer_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
struct echoaudio *chip;
chip = snd_kcontrol_chip(kcontrol);
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = 1;
uinfo->value.integer.min = ECHOGAIN_MINOUT;
uinfo->value.integer.max = ECHOGAIN_MAXOUT;
uinfo->dimen.d[0] = num_busses_out(chip);
uinfo->dimen.d[1] = num_pipes_out(chip);
return 0;
}
static int snd_echo_vmixer_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct echoaudio *chip;
chip = snd_kcontrol_chip(kcontrol);
ucontrol->value.integer.value[0] =
chip->vmixer_gain[ucontrol->id.index / num_pipes_out(chip)]
[ucontrol->id.index % num_pipes_out(chip)];
return 0;
}
static int snd_echo_vmixer_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct echoaudio *chip;
int gain, changed;
short vch, out;
changed = 0;
chip = snd_kcontrol_chip(kcontrol);
out = ucontrol->id.index / num_pipes_out(chip);
vch = ucontrol->id.index % num_pipes_out(chip);
gain = ucontrol->value.integer.value[0];
if (gain < ECHOGAIN_MINOUT || gain > ECHOGAIN_MAXOUT)
return -EINVAL;
if (chip->vmixer_gain[out][vch] != ucontrol->value.integer.value[0]) {
spin_lock_irq(&chip->lock);
set_vmixer_gain(chip, out, vch, ucontrol->value.integer.value[0]);
update_vmixer_level(chip);
spin_unlock_irq(&chip->lock);
changed = 1;
}
return changed;
}
static int snd_echo_digital_mode_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
static char *names[4] = {
"S/PDIF Coaxial", "S/PDIF Optical", "ADAT Optical",
"S/PDIF Cdrom"
};
struct echoaudio *chip;
chip = snd_kcontrol_chip(kcontrol);
uinfo->type = SNDRV_CTL_ELEM_TYPE_ENUMERATED;
uinfo->value.enumerated.items = chip->num_digital_modes;
uinfo->count = 1;
if (uinfo->value.enumerated.item >= chip->num_digital_modes)
uinfo->value.enumerated.item = chip->num_digital_modes - 1;
strcpy(uinfo->value.enumerated.name, names[
chip->digital_mode_list[uinfo->value.enumerated.item]]);
return 0;
}
static int snd_echo_digital_mode_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct echoaudio *chip;
int i, mode;
chip = snd_kcontrol_chip(kcontrol);
mode = chip->digital_mode;
for (i = chip->num_digital_modes - 1; i >= 0; i--)
if (mode == chip->digital_mode_list[i]) {
ucontrol->value.enumerated.item[0] = i;
break;
}
return 0;
}
static int snd_echo_digital_mode_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct echoaudio *chip;
int changed;
unsigned short emode, dmode;
changed = 0;
chip = snd_kcontrol_chip(kcontrol);
emode = ucontrol->value.enumerated.item[0];
if (emode >= chip->num_digital_modes)
return -EINVAL;
dmode = chip->digital_mode_list[emode];
if (dmode != chip->digital_mode) {
mutex_lock(&chip->mode_mutex);
if (atomic_read(&chip->opencount)) {
changed = -EAGAIN;
} else {
changed = set_digital_mode(chip, dmode);
if (changed > 0 && chip->clock_src_ctl) {
snd_ctl_notify(chip->card,
SNDRV_CTL_EVENT_MASK_VALUE,
&chip->clock_src_ctl->id);
DE_ACT(("SDM() =%d\n", changed));
}
if (changed >= 0)
changed = 1;
}
mutex_unlock(&chip->mode_mutex);
}
return changed;
}
static int snd_echo_spdif_mode_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
static char *names[2] = {"Consumer", "Professional"};
uinfo->type = SNDRV_CTL_ELEM_TYPE_ENUMERATED;
uinfo->value.enumerated.items = 2;
uinfo->count = 1;
if (uinfo->value.enumerated.item)
uinfo->value.enumerated.item = 1;
strcpy(uinfo->value.enumerated.name,
names[uinfo->value.enumerated.item]);
return 0;
}
static int snd_echo_spdif_mode_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct echoaudio *chip;
chip = snd_kcontrol_chip(kcontrol);
ucontrol->value.enumerated.item[0] = !!chip->professional_spdif;
return 0;
}
static int snd_echo_spdif_mode_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct echoaudio *chip;
int mode;
chip = snd_kcontrol_chip(kcontrol);
mode = !!ucontrol->value.enumerated.item[0];
if (mode != chip->professional_spdif) {
spin_lock_irq(&chip->lock);
set_professional_spdif(chip, mode);
spin_unlock_irq(&chip->lock);
return 1;
}
return 0;
}
static int snd_echo_clock_source_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
static char *names[8] = {
"Internal", "Word", "Super", "S/PDIF", "ADAT", "ESync",
"ESync96", "MTC"
};
struct echoaudio *chip;
chip = snd_kcontrol_chip(kcontrol);
uinfo->type = SNDRV_CTL_ELEM_TYPE_ENUMERATED;
uinfo->value.enumerated.items = chip->num_clock_sources;
uinfo->count = 1;
if (uinfo->value.enumerated.item >= chip->num_clock_sources)
uinfo->value.enumerated.item = chip->num_clock_sources - 1;
strcpy(uinfo->value.enumerated.name, names[
chip->clock_source_list[uinfo->value.enumerated.item]]);
return 0;
}
static int snd_echo_clock_source_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct echoaudio *chip;
int i, clock;
chip = snd_kcontrol_chip(kcontrol);
clock = chip->input_clock;
for (i = 0; i < chip->num_clock_sources; i++)
if (clock == chip->clock_source_list[i])
ucontrol->value.enumerated.item[0] = i;
return 0;
}
static int snd_echo_clock_source_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct echoaudio *chip;
int changed;
unsigned int eclock, dclock;
changed = 0;
chip = snd_kcontrol_chip(kcontrol);
eclock = ucontrol->value.enumerated.item[0];
if (eclock >= chip->input_clock_types)
return -EINVAL;
dclock = chip->clock_source_list[eclock];
if (chip->input_clock != dclock) {
mutex_lock(&chip->mode_mutex);
spin_lock_irq(&chip->lock);
if ((changed = set_input_clock(chip, dclock)) == 0)
changed = 1;
spin_unlock_irq(&chip->lock);
mutex_unlock(&chip->mode_mutex);
}
if (changed < 0)
DE_ACT(("seticlk val%d err 0x%x\n", dclock, changed));
return changed;
}
static int snd_echo_phantom_power_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct echoaudio *chip = snd_kcontrol_chip(kcontrol);
ucontrol->value.integer.value[0] = chip->phantom_power;
return 0;
}
static int snd_echo_phantom_power_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct echoaudio *chip = snd_kcontrol_chip(kcontrol);
int power, changed = 0;
power = !!ucontrol->value.integer.value[0];
if (chip->phantom_power != power) {
spin_lock_irq(&chip->lock);
changed = set_phantom_power(chip, power);
spin_unlock_irq(&chip->lock);
if (changed == 0)
changed = 1;
}
return changed;
}
static int snd_echo_automute_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct echoaudio *chip = snd_kcontrol_chip(kcontrol);
ucontrol->value.integer.value[0] = chip->digital_in_automute;
return 0;
}
static int snd_echo_automute_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct echoaudio *chip = snd_kcontrol_chip(kcontrol);
int automute, changed = 0;
automute = !!ucontrol->value.integer.value[0];
if (chip->digital_in_automute != automute) {
spin_lock_irq(&chip->lock);
changed = set_input_auto_mute(chip, automute);
spin_unlock_irq(&chip->lock);
if (changed == 0)
changed = 1;
}
return changed;
}
static int snd_echo_vumeters_switch_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct echoaudio *chip;
chip = snd_kcontrol_chip(kcontrol);
spin_lock_irq(&chip->lock);
set_meters_on(chip, ucontrol->value.integer.value[0]);
spin_unlock_irq(&chip->lock);
return 1;
}
static int snd_echo_vumeters_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
struct echoaudio *chip;
chip = snd_kcontrol_chip(kcontrol);
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = 96;
uinfo->value.integer.min = ECHOGAIN_MINOUT;
uinfo->value.integer.max = 0;
#ifdef ECHOCARD_HAS_VMIXER
uinfo->dimen.d[0] = 3;
#else
uinfo->dimen.d[0] = 2;
#endif
uinfo->dimen.d[1] = 16;
uinfo->dimen.d[2] = 2;
return 0;
}
static int snd_echo_vumeters_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct echoaudio *chip;
chip = snd_kcontrol_chip(kcontrol);
get_audio_meters(chip, ucontrol->value.integer.value);
return 0;
}
static int snd_echo_channels_info_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
struct echoaudio *chip;
chip = snd_kcontrol_chip(kcontrol);
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = 6;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = 1 << ECHO_CLOCK_NUMBER;
return 0;
}
static int snd_echo_channels_info_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct echoaudio *chip;
int detected, clocks, bit, src;
chip = snd_kcontrol_chip(kcontrol);
ucontrol->value.integer.value[0] = num_busses_in(chip);
ucontrol->value.integer.value[1] = num_analog_busses_in(chip);
ucontrol->value.integer.value[2] = num_busses_out(chip);
ucontrol->value.integer.value[3] = num_analog_busses_out(chip);
ucontrol->value.integer.value[4] = num_pipes_out(chip);
detected = detect_input_clocks(chip);
clocks = 0;
src = chip->num_clock_sources - 1;
for (bit = ECHO_CLOCK_NUMBER - 1; bit >= 0; bit--)
if (detected & (1 << bit))
for (; src >= 0; src--)
if (bit == chip->clock_source_list[src]) {
clocks |= 1 << src;
break;
}
ucontrol->value.integer.value[5] = clocks;
return 0;
}
static irqreturn_t snd_echo_interrupt(int irq, void *dev_id)
{
struct echoaudio *chip = dev_id;
struct snd_pcm_substream *substream;
int period, ss, st;
spin_lock(&chip->lock);
st = service_irq(chip);
if (st < 0) {
spin_unlock(&chip->lock);
return IRQ_NONE;
}
for (ss = 0; ss < DSP_MAXPIPES; ss++) {
substream = chip->substream[ss];
if (substream && ((struct audiopipe *)substream->runtime->
private_data)->state == PIPE_STATE_STARTED) {
period = pcm_pointer(substream) /
substream->runtime->period_size;
if (period != chip->last_period[ss]) {
chip->last_period[ss] = period;
spin_unlock(&chip->lock);
snd_pcm_period_elapsed(substream);
spin_lock(&chip->lock);
}
}
}
spin_unlock(&chip->lock);
#ifdef ECHOCARD_HAS_MIDI
if (st > 0 && chip->midi_in) {
snd_rawmidi_receive(chip->midi_in, chip->midi_buffer, st);
DE_MID(("rawmidi_iread=%d\n", st));
}
#endif
return IRQ_HANDLED;
}
static int snd_echo_free(struct echoaudio *chip)
{
DE_INIT(("Stop DSP...\n"));
if (chip->comm_page)
rest_in_peace(chip);
DE_INIT(("Stopped.\n"));
if (chip->irq >= 0)
free_irq(chip->irq, chip);
if (chip->comm_page)
snd_dma_free_pages(&chip->commpage_dma_buf);
if (chip->dsp_registers)
iounmap(chip->dsp_registers);
if (chip->iores)
release_and_free_resource(chip->iores);
DE_INIT(("MMIO freed.\n"));
pci_disable_device(chip->pci);
free_firmware_cache(chip);
kfree(chip);
DE_INIT(("Chip freed.\n"));
return 0;
}
static int snd_echo_dev_free(struct snd_device *device)
{
struct echoaudio *chip = device->device_data;
DE_INIT(("snd_echo_dev_free()...\n"));
return snd_echo_free(chip);
}
static __devinit int snd_echo_create(struct snd_card *card,
struct pci_dev *pci,
struct echoaudio **rchip)
{
struct echoaudio *chip;
int err;
size_t sz;
static struct snd_device_ops ops = {
.dev_free = snd_echo_dev_free,
};
*rchip = NULL;
pci_write_config_byte(pci, PCI_LATENCY_TIMER, 0xC0);
if ((err = pci_enable_device(pci)) < 0)
return err;
pci_set_master(pci);
if (!*rchip) {
chip = kzalloc(sizeof(*chip), GFP_KERNEL);
if (!chip) {
pci_disable_device(pci);
return -ENOMEM;
}
DE_INIT(("chip=%p\n", chip));
spin_lock_init(&chip->lock);
chip->card = card;
chip->pci = pci;
chip->irq = -1;
atomic_set(&chip->opencount, 0);
mutex_init(&chip->mode_mutex);
chip->can_set_rate = 1;
} else {
chip = *rchip;
}
chip->dsp_registers_phys = pci_resource_start(pci, 0);
sz = pci_resource_len(pci, 0);
if (sz > PAGE_SIZE)
sz = PAGE_SIZE;
if ((chip->iores = request_mem_region(chip->dsp_registers_phys, sz,
ECHOCARD_NAME)) == NULL) {
snd_echo_free(chip);
snd_printk(KERN_ERR "cannot get memory region\n");
return -EBUSY;
}
chip->dsp_registers = (volatile u32 __iomem *)
ioremap_nocache(chip->dsp_registers_phys, sz);
if (request_irq(pci->irq, snd_echo_interrupt, IRQF_SHARED,
KBUILD_MODNAME, chip)) {
snd_echo_free(chip);
snd_printk(KERN_ERR "cannot grab irq\n");
return -EBUSY;
}
chip->irq = pci->irq;
DE_INIT(("pci=%p irq=%d subdev=%04x Init hardware...\n",
chip->pci, chip->irq, chip->pci->subsystem_device));
if (snd_dma_alloc_pages(SNDRV_DMA_TYPE_DEV, snd_dma_pci_data(chip->pci),
sizeof(struct comm_page),
&chip->commpage_dma_buf) < 0) {
snd_echo_free(chip);
snd_printk(KERN_ERR "cannot allocate the comm page\n");
return -ENOMEM;
}
chip->comm_page_phys = chip->commpage_dma_buf.addr;
chip->comm_page = (struct comm_page *)chip->commpage_dma_buf.area;
err = init_hw(chip, chip->pci->device, chip->pci->subsystem_device);
if (err >= 0)
err = set_mixer_defaults(chip);
if (err < 0) {
DE_INIT(("init_hw err=%d\n", err));
snd_echo_free(chip);
return err;
}
DE_INIT(("Card init OK\n"));
if ((err = snd_device_new(card, SNDRV_DEV_LOWLEVEL, chip, &ops)) < 0) {
snd_echo_free(chip);
return err;
}
*rchip = chip;
return 0;
}
static int __devinit snd_echo_probe(struct pci_dev *pci,
const struct pci_device_id *pci_id)
{
static int dev;
struct snd_card *card;
struct echoaudio *chip;
char *dsp;
int i, err;
if (dev >= SNDRV_CARDS)
return -ENODEV;
if (!enable[dev]) {
dev++;
return -ENOENT;
}
DE_INIT(("Echoaudio driver starting...\n"));
i = 0;
err = snd_card_create(index[dev], id[dev], THIS_MODULE, 0, &card);
if (err < 0)
return err;
snd_card_set_dev(card, &pci->dev);
chip = NULL;
if ((err = snd_echo_create(card, pci, &chip)) < 0) {
snd_card_free(card);
return err;
}
strcpy(card->driver, "Echo_" ECHOCARD_NAME);
strcpy(card->shortname, chip->card_name);
dsp = "56301";
if (pci_id->device == 0x3410)
dsp = "56361";
sprintf(card->longname, "%s rev.%d (DSP%s) at 0x%lx irq %i",
card->shortname, pci_id->subdevice & 0x000f, dsp,
chip->dsp_registers_phys, chip->irq);
if ((err = snd_echo_new_pcm(chip)) < 0) {
snd_printk(KERN_ERR "new pcm error %d\n", err);
snd_card_free(card);
return err;
}
#ifdef ECHOCARD_HAS_MIDI
if (chip->has_midi) {
if ((err = snd_echo_midi_create(card, chip)) < 0) {
snd_printk(KERN_ERR "new midi error %d\n", err);
snd_card_free(card);
return err;
}
}
#endif
#ifdef ECHOCARD_HAS_VMIXER
snd_echo_vmixer.count = num_pipes_out(chip) * num_busses_out(chip);
if ((err = snd_ctl_add(chip->card, snd_ctl_new1(&snd_echo_vmixer, chip))) < 0)
goto ctl_error;
#ifdef ECHOCARD_HAS_LINE_OUT_GAIN
err = snd_ctl_add(chip->card,
snd_ctl_new1(&snd_echo_line_output_gain, chip));
if (err < 0)
goto ctl_error;
#endif
#else
err = snd_ctl_add(chip->card,
snd_ctl_new1(&snd_echo_pcm_output_gain, chip));
if (err < 0)
goto ctl_error;
#endif
#ifdef ECHOCARD_HAS_INPUT_GAIN
if ((err = snd_ctl_add(chip->card, snd_ctl_new1(&snd_echo_line_input_gain, chip))) < 0)
goto ctl_error;
#endif
#ifdef ECHOCARD_HAS_INPUT_NOMINAL_LEVEL
if (!chip->hasnt_input_nominal_level)
if ((err = snd_ctl_add(chip->card, snd_ctl_new1(&snd_echo_intput_nominal_level, chip))) < 0)
goto ctl_error;
#endif
#ifdef ECHOCARD_HAS_OUTPUT_NOMINAL_LEVEL
if ((err = snd_ctl_add(chip->card, snd_ctl_new1(&snd_echo_output_nominal_level, chip))) < 0)
goto ctl_error;
#endif
if ((err = snd_ctl_add(chip->card, snd_ctl_new1(&snd_echo_vumeters_switch, chip))) < 0)
goto ctl_error;
if ((err = snd_ctl_add(chip->card, snd_ctl_new1(&snd_echo_vumeters, chip))) < 0)
goto ctl_error;
#ifdef ECHOCARD_HAS_MONITOR
snd_echo_monitor_mixer.count = num_busses_in(chip) * num_busses_out(chip);
if ((err = snd_ctl_add(chip->card, snd_ctl_new1(&snd_echo_monitor_mixer, chip))) < 0)
goto ctl_error;
#endif
#ifdef ECHOCARD_HAS_DIGITAL_IN_AUTOMUTE
if ((err = snd_ctl_add(chip->card, snd_ctl_new1(&snd_echo_automute_switch, chip))) < 0)
goto ctl_error;
#endif
if ((err = snd_ctl_add(chip->card, snd_ctl_new1(&snd_echo_channels_info, chip))) < 0)
goto ctl_error;
#ifdef ECHOCARD_HAS_DIGITAL_MODE_SWITCH
chip->num_digital_modes = 0;
for (i = 0; i < 6; i++)
if (chip->digital_modes & (1 << i))
chip->digital_mode_list[chip->num_digital_modes++] = i;
if ((err = snd_ctl_add(chip->card, snd_ctl_new1(&snd_echo_digital_mode_switch, chip))) < 0)
goto ctl_error;
#endif
#ifdef ECHOCARD_HAS_EXTERNAL_CLOCK
chip->num_clock_sources = 0;
for (i = 0; i < 10; i++)
if (chip->input_clock_types & (1 << i))
chip->clock_source_list[chip->num_clock_sources++] = i;
if (chip->num_clock_sources > 1) {
chip->clock_src_ctl = snd_ctl_new1(&snd_echo_clock_source_switch, chip);
if ((err = snd_ctl_add(chip->card, chip->clock_src_ctl)) < 0)
goto ctl_error;
}
#endif
#ifdef ECHOCARD_HAS_DIGITAL_IO
if ((err = snd_ctl_add(chip->card, snd_ctl_new1(&snd_echo_spdif_mode_switch, chip))) < 0)
goto ctl_error;
#endif
#ifdef ECHOCARD_HAS_PHANTOM_POWER
if (chip->has_phantom_power)
if ((err = snd_ctl_add(chip->card, snd_ctl_new1(&snd_echo_phantom_power_switch, chip))) < 0)
goto ctl_error;
#endif
err = snd_card_register(card);
if (err < 0)
goto ctl_error;
snd_printk(KERN_INFO "Card registered: %s\n", card->longname);
pci_set_drvdata(pci, chip);
dev++;
return 0;
ctl_error:
snd_printk(KERN_ERR "new control error %d\n", err);
snd_card_free(card);
return err;
}
static int snd_echo_suspend(struct device *dev)
{
struct pci_dev *pci = to_pci_dev(dev);
struct echoaudio *chip = dev_get_drvdata(dev);
DE_INIT(("suspend start\n"));
snd_pcm_suspend_all(chip->analog_pcm);
snd_pcm_suspend_all(chip->digital_pcm);
#ifdef ECHOCARD_HAS_MIDI
if (chip->midi_out)
snd_echo_midi_output_trigger(chip->midi_out, 0);
#endif
spin_lock_irq(&chip->lock);
if (wait_handshake(chip)) {
spin_unlock_irq(&chip->lock);
return -EIO;
}
clear_handshake(chip);
if (send_vector(chip, DSP_VC_GO_COMATOSE) < 0) {
spin_unlock_irq(&chip->lock);
return -EIO;
}
spin_unlock_irq(&chip->lock);
chip->dsp_code = NULL;
free_irq(chip->irq, chip);
chip->irq = -1;
pci_save_state(pci);
pci_disable_device(pci);
DE_INIT(("suspend done\n"));
return 0;
}
static int snd_echo_resume(struct device *dev)
{
struct pci_dev *pci = to_pci_dev(dev);
struct echoaudio *chip = dev_get_drvdata(dev);
struct comm_page *commpage, *commpage_bak;
u32 pipe_alloc_mask;
int err;
DE_INIT(("resume start\n"));
pci_restore_state(pci);
commpage_bak = kmalloc(sizeof(struct echoaudio), GFP_KERNEL);
if (commpage_bak == NULL)
return -ENOMEM;
commpage = chip->comm_page;
memcpy(commpage_bak, commpage, sizeof(struct comm_page));
err = init_hw(chip, chip->pci->device, chip->pci->subsystem_device);
if (err < 0) {
kfree(commpage_bak);
DE_INIT(("resume init_hw err=%d\n", err));
snd_echo_free(chip);
return err;
}
DE_INIT(("resume init OK\n"));
pipe_alloc_mask = chip->pipe_alloc_mask;
chip->pipe_alloc_mask = 0;
err = restore_dsp_rettings(chip);
chip->pipe_alloc_mask = pipe_alloc_mask;
if (err < 0) {
kfree(commpage_bak);
return err;
}
DE_INIT(("resume restore OK\n"));
memcpy(&commpage->audio_format, &commpage_bak->audio_format,
sizeof(commpage->audio_format));
memcpy(&commpage->sglist_addr, &commpage_bak->sglist_addr,
sizeof(commpage->sglist_addr));
memcpy(&commpage->midi_output, &commpage_bak->midi_output,
sizeof(commpage->midi_output));
kfree(commpage_bak);
if (request_irq(pci->irq, snd_echo_interrupt, IRQF_SHARED,
KBUILD_MODNAME, chip)) {
snd_echo_free(chip);
snd_printk(KERN_ERR "cannot grab irq\n");
return -EBUSY;
}
chip->irq = pci->irq;
DE_INIT(("resume irq=%d\n", chip->irq));
#ifdef ECHOCARD_HAS_MIDI
if (chip->midi_input_enabled)
enable_midi_input(chip, TRUE);
if (chip->midi_out)
snd_echo_midi_output_trigger(chip->midi_out, 1);
#endif
DE_INIT(("resume done\n"));
return 0;
}
static void __devexit snd_echo_remove(struct pci_dev *pci)
{
struct echoaudio *chip;
chip = pci_get_drvdata(pci);
if (chip)
snd_card_free(chip->card);
pci_set_drvdata(pci, NULL);
}
