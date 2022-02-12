static void ack_bad(struct irq_data *data)
{
struct irq_desc *desc = irq_data_to_desc(data);
print_irq_desc(data->irq, desc);
ack_bad_irq(data->irq);
}
static void noop(struct irq_data *data) { }
static unsigned int noop_ret(struct irq_data *data)
{
return 0;
}
