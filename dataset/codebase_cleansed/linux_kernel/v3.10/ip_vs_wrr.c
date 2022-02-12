static int ip_vs_wrr_gcd_weight(struct ip_vs_service *svc)
{
struct ip_vs_dest *dest;
int weight;
int g = 0;
list_for_each_entry(dest, &svc->destinations, n_list) {
weight = atomic_read(&dest->weight);
if (weight > 0) {
if (g > 0)
g = gcd(weight, g);
else
g = weight;
}
}
return g ? g : 1;
}
static int ip_vs_wrr_max_weight(struct ip_vs_service *svc)
{
struct ip_vs_dest *dest;
int new_weight, weight = 0;
list_for_each_entry(dest, &svc->destinations, n_list) {
new_weight = atomic_read(&dest->weight);
if (new_weight > weight)
weight = new_weight;
}
return weight;
}
static int ip_vs_wrr_init_svc(struct ip_vs_service *svc)
{
struct ip_vs_wrr_mark *mark;
mark = kmalloc(sizeof(struct ip_vs_wrr_mark), GFP_KERNEL);
if (mark == NULL)
return -ENOMEM;
mark->cl = list_entry(&svc->destinations, struct ip_vs_dest, n_list);
mark->di = ip_vs_wrr_gcd_weight(svc);
mark->mw = ip_vs_wrr_max_weight(svc) - (mark->di - 1);
mark->cw = mark->mw;
svc->sched_data = mark;
return 0;
}
static void ip_vs_wrr_done_svc(struct ip_vs_service *svc)
{
struct ip_vs_wrr_mark *mark = svc->sched_data;
kfree_rcu(mark, rcu_head);
}
static int ip_vs_wrr_dest_changed(struct ip_vs_service *svc,
struct ip_vs_dest *dest)
{
struct ip_vs_wrr_mark *mark = svc->sched_data;
spin_lock_bh(&svc->sched_lock);
mark->cl = list_entry(&svc->destinations, struct ip_vs_dest, n_list);
mark->di = ip_vs_wrr_gcd_weight(svc);
mark->mw = ip_vs_wrr_max_weight(svc) - (mark->di - 1);
if (mark->cw > mark->mw || !mark->cw)
mark->cw = mark->mw;
else if (mark->di > 1)
mark->cw = (mark->cw / mark->di) * mark->di + 1;
spin_unlock_bh(&svc->sched_lock);
return 0;
}
static struct ip_vs_dest *
ip_vs_wrr_schedule(struct ip_vs_service *svc, const struct sk_buff *skb)
{
struct ip_vs_dest *dest, *last, *stop = NULL;
struct ip_vs_wrr_mark *mark = svc->sched_data;
bool last_pass = false, restarted = false;
IP_VS_DBG(6, "%s(): Scheduling...\n", __func__);
spin_lock_bh(&svc->sched_lock);
dest = mark->cl;
if (mark->mw == 0)
goto err_noavail;
last = dest;
while (1) {
list_for_each_entry_continue_rcu(dest,
&svc->destinations,
n_list) {
if (!(dest->flags & IP_VS_DEST_F_OVERLOAD) &&
atomic_read(&dest->weight) >= mark->cw)
goto found;
if (dest == stop)
goto err_over;
}
mark->cw -= mark->di;
if (mark->cw <= 0) {
mark->cw = mark->mw;
if (last_pass ||
&last->n_list == &svc->destinations)
goto err_over;
restarted = true;
}
last_pass = mark->cw <= mark->di;
if (last_pass && restarted &&
&last->n_list != &svc->destinations) {
stop = last;
}
}
found:
IP_VS_DBG_BUF(6, "WRR: server %s:%u "
"activeconns %d refcnt %d weight %d\n",
IP_VS_DBG_ADDR(svc->af, &dest->addr), ntohs(dest->port),
atomic_read(&dest->activeconns),
atomic_read(&dest->refcnt),
atomic_read(&dest->weight));
mark->cl = dest;
out:
spin_unlock_bh(&svc->sched_lock);
return dest;
err_noavail:
mark->cl = dest;
dest = NULL;
ip_vs_scheduler_err(svc, "no destination available");
goto out;
err_over:
mark->cl = dest;
dest = NULL;
ip_vs_scheduler_err(svc, "no destination available: "
"all destinations are overloaded");
goto out;
}
static int __init ip_vs_wrr_init(void)
{
return register_ip_vs_scheduler(&ip_vs_wrr_scheduler) ;
}
static void __exit ip_vs_wrr_cleanup(void)
{
unregister_ip_vs_scheduler(&ip_vs_wrr_scheduler);
synchronize_rcu();
}
