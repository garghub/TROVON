static inline void *
bitmap_ipmac_elem(const struct bitmap_ipmac *map, u32 id)
{
return (void *)((char *)map->members + id * map->dsize);
}
static inline bool
bitmap_timeout(const struct bitmap_ipmac *map, u32 id)
{
const struct ipmac_telem *elem = bitmap_ipmac_elem(map, id);
return ip_set_timeout_test(elem->timeout);
}
static inline bool
bitmap_expired(const struct bitmap_ipmac *map, u32 id)
{
const struct ipmac_telem *elem = bitmap_ipmac_elem(map, id);
return ip_set_timeout_expired(elem->timeout);
}
static inline int
bitmap_ipmac_exist(const struct ipmac_telem *elem)
{
return elem->match == MAC_UNSET ||
(elem->match == MAC_FILLED &&
!ip_set_timeout_expired(elem->timeout));
}
static int
bitmap_ipmac_test(struct ip_set *set, void *value, u32 timeout, u32 flags)
{
const struct bitmap_ipmac *map = set->data;
const struct ipmac *data = value;
const struct ipmac_elem *elem = bitmap_ipmac_elem(map, data->id);
switch (elem->match) {
case MAC_UNSET:
return -EAGAIN;
case MAC_FILLED:
return data->ether == NULL ||
compare_ether_addr(data->ether, elem->ether) == 0;
}
return 0;
}
static int
bitmap_ipmac_add(struct ip_set *set, void *value, u32 timeout, u32 flags)
{
struct bitmap_ipmac *map = set->data;
const struct ipmac *data = value;
struct ipmac_elem *elem = bitmap_ipmac_elem(map, data->id);
switch (elem->match) {
case MAC_UNSET:
if (!data->ether)
return -IPSET_ERR_EXIST;
memcpy(elem->ether, data->ether, ETH_ALEN);
elem->match = MAC_FILLED;
break;
case MAC_FILLED:
return -IPSET_ERR_EXIST;
case MAC_EMPTY:
if (data->ether) {
memcpy(elem->ether, data->ether, ETH_ALEN);
elem->match = MAC_FILLED;
} else
elem->match = MAC_UNSET;
}
return 0;
}
static int
bitmap_ipmac_del(struct ip_set *set, void *value, u32 timeout, u32 flags)
{
struct bitmap_ipmac *map = set->data;
const struct ipmac *data = value;
struct ipmac_elem *elem = bitmap_ipmac_elem(map, data->id);
if (elem->match == MAC_EMPTY)
return -IPSET_ERR_EXIST;
elem->match = MAC_EMPTY;
return 0;
}
static int
bitmap_ipmac_list(const struct ip_set *set,
struct sk_buff *skb, struct netlink_callback *cb)
{
const struct bitmap_ipmac *map = set->data;
const struct ipmac_elem *elem;
struct nlattr *atd, *nested;
u32 id, first = cb->args[2];
u32 last = map->last_ip - map->first_ip;
atd = ipset_nest_start(skb, IPSET_ATTR_ADT);
if (!atd)
return -EMSGSIZE;
for (; cb->args[2] <= last; cb->args[2]++) {
id = cb->args[2];
elem = bitmap_ipmac_elem(map, id);
if (elem->match == MAC_EMPTY)
continue;
nested = ipset_nest_start(skb, IPSET_ATTR_DATA);
if (!nested) {
if (id == first) {
nla_nest_cancel(skb, atd);
return -EMSGSIZE;
} else
goto nla_put_failure;
}
NLA_PUT_IPADDR4(skb, IPSET_ATTR_IP,
htonl(map->first_ip + id));
if (elem->match == MAC_FILLED)
NLA_PUT(skb, IPSET_ATTR_ETHER, ETH_ALEN,
elem->ether);
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
bitmap_ipmac_ttest(struct ip_set *set, void *value, u32 timeout, u32 flags)
{
const struct bitmap_ipmac *map = set->data;
const struct ipmac *data = value;
const struct ipmac_elem *elem = bitmap_ipmac_elem(map, data->id);
switch (elem->match) {
case MAC_UNSET:
return -EAGAIN;
case MAC_FILLED:
return (data->ether == NULL ||
compare_ether_addr(data->ether, elem->ether) == 0) &&
!bitmap_expired(map, data->id);
}
return 0;
}
static int
bitmap_ipmac_tadd(struct ip_set *set, void *value, u32 timeout, u32 flags)
{
struct bitmap_ipmac *map = set->data;
const struct ipmac *data = value;
struct ipmac_telem *elem = bitmap_ipmac_elem(map, data->id);
bool flag_exist = flags & IPSET_FLAG_EXIST;
switch (elem->match) {
case MAC_UNSET:
if (!(data->ether || flag_exist))
return -IPSET_ERR_EXIST;
memcpy(elem->ether, data->ether, ETH_ALEN);
elem->match = MAC_FILLED;
if (timeout == map->timeout)
timeout = elem->timeout;
elem->timeout = ip_set_timeout_set(timeout);
break;
case MAC_FILLED:
if (!(bitmap_expired(map, data->id) || flag_exist))
return -IPSET_ERR_EXIST;
case MAC_EMPTY:
if (data->ether) {
memcpy(elem->ether, data->ether, ETH_ALEN);
elem->match = MAC_FILLED;
} else
elem->match = MAC_UNSET;
elem->timeout = data->ether ? ip_set_timeout_set(timeout)
: timeout;
break;
}
return 0;
}
static int
bitmap_ipmac_tdel(struct ip_set *set, void *value, u32 timeout, u32 flags)
{
struct bitmap_ipmac *map = set->data;
const struct ipmac *data = value;
struct ipmac_telem *elem = bitmap_ipmac_elem(map, data->id);
if (elem->match == MAC_EMPTY || bitmap_expired(map, data->id))
return -IPSET_ERR_EXIST;
elem->match = MAC_EMPTY;
return 0;
}
static int
bitmap_ipmac_tlist(const struct ip_set *set,
struct sk_buff *skb, struct netlink_callback *cb)
{
const struct bitmap_ipmac *map = set->data;
const struct ipmac_telem *elem;
struct nlattr *atd, *nested;
u32 id, first = cb->args[2];
u32 timeout, last = map->last_ip - map->first_ip;
atd = ipset_nest_start(skb, IPSET_ATTR_ADT);
if (!atd)
return -EMSGSIZE;
for (; cb->args[2] <= last; cb->args[2]++) {
id = cb->args[2];
elem = bitmap_ipmac_elem(map, id);
if (!bitmap_ipmac_exist(elem))
continue;
nested = ipset_nest_start(skb, IPSET_ATTR_DATA);
if (!nested) {
if (id == first) {
nla_nest_cancel(skb, atd);
return -EMSGSIZE;
} else
goto nla_put_failure;
}
NLA_PUT_IPADDR4(skb, IPSET_ATTR_IP,
htonl(map->first_ip + id));
if (elem->match == MAC_FILLED)
NLA_PUT(skb, IPSET_ATTR_ETHER, ETH_ALEN,
elem->ether);
timeout = elem->match == MAC_UNSET ? elem->timeout
: ip_set_timeout_get(elem->timeout);
NLA_PUT_NET32(skb, IPSET_ATTR_TIMEOUT, htonl(timeout));
ipset_nest_end(skb, nested);
}
ipset_nest_end(skb, atd);
cb->args[2] = 0;
return 0;
nla_put_failure:
nla_nest_cancel(skb, nested);
ipset_nest_end(skb, atd);
return -EMSGSIZE;
}
static int
bitmap_ipmac_kadt(struct ip_set *set, const struct sk_buff *skb,
const struct xt_action_param *par,
enum ipset_adt adt, const struct ip_set_adt_opt *opt)
{
struct bitmap_ipmac *map = set->data;
ipset_adtfn adtfn = set->variant->adt[adt];
struct ipmac data;
if (!(opt->flags & IPSET_DIM_TWO_SRC))
return 0;
data.id = ntohl(ip4addr(skb, opt->flags & IPSET_DIM_ONE_SRC));
if (data.id < map->first_ip || data.id > map->last_ip)
return -IPSET_ERR_BITMAP_RANGE;
if (skb_mac_header(skb) < skb->head ||
(skb_mac_header(skb) + ETH_HLEN) > skb->data)
return -EINVAL;
data.id -= map->first_ip;
data.ether = eth_hdr(skb)->h_source;
return adtfn(set, &data, opt_timeout(opt, map), opt->cmdflags);
}
static int
bitmap_ipmac_uadt(struct ip_set *set, struct nlattr *tb[],
enum ipset_adt adt, u32 *lineno, u32 flags, bool retried)
{
const struct bitmap_ipmac *map = set->data;
ipset_adtfn adtfn = set->variant->adt[adt];
struct ipmac data;
u32 timeout = map->timeout;
int ret = 0;
if (unlikely(!tb[IPSET_ATTR_IP] ||
!ip_set_optattr_netorder(tb, IPSET_ATTR_TIMEOUT)))
return -IPSET_ERR_PROTOCOL;
if (tb[IPSET_ATTR_LINENO])
*lineno = nla_get_u32(tb[IPSET_ATTR_LINENO]);
ret = ip_set_get_hostipaddr4(tb[IPSET_ATTR_IP], &data.id);
if (ret)
return ret;
if (data.id < map->first_ip || data.id > map->last_ip)
return -IPSET_ERR_BITMAP_RANGE;
if (tb[IPSET_ATTR_ETHER])
data.ether = nla_data(tb[IPSET_ATTR_ETHER]);
else
data.ether = NULL;
if (tb[IPSET_ATTR_TIMEOUT]) {
if (!with_timeout(map->timeout))
return -IPSET_ERR_TIMEOUT;
timeout = ip_set_timeout_uget(tb[IPSET_ATTR_TIMEOUT]);
}
data.id -= map->first_ip;
ret = adtfn(set, &data, timeout, flags);
return ip_set_eexist(ret, flags) ? 0 : ret;
}
static void
bitmap_ipmac_destroy(struct ip_set *set)
{
struct bitmap_ipmac *map = set->data;
if (with_timeout(map->timeout))
del_timer_sync(&map->gc);
ip_set_free(map->members);
kfree(map);
set->data = NULL;
}
static void
bitmap_ipmac_flush(struct ip_set *set)
{
struct bitmap_ipmac *map = set->data;
memset(map->members, 0,
(map->last_ip - map->first_ip + 1) * map->dsize);
}
static int
bitmap_ipmac_head(struct ip_set *set, struct sk_buff *skb)
{
const struct bitmap_ipmac *map = set->data;
struct nlattr *nested;
nested = ipset_nest_start(skb, IPSET_ATTR_DATA);
if (!nested)
goto nla_put_failure;
NLA_PUT_IPADDR4(skb, IPSET_ATTR_IP, htonl(map->first_ip));
NLA_PUT_IPADDR4(skb, IPSET_ATTR_IP_TO, htonl(map->last_ip));
NLA_PUT_NET32(skb, IPSET_ATTR_REFERENCES, htonl(set->ref - 1));
NLA_PUT_NET32(skb, IPSET_ATTR_MEMSIZE,
htonl(sizeof(*map)
+ (map->last_ip - map->first_ip + 1) * map->dsize));
if (with_timeout(map->timeout))
NLA_PUT_NET32(skb, IPSET_ATTR_TIMEOUT, htonl(map->timeout));
ipset_nest_end(skb, nested);
return 0;
nla_put_failure:
return -EMSGSIZE;
}
static bool
bitmap_ipmac_same_set(const struct ip_set *a, const struct ip_set *b)
{
const struct bitmap_ipmac *x = a->data;
const struct bitmap_ipmac *y = b->data;
return x->first_ip == y->first_ip &&
x->last_ip == y->last_ip &&
x->timeout == y->timeout;
}
static void
bitmap_ipmac_gc(unsigned long ul_set)
{
struct ip_set *set = (struct ip_set *) ul_set;
struct bitmap_ipmac *map = set->data;
struct ipmac_telem *elem;
u32 id, last = map->last_ip - map->first_ip;
read_lock_bh(&set->lock);
for (id = 0; id <= last; id++) {
elem = bitmap_ipmac_elem(map, id);
if (elem->match == MAC_FILLED &&
ip_set_timeout_expired(elem->timeout))
elem->match = MAC_EMPTY;
}
read_unlock_bh(&set->lock);
map->gc.expires = jiffies + IPSET_GC_PERIOD(map->timeout) * HZ;
add_timer(&map->gc);
}
static void
bitmap_ipmac_gc_init(struct ip_set *set)
{
struct bitmap_ipmac *map = set->data;
init_timer(&map->gc);
map->gc.data = (unsigned long) set;
map->gc.function = bitmap_ipmac_gc;
map->gc.expires = jiffies + IPSET_GC_PERIOD(map->timeout) * HZ;
add_timer(&map->gc);
}
static bool
init_map_ipmac(struct ip_set *set, struct bitmap_ipmac *map,
u32 first_ip, u32 last_ip)
{
map->members = ip_set_alloc((last_ip - first_ip + 1) * map->dsize);
if (!map->members)
return false;
map->first_ip = first_ip;
map->last_ip = last_ip;
map->timeout = IPSET_NO_TIMEOUT;
set->data = map;
set->family = NFPROTO_IPV4;
return true;
}
static int
bitmap_ipmac_create(struct ip_set *set, struct nlattr *tb[],
u32 flags)
{
u32 first_ip, last_ip, elements;
struct bitmap_ipmac *map;
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
elements = last_ip - first_ip + 1;
if (elements > IPSET_BITMAP_MAX_RANGE + 1)
return -IPSET_ERR_BITMAP_RANGE_SIZE;
map = kzalloc(sizeof(*map), GFP_KERNEL);
if (!map)
return -ENOMEM;
if (tb[IPSET_ATTR_TIMEOUT]) {
map->dsize = sizeof(struct ipmac_telem);
if (!init_map_ipmac(set, map, first_ip, last_ip)) {
kfree(map);
return -ENOMEM;
}
map->timeout = ip_set_timeout_uget(tb[IPSET_ATTR_TIMEOUT]);
set->variant = &bitmap_tipmac;
bitmap_ipmac_gc_init(set);
} else {
map->dsize = sizeof(struct ipmac_elem);
if (!init_map_ipmac(set, map, first_ip, last_ip)) {
kfree(map);
return -ENOMEM;
}
set->variant = &bitmap_ipmac;
}
return 0;
}
static int __init
bitmap_ipmac_init(void)
{
return ip_set_type_register(&bitmap_ipmac_type);
}
static void __exit
bitmap_ipmac_fini(void)
{
ip_set_type_unregister(&bitmap_ipmac_type);
}
