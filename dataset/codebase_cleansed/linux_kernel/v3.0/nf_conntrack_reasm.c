static unsigned int nf_hashfn(struct inet_frag_queue *q)
{
const struct nf_ct_frag6_queue *nq;
nq = container_of(q, struct nf_ct_frag6_queue, q);
return inet6_hash_frag(nq->id, &nq->saddr, &nq->daddr, nf_frags.rnd);
}
static void nf_skb_free(struct sk_buff *skb)
{
if (NFCT_FRAG6_CB(skb)->orig)
kfree_skb(NFCT_FRAG6_CB(skb)->orig);
}
static __inline__ void fq_put(struct nf_ct_frag6_queue *fq)
{
inet_frag_put(&fq->q, &nf_frags);
}
static __inline__ void fq_kill(struct nf_ct_frag6_queue *fq)
{
inet_frag_kill(&fq->q, &nf_frags);
}
static void nf_ct_frag6_evictor(void)
{
local_bh_disable();
inet_frag_evictor(&nf_init_frags, &nf_frags);
local_bh_enable();
}
static void nf_ct_frag6_expire(unsigned long data)
{
struct nf_ct_frag6_queue *fq;
fq = container_of((struct inet_frag_queue *)data,
struct nf_ct_frag6_queue, q);
spin_lock(&fq->q.lock);
if (fq->q.last_in & INET_FRAG_COMPLETE)
goto out;
fq_kill(fq);
out:
spin_unlock(&fq->q.lock);
fq_put(fq);
}
int nf_ct_frag6_queue(struct nf_ct_frag6_queue *fq, struct sk_buff *skb,
const struct frag_hdr *fhdr, int nhoff)
{
struct sk_buff *prev, *next;
int offset, end;
if (fq->q.last_in & INET_FRAG_COMPLETE) {
pr_debug("Already completed\n");
goto err;
}
offset = ntohs(fhdr->frag_off) & ~0x7;
end = offset + (ntohs(ipv6_hdr(skb)->payload_len) -
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
skb->dev = NULL;
fq->q.stamp = skb->tstamp;
fq->q.meat += skb->len;
atomic_add(skb->truesize, &nf_init_frags.mem);
if (offset == 0) {
fq->nhoffset = nhoff;
fq->q.last_in |= INET_FRAG_FIRST_IN;
}
write_lock(&nf_frags.lock);
list_move_tail(&fq->q.lru_list, &nf_init_frags.lru_list);
write_unlock(&nf_frags.lock);
return 0;
discard_fq:
fq_kill(fq);
err:
return -1;
}
static struct sk_buff *
nf_ct_frag6_reasm(struct nf_ct_frag6_queue *fq, struct net_device *dev)
{
struct sk_buff *fp, *op, *head = fq->q.fragments;
int payload_len;
fq_kill(fq);
WARN_ON(head == NULL);
WARN_ON(NFCT_FRAG6_CB(head)->offset != 0);
payload_len = ((head->data - skb_network_header(head)) -
sizeof(struct ipv6hdr) + fq->q.len -
sizeof(struct frag_hdr));
if (payload_len > IPV6_MAXPLEN) {
pr_debug("payload len is too large.\n");
goto out_oversize;
}
if (skb_cloned(head) && pskb_expand_head(head, 0, 0, GFP_ATOMIC)) {
pr_debug("skb is cloned but can't expand head");
goto out_oom;
}
if (skb_has_frag_list(head)) {
struct sk_buff *clone;
int i, plen = 0;
if ((clone = alloc_skb(0, GFP_ATOMIC)) == NULL) {
pr_debug("Can't alloc skb\n");
goto out_oom;
}
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
NFCT_FRAG6_CB(clone)->orig = NULL;
atomic_add(clone->truesize, &nf_init_frags.mem);
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
atomic_sub(head->truesize, &nf_init_frags.mem);
head->next = NULL;
head->dev = dev;
head->tstamp = fq->q.stamp;
ipv6_hdr(head)->payload_len = htons(payload_len);
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
if (net_ratelimit())
printk(KERN_DEBUG "nf_ct_frag6_reasm: payload len = %d\n", payload_len);
goto out_fail;
out_oom:
if (net_ratelimit())
printk(KERN_DEBUG "nf_ct_frag6_reasm: no memory for reassembly\n");
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
struct frag_hdr *fhdr;
struct nf_ct_frag6_queue *fq;
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
if (atomic_read(&nf_init_frags.mem) > nf_init_frags.high_thresh)
nf_ct_frag6_evictor();
fq = fq_find(fhdr->identification, user, &hdr->saddr, &hdr->daddr);
if (fq == NULL) {
pr_debug("Can't find and can't create new queue\n");
goto ret_orig;
}
spin_lock_bh(&fq->q.lock);
if (nf_ct_frag6_queue(fq, clone, fhdr, nhoff) < 0) {
spin_unlock_bh(&fq->q.lock);
pr_debug("Can't insert skb to queue\n");
fq_put(fq);
goto ret_orig;
}
if (fq->q.last_in == (INET_FRAG_FIRST_IN | INET_FRAG_LAST_IN) &&
fq->q.meat == fq->q.len) {
ret_skb = nf_ct_frag6_reasm(fq, dev);
if (ret_skb == NULL)
pr_debug("Can't reassemble fragmented packets\n");
}
spin_unlock_bh(&fq->q.lock);
fq_put(fq);
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
for (s = NFCT_FRAG6_CB(skb)->orig; s;) {
nf_conntrack_put_reasm(s->nfct_reasm);
nf_conntrack_get_reasm(skb);
s->nfct_reasm = skb;
s2 = s->next;
s->next = NULL;
NF_HOOK_THRESH(NFPROTO_IPV6, hooknum, s, in, out, okfn,
NF_IP6_PRI_CONNTRACK_DEFRAG + 1);
s = s2;
}
nf_conntrack_put_reasm(skb);
}
int nf_ct_frag6_init(void)
{
nf_frags.hashfn = nf_hashfn;
nf_frags.constructor = ip6_frag_init;
nf_frags.destructor = NULL;
nf_frags.skb_free = nf_skb_free;
nf_frags.qsize = sizeof(struct nf_ct_frag6_queue);
nf_frags.match = ip6_frag_match;
nf_frags.frag_expire = nf_ct_frag6_expire;
nf_frags.secret_interval = 10 * 60 * HZ;
nf_init_frags.timeout = IPV6_FRAG_TIMEOUT;
nf_init_frags.high_thresh = IPV6_FRAG_HIGH_THRESH;
nf_init_frags.low_thresh = IPV6_FRAG_LOW_THRESH;
inet_frags_init_net(&nf_init_frags);
inet_frags_init(&nf_frags);
#ifdef CONFIG_SYSCTL
nf_ct_frag6_sysctl_header = register_sysctl_paths(nf_net_netfilter_sysctl_path,
nf_ct_frag6_sysctl_table);
if (!nf_ct_frag6_sysctl_header) {
inet_frags_fini(&nf_frags);
return -ENOMEM;
}
#endif
return 0;
}
void nf_ct_frag6_cleanup(void)
{
#ifdef CONFIG_SYSCTL
unregister_sysctl_table(nf_ct_frag6_sysctl_header);
nf_ct_frag6_sysctl_header = NULL;
#endif
inet_frags_fini(&nf_frags);
nf_init_frags.low_thresh = 0;
nf_ct_frag6_evictor();
}
