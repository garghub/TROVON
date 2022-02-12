static inline void snd_m3_outw(struct snd_m3 *chip, u16 value, unsigned long reg)
{
outw(value, chip->iobase + reg);
}
static inline u16 snd_m3_inw(struct snd_m3 *chip, unsigned long reg)
{
return inw(chip->iobase + reg);
}
static inline void snd_m3_outb(struct snd_m3 *chip, u8 value, unsigned long reg)
{
outb(value, chip->iobase + reg);
}
static inline u8 snd_m3_inb(struct snd_m3 *chip, unsigned long reg)
{
return inb(chip->iobase + reg);
}
static u16 snd_m3_assp_read(struct snd_m3 *chip, u16 region, u16 index)
{
snd_m3_outw(chip, region & MEMTYPE_MASK, DSP_PORT_MEMORY_TYPE);
snd_m3_outw(chip, index, DSP_PORT_MEMORY_INDEX);
return snd_m3_inw(chip, DSP_PORT_MEMORY_DATA);
}
static void snd_m3_assp_write(struct snd_m3 *chip, u16 region, u16 index, u16 data)
{
snd_m3_outw(chip, region & MEMTYPE_MASK, DSP_PORT_MEMORY_TYPE);
snd_m3_outw(chip, index, DSP_PORT_MEMORY_INDEX);
snd_m3_outw(chip, data, DSP_PORT_MEMORY_DATA);
}
static void snd_m3_assp_halt(struct snd_m3 *chip)
{
chip->reset_state = snd_m3_inb(chip, DSP_PORT_CONTROL_REG_B) & ~REGB_STOP_CLOCK;
msleep(10);
snd_m3_outb(chip, chip->reset_state & ~REGB_ENABLE_RESET, DSP_PORT_CONTROL_REG_B);
}
static void snd_m3_assp_continue(struct snd_m3 *chip)
{
snd_m3_outb(chip, chip->reset_state | REGB_ENABLE_RESET, DSP_PORT_CONTROL_REG_B);
}
static int snd_m3_add_list(struct snd_m3 *chip, struct m3_list *list, u16 val)
{
snd_m3_assp_write(chip, MEMTYPE_INTERNAL_DATA,
list->mem_addr + list->curlen,
val);
return list->curlen++;
}
static void snd_m3_remove_list(struct snd_m3 *chip, struct m3_list *list, int index)
{
u16 val;
int lastindex = list->curlen - 1;
if (index != lastindex) {
val = snd_m3_assp_read(chip, MEMTYPE_INTERNAL_DATA,
list->mem_addr + lastindex);
snd_m3_assp_write(chip, MEMTYPE_INTERNAL_DATA,
list->mem_addr + index,
val);
}
snd_m3_assp_write(chip, MEMTYPE_INTERNAL_DATA,
list->mem_addr + lastindex,
0);
list->curlen--;
}
static void snd_m3_inc_timer_users(struct snd_m3 *chip)
{
chip->timer_users++;
if (chip->timer_users != 1)
return;
snd_m3_assp_write(chip, MEMTYPE_INTERNAL_DATA,
KDATA_TIMER_COUNT_RELOAD,
240);
snd_m3_assp_write(chip, MEMTYPE_INTERNAL_DATA,
KDATA_TIMER_COUNT_CURRENT,
240);
snd_m3_outw(chip,
snd_m3_inw(chip, HOST_INT_CTRL) | CLKRUN_GEN_ENABLE,
HOST_INT_CTRL);
}
static void snd_m3_dec_timer_users(struct snd_m3 *chip)
{
chip->timer_users--;
if (chip->timer_users > 0)
return;
snd_m3_assp_write(chip, MEMTYPE_INTERNAL_DATA,
KDATA_TIMER_COUNT_RELOAD,
0);
snd_m3_assp_write(chip, MEMTYPE_INTERNAL_DATA,
KDATA_TIMER_COUNT_CURRENT,
0);
snd_m3_outw(chip,
snd_m3_inw(chip, HOST_INT_CTRL) & ~CLKRUN_GEN_ENABLE,
HOST_INT_CTRL);
}
static int snd_m3_pcm_start(struct snd_m3 *chip, struct m3_dma *s,
struct snd_pcm_substream *subs)
{
if (! s || ! subs)
return -EINVAL;
snd_m3_inc_timer_users(chip);
switch (subs->stream) {
case SNDRV_PCM_STREAM_PLAYBACK:
chip->dacs_active++;
snd_m3_assp_write(chip, MEMTYPE_INTERNAL_DATA,
s->inst.data + CDATA_INSTANCE_READY, 1);
snd_m3_assp_write(chip, MEMTYPE_INTERNAL_DATA,
KDATA_MIXER_TASK_NUMBER,
chip->dacs_active);
break;
case SNDRV_PCM_STREAM_CAPTURE:
snd_m3_assp_write(chip, MEMTYPE_INTERNAL_DATA,
KDATA_ADC1_REQUEST, 1);
snd_m3_assp_write(chip, MEMTYPE_INTERNAL_DATA,
s->inst.data + CDATA_INSTANCE_READY, 1);
break;
}
return 0;
}
static int snd_m3_pcm_stop(struct snd_m3 *chip, struct m3_dma *s,
struct snd_pcm_substream *subs)
{
if (! s || ! subs)
return -EINVAL;
snd_m3_assp_write(chip, MEMTYPE_INTERNAL_DATA,
s->inst.data + CDATA_INSTANCE_READY, 0);
snd_m3_dec_timer_users(chip);
switch (subs->stream) {
case SNDRV_PCM_STREAM_PLAYBACK:
chip->dacs_active--;
snd_m3_assp_write(chip, MEMTYPE_INTERNAL_DATA,
KDATA_MIXER_TASK_NUMBER,
chip->dacs_active);
break;
case SNDRV_PCM_STREAM_CAPTURE:
snd_m3_assp_write(chip, MEMTYPE_INTERNAL_DATA,
KDATA_ADC1_REQUEST, 0);
break;
}
return 0;
}
static int
snd_m3_pcm_trigger(struct snd_pcm_substream *subs, int cmd)
{
struct snd_m3 *chip = snd_pcm_substream_chip(subs);
struct m3_dma *s = subs->runtime->private_data;
int err = -EINVAL;
if (snd_BUG_ON(!s))
return -ENXIO;
spin_lock(&chip->reg_lock);
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
case SNDRV_PCM_TRIGGER_RESUME:
if (s->running)
err = -EBUSY;
else {
s->running = 1;
err = snd_m3_pcm_start(chip, s, subs);
}
break;
case SNDRV_PCM_TRIGGER_STOP:
case SNDRV_PCM_TRIGGER_SUSPEND:
if (! s->running)
err = 0;
else {
s->running = 0;
err = snd_m3_pcm_stop(chip, s, subs);
}
break;
}
spin_unlock(&chip->reg_lock);
return err;
}
static void
snd_m3_pcm_setup1(struct snd_m3 *chip, struct m3_dma *s, struct snd_pcm_substream *subs)
{
int dsp_in_size, dsp_out_size, dsp_in_buffer, dsp_out_buffer;
struct snd_pcm_runtime *runtime = subs->runtime;
if (subs->stream == SNDRV_PCM_STREAM_PLAYBACK) {
dsp_in_size = MINISRC_IN_BUFFER_SIZE - (0x20 * 2);
dsp_out_size = MINISRC_OUT_BUFFER_SIZE - (0x20 * 2);
} else {
dsp_in_size = MINISRC_IN_BUFFER_SIZE - (0x10 * 2);
dsp_out_size = MINISRC_OUT_BUFFER_SIZE - (0x10 * 2);
}
dsp_in_buffer = s->inst.data + (MINISRC_TMP_BUFFER_SIZE / 2);
dsp_out_buffer = dsp_in_buffer + (dsp_in_size / 2) + 1;
s->dma_size = frames_to_bytes(runtime, runtime->buffer_size);
s->period_size = frames_to_bytes(runtime, runtime->period_size);
s->hwptr = 0;
s->count = 0;
#define LO(x) ((x) & 0xffff)
#define HI(x) LO((x) >> 16)
snd_m3_assp_write(chip, MEMTYPE_INTERNAL_DATA,
s->inst.data + CDATA_HOST_SRC_ADDRL,
LO(s->buffer_addr));
snd_m3_assp_write(chip, MEMTYPE_INTERNAL_DATA,
s->inst.data + CDATA_HOST_SRC_ADDRH,
HI(s->buffer_addr));
snd_m3_assp_write(chip, MEMTYPE_INTERNAL_DATA,
s->inst.data + CDATA_HOST_SRC_END_PLUS_1L,
LO(s->buffer_addr + s->dma_size));
snd_m3_assp_write(chip, MEMTYPE_INTERNAL_DATA,
s->inst.data + CDATA_HOST_SRC_END_PLUS_1H,
HI(s->buffer_addr + s->dma_size));
snd_m3_assp_write(chip, MEMTYPE_INTERNAL_DATA,
s->inst.data + CDATA_HOST_SRC_CURRENTL,
LO(s->buffer_addr));
snd_m3_assp_write(chip, MEMTYPE_INTERNAL_DATA,
s->inst.data + CDATA_HOST_SRC_CURRENTH,
HI(s->buffer_addr));
#undef LO
#undef HI
snd_m3_assp_write(chip, MEMTYPE_INTERNAL_DATA,
s->inst.data + CDATA_IN_BUF_BEGIN,
dsp_in_buffer);
snd_m3_assp_write(chip, MEMTYPE_INTERNAL_DATA,
s->inst.data + CDATA_IN_BUF_END_PLUS_1,
dsp_in_buffer + (dsp_in_size / 2));
snd_m3_assp_write(chip, MEMTYPE_INTERNAL_DATA,
s->inst.data + CDATA_IN_BUF_HEAD,
dsp_in_buffer);
snd_m3_assp_write(chip, MEMTYPE_INTERNAL_DATA,
s->inst.data + CDATA_IN_BUF_TAIL,
dsp_in_buffer);
snd_m3_assp_write(chip, MEMTYPE_INTERNAL_DATA,
s->inst.data + CDATA_OUT_BUF_BEGIN,
dsp_out_buffer);
snd_m3_assp_write(chip, MEMTYPE_INTERNAL_DATA,
s->inst.data + CDATA_OUT_BUF_END_PLUS_1,
dsp_out_buffer + (dsp_out_size / 2));
snd_m3_assp_write(chip, MEMTYPE_INTERNAL_DATA,
s->inst.data + CDATA_OUT_BUF_HEAD,
dsp_out_buffer);
snd_m3_assp_write(chip, MEMTYPE_INTERNAL_DATA,
s->inst.data + CDATA_OUT_BUF_TAIL,
dsp_out_buffer);
}
static void snd_m3_pcm_setup2(struct snd_m3 *chip, struct m3_dma *s,
struct snd_pcm_runtime *runtime)
{
u32 freq;
if (! s->in_lists) {
s->index[0] = snd_m3_add_list(chip, s->index_list[0],
s->inst.data >> DP_SHIFT_COUNT);
s->index[1] = snd_m3_add_list(chip, s->index_list[1],
s->inst.data >> DP_SHIFT_COUNT);
s->index[2] = snd_m3_add_list(chip, s->index_list[2],
s->inst.data >> DP_SHIFT_COUNT);
s->in_lists = 1;
}
snd_m3_assp_write(chip, MEMTYPE_INTERNAL_DATA,
s->inst.data + SRC3_DIRECTION_OFFSET + 1,
runtime->channels == 2 ? 0 : 1);
snd_m3_assp_write(chip, MEMTYPE_INTERNAL_DATA,
s->inst.data + SRC3_DIRECTION_OFFSET + 2,
snd_pcm_format_width(runtime->format) == 16 ? 0 : 1);
freq = ((runtime->rate << 15) + 24000 ) / 48000;
if (freq)
freq--;
snd_m3_assp_write(chip, MEMTYPE_INTERNAL_DATA,
s->inst.data + CDATA_FREQUENCY,
freq);
}
static void
snd_m3_playback_setup(struct snd_m3 *chip, struct m3_dma *s,
struct snd_pcm_substream *subs)
{
unsigned int i;
snd_m3_assp_write(chip, MEMTYPE_INTERNAL_DATA,
s->inst.data + SRC3_DIRECTION_OFFSET + 12,
s->inst.data + 40 + 8);
snd_m3_assp_write(chip, MEMTYPE_INTERNAL_DATA,
s->inst.data + SRC3_DIRECTION_OFFSET + 19,
s->inst.code + MINISRC_COEF_LOC);
snd_m3_assp_write(chip, MEMTYPE_INTERNAL_DATA,
s->inst.data + SRC3_DIRECTION_OFFSET + 22,
subs->runtime->rate > 45000 ? 0xff : 0);
snd_m3_assp_write(chip, MEMTYPE_INTERNAL_DATA,
s->inst.data + CDATA_DMA_CONTROL,
DMACONTROL_AUTOREPEAT + DMAC_PAGE3_SELECTOR + DMAC_BLOCKF_SELECTOR);
for (i = 0; i < ARRAY_SIZE(pv); i++)
snd_m3_assp_write(chip, MEMTYPE_INTERNAL_DATA,
s->inst.data + pv[i].addr, pv[i].val);
}
static void
snd_m3_capture_setup(struct snd_m3 *chip, struct m3_dma *s, struct snd_pcm_substream *subs)
{
unsigned int i;
snd_m3_assp_write(chip, MEMTYPE_INTERNAL_DATA,
s->inst.data + SRC3_DIRECTION_OFFSET + 12,
s->inst.data + 40 + 8);
snd_m3_assp_write(chip, MEMTYPE_INTERNAL_DATA,
s->inst.data + CDATA_DMA_CONTROL,
DMACONTROL_DIRECTION + DMACONTROL_AUTOREPEAT +
DMAC_PAGE3_SELECTOR + DMAC_BLOCKF_SELECTOR);
for (i = 0; i < ARRAY_SIZE(rv); i++)
snd_m3_assp_write(chip, MEMTYPE_INTERNAL_DATA,
s->inst.data + rv[i].addr, rv[i].val);
}
static int snd_m3_pcm_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *hw_params)
{
struct m3_dma *s = substream->runtime->private_data;
int err;
if ((err = snd_pcm_lib_malloc_pages(substream, params_buffer_bytes(hw_params))) < 0)
return err;
s->buffer_addr = substream->runtime->dma_addr;
if (s->buffer_addr & 0x3) {
snd_printk(KERN_ERR "oh my, not aligned\n");
s->buffer_addr = s->buffer_addr & ~0x3;
}
return 0;
}
static int snd_m3_pcm_hw_free(struct snd_pcm_substream *substream)
{
struct m3_dma *s;
if (substream->runtime->private_data == NULL)
return 0;
s = substream->runtime->private_data;
snd_pcm_lib_free_pages(substream);
s->buffer_addr = 0;
return 0;
}
static int
snd_m3_pcm_prepare(struct snd_pcm_substream *subs)
{
struct snd_m3 *chip = snd_pcm_substream_chip(subs);
struct snd_pcm_runtime *runtime = subs->runtime;
struct m3_dma *s = runtime->private_data;
if (snd_BUG_ON(!s))
return -ENXIO;
if (runtime->format != SNDRV_PCM_FORMAT_U8 &&
runtime->format != SNDRV_PCM_FORMAT_S16_LE)
return -EINVAL;
if (runtime->rate > 48000 ||
runtime->rate < 8000)
return -EINVAL;
spin_lock_irq(&chip->reg_lock);
snd_m3_pcm_setup1(chip, s, subs);
if (subs->stream == SNDRV_PCM_STREAM_PLAYBACK)
snd_m3_playback_setup(chip, s, subs);
else
snd_m3_capture_setup(chip, s, subs);
snd_m3_pcm_setup2(chip, s, runtime);
spin_unlock_irq(&chip->reg_lock);
return 0;
}
static unsigned int
snd_m3_get_pointer(struct snd_m3 *chip, struct m3_dma *s, struct snd_pcm_substream *subs)
{
u16 hi = 0, lo = 0;
int retry = 10;
u32 addr;
while (retry--) {
hi = snd_m3_assp_read(chip, MEMTYPE_INTERNAL_DATA,
s->inst.data + CDATA_HOST_SRC_CURRENTH);
lo = snd_m3_assp_read(chip, MEMTYPE_INTERNAL_DATA,
s->inst.data + CDATA_HOST_SRC_CURRENTL);
if (hi == snd_m3_assp_read(chip, MEMTYPE_INTERNAL_DATA,
s->inst.data + CDATA_HOST_SRC_CURRENTH))
break;
}
addr = lo | ((u32)hi<<16);
return (unsigned int)(addr - s->buffer_addr);
}
static snd_pcm_uframes_t
snd_m3_pcm_pointer(struct snd_pcm_substream *subs)
{
struct snd_m3 *chip = snd_pcm_substream_chip(subs);
unsigned int ptr;
struct m3_dma *s = subs->runtime->private_data;
if (snd_BUG_ON(!s))
return 0;
spin_lock(&chip->reg_lock);
ptr = snd_m3_get_pointer(chip, s, subs);
spin_unlock(&chip->reg_lock);
return bytes_to_frames(subs->runtime, ptr);
}
static void snd_m3_update_ptr(struct snd_m3 *chip, struct m3_dma *s)
{
struct snd_pcm_substream *subs = s->substream;
unsigned int hwptr;
int diff;
if (! s->running)
return;
hwptr = snd_m3_get_pointer(chip, s, subs);
if (hwptr >= s->dma_size)
hwptr %= s->dma_size;
diff = s->dma_size + hwptr - s->hwptr;
if (diff >= s->dma_size)
diff %= s->dma_size;
s->hwptr = hwptr;
s->count += diff;
if (s->count >= (signed)s->period_size) {
if (s->count < 2 * (signed)s->period_size)
s->count -= (signed)s->period_size;
else
s->count %= s->period_size;
spin_unlock(&chip->reg_lock);
snd_pcm_period_elapsed(subs);
spin_lock(&chip->reg_lock);
}
}
static void snd_m3_update_hw_volume(struct work_struct *work)
{
struct snd_m3 *chip = container_of(work, struct snd_m3, hwvol_work);
int x, val;
x = inb(chip->iobase + SHADOW_MIX_REG_VOICE) & 0xee;
outb(0x88, chip->iobase + SHADOW_MIX_REG_VOICE);
outb(0x88, chip->iobase + HW_VOL_COUNTER_VOICE);
outb(0x88, chip->iobase + SHADOW_MIX_REG_MASTER);
outb(0x88, chip->iobase + HW_VOL_COUNTER_MASTER);
if (chip->in_suspend)
return;
#ifndef CONFIG_SND_MAESTRO3_INPUT
if (!chip->master_switch || !chip->master_volume)
return;
val = snd_ac97_read(chip->ac97, AC97_MASTER);
switch (x) {
case 0x88:
val ^= 0x8000;
break;
case 0xaa:
if ((val & 0x7f) > 0)
val--;
if ((val & 0x7f00) > 0)
val -= 0x0100;
break;
case 0x66:
if ((val & 0x7f) < 0x1f)
val++;
if ((val & 0x7f00) < 0x1f00)
val += 0x0100;
break;
}
if (snd_ac97_update(chip->ac97, AC97_MASTER, val))
snd_ctl_notify(chip->card, SNDRV_CTL_EVENT_MASK_VALUE,
&chip->master_switch->id);
#else
if (!chip->input_dev)
return;
val = 0;
switch (x) {
case 0x88:
val = KEY_MUTE;
break;
case 0xaa:
val = KEY_VOLUMEUP;
break;
case 0x66:
val = KEY_VOLUMEDOWN;
break;
}
if (val) {
input_report_key(chip->input_dev, val, 1);
input_sync(chip->input_dev);
input_report_key(chip->input_dev, val, 0);
input_sync(chip->input_dev);
}
#endif
}
static irqreturn_t snd_m3_interrupt(int irq, void *dev_id)
{
struct snd_m3 *chip = dev_id;
u8 status;
int i;
status = inb(chip->iobase + HOST_INT_STATUS);
if (status == 0xff)
return IRQ_NONE;
if (status & HV_INT_PENDING)
schedule_work(&chip->hwvol_work);
if (status & ASSP_INT_PENDING) {
u8 ctl = inb(chip->iobase + ASSP_CONTROL_B);
if (!(ctl & STOP_ASSP_CLOCK)) {
ctl = inb(chip->iobase + ASSP_HOST_INT_STATUS);
if (ctl & DSP2HOST_REQ_TIMER) {
outb(DSP2HOST_REQ_TIMER, chip->iobase + ASSP_HOST_INT_STATUS);
spin_lock(&chip->reg_lock);
for (i = 0; i < chip->num_substreams; i++) {
struct m3_dma *s = &chip->substreams[i];
if (s->running)
snd_m3_update_ptr(chip, s);
}
spin_unlock(&chip->reg_lock);
}
}
}
#if 0
if ((status & MPU401_INT_PENDING) && chip->rmidi)
snd_mpu401_uart_interrupt(irq, chip->rmidi->private_data, regs);
#endif
outb(status, chip->iobase + HOST_INT_STATUS);
return IRQ_HANDLED;
}
static int
snd_m3_substream_open(struct snd_m3 *chip, struct snd_pcm_substream *subs)
{
int i;
struct m3_dma *s;
spin_lock_irq(&chip->reg_lock);
for (i = 0; i < chip->num_substreams; i++) {
s = &chip->substreams[i];
if (! s->opened)
goto __found;
}
spin_unlock_irq(&chip->reg_lock);
return -ENOMEM;
__found:
s->opened = 1;
s->running = 0;
spin_unlock_irq(&chip->reg_lock);
subs->runtime->private_data = s;
s->substream = subs;
if (subs->stream == SNDRV_PCM_STREAM_PLAYBACK) {
s->index_list[0] = &chip->mixer_list;
} else
s->index_list[0] = &chip->adc1_list;
s->index_list[1] = &chip->msrc_list;
s->index_list[2] = &chip->dma_list;
return 0;
}
static void
snd_m3_substream_close(struct snd_m3 *chip, struct snd_pcm_substream *subs)
{
struct m3_dma *s = subs->runtime->private_data;
if (s == NULL)
return;
spin_lock_irq(&chip->reg_lock);
if (s->substream && s->running)
snd_m3_pcm_stop(chip, s, s->substream);
if (s->in_lists) {
snd_m3_remove_list(chip, s->index_list[0], s->index[0]);
snd_m3_remove_list(chip, s->index_list[1], s->index[1]);
snd_m3_remove_list(chip, s->index_list[2], s->index[2]);
s->in_lists = 0;
}
s->running = 0;
s->opened = 0;
spin_unlock_irq(&chip->reg_lock);
}
static int
snd_m3_playback_open(struct snd_pcm_substream *subs)
{
struct snd_m3 *chip = snd_pcm_substream_chip(subs);
struct snd_pcm_runtime *runtime = subs->runtime;
int err;
if ((err = snd_m3_substream_open(chip, subs)) < 0)
return err;
runtime->hw = snd_m3_playback;
return 0;
}
static int
snd_m3_playback_close(struct snd_pcm_substream *subs)
{
struct snd_m3 *chip = snd_pcm_substream_chip(subs);
snd_m3_substream_close(chip, subs);
return 0;
}
static int
snd_m3_capture_open(struct snd_pcm_substream *subs)
{
struct snd_m3 *chip = snd_pcm_substream_chip(subs);
struct snd_pcm_runtime *runtime = subs->runtime;
int err;
if ((err = snd_m3_substream_open(chip, subs)) < 0)
return err;
runtime->hw = snd_m3_capture;
return 0;
}
static int
snd_m3_capture_close(struct snd_pcm_substream *subs)
{
struct snd_m3 *chip = snd_pcm_substream_chip(subs);
snd_m3_substream_close(chip, subs);
return 0;
}
static int __devinit
snd_m3_pcm(struct snd_m3 * chip, int device)
{
struct snd_pcm *pcm;
int err;
err = snd_pcm_new(chip->card, chip->card->driver, device,
MAX_PLAYBACKS, MAX_CAPTURES, &pcm);
if (err < 0)
return err;
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_PLAYBACK, &snd_m3_playback_ops);
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_CAPTURE, &snd_m3_capture_ops);
pcm->private_data = chip;
pcm->info_flags = 0;
strcpy(pcm->name, chip->card->driver);
chip->pcm = pcm;
snd_pcm_lib_preallocate_pages_for_all(pcm, SNDRV_DMA_TYPE_DEV,
snd_dma_pci_data(chip->pci), 64*1024, 64*1024);
return 0;
}
static int snd_m3_ac97_wait(struct snd_m3 *chip)
{
int i = 10000;
do {
if (! (snd_m3_inb(chip, 0x30) & 1))
return 0;
cpu_relax();
} while (i-- > 0);
snd_printk(KERN_ERR "ac97 serial bus busy\n");
return 1;
}
static unsigned short
snd_m3_ac97_read(struct snd_ac97 *ac97, unsigned short reg)
{
struct snd_m3 *chip = ac97->private_data;
unsigned short data = 0xffff;
if (snd_m3_ac97_wait(chip))
goto fail;
snd_m3_outb(chip, 0x80 | (reg & 0x7f), CODEC_COMMAND);
if (snd_m3_ac97_wait(chip))
goto fail;
data = snd_m3_inw(chip, CODEC_DATA);
fail:
return data;
}
static void
snd_m3_ac97_write(struct snd_ac97 *ac97, unsigned short reg, unsigned short val)
{
struct snd_m3 *chip = ac97->private_data;
if (snd_m3_ac97_wait(chip))
return;
snd_m3_outw(chip, val, CODEC_DATA);
snd_m3_outb(chip, reg & 0x7f, CODEC_COMMAND);
}
static void snd_m3_remote_codec_config(int io, int isremote)
{
isremote = isremote ? 1 : 0;
outw((inw(io + RING_BUS_CTRL_B) & ~SECOND_CODEC_ID_MASK) | isremote,
io + RING_BUS_CTRL_B);
outw((inw(io + SDO_OUT_DEST_CTRL) & ~COMMAND_ADDR_OUT) | isremote,
io + SDO_OUT_DEST_CTRL);
outw((inw(io + SDO_IN_DEST_CTRL) & ~STATUS_ADDR_IN) | isremote,
io + SDO_IN_DEST_CTRL);
}
static int snd_m3_try_read_vendor(struct snd_m3 *chip)
{
u16 ret;
if (snd_m3_ac97_wait(chip))
return 1;
snd_m3_outb(chip, 0x80 | (AC97_VENDOR_ID1 & 0x7f), 0x30);
if (snd_m3_ac97_wait(chip))
return 1;
ret = snd_m3_inw(chip, 0x32);
return (ret == 0) || (ret == 0xffff);
}
static void snd_m3_ac97_reset(struct snd_m3 *chip)
{
u16 dir;
int delay1 = 0, delay2 = 0, i;
int io = chip->iobase;
if (chip->allegro_flag) {
delay1 = 50;
delay2 = 800;
} else {
delay1 = 20;
delay2 = 500;
}
for (i = 0; i < 5; i++) {
dir = inw(io + GPIO_DIRECTION);
if (!chip->irda_workaround)
dir |= 0x10;
snd_m3_remote_codec_config(io, 0);
outw(IO_SRAM_ENABLE, io + RING_BUS_CTRL_A);
udelay(20);
outw(dir & ~GPO_PRIMARY_AC97 , io + GPIO_DIRECTION);
outw(~GPO_PRIMARY_AC97 , io + GPIO_MASK);
outw(0, io + GPIO_DATA);
outw(dir | GPO_PRIMARY_AC97, io + GPIO_DIRECTION);
schedule_timeout_uninterruptible(msecs_to_jiffies(delay1));
outw(GPO_PRIMARY_AC97, io + GPIO_DATA);
udelay(5);
outw(IO_SRAM_ENABLE | SERIAL_AC_LINK_ENABLE, io + RING_BUS_CTRL_A);
outw(~0, io + GPIO_MASK);
schedule_timeout_uninterruptible(msecs_to_jiffies(delay2));
if (! snd_m3_try_read_vendor(chip))
break;
delay1 += 10;
delay2 += 100;
snd_printd("maestro3: retrying codec reset with delays of %d and %d ms\n",
delay1, delay2);
}
#if 0
tmp = inw(io + RING_BUS_CTRL_A);
outw(RAC_SDFS_ENABLE|LAC_SDFS_ENABLE, io + RING_BUS_CTRL_A);
msleep(20);
outw(tmp, io + RING_BUS_CTRL_A);
msleep(50);
#endif
}
static int __devinit snd_m3_mixer(struct snd_m3 *chip)
{
struct snd_ac97_bus *pbus;
struct snd_ac97_template ac97;
#ifndef CONFIG_SND_MAESTRO3_INPUT
struct snd_ctl_elem_id elem_id;
#endif
int err;
static struct snd_ac97_bus_ops ops = {
.write = snd_m3_ac97_write,
.read = snd_m3_ac97_read,
};
if ((err = snd_ac97_bus(chip->card, 0, &ops, NULL, &pbus)) < 0)
return err;
memset(&ac97, 0, sizeof(ac97));
ac97.private_data = chip;
if ((err = snd_ac97_mixer(pbus, &ac97, &chip->ac97)) < 0)
return err;
snd_ac97_write(chip->ac97, AC97_PCM, 0x8000 | (15 << 8) | 15);
schedule_timeout_uninterruptible(msecs_to_jiffies(100));
snd_ac97_write(chip->ac97, AC97_PCM, 0);
#ifndef CONFIG_SND_MAESTRO3_INPUT
memset(&elem_id, 0, sizeof(elem_id));
elem_id.iface = SNDRV_CTL_ELEM_IFACE_MIXER;
strcpy(elem_id.name, "Master Playback Switch");
chip->master_switch = snd_ctl_find_id(chip->card, &elem_id);
memset(&elem_id, 0, sizeof(elem_id));
elem_id.iface = SNDRV_CTL_ELEM_IFACE_MIXER;
strcpy(elem_id.name, "Master Playback Volume");
chip->master_volume = snd_ctl_find_id(chip->card, &elem_id);
#endif
return 0;
}
static void snd_m3_assp_init(struct snd_m3 *chip)
{
unsigned int i;
const u16 *data;
for (i = 0; i < (REV_B_DATA_MEMORY_UNIT_LENGTH * NUM_UNITS_KERNEL_DATA) / 2; i++)
snd_m3_assp_write(chip, MEMTYPE_INTERNAL_DATA,
KDATA_BASE_ADDR + i, 0);
for (i = 0; i < (REV_B_DATA_MEMORY_UNIT_LENGTH * NUM_UNITS_KERNEL_DATA) / 2; i++)
snd_m3_assp_write(chip, MEMTYPE_INTERNAL_DATA,
KDATA_BASE_ADDR2 + i, 0);
snd_m3_assp_write(chip, MEMTYPE_INTERNAL_DATA,
KDATA_CURRENT_DMA,
KDATA_DMA_XFER0);
data = (const u16 *)chip->assp_kernel_image->data;
for (i = 0 ; i * 2 < chip->assp_kernel_image->size; i++) {
snd_m3_assp_write(chip, MEMTYPE_INTERNAL_CODE,
REV_B_CODE_MEMORY_BEGIN + i,
le16_to_cpu(data[i]));
}
data = (const u16 *)chip->assp_minisrc_image->data;
for (i = 0; i * 2 < chip->assp_minisrc_image->size; i++) {
snd_m3_assp_write(chip, MEMTYPE_INTERNAL_CODE,
0x400 + i, le16_to_cpu(data[i]));
}
for (i = 0; i < MINISRC_LPF_LEN ; i++) {
snd_m3_assp_write(chip, MEMTYPE_INTERNAL_CODE,
0x400 + MINISRC_COEF_LOC + i,
minisrc_lpf[i]);
}
snd_m3_assp_write(chip, MEMTYPE_INTERNAL_CODE,
0x400 + MINISRC_COEF_LOC + MINISRC_LPF_LEN,
0x8000);
snd_m3_assp_write(chip, MEMTYPE_INTERNAL_DATA,
KDATA_TASK0,
0x400);
snd_m3_assp_write(chip, MEMTYPE_INTERNAL_DATA,
KDATA_MIXER_TASK_NUMBER,0);
snd_m3_assp_write(chip, MEMTYPE_INTERNAL_DATA,
KDATA_DAC_LEFT_VOLUME, ARB_VOLUME);
snd_m3_assp_write(chip, MEMTYPE_INTERNAL_DATA,
KDATA_DAC_RIGHT_VOLUME, ARB_VOLUME);
chip->mixer_list.curlen = 0;
chip->mixer_list.mem_addr = KDATA_MIXER_XFER0;
chip->mixer_list.max = MAX_VIRTUAL_MIXER_CHANNELS;
chip->adc1_list.curlen = 0;
chip->adc1_list.mem_addr = KDATA_ADC1_XFER0;
chip->adc1_list.max = MAX_VIRTUAL_ADC1_CHANNELS;
chip->dma_list.curlen = 0;
chip->dma_list.mem_addr = KDATA_DMA_XFER0;
chip->dma_list.max = MAX_VIRTUAL_DMA_CHANNELS;
chip->msrc_list.curlen = 0;
chip->msrc_list.mem_addr = KDATA_INSTANCE0_MINISRC;
chip->msrc_list.max = MAX_INSTANCE_MINISRC;
}
static int __devinit snd_m3_assp_client_init(struct snd_m3 *chip, struct m3_dma *s, int index)
{
int data_bytes = 2 * ( MINISRC_TMP_BUFFER_SIZE / 2 +
MINISRC_IN_BUFFER_SIZE / 2 +
1 + MINISRC_OUT_BUFFER_SIZE / 2 + 1 );
int address, i;
data_bytes = ALIGN(data_bytes, 256);
address = 0x1100 + ((data_bytes/2) * index);
if ((address + (data_bytes/2)) >= 0x1c00) {
snd_printk(KERN_ERR "no memory for %d bytes at ind %d (addr 0x%x)\n",
data_bytes, index, address);
return -ENOMEM;
}
s->number = index;
s->inst.code = 0x400;
s->inst.data = address;
for (i = data_bytes / 2; i > 0; address++, i--) {
snd_m3_assp_write(chip, MEMTYPE_INTERNAL_DATA,
address, 0);
}
return 0;
}
static void
snd_m3_amp_enable(struct snd_m3 *chip, int enable)
{
int io = chip->iobase;
u16 gpo, polarity;
if (! chip->external_amp)
return;
polarity = enable ? 0 : 1;
polarity = polarity << chip->amp_gpio;
gpo = 1 << chip->amp_gpio;
outw(~gpo, io + GPIO_MASK);
outw(inw(io + GPIO_DIRECTION) | gpo,
io + GPIO_DIRECTION);
outw((GPO_SECONDARY_AC97 | GPO_PRIMARY_AC97 | polarity),
io + GPIO_DATA);
outw(0xffff, io + GPIO_MASK);
}
static void
snd_m3_hv_init(struct snd_m3 *chip)
{
unsigned long io = chip->iobase;
u16 val = GPI_VOL_DOWN | GPI_VOL_UP;
if (!chip->is_omnibook)
return;
outw(0xffff, io + GPIO_MASK);
outw(0x0000, io + GPIO_DATA);
outw(~val, io + GPIO_MASK);
outw(inw(io + GPIO_DIRECTION) & ~val, io + GPIO_DIRECTION);
outw(val, io + GPIO_MASK);
outw(0xffff, io + GPIO_MASK);
}
static int
snd_m3_chip_init(struct snd_m3 *chip)
{
struct pci_dev *pcidev = chip->pci;
unsigned long io = chip->iobase;
u32 n;
u16 w;
u8 t;
pci_read_config_word(pcidev, PCI_LEGACY_AUDIO_CTRL, &w);
w &= ~(SOUND_BLASTER_ENABLE|FM_SYNTHESIS_ENABLE|
MPU401_IO_ENABLE|MPU401_IRQ_ENABLE|ALIAS_10BIT_IO|
DISABLE_LEGACY);
pci_write_config_word(pcidev, PCI_LEGACY_AUDIO_CTRL, w);
pci_read_config_dword(pcidev, PCI_ALLEGRO_CONFIG, &n);
n &= ~(HV_CTRL_ENABLE | REDUCED_DEBOUNCE | HV_BUTTON_FROM_GD);
n |= chip->hv_config;
n |= REDUCED_DEBOUNCE;
n |= PM_CTRL_ENABLE | CLK_DIV_BY_49 | USE_PCI_TIMING;
pci_write_config_dword(pcidev, PCI_ALLEGRO_CONFIG, n);
outb(RESET_ASSP, chip->iobase + ASSP_CONTROL_B);
pci_read_config_dword(pcidev, PCI_ALLEGRO_CONFIG, &n);
n &= ~INT_CLK_SELECT;
if (!chip->allegro_flag) {
n &= ~INT_CLK_MULT_ENABLE;
n |= INT_CLK_SRC_NOT_PCI;
}
n &= ~( CLK_MULT_MODE_SELECT | CLK_MULT_MODE_SELECT_2 );
pci_write_config_dword(pcidev, PCI_ALLEGRO_CONFIG, n);
if (chip->allegro_flag) {
pci_read_config_dword(pcidev, PCI_USER_CONFIG, &n);
n |= IN_CLK_12MHZ_SELECT;
pci_write_config_dword(pcidev, PCI_USER_CONFIG, n);
}
t = inb(chip->iobase + ASSP_CONTROL_A);
t &= ~( DSP_CLK_36MHZ_SELECT | ASSP_CLK_49MHZ_SELECT);
t |= ASSP_CLK_49MHZ_SELECT;
t |= ASSP_0_WS_ENABLE;
outb(t, chip->iobase + ASSP_CONTROL_A);
snd_m3_assp_init(chip);
outb(RUN_ASSP, chip->iobase + ASSP_CONTROL_B);
outb(0x00, io + HARDWARE_VOL_CTRL);
outb(0x88, io + SHADOW_MIX_REG_VOICE);
outb(0x88, io + HW_VOL_COUNTER_VOICE);
outb(0x88, io + SHADOW_MIX_REG_MASTER);
outb(0x88, io + HW_VOL_COUNTER_MASTER);
return 0;
}
static void
snd_m3_enable_ints(struct snd_m3 *chip)
{
unsigned long io = chip->iobase;
unsigned short val;
val = ASSP_INT_ENABLE ;
if (chip->hv_config & HV_CTRL_ENABLE)
val |= HV_INT_ENABLE;
outb(val, chip->iobase + HOST_INT_STATUS);
outw(val, io + HOST_INT_CTRL);
outb(inb(io + ASSP_CONTROL_C) | ASSP_HOST_INT_ENABLE,
io + ASSP_CONTROL_C);
}
static int snd_m3_free(struct snd_m3 *chip)
{
struct m3_dma *s;
int i;
cancel_work_sync(&chip->hwvol_work);
#ifdef CONFIG_SND_MAESTRO3_INPUT
if (chip->input_dev)
input_unregister_device(chip->input_dev);
#endif
if (chip->substreams) {
spin_lock_irq(&chip->reg_lock);
for (i = 0; i < chip->num_substreams; i++) {
s = &chip->substreams[i];
if (s->substream && s->running)
snd_m3_pcm_stop(chip, s, s->substream);
}
spin_unlock_irq(&chip->reg_lock);
kfree(chip->substreams);
}
if (chip->iobase) {
outw(0, chip->iobase + HOST_INT_CTRL);
}
#ifdef CONFIG_PM
vfree(chip->suspend_mem);
#endif
if (chip->irq >= 0)
free_irq(chip->irq, chip);
if (chip->iobase)
pci_release_regions(chip->pci);
release_firmware(chip->assp_kernel_image);
release_firmware(chip->assp_minisrc_image);
pci_disable_device(chip->pci);
kfree(chip);
return 0;
}
static int m3_suspend(struct pci_dev *pci, pm_message_t state)
{
struct snd_card *card = pci_get_drvdata(pci);
struct snd_m3 *chip = card->private_data;
int i, dsp_index;
if (chip->suspend_mem == NULL)
return 0;
chip->in_suspend = 1;
cancel_work_sync(&chip->hwvol_work);
snd_power_change_state(card, SNDRV_CTL_POWER_D3hot);
snd_pcm_suspend_all(chip->pcm);
snd_ac97_suspend(chip->ac97);
msleep(10);
snd_m3_assp_halt(chip);
dsp_index = 0;
for (i = REV_B_CODE_MEMORY_BEGIN; i <= REV_B_CODE_MEMORY_END; i++)
chip->suspend_mem[dsp_index++] =
snd_m3_assp_read(chip, MEMTYPE_INTERNAL_CODE, i);
for (i = REV_B_DATA_MEMORY_BEGIN ; i <= REV_B_DATA_MEMORY_END; i++)
chip->suspend_mem[dsp_index++] =
snd_m3_assp_read(chip, MEMTYPE_INTERNAL_DATA, i);
pci_disable_device(pci);
pci_save_state(pci);
pci_set_power_state(pci, pci_choose_state(pci, state));
return 0;
}
static int m3_resume(struct pci_dev *pci)
{
struct snd_card *card = pci_get_drvdata(pci);
struct snd_m3 *chip = card->private_data;
int i, dsp_index;
if (chip->suspend_mem == NULL)
return 0;
pci_set_power_state(pci, PCI_D0);
pci_restore_state(pci);
if (pci_enable_device(pci) < 0) {
printk(KERN_ERR "maestor3: pci_enable_device failed, "
"disabling device\n");
snd_card_disconnect(card);
return -EIO;
}
pci_set_master(pci);
snd_m3_outw(chip, 0, 0x54);
snd_m3_outw(chip, 0, 0x56);
snd_m3_chip_init(chip);
snd_m3_assp_halt(chip);
snd_m3_ac97_reset(chip);
dsp_index = 0;
for (i = REV_B_CODE_MEMORY_BEGIN; i <= REV_B_CODE_MEMORY_END; i++)
snd_m3_assp_write(chip, MEMTYPE_INTERNAL_CODE, i,
chip->suspend_mem[dsp_index++]);
for (i = REV_B_DATA_MEMORY_BEGIN ; i <= REV_B_DATA_MEMORY_END; i++)
snd_m3_assp_write(chip, MEMTYPE_INTERNAL_DATA, i,
chip->suspend_mem[dsp_index++]);
snd_m3_assp_write(chip, MEMTYPE_INTERNAL_DATA,
KDATA_DMA_ACTIVE, 0);
snd_ac97_resume(chip->ac97);
snd_m3_assp_continue(chip);
snd_m3_enable_ints(chip);
snd_m3_amp_enable(chip, 1);
snd_m3_hv_init(chip);
snd_power_change_state(card, SNDRV_CTL_POWER_D0);
chip->in_suspend = 0;
return 0;
}
static int __devinit snd_m3_input_register(struct snd_m3 *chip)
{
struct input_dev *input_dev;
int err;
input_dev = input_allocate_device();
if (!input_dev)
return -ENOMEM;
snprintf(chip->phys, sizeof(chip->phys), "pci-%s/input0",
pci_name(chip->pci));
input_dev->name = chip->card->driver;
input_dev->phys = chip->phys;
input_dev->id.bustype = BUS_PCI;
input_dev->id.vendor = chip->pci->vendor;
input_dev->id.product = chip->pci->device;
input_dev->dev.parent = &chip->pci->dev;
__set_bit(EV_KEY, input_dev->evbit);
__set_bit(KEY_MUTE, input_dev->keybit);
__set_bit(KEY_VOLUMEDOWN, input_dev->keybit);
__set_bit(KEY_VOLUMEUP, input_dev->keybit);
err = input_register_device(input_dev);
if (err) {
input_free_device(input_dev);
return err;
}
chip->input_dev = input_dev;
return 0;
}
static int snd_m3_dev_free(struct snd_device *device)
{
struct snd_m3 *chip = device->device_data;
return snd_m3_free(chip);
}
static int __devinit
snd_m3_create(struct snd_card *card, struct pci_dev *pci,
int enable_amp,
int amp_gpio,
struct snd_m3 **chip_ret)
{
struct snd_m3 *chip;
int i, err;
const struct snd_pci_quirk *quirk;
static struct snd_device_ops ops = {
.dev_free = snd_m3_dev_free,
};
*chip_ret = NULL;
if (pci_enable_device(pci))
return -EIO;
if (pci_set_dma_mask(pci, DMA_BIT_MASK(28)) < 0 ||
pci_set_consistent_dma_mask(pci, DMA_BIT_MASK(28)) < 0) {
snd_printk(KERN_ERR "architecture does not support 28bit PCI busmaster DMA\n");
pci_disable_device(pci);
return -ENXIO;
}
chip = kzalloc(sizeof(*chip), GFP_KERNEL);
if (chip == NULL) {
pci_disable_device(pci);
return -ENOMEM;
}
spin_lock_init(&chip->reg_lock);
switch (pci->device) {
case PCI_DEVICE_ID_ESS_ALLEGRO:
case PCI_DEVICE_ID_ESS_ALLEGRO_1:
case PCI_DEVICE_ID_ESS_CANYON3D_2LE:
case PCI_DEVICE_ID_ESS_CANYON3D_2:
chip->allegro_flag = 1;
break;
}
chip->card = card;
chip->pci = pci;
chip->irq = -1;
INIT_WORK(&chip->hwvol_work, snd_m3_update_hw_volume);
chip->external_amp = enable_amp;
if (amp_gpio >= 0 && amp_gpio <= 0x0f)
chip->amp_gpio = amp_gpio;
else {
quirk = snd_pci_quirk_lookup(pci, m3_amp_quirk_list);
if (quirk) {
snd_printdd(KERN_INFO "maestro3: set amp-gpio "
"for '%s'\n", quirk->name);
chip->amp_gpio = quirk->value;
} else if (chip->allegro_flag)
chip->amp_gpio = GPO_EXT_AMP_ALLEGRO;
else
chip->amp_gpio = GPO_EXT_AMP_M3;
}
quirk = snd_pci_quirk_lookup(pci, m3_irda_quirk_list);
if (quirk) {
snd_printdd(KERN_INFO "maestro3: enabled irda workaround "
"for '%s'\n", quirk->name);
chip->irda_workaround = 1;
}
quirk = snd_pci_quirk_lookup(pci, m3_hv_quirk_list);
if (quirk)
chip->hv_config = quirk->value;
if (snd_pci_quirk_lookup(pci, m3_omnibook_quirk_list))
chip->is_omnibook = 1;
chip->num_substreams = NR_DSPS;
chip->substreams = kcalloc(chip->num_substreams, sizeof(struct m3_dma),
GFP_KERNEL);
if (chip->substreams == NULL) {
kfree(chip);
pci_disable_device(pci);
return -ENOMEM;
}
err = request_firmware(&chip->assp_kernel_image,
"ess/maestro3_assp_kernel.fw", &pci->dev);
if (err < 0) {
snd_m3_free(chip);
return err;
}
err = request_firmware(&chip->assp_minisrc_image,
"ess/maestro3_assp_minisrc.fw", &pci->dev);
if (err < 0) {
snd_m3_free(chip);
return err;
}
if ((err = pci_request_regions(pci, card->driver)) < 0) {
snd_m3_free(chip);
return err;
}
chip->iobase = pci_resource_start(pci, 0);
pci_set_master(pci);
snd_m3_chip_init(chip);
snd_m3_assp_halt(chip);
snd_m3_ac97_reset(chip);
snd_m3_amp_enable(chip, 1);
snd_m3_hv_init(chip);
if (request_irq(pci->irq, snd_m3_interrupt, IRQF_SHARED,
KBUILD_MODNAME, chip)) {
snd_printk(KERN_ERR "unable to grab IRQ %d\n", pci->irq);
snd_m3_free(chip);
return -ENOMEM;
}
chip->irq = pci->irq;
#ifdef CONFIG_PM
chip->suspend_mem = vmalloc(sizeof(u16) * (REV_B_CODE_MEMORY_LENGTH + REV_B_DATA_MEMORY_LENGTH));
if (chip->suspend_mem == NULL)
snd_printk(KERN_WARNING "can't allocate apm buffer\n");
#endif
if ((err = snd_device_new(card, SNDRV_DEV_LOWLEVEL, chip, &ops)) < 0) {
snd_m3_free(chip);
return err;
}
if ((err = snd_m3_mixer(chip)) < 0)
return err;
for (i = 0; i < chip->num_substreams; i++) {
struct m3_dma *s = &chip->substreams[i];
if ((err = snd_m3_assp_client_init(chip, s, i)) < 0)
return err;
}
if ((err = snd_m3_pcm(chip, 0)) < 0)
return err;
#ifdef CONFIG_SND_MAESTRO3_INPUT
if (chip->hv_config & HV_CTRL_ENABLE) {
err = snd_m3_input_register(chip);
if (err)
snd_printk(KERN_WARNING "Input device registration "
"failed with error %i", err);
}
#endif
snd_m3_enable_ints(chip);
snd_m3_assp_continue(chip);
snd_card_set_dev(card, &pci->dev);
*chip_ret = chip;
return 0;
}
static int __devinit
snd_m3_probe(struct pci_dev *pci, const struct pci_device_id *pci_id)
{
static int dev;
struct snd_card *card;
struct snd_m3 *chip;
int err;
if (((pci->class >> 8) & 0xffff) != PCI_CLASS_MULTIMEDIA_AUDIO)
return -ENODEV;
if (dev >= SNDRV_CARDS)
return -ENODEV;
if (!enable[dev]) {
dev++;
return -ENOENT;
}
err = snd_card_create(index[dev], id[dev], THIS_MODULE, 0, &card);
if (err < 0)
return err;
switch (pci->device) {
case PCI_DEVICE_ID_ESS_ALLEGRO:
case PCI_DEVICE_ID_ESS_ALLEGRO_1:
strcpy(card->driver, "Allegro");
break;
case PCI_DEVICE_ID_ESS_CANYON3D_2LE:
case PCI_DEVICE_ID_ESS_CANYON3D_2:
strcpy(card->driver, "Canyon3D-2");
break;
default:
strcpy(card->driver, "Maestro3");
break;
}
if ((err = snd_m3_create(card, pci,
external_amp[dev],
amp_gpio[dev],
&chip)) < 0) {
snd_card_free(card);
return err;
}
card->private_data = chip;
sprintf(card->shortname, "ESS %s PCI", card->driver);
sprintf(card->longname, "%s at 0x%lx, irq %d",
card->shortname, chip->iobase, chip->irq);
if ((err = snd_card_register(card)) < 0) {
snd_card_free(card);
return err;
}
#if 0
err = snd_mpu401_uart_new(chip->card, 0, MPU401_HW_MPU401,
chip->iobase + MPU401_DATA_PORT,
MPU401_INFO_INTEGRATED | MPU401_INFO_IRQ_HOOK,
-1, &chip->rmidi);
if (err < 0)
printk(KERN_WARNING "maestro3: no MIDI support.\n");
#endif
pci_set_drvdata(pci, card);
dev++;
return 0;
}
static void __devexit snd_m3_remove(struct pci_dev *pci)
{
snd_card_free(pci_get_drvdata(pci));
pci_set_drvdata(pci, NULL);
}
