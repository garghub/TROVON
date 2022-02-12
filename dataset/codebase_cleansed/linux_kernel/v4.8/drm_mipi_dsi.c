static int mipi_dsi_device_match(struct device *dev, struct device_driver *drv)
{
struct mipi_dsi_device *dsi = to_mipi_dsi_device(dev);
if (of_driver_match_device(dev, drv))
return 1;
if (!strcmp(dsi->name, drv->name))
return 1;
return 0;
}
static int mipi_dsi_uevent(struct device *dev, struct kobj_uevent_env *env)
{
struct mipi_dsi_device *dsi = to_mipi_dsi_device(dev);
int err;
err = of_device_uevent_modalias(dev, env);
if (err != -ENODEV)
return err;
add_uevent_var(env, "MODALIAS=%s%s", MIPI_DSI_MODULE_PREFIX,
dsi->name);
return 0;
}
static int of_device_match(struct device *dev, void *data)
{
return dev->of_node == data;
}
struct mipi_dsi_device *of_find_mipi_dsi_device_by_node(struct device_node *np)
{
struct device *dev;
dev = bus_find_device(&mipi_dsi_bus_type, NULL, np, of_device_match);
return dev ? to_mipi_dsi_device(dev) : NULL;
}
static void mipi_dsi_dev_release(struct device *dev)
{
struct mipi_dsi_device *dsi = to_mipi_dsi_device(dev);
of_node_put(dev->of_node);
kfree(dsi);
}
static struct mipi_dsi_device *mipi_dsi_device_alloc(struct mipi_dsi_host *host)
{
struct mipi_dsi_device *dsi;
dsi = kzalloc(sizeof(*dsi), GFP_KERNEL);
if (!dsi)
return ERR_PTR(-ENOMEM);
dsi->host = host;
dsi->dev.bus = &mipi_dsi_bus_type;
dsi->dev.parent = host->dev;
dsi->dev.type = &mipi_dsi_device_type;
device_initialize(&dsi->dev);
return dsi;
}
static int mipi_dsi_device_add(struct mipi_dsi_device *dsi)
{
struct mipi_dsi_host *host = dsi->host;
dev_set_name(&dsi->dev, "%s.%d", dev_name(host->dev), dsi->channel);
return device_add(&dsi->dev);
}
static struct mipi_dsi_device *
of_mipi_dsi_device_add(struct mipi_dsi_host *host, struct device_node *node)
{
struct device *dev = host->dev;
struct mipi_dsi_device_info info = { };
int ret;
u32 reg;
if (of_modalias_node(node, info.type, sizeof(info.type)) < 0) {
dev_err(dev, "modalias failure on %s\n", node->full_name);
return ERR_PTR(-EINVAL);
}
ret = of_property_read_u32(node, "reg", &reg);
if (ret) {
dev_err(dev, "device node %s has no valid reg property: %d\n",
node->full_name, ret);
return ERR_PTR(-EINVAL);
}
info.channel = reg;
info.node = of_node_get(node);
return mipi_dsi_device_register_full(host, &info);
}
static struct mipi_dsi_device *
of_mipi_dsi_device_add(struct mipi_dsi_host *host, struct device_node *node)
{
return ERR_PTR(-ENODEV);
}
struct mipi_dsi_device *
mipi_dsi_device_register_full(struct mipi_dsi_host *host,
const struct mipi_dsi_device_info *info)
{
struct mipi_dsi_device *dsi;
struct device *dev = host->dev;
int ret;
if (!info) {
dev_err(dev, "invalid mipi_dsi_device_info pointer\n");
return ERR_PTR(-EINVAL);
}
if (info->channel > 3) {
dev_err(dev, "invalid virtual channel: %u\n", info->channel);
return ERR_PTR(-EINVAL);
}
dsi = mipi_dsi_device_alloc(host);
if (IS_ERR(dsi)) {
dev_err(dev, "failed to allocate DSI device %ld\n",
PTR_ERR(dsi));
return dsi;
}
dsi->dev.of_node = info->node;
dsi->channel = info->channel;
strlcpy(dsi->name, info->type, sizeof(dsi->name));
ret = mipi_dsi_device_add(dsi);
if (ret) {
dev_err(dev, "failed to add DSI device %d\n", ret);
kfree(dsi);
return ERR_PTR(ret);
}
return dsi;
}
void mipi_dsi_device_unregister(struct mipi_dsi_device *dsi)
{
device_unregister(&dsi->dev);
}
struct mipi_dsi_host *of_find_mipi_dsi_host_by_node(struct device_node *node)
{
struct mipi_dsi_host *host;
mutex_lock(&host_lock);
list_for_each_entry(host, &host_list, list) {
if (host->dev->of_node == node) {
mutex_unlock(&host_lock);
return host;
}
}
mutex_unlock(&host_lock);
return NULL;
}
int mipi_dsi_host_register(struct mipi_dsi_host *host)
{
struct device_node *node;
for_each_available_child_of_node(host->dev->of_node, node) {
if (!of_find_property(node, "reg", NULL))
continue;
of_mipi_dsi_device_add(host, node);
}
mutex_lock(&host_lock);
list_add_tail(&host->list, &host_list);
mutex_unlock(&host_lock);
return 0;
}
static int mipi_dsi_remove_device_fn(struct device *dev, void *priv)
{
struct mipi_dsi_device *dsi = to_mipi_dsi_device(dev);
mipi_dsi_device_unregister(dsi);
return 0;
}
void mipi_dsi_host_unregister(struct mipi_dsi_host *host)
{
device_for_each_child(host->dev, NULL, mipi_dsi_remove_device_fn);
mutex_lock(&host_lock);
list_del_init(&host->list);
mutex_unlock(&host_lock);
}
int mipi_dsi_attach(struct mipi_dsi_device *dsi)
{
const struct mipi_dsi_host_ops *ops = dsi->host->ops;
if (!ops || !ops->attach)
return -ENOSYS;
return ops->attach(dsi->host, dsi);
}
int mipi_dsi_detach(struct mipi_dsi_device *dsi)
{
const struct mipi_dsi_host_ops *ops = dsi->host->ops;
if (!ops || !ops->detach)
return -ENOSYS;
return ops->detach(dsi->host, dsi);
}
static ssize_t mipi_dsi_device_transfer(struct mipi_dsi_device *dsi,
struct mipi_dsi_msg *msg)
{
const struct mipi_dsi_host_ops *ops = dsi->host->ops;
if (!ops || !ops->transfer)
return -ENOSYS;
if (dsi->mode_flags & MIPI_DSI_MODE_LPM)
msg->flags |= MIPI_DSI_MSG_USE_LPM;
return ops->transfer(dsi->host, msg);
}
bool mipi_dsi_packet_format_is_short(u8 type)
{
switch (type) {
case MIPI_DSI_V_SYNC_START:
case MIPI_DSI_V_SYNC_END:
case MIPI_DSI_H_SYNC_START:
case MIPI_DSI_H_SYNC_END:
case MIPI_DSI_END_OF_TRANSMISSION:
case MIPI_DSI_COLOR_MODE_OFF:
case MIPI_DSI_COLOR_MODE_ON:
case MIPI_DSI_SHUTDOWN_PERIPHERAL:
case MIPI_DSI_TURN_ON_PERIPHERAL:
case MIPI_DSI_GENERIC_SHORT_WRITE_0_PARAM:
case MIPI_DSI_GENERIC_SHORT_WRITE_1_PARAM:
case MIPI_DSI_GENERIC_SHORT_WRITE_2_PARAM:
case MIPI_DSI_GENERIC_READ_REQUEST_0_PARAM:
case MIPI_DSI_GENERIC_READ_REQUEST_1_PARAM:
case MIPI_DSI_GENERIC_READ_REQUEST_2_PARAM:
case MIPI_DSI_DCS_SHORT_WRITE:
case MIPI_DSI_DCS_SHORT_WRITE_PARAM:
case MIPI_DSI_DCS_READ:
case MIPI_DSI_SET_MAXIMUM_RETURN_PACKET_SIZE:
return true;
}
return false;
}
bool mipi_dsi_packet_format_is_long(u8 type)
{
switch (type) {
case MIPI_DSI_NULL_PACKET:
case MIPI_DSI_BLANKING_PACKET:
case MIPI_DSI_GENERIC_LONG_WRITE:
case MIPI_DSI_DCS_LONG_WRITE:
case MIPI_DSI_LOOSELY_PACKED_PIXEL_STREAM_YCBCR20:
case MIPI_DSI_PACKED_PIXEL_STREAM_YCBCR24:
case MIPI_DSI_PACKED_PIXEL_STREAM_YCBCR16:
case MIPI_DSI_PACKED_PIXEL_STREAM_30:
case MIPI_DSI_PACKED_PIXEL_STREAM_36:
case MIPI_DSI_PACKED_PIXEL_STREAM_YCBCR12:
case MIPI_DSI_PACKED_PIXEL_STREAM_16:
case MIPI_DSI_PACKED_PIXEL_STREAM_18:
case MIPI_DSI_PIXEL_STREAM_3BYTE_18:
case MIPI_DSI_PACKED_PIXEL_STREAM_24:
return true;
}
return false;
}
int mipi_dsi_create_packet(struct mipi_dsi_packet *packet,
const struct mipi_dsi_msg *msg)
{
if (!packet || !msg)
return -EINVAL;
if (!mipi_dsi_packet_format_is_short(msg->type) &&
!mipi_dsi_packet_format_is_long(msg->type))
return -EINVAL;
if (msg->channel > 3)
return -EINVAL;
memset(packet, 0, sizeof(*packet));
packet->header[0] = ((msg->channel & 0x3) << 6) | (msg->type & 0x3f);
if (mipi_dsi_packet_format_is_long(msg->type)) {
packet->header[1] = (msg->tx_len >> 0) & 0xff;
packet->header[2] = (msg->tx_len >> 8) & 0xff;
packet->payload_length = msg->tx_len;
packet->payload = msg->tx_buf;
} else {
const u8 *tx = msg->tx_buf;
packet->header[1] = (msg->tx_len > 0) ? tx[0] : 0;
packet->header[2] = (msg->tx_len > 1) ? tx[1] : 0;
}
packet->size = sizeof(packet->header) + packet->payload_length;
return 0;
}
int mipi_dsi_shutdown_peripheral(struct mipi_dsi_device *dsi)
{
struct mipi_dsi_msg msg = {
.channel = dsi->channel,
.type = MIPI_DSI_SHUTDOWN_PERIPHERAL,
.tx_buf = (u8 [2]) { 0, 0 },
.tx_len = 2,
};
return mipi_dsi_device_transfer(dsi, &msg);
}
int mipi_dsi_turn_on_peripheral(struct mipi_dsi_device *dsi)
{
struct mipi_dsi_msg msg = {
.channel = dsi->channel,
.type = MIPI_DSI_TURN_ON_PERIPHERAL,
.tx_buf = (u8 [2]) { 0, 0 },
.tx_len = 2,
};
return mipi_dsi_device_transfer(dsi, &msg);
}
int mipi_dsi_set_maximum_return_packet_size(struct mipi_dsi_device *dsi,
u16 value)
{
u8 tx[2] = { value & 0xff, value >> 8 };
struct mipi_dsi_msg msg = {
.channel = dsi->channel,
.type = MIPI_DSI_SET_MAXIMUM_RETURN_PACKET_SIZE,
.tx_len = sizeof(tx),
.tx_buf = tx,
};
return mipi_dsi_device_transfer(dsi, &msg);
}
ssize_t mipi_dsi_generic_write(struct mipi_dsi_device *dsi, const void *payload,
size_t size)
{
struct mipi_dsi_msg msg = {
.channel = dsi->channel,
.tx_buf = payload,
.tx_len = size
};
switch (size) {
case 0:
msg.type = MIPI_DSI_GENERIC_SHORT_WRITE_0_PARAM;
break;
case 1:
msg.type = MIPI_DSI_GENERIC_SHORT_WRITE_1_PARAM;
break;
case 2:
msg.type = MIPI_DSI_GENERIC_SHORT_WRITE_2_PARAM;
break;
default:
msg.type = MIPI_DSI_GENERIC_LONG_WRITE;
break;
}
return mipi_dsi_device_transfer(dsi, &msg);
}
ssize_t mipi_dsi_generic_read(struct mipi_dsi_device *dsi, const void *params,
size_t num_params, void *data, size_t size)
{
struct mipi_dsi_msg msg = {
.channel = dsi->channel,
.tx_len = num_params,
.tx_buf = params,
.rx_len = size,
.rx_buf = data
};
switch (num_params) {
case 0:
msg.type = MIPI_DSI_GENERIC_READ_REQUEST_0_PARAM;
break;
case 1:
msg.type = MIPI_DSI_GENERIC_READ_REQUEST_1_PARAM;
break;
case 2:
msg.type = MIPI_DSI_GENERIC_READ_REQUEST_2_PARAM;
break;
default:
return -EINVAL;
}
return mipi_dsi_device_transfer(dsi, &msg);
}
ssize_t mipi_dsi_dcs_write_buffer(struct mipi_dsi_device *dsi,
const void *data, size_t len)
{
struct mipi_dsi_msg msg = {
.channel = dsi->channel,
.tx_buf = data,
.tx_len = len
};
switch (len) {
case 0:
return -EINVAL;
case 1:
msg.type = MIPI_DSI_DCS_SHORT_WRITE;
break;
case 2:
msg.type = MIPI_DSI_DCS_SHORT_WRITE_PARAM;
break;
default:
msg.type = MIPI_DSI_DCS_LONG_WRITE;
break;
}
return mipi_dsi_device_transfer(dsi, &msg);
}
ssize_t mipi_dsi_dcs_write(struct mipi_dsi_device *dsi, u8 cmd,
const void *data, size_t len)
{
ssize_t err;
size_t size;
u8 *tx;
if (len > 0) {
size = 1 + len;
tx = kmalloc(size, GFP_KERNEL);
if (!tx)
return -ENOMEM;
tx[0] = cmd;
memcpy(&tx[1], data, len);
} else {
tx = &cmd;
size = 1;
}
err = mipi_dsi_dcs_write_buffer(dsi, tx, size);
if (len > 0)
kfree(tx);
return err;
}
ssize_t mipi_dsi_dcs_read(struct mipi_dsi_device *dsi, u8 cmd, void *data,
size_t len)
{
struct mipi_dsi_msg msg = {
.channel = dsi->channel,
.type = MIPI_DSI_DCS_READ,
.tx_buf = &cmd,
.tx_len = 1,
.rx_buf = data,
.rx_len = len
};
return mipi_dsi_device_transfer(dsi, &msg);
}
int mipi_dsi_dcs_nop(struct mipi_dsi_device *dsi)
{
ssize_t err;
err = mipi_dsi_dcs_write(dsi, MIPI_DCS_NOP, NULL, 0);
if (err < 0)
return err;
return 0;
}
int mipi_dsi_dcs_soft_reset(struct mipi_dsi_device *dsi)
{
ssize_t err;
err = mipi_dsi_dcs_write(dsi, MIPI_DCS_SOFT_RESET, NULL, 0);
if (err < 0)
return err;
return 0;
}
int mipi_dsi_dcs_get_power_mode(struct mipi_dsi_device *dsi, u8 *mode)
{
ssize_t err;
err = mipi_dsi_dcs_read(dsi, MIPI_DCS_GET_POWER_MODE, mode,
sizeof(*mode));
if (err <= 0) {
if (err == 0)
err = -ENODATA;
return err;
}
return 0;
}
int mipi_dsi_dcs_get_pixel_format(struct mipi_dsi_device *dsi, u8 *format)
{
ssize_t err;
err = mipi_dsi_dcs_read(dsi, MIPI_DCS_GET_PIXEL_FORMAT, format,
sizeof(*format));
if (err <= 0) {
if (err == 0)
err = -ENODATA;
return err;
}
return 0;
}
int mipi_dsi_dcs_enter_sleep_mode(struct mipi_dsi_device *dsi)
{
ssize_t err;
err = mipi_dsi_dcs_write(dsi, MIPI_DCS_ENTER_SLEEP_MODE, NULL, 0);
if (err < 0)
return err;
return 0;
}
int mipi_dsi_dcs_exit_sleep_mode(struct mipi_dsi_device *dsi)
{
ssize_t err;
err = mipi_dsi_dcs_write(dsi, MIPI_DCS_EXIT_SLEEP_MODE, NULL, 0);
if (err < 0)
return err;
return 0;
}
int mipi_dsi_dcs_set_display_off(struct mipi_dsi_device *dsi)
{
ssize_t err;
err = mipi_dsi_dcs_write(dsi, MIPI_DCS_SET_DISPLAY_OFF, NULL, 0);
if (err < 0)
return err;
return 0;
}
int mipi_dsi_dcs_set_display_on(struct mipi_dsi_device *dsi)
{
ssize_t err;
err = mipi_dsi_dcs_write(dsi, MIPI_DCS_SET_DISPLAY_ON, NULL, 0);
if (err < 0)
return err;
return 0;
}
int mipi_dsi_dcs_set_column_address(struct mipi_dsi_device *dsi, u16 start,
u16 end)
{
u8 payload[4] = { start >> 8, start & 0xff, end >> 8, end & 0xff };
ssize_t err;
err = mipi_dsi_dcs_write(dsi, MIPI_DCS_SET_COLUMN_ADDRESS, payload,
sizeof(payload));
if (err < 0)
return err;
return 0;
}
int mipi_dsi_dcs_set_page_address(struct mipi_dsi_device *dsi, u16 start,
u16 end)
{
u8 payload[4] = { start >> 8, start & 0xff, end >> 8, end & 0xff };
ssize_t err;
err = mipi_dsi_dcs_write(dsi, MIPI_DCS_SET_PAGE_ADDRESS, payload,
sizeof(payload));
if (err < 0)
return err;
return 0;
}
int mipi_dsi_dcs_set_tear_off(struct mipi_dsi_device *dsi)
{
ssize_t err;
err = mipi_dsi_dcs_write(dsi, MIPI_DCS_SET_TEAR_OFF, NULL, 0);
if (err < 0)
return err;
return 0;
}
int mipi_dsi_dcs_set_tear_on(struct mipi_dsi_device *dsi,
enum mipi_dsi_dcs_tear_mode mode)
{
u8 value = mode;
ssize_t err;
err = mipi_dsi_dcs_write(dsi, MIPI_DCS_SET_TEAR_ON, &value,
sizeof(value));
if (err < 0)
return err;
return 0;
}
int mipi_dsi_dcs_set_tear_scanline(struct mipi_dsi_device *dsi, u16 scanline)
{
u8 payload[3] = { MIPI_DCS_SET_TEAR_SCANLINE, scanline >> 8,
scanline & 0xff };
ssize_t err;
err = mipi_dsi_generic_write(dsi, payload, sizeof(payload));
if (err < 0)
return err;
return 0;
}
int mipi_dsi_dcs_set_pixel_format(struct mipi_dsi_device *dsi, u8 format)
{
ssize_t err;
err = mipi_dsi_dcs_write(dsi, MIPI_DCS_SET_PIXEL_FORMAT, &format,
sizeof(format));
if (err < 0)
return err;
return 0;
}
static int mipi_dsi_drv_probe(struct device *dev)
{
struct mipi_dsi_driver *drv = to_mipi_dsi_driver(dev->driver);
struct mipi_dsi_device *dsi = to_mipi_dsi_device(dev);
return drv->probe(dsi);
}
static int mipi_dsi_drv_remove(struct device *dev)
{
struct mipi_dsi_driver *drv = to_mipi_dsi_driver(dev->driver);
struct mipi_dsi_device *dsi = to_mipi_dsi_device(dev);
return drv->remove(dsi);
}
static void mipi_dsi_drv_shutdown(struct device *dev)
{
struct mipi_dsi_driver *drv = to_mipi_dsi_driver(dev->driver);
struct mipi_dsi_device *dsi = to_mipi_dsi_device(dev);
drv->shutdown(dsi);
}
int mipi_dsi_driver_register_full(struct mipi_dsi_driver *drv,
struct module *owner)
{
drv->driver.bus = &mipi_dsi_bus_type;
drv->driver.owner = owner;
if (drv->probe)
drv->driver.probe = mipi_dsi_drv_probe;
if (drv->remove)
drv->driver.remove = mipi_dsi_drv_remove;
if (drv->shutdown)
drv->driver.shutdown = mipi_dsi_drv_shutdown;
return driver_register(&drv->driver);
}
void mipi_dsi_driver_unregister(struct mipi_dsi_driver *drv)
{
driver_unregister(&drv->driver);
}
static int __init mipi_dsi_bus_init(void)
{
return bus_register(&mipi_dsi_bus_type);
}
