void __init oss_init(void)
{
int i;
if (!oss_present) return;
oss = (struct mac_oss *) OSS_BASE;
for (i = 0; i < OSS_NUM_SOURCES; i++)
oss->irq_level[i] = 0;
}
void __init oss_nubus_init(void)
{
}
static void oss_irq(struct irq_desc *desc)
{
int events = oss->irq_pending &
(OSS_IP_IOPSCC | OSS_IP_SCSI | OSS_IP_IOPISM);
#ifdef DEBUG_IRQS
if ((console_loglevel == 10) && !(events & OSS_IP_SCSI)) {
unsigned int irq = irq_desc_get_irq(desc);
printk("oss_irq: irq %u events = 0x%04X\n", irq,
(int) oss->irq_pending);
}
#endif
if (events & OSS_IP_IOPSCC) {
oss->irq_pending &= ~OSS_IP_IOPSCC;
generic_handle_irq(IRQ_MAC_SCC);
}
if (events & OSS_IP_SCSI) {
oss->irq_pending &= ~OSS_IP_SCSI;
generic_handle_irq(IRQ_MAC_SCSI);
}
if (events & OSS_IP_IOPISM) {
oss->irq_pending &= ~OSS_IP_IOPISM;
generic_handle_irq(IRQ_MAC_ADB);
}
}
static void oss_nubus_irq(struct irq_desc *desc)
{
int events, irq_bit, i;
events = oss->irq_pending & OSS_IP_NUBUS;
if (!events)
return;
#ifdef DEBUG_NUBUS_INT
if (console_loglevel > 7) {
printk("oss_nubus_irq: events = 0x%04X\n", events);
}
#endif
i = 6;
irq_bit = 0x40;
do {
--i;
irq_bit >>= 1;
if (events & irq_bit) {
oss->irq_pending &= ~irq_bit;
generic_handle_irq(NUBUS_SOURCE_BASE + i);
}
} while(events & (irq_bit - 1));
}
void __init oss_register_interrupts(void)
{
irq_set_chained_handler(OSS_IRQLEV_IOPISM, oss_irq);
irq_set_chained_handler(OSS_IRQLEV_SCSI, oss_irq);
irq_set_chained_handler(OSS_IRQLEV_NUBUS, oss_nubus_irq);
irq_set_chained_handler(OSS_IRQLEV_IOPSCC, oss_irq);
irq_set_chained_handler(OSS_IRQLEV_VIA1, via1_irq);
oss->irq_level[OSS_VIA1] = IRQ_AUTO_6;
}
void oss_irq_enable(int irq) {
#ifdef DEBUG_IRQUSE
printk("oss_irq_enable(%d)\n", irq);
#endif
switch(irq) {
case IRQ_MAC_SCC:
oss->irq_level[OSS_IOPSCC] = OSS_IRQLEV_IOPSCC;
return;
case IRQ_MAC_ADB:
oss->irq_level[OSS_IOPISM] = OSS_IRQLEV_IOPISM;
return;
case IRQ_MAC_SCSI:
oss->irq_level[OSS_SCSI] = OSS_IRQLEV_SCSI;
return;
case IRQ_NUBUS_9:
case IRQ_NUBUS_A:
case IRQ_NUBUS_B:
case IRQ_NUBUS_C:
case IRQ_NUBUS_D:
case IRQ_NUBUS_E:
irq -= NUBUS_SOURCE_BASE;
oss->irq_level[irq] = OSS_IRQLEV_NUBUS;
return;
}
if (IRQ_SRC(irq) == 1)
via_irq_enable(irq);
}
void oss_irq_disable(int irq) {
#ifdef DEBUG_IRQUSE
printk("oss_irq_disable(%d)\n", irq);
#endif
switch(irq) {
case IRQ_MAC_SCC:
oss->irq_level[OSS_IOPSCC] = 0;
return;
case IRQ_MAC_ADB:
oss->irq_level[OSS_IOPISM] = 0;
return;
case IRQ_MAC_SCSI:
oss->irq_level[OSS_SCSI] = 0;
return;
case IRQ_NUBUS_9:
case IRQ_NUBUS_A:
case IRQ_NUBUS_B:
case IRQ_NUBUS_C:
case IRQ_NUBUS_D:
case IRQ_NUBUS_E:
irq -= NUBUS_SOURCE_BASE;
oss->irq_level[irq] = 0;
return;
}
if (IRQ_SRC(irq) == 1)
via_irq_disable(irq);
}
