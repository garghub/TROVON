static void mxc_expio_irq_handler(u32 irq, struct irq_desc *desc)
{
u32 imr_val;
u32 int_valid;
u32 expio_irq;
desc->irq_data.chip->irq_mask(&desc->irq_data);
imr_val = __raw_readw(brd_io + INTR_MASK_REG);
int_valid = __raw_readw(brd_io + INTR_STATUS_REG) & ~imr_val;
expio_irq = MXC_BOARD_IRQ_START;
for (; int_valid != 0; int_valid >>= 1, expio_irq++) {
if ((int_valid & 1) == 0)
continue;
generic_handle_irq(expio_irq);
}
desc->irq_data.chip->irq_ack(&desc->irq_data);
desc->irq_data.chip->irq_unmask(&desc->irq_data);
}
static void expio_mask_irq(struct irq_data *d)
{
u16 reg;
u32 expio = MXC_IRQ_TO_EXPIO(d->irq);
reg = __raw_readw(brd_io + INTR_MASK_REG);
reg |= (1 << expio);
__raw_writew(reg, brd_io + INTR_MASK_REG);
}
static void expio_ack_irq(struct irq_data *d)
{
u32 expio = MXC_IRQ_TO_EXPIO(d->irq);
__raw_writew(1 << expio, brd_io + INTR_RESET_REG);
__raw_writew(0, brd_io + INTR_RESET_REG);
expio_mask_irq(d);
}
static void expio_unmask_irq(struct irq_data *d)
{
u16 reg;
u32 expio = MXC_IRQ_TO_EXPIO(d->irq);
reg = __raw_readw(brd_io + INTR_MASK_REG);
reg &= ~(1 << expio);
__raw_writew(reg, brd_io + INTR_MASK_REG);
}
int __init mxc_expio_init(u32 base, u32 p_irq)
{
int i;
brd_io = ioremap(BOARD_IO_ADDR(base), SZ_4K);
if (brd_io == NULL)
return -ENOMEM;
if ((__raw_readw(brd_io + MAGIC_NUMBER1_REG) != 0xAAAA) ||
(__raw_readw(brd_io + MAGIC_NUMBER2_REG) != 0x5555) ||
(__raw_readw(brd_io + MAGIC_NUMBER3_REG) != 0xCAFE)) {
pr_info("3-Stack Debug board not detected\n");
iounmap(brd_io);
brd_io = NULL;
return -ENODEV;
}
pr_info("3-Stack Debug board detected, rev = 0x%04X\n",
readw(brd_io + CPLD_CODE_VER_REG));
gpio_request(MXC_IRQ_TO_GPIO(p_irq), "expio_pirq");
gpio_direction_input(MXC_IRQ_TO_GPIO(p_irq));
__raw_writew(0, brd_io + INTR_MASK_REG);
__raw_writew(0xFFFF, brd_io + INTR_RESET_REG);
__raw_writew(0, brd_io + INTR_RESET_REG);
__raw_writew(0x1F, brd_io + INTR_MASK_REG);
for (i = MXC_EXP_IO_BASE;
i < (MXC_EXP_IO_BASE + MXC_MAX_EXP_IO_LINES); i++) {
irq_set_chip_and_handler(i, &expio_irq_chip, handle_level_irq);
set_irq_flags(i, IRQF_VALID);
}
irq_set_irq_type(p_irq, IRQF_TRIGGER_LOW);
irq_set_chained_handler(p_irq, mxc_expio_irq_handler);
smsc911x_resources[0].start = LAN9217_BASE_ADDR(base);
smsc911x_resources[0].end = LAN9217_BASE_ADDR(base) + 0x100 - 1;
platform_device_register(&smsc_lan9217_device);
return 0;
}
