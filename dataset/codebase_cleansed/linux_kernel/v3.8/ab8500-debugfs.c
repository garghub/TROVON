static int ab8500_registers_print(struct seq_file *s, void *p)
{
struct device *dev = s->private;
unsigned int i;
u32 bank = debug_bank;
seq_printf(s, AB8500_NAME_STRING " register values:\n");
seq_printf(s, " bank %u:\n", bank);
for (i = 0; i < debug_ranges[bank].num_ranges; i++) {
u32 reg;
for (reg = debug_ranges[bank].range[i].first;
reg <= debug_ranges[bank].range[i].last;
reg++) {
u8 value;
int err;
err = abx500_get_register_interruptible(dev,
(u8)bank, (u8)reg, &value);
if (err < 0) {
dev_err(dev, "ab->read fail %d\n", err);
return err;
}
err = seq_printf(s, " [%u/0x%02X]: 0x%02X\n", bank,
reg, value);
if (err < 0) {
dev_err(dev, "seq_printf overflow\n");
return 0;
}
}
}
return 0;
}
static int ab8500_registers_open(struct inode *inode, struct file *file)
{
return single_open(file, ab8500_registers_print, inode->i_private);
}
static int ab8500_bank_print(struct seq_file *s, void *p)
{
return seq_printf(s, "%d\n", debug_bank);
}
static int ab8500_bank_open(struct inode *inode, struct file *file)
{
return single_open(file, ab8500_bank_print, inode->i_private);
}
static ssize_t ab8500_bank_write(struct file *file,
const char __user *user_buf,
size_t count, loff_t *ppos)
{
struct device *dev = ((struct seq_file *)(file->private_data))->private;
unsigned long user_bank;
int err;
err = kstrtoul_from_user(user_buf, count, 0, &user_bank);
if (err)
return err;
if (user_bank >= AB8500_NUM_BANKS) {
dev_err(dev, "debugfs error input > number of banks\n");
return -EINVAL;
}
debug_bank = user_bank;
return count;
}
static int ab8500_address_print(struct seq_file *s, void *p)
{
return seq_printf(s, "0x%02X\n", debug_address);
}
static int ab8500_address_open(struct inode *inode, struct file *file)
{
return single_open(file, ab8500_address_print, inode->i_private);
}
static ssize_t ab8500_address_write(struct file *file,
const char __user *user_buf,
size_t count, loff_t *ppos)
{
struct device *dev = ((struct seq_file *)(file->private_data))->private;
unsigned long user_address;
int err;
err = kstrtoul_from_user(user_buf, count, 0, &user_address);
if (err)
return err;
if (user_address > 0xff) {
dev_err(dev, "debugfs error input > 0xff\n");
return -EINVAL;
}
debug_address = user_address;
return count;
}
static int ab8500_val_print(struct seq_file *s, void *p)
{
struct device *dev = s->private;
int ret;
u8 regvalue;
ret = abx500_get_register_interruptible(dev,
(u8)debug_bank, (u8)debug_address, &regvalue);
if (ret < 0) {
dev_err(dev, "abx500_get_reg fail %d, %d\n",
ret, __LINE__);
return -EINVAL;
}
seq_printf(s, "0x%02X\n", regvalue);
return 0;
}
static int ab8500_val_open(struct inode *inode, struct file *file)
{
return single_open(file, ab8500_val_print, inode->i_private);
}
static ssize_t ab8500_val_write(struct file *file,
const char __user *user_buf,
size_t count, loff_t *ppos)
{
struct device *dev = ((struct seq_file *)(file->private_data))->private;
unsigned long user_val;
int err;
err = kstrtoul_from_user(user_buf, count, 0, &user_val);
if (err)
return err;
if (user_val > 0xff) {
dev_err(dev, "debugfs error input > 0xff\n");
return -EINVAL;
}
err = abx500_set_register_interruptible(dev,
(u8)debug_bank, debug_address, (u8)user_val);
if (err < 0) {
printk(KERN_ERR "abx500_set_reg failed %d, %d", err, __LINE__);
return -EINVAL;
}
return count;
}
static int ab8500_debug_probe(struct platform_device *plf)
{
debug_bank = AB8500_MISC;
debug_address = AB8500_REV_REG & 0x00FF;
ab8500_dir = debugfs_create_dir(AB8500_NAME_STRING, NULL);
if (!ab8500_dir)
goto exit_no_debugfs;
ab8500_reg_file = debugfs_create_file("all-bank-registers",
S_IRUGO, ab8500_dir, &plf->dev, &ab8500_registers_fops);
if (!ab8500_reg_file)
goto exit_destroy_dir;
ab8500_bank_file = debugfs_create_file("register-bank",
(S_IRUGO | S_IWUSR), ab8500_dir, &plf->dev, &ab8500_bank_fops);
if (!ab8500_bank_file)
goto exit_destroy_reg;
ab8500_address_file = debugfs_create_file("register-address",
(S_IRUGO | S_IWUSR), ab8500_dir, &plf->dev,
&ab8500_address_fops);
if (!ab8500_address_file)
goto exit_destroy_bank;
ab8500_val_file = debugfs_create_file("register-value",
(S_IRUGO | S_IWUSR), ab8500_dir, &plf->dev, &ab8500_val_fops);
if (!ab8500_val_file)
goto exit_destroy_address;
return 0;
exit_destroy_address:
debugfs_remove(ab8500_address_file);
exit_destroy_bank:
debugfs_remove(ab8500_bank_file);
exit_destroy_reg:
debugfs_remove(ab8500_reg_file);
exit_destroy_dir:
debugfs_remove(ab8500_dir);
exit_no_debugfs:
dev_err(&plf->dev, "failed to create debugfs entries.\n");
return -ENOMEM;
}
static int ab8500_debug_remove(struct platform_device *plf)
{
debugfs_remove(ab8500_val_file);
debugfs_remove(ab8500_address_file);
debugfs_remove(ab8500_bank_file);
debugfs_remove(ab8500_reg_file);
debugfs_remove(ab8500_dir);
return 0;
}
static int __init ab8500_debug_init(void)
{
return platform_driver_register(&ab8500_debug_driver);
}
static void __exit ab8500_debug_exit(void)
{
platform_driver_unregister(&ab8500_debug_driver);
}
