static inline u32
ip_to_id(const struct bitmap_ip *m, u32 ip)
{
return ((ip & ip_set_hostmask(m->netmask)) - m->first_ip)/m->hosts;
}
static int
bitmap_ip_test(struct ip_set *set, void *value, u32 timeout, u32 flags)
{
const struct bitmap_ip *map = set->data;
u16 id = *(u16 *)value;
return !!test_bit(id, map->members);
}
static int
bitmap_ip_add(struct ip_set *set, void *value, u32 timeout, u32 flags)
{
struct bitmap_ip *map = set->data;
u16 id = *(u16 *)value;
if (test_and_set_bit(id, map->members))
return -IPSET_ERR_EXIST;
return 0;
}
static int
bitmap_ip_del(struct ip_set *set, void *value, u32 timeout, u32 flags)
{
struct bitmap_ip *map = set->data;
u16 id = *(u16 *)value;
if (!test_and_clear_bit(id, map->members))
return -IPSET_ERR_EXIST;
return 0;
}
static int
bitmap_ip_list(const struct ip_set *set,
struct sk_buff *skb, struct netlink_callback *cb)
{
const struct bitmap_ip *map = set->data;
struct nlattr *atd, *nested;
u32 id, first = cb->args[2];
atd = ipset_nest_start(skb, IPSET_ATTR_ADT);
if (!atd)
return -EMSGSIZE;
for (; cb->args[2] < map->elements; cb->args[2]++) {
id = cb->args[2];
if (!test_bit(id, map->members))
continue;
nested = ipset_nest_start(skb, IPSET_ATTR_DATA);
if (!nested) {
if (id == first) {
nla_nest_cancel(skb, atd);
return -EMSGSIZE;
} else
goto nla_put_failure;
}
if (nla_put_ipaddr4(skb, IPSET_ATTR_IP,
htonl(map->first_ip + id * map->hosts)))
goto nla_put_failure;
ipset_nest_end(skb, nested);
}
ipset_nest_end(skb, atd);
cb->args[2] = 0;
return 0;
nla_put_failure:
nla_nest_cancel(skb, nested);
ipset_nest_end(skb, atd);
if (unlikely(id == first)) {
cb->args[2] = 0;
return -EMSGSIZE;
}
return 0;
}
static int
bitmap_ip_ttest(struct ip_set *set, void *value, u32 timeout, u32 flags)
{
const struct bitmap_ip *map = set->data;
const unsigned long *members = map->members;
u16 id = *(u16 *)value;
return ip_set_timeout_test(members[id]);
}
static int
bitmap_ip_tadd(struct ip_set *set, void *value, u32 timeout, u32 flags)
{
struct bitmap_ip *map = set->data;
unsigned long *members = map->members;
u16 id = *(u16 *)value;
if (ip_set_timeout_test(members[id]) && !(flags & IPSET_FLAG_EXIST))
return -IPSET_ERR_EXIST;
members[id] = ip_set_timeout_set(timeout);
return 0;
}
static int
bitmap_ip_tdel(struct ip_set *set, void *value, u32 timeout, u32 flags)
{
struct bitmap_ip *map = set->data;
unsigned long *members = map->members;
u16 id = *(u16 *)value;
int ret = -IPSET_ERR_EXIST;
if (ip_set_timeout_test(members[id]))
ret = 0;
members[id] = IPSET_ELEM_UNSET;
return ret;
}
static int
bitmap_ip_tlist(const struct ip_set *set,
struct sk_buff *skb, struct netlink_callback *cb)
{
const struct bitmap_ip *map = set->data;
struct nlattr *adt, *nested;
u32 id, first = cb->args[2];
const unsigned long *members = map->members;
adt = ipset_nest_start(skb, IPSET_ATTR_ADT);
if (!adt)
return -EMSGSIZE;
for (; cb->args[2] < map->elements; cb->args[2]++) {
id = cb->args[2];
if (!ip_set_timeout_test(members[id]))
continue;
nested = ipset_nest_start(skb, IPSET_ATTR_DATA);
if (!nested) {
if (id == first) {
nla_nest_cancel(skb, adt);
return -EMSGSIZE;
} else
goto nla_put_failure;
}
if (nla_put_ipaddr4(skb, IPSET_ATTR_IP,
htonl(map->first_ip + id * map->hosts)) ||
nla_put_net32(skb, IPSET_ATTR_TIMEOUT,
htonl(ip_set_timeout_get(members[id]))))
goto nla_put_failure;
ipset_nest_end(skb, nested);
}
ipset_nest_end(skb, adt);
cb->args[2] = 0;
return 0;
nla_put_failure:
nla_nest_cancel(skb, nested);
ipset_nest_end(skb, adt);
if (unlikely(id == first)) {
cb->args[2] = 0;
return -EMSGSIZE;
}
return 0;
}
static int
bitmap_ip_kadt(struct ip_set *set, const struct sk_buff *skb,
const struct xt_action_param *par,
enum ipset_adt adt, const struct ip_set_adt_opt *opt)
{
struct bitmap_ip *map = set->data;
ipset_adtfn adtfn = set->variant->adt[adt];
u32 ip;
ip = ntohl(ip4addr(skb, opt->flags & IPSET_DIM_ONE_SRC));
if (ip < map->first_ip || ip > map->last_ip)
return -IPSET_ERR_BITMAP_RANGE;
ip = ip_to_id(map, ip);
return adtfn(set, &ip, opt_timeout(opt, map), opt->cmdflags);
}
static int
bitmap_ip_uadt(struct ip_set *set, struct nlattr *tb[],
enum ipset_adt adt, u32 *lineno, u32 flags, bool retried)
{
struct bitmap_ip *map = set->data;
ipset_adtfn adtfn = set->variant->adt[adt];
u32 timeout = map->timeout;
u32 ip, ip_to, id;
int ret = 0;
if (unlikely(!tb[IPSET_ATTR_IP] ||
!ip_set_optattr_netorder(tb, IPSET_ATTR_TIMEOUT)))
return -IPSET_ERR_PROTOCOL;
if (tb[IPSET_ATTR_LINENO])
*lineno = nla_get_u32(tb[IPSET_ATTR_LINENO]);
ret = ip_set_get_hostipaddr4(tb[IPSET_ATTR_IP], &ip);
if (ret)
return ret;
if (ip < map->first_ip || ip > map->last_ip)
return -IPSET_ERR_BITMAP_RANGE;
if (tb[IPSET_ATTR_TIMEOUT]) {
if (!with_timeout(map->timeout))
return -IPSET_ERR_TIMEOUT;
timeout = ip_set_timeout_uget(tb[IPSET_ATTR_TIMEOUT]);
}
if (adt == IPSET_TEST) {
id = ip_to_id(map, ip);
return adtfn(set, &id, timeout, flags);
}
if (tb[IPSET_ATTR_IP_TO]) {
ret = ip_set_get_hostipaddr4(tb[IPSET_ATTR_IP_TO], &ip_to);
if (ret)
return ret;
if (ip > ip_to) {
swap(ip, ip_to);
if (ip < map->first_ip)
return -IPSET_ERR_BITMAP_RANGE;
}
} else if (tb[IPSET_ATTR_CIDR]) {
u8 cidr = nla_get_u8(tb[IPSET_ATTR_CIDR]);
if (cidr > 32)
return -IPSET_ERR_INVALID_CIDR;
ip_set_mask_from_to(ip, ip_to, cidr);
} else
ip_to = ip;
if (ip_to > map->last_ip)
return -IPSET_ERR_BITMAP_RANGE;
for (; !before(ip_to, ip); ip += map->hosts) {
id = ip_to_id(map, ip);
ret = adtfn(set, &id, timeout, flags);
if (ret && !ip_set_eexist(ret, flags))
return ret;
else
ret = 0;
}
return ret;
}
static void
bitmap_ip_destroy(struct ip_set *set)
{
struct bitmap_ip *map = set->data;
if (with_timeout(map->timeout))
del_timer_sync(&map->gc);
ip_set_free(map->members);
kfree(map);
set->data = NULL;
}
static void
bitmap_ip_flush(struct ip_set *set)
{
struct bitmap_ip *map = set->data;
memset(map->members, 0, map->memsize);
}
static int
bitmap_ip_head(struct ip_set *set, struct sk_buff *skb)
{
const struct bitmap_ip *map = set->data;
struct nlattr *nested;
nested = ipset_nest_start(skb, IPSET_ATTR_DATA);
if (!nested)
goto nla_put_failure;
if (nla_put_ipaddr4(skb, IPSET_ATTR_IP, htonl(map->first_ip)) ||
nla_put_ipaddr4(skb, IPSET_ATTR_IP_TO, htonl(map->last_ip)) ||
(map->netmask != 32 &&
nla_put_u8(skb, IPSET_ATTR_NETMASK, map->netmask)) ||
nla_put_net32(skb, IPSET_ATTR_REFERENCES, htonl(set->ref - 1)) ||
nla_put_net32(skb, IPSET_ATTR_MEMSIZE,
htonl(sizeof(*map) + map->memsize)) ||
(with_timeout(map->timeout) &&
nla_put_net32(skb, IPSET_ATTR_TIMEOUT, htonl(map->timeout))))
goto nla_put_failure;
ipset_nest_end(skb, nested);
return 0;
nla_put_failure:
return -EMSGSIZE;
}
static bool
bitmap_ip_same_set(const struct ip_set *a, const struct ip_set *b)
{
const struct bitmap_ip *x = a->data;
const struct bitmap_ip *y = b->data;
return x->first_ip == y->first_ip &&
x->last_ip == y->last_ip &&
x->netmask == y->netmask &&
x->timeout == y->timeout;
}
static void
bitmap_ip_gc(unsigned long ul_set)
{
struct ip_set *set = (struct ip_set *) ul_set;
struct bitmap_ip *map = set->data;
unsigned long *table = map->members;
u32 id;
read_lock_bh(&set->lock);
for (id = 0; id < map->elements; id++)
if (ip_set_timeout_expired(table[id]))
table[id] = IPSET_ELEM_UNSET;
read_unlock_bh(&set->lock);
map->gc.expires = jiffies + IPSET_GC_PERIOD(map->timeout) * HZ;
add_timer(&map->gc);
}
static void
bitmap_ip_gc_init(struct ip_set *set)
{
struct bitmap_ip *map = set->data;
init_timer(&map->gc);
map->gc.data = (unsigned long) set;
map->gc.function = bitmap_ip_gc;
map->gc.expires = jiffies + IPSET_GC_PERIOD(map->timeout) * HZ;
add_timer(&map->gc);
}
static bool
init_map_ip(struct ip_set *set, struct bitmap_ip *map,
u32 first_ip, u32 last_ip,
u32 elements, u32 hosts, u8 netmask)
{
map->members = ip_set_alloc(map->memsize);
if (!map->members)
return false;
map->first_ip = first_ip;
map->last_ip = last_ip;
map->elements = elements;
map->hosts = hosts;
map->netmask = netmask;
map->timeout = IPSET_NO_TIMEOUT;
set->data = map;
set->family = NFPROTO_IPV4;
return true;
}
static int
bitmap_ip_create(struct ip_set *set, struct nlattr *tb[], u32 flags)
{
struct bitmap_ip *map;
u32 first_ip, last_ip, hosts, elements;
u8 netmask = 32;
int ret;
if (unlikely(!tb[IPSET_ATTR_IP] ||
!ip_set_optattr_netorder(tb, IPSET_ATTR_TIMEOUT)))
return -IPSET_ERR_PROTOCOL;
ret = ip_set_get_hostipaddr4(tb[IPSET_ATTR_IP], &first_ip);
if (ret)
return ret;
if (tb[IPSET_ATTR_IP_TO]) {
ret = ip_set_get_hostipaddr4(tb[IPSET_ATTR_IP_TO], &last_ip);
if (ret)
return ret;
if (first_ip > last_ip) {
u32 tmp = first_ip;
first_ip = last_ip;
last_ip = tmp;
}
} else if (tb[IPSET_ATTR_CIDR]) {
u8 cidr = nla_get_u8(tb[IPSET_ATTR_CIDR]);
if (cidr >= 32)
return -IPSET_ERR_INVALID_CIDR;
ip_set_mask_from_to(first_ip, last_ip, cidr);
} else
return -IPSET_ERR_PROTOCOL;
if (tb[IPSET_ATTR_NETMASK]) {
netmask = nla_get_u8(tb[IPSET_ATTR_NETMASK]);
if (netmask > 32)
return -IPSET_ERR_INVALID_NETMASK;
first_ip &= ip_set_hostmask(netmask);
last_ip |= ~ip_set_hostmask(netmask);
}
if (netmask == 32) {
hosts = 1;
elements = last_ip - first_ip + 1;
} else {
u8 mask_bits;
u32 mask;
mask = range_to_mask(first_ip, last_ip, &mask_bits);
if ((!mask && (first_ip || last_ip != 0xFFFFFFFF)) ||
netmask <= mask_bits)
return -IPSET_ERR_BITMAP_RANGE;
pr_debug("mask_bits %u, netmask %u\n", mask_bits, netmask);
hosts = 2 << (32 - netmask - 1);
elements = 2 << (netmask - mask_bits - 1);
}
if (elements > IPSET_BITMAP_MAX_RANGE + 1)
return -IPSET_ERR_BITMAP_RANGE_SIZE;
pr_debug("hosts %u, elements %u\n", hosts, elements);
map = kzalloc(sizeof(*map), GFP_KERNEL);
if (!map)
return -ENOMEM;
if (tb[IPSET_ATTR_TIMEOUT]) {
map->memsize = elements * sizeof(unsigned long);
if (!init_map_ip(set, map, first_ip, last_ip,
elements, hosts, netmask)) {
kfree(map);
return -ENOMEM;
}
map->timeout = ip_set_timeout_uget(tb[IPSET_ATTR_TIMEOUT]);
set->variant = &bitmap_tip;
bitmap_ip_gc_init(set);
} else {
map->memsize = bitmap_bytes(0, elements - 1);
if (!init_map_ip(set, map, first_ip, last_ip,
elements, hosts, netmask)) {
kfree(map);
return -ENOMEM;
}
set->variant = &bitmap_ip;
}
return 0;
}
static int __init
bitmap_ip_init(void)
{
return ip_set_type_register(&bitmap_ip_type);
}
static void __exit
bitmap_ip_fini(void)
{
ip_set_type_unregister(&bitmap_ip_type);
}
