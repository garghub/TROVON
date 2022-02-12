static inline void snd_als4k_iobase_writeb(unsigned long iobase,
enum als4k_iobase_t reg,
u8 val)
{
outb(val, iobase + reg);
}
static inline void snd_als4k_iobase_writel(unsigned long iobase,
enum als4k_iobase_t reg,
u32 val)
{
outl(val, iobase + reg);
}
static inline u8 snd_als4k_iobase_readb(unsigned long iobase,
enum als4k_iobase_t reg)
{
return inb(iobase + reg);
}
static inline u32 snd_als4k_iobase_readl(unsigned long iobase,
enum als4k_iobase_t reg)
{
return inl(iobase + reg);
}
static inline void snd_als4k_gcr_write_addr(unsigned long iobase,
enum als4k_gcr_t reg,
u32 val)
{
snd_als4k_iobase_writeb(iobase, ALS4K_IOB_0C_GCR_INDEX, reg);
snd_als4k_iobase_writel(iobase, ALS4K_IOD_08_GCR_DATA, val);
}
static inline void snd_als4k_gcr_write(struct snd_sb *sb,
enum als4k_gcr_t reg,
u32 val)
{
snd_als4k_gcr_write_addr(sb->alt_port, reg, val);
}
static inline u32 snd_als4k_gcr_read_addr(unsigned long iobase,
enum als4k_gcr_t reg)
{
snd_als4k_iobase_writeb(iobase, ALS4K_IOB_0C_GCR_INDEX, reg);
return snd_als4k_iobase_readl(iobase, ALS4K_IOD_08_GCR_DATA);
}
static inline u32 snd_als4k_gcr_read(struct snd_sb *sb, enum als4k_gcr_t reg)
{
return snd_als4k_gcr_read_addr(sb->alt_port, reg);
}
static inline void snd_als4_cr_write(struct snd_sb *chip,
enum als4k_cr_t reg,
u8 data)
{
snd_sbmixer_write(chip, reg | 0xc0, data);
}
static inline u8 snd_als4_cr_read(struct snd_sb *chip,
enum als4k_cr_t reg)
{
return snd_sbmixer_read(chip, reg | 0xc0);
}
static void snd_als4000_set_rate(struct snd_sb *chip, unsigned int rate)
{
if (!(chip->mode & SB_RATE_LOCK)) {
snd_sbdsp_command(chip, SB_DSP_SAMPLE_RATE_OUT);
snd_sbdsp_command(chip, rate>>8);
snd_sbdsp_command(chip, rate);
}
}
static inline void snd_als4000_set_capture_dma(struct snd_sb *chip,
dma_addr_t addr, unsigned size)
{
snd_als4k_gcr_write(chip, ALS4K_GCRA2_FIFO2_PCIADDR, addr);
snd_als4k_gcr_write(chip, ALS4K_GCRA3_FIFO2_COUNT, (size-1));
}
static inline void snd_als4000_set_playback_dma(struct snd_sb *chip,
dma_addr_t addr,
unsigned size)
{
snd_als4k_gcr_write(chip, ALS4K_GCR91_DMA0_ADDR, addr);
snd_als4k_gcr_write(chip, ALS4K_GCR92_DMA0_MODE_COUNT,
(size-1)|0x180000);
}
static int snd_als4000_get_format(struct snd_pcm_runtime *runtime)
{
int result;
result = 0;
if (snd_pcm_format_signed(runtime->format))
result |= ALS4000_FORMAT_SIGNED;
if (snd_pcm_format_physical_width(runtime->format) == 16)
result |= ALS4000_FORMAT_16BIT;
if (runtime->channels > 1)
result |= ALS4000_FORMAT_STEREO;
return result;
}
static int snd_als4000_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *hw_params)
{
return snd_pcm_lib_malloc_pages(substream, params_buffer_bytes(hw_params));
}
static int snd_als4000_hw_free(struct snd_pcm_substream *substream)
{
snd_pcm_lib_free_pages(substream);
return 0;
}
static int snd_als4000_capture_prepare(struct snd_pcm_substream *substream)
{
struct snd_sb *chip = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
unsigned long size;
unsigned count;
chip->capture_format = snd_als4000_get_format(runtime);
size = snd_pcm_lib_buffer_bytes(substream);
count = snd_pcm_lib_period_bytes(substream);
if (chip->capture_format & ALS4000_FORMAT_16BIT)
count >>= 1;
count--;
spin_lock_irq(&chip->reg_lock);
snd_als4000_set_rate(chip, runtime->rate);
snd_als4000_set_capture_dma(chip, runtime->dma_addr, size);
spin_unlock_irq(&chip->reg_lock);
spin_lock_irq(&chip->mixer_lock);
snd_als4_cr_write(chip, ALS4K_CR1C_FIFO2_BLOCK_LENGTH_LO, count & 0xff);
snd_als4_cr_write(chip, ALS4K_CR1D_FIFO2_BLOCK_LENGTH_HI, count >> 8);
spin_unlock_irq(&chip->mixer_lock);
return 0;
}
static int snd_als4000_playback_prepare(struct snd_pcm_substream *substream)
{
struct snd_sb *chip = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
unsigned long size;
unsigned count;
chip->playback_format = snd_als4000_get_format(runtime);
size = snd_pcm_lib_buffer_bytes(substream);
count = snd_pcm_lib_period_bytes(substream);
if (chip->playback_format & ALS4000_FORMAT_16BIT)
count >>= 1;
count--;
spin_lock_irq(&chip->reg_lock);
snd_als4000_set_rate(chip, runtime->rate);
snd_als4000_set_playback_dma(chip, runtime->dma_addr, size);
snd_sbdsp_command(chip, playback_cmd(chip).dsp_cmd);
snd_sbdsp_command(chip, playback_cmd(chip).format);
snd_sbdsp_command(chip, count & 0xff);
snd_sbdsp_command(chip, count >> 8);
snd_sbdsp_command(chip, playback_cmd(chip).dma_off);
spin_unlock_irq(&chip->reg_lock);
return 0;
}
static int snd_als4000_capture_trigger(struct snd_pcm_substream *substream, int cmd)
{
struct snd_sb *chip = snd_pcm_substream_chip(substream);
int result = 0;
spin_lock(&chip->mixer_lock);
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
case SNDRV_PCM_TRIGGER_RESUME:
chip->mode |= SB_RATE_LOCK_CAPTURE;
snd_als4_cr_write(chip, ALS4K_CR1E_FIFO2_CONTROL,
capture_cmd(chip));
break;
case SNDRV_PCM_TRIGGER_STOP:
case SNDRV_PCM_TRIGGER_SUSPEND:
chip->mode &= ~SB_RATE_LOCK_CAPTURE;
snd_als4_cr_write(chip, ALS4K_CR1E_FIFO2_CONTROL,
capture_cmd(chip));
break;
default:
result = -EINVAL;
break;
}
spin_unlock(&chip->mixer_lock);
return result;
}
static int snd_als4000_playback_trigger(struct snd_pcm_substream *substream, int cmd)
{
struct snd_sb *chip = snd_pcm_substream_chip(substream);
int result = 0;
spin_lock(&chip->reg_lock);
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
case SNDRV_PCM_TRIGGER_RESUME:
chip->mode |= SB_RATE_LOCK_PLAYBACK;
snd_sbdsp_command(chip, playback_cmd(chip).dma_on);
break;
case SNDRV_PCM_TRIGGER_STOP:
case SNDRV_PCM_TRIGGER_SUSPEND:
snd_sbdsp_command(chip, playback_cmd(chip).dma_off);
chip->mode &= ~SB_RATE_LOCK_PLAYBACK;
break;
default:
result = -EINVAL;
break;
}
spin_unlock(&chip->reg_lock);
return result;
}
static snd_pcm_uframes_t snd_als4000_capture_pointer(struct snd_pcm_substream *substream)
{
struct snd_sb *chip = snd_pcm_substream_chip(substream);
unsigned int result;
spin_lock(&chip->reg_lock);
result = snd_als4k_gcr_read(chip, ALS4K_GCRA4_FIFO2_CURRENT_ADDR);
spin_unlock(&chip->reg_lock);
result &= 0xffff;
return bytes_to_frames( substream->runtime, result );
}
static snd_pcm_uframes_t snd_als4000_playback_pointer(struct snd_pcm_substream *substream)
{
struct snd_sb *chip = snd_pcm_substream_chip(substream);
unsigned result;
spin_lock(&chip->reg_lock);
result = snd_als4k_gcr_read(chip, ALS4K_GCRA0_FIFO1_CURRENT_ADDR);
spin_unlock(&chip->reg_lock);
result &= 0xffff;
return bytes_to_frames( substream->runtime, result );
}
static irqreturn_t snd_als4000_interrupt(int irq, void *dev_id)
{
struct snd_sb *chip = dev_id;
unsigned pci_irqstatus;
unsigned sb_irqstatus;
pci_irqstatus = snd_als4k_iobase_readb(chip->alt_port,
ALS4K_IOB_0E_IRQTYPE_SB_CR1E_MPU);
if ((pci_irqstatus & ALS4K_IOB_0E_SB_DMA_IRQ)
&& (chip->playback_substream))
snd_pcm_period_elapsed(chip->playback_substream);
if ((pci_irqstatus & ALS4K_IOB_0E_CR1E_IRQ)
&& (chip->capture_substream))
snd_pcm_period_elapsed(chip->capture_substream);
if ((pci_irqstatus & ALS4K_IOB_0E_MPU_IRQ)
&& (chip->rmidi))
snd_mpu401_uart_interrupt(irq, chip->rmidi->private_data);
snd_als4k_iobase_writeb(chip->alt_port,
ALS4K_IOB_0E_IRQTYPE_SB_CR1E_MPU, pci_irqstatus);
spin_lock(&chip->mixer_lock);
sb_irqstatus = snd_sbmixer_read(chip, SB_DSP4_IRQSTATUS);
spin_unlock(&chip->mixer_lock);
if (sb_irqstatus & SB_IRQTYPE_8BIT)
snd_sb_ack_8bit(chip);
if (sb_irqstatus & SB_IRQTYPE_16BIT)
snd_sb_ack_16bit(chip);
if (sb_irqstatus & SB_IRQTYPE_MPUIN)
inb(chip->mpu_port);
if (sb_irqstatus & ALS4K_IRQTYPE_CR1E_DMA)
snd_als4k_iobase_readb(chip->alt_port,
ALS4K_IOB_16_ACK_FOR_CR1E);
return IRQ_RETVAL(
(pci_irqstatus & (ALS4K_IOB_0E_SB_DMA_IRQ|ALS4K_IOB_0E_CR1E_IRQ|
ALS4K_IOB_0E_MPU_IRQ))
|| (sb_irqstatus & (SB_IRQTYPE_8BIT|SB_IRQTYPE_16BIT|
SB_IRQTYPE_MPUIN|ALS4K_IRQTYPE_CR1E_DMA))
);
}
static int snd_als4000_playback_open(struct snd_pcm_substream *substream)
{
struct snd_sb *chip = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
chip->playback_substream = substream;
runtime->hw = snd_als4000_playback;
return 0;
}
static int snd_als4000_playback_close(struct snd_pcm_substream *substream)
{
struct snd_sb *chip = snd_pcm_substream_chip(substream);
chip->playback_substream = NULL;
snd_pcm_lib_free_pages(substream);
return 0;
}
static int snd_als4000_capture_open(struct snd_pcm_substream *substream)
{
struct snd_sb *chip = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
chip->capture_substream = substream;
runtime->hw = snd_als4000_capture;
return 0;
}
static int snd_als4000_capture_close(struct snd_pcm_substream *substream)
{
struct snd_sb *chip = snd_pcm_substream_chip(substream);
chip->capture_substream = NULL;
snd_pcm_lib_free_pages(substream);
return 0;
}
static int __devinit snd_als4000_pcm(struct snd_sb *chip, int device)
{
struct snd_pcm *pcm;
int err;
err = snd_pcm_new(chip->card, "ALS4000 DSP", device, 1, 1, &pcm);
if (err < 0)
return err;
pcm->private_data = chip;
pcm->info_flags = SNDRV_PCM_INFO_JOINT_DUPLEX;
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_PLAYBACK, &snd_als4000_playback_ops);
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_CAPTURE, &snd_als4000_capture_ops);
snd_pcm_lib_preallocate_pages_for_all(pcm, SNDRV_DMA_TYPE_DEV, snd_dma_pci_data(chip->pci),
64*1024, 64*1024);
chip->pcm = pcm;
return 0;
}
static void snd_als4000_set_addr(unsigned long iobase,
unsigned int sb_io,
unsigned int mpu_io,
unsigned int opl_io,
unsigned int game_io)
{
u32 cfg1 = 0;
u32 cfg2 = 0;
if (mpu_io > 0)
cfg2 |= (mpu_io | 1) << 16;
if (sb_io > 0)
cfg2 |= (sb_io | 1);
if (game_io > 0)
cfg1 |= (game_io | 1) << 16;
if (opl_io > 0)
cfg1 |= (opl_io | 1);
snd_als4k_gcr_write_addr(iobase, ALS4K_GCRA8_LEGACY_CFG1, cfg1);
snd_als4k_gcr_write_addr(iobase, ALS4K_GCRA9_LEGACY_CFG2, cfg2);
}
static void snd_als4000_configure(struct snd_sb *chip)
{
u8 tmp;
int i;
spin_lock_irq(&chip->mixer_lock);
tmp = snd_als4_cr_read(chip, ALS4K_CR0_SB_CONFIG);
snd_als4_cr_write(chip, ALS4K_CR0_SB_CONFIG,
tmp|ALS4K_CR0_MX80_81_REG_WRITE_ENABLE);
snd_sbmixer_write(chip, SB_DSP4_DMASETUP, SB_DMASETUP_DMA0);
snd_als4_cr_write(chip, ALS4K_CR0_SB_CONFIG,
tmp & ~ALS4K_CR0_MX80_81_REG_WRITE_ENABLE);
spin_unlock_irq(&chip->mixer_lock);
spin_lock_irq(&chip->reg_lock);
snd_als4k_gcr_write(chip, ALS4K_GCR8C_MISC_CTRL,
ALS4K_GCR8C_IRQ_MASK_CTRL_ENABLE);
for (i = ALS4K_GCR91_DMA0_ADDR; i <= ALS4K_GCR96_DMA3_MODE_COUNT; ++i)
snd_als4k_gcr_write(chip, i, 0);
snd_als4k_gcr_write(chip, ALS4K_GCR99_DMA_EMULATION_CTRL,
(snd_als4k_gcr_read(chip, ALS4K_GCR99_DMA_EMULATION_CTRL) & ~0x07) | 0x04);
spin_unlock_irq(&chip->reg_lock);
}
static int __devinit snd_als4000_create_gameport(struct snd_card_als4000 *acard, int dev)
{
struct gameport *gp;
struct resource *r;
int io_port;
if (joystick_port[dev] == 0)
return -ENODEV;
if (joystick_port[dev] == 1) {
for (io_port = 0x200; io_port <= 0x218; io_port += 8) {
r = request_region(io_port, 8, "ALS4000 gameport");
if (r)
break;
}
} else {
io_port = joystick_port[dev];
r = request_region(io_port, 8, "ALS4000 gameport");
}
if (!r) {
printk(KERN_WARNING "als4000: cannot reserve joystick ports\n");
return -EBUSY;
}
acard->gameport = gp = gameport_allocate_port();
if (!gp) {
printk(KERN_ERR "als4000: cannot allocate memory for gameport\n");
release_and_free_resource(r);
return -ENOMEM;
}
gameport_set_name(gp, "ALS4000 Gameport");
gameport_set_phys(gp, "pci%s/gameport0", pci_name(acard->pci));
gameport_set_dev_parent(gp, &acard->pci->dev);
gp->io = io_port;
gameport_set_port_data(gp, r);
snd_als4000_set_addr(acard->iobase, 0, 0, 0, 1);
gameport_register_port(acard->gameport);
return 0;
}
static void snd_als4000_free_gameport(struct snd_card_als4000 *acard)
{
if (acard->gameport) {
struct resource *r = gameport_get_port_data(acard->gameport);
gameport_unregister_port(acard->gameport);
acard->gameport = NULL;
snd_als4000_set_addr(acard->iobase, 0, 0, 0, 0);
release_and_free_resource(r);
}
}
static inline int snd_als4000_create_gameport(struct snd_card_als4000 *acard, int dev) { return -ENOSYS; }
static inline void snd_als4000_free_gameport(struct snd_card_als4000 *acard) { }
static void snd_card_als4000_free( struct snd_card *card )
{
struct snd_card_als4000 *acard = card->private_data;
snd_als4k_gcr_write_addr(acard->iobase, ALS4K_GCR8C_MISC_CTRL, 0);
snd_als4000_free_gameport(acard);
pci_release_regions(acard->pci);
pci_disable_device(acard->pci);
}
static int __devinit snd_card_als4000_probe(struct pci_dev *pci,
const struct pci_device_id *pci_id)
{
static int dev;
struct snd_card *card;
struct snd_card_als4000 *acard;
unsigned long iobase;
struct snd_sb *chip;
struct snd_opl3 *opl3;
unsigned short word;
int err;
if (dev >= SNDRV_CARDS)
return -ENODEV;
if (!enable[dev]) {
dev++;
return -ENOENT;
}
if ((err = pci_enable_device(pci)) < 0) {
return err;
}
if (pci_set_dma_mask(pci, DMA_BIT_MASK(24)) < 0 ||
pci_set_consistent_dma_mask(pci, DMA_BIT_MASK(24)) < 0) {
snd_printk(KERN_ERR "architecture does not support 24bit PCI busmaster DMA\n");
pci_disable_device(pci);
return -ENXIO;
}
if ((err = pci_request_regions(pci, "ALS4000")) < 0) {
pci_disable_device(pci);
return err;
}
iobase = pci_resource_start(pci, 0);
pci_read_config_word(pci, PCI_COMMAND, &word);
pci_write_config_word(pci, PCI_COMMAND, word | PCI_COMMAND_IO);
pci_set_master(pci);
err = snd_card_create(index[dev], id[dev], THIS_MODULE,
sizeof(*acard) ,
&card);
if (err < 0) {
pci_release_regions(pci);
pci_disable_device(pci);
return err;
}
acard = card->private_data;
acard->pci = pci;
acard->iobase = iobase;
card->private_free = snd_card_als4000_free;
snd_als4000_set_addr(acard->iobase, 0, 0, 0, 0);
if ((err = snd_sbdsp_create(card,
iobase + ALS4K_IOB_10_ADLIB_ADDR0,
pci->irq,
snd_als4000_interrupt,
-1,
-1,
SB_HW_ALS4000,
&chip)) < 0) {
goto out_err;
}
acard->chip = chip;
chip->pci = pci;
chip->alt_port = iobase;
snd_card_set_dev(card, &pci->dev);
snd_als4000_configure(chip);
strcpy(card->driver, "ALS4000");
strcpy(card->shortname, "Avance Logic ALS4000");
sprintf(card->longname, "%s at 0x%lx, irq %i",
card->shortname, chip->alt_port, chip->irq);
if ((err = snd_mpu401_uart_new( card, 0, MPU401_HW_ALS4000,
iobase + ALS4K_IOB_30_MIDI_DATA,
MPU401_INFO_INTEGRATED |
MPU401_INFO_IRQ_HOOK,
-1, &chip->rmidi)) < 0) {
printk(KERN_ERR "als4000: no MPU-401 device at 0x%lx?\n",
iobase + ALS4K_IOB_30_MIDI_DATA);
goto out_err;
}
if ((err = snd_als4000_pcm(chip, 0)) < 0) {
goto out_err;
}
if ((err = snd_sbmixer_new(chip)) < 0) {
goto out_err;
}
if (snd_opl3_create(card,
iobase + ALS4K_IOB_10_ADLIB_ADDR0,
iobase + ALS4K_IOB_12_ADLIB_ADDR2,
OPL3_HW_AUTO, 1, &opl3) < 0) {
printk(KERN_ERR "als4000: no OPL device at 0x%lx-0x%lx?\n",
iobase + ALS4K_IOB_10_ADLIB_ADDR0,
iobase + ALS4K_IOB_12_ADLIB_ADDR2);
} else {
if ((err = snd_opl3_hwdep_new(opl3, 0, 1, NULL)) < 0) {
goto out_err;
}
}
snd_als4000_create_gameport(acard, dev);
if ((err = snd_card_register(card)) < 0) {
goto out_err;
}
pci_set_drvdata(pci, card);
dev++;
err = 0;
goto out;
out_err:
snd_card_free(card);
out:
return err;
}
static void __devexit snd_card_als4000_remove(struct pci_dev *pci)
{
snd_card_free(pci_get_drvdata(pci));
pci_set_drvdata(pci, NULL);
}
static int snd_als4000_suspend(struct device *dev)
{
struct pci_dev *pci = to_pci_dev(dev);
struct snd_card *card = dev_get_drvdata(dev);
struct snd_card_als4000 *acard = card->private_data;
struct snd_sb *chip = acard->chip;
snd_power_change_state(card, SNDRV_CTL_POWER_D3hot);
snd_pcm_suspend_all(chip->pcm);
snd_sbmixer_suspend(chip);
pci_disable_device(pci);
pci_save_state(pci);
pci_set_power_state(pci, PCI_D3hot);
return 0;
}
static int snd_als4000_resume(struct device *dev)
{
struct pci_dev *pci = to_pci_dev(dev);
struct snd_card *card = dev_get_drvdata(dev);
struct snd_card_als4000 *acard = card->private_data;
struct snd_sb *chip = acard->chip;
pci_set_power_state(pci, PCI_D0);
pci_restore_state(pci);
if (pci_enable_device(pci) < 0) {
printk(KERN_ERR "als4000: pci_enable_device failed, "
"disabling device\n");
snd_card_disconnect(card);
return -EIO;
}
pci_set_master(pci);
snd_als4000_configure(chip);
snd_sbdsp_reset(chip);
snd_sbmixer_resume(chip);
#ifdef SUPPORT_JOYSTICK
if (acard->gameport)
snd_als4000_set_addr(acard->iobase, 0, 0, 0, 1);
#endif
snd_power_change_state(card, SNDRV_CTL_POWER_D0);
return 0;
}
