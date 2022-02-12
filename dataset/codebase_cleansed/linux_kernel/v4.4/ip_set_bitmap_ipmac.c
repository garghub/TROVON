static inline u32
ip_to_id(const struct bitmap_ipmac *m, u32 ip)
{
return ip - m->first_ip;
}
static inline int
bitmap_ipmac_do_test(const struct bitmap_ipmac_adt_elem *e,
const struct bitmap_ipmac *map, size_t dsize)
{
const struct bitmap_ipmac_elem *elem;
if (!test_bit(e->id, map->members))
return 0;
elem = get_const_elem(map->extensions, e->id, dsize);
if (e->add_mac && elem->filled == MAC_FILLED)
return ether_addr_equal(e->ether, elem->ether);
return -EAGAIN;
}
static inline int
bitmap_ipmac_gc_test(u16 id, const struct bitmap_ipmac *map, size_t dsize)
{
const struct bitmap_ipmac_elem *elem;
if (!test_bit(id, map->members))
return 0;
elem = get_const_elem(map->extensions, id, dsize);
return elem->filled == MAC_FILLED;
}
static inline int
bitmap_ipmac_is_filled(const struct bitmap_ipmac_elem *elem)
{
return elem->filled == MAC_FILLED;
}
static inline int
bitmap_ipmac_add_timeout(unsigned long *timeout,
const struct bitmap_ipmac_adt_elem *e,
const struct ip_set_ext *ext, struct ip_set *set,
struct bitmap_ipmac *map, int mode)
{
u32 t = ext->timeout;
if (mode == IPSET_ADD_START_STORED_TIMEOUT) {
if (t == set->timeout)
t = *timeout;
ip_set_timeout_set(timeout, t);
} else {
if (e->add_mac)
ip_set_timeout_set(timeout, t);
else
*timeout = t;
}
return 0;
}
static inline int
bitmap_ipmac_do_add(const struct bitmap_ipmac_adt_elem *e,
struct bitmap_ipmac *map, u32 flags, size_t dsize)
{
struct bitmap_ipmac_elem *elem;
elem = get_elem(map->extensions, e->id, dsize);
if (test_bit(e->id, map->members)) {
if (elem->filled == MAC_FILLED) {
if (e->add_mac &&
(flags & IPSET_FLAG_EXIST) &&
!ether_addr_equal(e->ether, elem->ether)) {
clear_bit(e->id, map->members);
smp_mb__after_atomic();
ether_addr_copy(elem->ether, e->ether);
}
return IPSET_ADD_FAILED;
} else if (!e->add_mac)
return IPSET_ADD_FAILED;
clear_bit(e->id, map->members);
smp_mb__after_atomic();
ether_addr_copy(elem->ether, e->ether);
elem->filled = MAC_FILLED;
return IPSET_ADD_START_STORED_TIMEOUT;
} else if (e->add_mac) {
ether_addr_copy(elem->ether, e->ether);
elem->filled = MAC_FILLED;
return 0;
}
elem->filled = MAC_UNSET;
return IPSET_ADD_STORE_PLAIN_TIMEOUT;
}
static inline int
bitmap_ipmac_do_del(const struct bitmap_ipmac_adt_elem *e,
struct bitmap_ipmac *map)
{
return !test_and_clear_bit(e->id, map->members);
}
static inline int
bitmap_ipmac_do_list(struct sk_buff *skb, const struct bitmap_ipmac *map,
u32 id, size_t dsize)
{
const struct bitmap_ipmac_elem *elem =
get_const_elem(map->extensions, id, dsize);
return nla_put_ipaddr4(skb, IPSET_ATTR_IP,
htonl(map->first_ip + id)) ||
(elem->filled == MAC_FILLED &&
nla_put(skb, IPSET_ATTR_ETHER, ETH_ALEN, elem->ether));
}
static inline int
bitmap_ipmac_do_head(struct sk_buff *skb, const struct bitmap_ipmac *map)
{
return nla_put_ipaddr4(skb, IPSET_ATTR_IP, htonl(map->first_ip)) ||
nla_put_ipaddr4(skb, IPSET_ATTR_IP_TO, htonl(map->last_ip));
}
static int
bitmap_ipmac_kadt(struct ip_set *set, const struct sk_buff *skb,
const struct xt_action_param *par,
enum ipset_adt adt, struct ip_set_adt_opt *opt)
{
struct bitmap_ipmac *map = set->data;
ipset_adtfn adtfn = set->variant->adt[adt];
struct bitmap_ipmac_adt_elem e = { .id = 0, .add_mac = 1 };
struct ip_set_ext ext = IP_SET_INIT_KEXT(skb, opt, set);
u32 ip;
if (!(opt->flags & IPSET_DIM_TWO_SRC))
return 0;
ip = ntohl(ip4addr(skb, opt->flags & IPSET_DIM_ONE_SRC));
if (ip < map->first_ip || ip > map->last_ip)
return -IPSET_ERR_BITMAP_RANGE;
if (skb_mac_header(skb) < skb->head ||
(skb_mac_header(skb) + ETH_HLEN) > skb->data)
return -EINVAL;
e.id = ip_to_id(map, ip);
memcpy(e.ether, eth_hdr(skb)->h_source, ETH_ALEN);
return adtfn(set, &e, &ext, &opt->ext, opt->cmdflags);
}
static int
bitmap_ipmac_uadt(struct ip_set *set, struct nlattr *tb[],
enum ipset_adt adt, u32 *lineno, u32 flags, bool retried)
{
const struct bitmap_ipmac *map = set->data;
ipset_adtfn adtfn = set->variant->adt[adt];
struct bitmap_ipmac_adt_elem e = { .id = 0 };
struct ip_set_ext ext = IP_SET_INIT_UEXT(set);
u32 ip = 0;
int ret = 0;
if (tb[IPSET_ATTR_LINENO])
*lineno = nla_get_u32(tb[IPSET_ATTR_LINENO]);
if (unlikely(!tb[IPSET_ATTR_IP]))
return -IPSET_ERR_PROTOCOL;
ret = ip_set_get_hostipaddr4(tb[IPSET_ATTR_IP], &ip);
if (ret)
return ret;
ret = ip_set_get_extensions(set, tb, &ext);
if (ret)
return ret;
if (ip < map->first_ip || ip > map->last_ip)
return -IPSET_ERR_BITMAP_RANGE;
e.id = ip_to_id(map, ip);
if (tb[IPSET_ATTR_ETHER]) {
memcpy(e.ether, nla_data(tb[IPSET_ATTR_ETHER]), ETH_ALEN);
e.add_mac = 1;
}
ret = adtfn(set, &e, &ext, &ext, flags);
return ip_set_eexist(ret, flags) ? 0 : ret;
}
static bool
bitmap_ipmac_same_set(const struct ip_set *a, const struct ip_set *b)
{
const struct bitmap_ipmac *x = a->data;
const struct bitmap_ipmac *y = b->data;
return x->first_ip == y->first_ip &&
x->last_ip == y->last_ip &&
a->timeout == b->timeout &&
a->extensions == b->extensions;
}
static bool
init_map_ipmac(struct ip_set *set, struct bitmap_ipmac *map,
u32 first_ip, u32 last_ip, u32 elements)
{
map->members = ip_set_alloc(map->memsize);
if (!map->members)
return false;
map->first_ip = first_ip;
map->last_ip = last_ip;
map->elements = elements;
set->timeout = IPSET_NO_TIMEOUT;
set->data = map;
set->family = NFPROTO_IPV4;
return true;
}
static int
bitmap_ipmac_create(struct net *net, struct ip_set *set, struct nlattr *tb[],
u32 flags)
{
u32 first_ip = 0, last_ip = 0;
u64 elements;
struct bitmap_ipmac *map;
int ret;
if (unlikely(!tb[IPSET_ATTR_IP] ||
!ip_set_optattr_netorder(tb, IPSET_ATTR_TIMEOUT) ||
!ip_set_optattr_netorder(tb, IPSET_ATTR_CADT_FLAGS)))
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
if (cidr >= HOST_MASK)
return -IPSET_ERR_INVALID_CIDR;
ip_set_mask_from_to(first_ip, last_ip, cidr);
} else {
return -IPSET_ERR_PROTOCOL;
}
elements = (u64)last_ip - first_ip + 1;
if (elements > IPSET_BITMAP_MAX_RANGE + 1)
return -IPSET_ERR_BITMAP_RANGE_SIZE;
set->dsize = ip_set_elem_len(set, tb,
sizeof(struct bitmap_ipmac_elem),
__alignof__(struct bitmap_ipmac_elem));
map = ip_set_alloc(sizeof(*map) + elements * set->dsize);
if (!map)
return -ENOMEM;
map->memsize = bitmap_bytes(0, elements - 1);
set->variant = &bitmap_ipmac;
if (!init_map_ipmac(set, map, first_ip, last_ip, elements)) {
kfree(map);
return -ENOMEM;
}
if (tb[IPSET_ATTR_TIMEOUT]) {
set->timeout = ip_set_timeout_uget(tb[IPSET_ATTR_TIMEOUT]);
bitmap_ipmac_gc_init(set, bitmap_ipmac_gc);
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
rcu_barrier();
ip_set_type_unregister(&bitmap_ipmac_type);
}
