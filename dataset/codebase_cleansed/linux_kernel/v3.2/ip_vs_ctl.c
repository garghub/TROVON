int ip_vs_get_debug_level(void)
{
return sysctl_ip_vs_debug_level;
}
static int __ip_vs_addr_is_local_v6(struct net *net,
const struct in6_addr *addr)
{
struct rt6_info *rt;
struct flowi6 fl6 = {
.daddr = *addr,
};
rt = (struct rt6_info *)ip6_route_output(net, NULL, &fl6);
if (rt && rt->rt6i_dev && (rt->rt6i_dev->flags & IFF_LOOPBACK))
return 1;
return 0;
}
static void update_defense_level(struct netns_ipvs *ipvs)
{
struct sysinfo i;
static int old_secure_tcp = 0;
int availmem;
int nomem;
int to_change = -1;
si_meminfo(&i);
availmem = i.freeram + i.bufferram;
nomem = (availmem < ipvs->sysctl_amemthresh);
local_bh_disable();
spin_lock(&ipvs->dropentry_lock);
switch (ipvs->sysctl_drop_entry) {
case 0:
atomic_set(&ipvs->dropentry, 0);
break;
case 1:
if (nomem) {
atomic_set(&ipvs->dropentry, 1);
ipvs->sysctl_drop_entry = 2;
} else {
atomic_set(&ipvs->dropentry, 0);
}
break;
case 2:
if (nomem) {
atomic_set(&ipvs->dropentry, 1);
} else {
atomic_set(&ipvs->dropentry, 0);
ipvs->sysctl_drop_entry = 1;
};
break;
case 3:
atomic_set(&ipvs->dropentry, 1);
break;
}
spin_unlock(&ipvs->dropentry_lock);
spin_lock(&ipvs->droppacket_lock);
switch (ipvs->sysctl_drop_packet) {
case 0:
ipvs->drop_rate = 0;
break;
case 1:
if (nomem) {
ipvs->drop_rate = ipvs->drop_counter
= ipvs->sysctl_amemthresh /
(ipvs->sysctl_amemthresh-availmem);
ipvs->sysctl_drop_packet = 2;
} else {
ipvs->drop_rate = 0;
}
break;
case 2:
if (nomem) {
ipvs->drop_rate = ipvs->drop_counter
= ipvs->sysctl_amemthresh /
(ipvs->sysctl_amemthresh-availmem);
} else {
ipvs->drop_rate = 0;
ipvs->sysctl_drop_packet = 1;
}
break;
case 3:
ipvs->drop_rate = ipvs->sysctl_am_droprate;
break;
}
spin_unlock(&ipvs->droppacket_lock);
spin_lock(&ipvs->securetcp_lock);
switch (ipvs->sysctl_secure_tcp) {
case 0:
if (old_secure_tcp >= 2)
to_change = 0;
break;
case 1:
if (nomem) {
if (old_secure_tcp < 2)
to_change = 1;
ipvs->sysctl_secure_tcp = 2;
} else {
if (old_secure_tcp >= 2)
to_change = 0;
}
break;
case 2:
if (nomem) {
if (old_secure_tcp < 2)
to_change = 1;
} else {
if (old_secure_tcp >= 2)
to_change = 0;
ipvs->sysctl_secure_tcp = 1;
}
break;
case 3:
if (old_secure_tcp < 2)
to_change = 1;
break;
}
old_secure_tcp = ipvs->sysctl_secure_tcp;
if (to_change >= 0)
ip_vs_protocol_timeout_change(ipvs,
ipvs->sysctl_secure_tcp > 1);
spin_unlock(&ipvs->securetcp_lock);
local_bh_enable();
}
static void defense_work_handler(struct work_struct *work)
{
struct netns_ipvs *ipvs =
container_of(work, struct netns_ipvs, defense_work.work);
update_defense_level(ipvs);
if (atomic_read(&ipvs->dropentry))
ip_vs_random_dropentry(ipvs->net);
schedule_delayed_work(&ipvs->defense_work, DEFENSE_TIMER_PERIOD);
}
int
ip_vs_use_count_inc(void)
{
return try_module_get(THIS_MODULE);
}
void
ip_vs_use_count_dec(void)
{
module_put(THIS_MODULE);
}
static inline unsigned
ip_vs_svc_hashkey(struct net *net, int af, unsigned proto,
const union nf_inet_addr *addr, __be16 port)
{
register unsigned porth = ntohs(port);
__be32 addr_fold = addr->ip;
#ifdef CONFIG_IP_VS_IPV6
if (af == AF_INET6)
addr_fold = addr->ip6[0]^addr->ip6[1]^
addr->ip6[2]^addr->ip6[3];
#endif
addr_fold ^= ((size_t)net>>8);
return (proto^ntohl(addr_fold)^(porth>>IP_VS_SVC_TAB_BITS)^porth)
& IP_VS_SVC_TAB_MASK;
}
static inline unsigned ip_vs_svc_fwm_hashkey(struct net *net, __u32 fwmark)
{
return (((size_t)net>>8) ^ fwmark) & IP_VS_SVC_TAB_MASK;
}
static int ip_vs_svc_hash(struct ip_vs_service *svc)
{
unsigned hash;
if (svc->flags & IP_VS_SVC_F_HASHED) {
pr_err("%s(): request for already hashed, called from %pF\n",
__func__, __builtin_return_address(0));
return 0;
}
if (svc->fwmark == 0) {
hash = ip_vs_svc_hashkey(svc->net, svc->af, svc->protocol,
&svc->addr, svc->port);
list_add(&svc->s_list, &ip_vs_svc_table[hash]);
} else {
hash = ip_vs_svc_fwm_hashkey(svc->net, svc->fwmark);
list_add(&svc->f_list, &ip_vs_svc_fwm_table[hash]);
}
svc->flags |= IP_VS_SVC_F_HASHED;
atomic_inc(&svc->refcnt);
return 1;
}
static int ip_vs_svc_unhash(struct ip_vs_service *svc)
{
if (!(svc->flags & IP_VS_SVC_F_HASHED)) {
pr_err("%s(): request for unhash flagged, called from %pF\n",
__func__, __builtin_return_address(0));
return 0;
}
if (svc->fwmark == 0) {
list_del(&svc->s_list);
} else {
list_del(&svc->f_list);
}
svc->flags &= ~IP_VS_SVC_F_HASHED;
atomic_dec(&svc->refcnt);
return 1;
}
static inline struct ip_vs_service *
__ip_vs_service_find(struct net *net, int af, __u16 protocol,
const union nf_inet_addr *vaddr, __be16 vport)
{
unsigned hash;
struct ip_vs_service *svc;
hash = ip_vs_svc_hashkey(net, af, protocol, vaddr, vport);
list_for_each_entry(svc, &ip_vs_svc_table[hash], s_list){
if ((svc->af == af)
&& ip_vs_addr_equal(af, &svc->addr, vaddr)
&& (svc->port == vport)
&& (svc->protocol == protocol)
&& net_eq(svc->net, net)) {
return svc;
}
}
return NULL;
}
static inline struct ip_vs_service *
__ip_vs_svc_fwm_find(struct net *net, int af, __u32 fwmark)
{
unsigned hash;
struct ip_vs_service *svc;
hash = ip_vs_svc_fwm_hashkey(net, fwmark);
list_for_each_entry(svc, &ip_vs_svc_fwm_table[hash], f_list) {
if (svc->fwmark == fwmark && svc->af == af
&& net_eq(svc->net, net)) {
return svc;
}
}
return NULL;
}
struct ip_vs_service *
ip_vs_service_get(struct net *net, int af, __u32 fwmark, __u16 protocol,
const union nf_inet_addr *vaddr, __be16 vport)
{
struct ip_vs_service *svc;
struct netns_ipvs *ipvs = net_ipvs(net);
read_lock(&__ip_vs_svc_lock);
if (fwmark) {
svc = __ip_vs_svc_fwm_find(net, af, fwmark);
if (svc)
goto out;
}
svc = __ip_vs_service_find(net, af, protocol, vaddr, vport);
if (svc == NULL
&& protocol == IPPROTO_TCP
&& atomic_read(&ipvs->ftpsvc_counter)
&& (vport == FTPDATA || ntohs(vport) >= PROT_SOCK)) {
svc = __ip_vs_service_find(net, af, protocol, vaddr, FTPPORT);
}
if (svc == NULL
&& atomic_read(&ipvs->nullsvc_counter)) {
svc = __ip_vs_service_find(net, af, protocol, vaddr, 0);
}
out:
if (svc)
atomic_inc(&svc->usecnt);
read_unlock(&__ip_vs_svc_lock);
IP_VS_DBG_BUF(9, "lookup service: fwm %u %s %s:%u %s\n",
fwmark, ip_vs_proto_name(protocol),
IP_VS_DBG_ADDR(af, vaddr), ntohs(vport),
svc ? "hit" : "not hit");
return svc;
}
static inline void
__ip_vs_bind_svc(struct ip_vs_dest *dest, struct ip_vs_service *svc)
{
atomic_inc(&svc->refcnt);
dest->svc = svc;
}
static void
__ip_vs_unbind_svc(struct ip_vs_dest *dest)
{
struct ip_vs_service *svc = dest->svc;
dest->svc = NULL;
if (atomic_dec_and_test(&svc->refcnt)) {
IP_VS_DBG_BUF(3, "Removing service %u/%s:%u usecnt=%d\n",
svc->fwmark,
IP_VS_DBG_ADDR(svc->af, &svc->addr),
ntohs(svc->port), atomic_read(&svc->usecnt));
free_percpu(svc->stats.cpustats);
kfree(svc);
}
}
static inline unsigned ip_vs_rs_hashkey(int af,
const union nf_inet_addr *addr,
__be16 port)
{
register unsigned porth = ntohs(port);
__be32 addr_fold = addr->ip;
#ifdef CONFIG_IP_VS_IPV6
if (af == AF_INET6)
addr_fold = addr->ip6[0]^addr->ip6[1]^
addr->ip6[2]^addr->ip6[3];
#endif
return (ntohl(addr_fold)^(porth>>IP_VS_RTAB_BITS)^porth)
& IP_VS_RTAB_MASK;
}
static int ip_vs_rs_hash(struct netns_ipvs *ipvs, struct ip_vs_dest *dest)
{
unsigned hash;
if (!list_empty(&dest->d_list)) {
return 0;
}
hash = ip_vs_rs_hashkey(dest->af, &dest->addr, dest->port);
list_add(&dest->d_list, &ipvs->rs_table[hash]);
return 1;
}
static int ip_vs_rs_unhash(struct ip_vs_dest *dest)
{
if (!list_empty(&dest->d_list)) {
list_del(&dest->d_list);
INIT_LIST_HEAD(&dest->d_list);
}
return 1;
}
struct ip_vs_dest *
ip_vs_lookup_real_service(struct net *net, int af, __u16 protocol,
const union nf_inet_addr *daddr,
__be16 dport)
{
struct netns_ipvs *ipvs = net_ipvs(net);
unsigned hash;
struct ip_vs_dest *dest;
hash = ip_vs_rs_hashkey(af, daddr, dport);
read_lock(&ipvs->rs_lock);
list_for_each_entry(dest, &ipvs->rs_table[hash], d_list) {
if ((dest->af == af)
&& ip_vs_addr_equal(af, &dest->addr, daddr)
&& (dest->port == dport)
&& ((dest->protocol == protocol) ||
dest->vfwmark)) {
read_unlock(&ipvs->rs_lock);
return dest;
}
}
read_unlock(&ipvs->rs_lock);
return NULL;
}
static struct ip_vs_dest *
ip_vs_lookup_dest(struct ip_vs_service *svc, const union nf_inet_addr *daddr,
__be16 dport)
{
struct ip_vs_dest *dest;
list_for_each_entry(dest, &svc->destinations, n_list) {
if ((dest->af == svc->af)
&& ip_vs_addr_equal(svc->af, &dest->addr, daddr)
&& (dest->port == dport)) {
return dest;
}
}
return NULL;
}
struct ip_vs_dest *ip_vs_find_dest(struct net *net, int af,
const union nf_inet_addr *daddr,
__be16 dport,
const union nf_inet_addr *vaddr,
__be16 vport, __u16 protocol, __u32 fwmark,
__u32 flags)
{
struct ip_vs_dest *dest;
struct ip_vs_service *svc;
__be16 port = dport;
svc = ip_vs_service_get(net, af, fwmark, protocol, vaddr, vport);
if (!svc)
return NULL;
if (fwmark && (flags & IP_VS_CONN_F_FWD_MASK) != IP_VS_CONN_F_MASQ)
port = 0;
dest = ip_vs_lookup_dest(svc, daddr, port);
if (!dest)
dest = ip_vs_lookup_dest(svc, daddr, port ^ dport);
if (dest)
atomic_inc(&dest->refcnt);
ip_vs_service_put(svc);
return dest;
}
static struct ip_vs_dest *
ip_vs_trash_get_dest(struct ip_vs_service *svc, const union nf_inet_addr *daddr,
__be16 dport)
{
struct ip_vs_dest *dest, *nxt;
struct netns_ipvs *ipvs = net_ipvs(svc->net);
list_for_each_entry_safe(dest, nxt, &ipvs->dest_trash, n_list) {
IP_VS_DBG_BUF(3, "Destination %u/%s:%u still in trash, "
"dest->refcnt=%d\n",
dest->vfwmark,
IP_VS_DBG_ADDR(svc->af, &dest->addr),
ntohs(dest->port),
atomic_read(&dest->refcnt));
if (dest->af == svc->af &&
ip_vs_addr_equal(svc->af, &dest->addr, daddr) &&
dest->port == dport &&
dest->vfwmark == svc->fwmark &&
dest->protocol == svc->protocol &&
(svc->fwmark ||
(ip_vs_addr_equal(svc->af, &dest->vaddr, &svc->addr) &&
dest->vport == svc->port))) {
return dest;
}
if (atomic_read(&dest->refcnt) == 1) {
IP_VS_DBG_BUF(3, "Removing destination %u/%s:%u "
"from trash\n",
dest->vfwmark,
IP_VS_DBG_ADDR(svc->af, &dest->addr),
ntohs(dest->port));
list_del(&dest->n_list);
ip_vs_dst_reset(dest);
__ip_vs_unbind_svc(dest);
free_percpu(dest->stats.cpustats);
kfree(dest);
}
}
return NULL;
}
static void ip_vs_trash_cleanup(struct net *net)
{
struct ip_vs_dest *dest, *nxt;
struct netns_ipvs *ipvs = net_ipvs(net);
list_for_each_entry_safe(dest, nxt, &ipvs->dest_trash, n_list) {
list_del(&dest->n_list);
ip_vs_dst_reset(dest);
__ip_vs_unbind_svc(dest);
free_percpu(dest->stats.cpustats);
kfree(dest);
}
}
static void
ip_vs_copy_stats(struct ip_vs_stats_user *dst, struct ip_vs_stats *src)
{
#define IP_VS_SHOW_STATS_COUNTER(c) dst->c = src->ustats.c - src->ustats0.c
spin_lock_bh(&src->lock);
IP_VS_SHOW_STATS_COUNTER(conns);
IP_VS_SHOW_STATS_COUNTER(inpkts);
IP_VS_SHOW_STATS_COUNTER(outpkts);
IP_VS_SHOW_STATS_COUNTER(inbytes);
IP_VS_SHOW_STATS_COUNTER(outbytes);
ip_vs_read_estimator(dst, src);
spin_unlock_bh(&src->lock);
}
static void
ip_vs_zero_stats(struct ip_vs_stats *stats)
{
spin_lock_bh(&stats->lock);
#define IP_VS_ZERO_STATS_COUNTER(c) stats->ustats0.c = stats->ustats.c
IP_VS_ZERO_STATS_COUNTER(conns);
IP_VS_ZERO_STATS_COUNTER(inpkts);
IP_VS_ZERO_STATS_COUNTER(outpkts);
IP_VS_ZERO_STATS_COUNTER(inbytes);
IP_VS_ZERO_STATS_COUNTER(outbytes);
ip_vs_zero_estimator(stats);
spin_unlock_bh(&stats->lock);
}
static void
__ip_vs_update_dest(struct ip_vs_service *svc, struct ip_vs_dest *dest,
struct ip_vs_dest_user_kern *udest, int add)
{
struct netns_ipvs *ipvs = net_ipvs(svc->net);
int conn_flags;
atomic_set(&dest->weight, udest->weight);
conn_flags = udest->conn_flags & IP_VS_CONN_F_DEST_MASK;
conn_flags |= IP_VS_CONN_F_INACTIVE;
if ((conn_flags & IP_VS_CONN_F_FWD_MASK) != IP_VS_CONN_F_MASQ) {
conn_flags |= IP_VS_CONN_F_NOOUTPUT;
} else {
write_lock_bh(&ipvs->rs_lock);
ip_vs_rs_hash(ipvs, dest);
write_unlock_bh(&ipvs->rs_lock);
}
atomic_set(&dest->conn_flags, conn_flags);
if (!dest->svc) {
__ip_vs_bind_svc(dest, svc);
} else {
if (dest->svc != svc) {
__ip_vs_unbind_svc(dest);
ip_vs_zero_stats(&dest->stats);
__ip_vs_bind_svc(dest, svc);
}
}
dest->flags |= IP_VS_DEST_F_AVAILABLE;
if (udest->u_threshold == 0 || udest->u_threshold > dest->u_threshold)
dest->flags &= ~IP_VS_DEST_F_OVERLOAD;
dest->u_threshold = udest->u_threshold;
dest->l_threshold = udest->l_threshold;
spin_lock_bh(&dest->dst_lock);
ip_vs_dst_reset(dest);
spin_unlock_bh(&dest->dst_lock);
if (add)
ip_vs_start_estimator(svc->net, &dest->stats);
write_lock_bh(&__ip_vs_svc_lock);
IP_VS_WAIT_WHILE(atomic_read(&svc->usecnt) > 0);
if (add) {
list_add(&dest->n_list, &svc->destinations);
svc->num_dests++;
}
if (svc->scheduler->update_service)
svc->scheduler->update_service(svc);
write_unlock_bh(&__ip_vs_svc_lock);
}
static int
ip_vs_new_dest(struct ip_vs_service *svc, struct ip_vs_dest_user_kern *udest,
struct ip_vs_dest **dest_p)
{
struct ip_vs_dest *dest;
unsigned atype;
EnterFunction(2);
#ifdef CONFIG_IP_VS_IPV6
if (svc->af == AF_INET6) {
atype = ipv6_addr_type(&udest->addr.in6);
if ((!(atype & IPV6_ADDR_UNICAST) ||
atype & IPV6_ADDR_LINKLOCAL) &&
!__ip_vs_addr_is_local_v6(svc->net, &udest->addr.in6))
return -EINVAL;
} else
#endif
{
atype = inet_addr_type(svc->net, udest->addr.ip);
if (atype != RTN_LOCAL && atype != RTN_UNICAST)
return -EINVAL;
}
dest = kzalloc(sizeof(struct ip_vs_dest), GFP_KERNEL);
if (dest == NULL)
return -ENOMEM;
dest->stats.cpustats = alloc_percpu(struct ip_vs_cpu_stats);
if (!dest->stats.cpustats)
goto err_alloc;
dest->af = svc->af;
dest->protocol = svc->protocol;
dest->vaddr = svc->addr;
dest->vport = svc->port;
dest->vfwmark = svc->fwmark;
ip_vs_addr_copy(svc->af, &dest->addr, &udest->addr);
dest->port = udest->port;
atomic_set(&dest->activeconns, 0);
atomic_set(&dest->inactconns, 0);
atomic_set(&dest->persistconns, 0);
atomic_set(&dest->refcnt, 1);
INIT_LIST_HEAD(&dest->d_list);
spin_lock_init(&dest->dst_lock);
spin_lock_init(&dest->stats.lock);
__ip_vs_update_dest(svc, dest, udest, 1);
*dest_p = dest;
LeaveFunction(2);
return 0;
err_alloc:
kfree(dest);
return -ENOMEM;
}
static int
ip_vs_add_dest(struct ip_vs_service *svc, struct ip_vs_dest_user_kern *udest)
{
struct ip_vs_dest *dest;
union nf_inet_addr daddr;
__be16 dport = udest->port;
int ret;
EnterFunction(2);
if (udest->weight < 0) {
pr_err("%s(): server weight less than zero\n", __func__);
return -ERANGE;
}
if (udest->l_threshold > udest->u_threshold) {
pr_err("%s(): lower threshold is higher than upper threshold\n",
__func__);
return -ERANGE;
}
ip_vs_addr_copy(svc->af, &daddr, &udest->addr);
dest = ip_vs_lookup_dest(svc, &daddr, dport);
if (dest != NULL) {
IP_VS_DBG(1, "%s(): dest already exists\n", __func__);
return -EEXIST;
}
dest = ip_vs_trash_get_dest(svc, &daddr, dport);
if (dest != NULL) {
IP_VS_DBG_BUF(3, "Get destination %s:%u from trash, "
"dest->refcnt=%d, service %u/%s:%u\n",
IP_VS_DBG_ADDR(svc->af, &daddr), ntohs(dport),
atomic_read(&dest->refcnt),
dest->vfwmark,
IP_VS_DBG_ADDR(svc->af, &dest->vaddr),
ntohs(dest->vport));
list_del(&dest->n_list);
__ip_vs_update_dest(svc, dest, udest, 1);
ret = 0;
} else {
ret = ip_vs_new_dest(svc, udest, &dest);
}
LeaveFunction(2);
return ret;
}
static int
ip_vs_edit_dest(struct ip_vs_service *svc, struct ip_vs_dest_user_kern *udest)
{
struct ip_vs_dest *dest;
union nf_inet_addr daddr;
__be16 dport = udest->port;
EnterFunction(2);
if (udest->weight < 0) {
pr_err("%s(): server weight less than zero\n", __func__);
return -ERANGE;
}
if (udest->l_threshold > udest->u_threshold) {
pr_err("%s(): lower threshold is higher than upper threshold\n",
__func__);
return -ERANGE;
}
ip_vs_addr_copy(svc->af, &daddr, &udest->addr);
dest = ip_vs_lookup_dest(svc, &daddr, dport);
if (dest == NULL) {
IP_VS_DBG(1, "%s(): dest doesn't exist\n", __func__);
return -ENOENT;
}
__ip_vs_update_dest(svc, dest, udest, 0);
LeaveFunction(2);
return 0;
}
static void __ip_vs_del_dest(struct net *net, struct ip_vs_dest *dest)
{
struct netns_ipvs *ipvs = net_ipvs(net);
ip_vs_stop_estimator(net, &dest->stats);
write_lock_bh(&ipvs->rs_lock);
ip_vs_rs_unhash(dest);
write_unlock_bh(&ipvs->rs_lock);
if (atomic_dec_and_test(&dest->refcnt)) {
IP_VS_DBG_BUF(3, "Removing destination %u/%s:%u\n",
dest->vfwmark,
IP_VS_DBG_ADDR(dest->af, &dest->addr),
ntohs(dest->port));
ip_vs_dst_reset(dest);
atomic_dec(&dest->svc->refcnt);
free_percpu(dest->stats.cpustats);
kfree(dest);
} else {
IP_VS_DBG_BUF(3, "Moving dest %s:%u into trash, "
"dest->refcnt=%d\n",
IP_VS_DBG_ADDR(dest->af, &dest->addr),
ntohs(dest->port),
atomic_read(&dest->refcnt));
list_add(&dest->n_list, &ipvs->dest_trash);
atomic_inc(&dest->refcnt);
}
}
static void __ip_vs_unlink_dest(struct ip_vs_service *svc,
struct ip_vs_dest *dest,
int svcupd)
{
dest->flags &= ~IP_VS_DEST_F_AVAILABLE;
list_del(&dest->n_list);
svc->num_dests--;
if (svcupd && svc->scheduler->update_service)
svc->scheduler->update_service(svc);
}
static int
ip_vs_del_dest(struct ip_vs_service *svc, struct ip_vs_dest_user_kern *udest)
{
struct ip_vs_dest *dest;
__be16 dport = udest->port;
EnterFunction(2);
dest = ip_vs_lookup_dest(svc, &udest->addr, dport);
if (dest == NULL) {
IP_VS_DBG(1, "%s(): destination not found!\n", __func__);
return -ENOENT;
}
write_lock_bh(&__ip_vs_svc_lock);
IP_VS_WAIT_WHILE(atomic_read(&svc->usecnt) > 0);
__ip_vs_unlink_dest(svc, dest, 1);
write_unlock_bh(&__ip_vs_svc_lock);
__ip_vs_del_dest(svc->net, dest);
LeaveFunction(2);
return 0;
}
static int
ip_vs_add_service(struct net *net, struct ip_vs_service_user_kern *u,
struct ip_vs_service **svc_p)
{
int ret = 0;
struct ip_vs_scheduler *sched = NULL;
struct ip_vs_pe *pe = NULL;
struct ip_vs_service *svc = NULL;
struct netns_ipvs *ipvs = net_ipvs(net);
ip_vs_use_count_inc();
sched = ip_vs_scheduler_get(u->sched_name);
if (sched == NULL) {
pr_info("Scheduler module ip_vs_%s not found\n", u->sched_name);
ret = -ENOENT;
goto out_err;
}
if (u->pe_name && *u->pe_name) {
pe = ip_vs_pe_getbyname(u->pe_name);
if (pe == NULL) {
pr_info("persistence engine module ip_vs_pe_%s "
"not found\n", u->pe_name);
ret = -ENOENT;
goto out_err;
}
}
#ifdef CONFIG_IP_VS_IPV6
if (u->af == AF_INET6 && (u->netmask < 1 || u->netmask > 128)) {
ret = -EINVAL;
goto out_err;
}
#endif
svc = kzalloc(sizeof(struct ip_vs_service), GFP_KERNEL);
if (svc == NULL) {
IP_VS_DBG(1, "%s(): no memory\n", __func__);
ret = -ENOMEM;
goto out_err;
}
svc->stats.cpustats = alloc_percpu(struct ip_vs_cpu_stats);
if (!svc->stats.cpustats)
goto out_err;
atomic_set(&svc->usecnt, 0);
atomic_set(&svc->refcnt, 0);
svc->af = u->af;
svc->protocol = u->protocol;
ip_vs_addr_copy(svc->af, &svc->addr, &u->addr);
svc->port = u->port;
svc->fwmark = u->fwmark;
svc->flags = u->flags;
svc->timeout = u->timeout * HZ;
svc->netmask = u->netmask;
svc->net = net;
INIT_LIST_HEAD(&svc->destinations);
rwlock_init(&svc->sched_lock);
spin_lock_init(&svc->stats.lock);
ret = ip_vs_bind_scheduler(svc, sched);
if (ret)
goto out_err;
sched = NULL;
ip_vs_bind_pe(svc, pe);
pe = NULL;
if (svc->port == FTPPORT)
atomic_inc(&ipvs->ftpsvc_counter);
else if (svc->port == 0)
atomic_inc(&ipvs->nullsvc_counter);
ip_vs_start_estimator(net, &svc->stats);
if (svc->af == AF_INET)
ipvs->num_services++;
write_lock_bh(&__ip_vs_svc_lock);
ip_vs_svc_hash(svc);
write_unlock_bh(&__ip_vs_svc_lock);
*svc_p = svc;
ipvs->enable = 1;
return 0;
out_err:
if (svc != NULL) {
ip_vs_unbind_scheduler(svc);
if (svc->inc) {
local_bh_disable();
ip_vs_app_inc_put(svc->inc);
local_bh_enable();
}
if (svc->stats.cpustats)
free_percpu(svc->stats.cpustats);
kfree(svc);
}
ip_vs_scheduler_put(sched);
ip_vs_pe_put(pe);
ip_vs_use_count_dec();
return ret;
}
static int
ip_vs_edit_service(struct ip_vs_service *svc, struct ip_vs_service_user_kern *u)
{
struct ip_vs_scheduler *sched, *old_sched;
struct ip_vs_pe *pe = NULL, *old_pe = NULL;
int ret = 0;
sched = ip_vs_scheduler_get(u->sched_name);
if (sched == NULL) {
pr_info("Scheduler module ip_vs_%s not found\n", u->sched_name);
return -ENOENT;
}
old_sched = sched;
if (u->pe_name && *u->pe_name) {
pe = ip_vs_pe_getbyname(u->pe_name);
if (pe == NULL) {
pr_info("persistence engine module ip_vs_pe_%s "
"not found\n", u->pe_name);
ret = -ENOENT;
goto out;
}
old_pe = pe;
}
#ifdef CONFIG_IP_VS_IPV6
if (u->af == AF_INET6 && (u->netmask < 1 || u->netmask > 128)) {
ret = -EINVAL;
goto out;
}
#endif
write_lock_bh(&__ip_vs_svc_lock);
IP_VS_WAIT_WHILE(atomic_read(&svc->usecnt) > 0);
svc->flags = u->flags | IP_VS_SVC_F_HASHED;
svc->timeout = u->timeout * HZ;
svc->netmask = u->netmask;
old_sched = svc->scheduler;
if (sched != old_sched) {
if ((ret = ip_vs_unbind_scheduler(svc))) {
old_sched = sched;
goto out_unlock;
}
if ((ret = ip_vs_bind_scheduler(svc, sched))) {
ip_vs_bind_scheduler(svc, old_sched);
old_sched = sched;
goto out_unlock;
}
}
old_pe = svc->pe;
if (pe != old_pe) {
ip_vs_unbind_pe(svc);
ip_vs_bind_pe(svc, pe);
}
out_unlock:
write_unlock_bh(&__ip_vs_svc_lock);
out:
ip_vs_scheduler_put(old_sched);
ip_vs_pe_put(old_pe);
return ret;
}
static void __ip_vs_del_service(struct ip_vs_service *svc)
{
struct ip_vs_dest *dest, *nxt;
struct ip_vs_scheduler *old_sched;
struct ip_vs_pe *old_pe;
struct netns_ipvs *ipvs = net_ipvs(svc->net);
pr_info("%s: enter\n", __func__);
if (svc->af == AF_INET)
ipvs->num_services--;
ip_vs_stop_estimator(svc->net, &svc->stats);
old_sched = svc->scheduler;
ip_vs_unbind_scheduler(svc);
ip_vs_scheduler_put(old_sched);
old_pe = svc->pe;
ip_vs_unbind_pe(svc);
ip_vs_pe_put(old_pe);
if (svc->inc) {
ip_vs_app_inc_put(svc->inc);
svc->inc = NULL;
}
list_for_each_entry_safe(dest, nxt, &svc->destinations, n_list) {
__ip_vs_unlink_dest(svc, dest, 0);
__ip_vs_del_dest(svc->net, dest);
}
if (svc->port == FTPPORT)
atomic_dec(&ipvs->ftpsvc_counter);
else if (svc->port == 0)
atomic_dec(&ipvs->nullsvc_counter);
if (atomic_read(&svc->refcnt) == 0) {
IP_VS_DBG_BUF(3, "Removing service %u/%s:%u usecnt=%d\n",
svc->fwmark,
IP_VS_DBG_ADDR(svc->af, &svc->addr),
ntohs(svc->port), atomic_read(&svc->usecnt));
free_percpu(svc->stats.cpustats);
kfree(svc);
}
ip_vs_use_count_dec();
}
static void ip_vs_unlink_service(struct ip_vs_service *svc)
{
write_lock_bh(&__ip_vs_svc_lock);
ip_vs_svc_unhash(svc);
IP_VS_WAIT_WHILE(atomic_read(&svc->usecnt) > 0);
__ip_vs_del_service(svc);
write_unlock_bh(&__ip_vs_svc_lock);
}
static int ip_vs_del_service(struct ip_vs_service *svc)
{
if (svc == NULL)
return -EEXIST;
ip_vs_unlink_service(svc);
return 0;
}
static int ip_vs_flush(struct net *net)
{
int idx;
struct ip_vs_service *svc, *nxt;
for(idx = 0; idx < IP_VS_SVC_TAB_SIZE; idx++) {
list_for_each_entry_safe(svc, nxt, &ip_vs_svc_table[idx],
s_list) {
if (net_eq(svc->net, net))
ip_vs_unlink_service(svc);
}
}
for(idx = 0; idx < IP_VS_SVC_TAB_SIZE; idx++) {
list_for_each_entry_safe(svc, nxt,
&ip_vs_svc_fwm_table[idx], f_list) {
if (net_eq(svc->net, net))
ip_vs_unlink_service(svc);
}
}
return 0;
}
void ip_vs_service_net_cleanup(struct net *net)
{
EnterFunction(2);
mutex_lock(&__ip_vs_mutex);
ip_vs_flush(net);
mutex_unlock(&__ip_vs_mutex);
LeaveFunction(2);
}
static inline void
__ip_vs_dev_reset(struct ip_vs_dest *dest, struct net_device *dev)
{
spin_lock_bh(&dest->dst_lock);
if (dest->dst_cache && dest->dst_cache->dev == dev) {
IP_VS_DBG_BUF(3, "Reset dev:%s dest %s:%u ,dest->refcnt=%d\n",
dev->name,
IP_VS_DBG_ADDR(dest->af, &dest->addr),
ntohs(dest->port),
atomic_read(&dest->refcnt));
ip_vs_dst_reset(dest);
}
spin_unlock_bh(&dest->dst_lock);
}
static int ip_vs_dst_event(struct notifier_block *this, unsigned long event,
void *ptr)
{
struct net_device *dev = ptr;
struct net *net = dev_net(dev);
struct ip_vs_service *svc;
struct ip_vs_dest *dest;
unsigned int idx;
if (event != NETDEV_UNREGISTER)
return NOTIFY_DONE;
IP_VS_DBG(3, "%s() dev=%s\n", __func__, dev->name);
EnterFunction(2);
mutex_lock(&__ip_vs_mutex);
for (idx = 0; idx < IP_VS_SVC_TAB_SIZE; idx++) {
list_for_each_entry(svc, &ip_vs_svc_table[idx], s_list) {
if (net_eq(svc->net, net)) {
list_for_each_entry(dest, &svc->destinations,
n_list) {
__ip_vs_dev_reset(dest, dev);
}
}
}
list_for_each_entry(svc, &ip_vs_svc_fwm_table[idx], f_list) {
if (net_eq(svc->net, net)) {
list_for_each_entry(dest, &svc->destinations,
n_list) {
__ip_vs_dev_reset(dest, dev);
}
}
}
}
list_for_each_entry(dest, &net_ipvs(net)->dest_trash, n_list) {
__ip_vs_dev_reset(dest, dev);
}
mutex_unlock(&__ip_vs_mutex);
LeaveFunction(2);
return NOTIFY_DONE;
}
static int ip_vs_zero_service(struct ip_vs_service *svc)
{
struct ip_vs_dest *dest;
write_lock_bh(&__ip_vs_svc_lock);
list_for_each_entry(dest, &svc->destinations, n_list) {
ip_vs_zero_stats(&dest->stats);
}
ip_vs_zero_stats(&svc->stats);
write_unlock_bh(&__ip_vs_svc_lock);
return 0;
}
static int ip_vs_zero_all(struct net *net)
{
int idx;
struct ip_vs_service *svc;
for(idx = 0; idx < IP_VS_SVC_TAB_SIZE; idx++) {
list_for_each_entry(svc, &ip_vs_svc_table[idx], s_list) {
if (net_eq(svc->net, net))
ip_vs_zero_service(svc);
}
}
for(idx = 0; idx < IP_VS_SVC_TAB_SIZE; idx++) {
list_for_each_entry(svc, &ip_vs_svc_fwm_table[idx], f_list) {
if (net_eq(svc->net, net))
ip_vs_zero_service(svc);
}
}
ip_vs_zero_stats(&net_ipvs(net)->tot_stats);
return 0;
}
static int
proc_do_defense_mode(ctl_table *table, int write,
void __user *buffer, size_t *lenp, loff_t *ppos)
{
struct net *net = current->nsproxy->net_ns;
int *valp = table->data;
int val = *valp;
int rc;
rc = proc_dointvec(table, write, buffer, lenp, ppos);
if (write && (*valp != val)) {
if ((*valp < 0) || (*valp > 3)) {
*valp = val;
} else {
update_defense_level(net_ipvs(net));
}
}
return rc;
}
static int
proc_do_sync_threshold(ctl_table *table, int write,
void __user *buffer, size_t *lenp, loff_t *ppos)
{
int *valp = table->data;
int val[2];
int rc;
memcpy(val, valp, sizeof(val));
rc = proc_dointvec(table, write, buffer, lenp, ppos);
if (write && (valp[0] < 0 || valp[1] < 0 || valp[0] >= valp[1])) {
memcpy(valp, val, sizeof(val));
}
return rc;
}
static int
proc_do_sync_mode(ctl_table *table, int write,
void __user *buffer, size_t *lenp, loff_t *ppos)
{
int *valp = table->data;
int val = *valp;
int rc;
rc = proc_dointvec(table, write, buffer, lenp, ppos);
if (write && (*valp != val)) {
if ((*valp < 0) || (*valp > 1)) {
*valp = val;
} else {
struct net *net = current->nsproxy->net_ns;
ip_vs_sync_switch_mode(net, val);
}
}
return rc;
}
static inline const char *ip_vs_fwd_name(unsigned flags)
{
switch (flags & IP_VS_CONN_F_FWD_MASK) {
case IP_VS_CONN_F_LOCALNODE:
return "Local";
case IP_VS_CONN_F_TUNNEL:
return "Tunnel";
case IP_VS_CONN_F_DROUTE:
return "Route";
default:
return "Masq";
}
}
static struct ip_vs_service *ip_vs_info_array(struct seq_file *seq, loff_t pos)
{
struct net *net = seq_file_net(seq);
struct ip_vs_iter *iter = seq->private;
int idx;
struct ip_vs_service *svc;
for (idx = 0; idx < IP_VS_SVC_TAB_SIZE; idx++) {
list_for_each_entry(svc, &ip_vs_svc_table[idx], s_list) {
if (net_eq(svc->net, net) && pos-- == 0) {
iter->table = ip_vs_svc_table;
iter->bucket = idx;
return svc;
}
}
}
for (idx = 0; idx < IP_VS_SVC_TAB_SIZE; idx++) {
list_for_each_entry(svc, &ip_vs_svc_fwm_table[idx], f_list) {
if (net_eq(svc->net, net) && pos-- == 0) {
iter->table = ip_vs_svc_fwm_table;
iter->bucket = idx;
return svc;
}
}
}
return NULL;
}
static void *ip_vs_info_seq_start(struct seq_file *seq, loff_t *pos)
__acquires(__ip_vs_svc_lock)
{
read_lock_bh(&__ip_vs_svc_lock);
return *pos ? ip_vs_info_array(seq, *pos - 1) : SEQ_START_TOKEN;
}
static void *ip_vs_info_seq_next(struct seq_file *seq, void *v, loff_t *pos)
{
struct list_head *e;
struct ip_vs_iter *iter;
struct ip_vs_service *svc;
++*pos;
if (v == SEQ_START_TOKEN)
return ip_vs_info_array(seq,0);
svc = v;
iter = seq->private;
if (iter->table == ip_vs_svc_table) {
if ((e = svc->s_list.next) != &ip_vs_svc_table[iter->bucket])
return list_entry(e, struct ip_vs_service, s_list);
while (++iter->bucket < IP_VS_SVC_TAB_SIZE) {
list_for_each_entry(svc,&ip_vs_svc_table[iter->bucket],
s_list) {
return svc;
}
}
iter->table = ip_vs_svc_fwm_table;
iter->bucket = -1;
goto scan_fwmark;
}
if ((e = svc->f_list.next) != &ip_vs_svc_fwm_table[iter->bucket])
return list_entry(e, struct ip_vs_service, f_list);
scan_fwmark:
while (++iter->bucket < IP_VS_SVC_TAB_SIZE) {
list_for_each_entry(svc, &ip_vs_svc_fwm_table[iter->bucket],
f_list)
return svc;
}
return NULL;
}
static void ip_vs_info_seq_stop(struct seq_file *seq, void *v)
__releases(__ip_vs_svc_lock)
{
read_unlock_bh(&__ip_vs_svc_lock);
}
static int ip_vs_info_seq_show(struct seq_file *seq, void *v)
{
if (v == SEQ_START_TOKEN) {
seq_printf(seq,
"IP Virtual Server version %d.%d.%d (size=%d)\n",
NVERSION(IP_VS_VERSION_CODE), ip_vs_conn_tab_size);
seq_puts(seq,
"Prot LocalAddress:Port Scheduler Flags\n");
seq_puts(seq,
" -> RemoteAddress:Port Forward Weight ActiveConn InActConn\n");
} else {
const struct ip_vs_service *svc = v;
const struct ip_vs_iter *iter = seq->private;
const struct ip_vs_dest *dest;
if (iter->table == ip_vs_svc_table) {
#ifdef CONFIG_IP_VS_IPV6
if (svc->af == AF_INET6)
seq_printf(seq, "%s [%pI6]:%04X %s ",
ip_vs_proto_name(svc->protocol),
&svc->addr.in6,
ntohs(svc->port),
svc->scheduler->name);
else
#endif
seq_printf(seq, "%s %08X:%04X %s %s ",
ip_vs_proto_name(svc->protocol),
ntohl(svc->addr.ip),
ntohs(svc->port),
svc->scheduler->name,
(svc->flags & IP_VS_SVC_F_ONEPACKET)?"ops ":"");
} else {
seq_printf(seq, "FWM %08X %s %s",
svc->fwmark, svc->scheduler->name,
(svc->flags & IP_VS_SVC_F_ONEPACKET)?"ops ":"");
}
if (svc->flags & IP_VS_SVC_F_PERSISTENT)
seq_printf(seq, "persistent %d %08X\n",
svc->timeout,
ntohl(svc->netmask));
else
seq_putc(seq, '\n');
list_for_each_entry(dest, &svc->destinations, n_list) {
#ifdef CONFIG_IP_VS_IPV6
if (dest->af == AF_INET6)
seq_printf(seq,
" -> [%pI6]:%04X"
" %-7s %-6d %-10d %-10d\n",
&dest->addr.in6,
ntohs(dest->port),
ip_vs_fwd_name(atomic_read(&dest->conn_flags)),
atomic_read(&dest->weight),
atomic_read(&dest->activeconns),
atomic_read(&dest->inactconns));
else
#endif
seq_printf(seq,
" -> %08X:%04X "
"%-7s %-6d %-10d %-10d\n",
ntohl(dest->addr.ip),
ntohs(dest->port),
ip_vs_fwd_name(atomic_read(&dest->conn_flags)),
atomic_read(&dest->weight),
atomic_read(&dest->activeconns),
atomic_read(&dest->inactconns));
}
}
return 0;
}
static int ip_vs_info_open(struct inode *inode, struct file *file)
{
return seq_open_net(inode, file, &ip_vs_info_seq_ops,
sizeof(struct ip_vs_iter));
}
static int ip_vs_stats_show(struct seq_file *seq, void *v)
{
struct net *net = seq_file_single_net(seq);
struct ip_vs_stats_user show;
seq_puts(seq,
" Total Incoming Outgoing Incoming Outgoing\n");
seq_printf(seq,
" Conns Packets Packets Bytes Bytes\n");
ip_vs_copy_stats(&show, &net_ipvs(net)->tot_stats);
seq_printf(seq, "%8X %8X %8X %16LX %16LX\n\n", show.conns,
show.inpkts, show.outpkts,
(unsigned long long) show.inbytes,
(unsigned long long) show.outbytes);
seq_puts(seq,
" Conns/s Pkts/s Pkts/s Bytes/s Bytes/s\n");
seq_printf(seq, "%8X %8X %8X %16X %16X\n",
show.cps, show.inpps, show.outpps,
show.inbps, show.outbps);
return 0;
}
static int ip_vs_stats_seq_open(struct inode *inode, struct file *file)
{
return single_open_net(inode, file, ip_vs_stats_show);
}
static int ip_vs_stats_percpu_show(struct seq_file *seq, void *v)
{
struct net *net = seq_file_single_net(seq);
struct ip_vs_stats *tot_stats = &net_ipvs(net)->tot_stats;
struct ip_vs_cpu_stats *cpustats = tot_stats->cpustats;
struct ip_vs_stats_user rates;
int i;
seq_puts(seq,
" Total Incoming Outgoing Incoming Outgoing\n");
seq_printf(seq,
"CPU Conns Packets Packets Bytes Bytes\n");
for_each_possible_cpu(i) {
struct ip_vs_cpu_stats *u = per_cpu_ptr(cpustats, i);
unsigned int start;
__u64 inbytes, outbytes;
do {
start = u64_stats_fetch_begin_bh(&u->syncp);
inbytes = u->ustats.inbytes;
outbytes = u->ustats.outbytes;
} while (u64_stats_fetch_retry_bh(&u->syncp, start));
seq_printf(seq, "%3X %8X %8X %8X %16LX %16LX\n",
i, u->ustats.conns, u->ustats.inpkts,
u->ustats.outpkts, (__u64)inbytes,
(__u64)outbytes);
}
spin_lock_bh(&tot_stats->lock);
seq_printf(seq, " ~ %8X %8X %8X %16LX %16LX\n\n",
tot_stats->ustats.conns, tot_stats->ustats.inpkts,
tot_stats->ustats.outpkts,
(unsigned long long) tot_stats->ustats.inbytes,
(unsigned long long) tot_stats->ustats.outbytes);
ip_vs_read_estimator(&rates, tot_stats);
spin_unlock_bh(&tot_stats->lock);
seq_puts(seq,
" Conns/s Pkts/s Pkts/s Bytes/s Bytes/s\n");
seq_printf(seq, " %8X %8X %8X %16X %16X\n",
rates.cps,
rates.inpps,
rates.outpps,
rates.inbps,
rates.outbps);
return 0;
}
static int ip_vs_stats_percpu_seq_open(struct inode *inode, struct file *file)
{
return single_open_net(inode, file, ip_vs_stats_percpu_show);
}
static int ip_vs_set_timeout(struct net *net, struct ip_vs_timeout_user *u)
{
#if defined(CONFIG_IP_VS_PROTO_TCP) || defined(CONFIG_IP_VS_PROTO_UDP)
struct ip_vs_proto_data *pd;
#endif
IP_VS_DBG(2, "Setting timeout tcp:%d tcpfin:%d udp:%d\n",
u->tcp_timeout,
u->tcp_fin_timeout,
u->udp_timeout);
#ifdef CONFIG_IP_VS_PROTO_TCP
if (u->tcp_timeout) {
pd = ip_vs_proto_data_get(net, IPPROTO_TCP);
pd->timeout_table[IP_VS_TCP_S_ESTABLISHED]
= u->tcp_timeout * HZ;
}
if (u->tcp_fin_timeout) {
pd = ip_vs_proto_data_get(net, IPPROTO_TCP);
pd->timeout_table[IP_VS_TCP_S_FIN_WAIT]
= u->tcp_fin_timeout * HZ;
}
#endif
#ifdef CONFIG_IP_VS_PROTO_UDP
if (u->udp_timeout) {
pd = ip_vs_proto_data_get(net, IPPROTO_UDP);
pd->timeout_table[IP_VS_UDP_S_NORMAL]
= u->udp_timeout * HZ;
}
#endif
return 0;
}
static void ip_vs_copy_usvc_compat(struct ip_vs_service_user_kern *usvc,
struct ip_vs_service_user *usvc_compat)
{
memset(usvc, 0, sizeof(*usvc));
usvc->af = AF_INET;
usvc->protocol = usvc_compat->protocol;
usvc->addr.ip = usvc_compat->addr;
usvc->port = usvc_compat->port;
usvc->fwmark = usvc_compat->fwmark;
usvc->sched_name = usvc_compat->sched_name;
usvc->flags = usvc_compat->flags;
usvc->timeout = usvc_compat->timeout;
usvc->netmask = usvc_compat->netmask;
}
static void ip_vs_copy_udest_compat(struct ip_vs_dest_user_kern *udest,
struct ip_vs_dest_user *udest_compat)
{
memset(udest, 0, sizeof(*udest));
udest->addr.ip = udest_compat->addr;
udest->port = udest_compat->port;
udest->conn_flags = udest_compat->conn_flags;
udest->weight = udest_compat->weight;
udest->u_threshold = udest_compat->u_threshold;
udest->l_threshold = udest_compat->l_threshold;
}
static int
do_ip_vs_set_ctl(struct sock *sk, int cmd, void __user *user, unsigned int len)
{
struct net *net = sock_net(sk);
int ret;
unsigned char arg[MAX_ARG_LEN];
struct ip_vs_service_user *usvc_compat;
struct ip_vs_service_user_kern usvc;
struct ip_vs_service *svc;
struct ip_vs_dest_user *udest_compat;
struct ip_vs_dest_user_kern udest;
struct netns_ipvs *ipvs = net_ipvs(net);
if (!capable(CAP_NET_ADMIN))
return -EPERM;
if (cmd < IP_VS_BASE_CTL || cmd > IP_VS_SO_SET_MAX)
return -EINVAL;
if (len < 0 || len > MAX_ARG_LEN)
return -EINVAL;
if (len != set_arglen[SET_CMDID(cmd)]) {
pr_err("set_ctl: len %u != %u\n",
len, set_arglen[SET_CMDID(cmd)]);
return -EINVAL;
}
if (copy_from_user(arg, user, len) != 0)
return -EFAULT;
ip_vs_use_count_inc();
if (cmd == IP_VS_SO_SET_STARTDAEMON ||
cmd == IP_VS_SO_SET_STOPDAEMON) {
struct ip_vs_daemon_user *dm = (struct ip_vs_daemon_user *)arg;
if (mutex_lock_interruptible(&ipvs->sync_mutex)) {
ret = -ERESTARTSYS;
goto out_dec;
}
if (cmd == IP_VS_SO_SET_STARTDAEMON)
ret = start_sync_thread(net, dm->state, dm->mcast_ifn,
dm->syncid);
else
ret = stop_sync_thread(net, dm->state);
mutex_unlock(&ipvs->sync_mutex);
goto out_dec;
}
if (mutex_lock_interruptible(&__ip_vs_mutex)) {
ret = -ERESTARTSYS;
goto out_dec;
}
if (cmd == IP_VS_SO_SET_FLUSH) {
ret = ip_vs_flush(net);
goto out_unlock;
} else if (cmd == IP_VS_SO_SET_TIMEOUT) {
ret = ip_vs_set_timeout(net, (struct ip_vs_timeout_user *)arg);
goto out_unlock;
}
usvc_compat = (struct ip_vs_service_user *)arg;
udest_compat = (struct ip_vs_dest_user *)(usvc_compat + 1);
ip_vs_copy_usvc_compat(&usvc, usvc_compat);
ip_vs_copy_udest_compat(&udest, udest_compat);
if (cmd == IP_VS_SO_SET_ZERO) {
if (!usvc.fwmark && !usvc.addr.ip && !usvc.port) {
ret = ip_vs_zero_all(net);
goto out_unlock;
}
}
if (usvc.protocol != IPPROTO_TCP && usvc.protocol != IPPROTO_UDP &&
usvc.protocol != IPPROTO_SCTP) {
pr_err("set_ctl: invalid protocol: %d %pI4:%d %s\n",
usvc.protocol, &usvc.addr.ip,
ntohs(usvc.port), usvc.sched_name);
ret = -EFAULT;
goto out_unlock;
}
if (usvc.fwmark == 0)
svc = __ip_vs_service_find(net, usvc.af, usvc.protocol,
&usvc.addr, usvc.port);
else
svc = __ip_vs_svc_fwm_find(net, usvc.af, usvc.fwmark);
if (cmd != IP_VS_SO_SET_ADD
&& (svc == NULL || svc->protocol != usvc.protocol)) {
ret = -ESRCH;
goto out_unlock;
}
switch (cmd) {
case IP_VS_SO_SET_ADD:
if (svc != NULL)
ret = -EEXIST;
else
ret = ip_vs_add_service(net, &usvc, &svc);
break;
case IP_VS_SO_SET_EDIT:
ret = ip_vs_edit_service(svc, &usvc);
break;
case IP_VS_SO_SET_DEL:
ret = ip_vs_del_service(svc);
if (!ret)
goto out_unlock;
break;
case IP_VS_SO_SET_ZERO:
ret = ip_vs_zero_service(svc);
break;
case IP_VS_SO_SET_ADDDEST:
ret = ip_vs_add_dest(svc, &udest);
break;
case IP_VS_SO_SET_EDITDEST:
ret = ip_vs_edit_dest(svc, &udest);
break;
case IP_VS_SO_SET_DELDEST:
ret = ip_vs_del_dest(svc, &udest);
break;
default:
ret = -EINVAL;
}
out_unlock:
mutex_unlock(&__ip_vs_mutex);
out_dec:
ip_vs_use_count_dec();
return ret;
}
static void
ip_vs_copy_service(struct ip_vs_service_entry *dst, struct ip_vs_service *src)
{
dst->protocol = src->protocol;
dst->addr = src->addr.ip;
dst->port = src->port;
dst->fwmark = src->fwmark;
strlcpy(dst->sched_name, src->scheduler->name, sizeof(dst->sched_name));
dst->flags = src->flags;
dst->timeout = src->timeout / HZ;
dst->netmask = src->netmask;
dst->num_dests = src->num_dests;
ip_vs_copy_stats(&dst->stats, &src->stats);
}
static inline int
__ip_vs_get_service_entries(struct net *net,
const struct ip_vs_get_services *get,
struct ip_vs_get_services __user *uptr)
{
int idx, count=0;
struct ip_vs_service *svc;
struct ip_vs_service_entry entry;
int ret = 0;
for (idx = 0; idx < IP_VS_SVC_TAB_SIZE; idx++) {
list_for_each_entry(svc, &ip_vs_svc_table[idx], s_list) {
if (svc->af != AF_INET || !net_eq(svc->net, net))
continue;
if (count >= get->num_services)
goto out;
memset(&entry, 0, sizeof(entry));
ip_vs_copy_service(&entry, svc);
if (copy_to_user(&uptr->entrytable[count],
&entry, sizeof(entry))) {
ret = -EFAULT;
goto out;
}
count++;
}
}
for (idx = 0; idx < IP_VS_SVC_TAB_SIZE; idx++) {
list_for_each_entry(svc, &ip_vs_svc_fwm_table[idx], f_list) {
if (svc->af != AF_INET || !net_eq(svc->net, net))
continue;
if (count >= get->num_services)
goto out;
memset(&entry, 0, sizeof(entry));
ip_vs_copy_service(&entry, svc);
if (copy_to_user(&uptr->entrytable[count],
&entry, sizeof(entry))) {
ret = -EFAULT;
goto out;
}
count++;
}
}
out:
return ret;
}
static inline int
__ip_vs_get_dest_entries(struct net *net, const struct ip_vs_get_dests *get,
struct ip_vs_get_dests __user *uptr)
{
struct ip_vs_service *svc;
union nf_inet_addr addr = { .ip = get->addr };
int ret = 0;
if (get->fwmark)
svc = __ip_vs_svc_fwm_find(net, AF_INET, get->fwmark);
else
svc = __ip_vs_service_find(net, AF_INET, get->protocol, &addr,
get->port);
if (svc) {
int count = 0;
struct ip_vs_dest *dest;
struct ip_vs_dest_entry entry;
list_for_each_entry(dest, &svc->destinations, n_list) {
if (count >= get->num_dests)
break;
entry.addr = dest->addr.ip;
entry.port = dest->port;
entry.conn_flags = atomic_read(&dest->conn_flags);
entry.weight = atomic_read(&dest->weight);
entry.u_threshold = dest->u_threshold;
entry.l_threshold = dest->l_threshold;
entry.activeconns = atomic_read(&dest->activeconns);
entry.inactconns = atomic_read(&dest->inactconns);
entry.persistconns = atomic_read(&dest->persistconns);
ip_vs_copy_stats(&entry.stats, &dest->stats);
if (copy_to_user(&uptr->entrytable[count],
&entry, sizeof(entry))) {
ret = -EFAULT;
break;
}
count++;
}
} else
ret = -ESRCH;
return ret;
}
static inline void
__ip_vs_get_timeouts(struct net *net, struct ip_vs_timeout_user *u)
{
#if defined(CONFIG_IP_VS_PROTO_TCP) || defined(CONFIG_IP_VS_PROTO_UDP)
struct ip_vs_proto_data *pd;
#endif
#ifdef CONFIG_IP_VS_PROTO_TCP
pd = ip_vs_proto_data_get(net, IPPROTO_TCP);
u->tcp_timeout = pd->timeout_table[IP_VS_TCP_S_ESTABLISHED] / HZ;
u->tcp_fin_timeout = pd->timeout_table[IP_VS_TCP_S_FIN_WAIT] / HZ;
#endif
#ifdef CONFIG_IP_VS_PROTO_UDP
pd = ip_vs_proto_data_get(net, IPPROTO_UDP);
u->udp_timeout =
pd->timeout_table[IP_VS_UDP_S_NORMAL] / HZ;
#endif
}
static int
do_ip_vs_get_ctl(struct sock *sk, int cmd, void __user *user, int *len)
{
unsigned char arg[128];
int ret = 0;
unsigned int copylen;
struct net *net = sock_net(sk);
struct netns_ipvs *ipvs = net_ipvs(net);
BUG_ON(!net);
if (!capable(CAP_NET_ADMIN))
return -EPERM;
if (cmd < IP_VS_BASE_CTL || cmd > IP_VS_SO_GET_MAX)
return -EINVAL;
if (*len < get_arglen[GET_CMDID(cmd)]) {
pr_err("get_ctl: len %u < %u\n",
*len, get_arglen[GET_CMDID(cmd)]);
return -EINVAL;
}
copylen = get_arglen[GET_CMDID(cmd)];
if (copylen > 128)
return -EINVAL;
if (copy_from_user(arg, user, copylen) != 0)
return -EFAULT;
if (cmd == IP_VS_SO_GET_DAEMON) {
struct ip_vs_daemon_user d[2];
memset(&d, 0, sizeof(d));
if (mutex_lock_interruptible(&ipvs->sync_mutex))
return -ERESTARTSYS;
if (ipvs->sync_state & IP_VS_STATE_MASTER) {
d[0].state = IP_VS_STATE_MASTER;
strlcpy(d[0].mcast_ifn, ipvs->master_mcast_ifn,
sizeof(d[0].mcast_ifn));
d[0].syncid = ipvs->master_syncid;
}
if (ipvs->sync_state & IP_VS_STATE_BACKUP) {
d[1].state = IP_VS_STATE_BACKUP;
strlcpy(d[1].mcast_ifn, ipvs->backup_mcast_ifn,
sizeof(d[1].mcast_ifn));
d[1].syncid = ipvs->backup_syncid;
}
if (copy_to_user(user, &d, sizeof(d)) != 0)
ret = -EFAULT;
mutex_unlock(&ipvs->sync_mutex);
return ret;
}
if (mutex_lock_interruptible(&__ip_vs_mutex))
return -ERESTARTSYS;
switch (cmd) {
case IP_VS_SO_GET_VERSION:
{
char buf[64];
sprintf(buf, "IP Virtual Server version %d.%d.%d (size=%d)",
NVERSION(IP_VS_VERSION_CODE), ip_vs_conn_tab_size);
if (copy_to_user(user, buf, strlen(buf)+1) != 0) {
ret = -EFAULT;
goto out;
}
*len = strlen(buf)+1;
}
break;
case IP_VS_SO_GET_INFO:
{
struct ip_vs_getinfo info;
info.version = IP_VS_VERSION_CODE;
info.size = ip_vs_conn_tab_size;
info.num_services = ipvs->num_services;
if (copy_to_user(user, &info, sizeof(info)) != 0)
ret = -EFAULT;
}
break;
case IP_VS_SO_GET_SERVICES:
{
struct ip_vs_get_services *get;
int size;
get = (struct ip_vs_get_services *)arg;
size = sizeof(*get) +
sizeof(struct ip_vs_service_entry) * get->num_services;
if (*len != size) {
pr_err("length: %u != %u\n", *len, size);
ret = -EINVAL;
goto out;
}
ret = __ip_vs_get_service_entries(net, get, user);
}
break;
case IP_VS_SO_GET_SERVICE:
{
struct ip_vs_service_entry *entry;
struct ip_vs_service *svc;
union nf_inet_addr addr;
entry = (struct ip_vs_service_entry *)arg;
addr.ip = entry->addr;
if (entry->fwmark)
svc = __ip_vs_svc_fwm_find(net, AF_INET, entry->fwmark);
else
svc = __ip_vs_service_find(net, AF_INET,
entry->protocol, &addr,
entry->port);
if (svc) {
ip_vs_copy_service(entry, svc);
if (copy_to_user(user, entry, sizeof(*entry)) != 0)
ret = -EFAULT;
} else
ret = -ESRCH;
}
break;
case IP_VS_SO_GET_DESTS:
{
struct ip_vs_get_dests *get;
int size;
get = (struct ip_vs_get_dests *)arg;
size = sizeof(*get) +
sizeof(struct ip_vs_dest_entry) * get->num_dests;
if (*len != size) {
pr_err("length: %u != %u\n", *len, size);
ret = -EINVAL;
goto out;
}
ret = __ip_vs_get_dest_entries(net, get, user);
}
break;
case IP_VS_SO_GET_TIMEOUT:
{
struct ip_vs_timeout_user t;
__ip_vs_get_timeouts(net, &t);
if (copy_to_user(user, &t, sizeof(t)) != 0)
ret = -EFAULT;
}
break;
default:
ret = -EINVAL;
}
out:
mutex_unlock(&__ip_vs_mutex);
return ret;
}
static int ip_vs_genl_fill_stats(struct sk_buff *skb, int container_type,
struct ip_vs_stats *stats)
{
struct ip_vs_stats_user ustats;
struct nlattr *nl_stats = nla_nest_start(skb, container_type);
if (!nl_stats)
return -EMSGSIZE;
ip_vs_copy_stats(&ustats, stats);
NLA_PUT_U32(skb, IPVS_STATS_ATTR_CONNS, ustats.conns);
NLA_PUT_U32(skb, IPVS_STATS_ATTR_INPKTS, ustats.inpkts);
NLA_PUT_U32(skb, IPVS_STATS_ATTR_OUTPKTS, ustats.outpkts);
NLA_PUT_U64(skb, IPVS_STATS_ATTR_INBYTES, ustats.inbytes);
NLA_PUT_U64(skb, IPVS_STATS_ATTR_OUTBYTES, ustats.outbytes);
NLA_PUT_U32(skb, IPVS_STATS_ATTR_CPS, ustats.cps);
NLA_PUT_U32(skb, IPVS_STATS_ATTR_INPPS, ustats.inpps);
NLA_PUT_U32(skb, IPVS_STATS_ATTR_OUTPPS, ustats.outpps);
NLA_PUT_U32(skb, IPVS_STATS_ATTR_INBPS, ustats.inbps);
NLA_PUT_U32(skb, IPVS_STATS_ATTR_OUTBPS, ustats.outbps);
nla_nest_end(skb, nl_stats);
return 0;
nla_put_failure:
nla_nest_cancel(skb, nl_stats);
return -EMSGSIZE;
}
static int ip_vs_genl_fill_service(struct sk_buff *skb,
struct ip_vs_service *svc)
{
struct nlattr *nl_service;
struct ip_vs_flags flags = { .flags = svc->flags,
.mask = ~0 };
nl_service = nla_nest_start(skb, IPVS_CMD_ATTR_SERVICE);
if (!nl_service)
return -EMSGSIZE;
NLA_PUT_U16(skb, IPVS_SVC_ATTR_AF, svc->af);
if (svc->fwmark) {
NLA_PUT_U32(skb, IPVS_SVC_ATTR_FWMARK, svc->fwmark);
} else {
NLA_PUT_U16(skb, IPVS_SVC_ATTR_PROTOCOL, svc->protocol);
NLA_PUT(skb, IPVS_SVC_ATTR_ADDR, sizeof(svc->addr), &svc->addr);
NLA_PUT_U16(skb, IPVS_SVC_ATTR_PORT, svc->port);
}
NLA_PUT_STRING(skb, IPVS_SVC_ATTR_SCHED_NAME, svc->scheduler->name);
if (svc->pe)
NLA_PUT_STRING(skb, IPVS_SVC_ATTR_PE_NAME, svc->pe->name);
NLA_PUT(skb, IPVS_SVC_ATTR_FLAGS, sizeof(flags), &flags);
NLA_PUT_U32(skb, IPVS_SVC_ATTR_TIMEOUT, svc->timeout / HZ);
NLA_PUT_U32(skb, IPVS_SVC_ATTR_NETMASK, svc->netmask);
if (ip_vs_genl_fill_stats(skb, IPVS_SVC_ATTR_STATS, &svc->stats))
goto nla_put_failure;
nla_nest_end(skb, nl_service);
return 0;
nla_put_failure:
nla_nest_cancel(skb, nl_service);
return -EMSGSIZE;
}
static int ip_vs_genl_dump_service(struct sk_buff *skb,
struct ip_vs_service *svc,
struct netlink_callback *cb)
{
void *hdr;
hdr = genlmsg_put(skb, NETLINK_CB(cb->skb).pid, cb->nlh->nlmsg_seq,
&ip_vs_genl_family, NLM_F_MULTI,
IPVS_CMD_NEW_SERVICE);
if (!hdr)
return -EMSGSIZE;
if (ip_vs_genl_fill_service(skb, svc) < 0)
goto nla_put_failure;
return genlmsg_end(skb, hdr);
nla_put_failure:
genlmsg_cancel(skb, hdr);
return -EMSGSIZE;
}
static int ip_vs_genl_dump_services(struct sk_buff *skb,
struct netlink_callback *cb)
{
int idx = 0, i;
int start = cb->args[0];
struct ip_vs_service *svc;
struct net *net = skb_sknet(skb);
mutex_lock(&__ip_vs_mutex);
for (i = 0; i < IP_VS_SVC_TAB_SIZE; i++) {
list_for_each_entry(svc, &ip_vs_svc_table[i], s_list) {
if (++idx <= start || !net_eq(svc->net, net))
continue;
if (ip_vs_genl_dump_service(skb, svc, cb) < 0) {
idx--;
goto nla_put_failure;
}
}
}
for (i = 0; i < IP_VS_SVC_TAB_SIZE; i++) {
list_for_each_entry(svc, &ip_vs_svc_fwm_table[i], f_list) {
if (++idx <= start || !net_eq(svc->net, net))
continue;
if (ip_vs_genl_dump_service(skb, svc, cb) < 0) {
idx--;
goto nla_put_failure;
}
}
}
nla_put_failure:
mutex_unlock(&__ip_vs_mutex);
cb->args[0] = idx;
return skb->len;
}
static int ip_vs_genl_parse_service(struct net *net,
struct ip_vs_service_user_kern *usvc,
struct nlattr *nla, int full_entry,
struct ip_vs_service **ret_svc)
{
struct nlattr *attrs[IPVS_SVC_ATTR_MAX + 1];
struct nlattr *nla_af, *nla_port, *nla_fwmark, *nla_protocol, *nla_addr;
struct ip_vs_service *svc;
if (nla == NULL ||
nla_parse_nested(attrs, IPVS_SVC_ATTR_MAX, nla, ip_vs_svc_policy))
return -EINVAL;
nla_af = attrs[IPVS_SVC_ATTR_AF];
nla_protocol = attrs[IPVS_SVC_ATTR_PROTOCOL];
nla_addr = attrs[IPVS_SVC_ATTR_ADDR];
nla_port = attrs[IPVS_SVC_ATTR_PORT];
nla_fwmark = attrs[IPVS_SVC_ATTR_FWMARK];
if (!(nla_af && (nla_fwmark || (nla_port && nla_protocol && nla_addr))))
return -EINVAL;
memset(usvc, 0, sizeof(*usvc));
usvc->af = nla_get_u16(nla_af);
#ifdef CONFIG_IP_VS_IPV6
if (usvc->af != AF_INET && usvc->af != AF_INET6)
#else
if (usvc->af != AF_INET)
#endif
return -EAFNOSUPPORT;
if (nla_fwmark) {
usvc->protocol = IPPROTO_TCP;
usvc->fwmark = nla_get_u32(nla_fwmark);
} else {
usvc->protocol = nla_get_u16(nla_protocol);
nla_memcpy(&usvc->addr, nla_addr, sizeof(usvc->addr));
usvc->port = nla_get_u16(nla_port);
usvc->fwmark = 0;
}
if (usvc->fwmark)
svc = __ip_vs_svc_fwm_find(net, usvc->af, usvc->fwmark);
else
svc = __ip_vs_service_find(net, usvc->af, usvc->protocol,
&usvc->addr, usvc->port);
*ret_svc = svc;
if (full_entry) {
struct nlattr *nla_sched, *nla_flags, *nla_pe, *nla_timeout,
*nla_netmask;
struct ip_vs_flags flags;
nla_sched = attrs[IPVS_SVC_ATTR_SCHED_NAME];
nla_pe = attrs[IPVS_SVC_ATTR_PE_NAME];
nla_flags = attrs[IPVS_SVC_ATTR_FLAGS];
nla_timeout = attrs[IPVS_SVC_ATTR_TIMEOUT];
nla_netmask = attrs[IPVS_SVC_ATTR_NETMASK];
if (!(nla_sched && nla_flags && nla_timeout && nla_netmask))
return -EINVAL;
nla_memcpy(&flags, nla_flags, sizeof(flags));
if (svc)
usvc->flags = svc->flags;
usvc->flags = (usvc->flags & ~flags.mask) |
(flags.flags & flags.mask);
usvc->sched_name = nla_data(nla_sched);
usvc->pe_name = nla_pe ? nla_data(nla_pe) : NULL;
usvc->timeout = nla_get_u32(nla_timeout);
usvc->netmask = nla_get_u32(nla_netmask);
}
return 0;
}
static struct ip_vs_service *ip_vs_genl_find_service(struct net *net,
struct nlattr *nla)
{
struct ip_vs_service_user_kern usvc;
struct ip_vs_service *svc;
int ret;
ret = ip_vs_genl_parse_service(net, &usvc, nla, 0, &svc);
return ret ? ERR_PTR(ret) : svc;
}
static int ip_vs_genl_fill_dest(struct sk_buff *skb, struct ip_vs_dest *dest)
{
struct nlattr *nl_dest;
nl_dest = nla_nest_start(skb, IPVS_CMD_ATTR_DEST);
if (!nl_dest)
return -EMSGSIZE;
NLA_PUT(skb, IPVS_DEST_ATTR_ADDR, sizeof(dest->addr), &dest->addr);
NLA_PUT_U16(skb, IPVS_DEST_ATTR_PORT, dest->port);
NLA_PUT_U32(skb, IPVS_DEST_ATTR_FWD_METHOD,
atomic_read(&dest->conn_flags) & IP_VS_CONN_F_FWD_MASK);
NLA_PUT_U32(skb, IPVS_DEST_ATTR_WEIGHT, atomic_read(&dest->weight));
NLA_PUT_U32(skb, IPVS_DEST_ATTR_U_THRESH, dest->u_threshold);
NLA_PUT_U32(skb, IPVS_DEST_ATTR_L_THRESH, dest->l_threshold);
NLA_PUT_U32(skb, IPVS_DEST_ATTR_ACTIVE_CONNS,
atomic_read(&dest->activeconns));
NLA_PUT_U32(skb, IPVS_DEST_ATTR_INACT_CONNS,
atomic_read(&dest->inactconns));
NLA_PUT_U32(skb, IPVS_DEST_ATTR_PERSIST_CONNS,
atomic_read(&dest->persistconns));
if (ip_vs_genl_fill_stats(skb, IPVS_DEST_ATTR_STATS, &dest->stats))
goto nla_put_failure;
nla_nest_end(skb, nl_dest);
return 0;
nla_put_failure:
nla_nest_cancel(skb, nl_dest);
return -EMSGSIZE;
}
static int ip_vs_genl_dump_dest(struct sk_buff *skb, struct ip_vs_dest *dest,
struct netlink_callback *cb)
{
void *hdr;
hdr = genlmsg_put(skb, NETLINK_CB(cb->skb).pid, cb->nlh->nlmsg_seq,
&ip_vs_genl_family, NLM_F_MULTI,
IPVS_CMD_NEW_DEST);
if (!hdr)
return -EMSGSIZE;
if (ip_vs_genl_fill_dest(skb, dest) < 0)
goto nla_put_failure;
return genlmsg_end(skb, hdr);
nla_put_failure:
genlmsg_cancel(skb, hdr);
return -EMSGSIZE;
}
static int ip_vs_genl_dump_dests(struct sk_buff *skb,
struct netlink_callback *cb)
{
int idx = 0;
int start = cb->args[0];
struct ip_vs_service *svc;
struct ip_vs_dest *dest;
struct nlattr *attrs[IPVS_CMD_ATTR_MAX + 1];
struct net *net = skb_sknet(skb);
mutex_lock(&__ip_vs_mutex);
if (nlmsg_parse(cb->nlh, GENL_HDRLEN, attrs,
IPVS_CMD_ATTR_MAX, ip_vs_cmd_policy))
goto out_err;
svc = ip_vs_genl_find_service(net, attrs[IPVS_CMD_ATTR_SERVICE]);
if (IS_ERR(svc) || svc == NULL)
goto out_err;
list_for_each_entry(dest, &svc->destinations, n_list) {
if (++idx <= start)
continue;
if (ip_vs_genl_dump_dest(skb, dest, cb) < 0) {
idx--;
goto nla_put_failure;
}
}
nla_put_failure:
cb->args[0] = idx;
out_err:
mutex_unlock(&__ip_vs_mutex);
return skb->len;
}
static int ip_vs_genl_parse_dest(struct ip_vs_dest_user_kern *udest,
struct nlattr *nla, int full_entry)
{
struct nlattr *attrs[IPVS_DEST_ATTR_MAX + 1];
struct nlattr *nla_addr, *nla_port;
if (nla == NULL ||
nla_parse_nested(attrs, IPVS_DEST_ATTR_MAX, nla, ip_vs_dest_policy))
return -EINVAL;
nla_addr = attrs[IPVS_DEST_ATTR_ADDR];
nla_port = attrs[IPVS_DEST_ATTR_PORT];
if (!(nla_addr && nla_port))
return -EINVAL;
memset(udest, 0, sizeof(*udest));
nla_memcpy(&udest->addr, nla_addr, sizeof(udest->addr));
udest->port = nla_get_u16(nla_port);
if (full_entry) {
struct nlattr *nla_fwd, *nla_weight, *nla_u_thresh,
*nla_l_thresh;
nla_fwd = attrs[IPVS_DEST_ATTR_FWD_METHOD];
nla_weight = attrs[IPVS_DEST_ATTR_WEIGHT];
nla_u_thresh = attrs[IPVS_DEST_ATTR_U_THRESH];
nla_l_thresh = attrs[IPVS_DEST_ATTR_L_THRESH];
if (!(nla_fwd && nla_weight && nla_u_thresh && nla_l_thresh))
return -EINVAL;
udest->conn_flags = nla_get_u32(nla_fwd)
& IP_VS_CONN_F_FWD_MASK;
udest->weight = nla_get_u32(nla_weight);
udest->u_threshold = nla_get_u32(nla_u_thresh);
udest->l_threshold = nla_get_u32(nla_l_thresh);
}
return 0;
}
static int ip_vs_genl_fill_daemon(struct sk_buff *skb, __be32 state,
const char *mcast_ifn, __be32 syncid)
{
struct nlattr *nl_daemon;
nl_daemon = nla_nest_start(skb, IPVS_CMD_ATTR_DAEMON);
if (!nl_daemon)
return -EMSGSIZE;
NLA_PUT_U32(skb, IPVS_DAEMON_ATTR_STATE, state);
NLA_PUT_STRING(skb, IPVS_DAEMON_ATTR_MCAST_IFN, mcast_ifn);
NLA_PUT_U32(skb, IPVS_DAEMON_ATTR_SYNC_ID, syncid);
nla_nest_end(skb, nl_daemon);
return 0;
nla_put_failure:
nla_nest_cancel(skb, nl_daemon);
return -EMSGSIZE;
}
static int ip_vs_genl_dump_daemon(struct sk_buff *skb, __be32 state,
const char *mcast_ifn, __be32 syncid,
struct netlink_callback *cb)
{
void *hdr;
hdr = genlmsg_put(skb, NETLINK_CB(cb->skb).pid, cb->nlh->nlmsg_seq,
&ip_vs_genl_family, NLM_F_MULTI,
IPVS_CMD_NEW_DAEMON);
if (!hdr)
return -EMSGSIZE;
if (ip_vs_genl_fill_daemon(skb, state, mcast_ifn, syncid))
goto nla_put_failure;
return genlmsg_end(skb, hdr);
nla_put_failure:
genlmsg_cancel(skb, hdr);
return -EMSGSIZE;
}
static int ip_vs_genl_dump_daemons(struct sk_buff *skb,
struct netlink_callback *cb)
{
struct net *net = skb_sknet(skb);
struct netns_ipvs *ipvs = net_ipvs(net);
mutex_lock(&ipvs->sync_mutex);
if ((ipvs->sync_state & IP_VS_STATE_MASTER) && !cb->args[0]) {
if (ip_vs_genl_dump_daemon(skb, IP_VS_STATE_MASTER,
ipvs->master_mcast_ifn,
ipvs->master_syncid, cb) < 0)
goto nla_put_failure;
cb->args[0] = 1;
}
if ((ipvs->sync_state & IP_VS_STATE_BACKUP) && !cb->args[1]) {
if (ip_vs_genl_dump_daemon(skb, IP_VS_STATE_BACKUP,
ipvs->backup_mcast_ifn,
ipvs->backup_syncid, cb) < 0)
goto nla_put_failure;
cb->args[1] = 1;
}
nla_put_failure:
mutex_unlock(&ipvs->sync_mutex);
return skb->len;
}
static int ip_vs_genl_new_daemon(struct net *net, struct nlattr **attrs)
{
if (!(attrs[IPVS_DAEMON_ATTR_STATE] &&
attrs[IPVS_DAEMON_ATTR_MCAST_IFN] &&
attrs[IPVS_DAEMON_ATTR_SYNC_ID]))
return -EINVAL;
return start_sync_thread(net,
nla_get_u32(attrs[IPVS_DAEMON_ATTR_STATE]),
nla_data(attrs[IPVS_DAEMON_ATTR_MCAST_IFN]),
nla_get_u32(attrs[IPVS_DAEMON_ATTR_SYNC_ID]));
}
static int ip_vs_genl_del_daemon(struct net *net, struct nlattr **attrs)
{
if (!attrs[IPVS_DAEMON_ATTR_STATE])
return -EINVAL;
return stop_sync_thread(net,
nla_get_u32(attrs[IPVS_DAEMON_ATTR_STATE]));
}
static int ip_vs_genl_set_config(struct net *net, struct nlattr **attrs)
{
struct ip_vs_timeout_user t;
__ip_vs_get_timeouts(net, &t);
if (attrs[IPVS_CMD_ATTR_TIMEOUT_TCP])
t.tcp_timeout = nla_get_u32(attrs[IPVS_CMD_ATTR_TIMEOUT_TCP]);
if (attrs[IPVS_CMD_ATTR_TIMEOUT_TCP_FIN])
t.tcp_fin_timeout =
nla_get_u32(attrs[IPVS_CMD_ATTR_TIMEOUT_TCP_FIN]);
if (attrs[IPVS_CMD_ATTR_TIMEOUT_UDP])
t.udp_timeout = nla_get_u32(attrs[IPVS_CMD_ATTR_TIMEOUT_UDP]);
return ip_vs_set_timeout(net, &t);
}
static int ip_vs_genl_set_daemon(struct sk_buff *skb, struct genl_info *info)
{
int ret = 0, cmd;
struct net *net;
struct netns_ipvs *ipvs;
net = skb_sknet(skb);
ipvs = net_ipvs(net);
cmd = info->genlhdr->cmd;
if (cmd == IPVS_CMD_NEW_DAEMON || cmd == IPVS_CMD_DEL_DAEMON) {
struct nlattr *daemon_attrs[IPVS_DAEMON_ATTR_MAX + 1];
mutex_lock(&ipvs->sync_mutex);
if (!info->attrs[IPVS_CMD_ATTR_DAEMON] ||
nla_parse_nested(daemon_attrs, IPVS_DAEMON_ATTR_MAX,
info->attrs[IPVS_CMD_ATTR_DAEMON],
ip_vs_daemon_policy)) {
ret = -EINVAL;
goto out;
}
if (cmd == IPVS_CMD_NEW_DAEMON)
ret = ip_vs_genl_new_daemon(net, daemon_attrs);
else
ret = ip_vs_genl_del_daemon(net, daemon_attrs);
out:
mutex_unlock(&ipvs->sync_mutex);
}
return ret;
}
static int ip_vs_genl_set_cmd(struct sk_buff *skb, struct genl_info *info)
{
struct ip_vs_service *svc = NULL;
struct ip_vs_service_user_kern usvc;
struct ip_vs_dest_user_kern udest;
int ret = 0, cmd;
int need_full_svc = 0, need_full_dest = 0;
struct net *net;
net = skb_sknet(skb);
cmd = info->genlhdr->cmd;
mutex_lock(&__ip_vs_mutex);
if (cmd == IPVS_CMD_FLUSH) {
ret = ip_vs_flush(net);
goto out;
} else if (cmd == IPVS_CMD_SET_CONFIG) {
ret = ip_vs_genl_set_config(net, info->attrs);
goto out;
} else if (cmd == IPVS_CMD_ZERO &&
!info->attrs[IPVS_CMD_ATTR_SERVICE]) {
ret = ip_vs_zero_all(net);
goto out;
}
if (cmd == IPVS_CMD_NEW_SERVICE || cmd == IPVS_CMD_SET_SERVICE)
need_full_svc = 1;
ret = ip_vs_genl_parse_service(net, &usvc,
info->attrs[IPVS_CMD_ATTR_SERVICE],
need_full_svc, &svc);
if (ret)
goto out;
if ((cmd != IPVS_CMD_NEW_SERVICE) && (svc == NULL)) {
ret = -ESRCH;
goto out;
}
if (cmd == IPVS_CMD_NEW_DEST || cmd == IPVS_CMD_SET_DEST ||
cmd == IPVS_CMD_DEL_DEST) {
if (cmd != IPVS_CMD_DEL_DEST)
need_full_dest = 1;
ret = ip_vs_genl_parse_dest(&udest,
info->attrs[IPVS_CMD_ATTR_DEST],
need_full_dest);
if (ret)
goto out;
}
switch (cmd) {
case IPVS_CMD_NEW_SERVICE:
if (svc == NULL)
ret = ip_vs_add_service(net, &usvc, &svc);
else
ret = -EEXIST;
break;
case IPVS_CMD_SET_SERVICE:
ret = ip_vs_edit_service(svc, &usvc);
break;
case IPVS_CMD_DEL_SERVICE:
ret = ip_vs_del_service(svc);
break;
case IPVS_CMD_NEW_DEST:
ret = ip_vs_add_dest(svc, &udest);
break;
case IPVS_CMD_SET_DEST:
ret = ip_vs_edit_dest(svc, &udest);
break;
case IPVS_CMD_DEL_DEST:
ret = ip_vs_del_dest(svc, &udest);
break;
case IPVS_CMD_ZERO:
ret = ip_vs_zero_service(svc);
break;
default:
ret = -EINVAL;
}
out:
mutex_unlock(&__ip_vs_mutex);
return ret;
}
static int ip_vs_genl_get_cmd(struct sk_buff *skb, struct genl_info *info)
{
struct sk_buff *msg;
void *reply;
int ret, cmd, reply_cmd;
struct net *net;
net = skb_sknet(skb);
cmd = info->genlhdr->cmd;
if (cmd == IPVS_CMD_GET_SERVICE)
reply_cmd = IPVS_CMD_NEW_SERVICE;
else if (cmd == IPVS_CMD_GET_INFO)
reply_cmd = IPVS_CMD_SET_INFO;
else if (cmd == IPVS_CMD_GET_CONFIG)
reply_cmd = IPVS_CMD_SET_CONFIG;
else {
pr_err("unknown Generic Netlink command\n");
return -EINVAL;
}
msg = nlmsg_new(NLMSG_DEFAULT_SIZE, GFP_KERNEL);
if (!msg)
return -ENOMEM;
mutex_lock(&__ip_vs_mutex);
reply = genlmsg_put_reply(msg, info, &ip_vs_genl_family, 0, reply_cmd);
if (reply == NULL)
goto nla_put_failure;
switch (cmd) {
case IPVS_CMD_GET_SERVICE:
{
struct ip_vs_service *svc;
svc = ip_vs_genl_find_service(net,
info->attrs[IPVS_CMD_ATTR_SERVICE]);
if (IS_ERR(svc)) {
ret = PTR_ERR(svc);
goto out_err;
} else if (svc) {
ret = ip_vs_genl_fill_service(msg, svc);
if (ret)
goto nla_put_failure;
} else {
ret = -ESRCH;
goto out_err;
}
break;
}
case IPVS_CMD_GET_CONFIG:
{
struct ip_vs_timeout_user t;
__ip_vs_get_timeouts(net, &t);
#ifdef CONFIG_IP_VS_PROTO_TCP
NLA_PUT_U32(msg, IPVS_CMD_ATTR_TIMEOUT_TCP, t.tcp_timeout);
NLA_PUT_U32(msg, IPVS_CMD_ATTR_TIMEOUT_TCP_FIN,
t.tcp_fin_timeout);
#endif
#ifdef CONFIG_IP_VS_PROTO_UDP
NLA_PUT_U32(msg, IPVS_CMD_ATTR_TIMEOUT_UDP, t.udp_timeout);
#endif
break;
}
case IPVS_CMD_GET_INFO:
NLA_PUT_U32(msg, IPVS_INFO_ATTR_VERSION, IP_VS_VERSION_CODE);
NLA_PUT_U32(msg, IPVS_INFO_ATTR_CONN_TAB_SIZE,
ip_vs_conn_tab_size);
break;
}
genlmsg_end(msg, reply);
ret = genlmsg_reply(msg, info);
goto out;
nla_put_failure:
pr_err("not enough space in Netlink message\n");
ret = -EMSGSIZE;
out_err:
nlmsg_free(msg);
out:
mutex_unlock(&__ip_vs_mutex);
return ret;
}
static int __init ip_vs_genl_register(void)
{
return genl_register_family_with_ops(&ip_vs_genl_family,
ip_vs_genl_ops, ARRAY_SIZE(ip_vs_genl_ops));
}
static void ip_vs_genl_unregister(void)
{
genl_unregister_family(&ip_vs_genl_family);
}
int __net_init ip_vs_control_net_init_sysctl(struct net *net)
{
int idx;
struct netns_ipvs *ipvs = net_ipvs(net);
struct ctl_table *tbl;
atomic_set(&ipvs->dropentry, 0);
spin_lock_init(&ipvs->dropentry_lock);
spin_lock_init(&ipvs->droppacket_lock);
spin_lock_init(&ipvs->securetcp_lock);
if (!net_eq(net, &init_net)) {
tbl = kmemdup(vs_vars, sizeof(vs_vars), GFP_KERNEL);
if (tbl == NULL)
return -ENOMEM;
} else
tbl = vs_vars;
idx = 0;
ipvs->sysctl_amemthresh = 1024;
tbl[idx++].data = &ipvs->sysctl_amemthresh;
ipvs->sysctl_am_droprate = 10;
tbl[idx++].data = &ipvs->sysctl_am_droprate;
tbl[idx++].data = &ipvs->sysctl_drop_entry;
tbl[idx++].data = &ipvs->sysctl_drop_packet;
#ifdef CONFIG_IP_VS_NFCT
tbl[idx++].data = &ipvs->sysctl_conntrack;
#endif
tbl[idx++].data = &ipvs->sysctl_secure_tcp;
ipvs->sysctl_snat_reroute = 1;
tbl[idx++].data = &ipvs->sysctl_snat_reroute;
ipvs->sysctl_sync_ver = 1;
tbl[idx++].data = &ipvs->sysctl_sync_ver;
tbl[idx++].data = &ipvs->sysctl_cache_bypass;
tbl[idx++].data = &ipvs->sysctl_expire_nodest_conn;
tbl[idx++].data = &ipvs->sysctl_expire_quiescent_template;
ipvs->sysctl_sync_threshold[0] = DEFAULT_SYNC_THRESHOLD;
ipvs->sysctl_sync_threshold[1] = DEFAULT_SYNC_PERIOD;
tbl[idx].data = &ipvs->sysctl_sync_threshold;
tbl[idx++].maxlen = sizeof(ipvs->sysctl_sync_threshold);
tbl[idx++].data = &ipvs->sysctl_nat_icmp_send;
ipvs->sysctl_hdr = register_net_sysctl_table(net, net_vs_ctl_path,
tbl);
if (ipvs->sysctl_hdr == NULL) {
if (!net_eq(net, &init_net))
kfree(tbl);
return -ENOMEM;
}
ip_vs_start_estimator(net, &ipvs->tot_stats);
ipvs->sysctl_tbl = tbl;
INIT_DELAYED_WORK(&ipvs->defense_work, defense_work_handler);
schedule_delayed_work(&ipvs->defense_work, DEFENSE_TIMER_PERIOD);
return 0;
}
void __net_init ip_vs_control_net_cleanup_sysctl(struct net *net)
{
struct netns_ipvs *ipvs = net_ipvs(net);
cancel_delayed_work_sync(&ipvs->defense_work);
cancel_work_sync(&ipvs->defense_work.work);
unregister_net_sysctl_table(ipvs->sysctl_hdr);
}
int __net_init ip_vs_control_net_init_sysctl(struct net *net) { return 0; }
void __net_init ip_vs_control_net_cleanup_sysctl(struct net *net) { }
int __net_init ip_vs_control_net_init(struct net *net)
{
int idx;
struct netns_ipvs *ipvs = net_ipvs(net);
rwlock_init(&ipvs->rs_lock);
for (idx = 0; idx < IP_VS_RTAB_SIZE; idx++)
INIT_LIST_HEAD(&ipvs->rs_table[idx]);
INIT_LIST_HEAD(&ipvs->dest_trash);
atomic_set(&ipvs->ftpsvc_counter, 0);
atomic_set(&ipvs->nullsvc_counter, 0);
ipvs->tot_stats.cpustats = alloc_percpu(struct ip_vs_cpu_stats);
if (!ipvs->tot_stats.cpustats)
return -ENOMEM;
spin_lock_init(&ipvs->tot_stats.lock);
proc_net_fops_create(net, "ip_vs", 0, &ip_vs_info_fops);
proc_net_fops_create(net, "ip_vs_stats", 0, &ip_vs_stats_fops);
proc_net_fops_create(net, "ip_vs_stats_percpu", 0,
&ip_vs_stats_percpu_fops);
if (ip_vs_control_net_init_sysctl(net))
goto err;
return 0;
err:
free_percpu(ipvs->tot_stats.cpustats);
return -ENOMEM;
}
void __net_exit ip_vs_control_net_cleanup(struct net *net)
{
struct netns_ipvs *ipvs = net_ipvs(net);
ip_vs_trash_cleanup(net);
ip_vs_stop_estimator(net, &ipvs->tot_stats);
ip_vs_control_net_cleanup_sysctl(net);
proc_net_remove(net, "ip_vs_stats_percpu");
proc_net_remove(net, "ip_vs_stats");
proc_net_remove(net, "ip_vs");
free_percpu(ipvs->tot_stats.cpustats);
}
int __init ip_vs_control_init(void)
{
int idx;
int ret;
EnterFunction(2);
for(idx = 0; idx < IP_VS_SVC_TAB_SIZE; idx++) {
INIT_LIST_HEAD(&ip_vs_svc_table[idx]);
INIT_LIST_HEAD(&ip_vs_svc_fwm_table[idx]);
}
smp_wmb();
ret = nf_register_sockopt(&ip_vs_sockopts);
if (ret) {
pr_err("cannot register sockopt.\n");
goto err_sock;
}
ret = ip_vs_genl_register();
if (ret) {
pr_err("cannot register Generic Netlink interface.\n");
goto err_genl;
}
ret = register_netdevice_notifier(&ip_vs_dst_notifier);
if (ret < 0)
goto err_notf;
LeaveFunction(2);
return 0;
err_notf:
ip_vs_genl_unregister();
err_genl:
nf_unregister_sockopt(&ip_vs_sockopts);
err_sock:
return ret;
}
void ip_vs_control_cleanup(void)
{
EnterFunction(2);
unregister_netdevice_notifier(&ip_vs_dst_notifier);
ip_vs_genl_unregister();
nf_unregister_sockopt(&ip_vs_sockopts);
LeaveFunction(2);
}
