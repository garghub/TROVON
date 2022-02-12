static void free_imon_context(struct imon_context *ictx)
{
struct device *dev = ictx->dev;
usb_free_urb(ictx->tx_urb);
usb_free_urb(ictx->rx_urb_intf0);
usb_free_urb(ictx->rx_urb_intf1);
kfree(ictx);
dev_dbg(dev, "%s: iMON context freed\n", __func__);
}
static int display_open(struct inode *inode, struct file *file)
{
struct usb_interface *interface;
struct imon_context *ictx = NULL;
int subminor;
int retval = 0;
mutex_lock(&driver_lock);
subminor = iminor(inode);
interface = usb_find_interface(&imon_driver, subminor);
if (!interface) {
pr_err("could not find interface for minor %d\n", subminor);
retval = -ENODEV;
goto exit;
}
ictx = usb_get_intfdata(interface);
if (!ictx) {
pr_err("no context found for minor %d\n", subminor);
retval = -ENODEV;
goto exit;
}
mutex_lock(&ictx->lock);
if (!ictx->display_supported) {
pr_err("display not supported by device\n");
retval = -ENODEV;
} else if (ictx->display_isopen) {
pr_err("display port is already open\n");
retval = -EBUSY;
} else {
ictx->display_isopen = true;
file->private_data = ictx;
dev_dbg(ictx->dev, "display port opened\n");
}
mutex_unlock(&ictx->lock);
exit:
mutex_unlock(&driver_lock);
return retval;
}
static int display_close(struct inode *inode, struct file *file)
{
struct imon_context *ictx = NULL;
int retval = 0;
ictx = file->private_data;
if (!ictx) {
pr_err("no context for device\n");
return -ENODEV;
}
mutex_lock(&ictx->lock);
if (!ictx->display_supported) {
pr_err("display not supported by device\n");
retval = -ENODEV;
} else if (!ictx->display_isopen) {
pr_err("display is not open\n");
retval = -EIO;
} else {
ictx->display_isopen = false;
dev_dbg(ictx->dev, "display port closed\n");
}
mutex_unlock(&ictx->lock);
return retval;
}
static int send_packet(struct imon_context *ictx)
{
unsigned int pipe;
unsigned long timeout;
int interval = 0;
int retval = 0;
struct usb_ctrlrequest *control_req = NULL;
if (!ictx->tx_control) {
pipe = usb_sndintpipe(ictx->usbdev_intf0,
ictx->tx_endpoint->bEndpointAddress);
interval = ictx->tx_endpoint->bInterval;
usb_fill_int_urb(ictx->tx_urb, ictx->usbdev_intf0, pipe,
ictx->usb_tx_buf,
sizeof(ictx->usb_tx_buf),
usb_tx_callback, ictx, interval);
ictx->tx_urb->actual_length = 0;
} else {
control_req = kmalloc(sizeof(struct usb_ctrlrequest),
GFP_KERNEL);
if (control_req == NULL)
return -ENOMEM;
control_req->bRequestType = 0x21;
control_req->bRequest = 0x09;
control_req->wValue = cpu_to_le16(0x0200);
control_req->wIndex = cpu_to_le16(0x0001);
control_req->wLength = cpu_to_le16(0x0008);
pipe = usb_sndctrlpipe(ictx->usbdev_intf0, 0);
usb_fill_control_urb(ictx->tx_urb, ictx->usbdev_intf0,
pipe, (unsigned char *)control_req,
ictx->usb_tx_buf,
sizeof(ictx->usb_tx_buf),
usb_tx_callback, ictx);
ictx->tx_urb->actual_length = 0;
}
init_completion(&ictx->tx.finished);
ictx->tx.busy = true;
smp_rmb();
retval = usb_submit_urb(ictx->tx_urb, GFP_KERNEL);
if (retval) {
ictx->tx.busy = false;
smp_rmb();
pr_err_ratelimited("error submitting urb(%d)\n", retval);
} else {
mutex_unlock(&ictx->lock);
retval = wait_for_completion_interruptible(
&ictx->tx.finished);
if (retval) {
usb_kill_urb(ictx->tx_urb);
pr_err_ratelimited("task interrupted\n");
}
mutex_lock(&ictx->lock);
retval = ictx->tx.status;
if (retval)
pr_err_ratelimited("packet tx failed (%d)\n", retval);
}
kfree(control_req);
timeout = msecs_to_jiffies(ictx->send_packet_delay);
set_current_state(TASK_INTERRUPTIBLE);
schedule_timeout(timeout);
return retval;
}
static int send_associate_24g(struct imon_context *ictx)
{
int retval;
const unsigned char packet[8] = { 0x01, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x20 };
if (!ictx) {
pr_err("no context for device\n");
return -ENODEV;
}
if (!ictx->dev_present_intf0) {
pr_err("no iMON device present\n");
return -ENODEV;
}
memcpy(ictx->usb_tx_buf, packet, sizeof(packet));
retval = send_packet(ictx);
return retval;
}
static int send_set_imon_clock(struct imon_context *ictx,
unsigned int year, unsigned int month,
unsigned int day, unsigned int dow,
unsigned int hour, unsigned int minute,
unsigned int second)
{
unsigned char clock_enable_pkt[IMON_CLOCK_ENABLE_PACKETS][8];
int retval = 0;
int i;
if (!ictx) {
pr_err("no context for device\n");
return -ENODEV;
}
switch (ictx->display_type) {
case IMON_DISPLAY_TYPE_LCD:
clock_enable_pkt[0][0] = 0x80;
clock_enable_pkt[0][1] = year;
clock_enable_pkt[0][2] = month-1;
clock_enable_pkt[0][3] = day;
clock_enable_pkt[0][4] = hour;
clock_enable_pkt[0][5] = minute;
clock_enable_pkt[0][6] = second;
clock_enable_pkt[1][0] = 0x80;
clock_enable_pkt[1][1] = 0;
clock_enable_pkt[1][2] = 0;
clock_enable_pkt[1][3] = 0;
clock_enable_pkt[1][4] = 0;
clock_enable_pkt[1][5] = 0;
clock_enable_pkt[1][6] = 0;
if (ictx->product == 0xffdc) {
clock_enable_pkt[0][7] = 0x50;
clock_enable_pkt[1][7] = 0x51;
} else {
clock_enable_pkt[0][7] = 0x88;
clock_enable_pkt[1][7] = 0x8a;
}
break;
case IMON_DISPLAY_TYPE_VFD:
clock_enable_pkt[0][0] = year;
clock_enable_pkt[0][1] = month-1;
clock_enable_pkt[0][2] = day;
clock_enable_pkt[0][3] = dow;
clock_enable_pkt[0][4] = hour;
clock_enable_pkt[0][5] = minute;
clock_enable_pkt[0][6] = second;
clock_enable_pkt[0][7] = 0x40;
clock_enable_pkt[1][0] = 0;
clock_enable_pkt[1][1] = 0;
clock_enable_pkt[1][2] = 1;
clock_enable_pkt[1][3] = 0;
clock_enable_pkt[1][4] = 0;
clock_enable_pkt[1][5] = 0;
clock_enable_pkt[1][6] = 0;
clock_enable_pkt[1][7] = 0x42;
break;
default:
return -ENODEV;
}
for (i = 0; i < IMON_CLOCK_ENABLE_PACKETS; i++) {
memcpy(ictx->usb_tx_buf, clock_enable_pkt[i], 8);
retval = send_packet(ictx);
if (retval) {
pr_err("send_packet failed for packet %d\n", i);
break;
}
}
return retval;
}
static ssize_t show_associate_remote(struct device *d,
struct device_attribute *attr,
char *buf)
{
struct imon_context *ictx = dev_get_drvdata(d);
if (!ictx)
return -ENODEV;
mutex_lock(&ictx->lock);
if (ictx->rf_isassociating)
strcpy(buf, "associating\n");
else
strcpy(buf, "closed\n");
dev_info(d, "Visit http://www.lirc.org/html/imon-24g.html for "
"instructions on how to associate your iMON 2.4G DT/LT "
"remote\n");
mutex_unlock(&ictx->lock);
return strlen(buf);
}
static ssize_t store_associate_remote(struct device *d,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct imon_context *ictx;
ictx = dev_get_drvdata(d);
if (!ictx)
return -ENODEV;
mutex_lock(&ictx->lock);
ictx->rf_isassociating = true;
send_associate_24g(ictx);
mutex_unlock(&ictx->lock);
return count;
}
static ssize_t show_imon_clock(struct device *d,
struct device_attribute *attr, char *buf)
{
struct imon_context *ictx = dev_get_drvdata(d);
size_t len;
if (!ictx)
return -ENODEV;
mutex_lock(&ictx->lock);
if (!ictx->display_supported) {
len = snprintf(buf, PAGE_SIZE, "Not supported.");
} else {
len = snprintf(buf, PAGE_SIZE,
"To set the clock on your iMON display:\n"
"# date \"+%%y %%m %%d %%w %%H %%M %%S\" > imon_clock\n"
"%s", ictx->display_isopen ?
"\nNOTE: imon device must be closed\n" : "");
}
mutex_unlock(&ictx->lock);
return len;
}
static ssize_t store_imon_clock(struct device *d,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct imon_context *ictx = dev_get_drvdata(d);
ssize_t retval;
unsigned int year, month, day, dow, hour, minute, second;
if (!ictx)
return -ENODEV;
mutex_lock(&ictx->lock);
if (!ictx->display_supported) {
retval = -ENODEV;
goto exit;
} else if (ictx->display_isopen) {
retval = -EBUSY;
goto exit;
}
if (sscanf(buf, "%u %u %u %u %u %u %u", &year, &month, &day, &dow,
&hour, &minute, &second) != 7) {
retval = -EINVAL;
goto exit;
}
if ((month < 1 || month > 12) ||
(day < 1 || day > 31) || (dow > 6) ||
(hour > 23) || (minute > 59) || (second > 59)) {
retval = -EINVAL;
goto exit;
}
retval = send_set_imon_clock(ictx, year, month, day, dow,
hour, minute, second);
if (retval)
goto exit;
retval = count;
exit:
mutex_unlock(&ictx->lock);
return retval;
}
static ssize_t vfd_write(struct file *file, const char *buf,
size_t n_bytes, loff_t *pos)
{
int i;
int offset;
int seq;
int retval = 0;
struct imon_context *ictx;
const unsigned char vfd_packet6[] = {
0x01, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF };
ictx = file->private_data;
if (!ictx) {
pr_err_ratelimited("no context for device\n");
return -ENODEV;
}
mutex_lock(&ictx->lock);
if (!ictx->dev_present_intf0) {
pr_err_ratelimited("no iMON device present\n");
retval = -ENODEV;
goto exit;
}
if (n_bytes <= 0 || n_bytes > 32) {
pr_err_ratelimited("invalid payload size\n");
retval = -EINVAL;
goto exit;
}
if (copy_from_user(ictx->tx.data_buf, buf, n_bytes)) {
retval = -EFAULT;
goto exit;
}
for (i = n_bytes; i < 32; ++i)
ictx->tx.data_buf[i] = ' ';
for (i = 32; i < 35; ++i)
ictx->tx.data_buf[i] = 0xFF;
offset = 0;
seq = 0;
do {
memcpy(ictx->usb_tx_buf, ictx->tx.data_buf + offset, 7);
ictx->usb_tx_buf[7] = (unsigned char) seq;
retval = send_packet(ictx);
if (retval) {
pr_err_ratelimited("send packet #%d failed\n", seq / 2);
goto exit;
} else {
seq += 2;
offset += 7;
}
} while (offset < 35);
memcpy(ictx->usb_tx_buf, &vfd_packet6, sizeof(vfd_packet6));
ictx->usb_tx_buf[7] = (unsigned char) seq;
retval = send_packet(ictx);
if (retval)
pr_err_ratelimited("send packet #%d failed\n", seq / 2);
exit:
mutex_unlock(&ictx->lock);
return (!retval) ? n_bytes : retval;
}
static ssize_t lcd_write(struct file *file, const char *buf,
size_t n_bytes, loff_t *pos)
{
int retval = 0;
struct imon_context *ictx;
ictx = file->private_data;
if (!ictx) {
pr_err_ratelimited("no context for device\n");
return -ENODEV;
}
mutex_lock(&ictx->lock);
if (!ictx->display_supported) {
pr_err_ratelimited("no iMON display present\n");
retval = -ENODEV;
goto exit;
}
if (n_bytes != 8) {
pr_err_ratelimited("invalid payload size: %d (expected 8)\n",
(int)n_bytes);
retval = -EINVAL;
goto exit;
}
if (copy_from_user(ictx->usb_tx_buf, buf, 8)) {
retval = -EFAULT;
goto exit;
}
retval = send_packet(ictx);
if (retval) {
pr_err_ratelimited("send packet failed!\n");
goto exit;
} else {
dev_dbg(ictx->dev, "%s: write %d bytes to LCD\n",
__func__, (int) n_bytes);
}
exit:
mutex_unlock(&ictx->lock);
return (!retval) ? n_bytes : retval;
}
static void usb_tx_callback(struct urb *urb)
{
struct imon_context *ictx;
if (!urb)
return;
ictx = (struct imon_context *)urb->context;
if (!ictx)
return;
ictx->tx.status = urb->status;
ictx->tx.busy = false;
smp_rmb();
complete(&ictx->tx.finished);
}
static void imon_touch_display_timeout(unsigned long data)
{
struct imon_context *ictx = (struct imon_context *)data;
if (ictx->display_type != IMON_DISPLAY_TYPE_VGA)
return;
input_report_abs(ictx->touch, ABS_X, ictx->touch_x);
input_report_abs(ictx->touch, ABS_Y, ictx->touch_y);
input_report_key(ictx->touch, BTN_TOUCH, 0x00);
input_sync(ictx->touch);
}
static int imon_ir_change_protocol(struct rc_dev *rc, u64 *rc_type)
{
int retval;
struct imon_context *ictx = rc->priv;
struct device *dev = ictx->dev;
bool unlock = false;
unsigned char ir_proto_packet[] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x86 };
if (*rc_type && !(*rc_type & rc->allowed_protos))
dev_warn(dev, "Looks like you're trying to use an IR protocol "
"this device does not support\n");
if (*rc_type & RC_BIT_RC6_MCE) {
dev_dbg(dev, "Configuring IR receiver for MCE protocol\n");
ir_proto_packet[0] = 0x01;
*rc_type = RC_BIT_RC6_MCE;
} else if (*rc_type & RC_BIT_OTHER) {
dev_dbg(dev, "Configuring IR receiver for iMON protocol\n");
if (!pad_stabilize)
dev_dbg(dev, "PAD stabilize functionality disabled\n");
*rc_type = RC_BIT_OTHER;
} else {
dev_warn(dev, "Unsupported IR protocol specified, overriding "
"to iMON IR protocol\n");
if (!pad_stabilize)
dev_dbg(dev, "PAD stabilize functionality disabled\n");
*rc_type = RC_BIT_OTHER;
}
memcpy(ictx->usb_tx_buf, &ir_proto_packet, sizeof(ir_proto_packet));
if (!mutex_is_locked(&ictx->lock)) {
unlock = true;
mutex_lock(&ictx->lock);
}
retval = send_packet(ictx);
if (retval)
goto out;
ictx->rc_type = *rc_type;
ictx->pad_mouse = false;
out:
if (unlock)
mutex_unlock(&ictx->lock);
return retval;
}
static inline int tv2int(const struct timeval *a, const struct timeval *b)
{
int usecs = 0;
int sec = 0;
if (b->tv_usec > a->tv_usec) {
usecs = 1000000;
sec--;
}
usecs += a->tv_usec - b->tv_usec;
sec += a->tv_sec - b->tv_sec;
sec *= 1000;
usecs /= 1000;
sec += usecs;
if (sec < 0)
sec = 1000;
return sec;
}
static int stabilize(int a, int b, u16 timeout, u16 threshold)
{
struct timeval ct;
static struct timeval prev_time = {0, 0};
static struct timeval hit_time = {0, 0};
static int x, y, prev_result, hits;
int result = 0;
int msec, msec_hit;
do_gettimeofday(&ct);
msec = tv2int(&ct, &prev_time);
msec_hit = tv2int(&ct, &hit_time);
if (msec > 100) {
x = 0;
y = 0;
hits = 0;
}
x += a;
y += b;
prev_time = ct;
if (abs(x) > threshold || abs(y) > threshold) {
if (abs(y) > abs(x))
result = (y > 0) ? 0x7F : 0x80;
else
result = (x > 0) ? 0x7F00 : 0x8000;
x = 0;
y = 0;
if (result == prev_result) {
hits++;
if (hits > 3) {
switch (result) {
case 0x7F:
y = 17 * threshold / 30;
break;
case 0x80:
y -= 17 * threshold / 30;
break;
case 0x7F00:
x = 17 * threshold / 30;
break;
case 0x8000:
x -= 17 * threshold / 30;
break;
}
}
if (hits == 2 && msec_hit < timeout) {
result = 0;
hits = 1;
}
} else {
prev_result = result;
hits = 1;
hit_time = ct;
}
}
return result;
}
static u32 imon_remote_key_lookup(struct imon_context *ictx, u32 scancode)
{
u32 keycode;
u32 release;
bool is_release_code = false;
keycode = rc_g_keycode_from_table(ictx->rdev, scancode);
ictx->rc_toggle = 0x0;
ictx->rc_scancode = scancode;
if (keycode == KEY_RESERVED) {
release = scancode & ~0x4000;
keycode = rc_g_keycode_from_table(ictx->rdev, release);
if (keycode != KEY_RESERVED)
is_release_code = true;
}
ictx->release_code = is_release_code;
return keycode;
}
static u32 imon_mce_key_lookup(struct imon_context *ictx, u32 scancode)
{
u32 keycode;
#define MCE_KEY_MASK 0x7000
#define MCE_TOGGLE_BIT 0x8000
if (scancode & 0x80000000)
scancode = scancode | MCE_KEY_MASK | MCE_TOGGLE_BIT;
ictx->rc_scancode = scancode;
keycode = rc_g_keycode_from_table(ictx->rdev, scancode);
ictx->release_code = false;
return keycode;
}
static u32 imon_panel_key_lookup(u64 code)
{
int i;
u32 keycode = KEY_RESERVED;
for (i = 0; i < ARRAY_SIZE(imon_panel_key_table); i++) {
if (imon_panel_key_table[i].hw_code == (code | 0xffee)) {
keycode = imon_panel_key_table[i].keycode;
break;
}
}
return keycode;
}
static bool imon_mouse_event(struct imon_context *ictx,
unsigned char *buf, int len)
{
signed char rel_x = 0x00, rel_y = 0x00;
u8 right_shift = 1;
bool mouse_input = true;
int dir = 0;
unsigned long flags;
spin_lock_irqsave(&ictx->kc_lock, flags);
if (ictx->product != 0xffdc && (buf[0] & 0x01) && len == 5) {
rel_x = buf[2];
rel_y = buf[3];
right_shift = 1;
} else if (ictx->product == 0xffdc && (buf[0] & 0x40) &&
!((buf[1] & 0x01) || ((buf[1] >> 2) & 0x01))) {
rel_x = (buf[1] & 0x08) | (buf[1] & 0x10) >> 2 |
(buf[1] & 0x20) >> 4 | (buf[1] & 0x40) >> 6;
if (buf[0] & 0x02)
rel_x |= ~0x0f;
rel_x = rel_x + rel_x / 2;
rel_y = (buf[2] & 0x08) | (buf[2] & 0x10) >> 2 |
(buf[2] & 0x20) >> 4 | (buf[2] & 0x40) >> 6;
if (buf[0] & 0x01)
rel_y |= ~0x0f;
rel_y = rel_y + rel_y / 2;
right_shift = 2;
} else if (ictx->product == 0xffdc && (buf[0] == 0x68)) {
right_shift = 2;
} else if (ictx->kc == KEY_CHANNELUP && (buf[2] & 0x40) != 0x40) {
dir = 1;
} else if (ictx->kc == KEY_CHANNELDOWN && (buf[2] & 0x40) != 0x40) {
dir = -1;
} else
mouse_input = false;
spin_unlock_irqrestore(&ictx->kc_lock, flags);
if (mouse_input) {
dev_dbg(ictx->dev, "sending mouse data via input subsystem\n");
if (dir) {
input_report_rel(ictx->idev, REL_WHEEL, dir);
} else if (rel_x || rel_y) {
input_report_rel(ictx->idev, REL_X, rel_x);
input_report_rel(ictx->idev, REL_Y, rel_y);
} else {
input_report_key(ictx->idev, BTN_LEFT, buf[1] & 0x1);
input_report_key(ictx->idev, BTN_RIGHT,
buf[1] >> right_shift & 0x1);
}
input_sync(ictx->idev);
spin_lock_irqsave(&ictx->kc_lock, flags);
ictx->last_keycode = ictx->kc;
spin_unlock_irqrestore(&ictx->kc_lock, flags);
}
return mouse_input;
}
static void imon_touch_event(struct imon_context *ictx, unsigned char *buf)
{
mod_timer(&ictx->ttimer, jiffies + TOUCH_TIMEOUT);
ictx->touch_x = (buf[0] << 4) | (buf[1] >> 4);
ictx->touch_y = 0xfff - ((buf[2] << 4) | (buf[1] & 0xf));
input_report_abs(ictx->touch, ABS_X, ictx->touch_x);
input_report_abs(ictx->touch, ABS_Y, ictx->touch_y);
input_report_key(ictx->touch, BTN_TOUCH, 0x01);
input_sync(ictx->touch);
}
static void imon_pad_to_keys(struct imon_context *ictx, unsigned char *buf)
{
int dir = 0;
signed char rel_x = 0x00, rel_y = 0x00;
u16 timeout, threshold;
u32 scancode = KEY_RESERVED;
unsigned long flags;
if (ictx->product != 0xffdc) {
buf[5] = buf[6] = buf[7] = 0;
timeout = 500;
threshold = pad_thresh ? pad_thresh : 28;
rel_x = buf[2];
rel_y = buf[3];
if (ictx->rc_type == RC_BIT_OTHER && pad_stabilize) {
if ((buf[1] == 0) && ((rel_x != 0) || (rel_y != 0))) {
dir = stabilize((int)rel_x, (int)rel_y,
timeout, threshold);
if (!dir) {
spin_lock_irqsave(&ictx->kc_lock,
flags);
ictx->kc = KEY_UNKNOWN;
spin_unlock_irqrestore(&ictx->kc_lock,
flags);
return;
}
buf[2] = dir & 0xFF;
buf[3] = (dir >> 8) & 0xFF;
scancode = be32_to_cpu(*((u32 *)buf));
}
} else {
if (abs(rel_y) > abs(rel_x)) {
buf[2] = (rel_y > 0) ? 0x7F : 0x80;
buf[3] = 0;
if (rel_y > 0)
scancode = 0x01007f00;
else
scancode = 0x01008000;
} else {
buf[2] = 0;
buf[3] = (rel_x > 0) ? 0x7F : 0x80;
if (rel_x > 0)
scancode = 0x0100007f;
else
scancode = 0x01000080;
}
}
} else {
timeout = 10;
threshold = pad_thresh ? pad_thresh : 15;
rel_x = (buf[1] & 0x08) | (buf[1] & 0x10) >> 2 |
(buf[1] & 0x20) >> 4 | (buf[1] & 0x40) >> 6;
if (buf[0] & 0x02)
rel_x |= ~0x10+1;
rel_y = (buf[2] & 0x08) | (buf[2] & 0x10) >> 2 |
(buf[2] & 0x20) >> 4 | (buf[2] & 0x40) >> 6;
if (buf[0] & 0x01)
rel_y |= ~0x10+1;
buf[0] = 0x01;
buf[1] = buf[4] = buf[5] = buf[6] = buf[7] = 0;
if (ictx->rc_type == RC_BIT_OTHER && pad_stabilize) {
dir = stabilize((int)rel_x, (int)rel_y,
timeout, threshold);
if (!dir) {
spin_lock_irqsave(&ictx->kc_lock, flags);
ictx->kc = KEY_UNKNOWN;
spin_unlock_irqrestore(&ictx->kc_lock, flags);
return;
}
buf[2] = dir & 0xFF;
buf[3] = (dir >> 8) & 0xFF;
scancode = be32_to_cpu(*((u32 *)buf));
} else {
if (abs(rel_y) > abs(rel_x)) {
buf[2] = (rel_y > 0) ? 0x7F : 0x80;
buf[3] = 0;
if (rel_y > 0)
scancode = 0x01007f00;
else
scancode = 0x01008000;
} else {
buf[2] = 0;
buf[3] = (rel_x > 0) ? 0x7F : 0x80;
if (rel_x > 0)
scancode = 0x0100007f;
else
scancode = 0x01000080;
}
}
}
if (scancode) {
spin_lock_irqsave(&ictx->kc_lock, flags);
ictx->kc = imon_remote_key_lookup(ictx, scancode);
spin_unlock_irqrestore(&ictx->kc_lock, flags);
}
}
static int imon_parse_press_type(struct imon_context *ictx,
unsigned char *buf, u8 ktype)
{
int press_type = 0;
unsigned long flags;
spin_lock_irqsave(&ictx->kc_lock, flags);
if (ictx->kc == KEY_RESERVED && buf[0] == 0x02 && buf[3] == 0x00)
ictx->kc = ictx->last_keycode;
else if (ictx->kc == KEY_RESERVED && buf[0] == 0x68 && buf[1] == 0x82 &&
buf[2] == 0x81 && buf[3] == 0xb7)
ictx->kc = ictx->last_keycode;
else if (ictx->kc == KEY_RESERVED && buf[0] == 0x01 && buf[1] == 0x00 &&
buf[2] == 0x81 && buf[3] == 0xb7)
ictx->kc = ictx->last_keycode;
else if (ktype == IMON_KEY_MCE) {
ictx->rc_toggle = buf[2];
press_type = 1;
} else if (ictx->kc == KEY_RESERVED)
press_type = -EINVAL;
else if (ictx->release_code)
press_type = 0;
else
press_type = 1;
spin_unlock_irqrestore(&ictx->kc_lock, flags);
return press_type;
}
static void imon_incoming_packet(struct imon_context *ictx,
struct urb *urb, int intf)
{
int len = urb->actual_length;
unsigned char *buf = urb->transfer_buffer;
struct device *dev = ictx->dev;
unsigned long flags;
u32 kc;
int i;
u64 scancode;
int press_type = 0;
int msec;
struct timeval t;
static struct timeval prev_time = { 0, 0 };
u8 ktype;
if ((buf[0] == 0xff) && (buf[1] == 0xff) && (buf[2] == 0xff))
return;
if (len == 8 && buf[7] == 0xee) {
scancode = be64_to_cpu(*((u64 *)buf));
ktype = IMON_KEY_PANEL;
kc = imon_panel_key_lookup(scancode);
} else {
scancode = be32_to_cpu(*((u32 *)buf));
if (ictx->rc_type == RC_BIT_RC6_MCE) {
ktype = IMON_KEY_IMON;
if (buf[0] == 0x80)
ktype = IMON_KEY_MCE;
kc = imon_mce_key_lookup(ictx, scancode);
} else {
ktype = IMON_KEY_IMON;
kc = imon_remote_key_lookup(ictx, scancode);
}
}
spin_lock_irqsave(&ictx->kc_lock, flags);
if (kc == KEY_KEYBOARD && !ictx->release_code) {
ictx->last_keycode = kc;
if (!nomouse) {
ictx->pad_mouse = ~(ictx->pad_mouse) & 0x1;
dev_dbg(dev, "toggling to %s mode\n",
ictx->pad_mouse ? "mouse" : "keyboard");
spin_unlock_irqrestore(&ictx->kc_lock, flags);
return;
} else {
ictx->pad_mouse = false;
dev_dbg(dev, "mouse mode disabled, passing key value\n");
}
}
ictx->kc = kc;
spin_unlock_irqrestore(&ictx->kc_lock, flags);
if (ictx->display_type == IMON_DISPLAY_TYPE_VGA && len == 8 &&
buf[7] == 0x86) {
imon_touch_event(ictx, buf);
return;
} else if (ictx->pad_mouse) {
if (imon_mouse_event(ictx, buf, len))
return;
}
if (((len == 5) && (buf[0] == 0x01) && (buf[4] == 0x00)) ||
((len == 8) && (buf[0] & 0x40) &&
!(buf[1] & 0x1 || buf[1] >> 2 & 0x1))) {
len = 8;
imon_pad_to_keys(ictx, buf);
}
if (debug) {
printk(KERN_INFO "intf%d decoded packet: ", intf);
for (i = 0; i < len; ++i)
printk("%02x ", buf[i]);
printk("\n");
}
press_type = imon_parse_press_type(ictx, buf, ktype);
if (press_type < 0)
goto not_input_data;
if (ktype != IMON_KEY_PANEL) {
if (press_type == 0)
rc_keyup(ictx->rdev);
else {
rc_keydown(ictx->rdev, ictx->rc_scancode, ictx->rc_toggle);
spin_lock_irqsave(&ictx->kc_lock, flags);
ictx->last_keycode = ictx->kc;
spin_unlock_irqrestore(&ictx->kc_lock, flags);
}
return;
}
spin_lock_irqsave(&ictx->kc_lock, flags);
do_gettimeofday(&t);
if (ictx->kc == KEY_MUTE && ictx->kc == ictx->last_keycode) {
msec = tv2int(&t, &prev_time);
if (msec < ictx->idev->rep[REP_DELAY]) {
spin_unlock_irqrestore(&ictx->kc_lock, flags);
return;
}
}
prev_time = t;
kc = ictx->kc;
spin_unlock_irqrestore(&ictx->kc_lock, flags);
input_report_key(ictx->idev, kc, press_type);
input_sync(ictx->idev);
input_report_key(ictx->idev, kc, 0);
input_sync(ictx->idev);
spin_lock_irqsave(&ictx->kc_lock, flags);
ictx->last_keycode = kc;
spin_unlock_irqrestore(&ictx->kc_lock, flags);
return;
not_input_data:
if (len != 8) {
dev_warn(dev, "imon %s: invalid incoming packet "
"size (len = %d, intf%d)\n", __func__, len, intf);
return;
}
if (buf[0] == 0x00 &&
buf[2] == 0xFF &&
buf[3] == 0xFF &&
buf[4] == 0xFF &&
buf[5] == 0xFF &&
((buf[6] == 0x4E && buf[7] == 0xDF) ||
(buf[6] == 0x5E && buf[7] == 0xDF))) {
dev_warn(dev, "%s: remote associated refid=%02X\n",
__func__, buf[1]);
ictx->rf_isassociating = false;
}
}
static void usb_rx_callback_intf0(struct urb *urb)
{
struct imon_context *ictx;
int intfnum = 0;
if (!urb)
return;
ictx = (struct imon_context *)urb->context;
if (!ictx)
return;
if (!ictx->dev_present_intf0)
goto out;
switch (urb->status) {
case -ENOENT:
return;
case -ESHUTDOWN:
break;
case 0:
imon_incoming_packet(ictx, urb, intfnum);
break;
default:
dev_warn(ictx->dev, "imon %s: status(%d): ignored\n",
__func__, urb->status);
break;
}
out:
usb_submit_urb(ictx->rx_urb_intf0, GFP_ATOMIC);
}
static void usb_rx_callback_intf1(struct urb *urb)
{
struct imon_context *ictx;
int intfnum = 1;
if (!urb)
return;
ictx = (struct imon_context *)urb->context;
if (!ictx)
return;
if (!ictx->dev_present_intf1)
goto out;
switch (urb->status) {
case -ENOENT:
return;
case -ESHUTDOWN:
break;
case 0:
imon_incoming_packet(ictx, urb, intfnum);
break;
default:
dev_warn(ictx->dev, "imon %s: status(%d): ignored\n",
__func__, urb->status);
break;
}
out:
usb_submit_urb(ictx->rx_urb_intf1, GFP_ATOMIC);
}
static void imon_get_ffdc_type(struct imon_context *ictx)
{
u8 ffdc_cfg_byte = ictx->usb_rx_buf[6];
u8 detected_display_type = IMON_DISPLAY_TYPE_NONE;
u64 allowed_protos = RC_BIT_OTHER;
switch (ffdc_cfg_byte) {
case 0x21:
dev_info(ictx->dev, "0xffdc iMON Knob, iMON IR");
ictx->display_supported = false;
break;
case 0x4e:
dev_info(ictx->dev, "0xffdc iMON 2.4G LT, iMON RF");
ictx->display_supported = false;
ictx->rf_device = true;
break;
case 0x35:
dev_info(ictx->dev, "0xffdc iMON VFD + knob, no IR");
detected_display_type = IMON_DISPLAY_TYPE_VFD;
break;
case 0x24:
case 0x85:
dev_info(ictx->dev, "0xffdc iMON VFD, iMON IR");
detected_display_type = IMON_DISPLAY_TYPE_VFD;
break;
case 0x46:
case 0x7e:
case 0x9e:
dev_info(ictx->dev, "0xffdc iMON VFD, MCE IR");
detected_display_type = IMON_DISPLAY_TYPE_VFD;
allowed_protos = RC_BIT_RC6_MCE;
break;
case 0x9f:
dev_info(ictx->dev, "0xffdc iMON LCD, MCE IR");
detected_display_type = IMON_DISPLAY_TYPE_LCD;
allowed_protos = RC_BIT_RC6_MCE;
break;
default:
dev_info(ictx->dev, "Unknown 0xffdc device, "
"defaulting to VFD and iMON IR");
detected_display_type = IMON_DISPLAY_TYPE_VFD;
allowed_protos |= RC_BIT_RC6_MCE;
break;
}
printk(KERN_CONT " (id 0x%02x)\n", ffdc_cfg_byte);
ictx->display_type = detected_display_type;
ictx->rc_type = allowed_protos;
}
static void imon_set_display_type(struct imon_context *ictx)
{
u8 configured_display_type = IMON_DISPLAY_TYPE_VFD;
if (display_type == IMON_DISPLAY_TYPE_AUTO) {
switch (ictx->product) {
case 0xffdc:
configured_display_type = ictx->display_type;
break;
case 0x0034:
case 0x0035:
configured_display_type = IMON_DISPLAY_TYPE_VGA;
break;
case 0x0038:
case 0x0039:
case 0x0045:
configured_display_type = IMON_DISPLAY_TYPE_LCD;
break;
case 0x003c:
case 0x0041:
case 0x0042:
case 0x0043:
configured_display_type = IMON_DISPLAY_TYPE_NONE;
ictx->display_supported = false;
break;
case 0x0036:
case 0x0044:
default:
configured_display_type = IMON_DISPLAY_TYPE_VFD;
break;
}
} else {
configured_display_type = display_type;
if (display_type == IMON_DISPLAY_TYPE_NONE)
ictx->display_supported = false;
else
ictx->display_supported = true;
dev_info(ictx->dev, "%s: overriding display type to %d via "
"modparam\n", __func__, display_type);
}
ictx->display_type = configured_display_type;
}
static struct rc_dev *imon_init_rdev(struct imon_context *ictx)
{
struct rc_dev *rdev;
int ret;
const unsigned char fp_packet[] = { 0x40, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x88 };
rdev = rc_allocate_device();
if (!rdev) {
dev_err(ictx->dev, "remote control dev allocation failed\n");
goto out;
}
snprintf(ictx->name_rdev, sizeof(ictx->name_rdev),
"iMON Remote (%04x:%04x)", ictx->vendor, ictx->product);
usb_make_path(ictx->usbdev_intf0, ictx->phys_rdev,
sizeof(ictx->phys_rdev));
strlcat(ictx->phys_rdev, "/input0", sizeof(ictx->phys_rdev));
rdev->input_name = ictx->name_rdev;
rdev->input_phys = ictx->phys_rdev;
usb_to_input_id(ictx->usbdev_intf0, &rdev->input_id);
rdev->dev.parent = ictx->dev;
rdev->priv = ictx;
rdev->driver_type = RC_DRIVER_SCANCODE;
rdev->allowed_protos = RC_BIT_OTHER | RC_BIT_RC6_MCE;
rdev->change_protocol = imon_ir_change_protocol;
rdev->driver_name = MOD_NAME;
memcpy(ictx->usb_tx_buf, &fp_packet, sizeof(fp_packet));
ret = send_packet(ictx);
if (ret)
dev_info(ictx->dev, "panel buttons/knobs setup failed\n");
if (ictx->product == 0xffdc) {
imon_get_ffdc_type(ictx);
rdev->allowed_protos = ictx->rc_type;
}
imon_set_display_type(ictx);
if (ictx->rc_type == RC_BIT_RC6_MCE)
rdev->map_name = RC_MAP_IMON_MCE;
else
rdev->map_name = RC_MAP_IMON_PAD;
ret = rc_register_device(rdev);
if (ret < 0) {
dev_err(ictx->dev, "remote input dev register failed\n");
goto out;
}
return rdev;
out:
rc_free_device(rdev);
return NULL;
}
static struct input_dev *imon_init_idev(struct imon_context *ictx)
{
struct input_dev *idev;
int ret, i;
idev = input_allocate_device();
if (!idev)
goto out;
snprintf(ictx->name_idev, sizeof(ictx->name_idev),
"iMON Panel, Knob and Mouse(%04x:%04x)",
ictx->vendor, ictx->product);
idev->name = ictx->name_idev;
usb_make_path(ictx->usbdev_intf0, ictx->phys_idev,
sizeof(ictx->phys_idev));
strlcat(ictx->phys_idev, "/input1", sizeof(ictx->phys_idev));
idev->phys = ictx->phys_idev;
idev->evbit[0] = BIT_MASK(EV_KEY) | BIT_MASK(EV_REP) | BIT_MASK(EV_REL);
idev->keybit[BIT_WORD(BTN_MOUSE)] =
BIT_MASK(BTN_LEFT) | BIT_MASK(BTN_RIGHT);
idev->relbit[0] = BIT_MASK(REL_X) | BIT_MASK(REL_Y) |
BIT_MASK(REL_WHEEL);
for (i = 0; i < ARRAY_SIZE(imon_panel_key_table); i++) {
u32 kc = imon_panel_key_table[i].keycode;
__set_bit(kc, idev->keybit);
}
usb_to_input_id(ictx->usbdev_intf0, &idev->id);
idev->dev.parent = ictx->dev;
input_set_drvdata(idev, ictx);
ret = input_register_device(idev);
if (ret < 0) {
dev_err(ictx->dev, "input dev register failed\n");
goto out;
}
return idev;
out:
input_free_device(idev);
return NULL;
}
static struct input_dev *imon_init_touch(struct imon_context *ictx)
{
struct input_dev *touch;
int ret;
touch = input_allocate_device();
if (!touch)
goto touch_alloc_failed;
snprintf(ictx->name_touch, sizeof(ictx->name_touch),
"iMON USB Touchscreen (%04x:%04x)",
ictx->vendor, ictx->product);
touch->name = ictx->name_touch;
usb_make_path(ictx->usbdev_intf1, ictx->phys_touch,
sizeof(ictx->phys_touch));
strlcat(ictx->phys_touch, "/input2", sizeof(ictx->phys_touch));
touch->phys = ictx->phys_touch;
touch->evbit[0] =
BIT_MASK(EV_KEY) | BIT_MASK(EV_ABS);
touch->keybit[BIT_WORD(BTN_TOUCH)] =
BIT_MASK(BTN_TOUCH);
input_set_abs_params(touch, ABS_X,
0x00, 0xfff, 0, 0);
input_set_abs_params(touch, ABS_Y,
0x00, 0xfff, 0, 0);
input_set_drvdata(touch, ictx);
usb_to_input_id(ictx->usbdev_intf1, &touch->id);
touch->dev.parent = ictx->dev;
ret = input_register_device(touch);
if (ret < 0) {
dev_info(ictx->dev, "touchscreen input dev register failed\n");
goto touch_register_failed;
}
return touch;
touch_register_failed:
input_free_device(touch);
touch_alloc_failed:
return NULL;
}
static bool imon_find_endpoints(struct imon_context *ictx,
struct usb_host_interface *iface_desc)
{
struct usb_endpoint_descriptor *ep;
struct usb_endpoint_descriptor *rx_endpoint = NULL;
struct usb_endpoint_descriptor *tx_endpoint = NULL;
int ifnum = iface_desc->desc.bInterfaceNumber;
int num_endpts = iface_desc->desc.bNumEndpoints;
int i, ep_dir, ep_type;
bool ir_ep_found = false;
bool display_ep_found = false;
bool tx_control = false;
for (i = 0; i < num_endpts && !(ir_ep_found && display_ep_found); ++i) {
ep = &iface_desc->endpoint[i].desc;
ep_dir = ep->bEndpointAddress & USB_ENDPOINT_DIR_MASK;
ep_type = ep->bmAttributes & USB_ENDPOINT_XFERTYPE_MASK;
if (!ir_ep_found && ep_dir == USB_DIR_IN &&
ep_type == USB_ENDPOINT_XFER_INT) {
rx_endpoint = ep;
ir_ep_found = true;
dev_dbg(ictx->dev, "%s: found IR endpoint\n", __func__);
} else if (!display_ep_found && ep_dir == USB_DIR_OUT &&
ep_type == USB_ENDPOINT_XFER_INT) {
tx_endpoint = ep;
display_ep_found = true;
dev_dbg(ictx->dev, "%s: found display endpoint\n", __func__);
}
}
if (ifnum == 0) {
ictx->rx_endpoint_intf0 = rx_endpoint;
ictx->tx_endpoint = tx_endpoint;
} else {
ictx->rx_endpoint_intf1 = rx_endpoint;
}
if (!display_ep_found) {
tx_control = true;
display_ep_found = true;
dev_dbg(ictx->dev, "%s: device uses control endpoint, not "
"interface OUT endpoint\n", __func__);
}
if (ictx->display_type == IMON_DISPLAY_TYPE_NONE) {
display_ep_found = false;
dev_dbg(ictx->dev, "%s: device has no display\n", __func__);
}
if (ictx->display_type == IMON_DISPLAY_TYPE_VGA) {
display_ep_found = false;
dev_dbg(ictx->dev, "%s: iMON Touch device found\n", __func__);
}
if (!ir_ep_found)
pr_err("no valid input (IR) endpoint found\n");
ictx->tx_control = tx_control;
if (display_ep_found)
ictx->display_supported = true;
return ir_ep_found;
}
static struct imon_context *imon_init_intf0(struct usb_interface *intf,
const struct usb_device_id *id)
{
struct imon_context *ictx;
struct urb *rx_urb;
struct urb *tx_urb;
struct device *dev = &intf->dev;
struct usb_host_interface *iface_desc;
int ret = -ENOMEM;
ictx = kzalloc(sizeof(struct imon_context), GFP_KERNEL);
if (!ictx) {
dev_err(dev, "%s: kzalloc failed for context", __func__);
goto exit;
}
rx_urb = usb_alloc_urb(0, GFP_KERNEL);
if (!rx_urb) {
dev_err(dev, "%s: usb_alloc_urb failed for IR urb", __func__);
goto rx_urb_alloc_failed;
}
tx_urb = usb_alloc_urb(0, GFP_KERNEL);
if (!tx_urb) {
dev_err(dev, "%s: usb_alloc_urb failed for display urb",
__func__);
goto tx_urb_alloc_failed;
}
mutex_init(&ictx->lock);
spin_lock_init(&ictx->kc_lock);
mutex_lock(&ictx->lock);
ictx->dev = dev;
ictx->usbdev_intf0 = usb_get_dev(interface_to_usbdev(intf));
ictx->rx_urb_intf0 = rx_urb;
ictx->tx_urb = tx_urb;
ictx->rf_device = false;
ictx->vendor = le16_to_cpu(ictx->usbdev_intf0->descriptor.idVendor);
ictx->product = le16_to_cpu(ictx->usbdev_intf0->descriptor.idProduct);
ictx->send_packet_delay = id->driver_info & IMON_NEED_20MS_PKT_DELAY ?
20 : 5;
ret = -ENODEV;
iface_desc = intf->cur_altsetting;
if (!imon_find_endpoints(ictx, iface_desc)) {
goto find_endpoint_failed;
}
usb_fill_int_urb(ictx->rx_urb_intf0, ictx->usbdev_intf0,
usb_rcvintpipe(ictx->usbdev_intf0,
ictx->rx_endpoint_intf0->bEndpointAddress),
ictx->usb_rx_buf, sizeof(ictx->usb_rx_buf),
usb_rx_callback_intf0, ictx,
ictx->rx_endpoint_intf0->bInterval);
ret = usb_submit_urb(ictx->rx_urb_intf0, GFP_KERNEL);
if (ret) {
pr_err("usb_submit_urb failed for intf0 (%d)\n", ret);
goto urb_submit_failed;
}
ictx->idev = imon_init_idev(ictx);
if (!ictx->idev) {
dev_err(dev, "%s: input device setup failed\n", __func__);
goto idev_setup_failed;
}
ictx->rdev = imon_init_rdev(ictx);
if (!ictx->rdev) {
dev_err(dev, "%s: rc device setup failed\n", __func__);
goto rdev_setup_failed;
}
ictx->dev_present_intf0 = true;
mutex_unlock(&ictx->lock);
return ictx;
rdev_setup_failed:
input_unregister_device(ictx->idev);
idev_setup_failed:
usb_kill_urb(ictx->rx_urb_intf0);
urb_submit_failed:
find_endpoint_failed:
mutex_unlock(&ictx->lock);
usb_free_urb(tx_urb);
tx_urb_alloc_failed:
usb_free_urb(rx_urb);
rx_urb_alloc_failed:
kfree(ictx);
exit:
dev_err(dev, "unable to initialize intf0, err %d\n", ret);
return NULL;
}
static struct imon_context *imon_init_intf1(struct usb_interface *intf,
struct imon_context *ictx)
{
struct urb *rx_urb;
struct usb_host_interface *iface_desc;
int ret = -ENOMEM;
rx_urb = usb_alloc_urb(0, GFP_KERNEL);
if (!rx_urb) {
pr_err("usb_alloc_urb failed for IR urb\n");
goto rx_urb_alloc_failed;
}
mutex_lock(&ictx->lock);
if (ictx->display_type == IMON_DISPLAY_TYPE_VGA) {
init_timer(&ictx->ttimer);
ictx->ttimer.data = (unsigned long)ictx;
ictx->ttimer.function = imon_touch_display_timeout;
}
ictx->usbdev_intf1 = usb_get_dev(interface_to_usbdev(intf));
ictx->rx_urb_intf1 = rx_urb;
ret = -ENODEV;
iface_desc = intf->cur_altsetting;
if (!imon_find_endpoints(ictx, iface_desc))
goto find_endpoint_failed;
if (ictx->display_type == IMON_DISPLAY_TYPE_VGA) {
ictx->touch = imon_init_touch(ictx);
if (!ictx->touch)
goto touch_setup_failed;
} else
ictx->touch = NULL;
usb_fill_int_urb(ictx->rx_urb_intf1, ictx->usbdev_intf1,
usb_rcvintpipe(ictx->usbdev_intf1,
ictx->rx_endpoint_intf1->bEndpointAddress),
ictx->usb_rx_buf, sizeof(ictx->usb_rx_buf),
usb_rx_callback_intf1, ictx,
ictx->rx_endpoint_intf1->bInterval);
ret = usb_submit_urb(ictx->rx_urb_intf1, GFP_KERNEL);
if (ret) {
pr_err("usb_submit_urb failed for intf1 (%d)\n", ret);
goto urb_submit_failed;
}
ictx->dev_present_intf1 = true;
mutex_unlock(&ictx->lock);
return ictx;
urb_submit_failed:
if (ictx->touch)
input_unregister_device(ictx->touch);
touch_setup_failed:
find_endpoint_failed:
mutex_unlock(&ictx->lock);
usb_free_urb(rx_urb);
rx_urb_alloc_failed:
dev_err(ictx->dev, "unable to initialize intf1, err %d\n", ret);
return NULL;
}
static void imon_init_display(struct imon_context *ictx,
struct usb_interface *intf)
{
int ret;
dev_dbg(ictx->dev, "Registering iMON display with sysfs\n");
ret = sysfs_create_group(&intf->dev.kobj, &imon_display_attr_group);
if (ret)
dev_err(ictx->dev, "Could not create display sysfs "
"entries(%d)", ret);
if (ictx->display_type == IMON_DISPLAY_TYPE_LCD)
ret = usb_register_dev(intf, &imon_lcd_class);
else
ret = usb_register_dev(intf, &imon_vfd_class);
if (ret)
dev_info(ictx->dev, "could not get a minor number for "
"display\n");
}
static int imon_probe(struct usb_interface *interface,
const struct usb_device_id *id)
{
struct usb_device *usbdev = NULL;
struct usb_host_interface *iface_desc = NULL;
struct usb_interface *first_if;
struct device *dev = &interface->dev;
int ifnum, sysfs_err;
int ret = 0;
struct imon_context *ictx = NULL;
struct imon_context *first_if_ctx = NULL;
u16 vendor, product;
usbdev = usb_get_dev(interface_to_usbdev(interface));
iface_desc = interface->cur_altsetting;
ifnum = iface_desc->desc.bInterfaceNumber;
vendor = le16_to_cpu(usbdev->descriptor.idVendor);
product = le16_to_cpu(usbdev->descriptor.idProduct);
dev_dbg(dev, "%s: found iMON device (%04x:%04x, intf%d)\n",
__func__, vendor, product, ifnum);
mutex_lock(&driver_lock);
first_if = usb_ifnum_to_if(usbdev, 0);
first_if_ctx = usb_get_intfdata(first_if);
if (ifnum == 0) {
ictx = imon_init_intf0(interface, id);
if (!ictx) {
pr_err("failed to initialize context!\n");
ret = -ENODEV;
goto fail;
}
} else {
if (!first_if_ctx) {
ret = -ENODEV;
goto fail;
}
ictx = imon_init_intf1(interface, first_if_ctx);
if (!ictx) {
pr_err("failed to attach to context!\n");
ret = -ENODEV;
goto fail;
}
}
usb_set_intfdata(interface, ictx);
if (ifnum == 0) {
mutex_lock(&ictx->lock);
if (product == 0xffdc && ictx->rf_device) {
sysfs_err = sysfs_create_group(&interface->dev.kobj,
&imon_rf_attr_group);
if (sysfs_err)
pr_err("Could not create RF sysfs entries(%d)\n",
sysfs_err);
}
if (ictx->display_supported)
imon_init_display(ictx, interface);
mutex_unlock(&ictx->lock);
}
dev_info(dev, "iMON device (%04x:%04x, intf%d) on "
"usb<%d:%d> initialized\n", vendor, product, ifnum,
usbdev->bus->busnum, usbdev->devnum);
mutex_unlock(&driver_lock);
return 0;
fail:
mutex_unlock(&driver_lock);
dev_err(dev, "unable to register, err %d\n", ret);
return ret;
}
static void imon_disconnect(struct usb_interface *interface)
{
struct imon_context *ictx;
struct device *dev;
int ifnum;
mutex_lock(&driver_lock);
ictx = usb_get_intfdata(interface);
dev = ictx->dev;
ifnum = interface->cur_altsetting->desc.bInterfaceNumber;
sysfs_remove_group(&interface->dev.kobj, &imon_display_attr_group);
sysfs_remove_group(&interface->dev.kobj, &imon_rf_attr_group);
usb_set_intfdata(interface, NULL);
if (ictx->tx.busy) {
usb_kill_urb(ictx->tx_urb);
complete_all(&ictx->tx.finished);
}
if (ifnum == 0) {
ictx->dev_present_intf0 = false;
usb_kill_urb(ictx->rx_urb_intf0);
input_unregister_device(ictx->idev);
rc_unregister_device(ictx->rdev);
if (ictx->display_supported) {
if (ictx->display_type == IMON_DISPLAY_TYPE_LCD)
usb_deregister_dev(interface, &imon_lcd_class);
else if (ictx->display_type == IMON_DISPLAY_TYPE_VFD)
usb_deregister_dev(interface, &imon_vfd_class);
}
} else {
ictx->dev_present_intf1 = false;
usb_kill_urb(ictx->rx_urb_intf1);
if (ictx->display_type == IMON_DISPLAY_TYPE_VGA) {
input_unregister_device(ictx->touch);
del_timer_sync(&ictx->ttimer);
}
}
if (!ictx->dev_present_intf0 && !ictx->dev_present_intf1)
free_imon_context(ictx);
mutex_unlock(&driver_lock);
dev_dbg(dev, "%s: iMON device (intf%d) disconnected\n",
__func__, ifnum);
}
static int imon_suspend(struct usb_interface *intf, pm_message_t message)
{
struct imon_context *ictx = usb_get_intfdata(intf);
int ifnum = intf->cur_altsetting->desc.bInterfaceNumber;
if (ifnum == 0)
usb_kill_urb(ictx->rx_urb_intf0);
else
usb_kill_urb(ictx->rx_urb_intf1);
return 0;
}
static int imon_resume(struct usb_interface *intf)
{
int rc = 0;
struct imon_context *ictx = usb_get_intfdata(intf);
int ifnum = intf->cur_altsetting->desc.bInterfaceNumber;
if (ifnum == 0) {
usb_fill_int_urb(ictx->rx_urb_intf0, ictx->usbdev_intf0,
usb_rcvintpipe(ictx->usbdev_intf0,
ictx->rx_endpoint_intf0->bEndpointAddress),
ictx->usb_rx_buf, sizeof(ictx->usb_rx_buf),
usb_rx_callback_intf0, ictx,
ictx->rx_endpoint_intf0->bInterval);
rc = usb_submit_urb(ictx->rx_urb_intf0, GFP_ATOMIC);
} else {
usb_fill_int_urb(ictx->rx_urb_intf1, ictx->usbdev_intf1,
usb_rcvintpipe(ictx->usbdev_intf1,
ictx->rx_endpoint_intf1->bEndpointAddress),
ictx->usb_rx_buf, sizeof(ictx->usb_rx_buf),
usb_rx_callback_intf1, ictx,
ictx->rx_endpoint_intf1->bInterval);
rc = usb_submit_urb(ictx->rx_urb_intf1, GFP_ATOMIC);
}
return rc;
}
