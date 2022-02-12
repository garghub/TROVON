static int ptn3460_read_bytes(struct ptn3460_bridge *ptn_bridge, char addr,
u8 *buf, int len)
{
int ret;
ret = i2c_master_send(ptn_bridge->client, &addr, 1);
if (ret <= 0) {
DRM_ERROR("Failed to send i2c command, ret=%d\n", ret);
return ret;
}
ret = i2c_master_recv(ptn_bridge->client, buf, len);
if (ret <= 0) {
DRM_ERROR("Failed to recv i2c data, ret=%d\n", ret);
return ret;
}
return 0;
}
static int ptn3460_write_byte(struct ptn3460_bridge *ptn_bridge, char addr,
char val)
{
int ret;
char buf[2];
buf[0] = addr;
buf[1] = val;
ret = i2c_master_send(ptn_bridge->client, buf, ARRAY_SIZE(buf));
if (ret <= 0) {
DRM_ERROR("Failed to send i2c command, ret=%d\n", ret);
return ret;
}
return 0;
}
static int ptn3460_select_edid(struct ptn3460_bridge *ptn_bridge)
{
int ret;
char val;
ret = ptn3460_write_byte(ptn_bridge, PTN3460_EDID_SRAM_LOAD_ADDR,
ptn_bridge->edid_emulation);
if (ret) {
DRM_ERROR("Failed to transfer edid to sram, ret=%d\n", ret);
return ret;
}
val = 1 << PTN3460_EDID_ENABLE_EMULATION |
ptn_bridge->edid_emulation << PTN3460_EDID_EMULATION_SELECTION;
ret = ptn3460_write_byte(ptn_bridge, PTN3460_EDID_EMULATION_ADDR, val);
if (ret) {
DRM_ERROR("Failed to write edid value, ret=%d\n", ret);
return ret;
}
return 0;
}
static void ptn3460_pre_enable(struct drm_bridge *bridge)
{
struct ptn3460_bridge *ptn_bridge = bridge->driver_private;
int ret;
if (ptn_bridge->enabled)
return;
if (gpio_is_valid(ptn_bridge->gpio_pd_n))
gpio_set_value(ptn_bridge->gpio_pd_n, 1);
if (gpio_is_valid(ptn_bridge->gpio_rst_n)) {
gpio_set_value(ptn_bridge->gpio_rst_n, 0);
udelay(10);
gpio_set_value(ptn_bridge->gpio_rst_n, 1);
}
msleep(90);
ret = ptn3460_select_edid(ptn_bridge);
if (ret)
DRM_ERROR("Select edid failed ret=%d\n", ret);
ptn_bridge->enabled = true;
}
static void ptn3460_enable(struct drm_bridge *bridge)
{
}
static void ptn3460_disable(struct drm_bridge *bridge)
{
struct ptn3460_bridge *ptn_bridge = bridge->driver_private;
if (!ptn_bridge->enabled)
return;
ptn_bridge->enabled = false;
if (gpio_is_valid(ptn_bridge->gpio_rst_n))
gpio_set_value(ptn_bridge->gpio_rst_n, 1);
if (gpio_is_valid(ptn_bridge->gpio_pd_n))
gpio_set_value(ptn_bridge->gpio_pd_n, 0);
}
static void ptn3460_post_disable(struct drm_bridge *bridge)
{
}
void ptn3460_bridge_destroy(struct drm_bridge *bridge)
{
struct ptn3460_bridge *ptn_bridge = bridge->driver_private;
drm_bridge_cleanup(bridge);
if (gpio_is_valid(ptn_bridge->gpio_pd_n))
gpio_free(ptn_bridge->gpio_pd_n);
if (gpio_is_valid(ptn_bridge->gpio_rst_n))
gpio_free(ptn_bridge->gpio_rst_n);
}
int ptn3460_get_modes(struct drm_connector *connector)
{
struct ptn3460_bridge *ptn_bridge;
u8 *edid;
int ret, num_modes;
bool power_off;
ptn_bridge = container_of(connector, struct ptn3460_bridge, connector);
if (ptn_bridge->edid)
return drm_add_edid_modes(connector, ptn_bridge->edid);
power_off = !ptn_bridge->enabled;
ptn3460_pre_enable(ptn_bridge->bridge);
edid = kmalloc(EDID_LENGTH, GFP_KERNEL);
if (!edid) {
DRM_ERROR("Failed to allocate edid\n");
return 0;
}
ret = ptn3460_read_bytes(ptn_bridge, PTN3460_EDID_ADDR, edid,
EDID_LENGTH);
if (ret) {
kfree(edid);
num_modes = 0;
goto out;
}
ptn_bridge->edid = (struct edid *)edid;
drm_mode_connector_update_edid_property(connector, ptn_bridge->edid);
num_modes = drm_add_edid_modes(connector, ptn_bridge->edid);
out:
if (power_off)
ptn3460_disable(ptn_bridge->bridge);
return num_modes;
}
static int ptn3460_mode_valid(struct drm_connector *connector,
struct drm_display_mode *mode)
{
return MODE_OK;
}
struct drm_encoder *ptn3460_best_encoder(struct drm_connector *connector)
{
struct ptn3460_bridge *ptn_bridge;
ptn_bridge = container_of(connector, struct ptn3460_bridge, connector);
return ptn_bridge->encoder;
}
enum drm_connector_status ptn3460_detect(struct drm_connector *connector,
bool force)
{
return connector_status_connected;
}
void ptn3460_connector_destroy(struct drm_connector *connector)
{
drm_connector_cleanup(connector);
}
int ptn3460_init(struct drm_device *dev, struct drm_encoder *encoder,
struct i2c_client *client, struct device_node *node)
{
int ret;
struct drm_bridge *bridge;
struct ptn3460_bridge *ptn_bridge;
bridge = devm_kzalloc(dev->dev, sizeof(*bridge), GFP_KERNEL);
if (!bridge) {
DRM_ERROR("Failed to allocate drm bridge\n");
return -ENOMEM;
}
ptn_bridge = devm_kzalloc(dev->dev, sizeof(*ptn_bridge), GFP_KERNEL);
if (!ptn_bridge) {
DRM_ERROR("Failed to allocate ptn bridge\n");
return -ENOMEM;
}
ptn_bridge->client = client;
ptn_bridge->encoder = encoder;
ptn_bridge->bridge = bridge;
ptn_bridge->gpio_pd_n = of_get_named_gpio(node, "powerdown-gpio", 0);
if (gpio_is_valid(ptn_bridge->gpio_pd_n)) {
ret = gpio_request_one(ptn_bridge->gpio_pd_n,
GPIOF_OUT_INIT_HIGH, "PTN3460_PD_N");
if (ret) {
DRM_ERROR("Request powerdown-gpio failed (%d)\n", ret);
return ret;
}
}
ptn_bridge->gpio_rst_n = of_get_named_gpio(node, "reset-gpio", 0);
if (gpio_is_valid(ptn_bridge->gpio_rst_n)) {
ret = gpio_request_one(ptn_bridge->gpio_rst_n,
GPIOF_OUT_INIT_LOW, "PTN3460_RST_N");
if (ret) {
DRM_ERROR("Request reset-gpio failed (%d)\n", ret);
gpio_free(ptn_bridge->gpio_pd_n);
return ret;
}
}
ret = of_property_read_u32(node, "edid-emulation",
&ptn_bridge->edid_emulation);
if (ret) {
DRM_ERROR("Can't read edid emulation value\n");
goto err;
}
ret = drm_bridge_init(dev, bridge, &ptn3460_bridge_funcs);
if (ret) {
DRM_ERROR("Failed to initialize bridge with drm\n");
goto err;
}
bridge->driver_private = ptn_bridge;
encoder->bridge = bridge;
ret = drm_connector_init(dev, &ptn_bridge->connector,
&ptn3460_connector_funcs, DRM_MODE_CONNECTOR_LVDS);
if (ret) {
DRM_ERROR("Failed to initialize connector with drm\n");
goto err;
}
drm_connector_helper_add(&ptn_bridge->connector,
&ptn3460_connector_helper_funcs);
drm_sysfs_connector_add(&ptn_bridge->connector);
drm_mode_connector_attach_encoder(&ptn_bridge->connector, encoder);
return 0;
err:
if (gpio_is_valid(ptn_bridge->gpio_pd_n))
gpio_free(ptn_bridge->gpio_pd_n);
if (gpio_is_valid(ptn_bridge->gpio_rst_n))
gpio_free(ptn_bridge->gpio_rst_n);
return ret;
}
