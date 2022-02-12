static int imx_ssi_set_dai_tdm_slot(struct snd_soc_dai *cpu_dai,
unsigned int tx_mask, unsigned int rx_mask, int slots, int slot_width)
{
struct imx_ssi *ssi = snd_soc_dai_get_drvdata(cpu_dai);
u32 sccr;
sccr = readl(ssi->base + SSI_STCCR);
sccr &= ~SSI_STCCR_DC_MASK;
sccr |= SSI_STCCR_DC(slots - 1);
writel(sccr, ssi->base + SSI_STCCR);
sccr = readl(ssi->base + SSI_SRCCR);
sccr &= ~SSI_STCCR_DC_MASK;
sccr |= SSI_STCCR_DC(slots - 1);
writel(sccr, ssi->base + SSI_SRCCR);
writel(tx_mask, ssi->base + SSI_STMSK);
writel(rx_mask, ssi->base + SSI_SRMSK);
return 0;
}
static int imx_ssi_set_dai_fmt(struct snd_soc_dai *cpu_dai, unsigned int fmt)
{
struct imx_ssi *ssi = snd_soc_dai_get_drvdata(cpu_dai);
u32 strcr = 0, scr;
scr = readl(ssi->base + SSI_SCR) & ~(SSI_SCR_SYN | SSI_SCR_NET);
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
strcr |= SSI_STCR_TFSI | SSI_STCR_TEFS | SSI_STCR_TXBIT0;
scr |= SSI_SCR_NET;
if (ssi->flags & IMX_SSI_USE_I2S_SLAVE) {
scr &= ~SSI_I2S_MODE_MASK;
scr |= SSI_SCR_I2S_MODE_SLAVE;
}
break;
case SND_SOC_DAIFMT_LEFT_J:
strcr |= SSI_STCR_TXBIT0;
break;
case SND_SOC_DAIFMT_DSP_B:
strcr |= SSI_STCR_TFSL | SSI_STCR_TXBIT0;
break;
case SND_SOC_DAIFMT_DSP_A:
strcr |= SSI_STCR_TFSL | SSI_STCR_TEFS;
break;
}
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_IB_IF:
strcr |= SSI_STCR_TFSI;
strcr &= ~SSI_STCR_TSCKP;
break;
case SND_SOC_DAIFMT_IB_NF:
strcr &= ~(SSI_STCR_TSCKP | SSI_STCR_TFSI);
break;
case SND_SOC_DAIFMT_NB_IF:
strcr |= SSI_STCR_TFSI | SSI_STCR_TSCKP;
break;
case SND_SOC_DAIFMT_NB_NF:
strcr &= ~SSI_STCR_TFSI;
strcr |= SSI_STCR_TSCKP;
break;
}
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBM_CFM:
break;
default:
return -EINVAL;
}
strcr |= SSI_STCR_TFEN0;
if (ssi->flags & IMX_SSI_NET)
scr |= SSI_SCR_NET;
if (ssi->flags & IMX_SSI_SYN)
scr |= SSI_SCR_SYN;
writel(strcr, ssi->base + SSI_STCR);
writel(strcr, ssi->base + SSI_SRCR);
writel(scr, ssi->base + SSI_SCR);
return 0;
}
static int imx_ssi_set_dai_sysclk(struct snd_soc_dai *cpu_dai,
int clk_id, unsigned int freq, int dir)
{
struct imx_ssi *ssi = snd_soc_dai_get_drvdata(cpu_dai);
u32 scr;
scr = readl(ssi->base + SSI_SCR);
switch (clk_id) {
case IMX_SSP_SYS_CLK:
if (dir == SND_SOC_CLOCK_OUT)
scr |= SSI_SCR_SYS_CLK_EN;
else
scr &= ~SSI_SCR_SYS_CLK_EN;
break;
default:
return -EINVAL;
}
writel(scr, ssi->base + SSI_SCR);
return 0;
}
static int imx_ssi_set_dai_clkdiv(struct snd_soc_dai *cpu_dai,
int div_id, int div)
{
struct imx_ssi *ssi = snd_soc_dai_get_drvdata(cpu_dai);
u32 stccr, srccr;
stccr = readl(ssi->base + SSI_STCCR);
srccr = readl(ssi->base + SSI_SRCCR);
switch (div_id) {
case IMX_SSI_TX_DIV_2:
stccr &= ~SSI_STCCR_DIV2;
stccr |= div;
break;
case IMX_SSI_TX_DIV_PSR:
stccr &= ~SSI_STCCR_PSR;
stccr |= div;
break;
case IMX_SSI_TX_DIV_PM:
stccr &= ~0xff;
stccr |= SSI_STCCR_PM(div);
break;
case IMX_SSI_RX_DIV_2:
stccr &= ~SSI_STCCR_DIV2;
stccr |= div;
break;
case IMX_SSI_RX_DIV_PSR:
stccr &= ~SSI_STCCR_PSR;
stccr |= div;
break;
case IMX_SSI_RX_DIV_PM:
stccr &= ~0xff;
stccr |= SSI_STCCR_PM(div);
break;
default:
return -EINVAL;
}
writel(stccr, ssi->base + SSI_STCCR);
writel(srccr, ssi->base + SSI_SRCCR);
return 0;
}
static int imx_ssi_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *cpu_dai)
{
struct imx_ssi *ssi = snd_soc_dai_get_drvdata(cpu_dai);
struct imx_pcm_dma_params *dma_data;
u32 reg, sccr;
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) {
reg = SSI_STCCR;
dma_data = &ssi->dma_params_tx;
} else {
reg = SSI_SRCCR;
dma_data = &ssi->dma_params_rx;
}
if (ssi->flags & IMX_SSI_SYN)
reg = SSI_STCCR;
snd_soc_dai_set_dma_data(cpu_dai, substream, dma_data);
sccr = readl(ssi->base + reg) & ~SSI_STCCR_WL_MASK;
switch (params_format(params)) {
case SNDRV_PCM_FORMAT_S16_LE:
sccr |= SSI_SRCCR_WL(16);
break;
case SNDRV_PCM_FORMAT_S20_3LE:
sccr |= SSI_SRCCR_WL(20);
break;
case SNDRV_PCM_FORMAT_S24_LE:
sccr |= SSI_SRCCR_WL(24);
break;
}
writel(sccr, ssi->base + reg);
return 0;
}
static int imx_ssi_trigger(struct snd_pcm_substream *substream, int cmd,
struct snd_soc_dai *dai)
{
struct imx_ssi *ssi = snd_soc_dai_get_drvdata(dai);
unsigned int sier_bits, sier;
unsigned int scr;
scr = readl(ssi->base + SSI_SCR);
sier = readl(ssi->base + SSI_SIER);
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) {
if (ssi->flags & IMX_SSI_DMA)
sier_bits = SSI_SIER_TDMAE;
else
sier_bits = SSI_SIER_TIE | SSI_SIER_TFE0_EN;
} else {
if (ssi->flags & IMX_SSI_DMA)
sier_bits = SSI_SIER_RDMAE;
else
sier_bits = SSI_SIER_RIE | SSI_SIER_RFF0_EN;
}
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
case SNDRV_PCM_TRIGGER_RESUME:
case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
scr |= SSI_SCR_TE;
else
scr |= SSI_SCR_RE;
sier |= sier_bits;
if (++ssi->enabled == 1)
scr |= SSI_SCR_SSIEN;
break;
case SNDRV_PCM_TRIGGER_STOP:
case SNDRV_PCM_TRIGGER_SUSPEND:
case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
scr &= ~SSI_SCR_TE;
else
scr &= ~SSI_SCR_RE;
sier &= ~sier_bits;
if (--ssi->enabled == 0)
scr &= ~SSI_SCR_SSIEN;
break;
default:
return -EINVAL;
}
if (!(ssi->flags & IMX_SSI_USE_AC97))
writel(scr, ssi->base + SSI_SCR);
writel(sier, ssi->base + SSI_SIER);
return 0;
}
int snd_imx_pcm_mmap(struct snd_pcm_substream *substream,
struct vm_area_struct *vma)
{
struct snd_pcm_runtime *runtime = substream->runtime;
int ret;
ret = dma_mmap_coherent(NULL, vma, runtime->dma_area,
runtime->dma_addr, runtime->dma_bytes);
pr_debug("%s: ret: %d %p 0x%08x 0x%08x\n", __func__, ret,
runtime->dma_area,
runtime->dma_addr,
runtime->dma_bytes);
return ret;
}
static int imx_pcm_preallocate_dma_buffer(struct snd_pcm *pcm, int stream)
{
struct snd_pcm_substream *substream = pcm->streams[stream].substream;
struct snd_dma_buffer *buf = &substream->dma_buffer;
size_t size = IMX_SSI_DMABUF_SIZE;
buf->dev.type = SNDRV_DMA_TYPE_DEV;
buf->dev.dev = pcm->card->dev;
buf->private_data = NULL;
buf->area = dma_alloc_writecombine(pcm->card->dev, size,
&buf->addr, GFP_KERNEL);
if (!buf->area)
return -ENOMEM;
buf->bytes = size;
return 0;
}
int imx_pcm_new(struct snd_soc_pcm_runtime *rtd)
{
struct snd_card *card = rtd->card->snd_card;
struct snd_soc_dai *dai = rtd->cpu_dai;
struct snd_pcm *pcm = rtd->pcm;
int ret = 0;
if (!card->dev->dma_mask)
card->dev->dma_mask = &imx_pcm_dmamask;
if (!card->dev->coherent_dma_mask)
card->dev->coherent_dma_mask = DMA_BIT_MASK(32);
if (dai->driver->playback.channels_min) {
ret = imx_pcm_preallocate_dma_buffer(pcm,
SNDRV_PCM_STREAM_PLAYBACK);
if (ret)
goto out;
}
if (dai->driver->capture.channels_min) {
ret = imx_pcm_preallocate_dma_buffer(pcm,
SNDRV_PCM_STREAM_CAPTURE);
if (ret)
goto out;
}
out:
return ret;
}
void imx_pcm_free(struct snd_pcm *pcm)
{
struct snd_pcm_substream *substream;
struct snd_dma_buffer *buf;
int stream;
for (stream = 0; stream < 2; stream++) {
substream = pcm->streams[stream].substream;
if (!substream)
continue;
buf = &substream->dma_buffer;
if (!buf->area)
continue;
dma_free_writecombine(pcm->card->dev, buf->bytes,
buf->area, buf->addr);
buf->area = NULL;
}
}
static int imx_ssi_dai_probe(struct snd_soc_dai *dai)
{
struct imx_ssi *ssi = dev_get_drvdata(dai->dev);
uint32_t val;
snd_soc_dai_set_drvdata(dai, ssi);
val = SSI_SFCSR_TFWM0(ssi->dma_params_tx.burstsize) |
SSI_SFCSR_RFWM0(ssi->dma_params_rx.burstsize);
writel(val, ssi->base + SSI_SFCSR);
return 0;
}
static void setup_channel_to_ac97(struct imx_ssi *imx_ssi)
{
void __iomem *base = imx_ssi->base;
writel(0x0, base + SSI_SCR);
writel(0x0, base + SSI_STCR);
writel(0x0, base + SSI_SRCR);
writel(SSI_SCR_SYN | SSI_SCR_NET, base + SSI_SCR);
writel(SSI_SFCSR_RFWM0(8) |
SSI_SFCSR_TFWM0(8) |
SSI_SFCSR_RFWM1(8) |
SSI_SFCSR_TFWM1(8), base + SSI_SFCSR);
writel(SSI_STCCR_WL(16) | SSI_STCCR_DC(12), base + SSI_STCCR);
writel(SSI_STCCR_WL(16) | SSI_STCCR_DC(12), base + SSI_SRCCR);
writel(SSI_SCR_SYN | SSI_SCR_NET | SSI_SCR_SSIEN, base + SSI_SCR);
writel(SSI_SOR_WAIT(3), base + SSI_SOR);
writel(SSI_SCR_SYN | SSI_SCR_NET | SSI_SCR_SSIEN |
SSI_SCR_TE | SSI_SCR_RE,
base + SSI_SCR);
writel(SSI_SACNT_DEFAULT, base + SSI_SACNT);
writel(0xff, base + SSI_SACCDIS);
writel(0x300, base + SSI_SACCEN);
}
static void imx_ssi_ac97_write(struct snd_ac97 *ac97, unsigned short reg,
unsigned short val)
{
struct imx_ssi *imx_ssi = ac97_ssi;
void __iomem *base = imx_ssi->base;
unsigned int lreg;
unsigned int lval;
if (reg > 0x7f)
return;
pr_debug("%s: 0x%02x 0x%04x\n", __func__, reg, val);
lreg = reg << 12;
writel(lreg, base + SSI_SACADD);
lval = val << 4;
writel(lval , base + SSI_SACDAT);
writel(SSI_SACNT_DEFAULT | SSI_SACNT_WR, base + SSI_SACNT);
udelay(100);
}
static unsigned short imx_ssi_ac97_read(struct snd_ac97 *ac97,
unsigned short reg)
{
struct imx_ssi *imx_ssi = ac97_ssi;
void __iomem *base = imx_ssi->base;
unsigned short val = -1;
unsigned int lreg;
lreg = (reg & 0x7f) << 12 ;
writel(lreg, base + SSI_SACADD);
writel(SSI_SACNT_DEFAULT | SSI_SACNT_RD, base + SSI_SACNT);
udelay(100);
val = (readl(base + SSI_SACDAT) >> 4) & 0xffff;
pr_debug("%s: 0x%02x 0x%04x\n", __func__, reg, val);
return val;
}
static void imx_ssi_ac97_reset(struct snd_ac97 *ac97)
{
struct imx_ssi *imx_ssi = ac97_ssi;
if (imx_ssi->ac97_reset)
imx_ssi->ac97_reset(ac97);
}
static void imx_ssi_ac97_warm_reset(struct snd_ac97 *ac97)
{
struct imx_ssi *imx_ssi = ac97_ssi;
if (imx_ssi->ac97_warm_reset)
imx_ssi->ac97_warm_reset(ac97);
}
static int imx_ssi_probe(struct platform_device *pdev)
{
struct resource *res;
struct imx_ssi *ssi;
struct imx_ssi_platform_data *pdata = pdev->dev.platform_data;
int ret = 0;
struct snd_soc_dai_driver *dai;
ssi = kzalloc(sizeof(*ssi), GFP_KERNEL);
if (!ssi)
return -ENOMEM;
dev_set_drvdata(&pdev->dev, ssi);
if (pdata) {
ssi->ac97_reset = pdata->ac97_reset;
ssi->ac97_warm_reset = pdata->ac97_warm_reset;
ssi->flags = pdata->flags;
}
ssi->irq = platform_get_irq(pdev, 0);
ssi->clk = clk_get(&pdev->dev, NULL);
if (IS_ERR(ssi->clk)) {
ret = PTR_ERR(ssi->clk);
dev_err(&pdev->dev, "Cannot get the clock: %d\n",
ret);
goto failed_clk;
}
clk_enable(ssi->clk);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
ret = -ENODEV;
goto failed_get_resource;
}
if (!request_mem_region(res->start, resource_size(res), DRV_NAME)) {
dev_err(&pdev->dev, "request_mem_region failed\n");
ret = -EBUSY;
goto failed_get_resource;
}
ssi->base = ioremap(res->start, resource_size(res));
if (!ssi->base) {
dev_err(&pdev->dev, "ioremap failed\n");
ret = -ENODEV;
goto failed_ioremap;
}
if (ssi->flags & IMX_SSI_USE_AC97) {
if (ac97_ssi) {
ret = -EBUSY;
goto failed_ac97;
}
ac97_ssi = ssi;
setup_channel_to_ac97(ssi);
dai = &imx_ac97_dai;
} else
dai = &imx_ssi_dai;
writel(0x0, ssi->base + SSI_SIER);
ssi->dma_params_rx.dma_addr = res->start + SSI_SRX0;
ssi->dma_params_tx.dma_addr = res->start + SSI_STX0;
ssi->dma_params_tx.burstsize = 4;
ssi->dma_params_rx.burstsize = 4;
res = platform_get_resource_byname(pdev, IORESOURCE_DMA, "tx0");
if (res)
ssi->dma_params_tx.dma = res->start;
res = platform_get_resource_byname(pdev, IORESOURCE_DMA, "rx0");
if (res)
ssi->dma_params_rx.dma = res->start;
platform_set_drvdata(pdev, ssi);
ret = snd_soc_register_dai(&pdev->dev, dai);
if (ret) {
dev_err(&pdev->dev, "register DAI failed\n");
goto failed_register;
}
ssi->soc_platform_pdev_fiq = platform_device_alloc("imx-fiq-pcm-audio", pdev->id);
if (!ssi->soc_platform_pdev_fiq) {
ret = -ENOMEM;
goto failed_pdev_fiq_alloc;
}
platform_set_drvdata(ssi->soc_platform_pdev_fiq, ssi);
ret = platform_device_add(ssi->soc_platform_pdev_fiq);
if (ret) {
dev_err(&pdev->dev, "failed to add platform device\n");
goto failed_pdev_fiq_add;
}
ssi->soc_platform_pdev = platform_device_alloc("imx-pcm-audio", pdev->id);
if (!ssi->soc_platform_pdev) {
ret = -ENOMEM;
goto failed_pdev_alloc;
}
platform_set_drvdata(ssi->soc_platform_pdev, ssi);
ret = platform_device_add(ssi->soc_platform_pdev);
if (ret) {
dev_err(&pdev->dev, "failed to add platform device\n");
goto failed_pdev_add;
}
return 0;
failed_pdev_add:
platform_device_put(ssi->soc_platform_pdev);
failed_pdev_alloc:
platform_device_del(ssi->soc_platform_pdev_fiq);
failed_pdev_fiq_add:
platform_device_put(ssi->soc_platform_pdev_fiq);
failed_pdev_fiq_alloc:
snd_soc_unregister_dai(&pdev->dev);
failed_register:
failed_ac97:
iounmap(ssi->base);
failed_ioremap:
release_mem_region(res->start, resource_size(res));
failed_get_resource:
clk_disable(ssi->clk);
clk_put(ssi->clk);
failed_clk:
kfree(ssi);
return ret;
}
static int __devexit imx_ssi_remove(struct platform_device *pdev)
{
struct resource *res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
struct imx_ssi *ssi = platform_get_drvdata(pdev);
platform_device_unregister(ssi->soc_platform_pdev);
platform_device_unregister(ssi->soc_platform_pdev_fiq);
snd_soc_unregister_dai(&pdev->dev);
if (ssi->flags & IMX_SSI_USE_AC97)
ac97_ssi = NULL;
iounmap(ssi->base);
release_mem_region(res->start, resource_size(res));
clk_disable(ssi->clk);
clk_put(ssi->clk);
kfree(ssi);
return 0;
}
static int __init imx_ssi_init(void)
{
return platform_driver_register(&imx_ssi_driver);
}
static void __exit imx_ssi_exit(void)
{
platform_driver_unregister(&imx_ssi_driver);
}
