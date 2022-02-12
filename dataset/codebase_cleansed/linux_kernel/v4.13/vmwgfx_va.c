static struct vmw_stream *
vmw_stream(struct vmw_resource *res)
{
return container_of(res, struct vmw_stream, sres.res);
}
static void vmw_stream_hw_destroy(struct vmw_resource *res)
{
struct vmw_private *dev_priv = res->dev_priv;
struct vmw_stream *stream = vmw_stream(res);
int ret;
ret = vmw_overlay_unref(dev_priv, stream->stream_id);
WARN_ON_ONCE(ret != 0);
}
static int vmw_stream_init(struct vmw_resource *res, void *data)
{
struct vmw_stream *stream = vmw_stream(res);
return vmw_overlay_claim(res->dev_priv, &stream->stream_id);
}
static void vmw_stream_set_arg_handle(void *data, u32 handle)
{
struct drm_vmw_stream_arg *arg = (struct drm_vmw_stream_arg *)data;
arg->stream_id = handle;
}
int vmw_stream_unref_ioctl(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct drm_vmw_stream_arg *arg = (struct drm_vmw_stream_arg *)data;
return ttm_ref_object_base_unref(vmw_fpriv(file_priv)->tfile,
arg->stream_id, TTM_REF_USAGE);
}
int vmw_stream_claim_ioctl(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
return vmw_simple_resource_create_ioctl(dev, data, file_priv,
&va_stream_func);
}
int vmw_user_stream_lookup(struct vmw_private *dev_priv,
struct ttm_object_file *tfile,
uint32_t *inout_id, struct vmw_resource **out)
{
struct vmw_stream *stream;
struct vmw_resource *res =
vmw_simple_resource_lookup(tfile, *inout_id, &va_stream_func);
if (IS_ERR(res))
return PTR_ERR(res);
stream = vmw_stream(res);
*inout_id = stream->stream_id;
*out = res;
return 0;
}
