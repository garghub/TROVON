static inline int ip_vs_app_get(struct ip_vs_app *app)
{
return try_module_get(app->module);
}
static inline void ip_vs_app_put(struct ip_vs_app *app)
{
module_put(app->module);
}
static int
ip_vs_app_inc_new(struct net *net, struct ip_vs_app *app, __u16 proto,
__u16 port)
{
struct ip_vs_protocol *pp;
struct ip_vs_app *inc;
int ret;
if (!(pp = ip_vs_proto_get(proto)))
return -EPROTONOSUPPORT;
if (!pp->unregister_app)
return -EOPNOTSUPP;
inc = kmemdup(app, sizeof(*inc), GFP_KERNEL);
if (!inc)
return -ENOMEM;
INIT_LIST_HEAD(&inc->p_list);
INIT_LIST_HEAD(&inc->incs_list);
inc->app = app;
inc->port = htons(port);
atomic_set(&inc->usecnt, 0);
if (app->timeouts) {
inc->timeout_table =
ip_vs_create_timeout_table(app->timeouts,
app->timeouts_size);
if (!inc->timeout_table) {
ret = -ENOMEM;
goto out;
}
}
ret = pp->register_app(net, inc);
if (ret)
goto out;
list_add(&inc->a_list, &app->incs_list);
IP_VS_DBG(9, "%s App %s:%u registered\n",
pp->name, inc->name, ntohs(inc->port));
return 0;
out:
kfree(inc->timeout_table);
kfree(inc);
return ret;
}
static void
ip_vs_app_inc_release(struct net *net, struct ip_vs_app *inc)
{
struct ip_vs_protocol *pp;
if (!(pp = ip_vs_proto_get(inc->protocol)))
return;
if (pp->unregister_app)
pp->unregister_app(net, inc);
IP_VS_DBG(9, "%s App %s:%u unregistered\n",
pp->name, inc->name, ntohs(inc->port));
list_del(&inc->a_list);
kfree(inc->timeout_table);
kfree(inc);
}
int ip_vs_app_inc_get(struct ip_vs_app *inc)
{
int result;
atomic_inc(&inc->usecnt);
if (unlikely((result = ip_vs_app_get(inc->app)) != 1))
atomic_dec(&inc->usecnt);
return result;
}
void ip_vs_app_inc_put(struct ip_vs_app *inc)
{
ip_vs_app_put(inc->app);
atomic_dec(&inc->usecnt);
}
int
register_ip_vs_app_inc(struct net *net, struct ip_vs_app *app, __u16 proto,
__u16 port)
{
int result;
mutex_lock(&__ip_vs_app_mutex);
result = ip_vs_app_inc_new(net, app, proto, port);
mutex_unlock(&__ip_vs_app_mutex);
return result;
}
int register_ip_vs_app(struct net *net, struct ip_vs_app *app)
{
struct netns_ipvs *ipvs = net_ipvs(net);
ip_vs_use_count_inc();
mutex_lock(&__ip_vs_app_mutex);
list_add(&app->a_list, &ipvs->app_list);
mutex_unlock(&__ip_vs_app_mutex);
return 0;
}
void unregister_ip_vs_app(struct net *net, struct ip_vs_app *app)
{
struct ip_vs_app *inc, *nxt;
mutex_lock(&__ip_vs_app_mutex);
list_for_each_entry_safe(inc, nxt, &app->incs_list, a_list) {
ip_vs_app_inc_release(net, inc);
}
list_del(&app->a_list);
mutex_unlock(&__ip_vs_app_mutex);
ip_vs_use_count_dec();
}
int ip_vs_bind_app(struct ip_vs_conn *cp,
struct ip_vs_protocol *pp)
{
return pp->app_conn_bind(cp);
}
void ip_vs_unbind_app(struct ip_vs_conn *cp)
{
struct ip_vs_app *inc = cp->app;
if (!inc)
return;
if (inc->unbind_conn)
inc->unbind_conn(inc, cp);
if (inc->done_conn)
inc->done_conn(inc, cp);
ip_vs_app_inc_put(inc);
cp->app = NULL;
}
static inline void vs_fix_seq(const struct ip_vs_seq *vseq, struct tcphdr *th)
{
__u32 seq = ntohl(th->seq);
if (vseq->delta || vseq->previous_delta) {
if(after(seq, vseq->init_seq)) {
th->seq = htonl(seq + vseq->delta);
IP_VS_DBG(9, "%s(): added delta (%d) to seq\n",
__func__, vseq->delta);
} else {
th->seq = htonl(seq + vseq->previous_delta);
IP_VS_DBG(9, "%s(): added previous_delta (%d) to seq\n",
__func__, vseq->previous_delta);
}
}
}
static inline void
vs_fix_ack_seq(const struct ip_vs_seq *vseq, struct tcphdr *th)
{
__u32 ack_seq = ntohl(th->ack_seq);
if (vseq->delta || vseq->previous_delta) {
if(after(ack_seq, vseq->init_seq+vseq->delta)) {
th->ack_seq = htonl(ack_seq - vseq->delta);
IP_VS_DBG(9, "%s(): subtracted delta "
"(%d) from ack_seq\n", __func__, vseq->delta);
} else {
th->ack_seq = htonl(ack_seq - vseq->previous_delta);
IP_VS_DBG(9, "%s(): subtracted "
"previous_delta (%d) from ack_seq\n",
__func__, vseq->previous_delta);
}
}
}
static inline void vs_seq_update(struct ip_vs_conn *cp, struct ip_vs_seq *vseq,
unsigned int flag, __u32 seq, int diff)
{
spin_lock(&cp->lock);
if (!(cp->flags & flag) || after(seq, vseq->init_seq)) {
vseq->previous_delta = vseq->delta;
vseq->delta += diff;
vseq->init_seq = seq;
cp->flags |= flag;
}
spin_unlock(&cp->lock);
}
static inline int app_tcp_pkt_out(struct ip_vs_conn *cp, struct sk_buff *skb,
struct ip_vs_app *app)
{
int diff;
const unsigned int tcp_offset = ip_hdrlen(skb);
struct tcphdr *th;
__u32 seq;
if (!skb_make_writable(skb, tcp_offset + sizeof(*th)))
return 0;
th = (struct tcphdr *)(skb_network_header(skb) + tcp_offset);
seq = ntohl(th->seq);
if (cp->flags & IP_VS_CONN_F_OUT_SEQ)
vs_fix_seq(&cp->out_seq, th);
if (cp->flags & IP_VS_CONN_F_IN_SEQ)
vs_fix_ack_seq(&cp->in_seq, th);
if (app->pkt_out == NULL)
return 1;
if (!app->pkt_out(app, cp, skb, &diff))
return 0;
if (diff != 0)
vs_seq_update(cp, &cp->out_seq,
IP_VS_CONN_F_OUT_SEQ, seq, diff);
return 1;
}
int ip_vs_app_pkt_out(struct ip_vs_conn *cp, struct sk_buff *skb)
{
struct ip_vs_app *app;
if ((app = cp->app) == NULL)
return 1;
if (cp->protocol == IPPROTO_TCP)
return app_tcp_pkt_out(cp, skb, app);
if (app->pkt_out == NULL)
return 1;
return app->pkt_out(app, cp, skb, NULL);
}
static inline int app_tcp_pkt_in(struct ip_vs_conn *cp, struct sk_buff *skb,
struct ip_vs_app *app)
{
int diff;
const unsigned int tcp_offset = ip_hdrlen(skb);
struct tcphdr *th;
__u32 seq;
if (!skb_make_writable(skb, tcp_offset + sizeof(*th)))
return 0;
th = (struct tcphdr *)(skb_network_header(skb) + tcp_offset);
seq = ntohl(th->seq);
if (cp->flags & IP_VS_CONN_F_IN_SEQ)
vs_fix_seq(&cp->in_seq, th);
if (cp->flags & IP_VS_CONN_F_OUT_SEQ)
vs_fix_ack_seq(&cp->out_seq, th);
if (app->pkt_in == NULL)
return 1;
if (!app->pkt_in(app, cp, skb, &diff))
return 0;
if (diff != 0)
vs_seq_update(cp, &cp->in_seq,
IP_VS_CONN_F_IN_SEQ, seq, diff);
return 1;
}
int ip_vs_app_pkt_in(struct ip_vs_conn *cp, struct sk_buff *skb)
{
struct ip_vs_app *app;
if ((app = cp->app) == NULL)
return 1;
if (cp->protocol == IPPROTO_TCP)
return app_tcp_pkt_in(cp, skb, app);
if (app->pkt_in == NULL)
return 1;
return app->pkt_in(app, cp, skb, NULL);
}
static struct ip_vs_app *ip_vs_app_idx(struct netns_ipvs *ipvs, loff_t pos)
{
struct ip_vs_app *app, *inc;
list_for_each_entry(app, &ipvs->app_list, a_list) {
list_for_each_entry(inc, &app->incs_list, a_list) {
if (pos-- == 0)
return inc;
}
}
return NULL;
}
static void *ip_vs_app_seq_start(struct seq_file *seq, loff_t *pos)
{
struct net *net = seq_file_net(seq);
struct netns_ipvs *ipvs = net_ipvs(net);
mutex_lock(&__ip_vs_app_mutex);
return *pos ? ip_vs_app_idx(ipvs, *pos - 1) : SEQ_START_TOKEN;
}
static void *ip_vs_app_seq_next(struct seq_file *seq, void *v, loff_t *pos)
{
struct ip_vs_app *inc, *app;
struct list_head *e;
struct net *net = seq_file_net(seq);
struct netns_ipvs *ipvs = net_ipvs(net);
++*pos;
if (v == SEQ_START_TOKEN)
return ip_vs_app_idx(ipvs, 0);
inc = v;
app = inc->app;
if ((e = inc->a_list.next) != &app->incs_list)
return list_entry(e, struct ip_vs_app, a_list);
for (e = app->a_list.next; e != &ipvs->app_list; e = e->next) {
app = list_entry(e, struct ip_vs_app, a_list);
list_for_each_entry(inc, &app->incs_list, a_list) {
return inc;
}
}
return NULL;
}
static void ip_vs_app_seq_stop(struct seq_file *seq, void *v)
{
mutex_unlock(&__ip_vs_app_mutex);
}
static int ip_vs_app_seq_show(struct seq_file *seq, void *v)
{
if (v == SEQ_START_TOKEN)
seq_puts(seq, "prot port usecnt name\n");
else {
const struct ip_vs_app *inc = v;
seq_printf(seq, "%-3s %-7u %-6d %-17s\n",
ip_vs_proto_name(inc->protocol),
ntohs(inc->port),
atomic_read(&inc->usecnt),
inc->name);
}
return 0;
}
static int ip_vs_app_open(struct inode *inode, struct file *file)
{
return seq_open_net(inode, file, &ip_vs_app_seq_ops,
sizeof(struct seq_net_private));
}
int __net_init ip_vs_app_net_init(struct net *net)
{
struct netns_ipvs *ipvs = net_ipvs(net);
INIT_LIST_HEAD(&ipvs->app_list);
proc_net_fops_create(net, "ip_vs_app", 0, &ip_vs_app_fops);
return 0;
}
void __net_exit ip_vs_app_net_cleanup(struct net *net)
{
proc_net_remove(net, "ip_vs_app");
}
