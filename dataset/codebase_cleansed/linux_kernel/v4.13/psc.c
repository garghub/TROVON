static void psc_debug_dump(void)
{
int i;
if (!psc)
return;
for (i = 0x30 ; i < 0x70 ; i += 0x10) {
printk("PSC #%d: IFR = 0x%02X IER = 0x%02X\n",
i >> 4,
(int) psc_read_byte(pIFRbase + i),
(int) psc_read_byte(pIERbase + i));
}
}
static __init void psc_dma_die_die_die(void)
{
int i;
printk("Killing all PSC DMA channels...");
for (i = 0 ; i < 9 ; i++) {
psc_write_word(PSC_CTL_BASE + (i << 4), 0x8800);
psc_write_word(PSC_CTL_BASE + (i << 4), 0x1000);
psc_write_word(PSC_CMD_BASE + (i << 5), 0x1100);
psc_write_word(PSC_CMD_BASE + (i << 5) + 0x10, 0x1100);
}
printk("done!\n");
}
void __init psc_init(void)
{
int i;
if (macintosh_config->ident != MAC_MODEL_C660
&& macintosh_config->ident != MAC_MODEL_Q840)
{
psc = NULL;
return;
}
psc = (void *) PSC_BASE;
printk("PSC detected at %p\n", psc);
psc_dma_die_die_die();
#ifdef DEBUG_PSC
psc_debug_dump();
#endif
for (i = 0x30 ; i < 0x70 ; i += 0x10) {
psc_write_byte(pIERbase + i, 0x0F);
psc_write_byte(pIFRbase + i, 0x0F);
}
}
static void psc_irq(struct irq_desc *desc)
{
unsigned int offset = (unsigned int)irq_desc_get_handler_data(desc);
unsigned int irq = irq_desc_get_irq(desc);
int pIFR = pIFRbase + offset;
int pIER = pIERbase + offset;
int irq_num;
unsigned char irq_bit, events;
events = psc_read_byte(pIFR) & psc_read_byte(pIER) & 0xF;
if (!events)
return;
irq_num = irq << 3;
irq_bit = 1;
do {
if (events & irq_bit) {
psc_write_byte(pIFR, irq_bit);
generic_handle_irq(irq_num);
}
irq_num++;
irq_bit <<= 1;
} while (events >= irq_bit);
}
void __init psc_register_interrupts(void)
{
irq_set_chained_handler_and_data(IRQ_AUTO_3, psc_irq, (void *)0x30);
irq_set_chained_handler_and_data(IRQ_AUTO_4, psc_irq, (void *)0x40);
irq_set_chained_handler_and_data(IRQ_AUTO_5, psc_irq, (void *)0x50);
irq_set_chained_handler_and_data(IRQ_AUTO_6, psc_irq, (void *)0x60);
}
void psc_irq_enable(int irq) {
int irq_src = IRQ_SRC(irq);
int irq_idx = IRQ_IDX(irq);
int pIER = pIERbase + (irq_src << 4);
psc_write_byte(pIER, (1 << irq_idx) | 0x80);
}
void psc_irq_disable(int irq) {
int irq_src = IRQ_SRC(irq);
int irq_idx = IRQ_IDX(irq);
int pIER = pIERbase + (irq_src << 4);
psc_write_byte(pIER, 1 << irq_idx);
}
