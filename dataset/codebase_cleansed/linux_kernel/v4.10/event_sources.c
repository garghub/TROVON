void request_event_sources_irqs(struct device_node *np,
irq_handler_t handler,
const char *name)
{
int i, index, count = 0;
struct of_phandle_args oirq;
unsigned int virqs[16];
for (index = 0; of_irq_parse_one(np, index, &oirq) == 0;
index++) {
if (count > 15)
break;
virqs[count] = irq_create_of_mapping(&oirq);
if (!virqs[count]) {
pr_err("event-sources: Unable to allocate "
"interrupt number for %s\n",
np->full_name);
WARN_ON(1);
} else {
count++;
}
}
for (i = 0; i < count; i++) {
if (request_irq(virqs[i], handler, 0, name, NULL)) {
pr_err("event-sources: Unable to request interrupt "
"%d for %s\n", virqs[i], np->full_name);
WARN_ON(1);
return;
}
}
}
