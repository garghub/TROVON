static int setChar(struct yealink_dev *yld, int el, int chr)
{
int i, a, m, val;
if (el >= ARRAY_SIZE(lcdMap))
return -EINVAL;
if (chr == '\t' || chr == '\n')
return 0;
yld->lcdMap[el] = chr;
if (lcdMap[el].type == '.') {
a = lcdMap[el].u.p.a;
m = lcdMap[el].u.p.m;
if (chr != ' ')
yld->master.b[a] |= m;
else
yld->master.b[a] &= ~m;
return 0;
}
val = map_to_seg7(&map_seg7, chr);
for (i = 0; i < ARRAY_SIZE(lcdMap[0].u.s); i++) {
m = lcdMap[el].u.s[i].m;
if (m == 0)
continue;
a = lcdMap[el].u.s[i].a;
if (val & 1)
yld->master.b[a] |= m;
else
yld->master.b[a] &= ~m;
val = val >> 1;
}
return 0;
}
static int map_p1k_to_key(int scancode)
{
switch(scancode) {
case 0x23: return KEY_LEFT;
case 0x33: return KEY_UP;
case 0x04: return KEY_RIGHT;
case 0x24: return KEY_DOWN;
case 0x03: return KEY_ENTER;
case 0x14: return KEY_BACKSPACE;
case 0x13: return KEY_ESC;
case 0x00: return KEY_1;
case 0x01: return KEY_2;
case 0x02: return KEY_3;
case 0x10: return KEY_4;
case 0x11: return KEY_5;
case 0x12: return KEY_6;
case 0x20: return KEY_7;
case 0x21: return KEY_8;
case 0x22: return KEY_9;
case 0x30: return KEY_KPASTERISK;
case 0x31: return KEY_0;
case 0x32: return KEY_LEFTSHIFT |
KEY_3 << 8;
}
return -EINVAL;
}
static void report_key(struct yealink_dev *yld, int key)
{
struct input_dev *idev = yld->idev;
if (yld->key_code >= 0) {
input_report_key(idev, yld->key_code & 0xff, 0);
if (yld->key_code >> 8)
input_report_key(idev, yld->key_code >> 8, 0);
}
yld->key_code = key;
if (key >= 0) {
input_report_key(idev, key & 0xff, 1);
if (key >> 8)
input_report_key(idev, key >> 8, 1);
}
input_sync(idev);
}
static int yealink_cmd(struct yealink_dev *yld, struct yld_ctl_packet *p)
{
u8 *buf = (u8 *)p;
int i;
u8 sum = 0;
for(i=0; i<USB_PKT_LEN-1; i++)
sum -= buf[i];
p->sum = sum;
return usb_control_msg(yld->udev,
usb_sndctrlpipe(yld->udev, 0),
USB_REQ_SET_CONFIGURATION,
USB_TYPE_CLASS | USB_RECIP_INTERFACE | USB_DIR_OUT,
0x200, 3,
p, sizeof(*p),
USB_CTRL_SET_TIMEOUT);
}
static int yealink_set_ringtone(struct yealink_dev *yld, u8 *buf, size_t size)
{
struct yld_ctl_packet *p = yld->ctl_data;
int ix, len;
if (size <= 0)
return -EINVAL;
memset(yld->ctl_data, 0, sizeof(*(yld->ctl_data)));
yld->ctl_data->cmd = CMD_RING_VOLUME;
yld->ctl_data->size = 1;
yld->ctl_data->data[0] = buf[0];
yealink_cmd(yld, p);
buf++;
size--;
p->cmd = CMD_RING_NOTE;
ix = 0;
while (size != ix) {
len = size - ix;
if (len > sizeof(p->data))
len = sizeof(p->data);
p->size = len;
p->offset = cpu_to_be16(ix);
memcpy(p->data, &buf[ix], len);
yealink_cmd(yld, p);
ix += len;
}
return 0;
}
static int yealink_do_idle_tasks(struct yealink_dev *yld)
{
u8 val;
int i, ix, len;
ix = yld->stat_ix;
memset(yld->ctl_data, 0, sizeof(*(yld->ctl_data)));
yld->ctl_data->cmd = CMD_KEYPRESS;
yld->ctl_data->size = 1;
yld->ctl_data->sum = 0xff - CMD_KEYPRESS;
if (ix >= sizeof(yld->master)) {
yld->stat_ix = 0;
return 0;
}
do {
val = yld->master.b[ix];
if (val != yld->copy.b[ix])
goto send_update;
} while (++ix < sizeof(yld->master));
yld->stat_ix = 0;
return 0;
send_update:
yld->copy.b[ix] = val;
yld->ctl_data->data[0] = val;
switch(ix) {
case offsetof(struct yld_status, led):
yld->ctl_data->cmd = CMD_LED;
yld->ctl_data->sum = -1 - CMD_LED - val;
break;
case offsetof(struct yld_status, dialtone):
yld->ctl_data->cmd = CMD_DIALTONE;
yld->ctl_data->sum = -1 - CMD_DIALTONE - val;
break;
case offsetof(struct yld_status, ringtone):
yld->ctl_data->cmd = CMD_RINGTONE;
yld->ctl_data->sum = -1 - CMD_RINGTONE - val;
break;
case offsetof(struct yld_status, keynum):
val--;
val &= 0x1f;
yld->ctl_data->cmd = CMD_SCANCODE;
yld->ctl_data->offset = cpu_to_be16(val);
yld->ctl_data->data[0] = 0;
yld->ctl_data->sum = -1 - CMD_SCANCODE - val;
break;
default:
len = sizeof(yld->master.s.lcd) - ix;
if (len > sizeof(yld->ctl_data->data))
len = sizeof(yld->ctl_data->data);
yld->ctl_data->cmd = CMD_LCD;
yld->ctl_data->offset = cpu_to_be16(ix);
yld->ctl_data->size = len;
yld->ctl_data->sum = -CMD_LCD - ix - val - len;
for(i=1; i<len; i++) {
ix++;
val = yld->master.b[ix];
yld->copy.b[ix] = val;
yld->ctl_data->data[i] = val;
yld->ctl_data->sum -= val;
}
}
yld->stat_ix = ix + 1;
return 1;
}
static void urb_irq_callback(struct urb *urb)
{
struct yealink_dev *yld = urb->context;
int ret, status = urb->status;
if (status)
dev_err(&yld->intf->dev, "%s - urb status %d\n",
__func__, status);
switch (yld->irq_data->cmd) {
case CMD_KEYPRESS:
yld->master.s.keynum = yld->irq_data->data[0];
break;
case CMD_SCANCODE:
dev_dbg(&yld->intf->dev, "get scancode %x\n",
yld->irq_data->data[0]);
report_key(yld, map_p1k_to_key(yld->irq_data->data[0]));
break;
default:
dev_err(&yld->intf->dev, "unexpected response %x\n",
yld->irq_data->cmd);
}
yealink_do_idle_tasks(yld);
if (!yld->shutdown) {
ret = usb_submit_urb(yld->urb_ctl, GFP_ATOMIC);
if (ret && ret != -EPERM)
dev_err(&yld->intf->dev,
"%s - usb_submit_urb failed %d\n",
__func__, ret);
}
}
static void urb_ctl_callback(struct urb *urb)
{
struct yealink_dev *yld = urb->context;
int ret = 0, status = urb->status;
if (status)
dev_err(&yld->intf->dev, "%s - urb status %d\n",
__func__, status);
switch (yld->ctl_data->cmd) {
case CMD_KEYPRESS:
case CMD_SCANCODE:
if (!yld->shutdown)
ret = usb_submit_urb(yld->urb_irq, GFP_ATOMIC);
break;
default:
yealink_do_idle_tasks(yld);
if (!yld->shutdown)
ret = usb_submit_urb(yld->urb_ctl, GFP_ATOMIC);
break;
}
if (ret && ret != -EPERM)
dev_err(&yld->intf->dev, "%s - usb_submit_urb failed %d\n",
__func__, ret);
}
static int input_open(struct input_dev *dev)
{
struct yealink_dev *yld = input_get_drvdata(dev);
int i, ret;
dev_dbg(&yld->intf->dev, "%s\n", __func__);
for (i = 0; i<sizeof(yld->master); i++)
yld->copy.b[i] = ~yld->master.b[i];
yld->key_code = -1;
yealink_set_ringtone(yld, default_ringtone, sizeof(default_ringtone));
memset(yld->ctl_data, 0, sizeof(*(yld->ctl_data)));
yld->ctl_data->cmd = CMD_INIT;
yld->ctl_data->size = 10;
yld->ctl_data->sum = 0x100-CMD_INIT-10;
if ((ret = usb_submit_urb(yld->urb_ctl, GFP_KERNEL)) != 0) {
dev_dbg(&yld->intf->dev,
"%s - usb_submit_urb failed with result %d\n",
__func__, ret);
return ret;
}
return 0;
}
static void input_close(struct input_dev *dev)
{
struct yealink_dev *yld = input_get_drvdata(dev);
yld->shutdown = 1;
smp_wmb();
usb_kill_urb(yld->urb_ctl);
usb_kill_urb(yld->urb_irq);
yld->shutdown = 0;
smp_wmb();
}
static ssize_t show_map(struct device *dev, struct device_attribute *attr,
char *buf)
{
memcpy(buf, &map_seg7, sizeof(map_seg7));
return sizeof(map_seg7);
}
static ssize_t store_map(struct device *dev, struct device_attribute *attr,
const char *buf, size_t cnt)
{
if (cnt != sizeof(map_seg7))
return -EINVAL;
memcpy(&map_seg7, buf, sizeof(map_seg7));
return sizeof(map_seg7);
}
static ssize_t show_line(struct device *dev, char *buf, int a, int b)
{
struct yealink_dev *yld;
int i;
down_read(&sysfs_rwsema);
yld = dev_get_drvdata(dev);
if (yld == NULL) {
up_read(&sysfs_rwsema);
return -ENODEV;
}
for (i = a; i < b; i++)
*buf++ = lcdMap[i].type;
*buf++ = '\n';
for (i = a; i < b; i++)
*buf++ = yld->lcdMap[i];
*buf++ = '\n';
*buf = 0;
up_read(&sysfs_rwsema);
return 3 + ((b - a) << 1);
}
static ssize_t show_line1(struct device *dev, struct device_attribute *attr,
char *buf)
{
return show_line(dev, buf, LCD_LINE1_OFFSET, LCD_LINE2_OFFSET);
}
static ssize_t show_line2(struct device *dev, struct device_attribute *attr,
char *buf)
{
return show_line(dev, buf, LCD_LINE2_OFFSET, LCD_LINE3_OFFSET);
}
static ssize_t show_line3(struct device *dev, struct device_attribute *attr,
char *buf)
{
return show_line(dev, buf, LCD_LINE3_OFFSET, LCD_LINE4_OFFSET);
}
static ssize_t store_line(struct device *dev, const char *buf, size_t count,
int el, size_t len)
{
struct yealink_dev *yld;
int i;
down_write(&sysfs_rwsema);
yld = dev_get_drvdata(dev);
if (yld == NULL) {
up_write(&sysfs_rwsema);
return -ENODEV;
}
if (len > count)
len = count;
for (i = 0; i < len; i++)
setChar(yld, el++, buf[i]);
up_write(&sysfs_rwsema);
return count;
}
static ssize_t store_line1(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
return store_line(dev, buf, count, LCD_LINE1_OFFSET, LCD_LINE1_SIZE);
}
static ssize_t store_line2(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
return store_line(dev, buf, count, LCD_LINE2_OFFSET, LCD_LINE2_SIZE);
}
static ssize_t store_line3(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
return store_line(dev, buf, count, LCD_LINE3_OFFSET, LCD_LINE3_SIZE);
}
static ssize_t get_icons(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct yealink_dev *yld;
int i, ret = 1;
down_read(&sysfs_rwsema);
yld = dev_get_drvdata(dev);
if (yld == NULL) {
up_read(&sysfs_rwsema);
return -ENODEV;
}
for (i = 0; i < ARRAY_SIZE(lcdMap); i++) {
if (lcdMap[i].type != '.')
continue;
ret += sprintf(&buf[ret], "%s %s\n",
yld->lcdMap[i] == ' ' ? " " : "on",
lcdMap[i].u.p.name);
}
up_read(&sysfs_rwsema);
return ret;
}
static ssize_t set_icon(struct device *dev, const char *buf, size_t count,
int chr)
{
struct yealink_dev *yld;
int i;
down_write(&sysfs_rwsema);
yld = dev_get_drvdata(dev);
if (yld == NULL) {
up_write(&sysfs_rwsema);
return -ENODEV;
}
for (i = 0; i < ARRAY_SIZE(lcdMap); i++) {
if (lcdMap[i].type != '.')
continue;
if (strncmp(buf, lcdMap[i].u.p.name, count) == 0) {
setChar(yld, i, chr);
break;
}
}
up_write(&sysfs_rwsema);
return count;
}
static ssize_t show_icon(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
return set_icon(dev, buf, count, buf[0]);
}
static ssize_t hide_icon(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
return set_icon(dev, buf, count, ' ');
}
static ssize_t store_ringtone(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct yealink_dev *yld;
down_write(&sysfs_rwsema);
yld = dev_get_drvdata(dev);
if (yld == NULL) {
up_write(&sysfs_rwsema);
return -ENODEV;
}
yealink_set_ringtone(yld, (char *)buf, count);
up_write(&sysfs_rwsema);
return count;
}
static int usb_cleanup(struct yealink_dev *yld, int err)
{
if (yld == NULL)
return err;
if (yld->idev) {
if (err)
input_free_device(yld->idev);
else
input_unregister_device(yld->idev);
}
usb_free_urb(yld->urb_irq);
usb_free_urb(yld->urb_ctl);
kfree(yld->ctl_req);
usb_free_coherent(yld->udev, USB_PKT_LEN, yld->ctl_data, yld->ctl_dma);
usb_free_coherent(yld->udev, USB_PKT_LEN, yld->irq_data, yld->irq_dma);
kfree(yld);
return err;
}
static void usb_disconnect(struct usb_interface *intf)
{
struct yealink_dev *yld;
down_write(&sysfs_rwsema);
yld = usb_get_intfdata(intf);
sysfs_remove_group(&intf->dev.kobj, &yld_attr_group);
usb_set_intfdata(intf, NULL);
up_write(&sysfs_rwsema);
usb_cleanup(yld, 0);
}
static int usb_probe(struct usb_interface *intf, const struct usb_device_id *id)
{
struct usb_device *udev = interface_to_usbdev (intf);
struct driver_info *nfo = (struct driver_info *)id->driver_info;
struct usb_host_interface *interface;
struct usb_endpoint_descriptor *endpoint;
struct yealink_dev *yld;
struct input_dev *input_dev;
int ret, pipe, i;
interface = intf->cur_altsetting;
if (interface->desc.bNumEndpoints < 1)
return -ENODEV;
endpoint = &interface->endpoint[0].desc;
if (!usb_endpoint_is_int_in(endpoint))
return -ENODEV;
yld = kzalloc(sizeof(struct yealink_dev), GFP_KERNEL);
if (!yld)
return -ENOMEM;
yld->udev = udev;
yld->intf = intf;
yld->idev = input_dev = input_allocate_device();
if (!input_dev)
return usb_cleanup(yld, -ENOMEM);
yld->irq_data = usb_alloc_coherent(udev, USB_PKT_LEN,
GFP_ATOMIC, &yld->irq_dma);
if (yld->irq_data == NULL)
return usb_cleanup(yld, -ENOMEM);
yld->ctl_data = usb_alloc_coherent(udev, USB_PKT_LEN,
GFP_ATOMIC, &yld->ctl_dma);
if (!yld->ctl_data)
return usb_cleanup(yld, -ENOMEM);
yld->ctl_req = kmalloc(sizeof(*(yld->ctl_req)), GFP_KERNEL);
if (yld->ctl_req == NULL)
return usb_cleanup(yld, -ENOMEM);
yld->urb_irq = usb_alloc_urb(0, GFP_KERNEL);
if (yld->urb_irq == NULL)
return usb_cleanup(yld, -ENOMEM);
yld->urb_ctl = usb_alloc_urb(0, GFP_KERNEL);
if (yld->urb_ctl == NULL)
return usb_cleanup(yld, -ENOMEM);
pipe = usb_rcvintpipe(udev, endpoint->bEndpointAddress);
ret = usb_maxpacket(udev, pipe, usb_pipeout(pipe));
if (ret != USB_PKT_LEN)
dev_err(&intf->dev, "invalid payload size %d, expected %zd\n",
ret, USB_PKT_LEN);
usb_fill_int_urb(yld->urb_irq, udev, pipe, yld->irq_data,
USB_PKT_LEN,
urb_irq_callback,
yld, endpoint->bInterval);
yld->urb_irq->transfer_dma = yld->irq_dma;
yld->urb_irq->transfer_flags |= URB_NO_TRANSFER_DMA_MAP;
yld->urb_irq->dev = udev;
yld->ctl_req->bRequestType = USB_TYPE_CLASS | USB_RECIP_INTERFACE |
USB_DIR_OUT;
yld->ctl_req->bRequest = USB_REQ_SET_CONFIGURATION;
yld->ctl_req->wValue = cpu_to_le16(0x200);
yld->ctl_req->wIndex = cpu_to_le16(interface->desc.bInterfaceNumber);
yld->ctl_req->wLength = cpu_to_le16(USB_PKT_LEN);
usb_fill_control_urb(yld->urb_ctl, udev, usb_sndctrlpipe(udev, 0),
(void *)yld->ctl_req, yld->ctl_data, USB_PKT_LEN,
urb_ctl_callback, yld);
yld->urb_ctl->transfer_dma = yld->ctl_dma;
yld->urb_ctl->transfer_flags |= URB_NO_TRANSFER_DMA_MAP;
yld->urb_ctl->dev = udev;
usb_make_path(udev, yld->phys, sizeof(yld->phys));
strlcat(yld->phys, "/input0", sizeof(yld->phys));
input_dev->name = nfo->name;
input_dev->phys = yld->phys;
usb_to_input_id(udev, &input_dev->id);
input_dev->dev.parent = &intf->dev;
input_set_drvdata(input_dev, yld);
input_dev->open = input_open;
input_dev->close = input_close;
input_dev->evbit[0] = BIT_MASK(EV_KEY);
for (i = 0; i < 256; i++) {
int k = map_p1k_to_key(i);
if (k >= 0) {
set_bit(k & 0xff, input_dev->keybit);
if (k >> 8)
set_bit(k >> 8, input_dev->keybit);
}
}
ret = input_register_device(yld->idev);
if (ret)
return usb_cleanup(yld, ret);
usb_set_intfdata(intf, yld);
for (i = 0; i < ARRAY_SIZE(lcdMap); i++)
setChar(yld, i, ' ');
store_line3(&intf->dev, NULL,
DRIVER_VERSION, sizeof(DRIVER_VERSION));
ret = sysfs_create_group(&intf->dev.kobj, &yld_attr_group);
return 0;
}
