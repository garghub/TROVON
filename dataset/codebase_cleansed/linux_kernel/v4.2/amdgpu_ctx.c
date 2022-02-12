static void amdgpu_ctx_do_release(struct kref *ref)
{
struct amdgpu_ctx *ctx;
struct amdgpu_ctx_mgr *mgr;
ctx = container_of(ref, struct amdgpu_ctx, refcount);
mgr = &ctx->fpriv->ctx_mgr;
idr_remove(&mgr->ctx_handles, ctx->id);
kfree(ctx);
}
int amdgpu_ctx_alloc(struct amdgpu_device *adev, struct amdgpu_fpriv *fpriv, uint32_t *id, uint32_t flags)
{
int r;
struct amdgpu_ctx *ctx;
struct amdgpu_ctx_mgr *mgr = &fpriv->ctx_mgr;
ctx = kmalloc(sizeof(*ctx), GFP_KERNEL);
if (!ctx)
return -ENOMEM;
mutex_lock(&mgr->lock);
r = idr_alloc(&mgr->ctx_handles, ctx, 0, 0, GFP_KERNEL);
if (r < 0) {
mutex_unlock(&mgr->lock);
kfree(ctx);
return r;
}
*id = (uint32_t)r;
memset(ctx, 0, sizeof(*ctx));
ctx->id = *id;
ctx->fpriv = fpriv;
kref_init(&ctx->refcount);
mutex_unlock(&mgr->lock);
return 0;
}
int amdgpu_ctx_free(struct amdgpu_device *adev, struct amdgpu_fpriv *fpriv, uint32_t id)
{
struct amdgpu_ctx *ctx;
struct amdgpu_ctx_mgr *mgr = &fpriv->ctx_mgr;
mutex_lock(&mgr->lock);
ctx = idr_find(&mgr->ctx_handles, id);
if (ctx) {
kref_put(&ctx->refcount, amdgpu_ctx_do_release);
mutex_unlock(&mgr->lock);
return 0;
}
mutex_unlock(&mgr->lock);
return -EINVAL;
}
static int amdgpu_ctx_query(struct amdgpu_device *adev,
struct amdgpu_fpriv *fpriv, uint32_t id,
union drm_amdgpu_ctx_out *out)
{
struct amdgpu_ctx *ctx;
struct amdgpu_ctx_mgr *mgr = &fpriv->ctx_mgr;
unsigned reset_counter;
mutex_lock(&mgr->lock);
ctx = idr_find(&mgr->ctx_handles, id);
if (!ctx) {
mutex_unlock(&mgr->lock);
return -EINVAL;
}
out->state.flags = ctx->state.flags;
out->state.hangs = ctx->state.hangs;
reset_counter = atomic_read(&adev->gpu_reset_counter);
if (ctx->reset_counter == reset_counter)
out->state.reset_status = AMDGPU_CTX_NO_RESET;
else
out->state.reset_status = AMDGPU_CTX_UNKNOWN_RESET;
ctx->reset_counter = reset_counter;
mutex_unlock(&mgr->lock);
return 0;
}
void amdgpu_ctx_fini(struct amdgpu_fpriv *fpriv)
{
struct idr *idp;
struct amdgpu_ctx *ctx;
uint32_t id;
struct amdgpu_ctx_mgr *mgr = &fpriv->ctx_mgr;
idp = &mgr->ctx_handles;
idr_for_each_entry(idp,ctx,id) {
if (kref_put(&ctx->refcount, amdgpu_ctx_do_release) != 1)
DRM_ERROR("ctx (id=%ul) is still alive\n",ctx->id);
}
mutex_destroy(&mgr->lock);
}
int amdgpu_ctx_ioctl(struct drm_device *dev, void *data,
struct drm_file *filp)
{
int r;
uint32_t id;
uint32_t flags;
union drm_amdgpu_ctx *args = data;
struct amdgpu_device *adev = dev->dev_private;
struct amdgpu_fpriv *fpriv = filp->driver_priv;
r = 0;
id = args->in.ctx_id;
flags = args->in.flags;
switch (args->in.op) {
case AMDGPU_CTX_OP_ALLOC_CTX:
r = amdgpu_ctx_alloc(adev, fpriv, &id, flags);
args->out.alloc.ctx_id = id;
break;
case AMDGPU_CTX_OP_FREE_CTX:
r = amdgpu_ctx_free(adev, fpriv, id);
break;
case AMDGPU_CTX_OP_QUERY_STATE:
r = amdgpu_ctx_query(adev, fpriv, id, &args->out);
break;
default:
return -EINVAL;
}
return r;
}
struct amdgpu_ctx *amdgpu_ctx_get(struct amdgpu_fpriv *fpriv, uint32_t id)
{
struct amdgpu_ctx *ctx;
struct amdgpu_ctx_mgr *mgr = &fpriv->ctx_mgr;
mutex_lock(&mgr->lock);
ctx = idr_find(&mgr->ctx_handles, id);
if (ctx)
kref_get(&ctx->refcount);
mutex_unlock(&mgr->lock);
return ctx;
}
int amdgpu_ctx_put(struct amdgpu_ctx *ctx)
{
struct amdgpu_fpriv *fpriv;
struct amdgpu_ctx_mgr *mgr;
if (ctx == NULL)
return -EINVAL;
fpriv = ctx->fpriv;
mgr = &fpriv->ctx_mgr;
mutex_lock(&mgr->lock);
kref_put(&ctx->refcount, amdgpu_ctx_do_release);
mutex_unlock(&mgr->lock);
return 0;
}
