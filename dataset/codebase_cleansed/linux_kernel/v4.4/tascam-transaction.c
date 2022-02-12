static inline int calculate_message_bytes(u8 status)
{
switch (status) {
case 0xf6:
case 0xf8:
case 0xfa:
case 0xfb:
case 0xfc:
case 0xfe:
case 0xff:
return 1;
case 0xf1:
case 0xf3:
return 2;
case 0xf2:
return 3;
case 0xf0:
return 0;
case 0xf7:
break;
case 0xf4:
case 0xf5:
case 0xf9:
case 0xfd:
break;
default:
switch (status & 0xf0) {
case 0x80:
case 0x90:
case 0xa0:
case 0xb0:
case 0xe0:
return 3;
case 0xc0:
case 0xd0:
return 2;
default:
break;
}
break;
}
return -EINVAL;
}
static int fill_message(struct snd_rawmidi_substream *substream, u8 *buf)
{
struct snd_tscm *tscm = substream->rmidi->private_data;
unsigned int port = substream->number;
int i, len, consume;
u8 *label, *msg;
u8 status;
label = buf;
msg = buf + 1;
consume = snd_rawmidi_transmit_peek(substream, msg, 3);
if (consume == 0)
return 0;
if (tscm->on_sysex[port]) {
for (i = 0; i < consume; ++i) {
if (msg[i] == 0xf7) {
tscm->on_sysex[port] = false;
break;
}
}
if (!tscm->on_sysex[port]) {
consume = i + 1;
*label = (port << 4) | 0x07;
} else if (consume == 3) {
*label = (port << 4) | 0x04;
} else {
return 0;
}
len = consume;
} else {
if (msg[0] == 0xf0) {
tscm->on_sysex[port] = true;
return 0;
} else {
if ((msg[0] & 0x80) != 0x80)
status = tscm->running_status[port];
else
status = msg[0];
len = calculate_message_bytes(status);
if (len <= 0)
return 0;
if ((msg[0] & 0x80) != 0x80) {
if (consume < len - 1)
return 0;
consume = len - 1;
msg[2] = msg[1];
msg[1] = msg[0];
msg[0] = tscm->running_status[port];
} else {
if (consume < len)
return 0;
consume = len;
tscm->running_status[port] = msg[0];
}
}
*label = (port << 4) | (msg[0] >> 4);
}
if (len > 0 && len < 3)
memset(msg + len, 0, 3 - len);
return consume;
}
static void handle_midi_tx(struct fw_card *card, struct fw_request *request,
int tcode, int destination, int source,
int generation, unsigned long long offset,
void *data, size_t length, void *callback_data)
{
struct snd_tscm *tscm = callback_data;
u32 *buf = (u32 *)data;
unsigned int messages;
unsigned int i;
unsigned int port;
struct snd_rawmidi_substream *substream;
u8 *b;
int bytes;
if (offset != tscm->async_handler.offset)
goto end;
messages = length / 8;
for (i = 0; i < messages; i++) {
b = (u8 *)(buf + i * 2);
port = b[0] >> 4;
if (port >= tscm->spec->midi_capture_ports)
goto end;
bytes = calculate_message_bytes(b[1]);
if (bytes <= 0) {
for (bytes = 1; bytes < 4; bytes++) {
if (b[bytes] == 0xf7)
break;
}
if (bytes == 4)
bytes = 3;
}
substream = ACCESS_ONCE(tscm->tx_midi_substreams[port]);
if (substream != NULL)
snd_rawmidi_receive(substream, b + 1, bytes);
}
end:
fw_send_response(card, request, RCODE_COMPLETE);
}
int snd_tscm_transaction_register(struct snd_tscm *tscm)
{
static const struct fw_address_region resp_register_region = {
.start = 0xffffe0000000ull,
.end = 0xffffe000ffffull,
};
unsigned int i;
int err;
tscm->async_handler.length = 8 * 8;
tscm->async_handler.address_callback = handle_midi_tx;
tscm->async_handler.callback_data = tscm;
err = fw_core_add_address_handler(&tscm->async_handler,
&resp_register_region);
if (err < 0)
return err;
err = snd_tscm_transaction_reregister(tscm);
if (err < 0)
goto error;
for (i = 0; i < TSCM_MIDI_OUT_PORT_MAX; i++) {
err = snd_fw_async_midi_port_init(
&tscm->out_ports[i], tscm->unit,
TSCM_ADDR_BASE + TSCM_OFFSET_MIDI_RX_QUAD,
4, fill_message);
if (err < 0)
goto error;
}
return err;
error:
fw_core_remove_address_handler(&tscm->async_handler);
return err;
}
int snd_tscm_transaction_reregister(struct snd_tscm *tscm)
{
struct fw_device *device = fw_parent_device(tscm->unit);
__be32 reg;
int err;
reg = cpu_to_be32((device->card->node_id << 16) |
(tscm->async_handler.offset >> 32));
err = snd_fw_transaction(tscm->unit, TCODE_WRITE_QUADLET_REQUEST,
TSCM_ADDR_BASE + TSCM_OFFSET_MIDI_TX_ADDR_HI,
&reg, sizeof(reg), 0);
if (err < 0)
return err;
reg = cpu_to_be32(tscm->async_handler.offset);
err = snd_fw_transaction(tscm->unit, TCODE_WRITE_QUADLET_REQUEST,
TSCM_ADDR_BASE + TSCM_OFFSET_MIDI_TX_ADDR_LO,
&reg, sizeof(reg), 0);
if (err < 0)
return err;
reg = cpu_to_be32(0x00000001);
err = snd_fw_transaction(tscm->unit, TCODE_WRITE_QUADLET_REQUEST,
TSCM_ADDR_BASE + TSCM_OFFSET_MIDI_TX_ON,
&reg, sizeof(reg), 0);
if (err < 0)
return err;
reg = cpu_to_be32(0x0001008e);
return snd_fw_transaction(tscm->unit, TCODE_WRITE_QUADLET_REQUEST,
TSCM_ADDR_BASE + TSCM_OFFSET_LED_POWER,
&reg, sizeof(reg), 0);
}
void snd_tscm_transaction_unregister(struct snd_tscm *tscm)
{
__be32 reg;
unsigned int i;
reg = cpu_to_be32(0x0000008e);
snd_fw_transaction(tscm->unit, TCODE_WRITE_QUADLET_REQUEST,
TSCM_ADDR_BASE + TSCM_OFFSET_LED_POWER,
&reg, sizeof(reg), 0);
reg = cpu_to_be32(0x00000000);
snd_fw_transaction(tscm->unit, TCODE_WRITE_QUADLET_REQUEST,
TSCM_ADDR_BASE + TSCM_OFFSET_MIDI_TX_ON,
&reg, sizeof(reg), 0);
snd_fw_transaction(tscm->unit, TCODE_WRITE_QUADLET_REQUEST,
TSCM_ADDR_BASE + TSCM_OFFSET_MIDI_TX_ADDR_HI,
&reg, sizeof(reg), 0);
snd_fw_transaction(tscm->unit, TCODE_WRITE_QUADLET_REQUEST,
TSCM_ADDR_BASE + TSCM_OFFSET_MIDI_TX_ADDR_LO,
&reg, sizeof(reg), 0);
fw_core_remove_address_handler(&tscm->async_handler);
for (i = 0; i < TSCM_MIDI_OUT_PORT_MAX; i++)
snd_fw_async_midi_port_destroy(&tscm->out_ports[i]);
}
