int free_stream_context(struct intel_sst_drv *ctx, unsigned int str_id)
{
struct stream_info *stream;
int ret = 0;
stream = get_stream_info(ctx, str_id);
if (stream) {
ret = sst_free_stream(ctx, str_id);
if (ret)
sst_clean_stream(&ctx->streams[str_id]);
return ret;
} else {
dev_err(ctx->dev, "we tried to free stream context %d which was freed!!!\n", str_id);
}
return ret;
}
int sst_get_stream_allocated(struct intel_sst_drv *ctx,
struct snd_sst_params *str_param,
struct snd_sst_lib_download **lib_dnld)
{
int retval;
retval = ctx->ops->alloc_stream(ctx, str_param);
if (retval > 0)
dev_dbg(ctx->dev, "Stream allocated %d\n", retval);
return retval;
}
int sst_get_sfreq(struct snd_sst_params *str_param)
{
switch (str_param->codec) {
case SST_CODEC_TYPE_PCM:
return str_param->sparams.uc.pcm_params.sfreq;
case SST_CODEC_TYPE_AAC:
return str_param->sparams.uc.aac_params.externalsr;
case SST_CODEC_TYPE_MP3:
return 0;
default:
return -EINVAL;
}
}
int sst_get_num_channel(struct snd_sst_params *str_param)
{
switch (str_param->codec) {
case SST_CODEC_TYPE_PCM:
return str_param->sparams.uc.pcm_params.num_chan;
case SST_CODEC_TYPE_MP3:
return str_param->sparams.uc.mp3_params.num_chan;
case SST_CODEC_TYPE_AAC:
return str_param->sparams.uc.aac_params.num_chan;
default:
return -EINVAL;
}
}
int sst_get_stream(struct intel_sst_drv *ctx,
struct snd_sst_params *str_param)
{
int retval;
struct stream_info *str_info;
retval = ctx->ops->alloc_stream(ctx, str_param);
if (retval <= 0) {
return -EIO;
}
str_info = &ctx->streams[retval];
str_info->sfreq = sst_get_sfreq(str_param);
return retval;
}
static int sst_power_control(struct device *dev, bool state)
{
struct intel_sst_drv *ctx = dev_get_drvdata(dev);
dev_dbg(ctx->dev, "state:%d", state);
if (state == true)
return pm_runtime_get_sync(dev);
else
return sst_pm_runtime_put(ctx);
}
static int sst_open_pcm_stream(struct device *dev,
struct snd_sst_params *str_param)
{
int retval;
struct intel_sst_drv *ctx = dev_get_drvdata(dev);
if (!str_param)
return -EINVAL;
retval = sst_get_stream(ctx, str_param);
if (retval > 0)
ctx->stream_cnt++;
else
dev_err(ctx->dev, "sst_get_stream returned err %d\n", retval);
return retval;
}
static int sst_cdev_open(struct device *dev,
struct snd_sst_params *str_params, struct sst_compress_cb *cb)
{
int str_id, retval;
struct stream_info *stream;
struct intel_sst_drv *ctx = dev_get_drvdata(dev);
retval = pm_runtime_get_sync(ctx->dev);
if (retval < 0)
return retval;
str_id = sst_get_stream(ctx, str_params);
if (str_id > 0) {
dev_dbg(dev, "stream allocated in sst_cdev_open %d\n", str_id);
stream = &ctx->streams[str_id];
stream->compr_cb = cb->compr_cb;
stream->compr_cb_param = cb->param;
stream->drain_notify = cb->drain_notify;
stream->drain_cb_param = cb->drain_cb_param;
} else {
dev_err(dev, "stream encountered error during alloc %d\n", str_id);
str_id = -EINVAL;
sst_pm_runtime_put(ctx);
}
return str_id;
}
static int sst_cdev_close(struct device *dev, unsigned int str_id)
{
int retval;
struct stream_info *stream;
struct intel_sst_drv *ctx = dev_get_drvdata(dev);
stream = get_stream_info(ctx, str_id);
if (!stream) {
dev_err(dev, "stream info is NULL for str %d!!!\n", str_id);
return -EINVAL;
}
if (stream->status == STREAM_RESET) {
dev_dbg(dev, "stream in reset state...\n");
stream->status = STREAM_UN_INIT;
retval = 0;
goto put;
}
retval = sst_free_stream(ctx, str_id);
put:
stream->compr_cb_param = NULL;
stream->compr_cb = NULL;
if (retval)
dev_err(dev, "free stream returned err %d\n", retval);
dev_dbg(dev, "End\n");
return retval;
}
static int sst_cdev_ack(struct device *dev, unsigned int str_id,
unsigned long bytes)
{
struct stream_info *stream;
struct snd_sst_tstamp fw_tstamp = {0,};
int offset;
void __iomem *addr;
struct intel_sst_drv *ctx = dev_get_drvdata(dev);
stream = get_stream_info(ctx, str_id);
if (!stream)
return -EINVAL;
stream->cumm_bytes += bytes;
dev_dbg(dev, "bytes copied %d inc by %ld\n", stream->cumm_bytes, bytes);
memcpy_fromio(&fw_tstamp,
((void *)(ctx->mailbox + ctx->tstamp)
+(str_id * sizeof(fw_tstamp))),
sizeof(fw_tstamp));
fw_tstamp.bytes_copied = stream->cumm_bytes;
dev_dbg(dev, "bytes sent to fw %llu inc by %ld\n",
fw_tstamp.bytes_copied, bytes);
addr = ((void *)(ctx->mailbox + ctx->tstamp)) +
(str_id * sizeof(fw_tstamp));
offset = offsetof(struct snd_sst_tstamp, bytes_copied);
sst_shim_write(addr, offset, fw_tstamp.bytes_copied);
return 0;
}
static int sst_cdev_set_metadata(struct device *dev,
unsigned int str_id, struct snd_compr_metadata *metadata)
{
int retval = 0;
struct stream_info *str_info;
struct intel_sst_drv *ctx = dev_get_drvdata(dev);
dev_dbg(dev, "set metadata for stream %d\n", str_id);
str_info = get_stream_info(ctx, str_id);
if (!str_info)
return -EINVAL;
dev_dbg(dev, "pipe id = %d\n", str_info->pipe_id);
retval = sst_prepare_and_post_msg(ctx, str_info->task_id, IPC_CMD,
IPC_IA_SET_STREAM_PARAMS_MRFLD, str_info->pipe_id,
sizeof(*metadata), metadata, NULL,
true, true, true, false);
return retval;
}
static int sst_cdev_stream_pause(struct device *dev, unsigned int str_id)
{
struct intel_sst_drv *ctx = dev_get_drvdata(dev);
return sst_pause_stream(ctx, str_id);
}
static int sst_cdev_stream_pause_release(struct device *dev,
unsigned int str_id)
{
struct intel_sst_drv *ctx = dev_get_drvdata(dev);
return sst_resume_stream(ctx, str_id);
}
static int sst_cdev_stream_start(struct device *dev, unsigned int str_id)
{
struct stream_info *str_info;
struct intel_sst_drv *ctx = dev_get_drvdata(dev);
str_info = get_stream_info(ctx, str_id);
if (!str_info)
return -EINVAL;
str_info->prev = str_info->status;
str_info->status = STREAM_RUNNING;
return sst_start_stream(ctx, str_id);
}
static int sst_cdev_stream_drop(struct device *dev, unsigned int str_id)
{
struct intel_sst_drv *ctx = dev_get_drvdata(dev);
return sst_drop_stream(ctx, str_id);
}
static int sst_cdev_stream_drain(struct device *dev, unsigned int str_id)
{
struct intel_sst_drv *ctx = dev_get_drvdata(dev);
return sst_drain_stream(ctx, str_id, false);
}
static int sst_cdev_stream_partial_drain(struct device *dev,
unsigned int str_id)
{
struct intel_sst_drv *ctx = dev_get_drvdata(dev);
return sst_drain_stream(ctx, str_id, true);
}
static int sst_cdev_tstamp(struct device *dev, unsigned int str_id,
struct snd_compr_tstamp *tstamp)
{
struct snd_sst_tstamp fw_tstamp = {0,};
struct stream_info *stream;
struct intel_sst_drv *ctx = dev_get_drvdata(dev);
memcpy_fromio(&fw_tstamp,
((void *)(ctx->mailbox + ctx->tstamp)
+(str_id * sizeof(fw_tstamp))),
sizeof(fw_tstamp));
stream = get_stream_info(ctx, str_id);
if (!stream)
return -EINVAL;
dev_dbg(dev, "rb_counter %llu in bytes\n", fw_tstamp.ring_buffer_counter);
tstamp->copied_total = fw_tstamp.ring_buffer_counter;
tstamp->pcm_frames = fw_tstamp.frames_decoded;
tstamp->pcm_io_frames = div_u64(fw_tstamp.hardware_counter,
(u64)((stream->num_ch) * SST_GET_BYTES_PER_SAMPLE(24)));
tstamp->sampling_rate = fw_tstamp.sampling_frequency;
dev_dbg(dev, "PCM = %u\n", tstamp->pcm_io_frames);
dev_dbg(dev, "Ptr Query on strid = %d copied_total %d, decodec %d\n",
str_id, tstamp->copied_total, tstamp->pcm_frames);
dev_dbg(dev, "rendered %d\n", tstamp->pcm_io_frames);
return 0;
}
static int sst_cdev_caps(struct snd_compr_caps *caps)
{
caps->num_codecs = NUM_CODEC;
caps->min_fragment_size = MIN_FRAGMENT_SIZE;
caps->max_fragment_size = MAX_FRAGMENT_SIZE;
caps->min_fragments = MIN_FRAGMENT;
caps->max_fragments = MAX_FRAGMENT;
caps->codecs[0] = SND_AUDIOCODEC_MP3;
caps->codecs[1] = SND_AUDIOCODEC_AAC;
return 0;
}
static int sst_cdev_codec_caps(struct snd_compr_codec_caps *codec)
{
if (codec->codec == SND_AUDIOCODEC_MP3)
*codec = caps_mp3;
else if (codec->codec == SND_AUDIOCODEC_AAC)
*codec = caps_aac;
else
return -EINVAL;
return 0;
}
void sst_cdev_fragment_elapsed(struct intel_sst_drv *ctx, int str_id)
{
struct stream_info *stream;
dev_dbg(ctx->dev, "fragment elapsed from firmware for str_id %d\n",
str_id);
stream = &ctx->streams[str_id];
if (stream->compr_cb)
stream->compr_cb(stream->compr_cb_param);
}
static int sst_close_pcm_stream(struct device *dev, unsigned int str_id)
{
struct stream_info *stream;
int retval = 0;
struct intel_sst_drv *ctx = dev_get_drvdata(dev);
stream = get_stream_info(ctx, str_id);
if (!stream) {
dev_err(ctx->dev, "stream info is NULL for str %d!!!\n", str_id);
return -EINVAL;
}
if (stream->status == STREAM_RESET) {
dev_dbg(ctx->dev, "stream in reset state...\n");
retval = 0;
goto put;
}
retval = free_stream_context(ctx, str_id);
put:
stream->pcm_substream = NULL;
stream->status = STREAM_UN_INIT;
stream->period_elapsed = NULL;
ctx->stream_cnt--;
if (retval)
dev_err(ctx->dev, "free stream returned err %d\n", retval);
dev_dbg(ctx->dev, "Exit\n");
return 0;
}
static inline int sst_calc_tstamp(struct intel_sst_drv *ctx,
struct pcm_stream_info *info,
struct snd_pcm_substream *substream,
struct snd_sst_tstamp *fw_tstamp)
{
size_t delay_bytes, delay_frames;
size_t buffer_sz;
u32 pointer_bytes, pointer_samples;
dev_dbg(ctx->dev, "mrfld ring_buffer_counter %llu in bytes\n",
fw_tstamp->ring_buffer_counter);
dev_dbg(ctx->dev, "mrfld hardware_counter %llu in bytes\n",
fw_tstamp->hardware_counter);
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
delay_bytes = (size_t) (fw_tstamp->ring_buffer_counter -
fw_tstamp->hardware_counter);
else
delay_bytes = (size_t) (fw_tstamp->hardware_counter -
fw_tstamp->ring_buffer_counter);
delay_frames = bytes_to_frames(substream->runtime, delay_bytes);
buffer_sz = snd_pcm_lib_buffer_bytes(substream);
div_u64_rem(fw_tstamp->ring_buffer_counter, buffer_sz, &pointer_bytes);
pointer_samples = bytes_to_samples(substream->runtime, pointer_bytes);
dev_dbg(ctx->dev, "pcm delay %zu in bytes\n", delay_bytes);
info->buffer_ptr = pointer_samples / substream->runtime->channels;
info->pcm_delay = delay_frames / substream->runtime->channels;
dev_dbg(ctx->dev, "buffer ptr %llu pcm_delay rep: %llu\n",
info->buffer_ptr, info->pcm_delay);
return 0;
}
static int sst_read_timestamp(struct device *dev, struct pcm_stream_info *info)
{
struct stream_info *stream;
struct snd_pcm_substream *substream;
struct snd_sst_tstamp fw_tstamp;
unsigned int str_id;
struct intel_sst_drv *ctx = dev_get_drvdata(dev);
str_id = info->str_id;
stream = get_stream_info(ctx, str_id);
if (!stream)
return -EINVAL;
if (!stream->pcm_substream)
return -EINVAL;
substream = stream->pcm_substream;
memcpy_fromio(&fw_tstamp,
((void *)(ctx->mailbox + ctx->tstamp)
+ (str_id * sizeof(fw_tstamp))),
sizeof(fw_tstamp));
return sst_calc_tstamp(ctx, info, substream, &fw_tstamp);
}
static int sst_stream_start(struct device *dev, int str_id)
{
struct stream_info *str_info;
struct intel_sst_drv *ctx = dev_get_drvdata(dev);
if (ctx->sst_state != SST_FW_RUNNING)
return 0;
str_info = get_stream_info(ctx, str_id);
if (!str_info)
return -EINVAL;
str_info->prev = str_info->status;
str_info->status = STREAM_RUNNING;
sst_start_stream(ctx, str_id);
return 0;
}
static int sst_stream_drop(struct device *dev, int str_id)
{
struct stream_info *str_info;
struct intel_sst_drv *ctx = dev_get_drvdata(dev);
if (ctx->sst_state != SST_FW_RUNNING)
return 0;
str_info = get_stream_info(ctx, str_id);
if (!str_info)
return -EINVAL;
str_info->prev = STREAM_UN_INIT;
str_info->status = STREAM_INIT;
return sst_drop_stream(ctx, str_id);
}
static int sst_stream_init(struct device *dev, struct pcm_stream_info *str_info)
{
int str_id = 0;
struct stream_info *stream;
struct intel_sst_drv *ctx = dev_get_drvdata(dev);
str_id = str_info->str_id;
if (ctx->sst_state != SST_FW_RUNNING)
return 0;
stream = get_stream_info(ctx, str_id);
if (!stream)
return -EINVAL;
dev_dbg(ctx->dev, "setting the period ptrs\n");
stream->pcm_substream = str_info->arg;
stream->period_elapsed = str_info->period_elapsed;
stream->sfreq = str_info->sfreq;
stream->prev = stream->status;
stream->status = STREAM_INIT;
dev_dbg(ctx->dev,
"pcm_substream %p, period_elapsed %p, sfreq %d, status %d\n",
stream->pcm_substream, stream->period_elapsed,
stream->sfreq, stream->status);
return 0;
}
static int sst_send_byte_stream(struct device *dev,
struct snd_sst_bytes_v2 *bytes)
{
int ret_val = 0;
struct intel_sst_drv *ctx = dev_get_drvdata(dev);
if (NULL == bytes)
return -EINVAL;
ret_val = pm_runtime_get_sync(ctx->dev);
if (ret_val < 0)
return ret_val;
ret_val = sst_send_byte_stream_mrfld(ctx, bytes);
sst_pm_runtime_put(ctx);
return ret_val;
}
int sst_register(struct device *dev)
{
int ret_val;
sst_dsp_device.dev = dev;
ret_val = sst_register_dsp(&sst_dsp_device);
if (ret_val)
dev_err(dev, "Unable to register DSP with platform driver\n");
return ret_val;
}
int sst_unregister(struct device *dev)
{
return sst_unregister_dsp(&sst_dsp_device);
}
