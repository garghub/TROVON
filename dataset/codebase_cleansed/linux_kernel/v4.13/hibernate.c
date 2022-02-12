int pfn_is_nosave(unsigned long pfn)
{
unsigned long nosave_begin_pfn = PFN_DOWN((unsigned long)&__nosave_begin);
unsigned long nosave_end_pfn = PFN_DOWN((unsigned long)&__nosave_end);
return (pfn >= nosave_begin_pfn) && (pfn < nosave_end_pfn);
}
void save_processor_state(void)
{
save_and_clear_fpu();
}
void restore_processor_state(void)
{
struct mm_struct *mm = current->active_mm;
tsb_context_switch_ctx(mm, CTX_HWBITS(mm->context));
}
