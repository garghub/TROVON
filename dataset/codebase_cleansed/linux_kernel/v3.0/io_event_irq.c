static struct pseries_elog_section *find_xelog_section(struct rtas_error_log *elog,
uint16_t sect_id)
{
struct rtas_ext_event_log_v6 *xelog =
(struct rtas_ext_event_log_v6 *) elog->buffer;
struct pseries_elog_section *sect;
unsigned char *p, *log_end;
if (elog->extended_log_length < sizeof(struct rtas_ext_event_log_v6) ||
xelog->log_format != RTAS_V6EXT_LOG_FORMAT_EVENT_LOG ||
xelog->company_id != RTAS_V6EXT_COMPANY_ID_IBM)
return NULL;
log_end = elog->buffer + elog->extended_log_length;
p = xelog->vendor_log;
while (p < log_end) {
sect = (struct pseries_elog_section *)p;
if (sect->id == sect_id)
return sect;
p += sect->length;
}
return NULL;
}
static struct pseries_io_event * ioei_find_event(struct rtas_error_log *elog)
{
struct pseries_elog_section *sect;
if (unlikely(elog->type != RTAS_TYPE_IO)) {
printk_once(KERN_WARNING "io_event_irq: Unexpected event type %d",
elog->type);
return NULL;
}
sect = find_xelog_section(elog, PSERIES_ELOG_SECT_ID_IO_EVENT);
if (unlikely(!sect)) {
printk_once(KERN_WARNING "io_event_irq: RTAS extended event "
"log does not contain an IO Event section. "
"Could be a bug in system firmware!\n");
return NULL;
}
return (struct pseries_io_event *) &sect->data;
}
static irqreturn_t ioei_interrupt(int irq, void *dev_id)
{
struct pseries_io_event *event;
int rtas_rc;
for (;;) {
rtas_rc = rtas_call(ioei_check_exception_token, 6, 1, NULL,
RTAS_VECTOR_EXTERNAL_INTERRUPT,
virq_to_hw(irq),
RTAS_IO_EVENTS, 1 ,
__pa(ioei_rtas_buf),
RTAS_DATA_BUF_SIZE);
if (rtas_rc != 0)
break;
event = ioei_find_event((struct rtas_error_log *)ioei_rtas_buf);
if (!event)
continue;
atomic_notifier_call_chain(&pseries_ioei_notifier_list,
0, event);
}
return IRQ_HANDLED;
}
static int __init ioei_init(void)
{
struct device_node *np;
ioei_check_exception_token = rtas_token("check-exception");
if (ioei_check_exception_token == RTAS_UNKNOWN_SERVICE) {
pr_warning("IO Event IRQ not supported on this system !\n");
return -ENODEV;
}
np = of_find_node_by_path("/event-sources/ibm,io-events");
if (np) {
request_event_sources_irqs(np, ioei_interrupt, "IO_EVENT");
of_node_put(np);
} else {
pr_err("io_event_irq: No ibm,io-events on system! "
"IO Event interrupt disabled.\n");
return -ENODEV;
}
return 0;
}
