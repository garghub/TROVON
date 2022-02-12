unsigned long mpc5xxx_get_bus_frequency(struct device_node *node)
{
struct device_node *np;
const unsigned int *p_bus_freq = NULL;
of_node_get(node);
while (node) {
p_bus_freq = of_get_property(node, "bus-frequency", NULL);
if (p_bus_freq)
break;
np = of_get_parent(node);
of_node_put(node);
node = np;
}
of_node_put(node);
return p_bus_freq ? *p_bus_freq : 0;
}
