static int ds_send_control_cmd(struct ds_device *dev, u16 value, u16 index)
{
int err;
err = usb_control_msg(dev->udev, usb_sndctrlpipe(dev->udev, dev->ep[EP_CONTROL]),
CONTROL_CMD, 0x40, value, index, NULL, 0, 1000);
if (err < 0) {
printk(KERN_ERR "Failed to send command control message %x.%x: err=%d.\n",
value, index, err);
return err;
}
return err;
}
static int ds_send_control_mode(struct ds_device *dev, u16 value, u16 index)
{
int err;
err = usb_control_msg(dev->udev, usb_sndctrlpipe(dev->udev, dev->ep[EP_CONTROL]),
MODE_CMD, 0x40, value, index, NULL, 0, 1000);
if (err < 0) {
printk(KERN_ERR "Failed to send mode control message %x.%x: err=%d.\n",
value, index, err);
return err;
}
return err;
}
static int ds_send_control(struct ds_device *dev, u16 value, u16 index)
{
int err;
err = usb_control_msg(dev->udev, usb_sndctrlpipe(dev->udev, dev->ep[EP_CONTROL]),
COMM_CMD, 0x40, value, index, NULL, 0, 1000);
if (err < 0) {
printk(KERN_ERR "Failed to send control message %x.%x: err=%d.\n",
value, index, err);
return err;
}
return err;
}
static int ds_recv_status_nodump(struct ds_device *dev, struct ds_status *st,
unsigned char *buf, int size)
{
int count, err;
memset(st, 0, sizeof(*st));
count = 0;
err = usb_bulk_msg(dev->udev, usb_rcvbulkpipe(dev->udev, dev->ep[EP_STATUS]), buf, size, &count, 100);
if (err < 0) {
printk(KERN_ERR "Failed to read 1-wire data from 0x%x: err=%d.\n", dev->ep[EP_STATUS], err);
return err;
}
if (count >= sizeof(*st))
memcpy(st, buf, sizeof(*st));
return count;
}
static inline void ds_print_msg(unsigned char *buf, unsigned char *str, int off)
{
printk(KERN_INFO "%45s: %8x\n", str, buf[off]);
}
static void ds_dump_status(struct ds_device *dev, unsigned char *buf, int count)
{
int i;
printk(KERN_INFO "0x%x: count=%d, status: ", dev->ep[EP_STATUS], count);
for (i=0; i<count; ++i)
printk("%02x ", buf[i]);
printk(KERN_INFO "\n");
if (count >= 16) {
ds_print_msg(buf, "enable flag", 0);
ds_print_msg(buf, "1-wire speed", 1);
ds_print_msg(buf, "strong pullup duration", 2);
ds_print_msg(buf, "programming pulse duration", 3);
ds_print_msg(buf, "pulldown slew rate control", 4);
ds_print_msg(buf, "write-1 low time", 5);
ds_print_msg(buf, "data sample offset/write-0 recovery time",
6);
ds_print_msg(buf, "reserved (test register)", 7);
ds_print_msg(buf, "device status flags", 8);
ds_print_msg(buf, "communication command byte 1", 9);
ds_print_msg(buf, "communication command byte 2", 10);
ds_print_msg(buf, "communication command buffer status", 11);
ds_print_msg(buf, "1-wire data output buffer status", 12);
ds_print_msg(buf, "1-wire data input buffer status", 13);
ds_print_msg(buf, "reserved", 14);
ds_print_msg(buf, "reserved", 15);
}
for (i = 16; i < count; ++i) {
if (buf[i] == RR_DETECT) {
ds_print_msg(buf, "new device detect", i);
continue;
}
ds_print_msg(buf, "Result Register Value: ", i);
if (buf[i] & RR_NRS)
printk(KERN_INFO "NRS: Reset no presence or ...\n");
if (buf[i] & RR_SH)
printk(KERN_INFO "SH: short on reset or set path\n");
if (buf[i] & RR_APP)
printk(KERN_INFO "APP: alarming presence on reset\n");
if (buf[i] & RR_VPP)
printk(KERN_INFO "VPP: 12V expected not seen\n");
if (buf[i] & RR_CMP)
printk(KERN_INFO "CMP: compare error\n");
if (buf[i] & RR_CRC)
printk(KERN_INFO "CRC: CRC error detected\n");
if (buf[i] & RR_RDP)
printk(KERN_INFO "RDP: redirected page\n");
if (buf[i] & RR_EOS)
printk(KERN_INFO "EOS: end of search error\n");
}
}
static void ds_reset_device(struct ds_device *dev)
{
ds_send_control_cmd(dev, CTL_RESET_DEVICE, 0);
if (ds_send_control_mode(dev, MOD_PULSE_EN, PULSE_SPUE))
printk(KERN_ERR "ds_reset_device: "
"Error allowing strong pullup\n");
if (dev->spu_sleep) {
u8 del = dev->spu_sleep>>4;
if (ds_send_control(dev, COMM_SET_DURATION | COMM_IM, del))
printk(KERN_ERR "ds_reset_device: "
"Error setting duration\n");
}
}
static int ds_recv_data(struct ds_device *dev, unsigned char *buf, int size)
{
int count, err;
struct ds_status st;
count = 0;
err = usb_bulk_msg(dev->udev, usb_rcvbulkpipe(dev->udev, dev->ep[EP_DATA_IN]),
buf, size, &count, 1000);
if (err < 0) {
u8 buf[0x20];
int count;
printk(KERN_INFO "Clearing ep0x%x.\n", dev->ep[EP_DATA_IN]);
usb_clear_halt(dev->udev, usb_rcvbulkpipe(dev->udev, dev->ep[EP_DATA_IN]));
count = ds_recv_status_nodump(dev, &st, buf, sizeof(buf));
ds_dump_status(dev, buf, count);
return err;
}
#if 0
{
int i;
printk("%s: count=%d: ", __func__, count);
for (i=0; i<count; ++i)
printk("%02x ", buf[i]);
printk("\n");
}
#endif
return count;
}
static int ds_send_data(struct ds_device *dev, unsigned char *buf, int len)
{
int count, err;
count = 0;
err = usb_bulk_msg(dev->udev, usb_sndbulkpipe(dev->udev, dev->ep[EP_DATA_OUT]), buf, len, &count, 1000);
if (err < 0) {
printk(KERN_ERR "Failed to write 1-wire data to ep0x%x: "
"err=%d.\n", dev->ep[EP_DATA_OUT], err);
return err;
}
return err;
}
static int ds_wait_status(struct ds_device *dev, struct ds_status *st)
{
u8 buf[0x20];
int err, count = 0;
do {
err = ds_recv_status_nodump(dev, st, buf, sizeof(buf));
#if 0
if (err >= 0) {
int i;
printk("0x%x: count=%d, status: ", dev->ep[EP_STATUS], err);
for (i=0; i<err; ++i)
printk("%02x ", buf[i]);
printk("\n");
}
#endif
} while (!(buf[0x08] & ST_IDLE) && !(err < 0) && ++count < 100);
if (err >= 16 && st->status & ST_EPOF) {
printk(KERN_INFO "Resetting device after ST_EPOF.\n");
ds_reset_device(dev);
count = 101;
}
if (err > 16 || count >= 100 || err < 0)
ds_dump_status(dev, buf, err);
if (count >= 100 || err < 0)
return -1;
else
return 0;
}
static int ds_reset(struct ds_device *dev)
{
int err;
err = ds_send_control(dev, COMM_1_WIRE_RESET | COMM_IM, SPEED_NORMAL);
if (err)
return err;
return 0;
}
static int ds_set_pullup(struct ds_device *dev, int delay)
{
int err = 0;
u8 del = 1 + (u8)(delay >> 4);
int ms = del<<4;
dev->spu_bit = delay ? COMM_SPU : 0;
if (delay == 0 || ms == dev->spu_sleep)
return err;
err = ds_send_control(dev, COMM_SET_DURATION | COMM_IM, del);
if (err)
return err;
dev->spu_sleep = ms;
return err;
}
static int ds_touch_bit(struct ds_device *dev, u8 bit, u8 *tbit)
{
int err;
struct ds_status st;
err = ds_send_control(dev, COMM_BIT_IO | COMM_IM | (bit ? COMM_D : 0),
0);
if (err)
return err;
ds_wait_status(dev, &st);
err = ds_recv_data(dev, tbit, sizeof(*tbit));
if (err < 0)
return err;
return 0;
}
static int ds_write_byte(struct ds_device *dev, u8 byte)
{
int err;
struct ds_status st;
u8 rbyte;
err = ds_send_control(dev, COMM_BYTE_IO | COMM_IM | dev->spu_bit, byte);
if (err)
return err;
if (dev->spu_bit)
msleep(dev->spu_sleep);
err = ds_wait_status(dev, &st);
if (err)
return err;
err = ds_recv_data(dev, &rbyte, sizeof(rbyte));
if (err < 0)
return err;
return !(byte == rbyte);
}
static int ds_read_byte(struct ds_device *dev, u8 *byte)
{
int err;
struct ds_status st;
err = ds_send_control(dev, COMM_BYTE_IO | COMM_IM , 0xff);
if (err)
return err;
ds_wait_status(dev, &st);
err = ds_recv_data(dev, byte, sizeof(*byte));
if (err < 0)
return err;
return 0;
}
static int ds_read_block(struct ds_device *dev, u8 *buf, int len)
{
struct ds_status st;
int err;
if (len > 64*1024)
return -E2BIG;
memset(buf, 0xFF, len);
err = ds_send_data(dev, buf, len);
if (err < 0)
return err;
err = ds_send_control(dev, COMM_BLOCK_IO | COMM_IM, len);
if (err)
return err;
ds_wait_status(dev, &st);
memset(buf, 0x00, len);
err = ds_recv_data(dev, buf, len);
return err;
}
static int ds_write_block(struct ds_device *dev, u8 *buf, int len)
{
int err;
struct ds_status st;
err = ds_send_data(dev, buf, len);
if (err < 0)
return err;
err = ds_send_control(dev, COMM_BLOCK_IO | COMM_IM | dev->spu_bit, len);
if (err)
return err;
if (dev->spu_bit)
msleep(dev->spu_sleep);
ds_wait_status(dev, &st);
err = ds_recv_data(dev, buf, len);
if (err < 0)
return err;
return !(err == len);
}
static u8 ds9490r_touch_bit(void *data, u8 bit)
{
u8 ret;
struct ds_device *dev = data;
if (ds_touch_bit(dev, bit, &ret))
return 0;
return ret;
}
static void ds9490r_write_byte(void *data, u8 byte)
{
struct ds_device *dev = data;
ds_write_byte(dev, byte);
}
static u8 ds9490r_read_byte(void *data)
{
struct ds_device *dev = data;
int err;
u8 byte = 0;
err = ds_read_byte(dev, &byte);
if (err)
return 0;
return byte;
}
static void ds9490r_write_block(void *data, const u8 *buf, int len)
{
struct ds_device *dev = data;
ds_write_block(dev, (u8 *)buf, len);
}
static u8 ds9490r_read_block(void *data, u8 *buf, int len)
{
struct ds_device *dev = data;
int err;
err = ds_read_block(dev, buf, len);
if (err < 0)
return 0;
return len;
}
static u8 ds9490r_reset(void *data)
{
struct ds_device *dev = data;
int err;
err = ds_reset(dev);
if (err)
return 1;
return 0;
}
static u8 ds9490r_set_pullup(void *data, int delay)
{
struct ds_device *dev = data;
if (ds_set_pullup(dev, delay))
return 1;
return 0;
}
static int ds_w1_init(struct ds_device *dev)
{
memset(&dev->master, 0, sizeof(struct w1_bus_master));
ds_reset_device(dev);
dev->master.data = dev;
dev->master.touch_bit = &ds9490r_touch_bit;
dev->master.read_byte = &ds9490r_read_byte;
dev->master.write_byte = &ds9490r_write_byte;
dev->master.read_block = &ds9490r_read_block;
dev->master.write_block = &ds9490r_write_block;
dev->master.reset_bus = &ds9490r_reset;
dev->master.set_pullup = &ds9490r_set_pullup;
return w1_add_master_device(&dev->master);
}
static void ds_w1_fini(struct ds_device *dev)
{
w1_remove_master_device(&dev->master);
}
static int ds_probe(struct usb_interface *intf,
const struct usb_device_id *udev_id)
{
struct usb_device *udev = interface_to_usbdev(intf);
struct usb_endpoint_descriptor *endpoint;
struct usb_host_interface *iface_desc;
struct ds_device *dev;
int i, err;
dev = kmalloc(sizeof(struct ds_device), GFP_KERNEL);
if (!dev) {
printk(KERN_INFO "Failed to allocate new DS9490R structure.\n");
return -ENOMEM;
}
dev->spu_sleep = 0;
dev->spu_bit = 0;
dev->udev = usb_get_dev(udev);
if (!dev->udev) {
err = -ENOMEM;
goto err_out_free;
}
memset(dev->ep, 0, sizeof(dev->ep));
usb_set_intfdata(intf, dev);
err = usb_set_interface(dev->udev, intf->altsetting[0].desc.bInterfaceNumber, 3);
if (err) {
printk(KERN_ERR "Failed to set alternative setting 3 for %d interface: err=%d.\n",
intf->altsetting[0].desc.bInterfaceNumber, err);
goto err_out_clear;
}
err = usb_reset_configuration(dev->udev);
if (err) {
printk(KERN_ERR "Failed to reset configuration: err=%d.\n", err);
goto err_out_clear;
}
iface_desc = &intf->altsetting[0];
if (iface_desc->desc.bNumEndpoints != NUM_EP-1) {
printk(KERN_INFO "Num endpoints=%d. It is not DS9490R.\n", iface_desc->desc.bNumEndpoints);
err = -EINVAL;
goto err_out_clear;
}
for (i = 0; i < iface_desc->desc.bNumEndpoints; ++i) {
endpoint = &iface_desc->endpoint[i].desc;
dev->ep[i+1] = endpoint->bEndpointAddress;
#if 0
printk("%d: addr=%x, size=%d, dir=%s, type=%x\n",
i, endpoint->bEndpointAddress, le16_to_cpu(endpoint->wMaxPacketSize),
(endpoint->bEndpointAddress & USB_DIR_IN)?"IN":"OUT",
endpoint->bmAttributes & USB_ENDPOINT_XFERTYPE_MASK);
#endif
}
err = ds_w1_init(dev);
if (err)
goto err_out_clear;
mutex_lock(&ds_mutex);
list_add_tail(&dev->ds_entry, &ds_devices);
mutex_unlock(&ds_mutex);
return 0;
err_out_clear:
usb_set_intfdata(intf, NULL);
usb_put_dev(dev->udev);
err_out_free:
kfree(dev);
return err;
}
static void ds_disconnect(struct usb_interface *intf)
{
struct ds_device *dev;
dev = usb_get_intfdata(intf);
if (!dev)
return;
mutex_lock(&ds_mutex);
list_del(&dev->ds_entry);
mutex_unlock(&ds_mutex);
ds_w1_fini(dev);
usb_set_intfdata(intf, NULL);
usb_put_dev(dev->udev);
kfree(dev);
}
