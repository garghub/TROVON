inline int __vringh_get_head(const struct vringh *vrh,
int (*getu16)(const struct vringh *vrh,
u16 *val, const __virtio16 *p),
u16 *last_avail_idx)
{
u16 avail_idx, i, head;
int err;
err = getu16(vrh, &avail_idx, &vrh->vring.avail->idx);
if (err) {
vringh_bad("Failed to access avail idx at %p",
&vrh->vring.avail->idx);
return err;
}
if (*last_avail_idx == avail_idx)
return vrh->vring.num;
virtio_rmb(vrh->weak_barriers);
i = *last_avail_idx & (vrh->vring.num - 1);
err = getu16(vrh, &head, &vrh->vring.avail->ring[i]);
if (err) {
vringh_bad("Failed to read head: idx %d address %p",
*last_avail_idx, &vrh->vring.avail->ring[i]);
return err;
}
if (head >= vrh->vring.num) {
vringh_bad("Guest says index %u > %u is available",
head, vrh->vring.num);
return -EINVAL;
}
(*last_avail_idx)++;
return head;
}
static inline ssize_t vringh_iov_xfer(struct vringh_kiov *iov,
void *ptr, size_t len,
int (*xfer)(void *addr, void *ptr,
size_t len))
{
int err, done = 0;
while (len && iov->i < iov->used) {
size_t partlen;
partlen = min(iov->iov[iov->i].iov_len, len);
err = xfer(iov->iov[iov->i].iov_base, ptr, partlen);
if (err)
return err;
done += partlen;
len -= partlen;
ptr += partlen;
iov->consumed += partlen;
iov->iov[iov->i].iov_len -= partlen;
iov->iov[iov->i].iov_base += partlen;
if (!iov->iov[iov->i].iov_len) {
iov->iov[iov->i].iov_len = iov->consumed;
iov->iov[iov->i].iov_base -= iov->consumed;
iov->consumed = 0;
iov->i++;
}
}
return done;
}
static inline bool range_check(struct vringh *vrh, u64 addr, size_t *len,
struct vringh_range *range,
bool (*getrange)(struct vringh *,
u64, struct vringh_range *))
{
if (addr < range->start || addr > range->end_incl) {
if (!getrange(vrh, addr, range))
return false;
}
BUG_ON(addr < range->start || addr > range->end_incl);
if (unlikely(addr + *len == 0)) {
if (range->end_incl == -1ULL)
return true;
goto truncate;
}
if (addr + *len < addr) {
vringh_bad("Wrapping descriptor %zu@0x%llx",
*len, (unsigned long long)addr);
return false;
}
if (unlikely(addr + *len - 1 > range->end_incl))
goto truncate;
return true;
truncate:
*len = range->end_incl + 1 - addr;
return true;
}
static inline bool no_range_check(struct vringh *vrh, u64 addr, size_t *len,
struct vringh_range *range,
bool (*getrange)(struct vringh *,
u64, struct vringh_range *))
{
return true;
}
static int move_to_indirect(const struct vringh *vrh,
int *up_next, u16 *i, void *addr,
const struct vring_desc *desc,
struct vring_desc **descs, int *desc_max)
{
u32 len;
if (*up_next != -1) {
vringh_bad("Multilevel indirect %u->%u", *up_next, *i);
return -EINVAL;
}
len = vringh32_to_cpu(vrh, desc->len);
if (unlikely(len % sizeof(struct vring_desc))) {
vringh_bad("Strange indirect len %u", desc->len);
return -EINVAL;
}
if (desc->flags & cpu_to_vringh16(vrh, VRING_DESC_F_NEXT))
*up_next = vringh16_to_cpu(vrh, desc->next);
else
*up_next = -2;
*descs = addr;
*desc_max = len / sizeof(struct vring_desc);
*i = 0;
return 0;
}
static int resize_iovec(struct vringh_kiov *iov, gfp_t gfp)
{
struct kvec *new;
unsigned int flag, new_num = (iov->max_num & ~VRINGH_IOV_ALLOCATED) * 2;
if (new_num < 8)
new_num = 8;
flag = (iov->max_num & VRINGH_IOV_ALLOCATED);
if (flag)
new = krealloc(iov->iov, new_num * sizeof(struct iovec), gfp);
else {
new = kmalloc(new_num * sizeof(struct iovec), gfp);
if (new) {
memcpy(new, iov->iov,
iov->max_num * sizeof(struct iovec));
flag = VRINGH_IOV_ALLOCATED;
}
}
if (!new)
return -ENOMEM;
iov->iov = new;
iov->max_num = (new_num | flag);
return 0;
}
static u16 __cold return_from_indirect(const struct vringh *vrh, int *up_next,
struct vring_desc **descs, int *desc_max)
{
u16 i = *up_next;
*up_next = -1;
*descs = vrh->vring.desc;
*desc_max = vrh->vring.num;
return i;
}
static int slow_copy(struct vringh *vrh, void *dst, const void *src,
bool (*rcheck)(struct vringh *vrh, u64 addr, size_t *len,
struct vringh_range *range,
bool (*getrange)(struct vringh *vrh,
u64,
struct vringh_range *)),
bool (*getrange)(struct vringh *vrh,
u64 addr,
struct vringh_range *r),
struct vringh_range *range,
int (*copy)(void *dst, const void *src, size_t len))
{
size_t part, len = sizeof(struct vring_desc);
do {
u64 addr;
int err;
part = len;
addr = (u64)(unsigned long)src - range->offset;
if (!rcheck(vrh, addr, &part, range, getrange))
return -EINVAL;
err = copy(dst, src, part);
if (err)
return err;
dst += part;
src += part;
len -= part;
} while (len);
return 0;
}
static inline int
__vringh_iov(struct vringh *vrh, u16 i,
struct vringh_kiov *riov,
struct vringh_kiov *wiov,
bool (*rcheck)(struct vringh *vrh, u64 addr, size_t *len,
struct vringh_range *range,
bool (*getrange)(struct vringh *, u64,
struct vringh_range *)),
bool (*getrange)(struct vringh *, u64, struct vringh_range *),
gfp_t gfp,
int (*copy)(void *dst, const void *src, size_t len))
{
int err, count = 0, up_next, desc_max;
struct vring_desc desc, *descs;
struct vringh_range range = { -1ULL, 0 }, slowrange;
bool slow = false;
descs = vrh->vring.desc;
desc_max = vrh->vring.num;
up_next = -1;
if (riov)
riov->i = riov->used = 0;
else if (wiov)
wiov->i = wiov->used = 0;
else
BUG();
for (;;) {
void *addr;
struct vringh_kiov *iov;
size_t len;
if (unlikely(slow))
err = slow_copy(vrh, &desc, &descs[i], rcheck, getrange,
&slowrange, copy);
else
err = copy(&desc, &descs[i], sizeof(desc));
if (unlikely(err))
goto fail;
if (unlikely(desc.flags &
cpu_to_vringh16(vrh, VRING_DESC_F_INDIRECT))) {
u64 a = vringh64_to_cpu(vrh, desc.addr);
len = vringh32_to_cpu(vrh, desc.len);
if (!rcheck(vrh, a, &len, &range, getrange)) {
err = -EINVAL;
goto fail;
}
if (unlikely(len != vringh32_to_cpu(vrh, desc.len))) {
slow = true;
slowrange = range;
}
addr = (void *)(long)(a + range.offset);
err = move_to_indirect(vrh, &up_next, &i, addr, &desc,
&descs, &desc_max);
if (err)
goto fail;
continue;
}
if (count++ == vrh->vring.num) {
vringh_bad("Descriptor loop in %p", descs);
err = -ELOOP;
goto fail;
}
if (desc.flags & cpu_to_vringh16(vrh, VRING_DESC_F_WRITE))
iov = wiov;
else {
iov = riov;
if (unlikely(wiov && wiov->i)) {
vringh_bad("Readable desc %p after writable",
&descs[i]);
err = -EINVAL;
goto fail;
}
}
if (!iov) {
vringh_bad("Unexpected %s desc",
!wiov ? "writable" : "readable");
err = -EPROTO;
goto fail;
}
again:
len = vringh32_to_cpu(vrh, desc.len);
if (!rcheck(vrh, vringh64_to_cpu(vrh, desc.addr), &len, &range,
getrange)) {
err = -EINVAL;
goto fail;
}
addr = (void *)(unsigned long)(vringh64_to_cpu(vrh, desc.addr) +
range.offset);
if (unlikely(iov->used == (iov->max_num & ~VRINGH_IOV_ALLOCATED))) {
err = resize_iovec(iov, gfp);
if (err)
goto fail;
}
iov->iov[iov->used].iov_base = addr;
iov->iov[iov->used].iov_len = len;
iov->used++;
if (unlikely(len != vringh32_to_cpu(vrh, desc.len))) {
desc.len = cpu_to_vringh32(vrh,
vringh32_to_cpu(vrh, desc.len) - len);
desc.addr = cpu_to_vringh64(vrh,
vringh64_to_cpu(vrh, desc.addr) + len);
goto again;
}
if (desc.flags & cpu_to_vringh16(vrh, VRING_DESC_F_NEXT)) {
i = vringh16_to_cpu(vrh, desc.next);
} else {
if (unlikely(up_next > 0)) {
i = return_from_indirect(vrh, &up_next,
&descs, &desc_max);
slow = false;
} else
break;
}
if (i >= desc_max) {
vringh_bad("Chained index %u > %u", i, desc_max);
err = -EINVAL;
goto fail;
}
}
return 0;
fail:
return err;
}
static inline int __vringh_complete(struct vringh *vrh,
const struct vring_used_elem *used,
unsigned int num_used,
int (*putu16)(const struct vringh *vrh,
__virtio16 *p, u16 val),
int (*putused)(struct vring_used_elem *dst,
const struct vring_used_elem
*src, unsigned num))
{
struct vring_used *used_ring;
int err;
u16 used_idx, off;
used_ring = vrh->vring.used;
used_idx = vrh->last_used_idx + vrh->completed;
off = used_idx % vrh->vring.num;
if (num_used > 1 && unlikely(off + num_used >= vrh->vring.num)) {
u16 part = vrh->vring.num - off;
err = putused(&used_ring->ring[off], used, part);
if (!err)
err = putused(&used_ring->ring[0], used + part,
num_used - part);
} else
err = putused(&used_ring->ring[off], used, num_used);
if (err) {
vringh_bad("Failed to write %u used entries %u at %p",
num_used, off, &used_ring->ring[off]);
return err;
}
virtio_wmb(vrh->weak_barriers);
err = putu16(vrh, &vrh->vring.used->idx, used_idx + num_used);
if (err) {
vringh_bad("Failed to update used index at %p",
&vrh->vring.used->idx);
return err;
}
vrh->completed += num_used;
return 0;
}
static inline int __vringh_need_notify(struct vringh *vrh,
int (*getu16)(const struct vringh *vrh,
u16 *val,
const __virtio16 *p))
{
bool notify;
u16 used_event;
int err;
virtio_mb(vrh->weak_barriers);
if (!vrh->event_indices) {
u16 flags;
err = getu16(vrh, &flags, &vrh->vring.avail->flags);
if (err) {
vringh_bad("Failed to get flags at %p",
&vrh->vring.avail->flags);
return err;
}
return (!(flags & VRING_AVAIL_F_NO_INTERRUPT));
}
err = getu16(vrh, &used_event, &vring_used_event(&vrh->vring));
if (err) {
vringh_bad("Failed to get used event idx at %p",
&vring_used_event(&vrh->vring));
return err;
}
if (unlikely(vrh->completed > 0xffff))
notify = true;
else
notify = vring_need_event(used_event,
vrh->last_used_idx + vrh->completed,
vrh->last_used_idx);
vrh->last_used_idx += vrh->completed;
vrh->completed = 0;
return notify;
}
static inline bool __vringh_notify_enable(struct vringh *vrh,
int (*getu16)(const struct vringh *vrh,
u16 *val, const __virtio16 *p),
int (*putu16)(const struct vringh *vrh,
__virtio16 *p, u16 val))
{
u16 avail;
if (!vrh->event_indices) {
if (putu16(vrh, &vrh->vring.used->flags, 0) != 0) {
vringh_bad("Clearing used flags %p",
&vrh->vring.used->flags);
return true;
}
} else {
if (putu16(vrh, &vring_avail_event(&vrh->vring),
vrh->last_avail_idx) != 0) {
vringh_bad("Updating avail event index %p",
&vring_avail_event(&vrh->vring));
return true;
}
}
virtio_mb(vrh->weak_barriers);
if (getu16(vrh, &avail, &vrh->vring.avail->idx) != 0) {
vringh_bad("Failed to check avail idx at %p",
&vrh->vring.avail->idx);
return true;
}
return avail == vrh->last_avail_idx;
}
static inline void __vringh_notify_disable(struct vringh *vrh,
int (*putu16)(const struct vringh *vrh,
__virtio16 *p, u16 val))
{
if (!vrh->event_indices) {
if (putu16(vrh, &vrh->vring.used->flags,
VRING_USED_F_NO_NOTIFY)) {
vringh_bad("Setting used flags %p",
&vrh->vring.used->flags);
}
}
}
static inline int getu16_user(const struct vringh *vrh, u16 *val, const __virtio16 *p)
{
__virtio16 v = 0;
int rc = get_user(v, (__force __virtio16 __user *)p);
*val = vringh16_to_cpu(vrh, v);
return rc;
}
static inline int putu16_user(const struct vringh *vrh, __virtio16 *p, u16 val)
{
__virtio16 v = cpu_to_vringh16(vrh, val);
return put_user(v, (__force __virtio16 __user *)p);
}
static inline int copydesc_user(void *dst, const void *src, size_t len)
{
return copy_from_user(dst, (__force void __user *)src, len) ?
-EFAULT : 0;
}
static inline int putused_user(struct vring_used_elem *dst,
const struct vring_used_elem *src,
unsigned int num)
{
return copy_to_user((__force void __user *)dst, src,
sizeof(*dst) * num) ? -EFAULT : 0;
}
static inline int xfer_from_user(void *src, void *dst, size_t len)
{
return copy_from_user(dst, (__force void __user *)src, len) ?
-EFAULT : 0;
}
static inline int xfer_to_user(void *dst, void *src, size_t len)
{
return copy_to_user((__force void __user *)dst, src, len) ?
-EFAULT : 0;
}
int vringh_init_user(struct vringh *vrh, u64 features,
unsigned int num, bool weak_barriers,
struct vring_desc __user *desc,
struct vring_avail __user *avail,
struct vring_used __user *used)
{
if (!num || num > 0xffff || (num & (num - 1))) {
vringh_bad("Bad ring size %u", num);
return -EINVAL;
}
vrh->little_endian = (features & (1ULL << VIRTIO_F_VERSION_1));
vrh->event_indices = (features & (1 << VIRTIO_RING_F_EVENT_IDX));
vrh->weak_barriers = weak_barriers;
vrh->completed = 0;
vrh->last_avail_idx = 0;
vrh->last_used_idx = 0;
vrh->vring.num = num;
vrh->vring.desc = (__force struct vring_desc *)desc;
vrh->vring.avail = (__force struct vring_avail *)avail;
vrh->vring.used = (__force struct vring_used *)used;
return 0;
}
int vringh_getdesc_user(struct vringh *vrh,
struct vringh_iov *riov,
struct vringh_iov *wiov,
bool (*getrange)(struct vringh *vrh,
u64 addr, struct vringh_range *r),
u16 *head)
{
int err;
*head = vrh->vring.num;
err = __vringh_get_head(vrh, getu16_user, &vrh->last_avail_idx);
if (err < 0)
return err;
if (err == vrh->vring.num)
return 0;
BUILD_BUG_ON(sizeof(struct vringh_kiov) != sizeof(struct vringh_iov));
BUILD_BUG_ON(offsetof(struct vringh_kiov, iov) !=
offsetof(struct vringh_iov, iov));
BUILD_BUG_ON(offsetof(struct vringh_kiov, i) !=
offsetof(struct vringh_iov, i));
BUILD_BUG_ON(offsetof(struct vringh_kiov, used) !=
offsetof(struct vringh_iov, used));
BUILD_BUG_ON(offsetof(struct vringh_kiov, max_num) !=
offsetof(struct vringh_iov, max_num));
BUILD_BUG_ON(sizeof(struct iovec) != sizeof(struct kvec));
BUILD_BUG_ON(offsetof(struct iovec, iov_base) !=
offsetof(struct kvec, iov_base));
BUILD_BUG_ON(offsetof(struct iovec, iov_len) !=
offsetof(struct kvec, iov_len));
BUILD_BUG_ON(sizeof(((struct iovec *)NULL)->iov_base)
!= sizeof(((struct kvec *)NULL)->iov_base));
BUILD_BUG_ON(sizeof(((struct iovec *)NULL)->iov_len)
!= sizeof(((struct kvec *)NULL)->iov_len));
*head = err;
err = __vringh_iov(vrh, *head, (struct vringh_kiov *)riov,
(struct vringh_kiov *)wiov,
range_check, getrange, GFP_KERNEL, copydesc_user);
if (err)
return err;
return 1;
}
ssize_t vringh_iov_pull_user(struct vringh_iov *riov, void *dst, size_t len)
{
return vringh_iov_xfer((struct vringh_kiov *)riov,
dst, len, xfer_from_user);
}
ssize_t vringh_iov_push_user(struct vringh_iov *wiov,
const void *src, size_t len)
{
return vringh_iov_xfer((struct vringh_kiov *)wiov,
(void *)src, len, xfer_to_user);
}
void vringh_abandon_user(struct vringh *vrh, unsigned int num)
{
vrh->last_avail_idx -= num;
}
int vringh_complete_user(struct vringh *vrh, u16 head, u32 len)
{
struct vring_used_elem used;
used.id = cpu_to_vringh32(vrh, head);
used.len = cpu_to_vringh32(vrh, len);
return __vringh_complete(vrh, &used, 1, putu16_user, putused_user);
}
int vringh_complete_multi_user(struct vringh *vrh,
const struct vring_used_elem used[],
unsigned num_used)
{
return __vringh_complete(vrh, used, num_used,
putu16_user, putused_user);
}
bool vringh_notify_enable_user(struct vringh *vrh)
{
return __vringh_notify_enable(vrh, getu16_user, putu16_user);
}
void vringh_notify_disable_user(struct vringh *vrh)
{
__vringh_notify_disable(vrh, putu16_user);
}
int vringh_need_notify_user(struct vringh *vrh)
{
return __vringh_need_notify(vrh, getu16_user);
}
static inline int getu16_kern(const struct vringh *vrh,
u16 *val, const __virtio16 *p)
{
*val = vringh16_to_cpu(vrh, ACCESS_ONCE(*p));
return 0;
}
static inline int putu16_kern(const struct vringh *vrh, __virtio16 *p, u16 val)
{
ACCESS_ONCE(*p) = cpu_to_vringh16(vrh, val);
return 0;
}
static inline int copydesc_kern(void *dst, const void *src, size_t len)
{
memcpy(dst, src, len);
return 0;
}
static inline int putused_kern(struct vring_used_elem *dst,
const struct vring_used_elem *src,
unsigned int num)
{
memcpy(dst, src, num * sizeof(*dst));
return 0;
}
static inline int xfer_kern(void *src, void *dst, size_t len)
{
memcpy(dst, src, len);
return 0;
}
int vringh_init_kern(struct vringh *vrh, u64 features,
unsigned int num, bool weak_barriers,
struct vring_desc *desc,
struct vring_avail *avail,
struct vring_used *used)
{
if (!num || num > 0xffff || (num & (num - 1))) {
vringh_bad("Bad ring size %u", num);
return -EINVAL;
}
vrh->little_endian = (features & (1ULL << VIRTIO_F_VERSION_1));
vrh->event_indices = (features & (1 << VIRTIO_RING_F_EVENT_IDX));
vrh->weak_barriers = weak_barriers;
vrh->completed = 0;
vrh->last_avail_idx = 0;
vrh->last_used_idx = 0;
vrh->vring.num = num;
vrh->vring.desc = desc;
vrh->vring.avail = avail;
vrh->vring.used = used;
return 0;
}
int vringh_getdesc_kern(struct vringh *vrh,
struct vringh_kiov *riov,
struct vringh_kiov *wiov,
u16 *head,
gfp_t gfp)
{
int err;
err = __vringh_get_head(vrh, getu16_kern, &vrh->last_avail_idx);
if (err < 0)
return err;
if (err == vrh->vring.num)
return 0;
*head = err;
err = __vringh_iov(vrh, *head, riov, wiov, no_range_check, NULL,
gfp, copydesc_kern);
if (err)
return err;
return 1;
}
ssize_t vringh_iov_pull_kern(struct vringh_kiov *riov, void *dst, size_t len)
{
return vringh_iov_xfer(riov, dst, len, xfer_kern);
}
ssize_t vringh_iov_push_kern(struct vringh_kiov *wiov,
const void *src, size_t len)
{
return vringh_iov_xfer(wiov, (void *)src, len, xfer_kern);
}
void vringh_abandon_kern(struct vringh *vrh, unsigned int num)
{
vrh->last_avail_idx -= num;
}
int vringh_complete_kern(struct vringh *vrh, u16 head, u32 len)
{
struct vring_used_elem used;
used.id = cpu_to_vringh32(vrh, head);
used.len = cpu_to_vringh32(vrh, len);
return __vringh_complete(vrh, &used, 1, putu16_kern, putused_kern);
}
bool vringh_notify_enable_kern(struct vringh *vrh)
{
return __vringh_notify_enable(vrh, getu16_kern, putu16_kern);
}
void vringh_notify_disable_kern(struct vringh *vrh)
{
__vringh_notify_disable(vrh, putu16_kern);
}
int vringh_need_notify_kern(struct vringh *vrh)
{
return __vringh_need_notify(vrh, getu16_kern);
}
