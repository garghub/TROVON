static void __init early_code_mapping_set_exec(int executable)
{
efi_memory_desc_t *md;
if (!(__supported_pte_mask & _PAGE_NX))
return;
for_each_efi_memory_desc(md) {
if (md->type == EFI_RUNTIME_SERVICES_CODE ||
md->type == EFI_BOOT_SERVICES_CODE)
efi_set_executable(md, executable);
}
}
pgd_t * __init efi_call_phys_prolog(void)
{
unsigned long vaddress;
pgd_t *save_pgd;
int pgd;
int n_pgds;
if (!efi_enabled(EFI_OLD_MEMMAP)) {
save_pgd = (pgd_t *)read_cr3();
write_cr3((unsigned long)efi_scratch.efi_pgt);
goto out;
}
early_code_mapping_set_exec(1);
n_pgds = DIV_ROUND_UP((max_pfn << PAGE_SHIFT), PGDIR_SIZE);
save_pgd = kmalloc(n_pgds * sizeof(pgd_t), GFP_KERNEL);
for (pgd = 0; pgd < n_pgds; pgd++) {
save_pgd[pgd] = *pgd_offset_k(pgd * PGDIR_SIZE);
vaddress = (unsigned long)__va(pgd * PGDIR_SIZE);
set_pgd(pgd_offset_k(pgd * PGDIR_SIZE), *pgd_offset_k(vaddress));
}
out:
__flush_tlb_all();
return save_pgd;
}
void __init efi_call_phys_epilog(pgd_t *save_pgd)
{
int pgd_idx;
int nr_pgds;
if (!efi_enabled(EFI_OLD_MEMMAP)) {
write_cr3((unsigned long)save_pgd);
__flush_tlb_all();
return;
}
nr_pgds = DIV_ROUND_UP((max_pfn << PAGE_SHIFT) , PGDIR_SIZE);
for (pgd_idx = 0; pgd_idx < nr_pgds; pgd_idx++)
set_pgd(pgd_offset_k(pgd_idx * PGDIR_SIZE), save_pgd[pgd_idx]);
kfree(save_pgd);
__flush_tlb_all();
early_code_mapping_set_exec(0);
}
int __init efi_alloc_page_tables(void)
{
pgd_t *pgd;
pud_t *pud;
gfp_t gfp_mask;
if (efi_enabled(EFI_OLD_MEMMAP))
return 0;
gfp_mask = GFP_KERNEL | __GFP_NOTRACK | __GFP_ZERO;
efi_pgd = (pgd_t *)__get_free_page(gfp_mask);
if (!efi_pgd)
return -ENOMEM;
pgd = efi_pgd + pgd_index(EFI_VA_END);
pud = pud_alloc_one(NULL, 0);
if (!pud) {
free_page((unsigned long)efi_pgd);
return -ENOMEM;
}
pgd_populate(NULL, pgd, pud);
return 0;
}
void efi_sync_low_kernel_mappings(void)
{
unsigned num_entries;
pgd_t *pgd_k, *pgd_efi;
pud_t *pud_k, *pud_efi;
if (efi_enabled(EFI_OLD_MEMMAP))
return;
BUILD_BUG_ON(pgd_index(EFI_VA_END) != pgd_index(MODULES_END));
BUILD_BUG_ON((EFI_VA_START & PGDIR_MASK) !=
(EFI_VA_END & PGDIR_MASK));
pgd_efi = efi_pgd + pgd_index(PAGE_OFFSET);
pgd_k = pgd_offset_k(PAGE_OFFSET);
num_entries = pgd_index(EFI_VA_END) - pgd_index(PAGE_OFFSET);
memcpy(pgd_efi, pgd_k, sizeof(pgd_t) * num_entries);
BUILD_BUG_ON((EFI_VA_START & ~PUD_MASK) != 0);
BUILD_BUG_ON((EFI_VA_END & ~PUD_MASK) != 0);
pgd_efi = efi_pgd + pgd_index(EFI_VA_END);
pud_efi = pud_offset(pgd_efi, 0);
pgd_k = pgd_offset_k(EFI_VA_END);
pud_k = pud_offset(pgd_k, 0);
num_entries = pud_index(EFI_VA_END);
memcpy(pud_efi, pud_k, sizeof(pud_t) * num_entries);
pud_efi = pud_offset(pgd_efi, EFI_VA_START);
pud_k = pud_offset(pgd_k, EFI_VA_START);
num_entries = PTRS_PER_PUD - pud_index(EFI_VA_START);
memcpy(pud_efi, pud_k, sizeof(pud_t) * num_entries);
}
int __init efi_setup_page_tables(unsigned long pa_memmap, unsigned num_pages)
{
unsigned long pfn, text;
efi_memory_desc_t *md;
struct page *page;
unsigned npages;
pgd_t *pgd;
if (efi_enabled(EFI_OLD_MEMMAP))
return 0;
efi_scratch.efi_pgt = (pgd_t *)__pa(efi_pgd);
pgd = efi_pgd;
pfn = pa_memmap >> PAGE_SHIFT;
if (kernel_map_pages_in_pgd(pgd, pfn, pa_memmap, num_pages, _PAGE_NX | _PAGE_RW)) {
pr_err("Error ident-mapping new memmap (0x%lx)!\n", pa_memmap);
return 1;
}
efi_scratch.use_pgd = true;
if (!IS_ENABLED(CONFIG_EFI_MIXED))
return 0;
for_each_efi_memory_desc(md) {
if (md->type != EFI_CONVENTIONAL_MEMORY &&
md->type != EFI_LOADER_DATA &&
md->type != EFI_LOADER_CODE)
continue;
pfn = md->phys_addr >> PAGE_SHIFT;
npages = md->num_pages;
if (kernel_map_pages_in_pgd(pgd, pfn, md->phys_addr, npages, _PAGE_RW)) {
pr_err("Failed to map 1:1 memory\n");
return 1;
}
}
page = alloc_page(GFP_KERNEL|__GFP_DMA32);
if (!page)
panic("Unable to allocate EFI runtime stack < 4GB\n");
efi_scratch.phys_stack = virt_to_phys(page_address(page));
efi_scratch.phys_stack += PAGE_SIZE;
npages = (_etext - _text) >> PAGE_SHIFT;
text = __pa(_text);
pfn = text >> PAGE_SHIFT;
if (kernel_map_pages_in_pgd(pgd, pfn, text, npages, _PAGE_RW)) {
pr_err("Failed to map kernel text 1:1\n");
return 1;
}
return 0;
}
void __init efi_cleanup_page_tables(unsigned long pa_memmap, unsigned num_pages)
{
kernel_unmap_pages_in_pgd(efi_pgd, pa_memmap, num_pages);
}
static void __init __map_region(efi_memory_desc_t *md, u64 va)
{
unsigned long flags = _PAGE_RW;
unsigned long pfn;
pgd_t *pgd = efi_pgd;
if (!(md->attribute & EFI_MEMORY_WB))
flags |= _PAGE_PCD;
pfn = md->phys_addr >> PAGE_SHIFT;
if (kernel_map_pages_in_pgd(pgd, pfn, va, md->num_pages, flags))
pr_warn("Error mapping PA 0x%llx -> VA 0x%llx!\n",
md->phys_addr, va);
}
void __init efi_map_region(efi_memory_desc_t *md)
{
unsigned long size = md->num_pages << PAGE_SHIFT;
u64 pa = md->phys_addr;
if (efi_enabled(EFI_OLD_MEMMAP))
return old_map_region(md);
__map_region(md, md->phys_addr);
if (!efi_is_native () && IS_ENABLED(CONFIG_EFI_MIXED)) {
md->virt_addr = md->phys_addr;
return;
}
efi_va -= size;
if (!(pa & (PMD_SIZE - 1))) {
efi_va &= PMD_MASK;
} else {
u64 pa_offset = pa & (PMD_SIZE - 1);
u64 prev_va = efi_va;
efi_va = (efi_va & PMD_MASK) + pa_offset;
if (efi_va > prev_va)
efi_va -= PMD_SIZE;
}
if (efi_va < EFI_VA_END) {
pr_warn(FW_WARN "VA address range overflow!\n");
return;
}
__map_region(md, efi_va);
md->virt_addr = efi_va;
}
void __init efi_map_region_fixed(efi_memory_desc_t *md)
{
__map_region(md, md->virt_addr);
}
void __iomem *__init efi_ioremap(unsigned long phys_addr, unsigned long size,
u32 type, u64 attribute)
{
unsigned long last_map_pfn;
if (type == EFI_MEMORY_MAPPED_IO)
return ioremap(phys_addr, size);
last_map_pfn = init_memory_mapping(phys_addr, phys_addr + size);
if ((last_map_pfn << PAGE_SHIFT) < phys_addr + size) {
unsigned long top = last_map_pfn << PAGE_SHIFT;
efi_ioremap(top, size - (top - phys_addr), type, attribute);
}
if (!(attribute & EFI_MEMORY_WB))
efi_memory_uc((u64)(unsigned long)__va(phys_addr), size);
return (void __iomem *)__va(phys_addr);
}
void __init parse_efi_setup(u64 phys_addr, u32 data_len)
{
efi_setup = phys_addr + sizeof(struct setup_data);
}
void __init efi_runtime_update_mappings(void)
{
unsigned long pfn;
pgd_t *pgd = efi_pgd;
efi_memory_desc_t *md;
if (efi_enabled(EFI_OLD_MEMMAP)) {
if (__supported_pte_mask & _PAGE_NX)
runtime_code_page_mkexec();
return;
}
if (!efi_enabled(EFI_NX_PE_DATA))
return;
for_each_efi_memory_desc(md) {
unsigned long pf = 0;
if (!(md->attribute & EFI_MEMORY_RUNTIME))
continue;
if (!(md->attribute & EFI_MEMORY_WB))
pf |= _PAGE_PCD;
if ((md->attribute & EFI_MEMORY_XP) ||
(md->type == EFI_RUNTIME_SERVICES_DATA))
pf |= _PAGE_NX;
if (!(md->attribute & EFI_MEMORY_RO) &&
(md->type != EFI_RUNTIME_SERVICES_CODE))
pf |= _PAGE_RW;
pfn = md->phys_addr >> PAGE_SHIFT;
if (kernel_map_pages_in_pgd(pgd, pfn, md->phys_addr, md->num_pages, pf))
pr_warn("Error mapping PA 0x%llx -> VA 0x%llx!\n",
md->phys_addr, md->virt_addr);
if (kernel_map_pages_in_pgd(pgd, pfn, md->virt_addr, md->num_pages, pf))
pr_warn("Error mapping PA 0x%llx -> VA 0x%llx!\n",
md->phys_addr, md->virt_addr);
}
}
void __init efi_dump_pagetable(void)
{
#ifdef CONFIG_EFI_PGT_DUMP
ptdump_walk_pgd_level(NULL, efi_pgd);
#endif
}
efi_status_t efi_thunk_set_virtual_address_map(
void *phys_set_virtual_address_map,
unsigned long memory_map_size,
unsigned long descriptor_size,
u32 descriptor_version,
efi_memory_desc_t *virtual_map)
{
efi_status_t status;
unsigned long flags;
u32 func;
efi_sync_low_kernel_mappings();
local_irq_save(flags);
efi_scratch.prev_cr3 = read_cr3();
write_cr3((unsigned long)efi_scratch.efi_pgt);
__flush_tlb_all();
func = (u32)(unsigned long)phys_set_virtual_address_map;
status = efi64_thunk(func, memory_map_size, descriptor_size,
descriptor_version, virtual_map);
write_cr3(efi_scratch.prev_cr3);
__flush_tlb_all();
local_irq_restore(flags);
return status;
}
static efi_status_t efi_thunk_get_time(efi_time_t *tm, efi_time_cap_t *tc)
{
efi_status_t status;
u32 phys_tm, phys_tc;
spin_lock(&rtc_lock);
phys_tm = virt_to_phys(tm);
phys_tc = virt_to_phys(tc);
status = efi_thunk(get_time, phys_tm, phys_tc);
spin_unlock(&rtc_lock);
return status;
}
static efi_status_t efi_thunk_set_time(efi_time_t *tm)
{
efi_status_t status;
u32 phys_tm;
spin_lock(&rtc_lock);
phys_tm = virt_to_phys(tm);
status = efi_thunk(set_time, phys_tm);
spin_unlock(&rtc_lock);
return status;
}
static efi_status_t
efi_thunk_get_wakeup_time(efi_bool_t *enabled, efi_bool_t *pending,
efi_time_t *tm)
{
efi_status_t status;
u32 phys_enabled, phys_pending, phys_tm;
spin_lock(&rtc_lock);
phys_enabled = virt_to_phys(enabled);
phys_pending = virt_to_phys(pending);
phys_tm = virt_to_phys(tm);
status = efi_thunk(get_wakeup_time, phys_enabled,
phys_pending, phys_tm);
spin_unlock(&rtc_lock);
return status;
}
static efi_status_t
efi_thunk_set_wakeup_time(efi_bool_t enabled, efi_time_t *tm)
{
efi_status_t status;
u32 phys_tm;
spin_lock(&rtc_lock);
phys_tm = virt_to_phys(tm);
status = efi_thunk(set_wakeup_time, enabled, phys_tm);
spin_unlock(&rtc_lock);
return status;
}
static efi_status_t
efi_thunk_get_variable(efi_char16_t *name, efi_guid_t *vendor,
u32 *attr, unsigned long *data_size, void *data)
{
efi_status_t status;
u32 phys_name, phys_vendor, phys_attr;
u32 phys_data_size, phys_data;
phys_data_size = virt_to_phys(data_size);
phys_vendor = virt_to_phys(vendor);
phys_name = virt_to_phys(name);
phys_attr = virt_to_phys(attr);
phys_data = virt_to_phys(data);
status = efi_thunk(get_variable, phys_name, phys_vendor,
phys_attr, phys_data_size, phys_data);
return status;
}
static efi_status_t
efi_thunk_set_variable(efi_char16_t *name, efi_guid_t *vendor,
u32 attr, unsigned long data_size, void *data)
{
u32 phys_name, phys_vendor, phys_data;
efi_status_t status;
phys_name = virt_to_phys(name);
phys_vendor = virt_to_phys(vendor);
phys_data = virt_to_phys(data);
status = efi_thunk(set_variable, phys_name, phys_vendor,
attr, data_size, phys_data);
return status;
}
static efi_status_t
efi_thunk_get_next_variable(unsigned long *name_size,
efi_char16_t *name,
efi_guid_t *vendor)
{
efi_status_t status;
u32 phys_name_size, phys_name, phys_vendor;
phys_name_size = virt_to_phys(name_size);
phys_vendor = virt_to_phys(vendor);
phys_name = virt_to_phys(name);
status = efi_thunk(get_next_variable, phys_name_size,
phys_name, phys_vendor);
return status;
}
static efi_status_t
efi_thunk_get_next_high_mono_count(u32 *count)
{
efi_status_t status;
u32 phys_count;
phys_count = virt_to_phys(count);
status = efi_thunk(get_next_high_mono_count, phys_count);
return status;
}
static void
efi_thunk_reset_system(int reset_type, efi_status_t status,
unsigned long data_size, efi_char16_t *data)
{
u32 phys_data;
phys_data = virt_to_phys(data);
efi_thunk(reset_system, reset_type, status, data_size, phys_data);
}
static efi_status_t
efi_thunk_update_capsule(efi_capsule_header_t **capsules,
unsigned long count, unsigned long sg_list)
{
return EFI_UNSUPPORTED;
}
static efi_status_t
efi_thunk_query_variable_info(u32 attr, u64 *storage_space,
u64 *remaining_space,
u64 *max_variable_size)
{
efi_status_t status;
u32 phys_storage, phys_remaining, phys_max;
if (efi.runtime_version < EFI_2_00_SYSTEM_TABLE_REVISION)
return EFI_UNSUPPORTED;
phys_storage = virt_to_phys(storage_space);
phys_remaining = virt_to_phys(remaining_space);
phys_max = virt_to_phys(max_variable_size);
status = efi_thunk(query_variable_info, attr, phys_storage,
phys_remaining, phys_max);
return status;
}
static efi_status_t
efi_thunk_query_capsule_caps(efi_capsule_header_t **capsules,
unsigned long count, u64 *max_size,
int *reset_type)
{
return EFI_UNSUPPORTED;
}
void efi_thunk_runtime_setup(void)
{
efi.get_time = efi_thunk_get_time;
efi.set_time = efi_thunk_set_time;
efi.get_wakeup_time = efi_thunk_get_wakeup_time;
efi.set_wakeup_time = efi_thunk_set_wakeup_time;
efi.get_variable = efi_thunk_get_variable;
efi.get_next_variable = efi_thunk_get_next_variable;
efi.set_variable = efi_thunk_set_variable;
efi.get_next_high_mono_count = efi_thunk_get_next_high_mono_count;
efi.reset_system = efi_thunk_reset_system;
efi.query_variable_info = efi_thunk_query_variable_info;
efi.update_capsule = efi_thunk_update_capsule;
efi.query_capsule_caps = efi_thunk_query_capsule_caps;
}
