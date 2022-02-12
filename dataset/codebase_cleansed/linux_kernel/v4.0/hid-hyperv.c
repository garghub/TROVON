static struct mousevsc_dev *mousevsc_alloc_device(struct hv_device *device)
{
struct mousevsc_dev *input_dev;
input_dev = kzalloc(sizeof(struct mousevsc_dev), GFP_KERNEL);
if (!input_dev)
return NULL;
input_dev->device = device;
hv_set_drvdata(device, input_dev);
init_completion(&input_dev->wait_event);
input_dev->init_complete = false;
return input_dev;
}
static void mousevsc_free_device(struct mousevsc_dev *device)
{
kfree(device->hid_desc);
kfree(device->report_desc);
hv_set_drvdata(device->device, NULL);
kfree(device);
}
static void mousevsc_on_receive_device_info(struct mousevsc_dev *input_device,
struct synthhid_device_info *device_info)
{
int ret = 0;
struct hid_descriptor *desc;
struct mousevsc_prt_msg ack;
input_device->dev_info_status = -ENOMEM;
input_device->hid_dev_info = device_info->hid_dev_info;
desc = &device_info->hid_descriptor;
if (desc->bLength == 0)
goto cleanup;
input_device->hid_desc = kmemdup(desc, desc->bLength, GFP_ATOMIC);
if (!input_device->hid_desc)
goto cleanup;
input_device->report_desc_size = desc->desc[0].wDescriptorLength;
if (input_device->report_desc_size == 0) {
input_device->dev_info_status = -EINVAL;
goto cleanup;
}
input_device->report_desc = kzalloc(input_device->report_desc_size,
GFP_ATOMIC);
if (!input_device->report_desc) {
input_device->dev_info_status = -ENOMEM;
goto cleanup;
}
memcpy(input_device->report_desc,
((unsigned char *)desc) + desc->bLength,
desc->desc[0].wDescriptorLength);
memset(&ack, 0, sizeof(struct mousevsc_prt_msg));
ack.type = PIPE_MESSAGE_DATA;
ack.size = sizeof(struct synthhid_device_info_ack);
ack.ack.header.type = SYNTH_HID_INITIAL_DEVICE_INFO_ACK;
ack.ack.header.size = 1;
ack.ack.reserved = 0;
ret = vmbus_sendpacket(input_device->device->channel,
&ack,
sizeof(struct pipe_prt_msg) - sizeof(unsigned char) +
sizeof(struct synthhid_device_info_ack),
(unsigned long)&ack,
VM_PKT_DATA_INBAND,
VMBUS_DATA_PACKET_FLAG_COMPLETION_REQUESTED);
if (!ret)
input_device->dev_info_status = 0;
cleanup:
complete(&input_device->wait_event);
return;
}
static void mousevsc_on_receive(struct hv_device *device,
struct vmpacket_descriptor *packet)
{
struct pipe_prt_msg *pipe_msg;
struct synthhid_msg *hid_msg;
struct mousevsc_dev *input_dev = hv_get_drvdata(device);
struct synthhid_input_report *input_report;
size_t len;
pipe_msg = (struct pipe_prt_msg *)((unsigned long)packet +
(packet->offset8 << 3));
if (pipe_msg->type != PIPE_MESSAGE_DATA)
return;
hid_msg = (struct synthhid_msg *)pipe_msg->data;
switch (hid_msg->header.type) {
case SYNTH_HID_PROTOCOL_RESPONSE:
if ((pipe_msg->size + sizeof(struct pipe_prt_msg)
- sizeof(unsigned char))
> sizeof(struct mousevsc_prt_msg)) {
WARN_ON(1);
break;
}
memcpy(&input_dev->protocol_resp, pipe_msg,
pipe_msg->size + sizeof(struct pipe_prt_msg) -
sizeof(unsigned char));
complete(&input_dev->wait_event);
break;
case SYNTH_HID_INITIAL_DEVICE_INFO:
WARN_ON(pipe_msg->size < sizeof(struct hv_input_dev_info));
mousevsc_on_receive_device_info(input_dev,
(struct synthhid_device_info *)pipe_msg->data);
break;
case SYNTH_HID_INPUT_REPORT:
input_report =
(struct synthhid_input_report *)pipe_msg->data;
if (!input_dev->init_complete)
break;
len = min(input_report->header.size,
(u32)sizeof(input_dev->input_buf));
memcpy(input_dev->input_buf, input_report->buffer, len);
hid_input_report(input_dev->hid_device, HID_INPUT_REPORT,
input_dev->input_buf, len, 1);
pm_wakeup_event(&input_dev->device->device, 0);
break;
default:
pr_err("unsupported hid msg type - type %d len %d",
hid_msg->header.type, hid_msg->header.size);
break;
}
}
static void mousevsc_on_channel_callback(void *context)
{
const int packet_size = 0x100;
int ret;
struct hv_device *device = context;
u32 bytes_recvd;
u64 req_id;
struct vmpacket_descriptor *desc;
unsigned char *buffer;
int bufferlen = packet_size;
buffer = kmalloc(bufferlen, GFP_ATOMIC);
if (!buffer)
return;
do {
ret = vmbus_recvpacket_raw(device->channel, buffer,
bufferlen, &bytes_recvd, &req_id);
switch (ret) {
case 0:
if (bytes_recvd <= 0) {
kfree(buffer);
return;
}
desc = (struct vmpacket_descriptor *)buffer;
switch (desc->type) {
case VM_PKT_COMP:
break;
case VM_PKT_DATA_INBAND:
mousevsc_on_receive(device, desc);
break;
default:
pr_err("unhandled packet type %d, tid %llx len %d\n",
desc->type, req_id, bytes_recvd);
break;
}
break;
case -ENOBUFS:
kfree(buffer);
bufferlen = bytes_recvd;
buffer = kmalloc(bytes_recvd, GFP_ATOMIC);
if (!buffer)
return;
break;
}
} while (1);
}
static int mousevsc_connect_to_vsp(struct hv_device *device)
{
int ret = 0;
unsigned long t;
struct mousevsc_dev *input_dev = hv_get_drvdata(device);
struct mousevsc_prt_msg *request;
struct mousevsc_prt_msg *response;
request = &input_dev->protocol_req;
memset(request, 0, sizeof(struct mousevsc_prt_msg));
request->type = PIPE_MESSAGE_DATA;
request->size = sizeof(struct synthhid_protocol_request);
request->request.header.type = SYNTH_HID_PROTOCOL_REQUEST;
request->request.header.size = sizeof(unsigned int);
request->request.version_requested.version = SYNTHHID_INPUT_VERSION;
ret = vmbus_sendpacket(device->channel, request,
sizeof(struct pipe_prt_msg) -
sizeof(unsigned char) +
sizeof(struct synthhid_protocol_request),
(unsigned long)request,
VM_PKT_DATA_INBAND,
VMBUS_DATA_PACKET_FLAG_COMPLETION_REQUESTED);
if (ret)
goto cleanup;
t = wait_for_completion_timeout(&input_dev->wait_event, 5*HZ);
if (!t) {
ret = -ETIMEDOUT;
goto cleanup;
}
response = &input_dev->protocol_resp;
if (!response->response.approved) {
pr_err("synthhid protocol request failed (version %d)\n",
SYNTHHID_INPUT_VERSION);
ret = -ENODEV;
goto cleanup;
}
t = wait_for_completion_timeout(&input_dev->wait_event, 5*HZ);
if (!t) {
ret = -ETIMEDOUT;
goto cleanup;
}
ret = input_dev->dev_info_status;
cleanup:
return ret;
}
static int mousevsc_hid_parse(struct hid_device *hid)
{
struct hv_device *dev = hid_get_drvdata(hid);
struct mousevsc_dev *input_dev = hv_get_drvdata(dev);
return hid_parse_report(hid, input_dev->report_desc,
input_dev->report_desc_size);
}
static int mousevsc_hid_open(struct hid_device *hid)
{
return 0;
}
static int mousevsc_hid_start(struct hid_device *hid)
{
return 0;
}
static void mousevsc_hid_close(struct hid_device *hid)
{
}
static void mousevsc_hid_stop(struct hid_device *hid)
{
}
static int mousevsc_hid_raw_request(struct hid_device *hid,
unsigned char report_num,
__u8 *buf, size_t len,
unsigned char rtype,
int reqtype)
{
return 0;
}
static int mousevsc_probe(struct hv_device *device,
const struct hv_vmbus_device_id *dev_id)
{
int ret;
struct mousevsc_dev *input_dev;
struct hid_device *hid_dev;
input_dev = mousevsc_alloc_device(device);
if (!input_dev)
return -ENOMEM;
ret = vmbus_open(device->channel,
INPUTVSC_SEND_RING_BUFFER_SIZE,
INPUTVSC_RECV_RING_BUFFER_SIZE,
NULL,
0,
mousevsc_on_channel_callback,
device
);
if (ret)
goto probe_err0;
ret = mousevsc_connect_to_vsp(device);
if (ret)
goto probe_err1;
if (input_dev->report_desc[14] == 0x25)
input_dev->report_desc[14] = 0x29;
hid_dev = hid_allocate_device();
if (IS_ERR(hid_dev)) {
ret = PTR_ERR(hid_dev);
goto probe_err1;
}
hid_dev->ll_driver = &mousevsc_ll_driver;
hid_dev->driver = &mousevsc_hid_driver;
hid_dev->bus = BUS_VIRTUAL;
hid_dev->vendor = input_dev->hid_dev_info.vendor;
hid_dev->product = input_dev->hid_dev_info.product;
hid_dev->version = input_dev->hid_dev_info.version;
input_dev->hid_device = hid_dev;
sprintf(hid_dev->name, "%s", "Microsoft Vmbus HID-compliant Mouse");
hid_set_drvdata(hid_dev, device);
ret = hid_add_device(hid_dev);
if (ret)
goto probe_err1;
ret = hid_parse(hid_dev);
if (ret) {
hid_err(hid_dev, "parse failed\n");
goto probe_err2;
}
ret = hid_hw_start(hid_dev, HID_CONNECT_HIDINPUT | HID_CONNECT_HIDDEV);
if (ret) {
hid_err(hid_dev, "hw start failed\n");
goto probe_err2;
}
device_init_wakeup(&device->device, true);
input_dev->connected = true;
input_dev->init_complete = true;
return ret;
probe_err2:
hid_destroy_device(hid_dev);
probe_err1:
vmbus_close(device->channel);
probe_err0:
mousevsc_free_device(input_dev);
return ret;
}
static int mousevsc_remove(struct hv_device *dev)
{
struct mousevsc_dev *input_dev = hv_get_drvdata(dev);
device_init_wakeup(&dev->device, false);
vmbus_close(dev->channel);
hid_hw_stop(input_dev->hid_device);
hid_destroy_device(input_dev->hid_device);
mousevsc_free_device(input_dev);
return 0;
}
static int __init mousevsc_init(void)
{
return vmbus_driver_register(&mousevsc_drv);
}
static void __exit mousevsc_exit(void)
{
vmbus_driver_unregister(&mousevsc_drv);
}
