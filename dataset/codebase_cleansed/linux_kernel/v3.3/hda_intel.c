static void __mark_pages_wc(struct azx *chip, void *addr, size_t size, bool on)
{
if (azx_snoop(chip))
return;
if (addr && size) {
int pages = (size + PAGE_SIZE - 1) >> PAGE_SHIFT;
if (on)
set_memory_wc((unsigned long)addr, pages);
else
set_memory_wb((unsigned long)addr, pages);
}
}
static inline void mark_pages_wc(struct azx *chip, struct snd_dma_buffer *buf,
bool on)
{
__mark_pages_wc(chip, buf->area, buf->bytes, on);
}
static inline void mark_runtime_wc(struct azx *chip, struct azx_dev *azx_dev,
struct snd_pcm_runtime *runtime, bool on)
{
if (azx_dev->wc_marked != on) {
__mark_pages_wc(chip, runtime->dma_area, runtime->dma_bytes, on);
azx_dev->wc_marked = on;
}
}
static inline void mark_pages_wc(struct azx *chip, struct snd_dma_buffer *buf,
bool on)
{
}
static inline void mark_runtime_wc(struct azx *chip, struct azx_dev *azx_dev,
struct snd_pcm_runtime *runtime, bool on)
{
}
static int azx_alloc_cmd_io(struct azx *chip)
{
int err;
err = snd_dma_alloc_pages(SNDRV_DMA_TYPE_DEV,
snd_dma_pci_data(chip->pci),
PAGE_SIZE, &chip->rb);
if (err < 0) {
snd_printk(KERN_ERR SFX "cannot allocate CORB/RIRB\n");
return err;
}
mark_pages_wc(chip, &chip->rb, true);
return 0;
}
static void azx_init_cmd_io(struct azx *chip)
{
spin_lock_irq(&chip->reg_lock);
chip->corb.addr = chip->rb.addr;
chip->corb.buf = (u32 *)chip->rb.area;
azx_writel(chip, CORBLBASE, (u32)chip->corb.addr);
azx_writel(chip, CORBUBASE, upper_32_bits(chip->corb.addr));
azx_writeb(chip, CORBSIZE, 0x02);
azx_writew(chip, CORBWP, 0);
azx_writew(chip, CORBRP, ICH6_CORBRP_RST);
azx_writeb(chip, CORBCTL, ICH6_CORBCTL_RUN);
chip->rirb.addr = chip->rb.addr + 2048;
chip->rirb.buf = (u32 *)(chip->rb.area + 2048);
chip->rirb.wp = chip->rirb.rp = 0;
memset(chip->rirb.cmds, 0, sizeof(chip->rirb.cmds));
azx_writel(chip, RIRBLBASE, (u32)chip->rirb.addr);
azx_writel(chip, RIRBUBASE, upper_32_bits(chip->rirb.addr));
azx_writeb(chip, RIRBSIZE, 0x02);
azx_writew(chip, RIRBWP, ICH6_RIRBWP_RST);
if (chip->driver_caps & AZX_DCAPS_CTX_WORKAROUND)
azx_writew(chip, RINTCNT, 0xc0);
else
azx_writew(chip, RINTCNT, 1);
azx_writeb(chip, RIRBCTL, ICH6_RBCTL_DMA_EN | ICH6_RBCTL_IRQ_EN);
spin_unlock_irq(&chip->reg_lock);
}
static void azx_free_cmd_io(struct azx *chip)
{
spin_lock_irq(&chip->reg_lock);
azx_writeb(chip, RIRBCTL, 0);
azx_writeb(chip, CORBCTL, 0);
spin_unlock_irq(&chip->reg_lock);
}
static unsigned int azx_command_addr(u32 cmd)
{
unsigned int addr = cmd >> 28;
if (addr >= AZX_MAX_CODECS) {
snd_BUG();
addr = 0;
}
return addr;
}
static unsigned int azx_response_addr(u32 res)
{
unsigned int addr = res & 0xf;
if (addr >= AZX_MAX_CODECS) {
snd_BUG();
addr = 0;
}
return addr;
}
static int azx_corb_send_cmd(struct hda_bus *bus, u32 val)
{
struct azx *chip = bus->private_data;
unsigned int addr = azx_command_addr(val);
unsigned int wp;
spin_lock_irq(&chip->reg_lock);
wp = azx_readb(chip, CORBWP);
wp++;
wp %= ICH6_MAX_CORB_ENTRIES;
chip->rirb.cmds[addr]++;
chip->corb.buf[wp] = cpu_to_le32(val);
azx_writel(chip, CORBWP, wp);
spin_unlock_irq(&chip->reg_lock);
return 0;
}
static void azx_update_rirb(struct azx *chip)
{
unsigned int rp, wp;
unsigned int addr;
u32 res, res_ex;
wp = azx_readb(chip, RIRBWP);
if (wp == chip->rirb.wp)
return;
chip->rirb.wp = wp;
while (chip->rirb.rp != wp) {
chip->rirb.rp++;
chip->rirb.rp %= ICH6_MAX_RIRB_ENTRIES;
rp = chip->rirb.rp << 1;
res_ex = le32_to_cpu(chip->rirb.buf[rp + 1]);
res = le32_to_cpu(chip->rirb.buf[rp]);
addr = azx_response_addr(res_ex);
if (res_ex & ICH6_RIRB_EX_UNSOL_EV)
snd_hda_queue_unsol_event(chip->bus, res, res_ex);
else if (chip->rirb.cmds[addr]) {
chip->rirb.res[addr] = res;
smp_wmb();
chip->rirb.cmds[addr]--;
} else
snd_printk(KERN_ERR SFX "spurious response %#x:%#x, "
"last cmd=%#08x\n",
res, res_ex,
chip->last_cmd[addr]);
}
}
static unsigned int azx_rirb_get_response(struct hda_bus *bus,
unsigned int addr)
{
struct azx *chip = bus->private_data;
unsigned long timeout;
int do_poll = 0;
again:
timeout = jiffies + msecs_to_jiffies(1000);
for (;;) {
if (chip->polling_mode || do_poll) {
spin_lock_irq(&chip->reg_lock);
azx_update_rirb(chip);
spin_unlock_irq(&chip->reg_lock);
}
if (!chip->rirb.cmds[addr]) {
smp_rmb();
bus->rirb_error = 0;
if (!do_poll)
chip->poll_count = 0;
return chip->rirb.res[addr];
}
if (time_after(jiffies, timeout))
break;
if (bus->needs_damn_long_delay)
msleep(2);
else {
udelay(10);
cond_resched();
}
}
if (!chip->polling_mode && chip->poll_count < 2) {
snd_printdd(SFX "azx_get_response timeout, "
"polling the codec once: last cmd=0x%08x\n",
chip->last_cmd[addr]);
do_poll = 1;
chip->poll_count++;
goto again;
}
if (!chip->polling_mode) {
snd_printk(KERN_WARNING SFX "azx_get_response timeout, "
"switching to polling mode: last cmd=0x%08x\n",
chip->last_cmd[addr]);
chip->polling_mode = 1;
goto again;
}
if (chip->msi) {
snd_printk(KERN_WARNING SFX "No response from codec, "
"disabling MSI: last cmd=0x%08x\n",
chip->last_cmd[addr]);
free_irq(chip->irq, chip);
chip->irq = -1;
pci_disable_msi(chip->pci);
chip->msi = 0;
if (azx_acquire_irq(chip, 1) < 0) {
bus->rirb_error = 1;
return -1;
}
goto again;
}
if (chip->probing) {
return -1;
}
bus->rirb_error = 1;
if (bus->allow_bus_reset && !bus->response_reset && !bus->in_reset) {
bus->response_reset = 1;
return -1;
}
snd_printk(KERN_ERR "hda_intel: azx_get_response timeout, "
"switching to single_cmd mode: last cmd=0x%08x\n",
chip->last_cmd[addr]);
chip->single_cmd = 1;
bus->response_reset = 0;
azx_free_cmd_io(chip);
azx_writel(chip, GCTL, azx_readl(chip, GCTL) & ~ICH6_GCTL_UNSOL);
return -1;
}
static int azx_single_wait_for_response(struct azx *chip, unsigned int addr)
{
int timeout = 50;
while (timeout--) {
if (azx_readw(chip, IRS) & ICH6_IRS_VALID) {
chip->rirb.res[addr] = azx_readl(chip, IR);
return 0;
}
udelay(1);
}
if (printk_ratelimit())
snd_printd(SFX "get_response timeout: IRS=0x%x\n",
azx_readw(chip, IRS));
chip->rirb.res[addr] = -1;
return -EIO;
}
static int azx_single_send_cmd(struct hda_bus *bus, u32 val)
{
struct azx *chip = bus->private_data;
unsigned int addr = azx_command_addr(val);
int timeout = 50;
bus->rirb_error = 0;
while (timeout--) {
if (!((azx_readw(chip, IRS) & ICH6_IRS_BUSY))) {
azx_writew(chip, IRS, azx_readw(chip, IRS) |
ICH6_IRS_VALID);
azx_writel(chip, IC, val);
azx_writew(chip, IRS, azx_readw(chip, IRS) |
ICH6_IRS_BUSY);
return azx_single_wait_for_response(chip, addr);
}
udelay(1);
}
if (printk_ratelimit())
snd_printd(SFX "send_cmd timeout: IRS=0x%x, val=0x%x\n",
azx_readw(chip, IRS), val);
return -EIO;
}
static unsigned int azx_single_get_response(struct hda_bus *bus,
unsigned int addr)
{
struct azx *chip = bus->private_data;
return chip->rirb.res[addr];
}
static int azx_send_cmd(struct hda_bus *bus, unsigned int val)
{
struct azx *chip = bus->private_data;
chip->last_cmd[azx_command_addr(val)] = val;
if (chip->single_cmd)
return azx_single_send_cmd(bus, val);
else
return azx_corb_send_cmd(bus, val);
}
static unsigned int azx_get_response(struct hda_bus *bus,
unsigned int addr)
{
struct azx *chip = bus->private_data;
if (chip->single_cmd)
return azx_single_get_response(bus, addr);
else
return azx_rirb_get_response(bus, addr);
}
static int azx_reset(struct azx *chip, int full_reset)
{
int count;
if (!full_reset)
goto __skip;
azx_writeb(chip, STATESTS, STATESTS_INT_MASK);
azx_writel(chip, GCTL, azx_readl(chip, GCTL) & ~ICH6_GCTL_RESET);
count = 50;
while (azx_readb(chip, GCTL) && --count)
msleep(1);
msleep(1);
azx_writeb(chip, GCTL, azx_readb(chip, GCTL) | ICH6_GCTL_RESET);
count = 50;
while (!azx_readb(chip, GCTL) && --count)
msleep(1);
msleep(1);
__skip:
if (!azx_readb(chip, GCTL)) {
snd_printd(SFX "azx_reset: controller not ready!\n");
return -EBUSY;
}
if (!chip->single_cmd)
azx_writel(chip, GCTL, azx_readl(chip, GCTL) |
ICH6_GCTL_UNSOL);
if (!chip->codec_mask) {
chip->codec_mask = azx_readw(chip, STATESTS);
snd_printdd(SFX "codec_mask = 0x%x\n", chip->codec_mask);
}
return 0;
}
static void azx_int_enable(struct azx *chip)
{
azx_writel(chip, INTCTL, azx_readl(chip, INTCTL) |
ICH6_INT_CTRL_EN | ICH6_INT_GLOBAL_EN);
}
static void azx_int_disable(struct azx *chip)
{
int i;
for (i = 0; i < chip->num_streams; i++) {
struct azx_dev *azx_dev = &chip->azx_dev[i];
azx_sd_writeb(azx_dev, SD_CTL,
azx_sd_readb(azx_dev, SD_CTL) & ~SD_INT_MASK);
}
azx_writeb(chip, INTCTL, 0);
azx_writel(chip, INTCTL, azx_readl(chip, INTCTL) &
~(ICH6_INT_CTRL_EN | ICH6_INT_GLOBAL_EN));
}
static void azx_int_clear(struct azx *chip)
{
int i;
for (i = 0; i < chip->num_streams; i++) {
struct azx_dev *azx_dev = &chip->azx_dev[i];
azx_sd_writeb(azx_dev, SD_STS, SD_INT_MASK);
}
azx_writeb(chip, STATESTS, STATESTS_INT_MASK);
azx_writeb(chip, RIRBSTS, RIRB_INT_MASK);
azx_writel(chip, INTSTS, ICH6_INT_CTRL_EN | ICH6_INT_ALL_STREAM);
}
static void azx_stream_start(struct azx *chip, struct azx_dev *azx_dev)
{
azx_dev->insufficient = 1;
azx_writel(chip, INTCTL,
azx_readl(chip, INTCTL) | (1 << azx_dev->index));
azx_sd_writeb(azx_dev, SD_CTL, azx_sd_readb(azx_dev, SD_CTL) |
SD_CTL_DMA_START | SD_INT_MASK);
}
static void azx_stream_clear(struct azx *chip, struct azx_dev *azx_dev)
{
azx_sd_writeb(azx_dev, SD_CTL, azx_sd_readb(azx_dev, SD_CTL) &
~(SD_CTL_DMA_START | SD_INT_MASK));
azx_sd_writeb(azx_dev, SD_STS, SD_INT_MASK);
}
static void azx_stream_stop(struct azx *chip, struct azx_dev *azx_dev)
{
azx_stream_clear(chip, azx_dev);
azx_writel(chip, INTCTL,
azx_readl(chip, INTCTL) & ~(1 << azx_dev->index));
}
static void azx_init_chip(struct azx *chip, int full_reset)
{
if (chip->initialized)
return;
azx_reset(chip, full_reset);
azx_int_clear(chip);
azx_int_enable(chip);
if (!chip->single_cmd)
azx_init_cmd_io(chip);
azx_writel(chip, DPLBASE, (u32)chip->posbuf.addr);
azx_writel(chip, DPUBASE, upper_32_bits(chip->posbuf.addr));
chip->initialized = 1;
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
if (!(chip->driver_caps & AZX_DCAPS_NO_TCSEL)) {
snd_printdd(SFX "Clearing TCSEL\n");
update_pci_byte(chip->pci, ICH6_PCIREG_TCSEL, 0x07, 0);
}
if (chip->driver_caps & AZX_DCAPS_ATI_SNOOP) {
snd_printdd(SFX "Setting ATI snoop: %d\n", azx_snoop(chip));
update_pci_byte(chip->pci,
ATI_SB450_HDAUDIO_MISC_CNTR2_ADDR, 0x07,
azx_snoop(chip) ? ATI_SB450_HDAUDIO_ENABLE_SNOOP : 0);
}
if (chip->driver_caps & AZX_DCAPS_NVIDIA_SNOOP) {
snd_printdd(SFX "Setting Nvidia snoop: %d\n", azx_snoop(chip));
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
if (chip->driver_caps & AZX_DCAPS_SCH_SNOOP) {
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
snd_printdd(SFX "SCH snoop: %s\n",
(snoop & INTEL_SCH_HDA_DEVC_NOSNOOP)
? "Disabled" : "Enabled");
}
}
static irqreturn_t azx_interrupt(int irq, void *dev_id)
{
struct azx *chip = dev_id;
struct azx_dev *azx_dev;
u32 status;
u8 sd_status;
int i, ok;
spin_lock(&chip->reg_lock);
status = azx_readl(chip, INTSTS);
if (status == 0) {
spin_unlock(&chip->reg_lock);
return IRQ_NONE;
}
for (i = 0; i < chip->num_streams; i++) {
azx_dev = &chip->azx_dev[i];
if (status & azx_dev->sd_int_sta_mask) {
sd_status = azx_sd_readb(azx_dev, SD_STS);
azx_sd_writeb(azx_dev, SD_STS, SD_INT_MASK);
if (!azx_dev->substream || !azx_dev->running ||
!(sd_status & SD_INT_COMPLETE))
continue;
ok = azx_position_ok(chip, azx_dev);
if (ok == 1) {
azx_dev->irq_pending = 0;
spin_unlock(&chip->reg_lock);
snd_pcm_period_elapsed(azx_dev->substream);
spin_lock(&chip->reg_lock);
} else if (ok == 0 && chip->bus && chip->bus->workq) {
azx_dev->irq_pending = 1;
queue_work(chip->bus->workq,
&chip->irq_pending_work);
}
}
}
status = azx_readb(chip, RIRBSTS);
if (status & RIRB_INT_MASK) {
if (status & RIRB_INT_RESPONSE) {
if (chip->driver_caps & AZX_DCAPS_RIRB_PRE_DELAY)
udelay(80);
azx_update_rirb(chip);
}
azx_writeb(chip, RIRBSTS, RIRB_INT_MASK);
}
#if 0
if (azx_readb(chip, STATESTS) & 0x04)
azx_writeb(chip, STATESTS, 0x04);
#endif
spin_unlock(&chip->reg_lock);
return IRQ_HANDLED;
}
static int setup_bdle(struct snd_pcm_substream *substream,
struct azx_dev *azx_dev, u32 **bdlp,
int ofs, int size, int with_ioc)
{
u32 *bdl = *bdlp;
while (size > 0) {
dma_addr_t addr;
int chunk;
if (azx_dev->frags >= AZX_MAX_BDL_ENTRIES)
return -EINVAL;
addr = snd_pcm_sgbuf_get_addr(substream, ofs);
bdl[0] = cpu_to_le32((u32)addr);
bdl[1] = cpu_to_le32(upper_32_bits(addr));
chunk = snd_pcm_sgbuf_get_chunk_size(substream, ofs, size);
bdl[2] = cpu_to_le32(chunk);
size -= chunk;
bdl[3] = (size || !with_ioc) ? 0 : cpu_to_le32(0x01);
bdl += 4;
azx_dev->frags++;
ofs += chunk;
}
*bdlp = bdl;
return ofs;
}
static int azx_setup_periods(struct azx *chip,
struct snd_pcm_substream *substream,
struct azx_dev *azx_dev)
{
u32 *bdl;
int i, ofs, periods, period_bytes;
int pos_adj;
azx_sd_writel(azx_dev, SD_BDLPL, 0);
azx_sd_writel(azx_dev, SD_BDLPU, 0);
period_bytes = azx_dev->period_bytes;
periods = azx_dev->bufsize / period_bytes;
bdl = (u32 *)azx_dev->bdl.area;
ofs = 0;
azx_dev->frags = 0;
pos_adj = bdl_pos_adj[chip->dev_index];
if (pos_adj > 0) {
struct snd_pcm_runtime *runtime = substream->runtime;
int pos_align = pos_adj;
pos_adj = (pos_adj * runtime->rate + 47999) / 48000;
if (!pos_adj)
pos_adj = pos_align;
else
pos_adj = ((pos_adj + pos_align - 1) / pos_align) *
pos_align;
pos_adj = frames_to_bytes(runtime, pos_adj);
if (pos_adj >= period_bytes) {
snd_printk(KERN_WARNING SFX "Too big adjustment %d\n",
bdl_pos_adj[chip->dev_index]);
pos_adj = 0;
} else {
ofs = setup_bdle(substream, azx_dev,
&bdl, ofs, pos_adj,
!substream->runtime->no_period_wakeup);
if (ofs < 0)
goto error;
}
} else
pos_adj = 0;
for (i = 0; i < periods; i++) {
if (i == periods - 1 && pos_adj)
ofs = setup_bdle(substream, azx_dev, &bdl, ofs,
period_bytes - pos_adj, 0);
else
ofs = setup_bdle(substream, azx_dev, &bdl, ofs,
period_bytes,
!substream->runtime->no_period_wakeup);
if (ofs < 0)
goto error;
}
return 0;
error:
snd_printk(KERN_ERR SFX "Too many BDL entries: buffer=%d, period=%d\n",
azx_dev->bufsize, period_bytes);
return -EINVAL;
}
static void azx_stream_reset(struct azx *chip, struct azx_dev *azx_dev)
{
unsigned char val;
int timeout;
azx_stream_clear(chip, azx_dev);
azx_sd_writeb(azx_dev, SD_CTL, azx_sd_readb(azx_dev, SD_CTL) |
SD_CTL_STREAM_RESET);
udelay(3);
timeout = 300;
while (!((val = azx_sd_readb(azx_dev, SD_CTL)) & SD_CTL_STREAM_RESET) &&
--timeout)
;
val &= ~SD_CTL_STREAM_RESET;
azx_sd_writeb(azx_dev, SD_CTL, val);
udelay(3);
timeout = 300;
while (((val = azx_sd_readb(azx_dev, SD_CTL)) & SD_CTL_STREAM_RESET) &&
--timeout)
;
*azx_dev->posbuf = 0;
}
static int azx_setup_controller(struct azx *chip, struct azx_dev *azx_dev)
{
unsigned int val;
azx_stream_clear(chip, azx_dev);
val = azx_sd_readl(azx_dev, SD_CTL);
val = (val & ~SD_CTL_STREAM_TAG_MASK) |
(azx_dev->stream_tag << SD_CTL_STREAM_TAG_SHIFT);
if (!azx_snoop(chip))
val |= SD_CTL_TRAFFIC_PRIO;
azx_sd_writel(azx_dev, SD_CTL, val);
azx_sd_writel(azx_dev, SD_CBL, azx_dev->bufsize);
azx_sd_writew(azx_dev, SD_FORMAT, azx_dev->format_val);
azx_sd_writew(azx_dev, SD_LVI, azx_dev->frags - 1);
azx_sd_writel(azx_dev, SD_BDLPL, (u32)azx_dev->bdl.addr);
azx_sd_writel(azx_dev, SD_BDLPU, upper_32_bits(azx_dev->bdl.addr));
if (chip->position_fix[0] != POS_FIX_LPIB ||
chip->position_fix[1] != POS_FIX_LPIB) {
if (!(azx_readl(chip, DPLBASE) & ICH6_DPLBASE_ENABLE))
azx_writel(chip, DPLBASE,
(u32)chip->posbuf.addr | ICH6_DPLBASE_ENABLE);
}
azx_sd_writel(azx_dev, SD_CTL,
azx_sd_readl(azx_dev, SD_CTL) | SD_INT_MASK);
return 0;
}
static int probe_codec(struct azx *chip, int addr)
{
unsigned int cmd = (addr << 28) | (AC_NODE_ROOT << 20) |
(AC_VERB_PARAMETERS << 8) | AC_PAR_VENDOR_ID;
unsigned int res;
mutex_lock(&chip->bus->cmd_mutex);
chip->probing = 1;
azx_send_cmd(chip->bus, cmd);
res = azx_get_response(chip->bus, addr);
chip->probing = 0;
mutex_unlock(&chip->bus->cmd_mutex);
if (res == -1)
return -EIO;
snd_printdd(SFX "codec #%d probed OK\n", addr);
return 0;
}
static void azx_bus_reset(struct hda_bus *bus)
{
struct azx *chip = bus->private_data;
bus->in_reset = 1;
azx_stop_chip(chip);
azx_init_chip(chip, 1);
#ifdef CONFIG_PM
if (chip->initialized) {
struct azx_pcm *p;
list_for_each_entry(p, &chip->pcm_list, list)
snd_pcm_suspend_all(p->pcm);
snd_hda_suspend(chip->bus);
snd_hda_resume(chip->bus);
}
#endif
bus->in_reset = 0;
}
static int __devinit azx_codec_create(struct azx *chip, const char *model)
{
struct hda_bus_template bus_temp;
int c, codecs, err;
int max_slots;
memset(&bus_temp, 0, sizeof(bus_temp));
bus_temp.private_data = chip;
bus_temp.modelname = model;
bus_temp.pci = chip->pci;
bus_temp.ops.command = azx_send_cmd;
bus_temp.ops.get_response = azx_get_response;
bus_temp.ops.attach_pcm = azx_attach_pcm_stream;
bus_temp.ops.bus_reset = azx_bus_reset;
#ifdef CONFIG_SND_HDA_POWER_SAVE
bus_temp.power_save = &power_save;
bus_temp.ops.pm_notify = azx_power_notify;
#endif
err = snd_hda_bus_new(chip->card, &bus_temp, &chip->bus);
if (err < 0)
return err;
if (chip->driver_caps & AZX_DCAPS_RIRB_DELAY) {
snd_printd(SFX "Enable delay in RIRB handling\n");
chip->bus->needs_damn_long_delay = 1;
}
codecs = 0;
max_slots = azx_max_codecs[chip->driver_type];
if (!max_slots)
max_slots = AZX_DEFAULT_CODECS;
for (c = 0; c < max_slots; c++) {
if ((chip->codec_mask & (1 << c)) & chip->codec_probe_mask) {
if (probe_codec(chip, c) < 0) {
snd_printk(KERN_WARNING SFX
"Codec #%d probe error; "
"disabling it...\n", c);
chip->codec_mask &= ~(1 << c);
azx_stop_chip(chip);
azx_init_chip(chip, 1);
}
}
}
if (chip->driver_caps & AZX_DCAPS_SYNC_WRITE) {
snd_printd(SFX "Enable sync_write for stable communication\n");
chip->bus->sync_write = 1;
chip->bus->allow_bus_reset = 1;
}
for (c = 0; c < max_slots; c++) {
if ((chip->codec_mask & (1 << c)) & chip->codec_probe_mask) {
struct hda_codec *codec;
err = snd_hda_codec_new(chip->bus, c, &codec);
if (err < 0)
continue;
codec->beep_mode = chip->beep_mode;
codecs++;
}
}
if (!codecs) {
snd_printk(KERN_ERR SFX "no codecs initialized\n");
return -ENXIO;
}
return 0;
}
static int __devinit azx_codec_configure(struct azx *chip)
{
struct hda_codec *codec;
list_for_each_entry(codec, &chip->bus->codec_list, list) {
snd_hda_codec_configure(codec);
}
return 0;
}
static inline struct azx_dev *
azx_assign_device(struct azx *chip, struct snd_pcm_substream *substream)
{
int dev, i, nums;
struct azx_dev *res = NULL;
int key = (substream->pcm->device << 16) | (substream->number << 2) |
(substream->stream + 1);
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) {
dev = chip->playback_index_offset;
nums = chip->playback_streams;
} else {
dev = chip->capture_index_offset;
nums = chip->capture_streams;
}
for (i = 0; i < nums; i++, dev++)
if (!chip->azx_dev[dev].opened) {
res = &chip->azx_dev[dev];
if (res->assigned_key == key)
break;
}
if (res) {
res->opened = 1;
res->assigned_key = key;
}
return res;
}
static inline void azx_release_device(struct azx_dev *azx_dev)
{
azx_dev->opened = 0;
}
static int azx_pcm_open(struct snd_pcm_substream *substream)
{
struct azx_pcm *apcm = snd_pcm_substream_chip(substream);
struct hda_pcm_stream *hinfo = apcm->hinfo[substream->stream];
struct azx *chip = apcm->chip;
struct azx_dev *azx_dev;
struct snd_pcm_runtime *runtime = substream->runtime;
unsigned long flags;
int err;
int buff_step;
mutex_lock(&chip->open_mutex);
azx_dev = azx_assign_device(chip, substream);
if (azx_dev == NULL) {
mutex_unlock(&chip->open_mutex);
return -EBUSY;
}
runtime->hw = azx_pcm_hw;
runtime->hw.channels_min = hinfo->channels_min;
runtime->hw.channels_max = hinfo->channels_max;
runtime->hw.formats = hinfo->formats;
runtime->hw.rates = hinfo->rates;
snd_pcm_limit_hw_rates(runtime);
snd_pcm_hw_constraint_integer(runtime, SNDRV_PCM_HW_PARAM_PERIODS);
if (chip->align_buffer_size)
buff_step = 128;
else
buff_step = 4;
snd_pcm_hw_constraint_step(runtime, 0, SNDRV_PCM_HW_PARAM_BUFFER_BYTES,
buff_step);
snd_pcm_hw_constraint_step(runtime, 0, SNDRV_PCM_HW_PARAM_PERIOD_BYTES,
buff_step);
snd_hda_power_up(apcm->codec);
err = hinfo->ops.open(hinfo, apcm->codec, substream);
if (err < 0) {
azx_release_device(azx_dev);
snd_hda_power_down(apcm->codec);
mutex_unlock(&chip->open_mutex);
return err;
}
snd_pcm_limit_hw_rates(runtime);
if (snd_BUG_ON(!runtime->hw.channels_min) ||
snd_BUG_ON(!runtime->hw.channels_max) ||
snd_BUG_ON(!runtime->hw.formats) ||
snd_BUG_ON(!runtime->hw.rates)) {
azx_release_device(azx_dev);
hinfo->ops.close(hinfo, apcm->codec, substream);
snd_hda_power_down(apcm->codec);
mutex_unlock(&chip->open_mutex);
return -EINVAL;
}
spin_lock_irqsave(&chip->reg_lock, flags);
azx_dev->substream = substream;
azx_dev->running = 0;
spin_unlock_irqrestore(&chip->reg_lock, flags);
runtime->private_data = azx_dev;
snd_pcm_set_sync(substream);
mutex_unlock(&chip->open_mutex);
return 0;
}
static int azx_pcm_close(struct snd_pcm_substream *substream)
{
struct azx_pcm *apcm = snd_pcm_substream_chip(substream);
struct hda_pcm_stream *hinfo = apcm->hinfo[substream->stream];
struct azx *chip = apcm->chip;
struct azx_dev *azx_dev = get_azx_dev(substream);
unsigned long flags;
mutex_lock(&chip->open_mutex);
spin_lock_irqsave(&chip->reg_lock, flags);
azx_dev->substream = NULL;
azx_dev->running = 0;
spin_unlock_irqrestore(&chip->reg_lock, flags);
azx_release_device(azx_dev);
hinfo->ops.close(hinfo, apcm->codec, substream);
snd_hda_power_down(apcm->codec);
mutex_unlock(&chip->open_mutex);
return 0;
}
static int azx_pcm_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *hw_params)
{
struct azx_pcm *apcm = snd_pcm_substream_chip(substream);
struct azx *chip = apcm->chip;
struct snd_pcm_runtime *runtime = substream->runtime;
struct azx_dev *azx_dev = get_azx_dev(substream);
int ret;
mark_runtime_wc(chip, azx_dev, runtime, false);
azx_dev->bufsize = 0;
azx_dev->period_bytes = 0;
azx_dev->format_val = 0;
ret = snd_pcm_lib_malloc_pages(substream,
params_buffer_bytes(hw_params));
if (ret < 0)
return ret;
mark_runtime_wc(chip, azx_dev, runtime, true);
return ret;
}
static int azx_pcm_hw_free(struct snd_pcm_substream *substream)
{
struct azx_pcm *apcm = snd_pcm_substream_chip(substream);
struct azx_dev *azx_dev = get_azx_dev(substream);
struct azx *chip = apcm->chip;
struct snd_pcm_runtime *runtime = substream->runtime;
struct hda_pcm_stream *hinfo = apcm->hinfo[substream->stream];
azx_sd_writel(azx_dev, SD_BDLPL, 0);
azx_sd_writel(azx_dev, SD_BDLPU, 0);
azx_sd_writel(azx_dev, SD_CTL, 0);
azx_dev->bufsize = 0;
azx_dev->period_bytes = 0;
azx_dev->format_val = 0;
snd_hda_codec_cleanup(apcm->codec, hinfo, substream);
mark_runtime_wc(chip, azx_dev, runtime, false);
return snd_pcm_lib_free_pages(substream);
}
static int azx_pcm_prepare(struct snd_pcm_substream *substream)
{
struct azx_pcm *apcm = snd_pcm_substream_chip(substream);
struct azx *chip = apcm->chip;
struct azx_dev *azx_dev = get_azx_dev(substream);
struct hda_pcm_stream *hinfo = apcm->hinfo[substream->stream];
struct snd_pcm_runtime *runtime = substream->runtime;
unsigned int bufsize, period_bytes, format_val, stream_tag;
int err;
struct hda_spdif_out *spdif =
snd_hda_spdif_out_of_nid(apcm->codec, hinfo->nid);
unsigned short ctls = spdif ? spdif->ctls : 0;
azx_stream_reset(chip, azx_dev);
format_val = snd_hda_calc_stream_format(runtime->rate,
runtime->channels,
runtime->format,
hinfo->maxbps,
ctls);
if (!format_val) {
snd_printk(KERN_ERR SFX
"invalid format_val, rate=%d, ch=%d, format=%d\n",
runtime->rate, runtime->channels, runtime->format);
return -EINVAL;
}
bufsize = snd_pcm_lib_buffer_bytes(substream);
period_bytes = snd_pcm_lib_period_bytes(substream);
snd_printdd(SFX "azx_pcm_prepare: bufsize=0x%x, format=0x%x\n",
bufsize, format_val);
if (bufsize != azx_dev->bufsize ||
period_bytes != azx_dev->period_bytes ||
format_val != azx_dev->format_val) {
azx_dev->bufsize = bufsize;
azx_dev->period_bytes = period_bytes;
azx_dev->format_val = format_val;
err = azx_setup_periods(chip, substream, azx_dev);
if (err < 0)
return err;
}
azx_dev->period_wallclk = (((runtime->period_size * 24000) /
runtime->rate) * 1000);
azx_setup_controller(chip, azx_dev);
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
azx_dev->fifo_size = azx_sd_readw(azx_dev, SD_FIFOSIZE) + 1;
else
azx_dev->fifo_size = 0;
stream_tag = azx_dev->stream_tag;
if ((chip->driver_caps & AZX_DCAPS_CTX_WORKAROUND) &&
stream_tag > chip->capture_streams)
stream_tag -= chip->capture_streams;
return snd_hda_codec_prepare(apcm->codec, hinfo, stream_tag,
azx_dev->format_val, substream);
}
static int azx_pcm_trigger(struct snd_pcm_substream *substream, int cmd)
{
struct azx_pcm *apcm = snd_pcm_substream_chip(substream);
struct azx *chip = apcm->chip;
struct azx_dev *azx_dev;
struct snd_pcm_substream *s;
int rstart = 0, start, nsync = 0, sbits = 0;
int nwait, timeout;
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
rstart = 1;
case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
case SNDRV_PCM_TRIGGER_RESUME:
start = 1;
break;
case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
case SNDRV_PCM_TRIGGER_SUSPEND:
case SNDRV_PCM_TRIGGER_STOP:
start = 0;
break;
default:
return -EINVAL;
}
snd_pcm_group_for_each_entry(s, substream) {
if (s->pcm->card != substream->pcm->card)
continue;
azx_dev = get_azx_dev(s);
sbits |= 1 << azx_dev->index;
nsync++;
snd_pcm_trigger_done(s, substream);
}
spin_lock(&chip->reg_lock);
if (nsync > 1) {
if (chip->driver_caps & AZX_DCAPS_OLD_SSYNC)
azx_writel(chip, OLD_SSYNC,
azx_readl(chip, OLD_SSYNC) | sbits);
else
azx_writel(chip, SSYNC, azx_readl(chip, SSYNC) | sbits);
}
snd_pcm_group_for_each_entry(s, substream) {
if (s->pcm->card != substream->pcm->card)
continue;
azx_dev = get_azx_dev(s);
if (start) {
azx_dev->start_wallclk = azx_readl(chip, WALLCLK);
if (!rstart)
azx_dev->start_wallclk -=
azx_dev->period_wallclk;
azx_stream_start(chip, azx_dev);
} else {
azx_stream_stop(chip, azx_dev);
}
azx_dev->running = start;
}
spin_unlock(&chip->reg_lock);
if (start) {
if (nsync == 1)
return 0;
for (timeout = 5000; timeout; timeout--) {
nwait = 0;
snd_pcm_group_for_each_entry(s, substream) {
if (s->pcm->card != substream->pcm->card)
continue;
azx_dev = get_azx_dev(s);
if (!(azx_sd_readb(azx_dev, SD_STS) &
SD_STS_FIFO_READY))
nwait++;
}
if (!nwait)
break;
cpu_relax();
}
} else {
for (timeout = 5000; timeout; timeout--) {
nwait = 0;
snd_pcm_group_for_each_entry(s, substream) {
if (s->pcm->card != substream->pcm->card)
continue;
azx_dev = get_azx_dev(s);
if (azx_sd_readb(azx_dev, SD_CTL) &
SD_CTL_DMA_START)
nwait++;
}
if (!nwait)
break;
cpu_relax();
}
}
if (nsync > 1) {
spin_lock(&chip->reg_lock);
if (chip->driver_caps & AZX_DCAPS_OLD_SSYNC)
azx_writel(chip, OLD_SSYNC,
azx_readl(chip, OLD_SSYNC) & ~sbits);
else
azx_writel(chip, SSYNC, azx_readl(chip, SSYNC) & ~sbits);
spin_unlock(&chip->reg_lock);
}
return 0;
}
static unsigned int azx_via_get_position(struct azx *chip,
struct azx_dev *azx_dev)
{
unsigned int link_pos, mini_pos, bound_pos;
unsigned int mod_link_pos, mod_dma_pos, mod_mini_pos;
unsigned int fifo_size;
link_pos = azx_sd_readl(azx_dev, SD_LPIB);
if (azx_dev->substream->stream == SNDRV_PCM_STREAM_PLAYBACK) {
return link_pos;
}
mod_dma_pos = le32_to_cpu(*azx_dev->posbuf);
mod_dma_pos %= azx_dev->period_bytes;
fifo_size = readw(chip->remap_addr + VIA_IN_STREAM0_FIFO_SIZE_OFFSET);
if (azx_dev->insufficient) {
if (link_pos <= fifo_size)
return 0;
azx_dev->insufficient = 0;
}
if (link_pos <= fifo_size)
mini_pos = azx_dev->bufsize + link_pos - fifo_size;
else
mini_pos = link_pos - fifo_size;
mod_mini_pos = mini_pos % azx_dev->period_bytes;
mod_link_pos = link_pos % azx_dev->period_bytes;
if (mod_link_pos >= fifo_size)
bound_pos = link_pos - mod_link_pos;
else if (mod_dma_pos >= mod_mini_pos)
bound_pos = mini_pos - mod_mini_pos;
else {
bound_pos = mini_pos - mod_mini_pos + azx_dev->period_bytes;
if (bound_pos >= azx_dev->bufsize)
bound_pos = 0;
}
return bound_pos + mod_dma_pos;
}
static unsigned int azx_get_position(struct azx *chip,
struct azx_dev *azx_dev,
bool with_check)
{
unsigned int pos;
int stream = azx_dev->substream->stream;
switch (chip->position_fix[stream]) {
case POS_FIX_LPIB:
pos = azx_sd_readl(azx_dev, SD_LPIB);
break;
case POS_FIX_VIACOMBO:
pos = azx_via_get_position(chip, azx_dev);
break;
default:
pos = le32_to_cpu(*azx_dev->posbuf);
if (with_check && chip->position_fix[stream] == POS_FIX_AUTO) {
if (!pos || pos == (u32)-1) {
printk(KERN_WARNING
"hda-intel: Invalid position buffer, "
"using LPIB read method instead.\n");
chip->position_fix[stream] = POS_FIX_LPIB;
pos = azx_sd_readl(azx_dev, SD_LPIB);
} else
chip->position_fix[stream] = POS_FIX_POSBUF;
}
break;
}
if (pos >= azx_dev->bufsize)
pos = 0;
return pos;
}
static snd_pcm_uframes_t azx_pcm_pointer(struct snd_pcm_substream *substream)
{
struct azx_pcm *apcm = snd_pcm_substream_chip(substream);
struct azx *chip = apcm->chip;
struct azx_dev *azx_dev = get_azx_dev(substream);
return bytes_to_frames(substream->runtime,
azx_get_position(chip, azx_dev, false));
}
static int azx_position_ok(struct azx *chip, struct azx_dev *azx_dev)
{
u32 wallclk;
unsigned int pos;
int stream;
wallclk = azx_readl(chip, WALLCLK) - azx_dev->start_wallclk;
if (wallclk < (azx_dev->period_wallclk * 2) / 3)
return -1;
stream = azx_dev->substream->stream;
pos = azx_get_position(chip, azx_dev, true);
if (WARN_ONCE(!azx_dev->period_bytes,
"hda-intel: zero azx_dev->period_bytes"))
return -1;
if (wallclk < (azx_dev->period_wallclk * 5) / 4 &&
pos % azx_dev->period_bytes > azx_dev->period_bytes / 2)
return bdl_pos_adj[chip->dev_index] ? 0 : -1;
azx_dev->start_wallclk += wallclk;
return 1;
}
static void azx_irq_pending_work(struct work_struct *work)
{
struct azx *chip = container_of(work, struct azx, irq_pending_work);
int i, pending, ok;
if (!chip->irq_pending_warned) {
printk(KERN_WARNING
"hda-intel: IRQ timing workaround is activated "
"for card #%d. Suggest a bigger bdl_pos_adj.\n",
chip->card->number);
chip->irq_pending_warned = 1;
}
for (;;) {
pending = 0;
spin_lock_irq(&chip->reg_lock);
for (i = 0; i < chip->num_streams; i++) {
struct azx_dev *azx_dev = &chip->azx_dev[i];
if (!azx_dev->irq_pending ||
!azx_dev->substream ||
!azx_dev->running)
continue;
ok = azx_position_ok(chip, azx_dev);
if (ok > 0) {
azx_dev->irq_pending = 0;
spin_unlock(&chip->reg_lock);
snd_pcm_period_elapsed(azx_dev->substream);
spin_lock(&chip->reg_lock);
} else if (ok < 0) {
pending = 0;
} else
pending++;
}
spin_unlock_irq(&chip->reg_lock);
if (!pending)
return;
msleep(1);
}
}
static void azx_clear_irq_pending(struct azx *chip)
{
int i;
spin_lock_irq(&chip->reg_lock);
for (i = 0; i < chip->num_streams; i++)
chip->azx_dev[i].irq_pending = 0;
spin_unlock_irq(&chip->reg_lock);
}
static int azx_pcm_mmap(struct snd_pcm_substream *substream,
struct vm_area_struct *area)
{
struct azx_pcm *apcm = snd_pcm_substream_chip(substream);
struct azx *chip = apcm->chip;
if (!azx_snoop(chip))
area->vm_page_prot = pgprot_writecombine(area->vm_page_prot);
return snd_pcm_lib_default_mmap(substream, area);
}
static void azx_pcm_free(struct snd_pcm *pcm)
{
struct azx_pcm *apcm = pcm->private_data;
if (apcm) {
list_del(&apcm->list);
kfree(apcm);
}
}
static int
azx_attach_pcm_stream(struct hda_bus *bus, struct hda_codec *codec,
struct hda_pcm *cpcm)
{
struct azx *chip = bus->private_data;
struct snd_pcm *pcm;
struct azx_pcm *apcm;
int pcm_dev = cpcm->device;
unsigned int size;
int s, err;
list_for_each_entry(apcm, &chip->pcm_list, list) {
if (apcm->pcm->device == pcm_dev) {
snd_printk(KERN_ERR SFX "PCM %d already exists\n", pcm_dev);
return -EBUSY;
}
}
err = snd_pcm_new(chip->card, cpcm->name, pcm_dev,
cpcm->stream[SNDRV_PCM_STREAM_PLAYBACK].substreams,
cpcm->stream[SNDRV_PCM_STREAM_CAPTURE].substreams,
&pcm);
if (err < 0)
return err;
strlcpy(pcm->name, cpcm->name, sizeof(pcm->name));
apcm = kzalloc(sizeof(*apcm), GFP_KERNEL);
if (apcm == NULL)
return -ENOMEM;
apcm->chip = chip;
apcm->pcm = pcm;
apcm->codec = codec;
pcm->private_data = apcm;
pcm->private_free = azx_pcm_free;
if (cpcm->pcm_type == HDA_PCM_TYPE_MODEM)
pcm->dev_class = SNDRV_PCM_CLASS_MODEM;
list_add_tail(&apcm->list, &chip->pcm_list);
cpcm->pcm = pcm;
for (s = 0; s < 2; s++) {
apcm->hinfo[s] = &cpcm->stream[s];
if (cpcm->stream[s].substreams)
snd_pcm_set_ops(pcm, s, &azx_pcm_ops);
}
size = CONFIG_SND_HDA_PREALLOC_SIZE * 1024;
if (size > MAX_PREALLOC_SIZE)
size = MAX_PREALLOC_SIZE;
snd_pcm_lib_preallocate_pages_for_all(pcm, SNDRV_DMA_TYPE_DEV_SG,
snd_dma_pci_data(chip->pci),
size, MAX_PREALLOC_SIZE);
return 0;
}
static int __devinit azx_mixer_create(struct azx *chip)
{
return snd_hda_build_controls(chip->bus);
}
static int __devinit azx_init_stream(struct azx *chip)
{
int i;
for (i = 0; i < chip->num_streams; i++) {
struct azx_dev *azx_dev = &chip->azx_dev[i];
azx_dev->posbuf = (u32 __iomem *)(chip->posbuf.area + i * 8);
azx_dev->sd_addr = chip->remap_addr + (0x20 * i + 0x80);
azx_dev->sd_int_sta_mask = 1 << i;
azx_dev->index = i;
azx_dev->stream_tag = i + 1;
}
return 0;
}
static int azx_acquire_irq(struct azx *chip, int do_disconnect)
{
if (request_irq(chip->pci->irq, azx_interrupt,
chip->msi ? 0 : IRQF_SHARED,
KBUILD_MODNAME, chip)) {
printk(KERN_ERR "hda-intel: unable to grab IRQ %d, "
"disabling device\n", chip->pci->irq);
if (do_disconnect)
snd_card_disconnect(chip->card);
return -1;
}
chip->irq = chip->pci->irq;
pci_intx(chip->pci, !chip->msi);
return 0;
}
static void azx_stop_chip(struct azx *chip)
{
if (!chip->initialized)
return;
azx_int_disable(chip);
azx_int_clear(chip);
azx_free_cmd_io(chip);
azx_writel(chip, DPLBASE, 0);
azx_writel(chip, DPUBASE, 0);
chip->initialized = 0;
}
static void azx_power_notify(struct hda_bus *bus)
{
struct azx *chip = bus->private_data;
struct hda_codec *c;
int power_on = 0;
list_for_each_entry(c, &bus->codec_list, list) {
if (c->power_on) {
power_on = 1;
break;
}
}
if (power_on)
azx_init_chip(chip, 1);
else if (chip->running && power_save_controller &&
!bus->power_keep_link_on)
azx_stop_chip(chip);
}
static int snd_hda_codecs_inuse(struct hda_bus *bus)
{
struct hda_codec *codec;
list_for_each_entry(codec, &bus->codec_list, list) {
if (snd_hda_codec_needs_resume(codec))
return 1;
}
return 0;
}
static int azx_suspend(struct pci_dev *pci, pm_message_t state)
{
struct snd_card *card = pci_get_drvdata(pci);
struct azx *chip = card->private_data;
struct azx_pcm *p;
snd_power_change_state(card, SNDRV_CTL_POWER_D3hot);
azx_clear_irq_pending(chip);
list_for_each_entry(p, &chip->pcm_list, list)
snd_pcm_suspend_all(p->pcm);
if (chip->initialized)
snd_hda_suspend(chip->bus);
azx_stop_chip(chip);
if (chip->irq >= 0) {
free_irq(chip->irq, chip);
chip->irq = -1;
}
if (chip->msi)
pci_disable_msi(chip->pci);
pci_disable_device(pci);
pci_save_state(pci);
pci_set_power_state(pci, pci_choose_state(pci, state));
return 0;
}
static int azx_resume(struct pci_dev *pci)
{
struct snd_card *card = pci_get_drvdata(pci);
struct azx *chip = card->private_data;
pci_set_power_state(pci, PCI_D0);
pci_restore_state(pci);
if (pci_enable_device(pci) < 0) {
printk(KERN_ERR "hda-intel: pci_enable_device failed, "
"disabling device\n");
snd_card_disconnect(card);
return -EIO;
}
pci_set_master(pci);
if (chip->msi)
if (pci_enable_msi(pci) < 0)
chip->msi = 0;
if (azx_acquire_irq(chip, 1) < 0)
return -EIO;
azx_init_pci(chip);
if (snd_hda_codecs_inuse(chip->bus))
azx_init_chip(chip, 1);
snd_hda_resume(chip->bus);
snd_power_change_state(card, SNDRV_CTL_POWER_D0);
return 0;
}
static int azx_halt(struct notifier_block *nb, unsigned long event, void *buf)
{
struct azx *chip = container_of(nb, struct azx, reboot_notifier);
snd_hda_bus_reboot_notify(chip->bus);
azx_stop_chip(chip);
return NOTIFY_OK;
}
static void azx_notifier_register(struct azx *chip)
{
chip->reboot_notifier.notifier_call = azx_halt;
register_reboot_notifier(&chip->reboot_notifier);
}
static void azx_notifier_unregister(struct azx *chip)
{
if (chip->reboot_notifier.notifier_call)
unregister_reboot_notifier(&chip->reboot_notifier);
}
static int azx_free(struct azx *chip)
{
int i;
azx_notifier_unregister(chip);
if (chip->initialized) {
azx_clear_irq_pending(chip);
for (i = 0; i < chip->num_streams; i++)
azx_stream_stop(chip, &chip->azx_dev[i]);
azx_stop_chip(chip);
}
if (chip->irq >= 0)
free_irq(chip->irq, (void*)chip);
if (chip->msi)
pci_disable_msi(chip->pci);
if (chip->remap_addr)
iounmap(chip->remap_addr);
if (chip->azx_dev) {
for (i = 0; i < chip->num_streams; i++)
if (chip->azx_dev[i].bdl.area) {
mark_pages_wc(chip, &chip->azx_dev[i].bdl, false);
snd_dma_free_pages(&chip->azx_dev[i].bdl);
}
}
if (chip->rb.area) {
mark_pages_wc(chip, &chip->rb, false);
snd_dma_free_pages(&chip->rb);
}
if (chip->posbuf.area) {
mark_pages_wc(chip, &chip->posbuf, false);
snd_dma_free_pages(&chip->posbuf);
}
pci_release_regions(chip->pci);
pci_disable_device(chip->pci);
kfree(chip->azx_dev);
kfree(chip);
return 0;
}
static int azx_dev_free(struct snd_device *device)
{
return azx_free(device->device_data);
}
static int __devinit check_position_fix(struct azx *chip, int fix)
{
const struct snd_pci_quirk *q;
switch (fix) {
case POS_FIX_LPIB:
case POS_FIX_POSBUF:
case POS_FIX_VIACOMBO:
return fix;
}
q = snd_pci_quirk_lookup(chip->pci, position_fix_list);
if (q) {
printk(KERN_INFO
"hda_intel: position_fix set to %d "
"for device %04x:%04x\n",
q->value, q->subvendor, q->subdevice);
return q->value;
}
if (chip->driver_caps & AZX_DCAPS_POSFIX_VIA) {
snd_printd(SFX "Using VIACOMBO position fix\n");
return POS_FIX_VIACOMBO;
}
if (chip->driver_caps & AZX_DCAPS_POSFIX_LPIB) {
snd_printd(SFX "Using LPIB position fix\n");
return POS_FIX_LPIB;
}
return POS_FIX_AUTO;
}
static void __devinit check_probe_mask(struct azx *chip, int dev)
{
const struct snd_pci_quirk *q;
chip->codec_probe_mask = probe_mask[dev];
if (chip->codec_probe_mask == -1) {
q = snd_pci_quirk_lookup(chip->pci, probe_mask_list);
if (q) {
printk(KERN_INFO
"hda_intel: probe_mask set to 0x%x "
"for device %04x:%04x\n",
q->value, q->subvendor, q->subdevice);
chip->codec_probe_mask = q->value;
}
}
if (chip->codec_probe_mask != -1 &&
(chip->codec_probe_mask & AZX_FORCE_CODEC_MASK)) {
chip->codec_mask = chip->codec_probe_mask & 0xff;
printk(KERN_INFO "hda_intel: codec_mask forced to 0x%x\n",
chip->codec_mask);
}
}
static void __devinit check_msi(struct azx *chip)
{
const struct snd_pci_quirk *q;
if (enable_msi >= 0) {
chip->msi = !!enable_msi;
return;
}
chip->msi = 1;
q = snd_pci_quirk_lookup(chip->pci, msi_black_list);
if (q) {
printk(KERN_INFO
"hda_intel: msi for device %04x:%04x set to %d\n",
q->subvendor, q->subdevice, q->value);
chip->msi = q->value;
return;
}
if (chip->driver_caps & AZX_DCAPS_NO_MSI) {
printk(KERN_INFO "hda_intel: Disabling MSI\n");
chip->msi = 0;
}
}
static void __devinit azx_check_snoop_available(struct azx *chip)
{
bool snoop = chip->snoop;
switch (chip->driver_type) {
case AZX_DRIVER_VIA:
if (snoop) {
u8 val;
pci_read_config_byte(chip->pci, 0x42, &val);
if (!(val & 0x80) && chip->pci->revision == 0x30)
snoop = false;
}
break;
case AZX_DRIVER_ATIHDMI_NS:
snoop = false;
break;
}
if (snoop != chip->snoop) {
snd_printk(KERN_INFO SFX "Force to %s mode\n",
snoop ? "snoop" : "non-snoop");
chip->snoop = snoop;
}
}
static int __devinit azx_create(struct snd_card *card, struct pci_dev *pci,
int dev, unsigned int driver_caps,
struct azx **rchip)
{
struct azx *chip;
int i, err;
unsigned short gcap;
static struct snd_device_ops ops = {
.dev_free = azx_dev_free,
};
*rchip = NULL;
err = pci_enable_device(pci);
if (err < 0)
return err;
chip = kzalloc(sizeof(*chip), GFP_KERNEL);
if (!chip) {
snd_printk(KERN_ERR SFX "cannot allocate chip\n");
pci_disable_device(pci);
return -ENOMEM;
}
spin_lock_init(&chip->reg_lock);
mutex_init(&chip->open_mutex);
chip->card = card;
chip->pci = pci;
chip->irq = -1;
chip->driver_caps = driver_caps;
chip->driver_type = driver_caps & 0xff;
check_msi(chip);
chip->dev_index = dev;
INIT_WORK(&chip->irq_pending_work, azx_irq_pending_work);
INIT_LIST_HEAD(&chip->pcm_list);
chip->position_fix[0] = chip->position_fix[1] =
check_position_fix(chip, position_fix[dev]);
check_probe_mask(chip, dev);
chip->single_cmd = single_cmd;
chip->snoop = hda_snoop;
azx_check_snoop_available(chip);
if (bdl_pos_adj[dev] < 0) {
switch (chip->driver_type) {
case AZX_DRIVER_ICH:
case AZX_DRIVER_PCH:
bdl_pos_adj[dev] = 1;
break;
default:
bdl_pos_adj[dev] = 32;
break;
}
}
#if BITS_PER_LONG != 64
if (chip->driver_type == AZX_DRIVER_ULI) {
u16 tmp3;
pci_read_config_word(pci, 0x40, &tmp3);
pci_write_config_word(pci, 0x40, tmp3 | 0x10);
pci_write_config_dword(pci, PCI_BASE_ADDRESS_1, 0);
}
#endif
err = pci_request_regions(pci, "ICH HD audio");
if (err < 0) {
kfree(chip);
pci_disable_device(pci);
return err;
}
chip->addr = pci_resource_start(pci, 0);
chip->remap_addr = pci_ioremap_bar(pci, 0);
if (chip->remap_addr == NULL) {
snd_printk(KERN_ERR SFX "ioremap error\n");
err = -ENXIO;
goto errout;
}
if (chip->msi)
if (pci_enable_msi(pci) < 0)
chip->msi = 0;
if (azx_acquire_irq(chip, 0) < 0) {
err = -EBUSY;
goto errout;
}
pci_set_master(pci);
synchronize_irq(chip->irq);
gcap = azx_readw(chip, GCAP);
snd_printdd(SFX "chipset global capabilities = 0x%x\n", gcap);
if (chip->pci->vendor == PCI_VENDOR_ID_ATI) {
struct pci_dev *p_smbus;
p_smbus = pci_get_device(PCI_VENDOR_ID_ATI,
PCI_DEVICE_ID_ATI_SBX00_SMBUS,
NULL);
if (p_smbus) {
if (p_smbus->revision < 0x30)
gcap &= ~ICH6_GCAP_64OK;
pci_dev_put(p_smbus);
}
}
if (chip->driver_caps & AZX_DCAPS_NO_64BIT) {
snd_printd(SFX "Disabling 64bit DMA\n");
gcap &= ~ICH6_GCAP_64OK;
}
chip->align_buffer_size = align_buffer_size;
if (chip->driver_caps & AZX_DCAPS_BUFSIZE)
chip->align_buffer_size = 0;
if ((gcap & ICH6_GCAP_64OK) && !pci_set_dma_mask(pci, DMA_BIT_MASK(64)))
pci_set_consistent_dma_mask(pci, DMA_BIT_MASK(64));
else {
pci_set_dma_mask(pci, DMA_BIT_MASK(32));
pci_set_consistent_dma_mask(pci, DMA_BIT_MASK(32));
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
chip->azx_dev = kcalloc(chip->num_streams, sizeof(*chip->azx_dev),
GFP_KERNEL);
if (!chip->azx_dev) {
snd_printk(KERN_ERR SFX "cannot malloc azx_dev\n");
goto errout;
}
for (i = 0; i < chip->num_streams; i++) {
err = snd_dma_alloc_pages(SNDRV_DMA_TYPE_DEV,
snd_dma_pci_data(chip->pci),
BDL_SIZE, &chip->azx_dev[i].bdl);
if (err < 0) {
snd_printk(KERN_ERR SFX "cannot allocate BDL\n");
goto errout;
}
mark_pages_wc(chip, &chip->azx_dev[i].bdl, true);
}
err = snd_dma_alloc_pages(SNDRV_DMA_TYPE_DEV,
snd_dma_pci_data(chip->pci),
chip->num_streams * 8, &chip->posbuf);
if (err < 0) {
snd_printk(KERN_ERR SFX "cannot allocate posbuf\n");
goto errout;
}
mark_pages_wc(chip, &chip->posbuf, true);
err = azx_alloc_cmd_io(chip);
if (err < 0)
goto errout;
azx_init_stream(chip);
azx_init_pci(chip);
azx_init_chip(chip, (probe_only[dev] & 2) == 0);
if (!chip->codec_mask) {
snd_printk(KERN_ERR SFX "no codecs found!\n");
err = -ENODEV;
goto errout;
}
err = snd_device_new(card, SNDRV_DEV_LOWLEVEL, chip, &ops);
if (err <0) {
snd_printk(KERN_ERR SFX "Error creating device [card]!\n");
goto errout;
}
strcpy(card->driver, "HDA-Intel");
strlcpy(card->shortname, driver_short_names[chip->driver_type],
sizeof(card->shortname));
snprintf(card->longname, sizeof(card->longname),
"%s at 0x%lx irq %i",
card->shortname, chip->addr, chip->irq);
*rchip = chip;
return 0;
errout:
azx_free(chip);
return err;
}
static void power_down_all_codecs(struct azx *chip)
{
#ifdef CONFIG_SND_HDA_POWER_SAVE
struct hda_codec *codec;
list_for_each_entry(codec, &chip->bus->codec_list, list) {
snd_hda_power_down(codec);
}
#endif
}
static int __devinit azx_probe(struct pci_dev *pci,
const struct pci_device_id *pci_id)
{
static int dev;
struct snd_card *card;
struct azx *chip;
int err;
if (dev >= SNDRV_CARDS)
return -ENODEV;
if (!enable[dev]) {
dev++;
return -ENOENT;
}
err = snd_card_create(index[dev], id[dev], THIS_MODULE, 0, &card);
if (err < 0) {
snd_printk(KERN_ERR SFX "Error creating card!\n");
return err;
}
snd_card_set_dev(card, &pci->dev);
err = azx_create(card, pci, dev, pci_id->driver_data, &chip);
if (err < 0)
goto out_free;
card->private_data = chip;
#ifdef CONFIG_SND_HDA_INPUT_BEEP
chip->beep_mode = beep_mode[dev];
#endif
err = azx_codec_create(chip, model[dev]);
if (err < 0)
goto out_free;
#ifdef CONFIG_SND_HDA_PATCH_LOADER
if (patch[dev] && *patch[dev]) {
snd_printk(KERN_ERR SFX "Applying patch firmware '%s'\n",
patch[dev]);
err = snd_hda_load_patch(chip->bus, patch[dev]);
if (err < 0)
goto out_free;
}
#endif
if ((probe_only[dev] & 1) == 0) {
err = azx_codec_configure(chip);
if (err < 0)
goto out_free;
}
err = snd_hda_build_pcms(chip->bus);
if (err < 0)
goto out_free;
err = azx_mixer_create(chip);
if (err < 0)
goto out_free;
err = snd_card_register(card);
if (err < 0)
goto out_free;
pci_set_drvdata(pci, card);
chip->running = 1;
power_down_all_codecs(chip);
azx_notifier_register(chip);
dev++;
return err;
out_free:
snd_card_free(card);
return err;
}
static void __devexit azx_remove(struct pci_dev *pci)
{
snd_card_free(pci_get_drvdata(pci));
pci_set_drvdata(pci, NULL);
}
static int __init alsa_card_azx_init(void)
{
return pci_register_driver(&driver);
}
static void __exit alsa_card_azx_exit(void)
{
pci_unregister_driver(&driver);
}
