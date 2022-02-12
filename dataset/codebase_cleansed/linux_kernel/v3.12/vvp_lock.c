static unsigned long vvp_lock_weigh(const struct lu_env *env,
const struct cl_lock_slice *slice)
{
struct ccc_object *cob = cl2ccc(slice->cls_obj);
return atomic_read(&cob->cob_mmap_cnt) > 0 ? ~0UL >> 2 : 0;
}
int vvp_lock_init(const struct lu_env *env, struct cl_object *obj,
struct cl_lock *lock, const struct cl_io *io)
{
return ccc_lock_init(env, obj, lock, io, &vvp_lock_ops);
}
