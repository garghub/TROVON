static void *find_section(struct bdb_header *bdb, int section_id)
{
u8 *base = (u8 *)bdb;
int index = 0;
u16 total, current_size;
u8 current_id;
index += bdb->header_size;
total = bdb->bdb_size;
while (index < total) {
current_id = *(base + index);
index++;
current_size = *((u16 *)(base + index));
index += 2;
if (current_id == section_id)
return base + index;
index += current_size;
}
return NULL;
}
static void fill_detail_timing_data(struct drm_display_mode *panel_fixed_mode,
struct lvds_dvo_timing *dvo_timing)
{
panel_fixed_mode->hdisplay = (dvo_timing->hactive_hi << 8) |
dvo_timing->hactive_lo;
panel_fixed_mode->hsync_start = panel_fixed_mode->hdisplay +
((dvo_timing->hsync_off_hi << 8) | dvo_timing->hsync_off_lo);
panel_fixed_mode->hsync_end = panel_fixed_mode->hsync_start +
dvo_timing->hsync_pulse_width;
panel_fixed_mode->htotal = panel_fixed_mode->hdisplay +
((dvo_timing->hblank_hi << 8) | dvo_timing->hblank_lo);
panel_fixed_mode->vdisplay = (dvo_timing->vactive_hi << 8) |
dvo_timing->vactive_lo;
panel_fixed_mode->vsync_start = panel_fixed_mode->vdisplay +
dvo_timing->vsync_off;
panel_fixed_mode->vsync_end = panel_fixed_mode->vsync_start +
dvo_timing->vsync_pulse_width;
panel_fixed_mode->vtotal = panel_fixed_mode->vdisplay +
((dvo_timing->vblank_hi << 8) | dvo_timing->vblank_lo);
panel_fixed_mode->clock = dvo_timing->clock * 10;
panel_fixed_mode->type = DRM_MODE_TYPE_PREFERRED;
if (panel_fixed_mode->hsync_end > panel_fixed_mode->htotal)
panel_fixed_mode->htotal = panel_fixed_mode->hsync_end + 1;
if (panel_fixed_mode->vsync_end > panel_fixed_mode->vtotal)
panel_fixed_mode->vtotal = panel_fixed_mode->vsync_end + 1;
drm_mode_set_name(panel_fixed_mode);
}
static void parse_backlight_data(struct drm_psb_private *dev_priv,
struct bdb_header *bdb)
{
struct bdb_lvds_backlight *vbt_lvds_bl = NULL;
struct bdb_lvds_backlight *lvds_bl;
u8 p_type = 0;
void *bl_start = NULL;
struct bdb_lvds_options *lvds_opts
= find_section(bdb, BDB_LVDS_OPTIONS);
dev_priv->lvds_bl = NULL;
if (lvds_opts) {
DRM_DEBUG("lvds_options found at %p\n", lvds_opts);
p_type = lvds_opts->panel_type;
} else {
DRM_DEBUG("no lvds_options\n");
return;
}
bl_start = find_section(bdb, BDB_LVDS_BACKLIGHT);
vbt_lvds_bl = (struct bdb_lvds_backlight *)(bl_start + 1) + p_type;
lvds_bl = kzalloc(sizeof(*vbt_lvds_bl), GFP_KERNEL);
if (!lvds_bl) {
DRM_DEBUG("No memory\n");
return;
}
memcpy(lvds_bl, vbt_lvds_bl, sizeof(*vbt_lvds_bl));
dev_priv->lvds_bl = lvds_bl;
}
static void parse_lfp_panel_data(struct drm_psb_private *dev_priv,
struct bdb_header *bdb)
{
struct bdb_lvds_options *lvds_options;
struct bdb_lvds_lfp_data *lvds_lfp_data;
struct bdb_lvds_lfp_data_entry *entry;
struct lvds_dvo_timing *dvo_timing;
struct drm_display_mode *panel_fixed_mode;
dev_priv->lvds_dither = 0;
dev_priv->lvds_vbt = 0;
lvds_options = find_section(bdb, BDB_LVDS_OPTIONS);
if (!lvds_options)
return;
dev_priv->lvds_dither = lvds_options->pixel_dither;
if (lvds_options->panel_type == 0xff)
return;
lvds_lfp_data = find_section(bdb, BDB_LVDS_LFP_DATA);
if (!lvds_lfp_data)
return;
dev_priv->lvds_vbt = 1;
entry = &lvds_lfp_data->data[lvds_options->panel_type];
dvo_timing = &entry->dvo_timing;
panel_fixed_mode = kzalloc(sizeof(*panel_fixed_mode),
GFP_KERNEL);
fill_detail_timing_data(panel_fixed_mode, dvo_timing);
if (panel_fixed_mode->htotal > 0 && panel_fixed_mode->vtotal > 0) {
dev_priv->lfp_lvds_vbt_mode = panel_fixed_mode;
DRM_DEBUG("Found panel mode in BIOS VBT tables:\n");
drm_mode_debug_printmodeline(panel_fixed_mode);
} else {
DRM_DEBUG("Ignoring bogus LVDS VBT mode.\n");
dev_priv->lvds_vbt = 0;
kfree(panel_fixed_mode);
}
return;
}
static void parse_sdvo_panel_data(struct drm_psb_private *dev_priv,
struct bdb_header *bdb)
{
struct bdb_sdvo_lvds_options *sdvo_lvds_options;
struct lvds_dvo_timing *dvo_timing;
struct drm_display_mode *panel_fixed_mode;
dev_priv->sdvo_lvds_vbt_mode = NULL;
sdvo_lvds_options = find_section(bdb, BDB_SDVO_LVDS_OPTIONS);
if (!sdvo_lvds_options)
return;
dvo_timing = find_section(bdb, BDB_SDVO_PANEL_DTDS);
if (!dvo_timing)
return;
panel_fixed_mode = kzalloc(sizeof(*panel_fixed_mode), GFP_KERNEL);
if (!panel_fixed_mode)
return;
fill_detail_timing_data(panel_fixed_mode,
dvo_timing + sdvo_lvds_options->panel_type);
dev_priv->sdvo_lvds_vbt_mode = panel_fixed_mode;
return;
}
static void parse_general_features(struct drm_psb_private *dev_priv,
struct bdb_header *bdb)
{
struct bdb_general_features *general;
dev_priv->int_tv_support = 1;
dev_priv->int_crt_support = 1;
general = find_section(bdb, BDB_GENERAL_FEATURES);
if (general) {
dev_priv->int_tv_support = general->int_tv_support;
dev_priv->int_crt_support = general->int_crt_support;
dev_priv->lvds_use_ssc = general->enable_ssc;
if (dev_priv->lvds_use_ssc) {
dev_priv->lvds_ssc_freq
= general->ssc_freq ? 100 : 96;
}
}
}
bool psb_intel_init_bios(struct drm_device *dev)
{
struct drm_psb_private *dev_priv = dev->dev_private;
struct pci_dev *pdev = dev->pdev;
struct vbt_header *vbt = NULL;
struct bdb_header *bdb;
u8 __iomem *bios;
size_t size;
int i;
bios = pci_map_rom(pdev, &size);
if (!bios)
return -1;
for (i = 0; i + 4 < size; i++) {
if (!memcmp(bios + i, "$VBT", 4)) {
vbt = (struct vbt_header *)(bios + i);
break;
}
}
if (!vbt) {
DRM_ERROR("VBT signature missing\n");
pci_unmap_rom(pdev, bios);
return -1;
}
bdb = (struct bdb_header *)(bios + i + vbt->bdb_offset);
parse_general_features(dev_priv, bdb);
parse_lfp_panel_data(dev_priv, bdb);
parse_sdvo_panel_data(dev_priv, bdb);
parse_backlight_data(dev_priv, bdb);
pci_unmap_rom(pdev, bios);
return 0;
}
void psb_intel_destroy_bios(struct drm_device *dev)
{
struct drm_psb_private *dev_priv = dev->dev_private;
struct drm_display_mode *sdvo_lvds_vbt_mode =
dev_priv->sdvo_lvds_vbt_mode;
struct drm_display_mode *lfp_lvds_vbt_mode =
dev_priv->lfp_lvds_vbt_mode;
struct bdb_lvds_backlight *lvds_bl =
dev_priv->lvds_bl;
if (sdvo_lvds_vbt_mode) {
dev_priv->sdvo_lvds_vbt_mode = NULL;
kfree(sdvo_lvds_vbt_mode);
}
if (lfp_lvds_vbt_mode) {
dev_priv->lfp_lvds_vbt_mode = NULL;
kfree(lfp_lvds_vbt_mode);
}
if (lvds_bl) {
dev_priv->lvds_bl = NULL;
kfree(lvds_bl);
}
}
