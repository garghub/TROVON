int netlbl_cfg_map_del(const char *domain,
u16 family,
const void *addr,
const void *mask,
struct netlbl_audit *audit_info)
{
if (addr == NULL && mask == NULL) {
return netlbl_domhsh_remove(domain, audit_info);
} else if (addr != NULL && mask != NULL) {
switch (family) {
case AF_INET:
return netlbl_domhsh_remove_af4(domain, addr, mask,
audit_info);
default:
return -EPFNOSUPPORT;
}
} else
return -EINVAL;
}
int netlbl_cfg_unlbl_map_add(const char *domain,
u16 family,
const void *addr,
const void *mask,
struct netlbl_audit *audit_info)
{
int ret_val = -ENOMEM;
struct netlbl_dom_map *entry;
struct netlbl_domaddr_map *addrmap = NULL;
struct netlbl_domaddr4_map *map4 = NULL;
struct netlbl_domaddr6_map *map6 = NULL;
entry = kzalloc(sizeof(*entry), GFP_ATOMIC);
if (entry == NULL)
return -ENOMEM;
if (domain != NULL) {
entry->domain = kstrdup(domain, GFP_ATOMIC);
if (entry->domain == NULL)
goto cfg_unlbl_map_add_failure;
}
if (addr == NULL && mask == NULL)
entry->def.type = NETLBL_NLTYPE_UNLABELED;
else if (addr != NULL && mask != NULL) {
addrmap = kzalloc(sizeof(*addrmap), GFP_ATOMIC);
if (addrmap == NULL)
goto cfg_unlbl_map_add_failure;
INIT_LIST_HEAD(&addrmap->list4);
INIT_LIST_HEAD(&addrmap->list6);
switch (family) {
case AF_INET: {
const struct in_addr *addr4 = addr;
const struct in_addr *mask4 = mask;
map4 = kzalloc(sizeof(*map4), GFP_ATOMIC);
if (map4 == NULL)
goto cfg_unlbl_map_add_failure;
map4->def.type = NETLBL_NLTYPE_UNLABELED;
map4->list.addr = addr4->s_addr & mask4->s_addr;
map4->list.mask = mask4->s_addr;
map4->list.valid = 1;
ret_val = netlbl_af4list_add(&map4->list,
&addrmap->list4);
if (ret_val != 0)
goto cfg_unlbl_map_add_failure;
break;
}
#if IS_ENABLED(CONFIG_IPV6)
case AF_INET6: {
const struct in6_addr *addr6 = addr;
const struct in6_addr *mask6 = mask;
map6 = kzalloc(sizeof(*map6), GFP_ATOMIC);
if (map6 == NULL)
goto cfg_unlbl_map_add_failure;
map6->def.type = NETLBL_NLTYPE_UNLABELED;
map6->list.addr = *addr6;
map6->list.addr.s6_addr32[0] &= mask6->s6_addr32[0];
map6->list.addr.s6_addr32[1] &= mask6->s6_addr32[1];
map6->list.addr.s6_addr32[2] &= mask6->s6_addr32[2];
map6->list.addr.s6_addr32[3] &= mask6->s6_addr32[3];
map6->list.mask = *mask6;
map6->list.valid = 1;
ret_val = netlbl_af6list_add(&map6->list,
&addrmap->list6);
if (ret_val != 0)
goto cfg_unlbl_map_add_failure;
break;
}
#endif
default:
goto cfg_unlbl_map_add_failure;
}
entry->def.addrsel = addrmap;
entry->def.type = NETLBL_NLTYPE_ADDRSELECT;
} else {
ret_val = -EINVAL;
goto cfg_unlbl_map_add_failure;
}
ret_val = netlbl_domhsh_add(entry, audit_info);
if (ret_val != 0)
goto cfg_unlbl_map_add_failure;
return 0;
cfg_unlbl_map_add_failure:
kfree(entry->domain);
kfree(entry);
kfree(addrmap);
kfree(map4);
kfree(map6);
return ret_val;
}
int netlbl_cfg_unlbl_static_add(struct net *net,
const char *dev_name,
const void *addr,
const void *mask,
u16 family,
u32 secid,
struct netlbl_audit *audit_info)
{
u32 addr_len;
switch (family) {
case AF_INET:
addr_len = sizeof(struct in_addr);
break;
#if IS_ENABLED(CONFIG_IPV6)
case AF_INET6:
addr_len = sizeof(struct in6_addr);
break;
#endif
default:
return -EPFNOSUPPORT;
}
return netlbl_unlhsh_add(net,
dev_name, addr, mask, addr_len,
secid, audit_info);
}
int netlbl_cfg_unlbl_static_del(struct net *net,
const char *dev_name,
const void *addr,
const void *mask,
u16 family,
struct netlbl_audit *audit_info)
{
u32 addr_len;
switch (family) {
case AF_INET:
addr_len = sizeof(struct in_addr);
break;
#if IS_ENABLED(CONFIG_IPV6)
case AF_INET6:
addr_len = sizeof(struct in6_addr);
break;
#endif
default:
return -EPFNOSUPPORT;
}
return netlbl_unlhsh_remove(net,
dev_name, addr, mask, addr_len,
audit_info);
}
int netlbl_cfg_cipsov4_add(struct cipso_v4_doi *doi_def,
struct netlbl_audit *audit_info)
{
return cipso_v4_doi_add(doi_def, audit_info);
}
void netlbl_cfg_cipsov4_del(u32 doi, struct netlbl_audit *audit_info)
{
cipso_v4_doi_remove(doi, audit_info);
}
int netlbl_cfg_cipsov4_map_add(u32 doi,
const char *domain,
const struct in_addr *addr,
const struct in_addr *mask,
struct netlbl_audit *audit_info)
{
int ret_val = -ENOMEM;
struct cipso_v4_doi *doi_def;
struct netlbl_dom_map *entry;
struct netlbl_domaddr_map *addrmap = NULL;
struct netlbl_domaddr4_map *addrinfo = NULL;
doi_def = cipso_v4_doi_getdef(doi);
if (doi_def == NULL)
return -ENOENT;
entry = kzalloc(sizeof(*entry), GFP_ATOMIC);
if (entry == NULL)
goto out_entry;
if (domain != NULL) {
entry->domain = kstrdup(domain, GFP_ATOMIC);
if (entry->domain == NULL)
goto out_domain;
}
if (addr == NULL && mask == NULL) {
entry->def.cipso = doi_def;
entry->def.type = NETLBL_NLTYPE_CIPSOV4;
} else if (addr != NULL && mask != NULL) {
addrmap = kzalloc(sizeof(*addrmap), GFP_ATOMIC);
if (addrmap == NULL)
goto out_addrmap;
INIT_LIST_HEAD(&addrmap->list4);
INIT_LIST_HEAD(&addrmap->list6);
addrinfo = kzalloc(sizeof(*addrinfo), GFP_ATOMIC);
if (addrinfo == NULL)
goto out_addrinfo;
addrinfo->def.cipso = doi_def;
addrinfo->def.type = NETLBL_NLTYPE_CIPSOV4;
addrinfo->list.addr = addr->s_addr & mask->s_addr;
addrinfo->list.mask = mask->s_addr;
addrinfo->list.valid = 1;
ret_val = netlbl_af4list_add(&addrinfo->list, &addrmap->list4);
if (ret_val != 0)
goto cfg_cipsov4_map_add_failure;
entry->def.addrsel = addrmap;
entry->def.type = NETLBL_NLTYPE_ADDRSELECT;
} else {
ret_val = -EINVAL;
goto out_addrmap;
}
ret_val = netlbl_domhsh_add(entry, audit_info);
if (ret_val != 0)
goto cfg_cipsov4_map_add_failure;
return 0;
cfg_cipsov4_map_add_failure:
kfree(addrinfo);
out_addrinfo:
kfree(addrmap);
out_addrmap:
kfree(entry->domain);
out_domain:
kfree(entry);
out_entry:
cipso_v4_doi_putdef(doi_def);
return ret_val;
}
static struct netlbl_lsm_catmap *_netlbl_catmap_getnode(
struct netlbl_lsm_catmap **catmap,
u32 offset,
unsigned int cm_flags,
gfp_t gfp_flags)
{
struct netlbl_lsm_catmap *iter = *catmap;
struct netlbl_lsm_catmap *prev = NULL;
if (iter == NULL)
goto catmap_getnode_alloc;
if (offset < iter->startbit)
goto catmap_getnode_walk;
while (iter && offset >= (iter->startbit + NETLBL_CATMAP_SIZE)) {
prev = iter;
iter = iter->next;
}
if (iter == NULL || offset < iter->startbit)
goto catmap_getnode_walk;
return iter;
catmap_getnode_walk:
if (cm_flags & _CM_F_WALK)
return iter;
catmap_getnode_alloc:
if (!(cm_flags & _CM_F_ALLOC))
return NULL;
iter = netlbl_catmap_alloc(gfp_flags);
if (iter == NULL)
return NULL;
iter->startbit = offset & ~(NETLBL_CATMAP_SIZE - 1);
if (prev == NULL) {
iter->next = *catmap;
*catmap = iter;
} else {
iter->next = prev->next;
prev->next = iter;
}
return iter;
}
int netlbl_catmap_walk(struct netlbl_lsm_catmap *catmap, u32 offset)
{
struct netlbl_lsm_catmap *iter = catmap;
u32 idx;
u32 bit;
NETLBL_CATMAP_MAPTYPE bitmap;
iter = _netlbl_catmap_getnode(&catmap, offset, _CM_F_WALK, 0);
if (iter == NULL)
return -ENOENT;
if (offset > iter->startbit) {
offset -= iter->startbit;
idx = offset / NETLBL_CATMAP_MAPSIZE;
bit = offset % NETLBL_CATMAP_MAPSIZE;
} else {
idx = 0;
bit = 0;
}
bitmap = iter->bitmap[idx] >> bit;
for (;;) {
if (bitmap != 0) {
while ((bitmap & NETLBL_CATMAP_BIT) == 0) {
bitmap >>= 1;
bit++;
}
return iter->startbit +
(NETLBL_CATMAP_MAPSIZE * idx) + bit;
}
if (++idx >= NETLBL_CATMAP_MAPCNT) {
if (iter->next != NULL) {
iter = iter->next;
idx = 0;
} else
return -ENOENT;
}
bitmap = iter->bitmap[idx];
bit = 0;
}
return -ENOENT;
}
int netlbl_catmap_walkrng(struct netlbl_lsm_catmap *catmap, u32 offset)
{
struct netlbl_lsm_catmap *iter;
struct netlbl_lsm_catmap *prev = NULL;
u32 idx;
u32 bit;
NETLBL_CATMAP_MAPTYPE bitmask;
NETLBL_CATMAP_MAPTYPE bitmap;
iter = _netlbl_catmap_getnode(&catmap, offset, _CM_F_WALK, 0);
if (iter == NULL)
return -ENOENT;
if (offset > iter->startbit) {
offset -= iter->startbit;
idx = offset / NETLBL_CATMAP_MAPSIZE;
bit = offset % NETLBL_CATMAP_MAPSIZE;
} else {
idx = 0;
bit = 0;
}
bitmask = NETLBL_CATMAP_BIT << bit;
for (;;) {
bitmap = iter->bitmap[idx];
while (bitmask != 0 && (bitmap & bitmask) != 0) {
bitmask <<= 1;
bit++;
}
if (prev && idx == 0 && bit == 0)
return prev->startbit + NETLBL_CATMAP_SIZE - 1;
else if (bitmask != 0)
return iter->startbit +
(NETLBL_CATMAP_MAPSIZE * idx) + bit - 1;
else if (++idx >= NETLBL_CATMAP_MAPCNT) {
if (iter->next == NULL)
return iter->startbit + NETLBL_CATMAP_SIZE - 1;
prev = iter;
iter = iter->next;
idx = 0;
}
bitmask = NETLBL_CATMAP_BIT;
bit = 0;
}
return -ENOENT;
}
int netlbl_catmap_getlong(struct netlbl_lsm_catmap *catmap,
u32 *offset,
unsigned long *bitmap)
{
struct netlbl_lsm_catmap *iter;
u32 off = *offset;
u32 idx;
if ((off & (BITS_PER_LONG - 1)) != 0)
return -EINVAL;
if (off < catmap->startbit) {
off = catmap->startbit;
*offset = off;
}
iter = _netlbl_catmap_getnode(&catmap, off, _CM_F_NONE, 0);
if (iter == NULL) {
*offset = (u32)-1;
return 0;
}
if (off < iter->startbit) {
off = iter->startbit;
*offset = off;
} else
off -= iter->startbit;
idx = off / NETLBL_CATMAP_MAPSIZE;
*bitmap = iter->bitmap[idx] >> (off % NETLBL_CATMAP_SIZE);
return 0;
}
int netlbl_catmap_setbit(struct netlbl_lsm_catmap **catmap,
u32 bit,
gfp_t flags)
{
struct netlbl_lsm_catmap *iter;
u32 idx;
iter = _netlbl_catmap_getnode(catmap, bit, _CM_F_ALLOC, flags);
if (iter == NULL)
return -ENOMEM;
bit -= iter->startbit;
idx = bit / NETLBL_CATMAP_MAPSIZE;
iter->bitmap[idx] |= NETLBL_CATMAP_BIT << (bit % NETLBL_CATMAP_MAPSIZE);
return 0;
}
int netlbl_catmap_setrng(struct netlbl_lsm_catmap **catmap,
u32 start,
u32 end,
gfp_t flags)
{
int rc = 0;
u32 spot = start;
while (rc == 0 && spot <= end) {
if (((spot & (BITS_PER_LONG - 1)) != 0) &&
((end - spot) > BITS_PER_LONG)) {
rc = netlbl_catmap_setlong(catmap,
spot,
(unsigned long)-1,
flags);
spot += BITS_PER_LONG;
} else
rc = netlbl_catmap_setbit(catmap, spot++, flags);
}
return rc;
}
int netlbl_catmap_setlong(struct netlbl_lsm_catmap **catmap,
u32 offset,
unsigned long bitmap,
gfp_t flags)
{
struct netlbl_lsm_catmap *iter;
u32 idx;
if ((offset & (BITS_PER_LONG - 1)) != 0)
return -EINVAL;
iter = _netlbl_catmap_getnode(catmap, offset, _CM_F_ALLOC, flags);
if (iter == NULL)
return -ENOMEM;
offset -= iter->startbit;
idx = offset / NETLBL_CATMAP_MAPSIZE;
iter->bitmap[idx] |= bitmap << (offset % NETLBL_CATMAP_MAPSIZE);
return 0;
}
int netlbl_enabled(void)
{
return (atomic_read(&netlabel_mgmt_protocount) > 0);
}
int netlbl_sock_setattr(struct sock *sk,
u16 family,
const struct netlbl_lsm_secattr *secattr)
{
int ret_val;
struct netlbl_dom_map *dom_entry;
rcu_read_lock();
dom_entry = netlbl_domhsh_getentry(secattr->domain);
if (dom_entry == NULL) {
ret_val = -ENOENT;
goto socket_setattr_return;
}
switch (family) {
case AF_INET:
switch (dom_entry->def.type) {
case NETLBL_NLTYPE_ADDRSELECT:
ret_val = -EDESTADDRREQ;
break;
case NETLBL_NLTYPE_CIPSOV4:
ret_val = cipso_v4_sock_setattr(sk,
dom_entry->def.cipso,
secattr);
break;
case NETLBL_NLTYPE_UNLABELED:
ret_val = 0;
break;
default:
ret_val = -ENOENT;
}
break;
#if IS_ENABLED(CONFIG_IPV6)
case AF_INET6:
ret_val = 0;
break;
#endif
default:
ret_val = -EPROTONOSUPPORT;
}
socket_setattr_return:
rcu_read_unlock();
return ret_val;
}
void netlbl_sock_delattr(struct sock *sk)
{
cipso_v4_sock_delattr(sk);
}
int netlbl_sock_getattr(struct sock *sk,
struct netlbl_lsm_secattr *secattr)
{
int ret_val;
switch (sk->sk_family) {
case AF_INET:
ret_val = cipso_v4_sock_getattr(sk, secattr);
break;
#if IS_ENABLED(CONFIG_IPV6)
case AF_INET6:
ret_val = -ENOMSG;
break;
#endif
default:
ret_val = -EPROTONOSUPPORT;
}
return ret_val;
}
int netlbl_conn_setattr(struct sock *sk,
struct sockaddr *addr,
const struct netlbl_lsm_secattr *secattr)
{
int ret_val;
struct sockaddr_in *addr4;
struct netlbl_dommap_def *entry;
rcu_read_lock();
switch (addr->sa_family) {
case AF_INET:
addr4 = (struct sockaddr_in *)addr;
entry = netlbl_domhsh_getentry_af4(secattr->domain,
addr4->sin_addr.s_addr);
if (entry == NULL) {
ret_val = -ENOENT;
goto conn_setattr_return;
}
switch (entry->type) {
case NETLBL_NLTYPE_CIPSOV4:
ret_val = cipso_v4_sock_setattr(sk,
entry->cipso, secattr);
break;
case NETLBL_NLTYPE_UNLABELED:
cipso_v4_sock_delattr(sk);
ret_val = 0;
break;
default:
ret_val = -ENOENT;
}
break;
#if IS_ENABLED(CONFIG_IPV6)
case AF_INET6:
ret_val = 0;
break;
#endif
default:
ret_val = -EPROTONOSUPPORT;
}
conn_setattr_return:
rcu_read_unlock();
return ret_val;
}
int netlbl_req_setattr(struct request_sock *req,
const struct netlbl_lsm_secattr *secattr)
{
int ret_val;
struct netlbl_dommap_def *entry;
rcu_read_lock();
switch (req->rsk_ops->family) {
case AF_INET:
entry = netlbl_domhsh_getentry_af4(secattr->domain,
inet_rsk(req)->ir_rmt_addr);
if (entry == NULL) {
ret_val = -ENOENT;
goto req_setattr_return;
}
switch (entry->type) {
case NETLBL_NLTYPE_CIPSOV4:
ret_val = cipso_v4_req_setattr(req,
entry->cipso, secattr);
break;
case NETLBL_NLTYPE_UNLABELED:
cipso_v4_req_delattr(req);
ret_val = 0;
break;
default:
ret_val = -ENOENT;
}
break;
#if IS_ENABLED(CONFIG_IPV6)
case AF_INET6:
ret_val = 0;
break;
#endif
default:
ret_val = -EPROTONOSUPPORT;
}
req_setattr_return:
rcu_read_unlock();
return ret_val;
}
void netlbl_req_delattr(struct request_sock *req)
{
cipso_v4_req_delattr(req);
}
int netlbl_skbuff_setattr(struct sk_buff *skb,
u16 family,
const struct netlbl_lsm_secattr *secattr)
{
int ret_val;
struct iphdr *hdr4;
struct netlbl_dommap_def *entry;
rcu_read_lock();
switch (family) {
case AF_INET:
hdr4 = ip_hdr(skb);
entry = netlbl_domhsh_getentry_af4(secattr->domain,hdr4->daddr);
if (entry == NULL) {
ret_val = -ENOENT;
goto skbuff_setattr_return;
}
switch (entry->type) {
case NETLBL_NLTYPE_CIPSOV4:
ret_val = cipso_v4_skbuff_setattr(skb, entry->cipso,
secattr);
break;
case NETLBL_NLTYPE_UNLABELED:
ret_val = cipso_v4_skbuff_delattr(skb);
break;
default:
ret_val = -ENOENT;
}
break;
#if IS_ENABLED(CONFIG_IPV6)
case AF_INET6:
ret_val = 0;
break;
#endif
default:
ret_val = -EPROTONOSUPPORT;
}
skbuff_setattr_return:
rcu_read_unlock();
return ret_val;
}
int netlbl_skbuff_getattr(const struct sk_buff *skb,
u16 family,
struct netlbl_lsm_secattr *secattr)
{
switch (family) {
case AF_INET:
if (CIPSO_V4_OPTEXIST(skb) &&
cipso_v4_skbuff_getattr(skb, secattr) == 0)
return 0;
break;
#if IS_ENABLED(CONFIG_IPV6)
case AF_INET6:
break;
#endif
}
return netlbl_unlabel_getattr(skb, family, secattr);
}
void netlbl_skbuff_err(struct sk_buff *skb, int error, int gateway)
{
if (CIPSO_V4_OPTEXIST(skb))
cipso_v4_error(skb, error, gateway);
}
void netlbl_cache_invalidate(void)
{
cipso_v4_cache_invalidate();
}
int netlbl_cache_add(const struct sk_buff *skb,
const struct netlbl_lsm_secattr *secattr)
{
if ((secattr->flags & NETLBL_SECATTR_CACHE) == 0)
return -ENOMSG;
if (CIPSO_V4_OPTEXIST(skb))
return cipso_v4_cache_add(skb, secattr);
return -ENOMSG;
}
struct audit_buffer *netlbl_audit_start(int type,
struct netlbl_audit *audit_info)
{
return netlbl_audit_start_common(type, audit_info);
}
static int __init netlbl_init(void)
{
int ret_val;
printk(KERN_INFO "NetLabel: Initializing\n");
printk(KERN_INFO "NetLabel: domain hash size = %u\n",
(1 << NETLBL_DOMHSH_BITSIZE));
printk(KERN_INFO "NetLabel: protocols ="
" UNLABELED"
" CIPSOv4"
"\n");
ret_val = netlbl_domhsh_init(NETLBL_DOMHSH_BITSIZE);
if (ret_val != 0)
goto init_failure;
ret_val = netlbl_unlabel_init(NETLBL_UNLHSH_BITSIZE);
if (ret_val != 0)
goto init_failure;
ret_val = netlbl_netlink_init();
if (ret_val != 0)
goto init_failure;
ret_val = netlbl_unlabel_defconf();
if (ret_val != 0)
goto init_failure;
printk(KERN_INFO "NetLabel: unlabeled traffic allowed by default\n");
return 0;
init_failure:
panic("NetLabel: failed to initialize properly (%d)\n", ret_val);
}
