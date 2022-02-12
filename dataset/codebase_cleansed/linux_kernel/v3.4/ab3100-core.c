static int ab3100_get_chip_id(struct device *dev)
{
struct ab3100 *ab3100 = dev_get_drvdata(dev->parent);
return (int)ab3100->chip_id;
}
static int ab3100_set_register_interruptible(struct ab3100 *ab3100,
u8 reg, u8 regval)
{
u8 regandval[2] = {reg, regval};
int err;
err = mutex_lock_interruptible(&ab3100->access_mutex);
if (err)
return err;
err = i2c_master_send(ab3100->i2c_client, regandval, 2);
if (err < 0) {
dev_err(ab3100->dev,
"write error (write register): %d\n",
err);
} else if (err != 2) {
dev_err(ab3100->dev,
"write error (write register) "
"%d bytes transferred (expected 2)\n",
err);
err = -EIO;
} else {
err = 0;
}
mutex_unlock(&ab3100->access_mutex);
return err;
}
static int set_register_interruptible(struct device *dev,
u8 bank, u8 reg, u8 value)
{
struct ab3100 *ab3100 = dev_get_drvdata(dev->parent);
return ab3100_set_register_interruptible(ab3100, reg, value);
}
static int ab3100_set_test_register_interruptible(struct ab3100 *ab3100,
u8 reg, u8 regval)
{
u8 regandval[2] = {reg, regval};
int err;
err = mutex_lock_interruptible(&ab3100->access_mutex);
if (err)
return err;
err = i2c_master_send(ab3100->testreg_client, regandval, 2);
if (err < 0) {
dev_err(ab3100->dev,
"write error (write test register): %d\n",
err);
} else if (err != 2) {
dev_err(ab3100->dev,
"write error (write test register) "
"%d bytes transferred (expected 2)\n",
err);
err = -EIO;
} else {
err = 0;
}
mutex_unlock(&ab3100->access_mutex);
return err;
}
static int ab3100_get_register_interruptible(struct ab3100 *ab3100,
u8 reg, u8 *regval)
{
int err;
err = mutex_lock_interruptible(&ab3100->access_mutex);
if (err)
return err;
err = i2c_master_send(ab3100->i2c_client, &reg, 1);
if (err < 0) {
dev_err(ab3100->dev,
"write error (send register address): %d\n",
err);
goto get_reg_out_unlock;
} else if (err != 1) {
dev_err(ab3100->dev,
"write error (send register address) "
"%d bytes transferred (expected 1)\n",
err);
err = -EIO;
goto get_reg_out_unlock;
} else {
err = 0;
}
err = i2c_master_recv(ab3100->i2c_client, regval, 1);
if (err < 0) {
dev_err(ab3100->dev,
"write error (read register): %d\n",
err);
goto get_reg_out_unlock;
} else if (err != 1) {
dev_err(ab3100->dev,
"write error (read register) "
"%d bytes transferred (expected 1)\n",
err);
err = -EIO;
goto get_reg_out_unlock;
} else {
err = 0;
}
get_reg_out_unlock:
mutex_unlock(&ab3100->access_mutex);
return err;
}
static int get_register_interruptible(struct device *dev, u8 bank, u8 reg,
u8 *value)
{
struct ab3100 *ab3100 = dev_get_drvdata(dev->parent);
return ab3100_get_register_interruptible(ab3100, reg, value);
}
static int ab3100_get_register_page_interruptible(struct ab3100 *ab3100,
u8 first_reg, u8 *regvals, u8 numregs)
{
int err;
if (ab3100->chip_id == 0xa0 ||
ab3100->chip_id == 0xa1)
return -EIO;
err = mutex_lock_interruptible(&ab3100->access_mutex);
if (err)
return err;
err = i2c_master_send(ab3100->i2c_client, &first_reg, 1);
if (err < 0) {
dev_err(ab3100->dev,
"write error (send first register address): %d\n",
err);
goto get_reg_page_out_unlock;
} else if (err != 1) {
dev_err(ab3100->dev,
"write error (send first register address) "
"%d bytes transferred (expected 1)\n",
err);
err = -EIO;
goto get_reg_page_out_unlock;
}
err = i2c_master_recv(ab3100->i2c_client, regvals, numregs);
if (err < 0) {
dev_err(ab3100->dev,
"write error (read register page): %d\n",
err);
goto get_reg_page_out_unlock;
} else if (err != numregs) {
dev_err(ab3100->dev,
"write error (read register page) "
"%d bytes transferred (expected %d)\n",
err, numregs);
err = -EIO;
goto get_reg_page_out_unlock;
}
err = 0;
get_reg_page_out_unlock:
mutex_unlock(&ab3100->access_mutex);
return err;
}
static int get_register_page_interruptible(struct device *dev, u8 bank,
u8 first_reg, u8 *regvals, u8 numregs)
{
struct ab3100 *ab3100 = dev_get_drvdata(dev->parent);
return ab3100_get_register_page_interruptible(ab3100,
first_reg, regvals, numregs);
}
static int ab3100_mask_and_set_register_interruptible(struct ab3100 *ab3100,
u8 reg, u8 andmask, u8 ormask)
{
u8 regandval[2] = {reg, 0};
int err;
err = mutex_lock_interruptible(&ab3100->access_mutex);
if (err)
return err;
err = i2c_master_send(ab3100->i2c_client, &reg, 1);
if (err < 0) {
dev_err(ab3100->dev,
"write error (maskset send address): %d\n",
err);
goto get_maskset_unlock;
} else if (err != 1) {
dev_err(ab3100->dev,
"write error (maskset send address) "
"%d bytes transferred (expected 1)\n",
err);
err = -EIO;
goto get_maskset_unlock;
}
err = i2c_master_recv(ab3100->i2c_client, &regandval[1], 1);
if (err < 0) {
dev_err(ab3100->dev,
"write error (maskset read register): %d\n",
err);
goto get_maskset_unlock;
} else if (err != 1) {
dev_err(ab3100->dev,
"write error (maskset read register) "
"%d bytes transferred (expected 1)\n",
err);
err = -EIO;
goto get_maskset_unlock;
}
regandval[1] &= andmask;
regandval[1] |= ormask;
err = i2c_master_send(ab3100->i2c_client, regandval, 2);
if (err < 0) {
dev_err(ab3100->dev,
"write error (write register): %d\n",
err);
goto get_maskset_unlock;
} else if (err != 2) {
dev_err(ab3100->dev,
"write error (write register) "
"%d bytes transferred (expected 2)\n",
err);
err = -EIO;
goto get_maskset_unlock;
}
err = 0;
get_maskset_unlock:
mutex_unlock(&ab3100->access_mutex);
return err;
}
static int mask_and_set_register_interruptible(struct device *dev, u8 bank,
u8 reg, u8 bitmask, u8 bitvalues)
{
struct ab3100 *ab3100 = dev_get_drvdata(dev->parent);
return ab3100_mask_and_set_register_interruptible(ab3100,
reg, bitmask, (bitmask & bitvalues));
}
int ab3100_event_register(struct ab3100 *ab3100,
struct notifier_block *nb)
{
return blocking_notifier_chain_register(&ab3100->event_subscribers,
nb);
}
int ab3100_event_unregister(struct ab3100 *ab3100,
struct notifier_block *nb)
{
return blocking_notifier_chain_unregister(&ab3100->event_subscribers,
nb);
}
static int ab3100_event_registers_startup_state_get(struct device *dev,
u8 *event)
{
struct ab3100 *ab3100 = dev_get_drvdata(dev->parent);
if (!ab3100->startup_events_read)
return -EAGAIN;
memcpy(event, ab3100->startup_events, 3);
return 0;
}
static irqreturn_t ab3100_irq_handler(int irq, void *data)
{
struct ab3100 *ab3100 = data;
u8 event_regs[3];
u32 fatevent;
int err;
add_interrupt_randomness(irq);
err = ab3100_get_register_page_interruptible(ab3100, AB3100_EVENTA1,
event_regs, 3);
if (err)
goto err_event;
fatevent = (event_regs[0] << 16) |
(event_regs[1] << 8) |
event_regs[2];
if (!ab3100->startup_events_read) {
ab3100->startup_events[0] = event_regs[0];
ab3100->startup_events[1] = event_regs[1];
ab3100->startup_events[2] = event_regs[2];
ab3100->startup_events_read = true;
}
blocking_notifier_call_chain(&ab3100->event_subscribers,
fatevent, NULL);
dev_dbg(ab3100->dev,
"IRQ Event: 0x%08x\n", fatevent);
return IRQ_HANDLED;
err_event:
dev_dbg(ab3100->dev,
"error reading event status\n");
return IRQ_HANDLED;
}
static int ab3100_registers_print(struct seq_file *s, void *p)
{
struct ab3100 *ab3100 = s->private;
u8 value;
u8 reg;
seq_printf(s, "AB3100 registers:\n");
for (reg = 0; reg < 0xff; reg++) {
ab3100_get_register_interruptible(ab3100, reg, &value);
seq_printf(s, "[0x%x]: 0x%x\n", reg, value);
}
return 0;
}
static int ab3100_registers_open(struct inode *inode, struct file *file)
{
return single_open(file, ab3100_registers_print, inode->i_private);
}
static ssize_t ab3100_get_set_reg(struct file *file,
const char __user *user_buf,
size_t count, loff_t *ppos)
{
struct ab3100_get_set_reg_priv *priv = file->private_data;
struct ab3100 *ab3100 = priv->ab3100;
char buf[32];
ssize_t buf_size;
int regp;
unsigned long user_reg;
int err;
int i = 0;
buf_size = min(count, (sizeof(buf)-1));
if (copy_from_user(buf, user_buf, buf_size))
return -EFAULT;
buf[buf_size] = 0;
while ((i < buf_size) && (buf[i] == ' '))
i++;
regp = i;
while ((i < buf_size) && (buf[i] != ' '))
i++;
buf[i] = '\0';
err = strict_strtoul(&buf[regp], 16, &user_reg);
if (err)
return err;
if (user_reg > 0xff)
return -EINVAL;
if (!priv->mode) {
u8 reg = (u8) user_reg;
u8 regvalue;
ab3100_get_register_interruptible(ab3100, reg, &regvalue);
dev_info(ab3100->dev,
"debug read AB3100 reg[0x%02x]: 0x%02x\n",
reg, regvalue);
} else {
int valp;
unsigned long user_value;
u8 reg = (u8) user_reg;
u8 value;
u8 regvalue;
i++;
while ((i < buf_size) && (buf[i] == ' '))
i++;
valp = i;
while ((i < buf_size) && (buf[i] != ' '))
i++;
buf[i] = '\0';
err = strict_strtoul(&buf[valp], 16, &user_value);
if (err)
return err;
if (user_reg > 0xff)
return -EINVAL;
value = (u8) user_value;
ab3100_set_register_interruptible(ab3100, reg, value);
ab3100_get_register_interruptible(ab3100, reg, &regvalue);
dev_info(ab3100->dev,
"debug write reg[0x%02x] with 0x%02x, "
"after readback: 0x%02x\n",
reg, value, regvalue);
}
return buf_size;
}
static void ab3100_setup_debugfs(struct ab3100 *ab3100)
{
int err;
ab3100_dir = debugfs_create_dir("ab3100", NULL);
if (!ab3100_dir)
goto exit_no_debugfs;
ab3100_reg_file = debugfs_create_file("registers",
S_IRUGO, ab3100_dir, ab3100,
&ab3100_registers_fops);
if (!ab3100_reg_file) {
err = -ENOMEM;
goto exit_destroy_dir;
}
ab3100_get_priv.ab3100 = ab3100;
ab3100_get_priv.mode = false;
ab3100_get_reg_file = debugfs_create_file("get_reg",
S_IWUSR, ab3100_dir, &ab3100_get_priv,
&ab3100_get_set_reg_fops);
if (!ab3100_get_reg_file) {
err = -ENOMEM;
goto exit_destroy_reg;
}
ab3100_set_priv.ab3100 = ab3100;
ab3100_set_priv.mode = true;
ab3100_set_reg_file = debugfs_create_file("set_reg",
S_IWUSR, ab3100_dir, &ab3100_set_priv,
&ab3100_get_set_reg_fops);
if (!ab3100_set_reg_file) {
err = -ENOMEM;
goto exit_destroy_get_reg;
}
return;
exit_destroy_get_reg:
debugfs_remove(ab3100_get_reg_file);
exit_destroy_reg:
debugfs_remove(ab3100_reg_file);
exit_destroy_dir:
debugfs_remove(ab3100_dir);
exit_no_debugfs:
return;
}
static inline void ab3100_remove_debugfs(void)
{
debugfs_remove(ab3100_set_reg_file);
debugfs_remove(ab3100_get_reg_file);
debugfs_remove(ab3100_reg_file);
debugfs_remove(ab3100_dir);
}
static inline void ab3100_setup_debugfs(struct ab3100 *ab3100)
{
}
static inline void ab3100_remove_debugfs(void)
{
}
static int __devinit ab3100_setup(struct ab3100 *ab3100)
{
int err = 0;
int i;
for (i = 0; i < ARRAY_SIZE(ab3100_init_settings); i++) {
err = ab3100_set_register_interruptible(ab3100,
ab3100_init_settings[i].abreg,
ab3100_init_settings[i].setting);
if (err)
goto exit_no_setup;
}
if (ab3100->chip_id == 0xc4) {
dev_warn(ab3100->dev,
"AB3100 P1E variant detected, "
"forcing chip to 32KHz\n");
err = ab3100_set_test_register_interruptible(ab3100,
0x02, 0x08);
}
exit_no_setup:
return err;
}
static int __devinit ab3100_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct ab3100 *ab3100;
struct ab3100_platform_data *ab3100_plf_data =
client->dev.platform_data;
int err;
int i;
ab3100 = kzalloc(sizeof(struct ab3100), GFP_KERNEL);
if (!ab3100) {
dev_err(&client->dev, "could not allocate AB3100 device\n");
return -ENOMEM;
}
mutex_init(&ab3100->access_mutex);
BLOCKING_INIT_NOTIFIER_HEAD(&ab3100->event_subscribers);
ab3100->i2c_client = client;
ab3100->dev = &ab3100->i2c_client->dev;
i2c_set_clientdata(client, ab3100);
err = ab3100_get_register_interruptible(ab3100, AB3100_CID,
&ab3100->chip_id);
if (err) {
dev_err(&client->dev,
"could not communicate with the AB3100 analog "
"baseband chip\n");
goto exit_no_detect;
}
for (i = 0; ids[i].id != 0x0; i++) {
if (ids[i].id == ab3100->chip_id) {
if (ids[i].name != NULL) {
snprintf(&ab3100->chip_name[0],
sizeof(ab3100->chip_name) - 1,
"AB3100 %s",
ids[i].name);
break;
} else {
dev_err(&client->dev,
"AB3000 is not supported\n");
goto exit_no_detect;
}
}
}
if (ids[i].id == 0x0) {
dev_err(&client->dev, "unknown analog baseband chip id: 0x%x\n",
ab3100->chip_id);
dev_err(&client->dev, "accepting it anyway. Please update "
"the driver.\n");
goto exit_no_detect;
}
dev_info(&client->dev, "Detected chip: %s\n",
&ab3100->chip_name[0]);
ab3100->testreg_client = i2c_new_dummy(client->adapter,
client->addr + 1);
if (!ab3100->testreg_client) {
err = -ENOMEM;
goto exit_no_testreg_client;
}
err = ab3100_setup(ab3100);
if (err)
goto exit_no_setup;
err = request_threaded_irq(client->irq, NULL, ab3100_irq_handler,
IRQF_ONESHOT, "ab3100-core", ab3100);
rand_initialize_irq(client->irq);
if (err)
goto exit_no_irq;
err = abx500_register_ops(&client->dev, &ab3100_ops);
if (err)
goto exit_no_ops;
for (i = 0; i < ARRAY_SIZE(ab3100_devs); i++) {
ab3100_devs[i].platform_data = ab3100_plf_data;
ab3100_devs[i].pdata_size = sizeof(struct ab3100_platform_data);
}
err = mfd_add_devices(&client->dev, 0, ab3100_devs,
ARRAY_SIZE(ab3100_devs), NULL, 0);
ab3100_setup_debugfs(ab3100);
return 0;
exit_no_ops:
exit_no_irq:
exit_no_setup:
i2c_unregister_device(ab3100->testreg_client);
exit_no_testreg_client:
exit_no_detect:
kfree(ab3100);
return err;
}
static int __devexit ab3100_remove(struct i2c_client *client)
{
struct ab3100 *ab3100 = i2c_get_clientdata(client);
mfd_remove_devices(&client->dev);
ab3100_remove_debugfs();
i2c_unregister_device(ab3100->testreg_client);
free_irq(client->irq, ab3100);
kfree(ab3100);
return 0;
}
static int __init ab3100_i2c_init(void)
{
return i2c_add_driver(&ab3100_driver);
}
static void __exit ab3100_i2c_exit(void)
{
i2c_del_driver(&ab3100_driver);
}
