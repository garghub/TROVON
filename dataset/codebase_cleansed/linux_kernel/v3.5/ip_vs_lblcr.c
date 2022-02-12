static struct ip_vs_dest_set_elem *
ip_vs_dest_set_insert(struct ip_vs_dest_set *set, struct ip_vs_dest *dest)
{
struct ip_vs_dest_set_elem *e;
list_for_each_entry(e, &set->list, list) {
if (e->dest == dest)
return NULL;
}
e = kmalloc(sizeof(*e), GFP_ATOMIC);
if (e == NULL)
return NULL;
atomic_inc(&dest->refcnt);
e->dest = dest;
list_add(&e->list, &set->list);
atomic_inc(&set->size);
set->lastmod = jiffies;
return e;
}
static void
ip_vs_dest_set_erase(struct ip_vs_dest_set *set, struct ip_vs_dest *dest)
{
struct ip_vs_dest_set_elem *e;
list_for_each_entry(e, &set->list, list) {
if (e->dest == dest) {
atomic_dec(&set->size);
set->lastmod = jiffies;
atomic_dec(&e->dest->refcnt);
list_del(&e->list);
kfree(e);
break;
}
}
}
static void ip_vs_dest_set_eraseall(struct ip_vs_dest_set *set)
{
struct ip_vs_dest_set_elem *e, *ep;
write_lock(&set->lock);
list_for_each_entry_safe(e, ep, &set->list, list) {
atomic_dec(&e->dest->refcnt);
list_del(&e->list);
kfree(e);
}
write_unlock(&set->lock);
}
static inline struct ip_vs_dest *ip_vs_dest_set_min(struct ip_vs_dest_set *set)
{
register struct ip_vs_dest_set_elem *e;
struct ip_vs_dest *dest, *least;
int loh, doh;
if (set == NULL)
return NULL;
list_for_each_entry(e, &set->list, list) {
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
list_for_each_entry(e, &set->list, list) {
dest = e->dest;
if (dest->flags & IP_VS_DEST_F_OVERLOAD)
continue;
doh = ip_vs_dest_conn_overhead(dest);
if ((loh * atomic_read(&dest->weight) >
doh * atomic_read(&least->weight))
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
list_for_each_entry(e, &set->list, list) {
dest = e->dest;
doh = ip_vs_dest_conn_overhead(dest);
if ((moh * atomic_read(&dest->weight) <
doh * atomic_read(&most->weight))
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
list_del(&en->list);
ip_vs_dest_set_eraseall(&en->set);
kfree(en);
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
list_add(&en->list, &tbl->bucket[hash]);
atomic_inc(&tbl->entries);
}
static inline struct ip_vs_lblcr_entry *
ip_vs_lblcr_get(int af, struct ip_vs_lblcr_table *tbl,
const union nf_inet_addr *addr)
{
unsigned int hash = ip_vs_lblcr_hashkey(af, addr);
struct ip_vs_lblcr_entry *en;
list_for_each_entry(en, &tbl->bucket[hash], list)
if (ip_vs_addr_equal(af, &en->addr, addr))
return en;
return NULL;
}
static inline struct ip_vs_lblcr_entry *
ip_vs_lblcr_new(struct ip_vs_lblcr_table *tbl, const union nf_inet_addr *daddr,
struct ip_vs_dest *dest)
{
struct ip_vs_lblcr_entry *en;
en = ip_vs_lblcr_get(dest->af, tbl, daddr);
if (!en) {
en = kmalloc(sizeof(*en), GFP_ATOMIC);
if (!en)
return NULL;
en->af = dest->af;
ip_vs_addr_copy(dest->af, &en->addr, daddr);
en->lastuse = jiffies;
atomic_set(&(en->set.size), 0);
INIT_LIST_HEAD(&en->set.list);
rwlock_init(&en->set.lock);
ip_vs_lblcr_hash(tbl, en);
}
write_lock(&en->set.lock);
ip_vs_dest_set_insert(&en->set, dest);
write_unlock(&en->set.lock);
return en;
}
static void ip_vs_lblcr_flush(struct ip_vs_lblcr_table *tbl)
{
int i;
struct ip_vs_lblcr_entry *en, *nxt;
for (i=0; i<IP_VS_LBLCR_TAB_SIZE; i++) {
list_for_each_entry_safe(en, nxt, &tbl->bucket[i], list) {
ip_vs_lblcr_free(en);
}
}
}
static int sysctl_lblcr_expiration(struct ip_vs_service *svc)
{
#ifdef CONFIG_SYSCTL
struct netns_ipvs *ipvs = net_ipvs(svc->net);
return ipvs->sysctl_lblcr_expiration;
#else
return DEFAULT_EXPIRATION;
#endif
}
static inline void ip_vs_lblcr_full_check(struct ip_vs_service *svc)
{
struct ip_vs_lblcr_table *tbl = svc->sched_data;
unsigned long now = jiffies;
int i, j;
struct ip_vs_lblcr_entry *en, *nxt;
for (i=0, j=tbl->rover; i<IP_VS_LBLCR_TAB_SIZE; i++) {
j = (j + 1) & IP_VS_LBLCR_TAB_MASK;
write_lock(&svc->sched_lock);
list_for_each_entry_safe(en, nxt, &tbl->bucket[j], list) {
if (time_after(en->lastuse +
sysctl_lblcr_expiration(svc), now))
continue;
ip_vs_lblcr_free(en);
atomic_dec(&tbl->entries);
}
write_unlock(&svc->sched_lock);
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
struct ip_vs_lblcr_entry *en, *nxt;
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
for (i=0, j=tbl->rover; i<IP_VS_LBLCR_TAB_SIZE; i++) {
j = (j + 1) & IP_VS_LBLCR_TAB_MASK;
write_lock(&svc->sched_lock);
list_for_each_entry_safe(en, nxt, &tbl->bucket[j], list) {
if (time_before(now, en->lastuse+ENTRY_TIMEOUT))
continue;
ip_vs_lblcr_free(en);
atomic_dec(&tbl->entries);
goal--;
}
write_unlock(&svc->sched_lock);
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
for (i=0; i<IP_VS_LBLCR_TAB_SIZE; i++) {
INIT_LIST_HEAD(&tbl->bucket[i]);
}
tbl->max_size = IP_VS_LBLCR_TAB_SIZE*16;
tbl->rover = 0;
tbl->counter = 1;
setup_timer(&tbl->periodic_timer, ip_vs_lblcr_check_expire,
(unsigned long)svc);
mod_timer(&tbl->periodic_timer, jiffies + CHECK_EXPIRE_INTERVAL);
return 0;
}
static int ip_vs_lblcr_done_svc(struct ip_vs_service *svc)
{
struct ip_vs_lblcr_table *tbl = svc->sched_data;
del_timer_sync(&tbl->periodic_timer);
ip_vs_lblcr_flush(tbl);
kfree(tbl);
IP_VS_DBG(6, "LBLCR hash table (memory=%Zdbytes) released\n",
sizeof(*tbl));
return 0;
}
static inline struct ip_vs_dest *
__ip_vs_lblcr_schedule(struct ip_vs_service *svc)
{
struct ip_vs_dest *dest, *least;
int loh, doh;
list_for_each_entry(dest, &svc->destinations, n_list) {
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
list_for_each_entry_continue(dest, &svc->destinations, n_list) {
if (dest->flags & IP_VS_DEST_F_OVERLOAD)
continue;
doh = ip_vs_dest_conn_overhead(dest);
if (loh * atomic_read(&dest->weight) >
doh * atomic_read(&least->weight)) {
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
list_for_each_entry(d, &svc->destinations, n_list) {
if (atomic_read(&d->activeconns)*2
< atomic_read(&d->weight)) {
return 1;
}
}
}
return 0;
}
static struct ip_vs_dest *
ip_vs_lblcr_schedule(struct ip_vs_service *svc, const struct sk_buff *skb)
{
struct ip_vs_lblcr_table *tbl = svc->sched_data;
struct ip_vs_iphdr iph;
struct ip_vs_dest *dest = NULL;
struct ip_vs_lblcr_entry *en;
ip_vs_fill_iphdr(svc->af, skb_network_header(skb), &iph);
IP_VS_DBG(6, "%s(): Scheduling...\n", __func__);
read_lock(&svc->sched_lock);
en = ip_vs_lblcr_get(svc->af, tbl, &iph.daddr);
if (en) {
en->lastuse = jiffies;
read_lock(&en->set.lock);
dest = ip_vs_dest_set_min(&en->set);
read_unlock(&en->set.lock);
if (atomic_read(&en->set.size) > 1 &&
time_after(jiffies, en->set.lastmod +
sysctl_lblcr_expiration(svc))) {
struct ip_vs_dest *m;
write_lock(&en->set.lock);
m = ip_vs_dest_set_max(&en->set);
if (m)
ip_vs_dest_set_erase(&en->set, m);
write_unlock(&en->set.lock);
}
if (dest && !is_overloaded(dest, svc)) {
read_unlock(&svc->sched_lock);
goto out;
}
dest = __ip_vs_lblcr_schedule(svc);
if (!dest) {
ip_vs_scheduler_err(svc, "no destination available");
read_unlock(&svc->sched_lock);
return NULL;
}
write_lock(&en->set.lock);
ip_vs_dest_set_insert(&en->set, dest);
write_unlock(&en->set.lock);
}
read_unlock(&svc->sched_lock);
if (dest)
goto out;
dest = __ip_vs_lblcr_schedule(svc);
if (!dest) {
IP_VS_DBG(1, "no destination available\n");
return NULL;
}
write_lock(&svc->sched_lock);
ip_vs_lblcr_new(tbl, &iph.daddr, dest);
write_unlock(&svc->sched_lock);
out:
IP_VS_DBG_BUF(6, "LBLCR: destination IP address %s --> server %s:%d\n",
IP_VS_DBG_ADDR(svc->af, &iph.daddr),
IP_VS_DBG_ADDR(svc->af, &dest->addr), ntohs(dest->port));
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
}
