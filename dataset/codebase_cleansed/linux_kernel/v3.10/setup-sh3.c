void __init plat_irq_setup_pins(int mode)
{
if (mode == IRQ_MODE_IRQ) {
__raw_writew(__raw_readw(INTC_ICR1) & ~INTC_ICR1_IRQLVL, INTC_ICR1);
register_intc_controller(&intc_desc_irq0123);
return;
}
BUG();
}
void __init plat_irq_setup_sh3(void)
{
register_intc_controller(&intc_desc_irq45);
}
