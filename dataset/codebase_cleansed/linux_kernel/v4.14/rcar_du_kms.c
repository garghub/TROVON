const struct rcar_du_format_info *rcar_du_format_info(u32 fourcc)
{
unsigned int i;
for (i = 0; i < ARRAY_SIZE(rcar_du_format_infos); ++i) {
if (rcar_du_format_infos[i].fourcc == fourcc)
return &rcar_du_format_infos[i];
}
return NULL;
}
int rcar_du_dumb_create(struct drm_file *file, struct drm_device *dev,
struct drm_mode_create_dumb *args)
{
struct rcar_du_device *rcdu = dev->dev_private;
unsigned int min_pitch = DIV_ROUND_UP(args->width * args->bpp, 8);
unsigned int align;
if (rcar_du_needs(rcdu, RCAR_DU_QUIRK_ALIGN_128B))
align = 128;
else
align = 16 * args->bpp / 8;
args->pitch = roundup(min_pitch, align);
return drm_gem_cma_dumb_create_internal(file, dev, args);
}
static struct drm_framebuffer *
rcar_du_fb_create(struct drm_device *dev, struct drm_file *file_priv,
const struct drm_mode_fb_cmd2 *mode_cmd)
{
struct rcar_du_device *rcdu = dev->dev_private;
const struct rcar_du_format_info *format;
unsigned int max_pitch;
unsigned int align;
unsigned int bpp;
unsigned int i;
format = rcar_du_format_info(mode_cmd->pixel_format);
if (format == NULL) {
dev_dbg(dev->dev, "unsupported pixel format %08x\n",
mode_cmd->pixel_format);
return ERR_PTR(-EINVAL);
}
bpp = format->planes == 1 ? format->bpp / 8 : 1;
max_pitch = 4096 * bpp;
if (rcar_du_needs(rcdu, RCAR_DU_QUIRK_ALIGN_128B))
align = 128;
else
align = 16 * bpp;
if (mode_cmd->pitches[0] & (align - 1) ||
mode_cmd->pitches[0] >= max_pitch) {
dev_dbg(dev->dev, "invalid pitch value %u\n",
mode_cmd->pitches[0]);
return ERR_PTR(-EINVAL);
}
for (i = 1; i < format->planes; ++i) {
if (mode_cmd->pitches[i] != mode_cmd->pitches[0]) {
dev_dbg(dev->dev,
"luma and chroma pitches do not match\n");
return ERR_PTR(-EINVAL);
}
}
return drm_fb_cma_create(dev, file_priv, mode_cmd);
}
static void rcar_du_output_poll_changed(struct drm_device *dev)
{
struct rcar_du_device *rcdu = dev->dev_private;
drm_fbdev_cma_hotplug_event(rcdu->fbdev);
}
static int rcar_du_atomic_check(struct drm_device *dev,
struct drm_atomic_state *state)
{
struct rcar_du_device *rcdu = dev->dev_private;
int ret;
ret = drm_atomic_helper_check_modeset(dev, state);
if (ret)
return ret;
ret = drm_atomic_normalize_zpos(dev, state);
if (ret)
return ret;
ret = drm_atomic_helper_check_planes(dev, state);
if (ret)
return ret;
if (rcar_du_has(rcdu, RCAR_DU_FEATURE_VSP1_SOURCE))
return 0;
return rcar_du_atomic_check_planes(dev, state);
}
static void rcar_du_atomic_commit_tail(struct drm_atomic_state *old_state)
{
struct drm_device *dev = old_state->dev;
drm_atomic_helper_commit_modeset_disables(dev, old_state);
drm_atomic_helper_commit_planes(dev, old_state,
DRM_PLANE_COMMIT_ACTIVE_ONLY);
drm_atomic_helper_commit_modeset_enables(dev, old_state);
drm_atomic_helper_commit_hw_done(old_state);
drm_atomic_helper_wait_for_flip_done(dev, old_state);
drm_atomic_helper_cleanup_planes(dev, old_state);
}
static int rcar_du_encoders_init_one(struct rcar_du_device *rcdu,
enum rcar_du_output output,
struct of_endpoint *ep)
{
struct device_node *connector = NULL;
struct device_node *encoder = NULL;
struct device_node *ep_node = NULL;
struct device_node *entity_ep_node;
struct device_node *entity;
int ret;
entity = of_graph_get_remote_port_parent(ep->local_node);
if (!entity) {
dev_dbg(rcdu->dev, "unconnected endpoint %pOF, skipping\n",
ep->local_node);
return -ENODEV;
}
if (!of_device_is_available(entity)) {
dev_dbg(rcdu->dev,
"connected entity %pOF is disabled, skipping\n",
entity);
return -ENODEV;
}
entity_ep_node = of_graph_get_remote_endpoint(ep->local_node);
for_each_endpoint_of_node(entity, ep_node) {
if (ep_node == entity_ep_node)
continue;
encoder = entity;
connector = of_graph_get_remote_port_parent(ep_node);
of_node_put(ep_node);
if (!connector) {
dev_warn(rcdu->dev,
"no connector for encoder %pOF, skipping\n",
encoder);
of_node_put(entity_ep_node);
of_node_put(encoder);
return -ENODEV;
}
break;
}
of_node_put(entity_ep_node);
if (!encoder) {
connector = entity;
}
ret = rcar_du_encoder_init(rcdu, output, encoder, connector);
if (ret && ret != -EPROBE_DEFER)
dev_warn(rcdu->dev,
"failed to initialize encoder %pOF on output %u (%d), skipping\n",
encoder, output, ret);
of_node_put(encoder);
of_node_put(connector);
return ret;
}
static int rcar_du_encoders_init(struct rcar_du_device *rcdu)
{
struct device_node *np = rcdu->dev->of_node;
struct device_node *ep_node;
unsigned int num_encoders = 0;
for_each_endpoint_of_node(np, ep_node) {
enum rcar_du_output output;
struct of_endpoint ep;
unsigned int i;
int ret;
ret = of_graph_parse_endpoint(ep_node, &ep);
if (ret < 0) {
of_node_put(ep_node);
return ret;
}
for (i = 0; i < RCAR_DU_OUTPUT_MAX; ++i) {
if (rcdu->info->routes[i].possible_crtcs &&
rcdu->info->routes[i].port == ep.port) {
output = i;
break;
}
}
if (i == RCAR_DU_OUTPUT_MAX) {
dev_warn(rcdu->dev,
"port %u references unexisting output, skipping\n",
ep.port);
continue;
}
ret = rcar_du_encoders_init_one(rcdu, output, &ep);
if (ret < 0) {
if (ret == -EPROBE_DEFER) {
of_node_put(ep_node);
return ret;
}
continue;
}
num_encoders++;
}
return num_encoders;
}
static int rcar_du_properties_init(struct rcar_du_device *rcdu)
{
rcdu->props.alpha =
drm_property_create_range(rcdu->ddev, 0, "alpha", 0, 255);
if (rcdu->props.alpha == NULL)
return -ENOMEM;
rcdu->props.colorkey =
drm_property_create_range(rcdu->ddev, 0, "colorkey",
0, 0x01ffffff);
if (rcdu->props.colorkey == NULL)
return -ENOMEM;
return 0;
}
static int rcar_du_vsps_init(struct rcar_du_device *rcdu)
{
const struct device_node *np = rcdu->dev->of_node;
struct of_phandle_args args;
struct {
struct device_node *np;
unsigned int crtcs_mask;
} vsps[RCAR_DU_MAX_VSPS] = { { 0, }, };
unsigned int vsps_count = 0;
unsigned int cells;
unsigned int i;
int ret;
cells = of_property_count_u32_elems(np, "vsps") / rcdu->num_crtcs - 1;
if (cells > 1)
return -EINVAL;
for (i = 0; i < rcdu->num_crtcs; ++i) {
unsigned int j;
ret = of_parse_phandle_with_fixed_args(np, "vsps", cells, i,
&args);
if (ret < 0)
goto error;
for (j = 0; j < vsps_count; ++j) {
if (vsps[j].np == args.np)
break;
}
if (j < vsps_count)
of_node_put(args.np);
else
vsps[vsps_count++].np = args.np;
vsps[j].crtcs_mask |= BIT(i);
rcdu->crtcs[i].vsp = &rcdu->vsps[j];
rcdu->crtcs[i].vsp_pipe = cells >= 1 ? args.args[0] : 0;
}
for (i = 0; i < vsps_count; ++i) {
struct rcar_du_vsp *vsp = &rcdu->vsps[i];
vsp->index = i;
vsp->dev = rcdu;
ret = rcar_du_vsp_init(vsp, vsps[i].np, vsps[i].crtcs_mask);
if (ret < 0)
goto error;
}
return 0;
error:
for (i = 0; i < ARRAY_SIZE(vsps); ++i)
of_node_put(vsps[i].np);
return ret;
}
int rcar_du_modeset_init(struct rcar_du_device *rcdu)
{
static const unsigned int mmio_offsets[] = {
DU0_REG_OFFSET, DU2_REG_OFFSET
};
struct drm_device *dev = rcdu->ddev;
struct drm_encoder *encoder;
struct drm_fbdev_cma *fbdev;
unsigned int num_encoders;
unsigned int num_groups;
unsigned int i;
int ret;
drm_mode_config_init(dev);
dev->mode_config.min_width = 0;
dev->mode_config.min_height = 0;
dev->mode_config.max_width = 4095;
dev->mode_config.max_height = 2047;
dev->mode_config.funcs = &rcar_du_mode_config_funcs;
dev->mode_config.helper_private = &rcar_du_mode_config_helper;
rcdu->num_crtcs = rcdu->info->num_crtcs;
ret = rcar_du_properties_init(rcdu);
if (ret < 0)
return ret;
ret = drm_vblank_init(dev, (1 << rcdu->info->num_crtcs) - 1);
if (ret < 0)
return ret;
num_groups = DIV_ROUND_UP(rcdu->num_crtcs, 2);
for (i = 0; i < num_groups; ++i) {
struct rcar_du_group *rgrp = &rcdu->groups[i];
mutex_init(&rgrp->lock);
rgrp->dev = rcdu;
rgrp->mmio_offset = mmio_offsets[i];
rgrp->index = i;
rgrp->num_crtcs = min(rcdu->num_crtcs - 2 * i, 2U);
rgrp->dptsr_planes = rgrp->num_crtcs > 1
? (rcdu->info->gen >= 3 ? 0x04 : 0xf0)
: 0;
if (!rcar_du_has(rcdu, RCAR_DU_FEATURE_VSP1_SOURCE)) {
ret = rcar_du_planes_init(rgrp);
if (ret < 0)
return ret;
}
}
if (rcar_du_has(rcdu, RCAR_DU_FEATURE_VSP1_SOURCE)) {
ret = rcar_du_vsps_init(rcdu);
if (ret < 0)
return ret;
}
for (i = 0; i < rcdu->num_crtcs; ++i) {
struct rcar_du_group *rgrp = &rcdu->groups[i / 2];
ret = rcar_du_crtc_create(rgrp, i);
if (ret < 0)
return ret;
}
ret = rcar_du_lvdsenc_init(rcdu);
if (ret < 0)
return ret;
ret = rcar_du_encoders_init(rcdu);
if (ret < 0)
return ret;
if (ret == 0) {
dev_err(rcdu->dev, "error: no encoder could be initialized\n");
return -EINVAL;
}
num_encoders = ret;
list_for_each_entry(encoder, &dev->mode_config.encoder_list, head) {
struct rcar_du_encoder *renc = to_rcar_encoder(encoder);
const struct rcar_du_output_routing *route =
&rcdu->info->routes[renc->output];
encoder->possible_crtcs = route->possible_crtcs;
encoder->possible_clones = (1 << num_encoders) - 1;
}
drm_mode_config_reset(dev);
drm_kms_helper_poll_init(dev);
if (dev->mode_config.num_connector) {
fbdev = drm_fbdev_cma_init(dev, 32,
dev->mode_config.num_connector);
if (IS_ERR(fbdev))
return PTR_ERR(fbdev);
rcdu->fbdev = fbdev;
} else {
dev_info(rcdu->dev,
"no connector found, disabling fbdev emulation\n");
}
return 0;
}
