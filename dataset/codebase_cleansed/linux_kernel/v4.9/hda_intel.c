static void __mark_pages_wc(struct azx *chip, struct snd_dma_buffer *dmab, bool on)
{
int pages;
if (azx_snoop(chip))
return;
if (!dmab || !dmab->area || !dmab->bytes)
return;
#ifdef CONFIG_SND_DMA_SGBUF
if (dmab->dev.type == SNDRV_DMA_TYPE_DEV_SG) {
struct snd_sg_buf *sgbuf = dmab->private_data;
if (chip->driver_type == AZX_DRIVER_CMEDIA)
return;
if (on)
set_pages_array_wc(sgbuf->page_table, sgbuf->pages);
else
set_pages_array_wb(sgbuf->page_table, sgbuf->pages);
return;
}
#endif
pages = (dmab->bytes + PAGE_SIZE - 1) >> PAGE_SHIFT;
if (on)
set_memory_wc((unsigned long)dmab->area, pages);
else
set_memory_wb((unsigned long)dmab->area, pages);
}
static inline void mark_pages_wc(struct azx *chip, struct snd_dma_buffer *buf,
bool on)
{
__mark_pages_wc(chip, buf, on);
}
static inline void mark_runtime_wc(struct azx *chip, struct azx_dev *azx_dev,
struct snd_pcm_substream *substream, bool on)
{
if (azx_dev->wc_marked != on) {
__mark_pages_wc(chip, snd_pcm_get_dma_buf(substream), on);
azx_dev->wc_marked = on;
}
}
static inline void mark_pages_wc(struct azx *chip, struct snd_dma_buffer *buf,
bool on)
{
}
static inline void mark_runtime_wc(struct azx *chip, struct azx_dev *azx_dev,
struct snd_pcm_substream *substream, bool on)
{
}
static void update_pci_byte(struct pci_dev *pci, unsigned int reg,
unsigned char mask, unsigned char val)
{
unsigned char data;
pci_read_config_byte(pci, reg, &data);
data &= ~mask;
data |= (val & mask);
pci_write_config_byte(pci, reg, data);
}
static void azx_init_pci(struct azx *chip)
{
int snoop_type = azx_get_snoop_type(chip);
if (!(chip->driver_caps & AZX_DCAPS_NO_TCSEL)) {
dev_dbg(chip->card->dev, "Clearing TCSEL\n");
update_pci_byte(chip->pci, AZX_PCIREG_TCSEL, 0x07, 0);
}
if (snoop_type == AZX_SNOOP_TYPE_ATI) {
dev_dbg(chip->card->dev, "Setting ATI snoop: %d\n",
azx_snoop(chip));
update_pci_byte(chip->pci,
ATI_SB450_HDAUDIO_MISC_CNTR2_ADDR, 0x07,
azx_snoop(chip) ? ATI_SB450_HDAUDIO_ENABLE_SNOOP : 0);
}
if (snoop_type == AZX_SNOOP_TYPE_NVIDIA) {
dev_dbg(chip->card->dev, "Setting Nvidia snoop: %d\n",
azx_snoop(chip));
update_pci_byte(chip->pci,
NVIDIA_HDA_TRANSREG_ADDR,
0x0f, NVIDIA_HDA_ENABLE_COHBITS);
update_pci_byte(chip->pci,
NVIDIA_HDA_ISTRM_COH,
0x01, NVIDIA_HDA_ENABLE_COHBIT);
update_pci_byte(chip->pci,
NVIDIA_HDA_OSTRM_COH,
0x01, NVIDIA_HDA_ENABLE_COHBIT);
}
if (snoop_type == AZX_SNOOP_TYPE_SCH) {
unsigned short snoop;
pci_read_config_word(chip->pci, INTEL_SCH_HDA_DEVC, &snoop);
if ((!azx_snoop(chip) && !(snoop & INTEL_SCH_HDA_DEVC_NOSNOOP)) ||
(azx_snoop(chip) && (snoop & INTEL_SCH_HDA_DEVC_NOSNOOP))) {
snoop &= ~INTEL_SCH_HDA_DEVC_NOSNOOP;
if (!azx_snoop(chip))
snoop |= INTEL_SCH_HDA_DEVC_NOSNOOP;
pci_write_config_word(chip->pci, INTEL_SCH_HDA_DEVC, snoop);
pci_read_config_word(chip->pci,
INTEL_SCH_HDA_DEVC, &snoop);
}
dev_dbg(chip->card->dev, "SCH snoop: %s\n",
(snoop & INTEL_SCH_HDA_DEVC_NOSNOOP) ?
"Disabled" : "Enabled");
}
}
static void bxt_reduce_dma_latency(struct azx *chip)
{
u32 val;
val = azx_readl(chip, SKL_EM4L);
val &= (0x3 << 20);
azx_writel(chip, SKL_EM4L, val);
}
static void hda_intel_init_chip(struct azx *chip, bool full_reset)
{
struct hdac_bus *bus = azx_bus(chip);
struct pci_dev *pci = chip->pci;
u32 val;
if (chip->driver_caps & AZX_DCAPS_I915_POWERWELL)
snd_hdac_set_codec_wakeup(bus, true);
if (IS_SKL_PLUS(pci)) {
pci_read_config_dword(pci, INTEL_HDA_CGCTL, &val);
val = val & ~INTEL_HDA_CGCTL_MISCBDCGE;
pci_write_config_dword(pci, INTEL_HDA_CGCTL, val);
}
azx_init_chip(chip, full_reset);
if (IS_SKL_PLUS(pci)) {
pci_read_config_dword(pci, INTEL_HDA_CGCTL, &val);
val = val | INTEL_HDA_CGCTL_MISCBDCGE;
pci_write_config_dword(pci, INTEL_HDA_CGCTL, val);
}
if (chip->driver_caps & AZX_DCAPS_I915_POWERWELL)
snd_hdac_set_codec_wakeup(bus, false);
if (IS_BXT(pci))
bxt_reduce_dma_latency(chip);
}
static int azx_get_delay_from_lpib(struct azx *chip, struct azx_dev *azx_dev,
unsigned int pos)
{
struct snd_pcm_substream *substream = azx_dev->core.substream;
int stream = substream->stream;
unsigned int lpib_pos = azx_get_pos_lpib(chip, azx_dev);
int delay;
if (stream == SNDRV_PCM_STREAM_PLAYBACK)
delay = pos - lpib_pos;
else
delay = lpib_pos - pos;
if (delay < 0) {
if (delay >= azx_dev->core.delay_negative_threshold)
delay = 0;
else
delay += azx_dev->core.bufsize;
}
if (delay >= azx_dev->core.period_bytes) {
dev_info(chip->card->dev,
"Unstable LPIB (%d >= %d); disabling LPIB delay counting\n",
delay, azx_dev->core.period_bytes);
delay = 0;
chip->driver_caps &= ~AZX_DCAPS_COUNT_LPIB_DELAY;
chip->get_delay[stream] = NULL;
}
return bytes_to_frames(substream->runtime, delay);
}
static int azx_position_check(struct azx *chip, struct azx_dev *azx_dev)
{
struct hda_intel *hda = container_of(chip, struct hda_intel, chip);
int ok;
ok = azx_position_ok(chip, azx_dev);
if (ok == 1) {
azx_dev->irq_pending = 0;
return ok;
} else if (ok == 0) {
azx_dev->irq_pending = 1;
schedule_work(&hda->irq_pending_work);
}
return 0;
}
static int azx_intel_link_power(struct azx *chip, bool enable)
{
struct hdac_bus *bus = azx_bus(chip);
return snd_hdac_display_power(bus, enable);
}
static int azx_position_ok(struct azx *chip, struct azx_dev *azx_dev)
{
struct snd_pcm_substream *substream = azx_dev->core.substream;
int stream = substream->stream;
u32 wallclk;
unsigned int pos;
wallclk = azx_readl(chip, WALLCLK) - azx_dev->core.start_wallclk;
if (wallclk < (azx_dev->core.period_wallclk * 2) / 3)
return -1;
if (chip->get_position[stream])
pos = chip->get_position[stream](chip, azx_dev);
else {
pos = azx_get_pos_posbuf(chip, azx_dev);
if (!pos || pos == (u32)-1) {
dev_info(chip->card->dev,
"Invalid position buffer, using LPIB read method instead.\n");
chip->get_position[stream] = azx_get_pos_lpib;
if (chip->get_position[0] == azx_get_pos_lpib &&
chip->get_position[1] == azx_get_pos_lpib)
azx_bus(chip)->use_posbuf = false;
pos = azx_get_pos_lpib(chip, azx_dev);
chip->get_delay[stream] = NULL;
} else {
chip->get_position[stream] = azx_get_pos_posbuf;
if (chip->driver_caps & AZX_DCAPS_COUNT_LPIB_DELAY)
chip->get_delay[stream] = azx_get_delay_from_lpib;
}
}
if (pos >= azx_dev->core.bufsize)
pos = 0;
if (WARN_ONCE(!azx_dev->core.period_bytes,
"hda-intel: zero azx_dev->period_bytes"))
return -1;
if (wallclk < (azx_dev->core.period_wallclk * 5) / 4 &&
pos % azx_dev->core.period_bytes > azx_dev->core.period_bytes / 2)
return chip->bdl_pos_adj ? 0 : -1;
azx_dev->core.start_wallclk += wallclk;
return 1;
}
static void azx_irq_pending_work(struct work_struct *work)
{
struct hda_intel *hda = container_of(work, struct hda_intel, irq_pending_work);
struct azx *chip = &hda->chip;
struct hdac_bus *bus = azx_bus(chip);
struct hdac_stream *s;
int pending, ok;
if (!hda->irq_pending_warned) {
dev_info(chip->card->dev,
"IRQ timing workaround is activated for card #%d. Suggest a bigger bdl_pos_adj.\n",
chip->card->number);
hda->irq_pending_warned = 1;
}
for (;;) {
pending = 0;
spin_lock_irq(&bus->reg_lock);
list_for_each_entry(s, &bus->stream_list, list) {
struct azx_dev *azx_dev = stream_to_azx_dev(s);
if (!azx_dev->irq_pending ||
!s->substream ||
!s->running)
continue;
ok = azx_position_ok(chip, azx_dev);
if (ok > 0) {
azx_dev->irq_pending = 0;
spin_unlock(&bus->reg_lock);
snd_pcm_period_elapsed(s->substream);
spin_lock(&bus->reg_lock);
} else if (ok < 0) {
pending = 0;
} else
pending++;
}
spin_unlock_irq(&bus->reg_lock);
if (!pending)
return;
msleep(1);
}
}
static void azx_clear_irq_pending(struct azx *chip)
{
struct hdac_bus *bus = azx_bus(chip);
struct hdac_stream *s;
spin_lock_irq(&bus->reg_lock);
list_for_each_entry(s, &bus->stream_list, list) {
struct azx_dev *azx_dev = stream_to_azx_dev(s);
azx_dev->irq_pending = 0;
}
spin_unlock_irq(&bus->reg_lock);
}
static int azx_acquire_irq(struct azx *chip, int do_disconnect)
{
struct hdac_bus *bus = azx_bus(chip);
if (request_irq(chip->pci->irq, azx_interrupt,
chip->msi ? 0 : IRQF_SHARED,
chip->card->irq_descr, chip)) {
dev_err(chip->card->dev,
"unable to grab IRQ %d, disabling device\n",
chip->pci->irq);
if (do_disconnect)
snd_card_disconnect(chip->card);
return -1;
}
bus->irq = chip->pci->irq;
pci_intx(chip->pci, !chip->msi);
return 0;
}
static unsigned int azx_via_get_position(struct azx *chip,
struct azx_dev *azx_dev)
{
unsigned int link_pos, mini_pos, bound_pos;
unsigned int mod_link_pos, mod_dma_pos, mod_mini_pos;
unsigned int fifo_size;
link_pos = snd_hdac_stream_get_pos_lpib(azx_stream(azx_dev));
if (azx_dev->core.substream->stream == SNDRV_PCM_STREAM_PLAYBACK) {
return link_pos;
}
mod_dma_pos = le32_to_cpu(*azx_dev->core.posbuf);
mod_dma_pos %= azx_dev->core.period_bytes;
fifo_size = readw(azx_bus(chip)->remap_addr +
VIA_IN_STREAM0_FIFO_SIZE_OFFSET);
if (azx_dev->insufficient) {
if (link_pos <= fifo_size)
return 0;
azx_dev->insufficient = 0;
}
if (link_pos <= fifo_size)
mini_pos = azx_dev->core.bufsize + link_pos - fifo_size;
else
mini_pos = link_pos - fifo_size;
mod_mini_pos = mini_pos % azx_dev->core.period_bytes;
mod_link_pos = link_pos % azx_dev->core.period_bytes;
if (mod_link_pos >= fifo_size)
bound_pos = link_pos - mod_link_pos;
else if (mod_dma_pos >= mod_mini_pos)
bound_pos = mini_pos - mod_mini_pos;
else {
bound_pos = mini_pos - mod_mini_pos + azx_dev->core.period_bytes;
if (bound_pos >= azx_dev->core.bufsize)
bound_pos = 0;
}
return bound_pos + mod_dma_pos;
}
static void azx_add_card_list(struct azx *chip)
{
struct hda_intel *hda = container_of(chip, struct hda_intel, chip);
mutex_lock(&card_list_lock);
list_add(&hda->list, &card_list);
mutex_unlock(&card_list_lock);
}
static void azx_del_card_list(struct azx *chip)
{
struct hda_intel *hda = container_of(chip, struct hda_intel, chip);
mutex_lock(&card_list_lock);
list_del_init(&hda->list);
mutex_unlock(&card_list_lock);
}
static int param_set_xint(const char *val, const struct kernel_param *kp)
{
struct hda_intel *hda;
struct azx *chip;
int prev = power_save;
int ret = param_set_int(val, kp);
if (ret || prev == power_save)
return ret;
mutex_lock(&card_list_lock);
list_for_each_entry(hda, &card_list, list) {
chip = &hda->chip;
if (!hda->probe_continued || chip->disabled)
continue;
snd_hda_set_power_save(&chip->bus, power_save * 1000);
}
mutex_unlock(&card_list_lock);
return 0;
}
static int azx_suspend(struct device *dev)
{
struct snd_card *card = dev_get_drvdata(dev);
struct azx *chip;
struct hda_intel *hda;
struct hdac_bus *bus;
if (!card)
return 0;
chip = card->private_data;
hda = container_of(chip, struct hda_intel, chip);
if (chip->disabled || hda->init_failed || !chip->running)
return 0;
bus = azx_bus(chip);
snd_power_change_state(card, SNDRV_CTL_POWER_D3hot);
azx_clear_irq_pending(chip);
azx_stop_chip(chip);
azx_enter_link_reset(chip);
if (bus->irq >= 0) {
free_irq(bus->irq, chip);
bus->irq = -1;
}
if (chip->msi)
pci_disable_msi(chip->pci);
if (chip->driver_caps & AZX_DCAPS_I915_POWERWELL
&& hda->need_i915_power)
snd_hdac_display_power(bus, false);
trace_azx_suspend(chip);
return 0;
}
static int azx_resume(struct device *dev)
{
struct pci_dev *pci = to_pci_dev(dev);
struct snd_card *card = dev_get_drvdata(dev);
struct azx *chip;
struct hda_intel *hda;
struct hdac_bus *bus;
if (!card)
return 0;
chip = card->private_data;
hda = container_of(chip, struct hda_intel, chip);
bus = azx_bus(chip);
if (chip->disabled || hda->init_failed || !chip->running)
return 0;
if (chip->driver_caps & AZX_DCAPS_I915_POWERWELL) {
snd_hdac_display_power(bus, true);
if (hda->need_i915_power)
snd_hdac_i915_set_bclk(bus);
}
if (chip->msi)
if (pci_enable_msi(pci) < 0)
chip->msi = 0;
if (azx_acquire_irq(chip, 1) < 0)
return -EIO;
azx_init_pci(chip);
hda_intel_init_chip(chip, true);
if ((chip->driver_caps & AZX_DCAPS_I915_POWERWELL) &&
!hda->need_i915_power)
snd_hdac_display_power(bus, false);
snd_power_change_state(card, SNDRV_CTL_POWER_D0);
trace_azx_resume(chip);
return 0;
}
static int azx_freeze_noirq(struct device *dev)
{
struct pci_dev *pci = to_pci_dev(dev);
if (IS_SKL_PLUS(pci))
pci_set_power_state(pci, PCI_D3hot);
return 0;
}
static int azx_thaw_noirq(struct device *dev)
{
struct pci_dev *pci = to_pci_dev(dev);
if (IS_SKL_PLUS(pci))
pci_set_power_state(pci, PCI_D0);
return 0;
}
static int azx_runtime_suspend(struct device *dev)
{
struct snd_card *card = dev_get_drvdata(dev);
struct azx *chip;
struct hda_intel *hda;
if (!card)
return 0;
chip = card->private_data;
hda = container_of(chip, struct hda_intel, chip);
if (chip->disabled || hda->init_failed)
return 0;
if (!azx_has_pm_runtime(chip))
return 0;
azx_writew(chip, WAKEEN, azx_readw(chip, WAKEEN) |
STATESTS_INT_MASK);
azx_stop_chip(chip);
azx_enter_link_reset(chip);
azx_clear_irq_pending(chip);
if (chip->driver_caps & AZX_DCAPS_I915_POWERWELL
&& hda->need_i915_power)
snd_hdac_display_power(azx_bus(chip), false);
trace_azx_runtime_suspend(chip);
return 0;
}
static int azx_runtime_resume(struct device *dev)
{
struct snd_card *card = dev_get_drvdata(dev);
struct azx *chip;
struct hda_intel *hda;
struct hdac_bus *bus;
struct hda_codec *codec;
int status;
if (!card)
return 0;
chip = card->private_data;
hda = container_of(chip, struct hda_intel, chip);
bus = azx_bus(chip);
if (chip->disabled || hda->init_failed)
return 0;
if (!azx_has_pm_runtime(chip))
return 0;
if (chip->driver_caps & AZX_DCAPS_I915_POWERWELL) {
snd_hdac_display_power(bus, true);
if (hda->need_i915_power)
snd_hdac_i915_set_bclk(bus);
}
status = azx_readw(chip, STATESTS);
azx_init_pci(chip);
hda_intel_init_chip(chip, true);
if (status) {
list_for_each_codec(codec, &chip->bus)
if (status & (1 << codec->addr))
schedule_delayed_work(&codec->jackpoll_work,
codec->jackpoll_interval);
}
azx_writew(chip, WAKEEN, azx_readw(chip, WAKEEN) &
~STATESTS_INT_MASK);
if ((chip->driver_caps & AZX_DCAPS_I915_POWERWELL) &&
!hda->need_i915_power)
snd_hdac_display_power(bus, false);
trace_azx_runtime_resume(chip);
return 0;
}
static int azx_runtime_idle(struct device *dev)
{
struct snd_card *card = dev_get_drvdata(dev);
struct azx *chip;
struct hda_intel *hda;
if (!card)
return 0;
chip = card->private_data;
hda = container_of(chip, struct hda_intel, chip);
if (chip->disabled || hda->init_failed)
return 0;
if (!power_save_controller || !azx_has_pm_runtime(chip) ||
azx_bus(chip)->codec_powered || !chip->running)
return -EBUSY;
return 0;
}
static void azx_vs_set_state(struct pci_dev *pci,
enum vga_switcheroo_state state)
{
struct snd_card *card = pci_get_drvdata(pci);
struct azx *chip = card->private_data;
struct hda_intel *hda = container_of(chip, struct hda_intel, chip);
bool disabled;
wait_for_completion(&hda->probe_wait);
if (hda->init_failed)
return;
disabled = (state == VGA_SWITCHEROO_OFF);
if (chip->disabled == disabled)
return;
if (!hda->probe_continued) {
chip->disabled = disabled;
if (!disabled) {
dev_info(chip->card->dev,
"Start delayed initialization\n");
if (azx_probe_continue(chip) < 0) {
dev_err(chip->card->dev, "initialization error\n");
hda->init_failed = true;
}
}
} else {
dev_info(chip->card->dev, "%s via vga_switcheroo\n",
disabled ? "Disabling" : "Enabling");
if (disabled) {
pm_runtime_put_sync_suspend(card->dev);
azx_suspend(card->dev);
pci->current_state = PCI_D3cold;
chip->disabled = true;
if (snd_hda_lock_devices(&chip->bus))
dev_warn(chip->card->dev,
"Cannot lock devices!\n");
} else {
snd_hda_unlock_devices(&chip->bus);
pm_runtime_get_noresume(card->dev);
chip->disabled = false;
azx_resume(card->dev);
}
}
}
static bool azx_vs_can_switch(struct pci_dev *pci)
{
struct snd_card *card = pci_get_drvdata(pci);
struct azx *chip = card->private_data;
struct hda_intel *hda = container_of(chip, struct hda_intel, chip);
wait_for_completion(&hda->probe_wait);
if (hda->init_failed)
return false;
if (chip->disabled || !hda->probe_continued)
return true;
if (snd_hda_lock_devices(&chip->bus))
return false;
snd_hda_unlock_devices(&chip->bus);
return true;
}
static void init_vga_switcheroo(struct azx *chip)
{
struct hda_intel *hda = container_of(chip, struct hda_intel, chip);
struct pci_dev *p = get_bound_vga(chip->pci);
if (p) {
dev_info(chip->card->dev,
"Handle vga_switcheroo audio client\n");
hda->use_vga_switcheroo = 1;
pci_dev_put(p);
}
}
static int register_vga_switcheroo(struct azx *chip)
{
struct hda_intel *hda = container_of(chip, struct hda_intel, chip);
int err;
if (!hda->use_vga_switcheroo)
return 0;
err = vga_switcheroo_register_audio_client(chip->pci, &azx_vs_ops,
VGA_SWITCHEROO_DIS);
if (err < 0)
return err;
hda->vga_switcheroo_registered = 1;
vga_switcheroo_init_domain_pm_optimus_hdmi_audio(chip->card->dev,
&hda->hdmi_pm_domain);
return 0;
}
static int azx_free(struct azx *chip)
{
struct pci_dev *pci = chip->pci;
struct hda_intel *hda = container_of(chip, struct hda_intel, chip);
struct hdac_bus *bus = azx_bus(chip);
if (azx_has_pm_runtime(chip) && chip->running)
pm_runtime_get_noresume(&pci->dev);
azx_del_card_list(chip);
hda->init_failed = 1;
complete_all(&hda->probe_wait);
if (use_vga_switcheroo(hda)) {
if (chip->disabled && hda->probe_continued)
snd_hda_unlock_devices(&chip->bus);
if (hda->vga_switcheroo_registered) {
vga_switcheroo_unregister_client(chip->pci);
vga_switcheroo_fini_domain_pm_ops(chip->card->dev);
}
}
if (bus->chip_init) {
azx_clear_irq_pending(chip);
azx_stop_all_streams(chip);
azx_stop_chip(chip);
}
if (bus->irq >= 0)
free_irq(bus->irq, (void*)chip);
if (chip->msi)
pci_disable_msi(chip->pci);
iounmap(bus->remap_addr);
azx_free_stream_pages(chip);
azx_free_streams(chip);
snd_hdac_bus_exit(bus);
if (chip->region_requested)
pci_release_regions(chip->pci);
pci_disable_device(chip->pci);
#ifdef CONFIG_SND_HDA_PATCH_LOADER
release_firmware(chip->fw);
#endif
if (chip->driver_caps & AZX_DCAPS_I915_POWERWELL) {
if (hda->need_i915_power)
snd_hdac_display_power(bus, false);
snd_hdac_i915_exit(bus);
}
kfree(hda);
return 0;
}
static int azx_dev_disconnect(struct snd_device *device)
{
struct azx *chip = device->device_data;
chip->bus.shutdown = 1;
return 0;
}
static int azx_dev_free(struct snd_device *device)
{
return azx_free(device->device_data);
}
static struct pci_dev *get_bound_vga(struct pci_dev *pci)
{
struct pci_dev *p;
switch (pci->vendor) {
case PCI_VENDOR_ID_ATI:
case PCI_VENDOR_ID_AMD:
case PCI_VENDOR_ID_NVIDIA:
if (pci->devfn == 1) {
p = pci_get_domain_bus_and_slot(pci_domain_nr(pci->bus),
pci->bus->number, 0);
if (p) {
if ((p->class >> 8) == PCI_CLASS_DISPLAY_VGA)
return p;
pci_dev_put(p);
}
}
break;
}
return NULL;
}
static bool check_hdmi_disabled(struct pci_dev *pci)
{
bool vga_inactive = false;
struct pci_dev *p = get_bound_vga(pci);
if (p) {
if (vga_switcheroo_get_client_state(p) == VGA_SWITCHEROO_OFF)
vga_inactive = true;
pci_dev_put(p);
}
return vga_inactive;
}
static int check_position_fix(struct azx *chip, int fix)
{
const struct snd_pci_quirk *q;
switch (fix) {
case POS_FIX_AUTO:
case POS_FIX_LPIB:
case POS_FIX_POSBUF:
case POS_FIX_VIACOMBO:
case POS_FIX_COMBO:
return fix;
}
q = snd_pci_quirk_lookup(chip->pci, position_fix_list);
if (q) {
dev_info(chip->card->dev,
"position_fix set to %d for device %04x:%04x\n",
q->value, q->subvendor, q->subdevice);
return q->value;
}
if (chip->driver_type == AZX_DRIVER_VIA) {
dev_dbg(chip->card->dev, "Using VIACOMBO position fix\n");
return POS_FIX_VIACOMBO;
}
if (chip->driver_caps & AZX_DCAPS_POSFIX_LPIB) {
dev_dbg(chip->card->dev, "Using LPIB position fix\n");
return POS_FIX_LPIB;
}
return POS_FIX_AUTO;
}
static void assign_position_fix(struct azx *chip, int fix)
{
static azx_get_pos_callback_t callbacks[] = {
[POS_FIX_AUTO] = NULL,
[POS_FIX_LPIB] = azx_get_pos_lpib,
[POS_FIX_POSBUF] = azx_get_pos_posbuf,
[POS_FIX_VIACOMBO] = azx_via_get_position,
[POS_FIX_COMBO] = azx_get_pos_lpib,
};
chip->get_position[0] = chip->get_position[1] = callbacks[fix];
if (fix == POS_FIX_COMBO)
chip->get_position[1] = NULL;
if (fix == POS_FIX_POSBUF &&
(chip->driver_caps & AZX_DCAPS_COUNT_LPIB_DELAY)) {
chip->get_delay[0] = chip->get_delay[1] =
azx_get_delay_from_lpib;
}
}
static void check_probe_mask(struct azx *chip, int dev)
{
const struct snd_pci_quirk *q;
chip->codec_probe_mask = probe_mask[dev];
if (chip->codec_probe_mask == -1) {
q = snd_pci_quirk_lookup(chip->pci, probe_mask_list);
if (q) {
dev_info(chip->card->dev,
"probe_mask set to 0x%x for device %04x:%04x\n",
q->value, q->subvendor, q->subdevice);
chip->codec_probe_mask = q->value;
}
}
if (chip->codec_probe_mask != -1 &&
(chip->codec_probe_mask & AZX_FORCE_CODEC_MASK)) {
azx_bus(chip)->codec_mask = chip->codec_probe_mask & 0xff;
dev_info(chip->card->dev, "codec_mask forced to 0x%x\n",
(int)azx_bus(chip)->codec_mask);
}
}
static void check_msi(struct azx *chip)
{
const struct snd_pci_quirk *q;
if (enable_msi >= 0) {
chip->msi = !!enable_msi;
return;
}
chip->msi = 1;
q = snd_pci_quirk_lookup(chip->pci, msi_black_list);
if (q) {
dev_info(chip->card->dev,
"msi for device %04x:%04x set to %d\n",
q->subvendor, q->subdevice, q->value);
chip->msi = q->value;
return;
}
if (chip->driver_caps & AZX_DCAPS_NO_MSI) {
dev_info(chip->card->dev, "Disabling MSI\n");
chip->msi = 0;
}
}
static void azx_check_snoop_available(struct azx *chip)
{
int snoop = hda_snoop;
if (snoop >= 0) {
dev_info(chip->card->dev, "Force to %s mode by module option\n",
snoop ? "snoop" : "non-snoop");
chip->snoop = snoop;
return;
}
snoop = true;
if (azx_get_snoop_type(chip) == AZX_SNOOP_TYPE_NONE &&
chip->driver_type == AZX_DRIVER_VIA) {
u8 val;
pci_read_config_byte(chip->pci, 0x42, &val);
if (!(val & 0x80) && chip->pci->revision == 0x30)
snoop = false;
}
if (chip->driver_caps & AZX_DCAPS_SNOOP_OFF)
snoop = false;
chip->snoop = snoop;
if (!snoop)
dev_info(chip->card->dev, "Force to non-snoop mode\n");
}
static void azx_probe_work(struct work_struct *work)
{
struct hda_intel *hda = container_of(work, struct hda_intel, probe_work);
azx_probe_continue(&hda->chip);
}
static int default_bdl_pos_adj(struct azx *chip)
{
if (chip->pci->vendor == PCI_VENDOR_ID_INTEL) {
switch (chip->pci->device) {
case 0x0f04:
case 0x2284:
return 32;
}
}
switch (chip->driver_type) {
case AZX_DRIVER_ICH:
case AZX_DRIVER_PCH:
return 1;
default:
return 32;
}
}
static int azx_create(struct snd_card *card, struct pci_dev *pci,
int dev, unsigned int driver_caps,
struct azx **rchip)
{
static struct snd_device_ops ops = {
.dev_disconnect = azx_dev_disconnect,
.dev_free = azx_dev_free,
};
struct hda_intel *hda;
struct azx *chip;
int err;
*rchip = NULL;
err = pci_enable_device(pci);
if (err < 0)
return err;
hda = kzalloc(sizeof(*hda), GFP_KERNEL);
if (!hda) {
pci_disable_device(pci);
return -ENOMEM;
}
chip = &hda->chip;
mutex_init(&chip->open_mutex);
chip->card = card;
chip->pci = pci;
chip->ops = &pci_hda_ops;
chip->driver_caps = driver_caps;
chip->driver_type = driver_caps & 0xff;
check_msi(chip);
chip->dev_index = dev;
chip->jackpoll_ms = jackpoll_ms;
INIT_LIST_HEAD(&chip->pcm_list);
INIT_WORK(&hda->irq_pending_work, azx_irq_pending_work);
INIT_LIST_HEAD(&hda->list);
init_vga_switcheroo(chip);
init_completion(&hda->probe_wait);
assign_position_fix(chip, check_position_fix(chip, position_fix[dev]));
check_probe_mask(chip, dev);
chip->single_cmd = single_cmd;
azx_check_snoop_available(chip);
if (bdl_pos_adj[dev] < 0)
chip->bdl_pos_adj = default_bdl_pos_adj(chip);
else
chip->bdl_pos_adj = bdl_pos_adj[dev];
err = azx_bus_init(chip, model[dev], &pci_hda_io_ops);
if (err < 0) {
kfree(hda);
pci_disable_device(pci);
return err;
}
if (chip->driver_type == AZX_DRIVER_NVIDIA) {
dev_dbg(chip->card->dev, "Enable delay in RIRB handling\n");
chip->bus.needs_damn_long_delay = 1;
}
err = snd_device_new(card, SNDRV_DEV_LOWLEVEL, chip, &ops);
if (err < 0) {
dev_err(card->dev, "Error creating device [card]!\n");
azx_free(chip);
return err;
}
INIT_WORK(&hda->probe_work, azx_probe_work);
*rchip = chip;
return 0;
}
static int azx_first_init(struct azx *chip)
{
int dev = chip->dev_index;
struct pci_dev *pci = chip->pci;
struct snd_card *card = chip->card;
struct hdac_bus *bus = azx_bus(chip);
int err;
unsigned short gcap;
unsigned int dma_bits = 64;
#if BITS_PER_LONG != 64
if (chip->driver_type == AZX_DRIVER_ULI) {
u16 tmp3;
pci_read_config_word(pci, 0x40, &tmp3);
pci_write_config_word(pci, 0x40, tmp3 | 0x10);
pci_write_config_dword(pci, PCI_BASE_ADDRESS_1, 0);
}
#endif
err = pci_request_regions(pci, "ICH HD audio");
if (err < 0)
return err;
chip->region_requested = 1;
bus->addr = pci_resource_start(pci, 0);
bus->remap_addr = pci_ioremap_bar(pci, 0);
if (bus->remap_addr == NULL) {
dev_err(card->dev, "ioremap error\n");
return -ENXIO;
}
if (IS_SKL_PLUS(pci))
snd_hdac_bus_parse_capabilities(bus);
chip->gts_present = false;
#ifdef CONFIG_X86
if (bus->ppcap && boot_cpu_has(X86_FEATURE_ART))
chip->gts_present = true;
#endif
if (chip->msi) {
if (chip->driver_caps & AZX_DCAPS_NO_MSI64) {
dev_dbg(card->dev, "Disabling 64bit MSI\n");
pci->no_64bit_msi = true;
}
if (pci_enable_msi(pci) < 0)
chip->msi = 0;
}
if (azx_acquire_irq(chip, 0) < 0)
return -EBUSY;
pci_set_master(pci);
synchronize_irq(bus->irq);
gcap = azx_readw(chip, GCAP);
dev_dbg(card->dev, "chipset global capabilities = 0x%x\n", gcap);
if (chip->pci->vendor == PCI_VENDOR_ID_AMD)
dma_bits = 40;
if (chip->pci->vendor == PCI_VENDOR_ID_ATI) {
struct pci_dev *p_smbus;
dma_bits = 40;
p_smbus = pci_get_device(PCI_VENDOR_ID_ATI,
PCI_DEVICE_ID_ATI_SBX00_SMBUS,
NULL);
if (p_smbus) {
if (p_smbus->revision < 0x30)
gcap &= ~AZX_GCAP_64OK;
pci_dev_put(p_smbus);
}
}
if (chip->pci->vendor == PCI_VENDOR_ID_NVIDIA)
dma_bits = 40;
if (chip->driver_caps & AZX_DCAPS_NO_64BIT) {
dev_dbg(card->dev, "Disabling 64bit DMA\n");
gcap &= ~AZX_GCAP_64OK;
}
if (align_buffer_size >= 0)
chip->align_buffer_size = !!align_buffer_size;
else {
if (chip->driver_caps & AZX_DCAPS_NO_ALIGN_BUFSIZE)
chip->align_buffer_size = 0;
else
chip->align_buffer_size = 1;
}
if (!(gcap & AZX_GCAP_64OK))
dma_bits = 32;
if (!dma_set_mask(&pci->dev, DMA_BIT_MASK(dma_bits))) {
dma_set_coherent_mask(&pci->dev, DMA_BIT_MASK(dma_bits));
} else {
dma_set_mask(&pci->dev, DMA_BIT_MASK(32));
dma_set_coherent_mask(&pci->dev, DMA_BIT_MASK(32));
}
chip->capture_streams = (gcap >> 8) & 0x0f;
chip->playback_streams = (gcap >> 12) & 0x0f;
if (!chip->playback_streams && !chip->capture_streams) {
switch (chip->driver_type) {
case AZX_DRIVER_ULI:
chip->playback_streams = ULI_NUM_PLAYBACK;
chip->capture_streams = ULI_NUM_CAPTURE;
break;
case AZX_DRIVER_ATIHDMI:
case AZX_DRIVER_ATIHDMI_NS:
chip->playback_streams = ATIHDMI_NUM_PLAYBACK;
chip->capture_streams = ATIHDMI_NUM_CAPTURE;
break;
case AZX_DRIVER_GENERIC:
default:
chip->playback_streams = ICH6_NUM_PLAYBACK;
chip->capture_streams = ICH6_NUM_CAPTURE;
break;
}
}
chip->capture_index_offset = 0;
chip->playback_index_offset = chip->capture_streams;
chip->num_streams = chip->playback_streams + chip->capture_streams;
err = azx_init_streams(chip);
if (err < 0)
return err;
err = azx_alloc_stream_pages(chip);
if (err < 0)
return err;
azx_init_pci(chip);
if (chip->driver_caps & AZX_DCAPS_I915_POWERWELL)
snd_hdac_i915_set_bclk(bus);
hda_intel_init_chip(chip, (probe_only[dev] & 2) == 0);
if (!azx_bus(chip)->codec_mask) {
dev_err(card->dev, "no codecs found!\n");
return -ENODEV;
}
strcpy(card->driver, "HDA-Intel");
strlcpy(card->shortname, driver_short_names[chip->driver_type],
sizeof(card->shortname));
snprintf(card->longname, sizeof(card->longname),
"%s at 0x%lx irq %i",
card->shortname, bus->addr, bus->irq);
return 0;
}
static void azx_firmware_cb(const struct firmware *fw, void *context)
{
struct snd_card *card = context;
struct azx *chip = card->private_data;
struct pci_dev *pci = chip->pci;
if (!fw) {
dev_err(card->dev, "Cannot load firmware, aborting\n");
goto error;
}
chip->fw = fw;
if (!chip->disabled) {
if (azx_probe_continue(chip))
goto error;
}
return;
error:
snd_card_free(card);
pci_set_drvdata(pci, NULL);
}
static void pci_azx_writel(u32 value, u32 __iomem *addr)
{
writel(value, addr);
}
static u32 pci_azx_readl(u32 __iomem *addr)
{
return readl(addr);
}
static void pci_azx_writew(u16 value, u16 __iomem *addr)
{
writew(value, addr);
}
static u16 pci_azx_readw(u16 __iomem *addr)
{
return readw(addr);
}
static void pci_azx_writeb(u8 value, u8 __iomem *addr)
{
writeb(value, addr);
}
static u8 pci_azx_readb(u8 __iomem *addr)
{
return readb(addr);
}
static int disable_msi_reset_irq(struct azx *chip)
{
struct hdac_bus *bus = azx_bus(chip);
int err;
free_irq(bus->irq, chip);
bus->irq = -1;
pci_disable_msi(chip->pci);
chip->msi = 0;
err = azx_acquire_irq(chip, 1);
if (err < 0)
return err;
return 0;
}
static int dma_alloc_pages(struct hdac_bus *bus,
int type,
size_t size,
struct snd_dma_buffer *buf)
{
struct azx *chip = bus_to_azx(bus);
int err;
err = snd_dma_alloc_pages(type,
bus->dev,
size, buf);
if (err < 0)
return err;
mark_pages_wc(chip, buf, true);
return 0;
}
static void dma_free_pages(struct hdac_bus *bus, struct snd_dma_buffer *buf)
{
struct azx *chip = bus_to_azx(bus);
mark_pages_wc(chip, buf, false);
snd_dma_free_pages(buf);
}
static int substream_alloc_pages(struct azx *chip,
struct snd_pcm_substream *substream,
size_t size)
{
struct azx_dev *azx_dev = get_azx_dev(substream);
int ret;
mark_runtime_wc(chip, azx_dev, substream, false);
ret = snd_pcm_lib_malloc_pages(substream, size);
if (ret < 0)
return ret;
mark_runtime_wc(chip, azx_dev, substream, true);
return 0;
}
static int substream_free_pages(struct azx *chip,
struct snd_pcm_substream *substream)
{
struct azx_dev *azx_dev = get_azx_dev(substream);
mark_runtime_wc(chip, azx_dev, substream, false);
return snd_pcm_lib_free_pages(substream);
}
static void pcm_mmap_prepare(struct snd_pcm_substream *substream,
struct vm_area_struct *area)
{
#ifdef CONFIG_X86
struct azx_pcm *apcm = snd_pcm_substream_chip(substream);
struct azx *chip = apcm->chip;
if (!azx_snoop(chip) && chip->driver_type != AZX_DRIVER_CMEDIA)
area->vm_page_prot = pgprot_writecombine(area->vm_page_prot);
#endif
}
static int azx_probe(struct pci_dev *pci,
const struct pci_device_id *pci_id)
{
static int dev;
struct snd_card *card;
struct hda_intel *hda;
struct azx *chip;
bool schedule_probe;
int err;
if (dev >= SNDRV_CARDS)
return -ENODEV;
if (!enable[dev]) {
dev++;
return -ENOENT;
}
err = snd_card_new(&pci->dev, index[dev], id[dev], THIS_MODULE,
0, &card);
if (err < 0) {
dev_err(&pci->dev, "Error creating card!\n");
return err;
}
err = azx_create(card, pci, dev, pci_id->driver_data, &chip);
if (err < 0)
goto out_free;
card->private_data = chip;
hda = container_of(chip, struct hda_intel, chip);
pci_set_drvdata(pci, card);
err = register_vga_switcheroo(chip);
if (err < 0) {
dev_err(card->dev, "Error registering vga_switcheroo client\n");
goto out_free;
}
if (check_hdmi_disabled(pci)) {
dev_info(card->dev, "VGA controller is disabled\n");
dev_info(card->dev, "Delaying initialization\n");
chip->disabled = true;
}
schedule_probe = !chip->disabled;
#ifdef CONFIG_SND_HDA_PATCH_LOADER
if (patch[dev] && *patch[dev]) {
dev_info(card->dev, "Applying patch firmware '%s'\n",
patch[dev]);
err = request_firmware_nowait(THIS_MODULE, true, patch[dev],
&pci->dev, GFP_KERNEL, card,
azx_firmware_cb);
if (err < 0)
goto out_free;
schedule_probe = false;
}
#endif
#ifndef CONFIG_SND_HDA_I915
if (CONTROLLER_IN_GPU(pci))
dev_err(card->dev, "Haswell/Broadwell HDMI/DP must build in CONFIG_SND_HDA_I915\n");
#endif
if (schedule_probe)
schedule_work(&hda->probe_work);
dev++;
if (chip->disabled)
complete_all(&hda->probe_wait);
return 0;
out_free:
snd_card_free(card);
return err;
}
static int azx_probe_continue(struct azx *chip)
{
struct hda_intel *hda = container_of(chip, struct hda_intel, chip);
struct hdac_bus *bus = azx_bus(chip);
struct pci_dev *pci = chip->pci;
int dev = chip->dev_index;
int err;
hda->probe_continued = 1;
if (chip->driver_caps & AZX_DCAPS_I915_POWERWELL) {
if (CONTROLLER_IN_GPU(pci))
hda->need_i915_power = 1;
err = snd_hdac_i915_init(bus);
if (err < 0) {
if (CONTROLLER_IN_GPU(pci)) {
dev_err(chip->card->dev,
"HSW/BDW HD-audio HDMI/DP requires binding with gfx driver\n");
goto out_free;
} else
goto skip_i915;
}
err = snd_hdac_display_power(bus, true);
if (err < 0) {
dev_err(chip->card->dev,
"Cannot turn on display power on i915\n");
goto i915_power_fail;
}
}
skip_i915:
err = azx_first_init(chip);
if (err < 0)
goto out_free;
#ifdef CONFIG_SND_HDA_INPUT_BEEP
chip->beep_mode = beep_mode[dev];
#endif
err = azx_probe_codecs(chip, azx_max_codecs[chip->driver_type]);
if (err < 0)
goto out_free;
#ifdef CONFIG_SND_HDA_PATCH_LOADER
if (chip->fw) {
err = snd_hda_load_patch(&chip->bus, chip->fw->size,
chip->fw->data);
if (err < 0)
goto out_free;
#ifndef CONFIG_PM
release_firmware(chip->fw);
chip->fw = NULL;
#endif
}
#endif
if ((probe_only[dev] & 1) == 0) {
err = azx_codec_configure(chip);
if (err < 0)
goto out_free;
}
err = snd_card_register(chip->card);
if (err < 0)
goto out_free;
chip->running = 1;
azx_add_card_list(chip);
snd_hda_set_power_save(&chip->bus, power_save * 1000);
if (azx_has_pm_runtime(chip) || hda->use_vga_switcheroo)
pm_runtime_put_autosuspend(&pci->dev);
out_free:
if (chip->driver_caps & AZX_DCAPS_I915_POWERWELL
&& !hda->need_i915_power)
snd_hdac_display_power(bus, false);
i915_power_fail:
if (err < 0)
hda->init_failed = 1;
complete_all(&hda->probe_wait);
return err;
}
static void azx_remove(struct pci_dev *pci)
{
struct snd_card *card = pci_get_drvdata(pci);
struct azx *chip;
struct hda_intel *hda;
if (card) {
chip = card->private_data;
hda = container_of(chip, struct hda_intel, chip);
cancel_work_sync(&hda->probe_work);
snd_card_free(card);
}
}
static void azx_shutdown(struct pci_dev *pci)
{
struct snd_card *card = pci_get_drvdata(pci);
struct azx *chip;
if (!card)
return;
chip = card->private_data;
if (chip && chip->running)
azx_stop_chip(chip);
}
