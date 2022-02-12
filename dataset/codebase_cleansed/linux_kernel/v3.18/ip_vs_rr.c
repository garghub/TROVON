static int ip_vs_rr_init_svc(struct ip_vs_service *svc)
{
svc->sched_data = &svc->destinations;
return 0;
}
static int ip_vs_rr_del_dest(struct ip_vs_service *svc, struct ip_vs_dest *dest)
{
struct list_head *p;
spin_lock_bh(&svc->sched_lock);
p = (struct list_head *) svc->sched_data;
if (p == &dest->n_list)
svc->sched_data = p->next->prev;
spin_unlock_bh(&svc->sched_lock);
return 0;
}
static struct ip_vs_dest *
ip_vs_rr_schedule(struct ip_vs_service *svc, const struct sk_buff *skb,
struct ip_vs_iphdr *iph)
{
struct list_head *p;
struct ip_vs_dest *dest, *last;
int pass = 0;
IP_VS_DBG(6, "%s(): Scheduling...\n", __func__);
spin_lock_bh(&svc->sched_lock);
p = (struct list_head *) svc->sched_data;
last = dest = list_entry(p, struct ip_vs_dest, n_list);
do {
list_for_each_entry_continue_rcu(dest,
&svc->destinations,
n_list) {
if (!(dest->flags & IP_VS_DEST_F_OVERLOAD) &&
atomic_read(&dest->weight) > 0)
goto out;
if (dest == last)
goto stop;
}
pass++;
} while (pass < 2 && p != &svc->destinations);
stop:
spin_unlock_bh(&svc->sched_lock);
ip_vs_scheduler_err(svc, "no destination available");
return NULL;
out:
svc->sched_data = &dest->n_list;
spin_unlock_bh(&svc->sched_lock);
IP_VS_DBG_BUF(6, "RR: server %s:%u "
"activeconns %d refcnt %d weight %d\n",
IP_VS_DBG_ADDR(dest->af, &dest->addr), ntohs(dest->port),
atomic_read(&dest->activeconns),
atomic_read(&dest->refcnt), atomic_read(&dest->weight));
return dest;
}
static int __init ip_vs_rr_init(void)
{
return register_ip_vs_scheduler(&ip_vs_rr_scheduler);
}
static void __exit ip_vs_rr_cleanup(void)
{
unregister_ip_vs_scheduler(&ip_vs_rr_scheduler);
synchronize_rcu();
}
