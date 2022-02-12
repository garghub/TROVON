static void xprt_switch_add_xprt_locked(struct rpc_xprt_switch *xps,
struct rpc_xprt *xprt)
{
if (unlikely(xprt_get(xprt) == NULL))
return;
list_add_tail_rcu(&xprt->xprt_switch, &xps->xps_xprt_list);
smp_wmb();
if (xps->xps_nxprts == 0)
xps->xps_net = xprt->xprt_net;
xps->xps_nxprts++;
}
void rpc_xprt_switch_add_xprt(struct rpc_xprt_switch *xps,
struct rpc_xprt *xprt)
{
if (xprt == NULL)
return;
spin_lock(&xps->xps_lock);
if (xps->xps_net == xprt->xprt_net || xps->xps_net == NULL)
xprt_switch_add_xprt_locked(xps, xprt);
spin_unlock(&xps->xps_lock);
}
static void xprt_switch_remove_xprt_locked(struct rpc_xprt_switch *xps,
struct rpc_xprt *xprt)
{
if (unlikely(xprt == NULL))
return;
xps->xps_nxprts--;
if (xps->xps_nxprts == 0)
xps->xps_net = NULL;
smp_wmb();
list_del_rcu(&xprt->xprt_switch);
}
void rpc_xprt_switch_remove_xprt(struct rpc_xprt_switch *xps,
struct rpc_xprt *xprt)
{
spin_lock(&xps->xps_lock);
xprt_switch_remove_xprt_locked(xps, xprt);
spin_unlock(&xps->xps_lock);
xprt_put(xprt);
}
struct rpc_xprt_switch *xprt_switch_alloc(struct rpc_xprt *xprt,
gfp_t gfp_flags)
{
struct rpc_xprt_switch *xps;
xps = kmalloc(sizeof(*xps), gfp_flags);
if (xps != NULL) {
spin_lock_init(&xps->xps_lock);
kref_init(&xps->xps_kref);
xps->xps_nxprts = 0;
INIT_LIST_HEAD(&xps->xps_xprt_list);
xps->xps_iter_ops = &rpc_xprt_iter_singular;
xprt_switch_add_xprt_locked(xps, xprt);
}
return xps;
}
static void xprt_switch_free_entries(struct rpc_xprt_switch *xps)
{
spin_lock(&xps->xps_lock);
while (!list_empty(&xps->xps_xprt_list)) {
struct rpc_xprt *xprt;
xprt = list_first_entry(&xps->xps_xprt_list,
struct rpc_xprt, xprt_switch);
xprt_switch_remove_xprt_locked(xps, xprt);
spin_unlock(&xps->xps_lock);
xprt_put(xprt);
spin_lock(&xps->xps_lock);
}
spin_unlock(&xps->xps_lock);
}
static void xprt_switch_free(struct kref *kref)
{
struct rpc_xprt_switch *xps = container_of(kref,
struct rpc_xprt_switch, xps_kref);
xprt_switch_free_entries(xps);
kfree_rcu(xps, xps_rcu);
}
struct rpc_xprt_switch *xprt_switch_get(struct rpc_xprt_switch *xps)
{
if (xps != NULL && kref_get_unless_zero(&xps->xps_kref))
return xps;
return NULL;
}
void xprt_switch_put(struct rpc_xprt_switch *xps)
{
if (xps != NULL)
kref_put(&xps->xps_kref, xprt_switch_free);
}
void rpc_xprt_switch_set_roundrobin(struct rpc_xprt_switch *xps)
{
if (READ_ONCE(xps->xps_iter_ops) != &rpc_xprt_iter_roundrobin)
WRITE_ONCE(xps->xps_iter_ops, &rpc_xprt_iter_roundrobin);
}
static
const struct rpc_xprt_iter_ops *xprt_iter_ops(const struct rpc_xprt_iter *xpi)
{
if (xpi->xpi_ops != NULL)
return xpi->xpi_ops;
return rcu_dereference(xpi->xpi_xpswitch)->xps_iter_ops;
}
static
void xprt_iter_no_rewind(struct rpc_xprt_iter *xpi)
{
}
static
void xprt_iter_default_rewind(struct rpc_xprt_iter *xpi)
{
WRITE_ONCE(xpi->xpi_cursor, NULL);
}
static
struct rpc_xprt *xprt_switch_find_first_entry(struct list_head *head)
{
return list_first_or_null_rcu(head, struct rpc_xprt, xprt_switch);
}
static
struct rpc_xprt *xprt_iter_first_entry(struct rpc_xprt_iter *xpi)
{
struct rpc_xprt_switch *xps = rcu_dereference(xpi->xpi_xpswitch);
if (xps == NULL)
return NULL;
return xprt_switch_find_first_entry(&xps->xps_xprt_list);
}
static
struct rpc_xprt *xprt_switch_find_current_entry(struct list_head *head,
const struct rpc_xprt *cur)
{
struct rpc_xprt *pos;
list_for_each_entry_rcu(pos, head, xprt_switch) {
if (cur == pos)
return pos;
}
return NULL;
}
static
struct rpc_xprt *xprt_iter_current_entry(struct rpc_xprt_iter *xpi)
{
struct rpc_xprt_switch *xps = rcu_dereference(xpi->xpi_xpswitch);
struct list_head *head;
if (xps == NULL)
return NULL;
head = &xps->xps_xprt_list;
if (xpi->xpi_cursor == NULL || xps->xps_nxprts < 2)
return xprt_switch_find_first_entry(head);
return xprt_switch_find_current_entry(head, xpi->xpi_cursor);
}
static
struct rpc_xprt *xprt_switch_find_next_entry(struct list_head *head,
const struct rpc_xprt *cur)
{
struct rpc_xprt *pos, *prev = NULL;
list_for_each_entry_rcu(pos, head, xprt_switch) {
if (cur == prev)
return pos;
prev = pos;
}
return NULL;
}
static
struct rpc_xprt *xprt_switch_set_next_cursor(struct list_head *head,
struct rpc_xprt **cursor,
xprt_switch_find_xprt_t find_next)
{
struct rpc_xprt *cur, *pos, *old;
cur = READ_ONCE(*cursor);
for (;;) {
old = cur;
pos = find_next(head, old);
if (pos == NULL)
break;
cur = cmpxchg_relaxed(cursor, old, pos);
if (cur == old)
break;
}
return pos;
}
static
struct rpc_xprt *xprt_iter_next_entry_multiple(struct rpc_xprt_iter *xpi,
xprt_switch_find_xprt_t find_next)
{
struct rpc_xprt_switch *xps = rcu_dereference(xpi->xpi_xpswitch);
if (xps == NULL)
return NULL;
return xprt_switch_set_next_cursor(&xps->xps_xprt_list,
&xpi->xpi_cursor,
find_next);
}
static
struct rpc_xprt *xprt_switch_find_next_entry_roundrobin(struct list_head *head,
const struct rpc_xprt *cur)
{
struct rpc_xprt *ret;
ret = xprt_switch_find_next_entry(head, cur);
if (ret != NULL)
return ret;
return xprt_switch_find_first_entry(head);
}
static
struct rpc_xprt *xprt_iter_next_entry_roundrobin(struct rpc_xprt_iter *xpi)
{
return xprt_iter_next_entry_multiple(xpi,
xprt_switch_find_next_entry_roundrobin);
}
static
struct rpc_xprt *xprt_iter_next_entry_all(struct rpc_xprt_iter *xpi)
{
return xprt_iter_next_entry_multiple(xpi, xprt_switch_find_next_entry);
}
static
void xprt_iter_rewind(struct rpc_xprt_iter *xpi)
{
rcu_read_lock();
xprt_iter_ops(xpi)->xpi_rewind(xpi);
rcu_read_unlock();
}
static void __xprt_iter_init(struct rpc_xprt_iter *xpi,
struct rpc_xprt_switch *xps,
const struct rpc_xprt_iter_ops *ops)
{
rcu_assign_pointer(xpi->xpi_xpswitch, xprt_switch_get(xps));
xpi->xpi_cursor = NULL;
xpi->xpi_ops = ops;
}
void xprt_iter_init(struct rpc_xprt_iter *xpi,
struct rpc_xprt_switch *xps)
{
__xprt_iter_init(xpi, xps, NULL);
}
void xprt_iter_init_listall(struct rpc_xprt_iter *xpi,
struct rpc_xprt_switch *xps)
{
__xprt_iter_init(xpi, xps, &rpc_xprt_iter_listall);
}
struct rpc_xprt_switch *xprt_iter_xchg_switch(struct rpc_xprt_iter *xpi,
struct rpc_xprt_switch *newswitch)
{
struct rpc_xprt_switch __rcu *oldswitch;
oldswitch = xchg(&xpi->xpi_xpswitch, RCU_INITIALIZER(newswitch));
if (newswitch != NULL)
xprt_iter_rewind(xpi);
return rcu_dereference_protected(oldswitch, true);
}
void xprt_iter_destroy(struct rpc_xprt_iter *xpi)
{
xprt_switch_put(xprt_iter_xchg_switch(xpi, NULL));
}
struct rpc_xprt *xprt_iter_xprt(struct rpc_xprt_iter *xpi)
{
WARN_ON_ONCE(!rcu_read_lock_held());
return xprt_iter_ops(xpi)->xpi_xprt(xpi);
}
struct rpc_xprt *xprt_iter_get_xprt(struct rpc_xprt_iter *xpi)
{
struct rpc_xprt *xprt;
rcu_read_lock();
xprt = xprt_iter_get_helper(xpi, xprt_iter_ops(xpi)->xpi_xprt);
rcu_read_unlock();
return xprt;
}
struct rpc_xprt *xprt_iter_get_next(struct rpc_xprt_iter *xpi)
{
struct rpc_xprt *xprt;
rcu_read_lock();
xprt = xprt_iter_get_helper(xpi, xprt_iter_ops(xpi)->xpi_next);
rcu_read_unlock();
return xprt;
}
