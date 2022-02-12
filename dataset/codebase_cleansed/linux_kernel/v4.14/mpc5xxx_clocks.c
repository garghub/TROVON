unsigned long mpc5xxx_get_bus_frequency(struct device_node *node)
{
const unsigned int *p_bus_freq = NULL;
of_node_get(node);
while (node) {
p_bus_freq = of_get_property(node, "bus-frequency", NULL);
if (p_bus_freq)
break;
node = of_get_next_parent(node);
}
of_node_put(node);
return p_bus_freq ? *p_bus_freq : 0;
}
