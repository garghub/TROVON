int snd_fw_transaction(struct fw_unit *unit, int tcode,
u64 offset, void *buffer, size_t length,
unsigned int flags)
{
struct fw_device *device = fw_parent_device(unit);
int generation, rcode, tries = 0;
generation = flags & FW_GENERATION_MASK;
for (;;) {
if (!(flags & FW_FIXED_GENERATION)) {
generation = device->generation;
smp_rmb();
}
rcode = fw_run_transaction(device->card, tcode,
device->node_id, generation,
device->max_speed, offset,
buffer, length);
if (rcode == RCODE_COMPLETE)
return 0;
if (rcode == RCODE_GENERATION && (flags & FW_FIXED_GENERATION))
return -EAGAIN;
if (rcode_is_permanent_error(rcode) || ++tries >= 3) {
if (!(flags & FW_QUIET))
dev_err(&unit->device,
"transaction failed: %s\n",
fw_rcode_string(rcode));
return -EIO;
}
msleep(ERROR_RETRY_DELAY_MS);
}
}
static void async_midi_port_callback(struct fw_card *card, int rcode,
void *data, size_t length,
void *callback_data)
{
struct snd_fw_async_midi_port *port = callback_data;
struct snd_rawmidi_substream *substream = ACCESS_ONCE(port->substream);
if (substream == NULL)
return;
if (rcode == RCODE_COMPLETE)
snd_rawmidi_transmit_ack(substream, port->consume_bytes);
else if (!rcode_is_permanent_error(rcode))
port->next_ktime = ktime_set(0, 0);
else
port->error = true;
port->idling = true;
if (!snd_rawmidi_transmit_empty(substream))
schedule_work(&port->work);
}
static void midi_port_work(struct work_struct *work)
{
struct snd_fw_async_midi_port *port =
container_of(work, struct snd_fw_async_midi_port, work);
struct snd_rawmidi_substream *substream = ACCESS_ONCE(port->substream);
int generation;
int type;
if (!port->idling || port->error)
return;
if (substream == NULL || snd_rawmidi_transmit_empty(substream))
return;
if (ktime_after(port->next_ktime, ktime_get())) {
schedule_work(&port->work);
return;
}
memset(port->buf, 0, port->len);
port->consume_bytes = port->fill(substream, port->buf);
if (port->consume_bytes <= 0) {
if (port->consume_bytes == 0) {
port->next_ktime = ktime_set(0, 0);
schedule_work(&port->work);
} else {
port->error = true;
}
return;
}
if (port->len == 4)
type = TCODE_WRITE_QUADLET_REQUEST;
else
type = TCODE_WRITE_BLOCK_REQUEST;
port->next_ktime = ktime_add_ns(ktime_get(),
port->consume_bytes * 8 * NSEC_PER_SEC / 31250);
port->idling = false;
generation = port->parent->generation;
smp_rmb();
fw_send_request(port->parent->card, &port->transaction, type,
port->parent->node_id, generation,
port->parent->max_speed, port->addr,
port->buf, port->len, async_midi_port_callback,
port);
}
int snd_fw_async_midi_port_init(struct snd_fw_async_midi_port *port,
struct fw_unit *unit, u64 addr, unsigned int len,
snd_fw_async_midi_port_fill fill)
{
port->len = DIV_ROUND_UP(len, 4) * 4;
port->buf = kzalloc(port->len, GFP_KERNEL);
if (port->buf == NULL)
return -ENOMEM;
port->parent = fw_parent_device(unit);
port->addr = addr;
port->fill = fill;
port->idling = true;
port->next_ktime = ktime_set(0, 0);
port->error = false;
INIT_WORK(&port->work, midi_port_work);
return 0;
}
void snd_fw_async_midi_port_destroy(struct snd_fw_async_midi_port *port)
{
snd_fw_async_midi_port_finish(port);
cancel_work_sync(&port->work);
kfree(port->buf);
}
