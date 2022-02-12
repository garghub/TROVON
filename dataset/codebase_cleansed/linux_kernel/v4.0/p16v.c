static void snd_p16v_pcm_free_substream(struct snd_pcm_runtime *runtime)
{
struct snd_emu10k1_pcm *epcm = runtime->private_data;
kfree(epcm);
}
static int snd_p16v_pcm_open_playback_channel(struct snd_pcm_substream *substream, int channel_id)
{
struct snd_emu10k1 *emu = snd_pcm_substream_chip(substream);
struct snd_emu10k1_voice *channel = &(emu->p16v_voices[channel_id]);
struct snd_emu10k1_pcm *epcm;
struct snd_pcm_runtime *runtime = substream->runtime;
int err;
epcm = kzalloc(sizeof(*epcm), GFP_KERNEL);
if (epcm == NULL)
return -ENOMEM;
epcm->emu = emu;
epcm->substream = substream;
runtime->private_data = epcm;
runtime->private_free = snd_p16v_pcm_free_substream;
runtime->hw = snd_p16v_playback_hw;
channel->emu = emu;
channel->number = channel_id;
channel->use=1;
#if 0
dev_dbg(emu->card->dev,
"p16v: open channel_id=%d, channel=%p, use=0x%x\n",
channel_id, channel, channel->use);
dev_dbg(emu->card->dev, "open:channel_id=%d, chip=%p, channel=%p\n",
channel_id, chip, channel);
#endif
channel->epcm = epcm;
if ((err = snd_pcm_hw_constraint_integer(runtime, SNDRV_PCM_HW_PARAM_PERIODS)) < 0)
return err;
runtime->sync.id32[0] = substream->pcm->card->number;
runtime->sync.id32[1] = 'P';
runtime->sync.id32[2] = 16;
runtime->sync.id32[3] = 'V';
return 0;
}
static int snd_p16v_pcm_open_capture_channel(struct snd_pcm_substream *substream, int channel_id)
{
struct snd_emu10k1 *emu = snd_pcm_substream_chip(substream);
struct snd_emu10k1_voice *channel = &(emu->p16v_capture_voice);
struct snd_emu10k1_pcm *epcm;
struct snd_pcm_runtime *runtime = substream->runtime;
int err;
epcm = kzalloc(sizeof(*epcm), GFP_KERNEL);
if (epcm == NULL)
return -ENOMEM;
epcm->emu = emu;
epcm->substream = substream;
runtime->private_data = epcm;
runtime->private_free = snd_p16v_pcm_free_substream;
runtime->hw = snd_p16v_capture_hw;
channel->emu = emu;
channel->number = channel_id;
channel->use=1;
#if 0
dev_dbg(emu->card->dev,
"p16v: open channel_id=%d, channel=%p, use=0x%x\n",
channel_id, channel, channel->use);
dev_dbg(emu->card->dev, "open:channel_id=%d, chip=%p, channel=%p\n",
channel_id, chip, channel);
#endif
channel->epcm = epcm;
if ((err = snd_pcm_hw_constraint_integer(runtime, SNDRV_PCM_HW_PARAM_PERIODS)) < 0)
return err;
return 0;
}
static int snd_p16v_pcm_close_playback(struct snd_pcm_substream *substream)
{
struct snd_emu10k1 *emu = snd_pcm_substream_chip(substream);
emu->p16v_voices[substream->pcm->device - emu->p16v_device_offset].use = 0;
return 0;
}
static int snd_p16v_pcm_close_capture(struct snd_pcm_substream *substream)
{
struct snd_emu10k1 *emu = snd_pcm_substream_chip(substream);
emu->p16v_capture_voice.use = 0;
return 0;
}
static int snd_p16v_pcm_open_playback_front(struct snd_pcm_substream *substream)
{
return snd_p16v_pcm_open_playback_channel(substream, PCM_FRONT_CHANNEL);
}
static int snd_p16v_pcm_open_capture(struct snd_pcm_substream *substream)
{
return snd_p16v_pcm_open_capture_channel(substream, 0);
}
static int snd_p16v_pcm_hw_params_playback(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *hw_params)
{
int result;
result = snd_pcm_lib_malloc_pages(substream,
params_buffer_bytes(hw_params));
return result;
}
static int snd_p16v_pcm_hw_params_capture(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *hw_params)
{
int result;
result = snd_pcm_lib_malloc_pages(substream,
params_buffer_bytes(hw_params));
return result;
}
static int snd_p16v_pcm_hw_free_playback(struct snd_pcm_substream *substream)
{
int result;
result = snd_pcm_lib_free_pages(substream);
return result;
}
static int snd_p16v_pcm_hw_free_capture(struct snd_pcm_substream *substream)
{
int result;
result = snd_pcm_lib_free_pages(substream);
return result;
}
static int snd_p16v_pcm_prepare_playback(struct snd_pcm_substream *substream)
{
struct snd_emu10k1 *emu = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
int channel = substream->pcm->device - emu->p16v_device_offset;
u32 *table_base = (u32 *)(emu->p16v_buffer.area+(8*16*channel));
u32 period_size_bytes = frames_to_bytes(runtime, runtime->period_size);
int i;
u32 tmp;
#if 0
dev_dbg(emu->card->dev,
"prepare:channel_number=%d, rate=%d, "
"format=0x%x, channels=%d, buffer_size=%ld, "
"period_size=%ld, periods=%u, frames_to_bytes=%d\n",
channel, runtime->rate, runtime->format, runtime->channels,
runtime->buffer_size, runtime->period_size,
runtime->periods, frames_to_bytes(runtime, 1));
dev_dbg(emu->card->dev,
"dma_addr=%x, dma_area=%p, table_base=%p\n",
runtime->dma_addr, runtime->dma_area, table_base);
dev_dbg(emu->card->dev,
"dma_addr=%x, dma_area=%p, dma_bytes(size)=%x\n",
emu->p16v_buffer.addr, emu->p16v_buffer.area,
emu->p16v_buffer.bytes);
#endif
tmp = snd_emu10k1_ptr_read(emu, A_SPDIF_SAMPLERATE, channel);
switch (runtime->rate) {
case 44100:
snd_emu10k1_ptr_write(emu, A_SPDIF_SAMPLERATE, channel, (tmp & ~0xe0e0) | 0x8080);
break;
case 96000:
snd_emu10k1_ptr_write(emu, A_SPDIF_SAMPLERATE, channel, (tmp & ~0xe0e0) | 0x4040);
break;
case 192000:
snd_emu10k1_ptr_write(emu, A_SPDIF_SAMPLERATE, channel, (tmp & ~0xe0e0) | 0x2020);
break;
case 48000:
default:
snd_emu10k1_ptr_write(emu, A_SPDIF_SAMPLERATE, channel, (tmp & ~0xe0e0) | 0x0000);
break;
}
for(i = 0; i < runtime->periods; i++) {
table_base[i*2]=runtime->dma_addr+(i*period_size_bytes);
table_base[(i*2)+1]=period_size_bytes<<16;
}
snd_emu10k1_ptr20_write(emu, PLAYBACK_LIST_ADDR, channel, emu->p16v_buffer.addr+(8*16*channel));
snd_emu10k1_ptr20_write(emu, PLAYBACK_LIST_SIZE, channel, (runtime->periods - 1) << 19);
snd_emu10k1_ptr20_write(emu, PLAYBACK_LIST_PTR, channel, 0);
snd_emu10k1_ptr20_write(emu, PLAYBACK_DMA_ADDR, channel, runtime->dma_addr);
snd_emu10k1_ptr20_write(emu, PLAYBACK_PERIOD_SIZE, channel, 0);
snd_emu10k1_ptr20_write(emu, PLAYBACK_POINTER, channel, 0);
snd_emu10k1_ptr20_write(emu, 0x07, channel, 0x0);
snd_emu10k1_ptr20_write(emu, 0x08, channel, 0);
return 0;
}
static int snd_p16v_pcm_prepare_capture(struct snd_pcm_substream *substream)
{
struct snd_emu10k1 *emu = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
int channel = substream->pcm->device - emu->p16v_device_offset;
u32 tmp;
tmp = snd_emu10k1_ptr_read(emu, A_SPDIF_SAMPLERATE, channel);
switch (runtime->rate) {
case 44100:
snd_emu10k1_ptr_write(emu, A_SPDIF_SAMPLERATE, channel, (tmp & ~0x0e00) | 0x0800);
break;
case 96000:
snd_emu10k1_ptr_write(emu, A_SPDIF_SAMPLERATE, channel, (tmp & ~0x0e00) | 0x0400);
break;
case 192000:
snd_emu10k1_ptr_write(emu, A_SPDIF_SAMPLERATE, channel, (tmp & ~0x0e00) | 0x0200);
break;
case 48000:
default:
snd_emu10k1_ptr_write(emu, A_SPDIF_SAMPLERATE, channel, (tmp & ~0x0e00) | 0x0000);
break;
}
snd_emu10k1_ptr20_write(emu, 0x13, channel, 0);
snd_emu10k1_ptr20_write(emu, CAPTURE_DMA_ADDR, channel, runtime->dma_addr);
snd_emu10k1_ptr20_write(emu, CAPTURE_BUFFER_SIZE, channel, frames_to_bytes(runtime, runtime->buffer_size) << 16);
snd_emu10k1_ptr20_write(emu, CAPTURE_POINTER, channel, 0);
return 0;
}
static void snd_p16v_intr_enable(struct snd_emu10k1 *emu, unsigned int intrenb)
{
unsigned long flags;
unsigned int enable;
spin_lock_irqsave(&emu->emu_lock, flags);
enable = inl(emu->port + INTE2) | intrenb;
outl(enable, emu->port + INTE2);
spin_unlock_irqrestore(&emu->emu_lock, flags);
}
static void snd_p16v_intr_disable(struct snd_emu10k1 *emu, unsigned int intrenb)
{
unsigned long flags;
unsigned int disable;
spin_lock_irqsave(&emu->emu_lock, flags);
disable = inl(emu->port + INTE2) & (~intrenb);
outl(disable, emu->port + INTE2);
spin_unlock_irqrestore(&emu->emu_lock, flags);
}
static int snd_p16v_pcm_trigger_playback(struct snd_pcm_substream *substream,
int cmd)
{
struct snd_emu10k1 *emu = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime;
struct snd_emu10k1_pcm *epcm;
int channel;
int result = 0;
struct snd_pcm_substream *s;
u32 basic = 0;
u32 inte = 0;
int running = 0;
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
running=1;
break;
case SNDRV_PCM_TRIGGER_STOP:
default:
running = 0;
break;
}
snd_pcm_group_for_each_entry(s, substream) {
if (snd_pcm_substream_chip(s) != emu ||
s->stream != SNDRV_PCM_STREAM_PLAYBACK)
continue;
runtime = s->runtime;
epcm = runtime->private_data;
channel = substream->pcm->device-emu->p16v_device_offset;
epcm->running = running;
basic |= (0x1<<channel);
inte |= (INTE2_PLAYBACK_CH_0_LOOP<<channel);
snd_pcm_trigger_done(s, substream);
}
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
snd_p16v_intr_enable(emu, inte);
snd_emu10k1_ptr20_write(emu, BASIC_INTERRUPT, 0, snd_emu10k1_ptr20_read(emu, BASIC_INTERRUPT, 0)| (basic));
break;
case SNDRV_PCM_TRIGGER_STOP:
snd_emu10k1_ptr20_write(emu, BASIC_INTERRUPT, 0, snd_emu10k1_ptr20_read(emu, BASIC_INTERRUPT, 0) & ~(basic));
snd_p16v_intr_disable(emu, inte);
break;
default:
result = -EINVAL;
break;
}
return result;
}
static int snd_p16v_pcm_trigger_capture(struct snd_pcm_substream *substream,
int cmd)
{
struct snd_emu10k1 *emu = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
struct snd_emu10k1_pcm *epcm = runtime->private_data;
int channel = 0;
int result = 0;
u32 inte = INTE2_CAPTURE_CH_0_LOOP | INTE2_CAPTURE_CH_0_HALF_LOOP;
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
snd_p16v_intr_enable(emu, inte);
snd_emu10k1_ptr20_write(emu, BASIC_INTERRUPT, 0, snd_emu10k1_ptr20_read(emu, BASIC_INTERRUPT, 0)|(0x100<<channel));
epcm->running = 1;
break;
case SNDRV_PCM_TRIGGER_STOP:
snd_emu10k1_ptr20_write(emu, BASIC_INTERRUPT, 0, snd_emu10k1_ptr20_read(emu, BASIC_INTERRUPT, 0) & ~(0x100<<channel));
snd_p16v_intr_disable(emu, inte);
epcm->running = 0;
break;
default:
result = -EINVAL;
break;
}
return result;
}
static snd_pcm_uframes_t
snd_p16v_pcm_pointer_playback(struct snd_pcm_substream *substream)
{
struct snd_emu10k1 *emu = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
struct snd_emu10k1_pcm *epcm = runtime->private_data;
snd_pcm_uframes_t ptr, ptr1, ptr2,ptr3,ptr4 = 0;
int channel = substream->pcm->device - emu->p16v_device_offset;
if (!epcm->running)
return 0;
ptr3 = snd_emu10k1_ptr20_read(emu, PLAYBACK_LIST_PTR, channel);
ptr1 = snd_emu10k1_ptr20_read(emu, PLAYBACK_POINTER, channel);
ptr4 = snd_emu10k1_ptr20_read(emu, PLAYBACK_LIST_PTR, channel);
if (ptr3 != ptr4) ptr1 = snd_emu10k1_ptr20_read(emu, PLAYBACK_POINTER, channel);
ptr2 = bytes_to_frames(runtime, ptr1);
ptr2+= (ptr4 >> 3) * runtime->period_size;
ptr=ptr2;
if (ptr >= runtime->buffer_size)
ptr -= runtime->buffer_size;
return ptr;
}
static snd_pcm_uframes_t
snd_p16v_pcm_pointer_capture(struct snd_pcm_substream *substream)
{
struct snd_emu10k1 *emu = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
struct snd_emu10k1_pcm *epcm = runtime->private_data;
snd_pcm_uframes_t ptr, ptr1, ptr2 = 0;
int channel = 0;
if (!epcm->running)
return 0;
ptr1 = snd_emu10k1_ptr20_read(emu, CAPTURE_POINTER, channel);
ptr2 = bytes_to_frames(runtime, ptr1);
ptr=ptr2;
if (ptr >= runtime->buffer_size) {
ptr -= runtime->buffer_size;
dev_warn(emu->card->dev, "buffer capture limited!\n");
}
return ptr;
}
int snd_p16v_free(struct snd_emu10k1 *chip)
{
if (chip->p16v_buffer.area) {
snd_dma_free_pages(&chip->p16v_buffer);
}
return 0;
}
int snd_p16v_pcm(struct snd_emu10k1 *emu, int device)
{
struct snd_pcm *pcm;
struct snd_pcm_substream *substream;
int err;
int capture=1;
emu->p16v_device_offset = device;
if ((err = snd_pcm_new(emu->card, "p16v", device, 1, capture, &pcm)) < 0)
return err;
pcm->private_data = emu;
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_PLAYBACK, &snd_p16v_playback_front_ops);
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_CAPTURE, &snd_p16v_capture_ops);
pcm->info_flags = 0;
pcm->dev_subclass = SNDRV_PCM_SUBCLASS_GENERIC_MIX;
strcpy(pcm->name, "p16v");
emu->pcm_p16v = pcm;
for(substream = pcm->streams[SNDRV_PCM_STREAM_PLAYBACK].substream;
substream;
substream = substream->next) {
if ((err = snd_pcm_lib_preallocate_pages(substream,
SNDRV_DMA_TYPE_DEV,
snd_dma_pci_data(emu->pci),
((65536 - 64) * 8), ((65536 - 64) * 8))) < 0)
return err;
}
for (substream = pcm->streams[SNDRV_PCM_STREAM_CAPTURE].substream;
substream;
substream = substream->next) {
if ((err = snd_pcm_lib_preallocate_pages(substream,
SNDRV_DMA_TYPE_DEV,
snd_dma_pci_data(emu->pci),
65536 - 64, 65536 - 64)) < 0)
return err;
}
return 0;
}
static int snd_p16v_volume_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = 2;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = 255;
return 0;
}
static int snd_p16v_volume_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_emu10k1 *emu = snd_kcontrol_chip(kcontrol);
int high_low = (kcontrol->private_value >> 8) & 0xff;
int reg = kcontrol->private_value & 0xff;
u32 value;
value = snd_emu10k1_ptr20_read(emu, reg, high_low);
if (high_low) {
ucontrol->value.integer.value[0] = 0xff - ((value >> 24) & 0xff);
ucontrol->value.integer.value[1] = 0xff - ((value >> 16) & 0xff);
} else {
ucontrol->value.integer.value[0] = 0xff - ((value >> 8) & 0xff);
ucontrol->value.integer.value[1] = 0xff - ((value >> 0) & 0xff);
}
return 0;
}
static int snd_p16v_volume_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_emu10k1 *emu = snd_kcontrol_chip(kcontrol);
int high_low = (kcontrol->private_value >> 8) & 0xff;
int reg = kcontrol->private_value & 0xff;
u32 value, oval;
oval = value = snd_emu10k1_ptr20_read(emu, reg, 0);
if (high_low == 1) {
value &= 0xffff;
value |= ((0xff - ucontrol->value.integer.value[0]) << 24) |
((0xff - ucontrol->value.integer.value[1]) << 16);
} else {
value &= 0xffff0000;
value |= ((0xff - ucontrol->value.integer.value[0]) << 8) |
((0xff - ucontrol->value.integer.value[1]) );
}
if (value != oval) {
snd_emu10k1_ptr20_write(emu, reg, 0, value);
return 1;
}
return 0;
}
static int snd_p16v_capture_source_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
static const char * const texts[8] = {
"SPDIF", "I2S", "SRC48", "SRCMulti_SPDIF", "SRCMulti_I2S",
"CDIF", "FX", "AC97"
};
return snd_ctl_enum_info(uinfo, 1, 8, texts);
}
static int snd_p16v_capture_source_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_emu10k1 *emu = snd_kcontrol_chip(kcontrol);
ucontrol->value.enumerated.item[0] = emu->p16v_capture_source;
return 0;
}
static int snd_p16v_capture_source_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_emu10k1 *emu = snd_kcontrol_chip(kcontrol);
unsigned int val;
int change = 0;
u32 mask;
u32 source;
val = ucontrol->value.enumerated.item[0] ;
if (val > 7)
return -EINVAL;
change = (emu->p16v_capture_source != val);
if (change) {
emu->p16v_capture_source = val;
source = (val << 28) | (val << 24) | (val << 20) | (val << 16);
mask = snd_emu10k1_ptr20_read(emu, BASIC_INTERRUPT, 0) & 0xffff;
snd_emu10k1_ptr20_write(emu, BASIC_INTERRUPT, 0, source | mask);
}
return change;
}
static int snd_p16v_capture_channel_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
static const char * const texts[4] = { "0", "1", "2", "3", };
return snd_ctl_enum_info(uinfo, 1, 4, texts);
}
static int snd_p16v_capture_channel_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_emu10k1 *emu = snd_kcontrol_chip(kcontrol);
ucontrol->value.enumerated.item[0] = emu->p16v_capture_channel;
return 0;
}
static int snd_p16v_capture_channel_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_emu10k1 *emu = snd_kcontrol_chip(kcontrol);
unsigned int val;
int change = 0;
u32 tmp;
val = ucontrol->value.enumerated.item[0] ;
if (val > 3)
return -EINVAL;
change = (emu->p16v_capture_channel != val);
if (change) {
emu->p16v_capture_channel = val;
tmp = snd_emu10k1_ptr20_read(emu, CAPTURE_P16V_SOURCE, 0) & 0xfffc;
snd_emu10k1_ptr20_write(emu, CAPTURE_P16V_SOURCE, 0, tmp | val);
}
return change;
}
int snd_p16v_mixer(struct snd_emu10k1 *emu)
{
int i, err;
struct snd_card *card = emu->card;
for (i = 0; i < ARRAY_SIZE(p16v_mixer_controls); i++) {
if ((err = snd_ctl_add(card, snd_ctl_new1(&p16v_mixer_controls[i],
emu))) < 0)
return err;
}
return 0;
}
int snd_p16v_alloc_pm_buffer(struct snd_emu10k1 *emu)
{
emu->p16v_saved = vmalloc(NUM_CHS * 4 * 0x80);
if (! emu->p16v_saved)
return -ENOMEM;
return 0;
}
void snd_p16v_free_pm_buffer(struct snd_emu10k1 *emu)
{
vfree(emu->p16v_saved);
}
void snd_p16v_suspend(struct snd_emu10k1 *emu)
{
int i, ch;
unsigned int *val;
val = emu->p16v_saved;
for (ch = 0; ch < NUM_CHS; ch++)
for (i = 0; i < 0x80; i++, val++)
*val = snd_emu10k1_ptr20_read(emu, i, ch);
}
void snd_p16v_resume(struct snd_emu10k1 *emu)
{
int i, ch;
unsigned int *val;
val = emu->p16v_saved;
for (ch = 0; ch < NUM_CHS; ch++)
for (i = 0; i < 0x80; i++, val++)
snd_emu10k1_ptr20_write(emu, i, ch, *val);
}
