notrace unsigned long __init early_init(unsigned long dt_ptr)
{
unsigned long offset = reloc_offset();
memset_io((void __iomem *)PTRRELOC(&__bss_start), 0,
__bss_stop - __bss_start);
identify_cpu(offset, mfspr(SPRN_PVR));
apply_feature_fixups();
return KERNELBASE + offset;
}
notrace void __init machine_init(u64 dt_ptr)
{
unsigned int *addr = &memset_nocache_branch;
unsigned long insn;
setup_feature_keys();
udbg_early_init();
patch_instruction((unsigned int *)&memcpy, PPC_INST_NOP);
insn = create_cond_branch(addr, branch_target(addr), 0x820000);
patch_instruction(addr, insn);
early_init_devtree(__va(dt_ptr));
early_init_mmu();
setup_kdump_trampoline();
}
int __init ppc_setup_l2cr(char *str)
{
if (cpu_has_feature(CPU_FTR_L2CR)) {
unsigned long val = simple_strtoul(str, NULL, 0);
printk(KERN_INFO "l2cr set to %lx\n", val);
_set_L2CR(0);
_set_L2CR(val);
}
return 1;
}
int __init ppc_setup_l3cr(char *str)
{
if (cpu_has_feature(CPU_FTR_L3CR)) {
unsigned long val = simple_strtoul(str, NULL, 0);
printk(KERN_INFO "l3cr set to %lx\n", val);
_set_L3CR(val);
}
return 1;
}
unsigned char nvram_read_byte(int addr)
{
if (ppc_md.nvram_read_val)
return ppc_md.nvram_read_val(addr);
return 0xff;
}
void nvram_write_byte(unsigned char val, int addr)
{
if (ppc_md.nvram_write_val)
ppc_md.nvram_write_val(addr, val);
}
ssize_t nvram_get_size(void)
{
if (ppc_md.nvram_size)
return ppc_md.nvram_size();
return -1;
}
void nvram_sync(void)
{
if (ppc_md.nvram_sync)
ppc_md.nvram_sync();
}
int __init ppc_init(void)
{
if (ppc_md.progress)
ppc_md.progress(" ", 0xffff);
if (ppc_md.init != NULL) {
ppc_md.init();
}
return 0;
}
void __init irqstack_early_init(void)
{
unsigned int i;
for_each_possible_cpu(i) {
softirq_ctx[i] = (struct thread_info *)
__va(memblock_alloc(THREAD_SIZE, THREAD_SIZE));
hardirq_ctx[i] = (struct thread_info *)
__va(memblock_alloc(THREAD_SIZE, THREAD_SIZE));
}
}
void __init exc_lvl_early_init(void)
{
unsigned int i, hw_cpu;
for_each_possible_cpu(i) {
#ifdef CONFIG_SMP
hw_cpu = get_hard_smp_processor_id(i);
#else
hw_cpu = 0;
#endif
critirq_ctx[hw_cpu] = (struct thread_info *)
__va(memblock_alloc(THREAD_SIZE, THREAD_SIZE));
#ifdef CONFIG_BOOKE
dbgirq_ctx[hw_cpu] = (struct thread_info *)
__va(memblock_alloc(THREAD_SIZE, THREAD_SIZE));
mcheckirq_ctx[hw_cpu] = (struct thread_info *)
__va(memblock_alloc(THREAD_SIZE, THREAD_SIZE));
#endif
}
}
void __init setup_power_save(void)
{
#ifdef CONFIG_6xx
if (cpu_has_feature(CPU_FTR_CAN_DOZE) ||
cpu_has_feature(CPU_FTR_CAN_NAP))
ppc_md.power_save = ppc6xx_idle;
#endif
#ifdef CONFIG_E500
if (cpu_has_feature(CPU_FTR_CAN_DOZE) ||
cpu_has_feature(CPU_FTR_CAN_NAP))
ppc_md.power_save = e500_idle;
#endif
}
__init void initialize_cache_info(void)
{
dcache_bsize = cur_cpu_spec->dcache_bsize;
icache_bsize = cur_cpu_spec->icache_bsize;
ucache_bsize = 0;
if (cpu_has_feature(CPU_FTR_UNIFIED_ID_CACHE))
ucache_bsize = icache_bsize = dcache_bsize;
}
