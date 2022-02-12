static int s3c24xx_uda134x_startup(struct snd_pcm_substream *substream)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *cpu_dai = rtd->cpu_dai;
#ifdef ENFORCE_RATES
struct snd_pcm_runtime *runtime = substream->runtime;
#endif
int ret = 0;
mutex_lock(&clk_lock);
if (clk_users == 0) {
xtal = clk_get(rtd->dev, "xtal");
if (IS_ERR(xtal)) {
dev_err(rtd->dev, "%s cannot get xtal\n", __func__);
ret = PTR_ERR(xtal);
} else {
pclk = clk_get(cpu_dai->dev, "iis");
if (IS_ERR(pclk)) {
dev_err(rtd->dev, "%s cannot get pclk\n",
__func__);
clk_put(xtal);
ret = PTR_ERR(pclk);
}
}
if (!ret) {
int i, j;
for (i = 0; i < 2; i++) {
int fs = i ? 256 : 384;
rates[i*33] = clk_get_rate(xtal) / fs;
for (j = 1; j < 33; j++)
rates[i*33 + j] = clk_get_rate(pclk) /
(j * fs);
}
}
}
clk_users += 1;
mutex_unlock(&clk_lock);
if (!ret) {
#ifdef ENFORCE_RATES
ret = snd_pcm_hw_constraint_list(runtime, 0,
SNDRV_PCM_HW_PARAM_RATE,
&hw_constraints_rates);
if (ret < 0)
dev_err(rtd->dev, "%s cannot set constraints\n",
__func__);
#endif
}
return ret;
}
static void s3c24xx_uda134x_shutdown(struct snd_pcm_substream *substream)
{
mutex_lock(&clk_lock);
clk_users -= 1;
if (clk_users == 0) {
clk_put(xtal);
xtal = NULL;
clk_put(pclk);
pclk = NULL;
}
mutex_unlock(&clk_lock);
}
static int s3c24xx_uda134x_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
struct snd_soc_dai *cpu_dai = rtd->cpu_dai;
unsigned int clk = 0;
int ret = 0;
int clk_source, fs_mode;
unsigned long rate = params_rate(params);
long err, cerr;
unsigned int div;
int i, bi;
err = 999999;
bi = 0;
for (i = 0; i < 2*33; i++) {
cerr = rates[i] - rate;
if (cerr < 0)
cerr = -cerr;
if (cerr < err) {
err = cerr;
bi = i;
}
}
if (bi / 33 == 1)
fs_mode = S3C2410_IISMOD_256FS;
else
fs_mode = S3C2410_IISMOD_384FS;
if (bi % 33 == 0) {
clk_source = S3C24XX_CLKSRC_MPLL;
div = 1;
} else {
clk_source = S3C24XX_CLKSRC_PCLK;
div = bi % 33;
}
dev_dbg(rtd->dev, "%s desired rate %lu, %d\n", __func__, rate, bi);
clk = (fs_mode == S3C2410_IISMOD_384FS ? 384 : 256) * rate;
dev_dbg(rtd->dev, "%s will use: %s %s %d sysclk %d err %ld\n", __func__,
fs_mode == S3C2410_IISMOD_384FS ? "384FS" : "256FS",
clk_source == S3C24XX_CLKSRC_MPLL ? "MPLLin" : "PCLK",
div, clk, err);
if ((err * 100 / rate) > 5) {
dev_err(rtd->dev, "effective frequency too different "
"from desired (%ld%%)\n", err * 100 / rate);
return -EINVAL;
}
ret = snd_soc_dai_set_sysclk(cpu_dai, clk_source , clk,
SND_SOC_CLOCK_IN);
if (ret < 0)
return ret;
ret = snd_soc_dai_set_clkdiv(cpu_dai, S3C24XX_DIV_MCLK, fs_mode);
if (ret < 0)
return ret;
ret = snd_soc_dai_set_clkdiv(cpu_dai, S3C24XX_DIV_BCLK,
S3C2410_IISMOD_32FS);
if (ret < 0)
return ret;
ret = snd_soc_dai_set_clkdiv(cpu_dai, S3C24XX_DIV_PRESCALER,
S3C24XX_PRESCALE(div, div));
if (ret < 0)
return ret;
ret = snd_soc_dai_set_sysclk(codec_dai, 0, clk,
SND_SOC_CLOCK_OUT);
if (ret < 0)
return ret;
return 0;
}
static int s3c24xx_uda134x_probe(struct platform_device *pdev)
{
struct snd_soc_card *card = &snd_soc_s3c24xx_uda134x;
int ret;
platform_set_drvdata(pdev, card);
card->dev = &pdev->dev;
ret = devm_snd_soc_register_card(&pdev->dev, card);
if (ret)
dev_err(&pdev->dev, "failed to register card: %d\n", ret);
return ret;
}
