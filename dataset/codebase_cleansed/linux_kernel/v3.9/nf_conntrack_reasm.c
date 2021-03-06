static int nf_ct_frag6_sysctl_register(struct net *net)
{
struct ctl_table *table;
struct ctl_table_header *hdr;
table = nf_ct_frag6_sysctl_table;
if (!net_eq(net, &init_net)) {
table = kmemdup(table, sizeof(nf_ct_frag6_sysctl_table),
GFP_KERNEL);
if (table == NULL)
goto err_alloc;
table[0].data = &net->nf_frag.frags.timeout;
table[1].data = &net->nf_frag.frags.low_thresh;
table[2].data = &net->nf_frag.frags.high_thresh;
}
hdr = register_net_sysctl(net, "net/netfilter", table);
if (hdr == NULL)
goto err_reg;
net->nf_frag.sysctl.frags_hdr = hdr;
return 0;
err_reg:
if (!net_eq(net, &init_net))
kfree(table);
err_alloc:
return -ENOMEM;
}
static void __net_exit nf_ct_frags6_sysctl_unregister(struct net *net)
{
struct ctl_table *table;
table = net->nf_frag.sysctl.frags_hdr->ctl_table_arg;
unregister_net_sysctl_table(net->nf_frag.sysctl.frags_hdr);
if (!net_eq(net, &init_net))
kfree(table);
}
static int nf_ct_frag6_sysctl_register(struct net *net)
{
return 0;
}
static void __net_exit nf_ct_frags6_sysctl_unregister(struct net *net)
{
}
static unsigned int nf_hashfn(struct inet_frag_queue *q)
{
const struct frag_queue *nq;
nq = container_of(q, struct frag_queue, q);
return inet6_hash_frag(nq->id, &nq->saddr, &nq->daddr, nf_frags.rnd);
}
static void nf_skb_free(struct sk_buff *skb)
{
if (NFCT_FRAG6_CB(skb)->orig)
kfree_skb(NFCT_FRAG6_CB(skb)->orig);
}
static void nf_ct_frag6_expire(unsigned long data)
{
struct frag_queue *fq;
struct net *net;
fq = container_of((struct inet_frag_queue *)data, struct frag_queue, q);
net = container_of(fq->q.net, struct net, nf_frag.frags);
ip6_expire_frag_queue(net, fq, &nf_frags);
}
static inline struct frag_queue *fq_find(struct net *net, __be32 id,
u32 user, struct in6_addr *src,
struct in6_addr *dst)
{
struct inet_frag_queue *q;
struct ip6_create_arg arg;
unsigned int hash;
arg.id = id;
arg.user = user;
arg.src = src;
arg.dst = dst;
read_lock_bh(&nf_frags.lock);
hash = inet6_hash_frag(id, src, dst, nf_frags.rnd);
q = inet_frag_find(&net->nf_frag.frags, &nf_frags, &arg, hash);
local_bh_enable();
if (IS_ERR_OR_NULL(q)) {
inet_frag_maybe_warn_overflow(q, pr_fmt());
return NULL;
}
return container_of(q, struct frag_queue, q);
}
static int nf_ct_frag6_queue(struct frag_queue *fq, struct sk_buff *skb,
const struct frag_hdr *fhdr, int nhoff)
{
struct sk_buff *prev, *next;
unsigned int payload_len;
int offset, end;
if (fq->q.last_in & INET_FRAG_COMPLETE) {
pr_debug("Already completed\n");
goto err;
}
payload_len = ntohs(ipv6_hdr(skb)->payload_len);
offset = ntohs(fhdr->frag_off) & ~0x7;
end = offset + (payload_len -
((u8 *)(fhdr + 1) - (u8 *)(ipv6_hdr(skb) + 1)));
if ((unsigned int)end > IPV6_MAXPLEN) {
pr_debug("offset is too large.\n");
return -1;
}
if (skb->ip_summed == CHECKSUM_COMPLETE) {
const unsigned char *nh = skb_network_header(skb);
skb->csum = csum_sub(skb->csum,
csum_partial(nh, (u8 *)(fhdr + 1) - nh,
0));
}
if (!(fhdr->frag_off & htons(IP6_MF))) {
if (end < fq->q.len ||
((fq->q.last_in & INET_FRAG_LAST_IN) && end != fq->q.len)) {
pr_debug("already received last fragment\n");
goto err;
}
fq->q.last_in |= INET_FRAG_LAST_IN;
fq->q.len = end;
} else {
if (end & 0x7) {
pr_debug("end of fragment not rounded to 8 bytes.\n");
return -1;
}
if (end > fq->q.len) {
if (fq->q.last_in & INET_FRAG_LAST_IN) {
pr_debug("last packet already reached.\n");
goto err;
}
fq->q.len = end;
}
}
if (end == offset)
goto err;
if (!pskb_pull(skb, (u8 *) (fhdr + 1) - skb->data)) {
pr_debug("queue: message is too short.\n");
goto err;
}
if (pskb_trim_rcsum(skb, end - offset)) {
pr_debug("Can't trim\n");
goto err;
}
prev = fq->q.fragments_tail;
if (!prev || NFCT_FRAG6_CB(prev)->offset < offset) {
next = NULL;
goto found;
}
prev = NULL;
for (next = fq->q.fragments; next != NULL; next = next->next) {
if (NFCT_FRAG6_CB(next)->offset >= offset)
break;
prev = next;
}
found:
if (prev &&
(NFCT_FRAG6_CB(prev)->offset + prev->len) > offset)
goto discard_fq;
if (next && NFCT_FRAG6_CB(next)->offset < end)
goto discard_fq;
NFCT_FRAG6_CB(skb)->offset = offset;
skb->next = next;
if (!next)
fq->q.fragments_tail = skb;
if (prev)
prev->next = skb;
else
fq->q.fragments = skb;
if (skb->dev) {
fq->iif = skb->dev->ifindex;
skb->dev = NULL;
}
fq->q.stamp = skb->tstamp;
fq->q.meat += skb->len;
if (payload_len > fq->q.max_size)
fq->q.max_size = payload_len;
add_frag_mem_limit(&fq->q, skb->truesize);
if (offset == 0) {
fq->nhoffset = nhoff;
fq->q.last_in |= INET_FRAG_FIRST_IN;
}
inet_frag_lru_move(&fq->q);
return 0;
discard_fq:
inet_frag_kill(&fq->q, &nf_frags);
err:
return -1;
}
static struct sk_buff *
nf_ct_frag6_reasm(struct frag_queue *fq, struct net_device *dev)
{
struct sk_buff *fp, *op, *head = fq->q.fragments;
int payload_len;
inet_frag_kill(&fq->q, &nf_frags);
WARN_ON(head == NULL);
WARN_ON(NFCT_FRAG6_CB(head)->offset != 0);
payload_len = ((head->data - skb_network_header(head)) -
sizeof(struct ipv6hdr) + fq->q.len -
sizeof(struct frag_hdr));
if (payload_len > IPV6_MAXPLEN) {
pr_debug("payload len is too large.\n");
goto out_oversize;
}
if (skb_unclone(head, GFP_ATOMIC)) {
pr_debug("skb is cloned but can't expand head");
goto out_oom;
}
if (skb_has_frag_list(head)) {
struct sk_buff *clone;
int i, plen = 0;
clone = alloc_skb(0, GFP_ATOMIC);
if (clone == NULL)
goto out_oom;
clone->next = head->next;
head->next = clone;
skb_shinfo(clone)->frag_list = skb_shinfo(head)->frag_list;
skb_frag_list_init(head);
for (i = 0; i < skb_shinfo(head)->nr_frags; i++)
plen += skb_frag_size(&skb_shinfo(head)->frags[i]);
clone->len = clone->data_len = head->data_len - plen;
head->data_len -= clone->len;
head->len -= clone->len;
clone->csum = 0;
clone->ip_summed = head->ip_summed;
NFCT_FRAG6_CB(clone)->orig = NULL;
add_frag_mem_limit(&fq->q, clone->truesize);
}
skb_network_header(head)[fq->nhoffset] = skb_transport_header(head)[0];
memmove(head->head + sizeof(struct frag_hdr), head->head,
(head->data - head->head) - sizeof(struct frag_hdr));
head->mac_header += sizeof(struct frag_hdr);
head->network_header += sizeof(struct frag_hdr);
skb_shinfo(head)->frag_list = head->next;
skb_reset_transport_header(head);
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
sub_frag_mem_limit(&fq->q, head->truesize);
head->local_df = 1;
head->next = NULL;
head->dev = dev;
head->tstamp = fq->q.stamp;
ipv6_hdr(head)->payload_len = htons(payload_len);
IP6CB(head)->frag_max_size = sizeof(struct ipv6hdr) + fq->q.max_size;
if (head->ip_summed == CHECKSUM_COMPLETE)
head->csum = csum_partial(skb_network_header(head),
skb_network_header_len(head),
head->csum);
fq->q.fragments = NULL;
fq->q.fragments_tail = NULL;
fp = skb_shinfo(head)->frag_list;
if (fp && NFCT_FRAG6_CB(fp)->orig == NULL)
fp = fp->next;
op = NFCT_FRAG6_CB(head)->orig;
for (; fp; fp = fp->next) {
struct sk_buff *orig = NFCT_FRAG6_CB(fp)->orig;
op->next = orig;
op = orig;
NFCT_FRAG6_CB(fp)->orig = NULL;
}
return head;
out_oversize:
net_dbg_ratelimited("nf_ct_frag6_reasm: payload len = %d\n",
payload_len);
goto out_fail;
out_oom:
net_dbg_ratelimited("nf_ct_frag6_reasm: no memory for reassembly\n");
out_fail:
return NULL;
}
static int
find_prev_fhdr(struct sk_buff *skb, u8 *prevhdrp, int *prevhoff, int *fhoff)
{
u8 nexthdr = ipv6_hdr(skb)->nexthdr;
const int netoff = skb_network_offset(skb);
u8 prev_nhoff = netoff + offsetof(struct ipv6hdr, nexthdr);
int start = netoff + sizeof(struct ipv6hdr);
int len = skb->len - start;
u8 prevhdr = NEXTHDR_IPV6;
while (nexthdr != NEXTHDR_FRAGMENT) {
struct ipv6_opt_hdr hdr;
int hdrlen;
if (!ipv6_ext_hdr(nexthdr)) {
return -1;
}
if (nexthdr == NEXTHDR_NONE) {
pr_debug("next header is none\n");
return -1;
}
if (len < (int)sizeof(struct ipv6_opt_hdr)) {
pr_debug("too short\n");
return -1;
}
if (skb_copy_bits(skb, start, &hdr, sizeof(hdr)))
BUG();
if (nexthdr == NEXTHDR_AUTH)
hdrlen = (hdr.hdrlen+2)<<2;
else
hdrlen = ipv6_optlen(&hdr);
prevhdr = nexthdr;
prev_nhoff = start;
nexthdr = hdr.nexthdr;
len -= hdrlen;
start += hdrlen;
}
if (len < 0)
return -1;
*prevhdrp = prevhdr;
*prevhoff = prev_nhoff;
*fhoff = start;
return 0;
}
struct sk_buff *nf_ct_frag6_gather(struct sk_buff *skb, u32 user)
{
struct sk_buff *clone;
struct net_device *dev = skb->dev;
struct net *net = skb_dst(skb) ? dev_net(skb_dst(skb)->dev)
: dev_net(skb->dev);
struct frag_hdr *fhdr;
struct frag_queue *fq;
struct ipv6hdr *hdr;
int fhoff, nhoff;
u8 prevhdr;
struct sk_buff *ret_skb = NULL;
if (ipv6_hdr(skb)->payload_len == 0) {
pr_debug("payload len = 0\n");
return skb;
}
if (find_prev_fhdr(skb, &prevhdr, &nhoff, &fhoff) < 0)
return skb;
clone = skb_clone(skb, GFP_ATOMIC);
if (clone == NULL) {
pr_debug("Can't clone skb\n");
return skb;
}
NFCT_FRAG6_CB(clone)->orig = skb;
if (!pskb_may_pull(clone, fhoff + sizeof(*fhdr))) {
pr_debug("message is too short.\n");
goto ret_orig;
}
skb_set_transport_header(clone, fhoff);
hdr = ipv6_hdr(clone);
fhdr = (struct frag_hdr *)skb_transport_header(clone);
local_bh_disable();
inet_frag_evictor(&net->nf_frag.frags, &nf_frags, false);
local_bh_enable();
fq = fq_find(net, fhdr->identification, user, &hdr->saddr, &hdr->daddr);
if (fq == NULL) {
pr_debug("Can't find and can't create new queue\n");
goto ret_orig;
}
spin_lock_bh(&fq->q.lock);
if (nf_ct_frag6_queue(fq, clone, fhdr, nhoff) < 0) {
spin_unlock_bh(&fq->q.lock);
pr_debug("Can't insert skb to queue\n");
inet_frag_put(&fq->q, &nf_frags);
goto ret_orig;
}
if (fq->q.last_in == (INET_FRAG_FIRST_IN | INET_FRAG_LAST_IN) &&
fq->q.meat == fq->q.len) {
ret_skb = nf_ct_frag6_reasm(fq, dev);
if (ret_skb == NULL)
pr_debug("Can't reassemble fragmented packets\n");
}
spin_unlock_bh(&fq->q.lock);
inet_frag_put(&fq->q, &nf_frags);
return ret_skb;
ret_orig:
kfree_skb(clone);
return skb;
}
void nf_ct_frag6_output(unsigned int hooknum, struct sk_buff *skb,
struct net_device *in, struct net_device *out,
int (*okfn)(struct sk_buff *))
{
struct sk_buff *s, *s2;
unsigned int ret = 0;
for (s = NFCT_FRAG6_CB(skb)->orig; s;) {
nf_conntrack_put_reasm(s->nfct_reasm);
nf_conntrack_get_reasm(skb);
s->nfct_reasm = skb;
s2 = s->next;
s->next = NULL;
if (ret != -ECANCELED)
ret = NF_HOOK_THRESH(NFPROTO_IPV6, hooknum, s,
in, out, okfn,
NF_IP6_PRI_CONNTRACK_DEFRAG + 1);
else
kfree_skb(s);
s = s2;
}
nf_conntrack_put_reasm(skb);
}
static int nf_ct_net_init(struct net *net)
{
net->nf_frag.frags.high_thresh = IPV6_FRAG_HIGH_THRESH;
net->nf_frag.frags.low_thresh = IPV6_FRAG_LOW_THRESH;
net->nf_frag.frags.timeout = IPV6_FRAG_TIMEOUT;
inet_frags_init_net(&net->nf_frag.frags);
return nf_ct_frag6_sysctl_register(net);
}
static void nf_ct_net_exit(struct net *net)
{
nf_ct_frags6_sysctl_unregister(net);
inet_frags_exit_net(&net->nf_frag.frags, &nf_frags);
}
int nf_ct_frag6_init(void)
{
int ret = 0;
nf_frags.hashfn = nf_hashfn;
nf_frags.constructor = ip6_frag_init;
nf_frags.destructor = NULL;
nf_frags.skb_free = nf_skb_free;
nf_frags.qsize = sizeof(struct frag_queue);
nf_frags.match = ip6_frag_match;
nf_frags.frag_expire = nf_ct_frag6_expire;
nf_frags.secret_interval = 10 * 60 * HZ;
inet_frags_init(&nf_frags);
ret = register_pernet_subsys(&nf_ct_net_ops);
if (ret)
inet_frags_fini(&nf_frags);
return ret;
}
void nf_ct_frag6_cleanup(void)
{
unregister_pernet_subsys(&nf_ct_net_ops);
inet_frags_fini(&nf_frags);
}
