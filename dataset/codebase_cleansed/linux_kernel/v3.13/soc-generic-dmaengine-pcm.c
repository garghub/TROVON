static struct dmaengine_pcm *soc_platform_to_pcm(struct snd_soc_platform *p)
{
return container_of(p, struct dmaengine_pcm, platform);
}
static struct device *dmaengine_dma_dev(struct dmaengine_pcm *pcm,
struct snd_pcm_substream *substream)
{
if (!pcm->chan[substream->stream])
return NULL;
return pcm->chan[substream->stream]->device->dev;
}
int snd_dmaengine_pcm_prepare_slave_config(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params, struct dma_slave_config *slave_config)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_dmaengine_dai_dma_data *dma_data;
int ret;
dma_data = snd_soc_dai_get_dma_data(rtd->cpu_dai, substream);
ret = snd_hwparams_to_dma_slave_config(substream, params, slave_config);
if (ret)
return ret;
snd_dmaengine_pcm_set_config_from_dai_data(substream, dma_data,
slave_config);
return 0;
}
static int dmaengine_pcm_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct dmaengine_pcm *pcm = soc_platform_to_pcm(rtd->platform);
struct dma_chan *chan = snd_dmaengine_pcm_get_chan(substream);
int (*prepare_slave_config)(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct dma_slave_config *slave_config);
struct dma_slave_config slave_config;
int ret;
memset(&slave_config, 0, sizeof(slave_config));
if (!pcm->config)
prepare_slave_config = snd_dmaengine_pcm_prepare_slave_config;
else
prepare_slave_config = pcm->config->prepare_slave_config;
if (prepare_slave_config) {
ret = prepare_slave_config(substream, params, &slave_config);
if (ret)
return ret;
ret = dmaengine_slave_config(chan, &slave_config);
if (ret)
return ret;
}
return snd_pcm_lib_malloc_pages(substream, params_buffer_bytes(params));
}
static int dmaengine_pcm_set_runtime_hwparams(struct snd_pcm_substream *substream)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct dmaengine_pcm *pcm = soc_platform_to_pcm(rtd->platform);
struct device *dma_dev = dmaengine_dma_dev(pcm, substream);
struct dma_chan *chan = pcm->chan[substream->stream];
struct snd_dmaengine_dai_dma_data *dma_data;
struct dma_slave_caps dma_caps;
struct snd_pcm_hardware hw;
int ret;
if (pcm->config && pcm->config->pcm_hardware)
return snd_soc_set_runtime_hwparams(substream,
pcm->config->pcm_hardware);
dma_data = snd_soc_dai_get_dma_data(rtd->cpu_dai, substream);
memset(&hw, 0, sizeof(hw));
hw.info = SNDRV_PCM_INFO_MMAP | SNDRV_PCM_INFO_MMAP_VALID |
SNDRV_PCM_INFO_INTERLEAVED;
hw.periods_min = 2;
hw.periods_max = UINT_MAX;
hw.period_bytes_min = 256;
hw.period_bytes_max = dma_get_max_seg_size(dma_dev);
hw.buffer_bytes_max = SIZE_MAX;
hw.fifo_size = dma_data->fifo_size;
ret = dma_get_slave_caps(chan, &dma_caps);
if (ret == 0) {
if (dma_caps.cmd_pause)
hw.info |= SNDRV_PCM_INFO_PAUSE | SNDRV_PCM_INFO_RESUME;
}
return snd_soc_set_runtime_hwparams(substream, &hw);
}
static int dmaengine_pcm_open(struct snd_pcm_substream *substream)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct dmaengine_pcm *pcm = soc_platform_to_pcm(rtd->platform);
struct dma_chan *chan = pcm->chan[substream->stream];
int ret;
ret = dmaengine_pcm_set_runtime_hwparams(substream);
if (ret)
return ret;
return snd_dmaengine_pcm_open(substream, chan);
}
static void dmaengine_pcm_free(struct snd_pcm *pcm)
{
snd_pcm_lib_preallocate_free_for_all(pcm);
}
static struct dma_chan *dmaengine_pcm_compat_request_channel(
struct snd_soc_pcm_runtime *rtd,
struct snd_pcm_substream *substream)
{
struct dmaengine_pcm *pcm = soc_platform_to_pcm(rtd->platform);
struct snd_dmaengine_dai_dma_data *dma_data;
dma_data = snd_soc_dai_get_dma_data(rtd->cpu_dai, substream);
if ((pcm->flags & SND_DMAENGINE_PCM_FLAG_HALF_DUPLEX) && pcm->chan[0])
return pcm->chan[0];
if (pcm->config->compat_request_channel)
return pcm->config->compat_request_channel(rtd, substream);
return snd_dmaengine_pcm_request_channel(pcm->config->compat_filter_fn,
dma_data->filter_data);
}
static int dmaengine_pcm_new(struct snd_soc_pcm_runtime *rtd)
{
struct dmaengine_pcm *pcm = soc_platform_to_pcm(rtd->platform);
const struct snd_dmaengine_pcm_config *config = pcm->config;
struct device *dev = rtd->platform->dev;
struct snd_dmaengine_dai_dma_data *dma_data;
struct snd_pcm_substream *substream;
size_t prealloc_buffer_size;
size_t max_buffer_size;
unsigned int i;
int ret;
if (config && config->prealloc_buffer_size) {
prealloc_buffer_size = config->prealloc_buffer_size;
max_buffer_size = config->pcm_hardware->buffer_bytes_max;
} else {
prealloc_buffer_size = 512 * 1024;
max_buffer_size = SIZE_MAX;
}
for (i = SNDRV_PCM_STREAM_PLAYBACK; i <= SNDRV_PCM_STREAM_CAPTURE; i++) {
substream = rtd->pcm->streams[i].substream;
if (!substream)
continue;
dma_data = snd_soc_dai_get_dma_data(rtd->cpu_dai, substream);
if (!pcm->chan[i] &&
(pcm->flags & SND_DMAENGINE_PCM_FLAG_CUSTOM_CHANNEL_NAME))
pcm->chan[i] = dma_request_slave_channel(dev,
dma_data->chan_name);
if (!pcm->chan[i] && (pcm->flags & SND_DMAENGINE_PCM_FLAG_COMPAT)) {
pcm->chan[i] = dmaengine_pcm_compat_request_channel(rtd,
substream);
}
if (!pcm->chan[i]) {
dev_err(rtd->platform->dev,
"Missing dma channel for stream: %d\n", i);
ret = -EINVAL;
goto err_free;
}
ret = snd_pcm_lib_preallocate_pages(substream,
SNDRV_DMA_TYPE_DEV_IRAM,
dmaengine_dma_dev(pcm, substream),
prealloc_buffer_size,
max_buffer_size);
if (ret)
goto err_free;
}
return 0;
err_free:
dmaengine_pcm_free(rtd->pcm);
return ret;
}
static void dmaengine_pcm_request_chan_of(struct dmaengine_pcm *pcm,
struct device *dev)
{
unsigned int i;
if ((pcm->flags & (SND_DMAENGINE_PCM_FLAG_NO_DT |
SND_DMAENGINE_PCM_FLAG_CUSTOM_CHANNEL_NAME)) ||
!dev->of_node)
return;
if (pcm->flags & SND_DMAENGINE_PCM_FLAG_HALF_DUPLEX) {
pcm->chan[0] = dma_request_slave_channel(dev, "rx-tx");
pcm->chan[1] = pcm->chan[0];
} else {
for (i = SNDRV_PCM_STREAM_PLAYBACK; i <= SNDRV_PCM_STREAM_CAPTURE; i++) {
pcm->chan[i] = dma_request_slave_channel(dev,
dmaengine_pcm_dma_channel_names[i]);
}
}
}
static void dmaengine_pcm_release_chan(struct dmaengine_pcm *pcm)
{
unsigned int i;
for (i = SNDRV_PCM_STREAM_PLAYBACK; i <= SNDRV_PCM_STREAM_CAPTURE;
i++) {
if (!pcm->chan[i])
continue;
dma_release_channel(pcm->chan[i]);
if (pcm->flags & SND_DMAENGINE_PCM_FLAG_HALF_DUPLEX)
break;
}
}
int snd_dmaengine_pcm_register(struct device *dev,
const struct snd_dmaengine_pcm_config *config, unsigned int flags)
{
struct dmaengine_pcm *pcm;
int ret;
pcm = kzalloc(sizeof(*pcm), GFP_KERNEL);
if (!pcm)
return -ENOMEM;
pcm->config = config;
pcm->flags = flags;
dmaengine_pcm_request_chan_of(pcm, dev);
if (flags & SND_DMAENGINE_PCM_FLAG_NO_RESIDUE)
ret = snd_soc_add_platform(dev, &pcm->platform,
&dmaengine_no_residue_pcm_platform);
else
ret = snd_soc_add_platform(dev, &pcm->platform,
&dmaengine_pcm_platform);
if (ret)
goto err_free_dma;
return 0;
err_free_dma:
dmaengine_pcm_release_chan(pcm);
kfree(pcm);
return ret;
}
void snd_dmaengine_pcm_unregister(struct device *dev)
{
struct snd_soc_platform *platform;
struct dmaengine_pcm *pcm;
platform = snd_soc_lookup_platform(dev);
if (!platform)
return;
pcm = soc_platform_to_pcm(platform);
snd_soc_remove_platform(platform);
dmaengine_pcm_release_chan(pcm);
kfree(pcm);
}
