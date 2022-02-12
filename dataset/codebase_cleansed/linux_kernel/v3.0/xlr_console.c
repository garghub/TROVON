void prom_putchar(char c)
{
nlm_reg_t *mmio;
mmio = netlogic_io_mmio(NETLOGIC_IO_UART_0_OFFSET);
while (netlogic_read_reg(mmio, 0x5) == 0)
;
netlogic_write_reg(mmio, 0x0, c);
}
