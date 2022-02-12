static int img_prl_out_suspend(struct device *dev)
{
struct img_prl_out *prl = dev_get_drvdata(dev);
clk_disable_unprepare(prl->clk_ref);
return 0;
}
static int img_prl_out_resume(struct device *dev)
{
struct img_prl_out *prl = dev_get_drvdata(dev);
int ret;
ret = clk_prepare_enable(prl->clk_ref);
if (ret) {
dev_err(dev, "clk_enable failed: %d\n", ret);
return ret;
}
return 0;
}
static inline void img_prl_out_writel(struct img_prl_out *prl,
u32 val, u32 reg)
{
writel(val, prl->base + reg);
}
static inline u32 img_prl_out_readl(struct img_prl_out *prl, u32 reg)
{
return readl(prl->base + reg);
}
static void img_prl_out_reset(struct img_prl_out *prl)
{
u32 ctl;
ctl = img_prl_out_readl(prl, IMG_PRL_OUT_CTL) &
~IMG_PRL_OUT_CTL_ME_MASK;
reset_control_assert(prl->rst);
reset_control_deassert(prl->rst);
img_prl_out_writel(prl, ctl, IMG_PRL_OUT_CTL);
}
static int img_prl_out_trigger(struct snd_pcm_substream *substream, int cmd,
struct snd_soc_dai *dai)
{
struct img_prl_out *prl = snd_soc_dai_get_drvdata(dai);
u32 reg;
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
case SNDRV_PCM_TRIGGER_RESUME:
case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
reg = img_prl_out_readl(prl, IMG_PRL_OUT_CTL);
reg |= IMG_PRL_OUT_CTL_ME_MASK;
img_prl_out_writel(prl, reg, IMG_PRL_OUT_CTL);
break;
case SNDRV_PCM_TRIGGER_STOP:
case SNDRV_PCM_TRIGGER_SUSPEND:
case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
img_prl_out_reset(prl);
break;
default:
return -EINVAL;
}
return 0;
}
static int img_prl_out_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params, struct snd_soc_dai *dai)
{
struct img_prl_out *prl = snd_soc_dai_get_drvdata(dai);
unsigned int rate, channels;
u32 reg, control_set = 0;
snd_pcm_format_t format;
rate = params_rate(params);
format = params_format(params);
channels = params_channels(params);
switch (params_format(params)) {
case SNDRV_PCM_FORMAT_S32_LE:
control_set |= IMG_PRL_OUT_CTL_PACKH_MASK;
break;
case SNDRV_PCM_FORMAT_S24_LE:
break;
default:
return -EINVAL;
}
if (channels != 2)
return -EINVAL;
clk_set_rate(prl->clk_ref, rate * 256);
reg = img_prl_out_readl(prl, IMG_PRL_OUT_CTL);
reg = (reg & ~IMG_PRL_OUT_CTL_PACKH_MASK) | control_set;
img_prl_out_writel(prl, reg, IMG_PRL_OUT_CTL);
return 0;
}
static int img_prl_out_set_fmt(struct snd_soc_dai *dai, unsigned int fmt)
{
struct img_prl_out *prl = snd_soc_dai_get_drvdata(dai);
u32 reg, control_set = 0;
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
break;
case SND_SOC_DAIFMT_NB_IF:
control_set |= IMG_PRL_OUT_CTL_EDGE_MASK;
break;
default:
return -EINVAL;
}
reg = img_prl_out_readl(prl, IMG_PRL_OUT_CTL);
reg = (reg & ~IMG_PRL_OUT_CTL_EDGE_MASK) | control_set;
img_prl_out_writel(prl, reg, IMG_PRL_OUT_CTL);
return 0;
}
static int img_prl_out_dai_probe(struct snd_soc_dai *dai)
{
struct img_prl_out *prl = snd_soc_dai_get_drvdata(dai);
snd_soc_dai_init_dma_data(dai, &prl->dma_data, NULL);
return 0;
}
static int img_prl_out_probe(struct platform_device *pdev)
{
struct img_prl_out *prl;
struct resource *res;
void __iomem *base;
int ret;
struct device *dev = &pdev->dev;
prl = devm_kzalloc(&pdev->dev, sizeof(*prl), GFP_KERNEL);
if (!prl)
return -ENOMEM;
platform_set_drvdata(pdev, prl);
prl->dev = &pdev->dev;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(base))
return PTR_ERR(base);
prl->base = base;
prl->rst = devm_reset_control_get(&pdev->dev, "rst");
if (IS_ERR(prl->rst)) {
if (PTR_ERR(prl->rst) != -EPROBE_DEFER)
dev_err(&pdev->dev, "No top level reset found\n");
return PTR_ERR(prl->rst);
}
prl->clk_sys = devm_clk_get(&pdev->dev, "sys");
if (IS_ERR(prl->clk_sys)) {
if (PTR_ERR(prl->clk_sys) != -EPROBE_DEFER)
dev_err(dev, "Failed to acquire clock 'sys'\n");
return PTR_ERR(prl->clk_sys);
}
prl->clk_ref = devm_clk_get(&pdev->dev, "ref");
if (IS_ERR(prl->clk_ref)) {
if (PTR_ERR(prl->clk_ref) != -EPROBE_DEFER)
dev_err(dev, "Failed to acquire clock 'ref'\n");
return PTR_ERR(prl->clk_ref);
}
ret = clk_prepare_enable(prl->clk_sys);
if (ret)
return ret;
img_prl_out_writel(prl, IMG_PRL_OUT_CTL_EDGE_MASK, IMG_PRL_OUT_CTL);
img_prl_out_reset(prl);
pm_runtime_enable(&pdev->dev);
if (!pm_runtime_enabled(&pdev->dev)) {
ret = img_prl_out_resume(&pdev->dev);
if (ret)
goto err_pm_disable;
}
prl->dma_data.addr = res->start + IMG_PRL_OUT_TX_FIFO;
prl->dma_data.addr_width = 4;
prl->dma_data.maxburst = 4;
ret = devm_snd_soc_register_component(&pdev->dev,
&img_prl_out_component,
&img_prl_out_dai, 1);
if (ret)
goto err_suspend;
ret = devm_snd_dmaengine_pcm_register(&pdev->dev, NULL, 0);
if (ret)
goto err_suspend;
return 0;
err_suspend:
if (!pm_runtime_status_suspended(&pdev->dev))
img_prl_out_suspend(&pdev->dev);
err_pm_disable:
pm_runtime_disable(&pdev->dev);
clk_disable_unprepare(prl->clk_sys);
return ret;
}
static int img_prl_out_dev_remove(struct platform_device *pdev)
{
struct img_prl_out *prl = platform_get_drvdata(pdev);
pm_runtime_disable(&pdev->dev);
if (!pm_runtime_status_suspended(&pdev->dev))
img_prl_out_suspend(&pdev->dev);
clk_disable_unprepare(prl->clk_sys);
return 0;
}
