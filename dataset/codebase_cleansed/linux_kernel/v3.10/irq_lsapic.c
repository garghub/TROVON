static unsigned int
lsapic_noop_startup (struct irq_data *data)
{
return 0;
}
static void
lsapic_noop (struct irq_data *data)
{
}
static int lsapic_retrigger(struct irq_data *data)
{
ia64_resend_irq(data->irq);
return 1;
}
