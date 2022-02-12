static int cp2112_gpio_direction_input(struct gpio_chip *chip, unsigned offset)
{
struct cp2112_device *dev = container_of(chip, struct cp2112_device,
gc);
struct hid_device *hdev = dev->hdev;
u8 buf[5];
int ret;
ret = hid_hw_raw_request(hdev, CP2112_GPIO_CONFIG, buf,
sizeof(buf), HID_FEATURE_REPORT,
HID_REQ_GET_REPORT);
if (ret != sizeof(buf)) {
hid_err(hdev, "error requesting GPIO config: %d\n", ret);
return ret;
}
buf[1] &= ~(1 << offset);
buf[2] = gpio_push_pull;
ret = hid_hw_raw_request(hdev, CP2112_GPIO_CONFIG, buf, sizeof(buf),
HID_FEATURE_REPORT, HID_REQ_SET_REPORT);
if (ret < 0) {
hid_err(hdev, "error setting GPIO config: %d\n", ret);
return ret;
}
return 0;
}
static void cp2112_gpio_set(struct gpio_chip *chip, unsigned offset, int value)
{
struct cp2112_device *dev = container_of(chip, struct cp2112_device,
gc);
struct hid_device *hdev = dev->hdev;
u8 buf[3];
int ret;
buf[0] = CP2112_GPIO_SET;
buf[1] = value ? 0xff : 0;
buf[2] = 1 << offset;
ret = hid_hw_raw_request(hdev, CP2112_GPIO_SET, buf, sizeof(buf),
HID_FEATURE_REPORT, HID_REQ_SET_REPORT);
if (ret < 0)
hid_err(hdev, "error setting GPIO values: %d\n", ret);
}
static int cp2112_gpio_get(struct gpio_chip *chip, unsigned offset)
{
struct cp2112_device *dev = container_of(chip, struct cp2112_device,
gc);
struct hid_device *hdev = dev->hdev;
u8 buf[2];
int ret;
ret = hid_hw_raw_request(hdev, CP2112_GPIO_GET, buf, sizeof(buf),
HID_FEATURE_REPORT, HID_REQ_GET_REPORT);
if (ret != sizeof(buf)) {
hid_err(hdev, "error requesting GPIO values: %d\n", ret);
return ret;
}
return (buf[1] >> offset) & 1;
}
static int cp2112_gpio_direction_output(struct gpio_chip *chip,
unsigned offset, int value)
{
struct cp2112_device *dev = container_of(chip, struct cp2112_device,
gc);
struct hid_device *hdev = dev->hdev;
u8 buf[5];
int ret;
ret = hid_hw_raw_request(hdev, CP2112_GPIO_CONFIG, buf,
sizeof(buf), HID_FEATURE_REPORT,
HID_REQ_GET_REPORT);
if (ret != sizeof(buf)) {
hid_err(hdev, "error requesting GPIO config: %d\n", ret);
return ret;
}
buf[1] |= 1 << offset;
buf[2] = gpio_push_pull;
ret = hid_hw_raw_request(hdev, CP2112_GPIO_CONFIG, buf, sizeof(buf),
HID_FEATURE_REPORT, HID_REQ_SET_REPORT);
if (ret < 0) {
hid_err(hdev, "error setting GPIO config: %d\n", ret);
return ret;
}
cp2112_gpio_set(chip, offset, value);
return 0;
}
static int cp2112_hid_get(struct hid_device *hdev, unsigned char report_number,
u8 *data, size_t count, unsigned char report_type)
{
u8 *buf;
int ret;
buf = kmalloc(count, GFP_KERNEL);
if (!buf)
return -ENOMEM;
ret = hid_hw_raw_request(hdev, report_number, buf, count,
report_type, HID_REQ_GET_REPORT);
memcpy(data, buf, count);
kfree(buf);
return ret;
}
static int cp2112_hid_output(struct hid_device *hdev, u8 *data, size_t count,
unsigned char report_type)
{
u8 *buf;
int ret;
buf = kmemdup(data, count, GFP_KERNEL);
if (!buf)
return -ENOMEM;
if (report_type == HID_OUTPUT_REPORT)
ret = hid_hw_output_report(hdev, buf, count);
else
ret = hid_hw_raw_request(hdev, buf[0], buf, count, report_type,
HID_REQ_SET_REPORT);
kfree(buf);
return ret;
}
static int cp2112_wait(struct cp2112_device *dev, atomic_t *avail)
{
int ret = 0;
ret = wait_event_interruptible_timeout(dev->wait,
atomic_read(avail), msecs_to_jiffies(RESPONSE_TIMEOUT));
if (-ERESTARTSYS == ret)
return ret;
if (!ret)
return -ETIMEDOUT;
atomic_set(avail, 0);
return 0;
}
static int cp2112_xfer_status(struct cp2112_device *dev)
{
struct hid_device *hdev = dev->hdev;
u8 buf[2];
int ret;
buf[0] = CP2112_TRANSFER_STATUS_REQUEST;
buf[1] = 0x01;
atomic_set(&dev->xfer_avail, 0);
ret = cp2112_hid_output(hdev, buf, 2, HID_OUTPUT_REPORT);
if (ret < 0) {
hid_warn(hdev, "Error requesting status: %d\n", ret);
return ret;
}
ret = cp2112_wait(dev, &dev->xfer_avail);
if (ret)
return ret;
return dev->xfer_status;
}
static int cp2112_read(struct cp2112_device *dev, u8 *data, size_t size)
{
struct hid_device *hdev = dev->hdev;
struct cp2112_force_read_report report;
int ret;
report.report = CP2112_DATA_READ_FORCE_SEND;
report.length = cpu_to_be16(size);
atomic_set(&dev->read_avail, 0);
ret = cp2112_hid_output(hdev, &report.report, sizeof(report),
HID_OUTPUT_REPORT);
if (ret < 0) {
hid_warn(hdev, "Error requesting data: %d\n", ret);
return ret;
}
ret = cp2112_wait(dev, &dev->read_avail);
if (ret)
return ret;
hid_dbg(hdev, "read %d of %zd bytes requested\n",
dev->read_length, size);
if (size > dev->read_length)
size = dev->read_length;
memcpy(data, dev->read_data, size);
return dev->read_length;
}
static int cp2112_read_req(void *buf, u8 slave_address, u16 length)
{
struct cp2112_read_req_report *report = buf;
if (length < 1 || length > 512)
return -EINVAL;
report->report = CP2112_DATA_READ_REQUEST;
report->slave_address = slave_address << 1;
report->length = cpu_to_be16(length);
return sizeof(*report);
}
static int cp2112_write_read_req(void *buf, u8 slave_address, u16 length,
u8 command, u8 *data, u8 data_length)
{
struct cp2112_write_read_req_report *report = buf;
if (length < 1 || length > 512
|| data_length > sizeof(report->target_address) - 1)
return -EINVAL;
report->report = CP2112_DATA_WRITE_READ_REQUEST;
report->slave_address = slave_address << 1;
report->length = cpu_to_be16(length);
report->target_address_length = data_length + 1;
report->target_address[0] = command;
memcpy(&report->target_address[1], data, data_length);
return data_length + 6;
}
static int cp2112_write_req(void *buf, u8 slave_address, u8 command, u8 *data,
u8 data_length)
{
struct cp2112_write_req_report *report = buf;
if (data_length > sizeof(report->data) - 1)
return -EINVAL;
report->report = CP2112_DATA_WRITE_REQUEST;
report->slave_address = slave_address << 1;
report->length = data_length + 1;
report->data[0] = command;
memcpy(&report->data[1], data, data_length);
return data_length + 4;
}
static int cp2112_i2c_write_req(void *buf, u8 slave_address, u8 *data,
u8 data_length)
{
struct cp2112_write_req_report *report = buf;
if (data_length > sizeof(report->data))
return -EINVAL;
report->report = CP2112_DATA_WRITE_REQUEST;
report->slave_address = slave_address << 1;
report->length = data_length;
memcpy(report->data, data, data_length);
return data_length + 3;
}
static int cp2112_i2c_xfer(struct i2c_adapter *adap, struct i2c_msg *msgs,
int num)
{
struct cp2112_device *dev = (struct cp2112_device *)adap->algo_data;
struct hid_device *hdev = dev->hdev;
u8 buf[64];
ssize_t count;
unsigned int retries;
int ret;
hid_dbg(hdev, "I2C %d messages\n", num);
if (num != 1) {
hid_err(hdev,
"Multi-message I2C transactions not supported\n");
return -EOPNOTSUPP;
}
if (msgs->flags & I2C_M_RD)
count = cp2112_read_req(buf, msgs->addr, msgs->len);
else
count = cp2112_i2c_write_req(buf, msgs->addr, msgs->buf,
msgs->len);
if (count < 0)
return count;
ret = hid_hw_power(hdev, PM_HINT_FULLON);
if (ret < 0) {
hid_err(hdev, "power management error: %d\n", ret);
return ret;
}
ret = cp2112_hid_output(hdev, buf, count, HID_OUTPUT_REPORT);
if (ret < 0) {
hid_warn(hdev, "Error starting transaction: %d\n", ret);
goto power_normal;
}
for (retries = 0; retries < XFER_STATUS_RETRIES; ++retries) {
ret = cp2112_xfer_status(dev);
if (-EBUSY == ret)
continue;
if (ret < 0)
goto power_normal;
break;
}
if (XFER_STATUS_RETRIES <= retries) {
hid_warn(hdev, "Transfer timed out, cancelling.\n");
buf[0] = CP2112_CANCEL_TRANSFER;
buf[1] = 0x01;
ret = cp2112_hid_output(hdev, buf, 2, HID_OUTPUT_REPORT);
if (ret < 0)
hid_warn(hdev, "Error cancelling transaction: %d\n",
ret);
ret = -ETIMEDOUT;
goto power_normal;
}
if (!(msgs->flags & I2C_M_RD))
goto finish;
ret = cp2112_read(dev, msgs->buf, msgs->len);
if (ret < 0)
goto power_normal;
if (ret != msgs->len) {
hid_warn(hdev, "short read: %d < %d\n", ret, msgs->len);
ret = -EIO;
goto power_normal;
}
finish:
ret = 1;
power_normal:
hid_hw_power(hdev, PM_HINT_NORMAL);
hid_dbg(hdev, "I2C transfer finished: %d\n", ret);
return ret;
}
static int cp2112_xfer(struct i2c_adapter *adap, u16 addr,
unsigned short flags, char read_write, u8 command,
int size, union i2c_smbus_data *data)
{
struct cp2112_device *dev = (struct cp2112_device *)adap->algo_data;
struct hid_device *hdev = dev->hdev;
u8 buf[64];
__be16 word;
ssize_t count;
size_t read_length = 0;
unsigned int retries;
int ret;
hid_dbg(hdev, "%s addr 0x%x flags 0x%x cmd 0x%x size %d\n",
read_write == I2C_SMBUS_WRITE ? "write" : "read",
addr, flags, command, size);
switch (size) {
case I2C_SMBUS_BYTE:
read_length = 1;
if (I2C_SMBUS_READ == read_write)
count = cp2112_read_req(buf, addr, read_length);
else
count = cp2112_write_req(buf, addr, data->byte, NULL,
0);
break;
case I2C_SMBUS_BYTE_DATA:
read_length = 1;
if (I2C_SMBUS_READ == read_write)
count = cp2112_write_read_req(buf, addr, read_length,
command, NULL, 0);
else
count = cp2112_write_req(buf, addr, command,
&data->byte, 1);
break;
case I2C_SMBUS_WORD_DATA:
read_length = 2;
word = cpu_to_be16(data->word);
if (I2C_SMBUS_READ == read_write)
count = cp2112_write_read_req(buf, addr, read_length,
command, NULL, 0);
else
count = cp2112_write_req(buf, addr, command,
(u8 *)&word, 2);
break;
case I2C_SMBUS_PROC_CALL:
size = I2C_SMBUS_WORD_DATA;
read_write = I2C_SMBUS_READ;
read_length = 2;
word = cpu_to_be16(data->word);
count = cp2112_write_read_req(buf, addr, read_length, command,
(u8 *)&word, 2);
break;
case I2C_SMBUS_I2C_BLOCK_DATA:
size = I2C_SMBUS_BLOCK_DATA;
case I2C_SMBUS_BLOCK_DATA:
if (I2C_SMBUS_READ == read_write) {
count = cp2112_write_read_req(buf, addr,
I2C_SMBUS_BLOCK_MAX,
command, NULL, 0);
} else {
count = cp2112_write_req(buf, addr, command,
data->block,
data->block[0] + 1);
}
break;
case I2C_SMBUS_BLOCK_PROC_CALL:
size = I2C_SMBUS_BLOCK_DATA;
read_write = I2C_SMBUS_READ;
count = cp2112_write_read_req(buf, addr, I2C_SMBUS_BLOCK_MAX,
command, data->block,
data->block[0] + 1);
break;
default:
hid_warn(hdev, "Unsupported transaction %d\n", size);
return -EOPNOTSUPP;
}
if (count < 0)
return count;
ret = hid_hw_power(hdev, PM_HINT_FULLON);
if (ret < 0) {
hid_err(hdev, "power management error: %d\n", ret);
return ret;
}
ret = cp2112_hid_output(hdev, buf, count, HID_OUTPUT_REPORT);
if (ret < 0) {
hid_warn(hdev, "Error starting transaction: %d\n", ret);
goto power_normal;
}
for (retries = 0; retries < XFER_STATUS_RETRIES; ++retries) {
ret = cp2112_xfer_status(dev);
if (-EBUSY == ret)
continue;
if (ret < 0)
goto power_normal;
break;
}
if (XFER_STATUS_RETRIES <= retries) {
hid_warn(hdev, "Transfer timed out, cancelling.\n");
buf[0] = CP2112_CANCEL_TRANSFER;
buf[1] = 0x01;
ret = cp2112_hid_output(hdev, buf, 2, HID_OUTPUT_REPORT);
if (ret < 0)
hid_warn(hdev, "Error cancelling transaction: %d\n",
ret);
ret = -ETIMEDOUT;
goto power_normal;
}
if (I2C_SMBUS_WRITE == read_write) {
ret = 0;
goto power_normal;
}
if (I2C_SMBUS_BLOCK_DATA == size)
read_length = ret;
ret = cp2112_read(dev, buf, read_length);
if (ret < 0)
goto power_normal;
if (ret != read_length) {
hid_warn(hdev, "short read: %d < %zd\n", ret, read_length);
ret = -EIO;
goto power_normal;
}
switch (size) {
case I2C_SMBUS_BYTE:
case I2C_SMBUS_BYTE_DATA:
data->byte = buf[0];
break;
case I2C_SMBUS_WORD_DATA:
data->word = be16_to_cpup((__be16 *)buf);
break;
case I2C_SMBUS_BLOCK_DATA:
if (read_length > I2C_SMBUS_BLOCK_MAX) {
ret = -EPROTO;
goto power_normal;
}
memcpy(data->block, buf, read_length);
break;
}
ret = 0;
power_normal:
hid_hw_power(hdev, PM_HINT_NORMAL);
hid_dbg(hdev, "transfer finished: %d\n", ret);
return ret;
}
static u32 cp2112_functionality(struct i2c_adapter *adap)
{
return I2C_FUNC_I2C |
I2C_FUNC_SMBUS_BYTE |
I2C_FUNC_SMBUS_BYTE_DATA |
I2C_FUNC_SMBUS_WORD_DATA |
I2C_FUNC_SMBUS_BLOCK_DATA |
I2C_FUNC_SMBUS_I2C_BLOCK |
I2C_FUNC_SMBUS_PROC_CALL |
I2C_FUNC_SMBUS_BLOCK_PROC_CALL;
}
static int cp2112_get_usb_config(struct hid_device *hdev,
struct cp2112_usb_config_report *cfg)
{
int ret;
ret = cp2112_hid_get(hdev, CP2112_USB_CONFIG, (u8 *)cfg, sizeof(*cfg),
HID_FEATURE_REPORT);
if (ret != sizeof(*cfg)) {
hid_err(hdev, "error reading usb config: %d\n", ret);
if (ret < 0)
return ret;
return -EIO;
}
return 0;
}
static int cp2112_set_usb_config(struct hid_device *hdev,
struct cp2112_usb_config_report *cfg)
{
int ret;
BUG_ON(cfg->report != CP2112_USB_CONFIG);
ret = cp2112_hid_output(hdev, (u8 *)cfg, sizeof(*cfg),
HID_FEATURE_REPORT);
if (ret != sizeof(*cfg)) {
hid_err(hdev, "error writing usb config: %d\n", ret);
if (ret < 0)
return ret;
return -EIO;
}
return 0;
}
static ssize_t pstr_store(struct device *kdev,
struct device_attribute *kattr, const char *buf,
size_t count)
{
struct hid_device *hdev = container_of(kdev, struct hid_device, dev);
struct cp2112_pstring_attribute *attr =
container_of(kattr, struct cp2112_pstring_attribute, attr);
struct cp2112_string_report report;
int ret;
memset(&report, 0, sizeof(report));
ret = utf8s_to_utf16s(buf, count, UTF16_LITTLE_ENDIAN,
report.string, ARRAY_SIZE(report.string));
report.report = attr->report;
report.length = ret * sizeof(report.string[0]) + 2;
report.type = USB_DT_STRING;
ret = cp2112_hid_output(hdev, &report.report, report.length + 1,
HID_FEATURE_REPORT);
if (ret != report.length + 1) {
hid_err(hdev, "error writing %s string: %d\n", kattr->attr.name,
ret);
if (ret < 0)
return ret;
return -EIO;
}
chmod_sysfs_attrs(hdev);
return count;
}
static ssize_t pstr_show(struct device *kdev,
struct device_attribute *kattr, char *buf)
{
struct hid_device *hdev = container_of(kdev, struct hid_device, dev);
struct cp2112_pstring_attribute *attr =
container_of(kattr, struct cp2112_pstring_attribute, attr);
struct cp2112_string_report report;
u8 length;
int ret;
ret = cp2112_hid_get(hdev, attr->report, &report.report,
sizeof(report) - 1, HID_FEATURE_REPORT);
if (ret < 3) {
hid_err(hdev, "error reading %s string: %d\n", kattr->attr.name,
ret);
if (ret < 0)
return ret;
return -EIO;
}
if (report.length < 2) {
hid_err(hdev, "invalid %s string length: %d\n",
kattr->attr.name, report.length);
return -EIO;
}
length = report.length > ret - 1 ? ret - 1 : report.length;
length = (length - 2) / sizeof(report.string[0]);
ret = utf16s_to_utf8s(report.string, length, UTF16_LITTLE_ENDIAN, buf,
PAGE_SIZE - 1);
buf[ret++] = '\n';
return ret;
}
static void chmod_sysfs_attrs(struct hid_device *hdev)
{
struct attribute **attr;
u8 buf[2];
int ret;
ret = cp2112_hid_get(hdev, CP2112_LOCK_BYTE, buf, sizeof(buf),
HID_FEATURE_REPORT);
if (ret != sizeof(buf)) {
hid_err(hdev, "error reading lock byte: %d\n", ret);
return;
}
for (attr = cp2112_attr_group.attrs; *attr; ++attr) {
umode_t mode = (buf[1] & 1) ? S_IWUSR | S_IRUGO : S_IRUGO;
ret = sysfs_chmod_file(&hdev->dev.kobj, *attr, mode);
if (ret < 0)
hid_err(hdev, "error chmoding sysfs file %s\n",
(*attr)->name);
buf[1] >>= 1;
}
}
static int cp2112_probe(struct hid_device *hdev, const struct hid_device_id *id)
{
struct cp2112_device *dev;
u8 buf[3];
struct cp2112_smbus_config_report config;
int ret;
ret = hid_parse(hdev);
if (ret) {
hid_err(hdev, "parse failed\n");
return ret;
}
ret = hid_hw_start(hdev, HID_CONNECT_HIDRAW);
if (ret) {
hid_err(hdev, "hw start failed\n");
return ret;
}
ret = hid_hw_open(hdev);
if (ret) {
hid_err(hdev, "hw open failed\n");
goto err_hid_stop;
}
ret = hid_hw_power(hdev, PM_HINT_FULLON);
if (ret < 0) {
hid_err(hdev, "power management error: %d\n", ret);
goto err_hid_close;
}
ret = cp2112_hid_get(hdev, CP2112_GET_VERSION_INFO, buf, sizeof(buf),
HID_FEATURE_REPORT);
if (ret != sizeof(buf)) {
hid_err(hdev, "error requesting version\n");
if (ret >= 0)
ret = -EIO;
goto err_power_normal;
}
hid_info(hdev, "Part Number: 0x%02X Device Version: 0x%02X\n",
buf[1], buf[2]);
ret = cp2112_hid_get(hdev, CP2112_SMBUS_CONFIG, (u8 *)&config,
sizeof(config), HID_FEATURE_REPORT);
if (ret != sizeof(config)) {
hid_err(hdev, "error requesting SMBus config\n");
if (ret >= 0)
ret = -EIO;
goto err_power_normal;
}
config.retry_time = cpu_to_be16(1);
ret = cp2112_hid_output(hdev, (u8 *)&config, sizeof(config),
HID_FEATURE_REPORT);
if (ret != sizeof(config)) {
hid_err(hdev, "error setting SMBus config\n");
if (ret >= 0)
ret = -EIO;
goto err_power_normal;
}
dev = kzalloc(sizeof(*dev), GFP_KERNEL);
if (!dev) {
ret = -ENOMEM;
goto err_power_normal;
}
hid_set_drvdata(hdev, (void *)dev);
dev->hdev = hdev;
dev->adap.owner = THIS_MODULE;
dev->adap.class = I2C_CLASS_HWMON;
dev->adap.algo = &smbus_algorithm;
dev->adap.algo_data = dev;
dev->adap.dev.parent = &hdev->dev;
snprintf(dev->adap.name, sizeof(dev->adap.name),
"CP2112 SMBus Bridge on hiddev%d", hdev->minor);
init_waitqueue_head(&dev->wait);
hid_device_io_start(hdev);
ret = i2c_add_adapter(&dev->adap);
hid_device_io_stop(hdev);
if (ret) {
hid_err(hdev, "error registering i2c adapter\n");
goto err_free_dev;
}
hid_dbg(hdev, "adapter registered\n");
dev->gc.label = "cp2112_gpio";
dev->gc.direction_input = cp2112_gpio_direction_input;
dev->gc.direction_output = cp2112_gpio_direction_output;
dev->gc.set = cp2112_gpio_set;
dev->gc.get = cp2112_gpio_get;
dev->gc.base = -1;
dev->gc.ngpio = 8;
dev->gc.can_sleep = 1;
dev->gc.dev = &hdev->dev;
ret = gpiochip_add(&dev->gc);
if (ret < 0) {
hid_err(hdev, "error registering gpio chip\n");
goto err_free_i2c;
}
ret = sysfs_create_group(&hdev->dev.kobj, &cp2112_attr_group);
if (ret < 0) {
hid_err(hdev, "error creating sysfs attrs\n");
goto err_gpiochip_remove;
}
chmod_sysfs_attrs(hdev);
hid_hw_power(hdev, PM_HINT_NORMAL);
return ret;
err_gpiochip_remove:
if (gpiochip_remove(&dev->gc) < 0)
hid_err(hdev, "error removing gpio chip\n");
err_free_i2c:
i2c_del_adapter(&dev->adap);
err_free_dev:
kfree(dev);
err_power_normal:
hid_hw_power(hdev, PM_HINT_NORMAL);
err_hid_close:
hid_hw_close(hdev);
err_hid_stop:
hid_hw_stop(hdev);
return ret;
}
static void cp2112_remove(struct hid_device *hdev)
{
struct cp2112_device *dev = hid_get_drvdata(hdev);
sysfs_remove_group(&hdev->dev.kobj, &cp2112_attr_group);
if (gpiochip_remove(&dev->gc))
hid_err(hdev, "unable to remove gpio chip\n");
i2c_del_adapter(&dev->adap);
hid_hw_close(hdev);
hid_hw_stop(hdev);
kfree(dev);
}
static int cp2112_raw_event(struct hid_device *hdev, struct hid_report *report,
u8 *data, int size)
{
struct cp2112_device *dev = hid_get_drvdata(hdev);
struct cp2112_xfer_status_report *xfer = (void *)data;
switch (data[0]) {
case CP2112_TRANSFER_STATUS_RESPONSE:
hid_dbg(hdev, "xfer status: %02x %02x %04x %04x\n",
xfer->status0, xfer->status1,
be16_to_cpu(xfer->retries), be16_to_cpu(xfer->length));
switch (xfer->status0) {
case STATUS0_IDLE:
dev->xfer_status = -EAGAIN;
break;
case STATUS0_BUSY:
dev->xfer_status = -EBUSY;
break;
case STATUS0_COMPLETE:
dev->xfer_status = be16_to_cpu(xfer->length);
break;
case STATUS0_ERROR:
switch (xfer->status1) {
case STATUS1_TIMEOUT_NACK:
case STATUS1_TIMEOUT_BUS:
dev->xfer_status = -ETIMEDOUT;
break;
default:
dev->xfer_status = -EIO;
break;
}
break;
default:
dev->xfer_status = -EINVAL;
break;
}
atomic_set(&dev->xfer_avail, 1);
break;
case CP2112_DATA_READ_RESPONSE:
hid_dbg(hdev, "read response: %02x %02x\n", data[1], data[2]);
dev->read_length = data[2];
if (dev->read_length > sizeof(dev->read_data))
dev->read_length = sizeof(dev->read_data);
memcpy(dev->read_data, &data[3], dev->read_length);
atomic_set(&dev->read_avail, 1);
break;
default:
hid_err(hdev, "unknown report\n");
return 0;
}
wake_up_interruptible(&dev->wait);
return 1;
}
