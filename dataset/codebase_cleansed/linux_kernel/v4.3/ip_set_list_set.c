static int
list_set_ktest(struct ip_set *set, const struct sk_buff *skb,
const struct xt_action_param *par,
struct ip_set_adt_opt *opt, const struct ip_set_ext *ext)
{
struct list_set *map = set->data;
struct set_elem *e;
u32 cmdflags = opt->cmdflags;
int ret;
opt->cmdflags &= ~IPSET_FLAG_MATCH_COUNTERS;
if (opt->cmdflags & IPSET_FLAG_SKIP_SUBCOUNTER_UPDATE)
opt->cmdflags &= ~IPSET_FLAG_SKIP_COUNTER_UPDATE;
list_for_each_entry_rcu(e, &map->members, list) {
if (SET_WITH_TIMEOUT(set) &&
ip_set_timeout_expired(ext_timeout(e, set)))
continue;
ret = ip_set_test(e->id, skb, par, opt);
if (ret > 0) {
if (SET_WITH_COUNTER(set))
ip_set_update_counter(ext_counter(e, set),
ext, &opt->ext,
cmdflags);
if (SET_WITH_SKBINFO(set))
ip_set_get_skbinfo(ext_skbinfo(e, set),
ext, &opt->ext,
cmdflags);
return ret;
}
}
return 0;
}
static int
list_set_kadd(struct ip_set *set, const struct sk_buff *skb,
const struct xt_action_param *par,
struct ip_set_adt_opt *opt, const struct ip_set_ext *ext)
{
struct list_set *map = set->data;
struct set_elem *e;
int ret;
list_for_each_entry(e, &map->members, list) {
if (SET_WITH_TIMEOUT(set) &&
ip_set_timeout_expired(ext_timeout(e, set)))
continue;
ret = ip_set_add(e->id, skb, par, opt);
if (ret == 0)
return ret;
}
return 0;
}
static int
list_set_kdel(struct ip_set *set, const struct sk_buff *skb,
const struct xt_action_param *par,
struct ip_set_adt_opt *opt, const struct ip_set_ext *ext)
{
struct list_set *map = set->data;
struct set_elem *e;
int ret;
list_for_each_entry(e, &map->members, list) {
if (SET_WITH_TIMEOUT(set) &&
ip_set_timeout_expired(ext_timeout(e, set)))
continue;
ret = ip_set_del(e->id, skb, par, opt);
if (ret == 0)
return ret;
}
return 0;
}
static int
list_set_kadt(struct ip_set *set, const struct sk_buff *skb,
const struct xt_action_param *par,
enum ipset_adt adt, struct ip_set_adt_opt *opt)
{
struct ip_set_ext ext = IP_SET_INIT_KEXT(skb, opt, set);
int ret = -EINVAL;
rcu_read_lock();
switch (adt) {
case IPSET_TEST:
ret = list_set_ktest(set, skb, par, opt, &ext);
break;
case IPSET_ADD:
ret = list_set_kadd(set, skb, par, opt, &ext);
break;
case IPSET_DEL:
ret = list_set_kdel(set, skb, par, opt, &ext);
break;
default:
break;
}
rcu_read_unlock();
return ret;
}
static void
__list_set_del(struct ip_set *set, struct set_elem *e)
{
struct list_set *map = set->data;
ip_set_put_byindex(map->net, e->id);
ip_set_ext_destroy(set, e);
kfree_rcu(e, rcu);
}
static inline void
list_set_del(struct ip_set *set, struct set_elem *e)
{
list_del_rcu(&e->list);
__list_set_del(set, e);
}
static inline void
list_set_replace(struct ip_set *set, struct set_elem *e, struct set_elem *old)
{
list_replace_rcu(&old->list, &e->list);
__list_set_del(set, old);
}
static void
set_cleanup_entries(struct ip_set *set)
{
struct list_set *map = set->data;
struct set_elem *e, *n;
list_for_each_entry_safe(e, n, &map->members, list)
if (ip_set_timeout_expired(ext_timeout(e, set)))
list_set_del(set, e);
}
static int
list_set_utest(struct ip_set *set, void *value, const struct ip_set_ext *ext,
struct ip_set_ext *mext, u32 flags)
{
struct list_set *map = set->data;
struct set_adt_elem *d = value;
struct set_elem *e, *next, *prev = NULL;
int ret;
list_for_each_entry(e, &map->members, list) {
if (SET_WITH_TIMEOUT(set) &&
ip_set_timeout_expired(ext_timeout(e, set)))
continue;
else if (e->id != d->id) {
prev = e;
continue;
}
if (d->before == 0) {
ret = 1;
} else if (d->before > 0) {
next = list_next_entry(e, list);
ret = !list_is_last(&e->list, &map->members) &&
next->id == d->refid;
} else {
ret = prev && prev->id == d->refid;
}
return ret;
}
return 0;
}
static void
list_set_init_extensions(struct ip_set *set, const struct ip_set_ext *ext,
struct set_elem *e)
{
if (SET_WITH_COUNTER(set))
ip_set_init_counter(ext_counter(e, set), ext);
if (SET_WITH_COMMENT(set))
ip_set_init_comment(ext_comment(e, set), ext);
if (SET_WITH_SKBINFO(set))
ip_set_init_skbinfo(ext_skbinfo(e, set), ext);
if (SET_WITH_TIMEOUT(set))
ip_set_timeout_set(ext_timeout(e, set), ext->timeout);
}
static int
list_set_uadd(struct ip_set *set, void *value, const struct ip_set_ext *ext,
struct ip_set_ext *mext, u32 flags)
{
struct list_set *map = set->data;
struct set_adt_elem *d = value;
struct set_elem *e, *n, *prev, *next;
bool flag_exist = flags & IPSET_FLAG_EXIST;
if (SET_WITH_TIMEOUT(set))
set_cleanup_entries(set);
n = prev = next = NULL;
list_for_each_entry(e, &map->members, list) {
if (SET_WITH_TIMEOUT(set) &&
ip_set_timeout_expired(ext_timeout(e, set)))
continue;
else if (d->id == e->id)
n = e;
else if (d->before == 0 || e->id != d->refid)
continue;
else if (d->before > 0)
next = e;
else
prev = e;
}
if (n) {
if ((d->before > 0 && !next) ||
(d->before < 0 && !prev))
return -IPSET_ERR_REF_EXIST;
if (!flag_exist)
return -IPSET_ERR_EXIST;
ip_set_ext_destroy(set, n);
list_set_init_extensions(set, ext, n);
ip_set_put_byindex(map->net, d->id);
return 0;
}
if (d->before == 0) {
n = list_empty(&map->members) ? NULL :
list_last_entry(&map->members, struct set_elem, list);
} else if (d->before > 0) {
if (!list_is_last(&next->list, &map->members))
n = list_next_entry(next, list);
} else {
if (prev->list.prev != &map->members)
n = list_prev_entry(prev, list);
}
if (n &&
!(SET_WITH_TIMEOUT(set) &&
ip_set_timeout_expired(ext_timeout(n, set))))
n = NULL;
e = kzalloc(set->dsize, GFP_ATOMIC);
if (!e)
return -ENOMEM;
e->id = d->id;
INIT_LIST_HEAD(&e->list);
list_set_init_extensions(set, ext, e);
if (n)
list_set_replace(set, e, n);
else if (next)
list_add_tail_rcu(&e->list, &next->list);
else if (prev)
list_add_rcu(&e->list, &prev->list);
else
list_add_tail_rcu(&e->list, &map->members);
return 0;
}
static int
list_set_udel(struct ip_set *set, void *value, const struct ip_set_ext *ext,
struct ip_set_ext *mext, u32 flags)
{
struct list_set *map = set->data;
struct set_adt_elem *d = value;
struct set_elem *e, *next, *prev = NULL;
list_for_each_entry(e, &map->members, list) {
if (SET_WITH_TIMEOUT(set) &&
ip_set_timeout_expired(ext_timeout(e, set)))
continue;
else if (e->id != d->id) {
prev = e;
continue;
}
if (d->before > 0) {
next = list_next_entry(e, list);
if (list_is_last(&e->list, &map->members) ||
next->id != d->refid)
return -IPSET_ERR_REF_EXIST;
} else if (d->before < 0) {
if (!prev || prev->id != d->refid)
return -IPSET_ERR_REF_EXIST;
}
list_set_del(set, e);
return 0;
}
return d->before != 0 ? -IPSET_ERR_REF_EXIST : -IPSET_ERR_EXIST;
}
static int
list_set_uadt(struct ip_set *set, struct nlattr *tb[],
enum ipset_adt adt, u32 *lineno, u32 flags, bool retried)
{
struct list_set *map = set->data;
ipset_adtfn adtfn = set->variant->adt[adt];
struct set_adt_elem e = { .refid = IPSET_INVALID_ID };
struct ip_set_ext ext = IP_SET_INIT_UEXT(set);
struct ip_set *s;
int ret = 0;
if (tb[IPSET_ATTR_LINENO])
*lineno = nla_get_u32(tb[IPSET_ATTR_LINENO]);
if (unlikely(!tb[IPSET_ATTR_NAME] ||
!ip_set_optattr_netorder(tb, IPSET_ATTR_CADT_FLAGS)))
return -IPSET_ERR_PROTOCOL;
ret = ip_set_get_extensions(set, tb, &ext);
if (ret)
return ret;
e.id = ip_set_get_byname(map->net, nla_data(tb[IPSET_ATTR_NAME]), &s);
if (e.id == IPSET_INVALID_ID)
return -IPSET_ERR_NAME;
if (s->type->features & IPSET_TYPE_NAME) {
ret = -IPSET_ERR_LOOP;
goto finish;
}
if (tb[IPSET_ATTR_CADT_FLAGS]) {
u32 f = ip_set_get_h32(tb[IPSET_ATTR_CADT_FLAGS]);
e.before = f & IPSET_FLAG_BEFORE;
}
if (e.before && !tb[IPSET_ATTR_NAMEREF]) {
ret = -IPSET_ERR_BEFORE;
goto finish;
}
if (tb[IPSET_ATTR_NAMEREF]) {
e.refid = ip_set_get_byname(map->net,
nla_data(tb[IPSET_ATTR_NAMEREF]),
&s);
if (e.refid == IPSET_INVALID_ID) {
ret = -IPSET_ERR_NAMEREF;
goto finish;
}
if (!e.before)
e.before = -1;
}
if (adt != IPSET_TEST && SET_WITH_TIMEOUT(set))
set_cleanup_entries(set);
ret = adtfn(set, &e, &ext, &ext, flags);
finish:
if (e.refid != IPSET_INVALID_ID)
ip_set_put_byindex(map->net, e.refid);
if (adt != IPSET_ADD || ret)
ip_set_put_byindex(map->net, e.id);
return ip_set_eexist(ret, flags) ? 0 : ret;
}
static void
list_set_flush(struct ip_set *set)
{
struct list_set *map = set->data;
struct set_elem *e, *n;
list_for_each_entry_safe(e, n, &map->members, list)
list_set_del(set, e);
}
static void
list_set_destroy(struct ip_set *set)
{
struct list_set *map = set->data;
struct set_elem *e, *n;
if (SET_WITH_TIMEOUT(set))
del_timer_sync(&map->gc);
list_for_each_entry_safe(e, n, &map->members, list) {
list_del(&e->list);
ip_set_put_byindex(map->net, e->id);
ip_set_ext_destroy(set, e);
kfree(e);
}
kfree(map);
set->data = NULL;
}
static int
list_set_head(struct ip_set *set, struct sk_buff *skb)
{
const struct list_set *map = set->data;
struct nlattr *nested;
struct set_elem *e;
u32 n = 0;
list_for_each_entry(e, &map->members, list)
n++;
nested = ipset_nest_start(skb, IPSET_ATTR_DATA);
if (!nested)
goto nla_put_failure;
if (nla_put_net32(skb, IPSET_ATTR_SIZE, htonl(map->size)) ||
nla_put_net32(skb, IPSET_ATTR_REFERENCES, htonl(set->ref - 1)) ||
nla_put_net32(skb, IPSET_ATTR_MEMSIZE,
htonl(sizeof(*map) + n * set->dsize)))
goto nla_put_failure;
if (unlikely(ip_set_put_flags(skb, set)))
goto nla_put_failure;
ipset_nest_end(skb, nested);
return 0;
nla_put_failure:
return -EMSGSIZE;
}
static int
list_set_list(const struct ip_set *set,
struct sk_buff *skb, struct netlink_callback *cb)
{
const struct list_set *map = set->data;
struct nlattr *atd, *nested;
u32 i = 0, first = cb->args[IPSET_CB_ARG0];
struct set_elem *e;
int ret = 0;
atd = ipset_nest_start(skb, IPSET_ATTR_ADT);
if (!atd)
return -EMSGSIZE;
list_for_each_entry(e, &map->members, list) {
if (i == first)
break;
i++;
}
rcu_read_lock();
list_for_each_entry_from(e, &map->members, list) {
i++;
if (SET_WITH_TIMEOUT(set) &&
ip_set_timeout_expired(ext_timeout(e, set)))
continue;
nested = ipset_nest_start(skb, IPSET_ATTR_DATA);
if (!nested) {
if (i == first) {
nla_nest_cancel(skb, atd);
ret = -EMSGSIZE;
goto out;
}
goto nla_put_failure;
}
if (nla_put_string(skb, IPSET_ATTR_NAME,
ip_set_name_byindex(map->net, e->id)))
goto nla_put_failure;
if (ip_set_put_extensions(skb, set, e, true))
goto nla_put_failure;
ipset_nest_end(skb, nested);
}
ipset_nest_end(skb, atd);
cb->args[IPSET_CB_ARG0] = 0;
goto out;
nla_put_failure:
nla_nest_cancel(skb, nested);
if (unlikely(i == first)) {
cb->args[IPSET_CB_ARG0] = 0;
ret = -EMSGSIZE;
}
cb->args[IPSET_CB_ARG0] = i - 1;
ipset_nest_end(skb, atd);
out:
rcu_read_unlock();
return ret;
}
static bool
list_set_same_set(const struct ip_set *a, const struct ip_set *b)
{
const struct list_set *x = a->data;
const struct list_set *y = b->data;
return x->size == y->size &&
a->timeout == b->timeout &&
a->extensions == b->extensions;
}
static void
list_set_gc(unsigned long ul_set)
{
struct ip_set *set = (struct ip_set *)ul_set;
struct list_set *map = set->data;
spin_lock_bh(&set->lock);
set_cleanup_entries(set);
spin_unlock_bh(&set->lock);
map->gc.expires = jiffies + IPSET_GC_PERIOD(set->timeout) * HZ;
add_timer(&map->gc);
}
static void
list_set_gc_init(struct ip_set *set, void (*gc)(unsigned long ul_set))
{
struct list_set *map = set->data;
init_timer(&map->gc);
map->gc.data = (unsigned long)set;
map->gc.function = gc;
map->gc.expires = jiffies + IPSET_GC_PERIOD(set->timeout) * HZ;
add_timer(&map->gc);
}
static bool
init_list_set(struct net *net, struct ip_set *set, u32 size)
{
struct list_set *map;
map = kzalloc(sizeof(*map), GFP_KERNEL);
if (!map)
return false;
map->size = size;
map->net = net;
INIT_LIST_HEAD(&map->members);
set->data = map;
return true;
}
static int
list_set_create(struct net *net, struct ip_set *set, struct nlattr *tb[],
u32 flags)
{
u32 size = IP_SET_LIST_DEFAULT_SIZE;
if (unlikely(!ip_set_optattr_netorder(tb, IPSET_ATTR_SIZE) ||
!ip_set_optattr_netorder(tb, IPSET_ATTR_TIMEOUT) ||
!ip_set_optattr_netorder(tb, IPSET_ATTR_CADT_FLAGS)))
return -IPSET_ERR_PROTOCOL;
if (tb[IPSET_ATTR_SIZE])
size = ip_set_get_h32(tb[IPSET_ATTR_SIZE]);
if (size < IP_SET_LIST_MIN_SIZE)
size = IP_SET_LIST_MIN_SIZE;
set->variant = &set_variant;
set->dsize = ip_set_elem_len(set, tb, sizeof(struct set_elem));
if (!init_list_set(net, set, size))
return -ENOMEM;
if (tb[IPSET_ATTR_TIMEOUT]) {
set->timeout = ip_set_timeout_uget(tb[IPSET_ATTR_TIMEOUT]);
list_set_gc_init(set, list_set_gc);
}
return 0;
}
static int __init
list_set_init(void)
{
return ip_set_type_register(&list_set_type);
}
static void __exit
list_set_fini(void)
{
rcu_barrier();
ip_set_type_unregister(&list_set_type);
}
