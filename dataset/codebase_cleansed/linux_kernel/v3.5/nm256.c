static inline u8
snd_nm256_readb(struct nm256 *chip, int offset)
{
return readb(chip->cport + offset);
}
static inline u16
snd_nm256_readw(struct nm256 *chip, int offset)
{
return readw(chip->cport + offset);
}
static inline u32
snd_nm256_readl(struct nm256 *chip, int offset)
{
return readl(chip->cport + offset);
}
static inline void
snd_nm256_writeb(struct nm256 *chip, int offset, u8 val)
{
writeb(val, chip->cport + offset);
}
static inline void
snd_nm256_writew(struct nm256 *chip, int offset, u16 val)
{
writew(val, chip->cport + offset);
}
static inline void
snd_nm256_writel(struct nm256 *chip, int offset, u32 val)
{
writel(val, chip->cport + offset);
}
static inline void
snd_nm256_write_buffer(struct nm256 *chip, void *src, int offset, int size)
{
offset -= chip->buffer_start;
#ifdef CONFIG_SND_DEBUG
if (offset < 0 || offset >= chip->buffer_size) {
snd_printk(KERN_ERR "write_buffer invalid offset = %d size = %d\n",
offset, size);
return;
}
#endif
memcpy_toio(chip->buffer + offset, src, size);
}
static u16
snd_nm256_get_start_offset(int which)
{
u16 offset = 0;
while (which-- > 0)
offset += coefficient_sizes[which];
return offset;
}
static void
snd_nm256_load_one_coefficient(struct nm256 *chip, int stream, u32 port, int which)
{
u32 coeff_buf = chip->coeff_buf[stream];
u16 offset = snd_nm256_get_start_offset(which);
u16 size = coefficient_sizes[which];
snd_nm256_write_buffer(chip, coefficients + offset, coeff_buf, size);
snd_nm256_writel(chip, port, coeff_buf);
if (stream == SNDRV_PCM_STREAM_PLAYBACK)
size--;
snd_nm256_writel(chip, port + 4, coeff_buf + size);
}
static void
snd_nm256_load_coefficient(struct nm256 *chip, int stream, int number)
{
u32 poffset = (stream == SNDRV_PCM_STREAM_CAPTURE ?
NM_RECORD_ENABLE_REG : NM_PLAYBACK_ENABLE_REG);
u32 addr = NM_COEFF_START_OFFSET;
addr += (stream == SNDRV_PCM_STREAM_CAPTURE ?
NM_RECORD_REG_OFFSET : NM_PLAYBACK_REG_OFFSET);
if (snd_nm256_readb(chip, poffset) & 1) {
snd_printd("NM256: Engine was enabled while loading coefficients!\n");
return;
}
number &= 7;
if (stream == SNDRV_PCM_STREAM_CAPTURE)
number += 8;
if (! chip->use_cache) {
snd_nm256_load_one_coefficient(chip, stream, addr, number);
return;
}
if (! chip->coeffs_current) {
snd_nm256_write_buffer(chip, coefficients, chip->all_coeff_buf,
NM_TOTAL_COEFF_COUNT * 4);
chip->coeffs_current = 1;
} else {
u32 base = chip->all_coeff_buf;
u32 offset = snd_nm256_get_start_offset(number);
u32 end_offset = offset + coefficient_sizes[number];
snd_nm256_writel(chip, addr, base + offset);
if (stream == SNDRV_PCM_STREAM_PLAYBACK)
end_offset--;
snd_nm256_writel(chip, addr + 4, base + end_offset);
}
}
static int
snd_nm256_fixed_rate(unsigned int rate)
{
unsigned int i;
for (i = 0; i < ARRAY_SIZE(samplerates); i++) {
if (rate == samplerates[i])
return i;
}
snd_BUG();
return 0;
}
static void
snd_nm256_set_format(struct nm256 *chip, struct nm256_stream *s,
struct snd_pcm_substream *substream)
{
struct snd_pcm_runtime *runtime = substream->runtime;
int rate_index = snd_nm256_fixed_rate(runtime->rate);
unsigned char ratebits = (rate_index << 4) & NM_RATE_MASK;
s->shift = 0;
if (snd_pcm_format_width(runtime->format) == 16) {
ratebits |= NM_RATE_BITS_16;
s->shift++;
}
if (runtime->channels > 1) {
ratebits |= NM_RATE_STEREO;
s->shift++;
}
runtime->rate = samplerates[rate_index];
switch (substream->stream) {
case SNDRV_PCM_STREAM_PLAYBACK:
snd_nm256_load_coefficient(chip, 0, rate_index);
snd_nm256_writeb(chip,
NM_PLAYBACK_REG_OFFSET + NM_RATE_REG_OFFSET,
ratebits);
break;
case SNDRV_PCM_STREAM_CAPTURE:
snd_nm256_load_coefficient(chip, 1, rate_index);
snd_nm256_writeb(chip,
NM_RECORD_REG_OFFSET + NM_RATE_REG_OFFSET,
ratebits);
break;
}
}
static int snd_nm256_acquire_irq(struct nm256 *chip)
{
mutex_lock(&chip->irq_mutex);
if (chip->irq < 0) {
if (request_irq(chip->pci->irq, chip->interrupt, IRQF_SHARED,
KBUILD_MODNAME, chip)) {
snd_printk(KERN_ERR "unable to grab IRQ %d\n", chip->pci->irq);
mutex_unlock(&chip->irq_mutex);
return -EBUSY;
}
chip->irq = chip->pci->irq;
}
chip->irq_acks++;
mutex_unlock(&chip->irq_mutex);
return 0;
}
static void snd_nm256_release_irq(struct nm256 *chip)
{
mutex_lock(&chip->irq_mutex);
if (chip->irq_acks > 0)
chip->irq_acks--;
if (chip->irq_acks == 0 && chip->irq >= 0) {
free_irq(chip->irq, chip);
chip->irq = -1;
}
mutex_unlock(&chip->irq_mutex);
}
static void snd_nm256_pcm_mark(struct nm256 *chip, struct nm256_stream *s, int reg)
{
s->cur_period++;
s->cur_period %= s->periods;
snd_nm256_writel(chip, reg, s->buf + s->cur_period * s->period_size);
}
static void
snd_nm256_playback_start(struct nm256 *chip, struct nm256_stream *s,
struct snd_pcm_substream *substream)
{
snd_nm256_writel(chip, NM_PBUFFER_START, s->buf);
snd_nm256_writel(chip, NM_PBUFFER_END, s->buf + s->dma_size - (1 << s->shift));
snd_nm256_writel(chip, NM_PBUFFER_CURRP, s->buf);
snd_nm256_playback_mark(chip, s);
snd_nm256_writeb(chip, NM_PLAYBACK_ENABLE_REG,
NM_PLAYBACK_ENABLE_FLAG | NM_PLAYBACK_FREERUN);
snd_nm256_writew(chip, NM_AUDIO_MUTE_REG, 0x0);
}
static void
snd_nm256_capture_start(struct nm256 *chip, struct nm256_stream *s,
struct snd_pcm_substream *substream)
{
snd_nm256_writel(chip, NM_RBUFFER_START, s->buf);
snd_nm256_writel(chip, NM_RBUFFER_END, s->buf + s->dma_size);
snd_nm256_writel(chip, NM_RBUFFER_CURRP, s->buf);
snd_nm256_capture_mark(chip, s);
snd_nm256_writeb(chip, NM_RECORD_ENABLE_REG,
NM_RECORD_ENABLE_FLAG | NM_RECORD_FREERUN);
}
static void
snd_nm256_playback_stop(struct nm256 *chip)
{
snd_nm256_writew(chip, NM_AUDIO_MUTE_REG,
NM_AUDIO_MUTE_LEFT | NM_AUDIO_MUTE_RIGHT);
snd_nm256_writeb(chip, NM_PLAYBACK_ENABLE_REG, 0);
}
static void
snd_nm256_capture_stop(struct nm256 *chip)
{
snd_nm256_writeb(chip, NM_RECORD_ENABLE_REG, 0);
}
static int
snd_nm256_playback_trigger(struct snd_pcm_substream *substream, int cmd)
{
struct nm256 *chip = snd_pcm_substream_chip(substream);
struct nm256_stream *s = substream->runtime->private_data;
int err = 0;
if (snd_BUG_ON(!s))
return -ENXIO;
spin_lock(&chip->reg_lock);
switch (cmd) {
case SNDRV_PCM_TRIGGER_RESUME:
s->suspended = 0;
case SNDRV_PCM_TRIGGER_START:
if (! s->running) {
snd_nm256_playback_start(chip, s, substream);
s->running = 1;
}
break;
case SNDRV_PCM_TRIGGER_SUSPEND:
s->suspended = 1;
case SNDRV_PCM_TRIGGER_STOP:
if (s->running) {
snd_nm256_playback_stop(chip);
s->running = 0;
}
break;
default:
err = -EINVAL;
break;
}
spin_unlock(&chip->reg_lock);
return err;
}
static int
snd_nm256_capture_trigger(struct snd_pcm_substream *substream, int cmd)
{
struct nm256 *chip = snd_pcm_substream_chip(substream);
struct nm256_stream *s = substream->runtime->private_data;
int err = 0;
if (snd_BUG_ON(!s))
return -ENXIO;
spin_lock(&chip->reg_lock);
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
case SNDRV_PCM_TRIGGER_RESUME:
if (! s->running) {
snd_nm256_capture_start(chip, s, substream);
s->running = 1;
}
break;
case SNDRV_PCM_TRIGGER_STOP:
case SNDRV_PCM_TRIGGER_SUSPEND:
if (s->running) {
snd_nm256_capture_stop(chip);
s->running = 0;
}
break;
default:
err = -EINVAL;
break;
}
spin_unlock(&chip->reg_lock);
return err;
}
static int snd_nm256_pcm_prepare(struct snd_pcm_substream *substream)
{
struct nm256 *chip = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
struct nm256_stream *s = runtime->private_data;
if (snd_BUG_ON(!s))
return -ENXIO;
s->dma_size = frames_to_bytes(runtime, substream->runtime->buffer_size);
s->period_size = frames_to_bytes(runtime, substream->runtime->period_size);
s->periods = substream->runtime->periods;
s->cur_period = 0;
spin_lock_irq(&chip->reg_lock);
s->running = 0;
snd_nm256_set_format(chip, s, substream);
spin_unlock_irq(&chip->reg_lock);
return 0;
}
static snd_pcm_uframes_t
snd_nm256_playback_pointer(struct snd_pcm_substream *substream)
{
struct nm256 *chip = snd_pcm_substream_chip(substream);
struct nm256_stream *s = substream->runtime->private_data;
unsigned long curp;
if (snd_BUG_ON(!s))
return 0;
curp = snd_nm256_readl(chip, NM_PBUFFER_CURRP) - (unsigned long)s->buf;
curp %= s->dma_size;
return bytes_to_frames(substream->runtime, curp);
}
static snd_pcm_uframes_t
snd_nm256_capture_pointer(struct snd_pcm_substream *substream)
{
struct nm256 *chip = snd_pcm_substream_chip(substream);
struct nm256_stream *s = substream->runtime->private_data;
unsigned long curp;
if (snd_BUG_ON(!s))
return 0;
curp = snd_nm256_readl(chip, NM_RBUFFER_CURRP) - (unsigned long)s->buf;
curp %= s->dma_size;
return bytes_to_frames(substream->runtime, curp);
}
static int
snd_nm256_playback_silence(struct snd_pcm_substream *substream,
int channel,
snd_pcm_uframes_t pos,
snd_pcm_uframes_t count)
{
struct snd_pcm_runtime *runtime = substream->runtime;
struct nm256_stream *s = runtime->private_data;
count = frames_to_bytes(runtime, count);
pos = frames_to_bytes(runtime, pos);
memset_io(s->bufptr + pos, 0, count);
return 0;
}
static int
snd_nm256_playback_copy(struct snd_pcm_substream *substream,
int channel,
snd_pcm_uframes_t pos,
void __user *src,
snd_pcm_uframes_t count)
{
struct snd_pcm_runtime *runtime = substream->runtime;
struct nm256_stream *s = runtime->private_data;
count = frames_to_bytes(runtime, count);
pos = frames_to_bytes(runtime, pos);
if (copy_from_user_toio(s->bufptr + pos, src, count))
return -EFAULT;
return 0;
}
static int
snd_nm256_capture_copy(struct snd_pcm_substream *substream,
int channel,
snd_pcm_uframes_t pos,
void __user *dst,
snd_pcm_uframes_t count)
{
struct snd_pcm_runtime *runtime = substream->runtime;
struct nm256_stream *s = runtime->private_data;
count = frames_to_bytes(runtime, count);
pos = frames_to_bytes(runtime, pos);
if (copy_to_user_fromio(dst, s->bufptr + pos, count))
return -EFAULT;
return 0;
}
static void
snd_nm256_playback_update(struct nm256 *chip)
{
struct nm256_stream *s;
s = &chip->streams[SNDRV_PCM_STREAM_PLAYBACK];
if (s->running && s->substream) {
spin_unlock(&chip->reg_lock);
snd_pcm_period_elapsed(s->substream);
spin_lock(&chip->reg_lock);
snd_nm256_playback_mark(chip, s);
}
}
static void
snd_nm256_capture_update(struct nm256 *chip)
{
struct nm256_stream *s;
s = &chip->streams[SNDRV_PCM_STREAM_CAPTURE];
if (s->running && s->substream) {
spin_unlock(&chip->reg_lock);
snd_pcm_period_elapsed(s->substream);
spin_lock(&chip->reg_lock);
snd_nm256_capture_mark(chip, s);
}
}
static int snd_nm256_pcm_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *hw_params)
{
substream->runtime->dma_bytes = params_buffer_bytes(hw_params);
return 0;
}
static void snd_nm256_setup_stream(struct nm256 *chip, struct nm256_stream *s,
struct snd_pcm_substream *substream,
struct snd_pcm_hardware *hw_ptr)
{
struct snd_pcm_runtime *runtime = substream->runtime;
s->running = 0;
runtime->hw = *hw_ptr;
runtime->hw.buffer_bytes_max = s->bufsize;
runtime->hw.period_bytes_max = s->bufsize / 2;
runtime->dma_area = (void __force *) s->bufptr;
runtime->dma_addr = s->bufptr_addr;
runtime->dma_bytes = s->bufsize;
runtime->private_data = s;
s->substream = substream;
snd_pcm_hw_constraint_list(runtime, 0, SNDRV_PCM_HW_PARAM_RATE,
&constraints_rates);
}
static int
snd_nm256_playback_open(struct snd_pcm_substream *substream)
{
struct nm256 *chip = snd_pcm_substream_chip(substream);
if (snd_nm256_acquire_irq(chip) < 0)
return -EBUSY;
snd_nm256_setup_stream(chip, &chip->streams[SNDRV_PCM_STREAM_PLAYBACK],
substream, &snd_nm256_playback);
return 0;
}
static int
snd_nm256_capture_open(struct snd_pcm_substream *substream)
{
struct nm256 *chip = snd_pcm_substream_chip(substream);
if (snd_nm256_acquire_irq(chip) < 0)
return -EBUSY;
snd_nm256_setup_stream(chip, &chip->streams[SNDRV_PCM_STREAM_CAPTURE],
substream, &snd_nm256_capture);
return 0;
}
static int
snd_nm256_playback_close(struct snd_pcm_substream *substream)
{
struct nm256 *chip = snd_pcm_substream_chip(substream);
snd_nm256_release_irq(chip);
return 0;
}
static int
snd_nm256_capture_close(struct snd_pcm_substream *substream)
{
struct nm256 *chip = snd_pcm_substream_chip(substream);
snd_nm256_release_irq(chip);
return 0;
}
static int __devinit
snd_nm256_pcm(struct nm256 *chip, int device)
{
struct snd_pcm *pcm;
int i, err;
for (i = 0; i < 2; i++) {
struct nm256_stream *s = &chip->streams[i];
s->bufptr = chip->buffer + (s->buf - chip->buffer_start);
s->bufptr_addr = chip->buffer_addr + (s->buf - chip->buffer_start);
}
err = snd_pcm_new(chip->card, chip->card->driver, device,
1, 1, &pcm);
if (err < 0)
return err;
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_PLAYBACK, &snd_nm256_playback_ops);
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_CAPTURE, &snd_nm256_capture_ops);
pcm->private_data = chip;
pcm->info_flags = 0;
chip->pcm = pcm;
return 0;
}
static void
snd_nm256_init_chip(struct nm256 *chip)
{
snd_nm256_writeb(chip, 0x0, 0x11);
snd_nm256_writew(chip, 0x214, 0);
}
static irqreturn_t
snd_nm256_intr_check(struct nm256 *chip)
{
if (chip->badintrcount++ > 1000) {
if (chip->streams[SNDRV_PCM_STREAM_PLAYBACK].running)
snd_nm256_playback_stop(chip);
if (chip->streams[SNDRV_PCM_STREAM_CAPTURE].running)
snd_nm256_capture_stop(chip);
chip->badintrcount = 0;
return IRQ_HANDLED;
}
return IRQ_NONE;
}
static irqreturn_t
snd_nm256_interrupt(int irq, void *dev_id)
{
struct nm256 *chip = dev_id;
u16 status;
u8 cbyte;
status = snd_nm256_readw(chip, NM_INT_REG);
if (status == 0)
return snd_nm256_intr_check(chip);
chip->badintrcount = 0;
spin_lock(&chip->reg_lock);
if (status & NM_PLAYBACK_INT) {
status &= ~NM_PLAYBACK_INT;
NM_ACK_INT(chip, NM_PLAYBACK_INT);
snd_nm256_playback_update(chip);
}
if (status & NM_RECORD_INT) {
status &= ~NM_RECORD_INT;
NM_ACK_INT(chip, NM_RECORD_INT);
snd_nm256_capture_update(chip);
}
if (status & NM_MISC_INT_1) {
status &= ~NM_MISC_INT_1;
NM_ACK_INT(chip, NM_MISC_INT_1);
snd_printd("NM256: Got misc interrupt #1\n");
snd_nm256_writew(chip, NM_INT_REG, 0x8000);
cbyte = snd_nm256_readb(chip, 0x400);
snd_nm256_writeb(chip, 0x400, cbyte | 2);
}
if (status & NM_MISC_INT_2) {
status &= ~NM_MISC_INT_2;
NM_ACK_INT(chip, NM_MISC_INT_2);
snd_printd("NM256: Got misc interrupt #2\n");
cbyte = snd_nm256_readb(chip, 0x400);
snd_nm256_writeb(chip, 0x400, cbyte & ~2);
}
if (status) {
snd_printd("NM256: Fire in the hole! Unknown status 0x%x\n",
status);
NM_ACK_INT(chip, status);
}
spin_unlock(&chip->reg_lock);
return IRQ_HANDLED;
}
static irqreturn_t
snd_nm256_interrupt_zx(int irq, void *dev_id)
{
struct nm256 *chip = dev_id;
u32 status;
u8 cbyte;
status = snd_nm256_readl(chip, NM_INT_REG);
if (status == 0)
return snd_nm256_intr_check(chip);
chip->badintrcount = 0;
spin_lock(&chip->reg_lock);
if (status & NM2_PLAYBACK_INT) {
status &= ~NM2_PLAYBACK_INT;
NM2_ACK_INT(chip, NM2_PLAYBACK_INT);
snd_nm256_playback_update(chip);
}
if (status & NM2_RECORD_INT) {
status &= ~NM2_RECORD_INT;
NM2_ACK_INT(chip, NM2_RECORD_INT);
snd_nm256_capture_update(chip);
}
if (status & NM2_MISC_INT_1) {
status &= ~NM2_MISC_INT_1;
NM2_ACK_INT(chip, NM2_MISC_INT_1);
snd_printd("NM256: Got misc interrupt #1\n");
cbyte = snd_nm256_readb(chip, 0x400);
snd_nm256_writeb(chip, 0x400, cbyte | 2);
}
if (status & NM2_MISC_INT_2) {
status &= ~NM2_MISC_INT_2;
NM2_ACK_INT(chip, NM2_MISC_INT_2);
snd_printd("NM256: Got misc interrupt #2\n");
cbyte = snd_nm256_readb(chip, 0x400);
snd_nm256_writeb(chip, 0x400, cbyte & ~2);
}
if (status) {
snd_printd("NM256: Fire in the hole! Unknown status 0x%x\n",
status);
NM2_ACK_INT(chip, status);
}
spin_unlock(&chip->reg_lock);
return IRQ_HANDLED;
}
static int
snd_nm256_ac97_ready(struct nm256 *chip)
{
int timeout = 10;
u32 testaddr;
u16 testb;
testaddr = chip->mixer_status_offset;
testb = chip->mixer_status_mask;
while (timeout-- > 0) {
if ((snd_nm256_readw(chip, testaddr) & testb) == 0)
return 1;
udelay(100);
}
return 0;
}
static int nm256_ac97_idx(unsigned short reg)
{
int i;
for (i = 0; i < ARRAY_SIZE(nm256_ac97_init_val); i++)
if (nm256_ac97_init_val[i].reg == reg)
return i;
return -1;
}
static unsigned short
snd_nm256_ac97_read(struct snd_ac97 *ac97, unsigned short reg)
{
struct nm256 *chip = ac97->private_data;
int idx = nm256_ac97_idx(reg);
if (idx < 0)
return 0;
return chip->ac97_regs[idx];
}
static void
snd_nm256_ac97_write(struct snd_ac97 *ac97,
unsigned short reg, unsigned short val)
{
struct nm256 *chip = ac97->private_data;
int tries = 2;
int idx = nm256_ac97_idx(reg);
u32 base;
if (idx < 0)
return;
base = chip->mixer_base;
snd_nm256_ac97_ready(chip);
while (tries-- > 0) {
snd_nm256_writew(chip, base + reg, val);
msleep(1);
if (snd_nm256_ac97_ready(chip)) {
chip->ac97_regs[idx] = val;
return;
}
}
snd_printd("nm256: ac97 codec not ready..\n");
}
static void
snd_nm256_ac97_reset(struct snd_ac97 *ac97)
{
struct nm256 *chip = ac97->private_data;
snd_nm256_writeb(chip, 0x6c0, 1);
if (! chip->reset_workaround) {
snd_nm256_writeb(chip, 0x6cc, 0x87);
}
if (! chip->reset_workaround_2) {
snd_nm256_writeb(chip, 0x6cc, 0x80);
snd_nm256_writeb(chip, 0x6cc, 0x0);
}
if (! chip->in_resume) {
int i;
for (i = 0; i < ARRAY_SIZE(nm256_ac97_init_val); i++) {
snd_nm256_ac97_write(ac97, nm256_ac97_init_val[i].reg,
nm256_ac97_init_val[i].value);
}
}
}
static int __devinit
snd_nm256_mixer(struct nm256 *chip)
{
struct snd_ac97_bus *pbus;
struct snd_ac97_template ac97;
int err;
static struct snd_ac97_bus_ops ops = {
.reset = snd_nm256_ac97_reset,
.write = snd_nm256_ac97_write,
.read = snd_nm256_ac97_read,
};
chip->ac97_regs = kcalloc(ARRAY_SIZE(nm256_ac97_init_val),
sizeof(short), GFP_KERNEL);
if (! chip->ac97_regs)
return -ENOMEM;
if ((err = snd_ac97_bus(chip->card, 0, &ops, NULL, &pbus)) < 0)
return err;
memset(&ac97, 0, sizeof(ac97));
ac97.scaps = AC97_SCAP_AUDIO;
ac97.private_data = chip;
ac97.res_table = nm256_res_table;
pbus->no_vra = 1;
err = snd_ac97_mixer(pbus, &ac97, &chip->ac97);
if (err < 0)
return err;
if (! (chip->ac97->id & (0xf0000000))) {
sprintf(chip->card->mixername, "%s AC97", chip->card->driver);
}
return 0;
}
static int __devinit
snd_nm256_peek_for_sig(struct nm256 *chip)
{
void __iomem *temp;
unsigned long pointer_found = chip->buffer_end - 0x1400;
u32 sig;
temp = ioremap_nocache(chip->buffer_addr + chip->buffer_end - 0x400, 16);
if (temp == NULL) {
snd_printk(KERN_ERR "Unable to scan for card signature in video RAM\n");
return -EBUSY;
}
sig = readl(temp);
if ((sig & NM_SIG_MASK) == NM_SIGNATURE) {
u32 pointer = readl(temp + 4);
if (pointer == 0xffffffff ||
pointer < chip->buffer_size ||
pointer > chip->buffer_end) {
snd_printk(KERN_ERR "invalid signature found: 0x%x\n", pointer);
iounmap(temp);
return -ENODEV;
} else {
pointer_found = pointer;
printk(KERN_INFO "nm256: found card signature in video RAM: 0x%x\n",
pointer);
}
}
iounmap(temp);
chip->buffer_end = pointer_found;
return 0;
}
static int nm256_suspend(struct pci_dev *pci, pm_message_t state)
{
struct snd_card *card = pci_get_drvdata(pci);
struct nm256 *chip = card->private_data;
snd_power_change_state(card, SNDRV_CTL_POWER_D3hot);
snd_pcm_suspend_all(chip->pcm);
snd_ac97_suspend(chip->ac97);
chip->coeffs_current = 0;
pci_disable_device(pci);
pci_save_state(pci);
pci_set_power_state(pci, pci_choose_state(pci, state));
return 0;
}
static int nm256_resume(struct pci_dev *pci)
{
struct snd_card *card = pci_get_drvdata(pci);
struct nm256 *chip = card->private_data;
int i;
chip->in_resume = 1;
pci_set_power_state(pci, PCI_D0);
pci_restore_state(pci);
if (pci_enable_device(pci) < 0) {
printk(KERN_ERR "nm256: pci_enable_device failed, "
"disabling device\n");
snd_card_disconnect(card);
return -EIO;
}
pci_set_master(pci);
snd_nm256_init_chip(chip);
snd_ac97_resume(chip->ac97);
for (i = 0; i < 2; i++) {
struct nm256_stream *s = &chip->streams[i];
if (s->substream && s->suspended) {
spin_lock_irq(&chip->reg_lock);
snd_nm256_set_format(chip, s, s->substream);
spin_unlock_irq(&chip->reg_lock);
}
}
snd_power_change_state(card, SNDRV_CTL_POWER_D0);
chip->in_resume = 0;
return 0;
}
static int snd_nm256_free(struct nm256 *chip)
{
if (chip->streams[SNDRV_PCM_STREAM_PLAYBACK].running)
snd_nm256_playback_stop(chip);
if (chip->streams[SNDRV_PCM_STREAM_CAPTURE].running)
snd_nm256_capture_stop(chip);
if (chip->irq >= 0)
free_irq(chip->irq, chip);
if (chip->cport)
iounmap(chip->cport);
if (chip->buffer)
iounmap(chip->buffer);
release_and_free_resource(chip->res_cport);
release_and_free_resource(chip->res_buffer);
pci_disable_device(chip->pci);
kfree(chip->ac97_regs);
kfree(chip);
return 0;
}
static int snd_nm256_dev_free(struct snd_device *device)
{
struct nm256 *chip = device->device_data;
return snd_nm256_free(chip);
}
static int __devinit
snd_nm256_create(struct snd_card *card, struct pci_dev *pci,
struct nm256 **chip_ret)
{
struct nm256 *chip;
int err, pval;
static struct snd_device_ops ops = {
.dev_free = snd_nm256_dev_free,
};
u32 addr;
*chip_ret = NULL;
if ((err = pci_enable_device(pci)) < 0)
return err;
chip = kzalloc(sizeof(*chip), GFP_KERNEL);
if (chip == NULL) {
pci_disable_device(pci);
return -ENOMEM;
}
chip->card = card;
chip->pci = pci;
chip->use_cache = use_cache;
spin_lock_init(&chip->reg_lock);
chip->irq = -1;
mutex_init(&chip->irq_mutex);
chip->streams[SNDRV_PCM_STREAM_PLAYBACK].bufsize = playback_bufsize * 1024;
chip->streams[SNDRV_PCM_STREAM_CAPTURE].bufsize = capture_bufsize * 1024;
chip->buffer_addr = pci_resource_start(pci, 0);
chip->cport_addr = pci_resource_start(pci, 1);
chip->res_cport = request_mem_region(chip->cport_addr, NM_PORT2_SIZE,
card->driver);
if (chip->res_cport == NULL) {
snd_printk(KERN_ERR "memory region 0x%lx (size 0x%x) busy\n",
chip->cport_addr, NM_PORT2_SIZE);
err = -EBUSY;
goto __error;
}
chip->cport = ioremap_nocache(chip->cport_addr, NM_PORT2_SIZE);
if (chip->cport == NULL) {
snd_printk(KERN_ERR "unable to map control port %lx\n", chip->cport_addr);
err = -ENOMEM;
goto __error;
}
if (!strcmp(card->driver, "NM256AV")) {
pval = snd_nm256_readw(chip, NM_MIXER_PRESENCE);
if ((pval & NM_PRESENCE_MASK) != NM_PRESENCE_VALUE) {
if (! force_ac97) {
printk(KERN_ERR "nm256: no ac97 is found!\n");
printk(KERN_ERR " force the driver to load by "
"passing in the module parameter\n");
printk(KERN_ERR " force_ac97=1\n");
printk(KERN_ERR " or try sb16, opl3sa2, or "
"cs423x drivers instead.\n");
err = -ENXIO;
goto __error;
}
}
chip->buffer_end = 2560 * 1024;
chip->interrupt = snd_nm256_interrupt;
chip->mixer_status_offset = NM_MIXER_STATUS_OFFSET;
chip->mixer_status_mask = NM_MIXER_READY_MASK;
} else {
if (snd_nm256_readb(chip, 0xa0b) != 0)
chip->buffer_end = 6144 * 1024;
else
chip->buffer_end = 4096 * 1024;
chip->interrupt = snd_nm256_interrupt_zx;
chip->mixer_status_offset = NM2_MIXER_STATUS_OFFSET;
chip->mixer_status_mask = NM2_MIXER_READY_MASK;
}
chip->buffer_size = chip->streams[SNDRV_PCM_STREAM_PLAYBACK].bufsize +
chip->streams[SNDRV_PCM_STREAM_CAPTURE].bufsize;
if (chip->use_cache)
chip->buffer_size += NM_TOTAL_COEFF_COUNT * 4;
else
chip->buffer_size += NM_MAX_PLAYBACK_COEF_SIZE + NM_MAX_RECORD_COEF_SIZE;
if (buffer_top >= chip->buffer_size && buffer_top < chip->buffer_end)
chip->buffer_end = buffer_top;
else {
if ((err = snd_nm256_peek_for_sig(chip)) < 0)
goto __error;
}
chip->buffer_start = chip->buffer_end - chip->buffer_size;
chip->buffer_addr += chip->buffer_start;
printk(KERN_INFO "nm256: Mapping port 1 from 0x%x - 0x%x\n",
chip->buffer_start, chip->buffer_end);
chip->res_buffer = request_mem_region(chip->buffer_addr,
chip->buffer_size,
card->driver);
if (chip->res_buffer == NULL) {
snd_printk(KERN_ERR "nm256: buffer 0x%lx (size 0x%x) busy\n",
chip->buffer_addr, chip->buffer_size);
err = -EBUSY;
goto __error;
}
chip->buffer = ioremap_nocache(chip->buffer_addr, chip->buffer_size);
if (chip->buffer == NULL) {
err = -ENOMEM;
snd_printk(KERN_ERR "unable to map ring buffer at %lx\n", chip->buffer_addr);
goto __error;
}
addr = chip->buffer_start;
chip->streams[SNDRV_PCM_STREAM_PLAYBACK].buf = addr;
addr += chip->streams[SNDRV_PCM_STREAM_PLAYBACK].bufsize;
chip->streams[SNDRV_PCM_STREAM_CAPTURE].buf = addr;
addr += chip->streams[SNDRV_PCM_STREAM_CAPTURE].bufsize;
if (chip->use_cache) {
chip->all_coeff_buf = addr;
} else {
chip->coeff_buf[SNDRV_PCM_STREAM_PLAYBACK] = addr;
addr += NM_MAX_PLAYBACK_COEF_SIZE;
chip->coeff_buf[SNDRV_PCM_STREAM_CAPTURE] = addr;
}
chip->mixer_base = NM_MIXER_OFFSET;
chip->coeffs_current = 0;
snd_nm256_init_chip(chip);
if ((err = snd_device_new(card, SNDRV_DEV_LOWLEVEL, chip, &ops)) < 0)
goto __error;
snd_card_set_dev(card, &pci->dev);
*chip_ret = chip;
return 0;
__error:
snd_nm256_free(chip);
return err;
}
static int __devinit snd_nm256_probe(struct pci_dev *pci,
const struct pci_device_id *pci_id)
{
struct snd_card *card;
struct nm256 *chip;
int err;
const struct snd_pci_quirk *q;
q = snd_pci_quirk_lookup(pci, nm256_quirks);
if (q) {
snd_printdd(KERN_INFO "nm256: Enabled quirk for %s.\n", q->name);
switch (q->value) {
case NM_BLACKLISTED:
printk(KERN_INFO "nm256: The device is blacklisted. "
"Loading stopped\n");
return -ENODEV;
case NM_RESET_WORKAROUND_2:
reset_workaround_2 = 1;
case NM_RESET_WORKAROUND:
reset_workaround = 1;
break;
}
}
err = snd_card_create(index, id, THIS_MODULE, 0, &card);
if (err < 0)
return err;
switch (pci->device) {
case PCI_DEVICE_ID_NEOMAGIC_NM256AV_AUDIO:
strcpy(card->driver, "NM256AV");
break;
case PCI_DEVICE_ID_NEOMAGIC_NM256ZX_AUDIO:
strcpy(card->driver, "NM256ZX");
break;
case PCI_DEVICE_ID_NEOMAGIC_NM256XL_PLUS_AUDIO:
strcpy(card->driver, "NM256XL+");
break;
default:
snd_printk(KERN_ERR "invalid device id 0x%x\n", pci->device);
snd_card_free(card);
return -EINVAL;
}
if (vaio_hack)
buffer_top = 0x25a800;
if (playback_bufsize < 4)
playback_bufsize = 4;
if (playback_bufsize > 128)
playback_bufsize = 128;
if (capture_bufsize < 4)
capture_bufsize = 4;
if (capture_bufsize > 128)
capture_bufsize = 128;
if ((err = snd_nm256_create(card, pci, &chip)) < 0) {
snd_card_free(card);
return err;
}
card->private_data = chip;
if (reset_workaround) {
snd_printdd(KERN_INFO "nm256: reset_workaround activated\n");
chip->reset_workaround = 1;
}
if (reset_workaround_2) {
snd_printdd(KERN_INFO "nm256: reset_workaround_2 activated\n");
chip->reset_workaround_2 = 1;
}
if ((err = snd_nm256_pcm(chip, 0)) < 0 ||
(err = snd_nm256_mixer(chip)) < 0) {
snd_card_free(card);
return err;
}
sprintf(card->shortname, "NeoMagic %s", card->driver);
sprintf(card->longname, "%s at 0x%lx & 0x%lx, irq %d",
card->shortname,
chip->buffer_addr, chip->cport_addr, chip->irq);
if ((err = snd_card_register(card)) < 0) {
snd_card_free(card);
return err;
}
pci_set_drvdata(pci, card);
return 0;
}
static void __devexit snd_nm256_remove(struct pci_dev *pci)
{
snd_card_free(pci_get_drvdata(pci));
pci_set_drvdata(pci, NULL);
}
