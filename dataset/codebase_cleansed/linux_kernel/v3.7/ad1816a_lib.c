static inline int snd_ad1816a_busy_wait(struct snd_ad1816a *chip)
{
int timeout;
for (timeout = 1000; timeout-- > 0; udelay(10))
if (inb(AD1816A_REG(AD1816A_CHIP_STATUS)) & AD1816A_READY)
return 0;
snd_printk(KERN_WARNING "chip busy.\n");
return -EBUSY;
}
static inline unsigned char snd_ad1816a_in(struct snd_ad1816a *chip, unsigned char reg)
{
snd_ad1816a_busy_wait(chip);
return inb(AD1816A_REG(reg));
}
static inline void snd_ad1816a_out(struct snd_ad1816a *chip, unsigned char reg,
unsigned char value)
{
snd_ad1816a_busy_wait(chip);
outb(value, AD1816A_REG(reg));
}
static inline void snd_ad1816a_out_mask(struct snd_ad1816a *chip, unsigned char reg,
unsigned char mask, unsigned char value)
{
snd_ad1816a_out(chip, reg,
(value & mask) | (snd_ad1816a_in(chip, reg) & ~mask));
}
static unsigned short snd_ad1816a_read(struct snd_ad1816a *chip, unsigned char reg)
{
snd_ad1816a_out(chip, AD1816A_INDIR_ADDR, reg & 0x3f);
return snd_ad1816a_in(chip, AD1816A_INDIR_DATA_LOW) |
(snd_ad1816a_in(chip, AD1816A_INDIR_DATA_HIGH) << 8);
}
static void snd_ad1816a_write(struct snd_ad1816a *chip, unsigned char reg,
unsigned short value)
{
snd_ad1816a_out(chip, AD1816A_INDIR_ADDR, reg & 0x3f);
snd_ad1816a_out(chip, AD1816A_INDIR_DATA_LOW, value & 0xff);
snd_ad1816a_out(chip, AD1816A_INDIR_DATA_HIGH, (value >> 8) & 0xff);
}
static void snd_ad1816a_write_mask(struct snd_ad1816a *chip, unsigned char reg,
unsigned short mask, unsigned short value)
{
snd_ad1816a_write(chip, reg,
(value & mask) | (snd_ad1816a_read(chip, reg) & ~mask));
}
static unsigned char snd_ad1816a_get_format(struct snd_ad1816a *chip,
unsigned int format, int channels)
{
unsigned char retval = AD1816A_FMT_LINEAR_8;
switch (format) {
case SNDRV_PCM_FORMAT_MU_LAW:
retval = AD1816A_FMT_ULAW_8;
break;
case SNDRV_PCM_FORMAT_A_LAW:
retval = AD1816A_FMT_ALAW_8;
break;
case SNDRV_PCM_FORMAT_S16_LE:
retval = AD1816A_FMT_LINEAR_16_LIT;
break;
case SNDRV_PCM_FORMAT_S16_BE:
retval = AD1816A_FMT_LINEAR_16_BIG;
}
return (channels > 1) ? (retval | AD1816A_FMT_STEREO) : retval;
}
static int snd_ad1816a_open(struct snd_ad1816a *chip, unsigned int mode)
{
unsigned long flags;
spin_lock_irqsave(&chip->lock, flags);
if (chip->mode & mode) {
spin_unlock_irqrestore(&chip->lock, flags);
return -EAGAIN;
}
switch ((mode &= AD1816A_MODE_OPEN)) {
case AD1816A_MODE_PLAYBACK:
snd_ad1816a_out_mask(chip, AD1816A_INTERRUPT_STATUS,
AD1816A_PLAYBACK_IRQ_PENDING, 0x00);
snd_ad1816a_write_mask(chip, AD1816A_INTERRUPT_ENABLE,
AD1816A_PLAYBACK_IRQ_ENABLE, 0xffff);
break;
case AD1816A_MODE_CAPTURE:
snd_ad1816a_out_mask(chip, AD1816A_INTERRUPT_STATUS,
AD1816A_CAPTURE_IRQ_PENDING, 0x00);
snd_ad1816a_write_mask(chip, AD1816A_INTERRUPT_ENABLE,
AD1816A_CAPTURE_IRQ_ENABLE, 0xffff);
break;
case AD1816A_MODE_TIMER:
snd_ad1816a_out_mask(chip, AD1816A_INTERRUPT_STATUS,
AD1816A_TIMER_IRQ_PENDING, 0x00);
snd_ad1816a_write_mask(chip, AD1816A_INTERRUPT_ENABLE,
AD1816A_TIMER_IRQ_ENABLE, 0xffff);
}
chip->mode |= mode;
spin_unlock_irqrestore(&chip->lock, flags);
return 0;
}
static void snd_ad1816a_close(struct snd_ad1816a *chip, unsigned int mode)
{
unsigned long flags;
spin_lock_irqsave(&chip->lock, flags);
switch ((mode &= AD1816A_MODE_OPEN)) {
case AD1816A_MODE_PLAYBACK:
snd_ad1816a_out_mask(chip, AD1816A_INTERRUPT_STATUS,
AD1816A_PLAYBACK_IRQ_PENDING, 0x00);
snd_ad1816a_write_mask(chip, AD1816A_INTERRUPT_ENABLE,
AD1816A_PLAYBACK_IRQ_ENABLE, 0x0000);
break;
case AD1816A_MODE_CAPTURE:
snd_ad1816a_out_mask(chip, AD1816A_INTERRUPT_STATUS,
AD1816A_CAPTURE_IRQ_PENDING, 0x00);
snd_ad1816a_write_mask(chip, AD1816A_INTERRUPT_ENABLE,
AD1816A_CAPTURE_IRQ_ENABLE, 0x0000);
break;
case AD1816A_MODE_TIMER:
snd_ad1816a_out_mask(chip, AD1816A_INTERRUPT_STATUS,
AD1816A_TIMER_IRQ_PENDING, 0x00);
snd_ad1816a_write_mask(chip, AD1816A_INTERRUPT_ENABLE,
AD1816A_TIMER_IRQ_ENABLE, 0x0000);
}
if (!((chip->mode &= ~mode) & AD1816A_MODE_OPEN))
chip->mode = 0;
spin_unlock_irqrestore(&chip->lock, flags);
}
static int snd_ad1816a_trigger(struct snd_ad1816a *chip, unsigned char what,
int channel, int cmd, int iscapture)
{
int error = 0;
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
case SNDRV_PCM_TRIGGER_STOP:
spin_lock(&chip->lock);
cmd = (cmd == SNDRV_PCM_TRIGGER_START) ? 0xff: 0x00;
if (! iscapture)
snd_ad1816a_out_mask(chip, AD1816A_PLAYBACK_CONFIG,
AD1816A_PLAYBACK_ENABLE, cmd);
else
snd_ad1816a_out_mask(chip, AD1816A_CAPTURE_CONFIG,
AD1816A_CAPTURE_ENABLE, cmd);
spin_unlock(&chip->lock);
break;
default:
snd_printk(KERN_WARNING "invalid trigger mode 0x%x.\n", what);
error = -EINVAL;
}
return error;
}
static int snd_ad1816a_playback_trigger(struct snd_pcm_substream *substream, int cmd)
{
struct snd_ad1816a *chip = snd_pcm_substream_chip(substream);
return snd_ad1816a_trigger(chip, AD1816A_PLAYBACK_ENABLE,
SNDRV_PCM_STREAM_PLAYBACK, cmd, 0);
}
static int snd_ad1816a_capture_trigger(struct snd_pcm_substream *substream, int cmd)
{
struct snd_ad1816a *chip = snd_pcm_substream_chip(substream);
return snd_ad1816a_trigger(chip, AD1816A_CAPTURE_ENABLE,
SNDRV_PCM_STREAM_CAPTURE, cmd, 1);
}
static int snd_ad1816a_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *hw_params)
{
return snd_pcm_lib_malloc_pages(substream, params_buffer_bytes(hw_params));
}
static int snd_ad1816a_hw_free(struct snd_pcm_substream *substream)
{
return snd_pcm_lib_free_pages(substream);
}
static int snd_ad1816a_playback_prepare(struct snd_pcm_substream *substream)
{
struct snd_ad1816a *chip = snd_pcm_substream_chip(substream);
unsigned long flags;
struct snd_pcm_runtime *runtime = substream->runtime;
unsigned int size, rate;
spin_lock_irqsave(&chip->lock, flags);
chip->p_dma_size = size = snd_pcm_lib_buffer_bytes(substream);
snd_ad1816a_out_mask(chip, AD1816A_PLAYBACK_CONFIG,
AD1816A_PLAYBACK_ENABLE | AD1816A_PLAYBACK_PIO, 0x00);
snd_dma_program(chip->dma1, runtime->dma_addr, size,
DMA_MODE_WRITE | DMA_AUTOINIT);
rate = runtime->rate;
if (chip->clock_freq)
rate = (rate * 33000) / chip->clock_freq;
snd_ad1816a_write(chip, AD1816A_PLAYBACK_SAMPLE_RATE, rate);
snd_ad1816a_out_mask(chip, AD1816A_PLAYBACK_CONFIG,
AD1816A_FMT_ALL | AD1816A_FMT_STEREO,
snd_ad1816a_get_format(chip, runtime->format,
runtime->channels));
snd_ad1816a_write(chip, AD1816A_PLAYBACK_BASE_COUNT,
snd_pcm_lib_period_bytes(substream) / 4 - 1);
spin_unlock_irqrestore(&chip->lock, flags);
return 0;
}
static int snd_ad1816a_capture_prepare(struct snd_pcm_substream *substream)
{
struct snd_ad1816a *chip = snd_pcm_substream_chip(substream);
unsigned long flags;
struct snd_pcm_runtime *runtime = substream->runtime;
unsigned int size, rate;
spin_lock_irqsave(&chip->lock, flags);
chip->c_dma_size = size = snd_pcm_lib_buffer_bytes(substream);
snd_ad1816a_out_mask(chip, AD1816A_CAPTURE_CONFIG,
AD1816A_CAPTURE_ENABLE | AD1816A_CAPTURE_PIO, 0x00);
snd_dma_program(chip->dma2, runtime->dma_addr, size,
DMA_MODE_READ | DMA_AUTOINIT);
rate = runtime->rate;
if (chip->clock_freq)
rate = (rate * 33000) / chip->clock_freq;
snd_ad1816a_write(chip, AD1816A_CAPTURE_SAMPLE_RATE, rate);
snd_ad1816a_out_mask(chip, AD1816A_CAPTURE_CONFIG,
AD1816A_FMT_ALL | AD1816A_FMT_STEREO,
snd_ad1816a_get_format(chip, runtime->format,
runtime->channels));
snd_ad1816a_write(chip, AD1816A_CAPTURE_BASE_COUNT,
snd_pcm_lib_period_bytes(substream) / 4 - 1);
spin_unlock_irqrestore(&chip->lock, flags);
return 0;
}
static snd_pcm_uframes_t snd_ad1816a_playback_pointer(struct snd_pcm_substream *substream)
{
struct snd_ad1816a *chip = snd_pcm_substream_chip(substream);
size_t ptr;
if (!(chip->mode & AD1816A_MODE_PLAYBACK))
return 0;
ptr = snd_dma_pointer(chip->dma1, chip->p_dma_size);
return bytes_to_frames(substream->runtime, ptr);
}
static snd_pcm_uframes_t snd_ad1816a_capture_pointer(struct snd_pcm_substream *substream)
{
struct snd_ad1816a *chip = snd_pcm_substream_chip(substream);
size_t ptr;
if (!(chip->mode & AD1816A_MODE_CAPTURE))
return 0;
ptr = snd_dma_pointer(chip->dma2, chip->c_dma_size);
return bytes_to_frames(substream->runtime, ptr);
}
static irqreturn_t snd_ad1816a_interrupt(int irq, void *dev_id)
{
struct snd_ad1816a *chip = dev_id;
unsigned char status;
spin_lock(&chip->lock);
status = snd_ad1816a_in(chip, AD1816A_INTERRUPT_STATUS);
spin_unlock(&chip->lock);
if ((status & AD1816A_PLAYBACK_IRQ_PENDING) && chip->playback_substream)
snd_pcm_period_elapsed(chip->playback_substream);
if ((status & AD1816A_CAPTURE_IRQ_PENDING) && chip->capture_substream)
snd_pcm_period_elapsed(chip->capture_substream);
if ((status & AD1816A_TIMER_IRQ_PENDING) && chip->timer)
snd_timer_interrupt(chip->timer, chip->timer->sticks);
spin_lock(&chip->lock);
snd_ad1816a_out(chip, AD1816A_INTERRUPT_STATUS, 0x00);
spin_unlock(&chip->lock);
return IRQ_HANDLED;
}
static int snd_ad1816a_timer_close(struct snd_timer *timer)
{
struct snd_ad1816a *chip = snd_timer_chip(timer);
snd_ad1816a_close(chip, AD1816A_MODE_TIMER);
return 0;
}
static int snd_ad1816a_timer_open(struct snd_timer *timer)
{
struct snd_ad1816a *chip = snd_timer_chip(timer);
snd_ad1816a_open(chip, AD1816A_MODE_TIMER);
return 0;
}
static unsigned long snd_ad1816a_timer_resolution(struct snd_timer *timer)
{
if (snd_BUG_ON(!timer))
return 0;
return 10000;
}
static int snd_ad1816a_timer_start(struct snd_timer *timer)
{
unsigned short bits;
unsigned long flags;
struct snd_ad1816a *chip = snd_timer_chip(timer);
spin_lock_irqsave(&chip->lock, flags);
bits = snd_ad1816a_read(chip, AD1816A_INTERRUPT_ENABLE);
if (!(bits & AD1816A_TIMER_ENABLE)) {
snd_ad1816a_write(chip, AD1816A_TIMER_BASE_COUNT,
timer->sticks & 0xffff);
snd_ad1816a_write_mask(chip, AD1816A_INTERRUPT_ENABLE,
AD1816A_TIMER_ENABLE, 0xffff);
}
spin_unlock_irqrestore(&chip->lock, flags);
return 0;
}
static int snd_ad1816a_timer_stop(struct snd_timer *timer)
{
unsigned long flags;
struct snd_ad1816a *chip = snd_timer_chip(timer);
spin_lock_irqsave(&chip->lock, flags);
snd_ad1816a_write_mask(chip, AD1816A_INTERRUPT_ENABLE,
AD1816A_TIMER_ENABLE, 0x0000);
spin_unlock_irqrestore(&chip->lock, flags);
return 0;
}
static int snd_ad1816a_playback_open(struct snd_pcm_substream *substream)
{
struct snd_ad1816a *chip = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
int error;
if ((error = snd_ad1816a_open(chip, AD1816A_MODE_PLAYBACK)) < 0)
return error;
runtime->hw = snd_ad1816a_playback;
snd_pcm_limit_isa_dma_size(chip->dma1, &runtime->hw.buffer_bytes_max);
snd_pcm_limit_isa_dma_size(chip->dma1, &runtime->hw.period_bytes_max);
chip->playback_substream = substream;
return 0;
}
static int snd_ad1816a_capture_open(struct snd_pcm_substream *substream)
{
struct snd_ad1816a *chip = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
int error;
if ((error = snd_ad1816a_open(chip, AD1816A_MODE_CAPTURE)) < 0)
return error;
runtime->hw = snd_ad1816a_capture;
snd_pcm_limit_isa_dma_size(chip->dma2, &runtime->hw.buffer_bytes_max);
snd_pcm_limit_isa_dma_size(chip->dma2, &runtime->hw.period_bytes_max);
chip->capture_substream = substream;
return 0;
}
static int snd_ad1816a_playback_close(struct snd_pcm_substream *substream)
{
struct snd_ad1816a *chip = snd_pcm_substream_chip(substream);
chip->playback_substream = NULL;
snd_ad1816a_close(chip, AD1816A_MODE_PLAYBACK);
return 0;
}
static int snd_ad1816a_capture_close(struct snd_pcm_substream *substream)
{
struct snd_ad1816a *chip = snd_pcm_substream_chip(substream);
chip->capture_substream = NULL;
snd_ad1816a_close(chip, AD1816A_MODE_CAPTURE);
return 0;
}
static void snd_ad1816a_init(struct snd_ad1816a *chip)
{
unsigned long flags;
spin_lock_irqsave(&chip->lock, flags);
snd_ad1816a_out(chip, AD1816A_INTERRUPT_STATUS, 0x00);
snd_ad1816a_out_mask(chip, AD1816A_PLAYBACK_CONFIG,
AD1816A_PLAYBACK_ENABLE | AD1816A_PLAYBACK_PIO, 0x00);
snd_ad1816a_out_mask(chip, AD1816A_CAPTURE_CONFIG,
AD1816A_CAPTURE_ENABLE | AD1816A_CAPTURE_PIO, 0x00);
snd_ad1816a_write(chip, AD1816A_INTERRUPT_ENABLE, 0x0000);
snd_ad1816a_write_mask(chip, AD1816A_CHIP_CONFIG,
AD1816A_CAPTURE_NOT_EQUAL | AD1816A_WSS_ENABLE, 0xffff);
snd_ad1816a_write(chip, AD1816A_DSP_CONFIG, 0x0000);
snd_ad1816a_write(chip, AD1816A_POWERDOWN_CTRL, 0x0000);
spin_unlock_irqrestore(&chip->lock, flags);
}
void snd_ad1816a_suspend(struct snd_ad1816a *chip)
{
int reg;
unsigned long flags;
snd_pcm_suspend_all(chip->pcm);
spin_lock_irqsave(&chip->lock, flags);
for (reg = 0; reg < 48; reg++)
chip->image[reg] = snd_ad1816a_read(chip, reg);
spin_unlock_irqrestore(&chip->lock, flags);
}
void snd_ad1816a_resume(struct snd_ad1816a *chip)
{
int reg;
unsigned long flags;
snd_ad1816a_init(chip);
spin_lock_irqsave(&chip->lock, flags);
for (reg = 0; reg < 48; reg++)
snd_ad1816a_write(chip, reg, chip->image[reg]);
spin_unlock_irqrestore(&chip->lock, flags);
}
static int __devinit snd_ad1816a_probe(struct snd_ad1816a *chip)
{
unsigned long flags;
spin_lock_irqsave(&chip->lock, flags);
switch (chip->version = snd_ad1816a_read(chip, AD1816A_VERSION_ID)) {
case 0:
chip->hardware = AD1816A_HW_AD1815;
break;
case 1:
chip->hardware = AD1816A_HW_AD18MAX10;
break;
case 3:
chip->hardware = AD1816A_HW_AD1816A;
break;
default:
chip->hardware = AD1816A_HW_AUTO;
}
spin_unlock_irqrestore(&chip->lock, flags);
return 0;
}
static int snd_ad1816a_free(struct snd_ad1816a *chip)
{
release_and_free_resource(chip->res_port);
if (chip->irq >= 0)
free_irq(chip->irq, (void *) chip);
if (chip->dma1 >= 0) {
snd_dma_disable(chip->dma1);
free_dma(chip->dma1);
}
if (chip->dma2 >= 0) {
snd_dma_disable(chip->dma2);
free_dma(chip->dma2);
}
return 0;
}
static int snd_ad1816a_dev_free(struct snd_device *device)
{
struct snd_ad1816a *chip = device->device_data;
return snd_ad1816a_free(chip);
}
static const char __devinit *snd_ad1816a_chip_id(struct snd_ad1816a *chip)
{
switch (chip->hardware) {
case AD1816A_HW_AD1816A: return "AD1816A";
case AD1816A_HW_AD1815: return "AD1815";
case AD1816A_HW_AD18MAX10: return "AD18max10";
default:
snd_printk(KERN_WARNING "Unknown chip version %d:%d.\n",
chip->version, chip->hardware);
return "AD1816A - unknown";
}
}
int __devinit snd_ad1816a_create(struct snd_card *card,
unsigned long port, int irq, int dma1, int dma2,
struct snd_ad1816a *chip)
{
static struct snd_device_ops ops = {
.dev_free = snd_ad1816a_dev_free,
};
int error;
chip->irq = -1;
chip->dma1 = -1;
chip->dma2 = -1;
if ((chip->res_port = request_region(port, 16, "AD1816A")) == NULL) {
snd_printk(KERN_ERR "ad1816a: can't grab port 0x%lx\n", port);
snd_ad1816a_free(chip);
return -EBUSY;
}
if (request_irq(irq, snd_ad1816a_interrupt, 0, "AD1816A", (void *) chip)) {
snd_printk(KERN_ERR "ad1816a: can't grab IRQ %d\n", irq);
snd_ad1816a_free(chip);
return -EBUSY;
}
chip->irq = irq;
if (request_dma(dma1, "AD1816A - 1")) {
snd_printk(KERN_ERR "ad1816a: can't grab DMA1 %d\n", dma1);
snd_ad1816a_free(chip);
return -EBUSY;
}
chip->dma1 = dma1;
if (request_dma(dma2, "AD1816A - 2")) {
snd_printk(KERN_ERR "ad1816a: can't grab DMA2 %d\n", dma2);
snd_ad1816a_free(chip);
return -EBUSY;
}
chip->dma2 = dma2;
chip->card = card;
chip->port = port;
spin_lock_init(&chip->lock);
if ((error = snd_ad1816a_probe(chip))) {
snd_ad1816a_free(chip);
return error;
}
snd_ad1816a_init(chip);
if ((error = snd_device_new(card, SNDRV_DEV_LOWLEVEL, chip, &ops)) < 0) {
snd_ad1816a_free(chip);
return error;
}
return 0;
}
int __devinit snd_ad1816a_pcm(struct snd_ad1816a *chip, int device, struct snd_pcm **rpcm)
{
int error;
struct snd_pcm *pcm;
if ((error = snd_pcm_new(chip->card, "AD1816A", device, 1, 1, &pcm)))
return error;
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_PLAYBACK, &snd_ad1816a_playback_ops);
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_CAPTURE, &snd_ad1816a_capture_ops);
pcm->private_data = chip;
pcm->info_flags = (chip->dma1 == chip->dma2 ) ? SNDRV_PCM_INFO_JOINT_DUPLEX : 0;
strcpy(pcm->name, snd_ad1816a_chip_id(chip));
snd_ad1816a_init(chip);
snd_pcm_lib_preallocate_pages_for_all(pcm, SNDRV_DMA_TYPE_DEV,
snd_dma_isa_data(),
64*1024, chip->dma1 > 3 || chip->dma2 > 3 ? 128*1024 : 64*1024);
chip->pcm = pcm;
if (rpcm)
*rpcm = pcm;
return 0;
}
int __devinit snd_ad1816a_timer(struct snd_ad1816a *chip, int device, struct snd_timer **rtimer)
{
struct snd_timer *timer;
struct snd_timer_id tid;
int error;
tid.dev_class = SNDRV_TIMER_CLASS_CARD;
tid.dev_sclass = SNDRV_TIMER_SCLASS_NONE;
tid.card = chip->card->number;
tid.device = device;
tid.subdevice = 0;
if ((error = snd_timer_new(chip->card, "AD1816A", &tid, &timer)) < 0)
return error;
strcpy(timer->name, snd_ad1816a_chip_id(chip));
timer->private_data = chip;
chip->timer = timer;
timer->hw = snd_ad1816a_timer_table;
if (rtimer)
*rtimer = timer;
return 0;
}
static int snd_ad1816a_info_mux(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_info *uinfo)
{
static char *texts[8] = {
"Line", "Mix", "CD", "Synth", "Video",
"Mic", "Phone",
};
uinfo->type = SNDRV_CTL_ELEM_TYPE_ENUMERATED;
uinfo->count = 2;
uinfo->value.enumerated.items = 7;
if (uinfo->value.enumerated.item > 6)
uinfo->value.enumerated.item = 6;
strcpy(uinfo->value.enumerated.name, texts[uinfo->value.enumerated.item]);
return 0;
}
static int snd_ad1816a_get_mux(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ad1816a *chip = snd_kcontrol_chip(kcontrol);
unsigned long flags;
unsigned short val;
spin_lock_irqsave(&chip->lock, flags);
val = snd_ad1816a_read(chip, AD1816A_ADC_SOURCE_SEL);
spin_unlock_irqrestore(&chip->lock, flags);
ucontrol->value.enumerated.item[0] = (val >> 12) & 7;
ucontrol->value.enumerated.item[1] = (val >> 4) & 7;
return 0;
}
static int snd_ad1816a_put_mux(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ad1816a *chip = snd_kcontrol_chip(kcontrol);
unsigned long flags;
unsigned short val;
int change;
if (ucontrol->value.enumerated.item[0] > 6 ||
ucontrol->value.enumerated.item[1] > 6)
return -EINVAL;
val = (ucontrol->value.enumerated.item[0] << 12) |
(ucontrol->value.enumerated.item[1] << 4);
spin_lock_irqsave(&chip->lock, flags);
change = snd_ad1816a_read(chip, AD1816A_ADC_SOURCE_SEL) != val;
snd_ad1816a_write(chip, AD1816A_ADC_SOURCE_SEL, val);
spin_unlock_irqrestore(&chip->lock, flags);
return change;
}
static int snd_ad1816a_info_single(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_info *uinfo)
{
int mask = (kcontrol->private_value >> 16) & 0xff;
uinfo->type = mask == 1 ? SNDRV_CTL_ELEM_TYPE_BOOLEAN : SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = 1;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = mask;
return 0;
}
static int snd_ad1816a_get_single(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ad1816a *chip = snd_kcontrol_chip(kcontrol);
unsigned long flags;
int reg = kcontrol->private_value & 0xff;
int shift = (kcontrol->private_value >> 8) & 0xff;
int mask = (kcontrol->private_value >> 16) & 0xff;
int invert = (kcontrol->private_value >> 24) & 0xff;
spin_lock_irqsave(&chip->lock, flags);
ucontrol->value.integer.value[0] = (snd_ad1816a_read(chip, reg) >> shift) & mask;
spin_unlock_irqrestore(&chip->lock, flags);
if (invert)
ucontrol->value.integer.value[0] = mask - ucontrol->value.integer.value[0];
return 0;
}
static int snd_ad1816a_put_single(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ad1816a *chip = snd_kcontrol_chip(kcontrol);
unsigned long flags;
int reg = kcontrol->private_value & 0xff;
int shift = (kcontrol->private_value >> 8) & 0xff;
int mask = (kcontrol->private_value >> 16) & 0xff;
int invert = (kcontrol->private_value >> 24) & 0xff;
int change;
unsigned short old_val, val;
val = (ucontrol->value.integer.value[0] & mask);
if (invert)
val = mask - val;
val <<= shift;
spin_lock_irqsave(&chip->lock, flags);
old_val = snd_ad1816a_read(chip, reg);
val = (old_val & ~(mask << shift)) | val;
change = val != old_val;
snd_ad1816a_write(chip, reg, val);
spin_unlock_irqrestore(&chip->lock, flags);
return change;
}
static int snd_ad1816a_info_double(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_info *uinfo)
{
int mask = (kcontrol->private_value >> 16) & 0xff;
uinfo->type = mask == 1 ? SNDRV_CTL_ELEM_TYPE_BOOLEAN : SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = 2;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = mask;
return 0;
}
static int snd_ad1816a_get_double(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ad1816a *chip = snd_kcontrol_chip(kcontrol);
unsigned long flags;
int reg = kcontrol->private_value & 0xff;
int shift_left = (kcontrol->private_value >> 8) & 0x0f;
int shift_right = (kcontrol->private_value >> 12) & 0x0f;
int mask = (kcontrol->private_value >> 16) & 0xff;
int invert = (kcontrol->private_value >> 24) & 0xff;
unsigned short val;
spin_lock_irqsave(&chip->lock, flags);
val = snd_ad1816a_read(chip, reg);
ucontrol->value.integer.value[0] = (val >> shift_left) & mask;
ucontrol->value.integer.value[1] = (val >> shift_right) & mask;
spin_unlock_irqrestore(&chip->lock, flags);
if (invert) {
ucontrol->value.integer.value[0] = mask - ucontrol->value.integer.value[0];
ucontrol->value.integer.value[1] = mask - ucontrol->value.integer.value[1];
}
return 0;
}
static int snd_ad1816a_put_double(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ad1816a *chip = snd_kcontrol_chip(kcontrol);
unsigned long flags;
int reg = kcontrol->private_value & 0xff;
int shift_left = (kcontrol->private_value >> 8) & 0x0f;
int shift_right = (kcontrol->private_value >> 12) & 0x0f;
int mask = (kcontrol->private_value >> 16) & 0xff;
int invert = (kcontrol->private_value >> 24) & 0xff;
int change;
unsigned short old_val, val1, val2;
val1 = ucontrol->value.integer.value[0] & mask;
val2 = ucontrol->value.integer.value[1] & mask;
if (invert) {
val1 = mask - val1;
val2 = mask - val2;
}
val1 <<= shift_left;
val2 <<= shift_right;
spin_lock_irqsave(&chip->lock, flags);
old_val = snd_ad1816a_read(chip, reg);
val1 = (old_val & ~((mask << shift_left) | (mask << shift_right))) | val1 | val2;
change = val1 != old_val;
snd_ad1816a_write(chip, reg, val1);
spin_unlock_irqrestore(&chip->lock, flags);
return change;
}
int __devinit snd_ad1816a_mixer(struct snd_ad1816a *chip)
{
struct snd_card *card;
unsigned int idx;
int err;
if (snd_BUG_ON(!chip || !chip->card))
return -EINVAL;
card = chip->card;
strcpy(card->mixername, snd_ad1816a_chip_id(chip));
for (idx = 0; idx < ARRAY_SIZE(snd_ad1816a_controls); idx++) {
if ((err = snd_ctl_add(card, snd_ctl_new1(&snd_ad1816a_controls[idx], chip))) < 0)
return err;
}
return 0;
}
