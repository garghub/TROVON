static irqreturn_t dummy_interrupt(int irq, void *dev_id)
{
static int count = 0;
if (count == 0) {
printk(KERN_INFO "dummy-irq: interrupt occurred on IRQ %d\n",
irq);
count++;
}
return IRQ_NONE;
}
static int __init dummy_irq_init(void)
{
if (irq < 0) {
printk(KERN_ERR "dummy-irq: no IRQ given. Use irq=N\n");
return -EIO;
}
if (request_irq(irq, &dummy_interrupt, IRQF_SHARED, "dummy_irq", &irq)) {
printk(KERN_ERR "dummy-irq: cannot register IRQ %d\n", irq);
return -EIO;
}
printk(KERN_INFO "dummy-irq: registered for IRQ %d\n", irq);
return 0;
}
static void __exit dummy_irq_exit(void)
{
printk(KERN_INFO "dummy-irq unloaded\n");
free_irq(irq, &irq);
}
