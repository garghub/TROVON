static inline bool
hash_ip4_data_equal(const struct hash_ip4_elem *ip1,
const struct hash_ip4_elem *ip2,
u32 *multi)
{
return ip1->ip == ip2->ip;
}
static inline bool
hash_ip4_data_isnull(const struct hash_ip4_elem *elem)
{
return elem->ip == 0;
}
static inline void
hash_ip4_data_copy(struct hash_ip4_elem *dst, const struct hash_ip4_elem *src)
{
dst->ip = src->ip;
}
static inline void
hash_ip4_data_zero_out(struct hash_ip4_elem *elem)
{
elem->ip = 0;
}
static inline bool
hash_ip4_data_list(struct sk_buff *skb, const struct hash_ip4_elem *data)
{
if (nla_put_ipaddr4(skb, IPSET_ATTR_IP, data->ip))
goto nla_put_failure;
return 0;
nla_put_failure:
return 1;
}
static bool
hash_ip4_data_tlist(struct sk_buff *skb, const struct hash_ip4_elem *data)
{
const struct hash_ip4_telem *tdata =
(const struct hash_ip4_telem *)data;
if (nla_put_ipaddr4(skb, IPSET_ATTR_IP, tdata->ip) ||
nla_put_net32(skb, IPSET_ATTR_TIMEOUT,
htonl(ip_set_timeout_get(tdata->timeout))))
goto nla_put_failure;
return 0;
nla_put_failure:
return 1;
}
static inline void
hash_ip4_data_next(struct ip_set_hash *h, const struct hash_ip4_elem *d)
{
h->next.ip = d->ip;
}
static int
hash_ip4_kadt(struct ip_set *set, const struct sk_buff *skb,
const struct xt_action_param *par,
enum ipset_adt adt, const struct ip_set_adt_opt *opt)
{
const struct ip_set_hash *h = set->data;
ipset_adtfn adtfn = set->variant->adt[adt];
__be32 ip;
ip4addrptr(skb, opt->flags & IPSET_DIM_ONE_SRC, &ip);
ip &= ip_set_netmask(h->netmask);
if (ip == 0)
return -EINVAL;
return adtfn(set, &ip, opt_timeout(opt, h), opt->cmdflags);
}
static int
hash_ip4_uadt(struct ip_set *set, struct nlattr *tb[],
enum ipset_adt adt, u32 *lineno, u32 flags, bool retried)
{
const struct ip_set_hash *h = set->data;
ipset_adtfn adtfn = set->variant->adt[adt];
u32 ip, ip_to, hosts, timeout = h->timeout;
__be32 nip;
int ret = 0;
if (unlikely(!tb[IPSET_ATTR_IP] ||
!ip_set_optattr_netorder(tb, IPSET_ATTR_TIMEOUT)))
return -IPSET_ERR_PROTOCOL;
if (tb[IPSET_ATTR_LINENO])
*lineno = nla_get_u32(tb[IPSET_ATTR_LINENO]);
ret = ip_set_get_hostipaddr4(tb[IPSET_ATTR_IP], &ip);
if (ret)
return ret;
ip &= ip_set_hostmask(h->netmask);
if (tb[IPSET_ATTR_TIMEOUT]) {
if (!with_timeout(h->timeout))
return -IPSET_ERR_TIMEOUT;
timeout = ip_set_timeout_uget(tb[IPSET_ATTR_TIMEOUT]);
}
if (adt == IPSET_TEST) {
nip = htonl(ip);
if (nip == 0)
return -IPSET_ERR_HASH_ELEM;
return adtfn(set, &nip, timeout, flags);
}
ip_to = ip;
if (tb[IPSET_ATTR_IP_TO]) {
ret = ip_set_get_hostipaddr4(tb[IPSET_ATTR_IP_TO], &ip_to);
if (ret)
return ret;
if (ip > ip_to)
swap(ip, ip_to);
} else if (tb[IPSET_ATTR_CIDR]) {
u8 cidr = nla_get_u8(tb[IPSET_ATTR_CIDR]);
if (!cidr || cidr > 32)
return -IPSET_ERR_INVALID_CIDR;
ip_set_mask_from_to(ip, ip_to, cidr);
}
hosts = h->netmask == 32 ? 1 : 2 << (32 - h->netmask - 1);
if (retried)
ip = ntohl(h->next.ip);
for (; !before(ip_to, ip); ip += hosts) {
nip = htonl(ip);
if (nip == 0)
return -IPSET_ERR_HASH_ELEM;
ret = adtfn(set, &nip, timeout, flags);
if (ret && !ip_set_eexist(ret, flags))
return ret;
else
ret = 0;
}
return ret;
}
static bool
hash_ip_same_set(const struct ip_set *a, const struct ip_set *b)
{
const struct ip_set_hash *x = a->data;
const struct ip_set_hash *y = b->data;
return x->maxelem == y->maxelem &&
x->timeout == y->timeout &&
x->netmask == y->netmask;
}
static inline bool
hash_ip6_data_equal(const struct hash_ip6_elem *ip1,
const struct hash_ip6_elem *ip2,
u32 *multi)
{
return ipv6_addr_cmp(&ip1->ip.in6, &ip2->ip.in6) == 0;
}
static inline bool
hash_ip6_data_isnull(const struct hash_ip6_elem *elem)
{
return ipv6_addr_any(&elem->ip.in6);
}
static inline void
hash_ip6_data_copy(struct hash_ip6_elem *dst, const struct hash_ip6_elem *src)
{
dst->ip.in6 = src->ip.in6;
}
static inline void
hash_ip6_data_zero_out(struct hash_ip6_elem *elem)
{
ipv6_addr_set(&elem->ip.in6, 0, 0, 0, 0);
}
static inline void
ip6_netmask(union nf_inet_addr *ip, u8 prefix)
{
ip->ip6[0] &= ip_set_netmask6(prefix)[0];
ip->ip6[1] &= ip_set_netmask6(prefix)[1];
ip->ip6[2] &= ip_set_netmask6(prefix)[2];
ip->ip6[3] &= ip_set_netmask6(prefix)[3];
}
static bool
hash_ip6_data_list(struct sk_buff *skb, const struct hash_ip6_elem *data)
{
if (nla_put_ipaddr6(skb, IPSET_ATTR_IP, &data->ip.in6))
goto nla_put_failure;
return 0;
nla_put_failure:
return 1;
}
static bool
hash_ip6_data_tlist(struct sk_buff *skb, const struct hash_ip6_elem *data)
{
const struct hash_ip6_telem *e =
(const struct hash_ip6_telem *)data;
if (nla_put_ipaddr6(skb, IPSET_ATTR_IP, &e->ip.in6) ||
nla_put_net32(skb, IPSET_ATTR_TIMEOUT,
htonl(ip_set_timeout_get(e->timeout))))
goto nla_put_failure;
return 0;
nla_put_failure:
return 1;
}
static inline void
hash_ip6_data_next(struct ip_set_hash *h, const struct hash_ip6_elem *d)
{
}
static int
hash_ip6_kadt(struct ip_set *set, const struct sk_buff *skb,
const struct xt_action_param *par,
enum ipset_adt adt, const struct ip_set_adt_opt *opt)
{
const struct ip_set_hash *h = set->data;
ipset_adtfn adtfn = set->variant->adt[adt];
union nf_inet_addr ip;
ip6addrptr(skb, opt->flags & IPSET_DIM_ONE_SRC, &ip.in6);
ip6_netmask(&ip, h->netmask);
if (ipv6_addr_any(&ip.in6))
return -EINVAL;
return adtfn(set, &ip, opt_timeout(opt, h), opt->cmdflags);
}
static int
hash_ip6_uadt(struct ip_set *set, struct nlattr *tb[],
enum ipset_adt adt, u32 *lineno, u32 flags, bool retried)
{
const struct ip_set_hash *h = set->data;
ipset_adtfn adtfn = set->variant->adt[adt];
union nf_inet_addr ip;
u32 timeout = h->timeout;
int ret;
if (unlikely(!tb[IPSET_ATTR_IP] ||
!ip_set_optattr_netorder(tb, IPSET_ATTR_TIMEOUT) ||
tb[IPSET_ATTR_IP_TO] ||
tb[IPSET_ATTR_CIDR]))
return -IPSET_ERR_PROTOCOL;
if (tb[IPSET_ATTR_LINENO])
*lineno = nla_get_u32(tb[IPSET_ATTR_LINENO]);
ret = ip_set_get_ipaddr6(tb[IPSET_ATTR_IP], &ip);
if (ret)
return ret;
ip6_netmask(&ip, h->netmask);
if (ipv6_addr_any(&ip.in6))
return -IPSET_ERR_HASH_ELEM;
if (tb[IPSET_ATTR_TIMEOUT]) {
if (!with_timeout(h->timeout))
return -IPSET_ERR_TIMEOUT;
timeout = ip_set_timeout_uget(tb[IPSET_ATTR_TIMEOUT]);
}
ret = adtfn(set, &ip, timeout, flags);
return ip_set_eexist(ret, flags) ? 0 : ret;
}
static int
hash_ip_create(struct ip_set *set, struct nlattr *tb[], u32 flags)
{
u32 hashsize = IPSET_DEFAULT_HASHSIZE, maxelem = IPSET_DEFAULT_MAXELEM;
u8 netmask, hbits;
size_t hsize;
struct ip_set_hash *h;
if (!(set->family == NFPROTO_IPV4 || set->family == NFPROTO_IPV6))
return -IPSET_ERR_INVALID_FAMILY;
netmask = set->family == NFPROTO_IPV4 ? 32 : 128;
pr_debug("Create set %s with family %s\n",
set->name, set->family == NFPROTO_IPV4 ? "inet" : "inet6");
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
if (tb[IPSET_ATTR_NETMASK]) {
netmask = nla_get_u8(tb[IPSET_ATTR_NETMASK]);
if ((set->family == NFPROTO_IPV4 && netmask > 32) ||
(set->family == NFPROTO_IPV6 && netmask > 128) ||
netmask == 0)
return -IPSET_ERR_INVALID_NETMASK;
}
h = kzalloc(sizeof(*h), GFP_KERNEL);
if (!h)
return -ENOMEM;
h->maxelem = maxelem;
h->netmask = netmask;
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
? &hash_ip4_tvariant : &hash_ip6_tvariant;
if (set->family == NFPROTO_IPV4)
hash_ip4_gc_init(set);
else
hash_ip6_gc_init(set);
} else {
set->variant = set->family == NFPROTO_IPV4
? &hash_ip4_variant : &hash_ip6_variant;
}
pr_debug("create %s hashsize %u (%u) maxelem %u: %p(%p)\n",
set->name, jhash_size(h->table->htable_bits),
h->table->htable_bits, h->maxelem, set->data, h->table);
return 0;
}
static int __init
hash_ip_init(void)
{
return ip_set_type_register(&hash_ip_type);
}
static void __exit
hash_ip_fini(void)
{
ip_set_type_unregister(&hash_ip_type);
}
