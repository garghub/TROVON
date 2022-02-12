static struct cygnus_aio_port *cygnus_dai_get_dma_data(
struct snd_pcm_substream *substream)
{
struct snd_soc_pcm_runtime *soc_runtime = substream->private_data;
return snd_soc_dai_get_dma_data(soc_runtime->cpu_dai, substream);
}
static void ringbuf_set_initial(void __iomem *audio_io,
struct ringbuf_regs *p_rbuf,
bool is_playback,
u32 start,
u32 periodsize,
u32 bufsize)
{
u32 initial_rd;
u32 initial_wr;
u32 end;
u32 fmark_val;
p_rbuf->period_bytes = periodsize;
p_rbuf->buf_size = bufsize;
if (is_playback) {
initial_rd = start;
initial_wr = initial_rd ^ BIT(31);
} else {
initial_wr = start;
initial_rd = initial_wr;
}
end = start + bufsize - 1;
fmark_val = periodsize - PERIOD_BYTES_MIN;
writel(start, audio_io + p_rbuf->baseaddr);
writel(end, audio_io + p_rbuf->endaddr);
writel(fmark_val, audio_io + p_rbuf->fmark);
writel(initial_rd, audio_io + p_rbuf->rdaddr);
writel(initial_wr, audio_io + p_rbuf->wraddr);
}
static int configure_ringbuf_regs(struct snd_pcm_substream *substream)
{
struct cygnus_aio_port *aio;
struct ringbuf_regs *p_rbuf;
int status = 0;
aio = cygnus_dai_get_dma_data(substream);
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) {
p_rbuf = &aio->play_rb_regs;
switch (aio->portnum) {
case 0:
*p_rbuf = RINGBUF_REG_PLAYBACK(0);
break;
case 1:
*p_rbuf = RINGBUF_REG_PLAYBACK(2);
break;
case 2:
*p_rbuf = RINGBUF_REG_PLAYBACK(4);
break;
case 3:
*p_rbuf = RINGBUF_REG_PLAYBACK(6);
break;
default:
status = -EINVAL;
}
} else {
p_rbuf = &aio->capture_rb_regs;
switch (aio->portnum) {
case 0:
*p_rbuf = RINGBUF_REG_CAPTURE(0);
break;
case 1:
*p_rbuf = RINGBUF_REG_CAPTURE(2);
break;
case 2:
*p_rbuf = RINGBUF_REG_CAPTURE(4);
break;
default:
status = -EINVAL;
}
}
return status;
}
static struct ringbuf_regs *get_ringbuf(struct snd_pcm_substream *substream)
{
struct cygnus_aio_port *aio;
struct ringbuf_regs *p_rbuf = NULL;
aio = cygnus_dai_get_dma_data(substream);
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
p_rbuf = &aio->play_rb_regs;
else
p_rbuf = &aio->capture_rb_regs;
return p_rbuf;
}
static void enable_intr(struct snd_pcm_substream *substream)
{
struct cygnus_aio_port *aio;
u32 clear_mask;
aio = cygnus_dai_get_dma_data(substream);
clear_mask = BIT(aio->portnum);
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) {
writel(clear_mask, aio->cygaud->audio + ESR0_STATUS_CLR_OFFSET);
writel(clear_mask, aio->cygaud->audio + ESR1_STATUS_CLR_OFFSET);
writel(clear_mask, aio->cygaud->audio + ESR3_STATUS_CLR_OFFSET);
writel(clear_mask, aio->cygaud->audio + ESR0_MASK_CLR_OFFSET);
writel(clear_mask, aio->cygaud->audio + ESR1_MASK_CLR_OFFSET);
writel(clear_mask, aio->cygaud->audio + ESR3_MASK_CLR_OFFSET);
writel(ANY_PLAYBACK_IRQ,
aio->cygaud->audio + INTH_R5F_MASK_CLEAR_OFFSET);
} else {
writel(clear_mask, aio->cygaud->audio + ESR2_STATUS_CLR_OFFSET);
writel(clear_mask, aio->cygaud->audio + ESR4_STATUS_CLR_OFFSET);
writel(clear_mask, aio->cygaud->audio + ESR2_MASK_CLR_OFFSET);
writel(clear_mask, aio->cygaud->audio + ESR4_MASK_CLR_OFFSET);
writel(ANY_CAPTURE_IRQ,
aio->cygaud->audio + INTH_R5F_MASK_CLEAR_OFFSET);
}
}
static void disable_intr(struct snd_pcm_substream *substream)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct cygnus_aio_port *aio;
u32 set_mask;
aio = cygnus_dai_get_dma_data(substream);
dev_dbg(rtd->cpu_dai->dev, "%s on port %d\n", __func__, aio->portnum);
set_mask = BIT(aio->portnum);
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) {
writel(set_mask, aio->cygaud->audio + ESR0_MASK_SET_OFFSET);
writel(set_mask, aio->cygaud->audio + ESR1_MASK_SET_OFFSET);
writel(set_mask, aio->cygaud->audio + ESR3_MASK_SET_OFFSET);
} else {
writel(set_mask, aio->cygaud->audio + ESR2_MASK_SET_OFFSET);
writel(set_mask, aio->cygaud->audio + ESR4_MASK_SET_OFFSET);
}
}
static int cygnus_pcm_trigger(struct snd_pcm_substream *substream, int cmd)
{
int ret = 0;
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
case SNDRV_PCM_TRIGGER_RESUME:
enable_intr(substream);
break;
case SNDRV_PCM_TRIGGER_STOP:
case SNDRV_PCM_TRIGGER_SUSPEND:
disable_intr(substream);
break;
default:
ret = -EINVAL;
}
return ret;
}
static void cygnus_pcm_period_elapsed(struct snd_pcm_substream *substream)
{
struct cygnus_aio_port *aio;
struct ringbuf_regs *p_rbuf = NULL;
u32 regval;
aio = cygnus_dai_get_dma_data(substream);
p_rbuf = get_ringbuf(substream);
snd_pcm_period_elapsed(substream);
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) {
regval = readl(aio->cygaud->audio + p_rbuf->rdaddr);
regval = regval ^ BIT(31);
writel(regval, aio->cygaud->audio + p_rbuf->wraddr);
} else {
regval = readl(aio->cygaud->audio + p_rbuf->wraddr);
writel(regval, aio->cygaud->audio + p_rbuf->rdaddr);
}
}
static void handle_playback_irq(struct cygnus_audio *cygaud)
{
void __iomem *audio_io;
u32 port;
u32 esr_status0, esr_status1, esr_status3;
audio_io = cygaud->audio;
esr_status0 = readl(audio_io + ESR0_STATUS_OFFSET);
esr_status0 &= ~readl(audio_io + ESR0_MASK_STATUS_OFFSET);
esr_status1 = readl(audio_io + ESR1_STATUS_OFFSET);
esr_status1 &= ~readl(audio_io + ESR1_MASK_STATUS_OFFSET);
esr_status3 = readl(audio_io + ESR3_STATUS_OFFSET);
esr_status3 &= ~readl(audio_io + ESR3_MASK_STATUS_OFFSET);
for (port = 0; port < CYGNUS_MAX_PLAYBACK_PORTS; port++) {
u32 esrmask = BIT(port);
if ((esrmask & esr_status1) || (esrmask & esr_status0)) {
dev_dbg(cygaud->dev,
"Underrun: esr0=0x%x, esr1=0x%x esr3=0x%x\n",
esr_status0, esr_status1, esr_status3);
}
if (esrmask & esr_status3) {
struct snd_pcm_substream *playstr;
playstr = cygaud->portinfo[port].play_stream;
cygnus_pcm_period_elapsed(playstr);
}
}
writel(esr_status0, audio_io + ESR0_STATUS_CLR_OFFSET);
writel(esr_status1, audio_io + ESR1_STATUS_CLR_OFFSET);
writel(esr_status3, audio_io + ESR3_STATUS_CLR_OFFSET);
writel(esr_status3, audio_io + BF_REARM_FREE_MARK_OFFSET);
}
static void handle_capture_irq(struct cygnus_audio *cygaud)
{
void __iomem *audio_io;
u32 port;
u32 esr_status2, esr_status4;
audio_io = cygaud->audio;
esr_status2 = readl(audio_io + ESR2_STATUS_OFFSET);
esr_status2 &= ~readl(audio_io + ESR2_MASK_STATUS_OFFSET);
esr_status4 = readl(audio_io + ESR4_STATUS_OFFSET);
esr_status4 &= ~readl(audio_io + ESR4_MASK_STATUS_OFFSET);
for (port = 0; port < CYGNUS_MAX_CAPTURE_PORTS; port++) {
u32 esrmask = BIT(port);
if (esrmask & esr_status2)
dev_dbg(cygaud->dev,
"Overflow: esr2=0x%x\n", esr_status2);
if (esrmask & esr_status4) {
struct snd_pcm_substream *capstr;
capstr = cygaud->portinfo[port].capture_stream;
cygnus_pcm_period_elapsed(capstr);
}
}
writel(esr_status2, audio_io + ESR2_STATUS_CLR_OFFSET);
writel(esr_status4, audio_io + ESR4_STATUS_CLR_OFFSET);
writel(esr_status4, audio_io + BF_REARM_FULL_MARK_OFFSET);
}
static irqreturn_t cygnus_dma_irq(int irq, void *data)
{
u32 r5_status;
struct cygnus_audio *cygaud = data;
r5_status = readl(cygaud->audio + INTH_R5F_STATUS_OFFSET);
if (!(r5_status & (ANY_PLAYBACK_IRQ | ANY_CAPTURE_IRQ)))
return IRQ_NONE;
if (ANY_PLAYBACK_IRQ & r5_status) {
handle_playback_irq(cygaud);
writel(ANY_PLAYBACK_IRQ & r5_status,
cygaud->audio + INTH_R5F_CLEAR_OFFSET);
}
if (ANY_CAPTURE_IRQ & r5_status) {
handle_capture_irq(cygaud);
writel(ANY_CAPTURE_IRQ & r5_status,
cygaud->audio + INTH_R5F_CLEAR_OFFSET);
}
return IRQ_HANDLED;
}
static int cygnus_pcm_open(struct snd_pcm_substream *substream)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_pcm_runtime *runtime = substream->runtime;
struct cygnus_aio_port *aio;
int ret;
aio = cygnus_dai_get_dma_data(substream);
if (!aio)
return -ENODEV;
dev_dbg(rtd->cpu_dai->dev, "%s port %d\n", __func__, aio->portnum);
snd_soc_set_runtime_hwparams(substream, &cygnus_pcm_hw);
ret = snd_pcm_hw_constraint_step(runtime, 0,
SNDRV_PCM_HW_PARAM_PERIOD_BYTES, PERIOD_BYTES_MIN);
if (ret < 0)
return ret;
ret = snd_pcm_hw_constraint_step(runtime, 0,
SNDRV_PCM_HW_PARAM_BUFFER_BYTES, PERIOD_BYTES_MIN);
if (ret < 0)
return ret;
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
aio->play_stream = substream;
else
aio->capture_stream = substream;
return 0;
}
static int cygnus_pcm_close(struct snd_pcm_substream *substream)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct cygnus_aio_port *aio;
aio = cygnus_dai_get_dma_data(substream);
dev_dbg(rtd->cpu_dai->dev, "%s port %d\n", __func__, aio->portnum);
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
aio->play_stream = NULL;
else
aio->capture_stream = NULL;
if (!aio->play_stream && !aio->capture_stream)
dev_dbg(rtd->cpu_dai->dev, "freed port %d\n", aio->portnum);
return 0;
}
static int cygnus_pcm_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_pcm_runtime *runtime = substream->runtime;
struct cygnus_aio_port *aio;
int ret = 0;
aio = cygnus_dai_get_dma_data(substream);
dev_dbg(rtd->cpu_dai->dev, "%s port %d\n", __func__, aio->portnum);
snd_pcm_set_runtime_buffer(substream, &substream->dma_buffer);
runtime->dma_bytes = params_buffer_bytes(params);
return ret;
}
static int cygnus_pcm_hw_free(struct snd_pcm_substream *substream)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct cygnus_aio_port *aio;
aio = cygnus_dai_get_dma_data(substream);
dev_dbg(rtd->cpu_dai->dev, "%s port %d\n", __func__, aio->portnum);
snd_pcm_set_runtime_buffer(substream, NULL);
return 0;
}
static int cygnus_pcm_prepare(struct snd_pcm_substream *substream)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_pcm_runtime *runtime = substream->runtime;
struct cygnus_aio_port *aio;
unsigned long bufsize, periodsize;
int ret = 0;
bool is_play;
u32 start;
struct ringbuf_regs *p_rbuf = NULL;
aio = cygnus_dai_get_dma_data(substream);
dev_dbg(rtd->cpu_dai->dev, "%s port %d\n", __func__, aio->portnum);
bufsize = snd_pcm_lib_buffer_bytes(substream);
periodsize = snd_pcm_lib_period_bytes(substream);
dev_dbg(rtd->cpu_dai->dev, "%s (buf_size %lu) (period_size %lu)\n",
__func__, bufsize, periodsize);
configure_ringbuf_regs(substream);
p_rbuf = get_ringbuf(substream);
start = runtime->dma_addr;
is_play = (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) ? 1 : 0;
ringbuf_set_initial(aio->cygaud->audio, p_rbuf, is_play, start,
periodsize, bufsize);
return ret;
}
static snd_pcm_uframes_t cygnus_pcm_pointer(struct snd_pcm_substream *substream)
{
struct cygnus_aio_port *aio;
unsigned int res = 0, cur = 0, base = 0;
struct ringbuf_regs *p_rbuf = NULL;
aio = cygnus_dai_get_dma_data(substream);
p_rbuf = get_ringbuf(substream);
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
cur = readl(aio->cygaud->audio + p_rbuf->rdaddr);
else
cur = readl(aio->cygaud->audio + p_rbuf->wraddr);
base = readl(aio->cygaud->audio + p_rbuf->baseaddr);
res = (cur & 0x7fffffff) - (base & 0x7fffffff);
return bytes_to_frames(substream->runtime, res);
}
static int cygnus_pcm_preallocate_dma_buffer(struct snd_pcm *pcm, int stream)
{
struct snd_pcm_substream *substream = pcm->streams[stream].substream;
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_dma_buffer *buf = &substream->dma_buffer;
size_t size;
size = cygnus_pcm_hw.buffer_bytes_max;
buf->dev.type = SNDRV_DMA_TYPE_DEV;
buf->dev.dev = pcm->card->dev;
buf->private_data = NULL;
buf->area = dma_alloc_coherent(pcm->card->dev, size,
&buf->addr, GFP_KERNEL);
dev_dbg(rtd->cpu_dai->dev, "%s: size 0x%zx @ %pK\n",
__func__, size, buf->area);
if (!buf->area) {
dev_err(rtd->cpu_dai->dev, "%s: dma_alloc failed\n", __func__);
return -ENOMEM;
}
buf->bytes = size;
return 0;
}
static void cygnus_dma_free_dma_buffers(struct snd_pcm *pcm)
{
struct snd_pcm_substream *substream;
struct snd_dma_buffer *buf;
substream = pcm->streams[SNDRV_PCM_STREAM_PLAYBACK].substream;
if (substream) {
buf = &substream->dma_buffer;
if (buf->area) {
dma_free_coherent(pcm->card->dev, buf->bytes,
buf->area, buf->addr);
buf->area = NULL;
}
}
substream = pcm->streams[SNDRV_PCM_STREAM_CAPTURE].substream;
if (substream) {
buf = &substream->dma_buffer;
if (buf->area) {
dma_free_coherent(pcm->card->dev, buf->bytes,
buf->area, buf->addr);
buf->area = NULL;
}
}
}
static int cygnus_dma_new(struct snd_soc_pcm_runtime *rtd)
{
struct snd_card *card = rtd->card->snd_card;
struct snd_pcm *pcm = rtd->pcm;
int ret;
if (!card->dev->dma_mask)
card->dev->dma_mask = &cygnus_dma_dmamask;
if (!card->dev->coherent_dma_mask)
card->dev->coherent_dma_mask = DMA_BIT_MASK(32);
if (pcm->streams[SNDRV_PCM_STREAM_PLAYBACK].substream) {
ret = cygnus_pcm_preallocate_dma_buffer(pcm,
SNDRV_PCM_STREAM_PLAYBACK);
if (ret)
return ret;
}
if (pcm->streams[SNDRV_PCM_STREAM_CAPTURE].substream) {
ret = cygnus_pcm_preallocate_dma_buffer(pcm,
SNDRV_PCM_STREAM_CAPTURE);
if (ret) {
cygnus_dma_free_dma_buffers(pcm);
return ret;
}
}
return 0;
}
int cygnus_soc_platform_register(struct device *dev,
struct cygnus_audio *cygaud)
{
int rc = 0;
dev_dbg(dev, "%s Enter\n", __func__);
rc = devm_request_irq(dev, cygaud->irq_num, cygnus_dma_irq,
IRQF_SHARED, "cygnus-audio", cygaud);
if (rc) {
dev_err(dev, "%s request_irq error %d\n", __func__, rc);
return rc;
}
rc = snd_soc_register_platform(dev, &cygnus_soc_platform);
if (rc) {
dev_err(dev, "%s failed\n", __func__);
return rc;
}
return 0;
}
int cygnus_soc_platform_unregister(struct device *dev)
{
snd_soc_unregister_platform(dev);
return 0;
}
