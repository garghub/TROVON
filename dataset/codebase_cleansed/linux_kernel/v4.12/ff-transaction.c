static void finish_transmit_midi_msg(struct snd_ff *ff, unsigned int port,
int rcode)
{
struct snd_rawmidi_substream *substream =
ACCESS_ONCE(ff->rx_midi_substreams[port]);
if (rcode_is_permanent_error(rcode)) {
ff->rx_midi_error[port] = true;
return;
}
if (rcode != RCODE_COMPLETE) {
ff->next_ktime[port] = 0;
schedule_work(&ff->rx_midi_work[port]);
return;
}
snd_rawmidi_transmit_ack(substream, ff->rx_bytes[port]);
ff->rx_bytes[port] = 0;
if (!snd_rawmidi_transmit_empty(substream))
schedule_work(&ff->rx_midi_work[port]);
}
static void finish_transmit_midi0_msg(struct fw_card *card, int rcode,
void *data, size_t length,
void *callback_data)
{
struct snd_ff *ff =
container_of(callback_data, struct snd_ff, transactions[0]);
finish_transmit_midi_msg(ff, 0, rcode);
}
static void finish_transmit_midi1_msg(struct fw_card *card, int rcode,
void *data, size_t length,
void *callback_data)
{
struct snd_ff *ff =
container_of(callback_data, struct snd_ff, transactions[1]);
finish_transmit_midi_msg(ff, 1, rcode);
}
static inline void fill_midi_buf(struct snd_ff *ff, unsigned int port,
unsigned int index, u8 byte)
{
ff->msg_buf[port][index] = cpu_to_le32(byte);
}
static void transmit_midi_msg(struct snd_ff *ff, unsigned int port)
{
struct snd_rawmidi_substream *substream =
ACCESS_ONCE(ff->rx_midi_substreams[port]);
u8 *buf = (u8 *)ff->msg_buf[port];
int i, len;
struct fw_device *fw_dev = fw_parent_device(ff->unit);
unsigned long long addr;
int generation;
fw_transaction_callback_t callback;
if (substream == NULL || snd_rawmidi_transmit_empty(substream))
return;
if (ff->rx_bytes[port] > 0 || ff->rx_midi_error[port])
return;
if (ktime_after(ff->next_ktime[port], ktime_get())) {
schedule_work(&ff->rx_midi_work[port]);
return;
}
len = snd_rawmidi_transmit_peek(substream, buf,
SND_FF_MAXIMIM_MIDI_QUADS);
if (len <= 0)
return;
for (i = len - 1; i >= 0; i--)
fill_midi_buf(ff, port, i, buf[i]);
if (port == 0) {
addr = ff->spec->protocol->midi_rx_port_0_reg;
callback = finish_transmit_midi0_msg;
} else {
addr = ff->spec->protocol->midi_rx_port_1_reg;
callback = finish_transmit_midi1_msg;
}
ff->next_ktime[port] = ktime_add_ns(ktime_get(),
len * 8 * NSEC_PER_SEC / 31250);
ff->rx_bytes[port] = len;
generation = fw_dev->generation;
smp_rmb();
fw_send_request(fw_dev->card, &ff->transactions[port],
TCODE_WRITE_BLOCK_REQUEST,
fw_dev->node_id, generation, fw_dev->max_speed,
addr, &ff->msg_buf[port], len * 4,
callback, &ff->transactions[port]);
}
static void transmit_midi0_msg(struct work_struct *work)
{
struct snd_ff *ff = container_of(work, struct snd_ff, rx_midi_work[0]);
transmit_midi_msg(ff, 0);
}
static void transmit_midi1_msg(struct work_struct *work)
{
struct snd_ff *ff = container_of(work, struct snd_ff, rx_midi_work[1]);
transmit_midi_msg(ff, 1);
}
static void handle_midi_msg(struct fw_card *card, struct fw_request *request,
int tcode, int destination, int source,
int generation, unsigned long long offset,
void *data, size_t length, void *callback_data)
{
struct snd_ff *ff = callback_data;
__le32 *buf = data;
u32 quad;
u8 byte;
unsigned int index;
struct snd_rawmidi_substream *substream;
int i;
fw_send_response(card, request, RCODE_COMPLETE);
for (i = 0; i < length / 4; i++) {
quad = le32_to_cpu(buf[i]);
index = (quad >> 8) & 0xff;
if (index > 0) {
substream = ACCESS_ONCE(ff->tx_midi_substreams[0]);
if (substream != NULL) {
byte = quad & 0xff;
snd_rawmidi_receive(substream, &byte, 1);
}
}
index = (quad >> 24) & 0xff;
if (index > 0) {
substream = ACCESS_ONCE(ff->tx_midi_substreams[1]);
if (substream != NULL) {
byte = (quad >> 16) & 0xff;
snd_rawmidi_receive(substream, &byte, 1);
}
}
}
}
static int allocate_own_address(struct snd_ff *ff, int i)
{
struct fw_address_region midi_msg_region;
int err;
ff->async_handler.length = SND_FF_MAXIMIM_MIDI_QUADS * 4;
ff->async_handler.address_callback = handle_midi_msg;
ff->async_handler.callback_data = ff;
midi_msg_region.start = 0x000100000000ull * i;
midi_msg_region.end = midi_msg_region.start + ff->async_handler.length;
err = fw_core_add_address_handler(&ff->async_handler, &midi_msg_region);
if (err >= 0) {
if (ff->async_handler.offset & 0x0000ffffffff) {
fw_core_remove_address_handler(&ff->async_handler);
err = -EAGAIN;
}
}
return err;
}
int snd_ff_transaction_reregister(struct snd_ff *ff)
{
struct fw_card *fw_card = fw_parent_device(ff->unit)->card;
u32 addr;
__le32 reg;
addr = (fw_card->node_id << 16) | (ff->async_handler.offset >> 32);
reg = cpu_to_le32(addr);
return snd_fw_transaction(ff->unit, TCODE_WRITE_QUADLET_REQUEST,
ff->spec->protocol->midi_high_addr_reg,
&reg, sizeof(reg), 0);
}
int snd_ff_transaction_register(struct snd_ff *ff)
{
int i, err;
for (i = 0; i < 0xffff; i++) {
err = allocate_own_address(ff, i);
if (err != -EBUSY && err != -EAGAIN)
break;
}
if (err < 0)
return err;
err = snd_ff_transaction_reregister(ff);
if (err < 0)
return err;
INIT_WORK(&ff->rx_midi_work[0], transmit_midi0_msg);
INIT_WORK(&ff->rx_midi_work[1], transmit_midi1_msg);
return 0;
}
void snd_ff_transaction_unregister(struct snd_ff *ff)
{
__le32 reg;
if (ff->async_handler.callback_data == NULL)
return;
ff->async_handler.callback_data = NULL;
reg = cpu_to_le32(0x00000000);
snd_fw_transaction(ff->unit, TCODE_WRITE_QUADLET_REQUEST,
ff->spec->protocol->midi_high_addr_reg,
&reg, sizeof(reg), 0);
fw_core_remove_address_handler(&ff->async_handler);
}
