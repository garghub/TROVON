void __init baboon_init(void)
{
if (macintosh_config->ident != MAC_MODEL_PB190) {
baboon = NULL;
baboon_present = 0;
return;
}
baboon = (struct baboon *) BABOON_BASE;
baboon_present = 1;
printk("Baboon detected at %p\n", baboon);
}
static void baboon_irq(struct irq_desc *desc)
{
int irq_bit, irq_num;
unsigned char events;
events = baboon->mb_ifr & 0x07;
if (!events)
return;
irq_num = IRQ_BABOON_0;
irq_bit = 1;
do {
if (events & irq_bit) {
baboon->mb_ifr &= ~irq_bit;
generic_handle_irq(irq_num);
}
irq_bit <<= 1;
irq_num++;
} while(events >= irq_bit);
#if 0
if (baboon->mb_ifr & 0x02) macide_ack_intr(NULL);
baboon->mb_ifr &= ~events;
#endif
}
void __init baboon_register_interrupts(void)
{
irq_set_chained_handler(IRQ_NUBUS_C, baboon_irq);
}
void baboon_irq_enable(int irq)
{
mac_irq_enable(irq_get_irq_data(IRQ_NUBUS_C));
}
void baboon_irq_disable(int irq)
{
mac_irq_disable(irq_get_irq_data(IRQ_NUBUS_C));
}
