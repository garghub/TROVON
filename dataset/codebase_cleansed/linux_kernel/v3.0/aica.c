static void spu_write_wait(void)
{
int time_count;
time_count = 0;
while (1) {
if (!(readl(G2_FIFO) & 0x11))
break;
time_count++;
if (time_count > 0x10000) {
snd_printk
("WARNING: G2 FIFO appears to be blocked.\n");
break;
}
}
}
static void spu_memset(u32 toi, u32 what, int length)
{
int i;
unsigned long flags;
if (snd_BUG_ON(length % 4))
return;
for (i = 0; i < length; i++) {
if (!(i % 8))
spu_write_wait();
local_irq_save(flags);
writel(what, toi + SPU_MEMORY_BASE);
local_irq_restore(flags);
toi++;
}
}
static void spu_memload(u32 toi, void *from, int length)
{
unsigned long flags;
u32 *froml = from;
u32 __iomem *to = (u32 __iomem *) (SPU_MEMORY_BASE + toi);
int i;
u32 val;
length = DIV_ROUND_UP(length, 4);
spu_write_wait();
for (i = 0; i < length; i++) {
if (!(i % 8))
spu_write_wait();
val = *froml;
local_irq_save(flags);
writel(val, to);
local_irq_restore(flags);
froml++;
to++;
}
}
static void spu_disable(void)
{
int i;
unsigned long flags;
u32 regval;
spu_write_wait();
regval = readl(ARM_RESET_REGISTER);
regval |= 1;
spu_write_wait();
local_irq_save(flags);
writel(regval, ARM_RESET_REGISTER);
local_irq_restore(flags);
for (i = 0; i < 64; i++) {
spu_write_wait();
regval = readl(SPU_REGISTER_BASE + (i * 0x80));
regval = (regval & ~0x4000) | 0x8000;
spu_write_wait();
local_irq_save(flags);
writel(regval, SPU_REGISTER_BASE + (i * 0x80));
local_irq_restore(flags);
}
}
static void spu_enable(void)
{
unsigned long flags;
u32 regval = readl(ARM_RESET_REGISTER);
regval &= ~1;
spu_write_wait();
local_irq_save(flags);
writel(regval, ARM_RESET_REGISTER);
local_irq_restore(flags);
}
static void spu_reset(void)
{
unsigned long flags;
spu_disable();
spu_memset(0, 0, 0x200000 / 4);
local_irq_save(flags);
__raw_writel(0xea000002, SPU_MEMORY_BASE);
local_irq_restore(flags);
spu_enable();
}
static void aica_chn_start(void)
{
unsigned long flags;
spu_write_wait();
local_irq_save(flags);
writel(AICA_CMD_KICK | AICA_CMD_START, (u32 *) AICA_CONTROL_POINT);
local_irq_restore(flags);
}
static void aica_chn_halt(void)
{
unsigned long flags;
spu_write_wait();
local_irq_save(flags);
writel(AICA_CMD_KICK | AICA_CMD_STOP, (u32 *) AICA_CONTROL_POINT);
local_irq_restore(flags);
}
static int aica_dma_transfer(int channels, int buffer_size,
struct snd_pcm_substream *substream)
{
int q, err, period_offset;
struct snd_card_aica *dreamcastcard;
struct snd_pcm_runtime *runtime;
unsigned long flags;
err = 0;
dreamcastcard = substream->pcm->private_data;
period_offset = dreamcastcard->clicks;
period_offset %= (AICA_PERIOD_NUMBER / channels);
runtime = substream->runtime;
for (q = 0; q < channels; q++) {
local_irq_save(flags);
err = dma_xfer(AICA_DMA_CHANNEL,
(unsigned long) (runtime->dma_area +
(AICA_BUFFER_SIZE * q) /
channels +
AICA_PERIOD_SIZE *
period_offset),
AICA_CHANNEL0_OFFSET + q * CHANNEL_OFFSET +
AICA_PERIOD_SIZE * period_offset,
buffer_size / channels, AICA_DMA_MODE);
if (unlikely(err < 0)) {
local_irq_restore(flags);
break;
}
dma_wait_for_completion(AICA_DMA_CHANNEL);
local_irq_restore(flags);
}
return err;
}
static void startup_aica(struct snd_card_aica *dreamcastcard)
{
spu_memload(AICA_CHANNEL0_CONTROL_OFFSET,
dreamcastcard->channel, sizeof(struct aica_channel));
aica_chn_start();
}
static void run_spu_dma(struct work_struct *work)
{
int buffer_size;
struct snd_pcm_runtime *runtime;
struct snd_card_aica *dreamcastcard;
dreamcastcard =
container_of(work, struct snd_card_aica, spu_dma_work);
runtime = dreamcastcard->substream->runtime;
if (unlikely(dreamcastcard->dma_check == 0)) {
buffer_size =
frames_to_bytes(runtime, runtime->buffer_size);
if (runtime->channels > 1)
dreamcastcard->channel->flags |= 0x01;
aica_dma_transfer(runtime->channels, buffer_size,
dreamcastcard->substream);
startup_aica(dreamcastcard);
dreamcastcard->clicks =
buffer_size / (AICA_PERIOD_SIZE * runtime->channels);
return;
} else {
aica_dma_transfer(runtime->channels,
AICA_PERIOD_SIZE * runtime->channels,
dreamcastcard->substream);
snd_pcm_period_elapsed(dreamcastcard->substream);
dreamcastcard->clicks++;
if (unlikely(dreamcastcard->clicks >= AICA_PERIOD_NUMBER))
dreamcastcard->clicks %= AICA_PERIOD_NUMBER;
mod_timer(&dreamcastcard->timer, jiffies + 1);
}
}
static void aica_period_elapsed(unsigned long timer_var)
{
int play_period;
struct snd_pcm_runtime *runtime;
struct snd_pcm_substream *substream;
struct snd_card_aica *dreamcastcard;
substream = (struct snd_pcm_substream *) timer_var;
runtime = substream->runtime;
dreamcastcard = substream->pcm->private_data;
play_period =
frames_to_bytes(runtime,
readl
(AICA_CONTROL_CHANNEL_SAMPLE_NUMBER)) /
AICA_PERIOD_SIZE;
if (play_period == dreamcastcard->current_period) {
mod_timer(&(dreamcastcard->timer), jiffies + 1);
return;
}
if (runtime->channels > 1)
dreamcastcard->current_period = play_period;
if (unlikely(dreamcastcard->dma_check == 0))
dreamcastcard->dma_check = 1;
queue_work(aica_queue, &(dreamcastcard->spu_dma_work));
}
static void spu_begin_dma(struct snd_pcm_substream *substream)
{
struct snd_card_aica *dreamcastcard;
struct snd_pcm_runtime *runtime;
runtime = substream->runtime;
dreamcastcard = substream->pcm->private_data;
queue_work(aica_queue, &(dreamcastcard->spu_dma_work));
if (unlikely(dreamcastcard->timer.data)) {
mod_timer(&dreamcastcard->timer, jiffies + 4);
return;
}
init_timer(&(dreamcastcard->timer));
dreamcastcard->timer.data = (unsigned long) substream;
dreamcastcard->timer.function = aica_period_elapsed;
dreamcastcard->timer.expires = jiffies + 4;
add_timer(&(dreamcastcard->timer));
}
static int snd_aicapcm_pcm_open(struct snd_pcm_substream
*substream)
{
struct snd_pcm_runtime *runtime;
struct aica_channel *channel;
struct snd_card_aica *dreamcastcard;
if (!enable)
return -ENOENT;
dreamcastcard = substream->pcm->private_data;
channel = kmalloc(sizeof(struct aica_channel), GFP_KERNEL);
if (!channel)
return -ENOMEM;
channel->sfmt = SM_8BIT;
channel->cmd = AICA_CMD_START;
channel->vol = dreamcastcard->master_volume;
channel->pan = 0x80;
channel->pos = 0;
channel->flags = 0;
dreamcastcard->channel = channel;
runtime = substream->runtime;
runtime->hw = snd_pcm_aica_playback_hw;
spu_enable();
dreamcastcard->clicks = 0;
dreamcastcard->current_period = 0;
dreamcastcard->dma_check = 0;
return 0;
}
static int snd_aicapcm_pcm_close(struct snd_pcm_substream
*substream)
{
struct snd_card_aica *dreamcastcard = substream->pcm->private_data;
flush_workqueue(aica_queue);
if (dreamcastcard->timer.data)
del_timer(&dreamcastcard->timer);
kfree(dreamcastcard->channel);
spu_disable();
return 0;
}
static int snd_aicapcm_pcm_hw_free(struct snd_pcm_substream
*substream)
{
return snd_pcm_lib_free_pages(substream);
}
static int snd_aicapcm_pcm_hw_params(struct snd_pcm_substream
*substream, struct snd_pcm_hw_params
*hw_params)
{
return
snd_pcm_lib_malloc_pages(substream,
params_buffer_bytes(hw_params));
}
static int snd_aicapcm_pcm_prepare(struct snd_pcm_substream
*substream)
{
struct snd_card_aica *dreamcastcard = substream->pcm->private_data;
if ((substream->runtime)->format == SNDRV_PCM_FORMAT_S16_LE)
dreamcastcard->channel->sfmt = SM_16BIT;
dreamcastcard->channel->freq = substream->runtime->rate;
dreamcastcard->substream = substream;
return 0;
}
static int snd_aicapcm_pcm_trigger(struct snd_pcm_substream
*substream, int cmd)
{
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
spu_begin_dma(substream);
break;
case SNDRV_PCM_TRIGGER_STOP:
aica_chn_halt();
break;
default:
return -EINVAL;
}
return 0;
}
static unsigned long snd_aicapcm_pcm_pointer(struct snd_pcm_substream
*substream)
{
return readl(AICA_CONTROL_CHANNEL_SAMPLE_NUMBER);
}
static int __init snd_aicapcmchip(struct snd_card_aica
*dreamcastcard, int pcm_index)
{
struct snd_pcm *pcm;
int err;
err =
snd_pcm_new(dreamcastcard->card, "AICA PCM", pcm_index, 1, 0,
&pcm);
if (unlikely(err < 0))
return err;
pcm->private_data = dreamcastcard;
strcpy(pcm->name, "AICA PCM");
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_PLAYBACK,
&snd_aicapcm_playback_ops);
err =
snd_pcm_lib_preallocate_pages_for_all(pcm,
SNDRV_DMA_TYPE_CONTINUOUS,
snd_dma_continuous_data
(GFP_KERNEL),
AICA_BUFFER_SIZE,
AICA_BUFFER_SIZE);
return err;
}
static int aica_pcmswitch_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
ucontrol->value.integer.value[0] = 1;
return 0;
}
static int aica_pcmswitch_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
if (ucontrol->value.integer.value[0] == 1)
return 0;
else
aica_chn_halt();
return 0;
}
static int aica_pcmvolume_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = 1;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = 0xFF;
return 0;
}
static int aica_pcmvolume_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_card_aica *dreamcastcard;
dreamcastcard = kcontrol->private_data;
if (unlikely(!dreamcastcard->channel))
return -ETXTBSY;
ucontrol->value.integer.value[0] = dreamcastcard->channel->vol;
return 0;
}
static int aica_pcmvolume_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_card_aica *dreamcastcard;
unsigned int vol;
dreamcastcard = kcontrol->private_data;
if (unlikely(!dreamcastcard->channel))
return -ETXTBSY;
vol = ucontrol->value.integer.value[0];
if (vol > 0xff)
return -EINVAL;
if (unlikely(dreamcastcard->channel->vol == vol))
return 0;
dreamcastcard->channel->vol = ucontrol->value.integer.value[0];
dreamcastcard->master_volume = ucontrol->value.integer.value[0];
spu_memload(AICA_CHANNEL0_CONTROL_OFFSET,
dreamcastcard->channel, sizeof(struct aica_channel));
return 1;
}
static int load_aica_firmware(void)
{
int err;
const struct firmware *fw_entry;
spu_reset();
err = request_firmware(&fw_entry, "aica_firmware.bin", &pd->dev);
if (unlikely(err))
return err;
spu_disable();
spu_memload(0, fw_entry->data, fw_entry->size);
spu_enable();
release_firmware(fw_entry);
return err;
}
static int __devinit add_aicamixer_controls(struct snd_card_aica
*dreamcastcard)
{
int err;
err = snd_ctl_add
(dreamcastcard->card,
snd_ctl_new1(&snd_aica_pcmvolume_control, dreamcastcard));
if (unlikely(err < 0))
return err;
err = snd_ctl_add
(dreamcastcard->card,
snd_ctl_new1(&snd_aica_pcmswitch_control, dreamcastcard));
if (unlikely(err < 0))
return err;
return 0;
}
static int __devexit snd_aica_remove(struct platform_device *devptr)
{
struct snd_card_aica *dreamcastcard;
dreamcastcard = platform_get_drvdata(devptr);
if (unlikely(!dreamcastcard))
return -ENODEV;
snd_card_free(dreamcastcard->card);
kfree(dreamcastcard);
platform_set_drvdata(devptr, NULL);
return 0;
}
static int __devinit snd_aica_probe(struct platform_device *devptr)
{
int err;
struct snd_card_aica *dreamcastcard;
dreamcastcard = kmalloc(sizeof(struct snd_card_aica), GFP_KERNEL);
if (unlikely(!dreamcastcard))
return -ENOMEM;
err = snd_card_create(index, SND_AICA_DRIVER, THIS_MODULE, 0,
&dreamcastcard->card);
if (unlikely(err < 0)) {
kfree(dreamcastcard);
return err;
}
strcpy(dreamcastcard->card->driver, "snd_aica");
strcpy(dreamcastcard->card->shortname, SND_AICA_DRIVER);
strcpy(dreamcastcard->card->longname,
"Yamaha AICA Super Intelligent Sound Processor for SEGA Dreamcast");
INIT_WORK(&(dreamcastcard->spu_dma_work), run_spu_dma);
err = snd_aicapcmchip(dreamcastcard, 0);
if (unlikely(err < 0))
goto freedreamcast;
snd_card_set_dev(dreamcastcard->card, &devptr->dev);
dreamcastcard->timer.data = 0;
dreamcastcard->channel = NULL;
err = add_aicamixer_controls(dreamcastcard);
if (unlikely(err < 0))
goto freedreamcast;
err = snd_card_register(dreamcastcard->card);
if (unlikely(err < 0))
goto freedreamcast;
platform_set_drvdata(devptr, dreamcastcard);
aica_queue = create_workqueue(CARD_NAME);
if (unlikely(!aica_queue))
goto freedreamcast;
snd_printk
("ALSA Driver for Yamaha AICA Super Intelligent Sound Processor\n");
return 0;
freedreamcast:
snd_card_free(dreamcastcard->card);
kfree(dreamcastcard);
return err;
}
static int __init aica_init(void)
{
int err;
err = platform_driver_register(&snd_aica_driver);
if (unlikely(err < 0))
return err;
pd = platform_device_register_simple(SND_AICA_DRIVER, -1,
aica_memory_space, 2);
if (IS_ERR(pd)) {
platform_driver_unregister(&snd_aica_driver);
return PTR_ERR(pd);
}
return load_aica_firmware();
}
static void __exit aica_exit(void)
{
if (likely(aica_queue))
destroy_workqueue(aica_queue);
platform_device_unregister(pd);
platform_driver_unregister(&snd_aica_driver);
spu_reset();
}
