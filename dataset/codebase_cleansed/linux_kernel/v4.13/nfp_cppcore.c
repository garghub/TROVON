static void __resource_add(struct list_head *head, struct nfp_cpp_resource *res)
{
struct nfp_cpp_resource *tmp;
struct list_head *pos;
list_for_each(pos, head) {
tmp = container_of(pos, struct nfp_cpp_resource, list);
if (tmp->cpp_id > res->cpp_id)
break;
if (tmp->cpp_id == res->cpp_id && tmp->start > res->start)
break;
}
list_add_tail(&res->list, pos);
}
static void __resource_del(struct nfp_cpp_resource *res)
{
list_del_init(&res->list);
}
static void __release_cpp_area(struct kref *kref)
{
struct nfp_cpp_area *area =
container_of(kref, struct nfp_cpp_area, kref);
struct nfp_cpp *cpp = nfp_cpp_area_cpp(area);
if (area->cpp->op->area_cleanup)
area->cpp->op->area_cleanup(area);
write_lock(&cpp->resource_lock);
__resource_del(&area->resource);
write_unlock(&cpp->resource_lock);
kfree(area);
}
static void nfp_cpp_area_put(struct nfp_cpp_area *area)
{
kref_put(&area->kref, __release_cpp_area);
}
static struct nfp_cpp_area *nfp_cpp_area_get(struct nfp_cpp_area *area)
{
kref_get(&area->kref);
return area;
}
void nfp_cpp_free(struct nfp_cpp *cpp)
{
struct nfp_cpp_area_cache *cache, *ctmp;
struct nfp_cpp_resource *res, *rtmp;
list_for_each_entry_safe(cache, ctmp, &cpp->area_cache_list, entry) {
list_del(&cache->entry);
if (cache->id)
nfp_cpp_area_release(cache->area);
nfp_cpp_area_free(cache->area);
kfree(cache);
}
WARN_ON(!list_empty(&cpp->resource_list));
list_for_each_entry_safe(res, rtmp, &cpp->resource_list, list) {
struct nfp_cpp_area *area = container_of(res,
struct nfp_cpp_area,
resource);
dev_err(cpp->dev.parent, "Dangling area: %d:%d:%d:0x%0llx-0x%0llx%s%s\n",
NFP_CPP_ID_TARGET_of(res->cpp_id),
NFP_CPP_ID_ACTION_of(res->cpp_id),
NFP_CPP_ID_TOKEN_of(res->cpp_id),
res->start, res->end,
res->name ? " " : "",
res->name ? res->name : "");
if (area->cpp->op->area_release)
area->cpp->op->area_release(area);
__release_cpp_area(&area->kref);
}
if (cpp->op->free)
cpp->op->free(cpp);
device_unregister(&cpp->dev);
kfree(cpp);
}
u32 nfp_cpp_model(struct nfp_cpp *cpp)
{
return cpp->model;
}
u16 nfp_cpp_interface(struct nfp_cpp *cpp)
{
return cpp->interface;
}
int nfp_cpp_serial(struct nfp_cpp *cpp, const u8 **serial)
{
*serial = &cpp->serial[0];
return sizeof(cpp->serial);
}
struct nfp_cpp_area *
nfp_cpp_area_alloc_with_name(struct nfp_cpp *cpp, u32 dest, const char *name,
unsigned long long address, unsigned long size)
{
struct nfp_cpp_area *area;
u64 tmp64 = address;
int err, name_len;
err = nfp_target_cpp(dest, tmp64, &dest, &tmp64, cpp->imb_cat_table);
if (err < 0)
return NULL;
address = tmp64;
if (!name)
name = "(reserved)";
name_len = strlen(name) + 1;
area = kzalloc(sizeof(*area) + cpp->op->area_priv_size + name_len,
GFP_KERNEL);
if (!area)
return NULL;
area->cpp = cpp;
area->resource.name = (void *)area + sizeof(*area) +
cpp->op->area_priv_size;
memcpy((char *)area->resource.name, name, name_len);
area->resource.cpp_id = dest;
area->resource.start = address;
area->resource.end = area->resource.start + size - 1;
INIT_LIST_HEAD(&area->resource.list);
atomic_set(&area->refcount, 0);
kref_init(&area->kref);
mutex_init(&area->mutex);
if (cpp->op->area_init) {
int err;
err = cpp->op->area_init(area, dest, address, size);
if (err < 0) {
kfree(area);
return NULL;
}
}
write_lock(&cpp->resource_lock);
__resource_add(&cpp->resource_list, &area->resource);
write_unlock(&cpp->resource_lock);
area->offset = address;
area->size = size;
return area;
}
struct nfp_cpp_area *
nfp_cpp_area_alloc(struct nfp_cpp *cpp, u32 dest,
unsigned long long address, unsigned long size)
{
return nfp_cpp_area_alloc_with_name(cpp, dest, NULL, address, size);
}
struct nfp_cpp_area *
nfp_cpp_area_alloc_acquire(struct nfp_cpp *cpp, const char *name, u32 dest,
unsigned long long address, unsigned long size)
{
struct nfp_cpp_area *area;
area = nfp_cpp_area_alloc_with_name(cpp, dest, name, address, size);
if (!area)
return NULL;
if (nfp_cpp_area_acquire(area)) {
nfp_cpp_area_free(area);
return NULL;
}
return area;
}
void nfp_cpp_area_free(struct nfp_cpp_area *area)
{
if (atomic_read(&area->refcount))
nfp_warn(area->cpp, "Warning: freeing busy area\n");
nfp_cpp_area_put(area);
}
static bool nfp_cpp_area_acquire_try(struct nfp_cpp_area *area, int *status)
{
*status = area->cpp->op->area_acquire(area);
return *status != -EAGAIN;
}
static int __nfp_cpp_area_acquire(struct nfp_cpp_area *area)
{
int err, status;
if (atomic_inc_return(&area->refcount) > 1)
return 0;
if (!area->cpp->op->area_acquire)
return 0;
err = wait_event_interruptible(area->cpp->waitq,
nfp_cpp_area_acquire_try(area, &status));
if (!err)
err = status;
if (err) {
nfp_warn(area->cpp, "Warning: area wait failed: %d\n", err);
atomic_dec(&area->refcount);
return err;
}
nfp_cpp_area_get(area);
return 0;
}
int nfp_cpp_area_acquire(struct nfp_cpp_area *area)
{
int ret;
mutex_lock(&area->mutex);
ret = __nfp_cpp_area_acquire(area);
mutex_unlock(&area->mutex);
return ret;
}
int nfp_cpp_area_acquire_nonblocking(struct nfp_cpp_area *area)
{
mutex_lock(&area->mutex);
if (atomic_inc_return(&area->refcount) == 1) {
if (area->cpp->op->area_acquire) {
int err;
err = area->cpp->op->area_acquire(area);
if (err < 0) {
atomic_dec(&area->refcount);
mutex_unlock(&area->mutex);
return err;
}
}
}
mutex_unlock(&area->mutex);
nfp_cpp_area_get(area);
return 0;
}
void nfp_cpp_area_release(struct nfp_cpp_area *area)
{
mutex_lock(&area->mutex);
if (atomic_dec_and_test(&area->refcount)) {
if (area->cpp->op->area_release) {
area->cpp->op->area_release(area);
wake_up_interruptible_all(&area->cpp->waitq);
}
}
mutex_unlock(&area->mutex);
nfp_cpp_area_put(area);
}
void nfp_cpp_area_release_free(struct nfp_cpp_area *area)
{
nfp_cpp_area_release(area);
nfp_cpp_area_free(area);
}
int nfp_cpp_area_read(struct nfp_cpp_area *area,
unsigned long offset, void *kernel_vaddr,
size_t length)
{
return area->cpp->op->area_read(area, kernel_vaddr, offset, length);
}
int nfp_cpp_area_write(struct nfp_cpp_area *area,
unsigned long offset, const void *kernel_vaddr,
size_t length)
{
return area->cpp->op->area_write(area, kernel_vaddr, offset, length);
}
const char *nfp_cpp_area_name(struct nfp_cpp_area *cpp_area)
{
return cpp_area->resource.name;
}
void *nfp_cpp_area_priv(struct nfp_cpp_area *cpp_area)
{
return &cpp_area[1];
}
struct nfp_cpp *nfp_cpp_area_cpp(struct nfp_cpp_area *cpp_area)
{
return cpp_area->cpp;
}
struct resource *nfp_cpp_area_resource(struct nfp_cpp_area *area)
{
struct resource *res = NULL;
if (area->cpp->op->area_resource)
res = area->cpp->op->area_resource(area);
return res;
}
phys_addr_t nfp_cpp_area_phys(struct nfp_cpp_area *area)
{
phys_addr_t addr = ~0;
if (area->cpp->op->area_phys)
addr = area->cpp->op->area_phys(area);
return addr;
}
void __iomem *nfp_cpp_area_iomem(struct nfp_cpp_area *area)
{
void __iomem *iomem = NULL;
if (area->cpp->op->area_iomem)
iomem = area->cpp->op->area_iomem(area);
return iomem;
}
int nfp_cpp_area_readl(struct nfp_cpp_area *area,
unsigned long offset, u32 *value)
{
u8 tmp[4];
int err;
err = nfp_cpp_area_read(area, offset, &tmp, sizeof(tmp));
*value = get_unaligned_le32(tmp);
return err;
}
int nfp_cpp_area_writel(struct nfp_cpp_area *area,
unsigned long offset, u32 value)
{
u8 tmp[4];
put_unaligned_le32(value, tmp);
return nfp_cpp_area_write(area, offset, &tmp, sizeof(tmp));
}
int nfp_cpp_area_readq(struct nfp_cpp_area *area,
unsigned long offset, u64 *value)
{
u8 tmp[8];
int err;
err = nfp_cpp_area_read(area, offset, &tmp, sizeof(tmp));
*value = get_unaligned_le64(tmp);
return err;
}
int nfp_cpp_area_writeq(struct nfp_cpp_area *area,
unsigned long offset, u64 value)
{
u8 tmp[8];
put_unaligned_le64(value, tmp);
return nfp_cpp_area_write(area, offset, &tmp, sizeof(tmp));
}
int nfp_cpp_area_fill(struct nfp_cpp_area *area,
unsigned long offset, u32 value, size_t length)
{
u8 tmp[4];
size_t i;
int k;
put_unaligned_le32(value, tmp);
if (offset % sizeof(tmp) || length % sizeof(tmp))
return -EINVAL;
for (i = 0; i < length; i += sizeof(tmp)) {
k = nfp_cpp_area_write(area, offset + i, &tmp, sizeof(tmp));
if (k < 0)
return k;
}
return i;
}
int nfp_cpp_area_cache_add(struct nfp_cpp *cpp, size_t size)
{
struct nfp_cpp_area_cache *cache;
struct nfp_cpp_area *area;
area = nfp_cpp_area_alloc(cpp, NFP_CPP_ID(7, NFP_CPP_ACTION_RW, 0),
0, size);
if (!area)
return -ENOMEM;
cache = kzalloc(sizeof(*cache), GFP_KERNEL);
if (!cache)
return -ENOMEM;
cache->id = 0;
cache->addr = 0;
cache->size = size;
cache->area = area;
mutex_lock(&cpp->area_cache_mutex);
list_add_tail(&cache->entry, &cpp->area_cache_list);
mutex_unlock(&cpp->area_cache_mutex);
return 0;
}
static struct nfp_cpp_area_cache *
area_cache_get(struct nfp_cpp *cpp, u32 id,
u64 addr, unsigned long *offset, size_t length)
{
struct nfp_cpp_area_cache *cache;
int err;
if (length == 0 || id == 0)
return NULL;
err = nfp_target_cpp(id, addr, &id, &addr, cpp->imb_cat_table);
if (err < 0)
return NULL;
mutex_lock(&cpp->area_cache_mutex);
if (list_empty(&cpp->area_cache_list)) {
mutex_unlock(&cpp->area_cache_mutex);
return NULL;
}
addr += *offset;
list_for_each_entry(cache, &cpp->area_cache_list, entry) {
if (id == cache->id &&
addr >= cache->addr &&
addr + length <= cache->addr + cache->size)
goto exit;
}
cache = list_entry(cpp->area_cache_list.prev,
struct nfp_cpp_area_cache, entry);
if (round_down(addr + length - 1, cache->size) !=
round_down(addr, cache->size)) {
mutex_unlock(&cpp->area_cache_mutex);
return NULL;
}
if (cache->id) {
nfp_cpp_area_release(cache->area);
cache->id = 0;
cache->addr = 0;
}
cache->id = id;
cache->addr = addr & ~(u64)(cache->size - 1);
if (cpp->op->area_init) {
err = cpp->op->area_init(cache->area,
id, cache->addr, cache->size);
if (err < 0) {
mutex_unlock(&cpp->area_cache_mutex);
return NULL;
}
}
err = nfp_cpp_area_acquire(cache->area);
if (err < 0) {
mutex_unlock(&cpp->area_cache_mutex);
return NULL;
}
exit:
*offset = addr - cache->addr;
return cache;
}
static void
area_cache_put(struct nfp_cpp *cpp, struct nfp_cpp_area_cache *cache)
{
if (!cache)
return;
list_del(&cache->entry);
list_add(&cache->entry, &cpp->area_cache_list);
mutex_unlock(&cpp->area_cache_mutex);
}
static int __nfp_cpp_read(struct nfp_cpp *cpp, u32 destination,
unsigned long long address, void *kernel_vaddr,
size_t length)
{
struct nfp_cpp_area_cache *cache;
struct nfp_cpp_area *area;
unsigned long offset = 0;
int err;
cache = area_cache_get(cpp, destination, address, &offset, length);
if (cache) {
area = cache->area;
} else {
area = nfp_cpp_area_alloc(cpp, destination, address, length);
if (!area)
return -ENOMEM;
err = nfp_cpp_area_acquire(area);
if (err) {
nfp_cpp_area_free(area);
return err;
}
}
err = nfp_cpp_area_read(area, offset, kernel_vaddr, length);
if (cache)
area_cache_put(cpp, cache);
else
nfp_cpp_area_release_free(area);
return err;
}
int nfp_cpp_read(struct nfp_cpp *cpp, u32 destination,
unsigned long long address, void *kernel_vaddr,
size_t length)
{
size_t n, offset;
int ret;
for (offset = 0; offset < length; offset += n) {
unsigned long long r_addr = address + offset;
n = min_t(size_t, length - offset,
ALIGN(r_addr + 1, NFP_CPP_SAFE_AREA_SIZE) - r_addr);
ret = __nfp_cpp_read(cpp, destination, address + offset,
kernel_vaddr + offset, n);
if (ret < 0)
return ret;
if (ret != n)
return offset + n;
}
return length;
}
static int __nfp_cpp_write(struct nfp_cpp *cpp, u32 destination,
unsigned long long address,
const void *kernel_vaddr, size_t length)
{
struct nfp_cpp_area_cache *cache;
struct nfp_cpp_area *area;
unsigned long offset = 0;
int err;
cache = area_cache_get(cpp, destination, address, &offset, length);
if (cache) {
area = cache->area;
} else {
area = nfp_cpp_area_alloc(cpp, destination, address, length);
if (!area)
return -ENOMEM;
err = nfp_cpp_area_acquire(area);
if (err) {
nfp_cpp_area_free(area);
return err;
}
}
err = nfp_cpp_area_write(area, offset, kernel_vaddr, length);
if (cache)
area_cache_put(cpp, cache);
else
nfp_cpp_area_release_free(area);
return err;
}
int nfp_cpp_write(struct nfp_cpp *cpp, u32 destination,
unsigned long long address,
const void *kernel_vaddr, size_t length)
{
size_t n, offset;
int ret;
for (offset = 0; offset < length; offset += n) {
unsigned long long w_addr = address + offset;
n = min_t(size_t, length - offset,
ALIGN(w_addr + 1, NFP_CPP_SAFE_AREA_SIZE) - w_addr);
ret = __nfp_cpp_write(cpp, destination, address + offset,
kernel_vaddr + offset, n);
if (ret < 0)
return ret;
if (ret != n)
return offset + n;
}
return length;
}
static u32 nfp_xpb_to_cpp(struct nfp_cpp *cpp, u32 *xpb_addr)
{
int island;
u32 xpb;
xpb = NFP_CPP_ID(14, NFP_CPP_ACTION_RW, 0);
island = (*xpb_addr >> 24) & 0x3f;
if (!island)
return xpb;
if (island != 1) {
*xpb_addr |= 1 << 30;
return xpb;
}
*xpb_addr &= ~0x7f000000;
if (*xpb_addr < 0x60000) {
*xpb_addr |= 1 << 30;
} else {
if (NFP_CPP_INTERFACE_TYPE_of(nfp_cpp_interface(cpp))
!= NFP_CPP_INTERFACE_TYPE_ARM)
*xpb_addr |= 1 << 24;
}
return xpb;
}
int nfp_xpb_readl(struct nfp_cpp *cpp, u32 xpb_addr, u32 *value)
{
u32 cpp_dest = nfp_xpb_to_cpp(cpp, &xpb_addr);
return nfp_cpp_readl(cpp, cpp_dest, xpb_addr, value);
}
int nfp_xpb_writel(struct nfp_cpp *cpp, u32 xpb_addr, u32 value)
{
u32 cpp_dest = nfp_xpb_to_cpp(cpp, &xpb_addr);
return nfp_cpp_writel(cpp, cpp_dest, xpb_addr, value);
}
int nfp_xpb_writelm(struct nfp_cpp *cpp, u32 xpb_tgt,
u32 mask, u32 value)
{
int err;
u32 tmp;
err = nfp_xpb_readl(cpp, xpb_tgt, &tmp);
if (err < 0)
return err;
tmp &= ~mask;
tmp |= mask & value;
return nfp_xpb_writel(cpp, xpb_tgt, tmp);
}
static void nfp_cpp_dev_release(struct device *dev)
{
}
struct nfp_cpp *
nfp_cpp_from_operations(const struct nfp_cpp_operations *ops,
struct device *parent, void *priv)
{
const u32 arm = NFP_CPP_ID(NFP_CPP_TARGET_ARM, NFP_CPP_ACTION_RW, 0);
struct nfp_cpp *cpp;
u32 mask[2];
u32 xpbaddr;
size_t tgt;
int err;
cpp = kzalloc(sizeof(*cpp), GFP_KERNEL);
if (!cpp) {
err = -ENOMEM;
goto err_malloc;
}
cpp->op = ops;
cpp->priv = priv;
cpp->interface = ops->get_interface(parent);
if (ops->read_serial)
ops->read_serial(parent, cpp->serial);
rwlock_init(&cpp->resource_lock);
init_waitqueue_head(&cpp->waitq);
lockdep_set_class(&cpp->resource_lock, &nfp_cpp_resource_lock_key);
INIT_LIST_HEAD(&cpp->resource_list);
INIT_LIST_HEAD(&cpp->area_cache_list);
mutex_init(&cpp->area_cache_mutex);
cpp->dev.init_name = "cpp";
cpp->dev.parent = parent;
cpp->dev.release = nfp_cpp_dev_release;
err = device_register(&cpp->dev);
if (err < 0) {
put_device(&cpp->dev);
goto err_dev;
}
dev_set_drvdata(&cpp->dev, cpp);
if (cpp->op->init) {
err = cpp->op->init(cpp);
if (err < 0) {
dev_err(parent,
"NFP interface initialization failed\n");
goto err_out;
}
}
err = nfp_cpp_model_autodetect(cpp, &cpp->model);
if (err < 0) {
dev_err(parent, "NFP model detection failed\n");
goto err_out;
}
for (tgt = 0; tgt < ARRAY_SIZE(cpp->imb_cat_table); tgt++) {
xpbaddr = 0x000a0000 + (tgt * 4);
err = nfp_xpb_readl(cpp, xpbaddr,
&cpp->imb_cat_table[tgt]);
if (err < 0) {
dev_err(parent,
"Can't read CPP mapping from device\n");
goto err_out;
}
}
nfp_cpp_readl(cpp, arm, NFP_ARM_GCSR + NFP_ARM_GCSR_SOFTMODEL2,
&mask[0]);
nfp_cpp_readl(cpp, arm, NFP_ARM_GCSR + NFP_ARM_GCSR_SOFTMODEL3,
&mask[1]);
dev_info(cpp->dev.parent, "Model: 0x%08x, SN: %pM, Ifc: 0x%04x\n",
nfp_cpp_model(cpp), cpp->serial, nfp_cpp_interface(cpp));
return cpp;
err_out:
device_unregister(&cpp->dev);
err_dev:
kfree(cpp);
err_malloc:
return ERR_PTR(err);
}
void *nfp_cpp_priv(struct nfp_cpp *cpp)
{
return cpp->priv;
}
struct device *nfp_cpp_device(struct nfp_cpp *cpp)
{
return &cpp->dev;
}
struct nfp_cpp_explicit *nfp_cpp_explicit_acquire(struct nfp_cpp *cpp)
{
struct nfp_cpp_explicit *expl;
int err;
expl = kzalloc(sizeof(*expl) + cpp->op->explicit_priv_size, GFP_KERNEL);
if (!expl)
return NULL;
expl->cpp = cpp;
err = NFP_EXPL_OP(explicit_acquire, expl);
if (err < 0) {
kfree(expl);
return NULL;
}
return expl;
}
int nfp_cpp_explicit_set_target(struct nfp_cpp_explicit *expl,
u32 cpp_id, u8 len, u8 mask)
{
expl->cmd.cpp_id = cpp_id;
expl->cmd.len = len;
expl->cmd.byte_mask = mask;
return 0;
}
int nfp_cpp_explicit_set_data(struct nfp_cpp_explicit *expl,
u8 data_master, u16 data_ref)
{
expl->cmd.data_master = data_master;
expl->cmd.data_ref = data_ref;
return 0;
}
int nfp_cpp_explicit_set_signal(struct nfp_cpp_explicit *expl,
u8 signal_master, u8 signal_ref)
{
expl->cmd.signal_master = signal_master;
expl->cmd.signal_ref = signal_ref;
return 0;
}
int nfp_cpp_explicit_set_posted(struct nfp_cpp_explicit *expl, int posted,
u8 siga,
enum nfp_cpp_explicit_signal_mode siga_mode,
u8 sigb,
enum nfp_cpp_explicit_signal_mode sigb_mode)
{
expl->cmd.posted = posted;
expl->cmd.siga = siga;
expl->cmd.sigb = sigb;
expl->cmd.siga_mode = siga_mode;
expl->cmd.sigb_mode = sigb_mode;
return 0;
}
int nfp_cpp_explicit_put(struct nfp_cpp_explicit *expl,
const void *buff, size_t len)
{
return NFP_EXPL_OP(explicit_put, expl, buff, len);
}
int nfp_cpp_explicit_do(struct nfp_cpp_explicit *expl, u64 address)
{
return NFP_EXPL_OP(explicit_do, expl, &expl->cmd, address);
}
int nfp_cpp_explicit_get(struct nfp_cpp_explicit *expl, void *buff, size_t len)
{
return NFP_EXPL_OP(explicit_get, expl, buff, len);
}
void nfp_cpp_explicit_release(struct nfp_cpp_explicit *expl)
{
NFP_EXPL_OP_NR(explicit_release, expl);
kfree(expl);
}
struct nfp_cpp *nfp_cpp_explicit_cpp(struct nfp_cpp_explicit *cpp_explicit)
{
return cpp_explicit->cpp;
}
void *nfp_cpp_explicit_priv(struct nfp_cpp_explicit *cpp_explicit)
{
return &cpp_explicit[1];
}
