static inline struct jdi_panel *to_jdi_panel(struct drm_panel *panel)
{
return container_of(panel, struct jdi_panel, base);
}
static int jdi_panel_init(struct jdi_panel *jdi)
{
struct mipi_dsi_device *dsi = jdi->dsi;
struct device *dev = &jdi->dsi->dev;
int ret;
dsi->mode_flags |= MIPI_DSI_MODE_LPM;
ret = mipi_dsi_dcs_soft_reset(dsi);
if (ret < 0)
return ret;
usleep_range(10000, 20000);
ret = mipi_dsi_dcs_set_pixel_format(dsi, MIPI_DCS_PIXEL_FMT_24BIT << 4);
if (ret < 0) {
dev_err(dev, "failed to set pixel format: %d\n", ret);
return ret;
}
ret = mipi_dsi_dcs_set_column_address(dsi, 0, jdi->mode->hdisplay - 1);
if (ret < 0) {
dev_err(dev, "failed to set column address: %d\n", ret);
return ret;
}
ret = mipi_dsi_dcs_set_page_address(dsi, 0, jdi->mode->vdisplay - 1);
if (ret < 0) {
dev_err(dev, "failed to set page address: %d\n", ret);
return ret;
}
ret = mipi_dsi_dcs_write(dsi, MIPI_DCS_WRITE_CONTROL_DISPLAY,
(u8[]){ 0x24 }, 1);
if (ret < 0) {
dev_err(dev, "failed to write control display: %d\n", ret);
return ret;
}
ret = mipi_dsi_dcs_write(dsi, MIPI_DCS_WRITE_POWER_SAVE,
(u8[]){ 0x00 }, 1);
if (ret < 0) {
dev_err(dev, "failed to set cabc off: %d\n", ret);
return ret;
}
ret = mipi_dsi_dcs_exit_sleep_mode(dsi);
if (ret < 0) {
dev_err(dev, "failed to set exit sleep mode: %d\n", ret);
return ret;
}
msleep(120);
ret = mipi_dsi_generic_write(dsi, (u8[]){0xB0, 0x00}, 2);
if (ret < 0) {
dev_err(dev, "failed to set mcap: %d\n", ret);
return ret;
}
mdelay(10);
ret = mipi_dsi_generic_write(dsi, (u8[])
{0xB3, 0x26, 0x08, 0x00, 0x20, 0x00}, 6);
if (ret < 0) {
dev_err(dev, "failed to set display interface setting: %d\n"
, ret);
return ret;
}
mdelay(20);
ret = mipi_dsi_generic_write(dsi, (u8[]){0xB0, 0x03}, 2);
if (ret < 0) {
dev_err(dev, "failed to set default values for mcap: %d\n"
, ret);
return ret;
}
return 0;
}
static int jdi_panel_on(struct jdi_panel *jdi)
{
struct mipi_dsi_device *dsi = jdi->dsi;
struct device *dev = &jdi->dsi->dev;
int ret;
dsi->mode_flags |= MIPI_DSI_MODE_LPM;
ret = mipi_dsi_dcs_set_display_on(dsi);
if (ret < 0)
dev_err(dev, "failed to set display on: %d\n", ret);
return ret;
}
static void jdi_panel_off(struct jdi_panel *jdi)
{
struct mipi_dsi_device *dsi = jdi->dsi;
struct device *dev = &jdi->dsi->dev;
int ret;
dsi->mode_flags &= ~MIPI_DSI_MODE_LPM;
ret = mipi_dsi_dcs_set_display_off(dsi);
if (ret < 0)
dev_err(dev, "failed to set display off: %d\n", ret);
ret = mipi_dsi_dcs_enter_sleep_mode(dsi);
if (ret < 0)
dev_err(dev, "failed to enter sleep mode: %d\n", ret);
msleep(100);
}
static int jdi_panel_disable(struct drm_panel *panel)
{
struct jdi_panel *jdi = to_jdi_panel(panel);
if (!jdi->enabled)
return 0;
jdi->backlight->props.power = FB_BLANK_POWERDOWN;
backlight_update_status(jdi->backlight);
jdi->enabled = false;
return 0;
}
static int jdi_panel_unprepare(struct drm_panel *panel)
{
struct jdi_panel *jdi = to_jdi_panel(panel);
struct device *dev = &jdi->dsi->dev;
int ret;
if (!jdi->prepared)
return 0;
jdi_panel_off(jdi);
ret = regulator_bulk_disable(ARRAY_SIZE(jdi->supplies), jdi->supplies);
if (ret < 0)
dev_err(dev, "regulator disable failed, %d\n", ret);
gpiod_set_value(jdi->enable_gpio, 0);
gpiod_set_value(jdi->reset_gpio, 1);
gpiod_set_value(jdi->dcdc_en_gpio, 0);
jdi->prepared = false;
return 0;
}
static int jdi_panel_prepare(struct drm_panel *panel)
{
struct jdi_panel *jdi = to_jdi_panel(panel);
struct device *dev = &jdi->dsi->dev;
int ret;
if (jdi->prepared)
return 0;
ret = regulator_bulk_enable(ARRAY_SIZE(jdi->supplies), jdi->supplies);
if (ret < 0) {
dev_err(dev, "regulator enable failed, %d\n", ret);
return ret;
}
msleep(20);
gpiod_set_value(jdi->dcdc_en_gpio, 1);
usleep_range(10, 20);
gpiod_set_value(jdi->reset_gpio, 0);
usleep_range(10, 20);
gpiod_set_value(jdi->enable_gpio, 1);
usleep_range(10, 20);
ret = jdi_panel_init(jdi);
if (ret < 0) {
dev_err(dev, "failed to init panel: %d\n", ret);
goto poweroff;
}
ret = jdi_panel_on(jdi);
if (ret < 0) {
dev_err(dev, "failed to set panel on: %d\n", ret);
goto poweroff;
}
jdi->prepared = true;
return 0;
poweroff:
ret = regulator_bulk_disable(ARRAY_SIZE(jdi->supplies), jdi->supplies);
if (ret < 0)
dev_err(dev, "regulator disable failed, %d\n", ret);
gpiod_set_value(jdi->enable_gpio, 0);
gpiod_set_value(jdi->reset_gpio, 1);
gpiod_set_value(jdi->dcdc_en_gpio, 0);
return ret;
}
static int jdi_panel_enable(struct drm_panel *panel)
{
struct jdi_panel *jdi = to_jdi_panel(panel);
if (jdi->enabled)
return 0;
jdi->backlight->props.power = FB_BLANK_UNBLANK;
backlight_update_status(jdi->backlight);
jdi->enabled = true;
return 0;
}
static int jdi_panel_get_modes(struct drm_panel *panel)
{
struct drm_display_mode *mode;
struct jdi_panel *jdi = to_jdi_panel(panel);
struct device *dev = &jdi->dsi->dev;
mode = drm_mode_duplicate(panel->drm, &default_mode);
if (!mode) {
dev_err(dev, "failed to add mode %ux%ux@%u\n",
default_mode.hdisplay, default_mode.vdisplay,
default_mode.vrefresh);
return -ENOMEM;
}
drm_mode_set_name(mode);
drm_mode_probed_add(panel->connector, mode);
panel->connector->display_info.width_mm = 95;
panel->connector->display_info.height_mm = 151;
return 1;
}
static int dsi_dcs_bl_get_brightness(struct backlight_device *bl)
{
struct mipi_dsi_device *dsi = bl_get_data(bl);
int ret;
u16 brightness = bl->props.brightness;
dsi->mode_flags &= ~MIPI_DSI_MODE_LPM;
ret = mipi_dsi_dcs_get_display_brightness(dsi, &brightness);
if (ret < 0)
return ret;
dsi->mode_flags |= MIPI_DSI_MODE_LPM;
return brightness & 0xff;
}
static int dsi_dcs_bl_update_status(struct backlight_device *bl)
{
struct mipi_dsi_device *dsi = bl_get_data(bl);
int ret;
dsi->mode_flags &= ~MIPI_DSI_MODE_LPM;
ret = mipi_dsi_dcs_set_display_brightness(dsi, bl->props.brightness);
if (ret < 0)
return ret;
dsi->mode_flags |= MIPI_DSI_MODE_LPM;
return 0;
}
static struct backlight_device *
drm_panel_create_dsi_backlight(struct mipi_dsi_device *dsi)
{
struct device *dev = &dsi->dev;
struct backlight_properties props;
memset(&props, 0, sizeof(props));
props.type = BACKLIGHT_RAW;
props.brightness = 255;
props.max_brightness = 255;
return devm_backlight_device_register(dev, dev_name(dev), dev, dsi,
&dsi_bl_ops, &props);
}
static int jdi_panel_add(struct jdi_panel *jdi)
{
struct device *dev = &jdi->dsi->dev;
int ret;
unsigned int i;
jdi->mode = &default_mode;
for (i = 0; i < ARRAY_SIZE(jdi->supplies); i++)
jdi->supplies[i].supply = regulator_names[i];
ret = devm_regulator_bulk_get(dev, ARRAY_SIZE(jdi->supplies),
jdi->supplies);
if (ret < 0) {
dev_err(dev, "failed to init regulator, ret=%d\n", ret);
return ret;
}
jdi->enable_gpio = devm_gpiod_get(dev, "enable", GPIOD_OUT_LOW);
if (IS_ERR(jdi->enable_gpio)) {
ret = PTR_ERR(jdi->enable_gpio);
dev_err(dev, "cannot get enable-gpio %d\n", ret);
return ret;
}
jdi->reset_gpio = devm_gpiod_get(dev, "reset", GPIOD_OUT_HIGH);
if (IS_ERR(jdi->reset_gpio)) {
ret = PTR_ERR(jdi->reset_gpio);
dev_err(dev, "cannot get reset-gpios %d\n", ret);
return ret;
}
jdi->dcdc_en_gpio = devm_gpiod_get(dev, "dcdc-en", GPIOD_OUT_LOW);
if (IS_ERR(jdi->dcdc_en_gpio)) {
ret = PTR_ERR(jdi->dcdc_en_gpio);
dev_err(dev, "cannot get dcdc-en-gpio %d\n", ret);
return ret;
}
jdi->backlight = drm_panel_create_dsi_backlight(jdi->dsi);
if (IS_ERR(jdi->backlight)) {
ret = PTR_ERR(jdi->backlight);
dev_err(dev, "failed to register backlight %d\n", ret);
return ret;
}
drm_panel_init(&jdi->base);
jdi->base.funcs = &jdi_panel_funcs;
jdi->base.dev = &jdi->dsi->dev;
ret = drm_panel_add(&jdi->base);
return ret;
}
static void jdi_panel_del(struct jdi_panel *jdi)
{
if (jdi->base.dev)
drm_panel_remove(&jdi->base);
}
static int jdi_panel_probe(struct mipi_dsi_device *dsi)
{
struct jdi_panel *jdi;
int ret;
dsi->lanes = 4;
dsi->format = MIPI_DSI_FMT_RGB888;
dsi->mode_flags = MIPI_DSI_MODE_VIDEO_HSE | MIPI_DSI_MODE_VIDEO |
MIPI_DSI_CLOCK_NON_CONTINUOUS;
jdi = devm_kzalloc(&dsi->dev, sizeof(*jdi), GFP_KERNEL);
if (!jdi)
return -ENOMEM;
mipi_dsi_set_drvdata(dsi, jdi);
jdi->dsi = dsi;
ret = jdi_panel_add(jdi);
if (ret < 0)
return ret;
return mipi_dsi_attach(dsi);
}
static int jdi_panel_remove(struct mipi_dsi_device *dsi)
{
struct jdi_panel *jdi = mipi_dsi_get_drvdata(dsi);
int ret;
ret = jdi_panel_disable(&jdi->base);
if (ret < 0)
dev_err(&dsi->dev, "failed to disable panel: %d\n", ret);
ret = mipi_dsi_detach(dsi);
if (ret < 0)
dev_err(&dsi->dev, "failed to detach from DSI host: %d\n",
ret);
drm_panel_detach(&jdi->base);
jdi_panel_del(jdi);
return 0;
}
static void jdi_panel_shutdown(struct mipi_dsi_device *dsi)
{
struct jdi_panel *jdi = mipi_dsi_get_drvdata(dsi);
jdi_panel_disable(&jdi->base);
}
