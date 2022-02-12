static int __aat2870_read(struct aat2870_data *aat2870, u8 addr, u8 *val)
{
int ret;
if (addr >= AAT2870_REG_NUM) {
dev_err(aat2870->dev, "Invalid address, 0x%02x\n", addr);
return -EINVAL;
}
if (!aat2870->reg_cache[addr].readable) {
*val = aat2870->reg_cache[addr].value;
goto out;
}
ret = i2c_master_send(aat2870->client, &addr, 1);
if (ret < 0)
return ret;
if (ret != 1)
return -EIO;
ret = i2c_master_recv(aat2870->client, val, 1);
if (ret < 0)
return ret;
if (ret != 1)
return -EIO;
out:
dev_dbg(aat2870->dev, "read: addr=0x%02x, val=0x%02x\n", addr, *val);
return 0;
}
static int __aat2870_write(struct aat2870_data *aat2870, u8 addr, u8 val)
{
u8 msg[2];
int ret;
if (addr >= AAT2870_REG_NUM) {
dev_err(aat2870->dev, "Invalid address, 0x%02x\n", addr);
return -EINVAL;
}
if (!aat2870->reg_cache[addr].writeable) {
dev_err(aat2870->dev, "Address 0x%02x is not writeable\n",
addr);
return -EINVAL;
}
msg[0] = addr;
msg[1] = val;
ret = i2c_master_send(aat2870->client, msg, 2);
if (ret < 0)
return ret;
if (ret != 2)
return -EIO;
aat2870->reg_cache[addr].value = val;
dev_dbg(aat2870->dev, "write: addr=0x%02x, val=0x%02x\n", addr, val);
return 0;
}
static int aat2870_read(struct aat2870_data *aat2870, u8 addr, u8 *val)
{
int ret;
mutex_lock(&aat2870->io_lock);
ret = __aat2870_read(aat2870, addr, val);
mutex_unlock(&aat2870->io_lock);
return ret;
}
static int aat2870_write(struct aat2870_data *aat2870, u8 addr, u8 val)
{
int ret;
mutex_lock(&aat2870->io_lock);
ret = __aat2870_write(aat2870, addr, val);
mutex_unlock(&aat2870->io_lock);
return ret;
}
static int aat2870_update(struct aat2870_data *aat2870, u8 addr, u8 mask,
u8 val)
{
int change;
u8 old_val, new_val;
int ret;
mutex_lock(&aat2870->io_lock);
ret = __aat2870_read(aat2870, addr, &old_val);
if (ret)
goto out_unlock;
new_val = (old_val & ~mask) | (val & mask);
change = old_val != new_val;
if (change)
ret = __aat2870_write(aat2870, addr, new_val);
out_unlock:
mutex_unlock(&aat2870->io_lock);
return ret;
}
static inline void aat2870_enable(struct aat2870_data *aat2870)
{
if (aat2870->en_pin >= 0)
gpio_set_value(aat2870->en_pin, 1);
aat2870->is_enable = 1;
}
static inline void aat2870_disable(struct aat2870_data *aat2870)
{
if (aat2870->en_pin >= 0)
gpio_set_value(aat2870->en_pin, 0);
aat2870->is_enable = 0;
}
static ssize_t aat2870_dump_reg(struct aat2870_data *aat2870, char *buf)
{
u8 addr, val;
ssize_t count = 0;
int ret;
count += sprintf(buf, "aat2870 registers\n");
for (addr = 0; addr < AAT2870_REG_NUM; addr++) {
count += sprintf(buf + count, "0x%02x: ", addr);
if (count >= PAGE_SIZE - 1)
break;
ret = aat2870->read(aat2870, addr, &val);
if (ret == 0)
count += snprintf(buf + count, PAGE_SIZE - count,
"0x%02x", val);
else
count += snprintf(buf + count, PAGE_SIZE - count,
"<read fail: %d>", ret);
if (count >= PAGE_SIZE - 1)
break;
count += snprintf(buf + count, PAGE_SIZE - count, "\n");
if (count >= PAGE_SIZE - 1)
break;
}
if (count >= PAGE_SIZE)
count = PAGE_SIZE - 1;
return count;
}
static ssize_t aat2870_reg_read_file(struct file *file, char __user *user_buf,
size_t count, loff_t *ppos)
{
struct aat2870_data *aat2870 = file->private_data;
char *buf;
ssize_t ret;
buf = kmalloc(PAGE_SIZE, GFP_KERNEL);
if (!buf)
return -ENOMEM;
ret = aat2870_dump_reg(aat2870, buf);
if (ret >= 0)
ret = simple_read_from_buffer(user_buf, count, ppos, buf, ret);
kfree(buf);
return ret;
}
static ssize_t aat2870_reg_write_file(struct file *file,
const char __user *user_buf, size_t count,
loff_t *ppos)
{
struct aat2870_data *aat2870 = file->private_data;
char buf[32];
ssize_t buf_size;
char *start = buf;
unsigned long addr, val;
int ret;
buf_size = min(count, (size_t)(sizeof(buf)-1));
if (copy_from_user(buf, user_buf, buf_size)) {
dev_err(aat2870->dev, "Failed to copy from user\n");
return -EFAULT;
}
buf[buf_size] = 0;
while (*start == ' ')
start++;
ret = kstrtoul(start, 16, &addr);
if (ret)
return ret;
if (addr >= AAT2870_REG_NUM) {
dev_err(aat2870->dev, "Invalid address, 0x%lx\n", addr);
return -EINVAL;
}
while (*start == ' ')
start++;
ret = kstrtoul(start, 16, &val);
if (ret)
return ret;
ret = aat2870->write(aat2870, (u8)addr, (u8)val);
if (ret)
return ret;
return buf_size;
}
static void aat2870_init_debugfs(struct aat2870_data *aat2870)
{
aat2870->dentry_root = debugfs_create_dir("aat2870", NULL);
if (!aat2870->dentry_root) {
dev_warn(aat2870->dev,
"Failed to create debugfs root directory\n");
return;
}
aat2870->dentry_reg = debugfs_create_file("regs", 0644,
aat2870->dentry_root,
aat2870, &aat2870_reg_fops);
if (!aat2870->dentry_reg)
dev_warn(aat2870->dev,
"Failed to create debugfs register file\n");
}
static void aat2870_uninit_debugfs(struct aat2870_data *aat2870)
{
debugfs_remove_recursive(aat2870->dentry_root);
}
static inline void aat2870_init_debugfs(struct aat2870_data *aat2870)
{
}
static inline void aat2870_uninit_debugfs(struct aat2870_data *aat2870)
{
}
static int aat2870_i2c_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct aat2870_platform_data *pdata = dev_get_platdata(&client->dev);
struct aat2870_data *aat2870;
int i, j;
int ret = 0;
aat2870 = devm_kzalloc(&client->dev, sizeof(struct aat2870_data),
GFP_KERNEL);
if (!aat2870)
return -ENOMEM;
aat2870->dev = &client->dev;
dev_set_drvdata(aat2870->dev, aat2870);
aat2870->client = client;
i2c_set_clientdata(client, aat2870);
aat2870->reg_cache = aat2870_regs;
if (pdata->en_pin < 0)
aat2870->en_pin = -1;
else
aat2870->en_pin = pdata->en_pin;
aat2870->init = pdata->init;
aat2870->uninit = pdata->uninit;
aat2870->read = aat2870_read;
aat2870->write = aat2870_write;
aat2870->update = aat2870_update;
mutex_init(&aat2870->io_lock);
if (aat2870->init)
aat2870->init(aat2870);
if (aat2870->en_pin >= 0) {
ret = devm_gpio_request_one(&client->dev, aat2870->en_pin,
GPIOF_OUT_INIT_HIGH, "aat2870-en");
if (ret < 0) {
dev_err(&client->dev,
"Failed to request GPIO %d\n", aat2870->en_pin);
return ret;
}
}
aat2870_enable(aat2870);
for (i = 0; i < pdata->num_subdevs; i++) {
for (j = 0; j < ARRAY_SIZE(aat2870_devs); j++) {
if ((pdata->subdevs[i].id == aat2870_devs[j].id) &&
!strcmp(pdata->subdevs[i].name,
aat2870_devs[j].name)) {
aat2870_devs[j].platform_data =
pdata->subdevs[i].platform_data;
break;
}
}
}
ret = mfd_add_devices(aat2870->dev, 0, aat2870_devs,
ARRAY_SIZE(aat2870_devs), NULL, 0, NULL);
if (ret != 0) {
dev_err(aat2870->dev, "Failed to add subdev: %d\n", ret);
goto out_disable;
}
aat2870_init_debugfs(aat2870);
return 0;
out_disable:
aat2870_disable(aat2870);
return ret;
}
static int aat2870_i2c_remove(struct i2c_client *client)
{
struct aat2870_data *aat2870 = i2c_get_clientdata(client);
aat2870_uninit_debugfs(aat2870);
mfd_remove_devices(aat2870->dev);
aat2870_disable(aat2870);
if (aat2870->uninit)
aat2870->uninit(aat2870);
return 0;
}
static int aat2870_i2c_suspend(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct aat2870_data *aat2870 = i2c_get_clientdata(client);
aat2870_disable(aat2870);
return 0;
}
static int aat2870_i2c_resume(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct aat2870_data *aat2870 = i2c_get_clientdata(client);
struct aat2870_register *reg = NULL;
int i;
aat2870_enable(aat2870);
for (i = 0; i < AAT2870_REG_NUM; i++) {
reg = &aat2870->reg_cache[i];
if (reg->writeable)
aat2870->write(aat2870, i, reg->value);
}
return 0;
}
static int __init aat2870_init(void)
{
return i2c_add_driver(&aat2870_i2c_driver);
}
static void __exit aat2870_exit(void)
{
i2c_del_driver(&aat2870_i2c_driver);
}
