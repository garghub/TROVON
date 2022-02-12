static int ab5500_registers_print(struct seq_file *s, void *p)
{
struct ab5500 *ab = s->private;
unsigned int i;
u8 bank = (u8)ab->debug_bank;
seq_printf(s, "ab5500 register values:\n");
for (bank = 0; bank < AB5500_NUM_BANKS; bank++) {
seq_printf(s, " bank %u, %s (0x%x):\n", bank,
bankinfo[bank].name,
bankinfo[bank].slave_addr);
for (i = 0; i < ab5500_reg_ranges[bank].nranges; i++) {
u8 reg;
int err;
for (reg = ab5500_reg_ranges[bank].range[i].first;
reg <= ab5500_reg_ranges[bank].range[i].last;
reg++) {
u8 value;
err = ab5500_get_register_interruptible_raw(ab,
bank, reg,
&value);
if (err < 0) {
dev_err(ab->dev, "get_reg failed %d"
"bank 0x%x reg 0x%x\n",
err, bank, reg);
return err;
}
err = seq_printf(s, "[%d/0x%02X]: 0x%02X\n",
bank, reg, value);
if (err < 0) {
dev_err(ab->dev,
"seq_printf overflow\n");
return 0;
}
}
}
}
return 0;
}
static int ab5500_registers_open(struct inode *inode, struct file *file)
{
return single_open(file, ab5500_registers_print, inode->i_private);
}
static int ab5500_bank_print(struct seq_file *s, void *p)
{
struct ab5500 *ab = s->private;
seq_printf(s, "%d\n", ab->debug_bank);
return 0;
}
static int ab5500_bank_open(struct inode *inode, struct file *file)
{
return single_open(file, ab5500_bank_print, inode->i_private);
}
static ssize_t ab5500_bank_write(struct file *file,
const char __user *user_buf,
size_t count, loff_t *ppos)
{
struct ab5500 *ab = ((struct seq_file *)(file->private_data))->private;
char buf[32];
int buf_size;
unsigned long user_bank;
int err;
buf_size = min(count, (sizeof(buf) - 1));
if (copy_from_user(buf, user_buf, buf_size))
return -EFAULT;
buf[buf_size] = 0;
err = strict_strtoul(buf, 0, &user_bank);
if (err)
return -EINVAL;
if (user_bank >= AB5500_NUM_BANKS) {
dev_err(ab->dev,
"debugfs error input > number of banks\n");
return -EINVAL;
}
ab->debug_bank = user_bank;
return buf_size;
}
static int ab5500_address_print(struct seq_file *s, void *p)
{
struct ab5500 *ab = s->private;
seq_printf(s, "0x%02X\n", ab->debug_address);
return 0;
}
static int ab5500_address_open(struct inode *inode, struct file *file)
{
return single_open(file, ab5500_address_print, inode->i_private);
}
static ssize_t ab5500_address_write(struct file *file,
const char __user *user_buf,
size_t count, loff_t *ppos)
{
struct ab5500 *ab = ((struct seq_file *)(file->private_data))->private;
char buf[32];
int buf_size;
unsigned long user_address;
int err;
buf_size = min(count, (sizeof(buf) - 1));
if (copy_from_user(buf, user_buf, buf_size))
return -EFAULT;
buf[buf_size] = 0;
err = strict_strtoul(buf, 0, &user_address);
if (err)
return -EINVAL;
if (user_address > 0xff) {
dev_err(ab->dev,
"debugfs error input > 0xff\n");
return -EINVAL;
}
ab->debug_address = user_address;
return buf_size;
}
static int ab5500_val_print(struct seq_file *s, void *p)
{
struct ab5500 *ab = s->private;
int err;
u8 regvalue;
err = ab5500_get_register_interruptible_raw(ab, (u8)ab->debug_bank,
(u8)ab->debug_address, &regvalue);
if (err) {
dev_err(ab->dev, "get_reg failed %d, bank 0x%x"
", reg 0x%x\n", err, ab->debug_bank,
ab->debug_address);
return -EINVAL;
}
seq_printf(s, "0x%02X\n", regvalue);
return 0;
}
static int ab5500_val_open(struct inode *inode, struct file *file)
{
return single_open(file, ab5500_val_print, inode->i_private);
}
static ssize_t ab5500_val_write(struct file *file,
const char __user *user_buf,
size_t count, loff_t *ppos)
{
struct ab5500 *ab = ((struct seq_file *)(file->private_data))->private;
char buf[32];
int buf_size;
unsigned long user_val;
int err;
u8 regvalue;
buf_size = min(count, (sizeof(buf)-1));
if (copy_from_user(buf, user_buf, buf_size))
return -EFAULT;
buf[buf_size] = 0;
err = strict_strtoul(buf, 0, &user_val);
if (err)
return -EINVAL;
if (user_val > 0xff) {
dev_err(ab->dev,
"debugfs error input > 0xff\n");
return -EINVAL;
}
err = ab5500_mask_and_set_register_interruptible_raw(
ab, (u8)ab->debug_bank,
(u8)ab->debug_address, 0xFF, (u8)user_val);
if (err)
return -EINVAL;
ab5500_get_register_interruptible_raw(ab, (u8)ab->debug_bank,
(u8)ab->debug_address, &regvalue);
if (err)
return -EINVAL;
return buf_size;
}
void __init ab5500_setup_debugfs(struct ab5500 *ab)
{
ab->debug_bank = AB5500_BANK_VIT_IO_I2C_CLK_TST_OTP;
ab->debug_address = AB5500_CHIP_ID;
ab5500_dir = debugfs_create_dir("ab5500", NULL);
if (!ab5500_dir)
goto exit_no_debugfs;
ab5500_reg_file = debugfs_create_file("all-bank-registers",
S_IRUGO, ab5500_dir, ab, &ab5500_registers_fops);
if (!ab5500_reg_file)
goto exit_destroy_dir;
ab5500_bank_file = debugfs_create_file("register-bank",
(S_IRUGO | S_IWUGO), ab5500_dir, ab, &ab5500_bank_fops);
if (!ab5500_bank_file)
goto exit_destroy_reg;
ab5500_address_file = debugfs_create_file("register-address",
(S_IRUGO | S_IWUGO), ab5500_dir, ab, &ab5500_address_fops);
if (!ab5500_address_file)
goto exit_destroy_bank;
ab5500_val_file = debugfs_create_file("register-value",
(S_IRUGO | S_IWUGO), ab5500_dir, ab, &ab5500_val_fops);
if (!ab5500_val_file)
goto exit_destroy_address;
return;
exit_destroy_address:
debugfs_remove(ab5500_address_file);
exit_destroy_bank:
debugfs_remove(ab5500_bank_file);
exit_destroy_reg:
debugfs_remove(ab5500_reg_file);
exit_destroy_dir:
debugfs_remove(ab5500_dir);
exit_no_debugfs:
dev_err(ab->dev, "failed to create debugfs entries.\n");
return;
}
void __exit ab5500_remove_debugfs(void)
{
debugfs_remove(ab5500_val_file);
debugfs_remove(ab5500_address_file);
debugfs_remove(ab5500_bank_file);
debugfs_remove(ab5500_reg_file);
debugfs_remove(ab5500_dir);
}
