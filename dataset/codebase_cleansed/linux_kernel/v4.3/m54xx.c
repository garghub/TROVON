static void __init m54xx_uarts_init(void)
{
__raw_writeb(MCF_PAR_PSC_TXD | MCF_PAR_PSC_RXD, MCFGPIO_PAR_PSC0);
__raw_writeb(MCF_PAR_PSC_TXD | MCF_PAR_PSC_RXD | MCF_PAR_PSC_RTS_RTS,
MCFGPIO_PAR_PSC1);
__raw_writeb(MCF_PAR_PSC_TXD | MCF_PAR_PSC_RXD | MCF_PAR_PSC_RTS_RTS |
MCF_PAR_PSC_CTS_CTS, MCFGPIO_PAR_PSC2);
__raw_writeb(MCF_PAR_PSC_TXD | MCF_PAR_PSC_RXD, MCFGPIO_PAR_PSC3);
}
static void mcf54xx_reset(void)
{
asm("movew #0x2700, %sr\n");
__raw_writel(0, MCF_GPT_GMS0);
__raw_writel(MCF_GPT_GCIR_CNT(1), MCF_GPT_GCIR0);
__raw_writel(MCF_GPT_GMS_WDEN | MCF_GPT_GMS_CE | MCF_GPT_GMS_TMS(4),
MCF_GPT_GMS0);
}
static void __init mcf54xx_bootmem_alloc(void)
{
unsigned long start_pfn;
unsigned long memstart;
m68k_memory[0].addr = _rambase;
m68k_memory[0].size = _ramend - _rambase;
num_pages = PFN_DOWN(_ramend - _rambase);
memstart = PAGE_ALIGN(_ramstart);
min_low_pfn = PFN_DOWN(_rambase);
start_pfn = PFN_DOWN(memstart);
max_low_pfn = PFN_DOWN(_ramend);
high_memory = (void *)_ramend;
m68k_virt_to_node_shift = fls(_ramend - _rambase - 1) - 6;
module_fixup(NULL, __start_fixup, __stop_fixup);
m68k_setup_node(0);
memstart += init_bootmem_node(NODE_DATA(0), start_pfn,
min_low_pfn, max_low_pfn);
free_bootmem_node(NODE_DATA(0), memstart, _ramend - memstart);
}
void __init config_BSP(char *commandp, int size)
{
#ifdef CONFIG_MMU
mcf54xx_bootmem_alloc();
mmu_context_init();
#endif
mach_reset = mcf54xx_reset;
mach_sched_init = hw_timer_init;
m54xx_uarts_init();
}
