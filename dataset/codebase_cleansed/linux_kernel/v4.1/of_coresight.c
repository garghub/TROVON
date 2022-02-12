static int of_dev_node_match(struct device *dev, void *data)
{
return dev->of_node == data;
}
static struct device *
of_coresight_get_endpoint_device(struct device_node *endpoint)
{
struct device *dev = NULL;
dev = bus_find_device(&platform_bus_type, NULL,
endpoint, of_dev_node_match);
if (dev)
return dev;
return bus_find_device(&amba_bustype, NULL,
endpoint, of_dev_node_match);
}
static void of_coresight_get_ports(struct device_node *node,
int *nr_inport, int *nr_outport)
{
struct device_node *ep = NULL;
int in = 0, out = 0;
do {
ep = of_graph_get_next_endpoint(node, ep);
if (!ep)
break;
if (of_property_read_bool(ep, "slave-mode"))
in++;
else
out++;
} while (ep);
*nr_inport = in;
*nr_outport = out;
}
static int of_coresight_alloc_memory(struct device *dev,
struct coresight_platform_data *pdata)
{
pdata->outports = devm_kzalloc(dev, pdata->nr_outport *
sizeof(*pdata->outports),
GFP_KERNEL);
if (!pdata->outports)
return -ENOMEM;
pdata->child_names = devm_kzalloc(dev, pdata->nr_outport *
sizeof(*pdata->child_names),
GFP_KERNEL);
if (!pdata->child_names)
return -ENOMEM;
pdata->child_ports = devm_kzalloc(dev, pdata->nr_outport *
sizeof(*pdata->child_ports),
GFP_KERNEL);
if (!pdata->child_ports)
return -ENOMEM;
return 0;
}
struct coresight_platform_data *of_get_coresight_platform_data(
struct device *dev, struct device_node *node)
{
int i = 0, ret = 0, cpu;
struct coresight_platform_data *pdata;
struct of_endpoint endpoint, rendpoint;
struct device *rdev;
struct device_node *dn;
struct device_node *ep = NULL;
struct device_node *rparent = NULL;
struct device_node *rport = NULL;
pdata = devm_kzalloc(dev, sizeof(*pdata), GFP_KERNEL);
if (!pdata)
return ERR_PTR(-ENOMEM);
pdata->name = dev_name(dev);
of_coresight_get_ports(node, &pdata->nr_inport, &pdata->nr_outport);
if (pdata->nr_outport) {
ret = of_coresight_alloc_memory(dev, pdata);
if (ret)
return ERR_PTR(ret);
do {
ep = of_graph_get_next_endpoint(node, ep);
if (!ep)
break;
if (of_find_property(ep, "slave-mode", NULL))
continue;
ret = of_graph_parse_endpoint(ep, &endpoint);
if (ret)
continue;
pdata->outports[i] = endpoint.id;
rparent = of_graph_get_remote_port_parent(ep);
rport = of_graph_get_remote_port(ep);
if (!rparent || !rport)
continue;
if (of_graph_parse_endpoint(rport, &rendpoint))
continue;
rdev = of_coresight_get_endpoint_device(rparent);
if (!rdev)
continue;
pdata->child_names[i] = dev_name(rdev);
pdata->child_ports[i] = rendpoint.id;
i++;
} while (ep);
}
pdata->cpu = 0;
dn = of_parse_phandle(node, "cpu", 0);
for (cpu = 0; dn && cpu < nr_cpu_ids; cpu++) {
if (dn == of_get_cpu_node(cpu, NULL)) {
pdata->cpu = cpu;
break;
}
}
return pdata;
}
