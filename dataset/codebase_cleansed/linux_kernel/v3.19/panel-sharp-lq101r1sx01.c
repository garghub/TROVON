static inline struct sharp_panel *to_sharp_panel(struct drm_panel *panel)
{
return container_of(panel, struct sharp_panel, base);
}
static int sharp_panel_write(struct sharp_panel *sharp, u16 offset, u8 value)
{
u8 payload[3] = { offset >> 8, offset & 0xff, value };
struct mipi_dsi_device *dsi = sharp->link1;
ssize_t err;
err = mipi_dsi_generic_write(dsi, payload, sizeof(payload));
if (err < 0) {
dev_err(&dsi->dev, "failed to write %02x to %04x: %zd\n",
value, offset, err);
return err;
}
err = mipi_dsi_dcs_nop(dsi);
if (err < 0) {
dev_err(&dsi->dev, "failed to send DCS nop: %zd\n", err);
return err;
}
usleep_range(10, 20);
return 0;
}
static __maybe_unused int sharp_panel_read(struct sharp_panel *sharp,
u16 offset, u8 *value)
{
ssize_t err;
cpu_to_be16s(&offset);
err = mipi_dsi_generic_read(sharp->link1, &offset, sizeof(offset),
value, sizeof(*value));
if (err < 0)
dev_err(&sharp->link1->dev, "failed to read from %04x: %zd\n",
offset, err);
return err;
}
static int sharp_panel_disable(struct drm_panel *panel)
{
struct sharp_panel *sharp = to_sharp_panel(panel);
if (!sharp->enabled)
return 0;
if (sharp->backlight) {
sharp->backlight->props.power = FB_BLANK_POWERDOWN;
backlight_update_status(sharp->backlight);
}
sharp->enabled = false;
return 0;
}
static int sharp_panel_unprepare(struct drm_panel *panel)
{
struct sharp_panel *sharp = to_sharp_panel(panel);
int err;
if (!sharp->prepared)
return 0;
err = mipi_dsi_dcs_set_display_off(sharp->link1);
if (err < 0)
dev_err(panel->dev, "failed to set display off: %d\n", err);
err = mipi_dsi_dcs_enter_sleep_mode(sharp->link1);
if (err < 0)
dev_err(panel->dev, "failed to enter sleep mode: %d\n", err);
msleep(120);
regulator_disable(sharp->supply);
sharp->prepared = false;
return 0;
}
static int sharp_setup_symmetrical_split(struct mipi_dsi_device *left,
struct mipi_dsi_device *right,
const struct drm_display_mode *mode)
{
int err;
err = mipi_dsi_dcs_set_column_address(left, 0, mode->hdisplay / 2 - 1);
if (err < 0) {
dev_err(&left->dev, "failed to set column address: %d\n", err);
return err;
}
err = mipi_dsi_dcs_set_page_address(left, 0, mode->vdisplay - 1);
if (err < 0) {
dev_err(&left->dev, "failed to set page address: %d\n", err);
return err;
}
err = mipi_dsi_dcs_set_column_address(right, mode->hdisplay / 2,
mode->hdisplay - 1);
if (err < 0) {
dev_err(&right->dev, "failed to set column address: %d\n", err);
return err;
}
err = mipi_dsi_dcs_set_page_address(right, 0, mode->vdisplay - 1);
if (err < 0) {
dev_err(&right->dev, "failed to set page address: %d\n", err);
return err;
}
return 0;
}
static int sharp_panel_prepare(struct drm_panel *panel)
{
struct sharp_panel *sharp = to_sharp_panel(panel);
u8 format = MIPI_DCS_PIXEL_FMT_24BIT;
int err;
if (sharp->prepared)
return 0;
err = regulator_enable(sharp->supply);
if (err < 0)
return err;
usleep_range(10000, 20000);
err = mipi_dsi_dcs_soft_reset(sharp->link1);
if (err < 0) {
dev_err(panel->dev, "soft reset failed: %d\n", err);
goto poweroff;
}
msleep(120);
err = mipi_dsi_dcs_exit_sleep_mode(sharp->link1);
if (err < 0) {
dev_err(panel->dev, "failed to exit sleep mode: %d\n", err);
goto poweroff;
}
err = sharp_panel_write(sharp, 0x1000, 0x2a);
if (err < 0) {
dev_err(panel->dev, "failed to set left-right mode: %d\n", err);
goto poweroff;
}
err = sharp_panel_write(sharp, 0x1001, 0x01);
if (err < 0) {
dev_err(panel->dev, "failed to enable command mode: %d\n", err);
goto poweroff;
}
err = mipi_dsi_dcs_set_pixel_format(sharp->link1, format);
if (err < 0) {
dev_err(panel->dev, "failed to set pixel format: %d\n", err);
goto poweroff;
}
err = sharp_setup_symmetrical_split(sharp->link1, sharp->link2,
sharp->mode);
if (err < 0) {
dev_err(panel->dev, "failed to set up symmetrical split: %d\n",
err);
goto poweroff;
}
err = mipi_dsi_dcs_set_display_on(sharp->link1);
if (err < 0) {
dev_err(panel->dev, "failed to set display on: %d\n", err);
goto poweroff;
}
sharp->prepared = true;
return 0;
poweroff:
regulator_disable(sharp->supply);
return err;
}
static int sharp_panel_enable(struct drm_panel *panel)
{
struct sharp_panel *sharp = to_sharp_panel(panel);
if (sharp->enabled)
return 0;
if (sharp->backlight) {
sharp->backlight->props.power = FB_BLANK_UNBLANK;
backlight_update_status(sharp->backlight);
}
sharp->enabled = true;
return 0;
}
static int sharp_panel_get_modes(struct drm_panel *panel)
{
struct drm_display_mode *mode;
mode = drm_mode_duplicate(panel->drm, &default_mode);
if (!mode) {
dev_err(panel->drm->dev, "failed to add mode %ux%ux@%u\n",
default_mode.hdisplay, default_mode.vdisplay,
default_mode.vrefresh);
return -ENOMEM;
}
drm_mode_set_name(mode);
drm_mode_probed_add(panel->connector, mode);
panel->connector->display_info.width_mm = 217;
panel->connector->display_info.height_mm = 136;
return 1;
}
static int sharp_panel_add(struct sharp_panel *sharp)
{
struct device_node *np;
int err;
sharp->mode = &default_mode;
sharp->supply = devm_regulator_get(&sharp->link1->dev, "power");
if (IS_ERR(sharp->supply))
return PTR_ERR(sharp->supply);
np = of_parse_phandle(sharp->link1->dev.of_node, "backlight", 0);
if (np) {
sharp->backlight = of_find_backlight_by_node(np);
of_node_put(np);
if (!sharp->backlight)
return -EPROBE_DEFER;
}
drm_panel_init(&sharp->base);
sharp->base.funcs = &sharp_panel_funcs;
sharp->base.dev = &sharp->link1->dev;
err = drm_panel_add(&sharp->base);
if (err < 0)
goto put_backlight;
return 0;
put_backlight:
if (sharp->backlight)
put_device(&sharp->backlight->dev);
return err;
}
static void sharp_panel_del(struct sharp_panel *sharp)
{
if (sharp->base.dev)
drm_panel_remove(&sharp->base);
if (sharp->backlight)
put_device(&sharp->backlight->dev);
if (sharp->link2)
put_device(&sharp->link2->dev);
}
static int sharp_panel_probe(struct mipi_dsi_device *dsi)
{
struct mipi_dsi_device *secondary = NULL;
struct sharp_panel *sharp;
struct device_node *np;
int err;
dsi->lanes = 4;
dsi->format = MIPI_DSI_FMT_RGB888;
dsi->mode_flags = MIPI_DSI_MODE_LPM;
np = of_parse_phandle(dsi->dev.of_node, "link2", 0);
if (np) {
secondary = of_find_mipi_dsi_device_by_node(np);
of_node_put(np);
if (!secondary)
return -EPROBE_DEFER;
}
if (secondary) {
sharp = devm_kzalloc(&dsi->dev, sizeof(*sharp), GFP_KERNEL);
if (!sharp) {
put_device(&secondary->dev);
return -ENOMEM;
}
mipi_dsi_set_drvdata(dsi, sharp);
sharp->link2 = secondary;
sharp->link1 = dsi;
err = sharp_panel_add(sharp);
if (err < 0) {
put_device(&secondary->dev);
return err;
}
}
err = mipi_dsi_attach(dsi);
if (err < 0) {
if (secondary)
sharp_panel_del(sharp);
return err;
}
return 0;
}
static int sharp_panel_remove(struct mipi_dsi_device *dsi)
{
struct sharp_panel *sharp = mipi_dsi_get_drvdata(dsi);
int err;
if (!sharp) {
mipi_dsi_detach(dsi);
return 0;
}
err = sharp_panel_disable(&sharp->base);
if (err < 0)
dev_err(&dsi->dev, "failed to disable panel: %d\n", err);
err = mipi_dsi_detach(dsi);
if (err < 0)
dev_err(&dsi->dev, "failed to detach from DSI host: %d\n", err);
drm_panel_detach(&sharp->base);
sharp_panel_del(sharp);
return 0;
}
static void sharp_panel_shutdown(struct mipi_dsi_device *dsi)
{
struct sharp_panel *sharp = mipi_dsi_get_drvdata(dsi);
if (!sharp)
return;
sharp_panel_disable(&sharp->base);
}
