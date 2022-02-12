int pfn_is_nosave(unsigned long pfn)
{
unsigned long begin_pfn = __pa(&__nosave_begin) >> PAGE_SHIFT;
unsigned long end_pfn = PAGE_ALIGN(__pa(&__nosave_end)) >> PAGE_SHIFT;
return (pfn >= begin_pfn) && (pfn < end_pfn);
}
void save_processor_state(void)
{
init_fpu(current);
}
void restore_processor_state(void)
{
local_flush_tlb_all();
}
