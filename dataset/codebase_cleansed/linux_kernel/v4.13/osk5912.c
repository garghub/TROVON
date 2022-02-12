static int osk_startup(struct snd_pcm_substream *substream)
{
return clk_enable(tlv320aic23_mclk);
}
static void osk_shutdown(struct snd_pcm_substream *substream)
{
clk_disable(tlv320aic23_mclk);
}
static int osk_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
int err;
err =
snd_soc_dai_set_sysclk(codec_dai, 0, CODEC_CLOCK, SND_SOC_CLOCK_IN);
if (err < 0) {
printk(KERN_ERR "can't set codec system clock\n");
return err;
}
return err;
}
static int __init osk_soc_init(void)
{
int err;
u32 curRate;
struct device *dev;
if (!(machine_is_omap_osk()))
return -ENODEV;
osk_snd_device = platform_device_alloc("soc-audio", -1);
if (!osk_snd_device)
return -ENOMEM;
platform_set_drvdata(osk_snd_device, &snd_soc_card_osk);
err = platform_device_add(osk_snd_device);
if (err)
goto err1;
dev = &osk_snd_device->dev;
tlv320aic23_mclk = clk_get(dev, "mclk");
if (IS_ERR(tlv320aic23_mclk)) {
printk(KERN_ERR "Could not get mclk clock\n");
err = PTR_ERR(tlv320aic23_mclk);
goto err2;
}
curRate = (uint) clk_get_rate(tlv320aic23_mclk);
if (curRate != CODEC_CLOCK) {
if (clk_set_rate(tlv320aic23_mclk, CODEC_CLOCK)) {
printk(KERN_ERR "Cannot set MCLK for AIC23 CODEC\n");
err = -ECANCELED;
goto err3;
}
}
printk(KERN_INFO "MCLK = %d [%d]\n",
(uint) clk_get_rate(tlv320aic23_mclk), CODEC_CLOCK);
return 0;
err3:
clk_put(tlv320aic23_mclk);
err2:
platform_device_del(osk_snd_device);
err1:
platform_device_put(osk_snd_device);
return err;
}
static void __exit osk_soc_exit(void)
{
clk_put(tlv320aic23_mclk);
platform_device_unregister(osk_snd_device);
}
