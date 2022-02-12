static u32 nfp_mutex_locked(u16 interface)
{
return (u32)interface << 16 | 0x000f;
}
static u32 nfp_mutex_unlocked(u16 interface)
{
return (u32)interface << 16 | 0x0000;
}
static bool nfp_mutex_is_locked(u32 val)
{
return (val & 0xffff) == 0x000f;
}
static bool nfp_mutex_is_unlocked(u32 val)
{
return (val & 0xffff) == 0000;
}
static int
nfp_cpp_mutex_validate(u16 interface, int *target, unsigned long long address)
{
if (NFP_CPP_INTERFACE_TYPE_of(interface) ==
NFP_CPP_INTERFACE_TYPE_INVALID)
return -EINVAL;
if (address & 7)
return -EINVAL;
if (*target != NFP_CPP_TARGET_MU)
return -EINVAL;
return 0;
}
int nfp_cpp_mutex_init(struct nfp_cpp *cpp,
int target, unsigned long long address, u32 key)
{
const u32 muw = NFP_CPP_ID(target, 4, 0);
u16 interface = nfp_cpp_interface(cpp);
int err;
err = nfp_cpp_mutex_validate(interface, &target, address);
if (err)
return err;
err = nfp_cpp_writel(cpp, muw, address + 4, key);
if (err)
return err;
err = nfp_cpp_writel(cpp, muw, address, nfp_mutex_locked(interface));
if (err)
return err;
return 0;
}
struct nfp_cpp_mutex *nfp_cpp_mutex_alloc(struct nfp_cpp *cpp, int target,
unsigned long long address, u32 key)
{
const u32 mur = NFP_CPP_ID(target, 3, 0);
u16 interface = nfp_cpp_interface(cpp);
struct nfp_cpp_mutex *mutex;
int err;
u32 tmp;
err = nfp_cpp_mutex_validate(interface, &target, address);
if (err)
return NULL;
err = nfp_cpp_readl(cpp, mur, address + 4, &tmp);
if (err < 0)
return NULL;
if (tmp != key)
return NULL;
mutex = kzalloc(sizeof(*mutex), GFP_KERNEL);
if (!mutex)
return NULL;
mutex->cpp = cpp;
mutex->target = target;
mutex->address = address;
mutex->key = key;
mutex->depth = 0;
return mutex;
}
void nfp_cpp_mutex_free(struct nfp_cpp_mutex *mutex)
{
kfree(mutex);
}
int nfp_cpp_mutex_lock(struct nfp_cpp_mutex *mutex)
{
unsigned long warn_at = jiffies + NFP_MUTEX_WAIT_FIRST_WARN * HZ;
unsigned long err_at = jiffies + NFP_MUTEX_WAIT_ERROR * HZ;
unsigned int timeout_ms = 1;
int err;
for (;;) {
err = nfp_cpp_mutex_trylock(mutex);
if (err != -EBUSY)
break;
err = msleep_interruptible(timeout_ms);
if (err != 0)
return -ERESTARTSYS;
if (time_is_before_eq_jiffies(warn_at)) {
warn_at = jiffies + NFP_MUTEX_WAIT_NEXT_WARN * HZ;
nfp_warn(mutex->cpp,
"Warning: waiting for NFP mutex [depth:%hd target:%d addr:%llx key:%08x]\n",
mutex->depth,
mutex->target, mutex->address, mutex->key);
}
if (time_is_before_eq_jiffies(err_at)) {
nfp_err(mutex->cpp, "Error: mutex wait timed out\n");
return -EBUSY;
}
}
return err;
}
int nfp_cpp_mutex_unlock(struct nfp_cpp_mutex *mutex)
{
const u32 muw = NFP_CPP_ID(mutex->target, 4, 0);
const u32 mur = NFP_CPP_ID(mutex->target, 3, 0);
struct nfp_cpp *cpp = mutex->cpp;
u32 key, value;
u16 interface;
int err;
interface = nfp_cpp_interface(cpp);
if (mutex->depth > 1) {
mutex->depth--;
return 0;
}
err = nfp_cpp_readl(mutex->cpp, mur, mutex->address + 4, &key);
if (err < 0)
return err;
if (key != mutex->key)
return -EPERM;
err = nfp_cpp_readl(mutex->cpp, mur, mutex->address, &value);
if (err < 0)
return err;
if (value != nfp_mutex_locked(interface))
return -EACCES;
err = nfp_cpp_writel(cpp, muw, mutex->address,
nfp_mutex_unlocked(interface));
if (err < 0)
return err;
mutex->depth = 0;
return 0;
}
int nfp_cpp_mutex_trylock(struct nfp_cpp_mutex *mutex)
{
const u32 muw = NFP_CPP_ID(mutex->target, 4, 0);
const u32 mus = NFP_CPP_ID(mutex->target, 5, 3);
const u32 mur = NFP_CPP_ID(mutex->target, 3, 0);
struct nfp_cpp *cpp = mutex->cpp;
u32 key, value, tmp;
int err;
if (mutex->depth > 0) {
if (mutex->depth == NFP_MUTEX_DEPTH_MAX)
return -E2BIG;
mutex->depth++;
return 0;
}
err = nfp_cpp_readl(cpp, mur, mutex->address + 4, &key);
if (err < 0)
return err;
if (key != mutex->key)
return -EPERM;
value = nfp_mutex_locked(nfp_cpp_interface(cpp));
err = nfp_cpp_readl(cpp, mus, mutex->address, &tmp);
if (err < 0)
return err;
if (nfp_mutex_is_unlocked(tmp)) {
err = nfp_cpp_writel(cpp, muw, mutex->address, value);
if (err < 0)
return err;
mutex->depth = 1;
return 0;
}
return nfp_mutex_is_locked(tmp) ? -EBUSY : -EINVAL;
}
