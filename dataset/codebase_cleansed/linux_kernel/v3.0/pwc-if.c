static void *pwc_rvmalloc(unsigned long size)
{
void * mem;
unsigned long adr;
mem=vmalloc_32(size);
if (!mem)
return NULL;
memset(mem, 0, size);
adr=(unsigned long) mem;
while (size > 0)
{
SetPageReserved(vmalloc_to_page((void *)adr));
adr += PAGE_SIZE;
size -= PAGE_SIZE;
}
return mem;
}
static void pwc_rvfree(void * mem, unsigned long size)
{
unsigned long adr;
if (!mem)
return;
adr=(unsigned long) mem;
while ((long) size > 0)
{
ClearPageReserved(vmalloc_to_page((void *)adr));
adr += PAGE_SIZE;
size -= PAGE_SIZE;
}
vfree(mem);
}
static int pwc_allocate_buffers(struct pwc_device *pdev)
{
int i, err;
void *kbuf;
PWC_DEBUG_MEMORY(">> pwc_allocate_buffers(pdev = 0x%p)\n", pdev);
if (pdev == NULL)
return -ENXIO;
for (i = 0; i < MAX_ISO_BUFS; i++) {
if (pdev->sbuf[i].data == NULL) {
kbuf = kzalloc(ISO_BUFFER_SIZE, GFP_KERNEL);
if (kbuf == NULL) {
PWC_ERROR("Failed to allocate iso buffer %d.\n", i);
return -ENOMEM;
}
PWC_DEBUG_MEMORY("Allocated iso buffer at %p.\n", kbuf);
pdev->sbuf[i].data = kbuf;
}
}
if (pdev->fbuf == NULL) {
kbuf = kzalloc(default_fbufs * sizeof(struct pwc_frame_buf), GFP_KERNEL);
if (kbuf == NULL) {
PWC_ERROR("Failed to allocate frame buffer structure.\n");
return -ENOMEM;
}
PWC_DEBUG_MEMORY("Allocated frame buffer structure at %p.\n", kbuf);
pdev->fbuf = kbuf;
}
for (i = 0; i < default_fbufs; i++) {
if (pdev->fbuf[i].data == NULL) {
kbuf = vzalloc(PWC_FRAME_SIZE);
if (kbuf == NULL) {
PWC_ERROR("Failed to allocate frame buffer %d.\n", i);
return -ENOMEM;
}
PWC_DEBUG_MEMORY("Allocated frame buffer %d at %p.\n", i, kbuf);
pdev->fbuf[i].data = kbuf;
}
}
if (DEVICE_USE_CODEC1(pdev->type))
err = pwc_dec1_alloc(pdev);
else
err = pwc_dec23_alloc(pdev);
if (err) {
PWC_ERROR("Failed to allocate decompress table.\n");
return err;
}
kbuf = pwc_rvmalloc(pwc_mbufs * pdev->len_per_image);
if (kbuf == NULL) {
PWC_ERROR("Failed to allocate image buffer(s). needed (%d)\n",
pwc_mbufs * pdev->len_per_image);
return -ENOMEM;
}
PWC_DEBUG_MEMORY("Allocated image buffer at %p.\n", kbuf);
pdev->image_data = kbuf;
for (i = 0; i < pwc_mbufs; i++) {
pdev->images[i].offset = i * pdev->len_per_image;
pdev->images[i].vma_use_count = 0;
}
for (; i < MAX_IMAGES; i++) {
pdev->images[i].offset = 0;
}
kbuf = NULL;
PWC_DEBUG_MEMORY("<< pwc_allocate_buffers()\n");
return 0;
}
static void pwc_free_buffers(struct pwc_device *pdev)
{
int i;
PWC_DEBUG_MEMORY("Entering free_buffers(%p).\n", pdev);
if (pdev == NULL)
return;
for (i = 0; i < MAX_ISO_BUFS; i++)
if (pdev->sbuf[i].data != NULL) {
PWC_DEBUG_MEMORY("Freeing ISO buffer at %p.\n", pdev->sbuf[i].data);
kfree(pdev->sbuf[i].data);
pdev->sbuf[i].data = NULL;
}
if (pdev->fbuf != NULL) {
for (i = 0; i < default_fbufs; i++) {
if (pdev->fbuf[i].data != NULL) {
PWC_DEBUG_MEMORY("Freeing frame buffer %d at %p.\n", i, pdev->fbuf[i].data);
vfree(pdev->fbuf[i].data);
pdev->fbuf[i].data = NULL;
}
}
kfree(pdev->fbuf);
pdev->fbuf = NULL;
}
if (pdev->decompress_data != NULL) {
PWC_DEBUG_MEMORY("Freeing decompression buffer at %p.\n", pdev->decompress_data);
kfree(pdev->decompress_data);
pdev->decompress_data = NULL;
}
if (pdev->image_data != NULL) {
PWC_DEBUG_MEMORY("Freeing image buffer at %p.\n", pdev->image_data);
pwc_rvfree(pdev->image_data, pwc_mbufs * pdev->len_per_image);
}
pdev->image_data = NULL;
PWC_DEBUG_MEMORY("Leaving free_buffers().\n");
}
static int pwc_next_fill_frame(struct pwc_device *pdev)
{
int ret;
unsigned long flags;
ret = 0;
spin_lock_irqsave(&pdev->ptrlock, flags);
if (pdev->fill_frame != NULL) {
if (pdev->full_frames == NULL) {
pdev->full_frames = pdev->fill_frame;
pdev->full_frames_tail = pdev->full_frames;
}
else {
pdev->full_frames_tail->next = pdev->fill_frame;
pdev->full_frames_tail = pdev->fill_frame;
}
}
if (pdev->empty_frames != NULL) {
pdev->fill_frame = pdev->empty_frames;
pdev->empty_frames = pdev->empty_frames->next;
}
else {
if (pdev->full_frames == NULL) {
PWC_ERROR("Neither empty or full frames available!\n");
spin_unlock_irqrestore(&pdev->ptrlock, flags);
return -EINVAL;
}
pdev->fill_frame = pdev->full_frames;
pdev->full_frames = pdev->full_frames->next;
ret = 1;
}
pdev->fill_frame->next = NULL;
spin_unlock_irqrestore(&pdev->ptrlock, flags);
return ret;
}
static void pwc_reset_buffers(struct pwc_device *pdev)
{
int i;
unsigned long flags;
PWC_DEBUG_MEMORY(">> %s __enter__\n", __func__);
spin_lock_irqsave(&pdev->ptrlock, flags);
pdev->full_frames = NULL;
pdev->full_frames_tail = NULL;
for (i = 0; i < default_fbufs; i++) {
pdev->fbuf[i].filled = 0;
if (i > 0)
pdev->fbuf[i].next = &pdev->fbuf[i - 1];
else
pdev->fbuf->next = NULL;
}
pdev->empty_frames = &pdev->fbuf[default_fbufs - 1];
pdev->empty_frames_tail = pdev->fbuf;
pdev->read_frame = NULL;
pdev->fill_frame = pdev->empty_frames;
pdev->empty_frames = pdev->empty_frames->next;
pdev->image_read_pos = 0;
pdev->fill_image = 0;
spin_unlock_irqrestore(&pdev->ptrlock, flags);
PWC_DEBUG_MEMORY("<< %s __leaving__\n", __func__);
}
int pwc_handle_frame(struct pwc_device *pdev)
{
int ret = 0;
unsigned long flags;
spin_lock_irqsave(&pdev->ptrlock, flags);
if (pdev->read_frame != NULL) {
PWC_ERROR("Huh? Read frame still in use?\n");
spin_unlock_irqrestore(&pdev->ptrlock, flags);
return ret;
}
if (pdev->full_frames == NULL) {
PWC_ERROR("Woops. No frames ready.\n");
}
else {
pdev->read_frame = pdev->full_frames;
pdev->full_frames = pdev->full_frames->next;
pdev->read_frame->next = NULL;
}
if (pdev->read_frame != NULL) {
spin_unlock_irqrestore(&pdev->ptrlock, flags);
ret = pwc_decompress(pdev);
spin_lock_irqsave(&pdev->ptrlock, flags);
if (pdev->empty_frames == NULL) {
pdev->empty_frames = pdev->read_frame;
pdev->empty_frames_tail = pdev->empty_frames;
}
else {
pdev->empty_frames_tail->next = pdev->read_frame;
pdev->empty_frames_tail = pdev->read_frame;
}
pdev->read_frame = NULL;
}
spin_unlock_irqrestore(&pdev->ptrlock, flags);
return ret;
}
void pwc_next_image(struct pwc_device *pdev)
{
pdev->image_used[pdev->fill_image] = 0;
pdev->fill_image = (pdev->fill_image + 1) % pwc_mbufs;
}
static void pwc_frame_dumped(struct pwc_device *pdev)
{
pdev->vframes_dumped++;
if (pdev->vframe_count < FRAME_LOWMARK)
return;
if (pdev->vframes_dumped < 20)
PWC_DEBUG_FLOW("Dumping frame %d\n", pdev->vframe_count);
else if (pdev->vframes_dumped == 20)
PWC_DEBUG_FLOW("Dumping frame %d (last message)\n",
pdev->vframe_count);
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
static int pwc_rcv_short_packet(struct pwc_device *pdev, const struct pwc_frame_buf *fbuf)
{
int awake = 0;
if (pdev->type == 730) {
unsigned char *ptr = (unsigned char *)fbuf->data;
if (ptr[1] == 1 && ptr[0] & 0x10) {
PWC_TRACE("Hyundai CMOS sensor bug. Dropping frame.\n");
pdev->drop_frames += 2;
pdev->vframes_error++;
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
}
else if (pdev->type == 740 || pdev->type == 720) {
unsigned char *ptr = (unsigned char *)fbuf->data;
if ((ptr[0] ^ pdev->vmirror) & 0x01) {
pwc_snapshot_button(pdev, ptr[0] & 0x01);
}
pdev->vmirror = ptr[0] & 0x03;
}
if (pdev->drop_frames > 0)
pdev->drop_frames--;
else {
if (fbuf->filled < pdev->frame_total_size) {
PWC_DEBUG_FLOW("Frame buffer underflow (%d bytes);"
" discarded.\n", fbuf->filled);
pdev->vframes_error++;
}
else {
awake = 1;
if (pwc_next_fill_frame(pdev))
pwc_frame_dumped(pdev);
}
}
pdev->vframe_count++;
return awake;
}
static void pwc_isoc_handler(struct urb *urb)
{
struct pwc_device *pdev;
int i, fst, flen;
int awake;
struct pwc_frame_buf *fbuf;
unsigned char *fillptr = NULL, *iso_buf = NULL;
awake = 0;
pdev = (struct pwc_device *)urb->context;
if (pdev == NULL) {
PWC_ERROR("isoc_handler() called with NULL device?!\n");
return;
}
if (urb->status == -ENOENT || urb->status == -ECONNRESET) {
PWC_DEBUG_OPEN("URB (%p) unlinked %ssynchronuously.\n", urb, urb->status == -ENOENT ? "" : "a");
return;
}
if (urb->status != -EINPROGRESS && urb->status != 0) {
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
PWC_DEBUG_FLOW("pwc_isoc_handler() called with status %d [%s].\n", urb->status, errmsg);
if (++pdev->visoc_errors > MAX_ISOC_ERRORS)
{
PWC_INFO("Too many ISOC errors, bailing out.\n");
pdev->error_status = EIO;
awake = 1;
wake_up_interruptible(&pdev->frameq);
}
goto handler_end;
}
fbuf = pdev->fill_frame;
if (fbuf == NULL) {
PWC_ERROR("pwc_isoc_handler without valid fill frame.\n");
awake = 1;
goto handler_end;
}
else {
fillptr = fbuf->data + fbuf->filled;
}
pdev->visoc_errors = 0;
for (i = 0; i < urb->number_of_packets; i++) {
fst = urb->iso_frame_desc[i].status;
flen = urb->iso_frame_desc[i].actual_length;
iso_buf = urb->transfer_buffer + urb->iso_frame_desc[i].offset;
if (fst == 0) {
if (flen > 0) {
if (pdev->vsync > 0) {
pdev->vsync = 2;
if (flen + fbuf->filled > pdev->frame_total_size) {
PWC_DEBUG_FLOW("Frame buffer overflow (flen = %d, frame_total_size = %d).\n", flen, pdev->frame_total_size);
pdev->vsync = 0;
pdev->vframes_error++;
}
else {
memmove(fillptr, iso_buf, flen);
fillptr += flen;
}
}
fbuf->filled += flen;
}
if (flen < pdev->vlast_packet_size) {
if (pdev->vsync == 2) {
if (pwc_rcv_short_packet(pdev, fbuf)) {
awake = 1;
fbuf = pdev->fill_frame;
}
}
fbuf->filled = 0;
fillptr = fbuf->data;
pdev->vsync = 1;
}
pdev->vlast_packet_size = flen;
}
else {
static int iso_error;
iso_error++;
if (iso_error < 20)
PWC_DEBUG_FLOW("Iso frame %d of USB has error %d\n", i, fst);
}
}
handler_end:
if (awake)
wake_up_interruptible(&pdev->frameq);
urb->dev = pdev->udev;
i = usb_submit_urb(urb, GFP_ATOMIC);
if (i != 0)
PWC_ERROR("Error (%d) re-submitting urb in pwc_isoc_handler.\n", i);
}
int pwc_isoc_init(struct pwc_device *pdev)
{
struct usb_device *udev;
struct urb *urb;
int i, j, ret;
struct usb_interface *intf;
struct usb_host_interface *idesc = NULL;
if (pdev == NULL)
return -EFAULT;
if (pdev->iso_init)
return 0;
pdev->vsync = 0;
udev = pdev->udev;
if (!udev->actconfig)
return -EFAULT;
intf = usb_ifnum_to_if(udev, 0);
if (intf)
idesc = usb_altnum_to_altsetting(intf, pdev->valternate);
if (!idesc)
return -EFAULT;
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
ret = -ENOMEM;
break;
}
pdev->sbuf[i].urb = urb;
PWC_DEBUG_MEMORY("Allocated URB at 0x%p\n", urb);
}
if (ret) {
while (i--) {
usb_free_urb(pdev->sbuf[i].urb);
pdev->sbuf[i].urb = NULL;
}
return ret;
}
for (i = 0; i < MAX_ISO_BUFS; i++) {
urb = pdev->sbuf[i].urb;
urb->interval = 1;
urb->dev = udev;
urb->pipe = usb_rcvisocpipe(udev, pdev->vendpoint);
urb->transfer_flags = URB_ISO_ASAP;
urb->transfer_buffer = pdev->sbuf[i].data;
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
ret = usb_submit_urb(pdev->sbuf[i].urb, GFP_KERNEL);
if (ret) {
PWC_ERROR("isoc_init() submit_urb %d failed with error %d\n", i, ret);
pdev->iso_init = 1;
pwc_isoc_cleanup(pdev);
return ret;
}
PWC_DEBUG_MEMORY("URB 0x%p submitted.\n", pdev->sbuf[i].urb);
}
pdev->iso_init = 1;
PWC_DEBUG_OPEN("<< pwc_isoc_init()\n");
return 0;
}
static void pwc_iso_stop(struct pwc_device *pdev)
{
int i;
for (i = 0; i < MAX_ISO_BUFS; i++) {
struct urb *urb;
urb = pdev->sbuf[i].urb;
if (urb) {
PWC_DEBUG_MEMORY("Unlinking URB %p\n", urb);
usb_kill_urb(urb);
}
}
}
static void pwc_iso_free(struct pwc_device *pdev)
{
int i;
for (i = 0; i < MAX_ISO_BUFS; i++) {
struct urb *urb;
urb = pdev->sbuf[i].urb;
if (urb) {
PWC_DEBUG_MEMORY("Freeing URB\n");
usb_free_urb(urb);
pdev->sbuf[i].urb = NULL;
}
}
}
void pwc_isoc_cleanup(struct pwc_device *pdev)
{
PWC_DEBUG_OPEN(">> pwc_isoc_cleanup()\n");
if (pdev == NULL)
return;
if (pdev->iso_init == 0)
return;
pwc_iso_stop(pdev);
pwc_iso_free(pdev);
if (pdev->error_status != EPIPE) {
PWC_DEBUG_OPEN("Setting alternate interface 0.\n");
usb_set_interface(pdev->udev, 0, 0);
}
pdev->iso_init = 0;
PWC_DEBUG_OPEN("<< pwc_isoc_cleanup()\n");
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
int i, ret;
struct video_device *vdev = video_devdata(file);
struct pwc_device *pdev;
PWC_DEBUG_OPEN(">> video_open called(vdev = 0x%p).\n", vdev);
pdev = video_get_drvdata(vdev);
BUG_ON(!pdev);
if (pdev->vopen) {
PWC_DEBUG_OPEN("I'm busy, someone is using the device.\n");
return -EBUSY;
}
pwc_construct(pdev);
if (!pdev->usb_init) {
PWC_DEBUG_OPEN("Doing first time initialization.\n");
pdev->usb_init = 1;
ret = pwc_get_cmos_sensor(pdev, &i);
if (ret >= 0)
{
PWC_DEBUG_OPEN("This %s camera is equipped with a %s (%d).\n",
pdev->vdev.name,
pwc_sensor_type_to_string(i), i);
}
}
if (power_save) {
i = pwc_camera_power(pdev, 1);
if (i < 0)
PWC_DEBUG_OPEN("Failed to restore power to the camera! (%d)\n", i);
}
if (pwc_set_leds(pdev, led_on, led_off) < 0)
PWC_DEBUG_OPEN("Failed to set LED on/off time.\n");
i = pwc_allocate_buffers(pdev);
if (i < 0) {
PWC_DEBUG_OPEN("Failed to allocate buffers memory.\n");
pwc_free_buffers(pdev);
return i;
}
pwc_reset_buffers(pdev);
for (i = 0; i < pwc_mbufs; i++)
pdev->image_used[i] = 0;
pdev->vframe_count = 0;
pdev->vframes_dumped = 0;
pdev->vframes_error = 0;
pdev->visoc_errors = 0;
pdev->error_status = 0;
pwc_construct(pdev);
pdev->vsnapshot = 0;
i = pwc_set_video_mode(pdev, pwc_image_sizes[pdev->vsize].x, pwc_image_sizes[pdev->vsize].y, pdev->vframes, pdev->vcompression, 0);
if (i) {
unsigned int default_resolution;
PWC_DEBUG_OPEN("First attempt at set_video_mode failed.\n");
if (pdev->type>= 730)
default_resolution = PSZ_QSIF;
else
default_resolution = PSZ_QCIF;
i = pwc_set_video_mode(pdev,
pwc_image_sizes[default_resolution].x,
pwc_image_sizes[default_resolution].y,
10,
pdev->vcompression,
0);
}
if (i) {
PWC_DEBUG_OPEN("Second attempt at set_video_mode failed.\n");
pwc_free_buffers(pdev);
return i;
}
pwc_set_brightness(pdev, 0x7fff);
pwc_set_agc(pdev, 1, 0);
pdev->vopen++;
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
kfree(pdev);
}
static int pwc_video_close(struct file *file)
{
struct video_device *vdev = file->private_data;
struct pwc_device *pdev;
int i;
PWC_DEBUG_OPEN(">> video_close called(vdev = 0x%p).\n", vdev);
pdev = video_get_drvdata(vdev);
if (pdev->vopen == 0)
PWC_DEBUG_MODULE("video_close() called on closed device?\n");
if (pdev->vframe_count > 20)
PWC_DEBUG_MODULE("Closing video device: %d frames received, dumped %d frames, %d frames with errors.\n", pdev->vframe_count, pdev->vframes_dumped, pdev->vframes_error);
if (DEVICE_USE_CODEC1(pdev->type))
pwc_dec1_exit();
else
pwc_dec23_exit();
pwc_isoc_cleanup(pdev);
pwc_free_buffers(pdev);
if (!pdev->unplugged) {
if (pwc_set_leds(pdev, 0, 0) < 0)
PWC_DEBUG_MODULE("Failed to set LED on/off time.\n");
if (power_save) {
i = pwc_camera_power(pdev, 0);
if (i < 0)
PWC_ERROR("Failed to power down camera (%d)\n", i);
}
pdev->vopen--;
PWC_DEBUG_OPEN("<< video_close() vopen=%d\n", pdev->vopen);
}
return 0;
}
static ssize_t pwc_video_read(struct file *file, char __user *buf,
size_t count, loff_t *ppos)
{
struct video_device *vdev = file->private_data;
struct pwc_device *pdev;
int noblock = file->f_flags & O_NONBLOCK;
DECLARE_WAITQUEUE(wait, current);
int bytes_to_read, rv = 0;
void *image_buffer_addr;
PWC_DEBUG_READ("pwc_video_read(vdev=0x%p, buf=%p, count=%zd) called.\n",
vdev, buf, count);
if (vdev == NULL)
return -EFAULT;
pdev = video_get_drvdata(vdev);
if (pdev == NULL)
return -EFAULT;
if (pdev->error_status) {
rv = -pdev->error_status;
goto err_out;
}
rv = pwc_isoc_init(pdev);
if (rv)
goto err_out;
if (pdev->image_read_pos == 0) {
add_wait_queue(&pdev->frameq, &wait);
while (pdev->full_frames == NULL) {
if (pdev->error_status) {
remove_wait_queue(&pdev->frameq, &wait);
set_current_state(TASK_RUNNING);
rv = -pdev->error_status ;
goto err_out;
}
if (noblock) {
remove_wait_queue(&pdev->frameq, &wait);
set_current_state(TASK_RUNNING);
rv = -EWOULDBLOCK;
goto err_out;
}
if (signal_pending(current)) {
remove_wait_queue(&pdev->frameq, &wait);
set_current_state(TASK_RUNNING);
rv = -ERESTARTSYS;
goto err_out;
}
mutex_unlock(&pdev->modlock);
schedule();
set_current_state(TASK_INTERRUPTIBLE);
mutex_lock(&pdev->modlock);
}
remove_wait_queue(&pdev->frameq, &wait);
set_current_state(TASK_RUNNING);
if (pwc_handle_frame(pdev)) {
rv = -EFAULT;
goto err_out;
}
}
PWC_DEBUG_READ("Copying data to user space.\n");
if (pdev->pixfmt != V4L2_PIX_FMT_YUV420)
bytes_to_read = pdev->frame_size + sizeof(struct pwc_raw_frame);
else
bytes_to_read = pdev->view.size;
if (count + pdev->image_read_pos > bytes_to_read)
count = bytes_to_read - pdev->image_read_pos;
image_buffer_addr = pdev->image_data;
image_buffer_addr += pdev->images[pdev->fill_image].offset;
image_buffer_addr += pdev->image_read_pos;
if (copy_to_user(buf, image_buffer_addr, count)) {
rv = -EFAULT;
goto err_out;
}
pdev->image_read_pos += count;
if (pdev->image_read_pos >= bytes_to_read) {
pdev->image_read_pos = 0;
pwc_next_image(pdev);
}
return count;
err_out:
return rv;
}
static unsigned int pwc_video_poll(struct file *file, poll_table *wait)
{
struct video_device *vdev = file->private_data;
struct pwc_device *pdev;
int ret;
if (vdev == NULL)
return -EFAULT;
pdev = video_get_drvdata(vdev);
if (pdev == NULL)
return -EFAULT;
ret = pwc_isoc_init(pdev);
if (ret)
return ret;
poll_wait(file, &pdev->frameq, wait);
if (pdev->error_status)
return POLLERR;
if (pdev->full_frames != NULL)
return (POLLIN | POLLRDNORM);
return 0;
}
static int pwc_video_mmap(struct file *file, struct vm_area_struct *vma)
{
struct video_device *vdev = file->private_data;
struct pwc_device *pdev;
unsigned long start;
unsigned long size;
unsigned long page, pos = 0;
int index;
PWC_DEBUG_MEMORY(">> %s\n", __func__);
pdev = video_get_drvdata(vdev);
size = vma->vm_end - vma->vm_start;
start = vma->vm_start;
for (index = 0; index < pwc_mbufs; index++) {
pos = pdev->images[index].offset;
if ((pos>>PAGE_SHIFT) == vma->vm_pgoff)
break;
}
if (index == MAX_IMAGES)
return -EINVAL;
if (index == 0) {
unsigned long total_size;
total_size = pwc_mbufs * pdev->len_per_image;
if (size != pdev->len_per_image && size != total_size) {
PWC_ERROR("Wrong size (%lu) needed to be len_per_image=%d or total_size=%lu\n",
size, pdev->len_per_image, total_size);
return -EINVAL;
}
} else if (size > pdev->len_per_image)
return -EINVAL;
vma->vm_flags |= VM_IO;
pos += (unsigned long)pdev->image_data;
while (size > 0) {
page = vmalloc_to_pfn((void *)pos);
if (remap_pfn_range(vma, start, page, PAGE_SIZE, PAGE_SHARED))
return -EAGAIN;
start += PAGE_SIZE;
pos += PAGE_SIZE;
if (size > PAGE_SIZE)
size -= PAGE_SIZE;
else
size = 0;
}
return 0;
}
static int usb_pwc_probe(struct usb_interface *intf, const struct usb_device_id *id)
{
struct usb_device *udev = interface_to_usbdev(intf);
struct pwc_device *pdev = NULL;
int vendor_id, product_id, type_id;
int hint, rc;
int features = 0;
int video_nr = -1;
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
power_save = 1;
break;
case 0x08b5:
PWC_INFO("Logitech QuickCam Orbit/Sphere USB webcam detected.\n");
name = "Logitech QuickCam Orbit";
type_id = 740;
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
pdev->vsize = default_size;
pdev->vframes = default_fps;
strcpy(pdev->serial, serial_number);
pdev->features = features;
if (vendor_id == 0x046D && product_id == 0x08B5) {
pdev->angle_range.pan_min = -7000;
pdev->angle_range.pan_max = 7000;
pdev->angle_range.tilt_min = -3000;
pdev->angle_range.tilt_max = 2500;
}
mutex_init(&pdev->modlock);
spin_lock_init(&pdev->ptrlock);
pdev->udev = udev;
init_waitqueue_head(&pdev->frameq);
pdev->vcompression = pwc_preferred_compression;
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
pwc_set_leds(pdev, 0, 0);
pwc_camera_power(pdev, 0);
rc = video_register_device(&pdev->vdev, VFL_TYPE_GRABBER, video_nr);
if (rc < 0) {
PWC_ERROR("Failed to register as video device (%d).\n", rc);
goto err_free_mem;
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
err_free_mem:
kfree(pdev);
return rc;
}
static void usb_pwc_disconnect(struct usb_interface *intf)
{
struct pwc_device *pdev = usb_get_intfdata(intf);
mutex_lock(&pdev->modlock);
usb_set_intfdata (intf, NULL);
if (pdev == NULL) {
PWC_ERROR("pwc_disconnect() Called without private pointer.\n");
goto disconnect_out;
}
if (pdev->udev == NULL) {
PWC_ERROR("pwc_disconnect() already called for %p\n", pdev);
goto disconnect_out;
}
if (pdev->udev != interface_to_usbdev(intf)) {
PWC_ERROR("pwc_disconnect() Woops: pointer mismatch udev/pdev.\n");
goto disconnect_out;
}
pdev->error_status = EPIPE;
pdev->unplugged = 1;
wake_up_interruptible(&pdev->frameq);
pwc_isoc_cleanup(pdev);
disconnect_out:
mutex_unlock(&pdev->modlock);
pwc_remove_sysfs_files(pdev);
video_unregister_device(&pdev->vdev);
#ifdef CONFIG_USB_PWC_INPUT_EVDEV
if (pdev->button_dev)
input_unregister_device(pdev->button_dev);
#endif
}
static int __init usb_pwc_init(void)
{
int i, sz;
char *sizenames[PSZ_MAX] = { "sqcif", "qsif", "qcif", "sif", "cif", "vga" };
PWC_INFO("Philips webcam module version " PWC_VERSION " loaded.\n");
PWC_INFO("Supports Philips PCA645/646, PCVC675/680/690, PCVC720[40]/730/740/750 & PCVC830/840.\n");
PWC_INFO("Also supports the Askey VC010, various Logitech Quickcams, Samsung MPC-C10 and MPC-C30,\n");
PWC_INFO("the Creative WebCam 5 & Pro Ex, SOTEC Afina Eye and Visionite VCS-UC300 and VCS-UM100.\n");
if (fps) {
if (fps < 4 || fps > 30) {
PWC_ERROR("Framerate out of bounds (4-30).\n");
return -EINVAL;
}
default_fps = fps;
PWC_DEBUG_MODULE("Default framerate set to %d.\n", default_fps);
}
if (size) {
for (sz = 0; sz < PSZ_MAX; sz++) {
if (!strcmp(sizenames[sz], size)) {
default_size = sz;
break;
}
}
if (sz == PSZ_MAX) {
PWC_ERROR("Size not recognized; try size=[sqcif | qsif | qcif | sif | cif | vga].\n");
return -EINVAL;
}
PWC_DEBUG_MODULE("Default image size set to %s [%dx%d].\n", sizenames[default_size], pwc_image_sizes[default_size].x, pwc_image_sizes[default_size].y);
}
if (mbufs) {
if (mbufs < 1 || mbufs > MAX_IMAGES) {
PWC_ERROR("Illegal number of mmap() buffers; use a number between 1 and %d.\n", MAX_IMAGES);
return -EINVAL;
}
pwc_mbufs = mbufs;
PWC_DEBUG_MODULE("Number of image buffers set to %d.\n", pwc_mbufs);
}
if (fbufs) {
if (fbufs < 2 || fbufs > MAX_FRAMES) {
PWC_ERROR("Illegal number of frame buffers; use a number between 2 and %d.\n", MAX_FRAMES);
return -EINVAL;
}
default_fbufs = fbufs;
PWC_DEBUG_MODULE("Number of frame buffers set to %d.\n", default_fbufs);
}
#ifdef CONFIG_USB_PWC_DEBUG
if (pwc_trace >= 0) {
PWC_DEBUG_MODULE("Trace options: 0x%04x\n", pwc_trace);
}
#endif
if (compression >= 0) {
if (compression > 3) {
PWC_ERROR("Invalid compression setting; use a number between 0 (uncompressed) and 3 (high).\n");
return -EINVAL;
}
pwc_preferred_compression = compression;
PWC_DEBUG_MODULE("Preferred compression set to %d.\n", pwc_preferred_compression);
}
if (power_save)
PWC_DEBUG_MODULE("Enabling power save on open/close.\n");
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
