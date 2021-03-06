static inline bool
hash_netport4_data_equal(const struct hash_netport4_elem *ip1,
const struct hash_netport4_elem *ip2,
u32 *multi)
{
return ip1->ip == ip2->ip &&
ip1->port == ip2->port &&
ip1->proto == ip2->proto &&
ip1->cidr == ip2->cidr;
}
static inline bool
hash_netport4_data_isnull(const struct hash_netport4_elem *elem)
{
return elem->proto == 0;
}
static inline void
hash_netport4_data_copy(struct hash_netport4_elem *dst,
const struct hash_netport4_elem *src)
{
dst->ip = src->ip;
dst->port = src->port;
dst->proto = src->proto;
dst->cidr = src->cidr;
dst->nomatch = src->nomatch;
}
static inline void
hash_netport4_data_flags(struct hash_netport4_elem *dst, u32 flags)
{
dst->nomatch = !!(flags & IPSET_FLAG_NOMATCH);
}
static inline int
hash_netport4_data_match(const struct hash_netport4_elem *elem)
{
return elem->nomatch ? -ENOTEMPTY : 1;
}
static inline void
hash_netport4_data_netmask(struct hash_netport4_elem *elem, u8 cidr)
{
elem->ip &= ip_set_netmask(cidr);
elem->cidr = cidr - 1;
}
static inline void
hash_netport4_data_zero_out(struct hash_netport4_elem *elem)
{
elem->proto = 0;
}
static bool
hash_netport4_data_list(struct sk_buff *skb,
const struct hash_netport4_elem *data)
{
u32 flags = data->nomatch ? IPSET_FLAG_NOMATCH : 0;
if (nla_put_ipaddr4(skb, IPSET_ATTR_IP, data->ip) ||
nla_put_net16(skb, IPSET_ATTR_PORT, data->port) ||
nla_put_u8(skb, IPSET_ATTR_CIDR, data->cidr + 1) ||
nla_put_u8(skb, IPSET_ATTR_PROTO, data->proto) ||
(flags &&
nla_put_net32(skb, IPSET_ATTR_CADT_FLAGS, htonl(flags))))
goto nla_put_failure;
return 0;
nla_put_failure:
return 1;
}
static bool
hash_netport4_data_tlist(struct sk_buff *skb,
const struct hash_netport4_elem *data)
{
const struct hash_netport4_telem *tdata =
(const struct hash_netport4_telem *)data;
u32 flags = data->nomatch ? IPSET_FLAG_NOMATCH : 0;
if (nla_put_ipaddr4(skb, IPSET_ATTR_IP, tdata->ip) ||
nla_put_net16(skb, IPSET_ATTR_PORT, tdata->port) ||
nla_put_u8(skb, IPSET_ATTR_CIDR, data->cidr + 1) ||
nla_put_u8(skb, IPSET_ATTR_PROTO, data->proto) ||
nla_put_net32(skb, IPSET_ATTR_TIMEOUT,
htonl(ip_set_timeout_get(tdata->timeout))) ||
(flags &&
nla_put_net32(skb, IPSET_ATTR_CADT_FLAGS, htonl(flags))))
goto nla_put_failure;
return 0;
nla_put_failure:
return 1;
}
static inline void
hash_netport4_data_next(struct ip_set_hash *h,
const struct hash_netport4_elem *d)
{
h->next.ip = d->ip;
h->next.port = d->port;
}
static int
hash_netport4_kadt(struct ip_set *set, const struct sk_buff *skb,
const struct xt_action_param *par,
enum ipset_adt adt, const struct ip_set_adt_opt *opt)
{
const struct ip_set_hash *h = set->data;
ipset_adtfn adtfn = set->variant->adt[adt];
struct hash_netport4_elem data = {
.cidr = h->nets[0].cidr ? h->nets[0].cidr - 1 : HOST_MASK - 1
};
if (adt == IPSET_TEST)
data.cidr = HOST_MASK - 1;
if (!ip_set_get_ip4_port(skb, opt->flags & IPSET_DIM_TWO_SRC,
&data.port, &data.proto))
return -EINVAL;
ip4addrptr(skb, opt->flags & IPSET_DIM_ONE_SRC, &data.ip);
data.ip &= ip_set_netmask(data.cidr + 1);
return adtfn(set, &data, opt_timeout(opt, h), opt->cmdflags);
}
static int
hash_netport4_uadt(struct ip_set *set, struct nlattr *tb[],
enum ipset_adt adt, u32 *lineno, u32 flags, bool retried)
{
const struct ip_set_hash *h = set->data;
ipset_adtfn adtfn = set->variant->adt[adt];
struct hash_netport4_elem data = { .cidr = HOST_MASK - 1 };
u32 port, port_to, p = 0, ip = 0, ip_to, last;
u32 timeout = h->timeout;
bool with_ports = false;
u8 cidr;
int ret;
if (unlikely(!tb[IPSET_ATTR_IP] ||
!ip_set_attr_netorder(tb, IPSET_ATTR_PORT) ||
!ip_set_optattr_netorder(tb, IPSET_ATTR_PORT_TO) ||
!ip_set_optattr_netorder(tb, IPSET_ATTR_TIMEOUT) ||
!ip_set_optattr_netorder(tb, IPSET_ATTR_CADT_FLAGS)))
return -IPSET_ERR_PROTOCOL;
if (tb[IPSET_ATTR_LINENO])
*lineno = nla_get_u32(tb[IPSET_ATTR_LINENO]);
ret = ip_set_get_hostipaddr4(tb[IPSET_ATTR_IP], &ip);
if (ret)
return ret;
if (tb[IPSET_ATTR_CIDR]) {
cidr = nla_get_u8(tb[IPSET_ATTR_CIDR]);
if (!cidr || cidr > HOST_MASK)
return -IPSET_ERR_INVALID_CIDR;
data.cidr = cidr - 1;
}
if (tb[IPSET_ATTR_PORT])
data.port = nla_get_be16(tb[IPSET_ATTR_PORT]);
else
return -IPSET_ERR_PROTOCOL;
if (tb[IPSET_ATTR_PROTO]) {
data.proto = nla_get_u8(tb[IPSET_ATTR_PROTO]);
with_ports = ip_set_proto_with_ports(data.proto);
if (data.proto == 0)
return -IPSET_ERR_INVALID_PROTO;
} else
return -IPSET_ERR_MISSING_PROTO;
if (!(with_ports || data.proto == IPPROTO_ICMP))
data.port = 0;
if (tb[IPSET_ATTR_TIMEOUT]) {
if (!with_timeout(h->timeout))
return -IPSET_ERR_TIMEOUT;
timeout = ip_set_timeout_uget(tb[IPSET_ATTR_TIMEOUT]);
}
with_ports = with_ports && tb[IPSET_ATTR_PORT_TO];
if (tb[IPSET_ATTR_CADT_FLAGS] && adt == IPSET_ADD) {
u32 cadt_flags = ip_set_get_h32(tb[IPSET_ATTR_CADT_FLAGS]);
if (cadt_flags & IPSET_FLAG_NOMATCH)
flags |= (cadt_flags << 16);
}
if (adt == IPSET_TEST || !(with_ports || tb[IPSET_ATTR_IP_TO])) {
data.ip = htonl(ip & ip_set_hostmask(data.cidr + 1));
ret = adtfn(set, &data, timeout, flags);
return ip_set_eexist(ret, flags) ? 0 : ret;
}
port = port_to = ntohs(data.port);
if (tb[IPSET_ATTR_PORT_TO]) {
port_to = ip_set_get_h16(tb[IPSET_ATTR_PORT_TO]);
if (port_to < port)
swap(port, port_to);
}
if (tb[IPSET_ATTR_IP_TO]) {
ret = ip_set_get_hostipaddr4(tb[IPSET_ATTR_IP_TO], &ip_to);
if (ret)
return ret;
if (ip_to < ip)
swap(ip, ip_to);
if (ip + UINT_MAX == ip_to)
return -IPSET_ERR_HASH_RANGE;
} else {
ip_set_mask_from_to(ip, ip_to, data.cidr + 1);
}
if (retried)
ip = ntohl(h->next.ip);
while (!after(ip, ip_to)) {
data.ip = htonl(ip);
last = ip_set_range_to_cidr(ip, ip_to, &cidr);
data.cidr = cidr - 1;
p = retried && ip == ntohl(h->next.ip) ? ntohs(h->next.port)
: port;
for (; p <= port_to; p++) {
data.port = htons(p);
ret = adtfn(set, &data, timeout, flags);
if (ret && !ip_set_eexist(ret, flags))
return ret;
else
ret = 0;
}
ip = last + 1;
}
return ret;
}
static bool
hash_netport_same_set(const struct ip_set *a, const struct ip_set *b)
{
const struct ip_set_hash *x = a->data;
const struct ip_set_hash *y = b->data;
return x->maxelem == y->maxelem &&
x->timeout == y->timeout;
}
static inline bool
hash_netport6_data_equal(const struct hash_netport6_elem *ip1,
const struct hash_netport6_elem *ip2,
u32 *multi)
{
return ipv6_addr_cmp(&ip1->ip.in6, &ip2->ip.in6) == 0 &&
ip1->port == ip2->port &&
ip1->proto == ip2->proto &&
ip1->cidr == ip2->cidr;
}
static inline bool
hash_netport6_data_isnull(const struct hash_netport6_elem *elem)
{
return elem->proto == 0;
}
static inline void
hash_netport6_data_copy(struct hash_netport6_elem *dst,
const struct hash_netport6_elem *src)
{
memcpy(dst, src, sizeof(*dst));
}
static inline void
hash_netport6_data_flags(struct hash_netport6_elem *dst, u32 flags)
{
dst->nomatch = !!(flags & IPSET_FLAG_NOMATCH);
}
static inline int
hash_netport6_data_match(const struct hash_netport6_elem *elem)
{
return elem->nomatch ? -ENOTEMPTY : 1;
}
static inline void
hash_netport6_data_zero_out(struct hash_netport6_elem *elem)
{
elem->proto = 0;
}
static inline void
ip6_netmask(union nf_inet_addr *ip, u8 prefix)
{
ip->ip6[0] &= ip_set_netmask6(prefix)[0];
ip->ip6[1] &= ip_set_netmask6(prefix)[1];
ip->ip6[2] &= ip_set_netmask6(prefix)[2];
ip->ip6[3] &= ip_set_netmask6(prefix)[3];
}
static inline void
hash_netport6_data_netmask(struct hash_netport6_elem *elem, u8 cidr)
{
ip6_netmask(&elem->ip, cidr);
elem->cidr = cidr - 1;
}
static bool
hash_netport6_data_list(struct sk_buff *skb,
const struct hash_netport6_elem *data)
{
u32 flags = data->nomatch ? IPSET_FLAG_NOMATCH : 0;
if (nla_put_ipaddr6(skb, IPSET_ATTR_IP, &data->ip.in6) ||
nla_put_net16(skb, IPSET_ATTR_PORT, data->port) ||
nla_put_u8(skb, IPSET_ATTR_CIDR, data->cidr + 1) ||
nla_put_u8(skb, IPSET_ATTR_PROTO, data->proto) ||
(flags &&
nla_put_net32(skb, IPSET_ATTR_CADT_FLAGS, htonl(flags))))
goto nla_put_failure;
return 0;
nla_put_failure:
return 1;
}
static bool
hash_netport6_data_tlist(struct sk_buff *skb,
const struct hash_netport6_elem *data)
{
const struct hash_netport6_telem *e =
(const struct hash_netport6_telem *)data;
u32 flags = data->nomatch ? IPSET_FLAG_NOMATCH : 0;
if (nla_put_ipaddr6(skb, IPSET_ATTR_IP, &e->ip.in6) ||
nla_put_net16(skb, IPSET_ATTR_PORT, data->port) ||
nla_put_u8(skb, IPSET_ATTR_CIDR, data->cidr + 1) ||
nla_put_u8(skb, IPSET_ATTR_PROTO, data->proto) ||
nla_put_net32(skb, IPSET_ATTR_TIMEOUT,
htonl(ip_set_timeout_get(e->timeout))) ||
(flags &&
nla_put_net32(skb, IPSET_ATTR_CADT_FLAGS, htonl(flags))))
goto nla_put_failure;
return 0;
nla_put_failure:
return 1;
}
static inline void
hash_netport6_data_next(struct ip_set_hash *h,
const struct hash_netport6_elem *d)
{
h->next.port = d->port;
}
static int
hash_netport6_kadt(struct ip_set *set, const struct sk_buff *skb,
const struct xt_action_param *par,
enum ipset_adt adt, const struct ip_set_adt_opt *opt)
{
const struct ip_set_hash *h = set->data;
ipset_adtfn adtfn = set->variant->adt[adt];
struct hash_netport6_elem data = {
.cidr = h->nets[0].cidr ? h->nets[0].cidr - 1 : HOST_MASK - 1,
};
if (adt == IPSET_TEST)
data.cidr = HOST_MASK - 1;
if (!ip_set_get_ip6_port(skb, opt->flags & IPSET_DIM_TWO_SRC,
&data.port, &data.proto))
return -EINVAL;
ip6addrptr(skb, opt->flags & IPSET_DIM_ONE_SRC, &data.ip.in6);
ip6_netmask(&data.ip, data.cidr + 1);
return adtfn(set, &data, opt_timeout(opt, h), opt->cmdflags);
}
static int
hash_netport6_uadt(struct ip_set *set, struct nlattr *tb[],
enum ipset_adt adt, u32 *lineno, u32 flags, bool retried)
{
const struct ip_set_hash *h = set->data;
ipset_adtfn adtfn = set->variant->adt[adt];
struct hash_netport6_elem data = { .cidr = HOST_MASK - 1 };
u32 port, port_to;
u32 timeout = h->timeout;
bool with_ports = false;
u8 cidr;
int ret;
if (unlikely(!tb[IPSET_ATTR_IP] ||
!ip_set_attr_netorder(tb, IPSET_ATTR_PORT) ||
!ip_set_optattr_netorder(tb, IPSET_ATTR_PORT_TO) ||
!ip_set_optattr_netorder(tb, IPSET_ATTR_TIMEOUT) ||
!ip_set_optattr_netorder(tb, IPSET_ATTR_CADT_FLAGS)))
return -IPSET_ERR_PROTOCOL;
if (unlikely(tb[IPSET_ATTR_IP_TO]))
return -IPSET_ERR_HASH_RANGE_UNSUPPORTED;
if (tb[IPSET_ATTR_LINENO])
*lineno = nla_get_u32(tb[IPSET_ATTR_LINENO]);
ret = ip_set_get_ipaddr6(tb[IPSET_ATTR_IP], &data.ip);
if (ret)
return ret;
if (tb[IPSET_ATTR_CIDR]) {
cidr = nla_get_u8(tb[IPSET_ATTR_CIDR]);
if (!cidr || cidr > HOST_MASK)
return -IPSET_ERR_INVALID_CIDR;
data.cidr = cidr - 1;
}
ip6_netmask(&data.ip, data.cidr + 1);
if (tb[IPSET_ATTR_PORT])
data.port = nla_get_be16(tb[IPSET_ATTR_PORT]);
else
return -IPSET_ERR_PROTOCOL;
if (tb[IPSET_ATTR_PROTO]) {
data.proto = nla_get_u8(tb[IPSET_ATTR_PROTO]);
with_ports = ip_set_proto_with_ports(data.proto);
if (data.proto == 0)
return -IPSET_ERR_INVALID_PROTO;
} else
return -IPSET_ERR_MISSING_PROTO;
if (!(with_ports || data.proto == IPPROTO_ICMPV6))
data.port = 0;
if (tb[IPSET_ATTR_TIMEOUT]) {
if (!with_timeout(h->timeout))
return -IPSET_ERR_TIMEOUT;
timeout = ip_set_timeout_uget(tb[IPSET_ATTR_TIMEOUT]);
}
if (tb[IPSET_ATTR_CADT_FLAGS] && adt == IPSET_ADD) {
u32 cadt_flags = ip_set_get_h32(tb[IPSET_ATTR_CADT_FLAGS]);
if (cadt_flags & IPSET_FLAG_NOMATCH)
flags |= (cadt_flags << 16);
}
if (adt == IPSET_TEST || !with_ports || !tb[IPSET_ATTR_PORT_TO]) {
ret = adtfn(set, &data, timeout, flags);
return ip_set_eexist(ret, flags) ? 0 : ret;
}
port = ntohs(data.port);
port_to = ip_set_get_h16(tb[IPSET_ATTR_PORT_TO]);
if (port > port_to)
swap(port, port_to);
if (retried)
port = ntohs(h->next.port);
for (; port <= port_to; port++) {
data.port = htons(port);
ret = adtfn(set, &data, timeout, flags);
if (ret && !ip_set_eexist(ret, flags))
return ret;
else
ret = 0;
}
return ret;
}
static int
hash_netport_create(struct ip_set *set, struct nlattr *tb[], u32 flags)
{
struct ip_set_hash *h;
u32 hashsize = IPSET_DEFAULT_HASHSIZE, maxelem = IPSET_DEFAULT_MAXELEM;
u8 hbits;
size_t hsize;
if (!(set->family == NFPROTO_IPV4 || set->family == NFPROTO_IPV6))
return -IPSET_ERR_INVALID_FAMILY;
if (unlikely(!ip_set_optattr_netorder(tb, IPSET_ATTR_HASHSIZE) ||
!ip_set_optattr_netorder(tb, IPSET_ATTR_MAXELEM) ||
!ip_set_optattr_netorder(tb, IPSET_ATTR_TIMEOUT)))
return -IPSET_ERR_PROTOCOL;
if (tb[IPSET_ATTR_HASHSIZE]) {
hashsize = ip_set_get_h32(tb[IPSET_ATTR_HASHSIZE]);
if (hashsize < IPSET_MIMINAL_HASHSIZE)
hashsize = IPSET_MIMINAL_HASHSIZE;
}
if (tb[IPSET_ATTR_MAXELEM])
maxelem = ip_set_get_h32(tb[IPSET_ATTR_MAXELEM]);
h = kzalloc(sizeof(*h)
+ sizeof(struct ip_set_hash_nets)
* (set->family == NFPROTO_IPV4 ? 32 : 128), GFP_KERNEL);
if (!h)
return -ENOMEM;
h->maxelem = maxelem;
get_random_bytes(&h->initval, sizeof(h->initval));
h->timeout = IPSET_NO_TIMEOUT;
hbits = htable_bits(hashsize);
hsize = htable_size(hbits);
if (hsize == 0) {
kfree(h);
return -ENOMEM;
}
h->table = ip_set_alloc(hsize);
if (!h->table) {
kfree(h);
return -ENOMEM;
}
h->table->htable_bits = hbits;
set->data = h;
if (tb[IPSET_ATTR_TIMEOUT]) {
h->timeout = ip_set_timeout_uget(tb[IPSET_ATTR_TIMEOUT]);
set->variant = set->family == NFPROTO_IPV4
? &hash_netport4_tvariant : &hash_netport6_tvariant;
if (set->family == NFPROTO_IPV4)
hash_netport4_gc_init(set);
else
hash_netport6_gc_init(set);
} else {
set->variant = set->family == NFPROTO_IPV4
? &hash_netport4_variant : &hash_netport6_variant;
}
pr_debug("create %s hashsize %u (%u) maxelem %u: %p(%p)\n",
set->name, jhash_size(h->table->htable_bits),
h->table->htable_bits, h->maxelem, set->data, h->table);
return 0;
}
static int __init
hash_netport_init(void)
{
return ip_set_type_register(&hash_netport_type);
}
static void __exit
hash_netport_fini(void)
{
ip_set_type_unregister(&hash_netport_type);
}
