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
static void update_pci_dword(struct pci_dev *pci,
unsigned int reg, u32 mask, u32 val)
{
u32 data = 0;
pci_read_config_dword(pci, reg, &data);
data &= ~mask;
data |= (val & mask);
pci_write_config_dword(pci, reg, data);
}
static void skl_enable_miscbdcge(struct device *dev, bool enable)
{
struct pci_dev *pci = to_pci_dev(dev);
u32 val;
val = enable ? AZX_CGCTL_MISCBDCGE_MASK : 0;
update_pci_dword(pci, AZX_PCIREG_CGCTL, AZX_CGCTL_MISCBDCGE_MASK, val);
}
static int skl_init_chip(struct hdac_bus *bus, bool full_reset)
{
int ret;
skl_enable_miscbdcge(bus->dev, false);
ret = snd_hdac_bus_init_chip(bus, full_reset);
skl_enable_miscbdcge(bus->dev, true);
return ret;
}
void skl_update_d0i3c(struct device *dev, bool enable)
{
struct pci_dev *pci = to_pci_dev(dev);
struct hdac_ext_bus *ebus = pci_get_drvdata(pci);
struct hdac_bus *bus = ebus_to_hbus(ebus);
u8 reg;
int timeout = 50;
reg = snd_hdac_chip_readb(bus, VS_D0I3C);
while ((reg & AZX_REG_VS_D0I3C_CIP) && --timeout) {
udelay(10);
reg = snd_hdac_chip_readb(bus, VS_D0I3C);
}
if (!timeout) {
dev_err(bus->dev, "Before D0I3C update: D0I3C CIP timeout\n");
return;
}
if (enable)
reg = reg | AZX_REG_VS_D0I3C_I3;
else
reg = reg & (~AZX_REG_VS_D0I3C_I3);
snd_hdac_chip_writeb(bus, VS_D0I3C, reg);
timeout = 50;
reg = snd_hdac_chip_readb(bus, VS_D0I3C);
while ((reg & AZX_REG_VS_D0I3C_CIP) && --timeout) {
udelay(10);
reg = snd_hdac_chip_readb(bus, VS_D0I3C);
}
if (!timeout) {
dev_err(bus->dev, "After D0I3C update: D0I3C CIP timeout\n");
return;
}
dev_dbg(bus->dev, "D0I3C register = 0x%x\n",
snd_hdac_chip_readb(bus, VS_D0I3C));
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
static int skl_suspend_late(struct device *dev)
{
struct pci_dev *pci = to_pci_dev(dev);
struct hdac_ext_bus *ebus = pci_get_drvdata(pci);
struct skl *skl = ebus_to_skl(ebus);
return skl_suspend_late_dsp(skl);
}
static int _skl_suspend(struct hdac_ext_bus *ebus)
{
struct skl *skl = ebus_to_skl(ebus);
struct hdac_bus *bus = ebus_to_hbus(ebus);
struct pci_dev *pci = to_pci_dev(bus->dev);
int ret;
snd_hdac_ext_bus_link_power_down_all(ebus);
ret = skl_suspend_dsp(skl);
if (ret < 0)
return ret;
snd_hdac_bus_stop_chip(bus);
update_pci_dword(pci, AZX_PCIREG_PGCTL,
AZX_PGCTL_LSRMD_MASK, AZX_PGCTL_LSRMD_MASK);
skl_enable_miscbdcge(bus->dev, false);
snd_hdac_bus_enter_link_reset(bus);
skl_enable_miscbdcge(bus->dev, true);
skl_cleanup_resources(skl);
return 0;
}
static int _skl_resume(struct hdac_ext_bus *ebus)
{
struct skl *skl = ebus_to_skl(ebus);
struct hdac_bus *bus = ebus_to_hbus(ebus);
skl_init_pci(skl);
skl_init_chip(bus, true);
return skl_resume_dsp(skl);
}
static int skl_suspend(struct device *dev)
{
struct pci_dev *pci = to_pci_dev(dev);
struct hdac_ext_bus *ebus = pci_get_drvdata(pci);
struct skl *skl = ebus_to_skl(ebus);
struct hdac_bus *bus = ebus_to_hbus(ebus);
int ret = 0;
if (skl->supend_active) {
snd_hdac_ext_bus_link_power_down_all(ebus);
if (ebus->cmd_dma_state)
snd_hdac_bus_stop_cmd_io(&ebus->bus);
enable_irq_wake(bus->irq);
pci_save_state(pci);
} else {
ret = _skl_suspend(ebus);
if (ret < 0)
return ret;
skl->skl_sst->fw_loaded = false;
}
if (IS_ENABLED(CONFIG_SND_SOC_HDAC_HDMI)) {
ret = snd_hdac_display_power(bus, false);
if (ret < 0)
dev_err(bus->dev,
"Cannot turn OFF display power on i915\n");
}
return ret;
}
static int skl_resume(struct device *dev)
{
struct pci_dev *pci = to_pci_dev(dev);
struct hdac_ext_bus *ebus = pci_get_drvdata(pci);
struct skl *skl = ebus_to_skl(ebus);
struct hdac_bus *bus = ebus_to_hbus(ebus);
struct hdac_ext_link *hlink = NULL;
int ret;
if (IS_ENABLED(CONFIG_SND_SOC_HDAC_HDMI)) {
ret = snd_hdac_display_power(bus, true);
if (ret < 0) {
dev_err(bus->dev,
"Cannot turn on display power on i915\n");
return ret;
}
}
if (skl->supend_active) {
pci_restore_state(pci);
snd_hdac_ext_bus_link_power_up_all(ebus);
disable_irq_wake(bus->irq);
list_for_each_entry(hlink, &ebus->hlink_list, list) {
if (hlink->ref_count)
snd_hdac_ext_bus_link_power_up(hlink);
}
if (ebus->cmd_dma_state)
snd_hdac_bus_init_cmd_io(&ebus->bus);
} else {
ret = _skl_resume(ebus);
list_for_each_entry(hlink, &ebus->hlink_list, list) {
if (!hlink->ref_count)
snd_hdac_ext_bus_link_power_down(hlink);
}
if (!ebus->cmd_dma_state)
snd_hdac_bus_stop_cmd_io(&ebus->bus);
}
return ret;
}
static int skl_runtime_suspend(struct device *dev)
{
struct pci_dev *pci = to_pci_dev(dev);
struct hdac_ext_bus *ebus = pci_get_drvdata(pci);
struct hdac_bus *bus = ebus_to_hbus(ebus);
dev_dbg(bus->dev, "in %s\n", __func__);
return _skl_suspend(ebus);
}
static int skl_runtime_resume(struct device *dev)
{
struct pci_dev *pci = to_pci_dev(dev);
struct hdac_ext_bus *ebus = pci_get_drvdata(pci);
struct hdac_bus *bus = ebus_to_hbus(ebus);
dev_dbg(bus->dev, "in %s\n", __func__);
return _skl_resume(ebus);
}
static int skl_free(struct hdac_ext_bus *ebus)
{
struct skl *skl = ebus_to_skl(ebus);
struct hdac_bus *bus = ebus_to_hbus(ebus);
skl->init_failed = 1;
snd_hdac_ext_stop_streams(ebus);
if (bus->irq >= 0)
free_irq(bus->irq, (void *)bus);
snd_hdac_bus_free_stream_pages(bus);
snd_hdac_stream_free_all(ebus);
snd_hdac_link_free_all(ebus);
if (bus->remap_addr)
iounmap(bus->remap_addr);
pci_release_regions(skl->pci);
pci_disable_device(skl->pci);
snd_hdac_ext_bus_exit(ebus);
if (IS_ENABLED(CONFIG_SND_SOC_HDAC_HDMI))
snd_hdac_i915_exit(&ebus->bus);
return 0;
}
static int skl_machine_device_register(struct skl *skl, void *driver_data)
{
struct hdac_bus *bus = ebus_to_hbus(&skl->ebus);
struct platform_device *pdev;
struct sst_acpi_mach *mach = driver_data;
int ret;
mach = sst_acpi_find_machine(mach);
if (mach == NULL) {
dev_err(bus->dev, "No matching machine driver found\n");
return -ENODEV;
}
skl->fw_name = mach->fw_filename;
pdev = platform_device_alloc(mach->drv_name, -1);
if (pdev == NULL) {
dev_err(bus->dev, "platform device alloc failed\n");
return -EIO;
}
ret = platform_device_add(pdev);
if (ret) {
dev_err(bus->dev, "failed to add machine device\n");
platform_device_put(pdev);
return -EIO;
}
if (mach->pdata)
dev_set_drvdata(&pdev->dev, mach->pdata);
skl->i2s_dev = pdev;
return 0;
}
static void skl_machine_device_unregister(struct skl *skl)
{
if (skl->i2s_dev)
platform_device_unregister(skl->i2s_dev);
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
skl_init_chip(bus, true);
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
static int skl_i915_init(struct hdac_bus *bus)
{
int err;
err = snd_hdac_i915_init(bus);
if (err < 0)
return err;
err = snd_hdac_display_power(bus, true);
if (err < 0) {
dev_err(bus->dev, "Cannot turn on display power on i915\n");
return err;
}
return err;
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
snd_hdac_bus_parse_capabilities(bus);
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
if (IS_ENABLED(CONFIG_SND_SOC_HDAC_HDMI)) {
err = skl_i915_init(bus);
if (err < 0)
return err;
}
skl_init_chip(bus, true);
if (!bus->codec_mask) {
dev_info(bus->dev, "no hda codecs found!\n");
}
return 0;
}
static int skl_probe(struct pci_dev *pci,
const struct pci_device_id *pci_id)
{
struct skl *skl;
struct hdac_ext_bus *ebus = NULL;
struct hdac_bus *bus = NULL;
struct hdac_ext_link *hlink = NULL;
int err;
err = skl_create(pci, NULL, &skl);
if (err < 0)
return err;
ebus = &skl->ebus;
bus = ebus_to_hbus(ebus);
err = skl_first_init(ebus);
if (err < 0)
goto out_free;
skl->pci_id = pci->device;
device_disable_async_suspend(bus->dev);
skl->nhlt = skl_nhlt_init(bus->dev);
if (skl->nhlt == NULL) {
err = -ENODEV;
goto out_display_power_off;
}
err = skl_nhlt_create_sysfs(skl);
if (err < 0)
goto out_nhlt_free;
skl_nhlt_update_topology_bin(skl);
pci_set_drvdata(skl->pci, ebus);
skl_dmic_data.dmic_num = skl_get_dmic_geo(skl);
if (bus->ppcap) {
err = skl_machine_device_register(skl,
(void *)pci_id->driver_data);
if (err < 0)
goto out_nhlt_free;
err = skl_init_dsp(skl);
if (err < 0) {
dev_dbg(bus->dev, "error failed to register dsp\n");
goto out_mach_free;
}
skl->skl_sst->enable_miscbdcge = skl_enable_miscbdcge;
}
if (bus->mlcap)
snd_hdac_ext_bus_get_ml_capabilities(ebus);
err = skl_dmic_device_register(skl);
if (err < 0)
goto out_dsp_free;
err = skl_platform_register(bus->dev);
if (err < 0)
goto out_dmic_free;
err = skl_codec_create(ebus);
if (err < 0)
goto out_unregister;
if (IS_ENABLED(CONFIG_SND_SOC_HDAC_HDMI)) {
err = snd_hdac_display_power(bus, false);
if (err < 0) {
dev_err(bus->dev, "Cannot turn off display power on i915\n");
return err;
}
}
list_for_each_entry(hlink, &ebus->hlink_list, list)
snd_hdac_ext_bus_link_put(ebus, hlink);
pm_runtime_put_noidle(bus->dev);
pm_runtime_allow(bus->dev);
return 0;
out_unregister:
skl_platform_unregister(bus->dev);
out_dmic_free:
skl_dmic_device_unregister(skl);
out_dsp_free:
skl_free_dsp(skl);
out_mach_free:
skl_machine_device_unregister(skl);
out_nhlt_free:
skl_nhlt_free(skl->nhlt);
out_display_power_off:
if (IS_ENABLED(CONFIG_SND_SOC_HDAC_HDMI))
snd_hdac_display_power(bus, false);
out_free:
skl->init_failed = 1;
skl_free(ebus);
return err;
}
static void skl_shutdown(struct pci_dev *pci)
{
struct hdac_ext_bus *ebus = pci_get_drvdata(pci);
struct hdac_bus *bus = ebus_to_hbus(ebus);
struct hdac_stream *s;
struct hdac_ext_stream *stream;
struct skl *skl;
if (ebus == NULL)
return;
skl = ebus_to_skl(ebus);
if (skl->init_failed)
return;
snd_hdac_ext_stop_streams(ebus);
list_for_each_entry(s, &bus->stream_list, list) {
stream = stream_to_hdac_ext_stream(s);
snd_hdac_ext_stream_decouple(ebus, stream, false);
}
snd_hdac_bus_stop_chip(bus);
}
static void skl_remove(struct pci_dev *pci)
{
struct hdac_ext_bus *ebus = pci_get_drvdata(pci);
struct skl *skl = ebus_to_skl(ebus);
release_firmware(skl->tplg);
pm_runtime_get_noresume(&pci->dev);
snd_hdac_ext_bus_device_remove(ebus);
skl_platform_unregister(&pci->dev);
skl_free_dsp(skl);
skl_machine_device_unregister(skl);
skl_dmic_device_unregister(skl);
skl_nhlt_remove_sysfs(skl);
skl_nhlt_free(skl->nhlt);
skl_free(ebus);
dev_set_drvdata(&pci->dev, NULL);
}
