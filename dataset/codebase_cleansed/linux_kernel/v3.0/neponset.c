static void
neponset_irq_handler(unsigned int irq, struct irq_desc *desc)
{
unsigned int irr;
while (1) {
desc->irq_data.chip->irq_ack(&desc->irq_data);
irr = IRR ^ (IRR_ETHERNET | IRR_USAR);
if ((irr & (IRR_ETHERNET | IRR_USAR | IRR_SA1111)) == 0)
break;
if (irr & (IRR_ETHERNET | IRR_USAR)) {
desc->irq_data.chip->irq_mask(&desc->irq_data);
desc->irq_data.chip->irq_ack(&desc->irq_data);
if (irr & IRR_ETHERNET) {
generic_handle_irq(IRQ_NEPONSET_SMC9196);
}
if (irr & IRR_USAR) {
generic_handle_irq(IRQ_NEPONSET_USAR);
}
desc->irq_data.chip->irq_unmask(&desc->irq_data);
}
if (irr & IRR_SA1111) {
generic_handle_irq(IRQ_NEPONSET_SA1111);
}
}
}
static void neponset_set_mctrl(struct uart_port *port, u_int mctrl)
{
u_int mdm_ctl0 = MDM_CTL_0;
if (port->mapbase == _Ser1UTCR0) {
if (mctrl & TIOCM_RTS)
mdm_ctl0 &= ~MDM_CTL0_RTS2;
else
mdm_ctl0 |= MDM_CTL0_RTS2;
if (mctrl & TIOCM_DTR)
mdm_ctl0 &= ~MDM_CTL0_DTR2;
else
mdm_ctl0 |= MDM_CTL0_DTR2;
} else if (port->mapbase == _Ser3UTCR0) {
if (mctrl & TIOCM_RTS)
mdm_ctl0 &= ~MDM_CTL0_RTS1;
else
mdm_ctl0 |= MDM_CTL0_RTS1;
if (mctrl & TIOCM_DTR)
mdm_ctl0 &= ~MDM_CTL0_DTR1;
else
mdm_ctl0 |= MDM_CTL0_DTR1;
}
MDM_CTL_0 = mdm_ctl0;
}
static u_int neponset_get_mctrl(struct uart_port *port)
{
u_int ret = TIOCM_CD | TIOCM_CTS | TIOCM_DSR;
u_int mdm_ctl1 = MDM_CTL_1;
if (port->mapbase == _Ser1UTCR0) {
if (mdm_ctl1 & MDM_CTL1_DCD2)
ret &= ~TIOCM_CD;
if (mdm_ctl1 & MDM_CTL1_CTS2)
ret &= ~TIOCM_CTS;
if (mdm_ctl1 & MDM_CTL1_DSR2)
ret &= ~TIOCM_DSR;
} else if (port->mapbase == _Ser3UTCR0) {
if (mdm_ctl1 & MDM_CTL1_DCD1)
ret &= ~TIOCM_CD;
if (mdm_ctl1 & MDM_CTL1_CTS1)
ret &= ~TIOCM_CTS;
if (mdm_ctl1 & MDM_CTL1_DSR1)
ret &= ~TIOCM_DSR;
}
return ret;
}
static int __devinit neponset_probe(struct platform_device *dev)
{
sa1100_register_uart_fns(&neponset_port_fns);
irq_set_irq_type(IRQ_GPIO25, IRQ_TYPE_EDGE_RISING);
irq_set_chained_handler(IRQ_GPIO25, neponset_irq_handler);
#if 0
enable_irq_wake(IRQ_GPIO25);
#endif
irq_set_handler(IRQ_NEPONSET_SMC9196, handle_simple_irq);
set_irq_flags(IRQ_NEPONSET_SMC9196, IRQF_VALID | IRQF_PROBE);
irq_set_handler(IRQ_NEPONSET_USAR, handle_simple_irq);
set_irq_flags(IRQ_NEPONSET_USAR, IRQF_VALID | IRQF_PROBE);
NCR_0 = NCR_GP01_OFF;
return 0;
}
static int neponset_suspend(struct platform_device *dev, pm_message_t state)
{
neponset_saved_state = NCR_0;
return 0;
}
static int neponset_resume(struct platform_device *dev)
{
NCR_0 = neponset_saved_state;
return 0;
}
static int __init neponset_init(void)
{
platform_driver_register(&neponset_device_driver);
if (!machine_is_assabet())
return -ENODEV;
sa1110_mb_disable();
if (!machine_has_neponset()) {
printk(KERN_DEBUG "Neponset expansion board not present\n");
return -ENODEV;
}
if (WHOAMI != 0x11) {
printk(KERN_WARNING "Neponset board detected, but "
"wrong ID: %02x\n", WHOAMI);
return -ENODEV;
}
return platform_add_devices(devices, ARRAY_SIZE(devices));
}
void __init neponset_map_io(void)
{
iotable_init(neponset_io_desc, ARRAY_SIZE(neponset_io_desc));
}
