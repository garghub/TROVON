static irqreturn_t uni_reader_irq_handler(int irq, void *dev_id)
{
irqreturn_t ret = IRQ_NONE;
struct uniperif *reader = dev_id;
unsigned int status;
if (reader->state == UNIPERIF_STATE_STOPPED) {
dev_warn(reader->dev, "unexpected IRQ ");
return IRQ_HANDLED;
}
status = GET_UNIPERIF_ITS(reader);
SET_UNIPERIF_ITS_BCLR(reader, status);
if (unlikely(status & UNIPERIF_ITS_FIFO_ERROR_MASK(reader))) {
dev_err(reader->dev, "FIFO error detected");
snd_pcm_stream_lock(reader->substream);
snd_pcm_stop(reader->substream, SNDRV_PCM_STATE_XRUN);
snd_pcm_stream_unlock(reader->substream);
return IRQ_HANDLED;
}
return ret;
}
static int uni_reader_prepare(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct sti_uniperiph_data *priv = snd_soc_dai_get_drvdata(dai);
struct uniperif *reader = priv->dai_data.uni;
struct snd_pcm_runtime *runtime = substream->runtime;
int transfer_size, trigger_limit;
int slot_width;
int count = 10;
if (reader->state != UNIPERIF_STATE_STOPPED) {
dev_err(reader->dev, "%s: invalid reader state %d", __func__,
reader->state);
return -EINVAL;
}
transfer_size = runtime->channels * UNIPERIF_FIFO_FRAMES;
if (reader->ver < SND_ST_UNIPERIF_VERSION_UNI_PLR_TOP_1_0)
trigger_limit = UNIPERIF_FIFO_SIZE - transfer_size;
else
trigger_limit = transfer_size;
if ((!trigger_limit % 2) ||
(trigger_limit != 1 && transfer_size % 2) ||
(trigger_limit > UNIPERIF_CONFIG_DMA_TRIG_LIMIT_MASK(reader))) {
dev_err(reader->dev, "invalid trigger limit %d", trigger_limit);
return -EINVAL;
}
SET_UNIPERIF_CONFIG_DMA_TRIG_LIMIT(reader, trigger_limit);
switch (reader->daifmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_IB_IF:
case SND_SOC_DAIFMT_NB_IF:
SET_UNIPERIF_I2S_FMT_LR_POL_HIG(reader);
break;
default:
SET_UNIPERIF_I2S_FMT_LR_POL_LOW(reader);
}
if ((reader->daifmt & SND_SOC_DAIFMT_FORMAT_MASK)
== SND_SOC_DAIFMT_I2S) {
slot_width = 32;
} else {
switch (runtime->format) {
case SNDRV_PCM_FORMAT_S16_LE:
slot_width = 16;
break;
default:
slot_width = 32;
break;
}
}
switch (slot_width) {
case 32:
SET_UNIPERIF_I2S_FMT_NBIT_32(reader);
SET_UNIPERIF_I2S_FMT_DATA_SIZE_32(reader);
break;
case 16:
SET_UNIPERIF_I2S_FMT_NBIT_16(reader);
SET_UNIPERIF_I2S_FMT_DATA_SIZE_16(reader);
break;
default:
dev_err(reader->dev, "subframe format not supported");
return -EINVAL;
}
switch (runtime->format) {
case SNDRV_PCM_FORMAT_S16_LE:
SET_UNIPERIF_CONFIG_MEM_FMT_16_16(reader);
break;
case SNDRV_PCM_FORMAT_S32_LE:
SET_UNIPERIF_CONFIG_MEM_FMT_16_0(reader);
break;
default:
dev_err(reader->dev, "format not supported");
return -EINVAL;
}
switch (reader->daifmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
SET_UNIPERIF_I2S_FMT_ALIGN_LEFT(reader);
SET_UNIPERIF_I2S_FMT_PADDING_I2S_MODE(reader);
break;
case SND_SOC_DAIFMT_LEFT_J:
SET_UNIPERIF_I2S_FMT_ALIGN_LEFT(reader);
SET_UNIPERIF_I2S_FMT_PADDING_SONY_MODE(reader);
break;
case SND_SOC_DAIFMT_RIGHT_J:
SET_UNIPERIF_I2S_FMT_ALIGN_RIGHT(reader);
SET_UNIPERIF_I2S_FMT_PADDING_SONY_MODE(reader);
break;
default:
dev_err(reader->dev, "format not supported");
return -EINVAL;
}
SET_UNIPERIF_I2S_FMT_ORDER_MSB(reader);
SET_UNIPERIF_I2S_FMT_SCLK_EDGE_RISING(reader);
if ((runtime->channels % 2) || (runtime->channels < 2) ||
(runtime->channels > 10)) {
dev_err(reader->dev, "%s: invalid nb of channels", __func__);
return -EINVAL;
}
SET_UNIPERIF_I2S_FMT_NUM_CH(reader, runtime->channels / 2);
SET_UNIPERIF_ITS_BCLR(reader, GET_UNIPERIF_ITS(reader));
SET_UNIPERIF_I2S_FMT_NO_OF_SAMPLES_TO_READ(reader, 0);
SET_UNIPERIF_ITM_BSET_DMA_ERROR(reader);
SET_UNIPERIF_ITM_BSET_FIFO_ERROR(reader);
SET_UNIPERIF_ITM_BSET_MEM_BLK_READ(reader);
if (reader->info->underflow_enabled) {
SET_UNIPERIF_ITM_BSET_UNDERFLOW_REC_DONE(reader);
SET_UNIPERIF_ITM_BSET_UNDERFLOW_REC_FAILED(reader);
}
SET_UNIPERIF_SOFT_RST_SOFT_RST(reader);
while (GET_UNIPERIF_SOFT_RST_SOFT_RST(reader)) {
udelay(5);
count--;
}
if (!count) {
dev_err(reader->dev, "Failed to reset uniperif");
return -EIO;
}
return 0;
}
static int uni_reader_start(struct uniperif *reader)
{
if (reader->state != UNIPERIF_STATE_STOPPED) {
dev_err(reader->dev, "%s: invalid reader state", __func__);
return -EINVAL;
}
SET_UNIPERIF_ITS_BCLR_FIFO_ERROR(reader);
SET_UNIPERIF_ITM_BSET_FIFO_ERROR(reader);
SET_UNIPERIF_CTRL_OPERATION_PCM_DATA(reader);
reader->state = UNIPERIF_STATE_STARTED;
return 0;
}
static int uni_reader_stop(struct uniperif *reader)
{
if (reader->state == UNIPERIF_STATE_STOPPED) {
dev_err(reader->dev, "%s: invalid reader state", __func__);
return -EINVAL;
}
SET_UNIPERIF_CTRL_OPERATION_OFF(reader);
SET_UNIPERIF_ITM_BCLR(reader, GET_UNIPERIF_ITM(reader));
reader->state = UNIPERIF_STATE_STOPPED;
return 0;
}
static int uni_reader_trigger(struct snd_pcm_substream *substream,
int cmd, struct snd_soc_dai *dai)
{
struct sti_uniperiph_data *priv = snd_soc_dai_get_drvdata(dai);
struct uniperif *reader = priv->dai_data.uni;
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
return uni_reader_start(reader);
case SNDRV_PCM_TRIGGER_STOP:
return uni_reader_stop(reader);
default:
return -EINVAL;
}
}
static void uni_reader_shutdown(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct sti_uniperiph_data *priv = snd_soc_dai_get_drvdata(dai);
struct uniperif *reader = priv->dai_data.uni;
if (reader->state != UNIPERIF_STATE_STOPPED) {
uni_reader_stop(reader);
}
}
static int uni_reader_parse_dt(struct platform_device *pdev,
struct uniperif *reader)
{
struct uniperif_info *info;
struct device_node *node = pdev->dev.of_node;
info = devm_kzalloc(&pdev->dev, sizeof(*info), GFP_KERNEL);
if (!info)
return -ENOMEM;
if (of_property_read_u32(node, "version", &reader->ver) ||
reader->ver == SND_ST_UNIPERIF_VERSION_UNKNOWN) {
dev_err(&pdev->dev, "Unknown uniperipheral version ");
return -EINVAL;
}
reader->info = info;
return 0;
}
int uni_reader_init(struct platform_device *pdev,
struct uniperif *reader)
{
int ret = 0;
reader->dev = &pdev->dev;
reader->state = UNIPERIF_STATE_STOPPED;
reader->hw = &uni_reader_pcm_hw;
reader->dai_ops = &uni_reader_dai_ops;
dev_err(reader->dev, "%s: enter\n", __func__);
ret = uni_reader_parse_dt(pdev, reader);
if (ret < 0) {
dev_err(reader->dev, "Failed to parse DeviceTree");
return ret;
}
ret = devm_request_irq(&pdev->dev, reader->irq,
uni_reader_irq_handler, IRQF_SHARED,
dev_name(&pdev->dev), reader);
if (ret < 0) {
dev_err(&pdev->dev, "Failed to request IRQ");
return -EBUSY;
}
return 0;
}
