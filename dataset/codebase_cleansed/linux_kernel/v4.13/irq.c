void __init sdk7786_init_irq(void)
{
unsigned int tmp;
fpga_write_reg(fpga_read_reg(INTMSR) | 0x0303, INTMSR);
fpga_write_reg(0x0000, INTASR);
fpga_write_reg(0x0000, INTBSR);
tmp = fpga_read_reg(INTAMR);
tmp &= ~(1 << ETH_IRQ_BIT);
fpga_write_reg(tmp, INTAMR);
plat_irq_setup_pins(IRQ_MODE_IRL7654_MASK);
plat_irq_setup_pins(IRQ_MODE_IRL3210_MASK);
}
