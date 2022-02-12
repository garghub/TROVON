int amdtp_stream_init(struct amdtp_stream *s, struct fw_unit *unit,
enum amdtp_stream_direction dir, enum cip_flags flags,
unsigned int fmt,
amdtp_stream_process_data_blocks_t process_data_blocks,
unsigned int protocol_size)
{
if (process_data_blocks == NULL)
return -EINVAL;
s->protocol = kzalloc(protocol_size, GFP_KERNEL);
if (!s->protocol)
return -ENOMEM;
s->unit = unit;
s->direction = dir;
s->flags = flags;
s->context = ERR_PTR(-1);
mutex_init(&s->mutex);
tasklet_init(&s->period_tasklet, pcm_period_tasklet, (unsigned long)s);
s->packet_index = 0;
init_waitqueue_head(&s->callback_wait);
s->callbacked = false;
s->fmt = fmt;
s->process_data_blocks = process_data_blocks;
return 0;
}
void amdtp_stream_destroy(struct amdtp_stream *s)
{
if (s->protocol == NULL)
return;
WARN_ON(amdtp_stream_running(s));
kfree(s->protocol);
mutex_destroy(&s->mutex);
}
int amdtp_stream_add_pcm_hw_constraints(struct amdtp_stream *s,
struct snd_pcm_runtime *runtime)
{
struct snd_pcm_hardware *hw = &runtime->hw;
int err;
hw->info = SNDRV_PCM_INFO_BATCH |
SNDRV_PCM_INFO_BLOCK_TRANSFER |
SNDRV_PCM_INFO_INTERLEAVED |
SNDRV_PCM_INFO_JOINT_DUPLEX |
SNDRV_PCM_INFO_MMAP |
SNDRV_PCM_INFO_MMAP_VALID;
hw->periods_min = 2;
hw->periods_max = UINT_MAX;
hw->period_bytes_min = 4 * hw->channels_max;
hw->period_bytes_max = hw->period_bytes_min * 2048;
hw->buffer_bytes_max = hw->period_bytes_max * hw->periods_min;
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
int amdtp_stream_set_parameters(struct amdtp_stream *s, unsigned int rate,
unsigned int data_block_quadlets)
{
unsigned int sfc;
for (sfc = 0; sfc < ARRAY_SIZE(amdtp_rate_table); ++sfc) {
if (amdtp_rate_table[sfc] == rate)
break;
}
if (sfc == ARRAY_SIZE(amdtp_rate_table))
return -EINVAL;
s->sfc = sfc;
s->data_block_quadlets = data_block_quadlets;
s->syt_interval = amdtp_syt_intervals[sfc];
s->transfer_delay = TRANSFER_DELAY_TICKS - TICKS_PER_CYCLE;
if (s->flags & CIP_BLOCKING)
s->transfer_delay += TICKS_PER_SECOND * s->syt_interval / rate;
return 0;
}
unsigned int amdtp_stream_get_max_payload(struct amdtp_stream *s)
{
unsigned int multiplier = 1;
unsigned int header_size = 0;
if (s->flags & CIP_JUMBO_PAYLOAD)
multiplier = 5;
if (!(s->flags & CIP_NO_HEADER))
header_size = 8;
return header_size +
s->syt_interval * s->data_block_quadlets * 4 * multiplier;
}
void amdtp_stream_pcm_prepare(struct amdtp_stream *s)
{
tasklet_kill(&s->period_tasklet);
s->pcm_buffer_pointer = 0;
s->pcm_period_pointer = 0;
}
static unsigned int calculate_data_blocks(struct amdtp_stream *s,
unsigned int syt)
{
unsigned int phase, data_blocks;
if (s->flags & CIP_BLOCKING) {
if (syt == CIP_SYT_NO_INFO)
data_blocks = 0;
else
data_blocks = s->syt_interval;
} else {
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
static void update_pcm_pointers(struct amdtp_stream *s,
struct snd_pcm_substream *pcm,
unsigned int frames)
{
unsigned int ptr;
ptr = s->pcm_buffer_pointer + frames;
if (ptr >= pcm->runtime->buffer_size)
ptr -= pcm->runtime->buffer_size;
ACCESS_ONCE(s->pcm_buffer_pointer) = ptr;
s->pcm_period_pointer += frames;
if (s->pcm_period_pointer >= pcm->runtime->period_size) {
s->pcm_period_pointer -= pcm->runtime->period_size;
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
static int queue_packet(struct amdtp_stream *s, unsigned int header_length,
unsigned int payload_length)
{
struct fw_iso_packet p = {0};
int err = 0;
if (IS_ERR(s->context))
goto end;
p.interrupt = IS_ALIGNED(s->packet_index + 1, INTERRUPT_INTERVAL);
p.tag = s->tag;
p.header_length = header_length;
if (payload_length > 0)
p.payload_length = payload_length;
else
p.skip = true;
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
unsigned int payload_length)
{
return queue_packet(s, OUT_PACKET_HEADER_SIZE, payload_length);
}
static inline int queue_in_packet(struct amdtp_stream *s)
{
return queue_packet(s, IN_PACKET_HEADER_SIZE, s->max_payload_length);
}
static int handle_out_packet(struct amdtp_stream *s,
unsigned int payload_length, unsigned int cycle,
unsigned int index)
{
__be32 *buffer;
unsigned int syt;
unsigned int data_blocks;
unsigned int pcm_frames;
struct snd_pcm_substream *pcm;
buffer = s->buffer.packets[s->packet_index].buffer;
syt = calculate_syt(s, cycle);
data_blocks = calculate_data_blocks(s, syt);
pcm_frames = s->process_data_blocks(s, buffer + 2, data_blocks, &syt);
if (s->flags & CIP_DBC_IS_END_EVENT)
s->data_block_counter =
(s->data_block_counter + data_blocks) & 0xff;
buffer[0] = cpu_to_be32(ACCESS_ONCE(s->source_node_id_field) |
(s->data_block_quadlets << CIP_DBS_SHIFT) |
((s->sph << CIP_SPH_SHIFT) & CIP_SPH_MASK) |
s->data_block_counter);
buffer[1] = cpu_to_be32(CIP_EOH |
((s->fmt << CIP_FMT_SHIFT) & CIP_FMT_MASK) |
((s->fdf << CIP_FDF_SHIFT) & CIP_FDF_MASK) |
(syt & CIP_SYT_MASK));
if (!(s->flags & CIP_DBC_IS_END_EVENT))
s->data_block_counter =
(s->data_block_counter + data_blocks) & 0xff;
payload_length = 8 + data_blocks * 4 * s->data_block_quadlets;
trace_out_packet(s, cycle, buffer, payload_length, index);
if (queue_out_packet(s, payload_length) < 0)
return -EIO;
pcm = ACCESS_ONCE(s->pcm);
if (pcm && pcm_frames > 0)
update_pcm_pointers(s, pcm, pcm_frames);
return 0;
}
static int handle_out_packet_without_header(struct amdtp_stream *s,
unsigned int payload_length, unsigned int cycle,
unsigned int index)
{
__be32 *buffer;
unsigned int syt;
unsigned int data_blocks;
unsigned int pcm_frames;
struct snd_pcm_substream *pcm;
buffer = s->buffer.packets[s->packet_index].buffer;
syt = calculate_syt(s, cycle);
data_blocks = calculate_data_blocks(s, syt);
pcm_frames = s->process_data_blocks(s, buffer, data_blocks, &syt);
s->data_block_counter = (s->data_block_counter + data_blocks) & 0xff;
payload_length = data_blocks * 4 * s->data_block_quadlets;
trace_out_packet_without_header(s, cycle, payload_length, data_blocks,
index);
if (queue_out_packet(s, payload_length) < 0)
return -EIO;
pcm = ACCESS_ONCE(s->pcm);
if (pcm && pcm_frames > 0)
update_pcm_pointers(s, pcm, pcm_frames);
return 0;
}
static int handle_in_packet(struct amdtp_stream *s,
unsigned int payload_length, unsigned int cycle,
unsigned int index)
{
__be32 *buffer;
u32 cip_header[2];
unsigned int sph, fmt, fdf, syt;
unsigned int data_block_quadlets, data_block_counter, dbc_interval;
unsigned int data_blocks;
struct snd_pcm_substream *pcm;
unsigned int pcm_frames;
bool lost;
buffer = s->buffer.packets[s->packet_index].buffer;
cip_header[0] = be32_to_cpu(buffer[0]);
cip_header[1] = be32_to_cpu(buffer[1]);
trace_in_packet(s, cycle, cip_header, payload_length, index);
if ((((cip_header[0] & CIP_EOH_MASK) == CIP_EOH) ||
((cip_header[1] & CIP_EOH_MASK) != CIP_EOH)) &&
(!(s->flags & CIP_HEADER_WITHOUT_EOH))) {
dev_info_ratelimited(&s->unit->device,
"Invalid CIP header for AMDTP: %08X:%08X\n",
cip_header[0], cip_header[1]);
data_blocks = 0;
pcm_frames = 0;
goto end;
}
sph = (cip_header[0] & CIP_SPH_MASK) >> CIP_SPH_SHIFT;
fmt = (cip_header[1] & CIP_FMT_MASK) >> CIP_FMT_SHIFT;
if (sph != s->sph || fmt != s->fmt) {
dev_info_ratelimited(&s->unit->device,
"Detect unexpected protocol: %08x %08x\n",
cip_header[0], cip_header[1]);
data_blocks = 0;
pcm_frames = 0;
goto end;
}
fdf = (cip_header[1] & CIP_FDF_MASK) >> CIP_FDF_SHIFT;
if (payload_length < 12 ||
(fmt == CIP_FMT_AM && fdf == AMDTP_FDF_NO_DATA)) {
data_blocks = 0;
} else {
data_block_quadlets =
(cip_header[0] & CIP_DBS_MASK) >> CIP_DBS_SHIFT;
if (data_block_quadlets == 0) {
dev_err(&s->unit->device,
"Detect invalid value in dbs field: %08X\n",
cip_header[0]);
return -EPROTO;
}
if (s->flags & CIP_WRONG_DBS)
data_block_quadlets = s->data_block_quadlets;
data_blocks = (payload_length / 4 - 2) /
data_block_quadlets;
}
data_block_counter = cip_header[0] & CIP_DBC_MASK;
if (data_blocks == 0 && (s->flags & CIP_EMPTY_HAS_WRONG_DBC) &&
s->data_block_counter != UINT_MAX)
data_block_counter = s->data_block_counter;
if (((s->flags & CIP_SKIP_DBC_ZERO_CHECK) &&
data_block_counter == s->tx_first_dbc) ||
s->data_block_counter == UINT_MAX) {
lost = false;
} else if (!(s->flags & CIP_DBC_IS_END_EVENT)) {
lost = data_block_counter != s->data_block_counter;
} else {
if (data_blocks > 0 && s->tx_dbc_interval > 0)
dbc_interval = s->tx_dbc_interval;
else
dbc_interval = data_blocks;
lost = data_block_counter !=
((s->data_block_counter + dbc_interval) & 0xff);
}
if (lost) {
dev_err(&s->unit->device,
"Detect discontinuity of CIP: %02X %02X\n",
s->data_block_counter, data_block_counter);
return -EIO;
}
syt = be32_to_cpu(buffer[1]) & CIP_SYT_MASK;
pcm_frames = s->process_data_blocks(s, buffer + 2, data_blocks, &syt);
if (s->flags & CIP_DBC_IS_END_EVENT)
s->data_block_counter = data_block_counter;
else
s->data_block_counter =
(data_block_counter + data_blocks) & 0xff;
end:
if (queue_in_packet(s) < 0)
return -EIO;
pcm = ACCESS_ONCE(s->pcm);
if (pcm && pcm_frames > 0)
update_pcm_pointers(s, pcm, pcm_frames);
return 0;
}
static int handle_in_packet_without_header(struct amdtp_stream *s,
unsigned int payload_quadlets, unsigned int cycle,
unsigned int index)
{
__be32 *buffer;
unsigned int data_blocks;
struct snd_pcm_substream *pcm;
unsigned int pcm_frames;
buffer = s->buffer.packets[s->packet_index].buffer;
data_blocks = payload_quadlets / s->data_block_quadlets;
trace_in_packet_without_header(s, cycle, payload_quadlets, data_blocks,
index);
pcm_frames = s->process_data_blocks(s, buffer, data_blocks, NULL);
s->data_block_counter = (s->data_block_counter + data_blocks) & 0xff;
if (queue_in_packet(s) < 0)
return -EIO;
pcm = ACCESS_ONCE(s->pcm);
if (pcm && pcm_frames > 0)
update_pcm_pointers(s, pcm, pcm_frames);
return 0;
}
static inline u32 compute_cycle_count(u32 tstamp)
{
return (((tstamp >> 13) & 0x07) * 8000) + (tstamp & 0x1fff);
}
static inline u32 increment_cycle_count(u32 cycle, unsigned int addend)
{
cycle += addend;
if (cycle >= 8 * CYCLES_PER_SECOND)
cycle -= 8 * CYCLES_PER_SECOND;
return cycle;
}
static inline u32 decrement_cycle_count(u32 cycle, unsigned int subtrahend)
{
if (cycle < subtrahend)
cycle += 8 * CYCLES_PER_SECOND;
return cycle - subtrahend;
}
static void out_stream_callback(struct fw_iso_context *context, u32 tstamp,
size_t header_length, void *header,
void *private_data)
{
struct amdtp_stream *s = private_data;
unsigned int i, packets = header_length / 4;
u32 cycle;
if (s->packet_index < 0)
return;
cycle = compute_cycle_count(tstamp);
cycle = increment_cycle_count(cycle, QUEUE_LENGTH - packets);
for (i = 0; i < packets; ++i) {
cycle = increment_cycle_count(cycle, 1);
if (s->handle_packet(s, 0, cycle, i) < 0) {
s->packet_index = -1;
if (in_interrupt())
amdtp_stream_pcm_abort(s);
WRITE_ONCE(s->pcm_buffer_pointer, SNDRV_PCM_POS_XRUN);
return;
}
}
fw_iso_context_queue_flush(s->context);
}
static void in_stream_callback(struct fw_iso_context *context, u32 tstamp,
size_t header_length, void *header,
void *private_data)
{
struct amdtp_stream *s = private_data;
unsigned int i, packets;
unsigned int payload_length, max_payload_length;
__be32 *headers = header;
u32 cycle;
if (s->packet_index < 0)
return;
packets = header_length / IN_PACKET_HEADER_SIZE;
cycle = compute_cycle_count(tstamp);
cycle = decrement_cycle_count(cycle, packets);
max_payload_length = s->max_payload_length;
for (i = 0; i < packets; i++) {
cycle = increment_cycle_count(cycle, 1);
payload_length =
(be32_to_cpu(headers[i]) >> ISO_DATA_LENGTH_SHIFT);
if (payload_length > max_payload_length) {
dev_err(&s->unit->device,
"Detect jumbo payload: %04x %04x\n",
payload_length, max_payload_length);
break;
}
if (s->handle_packet(s, payload_length, cycle, i) < 0)
break;
}
if (i < packets) {
s->packet_index = -1;
if (in_interrupt())
amdtp_stream_pcm_abort(s);
WRITE_ONCE(s->pcm_buffer_pointer, SNDRV_PCM_POS_XRUN);
return;
}
fw_iso_context_queue_flush(s->context);
}
static void amdtp_stream_first_callback(struct fw_iso_context *context,
u32 tstamp, size_t header_length,
void *header, void *private_data)
{
struct amdtp_stream *s = private_data;
u32 cycle;
unsigned int packets;
s->max_payload_length = amdtp_stream_get_max_payload(s);
s->callbacked = true;
wake_up(&s->callback_wait);
cycle = compute_cycle_count(tstamp);
if (s->direction == AMDTP_IN_STREAM) {
packets = header_length / IN_PACKET_HEADER_SIZE;
cycle = decrement_cycle_count(cycle, packets);
context->callback.sc = in_stream_callback;
if (s->flags & CIP_NO_HEADER)
s->handle_packet = handle_in_packet_without_header;
else
s->handle_packet = handle_in_packet;
} else {
packets = header_length / 4;
cycle = increment_cycle_count(cycle, QUEUE_LENGTH - packets);
context->callback.sc = out_stream_callback;
if (s->flags & CIP_NO_HEADER)
s->handle_packet = handle_out_packet_without_header;
else
s->handle_packet = handle_out_packet;
}
s->start_cycle = cycle;
context->callback.sc(context, tstamp, header_length, header, s);
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
if (s->direction == AMDTP_IN_STREAM)
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
if (s->flags & CIP_NO_HEADER)
s->tag = TAG_NO_CIP_HEADER;
else
s->tag = TAG_CIP;
s->packet_index = 0;
do {
if (s->direction == AMDTP_IN_STREAM)
err = queue_in_packet(s);
else
err = queue_out_packet(s, 0);
if (err < 0)
goto err_context;
} while (s->packet_index > 0);
tag = FW_ISO_CONTEXT_MATCH_TAG1;
if ((s->flags & CIP_EMPTY_WITH_TAG0) || (s->flags & CIP_NO_HEADER))
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
if (!in_interrupt() && amdtp_stream_running(s))
fw_iso_context_flush_completions(s->context);
return ACCESS_ONCE(s->pcm_buffer_pointer);
}
int amdtp_stream_pcm_ack(struct amdtp_stream *s)
{
if (amdtp_stream_running(s))
fw_iso_context_flush_completions(s->context);
return 0;
}
void amdtp_stream_update(struct amdtp_stream *s)
{
ACCESS_ONCE(s->source_node_id_field) =
(fw_parent_device(s->unit)->card->node_id << CIP_SID_SHIFT) &
CIP_SID_MASK;
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
