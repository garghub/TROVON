static int cnmips_cu2_call(struct notifier_block *nfb, unsigned long action,
void *data)
{
unsigned long flags;
unsigned int status;
switch (action) {
case CU2_EXCEPTION:
prefetch(&current->thread.cp2);
local_irq_save(flags);
KSTK_STATUS(current) |= ST0_CU2;
status = read_c0_status();
write_c0_status(status | ST0_CU2);
octeon_cop2_restore(&(current->thread.cp2));
write_c0_status(status & ~ST0_CU2);
local_irq_restore(flags);
return NOTIFY_BAD;
}
return NOTIFY_OK;
}
static int __init cnmips_cu2_setup(void)
{
return cu2_notifier(cnmips_cu2_call, 0);
}
