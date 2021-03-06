void
efi_gettimeofday (struct timespec *ts)
{
efi_time_t tm;
if ((*efi.get_time)(&tm, NULL) != EFI_SUCCESS) {
memset(ts, 0, sizeof(*ts));
return;
}
ts->tv_sec = mktime(tm.year, tm.month, tm.day,
tm.hour, tm.minute, tm.second);
ts->tv_nsec = tm.nanosecond;
}
static int
is_memory_available (efi_memory_desc_t *md)
{
if (!(md->attribute & EFI_MEMORY_WB))
return 0;
switch (md->type) {
case EFI_LOADER_CODE:
case EFI_LOADER_DATA:
case EFI_BOOT_SERVICES_CODE:
case EFI_BOOT_SERVICES_DATA:
case EFI_CONVENTIONAL_MEMORY:
return 1;
}
return 0;
}
static inline u64
kmd_end(kern_memdesc_t *kmd)
{
return (kmd->start + (kmd->num_pages << EFI_PAGE_SHIFT));
}
static inline u64
efi_md_end(efi_memory_desc_t *md)
{
return (md->phys_addr + efi_md_size(md));
}
static inline int
efi_wb(efi_memory_desc_t *md)
{
return (md->attribute & EFI_MEMORY_WB);
}
static inline int
efi_uc(efi_memory_desc_t *md)
{
return (md->attribute & EFI_MEMORY_UC);
}
static void
walk (efi_freemem_callback_t callback, void *arg, u64 attr)
{
kern_memdesc_t *k;
u64 start, end, voff;
voff = (attr == EFI_MEMORY_WB) ? PAGE_OFFSET : __IA64_UNCACHED_OFFSET;
for (k = kern_memmap; k->start != ~0UL; k++) {
if (k->attribute != attr)
continue;
start = PAGE_ALIGN(k->start);
end = (k->start + (k->num_pages << EFI_PAGE_SHIFT)) & PAGE_MASK;
if (start < end)
if ((*callback)(start + voff, end + voff, arg) < 0)
return;
}
}
void
efi_memmap_walk (efi_freemem_callback_t callback, void *arg)
{
walk(callback, arg, EFI_MEMORY_WB);
}
void
efi_memmap_walk_uc (efi_freemem_callback_t callback, void *arg)
{
walk(callback, arg, EFI_MEMORY_UC);
}
void *
efi_get_pal_addr (void)
{
void *efi_map_start, *efi_map_end, *p;
efi_memory_desc_t *md;
u64 efi_desc_size;
int pal_code_count = 0;
u64 vaddr, mask;
efi_map_start = __va(ia64_boot_param->efi_memmap);
efi_map_end = efi_map_start + ia64_boot_param->efi_memmap_size;
efi_desc_size = ia64_boot_param->efi_memdesc_size;
for (p = efi_map_start; p < efi_map_end; p += efi_desc_size) {
md = p;
if (md->type != EFI_PAL_CODE)
continue;
if (++pal_code_count > 1) {
printk(KERN_ERR "Too many EFI Pal Code memory ranges, "
"dropped @ %llx\n", md->phys_addr);
continue;
}
mask = ~((1 << KERNEL_TR_PAGE_SHIFT) - 1);
vaddr = PAGE_OFFSET + md->phys_addr;
if ((vaddr & mask) == (KERNEL_START & mask)) {
printk(KERN_INFO "%s: no need to install ITR for PAL code\n",
__func__);
continue;
}
if (efi_md_size(md) > IA64_GRANULE_SIZE)
panic("Whoa! PAL code size bigger than a granule!");
#if EFI_DEBUG
mask = ~((1 << IA64_GRANULE_SHIFT) - 1);
printk(KERN_INFO "CPU %d: mapping PAL code "
"[0x%lx-0x%lx) into [0x%lx-0x%lx)\n",
smp_processor_id(), md->phys_addr,
md->phys_addr + efi_md_size(md),
vaddr & mask, (vaddr & mask) + IA64_GRANULE_SIZE);
#endif
return __va(md->phys_addr);
}
printk(KERN_WARNING "%s: no PAL-code memory-descriptor found\n",
__func__);
return NULL;
}
static u8 __init palo_checksum(u8 *buffer, u32 length)
{
u8 sum = 0;
u8 *end = buffer + length;
while (buffer < end)
sum = (u8) (sum + *(buffer++));
return sum;
}
static void __init handle_palo(unsigned long palo_phys)
{
struct palo_table *palo = __va(palo_phys);
u8 checksum;
if (strncmp(palo->signature, PALO_SIG, sizeof(PALO_SIG) - 1)) {
printk(KERN_INFO "PALO signature incorrect.\n");
return;
}
checksum = palo_checksum((u8 *)palo, palo->length);
if (checksum) {
printk(KERN_INFO "PALO checksum incorrect.\n");
return;
}
setup_ptcg_sem(palo->max_tlb_purges, NPTCG_FROM_PALO);
}
void
efi_map_pal_code (void)
{
void *pal_vaddr = efi_get_pal_addr ();
u64 psr;
if (!pal_vaddr)
return;
psr = ia64_clear_ic();
ia64_itr(0x1, IA64_TR_PALCODE,
GRANULEROUNDDOWN((unsigned long) pal_vaddr),
pte_val(pfn_pte(__pa(pal_vaddr) >> PAGE_SHIFT, PAGE_KERNEL)),
IA64_GRANULE_SHIFT);
paravirt_dv_serialize_data();
ia64_set_psr(psr);
}
void __init
efi_init (void)
{
void *efi_map_start, *efi_map_end;
efi_config_table_t *config_tables;
efi_char16_t *c16;
u64 efi_desc_size;
char *cp, vendor[100] = "unknown";
int i;
unsigned long palo_phys;
for (cp = boot_command_line; *cp; ) {
if (memcmp(cp, "mem=", 4) == 0) {
mem_limit = memparse(cp + 4, &cp);
} else if (memcmp(cp, "max_addr=", 9) == 0) {
max_addr = GRANULEROUNDDOWN(memparse(cp + 9, &cp));
} else if (memcmp(cp, "min_addr=", 9) == 0) {
min_addr = GRANULEROUNDDOWN(memparse(cp + 9, &cp));
} else {
while (*cp != ' ' && *cp)
++cp;
while (*cp == ' ')
++cp;
}
}
if (min_addr != 0UL)
printk(KERN_INFO "Ignoring memory below %lluMB\n",
min_addr >> 20);
if (max_addr != ~0UL)
printk(KERN_INFO "Ignoring memory above %lluMB\n",
max_addr >> 20);
efi.systab = __va(ia64_boot_param->efi_systab);
if (efi.systab == NULL)
panic("Whoa! Can't find EFI system table.\n");
if (efi.systab->hdr.signature != EFI_SYSTEM_TABLE_SIGNATURE)
panic("Whoa! EFI system table signature incorrect\n");
if ((efi.systab->hdr.revision >> 16) == 0)
printk(KERN_WARNING "Warning: EFI system table version "
"%d.%02d, expected 1.00 or greater\n",
efi.systab->hdr.revision >> 16,
efi.systab->hdr.revision & 0xffff);
config_tables = __va(efi.systab->tables);
c16 = __va(efi.systab->fw_vendor);
if (c16) {
for (i = 0;i < (int) sizeof(vendor) - 1 && *c16; ++i)
vendor[i] = *c16++;
vendor[i] = '\0';
}
printk(KERN_INFO "EFI v%u.%.02u by %s:",
efi.systab->hdr.revision >> 16,
efi.systab->hdr.revision & 0xffff, vendor);
efi.mps = EFI_INVALID_TABLE_ADDR;
efi.acpi = EFI_INVALID_TABLE_ADDR;
efi.acpi20 = EFI_INVALID_TABLE_ADDR;
efi.smbios = EFI_INVALID_TABLE_ADDR;
efi.sal_systab = EFI_INVALID_TABLE_ADDR;
efi.boot_info = EFI_INVALID_TABLE_ADDR;
efi.hcdp = EFI_INVALID_TABLE_ADDR;
efi.uga = EFI_INVALID_TABLE_ADDR;
palo_phys = EFI_INVALID_TABLE_ADDR;
for (i = 0; i < (int) efi.systab->nr_tables; i++) {
if (efi_guidcmp(config_tables[i].guid, MPS_TABLE_GUID) == 0) {
efi.mps = config_tables[i].table;
printk(" MPS=0x%lx", config_tables[i].table);
} else if (efi_guidcmp(config_tables[i].guid, ACPI_20_TABLE_GUID) == 0) {
efi.acpi20 = config_tables[i].table;
printk(" ACPI 2.0=0x%lx", config_tables[i].table);
} else if (efi_guidcmp(config_tables[i].guid, ACPI_TABLE_GUID) == 0) {
efi.acpi = config_tables[i].table;
printk(" ACPI=0x%lx", config_tables[i].table);
} else if (efi_guidcmp(config_tables[i].guid, SMBIOS_TABLE_GUID) == 0) {
efi.smbios = config_tables[i].table;
printk(" SMBIOS=0x%lx", config_tables[i].table);
} else if (efi_guidcmp(config_tables[i].guid, SAL_SYSTEM_TABLE_GUID) == 0) {
efi.sal_systab = config_tables[i].table;
printk(" SALsystab=0x%lx", config_tables[i].table);
} else if (efi_guidcmp(config_tables[i].guid, HCDP_TABLE_GUID) == 0) {
efi.hcdp = config_tables[i].table;
printk(" HCDP=0x%lx", config_tables[i].table);
} else if (efi_guidcmp(config_tables[i].guid,
PROCESSOR_ABSTRACTION_LAYER_OVERWRITE_GUID) == 0) {
palo_phys = config_tables[i].table;
printk(" PALO=0x%lx", config_tables[i].table);
}
}
printk("\n");
if (palo_phys != EFI_INVALID_TABLE_ADDR)
handle_palo(palo_phys);
runtime = __va(efi.systab->runtime);
efi.get_time = phys_get_time;
efi.set_time = phys_set_time;
efi.get_wakeup_time = phys_get_wakeup_time;
efi.set_wakeup_time = phys_set_wakeup_time;
efi.get_variable = phys_get_variable;
efi.get_next_variable = phys_get_next_variable;
efi.set_variable = phys_set_variable;
efi.get_next_high_mono_count = phys_get_next_high_mono_count;
efi.reset_system = phys_reset_system;
efi_map_start = __va(ia64_boot_param->efi_memmap);
efi_map_end = efi_map_start + ia64_boot_param->efi_memmap_size;
efi_desc_size = ia64_boot_param->efi_memdesc_size;
#if EFI_DEBUG
{
efi_memory_desc_t *md;
void *p;
for (i = 0, p = efi_map_start; p < efi_map_end;
++i, p += efi_desc_size)
{
const char *unit;
unsigned long size;
md = p;
size = md->num_pages << EFI_PAGE_SHIFT;
if ((size >> 40) > 0) {
size >>= 40;
unit = "TB";
} else if ((size >> 30) > 0) {
size >>= 30;
unit = "GB";
} else if ((size >> 20) > 0) {
size >>= 20;
unit = "MB";
} else {
size >>= 10;
unit = "KB";
}
printk("mem%02d: type=%2u, attr=0x%016lx, "
"range=[0x%016lx-0x%016lx) (%4lu%s)\n",
i, md->type, md->attribute, md->phys_addr,
md->phys_addr + efi_md_size(md), size, unit);
}
}
#endif
efi_map_pal_code();
efi_enter_virtual_mode();
}
void
efi_enter_virtual_mode (void)
{
void *efi_map_start, *efi_map_end, *p;
efi_memory_desc_t *md;
efi_status_t status;
u64 efi_desc_size;
efi_map_start = __va(ia64_boot_param->efi_memmap);
efi_map_end = efi_map_start + ia64_boot_param->efi_memmap_size;
efi_desc_size = ia64_boot_param->efi_memdesc_size;
for (p = efi_map_start; p < efi_map_end; p += efi_desc_size) {
md = p;
if (md->attribute & EFI_MEMORY_RUNTIME) {
if (md->attribute & EFI_MEMORY_WB) {
md->virt_addr = (u64) __va(md->phys_addr);
} else if (md->attribute & EFI_MEMORY_UC) {
md->virt_addr = (u64) ioremap(md->phys_addr, 0);
} else if (md->attribute & EFI_MEMORY_WC) {
#if 0
md->virt_addr = ia64_remap(md->phys_addr,
(_PAGE_A |
_PAGE_P |
_PAGE_D |
_PAGE_MA_WC |
_PAGE_PL_0 |
_PAGE_AR_RW));
#else
printk(KERN_INFO "EFI_MEMORY_WC mapping\n");
md->virt_addr = (u64) ioremap(md->phys_addr, 0);
#endif
} else if (md->attribute & EFI_MEMORY_WT) {
#if 0
md->virt_addr = ia64_remap(md->phys_addr,
(_PAGE_A |
_PAGE_P |
_PAGE_D |
_PAGE_MA_WT |
_PAGE_PL_0 |
_PAGE_AR_RW));
#else
printk(KERN_INFO "EFI_MEMORY_WT mapping\n");
md->virt_addr = (u64) ioremap(md->phys_addr, 0);
#endif
}
}
}
status = efi_call_phys(__va(runtime->set_virtual_address_map),
ia64_boot_param->efi_memmap_size,
efi_desc_size,
ia64_boot_param->efi_memdesc_version,
ia64_boot_param->efi_memmap);
if (status != EFI_SUCCESS) {
printk(KERN_WARNING "warning: unable to switch EFI into "
"virtual mode (status=%lu)\n", status);
return;
}
efi.get_time = virt_get_time;
efi.set_time = virt_set_time;
efi.get_wakeup_time = virt_get_wakeup_time;
efi.set_wakeup_time = virt_set_wakeup_time;
efi.get_variable = virt_get_variable;
efi.get_next_variable = virt_get_next_variable;
efi.set_variable = virt_set_variable;
efi.get_next_high_mono_count = virt_get_next_high_mono_count;
efi.reset_system = virt_reset_system;
}
u64
efi_get_iobase (void)
{
void *efi_map_start, *efi_map_end, *p;
efi_memory_desc_t *md;
u64 efi_desc_size;
efi_map_start = __va(ia64_boot_param->efi_memmap);
efi_map_end = efi_map_start + ia64_boot_param->efi_memmap_size;
efi_desc_size = ia64_boot_param->efi_memdesc_size;
for (p = efi_map_start; p < efi_map_end; p += efi_desc_size) {
md = p;
if (md->type == EFI_MEMORY_MAPPED_IO_PORT_SPACE) {
if (md->attribute & EFI_MEMORY_UC)
return md->phys_addr;
}
}
return 0;
}
static struct kern_memdesc *
kern_memory_descriptor (unsigned long phys_addr)
{
struct kern_memdesc *md;
for (md = kern_memmap; md->start != ~0UL; md++) {
if (phys_addr - md->start < (md->num_pages << EFI_PAGE_SHIFT))
return md;
}
return NULL;
}
static efi_memory_desc_t *
efi_memory_descriptor (unsigned long phys_addr)
{
void *efi_map_start, *efi_map_end, *p;
efi_memory_desc_t *md;
u64 efi_desc_size;
efi_map_start = __va(ia64_boot_param->efi_memmap);
efi_map_end = efi_map_start + ia64_boot_param->efi_memmap_size;
efi_desc_size = ia64_boot_param->efi_memdesc_size;
for (p = efi_map_start; p < efi_map_end; p += efi_desc_size) {
md = p;
if (phys_addr - md->phys_addr < efi_md_size(md))
return md;
}
return NULL;
}
static int
efi_memmap_intersects (unsigned long phys_addr, unsigned long size)
{
void *efi_map_start, *efi_map_end, *p;
efi_memory_desc_t *md;
u64 efi_desc_size;
unsigned long end;
efi_map_start = __va(ia64_boot_param->efi_memmap);
efi_map_end = efi_map_start + ia64_boot_param->efi_memmap_size;
efi_desc_size = ia64_boot_param->efi_memdesc_size;
end = phys_addr + size;
for (p = efi_map_start; p < efi_map_end; p += efi_desc_size) {
md = p;
if (md->phys_addr < end && efi_md_end(md) > phys_addr)
return 1;
}
return 0;
}
u32
efi_mem_type (unsigned long phys_addr)
{
efi_memory_desc_t *md = efi_memory_descriptor(phys_addr);
if (md)
return md->type;
return 0;
}
u64
efi_mem_attributes (unsigned long phys_addr)
{
efi_memory_desc_t *md = efi_memory_descriptor(phys_addr);
if (md)
return md->attribute;
return 0;
}
u64
efi_mem_attribute (unsigned long phys_addr, unsigned long size)
{
unsigned long end = phys_addr + size;
efi_memory_desc_t *md = efi_memory_descriptor(phys_addr);
u64 attr;
if (!md)
return 0;
attr = md->attribute & ~EFI_MEMORY_RUNTIME;
do {
unsigned long md_end = efi_md_end(md);
if (end <= md_end)
return attr;
md = efi_memory_descriptor(md_end);
if (!md || (md->attribute & ~EFI_MEMORY_RUNTIME) != attr)
return 0;
} while (md);
return 0;
}
u64
kern_mem_attribute (unsigned long phys_addr, unsigned long size)
{
unsigned long end = phys_addr + size;
struct kern_memdesc *md;
u64 attr;
if (!kern_memmap) {
attr = efi_mem_attribute(phys_addr, size);
if (attr & EFI_MEMORY_WB)
return EFI_MEMORY_WB;
return 0;
}
md = kern_memory_descriptor(phys_addr);
if (!md)
return 0;
attr = md->attribute;
do {
unsigned long md_end = kmd_end(md);
if (end <= md_end)
return attr;
md = kern_memory_descriptor(md_end);
if (!md || md->attribute != attr)
return 0;
} while (md);
return 0;
}
int
valid_phys_addr_range (unsigned long phys_addr, unsigned long size)
{
u64 attr;
attr = kern_mem_attribute(phys_addr, size);
if (attr & EFI_MEMORY_WB || attr & EFI_MEMORY_UC)
return 1;
return 0;
}
int
valid_mmap_phys_addr_range (unsigned long pfn, unsigned long size)
{
unsigned long phys_addr = pfn << PAGE_SHIFT;
u64 attr;
attr = efi_mem_attribute(phys_addr, size);
if (attr & EFI_MEMORY_WB || attr & EFI_MEMORY_UC)
return 1;
if (efi_memmap_intersects(phys_addr, size))
return 0;
return 1;
}
pgprot_t
phys_mem_access_prot(struct file *file, unsigned long pfn, unsigned long size,
pgprot_t vma_prot)
{
unsigned long phys_addr = pfn << PAGE_SHIFT;
u64 attr;
attr = kern_mem_attribute(phys_addr, size);
if (attr & EFI_MEMORY_WB)
return pgprot_cacheable(vma_prot);
else if (attr & EFI_MEMORY_UC)
return pgprot_noncached(vma_prot);
if (efi_mem_attribute(phys_addr, size) & EFI_MEMORY_WB)
return pgprot_cacheable(vma_prot);
return pgprot_noncached(vma_prot);
}
int __init
efi_uart_console_only(void)
{
efi_status_t status;
char *s, name[] = "ConOut";
efi_guid_t guid = EFI_GLOBAL_VARIABLE_GUID;
efi_char16_t *utf16, name_utf16[32];
unsigned char data[1024];
unsigned long size = sizeof(data);
struct efi_generic_dev_path *hdr, *end_addr;
int uart = 0;
utf16 = name_utf16;
s = name;
while (*s)
*utf16++ = *s++ & 0x7f;
*utf16 = 0;
status = efi.get_variable(name_utf16, &guid, NULL, &size, data);
if (status != EFI_SUCCESS) {
printk(KERN_ERR "No EFI %s variable?\n", name);
return 0;
}
hdr = (struct efi_generic_dev_path *) data;
end_addr = (struct efi_generic_dev_path *) ((u8 *) data + size);
while (hdr < end_addr) {
if (hdr->type == EFI_DEV_MSG &&
hdr->sub_type == EFI_DEV_MSG_UART)
uart = 1;
else if (hdr->type == EFI_DEV_END_PATH ||
hdr->type == EFI_DEV_END_PATH2) {
if (!uart)
return 0;
if (hdr->sub_type == EFI_DEV_END_ENTIRE)
return 1;
uart = 0;
}
hdr = (struct efi_generic_dev_path *)((u8 *) hdr + hdr->length);
}
printk(KERN_ERR "Malformed %s value\n", name);
return 0;
}
struct kern_memdesc *
find_memmap_space (void)
{
u64 contig_low=0, contig_high=0;
u64 as = 0, ae;
void *efi_map_start, *efi_map_end, *p, *q;
efi_memory_desc_t *md, *pmd = NULL, *check_md;
u64 space_needed, efi_desc_size;
unsigned long total_mem = 0;
efi_map_start = __va(ia64_boot_param->efi_memmap);
efi_map_end = efi_map_start + ia64_boot_param->efi_memmap_size;
efi_desc_size = ia64_boot_param->efi_memdesc_size;
space_needed = sizeof(kern_memdesc_t) *
(3 * (ia64_boot_param->efi_memmap_size/efi_desc_size) + 1);
for (p = efi_map_start; p < efi_map_end; pmd = md, p += efi_desc_size) {
md = p;
if (!efi_wb(md)) {
continue;
}
if (pmd == NULL || !efi_wb(pmd) ||
efi_md_end(pmd) != md->phys_addr) {
contig_low = GRANULEROUNDUP(md->phys_addr);
contig_high = efi_md_end(md);
for (q = p + efi_desc_size; q < efi_map_end;
q += efi_desc_size) {
check_md = q;
if (!efi_wb(check_md))
break;
if (contig_high != check_md->phys_addr)
break;
contig_high = efi_md_end(check_md);
}
contig_high = GRANULEROUNDDOWN(contig_high);
}
if (!is_memory_available(md) || md->type == EFI_LOADER_DATA)
continue;
as = max(contig_low, md->phys_addr);
ae = min(contig_high, efi_md_end(md));
as = max(as, min_addr);
ae = min(ae, max_addr);
if (ae <= as)
continue;
if (total_mem + (ae - as) > mem_limit)
ae -= total_mem + (ae - as) - mem_limit;
if (ae <= as)
continue;
if (ae - as > space_needed)
break;
}
if (p >= efi_map_end)
panic("Can't allocate space for kernel memory descriptors");
return __va(as);
}
unsigned long
efi_memmap_init(u64 *s, u64 *e)
{
struct kern_memdesc *k, *prev = NULL;
u64 contig_low=0, contig_high=0;
u64 as, ae, lim;
void *efi_map_start, *efi_map_end, *p, *q;
efi_memory_desc_t *md, *pmd = NULL, *check_md;
u64 efi_desc_size;
unsigned long total_mem = 0;
k = kern_memmap = find_memmap_space();
efi_map_start = __va(ia64_boot_param->efi_memmap);
efi_map_end = efi_map_start + ia64_boot_param->efi_memmap_size;
efi_desc_size = ia64_boot_param->efi_memdesc_size;
for (p = efi_map_start; p < efi_map_end; pmd = md, p += efi_desc_size) {
md = p;
if (!efi_wb(md)) {
if (efi_uc(md) &&
(md->type == EFI_CONVENTIONAL_MEMORY ||
md->type == EFI_BOOT_SERVICES_DATA)) {
k->attribute = EFI_MEMORY_UC;
k->start = md->phys_addr;
k->num_pages = md->num_pages;
k++;
}
continue;
}
if (pmd == NULL || !efi_wb(pmd) ||
efi_md_end(pmd) != md->phys_addr) {
contig_low = GRANULEROUNDUP(md->phys_addr);
contig_high = efi_md_end(md);
for (q = p + efi_desc_size; q < efi_map_end;
q += efi_desc_size) {
check_md = q;
if (!efi_wb(check_md))
break;
if (contig_high != check_md->phys_addr)
break;
contig_high = efi_md_end(check_md);
}
contig_high = GRANULEROUNDDOWN(contig_high);
}
if (!is_memory_available(md))
continue;
#ifdef CONFIG_CRASH_DUMP
if (saved_max_pfn < (efi_md_end(md) >> PAGE_SHIFT))
saved_max_pfn = (efi_md_end(md) >> PAGE_SHIFT);
#endif
if (md->phys_addr < contig_low) {
lim = min(efi_md_end(md), contig_low);
if (efi_uc(md)) {
if (k > kern_memmap &&
(k-1)->attribute == EFI_MEMORY_UC &&
kmd_end(k-1) == md->phys_addr) {
(k-1)->num_pages +=
(lim - md->phys_addr)
>> EFI_PAGE_SHIFT;
} else {
k->attribute = EFI_MEMORY_UC;
k->start = md->phys_addr;
k->num_pages = (lim - md->phys_addr)
>> EFI_PAGE_SHIFT;
k++;
}
}
as = contig_low;
} else
as = md->phys_addr;
if (efi_md_end(md) > contig_high) {
lim = max(md->phys_addr, contig_high);
if (efi_uc(md)) {
if (lim == md->phys_addr && k > kern_memmap &&
(k-1)->attribute == EFI_MEMORY_UC &&
kmd_end(k-1) == md->phys_addr) {
(k-1)->num_pages += md->num_pages;
} else {
k->attribute = EFI_MEMORY_UC;
k->start = lim;
k->num_pages = (efi_md_end(md) - lim)
>> EFI_PAGE_SHIFT;
k++;
}
}
ae = contig_high;
} else
ae = efi_md_end(md);
as = max(as, min_addr);
ae = min(ae, max_addr);
if (ae <= as)
continue;
if (total_mem + (ae - as) > mem_limit)
ae -= total_mem + (ae - as) - mem_limit;
if (ae <= as)
continue;
if (prev && kmd_end(prev) == md->phys_addr) {
prev->num_pages += (ae - as) >> EFI_PAGE_SHIFT;
total_mem += ae - as;
continue;
}
k->attribute = EFI_MEMORY_WB;
k->start = as;
k->num_pages = (ae - as) >> EFI_PAGE_SHIFT;
total_mem += ae - as;
prev = k++;
}
k->start = ~0L;
*s = (u64)kern_memmap;
*e = (u64)++k;
return total_mem;
}
void
efi_initialize_iomem_resources(struct resource *code_resource,
struct resource *data_resource,
struct resource *bss_resource)
{
struct resource *res;
void *efi_map_start, *efi_map_end, *p;
efi_memory_desc_t *md;
u64 efi_desc_size;
char *name;
unsigned long flags;
efi_map_start = __va(ia64_boot_param->efi_memmap);
efi_map_end = efi_map_start + ia64_boot_param->efi_memmap_size;
efi_desc_size = ia64_boot_param->efi_memdesc_size;
res = NULL;
for (p = efi_map_start; p < efi_map_end; p += efi_desc_size) {
md = p;
if (md->num_pages == 0)
continue;
flags = IORESOURCE_MEM | IORESOURCE_BUSY;
switch (md->type) {
case EFI_MEMORY_MAPPED_IO:
case EFI_MEMORY_MAPPED_IO_PORT_SPACE:
continue;
case EFI_LOADER_CODE:
case EFI_LOADER_DATA:
case EFI_BOOT_SERVICES_DATA:
case EFI_BOOT_SERVICES_CODE:
case EFI_CONVENTIONAL_MEMORY:
if (md->attribute & EFI_MEMORY_WP) {
name = "System ROM";
flags |= IORESOURCE_READONLY;
} else if (md->attribute == EFI_MEMORY_UC)
name = "Uncached RAM";
else
name = "System RAM";
break;
case EFI_ACPI_MEMORY_NVS:
name = "ACPI Non-volatile Storage";
break;
case EFI_UNUSABLE_MEMORY:
name = "reserved";
flags |= IORESOURCE_DISABLED;
break;
case EFI_RESERVED_TYPE:
case EFI_RUNTIME_SERVICES_CODE:
case EFI_RUNTIME_SERVICES_DATA:
case EFI_ACPI_RECLAIM_MEMORY:
default:
name = "reserved";
break;
}
if ((res = kzalloc(sizeof(struct resource),
GFP_KERNEL)) == NULL) {
printk(KERN_ERR
"failed to allocate resource for iomem\n");
return;
}
res->name = name;
res->start = md->phys_addr;
res->end = md->phys_addr + efi_md_size(md) - 1;
res->flags = flags;
if (insert_resource(&iomem_resource, res) < 0)
kfree(res);
else {
insert_resource(res, code_resource);
insert_resource(res, data_resource);
insert_resource(res, bss_resource);
#ifdef CONFIG_KEXEC
insert_resource(res, &efi_memmap_res);
insert_resource(res, &boot_param_res);
if (crashk_res.end > crashk_res.start)
insert_resource(res, &crashk_res);
#endif
}
}
}
unsigned long __init
kdump_find_rsvd_region (unsigned long size, struct rsvd_region *r, int n)
{
int i;
u64 start, end;
u64 alignment = 1UL << _PAGE_SIZE_64M;
void *efi_map_start, *efi_map_end, *p;
efi_memory_desc_t *md;
u64 efi_desc_size;
efi_map_start = __va(ia64_boot_param->efi_memmap);
efi_map_end = efi_map_start + ia64_boot_param->efi_memmap_size;
efi_desc_size = ia64_boot_param->efi_memdesc_size;
for (p = efi_map_start; p < efi_map_end; p += efi_desc_size) {
md = p;
if (!efi_wb(md))
continue;
start = ALIGN(md->phys_addr, alignment);
end = efi_md_end(md);
for (i = 0; i < n; i++) {
if (__pa(r[i].start) >= start && __pa(r[i].end) < end) {
if (__pa(r[i].start) > start + size)
return start;
start = ALIGN(__pa(r[i].end), alignment);
if (i < n-1 &&
__pa(r[i+1].start) < start + size)
continue;
else
break;
}
}
if (end > start + size)
return start;
}
printk(KERN_WARNING
"Cannot reserve 0x%lx byte of memory for crashdump\n", size);
return ~0UL;
}
unsigned long __init
vmcore_find_descriptor_size (unsigned long address)
{
void *efi_map_start, *efi_map_end, *p;
efi_memory_desc_t *md;
u64 efi_desc_size;
unsigned long ret = 0;
efi_map_start = __va(ia64_boot_param->efi_memmap);
efi_map_end = efi_map_start + ia64_boot_param->efi_memmap_size;
efi_desc_size = ia64_boot_param->efi_memdesc_size;
for (p = efi_map_start; p < efi_map_end; p += efi_desc_size) {
md = p;
if (efi_wb(md) && md->type == EFI_LOADER_DATA
&& md->phys_addr == address) {
ret = efi_md_size(md);
break;
}
}
if (ret == 0)
printk(KERN_WARNING "Cannot locate EFI vmcore descriptor\n");
return ret;
}
