static bool filter(struct dma_chan *chan, void *param)
{
if (!imx_dma_is_general_purpose(chan))
return false;
chan->private = param;
return true;
}
int imx_pcm_dma_init(struct platform_device *pdev, size_t size)
{
struct snd_dmaengine_pcm_config *config;
struct snd_pcm_hardware *pcm_hardware;
config = devm_kzalloc(&pdev->dev,
sizeof(struct snd_dmaengine_pcm_config), GFP_KERNEL);
*config = imx_dmaengine_pcm_config;
if (size)
config->prealloc_buffer_size = size;
pcm_hardware = devm_kzalloc(&pdev->dev,
sizeof(struct snd_pcm_hardware), GFP_KERNEL);
*pcm_hardware = imx_pcm_hardware;
if (size)
pcm_hardware->buffer_bytes_max = size;
config->pcm_hardware = pcm_hardware;
return devm_snd_dmaengine_pcm_register(&pdev->dev,
config,
SND_DMAENGINE_PCM_FLAG_COMPAT);
}
