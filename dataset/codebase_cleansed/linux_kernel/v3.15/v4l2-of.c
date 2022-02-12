static void v4l2_of_parse_csi_bus(const struct device_node *node,
struct v4l2_of_endpoint *endpoint)
{
struct v4l2_of_bus_mipi_csi2 *bus = &endpoint->bus.mipi_csi2;
u32 data_lanes[ARRAY_SIZE(bus->data_lanes)];
struct property *prop;
bool have_clk_lane = false;
unsigned int flags = 0;
u32 v;
prop = of_find_property(node, "data-lanes", NULL);
if (prop) {
const __be32 *lane = NULL;
int i;
for (i = 0; i < ARRAY_SIZE(data_lanes); i++) {
lane = of_prop_next_u32(prop, lane, &data_lanes[i]);
if (!lane)
break;
}
bus->num_data_lanes = i;
while (i--)
bus->data_lanes[i] = data_lanes[i];
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
if (!of_property_read_u32(node, "pclk-sample", &v))
flags |= v ? V4L2_MBUS_PCLK_SAMPLE_RISING :
V4L2_MBUS_PCLK_SAMPLE_FALLING;
if (!of_property_read_u32(node, "field-even-active", &v))
flags |= v ? V4L2_MBUS_FIELD_EVEN_HIGH :
V4L2_MBUS_FIELD_EVEN_LOW;
if (flags)
endpoint->bus_type = V4L2_MBUS_PARALLEL;
else
endpoint->bus_type = V4L2_MBUS_BT656;
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
of_graph_parse_endpoint(node, &endpoint->base);
endpoint->bus_type = 0;
memset(&endpoint->bus, 0, sizeof(endpoint->bus));
v4l2_of_parse_csi_bus(node, endpoint);
if (endpoint->bus.mipi_csi2.flags == 0)
v4l2_of_parse_parallel_bus(node, endpoint);
return 0;
}
