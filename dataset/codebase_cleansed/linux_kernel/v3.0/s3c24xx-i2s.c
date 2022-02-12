static void s3c24xx_snd_txctrl(int on)
{
u32 iisfcon;
u32 iiscon;
u32 iismod;
pr_debug("Entered %s\n", __func__);
iisfcon = readl(s3c24xx_i2s.regs + S3C2410_IISFCON);
iiscon = readl(s3c24xx_i2s.regs + S3C2410_IISCON);
iismod = readl(s3c24xx_i2s.regs + S3C2410_IISMOD);
pr_debug("r: IISCON: %x IISMOD: %x IISFCON: %x\n", iiscon, iismod, iisfcon);
if (on) {
iisfcon |= S3C2410_IISFCON_TXDMA | S3C2410_IISFCON_TXENABLE;
iiscon |= S3C2410_IISCON_TXDMAEN | S3C2410_IISCON_IISEN;
iiscon &= ~S3C2410_IISCON_TXIDLE;
iismod |= S3C2410_IISMOD_TXMODE;
writel(iismod, s3c24xx_i2s.regs + S3C2410_IISMOD);
writel(iisfcon, s3c24xx_i2s.regs + S3C2410_IISFCON);
writel(iiscon, s3c24xx_i2s.regs + S3C2410_IISCON);
} else {
iisfcon &= ~S3C2410_IISFCON_TXENABLE;
iisfcon &= ~S3C2410_IISFCON_TXDMA;
iiscon |= S3C2410_IISCON_TXIDLE;
iiscon &= ~S3C2410_IISCON_TXDMAEN;
iismod &= ~S3C2410_IISMOD_TXMODE;
writel(iiscon, s3c24xx_i2s.regs + S3C2410_IISCON);
writel(iisfcon, s3c24xx_i2s.regs + S3C2410_IISFCON);
writel(iismod, s3c24xx_i2s.regs + S3C2410_IISMOD);
}
pr_debug("w: IISCON: %x IISMOD: %x IISFCON: %x\n", iiscon, iismod, iisfcon);
}
static void s3c24xx_snd_rxctrl(int on)
{
u32 iisfcon;
u32 iiscon;
u32 iismod;
pr_debug("Entered %s\n", __func__);
iisfcon = readl(s3c24xx_i2s.regs + S3C2410_IISFCON);
iiscon = readl(s3c24xx_i2s.regs + S3C2410_IISCON);
iismod = readl(s3c24xx_i2s.regs + S3C2410_IISMOD);
pr_debug("r: IISCON: %x IISMOD: %x IISFCON: %x\n", iiscon, iismod, iisfcon);
if (on) {
iisfcon |= S3C2410_IISFCON_RXDMA | S3C2410_IISFCON_RXENABLE;
iiscon |= S3C2410_IISCON_RXDMAEN | S3C2410_IISCON_IISEN;
iiscon &= ~S3C2410_IISCON_RXIDLE;
iismod |= S3C2410_IISMOD_RXMODE;
writel(iismod, s3c24xx_i2s.regs + S3C2410_IISMOD);
writel(iisfcon, s3c24xx_i2s.regs + S3C2410_IISFCON);
writel(iiscon, s3c24xx_i2s.regs + S3C2410_IISCON);
} else {
iisfcon &= ~S3C2410_IISFCON_RXENABLE;
iisfcon &= ~S3C2410_IISFCON_RXDMA;
iiscon |= S3C2410_IISCON_RXIDLE;
iiscon &= ~S3C2410_IISCON_RXDMAEN;
iismod &= ~S3C2410_IISMOD_RXMODE;
writel(iisfcon, s3c24xx_i2s.regs + S3C2410_IISFCON);
writel(iiscon, s3c24xx_i2s.regs + S3C2410_IISCON);
writel(iismod, s3c24xx_i2s.regs + S3C2410_IISMOD);
}
pr_debug("w: IISCON: %x IISMOD: %x IISFCON: %x\n", iiscon, iismod, iisfcon);
}
static int s3c24xx_snd_lrsync(void)
{
u32 iiscon;
int timeout = 50;
pr_debug("Entered %s\n", __func__);
while (1) {
iiscon = readl(s3c24xx_i2s.regs + S3C2410_IISCON);
if (iiscon & S3C2410_IISCON_LRINDEX)
break;
if (!timeout--)
return -ETIMEDOUT;
udelay(100);
}
return 0;
}
static inline int s3c24xx_snd_is_clkmaster(void)
{
pr_debug("Entered %s\n", __func__);
return (readl(s3c24xx_i2s.regs + S3C2410_IISMOD) & S3C2410_IISMOD_SLAVE) ? 0:1;
}
static int s3c24xx_i2s_set_fmt(struct snd_soc_dai *cpu_dai,
unsigned int fmt)
{
u32 iismod;
pr_debug("Entered %s\n", __func__);
iismod = readl(s3c24xx_i2s.regs + S3C2410_IISMOD);
pr_debug("hw_params r: IISMOD: %x \n", iismod);
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBM_CFM:
iismod |= S3C2410_IISMOD_SLAVE;
break;
case SND_SOC_DAIFMT_CBS_CFS:
iismod &= ~S3C2410_IISMOD_SLAVE;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_LEFT_J:
iismod |= S3C2410_IISMOD_MSB;
break;
case SND_SOC_DAIFMT_I2S:
iismod &= ~S3C2410_IISMOD_MSB;
break;
default:
return -EINVAL;
}
writel(iismod, s3c24xx_i2s.regs + S3C2410_IISMOD);
pr_debug("hw_params w: IISMOD: %x \n", iismod);
return 0;
}
static int s3c24xx_i2s_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct s3c_dma_params *dma_data;
u32 iismod;
pr_debug("Entered %s\n", __func__);
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
dma_data = &s3c24xx_i2s_pcm_stereo_out;
else
dma_data = &s3c24xx_i2s_pcm_stereo_in;
snd_soc_dai_set_dma_data(rtd->cpu_dai, substream, dma_data);
iismod = readl(s3c24xx_i2s.regs + S3C2410_IISMOD);
pr_debug("hw_params r: IISMOD: %x\n", iismod);
switch (params_format(params)) {
case SNDRV_PCM_FORMAT_S8:
iismod &= ~S3C2410_IISMOD_16BIT;
dma_data->dma_size = 1;
break;
case SNDRV_PCM_FORMAT_S16_LE:
iismod |= S3C2410_IISMOD_16BIT;
dma_data->dma_size = 2;
break;
default:
return -EINVAL;
}
writel(iismod, s3c24xx_i2s.regs + S3C2410_IISMOD);
pr_debug("hw_params w: IISMOD: %x\n", iismod);
return 0;
}
static int s3c24xx_i2s_trigger(struct snd_pcm_substream *substream, int cmd,
struct snd_soc_dai *dai)
{
int ret = 0;
struct s3c_dma_params *dma_data =
snd_soc_dai_get_dma_data(dai, substream);
pr_debug("Entered %s\n", __func__);
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
case SNDRV_PCM_TRIGGER_RESUME:
case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
if (!s3c24xx_snd_is_clkmaster()) {
ret = s3c24xx_snd_lrsync();
if (ret)
goto exit_err;
}
if (substream->stream == SNDRV_PCM_STREAM_CAPTURE)
s3c24xx_snd_rxctrl(1);
else
s3c24xx_snd_txctrl(1);
s3c2410_dma_ctrl(dma_data->channel, S3C2410_DMAOP_STARTED);
break;
case SNDRV_PCM_TRIGGER_STOP:
case SNDRV_PCM_TRIGGER_SUSPEND:
case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
if (substream->stream == SNDRV_PCM_STREAM_CAPTURE)
s3c24xx_snd_rxctrl(0);
else
s3c24xx_snd_txctrl(0);
break;
default:
ret = -EINVAL;
break;
}
exit_err:
return ret;
}
static int s3c24xx_i2s_set_sysclk(struct snd_soc_dai *cpu_dai,
int clk_id, unsigned int freq, int dir)
{
u32 iismod = readl(s3c24xx_i2s.regs + S3C2410_IISMOD);
pr_debug("Entered %s\n", __func__);
iismod &= ~S3C2440_IISMOD_MPLL;
switch (clk_id) {
case S3C24XX_CLKSRC_PCLK:
break;
case S3C24XX_CLKSRC_MPLL:
iismod |= S3C2440_IISMOD_MPLL;
break;
default:
return -EINVAL;
}
writel(iismod, s3c24xx_i2s.regs + S3C2410_IISMOD);
return 0;
}
static int s3c24xx_i2s_set_clkdiv(struct snd_soc_dai *cpu_dai,
int div_id, int div)
{
u32 reg;
pr_debug("Entered %s\n", __func__);
switch (div_id) {
case S3C24XX_DIV_BCLK:
reg = readl(s3c24xx_i2s.regs + S3C2410_IISMOD) & ~S3C2410_IISMOD_FS_MASK;
writel(reg | div, s3c24xx_i2s.regs + S3C2410_IISMOD);
break;
case S3C24XX_DIV_MCLK:
reg = readl(s3c24xx_i2s.regs + S3C2410_IISMOD) & ~(S3C2410_IISMOD_384FS);
writel(reg | div, s3c24xx_i2s.regs + S3C2410_IISMOD);
break;
case S3C24XX_DIV_PRESCALER:
writel(div, s3c24xx_i2s.regs + S3C2410_IISPSR);
reg = readl(s3c24xx_i2s.regs + S3C2410_IISCON);
writel(reg | S3C2410_IISCON_PSCEN, s3c24xx_i2s.regs + S3C2410_IISCON);
break;
default:
return -EINVAL;
}
return 0;
}
u32 s3c24xx_i2s_get_clockrate(void)
{
return clk_get_rate(s3c24xx_i2s.iis_clk);
}
static int s3c24xx_i2s_probe(struct snd_soc_dai *dai)
{
pr_debug("Entered %s\n", __func__);
s3c24xx_i2s.regs = ioremap(S3C2410_PA_IIS, 0x100);
if (s3c24xx_i2s.regs == NULL)
return -ENXIO;
s3c24xx_i2s.iis_clk = clk_get(dai->dev, "iis");
if (s3c24xx_i2s.iis_clk == NULL) {
pr_err("failed to get iis_clock\n");
iounmap(s3c24xx_i2s.regs);
return -ENODEV;
}
clk_enable(s3c24xx_i2s.iis_clk);
s3c2410_gpio_cfgpin(S3C2410_GPE0, S3C2410_GPE0_I2SLRCK);
s3c2410_gpio_cfgpin(S3C2410_GPE1, S3C2410_GPE1_I2SSCLK);
s3c2410_gpio_cfgpin(S3C2410_GPE2, S3C2410_GPE2_CDCLK);
s3c2410_gpio_cfgpin(S3C2410_GPE3, S3C2410_GPE3_I2SSDI);
s3c2410_gpio_cfgpin(S3C2410_GPE4, S3C2410_GPE4_I2SSDO);
writel(S3C2410_IISCON_IISEN, s3c24xx_i2s.regs + S3C2410_IISCON);
s3c24xx_snd_txctrl(0);
s3c24xx_snd_rxctrl(0);
return 0;
}
static int s3c24xx_i2s_suspend(struct snd_soc_dai *cpu_dai)
{
pr_debug("Entered %s\n", __func__);
s3c24xx_i2s.iiscon = readl(s3c24xx_i2s.regs + S3C2410_IISCON);
s3c24xx_i2s.iismod = readl(s3c24xx_i2s.regs + S3C2410_IISMOD);
s3c24xx_i2s.iisfcon = readl(s3c24xx_i2s.regs + S3C2410_IISFCON);
s3c24xx_i2s.iispsr = readl(s3c24xx_i2s.regs + S3C2410_IISPSR);
clk_disable(s3c24xx_i2s.iis_clk);
return 0;
}
static int s3c24xx_i2s_resume(struct snd_soc_dai *cpu_dai)
{
pr_debug("Entered %s\n", __func__);
clk_enable(s3c24xx_i2s.iis_clk);
writel(s3c24xx_i2s.iiscon, s3c24xx_i2s.regs + S3C2410_IISCON);
writel(s3c24xx_i2s.iismod, s3c24xx_i2s.regs + S3C2410_IISMOD);
writel(s3c24xx_i2s.iisfcon, s3c24xx_i2s.regs + S3C2410_IISFCON);
writel(s3c24xx_i2s.iispsr, s3c24xx_i2s.regs + S3C2410_IISPSR);
return 0;
}
static __devinit int s3c24xx_iis_dev_probe(struct platform_device *pdev)
{
return snd_soc_register_dai(&pdev->dev, &s3c24xx_i2s_dai);
}
static __devexit int s3c24xx_iis_dev_remove(struct platform_device *pdev)
{
snd_soc_unregister_dai(&pdev->dev);
return 0;
}
static int __init s3c24xx_i2s_init(void)
{
return platform_driver_register(&s3c24xx_iis_driver);
}
static void __exit s3c24xx_i2s_exit(void)
{
platform_driver_unregister(&s3c24xx_iis_driver);
}
