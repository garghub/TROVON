static inline bool is_omap_iommu_detached(struct omap_iommu *obj)
{
return !obj->domain;
}
static ssize_t debug_read_regs(struct file *file, char __user *userbuf,
size_t count, loff_t *ppos)
{
struct omap_iommu *obj = file->private_data;
char *p, *buf;
ssize_t bytes;
if (is_omap_iommu_detached(obj))
return -EPERM;
buf = kmalloc(count, GFP_KERNEL);
if (!buf)
return -ENOMEM;
p = buf;
mutex_lock(&iommu_debug_lock);
bytes = omap_iommu_dump_ctx(obj, p, count);
bytes = simple_read_from_buffer(userbuf, count, ppos, buf, bytes);
mutex_unlock(&iommu_debug_lock);
kfree(buf);
return bytes;
}
static ssize_t debug_read_tlb(struct file *file, char __user *userbuf,
size_t count, loff_t *ppos)
{
struct omap_iommu *obj = file->private_data;
char *p, *buf;
ssize_t bytes, rest;
if (is_omap_iommu_detached(obj))
return -EPERM;
buf = kmalloc(count, GFP_KERNEL);
if (!buf)
return -ENOMEM;
p = buf;
mutex_lock(&iommu_debug_lock);
p += sprintf(p, "%8s %8s\n", "cam:", "ram:");
p += sprintf(p, "-----------------------------------------\n");
rest = count - (p - buf);
p += omap_dump_tlb_entries(obj, p, rest);
bytes = simple_read_from_buffer(userbuf, count, ppos, buf, p - buf);
mutex_unlock(&iommu_debug_lock);
kfree(buf);
return bytes;
}
static void dump_ioptable(struct seq_file *s)
{
int i, j;
u32 da;
u32 *iopgd, *iopte;
struct omap_iommu *obj = s->private;
spin_lock(&obj->page_table_lock);
iopgd = iopgd_offset(obj, 0);
for (i = 0; i < PTRS_PER_IOPGD; i++, iopgd++) {
if (!*iopgd)
continue;
if (!(*iopgd & IOPGD_TABLE)) {
da = i << IOPGD_SHIFT;
seq_printf(s, "1: 0x%08x 0x%08x\n", da, *iopgd);
continue;
}
iopte = iopte_offset(iopgd, 0);
for (j = 0; j < PTRS_PER_IOPTE; j++, iopte++) {
if (!*iopte)
continue;
da = (i << IOPGD_SHIFT) + (j << IOPTE_SHIFT);
seq_printf(s, "2: 0x%08x 0x%08x\n", da, *iopte);
}
}
spin_unlock(&obj->page_table_lock);
}
static int debug_read_pagetable(struct seq_file *s, void *data)
{
struct omap_iommu *obj = s->private;
if (is_omap_iommu_detached(obj))
return -EPERM;
mutex_lock(&iommu_debug_lock);
seq_printf(s, "L: %8s %8s\n", "da:", "pte:");
seq_puts(s, "--------------------------\n");
dump_ioptable(s);
mutex_unlock(&iommu_debug_lock);
return 0;
}
void omap_iommu_debugfs_add(struct omap_iommu *obj)
{
struct dentry *d;
if (!iommu_debug_root)
return;
obj->debug_dir = debugfs_create_dir(obj->name, iommu_debug_root);
if (!obj->debug_dir)
return;
d = debugfs_create_u8("nr_tlb_entries", 0400, obj->debug_dir,
(u8 *)&obj->nr_tlb_entries);
if (!d)
return;
DEBUG_ADD_FILE_RO(regs);
DEBUG_ADD_FILE_RO(tlb);
DEBUG_ADD_FILE_RO(pagetable);
return;
err:
debugfs_remove_recursive(obj->debug_dir);
}
void omap_iommu_debugfs_remove(struct omap_iommu *obj)
{
if (!obj->debug_dir)
return;
debugfs_remove_recursive(obj->debug_dir);
}
void __init omap_iommu_debugfs_init(void)
{
iommu_debug_root = debugfs_create_dir("omap_iommu", NULL);
if (!iommu_debug_root)
pr_err("can't create debugfs dir\n");
}
void __exit omap_iommu_debugfs_exit(void)
{
debugfs_remove(iommu_debug_root);
}
