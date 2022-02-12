static struct ip_vs_dest *
ip_vs_fo_schedule(struct ip_vs_service *svc, const struct sk_buff *skb,
struct ip_vs_iphdr *iph)
{
struct ip_vs_dest *dest, *hweight = NULL;
int hw = 0;
IP_VS_DBG(6, "ip_vs_fo_schedule(): Scheduling...\n");
list_for_each_entry_rcu(dest, &svc->destinations, n_list) {
if (!(dest->flags & IP_VS_DEST_F_OVERLOAD) &&
atomic_read(&dest->weight) > hw) {
hweight = dest;
hw = atomic_read(&dest->weight);
}
}
if (hweight) {
IP_VS_DBG_BUF(6, "FO: server %s:%u activeconns %d weight %d\n",
IP_VS_DBG_ADDR(hweight->af, &hweight->addr),
ntohs(hweight->port),
atomic_read(&hweight->activeconns),
atomic_read(&hweight->weight));
return hweight;
}
ip_vs_scheduler_err(svc, "no destination available");
return NULL;
}
static int __init ip_vs_fo_init(void)
{
return register_ip_vs_scheduler(&ip_vs_fo_scheduler);
}
static void __exit ip_vs_fo_cleanup(void)
{
unregister_ip_vs_scheduler(&ip_vs_fo_scheduler);
synchronize_rcu();
}
