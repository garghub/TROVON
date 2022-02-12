unsigned long octeon_crypto_enable(struct octeon_cop2_state *state)
{
int status;
unsigned long flags;
local_irq_save(flags);
status = read_c0_status();
write_c0_status(status | ST0_CU2);
if (KSTK_STATUS(current) & ST0_CU2) {
octeon_cop2_save(&(current->thread.cp2));
KSTK_STATUS(current) &= ~ST0_CU2;
status &= ~ST0_CU2;
} else if (status & ST0_CU2) {
octeon_cop2_save(state);
}
local_irq_restore(flags);
return status & ST0_CU2;
}
void octeon_crypto_disable(struct octeon_cop2_state *state,
unsigned long crypto_flags)
{
unsigned long flags;
local_irq_save(flags);
if (crypto_flags & ST0_CU2)
octeon_cop2_restore(state);
else
write_c0_status(read_c0_status() & ~ST0_CU2);
local_irq_restore(flags);
}
