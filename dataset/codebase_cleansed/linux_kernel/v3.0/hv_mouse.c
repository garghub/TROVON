static struct mousevsc_dev *alloc_input_device(struct hv_device *device)
{
struct mousevsc_dev *input_dev;
input_dev = kzalloc(sizeof(struct mousevsc_dev), GFP_KERNEL);
if (!input_dev)
return NULL;
atomic_cmpxchg(&input_dev->ref_count, 0, 2);
input_dev->device = device;
device->ext = input_dev;
return input_dev;
}
static void free_input_device(struct mousevsc_dev *device)
{
WARN_ON(atomic_read(&device->ref_count) == 0);
kfree(device);
}
static struct mousevsc_dev *get_input_device(struct hv_device *device)
{
struct mousevsc_dev *input_dev;
input_dev = (struct mousevsc_dev *)device->ext;
if (input_dev && atomic_read(&input_dev->ref_count) > 1)
atomic_inc(&input_dev->ref_count);
else
input_dev = NULL;
return input_dev;
}
static struct mousevsc_dev *must_get_input_device(struct hv_device *device)
{
struct mousevsc_dev *input_dev;
input_dev = (struct mousevsc_dev *)device->ext;
if (input_dev && atomic_read(&input_dev->ref_count))
atomic_inc(&input_dev->ref_count);
else
input_dev = NULL;
return input_dev;
}
static void put_input_device(struct hv_device *device)
{
struct mousevsc_dev *input_dev;
input_dev = (struct mousevsc_dev *)device->ext;
atomic_dec(&input_dev->ref_count);
}
static struct mousevsc_dev *release_input_device(struct hv_device *device)
{
struct mousevsc_dev *input_dev;
input_dev = (struct mousevsc_dev *)device->ext;
while (atomic_cmpxchg(&input_dev->ref_count, 2, 1) != 2)
udelay(100);
return input_dev;
}
static struct mousevsc_dev *final_release_input_device(struct hv_device *device)
{
struct mousevsc_dev *input_dev;
input_dev = (struct mousevsc_dev *)device->ext;
while (atomic_cmpxchg(&input_dev->ref_count, 1, 0) != 1)
udelay(100);
device->ext = NULL;
return input_dev;
}
static void mousevsc_on_send_completion(struct hv_device *device,
struct vmpacket_descriptor *packet)
{
struct mousevsc_dev *input_dev;
void *request;
input_dev = must_get_input_device(device);
if (!input_dev) {
pr_err("unable to get input device...device being destroyed?");
return;
}
request = (void *)(unsigned long)packet->trans_id;
if (request == &input_dev->protocol_req) {
}
put_input_device(device);
}
static void mousevsc_on_receive_device_info(struct mousevsc_dev *input_device,
struct synthhid_device_info *device_info)
{
int ret = 0;
struct hid_descriptor *desc;
struct mousevsc_prt_msg ack;
input_device->dev_info_status = 0;
memcpy(&input_device->hid_dev_info, &device_info->hid_dev_info,
sizeof(struct hv_input_dev_info));
desc = &device_info->hid_descriptor;
WARN_ON(desc->bLength > 0);
input_device->hid_desc = kzalloc(desc->bLength, GFP_KERNEL);
if (!input_device->hid_desc) {
pr_err("unable to allocate hid descriptor - size %d", desc->bLength);
goto Cleanup;
}
memcpy(input_device->hid_desc, desc, desc->bLength);
input_device->report_desc_size = desc->desc[0].wDescriptorLength;
input_device->report_desc = kzalloc(input_device->report_desc_size,
GFP_KERNEL);
if (!input_device->report_desc) {
pr_err("unable to allocate report descriptor - size %d",
input_device->report_desc_size);
goto Cleanup;
}
memcpy(input_device->report_desc,
((unsigned char *)desc) + desc->bLength,
desc->desc[0].wDescriptorLength);
memset(&ack, 0, sizeof(struct mousevsc_prt_msg));
ack.type = PipeMessageData;
ack.size = sizeof(struct synthhid_device_info_ack);
ack.ack.header.type = SynthHidInitialDeviceInfoAck;
ack.ack.header.size = 1;
ack.ack.reserved = 0;
ret = vmbus_sendpacket(input_device->device->channel,
&ack,
sizeof(struct pipe_prt_msg) - sizeof(unsigned char) +
sizeof(struct synthhid_device_info_ack),
(unsigned long)&ack,
VM_PKT_DATA_INBAND,
VMBUS_DATA_PACKET_FLAG_COMPLETION_REQUESTED);
if (ret != 0) {
pr_err("unable to send synthhid device info ack - ret %d",
ret);
goto Cleanup;
}
input_device->device_wait_condition = 1;
wake_up(&input_device->dev_info_wait_event);
return;
Cleanup:
kfree(input_device->hid_desc);
input_device->hid_desc = NULL;
kfree(input_device->report_desc);
input_device->report_desc = NULL;
input_device->dev_info_status = -1;
input_device->device_wait_condition = 1;
wake_up(&input_device->dev_info_wait_event);
}
static void mousevsc_on_receive_input_report(struct mousevsc_dev *input_device,
struct synthhid_input_report *input_report)
{
struct hv_driver *input_drv;
if (!input_device->init_complete) {
pr_info("Initialization incomplete...ignoring input_report msg");
return;
}
input_drv = drv_to_hv_drv(input_device->device->device.driver);
inputreport_callback(input_device->device,
input_report->buffer,
input_report->header.size);
}
static void mousevsc_on_receive(struct hv_device *device,
struct vmpacket_descriptor *packet)
{
struct pipe_prt_msg *pipe_msg;
struct synthhid_msg *hid_msg;
struct mousevsc_dev *input_dev;
input_dev = must_get_input_device(device);
if (!input_dev) {
pr_err("unable to get input device...device being destroyed?");
return;
}
pipe_msg = (struct pipe_prt_msg *)((unsigned long)packet +
(packet->offset8 << 3));
if (pipe_msg->type != PipeMessageData) {
pr_err("unknown pipe msg type - type %d len %d",
pipe_msg->type, pipe_msg->size);
put_input_device(device);
return ;
}
hid_msg = (struct synthhid_msg *)&pipe_msg->data[0];
switch (hid_msg->header.type) {
case SynthHidProtocolResponse:
memcpy(&input_dev->protocol_resp, pipe_msg,
pipe_msg->size + sizeof(struct pipe_prt_msg) -
sizeof(unsigned char));
input_dev->protocol_wait_condition = 1;
wake_up(&input_dev->protocol_wait_event);
break;
case SynthHidInitialDeviceInfo:
WARN_ON(pipe_msg->size >= sizeof(struct hv_input_dev_info));
mousevsc_on_receive_device_info(input_dev,
(struct synthhid_device_info *)&pipe_msg->data[0]);
break;
case SynthHidInputReport:
mousevsc_on_receive_input_report(input_dev,
(struct synthhid_input_report *)&pipe_msg->data[0]);
break;
default:
pr_err("unsupported hid msg type - type %d len %d",
hid_msg->header.type, hid_msg->header.size);
break;
}
put_input_device(device);
}
static void mousevsc_on_channel_callback(void *context)
{
const int packetSize = 0x100;
int ret = 0;
struct hv_device *device = (struct hv_device *)context;
struct mousevsc_dev *input_dev;
u32 bytes_recvd;
u64 req_id;
unsigned char packet[0x100];
struct vmpacket_descriptor *desc;
unsigned char *buffer = packet;
int bufferlen = packetSize;
input_dev = must_get_input_device(device);
if (!input_dev) {
pr_err("unable to get input device...device being destroyed?");
return;
}
do {
ret = vmbus_recvpacket_raw(device->channel, buffer,
bufferlen, &bytes_recvd, &req_id);
if (ret == 0) {
if (bytes_recvd > 0) {
desc = (struct vmpacket_descriptor *)buffer;
switch (desc->type) {
case VM_PKT_COMP:
mousevsc_on_send_completion(
device, desc);
break;
case VM_PKT_DATA_INBAND:
mousevsc_on_receive(
device, desc);
break;
default:
pr_err("unhandled packet type %d, tid %llx len %d\n",
desc->type,
req_id,
bytes_recvd);
break;
}
if (bufferlen > packetSize) {
kfree(buffer);
buffer = packet;
bufferlen = packetSize;
}
} else {
if (bufferlen > packetSize) {
kfree(buffer);
buffer = packet;
bufferlen = packetSize;
}
break;
}
} else if (ret == -2) {
bufferlen = bytes_recvd;
buffer = kzalloc(bytes_recvd, GFP_KERNEL);
if (buffer == NULL) {
buffer = packet;
bufferlen = packetSize;
pr_err("unable to allocate buffer of size %d!",
bytes_recvd);
break;
}
}
} while (1);
put_input_device(device);
return;
}
static int mousevsc_connect_to_vsp(struct hv_device *device)
{
int ret = 0;
struct mousevsc_dev *input_dev;
struct mousevsc_prt_msg *request;
struct mousevsc_prt_msg *response;
input_dev = get_input_device(device);
if (!input_dev) {
pr_err("unable to get input device...device being destroyed?");
return -1;
}
init_waitqueue_head(&input_dev->protocol_wait_event);
init_waitqueue_head(&input_dev->dev_info_wait_event);
request = &input_dev->protocol_req;
memset(request, 0, sizeof(struct mousevsc_prt_msg));
request->type = PipeMessageData;
request->size = sizeof(struct synthhid_protocol_request);
request->request.header.type = SynthHidProtocolRequest;
request->request.header.size = sizeof(unsigned long);
request->request.version_requested.version = SYNTHHID_INPUT_VERSION;
pr_info("synthhid protocol request...");
ret = vmbus_sendpacket(device->channel, request,
sizeof(struct pipe_prt_msg) -
sizeof(unsigned char) +
sizeof(struct synthhid_protocol_request),
(unsigned long)request,
VM_PKT_DATA_INBAND,
VMBUS_DATA_PACKET_FLAG_COMPLETION_REQUESTED);
if (ret != 0) {
pr_err("unable to send synthhid protocol request.");
goto Cleanup;
}
input_dev->protocol_wait_condition = 0;
wait_event_timeout(input_dev->protocol_wait_event,
input_dev->protocol_wait_condition, msecs_to_jiffies(1000));
if (input_dev->protocol_wait_condition == 0) {
ret = -ETIMEDOUT;
goto Cleanup;
}
response = &input_dev->protocol_resp;
if (!response->response.approved) {
pr_err("synthhid protocol request failed (version %d)",
SYNTHHID_INPUT_VERSION);
ret = -1;
goto Cleanup;
}
input_dev->device_wait_condition = 0;
wait_event_timeout(input_dev->dev_info_wait_event,
input_dev->device_wait_condition, msecs_to_jiffies(1000));
if (input_dev->device_wait_condition == 0) {
ret = -ETIMEDOUT;
goto Cleanup;
}
if (!input_dev->dev_info_status)
pr_info("**** input channel up and running!! ****");
else
ret = -1;
Cleanup:
put_input_device(device);
return ret;
}
static int mousevsc_on_device_add(struct hv_device *device,
void *additional_info)
{
int ret = 0;
struct mousevsc_dev *input_dev;
struct hv_driver *input_drv;
struct hv_input_dev_info dev_info;
input_dev = alloc_input_device(device);
if (!input_dev) {
ret = -1;
goto Cleanup;
}
input_dev->init_complete = false;
ret = vmbus_open(device->channel,
INPUTVSC_SEND_RING_BUFFER_SIZE,
INPUTVSC_RECV_RING_BUFFER_SIZE,
NULL,
0,
mousevsc_on_channel_callback,
device
);
if (ret != 0) {
pr_err("unable to open channel: %d", ret);
free_input_device(input_dev);
return -1;
}
pr_info("InputVsc channel open: %d", ret);
ret = mousevsc_connect_to_vsp(device);
if (ret != 0) {
pr_err("unable to connect channel: %d", ret);
vmbus_close(device->channel);
free_input_device(input_dev);
return ret;
}
input_drv = drv_to_hv_drv(input_dev->device->device.driver);
dev_info.vendor = input_dev->hid_dev_info.vendor;
dev_info.product = input_dev->hid_dev_info.product;
dev_info.version = input_dev->hid_dev_info.version;
strcpy(dev_info.name, "Microsoft Vmbus HID-compliant Mouse");
deviceinfo_callback(device, &dev_info);
if (input_dev->report_desc[14] == 0x25)
input_dev->report_desc[14] = 0x29;
reportdesc_callback(device, input_dev->report_desc,
input_dev->report_desc_size);
input_dev->init_complete = true;
Cleanup:
return ret;
}
static int mousevsc_on_device_remove(struct hv_device *device)
{
struct mousevsc_dev *input_dev;
int ret = 0;
pr_info("disabling input device (%p)...",
device->ext);
input_dev = release_input_device(device);
while (input_dev->num_outstanding_req) {
pr_info("waiting for %d requests to complete...",
input_dev->num_outstanding_req);
udelay(100);
}
pr_info("removing input device (%p)...", device->ext);
input_dev = final_release_input_device(device);
pr_info("input device (%p) safe to remove", input_dev);
vmbus_close(device->channel);
free_input_device(input_dev);
return ret;
}
static void deviceinfo_callback(struct hv_device *dev, struct hv_input_dev_info *info)
{
struct input_device_context *input_device_ctx =
dev_get_drvdata(&dev->device);
memcpy(&input_device_ctx->device_info, info,
sizeof(struct hv_input_dev_info));
DPRINT_INFO(INPUTVSC_DRV, "%s", __func__);
}
static void inputreport_callback(struct hv_device *dev, void *packet, u32 len)
{
int ret = 0;
struct input_device_context *input_dev_ctx =
dev_get_drvdata(&dev->device);
ret = hid_input_report(input_dev_ctx->hid_device,
HID_INPUT_REPORT, packet, len, 1);
DPRINT_DBG(INPUTVSC_DRV, "hid_input_report (ret %d)", ret);
}
static int mousevsc_hid_open(struct hid_device *hid)
{
return 0;
}
static void mousevsc_hid_close(struct hid_device *hid)
{
}
static int mousevsc_probe(struct hv_device *dev)
{
int ret = 0;
struct input_device_context *input_dev_ctx;
input_dev_ctx = kmalloc(sizeof(struct input_device_context),
GFP_KERNEL);
dev_set_drvdata(&dev->device, input_dev_ctx);
ret = mousevsc_on_device_add(dev, NULL);
if (ret != 0) {
DPRINT_ERR(INPUTVSC_DRV, "unable to add input vsc device");
return -1;
}
return 0;
}
static int mousevsc_remove(struct hv_device *dev)
{
int ret = 0;
struct input_device_context *input_dev_ctx;
input_dev_ctx = kmalloc(sizeof(struct input_device_context),
GFP_KERNEL);
dev_set_drvdata(&dev->device, input_dev_ctx);
if (input_dev_ctx->connected) {
hidinput_disconnect(input_dev_ctx->hid_device);
input_dev_ctx->connected = 0;
}
ret = mousevsc_on_device_remove(dev);
if (ret != 0) {
DPRINT_ERR(INPUTVSC_DRV,
"unable to remove vsc device (ret %d)", ret);
}
kfree(input_dev_ctx);
return ret;
}
static void reportdesc_callback(struct hv_device *dev, void *packet, u32 len)
{
struct input_device_context *input_device_ctx =
dev_get_drvdata(&dev->device);
struct hid_device *hid_dev;
hid_dev = kmalloc(sizeof(struct hid_device), GFP_KERNEL);
if (hid_parse_report(hid_dev, packet, len)) {
DPRINT_INFO(INPUTVSC_DRV, "Unable to call hd_parse_report");
return;
}
if (hid_dev) {
DPRINT_INFO(INPUTVSC_DRV, "hid_device created");
hid_dev->ll_driver->open = mousevsc_hid_open;
hid_dev->ll_driver->close = mousevsc_hid_close;
hid_dev->bus = BUS_VIRTUAL;
hid_dev->vendor = input_device_ctx->device_info.vendor;
hid_dev->product = input_device_ctx->device_info.product;
hid_dev->version = input_device_ctx->device_info.version;
hid_dev->dev = dev->device;
sprintf(hid_dev->name, "%s",
input_device_ctx->device_info.name);
if (!hidinput_connect(hid_dev, 0)) {
hid_dev->claimed |= HID_CLAIMED_INPUT;
input_device_ctx->connected = 1;
DPRINT_INFO(INPUTVSC_DRV,
"HID device claimed by input\n");
}
if (!hid_dev->claimed) {
DPRINT_ERR(INPUTVSC_DRV,
"HID device not claimed by "
"input or hiddev\n");
}
input_device_ctx->hid_device = hid_dev;
}
kfree(hid_dev);
}
static void mousevsc_drv_exit(void)
{
vmbus_child_driver_unregister(&mousevsc_drv.driver);
}
static int __init mousevsc_init(void)
{
struct hv_driver *drv = &mousevsc_drv;
DPRINT_INFO(INPUTVSC_DRV, "Hyper-V Mouse driver initializing.");
memcpy(&drv->dev_type, &mouse_guid,
sizeof(struct hv_guid));
drv->driver.name = driver_name;
drv->name = driver_name;
vmbus_child_driver_register(&drv->driver);
return 0;
}
static void __exit mousevsc_exit(void)
{
mousevsc_drv_exit();
}
