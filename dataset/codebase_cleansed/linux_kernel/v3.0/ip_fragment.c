static inline u8 ip4_frag_ecn(u8 tos)
{
return 1 << (tos & INET_ECN_MASK);
}
int ip_frag_nqueues(struct net *net)
{
return net->ipv4.frags.nqueues;
}
int ip_frag_mem(struct net *net)
{
return atomic_read(&net->ipv4.frags.mem);
}
static unsigned int ipqhashfn(__be16 id, __be32 saddr, __be32 daddr, u8 prot)
{
return jhash_3words((__force u32)id << 16 | prot,
(__force u32)saddr, (__force u32)daddr,
ip4_frags.rnd) & (INETFRAGS_HASHSZ - 1);
}
static unsigned int ip4_hashfn(struct inet_frag_queue *q)
{
struct ipq *ipq;
ipq = container_of(q, struct ipq, q);
return ipqhashfn(ipq->id, ipq->saddr, ipq->daddr, ipq->protocol);
}
static int ip4_frag_match(struct inet_frag_queue *q, void *a)
{
struct ipq *qp;
struct ip4_create_arg *arg = a;
qp = container_of(q, struct ipq, q);
return qp->id == arg->iph->id &&
qp->saddr == arg->iph->saddr &&
qp->daddr == arg->iph->daddr &&
qp->protocol == arg->iph->protocol &&
qp->user == arg->user;
}
static void frag_kfree_skb(struct netns_frags *nf, struct sk_buff *skb)
{
atomic_sub(skb->truesize, &nf->mem);
kfree_skb(skb);
}
static void ip4_frag_init(struct inet_frag_queue *q, void *a)
{
struct ipq *qp = container_of(q, struct ipq, q);
struct ip4_create_arg *arg = a;
qp->protocol = arg->iph->protocol;
qp->id = arg->iph->id;
qp->ecn = ip4_frag_ecn(arg->iph->tos);
qp->saddr = arg->iph->saddr;
qp->daddr = arg->iph->daddr;
qp->user = arg->user;
qp->peer = sysctl_ipfrag_max_dist ?
inet_getpeer_v4(arg->iph->saddr, 1) : NULL;
}
static __inline__ void ip4_frag_free(struct inet_frag_queue *q)
{
struct ipq *qp;
qp = container_of(q, struct ipq, q);
if (qp->peer)
inet_putpeer(qp->peer);
}
static __inline__ void ipq_put(struct ipq *ipq)
{
inet_frag_put(&ipq->q, &ip4_frags);
}
static void ipq_kill(struct ipq *ipq)
{
inet_frag_kill(&ipq->q, &ip4_frags);
}
static void ip_evictor(struct net *net)
{
int evicted;
evicted = inet_frag_evictor(&net->ipv4.frags, &ip4_frags);
if (evicted)
IP_ADD_STATS_BH(net, IPSTATS_MIB_REASMFAILS, evicted);
}
static void ip_expire(unsigned long arg)
{
struct ipq *qp;
struct net *net;
qp = container_of((struct inet_frag_queue *) arg, struct ipq, q);
net = container_of(qp->q.net, struct net, ipv4.frags);
spin_lock(&qp->q.lock);
if (qp->q.last_in & INET_FRAG_COMPLETE)
goto out;
ipq_kill(qp);
IP_INC_STATS_BH(net, IPSTATS_MIB_REASMTIMEOUT);
IP_INC_STATS_BH(net, IPSTATS_MIB_REASMFAILS);
if ((qp->q.last_in & INET_FRAG_FIRST_IN) && qp->q.fragments != NULL) {
struct sk_buff *head = qp->q.fragments;
const struct iphdr *iph;
int err;
rcu_read_lock();
head->dev = dev_get_by_index_rcu(net, qp->iif);
if (!head->dev)
goto out_rcu_unlock;
skb_dst_drop(head);
iph = ip_hdr(head);
err = ip_route_input_noref(head, iph->daddr, iph->saddr,
iph->tos, head->dev);
if (err)
goto out_rcu_unlock;
if (qp->user == IP_DEFRAG_CONNTRACK_IN &&
skb_rtable(head)->rt_type != RTN_LOCAL)
goto out_rcu_unlock;
icmp_send(head, ICMP_TIME_EXCEEDED, ICMP_EXC_FRAGTIME, 0);
out_rcu_unlock:
rcu_read_unlock();
}
out:
spin_unlock(&qp->q.lock);
ipq_put(qp);
}
static inline struct ipq *ip_find(struct net *net, struct iphdr *iph, u32 user)
{
struct inet_frag_queue *q;
struct ip4_create_arg arg;
unsigned int hash;
arg.iph = iph;
arg.user = user;
read_lock(&ip4_frags.lock);
hash = ipqhashfn(iph->id, iph->saddr, iph->daddr, iph->protocol);
q = inet_frag_find(&net->ipv4.frags, &ip4_frags, &arg, hash);
if (q == NULL)
goto out_nomem;
return container_of(q, struct ipq, q);
out_nomem:
LIMIT_NETDEBUG(KERN_ERR "ip_frag_create: no memory left !\n");
return NULL;
}
static inline int ip_frag_too_far(struct ipq *qp)
{
struct inet_peer *peer = qp->peer;
unsigned int max = sysctl_ipfrag_max_dist;
unsigned int start, end;
int rc;
if (!peer || !max)
return 0;
start = qp->rid;
end = atomic_inc_return(&peer->rid);
qp->rid = end;
rc = qp->q.fragments && (end - start) > max;
if (rc) {
struct net *net;
net = container_of(qp->q.net, struct net, ipv4.frags);
IP_INC_STATS_BH(net, IPSTATS_MIB_REASMFAILS);
}
return rc;
}
static int ip_frag_reinit(struct ipq *qp)
{
struct sk_buff *fp;
if (!mod_timer(&qp->q.timer, jiffies + qp->q.net->timeout)) {
atomic_inc(&qp->q.refcnt);
return -ETIMEDOUT;
}
fp = qp->q.fragments;
do {
struct sk_buff *xp = fp->next;
frag_kfree_skb(qp->q.net, fp);
fp = xp;
} while (fp);
qp->q.last_in = 0;
qp->q.len = 0;
qp->q.meat = 0;
qp->q.fragments = NULL;
qp->q.fragments_tail = NULL;
qp->iif = 0;
qp->ecn = 0;
return 0;
}
static int ip_frag_queue(struct ipq *qp, struct sk_buff *skb)
{
struct sk_buff *prev, *next;
struct net_device *dev;
int flags, offset;
int ihl, end;
int err = -ENOENT;
u8 ecn;
if (qp->q.last_in & INET_FRAG_COMPLETE)
goto err;
if (!(IPCB(skb)->flags & IPSKB_FRAG_COMPLETE) &&
unlikely(ip_frag_too_far(qp)) &&
unlikely(err = ip_frag_reinit(qp))) {
ipq_kill(qp);
goto err;
}
ecn = ip4_frag_ecn(ip_hdr(skb)->tos);
offset = ntohs(ip_hdr(skb)->frag_off);
flags = offset & ~IP_OFFSET;
offset &= IP_OFFSET;
offset <<= 3;
ihl = ip_hdrlen(skb);
end = offset + skb->len - ihl;
err = -EINVAL;
if ((flags & IP_MF) == 0) {
if (end < qp->q.len ||
((qp->q.last_in & INET_FRAG_LAST_IN) && end != qp->q.len))
goto err;
qp->q.last_in |= INET_FRAG_LAST_IN;
qp->q.len = end;
} else {
if (end&7) {
end &= ~7;
if (skb->ip_summed != CHECKSUM_UNNECESSARY)
skb->ip_summed = CHECKSUM_NONE;
}
if (end > qp->q.len) {
if (qp->q.last_in & INET_FRAG_LAST_IN)
goto err;
qp->q.len = end;
}
}
if (end == offset)
goto err;
err = -ENOMEM;
if (pskb_pull(skb, ihl) == NULL)
goto err;
err = pskb_trim_rcsum(skb, end - offset);
if (err)
goto err;
prev = qp->q.fragments_tail;
if (!prev || FRAG_CB(prev)->offset < offset) {
next = NULL;
goto found;
}
prev = NULL;
for (next = qp->q.fragments; next != NULL; next = next->next) {
if (FRAG_CB(next)->offset >= offset)
break;
prev = next;
}
found:
if (prev) {
int i = (FRAG_CB(prev)->offset + prev->len) - offset;
if (i > 0) {
offset += i;
err = -EINVAL;
if (end <= offset)
goto err;
err = -ENOMEM;
if (!pskb_pull(skb, i))
goto err;
if (skb->ip_summed != CHECKSUM_UNNECESSARY)
skb->ip_summed = CHECKSUM_NONE;
}
}
err = -ENOMEM;
while (next && FRAG_CB(next)->offset < end) {
int i = end - FRAG_CB(next)->offset;
if (i < next->len) {
if (!pskb_pull(next, i))
goto err;
FRAG_CB(next)->offset += i;
qp->q.meat -= i;
if (next->ip_summed != CHECKSUM_UNNECESSARY)
next->ip_summed = CHECKSUM_NONE;
break;
} else {
struct sk_buff *free_it = next;
next = next->next;
if (prev)
prev->next = next;
else
qp->q.fragments = next;
qp->q.meat -= free_it->len;
frag_kfree_skb(qp->q.net, free_it);
}
}
FRAG_CB(skb)->offset = offset;
skb->next = next;
if (!next)
qp->q.fragments_tail = skb;
if (prev)
prev->next = skb;
else
qp->q.fragments = skb;
dev = skb->dev;
if (dev) {
qp->iif = dev->ifindex;
skb->dev = NULL;
}
qp->q.stamp = skb->tstamp;
qp->q.meat += skb->len;
qp->ecn |= ecn;
atomic_add(skb->truesize, &qp->q.net->mem);
if (offset == 0)
qp->q.last_in |= INET_FRAG_FIRST_IN;
if (qp->q.last_in == (INET_FRAG_FIRST_IN | INET_FRAG_LAST_IN) &&
qp->q.meat == qp->q.len)
return ip_frag_reasm(qp, prev, dev);
write_lock(&ip4_frags.lock);
list_move_tail(&qp->q.lru_list, &qp->q.net->lru_list);
write_unlock(&ip4_frags.lock);
return -EINPROGRESS;
err:
kfree_skb(skb);
return err;
}
static int ip_frag_reasm(struct ipq *qp, struct sk_buff *prev,
struct net_device *dev)
{
struct net *net = container_of(qp->q.net, struct net, ipv4.frags);
struct iphdr *iph;
struct sk_buff *fp, *head = qp->q.fragments;
int len;
int ihlen;
int err;
u8 ecn;
ipq_kill(qp);
ecn = ip4_frag_ecn_table[qp->ecn];
if (unlikely(ecn == 0xff)) {
err = -EINVAL;
goto out_fail;
}
if (prev) {
head = prev->next;
fp = skb_clone(head, GFP_ATOMIC);
if (!fp)
goto out_nomem;
fp->next = head->next;
if (!fp->next)
qp->q.fragments_tail = fp;
prev->next = fp;
skb_morph(head, qp->q.fragments);
head->next = qp->q.fragments->next;
kfree_skb(qp->q.fragments);
qp->q.fragments = head;
}
WARN_ON(head == NULL);
WARN_ON(FRAG_CB(head)->offset != 0);
ihlen = ip_hdrlen(head);
len = ihlen + qp->q.len;
err = -E2BIG;
if (len > 65535)
goto out_oversize;
if (skb_cloned(head) && pskb_expand_head(head, 0, 0, GFP_ATOMIC))
goto out_nomem;
if (skb_has_frag_list(head)) {
struct sk_buff *clone;
int i, plen = 0;
if ((clone = alloc_skb(0, GFP_ATOMIC)) == NULL)
goto out_nomem;
clone->next = head->next;
head->next = clone;
skb_shinfo(clone)->frag_list = skb_shinfo(head)->frag_list;
skb_frag_list_init(head);
for (i=0; i<skb_shinfo(head)->nr_frags; i++)
plen += skb_shinfo(head)->frags[i].size;
clone->len = clone->data_len = head->data_len - plen;
head->data_len -= clone->len;
head->len -= clone->len;
clone->csum = 0;
clone->ip_summed = head->ip_summed;
atomic_add(clone->truesize, &qp->q.net->mem);
}
skb_shinfo(head)->frag_list = head->next;
skb_push(head, head->data - skb_network_header(head));
for (fp=head->next; fp; fp = fp->next) {
head->data_len += fp->len;
head->len += fp->len;
if (head->ip_summed != fp->ip_summed)
head->ip_summed = CHECKSUM_NONE;
else if (head->ip_summed == CHECKSUM_COMPLETE)
head->csum = csum_add(head->csum, fp->csum);
head->truesize += fp->truesize;
}
atomic_sub(head->truesize, &qp->q.net->mem);
head->next = NULL;
head->dev = dev;
head->tstamp = qp->q.stamp;
iph = ip_hdr(head);
iph->frag_off = 0;
iph->tot_len = htons(len);
iph->tos |= ecn;
IP_INC_STATS_BH(net, IPSTATS_MIB_REASMOKS);
qp->q.fragments = NULL;
qp->q.fragments_tail = NULL;
return 0;
out_nomem:
LIMIT_NETDEBUG(KERN_ERR "IP: queue_glue: no memory for gluing "
"queue %p\n", qp);
err = -ENOMEM;
goto out_fail;
out_oversize:
if (net_ratelimit())
printk(KERN_INFO "Oversized IP packet from %pI4.\n",
&qp->saddr);
out_fail:
IP_INC_STATS_BH(net, IPSTATS_MIB_REASMFAILS);
return err;
}
int ip_defrag(struct sk_buff *skb, u32 user)
{
struct ipq *qp;
struct net *net;
net = skb->dev ? dev_net(skb->dev) : dev_net(skb_dst(skb)->dev);
IP_INC_STATS_BH(net, IPSTATS_MIB_REASMREQDS);
if (atomic_read(&net->ipv4.frags.mem) > net->ipv4.frags.high_thresh)
ip_evictor(net);
if ((qp = ip_find(net, ip_hdr(skb), user)) != NULL) {
int ret;
spin_lock(&qp->q.lock);
ret = ip_frag_queue(qp, skb);
spin_unlock(&qp->q.lock);
ipq_put(qp);
return ret;
}
IP_INC_STATS_BH(net, IPSTATS_MIB_REASMFAILS);
kfree_skb(skb);
return -ENOMEM;
}
static int __net_init ip4_frags_ns_ctl_register(struct net *net)
{
struct ctl_table *table;
struct ctl_table_header *hdr;
table = ip4_frags_ns_ctl_table;
if (!net_eq(net, &init_net)) {
table = kmemdup(table, sizeof(ip4_frags_ns_ctl_table), GFP_KERNEL);
if (table == NULL)
goto err_alloc;
table[0].data = &net->ipv4.frags.high_thresh;
table[1].data = &net->ipv4.frags.low_thresh;
table[2].data = &net->ipv4.frags.timeout;
}
hdr = register_net_sysctl_table(net, net_ipv4_ctl_path, table);
if (hdr == NULL)
goto err_reg;
net->ipv4.frags_hdr = hdr;
return 0;
err_reg:
if (!net_eq(net, &init_net))
kfree(table);
err_alloc:
return -ENOMEM;
}
static void __net_exit ip4_frags_ns_ctl_unregister(struct net *net)
{
struct ctl_table *table;
table = net->ipv4.frags_hdr->ctl_table_arg;
unregister_net_sysctl_table(net->ipv4.frags_hdr);
kfree(table);
}
static void ip4_frags_ctl_register(void)
{
register_net_sysctl_rotable(net_ipv4_ctl_path, ip4_frags_ctl_table);
}
static inline int ip4_frags_ns_ctl_register(struct net *net)
{
return 0;
}
static inline void ip4_frags_ns_ctl_unregister(struct net *net)
{
}
static inline void ip4_frags_ctl_register(void)
{
}
static int __net_init ipv4_frags_init_net(struct net *net)
{
net->ipv4.frags.high_thresh = 256 * 1024;
net->ipv4.frags.low_thresh = 192 * 1024;
net->ipv4.frags.timeout = IP_FRAG_TIME;
inet_frags_init_net(&net->ipv4.frags);
return ip4_frags_ns_ctl_register(net);
}
static void __net_exit ipv4_frags_exit_net(struct net *net)
{
ip4_frags_ns_ctl_unregister(net);
inet_frags_exit_net(&net->ipv4.frags, &ip4_frags);
}
void __init ipfrag_init(void)
{
ip4_frags_ctl_register();
register_pernet_subsys(&ip4_frags_ops);
ip4_frags.hashfn = ip4_hashfn;
ip4_frags.constructor = ip4_frag_init;
ip4_frags.destructor = ip4_frag_free;
ip4_frags.skb_free = NULL;
ip4_frags.qsize = sizeof(struct ipq);
ip4_frags.match = ip4_frag_match;
ip4_frags.frag_expire = ip_expire;
ip4_frags.secret_interval = 10 * 60 * HZ;
inet_frags_init(&ip4_frags);
}
