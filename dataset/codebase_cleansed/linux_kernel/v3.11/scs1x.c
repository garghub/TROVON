static int scs_output_open(struct snd_rawmidi_substream *stream)
{
struct scs *scs = stream->rmidi->private_data;
scs->output_status = 0;
scs->output_bytes = 1;
scs->output_escaped = false;
return 0;
}
static int scs_output_close(struct snd_rawmidi_substream *stream)
{
return 0;
}
static void scs_output_trigger(struct snd_rawmidi_substream *stream, int up)
{
struct scs *scs = stream->rmidi->private_data;
ACCESS_ONCE(scs->output) = up ? stream : NULL;
if (up) {
scs->output_idle = false;
tasklet_schedule(&scs->tasklet);
}
}
static void scs_write_callback(struct fw_card *card, int rcode,
void *data, size_t length, void *callback_data)
{
struct scs *scs = callback_data;
if (rcode == RCODE_GENERATION) {
}
scs->transaction_running = false;
tasklet_schedule(&scs->tasklet);
}
static bool is_valid_running_status(u8 status)
{
return status >= 0x80 && status <= 0xef;
}
static bool is_one_byte_cmd(u8 status)
{
return status == 0xf6 ||
status >= 0xf8;
}
static bool is_two_bytes_cmd(u8 status)
{
return (status >= 0xc0 && status <= 0xdf) ||
status == 0xf1 ||
status == 0xf3;
}
static bool is_three_bytes_cmd(u8 status)
{
return (status >= 0x80 && status <= 0xbf) ||
(status >= 0xe0 && status <= 0xef) ||
status == 0xf2;
}
static bool is_invalid_cmd(u8 status)
{
return status == 0xf4 ||
status == 0xf5 ||
status == 0xf9 ||
status == 0xfd;
}
static void scs_output_tasklet(unsigned long data)
{
struct scs *scs = (void *)data;
struct snd_rawmidi_substream *stream;
unsigned int i;
u8 byte;
struct fw_device *dev;
int generation;
if (scs->transaction_running)
return;
stream = ACCESS_ONCE(scs->output);
if (!stream) {
scs->output_idle = true;
wake_up(&scs->idle_wait);
return;
}
i = scs->output_bytes;
for (;;) {
if (snd_rawmidi_transmit(stream, &byte, 1) != 1) {
scs->output_bytes = i;
scs->output_idle = true;
wake_up(&scs->idle_wait);
return;
}
if (scs->output_escaped && byte < 0x80) {
if (scs->output_escape_high_nibble) {
if (i < HSS1394_MAX_PACKET_SIZE) {
scs->buffer[i] = byte << 4;
scs->output_escape_high_nibble = false;
}
} else {
scs->buffer[i++] |= byte & 0x0f;
scs->output_escape_high_nibble = true;
}
} else if (byte < 0x80) {
if (i == 1) {
if (!is_valid_running_status(scs->output_status))
continue;
scs->buffer[0] = HSS1394_TAG_USER_DATA;
scs->buffer[i++] = scs->output_status;
}
scs->buffer[i++] = byte;
if ((i == 3 && is_two_bytes_cmd(scs->output_status)) ||
(i == 4 && is_three_bytes_cmd(scs->output_status)))
break;
if (i == 1 + ARRAY_SIZE(sysex_escape_prefix) &&
!memcmp(scs->buffer + 1, sysex_escape_prefix,
ARRAY_SIZE(sysex_escape_prefix))) {
scs->output_escaped = true;
scs->output_escape_high_nibble = true;
i = 0;
}
if (i >= HSS1394_MAX_PACKET_SIZE)
i = 1;
} else if (byte == 0xf7) {
if (scs->output_escaped) {
if (i >= 1 && scs->output_escape_high_nibble &&
scs->buffer[0] != HSS1394_TAG_CHANGE_ADDRESS)
break;
} else {
if (i > 1 && scs->output_status == 0xf0) {
scs->buffer[i++] = 0xf7;
break;
}
}
i = 1;
scs->output_escaped = false;
} else if (!is_invalid_cmd(byte) &&
byte < 0xf8) {
i = 1;
scs->buffer[0] = HSS1394_TAG_USER_DATA;
scs->buffer[i++] = byte;
scs->output_status = byte;
scs->output_escaped = false;
if (is_one_byte_cmd(byte))
break;
}
}
scs->output_bytes = 1;
scs->output_escaped = false;
scs->transaction_running = true;
dev = fw_parent_device(scs->unit);
generation = dev->generation;
smp_rmb();
fw_send_request(dev->card, &scs->transaction, TCODE_WRITE_BLOCK_REQUEST,
dev->node_id, generation, dev->max_speed,
HSS1394_ADDRESS, scs->buffer, i,
scs_write_callback, scs);
}
static void scs_output_drain(struct snd_rawmidi_substream *stream)
{
struct scs *scs = stream->rmidi->private_data;
wait_event(scs->idle_wait, scs->output_idle);
}
static int scs_input_open(struct snd_rawmidi_substream *stream)
{
struct scs *scs = stream->rmidi->private_data;
scs->input_escape_count = 0;
return 0;
}
static int scs_input_close(struct snd_rawmidi_substream *stream)
{
return 0;
}
static void scs_input_trigger(struct snd_rawmidi_substream *stream, int up)
{
struct scs *scs = stream->rmidi->private_data;
ACCESS_ONCE(scs->input) = up ? stream : NULL;
}
static void scs_input_escaped_byte(struct snd_rawmidi_substream *stream,
u8 byte)
{
u8 nibbles[2];
nibbles[0] = byte >> 4;
nibbles[1] = byte & 0x0f;
snd_rawmidi_receive(stream, nibbles, 2);
}
static void scs_input_midi_byte(struct scs *scs,
struct snd_rawmidi_substream *stream,
u8 byte)
{
if (scs->input_escape_count > 0) {
scs_input_escaped_byte(stream, byte);
scs->input_escape_count--;
if (scs->input_escape_count == 0)
snd_rawmidi_receive(stream, (const u8[]) { 0xf7 }, 1);
} else if (byte == 0xf9) {
snd_rawmidi_receive(stream, sysex_escape_prefix,
ARRAY_SIZE(sysex_escape_prefix));
scs_input_escaped_byte(stream, 0x00);
scs_input_escaped_byte(stream, 0xf9);
scs->input_escape_count = 3;
} else {
snd_rawmidi_receive(stream, &byte, 1);
}
}
static void scs_input_packet(struct scs *scs,
struct snd_rawmidi_substream *stream,
const u8 *data, unsigned int bytes)
{
unsigned int i;
if (data[0] == HSS1394_TAG_USER_DATA) {
for (i = 1; i < bytes; ++i)
scs_input_midi_byte(scs, stream, data[i]);
} else {
snd_rawmidi_receive(stream, sysex_escape_prefix,
ARRAY_SIZE(sysex_escape_prefix));
for (i = 0; i < bytes; ++i)
scs_input_escaped_byte(stream, data[i]);
snd_rawmidi_receive(stream, (const u8[]) { 0xf7 }, 1);
}
}
static int scs_create_midi(struct scs *scs)
{
struct snd_rawmidi *rmidi;
int err;
err = snd_rawmidi_new(scs->card, "SCS.1x", 0, 1, 1, &rmidi);
if (err < 0)
return err;
snprintf(rmidi->name, sizeof(rmidi->name),
"%s MIDI", scs->card->shortname);
rmidi->info_flags = SNDRV_RAWMIDI_INFO_OUTPUT |
SNDRV_RAWMIDI_INFO_INPUT |
SNDRV_RAWMIDI_INFO_DUPLEX;
rmidi->private_data = scs;
snd_rawmidi_set_ops(rmidi, SNDRV_RAWMIDI_STREAM_OUTPUT, &output_ops);
snd_rawmidi_set_ops(rmidi, SNDRV_RAWMIDI_STREAM_INPUT, &input_ops);
return 0;
}
static void handle_hss(struct fw_card *card, struct fw_request *request,
int tcode, int destination, int source, int generation,
unsigned long long offset, void *data, size_t length,
void *callback_data)
{
struct scs *scs = callback_data;
struct snd_rawmidi_substream *stream;
if (offset != scs->hss_handler.offset) {
fw_send_response(card, request, RCODE_ADDRESS_ERROR);
return;
}
if (tcode != TCODE_WRITE_QUADLET_REQUEST &&
tcode != TCODE_WRITE_BLOCK_REQUEST) {
fw_send_response(card, request, RCODE_TYPE_ERROR);
return;
}
if (length >= 1) {
stream = ACCESS_ONCE(scs->input);
if (stream)
scs_input_packet(scs, stream, data, length);
}
fw_send_response(card, request, RCODE_COMPLETE);
}
static int scs_init_hss_address(struct scs *scs)
{
__be64 data;
int err;
data = cpu_to_be64(((u64)HSS1394_TAG_CHANGE_ADDRESS << 56) |
scs->hss_handler.offset);
err = snd_fw_transaction(scs->unit, TCODE_WRITE_BLOCK_REQUEST,
HSS1394_ADDRESS, &data, 8);
if (err < 0)
dev_err(&scs->unit->device, "HSS1394 communication failed\n");
return err;
}
static void scs_card_free(struct snd_card *card)
{
struct scs *scs = card->private_data;
fw_core_remove_address_handler(&scs->hss_handler);
kfree(scs->buffer);
}
static int scs_probe(struct fw_unit *unit, const struct ieee1394_device_id *id)
{
struct fw_device *fw_dev = fw_parent_device(unit);
struct snd_card *card;
struct scs *scs;
int err;
err = snd_card_create(-16, NULL, THIS_MODULE, sizeof(*scs), &card);
if (err < 0)
return err;
snd_card_set_dev(card, &unit->device);
scs = card->private_data;
scs->card = card;
scs->unit = unit;
tasklet_init(&scs->tasklet, scs_output_tasklet, (unsigned long)scs);
init_waitqueue_head(&scs->idle_wait);
scs->output_idle = true;
scs->buffer = kmalloc(HSS1394_MAX_PACKET_SIZE, GFP_KERNEL);
if (!scs->buffer) {
err = -ENOMEM;
goto err_card;
}
scs->hss_handler.length = HSS1394_MAX_PACKET_SIZE;
scs->hss_handler.address_callback = handle_hss;
scs->hss_handler.callback_data = scs;
err = fw_core_add_address_handler(&scs->hss_handler,
&fw_high_memory_region);
if (err < 0)
goto err_buffer;
card->private_free = scs_card_free;
strcpy(card->driver, "SCS.1x");
strcpy(card->shortname, "SCS.1x");
fw_csr_string(unit->directory, CSR_MODEL,
card->shortname, sizeof(card->shortname));
snprintf(card->longname, sizeof(card->longname),
"Stanton DJ %s (GUID %08x%08x) at %s, S%d",
card->shortname, fw_dev->config_rom[3], fw_dev->config_rom[4],
dev_name(&unit->device), 100 << fw_dev->max_speed);
strcpy(card->mixername, card->shortname);
err = scs_init_hss_address(scs);
if (err < 0)
goto err_card;
err = scs_create_midi(scs);
if (err < 0)
goto err_card;
err = snd_card_register(card);
if (err < 0)
goto err_card;
dev_set_drvdata(&unit->device, scs);
return 0;
err_buffer:
kfree(scs->buffer);
err_card:
snd_card_free(card);
return err;
}
static void scs_update(struct fw_unit *unit)
{
struct scs *scs = dev_get_drvdata(&unit->device);
__be64 data;
data = cpu_to_be64(((u64)HSS1394_TAG_CHANGE_ADDRESS << 56) |
scs->hss_handler.offset);
snd_fw_transaction(scs->unit, TCODE_WRITE_BLOCK_REQUEST,
HSS1394_ADDRESS, &data, 8);
}
static void scs_remove(struct fw_unit *unit)
{
struct scs *scs = dev_get_drvdata(&unit->device);
snd_card_disconnect(scs->card);
ACCESS_ONCE(scs->output) = NULL;
ACCESS_ONCE(scs->input) = NULL;
wait_event(scs->idle_wait, scs->output_idle);
tasklet_kill(&scs->tasklet);
snd_card_free_when_closed(scs->card);
}
static int __init alsa_scs1x_init(void)
{
return driver_register(&scs_driver.driver);
}
static void __exit alsa_scs1x_exit(void)
{
driver_unregister(&scs_driver.driver);
}
