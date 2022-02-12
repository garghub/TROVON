static inline struct dmaengine_pcm_runtime_data *substream_to_prtd(
const struct snd_pcm_substream *substream)
{
return substream->runtime->private_data;
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
slave_config->device_fc = false;
return 0;
}
void snd_dmaengine_pcm_set_config_from_dai_data(
const struct snd_pcm_substream *substream,
const struct snd_dmaengine_dai_dma_data *dma_data,
struct dma_slave_config *slave_config)
{
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) {
slave_config->dst_addr = dma_data->addr;
slave_config->dst_maxburst = dma_data->maxburst;
if (dma_data->addr_width != DMA_SLAVE_BUSWIDTH_UNDEFINED)
slave_config->dst_addr_width = dma_data->addr_width;
} else {
slave_config->src_addr = dma_data->addr;
slave_config->src_maxburst = dma_data->maxburst;
if (dma_data->addr_width != DMA_SLAVE_BUSWIDTH_UNDEFINED)
slave_config->src_addr_width = dma_data->addr_width;
}
slave_config->slave_id = dma_data->slave_id;
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
unsigned long flags = DMA_CTRL_ACK;
direction = snd_pcm_substream_to_dma_direction(substream);
if (!substream->runtime->no_period_wakeup)
flags |= DMA_PREP_INTERRUPT;
prtd->pos = 0;
desc = dmaengine_prep_dma_cyclic(chan,
substream->runtime->dma_addr,
snd_pcm_lib_buffer_bytes(substream),
snd_pcm_lib_period_bytes(substream), direction, flags);
if (!desc)
return -ENOMEM;
desc->callback = dmaengine_pcm_dma_complete;
desc->callback_param = substream;
prtd->cookie = dmaengine_submit(desc);
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
snd_pcm_uframes_t snd_dmaengine_pcm_pointer_no_residue(struct snd_pcm_substream *substream)
{
struct dmaengine_pcm_runtime_data *prtd = substream_to_prtd(substream);
return bytes_to_frames(substream->runtime, prtd->pos);
}
snd_pcm_uframes_t snd_dmaengine_pcm_pointer(struct snd_pcm_substream *substream)
{
struct dmaengine_pcm_runtime_data *prtd = substream_to_prtd(substream);
struct dma_tx_state state;
enum dma_status status;
unsigned int buf_size;
unsigned int pos = 0;
status = dmaengine_tx_status(prtd->dma_chan, prtd->cookie, &state);
if (status == DMA_IN_PROGRESS || status == DMA_PAUSED) {
buf_size = snd_pcm_lib_buffer_bytes(substream);
if (state.residue > 0 && state.residue <= buf_size)
pos = buf_size - state.residue;
}
return bytes_to_frames(substream->runtime, pos);
}
struct dma_chan *snd_dmaengine_pcm_request_channel(dma_filter_fn filter_fn,
void *filter_data)
{
dma_cap_mask_t mask;
dma_cap_zero(mask);
dma_cap_set(DMA_SLAVE, mask);
dma_cap_set(DMA_CYCLIC, mask);
return dma_request_channel(mask, filter_fn, filter_data);
}
int snd_dmaengine_pcm_open(struct snd_pcm_substream *substream,
struct dma_chan *chan)
{
struct dmaengine_pcm_runtime_data *prtd;
int ret;
if (!chan)
return -ENXIO;
ret = snd_pcm_hw_constraint_integer(substream->runtime,
SNDRV_PCM_HW_PARAM_PERIODS);
if (ret < 0)
return ret;
prtd = kzalloc(sizeof(*prtd), GFP_KERNEL);
if (!prtd)
return -ENOMEM;
prtd->dma_chan = chan;
substream->runtime->private_data = prtd;
return 0;
}
int snd_dmaengine_pcm_open_request_chan(struct snd_pcm_substream *substream,
dma_filter_fn filter_fn, void *filter_data)
{
return snd_dmaengine_pcm_open(substream,
snd_dmaengine_pcm_request_channel(filter_fn, filter_data));
}
int snd_dmaengine_pcm_close(struct snd_pcm_substream *substream)
{
struct dmaengine_pcm_runtime_data *prtd = substream_to_prtd(substream);
kfree(prtd);
return 0;
}
int snd_dmaengine_pcm_close_release_chan(struct snd_pcm_substream *substream)
{
struct dmaengine_pcm_runtime_data *prtd = substream_to_prtd(substream);
dma_release_channel(prtd->dma_chan);
return snd_dmaengine_pcm_close(substream);
}
