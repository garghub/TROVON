static inline bool is_omap_iommu_detached(struct omap_iommu *obj)
{
return !obj->domain;
}
static ssize_t
omap2_iommu_dump_ctx(struct omap_iommu *obj, char *buf, ssize_t len)
{
char *p = buf;
pr_reg(REVISION);
pr_reg(IRQSTATUS);
pr_reg(IRQENABLE);
pr_reg(WALKING_ST);
pr_reg(CNTL);
pr_reg(FAULT_AD);
pr_reg(TTB);
pr_reg(LOCK);
pr_reg(LD_TLB);
pr_reg(CAM);
pr_reg(RAM);
pr_reg(GFLUSH);
pr_reg(FLUSH_ENTRY);
pr_reg(READ_CAM);
pr_reg(READ_RAM);
pr_reg(EMU_FAULT_AD);
out:
return p - buf;
}
static ssize_t omap_iommu_dump_ctx(struct omap_iommu *obj, char *buf,
ssize_t bytes)
{
if (!obj || !buf)
return -EINVAL;
pm_runtime_get_sync(obj->dev);
bytes = omap2_iommu_dump_ctx(obj, buf, bytes);
pm_runtime_put_sync(obj->dev);
return bytes;
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
static int
__dump_tlb_entries(struct omap_iommu *obj, struct cr_regs *crs, int num)
{
int i;
struct iotlb_lock saved;
struct cr_regs tmp;
struct cr_regs *p = crs;
pm_runtime_get_sync(obj->dev);
iotlb_lock_get(obj, &saved);
for_each_iotlb_cr(obj, num, i, tmp) {
if (!iotlb_cr_valid(&tmp))
continue;
*p++ = tmp;
}
iotlb_lock_set(obj, &saved);
pm_runtime_put_sync(obj->dev);
return p - crs;
}
static ssize_t iotlb_dump_cr(struct omap_iommu *obj, struct cr_regs *cr,
struct seq_file *s)
{
seq_printf(s, "%08x %08x %01x\n", cr->cam, cr->ram,
(cr->cam & MMU_CAM_P) ? 1 : 0);
return 0;
}
static size_t omap_dump_tlb_entries(struct omap_iommu *obj, struct seq_file *s)
{
int i, num;
struct cr_regs *cr;
num = obj->nr_tlb_entries;
cr = kcalloc(num, sizeof(*cr), GFP_KERNEL);
if (!cr)
return 0;
num = __dump_tlb_entries(obj, cr, num);
for (i = 0; i < num; i++)
iotlb_dump_cr(obj, cr + i, s);
kfree(cr);
return 0;
}
static int debug_read_tlb(struct seq_file *s, void *data)
{
struct omap_iommu *obj = s->private;
if (is_omap_iommu_detached(obj))
return -EPERM;
mutex_lock(&iommu_debug_lock);
seq_printf(s, "%8s %8s\n", "cam:", "ram:");
seq_puts(s, "-----------------------------------------\n");
omap_dump_tlb_entries(obj, s);
mutex_unlock(&iommu_debug_lock);
return 0;
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
