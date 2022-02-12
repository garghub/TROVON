static int imx_mc13783_hifi_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *cpu_dai = rtd->cpu_dai;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
int ret;
ret = snd_soc_dai_set_tdm_slot(codec_dai, 0xfffffffc, 0xfffffffc,
4, 16);
if (ret)
return ret;
ret = snd_soc_dai_set_sysclk(codec_dai, MC13783_CLK_CLIA, 26000000, 0);
if (ret)
return ret;
ret = snd_soc_dai_set_tdm_slot(cpu_dai, 0x0, 0xfffffffc, 2, 16);
if (ret)
return ret;
return 0;
}
static int imx_mc13783_probe(struct platform_device *pdev)
{
int ret;
imx_mc13783.dev = &pdev->dev;
ret = snd_soc_register_card(&imx_mc13783);
if (ret) {
dev_err(&pdev->dev, "snd_soc_register_card failed (%d)\n",
ret);
return ret;
}
if (machine_is_mx31_3ds() || machine_is_mx31moboard()) {
imx_audmux_v2_configure_port(MX31_AUDMUX_PORT4_SSI_PINS_4,
IMX_AUDMUX_V2_PTCR_SYN,
IMX_AUDMUX_V2_PDCR_RXDSEL(MX31_AUDMUX_PORT1_SSI0) |
IMX_AUDMUX_V2_PDCR_MODE(1) |
IMX_AUDMUX_V2_PDCR_INMMASK(0xfc));
imx_audmux_v2_configure_port(MX31_AUDMUX_PORT1_SSI0,
IMX_AUDMUX_V2_PTCR_SYN |
IMX_AUDMUX_V2_PTCR_TFSDIR |
IMX_AUDMUX_V2_PTCR_TFSEL(MX31_AUDMUX_PORT4_SSI_PINS_4) |
IMX_AUDMUX_V2_PTCR_TCLKDIR |
IMX_AUDMUX_V2_PTCR_TCSEL(MX31_AUDMUX_PORT4_SSI_PINS_4) |
IMX_AUDMUX_V2_PTCR_RFSDIR |
IMX_AUDMUX_V2_PTCR_RFSEL(MX31_AUDMUX_PORT4_SSI_PINS_4) |
IMX_AUDMUX_V2_PTCR_RCLKDIR |
IMX_AUDMUX_V2_PTCR_RCSEL(MX31_AUDMUX_PORT4_SSI_PINS_4),
IMX_AUDMUX_V2_PDCR_RXDSEL(MX31_AUDMUX_PORT4_SSI_PINS_4));
} else if (machine_is_mx27_3ds()) {
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
}
return ret;
}
static int imx_mc13783_remove(struct platform_device *pdev)
{
snd_soc_unregister_card(&imx_mc13783);
return 0;
}
