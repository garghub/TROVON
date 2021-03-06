static int build_via_table(struct viadev *dev, struct snd_pcm_substream *substream,
struct pci_dev *pci,
unsigned int periods, unsigned int fragsize)
{
unsigned int i, idx, ofs, rest;
struct via82xx_modem *chip = snd_pcm_substream_chip(substream);
if (dev->table.area == NULL) {
if (snd_dma_alloc_pages(SNDRV_DMA_TYPE_DEV, snd_dma_pci_data(chip->pci),
PAGE_ALIGN(VIA_TABLE_SIZE * 2 * 8),
&dev->table) < 0)
return -ENOMEM;
}
if (! dev->idx_table) {
dev->idx_table = kmalloc(sizeof(*dev->idx_table) * VIA_TABLE_SIZE, GFP_KERNEL);
if (! dev->idx_table)
return -ENOMEM;
}
idx = 0;
ofs = 0;
for (i = 0; i < periods; i++) {
rest = fragsize;
do {
unsigned int r;
unsigned int flag;
unsigned int addr;
if (idx >= VIA_TABLE_SIZE) {
snd_printk(KERN_ERR "via82xx: too much table size!\n");
return -EINVAL;
}
addr = snd_pcm_sgbuf_get_addr(substream, ofs);
((u32 *)dev->table.area)[idx << 1] = cpu_to_le32(addr);
r = PAGE_SIZE - (ofs % PAGE_SIZE);
if (rest < r)
r = rest;
rest -= r;
if (! rest) {
if (i == periods - 1)
flag = VIA_TBL_BIT_EOL;
else
flag = VIA_TBL_BIT_FLAG;
} else
flag = 0;
((u32 *)dev->table.area)[(idx<<1) + 1] = cpu_to_le32(r | flag);
dev->idx_table[idx].offset = ofs;
dev->idx_table[idx].size = r;
ofs += r;
idx++;
} while (rest > 0);
}
dev->tbl_entries = idx;
dev->bufsize = periods * fragsize;
dev->bufsize2 = dev->bufsize / 2;
return 0;
}
static int clean_via_table(struct viadev *dev, struct snd_pcm_substream *substream,
struct pci_dev *pci)
{
if (dev->table.area) {
snd_dma_free_pages(&dev->table);
dev->table.area = NULL;
}
kfree(dev->idx_table);
dev->idx_table = NULL;
return 0;
}
static inline unsigned int snd_via82xx_codec_xread(struct via82xx_modem *chip)
{
return inl(VIAREG(chip, AC97));
}
static inline void snd_via82xx_codec_xwrite(struct via82xx_modem *chip, unsigned int val)
{
outl(val, VIAREG(chip, AC97));
}
static int snd_via82xx_codec_ready(struct via82xx_modem *chip, int secondary)
{
unsigned int timeout = 1000;
unsigned int val;
while (timeout-- > 0) {
udelay(1);
if (!((val = snd_via82xx_codec_xread(chip)) & VIA_REG_AC97_BUSY))
return val & 0xffff;
}
snd_printk(KERN_ERR "codec_ready: codec %i is not ready [0x%x]\n",
secondary, snd_via82xx_codec_xread(chip));
return -EIO;
}
static int snd_via82xx_codec_valid(struct via82xx_modem *chip, int secondary)
{
unsigned int timeout = 1000;
unsigned int val, val1;
unsigned int stat = !secondary ? VIA_REG_AC97_PRIMARY_VALID :
VIA_REG_AC97_SECONDARY_VALID;
while (timeout-- > 0) {
val = snd_via82xx_codec_xread(chip);
val1 = val & (VIA_REG_AC97_BUSY | stat);
if (val1 == stat)
return val & 0xffff;
udelay(1);
}
return -EIO;
}
static void snd_via82xx_codec_wait(struct snd_ac97 *ac97)
{
struct via82xx_modem *chip = ac97->private_data;
int err;
err = snd_via82xx_codec_ready(chip, ac97->num);
msleep(500);
}
static void snd_via82xx_codec_write(struct snd_ac97 *ac97,
unsigned short reg,
unsigned short val)
{
struct via82xx_modem *chip = ac97->private_data;
unsigned int xval;
if(reg == AC97_GPIO_STATUS) {
outl(val, VIAREG(chip, GPI_STATUS));
return;
}
xval = !ac97->num ? VIA_REG_AC97_CODEC_ID_PRIMARY : VIA_REG_AC97_CODEC_ID_SECONDARY;
xval <<= VIA_REG_AC97_CODEC_ID_SHIFT;
xval |= reg << VIA_REG_AC97_CMD_SHIFT;
xval |= val << VIA_REG_AC97_DATA_SHIFT;
snd_via82xx_codec_xwrite(chip, xval);
snd_via82xx_codec_ready(chip, ac97->num);
}
static unsigned short snd_via82xx_codec_read(struct snd_ac97 *ac97, unsigned short reg)
{
struct via82xx_modem *chip = ac97->private_data;
unsigned int xval, val = 0xffff;
int again = 0;
xval = ac97->num << VIA_REG_AC97_CODEC_ID_SHIFT;
xval |= ac97->num ? VIA_REG_AC97_SECONDARY_VALID : VIA_REG_AC97_PRIMARY_VALID;
xval |= VIA_REG_AC97_READ;
xval |= (reg & 0x7f) << VIA_REG_AC97_CMD_SHIFT;
while (1) {
if (again++ > 3) {
snd_printk(KERN_ERR "codec_read: codec %i is not valid [0x%x]\n",
ac97->num, snd_via82xx_codec_xread(chip));
return 0xffff;
}
snd_via82xx_codec_xwrite(chip, xval);
udelay (20);
if (snd_via82xx_codec_valid(chip, ac97->num) >= 0) {
udelay(25);
val = snd_via82xx_codec_xread(chip);
break;
}
}
return val & 0xffff;
}
static void snd_via82xx_channel_reset(struct via82xx_modem *chip, struct viadev *viadev)
{
outb(VIA_REG_CTRL_PAUSE | VIA_REG_CTRL_TERMINATE | VIA_REG_CTRL_RESET,
VIADEV_REG(viadev, OFFSET_CONTROL));
inb(VIADEV_REG(viadev, OFFSET_CONTROL));
udelay(50);
outb(0x00, VIADEV_REG(viadev, OFFSET_CONTROL));
outb(0x03, VIADEV_REG(viadev, OFFSET_STATUS));
outb(0x00, VIADEV_REG(viadev, OFFSET_TYPE));
viadev->lastpos = 0;
}
static irqreturn_t snd_via82xx_interrupt(int irq, void *dev_id)
{
struct via82xx_modem *chip = dev_id;
unsigned int status;
unsigned int i;
status = inl(VIAREG(chip, SGD_SHADOW));
if (! (status & chip->intr_mask)) {
return IRQ_NONE;
}
spin_lock(&chip->reg_lock);
for (i = 0; i < chip->num_devs; i++) {
struct viadev *viadev = &chip->devs[i];
unsigned char c_status = inb(VIADEV_REG(viadev, OFFSET_STATUS));
c_status &= (VIA_REG_STAT_EOL|VIA_REG_STAT_FLAG|VIA_REG_STAT_STOPPED);
if (! c_status)
continue;
if (viadev->substream && viadev->running) {
spin_unlock(&chip->reg_lock);
snd_pcm_period_elapsed(viadev->substream);
spin_lock(&chip->reg_lock);
}
outb(c_status, VIADEV_REG(viadev, OFFSET_STATUS));
}
spin_unlock(&chip->reg_lock);
return IRQ_HANDLED;
}
static int snd_via82xx_pcm_trigger(struct snd_pcm_substream *substream, int cmd)
{
struct via82xx_modem *chip = snd_pcm_substream_chip(substream);
struct viadev *viadev = substream->runtime->private_data;
unsigned char val = 0;
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
case SNDRV_PCM_TRIGGER_SUSPEND:
val |= VIA_REG_CTRL_START;
viadev->running = 1;
break;
case SNDRV_PCM_TRIGGER_STOP:
val = VIA_REG_CTRL_TERMINATE;
viadev->running = 0;
break;
case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
val |= VIA_REG_CTRL_PAUSE;
viadev->running = 0;
break;
case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
viadev->running = 1;
break;
default:
return -EINVAL;
}
outb(val, VIADEV_REG(viadev, OFFSET_CONTROL));
if (cmd == SNDRV_PCM_TRIGGER_STOP)
snd_via82xx_channel_reset(chip, viadev);
return 0;
}
static inline unsigned int calc_linear_pos(struct viadev *viadev, unsigned int idx,
unsigned int count)
{
unsigned int size, res;
size = viadev->idx_table[idx].size;
res = viadev->idx_table[idx].offset + size - count;
if (size < count) {
snd_printd(KERN_ERR "invalid via82xx_cur_ptr (size = %d, count = %d)\n",
(int)size, (int)count);
res = viadev->lastpos;
} else if (check_invalid_pos(viadev, res)) {
#ifdef POINTER_DEBUG
printk(KERN_DEBUG "fail: idx = %i/%i, lastpos = 0x%x, "
"bufsize2 = 0x%x, offsize = 0x%x, size = 0x%x, "
"count = 0x%x\n", idx, viadev->tbl_entries, viadev->lastpos,
viadev->bufsize2, viadev->idx_table[idx].offset,
viadev->idx_table[idx].size, count);
#endif
if (count && size < count) {
snd_printd(KERN_ERR "invalid via82xx_cur_ptr, "
"using last valid pointer\n");
res = viadev->lastpos;
} else {
if (! count)
res = viadev->idx_table[idx].offset;
else
res = viadev->idx_table[idx].offset + size;
if (check_invalid_pos(viadev, res)) {
snd_printd(KERN_ERR "invalid via82xx_cur_ptr (2), "
"using last valid pointer\n");
res = viadev->lastpos;
}
}
}
viadev->lastpos = res;
if (res >= viadev->bufsize)
res -= viadev->bufsize;
return res;
}
static snd_pcm_uframes_t snd_via686_pcm_pointer(struct snd_pcm_substream *substream)
{
struct via82xx_modem *chip = snd_pcm_substream_chip(substream);
struct viadev *viadev = substream->runtime->private_data;
unsigned int idx, ptr, count, res;
if (snd_BUG_ON(!viadev->tbl_entries))
return 0;
if (!(inb(VIADEV_REG(viadev, OFFSET_STATUS)) & VIA_REG_STAT_ACTIVE))
return 0;
spin_lock(&chip->reg_lock);
count = inl(VIADEV_REG(viadev, OFFSET_CURR_COUNT)) & 0xffffff;
ptr = inl(VIADEV_REG(viadev, OFFSET_CURR_PTR));
if (ptr <= (unsigned int)viadev->table.addr)
idx = 0;
else
idx = ((ptr - (unsigned int)viadev->table.addr) / 8 - 1) %
viadev->tbl_entries;
res = calc_linear_pos(viadev, idx, count);
spin_unlock(&chip->reg_lock);
return bytes_to_frames(substream->runtime, res);
}
static int snd_via82xx_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *hw_params)
{
struct via82xx_modem *chip = snd_pcm_substream_chip(substream);
struct viadev *viadev = substream->runtime->private_data;
int err;
err = snd_pcm_lib_malloc_pages(substream, params_buffer_bytes(hw_params));
if (err < 0)
return err;
err = build_via_table(viadev, substream, chip->pci,
params_periods(hw_params),
params_period_bytes(hw_params));
if (err < 0)
return err;
snd_ac97_write(chip->ac97, AC97_LINE1_RATE, params_rate(hw_params));
snd_ac97_write(chip->ac97, AC97_LINE1_LEVEL, 0);
return 0;
}
static int snd_via82xx_hw_free(struct snd_pcm_substream *substream)
{
struct via82xx_modem *chip = snd_pcm_substream_chip(substream);
struct viadev *viadev = substream->runtime->private_data;
clean_via_table(viadev, substream, chip->pci);
snd_pcm_lib_free_pages(substream);
return 0;
}
static void snd_via82xx_set_table_ptr(struct via82xx_modem *chip, struct viadev *viadev)
{
snd_via82xx_codec_ready(chip, chip->ac97_secondary);
outl((u32)viadev->table.addr, VIADEV_REG(viadev, OFFSET_TABLE_PTR));
udelay(20);
snd_via82xx_codec_ready(chip, chip->ac97_secondary);
}
static int snd_via82xx_pcm_prepare(struct snd_pcm_substream *substream)
{
struct via82xx_modem *chip = snd_pcm_substream_chip(substream);
struct viadev *viadev = substream->runtime->private_data;
snd_via82xx_channel_reset(chip, viadev);
snd_via82xx_set_table_ptr(chip, viadev);
outb(VIA_REG_TYPE_AUTOSTART|VIA_REG_TYPE_INT_EOL|VIA_REG_TYPE_INT_FLAG,
VIADEV_REG(viadev, OFFSET_TYPE));
return 0;
}
static int snd_via82xx_modem_pcm_open(struct via82xx_modem *chip, struct viadev *viadev,
struct snd_pcm_substream *substream)
{
struct snd_pcm_runtime *runtime = substream->runtime;
int err;
static unsigned int rates[] = { 8000, 9600, 12000, 16000 };
static struct snd_pcm_hw_constraint_list hw_constraints_rates = {
.count = ARRAY_SIZE(rates),
.list = rates,
.mask = 0,
};
runtime->hw = snd_via82xx_hw;
if ((err = snd_pcm_hw_constraint_list(runtime, 0, SNDRV_PCM_HW_PARAM_RATE,
&hw_constraints_rates)) < 0)
return err;
if ((err = snd_pcm_hw_constraint_integer(runtime, SNDRV_PCM_HW_PARAM_PERIODS)) < 0)
return err;
runtime->private_data = viadev;
viadev->substream = substream;
return 0;
}
static int snd_via82xx_playback_open(struct snd_pcm_substream *substream)
{
struct via82xx_modem *chip = snd_pcm_substream_chip(substream);
struct viadev *viadev = &chip->devs[chip->playback_devno + substream->number];
return snd_via82xx_modem_pcm_open(chip, viadev, substream);
}
static int snd_via82xx_capture_open(struct snd_pcm_substream *substream)
{
struct via82xx_modem *chip = snd_pcm_substream_chip(substream);
struct viadev *viadev = &chip->devs[chip->capture_devno + substream->pcm->device];
return snd_via82xx_modem_pcm_open(chip, viadev, substream);
}
static int snd_via82xx_pcm_close(struct snd_pcm_substream *substream)
{
struct viadev *viadev = substream->runtime->private_data;
viadev->substream = NULL;
return 0;
}
static void init_viadev(struct via82xx_modem *chip, int idx, unsigned int reg_offset,
int direction)
{
chip->devs[idx].reg_offset = reg_offset;
chip->devs[idx].direction = direction;
chip->devs[idx].port = chip->port + reg_offset;
}
static int __devinit snd_via686_pcm_new(struct via82xx_modem *chip)
{
struct snd_pcm *pcm;
int err;
chip->playback_devno = 0;
chip->capture_devno = 1;
chip->num_devs = 2;
chip->intr_mask = 0x330000;
err = snd_pcm_new(chip->card, chip->card->shortname, 0, 1, 1, &pcm);
if (err < 0)
return err;
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_PLAYBACK, &snd_via686_playback_ops);
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_CAPTURE, &snd_via686_capture_ops);
pcm->dev_class = SNDRV_PCM_CLASS_MODEM;
pcm->private_data = chip;
strcpy(pcm->name, chip->card->shortname);
chip->pcms[0] = pcm;
init_viadev(chip, 0, VIA_REG_MO_STATUS, 0);
init_viadev(chip, 1, VIA_REG_MI_STATUS, 1);
if ((err = snd_pcm_lib_preallocate_pages_for_all(pcm, SNDRV_DMA_TYPE_DEV_SG,
snd_dma_pci_data(chip->pci),
64*1024, 128*1024)) < 0)
return err;
return 0;
}
static void snd_via82xx_mixer_free_ac97_bus(struct snd_ac97_bus *bus)
{
struct via82xx_modem *chip = bus->private_data;
chip->ac97_bus = NULL;
}
static void snd_via82xx_mixer_free_ac97(struct snd_ac97 *ac97)
{
struct via82xx_modem *chip = ac97->private_data;
chip->ac97 = NULL;
}
static int __devinit snd_via82xx_mixer_new(struct via82xx_modem *chip)
{
struct snd_ac97_template ac97;
int err;
static struct snd_ac97_bus_ops ops = {
.write = snd_via82xx_codec_write,
.read = snd_via82xx_codec_read,
.wait = snd_via82xx_codec_wait,
};
if ((err = snd_ac97_bus(chip->card, 0, &ops, chip, &chip->ac97_bus)) < 0)
return err;
chip->ac97_bus->private_free = snd_via82xx_mixer_free_ac97_bus;
chip->ac97_bus->clock = chip->ac97_clock;
memset(&ac97, 0, sizeof(ac97));
ac97.private_data = chip;
ac97.private_free = snd_via82xx_mixer_free_ac97;
ac97.pci = chip->pci;
ac97.scaps = AC97_SCAP_SKIP_AUDIO | AC97_SCAP_POWER_SAVE;
ac97.num = chip->ac97_secondary;
if ((err = snd_ac97_mixer(chip->ac97_bus, &ac97, &chip->ac97)) < 0)
return err;
return 0;
}
static void snd_via82xx_proc_read(struct snd_info_entry *entry, struct snd_info_buffer *buffer)
{
struct via82xx_modem *chip = entry->private_data;
int i;
snd_iprintf(buffer, "%s\n\n", chip->card->longname);
for (i = 0; i < 0xa0; i += 4) {
snd_iprintf(buffer, "%02x: %08x\n", i, inl(chip->port + i));
}
}
static void __devinit snd_via82xx_proc_init(struct via82xx_modem *chip)
{
struct snd_info_entry *entry;
if (! snd_card_proc_new(chip->card, "via82xx", &entry))
snd_info_set_text_ops(entry, chip, snd_via82xx_proc_read);
}
static int snd_via82xx_chip_init(struct via82xx_modem *chip)
{
unsigned int val;
unsigned long end_time;
unsigned char pval;
pci_read_config_byte(chip->pci, VIA_MC97_CTRL, &pval);
if((pval & VIA_MC97_CTRL_INIT) != VIA_MC97_CTRL_INIT) {
pci_write_config_byte(chip->pci, 0x44, pval|VIA_MC97_CTRL_INIT);
udelay(100);
}
pci_read_config_byte(chip->pci, VIA_ACLINK_STAT, &pval);
if (! (pval & VIA_ACLINK_C00_READY)) {
pci_write_config_byte(chip->pci, VIA_ACLINK_CTRL,
VIA_ACLINK_CTRL_ENABLE |
VIA_ACLINK_CTRL_RESET |
VIA_ACLINK_CTRL_SYNC);
udelay(100);
#if 1
pci_write_config_byte(chip->pci, VIA_ACLINK_CTRL, 0x00);
udelay(100);
#else
pci_write_config_byte(chip->pci, VIA_ACLINK_CTRL,
VIA_ACLINK_CTRL_RESET|VIA_ACLINK_CTRL_SYNC);
udelay(2);
#endif
pci_write_config_byte(chip->pci, VIA_ACLINK_CTRL, VIA_ACLINK_CTRL_INIT);
udelay(100);
}
pci_read_config_byte(chip->pci, VIA_ACLINK_CTRL, &pval);
if ((pval & VIA_ACLINK_CTRL_INIT) != VIA_ACLINK_CTRL_INIT) {
pci_write_config_byte(chip->pci, VIA_ACLINK_CTRL, VIA_ACLINK_CTRL_INIT);
udelay(100);
}
end_time = jiffies + msecs_to_jiffies(750);
do {
pci_read_config_byte(chip->pci, VIA_ACLINK_STAT, &pval);
if (pval & VIA_ACLINK_C00_READY)
break;
schedule_timeout_uninterruptible(1);
} while (time_before(jiffies, end_time));
if ((val = snd_via82xx_codec_xread(chip)) & VIA_REG_AC97_BUSY)
snd_printk(KERN_ERR "AC'97 codec is not ready [0x%x]\n", val);
snd_via82xx_codec_xwrite(chip, VIA_REG_AC97_READ |
VIA_REG_AC97_SECONDARY_VALID |
(VIA_REG_AC97_CODEC_ID_SECONDARY << VIA_REG_AC97_CODEC_ID_SHIFT));
end_time = jiffies + msecs_to_jiffies(750);
snd_via82xx_codec_xwrite(chip, VIA_REG_AC97_READ |
VIA_REG_AC97_SECONDARY_VALID |
(VIA_REG_AC97_CODEC_ID_SECONDARY << VIA_REG_AC97_CODEC_ID_SHIFT));
do {
if ((val = snd_via82xx_codec_xread(chip)) & VIA_REG_AC97_SECONDARY_VALID) {
chip->ac97_secondary = 1;
goto __ac97_ok2;
}
schedule_timeout_uninterruptible(1);
} while (time_before(jiffies, end_time));
__ac97_ok2:
outl(0, VIAREG(chip, GPI_INTR));
return 0;
}
static int snd_via82xx_suspend(struct pci_dev *pci, pm_message_t state)
{
struct snd_card *card = pci_get_drvdata(pci);
struct via82xx_modem *chip = card->private_data;
int i;
snd_power_change_state(card, SNDRV_CTL_POWER_D3hot);
for (i = 0; i < 2; i++)
snd_pcm_suspend_all(chip->pcms[i]);
for (i = 0; i < chip->num_devs; i++)
snd_via82xx_channel_reset(chip, &chip->devs[i]);
synchronize_irq(chip->irq);
snd_ac97_suspend(chip->ac97);
pci_disable_device(pci);
pci_save_state(pci);
pci_set_power_state(pci, pci_choose_state(pci, state));
return 0;
}
static int snd_via82xx_resume(struct pci_dev *pci)
{
struct snd_card *card = pci_get_drvdata(pci);
struct via82xx_modem *chip = card->private_data;
int i;
pci_set_power_state(pci, PCI_D0);
pci_restore_state(pci);
if (pci_enable_device(pci) < 0) {
printk(KERN_ERR "via82xx-modem: pci_enable_device failed, "
"disabling device\n");
snd_card_disconnect(card);
return -EIO;
}
pci_set_master(pci);
snd_via82xx_chip_init(chip);
snd_ac97_resume(chip->ac97);
for (i = 0; i < chip->num_devs; i++)
snd_via82xx_channel_reset(chip, &chip->devs[i]);
snd_power_change_state(card, SNDRV_CTL_POWER_D0);
return 0;
}
static int snd_via82xx_free(struct via82xx_modem *chip)
{
unsigned int i;
if (chip->irq < 0)
goto __end_hw;
for (i = 0; i < chip->num_devs; i++)
snd_via82xx_channel_reset(chip, &chip->devs[i]);
__end_hw:
if (chip->irq >= 0)
free_irq(chip->irq, chip);
pci_release_regions(chip->pci);
pci_disable_device(chip->pci);
kfree(chip);
return 0;
}
static int snd_via82xx_dev_free(struct snd_device *device)
{
struct via82xx_modem *chip = device->device_data;
return snd_via82xx_free(chip);
}
static int __devinit snd_via82xx_create(struct snd_card *card,
struct pci_dev *pci,
int chip_type,
int revision,
unsigned int ac97_clock,
struct via82xx_modem ** r_via)
{
struct via82xx_modem *chip;
int err;
static struct snd_device_ops ops = {
.dev_free = snd_via82xx_dev_free,
};
if ((err = pci_enable_device(pci)) < 0)
return err;
if ((chip = kzalloc(sizeof(*chip), GFP_KERNEL)) == NULL) {
pci_disable_device(pci);
return -ENOMEM;
}
spin_lock_init(&chip->reg_lock);
chip->card = card;
chip->pci = pci;
chip->irq = -1;
if ((err = pci_request_regions(pci, card->driver)) < 0) {
kfree(chip);
pci_disable_device(pci);
return err;
}
chip->port = pci_resource_start(pci, 0);
if (request_irq(pci->irq, snd_via82xx_interrupt, IRQF_SHARED,
KBUILD_MODNAME, chip)) {
snd_printk(KERN_ERR "unable to grab IRQ %d\n", pci->irq);
snd_via82xx_free(chip);
return -EBUSY;
}
chip->irq = pci->irq;
if (ac97_clock >= 8000 && ac97_clock <= 48000)
chip->ac97_clock = ac97_clock;
synchronize_irq(chip->irq);
if ((err = snd_via82xx_chip_init(chip)) < 0) {
snd_via82xx_free(chip);
return err;
}
if ((err = snd_device_new(card, SNDRV_DEV_LOWLEVEL, chip, &ops)) < 0) {
snd_via82xx_free(chip);
return err;
}
pci_set_master(pci);
snd_card_set_dev(card, &pci->dev);
*r_via = chip;
return 0;
}
static int __devinit snd_via82xx_probe(struct pci_dev *pci,
const struct pci_device_id *pci_id)
{
struct snd_card *card;
struct via82xx_modem *chip;
int chip_type = 0, card_type;
unsigned int i;
int err;
err = snd_card_create(index, id, THIS_MODULE, 0, &card);
if (err < 0)
return err;
card_type = pci_id->driver_data;
switch (card_type) {
case TYPE_CARD_VIA82XX_MODEM:
strcpy(card->driver, "VIA82XX-MODEM");
sprintf(card->shortname, "VIA 82XX modem");
break;
default:
snd_printk(KERN_ERR "invalid card type %d\n", card_type);
err = -EINVAL;
goto __error;
}
if ((err = snd_via82xx_create(card, pci, chip_type, pci->revision,
ac97_clock, &chip)) < 0)
goto __error;
card->private_data = chip;
if ((err = snd_via82xx_mixer_new(chip)) < 0)
goto __error;
if ((err = snd_via686_pcm_new(chip)) < 0 )
goto __error;
for (i = 0; i < chip->num_devs; i++)
snd_via82xx_channel_reset(chip, &chip->devs[i]);
sprintf(card->longname, "%s at 0x%lx, irq %d",
card->shortname, chip->port, chip->irq);
snd_via82xx_proc_init(chip);
if ((err = snd_card_register(card)) < 0) {
snd_card_free(card);
return err;
}
pci_set_drvdata(pci, card);
return 0;
__error:
snd_card_free(card);
return err;
}
static void __devexit snd_via82xx_remove(struct pci_dev *pci)
{
snd_card_free(pci_get_drvdata(pci));
pci_set_drvdata(pci, NULL);
}
static int __init alsa_card_via82xx_init(void)
{
return pci_register_driver(&driver);
}
static void __exit alsa_card_via82xx_exit(void)
{
pci_unregister_driver(&driver);
}
