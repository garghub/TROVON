static inline unsigned int vlan_prio(const struct l2t_entry *e)
{
return e->vlan >> VLAN_PRIO_SHIFT;
}
static inline void l2t_hold(struct l2t_data *d, struct l2t_entry *e)
{
if (atomic_add_return(1, &e->refcnt) == 1)
atomic_dec(&d->nfree);
}
static inline unsigned int arp_hash(struct l2t_data *d, const u32 *key,
int ifindex)
{
unsigned int l2t_size_half = d->l2t_size / 2;
return jhash_2words(*key, ifindex, 0) % l2t_size_half;
}
static inline unsigned int ipv6_hash(struct l2t_data *d, const u32 *key,
int ifindex)
{
unsigned int l2t_size_half = d->l2t_size / 2;
u32 xor = key[0] ^ key[1] ^ key[2] ^ key[3];
return (l2t_size_half +
(jhash_2words(xor, ifindex, 0) % l2t_size_half));
}
static unsigned int addr_hash(struct l2t_data *d, const u32 *addr,
int addr_len, int ifindex)
{
return addr_len == 4 ? arp_hash(d, addr, ifindex) :
ipv6_hash(d, addr, ifindex);
}
static int addreq(const struct l2t_entry *e, const u32 *addr)
{
if (e->v6)
return (e->addr[0] ^ addr[0]) | (e->addr[1] ^ addr[1]) |
(e->addr[2] ^ addr[2]) | (e->addr[3] ^ addr[3]);
return e->addr[0] ^ addr[0];
}
static void neigh_replace(struct l2t_entry *e, struct neighbour *n)
{
neigh_hold(n);
if (e->neigh)
neigh_release(e->neigh);
e->neigh = n;
}
static int write_l2e(struct adapter *adap, struct l2t_entry *e, int sync)
{
struct l2t_data *d = adap->l2t;
unsigned int l2t_idx = e->idx + d->l2t_start;
struct sk_buff *skb;
struct cpl_l2t_write_req *req;
skb = alloc_skb(sizeof(*req), GFP_ATOMIC);
if (!skb)
return -ENOMEM;
req = (struct cpl_l2t_write_req *)__skb_put(skb, sizeof(*req));
INIT_TP_WR(req, 0);
OPCODE_TID(req) = htonl(MK_OPCODE_TID(CPL_L2T_WRITE_REQ,
l2t_idx | (sync ? SYNC_WR_F : 0) |
TID_QID_V(adap->sge.fw_evtq.abs_id)));
req->params = htons(L2T_W_PORT_V(e->lport) | L2T_W_NOREPLY_V(!sync));
req->l2t_idx = htons(l2t_idx);
req->vlan = htons(e->vlan);
if (e->neigh && !(e->neigh->dev->flags & IFF_LOOPBACK))
memcpy(e->dmac, e->neigh->ha, sizeof(e->dmac));
memcpy(req->dst_mac, e->dmac, sizeof(req->dst_mac));
t4_mgmt_tx(adap, skb);
if (sync && e->state != L2T_STATE_SWITCHING)
e->state = L2T_STATE_SYNC_WRITE;
return 0;
}
static void send_pending(struct adapter *adap, struct l2t_entry *e)
{
struct sk_buff *skb;
while ((skb = __skb_dequeue(&e->arpq)) != NULL)
t4_ofld_send(adap, skb);
}
void do_l2t_write_rpl(struct adapter *adap, const struct cpl_l2t_write_rpl *rpl)
{
struct l2t_data *d = adap->l2t;
unsigned int tid = GET_TID(rpl);
unsigned int l2t_idx = tid % L2T_SIZE;
if (unlikely(rpl->status != CPL_ERR_NONE)) {
dev_err(adap->pdev_dev,
"Unexpected L2T_WRITE_RPL status %u for entry %u\n",
rpl->status, l2t_idx);
return;
}
if (tid & SYNC_WR_F) {
struct l2t_entry *e = &d->l2tab[l2t_idx - d->l2t_start];
spin_lock(&e->lock);
if (e->state != L2T_STATE_SWITCHING) {
send_pending(adap, e);
e->state = (e->neigh->nud_state & NUD_STALE) ?
L2T_STATE_STALE : L2T_STATE_VALID;
}
spin_unlock(&e->lock);
}
}
static inline void arpq_enqueue(struct l2t_entry *e, struct sk_buff *skb)
{
__skb_queue_tail(&e->arpq, skb);
}
int cxgb4_l2t_send(struct net_device *dev, struct sk_buff *skb,
struct l2t_entry *e)
{
struct adapter *adap = netdev2adap(dev);
again:
switch (e->state) {
case L2T_STATE_STALE:
neigh_event_send(e->neigh, NULL);
spin_lock_bh(&e->lock);
if (e->state == L2T_STATE_STALE)
e->state = L2T_STATE_VALID;
spin_unlock_bh(&e->lock);
case L2T_STATE_VALID:
return t4_ofld_send(adap, skb);
case L2T_STATE_RESOLVING:
case L2T_STATE_SYNC_WRITE:
spin_lock_bh(&e->lock);
if (e->state != L2T_STATE_SYNC_WRITE &&
e->state != L2T_STATE_RESOLVING) {
spin_unlock_bh(&e->lock);
goto again;
}
arpq_enqueue(e, skb);
spin_unlock_bh(&e->lock);
if (e->state == L2T_STATE_RESOLVING &&
!neigh_event_send(e->neigh, NULL)) {
spin_lock_bh(&e->lock);
if (e->state == L2T_STATE_RESOLVING &&
!skb_queue_empty(&e->arpq))
write_l2e(adap, e, 1);
spin_unlock_bh(&e->lock);
}
}
return 0;
}
static struct l2t_entry *alloc_l2e(struct l2t_data *d)
{
struct l2t_entry *end, *e, **p;
if (!atomic_read(&d->nfree))
return NULL;
for (e = d->rover, end = &d->l2tab[d->l2t_size]; e != end; ++e)
if (atomic_read(&e->refcnt) == 0)
goto found;
for (e = d->l2tab; atomic_read(&e->refcnt); ++e)
;
found:
d->rover = e + 1;
atomic_dec(&d->nfree);
if (e->state < L2T_STATE_SWITCHING)
for (p = &d->l2tab[e->hash].first; *p; p = &(*p)->next)
if (*p == e) {
*p = e->next;
e->next = NULL;
break;
}
e->state = L2T_STATE_UNUSED;
return e;
}
static struct l2t_entry *find_or_alloc_l2e(struct l2t_data *d, u16 vlan,
u8 port, u8 *dmac)
{
struct l2t_entry *end, *e, **p;
struct l2t_entry *first_free = NULL;
for (e = &d->l2tab[0], end = &d->l2tab[d->l2t_size]; e != end; ++e) {
if (atomic_read(&e->refcnt) == 0) {
if (!first_free)
first_free = e;
} else {
if (e->state == L2T_STATE_SWITCHING) {
if (ether_addr_equal(e->dmac, dmac) &&
(e->vlan == vlan) && (e->lport == port))
goto exists;
}
}
}
if (first_free) {
e = first_free;
goto found;
}
return NULL;
found:
if (e->state < L2T_STATE_SWITCHING)
for (p = &d->l2tab[e->hash].first; *p; p = &(*p)->next)
if (*p == e) {
*p = e->next;
e->next = NULL;
break;
}
e->state = L2T_STATE_UNUSED;
exists:
return e;
}
static void _t4_l2e_free(struct l2t_entry *e)
{
struct l2t_data *d;
struct sk_buff *skb;
if (atomic_read(&e->refcnt) == 0) {
if (e->neigh) {
neigh_release(e->neigh);
e->neigh = NULL;
}
while ((skb = __skb_dequeue(&e->arpq)) != NULL)
kfree_skb(skb);
}
d = container_of(e, struct l2t_data, l2tab[e->idx]);
atomic_inc(&d->nfree);
}
static void t4_l2e_free(struct l2t_entry *e)
{
struct l2t_data *d;
struct sk_buff *skb;
spin_lock_bh(&e->lock);
if (atomic_read(&e->refcnt) == 0) {
if (e->neigh) {
neigh_release(e->neigh);
e->neigh = NULL;
}
while ((skb = __skb_dequeue(&e->arpq)) != NULL)
kfree_skb(skb);
}
spin_unlock_bh(&e->lock);
d = container_of(e, struct l2t_data, l2tab[e->idx]);
atomic_inc(&d->nfree);
}
void cxgb4_l2t_release(struct l2t_entry *e)
{
if (atomic_dec_and_test(&e->refcnt))
t4_l2e_free(e);
}
static void reuse_entry(struct l2t_entry *e, struct neighbour *neigh)
{
unsigned int nud_state;
spin_lock(&e->lock);
if (neigh != e->neigh)
neigh_replace(e, neigh);
nud_state = neigh->nud_state;
if (memcmp(e->dmac, neigh->ha, sizeof(e->dmac)) ||
!(nud_state & NUD_VALID))
e->state = L2T_STATE_RESOLVING;
else if (nud_state & NUD_CONNECTED)
e->state = L2T_STATE_VALID;
else
e->state = L2T_STATE_STALE;
spin_unlock(&e->lock);
}
struct l2t_entry *cxgb4_l2t_get(struct l2t_data *d, struct neighbour *neigh,
const struct net_device *physdev,
unsigned int priority)
{
u8 lport;
u16 vlan;
struct l2t_entry *e;
int addr_len = neigh->tbl->key_len;
u32 *addr = (u32 *)neigh->primary_key;
int ifidx = neigh->dev->ifindex;
int hash = addr_hash(d, addr, addr_len, ifidx);
if (neigh->dev->flags & IFF_LOOPBACK)
lport = netdev2pinfo(physdev)->tx_chan + 4;
else
lport = netdev2pinfo(physdev)->lport;
if (is_vlan_dev(neigh->dev))
vlan = vlan_dev_vlan_id(neigh->dev);
else
vlan = VLAN_NONE;
write_lock_bh(&d->lock);
for (e = d->l2tab[hash].first; e; e = e->next)
if (!addreq(e, addr) && e->ifindex == ifidx &&
e->vlan == vlan && e->lport == lport) {
l2t_hold(d, e);
if (atomic_read(&e->refcnt) == 1)
reuse_entry(e, neigh);
goto done;
}
e = alloc_l2e(d);
if (e) {
spin_lock(&e->lock);
e->state = L2T_STATE_RESOLVING;
if (neigh->dev->flags & IFF_LOOPBACK)
memcpy(e->dmac, physdev->dev_addr, sizeof(e->dmac));
memcpy(e->addr, addr, addr_len);
e->ifindex = ifidx;
e->hash = hash;
e->lport = lport;
e->v6 = addr_len == 16;
atomic_set(&e->refcnt, 1);
neigh_replace(e, neigh);
e->vlan = vlan;
e->next = d->l2tab[hash].first;
d->l2tab[hash].first = e;
spin_unlock(&e->lock);
}
done:
write_unlock_bh(&d->lock);
return e;
}
u64 cxgb4_select_ntuple(struct net_device *dev,
const struct l2t_entry *l2t)
{
struct adapter *adap = netdev2adap(dev);
struct tp_params *tp = &adap->params.tp;
u64 ntuple = 0;
if (tp->vlan_shift >= 0 && l2t->vlan != VLAN_NONE)
ntuple |= (u64)(FT_VLAN_VLD_F | l2t->vlan) << tp->vlan_shift;
if (tp->port_shift >= 0)
ntuple |= (u64)l2t->lport << tp->port_shift;
if (tp->protocol_shift >= 0)
ntuple |= (u64)IPPROTO_TCP << tp->protocol_shift;
if (tp->vnic_shift >= 0) {
u32 viid = cxgb4_port_viid(dev);
u32 vf = FW_VIID_VIN_G(viid);
u32 pf = FW_VIID_PFN_G(viid);
u32 vld = FW_VIID_VIVLD_G(viid);
ntuple |= (u64)(FT_VNID_ID_VF_V(vf) |
FT_VNID_ID_PF_V(pf) |
FT_VNID_ID_VLD_V(vld)) << tp->vnic_shift;
}
return ntuple;
}
static void handle_failed_resolution(struct adapter *adap, struct l2t_entry *e)
{
struct sk_buff *skb;
while ((skb = __skb_dequeue(&e->arpq)) != NULL) {
const struct l2t_skb_cb *cb = L2T_SKB_CB(skb);
spin_unlock(&e->lock);
if (cb->arp_err_handler)
cb->arp_err_handler(cb->handle, skb);
else
t4_ofld_send(adap, skb);
spin_lock(&e->lock);
}
}
void t4_l2t_update(struct adapter *adap, struct neighbour *neigh)
{
struct l2t_entry *e;
struct sk_buff_head *arpq = NULL;
struct l2t_data *d = adap->l2t;
int addr_len = neigh->tbl->key_len;
u32 *addr = (u32 *) neigh->primary_key;
int ifidx = neigh->dev->ifindex;
int hash = addr_hash(d, addr, addr_len, ifidx);
read_lock_bh(&d->lock);
for (e = d->l2tab[hash].first; e; e = e->next)
if (!addreq(e, addr) && e->ifindex == ifidx) {
spin_lock(&e->lock);
if (atomic_read(&e->refcnt))
goto found;
spin_unlock(&e->lock);
break;
}
read_unlock_bh(&d->lock);
return;
found:
read_unlock(&d->lock);
if (neigh != e->neigh)
neigh_replace(e, neigh);
if (e->state == L2T_STATE_RESOLVING) {
if (neigh->nud_state & NUD_FAILED) {
arpq = &e->arpq;
} else if ((neigh->nud_state & (NUD_CONNECTED | NUD_STALE)) &&
!skb_queue_empty(&e->arpq)) {
write_l2e(adap, e, 1);
}
} else {
e->state = neigh->nud_state & NUD_CONNECTED ?
L2T_STATE_VALID : L2T_STATE_STALE;
if (memcmp(e->dmac, neigh->ha, sizeof(e->dmac)))
write_l2e(adap, e, 0);
}
if (arpq)
handle_failed_resolution(adap, e);
spin_unlock_bh(&e->lock);
}
struct l2t_entry *t4_l2t_alloc_switching(struct adapter *adap, u16 vlan,
u8 port, u8 *eth_addr)
{
struct l2t_data *d = adap->l2t;
struct l2t_entry *e;
int ret;
write_lock_bh(&d->lock);
e = find_or_alloc_l2e(d, vlan, port, eth_addr);
if (e) {
spin_lock(&e->lock);
if (!atomic_read(&e->refcnt)) {
e->state = L2T_STATE_SWITCHING;
e->vlan = vlan;
e->lport = port;
ether_addr_copy(e->dmac, eth_addr);
atomic_set(&e->refcnt, 1);
ret = write_l2e(adap, e, 0);
if (ret < 0) {
_t4_l2e_free(e);
spin_unlock(&e->lock);
write_unlock_bh(&d->lock);
return NULL;
}
} else {
atomic_inc(&e->refcnt);
}
spin_unlock(&e->lock);
}
write_unlock_bh(&d->lock);
return e;
}
struct l2t_entry *cxgb4_l2t_alloc_switching(struct net_device *dev, u16 vlan,
u8 port, u8 *dmac)
{
struct adapter *adap = netdev2adap(dev);
return t4_l2t_alloc_switching(adap, vlan, port, dmac);
}
struct l2t_data *t4_init_l2t(unsigned int l2t_start, unsigned int l2t_end)
{
unsigned int l2t_size;
int i;
struct l2t_data *d;
if (l2t_start >= l2t_end || l2t_end >= L2T_SIZE)
return NULL;
l2t_size = l2t_end - l2t_start + 1;
if (l2t_size < L2T_MIN_HASH_BUCKETS)
return NULL;
d = t4_alloc_mem(sizeof(*d) + l2t_size * sizeof(struct l2t_entry));
if (!d)
return NULL;
d->l2t_start = l2t_start;
d->l2t_size = l2t_size;
d->rover = d->l2tab;
atomic_set(&d->nfree, l2t_size);
rwlock_init(&d->lock);
for (i = 0; i < d->l2t_size; ++i) {
d->l2tab[i].idx = i;
d->l2tab[i].state = L2T_STATE_UNUSED;
spin_lock_init(&d->l2tab[i].lock);
atomic_set(&d->l2tab[i].refcnt, 0);
skb_queue_head_init(&d->l2tab[i].arpq);
}
return d;
}
static inline void *l2t_get_idx(struct seq_file *seq, loff_t pos)
{
struct l2t_data *d = seq->private;
return pos >= d->l2t_size ? NULL : &d->l2tab[pos];
}
static void *l2t_seq_start(struct seq_file *seq, loff_t *pos)
{
return *pos ? l2t_get_idx(seq, *pos - 1) : SEQ_START_TOKEN;
}
static void *l2t_seq_next(struct seq_file *seq, void *v, loff_t *pos)
{
v = l2t_get_idx(seq, *pos);
if (v)
++*pos;
return v;
}
static void l2t_seq_stop(struct seq_file *seq, void *v)
{
}
static char l2e_state(const struct l2t_entry *e)
{
switch (e->state) {
case L2T_STATE_VALID: return 'V';
case L2T_STATE_STALE: return 'S';
case L2T_STATE_SYNC_WRITE: return 'W';
case L2T_STATE_RESOLVING:
return skb_queue_empty(&e->arpq) ? 'R' : 'A';
case L2T_STATE_SWITCHING: return 'X';
default:
return 'U';
}
}
static int l2t_seq_show(struct seq_file *seq, void *v)
{
if (v == SEQ_START_TOKEN)
seq_puts(seq, " Idx IP address "
"Ethernet address VLAN/P LP State Users Port\n");
else {
char ip[60];
struct l2t_data *d = seq->private;
struct l2t_entry *e = v;
spin_lock_bh(&e->lock);
if (e->state == L2T_STATE_SWITCHING)
ip[0] = '\0';
else
sprintf(ip, e->v6 ? "%pI6c" : "%pI4", e->addr);
seq_printf(seq, "%4u %-25s %17pM %4d %u %2u %c %5u %s\n",
e->idx + d->l2t_start, ip, e->dmac,
e->vlan & VLAN_VID_MASK, vlan_prio(e), e->lport,
l2e_state(e), atomic_read(&e->refcnt),
e->neigh ? e->neigh->dev->name : "");
spin_unlock_bh(&e->lock);
}
return 0;
}
static int l2t_seq_open(struct inode *inode, struct file *file)
{
int rc = seq_open(file, &l2t_seq_ops);
if (!rc) {
struct adapter *adap = inode->i_private;
struct seq_file *seq = file->private_data;
seq->private = adap->l2t;
}
return rc;
}
