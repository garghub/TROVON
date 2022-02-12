static int s3c2412_i2s_probe(struct snd_soc_dai *dai)
{
int ret;
pr_debug("Entered %s\n", __func__);
ret = s3c_i2sv2_probe(dai, &s3c2412_i2s, S3C2410_PA_IIS);
if (ret)
return ret;
s3c2412_i2s.dma_capture = &s3c2412_i2s_pcm_stereo_in;
s3c2412_i2s.dma_playback = &s3c2412_i2s_pcm_stereo_out;
s3c2412_i2s.iis_cclk = clk_get(dai->dev, "i2sclk");
if (IS_ERR(s3c2412_i2s.iis_cclk)) {
pr_err("failed to get i2sclk clock\n");
iounmap(s3c2412_i2s.regs);
return PTR_ERR(s3c2412_i2s.iis_cclk);
}
clk_set_parent(s3c2412_i2s.iis_cclk, clk_get(NULL, "mpll"));
clk_enable(s3c2412_i2s.iis_cclk);
s3c2412_i2s.iis_cclk = s3c2412_i2s.iis_pclk;
s3c_gpio_cfgall_range(S3C2410_GPE(0), 5, S3C_GPIO_SFN(2),
S3C_GPIO_PULL_NONE);
return 0;
}
static int s3c2412_i2s_remove(struct snd_soc_dai *dai)
{
clk_disable(s3c2412_i2s.iis_cclk);
clk_put(s3c2412_i2s.iis_cclk);
iounmap(s3c2412_i2s.regs);
return 0;
}
static int s3c2412_i2s_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *cpu_dai)
{
struct s3c_i2sv2_info *i2s = snd_soc_dai_get_drvdata(cpu_dai);
struct s3c_dma_params *dma_data;
u32 iismod;
pr_debug("Entered %s\n", __func__);
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
dma_data = i2s->dma_playback;
else
dma_data = i2s->dma_capture;
snd_soc_dai_set_dma_data(cpu_dai, substream, dma_data);
iismod = readl(i2s->regs + S3C2412_IISMOD);
pr_debug("%s: r: IISMOD: %x\n", __func__, iismod);
switch (params_format(params)) {
case SNDRV_PCM_FORMAT_S8:
iismod |= S3C2412_IISMOD_8BIT;
break;
case SNDRV_PCM_FORMAT_S16_LE:
iismod &= ~S3C2412_IISMOD_8BIT;
break;
}
writel(iismod, i2s->regs + S3C2412_IISMOD);
pr_debug("%s: w: IISMOD: %x\n", __func__, iismod);
return 0;
}
static int s3c2412_iis_dev_probe(struct platform_device *pdev)
{
int ret = 0;
ret = s3c_i2sv2_register_component(&pdev->dev, -1,
&s3c2412_i2s_component,
&s3c2412_i2s_dai);
if (ret) {
pr_err("failed to register the dai\n");
return ret;
}
ret = samsung_asoc_dma_platform_register(&pdev->dev);
if (ret) {
pr_err("failed to register the DMA: %d\n", ret);
goto err;
}
return 0;
err:
snd_soc_unregister_component(&pdev->dev);
return ret;
}
static int s3c2412_iis_dev_remove(struct platform_device *pdev)
{
samsung_asoc_dma_platform_unregister(&pdev->dev);
snd_soc_unregister_component(&pdev->dev);
return 0;
}
