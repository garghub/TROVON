static int mt2701_dai_num_to_i2s(struct mtk_base_afe *afe, int num)
{
int val = num - MT2701_IO_I2S;
if (val < 0 || val >= MT2701_I2S_NUM) {
dev_err(afe->dev, "%s, num not available, num %d, val %d\n",
__func__, num, val);
return -EINVAL;
}
return val;
}
static int mt2701_afe_i2s_fs(unsigned int sample_rate)
{
int i;
for (i = 0; i < ARRAY_SIZE(mt2701_afe_i2s_rates); i++)
if (mt2701_afe_i2s_rates[i].rate == sample_rate)
return mt2701_afe_i2s_rates[i].regvalue;
return -EINVAL;
}
static int mt2701_afe_i2s_startup(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct mtk_base_afe *afe = snd_soc_platform_get_drvdata(rtd->platform);
struct mt2701_afe_private *afe_priv = afe->platform_priv;
int i2s_num = mt2701_dai_num_to_i2s(afe, dai->id);
int clk_num = MT2701_AUD_AUD_I2S1_MCLK + i2s_num;
int ret = 0;
if (i2s_num < 0)
return i2s_num;
ret = clk_prepare_enable(afe_priv->clocks[clk_num]);
if (ret)
dev_err(afe->dev, "Failed to enable mclk for I2S: %d\n",
i2s_num);
return ret;
}
static int mt2701_afe_i2s_path_shutdown(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai,
int dir_invert)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct mtk_base_afe *afe = snd_soc_platform_get_drvdata(rtd->platform);
struct mt2701_afe_private *afe_priv = afe->platform_priv;
int i2s_num = mt2701_dai_num_to_i2s(afe, dai->id);
struct mt2701_i2s_path *i2s_path;
const struct mt2701_i2s_data *i2s_data;
int stream_dir = substream->stream;
if (i2s_num < 0)
return i2s_num;
i2s_path = &afe_priv->i2s_path[i2s_num];
if (dir_invert) {
if (stream_dir == SNDRV_PCM_STREAM_PLAYBACK)
stream_dir = SNDRV_PCM_STREAM_CAPTURE;
else
stream_dir = SNDRV_PCM_STREAM_PLAYBACK;
}
i2s_data = i2s_path->i2s_data[stream_dir];
i2s_path->on[stream_dir]--;
if (i2s_path->on[stream_dir] < 0) {
dev_warn(afe->dev, "i2s_path->on: %d, dir: %d\n",
i2s_path->on[stream_dir], stream_dir);
i2s_path->on[stream_dir] = 0;
}
if (i2s_path->on[stream_dir])
return 0;
regmap_update_bits(afe->regmap, i2s_data->i2s_ctrl_reg,
ASYS_I2S_CON_I2S_EN, 0);
regmap_update_bits(afe->regmap, AUDIO_TOP_CON4,
1 << i2s_data->i2s_pwn_shift,
1 << i2s_data->i2s_pwn_shift);
return 0;
}
static void mt2701_afe_i2s_shutdown(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct mtk_base_afe *afe = snd_soc_platform_get_drvdata(rtd->platform);
struct mt2701_afe_private *afe_priv = afe->platform_priv;
int i2s_num = mt2701_dai_num_to_i2s(afe, dai->id);
struct mt2701_i2s_path *i2s_path;
int clk_num = MT2701_AUD_AUD_I2S1_MCLK + i2s_num;
if (i2s_num < 0)
return;
i2s_path = &afe_priv->i2s_path[i2s_num];
if (i2s_path->occupied[substream->stream])
i2s_path->occupied[substream->stream] = 0;
else
goto I2S_UNSTART;
mt2701_afe_i2s_path_shutdown(substream, dai, 0);
if (substream->stream == SNDRV_PCM_STREAM_CAPTURE)
mt2701_afe_i2s_path_shutdown(substream, dai, 1);
I2S_UNSTART:
clk_disable_unprepare(afe_priv->clocks[clk_num]);
}
static int mt2701_i2s_path_prepare_enable(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai,
int dir_invert)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct mtk_base_afe *afe = snd_soc_platform_get_drvdata(rtd->platform);
struct mt2701_afe_private *afe_priv = afe->platform_priv;
int i2s_num = mt2701_dai_num_to_i2s(afe, dai->id);
struct mt2701_i2s_path *i2s_path;
const struct mt2701_i2s_data *i2s_data;
struct snd_pcm_runtime * const runtime = substream->runtime;
int reg, fs, w_len = 1;
int stream_dir = substream->stream;
unsigned int mask = 0, val = 0;
if (i2s_num < 0)
return i2s_num;
i2s_path = &afe_priv->i2s_path[i2s_num];
if (dir_invert) {
if (stream_dir == SNDRV_PCM_STREAM_PLAYBACK)
stream_dir = SNDRV_PCM_STREAM_CAPTURE;
else
stream_dir = SNDRV_PCM_STREAM_PLAYBACK;
}
i2s_data = i2s_path->i2s_data[stream_dir];
i2s_path->on[stream_dir]++;
if (i2s_path->on[stream_dir] != 1)
return 0;
fs = mt2701_afe_i2s_fs(runtime->rate);
mask = ASYS_I2S_CON_FS |
ASYS_I2S_CON_I2S_COUPLE_MODE |
ASYS_I2S_CON_I2S_MODE |
ASYS_I2S_CON_WIDE_MODE;
val = ASYS_I2S_CON_FS_SET(fs) |
ASYS_I2S_CON_I2S_MODE |
ASYS_I2S_CON_WIDE_MODE_SET(w_len);
if (stream_dir == SNDRV_PCM_STREAM_CAPTURE) {
mask |= ASYS_I2S_IN_PHASE_FIX;
val |= ASYS_I2S_IN_PHASE_FIX;
}
regmap_update_bits(afe->regmap, i2s_data->i2s_ctrl_reg, mask, val);
if (stream_dir == SNDRV_PCM_STREAM_PLAYBACK)
reg = ASMO_TIMING_CON1;
else
reg = ASMI_TIMING_CON1;
regmap_update_bits(afe->regmap, reg,
i2s_data->i2s_asrc_fs_mask
<< i2s_data->i2s_asrc_fs_shift,
fs << i2s_data->i2s_asrc_fs_shift);
regmap_update_bits(afe->regmap, AUDIO_TOP_CON4,
1 << i2s_data->i2s_pwn_shift,
0 << i2s_data->i2s_pwn_shift);
regmap_update_bits(afe->regmap, i2s_data->i2s_ctrl_reg,
ASYS_I2S_CON_RESET, ASYS_I2S_CON_RESET);
udelay(1);
regmap_update_bits(afe->regmap, i2s_data->i2s_ctrl_reg,
ASYS_I2S_CON_RESET, 0);
udelay(1);
regmap_update_bits(afe->regmap, i2s_data->i2s_ctrl_reg,
ASYS_I2S_CON_I2S_EN, ASYS_I2S_CON_I2S_EN);
return 0;
}
static int mt2701_afe_i2s_prepare(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
int clk_domain;
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct mtk_base_afe *afe = snd_soc_platform_get_drvdata(rtd->platform);
struct mt2701_afe_private *afe_priv = afe->platform_priv;
int i2s_num = mt2701_dai_num_to_i2s(afe, dai->id);
struct mt2701_i2s_path *i2s_path;
int mclk_rate;
if (i2s_num < 0)
return i2s_num;
i2s_path = &afe_priv->i2s_path[i2s_num];
mclk_rate = i2s_path->mclk_rate;
if (i2s_path->occupied[substream->stream])
return -EBUSY;
i2s_path->occupied[substream->stream] = 1;
if (MT2701_PLL_DOMAIN_0_RATE % mclk_rate == 0) {
clk_domain = 0;
} else if (MT2701_PLL_DOMAIN_1_RATE % mclk_rate == 0) {
clk_domain = 1;
} else {
dev_err(dai->dev, "%s() bad mclk rate %d\n",
__func__, mclk_rate);
return -EINVAL;
}
mt2701_mclk_configuration(afe, i2s_num, clk_domain, mclk_rate);
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) {
mt2701_i2s_path_prepare_enable(substream, dai, 0);
} else {
mt2701_i2s_path_prepare_enable(substream, dai, 1);
mt2701_i2s_path_prepare_enable(substream, dai, 0);
}
return 0;
}
static int mt2701_afe_i2s_set_sysclk(struct snd_soc_dai *dai, int clk_id,
unsigned int freq, int dir)
{
struct mtk_base_afe *afe = dev_get_drvdata(dai->dev);
struct mt2701_afe_private *afe_priv = afe->platform_priv;
int i2s_num = mt2701_dai_num_to_i2s(afe, dai->id);
if (i2s_num < 0)
return i2s_num;
if (dir == SND_SOC_CLOCK_IN) {
dev_warn(dai->dev,
"%s() warning: mt2701 doesn't support mclk input\n",
__func__);
return -EINVAL;
}
afe_priv->i2s_path[i2s_num].mclk_rate = freq;
return 0;
}
static int mt2701_btmrg_startup(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct mtk_base_afe *afe = snd_soc_platform_get_drvdata(rtd->platform);
struct mt2701_afe_private *afe_priv = afe->platform_priv;
regmap_update_bits(afe->regmap, AUDIO_TOP_CON4,
AUDIO_TOP_CON4_PDN_MRGIF, 0);
afe_priv->mrg_enable[substream->stream] = 1;
return 0;
}
static int mt2701_btmrg_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct mtk_base_afe *afe = snd_soc_platform_get_drvdata(rtd->platform);
int stream_fs;
u32 val, msk;
stream_fs = params_rate(params);
if ((stream_fs != 8000) && (stream_fs != 16000)) {
dev_err(afe->dev, "%s() btmgr not supprt this stream_fs %d\n",
__func__, stream_fs);
return -EINVAL;
}
regmap_update_bits(afe->regmap, AFE_MRGIF_CON,
AFE_MRGIF_CON_I2S_MODE_MASK,
AFE_MRGIF_CON_I2S_MODE_32K);
val = AFE_DAIBT_CON0_BT_FUNC_EN | AFE_DAIBT_CON0_BT_FUNC_RDY
| AFE_DAIBT_CON0_MRG_USE;
msk = val;
if (stream_fs == 16000)
val |= AFE_DAIBT_CON0_BT_WIDE_MODE_EN;
msk |= AFE_DAIBT_CON0_BT_WIDE_MODE_EN;
regmap_update_bits(afe->regmap, AFE_DAIBT_CON0, msk, val);
regmap_update_bits(afe->regmap, AFE_DAIBT_CON0,
AFE_DAIBT_CON0_DAIBT_EN,
AFE_DAIBT_CON0_DAIBT_EN);
regmap_update_bits(afe->regmap, AFE_MRGIF_CON,
AFE_MRGIF_CON_MRG_I2S_EN,
AFE_MRGIF_CON_MRG_I2S_EN);
regmap_update_bits(afe->regmap, AFE_MRGIF_CON,
AFE_MRGIF_CON_MRG_EN,
AFE_MRGIF_CON_MRG_EN);
return 0;
}
static void mt2701_btmrg_shutdown(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct mtk_base_afe *afe = snd_soc_platform_get_drvdata(rtd->platform);
struct mt2701_afe_private *afe_priv = afe->platform_priv;
if (!afe_priv->mrg_enable[!substream->stream]) {
regmap_update_bits(afe->regmap, AFE_DAIBT_CON0,
AFE_DAIBT_CON0_DAIBT_EN, 0);
regmap_update_bits(afe->regmap, AFE_MRGIF_CON,
AFE_MRGIF_CON_MRG_EN, 0);
regmap_update_bits(afe->regmap, AFE_MRGIF_CON,
AFE_MRGIF_CON_MRG_I2S_EN, 0);
regmap_update_bits(afe->regmap, AUDIO_TOP_CON4,
AUDIO_TOP_CON4_PDN_MRGIF,
AUDIO_TOP_CON4_PDN_MRGIF);
}
afe_priv->mrg_enable[substream->stream] = 0;
}
static int mt2701_simple_fe_startup(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct mtk_base_afe *afe = snd_soc_platform_get_drvdata(rtd->platform);
int stream_dir = substream->stream;
int memif_num = rtd->cpu_dai->id;
struct mtk_base_afe_memif *memif_tmp;
if (stream_dir == SNDRV_PCM_STREAM_PLAYBACK) {
memif_tmp = &afe->memif[MT2701_MEMIF_DLM];
if (memif_tmp->substream) {
dev_warn(afe->dev, "%s memif is not available, stream_dir %d, memif_num %d\n",
__func__, stream_dir, memif_num);
return -EBUSY;
}
}
return mtk_afe_fe_startup(substream, dai);
}
static int mt2701_simple_fe_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct mtk_base_afe *afe = snd_soc_platform_get_drvdata(rtd->platform);
int stream_dir = substream->stream;
if (stream_dir == SNDRV_PCM_STREAM_PLAYBACK) {
regmap_update_bits(afe->regmap,
AFE_MEMIF_PBUF_SIZE,
AFE_MEMIF_PBUF_SIZE_DLM_MASK,
AFE_MEMIF_PBUF_SIZE_PAIR_INTERLEAVE);
}
return mtk_afe_fe_hw_params(substream, params, dai);
}
static int mt2701_dlm_fe_startup(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct mtk_base_afe *afe = snd_soc_platform_get_drvdata(rtd->platform);
struct mtk_base_afe_memif *memif_tmp;
const struct mtk_base_memif_data *memif_data;
int i;
for (i = MT2701_MEMIF_DL1; i < MT2701_MEMIF_DL_SINGLE_NUM; ++i) {
memif_tmp = &afe->memif[i];
if (memif_tmp->substream)
return -EBUSY;
}
for (i = MT2701_MEMIF_DL1; i < MT2701_MEMIF_DL_SINGLE_NUM; ++i) {
memif_data = afe->memif[i].data;
regmap_update_bits(afe->regmap,
memif_data->agent_disable_reg,
1 << memif_data->agent_disable_shift,
0 << memif_data->agent_disable_shift);
}
return mtk_afe_fe_startup(substream, dai);
}
static void mt2701_dlm_fe_shutdown(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct mtk_base_afe *afe = snd_soc_platform_get_drvdata(rtd->platform);
const struct mtk_base_memif_data *memif_data;
int i;
for (i = MT2701_MEMIF_DL1; i < MT2701_MEMIF_DL_SINGLE_NUM; ++i) {
memif_data = afe->memif[i].data;
regmap_update_bits(afe->regmap,
memif_data->agent_disable_reg,
1 << memif_data->agent_disable_shift,
1 << memif_data->agent_disable_shift);
}
return mtk_afe_fe_shutdown(substream, dai);
}
static int mt2701_dlm_fe_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct mtk_base_afe *afe = snd_soc_platform_get_drvdata(rtd->platform);
int channels = params_channels(params);
regmap_update_bits(afe->regmap,
AFE_MEMIF_PBUF_SIZE,
AFE_MEMIF_PBUF_SIZE_DLM_MASK,
AFE_MEMIF_PBUF_SIZE_FULL_INTERLEAVE);
regmap_update_bits(afe->regmap,
AFE_MEMIF_PBUF_SIZE,
AFE_MEMIF_PBUF_SIZE_DLM_BYTE_MASK,
AFE_MEMIF_PBUF_SIZE_DLM_32BYTES);
regmap_update_bits(afe->regmap,
AFE_MEMIF_PBUF_SIZE,
AFE_MEMIF_PBUF_SIZE_DLM_CH_MASK,
AFE_MEMIF_PBUF_SIZE_DLM_CH(channels));
return mtk_afe_fe_hw_params(substream, params, dai);
}
static int mt2701_dlm_fe_trigger(struct snd_pcm_substream *substream,
int cmd, struct snd_soc_dai *dai)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct mtk_base_afe *afe = snd_soc_platform_get_drvdata(rtd->platform);
struct mtk_base_afe_memif *memif_tmp = &afe->memif[MT2701_MEMIF_DL1];
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
case SNDRV_PCM_TRIGGER_RESUME:
regmap_update_bits(afe->regmap, memif_tmp->data->enable_reg,
1 << memif_tmp->data->enable_shift,
1 << memif_tmp->data->enable_shift);
mtk_afe_fe_trigger(substream, cmd, dai);
return 0;
case SNDRV_PCM_TRIGGER_STOP:
case SNDRV_PCM_TRIGGER_SUSPEND:
mtk_afe_fe_trigger(substream, cmd, dai);
regmap_update_bits(afe->regmap, memif_tmp->data->enable_reg,
1 << memif_tmp->data->enable_shift, 0);
return 0;
default:
return -EINVAL;
}
}
static int mt2701_memif_fs(struct snd_pcm_substream *substream,
unsigned int rate)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
int fs;
if (rtd->cpu_dai->id != MT2701_MEMIF_ULBT)
fs = mt2701_afe_i2s_fs(rate);
else
fs = (rate == 16000 ? 1 : 0);
return fs;
}
static int mt2701_irq_fs(struct snd_pcm_substream *substream, unsigned int rate)
{
return mt2701_afe_i2s_fs(rate);
}
static irqreturn_t mt2701_asys_isr(int irq_id, void *dev)
{
int id;
struct mtk_base_afe *afe = dev;
struct mtk_base_afe_memif *memif;
struct mtk_base_afe_irq *irq;
u32 status;
regmap_read(afe->regmap, ASYS_IRQ_STATUS, &status);
regmap_write(afe->regmap, ASYS_IRQ_CLR, status);
for (id = 0; id < MT2701_MEMIF_NUM; ++id) {
memif = &afe->memif[id];
if (memif->irq_usage < 0)
continue;
irq = &afe->irqs[memif->irq_usage];
if (status & 1 << (irq->irq_data->irq_clr_shift))
snd_pcm_period_elapsed(memif->substream);
}
return IRQ_HANDLED;
}
static int mt2701_afe_runtime_suspend(struct device *dev)
{
struct mtk_base_afe *afe = dev_get_drvdata(dev);
mt2701_afe_disable_clock(afe);
return 0;
}
static int mt2701_afe_runtime_resume(struct device *dev)
{
struct mtk_base_afe *afe = dev_get_drvdata(dev);
return mt2701_afe_enable_clock(afe);
}
static int mt2701_afe_pcm_dev_probe(struct platform_device *pdev)
{
int ret, i;
unsigned int irq_id;
struct mtk_base_afe *afe;
struct mt2701_afe_private *afe_priv;
struct resource *res;
struct device *dev;
ret = 0;
afe = devm_kzalloc(&pdev->dev, sizeof(*afe), GFP_KERNEL);
if (!afe)
return -ENOMEM;
afe->platform_priv = devm_kzalloc(&pdev->dev, sizeof(*afe_priv),
GFP_KERNEL);
if (!afe->platform_priv)
return -ENOMEM;
afe_priv = afe->platform_priv;
afe->dev = &pdev->dev;
dev = afe->dev;
irq_id = platform_get_irq(pdev, 0);
if (!irq_id) {
dev_err(dev, "%s no irq found\n", dev->of_node->name);
return -ENXIO;
}
ret = devm_request_irq(dev, irq_id, mt2701_asys_isr,
IRQF_TRIGGER_NONE, "asys-isr", (void *)afe);
if (ret) {
dev_err(dev, "could not request_irq for asys-isr\n");
return ret;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
afe->base_addr = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(afe->base_addr))
return PTR_ERR(afe->base_addr);
afe->regmap = devm_regmap_init_mmio(&pdev->dev, afe->base_addr,
&mt2701_afe_regmap_config);
if (IS_ERR(afe->regmap))
return PTR_ERR(afe->regmap);
mutex_init(&afe->irq_alloc_lock);
afe->memif_size = MT2701_MEMIF_NUM;
afe->memif = devm_kcalloc(dev, afe->memif_size, sizeof(*afe->memif),
GFP_KERNEL);
if (!afe->memif)
return -ENOMEM;
for (i = 0; i < afe->memif_size; i++) {
afe->memif[i].data = &memif_data[i];
afe->memif[i].irq_usage = -1;
}
afe->irqs_size = MT2701_IRQ_ASYS_END;
afe->irqs = devm_kcalloc(dev, afe->irqs_size, sizeof(*afe->irqs),
GFP_KERNEL);
if (!afe->irqs)
return -ENOMEM;
for (i = 0; i < afe->irqs_size; i++)
afe->irqs[i].irq_data = &irq_data[i];
for (i = 0; i < MT2701_I2S_NUM; i++) {
afe_priv->i2s_path[i].i2s_data[I2S_OUT]
= &mt2701_i2s_data[i][I2S_OUT];
afe_priv->i2s_path[i].i2s_data[I2S_IN]
= &mt2701_i2s_data[i][I2S_IN];
}
afe->mtk_afe_hardware = &mt2701_afe_hardware;
afe->memif_fs = mt2701_memif_fs;
afe->irq_fs = mt2701_irq_fs;
afe->reg_back_up_list = mt2701_afe_backup_list;
afe->reg_back_up_list_num = ARRAY_SIZE(mt2701_afe_backup_list);
afe->runtime_resume = mt2701_afe_runtime_resume;
afe->runtime_suspend = mt2701_afe_runtime_suspend;
ret = mt2701_init_clock(afe);
if (ret) {
dev_err(dev, "init clock error\n");
return ret;
}
platform_set_drvdata(pdev, afe);
pm_runtime_enable(&pdev->dev);
if (!pm_runtime_enabled(&pdev->dev))
goto err_pm_disable;
pm_runtime_get_sync(&pdev->dev);
ret = snd_soc_register_platform(&pdev->dev, &mtk_afe_pcm_platform);
if (ret) {
dev_warn(dev, "err_platform\n");
goto err_platform;
}
ret = snd_soc_register_component(&pdev->dev,
&mt2701_afe_pcm_dai_component,
mt2701_afe_pcm_dais,
ARRAY_SIZE(mt2701_afe_pcm_dais));
if (ret) {
dev_warn(dev, "err_dai_component\n");
goto err_dai_component;
}
mt2701_afe_runtime_resume(&pdev->dev);
return 0;
err_dai_component:
snd_soc_unregister_component(&pdev->dev);
err_platform:
snd_soc_unregister_platform(&pdev->dev);
err_pm_disable:
pm_runtime_disable(&pdev->dev);
return ret;
}
static int mt2701_afe_pcm_dev_remove(struct platform_device *pdev)
{
struct mtk_base_afe *afe = platform_get_drvdata(pdev);
pm_runtime_disable(&pdev->dev);
if (!pm_runtime_status_suspended(&pdev->dev))
mt2701_afe_runtime_suspend(&pdev->dev);
pm_runtime_put_sync(&pdev->dev);
snd_soc_unregister_component(&pdev->dev);
snd_soc_unregister_platform(&pdev->dev);
mt2701_afe_disable_clock(afe);
return 0;
}
