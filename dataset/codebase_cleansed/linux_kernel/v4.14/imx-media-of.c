static int of_add_pad_link(struct imx_media_dev *imxmd,
struct imx_media_pad *pad,
struct device_node *local_sd_node,
struct device_node *remote_sd_node,
int local_pad, int remote_pad)
{
dev_dbg(imxmd->md.dev, "%s: adding %s:%d -> %s:%d\n", __func__,
local_sd_node->name, local_pad,
remote_sd_node->name, remote_pad);
return imx_media_add_pad_link(imxmd, pad, remote_sd_node, NULL,
local_pad, remote_pad);
}
static void of_parse_sensor(struct imx_media_dev *imxmd,
struct imx_media_subdev *sensor,
struct device_node *sensor_np)
{
struct device_node *endpoint;
endpoint = of_graph_get_next_endpoint(sensor_np, NULL);
if (endpoint) {
v4l2_fwnode_endpoint_parse(of_fwnode_handle(endpoint),
&sensor->sensor_ep);
of_node_put(endpoint);
}
}
static int of_get_port_count(const struct device_node *np)
{
struct device_node *ports, *child;
int num = 0;
ports = of_get_child_by_name(np, "ports");
if (ports)
np = ports;
for_each_child_of_node(np, child)
if (of_node_cmp(child->name, "port") == 0)
num++;
of_node_put(ports);
return num;
}
static void of_get_remote_pad(struct device_node *epnode,
struct device_node **remote_node,
int *remote_pad)
{
struct device_node *rp, *rpp;
struct device_node *remote;
rp = of_graph_get_remote_port(epnode);
rpp = of_graph_get_remote_port_parent(epnode);
if (of_device_is_compatible(rpp, "fsl,imx6q-ipu")) {
remote = rp;
*remote_pad = 0;
of_node_put(rpp);
} else {
remote = rpp;
if (of_property_read_u32(rp, "reg", remote_pad))
*remote_pad = 0;
of_node_put(rp);
}
if (!of_device_is_available(remote)) {
of_node_put(remote);
*remote_node = NULL;
} else {
*remote_node = remote;
}
}
static int
of_parse_subdev(struct imx_media_dev *imxmd, struct device_node *sd_np,
bool is_csi_port, struct imx_media_subdev **subdev)
{
struct imx_media_subdev *imxsd;
int i, num_pads, ret;
if (!of_device_is_available(sd_np)) {
dev_dbg(imxmd->md.dev, "%s: %s not enabled\n", __func__,
sd_np->name);
*subdev = NULL;
return 0;
}
imxsd = imx_media_add_async_subdev(imxmd, sd_np, NULL);
ret = PTR_ERR_OR_ZERO(imxsd);
if (ret) {
if (ret == -EEXIST) {
*subdev = NULL;
return 0;
}
return ret;
}
*subdev = imxsd;
if (is_csi_port) {
num_pads = CSI_NUM_PADS;
imxsd->num_sink_pads = CSI_NUM_SINK_PADS;
} else if (of_device_is_compatible(sd_np, "fsl,imx6-mipi-csi2")) {
num_pads = of_get_port_count(sd_np);
imxsd->num_sink_pads = 1;
} else if (of_device_is_compatible(sd_np, "video-mux")) {
num_pads = of_get_port_count(sd_np);
imxsd->num_sink_pads = num_pads - 1;
} else {
num_pads = of_get_port_count(sd_np);
if (num_pads != 1) {
dev_warn(imxmd->md.dev,
"%s: unknown device %s with %d ports\n",
__func__, sd_np->name, num_pads);
return 0;
}
imxsd->num_sink_pads = 0;
}
if (imxsd->num_sink_pads >= num_pads)
return -EINVAL;
imxsd->num_src_pads = num_pads - imxsd->num_sink_pads;
dev_dbg(imxmd->md.dev, "%s: %s has %d pads (%d sink, %d src)\n",
__func__, sd_np->name, num_pads,
imxsd->num_sink_pads, imxsd->num_src_pads);
if (imxsd->num_sink_pads == 0)
of_parse_sensor(imxmd, imxsd, sd_np);
for (i = 0; i < num_pads; i++) {
struct device_node *epnode = NULL, *port, *remote_np;
struct imx_media_subdev *remote_imxsd;
struct imx_media_pad *pad;
int remote_pad;
pad = &imxsd->pad[i];
pad->pad.flags = (i < imxsd->num_sink_pads) ?
MEDIA_PAD_FL_SINK : MEDIA_PAD_FL_SOURCE;
if (is_csi_port)
port = (i < imxsd->num_sink_pads) ? sd_np : NULL;
else
port = of_graph_get_port_by_id(sd_np, i);
if (!port)
continue;
for_each_child_of_node(port, epnode) {
of_get_remote_pad(epnode, &remote_np, &remote_pad);
if (!remote_np)
continue;
ret = of_add_pad_link(imxmd, pad, sd_np, remote_np,
i, remote_pad);
if (ret)
break;
if (i < imxsd->num_sink_pads) {
ret = of_parse_subdev(imxmd, remote_np,
false, &remote_imxsd);
if (ret)
break;
}
of_node_put(remote_np);
}
if (port != sd_np)
of_node_put(port);
if (ret) {
of_node_put(remote_np);
of_node_put(epnode);
break;
}
}
return ret;
}
