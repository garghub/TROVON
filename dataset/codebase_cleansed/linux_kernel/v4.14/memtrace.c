static ssize_t memtrace_read(struct file *filp, char __user *ubuf,
size_t count, loff_t *ppos)
{
struct memtrace_entry *ent = filp->private_data;
return simple_read_from_buffer(ubuf, count, ppos, ent->mem, ent->size);
}
static bool valid_memtrace_range(struct memtrace_entry *dev,
unsigned long start, unsigned long size)
{
if ((start >= dev->start) &&
((start + size) <= (dev->start + dev->size)))
return true;
return false;
}
static int memtrace_mmap(struct file *filp, struct vm_area_struct *vma)
{
unsigned long size = vma->vm_end - vma->vm_start;
struct memtrace_entry *dev = filp->private_data;
if (!valid_memtrace_range(dev, vma->vm_pgoff << PAGE_SHIFT, size))
return -EINVAL;
vma->vm_page_prot = pgprot_noncached(vma->vm_page_prot);
if (remap_pfn_range(vma, vma->vm_start,
vma->vm_pgoff + (dev->start >> PAGE_SHIFT),
size, vma->vm_page_prot))
return -EAGAIN;
return 0;
}
static void flush_memory_region(u64 base, u64 size)
{
unsigned long line_size = ppc64_caches.l1d.size;
u64 end = base + size;
u64 addr;
base = round_down(base, line_size);
end = round_up(end, line_size);
for (addr = base; addr < end; addr += line_size)
asm volatile("dcbf 0,%0" : "=r" (addr) :: "memory");
}
static int check_memblock_online(struct memory_block *mem, void *arg)
{
if (mem->state != MEM_ONLINE)
return -1;
return 0;
}
static int change_memblock_state(struct memory_block *mem, void *arg)
{
unsigned long state = (unsigned long)arg;
mem->state = state;
return 0;
}
static bool memtrace_offline_pages(u32 nid, u64 start_pfn, u64 nr_pages)
{
u64 end_pfn = start_pfn + nr_pages - 1;
if (walk_memory_range(start_pfn, end_pfn, NULL,
check_memblock_online))
return false;
walk_memory_range(start_pfn, end_pfn, (void *)MEM_GOING_OFFLINE,
change_memblock_state);
if (offline_pages(start_pfn, nr_pages)) {
walk_memory_range(start_pfn, end_pfn, (void *)MEM_ONLINE,
change_memblock_state);
return false;
}
walk_memory_range(start_pfn, end_pfn, (void *)MEM_OFFLINE,
change_memblock_state);
flush_memory_region((u64)__va(start_pfn << PAGE_SHIFT),
nr_pages << PAGE_SHIFT);
lock_device_hotplug();
remove_memory(nid, start_pfn << PAGE_SHIFT, nr_pages << PAGE_SHIFT);
unlock_device_hotplug();
return true;
}
static u64 memtrace_alloc_node(u32 nid, u64 size)
{
u64 start_pfn, end_pfn, nr_pages;
u64 base_pfn;
if (!NODE_DATA(nid) || !node_spanned_pages(nid))
return 0;
start_pfn = node_start_pfn(nid);
end_pfn = node_end_pfn(nid);
nr_pages = size >> PAGE_SHIFT;
end_pfn = round_down(end_pfn - nr_pages, nr_pages);
for (base_pfn = end_pfn; base_pfn > start_pfn; base_pfn -= nr_pages) {
if (memtrace_offline_pages(nid, base_pfn, nr_pages) == true)
return base_pfn << PAGE_SHIFT;
}
return 0;
}
static int memtrace_init_regions_runtime(u64 size)
{
u32 nid;
u64 m;
memtrace_array = kcalloc(num_online_nodes(),
sizeof(struct memtrace_entry), GFP_KERNEL);
if (!memtrace_array) {
pr_err("Failed to allocate memtrace_array\n");
return -EINVAL;
}
for_each_online_node(nid) {
m = memtrace_alloc_node(nid, size);
if (!m) {
pr_err("Failed to allocate trace memory on node %d\n", nid);
continue;
}
pr_info("Allocated trace memory on node %d at 0x%016llx\n", nid, m);
memtrace_array[memtrace_array_nr].start = m;
memtrace_array[memtrace_array_nr].size = size;
memtrace_array[memtrace_array_nr].nid = nid;
memtrace_array_nr++;
}
return 0;
}
static int memtrace_init_debugfs(void)
{
int ret = 0;
int i;
for (i = 0; i < memtrace_array_nr; i++) {
struct dentry *dir;
struct memtrace_entry *ent = &memtrace_array[i];
ent->mem = ioremap(ent->start, ent->size);
if (!ent->mem) {
pr_err("Failed to map trace memory at 0x%llx\n",
ent->start);
ret = -1;
continue;
}
snprintf(ent->name, 16, "%08x", ent->nid);
dir = debugfs_create_dir(ent->name, memtrace_debugfs_dir);
if (!dir)
return -1;
ent->dir = dir;
debugfs_create_file("trace", 0400, dir, ent, &memtrace_fops);
debugfs_create_x64("start", 0400, dir, &ent->start);
debugfs_create_x64("size", 0400, dir, &ent->size);
}
return ret;
}
static int memtrace_enable_set(void *data, u64 val)
{
if (memtrace_size)
return -EINVAL;
if (!val)
return -EINVAL;
if (val & (memory_block_size_bytes() - 1))
return -EINVAL;
if (memtrace_init_regions_runtime(val))
return -EINVAL;
if (memtrace_init_debugfs())
return -EINVAL;
memtrace_size = val;
return 0;
}
static int memtrace_enable_get(void *data, u64 *val)
{
*val = memtrace_size;
return 0;
}
static int memtrace_init(void)
{
memtrace_debugfs_dir = debugfs_create_dir("memtrace",
powerpc_debugfs_root);
if (!memtrace_debugfs_dir)
return -1;
debugfs_create_file("enable", 0600, memtrace_debugfs_dir,
NULL, &memtrace_init_fops);
return 0;
}
