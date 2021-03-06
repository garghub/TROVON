static int v4l2_fwnode_endpoint_parse_csi_bus(struct fwnode_handle *fwnode,
struct v4l2_fwnode_endpoint *vep)
{
struct v4l2_fwnode_bus_mipi_csi2 *bus = &vep->bus.mipi_csi2;
bool have_clk_lane = false;
unsigned int flags = 0, lanes_used = 0;
unsigned int i;
u32 v;
int rval;
rval = fwnode_property_read_u32_array(fwnode, "data-lanes", NULL, 0);
if (rval > 0) {
u32 array[ARRAY_SIZE(bus->data_lanes)];
bus->num_data_lanes =
min_t(int, ARRAY_SIZE(bus->data_lanes), rval);
fwnode_property_read_u32_array(fwnode, "data-lanes", array,
bus->num_data_lanes);
for (i = 0; i < bus->num_data_lanes; i++) {
if (lanes_used & BIT(array[i]))
pr_warn("duplicated lane %u in data-lanes\n",
array[i]);
lanes_used |= BIT(array[i]);
bus->data_lanes[i] = array[i];
}
}
rval = fwnode_property_read_u32_array(fwnode, "lane-polarities", NULL,
0);
if (rval > 0) {
u32 array[ARRAY_SIZE(bus->lane_polarities)];
if (rval < 1 + bus->num_data_lanes ) {
pr_warn("too few lane-polarities entries (need %u, got %u)\n",
1 + bus->num_data_lanes, rval);
return -EINVAL;
}
fwnode_property_read_u32_array(fwnode, "lane-polarities", array,
1 + bus->num_data_lanes);
for (i = 0; i < 1 + bus->num_data_lanes; i++)
bus->lane_polarities[i] = array[i];
}
if (!fwnode_property_read_u32(fwnode, "clock-lanes", &v)) {
if (lanes_used & BIT(v))
pr_warn("duplicated lane %u in clock-lanes\n", v);
lanes_used |= BIT(v);
bus->clock_lane = v;
have_clk_lane = true;
}
if (fwnode_property_present(fwnode, "clock-noncontinuous"))
flags |= V4L2_MBUS_CSI2_NONCONTINUOUS_CLOCK;
else if (have_clk_lane || bus->num_data_lanes > 0)
flags |= V4L2_MBUS_CSI2_CONTINUOUS_CLOCK;
bus->flags = flags;
vep->bus_type = V4L2_MBUS_CSI2;
return 0;
}
static void v4l2_fwnode_endpoint_parse_parallel_bus(
struct fwnode_handle *fwnode, struct v4l2_fwnode_endpoint *vep)
{
struct v4l2_fwnode_bus_parallel *bus = &vep->bus.parallel;
unsigned int flags = 0;
u32 v;
if (!fwnode_property_read_u32(fwnode, "hsync-active", &v))
flags |= v ? V4L2_MBUS_HSYNC_ACTIVE_HIGH :
V4L2_MBUS_HSYNC_ACTIVE_LOW;
if (!fwnode_property_read_u32(fwnode, "vsync-active", &v))
flags |= v ? V4L2_MBUS_VSYNC_ACTIVE_HIGH :
V4L2_MBUS_VSYNC_ACTIVE_LOW;
if (!fwnode_property_read_u32(fwnode, "field-even-active", &v))
flags |= v ? V4L2_MBUS_FIELD_EVEN_HIGH :
V4L2_MBUS_FIELD_EVEN_LOW;
if (flags)
vep->bus_type = V4L2_MBUS_PARALLEL;
else
vep->bus_type = V4L2_MBUS_BT656;
if (!fwnode_property_read_u32(fwnode, "pclk-sample", &v))
flags |= v ? V4L2_MBUS_PCLK_SAMPLE_RISING :
V4L2_MBUS_PCLK_SAMPLE_FALLING;
if (!fwnode_property_read_u32(fwnode, "data-active", &v))
flags |= v ? V4L2_MBUS_DATA_ACTIVE_HIGH :
V4L2_MBUS_DATA_ACTIVE_LOW;
if (fwnode_property_present(fwnode, "slave-mode"))
flags |= V4L2_MBUS_SLAVE;
else
flags |= V4L2_MBUS_MASTER;
if (!fwnode_property_read_u32(fwnode, "bus-width", &v))
bus->bus_width = v;
if (!fwnode_property_read_u32(fwnode, "data-shift", &v))
bus->data_shift = v;
if (!fwnode_property_read_u32(fwnode, "sync-on-green-active", &v))
flags |= v ? V4L2_MBUS_VIDEO_SOG_ACTIVE_HIGH :
V4L2_MBUS_VIDEO_SOG_ACTIVE_LOW;
bus->flags = flags;
}
int v4l2_fwnode_endpoint_parse(struct fwnode_handle *fwnode,
struct v4l2_fwnode_endpoint *vep)
{
int rval;
fwnode_graph_parse_endpoint(fwnode, &vep->base);
memset(&vep->bus_type, 0, sizeof(*vep) -
offsetof(typeof(*vep), bus_type));
rval = v4l2_fwnode_endpoint_parse_csi_bus(fwnode, vep);
if (rval)
return rval;
if (vep->bus.mipi_csi2.flags == 0)
v4l2_fwnode_endpoint_parse_parallel_bus(fwnode, vep);
return 0;
}
void v4l2_fwnode_endpoint_free(struct v4l2_fwnode_endpoint *vep)
{
if (IS_ERR_OR_NULL(vep))
return;
kfree(vep->link_frequencies);
kfree(vep);
}
struct v4l2_fwnode_endpoint *v4l2_fwnode_endpoint_alloc_parse(
struct fwnode_handle *fwnode)
{
struct v4l2_fwnode_endpoint *vep;
int rval;
vep = kzalloc(sizeof(*vep), GFP_KERNEL);
if (!vep)
return ERR_PTR(-ENOMEM);
rval = v4l2_fwnode_endpoint_parse(fwnode, vep);
if (rval < 0)
goto out_err;
rval = fwnode_property_read_u64_array(fwnode, "link-frequencies",
NULL, 0);
if (rval < 0)
goto out_err;
vep->link_frequencies =
kmalloc_array(rval, sizeof(*vep->link_frequencies), GFP_KERNEL);
if (!vep->link_frequencies) {
rval = -ENOMEM;
goto out_err;
}
vep->nr_of_link_frequencies = rval;
rval = fwnode_property_read_u64_array(fwnode, "link-frequencies",
vep->link_frequencies,
vep->nr_of_link_frequencies);
if (rval < 0)
goto out_err;
return vep;
out_err:
v4l2_fwnode_endpoint_free(vep);
return ERR_PTR(rval);
}
int v4l2_fwnode_parse_link(struct fwnode_handle *__fwnode,
struct v4l2_fwnode_link *link)
{
const char *port_prop = is_of_node(__fwnode) ? "reg" : "port";
struct fwnode_handle *fwnode;
memset(link, 0, sizeof(*link));
fwnode = fwnode_get_parent(__fwnode);
fwnode_property_read_u32(fwnode, port_prop, &link->local_port);
fwnode = fwnode_get_next_parent(fwnode);
if (is_of_node(fwnode) &&
of_node_cmp(to_of_node(fwnode)->name, "ports") == 0)
fwnode = fwnode_get_next_parent(fwnode);
link->local_node = fwnode;
fwnode = fwnode_graph_get_remote_endpoint(__fwnode);
if (!fwnode) {
fwnode_handle_put(fwnode);
return -ENOLINK;
}
fwnode = fwnode_get_parent(fwnode);
fwnode_property_read_u32(fwnode, port_prop, &link->remote_port);
fwnode = fwnode_get_next_parent(fwnode);
if (is_of_node(fwnode) &&
of_node_cmp(to_of_node(fwnode)->name, "ports") == 0)
fwnode = fwnode_get_next_parent(fwnode);
link->remote_node = fwnode;
return 0;
}
void v4l2_fwnode_put_link(struct v4l2_fwnode_link *link)
{
fwnode_handle_put(link->local_node);
fwnode_handle_put(link->remote_node);
}
