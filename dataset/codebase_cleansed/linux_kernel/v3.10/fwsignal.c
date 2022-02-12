static const char *brcmf_fws_get_tlv_name(enum brcmf_fws_tlv_type id)
{
int i;
for (i = 0; i < ARRAY_SIZE(brcmf_fws_tlv_names); i++)
if (brcmf_fws_tlv_names[i].id == id)
return brcmf_fws_tlv_names[i].name;
return "INVALID";
}
static const char *brcmf_fws_get_tlv_name(enum brcmf_fws_tlv_type id)
{
return "NODEBUG";
}
static int brcmf_fws_get_tlv_len(struct brcmf_fws_info *fws,
enum brcmf_fws_tlv_type id)
{
switch (id) {
BRCMF_FWS_TLV_DEFLIST
default:
fws->stats.tlv_invalid_type++;
break;
}
return -EINVAL;
}
static bool brcmf_fws_ifidx_match(struct sk_buff *skb, void *arg)
{
u32 ifidx = brcmf_skb_if_flags_get_field(skb, INDEX);
return ifidx == *(int *)arg;
}
static void brcmf_fws_psq_flush(struct brcmf_fws_info *fws, struct pktq *q,
int ifidx)
{
bool (*matchfn)(struct sk_buff *, void *) = NULL;
struct sk_buff *skb;
int prec;
if (ifidx != -1)
matchfn = brcmf_fws_ifidx_match;
for (prec = 0; prec < q->num_prec; prec++) {
skb = brcmu_pktq_pdeq_match(q, prec, matchfn, &ifidx);
while (skb) {
brcmu_pkt_buf_free_skb(skb);
skb = brcmu_pktq_pdeq_match(q, prec, matchfn, &ifidx);
}
}
}
static void brcmf_fws_hanger_init(struct brcmf_fws_hanger *hanger)
{
int i;
brcmf_dbg(TRACE, "enter\n");
memset(hanger, 0, sizeof(*hanger));
for (i = 0; i < ARRAY_SIZE(hanger->items); i++)
hanger->items[i].state = BRCMF_FWS_HANGER_ITEM_STATE_FREE;
}
static u32 brcmf_fws_hanger_get_free_slot(struct brcmf_fws_hanger *h)
{
u32 i;
brcmf_dbg(TRACE, "enter\n");
i = (h->slot_pos + 1) % BRCMF_FWS_HANGER_MAXITEMS;
while (i != h->slot_pos) {
if (h->items[i].state == BRCMF_FWS_HANGER_ITEM_STATE_FREE) {
h->slot_pos = i;
goto done;
}
i++;
if (i == BRCMF_FWS_HANGER_MAXITEMS)
i = 0;
}
brcmf_err("all slots occupied\n");
h->failed_slotfind++;
i = BRCMF_FWS_HANGER_MAXITEMS;
done:
brcmf_dbg(TRACE, "exit: %d\n", i);
return i;
}
static int brcmf_fws_hanger_pushpkt(struct brcmf_fws_hanger *h,
struct sk_buff *pkt, u32 slot_id)
{
brcmf_dbg(TRACE, "enter\n");
if (slot_id >= BRCMF_FWS_HANGER_MAXITEMS)
return -ENOENT;
if (h->items[slot_id].state != BRCMF_FWS_HANGER_ITEM_STATE_FREE) {
brcmf_err("slot is not free\n");
h->failed_to_push++;
return -EINVAL;
}
h->items[slot_id].state = BRCMF_FWS_HANGER_ITEM_STATE_INUSE;
h->items[slot_id].pkt = pkt;
h->pushed++;
return 0;
}
static int brcmf_fws_hanger_poppkt(struct brcmf_fws_hanger *h,
u32 slot_id, struct sk_buff **pktout,
bool remove_item)
{
brcmf_dbg(TRACE, "enter\n");
if (slot_id >= BRCMF_FWS_HANGER_MAXITEMS)
return -ENOENT;
if (h->items[slot_id].state == BRCMF_FWS_HANGER_ITEM_STATE_FREE) {
brcmf_err("entry not in use\n");
h->failed_to_pop++;
return -EINVAL;
}
*pktout = h->items[slot_id].pkt;
if (remove_item) {
h->items[slot_id].state = BRCMF_FWS_HANGER_ITEM_STATE_FREE;
h->items[slot_id].pkt = NULL;
h->items[slot_id].gen = 0xff;
h->popped++;
}
return 0;
}
static int brcmf_fws_hanger_mark_suppressed(struct brcmf_fws_hanger *h,
u32 slot_id, u8 gen)
{
brcmf_dbg(TRACE, "enter\n");
if (slot_id >= BRCMF_FWS_HANGER_MAXITEMS)
return -ENOENT;
h->items[slot_id].gen = gen;
if (h->items[slot_id].state != BRCMF_FWS_HANGER_ITEM_STATE_INUSE) {
brcmf_err("entry not in use\n");
return -EINVAL;
}
h->items[slot_id].state = BRCMF_FWS_HANGER_ITEM_STATE_INUSE_SUPPRESSED;
return 0;
}
static int brcmf_fws_hanger_get_genbit(struct brcmf_fws_hanger *hanger,
struct sk_buff *pkt, u32 slot_id,
int *gen)
{
brcmf_dbg(TRACE, "enter\n");
*gen = 0xff;
if (slot_id >= BRCMF_FWS_HANGER_MAXITEMS)
return -ENOENT;
if (hanger->items[slot_id].state == BRCMF_FWS_HANGER_ITEM_STATE_FREE) {
brcmf_err("slot not in use\n");
return -EINVAL;
}
*gen = hanger->items[slot_id].gen;
return 0;
}
static void brcmf_fws_hanger_cleanup(struct brcmf_fws_info *fws,
bool (*fn)(struct sk_buff *, void *),
int ifidx)
{
struct brcmf_fws_hanger *h = &fws->hanger;
struct sk_buff *skb;
int i;
enum brcmf_fws_hanger_item_state s;
brcmf_dbg(TRACE, "enter: ifidx=%d\n", ifidx);
for (i = 0; i < ARRAY_SIZE(h->items); i++) {
s = h->items[i].state;
if (s == BRCMF_FWS_HANGER_ITEM_STATE_INUSE ||
s == BRCMF_FWS_HANGER_ITEM_STATE_INUSE_SUPPRESSED) {
skb = h->items[i].pkt;
if (fn == NULL || fn(skb, &ifidx)) {
if (s == BRCMF_FWS_HANGER_ITEM_STATE_INUSE)
brcmu_pkt_buf_free_skb(skb);
h->items[i].state =
BRCMF_FWS_HANGER_ITEM_STATE_FREE;
}
}
}
}
static void brcmf_fws_init_mac_descriptor(struct brcmf_fws_mac_descriptor *desc,
u8 *addr, u8 ifidx)
{
brcmf_dbg(TRACE,
"enter: desc %p ea=%pM, ifidx=%u\n", desc, addr, ifidx);
desc->occupied = 1;
desc->state = BRCMF_FWS_STATE_OPEN;
desc->requested_credit = 0;
desc->interface_id = ifidx;
desc->ac_bitmap = 0xff;
if (addr)
memcpy(&desc->ea[0], addr, ETH_ALEN);
}
static
void brcmf_fws_clear_mac_descriptor(struct brcmf_fws_mac_descriptor *desc)
{
brcmf_dbg(TRACE,
"enter: ea=%pM, ifidx=%u\n", desc->ea, desc->interface_id);
desc->occupied = 0;
desc->state = BRCMF_FWS_STATE_CLOSE;
desc->requested_credit = 0;
}
static struct brcmf_fws_mac_descriptor *
brcmf_fws_mac_descriptor_lookup(struct brcmf_fws_info *fws, u8 *ea)
{
struct brcmf_fws_mac_descriptor *entry;
int i;
brcmf_dbg(TRACE, "enter: ea=%pM\n", ea);
if (ea == NULL)
return ERR_PTR(-EINVAL);
entry = &fws->desc.nodes[0];
for (i = 0; i < ARRAY_SIZE(fws->desc.nodes); i++) {
if (entry->occupied && !memcmp(entry->ea, ea, ETH_ALEN))
return entry;
entry++;
}
return ERR_PTR(-ENOENT);
}
static struct brcmf_fws_mac_descriptor*
brcmf_fws_find_mac_desc(struct brcmf_fws_info *fws, struct brcmf_if *ifp,
u8 *da)
{
struct brcmf_fws_mac_descriptor *entry = &fws->desc.other;
bool multicast;
enum nl80211_iftype iftype;
brcmf_dbg(TRACE, "enter: idx=%d\n", ifp->bssidx);
multicast = is_multicast_ether_addr(da);
iftype = brcmf_cfg80211_get_iftype(ifp);
entry = NULL;
if ((multicast || iftype == NL80211_IFTYPE_STATION ||
iftype == NL80211_IFTYPE_P2P_CLIENT) && ifp->fws_desc)
entry = ifp->fws_desc;
if (entry != NULL && iftype != NL80211_IFTYPE_STATION)
goto done;
entry = brcmf_fws_mac_descriptor_lookup(fws, da);
if (IS_ERR(entry))
entry = &fws->desc.other;
done:
brcmf_dbg(TRACE, "exit: entry=%p\n", entry);
return entry;
}
static bool brcmf_fws_mac_desc_closed(struct brcmf_fws_info *fws,
struct brcmf_fws_mac_descriptor *entry,
int fifo)
{
struct brcmf_fws_mac_descriptor *if_entry;
bool closed;
if (entry->mac_handle) {
if_entry = &fws->desc.iface[entry->interface_id];
if (if_entry->state == BRCMF_FWS_STATE_CLOSE)
return true;
}
closed = entry->state == BRCMF_FWS_STATE_CLOSE &&
!entry->requested_credit && !entry->requested_packet;
return closed || !(entry->ac_bitmap & BIT(fifo));
}
static void brcmf_fws_mac_desc_cleanup(struct brcmf_fws_info *fws,
struct brcmf_fws_mac_descriptor *entry,
int ifidx)
{
brcmf_dbg(TRACE, "enter: entry=(ea=%pM, ifid=%d), ifidx=%d\n",
entry->ea, entry->interface_id, ifidx);
if (entry->occupied && (ifidx == -1 || ifidx == entry->interface_id)) {
brcmf_dbg(TRACE, "flush psq: ifidx=%d, qlen=%d\n",
ifidx, entry->psq.len);
brcmf_fws_psq_flush(fws, &entry->psq, ifidx);
entry->occupied = !!(entry->psq.len);
}
}
static void brcmf_fws_bus_txq_cleanup(struct brcmf_fws_info *fws,
bool (*fn)(struct sk_buff *, void *),
int ifidx)
{
struct brcmf_fws_hanger_item *hi;
struct pktq *txq;
struct sk_buff *skb;
int prec;
u32 hslot;
brcmf_dbg(TRACE, "enter: ifidx=%d\n", ifidx);
txq = brcmf_bus_gettxq(fws->drvr->bus_if);
if (IS_ERR(txq)) {
brcmf_dbg(TRACE, "no txq to clean up\n");
return;
}
for (prec = 0; prec < txq->num_prec; prec++) {
skb = brcmu_pktq_pdeq_match(txq, prec, fn, &ifidx);
while (skb) {
hslot = brcmf_skb_htod_tag_get_field(skb, HSLOT);
hi = &fws->hanger.items[hslot];
WARN_ON(skb != hi->pkt);
hi->state = BRCMF_FWS_HANGER_ITEM_STATE_FREE;
brcmu_pkt_buf_free_skb(skb);
skb = brcmu_pktq_pdeq_match(txq, prec, fn, &ifidx);
}
}
}
static void brcmf_fws_cleanup(struct brcmf_fws_info *fws, int ifidx)
{
int i;
struct brcmf_fws_mac_descriptor *table;
bool (*matchfn)(struct sk_buff *, void *) = NULL;
brcmf_dbg(TRACE, "enter: ifidx=%d\n", ifidx);
if (fws == NULL)
return;
if (ifidx != -1)
matchfn = brcmf_fws_ifidx_match;
table = &fws->desc.nodes[0];
for (i = 0; i < ARRAY_SIZE(fws->desc.nodes); i++)
brcmf_fws_mac_desc_cleanup(fws, &table[i], ifidx);
brcmf_fws_mac_desc_cleanup(fws, &fws->desc.other, ifidx);
brcmf_fws_bus_txq_cleanup(fws, matchfn, ifidx);
brcmf_fws_hanger_cleanup(fws, matchfn, ifidx);
}
static void brcmf_fws_tim_update(struct brcmf_fws_info *ctx,
struct brcmf_fws_mac_descriptor *entry,
int prec)
{
brcmf_dbg(TRACE, "enter: ea=%pM\n", entry->ea);
if (entry->state == BRCMF_FWS_STATE_CLOSE) {
if (brcmu_pktq_mlen(&entry->psq, 3 << (prec * 2)) == 0)
entry->traffic_pending_bmp =
entry->traffic_pending_bmp & ~NBITVAL(prec);
else
entry->traffic_pending_bmp =
entry->traffic_pending_bmp | NBITVAL(prec);
}
if (entry->traffic_lastreported_bmp != entry->traffic_pending_bmp)
entry->send_tim_signal = true;
}
static void
brcmf_fws_flow_control_check(struct brcmf_fws_info *fws, struct pktq *pq,
u8 if_id)
{
struct brcmf_if *ifp = fws->drvr->iflist[if_id];
if (WARN_ON(!ifp))
return;
brcmf_dbg(TRACE,
"enter: bssidx=%d, ifidx=%d\n", ifp->bssidx, ifp->ifidx);
if ((ifp->netif_stop & BRCMF_NETIF_STOP_REASON_FWS_FC) &&
pq->len <= BRCMF_FWS_FLOWCONTROL_LOWATER)
brcmf_txflowblock_if(ifp,
BRCMF_NETIF_STOP_REASON_FWS_FC, false);
if (!(ifp->netif_stop & BRCMF_NETIF_STOP_REASON_FWS_FC) &&
pq->len >= BRCMF_FWS_FLOWCONTROL_HIWATER)
brcmf_txflowblock_if(ifp, BRCMF_NETIF_STOP_REASON_FWS_FC, true);
return;
}
static int brcmf_fws_rssi_indicate(struct brcmf_fws_info *fws, s8 rssi)
{
brcmf_dbg(CTL, "rssi %d\n", rssi);
return 0;
}
static
int brcmf_fws_macdesc_indicate(struct brcmf_fws_info *fws, u8 type, u8 *data)
{
struct brcmf_fws_mac_descriptor *entry, *existing;
u8 mac_handle;
u8 ifidx;
u8 *addr;
mac_handle = *data++;
ifidx = *data++;
addr = data;
entry = &fws->desc.nodes[mac_handle & 0x1F];
if (type == BRCMF_FWS_TYPE_MACDESC_DEL) {
brcmf_dbg(TRACE, "deleting mac %pM idx %d\n", addr, ifidx);
if (entry->occupied) {
brcmf_fws_mac_desc_cleanup(fws, entry, -1);
brcmf_fws_clear_mac_descriptor(entry);
} else
fws->stats.mac_update_failed++;
return 0;
}
brcmf_dbg(TRACE,
"add mac %pM handle %u idx %d\n", addr, mac_handle, ifidx);
existing = brcmf_fws_mac_descriptor_lookup(fws, addr);
if (IS_ERR(existing)) {
if (!entry->occupied) {
entry->mac_handle = mac_handle;
brcmf_fws_init_mac_descriptor(entry, addr, ifidx);
brcmu_pktq_init(&entry->psq, BRCMF_FWS_PSQ_PREC_COUNT,
BRCMF_FWS_PSQ_LEN);
} else {
fws->stats.mac_update_failed++;
}
} else {
if (entry != existing) {
brcmf_dbg(TRACE, "relocate mac\n");
memcpy(entry, existing,
offsetof(struct brcmf_fws_mac_descriptor, psq));
entry->mac_handle = mac_handle;
brcmf_fws_clear_mac_descriptor(existing);
} else {
brcmf_dbg(TRACE, "use existing\n");
WARN_ON(entry->mac_handle != mac_handle);
}
}
return 0;
}
static int brcmf_fws_macdesc_state_indicate(struct brcmf_fws_info *fws,
u8 type, u8 *data)
{
struct brcmf_fws_mac_descriptor *entry;
u8 mac_handle;
int i;
mac_handle = data[0];
entry = &fws->desc.nodes[mac_handle & 0x1F];
if (!entry->occupied) {
fws->stats.mac_ps_update_failed++;
return -ESRCH;
}
entry->requested_credit = 0;
if (type == BRCMF_FWS_TYPE_MAC_OPEN) {
entry->state = BRCMF_FWS_STATE_OPEN;
return BRCMF_FWS_RET_OK_SCHEDULE;
} else {
entry->state = BRCMF_FWS_STATE_CLOSE;
for (i = BRCMF_FWS_FIFO_AC_BE; i < NL80211_NUM_ACS; i++)
brcmf_fws_tim_update(fws, entry, i);
}
return BRCMF_FWS_RET_OK_NOSCHEDULE;
}
static int brcmf_fws_interface_state_indicate(struct brcmf_fws_info *fws,
u8 type, u8 *data)
{
struct brcmf_fws_mac_descriptor *entry;
u8 ifidx;
int ret;
ifidx = data[0];
brcmf_dbg(TRACE, "enter: ifidx=%d\n", ifidx);
if (ifidx >= BRCMF_MAX_IFS) {
ret = -ERANGE;
goto fail;
}
entry = &fws->desc.iface[ifidx];
if (!entry->occupied) {
ret = -ESRCH;
goto fail;
}
switch (type) {
case BRCMF_FWS_TYPE_INTERFACE_OPEN:
entry->state = BRCMF_FWS_STATE_OPEN;
return BRCMF_FWS_RET_OK_SCHEDULE;
case BRCMF_FWS_TYPE_INTERFACE_CLOSE:
entry->state = BRCMF_FWS_STATE_CLOSE;
return BRCMF_FWS_RET_OK_NOSCHEDULE;
default:
ret = -EINVAL;
break;
}
fail:
fws->stats.if_update_failed++;
return ret;
}
static int brcmf_fws_request_indicate(struct brcmf_fws_info *fws, u8 type,
u8 *data)
{
struct brcmf_fws_mac_descriptor *entry;
entry = &fws->desc.nodes[data[1] & 0x1F];
if (!entry->occupied) {
if (type == BRCMF_FWS_TYPE_MAC_REQUEST_CREDIT)
fws->stats.credit_request_failed++;
else
fws->stats.packet_request_failed++;
return -ESRCH;
}
if (type == BRCMF_FWS_TYPE_MAC_REQUEST_CREDIT)
entry->requested_credit = data[0];
else
entry->requested_packet = data[0];
entry->ac_bitmap = data[2];
return BRCMF_FWS_RET_OK_SCHEDULE;
}
static void brcmf_fws_return_credits(struct brcmf_fws_info *fws,
u8 fifo, u8 credits)
{
int lender_ac;
int *borrowed;
int *fifo_credit;
if (!credits)
return;
if ((fifo == BRCMF_FWS_FIFO_AC_BE) &&
(fws->credits_borrowed[0])) {
for (lender_ac = BRCMF_FWS_FIFO_AC_VO; lender_ac >= 0;
lender_ac--) {
borrowed = &fws->credits_borrowed[lender_ac];
if (*borrowed) {
fws->fifo_credit_map |= (1 << lender_ac);
fifo_credit = &fws->fifo_credit[lender_ac];
if (*borrowed >= credits) {
*borrowed -= credits;
*fifo_credit += credits;
return;
} else {
credits -= *borrowed;
*fifo_credit += *borrowed;
*borrowed = 0;
}
}
}
}
fws->fifo_credit_map |= 1 << fifo;
fws->fifo_credit[fifo] += credits;
}
static void brcmf_fws_schedule_deq(struct brcmf_fws_info *fws)
{
if (fws->fifo_credit_map & fws->fifo_delay_map)
queue_work(fws->fws_wq, &fws->fws_dequeue_work);
}
static void brcmf_skb_pick_up_credit(struct brcmf_fws_info *fws, int fifo,
struct sk_buff *p)
{
struct brcmf_fws_mac_descriptor *entry = brcmf_skbcb(p)->mac;
if (brcmf_skbcb(p)->if_flags & BRCMF_SKB_IF_FLAGS_CREDITCHECK_MASK) {
if (fws->fcmode != BRCMF_FWS_FCMODE_IMPLIED_CREDIT)
return;
brcmf_fws_return_credits(fws, fifo, 1);
} else {
if (!brcmf_skb_if_flags_get_field(p, REQUESTED))
entry->requested_credit++;
}
brcmf_fws_schedule_deq(fws);
}
static int brcmf_fws_enq(struct brcmf_fws_info *fws,
enum brcmf_fws_skb_state state, int fifo,
struct sk_buff *p)
{
int prec = 2 * fifo;
u32 *qfull_stat = &fws->stats.delayq_full_error;
struct brcmf_fws_mac_descriptor *entry;
entry = brcmf_skbcb(p)->mac;
if (entry == NULL) {
brcmf_err("no mac descriptor found for skb %p\n", p);
return -ENOENT;
}
brcmf_dbg(TRACE, "enter: ea=%pM, qlen=%d\n", entry->ea, entry->psq.len);
if (state == BRCMF_FWS_SKBSTATE_SUPPRESSED) {
prec += 1;
qfull_stat = &fws->stats.supprq_full_error;
}
if (brcmu_pktq_penq(&entry->psq, prec, p) == NULL) {
*qfull_stat += 1;
return -ENFILE;
}
fws->fifo_delay_map |= 1 << fifo;
fws->fifo_enqpkt[fifo]++;
brcmf_skbcb(p)->state = state;
if (state == BRCMF_FWS_SKBSTATE_SUPPRESSED)
entry->suppress_count++;
brcmf_fws_tim_update(fws, entry, fifo);
brcmf_fws_flow_control_check(fws, &entry->psq,
brcmf_skb_if_flags_get_field(p, INDEX));
return 0;
}
static struct sk_buff *brcmf_fws_deq(struct brcmf_fws_info *fws, int fifo)
{
struct brcmf_fws_mac_descriptor *table;
struct brcmf_fws_mac_descriptor *entry;
struct sk_buff *p;
int use_credit = 1;
int num_nodes;
int node_pos;
int prec_out;
int pmsk;
int i;
table = (struct brcmf_fws_mac_descriptor *)&fws->desc;
num_nodes = sizeof(fws->desc) / sizeof(struct brcmf_fws_mac_descriptor);
node_pos = fws->deq_node_pos[fifo];
for (i = 0; i < num_nodes; i++) {
entry = &table[(node_pos + i) % num_nodes];
if (!entry->occupied ||
brcmf_fws_mac_desc_closed(fws, entry, fifo))
continue;
if (entry->suppressed)
pmsk = 2;
else
pmsk = 3;
p = brcmu_pktq_mdeq(&entry->psq, pmsk << (fifo * 2), &prec_out);
if (p == NULL) {
if (entry->suppressed) {
if (entry->suppr_transit_count >
entry->suppress_count)
return NULL;
entry->suppressed = false;
p = brcmu_pktq_mdeq(&entry->psq,
1 << (fifo * 2), &prec_out);
}
}
if (p == NULL)
continue;
if (entry->requested_credit > 0) {
entry->requested_credit--;
if (entry->state == BRCMF_FWS_STATE_CLOSE)
use_credit = 0;
} else if (entry->requested_packet > 0) {
entry->requested_packet--;
brcmf_skb_if_flags_set_field(p, REQUESTED, 1);
if (entry->state == BRCMF_FWS_STATE_CLOSE)
use_credit = 0;
}
brcmf_skb_if_flags_set_field(p, CREDITCHECK, use_credit);
fws->deq_node_pos[fifo] = (node_pos + i + 1) % num_nodes;
brcmf_fws_flow_control_check(fws, &entry->psq,
brcmf_skb_if_flags_get_field(p,
INDEX)
);
brcmf_fws_tim_update(fws, entry, fifo);
fws->fifo_enqpkt[fifo]--;
if (fws->fifo_enqpkt[fifo] == 0)
fws->fifo_delay_map &= ~(1 << fifo);
goto done;
}
p = NULL;
done:
brcmf_dbg(TRACE, "exit: fifo %d skb %p\n", fifo, p);
return p;
}
static int brcmf_fws_txstatus_suppressed(struct brcmf_fws_info *fws, int fifo,
struct sk_buff *skb, u32 genbit)
{
struct brcmf_fws_mac_descriptor *entry = brcmf_skbcb(skb)->mac;
u32 hslot;
int ret;
hslot = brcmf_skb_htod_tag_get_field(skb, HSLOT);
if (!entry->suppressed || entry->generation != genbit) {
entry->suppressed = true;
entry->suppress_count = brcmu_pktq_mlen(&entry->psq,
1 << (fifo * 2 + 1));
entry->suppr_transit_count = entry->transit_count;
}
entry->generation = genbit;
ret = brcmf_fws_enq(fws, BRCMF_FWS_SKBSTATE_SUPPRESSED, fifo, skb);
if (ret != 0) {
brcmf_fws_hanger_poppkt(&fws->hanger, hslot, &skb,
true);
} else {
brcmf_fws_hanger_mark_suppressed(&fws->hanger, hslot,
genbit);
entry->suppress_count++;
}
return ret;
}
static int
brcmf_fws_txstatus_process(struct brcmf_fws_info *fws, u8 flags, u32 hslot,
u32 genbit)
{
u32 fifo;
int ret;
bool remove_from_hanger = true;
struct sk_buff *skb;
struct brcmf_fws_mac_descriptor *entry = NULL;
brcmf_dbg(TRACE, "status: flags=0x%X, hslot=%d\n",
flags, hslot);
if (flags == BRCMF_FWS_TXSTATUS_DISCARD)
fws->stats.txs_discard++;
else if (flags == BRCMF_FWS_TXSTATUS_CORE_SUPPRESS) {
fws->stats.txs_supp_core++;
remove_from_hanger = false;
} else if (flags == BRCMF_FWS_TXSTATUS_FW_PS_SUPPRESS) {
fws->stats.txs_supp_ps++;
remove_from_hanger = false;
} else if (flags == BRCMF_FWS_TXSTATUS_FW_TOSSED)
fws->stats.txs_tossed++;
else
brcmf_err("unexpected txstatus\n");
ret = brcmf_fws_hanger_poppkt(&fws->hanger, hslot, &skb,
remove_from_hanger);
if (ret != 0) {
brcmf_err("no packet in hanger slot: hslot=%d\n", hslot);
return ret;
}
entry = brcmf_skbcb(skb)->mac;
if (WARN_ON(!entry)) {
brcmu_pkt_buf_free_skb(skb);
return -EINVAL;
}
fifo = brcmf_skb_htod_tag_get_field(skb, FIFO);
brcmf_skb_pick_up_credit(fws, fifo, skb);
if (!remove_from_hanger)
ret = brcmf_fws_txstatus_suppressed(fws, fifo, skb, genbit);
if (remove_from_hanger || ret) {
entry->transit_count--;
if (entry->suppressed)
entry->suppr_transit_count--;
brcmf_txfinalize(fws->drvr, skb, true);
}
return 0;
}
static int brcmf_fws_fifocreditback_indicate(struct brcmf_fws_info *fws,
u8 *data)
{
int i;
if (fws->fcmode != BRCMF_FWS_FCMODE_EXPLICIT_CREDIT) {
brcmf_dbg(INFO, "ignored\n");
return BRCMF_FWS_RET_OK_NOSCHEDULE;
}
brcmf_dbg(TRACE, "enter: data %pM\n", data);
for (i = 0; i < BRCMF_FWS_FIFO_COUNT; i++)
brcmf_fws_return_credits(fws, i, data[i]);
brcmf_dbg(INFO, "map: credit %x delay %x\n", fws->fifo_credit_map,
fws->fifo_delay_map);
return BRCMF_FWS_RET_OK_SCHEDULE;
}
static int brcmf_fws_txstatus_indicate(struct brcmf_fws_info *fws, u8 *data)
{
__le32 status_le;
u32 status;
u32 hslot;
u32 genbit;
u8 flags;
fws->stats.txs_indicate++;
memcpy(&status_le, data, sizeof(status_le));
status = le32_to_cpu(status_le);
flags = brcmf_txstatus_get_field(status, FLAGS);
hslot = brcmf_txstatus_get_field(status, HSLOT);
genbit = brcmf_txstatus_get_field(status, GENERATION);
return brcmf_fws_txstatus_process(fws, flags, hslot, genbit);
}
static int brcmf_fws_dbg_seqnum_check(struct brcmf_fws_info *fws, u8 *data)
{
__le32 timestamp;
memcpy(&timestamp, &data[2], sizeof(timestamp));
brcmf_dbg(INFO, "received: seq %d, timestamp %d\n", data[1],
le32_to_cpu(timestamp));
return 0;
}
static int brcmf_fws_notify_credit_map(struct brcmf_if *ifp,
const struct brcmf_event_msg *e,
void *data)
{
struct brcmf_fws_info *fws = ifp->drvr->fws;
int i;
ulong flags;
u8 *credits = data;
if (e->datalen < BRCMF_FWS_FIFO_COUNT) {
brcmf_err("event payload too small (%d)\n", e->datalen);
return -EINVAL;
}
brcmf_dbg(TRACE, "enter: credits %pM\n", credits);
brcmf_fws_lock(ifp->drvr, flags);
for (i = 0; i < ARRAY_SIZE(fws->fifo_credit); i++) {
if (*credits)
fws->fifo_credit_map |= 1 << i;
else
fws->fifo_credit_map &= ~(1 << i);
fws->fifo_credit[i] = *credits++;
}
brcmf_fws_schedule_deq(fws);
brcmf_fws_unlock(ifp->drvr, flags);
return 0;
}
int brcmf_fws_hdrpull(struct brcmf_pub *drvr, int ifidx, s16 signal_len,
struct sk_buff *skb)
{
struct brcmf_fws_info *fws = drvr->fws;
ulong flags;
u8 *signal_data;
s16 data_len;
u8 type;
u8 len;
u8 *data;
s32 status;
s32 err;
brcmf_dbg(TRACE, "enter: ifidx %d, skblen %u, sig %d\n",
ifidx, skb->len, signal_len);
WARN_ON(signal_len > skb->len);
if (!signal_len || !drvr->fw_signals) {
skb_pull(skb, signal_len);
return 0;
}
brcmf_fws_lock(drvr, flags);
fws->stats.header_pulls++;
data_len = signal_len;
signal_data = skb->data;
status = BRCMF_FWS_RET_OK_NOSCHEDULE;
while (data_len > 0) {
type = signal_data[0];
if (type == BRCMF_FWS_TYPE_FILLER) {
signal_data += 1;
data_len -= 1;
continue;
}
len = signal_data[1];
data = signal_data + 2;
brcmf_dbg(INFO, "tlv type=%d (%s), len=%d, data[0]=%d\n", type,
brcmf_fws_get_tlv_name(type), len, *data);
if (data_len < len + 2)
break;
if (len != brcmf_fws_get_tlv_len(fws, type))
break;
err = BRCMF_FWS_RET_OK_NOSCHEDULE;
switch (type) {
case BRCMF_FWS_TYPE_HOST_REORDER_RXPKTS:
case BRCMF_FWS_TYPE_COMP_TXSTATUS:
break;
case BRCMF_FWS_TYPE_MACDESC_ADD:
case BRCMF_FWS_TYPE_MACDESC_DEL:
brcmf_fws_macdesc_indicate(fws, type, data);
break;
case BRCMF_FWS_TYPE_MAC_OPEN:
case BRCMF_FWS_TYPE_MAC_CLOSE:
err = brcmf_fws_macdesc_state_indicate(fws, type, data);
break;
case BRCMF_FWS_TYPE_INTERFACE_OPEN:
case BRCMF_FWS_TYPE_INTERFACE_CLOSE:
err = brcmf_fws_interface_state_indicate(fws, type,
data);
break;
case BRCMF_FWS_TYPE_MAC_REQUEST_CREDIT:
case BRCMF_FWS_TYPE_MAC_REQUEST_PACKET:
err = brcmf_fws_request_indicate(fws, type, data);
break;
case BRCMF_FWS_TYPE_TXSTATUS:
brcmf_fws_txstatus_indicate(fws, data);
break;
case BRCMF_FWS_TYPE_FIFO_CREDITBACK:
err = brcmf_fws_fifocreditback_indicate(fws, data);
break;
case BRCMF_FWS_TYPE_RSSI:
brcmf_fws_rssi_indicate(fws, *data);
break;
case BRCMF_FWS_TYPE_TRANS_ID:
brcmf_fws_dbg_seqnum_check(fws, data);
break;
case BRCMF_FWS_TYPE_PKTTAG:
case BRCMF_FWS_TYPE_PENDING_TRAFFIC_BMP:
default:
fws->stats.tlv_invalid_type++;
break;
}
if (err == BRCMF_FWS_RET_OK_SCHEDULE)
status = BRCMF_FWS_RET_OK_SCHEDULE;
signal_data += len + 2;
data_len -= len + 2;
}
if (data_len != 0)
fws->stats.tlv_parse_failed++;
if (status == BRCMF_FWS_RET_OK_SCHEDULE)
brcmf_fws_schedule_deq(fws);
skb_pull(skb, signal_len);
if (skb->len == 0)
fws->stats.header_only_pkt++;
brcmf_fws_unlock(drvr, flags);
return 0;
}
static int brcmf_fws_hdrpush(struct brcmf_fws_info *fws, struct sk_buff *skb)
{
struct brcmf_fws_mac_descriptor *entry = brcmf_skbcb(skb)->mac;
u8 *wlh;
u16 data_offset = 0;
u8 fillers;
__le32 pkttag = cpu_to_le32(brcmf_skbcb(skb)->htod);
brcmf_dbg(TRACE, "enter: ea=%pM, ifidx=%u, pkttag=0x%08X\n",
entry->ea, entry->interface_id, le32_to_cpu(pkttag));
if (entry->send_tim_signal)
data_offset += 2 + BRCMF_FWS_TYPE_PENDING_TRAFFIC_BMP_LEN;
data_offset += 2 + BRCMF_FWS_TYPE_PKTTAG_LEN;
fillers = round_up(data_offset, 4) - data_offset;
data_offset += fillers;
skb_push(skb, data_offset);
wlh = skb->data;
wlh[0] = BRCMF_FWS_TYPE_PKTTAG;
wlh[1] = BRCMF_FWS_TYPE_PKTTAG_LEN;
memcpy(&wlh[2], &pkttag, sizeof(pkttag));
wlh += BRCMF_FWS_TYPE_PKTTAG_LEN + 2;
if (entry->send_tim_signal) {
entry->send_tim_signal = 0;
wlh[0] = BRCMF_FWS_TYPE_PENDING_TRAFFIC_BMP;
wlh[1] = BRCMF_FWS_TYPE_PENDING_TRAFFIC_BMP_LEN;
wlh[2] = entry->mac_handle;
wlh[3] = entry->traffic_pending_bmp;
wlh += BRCMF_FWS_TYPE_PENDING_TRAFFIC_BMP_LEN + 2;
entry->traffic_lastreported_bmp = entry->traffic_pending_bmp;
}
if (fillers)
memset(wlh, BRCMF_FWS_TYPE_FILLER, fillers);
brcmf_proto_hdrpush(fws->drvr, brcmf_skb_if_flags_get_field(skb, INDEX),
data_offset >> 2, skb);
return 0;
}
static int brcmf_fws_precommit_skb(struct brcmf_fws_info *fws, int fifo,
struct sk_buff *p)
{
struct brcmf_skbuff_cb *skcb = brcmf_skbcb(p);
struct brcmf_fws_mac_descriptor *entry = skcb->mac;
int rc = 0;
bool header_needed;
int hslot = BRCMF_FWS_HANGER_MAXITEMS;
u8 free_ctr;
u8 ifidx;
u8 flags;
header_needed = skcb->state != BRCMF_FWS_SKBSTATE_SUPPRESSED;
if (header_needed) {
hslot = brcmf_fws_hanger_get_free_slot(&fws->hanger);
free_ctr = entry->seq[fifo];
brcmf_skb_htod_tag_set_field(p, HSLOT, hslot);
brcmf_skb_htod_tag_set_field(p, FREERUN, free_ctr);
brcmf_skb_htod_tag_set_field(p, GENERATION, 1);
entry->transit_count++;
}
brcmf_skb_if_flags_set_field(p, TRANSMIT, 1);
brcmf_skb_htod_tag_set_field(p, FIFO, fifo);
flags = BRCMF_FWS_HTOD_FLAG_PKTFROMHOST;
if (!(skcb->if_flags & BRCMF_SKB_IF_FLAGS_CREDITCHECK_MASK)) {
flags |= BRCMF_FWS_HTOD_FLAG_PKT_REQUESTED;
}
brcmf_skb_htod_tag_set_field(p, FLAGS, flags);
if (header_needed) {
brcmf_fws_hdrpush(fws, p);
rc = brcmf_fws_hanger_pushpkt(&fws->hanger, p, hslot);
if (rc)
brcmf_err("hanger push failed: rc=%d\n", rc);
} else {
int gen;
rc = brcmf_proto_hdrpull(fws->drvr, false, &ifidx, p);
if (rc == 0) {
hslot = brcmf_skb_htod_tag_get_field(p, HSLOT);
brcmf_fws_hanger_get_genbit(&fws->hanger, p,
hslot, &gen);
brcmf_skb_htod_tag_set_field(p, GENERATION, gen);
brcmf_fws_hdrpush(fws, p);
}
}
return rc;
}
static void
brcmf_fws_rollback_toq(struct brcmf_fws_info *fws, struct sk_buff *skb)
{
struct brcmf_fws_mac_descriptor *entry;
enum brcmf_fws_skb_state state;
struct sk_buff *pktout;
int rc = 0;
int fifo;
int hslot;
u8 ifidx;
fifo = brcmf_skb_if_flags_get_field(skb, FIFO);
state = brcmf_skbcb(skb)->state;
entry = brcmf_skbcb(skb)->mac;
if (entry != NULL) {
if (state == BRCMF_FWS_SKBSTATE_SUPPRESSED) {
pktout = brcmu_pktq_penq_head(&entry->psq, 2 * fifo + 1,
skb);
if (pktout == NULL) {
brcmf_err("suppress queue full\n");
rc = -ENOSPC;
}
} else {
hslot = brcmf_skb_htod_tag_get_field(skb, HSLOT);
rc = brcmf_proto_hdrpull(fws->drvr, false, &ifidx, skb);
if (rc) {
brcmf_err("header removal failed\n");
brcmf_fws_hanger_poppkt(&fws->hanger, hslot,
&pktout, true);
rc = -EINVAL;
goto fail;
}
pktout = brcmu_pktq_penq_head(&entry->psq,
2 * fifo, skb);
if (pktout == NULL) {
brcmf_err("delay queue full\n");
rc = -ENOSPC;
}
brcmf_fws_hanger_poppkt(&fws->hanger, hslot, &pktout,
true);
entry->seq[fifo]--;
}
if (!(brcmf_skbcb(skb)->if_flags &
BRCMF_SKB_IF_FLAGS_CREDITCHECK_MASK))
entry->requested_credit++;
} else {
brcmf_err("no mac entry linked\n");
rc = -ENOENT;
}
fail:
if (rc) {
brcmf_txfinalize(fws->drvr, skb, false);
fws->stats.rollback_failed++;
} else
fws->stats.rollback_success++;
}
static int brcmf_fws_borrow_credit(struct brcmf_fws_info *fws)
{
int lender_ac;
if (time_after(fws->borrow_defer_timestamp, jiffies))
return -ENAVAIL;
for (lender_ac = 0; lender_ac <= BRCMF_FWS_FIFO_AC_VO; lender_ac++) {
if (fws->fifo_credit[lender_ac]) {
fws->credits_borrowed[lender_ac]++;
fws->fifo_credit[lender_ac]--;
if (fws->fifo_credit[lender_ac] == 0)
fws->fifo_credit_map &= ~(1 << lender_ac);
brcmf_dbg(TRACE, "borrow credit from: %d\n", lender_ac);
return 0;
}
}
return -ENAVAIL;
}
static int brcmf_fws_consume_credit(struct brcmf_fws_info *fws, int fifo,
struct sk_buff *skb)
{
struct brcmf_fws_mac_descriptor *entry = brcmf_skbcb(skb)->mac;
int *credit = &fws->fifo_credit[fifo];
int use_credit = 1;
brcmf_dbg(TRACE, "enter: ac=%d, credits=%d\n", fifo, *credit);
if (entry->requested_credit > 0) {
entry->requested_credit--;
if (entry->state == BRCMF_FWS_STATE_CLOSE)
use_credit = 0;
} else if (entry->requested_packet > 0) {
entry->requested_packet--;
brcmf_skb_if_flags_set_field(skb, REQUESTED, 1);
if (entry->state == BRCMF_FWS_STATE_CLOSE)
use_credit = 0;
}
brcmf_skb_if_flags_set_field(skb, CREDITCHECK, use_credit);
if (!use_credit) {
brcmf_dbg(TRACE, "exit: no creditcheck set\n");
return 0;
}
if (fifo != BRCMF_FWS_FIFO_AC_BE)
fws->borrow_defer_timestamp = jiffies +
BRCMF_FWS_BORROW_DEFER_PERIOD;
if (!(*credit)) {
if (fifo == BRCMF_FWS_FIFO_AC_BE &&
brcmf_fws_borrow_credit(fws) == 0)
return 0;
brcmf_dbg(TRACE, "exit: ac=%d, credits depleted\n", fifo);
return -ENAVAIL;
}
(*credit)--;
if (!(*credit))
fws->fifo_credit_map &= ~(1 << fifo);
brcmf_dbg(TRACE, "exit: ac=%d, credits=%d\n", fifo, *credit);
return 0;
}
static int brcmf_fws_commit_skb(struct brcmf_fws_info *fws, int fifo,
struct sk_buff *skb)
{
struct brcmf_skbuff_cb *skcb = brcmf_skbcb(skb);
struct brcmf_fws_mac_descriptor *entry;
struct brcmf_bus *bus = fws->drvr->bus_if;
int rc;
entry = skcb->mac;
if (IS_ERR(entry))
return PTR_ERR(entry);
rc = brcmf_fws_precommit_skb(fws, fifo, skb);
if (rc < 0) {
fws->stats.generic_error++;
goto rollback;
}
rc = brcmf_bus_txdata(bus, skb);
if (rc < 0)
goto rollback;
entry->seq[fifo]++;
fws->stats.pkt2bus++;
if (brcmf_skbcb(skb)->if_flags & BRCMF_SKB_IF_FLAGS_CREDITCHECK_MASK) {
fws->stats.send_pkts[fifo]++;
fws->stats.fifo_credits_sent[fifo]++;
}
return rc;
rollback:
brcmf_fws_rollback_toq(fws, skb);
return rc;
}
int brcmf_fws_process_skb(struct brcmf_if *ifp, struct sk_buff *skb)
{
struct brcmf_pub *drvr = ifp->drvr;
struct brcmf_fws_info *fws = drvr->fws;
struct brcmf_skbuff_cb *skcb = brcmf_skbcb(skb);
struct ethhdr *eh = (struct ethhdr *)(skb->data);
ulong flags;
int fifo = BRCMF_FWS_FIFO_BCMC;
bool multicast = is_multicast_ether_addr(eh->h_dest);
if (!skb->priority)
skb->priority = cfg80211_classify8021d(skb);
drvr->tx_multicast += !!multicast;
if (ntohs(eh->h_proto) == ETH_P_PAE)
atomic_inc(&ifp->pend_8021x_cnt);
if (!brcmf_fws_fc_active(fws)) {
brcmf_proto_hdrpush(drvr, ifp->ifidx, 0, skb);
return brcmf_bus_txdata(drvr->bus_if, skb);
}
skcb->if_flags = 0;
skcb->mac = brcmf_fws_find_mac_desc(fws, ifp, eh->h_dest);
skcb->state = BRCMF_FWS_SKBSTATE_NEW;
brcmf_skb_if_flags_set_field(skb, INDEX, ifp->ifidx);
if (!multicast)
fifo = brcmf_fws_prio2fifo[skb->priority];
brcmf_skb_if_flags_set_field(skb, FIFO, fifo);
brcmf_dbg(TRACE, "ea=%pM, multi=%d, fifo=%d\n", eh->h_dest,
multicast, fifo);
brcmf_fws_lock(drvr, flags);
if (skcb->mac->suppressed ||
brcmf_fws_mac_desc_closed(fws, skcb->mac, fifo) ||
brcmu_pktq_mlen(&skcb->mac->psq, 3 << (fifo * 2)) ||
(!multicast &&
brcmf_fws_consume_credit(fws, fifo, skb) < 0)) {
drvr->fws->fifo_delay_map |= 1 << fifo;
brcmf_fws_enq(fws, BRCMF_FWS_SKBSTATE_DELAYED, fifo, skb);
} else {
if (brcmf_fws_commit_skb(fws, fifo, skb))
if (!multicast)
brcmf_skb_pick_up_credit(fws, fifo, skb);
}
brcmf_fws_unlock(drvr, flags);
return 0;
}
void brcmf_fws_reset_interface(struct brcmf_if *ifp)
{
struct brcmf_fws_mac_descriptor *entry = ifp->fws_desc;
brcmf_dbg(TRACE, "enter: idx=%d\n", ifp->bssidx);
if (!entry)
return;
brcmf_fws_init_mac_descriptor(entry, ifp->mac_addr, ifp->ifidx);
}
void brcmf_fws_add_interface(struct brcmf_if *ifp)
{
struct brcmf_fws_info *fws = ifp->drvr->fws;
struct brcmf_fws_mac_descriptor *entry;
brcmf_dbg(TRACE, "enter: idx=%d, mac=%pM\n",
ifp->bssidx, ifp->mac_addr);
if (!ifp->ndev || !ifp->drvr->fw_signals)
return;
entry = &fws->desc.iface[ifp->ifidx];
ifp->fws_desc = entry;
brcmf_fws_init_mac_descriptor(entry, ifp->mac_addr, ifp->ifidx);
brcmu_pktq_init(&entry->psq, BRCMF_FWS_PSQ_PREC_COUNT,
BRCMF_FWS_PSQ_LEN);
}
void brcmf_fws_del_interface(struct brcmf_if *ifp)
{
struct brcmf_fws_mac_descriptor *entry = ifp->fws_desc;
ulong flags;
brcmf_dbg(TRACE, "enter: idx=%d\n", ifp->bssidx);
if (!entry)
return;
brcmf_fws_lock(ifp->drvr, flags);
ifp->fws_desc = NULL;
brcmf_fws_clear_mac_descriptor(entry);
brcmf_fws_cleanup(ifp->drvr->fws, ifp->ifidx);
brcmf_fws_unlock(ifp->drvr, flags);
}
static void brcmf_fws_dequeue_worker(struct work_struct *worker)
{
struct brcmf_fws_info *fws;
struct sk_buff *skb;
ulong flags;
int fifo;
int credit;
fws = container_of(worker, struct brcmf_fws_info, fws_dequeue_work);
brcmf_dbg(TRACE, "enter: fws=%p\n", fws);
brcmf_fws_lock(fws->drvr, flags);
for (fifo = NL80211_NUM_ACS; fifo >= 0; fifo--) {
brcmf_dbg(TRACE, "fifo %d credit %d\n", fifo,
fws->fifo_credit[fifo]);
for (credit = 0; credit < fws->fifo_credit[fifo]; ) {
skb = brcmf_fws_deq(fws, fifo);
if (!skb || brcmf_fws_commit_skb(fws, fifo, skb))
break;
if (brcmf_skbcb(skb)->if_flags &
BRCMF_SKB_IF_FLAGS_CREDITCHECK_MASK)
credit++;
}
if ((fifo == BRCMF_FWS_FIFO_AC_BE) &&
(credit == fws->fifo_credit[fifo])) {
fws->fifo_credit[fifo] -= credit;
while (brcmf_fws_borrow_credit(fws) == 0) {
skb = brcmf_fws_deq(fws, fifo);
if (!skb) {
brcmf_fws_return_credits(fws, fifo, 1);
break;
}
if (brcmf_fws_commit_skb(fws, fifo, skb)) {
brcmf_fws_return_credits(fws, fifo, 1);
break;
}
}
} else {
fws->fifo_credit[fifo] -= credit;
}
}
brcmf_fws_unlock(fws->drvr, flags);
}
int brcmf_fws_init(struct brcmf_pub *drvr)
{
u32 tlv = BRCMF_FWS_FLAGS_RSSI_SIGNALS;
int rc;
if (!drvr->fw_signals)
return 0;
spin_lock_init(&drvr->fws_spinlock);
drvr->fws = kzalloc(sizeof(*(drvr->fws)), GFP_KERNEL);
if (!drvr->fws) {
rc = -ENOMEM;
goto fail;
}
drvr->fws->drvr = drvr;
drvr->fws->fcmode = fcmode;
drvr->fws->fws_wq = create_singlethread_workqueue("brcmf_fws_wq");
if (drvr->fws->fws_wq == NULL) {
brcmf_err("workqueue creation failed\n");
rc = -EBADF;
goto fail;
}
INIT_WORK(&drvr->fws->fws_dequeue_work, brcmf_fws_dequeue_worker);
if (drvr->fws->fcmode != BRCMF_FWS_FCMODE_NONE)
tlv |= BRCMF_FWS_FLAGS_XONXOFF_SIGNALS |
BRCMF_FWS_FLAGS_CREDIT_STATUS_SIGNALS |
BRCMF_FWS_FLAGS_HOST_PROPTXSTATUS_ACTIVE;
rc = brcmf_fweh_register(drvr, BRCMF_E_FIFO_CREDIT_MAP,
brcmf_fws_notify_credit_map);
if (rc < 0) {
brcmf_err("register credit map handler failed\n");
goto fail;
}
if (brcmf_fil_iovar_int_set(drvr->iflist[0], "tlv", tlv)) {
brcmf_err("failed to set bdcv2 tlv signaling\n");
goto fail_event;
}
brcmf_fws_hanger_init(&drvr->fws->hanger);
brcmf_fws_init_mac_descriptor(&drvr->fws->desc.other, NULL, 0);
brcmu_pktq_init(&drvr->fws->desc.other.psq, BRCMF_FWS_PSQ_PREC_COUNT,
BRCMF_FWS_PSQ_LEN);
brcmf_debugfs_create_fws_stats(drvr, &drvr->fws->stats);
brcmf_err("%s bdcv2 tlv signaling [%x]\n",
drvr->fw_signals ? "enabled" : "disabled", tlv);
return 0;
fail_event:
brcmf_fweh_unregister(drvr, BRCMF_E_FIFO_CREDIT_MAP);
fail:
brcmf_fws_deinit(drvr);
return rc;
}
void brcmf_fws_deinit(struct brcmf_pub *drvr)
{
struct brcmf_fws_info *fws = drvr->fws;
ulong flags;
if (!fws)
return;
drvr->fw_signals = false;
if (drvr->fws->fws_wq)
destroy_workqueue(drvr->fws->fws_wq);
brcmf_fws_lock(drvr, flags);
brcmf_fws_cleanup(fws, -1);
drvr->fws = NULL;
brcmf_fws_unlock(drvr, flags);
kfree(fws);
}
bool brcmf_fws_fc_active(struct brcmf_fws_info *fws)
{
if (!fws)
return false;
brcmf_dbg(TRACE, "enter: mode=%d\n", fws->fcmode);
return fws->fcmode != BRCMF_FWS_FCMODE_NONE;
}
void brcmf_fws_bustxfail(struct brcmf_fws_info *fws, struct sk_buff *skb)
{
ulong flags;
brcmf_fws_lock(fws->drvr, flags);
brcmf_fws_txstatus_process(fws, BRCMF_FWS_TXSTATUS_FW_TOSSED,
brcmf_skb_htod_tag_get_field(skb, HSLOT), 0);
if (fws->fcmode == BRCMF_FWS_FCMODE_EXPLICIT_CREDIT &&
brcmf_skbcb(skb)->if_flags & BRCMF_SKB_IF_FLAGS_CREDITCHECK_MASK) {
brcmf_fws_return_credits(fws,
brcmf_skb_htod_tag_get_field(skb,
FIFO),
1);
brcmf_fws_schedule_deq(fws);
}
brcmf_fws_unlock(fws->drvr, flags);
}
