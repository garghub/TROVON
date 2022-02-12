static int nfp_cpp_resource_find(struct nfp_cpp *cpp, struct nfp_resource *res)
{
char name_pad[NFP_RESOURCE_ENTRY_NAME_SZ] = {};
struct nfp_resource_entry entry;
u32 cpp_id, key;
int ret, i;
cpp_id = NFP_CPP_ID(NFP_RESOURCE_TBL_TARGET, 3, 0);
strncpy(name_pad, res->name, sizeof(name_pad));
if (!memcmp(name_pad, NFP_RESOURCE_TBL_NAME "\0\0\0\0\0\0\0\0", 8)) {
nfp_err(cpp, "Grabbing device lock not supported\n");
return -EOPNOTSUPP;
}
key = crc32_posix(name_pad, sizeof(name_pad));
for (i = 0; i < NFP_RESOURCE_TBL_ENTRIES; i++) {
u64 addr = NFP_RESOURCE_TBL_BASE +
sizeof(struct nfp_resource_entry) * i;
ret = nfp_cpp_read(cpp, cpp_id, addr, &entry, sizeof(entry));
if (ret != sizeof(entry))
return -EIO;
if (entry.mutex.key != key)
continue;
res->mutex =
nfp_cpp_mutex_alloc(cpp,
NFP_RESOURCE_TBL_TARGET, addr, key);
res->cpp_id = NFP_CPP_ID(entry.region.cpp_target,
entry.region.cpp_action,
entry.region.cpp_token);
res->addr = (u64)entry.region.page_offset << 8;
res->size = (u64)entry.region.page_size << 8;
return 0;
}
return -ENOENT;
}
static int
nfp_resource_try_acquire(struct nfp_cpp *cpp, struct nfp_resource *res,
struct nfp_cpp_mutex *dev_mutex)
{
int err;
if (nfp_cpp_mutex_lock(dev_mutex))
return -EINVAL;
err = nfp_cpp_resource_find(cpp, res);
if (err)
goto err_unlock_dev;
err = nfp_cpp_mutex_trylock(res->mutex);
if (err)
goto err_res_mutex_free;
nfp_cpp_mutex_unlock(dev_mutex);
return 0;
err_res_mutex_free:
nfp_cpp_mutex_free(res->mutex);
err_unlock_dev:
nfp_cpp_mutex_unlock(dev_mutex);
return err;
}
struct nfp_resource *
nfp_resource_acquire(struct nfp_cpp *cpp, const char *name)
{
unsigned long warn_at = jiffies + NFP_MUTEX_WAIT_FIRST_WARN * HZ;
unsigned long err_at = jiffies + NFP_MUTEX_WAIT_ERROR * HZ;
struct nfp_cpp_mutex *dev_mutex;
struct nfp_resource *res;
int err;
res = kzalloc(sizeof(*res), GFP_KERNEL);
if (!res)
return ERR_PTR(-ENOMEM);
strncpy(res->name, name, NFP_RESOURCE_ENTRY_NAME_SZ);
dev_mutex = nfp_cpp_mutex_alloc(cpp, NFP_RESOURCE_TBL_TARGET,
NFP_RESOURCE_TBL_BASE,
NFP_RESOURCE_TBL_KEY);
if (!dev_mutex) {
kfree(res);
return ERR_PTR(-ENOMEM);
}
for (;;) {
err = nfp_resource_try_acquire(cpp, res, dev_mutex);
if (!err)
break;
if (err != -EBUSY)
goto err_free;
err = msleep_interruptible(1);
if (err != 0) {
err = -ERESTARTSYS;
goto err_free;
}
if (time_is_before_eq_jiffies(warn_at)) {
warn_at = jiffies + NFP_MUTEX_WAIT_NEXT_WARN * HZ;
nfp_warn(cpp, "Warning: waiting for NFP resource %s\n",
name);
}
if (time_is_before_eq_jiffies(err_at)) {
nfp_err(cpp, "Error: resource %s timed out\n", name);
err = -EBUSY;
goto err_free;
}
}
nfp_cpp_mutex_free(dev_mutex);
return res;
err_free:
nfp_cpp_mutex_free(dev_mutex);
kfree(res);
return ERR_PTR(err);
}
void nfp_resource_release(struct nfp_resource *res)
{
nfp_cpp_mutex_unlock(res->mutex);
nfp_cpp_mutex_free(res->mutex);
kfree(res);
}
int nfp_resource_wait(struct nfp_cpp *cpp, const char *name, unsigned int secs)
{
unsigned long warn_at = jiffies + NFP_MUTEX_WAIT_FIRST_WARN * HZ;
unsigned long err_at = jiffies + secs * HZ;
struct nfp_resource *res;
while (true) {
res = nfp_resource_acquire(cpp, name);
if (!IS_ERR(res)) {
nfp_resource_release(res);
return 0;
}
if (PTR_ERR(res) != -ENOENT) {
nfp_err(cpp, "error waiting for resource %s: %ld\n",
name, PTR_ERR(res));
return PTR_ERR(res);
}
if (time_is_before_eq_jiffies(err_at)) {
nfp_err(cpp, "timeout waiting for resource %s\n", name);
return -ETIMEDOUT;
}
if (time_is_before_eq_jiffies(warn_at)) {
warn_at = jiffies + NFP_MUTEX_WAIT_NEXT_WARN * HZ;
nfp_info(cpp, "waiting for NFP resource %s\n", name);
}
if (msleep_interruptible(10)) {
nfp_err(cpp, "wait for resource %s interrupted\n",
name);
return -ERESTARTSYS;
}
}
}
u32 nfp_resource_cpp_id(struct nfp_resource *res)
{
return res->cpp_id;
}
const char *nfp_resource_name(struct nfp_resource *res)
{
return res->name;
}
u64 nfp_resource_address(struct nfp_resource *res)
{
return res->addr;
}
u64 nfp_resource_size(struct nfp_resource *res)
{
return res->size;
}
