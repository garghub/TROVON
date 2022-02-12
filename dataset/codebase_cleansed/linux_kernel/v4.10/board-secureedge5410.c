static irqreturn_t eraseconfig_interrupt(int irq, void *dev_id)
{
printk("SnapGear: erase switch interrupt!\n");
return IRQ_HANDLED;
}
static int __init eraseconfig_init(void)
{
unsigned int irq = evt2irq(0x240);
printk("SnapGear: EraseConfig init\n");
if (request_irq(irq, eraseconfig_interrupt, 0, "Erase Config", NULL))
printk("SnapGear: failed to register IRQ%d for Reset witch\n",
irq);
else
printk("SnapGear: registered EraseConfig switch on IRQ%d\n",
irq);
return 0;
}
static void __init init_snapgear_IRQ(void)
{
printk("Setup SnapGear IRQ/IPR ...\n");
plat_irq_setup_pins(IRQ_MODE_IRQ);
}
