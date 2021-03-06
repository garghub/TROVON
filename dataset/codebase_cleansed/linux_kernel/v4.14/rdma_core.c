int uverbs_ns_idx(u16 *id, unsigned int ns_count)
{
int ret = (*id & UVERBS_ID_NS_MASK) >> UVERBS_ID_NS_SHIFT;
if (ret >= ns_count)
return -EINVAL;
*id &= ~UVERBS_ID_NS_MASK;
return ret;
}
const struct uverbs_object_spec *uverbs_get_object(const struct ib_device *ibdev,
uint16_t object)
{
const struct uverbs_root_spec *object_hash = ibdev->specs_root;
const struct uverbs_object_spec_hash *objects;
int ret = uverbs_ns_idx(&object, object_hash->num_buckets);
if (ret < 0)
return NULL;
objects = object_hash->object_buckets[ret];
if (object >= objects->num_objects)
return NULL;
return objects->objects[object];
}
const struct uverbs_method_spec *uverbs_get_method(const struct uverbs_object_spec *object,
uint16_t method)
{
const struct uverbs_method_spec_hash *methods;
int ret = uverbs_ns_idx(&method, object->num_buckets);
if (ret < 0)
return NULL;
methods = object->method_buckets[ret];
if (method >= methods->num_methods)
return NULL;
return methods->methods[method];
}
void uverbs_uobject_get(struct ib_uobject *uobject)
{
kref_get(&uobject->ref);
}
static void uverbs_uobject_free(struct kref *ref)
{
struct ib_uobject *uobj =
container_of(ref, struct ib_uobject, ref);
if (uobj->type->type_class->needs_kfree_rcu)
kfree_rcu(uobj, rcu);
else
kfree(uobj);
}
void uverbs_uobject_put(struct ib_uobject *uobject)
{
kref_put(&uobject->ref, uverbs_uobject_free);
}
static int uverbs_try_lock_object(struct ib_uobject *uobj, bool exclusive)
{
if (!exclusive)
return __atomic_add_unless(&uobj->usecnt, 1, -1) == -1 ?
-EBUSY : 0;
return atomic_cmpxchg(&uobj->usecnt, 0, -1) == 0 ? 0 : -EBUSY;
}
static struct ib_uobject *alloc_uobj(struct ib_ucontext *context,
const struct uverbs_obj_type *type)
{
struct ib_uobject *uobj = kzalloc(type->obj_size, GFP_KERNEL);
if (!uobj)
return ERR_PTR(-ENOMEM);
uobj->context = context;
uobj->type = type;
atomic_set(&uobj->usecnt, 0);
kref_init(&uobj->ref);
return uobj;
}
static int idr_add_uobj(struct ib_uobject *uobj)
{
int ret;
idr_preload(GFP_KERNEL);
spin_lock(&uobj->context->ufile->idr_lock);
ret = idr_alloc(&uobj->context->ufile->idr, NULL, 0,
min_t(unsigned long, U32_MAX - 1, INT_MAX), GFP_NOWAIT);
if (ret >= 0)
uobj->id = ret;
spin_unlock(&uobj->context->ufile->idr_lock);
idr_preload_end();
return ret < 0 ? ret : 0;
}
static void uverbs_idr_remove_uobj(struct ib_uobject *uobj)
{
spin_lock(&uobj->context->ufile->idr_lock);
idr_remove(&uobj->context->ufile->idr, uobj->id);
spin_unlock(&uobj->context->ufile->idr_lock);
}
static struct ib_uobject *lookup_get_idr_uobject(const struct uverbs_obj_type *type,
struct ib_ucontext *ucontext,
int id, bool exclusive)
{
struct ib_uobject *uobj;
rcu_read_lock();
uobj = idr_find(&ucontext->ufile->idr, id);
if (!uobj) {
uobj = ERR_PTR(-ENOENT);
goto free;
}
uverbs_uobject_get(uobj);
free:
rcu_read_unlock();
return uobj;
}
static struct ib_uobject *lookup_get_fd_uobject(const struct uverbs_obj_type *type,
struct ib_ucontext *ucontext,
int id, bool exclusive)
{
struct file *f;
struct ib_uobject *uobject;
const struct uverbs_obj_fd_type *fd_type =
container_of(type, struct uverbs_obj_fd_type, type);
if (exclusive)
return ERR_PTR(-EOPNOTSUPP);
f = fget(id);
if (!f)
return ERR_PTR(-EBADF);
uobject = f->private_data;
if (f->f_op != fd_type->fops) {
fput(f);
return ERR_PTR(-EBADF);
}
uverbs_uobject_get(uobject);
return uobject;
}
struct ib_uobject *rdma_lookup_get_uobject(const struct uverbs_obj_type *type,
struct ib_ucontext *ucontext,
int id, bool exclusive)
{
struct ib_uobject *uobj;
int ret;
uobj = type->type_class->lookup_get(type, ucontext, id, exclusive);
if (IS_ERR(uobj))
return uobj;
if (uobj->type != type) {
ret = -EINVAL;
goto free;
}
ret = uverbs_try_lock_object(uobj, exclusive);
if (ret) {
WARN(ucontext->cleanup_reason,
"ib_uverbs: Trying to lookup_get while cleanup context\n");
goto free;
}
return uobj;
free:
uobj->type->type_class->lookup_put(uobj, exclusive);
uverbs_uobject_put(uobj);
return ERR_PTR(ret);
}
static struct ib_uobject *alloc_begin_idr_uobject(const struct uverbs_obj_type *type,
struct ib_ucontext *ucontext)
{
int ret;
struct ib_uobject *uobj;
uobj = alloc_uobj(ucontext, type);
if (IS_ERR(uobj))
return uobj;
ret = idr_add_uobj(uobj);
if (ret)
goto uobj_put;
ret = ib_rdmacg_try_charge(&uobj->cg_obj, ucontext->device,
RDMACG_RESOURCE_HCA_OBJECT);
if (ret)
goto idr_remove;
return uobj;
idr_remove:
uverbs_idr_remove_uobj(uobj);
uobj_put:
uverbs_uobject_put(uobj);
return ERR_PTR(ret);
}
static struct ib_uobject *alloc_begin_fd_uobject(const struct uverbs_obj_type *type,
struct ib_ucontext *ucontext)
{
const struct uverbs_obj_fd_type *fd_type =
container_of(type, struct uverbs_obj_fd_type, type);
int new_fd;
struct ib_uobject *uobj;
struct ib_uobject_file *uobj_file;
struct file *filp;
new_fd = get_unused_fd_flags(O_CLOEXEC);
if (new_fd < 0)
return ERR_PTR(new_fd);
uobj = alloc_uobj(ucontext, type);
if (IS_ERR(uobj)) {
put_unused_fd(new_fd);
return uobj;
}
uobj_file = container_of(uobj, struct ib_uobject_file, uobj);
filp = anon_inode_getfile(fd_type->name,
fd_type->fops,
uobj_file,
fd_type->flags);
if (IS_ERR(filp)) {
put_unused_fd(new_fd);
uverbs_uobject_put(uobj);
return (void *)filp;
}
uobj_file->uobj.id = new_fd;
uobj_file->uobj.object = filp;
uobj_file->ufile = ucontext->ufile;
INIT_LIST_HEAD(&uobj->list);
kref_get(&uobj_file->ufile->ref);
return uobj;
}
struct ib_uobject *rdma_alloc_begin_uobject(const struct uverbs_obj_type *type,
struct ib_ucontext *ucontext)
{
return type->type_class->alloc_begin(type, ucontext);
}
static void uverbs_uobject_add(struct ib_uobject *uobject)
{
mutex_lock(&uobject->context->uobjects_lock);
list_add(&uobject->list, &uobject->context->uobjects);
mutex_unlock(&uobject->context->uobjects_lock);
}
static int __must_check remove_commit_idr_uobject(struct ib_uobject *uobj,
enum rdma_remove_reason why)
{
const struct uverbs_obj_idr_type *idr_type =
container_of(uobj->type, struct uverbs_obj_idr_type,
type);
int ret = idr_type->destroy_object(uobj, why);
if (why == RDMA_REMOVE_DESTROY && ret)
return ret;
ib_rdmacg_uncharge(&uobj->cg_obj, uobj->context->device,
RDMACG_RESOURCE_HCA_OBJECT);
uverbs_idr_remove_uobj(uobj);
return ret;
}
static void alloc_abort_fd_uobject(struct ib_uobject *uobj)
{
struct ib_uobject_file *uobj_file =
container_of(uobj, struct ib_uobject_file, uobj);
struct file *filp = uobj->object;
int id = uobj_file->uobj.id;
fput(filp);
put_unused_fd(id);
}
static int __must_check remove_commit_fd_uobject(struct ib_uobject *uobj,
enum rdma_remove_reason why)
{
const struct uverbs_obj_fd_type *fd_type =
container_of(uobj->type, struct uverbs_obj_fd_type, type);
struct ib_uobject_file *uobj_file =
container_of(uobj, struct ib_uobject_file, uobj);
int ret = fd_type->context_closed(uobj_file, why);
if (why == RDMA_REMOVE_DESTROY && ret)
return ret;
if (why == RDMA_REMOVE_DURING_CLEANUP) {
alloc_abort_fd_uobject(uobj);
return ret;
}
uobj_file->uobj.context = NULL;
return ret;
}
static void lockdep_check(struct ib_uobject *uobj, bool exclusive)
{
#ifdef CONFIG_LOCKDEP
if (exclusive)
WARN_ON(atomic_read(&uobj->usecnt) > 0);
else
WARN_ON(atomic_read(&uobj->usecnt) == -1);
#endif
}
static int __must_check _rdma_remove_commit_uobject(struct ib_uobject *uobj,
enum rdma_remove_reason why)
{
int ret;
struct ib_ucontext *ucontext = uobj->context;
ret = uobj->type->type_class->remove_commit(uobj, why);
if (ret && why == RDMA_REMOVE_DESTROY) {
atomic_set(&uobj->usecnt, 0);
uobj->type->type_class->lookup_put(uobj, true);
} else {
mutex_lock(&ucontext->uobjects_lock);
list_del(&uobj->list);
mutex_unlock(&ucontext->uobjects_lock);
uverbs_uobject_put(uobj);
}
return ret;
}
int __must_check rdma_remove_commit_uobject(struct ib_uobject *uobj)
{
int ret;
struct ib_ucontext *ucontext = uobj->context;
uverbs_uobject_put(uobj);
if (!down_read_trylock(&ucontext->cleanup_rwsem)) {
WARN(true, "ib_uverbs: Cleanup is running while removing an uobject\n");
return 0;
}
lockdep_check(uobj, true);
ret = _rdma_remove_commit_uobject(uobj, RDMA_REMOVE_DESTROY);
up_read(&ucontext->cleanup_rwsem);
return ret;
}
static int null_obj_type_class_remove_commit(struct ib_uobject *uobj,
enum rdma_remove_reason why)
{
return 0;
}
int rdma_explicit_destroy(struct ib_uobject *uobject)
{
int ret;
struct ib_ucontext *ucontext = uobject->context;
if (!down_read_trylock(&ucontext->cleanup_rwsem)) {
WARN(true, "ib_uverbs: Cleanup is running while removing an uobject\n");
return 0;
}
lockdep_check(uobject, true);
ret = uobject->type->type_class->remove_commit(uobject,
RDMA_REMOVE_DESTROY);
if (ret)
return ret;
uobject->type = &null_obj_type;
up_read(&ucontext->cleanup_rwsem);
return 0;
}
static void alloc_commit_idr_uobject(struct ib_uobject *uobj)
{
uverbs_uobject_add(uobj);
spin_lock(&uobj->context->ufile->idr_lock);
WARN_ON(idr_replace(&uobj->context->ufile->idr,
uobj, uobj->id));
spin_unlock(&uobj->context->ufile->idr_lock);
}
static void alloc_commit_fd_uobject(struct ib_uobject *uobj)
{
struct ib_uobject_file *uobj_file =
container_of(uobj, struct ib_uobject_file, uobj);
uverbs_uobject_add(&uobj_file->uobj);
fd_install(uobj_file->uobj.id, uobj->object);
uobj_file->uobj.id = 0;
uverbs_uobject_get(&uobj_file->uobj);
}
int rdma_alloc_commit_uobject(struct ib_uobject *uobj)
{
if (!down_read_trylock(&uobj->context->cleanup_rwsem)) {
int ret;
WARN(true, "ib_uverbs: Cleanup is running while allocating an uobject\n");
ret = uobj->type->type_class->remove_commit(uobj,
RDMA_REMOVE_DURING_CLEANUP);
if (ret)
pr_warn("ib_uverbs: cleanup of idr object %d failed\n",
uobj->id);
return ret;
}
uobj->type->type_class->alloc_commit(uobj);
up_read(&uobj->context->cleanup_rwsem);
return 0;
}
static void alloc_abort_idr_uobject(struct ib_uobject *uobj)
{
uverbs_idr_remove_uobj(uobj);
ib_rdmacg_uncharge(&uobj->cg_obj, uobj->context->device,
RDMACG_RESOURCE_HCA_OBJECT);
uverbs_uobject_put(uobj);
}
void rdma_alloc_abort_uobject(struct ib_uobject *uobj)
{
uobj->type->type_class->alloc_abort(uobj);
}
static void lookup_put_idr_uobject(struct ib_uobject *uobj, bool exclusive)
{
}
static void lookup_put_fd_uobject(struct ib_uobject *uobj, bool exclusive)
{
struct file *filp = uobj->object;
WARN_ON(exclusive);
fput(filp);
}
void rdma_lookup_put_uobject(struct ib_uobject *uobj, bool exclusive)
{
lockdep_check(uobj, exclusive);
uobj->type->type_class->lookup_put(uobj, exclusive);
if (!exclusive)
atomic_dec(&uobj->usecnt);
else
atomic_set(&uobj->usecnt, 0);
uverbs_uobject_put(uobj);
}
static void _uverbs_close_fd(struct ib_uobject_file *uobj_file)
{
struct ib_ucontext *ucontext;
struct ib_uverbs_file *ufile = uobj_file->ufile;
int ret;
mutex_lock(&uobj_file->ufile->cleanup_mutex);
if (!uobj_file->uobj.context ||
!down_read_trylock(&uobj_file->uobj.context->cleanup_rwsem))
goto unlock;
ucontext = uobj_file->uobj.context;
ret = _rdma_remove_commit_uobject(&uobj_file->uobj, RDMA_REMOVE_CLOSE);
up_read(&ucontext->cleanup_rwsem);
if (ret)
pr_warn("uverbs: unable to clean up uobject file in uverbs_close_fd.\n");
unlock:
mutex_unlock(&ufile->cleanup_mutex);
}
void uverbs_close_fd(struct file *f)
{
struct ib_uobject_file *uobj_file = f->private_data;
struct kref *uverbs_file_ref = &uobj_file->ufile->ref;
_uverbs_close_fd(uobj_file);
uverbs_uobject_put(&uobj_file->uobj);
kref_put(uverbs_file_ref, ib_uverbs_release_file);
}
void uverbs_cleanup_ucontext(struct ib_ucontext *ucontext, bool device_removed)
{
enum rdma_remove_reason reason = device_removed ?
RDMA_REMOVE_DRIVER_REMOVE : RDMA_REMOVE_CLOSE;
unsigned int cur_order = 0;
ucontext->cleanup_reason = reason;
down_write(&ucontext->cleanup_rwsem);
while (!list_empty(&ucontext->uobjects)) {
struct ib_uobject *obj, *next_obj;
unsigned int next_order = UINT_MAX;
mutex_lock(&ucontext->uobjects_lock);
list_for_each_entry_safe(obj, next_obj, &ucontext->uobjects,
list) {
if (obj->type->destroy_order == cur_order) {
int ret;
WARN_ON(uverbs_try_lock_object(obj, true));
ret = obj->type->type_class->remove_commit(obj,
reason);
list_del(&obj->list);
if (ret)
pr_warn("ib_uverbs: failed to remove uobject id %d order %u\n",
obj->id, cur_order);
uverbs_uobject_put(obj);
} else {
next_order = min(next_order,
obj->type->destroy_order);
}
}
mutex_unlock(&ucontext->uobjects_lock);
cur_order = next_order;
}
up_write(&ucontext->cleanup_rwsem);
}
void uverbs_initialize_ucontext(struct ib_ucontext *ucontext)
{
ucontext->cleanup_reason = 0;
mutex_init(&ucontext->uobjects_lock);
INIT_LIST_HEAD(&ucontext->uobjects);
init_rwsem(&ucontext->cleanup_rwsem);
}
struct ib_uobject *uverbs_get_uobject_from_context(const struct uverbs_obj_type *type_attrs,
struct ib_ucontext *ucontext,
enum uverbs_obj_access access,
int id)
{
switch (access) {
case UVERBS_ACCESS_READ:
return rdma_lookup_get_uobject(type_attrs, ucontext, id, false);
case UVERBS_ACCESS_DESTROY:
case UVERBS_ACCESS_WRITE:
return rdma_lookup_get_uobject(type_attrs, ucontext, id, true);
case UVERBS_ACCESS_NEW:
return rdma_alloc_begin_uobject(type_attrs, ucontext);
default:
WARN_ON(true);
return ERR_PTR(-EOPNOTSUPP);
}
}
int uverbs_finalize_object(struct ib_uobject *uobj,
enum uverbs_obj_access access,
bool commit)
{
int ret = 0;
switch (access) {
case UVERBS_ACCESS_READ:
rdma_lookup_put_uobject(uobj, false);
break;
case UVERBS_ACCESS_WRITE:
rdma_lookup_put_uobject(uobj, true);
break;
case UVERBS_ACCESS_DESTROY:
if (commit)
ret = rdma_remove_commit_uobject(uobj);
else
rdma_lookup_put_uobject(uobj, true);
break;
case UVERBS_ACCESS_NEW:
if (commit)
ret = rdma_alloc_commit_uobject(uobj);
else
rdma_alloc_abort_uobject(uobj);
break;
default:
WARN_ON(true);
ret = -EOPNOTSUPP;
}
return ret;
}
int uverbs_finalize_objects(struct uverbs_attr_bundle *attrs_bundle,
struct uverbs_attr_spec_hash * const *spec_hash,
size_t num,
bool commit)
{
unsigned int i;
int ret = 0;
for (i = 0; i < num; i++) {
struct uverbs_attr_bundle_hash *curr_bundle =
&attrs_bundle->hash[i];
const struct uverbs_attr_spec_hash *curr_spec_bucket =
spec_hash[i];
unsigned int j;
for (j = 0; j < curr_bundle->num_attrs; j++) {
struct uverbs_attr *attr;
const struct uverbs_attr_spec *spec;
if (!uverbs_attr_is_valid_in_hash(curr_bundle, j))
continue;
attr = &curr_bundle->attrs[j];
spec = &curr_spec_bucket->attrs[j];
if (spec->type == UVERBS_ATTR_TYPE_IDR ||
spec->type == UVERBS_ATTR_TYPE_FD) {
int current_ret;
current_ret = uverbs_finalize_object(attr->obj_attr.uobject,
spec->obj.access,
commit);
if (!ret)
ret = current_ret;
}
}
}
return ret;
}
