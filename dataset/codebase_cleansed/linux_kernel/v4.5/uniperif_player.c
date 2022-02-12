static inline int reset_player(struct uniperif *player)
{
int count = 10;
if (player->ver < SND_ST_UNIPERIF_VERSION_UNI_PLR_TOP_1_0) {
while (GET_UNIPERIF_SOFT_RST_SOFT_RST(player) && count) {
udelay(5);
count--;
}
}
if (!count) {
dev_err(player->dev, "Failed to reset uniperif");
return -EIO;
}
return 0;
}
static irqreturn_t uni_player_irq_handler(int irq, void *dev_id)
{
irqreturn_t ret = IRQ_NONE;
struct uniperif *player = dev_id;
unsigned int status;
unsigned int tmp;
if (player->state == UNIPERIF_STATE_STOPPED) {
return IRQ_NONE;
}
status = GET_UNIPERIF_ITS(player);
SET_UNIPERIF_ITS_BCLR(player, status);
if (unlikely(status & UNIPERIF_ITS_FIFO_ERROR_MASK(player))) {
dev_err(player->dev, "FIFO underflow error detected");
if (player->info->underflow_enabled) {
player->state = UNIPERIF_STATE_UNDERFLOW;
} else {
SET_UNIPERIF_ITM_BCLR_FIFO_ERROR(player);
snd_pcm_stream_lock(player->substream);
snd_pcm_stop(player->substream, SNDRV_PCM_STATE_XRUN);
snd_pcm_stream_unlock(player->substream);
}
ret = IRQ_HANDLED;
}
if (unlikely(status & UNIPERIF_ITS_DMA_ERROR_MASK(player))) {
dev_err(player->dev, "DMA error detected");
SET_UNIPERIF_ITM_BCLR_DMA_ERROR(player);
snd_pcm_stream_lock(player->substream);
snd_pcm_stop(player->substream, SNDRV_PCM_STATE_XRUN);
snd_pcm_stream_unlock(player->substream);
ret = IRQ_HANDLED;
}
if (unlikely(status & UNIPERIF_ITM_UNDERFLOW_REC_DONE_MASK(player))) {
if (!player->info->underflow_enabled) {
dev_err(player->dev, "unexpected Underflow recovering");
return -EPERM;
}
tmp = GET_UNIPERIF_STATUS_1_UNDERFLOW_DURATION(player);
SET_UNIPERIF_BIT_CONTROL_CLR_UNDERFLOW_DURATION(player);
player->state = UNIPERIF_STATE_STARTED;
ret = IRQ_HANDLED;
}
if (unlikely(status &
UNIPERIF_ITM_UNDERFLOW_REC_FAILED_MASK(player))) {
dev_err(player->dev, "Underflow recovery failed");
snd_pcm_stream_lock(player->substream);
snd_pcm_stop(player->substream, SNDRV_PCM_STATE_XRUN);
snd_pcm_stream_unlock(player->substream);
ret = IRQ_HANDLED;
}
return ret;
}
static int uni_player_clk_set_rate(struct uniperif *player, unsigned long rate)
{
int rate_adjusted, rate_achieved, delta, ret;
int adjustment = player->clk_adj;
if (adjustment < 0) {
delta = -1;
adjustment = -adjustment;
} else {
delta = 1;
}
delta *= (int)div64_u64((uint64_t)rate *
(uint64_t)adjustment + 500000, 1000000);
rate_adjusted = rate + delta;
if (!rate_adjusted)
return -EINVAL;
ret = clk_set_rate(player->clk, rate_adjusted);
if (ret < 0)
return ret;
rate_achieved = clk_get_rate(player->clk);
if (!rate_achieved)
return -EINVAL;
delta = rate_achieved - rate;
if (delta < 0) {
delta = -delta;
adjustment = -1;
} else {
adjustment = 1;
}
adjustment *= (int)div64_u64((uint64_t)delta * 1000000 + rate / 2,
rate);
player->clk_adj = adjustment;
return 0;
}
static void uni_player_set_channel_status(struct uniperif *player,
struct snd_pcm_runtime *runtime)
{
int n;
unsigned int status;
mutex_lock(&player->ctrl_lock);
if (runtime) {
switch (runtime->rate) {
case 22050:
player->stream_settings.iec958.status[3] =
IEC958_AES3_CON_FS_22050;
break;
case 44100:
player->stream_settings.iec958.status[3] =
IEC958_AES3_CON_FS_44100;
break;
case 88200:
player->stream_settings.iec958.status[3] =
IEC958_AES3_CON_FS_88200;
break;
case 176400:
player->stream_settings.iec958.status[3] =
IEC958_AES3_CON_FS_176400;
break;
case 24000:
player->stream_settings.iec958.status[3] =
IEC958_AES3_CON_FS_24000;
break;
case 48000:
player->stream_settings.iec958.status[3] =
IEC958_AES3_CON_FS_48000;
break;
case 96000:
player->stream_settings.iec958.status[3] =
IEC958_AES3_CON_FS_96000;
break;
case 192000:
player->stream_settings.iec958.status[3] =
IEC958_AES3_CON_FS_192000;
break;
case 32000:
player->stream_settings.iec958.status[3] =
IEC958_AES3_CON_FS_32000;
break;
default:
player->stream_settings.iec958.status[3] =
IEC958_AES3_CON_FS_NOTID;
break;
}
}
if (player->stream_settings.iec958.status[0] & IEC958_AES0_NONAUDIO)
player->stream_settings.encoding_mode =
UNIPERIF_IEC958_ENCODING_MODE_ENCODED;
else
player->stream_settings.encoding_mode =
UNIPERIF_IEC958_ENCODING_MODE_PCM;
if (player->stream_settings.encoding_mode ==
UNIPERIF_IEC958_ENCODING_MODE_PCM)
SET_UNIPERIF_USER_VALIDITY_VALIDITY_LR(player, 0);
else
SET_UNIPERIF_USER_VALIDITY_VALIDITY_LR(player, 1);
for (n = 0; n < 6; ++n) {
status =
player->stream_settings.iec958.status[0 + (n * 4)] & 0xf;
status |=
player->stream_settings.iec958.status[1 + (n * 4)] << 8;
status |=
player->stream_settings.iec958.status[2 + (n * 4)] << 16;
status |=
player->stream_settings.iec958.status[3 + (n * 4)] << 24;
SET_UNIPERIF_CHANNEL_STA_REGN(player, n, status);
}
mutex_unlock(&player->ctrl_lock);
if (player->ver < SND_ST_UNIPERIF_VERSION_UNI_PLR_TOP_1_0)
SET_UNIPERIF_CONFIG_CHL_STS_UPDATE(player);
else
SET_UNIPERIF_BIT_CONTROL_CHL_STS_UPDATE(player);
}
static int uni_player_prepare_iec958(struct uniperif *player,
struct snd_pcm_runtime *runtime)
{
int clk_div;
clk_div = player->mclk / runtime->rate;
if ((clk_div % 128) || (clk_div <= 0)) {
dev_err(player->dev, "%s: invalid clk_div %d",
__func__, clk_div);
return -EINVAL;
}
switch (runtime->format) {
case SNDRV_PCM_FORMAT_S16_LE:
SET_UNIPERIF_CONFIG_MEM_FMT_16_16(player);
SET_UNIPERIF_I2S_FMT_NBIT_32(player);
SET_UNIPERIF_I2S_FMT_DATA_SIZE_16(player);
break;
case SNDRV_PCM_FORMAT_S32_LE:
SET_UNIPERIF_CONFIG_MEM_FMT_16_0(player);
SET_UNIPERIF_I2S_FMT_NBIT_32(player);
SET_UNIPERIF_I2S_FMT_DATA_SIZE_24(player);
break;
default:
dev_err(player->dev, "format not supported");
return -EINVAL;
}
SET_UNIPERIF_CONFIG_PARITY_CNTR_BY_HW(player);
SET_UNIPERIF_CONFIG_CHANNEL_STA_CNTR_BY_HW(player);
SET_UNIPERIF_CONFIG_USER_DAT_CNTR_BY_HW(player);
SET_UNIPERIF_CONFIG_VALIDITY_DAT_CNTR_BY_HW(player);
SET_UNIPERIF_CONFIG_SPDIF_SW_CTRL_DISABLE(player);
SET_UNIPERIF_CTRL_ZERO_STUFF_HW(player);
uni_player_set_channel_status(player, runtime);
SET_UNIPERIF_USER_VALIDITY_VALIDITY_LR(player, 0);
SET_UNIPERIF_CONFIG_ONE_BIT_AUD_DISABLE(player);
SET_UNIPERIF_CONFIG_REPEAT_CHL_STS_ENABLE(player);
SET_UNIPERIF_CONFIG_SUBFRAME_SEL_SUBF1_SUBF0(player);
SET_UNIPERIF_I2S_FMT_ORDER_MSB(player);
if (player->stream_settings.encoding_mode ==
UNIPERIF_IEC958_ENCODING_MODE_ENCODED)
SET_UNIPERIF_CTRL_EXIT_STBY_ON_EOBLOCK_ON(player);
else
SET_UNIPERIF_CTRL_EXIT_STBY_ON_EOBLOCK_OFF(player);
SET_UNIPERIF_I2S_FMT_NUM_CH(player, runtime->channels / 2);
SET_UNIPERIF_CTRL_ROUNDING_OFF(player);
SET_UNIPERIF_CTRL_DIVIDER(player, clk_div / 128);
SET_UNIPERIF_CTRL_SPDIF_LAT_OFF(player);
if (player->ver < SND_ST_UNIPERIF_VERSION_UNI_PLR_TOP_1_0)
SET_UNIPERIF_CTRL_SPDIF_FMT_OFF(player);
else
SET_UNIPERIF_CTRL_SPDIF_FMT_ON(player);
return 0;
}
static int uni_player_prepare_pcm(struct uniperif *player,
struct snd_pcm_runtime *runtime)
{
int output_frame_size, slot_width, clk_div;
if ((player->daifmt & SND_SOC_DAIFMT_FORMAT_MASK) ==
SND_SOC_DAIFMT_I2S) {
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
output_frame_size = slot_width * runtime->channels;
clk_div = player->mclk / runtime->rate;
if ((slot_width == 32) && (clk_div % 128)) {
dev_err(player->dev, "%s: invalid clk_div", __func__);
return -EINVAL;
}
if ((slot_width == 16) && (clk_div % 64)) {
dev_err(player->dev, "%s: invalid clk_div", __func__);
return -EINVAL;
}
switch (slot_width) {
case 32:
SET_UNIPERIF_I2S_FMT_NBIT_32(player);
SET_UNIPERIF_I2S_FMT_DATA_SIZE_32(player);
break;
case 16:
SET_UNIPERIF_I2S_FMT_NBIT_16(player);
SET_UNIPERIF_I2S_FMT_DATA_SIZE_16(player);
break;
default:
dev_err(player->dev, "subframe format not supported");
return -EINVAL;
}
switch (runtime->format) {
case SNDRV_PCM_FORMAT_S16_LE:
SET_UNIPERIF_CONFIG_MEM_FMT_16_16(player);
break;
case SNDRV_PCM_FORMAT_S32_LE:
SET_UNIPERIF_CONFIG_MEM_FMT_16_0(player);
break;
default:
dev_err(player->dev, "format not supported");
return -EINVAL;
}
SET_UNIPERIF_CTRL_ROUNDING_OFF(player);
SET_UNIPERIF_CTRL_DIVIDER(player, clk_div / (2 * output_frame_size));
if ((runtime->channels % 2) || (runtime->channels < 2) ||
(runtime->channels > 10)) {
dev_err(player->dev, "%s: invalid nb of channels", __func__);
return -EINVAL;
}
SET_UNIPERIF_I2S_FMT_NUM_CH(player, runtime->channels / 2);
SET_UNIPERIF_CONFIG_ONE_BIT_AUD_DISABLE(player);
SET_UNIPERIF_I2S_FMT_ORDER_MSB(player);
SET_UNIPERIF_I2S_FMT_SCLK_EDGE_FALLING(player);
SET_UNIPERIF_CTRL_SPDIF_FMT_OFF(player);
return 0;
}
static int uni_player_ctl_iec958_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_IEC958;
uinfo->count = 1;
return 0;
}
static int uni_player_ctl_iec958_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_dai *dai = snd_kcontrol_chip(kcontrol);
struct sti_uniperiph_data *priv = snd_soc_dai_get_drvdata(dai);
struct uniperif *player = priv->dai_data.uni;
struct snd_aes_iec958 *iec958 = &player->stream_settings.iec958;
mutex_lock(&player->ctrl_lock);
ucontrol->value.iec958.status[0] = iec958->status[0];
ucontrol->value.iec958.status[1] = iec958->status[1];
ucontrol->value.iec958.status[2] = iec958->status[2];
ucontrol->value.iec958.status[3] = iec958->status[3];
mutex_unlock(&player->ctrl_lock);
return 0;
}
static int uni_player_ctl_iec958_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_dai *dai = snd_kcontrol_chip(kcontrol);
struct sti_uniperiph_data *priv = snd_soc_dai_get_drvdata(dai);
struct uniperif *player = priv->dai_data.uni;
struct snd_aes_iec958 *iec958 = &player->stream_settings.iec958;
mutex_lock(&player->ctrl_lock);
iec958->status[0] = ucontrol->value.iec958.status[0];
iec958->status[1] = ucontrol->value.iec958.status[1];
iec958->status[2] = ucontrol->value.iec958.status[2];
iec958->status[3] = ucontrol->value.iec958.status[3];
mutex_unlock(&player->ctrl_lock);
uni_player_set_channel_status(player, NULL);
return 0;
}
static int snd_sti_clk_adjustment_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = 1;
uinfo->value.integer.min = UNIPERIF_PLAYER_CLK_ADJ_MIN;
uinfo->value.integer.max = UNIPERIF_PLAYER_CLK_ADJ_MAX;
uinfo->value.integer.step = 1;
return 0;
}
static int snd_sti_clk_adjustment_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_dai *dai = snd_kcontrol_chip(kcontrol);
struct sti_uniperiph_data *priv = snd_soc_dai_get_drvdata(dai);
struct uniperif *player = priv->dai_data.uni;
mutex_lock(&player->ctrl_lock);
ucontrol->value.integer.value[0] = player->clk_adj;
mutex_unlock(&player->ctrl_lock);
return 0;
}
static int snd_sti_clk_adjustment_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_dai *dai = snd_kcontrol_chip(kcontrol);
struct sti_uniperiph_data *priv = snd_soc_dai_get_drvdata(dai);
struct uniperif *player = priv->dai_data.uni;
int ret = 0;
if ((ucontrol->value.integer.value[0] < UNIPERIF_PLAYER_CLK_ADJ_MIN) ||
(ucontrol->value.integer.value[0] > UNIPERIF_PLAYER_CLK_ADJ_MAX))
return -EINVAL;
mutex_lock(&player->ctrl_lock);
player->clk_adj = ucontrol->value.integer.value[0];
if (player->mclk)
ret = uni_player_clk_set_rate(player, player->mclk);
mutex_unlock(&player->ctrl_lock);
return ret;
}
static int uni_player_startup(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct sti_uniperiph_data *priv = snd_soc_dai_get_drvdata(dai);
struct uniperif *player = priv->dai_data.uni;
player->substream = substream;
player->clk_adj = 0;
return 0;
}
static int uni_player_set_sysclk(struct snd_soc_dai *dai, int clk_id,
unsigned int freq, int dir)
{
struct sti_uniperiph_data *priv = snd_soc_dai_get_drvdata(dai);
struct uniperif *player = priv->dai_data.uni;
int ret;
if (dir == SND_SOC_CLOCK_IN)
return 0;
if (clk_id != 0)
return -EINVAL;
mutex_lock(&player->ctrl_lock);
ret = uni_player_clk_set_rate(player, freq);
if (!ret)
player->mclk = freq;
mutex_unlock(&player->ctrl_lock);
return ret;
}
static int uni_player_prepare(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct sti_uniperiph_data *priv = snd_soc_dai_get_drvdata(dai);
struct uniperif *player = priv->dai_data.uni;
struct snd_pcm_runtime *runtime = substream->runtime;
int transfer_size, trigger_limit;
int ret;
if (player->state != UNIPERIF_STATE_STOPPED) {
dev_err(player->dev, "%s: invalid player state %d", __func__,
player->state);
return -EINVAL;
}
transfer_size = runtime->channels * UNIPERIF_FIFO_FRAMES;
if (player->ver < SND_ST_UNIPERIF_VERSION_UNI_PLR_TOP_1_0) {
trigger_limit = UNIPERIF_FIFO_SIZE - transfer_size;
} else {
trigger_limit = transfer_size;
}
if ((!trigger_limit % 2) || (trigger_limit != 1 && transfer_size % 2) ||
(trigger_limit > UNIPERIF_CONFIG_DMA_TRIG_LIMIT_MASK(player))) {
dev_err(player->dev, "invalid trigger limit %d", trigger_limit);
return -EINVAL;
}
SET_UNIPERIF_CONFIG_DMA_TRIG_LIMIT(player, trigger_limit);
switch (player->info->player_type) {
case SND_ST_UNIPERIF_PLAYER_TYPE_HDMI:
ret = uni_player_prepare_iec958(player, runtime);
break;
case SND_ST_UNIPERIF_PLAYER_TYPE_PCM:
ret = uni_player_prepare_pcm(player, runtime);
break;
case SND_ST_UNIPERIF_PLAYER_TYPE_SPDIF:
ret = uni_player_prepare_iec958(player, runtime);
break;
default:
dev_err(player->dev, "invalid player type");
return -EINVAL;
}
if (ret)
return ret;
switch (player->daifmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
SET_UNIPERIF_I2S_FMT_LR_POL_LOW(player);
SET_UNIPERIF_I2S_FMT_SCLK_EDGE_RISING(player);
break;
case SND_SOC_DAIFMT_NB_IF:
SET_UNIPERIF_I2S_FMT_LR_POL_HIG(player);
SET_UNIPERIF_I2S_FMT_SCLK_EDGE_RISING(player);
break;
case SND_SOC_DAIFMT_IB_NF:
SET_UNIPERIF_I2S_FMT_LR_POL_LOW(player);
SET_UNIPERIF_I2S_FMT_SCLK_EDGE_FALLING(player);
break;
case SND_SOC_DAIFMT_IB_IF:
SET_UNIPERIF_I2S_FMT_LR_POL_HIG(player);
SET_UNIPERIF_I2S_FMT_SCLK_EDGE_FALLING(player);
break;
}
switch (player->daifmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
SET_UNIPERIF_I2S_FMT_ALIGN_LEFT(player);
SET_UNIPERIF_I2S_FMT_PADDING_I2S_MODE(player);
break;
case SND_SOC_DAIFMT_LEFT_J:
SET_UNIPERIF_I2S_FMT_ALIGN_LEFT(player);
SET_UNIPERIF_I2S_FMT_PADDING_SONY_MODE(player);
break;
case SND_SOC_DAIFMT_RIGHT_J:
SET_UNIPERIF_I2S_FMT_ALIGN_RIGHT(player);
SET_UNIPERIF_I2S_FMT_PADDING_SONY_MODE(player);
break;
default:
dev_err(player->dev, "format not supported");
return -EINVAL;
}
SET_UNIPERIF_I2S_FMT_NO_OF_SAMPLES_TO_READ(player, 0);
SET_UNIPERIF_SOFT_RST_SOFT_RST(player);
return reset_player(player);
}
static int uni_player_start(struct uniperif *player)
{
int ret;
if (player->state != UNIPERIF_STATE_STOPPED) {
dev_err(player->dev, "%s: invalid player state", __func__);
return -EINVAL;
}
ret = clk_prepare_enable(player->clk);
if (ret) {
dev_err(player->dev, "%s: Failed to enable clock", __func__);
return ret;
}
SET_UNIPERIF_ITS_BCLR(player, GET_UNIPERIF_ITS(player));
SET_UNIPERIF_ITM_BSET_DMA_ERROR(player);
SET_UNIPERIF_ITM_BSET_FIFO_ERROR(player);
if (player->info->underflow_enabled) {
SET_UNIPERIF_ITM_BSET_UNDERFLOW_REC_DONE(player);
SET_UNIPERIF_ITM_BSET_UNDERFLOW_REC_FAILED(player);
}
SET_UNIPERIF_SOFT_RST_SOFT_RST(player);
ret = reset_player(player);
if (ret < 0)
return ret;
SET_UNIPERIF_CTRL_OPERATION_PCM_DATA(player);
if (player->ver < SND_ST_UNIPERIF_VERSION_UNI_PLR_TOP_1_0)
if (UNIPERIF_PLAYER_TYPE_IS_IEC958(player))
SET_UNIPERIF_CTRL_SPDIF_FMT_ON(player);
if (player->ver < SND_ST_UNIPERIF_VERSION_UNI_PLR_TOP_1_0)
SET_UNIPERIF_CONFIG_CHL_STS_UPDATE(player);
else
SET_UNIPERIF_BIT_CONTROL_CHL_STS_UPDATE(player);
player->state = UNIPERIF_STATE_STARTED;
return 0;
}
static int uni_player_stop(struct uniperif *player)
{
int ret;
if (player->state == UNIPERIF_STATE_STOPPED) {
dev_err(player->dev, "%s: invalid player state", __func__);
return -EINVAL;
}
SET_UNIPERIF_CTRL_OPERATION_OFF(player);
SET_UNIPERIF_SOFT_RST_SOFT_RST(player);
ret = reset_player(player);
if (ret < 0)
return ret;
SET_UNIPERIF_ITM_BCLR(player, GET_UNIPERIF_ITM(player));
clk_disable_unprepare(player->clk);
player->state = UNIPERIF_STATE_STOPPED;
return 0;
}
int uni_player_resume(struct uniperif *player)
{
int ret;
if (player->clk_sel) {
ret = regmap_field_write(player->clk_sel, 1);
if (ret) {
dev_err(player->dev,
"%s: Failed to select freq synth clock",
__func__);
return ret;
}
}
SET_UNIPERIF_CONFIG_BACK_STALL_REQ_DISABLE(player);
SET_UNIPERIF_CTRL_ROUNDING_OFF(player);
SET_UNIPERIF_CTRL_SPDIF_LAT_OFF(player);
SET_UNIPERIF_CONFIG_IDLE_MOD_DISABLE(player);
return 0;
}
static int uni_player_trigger(struct snd_pcm_substream *substream,
int cmd, struct snd_soc_dai *dai)
{
struct sti_uniperiph_data *priv = snd_soc_dai_get_drvdata(dai);
struct uniperif *player = priv->dai_data.uni;
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
return uni_player_start(player);
case SNDRV_PCM_TRIGGER_STOP:
return uni_player_stop(player);
case SNDRV_PCM_TRIGGER_RESUME:
return uni_player_resume(player);
default:
return -EINVAL;
}
}
static void uni_player_shutdown(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct sti_uniperiph_data *priv = snd_soc_dai_get_drvdata(dai);
struct uniperif *player = priv->dai_data.uni;
if (player->state != UNIPERIF_STATE_STOPPED)
uni_player_stop(player);
player->substream = NULL;
}
static int uni_player_parse_dt_clk_glue(struct platform_device *pdev,
struct uniperif *player)
{
int bit_offset;
struct device_node *node = pdev->dev.of_node;
struct regmap *regmap;
bit_offset = SYS_CFG_AUDI0_GLUE_PCM_CLKX + player->info->id;
regmap = syscon_regmap_lookup_by_phandle(node, "st,syscfg");
if (regmap) {
struct reg_field regfield =
REG_FIELD(SYS_CFG_AUDIO_GLUE, bit_offset, bit_offset);
player->clk_sel = regmap_field_alloc(regmap, regfield);
} else {
dev_err(&pdev->dev, "sti-audio-clk-glue syscf not found\n");
return -EINVAL;
}
return 0;
}
static int uni_player_parse_dt(struct platform_device *pdev,
struct uniperif *player)
{
struct uniperif_info *info;
struct device *dev = &pdev->dev;
struct device_node *pnode = pdev->dev.of_node;
const char *mode;
info = devm_kzalloc(dev, sizeof(*info), GFP_KERNEL);
if (!info)
return -ENOMEM;
if (of_property_read_u32(pnode, "st,version", &player->ver) ||
player->ver == SND_ST_UNIPERIF_VERSION_UNKNOWN) {
dev_err(dev, "Unknown uniperipheral version ");
return -EINVAL;
}
if (player->ver >= SND_ST_UNIPERIF_VERSION_UNI_PLR_TOP_1_0)
info->underflow_enabled = 1;
if (of_property_read_u32(pnode, "st,uniperiph-id", &info->id)) {
dev_err(dev, "uniperipheral id not defined");
return -EINVAL;
}
if (of_property_read_string(pnode, "st,mode", &mode)) {
dev_err(dev, "uniperipheral mode not defined");
return -EINVAL;
}
if (strcasecmp(mode, "hdmi") == 0)
info->player_type = SND_ST_UNIPERIF_PLAYER_TYPE_HDMI;
else if (strcasecmp(mode, "pcm") == 0)
info->player_type = SND_ST_UNIPERIF_PLAYER_TYPE_PCM;
else if (strcasecmp(mode, "spdif") == 0)
info->player_type = SND_ST_UNIPERIF_PLAYER_TYPE_SPDIF;
else
info->player_type = SND_ST_UNIPERIF_PLAYER_TYPE_NONE;
player->info = info;
if (uni_player_parse_dt_clk_glue(pdev, player))
return -EINVAL;
return 0;
}
int uni_player_init(struct platform_device *pdev,
struct uniperif *player)
{
int ret = 0;
player->dev = &pdev->dev;
player->state = UNIPERIF_STATE_STOPPED;
player->hw = &uni_player_pcm_hw;
player->dai_ops = &uni_player_dai_ops;
ret = uni_player_parse_dt(pdev, player);
if (ret < 0) {
dev_err(player->dev, "Failed to parse DeviceTree");
return ret;
}
player->clk = of_clk_get(pdev->dev.of_node, 0);
if (IS_ERR(player->clk))
ret = PTR_ERR(player->clk);
if (player->clk_sel) {
ret = regmap_field_write(player->clk_sel, 1);
if (ret) {
dev_err(player->dev,
"%s: Failed to select freq synth clock",
__func__);
return ret;
}
}
ret = devm_request_irq(&pdev->dev, player->irq,
uni_player_irq_handler, IRQF_SHARED,
dev_name(&pdev->dev), player);
if (ret < 0)
return ret;
mutex_init(&player->ctrl_lock);
SET_UNIPERIF_CONFIG_BACK_STALL_REQ_DISABLE(player);
SET_UNIPERIF_CTRL_ROUNDING_OFF(player);
SET_UNIPERIF_CTRL_SPDIF_LAT_OFF(player);
SET_UNIPERIF_CONFIG_IDLE_MOD_DISABLE(player);
if (UNIPERIF_PLAYER_TYPE_IS_IEC958(player)) {
player->stream_settings.iec958.status[0] = 0x00;
player->stream_settings.iec958.status[1] =
IEC958_AES1_CON_GENERAL;
player->stream_settings.iec958.status[2] =
IEC958_AES2_CON_SOURCE_UNSPEC;
player->stream_settings.iec958.status[3] =
IEC958_AES3_CON_FS_NOTID;
player->stream_settings.iec958.status[4] =
IEC958_AES4_CON_MAX_WORDLEN_24 |
IEC958_AES4_CON_WORDLEN_24_20;
player->num_ctrls = ARRAY_SIZE(snd_sti_iec_ctl);
player->snd_ctrls = snd_sti_iec_ctl[0];
} else {
player->num_ctrls = ARRAY_SIZE(snd_sti_pcm_ctl);
player->snd_ctrls = snd_sti_pcm_ctl[0];
}
return 0;
}
