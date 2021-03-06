static inline unsigned int vlan_prio(const struct l2t_entry *e)
{
return e->vlan >> 13;
}
static inline void l2t_hold(struct l2t_data *d, struct l2t_entry *e)
{
if (atomic_add_return(1, &e->refcnt) == 1)
atomic_dec(&d->nfree);
}
static inline unsigned int arp_hash(const u32 *key, int ifindex)
{
return jhash_2words(*key, ifindex, 0) & L2T_HASH_MASK;
}
static inline unsigned int ipv6_hash(const u32 *key, int ifindex)
{
u32 xor = key[0] ^ key[1] ^ key[2] ^ key[3];
return L2T_SZ_HALF + (jhash_2words(xor, ifindex, 0) & L2T_HASH_MASK);
}
static unsigned int addr_hash(const u32 *addr, int addr_len, int ifindex)
{
return addr_len == 4 ? arp_hash(addr, ifindex) :
ipv6_hash(addr, ifindex);
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
struct sk_buff *skb;
struct cpl_l2t_write_req *req;
skb = alloc_skb(sizeof(*req), GFP_ATOMIC);
if (!skb)
return -ENOMEM;
req = (struct cpl_l2t_write_req *)__skb_put(skb, sizeof(*req));
INIT_TP_WR(req, 0);
OPCODE_TID(req) = htonl(MK_OPCODE_TID(CPL_L2T_WRITE_REQ,
e->idx | (sync ? F_SYNC_WR : 0) |
TID_QID(adap->sge.fw_evtq.abs_id)));
req->params = htons(L2T_W_PORT(e->lport) | L2T_W_NOREPLY(!sync));
req->l2t_idx = htons(e->idx);
req->vlan = htons(e->vlan);
if (e->neigh)
memcpy(e->dmac, e->neigh->ha, sizeof(e->dmac));
memcpy(req->dst_mac, e->dmac, sizeof(req->dst_mac));
set_wr_txq(skb, CPL_PRIORITY_CONTROL, 0);
t4_ofld_send(adap, skb);
if (sync && e->state != L2T_STATE_SWITCHING)
e->state = L2T_STATE_SYNC_WRITE;
return 0;
}
static void send_pending(struct adapter *adap, struct l2t_entry *e)
{
while (e->arpq_head) {
struct sk_buff *skb = e->arpq_head;
e->arpq_head = skb->next;
skb->next = NULL;
t4_ofld_send(adap, skb);
}
e->arpq_tail = NULL;
}
void do_l2t_write_rpl(struct adapter *adap, const struct cpl_l2t_write_rpl *rpl)
{
unsigned int tid = GET_TID(rpl);
unsigned int idx = tid & (L2T_SIZE - 1);
if (unlikely(rpl->status != CPL_ERR_NONE)) {
dev_err(adap->pdev_dev,
"Unexpected L2T_WRITE_RPL status %u for entry %u\n",
rpl->status, idx);
return;
}
if (tid & F_SYNC_WR) {
struct l2t_entry *e = &adap->l2t->l2tab[idx];
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
skb->next = NULL;
if (e->arpq_head)
e->arpq_tail->next = skb;
else
e->arpq_head = skb;
e->arpq_tail = skb;
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
if (e->state == L2T_STATE_RESOLVING && e->arpq_head)
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
for (e = d->rover, end = &d->l2tab[L2T_SIZE]; e != end; ++e)
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
static void t4_l2e_free(struct l2t_entry *e)
{
struct l2t_data *d;
spin_lock_bh(&e->lock);
if (atomic_read(&e->refcnt) == 0) {
if (e->neigh) {
neigh_release(e->neigh);
e->neigh = NULL;
}
while (e->arpq_head) {
struct sk_buff *skb = e->arpq_head;
e->arpq_head = skb->next;
kfree_skb(skb);
}
e->arpq_tail = NULL;
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
int hash = addr_hash(addr, addr_len, ifidx);
if (neigh->dev->flags & IFF_LOOPBACK)
lport = netdev2pinfo(physdev)->tx_chan + 4;
else
lport = netdev2pinfo(physdev)->lport;
if (neigh->dev->priv_flags & IFF_802_1Q_VLAN)
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
static void handle_failed_resolution(struct adapter *adap, struct sk_buff *arpq)
{
while (arpq) {
struct sk_buff *skb = arpq;
const struct l2t_skb_cb *cb = L2T_SKB_CB(skb);
arpq = skb->next;
skb->next = NULL;
if (cb->arp_err_handler)
cb->arp_err_handler(cb->handle, skb);
else
t4_ofld_send(adap, skb);
}
}
void t4_l2t_update(struct adapter *adap, struct neighbour *neigh)
{
struct l2t_entry *e;
struct sk_buff *arpq = NULL;
struct l2t_data *d = adap->l2t;
int addr_len = neigh->tbl->key_len;
u32 *addr = (u32 *) neigh->primary_key;
int ifidx = neigh->dev->ifindex;
int hash = addr_hash(addr, addr_len, ifidx);
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
arpq = e->arpq_head;
e->arpq_head = e->arpq_tail = NULL;
} else if ((neigh->nud_state & (NUD_CONNECTED | NUD_STALE)) &&
e->arpq_head) {
write_l2e(adap, e, 1);
}
} else {
e->state = neigh->nud_state & NUD_CONNECTED ?
L2T_STATE_VALID : L2T_STATE_STALE;
if (memcmp(e->dmac, neigh->ha, sizeof(e->dmac)))
write_l2e(adap, e, 0);
}
spin_unlock_bh(&e->lock);
if (arpq)
handle_failed_resolution(adap, arpq);
}
struct l2t_data *t4_init_l2t(void)
{
int i;
struct l2t_data *d;
d = t4_alloc_mem(sizeof(*d));
if (!d)
return NULL;
d->rover = d->l2tab;
atomic_set(&d->nfree, L2T_SIZE);
rwlock_init(&d->lock);
for (i = 0; i < L2T_SIZE; ++i) {
d->l2tab[i].idx = i;
d->l2tab[i].state = L2T_STATE_UNUSED;
spin_lock_init(&d->l2tab[i].lock);
atomic_set(&d->l2tab[i].refcnt, 0);
}
return d;
}
static inline void *l2t_get_idx(struct seq_file *seq, loff_t pos)
{
struct l2t_entry *l2tab = seq->private;
return pos >= L2T_SIZE ? NULL : &l2tab[pos];
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
case L2T_STATE_RESOLVING: return e->arpq_head ? 'A' : 'R';
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
struct l2t_entry *e = v;
spin_lock_bh(&e->lock);
if (e->state == L2T_STATE_SWITCHING)
ip[0] = '\0';
else
sprintf(ip, e->v6 ? "%pI6c" : "%pI4", e->addr);
seq_printf(seq, "%4u %-25s %17pM %4d %u %2u %c %5u %s\n",
e->idx, ip, e->dmac,
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
seq->private = adap->l2t->l2tab;
}
return rc;
}
