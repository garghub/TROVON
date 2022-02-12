static int nfp_cpp_resource_find(struct nfp_cpp *cpp, struct nfp_resource *res)
{
char name_pad[NFP_RESOURCE_ENTRY_NAME_SZ] = {};
struct nfp_resource_entry entry;
u32 cpp_id, key;
int ret, i;
cpp_id = NFP_CPP_ID(NFP_RESOURCE_TBL_TARGET, 3, 0);
strncpy(name_pad, res->name, sizeof(name_pad));
key = NFP_RESOURCE_TBL_KEY;
if (memcmp(name_pad, NFP_RESOURCE_TBL_NAME "\0\0\0\0\0\0\0\0", 8))
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
unsigned long warn_at = jiffies + 15 * HZ;
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
warn_at = jiffies + 60 * HZ;
nfp_warn(cpp, "Warning: waiting for NFP resource %s\n",
name);
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
