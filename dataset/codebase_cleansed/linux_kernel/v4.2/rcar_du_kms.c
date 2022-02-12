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
struct drm_mode_fb_cmd2 *mode_cmd)
{
struct rcar_du_device *rcdu = dev->dev_private;
const struct rcar_du_format_info *format;
unsigned int max_pitch;
unsigned int align;
unsigned int bpp;
format = rcar_du_format_info(mode_cmd->pixel_format);
if (format == NULL) {
dev_dbg(dev->dev, "unsupported pixel format %08x\n",
mode_cmd->pixel_format);
return ERR_PTR(-EINVAL);
}
bpp = format->planes == 2 ? 1 : format->bpp / 8;
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
if (format->planes == 2) {
if (mode_cmd->pitches[1] != mode_cmd->pitches[0]) {
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
static bool rcar_du_plane_needs_realloc(struct rcar_du_plane *plane,
struct rcar_du_plane_state *state)
{
const struct rcar_du_format_info *cur_format;
cur_format = to_rcar_plane_state(plane->plane.state)->format;
return !cur_format || cur_format->planes != state->format->planes;
}
static unsigned int rcar_du_plane_hwmask(struct rcar_du_plane_state *state)
{
unsigned int mask;
if (state->hwindex == -1)
return 0;
mask = 1 << state->hwindex;
if (state->format->planes == 2)
mask |= 1 << ((state->hwindex + 1) % 8);
return mask;
}
static int rcar_du_plane_hwalloc(unsigned int num_planes, unsigned int free)
{
unsigned int i;
for (i = 0; i < RCAR_DU_NUM_HW_PLANES; ++i) {
if (!(free & (1 << i)))
continue;
if (num_planes == 1 || free & (1 << ((i + 1) % 8)))
break;
}
return i == RCAR_DU_NUM_HW_PLANES ? -EBUSY : i;
}
static int rcar_du_atomic_check(struct drm_device *dev,
struct drm_atomic_state *state)
{
struct rcar_du_device *rcdu = dev->dev_private;
unsigned int group_freed_planes[RCAR_DU_MAX_GROUPS] = { 0, };
unsigned int group_free_planes[RCAR_DU_MAX_GROUPS] = { 0, };
bool needs_realloc = false;
unsigned int groups = 0;
unsigned int i;
int ret;
ret = drm_atomic_helper_check(dev, state);
if (ret < 0)
return ret;
for (i = 0; i < dev->mode_config.num_total_plane; ++i) {
struct rcar_du_plane_state *plane_state;
struct rcar_du_plane *plane;
unsigned int index;
if (!state->planes[i])
continue;
plane = to_rcar_plane(state->planes[i]);
plane_state = to_rcar_plane_state(state->plane_states[i]);
dev_dbg(rcdu->dev, "%s: checking plane (%u,%u)\n", __func__,
plane->group->index, plane - plane->group->planes);
if (!plane_state->format) {
dev_dbg(rcdu->dev, "%s: plane is being disabled\n",
__func__);
index = plane - plane->group->planes;
group_freed_planes[plane->group->index] |= 1 << index;
plane_state->hwindex = -1;
continue;
}
if (rcar_du_plane_needs_realloc(plane, plane_state)) {
dev_dbg(rcdu->dev, "%s: plane needs reallocation\n",
__func__);
groups |= 1 << plane->group->index;
needs_realloc = true;
index = plane - plane->group->planes;
group_freed_planes[plane->group->index] |= 1 << index;
plane_state->hwindex = -1;
}
}
if (!needs_realloc)
return 0;
while (groups) {
unsigned int index = ffs(groups) - 1;
struct rcar_du_group *group = &rcdu->groups[index];
unsigned int used_planes = 0;
dev_dbg(rcdu->dev, "%s: finding free planes for group %u\n",
__func__, index);
for (i = 0; i < group->num_planes; ++i) {
struct rcar_du_plane *plane = &group->planes[i];
struct rcar_du_plane_state *plane_state;
struct drm_plane_state *s;
s = drm_atomic_get_plane_state(state, &plane->plane);
if (IS_ERR(s))
return PTR_ERR(s);
if (group_freed_planes[index] & (1 << i)) {
dev_dbg(rcdu->dev,
"%s: plane (%u,%u) has been freed, skipping\n",
__func__, plane->group->index,
plane - plane->group->planes);
continue;
}
plane_state = to_rcar_plane_state(plane->plane.state);
used_planes |= rcar_du_plane_hwmask(plane_state);
dev_dbg(rcdu->dev,
"%s: plane (%u,%u) uses %u hwplanes (index %d)\n",
__func__, plane->group->index,
plane - plane->group->planes,
plane_state->format ?
plane_state->format->planes : 0,
plane_state->hwindex);
}
group_free_planes[index] = 0xff & ~used_planes;
groups &= ~(1 << index);
dev_dbg(rcdu->dev, "%s: group %u free planes mask 0x%02x\n",
__func__, index, group_free_planes[index]);
}
for (i = 0; i < dev->mode_config.num_total_plane; ++i) {
struct rcar_du_plane_state *plane_state;
struct rcar_du_plane *plane;
unsigned int crtc_planes;
unsigned int free;
int idx;
if (!state->planes[i])
continue;
plane = to_rcar_plane(state->planes[i]);
plane_state = to_rcar_plane_state(state->plane_states[i]);
dev_dbg(rcdu->dev, "%s: allocating plane (%u,%u)\n", __func__,
plane->group->index, plane - plane->group->planes);
if (!plane_state->format ||
!rcar_du_plane_needs_realloc(plane, plane_state))
continue;
crtc_planes = to_rcar_crtc(plane_state->state.crtc)->index % 2
? plane->group->dptsr_planes
: ~plane->group->dptsr_planes;
free = group_free_planes[plane->group->index];
idx = rcar_du_plane_hwalloc(plane_state->format->planes,
free & crtc_planes);
if (idx < 0)
idx = rcar_du_plane_hwalloc(plane_state->format->planes,
free);
if (idx < 0) {
dev_dbg(rcdu->dev, "%s: no available hardware plane\n",
__func__);
return idx;
}
dev_dbg(rcdu->dev, "%s: allocated %u hwplanes (index %u)\n",
__func__, plane_state->format->planes, idx);
plane_state->hwindex = idx;
group_free_planes[plane->group->index] &=
~rcar_du_plane_hwmask(plane_state);
dev_dbg(rcdu->dev, "%s: group %u free planes mask 0x%02x\n",
__func__, plane->group->index,
group_free_planes[plane->group->index]);
}
return 0;
}
static void rcar_du_atomic_complete(struct rcar_du_commit *commit)
{
struct drm_device *dev = commit->dev;
struct rcar_du_device *rcdu = dev->dev_private;
struct drm_atomic_state *old_state = commit->state;
drm_atomic_helper_commit_modeset_disables(dev, old_state);
drm_atomic_helper_commit_modeset_enables(dev, old_state);
drm_atomic_helper_commit_planes(dev, old_state);
drm_atomic_helper_wait_for_vblanks(dev, old_state);
drm_atomic_helper_cleanup_planes(dev, old_state);
drm_atomic_state_free(old_state);
spin_lock(&rcdu->commit.wait.lock);
rcdu->commit.pending &= ~commit->crtcs;
wake_up_all_locked(&rcdu->commit.wait);
spin_unlock(&rcdu->commit.wait.lock);
kfree(commit);
}
static void rcar_du_atomic_work(struct work_struct *work)
{
struct rcar_du_commit *commit =
container_of(work, struct rcar_du_commit, work);
rcar_du_atomic_complete(commit);
}
static int rcar_du_atomic_commit(struct drm_device *dev,
struct drm_atomic_state *state, bool async)
{
struct rcar_du_device *rcdu = dev->dev_private;
struct rcar_du_commit *commit;
unsigned int i;
int ret;
ret = drm_atomic_helper_prepare_planes(dev, state);
if (ret)
return ret;
commit = kzalloc(sizeof(*commit), GFP_KERNEL);
if (commit == NULL) {
ret = -ENOMEM;
goto error;
}
INIT_WORK(&commit->work, rcar_du_atomic_work);
commit->dev = dev;
commit->state = state;
for (i = 0; i < dev->mode_config.num_crtc; ++i) {
if (state->crtcs[i])
commit->crtcs |= 1 << drm_crtc_index(state->crtcs[i]);
}
spin_lock(&rcdu->commit.wait.lock);
ret = wait_event_interruptible_locked(rcdu->commit.wait,
!(rcdu->commit.pending & commit->crtcs));
if (ret == 0)
rcdu->commit.pending |= commit->crtcs;
spin_unlock(&rcdu->commit.wait.lock);
if (ret) {
kfree(commit);
goto error;
}
drm_atomic_helper_swap_state(dev, state);
if (async)
schedule_work(&commit->work);
else
rcar_du_atomic_complete(commit);
return 0;
error:
drm_atomic_helper_cleanup_planes(dev, state);
return ret;
}
static int rcar_du_encoders_init_one(struct rcar_du_device *rcdu,
enum rcar_du_output output,
struct of_endpoint *ep)
{
static const struct {
const char *compatible;
enum rcar_du_encoder_type type;
} encoders[] = {
{ "adi,adv7123", RCAR_DU_ENCODER_VGA },
{ "adi,adv7511w", RCAR_DU_ENCODER_HDMI },
{ "thine,thc63lvdm83d", RCAR_DU_ENCODER_LVDS },
};
enum rcar_du_encoder_type enc_type = RCAR_DU_ENCODER_NONE;
struct device_node *connector = NULL;
struct device_node *encoder = NULL;
struct device_node *ep_node = NULL;
struct device_node *entity_ep_node;
struct device_node *entity;
int ret;
entity = of_graph_get_remote_port_parent(ep->local_node);
if (!entity) {
dev_dbg(rcdu->dev, "unconnected endpoint %s, skipping\n",
ep->local_node->full_name);
return -ENODEV;
}
entity_ep_node = of_parse_phandle(ep->local_node, "remote-endpoint", 0);
for_each_endpoint_of_node(entity, ep_node) {
if (ep_node == entity_ep_node)
continue;
encoder = entity;
connector = of_graph_get_remote_port_parent(ep_node);
of_node_put(ep_node);
if (!connector) {
dev_warn(rcdu->dev,
"no connector for encoder %s, skipping\n",
encoder->full_name);
of_node_put(entity_ep_node);
of_node_put(encoder);
return -ENODEV;
}
break;
}
of_node_put(entity_ep_node);
if (encoder) {
unsigned int i;
for (i = 0; i < ARRAY_SIZE(encoders); ++i) {
if (of_device_is_compatible(encoder,
encoders[i].compatible)) {
enc_type = encoders[i].type;
break;
}
}
if (i == ARRAY_SIZE(encoders)) {
dev_warn(rcdu->dev,
"unknown encoder type for %s, skipping\n",
encoder->full_name);
of_node_put(encoder);
of_node_put(connector);
return -EINVAL;
}
} else {
connector = entity;
}
ret = rcar_du_encoder_init(rcdu, enc_type, output, encoder, connector);
of_node_put(encoder);
of_node_put(connector);
if (ret && ret != -EPROBE_DEFER)
dev_warn(rcdu->dev,
"failed to initialize encoder %s (%d), skipping\n",
encoder->full_name, ret);
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
rcdu->props.zpos =
drm_property_create_range(rcdu->ddev, 0, "zpos", 1, 7);
if (rcdu->props.zpos == NULL)
return -ENOMEM;
return 0;
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
rcdu->num_crtcs = rcdu->info->num_crtcs;
ret = rcar_du_properties_init(rcdu);
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
rgrp->dptsr_planes = rgrp->num_crtcs > 1 ? 0xf0 : 0;
ret = rcar_du_planes_init(rgrp);
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
fbdev = drm_fbdev_cma_init(dev, 32, dev->mode_config.num_crtc,
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
