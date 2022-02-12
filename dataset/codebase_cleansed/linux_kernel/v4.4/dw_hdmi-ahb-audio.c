static void dw_hdmi_writel(u32 val, void __iomem *ptr)
{
writeb_relaxed(val, ptr);
writeb_relaxed(val >> 8, ptr + 1);
writeb_relaxed(val >> 16, ptr + 2);
writeb_relaxed(val >> 24, ptr + 3);
}
static void dw_hdmi_reformat_iec958(struct snd_dw_hdmi *dw,
size_t offset, size_t bytes)
{
u32 *src = dw->buf_src + offset;
u32 *dst = dw->buf_dst + offset;
u32 *end = dw->buf_src + offset + bytes;
do {
u32 b, sample = *src++;
b = (sample & 8) << (28 - 3);
sample >>= 4;
*dst++ = sample | b;
} while (src < end);
}
static u32 parity(u32 sample)
{
sample ^= sample >> 16;
sample ^= sample >> 8;
sample ^= sample >> 4;
sample ^= sample >> 2;
sample ^= sample >> 1;
return (sample & 1) << 27;
}
static void dw_hdmi_reformat_s24(struct snd_dw_hdmi *dw,
size_t offset, size_t bytes)
{
u32 *src = dw->buf_src + offset;
u32 *dst = dw->buf_dst + offset;
u32 *end = dw->buf_src + offset + bytes;
do {
unsigned i;
u8 *cs;
cs = dw->cs[dw->iec_offset++];
if (dw->iec_offset >= 192)
dw->iec_offset = 0;
i = dw->channels;
do {
u32 sample = *src++;
sample &= ~0xff000000;
sample |= *cs++ << 24;
sample |= parity(sample & ~0xf8000000);
*dst++ = sample;
} while (--i);
} while (src < end);
}
static void dw_hdmi_create_cs(struct snd_dw_hdmi *dw,
struct snd_pcm_runtime *runtime)
{
u8 cs[4];
unsigned ch, i, j;
snd_pcm_create_iec958_consumer(runtime, cs, sizeof(cs));
memset(dw->cs, 0, sizeof(dw->cs));
for (ch = 0; ch < 8; ch++) {
cs[2] &= ~IEC958_AES2_CON_CHANNEL;
cs[2] |= (ch + 1) << 4;
for (i = 0; i < ARRAY_SIZE(cs); i++) {
unsigned c = cs[i];
for (j = 0; j < 8; j++, c >>= 1)
dw->cs[i * 8 + j][ch] = (c & 1) << 2;
}
}
dw->cs[0][0] |= BIT(4);
}
static void dw_hdmi_start_dma(struct snd_dw_hdmi *dw)
{
void __iomem *base = dw->data.base;
unsigned offset = dw->buf_offset;
unsigned period = dw->buf_period;
u32 start, stop;
dw->reformat(dw, offset, period);
writeb_relaxed(HDMI_IH_AHBDMAAUD_STAT0_ALL,
base + HDMI_IH_AHBDMAAUD_STAT0);
start = dw->buf_addr + offset;
stop = start + period - 1;
dw_hdmi_writel(start, base + HDMI_AHB_DMA_STRADDR0);
dw_hdmi_writel(stop, base + HDMI_AHB_DMA_STPADDR0);
writeb_relaxed((u8)~HDMI_AHB_DMA_MASK_DONE, base + HDMI_AHB_DMA_MASK);
writeb(HDMI_AHB_DMA_START_START, base + HDMI_AHB_DMA_START);
offset += period;
if (offset >= dw->buf_size)
offset = 0;
dw->buf_offset = offset;
}
static void dw_hdmi_stop_dma(struct snd_dw_hdmi *dw)
{
writeb_relaxed(~0, dw->data.base + HDMI_AHB_DMA_MASK);
writeb_relaxed(HDMI_AHB_DMA_STOP_STOP, dw->data.base + HDMI_AHB_DMA_STOP);
}
static irqreturn_t snd_dw_hdmi_irq(int irq, void *data)
{
struct snd_dw_hdmi *dw = data;
struct snd_pcm_substream *substream;
unsigned stat;
stat = readb_relaxed(dw->data.base + HDMI_IH_AHBDMAAUD_STAT0);
if (!stat)
return IRQ_NONE;
writeb_relaxed(stat, dw->data.base + HDMI_IH_AHBDMAAUD_STAT0);
substream = dw->substream;
if (stat & HDMI_IH_AHBDMAAUD_STAT0_DONE && substream) {
snd_pcm_period_elapsed(substream);
spin_lock(&dw->lock);
if (dw->substream)
dw_hdmi_start_dma(dw);
spin_unlock(&dw->lock);
}
return IRQ_HANDLED;
}
static int dw_hdmi_open(struct snd_pcm_substream *substream)
{
struct snd_pcm_runtime *runtime = substream->runtime;
struct snd_dw_hdmi *dw = substream->private_data;
void __iomem *base = dw->data.base;
int ret;
runtime->hw = dw_hdmi_hw;
ret = snd_pcm_hw_constraint_eld(runtime, dw->data.eld);
if (ret < 0)
return ret;
ret = snd_pcm_limit_hw_rates(runtime);
if (ret < 0)
return ret;
ret = snd_pcm_hw_constraint_integer(runtime,
SNDRV_PCM_HW_PARAM_PERIODS);
if (ret < 0)
return ret;
ret = snd_pcm_hw_constraint_minmax(runtime,
SNDRV_PCM_HW_PARAM_BUFFER_SIZE,
0, substream->dma_buffer.bytes);
if (ret < 0)
return ret;
writeb_relaxed(HDMI_AHB_DMA_CONF0_SW_FIFO_RST,
base + HDMI_AHB_DMA_CONF0);
writeb_relaxed(~0, base + HDMI_AHB_DMA_POL);
writeb_relaxed(~0, base + HDMI_AHB_DMA_BUFFPOL);
writeb_relaxed(~0, base + HDMI_AHB_DMA_MASK);
writeb_relaxed(~0, base + HDMI_IH_AHBDMAAUD_STAT0);
ret = request_irq(dw->data.irq, snd_dw_hdmi_irq, IRQF_SHARED,
"dw-hdmi-audio", dw);
if (ret)
return ret;
writeb_relaxed(HDMI_IH_MUTE_AHBDMAAUD_STAT0_ALL &
~HDMI_IH_MUTE_AHBDMAAUD_STAT0_DONE,
base + HDMI_IH_MUTE_AHBDMAAUD_STAT0);
return 0;
}
static int dw_hdmi_close(struct snd_pcm_substream *substream)
{
struct snd_dw_hdmi *dw = substream->private_data;
writeb_relaxed(HDMI_IH_MUTE_AHBDMAAUD_STAT0_ALL,
dw->data.base + HDMI_IH_MUTE_AHBDMAAUD_STAT0);
free_irq(dw->data.irq, dw);
return 0;
}
static int dw_hdmi_hw_free(struct snd_pcm_substream *substream)
{
return snd_pcm_lib_free_vmalloc_buffer(substream);
}
static int dw_hdmi_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
return snd_pcm_lib_alloc_vmalloc_buffer(substream,
params_buffer_bytes(params));
}
static int dw_hdmi_prepare(struct snd_pcm_substream *substream)
{
struct snd_pcm_runtime *runtime = substream->runtime;
struct snd_dw_hdmi *dw = substream->private_data;
u8 threshold, conf0, conf1, layout, ca;
switch (dw->revision) {
case 0x0a:
conf0 = HDMI_AHB_DMA_CONF0_BURST_MODE |
HDMI_AHB_DMA_CONF0_INCR4;
if (runtime->channels == 2)
threshold = 126;
else
threshold = 124;
break;
case 0x1a:
conf0 = HDMI_AHB_DMA_CONF0_BURST_MODE |
HDMI_AHB_DMA_CONF0_INCR8;
threshold = 128;
break;
default:
return -EINVAL;
}
dw_hdmi_set_sample_rate(dw->data.hdmi, runtime->rate);
runtime->hw.fifo_size = threshold * 32;
conf0 |= HDMI_AHB_DMA_CONF0_EN_HLOCK;
conf1 = default_hdmi_channel_config[runtime->channels - 2].conf1;
ca = default_hdmi_channel_config[runtime->channels - 2].ca;
if (runtime->channels > 2)
layout = HDMI_FC_AUDSCONF_LAYOUT1;
else
layout = HDMI_FC_AUDSCONF_LAYOUT0;
writeb_relaxed(threshold, dw->data.base + HDMI_AHB_DMA_THRSLD);
writeb_relaxed(conf0, dw->data.base + HDMI_AHB_DMA_CONF0);
writeb_relaxed(conf1, dw->data.base + HDMI_AHB_DMA_CONF1);
writeb_relaxed(layout, dw->data.base + HDMI_FC_AUDSCONF);
writeb_relaxed(ca, dw->data.base + HDMI_FC_AUDICONF2);
switch (runtime->format) {
case SNDRV_PCM_FORMAT_IEC958_SUBFRAME_LE:
dw->reformat = dw_hdmi_reformat_iec958;
break;
case SNDRV_PCM_FORMAT_S24_LE:
dw_hdmi_create_cs(dw, runtime);
dw->reformat = dw_hdmi_reformat_s24;
break;
}
dw->iec_offset = 0;
dw->channels = runtime->channels;
dw->buf_src = runtime->dma_area;
dw->buf_dst = substream->dma_buffer.area;
dw->buf_addr = substream->dma_buffer.addr;
dw->buf_period = snd_pcm_lib_period_bytes(substream);
dw->buf_size = snd_pcm_lib_buffer_bytes(substream);
return 0;
}
static int dw_hdmi_trigger(struct snd_pcm_substream *substream, int cmd)
{
struct snd_dw_hdmi *dw = substream->private_data;
unsigned long flags;
int ret = 0;
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
spin_lock_irqsave(&dw->lock, flags);
dw->buf_offset = 0;
dw->substream = substream;
dw_hdmi_start_dma(dw);
dw_hdmi_audio_enable(dw->data.hdmi);
spin_unlock_irqrestore(&dw->lock, flags);
substream->runtime->delay = substream->runtime->period_size;
break;
case SNDRV_PCM_TRIGGER_STOP:
spin_lock_irqsave(&dw->lock, flags);
dw->substream = NULL;
dw_hdmi_stop_dma(dw);
dw_hdmi_audio_disable(dw->data.hdmi);
spin_unlock_irqrestore(&dw->lock, flags);
break;
default:
ret = -EINVAL;
break;
}
return ret;
}
static snd_pcm_uframes_t dw_hdmi_pointer(struct snd_pcm_substream *substream)
{
struct snd_pcm_runtime *runtime = substream->runtime;
struct snd_dw_hdmi *dw = substream->private_data;
return bytes_to_frames(runtime, dw->buf_offset);
}
static int snd_dw_hdmi_probe(struct platform_device *pdev)
{
const struct dw_hdmi_audio_data *data = pdev->dev.platform_data;
struct device *dev = pdev->dev.parent;
struct snd_dw_hdmi *dw;
struct snd_card *card;
struct snd_pcm *pcm;
unsigned revision;
int ret;
writeb_relaxed(HDMI_IH_MUTE_AHBDMAAUD_STAT0_ALL,
data->base + HDMI_IH_MUTE_AHBDMAAUD_STAT0);
revision = readb_relaxed(data->base + HDMI_REVISION_ID);
if (revision != 0x0a && revision != 0x1a) {
dev_err(dev, "dw-hdmi-audio: unknown revision 0x%02x\n",
revision);
return -ENXIO;
}
ret = snd_card_new(dev, SNDRV_DEFAULT_IDX1, SNDRV_DEFAULT_STR1,
THIS_MODULE, sizeof(struct snd_dw_hdmi), &card);
if (ret < 0)
return ret;
strlcpy(card->driver, DRIVER_NAME, sizeof(card->driver));
strlcpy(card->shortname, "DW-HDMI", sizeof(card->shortname));
snprintf(card->longname, sizeof(card->longname),
"%s rev 0x%02x, irq %d", card->shortname, revision,
data->irq);
dw = card->private_data;
dw->card = card;
dw->data = *data;
dw->revision = revision;
spin_lock_init(&dw->lock);
ret = snd_pcm_new(card, "DW HDMI", 0, 1, 0, &pcm);
if (ret < 0)
goto err;
dw->pcm = pcm;
pcm->private_data = dw;
strlcpy(pcm->name, DRIVER_NAME, sizeof(pcm->name));
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_PLAYBACK, &snd_dw_hdmi_ops);
snd_pcm_lib_preallocate_pages_for_all(pcm, SNDRV_DMA_TYPE_DEV,
dev, 128 * 1024, 1024 * 1024);
ret = snd_card_register(card);
if (ret < 0)
goto err;
platform_set_drvdata(pdev, dw);
return 0;
err:
snd_card_free(card);
return ret;
}
static int snd_dw_hdmi_remove(struct platform_device *pdev)
{
struct snd_dw_hdmi *dw = platform_get_drvdata(pdev);
snd_card_free(dw->card);
return 0;
}
static int snd_dw_hdmi_suspend(struct device *dev)
{
struct snd_dw_hdmi *dw = dev_get_drvdata(dev);
snd_power_change_state(dw->card, SNDRV_CTL_POWER_D3cold);
snd_pcm_suspend_all(dw->pcm);
return 0;
}
static int snd_dw_hdmi_resume(struct device *dev)
{
struct snd_dw_hdmi *dw = dev_get_drvdata(dev);
snd_power_change_state(dw->card, SNDRV_CTL_POWER_D0);
return 0;
}
