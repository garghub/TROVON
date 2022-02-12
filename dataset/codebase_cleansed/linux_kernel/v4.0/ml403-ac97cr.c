static void lm4550_regfile_init(void)
{
int i;
for (i = 0; i < 64; i++)
if (lm4550_regfile[i].flag & LM4550_REG_FAKEPROBE)
lm4550_regfile[i].value = lm4550_regfile[i].def;
}
static void lm4550_regfile_write_values_after_init(struct snd_ac97 *ac97)
{
int i;
for (i = 0; i < 64; i++)
if ((lm4550_regfile[i].flag & LM4550_REG_FAKEPROBE) &&
(lm4550_regfile[i].value != lm4550_regfile[i].def)) {
PDEBUG(CODEC_FAKE, "lm4550_regfile_write_values_after_"
"init(): reg=0x%x value=0x%x / %d is different "
"from def=0x%x / %d\n",
i, lm4550_regfile[i].value,
lm4550_regfile[i].value, lm4550_regfile[i].def,
lm4550_regfile[i].def);
snd_ac97_write(ac97, i * 2, lm4550_regfile[i].value);
lm4550_regfile[i].flag |= LM4550_REG_DONEREAD;
}
}
static size_t
snd_ml403_ac97cr_playback_ind2_zero(struct snd_pcm_substream *substream,
struct snd_pcm_indirect2 *rec)
{
struct snd_ml403_ac97cr *ml403_ac97cr;
int copied_words = 0;
u32 full = 0;
ml403_ac97cr = snd_pcm_substream_chip(substream);
spin_lock(&ml403_ac97cr->reg_lock);
while ((full = (in_be32(CR_REG(ml403_ac97cr, STATUS)) &
CR_PLAYFULL)) != CR_PLAYFULL) {
out_be32(CR_REG(ml403_ac97cr, PLAYFIFO), 0);
copied_words++;
}
rec->hw_ready = 0;
spin_unlock(&ml403_ac97cr->reg_lock);
return (size_t) (copied_words * 2);
}
static size_t
snd_ml403_ac97cr_playback_ind2_copy(struct snd_pcm_substream *substream,
struct snd_pcm_indirect2 *rec,
size_t bytes)
{
struct snd_ml403_ac97cr *ml403_ac97cr;
u16 *src;
int copied_words = 0;
u32 full = 0;
ml403_ac97cr = snd_pcm_substream_chip(substream);
src = (u16 *)(substream->runtime->dma_area + rec->sw_data);
spin_lock(&ml403_ac97cr->reg_lock);
while (((full = (in_be32(CR_REG(ml403_ac97cr, STATUS)) &
CR_PLAYFULL)) != CR_PLAYFULL) && (bytes > 1)) {
out_be32(CR_REG(ml403_ac97cr, PLAYFIFO),
CR_PLAYDATA(src[copied_words]));
copied_words++;
bytes = bytes - 2;
}
if (full != CR_PLAYFULL)
rec->hw_ready = 1;
else
rec->hw_ready = 0;
spin_unlock(&ml403_ac97cr->reg_lock);
return (size_t) (copied_words * 2);
}
static size_t
snd_ml403_ac97cr_capture_ind2_null(struct snd_pcm_substream *substream,
struct snd_pcm_indirect2 *rec)
{
struct snd_ml403_ac97cr *ml403_ac97cr;
int copied_words = 0;
u32 empty = 0;
ml403_ac97cr = snd_pcm_substream_chip(substream);
spin_lock(&ml403_ac97cr->reg_lock);
while ((empty = (in_be32(CR_REG(ml403_ac97cr, STATUS)) &
CR_RECEMPTY)) != CR_RECEMPTY) {
volatile u32 trash;
trash = CR_RECDATA(in_be32(CR_REG(ml403_ac97cr, RECFIFO)));
trash++;
copied_words++;
}
rec->hw_ready = 0;
spin_unlock(&ml403_ac97cr->reg_lock);
return (size_t) (copied_words * 2);
}
static size_t
snd_ml403_ac97cr_capture_ind2_copy(struct snd_pcm_substream *substream,
struct snd_pcm_indirect2 *rec, size_t bytes)
{
struct snd_ml403_ac97cr *ml403_ac97cr;
u16 *dst;
int copied_words = 0;
u32 empty = 0;
ml403_ac97cr = snd_pcm_substream_chip(substream);
dst = (u16 *)(substream->runtime->dma_area + rec->sw_data);
spin_lock(&ml403_ac97cr->reg_lock);
while (((empty = (in_be32(CR_REG(ml403_ac97cr, STATUS)) &
CR_RECEMPTY)) != CR_RECEMPTY) && (bytes > 1)) {
dst[copied_words] = CR_RECDATA(in_be32(CR_REG(ml403_ac97cr,
RECFIFO)));
copied_words++;
bytes = bytes - 2;
}
if (empty != CR_RECEMPTY)
rec->hw_ready = 1;
else
rec->hw_ready = 0;
spin_unlock(&ml403_ac97cr->reg_lock);
return (size_t) (copied_words * 2);
}
static snd_pcm_uframes_t
snd_ml403_ac97cr_pcm_pointer(struct snd_pcm_substream *substream)
{
struct snd_ml403_ac97cr *ml403_ac97cr;
struct snd_pcm_indirect2 *ind2_rec = NULL;
ml403_ac97cr = snd_pcm_substream_chip(substream);
if (substream == ml403_ac97cr->playback_substream)
ind2_rec = &ml403_ac97cr->ind_rec;
if (substream == ml403_ac97cr->capture_substream)
ind2_rec = &ml403_ac97cr->capture_ind2_rec;
if (ind2_rec != NULL)
return snd_pcm_indirect2_pointer(substream, ind2_rec);
return (snd_pcm_uframes_t) 0;
}
static int
snd_ml403_ac97cr_pcm_playback_trigger(struct snd_pcm_substream *substream,
int cmd)
{
struct snd_ml403_ac97cr *ml403_ac97cr;
int err = 0;
ml403_ac97cr = snd_pcm_substream_chip(substream);
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
PDEBUG(WORK_INFO, "trigger(playback): START\n");
ml403_ac97cr->ind_rec.hw_ready = 1;
out_be32(CR_REG(ml403_ac97cr, RESETFIFO), CR_PLAYRESET);
ml403_ac97cr->enable_irq = 1;
enable_irq(ml403_ac97cr->irq);
break;
case SNDRV_PCM_TRIGGER_STOP:
PDEBUG(WORK_INFO, "trigger(playback): STOP\n");
ml403_ac97cr->ind_rec.hw_ready = 0;
#ifdef SND_PCM_INDIRECT2_STAT
snd_pcm_indirect2_stat(substream, &ml403_ac97cr->ind_rec);
#endif
disable_irq_nosync(ml403_ac97cr->irq);
ml403_ac97cr->enable_irq = 0;
break;
default:
err = -EINVAL;
break;
}
PDEBUG(WORK_INFO, "trigger(playback): (done)\n");
return err;
}
static int
snd_ml403_ac97cr_pcm_capture_trigger(struct snd_pcm_substream *substream,
int cmd)
{
struct snd_ml403_ac97cr *ml403_ac97cr;
int err = 0;
ml403_ac97cr = snd_pcm_substream_chip(substream);
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
PDEBUG(WORK_INFO, "trigger(capture): START\n");
ml403_ac97cr->capture_ind2_rec.hw_ready = 0;
out_be32(CR_REG(ml403_ac97cr, RESETFIFO), CR_RECRESET);
ml403_ac97cr->enable_capture_irq = 1;
enable_irq(ml403_ac97cr->capture_irq);
break;
case SNDRV_PCM_TRIGGER_STOP:
PDEBUG(WORK_INFO, "trigger(capture): STOP\n");
ml403_ac97cr->capture_ind2_rec.hw_ready = 0;
#ifdef SND_PCM_INDIRECT2_STAT
snd_pcm_indirect2_stat(substream,
&ml403_ac97cr->capture_ind2_rec);
#endif
disable_irq_nosync(ml403_ac97cr->capture_irq);
ml403_ac97cr->enable_capture_irq = 0;
break;
default:
err = -EINVAL;
break;
}
PDEBUG(WORK_INFO, "trigger(capture): (done)\n");
return err;
}
static int
snd_ml403_ac97cr_pcm_playback_prepare(struct snd_pcm_substream *substream)
{
struct snd_ml403_ac97cr *ml403_ac97cr;
struct snd_pcm_runtime *runtime;
ml403_ac97cr = snd_pcm_substream_chip(substream);
runtime = substream->runtime;
PDEBUG(WORK_INFO,
"prepare(): period_bytes=%d, minperiod_bytes=%d\n",
snd_pcm_lib_period_bytes(substream), CR_FIFO_SIZE / 2);
snd_ac97_set_rate(ml403_ac97cr->ac97, AC97_PCM_FRONT_DAC_RATE,
runtime->rate);
PDEBUG(WORK_INFO, "prepare(): rate=%d\n", runtime->rate);
memset(&ml403_ac97cr->ind_rec, 0,
sizeof(struct snd_pcm_indirect2));
ml403_ac97cr->ind_rec.hw_buffer_size = CR_FIFO_SIZE;
ml403_ac97cr->ind_rec.sw_buffer_size =
snd_pcm_lib_buffer_bytes(substream);
ml403_ac97cr->ind_rec.min_periods = -1;
ml403_ac97cr->ind_rec.min_multiple =
snd_pcm_lib_period_bytes(substream) / (CR_FIFO_SIZE / 2);
PDEBUG(WORK_INFO, "prepare(): hw_buffer_size=%d, "
"sw_buffer_size=%d, min_multiple=%d\n",
CR_FIFO_SIZE, ml403_ac97cr->ind_rec.sw_buffer_size,
ml403_ac97cr->ind_rec.min_multiple);
return 0;
}
static int
snd_ml403_ac97cr_pcm_capture_prepare(struct snd_pcm_substream *substream)
{
struct snd_ml403_ac97cr *ml403_ac97cr;
struct snd_pcm_runtime *runtime;
ml403_ac97cr = snd_pcm_substream_chip(substream);
runtime = substream->runtime;
PDEBUG(WORK_INFO,
"prepare(capture): period_bytes=%d, minperiod_bytes=%d\n",
snd_pcm_lib_period_bytes(substream), CR_FIFO_SIZE / 2);
snd_ac97_set_rate(ml403_ac97cr->ac97, AC97_PCM_LR_ADC_RATE,
runtime->rate);
PDEBUG(WORK_INFO, "prepare(capture): rate=%d\n", runtime->rate);
memset(&ml403_ac97cr->capture_ind2_rec, 0,
sizeof(struct snd_pcm_indirect2));
ml403_ac97cr->capture_ind2_rec.hw_buffer_size = CR_FIFO_SIZE;
ml403_ac97cr->capture_ind2_rec.sw_buffer_size =
snd_pcm_lib_buffer_bytes(substream);
ml403_ac97cr->capture_ind2_rec.min_multiple =
snd_pcm_lib_period_bytes(substream) / (CR_FIFO_SIZE / 2);
PDEBUG(WORK_INFO, "prepare(capture): hw_buffer_size=%d, "
"sw_buffer_size=%d, min_multiple=%d\n", CR_FIFO_SIZE,
ml403_ac97cr->capture_ind2_rec.sw_buffer_size,
ml403_ac97cr->capture_ind2_rec.min_multiple);
return 0;
}
static int snd_ml403_ac97cr_hw_free(struct snd_pcm_substream *substream)
{
PDEBUG(WORK_INFO, "hw_free()\n");
return snd_pcm_lib_free_pages(substream);
}
static int
snd_ml403_ac97cr_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *hw_params)
{
PDEBUG(WORK_INFO, "hw_params(): desired buffer bytes=%d, desired "
"period bytes=%d\n",
params_buffer_bytes(hw_params), params_period_bytes(hw_params));
return snd_pcm_lib_malloc_pages(substream,
params_buffer_bytes(hw_params));
}
static int snd_ml403_ac97cr_playback_open(struct snd_pcm_substream *substream)
{
struct snd_ml403_ac97cr *ml403_ac97cr;
struct snd_pcm_runtime *runtime;
ml403_ac97cr = snd_pcm_substream_chip(substream);
runtime = substream->runtime;
PDEBUG(WORK_INFO, "open(playback)\n");
ml403_ac97cr->playback_substream = substream;
runtime->hw = snd_ml403_ac97cr_playback;
snd_pcm_hw_constraint_step(runtime, 0,
SNDRV_PCM_HW_PARAM_PERIOD_BYTES,
CR_FIFO_SIZE / 2);
return 0;
}
static int snd_ml403_ac97cr_capture_open(struct snd_pcm_substream *substream)
{
struct snd_ml403_ac97cr *ml403_ac97cr;
struct snd_pcm_runtime *runtime;
ml403_ac97cr = snd_pcm_substream_chip(substream);
runtime = substream->runtime;
PDEBUG(WORK_INFO, "open(capture)\n");
ml403_ac97cr->capture_substream = substream;
runtime->hw = snd_ml403_ac97cr_capture;
snd_pcm_hw_constraint_step(runtime, 0,
SNDRV_PCM_HW_PARAM_PERIOD_BYTES,
CR_FIFO_SIZE / 2);
return 0;
}
static int snd_ml403_ac97cr_playback_close(struct snd_pcm_substream *substream)
{
struct snd_ml403_ac97cr *ml403_ac97cr;
ml403_ac97cr = snd_pcm_substream_chip(substream);
PDEBUG(WORK_INFO, "close(playback)\n");
ml403_ac97cr->playback_substream = NULL;
return 0;
}
static int snd_ml403_ac97cr_capture_close(struct snd_pcm_substream *substream)
{
struct snd_ml403_ac97cr *ml403_ac97cr;
ml403_ac97cr = snd_pcm_substream_chip(substream);
PDEBUG(WORK_INFO, "close(capture)\n");
ml403_ac97cr->capture_substream = NULL;
return 0;
}
static irqreturn_t snd_ml403_ac97cr_irq(int irq, void *dev_id)
{
struct snd_ml403_ac97cr *ml403_ac97cr;
struct platform_device *pfdev;
int cmp_irq;
ml403_ac97cr = (struct snd_ml403_ac97cr *)dev_id;
if (ml403_ac97cr == NULL)
return IRQ_NONE;
pfdev = ml403_ac97cr->pfdev;
cmp_irq = platform_get_irq(pfdev, 0);
if (irq == cmp_irq) {
if (ml403_ac97cr->enable_irq)
snd_pcm_indirect2_playback_interrupt(
ml403_ac97cr->playback_substream,
&ml403_ac97cr->ind_rec,
snd_ml403_ac97cr_playback_ind2_copy,
snd_ml403_ac97cr_playback_ind2_zero);
else
goto __disable_irq;
} else {
cmp_irq = platform_get_irq(pfdev, 1);
if (irq == cmp_irq) {
if (ml403_ac97cr->enable_capture_irq)
snd_pcm_indirect2_capture_interrupt(
ml403_ac97cr->capture_substream,
&ml403_ac97cr->capture_ind2_rec,
snd_ml403_ac97cr_capture_ind2_copy,
snd_ml403_ac97cr_capture_ind2_null);
else
goto __disable_irq;
} else
return IRQ_NONE;
}
return IRQ_HANDLED;
__disable_irq:
PDEBUG(INIT_INFO, "irq(): irq %d is meant to be disabled! So, now try "
"to disable it _really_!\n", irq);
disable_irq_nosync(irq);
return IRQ_HANDLED;
}
static unsigned short
snd_ml403_ac97cr_codec_read(struct snd_ac97 *ac97, unsigned short reg)
{
struct snd_ml403_ac97cr *ml403_ac97cr = ac97->private_data;
#ifdef CODEC_STAT
u32 stat;
u32 rafaccess = 0;
#endif
unsigned long end_time;
u16 value = 0;
if (!LM4550_RF_OK(reg)) {
snd_printk(KERN_WARNING SND_ML403_AC97CR_DRIVER ": "
"access to unknown/unused codec register 0x%x "
"ignored!\n", reg);
return 0;
}
if ((lm4550_regfile[reg / 2].flag &
(LM4550_REG_DONEREAD | LM4550_REG_ALLFAKE)) &&
!(lm4550_regfile[reg / 2].flag & LM4550_REG_NOSHADOW)) {
if (lm4550_regfile[reg / 2].flag & LM4550_REG_FAKEREAD) {
PDEBUG(CODEC_FAKE, "codec_read(): faking read from "
"reg=0x%x, val=0x%x / %d\n",
reg, lm4550_regfile[reg / 2].def,
lm4550_regfile[reg / 2].def);
return lm4550_regfile[reg / 2].def;
} else if ((lm4550_regfile[reg / 2].flag &
LM4550_REG_FAKEPROBE) &&
ml403_ac97cr->ac97_fake) {
PDEBUG(CODEC_FAKE, "codec_read(): faking read from "
"reg=0x%x, val=0x%x / %d (probe)\n",
reg, lm4550_regfile[reg / 2].value,
lm4550_regfile[reg / 2].value);
return lm4550_regfile[reg / 2].value;
} else {
#ifdef CODEC_STAT
PDEBUG(CODEC_FAKE, "codec_read(): read access "
"answered by shadow register 0x%x (value=0x%x "
"/ %d) (cw=%d cr=%d)\n",
reg, lm4550_regfile[reg / 2].value,
lm4550_regfile[reg / 2].value,
ml403_ac97cr->ac97_write,
ml403_ac97cr->ac97_read);
#else
PDEBUG(CODEC_FAKE, "codec_read(): read access "
"answered by shadow register 0x%x (value=0x%x "
"/ %d)\n",
reg, lm4550_regfile[reg / 2].value,
lm4550_regfile[reg / 2].value);
#endif
return lm4550_regfile[reg / 2].value;
}
}
if (mutex_lock_interruptible(&ml403_ac97cr->cdc_mutex) != 0)
return 0;
#ifdef CODEC_STAT
ml403_ac97cr->ac97_read++;
#endif
spin_lock(&ml403_ac97cr->reg_lock);
out_be32(CR_REG(ml403_ac97cr, CODEC_ADDR),
CR_CODEC_ADDR(reg) | CR_CODEC_READ);
spin_unlock(&ml403_ac97cr->reg_lock);
end_time = jiffies + (HZ / CODEC_TIMEOUT_AFTER_READ);
do {
spin_lock(&ml403_ac97cr->reg_lock);
#ifdef CODEC_STAT
rafaccess++;
stat = in_be32(CR_REG(ml403_ac97cr, STATUS));
if ((stat & CR_RAF) == CR_RAF) {
value = CR_CODEC_DATAREAD(
in_be32(CR_REG(ml403_ac97cr, CODEC_DATAREAD)));
PDEBUG(CODEC_SUCCESS, "codec_read(): (done) reg=0x%x, "
"value=0x%x / %d (STATUS=0x%x)\n",
reg, value, value, stat);
#else
if ((in_be32(CR_REG(ml403_ac97cr, STATUS)) &
CR_RAF) == CR_RAF) {
value = CR_CODEC_DATAREAD(
in_be32(CR_REG(ml403_ac97cr, CODEC_DATAREAD)));
PDEBUG(CODEC_SUCCESS, "codec_read(): (done) "
"reg=0x%x, value=0x%x / %d\n",
reg, value, value);
#endif
lm4550_regfile[reg / 2].value = value;
lm4550_regfile[reg / 2].flag |= LM4550_REG_DONEREAD;
spin_unlock(&ml403_ac97cr->reg_lock);
mutex_unlock(&ml403_ac97cr->cdc_mutex);
return value;
}
spin_unlock(&ml403_ac97cr->reg_lock);
schedule_timeout_uninterruptible(1);
} while (time_after(end_time, jiffies));
spin_lock(&ml403_ac97cr->reg_lock);
value =
CR_CODEC_DATAREAD(in_be32(CR_REG(ml403_ac97cr, CODEC_DATAREAD)));
spin_unlock(&ml403_ac97cr->reg_lock);
#ifdef CODEC_STAT
snd_printk(KERN_WARNING SND_ML403_AC97CR_DRIVER ": "
"timeout while codec read! "
"(reg=0x%x, last STATUS=0x%x, DATAREAD=0x%x / %d, %d) "
"(cw=%d, cr=%d)\n",
reg, stat, value, value, rafaccess,
ml403_ac97cr->ac97_write, ml403_ac97cr->ac97_read);
#else
snd_printk(KERN_WARNING SND_ML403_AC97CR_DRIVER ": "
"timeout while codec read! "
"(reg=0x%x, DATAREAD=0x%x / %d)\n",
reg, value, value);
#endif
lm4550_regfile[reg / 2].value = value;
lm4550_regfile[reg / 2].flag |= LM4550_REG_DONEREAD;
mutex_unlock(&ml403_ac97cr->cdc_mutex);
return value;
}
static void
snd_ml403_ac97cr_codec_write(struct snd_ac97 *ac97, unsigned short reg,
unsigned short val)
{
struct snd_ml403_ac97cr *ml403_ac97cr = ac97->private_data;
#ifdef CODEC_STAT
u32 stat;
u32 rafaccess = 0;
#endif
#ifdef CODEC_WRITE_CHECK_RAF
unsigned long end_time;
#endif
if (!LM4550_RF_OK(reg)) {
snd_printk(KERN_WARNING SND_ML403_AC97CR_DRIVER ": "
"access to unknown/unused codec register 0x%x "
"ignored!\n", reg);
return;
}
if (lm4550_regfile[reg / 2].flag & LM4550_REG_READONLY) {
snd_printk(KERN_WARNING SND_ML403_AC97CR_DRIVER ": "
"write access to read only codec register 0x%x "
"ignored!\n", reg);
return;
}
if ((val & lm4550_regfile[reg / 2].wmask) != val) {
snd_printk(KERN_WARNING SND_ML403_AC97CR_DRIVER ": "
"write access to codec register 0x%x "
"with bad value 0x%x / %d!\n",
reg, val, val);
val = val & lm4550_regfile[reg / 2].wmask;
}
if (((lm4550_regfile[reg / 2].flag & LM4550_REG_FAKEPROBE) &&
ml403_ac97cr->ac97_fake) &&
!(lm4550_regfile[reg / 2].flag & LM4550_REG_NOSHADOW)) {
PDEBUG(CODEC_FAKE, "codec_write(): faking write to reg=0x%x, "
"val=0x%x / %d\n", reg, val, val);
lm4550_regfile[reg / 2].value = (val &
lm4550_regfile[reg / 2].wmask);
return;
}
if (mutex_lock_interruptible(&ml403_ac97cr->cdc_mutex) != 0)
return;
#ifdef CODEC_STAT
ml403_ac97cr->ac97_write++;
#endif
spin_lock(&ml403_ac97cr->reg_lock);
out_be32(CR_REG(ml403_ac97cr, CODEC_DATAWRITE),
CR_CODEC_DATAWRITE(val));
out_be32(CR_REG(ml403_ac97cr, CODEC_ADDR),
CR_CODEC_ADDR(reg) | CR_CODEC_WRITE);
spin_unlock(&ml403_ac97cr->reg_lock);
#ifdef CODEC_WRITE_CHECK_RAF
end_time = jiffies + HZ / CODEC_TIMEOUT_AFTER_WRITE;
do {
spin_lock(&ml403_ac97cr->reg_lock);
#ifdef CODEC_STAT
rafaccess++;
stat = in_be32(CR_REG(ml403_ac97cr, STATUS))
if ((stat & CR_RAF) == CR_RAF) {
#else
if ((in_be32(CR_REG(ml403_ac97cr, STATUS)) &
CR_RAF) == CR_RAF) {
#endif
PDEBUG(CODEC_SUCCESS, "codec_write(): (done) "
"reg=0x%x, value=%d / 0x%x\n",
reg, val, val);
if (!(lm4550_regfile[reg / 2].flag &
LM4550_REG_NOSHADOW) &&
!(lm4550_regfile[reg / 2].flag &
LM4550_REG_NOSAVE))
lm4550_regfile[reg / 2].value = val;
lm4550_regfile[reg / 2].flag |= LM4550_REG_DONEREAD;
spin_unlock(&ml403_ac97cr->reg_lock);
mutex_unlock(&ml403_ac97cr->cdc_mutex);
return;
}
spin_unlock(&ml403_ac97cr->reg_lock);
schedule_timeout_uninterruptible(1);
} while (time_after(end_time, jiffies));
#ifdef CODEC_STAT
snd_printk(KERN_WARNING SND_ML403_AC97CR_DRIVER ": "
"timeout while codec write "
"(reg=0x%x, val=0x%x / %d, last STATUS=0x%x, %d) "
"(cw=%d, cr=%d)\n",
reg, val, val, stat, rafaccess, ml403_ac97cr->ac97_write,
ml403_ac97cr->ac97_read);
#else
snd_printk(KERN_WARNING SND_ML403_AC97CR_DRIVER ": "
"timeout while codec write (reg=0x%x, val=0x%x / %d)\n",
reg, val, val);
#endif
#else
#if CODEC_WAIT_AFTER_WRITE > 0
schedule_timeout_uninterruptible(HZ / CODEC_WAIT_AFTER_WRITE);
#endif
PDEBUG(CODEC_SUCCESS, "codec_write(): (done) "
"reg=0x%x, value=%d / 0x%x (no RAF check)\n",
reg, val, val);
#endif
mutex_unlock(&ml403_ac97cr->cdc_mutex);
return;
}
static int
snd_ml403_ac97cr_chip_init(struct snd_ml403_ac97cr *ml403_ac97cr)
{
unsigned long end_time;
PDEBUG(INIT_INFO, "chip_init():\n");
end_time = jiffies + HZ / CODEC_TIMEOUT_ON_INIT;
do {
if (in_be32(CR_REG(ml403_ac97cr, STATUS)) & CR_CODECREADY) {
out_be32(CR_REG(ml403_ac97cr, RESETFIFO),
CR_RECRESET | CR_PLAYRESET);
PDEBUG(INIT_INFO, "chip_init(): (done)\n");
return 0;
}
schedule_timeout_uninterruptible(1);
} while (time_after(end_time, jiffies));
snd_printk(KERN_ERR SND_ML403_AC97CR_DRIVER ": "
"timeout while waiting for codec, "
"not ready!\n");
return -EBUSY;
}
static int snd_ml403_ac97cr_free(struct snd_ml403_ac97cr *ml403_ac97cr
static int snd_ml403_ac97cr_dev_free(struct snd_device *snddev)
{
struct snd_ml403_ac97cr *ml403_ac97cr = snddev->device_data;
PDEBUG(INIT_INFO, "dev_free():\n");
return snd_ml403_ac97cr_free(ml403_ac97cr);
}
static int
snd_ml403_ac97cr_create(struct snd_card *card, struct platform_device *pfdev,
struct snd_ml403_ac97cr **rml403_ac97cr)
{
struct snd_ml403_ac97cr *ml403_ac97cr;
int err;
static struct snd_device_ops ops = {
.dev_free = snd_ml403_ac97cr_dev_free,
};
struct resource *resource;
int irq;
*rml403_ac97cr = NULL;
ml403_ac97cr = kzalloc(sizeof(*ml403_ac97cr), GFP_KERNEL);
if (ml403_ac97cr == NULL)
return -ENOMEM;
spin_lock_init(&ml403_ac97cr->reg_lock);
mutex_init(&ml403_ac97cr->cdc_mutex);
ml403_ac97cr->card = card;
ml403_ac97cr->pfdev = pfdev;
ml403_ac97cr->irq = -1;
ml403_ac97cr->enable_irq = 0;
ml403_ac97cr->capture_irq = -1;
ml403_ac97cr->enable_capture_irq = 0;
ml403_ac97cr->port = NULL;
ml403_ac97cr->res_port = NULL;
PDEBUG(INIT_INFO, "Trying to reserve resources now ...\n");
resource = platform_get_resource(pfdev, IORESOURCE_MEM, 0);
ml403_ac97cr->port = ioremap_nocache(resource->start,
(resource->end) -
(resource->start) + 1);
if (ml403_ac97cr->port == NULL) {
snd_printk(KERN_ERR SND_ML403_AC97CR_DRIVER ": "
"unable to remap memory region (%pR)\n",
resource);
snd_ml403_ac97cr_free(ml403_ac97cr);
return -EBUSY;
}
snd_printk(KERN_INFO SND_ML403_AC97CR_DRIVER ": "
"remap controller memory region to "
"0x%x done\n", (unsigned int)ml403_ac97cr->port);
irq = platform_get_irq(pfdev, 0);
if (request_irq(irq, snd_ml403_ac97cr_irq, 0,
dev_name(&pfdev->dev), (void *)ml403_ac97cr)) {
snd_printk(KERN_ERR SND_ML403_AC97CR_DRIVER ": "
"unable to grab IRQ %d\n",
irq);
snd_ml403_ac97cr_free(ml403_ac97cr);
return -EBUSY;
}
ml403_ac97cr->irq = irq;
snd_printk(KERN_INFO SND_ML403_AC97CR_DRIVER ": "
"request (playback) irq %d done\n",
ml403_ac97cr->irq);
irq = platform_get_irq(pfdev, 1);
if (request_irq(irq, snd_ml403_ac97cr_irq, 0,
dev_name(&pfdev->dev), (void *)ml403_ac97cr)) {
snd_printk(KERN_ERR SND_ML403_AC97CR_DRIVER ": "
"unable to grab IRQ %d\n",
irq);
snd_ml403_ac97cr_free(ml403_ac97cr);
return -EBUSY;
}
ml403_ac97cr->capture_irq = irq;
snd_printk(KERN_INFO SND_ML403_AC97CR_DRIVER ": "
"request (capture) irq %d done\n",
ml403_ac97cr->capture_irq);
err = snd_ml403_ac97cr_chip_init(ml403_ac97cr);
if (err < 0) {
snd_ml403_ac97cr_free(ml403_ac97cr);
return err;
}
err = snd_device_new(card, SNDRV_DEV_LOWLEVEL, ml403_ac97cr, &ops);
if (err < 0) {
PDEBUG(INIT_FAILURE, "probe(): snd_device_new() failed!\n");
snd_ml403_ac97cr_free(ml403_ac97cr);
return err;
}
*rml403_ac97cr = ml403_ac97cr;
return 0;
}
static void snd_ml403_ac97cr_mixer_free(struct snd_ac97 *ac97)
{
struct snd_ml403_ac97cr *ml403_ac97cr = ac97->private_data;
PDEBUG(INIT_INFO, "mixer_free():\n");
ml403_ac97cr->ac97 = NULL;
PDEBUG(INIT_INFO, "mixer_free(): (done)\n");
}
static int
snd_ml403_ac97cr_mixer(struct snd_ml403_ac97cr *ml403_ac97cr)
{
struct snd_ac97_bus *bus;
struct snd_ac97_template ac97;
int err;
static struct snd_ac97_bus_ops ops = {
.write = snd_ml403_ac97cr_codec_write,
.read = snd_ml403_ac97cr_codec_read,
};
PDEBUG(INIT_INFO, "mixer():\n");
err = snd_ac97_bus(ml403_ac97cr->card, 0, &ops, NULL, &bus);
if (err < 0)
return err;
memset(&ac97, 0, sizeof(ac97));
ml403_ac97cr->ac97_fake = 1;
lm4550_regfile_init();
#ifdef CODEC_STAT
ml403_ac97cr->ac97_read = 0;
ml403_ac97cr->ac97_write = 0;
#endif
ac97.private_data = ml403_ac97cr;
ac97.private_free = snd_ml403_ac97cr_mixer_free;
ac97.scaps = AC97_SCAP_AUDIO | AC97_SCAP_SKIP_MODEM |
AC97_SCAP_NO_SPDIF;
err = snd_ac97_mixer(bus, &ac97, &ml403_ac97cr->ac97);
ml403_ac97cr->ac97_fake = 0;
lm4550_regfile_write_values_after_init(ml403_ac97cr->ac97);
PDEBUG(INIT_INFO, "mixer(): (done) snd_ac97_mixer()=%d\n", err);
return err;
}
static int
snd_ml403_ac97cr_pcm(struct snd_ml403_ac97cr *ml403_ac97cr, int device)
{
struct snd_pcm *pcm;
int err;
err = snd_pcm_new(ml403_ac97cr->card, "ML403AC97CR/1", device, 1, 1,
&pcm);
if (err < 0)
return err;
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_PLAYBACK,
&snd_ml403_ac97cr_playback_ops);
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_CAPTURE,
&snd_ml403_ac97cr_capture_ops);
pcm->private_data = ml403_ac97cr;
pcm->info_flags = 0;
strcpy(pcm->name, "ML403AC97CR DAC/ADC");
ml403_ac97cr->pcm = pcm;
snd_pcm_lib_preallocate_pages_for_all(pcm, SNDRV_DMA_TYPE_CONTINUOUS,
snd_dma_continuous_data(GFP_KERNEL),
64 * 1024,
128 * 1024);
return 0;
}
static int snd_ml403_ac97cr_probe(struct platform_device *pfdev)
{
struct snd_card *card;
struct snd_ml403_ac97cr *ml403_ac97cr = NULL;
int err;
int dev = pfdev->id;
if (dev >= SNDRV_CARDS)
return -ENODEV;
if (!enable[dev])
return -ENOENT;
err = snd_card_new(&pfdev->dev, index[dev], id[dev], THIS_MODULE,
0, &card);
if (err < 0)
return err;
err = snd_ml403_ac97cr_create(card, pfdev, &ml403_ac97cr);
if (err < 0) {
PDEBUG(INIT_FAILURE, "probe(): create failed!\n");
snd_card_free(card);
return err;
}
PDEBUG(INIT_INFO, "probe(): create done\n");
card->private_data = ml403_ac97cr;
err = snd_ml403_ac97cr_mixer(ml403_ac97cr);
if (err < 0) {
snd_card_free(card);
return err;
}
PDEBUG(INIT_INFO, "probe(): mixer done\n");
err = snd_ml403_ac97cr_pcm(ml403_ac97cr, 0);
if (err < 0) {
snd_card_free(card);
return err;
}
PDEBUG(INIT_INFO, "probe(): PCM done\n");
strcpy(card->driver, SND_ML403_AC97CR_DRIVER);
strcpy(card->shortname, "ML403 AC97 Controller Reference");
sprintf(card->longname, "%s %s at 0x%lx, irq %i & %i, device %i",
card->shortname, card->driver,
(unsigned long)ml403_ac97cr->port, ml403_ac97cr->irq,
ml403_ac97cr->capture_irq, dev + 1);
err = snd_card_register(card);
if (err < 0) {
snd_card_free(card);
return err;
}
platform_set_drvdata(pfdev, card);
PDEBUG(INIT_INFO, "probe(): (done)\n");
return 0;
}
static int snd_ml403_ac97cr_remove(struct platform_device *pfdev)
{
snd_card_free(platform_get_drvdata(pfdev));
return 0;
}
