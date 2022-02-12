static void virtio_gpu_plane_destroy(struct drm_plane *plane)
{
kfree(plane);
}
static int virtio_gpu_plane_atomic_check(struct drm_plane *plane,
struct drm_plane_state *state)
{
return 0;
}
static void virtio_gpu_plane_atomic_update(struct drm_plane *plane,
struct drm_plane_state *old_state)
{
struct drm_device *dev = plane->dev;
struct virtio_gpu_device *vgdev = dev->dev_private;
struct virtio_gpu_output *output = drm_crtc_to_virtio_gpu_output(plane->crtc);
struct virtio_gpu_framebuffer *vgfb;
struct virtio_gpu_object *bo;
uint32_t handle;
if (plane->fb) {
vgfb = to_virtio_gpu_framebuffer(plane->fb);
bo = gem_to_virtio_gpu_obj(vgfb->obj);
handle = bo->hw_res_handle;
} else {
handle = 0;
}
DRM_DEBUG("handle 0x%x, crtc %dx%d+%d+%d\n", handle,
plane->state->crtc_w, plane->state->crtc_h,
plane->state->crtc_x, plane->state->crtc_y);
virtio_gpu_cmd_set_scanout(vgdev, output->index, handle,
plane->state->crtc_w,
plane->state->crtc_h,
plane->state->crtc_x,
plane->state->crtc_y);
}
struct drm_plane *virtio_gpu_plane_init(struct virtio_gpu_device *vgdev,
int index)
{
struct drm_device *dev = vgdev->ddev;
struct drm_plane *plane;
int ret;
plane = kzalloc(sizeof(*plane), GFP_KERNEL);
if (!plane)
return ERR_PTR(-ENOMEM);
ret = drm_universal_plane_init(dev, plane, 1 << index,
&virtio_gpu_plane_funcs,
virtio_gpu_formats,
ARRAY_SIZE(virtio_gpu_formats),
DRM_PLANE_TYPE_PRIMARY);
if (ret)
goto err_plane_init;
drm_plane_helper_add(plane, &virtio_gpu_plane_helper_funcs);
return plane;
err_plane_init:
kfree(plane);
return ERR_PTR(ret);
}
