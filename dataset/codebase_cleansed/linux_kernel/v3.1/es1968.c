static void __maestro_write(struct es1968 *chip, u16 reg, u16 data)
{
outw(reg, chip->io_port + ESM_INDEX);
outw(data, chip->io_port + ESM_DATA);
chip->maestro_map[reg] = data;
}
static inline void maestro_write(struct es1968 *chip, u16 reg, u16 data)
{
unsigned long flags;
spin_lock_irqsave(&chip->reg_lock, flags);
__maestro_write(chip, reg, data);
spin_unlock_irqrestore(&chip->reg_lock, flags);
}
static u16 __maestro_read(struct es1968 *chip, u16 reg)
{
if (READABLE_MAP & (1 << reg)) {
outw(reg, chip->io_port + ESM_INDEX);
chip->maestro_map[reg] = inw(chip->io_port + ESM_DATA);
}
return chip->maestro_map[reg];
}
static inline u16 maestro_read(struct es1968 *chip, u16 reg)
{
unsigned long flags;
u16 result;
spin_lock_irqsave(&chip->reg_lock, flags);
result = __maestro_read(chip, reg);
spin_unlock_irqrestore(&chip->reg_lock, flags);
return result;
}
static int snd_es1968_ac97_wait(struct es1968 *chip)
{
int timeout = 100000;
while (timeout-- > 0) {
if (!(inb(chip->io_port + ESM_AC97_INDEX) & 1))
return 0;
cond_resched();
}
snd_printd("es1968: ac97 timeout\n");
return 1;
}
static int snd_es1968_ac97_wait_poll(struct es1968 *chip)
{
int timeout = 100000;
while (timeout-- > 0) {
if (!(inb(chip->io_port + ESM_AC97_INDEX) & 1))
return 0;
}
snd_printd("es1968: ac97 timeout\n");
return 1;
}
static void snd_es1968_ac97_write(struct snd_ac97 *ac97, unsigned short reg, unsigned short val)
{
struct es1968 *chip = ac97->private_data;
snd_es1968_ac97_wait(chip);
outw(val, chip->io_port + ESM_AC97_DATA);
outb(reg, chip->io_port + ESM_AC97_INDEX);
}
static unsigned short snd_es1968_ac97_read(struct snd_ac97 *ac97, unsigned short reg)
{
u16 data = 0;
struct es1968 *chip = ac97->private_data;
snd_es1968_ac97_wait(chip);
outb(reg | 0x80, chip->io_port + ESM_AC97_INDEX);
if (!snd_es1968_ac97_wait_poll(chip)) {
data = inw(chip->io_port + ESM_AC97_DATA);
}
return data;
}
static void apu_index_set(struct es1968 *chip, u16 index)
{
int i;
__maestro_write(chip, IDR1_CRAM_POINTER, index);
for (i = 0; i < 1000; i++)
if (__maestro_read(chip, IDR1_CRAM_POINTER) == index)
return;
snd_printd("es1968: APU register select failed. (Timeout)\n");
}
static void apu_data_set(struct es1968 *chip, u16 data)
{
int i;
for (i = 0; i < 1000; i++) {
if (__maestro_read(chip, IDR0_DATA_PORT) == data)
return;
__maestro_write(chip, IDR0_DATA_PORT, data);
}
snd_printd("es1968: APU register set probably failed (Timeout)!\n");
}
static void __apu_set_register(struct es1968 *chip, u16 channel, u8 reg, u16 data)
{
if (snd_BUG_ON(channel >= NR_APUS))
return;
#ifdef CONFIG_PM
chip->apu_map[channel][reg] = data;
#endif
reg |= (channel << 4);
apu_index_set(chip, reg);
apu_data_set(chip, data);
}
static void apu_set_register(struct es1968 *chip, u16 channel, u8 reg, u16 data)
{
unsigned long flags;
spin_lock_irqsave(&chip->reg_lock, flags);
__apu_set_register(chip, channel, reg, data);
spin_unlock_irqrestore(&chip->reg_lock, flags);
}
static u16 __apu_get_register(struct es1968 *chip, u16 channel, u8 reg)
{
if (snd_BUG_ON(channel >= NR_APUS))
return 0;
reg |= (channel << 4);
apu_index_set(chip, reg);
return __maestro_read(chip, IDR0_DATA_PORT);
}
static u16 apu_get_register(struct es1968 *chip, u16 channel, u8 reg)
{
unsigned long flags;
u16 v;
spin_lock_irqsave(&chip->reg_lock, flags);
v = __apu_get_register(chip, channel, reg);
spin_unlock_irqrestore(&chip->reg_lock, flags);
return v;
}
static void wave_set_register(struct es1968 *chip, u16 reg, u16 value)
{
unsigned long flags;
spin_lock_irqsave(&chip->reg_lock, flags);
outw(reg, chip->io_port + WC_INDEX);
outw(value, chip->io_port + WC_DATA);
spin_unlock_irqrestore(&chip->reg_lock, flags);
}
static u16 wave_get_register(struct es1968 *chip, u16 reg)
{
unsigned long flags;
u16 value;
spin_lock_irqsave(&chip->reg_lock, flags);
outw(reg, chip->io_port + WC_INDEX);
value = inw(chip->io_port + WC_DATA);
spin_unlock_irqrestore(&chip->reg_lock, flags);
return value;
}
static void snd_es1968_bob_stop(struct es1968 *chip)
{
u16 reg;
reg = __maestro_read(chip, 0x11);
reg &= ~ESM_BOB_ENABLE;
__maestro_write(chip, 0x11, reg);
reg = __maestro_read(chip, 0x17);
reg &= ~ESM_BOB_START;
__maestro_write(chip, 0x17, reg);
}
static void snd_es1968_bob_start(struct es1968 *chip)
{
int prescale;
int divide;
for (prescale = 5; prescale < 12; prescale++)
if (chip->bob_freq > (ESS_SYSCLK >> (prescale + 9)))
break;
divide = 1;
while ((prescale > 5) && (divide < 32)) {
prescale--;
divide <<= 1;
}
divide >>= 1;
for (; divide < 31; divide++)
if (chip->bob_freq >
((ESS_SYSCLK >> (prescale + 9)) / (divide + 1))) break;
if (divide == 0) {
divide++;
if (prescale > 5)
prescale--;
} else if (divide > 1)
divide--;
__maestro_write(chip, 6, 0x9000 | (prescale << 5) | divide);
__maestro_write(chip, 0x11, __maestro_read(chip, 0x11) | 1);
__maestro_write(chip, 0x17, __maestro_read(chip, 0x17) | 1);
}
static void snd_es1968_bob_inc(struct es1968 *chip, int freq)
{
chip->bobclient++;
if (chip->bobclient == 1) {
chip->bob_freq = freq;
snd_es1968_bob_start(chip);
} else if (chip->bob_freq < freq) {
snd_es1968_bob_stop(chip);
chip->bob_freq = freq;
snd_es1968_bob_start(chip);
}
}
static void snd_es1968_bob_dec(struct es1968 *chip)
{
chip->bobclient--;
if (chip->bobclient <= 0)
snd_es1968_bob_stop(chip);
else if (chip->bob_freq > ESM_BOB_FREQ) {
int max_freq = ESM_BOB_FREQ;
struct esschan *es;
list_for_each_entry(es, &chip->substream_list, list) {
if (max_freq < es->bob_freq)
max_freq = es->bob_freq;
}
if (max_freq != chip->bob_freq) {
snd_es1968_bob_stop(chip);
chip->bob_freq = max_freq;
snd_es1968_bob_start(chip);
}
}
}
static int
snd_es1968_calc_bob_rate(struct es1968 *chip, struct esschan *es,
struct snd_pcm_runtime *runtime)
{
int freq = runtime->rate * 4;
if (es->fmt & ESS_FMT_STEREO)
freq <<= 1;
if (es->fmt & ESS_FMT_16BIT)
freq <<= 1;
freq /= es->frag_size;
if (freq < ESM_BOB_FREQ)
freq = ESM_BOB_FREQ;
else if (freq > ESM_BOB_FREQ_MAX)
freq = ESM_BOB_FREQ_MAX;
return freq;
}
static u32 snd_es1968_compute_rate(struct es1968 *chip, u32 freq)
{
u32 rate = (freq << 16) / chip->clock;
#if 0
if (rate > 0x10000)
rate = 0x10000;
#endif
return rate;
}
static inline unsigned int
snd_es1968_get_dma_ptr(struct es1968 *chip, struct esschan *es)
{
unsigned int offset;
offset = apu_get_register(chip, es->apu[0], 5);
offset -= es->base[0];
return (offset & 0xFFFE);
}
static void snd_es1968_apu_set_freq(struct es1968 *chip, int apu, int freq)
{
apu_set_register(chip, apu, 2,
(apu_get_register(chip, apu, 2) & 0x00FF) |
((freq & 0xff) << 8) | 0x10);
apu_set_register(chip, apu, 3, freq >> 8);
}
static inline void snd_es1968_trigger_apu(struct es1968 *esm, int apu, int mode)
{
__apu_set_register(esm, apu, 0,
(__apu_get_register(esm, apu, 0) & 0xff0f) |
(mode << 4));
}
static void snd_es1968_pcm_start(struct es1968 *chip, struct esschan *es)
{
spin_lock(&chip->reg_lock);
__apu_set_register(chip, es->apu[0], 5, es->base[0]);
snd_es1968_trigger_apu(chip, es->apu[0], es->apu_mode[0]);
if (es->mode == ESM_MODE_CAPTURE) {
__apu_set_register(chip, es->apu[2], 5, es->base[2]);
snd_es1968_trigger_apu(chip, es->apu[2], es->apu_mode[2]);
}
if (es->fmt & ESS_FMT_STEREO) {
__apu_set_register(chip, es->apu[1], 5, es->base[1]);
snd_es1968_trigger_apu(chip, es->apu[1], es->apu_mode[1]);
if (es->mode == ESM_MODE_CAPTURE) {
__apu_set_register(chip, es->apu[3], 5, es->base[3]);
snd_es1968_trigger_apu(chip, es->apu[3], es->apu_mode[3]);
}
}
spin_unlock(&chip->reg_lock);
}
static void snd_es1968_pcm_stop(struct es1968 *chip, struct esschan *es)
{
spin_lock(&chip->reg_lock);
snd_es1968_trigger_apu(chip, es->apu[0], 0);
snd_es1968_trigger_apu(chip, es->apu[1], 0);
if (es->mode == ESM_MODE_CAPTURE) {
snd_es1968_trigger_apu(chip, es->apu[2], 0);
snd_es1968_trigger_apu(chip, es->apu[3], 0);
}
spin_unlock(&chip->reg_lock);
}
static void snd_es1968_program_wavecache(struct es1968 *chip, struct esschan *es,
int channel, u32 addr, int capture)
{
u32 tmpval = (addr - 0x10) & 0xFFF8;
if (! capture) {
if (!(es->fmt & ESS_FMT_16BIT))
tmpval |= 4;
if (es->fmt & ESS_FMT_STEREO)
tmpval |= 2;
}
wave_set_register(chip, es->apu[channel] << 3, tmpval);
#ifdef CONFIG_PM
es->wc_map[channel] = tmpval;
#endif
}
static void snd_es1968_playback_setup(struct es1968 *chip, struct esschan *es,
struct snd_pcm_runtime *runtime)
{
u32 pa;
int high_apu = 0;
int channel, apu;
int i, size;
unsigned long flags;
u32 freq;
size = es->dma_size >> es->wav_shift;
if (es->fmt & ESS_FMT_STEREO)
high_apu++;
for (channel = 0; channel <= high_apu; channel++) {
apu = es->apu[channel];
snd_es1968_program_wavecache(chip, es, channel, es->memory->buf.addr, 0);
pa = es->memory->buf.addr;
pa -= chip->dma.addr;
pa >>= 1;
pa |= 0x00400000;
if (es->fmt & ESS_FMT_STEREO) {
if (channel)
pa |= 0x00800000;
if (es->fmt & ESS_FMT_16BIT)
pa >>= 1;
}
es->base[channel] = pa & 0xFFFF;
for (i = 0; i < 16; i++)
apu_set_register(chip, apu, i, 0x0000);
apu_set_register(chip, apu, 4, ((pa >> 16) & 0xFF) << 8);
apu_set_register(chip, apu, 5, pa & 0xFFFF);
apu_set_register(chip, apu, 6, (pa + size) & 0xFFFF);
apu_set_register(chip, apu, 7, size);
apu_set_register(chip, apu, 8, 0x0000);
apu_set_register(chip, apu, 9, 0xD000);
apu_set_register(chip, apu, 11, 0x0000);
apu_set_register(chip, apu, 0, 0x400F);
if (es->fmt & ESS_FMT_16BIT)
es->apu_mode[channel] = ESM_APU_16BITLINEAR;
else
es->apu_mode[channel] = ESM_APU_8BITLINEAR;
if (es->fmt & ESS_FMT_STEREO) {
apu_set_register(chip, apu, 10,
0x8F00 | (channel ? 0 : 0x10));
es->apu_mode[channel] += 1;
} else
apu_set_register(chip, apu, 10, 0x8F08);
}
spin_lock_irqsave(&chip->reg_lock, flags);
outw(1, chip->io_port + 0x04);
outw(inw(chip->io_port + ESM_PORT_HOST_IRQ) | ESM_HIRQ_DSIE, chip->io_port + ESM_PORT_HOST_IRQ);
spin_unlock_irqrestore(&chip->reg_lock, flags);
freq = runtime->rate;
if (freq > 48000)
freq = 48000;
if (freq < 4000)
freq = 4000;
if (!(es->fmt & ESS_FMT_16BIT) && !(es->fmt & ESS_FMT_STEREO))
freq >>= 1;
freq = snd_es1968_compute_rate(chip, freq);
snd_es1968_apu_set_freq(chip, es->apu[0], freq);
snd_es1968_apu_set_freq(chip, es->apu[1], freq);
}
static void init_capture_apu(struct es1968 *chip, struct esschan *es, int channel,
unsigned int pa, unsigned int bsize,
int mode, int route)
{
int i, apu = es->apu[channel];
es->apu_mode[channel] = mode;
snd_es1968_program_wavecache(chip, es, channel, pa, 1);
pa -= chip->dma.addr;
pa >>= 1;
es->base[channel] = pa & 0xFFFF;
pa |= 0x00400000;
for (i = 0; i < 16; i++)
apu_set_register(chip, apu, i, 0x0000);
apu_set_register(chip, apu, 2, 0x8);
apu_set_register(chip, apu, 4, ((pa >> 16) & 0xFF) << 8);
apu_set_register(chip, apu, 5, pa & 0xFFFF);
apu_set_register(chip, apu, 6, (pa + bsize) & 0xFFFF);
apu_set_register(chip, apu, 7, bsize);
apu_set_register(chip, apu, 8, 0x00F0);
apu_set_register(chip, apu, 9, 0x0000);
apu_set_register(chip, apu, 10, 0x8F08);
apu_set_register(chip, apu, 11, route);
apu_set_register(chip, apu, 0, 0x400F);
}
static void snd_es1968_capture_setup(struct es1968 *chip, struct esschan *es,
struct snd_pcm_runtime *runtime)
{
int size;
u32 freq;
unsigned long flags;
size = es->dma_size >> es->wav_shift;
init_capture_apu(chip, es, 2,
es->mixbuf->buf.addr, ESM_MIXBUF_SIZE/4,
ESM_APU_INPUTMIXER, 0x14);
init_capture_apu(chip, es, 0, es->memory->buf.addr, size,
ESM_APU_SRCONVERTOR, es->apu[2]);
if (es->fmt & ESS_FMT_STEREO) {
init_capture_apu(chip, es, 3,
es->mixbuf->buf.addr + ESM_MIXBUF_SIZE/2,
ESM_MIXBUF_SIZE/4,
ESM_APU_INPUTMIXER, 0x15);
init_capture_apu(chip, es, 1,
es->memory->buf.addr + size*2, size,
ESM_APU_SRCONVERTOR, es->apu[3]);
}
freq = runtime->rate;
if (freq > 47999)
freq = 47999;
if (freq < 4000)
freq = 4000;
freq = snd_es1968_compute_rate(chip, freq);
snd_es1968_apu_set_freq(chip, es->apu[0], freq);
snd_es1968_apu_set_freq(chip, es->apu[1], freq);
freq = 0x10000;
snd_es1968_apu_set_freq(chip, es->apu[2], freq);
snd_es1968_apu_set_freq(chip, es->apu[3], freq);
spin_lock_irqsave(&chip->reg_lock, flags);
outw(1, chip->io_port + 0x04);
outw(inw(chip->io_port + ESM_PORT_HOST_IRQ) | ESM_HIRQ_DSIE, chip->io_port + ESM_PORT_HOST_IRQ);
spin_unlock_irqrestore(&chip->reg_lock, flags);
}
static int snd_es1968_pcm_prepare(struct snd_pcm_substream *substream)
{
struct es1968 *chip = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
struct esschan *es = runtime->private_data;
es->dma_size = snd_pcm_lib_buffer_bytes(substream);
es->frag_size = snd_pcm_lib_period_bytes(substream);
es->wav_shift = 1;
es->fmt = 0;
if (snd_pcm_format_width(runtime->format) == 16)
es->fmt |= ESS_FMT_16BIT;
if (runtime->channels > 1) {
es->fmt |= ESS_FMT_STEREO;
if (es->fmt & ESS_FMT_16BIT)
es->wav_shift++;
}
es->bob_freq = snd_es1968_calc_bob_rate(chip, es, runtime);
switch (es->mode) {
case ESM_MODE_PLAY:
snd_es1968_playback_setup(chip, es, runtime);
break;
case ESM_MODE_CAPTURE:
snd_es1968_capture_setup(chip, es, runtime);
break;
}
return 0;
}
static int snd_es1968_pcm_trigger(struct snd_pcm_substream *substream, int cmd)
{
struct es1968 *chip = snd_pcm_substream_chip(substream);
struct esschan *es = substream->runtime->private_data;
spin_lock(&chip->substream_lock);
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
case SNDRV_PCM_TRIGGER_RESUME:
if (es->running)
break;
snd_es1968_bob_inc(chip, es->bob_freq);
es->count = 0;
es->hwptr = 0;
snd_es1968_pcm_start(chip, es);
es->running = 1;
break;
case SNDRV_PCM_TRIGGER_STOP:
case SNDRV_PCM_TRIGGER_SUSPEND:
if (! es->running)
break;
snd_es1968_pcm_stop(chip, es);
es->running = 0;
snd_es1968_bob_dec(chip);
break;
}
spin_unlock(&chip->substream_lock);
return 0;
}
static snd_pcm_uframes_t snd_es1968_pcm_pointer(struct snd_pcm_substream *substream)
{
struct es1968 *chip = snd_pcm_substream_chip(substream);
struct esschan *es = substream->runtime->private_data;
unsigned int ptr;
ptr = snd_es1968_get_dma_ptr(chip, es) << es->wav_shift;
return bytes_to_frames(substream->runtime, ptr % es->dma_size);
}
static int calc_available_memory_size(struct es1968 *chip)
{
int max_size = 0;
struct esm_memory *buf;
mutex_lock(&chip->memory_mutex);
list_for_each_entry(buf, &chip->buf_list, list) {
if (buf->empty && buf->buf.bytes > max_size)
max_size = buf->buf.bytes;
}
mutex_unlock(&chip->memory_mutex);
if (max_size >= 128*1024)
max_size = 127*1024;
return max_size;
}
static struct esm_memory *snd_es1968_new_memory(struct es1968 *chip, int size)
{
struct esm_memory *buf;
size = ALIGN(size, ESM_MEM_ALIGN);
mutex_lock(&chip->memory_mutex);
list_for_each_entry(buf, &chip->buf_list, list) {
if (buf->empty && buf->buf.bytes >= size)
goto __found;
}
mutex_unlock(&chip->memory_mutex);
return NULL;
__found:
if (buf->buf.bytes > size) {
struct esm_memory *chunk = kmalloc(sizeof(*chunk), GFP_KERNEL);
if (chunk == NULL) {
mutex_unlock(&chip->memory_mutex);
return NULL;
}
chunk->buf = buf->buf;
chunk->buf.bytes -= size;
chunk->buf.area += size;
chunk->buf.addr += size;
chunk->empty = 1;
buf->buf.bytes = size;
list_add(&chunk->list, &buf->list);
}
buf->empty = 0;
mutex_unlock(&chip->memory_mutex);
return buf;
}
static void snd_es1968_free_memory(struct es1968 *chip, struct esm_memory *buf)
{
struct esm_memory *chunk;
mutex_lock(&chip->memory_mutex);
buf->empty = 1;
if (buf->list.prev != &chip->buf_list) {
chunk = list_entry(buf->list.prev, struct esm_memory, list);
if (chunk->empty) {
chunk->buf.bytes += buf->buf.bytes;
list_del(&buf->list);
kfree(buf);
buf = chunk;
}
}
if (buf->list.next != &chip->buf_list) {
chunk = list_entry(buf->list.next, struct esm_memory, list);
if (chunk->empty) {
buf->buf.bytes += chunk->buf.bytes;
list_del(&chunk->list);
kfree(chunk);
}
}
mutex_unlock(&chip->memory_mutex);
}
static void snd_es1968_free_dmabuf(struct es1968 *chip)
{
struct list_head *p;
if (! chip->dma.area)
return;
snd_dma_reserve_buf(&chip->dma, snd_dma_pci_buf_id(chip->pci));
while ((p = chip->buf_list.next) != &chip->buf_list) {
struct esm_memory *chunk = list_entry(p, struct esm_memory, list);
list_del(p);
kfree(chunk);
}
}
static int __devinit
snd_es1968_init_dmabuf(struct es1968 *chip)
{
int err;
struct esm_memory *chunk;
chip->dma.dev.type = SNDRV_DMA_TYPE_DEV;
chip->dma.dev.dev = snd_dma_pci_data(chip->pci);
if (! snd_dma_get_reserved_buf(&chip->dma, snd_dma_pci_buf_id(chip->pci))) {
err = snd_dma_alloc_pages_fallback(SNDRV_DMA_TYPE_DEV,
snd_dma_pci_data(chip->pci),
chip->total_bufsize, &chip->dma);
if (err < 0 || ! chip->dma.area) {
snd_printk(KERN_ERR "es1968: can't allocate dma pages for size %d\n",
chip->total_bufsize);
return -ENOMEM;
}
if ((chip->dma.addr + chip->dma.bytes - 1) & ~((1 << 28) - 1)) {
snd_dma_free_pages(&chip->dma);
snd_printk(KERN_ERR "es1968: DMA buffer beyond 256MB.\n");
return -ENOMEM;
}
}
INIT_LIST_HEAD(&chip->buf_list);
chunk = kmalloc(sizeof(*chunk), GFP_KERNEL);
if (chunk == NULL) {
snd_es1968_free_dmabuf(chip);
return -ENOMEM;
}
memset(chip->dma.area, 0, ESM_MEM_ALIGN);
chunk->buf = chip->dma;
chunk->buf.area += ESM_MEM_ALIGN;
chunk->buf.addr += ESM_MEM_ALIGN;
chunk->buf.bytes -= ESM_MEM_ALIGN;
chunk->empty = 1;
list_add(&chunk->list, &chip->buf_list);
return 0;
}
static int snd_es1968_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *hw_params)
{
struct es1968 *chip = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
struct esschan *chan = runtime->private_data;
int size = params_buffer_bytes(hw_params);
if (chan->memory) {
if (chan->memory->buf.bytes >= size) {
runtime->dma_bytes = size;
return 0;
}
snd_es1968_free_memory(chip, chan->memory);
}
chan->memory = snd_es1968_new_memory(chip, size);
if (chan->memory == NULL) {
return -ENOMEM;
}
snd_pcm_set_runtime_buffer(substream, &chan->memory->buf);
return 1;
}
static int snd_es1968_hw_free(struct snd_pcm_substream *substream)
{
struct es1968 *chip = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
struct esschan *chan;
if (runtime->private_data == NULL)
return 0;
chan = runtime->private_data;
if (chan->memory) {
snd_es1968_free_memory(chip, chan->memory);
chan->memory = NULL;
}
return 0;
}
static int snd_es1968_alloc_apu_pair(struct es1968 *chip, int type)
{
int apu;
for (apu = 0; apu < NR_APUS; apu += 2) {
if (chip->apu[apu] == ESM_APU_FREE &&
chip->apu[apu + 1] == ESM_APU_FREE) {
chip->apu[apu] = chip->apu[apu + 1] = type;
return apu;
}
}
return -EBUSY;
}
static void snd_es1968_free_apu_pair(struct es1968 *chip, int apu)
{
chip->apu[apu] = chip->apu[apu + 1] = ESM_APU_FREE;
}
static int snd_es1968_playback_open(struct snd_pcm_substream *substream)
{
struct es1968 *chip = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
struct esschan *es;
int apu1;
apu1 = snd_es1968_alloc_apu_pair(chip, ESM_APU_PCM_PLAY);
if (apu1 < 0)
return apu1;
es = kzalloc(sizeof(*es), GFP_KERNEL);
if (!es) {
snd_es1968_free_apu_pair(chip, apu1);
return -ENOMEM;
}
es->apu[0] = apu1;
es->apu[1] = apu1 + 1;
es->apu_mode[0] = 0;
es->apu_mode[1] = 0;
es->running = 0;
es->substream = substream;
es->mode = ESM_MODE_PLAY;
runtime->private_data = es;
runtime->hw = snd_es1968_playback;
runtime->hw.buffer_bytes_max = runtime->hw.period_bytes_max =
calc_available_memory_size(chip);
spin_lock_irq(&chip->substream_lock);
list_add(&es->list, &chip->substream_list);
spin_unlock_irq(&chip->substream_lock);
return 0;
}
static int snd_es1968_capture_open(struct snd_pcm_substream *substream)
{
struct snd_pcm_runtime *runtime = substream->runtime;
struct es1968 *chip = snd_pcm_substream_chip(substream);
struct esschan *es;
int apu1, apu2;
apu1 = snd_es1968_alloc_apu_pair(chip, ESM_APU_PCM_CAPTURE);
if (apu1 < 0)
return apu1;
apu2 = snd_es1968_alloc_apu_pair(chip, ESM_APU_PCM_RATECONV);
if (apu2 < 0) {
snd_es1968_free_apu_pair(chip, apu1);
return apu2;
}
es = kzalloc(sizeof(*es), GFP_KERNEL);
if (!es) {
snd_es1968_free_apu_pair(chip, apu1);
snd_es1968_free_apu_pair(chip, apu2);
return -ENOMEM;
}
es->apu[0] = apu1;
es->apu[1] = apu1 + 1;
es->apu[2] = apu2;
es->apu[3] = apu2 + 1;
es->apu_mode[0] = 0;
es->apu_mode[1] = 0;
es->apu_mode[2] = 0;
es->apu_mode[3] = 0;
es->running = 0;
es->substream = substream;
es->mode = ESM_MODE_CAPTURE;
if ((es->mixbuf = snd_es1968_new_memory(chip, ESM_MIXBUF_SIZE)) == NULL) {
snd_es1968_free_apu_pair(chip, apu1);
snd_es1968_free_apu_pair(chip, apu2);
kfree(es);
return -ENOMEM;
}
memset(es->mixbuf->buf.area, 0, ESM_MIXBUF_SIZE);
runtime->private_data = es;
runtime->hw = snd_es1968_capture;
runtime->hw.buffer_bytes_max = runtime->hw.period_bytes_max =
calc_available_memory_size(chip) - 1024;
snd_pcm_hw_constraint_pow2(runtime, 0, SNDRV_PCM_HW_PARAM_BUFFER_BYTES);
spin_lock_irq(&chip->substream_lock);
list_add(&es->list, &chip->substream_list);
spin_unlock_irq(&chip->substream_lock);
return 0;
}
static int snd_es1968_playback_close(struct snd_pcm_substream *substream)
{
struct es1968 *chip = snd_pcm_substream_chip(substream);
struct esschan *es;
if (substream->runtime->private_data == NULL)
return 0;
es = substream->runtime->private_data;
spin_lock_irq(&chip->substream_lock);
list_del(&es->list);
spin_unlock_irq(&chip->substream_lock);
snd_es1968_free_apu_pair(chip, es->apu[0]);
kfree(es);
return 0;
}
static int snd_es1968_capture_close(struct snd_pcm_substream *substream)
{
struct es1968 *chip = snd_pcm_substream_chip(substream);
struct esschan *es;
if (substream->runtime->private_data == NULL)
return 0;
es = substream->runtime->private_data;
spin_lock_irq(&chip->substream_lock);
list_del(&es->list);
spin_unlock_irq(&chip->substream_lock);
snd_es1968_free_memory(chip, es->mixbuf);
snd_es1968_free_apu_pair(chip, es->apu[0]);
snd_es1968_free_apu_pair(chip, es->apu[2]);
kfree(es);
return 0;
}
static void __devinit es1968_measure_clock(struct es1968 *chip)
{
int i, apu;
unsigned int pa, offset, t;
struct esm_memory *memory;
struct timeval start_time, stop_time;
if (chip->clock == 0)
chip->clock = 48000;
if ((apu = snd_es1968_alloc_apu_pair(chip, ESM_APU_PCM_PLAY)) < 0) {
snd_printk(KERN_ERR "Hmm, cannot find empty APU pair!?\n");
return;
}
if ((memory = snd_es1968_new_memory(chip, CLOCK_MEASURE_BUFSIZE)) == NULL) {
snd_printk(KERN_ERR "cannot allocate dma buffer - using default clock %d\n", chip->clock);
snd_es1968_free_apu_pair(chip, apu);
return;
}
memset(memory->buf.area, 0, CLOCK_MEASURE_BUFSIZE);
wave_set_register(chip, apu << 3, (memory->buf.addr - 0x10) & 0xfff8);
pa = (unsigned int)((memory->buf.addr - chip->dma.addr) >> 1);
pa |= 0x00400000;
for (i = 0; i < 16; i++)
apu_set_register(chip, apu, i, 0x0000);
apu_set_register(chip, apu, 0, 0x400f);
apu_set_register(chip, apu, 4, ((pa >> 16) & 0xff) << 8);
apu_set_register(chip, apu, 5, pa & 0xffff);
apu_set_register(chip, apu, 6, (pa + CLOCK_MEASURE_BUFSIZE/2) & 0xffff);
apu_set_register(chip, apu, 7, CLOCK_MEASURE_BUFSIZE/2);
apu_set_register(chip, apu, 8, 0x0000);
apu_set_register(chip, apu, 9, 0xD000);
apu_set_register(chip, apu, 10, 0x8F08);
apu_set_register(chip, apu, 11, 0x0000);
spin_lock_irq(&chip->reg_lock);
outw(1, chip->io_port + 0x04);
outw(inw(chip->io_port + ESM_PORT_HOST_IRQ) | ESM_HIRQ_DSIE, chip->io_port + ESM_PORT_HOST_IRQ);
spin_unlock_irq(&chip->reg_lock);
snd_es1968_apu_set_freq(chip, apu, ((unsigned int)48000 << 16) / chip->clock);
chip->in_measurement = 1;
chip->measure_apu = apu;
spin_lock_irq(&chip->reg_lock);
snd_es1968_bob_inc(chip, ESM_BOB_FREQ);
__apu_set_register(chip, apu, 5, pa & 0xffff);
snd_es1968_trigger_apu(chip, apu, ESM_APU_16BITLINEAR);
do_gettimeofday(&start_time);
spin_unlock_irq(&chip->reg_lock);
msleep(50);
spin_lock_irq(&chip->reg_lock);
offset = __apu_get_register(chip, apu, 5);
do_gettimeofday(&stop_time);
snd_es1968_trigger_apu(chip, apu, 0);
snd_es1968_bob_dec(chip);
chip->in_measurement = 0;
spin_unlock_irq(&chip->reg_lock);
offset -= (pa & 0xffff);
offset &= 0xfffe;
offset += chip->measure_count * (CLOCK_MEASURE_BUFSIZE/2);
t = stop_time.tv_sec - start_time.tv_sec;
t *= 1000000;
if (stop_time.tv_usec < start_time.tv_usec)
t -= start_time.tv_usec - stop_time.tv_usec;
else
t += stop_time.tv_usec - start_time.tv_usec;
if (t == 0) {
snd_printk(KERN_ERR "?? calculation error..\n");
} else {
offset *= 1000;
offset = (offset / t) * 1000 + ((offset % t) * 1000) / t;
if (offset < 47500 || offset > 48500) {
if (offset >= 40000 && offset <= 50000)
chip->clock = (chip->clock * offset) / 48000;
}
printk(KERN_INFO "es1968: clocking to %d\n", chip->clock);
}
snd_es1968_free_memory(chip, memory);
snd_es1968_free_apu_pair(chip, apu);
}
static void snd_es1968_pcm_free(struct snd_pcm *pcm)
{
struct es1968 *esm = pcm->private_data;
snd_es1968_free_dmabuf(esm);
esm->pcm = NULL;
}
static int __devinit
snd_es1968_pcm(struct es1968 *chip, int device)
{
struct snd_pcm *pcm;
int err;
if ((err = snd_es1968_init_dmabuf(chip)) < 0)
return err;
wave_set_register(chip, 0x01FC, chip->dma.addr >> 12);
wave_set_register(chip, 0x01FD, chip->dma.addr >> 12);
wave_set_register(chip, 0x01FE, chip->dma.addr >> 12);
wave_set_register(chip, 0x01FF, chip->dma.addr >> 12);
if ((err = snd_pcm_new(chip->card, "ESS Maestro", device,
chip->playback_streams,
chip->capture_streams, &pcm)) < 0)
return err;
pcm->private_data = chip;
pcm->private_free = snd_es1968_pcm_free;
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_PLAYBACK, &snd_es1968_playback_ops);
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_CAPTURE, &snd_es1968_capture_ops);
pcm->info_flags = 0;
strcpy(pcm->name, "ESS Maestro");
chip->pcm = pcm;
return 0;
}
static void snd_es1968_suppress_jitter(struct es1968 *chip, struct esschan *es)
{
unsigned int cp1;
unsigned int cp2;
unsigned int diff;
cp1 = __apu_get_register(chip, 0, 5);
cp2 = __apu_get_register(chip, 1, 5);
diff = (cp1 > cp2 ? cp1 - cp2 : cp2 - cp1);
if (diff > 1)
__maestro_write(chip, IDR0_DATA_PORT, cp1);
}
static void snd_es1968_update_pcm(struct es1968 *chip, struct esschan *es)
{
unsigned int hwptr;
unsigned int diff;
struct snd_pcm_substream *subs = es->substream;
if (subs == NULL || !es->running)
return;
hwptr = snd_es1968_get_dma_ptr(chip, es) << es->wav_shift;
hwptr %= es->dma_size;
diff = (es->dma_size + hwptr - es->hwptr) % es->dma_size;
es->hwptr = hwptr;
es->count += diff;
if (es->count > es->frag_size) {
spin_unlock(&chip->substream_lock);
snd_pcm_period_elapsed(subs);
spin_lock(&chip->substream_lock);
es->count %= es->frag_size;
}
}
static void es1968_update_hw_volume(struct work_struct *work)
{
struct es1968 *chip = container_of(work, struct es1968, hwvol_work);
int x, val;
x = inb(chip->io_port + 0x1c) & 0xee;
outb(0x88, chip->io_port + 0x1c);
outb(0x88, chip->io_port + 0x1d);
outb(0x88, chip->io_port + 0x1e);
outb(0x88, chip->io_port + 0x1f);
if (chip->in_suspend)
return;
#ifndef CONFIG_SND_ES1968_INPUT
if (! chip->master_switch || ! chip->master_volume)
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
&chip->master_volume->id);
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
static irqreturn_t snd_es1968_interrupt(int irq, void *dev_id)
{
struct es1968 *chip = dev_id;
u32 event;
if (!(event = inb(chip->io_port + 0x1A)))
return IRQ_NONE;
outw(inw(chip->io_port + 4) & 1, chip->io_port + 4);
if (event & ESM_HWVOL_IRQ)
schedule_work(&chip->hwvol_work);
outb(0xFF, chip->io_port + 0x1A);
if ((event & ESM_MPU401_IRQ) && chip->rmidi) {
snd_mpu401_uart_interrupt(irq, chip->rmidi->private_data);
}
if (event & ESM_SOUND_IRQ) {
struct esschan *es;
spin_lock(&chip->substream_lock);
list_for_each_entry(es, &chip->substream_list, list) {
if (es->running) {
snd_es1968_update_pcm(chip, es);
if (es->fmt & ESS_FMT_STEREO)
snd_es1968_suppress_jitter(chip, es);
}
}
spin_unlock(&chip->substream_lock);
if (chip->in_measurement) {
unsigned int curp = __apu_get_register(chip, chip->measure_apu, 5);
if (curp < chip->measure_lastpos)
chip->measure_count++;
chip->measure_lastpos = curp;
}
}
return IRQ_HANDLED;
}
static int __devinit
snd_es1968_mixer(struct es1968 *chip)
{
struct snd_ac97_bus *pbus;
struct snd_ac97_template ac97;
#ifndef CONFIG_SND_ES1968_INPUT
struct snd_ctl_elem_id elem_id;
#endif
int err;
static struct snd_ac97_bus_ops ops = {
.write = snd_es1968_ac97_write,
.read = snd_es1968_ac97_read,
};
if ((err = snd_ac97_bus(chip->card, 0, &ops, NULL, &pbus)) < 0)
return err;
pbus->no_vra = 1;
memset(&ac97, 0, sizeof(ac97));
ac97.private_data = chip;
if ((err = snd_ac97_mixer(pbus, &ac97, &chip->ac97)) < 0)
return err;
#ifndef CONFIG_SND_ES1968_INPUT
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
static void snd_es1968_ac97_reset(struct es1968 *chip)
{
unsigned long ioaddr = chip->io_port;
unsigned short save_ringbus_a;
unsigned short save_68;
unsigned short w;
unsigned int vend;
save_ringbus_a = inw(ioaddr + 0x36);
outw(inw(ioaddr + 0x3a) & 0xfffc, ioaddr + 0x3a);
outw(inw(ioaddr + 0x3c) & 0xfffc, ioaddr + 0x3c);
outw(0x0000, ioaddr + 0x36);
save_68 = inw(ioaddr + 0x68);
pci_read_config_word(chip->pci, 0x58, &w);
pci_read_config_dword(chip->pci, PCI_SUBSYSTEM_VENDOR_ID, &vend);
if (w & 1)
save_68 |= 0x10;
outw(0xfffe, ioaddr + 0x64);
outw(0x0001, ioaddr + 0x68);
outw(0x0000, ioaddr + 0x60);
udelay(20);
outw(0x0001, ioaddr + 0x60);
msleep(20);
outw(save_68 | 0x1, ioaddr + 0x68);
outw((inw(ioaddr + 0x38) & 0xfffc) | 0x1, ioaddr + 0x38);
outw((inw(ioaddr + 0x3a) & 0xfffc) | 0x1, ioaddr + 0x3a);
outw((inw(ioaddr + 0x3c) & 0xfffc) | 0x1, ioaddr + 0x3c);
outw(0x0000, ioaddr + 0x36);
outw(0xfff7, ioaddr + 0x64);
save_68 = inw(ioaddr + 0x68);
outw(0x0009, ioaddr + 0x68);
outw(0x0001, ioaddr + 0x60);
udelay(20);
outw(0x0009, ioaddr + 0x60);
msleep(500);
outw(inw(ioaddr + 0x3a) & 0xfffc, ioaddr + 0x3a);
outw(inw(ioaddr + 0x3c) & 0xfffc, ioaddr + 0x3c);
#if 0
snd_printk(KERN_INFO "trying software reset\n");
outb(0x80 | 0x7c, ioaddr + 0x30);
for (w = 0;; w++) {
if ((inw(ioaddr + 0x30) & 1) == 0) {
if (inb(ioaddr + 0x32) != 0)
break;
outb(0x80 | 0x7d, ioaddr + 0x30);
if (((inw(ioaddr + 0x30) & 1) == 0)
&& (inb(ioaddr + 0x32) != 0))
break;
outb(0x80 | 0x7f, ioaddr + 0x30);
if (((inw(ioaddr + 0x30) & 1) == 0)
&& (inb(ioaddr + 0x32) != 0))
break;
}
if (w > 10000) {
outb(inb(ioaddr + 0x37) | 0x08, ioaddr + 0x37);
msleep(500);
outb(inb(ioaddr + 0x37) & ~0x08,
ioaddr + 0x37);
udelay(1);
outw(0x80, ioaddr + 0x30);
for (w = 0; w < 10000; w++) {
if ((inw(ioaddr + 0x30) & 1) == 0)
break;
}
}
}
#endif
if (vend == NEC_VERSA_SUBID1 || vend == NEC_VERSA_SUBID2) {
outw(0xf9ff, ioaddr + 0x64);
outw(inw(ioaddr + 0x68) | 0x600, ioaddr + 0x68);
outw(0x0209, ioaddr + 0x60);
}
outw(save_ringbus_a, ioaddr + 0x36);
outb(inb(ioaddr+0xc0)|(1<<5), ioaddr+0xc0);
outb(0xff, ioaddr+0xc3);
outb(0xff, ioaddr+0xc4);
outb(0xff, ioaddr+0xc6);
outb(0xff, ioaddr+0xc8);
outb(0x3f, ioaddr+0xcf);
outb(0x3f, ioaddr+0xd0);
}
static void snd_es1968_reset(struct es1968 *chip)
{
outw(ESM_RESET_MAESTRO | ESM_RESET_DIRECTSOUND,
chip->io_port + ESM_PORT_HOST_IRQ);
udelay(10);
outw(0x0000, chip->io_port + ESM_PORT_HOST_IRQ);
udelay(10);
}
static void snd_es1968_chip_init(struct es1968 *chip)
{
struct pci_dev *pci = chip->pci;
int i;
unsigned long iobase = chip->io_port;
u16 w;
u32 n;
pci_read_config_word(pci, ESM_CONFIG_A, &w);
w &= ~DMA_CLEAR;
w &= ~(PIC_SNOOP1 | PIC_SNOOP2);
w &= ~SAFEGUARD;
w |= POST_WRITE;
w |= PCI_TIMING;
w &= ~SWAP_LR;
w &= ~SUBTR_DECODE;
pci_write_config_word(pci, ESM_CONFIG_A, w);
pci_read_config_word(pci, ESM_CONFIG_B, &w);
w &= ~(1 << 15);
w &= ~(1 << 14);
w &= ~SPDIF_CONFB;
w |= HWV_CONFB;
w |= DEBOUNCE;
w &= ~GPIO_CONFB;
w |= CHI_CONFB;
w &= ~IDMA_CONFB;
w &= ~MIDI_FIX;
w &= ~(1 << 1);
w &= ~IRQ_TO_ISA;
pci_write_config_word(pci, ESM_CONFIG_B, w);
pci_read_config_word(pci, ESM_DDMA, &w);
w &= ~(1 << 0);
pci_write_config_word(pci, ESM_DDMA, w);
pci_read_config_word(pci, ESM_LEGACY_AUDIO_CONTROL, &w);
w |= ESS_DISABLE_AUDIO;
w &= ~ESS_ENABLE_SERIAL_IRQ;
w &= ~(0x1f);
pci_write_config_word(pci, ESM_LEGACY_AUDIO_CONTROL, w);
pci_read_config_word(pci, 0x58, &w);
w|=1<<2;
w|=1<<3;
w&=~(1<<11);
pci_write_config_word(pci, 0x58, w);
snd_es1968_reset(chip);
outw(0xC090, iobase + ESM_RING_BUS_DEST);
udelay(20);
outw(0x3000, iobase + ESM_RING_BUS_CONTR_A);
udelay(20);
snd_es1968_ac97_reset(chip);
n = inl(iobase + ESM_RING_BUS_CONTR_B);
n &= ~RINGB_EN_SPDIF;
outl(n, iobase + ESM_RING_BUS_CONTR_B);
outb(0x88, iobase+0x1c);
outb(0x88, iobase+0x1d);
outb(0x88, iobase+0x1e);
outb(0x88, iobase+0x1f);
outb(0, iobase + ASSP_CONTROL_B);
outb(3, iobase + ASSP_CONTROL_A);
outb(0, iobase + ASSP_CONTROL_C);
for (i = 0; i < 16; i++) {
outw(0x01E0 + i, iobase + WC_INDEX);
outw(0x0000, iobase + WC_DATA);
outw(0x01D0 + i, iobase + WC_INDEX);
outw(0x0000, iobase + WC_DATA);
}
wave_set_register(chip, IDR7_WAVE_ROMRAM,
(wave_get_register(chip, IDR7_WAVE_ROMRAM) & 0xFF00));
wave_set_register(chip, IDR7_WAVE_ROMRAM,
wave_get_register(chip, IDR7_WAVE_ROMRAM) | 0x100);
wave_set_register(chip, IDR7_WAVE_ROMRAM,
wave_get_register(chip, IDR7_WAVE_ROMRAM) & ~0x200);
wave_set_register(chip, IDR7_WAVE_ROMRAM,
wave_get_register(chip, IDR7_WAVE_ROMRAM) | ~0x400);
maestro_write(chip, IDR2_CRAM_DATA, 0x0000);
maestro_write(chip, 0x08, 0xB004);
maestro_write(chip, 0x09, 0x001B);
maestro_write(chip, 0x0A, 0x8000);
maestro_write(chip, 0x0B, 0x3F37);
maestro_write(chip, 0x0C, 0x0098);
maestro_write(chip, 0x0C,
(maestro_read(chip, 0x0C) & ~0xF000) | 0x8000);
maestro_write(chip, 0x0C,
(maestro_read(chip, 0x0C) & ~0x0F00) | 0x0500);
maestro_write(chip, 0x0D, 0x7632);
w = inw(iobase + WC_CONTROL);
w &= ~0xFA00;
w |= 0xA000;
w &= ~0x0200;
w |= 0x0100;
w |= 0x0080;
w &= ~0x0060;
w |= 0x0020;
w &= ~0x000C;
w &= ~0x0001;
outw(w, iobase + WC_CONTROL);
for (i = 0; i < NR_APUS; i++) {
for (w = 0; w < NR_APU_REGS; w++)
apu_set_register(chip, i, w, 0);
}
}
static void snd_es1968_start_irq(struct es1968 *chip)
{
unsigned short w;
w = ESM_HIRQ_DSIE | ESM_HIRQ_HW_VOLUME;
if (chip->rmidi)
w |= ESM_HIRQ_MPU401;
outb(w, chip->io_port + 0x1A);
outw(w, chip->io_port + ESM_PORT_HOST_IRQ);
}
static int es1968_suspend(struct pci_dev *pci, pm_message_t state)
{
struct snd_card *card = pci_get_drvdata(pci);
struct es1968 *chip = card->private_data;
if (! chip->do_pm)
return 0;
chip->in_suspend = 1;
cancel_work_sync(&chip->hwvol_work);
snd_power_change_state(card, SNDRV_CTL_POWER_D3hot);
snd_pcm_suspend_all(chip->pcm);
snd_ac97_suspend(chip->ac97);
snd_es1968_bob_stop(chip);
pci_disable_device(pci);
pci_save_state(pci);
pci_set_power_state(pci, pci_choose_state(pci, state));
return 0;
}
static int es1968_resume(struct pci_dev *pci)
{
struct snd_card *card = pci_get_drvdata(pci);
struct es1968 *chip = card->private_data;
struct esschan *es;
if (! chip->do_pm)
return 0;
pci_set_power_state(pci, PCI_D0);
pci_restore_state(pci);
if (pci_enable_device(pci) < 0) {
printk(KERN_ERR "es1968: pci_enable_device failed, "
"disabling device\n");
snd_card_disconnect(card);
return -EIO;
}
pci_set_master(pci);
snd_es1968_chip_init(chip);
if (chip->dma.addr) {
wave_set_register(chip, 0x01FC, chip->dma.addr >> 12);
}
snd_es1968_start_irq(chip);
snd_ac97_resume(chip->ac97);
list_for_each_entry(es, &chip->substream_list, list) {
switch (es->mode) {
case ESM_MODE_PLAY:
snd_es1968_playback_setup(chip, es, es->substream->runtime);
break;
case ESM_MODE_CAPTURE:
snd_es1968_capture_setup(chip, es, es->substream->runtime);
break;
}
}
if (chip->bobclient)
snd_es1968_bob_start(chip);
snd_power_change_state(card, SNDRV_CTL_POWER_D0);
chip->in_suspend = 0;
return 0;
}
static int __devinit snd_es1968_create_gameport(struct es1968 *chip, int dev)
{
struct gameport *gp;
struct resource *r;
u16 val;
if (!joystick[dev])
return -ENODEV;
r = request_region(JOYSTICK_ADDR, 8, "ES1968 gameport");
if (!r)
return -EBUSY;
chip->gameport = gp = gameport_allocate_port();
if (!gp) {
printk(KERN_ERR "es1968: cannot allocate memory for gameport\n");
release_and_free_resource(r);
return -ENOMEM;
}
pci_read_config_word(chip->pci, ESM_LEGACY_AUDIO_CONTROL, &val);
pci_write_config_word(chip->pci, ESM_LEGACY_AUDIO_CONTROL, val | 0x04);
gameport_set_name(gp, "ES1968 Gameport");
gameport_set_phys(gp, "pci%s/gameport0", pci_name(chip->pci));
gameport_set_dev_parent(gp, &chip->pci->dev);
gp->io = JOYSTICK_ADDR;
gameport_set_port_data(gp, r);
gameport_register_port(gp);
return 0;
}
static void snd_es1968_free_gameport(struct es1968 *chip)
{
if (chip->gameport) {
struct resource *r = gameport_get_port_data(chip->gameport);
gameport_unregister_port(chip->gameport);
chip->gameport = NULL;
release_and_free_resource(r);
}
}
static inline int snd_es1968_create_gameport(struct es1968 *chip, int dev) { return -ENOSYS; }
static inline void snd_es1968_free_gameport(struct es1968 *chip) { }
static int __devinit snd_es1968_input_register(struct es1968 *chip)
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
static void snd_es1968_tea575x_set_pins(struct snd_tea575x *tea, u8 pins)
{
struct es1968 *chip = tea->private_data;
unsigned long io = chip->io_port + GPIO_DATA;
u16 val = 0;
val |= (pins & TEA575X_DATA) ? STR_DATA : 0;
val |= (pins & TEA575X_CLK) ? STR_CLK : 0;
val |= (pins & TEA575X_WREN) ? STR_WREN : 0;
outw(val, io);
}
static u8 snd_es1968_tea575x_get_pins(struct snd_tea575x *tea)
{
struct es1968 *chip = tea->private_data;
unsigned long io = chip->io_port + GPIO_DATA;
u16 val = inw(io);
return (val & STR_DATA) ? TEA575X_DATA : 0 |
(val & STR_MOST) ? TEA575X_MOST : 0;
}
static void snd_es1968_tea575x_set_direction(struct snd_tea575x *tea, bool output)
{
struct es1968 *chip = tea->private_data;
unsigned long io = chip->io_port + GPIO_DATA;
u16 odir = inw(io + IO_DIR);
if (output) {
outw(~(STR_DATA | STR_CLK | STR_WREN), io + IO_MASK);
outw(odir | STR_DATA | STR_CLK | STR_WREN, io + IO_DIR);
} else {
outw(~(STR_CLK | STR_WREN | STR_DATA | STR_MOST), io + IO_MASK);
outw((odir & ~(STR_DATA | STR_MOST)) | STR_CLK | STR_WREN, io + IO_DIR);
}
}
static int snd_es1968_free(struct es1968 *chip)
{
cancel_work_sync(&chip->hwvol_work);
#ifdef CONFIG_SND_ES1968_INPUT
if (chip->input_dev)
input_unregister_device(chip->input_dev);
#endif
if (chip->io_port) {
if (chip->irq >= 0)
synchronize_irq(chip->irq);
outw(1, chip->io_port + 0x04);
outw(0, chip->io_port + ESM_PORT_HOST_IRQ);
}
#ifdef CONFIG_SND_ES1968_RADIO
snd_tea575x_exit(&chip->tea);
#endif
if (chip->irq >= 0)
free_irq(chip->irq, chip);
snd_es1968_free_gameport(chip);
pci_release_regions(chip->pci);
pci_disable_device(chip->pci);
kfree(chip);
return 0;
}
static int snd_es1968_dev_free(struct snd_device *device)
{
struct es1968 *chip = device->device_data;
return snd_es1968_free(chip);
}
static int __devinit snd_es1968_create(struct snd_card *card,
struct pci_dev *pci,
int total_bufsize,
int play_streams,
int capt_streams,
int chip_type,
int do_pm,
struct es1968 **chip_ret)
{
static struct snd_device_ops ops = {
.dev_free = snd_es1968_dev_free,
};
struct es1968 *chip;
int i, err;
*chip_ret = NULL;
if ((err = pci_enable_device(pci)) < 0)
return err;
if (pci_set_dma_mask(pci, DMA_BIT_MASK(28)) < 0 ||
pci_set_consistent_dma_mask(pci, DMA_BIT_MASK(28)) < 0) {
snd_printk(KERN_ERR "architecture does not support 28bit PCI busmaster DMA\n");
pci_disable_device(pci);
return -ENXIO;
}
chip = kzalloc(sizeof(*chip), GFP_KERNEL);
if (! chip) {
pci_disable_device(pci);
return -ENOMEM;
}
chip->type = chip_type;
spin_lock_init(&chip->reg_lock);
spin_lock_init(&chip->substream_lock);
INIT_LIST_HEAD(&chip->buf_list);
INIT_LIST_HEAD(&chip->substream_list);
mutex_init(&chip->memory_mutex);
INIT_WORK(&chip->hwvol_work, es1968_update_hw_volume);
chip->card = card;
chip->pci = pci;
chip->irq = -1;
chip->total_bufsize = total_bufsize;
chip->playback_streams = play_streams;
chip->capture_streams = capt_streams;
if ((err = pci_request_regions(pci, "ESS Maestro")) < 0) {
kfree(chip);
pci_disable_device(pci);
return err;
}
chip->io_port = pci_resource_start(pci, 0);
if (request_irq(pci->irq, snd_es1968_interrupt, IRQF_SHARED,
KBUILD_MODNAME, chip)) {
snd_printk(KERN_ERR "unable to grab IRQ %d\n", pci->irq);
snd_es1968_free(chip);
return -EBUSY;
}
chip->irq = pci->irq;
for (i = 0; i < 32; i++)
chip->maestro_map[i] = 0;
for (i = 0; i < NR_APUS; i++)
chip->apu[i] = ESM_APU_FREE;
pci_set_master(pci);
if (do_pm > 1) {
unsigned short vend;
pci_read_config_word(chip->pci, PCI_SUBSYSTEM_VENDOR_ID, &vend);
for (i = 0; i < (int)ARRAY_SIZE(pm_whitelist); i++) {
if (chip->type == pm_whitelist[i].type &&
vend == pm_whitelist[i].vendor) {
do_pm = 1;
break;
}
}
if (do_pm > 1) {
printk(KERN_INFO "es1968: not attempting power management.\n");
do_pm = 0;
}
}
chip->do_pm = do_pm;
snd_es1968_chip_init(chip);
if ((err = snd_device_new(card, SNDRV_DEV_LOWLEVEL, chip, &ops)) < 0) {
snd_es1968_free(chip);
return err;
}
snd_card_set_dev(card, &pci->dev);
#ifdef CONFIG_SND_ES1968_RADIO
chip->tea.private_data = chip;
chip->tea.ops = &snd_es1968_tea_ops;
strlcpy(chip->tea.card, "SF64-PCE2", sizeof(chip->tea.card));
sprintf(chip->tea.bus_info, "PCI:%s", pci_name(pci));
if (!snd_tea575x_init(&chip->tea))
printk(KERN_INFO "es1968: detected TEA575x radio\n");
#endif
*chip_ret = chip;
return 0;
}
static int __devinit snd_es1968_probe(struct pci_dev *pci,
const struct pci_device_id *pci_id)
{
static int dev;
struct snd_card *card;
struct es1968 *chip;
unsigned int i;
int err;
if (dev >= SNDRV_CARDS)
return -ENODEV;
if (!enable[dev]) {
dev++;
return -ENOENT;
}
err = snd_card_create(index[dev], id[dev], THIS_MODULE, 0, &card);
if (err < 0)
return err;
if (total_bufsize[dev] < 128)
total_bufsize[dev] = 128;
if (total_bufsize[dev] > 4096)
total_bufsize[dev] = 4096;
if ((err = snd_es1968_create(card, pci,
total_bufsize[dev] * 1024,
pcm_substreams_p[dev],
pcm_substreams_c[dev],
pci_id->driver_data,
use_pm[dev],
&chip)) < 0) {
snd_card_free(card);
return err;
}
card->private_data = chip;
switch (chip->type) {
case TYPE_MAESTRO2E:
strcpy(card->driver, "ES1978");
strcpy(card->shortname, "ESS ES1978 (Maestro 2E)");
break;
case TYPE_MAESTRO2:
strcpy(card->driver, "ES1968");
strcpy(card->shortname, "ESS ES1968 (Maestro 2)");
break;
case TYPE_MAESTRO:
strcpy(card->driver, "ESM1");
strcpy(card->shortname, "ESS Maestro 1");
break;
}
if ((err = snd_es1968_pcm(chip, 0)) < 0) {
snd_card_free(card);
return err;
}
if ((err = snd_es1968_mixer(chip)) < 0) {
snd_card_free(card);
return err;
}
if (enable_mpu[dev] == 2) {
unsigned short vend;
pci_read_config_word(chip->pci, PCI_SUBSYSTEM_VENDOR_ID, &vend);
for (i = 0; i < ARRAY_SIZE(mpu_blacklist); i++) {
if (chip->type == mpu_blacklist[i].type &&
vend == mpu_blacklist[i].vendor) {
enable_mpu[dev] = 0;
break;
}
}
}
if (enable_mpu[dev]) {
if ((err = snd_mpu401_uart_new(card, 0, MPU401_HW_MPU401,
chip->io_port + ESM_MPU401_PORT,
MPU401_INFO_INTEGRATED,
chip->irq, 0, &chip->rmidi)) < 0) {
printk(KERN_WARNING "es1968: skipping MPU-401 MIDI support..\n");
}
}
snd_es1968_create_gameport(chip, dev);
#ifdef CONFIG_SND_ES1968_INPUT
err = snd_es1968_input_register(chip);
if (err)
snd_printk(KERN_WARNING "Input device registration "
"failed with error %i", err);
#endif
snd_es1968_start_irq(chip);
chip->clock = clock[dev];
if (! chip->clock)
es1968_measure_clock(chip);
sprintf(card->longname, "%s at 0x%lx, irq %i",
card->shortname, chip->io_port, chip->irq);
if ((err = snd_card_register(card)) < 0) {
snd_card_free(card);
return err;
}
pci_set_drvdata(pci, card);
dev++;
return 0;
}
static void __devexit snd_es1968_remove(struct pci_dev *pci)
{
snd_card_free(pci_get_drvdata(pci));
pci_set_drvdata(pci, NULL);
}
static int __init alsa_card_es1968_init(void)
{
return pci_register_driver(&driver);
}
static void __exit alsa_card_es1968_exit(void)
{
pci_unregister_driver(&driver);
}
