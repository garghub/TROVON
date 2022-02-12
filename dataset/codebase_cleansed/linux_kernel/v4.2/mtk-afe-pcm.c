static snd_pcm_uframes_t mtk_afe_pcm_pointer
(struct snd_pcm_substream *substream)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct mtk_afe *afe = snd_soc_platform_get_drvdata(rtd->platform);
struct mtk_afe_memif *memif = &afe->memif[rtd->cpu_dai->id];
return bytes_to_frames(substream->runtime, memif->hw_ptr);
}
static int mtk_afe_pcm_new(struct snd_soc_pcm_runtime *rtd)
{
size_t size;
struct snd_card *card = rtd->card->snd_card;
struct snd_pcm *pcm = rtd->pcm;
size = mtk_afe_hardware.buffer_bytes_max;
return snd_pcm_lib_preallocate_pages_for_all(pcm, SNDRV_DMA_TYPE_DEV,
card->dev, size, size);
}
static void mtk_afe_pcm_free(struct snd_pcm *pcm)
{
snd_pcm_lib_preallocate_free_for_all(pcm);
}
static int mtk_afe_i2s_fs(unsigned int sample_rate)
{
int i;
for (i = 0; i < ARRAY_SIZE(mtk_afe_i2s_rates); i++)
if (mtk_afe_i2s_rates[i].rate == sample_rate)
return mtk_afe_i2s_rates[i].regvalue;
return -EINVAL;
}
static int mtk_afe_set_i2s(struct mtk_afe *afe, unsigned int rate)
{
unsigned int val;
int fs = mtk_afe_i2s_fs(rate);
if (fs < 0)
return -EINVAL;
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
static void mtk_afe_set_i2s_enable(struct mtk_afe *afe, bool enable)
{
unsigned int val;
regmap_read(afe->regmap, AFE_I2S_CON2, &val);
if (!!(val & AFE_I2S_CON2_EN) == enable)
return;
regmap_update_bits(afe->regmap, AUDIO_TOP_CON1, 0x4, 0x4);
regmap_update_bits(afe->regmap, AFE_I2S_CON2, 0x1, enable);
regmap_update_bits(afe->regmap, AFE_I2S_CON1, 0x1, enable);
udelay(1);
regmap_update_bits(afe->regmap, AUDIO_TOP_CON1, 0x4, 0);
}
static int mtk_afe_dais_enable_clks(struct mtk_afe *afe,
struct clk *m_ck, struct clk *b_ck)
{
int ret;
if (m_ck) {
ret = clk_prepare_enable(m_ck);
if (ret) {
dev_err(afe->dev, "Failed to enable m_ck\n");
return ret;
}
regmap_update_bits(afe->regmap, AUDIO_TOP_CON0,
AUD_TCON0_PDN_22M | AUD_TCON0_PDN_24M, 0);
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
static int mtk_afe_dais_set_clks(struct mtk_afe *afe,
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
static void mtk_afe_dais_disable_clks(struct mtk_afe *afe,
struct clk *m_ck, struct clk *b_ck)
{
if (m_ck) {
regmap_update_bits(afe->regmap, AUDIO_TOP_CON0,
AUD_TCON0_PDN_22M | AUD_TCON0_PDN_24M,
AUD_TCON0_PDN_22M | AUD_TCON0_PDN_24M);
clk_disable_unprepare(m_ck);
}
if (b_ck)
clk_disable_unprepare(b_ck);
}
static int mtk_afe_i2s_startup(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct mtk_afe *afe = snd_soc_platform_get_drvdata(rtd->platform);
if (dai->active)
return 0;
mtk_afe_dais_enable_clks(afe, afe->clocks[MTK_CLK_I2S1_M], NULL);
return 0;
}
static void mtk_afe_i2s_shutdown(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct mtk_afe *afe = snd_soc_platform_get_drvdata(rtd->platform);
if (dai->active)
return;
mtk_afe_set_i2s_enable(afe, false);
mtk_afe_dais_disable_clks(afe, afe->clocks[MTK_CLK_I2S1_M], NULL);
regmap_update_bits(afe->regmap, AFE_DAC_CON0, 0x1, 0);
}
static int mtk_afe_i2s_prepare(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_pcm_runtime * const runtime = substream->runtime;
struct mtk_afe *afe = snd_soc_platform_get_drvdata(rtd->platform);
int ret;
mtk_afe_dais_set_clks(afe,
afe->clocks[MTK_CLK_I2S1_M], runtime->rate * 256,
NULL, 0);
ret = mtk_afe_set_i2s(afe, substream->runtime->rate);
if (ret)
return ret;
mtk_afe_set_i2s_enable(afe, true);
return 0;
}
static int mtk_afe_hdmi_startup(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct mtk_afe *afe = snd_soc_platform_get_drvdata(rtd->platform);
if (dai->active)
return 0;
mtk_afe_dais_enable_clks(afe, afe->clocks[MTK_CLK_I2S3_M],
afe->clocks[MTK_CLK_I2S3_B]);
return 0;
}
static void mtk_afe_hdmi_shutdown(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct mtk_afe *afe = snd_soc_platform_get_drvdata(rtd->platform);
if (dai->active)
return;
mtk_afe_dais_disable_clks(afe, afe->clocks[MTK_CLK_I2S3_M],
afe->clocks[MTK_CLK_I2S3_B]);
regmap_update_bits(afe->regmap, AFE_DAC_CON0, 0x1, 0);
}
static int mtk_afe_hdmi_prepare(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_pcm_runtime * const runtime = substream->runtime;
struct mtk_afe *afe = snd_soc_platform_get_drvdata(rtd->platform);
unsigned int val;
mtk_afe_dais_set_clks(afe,
afe->clocks[MTK_CLK_I2S3_M], runtime->rate * 128,
afe->clocks[MTK_CLK_I2S3_B],
runtime->rate * runtime->channels * 32);
val = AFE_TDM_CON1_BCK_INV |
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
static int mtk_afe_hdmi_trigger(struct snd_pcm_substream *substream, int cmd,
struct snd_soc_dai *dai)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct mtk_afe *afe = snd_soc_platform_get_drvdata(rtd->platform);
dev_info(afe->dev, "%s cmd=%d %s\n", __func__, cmd, dai->name);
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
case SNDRV_PCM_TRIGGER_RESUME:
regmap_update_bits(afe->regmap, AUDIO_TOP_CON0,
AUD_TCON0_PDN_HDMI | AUD_TCON0_PDN_SPDF, 0);
regmap_write(afe->regmap, AFE_HDMI_CONN0,
AFE_HDMI_CONN0_O30_I30 | AFE_HDMI_CONN0_O31_I31 |
AFE_HDMI_CONN0_O32_I34 | AFE_HDMI_CONN0_O33_I35 |
AFE_HDMI_CONN0_O34_I32 | AFE_HDMI_CONN0_O35_I33 |
AFE_HDMI_CONN0_O36_I36 | AFE_HDMI_CONN0_O37_I37);
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
static int mtk_afe_dais_startup(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct mtk_afe *afe = snd_soc_platform_get_drvdata(rtd->platform);
struct snd_pcm_runtime *runtime = substream->runtime;
struct mtk_afe_memif *memif = &afe->memif[rtd->cpu_dai->id];
int ret;
memif->substream = substream;
snd_soc_set_runtime_hwparams(substream, &mtk_afe_hardware);
ret = snd_pcm_hw_constraint_integer(runtime,
SNDRV_PCM_HW_PARAM_PERIODS);
if (ret < 0)
dev_err(afe->dev, "snd_pcm_hw_constraint_integer failed\n");
return ret;
}
static void mtk_afe_dais_shutdown(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct mtk_afe *afe = snd_soc_platform_get_drvdata(rtd->platform);
struct mtk_afe_memif *memif = &afe->memif[rtd->cpu_dai->id];
memif->substream = NULL;
}
static int mtk_afe_dais_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct mtk_afe *afe = snd_soc_platform_get_drvdata(rtd->platform);
struct mtk_afe_memif *memif = &afe->memif[rtd->cpu_dai->id];
int ret;
dev_dbg(afe->dev,
"%s period = %u, rate= %u, channels=%u\n",
__func__, params_period_size(params), params_rate(params),
params_channels(params));
ret = snd_pcm_lib_malloc_pages(substream, params_buffer_bytes(params));
if (ret < 0)
return ret;
memif->phys_buf_addr = substream->runtime->dma_addr;
memif->buffer_size = substream->runtime->dma_bytes;
memif->hw_ptr = 0;
regmap_write(afe->regmap,
memif->data->reg_ofs_base, memif->phys_buf_addr);
regmap_write(afe->regmap,
memif->data->reg_ofs_base + AFE_BASE_END_OFFSET,
memif->phys_buf_addr + memif->buffer_size - 1);
if (memif->data->mono_shift >= 0) {
unsigned int mono = (params_channels(params) == 1) ? 1 : 0;
regmap_update_bits(afe->regmap, AFE_DAC_CON1,
1 << memif->data->mono_shift,
mono << memif->data->mono_shift);
}
if (memif->data->fs_shift < 0)
return 0;
if (memif->data->id == MTK_AFE_MEMIF_DAI ||
memif->data->id == MTK_AFE_MEMIF_MOD_DAI) {
unsigned int val;
switch (params_rate(params)) {
case 8000:
val = 0;
break;
case 16000:
val = 1;
break;
case 32000:
val = 2;
break;
default:
return -EINVAL;
}
if (memif->data->id == MTK_AFE_MEMIF_DAI)
regmap_update_bits(afe->regmap, AFE_DAC_CON0,
0x3 << memif->data->fs_shift,
val << memif->data->fs_shift);
else
regmap_update_bits(afe->regmap, AFE_DAC_CON1,
0x3 << memif->data->fs_shift,
val << memif->data->fs_shift);
} else {
int fs = mtk_afe_i2s_fs(params_rate(params));
if (fs < 0)
return -EINVAL;
regmap_update_bits(afe->regmap, AFE_DAC_CON1,
0xf << memif->data->fs_shift,
fs << memif->data->fs_shift);
}
return 0;
}
static int mtk_afe_dais_hw_free(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
return snd_pcm_lib_free_pages(substream);
}
static int mtk_afe_dais_prepare(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct mtk_afe *afe = snd_soc_platform_get_drvdata(rtd->platform);
regmap_update_bits(afe->regmap, AFE_DAC_CON0, 0x1, 0x1);
return 0;
}
static int mtk_afe_dais_trigger(struct snd_pcm_substream *substream, int cmd,
struct snd_soc_dai *dai)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_pcm_runtime * const runtime = substream->runtime;
struct mtk_afe *afe = snd_soc_platform_get_drvdata(rtd->platform);
struct mtk_afe_memif *memif = &afe->memif[rtd->cpu_dai->id];
unsigned int counter = runtime->period_size;
dev_info(afe->dev, "%s %s cmd=%d\n", __func__, memif->data->name, cmd);
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
case SNDRV_PCM_TRIGGER_RESUME:
if (memif->data->enable_shift >= 0)
regmap_update_bits(afe->regmap, AFE_DAC_CON0,
1 << memif->data->enable_shift,
1 << memif->data->enable_shift);
regmap_update_bits(afe->regmap,
memif->data->irq_reg_cnt,
0x3ffff << memif->data->irq_cnt_shift,
counter << memif->data->irq_cnt_shift);
if (memif->data->irq_fs_shift >= 0) {
int fs = mtk_afe_i2s_fs(runtime->rate);
if (fs < 0)
return -EINVAL;
regmap_update_bits(afe->regmap,
AFE_IRQ_MCU_CON,
0xf << memif->data->irq_fs_shift,
fs << memif->data->irq_fs_shift);
}
regmap_update_bits(afe->regmap, AFE_IRQ_MCU_CON,
1 << memif->data->irq_en_shift,
1 << memif->data->irq_en_shift);
return 0;
case SNDRV_PCM_TRIGGER_STOP:
case SNDRV_PCM_TRIGGER_SUSPEND:
if (memif->data->enable_shift >= 0)
regmap_update_bits(afe->regmap, AFE_DAC_CON0,
1 << memif->data->enable_shift, 0);
regmap_update_bits(afe->regmap, AFE_IRQ_MCU_CON,
1 << memif->data->irq_en_shift,
0 << memif->data->irq_en_shift);
regmap_write(afe->regmap, AFE_IRQ_CLR,
1 << memif->data->irq_clr_shift);
memif->hw_ptr = 0;
return 0;
default:
return -EINVAL;
}
}
static irqreturn_t mtk_afe_irq_handler(int irq, void *dev_id)
{
struct mtk_afe *afe = dev_id;
unsigned int reg_value, hw_ptr;
int i, ret;
ret = regmap_read(afe->regmap, AFE_IRQ_STATUS, &reg_value);
if (ret) {
dev_err(afe->dev, "%s irq status err\n", __func__);
reg_value = AFE_IRQ_STATUS_BITS;
goto err_irq;
}
for (i = 0; i < MTK_AFE_MEMIF_NUM; i++) {
struct mtk_afe_memif *memif = &afe->memif[i];
if (!(reg_value & (1 << memif->data->irq_clr_shift)))
continue;
ret = regmap_read(afe->regmap, memif->data->reg_ofs_cur,
&hw_ptr);
if (ret || hw_ptr == 0) {
dev_err(afe->dev, "%s hw_ptr err\n", __func__);
hw_ptr = memif->phys_buf_addr;
}
memif->hw_ptr = hw_ptr - memif->phys_buf_addr;
snd_pcm_period_elapsed(memif->substream);
}
err_irq:
regmap_write(afe->regmap, AFE_IRQ_CLR, reg_value & AFE_IRQ_STATUS_BITS);
return IRQ_HANDLED;
}
static int mtk_afe_runtime_suspend(struct device *dev)
{
struct mtk_afe *afe = dev_get_drvdata(dev);
regmap_update_bits(afe->regmap, AUDIO_TOP_CON0,
AUD_TCON0_PDN_AFE, AUD_TCON0_PDN_AFE);
clk_disable_unprepare(afe->clocks[MTK_CLK_BCK0]);
clk_disable_unprepare(afe->clocks[MTK_CLK_BCK1]);
clk_disable_unprepare(afe->clocks[MTK_CLK_TOP_PDN_AUD]);
clk_disable_unprepare(afe->clocks[MTK_CLK_TOP_PDN_AUD_BUS]);
clk_disable_unprepare(afe->clocks[MTK_CLK_INFRASYS_AUD]);
return 0;
}
static int mtk_afe_runtime_resume(struct device *dev)
{
struct mtk_afe *afe = dev_get_drvdata(dev);
int ret;
ret = clk_prepare_enable(afe->clocks[MTK_CLK_INFRASYS_AUD]);
if (ret)
return ret;
ret = clk_prepare_enable(afe->clocks[MTK_CLK_TOP_PDN_AUD_BUS]);
if (ret)
goto err_infra;
ret = clk_prepare_enable(afe->clocks[MTK_CLK_TOP_PDN_AUD]);
if (ret)
goto err_top_aud_bus;
ret = clk_prepare_enable(afe->clocks[MTK_CLK_BCK0]);
if (ret)
goto err_top_aud;
ret = clk_prepare_enable(afe->clocks[MTK_CLK_BCK1]);
if (ret)
goto err_bck0;
regmap_update_bits(afe->regmap, AUDIO_TOP_CON0, AUD_TCON0_PDN_AFE, 0);
regmap_update_bits(afe->regmap, AFE_CONN_24BIT,
AFE_CONN_24BIT_O03 | AFE_CONN_24BIT_O04, 0);
regmap_update_bits(afe->regmap, AFE_IRQ_MCU_EN, 0xff, 0xff);
return 0;
err_bck0:
clk_disable_unprepare(afe->clocks[MTK_CLK_BCK0]);
err_top_aud:
clk_disable_unprepare(afe->clocks[MTK_CLK_TOP_PDN_AUD]);
err_top_aud_bus:
clk_disable_unprepare(afe->clocks[MTK_CLK_TOP_PDN_AUD_BUS]);
err_infra:
clk_disable_unprepare(afe->clocks[MTK_CLK_INFRASYS_AUD]);
return ret;
}
static int mtk_afe_init_audio_clk(struct mtk_afe *afe)
{
size_t i;
for (i = 0; i < ARRAY_SIZE(aud_clks); i++) {
afe->clocks[i] = devm_clk_get(afe->dev, aud_clks[i]);
if (IS_ERR(afe->clocks[i])) {
dev_err(afe->dev, "%s devm_clk_get %s fail\n",
__func__, aud_clks[i]);
return PTR_ERR(afe->clocks[i]);
}
}
clk_set_rate(afe->clocks[MTK_CLK_BCK0], 22579200);
clk_set_rate(afe->clocks[MTK_CLK_BCK1], 24576000);
return 0;
}
static int mtk_afe_pcm_dev_probe(struct platform_device *pdev)
{
int ret, i;
unsigned int irq_id;
struct mtk_afe *afe;
struct resource *res;
afe = devm_kzalloc(&pdev->dev, sizeof(*afe), GFP_KERNEL);
if (!afe)
return -ENOMEM;
afe->dev = &pdev->dev;
irq_id = platform_get_irq(pdev, 0);
if (!irq_id) {
dev_err(afe->dev, "np %s no irq\n", afe->dev->of_node->name);
return -ENXIO;
}
ret = devm_request_irq(afe->dev, irq_id, mtk_afe_irq_handler,
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
&mtk_afe_regmap_config);
if (IS_ERR(afe->regmap))
return PTR_ERR(afe->regmap);
ret = mtk_afe_init_audio_clk(afe);
if (ret) {
dev_err(afe->dev, "mtk_afe_init_audio_clk fail\n");
return ret;
}
for (i = 0; i < MTK_AFE_MEMIF_NUM; i++)
afe->memif[i].data = &memif_data[i];
platform_set_drvdata(pdev, afe);
pm_runtime_enable(&pdev->dev);
if (!pm_runtime_enabled(&pdev->dev)) {
ret = mtk_afe_runtime_resume(&pdev->dev);
if (ret)
goto err_pm_disable;
}
ret = snd_soc_register_platform(&pdev->dev, &mtk_afe_pcm_platform);
if (ret)
goto err_pm_disable;
ret = snd_soc_register_component(&pdev->dev,
&mtk_afe_pcm_dai_component,
mtk_afe_pcm_dais,
ARRAY_SIZE(mtk_afe_pcm_dais));
if (ret)
goto err_platform;
ret = snd_soc_register_component(&pdev->dev,
&mtk_afe_hdmi_dai_component,
mtk_afe_hdmi_dais,
ARRAY_SIZE(mtk_afe_hdmi_dais));
if (ret)
goto err_comp;
dev_info(&pdev->dev, "MTK AFE driver initialized.\n");
return 0;
err_comp:
snd_soc_unregister_component(&pdev->dev);
err_platform:
snd_soc_unregister_platform(&pdev->dev);
err_pm_disable:
pm_runtime_disable(&pdev->dev);
return ret;
}
static int mtk_afe_pcm_dev_remove(struct platform_device *pdev)
{
pm_runtime_disable(&pdev->dev);
if (!pm_runtime_status_suspended(&pdev->dev))
mtk_afe_runtime_suspend(&pdev->dev);
snd_soc_unregister_component(&pdev->dev);
snd_soc_unregister_platform(&pdev->dev);
return 0;
}
