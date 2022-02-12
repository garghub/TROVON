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
u32 addr_widths = BIT(DMA_SLAVE_BUSWIDTH_1_BYTE) |
BIT(DMA_SLAVE_BUSWIDTH_2_BYTES) |
BIT(DMA_SLAVE_BUSWIDTH_4_BYTES);
int i, ret;
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
if (pcm->flags & SND_DMAENGINE_PCM_FLAG_NO_RESIDUE)
hw.info |= SNDRV_PCM_INFO_BATCH;
ret = dma_get_slave_caps(chan, &dma_caps);
if (ret == 0) {
if (dma_caps.cmd_pause)
hw.info |= SNDRV_PCM_INFO_PAUSE | SNDRV_PCM_INFO_RESUME;
if (dma_caps.residue_granularity <= DMA_RESIDUE_GRANULARITY_SEGMENT)
hw.info |= SNDRV_PCM_INFO_BATCH;
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
addr_widths = dma_caps.dst_addr_widths;
else
addr_widths = dma_caps.src_addr_widths;
}
if (!(dma_data->flags & SND_DMAENGINE_PCM_DAI_FLAG_PACK))
for (i = 0; i <= SNDRV_PCM_FORMAT_LAST; i++) {
int bits = snd_pcm_format_physical_width(i);
switch (bits) {
case 8:
case 16:
case 24:
case 32:
case 64:
if (addr_widths & (1 << (bits / 8)))
hw.formats |= (1LL << i);
break;
default:
break;
}
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
static struct dma_chan *dmaengine_pcm_compat_request_channel(
struct snd_soc_pcm_runtime *rtd,
struct snd_pcm_substream *substream)
{
struct dmaengine_pcm *pcm = soc_platform_to_pcm(rtd->platform);
struct snd_dmaengine_dai_dma_data *dma_data;
dma_filter_fn fn = NULL;
dma_data = snd_soc_dai_get_dma_data(rtd->cpu_dai, substream);
if ((pcm->flags & SND_DMAENGINE_PCM_FLAG_HALF_DUPLEX) && pcm->chan[0])
return pcm->chan[0];
if (pcm->config && pcm->config->compat_request_channel)
return pcm->config->compat_request_channel(rtd, substream);
if (pcm->config)
fn = pcm->config->compat_filter_fn;
return snd_dmaengine_pcm_request_channel(fn, dma_data->filter_data);
}
static bool dmaengine_pcm_can_report_residue(struct device *dev,
struct dma_chan *chan)
{
struct dma_slave_caps dma_caps;
int ret;
ret = dma_get_slave_caps(chan, &dma_caps);
if (ret != 0) {
dev_warn(dev, "Failed to get DMA channel capabilities, falling back to period counting: %d\n",
ret);
return false;
}
if (dma_caps.residue_granularity == DMA_RESIDUE_GRANULARITY_DESCRIPTOR)
return false;
return true;
}
static int dmaengine_pcm_new(struct snd_soc_pcm_runtime *rtd)
{
struct dmaengine_pcm *pcm = soc_platform_to_pcm(rtd->platform);
const struct snd_dmaengine_pcm_config *config = pcm->config;
struct device *dev = rtd->platform->dev;
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
if (!pcm->chan[i] && (pcm->flags & SND_DMAENGINE_PCM_FLAG_COMPAT)) {
pcm->chan[i] = dmaengine_pcm_compat_request_channel(rtd,
substream);
}
if (!pcm->chan[i]) {
dev_err(rtd->platform->dev,
"Missing dma channel for stream: %d\n", i);
return -EINVAL;
}
ret = snd_pcm_lib_preallocate_pages(substream,
SNDRV_DMA_TYPE_DEV_IRAM,
dmaengine_dma_dev(pcm, substream),
prealloc_buffer_size,
max_buffer_size);
if (ret)
return ret;
if (!dmaengine_pcm_can_report_residue(dev, pcm->chan[i]))
pcm->flags |= SND_DMAENGINE_PCM_FLAG_NO_RESIDUE;
}
return 0;
}
static snd_pcm_uframes_t dmaengine_pcm_pointer(
struct snd_pcm_substream *substream)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct dmaengine_pcm *pcm = soc_platform_to_pcm(rtd->platform);
if (pcm->flags & SND_DMAENGINE_PCM_FLAG_NO_RESIDUE)
return snd_dmaengine_pcm_pointer_no_residue(substream);
else
return snd_dmaengine_pcm_pointer(substream);
}
static int dmaengine_pcm_request_chan_of(struct dmaengine_pcm *pcm,
struct device *dev, const struct snd_dmaengine_pcm_config *config)
{
unsigned int i;
const char *name;
struct dma_chan *chan;
if ((pcm->flags & SND_DMAENGINE_PCM_FLAG_NO_DT) || !dev->of_node)
return 0;
if (config && config->dma_dev) {
dev_warn(dev, "DMA channels sourced from device %s",
dev_name(config->dma_dev));
dev = config->dma_dev;
}
for (i = SNDRV_PCM_STREAM_PLAYBACK; i <= SNDRV_PCM_STREAM_CAPTURE;
i++) {
if (pcm->flags & SND_DMAENGINE_PCM_FLAG_HALF_DUPLEX)
name = "rx-tx";
else
name = dmaengine_pcm_dma_channel_names[i];
if (config && config->chan_names[i])
name = config->chan_names[i];
chan = dma_request_slave_channel_reason(dev, name);
if (IS_ERR(chan)) {
if (PTR_ERR(chan) == -EPROBE_DEFER)
return -EPROBE_DEFER;
pcm->chan[i] = NULL;
} else {
pcm->chan[i] = chan;
}
if (pcm->flags & SND_DMAENGINE_PCM_FLAG_HALF_DUPLEX)
break;
}
if (pcm->flags & SND_DMAENGINE_PCM_FLAG_HALF_DUPLEX)
pcm->chan[1] = pcm->chan[0];
return 0;
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
ret = dmaengine_pcm_request_chan_of(pcm, dev, config);
if (ret)
goto err_free_dma;
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
