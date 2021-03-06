static ssize_t mem_read(struct file *file, char __user *buf, size_t count,
loff_t *ppos)
{
loff_t pos = *ppos;
loff_t avail = file_inode(file)->i_size;
unsigned int mem = (uintptr_t)file->private_data & 3;
struct adapter *adap = file->private_data - mem;
__be32 *data;
int ret;
if (pos < 0)
return -EINVAL;
if (pos >= avail)
return 0;
if (count > avail - pos)
count = avail - pos;
data = t4_alloc_mem(count);
if (!data)
return -ENOMEM;
spin_lock(&adap->win0_lock);
ret = t4_memory_rw(adap, 0, mem, pos, count, data, T4_MEMORY_READ);
spin_unlock(&adap->win0_lock);
if (ret) {
t4_free_mem(data);
return ret;
}
ret = copy_to_user(buf, data, count);
t4_free_mem(data);
if (ret)
return -EFAULT;
*ppos = pos + count;
return count;
}
static void add_debugfs_mem(struct adapter *adap, const char *name,
unsigned int idx, unsigned int size_mb)
{
struct dentry *de;
de = debugfs_create_file(name, S_IRUSR, adap->debugfs_root,
(void *)adap + idx, &mem_debugfs_fops);
if (de && de->d_inode)
de->d_inode->i_size = size_mb << 20;
}
void add_debugfs_files(struct adapter *adap,
struct t4_debugfs_entry *files,
unsigned int nfiles)
{
int i;
for (i = 0; i < nfiles; i++)
debugfs_create_file(files[i].name, files[i].mode,
adap->debugfs_root,
(void *)adap + files[i].data,
files[i].ops);
}
int t4_setup_debugfs(struct adapter *adap)
{
int i;
u32 size;
static struct t4_debugfs_entry t4_debugfs_files[] = {
{ "l2t", &t4_l2t_fops, S_IRUSR, 0},
};
add_debugfs_files(adap,
t4_debugfs_files,
ARRAY_SIZE(t4_debugfs_files));
i = t4_read_reg(adap, MA_TARGET_MEM_ENABLE_A);
if (i & EDRAM0_ENABLE_F) {
size = t4_read_reg(adap, MA_EDRAM0_BAR_A);
add_debugfs_mem(adap, "edc0", MEM_EDC0, EDRAM0_SIZE_G(size));
}
if (i & EDRAM1_ENABLE_F) {
size = t4_read_reg(adap, MA_EDRAM1_BAR_A);
add_debugfs_mem(adap, "edc1", MEM_EDC1, EDRAM1_SIZE_G(size));
}
if (is_t4(adap->params.chip)) {
size = t4_read_reg(adap, MA_EXT_MEMORY_BAR_A);
if (i & EXT_MEM_ENABLE_F)
add_debugfs_mem(adap, "mc", MEM_MC,
EXT_MEM_SIZE_G(size));
} else {
if (i & EXT_MEM0_ENABLE_F) {
size = t4_read_reg(adap, MA_EXT_MEMORY0_BAR_A);
add_debugfs_mem(adap, "mc0", MEM_MC0,
EXT_MEM0_SIZE_G(size));
}
if (i & EXT_MEM1_ENABLE_F) {
size = t4_read_reg(adap, MA_EXT_MEMORY1_BAR_A);
add_debugfs_mem(adap, "mc1", MEM_MC1,
EXT_MEM1_SIZE_G(size));
}
}
return 0;
}
