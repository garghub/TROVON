int handle_perf_interrupt(struct pt_regs *regs, int fault)
{
int retval;
if (!perf_irq)
panic("Unexpected PERF_COUNT interrupt %d\n", fault);
nmi_enter();
retval = perf_irq(regs, fault);
nmi_exit();
return retval;
}
perf_irq_t reserve_pmc_hardware(perf_irq_t new_perf_irq)
{
return cmpxchg(&perf_irq, NULL, new_perf_irq);
}
void release_pmc_hardware(void)
{
perf_irq = NULL;
}
unsigned long
pmc_get_overflow(void)
{
unsigned long status;
status = __insn_mfspr(SPR_PERF_COUNT_STS);
status |= __insn_mfspr(SPR_AUX_PERF_COUNT_STS) << TILE_BASE_COUNTERS;
return status;
}
void
pmc_ack_overflow(unsigned long status)
{
__insn_mtspr(SPR_PERF_COUNT_STS, status);
__insn_mtspr(SPR_AUX_PERF_COUNT_STS, status >> TILE_BASE_COUNTERS);
}
static inline unsigned long long pmc_mask(void)
{
unsigned long long mask = 1ULL << INT_PERF_COUNT;
mask |= 1ULL << INT_AUX_PERF_COUNT;
return mask;
}
void unmask_pmc_interrupts(void)
{
interrupt_mask_reset_mask(pmc_mask());
}
void mask_pmc_interrupts(void)
{
interrupt_mask_set_mask(pmc_mask());
}
