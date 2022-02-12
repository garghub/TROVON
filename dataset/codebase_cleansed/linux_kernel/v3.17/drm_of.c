static uint32_t drm_crtc_port_mask(struct drm_device *dev,
struct device_node *port)
{
unsigned int index = 0;
struct drm_crtc *tmp;
list_for_each_entry(tmp, &dev->mode_config.crtc_list, head) {
if (tmp->port == port)
return 1 << index;
index++;
}
return 0;
}
uint32_t drm_of_find_possible_crtcs(struct drm_device *dev,
struct device_node *port)
{
struct device_node *remote_port, *ep = NULL;
uint32_t possible_crtcs = 0;
do {
ep = of_graph_get_next_endpoint(port, ep);
if (!ep)
break;
remote_port = of_graph_get_remote_port(ep);
if (!remote_port) {
of_node_put(ep);
return 0;
}
possible_crtcs |= drm_crtc_port_mask(dev, remote_port);
of_node_put(remote_port);
} while (1);
return possible_crtcs;
}
