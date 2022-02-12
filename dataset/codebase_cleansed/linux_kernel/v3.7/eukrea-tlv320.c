static int eukrea_tlv320_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
struct snd_soc_dai *cpu_dai = rtd->cpu_dai;
int ret;
ret = snd_soc_dai_set_fmt(cpu_dai, SND_SOC_DAIFMT_I2S |
SND_SOC_DAIFMT_NB_NF |
SND_SOC_DAIFMT_CBM_CFM);
if (ret) {
pr_err("%s: failed set cpu dai format\n", __func__);
return ret;
}
ret = snd_soc_dai_set_fmt(codec_dai, SND_SOC_DAIFMT_I2S |
SND_SOC_DAIFMT_NB_NF |
SND_SOC_DAIFMT_CBM_CFM);
if (ret) {
pr_err("%s: failed set codec dai format\n", __func__);
return ret;
}
ret = snd_soc_dai_set_sysclk(codec_dai, 0,
CODEC_CLOCK, SND_SOC_CLOCK_OUT);
if (ret) {
pr_err("%s: failed setting codec sysclk\n", __func__);
return ret;
}
snd_soc_dai_set_tdm_slot(cpu_dai, 0xffffffc, 0xffffffc, 2, 0);
ret = snd_soc_dai_set_sysclk(cpu_dai, IMX_SSP_SYS_CLK, 0,
SND_SOC_CLOCK_IN);
if (ret) {
pr_err("can't set CPU system clock IMX_SSP_SYS_CLK\n");
return ret;
}
return 0;
}
static int __devinit eukrea_tlv320_probe(struct platform_device *pdev)
{
int ret;
int int_port = 0, ext_port;
if (machine_is_eukrea_cpuimx27()) {
imx_audmux_v1_configure_port(MX27_AUDMUX_HPCR1_SSI0,
IMX_AUDMUX_V1_PCR_SYN |
IMX_AUDMUX_V1_PCR_TFSDIR |
IMX_AUDMUX_V1_PCR_TCLKDIR |
IMX_AUDMUX_V1_PCR_RFSDIR |
IMX_AUDMUX_V1_PCR_RCLKDIR |
IMX_AUDMUX_V1_PCR_TFCSEL(MX27_AUDMUX_HPCR3_SSI_PINS_4) |
IMX_AUDMUX_V1_PCR_RFCSEL(MX27_AUDMUX_HPCR3_SSI_PINS_4) |
IMX_AUDMUX_V1_PCR_RXDSEL(MX27_AUDMUX_HPCR3_SSI_PINS_4)
);
imx_audmux_v1_configure_port(MX27_AUDMUX_HPCR3_SSI_PINS_4,
IMX_AUDMUX_V1_PCR_SYN |
IMX_AUDMUX_V1_PCR_RXDSEL(MX27_AUDMUX_HPCR1_SSI0)
);
} else if (machine_is_eukrea_cpuimx25sd() ||
machine_is_eukrea_cpuimx35sd() ||
machine_is_eukrea_cpuimx51sd()) {
ext_port = machine_is_eukrea_cpuimx25sd() ? 4 : 3;
imx_audmux_v2_configure_port(int_port,
IMX_AUDMUX_V2_PTCR_SYN |
IMX_AUDMUX_V2_PTCR_TFSDIR |
IMX_AUDMUX_V2_PTCR_TFSEL(ext_port) |
IMX_AUDMUX_V2_PTCR_TCLKDIR |
IMX_AUDMUX_V2_PTCR_TCSEL(ext_port),
IMX_AUDMUX_V2_PDCR_RXDSEL(ext_port)
);
imx_audmux_v2_configure_port(ext_port,
IMX_AUDMUX_V2_PTCR_SYN,
IMX_AUDMUX_V2_PDCR_RXDSEL(int_port)
);
} else {
return 0;
}
eukrea_tlv320.dev = &pdev->dev;
ret = snd_soc_register_card(&eukrea_tlv320);
if (ret)
dev_err(&pdev->dev, "snd_soc_register_card failed (%d)\n", ret);
return ret;
}
static int __devexit eukrea_tlv320_remove(struct platform_device *pdev)
{
snd_soc_unregister_card(&eukrea_tlv320);
return 0;
}
