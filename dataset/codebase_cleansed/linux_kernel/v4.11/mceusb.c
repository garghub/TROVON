static int mceusb_cmd_datasize(u8 cmd, u8 subcmd)
{
int datasize = 0;
switch (cmd) {
case MCE_CMD_NULL:
if (subcmd == MCE_CMD_PORT_SYS)
datasize = 1;
break;
case MCE_CMD_PORT_SYS:
switch (subcmd) {
case MCE_RSP_GETPORTSTATUS:
datasize = 5;
break;
case MCE_RSP_EQWAKEVERSION:
datasize = 4;
break;
case MCE_CMD_G_REVISION:
datasize = 2;
break;
case MCE_RSP_EQWAKESUPPORT:
case MCE_RSP_GETWAKESOURCE:
case MCE_RSP_EQDEVDETAILS:
case MCE_RSP_EQEMVER:
datasize = 1;
break;
}
case MCE_CMD_PORT_IR:
switch (subcmd) {
case MCE_CMD_UNKNOWN:
case MCE_RSP_EQIRCFS:
case MCE_RSP_EQIRTIMEOUT:
case MCE_RSP_EQIRRXCFCNT:
case MCE_RSP_EQIRNUMPORTS:
datasize = 2;
break;
case MCE_CMD_SIG_END:
case MCE_RSP_EQIRTXPORTS:
case MCE_RSP_EQIRRXPORTEN:
datasize = 1;
break;
}
}
return datasize;
}
static void mceusb_dev_printdata(struct mceusb_dev *ir, char *buf,
int offset, int len, bool out)
{
#if defined(DEBUG) || defined(CONFIG_DYNAMIC_DEBUG)
char *inout;
u8 cmd, subcmd, data1, data2, data3, data4;
struct device *dev = ir->dev;
int start, skip = 0;
u32 carrier, period;
if (ir->flags.microsoft_gen1 && !out && !offset)
skip = 2;
if (len <= skip)
return;
dev_dbg(dev, "%cx data: %*ph (length=%d)",
(out ? 't' : 'r'), min(len, USB_BUFLEN), buf, len);
inout = out ? "Request" : "Got";
start = offset + skip;
cmd = buf[start] & 0xff;
subcmd = buf[start + 1] & 0xff;
data1 = buf[start + 2] & 0xff;
data2 = buf[start + 3] & 0xff;
data3 = buf[start + 4] & 0xff;
data4 = buf[start + 5] & 0xff;
switch (cmd) {
case MCE_CMD_NULL:
if (subcmd == MCE_CMD_NULL)
break;
if ((subcmd == MCE_CMD_PORT_SYS) &&
(data1 == MCE_CMD_RESUME))
dev_dbg(dev, "Device resume requested");
else
dev_dbg(dev, "Unknown command 0x%02x 0x%02x",
cmd, subcmd);
break;
case MCE_CMD_PORT_SYS:
switch (subcmd) {
case MCE_RSP_EQEMVER:
if (!out)
dev_dbg(dev, "Emulator interface version %x",
data1);
break;
case MCE_CMD_G_REVISION:
if (len == 2)
dev_dbg(dev, "Get hw/sw rev?");
else
dev_dbg(dev, "hw/sw rev %*ph",
4, &buf[start + 2]);
break;
case MCE_CMD_RESUME:
dev_dbg(dev, "Device resume requested");
break;
case MCE_RSP_CMD_ILLEGAL:
dev_dbg(dev, "Illegal PORT_SYS command");
break;
case MCE_RSP_EQWAKEVERSION:
if (!out)
dev_dbg(dev, "Wake version, proto: 0x%02x, payload: 0x%02x, address: 0x%02x, version: 0x%02x",
data1, data2, data3, data4);
break;
case MCE_RSP_GETPORTSTATUS:
if (!out)
dev_dbg(dev, "TX port %d: blaster is%s connected",
data1 + 1, data4 ? " not" : "");
break;
case MCE_CMD_FLASHLED:
dev_dbg(dev, "Attempting to flash LED");
break;
default:
dev_dbg(dev, "Unknown command 0x%02x 0x%02x",
cmd, subcmd);
break;
}
break;
case MCE_CMD_PORT_IR:
switch (subcmd) {
case MCE_CMD_SIG_END:
dev_dbg(dev, "End of signal");
break;
case MCE_CMD_PING:
dev_dbg(dev, "Ping");
break;
case MCE_CMD_UNKNOWN:
dev_dbg(dev, "Resp to 9f 05 of 0x%02x 0x%02x",
data1, data2);
break;
case MCE_RSP_EQIRCFS:
period = DIV_ROUND_CLOSEST(
(1U << data1 * 2) * (data2 + 1), 10);
if (!period)
break;
carrier = (1000 * 1000) / period;
dev_dbg(dev, "%s carrier of %u Hz (period %uus)",
inout, carrier, period);
break;
case MCE_CMD_GETIRCFS:
dev_dbg(dev, "Get carrier mode and freq");
break;
case MCE_RSP_EQIRTXPORTS:
dev_dbg(dev, "%s transmit blaster mask of 0x%02x",
inout, data1);
break;
case MCE_RSP_EQIRTIMEOUT:
period = ((data1 << 8) | data2) * MCE_TIME_UNIT / 1000;
dev_dbg(dev, "%s receive timeout of %d ms",
inout, period);
break;
case MCE_CMD_GETIRTIMEOUT:
dev_dbg(dev, "Get receive timeout");
break;
case MCE_CMD_GETIRTXPORTS:
dev_dbg(dev, "Get transmit blaster mask");
break;
case MCE_RSP_EQIRRXPORTEN:
dev_dbg(dev, "%s %s-range receive sensor in use",
inout, data1 == 0x02 ? "short" : "long");
break;
case MCE_CMD_GETIRRXPORTEN:
if (out)
dev_dbg(dev, "Get receive sensor");
else if (ir->learning_enabled)
dev_dbg(dev, "RX pulse count: %d",
((data1 << 8) | data2));
break;
case MCE_RSP_EQIRNUMPORTS:
if (out)
break;
dev_dbg(dev, "Num TX ports: %x, num RX ports: %x",
data1, data2);
break;
case MCE_RSP_CMD_ILLEGAL:
dev_dbg(dev, "Illegal PORT_IR command");
break;
default:
dev_dbg(dev, "Unknown command 0x%02x 0x%02x",
cmd, subcmd);
break;
}
break;
default:
break;
}
if (cmd == MCE_IRDATA_TRAILER)
dev_dbg(dev, "End of raw IR data");
else if ((cmd != MCE_CMD_PORT_IR) &&
((cmd & MCE_PORT_MASK) == MCE_COMMAND_IRDATA))
dev_dbg(dev, "Raw IR data, %d pulse/space samples", ir->rem);
#endif
}
static void mce_async_callback(struct urb *urb)
{
struct mceusb_dev *ir;
int len;
if (!urb)
return;
ir = urb->context;
switch (urb->status) {
case 0:
len = urb->actual_length;
mceusb_dev_printdata(ir, urb->transfer_buffer, 0, len, true);
break;
case -ECONNRESET:
case -ENOENT:
case -EILSEQ:
case -ESHUTDOWN:
break;
case -EPIPE:
default:
dev_err(ir->dev, "Error: request urb status = %d", urb->status);
break;
}
kfree(urb->transfer_buffer);
usb_free_urb(urb);
}
static void mce_request_packet(struct mceusb_dev *ir, unsigned char *data,
int size)
{
int res, pipe;
struct urb *async_urb;
struct device *dev = ir->dev;
unsigned char *async_buf;
async_urb = usb_alloc_urb(0, GFP_KERNEL);
if (unlikely(!async_urb)) {
dev_err(dev, "Error, couldn't allocate urb!\n");
return;
}
async_buf = kmalloc(size, GFP_KERNEL);
if (!async_buf) {
usb_free_urb(async_urb);
return;
}
if (usb_endpoint_xfer_int(ir->usb_ep_out)) {
pipe = usb_sndintpipe(ir->usbdev,
ir->usb_ep_out->bEndpointAddress);
usb_fill_int_urb(async_urb, ir->usbdev, pipe, async_buf,
size, mce_async_callback, ir,
ir->usb_ep_out->bInterval);
} else {
pipe = usb_sndbulkpipe(ir->usbdev,
ir->usb_ep_out->bEndpointAddress);
usb_fill_bulk_urb(async_urb, ir->usbdev, pipe,
async_buf, size, mce_async_callback,
ir);
}
memcpy(async_buf, data, size);
dev_dbg(dev, "receive request called (size=%#x)", size);
async_urb->transfer_buffer_length = size;
async_urb->dev = ir->usbdev;
res = usb_submit_urb(async_urb, GFP_ATOMIC);
if (res) {
dev_err(dev, "receive request FAILED! (res=%d)", res);
return;
}
dev_dbg(dev, "receive request complete (res=%d)", res);
}
static void mce_async_out(struct mceusb_dev *ir, unsigned char *data, int size)
{
int rsize = sizeof(DEVICE_RESUME);
if (ir->need_reset) {
ir->need_reset = false;
mce_request_packet(ir, DEVICE_RESUME, rsize);
msleep(10);
}
mce_request_packet(ir, data, size);
msleep(10);
}
static int mceusb_tx_ir(struct rc_dev *dev, unsigned *txbuf, unsigned count)
{
struct mceusb_dev *ir = dev->priv;
int i, length, ret = 0;
int cmdcount = 0;
unsigned char cmdbuf[MCE_CMDBUF_SIZE];
cmdbuf[cmdcount++] = MCE_CMD_PORT_IR;
cmdbuf[cmdcount++] = MCE_CMD_SETIRTXPORTS;
cmdbuf[cmdcount++] = ir->tx_mask;
mce_async_out(ir, cmdbuf, cmdcount);
cmdcount = 0;
for (i = 0; (i < count) && (cmdcount < MCE_CMDBUF_SIZE); i++) {
txbuf[i] = txbuf[i] / MCE_TIME_UNIT;
do {
if ((cmdcount < MCE_CMDBUF_SIZE) &&
(cmdcount % MCE_CODE_LENGTH) == 0)
cmdbuf[cmdcount++] = MCE_IRDATA_HEADER;
if (cmdcount < MCE_CMDBUF_SIZE)
cmdbuf[cmdcount++] =
(txbuf[i] < MCE_PULSE_BIT ?
txbuf[i] : MCE_MAX_PULSE_LENGTH) |
(i & 1 ? 0x00 : MCE_PULSE_BIT);
else {
ret = -EINVAL;
goto out;
}
} while ((txbuf[i] > MCE_MAX_PULSE_LENGTH) &&
(txbuf[i] -= MCE_MAX_PULSE_LENGTH));
}
if (cmdcount >= MCE_CMDBUF_SIZE) {
ret = -EINVAL;
goto out;
}
length = cmdcount % MCE_CODE_LENGTH;
cmdbuf[cmdcount - length] -= MCE_CODE_LENGTH - length;
cmdbuf[cmdcount++] = MCE_IRDATA_TRAILER;
mce_async_out(ir, cmdbuf, cmdcount);
out:
return ret ? ret : count;
}
static int mceusb_set_tx_mask(struct rc_dev *dev, u32 mask)
{
struct mceusb_dev *ir = dev->priv;
int emitters = ir->num_txports ? ir->num_txports : 2;
if (mask >= (1 << emitters))
return emitters;
if (ir->flags.tx_mask_normal)
ir->tx_mask = mask;
else
ir->tx_mask = (mask != MCE_DEFAULT_TX_MASK ?
mask ^ MCE_DEFAULT_TX_MASK : mask) << 1;
return 0;
}
static int mceusb_set_tx_carrier(struct rc_dev *dev, u32 carrier)
{
struct mceusb_dev *ir = dev->priv;
int clk = 10000000;
int prescaler = 0, divisor = 0;
unsigned char cmdbuf[4] = { MCE_CMD_PORT_IR,
MCE_CMD_SETIRCFS, 0x00, 0x00 };
if (ir->carrier != carrier) {
if (carrier == 0) {
ir->carrier = carrier;
cmdbuf[2] = MCE_CMD_SIG_END;
cmdbuf[3] = MCE_IRDATA_TRAILER;
dev_dbg(ir->dev, "disabling carrier modulation");
mce_async_out(ir, cmdbuf, sizeof(cmdbuf));
return 0;
}
for (prescaler = 0; prescaler < 4; ++prescaler) {
divisor = (clk >> (2 * prescaler)) / carrier;
if (divisor <= 0xff) {
ir->carrier = carrier;
cmdbuf[2] = prescaler;
cmdbuf[3] = divisor;
dev_dbg(ir->dev, "requesting %u HZ carrier",
carrier);
mce_async_out(ir, cmdbuf, sizeof(cmdbuf));
return 0;
}
}
return -EINVAL;
}
return 0;
}
static void mceusb_handle_command(struct mceusb_dev *ir, int index)
{
u8 hi = ir->buf_in[index + 1] & 0xff;
u8 lo = ir->buf_in[index + 2] & 0xff;
switch (ir->buf_in[index]) {
case MCE_RSP_GETPORTSTATUS:
if ((ir->buf_in[index + 4] & 0xff) == 0x00)
ir->txports_cabled |= 1 << hi;
break;
case MCE_RSP_EQIRTIMEOUT:
ir->rc->timeout = US_TO_NS((hi << 8 | lo) * MCE_TIME_UNIT);
break;
case MCE_RSP_EQIRNUMPORTS:
ir->num_txports = hi;
ir->num_rxports = lo;
break;
case MCE_RSP_EQEMVER:
ir->emver = hi;
break;
case MCE_RSP_EQIRTXPORTS:
ir->tx_mask = hi;
break;
case MCE_RSP_EQIRRXPORTEN:
ir->learning_enabled = ((hi & 0x02) == 0x02);
ir->rxports_active = hi;
break;
case MCE_RSP_CMD_ILLEGAL:
ir->need_reset = true;
break;
default:
break;
}
}
static void mceusb_process_ir_data(struct mceusb_dev *ir, int buf_len)
{
DEFINE_IR_RAW_EVENT(rawir);
bool event = false;
int i = 0;
if (ir->flags.microsoft_gen1)
i = 2;
if (buf_len <= i)
return;
for (; i < buf_len; i++) {
switch (ir->parser_state) {
case SUBCMD:
ir->rem = mceusb_cmd_datasize(ir->cmd, ir->buf_in[i]);
mceusb_dev_printdata(ir, ir->buf_in, i - 1,
ir->rem + 2, false);
mceusb_handle_command(ir, i);
ir->parser_state = CMD_DATA;
break;
case PARSE_IRDATA:
ir->rem--;
init_ir_raw_event(&rawir);
rawir.pulse = ((ir->buf_in[i] & MCE_PULSE_BIT) != 0);
rawir.duration = (ir->buf_in[i] & MCE_PULSE_MASK)
* US_TO_NS(MCE_TIME_UNIT);
dev_dbg(ir->dev, "Storing %s with duration %d",
rawir.pulse ? "pulse" : "space",
rawir.duration);
if (ir_raw_event_store_with_filter(ir->rc, &rawir))
event = true;
break;
case CMD_DATA:
ir->rem--;
break;
case CMD_HEADER:
ir->cmd = ir->buf_in[i];
if ((ir->cmd == MCE_CMD_PORT_IR) ||
((ir->cmd & MCE_PORT_MASK) !=
MCE_COMMAND_IRDATA)) {
ir->parser_state = SUBCMD;
continue;
}
ir->rem = (ir->cmd & MCE_PACKET_LENGTH_MASK);
mceusb_dev_printdata(ir, ir->buf_in,
i, ir->rem + 1, false);
if (ir->rem)
ir->parser_state = PARSE_IRDATA;
else
ir_raw_event_reset(ir->rc);
break;
}
if (ir->parser_state != CMD_HEADER && !ir->rem)
ir->parser_state = CMD_HEADER;
}
if (event) {
dev_dbg(ir->dev, "processed IR data");
ir_raw_event_handle(ir->rc);
}
}
static void mceusb_dev_recv(struct urb *urb)
{
struct mceusb_dev *ir;
if (!urb)
return;
ir = urb->context;
if (!ir) {
usb_unlink_urb(urb);
return;
}
switch (urb->status) {
case 0:
mceusb_process_ir_data(ir, urb->actual_length);
break;
case -ECONNRESET:
case -ENOENT:
case -EILSEQ:
case -ESHUTDOWN:
usb_unlink_urb(urb);
return;
case -EPIPE:
default:
dev_err(ir->dev, "Error: urb status = %d", urb->status);
break;
}
usb_submit_urb(urb, GFP_ATOMIC);
}
static void mceusb_get_emulator_version(struct mceusb_dev *ir)
{
ir->emver = 1;
mce_async_out(ir, GET_EMVER, sizeof(GET_EMVER));
}
static void mceusb_gen1_init(struct mceusb_dev *ir)
{
int ret;
struct device *dev = ir->dev;
char *data;
data = kzalloc(USB_CTRL_MSG_SZ, GFP_KERNEL);
if (!data) {
dev_err(dev, "%s: memory allocation failed!", __func__);
return;
}
ret = usb_control_msg(ir->usbdev, usb_rcvctrlpipe(ir->usbdev, 0),
USB_REQ_SET_ADDRESS, USB_TYPE_VENDOR, 0, 0,
data, USB_CTRL_MSG_SZ, HZ * 3);
dev_dbg(dev, "set address - ret = %d", ret);
dev_dbg(dev, "set address - data[0] = %d, data[1] = %d",
data[0], data[1]);
ret = usb_control_msg(ir->usbdev, usb_sndctrlpipe(ir->usbdev, 0),
USB_REQ_SET_FEATURE, USB_TYPE_VENDOR,
0xc04e, 0x0000, NULL, 0, HZ * 3);
dev_dbg(dev, "set feature - ret = %d", ret);
ret = usb_control_msg(ir->usbdev, usb_sndctrlpipe(ir->usbdev, 0),
4, USB_TYPE_VENDOR,
0x0808, 0x0000, NULL, 0, HZ * 3);
dev_dbg(dev, "set char length - retB = %d", ret);
ret = usb_control_msg(ir->usbdev, usb_sndctrlpipe(ir->usbdev, 0),
2, USB_TYPE_VENDOR,
0x0000, 0x0100, NULL, 0, HZ * 3);
dev_dbg(dev, "set handshake - retC = %d", ret);
mce_async_out(ir, DEVICE_RESUME, sizeof(DEVICE_RESUME));
mce_async_out(ir, GET_REVISION, sizeof(GET_REVISION));
kfree(data);
}
static void mceusb_gen2_init(struct mceusb_dev *ir)
{
mce_async_out(ir, DEVICE_RESUME, sizeof(DEVICE_RESUME));
mce_async_out(ir, GET_WAKEVERSION, sizeof(GET_WAKEVERSION));
mce_async_out(ir, GET_UNKNOWN2, sizeof(GET_UNKNOWN2));
}
static void mceusb_get_parameters(struct mceusb_dev *ir)
{
int i;
unsigned char cmdbuf[3] = { MCE_CMD_PORT_SYS,
MCE_CMD_GETPORTSTATUS, 0x00 };
ir->num_txports = 2;
ir->num_rxports = 2;
mce_async_out(ir, GET_NUM_PORTS, sizeof(GET_NUM_PORTS));
mce_async_out(ir, GET_CARRIER_FREQ, sizeof(GET_CARRIER_FREQ));
if (ir->num_txports && !ir->flags.no_tx)
mce_async_out(ir, GET_TX_BITMASK, sizeof(GET_TX_BITMASK));
mce_async_out(ir, GET_RX_TIMEOUT, sizeof(GET_RX_TIMEOUT));
mce_async_out(ir, GET_RX_SENSOR, sizeof(GET_RX_SENSOR));
for (i = 0; i < ir->num_txports; i++) {
cmdbuf[2] = i;
mce_async_out(ir, cmdbuf, sizeof(cmdbuf));
}
}
static void mceusb_flash_led(struct mceusb_dev *ir)
{
if (ir->emver < 2)
return;
mce_async_out(ir, FLASH_LED, sizeof(FLASH_LED));
}
static struct rc_dev *mceusb_init_rc_dev(struct mceusb_dev *ir)
{
struct usb_device *udev = ir->usbdev;
struct device *dev = ir->dev;
struct rc_dev *rc;
int ret;
rc = rc_allocate_device(RC_DRIVER_IR_RAW);
if (!rc) {
dev_err(dev, "remote dev allocation failed");
goto out;
}
snprintf(ir->name, sizeof(ir->name), "%s (%04x:%04x)",
mceusb_model[ir->model].name ?
mceusb_model[ir->model].name :
"Media Center Ed. eHome Infrared Remote Transceiver",
le16_to_cpu(ir->usbdev->descriptor.idVendor),
le16_to_cpu(ir->usbdev->descriptor.idProduct));
usb_make_path(ir->usbdev, ir->phys, sizeof(ir->phys));
rc->input_name = ir->name;
rc->input_phys = ir->phys;
usb_to_input_id(ir->usbdev, &rc->input_id);
rc->dev.parent = dev;
rc->priv = ir;
rc->allowed_protocols = RC_BIT_ALL_IR_DECODER;
rc->timeout = MS_TO_NS(100);
if (!ir->flags.no_tx) {
rc->s_tx_mask = mceusb_set_tx_mask;
rc->s_tx_carrier = mceusb_set_tx_carrier;
rc->tx_ir = mceusb_tx_ir;
}
rc->driver_name = DRIVER_NAME;
switch (le16_to_cpu(udev->descriptor.idVendor)) {
case VENDOR_HAUPPAUGE:
rc->map_name = RC_MAP_HAUPPAUGE;
break;
case VENDOR_PCTV:
rc->map_name = RC_MAP_PINNACLE_PCTV_HD;
break;
default:
rc->map_name = RC_MAP_RC6_MCE;
}
if (mceusb_model[ir->model].rc_map)
rc->map_name = mceusb_model[ir->model].rc_map;
ret = rc_register_device(rc);
if (ret < 0) {
dev_err(dev, "remote dev registration failed");
goto out;
}
return rc;
out:
rc_free_device(rc);
return NULL;
}
static int mceusb_dev_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
struct usb_device *dev = interface_to_usbdev(intf);
struct usb_host_interface *idesc;
struct usb_endpoint_descriptor *ep = NULL;
struct usb_endpoint_descriptor *ep_in = NULL;
struct usb_endpoint_descriptor *ep_out = NULL;
struct mceusb_dev *ir = NULL;
int pipe, maxp, i, res;
char buf[63], name[128] = "";
enum mceusb_model_type model = id->driver_info;
bool is_gen3;
bool is_microsoft_gen1;
bool tx_mask_normal;
int ir_intfnum;
dev_dbg(&intf->dev, "%s called", __func__);
idesc = intf->cur_altsetting;
is_gen3 = mceusb_model[model].mce_gen3;
is_microsoft_gen1 = mceusb_model[model].mce_gen1;
tx_mask_normal = mceusb_model[model].tx_mask_normal;
ir_intfnum = mceusb_model[model].ir_intfnum;
if (idesc->desc.bInterfaceNumber != ir_intfnum)
return -ENODEV;
for (i = 0; i < idesc->desc.bNumEndpoints; ++i) {
ep = &idesc->endpoint[i].desc;
if (ep_in == NULL) {
if (usb_endpoint_is_bulk_in(ep)) {
ep_in = ep;
dev_dbg(&intf->dev, "acceptable bulk inbound endpoint found\n");
} else if (usb_endpoint_is_int_in(ep)) {
ep_in = ep;
ep_in->bInterval = 1;
dev_dbg(&intf->dev, "acceptable interrupt inbound endpoint found\n");
}
}
if (ep_out == NULL) {
if (usb_endpoint_is_bulk_out(ep)) {
ep_out = ep;
dev_dbg(&intf->dev, "acceptable bulk outbound endpoint found\n");
} else if (usb_endpoint_is_int_out(ep)) {
ep_out = ep;
ep_out->bInterval = 1;
dev_dbg(&intf->dev, "acceptable interrupt outbound endpoint found\n");
}
}
}
if (ep_in == NULL) {
dev_dbg(&intf->dev, "inbound and/or endpoint not found");
return -ENODEV;
}
if (usb_endpoint_xfer_int(ep_in))
pipe = usb_rcvintpipe(dev, ep_in->bEndpointAddress);
else
pipe = usb_rcvbulkpipe(dev, ep_in->bEndpointAddress);
maxp = usb_maxpacket(dev, pipe, usb_pipeout(pipe));
ir = kzalloc(sizeof(struct mceusb_dev), GFP_KERNEL);
if (!ir)
goto mem_alloc_fail;
ir->buf_in = usb_alloc_coherent(dev, maxp, GFP_ATOMIC, &ir->dma_in);
if (!ir->buf_in)
goto buf_in_alloc_fail;
ir->urb_in = usb_alloc_urb(0, GFP_KERNEL);
if (!ir->urb_in)
goto urb_in_alloc_fail;
ir->usbdev = usb_get_dev(dev);
ir->dev = &intf->dev;
ir->len_in = maxp;
ir->flags.microsoft_gen1 = is_microsoft_gen1;
ir->flags.tx_mask_normal = tx_mask_normal;
ir->flags.no_tx = mceusb_model[model].no_tx;
ir->model = model;
ir->usb_ep_out = ep_out;
if (dev->descriptor.iManufacturer
&& usb_string(dev, dev->descriptor.iManufacturer,
buf, sizeof(buf)) > 0)
strlcpy(name, buf, sizeof(name));
if (dev->descriptor.iProduct
&& usb_string(dev, dev->descriptor.iProduct,
buf, sizeof(buf)) > 0)
snprintf(name + strlen(name), sizeof(name) - strlen(name),
" %s", buf);
ir->rc = mceusb_init_rc_dev(ir);
if (!ir->rc)
goto rc_dev_fail;
usb_fill_int_urb(ir->urb_in, dev, pipe, ir->buf_in, maxp,
mceusb_dev_recv, ir, ep_in->bInterval);
ir->urb_in->transfer_dma = ir->dma_in;
ir->urb_in->transfer_flags |= URB_NO_TRANSFER_DMA_MAP;
dev_dbg(&intf->dev, "Flushing receive buffers\n");
res = usb_submit_urb(ir->urb_in, GFP_KERNEL);
if (res)
dev_err(&intf->dev, "failed to flush buffers: %d\n", res);
mceusb_get_emulator_version(ir);
if (ir->flags.microsoft_gen1)
mceusb_gen1_init(ir);
else if (!is_gen3)
mceusb_gen2_init(ir);
mceusb_get_parameters(ir);
mceusb_flash_led(ir);
if (!ir->flags.no_tx)
mceusb_set_tx_mask(ir->rc, MCE_DEFAULT_TX_MASK);
usb_set_intfdata(intf, ir);
device_set_wakeup_capable(ir->dev, true);
device_set_wakeup_enable(ir->dev, true);
dev_info(&intf->dev, "Registered %s with mce emulator interface version %x",
name, ir->emver);
dev_info(&intf->dev, "%x tx ports (0x%x cabled) and %x rx sensors (0x%x active)",
ir->num_txports, ir->txports_cabled,
ir->num_rxports, ir->rxports_active);
return 0;
rc_dev_fail:
usb_put_dev(ir->usbdev);
usb_kill_urb(ir->urb_in);
usb_free_urb(ir->urb_in);
urb_in_alloc_fail:
usb_free_coherent(dev, maxp, ir->buf_in, ir->dma_in);
buf_in_alloc_fail:
kfree(ir);
mem_alloc_fail:
dev_err(&intf->dev, "%s: device setup failed!", __func__);
return -ENOMEM;
}
static void mceusb_dev_disconnect(struct usb_interface *intf)
{
struct usb_device *dev = interface_to_usbdev(intf);
struct mceusb_dev *ir = usb_get_intfdata(intf);
usb_set_intfdata(intf, NULL);
if (!ir)
return;
ir->usbdev = NULL;
rc_unregister_device(ir->rc);
usb_kill_urb(ir->urb_in);
usb_free_urb(ir->urb_in);
usb_free_coherent(dev, ir->len_in, ir->buf_in, ir->dma_in);
usb_put_dev(dev);
kfree(ir);
}
static int mceusb_dev_suspend(struct usb_interface *intf, pm_message_t message)
{
struct mceusb_dev *ir = usb_get_intfdata(intf);
dev_info(ir->dev, "suspend");
usb_kill_urb(ir->urb_in);
return 0;
}
static int mceusb_dev_resume(struct usb_interface *intf)
{
struct mceusb_dev *ir = usb_get_intfdata(intf);
dev_info(ir->dev, "resume");
if (usb_submit_urb(ir->urb_in, GFP_ATOMIC))
return -EIO;
return 0;
}
