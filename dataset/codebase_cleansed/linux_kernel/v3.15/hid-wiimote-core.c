static int wiimote_hid_send(struct hid_device *hdev, __u8 *buffer,
size_t count)
{
__u8 *buf;
int ret;
if (!hdev->ll_driver->output_report)
return -ENODEV;
buf = kmemdup(buffer, count, GFP_KERNEL);
if (!buf)
return -ENOMEM;
ret = hid_hw_output_report(hdev, buf, count);
kfree(buf);
return ret;
}
static void wiimote_queue_worker(struct work_struct *work)
{
struct wiimote_queue *queue = container_of(work, struct wiimote_queue,
worker);
struct wiimote_data *wdata = container_of(queue, struct wiimote_data,
queue);
unsigned long flags;
int ret;
spin_lock_irqsave(&wdata->queue.lock, flags);
while (wdata->queue.head != wdata->queue.tail) {
spin_unlock_irqrestore(&wdata->queue.lock, flags);
ret = wiimote_hid_send(wdata->hdev,
wdata->queue.outq[wdata->queue.tail].data,
wdata->queue.outq[wdata->queue.tail].size);
if (ret < 0) {
spin_lock_irqsave(&wdata->state.lock, flags);
wiimote_cmd_abort(wdata);
spin_unlock_irqrestore(&wdata->state.lock, flags);
}
spin_lock_irqsave(&wdata->queue.lock, flags);
wdata->queue.tail = (wdata->queue.tail + 1) % WIIMOTE_BUFSIZE;
}
spin_unlock_irqrestore(&wdata->queue.lock, flags);
}
static void wiimote_queue(struct wiimote_data *wdata, const __u8 *buffer,
size_t count)
{
unsigned long flags;
__u8 newhead;
if (count > HID_MAX_BUFFER_SIZE) {
hid_warn(wdata->hdev, "Sending too large output report\n");
spin_lock_irqsave(&wdata->queue.lock, flags);
goto out_error;
}
spin_lock_irqsave(&wdata->queue.lock, flags);
memcpy(wdata->queue.outq[wdata->queue.head].data, buffer, count);
wdata->queue.outq[wdata->queue.head].size = count;
newhead = (wdata->queue.head + 1) % WIIMOTE_BUFSIZE;
if (wdata->queue.head == wdata->queue.tail) {
wdata->queue.head = newhead;
schedule_work(&wdata->queue.worker);
} else if (newhead != wdata->queue.tail) {
wdata->queue.head = newhead;
} else {
hid_warn(wdata->hdev, "Output queue is full");
goto out_error;
}
goto out_unlock;
out_error:
wiimote_cmd_abort(wdata);
out_unlock:
spin_unlock_irqrestore(&wdata->queue.lock, flags);
}
static inline void wiiproto_keep_rumble(struct wiimote_data *wdata, __u8 *cmd1)
{
if (wdata->state.flags & WIIPROTO_FLAG_RUMBLE)
*cmd1 |= 0x01;
}
void wiiproto_req_rumble(struct wiimote_data *wdata, __u8 rumble)
{
__u8 cmd[2];
rumble = !!rumble;
if (rumble == !!(wdata->state.flags & WIIPROTO_FLAG_RUMBLE))
return;
if (rumble)
wdata->state.flags |= WIIPROTO_FLAG_RUMBLE;
else
wdata->state.flags &= ~WIIPROTO_FLAG_RUMBLE;
cmd[0] = WIIPROTO_REQ_RUMBLE;
cmd[1] = 0;
wiiproto_keep_rumble(wdata, &cmd[1]);
wiimote_queue(wdata, cmd, sizeof(cmd));
}
void wiiproto_req_leds(struct wiimote_data *wdata, int leds)
{
__u8 cmd[2];
leds &= WIIPROTO_FLAGS_LEDS;
if ((wdata->state.flags & WIIPROTO_FLAGS_LEDS) == leds)
return;
wdata->state.flags = (wdata->state.flags & ~WIIPROTO_FLAGS_LEDS) | leds;
cmd[0] = WIIPROTO_REQ_LED;
cmd[1] = 0;
if (leds & WIIPROTO_FLAG_LED1)
cmd[1] |= 0x10;
if (leds & WIIPROTO_FLAG_LED2)
cmd[1] |= 0x20;
if (leds & WIIPROTO_FLAG_LED3)
cmd[1] |= 0x40;
if (leds & WIIPROTO_FLAG_LED4)
cmd[1] |= 0x80;
wiiproto_keep_rumble(wdata, &cmd[1]);
wiimote_queue(wdata, cmd, sizeof(cmd));
}
static __u8 select_drm(struct wiimote_data *wdata)
{
__u8 ir = wdata->state.flags & WIIPROTO_FLAGS_IR;
bool ext;
ext = (wdata->state.flags & WIIPROTO_FLAG_EXT_USED) ||
(wdata->state.flags & WIIPROTO_FLAG_MP_USED);
if (wdata->state.devtype == WIIMOTE_DEV_BALANCE_BOARD) {
if (ext)
return WIIPROTO_REQ_DRM_KEE;
else
return WIIPROTO_REQ_DRM_K;
}
if (ir == WIIPROTO_FLAG_IR_BASIC) {
if (wdata->state.flags & WIIPROTO_FLAG_ACCEL) {
return WIIPROTO_REQ_DRM_KAIE;
} else {
return WIIPROTO_REQ_DRM_KIE;
}
} else if (ir == WIIPROTO_FLAG_IR_EXT) {
return WIIPROTO_REQ_DRM_KAI;
} else if (ir == WIIPROTO_FLAG_IR_FULL) {
return WIIPROTO_REQ_DRM_SKAI1;
} else {
if (wdata->state.flags & WIIPROTO_FLAG_ACCEL) {
if (ext)
return WIIPROTO_REQ_DRM_KAE;
else
return WIIPROTO_REQ_DRM_KA;
} else {
if (ext)
return WIIPROTO_REQ_DRM_KEE;
else
return WIIPROTO_REQ_DRM_K;
}
}
}
void wiiproto_req_drm(struct wiimote_data *wdata, __u8 drm)
{
__u8 cmd[3];
if (wdata->state.flags & WIIPROTO_FLAG_DRM_LOCKED)
drm = wdata->state.drm;
else if (drm == WIIPROTO_REQ_NULL)
drm = select_drm(wdata);
cmd[0] = WIIPROTO_REQ_DRM;
cmd[1] = 0;
cmd[2] = drm;
wdata->state.drm = drm;
wiiproto_keep_rumble(wdata, &cmd[1]);
wiimote_queue(wdata, cmd, sizeof(cmd));
}
void wiiproto_req_status(struct wiimote_data *wdata)
{
__u8 cmd[2];
cmd[0] = WIIPROTO_REQ_SREQ;
cmd[1] = 0;
wiiproto_keep_rumble(wdata, &cmd[1]);
wiimote_queue(wdata, cmd, sizeof(cmd));
}
void wiiproto_req_accel(struct wiimote_data *wdata, __u8 accel)
{
accel = !!accel;
if (accel == !!(wdata->state.flags & WIIPROTO_FLAG_ACCEL))
return;
if (accel)
wdata->state.flags |= WIIPROTO_FLAG_ACCEL;
else
wdata->state.flags &= ~WIIPROTO_FLAG_ACCEL;
wiiproto_req_drm(wdata, WIIPROTO_REQ_NULL);
}
void wiiproto_req_ir1(struct wiimote_data *wdata, __u8 flags)
{
__u8 cmd[2];
cmd[0] = WIIPROTO_REQ_IR1;
cmd[1] = flags;
wiiproto_keep_rumble(wdata, &cmd[1]);
wiimote_queue(wdata, cmd, sizeof(cmd));
}
void wiiproto_req_ir2(struct wiimote_data *wdata, __u8 flags)
{
__u8 cmd[2];
cmd[0] = WIIPROTO_REQ_IR2;
cmd[1] = flags;
wiiproto_keep_rumble(wdata, &cmd[1]);
wiimote_queue(wdata, cmd, sizeof(cmd));
}
static void wiiproto_req_wmem(struct wiimote_data *wdata, bool eeprom,
__u32 offset, const __u8 *buf, __u8 size)
{
__u8 cmd[22];
if (size > 16 || size == 0) {
hid_warn(wdata->hdev, "Invalid length %d wmem request\n", size);
return;
}
memset(cmd, 0, sizeof(cmd));
cmd[0] = WIIPROTO_REQ_WMEM;
cmd[2] = (offset >> 16) & 0xff;
cmd[3] = (offset >> 8) & 0xff;
cmd[4] = offset & 0xff;
cmd[5] = size;
memcpy(&cmd[6], buf, size);
if (!eeprom)
cmd[1] |= 0x04;
wiiproto_keep_rumble(wdata, &cmd[1]);
wiimote_queue(wdata, cmd, sizeof(cmd));
}
void wiiproto_req_rmem(struct wiimote_data *wdata, bool eeprom, __u32 offset,
__u16 size)
{
__u8 cmd[7];
if (size == 0) {
hid_warn(wdata->hdev, "Invalid length %d rmem request\n", size);
return;
}
cmd[0] = WIIPROTO_REQ_RMEM;
cmd[1] = 0;
cmd[2] = (offset >> 16) & 0xff;
cmd[3] = (offset >> 8) & 0xff;
cmd[4] = offset & 0xff;
cmd[5] = (size >> 8) & 0xff;
cmd[6] = size & 0xff;
if (!eeprom)
cmd[1] |= 0x04;
wiiproto_keep_rumble(wdata, &cmd[1]);
wiimote_queue(wdata, cmd, sizeof(cmd));
}
int wiimote_cmd_write(struct wiimote_data *wdata, __u32 offset,
const __u8 *wmem, __u8 size)
{
unsigned long flags;
int ret;
spin_lock_irqsave(&wdata->state.lock, flags);
wiimote_cmd_set(wdata, WIIPROTO_REQ_WMEM, 0);
wiiproto_req_wreg(wdata, offset, wmem, size);
spin_unlock_irqrestore(&wdata->state.lock, flags);
ret = wiimote_cmd_wait(wdata);
if (!ret && wdata->state.cmd_err)
ret = -EIO;
return ret;
}
ssize_t wiimote_cmd_read(struct wiimote_data *wdata, __u32 offset, __u8 *rmem,
__u8 size)
{
unsigned long flags;
ssize_t ret;
spin_lock_irqsave(&wdata->state.lock, flags);
wdata->state.cmd_read_size = size;
wdata->state.cmd_read_buf = rmem;
wiimote_cmd_set(wdata, WIIPROTO_REQ_RMEM, offset & 0xffff);
wiiproto_req_rreg(wdata, offset, size);
spin_unlock_irqrestore(&wdata->state.lock, flags);
ret = wiimote_cmd_wait(wdata);
spin_lock_irqsave(&wdata->state.lock, flags);
wdata->state.cmd_read_buf = NULL;
spin_unlock_irqrestore(&wdata->state.lock, flags);
if (!ret) {
if (wdata->state.cmd_read_size == 0)
ret = -EIO;
else
ret = wdata->state.cmd_read_size;
}
return ret;
}
static int wiimote_cmd_init_ext(struct wiimote_data *wdata)
{
__u8 wmem;
int ret;
wmem = 0x55;
ret = wiimote_cmd_write(wdata, 0xa400f0, &wmem, sizeof(wmem));
if (ret)
return ret;
wmem = 0x0;
ret = wiimote_cmd_write(wdata, 0xa400fb, &wmem, sizeof(wmem));
if (ret)
return ret;
return 0;
}
static __u8 wiimote_cmd_read_ext(struct wiimote_data *wdata, __u8 *rmem)
{
int ret;
ret = wiimote_cmd_read(wdata, 0xa400fa, rmem, 6);
if (ret != 6)
return WIIMOTE_EXT_NONE;
hid_dbg(wdata->hdev, "extension ID: %6phC\n", rmem);
if (rmem[0] == 0xff && rmem[1] == 0xff && rmem[2] == 0xff &&
rmem[3] == 0xff && rmem[4] == 0xff && rmem[5] == 0xff)
return WIIMOTE_EXT_NONE;
if (rmem[4] == 0x00 && rmem[5] == 0x00)
return WIIMOTE_EXT_NUNCHUK;
if (rmem[4] == 0x01 && rmem[5] == 0x01)
return WIIMOTE_EXT_CLASSIC_CONTROLLER;
if (rmem[4] == 0x04 && rmem[5] == 0x02)
return WIIMOTE_EXT_BALANCE_BOARD;
if (rmem[4] == 0x01 && rmem[5] == 0x20)
return WIIMOTE_EXT_PRO_CONTROLLER;
return WIIMOTE_EXT_UNKNOWN;
}
static int wiimote_cmd_init_mp(struct wiimote_data *wdata)
{
__u8 wmem;
int ret;
wmem = 0x55;
ret = wiimote_cmd_write(wdata, 0xa600f0, &wmem, sizeof(wmem));
if (ret)
return ret;
wmem = 0x0;
ret = wiimote_cmd_write(wdata, 0xa600fb, &wmem, sizeof(wmem));
if (ret)
return ret;
return 0;
}
static bool wiimote_cmd_map_mp(struct wiimote_data *wdata, __u8 exttype)
{
__u8 wmem;
switch (exttype) {
case WIIMOTE_EXT_CLASSIC_CONTROLLER:
wmem = 0x07;
break;
case WIIMOTE_EXT_NUNCHUK:
wmem = 0x05;
break;
default:
wmem = 0x04;
break;
}
return wiimote_cmd_write(wdata, 0xa600fe, &wmem, sizeof(wmem));
}
static bool wiimote_cmd_read_mp(struct wiimote_data *wdata, __u8 *rmem)
{
int ret;
ret = wiimote_cmd_read(wdata, 0xa600fa, rmem, 6);
if (ret != 6)
return false;
hid_dbg(wdata->hdev, "motion plus ID: %6phC\n", rmem);
if (rmem[5] == 0x05)
return true;
hid_info(wdata->hdev, "unknown motion plus ID: %6phC\n", rmem);
return false;
}
static __u8 wiimote_cmd_read_mp_mapped(struct wiimote_data *wdata)
{
int ret;
__u8 rmem[6];
ret = wiimote_cmd_read(wdata, 0xa400fa, rmem, 6);
if (ret != 6)
return WIIMOTE_MP_NONE;
hid_dbg(wdata->hdev, "mapped motion plus ID: %6phC\n", rmem);
if (rmem[0] == 0xff && rmem[1] == 0xff && rmem[2] == 0xff &&
rmem[3] == 0xff && rmem[4] == 0xff && rmem[5] == 0xff)
return WIIMOTE_MP_NONE;
if (rmem[4] == 0x04 && rmem[5] == 0x05)
return WIIMOTE_MP_SINGLE;
else if (rmem[4] == 0x05 && rmem[5] == 0x05)
return WIIMOTE_MP_PASSTHROUGH_NUNCHUK;
else if (rmem[4] == 0x07 && rmem[5] == 0x05)
return WIIMOTE_MP_PASSTHROUGH_CLASSIC;
return WIIMOTE_MP_UNKNOWN;
}
static void wiimote_modules_load(struct wiimote_data *wdata,
unsigned int devtype)
{
bool need_input = false;
const __u8 *mods, *iter;
const struct wiimod_ops *ops;
int ret;
mods = wiimote_devtype_mods[devtype];
for (iter = mods; *iter != WIIMOD_NULL; ++iter) {
if (wiimod_table[*iter]->flags & WIIMOD_FLAG_INPUT) {
need_input = true;
break;
}
}
if (need_input) {
wdata->input = input_allocate_device();
if (!wdata->input)
return;
input_set_drvdata(wdata->input, wdata);
wdata->input->dev.parent = &wdata->hdev->dev;
wdata->input->id.bustype = wdata->hdev->bus;
wdata->input->id.vendor = wdata->hdev->vendor;
wdata->input->id.product = wdata->hdev->product;
wdata->input->id.version = wdata->hdev->version;
wdata->input->name = WIIMOTE_NAME;
}
for (iter = mods; *iter != WIIMOD_NULL; ++iter) {
ops = wiimod_table[*iter];
if (!ops->probe)
continue;
ret = ops->probe(ops, wdata);
if (ret)
goto error;
}
if (wdata->input) {
ret = input_register_device(wdata->input);
if (ret)
goto error;
}
spin_lock_irq(&wdata->state.lock);
wdata->state.devtype = devtype;
spin_unlock_irq(&wdata->state.lock);
return;
error:
for ( ; iter-- != mods; ) {
ops = wiimod_table[*iter];
if (ops->remove)
ops->remove(ops, wdata);
}
if (wdata->input) {
input_free_device(wdata->input);
wdata->input = NULL;
}
}
static void wiimote_modules_unload(struct wiimote_data *wdata)
{
const __u8 *mods, *iter;
const struct wiimod_ops *ops;
unsigned long flags;
mods = wiimote_devtype_mods[wdata->state.devtype];
spin_lock_irqsave(&wdata->state.lock, flags);
wdata->state.devtype = WIIMOTE_DEV_UNKNOWN;
spin_unlock_irqrestore(&wdata->state.lock, flags);
for (iter = mods; *iter != WIIMOD_NULL; ++iter)
;
if (wdata->input) {
input_get_device(wdata->input);
input_unregister_device(wdata->input);
}
for ( ; iter-- != mods; ) {
ops = wiimod_table[*iter];
if (ops->remove)
ops->remove(ops, wdata);
}
if (wdata->input) {
input_put_device(wdata->input);
wdata->input = NULL;
}
}
static void wiimote_ext_load(struct wiimote_data *wdata, unsigned int ext)
{
unsigned long flags;
const struct wiimod_ops *ops;
int ret;
ops = wiimod_ext_table[ext];
if (ops->probe) {
ret = ops->probe(ops, wdata);
if (ret)
ext = WIIMOTE_EXT_UNKNOWN;
}
spin_lock_irqsave(&wdata->state.lock, flags);
wdata->state.exttype = ext;
spin_unlock_irqrestore(&wdata->state.lock, flags);
}
static void wiimote_ext_unload(struct wiimote_data *wdata)
{
unsigned long flags;
const struct wiimod_ops *ops;
ops = wiimod_ext_table[wdata->state.exttype];
spin_lock_irqsave(&wdata->state.lock, flags);
wdata->state.exttype = WIIMOTE_EXT_UNKNOWN;
wdata->state.flags &= ~WIIPROTO_FLAG_EXT_USED;
spin_unlock_irqrestore(&wdata->state.lock, flags);
if (ops->remove)
ops->remove(ops, wdata);
}
static void wiimote_mp_load(struct wiimote_data *wdata)
{
unsigned long flags;
const struct wiimod_ops *ops;
int ret;
__u8 mode = 2;
ops = &wiimod_mp;
if (ops->probe) {
ret = ops->probe(ops, wdata);
if (ret)
mode = 1;
}
spin_lock_irqsave(&wdata->state.lock, flags);
wdata->state.mp = mode;
spin_unlock_irqrestore(&wdata->state.lock, flags);
}
static void wiimote_mp_unload(struct wiimote_data *wdata)
{
unsigned long flags;
const struct wiimod_ops *ops;
if (wdata->state.mp < 2)
return;
ops = &wiimod_mp;
spin_lock_irqsave(&wdata->state.lock, flags);
wdata->state.mp = 0;
wdata->state.flags &= ~WIIPROTO_FLAG_MP_USED;
spin_unlock_irqrestore(&wdata->state.lock, flags);
if (ops->remove)
ops->remove(ops, wdata);
}
static void wiimote_init_set_type(struct wiimote_data *wdata,
__u8 exttype)
{
__u8 devtype = WIIMOTE_DEV_GENERIC;
__u16 vendor, product;
const char *name;
vendor = wdata->hdev->vendor;
product = wdata->hdev->product;
name = wdata->hdev->name;
if (exttype == WIIMOTE_EXT_BALANCE_BOARD) {
devtype = WIIMOTE_DEV_BALANCE_BOARD;
goto done;
} else if (exttype == WIIMOTE_EXT_PRO_CONTROLLER) {
devtype = WIIMOTE_DEV_PRO_CONTROLLER;
goto done;
}
if (!strcmp(name, "Nintendo RVL-CNT-01")) {
devtype = WIIMOTE_DEV_GEN10;
goto done;
} else if (!strcmp(name, "Nintendo RVL-CNT-01-TR")) {
devtype = WIIMOTE_DEV_GEN20;
goto done;
} else if (!strcmp(name, "Nintendo RVL-WBC-01")) {
devtype = WIIMOTE_DEV_BALANCE_BOARD;
goto done;
} else if (!strcmp(name, "Nintendo RVL-CNT-01-UC")) {
devtype = WIIMOTE_DEV_PRO_CONTROLLER;
goto done;
}
if (vendor == USB_VENDOR_ID_NINTENDO) {
if (product == USB_DEVICE_ID_NINTENDO_WIIMOTE) {
devtype = WIIMOTE_DEV_GEN10;
goto done;
} else if (product == USB_DEVICE_ID_NINTENDO_WIIMOTE2) {
devtype = WIIMOTE_DEV_GEN20;
goto done;
}
}
done:
if (devtype == WIIMOTE_DEV_GENERIC)
hid_info(wdata->hdev, "cannot detect device; NAME: %s VID: %04x PID: %04x EXT: %04x\n",
name, vendor, product, exttype);
else
hid_info(wdata->hdev, "detected device: %s\n",
wiimote_devtype_names[devtype]);
wiimote_modules_load(wdata, devtype);
}
static void wiimote_init_detect(struct wiimote_data *wdata)
{
__u8 exttype = WIIMOTE_EXT_NONE, extdata[6];
bool ext;
int ret;
wiimote_cmd_acquire_noint(wdata);
spin_lock_irq(&wdata->state.lock);
wdata->state.devtype = WIIMOTE_DEV_UNKNOWN;
wiimote_cmd_set(wdata, WIIPROTO_REQ_SREQ, 0);
wiiproto_req_status(wdata);
spin_unlock_irq(&wdata->state.lock);
ret = wiimote_cmd_wait_noint(wdata);
if (ret)
goto out_release;
spin_lock_irq(&wdata->state.lock);
ext = wdata->state.flags & WIIPROTO_FLAG_EXT_PLUGGED;
spin_unlock_irq(&wdata->state.lock);
if (!ext)
goto out_release;
wiimote_cmd_init_ext(wdata);
exttype = wiimote_cmd_read_ext(wdata, extdata);
out_release:
wiimote_cmd_release(wdata);
wiimote_init_set_type(wdata, exttype);
spin_lock_irq(&wdata->state.lock);
if (!(wdata->state.flags & WIIPROTO_FLAG_BUILTIN_MP) &&
!(wdata->state.flags & WIIPROTO_FLAG_NO_MP))
mod_timer(&wdata->timer, jiffies + HZ * 4);
spin_unlock_irq(&wdata->state.lock);
}
static void wiimote_init_poll_mp(struct wiimote_data *wdata)
{
bool mp;
__u8 mpdata[6];
wiimote_cmd_acquire_noint(wdata);
wiimote_cmd_init_mp(wdata);
mp = wiimote_cmd_read_mp(wdata, mpdata);
wiimote_cmd_release(wdata);
if (mp) {
if (!wdata->state.mp) {
hid_info(wdata->hdev, "detected extension: Nintendo Wii Motion Plus\n");
wiimote_mp_load(wdata);
}
} else if (wdata->state.mp) {
wiimote_mp_unload(wdata);
}
mod_timer(&wdata->timer, jiffies + HZ * 4);
}
static bool wiimote_init_check(struct wiimote_data *wdata)
{
__u32 flags;
__u8 type, data[6];
bool ret, poll_mp;
spin_lock_irq(&wdata->state.lock);
flags = wdata->state.flags;
spin_unlock_irq(&wdata->state.lock);
wiimote_cmd_acquire_noint(wdata);
if (wdata->state.exttype == WIIMOTE_EXT_NONE &&
wdata->state.mp > 0 && (flags & WIIPROTO_FLAG_MP_USED)) {
type = wiimote_cmd_read_mp_mapped(wdata);
ret = type == WIIMOTE_MP_SINGLE;
spin_lock_irq(&wdata->state.lock);
ret = ret && !(wdata->state.flags & WIIPROTO_FLAG_EXT_ACTIVE);
ret = ret && !(wdata->state.flags & WIIPROTO_FLAG_MP_PLUGGED);
ret = ret && (wdata->state.flags & WIIPROTO_FLAG_MP_ACTIVE);
spin_unlock_irq(&wdata->state.lock);
if (!ret)
hid_dbg(wdata->hdev, "state left: !EXT && MP\n");
poll_mp = false;
goto out_release;
}
if (!(flags & WIIPROTO_FLAG_MP_USED) &&
wdata->state.exttype != WIIMOTE_EXT_NONE) {
type = wiimote_cmd_read_ext(wdata, data);
ret = type == wdata->state.exttype;
spin_lock_irq(&wdata->state.lock);
ret = ret && !(wdata->state.flags & WIIPROTO_FLAG_MP_ACTIVE);
ret = ret && (wdata->state.flags & WIIPROTO_FLAG_EXT_ACTIVE);
spin_unlock_irq(&wdata->state.lock);
if (!ret)
hid_dbg(wdata->hdev, "state left: EXT && !MP\n");
poll_mp = true;
goto out_release;
}
if (!(flags & WIIPROTO_FLAG_MP_USED) &&
wdata->state.exttype == WIIMOTE_EXT_NONE) {
type = wiimote_cmd_read_ext(wdata, data);
ret = type == wdata->state.exttype;
spin_lock_irq(&wdata->state.lock);
ret = ret && !(wdata->state.flags & WIIPROTO_FLAG_EXT_ACTIVE);
ret = ret && !(wdata->state.flags & WIIPROTO_FLAG_MP_ACTIVE);
ret = ret && !(wdata->state.flags & WIIPROTO_FLAG_EXT_PLUGGED);
spin_unlock_irq(&wdata->state.lock);
if (!ret)
hid_dbg(wdata->hdev, "state left: !EXT && !MP\n");
poll_mp = true;
goto out_release;
}
if (wdata->state.exttype != WIIMOTE_EXT_NONE &&
wdata->state.mp > 0 && (flags & WIIPROTO_FLAG_MP_USED)) {
type = wiimote_cmd_read_mp_mapped(wdata);
ret = type != WIIMOTE_MP_NONE;
ret = ret && type != WIIMOTE_MP_UNKNOWN;
ret = ret && type != WIIMOTE_MP_SINGLE;
spin_lock_irq(&wdata->state.lock);
ret = ret && (wdata->state.flags & WIIPROTO_FLAG_EXT_PLUGGED);
ret = ret && (wdata->state.flags & WIIPROTO_FLAG_EXT_ACTIVE);
ret = ret && (wdata->state.flags & WIIPROTO_FLAG_MP_ACTIVE);
spin_unlock_irq(&wdata->state.lock);
if (!ret)
hid_dbg(wdata->hdev, "state left: EXT && MP\n");
poll_mp = false;
goto out_release;
}
ret = false;
out_release:
wiimote_cmd_release(wdata);
if (ret && poll_mp && !(flags & WIIPROTO_FLAG_BUILTIN_MP) &&
!(flags & WIIPROTO_FLAG_NO_MP))
wiimote_init_poll_mp(wdata);
return ret;
}
static void wiimote_init_hotplug(struct wiimote_data *wdata)
{
__u8 exttype, extdata[6], mpdata[6];
__u32 flags;
bool mp;
hid_dbg(wdata->hdev, "detect extensions..\n");
wiimote_cmd_acquire_noint(wdata);
spin_lock_irq(&wdata->state.lock);
flags = wdata->state.flags;
wdata->state.flags &= ~WIIPROTO_FLAG_EXT_ACTIVE;
wdata->state.flags &= ~WIIPROTO_FLAG_MP_ACTIVE;
spin_unlock_irq(&wdata->state.lock);
wiimote_cmd_init_ext(wdata);
if (flags & WIIPROTO_FLAG_NO_MP) {
mp = false;
} else {
wiimote_cmd_init_mp(wdata);
mp = wiimote_cmd_read_mp(wdata, mpdata);
}
exttype = wiimote_cmd_read_ext(wdata, extdata);
wiimote_cmd_release(wdata);
if (exttype != wdata->state.exttype) {
wiimote_ext_unload(wdata);
if (exttype == WIIMOTE_EXT_UNKNOWN) {
hid_info(wdata->hdev, "cannot detect extension; %6phC\n",
extdata);
} else if (exttype == WIIMOTE_EXT_NONE) {
spin_lock_irq(&wdata->state.lock);
wdata->state.exttype = WIIMOTE_EXT_NONE;
spin_unlock_irq(&wdata->state.lock);
} else {
hid_info(wdata->hdev, "detected extension: %s\n",
wiimote_exttype_names[exttype]);
wiimote_ext_load(wdata, exttype);
}
}
if (mp) {
if (!wdata->state.mp) {
hid_info(wdata->hdev, "detected extension: Nintendo Wii Motion Plus\n");
wiimote_mp_load(wdata);
}
} else if (wdata->state.mp) {
wiimote_mp_unload(wdata);
}
if (!(flags & WIIPROTO_FLAG_MP_USED))
mp = false;
if (mp) {
wiimote_cmd_acquire_noint(wdata);
wiimote_cmd_map_mp(wdata, exttype);
wiimote_cmd_release(wdata);
del_timer_sync(&wdata->timer);
} else {
if (!(flags & WIIPROTO_FLAG_BUILTIN_MP) &&
!(flags & WIIPROTO_FLAG_NO_MP))
mod_timer(&wdata->timer, jiffies + HZ * 4);
}
spin_lock_irq(&wdata->state.lock);
if (mp) {
wdata->state.flags |= WIIPROTO_FLAG_MP_ACTIVE;
if (wdata->state.exttype == WIIMOTE_EXT_NONE) {
wdata->state.flags &= ~WIIPROTO_FLAG_EXT_PLUGGED;
wdata->state.flags &= ~WIIPROTO_FLAG_MP_PLUGGED;
} else {
wdata->state.flags &= ~WIIPROTO_FLAG_EXT_PLUGGED;
wdata->state.flags |= WIIPROTO_FLAG_MP_PLUGGED;
wdata->state.flags |= WIIPROTO_FLAG_EXT_ACTIVE;
}
} else if (wdata->state.exttype != WIIMOTE_EXT_NONE) {
wdata->state.flags |= WIIPROTO_FLAG_EXT_ACTIVE;
}
wiiproto_req_status(wdata);
spin_unlock_irq(&wdata->state.lock);
hid_dbg(wdata->hdev, "detected extensions: MP: %d EXT: %d\n",
wdata->state.mp, wdata->state.exttype);
}
static void wiimote_init_worker(struct work_struct *work)
{
struct wiimote_data *wdata = container_of(work, struct wiimote_data,
init_worker);
bool changed = false;
if (wdata->state.devtype == WIIMOTE_DEV_PENDING) {
wiimote_init_detect(wdata);
changed = true;
}
if (changed || !wiimote_init_check(wdata))
wiimote_init_hotplug(wdata);
if (changed)
kobject_uevent(&wdata->hdev->dev.kobj, KOBJ_CHANGE);
}
void __wiimote_schedule(struct wiimote_data *wdata)
{
if (!(wdata->state.flags & WIIPROTO_FLAG_EXITING))
schedule_work(&wdata->init_worker);
}
static void wiimote_schedule(struct wiimote_data *wdata)
{
unsigned long flags;
spin_lock_irqsave(&wdata->state.lock, flags);
__wiimote_schedule(wdata);
spin_unlock_irqrestore(&wdata->state.lock, flags);
}
static void wiimote_init_timeout(unsigned long arg)
{
struct wiimote_data *wdata = (void*)arg;
wiimote_schedule(wdata);
}
static void handler_keys(struct wiimote_data *wdata, const __u8 *payload)
{
const __u8 *iter, *mods;
const struct wiimod_ops *ops;
ops = wiimod_ext_table[wdata->state.exttype];
if (ops->in_keys) {
ops->in_keys(wdata, payload);
return;
}
mods = wiimote_devtype_mods[wdata->state.devtype];
for (iter = mods; *iter != WIIMOD_NULL; ++iter) {
ops = wiimod_table[*iter];
if (ops->in_keys) {
ops->in_keys(wdata, payload);
break;
}
}
}
static void handler_accel(struct wiimote_data *wdata, const __u8 *payload)
{
const __u8 *iter, *mods;
const struct wiimod_ops *ops;
ops = wiimod_ext_table[wdata->state.exttype];
if (ops->in_accel) {
ops->in_accel(wdata, payload);
return;
}
mods = wiimote_devtype_mods[wdata->state.devtype];
for (iter = mods; *iter != WIIMOD_NULL; ++iter) {
ops = wiimod_table[*iter];
if (ops->in_accel) {
ops->in_accel(wdata, payload);
break;
}
}
}
static bool valid_ext_handler(const struct wiimod_ops *ops, size_t len)
{
if (!ops->in_ext)
return false;
if ((ops->flags & WIIMOD_FLAG_EXT8) && len < 8)
return false;
if ((ops->flags & WIIMOD_FLAG_EXT16) && len < 16)
return false;
return true;
}
static void handler_ext(struct wiimote_data *wdata, const __u8 *payload,
size_t len)
{
static const __u8 invalid[21] = { 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff,
0xff };
const __u8 *iter, *mods;
const struct wiimod_ops *ops;
bool is_mp;
if (len > 21)
len = 21;
if (len < 6 || !memcmp(payload, invalid, len))
return;
if (wdata->state.flags & WIIPROTO_FLAG_MP_ACTIVE) {
if (payload[5] & 0x01)
return;
if (payload[4] & 0x01) {
if (!(wdata->state.flags & WIIPROTO_FLAG_MP_PLUGGED)) {
hid_dbg(wdata->hdev, "MP hotplug: 1\n");
wdata->state.flags |= WIIPROTO_FLAG_MP_PLUGGED;
__wiimote_schedule(wdata);
}
} else {
if (wdata->state.flags & WIIPROTO_FLAG_MP_PLUGGED) {
hid_dbg(wdata->hdev, "MP hotplug: 0\n");
wdata->state.flags &= ~WIIPROTO_FLAG_MP_PLUGGED;
wdata->state.flags &= ~WIIPROTO_FLAG_EXT_ACTIVE;
__wiimote_schedule(wdata);
}
}
is_mp = payload[5] & 0x02;
} else {
is_mp = false;
}
if (!(wdata->state.flags & WIIPROTO_FLAG_EXT_ACTIVE) && !is_mp)
return;
ops = wiimod_ext_table[wdata->state.exttype];
if (is_mp && ops->in_mp) {
ops->in_mp(wdata, payload);
return;
} else if (!is_mp && valid_ext_handler(ops, len)) {
ops->in_ext(wdata, payload);
return;
}
ops = &wiimod_mp;
if (is_mp && ops->in_mp) {
ops->in_mp(wdata, payload);
return;
} else if (!is_mp && valid_ext_handler(ops, len)) {
ops->in_ext(wdata, payload);
return;
}
mods = wiimote_devtype_mods[wdata->state.devtype];
for (iter = mods; *iter != WIIMOD_NULL; ++iter) {
ops = wiimod_table[*iter];
if (is_mp && ops->in_mp) {
ops->in_mp(wdata, payload);
return;
} else if (!is_mp && valid_ext_handler(ops, len)) {
ops->in_ext(wdata, payload);
return;
}
}
}
static void handler_ir(struct wiimote_data *wdata, const __u8 *payload,
bool packed, unsigned int id)
{
const __u8 *iter, *mods;
const struct wiimod_ops *ops;
ops = wiimod_ext_table[wdata->state.exttype];
if (ops->in_ir) {
ops->in_ir(wdata, payload, packed, id);
return;
}
mods = wiimote_devtype_mods[wdata->state.devtype];
for (iter = mods; *iter != WIIMOD_NULL; ++iter) {
ops = wiimod_table[*iter];
if (ops->in_ir) {
ops->in_ir(wdata, payload, packed, id);
break;
}
}
}
static void handler_status_K(struct wiimote_data *wdata,
const __u8 *payload)
{
handler_keys(wdata, payload);
wiiproto_req_drm(wdata, WIIPROTO_REQ_NULL);
}
static void handler_status(struct wiimote_data *wdata, const __u8 *payload)
{
handler_status_K(wdata, payload);
if (payload[2] & 0x02) {
if (!(wdata->state.flags & WIIPROTO_FLAG_EXT_PLUGGED)) {
hid_dbg(wdata->hdev, "EXT hotplug: 1\n");
wdata->state.flags |= WIIPROTO_FLAG_EXT_PLUGGED;
__wiimote_schedule(wdata);
}
} else {
if (wdata->state.flags & WIIPROTO_FLAG_EXT_PLUGGED) {
hid_dbg(wdata->hdev, "EXT hotplug: 0\n");
wdata->state.flags &= ~WIIPROTO_FLAG_EXT_PLUGGED;
wdata->state.flags &= ~WIIPROTO_FLAG_MP_PLUGGED;
wdata->state.flags &= ~WIIPROTO_FLAG_EXT_ACTIVE;
wdata->state.flags &= ~WIIPROTO_FLAG_MP_ACTIVE;
__wiimote_schedule(wdata);
}
}
wdata->state.cmd_battery = payload[5];
if (wiimote_cmd_pending(wdata, WIIPROTO_REQ_SREQ, 0))
wiimote_cmd_complete(wdata);
}
static void handler_generic_K(struct wiimote_data *wdata, const __u8 *payload)
{
handler_keys(wdata, payload);
}
static void handler_data(struct wiimote_data *wdata, const __u8 *payload)
{
__u16 offset = payload[3] << 8 | payload[4];
__u8 size = (payload[2] >> 4) + 1;
__u8 err = payload[2] & 0x0f;
handler_keys(wdata, payload);
if (wiimote_cmd_pending(wdata, WIIPROTO_REQ_RMEM, offset)) {
if (err)
size = 0;
else if (size > wdata->state.cmd_read_size)
size = wdata->state.cmd_read_size;
wdata->state.cmd_read_size = size;
if (wdata->state.cmd_read_buf)
memcpy(wdata->state.cmd_read_buf, &payload[5], size);
wiimote_cmd_complete(wdata);
}
}
static void handler_return(struct wiimote_data *wdata, const __u8 *payload)
{
__u8 err = payload[3];
__u8 cmd = payload[2];
handler_keys(wdata, payload);
if (wiimote_cmd_pending(wdata, cmd, 0)) {
wdata->state.cmd_err = err;
wiimote_cmd_complete(wdata);
} else if (err) {
hid_warn(wdata->hdev, "Remote error %hhu on req %hhu\n", err,
cmd);
}
}
static void handler_drm_KA(struct wiimote_data *wdata, const __u8 *payload)
{
handler_keys(wdata, payload);
handler_accel(wdata, payload);
}
static void handler_drm_KE(struct wiimote_data *wdata, const __u8 *payload)
{
handler_keys(wdata, payload);
handler_ext(wdata, &payload[2], 8);
}
static void handler_drm_KAI(struct wiimote_data *wdata, const __u8 *payload)
{
handler_keys(wdata, payload);
handler_accel(wdata, payload);
ir_to_input0(wdata, &payload[5], false);
ir_to_input1(wdata, &payload[8], false);
ir_to_input2(wdata, &payload[11], false);
ir_to_input3(wdata, &payload[14], false);
}
static void handler_drm_KEE(struct wiimote_data *wdata, const __u8 *payload)
{
handler_keys(wdata, payload);
handler_ext(wdata, &payload[2], 19);
}
static void handler_drm_KIE(struct wiimote_data *wdata, const __u8 *payload)
{
handler_keys(wdata, payload);
ir_to_input0(wdata, &payload[2], false);
ir_to_input1(wdata, &payload[4], true);
ir_to_input2(wdata, &payload[7], false);
ir_to_input3(wdata, &payload[9], true);
handler_ext(wdata, &payload[12], 9);
}
static void handler_drm_KAE(struct wiimote_data *wdata, const __u8 *payload)
{
handler_keys(wdata, payload);
handler_accel(wdata, payload);
handler_ext(wdata, &payload[5], 16);
}
static void handler_drm_KAIE(struct wiimote_data *wdata, const __u8 *payload)
{
handler_keys(wdata, payload);
handler_accel(wdata, payload);
ir_to_input0(wdata, &payload[5], false);
ir_to_input1(wdata, &payload[7], true);
ir_to_input2(wdata, &payload[10], false);
ir_to_input3(wdata, &payload[12], true);
handler_ext(wdata, &payload[15], 6);
}
static void handler_drm_E(struct wiimote_data *wdata, const __u8 *payload)
{
handler_ext(wdata, payload, 21);
}
static void handler_drm_SKAI1(struct wiimote_data *wdata, const __u8 *payload)
{
handler_keys(wdata, payload);
wdata->state.accel_split[0] = payload[2];
wdata->state.accel_split[1] = (payload[0] >> 1) & (0x10 | 0x20);
wdata->state.accel_split[1] |= (payload[1] << 1) & (0x40 | 0x80);
ir_to_input0(wdata, &payload[3], false);
ir_to_input1(wdata, &payload[12], false);
}
static void handler_drm_SKAI2(struct wiimote_data *wdata, const __u8 *payload)
{
__u8 buf[5];
handler_keys(wdata, payload);
wdata->state.accel_split[1] |= (payload[0] >> 5) & (0x01 | 0x02);
wdata->state.accel_split[1] |= (payload[1] >> 3) & (0x04 | 0x08);
buf[0] = 0;
buf[1] = 0;
buf[2] = wdata->state.accel_split[0];
buf[3] = payload[2];
buf[4] = wdata->state.accel_split[1];
handler_accel(wdata, buf);
ir_to_input2(wdata, &payload[3], false);
ir_to_input3(wdata, &payload[12], false);
}
static int wiimote_hid_event(struct hid_device *hdev, struct hid_report *report,
u8 *raw_data, int size)
{
struct wiimote_data *wdata = hid_get_drvdata(hdev);
struct wiiproto_handler *h;
int i;
unsigned long flags;
if (size < 1)
return -EINVAL;
spin_lock_irqsave(&wdata->state.lock, flags);
for (i = 0; handlers[i].id; ++i) {
h = &handlers[i];
if (h->id == raw_data[0] && h->size < size) {
h->func(wdata, &raw_data[1]);
break;
}
}
if (!handlers[i].id)
hid_warn(hdev, "Unhandled report %hhu size %d\n", raw_data[0],
size);
spin_unlock_irqrestore(&wdata->state.lock, flags);
return 0;
}
static ssize_t wiimote_ext_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct wiimote_data *wdata = dev_to_wii(dev);
__u8 type;
unsigned long flags;
spin_lock_irqsave(&wdata->state.lock, flags);
type = wdata->state.exttype;
spin_unlock_irqrestore(&wdata->state.lock, flags);
switch (type) {
case WIIMOTE_EXT_NONE:
return sprintf(buf, "none\n");
case WIIMOTE_EXT_NUNCHUK:
return sprintf(buf, "nunchuk\n");
case WIIMOTE_EXT_CLASSIC_CONTROLLER:
return sprintf(buf, "classic\n");
case WIIMOTE_EXT_BALANCE_BOARD:
return sprintf(buf, "balanceboard\n");
case WIIMOTE_EXT_PRO_CONTROLLER:
return sprintf(buf, "procontroller\n");
case WIIMOTE_EXT_UNKNOWN:
default:
return sprintf(buf, "unknown\n");
}
}
static ssize_t wiimote_ext_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct wiimote_data *wdata = dev_to_wii(dev);
if (!strcmp(buf, "scan")) {
wiimote_schedule(wdata);
} else {
return -EINVAL;
}
return strnlen(buf, PAGE_SIZE);
}
static ssize_t wiimote_dev_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct wiimote_data *wdata = dev_to_wii(dev);
__u8 type;
unsigned long flags;
spin_lock_irqsave(&wdata->state.lock, flags);
type = wdata->state.devtype;
spin_unlock_irqrestore(&wdata->state.lock, flags);
switch (type) {
case WIIMOTE_DEV_GENERIC:
return sprintf(buf, "generic\n");
case WIIMOTE_DEV_GEN10:
return sprintf(buf, "gen10\n");
case WIIMOTE_DEV_GEN20:
return sprintf(buf, "gen20\n");
case WIIMOTE_DEV_BALANCE_BOARD:
return sprintf(buf, "balanceboard\n");
case WIIMOTE_DEV_PRO_CONTROLLER:
return sprintf(buf, "procontroller\n");
case WIIMOTE_DEV_PENDING:
return sprintf(buf, "pending\n");
case WIIMOTE_DEV_UNKNOWN:
default:
return sprintf(buf, "unknown\n");
}
}
static struct wiimote_data *wiimote_create(struct hid_device *hdev)
{
struct wiimote_data *wdata;
wdata = kzalloc(sizeof(*wdata), GFP_KERNEL);
if (!wdata)
return NULL;
wdata->hdev = hdev;
hid_set_drvdata(hdev, wdata);
spin_lock_init(&wdata->queue.lock);
INIT_WORK(&wdata->queue.worker, wiimote_queue_worker);
spin_lock_init(&wdata->state.lock);
init_completion(&wdata->state.ready);
mutex_init(&wdata->state.sync);
wdata->state.drm = WIIPROTO_REQ_DRM_K;
wdata->state.cmd_battery = 0xff;
INIT_WORK(&wdata->init_worker, wiimote_init_worker);
setup_timer(&wdata->timer, wiimote_init_timeout, (long)wdata);
return wdata;
}
static void wiimote_destroy(struct wiimote_data *wdata)
{
unsigned long flags;
wiidebug_deinit(wdata);
spin_lock_irqsave(&wdata->state.lock, flags);
wdata->state.flags |= WIIPROTO_FLAG_EXITING;
spin_unlock_irqrestore(&wdata->state.lock, flags);
cancel_work_sync(&wdata->init_worker);
del_timer_sync(&wdata->timer);
device_remove_file(&wdata->hdev->dev, &dev_attr_devtype);
device_remove_file(&wdata->hdev->dev, &dev_attr_extension);
wiimote_mp_unload(wdata);
wiimote_ext_unload(wdata);
wiimote_modules_unload(wdata);
cancel_work_sync(&wdata->queue.worker);
hid_hw_close(wdata->hdev);
hid_hw_stop(wdata->hdev);
kfree(wdata);
}
static int wiimote_hid_probe(struct hid_device *hdev,
const struct hid_device_id *id)
{
struct wiimote_data *wdata;
int ret;
hdev->quirks |= HID_QUIRK_NO_INIT_REPORTS;
wdata = wiimote_create(hdev);
if (!wdata) {
hid_err(hdev, "Can't alloc device\n");
return -ENOMEM;
}
ret = hid_parse(hdev);
if (ret) {
hid_err(hdev, "HID parse failed\n");
goto err;
}
ret = hid_hw_start(hdev, HID_CONNECT_HIDRAW);
if (ret) {
hid_err(hdev, "HW start failed\n");
goto err;
}
ret = hid_hw_open(hdev);
if (ret) {
hid_err(hdev, "cannot start hardware I/O\n");
goto err_stop;
}
ret = device_create_file(&hdev->dev, &dev_attr_extension);
if (ret) {
hid_err(hdev, "cannot create sysfs attribute\n");
goto err_close;
}
ret = device_create_file(&hdev->dev, &dev_attr_devtype);
if (ret) {
hid_err(hdev, "cannot create sysfs attribute\n");
goto err_ext;
}
ret = wiidebug_init(wdata);
if (ret)
goto err_free;
hid_info(hdev, "New device registered\n");
wiimote_schedule(wdata);
return 0;
err_free:
wiimote_destroy(wdata);
return ret;
err_ext:
device_remove_file(&wdata->hdev->dev, &dev_attr_extension);
err_close:
hid_hw_close(hdev);
err_stop:
hid_hw_stop(hdev);
err:
input_free_device(wdata->ir);
input_free_device(wdata->accel);
kfree(wdata);
return ret;
}
static void wiimote_hid_remove(struct hid_device *hdev)
{
struct wiimote_data *wdata = hid_get_drvdata(hdev);
hid_info(hdev, "Device removed\n");
wiimote_destroy(wdata);
}
