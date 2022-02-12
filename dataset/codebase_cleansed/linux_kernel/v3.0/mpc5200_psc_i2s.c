static int psc_i2s_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct psc_dma *psc_dma = snd_soc_dai_get_drvdata(rtd->cpu_dai);
u32 mode;
dev_dbg(psc_dma->dev, "%s(substream=%p) p_size=%i p_bytes=%i"
" periods=%i buffer_size=%i buffer_bytes=%i\n",
__func__, substream, params_period_size(params),
params_period_bytes(params), params_periods(params),
params_buffer_size(params), params_buffer_bytes(params));
switch (params_format(params)) {
case SNDRV_PCM_FORMAT_S8:
mode = MPC52xx_PSC_SICR_SIM_CODEC_8;
break;
case SNDRV_PCM_FORMAT_S16_BE:
mode = MPC52xx_PSC_SICR_SIM_CODEC_16;
break;
case SNDRV_PCM_FORMAT_S24_BE:
mode = MPC52xx_PSC_SICR_SIM_CODEC_24;
break;
case SNDRV_PCM_FORMAT_S32_BE:
mode = MPC52xx_PSC_SICR_SIM_CODEC_32;
break;
default:
dev_dbg(psc_dma->dev, "invalid format\n");
return -EINVAL;
}
out_be32(&psc_dma->psc_regs->sicr, psc_dma->sicr | mode);
return 0;
}
static int psc_i2s_set_sysclk(struct snd_soc_dai *cpu_dai,
int clk_id, unsigned int freq, int dir)
{
struct psc_dma *psc_dma = snd_soc_dai_get_drvdata(cpu_dai);
dev_dbg(psc_dma->dev, "psc_i2s_set_sysclk(cpu_dai=%p, dir=%i)\n",
cpu_dai, dir);
return (dir == SND_SOC_CLOCK_IN) ? 0 : -EINVAL;
}
static int psc_i2s_set_fmt(struct snd_soc_dai *cpu_dai, unsigned int format)
{
struct psc_dma *psc_dma = snd_soc_dai_get_drvdata(cpu_dai);
dev_dbg(psc_dma->dev, "psc_i2s_set_fmt(cpu_dai=%p, format=%i)\n",
cpu_dai, format);
return (format == SND_SOC_DAIFMT_I2S) ? 0 : -EINVAL;
}
static int __devinit psc_i2s_of_probe(struct platform_device *op)
{
int rc;
struct psc_dma *psc_dma;
struct mpc52xx_psc __iomem *regs;
rc = snd_soc_register_dais(&op->dev, psc_i2s_dai, ARRAY_SIZE(psc_i2s_dai));
if (rc != 0) {
pr_err("Failed to register DAI\n");
return rc;
}
psc_dma = dev_get_drvdata(&op->dev);
regs = psc_dma->psc_regs;
psc_dma->sicr = MPC52xx_PSC_SICR_DTS1 | MPC52xx_PSC_SICR_I2S |
MPC52xx_PSC_SICR_CLKPOL;
out_be32(&psc_dma->psc_regs->sicr,
psc_dma->sicr | MPC52xx_PSC_SICR_SIM_CODEC_8);
if (!of_get_property(op->dev.of_node, "codec-handle", NULL))
return 0;
while ((in_8(&regs->ipcr_acr.ipcr) & 0x80) != 0)
;
while ((in_8(&regs->ipcr_acr.ipcr) & 0x80) == 0)
;
out_8(&psc_dma->psc_regs->command,
MPC52xx_PSC_TX_ENABLE | MPC52xx_PSC_RX_ENABLE);
return 0;
}
static int __devexit psc_i2s_of_remove(struct platform_device *op)
{
snd_soc_unregister_dais(&op->dev, ARRAY_SIZE(psc_i2s_dai));
return 0;
}
static int __init psc_i2s_init(void)
{
return platform_driver_register(&psc_i2s_driver);
}
static void __exit psc_i2s_exit(void)
{
platform_driver_unregister(&psc_i2s_driver);
}
