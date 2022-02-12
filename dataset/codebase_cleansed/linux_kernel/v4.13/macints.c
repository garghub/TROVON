void __init mac_init_IRQ(void)
{
m68k_setup_irq_controller(&mac_irq_chip, handle_simple_irq, IRQ_USER,
NUM_MAC_SOURCES - IRQ_USER);
if (oss_present)
oss_register_interrupts();
else
via_register_interrupts();
if (psc)
psc_register_interrupts();
if (baboon_present)
baboon_register_interrupts();
iop_register_interrupts();
if (request_irq(IRQ_AUTO_7, mac_nmi_handler, 0, "NMI",
mac_nmi_handler))
pr_err("Couldn't register NMI\n");
}
void mac_irq_enable(struct irq_data *data)
{
int irq = data->irq;
int irq_src = IRQ_SRC(irq);
switch(irq_src) {
case 1:
case 2:
case 7:
if (oss_present)
oss_irq_enable(irq);
else
via_irq_enable(irq);
break;
case 3:
case 4:
case 5:
case 6:
if (psc)
psc_irq_enable(irq);
else if (oss_present)
oss_irq_enable(irq);
break;
case 8:
if (baboon_present)
baboon_irq_enable(irq);
break;
}
}
void mac_irq_disable(struct irq_data *data)
{
int irq = data->irq;
int irq_src = IRQ_SRC(irq);
switch(irq_src) {
case 1:
case 2:
case 7:
if (oss_present)
oss_irq_disable(irq);
else
via_irq_disable(irq);
break;
case 3:
case 4:
case 5:
case 6:
if (psc)
psc_irq_disable(irq);
else if (oss_present)
oss_irq_disable(irq);
break;
case 8:
if (baboon_present)
baboon_irq_disable(irq);
break;
}
}
static unsigned int mac_irq_startup(struct irq_data *data)
{
int irq = data->irq;
if (IRQ_SRC(irq) == 7 && !oss_present)
via_nubus_irq_startup(irq);
else
mac_irq_enable(data);
return 0;
}
static void mac_irq_shutdown(struct irq_data *data)
{
int irq = data->irq;
if (IRQ_SRC(irq) == 7 && !oss_present)
via_nubus_irq_shutdown(irq);
else
mac_irq_disable(data);
}
irqreturn_t mac_nmi_handler(int irq, void *dev_id)
{
if (in_nmi)
return IRQ_HANDLED;
in_nmi = 1;
pr_info("Non-Maskable Interrupt\n");
show_registers(get_irq_regs());
in_nmi = 0;
return IRQ_HANDLED;
}
