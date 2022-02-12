static void redrat3_issue_async(struct redrat3_dev *rr3)
{
int res;
res = usb_submit_urb(rr3->read_urb, GFP_ATOMIC);
if (res)
dev_dbg(rr3->dev,
"%s: receive request FAILED! (res %d, len %d)\n",
__func__, res, rr3->read_urb->transfer_buffer_length);
}
static void redrat3_dump_fw_error(struct redrat3_dev *rr3, int code)
{
if (!rr3->transmitting && (code != 0x40))
dev_info(rr3->dev, "fw error code 0x%02x: ", code);
switch (code) {
case 0x00:
pr_cont("No Error\n");
break;
case 0x20:
pr_cont("Initial signal pulse not long enough "
"to measure carrier frequency\n");
break;
case 0x21:
pr_cont("Not enough length values allocated for signal\n");
break;
case 0x22:
pr_cont("Not enough memory allocated for signal data\n");
break;
case 0x23:
pr_cont("Too many signal repeats\n");
break;
case 0x28:
pr_cont("Insufficient memory available for IR signal "
"data memory allocation\n");
break;
case 0x29:
pr_cont("Insufficient memory available "
"for IrDa signal data memory allocation\n");
break;
case 0x30:
pr_cont("Insufficient memory available for bulk "
"transfer structure\n");
break;
case 0x40:
if (!rr3->transmitting)
pr_cont("Signal capture has been terminated\n");
break;
case 0x41:
pr_cont("Attempt to set/get and unknown signal I/O "
"algorithm parameter\n");
break;
case 0x42:
pr_cont("Signal capture already started\n");
break;
default:
pr_cont("Unknown Error\n");
break;
}
}
static u32 redrat3_val_to_mod_freq(struct redrat3_irdata *irdata)
{
u32 mod_freq = 0;
u16 mod_freq_count = be16_to_cpu(irdata->mod_freq_count);
if (mod_freq_count != 0)
mod_freq = (RR3_CLK * be16_to_cpu(irdata->num_periods)) /
(mod_freq_count * RR3_CLK_PER_COUNT);
return mod_freq;
}
static u32 redrat3_len_to_us(u32 length)
{
u32 biglen = length * 1000;
u32 divisor = (RR3_CLK_CONV_FACTOR) / 1000;
u32 result = (u32) (biglen / divisor);
return result ? result : 1;
}
static u32 redrat3_us_to_len(u32 microsec)
{
u32 result;
u32 divisor;
microsec = (microsec > IR_MAX_DURATION) ? IR_MAX_DURATION : microsec;
divisor = (RR3_CLK_CONV_FACTOR / 1000);
result = (u32)(microsec * divisor) / 1000;
return result ? result : 1;
}
static void redrat3_process_ir_data(struct redrat3_dev *rr3)
{
DEFINE_IR_RAW_EVENT(rawir);
struct device *dev;
unsigned int i, sig_size, single_len, offset, val;
u32 mod_freq;
if (!rr3) {
pr_err("%s called with no context!\n", __func__);
return;
}
dev = rr3->dev;
mod_freq = redrat3_val_to_mod_freq(&rr3->irdata);
dev_dbg(dev, "Got mod_freq of %u\n", mod_freq);
sig_size = be16_to_cpu(rr3->irdata.sig_size);
for (i = 0; i < sig_size; i++) {
offset = rr3->irdata.sigdata[i];
val = get_unaligned_be16(&rr3->irdata.lens[offset]);
single_len = redrat3_len_to_us(val);
if (i % 2)
rawir.pulse = false;
else
rawir.pulse = true;
rawir.duration = US_TO_NS(single_len);
rawir.duration = (rawir.duration > IR_MAX_DURATION) ?
IR_MAX_DURATION : rawir.duration;
dev_dbg(dev, "storing %s with duration %d (i: %d)\n",
rawir.pulse ? "pulse" : "space", rawir.duration, i);
ir_raw_event_store_with_filter(rr3->rc, &rawir);
}
rawir.pulse = false;
rawir.timeout = true;
rawir.duration = rr3->rc->timeout;
dev_dbg(dev, "storing trailing timeout with duration %d\n",
rawir.duration);
ir_raw_event_store_with_filter(rr3->rc, &rawir);
dev_dbg(dev, "calling ir_raw_event_handle\n");
ir_raw_event_handle(rr3->rc);
}
static int redrat3_send_cmd(int cmd, struct redrat3_dev *rr3)
{
struct usb_device *udev;
u8 *data;
int res;
data = kzalloc(sizeof(u8), GFP_KERNEL);
if (!data)
return -ENOMEM;
udev = rr3->udev;
res = usb_control_msg(udev, usb_rcvctrlpipe(udev, 0), cmd,
USB_TYPE_VENDOR | USB_RECIP_DEVICE | USB_DIR_IN,
0x0000, 0x0000, data, sizeof(u8), HZ * 10);
if (res < 0) {
dev_err(rr3->dev, "%s: Error sending rr3 cmd res %d, data %d",
__func__, res, *data);
res = -EIO;
} else
res = data[0];
kfree(data);
return res;
}
static int redrat3_enable_detector(struct redrat3_dev *rr3)
{
struct device *dev = rr3->dev;
u8 ret;
ret = redrat3_send_cmd(RR3_RC_DET_ENABLE, rr3);
if (ret != 0)
dev_dbg(dev, "%s: unexpected ret of %d\n",
__func__, ret);
ret = redrat3_send_cmd(RR3_RC_DET_STATUS, rr3);
if (ret != 1) {
dev_err(dev, "%s: detector status: %d, should be 1\n",
__func__, ret);
return -EIO;
}
redrat3_issue_async(rr3);
return 0;
}
static inline void redrat3_delete(struct redrat3_dev *rr3,
struct usb_device *udev)
{
usb_kill_urb(rr3->read_urb);
usb_kill_urb(rr3->flash_urb);
usb_free_urb(rr3->read_urb);
usb_free_urb(rr3->flash_urb);
usb_free_coherent(udev, le16_to_cpu(rr3->ep_in->wMaxPacketSize),
rr3->bulk_in_buf, rr3->dma_in);
kfree(rr3);
}
static u32 redrat3_get_timeout(struct redrat3_dev *rr3)
{
__be32 *tmp;
u32 timeout = MS_TO_US(150);
int len, ret, pipe;
len = sizeof(*tmp);
tmp = kzalloc(len, GFP_KERNEL);
if (!tmp) {
dev_warn(rr3->dev, "Memory allocation faillure\n");
return timeout;
}
pipe = usb_rcvctrlpipe(rr3->udev, 0);
ret = usb_control_msg(rr3->udev, pipe, RR3_GET_IR_PARAM,
USB_TYPE_VENDOR | USB_RECIP_DEVICE | USB_DIR_IN,
RR3_IR_IO_SIG_TIMEOUT, 0, tmp, len, HZ * 5);
if (ret != len)
dev_warn(rr3->dev, "Failed to read timeout from hardware\n");
else {
timeout = redrat3_len_to_us(be32_to_cpup(tmp));
dev_dbg(rr3->dev, "Got timeout of %d ms\n", timeout / 1000);
}
kfree(tmp);
return timeout;
}
static int redrat3_set_timeout(struct rc_dev *rc_dev, unsigned int timeoutns)
{
struct redrat3_dev *rr3 = rc_dev->priv;
struct usb_device *udev = rr3->udev;
struct device *dev = rr3->dev;
__be32 *timeout;
int ret;
timeout = kmalloc(sizeof(*timeout), GFP_KERNEL);
if (!timeout)
return -ENOMEM;
*timeout = cpu_to_be32(redrat3_us_to_len(timeoutns / 1000));
ret = usb_control_msg(udev, usb_sndctrlpipe(udev, 0), RR3_SET_IR_PARAM,
USB_TYPE_VENDOR | USB_RECIP_DEVICE | USB_DIR_OUT,
RR3_IR_IO_SIG_TIMEOUT, 0, timeout, sizeof(*timeout),
HZ * 25);
dev_dbg(dev, "set ir parm timeout %d ret 0x%02x\n",
be32_to_cpu(*timeout), ret);
if (ret == sizeof(*timeout))
ret = 0;
else if (ret >= 0)
ret = -EIO;
kfree(timeout);
return ret;
}
static void redrat3_reset(struct redrat3_dev *rr3)
{
struct usb_device *udev = rr3->udev;
struct device *dev = rr3->dev;
int rc, rxpipe, txpipe;
u8 *val;
int len = sizeof(u8);
rxpipe = usb_rcvctrlpipe(udev, 0);
txpipe = usb_sndctrlpipe(udev, 0);
val = kmalloc(len, GFP_KERNEL);
if (!val) {
dev_err(dev, "Memory allocation failure\n");
return;
}
*val = 0x01;
rc = usb_control_msg(udev, rxpipe, RR3_RESET,
USB_TYPE_VENDOR | USB_RECIP_DEVICE | USB_DIR_IN,
RR3_CPUCS_REG_ADDR, 0, val, len, HZ * 25);
dev_dbg(dev, "reset returned 0x%02x\n", rc);
*val = length_fuzz;
rc = usb_control_msg(udev, txpipe, RR3_SET_IR_PARAM,
USB_TYPE_VENDOR | USB_RECIP_DEVICE | USB_DIR_OUT,
RR3_IR_IO_LENGTH_FUZZ, 0, val, len, HZ * 25);
dev_dbg(dev, "set ir parm len fuzz %d rc 0x%02x\n", *val, rc);
*val = (65536 - (minimum_pause * 2000)) / 256;
rc = usb_control_msg(udev, txpipe, RR3_SET_IR_PARAM,
USB_TYPE_VENDOR | USB_RECIP_DEVICE | USB_DIR_OUT,
RR3_IR_IO_MIN_PAUSE, 0, val, len, HZ * 25);
dev_dbg(dev, "set ir parm min pause %d rc 0x%02x\n", *val, rc);
*val = periods_measure_carrier;
rc = usb_control_msg(udev, txpipe, RR3_SET_IR_PARAM,
USB_TYPE_VENDOR | USB_RECIP_DEVICE | USB_DIR_OUT,
RR3_IR_IO_PERIODS_MF, 0, val, len, HZ * 25);
dev_dbg(dev, "set ir parm periods measure carrier %d rc 0x%02x", *val,
rc);
*val = RR3_DRIVER_MAXLENS;
rc = usb_control_msg(udev, txpipe, RR3_SET_IR_PARAM,
USB_TYPE_VENDOR | USB_RECIP_DEVICE | USB_DIR_OUT,
RR3_IR_IO_MAX_LENGTHS, 0, val, len, HZ * 25);
dev_dbg(dev, "set ir parm max lens %d rc 0x%02x\n", *val, rc);
kfree(val);
}
static void redrat3_get_firmware_rev(struct redrat3_dev *rr3)
{
int rc = 0;
char *buffer;
buffer = kzalloc(sizeof(char) * (RR3_FW_VERSION_LEN + 1), GFP_KERNEL);
if (!buffer) {
dev_err(rr3->dev, "Memory allocation failure\n");
return;
}
rc = usb_control_msg(rr3->udev, usb_rcvctrlpipe(rr3->udev, 0),
RR3_FW_VERSION,
USB_TYPE_VENDOR | USB_RECIP_DEVICE | USB_DIR_IN,
0, 0, buffer, RR3_FW_VERSION_LEN, HZ * 5);
if (rc >= 0)
dev_info(rr3->dev, "Firmware rev: %s", buffer);
else
dev_err(rr3->dev, "Problem fetching firmware ID\n");
kfree(buffer);
}
static void redrat3_read_packet_start(struct redrat3_dev *rr3, unsigned len)
{
struct redrat3_header *header = rr3->bulk_in_buf;
unsigned pktlen, pkttype;
pktlen = be16_to_cpu(header->length);
pkttype = be16_to_cpu(header->transfer_type);
if (pktlen > sizeof(rr3->irdata)) {
dev_warn(rr3->dev, "packet length %u too large\n", pktlen);
return;
}
switch (pkttype) {
case RR3_ERROR:
if (len >= sizeof(struct redrat3_error)) {
struct redrat3_error *error = rr3->bulk_in_buf;
unsigned fw_error = be16_to_cpu(error->fw_error);
redrat3_dump_fw_error(rr3, fw_error);
}
break;
case RR3_MOD_SIGNAL_IN:
memcpy(&rr3->irdata, rr3->bulk_in_buf, len);
rr3->bytes_read = len;
dev_dbg(rr3->dev, "bytes_read %d, pktlen %d\n",
rr3->bytes_read, pktlen);
break;
default:
dev_dbg(rr3->dev, "ignoring packet with type 0x%02x, len of %d, 0x%02x\n",
pkttype, len, pktlen);
break;
}
}
static void redrat3_read_packet_continue(struct redrat3_dev *rr3, unsigned len)
{
void *irdata = &rr3->irdata;
if (len + rr3->bytes_read > sizeof(rr3->irdata)) {
dev_warn(rr3->dev, "too much data for packet\n");
rr3->bytes_read = 0;
return;
}
memcpy(irdata + rr3->bytes_read, rr3->bulk_in_buf, len);
rr3->bytes_read += len;
dev_dbg(rr3->dev, "bytes_read %d, pktlen %d\n", rr3->bytes_read,
be16_to_cpu(rr3->irdata.header.length));
}
static int redrat3_get_ir_data(struct redrat3_dev *rr3, unsigned len)
{
struct device *dev = rr3->dev;
unsigned pkttype;
int ret = 0;
if (rr3->bytes_read == 0 && len >= sizeof(struct redrat3_header)) {
redrat3_read_packet_start(rr3, len);
} else if (rr3->bytes_read != 0) {
redrat3_read_packet_continue(rr3, len);
} else if (rr3->bytes_read == 0) {
dev_err(dev, "error: no packet data read\n");
ret = -ENODATA;
goto out;
}
if (rr3->bytes_read < be16_to_cpu(rr3->irdata.header.length) +
sizeof(struct redrat3_header))
return 0;
pkttype = be16_to_cpu(rr3->irdata.header.transfer_type);
if (pkttype == RR3_MOD_SIGNAL_IN)
redrat3_process_ir_data(rr3);
else
dev_dbg(dev, "discarding non-signal data packet (type 0x%02x)\n",
pkttype);
out:
rr3->bytes_read = 0;
return ret;
}
static void redrat3_handle_async(struct urb *urb)
{
struct redrat3_dev *rr3;
int ret;
if (!urb)
return;
rr3 = urb->context;
if (!rr3) {
pr_err("%s called with invalid context!\n", __func__);
usb_unlink_urb(urb);
return;
}
switch (urb->status) {
case 0:
ret = redrat3_get_ir_data(rr3, urb->actual_length);
if (!ret) {
redrat3_issue_async(rr3);
}
break;
case -ECONNRESET:
case -ENOENT:
case -ESHUTDOWN:
usb_unlink_urb(urb);
return;
case -EPIPE:
default:
dev_warn(rr3->dev, "Error: urb status = %d\n", urb->status);
rr3->bytes_read = 0;
break;
}
}
static u16 mod_freq_to_val(unsigned int mod_freq)
{
int mult = 6000000;
return 65536 - (mult / mod_freq);
}
static int redrat3_set_tx_carrier(struct rc_dev *rcdev, u32 carrier)
{
struct redrat3_dev *rr3 = rcdev->priv;
struct device *dev = rr3->dev;
dev_dbg(dev, "Setting modulation frequency to %u", carrier);
if (carrier == 0)
return -EINVAL;
rr3->carrier = carrier;
return 0;
}
static int redrat3_transmit_ir(struct rc_dev *rcdev, unsigned *txbuf,
unsigned count)
{
struct redrat3_dev *rr3 = rcdev->priv;
struct device *dev = rr3->dev;
struct redrat3_irdata *irdata = NULL;
int ret, ret_len;
int lencheck, cur_sample_len, pipe;
int *sample_lens = NULL;
u8 curlencheck = 0;
unsigned i, sendbuf_len;
if (rr3->transmitting) {
dev_warn(dev, "%s: transmitter already in use\n", __func__);
return -EAGAIN;
}
if (count > RR3_MAX_SIG_SIZE - RR3_TX_TRAILER_LEN)
return -EINVAL;
rr3->transmitting = true;
sample_lens = kzalloc(sizeof(int) * RR3_DRIVER_MAXLENS, GFP_KERNEL);
if (!sample_lens) {
ret = -ENOMEM;
goto out;
}
irdata = kzalloc(sizeof(*irdata), GFP_KERNEL);
if (!irdata) {
ret = -ENOMEM;
goto out;
}
for (i = 0; i < count; i++) {
cur_sample_len = redrat3_us_to_len(txbuf[i]);
if (cur_sample_len > 0xffff) {
dev_warn(dev, "transmit period of %uus truncated to %uus\n",
txbuf[i], redrat3_len_to_us(0xffff));
cur_sample_len = 0xffff;
}
for (lencheck = 0; lencheck < curlencheck; lencheck++) {
if (sample_lens[lencheck] == cur_sample_len)
break;
}
if (lencheck == curlencheck) {
dev_dbg(dev, "txbuf[%d]=%u, pos %d, enc %u\n",
i, txbuf[i], curlencheck, cur_sample_len);
if (curlencheck < RR3_DRIVER_MAXLENS) {
sample_lens[curlencheck] = cur_sample_len;
put_unaligned_be16(cur_sample_len,
&irdata->lens[curlencheck]);
curlencheck++;
} else {
ret = -EINVAL;
goto out;
}
}
irdata->sigdata[i] = lencheck;
}
irdata->sigdata[count] = RR3_END_OF_SIGNAL;
irdata->sigdata[count + 1] = RR3_END_OF_SIGNAL;
sendbuf_len = offsetof(struct redrat3_irdata,
sigdata[count + RR3_TX_TRAILER_LEN]);
irdata->header.length = cpu_to_be16(sendbuf_len -
sizeof(struct redrat3_header));
irdata->header.transfer_type = cpu_to_be16(RR3_MOD_SIGNAL_OUT);
irdata->pause = cpu_to_be32(redrat3_len_to_us(100));
irdata->mod_freq_count = cpu_to_be16(mod_freq_to_val(rr3->carrier));
irdata->no_lengths = curlencheck;
irdata->sig_size = cpu_to_be16(count + RR3_TX_TRAILER_LEN);
pipe = usb_sndbulkpipe(rr3->udev, rr3->ep_out->bEndpointAddress);
ret = usb_bulk_msg(rr3->udev, pipe, irdata,
sendbuf_len, &ret_len, 10 * HZ);
dev_dbg(dev, "sent %d bytes, (ret %d)\n", ret_len, ret);
pipe = usb_rcvctrlpipe(rr3->udev, 0);
ret = usb_control_msg(rr3->udev, pipe, RR3_TX_SEND_SIGNAL,
USB_TYPE_VENDOR | USB_RECIP_DEVICE | USB_DIR_IN,
0, 0, irdata, 2, HZ * 10);
if (ret < 0)
dev_err(dev, "Error: control msg send failed, rc %d\n", ret);
else
ret = count;
out:
kfree(sample_lens);
kfree(irdata);
rr3->transmitting = false;
return ret;
}
static void redrat3_brightness_set(struct led_classdev *led_dev, enum
led_brightness brightness)
{
struct redrat3_dev *rr3 = container_of(led_dev, struct redrat3_dev,
led);
if (brightness != LED_OFF && atomic_cmpxchg(&rr3->flash, 0, 1) == 0) {
int ret = usb_submit_urb(rr3->flash_urb, GFP_ATOMIC);
if (ret != 0) {
dev_dbg(rr3->dev, "%s: unexpected ret of %d\n",
__func__, ret);
atomic_set(&rr3->flash, 0);
}
}
}
static void redrat3_led_complete(struct urb *urb)
{
struct redrat3_dev *rr3 = urb->context;
switch (urb->status) {
case 0:
break;
case -ECONNRESET:
case -ENOENT:
case -ESHUTDOWN:
usb_unlink_urb(urb);
return;
case -EPIPE:
default:
dev_dbg(rr3->dev, "Error: urb status = %d\n", urb->status);
break;
}
rr3->led.brightness = LED_OFF;
atomic_dec(&rr3->flash);
}
static struct rc_dev *redrat3_init_rc_dev(struct redrat3_dev *rr3)
{
struct device *dev = rr3->dev;
struct rc_dev *rc;
int ret = -ENODEV;
u16 prod = le16_to_cpu(rr3->udev->descriptor.idProduct);
rc = rc_allocate_device();
if (!rc) {
dev_err(dev, "remote input dev allocation failed\n");
goto out;
}
snprintf(rr3->name, sizeof(rr3->name), "RedRat3%s "
"Infrared Remote Transceiver (%04x:%04x)",
prod == USB_RR3IIUSB_PRODUCT_ID ? "-II" : "",
le16_to_cpu(rr3->udev->descriptor.idVendor), prod);
usb_make_path(rr3->udev, rr3->phys, sizeof(rr3->phys));
rc->input_name = rr3->name;
rc->input_phys = rr3->phys;
usb_to_input_id(rr3->udev, &rc->input_id);
rc->dev.parent = dev;
rc->priv = rr3;
rc->driver_type = RC_DRIVER_IR_RAW;
rc->allowed_protocols = RC_BIT_ALL;
rc->min_timeout = MS_TO_NS(RR3_RX_MIN_TIMEOUT);
rc->max_timeout = MS_TO_NS(RR3_RX_MAX_TIMEOUT);
rc->timeout = US_TO_NS(redrat3_get_timeout(rr3));
rc->s_timeout = redrat3_set_timeout;
rc->tx_ir = redrat3_transmit_ir;
rc->s_tx_carrier = redrat3_set_tx_carrier;
rc->driver_name = DRIVER_NAME;
rc->rx_resolution = US_TO_NS(2);
rc->map_name = RC_MAP_HAUPPAUGE;
ret = rc_register_device(rc);
if (ret < 0) {
dev_err(dev, "remote dev registration failed\n");
goto out;
}
return rc;
out:
rc_free_device(rc);
return NULL;
}
static int redrat3_dev_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
struct usb_device *udev = interface_to_usbdev(intf);
struct device *dev = &intf->dev;
struct usb_host_interface *uhi;
struct redrat3_dev *rr3;
struct usb_endpoint_descriptor *ep;
struct usb_endpoint_descriptor *ep_in = NULL;
struct usb_endpoint_descriptor *ep_out = NULL;
u8 addr, attrs;
int pipe, i;
int retval = -ENOMEM;
uhi = intf->cur_altsetting;
for (i = 0; i < uhi->desc.bNumEndpoints; ++i) {
ep = &uhi->endpoint[i].desc;
addr = ep->bEndpointAddress;
attrs = ep->bmAttributes;
if ((ep_in == NULL) &&
((addr & USB_ENDPOINT_DIR_MASK) == USB_DIR_IN) &&
((attrs & USB_ENDPOINT_XFERTYPE_MASK) ==
USB_ENDPOINT_XFER_BULK)) {
dev_dbg(dev, "found bulk-in endpoint at 0x%02x\n",
ep->bEndpointAddress);
if (ep->bEndpointAddress == RR3_BULK_IN_EP_ADDR)
ep_in = ep;
}
if ((ep_out == NULL) &&
((addr & USB_ENDPOINT_DIR_MASK) == USB_DIR_OUT) &&
((attrs & USB_ENDPOINT_XFERTYPE_MASK) ==
USB_ENDPOINT_XFER_BULK)) {
dev_dbg(dev, "found bulk-out endpoint at 0x%02x\n",
ep->bEndpointAddress);
ep_out = ep;
}
}
if (!ep_in || !ep_out) {
dev_err(dev, "Couldn't find both in and out endpoints\n");
retval = -ENODEV;
goto no_endpoints;
}
rr3 = kzalloc(sizeof(*rr3), GFP_KERNEL);
if (rr3 == NULL) {
dev_err(dev, "Memory allocation failure\n");
goto no_endpoints;
}
rr3->dev = &intf->dev;
rr3->read_urb = usb_alloc_urb(0, GFP_KERNEL);
if (!rr3->read_urb)
goto error;
rr3->ep_in = ep_in;
rr3->bulk_in_buf = usb_alloc_coherent(udev,
le16_to_cpu(ep_in->wMaxPacketSize), GFP_KERNEL, &rr3->dma_in);
if (!rr3->bulk_in_buf) {
dev_err(dev, "Read buffer allocation failure\n");
goto error;
}
pipe = usb_rcvbulkpipe(udev, ep_in->bEndpointAddress);
usb_fill_bulk_urb(rr3->read_urb, udev, pipe, rr3->bulk_in_buf,
le16_to_cpu(ep_in->wMaxPacketSize), redrat3_handle_async, rr3);
rr3->read_urb->transfer_dma = rr3->dma_in;
rr3->read_urb->transfer_flags |= URB_NO_TRANSFER_DMA_MAP;
rr3->ep_out = ep_out;
rr3->udev = udev;
redrat3_reset(rr3);
redrat3_get_firmware_rev(rr3);
retval = redrat3_enable_detector(rr3);
if (retval < 0)
goto error;
rr3->carrier = 38000;
rr3->led.name = "redrat3:red:feedback";
rr3->led.default_trigger = "rc-feedback";
rr3->led.brightness_set = redrat3_brightness_set;
retval = led_classdev_register(&intf->dev, &rr3->led);
if (retval)
goto error;
atomic_set(&rr3->flash, 0);
rr3->flash_urb = usb_alloc_urb(0, GFP_KERNEL);
if (!rr3->flash_urb) {
retval = -ENOMEM;
goto led_free_error;
}
rr3->flash_control.bRequestType = 0xc0;
rr3->flash_control.bRequest = RR3_BLINK_LED;
rr3->flash_control.wLength = cpu_to_le16(1);
usb_fill_control_urb(rr3->flash_urb, udev, usb_rcvctrlpipe(udev, 0),
(unsigned char *)&rr3->flash_control,
&rr3->flash_in_buf, sizeof(rr3->flash_in_buf),
redrat3_led_complete, rr3);
rr3->rc = redrat3_init_rc_dev(rr3);
if (!rr3->rc) {
retval = -ENOMEM;
goto led_free_error;
}
usb_set_intfdata(intf, rr3);
return 0;
led_free_error:
led_classdev_unregister(&rr3->led);
error:
redrat3_delete(rr3, rr3->udev);
no_endpoints:
dev_err(dev, "%s: retval = %x", __func__, retval);
return retval;
}
static void redrat3_dev_disconnect(struct usb_interface *intf)
{
struct usb_device *udev = interface_to_usbdev(intf);
struct redrat3_dev *rr3 = usb_get_intfdata(intf);
if (!rr3)
return;
usb_set_intfdata(intf, NULL);
rc_unregister_device(rr3->rc);
led_classdev_unregister(&rr3->led);
redrat3_delete(rr3, udev);
}
static int redrat3_dev_suspend(struct usb_interface *intf, pm_message_t message)
{
struct redrat3_dev *rr3 = usb_get_intfdata(intf);
led_classdev_suspend(&rr3->led);
usb_kill_urb(rr3->read_urb);
usb_kill_urb(rr3->flash_urb);
return 0;
}
static int redrat3_dev_resume(struct usb_interface *intf)
{
struct redrat3_dev *rr3 = usb_get_intfdata(intf);
if (usb_submit_urb(rr3->read_urb, GFP_ATOMIC))
return -EIO;
led_classdev_resume(&rr3->led);
return 0;
}
