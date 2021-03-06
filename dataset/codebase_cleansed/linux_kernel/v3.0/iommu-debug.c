static ssize_t debug_read_ver(struct file *file, char __user *userbuf,
size_t count, loff_t *ppos)
{
u32 ver = iommu_arch_version();
char buf[MAXCOLUMN], *p = buf;
p += sprintf(p, "H/W version: %d.%d\n", (ver >> 4) & 0xf , ver & 0xf);
return simple_read_from_buffer(userbuf, count, ppos, buf, p - buf);
}
static ssize_t debug_read_regs(struct file *file, char __user *userbuf,
size_t count, loff_t *ppos)
{
struct iommu *obj = file->private_data;
char *p, *buf;
ssize_t bytes;
buf = kmalloc(count, GFP_KERNEL);
if (!buf)
return -ENOMEM;
p = buf;
mutex_lock(&iommu_debug_lock);
bytes = iommu_dump_ctx(obj, p, count);
bytes = simple_read_from_buffer(userbuf, count, ppos, buf, bytes);
mutex_unlock(&iommu_debug_lock);
kfree(buf);
return bytes;
}
static ssize_t debug_read_tlb(struct file *file, char __user *userbuf,
size_t count, loff_t *ppos)
{
struct iommu *obj = file->private_data;
char *p, *buf;
ssize_t bytes, rest;
buf = kmalloc(count, GFP_KERNEL);
if (!buf)
return -ENOMEM;
p = buf;
mutex_lock(&iommu_debug_lock);
p += sprintf(p, "%8s %8s\n", "cam:", "ram:");
p += sprintf(p, "-----------------------------------------\n");
rest = count - (p - buf);
p += dump_tlb_entries(obj, p, rest);
bytes = simple_read_from_buffer(userbuf, count, ppos, buf, p - buf);
mutex_unlock(&iommu_debug_lock);
kfree(buf);
return bytes;
}
static ssize_t debug_write_pagetable(struct file *file,
const char __user *userbuf, size_t count, loff_t *ppos)
{
struct iotlb_entry e;
struct cr_regs cr;
int err;
struct iommu *obj = file->private_data;
char buf[MAXCOLUMN], *p = buf;
count = min(count, sizeof(buf));
mutex_lock(&iommu_debug_lock);
if (copy_from_user(p, userbuf, count)) {
mutex_unlock(&iommu_debug_lock);
return -EFAULT;
}
sscanf(p, "%x %x", &cr.cam, &cr.ram);
if (!cr.cam || !cr.ram) {
mutex_unlock(&iommu_debug_lock);
return -EINVAL;
}
iotlb_cr_to_e(&cr, &e);
err = iopgtable_store_entry(obj, &e);
if (err)
dev_err(obj->dev, "%s: fail to store cr\n", __func__);
mutex_unlock(&iommu_debug_lock);
return count;
}
static ssize_t dump_ioptable(struct iommu *obj, char *buf, ssize_t len)
{
int i;
u32 *iopgd;
char *p = buf;
spin_lock(&obj->page_table_lock);
iopgd = iopgd_offset(obj, 0);
for (i = 0; i < PTRS_PER_IOPGD; i++, iopgd++) {
int j, err;
u32 *iopte;
u32 da;
if (!*iopgd)
continue;
if (!(*iopgd & IOPGD_TABLE)) {
da = i << IOPGD_SHIFT;
err = dump_ioptable_entry_one(1, da, *iopgd);
if (err)
goto out;
continue;
}
iopte = iopte_offset(iopgd, 0);
for (j = 0; j < PTRS_PER_IOPTE; j++, iopte++) {
if (!*iopte)
continue;
da = (i << IOPGD_SHIFT) + (j << IOPTE_SHIFT);
err = dump_ioptable_entry_one(2, da, *iopgd);
if (err)
goto out;
}
}
out:
spin_unlock(&obj->page_table_lock);
return p - buf;
}
static ssize_t debug_read_pagetable(struct file *file, char __user *userbuf,
size_t count, loff_t *ppos)
{
struct iommu *obj = file->private_data;
char *p, *buf;
size_t bytes;
buf = (char *)__get_free_page(GFP_KERNEL);
if (!buf)
return -ENOMEM;
p = buf;
p += sprintf(p, "L: %8s %8s\n", "da:", "pa:");
p += sprintf(p, "-----------------------------------------\n");
mutex_lock(&iommu_debug_lock);
bytes = PAGE_SIZE - (p - buf);
p += dump_ioptable(obj, p, bytes);
bytes = simple_read_from_buffer(userbuf, count, ppos, buf, p - buf);
mutex_unlock(&iommu_debug_lock);
free_page((unsigned long)buf);
return bytes;
}
static ssize_t debug_read_mmap(struct file *file, char __user *userbuf,
size_t count, loff_t *ppos)
{
struct iommu *obj = file->private_data;
char *p, *buf;
struct iovm_struct *tmp;
int uninitialized_var(i);
ssize_t bytes;
buf = (char *)__get_free_page(GFP_KERNEL);
if (!buf)
return -ENOMEM;
p = buf;
p += sprintf(p, "%-3s %-8s %-8s %6s %8s\n",
"No", "start", "end", "size", "flags");
p += sprintf(p, "-------------------------------------------------\n");
mutex_lock(&iommu_debug_lock);
list_for_each_entry(tmp, &obj->mmap, list) {
size_t len;
const char *str = "%3d %08x-%08x %6x %8x\n";
const int maxcol = 39;
len = tmp->da_end - tmp->da_start;
p += snprintf(p, maxcol, str,
i, tmp->da_start, tmp->da_end, len, tmp->flags);
if (PAGE_SIZE - (p - buf) < maxcol)
break;
i++;
}
bytes = simple_read_from_buffer(userbuf, count, ppos, buf, p - buf);
mutex_unlock(&iommu_debug_lock);
free_page((unsigned long)buf);
return bytes;
}
static ssize_t debug_read_mem(struct file *file, char __user *userbuf,
size_t count, loff_t *ppos)
{
struct iommu *obj = file->private_data;
char *p, *buf;
struct iovm_struct *area;
ssize_t bytes;
count = min_t(ssize_t, count, PAGE_SIZE);
buf = (char *)__get_free_page(GFP_KERNEL);
if (!buf)
return -ENOMEM;
p = buf;
mutex_lock(&iommu_debug_lock);
area = find_iovm_area(obj, (u32)ppos);
if (IS_ERR(area)) {
bytes = -EINVAL;
goto err_out;
}
memcpy(p, area->va, count);
p += count;
bytes = simple_read_from_buffer(userbuf, count, ppos, buf, p - buf);
err_out:
mutex_unlock(&iommu_debug_lock);
free_page((unsigned long)buf);
return bytes;
}
static ssize_t debug_write_mem(struct file *file, const char __user *userbuf,
size_t count, loff_t *ppos)
{
struct iommu *obj = file->private_data;
struct iovm_struct *area;
char *p, *buf;
count = min_t(size_t, count, PAGE_SIZE);
buf = (char *)__get_free_page(GFP_KERNEL);
if (!buf)
return -ENOMEM;
p = buf;
mutex_lock(&iommu_debug_lock);
if (copy_from_user(p, userbuf, count)) {
count = -EFAULT;
goto err_out;
}
area = find_iovm_area(obj, (u32)ppos);
if (IS_ERR(area)) {
count = -EINVAL;
goto err_out;
}
memcpy(area->va, p, count);
err_out:
mutex_unlock(&iommu_debug_lock);
free_page((unsigned long)buf);
return count;
}
static int debug_open_generic(struct inode *inode, struct file *file)
{
file->private_data = inode->i_private;
return 0;
}
static int iommu_debug_register(struct device *dev, void *data)
{
struct platform_device *pdev = to_platform_device(dev);
struct iommu *obj = platform_get_drvdata(pdev);
struct dentry *d, *parent;
if (!obj || !obj->dev)
return -EINVAL;
d = debugfs_create_dir(obj->name, iommu_debug_root);
if (!d)
return -ENOMEM;
parent = d;
d = debugfs_create_u8("nr_tlb_entries", 400, parent,
(u8 *)&obj->nr_tlb_entries);
if (!d)
return -ENOMEM;
DEBUG_ADD_FILE_RO(ver);
DEBUG_ADD_FILE_RO(regs);
DEBUG_ADD_FILE_RO(tlb);
DEBUG_ADD_FILE(pagetable);
DEBUG_ADD_FILE_RO(mmap);
DEBUG_ADD_FILE(mem);
return 0;
}
static int __init iommu_debug_init(void)
{
struct dentry *d;
int err;
d = debugfs_create_dir("iommu", NULL);
if (!d)
return -ENOMEM;
iommu_debug_root = d;
err = foreach_iommu_device(d, iommu_debug_register);
if (err)
goto err_out;
return 0;
err_out:
debugfs_remove_recursive(iommu_debug_root);
return err;
}
static void __exit iommu_debugfs_exit(void)
{
debugfs_remove_recursive(iommu_debug_root);
}
