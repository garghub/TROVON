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
static int azx_alloc_cmd_io(struct azx *chip)
{
int err;
err = snd_dma_alloc_pages(SNDRV_DMA_TYPE_DEV,
snd_dma_pci_data(chip->pci),
PAGE_SIZE, &chip->rb);
if (err < 0) {
snd_printk(KERN_ERR SFX "%s: cannot allocate CORB/RIRB\n", pci_name(chip->pci));
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
unsigned int wp, rp;
spin_lock_irq(&chip->reg_lock);
wp = azx_readw(chip, CORBWP);
if (wp == 0xffff) {
spin_unlock_irq(&chip->reg_lock);
return -EIO;
}
wp++;
wp %= ICH6_MAX_CORB_ENTRIES;
rp = azx_readw(chip, CORBRP);
if (wp == rp) {
spin_unlock_irq(&chip->reg_lock);
return -EAGAIN;
}
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
wp = azx_readw(chip, RIRBWP);
if (wp == 0xffff) {
return;
}
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
snd_printk(KERN_ERR SFX "%s: spurious response %#x:%#x, "
"last cmd=%#08x\n",
pci_name(chip->pci),
res, res_ex,
chip->last_cmd[addr]);
}
}
static unsigned int azx_rirb_get_response(struct hda_bus *bus,
unsigned int addr)
{
struct azx *chip = bus->private_data;
unsigned long timeout;
unsigned long loopcounter;
int do_poll = 0;
again:
timeout = jiffies + msecs_to_jiffies(1000);
for (loopcounter = 0;; loopcounter++) {
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
if (bus->needs_damn_long_delay || loopcounter > 3000)
msleep(2);
else {
udelay(10);
cond_resched();
}
}
if (!bus->no_response_fallback)
return -1;
if (!chip->polling_mode && chip->poll_count < 2) {
snd_printdd(SFX "%s: azx_get_response timeout, "
"polling the codec once: last cmd=0x%08x\n",
pci_name(chip->pci), chip->last_cmd[addr]);
do_poll = 1;
chip->poll_count++;
goto again;
}
if (!chip->polling_mode) {
snd_printk(KERN_WARNING SFX "%s: azx_get_response timeout, "
"switching to polling mode: last cmd=0x%08x\n",
pci_name(chip->pci), chip->last_cmd[addr]);
chip->polling_mode = 1;
goto again;
}
if (chip->msi) {
snd_printk(KERN_WARNING SFX "%s: No response from codec, "
"disabling MSI: last cmd=0x%08x\n",
pci_name(chip->pci), chip->last_cmd[addr]);
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
snd_printd(SFX "%s: get_response timeout: IRS=0x%x\n",
pci_name(chip->pci), azx_readw(chip, IRS));
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
snd_printd(SFX "%s: send_cmd timeout: IRS=0x%x, val=0x%x\n",
pci_name(chip->pci), azx_readw(chip, IRS), val);
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
if (chip->disabled)
return 0;
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
if (chip->disabled)
return 0;
if (chip->single_cmd)
return azx_single_get_response(bus, addr);
else
return azx_rirb_get_response(bus, addr);
}
static void azx_enter_link_reset(struct azx *chip)
{
unsigned long timeout;
azx_writel(chip, GCTL, azx_readl(chip, GCTL) & ~ICH6_GCTL_RESET);
timeout = jiffies + msecs_to_jiffies(100);
while ((azx_readb(chip, GCTL) & ICH6_GCTL_RESET) &&
time_before(jiffies, timeout))
usleep_range(500, 1000);
}
static void azx_exit_link_reset(struct azx *chip)
{
unsigned long timeout;
azx_writeb(chip, GCTL, azx_readb(chip, GCTL) | ICH6_GCTL_RESET);
timeout = jiffies + msecs_to_jiffies(100);
while (!azx_readb(chip, GCTL) &&
time_before(jiffies, timeout))
usleep_range(500, 1000);
}
static int azx_reset(struct azx *chip, int full_reset)
{
if (!full_reset)
goto __skip;
azx_writew(chip, STATESTS, STATESTS_INT_MASK);
azx_enter_link_reset(chip);
usleep_range(500, 1000);
azx_exit_link_reset(chip);
usleep_range(1000, 1200);
__skip:
if (!azx_readb(chip, GCTL)) {
snd_printd(SFX "%s: azx_reset: controller not ready!\n", pci_name(chip->pci));
return -EBUSY;
}
if (!chip->single_cmd)
azx_writel(chip, GCTL, azx_readl(chip, GCTL) |
ICH6_GCTL_UNSOL);
if (!chip->codec_mask) {
chip->codec_mask = azx_readw(chip, STATESTS);
snd_printdd(SFX "%s: codec_mask = 0x%x\n", pci_name(chip->pci), chip->codec_mask);
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
azx_writew(chip, STATESTS, STATESTS_INT_MASK);
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
snd_printdd(SFX "%s: Clearing TCSEL\n", pci_name(chip->pci));
update_pci_byte(chip->pci, ICH6_PCIREG_TCSEL, 0x07, 0);
}
if (chip->driver_caps & AZX_DCAPS_ATI_SNOOP) {
snd_printdd(SFX "%s: Setting ATI snoop: %d\n", pci_name(chip->pci), azx_snoop(chip));
update_pci_byte(chip->pci,
ATI_SB450_HDAUDIO_MISC_CNTR2_ADDR, 0x07,
azx_snoop(chip) ? ATI_SB450_HDAUDIO_ENABLE_SNOOP : 0);
}
if (chip->driver_caps & AZX_DCAPS_NVIDIA_SNOOP) {
snd_printdd(SFX "%s: Setting Nvidia snoop: %d\n", pci_name(chip->pci), azx_snoop(chip));
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
snd_printdd(SFX "%s: SCH snoop: %s\n",
pci_name(chip->pci), (snoop & INTEL_SCH_HDA_DEVC_NOSNOOP)
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
#ifdef CONFIG_PM_RUNTIME
if (chip->driver_caps & AZX_DCAPS_PM_RUNTIME)
if (chip->pci->dev.power.runtime_status != RPM_ACTIVE)
return IRQ_NONE;
#endif
spin_lock(&chip->reg_lock);
if (chip->disabled) {
spin_unlock(&chip->reg_lock);
return IRQ_NONE;
}
status = azx_readl(chip, INTSTS);
if (status == 0 || status == 0xffffffff) {
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
if (azx_readw(chip, STATESTS) & 0x04)
azx_writew(chip, STATESTS, 0x04);
#endif
spin_unlock(&chip->reg_lock);
return IRQ_HANDLED;
}
static int setup_bdle(struct azx *chip,
struct snd_dma_buffer *dmab,
struct azx_dev *azx_dev, u32 **bdlp,
int ofs, int size, int with_ioc)
{
u32 *bdl = *bdlp;
while (size > 0) {
dma_addr_t addr;
int chunk;
if (azx_dev->frags >= AZX_MAX_BDL_ENTRIES)
return -EINVAL;
addr = snd_sgbuf_get_addr(dmab, ofs);
bdl[0] = cpu_to_le32((u32)addr);
bdl[1] = cpu_to_le32(upper_32_bits(addr));
chunk = snd_sgbuf_get_chunk_size(dmab, ofs, size);
if (chip->driver_caps & AZX_DCAPS_4K_BDLE_BOUNDARY) {
u32 remain = 0x1000 - (ofs & 0xfff);
if (chunk > remain)
chunk = remain;
}
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
if (!azx_dev->no_period_wakeup && pos_adj > 0) {
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
snd_printk(KERN_WARNING SFX "%s: Too big adjustment %d\n",
pci_name(chip->pci), bdl_pos_adj[chip->dev_index]);
pos_adj = 0;
} else {
ofs = setup_bdle(chip, snd_pcm_get_dma_buf(substream),
azx_dev,
&bdl, ofs, pos_adj, true);
if (ofs < 0)
goto error;
}
} else
pos_adj = 0;
for (i = 0; i < periods; i++) {
if (i == periods - 1 && pos_adj)
ofs = setup_bdle(chip, snd_pcm_get_dma_buf(substream),
azx_dev, &bdl, ofs,
period_bytes - pos_adj, 0);
else
ofs = setup_bdle(chip, snd_pcm_get_dma_buf(substream),
azx_dev, &bdl, ofs,
period_bytes,
!azx_dev->no_period_wakeup);
if (ofs < 0)
goto error;
}
return 0;
error:
snd_printk(KERN_ERR SFX "%s: Too many BDL entries: buffer=%d, period=%d\n",
pci_name(chip->pci), azx_dev->bufsize, period_bytes);
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
snd_printdd(SFX "%s: codec #%d probed OK\n", pci_name(chip->pci), addr);
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
static int get_jackpoll_interval(struct azx *chip)
{
int i = jackpoll_ms[chip->dev_index];
unsigned int j;
if (i == 0)
return 0;
if (i < 50 || i > 60000)
j = 0;
else
j = msecs_to_jiffies(i);
if (j == 0)
snd_printk(KERN_WARNING SFX
"jackpoll_ms value out of range: %d\n", i);
return j;
}
static int azx_codec_create(struct azx *chip, const char *model)
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
#ifdef CONFIG_PM
bus_temp.power_save = &power_save;
bus_temp.ops.pm_notify = azx_power_notify;
#endif
#ifdef CONFIG_SND_HDA_DSP_LOADER
bus_temp.ops.load_dsp_prepare = azx_load_dsp_prepare;
bus_temp.ops.load_dsp_trigger = azx_load_dsp_trigger;
bus_temp.ops.load_dsp_cleanup = azx_load_dsp_cleanup;
#endif
err = snd_hda_bus_new(chip->card, &bus_temp, &chip->bus);
if (err < 0)
return err;
if (chip->driver_caps & AZX_DCAPS_RIRB_DELAY) {
snd_printd(SFX "%s: Enable delay in RIRB handling\n", pci_name(chip->pci));
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
"%s: Codec #%d probe error; "
"disabling it...\n", pci_name(chip->pci), c);
chip->codec_mask &= ~(1 << c);
azx_stop_chip(chip);
azx_init_chip(chip, 1);
}
}
}
if (chip->driver_caps & AZX_DCAPS_SYNC_WRITE) {
snd_printd(SFX "%s: Enable sync_write for stable communication\n",
pci_name(chip->pci));
chip->bus->sync_write = 1;
chip->bus->allow_bus_reset = 1;
}
for (c = 0; c < max_slots; c++) {
if ((chip->codec_mask & (1 << c)) & chip->codec_probe_mask) {
struct hda_codec *codec;
err = snd_hda_codec_new(chip->bus, c, &codec);
if (err < 0)
continue;
codec->jackpoll_interval = get_jackpoll_interval(chip);
codec->beep_mode = chip->beep_mode;
codecs++;
}
}
if (!codecs) {
snd_printk(KERN_ERR SFX "%s: no codecs initialized\n", pci_name(chip->pci));
return -ENXIO;
}
return 0;
}
static int azx_codec_configure(struct azx *chip)
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
for (i = 0; i < nums; i++, dev++) {
struct azx_dev *azx_dev = &chip->azx_dev[dev];
dsp_lock(azx_dev);
if (!azx_dev->opened && !dsp_is_locked(azx_dev)) {
res = azx_dev;
if (res->assigned_key == key) {
res->opened = 1;
res->assigned_key = key;
dsp_unlock(azx_dev);
return azx_dev;
}
}
dsp_unlock(azx_dev);
}
if (res) {
dsp_lock(res);
res->opened = 1;
res->assigned_key = key;
dsp_unlock(res);
}
return res;
}
static inline void azx_release_device(struct azx_dev *azx_dev)
{
azx_dev->opened = 0;
}
static cycle_t azx_cc_read(const struct cyclecounter *cc)
{
struct azx_dev *azx_dev = container_of(cc, struct azx_dev, azx_cc);
struct snd_pcm_substream *substream = azx_dev->substream;
struct azx_pcm *apcm = snd_pcm_substream_chip(substream);
struct azx *chip = apcm->chip;
return azx_readl(chip, WALLCLK);
}
static void azx_timecounter_init(struct snd_pcm_substream *substream,
bool force, cycle_t last)
{
struct azx_dev *azx_dev = get_azx_dev(substream);
struct timecounter *tc = &azx_dev->azx_tc;
struct cyclecounter *cc = &azx_dev->azx_cc;
u64 nsec;
cc->read = azx_cc_read;
cc->mask = CLOCKSOURCE_MASK(32);
cc->mult = 125;
cc->shift = 0;
nsec = 0;
timecounter_init(tc, cc, nsec);
if (force)
tc->cycle_last = last;
}
static u64 azx_adjust_codec_delay(struct snd_pcm_substream *substream,
u64 nsec)
{
struct azx_pcm *apcm = snd_pcm_substream_chip(substream);
struct hda_pcm_stream *hinfo = apcm->hinfo[substream->stream];
u64 codec_frames, codec_nsecs;
if (!hinfo->ops.get_delay)
return nsec;
codec_frames = hinfo->ops.get_delay(hinfo, apcm->codec, substream);
codec_nsecs = div_u64(codec_frames * 1000000000LL,
substream->runtime->rate);
if (substream->stream == SNDRV_PCM_STREAM_CAPTURE)
return nsec + codec_nsecs;
return (nsec > codec_nsecs) ? nsec - codec_nsecs : 0;
}
static int azx_get_wallclock_tstamp(struct snd_pcm_substream *substream,
struct timespec *ts)
{
struct azx_dev *azx_dev = get_azx_dev(substream);
u64 nsec;
nsec = timecounter_read(&azx_dev->azx_tc);
nsec = div_u64(nsec, 3);
nsec = azx_adjust_codec_delay(substream, nsec);
*ts = ns_to_timespec(nsec);
return 0;
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
snd_pcm_hw_constraint_minmax(runtime, SNDRV_PCM_HW_PARAM_BUFFER_TIME,
20,
178000000);
if (chip->align_buffer_size)
buff_step = 128;
else
buff_step = 4;
snd_pcm_hw_constraint_step(runtime, 0, SNDRV_PCM_HW_PARAM_BUFFER_BYTES,
buff_step);
snd_pcm_hw_constraint_step(runtime, 0, SNDRV_PCM_HW_PARAM_PERIOD_BYTES,
buff_step);
snd_hda_power_up_d3wait(apcm->codec);
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
if (substream->stream == SNDRV_PCM_STREAM_CAPTURE)
runtime->hw.info &= ~SNDRV_PCM_INFO_HAS_WALL_CLOCK;
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
struct azx_dev *azx_dev = get_azx_dev(substream);
int ret;
dsp_lock(azx_dev);
if (dsp_is_locked(azx_dev)) {
ret = -EBUSY;
goto unlock;
}
mark_runtime_wc(chip, azx_dev, substream, false);
azx_dev->bufsize = 0;
azx_dev->period_bytes = 0;
azx_dev->format_val = 0;
ret = snd_pcm_lib_malloc_pages(substream,
params_buffer_bytes(hw_params));
if (ret < 0)
goto unlock;
mark_runtime_wc(chip, azx_dev, substream, true);
unlock:
dsp_unlock(azx_dev);
return ret;
}
static int azx_pcm_hw_free(struct snd_pcm_substream *substream)
{
struct azx_pcm *apcm = snd_pcm_substream_chip(substream);
struct azx_dev *azx_dev = get_azx_dev(substream);
struct azx *chip = apcm->chip;
struct hda_pcm_stream *hinfo = apcm->hinfo[substream->stream];
dsp_lock(azx_dev);
if (!dsp_is_locked(azx_dev)) {
azx_sd_writel(azx_dev, SD_BDLPL, 0);
azx_sd_writel(azx_dev, SD_BDLPU, 0);
azx_sd_writel(azx_dev, SD_CTL, 0);
azx_dev->bufsize = 0;
azx_dev->period_bytes = 0;
azx_dev->format_val = 0;
}
snd_hda_codec_cleanup(apcm->codec, hinfo, substream);
mark_runtime_wc(chip, azx_dev, substream, false);
azx_dev->prepared = 0;
dsp_unlock(azx_dev);
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
dsp_lock(azx_dev);
if (dsp_is_locked(azx_dev)) {
err = -EBUSY;
goto unlock;
}
azx_stream_reset(chip, azx_dev);
format_val = snd_hda_calc_stream_format(runtime->rate,
runtime->channels,
runtime->format,
hinfo->maxbps,
ctls);
if (!format_val) {
snd_printk(KERN_ERR SFX
"%s: invalid format_val, rate=%d, ch=%d, format=%d\n",
pci_name(chip->pci), runtime->rate, runtime->channels, runtime->format);
err = -EINVAL;
goto unlock;
}
bufsize = snd_pcm_lib_buffer_bytes(substream);
period_bytes = snd_pcm_lib_period_bytes(substream);
snd_printdd(SFX "%s: azx_pcm_prepare: bufsize=0x%x, format=0x%x\n",
pci_name(chip->pci), bufsize, format_val);
if (bufsize != azx_dev->bufsize ||
period_bytes != azx_dev->period_bytes ||
format_val != azx_dev->format_val ||
runtime->no_period_wakeup != azx_dev->no_period_wakeup) {
azx_dev->bufsize = bufsize;
azx_dev->period_bytes = period_bytes;
azx_dev->format_val = format_val;
azx_dev->no_period_wakeup = runtime->no_period_wakeup;
err = azx_setup_periods(chip, substream, azx_dev);
if (err < 0)
goto unlock;
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
err = snd_hda_codec_prepare(apcm->codec, hinfo, stream_tag,
azx_dev->format_val, substream);
unlock:
if (!err)
azx_dev->prepared = 1;
dsp_unlock(azx_dev);
return err;
}
static int azx_pcm_trigger(struct snd_pcm_substream *substream, int cmd)
{
struct azx_pcm *apcm = snd_pcm_substream_chip(substream);
struct azx *chip = apcm->chip;
struct azx_dev *azx_dev;
struct snd_pcm_substream *s;
int rstart = 0, start, nsync = 0, sbits = 0;
int nwait, timeout;
azx_dev = get_azx_dev(substream);
trace_azx_pcm_trigger(chip, azx_dev, cmd);
if (dsp_is_locked(azx_dev) || !azx_dev->prepared)
return -EPIPE;
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
if (chip->driver_caps & AZX_DCAPS_OLD_SSYNC)
azx_writel(chip, OLD_SSYNC,
azx_readl(chip, OLD_SSYNC) | sbits);
else
azx_writel(chip, SSYNC, azx_readl(chip, SSYNC) | sbits);
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
spin_lock(&chip->reg_lock);
if (chip->driver_caps & AZX_DCAPS_OLD_SSYNC)
azx_writel(chip, OLD_SSYNC,
azx_readl(chip, OLD_SSYNC) & ~sbits);
else
azx_writel(chip, SSYNC, azx_readl(chip, SSYNC) & ~sbits);
if (start) {
azx_timecounter_init(substream, 0, 0);
if (nsync > 1) {
cycle_t cycle_last;
azx_dev = get_azx_dev(substream);
cycle_last = azx_dev->azx_tc.cycle_last;
snd_pcm_group_for_each_entry(s, substream) {
if (s->pcm->card != substream->pcm->card)
continue;
azx_timecounter_init(s, 1, cycle_last);
}
}
}
spin_unlock(&chip->reg_lock);
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
struct snd_pcm_substream *substream = azx_dev->substream;
struct azx_pcm *apcm = snd_pcm_substream_chip(substream);
unsigned int pos;
int stream = substream->stream;
struct hda_pcm_stream *hinfo = apcm->hinfo[stream];
int delay = 0;
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
if (substream->runtime &&
chip->position_fix[stream] == POS_FIX_POSBUF &&
(chip->driver_caps & AZX_DCAPS_COUNT_LPIB_DELAY)) {
unsigned int lpib_pos = azx_sd_readl(azx_dev, SD_LPIB);
if (stream == SNDRV_PCM_STREAM_PLAYBACK)
delay = pos - lpib_pos;
else
delay = lpib_pos - pos;
if (delay < 0)
delay += azx_dev->bufsize;
if (delay >= azx_dev->period_bytes) {
snd_printk(KERN_WARNING SFX
"%s: Unstable LPIB (%d >= %d); "
"disabling LPIB delay counting\n",
pci_name(chip->pci), delay, azx_dev->period_bytes);
delay = 0;
chip->driver_caps &= ~AZX_DCAPS_COUNT_LPIB_DELAY;
}
delay = bytes_to_frames(substream->runtime, delay);
}
if (substream->runtime) {
if (hinfo->ops.get_delay)
delay += hinfo->ops.get_delay(hinfo, apcm->codec,
substream);
substream->runtime->delay = delay;
}
trace_azx_get_position(chip, azx_dev, pos, delay);
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
wallclk = azx_readl(chip, WALLCLK) - azx_dev->start_wallclk;
if (wallclk < (azx_dev->period_wallclk * 2) / 3)
return -1;
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
snd_printk(KERN_ERR SFX "%s: PCM %d already exists\n",
pci_name(chip->pci), pcm_dev);
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
static int azx_mixer_create(struct azx *chip)
{
return snd_hda_build_controls(chip->bus);
}
static int azx_init_stream(struct azx *chip)
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
static struct azx_dev *
azx_get_dsp_loader_dev(struct azx *chip)
{
return &chip->azx_dev[chip->playback_index_offset];
}
static int azx_load_dsp_prepare(struct hda_bus *bus, unsigned int format,
unsigned int byte_size,
struct snd_dma_buffer *bufp)
{
u32 *bdl;
struct azx *chip = bus->private_data;
struct azx_dev *azx_dev;
int err;
azx_dev = azx_get_dsp_loader_dev(chip);
dsp_lock(azx_dev);
spin_lock_irq(&chip->reg_lock);
if (azx_dev->running || azx_dev->locked) {
spin_unlock_irq(&chip->reg_lock);
err = -EBUSY;
goto unlock;
}
azx_dev->prepared = 0;
chip->saved_azx_dev = *azx_dev;
azx_dev->locked = 1;
spin_unlock_irq(&chip->reg_lock);
err = snd_dma_alloc_pages(SNDRV_DMA_TYPE_DEV_SG,
snd_dma_pci_data(chip->pci),
byte_size, bufp);
if (err < 0)
goto err_alloc;
mark_pages_wc(chip, bufp, true);
azx_dev->bufsize = byte_size;
azx_dev->period_bytes = byte_size;
azx_dev->format_val = format;
azx_stream_reset(chip, azx_dev);
azx_sd_writel(azx_dev, SD_BDLPL, 0);
azx_sd_writel(azx_dev, SD_BDLPU, 0);
azx_dev->frags = 0;
bdl = (u32 *)azx_dev->bdl.area;
err = setup_bdle(chip, bufp, azx_dev, &bdl, 0, byte_size, 0);
if (err < 0)
goto error;
azx_setup_controller(chip, azx_dev);
dsp_unlock(azx_dev);
return azx_dev->stream_tag;
error:
mark_pages_wc(chip, bufp, false);
snd_dma_free_pages(bufp);
err_alloc:
spin_lock_irq(&chip->reg_lock);
if (azx_dev->opened)
*azx_dev = chip->saved_azx_dev;
azx_dev->locked = 0;
spin_unlock_irq(&chip->reg_lock);
unlock:
dsp_unlock(azx_dev);
return err;
}
static void azx_load_dsp_trigger(struct hda_bus *bus, bool start)
{
struct azx *chip = bus->private_data;
struct azx_dev *azx_dev = azx_get_dsp_loader_dev(chip);
if (start)
azx_stream_start(chip, azx_dev);
else
azx_stream_stop(chip, azx_dev);
azx_dev->running = start;
}
static void azx_load_dsp_cleanup(struct hda_bus *bus,
struct snd_dma_buffer *dmab)
{
struct azx *chip = bus->private_data;
struct azx_dev *azx_dev = azx_get_dsp_loader_dev(chip);
if (!dmab->area || !azx_dev->locked)
return;
dsp_lock(azx_dev);
azx_sd_writel(azx_dev, SD_BDLPL, 0);
azx_sd_writel(azx_dev, SD_BDLPU, 0);
azx_sd_writel(azx_dev, SD_CTL, 0);
azx_dev->bufsize = 0;
azx_dev->period_bytes = 0;
azx_dev->format_val = 0;
mark_pages_wc(chip, dmab, false);
snd_dma_free_pages(dmab);
dmab->area = NULL;
spin_lock_irq(&chip->reg_lock);
if (azx_dev->opened)
*azx_dev = chip->saved_azx_dev;
azx_dev->locked = 0;
spin_unlock_irq(&chip->reg_lock);
dsp_unlock(azx_dev);
}
static void azx_power_notify(struct hda_bus *bus, bool power_up)
{
struct azx *chip = bus->private_data;
if (!(chip->driver_caps & AZX_DCAPS_PM_RUNTIME))
return;
if (power_up)
pm_runtime_get_sync(&chip->pci->dev);
else
pm_runtime_put_sync(&chip->pci->dev);
}
static void azx_add_card_list(struct azx *chip)
{
mutex_lock(&card_list_lock);
list_add(&chip->list, &card_list);
mutex_unlock(&card_list_lock);
}
static void azx_del_card_list(struct azx *chip)
{
mutex_lock(&card_list_lock);
list_del_init(&chip->list);
mutex_unlock(&card_list_lock);
}
static int param_set_xint(const char *val, const struct kernel_param *kp)
{
struct azx *chip;
struct hda_codec *c;
int prev = power_save;
int ret = param_set_int(val, kp);
if (ret || prev == power_save)
return ret;
mutex_lock(&card_list_lock);
list_for_each_entry(chip, &card_list, list) {
if (!chip->bus || chip->disabled)
continue;
list_for_each_entry(c, &chip->bus->codec_list, list)
snd_hda_power_sync(c);
}
mutex_unlock(&card_list_lock);
return 0;
}
static int azx_suspend(struct device *dev)
{
struct pci_dev *pci = to_pci_dev(dev);
struct snd_card *card = dev_get_drvdata(dev);
struct azx *chip = card->private_data;
struct azx_pcm *p;
if (chip->disabled)
return 0;
snd_power_change_state(card, SNDRV_CTL_POWER_D3hot);
azx_clear_irq_pending(chip);
list_for_each_entry(p, &chip->pcm_list, list)
snd_pcm_suspend_all(p->pcm);
if (chip->initialized)
snd_hda_suspend(chip->bus);
azx_stop_chip(chip);
azx_enter_link_reset(chip);
if (chip->irq >= 0) {
free_irq(chip->irq, chip);
chip->irq = -1;
}
if (chip->msi)
pci_disable_msi(chip->pci);
pci_disable_device(pci);
pci_save_state(pci);
pci_set_power_state(pci, PCI_D3hot);
if (chip->driver_caps & AZX_DCAPS_I915_POWERWELL)
hda_display_power(false);
return 0;
}
static int azx_resume(struct device *dev)
{
struct pci_dev *pci = to_pci_dev(dev);
struct snd_card *card = dev_get_drvdata(dev);
struct azx *chip = card->private_data;
if (chip->disabled)
return 0;
if (chip->driver_caps & AZX_DCAPS_I915_POWERWELL)
hda_display_power(true);
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
azx_init_chip(chip, 1);
snd_hda_resume(chip->bus);
snd_power_change_state(card, SNDRV_CTL_POWER_D0);
return 0;
}
static int azx_runtime_suspend(struct device *dev)
{
struct snd_card *card = dev_get_drvdata(dev);
struct azx *chip = card->private_data;
if (chip->disabled)
return 0;
if (!(chip->driver_caps & AZX_DCAPS_PM_RUNTIME))
return 0;
azx_writew(chip, WAKEEN, azx_readw(chip, WAKEEN) |
STATESTS_INT_MASK);
azx_stop_chip(chip);
azx_enter_link_reset(chip);
azx_clear_irq_pending(chip);
if (chip->driver_caps & AZX_DCAPS_I915_POWERWELL)
hda_display_power(false);
return 0;
}
static int azx_runtime_resume(struct device *dev)
{
struct snd_card *card = dev_get_drvdata(dev);
struct azx *chip = card->private_data;
struct hda_bus *bus;
struct hda_codec *codec;
int status;
if (chip->disabled)
return 0;
if (!(chip->driver_caps & AZX_DCAPS_PM_RUNTIME))
return 0;
if (chip->driver_caps & AZX_DCAPS_I915_POWERWELL)
hda_display_power(true);
status = azx_readw(chip, STATESTS);
azx_init_pci(chip);
azx_init_chip(chip, 1);
bus = chip->bus;
if (status && bus) {
list_for_each_entry(codec, &bus->codec_list, list)
if (status & (1 << codec->addr))
queue_delayed_work(codec->bus->workq,
&codec->jackpoll_work, codec->jackpoll_interval);
}
azx_writew(chip, WAKEEN, azx_readw(chip, WAKEEN) &
~STATESTS_INT_MASK);
return 0;
}
static int azx_runtime_idle(struct device *dev)
{
struct snd_card *card = dev_get_drvdata(dev);
struct azx *chip = card->private_data;
if (chip->disabled)
return 0;
if (!power_save_controller ||
!(chip->driver_caps & AZX_DCAPS_PM_RUNTIME))
return -EBUSY;
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
static void azx_vs_set_state(struct pci_dev *pci,
enum vga_switcheroo_state state)
{
struct snd_card *card = pci_get_drvdata(pci);
struct azx *chip = card->private_data;
bool disabled;
wait_for_completion(&chip->probe_wait);
if (chip->init_failed)
return;
disabled = (state == VGA_SWITCHEROO_OFF);
if (chip->disabled == disabled)
return;
if (!chip->bus) {
chip->disabled = disabled;
if (!disabled) {
snd_printk(KERN_INFO SFX
"%s: Start delayed initialization\n",
pci_name(chip->pci));
if (azx_probe_continue(chip) < 0) {
snd_printk(KERN_ERR SFX
"%s: initialization error\n",
pci_name(chip->pci));
chip->init_failed = true;
}
}
} else {
snd_printk(KERN_INFO SFX
"%s: %s via VGA-switcheroo\n", pci_name(chip->pci),
disabled ? "Disabling" : "Enabling");
if (disabled) {
pm_runtime_put_sync_suspend(&pci->dev);
azx_suspend(&pci->dev);
pci->current_state = PCI_D3cold;
chip->disabled = true;
if (snd_hda_lock_devices(chip->bus))
snd_printk(KERN_WARNING SFX "%s: Cannot lock devices!\n",
pci_name(chip->pci));
} else {
snd_hda_unlock_devices(chip->bus);
pm_runtime_get_noresume(&pci->dev);
chip->disabled = false;
azx_resume(&pci->dev);
}
}
}
static bool azx_vs_can_switch(struct pci_dev *pci)
{
struct snd_card *card = pci_get_drvdata(pci);
struct azx *chip = card->private_data;
wait_for_completion(&chip->probe_wait);
if (chip->init_failed)
return false;
if (chip->disabled || !chip->bus)
return true;
if (snd_hda_lock_devices(chip->bus))
return false;
snd_hda_unlock_devices(chip->bus);
return true;
}
static void init_vga_switcheroo(struct azx *chip)
{
struct pci_dev *p = get_bound_vga(chip->pci);
if (p) {
snd_printk(KERN_INFO SFX
"%s: Handle VGA-switcheroo audio client\n",
pci_name(chip->pci));
chip->use_vga_switcheroo = 1;
pci_dev_put(p);
}
}
static int register_vga_switcheroo(struct azx *chip)
{
int err;
if (!chip->use_vga_switcheroo)
return 0;
err = vga_switcheroo_register_audio_client(chip->pci, &azx_vs_ops,
VGA_SWITCHEROO_DIS,
chip->bus != NULL);
if (err < 0)
return err;
chip->vga_switcheroo_registered = 1;
vga_switcheroo_init_domain_pm_optimus_hdmi_audio(&chip->pci->dev, &chip->hdmi_pm_domain);
return 0;
}
static int azx_free(struct azx *chip)
{
struct pci_dev *pci = chip->pci;
int i;
if ((chip->driver_caps & AZX_DCAPS_PM_RUNTIME)
&& chip->running)
pm_runtime_get_noresume(&pci->dev);
azx_del_card_list(chip);
azx_notifier_unregister(chip);
chip->init_failed = 1;
complete_all(&chip->probe_wait);
if (use_vga_switcheroo(chip)) {
if (chip->disabled && chip->bus)
snd_hda_unlock_devices(chip->bus);
if (chip->vga_switcheroo_registered)
vga_switcheroo_unregister_client(chip->pci);
}
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
if (chip->region_requested)
pci_release_regions(chip->pci);
pci_disable_device(chip->pci);
kfree(chip->azx_dev);
#ifdef CONFIG_SND_HDA_PATCH_LOADER
if (chip->fw)
release_firmware(chip->fw);
#endif
if (chip->driver_caps & AZX_DCAPS_I915_POWERWELL) {
hda_display_power(false);
hda_i915_exit();
}
kfree(chip);
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
printk(KERN_INFO
"hda_intel: position_fix set to %d "
"for device %04x:%04x\n",
q->value, q->subvendor, q->subdevice);
return q->value;
}
if (chip->driver_caps & AZX_DCAPS_POSFIX_VIA) {
snd_printd(SFX "%s: Using VIACOMBO position fix\n", pci_name(chip->pci));
return POS_FIX_VIACOMBO;
}
if (chip->driver_caps & AZX_DCAPS_POSFIX_LPIB) {
snd_printd(SFX "%s: Using LPIB position fix\n", pci_name(chip->pci));
return POS_FIX_LPIB;
}
return POS_FIX_AUTO;
}
static void check_probe_mask(struct azx *chip, int dev)
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
static void azx_check_snoop_available(struct azx *chip)
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
case AZX_DRIVER_CTHDA:
snoop = false;
break;
}
if (snoop != chip->snoop) {
snd_printk(KERN_INFO SFX "%s: Force to %s mode\n",
pci_name(chip->pci), snoop ? "snoop" : "non-snoop");
chip->snoop = snoop;
}
}
static void azx_probe_work(struct work_struct *work)
{
azx_probe_continue(container_of(work, struct azx, probe_work));
}
static int azx_create(struct snd_card *card, struct pci_dev *pci,
int dev, unsigned int driver_caps,
struct azx **rchip)
{
static struct snd_device_ops ops = {
.dev_free = azx_dev_free,
};
struct azx *chip;
int err;
*rchip = NULL;
err = pci_enable_device(pci);
if (err < 0)
return err;
chip = kzalloc(sizeof(*chip), GFP_KERNEL);
if (!chip) {
snd_printk(KERN_ERR SFX "%s: Cannot allocate chip\n", pci_name(pci));
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
INIT_LIST_HEAD(&chip->list);
init_vga_switcheroo(chip);
init_completion(&chip->probe_wait);
chip->position_fix[0] = chip->position_fix[1] =
check_position_fix(chip, position_fix[dev]);
if (chip->position_fix[0] == POS_FIX_COMBO) {
chip->position_fix[0] = POS_FIX_LPIB;
chip->position_fix[1] = POS_FIX_AUTO;
}
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
err = snd_device_new(card, SNDRV_DEV_LOWLEVEL, chip, &ops);
if (err < 0) {
snd_printk(KERN_ERR SFX "%s: Error creating device [card]!\n",
pci_name(chip->pci));
azx_free(chip);
return err;
}
#ifdef CONFIG_SND_HDA_I915
INIT_WORK(&chip->probe_work, azx_probe_work);
#endif
*rchip = chip;
return 0;
}
static int azx_first_init(struct azx *chip)
{
int dev = chip->dev_index;
struct pci_dev *pci = chip->pci;
struct snd_card *card = chip->card;
int i, err;
unsigned short gcap;
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
chip->addr = pci_resource_start(pci, 0);
chip->remap_addr = pci_ioremap_bar(pci, 0);
if (chip->remap_addr == NULL) {
snd_printk(KERN_ERR SFX "%s: ioremap error\n", pci_name(chip->pci));
return -ENXIO;
}
if (chip->msi)
if (pci_enable_msi(pci) < 0)
chip->msi = 0;
if (azx_acquire_irq(chip, 0) < 0)
return -EBUSY;
pci_set_master(pci);
synchronize_irq(chip->irq);
gcap = azx_readw(chip, GCAP);
snd_printdd(SFX "%s: chipset global capabilities = 0x%x\n", pci_name(chip->pci), gcap);
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
snd_printd(SFX "%s: Disabling 64bit DMA\n", pci_name(chip->pci));
gcap &= ~ICH6_GCAP_64OK;
}
if (align_buffer_size >= 0)
chip->align_buffer_size = !!align_buffer_size;
else {
if (chip->driver_caps & AZX_DCAPS_BUFSIZE)
chip->align_buffer_size = 0;
else if (chip->driver_caps & AZX_DCAPS_ALIGN_BUFSIZE)
chip->align_buffer_size = 1;
else
chip->align_buffer_size = 1;
}
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
snd_printk(KERN_ERR SFX "%s: cannot malloc azx_dev\n", pci_name(chip->pci));
return -ENOMEM;
}
for (i = 0; i < chip->num_streams; i++) {
dsp_lock_init(&chip->azx_dev[i]);
err = snd_dma_alloc_pages(SNDRV_DMA_TYPE_DEV,
snd_dma_pci_data(chip->pci),
BDL_SIZE, &chip->azx_dev[i].bdl);
if (err < 0) {
snd_printk(KERN_ERR SFX "%s: cannot allocate BDL\n", pci_name(chip->pci));
return -ENOMEM;
}
mark_pages_wc(chip, &chip->azx_dev[i].bdl, true);
}
err = snd_dma_alloc_pages(SNDRV_DMA_TYPE_DEV,
snd_dma_pci_data(chip->pci),
chip->num_streams * 8, &chip->posbuf);
if (err < 0) {
snd_printk(KERN_ERR SFX "%s: cannot allocate posbuf\n", pci_name(chip->pci));
return -ENOMEM;
}
mark_pages_wc(chip, &chip->posbuf, true);
err = azx_alloc_cmd_io(chip);
if (err < 0)
return err;
azx_init_stream(chip);
azx_init_pci(chip);
azx_init_chip(chip, (probe_only[dev] & 2) == 0);
if (!chip->codec_mask) {
snd_printk(KERN_ERR SFX "%s: no codecs found!\n", pci_name(chip->pci));
return -ENODEV;
}
strcpy(card->driver, "HDA-Intel");
strlcpy(card->shortname, driver_short_names[chip->driver_type],
sizeof(card->shortname));
snprintf(card->longname, sizeof(card->longname),
"%s at 0x%lx irq %i",
card->shortname, chip->addr, chip->irq);
return 0;
}
static void power_down_all_codecs(struct azx *chip)
{
#ifdef CONFIG_PM
struct hda_codec *codec;
list_for_each_entry(codec, &chip->bus->codec_list, list) {
snd_hda_power_down(codec);
}
#endif
}
static void azx_firmware_cb(const struct firmware *fw, void *context)
{
struct snd_card *card = context;
struct azx *chip = card->private_data;
struct pci_dev *pci = chip->pci;
if (!fw) {
snd_printk(KERN_ERR SFX "%s: Cannot load firmware, aborting\n",
pci_name(chip->pci));
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
static int azx_probe(struct pci_dev *pci,
const struct pci_device_id *pci_id)
{
static int dev;
struct snd_card *card;
struct azx *chip;
bool probe_now;
int err;
if (dev >= SNDRV_CARDS)
return -ENODEV;
if (!enable[dev]) {
dev++;
return -ENOENT;
}
err = snd_card_create(index[dev], id[dev], THIS_MODULE, 0, &card);
if (err < 0) {
snd_printk(KERN_ERR "hda-intel: Error creating card!\n");
return err;
}
snd_card_set_dev(card, &pci->dev);
err = azx_create(card, pci, dev, pci_id->driver_data, &chip);
if (err < 0)
goto out_free;
card->private_data = chip;
pci_set_drvdata(pci, card);
err = register_vga_switcheroo(chip);
if (err < 0) {
snd_printk(KERN_ERR SFX
"%s: Error registering VGA-switcheroo client\n", pci_name(pci));
goto out_free;
}
if (check_hdmi_disabled(pci)) {
snd_printk(KERN_INFO SFX "%s: VGA controller is disabled\n",
pci_name(pci));
snd_printk(KERN_INFO SFX "%s: Delaying initialization\n", pci_name(pci));
chip->disabled = true;
}
probe_now = !chip->disabled;
#ifdef CONFIG_SND_HDA_PATCH_LOADER
if (patch[dev] && *patch[dev]) {
snd_printk(KERN_ERR SFX "%s: Applying patch firmware '%s'\n",
pci_name(pci), patch[dev]);
err = request_firmware_nowait(THIS_MODULE, true, patch[dev],
&pci->dev, GFP_KERNEL, card,
azx_firmware_cb);
if (err < 0)
goto out_free;
probe_now = false;
}
#endif
if (probe_now && (chip->driver_caps & AZX_DCAPS_I915_POWERWELL)) {
#ifdef CONFIG_SND_HDA_I915
probe_now = false;
schedule_work(&chip->probe_work);
#else
snd_printk(KERN_ERR SFX "Haswell must build in CONFIG_SND_HDA_I915\n");
#endif
}
if (probe_now) {
err = azx_probe_continue(chip);
if (err < 0)
goto out_free;
}
dev++;
complete_all(&chip->probe_wait);
return 0;
out_free:
snd_card_free(card);
return err;
}
static int azx_probe_continue(struct azx *chip)
{
struct pci_dev *pci = chip->pci;
int dev = chip->dev_index;
int err;
if (chip->driver_caps & AZX_DCAPS_I915_POWERWELL) {
#ifdef CONFIG_SND_HDA_I915
err = hda_i915_init();
if (err < 0) {
snd_printk(KERN_ERR SFX "Error request power-well from i915\n");
goto out_free;
}
#endif
hda_display_power(true);
}
err = azx_first_init(chip);
if (err < 0)
goto out_free;
#ifdef CONFIG_SND_HDA_INPUT_BEEP
chip->beep_mode = beep_mode[dev];
#endif
err = azx_codec_create(chip, model[dev]);
if (err < 0)
goto out_free;
#ifdef CONFIG_SND_HDA_PATCH_LOADER
if (chip->fw) {
err = snd_hda_load_patch(chip->bus, chip->fw->size,
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
err = snd_hda_build_pcms(chip->bus);
if (err < 0)
goto out_free;
err = azx_mixer_create(chip);
if (err < 0)
goto out_free;
err = snd_card_register(chip->card);
if (err < 0)
goto out_free;
chip->running = 1;
power_down_all_codecs(chip);
azx_notifier_register(chip);
azx_add_card_list(chip);
if ((chip->driver_caps & AZX_DCAPS_PM_RUNTIME) || chip->use_vga_switcheroo)
pm_runtime_put_noidle(&pci->dev);
return 0;
out_free:
chip->init_failed = 1;
return err;
}
static void azx_remove(struct pci_dev *pci)
{
struct snd_card *card = pci_get_drvdata(pci);
if (card)
snd_card_free(card);
}
