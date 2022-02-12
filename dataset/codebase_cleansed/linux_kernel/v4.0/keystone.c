static int keystone_platform_notifier(struct notifier_block *nb,
unsigned long event, void *data)
{
struct device *dev = data;
if (event != BUS_NOTIFY_ADD_DEVICE)
return NOTIFY_DONE;
if (!dev)
return NOTIFY_BAD;
if (!dev->of_node) {
dev->dma_pfn_offset = keystone_dma_pfn_offset;
dev_err(dev, "set dma_pfn_offset%08lx\n",
dev->dma_pfn_offset);
}
return NOTIFY_OK;
}
static void __init keystone_init(void)
{
keystone_pm_runtime_init();
if (platform_nb.notifier_call)
bus_register_notifier(&platform_bus_type, &platform_nb);
of_platform_populate(NULL, of_default_bus_match_table, NULL, NULL);
}
static phys_addr_t keystone_virt_to_idmap(unsigned long x)
{
return (phys_addr_t)(x) - CONFIG_PAGE_OFFSET + KEYSTONE_LOW_PHYS_START;
}
static void __init keystone_init_meminfo(void)
{
bool lpae = IS_ENABLED(CONFIG_ARM_LPAE);
bool pvpatch = IS_ENABLED(CONFIG_ARM_PATCH_PHYS_VIRT);
phys_addr_t offset = PHYS_OFFSET - KEYSTONE_LOW_PHYS_START;
phys_addr_t mem_start, mem_end;
mem_start = memblock_start_of_DRAM();
mem_end = memblock_end_of_DRAM();
if (mem_start >= KEYSTONE_LOW_PHYS_START &&
mem_end <= KEYSTONE_LOW_PHYS_END)
return;
if (!lpae || !pvpatch) {
pr_crit("Enable %s%s%s to run outside 32-bit space\n",
!lpae ? __stringify(CONFIG_ARM_LPAE) : "",
(!lpae && !pvpatch) ? " and " : "",
!pvpatch ? __stringify(CONFIG_ARM_PATCH_PHYS_VIRT) : "");
}
if (mem_start < KEYSTONE_HIGH_PHYS_START ||
mem_end > KEYSTONE_HIGH_PHYS_END) {
pr_crit("Invalid address space for memory (%08llx-%08llx)\n",
(u64)mem_start, (u64)mem_end);
}
offset += KEYSTONE_HIGH_PHYS_START;
__pv_phys_pfn_offset = PFN_DOWN(offset);
__pv_offset = (offset - PAGE_OFFSET);
arch_virt_to_idmap = keystone_virt_to_idmap;
platform_nb.notifier_call = keystone_platform_notifier;
keystone_dma_pfn_offset = PFN_DOWN(KEYSTONE_HIGH_PHYS_START -
KEYSTONE_LOW_PHYS_START);
pr_info("Switching to high address space at 0x%llx\n", (u64)offset);
}
