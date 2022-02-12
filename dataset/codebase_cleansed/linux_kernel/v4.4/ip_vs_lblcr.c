static void ip_vs_dest_set_insert(struct ip_vs_dest_set *set,
struct ip_vs_dest *dest, bool check)
{
struct ip_vs_dest_set_elem *e;
if (check) {
list_for_each_entry(e, &set->list, list) {
if (e->dest == dest)
return;
}
}
e = kmalloc(sizeof(*e), GFP_ATOMIC);
if (e == NULL)
return;
ip_vs_dest_hold(dest);
e->dest = dest;
list_add_rcu(&e->list, &set->list);
atomic_inc(&set->size);
set->lastmod = jiffies;
}
static void ip_vs_lblcr_elem_rcu_free(struct rcu_head *head)
{
struct ip_vs_dest_set_elem *e;
e = container_of(head, struct ip_vs_dest_set_elem, rcu_head);
ip_vs_dest_put_and_free(e->dest);
kfree(e);
}
static void
ip_vs_dest_set_erase(struct ip_vs_dest_set *set, struct ip_vs_dest *dest)
{
struct ip_vs_dest_set_elem *e;
list_for_each_entry(e, &set->list, list) {
if (e->dest == dest) {
atomic_dec(&set->size);
set->lastmod = jiffies;
list_del_rcu(&e->list);
call_rcu(&e->rcu_head, ip_vs_lblcr_elem_rcu_free);
break;
}
}
}
static void ip_vs_dest_set_eraseall(struct ip_vs_dest_set *set)
{
struct ip_vs_dest_set_elem *e, *ep;
list_for_each_entry_safe(e, ep, &set->list, list) {
list_del_rcu(&e->list);
call_rcu(&e->rcu_head, ip_vs_lblcr_elem_rcu_free);
}
}
static inline struct ip_vs_dest *ip_vs_dest_set_min(struct ip_vs_dest_set *set)
{
register struct ip_vs_dest_set_elem *e;
struct ip_vs_dest *dest, *least;
int loh, doh;
list_for_each_entry_rcu(e, &set->list, list) {
least = e->dest;
if (least->flags & IP_VS_DEST_F_OVERLOAD)
continue;
if ((atomic_read(&least->weight) > 0)
&& (least->flags & IP_VS_DEST_F_AVAILABLE)) {
loh = ip_vs_dest_conn_overhead(least);
goto nextstage;
}
}
return NULL;
nextstage:
list_for_each_entry_continue_rcu(e, &set->list, list) {
dest = e->dest;
if (dest->flags & IP_VS_DEST_F_OVERLOAD)
continue;
doh = ip_vs_dest_conn_overhead(dest);
if (((__s64)loh * atomic_read(&dest->weight) >
(__s64)doh * atomic_read(&least->weight))
&& (dest->flags & IP_VS_DEST_F_AVAILABLE)) {
least = dest;
loh = doh;
}
}
IP_VS_DBG_BUF(6, "%s(): server %s:%d "
"activeconns %d refcnt %d weight %d overhead %d\n",
__func__,
IP_VS_DBG_ADDR(least->af, &least->addr),
ntohs(least->port),
atomic_read(&least->activeconns),
atomic_read(&least->refcnt),
atomic_read(&least->weight), loh);
return least;
}
static inline struct ip_vs_dest *ip_vs_dest_set_max(struct ip_vs_dest_set *set)
{
register struct ip_vs_dest_set_elem *e;
struct ip_vs_dest *dest, *most;
int moh, doh;
if (set == NULL)
return NULL;
list_for_each_entry(e, &set->list, list) {
most = e->dest;
if (atomic_read(&most->weight) > 0) {
moh = ip_vs_dest_conn_overhead(most);
goto nextstage;
}
}
return NULL;
nextstage:
list_for_each_entry_continue(e, &set->list, list) {
dest = e->dest;
doh = ip_vs_dest_conn_overhead(dest);
if (((__s64)moh * atomic_read(&dest->weight) <
(__s64)doh * atomic_read(&most->weight))
&& (atomic_read(&dest->weight) > 0)) {
most = dest;
moh = doh;
}
}
IP_VS_DBG_BUF(6, "%s(): server %s:%d "
"activeconns %d refcnt %d weight %d overhead %d\n",
__func__,
IP_VS_DBG_ADDR(most->af, &most->addr), ntohs(most->port),
atomic_read(&most->activeconns),
atomic_read(&most->refcnt),
atomic_read(&most->weight), moh);
return most;
}
static inline void ip_vs_lblcr_free(struct ip_vs_lblcr_entry *en)
{
hlist_del_rcu(&en->list);
ip_vs_dest_set_eraseall(&en->set);
kfree_rcu(en, rcu_head);
}
static inline unsigned int
ip_vs_lblcr_hashkey(int af, const union nf_inet_addr *addr)
{
__be32 addr_fold = addr->ip;
#ifdef CONFIG_IP_VS_IPV6
if (af == AF_INET6)
addr_fold = addr->ip6[0]^addr->ip6[1]^
addr->ip6[2]^addr->ip6[3];
#endif
return (ntohl(addr_fold)*2654435761UL) & IP_VS_LBLCR_TAB_MASK;
}
static void
ip_vs_lblcr_hash(struct ip_vs_lblcr_table *tbl, struct ip_vs_lblcr_entry *en)
{
unsigned int hash = ip_vs_lblcr_hashkey(en->af, &en->addr);
hlist_add_head_rcu(&en->list, &tbl->bucket[hash]);
atomic_inc(&tbl->entries);
}
static inline struct ip_vs_lblcr_entry *
ip_vs_lblcr_get(int af, struct ip_vs_lblcr_table *tbl,
const union nf_inet_addr *addr)
{
unsigned int hash = ip_vs_lblcr_hashkey(af, addr);
struct ip_vs_lblcr_entry *en;
hlist_for_each_entry_rcu(en, &tbl->bucket[hash], list)
if (ip_vs_addr_equal(af, &en->addr, addr))
return en;
return NULL;
}
static inline struct ip_vs_lblcr_entry *
ip_vs_lblcr_new(struct ip_vs_lblcr_table *tbl, const union nf_inet_addr *daddr,
u16 af, struct ip_vs_dest *dest)
{
struct ip_vs_lblcr_entry *en;
en = ip_vs_lblcr_get(af, tbl, daddr);
if (!en) {
en = kmalloc(sizeof(*en), GFP_ATOMIC);
if (!en)
return NULL;
en->af = af;
ip_vs_addr_copy(af, &en->addr, daddr);
en->lastuse = jiffies;
atomic_set(&(en->set.size), 0);
INIT_LIST_HEAD(&en->set.list);
ip_vs_dest_set_insert(&en->set, dest, false);
ip_vs_lblcr_hash(tbl, en);
return en;
}
ip_vs_dest_set_insert(&en->set, dest, true);
return en;
}
static void ip_vs_lblcr_flush(struct ip_vs_service *svc)
{
struct ip_vs_lblcr_table *tbl = svc->sched_data;
int i;
struct ip_vs_lblcr_entry *en;
struct hlist_node *next;
spin_lock_bh(&svc->sched_lock);
tbl->dead = 1;
for (i = 0; i < IP_VS_LBLCR_TAB_SIZE; i++) {
hlist_for_each_entry_safe(en, next, &tbl->bucket[i], list) {
ip_vs_lblcr_free(en);
}
}
spin_unlock_bh(&svc->sched_lock);
}
static int sysctl_lblcr_expiration(struct ip_vs_service *svc)
{
#ifdef CONFIG_SYSCTL
return svc->ipvs->sysctl_lblcr_expiration;
#else
return DEFAULT_EXPIRATION;
#endif
}
static inline void ip_vs_lblcr_full_check(struct ip_vs_service *svc)
{
struct ip_vs_lblcr_table *tbl = svc->sched_data;
unsigned long now = jiffies;
int i, j;
struct ip_vs_lblcr_entry *en;
struct hlist_node *next;
for (i = 0, j = tbl->rover; i < IP_VS_LBLCR_TAB_SIZE; i++) {
j = (j + 1) & IP_VS_LBLCR_TAB_MASK;
spin_lock(&svc->sched_lock);
hlist_for_each_entry_safe(en, next, &tbl->bucket[j], list) {
if (time_after(en->lastuse +
sysctl_lblcr_expiration(svc), now))
continue;
ip_vs_lblcr_free(en);
atomic_dec(&tbl->entries);
}
spin_unlock(&svc->sched_lock);
}
tbl->rover = j;
}
static void ip_vs_lblcr_check_expire(unsigned long data)
{
struct ip_vs_service *svc = (struct ip_vs_service *) data;
struct ip_vs_lblcr_table *tbl = svc->sched_data;
unsigned long now = jiffies;
int goal;
int i, j;
struct ip_vs_lblcr_entry *en;
struct hlist_node *next;
if ((tbl->counter % COUNT_FOR_FULL_EXPIRATION) == 0) {
ip_vs_lblcr_full_check(svc);
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
for (i = 0, j = tbl->rover; i < IP_VS_LBLCR_TAB_SIZE; i++) {
j = (j + 1) & IP_VS_LBLCR_TAB_MASK;
spin_lock(&svc->sched_lock);
hlist_for_each_entry_safe(en, next, &tbl->bucket[j], list) {
if (time_before(now, en->lastuse+ENTRY_TIMEOUT))
continue;
ip_vs_lblcr_free(en);
atomic_dec(&tbl->entries);
goal--;
}
spin_unlock(&svc->sched_lock);
if (goal <= 0)
break;
}
tbl->rover = j;
out:
mod_timer(&tbl->periodic_timer, jiffies+CHECK_EXPIRE_INTERVAL);
}
static int ip_vs_lblcr_init_svc(struct ip_vs_service *svc)
{
int i;
struct ip_vs_lblcr_table *tbl;
tbl = kmalloc(sizeof(*tbl), GFP_KERNEL);
if (tbl == NULL)
return -ENOMEM;
svc->sched_data = tbl;
IP_VS_DBG(6, "LBLCR hash table (memory=%Zdbytes) allocated for "
"current service\n", sizeof(*tbl));
for (i = 0; i < IP_VS_LBLCR_TAB_SIZE; i++) {
INIT_HLIST_HEAD(&tbl->bucket[i]);
}
tbl->max_size = IP_VS_LBLCR_TAB_SIZE*16;
tbl->rover = 0;
tbl->counter = 1;
tbl->dead = 0;
setup_timer(&tbl->periodic_timer, ip_vs_lblcr_check_expire,
(unsigned long)svc);
mod_timer(&tbl->periodic_timer, jiffies + CHECK_EXPIRE_INTERVAL);
return 0;
}
static void ip_vs_lblcr_done_svc(struct ip_vs_service *svc)
{
struct ip_vs_lblcr_table *tbl = svc->sched_data;
del_timer_sync(&tbl->periodic_timer);
ip_vs_lblcr_flush(svc);
kfree_rcu(tbl, rcu_head);
IP_VS_DBG(6, "LBLCR hash table (memory=%Zdbytes) released\n",
sizeof(*tbl));
}
static inline struct ip_vs_dest *
__ip_vs_lblcr_schedule(struct ip_vs_service *svc)
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
IP_VS_DBG_BUF(6, "LBLCR: server %s:%d "
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
ip_vs_lblcr_schedule(struct ip_vs_service *svc, const struct sk_buff *skb,
struct ip_vs_iphdr *iph)
{
struct ip_vs_lblcr_table *tbl = svc->sched_data;
struct ip_vs_dest *dest;
struct ip_vs_lblcr_entry *en;
IP_VS_DBG(6, "%s(): Scheduling...\n", __func__);
en = ip_vs_lblcr_get(svc->af, tbl, &iph->daddr);
if (en) {
en->lastuse = jiffies;
dest = ip_vs_dest_set_min(&en->set);
if (atomic_read(&en->set.size) > 1 &&
time_after(jiffies, en->set.lastmod +
sysctl_lblcr_expiration(svc))) {
spin_lock_bh(&svc->sched_lock);
if (atomic_read(&en->set.size) > 1) {
struct ip_vs_dest *m;
m = ip_vs_dest_set_max(&en->set);
if (m)
ip_vs_dest_set_erase(&en->set, m);
}
spin_unlock_bh(&svc->sched_lock);
}
if (dest && !is_overloaded(dest, svc))
goto out;
dest = __ip_vs_lblcr_schedule(svc);
if (!dest) {
ip_vs_scheduler_err(svc, "no destination available");
return NULL;
}
spin_lock_bh(&svc->sched_lock);
if (!tbl->dead)
ip_vs_dest_set_insert(&en->set, dest, true);
spin_unlock_bh(&svc->sched_lock);
goto out;
}
dest = __ip_vs_lblcr_schedule(svc);
if (!dest) {
IP_VS_DBG(1, "no destination available\n");
return NULL;
}
spin_lock_bh(&svc->sched_lock);
if (!tbl->dead)
ip_vs_lblcr_new(tbl, &iph->daddr, svc->af, dest);
spin_unlock_bh(&svc->sched_lock);
out:
IP_VS_DBG_BUF(6, "LBLCR: destination IP address %s --> server %s:%d\n",
IP_VS_DBG_ADDR(svc->af, &iph->daddr),
IP_VS_DBG_ADDR(dest->af, &dest->addr), ntohs(dest->port));
return dest;
}
static int __net_init __ip_vs_lblcr_init(struct net *net)
{
struct netns_ipvs *ipvs = net_ipvs(net);
if (!ipvs)
return -ENOENT;
if (!net_eq(net, &init_net)) {
ipvs->lblcr_ctl_table = kmemdup(vs_vars_table,
sizeof(vs_vars_table),
GFP_KERNEL);
if (ipvs->lblcr_ctl_table == NULL)
return -ENOMEM;
if (net->user_ns != &init_user_ns)
ipvs->lblcr_ctl_table[0].procname = NULL;
} else
ipvs->lblcr_ctl_table = vs_vars_table;
ipvs->sysctl_lblcr_expiration = DEFAULT_EXPIRATION;
ipvs->lblcr_ctl_table[0].data = &ipvs->sysctl_lblcr_expiration;
ipvs->lblcr_ctl_header =
register_net_sysctl(net, "net/ipv4/vs", ipvs->lblcr_ctl_table);
if (!ipvs->lblcr_ctl_header) {
if (!net_eq(net, &init_net))
kfree(ipvs->lblcr_ctl_table);
return -ENOMEM;
}
return 0;
}
static void __net_exit __ip_vs_lblcr_exit(struct net *net)
{
struct netns_ipvs *ipvs = net_ipvs(net);
unregister_net_sysctl_table(ipvs->lblcr_ctl_header);
if (!net_eq(net, &init_net))
kfree(ipvs->lblcr_ctl_table);
}
static int __net_init __ip_vs_lblcr_init(struct net *net) { return 0; }
static void __net_exit __ip_vs_lblcr_exit(struct net *net) { }
static int __init ip_vs_lblcr_init(void)
{
int ret;
ret = register_pernet_subsys(&ip_vs_lblcr_ops);
if (ret)
return ret;
ret = register_ip_vs_scheduler(&ip_vs_lblcr_scheduler);
if (ret)
unregister_pernet_subsys(&ip_vs_lblcr_ops);
return ret;
}
static void __exit ip_vs_lblcr_cleanup(void)
{
unregister_ip_vs_scheduler(&ip_vs_lblcr_scheduler);
unregister_pernet_subsys(&ip_vs_lblcr_ops);
rcu_barrier();
}
