static void *
find_section(struct bdb_header *bdb, int section_id)
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
static void
fill_detail_timing_data(struct drm_display_mode *panel_fixed_mode,
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
static void
parse_lfp_panel_data(struct drm_i915_private *dev_priv,
struct bdb_header *bdb)
{
struct bdb_lvds_options *lvds_options;
struct bdb_lvds_lfp_data *lvds_lfp_data;
struct bdb_lvds_lfp_data_ptrs *lvds_lfp_data_ptrs;
struct bdb_lvds_lfp_data_entry *entry;
struct lvds_dvo_timing *dvo_timing;
struct drm_display_mode *panel_fixed_mode;
int lfp_data_size, dvo_timing_offset;
int i, temp_downclock;
struct drm_display_mode *temp_mode;
lvds_options = find_section(bdb, BDB_LVDS_OPTIONS);
if (!lvds_options)
return;
dev_priv->lvds_dither = lvds_options->pixel_dither;
if (lvds_options->panel_type == 0xff)
return;
panel_type = lvds_options->panel_type;
lvds_lfp_data = find_section(bdb, BDB_LVDS_LFP_DATA);
if (!lvds_lfp_data)
return;
lvds_lfp_data_ptrs = find_section(bdb, BDB_LVDS_LFP_DATA_PTRS);
if (!lvds_lfp_data_ptrs)
return;
dev_priv->lvds_vbt = 1;
lfp_data_size = lvds_lfp_data_ptrs->ptr[1].dvo_timing_offset -
lvds_lfp_data_ptrs->ptr[0].dvo_timing_offset;
entry = (struct bdb_lvds_lfp_data_entry *)
((uint8_t *)lvds_lfp_data->data + (lfp_data_size *
lvds_options->panel_type));
dvo_timing_offset = lvds_lfp_data_ptrs->ptr[0].dvo_timing_offset -
lvds_lfp_data_ptrs->ptr[0].fp_timing_offset;
dvo_timing = (struct lvds_dvo_timing *)
((unsigned char *)entry + dvo_timing_offset);
panel_fixed_mode = kzalloc(sizeof(*panel_fixed_mode), GFP_KERNEL);
if (!panel_fixed_mode)
return;
fill_detail_timing_data(panel_fixed_mode, dvo_timing);
dev_priv->lfp_lvds_vbt_mode = panel_fixed_mode;
DRM_DEBUG_KMS("Found panel mode in BIOS VBT tables:\n");
drm_mode_debug_printmodeline(panel_fixed_mode);
temp_mode = kzalloc(sizeof(*temp_mode), GFP_KERNEL);
temp_downclock = panel_fixed_mode->clock;
for (i = 0; i < 16; i++) {
entry = (struct bdb_lvds_lfp_data_entry *)
((uint8_t *)lvds_lfp_data->data + (lfp_data_size * i));
dvo_timing = (struct lvds_dvo_timing *)
((unsigned char *)entry + dvo_timing_offset);
fill_detail_timing_data(temp_mode, dvo_timing);
if (temp_mode->hdisplay == panel_fixed_mode->hdisplay &&
temp_mode->hsync_start == panel_fixed_mode->hsync_start &&
temp_mode->hsync_end == panel_fixed_mode->hsync_end &&
temp_mode->htotal == panel_fixed_mode->htotal &&
temp_mode->vdisplay == panel_fixed_mode->vdisplay &&
temp_mode->vsync_start == panel_fixed_mode->vsync_start &&
temp_mode->vsync_end == panel_fixed_mode->vsync_end &&
temp_mode->vtotal == panel_fixed_mode->vtotal &&
temp_mode->clock < temp_downclock) {
temp_downclock = temp_mode->clock;
}
memset(temp_mode, 0, sizeof(*temp_mode));
}
kfree(temp_mode);
if (temp_downclock < panel_fixed_mode->clock &&
i915_lvds_downclock) {
dev_priv->lvds_downclock_avail = 1;
dev_priv->lvds_downclock = temp_downclock;
DRM_DEBUG_KMS("LVDS downclock is found in VBT. "
"Normal Clock %dKHz, downclock %dKHz\n",
temp_downclock, panel_fixed_mode->clock);
}
return;
}
static void
parse_sdvo_panel_data(struct drm_i915_private *dev_priv,
struct bdb_header *bdb)
{
struct lvds_dvo_timing *dvo_timing;
struct drm_display_mode *panel_fixed_mode;
int index;
index = i915_vbt_sdvo_panel_type;
if (index == -1) {
struct bdb_sdvo_lvds_options *sdvo_lvds_options;
sdvo_lvds_options = find_section(bdb, BDB_SDVO_LVDS_OPTIONS);
if (!sdvo_lvds_options)
return;
index = sdvo_lvds_options->panel_type;
}
dvo_timing = find_section(bdb, BDB_SDVO_PANEL_DTDS);
if (!dvo_timing)
return;
panel_fixed_mode = kzalloc(sizeof(*panel_fixed_mode), GFP_KERNEL);
if (!panel_fixed_mode)
return;
fill_detail_timing_data(panel_fixed_mode, dvo_timing + index);
dev_priv->sdvo_lvds_vbt_mode = panel_fixed_mode;
DRM_DEBUG_KMS("Found SDVO panel mode in BIOS VBT tables:\n");
drm_mode_debug_printmodeline(panel_fixed_mode);
}
static int intel_bios_ssc_frequency(struct drm_device *dev,
bool alternate)
{
switch (INTEL_INFO(dev)->gen) {
case 2:
return alternate ? 66 : 48;
case 3:
case 4:
return alternate ? 100 : 96;
default:
return alternate ? 100 : 120;
}
}
static void
parse_general_features(struct drm_i915_private *dev_priv,
struct bdb_header *bdb)
{
struct drm_device *dev = dev_priv->dev;
struct bdb_general_features *general;
general = find_section(bdb, BDB_GENERAL_FEATURES);
if (general) {
dev_priv->int_tv_support = general->int_tv_support;
dev_priv->int_crt_support = general->int_crt_support;
dev_priv->lvds_use_ssc = general->enable_ssc;
dev_priv->lvds_ssc_freq =
intel_bios_ssc_frequency(dev, general->ssc_freq);
}
}
static void
parse_general_definitions(struct drm_i915_private *dev_priv,
struct bdb_header *bdb)
{
struct bdb_general_definitions *general;
general = find_section(bdb, BDB_GENERAL_DEFINITIONS);
if (general) {
u16 block_size = get_blocksize(general);
if (block_size >= sizeof(*general)) {
int bus_pin = general->crt_ddc_gmbus_pin;
DRM_DEBUG_KMS("crt_ddc_bus_pin: %d\n", bus_pin);
if (bus_pin >= 1 && bus_pin <= 6)
dev_priv->crt_ddc_pin = bus_pin;
} else {
DRM_DEBUG_KMS("BDB_GD too small (%d). Invalid.\n",
block_size);
}
}
}
static void
parse_sdvo_device_mapping(struct drm_i915_private *dev_priv,
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
DRM_DEBUG_KMS("Incorrect SDVO port. Skip it \n");
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
p_mapping->i2c_speed = p_child->i2c_speed;
p_mapping->initialized = 1;
DRM_DEBUG_KMS("SDVO device: dvo=%x, addr=%x, wiring=%d, ddc_pin=%d, i2c_pin=%d, i2c_speed=%d\n",
p_mapping->dvo_port,
p_mapping->slave_addr,
p_mapping->dvo_wiring,
p_mapping->ddc_pin,
p_mapping->i2c_pin,
p_mapping->i2c_speed);
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
parse_driver_features(struct drm_i915_private *dev_priv,
struct bdb_header *bdb)
{
struct drm_device *dev = dev_priv->dev;
struct bdb_driver_features *driver;
driver = find_section(bdb, BDB_DRIVER_FEATURES);
if (!driver)
return;
if (SUPPORTS_EDP(dev) &&
driver->lvds_config == BDB_DRIVER_FEATURE_EDP)
dev_priv->edp.support = 1;
if (driver->dual_frequency)
dev_priv->render_reclock_avail = true;
}
static void
parse_edp(struct drm_i915_private *dev_priv, struct bdb_header *bdb)
{
struct bdb_edp *edp;
struct edp_power_seq *edp_pps;
struct edp_link_params *edp_link_params;
edp = find_section(bdb, BDB_EDP);
if (!edp) {
if (SUPPORTS_EDP(dev_priv->dev) && dev_priv->edp.support) {
DRM_DEBUG_KMS("No eDP BDB found but eDP panel "
"supported, assume %dbpp panel color "
"depth.\n",
dev_priv->edp.bpp);
}
return;
}
switch ((edp->color_depth >> (panel_type * 2)) & 3) {
case EDP_18BPP:
dev_priv->edp.bpp = 18;
break;
case EDP_24BPP:
dev_priv->edp.bpp = 24;
break;
case EDP_30BPP:
dev_priv->edp.bpp = 30;
break;
}
edp_pps = &edp->power_seqs[panel_type];
edp_link_params = &edp->link_params[panel_type];
dev_priv->edp.pps = *edp_pps;
dev_priv->edp.rate = edp_link_params->rate ? DP_LINK_BW_2_7 :
DP_LINK_BW_1_62;
switch (edp_link_params->lanes) {
case 0:
dev_priv->edp.lanes = 1;
break;
case 1:
dev_priv->edp.lanes = 2;
break;
case 3:
default:
dev_priv->edp.lanes = 4;
break;
}
switch (edp_link_params->preemphasis) {
case 0:
dev_priv->edp.preemphasis = DP_TRAIN_PRE_EMPHASIS_0;
break;
case 1:
dev_priv->edp.preemphasis = DP_TRAIN_PRE_EMPHASIS_3_5;
break;
case 2:
dev_priv->edp.preemphasis = DP_TRAIN_PRE_EMPHASIS_6;
break;
case 3:
dev_priv->edp.preemphasis = DP_TRAIN_PRE_EMPHASIS_9_5;
break;
}
switch (edp_link_params->vswing) {
case 0:
dev_priv->edp.vswing = DP_TRAIN_VOLTAGE_SWING_400;
break;
case 1:
dev_priv->edp.vswing = DP_TRAIN_VOLTAGE_SWING_600;
break;
case 2:
dev_priv->edp.vswing = DP_TRAIN_VOLTAGE_SWING_800;
break;
case 3:
dev_priv->edp.vswing = DP_TRAIN_VOLTAGE_SWING_1200;
break;
}
}
static void
parse_device_mapping(struct drm_i915_private *dev_priv,
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
DRM_DEBUG_KMS("no child dev is parsed from VBT \n");
return;
}
dev_priv->child_dev = kzalloc(sizeof(*p_child) * count, GFP_KERNEL);
if (!dev_priv->child_dev) {
DRM_DEBUG_KMS("No memory space for child device\n");
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
static void
init_vbt_defaults(struct drm_i915_private *dev_priv)
{
struct drm_device *dev = dev_priv->dev;
dev_priv->crt_ddc_pin = GMBUS_PORT_VGADDC;
dev_priv->lvds_dither = 1;
dev_priv->lvds_vbt = 0;
dev_priv->sdvo_lvds_vbt_mode = NULL;
dev_priv->int_tv_support = 1;
dev_priv->int_crt_support = 1;
dev_priv->lvds_use_ssc = 1;
dev_priv->lvds_ssc_freq = intel_bios_ssc_frequency(dev, 1);
DRM_DEBUG("Set default to SSC at %dMHz\n", dev_priv->lvds_ssc_freq);
dev_priv->edp.bpp = 18;
}
bool
intel_parse_bios(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct pci_dev *pdev = dev->pdev;
struct bdb_header *bdb = NULL;
u8 __iomem *bios = NULL;
init_vbt_defaults(dev_priv);
if (dev_priv->opregion.vbt) {
struct vbt_header *vbt = dev_priv->opregion.vbt;
if (memcmp(vbt->signature, "$VBT", 4) == 0) {
DRM_DEBUG_DRIVER("Using VBT from OpRegion: %20s\n",
vbt->signature);
bdb = (struct bdb_header *)((char *)vbt + vbt->bdb_offset);
} else
dev_priv->opregion.vbt = NULL;
}
if (bdb == NULL) {
struct vbt_header *vbt = NULL;
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
}
parse_general_features(dev_priv, bdb);
parse_general_definitions(dev_priv, bdb);
parse_lfp_panel_data(dev_priv, bdb);
parse_sdvo_panel_data(dev_priv, bdb);
parse_sdvo_device_mapping(dev_priv, bdb);
parse_device_mapping(dev_priv, bdb);
parse_driver_features(dev_priv, bdb);
parse_edp(dev_priv, bdb);
if (bios)
pci_unmap_rom(pdev, bios);
return 0;
}
void intel_setup_bios(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
if ((I915_READ(PP_ON_DELAYS) == 0) && (I915_READ(PP_OFF_DELAYS) == 0)) {
I915_WRITE(PP_ON_DELAYS, 0x019007d0);
I915_WRITE(PP_OFF_DELAYS, 0x015e07d0);
}
}
