static int acpi_ec_open_io(struct inode *i, struct file *f)
{
f->private_data = i->i_private;
return 0;
}
static ssize_t acpi_ec_read_io(struct file *f, char __user *buf,
size_t count, loff_t *off)
{
unsigned int size = EC_SPACE_SIZE;
u8 *data = (u8 *) buf;
loff_t init_off = *off;
int err = 0;
if (*off >= size)
return 0;
if (*off + count >= size) {
size -= *off;
count = size;
} else
size = count;
while (size) {
err = ec_read(*off, &data[*off - init_off]);
if (err)
return err;
*off += 1;
size--;
}
return count;
}
static ssize_t acpi_ec_write_io(struct file *f, const char __user *buf,
size_t count, loff_t *off)
{
unsigned int size = count;
loff_t init_off = *off;
u8 *data = (u8 *) buf;
int err = 0;
if (*off >= EC_SPACE_SIZE)
return 0;
if (*off + count >= EC_SPACE_SIZE) {
size = EC_SPACE_SIZE - *off;
count = size;
}
while (size) {
u8 byte_write = data[*off - init_off];
err = ec_write(*off, byte_write);
if (err)
return err;
*off += 1;
size--;
}
return count;
}
int acpi_ec_add_debugfs(struct acpi_ec *ec, unsigned int ec_device_count)
{
struct dentry *dev_dir;
char name[64];
umode_t mode = 0400;
if (ec_device_count == 0) {
acpi_ec_debugfs_dir = debugfs_create_dir("ec", NULL);
if (!acpi_ec_debugfs_dir)
return -ENOMEM;
}
sprintf(name, "ec%u", ec_device_count);
dev_dir = debugfs_create_dir(name, acpi_ec_debugfs_dir);
if (!dev_dir) {
if (ec_device_count != 0)
goto error;
return -ENOMEM;
}
if (!debugfs_create_x32("gpe", 0444, dev_dir, (u32 *)&first_ec->gpe))
goto error;
if (!debugfs_create_bool("use_global_lock", 0444, dev_dir,
(u32 *)&first_ec->global_lock))
goto error;
if (write_support)
mode = 0600;
if (!debugfs_create_file("io", mode, dev_dir, ec, &acpi_ec_io_ops))
goto error;
return 0;
error:
debugfs_remove_recursive(acpi_ec_debugfs_dir);
return -ENOMEM;
}
static int __init acpi_ec_sys_init(void)
{
int err = 0;
if (first_ec)
err = acpi_ec_add_debugfs(first_ec, 0);
else
err = -ENODEV;
return err;
}
static void __exit acpi_ec_sys_exit(void)
{
debugfs_remove_recursive(acpi_ec_debugfs_dir);
}
