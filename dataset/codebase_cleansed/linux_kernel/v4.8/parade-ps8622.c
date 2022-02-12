static inline struct ps8622_bridge *
bridge_to_ps8622(struct drm_bridge *bridge)
{
return container_of(bridge, struct ps8622_bridge, bridge);
}
static inline struct ps8622_bridge *
connector_to_ps8622(struct drm_connector *connector)
{
return container_of(connector, struct ps8622_bridge, connector);
}
static int ps8622_set(struct i2c_client *client, u8 page, u8 reg, u8 val)
{
int ret;
struct i2c_adapter *adap = client->adapter;
struct i2c_msg msg;
u8 data[] = {reg, val};
msg.addr = client->addr + page;
msg.flags = 0;
msg.len = sizeof(data);
msg.buf = data;
ret = i2c_transfer(adap, &msg, 1);
if (ret != 1)
pr_warn("PS8622 I2C write (0x%02x,0x%02x,0x%02x) failed: %d\n",
client->addr + page, reg, val, ret);
return !(ret == 1);
}
static int ps8622_send_config(struct ps8622_bridge *ps8622)
{
struct i2c_client *cl = ps8622->client;
int err = 0;
err = ps8622_set(cl, 0x02, 0xa1, 0x01);
if (err)
goto error;
err = ps8622_set(cl, 0x04, 0x14, 0x01);
if (err)
goto error;
err = ps8622_set(cl, 0x04, 0xe3, 0x20);
if (err)
goto error;
err = ps8622_set(cl, 0x04, 0xe2, 0x80);
if (err)
goto error;
err = ps8622_set(cl, 0x04, 0x8a, 0x0c);
if (err)
goto error;
err = ps8622_set(cl, 0x04, 0x89, 0x08);
if (err)
goto error;
err = ps8622_set(cl, 0x04, 0x71, 0x2d);
if (err)
goto error;
err = ps8622_set(cl, 0x04, 0x7d, 0x07);
if (err)
goto error;
err = ps8622_set(cl, 0x04, 0x7b, 0x00);
if (err)
goto error;
err = ps8622_set(cl, 0x04, 0x7a, 0xfd);
if (err)
goto error;
err = ps8622_set(cl, 0x04, 0xc0, 0x12);
if (err)
goto error;
err = ps8622_set(cl, 0x04, 0xc1, 0x92);
if (err)
goto error;
err = ps8622_set(cl, 0x04, 0xc2, 0x1c);
if (err)
goto error;
err = ps8622_set(cl, 0x04, 0x32, 0x80);
if (err)
goto error;
err = ps8622_set(cl, 0x04, 0x00, 0xb0);
if (err)
goto error;
err = ps8622_set(cl, 0x04, 0x15, 0x40);
if (err)
goto error;
err = ps8622_set(cl, 0x04, 0x54, 0x10);
if (err)
goto error;
err = ps8622_set(cl, 0x01, 0x02, 0x80 | ps8622->max_lane_count);
if (err)
goto error;
err = ps8622_set(cl, 0x01, 0x21, 0x80 | ps8622->lane_count);
if (err)
goto error;
err = ps8622_set(cl, 0x00, 0x52, 0x20);
if (err)
goto error;
err = ps8622_set(cl, 0x00, 0xf1, 0x03);
if (err)
goto error;
err = ps8622_set(cl, 0x00, 0x62, 0x41);
if (err)
goto error;
err = ps8622_set(cl, 0x00, 0xf6, 0x01);
if (err)
goto error;
err = ps8622_set(cl, 0x00, 0x77, 0x06);
if (err)
goto error;
err = ps8622_set(cl, 0x00, 0x4c, 0x04);
if (err)
goto error;
err = ps8622_set(cl, 0x01, 0xc0, 0x00);
if (err)
goto error;
err = ps8622_set(cl, 0x01, 0xc1, 0x1c);
if (err)
goto error;
err = ps8622_set(cl, 0x01, 0xc2, 0xf8);
if (err)
goto error;
err = ps8622_set(cl, 0x01, 0xc3, 0x44);
if (err)
goto error;
err = ps8622_set(cl, 0x01, 0xc4, 0x32);
if (err)
goto error;
err = ps8622_set(cl, 0x01, 0xc5, 0x53);
if (err)
goto error;
err = ps8622_set(cl, 0x01, 0xc6, 0x4c);
if (err)
goto error;
err = ps8622_set(cl, 0x01, 0xc7, 0x56);
if (err)
goto error;
err = ps8622_set(cl, 0x01, 0xc8, 0x35);
if (err)
goto error;
err = ps8622_set(cl, 0x01, 0xca, 0x01);
if (err)
goto error;
err = ps8622_set(cl, 0x01, 0xcb, 0x05);
if (err)
goto error;
if (ps8622->bl) {
err = ps8622_set(cl, 0x01, 0xa5, 0xa0);
if (err)
goto error;
err = ps8622_set(cl, 0x01, 0xa7,
ps8622->bl->props.brightness);
if (err)
goto error;
} else {
err = ps8622_set(cl, 0x01, 0xa5, 0x80);
if (err)
goto error;
}
err = ps8622_set(cl, 0x01, 0xcc, 0x13);
if (err)
goto error;
err = ps8622_set(cl, 0x02, 0xb1, 0x20);
if (err)
goto error;
err = ps8622_set(cl, 0x04, 0x10, 0x16);
if (err)
goto error;
err = ps8622_set(cl, 0x04, 0x59, 0x60);
if (err)
goto error;
err = ps8622_set(cl, 0x04, 0x54, 0x14);
if (err)
goto error;
err = ps8622_set(cl, 0x02, 0xa1, 0x91);
error:
return err ? -EIO : 0;
}
static int ps8622_backlight_update(struct backlight_device *bl)
{
struct ps8622_bridge *ps8622 = dev_get_drvdata(&bl->dev);
int ret, brightness = bl->props.brightness;
if (bl->props.power != FB_BLANK_UNBLANK ||
bl->props.state & (BL_CORE_SUSPENDED | BL_CORE_FBBLANK))
brightness = 0;
if (!ps8622->enabled)
return -EINVAL;
ret = ps8622_set(ps8622->client, 0x01, 0xa7, brightness);
return ret;
}
static void ps8622_pre_enable(struct drm_bridge *bridge)
{
struct ps8622_bridge *ps8622 = bridge_to_ps8622(bridge);
int ret;
if (ps8622->enabled)
return;
gpiod_set_value(ps8622->gpio_rst, 0);
if (ps8622->v12) {
ret = regulator_enable(ps8622->v12);
if (ret)
DRM_ERROR("fails to enable ps8622->v12");
}
if (drm_panel_prepare(ps8622->panel)) {
DRM_ERROR("failed to prepare panel\n");
return;
}
gpiod_set_value(ps8622->gpio_slp, 1);
usleep_range(PS8622_RST_HIGH_T2_MIN_US + PS8622_POWER_RISE_T1_MAX_US,
PS8622_RST_HIGH_T2_MAX_US + PS8622_POWER_RISE_T1_MIN_US);
gpiod_set_value(ps8622->gpio_rst, 1);
usleep_range(20000, 30000);
ret = ps8622_send_config(ps8622);
if (ret) {
DRM_ERROR("Failed to send config to bridge (%d)\n", ret);
return;
}
ps8622->enabled = true;
}
static void ps8622_enable(struct drm_bridge *bridge)
{
struct ps8622_bridge *ps8622 = bridge_to_ps8622(bridge);
if (drm_panel_enable(ps8622->panel)) {
DRM_ERROR("failed to enable panel\n");
return;
}
}
static void ps8622_disable(struct drm_bridge *bridge)
{
struct ps8622_bridge *ps8622 = bridge_to_ps8622(bridge);
if (drm_panel_disable(ps8622->panel)) {
DRM_ERROR("failed to disable panel\n");
return;
}
msleep(PS8622_PWMO_END_T12_MS);
}
static void ps8622_post_disable(struct drm_bridge *bridge)
{
struct ps8622_bridge *ps8622 = bridge_to_ps8622(bridge);
if (!ps8622->enabled)
return;
ps8622->enabled = false;
gpiod_set_value(ps8622->gpio_slp, 0);
if (drm_panel_unprepare(ps8622->panel)) {
DRM_ERROR("failed to unprepare panel\n");
return;
}
if (ps8622->v12)
regulator_disable(ps8622->v12);
usleep_range(PS8622_POWER_FALL_T16_MAX_US,
2 * PS8622_POWER_FALL_T16_MAX_US);
gpiod_set_value(ps8622->gpio_rst, 0);
msleep(PS8622_POWER_OFF_T17_MS);
}
static int ps8622_get_modes(struct drm_connector *connector)
{
struct ps8622_bridge *ps8622;
ps8622 = connector_to_ps8622(connector);
return drm_panel_get_modes(ps8622->panel);
}
static enum drm_connector_status ps8622_detect(struct drm_connector *connector,
bool force)
{
return connector_status_connected;
}
static void ps8622_connector_destroy(struct drm_connector *connector)
{
drm_connector_cleanup(connector);
}
static int ps8622_attach(struct drm_bridge *bridge)
{
struct ps8622_bridge *ps8622 = bridge_to_ps8622(bridge);
int ret;
if (!bridge->encoder) {
DRM_ERROR("Parent encoder object not found");
return -ENODEV;
}
ps8622->connector.polled = DRM_CONNECTOR_POLL_HPD;
ret = drm_connector_init(bridge->dev, &ps8622->connector,
&ps8622_connector_funcs, DRM_MODE_CONNECTOR_LVDS);
if (ret) {
DRM_ERROR("Failed to initialize connector with drm\n");
return ret;
}
drm_connector_helper_add(&ps8622->connector,
&ps8622_connector_helper_funcs);
drm_connector_register(&ps8622->connector);
drm_mode_connector_attach_encoder(&ps8622->connector,
bridge->encoder);
if (ps8622->panel)
drm_panel_attach(ps8622->panel, &ps8622->connector);
drm_helper_hpd_irq_event(ps8622->connector.dev);
return ret;
}
static int ps8622_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct device *dev = &client->dev;
struct device_node *endpoint, *panel_node;
struct ps8622_bridge *ps8622;
int ret;
ps8622 = devm_kzalloc(dev, sizeof(*ps8622), GFP_KERNEL);
if (!ps8622)
return -ENOMEM;
endpoint = of_graph_get_next_endpoint(dev->of_node, NULL);
if (endpoint) {
panel_node = of_graph_get_remote_port_parent(endpoint);
if (panel_node) {
ps8622->panel = of_drm_find_panel(panel_node);
of_node_put(panel_node);
if (!ps8622->panel)
return -EPROBE_DEFER;
}
}
ps8622->client = client;
ps8622->v12 = devm_regulator_get(dev, "vdd12");
if (IS_ERR(ps8622->v12)) {
dev_info(dev, "no 1.2v regulator found for PS8622\n");
ps8622->v12 = NULL;
}
ps8622->gpio_slp = devm_gpiod_get(dev, "sleep", GPIOD_OUT_HIGH);
if (IS_ERR(ps8622->gpio_slp)) {
ret = PTR_ERR(ps8622->gpio_slp);
dev_err(dev, "cannot get gpio_slp %d\n", ret);
return ret;
}
ps8622->gpio_rst = devm_gpiod_get(dev, "reset", GPIOD_OUT_HIGH);
if (IS_ERR(ps8622->gpio_rst)) {
ret = PTR_ERR(ps8622->gpio_rst);
dev_err(dev, "cannot get gpio_rst %d\n", ret);
return ret;
}
ps8622->max_lane_count = id->driver_data;
if (of_property_read_u32(dev->of_node, "lane-count",
&ps8622->lane_count)) {
ps8622->lane_count = ps8622->max_lane_count;
} else if (ps8622->lane_count > ps8622->max_lane_count) {
dev_info(dev, "lane-count property is too high,"
"using max_lane_count\n");
ps8622->lane_count = ps8622->max_lane_count;
}
if (!of_find_property(dev->of_node, "use-external-pwm", NULL)) {
ps8622->bl = backlight_device_register("ps8622-backlight",
dev, ps8622, &ps8622_backlight_ops,
NULL);
if (IS_ERR(ps8622->bl)) {
DRM_ERROR("failed to register backlight\n");
ret = PTR_ERR(ps8622->bl);
ps8622->bl = NULL;
return ret;
}
ps8622->bl->props.max_brightness = PS8622_MAX_BRIGHTNESS;
ps8622->bl->props.brightness = PS8622_MAX_BRIGHTNESS;
}
ps8622->bridge.funcs = &ps8622_bridge_funcs;
ps8622->bridge.of_node = dev->of_node;
ret = drm_bridge_add(&ps8622->bridge);
if (ret) {
DRM_ERROR("Failed to add bridge\n");
return ret;
}
i2c_set_clientdata(client, ps8622);
return 0;
}
static int ps8622_remove(struct i2c_client *client)
{
struct ps8622_bridge *ps8622 = i2c_get_clientdata(client);
backlight_device_unregister(ps8622->bl);
drm_bridge_remove(&ps8622->bridge);
return 0;
}
