static inline unsigned ep93xx_ac97_read_reg(struct ep93xx_ac97_info *info,
unsigned reg)
{
return __raw_readl(info->regs + reg);
}
static inline void ep93xx_ac97_write_reg(struct ep93xx_ac97_info *info,
unsigned reg, unsigned val)
{
__raw_writel(val, info->regs + reg);
}
static unsigned short ep93xx_ac97_read(struct snd_ac97 *ac97,
unsigned short reg)
{
struct ep93xx_ac97_info *info = ep93xx_ac97_info;
unsigned short val;
mutex_lock(&info->lock);
ep93xx_ac97_write_reg(info, AC97S1DATA, reg);
ep93xx_ac97_write_reg(info, AC97IM, AC97_SLOT2RXVALID);
if (!wait_for_completion_timeout(&info->done, AC97_TIMEOUT)) {
dev_warn(info->dev, "timeout reading register %x\n", reg);
mutex_unlock(&info->lock);
return -ETIMEDOUT;
}
val = (unsigned short)ep93xx_ac97_read_reg(info, AC97S2DATA);
mutex_unlock(&info->lock);
return val;
}
static void ep93xx_ac97_write(struct snd_ac97 *ac97,
unsigned short reg,
unsigned short val)
{
struct ep93xx_ac97_info *info = ep93xx_ac97_info;
mutex_lock(&info->lock);
ep93xx_ac97_write_reg(info, AC97S2DATA, val);
ep93xx_ac97_write_reg(info, AC97S1DATA, reg);
ep93xx_ac97_write_reg(info, AC97IM, AC97_SLOT2TXCOMPLETE);
if (!wait_for_completion_timeout(&info->done, AC97_TIMEOUT))
dev_warn(info->dev, "timeout writing register %x\n", reg);
mutex_unlock(&info->lock);
}
static void ep93xx_ac97_warm_reset(struct snd_ac97 *ac97)
{
struct ep93xx_ac97_info *info = ep93xx_ac97_info;
mutex_lock(&info->lock);
ep93xx_ac97_write_reg(info, AC97SYNC, AC97SYNC_TIMEDSYNC);
ep93xx_ac97_write_reg(info, AC97IM, AC97_CODECREADY);
if (!wait_for_completion_timeout(&info->done, AC97_TIMEOUT))
dev_warn(info->dev, "codec warm reset timeout\n");
mutex_unlock(&info->lock);
}
static void ep93xx_ac97_cold_reset(struct snd_ac97 *ac97)
{
struct ep93xx_ac97_info *info = ep93xx_ac97_info;
mutex_lock(&info->lock);
ep93xx_ac97_write_reg(info, AC97GCR, 0);
ep93xx_ac97_write_reg(info, AC97EOI, AC97EOI_CODECREADY | AC97EOI_WINT);
ep93xx_ac97_write_reg(info, AC97GCR, AC97GCR_AC97IFE);
ep93xx_ac97_write_reg(info, AC97RESET, AC97RESET_TIMEDRESET);
ep93xx_ac97_write_reg(info, AC97IM, AC97_CODECREADY);
if (!wait_for_completion_timeout(&info->done, AC97_TIMEOUT))
dev_warn(info->dev, "codec cold reset timeout\n");
usleep_range(15000, 20000);
mutex_unlock(&info->lock);
}
static irqreturn_t ep93xx_ac97_interrupt(int irq, void *dev_id)
{
struct ep93xx_ac97_info *info = dev_id;
unsigned status, mask;
status = ep93xx_ac97_read_reg(info, AC97GIS);
mask = ep93xx_ac97_read_reg(info, AC97IM);
mask &= ~status;
ep93xx_ac97_write_reg(info, AC97IM, mask);
complete(&info->done);
return IRQ_HANDLED;
}
static int ep93xx_ac97_trigger(struct snd_pcm_substream *substream,
int cmd, struct snd_soc_dai *dai)
{
struct ep93xx_ac97_info *info = snd_soc_dai_get_drvdata(dai);
unsigned v = 0;
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
case SNDRV_PCM_TRIGGER_RESUME:
case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) {
v |= AC97TXCR_CM;
v |= AC97TXCR_TX3 | AC97TXCR_TX4;
v |= AC97TXCR_TEN;
ep93xx_ac97_write_reg(info, AC97TXCR(1), v);
} else {
v |= AC97RXCR_CM;
v |= AC97RXCR_RX3 | AC97RXCR_RX4;
v |= AC97RXCR_REN;
ep93xx_ac97_write_reg(info, AC97RXCR(1), v);
}
break;
case SNDRV_PCM_TRIGGER_STOP:
case SNDRV_PCM_TRIGGER_SUSPEND:
case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) {
unsigned long timeout = jiffies + AC97_TIMEOUT;
do {
v = ep93xx_ac97_read_reg(info, AC97SR(1));
if (time_after(jiffies, timeout)) {
dev_warn(info->dev, "TX timeout\n");
break;
}
} while (!(v & (AC97SR_TXFE | AC97SR_TXUE)));
ep93xx_ac97_write_reg(info, AC97TXCR(1), 0);
} else {
ep93xx_ac97_write_reg(info, AC97RXCR(1), 0);
}
break;
default:
dev_warn(info->dev, "unknown command %d\n", cmd);
return -EINVAL;
}
return 0;
}
static int ep93xx_ac97_dai_probe(struct snd_soc_dai *dai)
{
dai->playback_dma_data = &ep93xx_ac97_pcm_out;
dai->capture_dma_data = &ep93xx_ac97_pcm_in;
return 0;
}
static int ep93xx_ac97_probe(struct platform_device *pdev)
{
struct ep93xx_ac97_info *info;
struct resource *res;
unsigned int irq;
int ret;
info = devm_kzalloc(&pdev->dev, sizeof(*info), GFP_KERNEL);
if (!info)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res)
return -ENODEV;
info->regs = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(info->regs))
return PTR_ERR(info->regs);
irq = platform_get_irq(pdev, 0);
if (!irq)
return -ENODEV;
ret = devm_request_irq(&pdev->dev, irq, ep93xx_ac97_interrupt,
IRQF_TRIGGER_HIGH, pdev->name, info);
if (ret)
goto fail;
dev_set_drvdata(&pdev->dev, info);
mutex_init(&info->lock);
init_completion(&info->done);
info->dev = &pdev->dev;
ep93xx_ac97_info = info;
platform_set_drvdata(pdev, info);
ret = snd_soc_set_ac97_ops(&ep93xx_ac97_ops);
if (ret)
goto fail;
ret = snd_soc_register_component(&pdev->dev, &ep93xx_ac97_component,
&ep93xx_ac97_dai, 1);
if (ret)
goto fail;
return 0;
fail:
ep93xx_ac97_info = NULL;
snd_soc_set_ac97_ops(NULL);
return ret;
}
static int ep93xx_ac97_remove(struct platform_device *pdev)
{
struct ep93xx_ac97_info *info = platform_get_drvdata(pdev);
snd_soc_unregister_component(&pdev->dev);
ep93xx_ac97_write_reg(info, AC97GCR, 0);
ep93xx_ac97_info = NULL;
snd_soc_set_ac97_ops(NULL);
return 0;
}
