static inline void ct_write_lock_bh(unsigned int key)
{
spin_lock_bh(&__ip_vs_conntbl_lock_array[key&CT_LOCKARRAY_MASK].l);
}
static inline void ct_write_unlock_bh(unsigned int key)
{
spin_unlock_bh(&__ip_vs_conntbl_lock_array[key&CT_LOCKARRAY_MASK].l);
}
static unsigned int ip_vs_conn_hashkey(struct netns_ipvs *ipvs, int af, unsigned int proto,
const union nf_inet_addr *addr,
__be16 port)
{
#ifdef CONFIG_IP_VS_IPV6
if (af == AF_INET6)
return (jhash_3words(jhash(addr, 16, ip_vs_conn_rnd),
(__force u32)port, proto, ip_vs_conn_rnd) ^
((size_t)ipvs>>8)) & ip_vs_conn_tab_mask;
#endif
return (jhash_3words((__force u32)addr->ip, (__force u32)port, proto,
ip_vs_conn_rnd) ^
((size_t)ipvs>>8)) & ip_vs_conn_tab_mask;
}
static unsigned int ip_vs_conn_hashkey_param(const struct ip_vs_conn_param *p,
bool inverse)
{
const union nf_inet_addr *addr;
__be16 port;
if (p->pe_data && p->pe->hashkey_raw)
return p->pe->hashkey_raw(p, ip_vs_conn_rnd, inverse) &
ip_vs_conn_tab_mask;
if (likely(!inverse)) {
addr = p->caddr;
port = p->cport;
} else {
addr = p->vaddr;
port = p->vport;
}
return ip_vs_conn_hashkey(p->ipvs, p->af, p->protocol, addr, port);
}
static unsigned int ip_vs_conn_hashkey_conn(const struct ip_vs_conn *cp)
{
struct ip_vs_conn_param p;
ip_vs_conn_fill_param(cp->ipvs, cp->af, cp->protocol,
&cp->caddr, cp->cport, NULL, 0, &p);
if (cp->pe) {
p.pe = cp->pe;
p.pe_data = cp->pe_data;
p.pe_data_len = cp->pe_data_len;
}
return ip_vs_conn_hashkey_param(&p, false);
}
static inline int ip_vs_conn_hash(struct ip_vs_conn *cp)
{
unsigned int hash;
int ret;
if (cp->flags & IP_VS_CONN_F_ONE_PACKET)
return 0;
hash = ip_vs_conn_hashkey_conn(cp);
ct_write_lock_bh(hash);
spin_lock(&cp->lock);
if (!(cp->flags & IP_VS_CONN_F_HASHED)) {
cp->flags |= IP_VS_CONN_F_HASHED;
refcount_inc(&cp->refcnt);
hlist_add_head_rcu(&cp->c_list, &ip_vs_conn_tab[hash]);
ret = 1;
} else {
pr_err("%s(): request for already hashed, called from %pF\n",
__func__, __builtin_return_address(0));
ret = 0;
}
spin_unlock(&cp->lock);
ct_write_unlock_bh(hash);
return ret;
}
static inline int ip_vs_conn_unhash(struct ip_vs_conn *cp)
{
unsigned int hash;
int ret;
hash = ip_vs_conn_hashkey_conn(cp);
ct_write_lock_bh(hash);
spin_lock(&cp->lock);
if (cp->flags & IP_VS_CONN_F_HASHED) {
hlist_del_rcu(&cp->c_list);
cp->flags &= ~IP_VS_CONN_F_HASHED;
refcount_dec(&cp->refcnt);
ret = 1;
} else
ret = 0;
spin_unlock(&cp->lock);
ct_write_unlock_bh(hash);
return ret;
}
static inline bool ip_vs_conn_unlink(struct ip_vs_conn *cp)
{
unsigned int hash;
bool ret;
hash = ip_vs_conn_hashkey_conn(cp);
ct_write_lock_bh(hash);
spin_lock(&cp->lock);
if (cp->flags & IP_VS_CONN_F_HASHED) {
ret = false;
if (refcount_dec_if_one(&cp->refcnt)) {
hlist_del_rcu(&cp->c_list);
cp->flags &= ~IP_VS_CONN_F_HASHED;
ret = true;
}
} else
ret = refcount_read(&cp->refcnt) ? false : true;
spin_unlock(&cp->lock);
ct_write_unlock_bh(hash);
return ret;
}
static inline struct ip_vs_conn *
__ip_vs_conn_in_get(const struct ip_vs_conn_param *p)
{
unsigned int hash;
struct ip_vs_conn *cp;
hash = ip_vs_conn_hashkey_param(p, false);
rcu_read_lock();
hlist_for_each_entry_rcu(cp, &ip_vs_conn_tab[hash], c_list) {
if (p->cport == cp->cport && p->vport == cp->vport &&
cp->af == p->af &&
ip_vs_addr_equal(p->af, p->caddr, &cp->caddr) &&
ip_vs_addr_equal(p->af, p->vaddr, &cp->vaddr) &&
((!p->cport) ^ (!(cp->flags & IP_VS_CONN_F_NO_CPORT))) &&
p->protocol == cp->protocol &&
cp->ipvs == p->ipvs) {
if (!__ip_vs_conn_get(cp))
continue;
rcu_read_unlock();
return cp;
}
}
rcu_read_unlock();
return NULL;
}
struct ip_vs_conn *ip_vs_conn_in_get(const struct ip_vs_conn_param *p)
{
struct ip_vs_conn *cp;
cp = __ip_vs_conn_in_get(p);
if (!cp && atomic_read(&ip_vs_conn_no_cport_cnt)) {
struct ip_vs_conn_param cport_zero_p = *p;
cport_zero_p.cport = 0;
cp = __ip_vs_conn_in_get(&cport_zero_p);
}
IP_VS_DBG_BUF(9, "lookup/in %s %s:%d->%s:%d %s\n",
ip_vs_proto_name(p->protocol),
IP_VS_DBG_ADDR(p->af, p->caddr), ntohs(p->cport),
IP_VS_DBG_ADDR(p->af, p->vaddr), ntohs(p->vport),
cp ? "hit" : "not hit");
return cp;
}
static int
ip_vs_conn_fill_param_proto(struct netns_ipvs *ipvs,
int af, const struct sk_buff *skb,
const struct ip_vs_iphdr *iph,
struct ip_vs_conn_param *p)
{
__be16 _ports[2], *pptr;
pptr = frag_safe_skb_hp(skb, iph->len, sizeof(_ports), _ports, iph);
if (pptr == NULL)
return 1;
if (likely(!ip_vs_iph_inverse(iph)))
ip_vs_conn_fill_param(ipvs, af, iph->protocol, &iph->saddr,
pptr[0], &iph->daddr, pptr[1], p);
else
ip_vs_conn_fill_param(ipvs, af, iph->protocol, &iph->daddr,
pptr[1], &iph->saddr, pptr[0], p);
return 0;
}
struct ip_vs_conn *
ip_vs_conn_in_get_proto(struct netns_ipvs *ipvs, int af,
const struct sk_buff *skb,
const struct ip_vs_iphdr *iph)
{
struct ip_vs_conn_param p;
if (ip_vs_conn_fill_param_proto(ipvs, af, skb, iph, &p))
return NULL;
return ip_vs_conn_in_get(&p);
}
struct ip_vs_conn *ip_vs_ct_in_get(const struct ip_vs_conn_param *p)
{
unsigned int hash;
struct ip_vs_conn *cp;
hash = ip_vs_conn_hashkey_param(p, false);
rcu_read_lock();
hlist_for_each_entry_rcu(cp, &ip_vs_conn_tab[hash], c_list) {
if (unlikely(p->pe_data && p->pe->ct_match)) {
if (cp->ipvs != p->ipvs)
continue;
if (p->pe == cp->pe && p->pe->ct_match(p, cp)) {
if (__ip_vs_conn_get(cp))
goto out;
}
continue;
}
if (cp->af == p->af &&
ip_vs_addr_equal(p->af, p->caddr, &cp->caddr) &&
ip_vs_addr_equal(p->protocol == IPPROTO_IP ? AF_UNSPEC :
p->af, p->vaddr, &cp->vaddr) &&
p->vport == cp->vport && p->cport == cp->cport &&
cp->flags & IP_VS_CONN_F_TEMPLATE &&
p->protocol == cp->protocol &&
cp->ipvs == p->ipvs) {
if (__ip_vs_conn_get(cp))
goto out;
}
}
cp = NULL;
out:
rcu_read_unlock();
IP_VS_DBG_BUF(9, "template lookup/in %s %s:%d->%s:%d %s\n",
ip_vs_proto_name(p->protocol),
IP_VS_DBG_ADDR(p->af, p->caddr), ntohs(p->cport),
IP_VS_DBG_ADDR(p->af, p->vaddr), ntohs(p->vport),
cp ? "hit" : "not hit");
return cp;
}
struct ip_vs_conn *ip_vs_conn_out_get(const struct ip_vs_conn_param *p)
{
unsigned int hash;
struct ip_vs_conn *cp, *ret=NULL;
hash = ip_vs_conn_hashkey_param(p, true);
rcu_read_lock();
hlist_for_each_entry_rcu(cp, &ip_vs_conn_tab[hash], c_list) {
if (p->vport == cp->cport && p->cport == cp->dport &&
cp->af == p->af &&
ip_vs_addr_equal(p->af, p->vaddr, &cp->caddr) &&
ip_vs_addr_equal(p->af, p->caddr, &cp->daddr) &&
p->protocol == cp->protocol &&
cp->ipvs == p->ipvs) {
if (!__ip_vs_conn_get(cp))
continue;
ret = cp;
break;
}
}
rcu_read_unlock();
IP_VS_DBG_BUF(9, "lookup/out %s %s:%d->%s:%d %s\n",
ip_vs_proto_name(p->protocol),
IP_VS_DBG_ADDR(p->af, p->caddr), ntohs(p->cport),
IP_VS_DBG_ADDR(p->af, p->vaddr), ntohs(p->vport),
ret ? "hit" : "not hit");
return ret;
}
struct ip_vs_conn *
ip_vs_conn_out_get_proto(struct netns_ipvs *ipvs, int af,
const struct sk_buff *skb,
const struct ip_vs_iphdr *iph)
{
struct ip_vs_conn_param p;
if (ip_vs_conn_fill_param_proto(ipvs, af, skb, iph, &p))
return NULL;
return ip_vs_conn_out_get(&p);
}
static void __ip_vs_conn_put_notimer(struct ip_vs_conn *cp)
{
__ip_vs_conn_put(cp);
ip_vs_conn_expire((unsigned long)cp);
}
static void __ip_vs_conn_put_timer(struct ip_vs_conn *cp)
{
unsigned long t = (cp->flags & IP_VS_CONN_F_ONE_PACKET) ?
0 : cp->timeout;
mod_timer(&cp->timer, jiffies+t);
__ip_vs_conn_put(cp);
}
void ip_vs_conn_put(struct ip_vs_conn *cp)
{
if ((cp->flags & IP_VS_CONN_F_ONE_PACKET) &&
(refcount_read(&cp->refcnt) == 1) &&
!timer_pending(&cp->timer))
__ip_vs_conn_put_notimer(cp);
else
__ip_vs_conn_put_timer(cp);
}
void ip_vs_conn_fill_cport(struct ip_vs_conn *cp, __be16 cport)
{
if (ip_vs_conn_unhash(cp)) {
spin_lock_bh(&cp->lock);
if (cp->flags & IP_VS_CONN_F_NO_CPORT) {
atomic_dec(&ip_vs_conn_no_cport_cnt);
cp->flags &= ~IP_VS_CONN_F_NO_CPORT;
cp->cport = cport;
}
spin_unlock_bh(&cp->lock);
ip_vs_conn_hash(cp);
}
}
static inline void ip_vs_bind_xmit(struct ip_vs_conn *cp)
{
switch (IP_VS_FWD_METHOD(cp)) {
case IP_VS_CONN_F_MASQ:
cp->packet_xmit = ip_vs_nat_xmit;
break;
case IP_VS_CONN_F_TUNNEL:
#ifdef CONFIG_IP_VS_IPV6
if (cp->daf == AF_INET6)
cp->packet_xmit = ip_vs_tunnel_xmit_v6;
else
#endif
cp->packet_xmit = ip_vs_tunnel_xmit;
break;
case IP_VS_CONN_F_DROUTE:
cp->packet_xmit = ip_vs_dr_xmit;
break;
case IP_VS_CONN_F_LOCALNODE:
cp->packet_xmit = ip_vs_null_xmit;
break;
case IP_VS_CONN_F_BYPASS:
cp->packet_xmit = ip_vs_bypass_xmit;
break;
}
}
static inline void ip_vs_bind_xmit_v6(struct ip_vs_conn *cp)
{
switch (IP_VS_FWD_METHOD(cp)) {
case IP_VS_CONN_F_MASQ:
cp->packet_xmit = ip_vs_nat_xmit_v6;
break;
case IP_VS_CONN_F_TUNNEL:
if (cp->daf == AF_INET6)
cp->packet_xmit = ip_vs_tunnel_xmit_v6;
else
cp->packet_xmit = ip_vs_tunnel_xmit;
break;
case IP_VS_CONN_F_DROUTE:
cp->packet_xmit = ip_vs_dr_xmit_v6;
break;
case IP_VS_CONN_F_LOCALNODE:
cp->packet_xmit = ip_vs_null_xmit;
break;
case IP_VS_CONN_F_BYPASS:
cp->packet_xmit = ip_vs_bypass_xmit_v6;
break;
}
}
static inline int ip_vs_dest_totalconns(struct ip_vs_dest *dest)
{
return atomic_read(&dest->activeconns)
+ atomic_read(&dest->inactconns);
}
static inline void
ip_vs_bind_dest(struct ip_vs_conn *cp, struct ip_vs_dest *dest)
{
unsigned int conn_flags;
__u32 flags;
if (!dest)
return;
ip_vs_dest_hold(dest);
conn_flags = atomic_read(&dest->conn_flags);
if (cp->protocol != IPPROTO_UDP)
conn_flags &= ~IP_VS_CONN_F_ONE_PACKET;
flags = cp->flags;
if (flags & IP_VS_CONN_F_SYNC) {
if (!(flags & IP_VS_CONN_F_TEMPLATE))
conn_flags &= ~IP_VS_CONN_F_INACTIVE;
flags &= ~(IP_VS_CONN_F_FWD_MASK | IP_VS_CONN_F_NOOUTPUT);
}
flags |= conn_flags;
cp->flags = flags;
cp->dest = dest;
IP_VS_DBG_BUF(7, "Bind-dest %s c:%s:%d v:%s:%d "
"d:%s:%d fwd:%c s:%u conn->flags:%X conn->refcnt:%d "
"dest->refcnt:%d\n",
ip_vs_proto_name(cp->protocol),
IP_VS_DBG_ADDR(cp->af, &cp->caddr), ntohs(cp->cport),
IP_VS_DBG_ADDR(cp->af, &cp->vaddr), ntohs(cp->vport),
IP_VS_DBG_ADDR(cp->daf, &cp->daddr), ntohs(cp->dport),
ip_vs_fwd_tag(cp), cp->state,
cp->flags, refcount_read(&cp->refcnt),
refcount_read(&dest->refcnt));
if (!(flags & IP_VS_CONN_F_TEMPLATE)) {
if (!(flags & IP_VS_CONN_F_INACTIVE))
atomic_inc(&dest->activeconns);
else
atomic_inc(&dest->inactconns);
} else {
atomic_inc(&dest->persistconns);
}
if (dest->u_threshold != 0 &&
ip_vs_dest_totalconns(dest) >= dest->u_threshold)
dest->flags |= IP_VS_DEST_F_OVERLOAD;
}
void ip_vs_try_bind_dest(struct ip_vs_conn *cp)
{
struct ip_vs_dest *dest;
rcu_read_lock();
dest = ip_vs_find_dest(cp->ipvs, cp->af, cp->af, &cp->daddr,
cp->dport, &cp->vaddr, cp->vport,
cp->protocol, cp->fwmark, cp->flags);
if (dest) {
struct ip_vs_proto_data *pd;
spin_lock_bh(&cp->lock);
if (cp->dest) {
spin_unlock_bh(&cp->lock);
rcu_read_unlock();
return;
}
if (cp->app)
ip_vs_unbind_app(cp);
ip_vs_bind_dest(cp, dest);
spin_unlock_bh(&cp->lock);
cp->packet_xmit = NULL;
#ifdef CONFIG_IP_VS_IPV6
if (cp->af == AF_INET6)
ip_vs_bind_xmit_v6(cp);
else
#endif
ip_vs_bind_xmit(cp);
pd = ip_vs_proto_data_get(cp->ipvs, cp->protocol);
if (pd && atomic_read(&pd->appcnt))
ip_vs_bind_app(cp, pd->pp);
}
rcu_read_unlock();
}
static inline void ip_vs_unbind_dest(struct ip_vs_conn *cp)
{
struct ip_vs_dest *dest = cp->dest;
if (!dest)
return;
IP_VS_DBG_BUF(7, "Unbind-dest %s c:%s:%d v:%s:%d "
"d:%s:%d fwd:%c s:%u conn->flags:%X conn->refcnt:%d "
"dest->refcnt:%d\n",
ip_vs_proto_name(cp->protocol),
IP_VS_DBG_ADDR(cp->af, &cp->caddr), ntohs(cp->cport),
IP_VS_DBG_ADDR(cp->af, &cp->vaddr), ntohs(cp->vport),
IP_VS_DBG_ADDR(cp->daf, &cp->daddr), ntohs(cp->dport),
ip_vs_fwd_tag(cp), cp->state,
cp->flags, refcount_read(&cp->refcnt),
refcount_read(&dest->refcnt));
if (!(cp->flags & IP_VS_CONN_F_TEMPLATE)) {
if (cp->flags & IP_VS_CONN_F_INACTIVE) {
atomic_dec(&dest->inactconns);
} else {
atomic_dec(&dest->activeconns);
}
} else {
atomic_dec(&dest->persistconns);
}
if (dest->l_threshold != 0) {
if (ip_vs_dest_totalconns(dest) < dest->l_threshold)
dest->flags &= ~IP_VS_DEST_F_OVERLOAD;
} else if (dest->u_threshold != 0) {
if (ip_vs_dest_totalconns(dest) * 4 < dest->u_threshold * 3)
dest->flags &= ~IP_VS_DEST_F_OVERLOAD;
} else {
if (dest->flags & IP_VS_DEST_F_OVERLOAD)
dest->flags &= ~IP_VS_DEST_F_OVERLOAD;
}
ip_vs_dest_put(dest);
}
static int expire_quiescent_template(struct netns_ipvs *ipvs,
struct ip_vs_dest *dest)
{
#ifdef CONFIG_SYSCTL
return ipvs->sysctl_expire_quiescent_template &&
(atomic_read(&dest->weight) == 0);
#else
return 0;
#endif
}
int ip_vs_check_template(struct ip_vs_conn *ct, struct ip_vs_dest *cdest)
{
struct ip_vs_dest *dest = ct->dest;
struct netns_ipvs *ipvs = ct->ipvs;
if ((dest == NULL) ||
!(dest->flags & IP_VS_DEST_F_AVAILABLE) ||
expire_quiescent_template(ipvs, dest) ||
(cdest && (dest != cdest))) {
IP_VS_DBG_BUF(9, "check_template: dest not available for "
"protocol %s s:%s:%d v:%s:%d "
"-> d:%s:%d\n",
ip_vs_proto_name(ct->protocol),
IP_VS_DBG_ADDR(ct->af, &ct->caddr),
ntohs(ct->cport),
IP_VS_DBG_ADDR(ct->af, &ct->vaddr),
ntohs(ct->vport),
IP_VS_DBG_ADDR(ct->daf, &ct->daddr),
ntohs(ct->dport));
if (ct->vport != htons(0xffff)) {
if (ip_vs_conn_unhash(ct)) {
ct->dport = htons(0xffff);
ct->vport = htons(0xffff);
ct->cport = 0;
ip_vs_conn_hash(ct);
}
}
__ip_vs_conn_put(ct);
return 0;
}
return 1;
}
static void ip_vs_conn_rcu_free(struct rcu_head *head)
{
struct ip_vs_conn *cp = container_of(head, struct ip_vs_conn,
rcu_head);
ip_vs_pe_put(cp->pe);
kfree(cp->pe_data);
kmem_cache_free(ip_vs_conn_cachep, cp);
}
static void ip_vs_conn_expire(unsigned long data)
{
struct ip_vs_conn *cp = (struct ip_vs_conn *)data;
struct netns_ipvs *ipvs = cp->ipvs;
if (atomic_read(&cp->n_control))
goto expire_later;
if (likely(ip_vs_conn_unlink(cp))) {
del_timer(&cp->timer);
if (cp->control)
ip_vs_control_del(cp);
if ((cp->flags & IP_VS_CONN_F_NFCT) &&
!(cp->flags & IP_VS_CONN_F_ONE_PACKET)) {
smp_rmb();
if (ipvs->enable)
ip_vs_conn_drop_conntrack(cp);
}
if (unlikely(cp->app != NULL))
ip_vs_unbind_app(cp);
ip_vs_unbind_dest(cp);
if (cp->flags & IP_VS_CONN_F_NO_CPORT)
atomic_dec(&ip_vs_conn_no_cport_cnt);
if (cp->flags & IP_VS_CONN_F_ONE_PACKET)
ip_vs_conn_rcu_free(&cp->rcu_head);
else
call_rcu(&cp->rcu_head, ip_vs_conn_rcu_free);
atomic_dec(&ipvs->conn_count);
return;
}
expire_later:
IP_VS_DBG(7, "delayed: conn->refcnt=%d conn->n_control=%d\n",
refcount_read(&cp->refcnt),
atomic_read(&cp->n_control));
refcount_inc(&cp->refcnt);
cp->timeout = 60*HZ;
if (ipvs->sync_state & IP_VS_STATE_MASTER)
ip_vs_sync_conn(ipvs, cp, sysctl_sync_threshold(ipvs));
__ip_vs_conn_put_timer(cp);
}
void ip_vs_conn_expire_now(struct ip_vs_conn *cp)
{
if (timer_pending(&cp->timer) &&
time_after(cp->timer.expires, jiffies))
mod_timer_pending(&cp->timer, jiffies);
}
struct ip_vs_conn *
ip_vs_conn_new(const struct ip_vs_conn_param *p, int dest_af,
const union nf_inet_addr *daddr, __be16 dport, unsigned int flags,
struct ip_vs_dest *dest, __u32 fwmark)
{
struct ip_vs_conn *cp;
struct netns_ipvs *ipvs = p->ipvs;
struct ip_vs_proto_data *pd = ip_vs_proto_data_get(p->ipvs,
p->protocol);
cp = kmem_cache_alloc(ip_vs_conn_cachep, GFP_ATOMIC);
if (cp == NULL) {
IP_VS_ERR_RL("%s(): no memory\n", __func__);
return NULL;
}
INIT_HLIST_NODE(&cp->c_list);
setup_timer(&cp->timer, ip_vs_conn_expire, (unsigned long)cp);
cp->ipvs = ipvs;
cp->af = p->af;
cp->daf = dest_af;
cp->protocol = p->protocol;
ip_vs_addr_set(p->af, &cp->caddr, p->caddr);
cp->cport = p->cport;
ip_vs_addr_set(p->protocol == IPPROTO_IP ? AF_UNSPEC : p->af,
&cp->vaddr, p->vaddr);
cp->vport = p->vport;
ip_vs_addr_set(cp->daf, &cp->daddr, daddr);
cp->dport = dport;
cp->flags = flags;
cp->fwmark = fwmark;
if (flags & IP_VS_CONN_F_TEMPLATE && p->pe) {
ip_vs_pe_get(p->pe);
cp->pe = p->pe;
cp->pe_data = p->pe_data;
cp->pe_data_len = p->pe_data_len;
} else {
cp->pe = NULL;
cp->pe_data = NULL;
cp->pe_data_len = 0;
}
spin_lock_init(&cp->lock);
refcount_set(&cp->refcnt, 1);
cp->control = NULL;
atomic_set(&cp->n_control, 0);
atomic_set(&cp->in_pkts, 0);
cp->packet_xmit = NULL;
cp->app = NULL;
cp->app_data = NULL;
cp->in_seq.delta = 0;
cp->out_seq.delta = 0;
atomic_inc(&ipvs->conn_count);
if (flags & IP_VS_CONN_F_NO_CPORT)
atomic_inc(&ip_vs_conn_no_cport_cnt);
cp->dest = NULL;
ip_vs_bind_dest(cp, dest);
cp->state = 0;
cp->old_state = 0;
cp->timeout = 3*HZ;
cp->sync_endtime = jiffies & ~3UL;
#ifdef CONFIG_IP_VS_IPV6
if (p->af == AF_INET6)
ip_vs_bind_xmit_v6(cp);
else
#endif
ip_vs_bind_xmit(cp);
if (unlikely(pd && atomic_read(&pd->appcnt)))
ip_vs_bind_app(cp, pd->pp);
if (ip_vs_conntrack_enabled(ipvs))
cp->flags |= IP_VS_CONN_F_NFCT;
ip_vs_conn_hash(cp);
return cp;
}
static void *ip_vs_conn_array(struct seq_file *seq, loff_t pos)
{
int idx;
struct ip_vs_conn *cp;
struct ip_vs_iter_state *iter = seq->private;
for (idx = 0; idx < ip_vs_conn_tab_size; idx++) {
hlist_for_each_entry_rcu(cp, &ip_vs_conn_tab[idx], c_list) {
if (pos-- == 0) {
iter->l = &ip_vs_conn_tab[idx];
return cp;
}
}
cond_resched_rcu();
}
return NULL;
}
static void *ip_vs_conn_seq_start(struct seq_file *seq, loff_t *pos)
__acquires(RCU)
{
struct ip_vs_iter_state *iter = seq->private;
iter->l = NULL;
rcu_read_lock();
return *pos ? ip_vs_conn_array(seq, *pos - 1) :SEQ_START_TOKEN;
}
static void *ip_vs_conn_seq_next(struct seq_file *seq, void *v, loff_t *pos)
{
struct ip_vs_conn *cp = v;
struct ip_vs_iter_state *iter = seq->private;
struct hlist_node *e;
struct hlist_head *l = iter->l;
int idx;
++*pos;
if (v == SEQ_START_TOKEN)
return ip_vs_conn_array(seq, 0);
e = rcu_dereference(hlist_next_rcu(&cp->c_list));
if (e)
return hlist_entry(e, struct ip_vs_conn, c_list);
idx = l - ip_vs_conn_tab;
while (++idx < ip_vs_conn_tab_size) {
hlist_for_each_entry_rcu(cp, &ip_vs_conn_tab[idx], c_list) {
iter->l = &ip_vs_conn_tab[idx];
return cp;
}
cond_resched_rcu();
}
iter->l = NULL;
return NULL;
}
static void ip_vs_conn_seq_stop(struct seq_file *seq, void *v)
__releases(RCU)
{
rcu_read_unlock();
}
static int ip_vs_conn_seq_show(struct seq_file *seq, void *v)
{
if (v == SEQ_START_TOKEN)
seq_puts(seq,
"Pro FromIP FPrt ToIP TPrt DestIP DPrt State Expires PEName PEData\n");
else {
const struct ip_vs_conn *cp = v;
struct net *net = seq_file_net(seq);
char pe_data[IP_VS_PENAME_MAXLEN + IP_VS_PEDATA_MAXLEN + 3];
size_t len = 0;
char dbuf[IP_VS_ADDRSTRLEN];
if (!net_eq(cp->ipvs->net, net))
return 0;
if (cp->pe_data) {
pe_data[0] = ' ';
len = strlen(cp->pe->name);
memcpy(pe_data + 1, cp->pe->name, len);
pe_data[len + 1] = ' ';
len += 2;
len += cp->pe->show_pe_data(cp, pe_data + len);
}
pe_data[len] = '\0';
#ifdef CONFIG_IP_VS_IPV6
if (cp->daf == AF_INET6)
snprintf(dbuf, sizeof(dbuf), "%pI6", &cp->daddr.in6);
else
#endif
snprintf(dbuf, sizeof(dbuf), "%08X",
ntohl(cp->daddr.ip));
#ifdef CONFIG_IP_VS_IPV6
if (cp->af == AF_INET6)
seq_printf(seq, "%-3s %pI6 %04X %pI6 %04X "
"%s %04X %-11s %7lu%s\n",
ip_vs_proto_name(cp->protocol),
&cp->caddr.in6, ntohs(cp->cport),
&cp->vaddr.in6, ntohs(cp->vport),
dbuf, ntohs(cp->dport),
ip_vs_state_name(cp->protocol, cp->state),
(cp->timer.expires-jiffies)/HZ, pe_data);
else
#endif
seq_printf(seq,
"%-3s %08X %04X %08X %04X"
" %s %04X %-11s %7lu%s\n",
ip_vs_proto_name(cp->protocol),
ntohl(cp->caddr.ip), ntohs(cp->cport),
ntohl(cp->vaddr.ip), ntohs(cp->vport),
dbuf, ntohs(cp->dport),
ip_vs_state_name(cp->protocol, cp->state),
(cp->timer.expires-jiffies)/HZ, pe_data);
}
return 0;
}
static int ip_vs_conn_open(struct inode *inode, struct file *file)
{
return seq_open_net(inode, file, &ip_vs_conn_seq_ops,
sizeof(struct ip_vs_iter_state));
}
static const char *ip_vs_origin_name(unsigned int flags)
{
if (flags & IP_VS_CONN_F_SYNC)
return "SYNC";
else
return "LOCAL";
}
static int ip_vs_conn_sync_seq_show(struct seq_file *seq, void *v)
{
char dbuf[IP_VS_ADDRSTRLEN];
if (v == SEQ_START_TOKEN)
seq_puts(seq,
"Pro FromIP FPrt ToIP TPrt DestIP DPrt State Origin Expires\n");
else {
const struct ip_vs_conn *cp = v;
struct net *net = seq_file_net(seq);
if (!net_eq(cp->ipvs->net, net))
return 0;
#ifdef CONFIG_IP_VS_IPV6
if (cp->daf == AF_INET6)
snprintf(dbuf, sizeof(dbuf), "%pI6", &cp->daddr.in6);
else
#endif
snprintf(dbuf, sizeof(dbuf), "%08X",
ntohl(cp->daddr.ip));
#ifdef CONFIG_IP_VS_IPV6
if (cp->af == AF_INET6)
seq_printf(seq, "%-3s %pI6 %04X %pI6 %04X "
"%s %04X %-11s %-6s %7lu\n",
ip_vs_proto_name(cp->protocol),
&cp->caddr.in6, ntohs(cp->cport),
&cp->vaddr.in6, ntohs(cp->vport),
dbuf, ntohs(cp->dport),
ip_vs_state_name(cp->protocol, cp->state),
ip_vs_origin_name(cp->flags),
(cp->timer.expires-jiffies)/HZ);
else
#endif
seq_printf(seq,
"%-3s %08X %04X %08X %04X "
"%s %04X %-11s %-6s %7lu\n",
ip_vs_proto_name(cp->protocol),
ntohl(cp->caddr.ip), ntohs(cp->cport),
ntohl(cp->vaddr.ip), ntohs(cp->vport),
dbuf, ntohs(cp->dport),
ip_vs_state_name(cp->protocol, cp->state),
ip_vs_origin_name(cp->flags),
(cp->timer.expires-jiffies)/HZ);
}
return 0;
}
static int ip_vs_conn_sync_open(struct inode *inode, struct file *file)
{
return seq_open_net(inode, file, &ip_vs_conn_sync_seq_ops,
sizeof(struct ip_vs_iter_state));
}
static inline int todrop_entry(struct ip_vs_conn *cp)
{
static const char todrop_rate[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
static char todrop_counter[9] = {0};
int i;
if (time_before(cp->timeout + jiffies, cp->timer.expires + 60*HZ))
return 0;
i = atomic_read(&cp->in_pkts);
if (i > 8 || i < 0) return 0;
if (!todrop_rate[i]) return 0;
if (--todrop_counter[i] > 0) return 0;
todrop_counter[i] = todrop_rate[i];
return 1;
}
static inline bool ip_vs_conn_ops_mode(struct ip_vs_conn *cp)
{
struct ip_vs_service *svc;
if (!cp->dest)
return false;
svc = rcu_dereference(cp->dest->svc);
return svc && (svc->flags & IP_VS_SVC_F_ONEPACKET);
}
void ip_vs_random_dropentry(struct netns_ipvs *ipvs)
{
int idx;
struct ip_vs_conn *cp, *cp_c;
rcu_read_lock();
for (idx = 0; idx < (ip_vs_conn_tab_size>>5); idx++) {
unsigned int hash = prandom_u32() & ip_vs_conn_tab_mask;
hlist_for_each_entry_rcu(cp, &ip_vs_conn_tab[hash], c_list) {
if (cp->ipvs != ipvs)
continue;
if (cp->flags & IP_VS_CONN_F_TEMPLATE) {
if (atomic_read(&cp->n_control) ||
!ip_vs_conn_ops_mode(cp))
continue;
else
goto try_drop;
}
if (cp->protocol == IPPROTO_TCP) {
switch(cp->state) {
case IP_VS_TCP_S_SYN_RECV:
case IP_VS_TCP_S_SYNACK:
break;
case IP_VS_TCP_S_ESTABLISHED:
if (todrop_entry(cp))
break;
continue;
default:
continue;
}
} else if (cp->protocol == IPPROTO_SCTP) {
switch (cp->state) {
case IP_VS_SCTP_S_INIT1:
case IP_VS_SCTP_S_INIT:
break;
case IP_VS_SCTP_S_ESTABLISHED:
if (todrop_entry(cp))
break;
continue;
default:
continue;
}
} else {
try_drop:
if (!todrop_entry(cp))
continue;
}
IP_VS_DBG(4, "del connection\n");
ip_vs_conn_expire_now(cp);
cp_c = cp->control;
if (cp_c && __ip_vs_conn_get(cp)) {
IP_VS_DBG(4, "del conn template\n");
ip_vs_conn_expire_now(cp_c);
__ip_vs_conn_put(cp);
}
}
cond_resched_rcu();
}
rcu_read_unlock();
}
static void ip_vs_conn_flush(struct netns_ipvs *ipvs)
{
int idx;
struct ip_vs_conn *cp, *cp_c;
flush_again:
rcu_read_lock();
for (idx = 0; idx < ip_vs_conn_tab_size; idx++) {
hlist_for_each_entry_rcu(cp, &ip_vs_conn_tab[idx], c_list) {
if (cp->ipvs != ipvs)
continue;
IP_VS_DBG(4, "del connection\n");
ip_vs_conn_expire_now(cp);
cp_c = cp->control;
if (cp_c && __ip_vs_conn_get(cp)) {
IP_VS_DBG(4, "del conn template\n");
ip_vs_conn_expire_now(cp_c);
__ip_vs_conn_put(cp);
}
}
cond_resched_rcu();
}
rcu_read_unlock();
if (atomic_read(&ipvs->conn_count) != 0) {
schedule();
goto flush_again;
}
}
int __net_init ip_vs_conn_net_init(struct netns_ipvs *ipvs)
{
atomic_set(&ipvs->conn_count, 0);
proc_create("ip_vs_conn", 0, ipvs->net->proc_net, &ip_vs_conn_fops);
proc_create("ip_vs_conn_sync", 0, ipvs->net->proc_net,
&ip_vs_conn_sync_fops);
return 0;
}
void __net_exit ip_vs_conn_net_cleanup(struct netns_ipvs *ipvs)
{
ip_vs_conn_flush(ipvs);
remove_proc_entry("ip_vs_conn", ipvs->net->proc_net);
remove_proc_entry("ip_vs_conn_sync", ipvs->net->proc_net);
}
int __init ip_vs_conn_init(void)
{
int idx;
ip_vs_conn_tab_size = 1 << ip_vs_conn_tab_bits;
ip_vs_conn_tab_mask = ip_vs_conn_tab_size - 1;
ip_vs_conn_tab = vmalloc(ip_vs_conn_tab_size * sizeof(*ip_vs_conn_tab));
if (!ip_vs_conn_tab)
return -ENOMEM;
ip_vs_conn_cachep = kmem_cache_create("ip_vs_conn",
sizeof(struct ip_vs_conn), 0,
SLAB_HWCACHE_ALIGN, NULL);
if (!ip_vs_conn_cachep) {
vfree(ip_vs_conn_tab);
return -ENOMEM;
}
pr_info("Connection hash table configured "
"(size=%d, memory=%ldKbytes)\n",
ip_vs_conn_tab_size,
(long)(ip_vs_conn_tab_size*sizeof(struct list_head))/1024);
IP_VS_DBG(0, "Each connection entry needs %zd bytes at least\n",
sizeof(struct ip_vs_conn));
for (idx = 0; idx < ip_vs_conn_tab_size; idx++)
INIT_HLIST_HEAD(&ip_vs_conn_tab[idx]);
for (idx = 0; idx < CT_LOCKARRAY_SIZE; idx++) {
spin_lock_init(&__ip_vs_conntbl_lock_array[idx].l);
}
get_random_bytes(&ip_vs_conn_rnd, sizeof(ip_vs_conn_rnd));
return 0;
}
void ip_vs_conn_cleanup(void)
{
rcu_barrier();
kmem_cache_destroy(ip_vs_conn_cachep);
vfree(ip_vs_conn_tab);
}
