struct pwc_frame_buf *pwc_get_next_fill_buf(struct pwc_device *pdev)
{
unsigned long flags = 0;
struct pwc_frame_buf *buf = NULL;
spin_lock_irqsave(&pdev->queued_bufs_lock, flags);
if (list_empty(&pdev->queued_bufs))
goto leave;
buf = list_entry(pdev->queued_bufs.next, struct pwc_frame_buf, list);
list_del(&buf->list);
leave:
spin_unlock_irqrestore(&pdev->queued_bufs_lock, flags);
return buf;
}
static void pwc_snapshot_button(struct pwc_device *pdev, int down)
{
if (down) {
PWC_TRACE("Snapshot button pressed.\n");
pdev->snapshot_button_status = 1;
} else {
PWC_TRACE("Snapshot button released.\n");
}
#ifdef CONFIG_USB_PWC_INPUT_EVDEV
if (pdev->button_dev) {
input_report_key(pdev->button_dev, KEY_CAMERA, down);
input_sync(pdev->button_dev);
}
#endif
}
static void pwc_frame_complete(struct pwc_device *pdev)
{
struct pwc_frame_buf *fbuf = pdev->fill_buf;
if (pdev->type == 730) {
unsigned char *ptr = (unsigned char *)fbuf->data;
if (ptr[1] == 1 && ptr[0] & 0x10) {
PWC_TRACE("Hyundai CMOS sensor bug. Dropping frame.\n");
pdev->drop_frames += 2;
}
if ((ptr[0] ^ pdev->vmirror) & 0x01) {
pwc_snapshot_button(pdev, ptr[0] & 0x01);
}
if ((ptr[0] ^ pdev->vmirror) & 0x02) {
if (ptr[0] & 0x02)
PWC_TRACE("Image is mirrored.\n");
else
PWC_TRACE("Image is normal.\n");
}
pdev->vmirror = ptr[0] & 0x03;
if (fbuf->filled == 4)
pdev->drop_frames++;
} else if (pdev->type == 740 || pdev->type == 720) {
unsigned char *ptr = (unsigned char *)fbuf->data;
if ((ptr[0] ^ pdev->vmirror) & 0x01) {
pwc_snapshot_button(pdev, ptr[0] & 0x01);
}
pdev->vmirror = ptr[0] & 0x03;
}
if (pdev->drop_frames > 0) {
pdev->drop_frames--;
} else {
if (fbuf->filled < pdev->frame_total_size) {
PWC_DEBUG_FLOW("Frame buffer underflow (%d bytes);"
" discarded.\n", fbuf->filled);
} else {
fbuf->vb.v4l2_buf.field = V4L2_FIELD_NONE;
fbuf->vb.v4l2_buf.sequence = pdev->vframe_count;
vb2_buffer_done(&fbuf->vb, VB2_BUF_STATE_DONE);
pdev->fill_buf = NULL;
pdev->vsync = 0;
}
}
pdev->vframe_count++;
}
static void pwc_isoc_handler(struct urb *urb)
{
struct pwc_device *pdev = (struct pwc_device *)urb->context;
int i, fst, flen;
unsigned char *iso_buf = NULL;
if (urb->status == -ENOENT || urb->status == -ECONNRESET ||
urb->status == -ESHUTDOWN) {
PWC_DEBUG_OPEN("URB (%p) unlinked %ssynchronuously.\n", urb, urb->status == -ENOENT ? "" : "a");
return;
}
if (pdev->fill_buf == NULL)
pdev->fill_buf = pwc_get_next_fill_buf(pdev);
if (urb->status != 0) {
const char *errmsg;
errmsg = "Unknown";
switch(urb->status) {
case -ENOSR: errmsg = "Buffer error (overrun)"; break;
case -EPIPE: errmsg = "Stalled (device not responding)"; break;
case -EOVERFLOW: errmsg = "Babble (bad cable?)"; break;
case -EPROTO: errmsg = "Bit-stuff error (bad cable?)"; break;
case -EILSEQ: errmsg = "CRC/Timeout (could be anything)"; break;
case -ETIME: errmsg = "Device does not respond"; break;
}
PWC_ERROR("pwc_isoc_handler() called with status %d [%s].\n",
urb->status, errmsg);
if (++pdev->visoc_errors > MAX_ISOC_ERRORS)
{
PWC_ERROR("Too many ISOC errors, bailing out.\n");
if (pdev->fill_buf) {
vb2_buffer_done(&pdev->fill_buf->vb,
VB2_BUF_STATE_ERROR);
pdev->fill_buf = NULL;
}
}
pdev->vsync = 0;
goto handler_end;
}
pdev->visoc_errors = 0;
for (i = 0; i < urb->number_of_packets; i++) {
fst = urb->iso_frame_desc[i].status;
flen = urb->iso_frame_desc[i].actual_length;
iso_buf = urb->transfer_buffer + urb->iso_frame_desc[i].offset;
if (fst != 0) {
PWC_ERROR("Iso frame %d has error %d\n", i, fst);
continue;
}
if (flen > 0 && pdev->vsync) {
struct pwc_frame_buf *fbuf = pdev->fill_buf;
if (pdev->vsync == 1) {
do_gettimeofday(&fbuf->vb.v4l2_buf.timestamp);
pdev->vsync = 2;
}
if (flen + fbuf->filled > pdev->frame_total_size) {
PWC_ERROR("Frame overflow (%d > %d)\n",
flen + fbuf->filled,
pdev->frame_total_size);
pdev->vsync = 0;
} else {
memcpy(fbuf->data + fbuf->filled, iso_buf,
flen);
fbuf->filled += flen;
}
}
if (flen < pdev->vlast_packet_size) {
if (pdev->vsync == 2)
pwc_frame_complete(pdev);
if (pdev->fill_buf == NULL)
pdev->fill_buf = pwc_get_next_fill_buf(pdev);
if (pdev->fill_buf) {
pdev->fill_buf->filled = 0;
pdev->vsync = 1;
}
}
pdev->vlast_packet_size = flen;
}
handler_end:
i = usb_submit_urb(urb, GFP_ATOMIC);
if (i != 0)
PWC_ERROR("Error (%d) re-submitting urb in pwc_isoc_handler.\n", i);
}
static int pwc_isoc_init(struct pwc_device *pdev)
{
struct usb_device *udev;
struct urb *urb;
int i, j, ret;
struct usb_interface *intf;
struct usb_host_interface *idesc = NULL;
if (pdev->iso_init)
return 0;
pdev->vsync = 0;
pdev->vlast_packet_size = 0;
pdev->fill_buf = NULL;
pdev->vframe_count = 0;
pdev->visoc_errors = 0;
udev = pdev->udev;
intf = usb_ifnum_to_if(udev, 0);
if (intf)
idesc = usb_altnum_to_altsetting(intf, pdev->valternate);
if (!idesc)
return -EIO;
pdev->vmax_packet_size = -1;
for (i = 0; i < idesc->desc.bNumEndpoints; i++) {
if ((idesc->endpoint[i].desc.bEndpointAddress & 0xF) == pdev->vendpoint) {
pdev->vmax_packet_size = le16_to_cpu(idesc->endpoint[i].desc.wMaxPacketSize);
break;
}
}
if (pdev->vmax_packet_size < 0 || pdev->vmax_packet_size > ISO_MAX_FRAME_SIZE) {
PWC_ERROR("Failed to find packet size for video endpoint in current alternate setting.\n");
return -ENFILE;
}
ret = 0;
PWC_DEBUG_OPEN("Setting alternate interface %d\n", pdev->valternate);
ret = usb_set_interface(pdev->udev, 0, pdev->valternate);
if (ret < 0)
return ret;
for (i = 0; i < MAX_ISO_BUFS; i++) {
urb = usb_alloc_urb(ISO_FRAMES_PER_DESC, GFP_KERNEL);
if (urb == NULL) {
PWC_ERROR("Failed to allocate urb %d\n", i);
pdev->iso_init = 1;
pwc_isoc_cleanup(pdev);
return -ENOMEM;
}
pdev->urbs[i] = urb;
PWC_DEBUG_MEMORY("Allocated URB at 0x%p\n", urb);
urb->interval = 1;
urb->dev = udev;
urb->pipe = usb_rcvisocpipe(udev, pdev->vendpoint);
urb->transfer_flags = URB_ISO_ASAP | URB_NO_TRANSFER_DMA_MAP;
urb->transfer_buffer = usb_alloc_coherent(udev,
ISO_BUFFER_SIZE,
GFP_KERNEL,
&urb->transfer_dma);
if (urb->transfer_buffer == NULL) {
PWC_ERROR("Failed to allocate urb buffer %d\n", i);
pdev->iso_init = 1;
pwc_isoc_cleanup(pdev);
return -ENOMEM;
}
urb->transfer_buffer_length = ISO_BUFFER_SIZE;
urb->complete = pwc_isoc_handler;
urb->context = pdev;
urb->start_frame = 0;
urb->number_of_packets = ISO_FRAMES_PER_DESC;
for (j = 0; j < ISO_FRAMES_PER_DESC; j++) {
urb->iso_frame_desc[j].offset = j * ISO_MAX_FRAME_SIZE;
urb->iso_frame_desc[j].length = pdev->vmax_packet_size;
}
}
for (i = 0; i < MAX_ISO_BUFS; i++) {
ret = usb_submit_urb(pdev->urbs[i], GFP_KERNEL);
if (ret) {
PWC_ERROR("isoc_init() submit_urb %d failed with error %d\n", i, ret);
pdev->iso_init = 1;
pwc_isoc_cleanup(pdev);
return ret;
}
PWC_DEBUG_MEMORY("URB 0x%p submitted.\n", pdev->urbs[i]);
}
pdev->iso_init = 1;
PWC_DEBUG_OPEN("<< pwc_isoc_init()\n");
return 0;
}
static void pwc_iso_stop(struct pwc_device *pdev)
{
int i;
for (i = 0; i < MAX_ISO_BUFS; i++) {
if (pdev->urbs[i]) {
PWC_DEBUG_MEMORY("Unlinking URB %p\n", pdev->urbs[i]);
usb_kill_urb(pdev->urbs[i]);
}
}
}
static void pwc_iso_free(struct pwc_device *pdev)
{
int i;
for (i = 0; i < MAX_ISO_BUFS; i++) {
if (pdev->urbs[i]) {
PWC_DEBUG_MEMORY("Freeing URB\n");
if (pdev->urbs[i]->transfer_buffer) {
usb_free_coherent(pdev->udev,
pdev->urbs[i]->transfer_buffer_length,
pdev->urbs[i]->transfer_buffer,
pdev->urbs[i]->transfer_dma);
}
usb_free_urb(pdev->urbs[i]);
pdev->urbs[i] = NULL;
}
}
}
static void pwc_isoc_cleanup(struct pwc_device *pdev)
{
PWC_DEBUG_OPEN(">> pwc_isoc_cleanup()\n");
if (pdev->iso_init == 0)
return;
pwc_iso_stop(pdev);
pwc_iso_free(pdev);
usb_set_interface(pdev->udev, 0, 0);
pdev->iso_init = 0;
PWC_DEBUG_OPEN("<< pwc_isoc_cleanup()\n");
}
static void pwc_cleanup_queued_bufs(struct pwc_device *pdev)
{
while (!list_empty(&pdev->queued_bufs)) {
struct pwc_frame_buf *buf;
buf = list_entry(pdev->queued_bufs.next, struct pwc_frame_buf,
list);
list_del(&buf->list);
vb2_buffer_done(&buf->vb, VB2_BUF_STATE_ERROR);
}
}
static struct pwc_device *cd_to_pwc(struct device *cd)
{
struct video_device *vdev = to_video_device(cd);
return video_get_drvdata(vdev);
}
static ssize_t show_pan_tilt(struct device *class_dev,
struct device_attribute *attr, char *buf)
{
struct pwc_device *pdev = cd_to_pwc(class_dev);
return sprintf(buf, "%d %d\n", pdev->pan_angle, pdev->tilt_angle);
}
static ssize_t store_pan_tilt(struct device *class_dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct pwc_device *pdev = cd_to_pwc(class_dev);
int pan, tilt;
int ret = -EINVAL;
if (strncmp(buf, "reset", 5) == 0)
ret = pwc_mpt_reset(pdev, 0x3);
else if (sscanf(buf, "%d %d", &pan, &tilt) > 0)
ret = pwc_mpt_set_angle(pdev, pan, tilt);
if (ret < 0)
return ret;
return strlen(buf);
}
static ssize_t show_snapshot_button_status(struct device *class_dev,
struct device_attribute *attr, char *buf)
{
struct pwc_device *pdev = cd_to_pwc(class_dev);
int status = pdev->snapshot_button_status;
pdev->snapshot_button_status = 0;
return sprintf(buf, "%d\n", status);
}
static int pwc_create_sysfs_files(struct pwc_device *pdev)
{
int rc;
rc = device_create_file(&pdev->vdev.dev, &dev_attr_button);
if (rc)
goto err;
if (pdev->features & FEATURE_MOTOR_PANTILT) {
rc = device_create_file(&pdev->vdev.dev, &dev_attr_pan_tilt);
if (rc)
goto err_button;
}
return 0;
err_button:
device_remove_file(&pdev->vdev.dev, &dev_attr_button);
err:
PWC_ERROR("Could not create sysfs files.\n");
return rc;
}
static void pwc_remove_sysfs_files(struct pwc_device *pdev)
{
if (pdev->features & FEATURE_MOTOR_PANTILT)
device_remove_file(&pdev->vdev.dev, &dev_attr_pan_tilt);
device_remove_file(&pdev->vdev.dev, &dev_attr_button);
}
static const char *pwc_sensor_type_to_string(unsigned int sensor_type)
{
switch(sensor_type) {
case 0x00:
return "Hyundai CMOS sensor";
case 0x20:
return "Sony CCD sensor + TDA8787";
case 0x2E:
return "Sony CCD sensor + Exas 98L59";
case 0x2F:
return "Sony CCD sensor + ADI 9804";
case 0x30:
return "Sharp CCD sensor + TDA8787";
case 0x3E:
return "Sharp CCD sensor + Exas 98L59";
case 0x3F:
return "Sharp CCD sensor + ADI 9804";
case 0x40:
return "UPA 1021 sensor";
case 0x100:
return "VGA sensor";
case 0x101:
return "PAL MR sensor";
default:
return "unknown type of sensor";
}
}
static int pwc_video_open(struct file *file)
{
struct video_device *vdev = video_devdata(file);
struct pwc_device *pdev;
PWC_DEBUG_OPEN(">> video_open called(vdev = 0x%p).\n", vdev);
pdev = video_get_drvdata(vdev);
if (!pdev->udev)
return -ENODEV;
file->private_data = vdev;
PWC_DEBUG_OPEN("<< video_open() returns 0.\n");
return 0;
}
static void pwc_video_release(struct video_device *vfd)
{
struct pwc_device *pdev = container_of(vfd, struct pwc_device, vdev);
int hint;
for (hint = 0; hint < MAX_DEV_HINTS; hint++)
if (device_hint[hint].pdev == pdev)
device_hint[hint].pdev = NULL;
if (pdev->decompress_data != NULL) {
PWC_DEBUG_MEMORY("Freeing decompression buffer at %p.\n",
pdev->decompress_data);
kfree(pdev->decompress_data);
pdev->decompress_data = NULL;
}
v4l2_ctrl_handler_free(&pdev->ctrl_handler);
kfree(pdev);
}
static int pwc_video_close(struct file *file)
{
struct video_device *vdev = file->private_data;
struct pwc_device *pdev;
PWC_DEBUG_OPEN(">> video_close called(vdev = 0x%p).\n", vdev);
pdev = video_get_drvdata(vdev);
if (pdev->capt_file == file) {
vb2_queue_release(&pdev->vb_queue);
pdev->capt_file = NULL;
}
PWC_DEBUG_OPEN("<< video_close()\n");
return 0;
}
static ssize_t pwc_video_read(struct file *file, char __user *buf,
size_t count, loff_t *ppos)
{
struct video_device *vdev = file->private_data;
struct pwc_device *pdev = video_get_drvdata(vdev);
if (!pdev->udev)
return -ENODEV;
if (pdev->capt_file != NULL &&
pdev->capt_file != file)
return -EBUSY;
pdev->capt_file = file;
return vb2_read(&pdev->vb_queue, buf, count, ppos,
file->f_flags & O_NONBLOCK);
}
static unsigned int pwc_video_poll(struct file *file, poll_table *wait)
{
struct video_device *vdev = file->private_data;
struct pwc_device *pdev = video_get_drvdata(vdev);
if (!pdev->udev)
return POLL_ERR;
return vb2_poll(&pdev->vb_queue, file, wait);
}
static int pwc_video_mmap(struct file *file, struct vm_area_struct *vma)
{
struct video_device *vdev = file->private_data;
struct pwc_device *pdev = video_get_drvdata(vdev);
if (pdev->capt_file != file)
return -EBUSY;
return vb2_mmap(&pdev->vb_queue, vma);
}
static int queue_setup(struct vb2_queue *vq, const struct v4l2_format *fmt,
unsigned int *nbuffers, unsigned int *nplanes,
unsigned int sizes[], void *alloc_ctxs[])
{
struct pwc_device *pdev = vb2_get_drv_priv(vq);
if (*nbuffers < MIN_FRAMES)
*nbuffers = MIN_FRAMES;
else if (*nbuffers > MAX_FRAMES)
*nbuffers = MAX_FRAMES;
*nplanes = 1;
sizes[0] = PAGE_ALIGN((pdev->abs_max.x * pdev->abs_max.y * 3) / 2);
return 0;
}
static int buffer_init(struct vb2_buffer *vb)
{
struct pwc_frame_buf *buf = container_of(vb, struct pwc_frame_buf, vb);
buf->data = vzalloc(PWC_FRAME_SIZE);
if (buf->data == NULL)
return -ENOMEM;
return 0;
}
static int buffer_prepare(struct vb2_buffer *vb)
{
struct pwc_device *pdev = vb2_get_drv_priv(vb->vb2_queue);
if (!pdev->udev)
return -ENODEV;
return 0;
}
static int buffer_finish(struct vb2_buffer *vb)
{
struct pwc_device *pdev = vb2_get_drv_priv(vb->vb2_queue);
struct pwc_frame_buf *buf = container_of(vb, struct pwc_frame_buf, vb);
return pwc_decompress(pdev, buf);
}
static void buffer_cleanup(struct vb2_buffer *vb)
{
struct pwc_frame_buf *buf = container_of(vb, struct pwc_frame_buf, vb);
vfree(buf->data);
}
static void buffer_queue(struct vb2_buffer *vb)
{
struct pwc_device *pdev = vb2_get_drv_priv(vb->vb2_queue);
struct pwc_frame_buf *buf = container_of(vb, struct pwc_frame_buf, vb);
unsigned long flags = 0;
spin_lock_irqsave(&pdev->queued_bufs_lock, flags);
list_add_tail(&buf->list, &pdev->queued_bufs);
spin_unlock_irqrestore(&pdev->queued_bufs_lock, flags);
}
static int start_streaming(struct vb2_queue *vq, unsigned int count)
{
struct pwc_device *pdev = vb2_get_drv_priv(vq);
if (!pdev->udev)
return -ENODEV;
pwc_camera_power(pdev, 1);
if (pdev->power_save) {
pwc_set_video_mode(pdev, pdev->view.x, pdev->view.y,
pdev->vframes, pdev->vcompression,
pdev->vsnapshot);
}
pwc_set_leds(pdev, led_on, led_off);
return pwc_isoc_init(pdev);
}
static int stop_streaming(struct vb2_queue *vq)
{
struct pwc_device *pdev = vb2_get_drv_priv(vq);
if (pdev->udev) {
pwc_set_leds(pdev, 0, 0);
pwc_camera_power(pdev, 0);
pwc_isoc_cleanup(pdev);
}
pwc_cleanup_queued_bufs(pdev);
return 0;
}
static void pwc_lock(struct vb2_queue *vq)
{
struct pwc_device *pdev = vb2_get_drv_priv(vq);
mutex_lock(&pdev->modlock);
}
static void pwc_unlock(struct vb2_queue *vq)
{
struct pwc_device *pdev = vb2_get_drv_priv(vq);
mutex_unlock(&pdev->modlock);
}
static int usb_pwc_probe(struct usb_interface *intf, const struct usb_device_id *id)
{
struct usb_device *udev = interface_to_usbdev(intf);
struct pwc_device *pdev = NULL;
int vendor_id, product_id, type_id;
int hint, rc;
int features = 0;
int video_nr = -1;
int my_power_save = power_save;
char serial_number[30], *name;
vendor_id = le16_to_cpu(udev->descriptor.idVendor);
product_id = le16_to_cpu(udev->descriptor.idProduct);
PWC_DEBUG_PROBE("probe() called [%04X %04X], if %d\n",
vendor_id, product_id,
intf->altsetting->desc.bInterfaceNumber);
if (intf->altsetting->desc.bInterfaceNumber > 0)
return -ENODEV;
if (vendor_id == 0x0471) {
switch (product_id) {
case 0x0302:
PWC_INFO("Philips PCA645VC USB webcam detected.\n");
name = "Philips 645 webcam";
type_id = 645;
break;
case 0x0303:
PWC_INFO("Philips PCA646VC USB webcam detected.\n");
name = "Philips 646 webcam";
type_id = 646;
break;
case 0x0304:
PWC_INFO("Askey VC010 type 2 USB webcam detected.\n");
name = "Askey VC010 webcam";
type_id = 646;
break;
case 0x0307:
PWC_INFO("Philips PCVC675K (Vesta) USB webcam detected.\n");
name = "Philips 675 webcam";
type_id = 675;
break;
case 0x0308:
PWC_INFO("Philips PCVC680K (Vesta Pro) USB webcam detected.\n");
name = "Philips 680 webcam";
type_id = 680;
break;
case 0x030C:
PWC_INFO("Philips PCVC690K (Vesta Pro Scan) USB webcam detected.\n");
name = "Philips 690 webcam";
type_id = 690;
break;
case 0x0310:
PWC_INFO("Philips PCVC730K (ToUCam Fun)/PCVC830 (ToUCam II) USB webcam detected.\n");
name = "Philips 730 webcam";
type_id = 730;
break;
case 0x0311:
PWC_INFO("Philips PCVC740K (ToUCam Pro)/PCVC840 (ToUCam II) USB webcam detected.\n");
name = "Philips 740 webcam";
type_id = 740;
break;
case 0x0312:
PWC_INFO("Philips PCVC750K (ToUCam Pro Scan) USB webcam detected.\n");
name = "Philips 750 webcam";
type_id = 750;
break;
case 0x0313:
PWC_INFO("Philips PCVC720K/40 (ToUCam XS) USB webcam detected.\n");
name = "Philips 720K/40 webcam";
type_id = 720;
break;
case 0x0329:
PWC_INFO("Philips SPC 900NC USB webcam detected.\n");
name = "Philips SPC 900NC webcam";
type_id = 740;
break;
default:
return -ENODEV;
break;
}
}
else if (vendor_id == 0x069A) {
switch(product_id) {
case 0x0001:
PWC_INFO("Askey VC010 type 1 USB webcam detected.\n");
name = "Askey VC010 webcam";
type_id = 645;
break;
default:
return -ENODEV;
break;
}
}
else if (vendor_id == 0x046d) {
switch(product_id) {
case 0x08b0:
PWC_INFO("Logitech QuickCam Pro 3000 USB webcam detected.\n");
name = "Logitech QuickCam Pro 3000";
type_id = 740;
break;
case 0x08b1:
PWC_INFO("Logitech QuickCam Notebook Pro USB webcam detected.\n");
name = "Logitech QuickCam Notebook Pro";
type_id = 740;
break;
case 0x08b2:
PWC_INFO("Logitech QuickCam 4000 Pro USB webcam detected.\n");
name = "Logitech QuickCam Pro 4000";
type_id = 740;
if (my_power_save == -1)
my_power_save = 1;
break;
case 0x08b3:
PWC_INFO("Logitech QuickCam Zoom USB webcam detected.\n");
name = "Logitech QuickCam Zoom";
type_id = 740;
break;
case 0x08B4:
PWC_INFO("Logitech QuickCam Zoom (new model) USB webcam detected.\n");
name = "Logitech QuickCam Zoom";
type_id = 740;
if (my_power_save == -1)
my_power_save = 1;
break;
case 0x08b5:
PWC_INFO("Logitech QuickCam Orbit/Sphere USB webcam detected.\n");
name = "Logitech QuickCam Orbit";
type_id = 740;
if (my_power_save == -1)
my_power_save = 1;
features |= FEATURE_MOTOR_PANTILT;
break;
case 0x08b6:
PWC_INFO("Logitech/Cisco VT Camera webcam detected.\n");
name = "Cisco VT Camera";
type_id = 740;
break;
case 0x08b7:
PWC_INFO("Logitech ViewPort AV 100 webcam detected.\n");
name = "Logitech ViewPort AV 100";
type_id = 740;
break;
case 0x08b8:
PWC_INFO("Logitech QuickCam detected (reserved ID).\n");
name = "Logitech QuickCam (res.)";
type_id = 730;
break;
default:
return -ENODEV;
break;
}
}
else if (vendor_id == 0x055d) {
switch(product_id) {
case 0x9000:
PWC_INFO("Samsung MPC-C10 USB webcam detected.\n");
name = "Samsung MPC-C10";
type_id = 675;
break;
case 0x9001:
PWC_INFO("Samsung MPC-C30 USB webcam detected.\n");
name = "Samsung MPC-C30";
type_id = 675;
break;
case 0x9002:
PWC_INFO("Samsung SNC-35E (v3.0) USB webcam detected.\n");
name = "Samsung MPC-C30";
type_id = 740;
break;
default:
return -ENODEV;
break;
}
}
else if (vendor_id == 0x041e) {
switch(product_id) {
case 0x400c:
PWC_INFO("Creative Labs Webcam 5 detected.\n");
name = "Creative Labs Webcam 5";
type_id = 730;
if (my_power_save == -1)
my_power_save = 1;
break;
case 0x4011:
PWC_INFO("Creative Labs Webcam Pro Ex detected.\n");
name = "Creative Labs Webcam Pro Ex";
type_id = 740;
break;
default:
return -ENODEV;
break;
}
}
else if (vendor_id == 0x04cc) {
switch(product_id) {
case 0x8116:
PWC_INFO("Sotec Afina Eye USB webcam detected.\n");
name = "Sotec Afina Eye";
type_id = 730;
break;
default:
return -ENODEV;
break;
}
}
else if (vendor_id == 0x06be) {
switch(product_id) {
case 0x8116:
PWC_INFO("AME Co. Afina Eye USB webcam detected.\n");
name = "AME Co. Afina Eye";
type_id = 750;
break;
default:
return -ENODEV;
break;
}
}
else if (vendor_id == 0x0d81) {
switch(product_id) {
case 0x1900:
PWC_INFO("Visionite VCS-UC300 USB webcam detected.\n");
name = "Visionite VCS-UC300";
type_id = 740;
break;
case 0x1910:
PWC_INFO("Visionite VCS-UM100 USB webcam detected.\n");
name = "Visionite VCS-UM100";
type_id = 730;
break;
default:
return -ENODEV;
break;
}
}
else
return -ENODEV;
if (my_power_save == -1)
my_power_save = 0;
memset(serial_number, 0, 30);
usb_string(udev, udev->descriptor.iSerialNumber, serial_number, 29);
PWC_DEBUG_PROBE("Device serial number is %s\n", serial_number);
if (udev->descriptor.bNumConfigurations > 1)
PWC_WARNING("Warning: more than 1 configuration available.\n");
pdev = kzalloc(sizeof(struct pwc_device), GFP_KERNEL);
if (pdev == NULL) {
PWC_ERROR("Oops, could not allocate memory for pwc_device.\n");
return -ENOMEM;
}
pdev->type = type_id;
pdev->vframes = default_fps;
strcpy(pdev->serial, serial_number);
pdev->features = features;
if (vendor_id == 0x046D && product_id == 0x08B5) {
pdev->angle_range.pan_min = -7000;
pdev->angle_range.pan_max = 7000;
pdev->angle_range.tilt_min = -3000;
pdev->angle_range.tilt_max = 2500;
}
pwc_construct(pdev);
mutex_init(&pdev->modlock);
mutex_init(&pdev->udevlock);
spin_lock_init(&pdev->queued_bufs_lock);
INIT_LIST_HEAD(&pdev->queued_bufs);
pdev->udev = udev;
pdev->vcompression = pwc_preferred_compression;
pdev->power_save = my_power_save;
memset(&pdev->vb_queue, 0, sizeof(pdev->vb_queue));
pdev->vb_queue.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
pdev->vb_queue.io_modes = VB2_MMAP | VB2_USERPTR | VB2_READ;
pdev->vb_queue.drv_priv = pdev;
pdev->vb_queue.buf_struct_size = sizeof(struct pwc_frame_buf);
pdev->vb_queue.ops = &pwc_vb_queue_ops;
pdev->vb_queue.mem_ops = &vb2_vmalloc_memops;
vb2_queue_init(&pdev->vb_queue);
memcpy(&pdev->vdev, &pwc_template, sizeof(pwc_template));
pdev->vdev.parent = &intf->dev;
pdev->vdev.lock = &pdev->modlock;
strcpy(pdev->vdev.name, name);
video_set_drvdata(&pdev->vdev, pdev);
pdev->release = le16_to_cpu(udev->descriptor.bcdDevice);
PWC_DEBUG_PROBE("Release: %04x\n", pdev->release);
for (hint = 0; hint < MAX_DEV_HINTS; hint++) {
if (((device_hint[hint].type == -1) || (device_hint[hint].type == pdev->type)) &&
(device_hint[hint].pdev == NULL)) {
if ((device_hint[hint].serial_number[0] == '*') || !strcmp(device_hint[hint].serial_number, serial_number)) {
video_nr = device_hint[hint].device_node;
PWC_DEBUG_PROBE("Found hint, will try to register as /dev/video%d\n", video_nr);
break;
}
}
}
if (hint < MAX_DEV_HINTS)
device_hint[hint].pdev = pdev;
PWC_DEBUG_PROBE("probe() function returning struct at 0x%p.\n", pdev);
usb_set_intfdata(intf, pdev);
#ifdef CONFIG_USB_PWC_DEBUG
if (pwc_get_cmos_sensor(pdev, &rc) >= 0) {
PWC_DEBUG_OPEN("This %s camera is equipped with a %s (%d).\n",
pdev->vdev.name,
pwc_sensor_type_to_string(rc), rc);
}
#endif
pwc_set_leds(pdev, 0, 0);
rc = pwc_set_video_mode(pdev, pdev->view_max.x, pdev->view_max.y,
pdev->vframes, pdev->vcompression, 0);
if (rc)
goto err_free_mem;
rc = pwc_init_controls(pdev);
if (rc) {
PWC_ERROR("Failed to register v4l2 controls (%d).\n", rc);
goto err_free_mem;
}
pdev->vdev.ctrl_handler = &pdev->ctrl_handler;
pwc_camera_power(pdev, 0);
rc = video_register_device(&pdev->vdev, VFL_TYPE_GRABBER, video_nr);
if (rc < 0) {
PWC_ERROR("Failed to register as video device (%d).\n", rc);
goto err_free_controls;
}
rc = pwc_create_sysfs_files(pdev);
if (rc)
goto err_video_unreg;
PWC_INFO("Registered as %s.\n", video_device_node_name(&pdev->vdev));
#ifdef CONFIG_USB_PWC_INPUT_EVDEV
pdev->button_dev = input_allocate_device();
if (!pdev->button_dev) {
PWC_ERROR("Err, insufficient memory for webcam snapshot button device.");
rc = -ENOMEM;
pwc_remove_sysfs_files(pdev);
goto err_video_unreg;
}
usb_make_path(udev, pdev->button_phys, sizeof(pdev->button_phys));
strlcat(pdev->button_phys, "/input0", sizeof(pdev->button_phys));
pdev->button_dev->name = "PWC snapshot button";
pdev->button_dev->phys = pdev->button_phys;
usb_to_input_id(pdev->udev, &pdev->button_dev->id);
pdev->button_dev->dev.parent = &pdev->udev->dev;
pdev->button_dev->evbit[0] = BIT_MASK(EV_KEY);
pdev->button_dev->keybit[BIT_WORD(KEY_CAMERA)] = BIT_MASK(KEY_CAMERA);
rc = input_register_device(pdev->button_dev);
if (rc) {
input_free_device(pdev->button_dev);
pdev->button_dev = NULL;
pwc_remove_sysfs_files(pdev);
goto err_video_unreg;
}
#endif
return 0;
err_video_unreg:
if (hint < MAX_DEV_HINTS)
device_hint[hint].pdev = NULL;
video_unregister_device(&pdev->vdev);
err_free_controls:
v4l2_ctrl_handler_free(&pdev->ctrl_handler);
err_free_mem:
usb_set_intfdata(intf, NULL);
kfree(pdev);
return rc;
}
static void usb_pwc_disconnect(struct usb_interface *intf)
{
struct pwc_device *pdev = usb_get_intfdata(intf);
mutex_lock(&pdev->udevlock);
mutex_lock(&pdev->modlock);
usb_set_intfdata(intf, NULL);
pwc_isoc_cleanup(pdev);
pwc_cleanup_queued_bufs(pdev);
pdev->udev = NULL;
mutex_unlock(&pdev->modlock);
mutex_unlock(&pdev->udevlock);
pwc_remove_sysfs_files(pdev);
video_unregister_device(&pdev->vdev);
#ifdef CONFIG_USB_PWC_INPUT_EVDEV
if (pdev->button_dev)
input_unregister_device(pdev->button_dev);
#endif
}
static int __init usb_pwc_init(void)
{
int i;
#ifdef CONFIG_USB_PWC_DEBUG
PWC_INFO("Philips webcam module version " PWC_VERSION " loaded.\n");
PWC_INFO("Supports Philips PCA645/646, PCVC675/680/690, PCVC720[40]/730/740/750 & PCVC830/840.\n");
PWC_INFO("Also supports the Askey VC010, various Logitech Quickcams, Samsung MPC-C10 and MPC-C30,\n");
PWC_INFO("the Creative WebCam 5 & Pro Ex, SOTEC Afina Eye and Visionite VCS-UC300 and VCS-UM100.\n");
if (pwc_trace >= 0) {
PWC_DEBUG_MODULE("Trace options: 0x%04x\n", pwc_trace);
}
#endif
if (fps) {
if (fps < 4 || fps > 30) {
PWC_ERROR("Framerate out of bounds (4-30).\n");
return -EINVAL;
}
default_fps = fps;
PWC_DEBUG_MODULE("Default framerate set to %d.\n", default_fps);
}
if (compression >= 0) {
if (compression > 3) {
PWC_ERROR("Invalid compression setting; use a number between 0 (uncompressed) and 3 (high).\n");
return -EINVAL;
}
pwc_preferred_compression = compression;
PWC_DEBUG_MODULE("Preferred compression set to %d.\n", pwc_preferred_compression);
}
if (leds[0] >= 0)
led_on = leds[0];
if (leds[1] >= 0)
led_off = leds[1];
for (i = 0; i < MAX_DEV_HINTS; i++) {
char *s, *colon, *dot;
device_hint[i].pdev = NULL;
s = dev_hint[i];
if (s != NULL && *s != '\0') {
device_hint[i].type = -1;
strcpy(device_hint[i].serial_number, "*");
colon = dot = s;
while (*colon != '\0' && *colon != ':')
colon++;
while (*dot != '\0' && *dot != '.')
dot++;
if (*dot != '\0' && dot > colon) {
PWC_ERROR("Malformed camera hint: the colon must be after the dot.\n");
return -EINVAL;
}
if (*colon == '\0') {
if (*dot != '\0') {
PWC_ERROR("Malformed camera hint: no colon + device node given.\n");
return -EINVAL;
}
else {
device_hint[i].device_node =
simple_strtol(s, NULL, 10);
}
}
else {
device_hint[i].type =
simple_strtol(s, NULL, 10);
device_hint[i].device_node =
simple_strtol(colon + 1, NULL, 10);
if (*dot != '\0') {
int k;
dot++;
k = 0;
while (*dot != ':' && k < 29) {
device_hint[i].serial_number[k++] = *dot;
dot++;
}
device_hint[i].serial_number[k] = '\0';
}
}
PWC_TRACE("device_hint[%d]:\n", i);
PWC_TRACE(" type : %d\n", device_hint[i].type);
PWC_TRACE(" serial# : %s\n", device_hint[i].serial_number);
PWC_TRACE(" node : %d\n", device_hint[i].device_node);
}
else
device_hint[i].type = 0;
}
PWC_DEBUG_PROBE("Registering driver at address 0x%p.\n", &pwc_driver);
return usb_register(&pwc_driver);
}
static void __exit usb_pwc_exit(void)
{
PWC_DEBUG_MODULE("Deregistering driver.\n");
usb_deregister(&pwc_driver);
PWC_INFO("Philips webcam module removed.\n");
}
