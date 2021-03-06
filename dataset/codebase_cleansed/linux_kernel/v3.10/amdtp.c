int amdtp_out_stream_init(struct amdtp_out_stream *s, struct fw_unit *unit,
enum cip_out_flags flags)
{
if (flags != CIP_NONBLOCKING)
return -EINVAL;
s->unit = fw_unit_get(unit);
s->flags = flags;
s->context = ERR_PTR(-1);
mutex_init(&s->mutex);
tasklet_init(&s->period_tasklet, pcm_period_tasklet, (unsigned long)s);
s->packet_index = 0;
return 0;
}
void amdtp_out_stream_destroy(struct amdtp_out_stream *s)
{
WARN_ON(!IS_ERR(s->context));
mutex_destroy(&s->mutex);
fw_unit_put(s->unit);
}
void amdtp_out_stream_set_rate(struct amdtp_out_stream *s, unsigned int rate)
{
static const struct {
unsigned int rate;
unsigned int syt_interval;
} rate_info[] = {
[CIP_SFC_32000] = { 32000, 8, },
[CIP_SFC_44100] = { 44100, 8, },
[CIP_SFC_48000] = { 48000, 8, },
[CIP_SFC_88200] = { 88200, 16, },
[CIP_SFC_96000] = { 96000, 16, },
[CIP_SFC_176400] = { 176400, 32, },
[CIP_SFC_192000] = { 192000, 32, },
};
unsigned int sfc;
if (WARN_ON(!IS_ERR(s->context)))
return;
for (sfc = 0; sfc < ARRAY_SIZE(rate_info); ++sfc)
if (rate_info[sfc].rate == rate) {
s->sfc = sfc;
s->syt_interval = rate_info[sfc].syt_interval;
return;
}
WARN_ON(1);
}
unsigned int amdtp_out_stream_get_max_payload(struct amdtp_out_stream *s)
{
static const unsigned int max_data_blocks[] = {
[CIP_SFC_32000] = 4,
[CIP_SFC_44100] = 6,
[CIP_SFC_48000] = 6,
[CIP_SFC_88200] = 12,
[CIP_SFC_96000] = 12,
[CIP_SFC_176400] = 23,
[CIP_SFC_192000] = 24,
};
s->data_block_quadlets = s->pcm_channels;
s->data_block_quadlets += DIV_ROUND_UP(s->midi_ports, 8);
return 8 + max_data_blocks[s->sfc] * 4 * s->data_block_quadlets;
}
void amdtp_out_stream_set_pcm_format(struct amdtp_out_stream *s,
snd_pcm_format_t format)
{
if (WARN_ON(!IS_ERR(s->context)))
return;
switch (format) {
default:
WARN_ON(1);
case SNDRV_PCM_FORMAT_S16:
s->transfer_samples = amdtp_write_s16;
break;
case SNDRV_PCM_FORMAT_S32:
s->transfer_samples = amdtp_write_s32;
break;
}
}
void amdtp_out_stream_pcm_prepare(struct amdtp_out_stream *s)
{
tasklet_kill(&s->period_tasklet);
s->pcm_buffer_pointer = 0;
s->pcm_period_pointer = 0;
s->pointer_flush = true;
}
static unsigned int calculate_data_blocks(struct amdtp_out_stream *s)
{
unsigned int phase, data_blocks;
if (!cip_sfc_is_base_44100(s->sfc)) {
data_blocks = s->data_block_state;
} else {
phase = s->data_block_state;
if (s->sfc == CIP_SFC_44100)
data_blocks = 5 + ((phase & 1) ^
(phase == 0 || phase >= 40));
else
data_blocks = 11 * (s->sfc >> 1) + (phase == 0);
if (++phase >= (80 >> (s->sfc >> 1)))
phase = 0;
s->data_block_state = phase;
}
return data_blocks;
}
static unsigned int calculate_syt(struct amdtp_out_stream *s,
unsigned int cycle)
{
unsigned int syt_offset, phase, index, syt;
if (s->last_syt_offset < TICKS_PER_CYCLE) {
if (!cip_sfc_is_base_44100(s->sfc))
syt_offset = s->last_syt_offset + s->syt_offset_state;
else {
phase = s->syt_offset_state;
index = phase % 13;
syt_offset = s->last_syt_offset;
syt_offset += 1386 + ((index && !(index & 3)) ||
phase == 146);
if (++phase >= 147)
phase = 0;
s->syt_offset_state = phase;
}
} else
syt_offset = s->last_syt_offset - TICKS_PER_CYCLE;
s->last_syt_offset = syt_offset;
if (syt_offset < TICKS_PER_CYCLE) {
syt_offset += TRANSFER_DELAY_TICKS - TICKS_PER_CYCLE;
syt = (cycle + syt_offset / TICKS_PER_CYCLE) << 12;
syt += syt_offset % TICKS_PER_CYCLE;
return syt & 0xffff;
} else {
return 0xffff;
}
}
static void amdtp_write_s32(struct amdtp_out_stream *s,
struct snd_pcm_substream *pcm,
__be32 *buffer, unsigned int frames)
{
struct snd_pcm_runtime *runtime = pcm->runtime;
unsigned int channels, remaining_frames, frame_step, i, c;
const u32 *src;
channels = s->pcm_channels;
src = (void *)runtime->dma_area +
s->pcm_buffer_pointer * (runtime->frame_bits / 8);
remaining_frames = runtime->buffer_size - s->pcm_buffer_pointer;
frame_step = s->data_block_quadlets - channels;
for (i = 0; i < frames; ++i) {
for (c = 0; c < channels; ++c) {
*buffer = cpu_to_be32((*src >> 8) | 0x40000000);
src++;
buffer++;
}
buffer += frame_step;
if (--remaining_frames == 0)
src = (void *)runtime->dma_area;
}
}
static void amdtp_write_s16(struct amdtp_out_stream *s,
struct snd_pcm_substream *pcm,
__be32 *buffer, unsigned int frames)
{
struct snd_pcm_runtime *runtime = pcm->runtime;
unsigned int channels, remaining_frames, frame_step, i, c;
const u16 *src;
channels = s->pcm_channels;
src = (void *)runtime->dma_area +
s->pcm_buffer_pointer * (runtime->frame_bits / 8);
remaining_frames = runtime->buffer_size - s->pcm_buffer_pointer;
frame_step = s->data_block_quadlets - channels;
for (i = 0; i < frames; ++i) {
for (c = 0; c < channels; ++c) {
*buffer = cpu_to_be32((*src << 8) | 0x40000000);
src++;
buffer++;
}
buffer += frame_step;
if (--remaining_frames == 0)
src = (void *)runtime->dma_area;
}
}
static void amdtp_fill_pcm_silence(struct amdtp_out_stream *s,
__be32 *buffer, unsigned int frames)
{
unsigned int i, c;
for (i = 0; i < frames; ++i) {
for (c = 0; c < s->pcm_channels; ++c)
buffer[c] = cpu_to_be32(0x40000000);
buffer += s->data_block_quadlets;
}
}
static void amdtp_fill_midi(struct amdtp_out_stream *s,
__be32 *buffer, unsigned int frames)
{
unsigned int i;
for (i = 0; i < frames; ++i)
buffer[s->pcm_channels + i * s->data_block_quadlets] =
cpu_to_be32(0x80000000);
}
static void queue_out_packet(struct amdtp_out_stream *s, unsigned int cycle)
{
__be32 *buffer;
unsigned int index, data_blocks, syt, ptr;
struct snd_pcm_substream *pcm;
struct fw_iso_packet packet;
int err;
if (s->packet_index < 0)
return;
index = s->packet_index;
data_blocks = calculate_data_blocks(s);
syt = calculate_syt(s, cycle);
buffer = s->buffer.packets[index].buffer;
buffer[0] = cpu_to_be32(ACCESS_ONCE(s->source_node_id_field) |
(s->data_block_quadlets << 16) |
s->data_block_counter);
buffer[1] = cpu_to_be32(CIP_EOH | CIP_FMT_AM | AMDTP_FDF_AM824 |
(s->sfc << AMDTP_FDF_SFC_SHIFT) | syt);
buffer += 2;
pcm = ACCESS_ONCE(s->pcm);
if (pcm)
s->transfer_samples(s, pcm, buffer, data_blocks);
else
amdtp_fill_pcm_silence(s, buffer, data_blocks);
if (s->midi_ports)
amdtp_fill_midi(s, buffer, data_blocks);
s->data_block_counter = (s->data_block_counter + data_blocks) & 0xff;
packet.payload_length = 8 + data_blocks * 4 * s->data_block_quadlets;
packet.interrupt = IS_ALIGNED(index + 1, INTERRUPT_INTERVAL);
packet.skip = 0;
packet.tag = TAG_CIP;
packet.sy = 0;
packet.header_length = 0;
err = fw_iso_context_queue(s->context, &packet, &s->buffer.iso_buffer,
s->buffer.packets[index].offset);
if (err < 0) {
dev_err(&s->unit->device, "queueing error: %d\n", err);
s->packet_index = -1;
amdtp_out_stream_pcm_abort(s);
return;
}
if (++index >= QUEUE_LENGTH)
index = 0;
s->packet_index = index;
if (pcm) {
ptr = s->pcm_buffer_pointer + data_blocks;
if (ptr >= pcm->runtime->buffer_size)
ptr -= pcm->runtime->buffer_size;
ACCESS_ONCE(s->pcm_buffer_pointer) = ptr;
s->pcm_period_pointer += data_blocks;
if (s->pcm_period_pointer >= pcm->runtime->period_size) {
s->pcm_period_pointer -= pcm->runtime->period_size;
s->pointer_flush = false;
tasklet_hi_schedule(&s->period_tasklet);
}
}
}
static void pcm_period_tasklet(unsigned long data)
{
struct amdtp_out_stream *s = (void *)data;
struct snd_pcm_substream *pcm = ACCESS_ONCE(s->pcm);
if (pcm)
snd_pcm_period_elapsed(pcm);
}
static void out_packet_callback(struct fw_iso_context *context, u32 cycle,
size_t header_length, void *header, void *data)
{
struct amdtp_out_stream *s = data;
unsigned int i, packets = header_length / 4;
cycle += QUEUE_LENGTH - packets;
for (i = 0; i < packets; ++i)
queue_out_packet(s, ++cycle);
fw_iso_context_queue_flush(s->context);
}
static int queue_initial_skip_packets(struct amdtp_out_stream *s)
{
struct fw_iso_packet skip_packet = {
.skip = 1,
};
unsigned int i;
int err;
for (i = 0; i < QUEUE_LENGTH; ++i) {
skip_packet.interrupt = IS_ALIGNED(s->packet_index + 1,
INTERRUPT_INTERVAL);
err = fw_iso_context_queue(s->context, &skip_packet, NULL, 0);
if (err < 0)
return err;
if (++s->packet_index >= QUEUE_LENGTH)
s->packet_index = 0;
}
return 0;
}
int amdtp_out_stream_start(struct amdtp_out_stream *s, int channel, int speed)
{
static const struct {
unsigned int data_block;
unsigned int syt_offset;
} initial_state[] = {
[CIP_SFC_32000] = { 4, 3072 },
[CIP_SFC_48000] = { 6, 1024 },
[CIP_SFC_96000] = { 12, 1024 },
[CIP_SFC_192000] = { 24, 1024 },
[CIP_SFC_44100] = { 0, 67 },
[CIP_SFC_88200] = { 0, 67 },
[CIP_SFC_176400] = { 0, 67 },
};
int err;
mutex_lock(&s->mutex);
if (WARN_ON(!IS_ERR(s->context) ||
(!s->pcm_channels && !s->midi_ports))) {
err = -EBADFD;
goto err_unlock;
}
s->data_block_state = initial_state[s->sfc].data_block;
s->syt_offset_state = initial_state[s->sfc].syt_offset;
s->last_syt_offset = TICKS_PER_CYCLE;
err = iso_packets_buffer_init(&s->buffer, s->unit, QUEUE_LENGTH,
amdtp_out_stream_get_max_payload(s),
DMA_TO_DEVICE);
if (err < 0)
goto err_unlock;
s->context = fw_iso_context_create(fw_parent_device(s->unit)->card,
FW_ISO_CONTEXT_TRANSMIT,
channel, speed, 0,
out_packet_callback, s);
if (IS_ERR(s->context)) {
err = PTR_ERR(s->context);
if (err == -EBUSY)
dev_err(&s->unit->device,
"no free output stream on this controller\n");
goto err_buffer;
}
amdtp_out_stream_update(s);
s->packet_index = 0;
s->data_block_counter = 0;
err = queue_initial_skip_packets(s);
if (err < 0)
goto err_context;
err = fw_iso_context_start(s->context, -1, 0, 0);
if (err < 0)
goto err_context;
mutex_unlock(&s->mutex);
return 0;
err_context:
fw_iso_context_destroy(s->context);
s->context = ERR_PTR(-1);
err_buffer:
iso_packets_buffer_destroy(&s->buffer, s->unit);
err_unlock:
mutex_unlock(&s->mutex);
return err;
}
unsigned long amdtp_out_stream_pcm_pointer(struct amdtp_out_stream *s)
{
if (s->pointer_flush)
fw_iso_context_flush_completions(s->context);
else
s->pointer_flush = true;
return ACCESS_ONCE(s->pcm_buffer_pointer);
}
void amdtp_out_stream_update(struct amdtp_out_stream *s)
{
ACCESS_ONCE(s->source_node_id_field) =
(fw_parent_device(s->unit)->card->node_id & 0x3f) << 24;
}
void amdtp_out_stream_stop(struct amdtp_out_stream *s)
{
mutex_lock(&s->mutex);
if (IS_ERR(s->context)) {
mutex_unlock(&s->mutex);
return;
}
tasklet_kill(&s->period_tasklet);
fw_iso_context_stop(s->context);
fw_iso_context_destroy(s->context);
s->context = ERR_PTR(-1);
iso_packets_buffer_destroy(&s->buffer, s->unit);
mutex_unlock(&s->mutex);
}
void amdtp_out_stream_pcm_abort(struct amdtp_out_stream *s)
{
struct snd_pcm_substream *pcm;
pcm = ACCESS_ONCE(s->pcm);
if (pcm) {
snd_pcm_stream_lock_irq(pcm);
if (snd_pcm_running(pcm))
snd_pcm_stop(pcm, SNDRV_PCM_STATE_XRUN);
snd_pcm_stream_unlock_irq(pcm);
}
}
