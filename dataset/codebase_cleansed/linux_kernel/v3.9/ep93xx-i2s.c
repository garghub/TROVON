static inline void ep93xx_i2s_write_reg(struct ep93xx_i2s_info *info,
unsigned reg, unsigned val)
{
__raw_writel(val, info->regs + reg);
}
static inline unsigned ep93xx_i2s_read_reg(struct ep93xx_i2s_info *info,
unsigned reg)
{
return __raw_readl(info->regs + reg);
}
static void ep93xx_i2s_enable(struct ep93xx_i2s_info *info, int stream)
{
unsigned base_reg;
int i;
if ((ep93xx_i2s_read_reg(info, EP93XX_I2S_TX0EN) & 0x1) == 0 &&
(ep93xx_i2s_read_reg(info, EP93XX_I2S_RX0EN) & 0x1) == 0) {
clk_enable(info->mclk);
clk_enable(info->sclk);
clk_enable(info->lrclk);
ep93xx_i2s_write_reg(info, EP93XX_I2S_GLCTRL, 1);
}
if (stream == SNDRV_PCM_STREAM_PLAYBACK)
base_reg = EP93XX_I2S_TX0EN;
else
base_reg = EP93XX_I2S_RX0EN;
for (i = 0; i < 3; i++)
ep93xx_i2s_write_reg(info, base_reg + (i * 4), 1);
}
static void ep93xx_i2s_disable(struct ep93xx_i2s_info *info, int stream)
{
unsigned base_reg;
int i;
if (stream == SNDRV_PCM_STREAM_PLAYBACK)
base_reg = EP93XX_I2S_TX0EN;
else
base_reg = EP93XX_I2S_RX0EN;
for (i = 0; i < 3; i++)
ep93xx_i2s_write_reg(info, base_reg + (i * 4), 0);
if ((ep93xx_i2s_read_reg(info, EP93XX_I2S_TX0EN) & 0x1) == 0 &&
(ep93xx_i2s_read_reg(info, EP93XX_I2S_RX0EN) & 0x1) == 0) {
ep93xx_i2s_write_reg(info, EP93XX_I2S_GLCTRL, 0);
clk_disable(info->lrclk);
clk_disable(info->sclk);
clk_disable(info->mclk);
}
}
static int ep93xx_i2s_startup(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct ep93xx_i2s_info *info = snd_soc_dai_get_drvdata(dai);
struct snd_soc_dai *cpu_dai = rtd->cpu_dai;
snd_soc_dai_set_dma_data(cpu_dai, substream,
&info->dma_params[substream->stream]);
return 0;
}
static void ep93xx_i2s_shutdown(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct ep93xx_i2s_info *info = snd_soc_dai_get_drvdata(dai);
ep93xx_i2s_disable(info, substream->stream);
}
static int ep93xx_i2s_set_dai_fmt(struct snd_soc_dai *cpu_dai,
unsigned int fmt)
{
struct ep93xx_i2s_info *info = snd_soc_dai_get_drvdata(cpu_dai);
unsigned int clk_cfg, lin_ctrl;
clk_cfg = ep93xx_i2s_read_reg(info, EP93XX_I2S_RXCLKCFG);
lin_ctrl = ep93xx_i2s_read_reg(info, EP93XX_I2S_RXLINCTRLDATA);
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
clk_cfg |= EP93XX_I2S_CLKCFG_REL;
lin_ctrl &= ~EP93XX_I2S_LINCTRLDATA_R_JUST;
break;
case SND_SOC_DAIFMT_LEFT_J:
clk_cfg &= ~EP93XX_I2S_CLKCFG_REL;
lin_ctrl &= ~EP93XX_I2S_LINCTRLDATA_R_JUST;
break;
case SND_SOC_DAIFMT_RIGHT_J:
clk_cfg &= ~EP93XX_I2S_CLKCFG_REL;
lin_ctrl |= EP93XX_I2S_LINCTRLDATA_R_JUST;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBS_CFS:
clk_cfg |= EP93XX_I2S_CLKCFG_MASTER;
break;
case SND_SOC_DAIFMT_CBM_CFM:
clk_cfg &= ~EP93XX_I2S_CLKCFG_MASTER;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
clk_cfg &= ~(EP93XX_I2S_CLKCFG_CKP | EP93XX_I2S_CLKCFG_REL);
break;
case SND_SOC_DAIFMT_NB_IF:
clk_cfg &= ~EP93XX_I2S_CLKCFG_CKP;
clk_cfg |= EP93XX_I2S_CLKCFG_REL;
break;
case SND_SOC_DAIFMT_IB_NF:
clk_cfg |= EP93XX_I2S_CLKCFG_CKP;
clk_cfg &= ~EP93XX_I2S_CLKCFG_REL;
break;
case SND_SOC_DAIFMT_IB_IF:
clk_cfg |= EP93XX_I2S_CLKCFG_CKP | EP93XX_I2S_CLKCFG_REL;
break;
}
ep93xx_i2s_write_reg(info, EP93XX_I2S_RXCLKCFG, clk_cfg);
ep93xx_i2s_write_reg(info, EP93XX_I2S_TXCLKCFG, clk_cfg);
ep93xx_i2s_write_reg(info, EP93XX_I2S_RXLINCTRLDATA, lin_ctrl);
ep93xx_i2s_write_reg(info, EP93XX_I2S_TXLINCTRLDATA, lin_ctrl);
return 0;
}
static int ep93xx_i2s_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct ep93xx_i2s_info *info = snd_soc_dai_get_drvdata(dai);
unsigned word_len, div, sdiv, lrdiv;
int err;
switch (params_format(params)) {
case SNDRV_PCM_FORMAT_S16_LE:
word_len = EP93XX_I2S_WRDLEN_16;
break;
case SNDRV_PCM_FORMAT_S24_LE:
word_len = EP93XX_I2S_WRDLEN_24;
break;
case SNDRV_PCM_FORMAT_S32_LE:
word_len = EP93XX_I2S_WRDLEN_32;
break;
default:
return -EINVAL;
}
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
ep93xx_i2s_write_reg(info, EP93XX_I2S_TXWRDLEN, word_len);
else
ep93xx_i2s_write_reg(info, EP93XX_I2S_RXWRDLEN, word_len);
div = clk_get_rate(info->mclk) / params_rate(params);
sdiv = 4;
if (div > (256 + 512) / 2) {
lrdiv = 128;
} else {
lrdiv = 64;
if (div < (128 + 256) / 2)
sdiv = 2;
}
err = clk_set_rate(info->sclk, clk_get_rate(info->mclk) / sdiv);
if (err)
return err;
err = clk_set_rate(info->lrclk, clk_get_rate(info->sclk) / lrdiv);
if (err)
return err;
ep93xx_i2s_enable(info, substream->stream);
return 0;
}
static int ep93xx_i2s_set_sysclk(struct snd_soc_dai *cpu_dai, int clk_id,
unsigned int freq, int dir)
{
struct ep93xx_i2s_info *info = snd_soc_dai_get_drvdata(cpu_dai);
if (dir == SND_SOC_CLOCK_IN || clk_id != 0)
return -EINVAL;
return clk_set_rate(info->mclk, freq);
}
static int ep93xx_i2s_suspend(struct snd_soc_dai *dai)
{
struct ep93xx_i2s_info *info = snd_soc_dai_get_drvdata(dai);
if (!dai->active)
return 0;
ep93xx_i2s_disable(info, SNDRV_PCM_STREAM_PLAYBACK);
ep93xx_i2s_disable(info, SNDRV_PCM_STREAM_CAPTURE);
return 0;
}
static int ep93xx_i2s_resume(struct snd_soc_dai *dai)
{
struct ep93xx_i2s_info *info = snd_soc_dai_get_drvdata(dai);
if (!dai->active)
return 0;
ep93xx_i2s_enable(info, SNDRV_PCM_STREAM_PLAYBACK);
ep93xx_i2s_enable(info, SNDRV_PCM_STREAM_CAPTURE);
return 0;
}
static int ep93xx_i2s_probe(struct platform_device *pdev)
{
struct ep93xx_i2s_info *info;
struct resource *res;
int err;
info = devm_kzalloc(&pdev->dev, sizeof(*info), GFP_KERNEL);
if (!info)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res)
return -ENODEV;
info->regs = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(info->regs))
return PTR_ERR(info->regs);
info->mclk = clk_get(&pdev->dev, "mclk");
if (IS_ERR(info->mclk)) {
err = PTR_ERR(info->mclk);
goto fail;
}
info->sclk = clk_get(&pdev->dev, "sclk");
if (IS_ERR(info->sclk)) {
err = PTR_ERR(info->sclk);
goto fail_put_mclk;
}
info->lrclk = clk_get(&pdev->dev, "lrclk");
if (IS_ERR(info->lrclk)) {
err = PTR_ERR(info->lrclk);
goto fail_put_sclk;
}
dev_set_drvdata(&pdev->dev, info);
info->dma_params = ep93xx_i2s_dma_params;
err = snd_soc_register_dai(&pdev->dev, &ep93xx_i2s_dai);
if (err)
goto fail_put_lrclk;
return 0;
fail_put_lrclk:
dev_set_drvdata(&pdev->dev, NULL);
clk_put(info->lrclk);
fail_put_sclk:
clk_put(info->sclk);
fail_put_mclk:
clk_put(info->mclk);
fail:
return err;
}
static int ep93xx_i2s_remove(struct platform_device *pdev)
{
struct ep93xx_i2s_info *info = dev_get_drvdata(&pdev->dev);
snd_soc_unregister_dai(&pdev->dev);
dev_set_drvdata(&pdev->dev, NULL);
clk_put(info->lrclk);
clk_put(info->sclk);
clk_put(info->mclk);
return 0;
}
