static inline void __noreturn back_to_prom(void)
{
noret_func_t func = (void *)CKSEG1ADDR(0x1fc00000);
func();
}
void __noreturn dec_machine_restart(char *command)
{
back_to_prom();
}
void __noreturn dec_machine_halt(void)
{
back_to_prom();
}
void __noreturn dec_machine_power_off(void)
{
back_to_prom();
}
irqreturn_t dec_intr_halt(int irq, void *dev_id)
{
dec_machine_halt();
}
