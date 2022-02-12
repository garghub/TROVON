static inline struct ioc3_uartregs *console_uart(void)
{
struct ioc3 *ioc3;
nasid_t nasid;
nasid = (master_nasid == INVALID_NASID) ? get_nasid() : master_nasid;
ioc3 = (struct ioc3 *)KL_CONFIG_CH_CONS_INFO(nasid)->memory_base;
return &ioc3->sregs.uarta;
}
void prom_putchar(char c)
{
struct ioc3_uartregs *uart = console_uart();
while ((uart->iu_lsr & 0x20) == 0);
uart->iu_thr = c;
}
