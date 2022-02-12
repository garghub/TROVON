static size_t regmap_calc_reg_len(int max_val, char *buf, size_t buf_size)
{
snprintf(buf, buf_size, "%x", max_val);
return strlen(buf);
}
static int regmap_open_file(struct inode *inode, struct file *file)
{
file->private_data = inode->i_private;
return 0;
}
static ssize_t regmap_map_read_file(struct file *file, char __user *user_buf,
size_t count, loff_t *ppos)
{
int reg_len, val_len, tot_len;
size_t buf_pos = 0;
loff_t p = 0;
ssize_t ret;
int i;
struct regmap *map = file->private_data;
char *buf;
unsigned int val;
if (*ppos < 0 || !count)
return -EINVAL;
buf = kmalloc(count, GFP_KERNEL);
if (!buf)
return -ENOMEM;
reg_len = regmap_calc_reg_len(map->max_register, buf, count);
val_len = 2 * map->format.val_bytes;
tot_len = reg_len + val_len + 3;
for (i = 0; i < map->max_register + 1; i++) {
if (!regmap_readable(map, i))
continue;
if (regmap_precious(map, i))
continue;
if (p >= *ppos) {
if (buf_pos >= count - 1 - tot_len)
break;
snprintf(buf + buf_pos, count - buf_pos, "%.*x: ",
reg_len, i);
buf_pos += reg_len + 2;
ret = regmap_read(map, i, &val);
if (ret == 0)
snprintf(buf + buf_pos, count - buf_pos,
"%.*x", val_len, val);
else
memset(buf + buf_pos, 'X', val_len);
buf_pos += 2 * map->format.val_bytes;
buf[buf_pos++] = '\n';
}
p += tot_len;
}
ret = buf_pos;
if (copy_to_user(user_buf, buf, buf_pos)) {
ret = -EFAULT;
goto out;
}
*ppos += buf_pos;
out:
kfree(buf);
return ret;
}
static ssize_t regmap_access_read_file(struct file *file,
char __user *user_buf, size_t count,
loff_t *ppos)
{
int reg_len, tot_len;
size_t buf_pos = 0;
loff_t p = 0;
ssize_t ret;
int i;
struct regmap *map = file->private_data;
char *buf;
if (*ppos < 0 || !count)
return -EINVAL;
buf = kmalloc(count, GFP_KERNEL);
if (!buf)
return -ENOMEM;
reg_len = regmap_calc_reg_len(map->max_register, buf, count);
tot_len = reg_len + 10;
for (i = 0; i < map->max_register + 1; i++) {
if (!regmap_readable(map, i) && !regmap_writeable(map, i))
continue;
if (p >= *ppos) {
if (buf_pos >= count - 1 - tot_len)
break;
snprintf(buf + buf_pos, count - buf_pos,
"%.*x: %c %c %c %c\n",
reg_len, i,
regmap_readable(map, i) ? 'y' : 'n',
regmap_writeable(map, i) ? 'y' : 'n',
regmap_volatile(map, i) ? 'y' : 'n',
regmap_precious(map, i) ? 'y' : 'n');
buf_pos += tot_len;
}
p += tot_len;
}
ret = buf_pos;
if (copy_to_user(user_buf, buf, buf_pos)) {
ret = -EFAULT;
goto out;
}
*ppos += buf_pos;
out:
kfree(buf);
return ret;
}
void regmap_debugfs_init(struct regmap *map)
{
map->debugfs = debugfs_create_dir(dev_name(map->dev),
regmap_debugfs_root);
if (!map->debugfs) {
dev_warn(map->dev, "Failed to create debugfs directory\n");
return;
}
if (map->max_register) {
debugfs_create_file("registers", 0400, map->debugfs,
map, &regmap_map_fops);
debugfs_create_file("access", 0400, map->debugfs,
map, &regmap_access_fops);
}
}
void regmap_debugfs_exit(struct regmap *map)
{
debugfs_remove_recursive(map->debugfs);
}
void regmap_debugfs_initcall(void)
{
regmap_debugfs_root = debugfs_create_dir("regmap", NULL);
if (!regmap_debugfs_root) {
pr_warn("regmap: Failed to create debugfs root\n");
return;
}
}
