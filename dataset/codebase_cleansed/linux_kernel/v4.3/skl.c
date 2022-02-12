static void skl_update_pci_byte(struct pci_dev *pci, unsigned int reg,
unsigned char mask, unsigned char val)
{
unsigned char data;
pci_read_config_byte(pci, reg, &data);
data &= ~mask;
data |= (val & mask);
pci_write_config_byte(pci, reg, data);
}
static void skl_init_pci(struct skl *skl)
{
struct hdac_ext_bus *ebus = &skl->ebus;
dev_dbg(ebus_to_hbus(ebus)->dev, "Clearing TCSEL\n");
skl_update_pci_byte(skl->pci, AZX_PCIREG_TCSEL, 0x07, 0);
}
static void skl_stream_update(struct hdac_bus *bus, struct hdac_stream *hstr)
{
snd_pcm_period_elapsed(hstr->substream);
}
static irqreturn_t skl_interrupt(int irq, void *dev_id)
{
struct hdac_ext_bus *ebus = dev_id;
struct hdac_bus *bus = ebus_to_hbus(ebus);
u32 status;
if (!pm_runtime_active(bus->dev))
return IRQ_NONE;
spin_lock(&bus->reg_lock);
status = snd_hdac_chip_readl(bus, INTSTS);
if (status == 0 || status == 0xffffffff) {
spin_unlock(&bus->reg_lock);
return IRQ_NONE;
}
status = snd_hdac_chip_readb(bus, RIRBSTS);
if (status & RIRB_INT_MASK) {
if (status & RIRB_INT_RESPONSE)
snd_hdac_bus_update_rirb(bus);
snd_hdac_chip_writeb(bus, RIRBSTS, RIRB_INT_MASK);
}
spin_unlock(&bus->reg_lock);
return snd_hdac_chip_readl(bus, INTSTS) ? IRQ_WAKE_THREAD : IRQ_HANDLED;
}
static irqreturn_t skl_threaded_handler(int irq, void *dev_id)
{
struct hdac_ext_bus *ebus = dev_id;
struct hdac_bus *bus = ebus_to_hbus(ebus);
u32 status;
status = snd_hdac_chip_readl(bus, INTSTS);
snd_hdac_bus_handle_stream_irq(bus, status, skl_stream_update);
return IRQ_HANDLED;
}
static int skl_acquire_irq(struct hdac_ext_bus *ebus, int do_disconnect)
{
struct skl *skl = ebus_to_skl(ebus);
struct hdac_bus *bus = ebus_to_hbus(ebus);
int ret;
ret = request_threaded_irq(skl->pci->irq, skl_interrupt,
skl_threaded_handler,
IRQF_SHARED,
KBUILD_MODNAME, ebus);
if (ret) {
dev_err(bus->dev,
"unable to grab IRQ %d, disabling device\n",
skl->pci->irq);
return ret;
}
bus->irq = skl->pci->irq;
pci_intx(skl->pci, 1);
return 0;
}
static int skl_suspend(struct device *dev)
{
struct pci_dev *pci = to_pci_dev(dev);
struct hdac_ext_bus *ebus = pci_get_drvdata(pci);
struct hdac_bus *bus = ebus_to_hbus(ebus);
snd_hdac_bus_stop_chip(bus);
snd_hdac_bus_enter_link_reset(bus);
return 0;
}
static int skl_resume(struct device *dev)
{
struct pci_dev *pci = to_pci_dev(dev);
struct hdac_ext_bus *ebus = pci_get_drvdata(pci);
struct hdac_bus *bus = ebus_to_hbus(ebus);
struct skl *hda = ebus_to_skl(ebus);
skl_init_pci(hda);
snd_hdac_bus_init_chip(bus, 1);
return 0;
}
static int skl_runtime_suspend(struct device *dev)
{
struct pci_dev *pci = to_pci_dev(dev);
struct hdac_ext_bus *ebus = pci_get_drvdata(pci);
struct hdac_bus *bus = ebus_to_hbus(ebus);
dev_dbg(bus->dev, "in %s\n", __func__);
snd_hdac_chip_updatew(bus, WAKEEN, 0, STATESTS_INT_MASK);
snd_hdac_bus_stop_chip(bus);
snd_hdac_bus_enter_link_reset(bus);
return 0;
}
static int skl_runtime_resume(struct device *dev)
{
struct pci_dev *pci = to_pci_dev(dev);
struct hdac_ext_bus *ebus = pci_get_drvdata(pci);
struct hdac_bus *bus = ebus_to_hbus(ebus);
struct skl *hda = ebus_to_skl(ebus);
int status;
dev_dbg(bus->dev, "in %s\n", __func__);
status = snd_hdac_chip_readw(bus, STATESTS);
skl_init_pci(hda);
snd_hdac_bus_init_chip(bus, true);
snd_hdac_chip_updatew(bus, WAKEEN, STATESTS_INT_MASK, 0);
return 0;
}
static int skl_free(struct hdac_ext_bus *ebus)
{
struct skl *skl = ebus_to_skl(ebus);
struct hdac_bus *bus = ebus_to_hbus(ebus);
skl->init_failed = 1;
snd_hdac_ext_stop_streams(ebus);
if (bus->irq >= 0)
free_irq(bus->irq, (void *)bus);
if (bus->remap_addr)
iounmap(bus->remap_addr);
snd_hdac_bus_free_stream_pages(bus);
snd_hdac_stream_free_all(ebus);
snd_hdac_link_free_all(ebus);
pci_release_regions(skl->pci);
pci_disable_device(skl->pci);
snd_hdac_ext_bus_exit(ebus);
return 0;
}
static int skl_dmic_device_register(struct skl *skl)
{
struct hdac_bus *bus = ebus_to_hbus(&skl->ebus);
struct platform_device *pdev;
int ret;
pdev = platform_device_alloc("dmic-codec", -1);
if (!pdev) {
dev_err(bus->dev, "failed to allocate dmic device\n");
return -ENOMEM;
}
ret = platform_device_add(pdev);
if (ret) {
dev_err(bus->dev, "failed to add dmic device: %d\n", ret);
platform_device_put(pdev);
return ret;
}
skl->dmic_dev = pdev;
return 0;
}
static void skl_dmic_device_unregister(struct skl *skl)
{
if (skl->dmic_dev)
platform_device_unregister(skl->dmic_dev);
}
static int probe_codec(struct hdac_ext_bus *ebus, int addr)
{
struct hdac_bus *bus = ebus_to_hbus(ebus);
unsigned int cmd = (addr << 28) | (AC_NODE_ROOT << 20) |
(AC_VERB_PARAMETERS << 8) | AC_PAR_VENDOR_ID;
unsigned int res;
mutex_lock(&bus->cmd_mutex);
snd_hdac_bus_send_cmd(bus, cmd);
snd_hdac_bus_get_response(bus, addr, &res);
mutex_unlock(&bus->cmd_mutex);
if (res == -1)
return -EIO;
dev_dbg(bus->dev, "codec #%d probed OK\n", addr);
return snd_hdac_ext_bus_device_init(ebus, addr);
}
static int skl_codec_create(struct hdac_ext_bus *ebus)
{
struct hdac_bus *bus = ebus_to_hbus(ebus);
int c, max_slots;
max_slots = HDA_MAX_CODECS;
for (c = 0; c < max_slots; c++) {
if ((bus->codec_mask & (1 << c))) {
if (probe_codec(ebus, c) < 0) {
dev_warn(bus->dev,
"Codec #%d probe error; disabling it...\n", c);
bus->codec_mask &= ~(1 << c);
snd_hdac_bus_stop_chip(bus);
snd_hdac_bus_init_chip(bus, true);
}
}
}
return 0;
}
static int skl_create(struct pci_dev *pci,
const struct hdac_io_ops *io_ops,
struct skl **rskl)
{
struct skl *skl;
struct hdac_ext_bus *ebus;
int err;
*rskl = NULL;
err = pci_enable_device(pci);
if (err < 0)
return err;
skl = devm_kzalloc(&pci->dev, sizeof(*skl), GFP_KERNEL);
if (!skl) {
pci_disable_device(pci);
return -ENOMEM;
}
ebus = &skl->ebus;
snd_hdac_ext_bus_init(ebus, &pci->dev, &bus_core_ops, io_ops);
ebus->bus.use_posbuf = 1;
skl->pci = pci;
ebus->bus.bdl_pos_adj = 0;
*rskl = skl;
return 0;
}
static int skl_first_init(struct hdac_ext_bus *ebus)
{
struct skl *skl = ebus_to_skl(ebus);
struct hdac_bus *bus = ebus_to_hbus(ebus);
struct pci_dev *pci = skl->pci;
int err;
unsigned short gcap;
int cp_streams, pb_streams, start_idx;
err = pci_request_regions(pci, "Skylake HD audio");
if (err < 0)
return err;
bus->addr = pci_resource_start(pci, 0);
bus->remap_addr = pci_ioremap_bar(pci, 0);
if (bus->remap_addr == NULL) {
dev_err(bus->dev, "ioremap error\n");
return -ENXIO;
}
snd_hdac_ext_bus_parse_capabilities(ebus);
if (skl_acquire_irq(ebus, 0) < 0)
return -EBUSY;
pci_set_master(pci);
synchronize_irq(bus->irq);
gcap = snd_hdac_chip_readw(bus, GCAP);
dev_dbg(bus->dev, "chipset global capabilities = 0x%x\n", gcap);
if (!dma_set_mask(bus->dev, DMA_BIT_MASK(64))) {
dma_set_coherent_mask(bus->dev, DMA_BIT_MASK(64));
} else {
dma_set_mask(bus->dev, DMA_BIT_MASK(32));
dma_set_coherent_mask(bus->dev, DMA_BIT_MASK(32));
}
cp_streams = (gcap >> 8) & 0x0f;
pb_streams = (gcap >> 12) & 0x0f;
if (!pb_streams && !cp_streams)
return -EIO;
ebus->num_streams = cp_streams + pb_streams;
snd_hdac_ext_stream_init_all
(ebus, 0, cp_streams, SNDRV_PCM_STREAM_CAPTURE);
start_idx = cp_streams;
snd_hdac_ext_stream_init_all
(ebus, start_idx, pb_streams, SNDRV_PCM_STREAM_PLAYBACK);
err = snd_hdac_bus_alloc_stream_pages(bus);
if (err < 0)
return err;
skl_init_pci(skl);
snd_hdac_bus_init_chip(bus, true);
if (!bus->codec_mask) {
dev_err(bus->dev, "no codecs found!\n");
return -ENODEV;
}
return 0;
}
static int skl_probe(struct pci_dev *pci,
const struct pci_device_id *pci_id)
{
struct skl *skl;
struct hdac_ext_bus *ebus = NULL;
struct hdac_bus *bus = NULL;
int err;
err = skl_create(pci, NULL, &skl);
if (err < 0)
return err;
ebus = &skl->ebus;
bus = ebus_to_hbus(ebus);
err = skl_first_init(ebus);
if (err < 0)
goto out_free;
pci_set_drvdata(skl->pci, ebus);
if (ebus->ppcap) {
dev_dbg(bus->dev, "Register dsp\n");
}
if (ebus->mlcap)
snd_hdac_ext_bus_get_ml_capabilities(ebus);
err = skl_dmic_device_register(skl);
if (err < 0)
goto out_free;
err = skl_platform_register(bus->dev);
if (err < 0)
goto out_dmic_free;
err = skl_codec_create(ebus);
if (err < 0)
goto out_unregister;
pm_runtime_set_autosuspend_delay(bus->dev, SKL_SUSPEND_DELAY);
pm_runtime_use_autosuspend(bus->dev);
pm_runtime_put_noidle(bus->dev);
pm_runtime_allow(bus->dev);
return 0;
out_unregister:
skl_platform_unregister(bus->dev);
out_dmic_free:
skl_dmic_device_unregister(skl);
out_free:
skl->init_failed = 1;
skl_free(ebus);
return err;
}
static void skl_remove(struct pci_dev *pci)
{
struct hdac_ext_bus *ebus = pci_get_drvdata(pci);
struct skl *skl = ebus_to_skl(ebus);
if (pci_dev_run_wake(pci))
pm_runtime_get_noresume(&pci->dev);
pci_dev_put(pci);
skl_platform_unregister(&pci->dev);
skl_dmic_device_unregister(skl);
skl_free(ebus);
dev_set_drvdata(&pci->dev, NULL);
}
