static inline u32 snd_als300_gcr_read(unsigned long port, unsigned short reg)
{
outb(reg, port+GCR_INDEX);
return inl(port+GCR_DATA);
}
static inline void snd_als300_gcr_write(unsigned long port,
unsigned short reg, u32 val)
{
outb(reg, port+GCR_INDEX);
outl(val, port+GCR_DATA);
}
static void snd_als300_set_irq_flag(struct snd_als300 *chip, int cmd)
{
u32 tmp = snd_als300_gcr_read(chip->port, MISC_CONTROL);
snd_als300_dbgcallenter();
if (((chip->revision > 5 || chip->chip_type == DEVICE_ALS300_PLUS) ^
(cmd == IRQ_ENABLE)) == 0)
tmp |= IRQ_SET_BIT;
else
tmp &= ~IRQ_SET_BIT;
snd_als300_gcr_write(chip->port, MISC_CONTROL, tmp);
snd_als300_dbgcallleave();
}
static int snd_als300_free(struct snd_als300 *chip)
{
snd_als300_dbgcallenter();
snd_als300_set_irq_flag(chip, IRQ_DISABLE);
if (chip->irq >= 0)
free_irq(chip->irq, chip);
pci_release_regions(chip->pci);
pci_disable_device(chip->pci);
kfree(chip);
snd_als300_dbgcallleave();
return 0;
}
static int snd_als300_dev_free(struct snd_device *device)
{
struct snd_als300 *chip = device->device_data;
return snd_als300_free(chip);
}
static irqreturn_t snd_als300_interrupt(int irq, void *dev_id)
{
u8 status;
struct snd_als300 *chip = dev_id;
struct snd_als300_substream_data *data;
status = inb(chip->port+ALS300_IRQ_STATUS);
if (!status)
return IRQ_NONE;
outb(status, chip->port+ALS300_IRQ_STATUS);
if (status & IRQ_PLAYBACK) {
if (chip->pcm && chip->playback_substream) {
data = chip->playback_substream->runtime->private_data;
data->period_flipflop ^= 1;
snd_pcm_period_elapsed(chip->playback_substream);
snd_als300_dbgplay("IRQ_PLAYBACK\n");
}
}
if (status & IRQ_CAPTURE) {
if (chip->pcm && chip->capture_substream) {
data = chip->capture_substream->runtime->private_data;
data->period_flipflop ^= 1;
snd_pcm_period_elapsed(chip->capture_substream);
snd_als300_dbgplay("IRQ_CAPTURE\n");
}
}
return IRQ_HANDLED;
}
static irqreturn_t snd_als300plus_interrupt(int irq, void *dev_id)
{
u8 general, mpu, dram;
struct snd_als300 *chip = dev_id;
struct snd_als300_substream_data *data;
general = inb(chip->port+ALS300P_IRQ_STATUS);
mpu = inb(chip->port+MPU_IRQ_STATUS);
dram = inb(chip->port+ALS300P_DRAM_IRQ_STATUS);
if ((general == 0) && ((mpu & 0x80) == 0) && ((dram & 0x01) == 0))
return IRQ_NONE;
if (general & IRQ_PLAYBACK) {
if (chip->pcm && chip->playback_substream) {
outb(IRQ_PLAYBACK, chip->port+ALS300P_IRQ_STATUS);
data = chip->playback_substream->runtime->private_data;
data->period_flipflop ^= 1;
snd_pcm_period_elapsed(chip->playback_substream);
snd_als300_dbgplay("IRQ_PLAYBACK\n");
}
}
if (general & IRQ_CAPTURE) {
if (chip->pcm && chip->capture_substream) {
outb(IRQ_CAPTURE, chip->port+ALS300P_IRQ_STATUS);
data = chip->capture_substream->runtime->private_data;
data->period_flipflop ^= 1;
snd_pcm_period_elapsed(chip->capture_substream);
snd_als300_dbgplay("IRQ_CAPTURE\n");
}
}
return IRQ_HANDLED;
}
static void snd_als300_remove(struct pci_dev *pci)
{
snd_als300_dbgcallenter();
snd_card_free(pci_get_drvdata(pci));
pci_set_drvdata(pci, NULL);
snd_als300_dbgcallleave();
}
static unsigned short snd_als300_ac97_read(struct snd_ac97 *ac97,
unsigned short reg)
{
int i;
struct snd_als300 *chip = ac97->private_data;
for (i = 0; i < 1000; i++) {
if ((inb(chip->port+AC97_STATUS) & (AC97_BUSY)) == 0)
break;
udelay(10);
}
outl((reg << 24) | (1 << 31), chip->port+AC97_ACCESS);
for (i = 0; i < 1000; i++) {
if ((inb(chip->port+AC97_STATUS) & (AC97_DATA_AVAIL)) != 0)
break;
udelay(10);
}
return inw(chip->port+AC97_READ);
}
static void snd_als300_ac97_write(struct snd_ac97 *ac97,
unsigned short reg, unsigned short val)
{
int i;
struct snd_als300 *chip = ac97->private_data;
for (i = 0; i < 1000; i++) {
if ((inb(chip->port+AC97_STATUS) & (AC97_BUSY)) == 0)
break;
udelay(10);
}
outl((reg << 24) | val, chip->port+AC97_ACCESS);
}
static int snd_als300_ac97(struct snd_als300 *chip)
{
struct snd_ac97_bus *bus;
struct snd_ac97_template ac97;
int err;
static struct snd_ac97_bus_ops ops = {
.write = snd_als300_ac97_write,
.read = snd_als300_ac97_read,
};
snd_als300_dbgcallenter();
if ((err = snd_ac97_bus(chip->card, 0, &ops, NULL, &bus)) < 0)
return err;
memset(&ac97, 0, sizeof(ac97));
ac97.private_data = chip;
snd_als300_dbgcallleave();
return snd_ac97_mixer(bus, &ac97, &chip->ac97);
}
static int snd_als300_playback_open(struct snd_pcm_substream *substream)
{
struct snd_als300 *chip = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
struct snd_als300_substream_data *data = kzalloc(sizeof(*data),
GFP_KERNEL);
if (!data)
return -ENOMEM;
snd_als300_dbgcallenter();
chip->playback_substream = substream;
runtime->hw = snd_als300_playback_hw;
runtime->private_data = data;
data->control_register = PLAYBACK_CONTROL;
data->block_counter_register = PLAYBACK_BLOCK_COUNTER;
snd_als300_dbgcallleave();
return 0;
}
static int snd_als300_playback_close(struct snd_pcm_substream *substream)
{
struct snd_als300 *chip = snd_pcm_substream_chip(substream);
struct snd_als300_substream_data *data;
data = substream->runtime->private_data;
snd_als300_dbgcallenter();
kfree(data);
chip->playback_substream = NULL;
snd_pcm_lib_free_pages(substream);
snd_als300_dbgcallleave();
return 0;
}
static int snd_als300_capture_open(struct snd_pcm_substream *substream)
{
struct snd_als300 *chip = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
struct snd_als300_substream_data *data = kzalloc(sizeof(*data),
GFP_KERNEL);
if (!data)
return -ENOMEM;
snd_als300_dbgcallenter();
chip->capture_substream = substream;
runtime->hw = snd_als300_capture_hw;
runtime->private_data = data;
data->control_register = RECORD_CONTROL;
data->block_counter_register = RECORD_BLOCK_COUNTER;
snd_als300_dbgcallleave();
return 0;
}
static int snd_als300_capture_close(struct snd_pcm_substream *substream)
{
struct snd_als300 *chip = snd_pcm_substream_chip(substream);
struct snd_als300_substream_data *data;
data = substream->runtime->private_data;
snd_als300_dbgcallenter();
kfree(data);
chip->capture_substream = NULL;
snd_pcm_lib_free_pages(substream);
snd_als300_dbgcallleave();
return 0;
}
static int snd_als300_pcm_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *hw_params)
{
return snd_pcm_lib_malloc_pages(substream,
params_buffer_bytes(hw_params));
}
static int snd_als300_pcm_hw_free(struct snd_pcm_substream *substream)
{
return snd_pcm_lib_free_pages(substream);
}
static int snd_als300_playback_prepare(struct snd_pcm_substream *substream)
{
u32 tmp;
struct snd_als300 *chip = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
unsigned short period_bytes = snd_pcm_lib_period_bytes(substream);
unsigned short buffer_bytes = snd_pcm_lib_buffer_bytes(substream);
snd_als300_dbgcallenter();
spin_lock_irq(&chip->reg_lock);
tmp = snd_als300_gcr_read(chip->port, PLAYBACK_CONTROL);
tmp &= ~TRANSFER_START;
snd_als300_dbgplay("Period bytes: %d Buffer bytes %d\n",
period_bytes, buffer_bytes);
tmp &= 0xffff0000;
tmp |= period_bytes - 1;
snd_als300_gcr_write(chip->port, PLAYBACK_CONTROL, tmp);
snd_als300_gcr_write(chip->port, PLAYBACK_START,
runtime->dma_addr);
snd_als300_gcr_write(chip->port, PLAYBACK_END,
runtime->dma_addr + buffer_bytes - 1);
spin_unlock_irq(&chip->reg_lock);
snd_als300_dbgcallleave();
return 0;
}
static int snd_als300_capture_prepare(struct snd_pcm_substream *substream)
{
u32 tmp;
struct snd_als300 *chip = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
unsigned short period_bytes = snd_pcm_lib_period_bytes(substream);
unsigned short buffer_bytes = snd_pcm_lib_buffer_bytes(substream);
snd_als300_dbgcallenter();
spin_lock_irq(&chip->reg_lock);
tmp = snd_als300_gcr_read(chip->port, RECORD_CONTROL);
tmp &= ~TRANSFER_START;
snd_als300_dbgplay("Period bytes: %d Buffer bytes %d\n", period_bytes,
buffer_bytes);
tmp &= 0xffff0000;
tmp |= period_bytes - 1;
snd_als300_gcr_write(chip->port, RECORD_CONTROL, tmp);
snd_als300_gcr_write(chip->port, RECORD_START,
runtime->dma_addr);
snd_als300_gcr_write(chip->port, RECORD_END,
runtime->dma_addr + buffer_bytes - 1);
spin_unlock_irq(&chip->reg_lock);
snd_als300_dbgcallleave();
return 0;
}
static int snd_als300_trigger(struct snd_pcm_substream *substream, int cmd)
{
struct snd_als300 *chip = snd_pcm_substream_chip(substream);
u32 tmp;
struct snd_als300_substream_data *data;
unsigned short reg;
int ret = 0;
data = substream->runtime->private_data;
reg = data->control_register;
snd_als300_dbgcallenter();
spin_lock(&chip->reg_lock);
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
case SNDRV_PCM_TRIGGER_RESUME:
tmp = snd_als300_gcr_read(chip->port, reg);
data->period_flipflop = 1;
snd_als300_gcr_write(chip->port, reg, tmp | TRANSFER_START);
snd_als300_dbgplay("TRIGGER START\n");
break;
case SNDRV_PCM_TRIGGER_STOP:
case SNDRV_PCM_TRIGGER_SUSPEND:
tmp = snd_als300_gcr_read(chip->port, reg);
snd_als300_gcr_write(chip->port, reg, tmp & ~TRANSFER_START);
snd_als300_dbgplay("TRIGGER STOP\n");
break;
case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
tmp = snd_als300_gcr_read(chip->port, reg);
snd_als300_gcr_write(chip->port, reg, tmp | FIFO_PAUSE);
snd_als300_dbgplay("TRIGGER PAUSE\n");
break;
case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
tmp = snd_als300_gcr_read(chip->port, reg);
snd_als300_gcr_write(chip->port, reg, tmp & ~FIFO_PAUSE);
snd_als300_dbgplay("TRIGGER RELEASE\n");
break;
default:
snd_als300_dbgplay("TRIGGER INVALID\n");
ret = -EINVAL;
}
spin_unlock(&chip->reg_lock);
snd_als300_dbgcallleave();
return ret;
}
static snd_pcm_uframes_t snd_als300_pointer(struct snd_pcm_substream *substream)
{
u16 current_ptr;
struct snd_als300 *chip = snd_pcm_substream_chip(substream);
struct snd_als300_substream_data *data;
unsigned short period_bytes;
data = substream->runtime->private_data;
period_bytes = snd_pcm_lib_period_bytes(substream);
snd_als300_dbgcallenter();
spin_lock(&chip->reg_lock);
current_ptr = (u16) snd_als300_gcr_read(chip->port,
data->block_counter_register) + 4;
spin_unlock(&chip->reg_lock);
if (current_ptr > period_bytes)
current_ptr = 0;
else
current_ptr = period_bytes - current_ptr;
if (data->period_flipflop == 0)
current_ptr += period_bytes;
snd_als300_dbgplay("Pointer (bytes): %d\n", current_ptr);
snd_als300_dbgcallleave();
return bytes_to_frames(substream->runtime, current_ptr);
}
static int snd_als300_new_pcm(struct snd_als300 *chip)
{
struct snd_pcm *pcm;
int err;
snd_als300_dbgcallenter();
err = snd_pcm_new(chip->card, "ALS300", 0, 1, 1, &pcm);
if (err < 0)
return err;
pcm->private_data = chip;
strcpy(pcm->name, "ALS300");
chip->pcm = pcm;
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_PLAYBACK,
&snd_als300_playback_ops);
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_CAPTURE,
&snd_als300_capture_ops);
snd_pcm_lib_preallocate_pages_for_all(pcm, SNDRV_DMA_TYPE_DEV,
snd_dma_pci_data(chip->pci), 64*1024, 64*1024);
snd_als300_dbgcallleave();
return 0;
}
static void snd_als300_init(struct snd_als300 *chip)
{
unsigned long flags;
u32 tmp;
snd_als300_dbgcallenter();
spin_lock_irqsave(&chip->reg_lock, flags);
chip->revision = (snd_als300_gcr_read(chip->port, MISC_CONTROL) >> 16)
& 0x0000000F;
tmp = snd_als300_gcr_read(chip->port, DRAM_WRITE_CONTROL);
snd_als300_gcr_write(chip->port, DRAM_WRITE_CONTROL,
(tmp | DRAM_MODE_2)
& ~WRITE_TRANS_START);
snd_als300_set_irq_flag(chip, IRQ_ENABLE);
tmp = snd_als300_gcr_read(chip->port, MISC_CONTROL);
snd_als300_gcr_write(chip->port, MISC_CONTROL,
tmp | VMUTE_NORMAL | MMUTE_NORMAL);
snd_als300_gcr_write(chip->port, MUS_VOC_VOL, 0);
tmp = snd_als300_gcr_read(chip->port, PLAYBACK_CONTROL);
snd_als300_gcr_write(chip->port, PLAYBACK_CONTROL,
tmp & ~TRANSFER_START);
spin_unlock_irqrestore(&chip->reg_lock, flags);
snd_als300_dbgcallleave();
}
static int snd_als300_create(struct snd_card *card,
struct pci_dev *pci, int chip_type,
struct snd_als300 **rchip)
{
struct snd_als300 *chip;
void *irq_handler;
int err;
static struct snd_device_ops ops = {
.dev_free = snd_als300_dev_free,
};
*rchip = NULL;
snd_als300_dbgcallenter();
if ((err = pci_enable_device(pci)) < 0)
return err;
if (pci_set_dma_mask(pci, DMA_BIT_MASK(28)) < 0 ||
pci_set_consistent_dma_mask(pci, DMA_BIT_MASK(28)) < 0) {
printk(KERN_ERR "error setting 28bit DMA mask\n");
pci_disable_device(pci);
return -ENXIO;
}
pci_set_master(pci);
chip = kzalloc(sizeof(*chip), GFP_KERNEL);
if (chip == NULL) {
pci_disable_device(pci);
return -ENOMEM;
}
chip->card = card;
chip->pci = pci;
chip->irq = -1;
chip->chip_type = chip_type;
spin_lock_init(&chip->reg_lock);
if ((err = pci_request_regions(pci, "ALS300")) < 0) {
kfree(chip);
pci_disable_device(pci);
return err;
}
chip->port = pci_resource_start(pci, 0);
if (chip->chip_type == DEVICE_ALS300_PLUS)
irq_handler = snd_als300plus_interrupt;
else
irq_handler = snd_als300_interrupt;
if (request_irq(pci->irq, irq_handler, IRQF_SHARED,
KBUILD_MODNAME, chip)) {
snd_printk(KERN_ERR "unable to grab IRQ %d\n", pci->irq);
snd_als300_free(chip);
return -EBUSY;
}
chip->irq = pci->irq;
snd_als300_init(chip);
err = snd_als300_ac97(chip);
if (err < 0) {
snd_printk(KERN_WARNING "Could not create ac97\n");
snd_als300_free(chip);
return err;
}
if ((err = snd_als300_new_pcm(chip)) < 0) {
snd_printk(KERN_WARNING "Could not create PCM\n");
snd_als300_free(chip);
return err;
}
if ((err = snd_device_new(card, SNDRV_DEV_LOWLEVEL,
chip, &ops)) < 0) {
snd_als300_free(chip);
return err;
}
snd_card_set_dev(card, &pci->dev);
*rchip = chip;
snd_als300_dbgcallleave();
return 0;
}
static int snd_als300_suspend(struct device *dev)
{
struct pci_dev *pci = to_pci_dev(dev);
struct snd_card *card = dev_get_drvdata(dev);
struct snd_als300 *chip = card->private_data;
snd_power_change_state(card, SNDRV_CTL_POWER_D3hot);
snd_pcm_suspend_all(chip->pcm);
snd_ac97_suspend(chip->ac97);
pci_disable_device(pci);
pci_save_state(pci);
pci_set_power_state(pci, PCI_D3hot);
return 0;
}
static int snd_als300_resume(struct device *dev)
{
struct pci_dev *pci = to_pci_dev(dev);
struct snd_card *card = dev_get_drvdata(dev);
struct snd_als300 *chip = card->private_data;
pci_set_power_state(pci, PCI_D0);
pci_restore_state(pci);
if (pci_enable_device(pci) < 0) {
printk(KERN_ERR "als300: pci_enable_device failed, "
"disabling device\n");
snd_card_disconnect(card);
return -EIO;
}
pci_set_master(pci);
snd_als300_init(chip);
snd_ac97_resume(chip->ac97);
snd_power_change_state(card, SNDRV_CTL_POWER_D0);
return 0;
}
static int snd_als300_probe(struct pci_dev *pci,
const struct pci_device_id *pci_id)
{
static int dev;
struct snd_card *card;
struct snd_als300 *chip;
int err, chip_type;
if (dev >= SNDRV_CARDS)
return -ENODEV;
if (!enable[dev]) {
dev++;
return -ENOENT;
}
err = snd_card_create(index[dev], id[dev], THIS_MODULE, 0, &card);
if (err < 0)
return err;
chip_type = pci_id->driver_data;
if ((err = snd_als300_create(card, pci, chip_type, &chip)) < 0) {
snd_card_free(card);
return err;
}
card->private_data = chip;
strcpy(card->driver, "ALS300");
if (chip->chip_type == DEVICE_ALS300_PLUS)
sprintf(card->shortname, "ALS300+ (Rev. %d)", chip->revision);
else
sprintf(card->shortname, "ALS300 (Rev. %c)", 'A' +
chip->revision - 1);
sprintf(card->longname, "%s at 0x%lx irq %i",
card->shortname, chip->port, chip->irq);
if ((err = snd_card_register(card)) < 0) {
snd_card_free(card);
return err;
}
pci_set_drvdata(pci, card);
dev++;
return 0;
}
