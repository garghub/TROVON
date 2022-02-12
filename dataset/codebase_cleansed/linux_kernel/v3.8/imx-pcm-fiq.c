static enum hrtimer_restart snd_hrtimer_callback(struct hrtimer *hrt)
{
struct imx_pcm_runtime_data *iprtd =
container_of(hrt, struct imx_pcm_runtime_data, hrt);
struct snd_pcm_substream *substream = iprtd->substream;
struct snd_pcm_runtime *runtime = substream->runtime;
struct pt_regs regs;
unsigned long delta;
if (!atomic_read(&iprtd->running))
return HRTIMER_NORESTART;
get_fiq_regs(&regs);
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
iprtd->offset = regs.ARM_r8 & 0xffff;
else
iprtd->offset = regs.ARM_r9 & 0xffff;
if (iprtd->offset >= iprtd->last_offset)
delta = iprtd->offset - iprtd->last_offset;
else
delta = runtime->buffer_size + iprtd->offset
- iprtd->last_offset;
if (delta >= iprtd->period) {
snd_pcm_period_elapsed(substream);
iprtd->last_offset = iprtd->offset;
}
hrtimer_forward_now(hrt, ns_to_ktime(iprtd->poll_time_ns));
return HRTIMER_RESTART;
}
static int snd_imx_pcm_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_pcm_runtime *runtime = substream->runtime;
struct imx_pcm_runtime_data *iprtd = runtime->private_data;
iprtd->size = params_buffer_bytes(params);
iprtd->periods = params_periods(params);
iprtd->period = params_period_bytes(params) ;
iprtd->offset = 0;
iprtd->last_offset = 0;
iprtd->poll_time_ns = 1000000000 / params_rate(params) *
params_period_size(params);
snd_pcm_set_runtime_buffer(substream, &substream->dma_buffer);
return 0;
}
static int snd_imx_pcm_prepare(struct snd_pcm_substream *substream)
{
struct snd_pcm_runtime *runtime = substream->runtime;
struct imx_pcm_runtime_data *iprtd = runtime->private_data;
struct pt_regs regs;
get_fiq_regs(&regs);
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
regs.ARM_r8 = (iprtd->period * iprtd->periods - 1) << 16;
else
regs.ARM_r9 = (iprtd->period * iprtd->periods - 1) << 16;
set_fiq_regs(&regs);
return 0;
}
static int snd_imx_pcm_trigger(struct snd_pcm_substream *substream, int cmd)
{
struct snd_pcm_runtime *runtime = substream->runtime;
struct imx_pcm_runtime_data *iprtd = runtime->private_data;
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
case SNDRV_PCM_TRIGGER_RESUME:
case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
atomic_set(&iprtd->running, 1);
hrtimer_start(&iprtd->hrt, ns_to_ktime(iprtd->poll_time_ns),
HRTIMER_MODE_REL);
if (++fiq_enable == 1)
enable_fiq(imx_pcm_fiq);
break;
case SNDRV_PCM_TRIGGER_STOP:
case SNDRV_PCM_TRIGGER_SUSPEND:
case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
atomic_set(&iprtd->running, 0);
if (--fiq_enable == 0)
disable_fiq(imx_pcm_fiq);
break;
default:
return -EINVAL;
}
return 0;
}
static snd_pcm_uframes_t snd_imx_pcm_pointer(struct snd_pcm_substream *substream)
{
struct snd_pcm_runtime *runtime = substream->runtime;
struct imx_pcm_runtime_data *iprtd = runtime->private_data;
return bytes_to_frames(substream->runtime, iprtd->offset);
}
static int snd_imx_open(struct snd_pcm_substream *substream)
{
struct snd_pcm_runtime *runtime = substream->runtime;
struct imx_pcm_runtime_data *iprtd;
int ret;
iprtd = kzalloc(sizeof(*iprtd), GFP_KERNEL);
if (iprtd == NULL)
return -ENOMEM;
runtime->private_data = iprtd;
iprtd->substream = substream;
atomic_set(&iprtd->running, 0);
hrtimer_init(&iprtd->hrt, CLOCK_MONOTONIC, HRTIMER_MODE_REL);
iprtd->hrt.function = snd_hrtimer_callback;
ret = snd_pcm_hw_constraint_integer(substream->runtime,
SNDRV_PCM_HW_PARAM_PERIODS);
if (ret < 0) {
kfree(iprtd);
return ret;
}
snd_soc_set_runtime_hwparams(substream, &snd_imx_hardware);
return 0;
}
static int snd_imx_close(struct snd_pcm_substream *substream)
{
struct snd_pcm_runtime *runtime = substream->runtime;
struct imx_pcm_runtime_data *iprtd = runtime->private_data;
hrtimer_cancel(&iprtd->hrt);
kfree(iprtd);
return 0;
}
static int imx_pcm_fiq_new(struct snd_soc_pcm_runtime *rtd)
{
struct snd_pcm *pcm = rtd->pcm;
struct snd_pcm_substream *substream;
int ret;
ret = imx_pcm_new(rtd);
if (ret)
return ret;
substream = pcm->streams[SNDRV_PCM_STREAM_PLAYBACK].substream;
if (substream) {
struct snd_dma_buffer *buf = &substream->dma_buffer;
imx_ssi_fiq_tx_buffer = (unsigned long)buf->area;
}
substream = pcm->streams[SNDRV_PCM_STREAM_CAPTURE].substream;
if (substream) {
struct snd_dma_buffer *buf = &substream->dma_buffer;
imx_ssi_fiq_rx_buffer = (unsigned long)buf->area;
}
set_fiq_handler(&imx_ssi_fiq_start,
&imx_ssi_fiq_end - &imx_ssi_fiq_start);
return 0;
}
static void imx_pcm_fiq_free(struct snd_pcm *pcm)
{
mxc_set_irq_fiq(ssi_irq, 0);
release_fiq(&fh);
imx_pcm_free(pcm);
}
int imx_pcm_fiq_init(struct platform_device *pdev)
{
struct imx_ssi *ssi = platform_get_drvdata(pdev);
int ret;
ret = claim_fiq(&fh);
if (ret) {
dev_err(&pdev->dev, "failed to claim fiq: %d", ret);
return ret;
}
mxc_set_irq_fiq(ssi->irq, 1);
ssi_irq = ssi->irq;
imx_pcm_fiq = ssi->irq;
imx_ssi_fiq_base = (unsigned long)ssi->base;
ssi->dma_params_tx.burstsize = 4;
ssi->dma_params_rx.burstsize = 6;
ret = snd_soc_register_platform(&pdev->dev, &imx_soc_platform_fiq);
if (ret)
goto failed_register;
return 0;
failed_register:
mxc_set_irq_fiq(ssi_irq, 0);
release_fiq(&fh);
return ret;
}
