static int mt8173_afe_i2s_fs(unsigned int sample_rate)
{
int i;
for (i = 0; i < ARRAY_SIZE(mt8173_afe_i2s_rates); i++)
if (mt8173_afe_i2s_rates[i].rate == sample_rate)
return mt8173_afe_i2s_rates[i].regvalue;
return -EINVAL;
}
static int mt8173_afe_set_i2s(struct mtk_base_afe *afe, unsigned int rate)
{
unsigned int val;
int fs = mt8173_afe_i2s_fs(rate);
if (fs < 0)
return -EINVAL;
regmap_update_bits(afe->regmap, AFE_ADDA_TOP_CON0, 0x1, 0x1);
regmap_update_bits(afe->regmap, AFE_ADDA2_TOP_CON0, 0x1, 0x1);
val = AFE_I2S_CON2_LOW_JITTER_CLK |
AFE_I2S_CON2_RATE(fs) |
AFE_I2S_CON2_FORMAT_I2S;
regmap_update_bits(afe->regmap, AFE_I2S_CON2, ~AFE_I2S_CON2_EN, val);
val = AFE_I2S_CON1_LOW_JITTER_CLK |
AFE_I2S_CON1_RATE(fs) |
AFE_I2S_CON1_FORMAT_I2S;
regmap_update_bits(afe->regmap, AFE_I2S_CON1, ~AFE_I2S_CON1_EN, val);
return 0;
}
static void mt8173_afe_set_i2s_enable(struct mtk_base_afe *afe, bool enable)
{
unsigned int val;
regmap_read(afe->regmap, AFE_I2S_CON2, &val);
if (!!(val & AFE_I2S_CON2_EN) == enable)
return;
regmap_update_bits(afe->regmap, AFE_I2S_CON2, 0x1, enable);
regmap_update_bits(afe->regmap, AFE_I2S_CON1, 0x1, enable);
}
static int mt8173_afe_dais_enable_clks(struct mtk_base_afe *afe,
struct clk *m_ck, struct clk *b_ck)
{
int ret;
if (m_ck) {
ret = clk_prepare_enable(m_ck);
if (ret) {
dev_err(afe->dev, "Failed to enable m_ck\n");
return ret;
}
}
if (b_ck) {
ret = clk_prepare_enable(b_ck);
if (ret) {
dev_err(afe->dev, "Failed to enable b_ck\n");
return ret;
}
}
return 0;
}
static int mt8173_afe_dais_set_clks(struct mtk_base_afe *afe,
struct clk *m_ck, unsigned int mck_rate,
struct clk *b_ck, unsigned int bck_rate)
{
int ret;
if (m_ck) {
ret = clk_set_rate(m_ck, mck_rate);
if (ret) {
dev_err(afe->dev, "Failed to set m_ck rate\n");
return ret;
}
}
if (b_ck) {
ret = clk_set_rate(b_ck, bck_rate);
if (ret) {
dev_err(afe->dev, "Failed to set b_ck rate\n");
return ret;
}
}
return 0;
}
static void mt8173_afe_dais_disable_clks(struct mtk_base_afe *afe,
struct clk *m_ck, struct clk *b_ck)
{
if (m_ck)
clk_disable_unprepare(m_ck);
if (b_ck)
clk_disable_unprepare(b_ck);
}
static int mt8173_afe_i2s_startup(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct mtk_base_afe *afe = snd_soc_platform_get_drvdata(rtd->platform);
if (dai->active)
return 0;
regmap_update_bits(afe->regmap, AUDIO_TOP_CON0,
AUD_TCON0_PDN_22M | AUD_TCON0_PDN_24M, 0);
return 0;
}
static void mt8173_afe_i2s_shutdown(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct mtk_base_afe *afe = snd_soc_platform_get_drvdata(rtd->platform);
if (dai->active)
return;
mt8173_afe_set_i2s_enable(afe, false);
regmap_update_bits(afe->regmap, AUDIO_TOP_CON0,
AUD_TCON0_PDN_22M | AUD_TCON0_PDN_24M,
AUD_TCON0_PDN_22M | AUD_TCON0_PDN_24M);
}
static int mt8173_afe_i2s_prepare(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_pcm_runtime * const runtime = substream->runtime;
struct mtk_base_afe *afe = snd_soc_platform_get_drvdata(rtd->platform);
struct mt8173_afe_private *afe_priv = afe->platform_priv;
int ret;
mt8173_afe_dais_set_clks(afe, afe_priv->clocks[MT8173_CLK_I2S1_M],
runtime->rate * 256, NULL, 0);
mt8173_afe_dais_set_clks(afe, afe_priv->clocks[MT8173_CLK_I2S2_M],
runtime->rate * 256, NULL, 0);
ret = mt8173_afe_set_i2s(afe, substream->runtime->rate);
if (ret)
return ret;
mt8173_afe_set_i2s_enable(afe, true);
return 0;
}
static int mt8173_afe_hdmi_startup(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct mtk_base_afe *afe = snd_soc_platform_get_drvdata(rtd->platform);
struct mt8173_afe_private *afe_priv = afe->platform_priv;
if (dai->active)
return 0;
mt8173_afe_dais_enable_clks(afe, afe_priv->clocks[MT8173_CLK_I2S3_M],
afe_priv->clocks[MT8173_CLK_I2S3_B]);
return 0;
}
static void mt8173_afe_hdmi_shutdown(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct mtk_base_afe *afe = snd_soc_platform_get_drvdata(rtd->platform);
struct mt8173_afe_private *afe_priv = afe->platform_priv;
if (dai->active)
return;
mt8173_afe_dais_disable_clks(afe, afe_priv->clocks[MT8173_CLK_I2S3_M],
afe_priv->clocks[MT8173_CLK_I2S3_B]);
}
static int mt8173_afe_hdmi_prepare(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_pcm_runtime * const runtime = substream->runtime;
struct mtk_base_afe *afe = snd_soc_platform_get_drvdata(rtd->platform);
struct mt8173_afe_private *afe_priv = afe->platform_priv;
unsigned int val;
mt8173_afe_dais_set_clks(afe, afe_priv->clocks[MT8173_CLK_I2S3_M],
runtime->rate * 128,
afe_priv->clocks[MT8173_CLK_I2S3_B],
runtime->rate * runtime->channels * 32);
val = AFE_TDM_CON1_BCK_INV |
AFE_TDM_CON1_LRCK_INV |
AFE_TDM_CON1_1_BCK_DELAY |
AFE_TDM_CON1_MSB_ALIGNED |
AFE_TDM_CON1_WLEN_32BIT |
AFE_TDM_CON1_32_BCK_CYCLES |
AFE_TDM_CON1_LRCK_WIDTH(32);
regmap_update_bits(afe->regmap, AFE_TDM_CON1, ~AFE_TDM_CON1_EN, val);
switch (runtime->channels) {
case 1:
case 2:
val = AFE_TDM_CH_START_O30_O31;
val |= (AFE_TDM_CH_ZERO << 4);
val |= (AFE_TDM_CH_ZERO << 8);
val |= (AFE_TDM_CH_ZERO << 12);
break;
case 3:
case 4:
val = AFE_TDM_CH_START_O30_O31;
val |= (AFE_TDM_CH_START_O32_O33 << 4);
val |= (AFE_TDM_CH_ZERO << 8);
val |= (AFE_TDM_CH_ZERO << 12);
break;
case 5:
case 6:
val = AFE_TDM_CH_START_O30_O31;
val |= (AFE_TDM_CH_START_O32_O33 << 4);
val |= (AFE_TDM_CH_START_O34_O35 << 8);
val |= (AFE_TDM_CH_ZERO << 12);
break;
case 7:
case 8:
val = AFE_TDM_CH_START_O30_O31;
val |= (AFE_TDM_CH_START_O32_O33 << 4);
val |= (AFE_TDM_CH_START_O34_O35 << 8);
val |= (AFE_TDM_CH_START_O36_O37 << 12);
break;
default:
val = 0;
}
regmap_update_bits(afe->regmap, AFE_TDM_CON2, 0x0000ffff, val);
regmap_update_bits(afe->regmap, AFE_HDMI_OUT_CON0,
0x000000f0, runtime->channels << 4);
return 0;
}
static int mt8173_afe_hdmi_trigger(struct snd_pcm_substream *substream, int cmd,
struct snd_soc_dai *dai)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct mtk_base_afe *afe = snd_soc_platform_get_drvdata(rtd->platform);
dev_info(afe->dev, "%s cmd=%d %s\n", __func__, cmd, dai->name);
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
case SNDRV_PCM_TRIGGER_RESUME:
regmap_update_bits(afe->regmap, AUDIO_TOP_CON0,
AUD_TCON0_PDN_HDMI | AUD_TCON0_PDN_SPDF, 0);
regmap_write(afe->regmap, AFE_HDMI_CONN0,
AFE_HDMI_CONN0_O30_I30 |
AFE_HDMI_CONN0_O31_I31 |
AFE_HDMI_CONN0_O32_I34 |
AFE_HDMI_CONN0_O33_I35 |
AFE_HDMI_CONN0_O34_I32 |
AFE_HDMI_CONN0_O35_I33 |
AFE_HDMI_CONN0_O36_I36 |
AFE_HDMI_CONN0_O37_I37);
regmap_update_bits(afe->regmap, AFE_HDMI_OUT_CON0, 0x1, 0x1);
regmap_update_bits(afe->regmap, AFE_TDM_CON1, 0x1, 0x1);
return 0;
case SNDRV_PCM_TRIGGER_STOP:
case SNDRV_PCM_TRIGGER_SUSPEND:
regmap_update_bits(afe->regmap, AFE_TDM_CON1, 0x1, 0);
regmap_update_bits(afe->regmap, AFE_HDMI_OUT_CON0, 0x1, 0);
regmap_update_bits(afe->regmap, AUDIO_TOP_CON0,
AUD_TCON0_PDN_HDMI | AUD_TCON0_PDN_SPDF,
AUD_TCON0_PDN_HDMI | AUD_TCON0_PDN_SPDF);
return 0;
default:
return -EINVAL;
}
}
static int mt8173_memif_fs(struct snd_pcm_substream *substream,
unsigned int rate)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct mtk_base_afe *afe = snd_soc_platform_get_drvdata(rtd->platform);
struct mtk_base_afe_memif *memif = &afe->memif[rtd->cpu_dai->id];
int fs;
if (memif->data->id == MT8173_AFE_MEMIF_DAI ||
memif->data->id == MT8173_AFE_MEMIF_MOD_DAI) {
switch (rate) {
case 8000:
fs = 0;
break;
case 16000:
fs = 1;
break;
case 32000:
fs = 2;
break;
default:
return -EINVAL;
}
} else {
fs = mt8173_afe_i2s_fs(rate);
}
return fs;
}
static int mt8173_irq_fs(struct snd_pcm_substream *substream, unsigned int rate)
{
return mt8173_afe_i2s_fs(rate);
}
static irqreturn_t mt8173_afe_irq_handler(int irq, void *dev_id)
{
struct mtk_base_afe *afe = dev_id;
unsigned int reg_value;
int i, ret;
ret = regmap_read(afe->regmap, AFE_IRQ_STATUS, &reg_value);
if (ret) {
dev_err(afe->dev, "%s irq status err\n", __func__);
reg_value = AFE_IRQ_STATUS_BITS;
goto err_irq;
}
for (i = 0; i < MT8173_AFE_MEMIF_NUM; i++) {
struct mtk_base_afe_memif *memif = &afe->memif[i];
struct mtk_base_afe_irq *irq;
if (memif->irq_usage < 0)
continue;
irq = &afe->irqs[memif->irq_usage];
if (!(reg_value & (1 << irq->irq_data->irq_clr_shift)))
continue;
snd_pcm_period_elapsed(memif->substream);
}
err_irq:
regmap_write(afe->regmap, AFE_IRQ_CLR,
reg_value & AFE_IRQ_STATUS_BITS);
return IRQ_HANDLED;
}
static int mt8173_afe_runtime_suspend(struct device *dev)
{
struct mtk_base_afe *afe = dev_get_drvdata(dev);
struct mt8173_afe_private *afe_priv = afe->platform_priv;
regmap_update_bits(afe->regmap, AFE_DAC_CON0, 0x1, 0);
regmap_update_bits(afe->regmap, AUDIO_TOP_CON0,
AUD_TCON0_PDN_AFE, AUD_TCON0_PDN_AFE);
clk_disable_unprepare(afe_priv->clocks[MT8173_CLK_I2S1_M]);
clk_disable_unprepare(afe_priv->clocks[MT8173_CLK_I2S2_M]);
clk_disable_unprepare(afe_priv->clocks[MT8173_CLK_BCK0]);
clk_disable_unprepare(afe_priv->clocks[MT8173_CLK_BCK1]);
clk_disable_unprepare(afe_priv->clocks[MT8173_CLK_TOP_PDN_AUD]);
clk_disable_unprepare(afe_priv->clocks[MT8173_CLK_TOP_PDN_AUD_BUS]);
clk_disable_unprepare(afe_priv->clocks[MT8173_CLK_INFRASYS_AUD]);
return 0;
}
static int mt8173_afe_runtime_resume(struct device *dev)
{
struct mtk_base_afe *afe = dev_get_drvdata(dev);
struct mt8173_afe_private *afe_priv = afe->platform_priv;
int ret;
ret = clk_prepare_enable(afe_priv->clocks[MT8173_CLK_INFRASYS_AUD]);
if (ret)
return ret;
ret = clk_prepare_enable(afe_priv->clocks[MT8173_CLK_TOP_PDN_AUD_BUS]);
if (ret)
goto err_infra;
ret = clk_prepare_enable(afe_priv->clocks[MT8173_CLK_TOP_PDN_AUD]);
if (ret)
goto err_top_aud_bus;
ret = clk_prepare_enable(afe_priv->clocks[MT8173_CLK_BCK0]);
if (ret)
goto err_top_aud;
ret = clk_prepare_enable(afe_priv->clocks[MT8173_CLK_BCK1]);
if (ret)
goto err_bck0;
ret = clk_prepare_enable(afe_priv->clocks[MT8173_CLK_I2S1_M]);
if (ret)
goto err_i2s1_m;
ret = clk_prepare_enable(afe_priv->clocks[MT8173_CLK_I2S2_M]);
if (ret)
goto err_i2s2_m;
regmap_update_bits(afe->regmap, AUDIO_TOP_CON0, AUD_TCON0_PDN_AFE, 0);
regmap_update_bits(afe->regmap, AFE_CONN_24BIT,
AFE_CONN_24BIT_O03 | AFE_CONN_24BIT_O04, 0);
regmap_update_bits(afe->regmap, AFE_IRQ_MCU_EN, 0xff, 0xff);
regmap_update_bits(afe->regmap, AFE_DAC_CON0, 0x1, 0x1);
return 0;
err_i2s1_m:
clk_disable_unprepare(afe_priv->clocks[MT8173_CLK_I2S1_M]);
err_i2s2_m:
clk_disable_unprepare(afe_priv->clocks[MT8173_CLK_I2S2_M]);
err_bck0:
clk_disable_unprepare(afe_priv->clocks[MT8173_CLK_BCK0]);
err_top_aud:
clk_disable_unprepare(afe_priv->clocks[MT8173_CLK_TOP_PDN_AUD]);
err_top_aud_bus:
clk_disable_unprepare(afe_priv->clocks[MT8173_CLK_TOP_PDN_AUD_BUS]);
err_infra:
clk_disable_unprepare(afe_priv->clocks[MT8173_CLK_INFRASYS_AUD]);
return ret;
}
static int mt8173_afe_init_audio_clk(struct mtk_base_afe *afe)
{
size_t i;
struct mt8173_afe_private *afe_priv = afe->platform_priv;
for (i = 0; i < ARRAY_SIZE(aud_clks); i++) {
afe_priv->clocks[i] = devm_clk_get(afe->dev, aud_clks[i]);
if (IS_ERR(afe_priv->clocks[i])) {
dev_err(afe->dev, "%s devm_clk_get %s fail\n",
__func__, aud_clks[i]);
return PTR_ERR(afe_priv->clocks[i]);
}
}
clk_set_rate(afe_priv->clocks[MT8173_CLK_BCK0], 22579200);
clk_set_rate(afe_priv->clocks[MT8173_CLK_BCK1], 24576000);
return 0;
}
static int mt8173_afe_pcm_dev_probe(struct platform_device *pdev)
{
int ret, i;
unsigned int irq_id;
struct mtk_base_afe *afe;
struct mt8173_afe_private *afe_priv;
struct resource *res;
ret = dma_set_mask_and_coherent(&pdev->dev, DMA_BIT_MASK(33));
if (ret)
return ret;
afe = devm_kzalloc(&pdev->dev, sizeof(*afe), GFP_KERNEL);
if (!afe)
return -ENOMEM;
afe->platform_priv = devm_kzalloc(&pdev->dev, sizeof(*afe_priv),
GFP_KERNEL);
afe_priv = afe->platform_priv;
if (!afe_priv)
return -ENOMEM;
afe->dev = &pdev->dev;
irq_id = platform_get_irq(pdev, 0);
if (!irq_id) {
dev_err(afe->dev, "np %s no irq\n", afe->dev->of_node->name);
return -ENXIO;
}
ret = devm_request_irq(afe->dev, irq_id, mt8173_afe_irq_handler,
0, "Afe_ISR_Handle", (void *)afe);
if (ret) {
dev_err(afe->dev, "could not request_irq\n");
return ret;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
afe->base_addr = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(afe->base_addr))
return PTR_ERR(afe->base_addr);
afe->regmap = devm_regmap_init_mmio(&pdev->dev, afe->base_addr,
&mt8173_afe_regmap_config);
if (IS_ERR(afe->regmap))
return PTR_ERR(afe->regmap);
ret = mt8173_afe_init_audio_clk(afe);
if (ret) {
dev_err(afe->dev, "mt8173_afe_init_audio_clk fail\n");
return ret;
}
afe->memif_size = MT8173_AFE_MEMIF_NUM;
afe->memif = devm_kcalloc(afe->dev, afe->memif_size,
sizeof(*afe->memif), GFP_KERNEL);
if (!afe->memif)
return -ENOMEM;
afe->irqs_size = MT8173_AFE_IRQ_NUM;
afe->irqs = devm_kcalloc(afe->dev, afe->irqs_size,
sizeof(*afe->irqs), GFP_KERNEL);
if (!afe->irqs)
return -ENOMEM;
for (i = 0; i < afe->irqs_size; i++) {
afe->memif[i].data = &memif_data[i];
afe->irqs[i].irq_data = &irq_data[i];
afe->irqs[i].irq_occupyed = true;
afe->memif[i].irq_usage = i;
afe->memif[i].const_irq = 1;
}
afe->mtk_afe_hardware = &mt8173_afe_hardware;
afe->memif_fs = mt8173_memif_fs;
afe->irq_fs = mt8173_irq_fs;
platform_set_drvdata(pdev, afe);
pm_runtime_enable(&pdev->dev);
if (!pm_runtime_enabled(&pdev->dev)) {
ret = mt8173_afe_runtime_resume(&pdev->dev);
if (ret)
goto err_pm_disable;
}
afe->reg_back_up_list = mt8173_afe_backup_list;
afe->reg_back_up_list_num = ARRAY_SIZE(mt8173_afe_backup_list);
afe->runtime_resume = mt8173_afe_runtime_resume;
afe->runtime_suspend = mt8173_afe_runtime_suspend;
ret = snd_soc_register_platform(&pdev->dev, &mtk_afe_pcm_platform);
if (ret)
goto err_pm_disable;
ret = snd_soc_register_component(&pdev->dev,
&mt8173_afe_pcm_dai_component,
mt8173_afe_pcm_dais,
ARRAY_SIZE(mt8173_afe_pcm_dais));
if (ret)
goto err_platform;
ret = snd_soc_register_component(&pdev->dev,
&mt8173_afe_hdmi_dai_component,
mt8173_afe_hdmi_dais,
ARRAY_SIZE(mt8173_afe_hdmi_dais));
if (ret)
goto err_comp;
dev_info(&pdev->dev, "MT8173 AFE driver initialized.\n");
return 0;
err_comp:
snd_soc_unregister_component(&pdev->dev);
err_platform:
snd_soc_unregister_platform(&pdev->dev);
err_pm_disable:
pm_runtime_disable(&pdev->dev);
return ret;
}
static int mt8173_afe_pcm_dev_remove(struct platform_device *pdev)
{
pm_runtime_disable(&pdev->dev);
if (!pm_runtime_status_suspended(&pdev->dev))
mt8173_afe_runtime_suspend(&pdev->dev);
snd_soc_unregister_component(&pdev->dev);
snd_soc_unregister_platform(&pdev->dev);
return 0;
}
