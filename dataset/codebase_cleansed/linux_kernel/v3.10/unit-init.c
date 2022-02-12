asmlinkage void __init unit_init(void)
{
SET_XIRQ_TRIGGER(0, XIRQ_TRIGGER_HILEVEL);
SET_XIRQ_TRIGGER(2, XIRQ_TRIGGER_LOWLEVEL);
SET_XIRQ_TRIGGER(3, XIRQ_TRIGGER_HILEVEL);
SET_XIRQ_TRIGGER(4, XIRQ_TRIGGER_LOWLEVEL);
SET_XIRQ_TRIGGER(5, XIRQ_TRIGGER_LOWLEVEL);
#ifdef CONFIG_EXT_SERIAL_IRQ_LEVEL
set_intr_level(XIRQ0, NUM2GxICR_LEVEL(CONFIG_EXT_SERIAL_IRQ_LEVEL));
#endif
#ifdef CONFIG_ETHERNET_IRQ_LEVEL
set_intr_level(XIRQ3, NUM2GxICR_LEVEL(CONFIG_ETHERNET_IRQ_LEVEL));
#endif
}
void __init unit_setup(void)
{
}
void __init unit_init_IRQ(void)
{
unsigned int extnum;
for (extnum = 0; extnum < NR_XIRQS; extnum++) {
switch (GET_XIRQ_TRIGGER(extnum)) {
case XIRQ_TRIGGER_HILEVEL:
case XIRQ_TRIGGER_LOWLEVEL:
mn10300_set_lateack_irq_type(XIRQ2IRQ(extnum));
break;
default:
break;
}
}
}
