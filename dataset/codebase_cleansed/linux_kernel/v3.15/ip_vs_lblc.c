static void ip_vs_lblc_rcu_free(struct rcu_head *head)
{
struct ip_vs_lblc_entry *en = container_of(head,
struct ip_vs_lblc_entry,
rcu_head);
ip_vs_dest_put_and_free(en->dest);
kfree(en);
}
static inline void ip_vs_lblc_del(struct ip_vs_lblc_entry *en)
{
hlist_del_rcu(&en->list);
call_rcu(&en->rcu_head, ip_vs_lblc_rcu_free);
}
static inline unsigned int
ip_vs_lblc_hashkey(int af, const union nf_inet_addr *addr)
{
__be32 addr_fold = addr->ip;
#ifdef CONFIG_IP_VS_IPV6
if (af == AF_INET6)
addr_fold = addr->ip6[0]^addr->ip6[1]^
addr->ip6[2]^addr->ip6[3];
#endif
return (ntohl(addr_fold)*2654435761UL) & IP_VS_LBLC_TAB_MASK;
}
static void
ip_vs_lblc_hash(struct ip_vs_lblc_table *tbl, struct ip_vs_lblc_entry *en)
{
unsigned int hash = ip_vs_lblc_hashkey(en->af, &en->addr);
hlist_add_head_rcu(&en->list, &tbl->bucket[hash]);
atomic_inc(&tbl->entries);
}
static inline struct ip_vs_lblc_entry *
ip_vs_lblc_get(int af, struct ip_vs_lblc_table *tbl,
const union nf_inet_addr *addr)
{
unsigned int hash = ip_vs_lblc_hashkey(af, addr);
struct ip_vs_lblc_entry *en;
hlist_for_each_entry_rcu(en, &tbl->bucket[hash], list)
if (ip_vs_addr_equal(af, &en->addr, addr))
return en;
return NULL;
}
static inline struct ip_vs_lblc_entry *
ip_vs_lblc_new(struct ip_vs_lblc_table *tbl, const union nf_inet_addr *daddr,
struct ip_vs_dest *dest)
{
struct ip_vs_lblc_entry *en;
en = ip_vs_lblc_get(dest->af, tbl, daddr);
if (en) {
if (en->dest == dest)
return en;
ip_vs_lblc_del(en);
}
en = kmalloc(sizeof(*en), GFP_ATOMIC);
if (!en)
return NULL;
en->af = dest->af;
ip_vs_addr_copy(dest->af, &en->addr, daddr);
en->lastuse = jiffies;
ip_vs_dest_hold(dest);
en->dest = dest;
ip_vs_lblc_hash(tbl, en);
return en;
}
static void ip_vs_lblc_flush(struct ip_vs_service *svc)
{
struct ip_vs_lblc_table *tbl = svc->sched_data;
struct ip_vs_lblc_entry *en;
struct hlist_node *next;
int i;
spin_lock_bh(&svc->sched_lock);
tbl->dead = 1;
for (i = 0; i < IP_VS_LBLC_TAB_SIZE; i++) {
hlist_for_each_entry_safe(en, next, &tbl->bucket[i], list) {
ip_vs_lblc_del(en);
atomic_dec(&tbl->entries);
}
}
spin_unlock_bh(&svc->sched_lock);
}
static int sysctl_lblc_expiration(struct ip_vs_service *svc)
{
#ifdef CONFIG_SYSCTL
struct netns_ipvs *ipvs = net_ipvs(svc->net);
return ipvs->sysctl_lblc_expiration;
#else
return DEFAULT_EXPIRATION;
#endif
}
static inline void ip_vs_lblc_full_check(struct ip_vs_service *svc)
{
struct ip_vs_lblc_table *tbl = svc->sched_data;
struct ip_vs_lblc_entry *en;
struct hlist_node *next;
unsigned long now = jiffies;
int i, j;
for (i = 0, j = tbl->rover; i < IP_VS_LBLC_TAB_SIZE; i++) {
j = (j + 1) & IP_VS_LBLC_TAB_MASK;
spin_lock(&svc->sched_lock);
hlist_for_each_entry_safe(en, next, &tbl->bucket[j], list) {
if (time_before(now,
en->lastuse +
sysctl_lblc_expiration(svc)))
continue;
ip_vs_lblc_del(en);
atomic_dec(&tbl->entries);
}
spin_unlock(&svc->sched_lock);
}
tbl->rover = j;
}
static void ip_vs_lblc_check_expire(unsigned long data)
{
struct ip_vs_service *svc = (struct ip_vs_service *) data;
struct ip_vs_lblc_table *tbl = svc->sched_data;
unsigned long now = jiffies;
int goal;
int i, j;
struct ip_vs_lblc_entry *en;
struct hlist_node *next;
if ((tbl->counter % COUNT_FOR_FULL_EXPIRATION) == 0) {
ip_vs_lblc_full_check(svc);
tbl->counter = 1;
goto out;
}
if (atomic_read(&tbl->entries) <= tbl->max_size) {
tbl->counter++;
goto out;
}
goal = (atomic_read(&tbl->entries) - tbl->max_size)*4/3;
if (goal > tbl->max_size/2)
goal = tbl->max_size/2;
for (i = 0, j = tbl->rover; i < IP_VS_LBLC_TAB_SIZE; i++) {
j = (j + 1) & IP_VS_LBLC_TAB_MASK;
spin_lock(&svc->sched_lock);
hlist_for_each_entry_safe(en, next, &tbl->bucket[j], list) {
if (time_before(now, en->lastuse + ENTRY_TIMEOUT))
continue;
ip_vs_lblc_del(en);
atomic_dec(&tbl->entries);
goal--;
}
spin_unlock(&svc->sched_lock);
if (goal <= 0)
break;
}
tbl->rover = j;
out:
mod_timer(&tbl->periodic_timer, jiffies + CHECK_EXPIRE_INTERVAL);
}
static int ip_vs_lblc_init_svc(struct ip_vs_service *svc)
{
int i;
struct ip_vs_lblc_table *tbl;
tbl = kmalloc(sizeof(*tbl), GFP_KERNEL);
if (tbl == NULL)
return -ENOMEM;
svc->sched_data = tbl;
IP_VS_DBG(6, "LBLC hash table (memory=%Zdbytes) allocated for "
"current service\n", sizeof(*tbl));
for (i = 0; i < IP_VS_LBLC_TAB_SIZE; i++) {
INIT_HLIST_HEAD(&tbl->bucket[i]);
}
tbl->max_size = IP_VS_LBLC_TAB_SIZE*16;
tbl->rover = 0;
tbl->counter = 1;
tbl->dead = 0;
setup_timer(&tbl->periodic_timer, ip_vs_lblc_check_expire,
(unsigned long)svc);
mod_timer(&tbl->periodic_timer, jiffies + CHECK_EXPIRE_INTERVAL);
return 0;
}
static void ip_vs_lblc_done_svc(struct ip_vs_service *svc)
{
struct ip_vs_lblc_table *tbl = svc->sched_data;
del_timer_sync(&tbl->periodic_timer);
ip_vs_lblc_flush(svc);
kfree_rcu(tbl, rcu_head);
IP_VS_DBG(6, "LBLC hash table (memory=%Zdbytes) released\n",
sizeof(*tbl));
}
static inline struct ip_vs_dest *
__ip_vs_lblc_schedule(struct ip_vs_service *svc)
{
struct ip_vs_dest *dest, *least;
int loh, doh;
list_for_each_entry_rcu(dest, &svc->destinations, n_list) {
if (dest->flags & IP_VS_DEST_F_OVERLOAD)
continue;
if (atomic_read(&dest->weight) > 0) {
least = dest;
loh = ip_vs_dest_conn_overhead(least);
goto nextstage;
}
}
return NULL;
nextstage:
list_for_each_entry_continue_rcu(dest, &svc->destinations, n_list) {
if (dest->flags & IP_VS_DEST_F_OVERLOAD)
continue;
doh = ip_vs_dest_conn_overhead(dest);
if ((__s64)loh * atomic_read(&dest->weight) >
(__s64)doh * atomic_read(&least->weight)) {
least = dest;
loh = doh;
}
}
IP_VS_DBG_BUF(6, "LBLC: server %s:%d "
"activeconns %d refcnt %d weight %d overhead %d\n",
IP_VS_DBG_ADDR(least->af, &least->addr),
ntohs(least->port),
atomic_read(&least->activeconns),
atomic_read(&least->refcnt),
atomic_read(&least->weight), loh);
return least;
}
static inline int
is_overloaded(struct ip_vs_dest *dest, struct ip_vs_service *svc)
{
if (atomic_read(&dest->activeconns) > atomic_read(&dest->weight)) {
struct ip_vs_dest *d;
list_for_each_entry_rcu(d, &svc->destinations, n_list) {
if (atomic_read(&d->activeconns)*2
< atomic_read(&d->weight)) {
return 1;
}
}
}
return 0;
}
static struct ip_vs_dest *
ip_vs_lblc_schedule(struct ip_vs_service *svc, const struct sk_buff *skb,
struct ip_vs_iphdr *iph)
{
struct ip_vs_lblc_table *tbl = svc->sched_data;
struct ip_vs_dest *dest = NULL;
struct ip_vs_lblc_entry *en;
IP_VS_DBG(6, "%s(): Scheduling...\n", __func__);
en = ip_vs_lblc_get(svc->af, tbl, &iph->daddr);
if (en) {
en->lastuse = jiffies;
dest = en->dest;
if ((dest->flags & IP_VS_DEST_F_AVAILABLE) &&
atomic_read(&dest->weight) > 0 && !is_overloaded(dest, svc))
goto out;
}
dest = __ip_vs_lblc_schedule(svc);
if (!dest) {
ip_vs_scheduler_err(svc, "no destination available");
return NULL;
}
spin_lock_bh(&svc->sched_lock);
if (!tbl->dead)
ip_vs_lblc_new(tbl, &iph->daddr, dest);
spin_unlock_bh(&svc->sched_lock);
out:
IP_VS_DBG_BUF(6, "LBLC: destination IP address %s --> server %s:%d\n",
IP_VS_DBG_ADDR(svc->af, &iph->daddr),
IP_VS_DBG_ADDR(svc->af, &dest->addr), ntohs(dest->port));
return dest;
}
static int __net_init __ip_vs_lblc_init(struct net *net)
{
struct netns_ipvs *ipvs = net_ipvs(net);
if (!ipvs)
return -ENOENT;
if (!net_eq(net, &init_net)) {
ipvs->lblc_ctl_table = kmemdup(vs_vars_table,
sizeof(vs_vars_table),
GFP_KERNEL);
if (ipvs->lblc_ctl_table == NULL)
return -ENOMEM;
if (net->user_ns != &init_user_ns)
ipvs->lblc_ctl_table[0].procname = NULL;
} else
ipvs->lblc_ctl_table = vs_vars_table;
ipvs->sysctl_lblc_expiration = DEFAULT_EXPIRATION;
ipvs->lblc_ctl_table[0].data = &ipvs->sysctl_lblc_expiration;
ipvs->lblc_ctl_header =
register_net_sysctl(net, "net/ipv4/vs", ipvs->lblc_ctl_table);
if (!ipvs->lblc_ctl_header) {
if (!net_eq(net, &init_net))
kfree(ipvs->lblc_ctl_table);
return -ENOMEM;
}
return 0;
}
static void __net_exit __ip_vs_lblc_exit(struct net *net)
{
struct netns_ipvs *ipvs = net_ipvs(net);
unregister_net_sysctl_table(ipvs->lblc_ctl_header);
if (!net_eq(net, &init_net))
kfree(ipvs->lblc_ctl_table);
}
static int __net_init __ip_vs_lblc_init(struct net *net) { return 0; }
static void __net_exit __ip_vs_lblc_exit(struct net *net) { }
static int __init ip_vs_lblc_init(void)
{
int ret;
ret = register_pernet_subsys(&ip_vs_lblc_ops);
if (ret)
return ret;
ret = register_ip_vs_scheduler(&ip_vs_lblc_scheduler);
if (ret)
unregister_pernet_subsys(&ip_vs_lblc_ops);
return ret;
}
static void __exit ip_vs_lblc_cleanup(void)
{
unregister_ip_vs_scheduler(&ip_vs_lblc_scheduler);
unregister_pernet_subsys(&ip_vs_lblc_ops);
rcu_barrier();
}
