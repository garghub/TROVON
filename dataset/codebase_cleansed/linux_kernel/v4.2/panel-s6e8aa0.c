static inline struct s6e8aa0 *panel_to_s6e8aa0(struct drm_panel *panel)
{
return container_of(panel, struct s6e8aa0, panel);
}
static int s6e8aa0_clear_error(struct s6e8aa0 *ctx)
{
int ret = ctx->error;
ctx->error = 0;
return ret;
}
static void s6e8aa0_dcs_write(struct s6e8aa0 *ctx, const void *data, size_t len)
{
struct mipi_dsi_device *dsi = to_mipi_dsi_device(ctx->dev);
ssize_t ret;
if (ctx->error < 0)
return;
ret = mipi_dsi_dcs_write_buffer(dsi, data, len);
if (ret < 0) {
dev_err(ctx->dev, "error %zd writing dcs seq: %*ph\n", ret,
(int)len, data);
ctx->error = ret;
}
}
static int s6e8aa0_dcs_read(struct s6e8aa0 *ctx, u8 cmd, void *data, size_t len)
{
struct mipi_dsi_device *dsi = to_mipi_dsi_device(ctx->dev);
int ret;
if (ctx->error < 0)
return ctx->error;
ret = mipi_dsi_dcs_read(dsi, cmd, data, len);
if (ret < 0) {
dev_err(ctx->dev, "error %d reading dcs seq(%#x)\n", ret, cmd);
ctx->error = ret;
}
return ret;
}
static void s6e8aa0_apply_level_1_key(struct s6e8aa0 *ctx)
{
s6e8aa0_dcs_write_seq_static(ctx, 0xf0, 0x5a, 0x5a);
}
static void s6e8aa0_panel_cond_set_v142(struct s6e8aa0 *ctx)
{
static const u8 aids[] = {
0x04, 0x04, 0x04, 0x04, 0x04, 0x60, 0x80, 0xA0
};
u8 aid = aids[ctx->id >> 5];
u8 cfg = 0x3d;
u8 clk_con = 0xc8;
u8 int_con = 0x08;
u8 bictl_con = 0x48;
u8 em_clk1_con = 0xff;
u8 em_clk2_con = 0xff;
u8 em_int_con = 0xc8;
if (ctx->flip_vertical) {
cfg &= ~(PANELCTL_GTCON_MASK);
cfg |= (PANELCTL_GTCON_110);
}
if (ctx->flip_horizontal) {
cfg &= ~(PANELCTL_SS_MASK);
cfg |= (PANELCTL_SS_1_800);
}
if (ctx->flip_horizontal || ctx->flip_vertical) {
clk_con &= ~(PANELCTL_CLK1_CON_MASK |
PANELCTL_CLK2_CON_MASK);
clk_con |= (PANELCTL_CLK1_000 | PANELCTL_CLK2_001);
int_con &= ~(PANELCTL_INT1_CON_MASK |
PANELCTL_INT2_CON_MASK);
int_con |= (PANELCTL_INT1_000 | PANELCTL_INT2_001);
bictl_con &= ~(PANELCTL_BICTL_CON_MASK |
PANELCTL_BICTLB_CON_MASK);
bictl_con |= (PANELCTL_BICTL_000 |
PANELCTL_BICTLB_001);
em_clk1_con &= ~(PANELCTL_EM_CLK1_CON_MASK |
PANELCTL_EM_CLK1B_CON_MASK);
em_clk1_con |= (PANELCTL_EM_CLK1_110 |
PANELCTL_EM_CLK1B_110);
em_clk2_con &= ~(PANELCTL_EM_CLK2_CON_MASK |
PANELCTL_EM_CLK2B_CON_MASK);
em_clk2_con |= (PANELCTL_EM_CLK2_110 |
PANELCTL_EM_CLK2B_110);
em_int_con &= ~(PANELCTL_EM_INT1_CON_MASK |
PANELCTL_EM_INT2_CON_MASK);
em_int_con |= (PANELCTL_EM_INT1_000 |
PANELCTL_EM_INT2_001);
}
s6e8aa0_dcs_write_seq(ctx,
0xf8, cfg, 0x35, 0x00, 0x00, 0x00, 0x93, 0x00,
0x3c, 0x78, 0x08, 0x27, 0x7d, 0x3f, 0x00, 0x00,
0x00, 0x20, aid, 0x08, 0x6e, 0x00, 0x00, 0x00,
0x02, 0x07, 0x07, 0x23, 0x23, 0xc0, clk_con, int_con,
bictl_con, 0xc1, 0x00, 0xc1, em_clk1_con, em_clk2_con,
em_int_con);
}
static void s6e8aa0_panel_cond_set(struct s6e8aa0 *ctx)
{
if (ctx->version < 142)
s6e8aa0_dcs_write_seq_static(ctx,
0xf8, 0x19, 0x35, 0x00, 0x00, 0x00, 0x94, 0x00,
0x3c, 0x78, 0x10, 0x27, 0x08, 0x6e, 0x00, 0x00,
0x00, 0x00, 0x04, 0x08, 0x6e, 0x00, 0x00, 0x00,
0x00, 0x07, 0x07, 0x23, 0x6e, 0xc0, 0xc1, 0x01,
0x81, 0xc1, 0x00, 0xc3, 0xf6, 0xf6, 0xc1
);
else
s6e8aa0_panel_cond_set_v142(ctx);
}
static void s6e8aa0_display_condition_set(struct s6e8aa0 *ctx)
{
s6e8aa0_dcs_write_seq_static(ctx, 0xf2, 0x80, 0x03, 0x0d);
}
static void s6e8aa0_etc_source_control(struct s6e8aa0 *ctx)
{
s6e8aa0_dcs_write_seq_static(ctx, 0xf6, 0x00, 0x02, 0x00);
}
static void s6e8aa0_etc_pentile_control(struct s6e8aa0 *ctx)
{
static const u8 pent32[] = {
0xb6, 0x0c, 0x02, 0x03, 0x32, 0xc0, 0x44, 0x44, 0xc0, 0x00
};
static const u8 pent142[] = {
0xb6, 0x0c, 0x02, 0x03, 0x32, 0xff, 0x44, 0x44, 0xc0, 0x00
};
if (ctx->version < 142)
s6e8aa0_dcs_write(ctx, pent32, ARRAY_SIZE(pent32));
else
s6e8aa0_dcs_write(ctx, pent142, ARRAY_SIZE(pent142));
}
static void s6e8aa0_etc_power_control(struct s6e8aa0 *ctx)
{
static const u8 pwr142[] = {
0xf4, 0xcf, 0x0a, 0x12, 0x10, 0x1e, 0x33, 0x02
};
static const u8 pwr32[] = {
0xf4, 0xcf, 0x0a, 0x15, 0x10, 0x19, 0x33, 0x02
};
if (ctx->version < 142)
s6e8aa0_dcs_write(ctx, pwr32, ARRAY_SIZE(pwr32));
else
s6e8aa0_dcs_write(ctx, pwr142, ARRAY_SIZE(pwr142));
}
static void s6e8aa0_etc_elvss_control(struct s6e8aa0 *ctx)
{
u8 id = ctx->id ? 0 : 0x95;
s6e8aa0_dcs_write_seq(ctx, 0xb1, 0x04, id);
}
static void s6e8aa0_elvss_nvm_set_v142(struct s6e8aa0 *ctx)
{
u8 br;
switch (ctx->brightness) {
case 0 ... 6:
br = 0xdf;
break;
case 7 ... 11:
br = 0xdd;
break;
case 12 ... 15:
default:
br = 0xd9;
break;
case 16 ... 24:
br = 0xd0;
break;
}
s6e8aa0_dcs_write_seq(ctx, 0xd9, 0x14, 0x40, 0x0c, 0xcb, 0xce, 0x6e,
0xc4, 0x0f, 0x40, 0x41, br, 0x00, 0x60, 0x19);
}
static void s6e8aa0_elvss_nvm_set(struct s6e8aa0 *ctx)
{
if (ctx->version < 142)
s6e8aa0_dcs_write_seq_static(ctx,
0xd9, 0x14, 0x40, 0x0c, 0xcb, 0xce, 0x6e, 0xc4, 0x07,
0x40, 0x41, 0xc1, 0x00, 0x60, 0x19);
else
s6e8aa0_elvss_nvm_set_v142(ctx);
}
static void s6e8aa0_apply_level_2_key(struct s6e8aa0 *ctx)
{
s6e8aa0_dcs_write_seq_static(ctx, 0xfc, 0x5a, 0x5a);
}
static void s6e8aa0_brightness_set(struct s6e8aa0 *ctx)
{
const u8 *gamma;
if (ctx->error)
return;
gamma = ctx->variant->gamma_tables[ctx->brightness];
if (ctx->version >= 142)
s6e8aa0_elvss_nvm_set(ctx);
s6e8aa0_dcs_write(ctx, gamma, GAMMA_TABLE_LEN);
s6e8aa0_dcs_write_seq_static(ctx, 0xf7, 0x03);
}
static void s6e8aa0_panel_init(struct s6e8aa0 *ctx)
{
s6e8aa0_apply_level_1_key(ctx);
s6e8aa0_apply_level_2_key(ctx);
msleep(20);
s6e8aa0_dcs_write_seq_static(ctx, MIPI_DCS_EXIT_SLEEP_MODE);
msleep(40);
s6e8aa0_panel_cond_set(ctx);
s6e8aa0_display_condition_set(ctx);
s6e8aa0_brightness_set(ctx);
s6e8aa0_etc_source_control(ctx);
s6e8aa0_etc_pentile_control(ctx);
s6e8aa0_elvss_nvm_set(ctx);
s6e8aa0_etc_power_control(ctx);
s6e8aa0_etc_elvss_control(ctx);
msleep(ctx->init_delay);
}
static void s6e8aa0_set_maximum_return_packet_size(struct s6e8aa0 *ctx,
u16 size)
{
struct mipi_dsi_device *dsi = to_mipi_dsi_device(ctx->dev);
int ret;
if (ctx->error < 0)
return;
ret = mipi_dsi_set_maximum_return_packet_size(dsi, size);
if (ret < 0) {
dev_err(ctx->dev,
"error %d setting maximum return packet size to %d\n",
ret, size);
ctx->error = ret;
}
}
static void s6e8aa0_read_mtp_id(struct s6e8aa0 *ctx)
{
u8 id[3];
int ret, i;
ret = s6e8aa0_dcs_read(ctx, 0xd1, id, ARRAY_SIZE(id));
if (ret < ARRAY_SIZE(id) || id[0] == 0x00) {
dev_err(ctx->dev, "read id failed\n");
ctx->error = -EIO;
return;
}
dev_info(ctx->dev, "ID: 0x%2x, 0x%2x, 0x%2x\n", id[0], id[1], id[2]);
for (i = 0; i < ARRAY_SIZE(s6e8aa0_variants); ++i) {
if (id[1] == s6e8aa0_variants[i].version)
break;
}
if (i >= ARRAY_SIZE(s6e8aa0_variants)) {
dev_err(ctx->dev, "unsupported display version %d\n", id[1]);
ctx->error = -EINVAL;
return;
}
ctx->variant = &s6e8aa0_variants[i];
ctx->version = id[1];
ctx->id = id[2];
}
static void s6e8aa0_set_sequence(struct s6e8aa0 *ctx)
{
s6e8aa0_set_maximum_return_packet_size(ctx, 3);
s6e8aa0_read_mtp_id(ctx);
s6e8aa0_panel_init(ctx);
s6e8aa0_dcs_write_seq_static(ctx, MIPI_DCS_SET_DISPLAY_ON);
}
static int s6e8aa0_power_on(struct s6e8aa0 *ctx)
{
int ret;
ret = regulator_bulk_enable(ARRAY_SIZE(ctx->supplies), ctx->supplies);
if (ret < 0)
return ret;
msleep(ctx->power_on_delay);
gpiod_set_value(ctx->reset_gpio, 0);
usleep_range(10000, 11000);
gpiod_set_value(ctx->reset_gpio, 1);
msleep(ctx->reset_delay);
return 0;
}
static int s6e8aa0_power_off(struct s6e8aa0 *ctx)
{
return regulator_bulk_disable(ARRAY_SIZE(ctx->supplies), ctx->supplies);
}
static int s6e8aa0_disable(struct drm_panel *panel)
{
return 0;
}
static int s6e8aa0_unprepare(struct drm_panel *panel)
{
struct s6e8aa0 *ctx = panel_to_s6e8aa0(panel);
s6e8aa0_dcs_write_seq_static(ctx, MIPI_DCS_ENTER_SLEEP_MODE);
s6e8aa0_dcs_write_seq_static(ctx, MIPI_DCS_SET_DISPLAY_OFF);
msleep(40);
s6e8aa0_clear_error(ctx);
return s6e8aa0_power_off(ctx);
}
static int s6e8aa0_prepare(struct drm_panel *panel)
{
struct s6e8aa0 *ctx = panel_to_s6e8aa0(panel);
int ret;
ret = s6e8aa0_power_on(ctx);
if (ret < 0)
return ret;
s6e8aa0_set_sequence(ctx);
ret = ctx->error;
if (ret < 0)
s6e8aa0_unprepare(panel);
return ret;
}
static int s6e8aa0_enable(struct drm_panel *panel)
{
return 0;
}
static int s6e8aa0_get_modes(struct drm_panel *panel)
{
struct drm_connector *connector = panel->connector;
struct s6e8aa0 *ctx = panel_to_s6e8aa0(panel);
struct drm_display_mode *mode;
mode = drm_mode_create(connector->dev);
if (!mode) {
DRM_ERROR("failed to create a new display mode\n");
return 0;
}
drm_display_mode_from_videomode(&ctx->vm, mode);
mode->width_mm = ctx->width_mm;
mode->height_mm = ctx->height_mm;
connector->display_info.width_mm = mode->width_mm;
connector->display_info.height_mm = mode->height_mm;
mode->type = DRM_MODE_TYPE_DRIVER | DRM_MODE_TYPE_PREFERRED;
drm_mode_probed_add(connector, mode);
return 1;
}
static int s6e8aa0_parse_dt(struct s6e8aa0 *ctx)
{
struct device *dev = ctx->dev;
struct device_node *np = dev->of_node;
int ret;
ret = of_get_videomode(np, &ctx->vm, 0);
if (ret < 0)
return ret;
of_property_read_u32(np, "power-on-delay", &ctx->power_on_delay);
of_property_read_u32(np, "reset-delay", &ctx->reset_delay);
of_property_read_u32(np, "init-delay", &ctx->init_delay);
of_property_read_u32(np, "panel-width-mm", &ctx->width_mm);
of_property_read_u32(np, "panel-height-mm", &ctx->height_mm);
ctx->flip_horizontal = of_property_read_bool(np, "flip-horizontal");
ctx->flip_vertical = of_property_read_bool(np, "flip-vertical");
return 0;
}
static int s6e8aa0_probe(struct mipi_dsi_device *dsi)
{
struct device *dev = &dsi->dev;
struct s6e8aa0 *ctx;
int ret;
ctx = devm_kzalloc(dev, sizeof(struct s6e8aa0), GFP_KERNEL);
if (!ctx)
return -ENOMEM;
mipi_dsi_set_drvdata(dsi, ctx);
ctx->dev = dev;
dsi->lanes = 4;
dsi->format = MIPI_DSI_FMT_RGB888;
dsi->mode_flags = MIPI_DSI_MODE_VIDEO | MIPI_DSI_MODE_VIDEO_BURST
| MIPI_DSI_MODE_VIDEO_HFP | MIPI_DSI_MODE_VIDEO_HBP
| MIPI_DSI_MODE_VIDEO_HSA | MIPI_DSI_MODE_EOT_PACKET
| MIPI_DSI_MODE_VSYNC_FLUSH | MIPI_DSI_MODE_VIDEO_AUTO_VERT;
ret = s6e8aa0_parse_dt(ctx);
if (ret < 0)
return ret;
ctx->supplies[0].supply = "vdd3";
ctx->supplies[1].supply = "vci";
ret = devm_regulator_bulk_get(dev, ARRAY_SIZE(ctx->supplies),
ctx->supplies);
if (ret < 0) {
dev_err(dev, "failed to get regulators: %d\n", ret);
return ret;
}
ctx->reset_gpio = devm_gpiod_get(dev, "reset", GPIOD_OUT_HIGH);
if (IS_ERR(ctx->reset_gpio)) {
dev_err(dev, "cannot get reset-gpios %ld\n",
PTR_ERR(ctx->reset_gpio));
return PTR_ERR(ctx->reset_gpio);
}
ctx->brightness = GAMMA_LEVEL_NUM - 1;
drm_panel_init(&ctx->panel);
ctx->panel.dev = dev;
ctx->panel.funcs = &s6e8aa0_drm_funcs;
ret = drm_panel_add(&ctx->panel);
if (ret < 0)
return ret;
ret = mipi_dsi_attach(dsi);
if (ret < 0)
drm_panel_remove(&ctx->panel);
return ret;
}
static int s6e8aa0_remove(struct mipi_dsi_device *dsi)
{
struct s6e8aa0 *ctx = mipi_dsi_get_drvdata(dsi);
mipi_dsi_detach(dsi);
drm_panel_remove(&ctx->panel);
return 0;
}
