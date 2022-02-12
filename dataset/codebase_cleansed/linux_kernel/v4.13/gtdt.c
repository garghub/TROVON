static inline void *next_platform_timer(void *platform_timer)
{
struct acpi_gtdt_header *gh = platform_timer;
platform_timer += gh->length;
if (platform_timer < acpi_gtdt_desc.gtdt_end)
return platform_timer;
return NULL;
}
static inline bool is_timer_block(void *platform_timer)
{
struct acpi_gtdt_header *gh = platform_timer;
return gh->type == ACPI_GTDT_TYPE_TIMER_BLOCK;
}
static inline bool is_non_secure_watchdog(void *platform_timer)
{
struct acpi_gtdt_header *gh = platform_timer;
struct acpi_gtdt_watchdog *wd = platform_timer;
if (gh->type != ACPI_GTDT_TYPE_WATCHDOG)
return false;
return !(wd->timer_flags & ACPI_GTDT_WATCHDOG_SECURE);
}
static int __init map_gt_gsi(u32 interrupt, u32 flags)
{
int trigger, polarity;
trigger = (flags & ACPI_GTDT_INTERRUPT_MODE) ? ACPI_EDGE_SENSITIVE
: ACPI_LEVEL_SENSITIVE;
polarity = (flags & ACPI_GTDT_INTERRUPT_POLARITY) ? ACPI_ACTIVE_LOW
: ACPI_ACTIVE_HIGH;
return acpi_register_gsi(NULL, interrupt, trigger, polarity);
}
int __init acpi_gtdt_map_ppi(int type)
{
struct acpi_table_gtdt *gtdt = acpi_gtdt_desc.gtdt;
switch (type) {
case ARCH_TIMER_PHYS_NONSECURE_PPI:
return map_gt_gsi(gtdt->non_secure_el1_interrupt,
gtdt->non_secure_el1_flags);
case ARCH_TIMER_VIRT_PPI:
return map_gt_gsi(gtdt->virtual_timer_interrupt,
gtdt->virtual_timer_flags);
case ARCH_TIMER_HYP_PPI:
return map_gt_gsi(gtdt->non_secure_el2_interrupt,
gtdt->non_secure_el2_flags);
default:
pr_err("Failed to map timer interrupt: invalid type.\n");
}
return 0;
}
bool __init acpi_gtdt_c3stop(int type)
{
struct acpi_table_gtdt *gtdt = acpi_gtdt_desc.gtdt;
switch (type) {
case ARCH_TIMER_PHYS_NONSECURE_PPI:
return !(gtdt->non_secure_el1_flags & ACPI_GTDT_ALWAYS_ON);
case ARCH_TIMER_VIRT_PPI:
return !(gtdt->virtual_timer_flags & ACPI_GTDT_ALWAYS_ON);
case ARCH_TIMER_HYP_PPI:
return !(gtdt->non_secure_el2_flags & ACPI_GTDT_ALWAYS_ON);
default:
pr_err("Failed to get c3stop info: invalid type.\n");
}
return false;
}
int __init acpi_gtdt_init(struct acpi_table_header *table,
int *platform_timer_count)
{
void *platform_timer;
struct acpi_table_gtdt *gtdt;
gtdt = container_of(table, struct acpi_table_gtdt, header);
acpi_gtdt_desc.gtdt = gtdt;
acpi_gtdt_desc.gtdt_end = (void *)table + table->length;
acpi_gtdt_desc.platform_timer = NULL;
if (platform_timer_count)
*platform_timer_count = 0;
if (table->revision < 2) {
pr_warn("Revision:%d doesn't support Platform Timers.\n",
table->revision);
return 0;
}
if (!gtdt->platform_timer_count) {
pr_debug("No Platform Timer.\n");
return 0;
}
platform_timer = (void *)gtdt + gtdt->platform_timer_offset;
if (platform_timer < (void *)table + sizeof(struct acpi_table_gtdt)) {
pr_err(FW_BUG "invalid timer data.\n");
return -EINVAL;
}
acpi_gtdt_desc.platform_timer = platform_timer;
if (platform_timer_count)
*platform_timer_count = gtdt->platform_timer_count;
return 0;
}
static int __init gtdt_parse_timer_block(struct acpi_gtdt_timer_block *block,
struct arch_timer_mem *timer_mem)
{
int i;
struct arch_timer_mem_frame *frame;
struct acpi_gtdt_timer_entry *gtdt_frame;
if (!block->timer_count) {
pr_err(FW_BUG "GT block present, but frame count is zero.");
return -ENODEV;
}
if (block->timer_count > ARCH_TIMER_MEM_MAX_FRAMES) {
pr_err(FW_BUG "GT block lists %d frames, ACPI spec only allows 8\n",
block->timer_count);
return -EINVAL;
}
timer_mem->cntctlbase = (phys_addr_t)block->block_address;
timer_mem->size = SZ_4K;
gtdt_frame = (void *)block + block->timer_offset;
if (gtdt_frame + block->timer_count != (void *)block + block->header.length)
return -EINVAL;
for (i = 0; i < block->timer_count; i++, gtdt_frame++) {
if (gtdt_frame->common_flags & ACPI_GTDT_GT_IS_SECURE_TIMER)
continue;
if (gtdt_frame->frame_number >= ARCH_TIMER_MEM_MAX_FRAMES ||
!gtdt_frame->base_address || !gtdt_frame->timer_interrupt)
goto error;
frame = &timer_mem->frame[gtdt_frame->frame_number];
if (frame->valid)
goto error;
frame->phys_irq = map_gt_gsi(gtdt_frame->timer_interrupt,
gtdt_frame->timer_flags);
if (frame->phys_irq <= 0) {
pr_warn("failed to map physical timer irq in frame %d.\n",
gtdt_frame->frame_number);
goto error;
}
if (gtdt_frame->virtual_timer_interrupt) {
frame->virt_irq =
map_gt_gsi(gtdt_frame->virtual_timer_interrupt,
gtdt_frame->virtual_timer_flags);
if (frame->virt_irq <= 0) {
pr_warn("failed to map virtual timer irq in frame %d.\n",
gtdt_frame->frame_number);
goto error;
}
} else {
pr_debug("virtual timer in frame %d not implemented.\n",
gtdt_frame->frame_number);
}
frame->cntbase = gtdt_frame->base_address;
frame->size = SZ_4K;
frame->valid = true;
}
return 0;
error:
do {
if (gtdt_frame->common_flags & ACPI_GTDT_GT_IS_SECURE_TIMER ||
gtdt_frame->frame_number >= ARCH_TIMER_MEM_MAX_FRAMES)
continue;
frame = &timer_mem->frame[gtdt_frame->frame_number];
if (frame->phys_irq > 0)
acpi_unregister_gsi(gtdt_frame->timer_interrupt);
frame->phys_irq = 0;
if (frame->virt_irq > 0)
acpi_unregister_gsi(gtdt_frame->virtual_timer_interrupt);
frame->virt_irq = 0;
} while (i-- >= 0 && gtdt_frame--);
return -EINVAL;
}
int __init acpi_arch_timer_mem_init(struct arch_timer_mem *timer_mem,
int *timer_count)
{
int ret;
void *platform_timer;
*timer_count = 0;
for_each_platform_timer(platform_timer) {
if (is_timer_block(platform_timer)) {
ret = gtdt_parse_timer_block(platform_timer, timer_mem);
if (ret)
return ret;
timer_mem++;
(*timer_count)++;
}
}
if (*timer_count)
pr_info("found %d memory-mapped timer block(s).\n",
*timer_count);
return 0;
}
static int __init gtdt_import_sbsa_gwdt(struct acpi_gtdt_watchdog *wd,
int index)
{
struct platform_device *pdev;
int irq = map_gt_gsi(wd->timer_interrupt, wd->timer_flags);
struct resource res[] = {
DEFINE_RES_MEM(wd->control_frame_address, SZ_4K),
DEFINE_RES_MEM(wd->refresh_frame_address, SZ_4K),
DEFINE_RES_IRQ(irq),
};
int nr_res = ARRAY_SIZE(res);
pr_debug("found a Watchdog (0x%llx/0x%llx gsi:%u flags:0x%x).\n",
wd->refresh_frame_address, wd->control_frame_address,
wd->timer_interrupt, wd->timer_flags);
if (!(wd->refresh_frame_address && wd->control_frame_address)) {
pr_err(FW_BUG "failed to get the Watchdog base address.\n");
acpi_unregister_gsi(wd->timer_interrupt);
return -EINVAL;
}
if (irq <= 0) {
pr_warn("failed to map the Watchdog interrupt.\n");
nr_res--;
}
pdev = platform_device_register_simple("sbsa-gwdt", index, res, nr_res);
if (IS_ERR(pdev)) {
acpi_unregister_gsi(wd->timer_interrupt);
return PTR_ERR(pdev);
}
return 0;
}
static int __init gtdt_sbsa_gwdt_init(void)
{
void *platform_timer;
struct acpi_table_header *table;
int ret, timer_count, gwdt_count = 0;
if (acpi_disabled)
return 0;
if (ACPI_FAILURE(acpi_get_table(ACPI_SIG_GTDT, 0, &table)))
return -EINVAL;
ret = acpi_gtdt_init(table, &timer_count);
if (ret || !timer_count)
return ret;
for_each_platform_timer(platform_timer) {
if (is_non_secure_watchdog(platform_timer)) {
ret = gtdt_import_sbsa_gwdt(platform_timer, gwdt_count);
if (ret)
break;
gwdt_count++;
}
}
if (gwdt_count)
pr_info("found %d SBSA generic Watchdog(s).\n", gwdt_count);
return ret;
}
