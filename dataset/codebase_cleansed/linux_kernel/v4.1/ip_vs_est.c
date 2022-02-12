static void ip_vs_read_cpu_stats(struct ip_vs_kstats *sum,
struct ip_vs_cpu_stats __percpu *stats)
{
int i;
bool add = false;
for_each_possible_cpu(i) {
struct ip_vs_cpu_stats *s = per_cpu_ptr(stats, i);
unsigned int start;
u64 conns, inpkts, outpkts, inbytes, outbytes;
if (add) {
do {
start = u64_stats_fetch_begin(&s->syncp);
conns = s->cnt.conns;
inpkts = s->cnt.inpkts;
outpkts = s->cnt.outpkts;
inbytes = s->cnt.inbytes;
outbytes = s->cnt.outbytes;
} while (u64_stats_fetch_retry(&s->syncp, start));
sum->conns += conns;
sum->inpkts += inpkts;
sum->outpkts += outpkts;
sum->inbytes += inbytes;
sum->outbytes += outbytes;
} else {
add = true;
do {
start = u64_stats_fetch_begin(&s->syncp);
sum->conns = s->cnt.conns;
sum->inpkts = s->cnt.inpkts;
sum->outpkts = s->cnt.outpkts;
sum->inbytes = s->cnt.inbytes;
sum->outbytes = s->cnt.outbytes;
} while (u64_stats_fetch_retry(&s->syncp, start));
}
}
}
static void estimation_timer(unsigned long arg)
{
struct ip_vs_estimator *e;
struct ip_vs_stats *s;
u64 rate;
struct net *net = (struct net *)arg;
struct netns_ipvs *ipvs;
ipvs = net_ipvs(net);
spin_lock(&ipvs->est_lock);
list_for_each_entry(e, &ipvs->est_list, list) {
s = container_of(e, struct ip_vs_stats, est);
spin_lock(&s->lock);
ip_vs_read_cpu_stats(&s->kstats, s->cpustats);
rate = (s->kstats.conns - e->last_conns) << 9;
e->last_conns = s->kstats.conns;
e->cps += ((s64)rate - (s64)e->cps) >> 2;
rate = (s->kstats.inpkts - e->last_inpkts) << 9;
e->last_inpkts = s->kstats.inpkts;
e->inpps += ((s64)rate - (s64)e->inpps) >> 2;
rate = (s->kstats.outpkts - e->last_outpkts) << 9;
e->last_outpkts = s->kstats.outpkts;
e->outpps += ((s64)rate - (s64)e->outpps) >> 2;
rate = (s->kstats.inbytes - e->last_inbytes) << 4;
e->last_inbytes = s->kstats.inbytes;
e->inbps += ((s64)rate - (s64)e->inbps) >> 2;
rate = (s->kstats.outbytes - e->last_outbytes) << 4;
e->last_outbytes = s->kstats.outbytes;
e->outbps += ((s64)rate - (s64)e->outbps) >> 2;
spin_unlock(&s->lock);
}
spin_unlock(&ipvs->est_lock);
mod_timer(&ipvs->est_timer, jiffies + 2*HZ);
}
void ip_vs_start_estimator(struct net *net, struct ip_vs_stats *stats)
{
struct netns_ipvs *ipvs = net_ipvs(net);
struct ip_vs_estimator *est = &stats->est;
INIT_LIST_HEAD(&est->list);
spin_lock_bh(&ipvs->est_lock);
list_add(&est->list, &ipvs->est_list);
spin_unlock_bh(&ipvs->est_lock);
}
void ip_vs_stop_estimator(struct net *net, struct ip_vs_stats *stats)
{
struct netns_ipvs *ipvs = net_ipvs(net);
struct ip_vs_estimator *est = &stats->est;
spin_lock_bh(&ipvs->est_lock);
list_del(&est->list);
spin_unlock_bh(&ipvs->est_lock);
}
void ip_vs_zero_estimator(struct ip_vs_stats *stats)
{
struct ip_vs_estimator *est = &stats->est;
struct ip_vs_kstats *k = &stats->kstats;
est->last_inbytes = k->inbytes;
est->last_outbytes = k->outbytes;
est->last_conns = k->conns;
est->last_inpkts = k->inpkts;
est->last_outpkts = k->outpkts;
est->cps = 0;
est->inpps = 0;
est->outpps = 0;
est->inbps = 0;
est->outbps = 0;
}
void ip_vs_read_estimator(struct ip_vs_kstats *dst, struct ip_vs_stats *stats)
{
struct ip_vs_estimator *e = &stats->est;
dst->cps = (e->cps + 0x1FF) >> 10;
dst->inpps = (e->inpps + 0x1FF) >> 10;
dst->outpps = (e->outpps + 0x1FF) >> 10;
dst->inbps = (e->inbps + 0xF) >> 5;
dst->outbps = (e->outbps + 0xF) >> 5;
}
int __net_init ip_vs_estimator_net_init(struct net *net)
{
struct netns_ipvs *ipvs = net_ipvs(net);
INIT_LIST_HEAD(&ipvs->est_list);
spin_lock_init(&ipvs->est_lock);
setup_timer(&ipvs->est_timer, estimation_timer, (unsigned long)net);
mod_timer(&ipvs->est_timer, jiffies + 2 * HZ);
return 0;
}
void __net_exit ip_vs_estimator_net_cleanup(struct net *net)
{
del_timer_sync(&net_ipvs(net)->est_timer);
}
