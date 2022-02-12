int __init init_maps(unsigned long physmem, unsigned long iomem,
unsigned long highmem)
{
struct page *p, *map;
unsigned long phys_len, phys_pages, highmem_len, highmem_pages;
unsigned long iomem_len, iomem_pages, total_len, total_pages;
int i;
phys_pages = physmem >> PAGE_SHIFT;
phys_len = phys_pages * sizeof(struct page);
iomem_pages = iomem >> PAGE_SHIFT;
iomem_len = iomem_pages * sizeof(struct page);
highmem_pages = highmem >> PAGE_SHIFT;
highmem_len = highmem_pages * sizeof(struct page);
total_pages = phys_pages + iomem_pages + highmem_pages;
total_len = phys_len + iomem_len + highmem_len;
map = alloc_bootmem_low_pages(total_len);
if (map == NULL)
return -ENOMEM;
for (i = 0; i < total_pages; i++) {
p = &map[i];
memset(p, 0, sizeof(struct page));
SetPageReserved(p);
INIT_LIST_HEAD(&p->lru);
}
max_mapnr = total_pages;
return 0;
}
void map_memory(unsigned long virt, unsigned long phys, unsigned long len,
int r, int w, int x)
{
__u64 offset;
int fd, err;
fd = phys_mapping(phys, &offset);
err = os_map_memory((void *) virt, fd, offset, len, r, w, x);
if (err) {
if (err == -ENOMEM)
printk(KERN_ERR "try increasing the host's "
"/proc/sys/vm/max_map_count to <physical "
"memory size>/4096\n");
panic("map_memory(0x%lx, %d, 0x%llx, %ld, %d, %d, %d) failed, "
"err = %d\n", virt, fd, offset, len, r, w, x, err);
}
}
void __init setup_physmem(unsigned long start, unsigned long reserve_end,
unsigned long len, unsigned long long highmem)
{
unsigned long reserve = reserve_end - start;
int pfn = PFN_UP(__pa(reserve_end));
int delta = (len - reserve) >> PAGE_SHIFT;
int err, offset, bootmap_size;
physmem_fd = create_mem_file(len + highmem);
offset = uml_reserved - uml_physmem;
err = os_map_memory((void *) uml_reserved, physmem_fd, offset,
len - offset, 1, 1, 1);
if (err < 0) {
printf("setup_physmem - mapping %ld bytes of memory at 0x%p "
"failed - errno = %d\n", len - offset,
(void *) uml_reserved, err);
exit(1);
}
os_seek_file(physmem_fd, __pa(&__syscall_stub_start));
os_write_file(physmem_fd, &__syscall_stub_start, PAGE_SIZE);
os_fsync_file(physmem_fd);
bootmap_size = init_bootmem(pfn, pfn + delta);
free_bootmem(__pa(reserve_end) + bootmap_size,
len - bootmap_size - reserve);
}
int phys_mapping(unsigned long phys, unsigned long long *offset_out)
{
int fd = -1;
if (phys < physmem_size) {
fd = physmem_fd;
*offset_out = phys;
}
else if (phys < __pa(end_iomem)) {
struct iomem_region *region = iomem_regions;
while (region != NULL) {
if ((phys >= region->phys) &&
(phys < region->phys + region->size)) {
fd = region->fd;
*offset_out = phys - region->phys;
break;
}
region = region->next;
}
}
else if (phys < __pa(end_iomem) + highmem) {
fd = physmem_fd;
*offset_out = phys - iomem_size;
}
return fd;
}
static int __init uml_mem_setup(char *line, int *add)
{
char *retptr;
physmem_size = memparse(line,&retptr);
return 0;
}
unsigned long find_iomem(char *driver, unsigned long *len_out)
{
struct iomem_region *region = iomem_regions;
while (region != NULL) {
if (!strcmp(region->driver, driver)) {
*len_out = region->size;
return region->virt;
}
region = region->next;
}
return 0;
}
static int setup_iomem(void)
{
struct iomem_region *region = iomem_regions;
unsigned long iomem_start = high_physmem + PAGE_SIZE;
int err;
while (region != NULL) {
err = os_map_memory((void *) iomem_start, region->fd, 0,
region->size, 1, 1, 0);
if (err)
printk(KERN_ERR "Mapping iomem region for driver '%s' "
"failed, errno = %d\n", region->driver, -err);
else {
region->virt = iomem_start;
region->phys = __pa(region->virt);
}
iomem_start += region->size + PAGE_SIZE;
region = region->next;
}
return 0;
}
