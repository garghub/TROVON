struct device_node *
omapdss_of_get_next_port(const struct device_node *parent,
struct device_node *prev)
{
struct device_node *port = NULL;
if (!parent)
return NULL;
if (!prev) {
struct device_node *ports;
ports = of_get_child_by_name(parent, "ports");
if (ports)
parent = ports;
port = of_get_child_by_name(parent, "port");
of_node_put(ports);
} else {
struct device_node *ports;
ports = of_get_parent(prev);
if (!ports)
return NULL;
do {
port = of_get_next_child(ports, prev);
if (!port) {
of_node_put(ports);
return NULL;
}
prev = port;
} while (of_node_cmp(port->name, "port") != 0);
of_node_put(ports);
}
return port;
}
struct device_node *
omapdss_of_get_next_endpoint(const struct device_node *parent,
struct device_node *prev)
{
struct device_node *ep = NULL;
if (!parent)
return NULL;
do {
ep = of_get_next_child(parent, prev);
if (!ep)
return NULL;
prev = ep;
} while (of_node_cmp(ep->name, "endpoint") != 0);
return ep;
}
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
static struct device_node *omapdss_of_get_remote_port(const struct device_node *node)
{
struct device_node *np, *np_parent;
np = of_parse_phandle(node, "remote-endpoint", 0);
if (!np)
return NULL;
np_parent = of_get_next_parent(np);
of_node_put(np);
return np_parent;
}
struct device_node *
omapdss_of_get_first_endpoint(const struct device_node *parent)
{
struct device_node *port, *ep;
port = omapdss_of_get_next_port(parent, NULL);
if (!port)
return NULL;
ep = omapdss_of_get_next_endpoint(port, NULL);
of_node_put(port);
return ep;
}
struct omap_dss_device *
omapdss_of_find_source_for_first_ep(struct device_node *node)
{
struct device_node *ep;
struct device_node *src_port;
struct omap_dss_device *src;
ep = omapdss_of_get_first_endpoint(node);
if (!ep)
return ERR_PTR(-EINVAL);
src_port = omapdss_of_get_remote_port(ep);
if (!src_port) {
of_node_put(ep);
return ERR_PTR(-EINVAL);
}
of_node_put(ep);
src = omap_dss_find_output_by_port_node(src_port);
of_node_put(src_port);
return src ? src : ERR_PTR(-EPROBE_DEFER);
}
