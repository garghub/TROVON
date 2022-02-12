static int s3c2412_i2s_probe(struct snd_soc_dai *dai)
{
int ret;
pr_debug("Entered %s\n", __func__);
samsung_asoc_init_dma_data(dai, &s3c2412_i2s_pcm_stereo_out,
&s3c2412_i2s_pcm_stereo_in);
ret = s3c_i2sv2_probe(dai, &s3c2412_i2s, S3C2410_PA_IIS);
if (ret)
return ret;
s3c2412_i2s.dma_capture = &s3c2412_i2s_pcm_stereo_in;
s3c2412_i2s.dma_playback = &s3c2412_i2s_pcm_stereo_out;
s3c2412_i2s.iis_cclk = devm_clk_get(dai->dev, "i2sclk");
if (IS_ERR(s3c2412_i2s.iis_cclk)) {
pr_err("failed to get i2sclk clock\n");
return PTR_ERR(s3c2412_i2s.iis_cclk);
}
clk_set_parent(s3c2412_i2s.iis_cclk, clk_get(NULL, "mpll"));
clk_prepare_enable(s3c2412_i2s.iis_cclk);
s3c2412_i2s.iis_cclk = s3c2412_i2s.iis_pclk;
s3c_gpio_cfgall_range(S3C2410_GPE(0), 5, S3C_GPIO_SFN(2),
S3C_GPIO_PULL_NONE);
return 0;
}
static int s3c2412_i2s_remove(struct snd_soc_dai *dai)
{
clk_disable_unprepare(s3c2412_i2s.iis_cclk);
return 0;
}
static int s3c2412_i2s_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *cpu_dai)
{
struct s3c_i2sv2_info *i2s = snd_soc_dai_get_drvdata(cpu_dai);
u32 iismod;
pr_debug("Entered %s\n", __func__);
iismod = readl(i2s->regs + S3C2412_IISMOD);
pr_debug("%s: r: IISMOD: %x\n", __func__, iismod);
switch (params_width(params)) {
case 8:
iismod |= S3C2412_IISMOD_8BIT;
break;
case 16:
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
struct resource *res;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
s3c2412_i2s.regs = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(s3c2412_i2s.regs))
return PTR_ERR(s3c2412_i2s.regs);
s3c2412_i2s_pcm_stereo_out.dma_addr = res->start + S3C2412_IISTXD;
s3c2412_i2s_pcm_stereo_in.dma_addr = res->start + S3C2412_IISRXD;
ret = s3c_i2sv2_register_component(&pdev->dev, -1,
&s3c2412_i2s_component,
&s3c2412_i2s_dai);
if (ret) {
pr_err("failed to register the dai\n");
return ret;
}
ret = samsung_asoc_dma_platform_register(&pdev->dev);
if (ret)
pr_err("failed to register the DMA: %d\n", ret);
return ret;
}
