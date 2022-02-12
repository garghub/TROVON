static int vicam_control_msg(struct gspca_dev *gspca_dev, u8 request,
u16 value, u16 index, u8 *data, u16 len)
{
int ret;
ret = usb_control_msg(gspca_dev->dev,
usb_sndctrlpipe(gspca_dev->dev, 0),
request,
USB_DIR_OUT | USB_TYPE_VENDOR | USB_RECIP_DEVICE,
value, index, data, len, 1000);
if (ret < 0)
pr_err("control msg req %02X error %d\n", request, ret);
return ret;
}
static int vicam_set_camera_power(struct gspca_dev *gspca_dev, int state)
{
int ret;
ret = vicam_control_msg(gspca_dev, 0x50, state, 0, NULL, 0);
if (ret < 0)
return ret;
if (state)
ret = vicam_control_msg(gspca_dev, 0x55, 1, 0, NULL, 0);
return ret;
}
static int vicam_read_frame(struct gspca_dev *gspca_dev, u8 *data, int size)
{
struct sd *sd = (struct sd *)gspca_dev;
int ret, unscaled_height, act_len = 0;
u8 *req_data = gspca_dev->usb_buf;
memset(req_data, 0, 16);
req_data[0] = sd->ctrls[GAIN].val;
if (gspca_dev->width == 256)
req_data[1] |= 0x01;
if (gspca_dev->height <= 122) {
req_data[1] |= 0x10;
unscaled_height = gspca_dev->height * 2;
} else
unscaled_height = gspca_dev->height;
req_data[2] = 0x90;
if (unscaled_height <= 200)
req_data[3] = 0x06;
else if (unscaled_height <= 242)
req_data[3] = 0x07;
else
req_data[3] = 0x08;
if (sd->ctrls[EXPOSURE].val < 256) {
req_data[4] = 255 - sd->ctrls[EXPOSURE].val;
req_data[5] = 0x00;
req_data[6] = 0x00;
req_data[7] = 0x01;
} else {
req_data[4] = 0x00;
req_data[5] = 0x00;
req_data[6] = sd->ctrls[EXPOSURE].val & 0xFF;
req_data[7] = sd->ctrls[EXPOSURE].val >> 8;
}
req_data[8] = ((244 - unscaled_height) / 2) & ~0x01;
mutex_lock(&gspca_dev->usb_lock);
ret = vicam_control_msg(gspca_dev, 0x51, 0x80, 0, req_data, 16);
mutex_unlock(&gspca_dev->usb_lock);
if (ret < 0)
return ret;
ret = usb_bulk_msg(gspca_dev->dev,
usb_rcvbulkpipe(gspca_dev->dev, 0x81),
data, size, &act_len, 10000);
if (ret < 0 || act_len != size) {
pr_err("bulk read fail (%d) len %d/%d\n",
ret, act_len, size);
return -EIO;
}
return 0;
}
static void vicam_dostream(struct work_struct *work)
{
struct sd *sd = container_of(work, struct sd, work_struct);
struct gspca_dev *gspca_dev = &sd->gspca_dev;
int ret, frame_sz;
u8 *buffer;
frame_sz = gspca_dev->cam.cam_mode[gspca_dev->curr_mode].sizeimage +
HEADER_SIZE;
buffer = kmalloc(frame_sz, GFP_KERNEL | GFP_DMA);
if (!buffer) {
pr_err("Couldn't allocate USB buffer\n");
goto exit;
}
while (gspca_dev->dev && gspca_dev->streaming) {
#ifdef CONFIG_PM
if (gspca_dev->frozen)
break;
#endif
ret = vicam_read_frame(gspca_dev, buffer, frame_sz);
if (ret < 0)
break;
gspca_frame_add(gspca_dev, FIRST_PACKET,
buffer + HEADER_SIZE,
frame_sz - HEADER_SIZE);
gspca_frame_add(gspca_dev, LAST_PACKET, NULL, 0);
}
exit:
kfree(buffer);
}
static int sd_config(struct gspca_dev *gspca_dev,
const struct usb_device_id *id)
{
struct cam *cam = &gspca_dev->cam;
struct sd *sd = (struct sd *)gspca_dev;
cam->bulk = 1;
cam->bulk_size = 64;
cam->cam_mode = vicam_mode;
cam->nmodes = ARRAY_SIZE(vicam_mode);
cam->ctrls = sd->ctrls;
INIT_WORK(&sd->work_struct, vicam_dostream);
return 0;
}
static int sd_init(struct gspca_dev *gspca_dev)
{
int ret;
const struct ihex_binrec *rec;
const struct firmware *uninitialized_var(fw);
u8 *firmware_buf;
ret = request_ihex_firmware(&fw, VICAM_FIRMWARE,
&gspca_dev->dev->dev);
if (ret) {
pr_err("Failed to load \"vicam/firmware.fw\": %d\n", ret);
return ret;
}
firmware_buf = kmalloc(PAGE_SIZE, GFP_KERNEL);
if (!firmware_buf) {
ret = -ENOMEM;
goto exit;
}
for (rec = (void *)fw->data; rec; rec = ihex_next_binrec(rec)) {
memcpy(firmware_buf, rec->data, be16_to_cpu(rec->len));
ret = vicam_control_msg(gspca_dev, 0xff, 0, 0, firmware_buf,
be16_to_cpu(rec->len));
if (ret < 0)
break;
}
kfree(firmware_buf);
exit:
release_firmware(fw);
return ret;
}
static int sd_start(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *)gspca_dev;
int ret;
ret = vicam_set_camera_power(gspca_dev, 1);
if (ret < 0)
return ret;
sd->work_thread = create_singlethread_workqueue(MODULE_NAME);
queue_work(sd->work_thread, &sd->work_struct);
return 0;
}
static void sd_stop0(struct gspca_dev *gspca_dev)
{
struct sd *dev = (struct sd *)gspca_dev;
mutex_unlock(&gspca_dev->usb_lock);
destroy_workqueue(dev->work_thread);
dev->work_thread = NULL;
mutex_lock(&gspca_dev->usb_lock);
if (gspca_dev->dev)
vicam_set_camera_power(gspca_dev, 0);
}
static int sd_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
return gspca_dev_probe(intf, id,
&sd_desc,
sizeof(struct sd),
THIS_MODULE);
}
