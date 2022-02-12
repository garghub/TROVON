static inline u8 __get_latch(u16 port)
{
return inb(port) & 0xff;
}
static inline int __check_latch(u16 port, u8 val)
{
if (__get_latch(port) == val)
return 0;
return -EINVAL;
}
static int __wait_latch(u16 port, u8 val)
{
unsigned int i;
for (i = 0; i < 20; i++) {
if (!__check_latch(port, val))
return 0;
udelay(5);
}
return -EIO;
}
static void __device_refresh(void)
{
udelay(200);
if (inb(0x1604) != STATE_FRESH) {
outb(0x11, 0x1610);
outb(0x01, 0x161f);
}
}
static int __device_refresh_sync(void)
{
__device_refresh();
return __wait_latch(0x1604, STATE_FRESH);
}
static inline void __device_complete(void)
{
inb(0x161f);
inb(0x1604);
__device_refresh();
}
static int hdaps_readb_one(unsigned int port, u8 *val)
{
int ret;
mutex_lock(&hdaps_mtx);
ret = __device_refresh_sync();
if (ret)
goto out;
*val = inb(port);
__device_complete();
out:
mutex_unlock(&hdaps_mtx);
return ret;
}
static int __hdaps_read_pair(unsigned int port1, unsigned int port2,
int *x, int *y)
{
if (__device_refresh_sync())
return -EIO;
*y = inw(port2);
*x = inw(port1);
km_activity = inb(HDAPS_PORT_KMACT);
__device_complete();
if (hdaps_invert & HDAPS_X_AXIS)
*x = -*x;
if (hdaps_invert & HDAPS_Y_AXIS)
*y = -*y;
return 0;
}
static int hdaps_read_pair(unsigned int port1, unsigned int port2,
int *val1, int *val2)
{
int ret;
mutex_lock(&hdaps_mtx);
ret = __hdaps_read_pair(port1, port2, val1, val2);
mutex_unlock(&hdaps_mtx);
return ret;
}
static int hdaps_device_init(void)
{
int total, ret = -ENXIO;
mutex_lock(&hdaps_mtx);
outb(0x13, 0x1610);
outb(0x01, 0x161f);
if (__wait_latch(0x161f, 0x00))
goto out;
if (__check_latch(0x1611, 0x03) &&
__check_latch(0x1611, 0x02) &&
__check_latch(0x1611, 0x01))
goto out;
printk(KERN_DEBUG "hdaps: initial latch check good (0x%02x)\n",
__get_latch(0x1611));
outb(0x17, 0x1610);
outb(0x81, 0x1611);
outb(0x01, 0x161f);
if (__wait_latch(0x161f, 0x00))
goto out;
if (__wait_latch(0x1611, 0x00))
goto out;
if (__wait_latch(0x1612, 0x60))
goto out;
if (__wait_latch(0x1613, 0x00))
goto out;
outb(0x14, 0x1610);
outb(0x01, 0x1611);
outb(0x01, 0x161f);
if (__wait_latch(0x161f, 0x00))
goto out;
outb(0x10, 0x1610);
outb(0xc8, 0x1611);
outb(0x00, 0x1612);
outb(0x02, 0x1613);
outb(0x01, 0x161f);
if (__wait_latch(0x161f, 0x00))
goto out;
if (__device_refresh_sync())
goto out;
if (__wait_latch(0x1611, 0x00))
goto out;
for (total = INIT_TIMEOUT_MSECS; total > 0; total -= INIT_WAIT_MSECS) {
int x, y;
__hdaps_read_pair(HDAPS_PORT_XPOS, HDAPS_PORT_YPOS, &x, &y);
if (!__wait_latch(0x1611, 0x02)) {
ret = 0;
break;
}
msleep(INIT_WAIT_MSECS);
}
out:
mutex_unlock(&hdaps_mtx);
return ret;
}
static int hdaps_probe(struct platform_device *dev)
{
int ret;
ret = hdaps_device_init();
if (ret)
return ret;
pr_info("device successfully initialized\n");
return 0;
}
static int hdaps_resume(struct platform_device *dev)
{
return hdaps_device_init();
}
static void hdaps_calibrate(void)
{
__hdaps_read_pair(HDAPS_PORT_XPOS, HDAPS_PORT_YPOS, &rest_x, &rest_y);
}
static void hdaps_mousedev_poll(struct input_polled_dev *dev)
{
struct input_dev *input_dev = dev->input;
int x, y;
mutex_lock(&hdaps_mtx);
if (__hdaps_read_pair(HDAPS_PORT_XPOS, HDAPS_PORT_YPOS, &x, &y))
goto out;
input_report_abs(input_dev, ABS_X, x - rest_x);
input_report_abs(input_dev, ABS_Y, y - rest_y);
input_sync(input_dev);
out:
mutex_unlock(&hdaps_mtx);
}
static ssize_t hdaps_position_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
int ret, x, y;
ret = hdaps_read_pair(HDAPS_PORT_XPOS, HDAPS_PORT_YPOS, &x, &y);
if (ret)
return ret;
return sprintf(buf, "(%d,%d)\n", x, y);
}
static ssize_t hdaps_variance_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
int ret, x, y;
ret = hdaps_read_pair(HDAPS_PORT_XVAR, HDAPS_PORT_YVAR, &x, &y);
if (ret)
return ret;
return sprintf(buf, "(%d,%d)\n", x, y);
}
static ssize_t hdaps_temp1_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
u8 temp;
int ret;
ret = hdaps_readb_one(HDAPS_PORT_TEMP1, &temp);
if (ret < 0)
return ret;
return sprintf(buf, "%u\n", temp);
}
static ssize_t hdaps_temp2_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
u8 temp;
int ret;
ret = hdaps_readb_one(HDAPS_PORT_TEMP2, &temp);
if (ret < 0)
return ret;
return sprintf(buf, "%u\n", temp);
}
static ssize_t hdaps_keyboard_activity_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
return sprintf(buf, "%u\n", KEYBD_ISSET(km_activity));
}
static ssize_t hdaps_mouse_activity_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
return sprintf(buf, "%u\n", MOUSE_ISSET(km_activity));
}
static ssize_t hdaps_calibrate_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
return sprintf(buf, "(%d,%d)\n", rest_x, rest_y);
}
static ssize_t hdaps_calibrate_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
mutex_lock(&hdaps_mtx);
hdaps_calibrate();
mutex_unlock(&hdaps_mtx);
return count;
}
static ssize_t hdaps_invert_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
return sprintf(buf, "%u\n", hdaps_invert);
}
static ssize_t hdaps_invert_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
int invert;
if (sscanf(buf, "%d", &invert) != 1 ||
invert < 0 || invert > HDAPS_BOTH_AXES)
return -EINVAL;
hdaps_invert = invert;
hdaps_calibrate();
return count;
}
static int __init hdaps_dmi_match(const struct dmi_system_id *id)
{
pr_info("%s detected\n", id->ident);
return 1;
}
static int __init hdaps_dmi_match_invert(const struct dmi_system_id *id)
{
hdaps_invert = (unsigned long)id->driver_data;
pr_info("inverting axis (%u) readings\n", hdaps_invert);
return hdaps_dmi_match(id);
}
static int __init hdaps_init(void)
{
struct input_dev *idev;
int ret;
if (!dmi_check_system(hdaps_whitelist)) {
pr_warn("supported laptop not found!\n");
ret = -ENODEV;
goto out;
}
if (!request_region(HDAPS_LOW_PORT, HDAPS_NR_PORTS, "hdaps")) {
ret = -ENXIO;
goto out;
}
ret = platform_driver_register(&hdaps_driver);
if (ret)
goto out_region;
pdev = platform_device_register_simple("hdaps", -1, NULL, 0);
if (IS_ERR(pdev)) {
ret = PTR_ERR(pdev);
goto out_driver;
}
ret = sysfs_create_group(&pdev->dev.kobj, &hdaps_attribute_group);
if (ret)
goto out_device;
hdaps_idev = input_allocate_polled_device();
if (!hdaps_idev) {
ret = -ENOMEM;
goto out_group;
}
hdaps_idev->poll = hdaps_mousedev_poll;
hdaps_idev->poll_interval = HDAPS_POLL_INTERVAL;
hdaps_calibrate();
idev = hdaps_idev->input;
idev->name = "hdaps";
idev->phys = "isa1600/input0";
idev->id.bustype = BUS_ISA;
idev->dev.parent = &pdev->dev;
idev->evbit[0] = BIT_MASK(EV_ABS);
input_set_abs_params(idev, ABS_X,
-256, 256, HDAPS_INPUT_FUZZ, HDAPS_INPUT_FLAT);
input_set_abs_params(idev, ABS_Y,
-256, 256, HDAPS_INPUT_FUZZ, HDAPS_INPUT_FLAT);
ret = input_register_polled_device(hdaps_idev);
if (ret)
goto out_idev;
pr_info("driver successfully loaded\n");
return 0;
out_idev:
input_free_polled_device(hdaps_idev);
out_group:
sysfs_remove_group(&pdev->dev.kobj, &hdaps_attribute_group);
out_device:
platform_device_unregister(pdev);
out_driver:
platform_driver_unregister(&hdaps_driver);
out_region:
release_region(HDAPS_LOW_PORT, HDAPS_NR_PORTS);
out:
pr_warn("driver init failed (ret=%d)!\n", ret);
return ret;
}
static void __exit hdaps_exit(void)
{
input_unregister_polled_device(hdaps_idev);
input_free_polled_device(hdaps_idev);
sysfs_remove_group(&pdev->dev.kobj, &hdaps_attribute_group);
platform_device_unregister(pdev);
platform_driver_unregister(&hdaps_driver);
release_region(HDAPS_LOW_PORT, HDAPS_NR_PORTS);
pr_info("driver unloaded\n");
}
