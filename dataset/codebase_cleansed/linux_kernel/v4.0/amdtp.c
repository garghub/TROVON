int amdtp_stream_init(struct amdtp_stream *s, struct fw_unit *unit,
enum amdtp_stream_direction dir, enum cip_flags flags)
{
s->unit = unit;
s->direction = dir;
s->flags = flags;
s->context = ERR_PTR(-1);
mutex_init(&s->mutex);
tasklet_init(&s->period_tasklet, pcm_period_tasklet, (unsigned long)s);
s->packet_index = 0;
init_waitqueue_head(&s->callback_wait);
s->callbacked = false;
s->sync_slave = NULL;
return 0;
}
void amdtp_stream_destroy(struct amdtp_stream *s)
{
WARN_ON(amdtp_stream_running(s));
mutex_destroy(&s->mutex);
}
int amdtp_stream_add_pcm_hw_constraints(struct amdtp_stream *s,
struct snd_pcm_runtime *runtime)
{
int err;
err = snd_pcm_hw_constraint_msbits(runtime, 0, 32, 24);
if (err < 0)
goto end;
err = snd_pcm_hw_constraint_minmax(runtime,
SNDRV_PCM_HW_PARAM_PERIOD_TIME,
5000, UINT_MAX);
if (err < 0)
goto end;
if (!(s->flags & CIP_BLOCKING))
goto end;
err = snd_pcm_hw_constraint_step(runtime, 0,
SNDRV_PCM_HW_PARAM_PERIOD_SIZE, 32);
if (err < 0)
goto end;
err = snd_pcm_hw_constraint_step(runtime, 0,
SNDRV_PCM_HW_PARAM_BUFFER_SIZE, 32);
end:
return err;
}
void amdtp_stream_set_parameters(struct amdtp_stream *s,
unsigned int rate,
unsigned int pcm_channels,
unsigned int midi_ports)
{
unsigned int i, sfc, midi_channels;
midi_channels = DIV_ROUND_UP(midi_ports, 8);
if (WARN_ON(amdtp_stream_running(s)) |
WARN_ON(pcm_channels > AMDTP_MAX_CHANNELS_FOR_PCM) |
WARN_ON(midi_channels > AMDTP_MAX_CHANNELS_FOR_MIDI))
return;
for (sfc = 0; sfc < ARRAY_SIZE(amdtp_rate_table); ++sfc)
if (amdtp_rate_table[sfc] == rate)
goto sfc_found;
WARN_ON(1);
return;
sfc_found:
s->pcm_channels = pcm_channels;
s->sfc = sfc;
s->data_block_quadlets = s->pcm_channels + midi_channels;
s->midi_ports = midi_ports;
s->syt_interval = amdtp_syt_intervals[sfc];
s->transfer_delay = TRANSFER_DELAY_TICKS - TICKS_PER_CYCLE;
if (s->flags & CIP_BLOCKING)
s->transfer_delay += TICKS_PER_SECOND * s->syt_interval / rate;
for (i = 0; i < pcm_channels; i++)
s->pcm_positions[i] = i;
s->midi_position = s->pcm_channels;
s->midi_fifo_limit = rate - MIDI_BYTES_PER_SECOND * s->syt_interval + 1;
}
unsigned int amdtp_stream_get_max_payload(struct amdtp_stream *s)
{
return 8 + s->syt_interval * s->data_block_quadlets * 4;
}
void amdtp_stream_set_pcm_format(struct amdtp_stream *s,
snd_pcm_format_t format)
{
if (WARN_ON(amdtp_stream_pcm_running(s)))
return;
switch (format) {
default:
WARN_ON(1);
case SNDRV_PCM_FORMAT_S16:
if (s->direction == AMDTP_OUT_STREAM) {
s->transfer_samples = amdtp_write_s16;
break;
}
WARN_ON(1);
case SNDRV_PCM_FORMAT_S32:
if (s->direction == AMDTP_OUT_STREAM)
s->transfer_samples = amdtp_write_s32;
else
s->transfer_samples = amdtp_read_s32;
break;
}
}
void amdtp_stream_pcm_prepare(struct amdtp_stream *s)
{
tasklet_kill(&s->period_tasklet);
s->pcm_buffer_pointer = 0;
s->pcm_period_pointer = 0;
s->pointer_flush = true;
}
static unsigned int calculate_data_blocks(struct amdtp_stream *s)
{
unsigned int phase, data_blocks;
if (s->flags & CIP_BLOCKING)
data_blocks = s->syt_interval;
else if (!cip_sfc_is_base_44100(s->sfc)) {
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
static unsigned int calculate_syt(struct amdtp_stream *s,
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
syt_offset += s->transfer_delay;
syt = (cycle + syt_offset / TICKS_PER_CYCLE) << 12;
syt += syt_offset % TICKS_PER_CYCLE;
return syt & CIP_SYT_MASK;
} else {
return CIP_SYT_NO_INFO;
}
}
static void amdtp_write_s32(struct amdtp_stream *s,
struct snd_pcm_substream *pcm,
__be32 *buffer, unsigned int frames)
{
struct snd_pcm_runtime *runtime = pcm->runtime;
unsigned int channels, remaining_frames, i, c;
const u32 *src;
channels = s->pcm_channels;
src = (void *)runtime->dma_area +
frames_to_bytes(runtime, s->pcm_buffer_pointer);
remaining_frames = runtime->buffer_size - s->pcm_buffer_pointer;
for (i = 0; i < frames; ++i) {
for (c = 0; c < channels; ++c) {
buffer[s->pcm_positions[c]] =
cpu_to_be32((*src >> 8) | 0x40000000);
src++;
}
buffer += s->data_block_quadlets;
if (--remaining_frames == 0)
src = (void *)runtime->dma_area;
}
}
static void amdtp_write_s16(struct amdtp_stream *s,
struct snd_pcm_substream *pcm,
__be32 *buffer, unsigned int frames)
{
struct snd_pcm_runtime *runtime = pcm->runtime;
unsigned int channels, remaining_frames, i, c;
const u16 *src;
channels = s->pcm_channels;
src = (void *)runtime->dma_area +
frames_to_bytes(runtime, s->pcm_buffer_pointer);
remaining_frames = runtime->buffer_size - s->pcm_buffer_pointer;
for (i = 0; i < frames; ++i) {
for (c = 0; c < channels; ++c) {
buffer[s->pcm_positions[c]] =
cpu_to_be32((*src << 8) | 0x42000000);
src++;
}
buffer += s->data_block_quadlets;
if (--remaining_frames == 0)
src = (void *)runtime->dma_area;
}
}
static void amdtp_read_s32(struct amdtp_stream *s,
struct snd_pcm_substream *pcm,
__be32 *buffer, unsigned int frames)
{
struct snd_pcm_runtime *runtime = pcm->runtime;
unsigned int channels, remaining_frames, i, c;
u32 *dst;
channels = s->pcm_channels;
dst = (void *)runtime->dma_area +
frames_to_bytes(runtime, s->pcm_buffer_pointer);
remaining_frames = runtime->buffer_size - s->pcm_buffer_pointer;
for (i = 0; i < frames; ++i) {
for (c = 0; c < channels; ++c) {
*dst = be32_to_cpu(buffer[s->pcm_positions[c]]) << 8;
dst++;
}
buffer += s->data_block_quadlets;
if (--remaining_frames == 0)
dst = (void *)runtime->dma_area;
}
}
static void amdtp_fill_pcm_silence(struct amdtp_stream *s,
__be32 *buffer, unsigned int frames)
{
unsigned int i, c;
for (i = 0; i < frames; ++i) {
for (c = 0; c < s->pcm_channels; ++c)
buffer[s->pcm_positions[c]] = cpu_to_be32(0x40000000);
buffer += s->data_block_quadlets;
}
}
static bool midi_ratelimit_per_packet(struct amdtp_stream *s, unsigned int port)
{
int used;
used = s->midi_fifo_used[port];
if (used == 0)
return true;
used -= MIDI_BYTES_PER_SECOND * s->syt_interval;
used = max(used, 0);
s->midi_fifo_used[port] = used;
return used < s->midi_fifo_limit;
}
static void midi_rate_use_one_byte(struct amdtp_stream *s, unsigned int port)
{
s->midi_fifo_used[port] += amdtp_rate_table[s->sfc];
}
static void amdtp_fill_midi(struct amdtp_stream *s,
__be32 *buffer, unsigned int frames)
{
unsigned int f, port;
u8 *b;
for (f = 0; f < frames; f++) {
b = (u8 *)&buffer[s->midi_position];
port = (s->data_block_counter + f) % 8;
if (f < MAX_MIDI_RX_BLOCKS &&
midi_ratelimit_per_packet(s, port) &&
s->midi[port] != NULL &&
snd_rawmidi_transmit(s->midi[port], &b[1], 1) == 1) {
midi_rate_use_one_byte(s, port);
b[0] = 0x81;
} else {
b[0] = 0x80;
b[1] = 0;
}
b[2] = 0;
b[3] = 0;
buffer += s->data_block_quadlets;
}
}
static void amdtp_pull_midi(struct amdtp_stream *s,
__be32 *buffer, unsigned int frames)
{
unsigned int f, port;
int len;
u8 *b;
for (f = 0; f < frames; f++) {
port = (s->data_block_counter + f) % 8;
b = (u8 *)&buffer[s->midi_position];
len = b[0] - 0x80;
if ((1 <= len) && (len <= 3) && (s->midi[port]))
snd_rawmidi_receive(s->midi[port], b + 1, len);
buffer += s->data_block_quadlets;
}
}
static void update_pcm_pointers(struct amdtp_stream *s,
struct snd_pcm_substream *pcm,
unsigned int frames)
{
unsigned int ptr;
if (s->double_pcm_frames)
frames *= 2;
ptr = s->pcm_buffer_pointer + frames;
if (ptr >= pcm->runtime->buffer_size)
ptr -= pcm->runtime->buffer_size;
ACCESS_ONCE(s->pcm_buffer_pointer) = ptr;
s->pcm_period_pointer += frames;
if (s->pcm_period_pointer >= pcm->runtime->period_size) {
s->pcm_period_pointer -= pcm->runtime->period_size;
s->pointer_flush = false;
tasklet_hi_schedule(&s->period_tasklet);
}
}
static void pcm_period_tasklet(unsigned long data)
{
struct amdtp_stream *s = (void *)data;
struct snd_pcm_substream *pcm = ACCESS_ONCE(s->pcm);
if (pcm)
snd_pcm_period_elapsed(pcm);
}
static int queue_packet(struct amdtp_stream *s,
unsigned int header_length,
unsigned int payload_length, bool skip)
{
struct fw_iso_packet p = {0};
int err = 0;
if (IS_ERR(s->context))
goto end;
p.interrupt = IS_ALIGNED(s->packet_index + 1, INTERRUPT_INTERVAL);
p.tag = TAG_CIP;
p.header_length = header_length;
p.payload_length = (!skip) ? payload_length : 0;
p.skip = skip;
err = fw_iso_context_queue(s->context, &p, &s->buffer.iso_buffer,
s->buffer.packets[s->packet_index].offset);
if (err < 0) {
dev_err(&s->unit->device, "queueing error: %d\n", err);
goto end;
}
if (++s->packet_index >= QUEUE_LENGTH)
s->packet_index = 0;
end:
return err;
}
static inline int queue_out_packet(struct amdtp_stream *s,
unsigned int payload_length, bool skip)
{
return queue_packet(s, OUT_PACKET_HEADER_SIZE,
payload_length, skip);
}
static inline int queue_in_packet(struct amdtp_stream *s)
{
return queue_packet(s, IN_PACKET_HEADER_SIZE,
amdtp_stream_get_max_payload(s), false);
}
static void handle_out_packet(struct amdtp_stream *s, unsigned int syt)
{
__be32 *buffer;
unsigned int data_blocks, payload_length;
struct snd_pcm_substream *pcm;
if (s->packet_index < 0)
return;
if (!(s->flags & CIP_BLOCKING) || (syt != CIP_SYT_NO_INFO))
data_blocks = calculate_data_blocks(s);
else
data_blocks = 0;
buffer = s->buffer.packets[s->packet_index].buffer;
buffer[0] = cpu_to_be32(ACCESS_ONCE(s->source_node_id_field) |
(s->data_block_quadlets << AMDTP_DBS_SHIFT) |
s->data_block_counter);
buffer[1] = cpu_to_be32(CIP_EOH | CIP_FMT_AM | AMDTP_FDF_AM824 |
(s->sfc << CIP_FDF_SFC_SHIFT) | syt);
buffer += 2;
pcm = ACCESS_ONCE(s->pcm);
if (pcm)
s->transfer_samples(s, pcm, buffer, data_blocks);
else
amdtp_fill_pcm_silence(s, buffer, data_blocks);
if (s->midi_ports)
amdtp_fill_midi(s, buffer, data_blocks);
s->data_block_counter = (s->data_block_counter + data_blocks) & 0xff;
payload_length = 8 + data_blocks * 4 * s->data_block_quadlets;
if (queue_out_packet(s, payload_length, false) < 0) {
s->packet_index = -1;
amdtp_stream_pcm_abort(s);
return;
}
if (pcm)
update_pcm_pointers(s, pcm, data_blocks);
}
static void handle_in_packet(struct amdtp_stream *s,
unsigned int payload_quadlets,
__be32 *buffer)
{
u32 cip_header[2];
unsigned int data_blocks, data_block_quadlets, data_block_counter,
dbc_interval;
struct snd_pcm_substream *pcm = NULL;
bool lost;
cip_header[0] = be32_to_cpu(buffer[0]);
cip_header[1] = be32_to_cpu(buffer[1]);
if (((cip_header[0] & CIP_EOH_MASK) == CIP_EOH) ||
((cip_header[1] & CIP_EOH_MASK) != CIP_EOH) ||
((cip_header[1] & CIP_FMT_MASK) != CIP_FMT_AM)) {
dev_info_ratelimited(&s->unit->device,
"Invalid CIP header for AMDTP: %08X:%08X\n",
cip_header[0], cip_header[1]);
goto end;
}
if (payload_quadlets < 3 ||
((cip_header[1] & CIP_FDF_MASK) ==
(AMDTP_FDF_NO_DATA << CIP_FDF_SFC_SHIFT))) {
data_blocks = 0;
} else {
data_block_quadlets =
(cip_header[0] & AMDTP_DBS_MASK) >> AMDTP_DBS_SHIFT;
if (data_block_quadlets == 0) {
dev_info_ratelimited(&s->unit->device,
"Detect invalid value in dbs field: %08X\n",
cip_header[0]);
goto err;
}
if (s->flags & CIP_WRONG_DBS)
data_block_quadlets = s->data_block_quadlets;
data_blocks = (payload_quadlets - 2) / data_block_quadlets;
}
data_block_counter = cip_header[0] & AMDTP_DBC_MASK;
if (data_blocks == 0 && (s->flags & CIP_EMPTY_HAS_WRONG_DBC) &&
s->data_block_counter != UINT_MAX)
data_block_counter = s->data_block_counter;
if (((s->flags & CIP_SKIP_DBC_ZERO_CHECK) && data_block_counter == 0) ||
(s->data_block_counter == UINT_MAX)) {
lost = false;
} else if (!(s->flags & CIP_DBC_IS_END_EVENT)) {
lost = data_block_counter != s->data_block_counter;
} else {
if ((data_blocks > 0) && (s->tx_dbc_interval > 0))
dbc_interval = s->tx_dbc_interval;
else
dbc_interval = data_blocks;
lost = data_block_counter !=
((s->data_block_counter + dbc_interval) & 0xff);
}
if (lost) {
dev_info(&s->unit->device,
"Detect discontinuity of CIP: %02X %02X\n",
s->data_block_counter, data_block_counter);
goto err;
}
if (data_blocks > 0) {
buffer += 2;
pcm = ACCESS_ONCE(s->pcm);
if (pcm)
s->transfer_samples(s, pcm, buffer, data_blocks);
if (s->midi_ports)
amdtp_pull_midi(s, buffer, data_blocks);
}
if (s->flags & CIP_DBC_IS_END_EVENT)
s->data_block_counter = data_block_counter;
else
s->data_block_counter =
(data_block_counter + data_blocks) & 0xff;
end:
if (queue_in_packet(s) < 0)
goto err;
if (pcm)
update_pcm_pointers(s, pcm, data_blocks);
return;
err:
s->packet_index = -1;
amdtp_stream_pcm_abort(s);
}
static void out_stream_callback(struct fw_iso_context *context, u32 cycle,
size_t header_length, void *header,
void *private_data)
{
struct amdtp_stream *s = private_data;
unsigned int i, syt, packets = header_length / 4;
cycle += QUEUE_LENGTH - packets;
for (i = 0; i < packets; ++i) {
syt = calculate_syt(s, ++cycle);
handle_out_packet(s, syt);
}
fw_iso_context_queue_flush(s->context);
}
static void in_stream_callback(struct fw_iso_context *context, u32 cycle,
size_t header_length, void *header,
void *private_data)
{
struct amdtp_stream *s = private_data;
unsigned int p, syt, packets, payload_quadlets;
__be32 *buffer, *headers = header;
packets = header_length / IN_PACKET_HEADER_SIZE;
for (p = 0; p < packets; p++) {
if (s->packet_index < 0)
break;
buffer = s->buffer.packets[s->packet_index].buffer;
if (s->sync_slave && s->sync_slave->callbacked) {
syt = be32_to_cpu(buffer[1]) & CIP_SYT_MASK;
handle_out_packet(s->sync_slave, syt);
}
payload_quadlets =
(be32_to_cpu(headers[p]) >> ISO_DATA_LENGTH_SHIFT) / 4;
handle_in_packet(s, payload_quadlets, buffer);
}
if (s->packet_index < 0) {
if (s->sync_slave) {
s->sync_slave->packet_index = -1;
amdtp_stream_pcm_abort(s->sync_slave);
}
return;
}
if (s->sync_slave && s->sync_slave->callbacked)
fw_iso_context_queue_flush(s->sync_slave->context);
fw_iso_context_queue_flush(s->context);
}
static void slave_stream_callback(struct fw_iso_context *context, u32 cycle,
size_t header_length, void *header,
void *private_data)
{
return;
}
static void amdtp_stream_first_callback(struct fw_iso_context *context,
u32 cycle, size_t header_length,
void *header, void *private_data)
{
struct amdtp_stream *s = private_data;
s->callbacked = true;
wake_up(&s->callback_wait);
if (s->direction == AMDTP_IN_STREAM)
context->callback.sc = in_stream_callback;
else if ((s->flags & CIP_BLOCKING) && (s->flags & CIP_SYNC_TO_DEVICE))
context->callback.sc = slave_stream_callback;
else
context->callback.sc = out_stream_callback;
context->callback.sc(context, cycle, header_length, header, s);
}
int amdtp_stream_start(struct amdtp_stream *s, int channel, int speed)
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
unsigned int header_size;
enum dma_data_direction dir;
int type, tag, err;
mutex_lock(&s->mutex);
if (WARN_ON(amdtp_stream_running(s) ||
(s->data_block_quadlets < 1))) {
err = -EBADFD;
goto err_unlock;
}
if (s->direction == AMDTP_IN_STREAM &&
s->flags & CIP_SKIP_INIT_DBC_CHECK)
s->data_block_counter = UINT_MAX;
else
s->data_block_counter = 0;
s->data_block_state = initial_state[s->sfc].data_block;
s->syt_offset_state = initial_state[s->sfc].syt_offset;
s->last_syt_offset = TICKS_PER_CYCLE;
if (s->direction == AMDTP_IN_STREAM) {
dir = DMA_FROM_DEVICE;
type = FW_ISO_CONTEXT_RECEIVE;
header_size = IN_PACKET_HEADER_SIZE;
} else {
dir = DMA_TO_DEVICE;
type = FW_ISO_CONTEXT_TRANSMIT;
header_size = OUT_PACKET_HEADER_SIZE;
}
err = iso_packets_buffer_init(&s->buffer, s->unit, QUEUE_LENGTH,
amdtp_stream_get_max_payload(s), dir);
if (err < 0)
goto err_unlock;
s->context = fw_iso_context_create(fw_parent_device(s->unit)->card,
type, channel, speed, header_size,
amdtp_stream_first_callback, s);
if (IS_ERR(s->context)) {
err = PTR_ERR(s->context);
if (err == -EBUSY)
dev_err(&s->unit->device,
"no free stream on this controller\n");
goto err_buffer;
}
amdtp_stream_update(s);
s->packet_index = 0;
do {
if (s->direction == AMDTP_IN_STREAM)
err = queue_in_packet(s);
else
err = queue_out_packet(s, 0, true);
if (err < 0)
goto err_context;
} while (s->packet_index > 0);
tag = FW_ISO_CONTEXT_MATCH_TAG1;
if (s->flags & CIP_EMPTY_WITH_TAG0)
tag |= FW_ISO_CONTEXT_MATCH_TAG0;
s->callbacked = false;
err = fw_iso_context_start(s->context, -1, 0, tag);
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
unsigned long amdtp_stream_pcm_pointer(struct amdtp_stream *s)
{
if (s->pointer_flush && amdtp_stream_running(s))
fw_iso_context_flush_completions(s->context);
else
s->pointer_flush = true;
return ACCESS_ONCE(s->pcm_buffer_pointer);
}
void amdtp_stream_update(struct amdtp_stream *s)
{
ACCESS_ONCE(s->source_node_id_field) =
(fw_parent_device(s->unit)->card->node_id & 0x3f) << 24;
}
void amdtp_stream_stop(struct amdtp_stream *s)
{
mutex_lock(&s->mutex);
if (!amdtp_stream_running(s)) {
mutex_unlock(&s->mutex);
return;
}
tasklet_kill(&s->period_tasklet);
fw_iso_context_stop(s->context);
fw_iso_context_destroy(s->context);
s->context = ERR_PTR(-1);
iso_packets_buffer_destroy(&s->buffer, s->unit);
s->callbacked = false;
mutex_unlock(&s->mutex);
}
void amdtp_stream_pcm_abort(struct amdtp_stream *s)
{
struct snd_pcm_substream *pcm;
pcm = ACCESS_ONCE(s->pcm);
if (pcm)
snd_pcm_stop_xrun(pcm);
}
