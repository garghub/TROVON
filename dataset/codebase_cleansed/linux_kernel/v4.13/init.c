void __init paging_init(void)
{
unsigned long end_mem = memory_end & PAGE_MASK;
unsigned long zones_size[MAX_NR_ZONES] = {
[0] = 0,
[ZONE_DMA] = (end_mem - CONFIG_PHY_RAM_BASE_ADDRESS) >> PAGE_SHIFT,
[ZONE_NORMAL] = 0,
#ifdef CONFIG_HIGHMEM
[ZONE_HIGHMEM] = 0,
#endif
};
set_fs(KERNEL_DS);
pr_debug("free_area_init -> start_mem is %#lx virtual_end is %#lx\n",
PAGE_ALIGN(memory_start), end_mem);
free_area_init_node(0, zones_size,
CONFIG_PHY_RAM_BASE_ADDRESS >> PAGE_SHIFT, NULL);
}
asmlinkage void __init init_pda(void)
{
unsigned int cpu = raw_smp_processor_id();
early_shadow_stamp();
memset(&cpu_pda[cpu], 0, sizeof(cpu_pda[cpu]));
#ifdef CONFIG_EXCEPTION_L1_SCRATCH
cpu_pda[cpu].ex_stack = (unsigned long *)(L1_SCRATCH_START + \
L1_SCRATCH_LENGTH);
#else
cpu_pda[cpu].ex_stack = exception_stack[cpu + 1];
#endif
#ifdef CONFIG_SMP
cpu_pda[cpu].imask = 0x1f;
#endif
}
void __init mem_init(void)
{
char buf[64];
high_memory = (void *)(memory_end & PAGE_MASK);
max_mapnr = MAP_NR(high_memory);
printk(KERN_DEBUG "Kernel managed physical pages: %lu\n", max_mapnr);
free_all_bootmem();
snprintf(buf, sizeof(buf) - 1, "%uK DMA", DMA_UNCACHED_REGION >> 10);
mem_init_print_info(buf);
}
void __init free_initrd_mem(unsigned long start, unsigned long end)
{
#ifndef CONFIG_MPU
free_reserved_area((void *)start, (void *)end, -1, "initrd");
#endif
}
void __ref free_initmem(void)
{
#if defined CONFIG_RAMKERNEL && !defined CONFIG_MPU
free_initmem_default(-1);
if (memory_start == (unsigned long)(&__init_end))
memory_start = (unsigned long)(&__init_begin);
#endif
}
