static void setup_modem_intcon(void __iomem *modem_intcon_base)
{
writel(MODEM_INTCON_CPU_NBR, modem_intcon_base + DEST_IRQ41_OFFSET);
writel(MODEM_INTCON_CPU_NBR, modem_intcon_base + DEST_IRQ43_OFFSET);
writel(MODEM_INTCON_CPU_NBR, modem_intcon_base + DEST_IRQ45_OFFSET);
writel(MODEM_INTCON_PRIO_HIGH, modem_intcon_base + PRIO_IRQ41_OFFSET);
writel(MODEM_INTCON_PRIO_HIGH, modem_intcon_base + PRIO_IRQ43_OFFSET);
writel(MODEM_INTCON_PRIO_HIGH, modem_intcon_base + PRIO_IRQ45_OFFSET);
writel(MODEM_INTCON_ALLOW_IRQ41 |
MODEM_INTCON_ALLOW_IRQ43 |
MODEM_INTCON_ALLOW_IRQ45,
modem_intcon_base + ALLOW_IRQ_OFFSET);
}
static irqreturn_t modem_cpu_irq_handler(int irq, void *data)
{
int real_irq;
int virt_irq;
struct modem_irq *mi = (struct modem_irq *)data;
real_irq = readl(mi->modem_intcon_base + MODEM_IRQ_REG_OFFSET) & 0xFF;
virt_irq = IRQ_MODEM_EVENTS_BASE + real_irq;
pr_debug("modem_irq: Worker read addr 0x%X and got value 0x%X "
"which will be 0x%X (%d) which translates to "
"virtual IRQ 0x%X (%d)!\n",
(u32)mi->modem_intcon_base + MODEM_IRQ_REG_OFFSET,
real_irq,
real_irq & 0xFF,
real_irq & 0xFF,
virt_irq,
virt_irq);
if (virt_irq != 0)
generic_handle_irq(virt_irq);
pr_debug("modem_irq: Done handling virtual IRQ %d!\n", virt_irq);
return IRQ_HANDLED;
}
static void create_virtual_irq(int irq, struct irq_chip *modem_irq_chip)
{
irq_set_chip_and_handler(irq, modem_irq_chip, handle_simple_irq);
set_irq_flags(irq, IRQF_VALID);
pr_debug("modem_irq: Created virtual IRQ %d\n", irq);
}
static int modem_irq_init(void)
{
int err;
static struct irq_chip modem_irq_chip;
struct modem_irq *mi;
if (!cpu_is_u5500())
return -ENODEV;
pr_info("modem_irq: Set up IRQ handler for incoming modem IRQ %d\n",
IRQ_DB5500_MODEM);
mi = kmalloc(sizeof(struct modem_irq), GFP_KERNEL);
if (!mi) {
pr_err("modem_irq: Could not allocate device\n");
return -ENOMEM;
}
mi->modem_intcon_base =
ioremap(MODEM_INTCON_BASE_ADDR, MODEM_INTCON_SIZE);
pr_debug("modem_irq: ioremapped modem_intcon_base from "
"phy 0x%x to virt 0x%x\n", MODEM_INTCON_BASE_ADDR,
(u32)mi->modem_intcon_base);
setup_modem_intcon(mi->modem_intcon_base);
modem_irq_chip = dummy_irq_chip;
modem_irq_chip.name = "modem_irq";
create_virtual_irq(MBOX_PAIR0_VIRT_IRQ, &modem_irq_chip);
create_virtual_irq(MBOX_PAIR1_VIRT_IRQ, &modem_irq_chip);
create_virtual_irq(MBOX_PAIR2_VIRT_IRQ, &modem_irq_chip);
err = request_threaded_irq(IRQ_DB5500_MODEM, NULL,
modem_cpu_irq_handler, IRQF_ONESHOT,
"modem_irq", mi);
if (err)
pr_err("modem_irq: Could not register IRQ %d\n",
IRQ_DB5500_MODEM);
return 0;
}
