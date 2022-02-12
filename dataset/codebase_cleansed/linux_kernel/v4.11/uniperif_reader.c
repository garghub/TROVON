static irqreturn_t uni_reader_irq_handler(int irq, void *dev_id)
{
irqreturn_t ret = IRQ_NONE;
struct uniperif *reader = dev_id;
unsigned int status;
spin_lock(&reader->irq_lock);
if (!reader->substream)
goto irq_spin_unlock;
snd_pcm_stream_lock(reader->substream);
if (reader->state == UNIPERIF_STATE_STOPPED) {
dev_warn(reader->dev, "unexpected IRQ\n");
goto stream_unlock;
}
status = GET_UNIPERIF_ITS(reader);
SET_UNIPERIF_ITS_BCLR(reader, status);
if (unlikely(status & UNIPERIF_ITS_FIFO_ERROR_MASK(reader))) {
dev_err(reader->dev, "FIFO error detected\n");
snd_pcm_stop(reader->substream, SNDRV_PCM_STATE_XRUN);
ret = IRQ_HANDLED;
}
stream_unlock:
snd_pcm_stream_unlock(reader->substream);
irq_spin_unlock:
spin_unlock(&reader->irq_lock);
return ret;
}
static int uni_reader_prepare_pcm(struct snd_pcm_runtime *runtime,
struct uniperif *reader)
{
int slot_width;
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
dev_err(reader->dev, "subframe format not supported\n");
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
dev_err(reader->dev, "format not supported\n");
return -EINVAL;
}
if ((runtime->channels % 2) || (runtime->channels < 2) ||
(runtime->channels > 10)) {
dev_err(reader->dev, "%s: invalid nb of channels\n", __func__);
return -EINVAL;
}
SET_UNIPERIF_I2S_FMT_NUM_CH(reader, runtime->channels / 2);
SET_UNIPERIF_I2S_FMT_ORDER_MSB(reader);
return 0;
}
static int uni_reader_prepare_tdm(struct snd_pcm_runtime *runtime,
struct uniperif *reader)
{
int frame_size;
unsigned int word_pos[4] = {
0x04060002, 0x0C0E080A, 0x14161012, 0x1C1E181A};
frame_size = sti_uniperiph_get_user_frame_size(runtime);
SET_UNIPERIF_CONFIG_MEM_FMT_16_0(reader);
SET_UNIPERIF_I2S_FMT_DATA_SIZE_32(reader);
SET_UNIPERIF_I2S_FMT_NUM_CH(reader, frame_size / 4 / 2);
SET_UNIPERIF_I2S_FMT_ORDER_MSB(reader);
SET_UNIPERIF_I2S_FMT_ALIGN_LEFT(reader);
SET_UNIPERIF_TDM_ENABLE_TDM_ENABLE(reader);
sti_uniperiph_get_tdm_word_pos(reader, word_pos);
SET_UNIPERIF_TDM_WORD_POS(reader, 1_2, word_pos[WORD_1_2]);
SET_UNIPERIF_TDM_WORD_POS(reader, 3_4, word_pos[WORD_3_4]);
SET_UNIPERIF_TDM_WORD_POS(reader, 5_6, word_pos[WORD_5_6]);
SET_UNIPERIF_TDM_WORD_POS(reader, 7_8, word_pos[WORD_7_8]);
return 0;
}
static int uni_reader_prepare(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct sti_uniperiph_data *priv = snd_soc_dai_get_drvdata(dai);
struct uniperif *reader = priv->dai_data.uni;
struct snd_pcm_runtime *runtime = substream->runtime;
int transfer_size, trigger_limit, ret;
if (reader->state != UNIPERIF_STATE_STOPPED) {
dev_err(reader->dev, "%s: invalid reader state %d\n", __func__,
reader->state);
return -EINVAL;
}
if (reader->type == SND_ST_UNIPERIF_TYPE_TDM) {
transfer_size =
sti_uniperiph_get_user_frame_size(runtime) / 4;
} else {
transfer_size = runtime->channels * UNIPERIF_FIFO_FRAMES;
}
if (reader->ver < SND_ST_UNIPERIF_VERSION_UNI_PLR_TOP_1_0)
trigger_limit = UNIPERIF_FIFO_SIZE - transfer_size;
else
trigger_limit = transfer_size;
if ((!trigger_limit % 2) ||
(trigger_limit != 1 && transfer_size % 2) ||
(trigger_limit > UNIPERIF_CONFIG_DMA_TRIG_LIMIT_MASK(reader))) {
dev_err(reader->dev, "invalid trigger limit %d\n",
trigger_limit);
return -EINVAL;
}
SET_UNIPERIF_CONFIG_DMA_TRIG_LIMIT(reader, trigger_limit);
if (UNIPERIF_TYPE_IS_TDM(reader))
ret = uni_reader_prepare_tdm(runtime, reader);
else
ret = uni_reader_prepare_pcm(runtime, reader);
if (ret)
return ret;
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
dev_err(reader->dev, "format not supported\n");
return -EINVAL;
}
switch (reader->daifmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
SET_UNIPERIF_I2S_FMT_LR_POL_LOW(reader);
SET_UNIPERIF_I2S_FMT_SCLK_EDGE_RISING(reader);
break;
case SND_SOC_DAIFMT_NB_IF:
SET_UNIPERIF_I2S_FMT_LR_POL_HIG(reader);
SET_UNIPERIF_I2S_FMT_SCLK_EDGE_RISING(reader);
break;
case SND_SOC_DAIFMT_IB_NF:
SET_UNIPERIF_I2S_FMT_LR_POL_LOW(reader);
SET_UNIPERIF_I2S_FMT_SCLK_EDGE_FALLING(reader);
break;
case SND_SOC_DAIFMT_IB_IF:
SET_UNIPERIF_I2S_FMT_LR_POL_HIG(reader);
SET_UNIPERIF_I2S_FMT_SCLK_EDGE_FALLING(reader);
break;
}
SET_UNIPERIF_ITS_BCLR(reader, GET_UNIPERIF_ITS(reader));
SET_UNIPERIF_I2S_FMT_NO_OF_SAMPLES_TO_READ(reader, 0);
SET_UNIPERIF_ITM_BSET_DMA_ERROR(reader);
SET_UNIPERIF_ITM_BSET_FIFO_ERROR(reader);
SET_UNIPERIF_ITM_BSET_MEM_BLK_READ(reader);
if (reader->underflow_enabled) {
SET_UNIPERIF_ITM_BSET_UNDERFLOW_REC_DONE(reader);
SET_UNIPERIF_ITM_BSET_UNDERFLOW_REC_FAILED(reader);
}
return sti_uniperiph_reset(reader);
}
static int uni_reader_start(struct uniperif *reader)
{
if (reader->state != UNIPERIF_STATE_STOPPED) {
dev_err(reader->dev, "%s: invalid reader state\n", __func__);
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
dev_err(reader->dev, "%s: invalid reader state\n", __func__);
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
static int uni_reader_startup(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct sti_uniperiph_data *priv = snd_soc_dai_get_drvdata(dai);
struct uniperif *reader = priv->dai_data.uni;
unsigned long flags;
int ret;
spin_lock_irqsave(&reader->irq_lock, flags);
reader->substream = substream;
spin_unlock_irqrestore(&reader->irq_lock, flags);
if (!UNIPERIF_TYPE_IS_TDM(reader))
return 0;
ret = snd_pcm_hw_rule_add(substream->runtime, 0,
SNDRV_PCM_HW_PARAM_CHANNELS,
sti_uniperiph_fix_tdm_chan,
reader, SNDRV_PCM_HW_PARAM_CHANNELS,
-1);
if (ret < 0)
return ret;
return snd_pcm_hw_rule_add(substream->runtime, 0,
SNDRV_PCM_HW_PARAM_FORMAT,
sti_uniperiph_fix_tdm_format,
reader, SNDRV_PCM_HW_PARAM_FORMAT,
-1);
}
static void uni_reader_shutdown(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct sti_uniperiph_data *priv = snd_soc_dai_get_drvdata(dai);
struct uniperif *reader = priv->dai_data.uni;
unsigned long flags;
spin_lock_irqsave(&reader->irq_lock, flags);
if (reader->state != UNIPERIF_STATE_STOPPED) {
uni_reader_stop(reader);
}
reader->substream = NULL;
spin_unlock_irqrestore(&reader->irq_lock, flags);
}
int uni_reader_init(struct platform_device *pdev,
struct uniperif *reader)
{
int ret = 0;
reader->dev = &pdev->dev;
reader->state = UNIPERIF_STATE_STOPPED;
reader->dai_ops = &uni_reader_dai_ops;
if (UNIPERIF_TYPE_IS_TDM(reader))
reader->hw = &uni_tdm_hw;
else
reader->hw = &uni_reader_pcm_hw;
ret = devm_request_irq(&pdev->dev, reader->irq,
uni_reader_irq_handler, IRQF_SHARED,
dev_name(&pdev->dev), reader);
if (ret < 0) {
dev_err(&pdev->dev, "Failed to request IRQ\n");
return -EBUSY;
}
spin_lock_init(&reader->irq_lock);
return 0;
}
