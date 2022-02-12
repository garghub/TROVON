int sst_register_dsp(struct sst_device *dev)
{
if (WARN_ON(!dev))
return -EINVAL;
if (!try_module_get(dev->dev->driver->owner))
return -ENODEV;
mutex_lock(&sst_lock);
if (sst) {
dev_err(dev->dev, "we already have a device %s\n", sst->name);
module_put(dev->dev->driver->owner);
mutex_unlock(&sst_lock);
return -EEXIST;
}
dev_dbg(dev->dev, "registering device %s\n", dev->name);
sst = dev;
mutex_unlock(&sst_lock);
return 0;
}
int sst_unregister_dsp(struct sst_device *dev)
{
if (WARN_ON(!dev))
return -EINVAL;
if (dev != sst)
return -EINVAL;
mutex_lock(&sst_lock);
if (!sst) {
mutex_unlock(&sst_lock);
return -EIO;
}
module_put(sst->dev->driver->owner);
dev_dbg(dev->dev, "unreg %s\n", sst->name);
sst = NULL;
mutex_unlock(&sst_lock);
return 0;
}
static int sst_media_digital_mute(struct snd_soc_dai *dai, int mute, int stream)
{
return sst_send_pipe_gains(dai, stream, mute);
}
void sst_set_stream_status(struct sst_runtime_stream *stream,
int state)
{
unsigned long flags;
spin_lock_irqsave(&stream->status_lock, flags);
stream->stream_status = state;
spin_unlock_irqrestore(&stream->status_lock, flags);
}
static inline int sst_get_stream_status(struct sst_runtime_stream *stream)
{
int state;
unsigned long flags;
spin_lock_irqsave(&stream->status_lock, flags);
state = stream->stream_status;
spin_unlock_irqrestore(&stream->status_lock, flags);
return state;
}
static void sst_fill_alloc_params(struct snd_pcm_substream *substream,
struct snd_sst_alloc_params_ext *alloc_param)
{
unsigned int channels;
snd_pcm_uframes_t period_size;
ssize_t periodbytes;
ssize_t buffer_bytes = snd_pcm_lib_buffer_bytes(substream);
u32 buffer_addr = virt_to_phys(substream->dma_buffer.area);
channels = substream->runtime->channels;
period_size = substream->runtime->period_size;
periodbytes = samples_to_bytes(substream->runtime, period_size);
alloc_param->ring_buf_info[0].addr = buffer_addr;
alloc_param->ring_buf_info[0].size = buffer_bytes;
alloc_param->sg_count = 1;
alloc_param->reserved = 0;
alloc_param->frag_size = periodbytes * channels;
}
static void sst_fill_pcm_params(struct snd_pcm_substream *substream,
struct snd_sst_stream_params *param)
{
param->uc.pcm_params.num_chan = (u8) substream->runtime->channels;
param->uc.pcm_params.pcm_wd_sz = substream->runtime->sample_bits;
param->uc.pcm_params.sfreq = substream->runtime->rate;
param->uc.pcm_params.use_offload_path = 0;
param->uc.pcm_params.reserved2 = 0;
memset(param->uc.pcm_params.channel_map, 0, sizeof(u8));
}
static int sst_get_stream_mapping(int dev, int sdev, int dir,
struct sst_dev_stream_map *map, int size)
{
int i;
if (map == NULL)
return -EINVAL;
for (i = 1; i < size; i++) {
if ((map[i].dev_num == dev) && (map[i].direction == dir))
return i;
}
return 0;
}
int sst_fill_stream_params(void *substream,
const struct sst_data *ctx, struct snd_sst_params *str_params, bool is_compress)
{
int map_size;
int index;
struct sst_dev_stream_map *map;
struct snd_pcm_substream *pstream = NULL;
struct snd_compr_stream *cstream = NULL;
map = ctx->pdata->pdev_strm_map;
map_size = ctx->pdata->strm_map_size;
if (is_compress == true)
cstream = (struct snd_compr_stream *)substream;
else
pstream = (struct snd_pcm_substream *)substream;
str_params->stream_type = SST_STREAM_TYPE_MUSIC;
if (pstream) {
index = sst_get_stream_mapping(pstream->pcm->device,
pstream->number, pstream->stream,
map, map_size);
if (index <= 0)
return -EINVAL;
str_params->stream_id = index;
str_params->device_type = map[index].device_id;
str_params->task = map[index].task_id;
str_params->ops = (u8)pstream->stream;
}
if (cstream) {
index = sst_get_stream_mapping(cstream->device->device,
0, cstream->direction,
map, map_size);
if (index <= 0)
return -EINVAL;
str_params->stream_id = index;
str_params->device_type = map[index].device_id;
str_params->task = map[index].task_id;
str_params->ops = (u8)cstream->direction;
}
return 0;
}
static int sst_platform_alloc_stream(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct sst_runtime_stream *stream =
substream->runtime->private_data;
struct snd_sst_stream_params param = {{{0,},},};
struct snd_sst_params str_params = {0};
struct snd_sst_alloc_params_ext alloc_params = {0};
int ret_val = 0;
struct sst_data *ctx = snd_soc_dai_get_drvdata(dai);
sst_fill_pcm_params(substream, &param);
sst_fill_alloc_params(substream, &alloc_params);
substream->runtime->dma_area = substream->dma_buffer.area;
str_params.sparams = param;
str_params.aparams = alloc_params;
str_params.codec = SST_CODEC_TYPE_PCM;
ret_val = sst_fill_stream_params(substream, ctx, &str_params, false);
if (ret_val < 0)
return ret_val;
stream->stream_info.str_id = str_params.stream_id;
ret_val = stream->ops->open(sst->dev, &str_params);
if (ret_val <= 0)
return ret_val;
return ret_val;
}
static void sst_period_elapsed(void *arg)
{
struct snd_pcm_substream *substream = arg;
struct sst_runtime_stream *stream;
int status;
if (!substream || !substream->runtime)
return;
stream = substream->runtime->private_data;
if (!stream)
return;
status = sst_get_stream_status(stream);
if (status != SST_PLATFORM_RUNNING)
return;
snd_pcm_period_elapsed(substream);
}
static int sst_platform_init_stream(struct snd_pcm_substream *substream)
{
struct sst_runtime_stream *stream =
substream->runtime->private_data;
struct snd_soc_pcm_runtime *rtd = substream->private_data;
int ret_val;
dev_dbg(rtd->dev, "setting buffer ptr param\n");
sst_set_stream_status(stream, SST_PLATFORM_INIT);
stream->stream_info.period_elapsed = sst_period_elapsed;
stream->stream_info.arg = substream;
stream->stream_info.buffer_ptr = 0;
stream->stream_info.sfreq = substream->runtime->rate;
ret_val = stream->ops->stream_init(sst->dev, &stream->stream_info);
if (ret_val)
dev_err(rtd->dev, "control_set ret error %d\n", ret_val);
return ret_val;
}
static int power_up_sst(struct sst_runtime_stream *stream)
{
return stream->ops->power(sst->dev, true);
}
static void power_down_sst(struct sst_runtime_stream *stream)
{
stream->ops->power(sst->dev, false);
}
static int sst_media_open(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
int ret_val = 0;
struct snd_pcm_runtime *runtime = substream->runtime;
struct sst_runtime_stream *stream;
stream = kzalloc(sizeof(*stream), GFP_KERNEL);
if (!stream)
return -ENOMEM;
spin_lock_init(&stream->status_lock);
mutex_lock(&sst_lock);
if (!sst ||
!try_module_get(sst->dev->driver->owner)) {
dev_err(dai->dev, "no device available to run\n");
ret_val = -ENODEV;
goto out_ops;
}
stream->ops = sst->ops;
mutex_unlock(&sst_lock);
stream->stream_info.str_id = 0;
stream->stream_info.arg = substream;
runtime->private_data = stream;
ret_val = power_up_sst(stream);
if (ret_val < 0)
return ret_val;
snd_pcm_hw_constraint_step(substream->runtime, 0,
SNDRV_PCM_HW_PARAM_PERIODS, 2);
return snd_pcm_hw_constraint_integer(runtime,
SNDRV_PCM_HW_PARAM_PERIODS);
out_ops:
kfree(stream);
mutex_unlock(&sst_lock);
return ret_val;
}
static void sst_media_close(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct sst_runtime_stream *stream;
int ret_val = 0, str_id;
stream = substream->runtime->private_data;
power_down_sst(stream);
str_id = stream->stream_info.str_id;
if (str_id)
ret_val = stream->ops->close(sst->dev, str_id);
module_put(sst->dev->driver->owner);
kfree(stream);
}
static int sst_media_prepare(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct sst_runtime_stream *stream;
int ret_val = 0, str_id;
stream = substream->runtime->private_data;
str_id = stream->stream_info.str_id;
if (stream->stream_info.str_id) {
ret_val = stream->ops->stream_drop(sst->dev, str_id);
return ret_val;
}
ret_val = sst_platform_alloc_stream(substream, dai);
if (ret_val <= 0)
return ret_val;
snprintf(substream->pcm->id, sizeof(substream->pcm->id),
"%d", stream->stream_info.str_id);
ret_val = sst_platform_init_stream(substream);
if (ret_val)
return ret_val;
substream->runtime->hw.info = SNDRV_PCM_INFO_BLOCK_TRANSFER;
return ret_val;
}
static int sst_media_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
snd_pcm_lib_malloc_pages(substream, params_buffer_bytes(params));
memset(substream->runtime->dma_area, 0, params_buffer_bytes(params));
return 0;
}
static int sst_media_hw_free(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
return snd_pcm_lib_free_pages(substream);
}
static int sst_enable_ssp(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
int ret = 0;
if (!dai->active) {
ret = sst_handle_vb_timer(dai, true);
sst_fill_ssp_defaults(dai);
}
return ret;
}
static int sst_be_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
int ret = 0;
if (dai->active == 1)
ret = send_ssp_cmd(dai, dai->name, 1);
return ret;
}
static int sst_set_format(struct snd_soc_dai *dai, unsigned int fmt)
{
int ret = 0;
if (!dai->active)
return 0;
ret = sst_fill_ssp_config(dai, fmt);
if (ret < 0)
dev_err(dai->dev, "sst_set_format failed..\n");
return ret;
}
static int sst_platform_set_ssp_slot(struct snd_soc_dai *dai,
unsigned int tx_mask, unsigned int rx_mask,
int slots, int slot_width) {
int ret = 0;
if (!dai->active)
return ret;
ret = sst_fill_ssp_slot(dai, tx_mask, rx_mask, slots, slot_width);
if (ret < 0)
dev_err(dai->dev, "sst_fill_ssp_slot failed..%d\n", ret);
return ret;
}
static void sst_disable_ssp(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
if (!dai->active) {
send_ssp_cmd(dai, dai->name, 0);
sst_handle_vb_timer(dai, false);
}
}
static int sst_platform_open(struct snd_pcm_substream *substream)
{
struct snd_pcm_runtime *runtime;
if (substream->pcm->internal)
return 0;
runtime = substream->runtime;
runtime->hw = sst_platform_pcm_hw;
return 0;
}
static int sst_platform_pcm_trigger(struct snd_pcm_substream *substream,
int cmd)
{
int ret_val = 0, str_id;
struct sst_runtime_stream *stream;
int status;
struct snd_soc_pcm_runtime *rtd = substream->private_data;
dev_dbg(rtd->dev, "sst_platform_pcm_trigger called\n");
if (substream->pcm->internal)
return 0;
stream = substream->runtime->private_data;
str_id = stream->stream_info.str_id;
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
dev_dbg(rtd->dev, "sst: Trigger Start\n");
status = SST_PLATFORM_RUNNING;
stream->stream_info.arg = substream;
ret_val = stream->ops->stream_start(sst->dev, str_id);
break;
case SNDRV_PCM_TRIGGER_STOP:
dev_dbg(rtd->dev, "sst: in stop\n");
status = SST_PLATFORM_DROPPED;
ret_val = stream->ops->stream_drop(sst->dev, str_id);
break;
case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
case SNDRV_PCM_TRIGGER_SUSPEND:
dev_dbg(rtd->dev, "sst: in pause\n");
status = SST_PLATFORM_PAUSED;
ret_val = stream->ops->stream_pause(sst->dev, str_id);
break;
case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
case SNDRV_PCM_TRIGGER_RESUME:
dev_dbg(rtd->dev, "sst: in pause release\n");
status = SST_PLATFORM_RUNNING;
ret_val = stream->ops->stream_pause_release(sst->dev, str_id);
break;
default:
return -EINVAL;
}
if (!ret_val)
sst_set_stream_status(stream, status);
return ret_val;
}
static snd_pcm_uframes_t sst_platform_pcm_pointer
(struct snd_pcm_substream *substream)
{
struct sst_runtime_stream *stream;
int ret_val, status;
struct pcm_stream_info *str_info;
struct snd_soc_pcm_runtime *rtd = substream->private_data;
stream = substream->runtime->private_data;
status = sst_get_stream_status(stream);
if (status == SST_PLATFORM_INIT)
return 0;
str_info = &stream->stream_info;
ret_val = stream->ops->stream_read_tstamp(sst->dev, str_info);
if (ret_val) {
dev_err(rtd->dev, "sst: error code = %d\n", ret_val);
return ret_val;
}
substream->runtime->delay = str_info->pcm_delay;
return str_info->buffer_ptr;
}
static int sst_pcm_new(struct snd_soc_pcm_runtime *rtd)
{
struct snd_soc_dai *dai = rtd->cpu_dai;
struct snd_pcm *pcm = rtd->pcm;
int retval = 0;
if (dai->driver->playback.channels_min ||
dai->driver->capture.channels_min) {
retval = snd_pcm_lib_preallocate_pages_for_all(pcm,
SNDRV_DMA_TYPE_CONTINUOUS,
snd_dma_continuous_data(GFP_DMA),
SST_MIN_BUFFER, SST_MAX_BUFFER);
if (retval) {
dev_err(rtd->dev, "dma buffer allocationf fail\n");
return retval;
}
}
return retval;
}
static int sst_soc_probe(struct snd_soc_platform *platform)
{
struct sst_data *drv = dev_get_drvdata(platform->dev);
drv->soc_card = platform->component.card;
return sst_dsp_init_v2_dpcm(platform);
}
static int sst_platform_probe(struct platform_device *pdev)
{
struct sst_data *drv;
int ret;
struct sst_platform_data *pdata;
drv = devm_kzalloc(&pdev->dev, sizeof(*drv), GFP_KERNEL);
if (drv == NULL) {
return -ENOMEM;
}
pdata = devm_kzalloc(&pdev->dev, sizeof(*pdata), GFP_KERNEL);
if (pdata == NULL) {
return -ENOMEM;
}
pdata->pdev_strm_map = dpcm_strm_map;
pdata->strm_map_size = ARRAY_SIZE(dpcm_strm_map);
drv->pdata = pdata;
drv->pdev = pdev;
mutex_init(&drv->lock);
dev_set_drvdata(&pdev->dev, drv);
ret = snd_soc_register_platform(&pdev->dev, &sst_soc_platform_drv);
if (ret) {
dev_err(&pdev->dev, "registering soc platform failed\n");
return ret;
}
ret = snd_soc_register_component(&pdev->dev, &sst_component,
sst_platform_dai, ARRAY_SIZE(sst_platform_dai));
if (ret) {
dev_err(&pdev->dev, "registering cpu dais failed\n");
snd_soc_unregister_platform(&pdev->dev);
}
return ret;
}
static int sst_platform_remove(struct platform_device *pdev)
{
snd_soc_unregister_component(&pdev->dev);
snd_soc_unregister_platform(&pdev->dev);
dev_dbg(&pdev->dev, "sst_platform_remove success\n");
return 0;
}
static int sst_soc_prepare(struct device *dev)
{
struct sst_data *drv = dev_get_drvdata(dev);
struct snd_soc_pcm_runtime *rtd;
if (!drv->soc_card)
return 0;
snd_soc_suspend(drv->soc_card->dev);
snd_soc_poweroff(drv->soc_card->dev);
list_for_each_entry(rtd, &drv->soc_card->rtd_list, list) {
struct snd_soc_dai *dai = rtd->cpu_dai;
if (dai->active) {
send_ssp_cmd(dai, dai->name, 0);
sst_handle_vb_timer(dai, false);
}
}
return 0;
}
static void sst_soc_complete(struct device *dev)
{
struct sst_data *drv = dev_get_drvdata(dev);
struct snd_soc_pcm_runtime *rtd;
if (!drv->soc_card)
return;
list_for_each_entry(rtd, &drv->soc_card->rtd_list, list) {
struct snd_soc_dai *dai = rtd->cpu_dai;
if (dai->active) {
sst_handle_vb_timer(dai, true);
send_ssp_cmd(dai, dai->name, 1);
}
}
snd_soc_resume(drv->soc_card->dev);
}
