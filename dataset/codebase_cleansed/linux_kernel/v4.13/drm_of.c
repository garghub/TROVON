static void drm_release_of(struct device *dev, void *data)
{
of_node_put(data);
}
static uint32_t drm_crtc_port_mask(struct drm_device *dev,
struct device_node *port)
{
unsigned int index = 0;
struct drm_crtc *tmp;
drm_for_each_crtc(tmp, dev) {
if (tmp->port == port)
return 1 << index;
index++;
}
return 0;
}
uint32_t drm_of_find_possible_crtcs(struct drm_device *dev,
struct device_node *port)
{
struct device_node *remote_port, *ep;
uint32_t possible_crtcs = 0;
for_each_endpoint_of_node(port, ep) {
remote_port = of_graph_get_remote_port(ep);
if (!remote_port) {
of_node_put(ep);
return 0;
}
possible_crtcs |= drm_crtc_port_mask(dev, remote_port);
of_node_put(remote_port);
}
return possible_crtcs;
}
void drm_of_component_match_add(struct device *master,
struct component_match **matchptr,
int (*compare)(struct device *, void *),
struct device_node *node)
{
of_node_get(node);
component_match_add_release(master, matchptr, drm_release_of,
compare, node);
}
int drm_of_component_probe(struct device *dev,
int (*compare_of)(struct device *, void *),
const struct component_master_ops *m_ops)
{
struct device_node *ep, *port, *remote;
struct component_match *match = NULL;
int i;
if (!dev->of_node)
return -EINVAL;
for (i = 0; ; i++) {
port = of_parse_phandle(dev->of_node, "ports", i);
if (!port)
break;
if (!of_device_is_available(port->parent)) {
of_node_put(port);
continue;
}
drm_of_component_match_add(dev, &match, compare_of, port);
of_node_put(port);
}
if (i == 0) {
dev_err(dev, "missing 'ports' property\n");
return -ENODEV;
}
if (!match) {
dev_err(dev, "no available port\n");
return -ENODEV;
}
for (i = 0; ; i++) {
port = of_parse_phandle(dev->of_node, "ports", i);
if (!port)
break;
if (!of_device_is_available(port->parent)) {
of_node_put(port);
continue;
}
for_each_child_of_node(port, ep) {
remote = of_graph_get_remote_port_parent(ep);
if (!remote || !of_device_is_available(remote)) {
of_node_put(remote);
continue;
} else if (!of_device_is_available(remote->parent)) {
dev_warn(dev, "parent device of %s is not available\n",
remote->full_name);
of_node_put(remote);
continue;
}
drm_of_component_match_add(dev, &match, compare_of,
remote);
of_node_put(remote);
}
of_node_put(port);
}
return component_master_add_with_match(dev, m_ops, match);
}
int drm_of_encoder_active_endpoint(struct device_node *node,
struct drm_encoder *encoder,
struct of_endpoint *endpoint)
{
struct device_node *ep;
struct drm_crtc *crtc = encoder->crtc;
struct device_node *port;
int ret;
if (!node || !crtc)
return -EINVAL;
for_each_endpoint_of_node(node, ep) {
port = of_graph_get_remote_port(ep);
of_node_put(port);
if (port == crtc->port) {
ret = of_graph_parse_endpoint(ep, endpoint);
of_node_put(ep);
return ret;
}
}
return -EINVAL;
}
int drm_of_find_panel_or_bridge(const struct device_node *np,
int port, int endpoint,
struct drm_panel **panel,
struct drm_bridge **bridge)
{
int ret = -EPROBE_DEFER;
struct device_node *remote;
if (!panel && !bridge)
return -EINVAL;
remote = of_graph_get_remote_node(np, port, endpoint);
if (!remote)
return -ENODEV;
if (panel) {
*panel = of_drm_find_panel(remote);
if (*panel)
ret = 0;
}
if (bridge) {
if (ret) {
*bridge = of_drm_find_bridge(remote);
if (*bridge)
ret = 0;
} else {
*bridge = NULL;
}
}
of_node_put(remote);
return ret;
}
