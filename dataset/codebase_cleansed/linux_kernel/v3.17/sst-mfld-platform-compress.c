static void sst_compr_fragment_elapsed(void *arg)
{
struct snd_compr_stream *cstream = (struct snd_compr_stream *)arg;
pr_debug("fragment elapsed by driver\n");
if (cstream)
snd_compr_fragment_elapsed(cstream);
}
static void sst_drain_notify(void *arg)
{
struct snd_compr_stream *cstream = (struct snd_compr_stream *)arg;
pr_debug("drain notify by driver\n");
if (cstream)
snd_compr_drain_notify(cstream);
}
static int sst_platform_compr_open(struct snd_compr_stream *cstream)
{
int ret_val = 0;
struct snd_compr_runtime *runtime = cstream->runtime;
struct sst_runtime_stream *stream;
stream = kzalloc(sizeof(*stream), GFP_KERNEL);
if (!stream)
return -ENOMEM;
spin_lock_init(&stream->status_lock);
if (!sst || !try_module_get(sst->dev->driver->owner)) {
pr_err("no device available to run\n");
ret_val = -ENODEV;
goto out_ops;
}
stream->compr_ops = sst->compr_ops;
stream->id = 0;
sst_set_stream_status(stream, SST_PLATFORM_INIT);
runtime->private_data = stream;
return 0;
out_ops:
kfree(stream);
return ret_val;
}
static int sst_platform_compr_free(struct snd_compr_stream *cstream)
{
struct sst_runtime_stream *stream;
int ret_val = 0, str_id;
stream = cstream->runtime->private_data;
str_id = stream->id;
if (str_id)
ret_val = stream->compr_ops->close(str_id);
module_put(sst->dev->driver->owner);
kfree(stream);
pr_debug("%s: %d\n", __func__, ret_val);
return 0;
}
static int sst_platform_compr_set_params(struct snd_compr_stream *cstream,
struct snd_compr_params *params)
{
struct sst_runtime_stream *stream;
int retval;
struct snd_sst_params str_params;
struct sst_compress_cb cb;
struct snd_soc_pcm_runtime *rtd = cstream->private_data;
struct snd_soc_platform *platform = rtd->platform;
struct sst_data *ctx = snd_soc_platform_get_drvdata(platform);
stream = cstream->runtime->private_data;
memset(&str_params, 0, sizeof(str_params));
retval = sst_fill_stream_params(cstream, ctx, &str_params, true);
pr_debug("compr_set_params: fill stream params ret_val = 0x%x\n", retval);
if (retval < 0)
return retval;
switch (params->codec.id) {
case SND_AUDIOCODEC_MP3: {
str_params.codec = SST_CODEC_TYPE_MP3;
str_params.sparams.uc.mp3_params.num_chan = params->codec.ch_in;
str_params.sparams.uc.mp3_params.pcm_wd_sz = 16;
break;
}
case SND_AUDIOCODEC_AAC: {
str_params.codec = SST_CODEC_TYPE_AAC;
str_params.sparams.uc.aac_params.num_chan = params->codec.ch_in;
str_params.sparams.uc.aac_params.pcm_wd_sz = 16;
if (params->codec.format == SND_AUDIOSTREAMFORMAT_MP4ADTS)
str_params.sparams.uc.aac_params.bs_format =
AAC_BIT_STREAM_ADTS;
else if (params->codec.format == SND_AUDIOSTREAMFORMAT_RAW)
str_params.sparams.uc.aac_params.bs_format =
AAC_BIT_STREAM_RAW;
else {
pr_err("Undefined format%d\n", params->codec.format);
return -EINVAL;
}
str_params.sparams.uc.aac_params.externalsr =
params->codec.sample_rate;
break;
}
default:
pr_err("codec not supported, id =%d\n", params->codec.id);
return -EINVAL;
}
str_params.aparams.ring_buf_info[0].addr =
virt_to_phys(cstream->runtime->buffer);
str_params.aparams.ring_buf_info[0].size =
cstream->runtime->buffer_size;
str_params.aparams.sg_count = 1;
str_params.aparams.frag_size = cstream->runtime->fragment_size;
cb.param = cstream;
cb.compr_cb = sst_compr_fragment_elapsed;
cb.drain_cb_param = cstream;
cb.drain_notify = sst_drain_notify;
retval = stream->compr_ops->open(&str_params, &cb);
if (retval < 0) {
pr_err("stream allocation failed %d\n", retval);
return retval;
}
stream->id = retval;
return 0;
}
static int sst_platform_compr_trigger(struct snd_compr_stream *cstream, int cmd)
{
struct sst_runtime_stream *stream =
cstream->runtime->private_data;
return stream->compr_ops->control(cmd, stream->id);
}
static int sst_platform_compr_pointer(struct snd_compr_stream *cstream,
struct snd_compr_tstamp *tstamp)
{
struct sst_runtime_stream *stream;
stream = cstream->runtime->private_data;
stream->compr_ops->tstamp(stream->id, tstamp);
tstamp->byte_offset = tstamp->copied_total %
(u32)cstream->runtime->buffer_size;
pr_debug("calc bytes offset/copied bytes as %d\n", tstamp->byte_offset);
return 0;
}
static int sst_platform_compr_ack(struct snd_compr_stream *cstream,
size_t bytes)
{
struct sst_runtime_stream *stream;
stream = cstream->runtime->private_data;
stream->compr_ops->ack(stream->id, (unsigned long)bytes);
stream->bytes_written += bytes;
return 0;
}
static int sst_platform_compr_get_caps(struct snd_compr_stream *cstream,
struct snd_compr_caps *caps)
{
struct sst_runtime_stream *stream =
cstream->runtime->private_data;
return stream->compr_ops->get_caps(caps);
}
static int sst_platform_compr_get_codec_caps(struct snd_compr_stream *cstream,
struct snd_compr_codec_caps *codec)
{
struct sst_runtime_stream *stream =
cstream->runtime->private_data;
return stream->compr_ops->get_codec_caps(codec);
}
static int sst_platform_compr_set_metadata(struct snd_compr_stream *cstream,
struct snd_compr_metadata *metadata)
{
struct sst_runtime_stream *stream =
cstream->runtime->private_data;
return stream->compr_ops->set_metadata(stream->id, metadata);
}
