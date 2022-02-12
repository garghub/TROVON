void __init tboot_probe(void)
{
if (!boot_params.tboot_addr)
return;
if (!e820_any_mapped(boot_params.tboot_addr,
boot_params.tboot_addr, E820_RESERVED)) {
pr_warning("non-0 tboot_addr but it is not of type E820_RESERVED\n");
return;
}
if (paravirt_enabled()) {
pr_warning("non-0 tboot_addr but pv_ops is enabled\n");
return;
}
set_fixmap(FIX_TBOOT_BASE, boot_params.tboot_addr);
tboot = (struct tboot *)fix_to_virt(FIX_TBOOT_BASE);
if (memcmp(&tboot_uuid, &tboot->uuid, sizeof(tboot->uuid))) {
pr_warning("tboot at 0x%llx is invalid\n",
boot_params.tboot_addr);
tboot = NULL;
return;
}
if (tboot->version < 5) {
pr_warning("tboot version is invalid: %u\n", tboot->version);
tboot = NULL;
return;
}
pr_info("found shared page at phys addr 0x%llx:\n",
boot_params.tboot_addr);
pr_debug("version: %d\n", tboot->version);
pr_debug("log_addr: 0x%08x\n", tboot->log_addr);
pr_debug("shutdown_entry: 0x%x\n", tboot->shutdown_entry);
pr_debug("tboot_base: 0x%08x\n", tboot->tboot_base);
pr_debug("tboot_size: 0x%x\n", tboot->tboot_size);
}
static inline void switch_to_tboot_pt(void)
{
write_cr3(virt_to_phys(tboot_pg_dir));
}
static int map_tboot_page(unsigned long vaddr, unsigned long pfn,
pgprot_t prot)
{
pgd_t *pgd;
pud_t *pud;
pmd_t *pmd;
pte_t *pte;
pgd = pgd_offset(&tboot_mm, vaddr);
pud = pud_alloc(&tboot_mm, pgd, vaddr);
if (!pud)
return -1;
pmd = pmd_alloc(&tboot_mm, pud, vaddr);
if (!pmd)
return -1;
pte = pte_alloc_map(&tboot_mm, pmd, vaddr);
if (!pte)
return -1;
set_pte_at(&tboot_mm, vaddr, pte, pfn_pte(pfn, prot));
pte_unmap(pte);
return 0;
}
static int map_tboot_pages(unsigned long vaddr, unsigned long start_pfn,
unsigned long nr)
{
tboot_pg_dir = pgd_alloc(&tboot_mm);
if (!tboot_pg_dir)
return -1;
for (; nr > 0; nr--, vaddr += PAGE_SIZE, start_pfn++) {
if (map_tboot_page(vaddr, start_pfn, PAGE_KERNEL_EXEC))
return -1;
}
return 0;
}
static void tboot_create_trampoline(void)
{
u32 map_base, map_size;
map_base = PFN_DOWN(tboot->tboot_base);
map_size = PFN_UP(tboot->tboot_size);
if (map_tboot_pages(map_base << PAGE_SHIFT, map_base, map_size))
panic("tboot: Error mapping tboot pages (mfns) @ 0x%x, 0x%x\n",
map_base, map_size);
}
static void add_mac_region(phys_addr_t start, unsigned long size)
{
struct tboot_mac_region *mr;
phys_addr_t end = start + size;
if (tboot->num_mac_regions >= MAX_TB_MAC_REGIONS)
panic("tboot: Too many MAC regions\n");
if (start && size) {
mr = &tboot->mac_regions[tboot->num_mac_regions++];
mr->start = round_down(start, PAGE_SIZE);
mr->size = round_up(end, PAGE_SIZE) - mr->start;
}
}
static int tboot_setup_sleep(void)
{
int i;
tboot->num_mac_regions = 0;
for (i = 0; i < e820.nr_map; i++) {
if ((e820.map[i].type != E820_RAM)
&& (e820.map[i].type != E820_RESERVED_KERN))
continue;
add_mac_region(e820.map[i].addr, e820.map[i].size);
}
tboot->acpi_sinfo.kernel_s3_resume_vector =
real_mode_header->wakeup_start;
return 0;
}
static int tboot_setup_sleep(void)
{
BUG();
return -1;
}
void tboot_shutdown(u32 shutdown_type)
{
void (*shutdown)(void);
if (!tboot_enabled())
return;
if (!tboot_pg_dir)
return;
if (shutdown_type == TB_SHUTDOWN_S3)
if (tboot_setup_sleep())
return;
tboot->shutdown_type = shutdown_type;
switch_to_tboot_pt();
shutdown = (void(*)(void))(unsigned long)tboot->shutdown_entry;
shutdown();
while (1)
halt();
}
static void tboot_copy_fadt(const struct acpi_table_fadt *fadt)
{
#define TB_COPY_GAS(tbg, g) \
tbg.space_id = g.space_id; \
tbg.bit_width = g.bit_width; \
tbg.bit_offset = g.bit_offset; \
tbg.access_width = g.access_width; \
tbg.address = g.address;
TB_COPY_GAS(tboot->acpi_sinfo.pm1a_cnt_blk, fadt->xpm1a_control_block);
TB_COPY_GAS(tboot->acpi_sinfo.pm1b_cnt_blk, fadt->xpm1b_control_block);
TB_COPY_GAS(tboot->acpi_sinfo.pm1a_evt_blk, fadt->xpm1a_event_block);
TB_COPY_GAS(tboot->acpi_sinfo.pm1b_evt_blk, fadt->xpm1b_event_block);
tboot->acpi_sinfo.wakeup_vector = fadt->facs +
offsetof(struct acpi_table_facs, firmware_waking_vector);
}
static int tboot_sleep(u8 sleep_state, u32 pm1a_control, u32 pm1b_control)
{
static u32 acpi_shutdown_map[ACPI_S_STATE_COUNT] = {
-1, -1, -1,
TB_SHUTDOWN_S3,
TB_SHUTDOWN_S4,
TB_SHUTDOWN_S5 };
if (!tboot_enabled())
return 0;
tboot_copy_fadt(&acpi_gbl_FADT);
tboot->acpi_sinfo.pm1a_cnt_val = pm1a_control;
tboot->acpi_sinfo.pm1b_cnt_val = pm1b_control;
tboot->acpi_sinfo.vector_width = 32;
if (sleep_state >= ACPI_S_STATE_COUNT ||
acpi_shutdown_map[sleep_state] == -1) {
pr_warning("unsupported sleep state 0x%x\n", sleep_state);
return -1;
}
tboot_shutdown(acpi_shutdown_map[sleep_state]);
return 0;
}
static int tboot_extended_sleep(u8 sleep_state, u32 val_a, u32 val_b)
{
if (!tboot_enabled())
return 0;
pr_warning("tboot is not able to suspend on platforms with reduced hardware sleep (ACPIv5)");
return -ENODEV;
}
static int tboot_wait_for_aps(int num_aps)
{
unsigned long timeout;
timeout = AP_WAIT_TIMEOUT*HZ;
while (atomic_read((atomic_t *)&tboot->num_in_wfs) != num_aps &&
timeout) {
mdelay(1);
timeout--;
}
if (timeout)
pr_warning("tboot wait for APs timeout\n");
return !(atomic_read((atomic_t *)&tboot->num_in_wfs) == num_aps);
}
static int tboot_cpu_callback(struct notifier_block *nfb, unsigned long action,
void *hcpu)
{
switch (action) {
case CPU_DYING:
atomic_inc(&ap_wfs_count);
if (num_online_cpus() == 1)
if (tboot_wait_for_aps(atomic_read(&ap_wfs_count)))
return NOTIFY_BAD;
break;
}
return NOTIFY_OK;
}
static ssize_t tboot_log_read(struct file *file, char __user *user_buf, size_t count, loff_t *ppos)
{
void __iomem *log_base;
u8 log_uuid[16];
u32 max_size;
void *kbuf;
int ret = -EFAULT;
log_base = ioremap_nocache(TBOOT_SERIAL_LOG_ADDR, TBOOT_SERIAL_LOG_SIZE);
if (!log_base)
return ret;
memcpy_fromio(log_uuid, log_base, sizeof(log_uuid));
if (memcmp(&tboot_log_uuid, log_uuid, sizeof(log_uuid)))
goto err_iounmap;
max_size = readl(log_base + LOG_MAX_SIZE_OFF);
if (*ppos >= max_size) {
ret = 0;
goto err_iounmap;
}
if (*ppos + count > max_size)
count = max_size - *ppos;
kbuf = kmalloc(count, GFP_KERNEL);
if (!kbuf) {
ret = -ENOMEM;
goto err_iounmap;
}
memcpy_fromio(kbuf, log_base + LOG_BUF_OFF + *ppos, count);
if (copy_to_user(user_buf, kbuf, count))
goto err_kfree;
*ppos += count;
ret = count;
err_kfree:
kfree(kbuf);
err_iounmap:
iounmap(log_base);
return ret;
}
static __init int tboot_late_init(void)
{
if (!tboot_enabled())
return 0;
tboot_create_trampoline();
atomic_set(&ap_wfs_count, 0);
register_hotcpu_notifier(&tboot_cpu_notifier);
#ifdef CONFIG_DEBUG_FS
debugfs_create_file("tboot_log", S_IRUSR,
arch_debugfs_dir, NULL, &tboot_log_fops);
#endif
acpi_os_set_prepare_sleep(&tboot_sleep);
acpi_os_set_prepare_extended_sleep(&tboot_extended_sleep);
return 0;
}
struct acpi_table_header *tboot_get_dmar_table(struct acpi_table_header *dmar_tbl)
{
void *heap_base, *heap_ptr, *config;
if (!tboot_enabled())
return dmar_tbl;
config = ioremap(TXT_PUB_CONFIG_REGS_BASE, NR_TXT_CONFIG_PAGES *
PAGE_SIZE);
if (!config)
return NULL;
heap_base = ioremap(*(u64 *)(config + TXTCR_HEAP_BASE),
*(u64 *)(config + TXTCR_HEAP_SIZE));
iounmap(config);
if (!heap_base)
return NULL;
heap_ptr = heap_base + *(u64 *)heap_base;
heap_ptr += *(u64 *)heap_ptr;
heap_ptr += *(u64 *)heap_ptr;
heap_ptr += sizeof(u64);
dmar_tbl = (struct acpi_table_header *)(heap_ptr +
((struct sinit_mle_data *)heap_ptr)->vtd_dmars_off -
sizeof(u64));
return dmar_tbl;
}
int tboot_force_iommu(void)
{
if (!tboot_enabled())
return 0;
if (no_iommu || swiotlb || dmar_disabled)
pr_warning("Forcing Intel-IOMMU to enabled\n");
dmar_disabled = 0;
#ifdef CONFIG_SWIOTLB
swiotlb = 0;
#endif
no_iommu = 0;
return 1;
}
