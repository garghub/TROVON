static inline unsigned long RD(struct au1xpsc_audio_data *ctx, int reg)
{
return __raw_readl(ctx->mmio + reg);
}
static inline void WR(struct au1xpsc_audio_data *ctx, int reg, unsigned long v)
{
__raw_writel(v, ctx->mmio + reg);
wmb();
}
static unsigned short au1xac97c_ac97_read(struct snd_ac97 *ac97,
unsigned short r)
{
struct au1xpsc_audio_data *ctx = ac97_to_ctx(ac97);
unsigned int tmo, retry;
unsigned long data;
data = ~0;
retry = AC97_RW_RETRIES;
do {
mutex_lock(&ctx->lock);
tmo = 5;
while ((RD(ctx, AC97_STATUS) & STAT_CP) && tmo--)
udelay(21);
if (!tmo) {
pr_debug("ac97rd timeout #1\n");
goto next;
}
WR(ctx, AC97_CMDRESP, CMD_IDX(r) | CMD_READ);
tmo = 0x10000;
while ((RD(ctx, AC97_STATUS) & STAT_CP) && tmo--)
asm volatile ("nop");
data = RD(ctx, AC97_CMDRESP);
if (!tmo)
pr_debug("ac97rd timeout #2\n");
next:
mutex_unlock(&ctx->lock);
} while (--retry && !tmo);
pr_debug("AC97RD %04x %04lx %d\n", r, data, retry);
return retry ? data & 0xffff : 0xffff;
}
static void au1xac97c_ac97_write(struct snd_ac97 *ac97, unsigned short r,
unsigned short v)
{
struct au1xpsc_audio_data *ctx = ac97_to_ctx(ac97);
unsigned int tmo, retry;
retry = AC97_RW_RETRIES;
do {
mutex_lock(&ctx->lock);
for (tmo = 5; (RD(ctx, AC97_STATUS) & STAT_CP) && tmo; tmo--)
udelay(21);
if (!tmo) {
pr_debug("ac97wr timeout #1\n");
goto next;
}
WR(ctx, AC97_CMDRESP, CMD_WRITE | CMD_IDX(r) | CMD_SET_DATA(v));
for (tmo = 10; (RD(ctx, AC97_STATUS) & STAT_CP) && tmo; tmo--)
udelay(21);
if (!tmo)
pr_debug("ac97wr timeout #2\n");
next:
mutex_unlock(&ctx->lock);
} while (--retry && !tmo);
pr_debug("AC97WR %04x %04x %d\n", r, v, retry);
}
static void au1xac97c_ac97_warm_reset(struct snd_ac97 *ac97)
{
struct au1xpsc_audio_data *ctx = ac97_to_ctx(ac97);
WR(ctx, AC97_CONFIG, ctx->cfg | CFG_SG | CFG_SN);
msleep(20);
WR(ctx, AC97_CONFIG, ctx->cfg | CFG_SG);
WR(ctx, AC97_CONFIG, ctx->cfg);
}
static void au1xac97c_ac97_cold_reset(struct snd_ac97 *ac97)
{
struct au1xpsc_audio_data *ctx = ac97_to_ctx(ac97);
int i;
WR(ctx, AC97_CONFIG, ctx->cfg | CFG_RS);
msleep(500);
WR(ctx, AC97_CONFIG, ctx->cfg);
i = 50;
while (((RD(ctx, AC97_STATUS) & STAT_RD) == 0) && --i)
msleep(20);
if (!i)
printk(KERN_ERR "ac97c: codec not ready after cold reset\n");
}
static int alchemy_ac97c_startup(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct au1xpsc_audio_data *ctx = snd_soc_dai_get_drvdata(dai);
snd_soc_dai_set_dma_data(dai, substream, &ctx->dmaids[0]);
return 0;
}
static int au1xac97c_dai_probe(struct snd_soc_dai *dai)
{
return ac97c_workdata ? 0 : -ENODEV;
}
static int au1xac97c_drvprobe(struct platform_device *pdev)
{
int ret;
struct resource *iores, *dmares;
struct au1xpsc_audio_data *ctx;
ctx = devm_kzalloc(&pdev->dev, sizeof(*ctx), GFP_KERNEL);
if (!ctx)
return -ENOMEM;
mutex_init(&ctx->lock);
iores = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!iores)
return -ENODEV;
if (!devm_request_mem_region(&pdev->dev, iores->start,
resource_size(iores),
pdev->name))
return -EBUSY;
ctx->mmio = devm_ioremap_nocache(&pdev->dev, iores->start,
resource_size(iores));
if (!ctx->mmio)
return -EBUSY;
dmares = platform_get_resource(pdev, IORESOURCE_DMA, 0);
if (!dmares)
return -EBUSY;
ctx->dmaids[SNDRV_PCM_STREAM_PLAYBACK] = dmares->start;
dmares = platform_get_resource(pdev, IORESOURCE_DMA, 1);
if (!dmares)
return -EBUSY;
ctx->dmaids[SNDRV_PCM_STREAM_CAPTURE] = dmares->start;
WR(ctx, AC97_ENABLE, EN_D | EN_CE);
WR(ctx, AC97_ENABLE, EN_CE);
ctx->cfg = CFG_RC(3) | CFG_XS(3);
WR(ctx, AC97_CONFIG, ctx->cfg);
platform_set_drvdata(pdev, ctx);
ret = snd_soc_set_ac97_ops(&ac97c_bus_ops);
if (ret)
return ret;
ret = snd_soc_register_component(&pdev->dev, &au1xac97c_component,
&au1xac97c_dai_driver, 1);
if (ret)
return ret;
ac97c_workdata = ctx;
return 0;
}
static int au1xac97c_drvremove(struct platform_device *pdev)
{
struct au1xpsc_audio_data *ctx = platform_get_drvdata(pdev);
snd_soc_unregister_component(&pdev->dev);
WR(ctx, AC97_ENABLE, EN_D);
ac97c_workdata = NULL;
return 0;
}
static int au1xac97c_drvsuspend(struct device *dev)
{
struct au1xpsc_audio_data *ctx = dev_get_drvdata(dev);
WR(ctx, AC97_ENABLE, EN_D);
return 0;
}
static int au1xac97c_drvresume(struct device *dev)
{
struct au1xpsc_audio_data *ctx = dev_get_drvdata(dev);
WR(ctx, AC97_ENABLE, EN_D | EN_CE);
WR(ctx, AC97_ENABLE, EN_CE);
WR(ctx, AC97_CONFIG, ctx->cfg);
return 0;
}
