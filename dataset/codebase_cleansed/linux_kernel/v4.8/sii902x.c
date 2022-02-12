static inline struct sii902x *bridge_to_sii902x(struct drm_bridge *bridge)
{
return container_of(bridge, struct sii902x, bridge);
}
static inline struct sii902x *connector_to_sii902x(struct drm_connector *con)
{
return container_of(con, struct sii902x, connector);
}
static void sii902x_reset(struct sii902x *sii902x)
{
if (!sii902x->reset_gpio)
return;
gpiod_set_value(sii902x->reset_gpio, 1);
usleep_range(150, 200);
gpiod_set_value(sii902x->reset_gpio, 0);
}
static enum drm_connector_status
sii902x_connector_detect(struct drm_connector *connector, bool force)
{
struct sii902x *sii902x = connector_to_sii902x(connector);
unsigned int status;
regmap_read(sii902x->regmap, SII902X_INT_STATUS, &status);
return (status & SII902X_PLUGGED_STATUS) ?
connector_status_connected : connector_status_disconnected;
}
static int sii902x_get_modes(struct drm_connector *connector)
{
struct sii902x *sii902x = connector_to_sii902x(connector);
struct regmap *regmap = sii902x->regmap;
u32 bus_format = MEDIA_BUS_FMT_RGB888_1X24;
unsigned long timeout;
unsigned int status;
struct edid *edid;
int num = 0;
int ret;
ret = regmap_update_bits(regmap, SII902X_SYS_CTRL_DATA,
SII902X_SYS_CTRL_DDC_BUS_REQ,
SII902X_SYS_CTRL_DDC_BUS_REQ);
if (ret)
return ret;
timeout = jiffies +
msecs_to_jiffies(SII902X_I2C_BUS_ACQUISITION_TIMEOUT_MS);
do {
ret = regmap_read(regmap, SII902X_SYS_CTRL_DATA, &status);
if (ret)
return ret;
} while (!(status & SII902X_SYS_CTRL_DDC_BUS_GRTD) &&
time_before(jiffies, timeout));
if (!(status & SII902X_SYS_CTRL_DDC_BUS_GRTD)) {
dev_err(&sii902x->i2c->dev, "failed to acquire the i2c bus");
return -ETIMEDOUT;
}
ret = regmap_write(regmap, SII902X_SYS_CTRL_DATA, status);
if (ret)
return ret;
edid = drm_get_edid(connector, sii902x->i2c->adapter);
drm_mode_connector_update_edid_property(connector, edid);
if (edid) {
num = drm_add_edid_modes(connector, edid);
kfree(edid);
}
ret = drm_display_info_set_bus_formats(&connector->display_info,
&bus_format, 1);
if (ret)
return ret;
ret = regmap_read(regmap, SII902X_SYS_CTRL_DATA, &status);
if (ret)
return ret;
ret = regmap_update_bits(regmap, SII902X_SYS_CTRL_DATA,
SII902X_SYS_CTRL_DDC_BUS_REQ |
SII902X_SYS_CTRL_DDC_BUS_GRTD, 0);
if (ret)
return ret;
timeout = jiffies +
msecs_to_jiffies(SII902X_I2C_BUS_ACQUISITION_TIMEOUT_MS);
do {
ret = regmap_read(regmap, SII902X_SYS_CTRL_DATA, &status);
if (ret)
return ret;
} while (status & (SII902X_SYS_CTRL_DDC_BUS_REQ |
SII902X_SYS_CTRL_DDC_BUS_GRTD) &&
time_before(jiffies, timeout));
if (status & (SII902X_SYS_CTRL_DDC_BUS_REQ |
SII902X_SYS_CTRL_DDC_BUS_GRTD)) {
dev_err(&sii902x->i2c->dev, "failed to release the i2c bus");
return -ETIMEDOUT;
}
return num;
}
static enum drm_mode_status sii902x_mode_valid(struct drm_connector *connector,
struct drm_display_mode *mode)
{
return MODE_OK;
}
static void sii902x_bridge_disable(struct drm_bridge *bridge)
{
struct sii902x *sii902x = bridge_to_sii902x(bridge);
regmap_update_bits(sii902x->regmap, SII902X_SYS_CTRL_DATA,
SII902X_SYS_CTRL_PWR_DWN,
SII902X_SYS_CTRL_PWR_DWN);
}
static void sii902x_bridge_enable(struct drm_bridge *bridge)
{
struct sii902x *sii902x = bridge_to_sii902x(bridge);
regmap_update_bits(sii902x->regmap, SII902X_PWR_STATE_CTRL,
SII902X_AVI_POWER_STATE_MSK,
SII902X_AVI_POWER_STATE_D(0));
regmap_update_bits(sii902x->regmap, SII902X_SYS_CTRL_DATA,
SII902X_SYS_CTRL_PWR_DWN, 0);
}
static void sii902x_bridge_mode_set(struct drm_bridge *bridge,
struct drm_display_mode *mode,
struct drm_display_mode *adj)
{
struct sii902x *sii902x = bridge_to_sii902x(bridge);
struct regmap *regmap = sii902x->regmap;
u8 buf[HDMI_INFOFRAME_SIZE(AVI)];
struct hdmi_avi_infoframe frame;
int ret;
buf[0] = adj->clock;
buf[1] = adj->clock >> 8;
buf[2] = adj->vrefresh;
buf[3] = 0x00;
buf[4] = adj->hdisplay;
buf[5] = adj->hdisplay >> 8;
buf[6] = adj->vdisplay;
buf[7] = adj->vdisplay >> 8;
buf[8] = SII902X_TPI_CLK_RATIO_1X | SII902X_TPI_AVI_PIXEL_REP_NONE |
SII902X_TPI_AVI_PIXEL_REP_BUS_24BIT;
buf[9] = SII902X_TPI_AVI_INPUT_RANGE_AUTO |
SII902X_TPI_AVI_INPUT_COLORSPACE_RGB;
ret = regmap_bulk_write(regmap, SII902X_TPI_VIDEO_DATA, buf, 10);
if (ret)
return;
ret = drm_hdmi_avi_infoframe_from_display_mode(&frame, adj);
if (ret < 0) {
DRM_ERROR("couldn't fill AVI infoframe\n");
return;
}
ret = hdmi_avi_infoframe_pack(&frame, buf, sizeof(buf));
if (ret < 0) {
DRM_ERROR("failed to pack AVI infoframe: %d\n", ret);
return;
}
regmap_bulk_write(regmap, SII902X_TPI_AVI_INFOFRAME,
buf + HDMI_INFOFRAME_HEADER_SIZE - 1,
HDMI_AVI_INFOFRAME_SIZE + 1);
}
static int sii902x_bridge_attach(struct drm_bridge *bridge)
{
struct sii902x *sii902x = bridge_to_sii902x(bridge);
struct drm_device *drm = bridge->dev;
int ret;
drm_connector_helper_add(&sii902x->connector,
&sii902x_connector_helper_funcs);
if (!drm_core_check_feature(drm, DRIVER_ATOMIC)) {
dev_err(&sii902x->i2c->dev,
"sii902x driver is only compatible with DRM devices supporting atomic updates");
return -ENOTSUPP;
}
ret = drm_connector_init(drm, &sii902x->connector,
&sii902x_connector_funcs,
DRM_MODE_CONNECTOR_HDMIA);
if (ret)
return ret;
if (sii902x->i2c->irq > 0)
sii902x->connector.polled = DRM_CONNECTOR_POLL_HPD;
else
sii902x->connector.polled = DRM_CONNECTOR_POLL_CONNECT;
drm_mode_connector_attach_encoder(&sii902x->connector, bridge->encoder);
return 0;
}
static irqreturn_t sii902x_interrupt(int irq, void *data)
{
struct sii902x *sii902x = data;
unsigned int status = 0;
regmap_read(sii902x->regmap, SII902X_INT_STATUS, &status);
regmap_write(sii902x->regmap, SII902X_INT_STATUS, status);
if ((status & SII902X_HOTPLUG_EVENT) && sii902x->bridge.dev)
drm_helper_hpd_irq_event(sii902x->bridge.dev);
return IRQ_HANDLED;
}
static int sii902x_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct device *dev = &client->dev;
unsigned int status = 0;
struct sii902x *sii902x;
u8 chipid[4];
int ret;
sii902x = devm_kzalloc(dev, sizeof(*sii902x), GFP_KERNEL);
if (!sii902x)
return -ENOMEM;
sii902x->i2c = client;
sii902x->regmap = devm_regmap_init_i2c(client, &sii902x_regmap_config);
if (IS_ERR(sii902x->regmap))
return PTR_ERR(sii902x->regmap);
sii902x->reset_gpio = devm_gpiod_get_optional(dev, "reset",
GPIOD_OUT_LOW);
if (IS_ERR(sii902x->reset_gpio)) {
dev_err(dev, "Failed to retrieve/request reset gpio: %ld\n",
PTR_ERR(sii902x->reset_gpio));
return PTR_ERR(sii902x->reset_gpio);
}
sii902x_reset(sii902x);
ret = regmap_write(sii902x->regmap, SII902X_REG_TPI_RQB, 0x0);
if (ret)
return ret;
ret = regmap_bulk_read(sii902x->regmap, SII902X_REG_CHIPID(0),
&chipid, 4);
if (ret) {
dev_err(dev, "regmap_read failed %d\n", ret);
return ret;
}
if (chipid[0] != 0xb0) {
dev_err(dev, "Invalid chipid: %02x (expecting 0xb0)\n",
chipid[0]);
return -EINVAL;
}
regmap_read(sii902x->regmap, SII902X_INT_STATUS, &status);
regmap_write(sii902x->regmap, SII902X_INT_STATUS, status);
if (client->irq > 0) {
regmap_write(sii902x->regmap, SII902X_INT_ENABLE,
SII902X_HOTPLUG_EVENT);
ret = devm_request_threaded_irq(dev, client->irq, NULL,
sii902x_interrupt,
IRQF_ONESHOT, dev_name(dev),
sii902x);
if (ret)
return ret;
}
sii902x->bridge.funcs = &sii902x_bridge_funcs;
sii902x->bridge.of_node = dev->of_node;
ret = drm_bridge_add(&sii902x->bridge);
if (ret) {
dev_err(dev, "Failed to add drm_bridge\n");
return ret;
}
i2c_set_clientdata(client, sii902x);
return 0;
}
static int sii902x_remove(struct i2c_client *client)
{
struct sii902x *sii902x = i2c_get_clientdata(client);
drm_bridge_remove(&sii902x->bridge);
return 0;
}
