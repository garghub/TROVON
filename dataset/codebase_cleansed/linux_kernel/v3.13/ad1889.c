static inline u16
ad1889_readw(struct snd_ad1889 *chip, unsigned reg)
{
return readw(chip->iobase + reg);
}
static inline void
ad1889_writew(struct snd_ad1889 *chip, unsigned reg, u16 val)
{
writew(val, chip->iobase + reg);
}
static inline u32
ad1889_readl(struct snd_ad1889 *chip, unsigned reg)
{
return readl(chip->iobase + reg);
}
static inline void
ad1889_writel(struct snd_ad1889 *chip, unsigned reg, u32 val)
{
writel(val, chip->iobase + reg);
}
static inline void
ad1889_unmute(struct snd_ad1889 *chip)
{
u16 st;
st = ad1889_readw(chip, AD_DS_WADA) &
~(AD_DS_WADA_RWAM | AD_DS_WADA_LWAM);
ad1889_writew(chip, AD_DS_WADA, st);
ad1889_readw(chip, AD_DS_WADA);
}
static inline void
ad1889_mute(struct snd_ad1889 *chip)
{
u16 st;
st = ad1889_readw(chip, AD_DS_WADA) | AD_DS_WADA_RWAM | AD_DS_WADA_LWAM;
ad1889_writew(chip, AD_DS_WADA, st);
ad1889_readw(chip, AD_DS_WADA);
}
static inline void
ad1889_load_adc_buffer_address(struct snd_ad1889 *chip, u32 address)
{
ad1889_writel(chip, AD_DMA_ADCBA, address);
ad1889_writel(chip, AD_DMA_ADCCA, address);
}
static inline void
ad1889_load_adc_buffer_count(struct snd_ad1889 *chip, u32 count)
{
ad1889_writel(chip, AD_DMA_ADCBC, count);
ad1889_writel(chip, AD_DMA_ADCCC, count);
}
static inline void
ad1889_load_adc_interrupt_count(struct snd_ad1889 *chip, u32 count)
{
ad1889_writel(chip, AD_DMA_ADCIB, count);
ad1889_writel(chip, AD_DMA_ADCIC, count);
}
static inline void
ad1889_load_wave_buffer_address(struct snd_ad1889 *chip, u32 address)
{
ad1889_writel(chip, AD_DMA_WAVBA, address);
ad1889_writel(chip, AD_DMA_WAVCA, address);
}
static inline void
ad1889_load_wave_buffer_count(struct snd_ad1889 *chip, u32 count)
{
ad1889_writel(chip, AD_DMA_WAVBC, count);
ad1889_writel(chip, AD_DMA_WAVCC, count);
}
static inline void
ad1889_load_wave_interrupt_count(struct snd_ad1889 *chip, u32 count)
{
ad1889_writel(chip, AD_DMA_WAVIB, count);
ad1889_writel(chip, AD_DMA_WAVIC, count);
}
static void
ad1889_channel_reset(struct snd_ad1889 *chip, unsigned int channel)
{
u16 reg;
if (channel & AD_CHAN_WAV) {
reg = ad1889_readw(chip, AD_DS_WSMC) & ~AD_DS_WSMC_WAEN;
ad1889_writew(chip, AD_DS_WSMC, reg);
chip->wave.reg = reg;
reg = ad1889_readw(chip, AD_DMA_WAV);
reg &= AD_DMA_IM_DIS;
reg &= ~AD_DMA_LOOP;
ad1889_writew(chip, AD_DMA_WAV, reg);
ad1889_load_wave_buffer_address(chip, 0x0);
ad1889_load_wave_buffer_count(chip, 0x0);
ad1889_load_wave_interrupt_count(chip, 0x0);
ad1889_readw(chip, AD_DMA_WAV);
}
if (channel & AD_CHAN_ADC) {
reg = ad1889_readw(chip, AD_DS_RAMC) & ~AD_DS_RAMC_ADEN;
ad1889_writew(chip, AD_DS_RAMC, reg);
chip->ramc.reg = reg;
reg = ad1889_readw(chip, AD_DMA_ADC);
reg &= AD_DMA_IM_DIS;
reg &= ~AD_DMA_LOOP;
ad1889_writew(chip, AD_DMA_ADC, reg);
ad1889_load_adc_buffer_address(chip, 0x0);
ad1889_load_adc_buffer_count(chip, 0x0);
ad1889_load_adc_interrupt_count(chip, 0x0);
ad1889_readw(chip, AD_DMA_ADC);
}
}
static u16
snd_ad1889_ac97_read(struct snd_ac97 *ac97, unsigned short reg)
{
struct snd_ad1889 *chip = ac97->private_data;
return ad1889_readw(chip, AD_AC97_BASE + reg);
}
static void
snd_ad1889_ac97_write(struct snd_ac97 *ac97, unsigned short reg, unsigned short val)
{
struct snd_ad1889 *chip = ac97->private_data;
ad1889_writew(chip, AD_AC97_BASE + reg, val);
}
static int
snd_ad1889_ac97_ready(struct snd_ad1889 *chip)
{
int retry = 400;
while (!(ad1889_readw(chip, AD_AC97_ACIC) & AD_AC97_ACIC_ACRDY)
&& --retry)
mdelay(1);
if (!retry) {
snd_printk(KERN_ERR PFX "[%s] Link is not ready.\n",
__func__);
return -EIO;
}
ad1889_debug("[%s] ready after %d ms\n", __func__, 400 - retry);
return 0;
}
static int
snd_ad1889_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *hw_params)
{
return snd_pcm_lib_malloc_pages(substream,
params_buffer_bytes(hw_params));
}
static int
snd_ad1889_hw_free(struct snd_pcm_substream *substream)
{
return snd_pcm_lib_free_pages(substream);
}
static int
snd_ad1889_playback_open(struct snd_pcm_substream *ss)
{
struct snd_ad1889 *chip = snd_pcm_substream_chip(ss);
struct snd_pcm_runtime *rt = ss->runtime;
chip->psubs = ss;
rt->hw = snd_ad1889_playback_hw;
return 0;
}
static int
snd_ad1889_capture_open(struct snd_pcm_substream *ss)
{
struct snd_ad1889 *chip = snd_pcm_substream_chip(ss);
struct snd_pcm_runtime *rt = ss->runtime;
chip->csubs = ss;
rt->hw = snd_ad1889_capture_hw;
return 0;
}
static int
snd_ad1889_playback_close(struct snd_pcm_substream *ss)
{
struct snd_ad1889 *chip = snd_pcm_substream_chip(ss);
chip->psubs = NULL;
return 0;
}
static int
snd_ad1889_capture_close(struct snd_pcm_substream *ss)
{
struct snd_ad1889 *chip = snd_pcm_substream_chip(ss);
chip->csubs = NULL;
return 0;
}
static int
snd_ad1889_playback_prepare(struct snd_pcm_substream *ss)
{
struct snd_ad1889 *chip = snd_pcm_substream_chip(ss);
struct snd_pcm_runtime *rt = ss->runtime;
unsigned int size = snd_pcm_lib_buffer_bytes(ss);
unsigned int count = snd_pcm_lib_period_bytes(ss);
u16 reg;
ad1889_channel_reset(chip, AD_CHAN_WAV);
reg = ad1889_readw(chip, AD_DS_WSMC);
reg &= ~(AD_DS_WSMC_WA16 | AD_DS_WSMC_WAST);
if (snd_pcm_format_width(rt->format) == 16)
reg |= AD_DS_WSMC_WA16;
if (rt->channels > 1)
reg |= AD_DS_WSMC_WAST;
spin_lock_irq(&chip->lock);
chip->wave.size = size;
chip->wave.reg = reg;
chip->wave.addr = rt->dma_addr;
ad1889_writew(chip, AD_DS_WSMC, chip->wave.reg);
ad1889_writew(chip, AD_DS_WAS, rt->rate);
ad1889_load_wave_buffer_address(chip, chip->wave.addr);
ad1889_load_wave_buffer_count(chip, size);
ad1889_load_wave_interrupt_count(chip, count);
ad1889_readw(chip, AD_DS_WSMC);
spin_unlock_irq(&chip->lock);
ad1889_debug("prepare playback: addr = 0x%x, count = %u, "
"size = %u, reg = 0x%x, rate = %u\n", chip->wave.addr,
count, size, reg, rt->rate);
return 0;
}
static int
snd_ad1889_capture_prepare(struct snd_pcm_substream *ss)
{
struct snd_ad1889 *chip = snd_pcm_substream_chip(ss);
struct snd_pcm_runtime *rt = ss->runtime;
unsigned int size = snd_pcm_lib_buffer_bytes(ss);
unsigned int count = snd_pcm_lib_period_bytes(ss);
u16 reg;
ad1889_channel_reset(chip, AD_CHAN_ADC);
reg = ad1889_readw(chip, AD_DS_RAMC);
reg &= ~(AD_DS_RAMC_AD16 | AD_DS_RAMC_ADST);
if (snd_pcm_format_width(rt->format) == 16)
reg |= AD_DS_RAMC_AD16;
if (rt->channels > 1)
reg |= AD_DS_RAMC_ADST;
spin_lock_irq(&chip->lock);
chip->ramc.size = size;
chip->ramc.reg = reg;
chip->ramc.addr = rt->dma_addr;
ad1889_writew(chip, AD_DS_RAMC, chip->ramc.reg);
ad1889_load_adc_buffer_address(chip, chip->ramc.addr);
ad1889_load_adc_buffer_count(chip, size);
ad1889_load_adc_interrupt_count(chip, count);
ad1889_readw(chip, AD_DS_RAMC);
spin_unlock_irq(&chip->lock);
ad1889_debug("prepare capture: addr = 0x%x, count = %u, "
"size = %u, reg = 0x%x, rate = %u\n", chip->ramc.addr,
count, size, reg, rt->rate);
return 0;
}
static int
snd_ad1889_playback_trigger(struct snd_pcm_substream *ss, int cmd)
{
u16 wsmc;
struct snd_ad1889 *chip = snd_pcm_substream_chip(ss);
wsmc = ad1889_readw(chip, AD_DS_WSMC);
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
ad1889_writew(chip, AD_DMA_WAV, AD_DMA_LOOP | AD_DMA_IM_CNT);
wsmc |= AD_DS_WSMC_WAEN;
ad1889_writel(chip, AD_DMA_CHSS, AD_DMA_CHSS_WAVS);
ad1889_unmute(chip);
break;
case SNDRV_PCM_TRIGGER_STOP:
ad1889_mute(chip);
wsmc &= ~AD_DS_WSMC_WAEN;
break;
default:
snd_BUG();
return -EINVAL;
}
chip->wave.reg = wsmc;
ad1889_writew(chip, AD_DS_WSMC, wsmc);
ad1889_readw(chip, AD_DS_WSMC);
if (cmd == SNDRV_PCM_TRIGGER_STOP)
ad1889_channel_reset(chip, AD_CHAN_WAV);
return 0;
}
static int
snd_ad1889_capture_trigger(struct snd_pcm_substream *ss, int cmd)
{
u16 ramc;
struct snd_ad1889 *chip = snd_pcm_substream_chip(ss);
ramc = ad1889_readw(chip, AD_DS_RAMC);
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
ad1889_writew(chip, AD_DMA_ADC, AD_DMA_LOOP | AD_DMA_IM_CNT);
ramc |= AD_DS_RAMC_ADEN;
ad1889_writel(chip, AD_DMA_CHSS, AD_DMA_CHSS_ADCS);
break;
case SNDRV_PCM_TRIGGER_STOP:
ramc &= ~AD_DS_RAMC_ADEN;
break;
default:
return -EINVAL;
}
chip->ramc.reg = ramc;
ad1889_writew(chip, AD_DS_RAMC, ramc);
ad1889_readw(chip, AD_DS_RAMC);
if (cmd == SNDRV_PCM_TRIGGER_STOP)
ad1889_channel_reset(chip, AD_CHAN_ADC);
return 0;
}
static snd_pcm_uframes_t
snd_ad1889_playback_pointer(struct snd_pcm_substream *ss)
{
size_t ptr = 0;
struct snd_ad1889 *chip = snd_pcm_substream_chip(ss);
if (unlikely(!(chip->wave.reg & AD_DS_WSMC_WAEN)))
return 0;
ptr = ad1889_readl(chip, AD_DMA_WAVCA);
ptr -= chip->wave.addr;
if (snd_BUG_ON(ptr >= chip->wave.size))
return 0;
return bytes_to_frames(ss->runtime, ptr);
}
static snd_pcm_uframes_t
snd_ad1889_capture_pointer(struct snd_pcm_substream *ss)
{
size_t ptr = 0;
struct snd_ad1889 *chip = snd_pcm_substream_chip(ss);
if (unlikely(!(chip->ramc.reg & AD_DS_RAMC_ADEN)))
return 0;
ptr = ad1889_readl(chip, AD_DMA_ADCCA);
ptr -= chip->ramc.addr;
if (snd_BUG_ON(ptr >= chip->ramc.size))
return 0;
return bytes_to_frames(ss->runtime, ptr);
}
static irqreturn_t
snd_ad1889_interrupt(int irq, void *dev_id)
{
unsigned long st;
struct snd_ad1889 *chip = dev_id;
st = ad1889_readl(chip, AD_DMA_DISR);
ad1889_writel(chip, AD_DMA_DISR, st);
st &= AD_INTR_MASK;
if (unlikely(!st))
return IRQ_NONE;
if (st & (AD_DMA_DISR_PMAI|AD_DMA_DISR_PTAI))
ad1889_debug("Unexpected master or target abort interrupt!\n");
if ((st & AD_DMA_DISR_WAVI) && chip->psubs)
snd_pcm_period_elapsed(chip->psubs);
if ((st & AD_DMA_DISR_ADCI) && chip->csubs)
snd_pcm_period_elapsed(chip->csubs);
return IRQ_HANDLED;
}
static int
snd_ad1889_pcm_init(struct snd_ad1889 *chip, int device, struct snd_pcm **rpcm)
{
int err;
struct snd_pcm *pcm;
if (rpcm)
*rpcm = NULL;
err = snd_pcm_new(chip->card, chip->card->driver, device, 1, 1, &pcm);
if (err < 0)
return err;
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_PLAYBACK,
&snd_ad1889_playback_ops);
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_CAPTURE,
&snd_ad1889_capture_ops);
pcm->private_data = chip;
pcm->info_flags = 0;
strcpy(pcm->name, chip->card->shortname);
chip->pcm = pcm;
chip->psubs = NULL;
chip->csubs = NULL;
err = snd_pcm_lib_preallocate_pages_for_all(pcm, SNDRV_DMA_TYPE_DEV,
snd_dma_pci_data(chip->pci),
BUFFER_BYTES_MAX / 2,
BUFFER_BYTES_MAX);
if (err < 0) {
snd_printk(KERN_ERR PFX "buffer allocation error: %d\n", err);
return err;
}
if (rpcm)
*rpcm = pcm;
return 0;
}
static void
snd_ad1889_proc_read(struct snd_info_entry *entry, struct snd_info_buffer *buffer)
{
struct snd_ad1889 *chip = entry->private_data;
u16 reg;
int tmp;
reg = ad1889_readw(chip, AD_DS_WSMC);
snd_iprintf(buffer, "Wave output: %s\n",
(reg & AD_DS_WSMC_WAEN) ? "enabled" : "disabled");
snd_iprintf(buffer, "Wave Channels: %s\n",
(reg & AD_DS_WSMC_WAST) ? "stereo" : "mono");
snd_iprintf(buffer, "Wave Quality: %d-bit linear\n",
(reg & AD_DS_WSMC_WA16) ? 16 : 8);
tmp = (reg & AD_DS_WSMC_WARQ) ?
(((reg & AD_DS_WSMC_WARQ >> 12) & 0x01) ? 12 : 18) : 4;
tmp /= (reg & AD_DS_WSMC_WAST) ? 2 : 1;
snd_iprintf(buffer, "Wave FIFO: %d %s words\n\n", tmp,
(reg & AD_DS_WSMC_WAST) ? "stereo" : "mono");
snd_iprintf(buffer, "Synthesis output: %s\n",
reg & AD_DS_WSMC_SYEN ? "enabled" : "disabled");
tmp = (reg & AD_DS_WSMC_SYRQ) ?
(((reg & AD_DS_WSMC_SYRQ >> 4) & 0x01) ? 12 : 18) : 4;
tmp /= (reg & AD_DS_WSMC_WAST) ? 2 : 1;
snd_iprintf(buffer, "Synthesis FIFO: %d %s words\n\n", tmp,
(reg & AD_DS_WSMC_WAST) ? "stereo" : "mono");
reg = ad1889_readw(chip, AD_DS_RAMC);
snd_iprintf(buffer, "ADC input: %s\n",
(reg & AD_DS_RAMC_ADEN) ? "enabled" : "disabled");
snd_iprintf(buffer, "ADC Channels: %s\n",
(reg & AD_DS_RAMC_ADST) ? "stereo" : "mono");
snd_iprintf(buffer, "ADC Quality: %d-bit linear\n",
(reg & AD_DS_RAMC_AD16) ? 16 : 8);
tmp = (reg & AD_DS_RAMC_ACRQ) ?
(((reg & AD_DS_RAMC_ACRQ >> 4) & 0x01) ? 12 : 18) : 4;
tmp /= (reg & AD_DS_RAMC_ADST) ? 2 : 1;
snd_iprintf(buffer, "ADC FIFO: %d %s words\n\n", tmp,
(reg & AD_DS_RAMC_ADST) ? "stereo" : "mono");
snd_iprintf(buffer, "Resampler input: %s\n",
reg & AD_DS_RAMC_REEN ? "enabled" : "disabled");
tmp = (reg & AD_DS_RAMC_RERQ) ?
(((reg & AD_DS_RAMC_RERQ >> 12) & 0x01) ? 12 : 18) : 4;
tmp /= (reg & AD_DS_RAMC_ADST) ? 2 : 1;
snd_iprintf(buffer, "Resampler FIFO: %d %s words\n\n", tmp,
(reg & AD_DS_WSMC_WAST) ? "stereo" : "mono");
reg = ad1889_readw(chip, AD_DS_WADA);
snd_iprintf(buffer, "Left: %s, -%d dB\n",
(reg & AD_DS_WADA_LWAM) ? "mute" : "unmute",
((reg & AD_DS_WADA_LWAA) >> 8) * 3);
reg = ad1889_readw(chip, AD_DS_WADA);
snd_iprintf(buffer, "Right: %s, -%d dB\n",
(reg & AD_DS_WADA_RWAM) ? "mute" : "unmute",
(reg & AD_DS_WADA_RWAA) * 3);
reg = ad1889_readw(chip, AD_DS_WAS);
snd_iprintf(buffer, "Wave samplerate: %u Hz\n", reg);
reg = ad1889_readw(chip, AD_DS_RES);
snd_iprintf(buffer, "Resampler samplerate: %u Hz\n", reg);
}
static void
snd_ad1889_proc_init(struct snd_ad1889 *chip)
{
struct snd_info_entry *entry;
if (!snd_card_proc_new(chip->card, chip->card->driver, &entry))
snd_info_set_text_ops(entry, chip, snd_ad1889_proc_read);
}
static void
snd_ad1889_ac97_xinit(struct snd_ad1889 *chip)
{
u16 reg;
reg = ad1889_readw(chip, AD_AC97_ACIC);
reg |= AD_AC97_ACIC_ACRD;
ad1889_writew(chip, AD_AC97_ACIC, reg);
ad1889_readw(chip, AD_AC97_ACIC);
udelay(10);
reg |= AD_AC97_ACIC_ACIE;
ad1889_writew(chip, AD_AC97_ACIC, reg);
snd_ad1889_ac97_ready(chip);
reg = ad1889_readw(chip, AD_AC97_ACIC);
reg |= AD_AC97_ACIC_ASOE | AD_AC97_ACIC_VSRM;
ad1889_writew(chip, AD_AC97_ACIC, reg);
ad1889_readw(chip, AD_AC97_ACIC);
}
static void
snd_ad1889_ac97_bus_free(struct snd_ac97_bus *bus)
{
struct snd_ad1889 *chip = bus->private_data;
chip->ac97_bus = NULL;
}
static void
snd_ad1889_ac97_free(struct snd_ac97 *ac97)
{
struct snd_ad1889 *chip = ac97->private_data;
chip->ac97 = NULL;
}
static int
snd_ad1889_ac97_init(struct snd_ad1889 *chip, const char *quirk_override)
{
int err;
struct snd_ac97_template ac97;
static struct snd_ac97_bus_ops ops = {
.write = snd_ad1889_ac97_write,
.read = snd_ad1889_ac97_read,
};
snd_ad1889_ac97_xinit(chip);
err = snd_ac97_bus(chip->card, 0, &ops, chip, &chip->ac97_bus);
if (err < 0)
return err;
chip->ac97_bus->private_free = snd_ad1889_ac97_bus_free;
memset(&ac97, 0, sizeof(ac97));
ac97.private_data = chip;
ac97.private_free = snd_ad1889_ac97_free;
ac97.pci = chip->pci;
err = snd_ac97_mixer(chip->ac97_bus, &ac97, &chip->ac97);
if (err < 0)
return err;
snd_ac97_tune_hardware(chip->ac97, ac97_quirks, quirk_override);
return 0;
}
static int
snd_ad1889_free(struct snd_ad1889 *chip)
{
if (chip->irq < 0)
goto skip_hw;
spin_lock_irq(&chip->lock);
ad1889_mute(chip);
ad1889_channel_reset(chip, AD_CHAN_WAV | AD_CHAN_ADC);
ad1889_writel(chip, AD_DMA_DISR, AD_DMA_DISR_PTAI | AD_DMA_DISR_PMAI);
ad1889_readl(chip, AD_DMA_DISR);
spin_unlock_irq(&chip->lock);
if (chip->irq >= 0)
free_irq(chip->irq, chip);
skip_hw:
if (chip->iobase)
iounmap(chip->iobase);
pci_release_regions(chip->pci);
pci_disable_device(chip->pci);
kfree(chip);
return 0;
}
static int
snd_ad1889_dev_free(struct snd_device *device)
{
struct snd_ad1889 *chip = device->device_data;
return snd_ad1889_free(chip);
}
static int
snd_ad1889_init(struct snd_ad1889 *chip)
{
ad1889_writew(chip, AD_DS_CCS, AD_DS_CCS_CLKEN);
ad1889_readw(chip, AD_DS_CCS);
mdelay(10);
ad1889_writel(chip, AD_DMA_DISR, AD_DMA_DISR_PMAE | AD_DMA_DISR_PTAE);
return 0;
}
static int
snd_ad1889_create(struct snd_card *card,
struct pci_dev *pci,
struct snd_ad1889 **rchip)
{
int err;
struct snd_ad1889 *chip;
static struct snd_device_ops ops = {
.dev_free = snd_ad1889_dev_free,
};
*rchip = NULL;
if ((err = pci_enable_device(pci)) < 0)
return err;
if (pci_set_dma_mask(pci, DMA_BIT_MASK(32)) < 0 ||
pci_set_consistent_dma_mask(pci, DMA_BIT_MASK(32)) < 0) {
printk(KERN_ERR PFX "error setting 32-bit DMA mask.\n");
pci_disable_device(pci);
return -ENXIO;
}
if ((chip = kzalloc(sizeof(*chip), GFP_KERNEL)) == NULL) {
pci_disable_device(pci);
return -ENOMEM;
}
chip->card = card;
card->private_data = chip;
chip->pci = pci;
chip->irq = -1;
if ((err = pci_request_regions(pci, card->driver)) < 0)
goto free_and_ret;
chip->bar = pci_resource_start(pci, 0);
chip->iobase = pci_ioremap_bar(pci, 0);
if (chip->iobase == NULL) {
printk(KERN_ERR PFX "unable to reserve region.\n");
err = -EBUSY;
goto free_and_ret;
}
pci_set_master(pci);
spin_lock_init(&chip->lock);
if (request_irq(pci->irq, snd_ad1889_interrupt,
IRQF_SHARED, KBUILD_MODNAME, chip)) {
printk(KERN_ERR PFX "cannot obtain IRQ %d\n", pci->irq);
snd_ad1889_free(chip);
return -EBUSY;
}
chip->irq = pci->irq;
synchronize_irq(chip->irq);
if ((err = snd_ad1889_init(chip)) < 0) {
snd_ad1889_free(chip);
return err;
}
if ((err = snd_device_new(card, SNDRV_DEV_LOWLEVEL, chip, &ops)) < 0) {
snd_ad1889_free(chip);
return err;
}
snd_card_set_dev(card, &pci->dev);
*rchip = chip;
return 0;
free_and_ret:
kfree(chip);
pci_disable_device(pci);
return err;
}
static int
snd_ad1889_probe(struct pci_dev *pci,
const struct pci_device_id *pci_id)
{
int err;
static int devno;
struct snd_card *card;
struct snd_ad1889 *chip;
if (devno >= SNDRV_CARDS)
return -ENODEV;
if (!enable[devno]) {
devno++;
return -ENOENT;
}
err = snd_card_create(index[devno], id[devno], THIS_MODULE, 0, &card);
if (err < 0)
return err;
strcpy(card->driver, "AD1889");
strcpy(card->shortname, "Analog Devices AD1889");
err = snd_ad1889_create(card, pci, &chip);
if (err < 0)
goto free_and_ret;
sprintf(card->longname, "%s at 0x%lx irq %i",
card->shortname, chip->bar, chip->irq);
err = snd_ad1889_ac97_init(chip, ac97_quirk[devno]);
if (err < 0)
goto free_and_ret;
err = snd_ad1889_pcm_init(chip, 0, NULL);
if (err < 0)
goto free_and_ret;
snd_ad1889_proc_init(chip);
err = snd_card_register(card);
if (err < 0)
goto free_and_ret;
pci_set_drvdata(pci, card);
devno++;
return 0;
free_and_ret:
snd_card_free(card);
return err;
}
static void
snd_ad1889_remove(struct pci_dev *pci)
{
snd_card_free(pci_get_drvdata(pci));
}
