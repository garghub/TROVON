static void tegra20_ac97_codec_reset(struct snd_ac97 *ac97)
{
u32 readback;
unsigned long timeout;
gpio_set_value(workdata->reset_gpio, 0);
udelay(2);
gpio_set_value(workdata->reset_gpio, 1);
udelay(2);
timeout = jiffies + msecs_to_jiffies(100);
do {
regmap_read(workdata->regmap, TEGRA20_AC97_STATUS1, &readback);
if (readback & TEGRA20_AC97_STATUS1_CODEC1_RDY)
break;
usleep_range(1000, 2000);
} while (!time_after(jiffies, timeout));
}
static void tegra20_ac97_codec_warm_reset(struct snd_ac97 *ac97)
{
u32 readback;
unsigned long timeout;
gpio_request(workdata->sync_gpio, "codec-sync");
gpio_direction_output(workdata->sync_gpio, 1);
udelay(2);
gpio_set_value(workdata->sync_gpio, 0);
udelay(2);
gpio_free(workdata->sync_gpio);
timeout = jiffies + msecs_to_jiffies(100);
do {
regmap_read(workdata->regmap, TEGRA20_AC97_STATUS1, &readback);
if (readback & TEGRA20_AC97_STATUS1_CODEC1_RDY)
break;
usleep_range(1000, 2000);
} while (!time_after(jiffies, timeout));
}
static unsigned short tegra20_ac97_codec_read(struct snd_ac97 *ac97_snd,
unsigned short reg)
{
u32 readback;
unsigned long timeout;
regmap_write(workdata->regmap, TEGRA20_AC97_CMD,
(((reg | 0x80) << TEGRA20_AC97_CMD_CMD_ADDR_SHIFT) &
TEGRA20_AC97_CMD_CMD_ADDR_MASK) |
TEGRA20_AC97_CMD_BUSY);
timeout = jiffies + msecs_to_jiffies(100);
do {
regmap_read(workdata->regmap, TEGRA20_AC97_STATUS1, &readback);
if (readback & TEGRA20_AC97_STATUS1_STA_VALID1)
break;
usleep_range(1000, 2000);
} while (!time_after(jiffies, timeout));
return ((readback & TEGRA20_AC97_STATUS1_STA_DATA1_MASK) >>
TEGRA20_AC97_STATUS1_STA_DATA1_SHIFT);
}
static void tegra20_ac97_codec_write(struct snd_ac97 *ac97_snd,
unsigned short reg, unsigned short val)
{
u32 readback;
unsigned long timeout;
regmap_write(workdata->regmap, TEGRA20_AC97_CMD,
((reg << TEGRA20_AC97_CMD_CMD_ADDR_SHIFT) &
TEGRA20_AC97_CMD_CMD_ADDR_MASK) |
((val << TEGRA20_AC97_CMD_CMD_DATA_SHIFT) &
TEGRA20_AC97_CMD_CMD_DATA_MASK) |
TEGRA20_AC97_CMD_BUSY);
timeout = jiffies + msecs_to_jiffies(100);
do {
regmap_read(workdata->regmap, TEGRA20_AC97_CMD, &readback);
if (!(readback & TEGRA20_AC97_CMD_BUSY))
break;
usleep_range(1000, 2000);
} while (!time_after(jiffies, timeout));
}
static inline void tegra20_ac97_start_playback(struct tegra20_ac97 *ac97)
{
regmap_update_bits(ac97->regmap, TEGRA20_AC97_FIFO1_SCR,
TEGRA20_AC97_FIFO_SCR_PB_QRT_MT_EN,
TEGRA20_AC97_FIFO_SCR_PB_QRT_MT_EN);
regmap_update_bits(ac97->regmap, TEGRA20_AC97_CTRL,
TEGRA20_AC97_CTRL_PCM_DAC_EN |
TEGRA20_AC97_CTRL_STM_EN,
TEGRA20_AC97_CTRL_PCM_DAC_EN |
TEGRA20_AC97_CTRL_STM_EN);
}
static inline void tegra20_ac97_stop_playback(struct tegra20_ac97 *ac97)
{
regmap_update_bits(ac97->regmap, TEGRA20_AC97_FIFO1_SCR,
TEGRA20_AC97_FIFO_SCR_PB_QRT_MT_EN, 0);
regmap_update_bits(ac97->regmap, TEGRA20_AC97_CTRL,
TEGRA20_AC97_CTRL_PCM_DAC_EN, 0);
}
static inline void tegra20_ac97_start_capture(struct tegra20_ac97 *ac97)
{
regmap_update_bits(ac97->regmap, TEGRA20_AC97_FIFO1_SCR,
TEGRA20_AC97_FIFO_SCR_REC_FULL_EN,
TEGRA20_AC97_FIFO_SCR_REC_FULL_EN);
}
static inline void tegra20_ac97_stop_capture(struct tegra20_ac97 *ac97)
{
regmap_update_bits(ac97->regmap, TEGRA20_AC97_FIFO1_SCR,
TEGRA20_AC97_FIFO_SCR_REC_FULL_EN, 0);
}
static int tegra20_ac97_trigger(struct snd_pcm_substream *substream, int cmd,
struct snd_soc_dai *dai)
{
struct tegra20_ac97 *ac97 = snd_soc_dai_get_drvdata(dai);
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
case SNDRV_PCM_TRIGGER_RESUME:
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
tegra20_ac97_start_playback(ac97);
else
tegra20_ac97_start_capture(ac97);
break;
case SNDRV_PCM_TRIGGER_STOP:
case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
case SNDRV_PCM_TRIGGER_SUSPEND:
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
tegra20_ac97_stop_playback(ac97);
else
tegra20_ac97_stop_capture(ac97);
break;
default:
return -EINVAL;
}
return 0;
}
static int tegra20_ac97_probe(struct snd_soc_dai *dai)
{
struct tegra20_ac97 *ac97 = snd_soc_dai_get_drvdata(dai);
dai->capture_dma_data = &ac97->capture_dma_data;
dai->playback_dma_data = &ac97->playback_dma_data;
return 0;
}
static bool tegra20_ac97_wr_rd_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case TEGRA20_AC97_CTRL:
case TEGRA20_AC97_CMD:
case TEGRA20_AC97_STATUS1:
case TEGRA20_AC97_FIFO1_SCR:
case TEGRA20_AC97_FIFO_TX1:
case TEGRA20_AC97_FIFO_RX1:
return true;
default:
break;
}
return false;
}
static bool tegra20_ac97_volatile_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case TEGRA20_AC97_STATUS1:
case TEGRA20_AC97_FIFO1_SCR:
case TEGRA20_AC97_FIFO_TX1:
case TEGRA20_AC97_FIFO_RX1:
return true;
default:
break;
}
return false;
}
static bool tegra20_ac97_precious_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case TEGRA20_AC97_FIFO_TX1:
case TEGRA20_AC97_FIFO_RX1:
return true;
default:
break;
}
return false;
}
static int tegra20_ac97_platform_probe(struct platform_device *pdev)
{
struct tegra20_ac97 *ac97;
struct resource *mem, *memregion;
u32 of_dma[2];
void __iomem *regs;
int ret = 0;
ac97 = devm_kzalloc(&pdev->dev, sizeof(struct tegra20_ac97),
GFP_KERNEL);
if (!ac97) {
dev_err(&pdev->dev, "Can't allocate tegra20_ac97\n");
ret = -ENOMEM;
goto err;
}
dev_set_drvdata(&pdev->dev, ac97);
ac97->clk_ac97 = clk_get(&pdev->dev, NULL);
if (IS_ERR(ac97->clk_ac97)) {
dev_err(&pdev->dev, "Can't retrieve ac97 clock\n");
ret = PTR_ERR(ac97->clk_ac97);
goto err;
}
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!mem) {
dev_err(&pdev->dev, "No memory resource\n");
ret = -ENODEV;
goto err_clk_put;
}
memregion = devm_request_mem_region(&pdev->dev, mem->start,
resource_size(mem), DRV_NAME);
if (!memregion) {
dev_err(&pdev->dev, "Memory region already claimed\n");
ret = -EBUSY;
goto err_clk_put;
}
regs = devm_ioremap(&pdev->dev, mem->start, resource_size(mem));
if (!regs) {
dev_err(&pdev->dev, "ioremap failed\n");
ret = -ENOMEM;
goto err_clk_put;
}
ac97->regmap = devm_regmap_init_mmio(&pdev->dev, regs,
&tegra20_ac97_regmap_config);
if (IS_ERR(ac97->regmap)) {
dev_err(&pdev->dev, "regmap init failed\n");
ret = PTR_ERR(ac97->regmap);
goto err_clk_put;
}
if (of_property_read_u32_array(pdev->dev.of_node,
"nvidia,dma-request-selector",
of_dma, 2) < 0) {
dev_err(&pdev->dev, "No DMA resource\n");
ret = -ENODEV;
goto err_clk_put;
}
ac97->reset_gpio = of_get_named_gpio(pdev->dev.of_node,
"nvidia,codec-reset-gpio", 0);
if (gpio_is_valid(ac97->reset_gpio)) {
ret = devm_gpio_request_one(&pdev->dev, ac97->reset_gpio,
GPIOF_OUT_INIT_HIGH, "codec-reset");
if (ret) {
dev_err(&pdev->dev, "could not get codec-reset GPIO\n");
goto err_clk_put;
}
} else {
dev_err(&pdev->dev, "no codec-reset GPIO supplied\n");
goto err_clk_put;
}
ac97->sync_gpio = of_get_named_gpio(pdev->dev.of_node,
"nvidia,codec-sync-gpio", 0);
if (!gpio_is_valid(ac97->sync_gpio)) {
dev_err(&pdev->dev, "no codec-sync GPIO supplied\n");
goto err_clk_put;
}
ac97->capture_dma_data.addr = mem->start + TEGRA20_AC97_FIFO_RX1;
ac97->capture_dma_data.wrap = 4;
ac97->capture_dma_data.width = 32;
ac97->capture_dma_data.req_sel = of_dma[1];
ac97->playback_dma_data.addr = mem->start + TEGRA20_AC97_FIFO_TX1;
ac97->playback_dma_data.wrap = 4;
ac97->playback_dma_data.width = 32;
ac97->playback_dma_data.req_sel = of_dma[1];
ret = snd_soc_register_dais(&pdev->dev, &tegra20_ac97_dai, 1);
if (ret) {
dev_err(&pdev->dev, "Could not register DAI: %d\n", ret);
ret = -ENOMEM;
goto err_clk_put;
}
ret = tegra_pcm_platform_register(&pdev->dev);
if (ret) {
dev_err(&pdev->dev, "Could not register PCM: %d\n", ret);
goto err_unregister_dai;
}
ret = tegra_asoc_utils_init(&ac97->util_data, &pdev->dev);
if (ret)
goto err_unregister_pcm;
ret = tegra_asoc_utils_set_ac97_rate(&ac97->util_data);
if (ret)
goto err_asoc_utils_fini;
ret = clk_prepare_enable(ac97->clk_ac97);
if (ret) {
dev_err(&pdev->dev, "clk_enable failed: %d\n", ret);
goto err_asoc_utils_fini;
}
workdata = ac97;
return 0;
err_asoc_utils_fini:
tegra_asoc_utils_fini(&ac97->util_data);
err_unregister_pcm:
tegra_pcm_platform_unregister(&pdev->dev);
err_unregister_dai:
snd_soc_unregister_dai(&pdev->dev);
err_clk_put:
clk_put(ac97->clk_ac97);
err:
return ret;
}
static int tegra20_ac97_platform_remove(struct platform_device *pdev)
{
struct tegra20_ac97 *ac97 = dev_get_drvdata(&pdev->dev);
tegra_pcm_platform_unregister(&pdev->dev);
snd_soc_unregister_dai(&pdev->dev);
tegra_asoc_utils_fini(&ac97->util_data);
clk_disable_unprepare(ac97->clk_ac97);
clk_put(ac97->clk_ac97);
return 0;
}
