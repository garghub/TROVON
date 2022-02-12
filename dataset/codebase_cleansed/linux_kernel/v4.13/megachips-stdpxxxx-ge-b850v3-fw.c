static u8 *stdp2690_get_edid(struct i2c_client *client)
{
struct i2c_adapter *adapter = client->adapter;
unsigned char start = 0x00;
unsigned int total_size;
u8 *block = kmalloc(EDID_LENGTH, GFP_KERNEL);
struct i2c_msg msgs[] = {
{
.addr = client->addr,
.flags = 0,
.len = 1,
.buf = &start,
}, {
.addr = client->addr,
.flags = I2C_M_RD,
.len = EDID_LENGTH,
.buf = block,
}
};
if (!block)
return NULL;
if (i2c_transfer(adapter, msgs, 2) != 2) {
DRM_ERROR("Unable to read EDID.\n");
goto err;
}
if (!drm_edid_block_valid(block, 0, false, NULL)) {
DRM_ERROR("Invalid EDID data\n");
goto err;
}
total_size = (block[EDID_EXT_BLOCK_CNT] + 1) * EDID_LENGTH;
if (total_size > EDID_LENGTH) {
kfree(block);
block = kmalloc(total_size, GFP_KERNEL);
if (!block)
return NULL;
start = 0x00;
msgs[1].len = total_size;
msgs[1].buf = block;
if (i2c_transfer(adapter, msgs, 2) != 2) {
DRM_ERROR("Unable to read EDID extension blocks.\n");
goto err;
}
if (!drm_edid_block_valid(block, 1, false, NULL)) {
DRM_ERROR("Invalid EDID data\n");
goto err;
}
}
return block;
err:
kfree(block);
return NULL;
}
static int ge_b850v3_lvds_get_modes(struct drm_connector *connector)
{
struct i2c_client *client;
int num_modes = 0;
client = ge_b850v3_lvds_ptr->stdp2690_i2c;
kfree(ge_b850v3_lvds_ptr->edid);
ge_b850v3_lvds_ptr->edid = (struct edid *)stdp2690_get_edid(client);
if (ge_b850v3_lvds_ptr->edid) {
drm_mode_connector_update_edid_property(connector,
ge_b850v3_lvds_ptr->edid);
num_modes = drm_add_edid_modes(connector,
ge_b850v3_lvds_ptr->edid);
}
return num_modes;
}
static enum drm_mode_status ge_b850v3_lvds_mode_valid(
struct drm_connector *connector, struct drm_display_mode *mode)
{
return MODE_OK;
}
static enum drm_connector_status ge_b850v3_lvds_detect(
struct drm_connector *connector, bool force)
{
struct i2c_client *stdp4028_i2c =
ge_b850v3_lvds_ptr->stdp4028_i2c;
s32 link_state;
link_state = i2c_smbus_read_word_data(stdp4028_i2c,
STDP4028_DPTX_STS_REG);
if (link_state == STDP4028_CON_STATE_CONNECTED)
return connector_status_connected;
if (link_state == 0)
return connector_status_disconnected;
return connector_status_unknown;
}
static irqreturn_t ge_b850v3_lvds_irq_handler(int irq, void *dev_id)
{
struct i2c_client *stdp4028_i2c
= ge_b850v3_lvds_ptr->stdp4028_i2c;
i2c_smbus_write_word_data(stdp4028_i2c,
STDP4028_DPTX_IRQ_STS_REG,
STDP4028_DPTX_IRQ_CLEAR);
if (ge_b850v3_lvds_ptr->connector.dev)
drm_kms_helper_hotplug_event(ge_b850v3_lvds_ptr->connector.dev);
return IRQ_HANDLED;
}
static int ge_b850v3_lvds_attach(struct drm_bridge *bridge)
{
struct drm_connector *connector = &ge_b850v3_lvds_ptr->connector;
struct i2c_client *stdp4028_i2c
= ge_b850v3_lvds_ptr->stdp4028_i2c;
int ret;
if (!bridge->encoder) {
DRM_ERROR("Parent encoder object not found");
return -ENODEV;
}
connector->polled = DRM_CONNECTOR_POLL_HPD;
drm_connector_helper_add(connector,
&ge_b850v3_lvds_connector_helper_funcs);
ret = drm_connector_init(bridge->dev, connector,
&ge_b850v3_lvds_connector_funcs,
DRM_MODE_CONNECTOR_DisplayPort);
if (ret) {
DRM_ERROR("Failed to initialize connector with drm\n");
return ret;
}
ret = drm_mode_connector_attach_encoder(connector, bridge->encoder);
if (ret)
return ret;
i2c_smbus_write_word_data(stdp4028_i2c,
STDP4028_IRQ_OUT_CONF_REG,
STDP4028_DPTX_DP_IRQ_EN);
i2c_smbus_write_word_data(stdp4028_i2c,
STDP4028_DPTX_IRQ_EN_REG,
STDP4028_DPTX_IRQ_CONFIG);
return 0;
}
static int ge_b850v3_lvds_init(struct device *dev)
{
mutex_lock(&ge_b850v3_lvds_dev_mutex);
if (ge_b850v3_lvds_ptr)
goto success;
ge_b850v3_lvds_ptr = devm_kzalloc(dev,
sizeof(*ge_b850v3_lvds_ptr),
GFP_KERNEL);
if (!ge_b850v3_lvds_ptr) {
mutex_unlock(&ge_b850v3_lvds_dev_mutex);
return -ENOMEM;
}
success:
mutex_unlock(&ge_b850v3_lvds_dev_mutex);
return 0;
}
static void ge_b850v3_lvds_remove(void)
{
mutex_lock(&ge_b850v3_lvds_dev_mutex);
if (!ge_b850v3_lvds_ptr)
goto out;
drm_bridge_remove(&ge_b850v3_lvds_ptr->bridge);
kfree(ge_b850v3_lvds_ptr->edid);
ge_b850v3_lvds_ptr = NULL;
out:
mutex_unlock(&ge_b850v3_lvds_dev_mutex);
}
static int stdp4028_ge_b850v3_fw_probe(struct i2c_client *stdp4028_i2c,
const struct i2c_device_id *id)
{
struct device *dev = &stdp4028_i2c->dev;
ge_b850v3_lvds_init(dev);
ge_b850v3_lvds_ptr->stdp4028_i2c = stdp4028_i2c;
i2c_set_clientdata(stdp4028_i2c, ge_b850v3_lvds_ptr);
ge_b850v3_lvds_ptr->bridge.funcs = &ge_b850v3_lvds_funcs;
ge_b850v3_lvds_ptr->bridge.of_node = dev->of_node;
drm_bridge_add(&ge_b850v3_lvds_ptr->bridge);
i2c_smbus_write_word_data(stdp4028_i2c,
STDP4028_DPTX_IRQ_STS_REG,
STDP4028_DPTX_IRQ_CLEAR);
if (!stdp4028_i2c->irq)
return 0;
return devm_request_threaded_irq(&stdp4028_i2c->dev,
stdp4028_i2c->irq, NULL,
ge_b850v3_lvds_irq_handler,
IRQF_TRIGGER_HIGH | IRQF_ONESHOT,
"ge-b850v3-lvds-dp", ge_b850v3_lvds_ptr);
}
static int stdp4028_ge_b850v3_fw_remove(struct i2c_client *stdp4028_i2c)
{
ge_b850v3_lvds_remove();
return 0;
}
static int stdp2690_ge_b850v3_fw_probe(struct i2c_client *stdp2690_i2c,
const struct i2c_device_id *id)
{
struct device *dev = &stdp2690_i2c->dev;
ge_b850v3_lvds_init(dev);
ge_b850v3_lvds_ptr->stdp2690_i2c = stdp2690_i2c;
i2c_set_clientdata(stdp2690_i2c, ge_b850v3_lvds_ptr);
return 0;
}
static int stdp2690_ge_b850v3_fw_remove(struct i2c_client *stdp2690_i2c)
{
ge_b850v3_lvds_remove();
return 0;
}
static int __init stdpxxxx_ge_b850v3_init(void)
{
int ret;
ret = i2c_add_driver(&stdp4028_ge_b850v3_fw_driver);
if (ret)
return ret;
return i2c_add_driver(&stdp2690_ge_b850v3_fw_driver);
}
static void __exit stdpxxxx_ge_b850v3_exit(void)
{
i2c_del_driver(&stdp2690_ge_b850v3_fw_driver);
i2c_del_driver(&stdp4028_ge_b850v3_fw_driver);
}
