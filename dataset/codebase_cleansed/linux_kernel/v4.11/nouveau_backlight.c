static bool
nouveau_get_backlight_name(char backlight_name[BL_NAME_SIZE], struct backlight_connector
*connector)
{
const int nb = ida_simple_get(&bl_ida, 0, 0, GFP_KERNEL);
if (nb < 0 || nb >= 100)
return false;
if (nb > 0)
snprintf(backlight_name, BL_NAME_SIZE, "nv_backlight%d", nb);
else
snprintf(backlight_name, BL_NAME_SIZE, "nv_backlight");
connector->id = nb;
return true;
}
static int
nv40_get_intensity(struct backlight_device *bd)
{
struct nouveau_drm *drm = bl_get_data(bd);
struct nvif_object *device = &drm->client.device.object;
int val = (nvif_rd32(device, NV40_PMC_BACKLIGHT) &
NV40_PMC_BACKLIGHT_MASK) >> 16;
return val;
}
static int
nv40_set_intensity(struct backlight_device *bd)
{
struct nouveau_drm *drm = bl_get_data(bd);
struct nvif_object *device = &drm->client.device.object;
int val = bd->props.brightness;
int reg = nvif_rd32(device, NV40_PMC_BACKLIGHT);
nvif_wr32(device, NV40_PMC_BACKLIGHT,
(val << 16) | (reg & ~NV40_PMC_BACKLIGHT_MASK));
return 0;
}
static int
nv40_backlight_init(struct drm_connector *connector)
{
struct nouveau_drm *drm = nouveau_drm(connector->dev);
struct nvif_object *device = &drm->client.device.object;
struct backlight_properties props;
struct backlight_device *bd;
struct backlight_connector bl_connector;
char backlight_name[BL_NAME_SIZE];
if (!(nvif_rd32(device, NV40_PMC_BACKLIGHT) & NV40_PMC_BACKLIGHT_MASK))
return 0;
memset(&props, 0, sizeof(struct backlight_properties));
props.type = BACKLIGHT_RAW;
props.max_brightness = 31;
if (!nouveau_get_backlight_name(backlight_name, &bl_connector)) {
NV_ERROR(drm, "Failed to retrieve a unique name for the backlight interface\n");
return 0;
}
bd = backlight_device_register(backlight_name , connector->kdev, drm,
&nv40_bl_ops, &props);
if (IS_ERR(bd)) {
if (bl_connector.id > 0)
ida_simple_remove(&bl_ida, bl_connector.id);
return PTR_ERR(bd);
}
list_add(&bl_connector.head, &drm->bl_connectors);
drm->backlight = bd;
bd->props.brightness = nv40_get_intensity(bd);
backlight_update_status(bd);
return 0;
}
static int
nv50_get_intensity(struct backlight_device *bd)
{
struct nouveau_encoder *nv_encoder = bl_get_data(bd);
struct nouveau_drm *drm = nouveau_drm(nv_encoder->base.base.dev);
struct nvif_object *device = &drm->client.device.object;
int or = nv_encoder->or;
u32 div = 1025;
u32 val;
val = nvif_rd32(device, NV50_PDISP_SOR_PWM_CTL(or));
val &= NV50_PDISP_SOR_PWM_CTL_VAL;
return ((val * 100) + (div / 2)) / div;
}
static int
nv50_set_intensity(struct backlight_device *bd)
{
struct nouveau_encoder *nv_encoder = bl_get_data(bd);
struct nouveau_drm *drm = nouveau_drm(nv_encoder->base.base.dev);
struct nvif_object *device = &drm->client.device.object;
int or = nv_encoder->or;
u32 div = 1025;
u32 val = (bd->props.brightness * div) / 100;
nvif_wr32(device, NV50_PDISP_SOR_PWM_CTL(or),
NV50_PDISP_SOR_PWM_CTL_NEW | val);
return 0;
}
static int
nva3_get_intensity(struct backlight_device *bd)
{
struct nouveau_encoder *nv_encoder = bl_get_data(bd);
struct nouveau_drm *drm = nouveau_drm(nv_encoder->base.base.dev);
struct nvif_object *device = &drm->client.device.object;
int or = nv_encoder->or;
u32 div, val;
div = nvif_rd32(device, NV50_PDISP_SOR_PWM_DIV(or));
val = nvif_rd32(device, NV50_PDISP_SOR_PWM_CTL(or));
val &= NVA3_PDISP_SOR_PWM_CTL_VAL;
if (div && div >= val)
return ((val * 100) + (div / 2)) / div;
return 100;
}
static int
nva3_set_intensity(struct backlight_device *bd)
{
struct nouveau_encoder *nv_encoder = bl_get_data(bd);
struct nouveau_drm *drm = nouveau_drm(nv_encoder->base.base.dev);
struct nvif_object *device = &drm->client.device.object;
int or = nv_encoder->or;
u32 div, val;
div = nvif_rd32(device, NV50_PDISP_SOR_PWM_DIV(or));
val = (bd->props.brightness * div) / 100;
if (div) {
nvif_wr32(device, NV50_PDISP_SOR_PWM_CTL(or), val |
NV50_PDISP_SOR_PWM_CTL_NEW |
NVA3_PDISP_SOR_PWM_CTL_UNK);
return 0;
}
return -EINVAL;
}
static int
nv50_backlight_init(struct drm_connector *connector)
{
struct nouveau_drm *drm = nouveau_drm(connector->dev);
struct nvif_object *device = &drm->client.device.object;
struct nouveau_encoder *nv_encoder;
struct backlight_properties props;
struct backlight_device *bd;
const struct backlight_ops *ops;
struct backlight_connector bl_connector;
char backlight_name[BL_NAME_SIZE];
nv_encoder = find_encoder(connector, DCB_OUTPUT_LVDS);
if (!nv_encoder) {
nv_encoder = find_encoder(connector, DCB_OUTPUT_DP);
if (!nv_encoder)
return -ENODEV;
}
if (!nvif_rd32(device, NV50_PDISP_SOR_PWM_CTL(nv_encoder->or)))
return 0;
if (drm->client.device.info.chipset <= 0xa0 ||
drm->client.device.info.chipset == 0xaa ||
drm->client.device.info.chipset == 0xac)
ops = &nv50_bl_ops;
else
ops = &nva3_bl_ops;
memset(&props, 0, sizeof(struct backlight_properties));
props.type = BACKLIGHT_RAW;
props.max_brightness = 100;
if (!nouveau_get_backlight_name(backlight_name, &bl_connector)) {
NV_ERROR(drm, "Failed to retrieve a unique name for the backlight interface\n");
return 0;
}
bd = backlight_device_register(backlight_name , connector->kdev,
nv_encoder, ops, &props);
if (IS_ERR(bd)) {
if (bl_connector.id > 0)
ida_simple_remove(&bl_ida, bl_connector.id);
return PTR_ERR(bd);
}
list_add(&bl_connector.head, &drm->bl_connectors);
drm->backlight = bd;
bd->props.brightness = bd->ops->get_brightness(bd);
backlight_update_status(bd);
return 0;
}
int
nouveau_backlight_init(struct drm_device *dev)
{
struct nouveau_drm *drm = nouveau_drm(dev);
struct nvif_device *device = &drm->client.device;
struct drm_connector *connector;
if (apple_gmux_present()) {
NV_INFO(drm, "Apple GMUX detected: not registering Nouveau backlight interface\n");
return 0;
}
INIT_LIST_HEAD(&drm->bl_connectors);
list_for_each_entry(connector, &dev->mode_config.connector_list, head) {
if (connector->connector_type != DRM_MODE_CONNECTOR_LVDS &&
connector->connector_type != DRM_MODE_CONNECTOR_eDP)
continue;
switch (device->info.family) {
case NV_DEVICE_INFO_V0_CURIE:
return nv40_backlight_init(connector);
case NV_DEVICE_INFO_V0_TESLA:
case NV_DEVICE_INFO_V0_FERMI:
case NV_DEVICE_INFO_V0_KEPLER:
case NV_DEVICE_INFO_V0_MAXWELL:
return nv50_backlight_init(connector);
default:
break;
}
}
return 0;
}
void
nouveau_backlight_exit(struct drm_device *dev)
{
struct nouveau_drm *drm = nouveau_drm(dev);
struct backlight_connector *connector;
list_for_each_entry(connector, &drm->bl_connectors, head) {
if (connector->id >= 0)
ida_simple_remove(&bl_ida, connector->id);
}
if (drm->backlight) {
backlight_device_unregister(drm->backlight);
drm->backlight = NULL;
}
}
void
nouveau_backlight_ctor(void)
{
ida_init(&bl_ida);
}
void
nouveau_backlight_dtor(void)
{
ida_destroy(&bl_ida);
}
