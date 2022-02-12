static void vvp_lock_fini(const struct lu_env *env, struct cl_lock_slice *slice)
{
struct vvp_lock *vlk = cl2vvp_lock(slice);
kmem_cache_free(vvp_lock_kmem, vlk);
}
static int vvp_lock_enqueue(const struct lu_env *env,
const struct cl_lock_slice *slice,
struct cl_io *unused, struct cl_sync_io *anchor)
{
CLOBINVRNT(env, slice->cls_obj, vvp_object_invariant(slice->cls_obj));
return 0;
}
int vvp_lock_init(const struct lu_env *env, struct cl_object *obj,
struct cl_lock *lock, const struct cl_io *unused)
{
struct vvp_lock *vlk;
int result;
CLOBINVRNT(env, obj, vvp_object_invariant(obj));
vlk = kmem_cache_zalloc(vvp_lock_kmem, GFP_NOFS);
if (vlk) {
cl_lock_slice_add(lock, &vlk->vlk_cl, obj, &vvp_lock_ops);
result = 0;
} else {
result = -ENOMEM;
}
return result;
}
