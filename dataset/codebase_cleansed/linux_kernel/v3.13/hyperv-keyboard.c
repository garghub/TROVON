static void hv_kbd_on_receive(struct hv_device *hv_dev,
struct synth_kbd_msg *msg, u32 msg_length)
{
struct hv_kbd_dev *kbd_dev = hv_get_drvdata(hv_dev);
struct synth_kbd_keystroke *ks_msg;
unsigned long flags;
u32 msg_type = __le32_to_cpu(msg->header.type);
u32 info;
u16 scan_code;
switch (msg_type) {
case SYNTH_KBD_PROTOCOL_RESPONSE:
if (msg_length < sizeof(struct synth_kbd_protocol_response)) {
dev_err(&hv_dev->device,
"Illegal protocol response packet (len: %d)\n",
msg_length);
break;
}
memcpy(&kbd_dev->protocol_resp, msg,
sizeof(struct synth_kbd_protocol_response));
complete(&kbd_dev->wait_event);
break;
case SYNTH_KBD_EVENT:
if (msg_length < sizeof(struct synth_kbd_keystroke)) {
dev_err(&hv_dev->device,
"Illegal keyboard event packet (len: %d)\n",
msg_length);
break;
}
ks_msg = (struct synth_kbd_keystroke *)msg;
info = __le32_to_cpu(ks_msg->info);
spin_lock_irqsave(&kbd_dev->lock, flags);
if (kbd_dev->started) {
if (info & IS_E0)
serio_interrupt(kbd_dev->hv_serio,
XTKBD_EMUL0, 0);
scan_code = __le16_to_cpu(ks_msg->make_code);
if (info & IS_BREAK)
scan_code |= XTKBD_RELEASE;
serio_interrupt(kbd_dev->hv_serio, scan_code, 0);
}
spin_unlock_irqrestore(&kbd_dev->lock, flags);
break;
default:
dev_err(&hv_dev->device,
"unhandled message type %d\n", msg_type);
}
}
static void hv_kbd_handle_received_packet(struct hv_device *hv_dev,
struct vmpacket_descriptor *desc,
u32 bytes_recvd,
u64 req_id)
{
struct synth_kbd_msg *msg;
u32 msg_sz;
switch (desc->type) {
case VM_PKT_COMP:
break;
case VM_PKT_DATA_INBAND:
msg_sz = bytes_recvd - (desc->offset8 << 3);
if (msg_sz <= sizeof(struct synth_kbd_msg_hdr)) {
dev_err(&hv_dev->device,
"Illegal packet (type: %d, tid: %llx, size: %d)\n",
desc->type, req_id, msg_sz);
break;
}
msg = (void *)desc + (desc->offset8 << 3);
hv_kbd_on_receive(hv_dev, msg, msg_sz);
break;
default:
dev_err(&hv_dev->device,
"unhandled packet type %d, tid %llx len %d\n",
desc->type, req_id, bytes_recvd);
break;
}
}
static void hv_kbd_on_channel_callback(void *context)
{
struct hv_device *hv_dev = context;
void *buffer;
int bufferlen = 0x100;
u32 bytes_recvd;
u64 req_id;
int error;
buffer = kmalloc(bufferlen, GFP_ATOMIC);
if (!buffer)
return;
while (1) {
error = vmbus_recvpacket_raw(hv_dev->channel, buffer, bufferlen,
&bytes_recvd, &req_id);
switch (error) {
case 0:
if (bytes_recvd == 0) {
kfree(buffer);
return;
}
hv_kbd_handle_received_packet(hv_dev, buffer,
bytes_recvd, req_id);
break;
case -ENOBUFS:
kfree(buffer);
bufferlen = bytes_recvd;
buffer = kmalloc(bytes_recvd, GFP_ATOMIC);
if (!buffer)
return;
break;
}
}
}
static int hv_kbd_connect_to_vsp(struct hv_device *hv_dev)
{
struct hv_kbd_dev *kbd_dev = hv_get_drvdata(hv_dev);
struct synth_kbd_protocol_request *request;
struct synth_kbd_protocol_response *response;
u32 proto_status;
int error;
request = &kbd_dev->protocol_req;
memset(request, 0, sizeof(struct synth_kbd_protocol_request));
request->header.type = __cpu_to_le32(SYNTH_KBD_PROTOCOL_REQUEST);
request->version_requested.version = __cpu_to_le32(SYNTH_KBD_VERSION);
error = vmbus_sendpacket(hv_dev->channel, request,
sizeof(struct synth_kbd_protocol_request),
(unsigned long)request,
VM_PKT_DATA_INBAND,
VMBUS_DATA_PACKET_FLAG_COMPLETION_REQUESTED);
if (error)
return error;
if (!wait_for_completion_timeout(&kbd_dev->wait_event, 10 * HZ))
return -ETIMEDOUT;
response = &kbd_dev->protocol_resp;
proto_status = __le32_to_cpu(response->proto_status);
if (!(proto_status & PROTOCOL_ACCEPTED)) {
dev_err(&hv_dev->device,
"synth_kbd protocol request failed (version %d)\n",
SYNTH_KBD_VERSION);
return -ENODEV;
}
return 0;
}
static int hv_kbd_start(struct serio *serio)
{
struct hv_kbd_dev *kbd_dev = serio->port_data;
unsigned long flags;
spin_lock_irqsave(&kbd_dev->lock, flags);
kbd_dev->started = true;
spin_unlock_irqrestore(&kbd_dev->lock, flags);
return 0;
}
static void hv_kbd_stop(struct serio *serio)
{
struct hv_kbd_dev *kbd_dev = serio->port_data;
unsigned long flags;
spin_lock_irqsave(&kbd_dev->lock, flags);
kbd_dev->started = false;
spin_unlock_irqrestore(&kbd_dev->lock, flags);
}
static int hv_kbd_probe(struct hv_device *hv_dev,
const struct hv_vmbus_device_id *dev_id)
{
struct hv_kbd_dev *kbd_dev;
struct serio *hv_serio;
int error;
kbd_dev = kzalloc(sizeof(struct hv_kbd_dev), GFP_KERNEL);
hv_serio = kzalloc(sizeof(struct serio), GFP_KERNEL);
if (!kbd_dev || !hv_serio) {
error = -ENOMEM;
goto err_free_mem;
}
kbd_dev->hv_dev = hv_dev;
kbd_dev->hv_serio = hv_serio;
spin_lock_init(&kbd_dev->lock);
init_completion(&kbd_dev->wait_event);
hv_set_drvdata(hv_dev, kbd_dev);
hv_serio->dev.parent = &hv_dev->device;
hv_serio->id.type = SERIO_8042_XL;
hv_serio->port_data = kbd_dev;
strlcpy(hv_serio->name, dev_name(&hv_dev->device),
sizeof(hv_serio->name));
strlcpy(hv_serio->phys, dev_name(&hv_dev->device),
sizeof(hv_serio->phys));
hv_serio->start = hv_kbd_start;
hv_serio->stop = hv_kbd_stop;
error = vmbus_open(hv_dev->channel,
KBD_VSC_SEND_RING_BUFFER_SIZE,
KBD_VSC_RECV_RING_BUFFER_SIZE,
NULL, 0,
hv_kbd_on_channel_callback,
hv_dev);
if (error)
goto err_free_mem;
error = hv_kbd_connect_to_vsp(hv_dev);
if (error)
goto err_close_vmbus;
serio_register_port(kbd_dev->hv_serio);
return 0;
err_close_vmbus:
vmbus_close(hv_dev->channel);
err_free_mem:
kfree(hv_serio);
kfree(kbd_dev);
return error;
}
static int hv_kbd_remove(struct hv_device *hv_dev)
{
struct hv_kbd_dev *kbd_dev = hv_get_drvdata(hv_dev);
serio_unregister_port(kbd_dev->hv_serio);
vmbus_close(hv_dev->channel);
kfree(kbd_dev);
hv_set_drvdata(hv_dev, NULL);
return 0;
}
static int __init hv_kbd_init(void)
{
return vmbus_driver_register(&hv_kbd_drv);
}
static void __exit hv_kbd_exit(void)
{
vmbus_driver_unregister(&hv_kbd_drv);
}
