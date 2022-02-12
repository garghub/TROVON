static inline struct azx_dev *
azx_assign_device(struct azx *chip, struct snd_pcm_substream *substream)
{
struct hdac_stream *s;
s = snd_hdac_stream_assign(azx_bus(chip), substream);
if (!s)
return NULL;
return stream_to_azx_dev(s);
}
static inline void azx_release_device(struct azx_dev *azx_dev)
{
snd_hdac_stream_release(azx_stream(azx_dev));
}
static inline struct hda_pcm_stream *
to_hda_pcm_stream(struct snd_pcm_substream *substream)
{
struct azx_pcm *apcm = snd_pcm_substream_chip(substream);
return &apcm->info->stream[substream->stream];
}
static u64 azx_adjust_codec_delay(struct snd_pcm_substream *substream,
u64 nsec)
{
struct azx_pcm *apcm = snd_pcm_substream_chip(substream);
struct hda_pcm_stream *hinfo = to_hda_pcm_stream(substream);
u64 codec_frames, codec_nsecs;
if (!hinfo->ops.get_delay)
return nsec;
codec_frames = hinfo->ops.get_delay(hinfo, apcm->codec, substream);
codec_nsecs = div_u64(codec_frames * 1000000000LL,
substream->runtime->rate);
if (substream->stream == SNDRV_PCM_STREAM_CAPTURE)
return nsec + codec_nsecs;
return (nsec > codec_nsecs) ? nsec - codec_nsecs : 0;
}
static int azx_pcm_close(struct snd_pcm_substream *substream)
{
struct azx_pcm *apcm = snd_pcm_substream_chip(substream);
struct hda_pcm_stream *hinfo = to_hda_pcm_stream(substream);
struct azx *chip = apcm->chip;
struct azx_dev *azx_dev = get_azx_dev(substream);
trace_azx_pcm_close(chip, azx_dev);
mutex_lock(&chip->open_mutex);
azx_release_device(azx_dev);
if (hinfo->ops.close)
hinfo->ops.close(hinfo, apcm->codec, substream);
snd_hda_power_down(apcm->codec);
mutex_unlock(&chip->open_mutex);
snd_hda_codec_pcm_put(apcm->info);
return 0;
}
static int azx_pcm_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *hw_params)
{
struct azx_pcm *apcm = snd_pcm_substream_chip(substream);
struct azx *chip = apcm->chip;
struct azx_dev *azx_dev = get_azx_dev(substream);
int ret;
trace_azx_pcm_hw_params(chip, azx_dev);
dsp_lock(azx_dev);
if (dsp_is_locked(azx_dev)) {
ret = -EBUSY;
goto unlock;
}
azx_dev->core.bufsize = 0;
azx_dev->core.period_bytes = 0;
azx_dev->core.format_val = 0;
ret = chip->ops->substream_alloc_pages(chip, substream,
params_buffer_bytes(hw_params));
unlock:
dsp_unlock(azx_dev);
return ret;
}
static int azx_pcm_hw_free(struct snd_pcm_substream *substream)
{
struct azx_pcm *apcm = snd_pcm_substream_chip(substream);
struct azx_dev *azx_dev = get_azx_dev(substream);
struct azx *chip = apcm->chip;
struct hda_pcm_stream *hinfo = to_hda_pcm_stream(substream);
int err;
dsp_lock(azx_dev);
if (!dsp_is_locked(azx_dev))
snd_hdac_stream_cleanup(azx_stream(azx_dev));
snd_hda_codec_cleanup(apcm->codec, hinfo, substream);
err = chip->ops->substream_free_pages(chip, substream);
azx_stream(azx_dev)->prepared = 0;
dsp_unlock(azx_dev);
return err;
}
static int azx_pcm_prepare(struct snd_pcm_substream *substream)
{
struct azx_pcm *apcm = snd_pcm_substream_chip(substream);
struct azx *chip = apcm->chip;
struct azx_dev *azx_dev = get_azx_dev(substream);
struct hda_pcm_stream *hinfo = to_hda_pcm_stream(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
unsigned int format_val, stream_tag;
int err;
struct hda_spdif_out *spdif =
snd_hda_spdif_out_of_nid(apcm->codec, hinfo->nid);
unsigned short ctls = spdif ? spdif->ctls : 0;
trace_azx_pcm_prepare(chip, azx_dev);
dsp_lock(azx_dev);
if (dsp_is_locked(azx_dev)) {
err = -EBUSY;
goto unlock;
}
snd_hdac_stream_reset(azx_stream(azx_dev));
format_val = snd_hdac_calc_stream_format(runtime->rate,
runtime->channels,
runtime->format,
hinfo->maxbps,
ctls);
if (!format_val) {
dev_err(chip->card->dev,
"invalid format_val, rate=%d, ch=%d, format=%d\n",
runtime->rate, runtime->channels, runtime->format);
err = -EINVAL;
goto unlock;
}
err = snd_hdac_stream_set_params(azx_stream(azx_dev), format_val);
if (err < 0)
goto unlock;
snd_hdac_stream_setup(azx_stream(azx_dev));
stream_tag = azx_dev->core.stream_tag;
if ((chip->driver_caps & AZX_DCAPS_CTX_WORKAROUND) &&
stream_tag > chip->capture_streams)
stream_tag -= chip->capture_streams;
err = snd_hda_codec_prepare(apcm->codec, hinfo, stream_tag,
azx_dev->core.format_val, substream);
unlock:
if (!err)
azx_stream(azx_dev)->prepared = 1;
dsp_unlock(azx_dev);
return err;
}
static int azx_pcm_trigger(struct snd_pcm_substream *substream, int cmd)
{
struct azx_pcm *apcm = snd_pcm_substream_chip(substream);
struct azx *chip = apcm->chip;
struct hdac_bus *bus = azx_bus(chip);
struct azx_dev *azx_dev;
struct snd_pcm_substream *s;
struct hdac_stream *hstr;
bool start;
int sbits = 0;
int sync_reg;
azx_dev = get_azx_dev(substream);
trace_azx_pcm_trigger(chip, azx_dev, cmd);
hstr = azx_stream(azx_dev);
if (chip->driver_caps & AZX_DCAPS_OLD_SSYNC)
sync_reg = AZX_REG_OLD_SSYNC;
else
sync_reg = AZX_REG_SSYNC;
if (dsp_is_locked(azx_dev) || !hstr->prepared)
return -EPIPE;
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
case SNDRV_PCM_TRIGGER_RESUME:
start = true;
break;
case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
case SNDRV_PCM_TRIGGER_SUSPEND:
case SNDRV_PCM_TRIGGER_STOP:
start = false;
break;
default:
return -EINVAL;
}
snd_pcm_group_for_each_entry(s, substream) {
if (s->pcm->card != substream->pcm->card)
continue;
azx_dev = get_azx_dev(s);
sbits |= 1 << azx_dev->core.index;
snd_pcm_trigger_done(s, substream);
}
spin_lock(&bus->reg_lock);
snd_hdac_stream_sync_trigger(hstr, true, sbits, sync_reg);
snd_pcm_group_for_each_entry(s, substream) {
if (s->pcm->card != substream->pcm->card)
continue;
azx_dev = get_azx_dev(s);
if (start) {
azx_dev->insufficient = 1;
snd_hdac_stream_start(azx_stream(azx_dev), true);
} else {
snd_hdac_stream_stop(azx_stream(azx_dev));
}
}
spin_unlock(&bus->reg_lock);
snd_hdac_stream_sync(hstr, start, sbits);
spin_lock(&bus->reg_lock);
snd_hdac_stream_sync_trigger(hstr, false, sbits, sync_reg);
if (start)
snd_hdac_stream_timecounter_init(hstr, sbits);
spin_unlock(&bus->reg_lock);
return 0;
}
unsigned int azx_get_pos_lpib(struct azx *chip, struct azx_dev *azx_dev)
{
return snd_hdac_stream_get_pos_lpib(azx_stream(azx_dev));
}
unsigned int azx_get_pos_posbuf(struct azx *chip, struct azx_dev *azx_dev)
{
return snd_hdac_stream_get_pos_posbuf(azx_stream(azx_dev));
}
unsigned int azx_get_position(struct azx *chip,
struct azx_dev *azx_dev)
{
struct snd_pcm_substream *substream = azx_dev->core.substream;
unsigned int pos;
int stream = substream->stream;
int delay = 0;
if (chip->get_position[stream])
pos = chip->get_position[stream](chip, azx_dev);
else
pos = azx_get_pos_posbuf(chip, azx_dev);
if (pos >= azx_dev->core.bufsize)
pos = 0;
if (substream->runtime) {
struct azx_pcm *apcm = snd_pcm_substream_chip(substream);
struct hda_pcm_stream *hinfo = to_hda_pcm_stream(substream);
if (chip->get_delay[stream])
delay += chip->get_delay[stream](chip, azx_dev, pos);
if (hinfo->ops.get_delay)
delay += hinfo->ops.get_delay(hinfo, apcm->codec,
substream);
substream->runtime->delay = delay;
}
trace_azx_get_position(chip, azx_dev, pos, delay);
return pos;
}
static snd_pcm_uframes_t azx_pcm_pointer(struct snd_pcm_substream *substream)
{
struct azx_pcm *apcm = snd_pcm_substream_chip(substream);
struct azx *chip = apcm->chip;
struct azx_dev *azx_dev = get_azx_dev(substream);
return bytes_to_frames(substream->runtime,
azx_get_position(chip, azx_dev));
}
static u64 azx_scale64(u64 base, u32 num, u32 den)
{
u64 rem;
rem = do_div(base, den);
base *= num;
rem *= num;
do_div(rem, den);
return base + rem;
}
static int azx_get_sync_time(ktime_t *device,
struct system_counterval_t *system, void *ctx)
{
struct snd_pcm_substream *substream = ctx;
struct azx_dev *azx_dev = get_azx_dev(substream);
struct azx_pcm *apcm = snd_pcm_substream_chip(substream);
struct azx *chip = apcm->chip;
struct snd_pcm_runtime *runtime;
u64 ll_counter, ll_counter_l, ll_counter_h;
u64 tsc_counter, tsc_counter_l, tsc_counter_h;
u32 wallclk_ctr, wallclk_cycles;
bool direction;
u32 dma_select;
u32 timeout = 200;
u32 retry_count = 0;
runtime = substream->runtime;
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
direction = 1;
else
direction = 0;
do {
timeout = 100;
dma_select = (direction << GTSCC_CDMAS_DMA_DIR_SHIFT) |
(azx_dev->core.stream_tag - 1);
snd_hdac_chip_writel(azx_bus(chip), GTSCC, dma_select);
snd_hdac_chip_updatel(azx_bus(chip), GTSCC, 0, GTSCC_TSCCI_MASK);
while (timeout) {
if (snd_hdac_chip_readl(azx_bus(chip), GTSCC) &
GTSCC_TSCCD_MASK)
break;
timeout--;
}
if (!timeout) {
dev_err(chip->card->dev, "GTSCC capture Timedout!\n");
return -EIO;
}
wallclk_ctr = snd_hdac_chip_readl(azx_bus(chip), WALFCC);
tsc_counter_l = snd_hdac_chip_readl(azx_bus(chip), TSCCL);
tsc_counter_h = snd_hdac_chip_readl(azx_bus(chip), TSCCU);
ll_counter_l = snd_hdac_chip_readl(azx_bus(chip), LLPCL);
ll_counter_h = snd_hdac_chip_readl(azx_bus(chip), LLPCU);
snd_hdac_chip_writel(azx_bus(chip), GTSCC, GTSCC_TSCCD_SHIFT);
tsc_counter = (tsc_counter_h << TSCCU_CCU_SHIFT) |
tsc_counter_l;
ll_counter = (ll_counter_h << LLPC_CCU_SHIFT) | ll_counter_l;
wallclk_cycles = wallclk_ctr & WALFCC_CIF_MASK;
if (wallclk_cycles < HDA_MAX_CYCLE_VALUE - HDA_MAX_CYCLE_OFFSET
&& wallclk_cycles > HDA_MAX_CYCLE_OFFSET)
break;
udelay(retry_count++);
} while (retry_count != HDA_MAX_CYCLE_READ_RETRY);
if (retry_count == HDA_MAX_CYCLE_READ_RETRY) {
dev_err_ratelimited(chip->card->dev,
"Error in WALFCC cycle count\n");
return -EIO;
}
*device = ns_to_ktime(azx_scale64(ll_counter,
NSEC_PER_SEC, runtime->rate));
*device = ktime_add_ns(*device, (wallclk_cycles * NSEC_PER_SEC) /
((HDA_MAX_CYCLE_VALUE + 1) * runtime->rate));
*system = convert_art_to_tsc(tsc_counter);
return 0;
}
static int azx_get_sync_time(ktime_t *device,
struct system_counterval_t *system, void *ctx)
{
return -ENXIO;
}
static int azx_get_crosststamp(struct snd_pcm_substream *substream,
struct system_device_crosststamp *xtstamp)
{
return get_device_system_crosststamp(azx_get_sync_time,
substream, NULL, xtstamp);
}
static inline bool is_link_time_supported(struct snd_pcm_runtime *runtime,
struct snd_pcm_audio_tstamp_config *ts)
{
if (runtime->hw.info & SNDRV_PCM_INFO_HAS_LINK_SYNCHRONIZED_ATIME)
if (ts->type_requested == SNDRV_PCM_AUDIO_TSTAMP_TYPE_LINK_SYNCHRONIZED)
return true;
return false;
}
static int azx_get_time_info(struct snd_pcm_substream *substream,
struct timespec *system_ts, struct timespec *audio_ts,
struct snd_pcm_audio_tstamp_config *audio_tstamp_config,
struct snd_pcm_audio_tstamp_report *audio_tstamp_report)
{
struct azx_dev *azx_dev = get_azx_dev(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
struct system_device_crosststamp xtstamp;
int ret;
u64 nsec;
if ((substream->runtime->hw.info & SNDRV_PCM_INFO_HAS_LINK_ATIME) &&
(audio_tstamp_config->type_requested == SNDRV_PCM_AUDIO_TSTAMP_TYPE_LINK)) {
snd_pcm_gettime(substream->runtime, system_ts);
nsec = timecounter_read(&azx_dev->core.tc);
nsec = div_u64(nsec, 3);
if (audio_tstamp_config->report_delay)
nsec = azx_adjust_codec_delay(substream, nsec);
*audio_ts = ns_to_timespec(nsec);
audio_tstamp_report->actual_type = SNDRV_PCM_AUDIO_TSTAMP_TYPE_LINK;
audio_tstamp_report->accuracy_report = 1;
audio_tstamp_report->accuracy = 42;
} else if (is_link_time_supported(runtime, audio_tstamp_config)) {
ret = azx_get_crosststamp(substream, &xtstamp);
if (ret)
return ret;
switch (runtime->tstamp_type) {
case SNDRV_PCM_TSTAMP_TYPE_MONOTONIC:
return -EINVAL;
case SNDRV_PCM_TSTAMP_TYPE_MONOTONIC_RAW:
*system_ts = ktime_to_timespec(xtstamp.sys_monoraw);
break;
default:
*system_ts = ktime_to_timespec(xtstamp.sys_realtime);
break;
}
*audio_ts = ktime_to_timespec(xtstamp.device);
audio_tstamp_report->actual_type =
SNDRV_PCM_AUDIO_TSTAMP_TYPE_LINK_SYNCHRONIZED;
audio_tstamp_report->accuracy_report = 1;
audio_tstamp_report->accuracy = 42;
} else {
audio_tstamp_report->actual_type = SNDRV_PCM_AUDIO_TSTAMP_TYPE_DEFAULT;
}
return 0;
}
static int azx_pcm_open(struct snd_pcm_substream *substream)
{
struct azx_pcm *apcm = snd_pcm_substream_chip(substream);
struct hda_pcm_stream *hinfo = to_hda_pcm_stream(substream);
struct azx *chip = apcm->chip;
struct azx_dev *azx_dev;
struct snd_pcm_runtime *runtime = substream->runtime;
int err;
int buff_step;
snd_hda_codec_pcm_get(apcm->info);
mutex_lock(&chip->open_mutex);
azx_dev = azx_assign_device(chip, substream);
trace_azx_pcm_open(chip, azx_dev);
if (azx_dev == NULL) {
err = -EBUSY;
goto unlock;
}
runtime->private_data = azx_dev;
if (chip->gts_present)
azx_pcm_hw.info = azx_pcm_hw.info |
SNDRV_PCM_INFO_HAS_LINK_SYNCHRONIZED_ATIME;
runtime->hw = azx_pcm_hw;
runtime->hw.channels_min = hinfo->channels_min;
runtime->hw.channels_max = hinfo->channels_max;
runtime->hw.formats = hinfo->formats;
runtime->hw.rates = hinfo->rates;
snd_pcm_limit_hw_rates(runtime);
snd_pcm_hw_constraint_integer(runtime, SNDRV_PCM_HW_PARAM_PERIODS);
snd_pcm_hw_constraint_minmax(runtime, SNDRV_PCM_HW_PARAM_BUFFER_TIME,
20,
178000000);
if (chip->align_buffer_size)
buff_step = 128;
else
buff_step = 4;
snd_pcm_hw_constraint_step(runtime, 0, SNDRV_PCM_HW_PARAM_BUFFER_BYTES,
buff_step);
snd_pcm_hw_constraint_step(runtime, 0, SNDRV_PCM_HW_PARAM_PERIOD_BYTES,
buff_step);
snd_hda_power_up(apcm->codec);
if (hinfo->ops.open)
err = hinfo->ops.open(hinfo, apcm->codec, substream);
else
err = -ENODEV;
if (err < 0) {
azx_release_device(azx_dev);
goto powerdown;
}
snd_pcm_limit_hw_rates(runtime);
if (snd_BUG_ON(!runtime->hw.channels_min) ||
snd_BUG_ON(!runtime->hw.channels_max) ||
snd_BUG_ON(!runtime->hw.formats) ||
snd_BUG_ON(!runtime->hw.rates)) {
azx_release_device(azx_dev);
if (hinfo->ops.close)
hinfo->ops.close(hinfo, apcm->codec, substream);
err = -EINVAL;
goto powerdown;
}
if (substream->stream == SNDRV_PCM_STREAM_CAPTURE) {
runtime->hw.info &= ~SNDRV_PCM_INFO_HAS_WALL_CLOCK;
runtime->hw.info &= ~SNDRV_PCM_INFO_HAS_LINK_ATIME;
}
snd_pcm_set_sync(substream);
mutex_unlock(&chip->open_mutex);
return 0;
powerdown:
snd_hda_power_down(apcm->codec);
unlock:
mutex_unlock(&chip->open_mutex);
snd_hda_codec_pcm_put(apcm->info);
return err;
}
static int azx_pcm_mmap(struct snd_pcm_substream *substream,
struct vm_area_struct *area)
{
struct azx_pcm *apcm = snd_pcm_substream_chip(substream);
struct azx *chip = apcm->chip;
if (chip->ops->pcm_mmap_prepare)
chip->ops->pcm_mmap_prepare(substream, area);
return snd_pcm_lib_default_mmap(substream, area);
}
static void azx_pcm_free(struct snd_pcm *pcm)
{
struct azx_pcm *apcm = pcm->private_data;
if (apcm) {
list_del(&apcm->list);
apcm->info->pcm = NULL;
kfree(apcm);
}
}
int snd_hda_attach_pcm_stream(struct hda_bus *_bus, struct hda_codec *codec,
struct hda_pcm *cpcm)
{
struct hdac_bus *bus = &_bus->core;
struct azx *chip = bus_to_azx(bus);
struct snd_pcm *pcm;
struct azx_pcm *apcm;
int pcm_dev = cpcm->device;
unsigned int size;
int s, err;
list_for_each_entry(apcm, &chip->pcm_list, list) {
if (apcm->pcm->device == pcm_dev) {
dev_err(chip->card->dev, "PCM %d already exists\n",
pcm_dev);
return -EBUSY;
}
}
err = snd_pcm_new(chip->card, cpcm->name, pcm_dev,
cpcm->stream[SNDRV_PCM_STREAM_PLAYBACK].substreams,
cpcm->stream[SNDRV_PCM_STREAM_CAPTURE].substreams,
&pcm);
if (err < 0)
return err;
strlcpy(pcm->name, cpcm->name, sizeof(pcm->name));
apcm = kzalloc(sizeof(*apcm), GFP_KERNEL);
if (apcm == NULL)
return -ENOMEM;
apcm->chip = chip;
apcm->pcm = pcm;
apcm->codec = codec;
apcm->info = cpcm;
pcm->private_data = apcm;
pcm->private_free = azx_pcm_free;
if (cpcm->pcm_type == HDA_PCM_TYPE_MODEM)
pcm->dev_class = SNDRV_PCM_CLASS_MODEM;
list_add_tail(&apcm->list, &chip->pcm_list);
cpcm->pcm = pcm;
for (s = 0; s < 2; s++) {
if (cpcm->stream[s].substreams)
snd_pcm_set_ops(pcm, s, &azx_pcm_ops);
}
size = CONFIG_SND_HDA_PREALLOC_SIZE * 1024;
if (size > MAX_PREALLOC_SIZE)
size = MAX_PREALLOC_SIZE;
snd_pcm_lib_preallocate_pages_for_all(pcm, SNDRV_DMA_TYPE_DEV_SG,
chip->card->dev,
size, MAX_PREALLOC_SIZE);
return 0;
}
static unsigned int azx_command_addr(u32 cmd)
{
unsigned int addr = cmd >> 28;
if (addr >= AZX_MAX_CODECS) {
snd_BUG();
addr = 0;
}
return addr;
}
static int azx_rirb_get_response(struct hdac_bus *bus, unsigned int addr,
unsigned int *res)
{
struct azx *chip = bus_to_azx(bus);
struct hda_bus *hbus = &chip->bus;
unsigned long timeout;
unsigned long loopcounter;
int do_poll = 0;
again:
timeout = jiffies + msecs_to_jiffies(1000);
for (loopcounter = 0;; loopcounter++) {
spin_lock_irq(&bus->reg_lock);
if (chip->polling_mode || do_poll)
snd_hdac_bus_update_rirb(bus);
if (!bus->rirb.cmds[addr]) {
if (!do_poll)
chip->poll_count = 0;
if (res)
*res = bus->rirb.res[addr];
spin_unlock_irq(&bus->reg_lock);
return 0;
}
spin_unlock_irq(&bus->reg_lock);
if (time_after(jiffies, timeout))
break;
if (hbus->needs_damn_long_delay || loopcounter > 3000)
msleep(2);
else {
udelay(10);
cond_resched();
}
}
if (hbus->no_response_fallback)
return -EIO;
if (!chip->polling_mode && chip->poll_count < 2) {
dev_dbg(chip->card->dev,
"azx_get_response timeout, polling the codec once: last cmd=0x%08x\n",
bus->last_cmd[addr]);
do_poll = 1;
chip->poll_count++;
goto again;
}
if (!chip->polling_mode) {
dev_warn(chip->card->dev,
"azx_get_response timeout, switching to polling mode: last cmd=0x%08x\n",
bus->last_cmd[addr]);
chip->polling_mode = 1;
goto again;
}
if (chip->msi) {
dev_warn(chip->card->dev,
"No response from codec, disabling MSI: last cmd=0x%08x\n",
bus->last_cmd[addr]);
if (chip->ops->disable_msi_reset_irq &&
chip->ops->disable_msi_reset_irq(chip) < 0)
return -EIO;
goto again;
}
if (chip->probing) {
return -EIO;
}
if (!chip->fallback_to_single_cmd)
return -EIO;
if (hbus->allow_bus_reset && !hbus->response_reset && !hbus->in_reset) {
hbus->response_reset = 1;
return -EAGAIN;
}
dev_err(chip->card->dev,
"azx_get_response timeout, switching to single_cmd mode: last cmd=0x%08x\n",
bus->last_cmd[addr]);
chip->single_cmd = 1;
hbus->response_reset = 0;
snd_hdac_bus_stop_cmd_io(bus);
return -EIO;
}
static int azx_single_wait_for_response(struct azx *chip, unsigned int addr)
{
int timeout = 50;
while (timeout--) {
if (azx_readw(chip, IRS) & AZX_IRS_VALID) {
azx_bus(chip)->rirb.res[addr] = azx_readl(chip, IR);
return 0;
}
udelay(1);
}
if (printk_ratelimit())
dev_dbg(chip->card->dev, "get_response timeout: IRS=0x%x\n",
azx_readw(chip, IRS));
azx_bus(chip)->rirb.res[addr] = -1;
return -EIO;
}
static int azx_single_send_cmd(struct hdac_bus *bus, u32 val)
{
struct azx *chip = bus_to_azx(bus);
unsigned int addr = azx_command_addr(val);
int timeout = 50;
bus->last_cmd[azx_command_addr(val)] = val;
while (timeout--) {
if (!((azx_readw(chip, IRS) & AZX_IRS_BUSY))) {
azx_writew(chip, IRS, azx_readw(chip, IRS) |
AZX_IRS_VALID);
azx_writel(chip, IC, val);
azx_writew(chip, IRS, azx_readw(chip, IRS) |
AZX_IRS_BUSY);
return azx_single_wait_for_response(chip, addr);
}
udelay(1);
}
if (printk_ratelimit())
dev_dbg(chip->card->dev,
"send_cmd timeout: IRS=0x%x, val=0x%x\n",
azx_readw(chip, IRS), val);
return -EIO;
}
static int azx_single_get_response(struct hdac_bus *bus, unsigned int addr,
unsigned int *res)
{
if (res)
*res = bus->rirb.res[addr];
return 0;
}
static int azx_send_cmd(struct hdac_bus *bus, unsigned int val)
{
struct azx *chip = bus_to_azx(bus);
if (chip->disabled)
return 0;
if (chip->single_cmd)
return azx_single_send_cmd(bus, val);
else
return snd_hdac_bus_send_cmd(bus, val);
}
static int azx_get_response(struct hdac_bus *bus, unsigned int addr,
unsigned int *res)
{
struct azx *chip = bus_to_azx(bus);
if (chip->disabled)
return 0;
if (chip->single_cmd)
return azx_single_get_response(bus, addr, res);
else
return azx_rirb_get_response(bus, addr, res);
}
static int azx_link_power(struct hdac_bus *bus, bool enable)
{
struct azx *chip = bus_to_azx(bus);
if (chip->ops->link_power)
return chip->ops->link_power(chip, enable);
else
return -EINVAL;
}
static struct azx_dev *
azx_get_dsp_loader_dev(struct azx *chip)
{
struct hdac_bus *bus = azx_bus(chip);
struct hdac_stream *s;
list_for_each_entry(s, &bus->stream_list, list)
if (s->index == chip->playback_index_offset)
return stream_to_azx_dev(s);
return NULL;
}
int snd_hda_codec_load_dsp_prepare(struct hda_codec *codec, unsigned int format,
unsigned int byte_size,
struct snd_dma_buffer *bufp)
{
struct hdac_bus *bus = &codec->bus->core;
struct azx *chip = bus_to_azx(bus);
struct azx_dev *azx_dev;
struct hdac_stream *hstr;
bool saved = false;
int err;
azx_dev = azx_get_dsp_loader_dev(chip);
hstr = azx_stream(azx_dev);
spin_lock_irq(&bus->reg_lock);
if (hstr->opened) {
chip->saved_azx_dev = *azx_dev;
saved = true;
}
spin_unlock_irq(&bus->reg_lock);
err = snd_hdac_dsp_prepare(hstr, format, byte_size, bufp);
if (err < 0) {
spin_lock_irq(&bus->reg_lock);
if (saved)
*azx_dev = chip->saved_azx_dev;
spin_unlock_irq(&bus->reg_lock);
return err;
}
hstr->prepared = 0;
return err;
}
void snd_hda_codec_load_dsp_trigger(struct hda_codec *codec, bool start)
{
struct hdac_bus *bus = &codec->bus->core;
struct azx *chip = bus_to_azx(bus);
struct azx_dev *azx_dev = azx_get_dsp_loader_dev(chip);
snd_hdac_dsp_trigger(azx_stream(azx_dev), start);
}
void snd_hda_codec_load_dsp_cleanup(struct hda_codec *codec,
struct snd_dma_buffer *dmab)
{
struct hdac_bus *bus = &codec->bus->core;
struct azx *chip = bus_to_azx(bus);
struct azx_dev *azx_dev = azx_get_dsp_loader_dev(chip);
struct hdac_stream *hstr = azx_stream(azx_dev);
if (!dmab->area || !hstr->locked)
return;
snd_hdac_dsp_cleanup(hstr, dmab);
spin_lock_irq(&bus->reg_lock);
if (hstr->opened)
*azx_dev = chip->saved_azx_dev;
hstr->locked = false;
spin_unlock_irq(&bus->reg_lock);
}
void azx_init_chip(struct azx *chip, bool full_reset)
{
if (snd_hdac_bus_init_chip(azx_bus(chip), full_reset)) {
if (chip->driver_caps & AZX_DCAPS_CTX_WORKAROUND)
azx_writew(chip, RINTCNT, 0xc0);
}
}
void azx_stop_all_streams(struct azx *chip)
{
struct hdac_bus *bus = azx_bus(chip);
struct hdac_stream *s;
list_for_each_entry(s, &bus->stream_list, list)
snd_hdac_stream_stop(s);
}
void azx_stop_chip(struct azx *chip)
{
snd_hdac_bus_stop_chip(azx_bus(chip));
}
static void stream_update(struct hdac_bus *bus, struct hdac_stream *s)
{
struct azx *chip = bus_to_azx(bus);
struct azx_dev *azx_dev = stream_to_azx_dev(s);
if (!chip->ops->position_check ||
chip->ops->position_check(chip, azx_dev)) {
spin_unlock(&bus->reg_lock);
snd_pcm_period_elapsed(azx_stream(azx_dev)->substream);
spin_lock(&bus->reg_lock);
}
}
irqreturn_t azx_interrupt(int irq, void *dev_id)
{
struct azx *chip = dev_id;
struct hdac_bus *bus = azx_bus(chip);
u32 status;
bool active, handled = false;
int repeat = 0;
#ifdef CONFIG_PM
if (azx_has_pm_runtime(chip))
if (!pm_runtime_active(chip->card->dev))
return IRQ_NONE;
#endif
spin_lock(&bus->reg_lock);
if (chip->disabled)
goto unlock;
do {
status = azx_readl(chip, INTSTS);
if (status == 0 || status == 0xffffffff)
break;
handled = true;
active = false;
if (snd_hdac_bus_handle_stream_irq(bus, status, stream_update))
active = true;
status = azx_readb(chip, RIRBSTS);
if (status & RIRB_INT_MASK) {
active = true;
if (status & RIRB_INT_RESPONSE) {
if (chip->driver_caps & AZX_DCAPS_CTX_WORKAROUND)
udelay(80);
snd_hdac_bus_update_rirb(bus);
}
azx_writeb(chip, RIRBSTS, RIRB_INT_MASK);
}
} while (active && ++repeat < 10);
unlock:
spin_unlock(&bus->reg_lock);
return IRQ_RETVAL(handled);
}
static int probe_codec(struct azx *chip, int addr)
{
unsigned int cmd = (addr << 28) | (AC_NODE_ROOT << 20) |
(AC_VERB_PARAMETERS << 8) | AC_PAR_VENDOR_ID;
struct hdac_bus *bus = azx_bus(chip);
int err;
unsigned int res = -1;
mutex_lock(&bus->cmd_mutex);
chip->probing = 1;
azx_send_cmd(bus, cmd);
err = azx_get_response(bus, addr, &res);
chip->probing = 0;
mutex_unlock(&bus->cmd_mutex);
if (err < 0 || res == -1)
return -EIO;
dev_dbg(chip->card->dev, "codec #%d probed OK\n", addr);
return 0;
}
void snd_hda_bus_reset(struct hda_bus *bus)
{
struct azx *chip = bus_to_azx(&bus->core);
bus->in_reset = 1;
azx_stop_chip(chip);
azx_init_chip(chip, true);
if (bus->core.chip_init)
snd_hda_bus_reset_codecs(bus);
bus->in_reset = 0;
}
static int get_jackpoll_interval(struct azx *chip)
{
int i;
unsigned int j;
if (!chip->jackpoll_ms)
return 0;
i = chip->jackpoll_ms[chip->dev_index];
if (i == 0)
return 0;
if (i < 50 || i > 60000)
j = 0;
else
j = msecs_to_jiffies(i);
if (j == 0)
dev_warn(chip->card->dev,
"jackpoll_ms value out of range: %d\n", i);
return j;
}
int azx_bus_init(struct azx *chip, const char *model,
const struct hdac_io_ops *io_ops)
{
struct hda_bus *bus = &chip->bus;
int err;
err = snd_hdac_bus_init(&bus->core, chip->card->dev, &bus_core_ops,
io_ops);
if (err < 0)
return err;
bus->card = chip->card;
mutex_init(&bus->prepare_mutex);
bus->pci = chip->pci;
bus->modelname = model;
bus->mixer_assigned = -1;
bus->core.snoop = azx_snoop(chip);
if (chip->get_position[0] != azx_get_pos_lpib ||
chip->get_position[1] != azx_get_pos_lpib)
bus->core.use_posbuf = true;
bus->core.bdl_pos_adj = chip->bdl_pos_adj;
if (chip->driver_caps & AZX_DCAPS_CORBRP_SELF_CLEAR)
bus->core.corbrp_self_clear = true;
if (chip->driver_caps & AZX_DCAPS_4K_BDLE_BOUNDARY)
bus->core.align_bdle_4k = true;
if (chip->driver_caps & AZX_DCAPS_SYNC_WRITE) {
dev_dbg(chip->card->dev, "Enable sync_write for stable communication\n");
bus->core.sync_write = 1;
bus->allow_bus_reset = 1;
}
return 0;
}
int azx_probe_codecs(struct azx *chip, unsigned int max_slots)
{
struct hdac_bus *bus = azx_bus(chip);
int c, codecs, err;
codecs = 0;
if (!max_slots)
max_slots = AZX_DEFAULT_CODECS;
for (c = 0; c < max_slots; c++) {
if ((bus->codec_mask & (1 << c)) & chip->codec_probe_mask) {
if (probe_codec(chip, c) < 0) {
dev_warn(chip->card->dev,
"Codec #%d probe error; disabling it...\n", c);
bus->codec_mask &= ~(1 << c);
azx_stop_chip(chip);
azx_init_chip(chip, true);
}
}
}
for (c = 0; c < max_slots; c++) {
if ((bus->codec_mask & (1 << c)) & chip->codec_probe_mask) {
struct hda_codec *codec;
err = snd_hda_codec_new(&chip->bus, chip->card, c, &codec);
if (err < 0)
continue;
codec->jackpoll_interval = get_jackpoll_interval(chip);
codec->beep_mode = chip->beep_mode;
codecs++;
}
}
if (!codecs) {
dev_err(chip->card->dev, "no codecs initialized\n");
return -ENXIO;
}
return 0;
}
int azx_codec_configure(struct azx *chip)
{
struct hda_codec *codec, *next;
list_for_each_codec_safe(codec, next, &chip->bus) {
snd_hda_codec_configure(codec);
}
return 0;
}
static int stream_direction(struct azx *chip, unsigned char index)
{
if (index >= chip->capture_index_offset &&
index < chip->capture_index_offset + chip->capture_streams)
return SNDRV_PCM_STREAM_CAPTURE;
return SNDRV_PCM_STREAM_PLAYBACK;
}
int azx_init_streams(struct azx *chip)
{
int i;
int stream_tags[2] = { 0, 0 };
for (i = 0; i < chip->num_streams; i++) {
struct azx_dev *azx_dev = kzalloc(sizeof(*azx_dev), GFP_KERNEL);
int dir, tag;
if (!azx_dev)
return -ENOMEM;
dir = stream_direction(chip, i);
if (chip->driver_caps & AZX_DCAPS_SEPARATE_STREAM_TAG)
tag = ++stream_tags[dir];
else
tag = i + 1;
snd_hdac_stream_init(azx_bus(chip), azx_stream(azx_dev),
i, dir, tag);
}
return 0;
}
void azx_free_streams(struct azx *chip)
{
struct hdac_bus *bus = azx_bus(chip);
struct hdac_stream *s;
while (!list_empty(&bus->stream_list)) {
s = list_first_entry(&bus->stream_list, struct hdac_stream, list);
list_del(&s->list);
kfree(stream_to_azx_dev(s));
}
}
