static int ip_vs_rr_init_svc(struct ip_vs_service *svc)
{
svc->sched_data = &svc->destinations;
return 0;
}
static int ip_vs_rr_update_svc(struct ip_vs_service *svc)
{
svc->sched_data = &svc->destinations;
return 0;
}
static struct ip_vs_dest *
ip_vs_rr_schedule(struct ip_vs_service *svc, const struct sk_buff *skb)
{
struct list_head *p, *q;
struct ip_vs_dest *dest;
IP_VS_DBG(6, "%s(): Scheduling...\n", __func__);
write_lock(&svc->sched_lock);
p = (struct list_head *)svc->sched_data;
p = p->next;
q = p;
do {
if (q == &svc->destinations) {
q = q->next;
continue;
}
dest = list_entry(q, struct ip_vs_dest, n_list);
if (!(dest->flags & IP_VS_DEST_F_OVERLOAD) &&
atomic_read(&dest->weight) > 0)
goto out;
q = q->next;
} while (q != p);
write_unlock(&svc->sched_lock);
ip_vs_scheduler_err(svc, "no destination available");
return NULL;
out:
svc->sched_data = q;
write_unlock(&svc->sched_lock);
IP_VS_DBG_BUF(6, "RR: server %s:%u "
"activeconns %d refcnt %d weight %d\n",
IP_VS_DBG_ADDR(svc->af, &dest->addr), ntohs(dest->port),
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
}
