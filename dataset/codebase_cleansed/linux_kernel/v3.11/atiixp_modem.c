static int snd_atiixp_update_bits(struct atiixp_modem *chip, unsigned int reg,
unsigned int mask, unsigned int value)
{
void __iomem *addr = chip->remap_addr + reg;
unsigned int data, old_data;
old_data = data = readl(addr);
data &= ~mask;
data |= value;
if (old_data == data)
return 0;
writel(data, addr);
return 1;
}
static int atiixp_build_dma_packets(struct atiixp_modem *chip,
struct atiixp_dma *dma,
struct snd_pcm_substream *substream,
unsigned int periods,
unsigned int period_bytes)
{
unsigned int i;
u32 addr, desc_addr;
unsigned long flags;
if (periods > ATI_MAX_DESCRIPTORS)
return -ENOMEM;
if (dma->desc_buf.area == NULL) {
if (snd_dma_alloc_pages(SNDRV_DMA_TYPE_DEV, snd_dma_pci_data(chip->pci),
ATI_DESC_LIST_SIZE, &dma->desc_buf) < 0)
return -ENOMEM;
dma->period_bytes = dma->periods = 0;
}
if (dma->periods == periods && dma->period_bytes == period_bytes)
return 0;
spin_lock_irqsave(&chip->reg_lock, flags);
writel(0, chip->remap_addr + dma->ops->llp_offset);
dma->ops->enable_dma(chip, 0);
dma->ops->enable_dma(chip, 1);
spin_unlock_irqrestore(&chip->reg_lock, flags);
addr = (u32)substream->runtime->dma_addr;
desc_addr = (u32)dma->desc_buf.addr;
for (i = 0; i < periods; i++) {
struct atiixp_dma_desc *desc;
desc = &((struct atiixp_dma_desc *)dma->desc_buf.area)[i];
desc->addr = cpu_to_le32(addr);
desc->status = 0;
desc->size = period_bytes >> 2;
desc_addr += sizeof(struct atiixp_dma_desc);
if (i == periods - 1)
desc->next = cpu_to_le32((u32)dma->desc_buf.addr);
else
desc->next = cpu_to_le32(desc_addr);
addr += period_bytes;
}
writel((u32)dma->desc_buf.addr | ATI_REG_LINKPTR_EN,
chip->remap_addr + dma->ops->llp_offset);
dma->period_bytes = period_bytes;
dma->periods = periods;
return 0;
}
static void atiixp_clear_dma_packets(struct atiixp_modem *chip,
struct atiixp_dma *dma,
struct snd_pcm_substream *substream)
{
if (dma->desc_buf.area) {
writel(0, chip->remap_addr + dma->ops->llp_offset);
snd_dma_free_pages(&dma->desc_buf);
dma->desc_buf.area = NULL;
}
}
static int snd_atiixp_acquire_codec(struct atiixp_modem *chip)
{
int timeout = 1000;
while (atiixp_read(chip, PHYS_OUT_ADDR) & ATI_REG_PHYS_OUT_ADDR_EN) {
if (! timeout--) {
snd_printk(KERN_WARNING "atiixp-modem: codec acquire timeout\n");
return -EBUSY;
}
udelay(1);
}
return 0;
}
static unsigned short snd_atiixp_codec_read(struct atiixp_modem *chip,
unsigned short codec,
unsigned short reg)
{
unsigned int data;
int timeout;
if (snd_atiixp_acquire_codec(chip) < 0)
return 0xffff;
data = (reg << ATI_REG_PHYS_OUT_ADDR_SHIFT) |
ATI_REG_PHYS_OUT_ADDR_EN |
ATI_REG_PHYS_OUT_RW |
codec;
atiixp_write(chip, PHYS_OUT_ADDR, data);
if (snd_atiixp_acquire_codec(chip) < 0)
return 0xffff;
timeout = 1000;
do {
data = atiixp_read(chip, PHYS_IN_ADDR);
if (data & ATI_REG_PHYS_IN_READ_FLAG)
return data >> ATI_REG_PHYS_IN_DATA_SHIFT;
udelay(1);
} while (--timeout);
if (reg < 0x7c)
snd_printk(KERN_WARNING "atiixp-modem: codec read timeout (reg %x)\n", reg);
return 0xffff;
}
static void snd_atiixp_codec_write(struct atiixp_modem *chip,
unsigned short codec,
unsigned short reg, unsigned short val)
{
unsigned int data;
if (snd_atiixp_acquire_codec(chip) < 0)
return;
data = ((unsigned int)val << ATI_REG_PHYS_OUT_DATA_SHIFT) |
((unsigned int)reg << ATI_REG_PHYS_OUT_ADDR_SHIFT) |
ATI_REG_PHYS_OUT_ADDR_EN | codec;
atiixp_write(chip, PHYS_OUT_ADDR, data);
}
static unsigned short snd_atiixp_ac97_read(struct snd_ac97 *ac97,
unsigned short reg)
{
struct atiixp_modem *chip = ac97->private_data;
return snd_atiixp_codec_read(chip, ac97->num, reg);
}
static void snd_atiixp_ac97_write(struct snd_ac97 *ac97, unsigned short reg,
unsigned short val)
{
struct atiixp_modem *chip = ac97->private_data;
if (reg == AC97_GPIO_STATUS) {
atiixp_write(chip, MODEM_OUT_GPIO,
(val << ATI_REG_MODEM_OUT_GPIO_DATA_SHIFT) | ATI_REG_MODEM_OUT_GPIO_EN);
return;
}
snd_atiixp_codec_write(chip, ac97->num, reg, val);
}
static int snd_atiixp_aclink_reset(struct atiixp_modem *chip)
{
int timeout;
if (atiixp_update(chip, CMD, ATI_REG_CMD_POWERDOWN, 0))
udelay(10);
atiixp_update(chip, CMD, ATI_REG_CMD_AC_SOFT_RESET, ATI_REG_CMD_AC_SOFT_RESET);
atiixp_read(chip, CMD);
udelay(10);
atiixp_update(chip, CMD, ATI_REG_CMD_AC_SOFT_RESET, 0);
timeout = 10;
while (! (atiixp_read(chip, CMD) & ATI_REG_CMD_ACLINK_ACTIVE)) {
atiixp_update(chip, CMD, ATI_REG_CMD_AC_SYNC|ATI_REG_CMD_AC_RESET,
ATI_REG_CMD_AC_SYNC);
atiixp_read(chip, CMD);
msleep(1);
atiixp_update(chip, CMD, ATI_REG_CMD_AC_RESET, ATI_REG_CMD_AC_RESET);
if (!--timeout) {
snd_printk(KERN_ERR "atiixp-modem: codec reset timeout\n");
break;
}
}
atiixp_update(chip, CMD, ATI_REG_CMD_AC_SYNC|ATI_REG_CMD_AC_RESET,
ATI_REG_CMD_AC_SYNC|ATI_REG_CMD_AC_RESET);
return 0;
}
static int snd_atiixp_aclink_down(struct atiixp_modem *chip)
{
atiixp_update(chip, CMD,
ATI_REG_CMD_POWERDOWN | ATI_REG_CMD_AC_RESET,
ATI_REG_CMD_POWERDOWN);
return 0;
}
static int snd_atiixp_codec_detect(struct atiixp_modem *chip)
{
int timeout;
chip->codec_not_ready_bits = 0;
atiixp_write(chip, IER, CODEC_CHECK_BITS);
timeout = 50;
while (timeout-- > 0) {
msleep(1);
if (chip->codec_not_ready_bits)
break;
}
atiixp_write(chip, IER, 0);
if ((chip->codec_not_ready_bits & ALL_CODEC_NOT_READY) == ALL_CODEC_NOT_READY) {
snd_printk(KERN_ERR "atiixp-modem: no codec detected!\n");
return -ENXIO;
}
return 0;
}
static int snd_atiixp_chip_start(struct atiixp_modem *chip)
{
unsigned int reg;
reg = atiixp_read(chip, CMD);
reg |= ATI_REG_CMD_BURST_EN;
if(!(reg & ATI_REG_CMD_MODEM_PRESENT))
reg |= ATI_REG_CMD_MODEM_PRESENT;
atiixp_write(chip, CMD, reg);
atiixp_write(chip, ISR, 0xffffffff);
atiixp_write(chip, IER,
ATI_REG_IER_MODEM_STATUS_EN |
ATI_REG_IER_MODEM_IN_XRUN_EN |
ATI_REG_IER_MODEM_OUT1_XRUN_EN);
return 0;
}
static int snd_atiixp_chip_stop(struct atiixp_modem *chip)
{
atiixp_write(chip, ISR, atiixp_read(chip, ISR));
atiixp_write(chip, IER, 0);
return 0;
}
static snd_pcm_uframes_t snd_atiixp_pcm_pointer(struct snd_pcm_substream *substream)
{
struct atiixp_modem *chip = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
struct atiixp_dma *dma = runtime->private_data;
unsigned int curptr;
int timeout = 1000;
while (timeout--) {
curptr = readl(chip->remap_addr + dma->ops->dt_cur);
if (curptr < dma->buf_addr)
continue;
curptr -= dma->buf_addr;
if (curptr >= dma->buf_bytes)
continue;
return bytes_to_frames(runtime, curptr);
}
snd_printd("atiixp-modem: invalid DMA pointer read 0x%x (buf=%x)\n",
readl(chip->remap_addr + dma->ops->dt_cur), dma->buf_addr);
return 0;
}
static void snd_atiixp_xrun_dma(struct atiixp_modem *chip,
struct atiixp_dma *dma)
{
if (! dma->substream || ! dma->running)
return;
snd_printdd("atiixp-modem: XRUN detected (DMA %d)\n", dma->ops->type);
snd_pcm_stream_lock(dma->substream);
snd_pcm_stop(dma->substream, SNDRV_PCM_STATE_XRUN);
snd_pcm_stream_unlock(dma->substream);
}
static void snd_atiixp_update_dma(struct atiixp_modem *chip,
struct atiixp_dma *dma)
{
if (! dma->substream || ! dma->running)
return;
snd_pcm_period_elapsed(dma->substream);
}
static void snd_atiixp_check_bus_busy(struct atiixp_modem *chip)
{
unsigned int bus_busy;
if (atiixp_read(chip, CMD) & (ATI_REG_CMD_MODEM_SEND1_EN |
ATI_REG_CMD_MODEM_RECEIVE_EN))
bus_busy = ATI_REG_IER_MODEM_SET_BUS_BUSY;
else
bus_busy = 0;
atiixp_update(chip, IER, ATI_REG_IER_MODEM_SET_BUS_BUSY, bus_busy);
}
static int snd_atiixp_pcm_trigger(struct snd_pcm_substream *substream, int cmd)
{
struct atiixp_modem *chip = snd_pcm_substream_chip(substream);
struct atiixp_dma *dma = substream->runtime->private_data;
int err = 0;
if (snd_BUG_ON(!dma->ops->enable_transfer ||
!dma->ops->flush_dma))
return -EINVAL;
spin_lock(&chip->reg_lock);
switch(cmd) {
case SNDRV_PCM_TRIGGER_START:
dma->ops->enable_transfer(chip, 1);
dma->running = 1;
break;
case SNDRV_PCM_TRIGGER_STOP:
dma->ops->enable_transfer(chip, 0);
dma->running = 0;
break;
default:
err = -EINVAL;
break;
}
if (! err) {
snd_atiixp_check_bus_busy(chip);
if (cmd == SNDRV_PCM_TRIGGER_STOP) {
dma->ops->flush_dma(chip);
snd_atiixp_check_bus_busy(chip);
}
}
spin_unlock(&chip->reg_lock);
return err;
}
static void atiixp_out_flush_dma(struct atiixp_modem *chip)
{
atiixp_write(chip, MODEM_FIFO_FLUSH, ATI_REG_MODEM_FIFO_OUT1_FLUSH);
}
static void atiixp_out_enable_dma(struct atiixp_modem *chip, int on)
{
unsigned int data;
data = atiixp_read(chip, CMD);
if (on) {
if (data & ATI_REG_CMD_MODEM_OUT_DMA1_EN)
return;
atiixp_out_flush_dma(chip);
data |= ATI_REG_CMD_MODEM_OUT_DMA1_EN;
} else
data &= ~ATI_REG_CMD_MODEM_OUT_DMA1_EN;
atiixp_write(chip, CMD, data);
}
static void atiixp_out_enable_transfer(struct atiixp_modem *chip, int on)
{
atiixp_update(chip, CMD, ATI_REG_CMD_MODEM_SEND1_EN,
on ? ATI_REG_CMD_MODEM_SEND1_EN : 0);
}
static void atiixp_in_enable_dma(struct atiixp_modem *chip, int on)
{
atiixp_update(chip, CMD, ATI_REG_CMD_MODEM_IN_DMA_EN,
on ? ATI_REG_CMD_MODEM_IN_DMA_EN : 0);
}
static void atiixp_in_enable_transfer(struct atiixp_modem *chip, int on)
{
if (on) {
unsigned int data = atiixp_read(chip, CMD);
if (! (data & ATI_REG_CMD_MODEM_RECEIVE_EN)) {
data |= ATI_REG_CMD_MODEM_RECEIVE_EN;
atiixp_write(chip, CMD, data);
}
} else
atiixp_update(chip, CMD, ATI_REG_CMD_MODEM_RECEIVE_EN, 0);
}
static void atiixp_in_flush_dma(struct atiixp_modem *chip)
{
atiixp_write(chip, MODEM_FIFO_FLUSH, ATI_REG_MODEM_FIFO_IN_FLUSH);
}
static int snd_atiixp_playback_prepare(struct snd_pcm_substream *substream)
{
struct atiixp_modem *chip = snd_pcm_substream_chip(substream);
unsigned int data;
spin_lock_irq(&chip->reg_lock);
data = atiixp_read(chip, MODEM_OUT_FIFO);
data &= ~ATI_REG_MODEM_OUT1_DMA_THRESHOLD_MASK;
data |= 0x04 << ATI_REG_MODEM_OUT1_DMA_THRESHOLD_SHIFT;
atiixp_write(chip, MODEM_OUT_FIFO, data);
spin_unlock_irq(&chip->reg_lock);
return 0;
}
static int snd_atiixp_capture_prepare(struct snd_pcm_substream *substream)
{
return 0;
}
static int snd_atiixp_pcm_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *hw_params)
{
struct atiixp_modem *chip = snd_pcm_substream_chip(substream);
struct atiixp_dma *dma = substream->runtime->private_data;
int err;
int i;
err = snd_pcm_lib_malloc_pages(substream, params_buffer_bytes(hw_params));
if (err < 0)
return err;
dma->buf_addr = substream->runtime->dma_addr;
dma->buf_bytes = params_buffer_bytes(hw_params);
err = atiixp_build_dma_packets(chip, dma, substream,
params_periods(hw_params),
params_period_bytes(hw_params));
if (err < 0)
return err;
for (i = 0; i < NUM_ATI_CODECS; i++) {
if (! chip->ac97[i])
continue;
snd_ac97_write(chip->ac97[i], AC97_LINE1_RATE, params_rate(hw_params));
snd_ac97_write(chip->ac97[i], AC97_LINE1_LEVEL, 0);
}
return err;
}
static int snd_atiixp_pcm_hw_free(struct snd_pcm_substream *substream)
{
struct atiixp_modem *chip = snd_pcm_substream_chip(substream);
struct atiixp_dma *dma = substream->runtime->private_data;
atiixp_clear_dma_packets(chip, dma, substream);
snd_pcm_lib_free_pages(substream);
return 0;
}
static int snd_atiixp_pcm_open(struct snd_pcm_substream *substream,
struct atiixp_dma *dma, int pcm_type)
{
struct atiixp_modem *chip = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
int err;
static unsigned int rates[] = { 8000, 9600, 12000, 16000 };
static struct snd_pcm_hw_constraint_list hw_constraints_rates = {
.count = ARRAY_SIZE(rates),
.list = rates,
.mask = 0,
};
if (snd_BUG_ON(!dma->ops || !dma->ops->enable_dma))
return -EINVAL;
if (dma->opened)
return -EBUSY;
dma->substream = substream;
runtime->hw = snd_atiixp_pcm_hw;
dma->ac97_pcm_type = pcm_type;
if ((err = snd_pcm_hw_constraint_list(runtime, 0,
SNDRV_PCM_HW_PARAM_RATE,
&hw_constraints_rates)) < 0)
return err;
if ((err = snd_pcm_hw_constraint_integer(runtime,
SNDRV_PCM_HW_PARAM_PERIODS)) < 0)
return err;
runtime->private_data = dma;
spin_lock_irq(&chip->reg_lock);
dma->ops->enable_dma(chip, 1);
spin_unlock_irq(&chip->reg_lock);
dma->opened = 1;
return 0;
}
static int snd_atiixp_pcm_close(struct snd_pcm_substream *substream,
struct atiixp_dma *dma)
{
struct atiixp_modem *chip = snd_pcm_substream_chip(substream);
if (snd_BUG_ON(!dma->ops || !dma->ops->enable_dma))
return -EINVAL;
spin_lock_irq(&chip->reg_lock);
dma->ops->enable_dma(chip, 0);
spin_unlock_irq(&chip->reg_lock);
dma->substream = NULL;
dma->opened = 0;
return 0;
}
static int snd_atiixp_playback_open(struct snd_pcm_substream *substream)
{
struct atiixp_modem *chip = snd_pcm_substream_chip(substream);
int err;
mutex_lock(&chip->open_mutex);
err = snd_atiixp_pcm_open(substream, &chip->dmas[ATI_DMA_PLAYBACK], 0);
mutex_unlock(&chip->open_mutex);
if (err < 0)
return err;
return 0;
}
static int snd_atiixp_playback_close(struct snd_pcm_substream *substream)
{
struct atiixp_modem *chip = snd_pcm_substream_chip(substream);
int err;
mutex_lock(&chip->open_mutex);
err = snd_atiixp_pcm_close(substream, &chip->dmas[ATI_DMA_PLAYBACK]);
mutex_unlock(&chip->open_mutex);
return err;
}
static int snd_atiixp_capture_open(struct snd_pcm_substream *substream)
{
struct atiixp_modem *chip = snd_pcm_substream_chip(substream);
return snd_atiixp_pcm_open(substream, &chip->dmas[ATI_DMA_CAPTURE], 1);
}
static int snd_atiixp_capture_close(struct snd_pcm_substream *substream)
{
struct atiixp_modem *chip = snd_pcm_substream_chip(substream);
return snd_atiixp_pcm_close(substream, &chip->dmas[ATI_DMA_CAPTURE]);
}
static int snd_atiixp_pcm_new(struct atiixp_modem *chip)
{
struct snd_pcm *pcm;
int err;
chip->dmas[ATI_DMA_PLAYBACK].ops = &snd_atiixp_playback_dma_ops;
chip->dmas[ATI_DMA_CAPTURE].ops = &snd_atiixp_capture_dma_ops;
err = snd_pcm_new(chip->card, "ATI IXP MC97", ATI_PCMDEV_ANALOG, 1, 1, &pcm);
if (err < 0)
return err;
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_PLAYBACK, &snd_atiixp_playback_ops);
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_CAPTURE, &snd_atiixp_capture_ops);
pcm->dev_class = SNDRV_PCM_CLASS_MODEM;
pcm->private_data = chip;
strcpy(pcm->name, "ATI IXP MC97");
chip->pcmdevs[ATI_PCMDEV_ANALOG] = pcm;
snd_pcm_lib_preallocate_pages_for_all(pcm, SNDRV_DMA_TYPE_DEV,
snd_dma_pci_data(chip->pci),
64*1024, 128*1024);
return 0;
}
static irqreturn_t snd_atiixp_interrupt(int irq, void *dev_id)
{
struct atiixp_modem *chip = dev_id;
unsigned int status;
status = atiixp_read(chip, ISR);
if (! status)
return IRQ_NONE;
if (status & ATI_REG_ISR_MODEM_OUT1_XRUN)
snd_atiixp_xrun_dma(chip, &chip->dmas[ATI_DMA_PLAYBACK]);
else if (status & ATI_REG_ISR_MODEM_OUT1_STATUS)
snd_atiixp_update_dma(chip, &chip->dmas[ATI_DMA_PLAYBACK]);
if (status & ATI_REG_ISR_MODEM_IN_XRUN)
snd_atiixp_xrun_dma(chip, &chip->dmas[ATI_DMA_CAPTURE]);
else if (status & ATI_REG_ISR_MODEM_IN_STATUS)
snd_atiixp_update_dma(chip, &chip->dmas[ATI_DMA_CAPTURE]);
if (status & CODEC_CHECK_BITS) {
unsigned int detected;
detected = status & CODEC_CHECK_BITS;
spin_lock(&chip->reg_lock);
chip->codec_not_ready_bits |= detected;
atiixp_update(chip, IER, detected, 0);
spin_unlock(&chip->reg_lock);
}
atiixp_write(chip, ISR, status);
return IRQ_HANDLED;
}
static int snd_atiixp_mixer_new(struct atiixp_modem *chip, int clock)
{
struct snd_ac97_bus *pbus;
struct snd_ac97_template ac97;
int i, err;
int codec_count;
static struct snd_ac97_bus_ops ops = {
.write = snd_atiixp_ac97_write,
.read = snd_atiixp_ac97_read,
};
static unsigned int codec_skip[NUM_ATI_CODECS] = {
ATI_REG_ISR_CODEC0_NOT_READY,
ATI_REG_ISR_CODEC1_NOT_READY,
ATI_REG_ISR_CODEC2_NOT_READY,
};
if (snd_atiixp_codec_detect(chip) < 0)
return -ENXIO;
if ((err = snd_ac97_bus(chip->card, 0, &ops, chip, &pbus)) < 0)
return err;
pbus->clock = clock;
chip->ac97_bus = pbus;
codec_count = 0;
for (i = 0; i < NUM_ATI_CODECS; i++) {
if (chip->codec_not_ready_bits & codec_skip[i])
continue;
memset(&ac97, 0, sizeof(ac97));
ac97.private_data = chip;
ac97.pci = chip->pci;
ac97.num = i;
ac97.scaps = AC97_SCAP_SKIP_AUDIO | AC97_SCAP_POWER_SAVE;
if ((err = snd_ac97_mixer(pbus, &ac97, &chip->ac97[i])) < 0) {
chip->ac97[i] = NULL;
snd_printdd("atiixp-modem: codec %d not available for modem\n", i);
continue;
}
codec_count++;
}
if (! codec_count) {
snd_printk(KERN_ERR "atiixp-modem: no codec available\n");
return -ENODEV;
}
return 0;
}
static int snd_atiixp_suspend(struct device *dev)
{
struct pci_dev *pci = to_pci_dev(dev);
struct snd_card *card = dev_get_drvdata(dev);
struct atiixp_modem *chip = card->private_data;
int i;
snd_power_change_state(card, SNDRV_CTL_POWER_D3hot);
for (i = 0; i < NUM_ATI_PCMDEVS; i++)
snd_pcm_suspend_all(chip->pcmdevs[i]);
for (i = 0; i < NUM_ATI_CODECS; i++)
snd_ac97_suspend(chip->ac97[i]);
snd_atiixp_aclink_down(chip);
snd_atiixp_chip_stop(chip);
pci_disable_device(pci);
pci_save_state(pci);
pci_set_power_state(pci, PCI_D3hot);
return 0;
}
static int snd_atiixp_resume(struct device *dev)
{
struct pci_dev *pci = to_pci_dev(dev);
struct snd_card *card = dev_get_drvdata(dev);
struct atiixp_modem *chip = card->private_data;
int i;
pci_set_power_state(pci, PCI_D0);
pci_restore_state(pci);
if (pci_enable_device(pci) < 0) {
printk(KERN_ERR "atiixp-modem: pci_enable_device failed, "
"disabling device\n");
snd_card_disconnect(card);
return -EIO;
}
pci_set_master(pci);
snd_atiixp_aclink_reset(chip);
snd_atiixp_chip_start(chip);
for (i = 0; i < NUM_ATI_CODECS; i++)
snd_ac97_resume(chip->ac97[i]);
snd_power_change_state(card, SNDRV_CTL_POWER_D0);
return 0;
}
static void snd_atiixp_proc_read(struct snd_info_entry *entry,
struct snd_info_buffer *buffer)
{
struct atiixp_modem *chip = entry->private_data;
int i;
for (i = 0; i < 256; i += 4)
snd_iprintf(buffer, "%02x: %08x\n", i, readl(chip->remap_addr + i));
}
static void snd_atiixp_proc_init(struct atiixp_modem *chip)
{
struct snd_info_entry *entry;
if (! snd_card_proc_new(chip->card, "atiixp-modem", &entry))
snd_info_set_text_ops(entry, chip, snd_atiixp_proc_read);
}
static int snd_atiixp_free(struct atiixp_modem *chip)
{
if (chip->irq < 0)
goto __hw_end;
snd_atiixp_chip_stop(chip);
__hw_end:
if (chip->irq >= 0)
free_irq(chip->irq, chip);
if (chip->remap_addr)
iounmap(chip->remap_addr);
pci_release_regions(chip->pci);
pci_disable_device(chip->pci);
kfree(chip);
return 0;
}
static int snd_atiixp_dev_free(struct snd_device *device)
{
struct atiixp_modem *chip = device->device_data;
return snd_atiixp_free(chip);
}
static int snd_atiixp_create(struct snd_card *card,
struct pci_dev *pci,
struct atiixp_modem **r_chip)
{
static struct snd_device_ops ops = {
.dev_free = snd_atiixp_dev_free,
};
struct atiixp_modem *chip;
int err;
if ((err = pci_enable_device(pci)) < 0)
return err;
chip = kzalloc(sizeof(*chip), GFP_KERNEL);
if (chip == NULL) {
pci_disable_device(pci);
return -ENOMEM;
}
spin_lock_init(&chip->reg_lock);
mutex_init(&chip->open_mutex);
chip->card = card;
chip->pci = pci;
chip->irq = -1;
if ((err = pci_request_regions(pci, "ATI IXP MC97")) < 0) {
kfree(chip);
pci_disable_device(pci);
return err;
}
chip->addr = pci_resource_start(pci, 0);
chip->remap_addr = pci_ioremap_bar(pci, 0);
if (chip->remap_addr == NULL) {
snd_printk(KERN_ERR "AC'97 space ioremap problem\n");
snd_atiixp_free(chip);
return -EIO;
}
if (request_irq(pci->irq, snd_atiixp_interrupt, IRQF_SHARED,
KBUILD_MODNAME, chip)) {
snd_printk(KERN_ERR "unable to grab IRQ %d\n", pci->irq);
snd_atiixp_free(chip);
return -EBUSY;
}
chip->irq = pci->irq;
pci_set_master(pci);
synchronize_irq(chip->irq);
if ((err = snd_device_new(card, SNDRV_DEV_LOWLEVEL, chip, &ops)) < 0) {
snd_atiixp_free(chip);
return err;
}
snd_card_set_dev(card, &pci->dev);
*r_chip = chip;
return 0;
}
static int snd_atiixp_probe(struct pci_dev *pci,
const struct pci_device_id *pci_id)
{
struct snd_card *card;
struct atiixp_modem *chip;
int err;
err = snd_card_create(index, id, THIS_MODULE, 0, &card);
if (err < 0)
return err;
strcpy(card->driver, "ATIIXP-MODEM");
strcpy(card->shortname, "ATI IXP Modem");
if ((err = snd_atiixp_create(card, pci, &chip)) < 0)
goto __error;
card->private_data = chip;
if ((err = snd_atiixp_aclink_reset(chip)) < 0)
goto __error;
if ((err = snd_atiixp_mixer_new(chip, ac97_clock)) < 0)
goto __error;
if ((err = snd_atiixp_pcm_new(chip)) < 0)
goto __error;
snd_atiixp_proc_init(chip);
snd_atiixp_chip_start(chip);
sprintf(card->longname, "%s rev %x at 0x%lx, irq %i",
card->shortname, pci->revision, chip->addr, chip->irq);
if ((err = snd_card_register(card)) < 0)
goto __error;
pci_set_drvdata(pci, card);
return 0;
__error:
snd_card_free(card);
return err;
}
static void snd_atiixp_remove(struct pci_dev *pci)
{
snd_card_free(pci_get_drvdata(pci));
}
