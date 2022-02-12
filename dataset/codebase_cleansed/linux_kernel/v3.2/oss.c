void __init oss_init(void)
{
int i;
if (!oss_present) return;
oss = (struct mac_oss *) OSS_BASE;
for (i = 0; i <= OSS_NUM_SOURCES; i++) {
oss->irq_level[i] = OSS_IRQLEV_DISABLED;
}
oss->irq_level[OSS_VIA1] = OSS_IRQLEV_VIA1;
}
void __init oss_nubus_init(void)
{
}
static void oss_irq(unsigned int irq, struct irq_desc *desc)
{
int events;
events = oss->irq_pending & (OSS_IP_SOUND|OSS_IP_SCSI);
if (!events)
return;
#ifdef DEBUG_IRQS
if ((console_loglevel == 10) && !(events & OSS_IP_SCSI)) {
printk("oss_irq: irq %u events = 0x%04X\n", irq,
(int) oss->irq_pending);
}
#endif
if (events & OSS_IP_SOUND) {
oss->irq_pending &= ~OSS_IP_SOUND;
} else if (events & OSS_IP_SCSI) {
oss->irq_pending &= ~OSS_IP_SCSI;
generic_handle_irq(IRQ_MAC_SCSI);
} else {
}
}
static void oss_nubus_irq(unsigned int irq, struct irq_desc *desc)
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
irq_set_chained_handler(OSS_IRQLEV_SCSI, oss_irq);
irq_set_chained_handler(OSS_IRQLEV_NUBUS, oss_nubus_irq);
irq_set_chained_handler(OSS_IRQLEV_SOUND, oss_irq);
irq_set_chained_handler(OSS_IRQLEV_VIA1, via1_irq);
}
void oss_irq_enable(int irq) {
#ifdef DEBUG_IRQUSE
printk("oss_irq_enable(%d)\n", irq);
#endif
switch(irq) {
case IRQ_MAC_SCC:
oss->irq_level[OSS_IOPSCC] = OSS_IRQLEV_IOPSCC;
break;
case IRQ_MAC_ADB:
oss->irq_level[OSS_IOPISM] = OSS_IRQLEV_IOPISM;
break;
case IRQ_MAC_SCSI:
oss->irq_level[OSS_SCSI] = OSS_IRQLEV_SCSI;
break;
case IRQ_NUBUS_9:
case IRQ_NUBUS_A:
case IRQ_NUBUS_B:
case IRQ_NUBUS_C:
case IRQ_NUBUS_D:
case IRQ_NUBUS_E:
irq -= NUBUS_SOURCE_BASE;
oss->irq_level[irq] = OSS_IRQLEV_NUBUS;
break;
#ifdef DEBUG_IRQUSE
default:
printk("%s unknown irq %d\n", __func__, irq);
break;
#endif
}
}
void oss_irq_disable(int irq) {
#ifdef DEBUG_IRQUSE
printk("oss_irq_disable(%d)\n", irq);
#endif
switch(irq) {
case IRQ_MAC_SCC:
oss->irq_level[OSS_IOPSCC] = OSS_IRQLEV_DISABLED;
break;
case IRQ_MAC_ADB:
oss->irq_level[OSS_IOPISM] = OSS_IRQLEV_DISABLED;
break;
case IRQ_MAC_SCSI:
oss->irq_level[OSS_SCSI] = OSS_IRQLEV_DISABLED;
break;
case IRQ_NUBUS_9:
case IRQ_NUBUS_A:
case IRQ_NUBUS_B:
case IRQ_NUBUS_C:
case IRQ_NUBUS_D:
case IRQ_NUBUS_E:
irq -= NUBUS_SOURCE_BASE;
oss->irq_level[irq] = OSS_IRQLEV_DISABLED;
break;
#ifdef DEBUG_IRQUSE
default:
printk("%s unknown irq %d\n", __func__, irq);
break;
#endif
}
}
void oss_irq_clear(int irq) {
switch(irq) {
case IRQ_MAC_SCC:
oss->irq_pending &= ~OSS_IP_IOPSCC;
break;
case IRQ_MAC_ADB:
oss->irq_pending &= ~OSS_IP_IOPISM;
break;
case IRQ_MAC_SCSI:
oss->irq_pending &= ~OSS_IP_SCSI;
break;
case IRQ_NUBUS_9:
case IRQ_NUBUS_A:
case IRQ_NUBUS_B:
case IRQ_NUBUS_C:
case IRQ_NUBUS_D:
case IRQ_NUBUS_E:
irq -= NUBUS_SOURCE_BASE;
oss->irq_pending &= ~(1 << irq);
break;
}
}
int oss_irq_pending(int irq)
{
switch(irq) {
case IRQ_MAC_SCC:
return oss->irq_pending & OSS_IP_IOPSCC;
break;
case IRQ_MAC_ADB:
return oss->irq_pending & OSS_IP_IOPISM;
break;
case IRQ_MAC_SCSI:
return oss->irq_pending & OSS_IP_SCSI;
break;
case IRQ_NUBUS_9:
case IRQ_NUBUS_A:
case IRQ_NUBUS_B:
case IRQ_NUBUS_C:
case IRQ_NUBUS_D:
case IRQ_NUBUS_E:
irq -= NUBUS_SOURCE_BASE;
return oss->irq_pending & (1 << irq);
break;
}
return 0;
}
