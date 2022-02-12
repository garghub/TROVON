static inline struct dmaengine_pcm_runtime_data *substream_to_prtd(
const struct snd_pcm_substream *substream)
{
return substream->runtime->private_data;
}
void snd_dmaengine_pcm_set_data(struct snd_pcm_substream *substream, void *data)
{
struct dmaengine_pcm_runtime_data *prtd = substream_to_prtd(substream);
prtd->data = data;
}
void *snd_dmaengine_pcm_get_data(struct snd_pcm_substream *substream)
{
struct dmaengine_pcm_runtime_data *prtd = substream_to_prtd(substream);
return prtd->data;
}
struct dma_chan *snd_dmaengine_pcm_get_chan(struct snd_pcm_substream *substream)
{
struct dmaengine_pcm_runtime_data *prtd = substream_to_prtd(substream);
return prtd->dma_chan;
}
int snd_hwparams_to_dma_slave_config(const struct snd_pcm_substream *substream,
const struct snd_pcm_hw_params *params,
struct dma_slave_config *slave_config)
{
enum dma_slave_buswidth buswidth;
switch (params_format(params)) {
case SNDRV_PCM_FORMAT_S8:
buswidth = DMA_SLAVE_BUSWIDTH_1_BYTE;
break;
case SNDRV_PCM_FORMAT_S16_LE:
buswidth = DMA_SLAVE_BUSWIDTH_2_BYTES;
break;
case SNDRV_PCM_FORMAT_S18_3LE:
case SNDRV_PCM_FORMAT_S20_3LE:
case SNDRV_PCM_FORMAT_S24_LE:
case SNDRV_PCM_FORMAT_S32_LE:
buswidth = DMA_SLAVE_BUSWIDTH_4_BYTES;
break;
default:
return -EINVAL;
}
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) {
slave_config->direction = DMA_MEM_TO_DEV;
slave_config->dst_addr_width = buswidth;
} else {
slave_config->direction = DMA_DEV_TO_MEM;
slave_config->src_addr_width = buswidth;
}
return 0;
}
static void dmaengine_pcm_dma_complete(void *arg)
{
struct snd_pcm_substream *substream = arg;
struct dmaengine_pcm_runtime_data *prtd = substream_to_prtd(substream);
prtd->pos += snd_pcm_lib_period_bytes(substream);
if (prtd->pos >= snd_pcm_lib_buffer_bytes(substream))
prtd->pos = 0;
snd_pcm_period_elapsed(substream);
}
static int dmaengine_pcm_prepare_and_submit(struct snd_pcm_substream *substream)
{
struct dmaengine_pcm_runtime_data *prtd = substream_to_prtd(substream);
struct dma_chan *chan = prtd->dma_chan;
struct dma_async_tx_descriptor *desc;
enum dma_transfer_direction direction;
direction = snd_pcm_substream_to_dma_direction(substream);
prtd->pos = 0;
desc = dmaengine_prep_dma_cyclic(chan,
substream->runtime->dma_addr,
snd_pcm_lib_buffer_bytes(substream),
snd_pcm_lib_period_bytes(substream), direction);
if (!desc)
return -ENOMEM;
desc->callback = dmaengine_pcm_dma_complete;
desc->callback_param = substream;
dmaengine_submit(desc);
return 0;
}
int snd_dmaengine_pcm_trigger(struct snd_pcm_substream *substream, int cmd)
{
struct dmaengine_pcm_runtime_data *prtd = substream_to_prtd(substream);
int ret;
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
ret = dmaengine_pcm_prepare_and_submit(substream);
if (ret)
return ret;
dma_async_issue_pending(prtd->dma_chan);
break;
case SNDRV_PCM_TRIGGER_RESUME:
case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
dmaengine_resume(prtd->dma_chan);
break;
case SNDRV_PCM_TRIGGER_SUSPEND:
case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
dmaengine_pause(prtd->dma_chan);
break;
case SNDRV_PCM_TRIGGER_STOP:
dmaengine_terminate_all(prtd->dma_chan);
break;
default:
return -EINVAL;
}
return 0;
}
snd_pcm_uframes_t snd_dmaengine_pcm_pointer(struct snd_pcm_substream *substream)
{
struct dmaengine_pcm_runtime_data *prtd = substream_to_prtd(substream);
return bytes_to_frames(substream->runtime, prtd->pos);
}
static int dmaengine_pcm_request_channel(struct dmaengine_pcm_runtime_data *prtd,
dma_filter_fn filter_fn, void *filter_data)
{
dma_cap_mask_t mask;
dma_cap_zero(mask);
dma_cap_set(DMA_SLAVE, mask);
dma_cap_set(DMA_CYCLIC, mask);
prtd->dma_chan = dma_request_channel(mask, filter_fn, filter_data);
if (!prtd->dma_chan)
return -ENXIO;
return 0;
}
int snd_dmaengine_pcm_open(struct snd_pcm_substream *substream,
dma_filter_fn filter_fn, void *filter_data)
{
struct dmaengine_pcm_runtime_data *prtd;
int ret;
ret = snd_pcm_hw_constraint_integer(substream->runtime,
SNDRV_PCM_HW_PARAM_PERIODS);
if (ret < 0)
return ret;
prtd = kzalloc(sizeof(*prtd), GFP_KERNEL);
if (!prtd)
return -ENOMEM;
ret = dmaengine_pcm_request_channel(prtd, filter_fn, filter_data);
if (ret < 0) {
kfree(prtd);
return ret;
}
substream->runtime->private_data = prtd;
return 0;
}
int snd_dmaengine_pcm_close(struct snd_pcm_substream *substream)
{
struct dmaengine_pcm_runtime_data *prtd = substream_to_prtd(substream);
dma_release_channel(prtd->dma_chan);
kfree(prtd);
return 0;
}
