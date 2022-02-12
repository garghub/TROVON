static void mxc_expio_irq_handler(struct irq_desc *desc)
{
u32 imr_val;
u32 int_valid;
u32 expio_irq;
desc->irq_data.chip->irq_mask(&desc->irq_data);
imr_val = imx_readw(brd_io + INTR_MASK_REG);
int_valid = imx_readw(brd_io + INTR_STATUS_REG) & ~imr_val;
expio_irq = 0;
for (; int_valid != 0; int_valid >>= 1, expio_irq++) {
if ((int_valid & 1) == 0)
continue;
generic_handle_irq(irq_find_mapping(domain, expio_irq));
}
desc->irq_data.chip->irq_ack(&desc->irq_data);
desc->irq_data.chip->irq_unmask(&desc->irq_data);
}
static void expio_mask_irq(struct irq_data *d)
{
u16 reg;
u32 expio = d->hwirq;
reg = imx_readw(brd_io + INTR_MASK_REG);
reg |= (1 << expio);
imx_writew(reg, brd_io + INTR_MASK_REG);
}
static void expio_ack_irq(struct irq_data *d)
{
u32 expio = d->hwirq;
imx_writew(1 << expio, brd_io + INTR_RESET_REG);
imx_writew(0, brd_io + INTR_RESET_REG);
expio_mask_irq(d);
}
static void expio_unmask_irq(struct irq_data *d)
{
u16 reg;
u32 expio = d->hwirq;
reg = imx_readw(brd_io + INTR_MASK_REG);
reg &= ~(1 << expio);
imx_writew(reg, brd_io + INTR_MASK_REG);
}
int __init mxc_expio_init(u32 base, u32 intr_gpio)
{
u32 p_irq = gpio_to_irq(intr_gpio);
int irq_base;
int i;
brd_io = ioremap(BOARD_IO_ADDR(base), SZ_4K);
if (brd_io == NULL)
return -ENOMEM;
if ((imx_readw(brd_io + MAGIC_NUMBER1_REG) != 0xAAAA) ||
(imx_readw(brd_io + MAGIC_NUMBER2_REG) != 0x5555) ||
(imx_readw(brd_io + MAGIC_NUMBER3_REG) != 0xCAFE)) {
pr_info("3-Stack Debug board not detected\n");
iounmap(brd_io);
brd_io = NULL;
return -ENODEV;
}
pr_info("3-Stack Debug board detected, rev = 0x%04X\n",
readw(brd_io + CPLD_CODE_VER_REG));
gpio_request(intr_gpio, "expio_pirq");
gpio_direction_input(intr_gpio);
imx_writew(0, brd_io + INTR_MASK_REG);
imx_writew(0xFFFF, brd_io + INTR_RESET_REG);
imx_writew(0, brd_io + INTR_RESET_REG);
imx_writew(0x1F, brd_io + INTR_MASK_REG);
irq_base = irq_alloc_descs(-1, 0, MXC_MAX_EXP_IO_LINES, numa_node_id());
WARN_ON(irq_base < 0);
domain = irq_domain_add_legacy(NULL, MXC_MAX_EXP_IO_LINES, irq_base, 0,
&irq_domain_simple_ops, NULL);
WARN_ON(!domain);
for (i = irq_base; i < irq_base + MXC_MAX_EXP_IO_LINES; i++) {
irq_set_chip_and_handler(i, &expio_irq_chip, handle_level_irq);
irq_clear_status_flags(i, IRQ_NOREQUEST);
}
irq_set_irq_type(p_irq, IRQF_TRIGGER_LOW);
irq_set_chained_handler(p_irq, mxc_expio_irq_handler);
regulator_register_fixed(0, dummy_supplies, ARRAY_SIZE(dummy_supplies));
smsc911x_resources[0].start = LAN9217_BASE_ADDR(base);
smsc911x_resources[0].end = LAN9217_BASE_ADDR(base) + 0x100 - 1;
smsc911x_resources[1].start = irq_find_mapping(domain, EXPIO_INT_ENET);
smsc911x_resources[1].end = irq_find_mapping(domain, EXPIO_INT_ENET);
platform_device_register(&smsc_lan9217_device);
return 0;
}
