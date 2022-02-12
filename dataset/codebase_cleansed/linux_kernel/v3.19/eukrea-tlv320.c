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
if (ret && ret != -ENOTSUPP) {
dev_err(cpu_dai->dev,
"Failed to set the cpu dai format.\n");
return ret;
}
ret = snd_soc_dai_set_fmt(codec_dai, SND_SOC_DAIFMT_I2S |
SND_SOC_DAIFMT_NB_NF |
SND_SOC_DAIFMT_CBM_CFM);
if (ret) {
dev_err(cpu_dai->dev,
"Failed to set the codec format.\n");
return ret;
}
ret = snd_soc_dai_set_sysclk(codec_dai, 0,
CODEC_CLOCK, SND_SOC_CLOCK_OUT);
if (ret) {
dev_err(cpu_dai->dev,
"Failed to set the codec sysclk.\n");
return ret;
}
snd_soc_dai_set_tdm_slot(cpu_dai, 0xffffffc, 0xffffffc, 2, 0);
ret = snd_soc_dai_set_sysclk(cpu_dai, IMX_SSP_SYS_CLK, 0,
SND_SOC_CLOCK_IN);
if (ret && ret != -EINVAL) {
dev_err(cpu_dai->dev,
"Can't set the IMX_SSP_SYS_CLK CPU system clock.\n");
return ret;
}
return 0;
}
static int eukrea_tlv320_probe(struct platform_device *pdev)
{
int ret;
int int_port = 0, ext_port;
struct device_node *np = pdev->dev.of_node;
struct device_node *ssi_np = NULL, *codec_np = NULL;
eukrea_tlv320.dev = &pdev->dev;
if (np) {
ret = snd_soc_of_parse_card_name(&eukrea_tlv320,
"eukrea,model");
if (ret) {
dev_err(&pdev->dev,
"eukrea,model node missing or invalid.\n");
goto err;
}
ssi_np = of_parse_phandle(pdev->dev.of_node,
"ssi-controller", 0);
if (!ssi_np) {
dev_err(&pdev->dev,
"ssi-controller missing or invalid.\n");
ret = -ENODEV;
goto err;
}
codec_np = of_parse_phandle(ssi_np, "codec-handle", 0);
if (codec_np)
eukrea_tlv320_dai.codec_of_node = codec_np;
else
dev_err(&pdev->dev, "codec-handle node missing or invalid.\n");
ret = of_property_read_u32(np, "fsl,mux-int-port", &int_port);
if (ret) {
dev_err(&pdev->dev,
"fsl,mux-int-port node missing or invalid.\n");
return ret;
}
ret = of_property_read_u32(np, "fsl,mux-ext-port", &ext_port);
if (ret) {
dev_err(&pdev->dev,
"fsl,mux-ext-port node missing or invalid.\n");
return ret;
}
int_port--;
ext_port--;
eukrea_tlv320_dai.cpu_of_node = ssi_np;
eukrea_tlv320_dai.platform_of_node = ssi_np;
} else {
eukrea_tlv320_dai.cpu_dai_name = "imx-ssi.0";
eukrea_tlv320_dai.platform_name = "imx-ssi.0";
eukrea_tlv320_dai.codec_name = "tlv320aic23-codec.0-001a";
eukrea_tlv320.name = "cpuimx-audio";
}
if (machine_is_eukrea_cpuimx27() ||
of_find_compatible_node(NULL, NULL, "fsl,imx21-audmux")) {
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
machine_is_eukrea_cpuimx51sd() ||
of_find_compatible_node(NULL, NULL, "fsl,imx31-audmux")) {
if (!np)
ext_port = machine_is_eukrea_cpuimx25sd() ?
4 : 3;
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
if (np) {
dev_err(&pdev->dev,
"Missing or invalid audmux DT node.\n");
return -ENODEV;
} else {
return 0;
}
}
ret = snd_soc_register_card(&eukrea_tlv320);
err:
if (ret)
dev_err(&pdev->dev, "snd_soc_register_card failed (%d)\n", ret);
of_node_put(ssi_np);
return ret;
}
static int eukrea_tlv320_remove(struct platform_device *pdev)
{
snd_soc_unregister_card(&eukrea_tlv320);
return 0;
}
