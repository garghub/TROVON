static inline void tegra_spdif_write(struct tegra_spdif *spdif, u32 reg,
u32 val)
{
__raw_writel(val, spdif->regs + reg);
}
static inline u32 tegra_spdif_read(struct tegra_spdif *spdif, u32 reg)
{
return __raw_readl(spdif->regs + reg);
}
static int tegra_spdif_show(struct seq_file *s, void *unused)
{
#define REG(r) { r, #r }
static const struct {
int offset;
const char *name;
} regs[] = {
REG(TEGRA_SPDIF_CTRL),
REG(TEGRA_SPDIF_STATUS),
REG(TEGRA_SPDIF_STROBE_CTRL),
REG(TEGRA_SPDIF_DATA_FIFO_CSR),
REG(TEGRA_SPDIF_CH_STA_RX_A),
REG(TEGRA_SPDIF_CH_STA_RX_B),
REG(TEGRA_SPDIF_CH_STA_RX_C),
REG(TEGRA_SPDIF_CH_STA_RX_D),
REG(TEGRA_SPDIF_CH_STA_RX_E),
REG(TEGRA_SPDIF_CH_STA_RX_F),
REG(TEGRA_SPDIF_CH_STA_TX_A),
REG(TEGRA_SPDIF_CH_STA_TX_B),
REG(TEGRA_SPDIF_CH_STA_TX_C),
REG(TEGRA_SPDIF_CH_STA_TX_D),
REG(TEGRA_SPDIF_CH_STA_TX_E),
REG(TEGRA_SPDIF_CH_STA_TX_F),
};
#undef REG
struct tegra_spdif *spdif = s->private;
int i;
for (i = 0; i < ARRAY_SIZE(regs); i++) {
u32 val = tegra_spdif_read(spdif, regs[i].offset);
seq_printf(s, "%s = %08x\n", regs[i].name, val);
}
return 0;
}
static int tegra_spdif_debug_open(struct inode *inode, struct file *file)
{
return single_open(file, tegra_spdif_show, inode->i_private);
}
static void tegra_spdif_debug_add(struct tegra_spdif *spdif)
{
spdif->debug = debugfs_create_file(DRV_NAME, S_IRUGO,
snd_soc_debugfs_root, spdif,
&tegra_spdif_debug_fops);
}
static void tegra_spdif_debug_remove(struct tegra_spdif *spdif)
{
if (spdif->debug)
debugfs_remove(spdif->debug);
}
static inline void tegra_spdif_debug_add(struct tegra_spdif *spdif)
{
}
static inline void tegra_spdif_debug_remove(struct tegra_spdif *spdif)
{
}
static int tegra_spdif_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct device *dev = substream->pcm->card->dev;
struct tegra_spdif *spdif = snd_soc_dai_get_drvdata(dai);
int ret, srate, spdifclock;
spdif->reg_ctrl &= ~TEGRA_SPDIF_CTRL_PACK;
spdif->reg_ctrl &= ~TEGRA_SPDIF_CTRL_BIT_MODE_MASK;
switch (params_format(params)) {
case SNDRV_PCM_FORMAT_S16_LE:
spdif->reg_ctrl |= TEGRA_SPDIF_CTRL_PACK;
spdif->reg_ctrl |= TEGRA_SPDIF_CTRL_BIT_MODE_16BIT;
break;
default:
return -EINVAL;
}
srate = params_rate(params);
switch (params_rate(params)) {
case 32000:
spdifclock = 4096000;
break;
case 44100:
spdifclock = 5644800;
break;
case 48000:
spdifclock = 6144000;
break;
case 88200:
spdifclock = 11289600;
break;
case 96000:
spdifclock = 12288000;
break;
case 176400:
spdifclock = 22579200;
break;
case 192000:
spdifclock = 24576000;
break;
default:
return -EINVAL;
}
ret = clk_set_rate(spdif->clk_spdif_out, spdifclock);
if (ret) {
dev_err(dev, "Can't set SPDIF clock rate: %d\n", ret);
return ret;
}
return 0;
}
static void tegra_spdif_start_playback(struct tegra_spdif *spdif)
{
spdif->reg_ctrl |= TEGRA_SPDIF_CTRL_TX_EN;
tegra_spdif_write(spdif, TEGRA_SPDIF_CTRL, spdif->reg_ctrl);
}
static void tegra_spdif_stop_playback(struct tegra_spdif *spdif)
{
spdif->reg_ctrl &= ~TEGRA_SPDIF_CTRL_TX_EN;
tegra_spdif_write(spdif, TEGRA_SPDIF_CTRL, spdif->reg_ctrl);
}
static int tegra_spdif_trigger(struct snd_pcm_substream *substream, int cmd,
struct snd_soc_dai *dai)
{
struct tegra_spdif *spdif = snd_soc_dai_get_drvdata(dai);
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
case SNDRV_PCM_TRIGGER_RESUME:
if (!spdif->clk_refs)
clk_enable(spdif->clk_spdif_out);
spdif->clk_refs++;
tegra_spdif_start_playback(spdif);
break;
case SNDRV_PCM_TRIGGER_STOP:
case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
case SNDRV_PCM_TRIGGER_SUSPEND:
tegra_spdif_stop_playback(spdif);
spdif->clk_refs--;
if (!spdif->clk_refs)
clk_disable(spdif->clk_spdif_out);
break;
default:
return -EINVAL;
}
return 0;
}
static int tegra_spdif_probe(struct snd_soc_dai *dai)
{
struct tegra_spdif *spdif = snd_soc_dai_get_drvdata(dai);
dai->capture_dma_data = NULL;
dai->playback_dma_data = &spdif->playback_dma_data;
return 0;
}
static __devinit int tegra_spdif_platform_probe(struct platform_device *pdev)
{
struct tegra_spdif *spdif;
struct resource *mem, *memregion, *dmareq;
int ret;
spdif = kzalloc(sizeof(struct tegra_spdif), GFP_KERNEL);
if (!spdif) {
dev_err(&pdev->dev, "Can't allocate tegra_spdif\n");
ret = -ENOMEM;
goto exit;
}
dev_set_drvdata(&pdev->dev, spdif);
spdif->clk_spdif_out = clk_get(&pdev->dev, "spdif_out");
if (IS_ERR(spdif->clk_spdif_out)) {
pr_err("Can't retrieve spdif clock\n");
ret = PTR_ERR(spdif->clk_spdif_out);
goto err_free;
}
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!mem) {
dev_err(&pdev->dev, "No memory resource\n");
ret = -ENODEV;
goto err_clk_put;
}
dmareq = platform_get_resource(pdev, IORESOURCE_DMA, 0);
if (!dmareq) {
dev_err(&pdev->dev, "No DMA resource\n");
ret = -ENODEV;
goto err_clk_put;
}
memregion = request_mem_region(mem->start, resource_size(mem),
DRV_NAME);
if (!memregion) {
dev_err(&pdev->dev, "Memory region already claimed\n");
ret = -EBUSY;
goto err_clk_put;
}
spdif->regs = ioremap(mem->start, resource_size(mem));
if (!spdif->regs) {
dev_err(&pdev->dev, "ioremap failed\n");
ret = -ENOMEM;
goto err_release;
}
spdif->playback_dma_data.addr = mem->start + TEGRA_SPDIF_DATA_OUT;
spdif->playback_dma_data.wrap = 4;
spdif->playback_dma_data.width = 32;
spdif->playback_dma_data.req_sel = dmareq->start;
ret = snd_soc_register_dai(&pdev->dev, &tegra_spdif_dai);
if (ret) {
dev_err(&pdev->dev, "Could not register DAI: %d\n", ret);
ret = -ENOMEM;
goto err_unmap;
}
tegra_spdif_debug_add(spdif);
return 0;
err_unmap:
iounmap(spdif->regs);
err_release:
release_mem_region(mem->start, resource_size(mem));
err_clk_put:
clk_put(spdif->clk_spdif_out);
err_free:
kfree(spdif);
exit:
return ret;
}
static int __devexit tegra_spdif_platform_remove(struct platform_device *pdev)
{
struct tegra_spdif *spdif = dev_get_drvdata(&pdev->dev);
struct resource *res;
snd_soc_unregister_dai(&pdev->dev);
tegra_spdif_debug_remove(spdif);
iounmap(spdif->regs);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
release_mem_region(res->start, resource_size(res));
clk_put(spdif->clk_spdif_out);
kfree(spdif);
return 0;
}
static int __init snd_tegra_spdif_init(void)
{
return platform_driver_register(&tegra_spdif_driver);
}
static void __exit snd_tegra_spdif_exit(void)
{
platform_driver_unregister(&tegra_spdif_driver);
}
