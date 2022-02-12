static int go7007_usb_vendor_request(struct go7007 *go, int request,
int value, int index, void *transfer_buffer, int length, int in)
{
struct go7007_usb *usb = go->hpi_context;
int timeout = 5000;
if (in) {
return usb_control_msg(usb->usbdev,
usb_rcvctrlpipe(usb->usbdev, 0), request,
USB_TYPE_VENDOR | USB_RECIP_DEVICE | USB_DIR_IN,
value, index, transfer_buffer, length, timeout);
} else {
return usb_control_msg(usb->usbdev,
usb_sndctrlpipe(usb->usbdev, 0), request,
USB_TYPE_VENDOR | USB_RECIP_DEVICE,
value, index, transfer_buffer, length, timeout);
}
}
static int go7007_usb_interface_reset(struct go7007 *go)
{
struct go7007_usb *usb = go->hpi_context;
u16 intr_val, intr_data;
if (go7007_write_interrupt(go, 0x0001, 0x0001) < 0)
return -1;
msleep(100);
if (usb->board->flags & GO7007_USB_EZUSB) {
#ifdef GO7007_USB_DEBUG
printk(KERN_DEBUG "go7007-usb: resetting EZ-USB buffers\n");
#endif
if (go7007_usb_vendor_request(go, 0x10, 0, 0, NULL, 0, 0) < 0 ||
go7007_usb_vendor_request(go, 0x10, 0, 0, NULL, 0, 0) < 0)
return -1;
if (go7007_write_interrupt(go, 0x0001, 0x0001) < 0)
return -1;
msleep(100);
}
if (go7007_read_interrupt(go, &intr_val, &intr_data) < 0 ||
(intr_val & ~0x1) != 0x55aa) {
printk(KERN_ERR
"go7007-usb: unable to reset the USB interface\n");
return -1;
}
return 0;
}
static int go7007_usb_ezusb_write_interrupt(struct go7007 *go,
int addr, int data)
{
struct go7007_usb *usb = go->hpi_context;
int i, r;
u16 status_reg;
int timeout = 500;
#ifdef GO7007_USB_DEBUG
printk(KERN_DEBUG
"go7007-usb: WriteInterrupt: %04x %04x\n", addr, data);
#endif
for (i = 0; i < 100; ++i) {
r = usb_control_msg(usb->usbdev,
usb_rcvctrlpipe(usb->usbdev, 0), 0x14,
USB_TYPE_VENDOR | USB_RECIP_DEVICE | USB_DIR_IN,
0, HPI_STATUS_ADDR, &status_reg,
sizeof(status_reg), timeout);
if (r < 0)
goto write_int_error;
__le16_to_cpus(&status_reg);
if (!(status_reg & 0x0010))
break;
msleep(10);
}
if (i == 100) {
printk(KERN_ERR
"go7007-usb: device is hung, status reg = 0x%04x\n",
status_reg);
return -1;
}
r = usb_control_msg(usb->usbdev, usb_sndctrlpipe(usb->usbdev, 0), 0x12,
USB_TYPE_VENDOR | USB_RECIP_DEVICE, data,
INT_PARAM_ADDR, NULL, 0, timeout);
if (r < 0)
goto write_int_error;
r = usb_control_msg(usb->usbdev, usb_sndctrlpipe(usb->usbdev, 0),
0x12, USB_TYPE_VENDOR | USB_RECIP_DEVICE, addr,
INT_INDEX_ADDR, NULL, 0, timeout);
if (r < 0)
goto write_int_error;
return 0;
write_int_error:
printk(KERN_ERR "go7007-usb: error in WriteInterrupt: %d\n", r);
return r;
}
static int go7007_usb_onboard_write_interrupt(struct go7007 *go,
int addr, int data)
{
struct go7007_usb *usb = go->hpi_context;
u8 *tbuf;
int r;
int timeout = 500;
#ifdef GO7007_USB_DEBUG
printk(KERN_DEBUG
"go7007-usb: WriteInterrupt: %04x %04x\n", addr, data);
#endif
tbuf = kzalloc(8, GFP_KERNEL);
if (tbuf == NULL)
return -ENOMEM;
tbuf[0] = data & 0xff;
tbuf[1] = data >> 8;
tbuf[2] = addr & 0xff;
tbuf[3] = addr >> 8;
r = usb_control_msg(usb->usbdev, usb_sndctrlpipe(usb->usbdev, 2), 0x00,
USB_TYPE_VENDOR | USB_RECIP_ENDPOINT, 0x55aa,
0xf0f0, tbuf, 8, timeout);
kfree(tbuf);
if (r < 0) {
printk(KERN_ERR "go7007-usb: error in WriteInterrupt: %d\n", r);
return r;
}
return 0;
}
static void go7007_usb_readinterrupt_complete(struct urb *urb)
{
struct go7007 *go = (struct go7007 *)urb->context;
u16 *regs = (u16 *)urb->transfer_buffer;
int status = urb->status;
if (status) {
if (status != -ESHUTDOWN &&
go->status != STATUS_SHUTDOWN) {
printk(KERN_ERR
"go7007-usb: error in read interrupt: %d\n",
urb->status);
} else {
wake_up(&go->interrupt_waitq);
return;
}
} else if (urb->actual_length != urb->transfer_buffer_length) {
printk(KERN_ERR "go7007-usb: short read in interrupt pipe!\n");
} else {
go->interrupt_available = 1;
go->interrupt_data = __le16_to_cpu(regs[0]);
go->interrupt_value = __le16_to_cpu(regs[1]);
#ifdef GO7007_USB_DEBUG
printk(KERN_DEBUG "go7007-usb: ReadInterrupt: %04x %04x\n",
go->interrupt_value, go->interrupt_data);
#endif
}
wake_up(&go->interrupt_waitq);
}
static int go7007_usb_read_interrupt(struct go7007 *go)
{
struct go7007_usb *usb = go->hpi_context;
int r;
r = usb_submit_urb(usb->intr_urb, GFP_KERNEL);
if (r < 0) {
printk(KERN_ERR
"go7007-usb: unable to submit interrupt urb: %d\n", r);
return r;
}
return 0;
}
static void go7007_usb_read_video_pipe_complete(struct urb *urb)
{
struct go7007 *go = (struct go7007 *)urb->context;
int r, status = urb->status;
if (!go->streaming) {
wake_up_interruptible(&go->frame_waitq);
return;
}
if (status) {
printk(KERN_ERR "go7007-usb: error in video pipe: %d\n",
status);
return;
}
if (urb->actual_length != urb->transfer_buffer_length) {
printk(KERN_ERR "go7007-usb: short read in video pipe!\n");
return;
}
go7007_parse_video_stream(go, urb->transfer_buffer, urb->actual_length);
r = usb_submit_urb(urb, GFP_ATOMIC);
if (r < 0)
printk(KERN_ERR "go7007-usb: error in video pipe: %d\n", r);
}
static void go7007_usb_read_audio_pipe_complete(struct urb *urb)
{
struct go7007 *go = (struct go7007 *)urb->context;
int r, status = urb->status;
if (!go->streaming)
return;
if (status) {
printk(KERN_ERR "go7007-usb: error in audio pipe: %d\n",
status);
return;
}
if (urb->actual_length != urb->transfer_buffer_length) {
printk(KERN_ERR "go7007-usb: short read in audio pipe!\n");
return;
}
if (go->audio_deliver != NULL)
go->audio_deliver(go, urb->transfer_buffer, urb->actual_length);
r = usb_submit_urb(urb, GFP_ATOMIC);
if (r < 0)
printk(KERN_ERR "go7007-usb: error in audio pipe: %d\n", r);
}
static int go7007_usb_stream_start(struct go7007 *go)
{
struct go7007_usb *usb = go->hpi_context;
int i, r;
for (i = 0; i < 8; ++i) {
r = usb_submit_urb(usb->video_urbs[i], GFP_KERNEL);
if (r < 0) {
printk(KERN_ERR "go7007-usb: error submitting video "
"urb %d: %d\n", i, r);
goto video_submit_failed;
}
}
if (!go->audio_enabled)
return 0;
for (i = 0; i < 8; ++i) {
r = usb_submit_urb(usb->audio_urbs[i], GFP_KERNEL);
if (r < 0) {
printk(KERN_ERR "go7007-usb: error submitting audio "
"urb %d: %d\n", i, r);
goto audio_submit_failed;
}
}
return 0;
audio_submit_failed:
for (i = 0; i < 7; ++i)
usb_kill_urb(usb->audio_urbs[i]);
video_submit_failed:
for (i = 0; i < 8; ++i)
usb_kill_urb(usb->video_urbs[i]);
return -1;
}
static int go7007_usb_stream_stop(struct go7007 *go)
{
struct go7007_usb *usb = go->hpi_context;
int i;
if (go->status == STATUS_SHUTDOWN)
return 0;
for (i = 0; i < 8; ++i)
usb_kill_urb(usb->video_urbs[i]);
if (go->audio_enabled)
for (i = 0; i < 8; ++i)
usb_kill_urb(usb->audio_urbs[i]);
return 0;
}
static int go7007_usb_send_firmware(struct go7007 *go, u8 *data, int len)
{
struct go7007_usb *usb = go->hpi_context;
int transferred, pipe;
int timeout = 500;
#ifdef GO7007_USB_DEBUG
printk(KERN_DEBUG "go7007-usb: DownloadBuffer sending %d bytes\n", len);
#endif
if (usb->board->flags & GO7007_USB_EZUSB)
pipe = usb_sndbulkpipe(usb->usbdev, 2);
else
pipe = usb_sndbulkpipe(usb->usbdev, 3);
return usb_bulk_msg(usb->usbdev, pipe, data, len,
&transferred, timeout);
}
static int go7007_usb_i2c_master_xfer(struct i2c_adapter *adapter,
struct i2c_msg msgs[], int num)
{
struct go7007 *go = i2c_get_adapdata(adapter);
struct go7007_usb *usb = go->hpi_context;
u8 buf[16];
int buf_len, i;
int ret = -1;
if (go->status == STATUS_SHUTDOWN)
return -1;
mutex_lock(&usb->i2c_lock);
for (i = 0; i < num; ++i) {
if (i + 1 < num && msgs[i].addr == msgs[i + 1].addr &&
!(msgs[i].flags & I2C_M_RD) &&
(msgs[i + 1].flags & I2C_M_RD)) {
#ifdef GO7007_I2C_DEBUG
printk(KERN_DEBUG "go7007-usb: i2c write/read %d/%d "
"bytes on %02x\n", msgs[i].len,
msgs[i + 1].len, msgs[i].addr);
#endif
buf[0] = 0x01;
buf[1] = msgs[i].len + 1;
buf[2] = msgs[i].addr << 1;
memcpy(&buf[3], msgs[i].buf, msgs[i].len);
buf_len = msgs[i].len + 3;
buf[buf_len++] = msgs[++i].len;
} else if (msgs[i].flags & I2C_M_RD) {
#ifdef GO7007_I2C_DEBUG
printk(KERN_DEBUG "go7007-usb: i2c read %d "
"bytes on %02x\n", msgs[i].len,
msgs[i].addr);
#endif
buf[0] = 0x01;
buf[1] = 1;
buf[2] = msgs[i].addr << 1;
buf[3] = msgs[i].len;
buf_len = 4;
} else {
#ifdef GO7007_I2C_DEBUG
printk(KERN_DEBUG "go7007-usb: i2c write %d "
"bytes on %02x\n", msgs[i].len,
msgs[i].addr);
#endif
buf[0] = 0x00;
buf[1] = msgs[i].len + 1;
buf[2] = msgs[i].addr << 1;
memcpy(&buf[3], msgs[i].buf, msgs[i].len);
buf_len = msgs[i].len + 3;
buf[buf_len++] = 0;
}
if (go7007_usb_vendor_request(go, 0x24, 0, 0,
buf, buf_len, 0) < 0)
goto i2c_done;
if (msgs[i].flags & I2C_M_RD) {
memset(buf, 0, sizeof(buf));
if (go7007_usb_vendor_request(go, 0x25, 0, 0, buf,
msgs[i].len + 1, 1) < 0)
goto i2c_done;
memcpy(msgs[i].buf, buf + 1, msgs[i].len);
}
}
ret = 0;
i2c_done:
mutex_unlock(&usb->i2c_lock);
return ret;
}
static u32 go7007_usb_functionality(struct i2c_adapter *adapter)
{
return (I2C_FUNC_SMBUS_EMUL) & ~I2C_FUNC_SMBUS_QUICK;
}
static int go7007_usb_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
struct go7007 *go;
struct go7007_usb *usb;
struct go7007_usb_board *board;
struct usb_device *usbdev = interface_to_usbdev(intf);
char *name;
int video_pipe, i, v_urb_len;
printk(KERN_DEBUG "go7007-usb: probing new GO7007 USB board\n");
switch (id->driver_info) {
case GO7007_BOARDID_MATRIX_II:
name = "WIS Matrix II or compatible";
board = &board_matrix_ii;
break;
case GO7007_BOARDID_MATRIX_RELOAD:
name = "WIS Matrix Reloaded or compatible";
board = &board_matrix_reload;
break;
case GO7007_BOARDID_MATRIX_REV:
name = "WIS Matrix Revolution or compatible";
board = &board_matrix_revolution;
break;
case GO7007_BOARDID_STAR_TREK:
name = "WIS Star Trek or compatible";
board = &board_star_trek;
break;
case GO7007_BOARDID_XMEN:
name = "WIS XMen or compatible";
board = &board_xmen;
break;
case GO7007_BOARDID_XMEN_II:
name = "WIS XMen II or compatible";
board = &board_xmen;
break;
case GO7007_BOARDID_XMEN_III:
name = "WIS XMen III or compatible";
board = &board_xmen;
break;
case GO7007_BOARDID_PX_M402U:
name = "Plextor PX-M402U";
board = &board_matrix_ii;
break;
case GO7007_BOARDID_PX_TV402U_ANY:
name = "Plextor PX-TV402U (unknown tuner)";
board = &board_px_tv402u;
break;
case GO7007_BOARDID_LIFEVIEW_LR192:
printk(KERN_ERR "go7007-usb: The Lifeview TV Walker Ultra "
"is not supported. Sorry!\n");
return 0;
name = "Lifeview TV Walker Ultra";
board = &board_lifeview_lr192;
break;
case GO7007_BOARDID_SENSORAY_2250:
printk(KERN_INFO "Sensoray 2250 found\n");
name = "Sensoray 2250/2251";
board = &board_sensoray_2250;
break;
default:
printk(KERN_ERR "go7007-usb: unknown board ID %d!\n",
(unsigned int)id->driver_info);
return 0;
}
usb = kzalloc(sizeof(struct go7007_usb), GFP_KERNEL);
if (usb == NULL)
return -ENOMEM;
usb->intr_urb = usb_alloc_urb(0, GFP_KERNEL);
if (usb->intr_urb == NULL)
goto allocfail;
usb->intr_urb->transfer_buffer = kmalloc(2*sizeof(u16), GFP_KERNEL);
if (usb->intr_urb->transfer_buffer == NULL)
goto allocfail;
go = go7007_alloc(&board->main_info, &intf->dev);
if (go == NULL)
goto allocfail;
usb->board = board;
usb->usbdev = usbdev;
go->board_id = id->driver_info;
strncpy(go->name, name, sizeof(go->name));
if (board->flags & GO7007_USB_EZUSB)
go->hpi_ops = &go7007_usb_ezusb_hpi_ops;
else
go->hpi_ops = &go7007_usb_onboard_hpi_ops;
go->hpi_context = usb;
if (go->board_id == GO7007_BOARDID_SENSORAY_2250)
usb_fill_bulk_urb(usb->intr_urb, usb->usbdev,
usb_rcvbulkpipe(usb->usbdev, 4),
usb->intr_urb->transfer_buffer, 2*sizeof(u16),
go7007_usb_readinterrupt_complete, go);
else
usb_fill_int_urb(usb->intr_urb, usb->usbdev,
usb_rcvintpipe(usb->usbdev, 4),
usb->intr_urb->transfer_buffer, 2*sizeof(u16),
go7007_usb_readinterrupt_complete, go, 8);
usb_set_intfdata(intf, &go->v4l2_dev);
if (go7007_boot_encoder(go, go->board_info->flags &
GO7007_BOARD_USE_ONBOARD_I2C) < 0)
goto initfail;
if (board->flags & GO7007_USB_EZUSB_I2C) {
memcpy(&go->i2c_adapter, &go7007_usb_adap_templ,
sizeof(go7007_usb_adap_templ));
mutex_init(&usb->i2c_lock);
go->i2c_adapter.dev.parent = go->dev;
i2c_set_adapdata(&go->i2c_adapter, go);
if (i2c_add_adapter(&go->i2c_adapter) < 0) {
printk(KERN_ERR
"go7007-usb: error: i2c_add_adapter failed\n");
goto initfail;
}
go->i2c_adapter_online = 1;
}
if ((go->board_id == GO7007_BOARDID_XMEN ||
go->board_id == GO7007_BOARDID_XMEN_III) &&
go->i2c_adapter_online) {
union i2c_smbus_data data;
i2c_smbus_xfer(&go->i2c_adapter, 0x21, I2C_CLIENT_SCCB,
I2C_SMBUS_READ, 0x0A, I2C_SMBUS_BYTE_DATA, &data);
if (data.byte != 0x76) {
if (assume_endura) {
go->board_id = GO7007_BOARDID_ENDURA;
usb->board = board = &board_endura;
go->board_info = &board->main_info;
strncpy(go->name, "Pelco Endura",
sizeof(go->name));
} else {
u16 channel;
go7007_write_addr(go, 0x3c82, 0x0000);
go7007_write_addr(go, 0x3c80, 0x00df);
go7007_read_addr(go, 0x3c81, &channel);
channel &= 0x3;
go->board_id = GO7007_BOARDID_ADLINK_MPG24;
usb->board = board = &board_adlink_mpg24;
go->board_info = &board->main_info;
go->channel_number = channel;
snprintf(go->name, sizeof(go->name),
"Adlink PCI-MPG24, channel #%d",
channel);
}
}
}
if (go->board_id == GO7007_BOARDID_PX_TV402U_ANY) {
u8 data[3];
if (go7007_usb_vendor_request(go, 0x41, 0, 0, data, 3, 1) < 0) {
printk(KERN_ERR "go7007-usb: GPIO read failed!\n");
goto initfail;
}
switch (data[0] >> 6) {
case 1:
go->board_id = GO7007_BOARDID_PX_TV402U_EU;
go->tuner_type = TUNER_SONY_BTF_PG472Z;
strncpy(go->name, "Plextor PX-TV402U-EU",
sizeof(go->name));
break;
case 2:
go->board_id = GO7007_BOARDID_PX_TV402U_JP;
go->tuner_type = TUNER_SONY_BTF_PK467Z;
strncpy(go->name, "Plextor PX-TV402U-JP",
sizeof(go->name));
break;
case 3:
go->board_id = GO7007_BOARDID_PX_TV402U_NA;
go->tuner_type = TUNER_SONY_BTF_PB463Z;
strncpy(go->name, "Plextor PX-TV402U-NA",
sizeof(go->name));
break;
default:
printk(KERN_DEBUG "go7007-usb: unable to detect "
"tuner type!\n");
break;
}
if (go7007_usb_vendor_request(go, 0x40, 0x7f02, 0,
NULL, 0, 0) < 0) {
printk(KERN_ERR "go7007-usb: GPIO write failed!\n");
goto initfail;
}
}
if ((board->flags & GO7007_USB_EZUSB) &&
usbdev->speed != USB_SPEED_HIGH)
printk(KERN_ERR "go7007-usb: *** WARNING *** This device "
"must be connected to a USB 2.0 port! "
"Attempting to capture video through a USB 1.1 "
"port will result in stream corruption, even "
"at low bitrates!\n");
if (go7007_register_encoder(go) < 0)
goto initfail;
if (board->flags & GO7007_USB_EZUSB) {
v_urb_len = 1024;
video_pipe = usb_rcvbulkpipe(usb->usbdev, 6);
} else {
v_urb_len = 512;
video_pipe = usb_rcvbulkpipe(usb->usbdev, 1);
}
for (i = 0; i < 8; ++i) {
usb->video_urbs[i] = usb_alloc_urb(0, GFP_KERNEL);
if (usb->video_urbs[i] == NULL)
goto initfail;
usb->video_urbs[i]->transfer_buffer =
kmalloc(v_urb_len, GFP_KERNEL);
if (usb->video_urbs[i]->transfer_buffer == NULL)
goto initfail;
usb_fill_bulk_urb(usb->video_urbs[i], usb->usbdev, video_pipe,
usb->video_urbs[i]->transfer_buffer, v_urb_len,
go7007_usb_read_video_pipe_complete, go);
}
if ((board->flags & GO7007_USB_EZUSB) && go->audio_enabled)
for (i = 0; i < 8; ++i) {
usb->audio_urbs[i] = usb_alloc_urb(0, GFP_KERNEL);
if (usb->audio_urbs[i] == NULL)
goto initfail;
usb->audio_urbs[i]->transfer_buffer = kmalloc(4096,
GFP_KERNEL);
if (usb->audio_urbs[i]->transfer_buffer == NULL)
goto initfail;
usb_fill_bulk_urb(usb->audio_urbs[i], usb->usbdev,
usb_rcvbulkpipe(usb->usbdev, 8),
usb->audio_urbs[i]->transfer_buffer, 4096,
go7007_usb_read_audio_pipe_complete, go);
}
go->status = STATUS_ONLINE;
return 0;
initfail:
go->status = STATUS_SHUTDOWN;
return 0;
allocfail:
if (usb->intr_urb) {
kfree(usb->intr_urb->transfer_buffer);
usb_free_urb(usb->intr_urb);
}
kfree(usb);
return -ENOMEM;
}
static void go7007_usb_disconnect(struct usb_interface *intf)
{
struct go7007 *go = to_go7007(usb_get_intfdata(intf));
struct go7007_usb *usb = go->hpi_context;
struct urb *vurb, *aurb;
int i;
go->status = STATUS_SHUTDOWN;
usb_kill_urb(usb->intr_urb);
for (i = 0; i < 8; ++i) {
vurb = usb->video_urbs[i];
if (vurb) {
usb_kill_urb(vurb);
kfree(vurb->transfer_buffer);
usb_free_urb(vurb);
}
aurb = usb->audio_urbs[i];
if (aurb) {
usb_kill_urb(aurb);
kfree(aurb->transfer_buffer);
usb_free_urb(aurb);
}
}
kfree(usb->intr_urb->transfer_buffer);
usb_free_urb(usb->intr_urb);
kfree(go->hpi_context);
go7007_remove(go);
}
