int __cpuinit local_timer_setup(struct clock_event_device *evt)
{
struct device_node *np;
np = of_find_compatible_node(NULL, NULL, "arm,smp-twd");
if (!twd_base) {
twd_base = of_iomap(np, 0);
WARN_ON(!twd_base);
}
evt->irq = irq_of_parse_and_map(np, 0);
twd_timer_setup(evt);
return 0;
}
