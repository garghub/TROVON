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
static u16
get_blocksize(void *p)
{
u16 *block_ptr, block_size;
block_ptr = (u16 *)((char *)p - 2);
block_size = *block_ptr;
return block_size;
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
if (dvo_timing->hsync_positive)
panel_fixed_mode->flags |= DRM_MODE_FLAG_PHSYNC;
else
panel_fixed_mode->flags |= DRM_MODE_FLAG_NHSYNC;
if (dvo_timing->vsync_positive)
panel_fixed_mode->flags |= DRM_MODE_FLAG_PVSYNC;
else
panel_fixed_mode->flags |= DRM_MODE_FLAG_NVSYNC;
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
if (lvds_opts)
p_type = lvds_opts->panel_type;
else
return;
bl_start = find_section(bdb, BDB_LVDS_BACKLIGHT);
vbt_lvds_bl = (struct bdb_lvds_backlight *)(bl_start + 1) + p_type;
lvds_bl = kzalloc(sizeof(*vbt_lvds_bl), GFP_KERNEL);
if (!lvds_bl) {
dev_err(dev_priv->dev->dev, "out of memory for backlight data\n");
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
entry = &lvds_lfp_data->data[lvds_options->panel_type];
dvo_timing = &entry->dvo_timing;
panel_fixed_mode = kzalloc(sizeof(*panel_fixed_mode),
GFP_KERNEL);
if (panel_fixed_mode == NULL) {
dev_err(dev_priv->dev->dev, "out of memory for fixed panel mode\n");
return;
}
dev_priv->lvds_vbt = 1;
fill_detail_timing_data(panel_fixed_mode, dvo_timing);
if (panel_fixed_mode->htotal > 0 && panel_fixed_mode->vtotal > 0) {
dev_priv->lfp_lvds_vbt_mode = panel_fixed_mode;
drm_mode_debug_printmodeline(panel_fixed_mode);
} else {
dev_dbg(dev_priv->dev->dev, "ignoring invalid LVDS VBT\n");
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
static void
parse_sdvo_device_mapping(struct drm_psb_private *dev_priv,
struct bdb_header *bdb)
{
struct sdvo_device_mapping *p_mapping;
struct bdb_general_definitions *p_defs;
struct child_device_config *p_child;
int i, child_device_num, count;
u16 block_size;
p_defs = find_section(bdb, BDB_GENERAL_DEFINITIONS);
if (!p_defs) {
DRM_DEBUG_KMS("No general definition block is found, unable to construct sdvo mapping.\n");
return;
}
if (p_defs->child_dev_size != sizeof(*p_child)) {
DRM_DEBUG_KMS("different child size is found. Invalid.\n");
return;
}
block_size = get_blocksize(p_defs);
child_device_num = (block_size - sizeof(*p_defs)) /
sizeof(*p_child);
count = 0;
for (i = 0; i < child_device_num; i++) {
p_child = &(p_defs->devices[i]);
if (!p_child->device_type) {
continue;
}
if (p_child->slave_addr != SLAVE_ADDR1 &&
p_child->slave_addr != SLAVE_ADDR2) {
continue;
}
if (p_child->dvo_port != DEVICE_PORT_DVOB &&
p_child->dvo_port != DEVICE_PORT_DVOC) {
DRM_DEBUG_KMS("Incorrect SDVO port. Skip it\n");
continue;
}
DRM_DEBUG_KMS("the SDVO device with slave addr %2x is found on"
" %s port\n",
p_child->slave_addr,
(p_child->dvo_port == DEVICE_PORT_DVOB) ?
"SDVOB" : "SDVOC");
p_mapping = &(dev_priv->sdvo_mappings[p_child->dvo_port - 1]);
if (!p_mapping->initialized) {
p_mapping->dvo_port = p_child->dvo_port;
p_mapping->slave_addr = p_child->slave_addr;
p_mapping->dvo_wiring = p_child->dvo_wiring;
p_mapping->ddc_pin = p_child->ddc_pin;
p_mapping->i2c_pin = p_child->i2c_pin;
p_mapping->initialized = 1;
DRM_DEBUG_KMS("SDVO device: dvo=%x, addr=%x, wiring=%d, ddc_pin=%d, i2c_pin=%d\n",
p_mapping->dvo_port,
p_mapping->slave_addr,
p_mapping->dvo_wiring,
p_mapping->ddc_pin,
p_mapping->i2c_pin);
} else {
DRM_DEBUG_KMS("Maybe one SDVO port is shared by "
"two SDVO device.\n");
}
if (p_child->slave2_addr) {
DRM_DEBUG_KMS("there exists the slave2_addr. Maybe this"
" is a SDVO device with multiple inputs.\n");
}
count++;
}
if (!count) {
DRM_DEBUG_KMS("No SDVO device info is found in VBT\n");
}
return;
}
static void
parse_driver_features(struct drm_psb_private *dev_priv,
struct bdb_header *bdb)
{
struct bdb_driver_features *driver;
driver = find_section(bdb, BDB_DRIVER_FEATURES);
if (!driver)
return;
if (driver->primary_lfp_id)
dev_priv->dplla_96mhz = true;
else
dev_priv->dplla_96mhz = false;
}
static void
parse_device_mapping(struct drm_psb_private *dev_priv,
struct bdb_header *bdb)
{
struct bdb_general_definitions *p_defs;
struct child_device_config *p_child, *child_dev_ptr;
int i, child_device_num, count;
u16 block_size;
p_defs = find_section(bdb, BDB_GENERAL_DEFINITIONS);
if (!p_defs) {
DRM_DEBUG_KMS("No general definition block is found, no devices defined.\n");
return;
}
if (p_defs->child_dev_size != sizeof(*p_child)) {
DRM_DEBUG_KMS("different child size is found. Invalid.\n");
return;
}
block_size = get_blocksize(p_defs);
child_device_num = (block_size - sizeof(*p_defs)) /
sizeof(*p_child);
count = 0;
for (i = 0; i < child_device_num; i++) {
p_child = &(p_defs->devices[i]);
if (!p_child->device_type) {
continue;
}
count++;
}
if (!count) {
DRM_DEBUG_KMS("no child dev is parsed from VBT\n");
return;
}
dev_priv->child_dev = kcalloc(count, sizeof(*p_child), GFP_KERNEL);
if (!dev_priv->child_dev) {
DRM_DEBUG_KMS("No memory space for child devices\n");
return;
}
dev_priv->child_dev_num = count;
count = 0;
for (i = 0; i < child_device_num; i++) {
p_child = &(p_defs->devices[i]);
if (!p_child->device_type) {
continue;
}
child_dev_ptr = dev_priv->child_dev + count;
count++;
memcpy((void *)child_dev_ptr, (void *)p_child,
sizeof(*p_child));
}
return;
}
bool psb_intel_init_bios(struct drm_device *dev)
{
struct drm_psb_private *dev_priv = dev->dev_private;
struct pci_dev *pdev = dev->pdev;
struct vbt_header *vbt = NULL;
struct bdb_header *bdb = NULL;
u8 __iomem *bios = NULL;
size_t size;
int i;
if (dev_priv->opregion.vbt) {
struct vbt_header *vbt = dev_priv->opregion.vbt;
if (memcmp(vbt->signature, "$VBT", 4) == 0) {
DRM_DEBUG_KMS("Using VBT from OpRegion: %20s\n",
vbt->signature);
bdb = (struct bdb_header *)((char *)vbt + vbt->bdb_offset);
} else
dev_priv->opregion.vbt = NULL;
}
if (bdb == NULL) {
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
dev_err(dev->dev, "VBT signature missing\n");
pci_unmap_rom(pdev, bios);
return -1;
}
bdb = (struct bdb_header *)(bios + i + vbt->bdb_offset);
}
parse_general_features(dev_priv, bdb);
parse_driver_features(dev_priv, bdb);
parse_lfp_panel_data(dev_priv, bdb);
parse_sdvo_panel_data(dev_priv, bdb);
parse_sdvo_device_mapping(dev_priv, bdb);
parse_device_mapping(dev_priv, bdb);
parse_backlight_data(dev_priv, bdb);
if (bios)
pci_unmap_rom(pdev, bios);
return 0;
}
void psb_intel_destroy_bios(struct drm_device *dev)
{
struct drm_psb_private *dev_priv = dev->dev_private;
kfree(dev_priv->sdvo_lvds_vbt_mode);
kfree(dev_priv->lfp_lvds_vbt_mode);
kfree(dev_priv->lvds_bl);
}
