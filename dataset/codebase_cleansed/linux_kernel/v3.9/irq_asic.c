static inline void unmask_asic_irq(struct irq_data *d)
{
unsigned long enable_bit;
unsigned int irq = d->irq;
enable_bit = (1 << (irq & 0x1f));
switch (irq >> 5) {
case 0:
asic_write(asic_read(ien_int_0) | enable_bit, ien_int_0);
break;
case 1:
asic_write(asic_read(ien_int_1) | enable_bit, ien_int_1);
break;
case 2:
asic_write(asic_read(ien_int_2) | enable_bit, ien_int_2);
break;
case 3:
asic_write(asic_read(ien_int_3) | enable_bit, ien_int_3);
break;
default:
BUG();
}
}
static inline void mask_asic_irq(struct irq_data *d)
{
unsigned long disable_mask;
unsigned int irq = d->irq;
disable_mask = ~(1 << (irq & 0x1f));
switch (irq >> 5) {
case 0:
asic_write(asic_read(ien_int_0) & disable_mask, ien_int_0);
break;
case 1:
asic_write(asic_read(ien_int_1) & disable_mask, ien_int_1);
break;
case 2:
asic_write(asic_read(ien_int_2) & disable_mask, ien_int_2);
break;
case 3:
asic_write(asic_read(ien_int_3) & disable_mask, ien_int_3);
break;
default:
BUG();
}
}
void __init asic_irq_init(void)
{
int i;
write_c0_status(read_c0_status() & ~(0x0000fc00));
asic_write(0, ien_int_0);
asic_write(0, ien_int_1);
asic_write(0, ien_int_2);
asic_write(0, ien_int_3);
asic_write(0x0fffffff, int_level_3_3);
asic_write(0xffffffff, int_level_3_2);
asic_write(0xffffffff, int_level_3_1);
asic_write(0xffffffff, int_level_3_0);
asic_write(0xffffffff, int_level_2_3);
asic_write(0xffffffff, int_level_2_2);
asic_write(0xffffffff, int_level_2_1);
asic_write(0xffffffff, int_level_2_0);
asic_write(0xffffffff, int_level_1_3);
asic_write(0xffffffff, int_level_1_2);
asic_write(0xffffffff, int_level_1_1);
asic_write(0xffffffff, int_level_1_0);
asic_write(0xffffffff, int_level_0_3);
asic_write(0xffffffff, int_level_0_2);
asic_write(0xffffffff, int_level_0_1);
asic_write(0xffffffff, int_level_0_0);
asic_write(0xf, int_int_scan);
for (i = 0; i < NR_IRQS; i++)
irq_set_chip_and_handler(i, &asic_irq_chip, handle_level_irq);
}
