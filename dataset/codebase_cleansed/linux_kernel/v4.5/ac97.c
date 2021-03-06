static void s3c_ac97_activate(struct snd_ac97 *ac97)
{
u32 ac_glbctrl, stat;
stat = readl(s3c_ac97.regs + S3C_AC97_GLBSTAT) & 0x7;
if (stat == S3C_AC97_GLBSTAT_MAINSTATE_ACTIVE)
return;
reinit_completion(&s3c_ac97.done);
ac_glbctrl = readl(s3c_ac97.regs + S3C_AC97_GLBCTRL);
ac_glbctrl = S3C_AC97_GLBCTRL_ACLINKON;
writel(ac_glbctrl, s3c_ac97.regs + S3C_AC97_GLBCTRL);
msleep(1);
ac_glbctrl |= S3C_AC97_GLBCTRL_TRANSFERDATAENABLE;
writel(ac_glbctrl, s3c_ac97.regs + S3C_AC97_GLBCTRL);
msleep(1);
ac_glbctrl = readl(s3c_ac97.regs + S3C_AC97_GLBCTRL);
ac_glbctrl |= S3C_AC97_GLBCTRL_CODECREADYIE;
writel(ac_glbctrl, s3c_ac97.regs + S3C_AC97_GLBCTRL);
if (!wait_for_completion_timeout(&s3c_ac97.done, HZ))
pr_err("AC97: Unable to activate!");
}
static unsigned short s3c_ac97_read(struct snd_ac97 *ac97,
unsigned short reg)
{
u32 ac_glbctrl, ac_codec_cmd;
u32 stat, addr, data;
mutex_lock(&s3c_ac97.lock);
s3c_ac97_activate(ac97);
reinit_completion(&s3c_ac97.done);
ac_codec_cmd = readl(s3c_ac97.regs + S3C_AC97_CODEC_CMD);
ac_codec_cmd = S3C_AC97_CODEC_CMD_READ | AC_CMD_ADDR(reg);
writel(ac_codec_cmd, s3c_ac97.regs + S3C_AC97_CODEC_CMD);
udelay(50);
ac_glbctrl = readl(s3c_ac97.regs + S3C_AC97_GLBCTRL);
ac_glbctrl |= S3C_AC97_GLBCTRL_CODECREADYIE;
writel(ac_glbctrl, s3c_ac97.regs + S3C_AC97_GLBCTRL);
if (!wait_for_completion_timeout(&s3c_ac97.done, HZ))
pr_err("AC97: Unable to read!");
stat = readl(s3c_ac97.regs + S3C_AC97_STAT);
addr = (stat >> 16) & 0x7f;
data = (stat & 0xffff);
if (addr != reg)
pr_err("ac97: req addr = %02x, rep addr = %02x\n",
reg, addr);
mutex_unlock(&s3c_ac97.lock);
return (unsigned short)data;
}
static void s3c_ac97_write(struct snd_ac97 *ac97, unsigned short reg,
unsigned short val)
{
u32 ac_glbctrl, ac_codec_cmd;
mutex_lock(&s3c_ac97.lock);
s3c_ac97_activate(ac97);
reinit_completion(&s3c_ac97.done);
ac_codec_cmd = readl(s3c_ac97.regs + S3C_AC97_CODEC_CMD);
ac_codec_cmd = AC_CMD_ADDR(reg) | AC_CMD_DATA(val);
writel(ac_codec_cmd, s3c_ac97.regs + S3C_AC97_CODEC_CMD);
udelay(50);
ac_glbctrl = readl(s3c_ac97.regs + S3C_AC97_GLBCTRL);
ac_glbctrl |= S3C_AC97_GLBCTRL_CODECREADYIE;
writel(ac_glbctrl, s3c_ac97.regs + S3C_AC97_GLBCTRL);
if (!wait_for_completion_timeout(&s3c_ac97.done, HZ))
pr_err("AC97: Unable to write!");
ac_codec_cmd = readl(s3c_ac97.regs + S3C_AC97_CODEC_CMD);
ac_codec_cmd |= S3C_AC97_CODEC_CMD_READ;
writel(ac_codec_cmd, s3c_ac97.regs + S3C_AC97_CODEC_CMD);
mutex_unlock(&s3c_ac97.lock);
}
static void s3c_ac97_cold_reset(struct snd_ac97 *ac97)
{
pr_debug("AC97: Cold reset\n");
writel(S3C_AC97_GLBCTRL_COLDRESET,
s3c_ac97.regs + S3C_AC97_GLBCTRL);
msleep(1);
writel(0, s3c_ac97.regs + S3C_AC97_GLBCTRL);
msleep(1);
}
static void s3c_ac97_warm_reset(struct snd_ac97 *ac97)
{
u32 stat;
stat = readl(s3c_ac97.regs + S3C_AC97_GLBSTAT) & 0x7;
if (stat == S3C_AC97_GLBSTAT_MAINSTATE_ACTIVE)
return;
pr_debug("AC97: Warm reset\n");
writel(S3C_AC97_GLBCTRL_WARMRESET, s3c_ac97.regs + S3C_AC97_GLBCTRL);
msleep(1);
writel(0, s3c_ac97.regs + S3C_AC97_GLBCTRL);
msleep(1);
s3c_ac97_activate(ac97);
}
static irqreturn_t s3c_ac97_irq(int irq, void *dev_id)
{
u32 ac_glbctrl, ac_glbstat;
ac_glbstat = readl(s3c_ac97.regs + S3C_AC97_GLBSTAT);
if (ac_glbstat & S3C_AC97_GLBSTAT_CODECREADY) {
ac_glbctrl = readl(s3c_ac97.regs + S3C_AC97_GLBCTRL);
ac_glbctrl &= ~S3C_AC97_GLBCTRL_CODECREADYIE;
writel(ac_glbctrl, s3c_ac97.regs + S3C_AC97_GLBCTRL);
complete(&s3c_ac97.done);
}
ac_glbctrl = readl(s3c_ac97.regs + S3C_AC97_GLBCTRL);
ac_glbctrl |= (1<<30);
writel(ac_glbctrl, s3c_ac97.regs + S3C_AC97_GLBCTRL);
return IRQ_HANDLED;
}
static int s3c_ac97_trigger(struct snd_pcm_substream *substream, int cmd,
struct snd_soc_dai *dai)
{
u32 ac_glbctrl;
ac_glbctrl = readl(s3c_ac97.regs + S3C_AC97_GLBCTRL);
if (substream->stream == SNDRV_PCM_STREAM_CAPTURE)
ac_glbctrl &= ~S3C_AC97_GLBCTRL_PCMINTM_MASK;
else
ac_glbctrl &= ~S3C_AC97_GLBCTRL_PCMOUTTM_MASK;
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
case SNDRV_PCM_TRIGGER_RESUME:
case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
if (substream->stream == SNDRV_PCM_STREAM_CAPTURE)
ac_glbctrl |= S3C_AC97_GLBCTRL_PCMINTM_DMA;
else
ac_glbctrl |= S3C_AC97_GLBCTRL_PCMOUTTM_DMA;
break;
case SNDRV_PCM_TRIGGER_STOP:
case SNDRV_PCM_TRIGGER_SUSPEND:
case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
break;
}
writel(ac_glbctrl, s3c_ac97.regs + S3C_AC97_GLBCTRL);
return 0;
}
static int s3c_ac97_mic_trigger(struct snd_pcm_substream *substream,
int cmd, struct snd_soc_dai *dai)
{
u32 ac_glbctrl;
ac_glbctrl = readl(s3c_ac97.regs + S3C_AC97_GLBCTRL);
ac_glbctrl &= ~S3C_AC97_GLBCTRL_MICINTM_MASK;
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
case SNDRV_PCM_TRIGGER_RESUME:
case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
ac_glbctrl |= S3C_AC97_GLBCTRL_MICINTM_DMA;
break;
case SNDRV_PCM_TRIGGER_STOP:
case SNDRV_PCM_TRIGGER_SUSPEND:
case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
break;
}
writel(ac_glbctrl, s3c_ac97.regs + S3C_AC97_GLBCTRL);
return 0;
}
static int s3c_ac97_dai_probe(struct snd_soc_dai *dai)
{
samsung_asoc_init_dma_data(dai, &s3c_ac97_pcm_out, &s3c_ac97_pcm_in);
return 0;
}
static int s3c_ac97_mic_dai_probe(struct snd_soc_dai *dai)
{
samsung_asoc_init_dma_data(dai, NULL, &s3c_ac97_mic_in);
return 0;
}
static int s3c_ac97_probe(struct platform_device *pdev)
{
struct resource *mem_res, *irq_res;
struct s3c_audio_pdata *ac97_pdata;
int ret;
ac97_pdata = pdev->dev.platform_data;
if (!ac97_pdata || !ac97_pdata->cfg_gpio) {
dev_err(&pdev->dev, "cfg_gpio callback not provided!\n");
return -EINVAL;
}
irq_res = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
if (!irq_res) {
dev_err(&pdev->dev, "AC97 IRQ not provided!\n");
return -ENXIO;
}
mem_res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
s3c_ac97.regs = devm_ioremap_resource(&pdev->dev, mem_res);
if (IS_ERR(s3c_ac97.regs))
return PTR_ERR(s3c_ac97.regs);
s3c_ac97_pcm_out.slave = ac97_pdata->dma_playback;
s3c_ac97_pcm_out.dma_addr = mem_res->start + S3C_AC97_PCM_DATA;
s3c_ac97_pcm_in.slave = ac97_pdata->dma_capture;
s3c_ac97_pcm_in.dma_addr = mem_res->start + S3C_AC97_PCM_DATA;
s3c_ac97_mic_in.slave = ac97_pdata->dma_capture_mic;
s3c_ac97_mic_in.dma_addr = mem_res->start + S3C_AC97_MIC_DATA;
init_completion(&s3c_ac97.done);
mutex_init(&s3c_ac97.lock);
s3c_ac97.ac97_clk = devm_clk_get(&pdev->dev, "ac97");
if (IS_ERR(s3c_ac97.ac97_clk)) {
dev_err(&pdev->dev, "ac97 failed to get ac97_clock\n");
ret = -ENODEV;
goto err2;
}
clk_prepare_enable(s3c_ac97.ac97_clk);
if (ac97_pdata->cfg_gpio(pdev)) {
dev_err(&pdev->dev, "Unable to configure gpio\n");
ret = -EINVAL;
goto err3;
}
ret = request_irq(irq_res->start, s3c_ac97_irq,
0, "AC97", NULL);
if (ret < 0) {
dev_err(&pdev->dev, "ac97: interrupt request failed.\n");
goto err4;
}
ret = snd_soc_set_ac97_ops(&s3c_ac97_ops);
if (ret != 0) {
dev_err(&pdev->dev, "Failed to set AC'97 ops: %d\n", ret);
goto err4;
}
ret = devm_snd_soc_register_component(&pdev->dev, &s3c_ac97_component,
s3c_ac97_dai, ARRAY_SIZE(s3c_ac97_dai));
if (ret)
goto err5;
ret = samsung_asoc_dma_platform_register(&pdev->dev,
ac97_pdata->dma_filter);
if (ret) {
dev_err(&pdev->dev, "failed to get register DMA: %d\n", ret);
goto err5;
}
return 0;
err5:
free_irq(irq_res->start, NULL);
err4:
err3:
clk_disable_unprepare(s3c_ac97.ac97_clk);
err2:
snd_soc_set_ac97_ops(NULL);
return ret;
}
static int s3c_ac97_remove(struct platform_device *pdev)
{
struct resource *irq_res;
irq_res = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
if (irq_res)
free_irq(irq_res->start, NULL);
clk_disable_unprepare(s3c_ac97.ac97_clk);
snd_soc_set_ac97_ops(NULL);
return 0;
}
