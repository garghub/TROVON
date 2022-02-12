static int v4l2_of_parse_csi_bus(const struct device_node *node,
struct v4l2_of_endpoint *endpoint)
{
struct v4l2_of_bus_mipi_csi2 *bus = &endpoint->bus.mipi_csi2;
struct property *prop;
bool have_clk_lane = false;
unsigned int flags = 0;
u32 v;
prop = of_find_property(node, "data-lanes", NULL);
if (prop) {
const __be32 *lane = NULL;
unsigned int i;
for (i = 0; i < ARRAY_SIZE(bus->data_lanes); i++) {
lane = of_prop_next_u32(prop, lane, &v);
if (!lane)
break;
bus->data_lanes[i] = v;
}
bus->num_data_lanes = i;
}
prop = of_find_property(node, "lane-polarities", NULL);
if (prop) {
const __be32 *polarity = NULL;
unsigned int i;
for (i = 0; i < ARRAY_SIZE(bus->lane_polarities); i++) {
polarity = of_prop_next_u32(prop, polarity, &v);
if (!polarity)
break;
bus->lane_polarities[i] = v;
}
if (i < 1 + bus->num_data_lanes ) {
pr_warn("%s: too few lane-polarities entries (need %u, got %u)\n",
node->full_name, 1 + bus->num_data_lanes, i);
return -EINVAL;
}
}
if (!of_property_read_u32(node, "clock-lanes", &v)) {
bus->clock_lane = v;
have_clk_lane = true;
}
if (of_get_property(node, "clock-noncontinuous", &v))
flags |= V4L2_MBUS_CSI2_NONCONTINUOUS_CLOCK;
else if (have_clk_lane || bus->num_data_lanes > 0)
flags |= V4L2_MBUS_CSI2_CONTINUOUS_CLOCK;
bus->flags = flags;
endpoint->bus_type = V4L2_MBUS_CSI2;
return 0;
}
static void v4l2_of_parse_parallel_bus(const struct device_node *node,
struct v4l2_of_endpoint *endpoint)
{
struct v4l2_of_bus_parallel *bus = &endpoint->bus.parallel;
unsigned int flags = 0;
u32 v;
if (!of_property_read_u32(node, "hsync-active", &v))
flags |= v ? V4L2_MBUS_HSYNC_ACTIVE_HIGH :
V4L2_MBUS_HSYNC_ACTIVE_LOW;
if (!of_property_read_u32(node, "vsync-active", &v))
flags |= v ? V4L2_MBUS_VSYNC_ACTIVE_HIGH :
V4L2_MBUS_VSYNC_ACTIVE_LOW;
if (!of_property_read_u32(node, "field-even-active", &v))
flags |= v ? V4L2_MBUS_FIELD_EVEN_HIGH :
V4L2_MBUS_FIELD_EVEN_LOW;
if (flags)
endpoint->bus_type = V4L2_MBUS_PARALLEL;
else
endpoint->bus_type = V4L2_MBUS_BT656;
if (!of_property_read_u32(node, "pclk-sample", &v))
flags |= v ? V4L2_MBUS_PCLK_SAMPLE_RISING :
V4L2_MBUS_PCLK_SAMPLE_FALLING;
if (!of_property_read_u32(node, "data-active", &v))
flags |= v ? V4L2_MBUS_DATA_ACTIVE_HIGH :
V4L2_MBUS_DATA_ACTIVE_LOW;
if (of_get_property(node, "slave-mode", &v))
flags |= V4L2_MBUS_SLAVE;
else
flags |= V4L2_MBUS_MASTER;
if (!of_property_read_u32(node, "bus-width", &v))
bus->bus_width = v;
if (!of_property_read_u32(node, "data-shift", &v))
bus->data_shift = v;
if (!of_property_read_u32(node, "sync-on-green-active", &v))
flags |= v ? V4L2_MBUS_VIDEO_SOG_ACTIVE_HIGH :
V4L2_MBUS_VIDEO_SOG_ACTIVE_LOW;
bus->flags = flags;
}
int v4l2_of_parse_endpoint(const struct device_node *node,
struct v4l2_of_endpoint *endpoint)
{
int rval;
of_graph_parse_endpoint(node, &endpoint->base);
memset(&endpoint->bus_type, 0, sizeof(*endpoint) -
offsetof(typeof(*endpoint), bus_type));
rval = v4l2_of_parse_csi_bus(node, endpoint);
if (rval)
return rval;
if (endpoint->bus.mipi_csi2.flags == 0)
v4l2_of_parse_parallel_bus(node, endpoint);
return 0;
}
void v4l2_of_free_endpoint(struct v4l2_of_endpoint *endpoint)
{
if (IS_ERR_OR_NULL(endpoint))
return;
kfree(endpoint->link_frequencies);
kfree(endpoint);
}
struct v4l2_of_endpoint *v4l2_of_alloc_parse_endpoint(
const struct device_node *node)
{
struct v4l2_of_endpoint *endpoint;
int len;
int rval;
endpoint = kzalloc(sizeof(*endpoint), GFP_KERNEL);
if (!endpoint)
return ERR_PTR(-ENOMEM);
rval = v4l2_of_parse_endpoint(node, endpoint);
if (rval < 0)
goto out_err;
if (of_get_property(node, "link-frequencies", &len)) {
endpoint->link_frequencies = kmalloc(len, GFP_KERNEL);
if (!endpoint->link_frequencies) {
rval = -ENOMEM;
goto out_err;
}
endpoint->nr_of_link_frequencies =
len / sizeof(*endpoint->link_frequencies);
rval = of_property_read_u64_array(
node, "link-frequencies", endpoint->link_frequencies,
endpoint->nr_of_link_frequencies);
if (rval < 0)
goto out_err;
}
return endpoint;
out_err:
v4l2_of_free_endpoint(endpoint);
return ERR_PTR(rval);
}
int v4l2_of_parse_link(const struct device_node *node,
struct v4l2_of_link *link)
{
struct device_node *np;
memset(link, 0, sizeof(*link));
np = of_get_parent(node);
of_property_read_u32(np, "reg", &link->local_port);
np = of_get_next_parent(np);
if (of_node_cmp(np->name, "ports") == 0)
np = of_get_next_parent(np);
link->local_node = np;
np = of_parse_phandle(node, "remote-endpoint", 0);
if (!np) {
of_node_put(link->local_node);
return -ENOLINK;
}
np = of_get_parent(np);
of_property_read_u32(np, "reg", &link->remote_port);
np = of_get_next_parent(np);
if (of_node_cmp(np->name, "ports") == 0)
np = of_get_next_parent(np);
link->remote_node = np;
return 0;
}
void v4l2_of_put_link(struct v4l2_of_link *link)
{
of_node_put(link->local_node);
of_node_put(link->remote_node);
}
