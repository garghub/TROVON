unsigned int snd_ca0106_ptr_read(struct snd_ca0106 * emu,
unsigned int reg,
unsigned int chn)
{
unsigned long flags;
unsigned int regptr, val;
regptr = (reg << 16) | chn;
spin_lock_irqsave(&emu->emu_lock, flags);
outl(regptr, emu->port + PTR);
val = inl(emu->port + DATA);
spin_unlock_irqrestore(&emu->emu_lock, flags);
return val;
}
void snd_ca0106_ptr_write(struct snd_ca0106 *emu,
unsigned int reg,
unsigned int chn,
unsigned int data)
{
unsigned int regptr;
unsigned long flags;
regptr = (reg << 16) | chn;
spin_lock_irqsave(&emu->emu_lock, flags);
outl(regptr, emu->port + PTR);
outl(data, emu->port + DATA);
spin_unlock_irqrestore(&emu->emu_lock, flags);
}
int snd_ca0106_spi_write(struct snd_ca0106 * emu,
unsigned int data)
{
unsigned int reset, set;
unsigned int reg, tmp;
int n, result;
reg = SPI;
if (data > 0xffff)
return 1;
tmp = snd_ca0106_ptr_read(emu, reg, 0);
reset = (tmp & ~0x3ffff) | 0x20000;
set = reset | 0x10000;
snd_ca0106_ptr_write(emu, reg, 0, reset | data);
tmp = snd_ca0106_ptr_read(emu, reg, 0);
snd_ca0106_ptr_write(emu, reg, 0, set | data);
result = 1;
for (n = 0; n < 100; n++) {
udelay(10);
tmp = snd_ca0106_ptr_read(emu, reg, 0);
if (!(tmp & 0x10000)) {
result = 0;
break;
}
}
if (result)
return 1;
snd_ca0106_ptr_write(emu, reg, 0, reset | data);
tmp = snd_ca0106_ptr_read(emu, reg, 0);
return 0;
}
int snd_ca0106_i2c_write(struct snd_ca0106 *emu,
u32 reg,
u32 value)
{
u32 tmp;
int timeout = 0;
int status;
int retry;
if ((reg > 0x7f) || (value > 0x1ff)) {
dev_err(emu->card->dev, "i2c_write: invalid values.\n");
return -EINVAL;
}
tmp = reg << 25 | value << 16;
snd_ca0106_ptr_write(emu, I2C_D1, 0, tmp);
for (retry = 0; retry < 10; retry++) {
tmp = 0;
tmp = tmp | (I2C_A_ADC_LAST|I2C_A_ADC_START|I2C_A_ADC_ADD);
snd_ca0106_ptr_write(emu, I2C_A, 0, tmp);
while (1) {
status = snd_ca0106_ptr_read(emu, I2C_A, 0);
timeout++;
if ((status & I2C_A_ADC_START) == 0)
break;
if (timeout > 1000)
break;
}
if ((status & I2C_A_ADC_ABORT) == 0)
break;
}
if (retry == 10) {
dev_err(emu->card->dev, "Writing to ADC failed!\n");
return -EINVAL;
}
return 0;
}
static void snd_ca0106_intr_enable(struct snd_ca0106 *emu, unsigned int intrenb)
{
unsigned long flags;
unsigned int intr_enable;
spin_lock_irqsave(&emu->emu_lock, flags);
intr_enable = inl(emu->port + INTE) | intrenb;
outl(intr_enable, emu->port + INTE);
spin_unlock_irqrestore(&emu->emu_lock, flags);
}
static void snd_ca0106_intr_disable(struct snd_ca0106 *emu, unsigned int intrenb)
{
unsigned long flags;
unsigned int intr_enable;
spin_lock_irqsave(&emu->emu_lock, flags);
intr_enable = inl(emu->port + INTE) & ~intrenb;
outl(intr_enable, emu->port + INTE);
spin_unlock_irqrestore(&emu->emu_lock, flags);
}
static void snd_ca0106_pcm_free_substream(struct snd_pcm_runtime *runtime)
{
kfree(runtime->private_data);
}
static void restore_spdif_bits(struct snd_ca0106 *chip, int idx)
{
if (chip->spdif_str_bits[idx] != chip->spdif_bits[idx]) {
chip->spdif_str_bits[idx] = chip->spdif_bits[idx];
snd_ca0106_ptr_write(chip, SPCS0 + idx, 0,
chip->spdif_str_bits[idx]);
}
}
static int snd_ca0106_channel_dac(struct snd_ca0106 *chip,
struct snd_ca0106_details *details,
int channel_id)
{
switch (channel_id) {
case PCM_FRONT_CHANNEL:
return (details->spi_dac & 0xf000) >> (4 * 3);
case PCM_REAR_CHANNEL:
return (details->spi_dac & 0x0f00) >> (4 * 2);
case PCM_CENTER_LFE_CHANNEL:
return (details->spi_dac & 0x00f0) >> (4 * 1);
case PCM_UNKNOWN_CHANNEL:
return (details->spi_dac & 0x000f) >> (4 * 0);
default:
dev_dbg(chip->card->dev, "ca0106: unknown channel_id %d\n",
channel_id);
}
return 0;
}
static int snd_ca0106_pcm_power_dac(struct snd_ca0106 *chip, int channel_id,
int power)
{
if (chip->details->spi_dac) {
const int dac = snd_ca0106_channel_dac(chip, chip->details,
channel_id);
const int reg = spi_dacd_reg[dac];
const int bit = spi_dacd_bit[dac];
if (power)
chip->spi_dac_reg[reg] &= ~bit;
else
chip->spi_dac_reg[reg] |= bit;
return snd_ca0106_spi_write(chip, chip->spi_dac_reg[reg]);
}
return 0;
}
static int snd_ca0106_pcm_open_playback_channel(struct snd_pcm_substream *substream,
int channel_id)
{
struct snd_ca0106 *chip = snd_pcm_substream_chip(substream);
struct snd_ca0106_channel *channel = &(chip->playback_channels[channel_id]);
struct snd_ca0106_pcm *epcm;
struct snd_pcm_runtime *runtime = substream->runtime;
int err;
epcm = kzalloc(sizeof(*epcm), GFP_KERNEL);
if (epcm == NULL)
return -ENOMEM;
epcm->emu = chip;
epcm->substream = substream;
epcm->channel_id=channel_id;
runtime->private_data = epcm;
runtime->private_free = snd_ca0106_pcm_free_substream;
runtime->hw = snd_ca0106_playback_hw;
channel->emu = chip;
channel->number = channel_id;
channel->use = 1;
channel->epcm = epcm;
if ((err = snd_pcm_hw_constraint_integer(runtime, SNDRV_PCM_HW_PARAM_PERIODS)) < 0)
return err;
if ((err = snd_pcm_hw_constraint_step(runtime, 0, SNDRV_PCM_HW_PARAM_PERIOD_BYTES, 64)) < 0)
return err;
snd_pcm_set_sync(substream);
if (channel_id != PCM_FRONT_CHANNEL) {
err = snd_ca0106_pcm_power_dac(chip, channel_id, 1);
if (err < 0)
return err;
}
restore_spdif_bits(chip, channel_id);
return 0;
}
static int snd_ca0106_pcm_close_playback(struct snd_pcm_substream *substream)
{
struct snd_ca0106 *chip = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
struct snd_ca0106_pcm *epcm = runtime->private_data;
chip->playback_channels[epcm->channel_id].use = 0;
restore_spdif_bits(chip, epcm->channel_id);
if (epcm->channel_id != PCM_FRONT_CHANNEL) {
int err;
err = snd_ca0106_pcm_power_dac(chip, epcm->channel_id, 0);
if (err < 0)
return err;
}
return 0;
}
static int snd_ca0106_pcm_open_playback_front(struct snd_pcm_substream *substream)
{
return snd_ca0106_pcm_open_playback_channel(substream, PCM_FRONT_CHANNEL);
}
static int snd_ca0106_pcm_open_playback_center_lfe(struct snd_pcm_substream *substream)
{
return snd_ca0106_pcm_open_playback_channel(substream, PCM_CENTER_LFE_CHANNEL);
}
static int snd_ca0106_pcm_open_playback_unknown(struct snd_pcm_substream *substream)
{
return snd_ca0106_pcm_open_playback_channel(substream, PCM_UNKNOWN_CHANNEL);
}
static int snd_ca0106_pcm_open_playback_rear(struct snd_pcm_substream *substream)
{
return snd_ca0106_pcm_open_playback_channel(substream, PCM_REAR_CHANNEL);
}
static int snd_ca0106_pcm_open_capture_channel(struct snd_pcm_substream *substream,
int channel_id)
{
struct snd_ca0106 *chip = snd_pcm_substream_chip(substream);
struct snd_ca0106_channel *channel = &(chip->capture_channels[channel_id]);
struct snd_ca0106_pcm *epcm;
struct snd_pcm_runtime *runtime = substream->runtime;
int err;
epcm = kzalloc(sizeof(*epcm), GFP_KERNEL);
if (epcm == NULL) {
dev_err(chip->card->dev,
"open_capture_channel: failed epcm alloc\n");
return -ENOMEM;
}
epcm->emu = chip;
epcm->substream = substream;
epcm->channel_id=channel_id;
runtime->private_data = epcm;
runtime->private_free = snd_ca0106_pcm_free_substream;
runtime->hw = snd_ca0106_capture_hw;
channel->emu = chip;
channel->number = channel_id;
channel->use = 1;
channel->epcm = epcm;
if ((err = snd_pcm_hw_constraint_integer(runtime, SNDRV_PCM_HW_PARAM_PERIODS)) < 0)
return err;
if ((err = snd_pcm_hw_constraint_step(runtime, 0, SNDRV_PCM_HW_PARAM_PERIOD_BYTES, 64)) < 0)
return err;
return 0;
}
static int snd_ca0106_pcm_close_capture(struct snd_pcm_substream *substream)
{
struct snd_ca0106 *chip = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
struct snd_ca0106_pcm *epcm = runtime->private_data;
chip->capture_channels[epcm->channel_id].use = 0;
return 0;
}
static int snd_ca0106_pcm_open_0_capture(struct snd_pcm_substream *substream)
{
return snd_ca0106_pcm_open_capture_channel(substream, 0);
}
static int snd_ca0106_pcm_open_1_capture(struct snd_pcm_substream *substream)
{
return snd_ca0106_pcm_open_capture_channel(substream, 1);
}
static int snd_ca0106_pcm_open_2_capture(struct snd_pcm_substream *substream)
{
return snd_ca0106_pcm_open_capture_channel(substream, 2);
}
static int snd_ca0106_pcm_open_3_capture(struct snd_pcm_substream *substream)
{
return snd_ca0106_pcm_open_capture_channel(substream, 3);
}
static int snd_ca0106_pcm_hw_params_playback(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *hw_params)
{
return snd_pcm_lib_malloc_pages(substream,
params_buffer_bytes(hw_params));
}
static int snd_ca0106_pcm_hw_free_playback(struct snd_pcm_substream *substream)
{
return snd_pcm_lib_free_pages(substream);
}
static int snd_ca0106_pcm_hw_params_capture(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *hw_params)
{
return snd_pcm_lib_malloc_pages(substream,
params_buffer_bytes(hw_params));
}
static int snd_ca0106_pcm_hw_free_capture(struct snd_pcm_substream *substream)
{
return snd_pcm_lib_free_pages(substream);
}
static int snd_ca0106_pcm_prepare_playback(struct snd_pcm_substream *substream)
{
struct snd_ca0106 *emu = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
struct snd_ca0106_pcm *epcm = runtime->private_data;
int channel = epcm->channel_id;
u32 *table_base = (u32 *)(emu->buffer.area+(8*16*channel));
u32 period_size_bytes = frames_to_bytes(runtime, runtime->period_size);
u32 hcfg_mask = HCFG_PLAYBACK_S32_LE;
u32 hcfg_set = 0x00000000;
u32 hcfg;
u32 reg40_mask = 0x30000 << (channel<<1);
u32 reg40_set = 0;
u32 reg40;
u32 reg71_mask = 0x03030000 ;
u32 reg71_set = 0;
u32 reg71;
int i;
#if 0
dev_dbg(emu->card->dev,
"prepare:channel_number=%d, rate=%d, format=0x%x, "
"channels=%d, buffer_size=%ld, period_size=%ld, "
"periods=%u, frames_to_bytes=%d\n",
channel, runtime->rate, runtime->format,
runtime->channels, runtime->buffer_size,
runtime->period_size, runtime->periods,
frames_to_bytes(runtime, 1));
dev_dbg(emu->card->dev,
"dma_addr=%x, dma_area=%p, table_base=%p\n",
runtime->dma_addr, runtime->dma_area, table_base);
dev_dbg(emu->card->dev,
"dma_addr=%x, dma_area=%p, dma_bytes(size)=%x\n",
emu->buffer.addr, emu->buffer.area, emu->buffer.bytes);
#endif
switch (runtime->rate) {
case 44100:
reg40_set = 0x10000 << (channel<<1);
reg71_set = 0x01010000;
break;
case 48000:
reg40_set = 0;
reg71_set = 0;
break;
case 96000:
reg40_set = 0x20000 << (channel<<1);
reg71_set = 0x02020000;
break;
case 192000:
reg40_set = 0x30000 << (channel<<1);
reg71_set = 0x03030000;
break;
default:
reg40_set = 0;
reg71_set = 0;
break;
}
switch (runtime->format) {
case SNDRV_PCM_FORMAT_S16_LE:
hcfg_set = 0;
break;
case SNDRV_PCM_FORMAT_S32_LE:
hcfg_set = HCFG_PLAYBACK_S32_LE;
break;
default:
hcfg_set = 0;
break;
}
hcfg = inl(emu->port + HCFG) ;
hcfg = (hcfg & ~hcfg_mask) | hcfg_set;
outl(hcfg, emu->port + HCFG);
reg40 = snd_ca0106_ptr_read(emu, 0x40, 0);
reg40 = (reg40 & ~reg40_mask) | reg40_set;
snd_ca0106_ptr_write(emu, 0x40, 0, reg40);
reg71 = snd_ca0106_ptr_read(emu, 0x71, 0);
reg71 = (reg71 & ~reg71_mask) | reg71_set;
snd_ca0106_ptr_write(emu, 0x71, 0, reg71);
for(i=0; i < runtime->periods; i++) {
table_base[i*2] = runtime->dma_addr + (i * period_size_bytes);
table_base[i*2+1] = period_size_bytes << 16;
}
snd_ca0106_ptr_write(emu, PLAYBACK_LIST_ADDR, channel, emu->buffer.addr+(8*16*channel));
snd_ca0106_ptr_write(emu, PLAYBACK_LIST_SIZE, channel, (runtime->periods - 1) << 19);
snd_ca0106_ptr_write(emu, PLAYBACK_LIST_PTR, channel, 0);
snd_ca0106_ptr_write(emu, PLAYBACK_DMA_ADDR, channel, runtime->dma_addr);
snd_ca0106_ptr_write(emu, PLAYBACK_PERIOD_SIZE, channel, frames_to_bytes(runtime, runtime->period_size)<<16);
snd_ca0106_ptr_write(emu, PLAYBACK_PERIOD_SIZE, channel, 0);
snd_ca0106_ptr_write(emu, PLAYBACK_POINTER, channel, 0);
snd_ca0106_ptr_write(emu, 0x07, channel, 0x0);
snd_ca0106_ptr_write(emu, 0x08, channel, 0);
snd_ca0106_ptr_write(emu, PLAYBACK_MUTE, 0x0, 0x0);
#if 0
snd_ca0106_ptr_write(emu, SPCS0, 0,
SPCS_CLKACCY_1000PPM | SPCS_SAMPLERATE_48 |
SPCS_CHANNELNUM_LEFT | SPCS_SOURCENUM_UNSPEC |
SPCS_GENERATIONSTATUS | 0x00001200 |
0x00000000 | SPCS_EMPHASIS_NONE | SPCS_COPYRIGHT );
#endif
return 0;
}
static int snd_ca0106_pcm_prepare_capture(struct snd_pcm_substream *substream)
{
struct snd_ca0106 *emu = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
struct snd_ca0106_pcm *epcm = runtime->private_data;
int channel = epcm->channel_id;
u32 hcfg_mask = HCFG_CAPTURE_S32_LE;
u32 hcfg_set = 0x00000000;
u32 hcfg;
u32 over_sampling=0x2;
u32 reg71_mask = 0x0000c000 ;
u32 reg71_set = 0;
u32 reg71;
#if 0
dev_dbg(emu->card->dev,
"prepare:channel_number=%d, rate=%d, format=0x%x, "
"channels=%d, buffer_size=%ld, period_size=%ld, "
"periods=%u, frames_to_bytes=%d\n",
channel, runtime->rate, runtime->format,
runtime->channels, runtime->buffer_size,
runtime->period_size, runtime->periods,
frames_to_bytes(runtime, 1));
dev_dbg(emu->card->dev,
"dma_addr=%x, dma_area=%p, table_base=%p\n",
runtime->dma_addr, runtime->dma_area, table_base);
dev_dbg(emu->card->dev,
"dma_addr=%x, dma_area=%p, dma_bytes(size)=%x\n",
emu->buffer.addr, emu->buffer.area, emu->buffer.bytes);
#endif
switch (runtime->rate) {
case 44100:
reg71_set = 0x00004000;
break;
case 48000:
reg71_set = 0;
break;
case 96000:
reg71_set = 0x00008000;
over_sampling=0xa;
break;
case 192000:
reg71_set = 0x0000c000;
over_sampling=0xa;
break;
default:
reg71_set = 0;
break;
}
switch (runtime->format) {
case SNDRV_PCM_FORMAT_S16_LE:
hcfg_set = 0;
break;
case SNDRV_PCM_FORMAT_S32_LE:
hcfg_set = HCFG_CAPTURE_S32_LE;
break;
default:
hcfg_set = 0;
break;
}
hcfg = inl(emu->port + HCFG) ;
hcfg = (hcfg & ~hcfg_mask) | hcfg_set;
outl(hcfg, emu->port + HCFG);
reg71 = snd_ca0106_ptr_read(emu, 0x71, 0);
reg71 = (reg71 & ~reg71_mask) | reg71_set;
snd_ca0106_ptr_write(emu, 0x71, 0, reg71);
if (emu->details->i2c_adc == 1) {
snd_ca0106_i2c_write(emu, ADC_MASTER, over_sampling);
}
snd_ca0106_ptr_write(emu, 0x13, channel, 0);
snd_ca0106_ptr_write(emu, CAPTURE_DMA_ADDR, channel, runtime->dma_addr);
snd_ca0106_ptr_write(emu, CAPTURE_BUFFER_SIZE, channel, frames_to_bytes(runtime, runtime->buffer_size)<<16);
snd_ca0106_ptr_write(emu, CAPTURE_POINTER, channel, 0);
return 0;
}
static int snd_ca0106_pcm_trigger_playback(struct snd_pcm_substream *substream,
int cmd)
{
struct snd_ca0106 *emu = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime;
struct snd_ca0106_pcm *epcm;
int channel;
int result = 0;
struct snd_pcm_substream *s;
u32 basic = 0;
u32 extended = 0;
u32 bits;
int running = 0;
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
case SNDRV_PCM_TRIGGER_RESUME:
running = 1;
break;
case SNDRV_PCM_TRIGGER_STOP:
case SNDRV_PCM_TRIGGER_SUSPEND:
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
channel = epcm->channel_id;
epcm->running = running;
basic |= (0x1 << channel);
extended |= (0x10 << channel);
snd_pcm_trigger_done(s, substream);
}
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
case SNDRV_PCM_TRIGGER_RESUME:
bits = snd_ca0106_ptr_read(emu, EXTENDED_INT_MASK, 0);
bits |= extended;
snd_ca0106_ptr_write(emu, EXTENDED_INT_MASK, 0, bits);
bits = snd_ca0106_ptr_read(emu, BASIC_INTERRUPT, 0);
bits |= basic;
snd_ca0106_ptr_write(emu, BASIC_INTERRUPT, 0, bits);
break;
case SNDRV_PCM_TRIGGER_STOP:
case SNDRV_PCM_TRIGGER_SUSPEND:
bits = snd_ca0106_ptr_read(emu, BASIC_INTERRUPT, 0);
bits &= ~basic;
snd_ca0106_ptr_write(emu, BASIC_INTERRUPT, 0, bits);
bits = snd_ca0106_ptr_read(emu, EXTENDED_INT_MASK, 0);
bits &= ~extended;
snd_ca0106_ptr_write(emu, EXTENDED_INT_MASK, 0, bits);
break;
default:
result = -EINVAL;
break;
}
return result;
}
static int snd_ca0106_pcm_trigger_capture(struct snd_pcm_substream *substream,
int cmd)
{
struct snd_ca0106 *emu = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
struct snd_ca0106_pcm *epcm = runtime->private_data;
int channel = epcm->channel_id;
int result = 0;
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
snd_ca0106_ptr_write(emu, EXTENDED_INT_MASK, 0, snd_ca0106_ptr_read(emu, EXTENDED_INT_MASK, 0) | (0x110000<<channel));
snd_ca0106_ptr_write(emu, BASIC_INTERRUPT, 0, snd_ca0106_ptr_read(emu, BASIC_INTERRUPT, 0)|(0x100<<channel));
epcm->running = 1;
break;
case SNDRV_PCM_TRIGGER_STOP:
snd_ca0106_ptr_write(emu, BASIC_INTERRUPT, 0, snd_ca0106_ptr_read(emu, BASIC_INTERRUPT, 0) & ~(0x100<<channel));
snd_ca0106_ptr_write(emu, EXTENDED_INT_MASK, 0, snd_ca0106_ptr_read(emu, EXTENDED_INT_MASK, 0) & ~(0x110000<<channel));
epcm->running = 0;
break;
default:
result = -EINVAL;
break;
}
return result;
}
static snd_pcm_uframes_t
snd_ca0106_pcm_pointer_playback(struct snd_pcm_substream *substream)
{
struct snd_ca0106 *emu = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
struct snd_ca0106_pcm *epcm = runtime->private_data;
unsigned int ptr, prev_ptr;
int channel = epcm->channel_id;
int timeout = 10;
if (!epcm->running)
return 0;
prev_ptr = -1;
do {
ptr = snd_ca0106_ptr_read(emu, PLAYBACK_LIST_PTR, channel);
ptr = (ptr >> 3) * runtime->period_size;
ptr += bytes_to_frames(runtime,
snd_ca0106_ptr_read(emu, PLAYBACK_POINTER, channel));
if (ptr >= runtime->buffer_size)
ptr -= runtime->buffer_size;
if (prev_ptr == ptr)
return ptr;
prev_ptr = ptr;
} while (--timeout);
dev_warn(emu->card->dev, "ca0106: unstable DMA pointer!\n");
return 0;
}
static snd_pcm_uframes_t
snd_ca0106_pcm_pointer_capture(struct snd_pcm_substream *substream)
{
struct snd_ca0106 *emu = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
struct snd_ca0106_pcm *epcm = runtime->private_data;
snd_pcm_uframes_t ptr, ptr1, ptr2 = 0;
int channel = epcm->channel_id;
if (!epcm->running)
return 0;
ptr1 = snd_ca0106_ptr_read(emu, CAPTURE_POINTER, channel);
ptr2 = bytes_to_frames(runtime, ptr1);
ptr=ptr2;
if (ptr >= runtime->buffer_size)
ptr -= runtime->buffer_size;
return ptr;
}
static unsigned short snd_ca0106_ac97_read(struct snd_ac97 *ac97,
unsigned short reg)
{
struct snd_ca0106 *emu = ac97->private_data;
unsigned long flags;
unsigned short val;
spin_lock_irqsave(&emu->emu_lock, flags);
outb(reg, emu->port + AC97ADDRESS);
val = inw(emu->port + AC97DATA);
spin_unlock_irqrestore(&emu->emu_lock, flags);
return val;
}
static void snd_ca0106_ac97_write(struct snd_ac97 *ac97,
unsigned short reg, unsigned short val)
{
struct snd_ca0106 *emu = ac97->private_data;
unsigned long flags;
spin_lock_irqsave(&emu->emu_lock, flags);
outb(reg, emu->port + AC97ADDRESS);
outw(val, emu->port + AC97DATA);
spin_unlock_irqrestore(&emu->emu_lock, flags);
}
static int snd_ca0106_ac97(struct snd_ca0106 *chip)
{
struct snd_ac97_bus *pbus;
struct snd_ac97_template ac97;
int err;
static struct snd_ac97_bus_ops ops = {
.write = snd_ca0106_ac97_write,
.read = snd_ca0106_ac97_read,
};
if ((err = snd_ac97_bus(chip->card, 0, &ops, NULL, &pbus)) < 0)
return err;
pbus->no_vra = 1;
memset(&ac97, 0, sizeof(ac97));
ac97.private_data = chip;
ac97.scaps = AC97_SCAP_NO_SPDIF;
return snd_ac97_mixer(pbus, &ac97, &chip->ac97);
}
static int snd_ca0106_free(struct snd_ca0106 *chip)
{
if (chip->res_port != NULL) {
ca0106_stop_chip(chip);
}
if (chip->irq >= 0)
free_irq(chip->irq, chip);
#if 1
if (chip->buffer.area)
snd_dma_free_pages(&chip->buffer);
#endif
release_and_free_resource(chip->res_port);
pci_disable_device(chip->pci);
kfree(chip);
return 0;
}
static int snd_ca0106_dev_free(struct snd_device *device)
{
struct snd_ca0106 *chip = device->device_data;
return snd_ca0106_free(chip);
}
static irqreturn_t snd_ca0106_interrupt(int irq, void *dev_id)
{
unsigned int status;
struct snd_ca0106 *chip = dev_id;
int i;
int mask;
unsigned int stat76;
struct snd_ca0106_channel *pchannel;
status = inl(chip->port + IPR);
if (! status)
return IRQ_NONE;
stat76 = snd_ca0106_ptr_read(chip, EXTENDED_INT, 0);
mask = 0x11;
for(i = 0; i < 4; i++) {
pchannel = &(chip->playback_channels[i]);
if (stat76 & mask) {
if(pchannel->use) {
snd_pcm_period_elapsed(pchannel->epcm->substream);
}
}
mask <<= 1;
}
mask = 0x110000;
for(i = 0; i < 4; i++) {
pchannel = &(chip->capture_channels[i]);
if (stat76 & mask) {
if(pchannel->use) {
snd_pcm_period_elapsed(pchannel->epcm->substream);
}
}
mask <<= 1;
}
snd_ca0106_ptr_write(chip, EXTENDED_INT, 0, stat76);
if (chip->midi.dev_id &&
(status & (chip->midi.ipr_tx|chip->midi.ipr_rx))) {
if (chip->midi.interrupt)
chip->midi.interrupt(&chip->midi, status);
else
chip->midi.interrupt_disable(&chip->midi, chip->midi.tx_enable | chip->midi.rx_enable);
}
outl(status, chip->port+IPR);
return IRQ_HANDLED;
}
static int snd_ca0106_pcm(struct snd_ca0106 *emu, int device)
{
struct snd_pcm *pcm;
struct snd_pcm_substream *substream;
const struct snd_pcm_chmap_elem *map = NULL;
int err;
err = snd_pcm_new(emu->card, "ca0106", device, 1, 1, &pcm);
if (err < 0)
return err;
pcm->private_data = emu;
switch (device) {
case 0:
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_PLAYBACK, &snd_ca0106_playback_front_ops);
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_CAPTURE, &snd_ca0106_capture_0_ops);
map = snd_pcm_std_chmaps;
break;
case 1:
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_PLAYBACK, &snd_ca0106_playback_rear_ops);
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_CAPTURE, &snd_ca0106_capture_1_ops);
map = surround_map;
break;
case 2:
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_PLAYBACK, &snd_ca0106_playback_center_lfe_ops);
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_CAPTURE, &snd_ca0106_capture_2_ops);
map = clfe_map;
break;
case 3:
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_PLAYBACK, &snd_ca0106_playback_unknown_ops);
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_CAPTURE, &snd_ca0106_capture_3_ops);
map = side_map;
break;
}
pcm->info_flags = 0;
strcpy(pcm->name, "CA0106");
for(substream = pcm->streams[SNDRV_PCM_STREAM_PLAYBACK].substream;
substream;
substream = substream->next) {
if ((err = snd_pcm_lib_preallocate_pages(substream,
SNDRV_DMA_TYPE_DEV,
snd_dma_pci_data(emu->pci),
64*1024, 64*1024)) < 0)
return err;
}
for (substream = pcm->streams[SNDRV_PCM_STREAM_CAPTURE].substream;
substream;
substream = substream->next) {
if ((err = snd_pcm_lib_preallocate_pages(substream,
SNDRV_DMA_TYPE_DEV,
snd_dma_pci_data(emu->pci),
64*1024, 64*1024)) < 0)
return err;
}
err = snd_pcm_add_chmap_ctls(pcm, SNDRV_PCM_STREAM_PLAYBACK, map, 2,
1 << 2, NULL);
if (err < 0)
return err;
emu->pcm[device] = pcm;
return 0;
}
static void ca0106_init_chip(struct snd_ca0106 *chip, int resume)
{
int ch;
unsigned int def_bits;
outl(0, chip->port + INTE);
def_bits =
SPCS_CLKACCY_1000PPM | SPCS_SAMPLERATE_48 |
SPCS_CHANNELNUM_LEFT | SPCS_SOURCENUM_UNSPEC |
SPCS_GENERATIONSTATUS | 0x00001200 |
0x00000000 | SPCS_EMPHASIS_NONE | SPCS_COPYRIGHT;
if (!resume) {
chip->spdif_str_bits[0] = chip->spdif_bits[0] = def_bits;
chip->spdif_str_bits[1] = chip->spdif_bits[1] = def_bits;
chip->spdif_str_bits[2] = chip->spdif_bits[2] = def_bits;
chip->spdif_str_bits[3] = chip->spdif_bits[3] = def_bits;
}
snd_ca0106_ptr_write(chip, SPCS1, 0, chip->spdif_str_bits[1]);
snd_ca0106_ptr_write(chip, SPCS0, 0, chip->spdif_str_bits[0]);
snd_ca0106_ptr_write(chip, SPCS2, 0, chip->spdif_str_bits[2]);
snd_ca0106_ptr_write(chip, SPCS3, 0, chip->spdif_str_bits[3]);
snd_ca0106_ptr_write(chip, PLAYBACK_MUTE, 0, 0x00fc0000);
snd_ca0106_ptr_write(chip, CAPTURE_MUTE, 0, 0x00fc0000);
outb(AC97_REC_GAIN, chip->port + AC97ADDRESS);
outw(0x8000, chip->port + AC97DATA);
#if 0
snd_ca0106_ptr_write(chip, SPCS0, 0, 0x2108006);
snd_ca0106_ptr_write(chip, 0x42, 0, 0x2108006);
snd_ca0106_ptr_write(chip, 0x43, 0, 0x2108006);
snd_ca0106_ptr_write(chip, 0x44, 0, 0x2108006);
#endif
snd_ca0106_ptr_write(chip, SPDIF_SELECT1, 0, 0xf);
snd_ca0106_ptr_write(chip, SPDIF_SELECT2, 0, 0x000f0000);
chip->spdif_enable = 0;
snd_ca0106_ptr_write(chip, CAPTURE_CONTROL, 0, 0x40c81000);
snd_ca0106_ptr_write(chip, CAPTURE_CONTROL, 1, 0xffffffff);
snd_ca0106_ptr_write(chip, CAPTURE_CONTROL, 2, 0x30300000);
snd_ca0106_ptr_write(chip, CAPTURE_CONTROL, 3, 0x00700000);
snd_ca0106_ptr_write(chip, PLAYBACK_ROUTING1, 0, 0x32765410);
snd_ca0106_ptr_write(chip, PLAYBACK_ROUTING2, 0, 0x76767676);
snd_ca0106_ptr_write(chip, CAPTURE_ROUTING1, 0, 0x32765410);
snd_ca0106_ptr_write(chip, CAPTURE_ROUTING2, 0, 0x76767676);
for (ch = 0; ch < 4; ch++) {
snd_ca0106_ptr_write(chip, CAPTURE_VOLUME1, ch, 0x30303030);
snd_ca0106_ptr_write(chip, CAPTURE_VOLUME2, ch, 0x30303030);
#if 0
snd_ca0106_ptr_write(chip, PLAYBACK_VOLUME1, ch, 0x40404040);
snd_ca0106_ptr_write(chip, PLAYBACK_VOLUME2, ch, 0x40404040);
snd_ca0106_ptr_write(chip, PLAYBACK_VOLUME1, ch, 0xffffffff);
snd_ca0106_ptr_write(chip, PLAYBACK_VOLUME2, ch, 0xffffffff);
#endif
}
if (chip->details->i2c_adc == 1) {
snd_ca0106_ptr_write(chip, CAPTURE_SOURCE, 0x0, 0x333300e4);
if (!resume)
chip->capture_source = 3;
} else if (chip->details->ac97 == 1) {
snd_ca0106_ptr_write(chip, CAPTURE_SOURCE, 0x0, 0x444400e4);
if (!resume)
chip->capture_source = 4;
} else {
snd_ca0106_ptr_write(chip, CAPTURE_SOURCE, 0x0, 0x333300e4);
if (!resume)
chip->capture_source = 3;
}
if (chip->details->gpio_type == 2) {
outl(0x0, chip->port+GPIO);
outl(0x005f5301, chip->port+GPIO);
} else if (chip->details->gpio_type == 1) {
outl(0x0, chip->port+GPIO);
outl(0x005f5301, chip->port+GPIO);
} else {
outl(0x0, chip->port+GPIO);
outl(0x005f03a3, chip->port+GPIO);
}
snd_ca0106_intr_enable(chip, 0x105);
outl(HCFG_AC97 | HCFG_AUDIOENABLE, chip->port+HCFG);
if (chip->details->i2c_adc == 1) {
int size, n;
size = ARRAY_SIZE(i2c_adc_init);
for (n = 0; n < size; n++)
snd_ca0106_i2c_write(chip, i2c_adc_init[n][0],
i2c_adc_init[n][1]);
for (n = 0; n < 4; n++) {
chip->i2c_capture_volume[n][0] = 0xcf;
chip->i2c_capture_volume[n][1] = 0xcf;
}
chip->i2c_capture_source = 2;
}
if (chip->details->spi_dac) {
int size, n;
size = ARRAY_SIZE(spi_dac_init);
for (n = 0; n < size; n++) {
int reg = spi_dac_init[n] >> SPI_REG_SHIFT;
snd_ca0106_spi_write(chip, spi_dac_init[n]);
if (reg < ARRAY_SIZE(chip->spi_dac_reg))
chip->spi_dac_reg[reg] = spi_dac_init[n];
}
snd_ca0106_pcm_power_dac(chip, PCM_FRONT_CHANNEL, 1);
}
}
static void ca0106_stop_chip(struct snd_ca0106 *chip)
{
snd_ca0106_ptr_write(chip, BASIC_INTERRUPT, 0, 0);
outl(0, chip->port + INTE);
snd_ca0106_ptr_write(chip, EXTENDED_INT_MASK, 0, 0);
udelay(1000);
outl(0, chip->port + HCFG);
}
static int snd_ca0106_create(int dev, struct snd_card *card,
struct pci_dev *pci,
struct snd_ca0106 **rchip)
{
struct snd_ca0106 *chip;
struct snd_ca0106_details *c;
int err;
static struct snd_device_ops ops = {
.dev_free = snd_ca0106_dev_free,
};
*rchip = NULL;
err = pci_enable_device(pci);
if (err < 0)
return err;
if (dma_set_mask(&pci->dev, DMA_BIT_MASK(32)) < 0 ||
dma_set_coherent_mask(&pci->dev, DMA_BIT_MASK(32)) < 0) {
dev_err(card->dev, "error to set 32bit mask DMA\n");
pci_disable_device(pci);
return -ENXIO;
}
chip = kzalloc(sizeof(*chip), GFP_KERNEL);
if (chip == NULL) {
pci_disable_device(pci);
return -ENOMEM;
}
chip->card = card;
chip->pci = pci;
chip->irq = -1;
spin_lock_init(&chip->emu_lock);
chip->port = pci_resource_start(pci, 0);
chip->res_port = request_region(chip->port, 0x20, "snd_ca0106");
if (!chip->res_port) {
snd_ca0106_free(chip);
dev_err(card->dev, "cannot allocate the port\n");
return -EBUSY;
}
if (request_irq(pci->irq, snd_ca0106_interrupt,
IRQF_SHARED, KBUILD_MODNAME, chip)) {
snd_ca0106_free(chip);
dev_err(card->dev, "cannot grab irq\n");
return -EBUSY;
}
chip->irq = pci->irq;
if (snd_dma_alloc_pages(SNDRV_DMA_TYPE_DEV, snd_dma_pci_data(pci),
1024, &chip->buffer) < 0) {
snd_ca0106_free(chip);
return -ENOMEM;
}
pci_set_master(pci);
pci_read_config_dword(pci, PCI_SUBSYSTEM_VENDOR_ID, &chip->serial);
pci_read_config_word(pci, PCI_SUBSYSTEM_ID, &chip->model);
dev_info(card->dev, "Model %04x Rev %08x Serial %08x\n",
chip->model, pci->revision, chip->serial);
strcpy(card->driver, "CA0106");
strcpy(card->shortname, "CA0106");
for (c = ca0106_chip_details; c->serial; c++) {
if (subsystem[dev]) {
if (c->serial == subsystem[dev])
break;
} else if (c->serial == chip->serial)
break;
}
chip->details = c;
if (subsystem[dev]) {
dev_info(card->dev, "Sound card name=%s, "
"subsystem=0x%x. Forced to subsystem=0x%x\n",
c->name, chip->serial, subsystem[dev]);
}
sprintf(card->longname, "%s at 0x%lx irq %i",
c->name, chip->port, chip->irq);
ca0106_init_chip(chip, 0);
err = snd_device_new(card, SNDRV_DEV_LOWLEVEL, chip, &ops);
if (err < 0) {
snd_ca0106_free(chip);
return err;
}
*rchip = chip;
return 0;
}
static void ca0106_midi_interrupt_enable(struct snd_ca_midi *midi, int intr)
{
snd_ca0106_intr_enable((struct snd_ca0106 *)(midi->dev_id), intr);
}
static void ca0106_midi_interrupt_disable(struct snd_ca_midi *midi, int intr)
{
snd_ca0106_intr_disable((struct snd_ca0106 *)(midi->dev_id), intr);
}
static unsigned char ca0106_midi_read(struct snd_ca_midi *midi, int idx)
{
return (unsigned char)snd_ca0106_ptr_read((struct snd_ca0106 *)(midi->dev_id),
midi->port + idx, 0);
}
static void ca0106_midi_write(struct snd_ca_midi *midi, int data, int idx)
{
snd_ca0106_ptr_write((struct snd_ca0106 *)(midi->dev_id), midi->port + idx, 0, data);
}
static struct snd_card *ca0106_dev_id_card(void *dev_id)
{
return ((struct snd_ca0106 *)dev_id)->card;
}
static int ca0106_dev_id_port(void *dev_id)
{
return ((struct snd_ca0106 *)dev_id)->port;
}
static int snd_ca0106_midi(struct snd_ca0106 *chip, unsigned int channel)
{
struct snd_ca_midi *midi;
char *name;
int err;
if (channel == CA0106_MIDI_CHAN_B) {
name = "CA0106 MPU-401 (UART) B";
midi = &chip->midi2;
midi->tx_enable = INTE_MIDI_TX_B;
midi->rx_enable = INTE_MIDI_RX_B;
midi->ipr_tx = IPR_MIDI_TX_B;
midi->ipr_rx = IPR_MIDI_RX_B;
midi->port = MIDI_UART_B_DATA;
} else {
name = "CA0106 MPU-401 (UART)";
midi = &chip->midi;
midi->tx_enable = INTE_MIDI_TX_A;
midi->rx_enable = INTE_MIDI_TX_B;
midi->ipr_tx = IPR_MIDI_TX_A;
midi->ipr_rx = IPR_MIDI_RX_A;
midi->port = MIDI_UART_A_DATA;
}
midi->reset = CA0106_MPU401_RESET;
midi->enter_uart = CA0106_MPU401_ENTER_UART;
midi->ack = CA0106_MPU401_ACK;
midi->input_avail = CA0106_MIDI_INPUT_AVAIL;
midi->output_ready = CA0106_MIDI_OUTPUT_READY;
midi->channel = channel;
midi->interrupt_enable = ca0106_midi_interrupt_enable;
midi->interrupt_disable = ca0106_midi_interrupt_disable;
midi->read = ca0106_midi_read;
midi->write = ca0106_midi_write;
midi->get_dev_id_card = ca0106_dev_id_card;
midi->get_dev_id_port = ca0106_dev_id_port;
midi->dev_id = chip;
if ((err = ca_midi_init(chip, midi, 0, name)) < 0)
return err;
return 0;
}
static int snd_ca0106_probe(struct pci_dev *pci,
const struct pci_device_id *pci_id)
{
static int dev;
struct snd_card *card;
struct snd_ca0106 *chip;
int i, err;
if (dev >= SNDRV_CARDS)
return -ENODEV;
if (!enable[dev]) {
dev++;
return -ENOENT;
}
err = snd_card_new(&pci->dev, index[dev], id[dev], THIS_MODULE,
0, &card);
if (err < 0)
return err;
err = snd_ca0106_create(dev, card, pci, &chip);
if (err < 0)
goto error;
card->private_data = chip;
for (i = 0; i < 4; i++) {
err = snd_ca0106_pcm(chip, i);
if (err < 0)
goto error;
}
if (chip->details->ac97 == 1) {
err = snd_ca0106_ac97(chip);
if (err < 0)
goto error;
}
err = snd_ca0106_mixer(chip);
if (err < 0)
goto error;
dev_dbg(card->dev, "probe for MIDI channel A ...");
err = snd_ca0106_midi(chip, CA0106_MIDI_CHAN_A);
if (err < 0)
goto error;
dev_dbg(card->dev, " done.\n");
#ifdef CONFIG_SND_PROC_FS
snd_ca0106_proc_init(chip);
#endif
err = snd_card_register(card);
if (err < 0)
goto error;
pci_set_drvdata(pci, card);
dev++;
return 0;
error:
snd_card_free(card);
return err;
}
static void snd_ca0106_remove(struct pci_dev *pci)
{
snd_card_free(pci_get_drvdata(pci));
}
static int snd_ca0106_suspend(struct device *dev)
{
struct snd_card *card = dev_get_drvdata(dev);
struct snd_ca0106 *chip = card->private_data;
int i;
snd_power_change_state(card, SNDRV_CTL_POWER_D3hot);
for (i = 0; i < 4; i++)
snd_pcm_suspend_all(chip->pcm[i]);
if (chip->details->ac97)
snd_ac97_suspend(chip->ac97);
snd_ca0106_mixer_suspend(chip);
ca0106_stop_chip(chip);
return 0;
}
static int snd_ca0106_resume(struct device *dev)
{
struct snd_card *card = dev_get_drvdata(dev);
struct snd_ca0106 *chip = card->private_data;
int i;
ca0106_init_chip(chip, 1);
if (chip->details->ac97)
snd_ac97_resume(chip->ac97);
snd_ca0106_mixer_resume(chip);
if (chip->details->spi_dac) {
for (i = 0; i < ARRAY_SIZE(chip->spi_dac_reg); i++)
snd_ca0106_spi_write(chip, chip->spi_dac_reg[i]);
}
snd_power_change_state(card, SNDRV_CTL_POWER_D0);
return 0;
}
