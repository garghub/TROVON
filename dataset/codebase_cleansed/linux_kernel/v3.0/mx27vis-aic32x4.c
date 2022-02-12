static int mx27vis_aic32x4_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
struct snd_soc_dai *cpu_dai = rtd->cpu_dai;
int ret;
u32 dai_format;
dai_format = SND_SOC_DAIFMT_DSP_B | SND_SOC_DAIFMT_NB_NF |
SND_SOC_DAIFMT_CBM_CFM;
snd_soc_dai_set_fmt(codec_dai, dai_format);
snd_soc_dai_set_fmt(cpu_dai, dai_format);
ret = snd_soc_dai_set_sysclk(codec_dai, 0,
25000000, SND_SOC_CLOCK_OUT);
if (ret) {
pr_err("%s: failed setting codec sysclk\n", __func__);
return ret;
}
ret = snd_soc_dai_set_sysclk(cpu_dai, IMX_SSP_SYS_CLK, 0,
SND_SOC_CLOCK_IN);
if (ret) {
pr_err("can't set CPU system clock IMX_SSP_SYS_CLK\n");
return ret;
}
return 0;
}
static int __init mx27vis_aic32x4_init(void)
{
int ret;
mx27vis_aic32x4_snd_device = platform_device_alloc("soc-audio", -1);
if (!mx27vis_aic32x4_snd_device)
return -ENOMEM;
platform_set_drvdata(mx27vis_aic32x4_snd_device, &mx27vis_aic32x4);
ret = platform_device_add(mx27vis_aic32x4_snd_device);
if (ret) {
printk(KERN_ERR "ASoC: Platform device allocation failed\n");
platform_device_put(mx27vis_aic32x4_snd_device);
}
mxc_audmux_v1_configure_port(MX27_AUDMUX_HPCR1_SSI0,
MXC_AUDMUX_V1_PCR_SYN |
MXC_AUDMUX_V1_PCR_TFSDIR |
MXC_AUDMUX_V1_PCR_TCLKDIR |
MXC_AUDMUX_V1_PCR_TFCSEL(MX27_AUDMUX_PPCR1_SSI_PINS_1) |
MXC_AUDMUX_V1_PCR_RXDSEL(MX27_AUDMUX_PPCR1_SSI_PINS_1)
);
mxc_audmux_v1_configure_port(MX27_AUDMUX_PPCR1_SSI_PINS_1,
MXC_AUDMUX_V1_PCR_SYN |
MXC_AUDMUX_V1_PCR_RXDSEL(MX27_AUDMUX_HPCR1_SSI0)
);
return ret;
}
static void __exit mx27vis_aic32x4_exit(void)
{
platform_device_unregister(mx27vis_aic32x4_snd_device);
}
