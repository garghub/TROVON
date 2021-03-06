static int s3c24xx_uda134x_startup(struct snd_pcm_substream *substream)
{
int ret = 0;
#ifdef ENFORCE_RATES
struct snd_pcm_runtime *runtime = substream->runtime;
#endif
mutex_lock(&clk_lock);
pr_debug("%s %d\n", __func__, clk_users);
if (clk_users == 0) {
xtal = clk_get(&s3c24xx_uda134x_snd_device->dev, "xtal");
if (!xtal) {
printk(KERN_ERR "%s cannot get xtal\n", __func__);
ret = -EBUSY;
} else {
pclk = clk_get(&s3c24xx_uda134x_snd_device->dev,
"pclk");
if (!pclk) {
printk(KERN_ERR "%s cannot get pclk\n",
__func__);
clk_put(xtal);
ret = -EBUSY;
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
printk(KERN_ERR "%s cannot set constraints\n",
__func__);
#endif
}
return ret;
}
static void s3c24xx_uda134x_shutdown(struct snd_pcm_substream *substream)
{
mutex_lock(&clk_lock);
pr_debug("%s %d\n", __func__, clk_users);
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
pr_debug("%s desired rate %lu, %d\n", __func__, rate, bi);
clk = (fs_mode == S3C2410_IISMOD_384FS ? 384 : 256) * rate;
pr_debug("%s will use: %s %s %d sysclk %d err %ld\n", __func__,
fs_mode == S3C2410_IISMOD_384FS ? "384FS" : "256FS",
clk_source == S3C24XX_CLKSRC_MPLL ? "MPLLin" : "PCLK",
div, clk, err);
if ((err * 100 / rate) > 5) {
printk(KERN_ERR "S3C24XX_UDA134X: effective frequency "
"too different from desired (%ld%%)\n",
err * 100 / rate);
return -EINVAL;
}
ret = snd_soc_dai_set_fmt(codec_dai, SND_SOC_DAIFMT_I2S |
SND_SOC_DAIFMT_NB_NF | SND_SOC_DAIFMT_CBS_CFS);
if (ret < 0)
return ret;
ret = snd_soc_dai_set_fmt(cpu_dai, SND_SOC_DAIFMT_I2S |
SND_SOC_DAIFMT_NB_NF | SND_SOC_DAIFMT_CBS_CFS);
if (ret < 0)
return ret;
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
static void setdat(int v)
{
gpio_set_value(s3c24xx_uda134x_l3_pins->l3_data, v > 0);
}
static void setclk(int v)
{
gpio_set_value(s3c24xx_uda134x_l3_pins->l3_clk, v > 0);
}
static void setmode(int v)
{
gpio_set_value(s3c24xx_uda134x_l3_pins->l3_mode, v > 0);
}
static int s3c24xx_uda134x_setup_pin(int pin, char *fun)
{
if (gpio_request(pin, "s3c24xx_uda134x") < 0) {
printk(KERN_ERR "S3C24XX_UDA134X SoC Audio: "
"l3 %s pin already in use", fun);
return -EBUSY;
}
gpio_direction_output(pin, 0);
return 0;
}
static int s3c24xx_uda134x_probe(struct platform_device *pdev)
{
int ret;
printk(KERN_INFO "S3C24XX_UDA134X SoC Audio driver\n");
s3c24xx_uda134x_l3_pins = pdev->dev.platform_data;
if (s3c24xx_uda134x_l3_pins == NULL) {
printk(KERN_ERR "S3C24XX_UDA134X SoC Audio: "
"unable to find platform data\n");
return -ENODEV;
}
s3c24xx_uda134x.power = s3c24xx_uda134x_l3_pins->power;
s3c24xx_uda134x.model = s3c24xx_uda134x_l3_pins->model;
if (s3c24xx_uda134x_setup_pin(s3c24xx_uda134x_l3_pins->l3_data,
"data") < 0)
return -EBUSY;
if (s3c24xx_uda134x_setup_pin(s3c24xx_uda134x_l3_pins->l3_clk,
"clk") < 0) {
gpio_free(s3c24xx_uda134x_l3_pins->l3_data);
return -EBUSY;
}
if (s3c24xx_uda134x_setup_pin(s3c24xx_uda134x_l3_pins->l3_mode,
"mode") < 0) {
gpio_free(s3c24xx_uda134x_l3_pins->l3_data);
gpio_free(s3c24xx_uda134x_l3_pins->l3_clk);
return -EBUSY;
}
s3c24xx_uda134x_snd_device = platform_device_alloc("soc-audio", -1);
if (!s3c24xx_uda134x_snd_device) {
printk(KERN_ERR "S3C24XX_UDA134X SoC Audio: "
"Unable to register\n");
return -ENOMEM;
}
platform_set_drvdata(s3c24xx_uda134x_snd_device,
&snd_soc_s3c24xx_uda134x);
platform_device_add_data(s3c24xx_uda134x_snd_device, &s3c24xx_uda134x, sizeof(s3c24xx_uda134x));
ret = platform_device_add(s3c24xx_uda134x_snd_device);
if (ret) {
printk(KERN_ERR "S3C24XX_UDA134X SoC Audio: Unable to add\n");
platform_device_put(s3c24xx_uda134x_snd_device);
}
return ret;
}
static int s3c24xx_uda134x_remove(struct platform_device *pdev)
{
platform_device_unregister(s3c24xx_uda134x_snd_device);
gpio_free(s3c24xx_uda134x_l3_pins->l3_data);
gpio_free(s3c24xx_uda134x_l3_pins->l3_clk);
gpio_free(s3c24xx_uda134x_l3_pins->l3_mode);
return 0;
}
static int __init s3c24xx_uda134x_init(void)
{
return platform_driver_register(&s3c24xx_uda134x_driver);
}
static void __exit s3c24xx_uda134x_exit(void)
{
platform_driver_unregister(&s3c24xx_uda134x_driver);
}
