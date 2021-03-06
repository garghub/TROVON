static int sst_byt_pcm_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct sst_byt_priv_data *pdata =
snd_soc_platform_get_drvdata(rtd->platform);
struct sst_byt_pcm_data *pcm_data = &pdata->pcm[substream->stream];
struct sst_byt *byt = pdata->byt;
u32 rate, bits;
u8 channels;
int ret, playback = (substream->stream == SNDRV_PCM_STREAM_PLAYBACK);
dev_dbg(rtd->dev, "PCM: hw_params, pcm_data %p\n", pcm_data);
ret = sst_byt_stream_type(byt, pcm_data->stream,
1, 1, !playback);
if (ret < 0) {
dev_err(rtd->dev, "failed to set stream format %d\n", ret);
return ret;
}
rate = params_rate(params);
ret = sst_byt_stream_set_rate(byt, pcm_data->stream, rate);
if (ret < 0) {
dev_err(rtd->dev, "could not set rate %d\n", rate);
return ret;
}
bits = snd_pcm_format_width(params_format(params));
ret = sst_byt_stream_set_bits(byt, pcm_data->stream, bits);
if (ret < 0) {
dev_err(rtd->dev, "could not set formats %d\n",
params_rate(params));
return ret;
}
channels = (u8)(params_channels(params) & 0xF);
ret = sst_byt_stream_set_channels(byt, pcm_data->stream, channels);
if (ret < 0) {
dev_err(rtd->dev, "could not set channels %d\n",
params_rate(params));
return ret;
}
snd_pcm_lib_malloc_pages(substream, params_buffer_bytes(params));
ret = sst_byt_stream_buffer(byt, pcm_data->stream,
substream->dma_buffer.addr,
params_buffer_bytes(params));
if (ret < 0) {
dev_err(rtd->dev, "PCM: failed to set DMA buffer %d\n", ret);
return ret;
}
ret = sst_byt_stream_commit(byt, pcm_data->stream);
if (ret < 0) {
dev_err(rtd->dev, "PCM: failed stream commit %d\n", ret);
return ret;
}
return 0;
}
static int sst_byt_pcm_hw_free(struct snd_pcm_substream *substream)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
dev_dbg(rtd->dev, "PCM: hw_free\n");
snd_pcm_lib_free_pages(substream);
return 0;
}
static int sst_byt_pcm_restore_stream_context(struct snd_pcm_substream *substream)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct sst_byt_priv_data *pdata =
snd_soc_platform_get_drvdata(rtd->platform);
struct sst_byt_pcm_data *pcm_data = &pdata->pcm[substream->stream];
struct sst_byt *byt = pdata->byt;
int ret;
ret = sst_byt_stream_commit(byt, pcm_data->stream);
if (ret < 0) {
dev_err(rtd->dev, "PCM: failed stream commit %d\n", ret);
return ret;
}
sst_byt_stream_start(byt, pcm_data->stream, pcm_data->hw_ptr);
dev_dbg(rtd->dev, "stream context restored at offset %d\n",
pcm_data->hw_ptr);
return 0;
}
static void sst_byt_pcm_work(struct work_struct *work)
{
struct sst_byt_pcm_data *pcm_data =
container_of(work, struct sst_byt_pcm_data, work);
if (snd_pcm_running(pcm_data->substream))
sst_byt_pcm_restore_stream_context(pcm_data->substream);
}
static int sst_byt_pcm_trigger(struct snd_pcm_substream *substream, int cmd)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct sst_byt_priv_data *pdata =
snd_soc_platform_get_drvdata(rtd->platform);
struct sst_byt_pcm_data *pcm_data = &pdata->pcm[substream->stream];
struct sst_byt *byt = pdata->byt;
dev_dbg(rtd->dev, "PCM: trigger %d\n", cmd);
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
pcm_data->hw_ptr = 0;
sst_byt_stream_start(byt, pcm_data->stream, 0);
break;
case SNDRV_PCM_TRIGGER_RESUME:
schedule_work(&pcm_data->work);
break;
case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
sst_byt_stream_resume(byt, pcm_data->stream);
break;
case SNDRV_PCM_TRIGGER_STOP:
sst_byt_stream_stop(byt, pcm_data->stream);
break;
case SNDRV_PCM_TRIGGER_SUSPEND:
case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
sst_byt_stream_pause(byt, pcm_data->stream);
break;
default:
break;
}
return 0;
}
static u32 byt_notify_pointer(struct sst_byt_stream *stream, void *data)
{
struct sst_byt_pcm_data *pcm_data = data;
struct snd_pcm_substream *substream = pcm_data->substream;
struct snd_pcm_runtime *runtime = substream->runtime;
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct sst_byt_priv_data *pdata =
snd_soc_platform_get_drvdata(rtd->platform);
struct sst_byt *byt = pdata->byt;
u32 pos, hw_pos;
hw_pos = sst_byt_get_dsp_position(byt, pcm_data->stream,
snd_pcm_lib_buffer_bytes(substream));
pcm_data->hw_ptr = hw_pos;
pos = frames_to_bytes(runtime,
(runtime->control->appl_ptr %
runtime->buffer_size));
dev_dbg(rtd->dev, "PCM: App/DMA pointer %u/%u bytes\n", pos, hw_pos);
snd_pcm_period_elapsed(substream);
return pos;
}
static snd_pcm_uframes_t sst_byt_pcm_pointer(struct snd_pcm_substream *substream)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_pcm_runtime *runtime = substream->runtime;
struct sst_byt_priv_data *pdata =
snd_soc_platform_get_drvdata(rtd->platform);
struct sst_byt_pcm_data *pcm_data = &pdata->pcm[substream->stream];
dev_dbg(rtd->dev, "PCM: DMA pointer %u bytes\n", pcm_data->hw_ptr);
return bytes_to_frames(runtime, pcm_data->hw_ptr);
}
static int sst_byt_pcm_open(struct snd_pcm_substream *substream)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct sst_byt_priv_data *pdata =
snd_soc_platform_get_drvdata(rtd->platform);
struct sst_byt_pcm_data *pcm_data = &pdata->pcm[substream->stream];
struct sst_byt *byt = pdata->byt;
dev_dbg(rtd->dev, "PCM: open\n");
mutex_lock(&pcm_data->mutex);
pcm_data->substream = substream;
snd_soc_set_runtime_hwparams(substream, &sst_byt_pcm_hardware);
pcm_data->stream = sst_byt_stream_new(byt, substream->stream + 1,
byt_notify_pointer, pcm_data);
if (pcm_data->stream == NULL) {
dev_err(rtd->dev, "failed to create stream\n");
mutex_unlock(&pcm_data->mutex);
return -EINVAL;
}
mutex_unlock(&pcm_data->mutex);
return 0;
}
static int sst_byt_pcm_close(struct snd_pcm_substream *substream)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct sst_byt_priv_data *pdata =
snd_soc_platform_get_drvdata(rtd->platform);
struct sst_byt_pcm_data *pcm_data = &pdata->pcm[substream->stream];
struct sst_byt *byt = pdata->byt;
int ret;
dev_dbg(rtd->dev, "PCM: close\n");
cancel_work_sync(&pcm_data->work);
mutex_lock(&pcm_data->mutex);
ret = sst_byt_stream_free(byt, pcm_data->stream);
if (ret < 0) {
dev_dbg(rtd->dev, "Free stream fail\n");
goto out;
}
pcm_data->stream = NULL;
out:
mutex_unlock(&pcm_data->mutex);
return ret;
}
static int sst_byt_pcm_mmap(struct snd_pcm_substream *substream,
struct vm_area_struct *vma)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
dev_dbg(rtd->dev, "PCM: mmap\n");
return snd_pcm_lib_default_mmap(substream, vma);
}
static void sst_byt_pcm_free(struct snd_pcm *pcm)
{
snd_pcm_lib_preallocate_free_for_all(pcm);
}
static int sst_byt_pcm_new(struct snd_soc_pcm_runtime *rtd)
{
struct snd_pcm *pcm = rtd->pcm;
size_t size;
struct snd_soc_platform *platform = rtd->platform;
struct sst_pdata *pdata = dev_get_platdata(platform->dev);
int ret = 0;
if (pcm->streams[SNDRV_PCM_STREAM_PLAYBACK].substream ||
pcm->streams[SNDRV_PCM_STREAM_CAPTURE].substream) {
size = sst_byt_pcm_hardware.buffer_bytes_max;
ret = snd_pcm_lib_preallocate_pages_for_all(pcm,
SNDRV_DMA_TYPE_DEV,
pdata->dma_dev,
size, size);
if (ret) {
dev_err(rtd->dev, "dma buffer allocation failed %d\n",
ret);
return ret;
}
}
return ret;
}
static int sst_byt_pcm_probe(struct snd_soc_platform *platform)
{
struct sst_pdata *plat_data = dev_get_platdata(platform->dev);
struct sst_byt_priv_data *priv_data;
int i;
if (!plat_data)
return -ENODEV;
priv_data = devm_kzalloc(platform->dev, sizeof(*priv_data),
GFP_KERNEL);
priv_data->byt = plat_data->dsp;
snd_soc_platform_set_drvdata(platform, priv_data);
for (i = 0; i < BYT_PCM_COUNT; i++) {
mutex_init(&priv_data->pcm[i].mutex);
INIT_WORK(&priv_data->pcm[i].work, sst_byt_pcm_work);
}
return 0;
}
static int sst_byt_pcm_remove(struct snd_soc_platform *platform)
{
return 0;
}
static int sst_byt_pcm_dev_suspend_noirq(struct device *dev)
{
struct sst_pdata *sst_pdata = dev_get_platdata(dev);
int ret;
dev_dbg(dev, "suspending noirq\n");
ret = sst_byt_dsp_suspend_noirq(dev, sst_pdata);
if (ret < 0) {
dev_err(dev, "failed to suspend %d\n", ret);
return ret;
}
return ret;
}
static int sst_byt_pcm_dev_suspend_late(struct device *dev)
{
struct sst_pdata *sst_pdata = dev_get_platdata(dev);
int ret;
dev_dbg(dev, "suspending late\n");
ret = sst_byt_dsp_suspend_late(dev, sst_pdata);
if (ret < 0) {
dev_err(dev, "failed to suspend %d\n", ret);
return ret;
}
return ret;
}
static int sst_byt_pcm_dev_resume_early(struct device *dev)
{
struct sst_pdata *sst_pdata = dev_get_platdata(dev);
dev_dbg(dev, "resume early\n");
return sst_byt_dsp_boot(dev, sst_pdata);
}
static int sst_byt_pcm_dev_resume(struct device *dev)
{
struct sst_pdata *sst_pdata = dev_get_platdata(dev);
dev_dbg(dev, "resume\n");
return sst_byt_dsp_wait_for_ready(dev, sst_pdata);
}
static int sst_byt_pcm_dev_probe(struct platform_device *pdev)
{
struct sst_pdata *sst_pdata = dev_get_platdata(&pdev->dev);
int ret;
ret = sst_byt_dsp_init(&pdev->dev, sst_pdata);
if (ret < 0)
return -ENODEV;
ret = snd_soc_register_platform(&pdev->dev, &byt_soc_platform);
if (ret < 0)
goto err_plat;
ret = snd_soc_register_component(&pdev->dev, &byt_dai_component,
byt_dais, ARRAY_SIZE(byt_dais));
if (ret < 0)
goto err_comp;
return 0;
err_comp:
snd_soc_unregister_platform(&pdev->dev);
err_plat:
sst_byt_dsp_free(&pdev->dev, sst_pdata);
return ret;
}
static int sst_byt_pcm_dev_remove(struct platform_device *pdev)
{
struct sst_pdata *sst_pdata = dev_get_platdata(&pdev->dev);
snd_soc_unregister_platform(&pdev->dev);
snd_soc_unregister_component(&pdev->dev);
sst_byt_dsp_free(&pdev->dev, sst_pdata);
return 0;
}
