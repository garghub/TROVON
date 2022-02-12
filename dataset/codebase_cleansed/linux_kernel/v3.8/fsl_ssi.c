static inline void write_ssi_mask(u32 __iomem *addr, u32 clear, u32 set)
{
u32 val = readl(addr);
val = (val & ~clear) | set;
writel(val, addr);
}
static irqreturn_t fsl_ssi_isr(int irq, void *dev_id)
{
struct fsl_ssi_private *ssi_private = dev_id;
struct ccsr_ssi __iomem *ssi = ssi_private->ssi;
irqreturn_t ret = IRQ_NONE;
__be32 sisr;
__be32 sisr2 = 0;
sisr = read_ssi(&ssi->sisr) & SIER_FLAGS;
if (sisr & CCSR_SSI_SISR_RFRC) {
ssi_private->stats.rfrc++;
sisr2 |= CCSR_SSI_SISR_RFRC;
ret = IRQ_HANDLED;
}
if (sisr & CCSR_SSI_SISR_TFRC) {
ssi_private->stats.tfrc++;
sisr2 |= CCSR_SSI_SISR_TFRC;
ret = IRQ_HANDLED;
}
if (sisr & CCSR_SSI_SISR_CMDAU) {
ssi_private->stats.cmdau++;
ret = IRQ_HANDLED;
}
if (sisr & CCSR_SSI_SISR_CMDDU) {
ssi_private->stats.cmddu++;
ret = IRQ_HANDLED;
}
if (sisr & CCSR_SSI_SISR_RXT) {
ssi_private->stats.rxt++;
ret = IRQ_HANDLED;
}
if (sisr & CCSR_SSI_SISR_RDR1) {
ssi_private->stats.rdr1++;
ret = IRQ_HANDLED;
}
if (sisr & CCSR_SSI_SISR_RDR0) {
ssi_private->stats.rdr0++;
ret = IRQ_HANDLED;
}
if (sisr & CCSR_SSI_SISR_TDE1) {
ssi_private->stats.tde1++;
ret = IRQ_HANDLED;
}
if (sisr & CCSR_SSI_SISR_TDE0) {
ssi_private->stats.tde0++;
ret = IRQ_HANDLED;
}
if (sisr & CCSR_SSI_SISR_ROE1) {
ssi_private->stats.roe1++;
sisr2 |= CCSR_SSI_SISR_ROE1;
ret = IRQ_HANDLED;
}
if (sisr & CCSR_SSI_SISR_ROE0) {
ssi_private->stats.roe0++;
sisr2 |= CCSR_SSI_SISR_ROE0;
ret = IRQ_HANDLED;
}
if (sisr & CCSR_SSI_SISR_TUE1) {
ssi_private->stats.tue1++;
sisr2 |= CCSR_SSI_SISR_TUE1;
ret = IRQ_HANDLED;
}
if (sisr & CCSR_SSI_SISR_TUE0) {
ssi_private->stats.tue0++;
sisr2 |= CCSR_SSI_SISR_TUE0;
ret = IRQ_HANDLED;
}
if (sisr & CCSR_SSI_SISR_TFS) {
ssi_private->stats.tfs++;
ret = IRQ_HANDLED;
}
if (sisr & CCSR_SSI_SISR_RFS) {
ssi_private->stats.rfs++;
ret = IRQ_HANDLED;
}
if (sisr & CCSR_SSI_SISR_TLS) {
ssi_private->stats.tls++;
ret = IRQ_HANDLED;
}
if (sisr & CCSR_SSI_SISR_RLS) {
ssi_private->stats.rls++;
ret = IRQ_HANDLED;
}
if (sisr & CCSR_SSI_SISR_RFF1) {
ssi_private->stats.rff1++;
ret = IRQ_HANDLED;
}
if (sisr & CCSR_SSI_SISR_RFF0) {
ssi_private->stats.rff0++;
ret = IRQ_HANDLED;
}
if (sisr & CCSR_SSI_SISR_TFE1) {
ssi_private->stats.tfe1++;
ret = IRQ_HANDLED;
}
if (sisr & CCSR_SSI_SISR_TFE0) {
ssi_private->stats.tfe0++;
ret = IRQ_HANDLED;
}
if (sisr2)
write_ssi(sisr2, &ssi->sisr);
return ret;
}
static int fsl_ssi_startup(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct fsl_ssi_private *ssi_private =
snd_soc_dai_get_drvdata(rtd->cpu_dai);
int synchronous = ssi_private->cpu_dai_drv.symmetric_rates;
if (!ssi_private->first_stream) {
struct ccsr_ssi __iomem *ssi = ssi_private->ssi;
ssi_private->first_stream = substream;
write_ssi_mask(&ssi->scr, CCSR_SSI_SCR_SSIEN, 0);
write_ssi_mask(&ssi->scr,
CCSR_SSI_SCR_I2S_MODE_MASK | CCSR_SSI_SCR_SYN,
CCSR_SSI_SCR_TFR_CLK_DIS | CCSR_SSI_SCR_I2S_MODE_SLAVE
| (synchronous ? CCSR_SSI_SCR_SYN : 0));
write_ssi(CCSR_SSI_STCR_TXBIT0 | CCSR_SSI_STCR_TFEN0 |
CCSR_SSI_STCR_TFSI | CCSR_SSI_STCR_TEFS |
CCSR_SSI_STCR_TSCKP, &ssi->stcr);
write_ssi(CCSR_SSI_SRCR_RXBIT0 | CCSR_SSI_SRCR_RFEN0 |
CCSR_SSI_SRCR_RFSI | CCSR_SSI_SRCR_REFS |
CCSR_SSI_SRCR_RSCKP, &ssi->srcr);
write_ssi(SIER_FLAGS, &ssi->sier);
write_ssi(CCSR_SSI_SFCSR_TFWM0(ssi_private->fifo_depth - 2) |
CCSR_SSI_SFCSR_RFWM0(ssi_private->fifo_depth - 2),
&ssi->sfcsr);
} else {
if (synchronous) {
struct snd_pcm_runtime *first_runtime =
ssi_private->first_stream->runtime;
if (!first_runtime->sample_bits) {
dev_err(substream->pcm->card->dev,
"set sample size in %s stream first\n",
substream->stream ==
SNDRV_PCM_STREAM_PLAYBACK
? "capture" : "playback");
return -EAGAIN;
}
snd_pcm_hw_constraint_minmax(substream->runtime,
SNDRV_PCM_HW_PARAM_SAMPLE_BITS,
first_runtime->sample_bits,
first_runtime->sample_bits);
}
ssi_private->second_stream = substream;
}
if (ssi_private->ssi_on_imx)
snd_soc_dai_set_dma_data(dai, substream,
(substream->stream == SNDRV_PCM_STREAM_PLAYBACK) ?
&ssi_private->dma_params_tx :
&ssi_private->dma_params_rx);
return 0;
}
static int fsl_ssi_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *hw_params, struct snd_soc_dai *cpu_dai)
{
struct fsl_ssi_private *ssi_private = snd_soc_dai_get_drvdata(cpu_dai);
struct ccsr_ssi __iomem *ssi = ssi_private->ssi;
unsigned int sample_size =
snd_pcm_format_width(params_format(hw_params));
u32 wl = CCSR_SSI_SxCCR_WL(sample_size);
int enabled = read_ssi(&ssi->scr) & CCSR_SSI_SCR_SSIEN;
if (enabled && ssi_private->cpu_dai_drv.symmetric_rates)
return 0;
if ((substream->stream == SNDRV_PCM_STREAM_PLAYBACK) ||
ssi_private->cpu_dai_drv.symmetric_rates)
write_ssi_mask(&ssi->stccr, CCSR_SSI_SxCCR_WL_MASK, wl);
else
write_ssi_mask(&ssi->srccr, CCSR_SSI_SxCCR_WL_MASK, wl);
return 0;
}
static int fsl_ssi_trigger(struct snd_pcm_substream *substream, int cmd,
struct snd_soc_dai *dai)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct fsl_ssi_private *ssi_private = snd_soc_dai_get_drvdata(rtd->cpu_dai);
struct ccsr_ssi __iomem *ssi = ssi_private->ssi;
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
write_ssi_mask(&ssi->scr, 0,
CCSR_SSI_SCR_SSIEN | CCSR_SSI_SCR_TE);
else
write_ssi_mask(&ssi->scr, 0,
CCSR_SSI_SCR_SSIEN | CCSR_SSI_SCR_RE);
break;
case SNDRV_PCM_TRIGGER_STOP:
case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
write_ssi_mask(&ssi->scr, CCSR_SSI_SCR_TE, 0);
else
write_ssi_mask(&ssi->scr, CCSR_SSI_SCR_RE, 0);
break;
default:
return -EINVAL;
}
return 0;
}
static void fsl_ssi_shutdown(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct fsl_ssi_private *ssi_private = snd_soc_dai_get_drvdata(rtd->cpu_dai);
if (ssi_private->first_stream == substream)
ssi_private->first_stream = ssi_private->second_stream;
ssi_private->second_stream = NULL;
if (!ssi_private->first_stream) {
struct ccsr_ssi __iomem *ssi = ssi_private->ssi;
write_ssi_mask(&ssi->scr, CCSR_SSI_SCR_SSIEN, 0);
}
}
static ssize_t fsl_sysfs_ssi_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct fsl_ssi_private *ssi_private =
container_of(attr, struct fsl_ssi_private, dev_attr);
ssize_t length = 0;
SIER_SHOW(RFRC_EN, rfrc);
SIER_SHOW(TFRC_EN, tfrc);
SIER_SHOW(CMDAU_EN, cmdau);
SIER_SHOW(CMDDU_EN, cmddu);
SIER_SHOW(RXT_EN, rxt);
SIER_SHOW(RDR1_EN, rdr1);
SIER_SHOW(RDR0_EN, rdr0);
SIER_SHOW(TDE1_EN, tde1);
SIER_SHOW(TDE0_EN, tde0);
SIER_SHOW(ROE1_EN, roe1);
SIER_SHOW(ROE0_EN, roe0);
SIER_SHOW(TUE1_EN, tue1);
SIER_SHOW(TUE0_EN, tue0);
SIER_SHOW(TFS_EN, tfs);
SIER_SHOW(RFS_EN, rfs);
SIER_SHOW(TLS_EN, tls);
SIER_SHOW(RLS_EN, rls);
SIER_SHOW(RFF1_EN, rff1);
SIER_SHOW(RFF0_EN, rff0);
SIER_SHOW(TFE1_EN, tfe1);
SIER_SHOW(TFE0_EN, tfe0);
return length;
}
static void make_lowercase(char *s)
{
char *p = s;
char c;
while ((c = *p)) {
if ((c >= 'A') && (c <= 'Z'))
*p = c + ('a' - 'A');
p++;
}
}
static int fsl_ssi_probe(struct platform_device *pdev)
{
struct fsl_ssi_private *ssi_private;
int ret = 0;
struct device_attribute *dev_attr = NULL;
struct device_node *np = pdev->dev.of_node;
const char *p, *sprop;
const uint32_t *iprop;
struct resource res;
char name[64];
if (!of_device_is_available(np))
return -ENODEV;
sprop = of_get_property(np, "fsl,mode", NULL);
if (!sprop || strcmp(sprop, "i2s-slave")) {
dev_notice(&pdev->dev, "mode %s is unsupported\n", sprop);
return -ENODEV;
}
p = strrchr(np->full_name, '/') + 1;
ssi_private = kzalloc(sizeof(struct fsl_ssi_private) + strlen(p),
GFP_KERNEL);
if (!ssi_private) {
dev_err(&pdev->dev, "could not allocate DAI object\n");
return -ENOMEM;
}
strcpy(ssi_private->name, p);
memcpy(&ssi_private->cpu_dai_drv, &fsl_ssi_dai_template,
sizeof(fsl_ssi_dai_template));
ssi_private->cpu_dai_drv.name = ssi_private->name;
ret = of_address_to_resource(np, 0, &res);
if (ret) {
dev_err(&pdev->dev, "could not determine device resources\n");
goto error_kmalloc;
}
ssi_private->ssi = of_iomap(np, 0);
if (!ssi_private->ssi) {
dev_err(&pdev->dev, "could not map device resources\n");
ret = -ENOMEM;
goto error_kmalloc;
}
ssi_private->ssi_phys = res.start;
ssi_private->irq = irq_of_parse_and_map(np, 0);
if (ssi_private->irq == NO_IRQ) {
dev_err(&pdev->dev, "no irq for node %s\n", np->full_name);
ret = -ENXIO;
goto error_iomap;
}
ret = request_irq(ssi_private->irq, fsl_ssi_isr, 0, ssi_private->name,
ssi_private);
if (ret < 0) {
dev_err(&pdev->dev, "could not claim irq %u\n", ssi_private->irq);
goto error_irqmap;
}
if (!of_find_property(np, "fsl,ssi-asynchronous", NULL))
ssi_private->cpu_dai_drv.symmetric_rates = 1;
iprop = of_get_property(np, "fsl,fifo-depth", NULL);
if (iprop)
ssi_private->fifo_depth = be32_to_cpup(iprop);
else
ssi_private->fifo_depth = 8;
if (of_device_is_compatible(pdev->dev.of_node, "fsl,imx21-ssi")) {
u32 dma_events[2];
ssi_private->ssi_on_imx = true;
ssi_private->clk = clk_get(&pdev->dev, NULL);
if (IS_ERR(ssi_private->clk)) {
ret = PTR_ERR(ssi_private->clk);
dev_err(&pdev->dev, "could not get clock: %d\n", ret);
goto error_irq;
}
clk_prepare_enable(ssi_private->clk);
ssi_private->dma_params_tx.burstsize =
ssi_private->fifo_depth - 2;
ssi_private->dma_params_rx.burstsize =
ssi_private->fifo_depth - 2;
ssi_private->dma_params_tx.dma_addr =
ssi_private->ssi_phys + offsetof(struct ccsr_ssi, stx0);
ssi_private->dma_params_rx.dma_addr =
ssi_private->ssi_phys + offsetof(struct ccsr_ssi, srx0);
ret = of_property_read_u32_array(pdev->dev.of_node,
"fsl,ssi-dma-events", dma_events, 2);
if (ret) {
dev_err(&pdev->dev, "could not get dma events\n");
goto error_clk;
}
ssi_private->dma_params_tx.dma = dma_events[0];
ssi_private->dma_params_rx.dma = dma_events[1];
ssi_private->dma_params_tx.shared_peripheral =
of_device_is_compatible(of_get_parent(np),
"fsl,spba-bus");
ssi_private->dma_params_rx.shared_peripheral =
ssi_private->dma_params_tx.shared_peripheral;
}
dev_attr = &ssi_private->dev_attr;
sysfs_attr_init(&dev_attr->attr);
dev_attr->attr.name = "statistics";
dev_attr->attr.mode = S_IRUGO;
dev_attr->show = fsl_sysfs_ssi_show;
ret = device_create_file(&pdev->dev, dev_attr);
if (ret) {
dev_err(&pdev->dev, "could not create sysfs %s file\n",
ssi_private->dev_attr.attr.name);
goto error_irq;
}
dev_set_drvdata(&pdev->dev, ssi_private);
ret = snd_soc_register_dai(&pdev->dev, &ssi_private->cpu_dai_drv);
if (ret) {
dev_err(&pdev->dev, "failed to register DAI: %d\n", ret);
goto error_dev;
}
if (ssi_private->ssi_on_imx) {
ssi_private->imx_pcm_pdev =
platform_device_register_simple("imx-pcm-audio",
-1, NULL, 0);
if (IS_ERR(ssi_private->imx_pcm_pdev)) {
ret = PTR_ERR(ssi_private->imx_pcm_pdev);
goto error_dev;
}
}
if (!of_get_property(np, "codec-handle", NULL)) {
ssi_private->new_binding = true;
goto done;
}
sprop = of_get_property(of_find_node_by_path("/"), "compatible", NULL);
p = strrchr(sprop, ',');
if (p)
sprop = p + 1;
snprintf(name, sizeof(name), "snd-soc-%s", sprop);
make_lowercase(name);
ssi_private->pdev =
platform_device_register_data(&pdev->dev, name, 0, NULL, 0);
if (IS_ERR(ssi_private->pdev)) {
ret = PTR_ERR(ssi_private->pdev);
dev_err(&pdev->dev, "failed to register platform: %d\n", ret);
goto error_dai;
}
done:
return 0;
error_dai:
if (ssi_private->ssi_on_imx)
platform_device_unregister(ssi_private->imx_pcm_pdev);
snd_soc_unregister_dai(&pdev->dev);
error_dev:
dev_set_drvdata(&pdev->dev, NULL);
device_remove_file(&pdev->dev, dev_attr);
error_clk:
if (ssi_private->ssi_on_imx) {
clk_disable_unprepare(ssi_private->clk);
clk_put(ssi_private->clk);
}
error_irq:
free_irq(ssi_private->irq, ssi_private);
error_irqmap:
irq_dispose_mapping(ssi_private->irq);
error_iomap:
iounmap(ssi_private->ssi);
error_kmalloc:
kfree(ssi_private);
return ret;
}
static int fsl_ssi_remove(struct platform_device *pdev)
{
struct fsl_ssi_private *ssi_private = dev_get_drvdata(&pdev->dev);
if (!ssi_private->new_binding)
platform_device_unregister(ssi_private->pdev);
if (ssi_private->ssi_on_imx) {
platform_device_unregister(ssi_private->imx_pcm_pdev);
clk_disable_unprepare(ssi_private->clk);
clk_put(ssi_private->clk);
}
snd_soc_unregister_dai(&pdev->dev);
device_remove_file(&pdev->dev, &ssi_private->dev_attr);
free_irq(ssi_private->irq, ssi_private);
irq_dispose_mapping(ssi_private->irq);
kfree(ssi_private);
dev_set_drvdata(&pdev->dev, NULL);
return 0;
}
