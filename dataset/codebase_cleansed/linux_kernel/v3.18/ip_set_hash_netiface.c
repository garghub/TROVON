static void
rbtree_destroy(struct rb_root *root)
{
struct iface_node *node, *next;
rbtree_postorder_for_each_entry_safe(node, next, root, node)
kfree(node);
*root = RB_ROOT;
}
static int
iface_test(struct rb_root *root, const char **iface)
{
struct rb_node *n = root->rb_node;
while (n) {
const char *d = iface_data(n);
int res = strcmp(*iface, d);
if (res < 0)
n = n->rb_left;
else if (res > 0)
n = n->rb_right;
else {
*iface = d;
return 1;
}
}
return 0;
}
static int
iface_add(struct rb_root *root, const char **iface)
{
struct rb_node **n = &(root->rb_node), *p = NULL;
struct iface_node *d;
while (*n) {
char *ifname = iface_data(*n);
int res = strcmp(*iface, ifname);
p = *n;
if (res < 0)
n = &((*n)->rb_left);
else if (res > 0)
n = &((*n)->rb_right);
else {
*iface = ifname;
return 0;
}
}
d = kzalloc(sizeof(*d), GFP_ATOMIC);
if (!d)
return -ENOMEM;
strcpy(d->iface, *iface);
rb_link_node(&d->node, p, n);
rb_insert_color(&d->node, root);
*iface = d->iface;
return 0;
}
static inline bool
hash_netiface4_data_equal(const struct hash_netiface4_elem *ip1,
const struct hash_netiface4_elem *ip2,
u32 *multi)
{
return ip1->ip == ip2->ip &&
ip1->cidr == ip2->cidr &&
(++*multi) &&
ip1->physdev == ip2->physdev &&
ip1->iface == ip2->iface;
}
static inline int
hash_netiface4_do_data_match(const struct hash_netiface4_elem *elem)
{
return elem->nomatch ? -ENOTEMPTY : 1;
}
static inline void
hash_netiface4_data_set_flags(struct hash_netiface4_elem *elem, u32 flags)
{
elem->nomatch = (flags >> 16) & IPSET_FLAG_NOMATCH;
}
static inline void
hash_netiface4_data_reset_flags(struct hash_netiface4_elem *elem, u8 *flags)
{
swap(*flags, elem->nomatch);
}
static inline void
hash_netiface4_data_netmask(struct hash_netiface4_elem *elem, u8 cidr)
{
elem->ip &= ip_set_netmask(cidr);
elem->cidr = cidr;
}
static bool
hash_netiface4_data_list(struct sk_buff *skb,
const struct hash_netiface4_elem *data)
{
u32 flags = data->physdev ? IPSET_FLAG_PHYSDEV : 0;
if (data->nomatch)
flags |= IPSET_FLAG_NOMATCH;
if (nla_put_ipaddr4(skb, IPSET_ATTR_IP, data->ip) ||
nla_put_u8(skb, IPSET_ATTR_CIDR, data->cidr) ||
nla_put_string(skb, IPSET_ATTR_IFACE, data->iface) ||
(flags &&
nla_put_net32(skb, IPSET_ATTR_CADT_FLAGS, htonl(flags))))
goto nla_put_failure;
return 0;
nla_put_failure:
return 1;
}
static inline void
hash_netiface4_data_next(struct hash_netiface4_elem *next,
const struct hash_netiface4_elem *d)
{
next->ip = d->ip;
}
static int
hash_netiface4_kadt(struct ip_set *set, const struct sk_buff *skb,
const struct xt_action_param *par,
enum ipset_adt adt, struct ip_set_adt_opt *opt)
{
struct hash_netiface *h = set->data;
ipset_adtfn adtfn = set->variant->adt[adt];
struct hash_netiface4_elem e = {
.cidr = IP_SET_INIT_CIDR(h->nets[0].cidr[0], HOST_MASK),
.elem = 1,
};
struct ip_set_ext ext = IP_SET_INIT_KEXT(skb, opt, set);
int ret;
if (e.cidr == 0)
return -EINVAL;
if (adt == IPSET_TEST)
e.cidr = HOST_MASK;
ip4addrptr(skb, opt->flags & IPSET_DIM_ONE_SRC, &e.ip);
e.ip &= ip_set_netmask(e.cidr);
#define IFACE(dir) (par->dir ? par->dir->name : NULL)
#define PHYSDEV(dir) (nf_bridge->dir ? nf_bridge->dir->name : NULL)
#define SRCDIR (opt->flags & IPSET_DIM_TWO_SRC)
if (opt->cmdflags & IPSET_FLAG_PHYSDEV) {
#if IS_ENABLED(CONFIG_BRIDGE_NETFILTER)
const struct nf_bridge_info *nf_bridge = skb->nf_bridge;
if (!nf_bridge)
return -EINVAL;
e.iface = SRCDIR ? PHYSDEV(physindev) : PHYSDEV(physoutdev);
e.physdev = 1;
#else
e.iface = NULL;
#endif
} else
e.iface = SRCDIR ? IFACE(in) : IFACE(out);
if (!e.iface)
return -EINVAL;
ret = iface_test(&h->rbtree, &e.iface);
if (adt == IPSET_ADD) {
if (!ret) {
ret = iface_add(&h->rbtree, &e.iface);
if (ret)
return ret;
}
} else if (!ret)
return ret;
return adtfn(set, &e, &ext, &opt->ext, opt->cmdflags);
}
static int
hash_netiface4_uadt(struct ip_set *set, struct nlattr *tb[],
enum ipset_adt adt, u32 *lineno, u32 flags, bool retried)
{
struct hash_netiface *h = set->data;
ipset_adtfn adtfn = set->variant->adt[adt];
struct hash_netiface4_elem e = { .cidr = HOST_MASK, .elem = 1 };
struct ip_set_ext ext = IP_SET_INIT_UEXT(set);
u32 ip = 0, ip_to = 0, last;
char iface[IFNAMSIZ];
int ret;
if (unlikely(!tb[IPSET_ATTR_IP] ||
!tb[IPSET_ATTR_IFACE] ||
!ip_set_optattr_netorder(tb, IPSET_ATTR_TIMEOUT) ||
!ip_set_optattr_netorder(tb, IPSET_ATTR_CADT_FLAGS) ||
!ip_set_optattr_netorder(tb, IPSET_ATTR_PACKETS) ||
!ip_set_optattr_netorder(tb, IPSET_ATTR_BYTES) ||
!ip_set_optattr_netorder(tb, IPSET_ATTR_SKBMARK) ||
!ip_set_optattr_netorder(tb, IPSET_ATTR_SKBPRIO) ||
!ip_set_optattr_netorder(tb, IPSET_ATTR_SKBQUEUE)))
return -IPSET_ERR_PROTOCOL;
if (tb[IPSET_ATTR_LINENO])
*lineno = nla_get_u32(tb[IPSET_ATTR_LINENO]);
ret = ip_set_get_hostipaddr4(tb[IPSET_ATTR_IP], &ip) ||
ip_set_get_extensions(set, tb, &ext);
if (ret)
return ret;
if (tb[IPSET_ATTR_CIDR]) {
e.cidr = nla_get_u8(tb[IPSET_ATTR_CIDR]);
if (e.cidr > HOST_MASK)
return -IPSET_ERR_INVALID_CIDR;
}
strcpy(iface, nla_data(tb[IPSET_ATTR_IFACE]));
e.iface = iface;
ret = iface_test(&h->rbtree, &e.iface);
if (adt == IPSET_ADD) {
if (!ret) {
ret = iface_add(&h->rbtree, &e.iface);
if (ret)
return ret;
}
} else if (!ret)
return ret;
if (tb[IPSET_ATTR_CADT_FLAGS]) {
u32 cadt_flags = ip_set_get_h32(tb[IPSET_ATTR_CADT_FLAGS]);
if (cadt_flags & IPSET_FLAG_PHYSDEV)
e.physdev = 1;
if (cadt_flags & IPSET_FLAG_NOMATCH)
flags |= (IPSET_FLAG_NOMATCH << 16);
}
if (adt == IPSET_TEST || !tb[IPSET_ATTR_IP_TO]) {
e.ip = htonl(ip & ip_set_hostmask(e.cidr));
ret = adtfn(set, &e, &ext, &ext, flags);
return ip_set_enomatch(ret, flags, adt, set) ? -ret :
ip_set_eexist(ret, flags) ? 0 : ret;
}
if (tb[IPSET_ATTR_IP_TO]) {
ret = ip_set_get_hostipaddr4(tb[IPSET_ATTR_IP_TO], &ip_to);
if (ret)
return ret;
if (ip_to < ip)
swap(ip, ip_to);
if (ip + UINT_MAX == ip_to)
return -IPSET_ERR_HASH_RANGE;
} else
ip_set_mask_from_to(ip, ip_to, e.cidr);
if (retried)
ip = ntohl(h->next.ip);
while (!after(ip, ip_to)) {
e.ip = htonl(ip);
last = ip_set_range_to_cidr(ip, ip_to, &e.cidr);
ret = adtfn(set, &e, &ext, &ext, flags);
if (ret && !ip_set_eexist(ret, flags))
return ret;
else
ret = 0;
ip = last + 1;
}
return ret;
}
static inline bool
hash_netiface6_data_equal(const struct hash_netiface6_elem *ip1,
const struct hash_netiface6_elem *ip2,
u32 *multi)
{
return ipv6_addr_equal(&ip1->ip.in6, &ip2->ip.in6) &&
ip1->cidr == ip2->cidr &&
(++*multi) &&
ip1->physdev == ip2->physdev &&
ip1->iface == ip2->iface;
}
static inline int
hash_netiface6_do_data_match(const struct hash_netiface6_elem *elem)
{
return elem->nomatch ? -ENOTEMPTY : 1;
}
static inline void
hash_netiface6_data_set_flags(struct hash_netiface6_elem *elem, u32 flags)
{
elem->nomatch = (flags >> 16) & IPSET_FLAG_NOMATCH;
}
static inline void
hash_netiface6_data_reset_flags(struct hash_netiface6_elem *elem, u8 *flags)
{
swap(*flags, elem->nomatch);
}
static inline void
hash_netiface6_data_netmask(struct hash_netiface6_elem *elem, u8 cidr)
{
ip6_netmask(&elem->ip, cidr);
elem->cidr = cidr;
}
static bool
hash_netiface6_data_list(struct sk_buff *skb,
const struct hash_netiface6_elem *data)
{
u32 flags = data->physdev ? IPSET_FLAG_PHYSDEV : 0;
if (data->nomatch)
flags |= IPSET_FLAG_NOMATCH;
if (nla_put_ipaddr6(skb, IPSET_ATTR_IP, &data->ip.in6) ||
nla_put_u8(skb, IPSET_ATTR_CIDR, data->cidr) ||
nla_put_string(skb, IPSET_ATTR_IFACE, data->iface) ||
(flags &&
nla_put_net32(skb, IPSET_ATTR_CADT_FLAGS, htonl(flags))))
goto nla_put_failure;
return 0;
nla_put_failure:
return 1;
}
static inline void
hash_netiface6_data_next(struct hash_netiface4_elem *next,
const struct hash_netiface6_elem *d)
{
}
static int
hash_netiface6_kadt(struct ip_set *set, const struct sk_buff *skb,
const struct xt_action_param *par,
enum ipset_adt adt, struct ip_set_adt_opt *opt)
{
struct hash_netiface *h = set->data;
ipset_adtfn adtfn = set->variant->adt[adt];
struct hash_netiface6_elem e = {
.cidr = IP_SET_INIT_CIDR(h->nets[0].cidr[0], HOST_MASK),
.elem = 1,
};
struct ip_set_ext ext = IP_SET_INIT_KEXT(skb, opt, set);
int ret;
if (e.cidr == 0)
return -EINVAL;
if (adt == IPSET_TEST)
e.cidr = HOST_MASK;
ip6addrptr(skb, opt->flags & IPSET_DIM_ONE_SRC, &e.ip.in6);
ip6_netmask(&e.ip, e.cidr);
if (opt->cmdflags & IPSET_FLAG_PHYSDEV) {
#if IS_ENABLED(CONFIG_BRIDGE_NETFILTER)
const struct nf_bridge_info *nf_bridge = skb->nf_bridge;
if (!nf_bridge)
return -EINVAL;
e.iface = SRCDIR ? PHYSDEV(physindev) : PHYSDEV(physoutdev);
e.physdev = 1;
#else
e.iface = NULL;
#endif
} else
e.iface = SRCDIR ? IFACE(in) : IFACE(out);
if (!e.iface)
return -EINVAL;
ret = iface_test(&h->rbtree, &e.iface);
if (adt == IPSET_ADD) {
if (!ret) {
ret = iface_add(&h->rbtree, &e.iface);
if (ret)
return ret;
}
} else if (!ret)
return ret;
return adtfn(set, &e, &ext, &opt->ext, opt->cmdflags);
}
static int
hash_netiface6_uadt(struct ip_set *set, struct nlattr *tb[],
enum ipset_adt adt, u32 *lineno, u32 flags, bool retried)
{
struct hash_netiface *h = set->data;
ipset_adtfn adtfn = set->variant->adt[adt];
struct hash_netiface6_elem e = { .cidr = HOST_MASK, .elem = 1 };
struct ip_set_ext ext = IP_SET_INIT_UEXT(set);
char iface[IFNAMSIZ];
int ret;
if (unlikely(!tb[IPSET_ATTR_IP] ||
!tb[IPSET_ATTR_IFACE] ||
!ip_set_optattr_netorder(tb, IPSET_ATTR_TIMEOUT) ||
!ip_set_optattr_netorder(tb, IPSET_ATTR_CADT_FLAGS) ||
!ip_set_optattr_netorder(tb, IPSET_ATTR_PACKETS) ||
!ip_set_optattr_netorder(tb, IPSET_ATTR_BYTES) ||
!ip_set_optattr_netorder(tb, IPSET_ATTR_SKBMARK) ||
!ip_set_optattr_netorder(tb, IPSET_ATTR_SKBPRIO) ||
!ip_set_optattr_netorder(tb, IPSET_ATTR_SKBQUEUE)))
return -IPSET_ERR_PROTOCOL;
if (unlikely(tb[IPSET_ATTR_IP_TO]))
return -IPSET_ERR_HASH_RANGE_UNSUPPORTED;
if (tb[IPSET_ATTR_LINENO])
*lineno = nla_get_u32(tb[IPSET_ATTR_LINENO]);
ret = ip_set_get_ipaddr6(tb[IPSET_ATTR_IP], &e.ip) ||
ip_set_get_extensions(set, tb, &ext);
if (ret)
return ret;
if (tb[IPSET_ATTR_CIDR])
e.cidr = nla_get_u8(tb[IPSET_ATTR_CIDR]);
if (e.cidr > HOST_MASK)
return -IPSET_ERR_INVALID_CIDR;
ip6_netmask(&e.ip, e.cidr);
strcpy(iface, nla_data(tb[IPSET_ATTR_IFACE]));
e.iface = iface;
ret = iface_test(&h->rbtree, &e.iface);
if (adt == IPSET_ADD) {
if (!ret) {
ret = iface_add(&h->rbtree, &e.iface);
if (ret)
return ret;
}
} else if (!ret)
return ret;
if (tb[IPSET_ATTR_CADT_FLAGS]) {
u32 cadt_flags = ip_set_get_h32(tb[IPSET_ATTR_CADT_FLAGS]);
if (cadt_flags & IPSET_FLAG_PHYSDEV)
e.physdev = 1;
if (cadt_flags & IPSET_FLAG_NOMATCH)
flags |= (IPSET_FLAG_NOMATCH << 16);
}
ret = adtfn(set, &e, &ext, &ext, flags);
return ip_set_enomatch(ret, flags, adt, set) ? -ret :
ip_set_eexist(ret, flags) ? 0 : ret;
}
static int __init
hash_netiface_init(void)
{
return ip_set_type_register(&hash_netiface_type);
}
static void __exit
hash_netiface_fini(void)
{
ip_set_type_unregister(&hash_netiface_type);
}
