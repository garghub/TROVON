static int edt_ft5x06_ts_readwrite(struct i2c_client *client,
u16 wr_len, u8 *wr_buf,
u16 rd_len, u8 *rd_buf)
{
struct i2c_msg wrmsg[2];
int i = 0;
int ret;
if (wr_len) {
wrmsg[i].addr = client->addr;
wrmsg[i].flags = 0;
wrmsg[i].len = wr_len;
wrmsg[i].buf = wr_buf;
i++;
}
if (rd_len) {
wrmsg[i].addr = client->addr;
wrmsg[i].flags = I2C_M_RD;
wrmsg[i].len = rd_len;
wrmsg[i].buf = rd_buf;
i++;
}
ret = i2c_transfer(client->adapter, wrmsg, i);
if (ret < 0)
return ret;
if (ret != i)
return -EIO;
return 0;
}
static bool edt_ft5x06_ts_check_crc(struct edt_ft5x06_ts_data *tsdata,
u8 *buf, int buflen)
{
int i;
u8 crc = 0;
for (i = 0; i < buflen - 1; i++)
crc ^= buf[i];
if (crc != buf[buflen-1]) {
dev_err_ratelimited(&tsdata->client->dev,
"crc error: 0x%02x expected, got 0x%02x\n",
crc, buf[buflen-1]);
return false;
}
return true;
}
static irqreturn_t edt_ft5x06_ts_isr(int irq, void *dev_id)
{
struct edt_ft5x06_ts_data *tsdata = dev_id;
struct device *dev = &tsdata->client->dev;
u8 cmd = 0xf9;
u8 rdbuf[26];
int i, type, x, y, id;
int error;
memset(rdbuf, 0, sizeof(rdbuf));
error = edt_ft5x06_ts_readwrite(tsdata->client,
sizeof(cmd), &cmd,
sizeof(rdbuf), rdbuf);
if (error) {
dev_err_ratelimited(dev, "Unable to fetch data, error: %d\n",
error);
goto out;
}
if (rdbuf[0] != 0xaa || rdbuf[1] != 0xaa || rdbuf[2] != 26) {
dev_err_ratelimited(dev, "Unexpected header: %02x%02x%02x!\n",
rdbuf[0], rdbuf[1], rdbuf[2]);
goto out;
}
if (!edt_ft5x06_ts_check_crc(tsdata, rdbuf, 26))
goto out;
for (i = 0; i < MAX_SUPPORT_POINTS; i++) {
u8 *buf = &rdbuf[i * 4 + 5];
bool down;
type = buf[0] >> 6;
if (type == TOUCH_EVENT_RESERVED)
continue;
x = ((buf[0] << 8) | buf[1]) & 0x0fff;
y = ((buf[2] << 8) | buf[3]) & 0x0fff;
id = (buf[2] >> 4) & 0x0f;
down = (type != TOUCH_EVENT_UP);
input_mt_slot(tsdata->input, id);
input_mt_report_slot_state(tsdata->input, MT_TOOL_FINGER, down);
if (!down)
continue;
input_report_abs(tsdata->input, ABS_MT_POSITION_X, x);
input_report_abs(tsdata->input, ABS_MT_POSITION_Y, y);
}
input_mt_report_pointer_emulation(tsdata->input, true);
input_sync(tsdata->input);
out:
return IRQ_HANDLED;
}
static int edt_ft5x06_register_write(struct edt_ft5x06_ts_data *tsdata,
u8 addr, u8 value)
{
u8 wrbuf[4];
wrbuf[0] = tsdata->factory_mode ? 0xf3 : 0xfc;
wrbuf[1] = tsdata->factory_mode ? addr & 0x7f : addr & 0x3f;
wrbuf[2] = value;
wrbuf[3] = wrbuf[0] ^ wrbuf[1] ^ wrbuf[2];
return edt_ft5x06_ts_readwrite(tsdata->client, 4, wrbuf, 0, NULL);
}
static int edt_ft5x06_register_read(struct edt_ft5x06_ts_data *tsdata,
u8 addr)
{
u8 wrbuf[2], rdbuf[2];
int error;
wrbuf[0] = tsdata->factory_mode ? 0xf3 : 0xfc;
wrbuf[1] = tsdata->factory_mode ? addr & 0x7f : addr & 0x3f;
wrbuf[1] |= tsdata->factory_mode ? 0x80 : 0x40;
error = edt_ft5x06_ts_readwrite(tsdata->client, 2, wrbuf, 2, rdbuf);
if (error)
return error;
if ((wrbuf[0] ^ wrbuf[1] ^ rdbuf[0]) != rdbuf[1]) {
dev_err(&tsdata->client->dev,
"crc error: 0x%02x expected, got 0x%02x\n",
wrbuf[0] ^ wrbuf[1] ^ rdbuf[0], rdbuf[1]);
return -EIO;
}
return rdbuf[0];
}
static ssize_t edt_ft5x06_setting_show(struct device *dev,
struct device_attribute *dattr,
char *buf)
{
struct i2c_client *client = to_i2c_client(dev);
struct edt_ft5x06_ts_data *tsdata = i2c_get_clientdata(client);
struct edt_ft5x06_attribute *attr =
container_of(dattr, struct edt_ft5x06_attribute, dattr);
u8 *field = (u8 *)((char *)tsdata + attr->field_offset);
int val;
size_t count = 0;
int error = 0;
mutex_lock(&tsdata->mutex);
if (tsdata->factory_mode) {
error = -EIO;
goto out;
}
val = edt_ft5x06_register_read(tsdata, attr->addr);
if (val < 0) {
error = val;
dev_err(&tsdata->client->dev,
"Failed to fetch attribute %s, error %d\n",
dattr->attr.name, error);
goto out;
}
if (val != *field) {
dev_warn(&tsdata->client->dev,
"%s: read (%d) and stored value (%d) differ\n",
dattr->attr.name, val, *field);
*field = val;
}
count = scnprintf(buf, PAGE_SIZE, "%d\n", val);
out:
mutex_unlock(&tsdata->mutex);
return error ?: count;
}
static ssize_t edt_ft5x06_setting_store(struct device *dev,
struct device_attribute *dattr,
const char *buf, size_t count)
{
struct i2c_client *client = to_i2c_client(dev);
struct edt_ft5x06_ts_data *tsdata = i2c_get_clientdata(client);
struct edt_ft5x06_attribute *attr =
container_of(dattr, struct edt_ft5x06_attribute, dattr);
u8 *field = (u8 *)((char *)tsdata + attr->field_offset);
unsigned int val;
int error;
mutex_lock(&tsdata->mutex);
if (tsdata->factory_mode) {
error = -EIO;
goto out;
}
error = kstrtouint(buf, 0, &val);
if (error)
goto out;
if (val < attr->limit_low || val > attr->limit_high) {
error = -ERANGE;
goto out;
}
error = edt_ft5x06_register_write(tsdata, attr->addr, val);
if (error) {
dev_err(&tsdata->client->dev,
"Failed to update attribute %s, error: %d\n",
dattr->attr.name, error);
goto out;
}
*field = val;
out:
mutex_unlock(&tsdata->mutex);
return error ?: count;
}
static int edt_ft5x06_factory_mode(struct edt_ft5x06_ts_data *tsdata)
{
struct i2c_client *client = tsdata->client;
int retries = EDT_SWITCH_MODE_RETRIES;
int ret;
int error;
disable_irq(client->irq);
if (!tsdata->raw_buffer) {
tsdata->raw_bufsize = tsdata->num_x * tsdata->num_y *
sizeof(u16);
tsdata->raw_buffer = kzalloc(tsdata->raw_bufsize, GFP_KERNEL);
if (!tsdata->raw_buffer) {
error = -ENOMEM;
goto err_out;
}
}
error = edt_ft5x06_register_write(tsdata, WORK_REGISTER_OPMODE, 0x03);
if (error) {
dev_err(&client->dev,
"failed to switch to factory mode, error %d\n", error);
goto err_out;
}
tsdata->factory_mode = true;
do {
mdelay(EDT_SWITCH_MODE_DELAY);
ret = edt_ft5x06_register_read(tsdata, FACTORY_REGISTER_OPMODE);
if (ret == 0x03)
break;
} while (--retries > 0);
if (retries == 0) {
dev_err(&client->dev, "not in factory mode after %dms.\n",
EDT_SWITCH_MODE_RETRIES * EDT_SWITCH_MODE_DELAY);
error = -EIO;
goto err_out;
}
return 0;
err_out:
kfree(tsdata->raw_buffer);
tsdata->raw_buffer = NULL;
tsdata->factory_mode = false;
enable_irq(client->irq);
return error;
}
static int edt_ft5x06_work_mode(struct edt_ft5x06_ts_data *tsdata)
{
struct i2c_client *client = tsdata->client;
int retries = EDT_SWITCH_MODE_RETRIES;
int ret;
int error;
error = edt_ft5x06_register_write(tsdata, FACTORY_REGISTER_OPMODE, 0x1);
if (error) {
dev_err(&client->dev,
"failed to switch to work mode, error: %d\n", error);
return error;
}
tsdata->factory_mode = false;
do {
mdelay(EDT_SWITCH_MODE_DELAY);
ret = edt_ft5x06_register_read(tsdata, WORK_REGISTER_OPMODE);
if (ret == 0x01)
break;
} while (--retries > 0);
if (retries == 0) {
dev_err(&client->dev, "not in work mode after %dms.\n",
EDT_SWITCH_MODE_RETRIES * EDT_SWITCH_MODE_DELAY);
tsdata->factory_mode = true;
return -EIO;
}
if (tsdata->raw_buffer)
kfree(tsdata->raw_buffer);
tsdata->raw_buffer = NULL;
edt_ft5x06_register_write(tsdata, WORK_REGISTER_THRESHOLD,
tsdata->threshold);
edt_ft5x06_register_write(tsdata, WORK_REGISTER_GAIN,
tsdata->gain);
edt_ft5x06_register_write(tsdata, WORK_REGISTER_OFFSET,
tsdata->offset);
edt_ft5x06_register_write(tsdata, WORK_REGISTER_REPORT_RATE,
tsdata->report_rate);
enable_irq(client->irq);
return 0;
}
static int edt_ft5x06_debugfs_mode_get(void *data, u64 *mode)
{
struct edt_ft5x06_ts_data *tsdata = data;
*mode = tsdata->factory_mode;
return 0;
}
static int edt_ft5x06_debugfs_mode_set(void *data, u64 mode)
{
struct edt_ft5x06_ts_data *tsdata = data;
int retval = 0;
if (mode > 1)
return -ERANGE;
mutex_lock(&tsdata->mutex);
if (mode != tsdata->factory_mode) {
retval = mode ? edt_ft5x06_factory_mode(tsdata) :
edt_ft5x06_work_mode(tsdata);
}
mutex_unlock(&tsdata->mutex);
return retval;
}
static ssize_t edt_ft5x06_debugfs_raw_data_read(struct file *file,
char __user *buf, size_t count, loff_t *off)
{
struct edt_ft5x06_ts_data *tsdata = file->private_data;
struct i2c_client *client = tsdata->client;
int retries = EDT_RAW_DATA_RETRIES;
int val, i, error;
size_t read = 0;
int colbytes;
char wrbuf[3];
u8 *rdbuf;
if (*off < 0 || *off >= tsdata->raw_bufsize)
return 0;
mutex_lock(&tsdata->mutex);
if (!tsdata->factory_mode || !tsdata->raw_buffer) {
error = -EIO;
goto out;
}
error = edt_ft5x06_register_write(tsdata, 0x08, 0x01);
if (error) {
dev_dbg(&client->dev,
"failed to write 0x08 register, error %d\n", error);
goto out;
}
do {
msleep(EDT_RAW_DATA_DELAY);
val = edt_ft5x06_register_read(tsdata, 0x08);
if (val < 1)
break;
} while (--retries > 0);
if (val < 0) {
error = val;
dev_dbg(&client->dev,
"failed to read 0x08 register, error %d\n", error);
goto out;
}
if (retries == 0) {
dev_dbg(&client->dev,
"timed out waiting for register to settle\n");
error = -ETIMEDOUT;
goto out;
}
rdbuf = tsdata->raw_buffer;
colbytes = tsdata->num_y * sizeof(u16);
wrbuf[0] = 0xf5;
wrbuf[1] = 0x0e;
for (i = 0; i < tsdata->num_x; i++) {
wrbuf[2] = i;
error = edt_ft5x06_ts_readwrite(tsdata->client,
sizeof(wrbuf), wrbuf,
colbytes, rdbuf);
if (error)
goto out;
rdbuf += colbytes;
}
read = min_t(size_t, count, tsdata->raw_bufsize - *off);
if (copy_to_user(buf, tsdata->raw_buffer + *off, read)) {
error = -EFAULT;
goto out;
}
*off += read;
out:
mutex_unlock(&tsdata->mutex);
return error ?: read;
}
static void
edt_ft5x06_ts_prepare_debugfs(struct edt_ft5x06_ts_data *tsdata,
const char *debugfs_name)
{
tsdata->debug_dir = debugfs_create_dir(debugfs_name, NULL);
if (!tsdata->debug_dir)
return;
debugfs_create_u16("num_x", S_IRUSR, tsdata->debug_dir, &tsdata->num_x);
debugfs_create_u16("num_y", S_IRUSR, tsdata->debug_dir, &tsdata->num_y);
debugfs_create_file("mode", S_IRUSR | S_IWUSR,
tsdata->debug_dir, tsdata, &debugfs_mode_fops);
debugfs_create_file("raw_data", S_IRUSR,
tsdata->debug_dir, tsdata, &debugfs_raw_data_fops);
}
static void
edt_ft5x06_ts_teardown_debugfs(struct edt_ft5x06_ts_data *tsdata)
{
if (tsdata->debug_dir)
debugfs_remove_recursive(tsdata->debug_dir);
kfree(tsdata->raw_buffer);
}
static inline void
edt_ft5x06_ts_prepare_debugfs(struct edt_ft5x06_ts_data *tsdata,
const char *debugfs_name)
{
}
static inline void
edt_ft5x06_ts_teardown_debugfs(struct edt_ft5x06_ts_data *tsdata)
{
}
static int edt_ft5x06_ts_reset(struct i2c_client *client,
int reset_pin)
{
int error;
if (gpio_is_valid(reset_pin)) {
error = gpio_request_one(reset_pin, GPIOF_OUT_INIT_LOW,
"edt-ft5x06 reset");
if (error) {
dev_err(&client->dev,
"Failed to request GPIO %d as reset pin, error %d\n",
reset_pin, error);
return error;
}
mdelay(50);
gpio_set_value(reset_pin, 1);
mdelay(100);
}
return 0;
}
static int edt_ft5x06_ts_identify(struct i2c_client *client,
char *model_name,
char *fw_version)
{
u8 rdbuf[EDT_NAME_LEN];
char *p;
int error;
error = edt_ft5x06_ts_readwrite(client, 1, "\xbb",
EDT_NAME_LEN - 1, rdbuf);
if (error)
return error;
rdbuf[EDT_NAME_LEN - 1] = '\0';
if (rdbuf[EDT_NAME_LEN - 2] == '$')
rdbuf[EDT_NAME_LEN - 2] = '\0';
p = strchr(rdbuf, '*');
if (p)
*p++ = '\0';
strlcpy(model_name, rdbuf + 1, EDT_NAME_LEN);
strlcpy(fw_version, p ? p : "", EDT_NAME_LEN);
return 0;
}
static void
edt_ft5x06_ts_get_defaults(struct edt_ft5x06_ts_data *tsdata,
const struct edt_ft5x06_platform_data *pdata)
{
if (!pdata->use_parameters)
return;
EDT_ATTR_CHECKSET(threshold, WORK_REGISTER_THRESHOLD);
EDT_ATTR_CHECKSET(gain, WORK_REGISTER_GAIN);
EDT_ATTR_CHECKSET(offset, WORK_REGISTER_OFFSET);
EDT_ATTR_CHECKSET(report_rate, WORK_REGISTER_REPORT_RATE);
}
static void
edt_ft5x06_ts_get_parameters(struct edt_ft5x06_ts_data *tsdata)
{
tsdata->threshold = edt_ft5x06_register_read(tsdata,
WORK_REGISTER_THRESHOLD);
tsdata->gain = edt_ft5x06_register_read(tsdata, WORK_REGISTER_GAIN);
tsdata->offset = edt_ft5x06_register_read(tsdata, WORK_REGISTER_OFFSET);
tsdata->report_rate = edt_ft5x06_register_read(tsdata,
WORK_REGISTER_REPORT_RATE);
tsdata->num_x = edt_ft5x06_register_read(tsdata, WORK_REGISTER_NUM_X);
tsdata->num_y = edt_ft5x06_register_read(tsdata, WORK_REGISTER_NUM_Y);
}
static int edt_ft5x06_ts_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
const struct edt_ft5x06_platform_data *pdata =
client->dev.platform_data;
struct edt_ft5x06_ts_data *tsdata;
struct input_dev *input;
int error;
char fw_version[EDT_NAME_LEN];
dev_dbg(&client->dev, "probing for EDT FT5x06 I2C\n");
if (!pdata) {
dev_err(&client->dev, "no platform data?\n");
return -EINVAL;
}
error = edt_ft5x06_ts_reset(client, pdata->reset_pin);
if (error)
return error;
if (gpio_is_valid(pdata->irq_pin)) {
error = gpio_request_one(pdata->irq_pin,
GPIOF_IN, "edt-ft5x06 irq");
if (error) {
dev_err(&client->dev,
"Failed to request GPIO %d, error %d\n",
pdata->irq_pin, error);
return error;
}
}
tsdata = kzalloc(sizeof(*tsdata), GFP_KERNEL);
input = input_allocate_device();
if (!tsdata || !input) {
dev_err(&client->dev, "failed to allocate driver data.\n");
error = -ENOMEM;
goto err_free_mem;
}
mutex_init(&tsdata->mutex);
tsdata->client = client;
tsdata->input = input;
tsdata->factory_mode = false;
error = edt_ft5x06_ts_identify(client, tsdata->name, fw_version);
if (error) {
dev_err(&client->dev, "touchscreen probe failed\n");
goto err_free_mem;
}
edt_ft5x06_ts_get_defaults(tsdata, pdata);
edt_ft5x06_ts_get_parameters(tsdata);
dev_dbg(&client->dev,
"Model \"%s\", Rev. \"%s\", %dx%d sensors\n",
tsdata->name, fw_version, tsdata->num_x, tsdata->num_y);
input->name = tsdata->name;
input->id.bustype = BUS_I2C;
input->dev.parent = &client->dev;
__set_bit(EV_SYN, input->evbit);
__set_bit(EV_KEY, input->evbit);
__set_bit(EV_ABS, input->evbit);
__set_bit(BTN_TOUCH, input->keybit);
input_set_abs_params(input, ABS_X, 0, tsdata->num_x * 64 - 1, 0, 0);
input_set_abs_params(input, ABS_Y, 0, tsdata->num_y * 64 - 1, 0, 0);
input_set_abs_params(input, ABS_MT_POSITION_X,
0, tsdata->num_x * 64 - 1, 0, 0);
input_set_abs_params(input, ABS_MT_POSITION_Y,
0, tsdata->num_y * 64 - 1, 0, 0);
error = input_mt_init_slots(input, MAX_SUPPORT_POINTS, 0);
if (error) {
dev_err(&client->dev, "Unable to init MT slots.\n");
goto err_free_mem;
}
input_set_drvdata(input, tsdata);
i2c_set_clientdata(client, tsdata);
error = request_threaded_irq(client->irq, NULL, edt_ft5x06_ts_isr,
IRQF_TRIGGER_FALLING | IRQF_ONESHOT,
client->name, tsdata);
if (error) {
dev_err(&client->dev, "Unable to request touchscreen IRQ.\n");
goto err_free_mem;
}
error = sysfs_create_group(&client->dev.kobj, &edt_ft5x06_attr_group);
if (error)
goto err_free_irq;
error = input_register_device(input);
if (error)
goto err_remove_attrs;
edt_ft5x06_ts_prepare_debugfs(tsdata, dev_driver_string(&client->dev));
device_init_wakeup(&client->dev, 1);
dev_dbg(&client->dev,
"EDT FT5x06 initialized: IRQ pin %d, Reset pin %d.\n",
pdata->irq_pin, pdata->reset_pin);
return 0;
err_remove_attrs:
sysfs_remove_group(&client->dev.kobj, &edt_ft5x06_attr_group);
err_free_irq:
free_irq(client->irq, tsdata);
err_free_mem:
input_free_device(input);
kfree(tsdata);
if (gpio_is_valid(pdata->irq_pin))
gpio_free(pdata->irq_pin);
return error;
}
static int edt_ft5x06_ts_remove(struct i2c_client *client)
{
const struct edt_ft5x06_platform_data *pdata =
dev_get_platdata(&client->dev);
struct edt_ft5x06_ts_data *tsdata = i2c_get_clientdata(client);
edt_ft5x06_ts_teardown_debugfs(tsdata);
sysfs_remove_group(&client->dev.kobj, &edt_ft5x06_attr_group);
free_irq(client->irq, tsdata);
input_unregister_device(tsdata->input);
if (gpio_is_valid(pdata->irq_pin))
gpio_free(pdata->irq_pin);
if (gpio_is_valid(pdata->reset_pin))
gpio_free(pdata->reset_pin);
kfree(tsdata);
return 0;
}
static int edt_ft5x06_ts_suspend(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
if (device_may_wakeup(dev))
enable_irq_wake(client->irq);
return 0;
}
static int edt_ft5x06_ts_resume(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
if (device_may_wakeup(dev))
disable_irq_wake(client->irq);
return 0;
}
