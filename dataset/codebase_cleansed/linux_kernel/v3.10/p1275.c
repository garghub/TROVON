void p1275_cmd_direct(unsigned long *args)
{
unsigned long flags;
raw_local_save_flags(flags);
raw_local_irq_restore((unsigned long)PIL_NMI);
raw_spin_lock(&prom_entry_lock);
prom_world(1);
prom_cif_direct(args);
prom_world(0);
raw_spin_unlock(&prom_entry_lock);
raw_local_irq_restore(flags);
}
void prom_cif_init(void *cif_handler, void *cif_stack)
{
p1275buf.prom_cif_handler = (void (*)(long *))cif_handler;
p1275buf.prom_cif_stack = (unsigned long)cif_stack;
}
