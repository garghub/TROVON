void save_processor_state(void)
{
flush_all_to_thread(current);
#ifdef CONFIG_PPC64
hard_irq_disable();
#endif
}
void restore_processor_state(void)
{
#ifdef CONFIG_PPC32
switch_mmu_context(current->active_mm, current->active_mm, NULL);
#endif
}
