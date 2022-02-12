static unsigned long init_dump_header(struct phyp_dump_header *ph)
{
unsigned long addr_offset = 0;
ph->version = DUMP_HEADER_VERSION;
ph->num_of_sections = NUM_DUMP_SECTIONS;
ph->status = 0;
ph->first_offset_section =
(u32)offsetof(struct phyp_dump_header, cpu_data);
ph->dump_disk_section = 0;
ph->block_num_dd = 0;
ph->num_of_blocks_dd = 0;
ph->offset_dd = 0;
ph->maxtime_to_auto = 0;
ph->cpu_data.dump_flags = DUMP_REQUEST_FLAG;
ph->cpu_data.source_type = DUMP_SOURCE_CPU;
ph->cpu_data.source_address = 0;
ph->cpu_data.source_length = phyp_dump_info->cpu_state_size;
ph->cpu_data.destination_address = addr_offset;
addr_offset += phyp_dump_info->cpu_state_size;
ph->hpte_data.dump_flags = DUMP_REQUEST_FLAG;
ph->hpte_data.source_type = DUMP_SOURCE_HPTE;
ph->hpte_data.source_address = 0;
ph->hpte_data.source_length = phyp_dump_info->hpte_region_size;
ph->hpte_data.destination_address = addr_offset;
addr_offset += phyp_dump_info->hpte_region_size;
ph->kernel_data.dump_flags = DUMP_REQUEST_FLAG;
ph->kernel_data.source_type = DUMP_SOURCE_RMO;
ph->kernel_data.source_address = PHYP_DUMP_RMR_START;
ph->kernel_data.source_length = PHYP_DUMP_RMR_END;
ph->kernel_data.destination_address = addr_offset;
addr_offset += ph->kernel_data.source_length;
return addr_offset;
}
static void print_dump_header(const struct phyp_dump_header *ph)
{
#ifdef DEBUG
if (ph == NULL)
return;
printk(KERN_INFO "dump header:\n");
printk(KERN_INFO "version = %d\n", ph->version);
printk(KERN_INFO "Sections = %d\n", ph->num_of_sections);
printk(KERN_INFO "Status = 0x%x\n", ph->status);
printk(KERN_INFO "Offset to first section 0x%x\n",
ph->first_offset_section);
printk(KERN_INFO "dump disk sections should be zero\n");
printk(KERN_INFO "dump disk section = %d\n", ph->dump_disk_section);
printk(KERN_INFO "block num = %lld\n", ph->block_num_dd);
printk(KERN_INFO "number of blocks = %lld\n", ph->num_of_blocks_dd);
printk(KERN_INFO "dump disk offset = %d\n", ph->offset_dd);
printk(KERN_INFO "Max auto time= %d\n", ph->maxtime_to_auto);
printk(KERN_INFO " CPU AREA\n");
printk(KERN_INFO "cpu dump_flags =%d\n", ph->cpu_data.dump_flags);
printk(KERN_INFO "cpu source_type =%d\n", ph->cpu_data.source_type);
printk(KERN_INFO "cpu error_flags =%d\n", ph->cpu_data.error_flags);
printk(KERN_INFO "cpu source_address =%llx\n",
ph->cpu_data.source_address);
printk(KERN_INFO "cpu source_length =%llx\n",
ph->cpu_data.source_length);
printk(KERN_INFO "cpu length_copied =%llx\n",
ph->cpu_data.length_copied);
printk(KERN_INFO " HPTE AREA\n");
printk(KERN_INFO "HPTE dump_flags =%d\n", ph->hpte_data.dump_flags);
printk(KERN_INFO "HPTE source_type =%d\n", ph->hpte_data.source_type);
printk(KERN_INFO "HPTE error_flags =%d\n", ph->hpte_data.error_flags);
printk(KERN_INFO "HPTE source_address =%llx\n",
ph->hpte_data.source_address);
printk(KERN_INFO "HPTE source_length =%llx\n",
ph->hpte_data.source_length);
printk(KERN_INFO "HPTE length_copied =%llx\n",
ph->hpte_data.length_copied);
printk(KERN_INFO " SRSD AREA\n");
printk(KERN_INFO "SRSD dump_flags =%d\n", ph->kernel_data.dump_flags);
printk(KERN_INFO "SRSD source_type =%d\n", ph->kernel_data.source_type);
printk(KERN_INFO "SRSD error_flags =%d\n", ph->kernel_data.error_flags);
printk(KERN_INFO "SRSD source_address =%llx\n",
ph->kernel_data.source_address);
printk(KERN_INFO "SRSD source_length =%llx\n",
ph->kernel_data.source_length);
printk(KERN_INFO "SRSD length_copied =%llx\n",
ph->kernel_data.length_copied);
#endif
}
static ssize_t show_phyp_dump_active(struct kobject *kobj,
struct kobj_attribute *attr, char *buf)
{
return sprintf(buf, "%lx\n", phyp_dump_info->phyp_dump_at_boot);
}
static void register_dump_area(struct phyp_dump_header *ph, unsigned long addr)
{
int rc;
if (ph->cpu_data.destination_address == 0) {
ph->cpu_data.destination_address += addr;
ph->hpte_data.destination_address += addr;
ph->kernel_data.destination_address += addr;
}
do {
rc = rtas_call(ibm_configure_kernel_dump, 3, 1, NULL,
1, ph, sizeof(struct phyp_dump_header));
} while (rtas_busy_delay(rc));
if (rc) {
printk(KERN_ERR "phyp-dump: unexpected error (%d) on "
"register\n", rc);
print_dump_header(ph);
return;
}
rc = sysfs_create_file(kernel_kobj, &pdl.attr);
if (rc)
printk(KERN_ERR "phyp-dump: unable to create sysfs"
" file (%d)\n", rc);
}
static
void invalidate_last_dump(struct phyp_dump_header *ph, unsigned long addr)
{
int rc;
if (ph->cpu_data.destination_address == 0) {
ph->cpu_data.destination_address += addr;
ph->hpte_data.destination_address += addr;
ph->kernel_data.destination_address += addr;
}
do {
rc = rtas_call(ibm_configure_kernel_dump, 3, 1, NULL,
2, ph, sizeof(struct phyp_dump_header));
} while (rtas_busy_delay(rc));
if (rc) {
printk(KERN_ERR "phyp-dump: unexpected error (%d) "
"on invalidate\n", rc);
print_dump_header(ph);
}
}
static void release_memory_range(unsigned long start_pfn,
unsigned long nr_pages)
{
struct page *rpage;
unsigned long end_pfn;
long i;
end_pfn = start_pfn + nr_pages;
for (i = start_pfn; i <= end_pfn; i++) {
rpage = pfn_to_page(i);
if (PageReserved(rpage)) {
ClearPageReserved(rpage);
init_page_count(rpage);
__free_page(rpage);
totalram_pages++;
}
}
}
static void
track_freed_range(unsigned long addr, unsigned long length)
{
static unsigned long scratch_area_size, reserved_area_size;
if (addr < phyp_dump_info->init_reserve_start)
return;
if ((addr >= phyp_dump_info->init_reserve_start) &&
(addr <= phyp_dump_info->init_reserve_start +
phyp_dump_info->init_reserve_size))
reserved_area_size += length;
if ((addr >= phyp_dump_info->reserved_scratch_addr) &&
(addr <= phyp_dump_info->reserved_scratch_addr +
phyp_dump_info->reserved_scratch_size))
scratch_area_size += length;
if ((reserved_area_size == phyp_dump_info->init_reserve_size) &&
(scratch_area_size == phyp_dump_info->reserved_scratch_size)) {
invalidate_last_dump(&phdr,
phyp_dump_info->reserved_scratch_addr);
register_dump_area(&phdr,
phyp_dump_info->reserved_scratch_addr);
}
}
static ssize_t store_release_region(struct kobject *kobj,
struct kobj_attribute *attr,
const char *buf, size_t count)
{
unsigned long start_addr, length, end_addr;
unsigned long start_pfn, nr_pages;
ssize_t ret;
ret = sscanf(buf, "%lx %lx", &start_addr, &length);
if (ret != 2)
return -EINVAL;
track_freed_range(start_addr, length);
if (start_addr < phyp_dump_info->init_reserve_start)
start_addr = phyp_dump_info->init_reserve_start;
end_addr = phyp_dump_info->init_reserve_start +
phyp_dump_info->init_reserve_size;
if (start_addr+length > end_addr)
length = end_addr - start_addr;
start_pfn = PFN_DOWN(start_addr);
nr_pages = PFN_DOWN(length);
release_memory_range(start_pfn, nr_pages);
return count;
}
static ssize_t show_release_region(struct kobject *kobj,
struct kobj_attribute *attr, char *buf)
{
u64 second_addr_range;
second_addr_range = phyp_dump_info->init_reserve_size -
phyp_dump_info->reserved_scratch_size;
return sprintf(buf, "CPU:0x%llx-0x%llx: HPTE:0x%llx-0x%llx:"
" DUMP:0x%llx-0x%llx, 0x%lx-0x%llx:\n",
phdr.cpu_data.destination_address,
phdr.cpu_data.length_copied,
phdr.hpte_data.destination_address,
phdr.hpte_data.length_copied,
phdr.kernel_data.destination_address,
phdr.kernel_data.length_copied,
phyp_dump_info->init_reserve_start,
second_addr_range);
}
static int __init phyp_dump_setup(void)
{
struct device_node *rtas;
const struct phyp_dump_header *dump_header = NULL;
unsigned long dump_area_start;
unsigned long dump_area_length;
int header_len = 0;
int rc;
if (phyp_dump_info->init_reserve_size == 0)
return 0;
if (!phyp_dump_info->phyp_dump_configured)
return -ENOSYS;
rtas = of_find_node_by_path("/rtas");
if (rtas) {
dump_header = of_get_property(rtas, "ibm,kernel-dump",
&header_len);
of_node_put(rtas);
}
ibm_configure_kernel_dump = rtas_token("ibm,configure-kernel-dump");
print_dump_header(dump_header);
dump_area_length = init_dump_header(&phdr);
dump_area_start = phyp_dump_info->init_reserve_start & PAGE_MASK;
if (dump_header == NULL) {
register_dump_area(&phdr, dump_area_start);
return 0;
}
if ((dump_header) && (dump_header->status & DUMP_ERROR_FLAG)) {
invalidate_last_dump(&phdr, dump_area_start);
register_dump_area(&phdr, dump_area_start);
return 0;
}
if (dump_header) {
phyp_dump_info->reserved_scratch_addr =
dump_header->cpu_data.destination_address;
phyp_dump_info->reserved_scratch_size =
dump_header->cpu_data.source_length +
dump_header->hpte_data.source_length +
dump_header->kernel_data.source_length;
}
rc = sysfs_create_file(kernel_kobj, &rr.attr);
if (rc)
printk(KERN_ERR "phyp-dump: unable to create sysfs file (%d)\n",
rc);
return 0;
}
int __init early_init_dt_scan_phyp_dump(unsigned long node,
const char *uname, int depth, void *data)
{
const unsigned int *sizes;
phyp_dump_info->phyp_dump_configured = 0;
phyp_dump_info->phyp_dump_is_active = 0;
if (depth != 1 || strcmp(uname, "rtas") != 0)
return 0;
if (of_get_flat_dt_prop(node, "ibm,configure-kernel-dump", NULL))
phyp_dump_info->phyp_dump_configured++;
if (of_get_flat_dt_prop(node, "ibm,dump-kernel", NULL))
phyp_dump_info->phyp_dump_is_active++;
sizes = of_get_flat_dt_prop(node, "ibm,configure-kernel-dump-sizes",
NULL);
if (!sizes)
return 0;
if (sizes[0] == 1)
phyp_dump_info->cpu_state_size = *((unsigned long *)&sizes[1]);
if (sizes[3] == 2)
phyp_dump_info->hpte_region_size =
*((unsigned long *)&sizes[4]);
return 1;
}
static int __init early_phyp_dump_enabled(char *p)
{
phyp_dump_info->phyp_dump_at_boot = 1;
if (!p)
return 0;
if (strncmp(p, "1", 1) == 0)
phyp_dump_info->phyp_dump_at_boot = 1;
else if (strncmp(p, "0", 1) == 0)
phyp_dump_info->phyp_dump_at_boot = 0;
return 0;
}
static int __init early_phyp_dump_reserve_size(char *p)
{
if (p)
phyp_dump_info->reserve_bootvar = memparse(p, &p);
return 0;
}
