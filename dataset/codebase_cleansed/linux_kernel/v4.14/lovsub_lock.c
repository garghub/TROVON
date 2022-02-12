static void lovsub_lock_fini(const struct lu_env *env,
struct cl_lock_slice *slice)
{
struct lovsub_lock *lsl;
lsl = cl2lovsub_lock(slice);
kmem_cache_free(lovsub_lock_kmem, lsl);
}
int lovsub_lock_init(const struct lu_env *env, struct cl_object *obj,
struct cl_lock *lock, const struct cl_io *io)
{
struct lovsub_lock *lsk;
int result;
lsk = kmem_cache_zalloc(lovsub_lock_kmem, GFP_NOFS);
if (lsk) {
cl_lock_slice_add(lock, &lsk->lss_cl, obj, &lovsub_lock_ops);
result = 0;
} else {
result = -ENOMEM;
}
return result;
}
