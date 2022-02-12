static struct nouveau_encoder *
find_encoder_by_type(struct drm_connector *connector, int type)
{
struct drm_device *dev = connector->dev;
struct nouveau_encoder *nv_encoder;
struct drm_mode_object *obj;
int i, id;
for (i = 0; i < DRM_CONNECTOR_MAX_ENCODER; i++) {
id = connector->encoder_ids[i];
if (!id)
break;
obj = drm_mode_object_find(dev, id, DRM_MODE_OBJECT_ENCODER);
if (!obj)
continue;
nv_encoder = nouveau_encoder(obj_to_encoder(obj));
if (type == OUTPUT_ANY || nv_encoder->dcb->type == type)
return nv_encoder;
}
return NULL;
}
struct nouveau_connector *
nouveau_encoder_connector_get(struct nouveau_encoder *encoder)
{
struct drm_device *dev = to_drm_encoder(encoder)->dev;
struct drm_connector *drm_connector;
list_for_each_entry(drm_connector, &dev->mode_config.connector_list, head) {
if (drm_connector->encoder == to_drm_encoder(encoder))
return nouveau_connector(drm_connector);
}
return NULL;
}
int
nouveau_connector_bpp(struct drm_connector *connector)
{
struct nouveau_connector *nv_connector = nouveau_connector(connector);
if (nv_connector->edid && nv_connector->edid->revision >= 4) {
u8 bpc = ((nv_connector->edid->input & 0x70) >> 3) + 4;
if (bpc > 4)
return bpc;
}
return 18;
}
static void
nouveau_connector_destroy(struct drm_connector *connector)
{
struct nouveau_connector *nv_connector = nouveau_connector(connector);
struct drm_nouveau_private *dev_priv;
struct nouveau_gpio_engine *pgpio;
struct drm_device *dev;
if (!nv_connector)
return;
dev = nv_connector->base.dev;
dev_priv = dev->dev_private;
NV_DEBUG_KMS(dev, "\n");
pgpio = &dev_priv->engine.gpio;
if (pgpio->irq_unregister) {
pgpio->irq_unregister(dev, nv_connector->dcb->gpio_tag,
nouveau_connector_hotplug, connector);
}
if (connector->connector_type == DRM_MODE_CONNECTOR_LVDS ||
connector->connector_type == DRM_MODE_CONNECTOR_eDP)
nouveau_backlight_exit(connector);
kfree(nv_connector->edid);
drm_sysfs_connector_remove(connector);
drm_connector_cleanup(connector);
kfree(connector);
}
static struct nouveau_i2c_chan *
nouveau_connector_ddc_detect(struct drm_connector *connector,
struct nouveau_encoder **pnv_encoder)
{
struct drm_device *dev = connector->dev;
int i;
for (i = 0; i < DRM_CONNECTOR_MAX_ENCODER; i++) {
struct nouveau_i2c_chan *i2c = NULL;
struct nouveau_encoder *nv_encoder;
struct drm_mode_object *obj;
int id;
id = connector->encoder_ids[i];
if (!id)
break;
obj = drm_mode_object_find(dev, id, DRM_MODE_OBJECT_ENCODER);
if (!obj)
continue;
nv_encoder = nouveau_encoder(obj_to_encoder(obj));
if (nv_encoder->dcb->i2c_index < 0xf)
i2c = nouveau_i2c_find(dev, nv_encoder->dcb->i2c_index);
if (i2c && nouveau_probe_i2c_addr(i2c, 0x50)) {
*pnv_encoder = nv_encoder;
return i2c;
}
}
return NULL;
}
static struct nouveau_encoder *
nouveau_connector_of_detect(struct drm_connector *connector)
{
#ifdef __powerpc__
struct drm_device *dev = connector->dev;
struct nouveau_connector *nv_connector = nouveau_connector(connector);
struct nouveau_encoder *nv_encoder;
struct device_node *cn, *dn = pci_device_to_OF_node(dev->pdev);
if (!dn ||
!((nv_encoder = find_encoder_by_type(connector, OUTPUT_TMDS)) ||
(nv_encoder = find_encoder_by_type(connector, OUTPUT_ANALOG))))
return NULL;
for_each_child_of_node(dn, cn) {
const char *name = of_get_property(cn, "name", NULL);
const void *edid = of_get_property(cn, "EDID", NULL);
int idx = name ? name[strlen(name) - 1] - 'A' : 0;
if (nv_encoder->dcb->i2c_index == idx && edid) {
nv_connector->edid =
kmemdup(edid, EDID_LENGTH, GFP_KERNEL);
of_node_put(cn);
return nv_encoder;
}
}
#endif
return NULL;
}
static void
nouveau_connector_set_encoder(struct drm_connector *connector,
struct nouveau_encoder *nv_encoder)
{
struct nouveau_connector *nv_connector = nouveau_connector(connector);
struct drm_nouveau_private *dev_priv = connector->dev->dev_private;
struct drm_device *dev = connector->dev;
if (nv_connector->detected_encoder == nv_encoder)
return;
nv_connector->detected_encoder = nv_encoder;
if (nv_encoder->dcb->type == OUTPUT_LVDS ||
nv_encoder->dcb->type == OUTPUT_TMDS) {
connector->doublescan_allowed = false;
connector->interlace_allowed = false;
} else {
connector->doublescan_allowed = true;
if (dev_priv->card_type == NV_20 ||
(dev_priv->card_type == NV_10 &&
(dev->pci_device & 0x0ff0) != 0x0100 &&
(dev->pci_device & 0x0ff0) != 0x0150))
connector->interlace_allowed = false;
else
connector->interlace_allowed = true;
}
if (nv_connector->dcb->type == DCB_CONNECTOR_DVI_I) {
drm_connector_property_set_value(connector,
dev->mode_config.dvi_i_subconnector_property,
nv_encoder->dcb->type == OUTPUT_TMDS ?
DRM_MODE_SUBCONNECTOR_DVID :
DRM_MODE_SUBCONNECTOR_DVIA);
}
}
static enum drm_connector_status
nouveau_connector_detect(struct drm_connector *connector, bool force)
{
struct drm_device *dev = connector->dev;
struct nouveau_connector *nv_connector = nouveau_connector(connector);
struct nouveau_encoder *nv_encoder = NULL;
struct nouveau_i2c_chan *i2c;
int type;
if (nv_connector->edid) {
drm_mode_connector_update_edid_property(connector, NULL);
kfree(nv_connector->edid);
nv_connector->edid = NULL;
}
i2c = nouveau_connector_ddc_detect(connector, &nv_encoder);
if (i2c) {
nv_connector->edid = drm_get_edid(connector, &i2c->adapter);
drm_mode_connector_update_edid_property(connector,
nv_connector->edid);
if (!nv_connector->edid) {
NV_ERROR(dev, "DDC responded, but no EDID for %s\n",
drm_get_connector_name(connector));
goto detect_analog;
}
if (nv_encoder->dcb->type == OUTPUT_DP &&
!nouveau_dp_detect(to_drm_encoder(nv_encoder))) {
NV_ERROR(dev, "Detected %s, but failed init\n",
drm_get_connector_name(connector));
return connector_status_disconnected;
}
if (nv_connector->dcb->type == DCB_CONNECTOR_DVI_I) {
if (nv_connector->edid->input & DRM_EDID_INPUT_DIGITAL)
type = OUTPUT_TMDS;
else
type = OUTPUT_ANALOG;
nv_encoder = find_encoder_by_type(connector, type);
if (!nv_encoder) {
NV_ERROR(dev, "Detected %d encoder on %s, "
"but no object!\n", type,
drm_get_connector_name(connector));
return connector_status_disconnected;
}
}
nouveau_connector_set_encoder(connector, nv_encoder);
return connector_status_connected;
}
nv_encoder = nouveau_connector_of_detect(connector);
if (nv_encoder) {
nouveau_connector_set_encoder(connector, nv_encoder);
return connector_status_connected;
}
detect_analog:
nv_encoder = find_encoder_by_type(connector, OUTPUT_ANALOG);
if (!nv_encoder && !nouveau_tv_disable)
nv_encoder = find_encoder_by_type(connector, OUTPUT_TV);
if (nv_encoder && force) {
struct drm_encoder *encoder = to_drm_encoder(nv_encoder);
struct drm_encoder_helper_funcs *helper =
encoder->helper_private;
if (helper->detect(encoder, connector) ==
connector_status_connected) {
nouveau_connector_set_encoder(connector, nv_encoder);
return connector_status_connected;
}
}
return connector_status_disconnected;
}
static enum drm_connector_status
nouveau_connector_detect_lvds(struct drm_connector *connector, bool force)
{
struct drm_device *dev = connector->dev;
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct nouveau_connector *nv_connector = nouveau_connector(connector);
struct nouveau_encoder *nv_encoder = NULL;
enum drm_connector_status status = connector_status_disconnected;
if (nv_connector->edid) {
drm_mode_connector_update_edid_property(connector, NULL);
kfree(nv_connector->edid);
nv_connector->edid = NULL;
}
nv_encoder = find_encoder_by_type(connector, OUTPUT_LVDS);
if (!nv_encoder)
return connector_status_disconnected;
if (!dev_priv->vbios.fp_no_ddc) {
status = nouveau_connector_detect(connector, force);
if (status == connector_status_connected)
goto out;
}
if (nv_encoder->dcb->lvdsconf.use_acpi_for_edid) {
if (!nouveau_acpi_edid(dev, connector)) {
status = connector_status_connected;
goto out;
}
}
if (nouveau_bios_fp_mode(dev, NULL) && (dev_priv->vbios.fp_no_ddc ||
nv_encoder->dcb->lvdsconf.use_straps_for_mode)) {
status = connector_status_connected;
goto out;
}
if (!dev_priv->vbios.fp_no_ddc) {
struct edid *edid =
(struct edid *)nouveau_bios_embedded_edid(dev);
if (edid) {
nv_connector->edid = kmalloc(EDID_LENGTH, GFP_KERNEL);
*(nv_connector->edid) = *edid;
status = connector_status_connected;
}
}
out:
#if defined(CONFIG_ACPI_BUTTON) || \
(defined(CONFIG_ACPI_BUTTON_MODULE) && defined(MODULE))
if (status == connector_status_connected &&
!nouveau_ignorelid && !acpi_lid_open())
status = connector_status_unknown;
#endif
drm_mode_connector_update_edid_property(connector, nv_connector->edid);
nouveau_connector_set_encoder(connector, nv_encoder);
return status;
}
static void
nouveau_connector_force(struct drm_connector *connector)
{
struct nouveau_connector *nv_connector = nouveau_connector(connector);
struct nouveau_encoder *nv_encoder;
int type;
if (nv_connector->dcb->type == DCB_CONNECTOR_DVI_I) {
if (connector->force == DRM_FORCE_ON_DIGITAL)
type = OUTPUT_TMDS;
else
type = OUTPUT_ANALOG;
} else
type = OUTPUT_ANY;
nv_encoder = find_encoder_by_type(connector, type);
if (!nv_encoder) {
NV_ERROR(connector->dev, "can't find encoder to force %s on!\n",
drm_get_connector_name(connector));
connector->status = connector_status_disconnected;
return;
}
nouveau_connector_set_encoder(connector, nv_encoder);
}
static int
nouveau_connector_set_property(struct drm_connector *connector,
struct drm_property *property, uint64_t value)
{
struct nouveau_connector *nv_connector = nouveau_connector(connector);
struct nouveau_encoder *nv_encoder = nv_connector->detected_encoder;
struct drm_encoder *encoder = to_drm_encoder(nv_encoder);
struct drm_device *dev = connector->dev;
int ret;
if (property == dev->mode_config.scaling_mode_property) {
struct nouveau_crtc *nv_crtc = NULL;
bool modeset = false;
switch (value) {
case DRM_MODE_SCALE_NONE:
case DRM_MODE_SCALE_FULLSCREEN:
case DRM_MODE_SCALE_CENTER:
case DRM_MODE_SCALE_ASPECT:
break;
default:
return -EINVAL;
}
if (connector->connector_type == DRM_MODE_CONNECTOR_LVDS &&
value == DRM_MODE_SCALE_NONE)
return -EINVAL;
if ((nv_connector->scaling_mode == DRM_MODE_SCALE_NONE) ||
(value == DRM_MODE_SCALE_NONE))
modeset = true;
nv_connector->scaling_mode = value;
if (connector->encoder && connector->encoder->crtc)
nv_crtc = nouveau_crtc(connector->encoder->crtc);
if (!nv_crtc)
return 0;
if (modeset || !nv_crtc->set_scale) {
ret = drm_crtc_helper_set_mode(&nv_crtc->base,
&nv_crtc->base.mode,
nv_crtc->base.x,
nv_crtc->base.y, NULL);
if (!ret)
return -EINVAL;
} else {
ret = nv_crtc->set_scale(nv_crtc, value, true);
if (ret)
return ret;
}
return 0;
}
if (property == dev->mode_config.dithering_mode_property) {
struct nouveau_crtc *nv_crtc = NULL;
if (value == DRM_MODE_DITHERING_ON)
nv_connector->use_dithering = true;
else
nv_connector->use_dithering = false;
if (connector->encoder && connector->encoder->crtc)
nv_crtc = nouveau_crtc(connector->encoder->crtc);
if (!nv_crtc || !nv_crtc->set_dither)
return 0;
return nv_crtc->set_dither(nv_crtc, nv_connector->use_dithering,
true);
}
if (nv_encoder && nv_encoder->dcb->type == OUTPUT_TV)
return get_slave_funcs(encoder)->set_property(
encoder, connector, property, value);
return -EINVAL;
}
static struct drm_display_mode *
nouveau_connector_native_mode(struct drm_connector *connector)
{
struct drm_connector_helper_funcs *helper = connector->helper_private;
struct nouveau_connector *nv_connector = nouveau_connector(connector);
struct drm_device *dev = connector->dev;
struct drm_display_mode *mode, *largest = NULL;
int high_w = 0, high_h = 0, high_v = 0;
list_for_each_entry(mode, &nv_connector->base.probed_modes, head) {
mode->vrefresh = drm_mode_vrefresh(mode);
if (helper->mode_valid(connector, mode) != MODE_OK ||
(mode->flags & DRM_MODE_FLAG_INTERLACE))
continue;
if (mode->type & DRM_MODE_TYPE_PREFERRED) {
NV_DEBUG_KMS(dev, "native mode from preferred\n");
return drm_mode_duplicate(dev, mode);
}
if (mode->hdisplay < high_w)
continue;
if (mode->hdisplay == high_w && mode->vdisplay < high_h)
continue;
if (mode->hdisplay == high_w && mode->vdisplay == high_h &&
mode->vrefresh < high_v)
continue;
high_w = mode->hdisplay;
high_h = mode->vdisplay;
high_v = mode->vrefresh;
largest = mode;
}
NV_DEBUG_KMS(dev, "native mode from largest: %dx%d@%d\n",
high_w, high_h, high_v);
return largest ? drm_mode_duplicate(dev, largest) : NULL;
}
static int
nouveau_connector_scaler_modes_add(struct drm_connector *connector)
{
struct nouveau_connector *nv_connector = nouveau_connector(connector);
struct drm_display_mode *native = nv_connector->native_mode, *m;
struct drm_device *dev = connector->dev;
struct moderec *mode = &scaler_modes[0];
int modes = 0;
if (!native)
return 0;
while (mode->hdisplay) {
if (mode->hdisplay <= native->hdisplay &&
mode->vdisplay <= native->vdisplay) {
m = drm_cvt_mode(dev, mode->hdisplay, mode->vdisplay,
drm_mode_vrefresh(native), false,
false, false);
if (!m)
continue;
m->type |= DRM_MODE_TYPE_DRIVER;
drm_mode_probed_add(connector, m);
modes++;
}
mode++;
}
return modes;
}
static int
nouveau_connector_get_modes(struct drm_connector *connector)
{
struct drm_device *dev = connector->dev;
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct nouveau_connector *nv_connector = nouveau_connector(connector);
struct nouveau_encoder *nv_encoder = nv_connector->detected_encoder;
struct drm_encoder *encoder = to_drm_encoder(nv_encoder);
int ret = 0;
if (nv_connector->native_mode) {
drm_mode_destroy(dev, nv_connector->native_mode);
nv_connector->native_mode = NULL;
}
if (nv_connector->edid)
ret = drm_add_edid_modes(connector, nv_connector->edid);
else
if (nv_encoder->dcb->type == OUTPUT_LVDS &&
(nv_encoder->dcb->lvdsconf.use_straps_for_mode ||
dev_priv->vbios.fp_no_ddc) && nouveau_bios_fp_mode(dev, NULL)) {
struct drm_display_mode mode;
nouveau_bios_fp_mode(dev, &mode);
nv_connector->native_mode = drm_mode_duplicate(dev, &mode);
}
if (!nv_connector->native_mode)
nv_connector->native_mode =
nouveau_connector_native_mode(connector);
if (ret == 0 && nv_connector->native_mode) {
struct drm_display_mode *mode;
mode = drm_mode_duplicate(dev, nv_connector->native_mode);
drm_mode_probed_add(connector, mode);
ret = 1;
}
if (nv_encoder->dcb->type == OUTPUT_TV)
ret = get_slave_funcs(encoder)->get_modes(encoder, connector);
if (nv_connector->dcb->type == DCB_CONNECTOR_LVDS ||
nv_connector->dcb->type == DCB_CONNECTOR_LVDS_SPWG ||
nv_connector->dcb->type == DCB_CONNECTOR_eDP)
ret += nouveau_connector_scaler_modes_add(connector);
return ret;
}
static unsigned
get_tmds_link_bandwidth(struct drm_connector *connector)
{
struct nouveau_connector *nv_connector = nouveau_connector(connector);
struct drm_nouveau_private *dev_priv = connector->dev->dev_private;
struct dcb_entry *dcb = nv_connector->detected_encoder->dcb;
if (dcb->location != DCB_LOC_ON_CHIP ||
dev_priv->chipset >= 0x46)
return 165000;
else if (dev_priv->chipset >= 0x40)
return 155000;
else if (dev_priv->chipset >= 0x18)
return 135000;
else
return 112000;
}
static int
nouveau_connector_mode_valid(struct drm_connector *connector,
struct drm_display_mode *mode)
{
struct nouveau_connector *nv_connector = nouveau_connector(connector);
struct nouveau_encoder *nv_encoder = nv_connector->detected_encoder;
struct drm_encoder *encoder = to_drm_encoder(nv_encoder);
unsigned min_clock = 25000, max_clock = min_clock;
unsigned clock = mode->clock;
switch (nv_encoder->dcb->type) {
case OUTPUT_LVDS:
if (nv_connector->native_mode &&
(mode->hdisplay > nv_connector->native_mode->hdisplay ||
mode->vdisplay > nv_connector->native_mode->vdisplay))
return MODE_PANEL;
min_clock = 0;
max_clock = 400000;
break;
case OUTPUT_TMDS:
max_clock = get_tmds_link_bandwidth(connector);
if (nouveau_duallink && nv_encoder->dcb->duallink_possible)
max_clock *= 2;
break;
case OUTPUT_ANALOG:
max_clock = nv_encoder->dcb->crtconf.maxfreq;
if (!max_clock)
max_clock = 350000;
break;
case OUTPUT_TV:
return get_slave_funcs(encoder)->mode_valid(encoder, mode);
case OUTPUT_DP:
if (nv_encoder->dp.link_bw == DP_LINK_BW_2_7)
max_clock = nv_encoder->dp.link_nr * 270000;
else
max_clock = nv_encoder->dp.link_nr * 162000;
clock = clock * nouveau_connector_bpp(connector) / 8;
break;
default:
BUG_ON(1);
return MODE_BAD;
}
if (clock < min_clock)
return MODE_CLOCK_LOW;
if (clock > max_clock)
return MODE_CLOCK_HIGH;
return MODE_OK;
}
static struct drm_encoder *
nouveau_connector_best_encoder(struct drm_connector *connector)
{
struct nouveau_connector *nv_connector = nouveau_connector(connector);
if (nv_connector->detected_encoder)
return to_drm_encoder(nv_connector->detected_encoder);
return NULL;
}
struct drm_connector *
nouveau_connector_create(struct drm_device *dev, int index)
{
const struct drm_connector_funcs *funcs = &nouveau_connector_funcs;
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct nouveau_gpio_engine *pgpio = &dev_priv->engine.gpio;
struct nouveau_connector *nv_connector = NULL;
struct dcb_connector_table_entry *dcb = NULL;
struct drm_connector *connector;
int type, ret = 0;
NV_DEBUG_KMS(dev, "\n");
if (index >= dev_priv->vbios.dcb.connector.entries)
return ERR_PTR(-EINVAL);
dcb = &dev_priv->vbios.dcb.connector.entry[index];
if (dcb->drm)
return dcb->drm;
switch (dcb->type) {
case DCB_CONNECTOR_VGA:
type = DRM_MODE_CONNECTOR_VGA;
break;
case DCB_CONNECTOR_TV_0:
case DCB_CONNECTOR_TV_1:
case DCB_CONNECTOR_TV_3:
type = DRM_MODE_CONNECTOR_TV;
break;
case DCB_CONNECTOR_DVI_I:
type = DRM_MODE_CONNECTOR_DVII;
break;
case DCB_CONNECTOR_DVI_D:
type = DRM_MODE_CONNECTOR_DVID;
break;
case DCB_CONNECTOR_HDMI_0:
case DCB_CONNECTOR_HDMI_1:
type = DRM_MODE_CONNECTOR_HDMIA;
break;
case DCB_CONNECTOR_LVDS:
case DCB_CONNECTOR_LVDS_SPWG:
type = DRM_MODE_CONNECTOR_LVDS;
funcs = &nouveau_connector_funcs_lvds;
break;
case DCB_CONNECTOR_DP:
type = DRM_MODE_CONNECTOR_DisplayPort;
break;
case DCB_CONNECTOR_eDP:
type = DRM_MODE_CONNECTOR_eDP;
break;
default:
NV_ERROR(dev, "unknown connector type: 0x%02x!!\n", dcb->type);
return ERR_PTR(-EINVAL);
}
nv_connector = kzalloc(sizeof(*nv_connector), GFP_KERNEL);
if (!nv_connector)
return ERR_PTR(-ENOMEM);
nv_connector->dcb = dcb;
connector = &nv_connector->base;
connector->interlace_allowed = false;
connector->doublescan_allowed = false;
drm_connector_init(dev, connector, funcs, type);
drm_connector_helper_add(connector, &nouveau_connector_helper_funcs);
if (connector->connector_type == DRM_MODE_CONNECTOR_LVDS) {
bool dummy, is_24bit = false;
ret = nouveau_bios_parse_lvds_table(dev, 0, &dummy, &is_24bit);
if (ret) {
NV_ERROR(dev, "Error parsing LVDS table, disabling "
"LVDS\n");
goto fail;
}
nv_connector->use_dithering = !is_24bit;
}
if (dcb->type == DCB_CONNECTOR_DVI_I) {
drm_mode_create_dvi_i_properties(dev);
drm_connector_attach_property(connector, dev->mode_config.dvi_i_subconnector_property, 0);
drm_connector_attach_property(connector, dev->mode_config.dvi_i_select_subconnector_property, 0);
}
switch (dcb->type) {
case DCB_CONNECTOR_VGA:
if (dev_priv->card_type >= NV_50) {
drm_connector_attach_property(connector,
dev->mode_config.scaling_mode_property,
nv_connector->scaling_mode);
}
connector->polled = DRM_CONNECTOR_POLL_CONNECT;
case DCB_CONNECTOR_TV_0:
case DCB_CONNECTOR_TV_1:
case DCB_CONNECTOR_TV_3:
nv_connector->scaling_mode = DRM_MODE_SCALE_NONE;
break;
default:
nv_connector->scaling_mode = DRM_MODE_SCALE_FULLSCREEN;
drm_connector_attach_property(connector,
dev->mode_config.scaling_mode_property,
nv_connector->scaling_mode);
drm_connector_attach_property(connector,
dev->mode_config.dithering_mode_property,
nv_connector->use_dithering ?
DRM_MODE_DITHERING_ON : DRM_MODE_DITHERING_OFF);
if (connector->connector_type != DRM_MODE_CONNECTOR_LVDS) {
if (dev_priv->card_type >= NV_50)
connector->polled = DRM_CONNECTOR_POLL_HPD;
else
connector->polled = DRM_CONNECTOR_POLL_CONNECT;
}
break;
}
if (pgpio->irq_register) {
pgpio->irq_register(dev, nv_connector->dcb->gpio_tag,
nouveau_connector_hotplug, connector);
}
drm_sysfs_connector_add(connector);
if (connector->connector_type == DRM_MODE_CONNECTOR_LVDS ||
connector->connector_type == DRM_MODE_CONNECTOR_eDP)
nouveau_backlight_init(connector);
dcb->drm = connector;
return dcb->drm;
fail:
drm_connector_cleanup(connector);
kfree(connector);
return ERR_PTR(ret);
}
static void
nouveau_connector_hotplug(void *data, int plugged)
{
struct drm_connector *connector = data;
struct drm_device *dev = connector->dev;
NV_INFO(dev, "%splugged %s\n", plugged ? "" : "un",
drm_get_connector_name(connector));
if (connector->encoder && connector->encoder->crtc &&
connector->encoder->crtc->enabled) {
struct nouveau_encoder *nv_encoder = nouveau_encoder(connector->encoder);
struct drm_encoder_helper_funcs *helper =
connector->encoder->helper_private;
if (nv_encoder->dcb->type == OUTPUT_DP) {
if (plugged)
helper->dpms(connector->encoder, DRM_MODE_DPMS_ON);
else
helper->dpms(connector->encoder, DRM_MODE_DPMS_OFF);
}
}
drm_helper_hpd_irq_event(dev);
}
