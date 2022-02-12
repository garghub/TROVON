struct device_node *dss_of_port_get_parent_device(struct device_node *port)
{
struct device_node *np;
int i;
if (!port)
return NULL;
np = of_get_parent(port);
for (i = 0; i < 2 && np; ++i) {
struct property *prop;
prop = of_find_property(np, "compatible", NULL);
if (prop)
return np;
np = of_get_next_parent(np);
}
return NULL;
}
u32 dss_of_port_get_port_number(struct device_node *port)
{
int r;
u32 reg;
r = of_property_read_u32(port, "reg", &reg);
if (r)
reg = 0;
return reg;
}
struct omap_dss_device *
omapdss_of_find_source_for_first_ep(struct device_node *node)
{
struct device_node *ep;
struct device_node *src_port;
struct omap_dss_device *src;
ep = of_graph_get_endpoint_by_regs(node, 0, 0);
if (!ep)
return ERR_PTR(-EINVAL);
src_port = of_graph_get_remote_port(ep);
if (!src_port) {
of_node_put(ep);
return ERR_PTR(-EINVAL);
}
of_node_put(ep);
src = omap_dss_find_output_by_port_node(src_port);
of_node_put(src_port);
return src ? src : ERR_PTR(-EPROBE_DEFER);
}
