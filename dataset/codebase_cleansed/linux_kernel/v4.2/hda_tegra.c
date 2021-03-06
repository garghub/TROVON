static int dma_alloc_pages(struct hdac_bus *bus, int type, size_t size,
struct snd_dma_buffer *buf)
{
return snd_dma_alloc_pages(type, bus->dev, size, buf);
}
static void dma_free_pages(struct hdac_bus *bus, struct snd_dma_buffer *buf)
{
snd_dma_free_pages(buf);
}
static int substream_alloc_pages(struct azx *chip,
struct snd_pcm_substream *substream,
size_t size)
{
return snd_pcm_lib_malloc_pages(substream, size);
}
static int substream_free_pages(struct azx *chip,
struct snd_pcm_substream *substream)
{
return snd_pcm_lib_free_pages(substream);
}
static void hda_tegra_writel(u32 value, u32 *addr)
{
writel(value, addr);
}
static u32 hda_tegra_readl(u32 *addr)
{
return readl(addr);
}
static void hda_tegra_writew(u16 value, u16 *addr)
{
unsigned int shift = ((unsigned long)(addr) & 0x3) << 3;
void *dword_addr = (void *)((unsigned long)(addr) & ~0x3);
u32 v;
v = readl(dword_addr);
v &= ~(0xffff << shift);
v |= value << shift;
writel(v, dword_addr);
}
static u16 hda_tegra_readw(u16 *addr)
{
unsigned int shift = ((unsigned long)(addr) & 0x3) << 3;
void *dword_addr = (void *)((unsigned long)(addr) & ~0x3);
u32 v;
v = readl(dword_addr);
return (v >> shift) & 0xffff;
}
static void hda_tegra_writeb(u8 value, u8 *addr)
{
unsigned int shift = ((unsigned long)(addr) & 0x3) << 3;
void *dword_addr = (void *)((unsigned long)(addr) & ~0x3);
u32 v;
v = readl(dword_addr);
v &= ~(0xff << shift);
v |= value << shift;
writel(v, dword_addr);
}
static u8 hda_tegra_readb(u8 *addr)
{
unsigned int shift = ((unsigned long)(addr) & 0x3) << 3;
void *dword_addr = (void *)((unsigned long)(addr) & ~0x3);
u32 v;
v = readl(dword_addr);
return (v >> shift) & 0xff;
}
static void hda_tegra_init(struct hda_tegra *hda)
{
u32 v;
v = readl(hda->regs + HDA_IPFS_CONFIG);
v |= HDA_IPFS_EN_FPCI;
writel(v, hda->regs + HDA_IPFS_CONFIG);
v = readl(hda->regs + HDA_CFG_CMD);
v &= ~HDA_DISABLE_INTR;
v |= HDA_ENABLE_MEM_SPACE | HDA_ENABLE_IO_SPACE |
HDA_ENABLE_BUS_MASTER | HDA_ENABLE_SERR;
writel(v, hda->regs + HDA_CFG_CMD);
writel(HDA_BAR0_INIT_PROGRAM, hda->regs + HDA_CFG_BAR0);
writel(HDA_BAR0_FINAL_PROGRAM, hda->regs + HDA_CFG_BAR0);
writel(HDA_FPCI_BAR0_START, hda->regs + HDA_IPFS_FPCI_BAR0);
v = readl(hda->regs + HDA_IPFS_INTR_MASK);
v |= HDA_IPFS_EN_INTR;
writel(v, hda->regs + HDA_IPFS_INTR_MASK);
}
static int hda_tegra_enable_clocks(struct hda_tegra *data)
{
int rc;
rc = clk_prepare_enable(data->hda_clk);
if (rc)
return rc;
rc = clk_prepare_enable(data->hda2codec_2x_clk);
if (rc)
goto disable_hda;
rc = clk_prepare_enable(data->hda2hdmi_clk);
if (rc)
goto disable_codec_2x;
return 0;
disable_codec_2x:
clk_disable_unprepare(data->hda2codec_2x_clk);
disable_hda:
clk_disable_unprepare(data->hda_clk);
return rc;
}
static void hda_tegra_disable_clocks(struct hda_tegra *data)
{
clk_disable_unprepare(data->hda2hdmi_clk);
clk_disable_unprepare(data->hda2codec_2x_clk);
clk_disable_unprepare(data->hda_clk);
}
static int hda_tegra_suspend(struct device *dev)
{
struct snd_card *card = dev_get_drvdata(dev);
struct azx *chip = card->private_data;
struct hda_tegra *hda = container_of(chip, struct hda_tegra, chip);
snd_power_change_state(card, SNDRV_CTL_POWER_D3hot);
azx_stop_chip(chip);
azx_enter_link_reset(chip);
hda_tegra_disable_clocks(hda);
return 0;
}
static int hda_tegra_resume(struct device *dev)
{
struct snd_card *card = dev_get_drvdata(dev);
struct azx *chip = card->private_data;
struct hda_tegra *hda = container_of(chip, struct hda_tegra, chip);
hda_tegra_enable_clocks(hda);
hda_tegra_init(hda);
azx_init_chip(chip, 1);
snd_power_change_state(card, SNDRV_CTL_POWER_D0);
return 0;
}
static int hda_tegra_dev_disconnect(struct snd_device *device)
{
struct azx *chip = device->device_data;
chip->bus.shutdown = 1;
return 0;
}
static int hda_tegra_dev_free(struct snd_device *device)
{
struct azx *chip = device->device_data;
if (azx_bus(chip)->chip_init) {
azx_stop_all_streams(chip);
azx_stop_chip(chip);
}
azx_free_stream_pages(chip);
azx_free_streams(chip);
snd_hdac_bus_exit(azx_bus(chip));
return 0;
}
static int hda_tegra_init_chip(struct azx *chip, struct platform_device *pdev)
{
struct hda_tegra *hda = container_of(chip, struct hda_tegra, chip);
struct hdac_bus *bus = azx_bus(chip);
struct device *dev = hda->dev;
struct resource *res;
int err;
hda->hda_clk = devm_clk_get(dev, "hda");
if (IS_ERR(hda->hda_clk)) {
dev_err(dev, "failed to get hda clock\n");
return PTR_ERR(hda->hda_clk);
}
hda->hda2codec_2x_clk = devm_clk_get(dev, "hda2codec_2x");
if (IS_ERR(hda->hda2codec_2x_clk)) {
dev_err(dev, "failed to get hda2codec_2x clock\n");
return PTR_ERR(hda->hda2codec_2x_clk);
}
hda->hda2hdmi_clk = devm_clk_get(dev, "hda2hdmi");
if (IS_ERR(hda->hda2hdmi_clk)) {
dev_err(dev, "failed to get hda2hdmi clock\n");
return PTR_ERR(hda->hda2hdmi_clk);
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
hda->regs = devm_ioremap_resource(dev, res);
if (IS_ERR(hda->regs))
return PTR_ERR(hda->regs);
bus->remap_addr = hda->regs + HDA_BAR0;
bus->addr = res->start + HDA_BAR0;
err = hda_tegra_enable_clocks(hda);
if (err) {
dev_err(dev, "failed to get enable clocks\n");
return err;
}
hda_tegra_init(hda);
return 0;
}
static int hda_tegra_first_init(struct azx *chip, struct platform_device *pdev)
{
struct hdac_bus *bus = azx_bus(chip);
struct snd_card *card = chip->card;
int err;
unsigned short gcap;
int irq_id = platform_get_irq(pdev, 0);
err = hda_tegra_init_chip(chip, pdev);
if (err)
return err;
err = devm_request_irq(chip->card->dev, irq_id, azx_interrupt,
IRQF_SHARED, KBUILD_MODNAME, chip);
if (err) {
dev_err(chip->card->dev,
"unable to request IRQ %d, disabling device\n",
irq_id);
return err;
}
bus->irq = irq_id;
synchronize_irq(bus->irq);
gcap = azx_readw(chip, GCAP);
dev_dbg(card->dev, "chipset global capabilities = 0x%x\n", gcap);
chip->capture_streams = (gcap >> 8) & 0x0f;
chip->playback_streams = (gcap >> 12) & 0x0f;
if (!chip->playback_streams && !chip->capture_streams) {
chip->playback_streams = NUM_PLAYBACK_SD;
chip->capture_streams = NUM_CAPTURE_SD;
}
chip->capture_index_offset = 0;
chip->playback_index_offset = chip->capture_streams;
chip->num_streams = chip->playback_streams + chip->capture_streams;
err = azx_init_streams(chip);
if (err < 0) {
dev_err(card->dev, "failed to initialize streams: %d\n", err);
return err;
}
err = azx_alloc_stream_pages(chip);
if (err < 0) {
dev_err(card->dev, "failed to allocate stream pages: %d\n",
err);
return err;
}
azx_init_chip(chip, 1);
if (!bus->codec_mask) {
dev_err(card->dev, "no codecs found!\n");
return -ENODEV;
}
strcpy(card->driver, "tegra-hda");
strcpy(card->shortname, "tegra-hda");
snprintf(card->longname, sizeof(card->longname),
"%s at 0x%lx irq %i",
card->shortname, bus->addr, bus->irq);
return 0;
}
static int hda_tegra_create(struct snd_card *card,
unsigned int driver_caps,
struct hda_tegra *hda)
{
static struct snd_device_ops ops = {
.dev_disconnect = hda_tegra_dev_disconnect,
.dev_free = hda_tegra_dev_free,
};
struct azx *chip;
int err;
chip = &hda->chip;
mutex_init(&chip->open_mutex);
chip->card = card;
chip->ops = &hda_tegra_ops;
chip->driver_caps = driver_caps;
chip->driver_type = driver_caps & 0xff;
chip->dev_index = 0;
INIT_LIST_HEAD(&chip->pcm_list);
chip->codec_probe_mask = -1;
chip->single_cmd = false;
chip->snoop = true;
err = azx_bus_init(chip, NULL, &hda_tegra_io_ops);
if (err < 0)
return err;
err = snd_device_new(card, SNDRV_DEV_LOWLEVEL, chip, &ops);
if (err < 0) {
dev_err(card->dev, "Error creating device\n");
return err;
}
return 0;
}
static int hda_tegra_probe(struct platform_device *pdev)
{
const unsigned int driver_flags = AZX_DCAPS_RIRB_DELAY |
AZX_DCAPS_CORBRP_SELF_CLEAR;
struct snd_card *card;
struct azx *chip;
struct hda_tegra *hda;
int err;
hda = devm_kzalloc(&pdev->dev, sizeof(*hda), GFP_KERNEL);
if (!hda)
return -ENOMEM;
hda->dev = &pdev->dev;
chip = &hda->chip;
err = snd_card_new(&pdev->dev, SNDRV_DEFAULT_IDX1, SNDRV_DEFAULT_STR1,
THIS_MODULE, 0, &card);
if (err < 0) {
dev_err(&pdev->dev, "Error creating card!\n");
return err;
}
err = hda_tegra_create(card, driver_flags, hda);
if (err < 0)
goto out_free;
card->private_data = chip;
dev_set_drvdata(&pdev->dev, card);
err = hda_tegra_first_init(chip, pdev);
if (err < 0)
goto out_free;
err = azx_probe_codecs(chip, 0);
if (err < 0)
goto out_free;
err = azx_codec_configure(chip);
if (err < 0)
goto out_free;
err = snd_card_register(chip->card);
if (err < 0)
goto out_free;
chip->running = 1;
snd_hda_set_power_save(&chip->bus, power_save * 1000);
return 0;
out_free:
snd_card_free(card);
return err;
}
static int hda_tegra_remove(struct platform_device *pdev)
{
return snd_card_free(dev_get_drvdata(&pdev->dev));
}
static void hda_tegra_shutdown(struct platform_device *pdev)
{
struct snd_card *card = dev_get_drvdata(&pdev->dev);
struct azx *chip;
if (!card)
return;
chip = card->private_data;
if (chip && chip->running)
azx_stop_chip(chip);
}
