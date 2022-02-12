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
static void brcmf_fws_lock(struct brcmf_fws_info *fws)
__acquires(&fws->spinlock
static void brcmf_fws_unlock(struct brcmf_fws_info *fws)
__releases(&fws->spinlock
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
memset(hanger, 0, sizeof(*hanger));
for (i = 0; i < ARRAY_SIZE(hanger->items); i++)
hanger->items[i].state = BRCMF_FWS_HANGER_ITEM_STATE_FREE;
}
static u32 brcmf_fws_hanger_get_free_slot(struct brcmf_fws_hanger *h)
{
u32 i;
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
return i;
}
static int brcmf_fws_hanger_pushpkt(struct brcmf_fws_hanger *h,
struct sk_buff *pkt, u32 slot_id)
{
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
static inline int brcmf_fws_hanger_poppkt(struct brcmf_fws_hanger *h,
u32 slot_id, struct sk_buff **pktout,
bool remove_item)
{
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
h->popped++;
}
return 0;
}
static int brcmf_fws_hanger_mark_suppressed(struct brcmf_fws_hanger *h,
u32 slot_id)
{
if (slot_id >= BRCMF_FWS_HANGER_MAXITEMS)
return -ENOENT;
if (h->items[slot_id].state == BRCMF_FWS_HANGER_ITEM_STATE_FREE) {
brcmf_err("entry not in use\n");
return -EINVAL;
}
h->items[slot_id].state = BRCMF_FWS_HANGER_ITEM_STATE_INUSE_SUPPRESSED;
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
static void brcmf_fws_macdesc_set_name(struct brcmf_fws_info *fws,
struct brcmf_fws_mac_descriptor *desc)
{
if (desc == &fws->desc.other)
strlcpy(desc->name, "MAC-OTHER", sizeof(desc->name));
else if (desc->mac_handle)
scnprintf(desc->name, sizeof(desc->name), "MAC-%d:%d",
desc->mac_handle, desc->interface_id);
else
scnprintf(desc->name, sizeof(desc->name), "MACIF:%d",
desc->interface_id);
}
static void brcmf_fws_macdesc_init(struct brcmf_fws_mac_descriptor *desc,
u8 *addr, u8 ifidx)
{
brcmf_dbg(TRACE,
"enter: desc %p ea=%pM, ifidx=%u\n", desc, addr, ifidx);
desc->occupied = 1;
desc->state = BRCMF_FWS_STATE_OPEN;
desc->requested_credit = 0;
desc->requested_packet = 0;
desc->interface_id = ifidx;
desc->ac_bitmap = 0xff;
if (addr)
memcpy(&desc->ea[0], addr, ETH_ALEN);
}
static
void brcmf_fws_macdesc_deinit(struct brcmf_fws_mac_descriptor *desc)
{
brcmf_dbg(TRACE,
"enter: ea=%pM, ifidx=%u\n", desc->ea, desc->interface_id);
desc->occupied = 0;
desc->state = BRCMF_FWS_STATE_CLOSE;
desc->requested_credit = 0;
desc->requested_packet = 0;
}
static struct brcmf_fws_mac_descriptor *
brcmf_fws_macdesc_lookup(struct brcmf_fws_info *fws, u8 *ea)
{
struct brcmf_fws_mac_descriptor *entry;
int i;
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
brcmf_fws_macdesc_find(struct brcmf_fws_info *fws, struct brcmf_if *ifp, u8 *da)
{
struct brcmf_fws_mac_descriptor *entry = &fws->desc.other;
bool multicast;
multicast = is_multicast_ether_addr(da);
if (multicast && ifp->fws_desc) {
entry = ifp->fws_desc;
goto done;
}
entry = brcmf_fws_macdesc_lookup(fws, da);
if (IS_ERR(entry))
entry = ifp->fws_desc;
done:
return entry;
}
static bool brcmf_fws_macdesc_closed(struct brcmf_fws_info *fws,
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
static void brcmf_fws_macdesc_cleanup(struct brcmf_fws_info *fws,
struct brcmf_fws_mac_descriptor *entry,
int ifidx)
{
if (entry->occupied && (ifidx == -1 || ifidx == entry->interface_id)) {
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
if (fws == NULL)
return;
if (ifidx != -1)
matchfn = brcmf_fws_ifidx_match;
table = &fws->desc.nodes[0];
for (i = 0; i < ARRAY_SIZE(fws->desc.nodes); i++)
brcmf_fws_macdesc_cleanup(fws, &table[i], ifidx);
brcmf_fws_macdesc_cleanup(fws, &fws->desc.other, ifidx);
brcmf_fws_bus_txq_cleanup(fws, matchfn, ifidx);
brcmf_fws_hanger_cleanup(fws, matchfn, ifidx);
}
static u8 brcmf_fws_hdrpush(struct brcmf_fws_info *fws, struct sk_buff *skb)
{
struct brcmf_fws_mac_descriptor *entry = brcmf_skbcb(skb)->mac;
u8 *wlh;
u16 data_offset = 0;
u8 fillers;
__le32 pkttag = cpu_to_le32(brcmf_skbcb(skb)->htod);
__le16 pktseq = cpu_to_le16(brcmf_skbcb(skb)->htod_seq);
brcmf_dbg(TRACE, "enter: %s, idx=%d hslot=%d htod %X seq %X\n",
entry->name, brcmf_skb_if_flags_get_field(skb, INDEX),
(le32_to_cpu(pkttag) >> 8) & 0xffff,
brcmf_skbcb(skb)->htod, brcmf_skbcb(skb)->htod_seq);
if (entry->send_tim_signal)
data_offset += 2 + BRCMF_FWS_TYPE_PENDING_TRAFFIC_BMP_LEN;
if (BRCMF_FWS_MODE_GET_REUSESEQ(fws->mode))
data_offset += BRCMF_FWS_TYPE_SEQ_LEN;
data_offset += 2 + BRCMF_FWS_TYPE_PKTTAG_LEN;
fillers = round_up(data_offset, 4) - data_offset;
data_offset += fillers;
skb_push(skb, data_offset);
wlh = skb->data;
wlh[0] = BRCMF_FWS_TYPE_PKTTAG;
wlh[1] = BRCMF_FWS_TYPE_PKTTAG_LEN;
memcpy(&wlh[2], &pkttag, sizeof(pkttag));
if (BRCMF_FWS_MODE_GET_REUSESEQ(fws->mode)) {
wlh[1] += BRCMF_FWS_TYPE_SEQ_LEN;
memcpy(&wlh[2 + BRCMF_FWS_TYPE_PKTTAG_LEN], &pktseq,
sizeof(pktseq));
}
wlh += wlh[1] + 2;
if (entry->send_tim_signal) {
entry->send_tim_signal = 0;
wlh[0] = BRCMF_FWS_TYPE_PENDING_TRAFFIC_BMP;
wlh[1] = BRCMF_FWS_TYPE_PENDING_TRAFFIC_BMP_LEN;
wlh[2] = entry->mac_handle;
wlh[3] = entry->traffic_pending_bmp;
brcmf_dbg(TRACE, "adding TIM info: handle %d bmp 0x%X\n",
entry->mac_handle, entry->traffic_pending_bmp);
wlh += BRCMF_FWS_TYPE_PENDING_TRAFFIC_BMP_LEN + 2;
entry->traffic_lastreported_bmp = entry->traffic_pending_bmp;
}
if (fillers)
memset(wlh, BRCMF_FWS_TYPE_FILLER, fillers);
return (u8)(data_offset >> 2);
}
static bool brcmf_fws_tim_update(struct brcmf_fws_info *fws,
struct brcmf_fws_mac_descriptor *entry,
int fifo, bool send_immediately)
{
struct sk_buff *skb;
struct brcmf_skbuff_cb *skcb;
s32 err;
u32 len;
u8 data_offset;
int ifidx;
if (brcmu_pktq_mlen(&entry->psq, 3 << (fifo * 2)) == 0)
entry->traffic_pending_bmp &= ~NBITVAL(fifo);
else
entry->traffic_pending_bmp |= NBITVAL(fifo);
entry->send_tim_signal = false;
if (entry->traffic_lastreported_bmp != entry->traffic_pending_bmp)
entry->send_tim_signal = true;
if (send_immediately && entry->send_tim_signal &&
entry->state == BRCMF_FWS_STATE_CLOSE) {
len = BRCMF_FWS_TYPE_PKTTAG_LEN + 2 +
BRCMF_FWS_TYPE_SEQ_LEN +
BRCMF_FWS_TYPE_PENDING_TRAFFIC_BMP_LEN + 2 +
4 + fws->drvr->hdrlen;
skb = brcmu_pkt_buf_get_skb(len);
if (skb == NULL)
return false;
skb_pull(skb, len);
skcb = brcmf_skbcb(skb);
skcb->mac = entry;
skcb->state = BRCMF_FWS_SKBSTATE_TIM;
skcb->htod = 0;
skcb->htod_seq = 0;
data_offset = brcmf_fws_hdrpush(fws, skb);
ifidx = brcmf_skb_if_flags_get_field(skb, INDEX);
brcmf_fws_unlock(fws);
err = brcmf_proto_txdata(fws->drvr, ifidx, data_offset, skb);
brcmf_fws_lock(fws);
if (err)
brcmu_pkt_buf_free_skb(skb);
return true;
}
return false;
}
static void
brcmf_fws_flow_control_check(struct brcmf_fws_info *fws, struct pktq *pq,
u8 if_id)
{
struct brcmf_if *ifp = brcmf_get_ifp(fws->drvr, if_id);
if (WARN_ON(!ifp))
return;
if ((ifp->netif_stop & BRCMF_NETIF_STOP_REASON_FWS_FC) &&
pq->len <= BRCMF_FWS_FLOWCONTROL_LOWATER)
brcmf_txflowblock_if(ifp,
BRCMF_NETIF_STOP_REASON_FWS_FC, false);
if (!(ifp->netif_stop & BRCMF_NETIF_STOP_REASON_FWS_FC) &&
pq->len >= BRCMF_FWS_FLOWCONTROL_HIWATER) {
fws->stats.fws_flow_block++;
brcmf_txflowblock_if(ifp, BRCMF_NETIF_STOP_REASON_FWS_FC, true);
}
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
if (entry->occupied) {
brcmf_dbg(TRACE, "deleting %s mac %pM\n",
entry->name, addr);
brcmf_fws_lock(fws);
brcmf_fws_macdesc_cleanup(fws, entry, -1);
brcmf_fws_macdesc_deinit(entry);
brcmf_fws_unlock(fws);
} else
fws->stats.mac_update_failed++;
return 0;
}
existing = brcmf_fws_macdesc_lookup(fws, addr);
if (IS_ERR(existing)) {
if (!entry->occupied) {
brcmf_fws_lock(fws);
entry->mac_handle = mac_handle;
brcmf_fws_macdesc_init(entry, addr, ifidx);
brcmf_fws_macdesc_set_name(fws, entry);
brcmu_pktq_init(&entry->psq, BRCMF_FWS_PSQ_PREC_COUNT,
BRCMF_FWS_PSQ_LEN);
brcmf_fws_unlock(fws);
brcmf_dbg(TRACE, "add %s mac %pM\n", entry->name, addr);
} else {
fws->stats.mac_update_failed++;
}
} else {
if (entry != existing) {
brcmf_dbg(TRACE, "copy mac %s\n", existing->name);
brcmf_fws_lock(fws);
memcpy(entry, existing,
offsetof(struct brcmf_fws_mac_descriptor, psq));
entry->mac_handle = mac_handle;
brcmf_fws_macdesc_deinit(existing);
brcmf_fws_macdesc_set_name(fws, entry);
brcmf_fws_unlock(fws);
brcmf_dbg(TRACE, "relocate %s mac %pM\n", entry->name,
addr);
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
int ret;
mac_handle = data[0];
entry = &fws->desc.nodes[mac_handle & 0x1F];
if (!entry->occupied) {
fws->stats.mac_ps_update_failed++;
return -ESRCH;
}
brcmf_fws_lock(fws);
entry->requested_credit = 0;
entry->requested_packet = 0;
if (type == BRCMF_FWS_TYPE_MAC_OPEN) {
entry->state = BRCMF_FWS_STATE_OPEN;
ret = BRCMF_FWS_RET_OK_SCHEDULE;
} else {
entry->state = BRCMF_FWS_STATE_CLOSE;
brcmf_fws_tim_update(fws, entry, BRCMF_FWS_FIFO_AC_BK, false);
brcmf_fws_tim_update(fws, entry, BRCMF_FWS_FIFO_AC_BE, false);
brcmf_fws_tim_update(fws, entry, BRCMF_FWS_FIFO_AC_VI, false);
brcmf_fws_tim_update(fws, entry, BRCMF_FWS_FIFO_AC_VO, true);
ret = BRCMF_FWS_RET_OK_NOSCHEDULE;
}
brcmf_fws_unlock(fws);
return ret;
}
static int brcmf_fws_interface_state_indicate(struct brcmf_fws_info *fws,
u8 type, u8 *data)
{
struct brcmf_fws_mac_descriptor *entry;
u8 ifidx;
int ret;
ifidx = data[0];
if (ifidx >= BRCMF_MAX_IFS) {
ret = -ERANGE;
goto fail;
}
entry = &fws->desc.iface[ifidx];
if (!entry->occupied) {
ret = -ESRCH;
goto fail;
}
brcmf_dbg(TRACE, "%s (%d): %s\n", brcmf_fws_get_tlv_name(type), type,
entry->name);
brcmf_fws_lock(fws);
switch (type) {
case BRCMF_FWS_TYPE_INTERFACE_OPEN:
entry->state = BRCMF_FWS_STATE_OPEN;
ret = BRCMF_FWS_RET_OK_SCHEDULE;
break;
case BRCMF_FWS_TYPE_INTERFACE_CLOSE:
entry->state = BRCMF_FWS_STATE_CLOSE;
ret = BRCMF_FWS_RET_OK_NOSCHEDULE;
break;
default:
ret = -EINVAL;
brcmf_fws_unlock(fws);
goto fail;
}
brcmf_fws_unlock(fws);
return ret;
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
brcmf_dbg(TRACE, "%s (%d): %s cnt %d bmp %d\n",
brcmf_fws_get_tlv_name(type), type, entry->name,
data[0], data[2]);
brcmf_fws_lock(fws);
if (type == BRCMF_FWS_TYPE_MAC_REQUEST_CREDIT)
entry->requested_credit = data[0];
else
entry->requested_packet = data[0];
entry->ac_bitmap = data[2];
brcmf_fws_unlock(fws);
return BRCMF_FWS_RET_OK_SCHEDULE;
}
static void
brcmf_fws_macdesc_use_req_credit(struct brcmf_fws_mac_descriptor *entry,
struct sk_buff *skb)
{
if (entry->requested_credit > 0) {
entry->requested_credit--;
brcmf_skb_if_flags_set_field(skb, REQUESTED, 1);
brcmf_skb_if_flags_set_field(skb, REQ_CREDIT, 1);
if (entry->state != BRCMF_FWS_STATE_CLOSE)
brcmf_err("requested credit set while mac not closed!\n");
} else if (entry->requested_packet > 0) {
entry->requested_packet--;
brcmf_skb_if_flags_set_field(skb, REQUESTED, 1);
brcmf_skb_if_flags_set_field(skb, REQ_CREDIT, 0);
if (entry->state != BRCMF_FWS_STATE_CLOSE)
brcmf_err("requested packet set while mac not closed!\n");
} else {
brcmf_skb_if_flags_set_field(skb, REQUESTED, 0);
brcmf_skb_if_flags_set_field(skb, REQ_CREDIT, 0);
}
}
static void brcmf_fws_macdesc_return_req_credit(struct sk_buff *skb)
{
struct brcmf_fws_mac_descriptor *entry = brcmf_skbcb(skb)->mac;
if ((brcmf_skb_if_flags_get_field(skb, REQ_CREDIT)) &&
(entry->state == BRCMF_FWS_STATE_CLOSE))
entry->requested_credit++;
}
static void brcmf_fws_return_credits(struct brcmf_fws_info *fws,
u8 fifo, u8 credits)
{
int lender_ac;
int *borrowed;
int *fifo_credit;
if (!credits)
return;
fws->fifo_credit_map |= 1 << fifo;
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
fws->fifo_credit[fifo] += credits;
}
static void brcmf_fws_schedule_deq(struct brcmf_fws_info *fws)
{
if ((fws->fifo_credit_map & fws->fifo_delay_map) ||
(!brcmf_fws_fc_active(fws) && fws->fifo_delay_map))
queue_work(fws->fws_wq, &fws->fws_dequeue_work);
}
static int brcmf_fws_enq(struct brcmf_fws_info *fws,
enum brcmf_fws_skb_state state, int fifo,
struct sk_buff *p)
{
int prec = 2 * fifo;
u32 *qfull_stat = &fws->stats.delayq_full_error;
struct brcmf_fws_mac_descriptor *entry;
struct pktq *pq;
struct sk_buff_head *queue;
struct sk_buff *p_head;
struct sk_buff *p_tail;
u32 fr_new;
u32 fr_compare;
entry = brcmf_skbcb(p)->mac;
if (entry == NULL) {
brcmf_err("no mac descriptor found for skb %p\n", p);
return -ENOENT;
}
brcmf_dbg(DATA, "enter: fifo %d skb %p\n", fifo, p);
if (state == BRCMF_FWS_SKBSTATE_SUPPRESSED) {
prec += 1;
qfull_stat = &fws->stats.supprq_full_error;
pq = &entry->psq;
if (pktq_full(pq) || pktq_pfull(pq, prec)) {
*qfull_stat += 1;
return -ENFILE;
}
queue = &pq->q[prec].skblist;
p_head = skb_peek(queue);
p_tail = skb_peek_tail(queue);
fr_new = brcmf_skb_htod_tag_get_field(p, FREERUN);
while (p_head != p_tail) {
fr_compare = brcmf_skb_htod_tag_get_field(p_tail,
FREERUN);
if (((fr_new > fr_compare) &&
((fr_new - fr_compare) < 128)) ||
((fr_new < fr_compare) &&
((fr_compare - fr_new) > 128)))
break;
p_tail = skb_queue_prev(queue, p_tail);
}
if (p_tail == NULL) {
__skb_queue_tail(queue, p);
} else {
fr_compare = brcmf_skb_htod_tag_get_field(p_tail,
FREERUN);
if (((fr_new > fr_compare) &&
((fr_new - fr_compare) < 128)) ||
((fr_new < fr_compare) &&
((fr_compare - fr_new) > 128))) {
__skb_queue_after(queue, p_tail, p);
} else {
__skb_insert(p, p_tail->prev, p_tail, queue);
}
}
pq->len++;
if (pq->hi_prec < prec)
pq->hi_prec = (u8) prec;
} else if (brcmu_pktq_penq(&entry->psq, prec, p) == NULL) {
*qfull_stat += 1;
return -ENFILE;
}
fws->fifo_delay_map |= 1 << fifo;
fws->fifo_enqpkt[fifo]++;
brcmf_skbcb(p)->state = state;
brcmf_fws_tim_update(fws, entry, fifo, true);
brcmf_fws_flow_control_check(fws, &entry->psq,
brcmf_skb_if_flags_get_field(p, INDEX));
return 0;
}
static struct sk_buff *brcmf_fws_deq(struct brcmf_fws_info *fws, int fifo)
{
struct brcmf_fws_mac_descriptor *table;
struct brcmf_fws_mac_descriptor *entry;
struct sk_buff *p;
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
brcmf_fws_macdesc_closed(fws, entry, fifo))
continue;
if (entry->suppressed)
pmsk = 2;
else
pmsk = 3;
p = brcmu_pktq_mdeq(&entry->psq, pmsk << (fifo * 2), &prec_out);
if (p == NULL) {
if (entry->suppressed) {
if (entry->suppr_transit_count)
continue;
entry->suppressed = false;
p = brcmu_pktq_mdeq(&entry->psq,
1 << (fifo * 2), &prec_out);
}
}
if (p == NULL)
continue;
brcmf_fws_macdesc_use_req_credit(entry, p);
fws->deq_node_pos[fifo] = (node_pos + i + 1) % num_nodes;
brcmf_fws_flow_control_check(fws, &entry->psq,
brcmf_skb_if_flags_get_field(p,
INDEX)
);
brcmf_fws_tim_update(fws, entry, fifo, false);
fws->fifo_enqpkt[fifo]--;
if (fws->fifo_enqpkt[fifo] == 0)
fws->fifo_delay_map &= ~(1 << fifo);
goto done;
}
p = NULL;
done:
brcmf_dbg(DATA, "exit: fifo %d skb %p\n", fifo, p);
return p;
}
static int brcmf_fws_txstatus_suppressed(struct brcmf_fws_info *fws, int fifo,
struct sk_buff *skb,
u32 genbit, u16 seq)
{
struct brcmf_fws_mac_descriptor *entry = brcmf_skbcb(skb)->mac;
u32 hslot;
int ret;
hslot = brcmf_skb_htod_tag_get_field(skb, HSLOT);
if (!entry->suppressed) {
entry->suppressed = true;
entry->suppr_transit_count = entry->transit_count;
brcmf_dbg(DATA, "suppress %s: transit %d\n",
entry->name, entry->transit_count);
}
entry->generation = genbit;
brcmf_skb_htod_tag_set_field(skb, GENERATION, genbit);
brcmf_skbcb(skb)->htod_seq = seq;
if (brcmf_skb_htod_seq_get_field(skb, FROMFW)) {
brcmf_skb_htod_seq_set_field(skb, FROMDRV, 1);
brcmf_skb_htod_seq_set_field(skb, FROMFW, 0);
} else {
brcmf_skb_htod_seq_set_field(skb, FROMDRV, 0);
}
ret = brcmf_fws_enq(fws, BRCMF_FWS_SKBSTATE_SUPPRESSED, fifo, skb);
if (ret != 0) {
brcmf_fws_hanger_poppkt(&fws->hanger, hslot, &skb, true);
} else {
brcmf_fws_hanger_mark_suppressed(&fws->hanger, hslot);
}
return ret;
}
static int
brcmf_fws_txs_process(struct brcmf_fws_info *fws, u8 flags, u32 hslot,
u32 genbit, u16 seq)
{
u32 fifo;
int ret;
bool remove_from_hanger = true;
struct sk_buff *skb;
struct brcmf_skbuff_cb *skcb;
struct brcmf_fws_mac_descriptor *entry = NULL;
struct brcmf_if *ifp;
brcmf_dbg(DATA, "flags %d\n", flags);
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
else if (flags == BRCMF_FWS_TXSTATUS_HOST_TOSSED)
fws->stats.txs_host_tossed++;
else
brcmf_err("unexpected txstatus\n");
ret = brcmf_fws_hanger_poppkt(&fws->hanger, hslot, &skb,
remove_from_hanger);
if (ret != 0) {
brcmf_err("no packet in hanger slot: hslot=%d\n", hslot);
return ret;
}
skcb = brcmf_skbcb(skb);
entry = skcb->mac;
if (WARN_ON(!entry)) {
brcmu_pkt_buf_free_skb(skb);
return -EINVAL;
}
entry->transit_count--;
if (entry->suppressed && entry->suppr_transit_count)
entry->suppr_transit_count--;
brcmf_dbg(DATA, "%s flags %d htod %X seq %X\n", entry->name, flags,
skcb->htod, seq);
fifo = brcmf_skb_htod_tag_get_field(skb, FIFO);
if ((fws->fcmode == BRCMF_FWS_FCMODE_IMPLIED_CREDIT) ||
(brcmf_skb_if_flags_get_field(skb, REQ_CREDIT)) ||
(flags == BRCMF_FWS_TXSTATUS_HOST_TOSSED)) {
brcmf_fws_return_credits(fws, fifo, 1);
brcmf_fws_schedule_deq(fws);
}
brcmf_fws_macdesc_return_req_credit(skb);
ret = brcmf_proto_hdrpull(fws->drvr, false, skb, &ifp);
if (ret) {
brcmu_pkt_buf_free_skb(skb);
return -EINVAL;
}
if (!remove_from_hanger)
ret = brcmf_fws_txstatus_suppressed(fws, fifo, skb,
genbit, seq);
if (remove_from_hanger || ret)
brcmf_txfinalize(ifp, skb, true);
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
brcmf_dbg(DATA, "enter: data %pM\n", data);
brcmf_fws_lock(fws);
for (i = 0; i < BRCMF_FWS_FIFO_COUNT; i++)
brcmf_fws_return_credits(fws, i, data[i]);
brcmf_dbg(DATA, "map: credit %x delay %x\n", fws->fifo_credit_map,
fws->fifo_delay_map);
brcmf_fws_unlock(fws);
return BRCMF_FWS_RET_OK_SCHEDULE;
}
static int brcmf_fws_txstatus_indicate(struct brcmf_fws_info *fws, u8 *data)
{
__le32 status_le;
__le16 seq_le;
u32 status;
u32 hslot;
u32 genbit;
u8 flags;
u16 seq;
fws->stats.txs_indicate++;
memcpy(&status_le, data, sizeof(status_le));
status = le32_to_cpu(status_le);
flags = brcmf_txstatus_get_field(status, FLAGS);
hslot = brcmf_txstatus_get_field(status, HSLOT);
genbit = brcmf_txstatus_get_field(status, GENERATION);
if (BRCMF_FWS_MODE_GET_REUSESEQ(fws->mode)) {
memcpy(&seq_le, &data[BRCMF_FWS_TYPE_PKTTAG_LEN],
sizeof(seq_le));
seq = le16_to_cpu(seq_le);
} else {
seq = 0;
}
brcmf_fws_lock(fws);
brcmf_fws_txs_process(fws, flags, hslot, genbit, seq);
brcmf_fws_unlock(fws);
return BRCMF_FWS_RET_OK_NOSCHEDULE;
}
static int brcmf_fws_dbg_seqnum_check(struct brcmf_fws_info *fws, u8 *data)
{
__le32 timestamp;
memcpy(&timestamp, &data[2], sizeof(timestamp));
brcmf_dbg(CTL, "received: seq %d, timestamp %d\n", data[1],
le32_to_cpu(timestamp));
return 0;
}
static int brcmf_fws_notify_credit_map(struct brcmf_if *ifp,
const struct brcmf_event_msg *e,
void *data)
{
struct brcmf_fws_info *fws = ifp->drvr->fws;
int i;
u8 *credits = data;
if (e->datalen < BRCMF_FWS_FIFO_COUNT) {
brcmf_err("event payload too small (%d)\n", e->datalen);
return -EINVAL;
}
if (fws->creditmap_received)
return 0;
fws->creditmap_received = true;
brcmf_dbg(TRACE, "enter: credits %pM\n", credits);
brcmf_fws_lock(fws);
for (i = 0; i < ARRAY_SIZE(fws->fifo_credit); i++) {
if (*credits)
fws->fifo_credit_map |= 1 << i;
else
fws->fifo_credit_map &= ~(1 << i);
fws->fifo_credit[i] = *credits++;
}
brcmf_fws_schedule_deq(fws);
brcmf_fws_unlock(fws);
return 0;
}
static int brcmf_fws_notify_bcmc_credit_support(struct brcmf_if *ifp,
const struct brcmf_event_msg *e,
void *data)
{
struct brcmf_fws_info *fws = ifp->drvr->fws;
brcmf_fws_lock(fws);
if (fws)
fws->bcmc_credit_check = true;
brcmf_fws_unlock(fws);
return 0;
}
void brcmf_fws_hdrpull(struct brcmf_if *ifp, s16 siglen, struct sk_buff *skb)
{
struct brcmf_skb_reorder_data *rd;
struct brcmf_fws_info *fws = ifp->drvr->fws;
u8 *signal_data;
s16 data_len;
u8 type;
u8 len;
u8 *data;
s32 status;
s32 err;
brcmf_dbg(HDRS, "enter: ifidx %d, skblen %u, sig %d\n",
ifp->ifidx, skb->len, siglen);
WARN_ON(siglen > skb->len);
if (!siglen)
return;
if ((!fws) || (!fws->fw_signals)) {
skb_pull(skb, siglen);
return;
}
fws->stats.header_pulls++;
data_len = siglen;
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
brcmf_dbg(HDRS, "tlv type=%s (%d), len=%d (%d)\n",
brcmf_fws_get_tlv_name(type), type, len,
brcmf_fws_get_tlv_len(fws, type));
if (data_len < len + 2)
break;
if (len < brcmf_fws_get_tlv_len(fws, type))
break;
err = BRCMF_FWS_RET_OK_NOSCHEDULE;
switch (type) {
case BRCMF_FWS_TYPE_COMP_TXSTATUS:
break;
case BRCMF_FWS_TYPE_HOST_REORDER_RXPKTS:
rd = (struct brcmf_skb_reorder_data *)skb->cb;
rd->reorder = data;
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
skb_pull(skb, siglen);
if (skb->len == 0)
fws->stats.header_only_pkt++;
}
static u8 brcmf_fws_precommit_skb(struct brcmf_fws_info *fws, int fifo,
struct sk_buff *p)
{
struct brcmf_skbuff_cb *skcb = brcmf_skbcb(p);
struct brcmf_fws_mac_descriptor *entry = skcb->mac;
u8 flags;
if (skcb->state != BRCMF_FWS_SKBSTATE_SUPPRESSED)
brcmf_skb_htod_tag_set_field(p, GENERATION, entry->generation);
flags = BRCMF_FWS_HTOD_FLAG_PKTFROMHOST;
if (brcmf_skb_if_flags_get_field(p, REQUESTED)) {
flags |= BRCMF_FWS_HTOD_FLAG_PKT_REQUESTED;
}
brcmf_skb_htod_tag_set_field(p, FLAGS, flags);
return brcmf_fws_hdrpush(fws, p);
}
static void brcmf_fws_rollback_toq(struct brcmf_fws_info *fws,
struct sk_buff *skb, int fifo)
{
struct brcmf_fws_mac_descriptor *entry;
struct sk_buff *pktout;
int qidx, hslot;
int rc = 0;
entry = brcmf_skbcb(skb)->mac;
if (entry->occupied) {
qidx = 2 * fifo;
if (brcmf_skbcb(skb)->state == BRCMF_FWS_SKBSTATE_SUPPRESSED)
qidx++;
pktout = brcmu_pktq_penq_head(&entry->psq, qidx, skb);
if (pktout == NULL) {
brcmf_err("%s queue %d full\n", entry->name, qidx);
rc = -ENOSPC;
}
} else {
brcmf_err("%s entry removed\n", entry->name);
rc = -ENOENT;
}
if (rc) {
fws->stats.rollback_failed++;
hslot = brcmf_skb_htod_tag_get_field(skb, HSLOT);
brcmf_fws_txs_process(fws, BRCMF_FWS_TXSTATUS_HOST_TOSSED,
hslot, 0, 0);
} else {
fws->stats.rollback_success++;
brcmf_fws_return_credits(fws, fifo, 1);
brcmf_fws_macdesc_return_req_credit(skb);
}
}
static int brcmf_fws_borrow_credit(struct brcmf_fws_info *fws)
{
int lender_ac;
if (time_after(fws->borrow_defer_timestamp, jiffies)) {
fws->fifo_credit_map &= ~(1 << BRCMF_FWS_FIFO_AC_BE);
return -ENAVAIL;
}
for (lender_ac = 0; lender_ac <= BRCMF_FWS_FIFO_AC_VO; lender_ac++) {
if (fws->fifo_credit[lender_ac]) {
fws->credits_borrowed[lender_ac]++;
fws->fifo_credit[lender_ac]--;
if (fws->fifo_credit[lender_ac] == 0)
fws->fifo_credit_map &= ~(1 << lender_ac);
fws->fifo_credit_map |= (1 << BRCMF_FWS_FIFO_AC_BE);
brcmf_dbg(DATA, "borrow credit from: %d\n", lender_ac);
return 0;
}
}
fws->fifo_credit_map &= ~(1 << BRCMF_FWS_FIFO_AC_BE);
return -ENAVAIL;
}
static int brcmf_fws_commit_skb(struct brcmf_fws_info *fws, int fifo,
struct sk_buff *skb)
{
struct brcmf_skbuff_cb *skcb = brcmf_skbcb(skb);
struct brcmf_fws_mac_descriptor *entry;
int rc;
u8 ifidx;
u8 data_offset;
entry = skcb->mac;
if (IS_ERR(entry))
return PTR_ERR(entry);
data_offset = brcmf_fws_precommit_skb(fws, fifo, skb);
entry->transit_count++;
if (entry->suppressed)
entry->suppr_transit_count++;
ifidx = brcmf_skb_if_flags_get_field(skb, INDEX);
brcmf_fws_unlock(fws);
rc = brcmf_proto_txdata(fws->drvr, ifidx, data_offset, skb);
brcmf_fws_lock(fws);
brcmf_dbg(DATA, "%s flags %X htod %X bus_tx %d\n", entry->name,
skcb->if_flags, skcb->htod, rc);
if (rc < 0) {
entry->transit_count--;
if (entry->suppressed)
entry->suppr_transit_count--;
(void)brcmf_proto_hdrpull(fws->drvr, false, skb, NULL);
goto rollback;
}
fws->stats.pkt2bus++;
fws->stats.send_pkts[fifo]++;
if (brcmf_skb_if_flags_get_field(skb, REQUESTED))
fws->stats.requested_sent[fifo]++;
return rc;
rollback:
brcmf_fws_rollback_toq(fws, skb, fifo);
return rc;
}
static int brcmf_fws_assign_htod(struct brcmf_fws_info *fws, struct sk_buff *p,
int fifo)
{
struct brcmf_skbuff_cb *skcb = brcmf_skbcb(p);
int rc, hslot;
skcb->htod = 0;
skcb->htod_seq = 0;
hslot = brcmf_fws_hanger_get_free_slot(&fws->hanger);
brcmf_skb_htod_tag_set_field(p, HSLOT, hslot);
brcmf_skb_htod_tag_set_field(p, FREERUN, skcb->mac->seq[fifo]);
brcmf_skb_htod_tag_set_field(p, FIFO, fifo);
rc = brcmf_fws_hanger_pushpkt(&fws->hanger, p, hslot);
if (!rc)
skcb->mac->seq[fifo]++;
else
fws->stats.generic_error++;
return rc;
}
int brcmf_fws_process_skb(struct brcmf_if *ifp, struct sk_buff *skb)
{
struct brcmf_pub *drvr = ifp->drvr;
struct brcmf_fws_info *fws = drvr->fws;
struct brcmf_skbuff_cb *skcb = brcmf_skbcb(skb);
struct ethhdr *eh = (struct ethhdr *)(skb->data);
int fifo = BRCMF_FWS_FIFO_BCMC;
bool multicast = is_multicast_ether_addr(eh->h_dest);
int rc = 0;
brcmf_dbg(DATA, "tx proto=0x%X\n", ntohs(eh->h_proto));
if (!skb->priority)
skb->priority = cfg80211_classify8021d(skb, NULL);
drvr->tx_multicast += !!multicast;
if (fws->avoid_queueing) {
rc = brcmf_proto_txdata(drvr, ifp->ifidx, 0, skb);
if (rc < 0)
brcmf_txfinalize(ifp, skb, false);
return rc;
}
skcb->if_flags = 0;
skcb->state = BRCMF_FWS_SKBSTATE_NEW;
brcmf_skb_if_flags_set_field(skb, INDEX, ifp->ifidx);
if (!multicast)
fifo = brcmf_fws_prio2fifo[skb->priority];
brcmf_fws_lock(fws);
if (fifo != BRCMF_FWS_FIFO_AC_BE && fifo < BRCMF_FWS_FIFO_BCMC)
fws->borrow_defer_timestamp = jiffies +
BRCMF_FWS_BORROW_DEFER_PERIOD;
skcb->mac = brcmf_fws_macdesc_find(fws, ifp, eh->h_dest);
brcmf_dbg(DATA, "%s mac %pM multi %d fifo %d\n", skcb->mac->name,
eh->h_dest, multicast, fifo);
if (!brcmf_fws_assign_htod(fws, skb, fifo)) {
brcmf_fws_enq(fws, BRCMF_FWS_SKBSTATE_DELAYED, fifo, skb);
brcmf_fws_schedule_deq(fws);
} else {
brcmf_err("drop skb: no hanger slot\n");
brcmf_txfinalize(ifp, skb, false);
rc = -ENOMEM;
}
brcmf_fws_unlock(fws);
return rc;
}
void brcmf_fws_reset_interface(struct brcmf_if *ifp)
{
struct brcmf_fws_mac_descriptor *entry = ifp->fws_desc;
brcmf_dbg(TRACE, "enter: idx=%d\n", ifp->bssidx);
if (!entry)
return;
brcmf_fws_macdesc_init(entry, ifp->mac_addr, ifp->ifidx);
}
void brcmf_fws_add_interface(struct brcmf_if *ifp)
{
struct brcmf_fws_info *fws = ifp->drvr->fws;
struct brcmf_fws_mac_descriptor *entry;
if (!ifp->ndev)
return;
entry = &fws->desc.iface[ifp->ifidx];
ifp->fws_desc = entry;
brcmf_fws_macdesc_init(entry, ifp->mac_addr, ifp->ifidx);
brcmf_fws_macdesc_set_name(fws, entry);
brcmu_pktq_init(&entry->psq, BRCMF_FWS_PSQ_PREC_COUNT,
BRCMF_FWS_PSQ_LEN);
brcmf_dbg(TRACE, "added %s\n", entry->name);
}
void brcmf_fws_del_interface(struct brcmf_if *ifp)
{
struct brcmf_fws_mac_descriptor *entry = ifp->fws_desc;
if (!entry)
return;
brcmf_fws_lock(ifp->drvr->fws);
ifp->fws_desc = NULL;
brcmf_dbg(TRACE, "deleting %s\n", entry->name);
brcmf_fws_macdesc_deinit(entry);
brcmf_fws_cleanup(ifp->drvr->fws, ifp->ifidx);
brcmf_fws_unlock(ifp->drvr->fws);
}
static void brcmf_fws_dequeue_worker(struct work_struct *worker)
{
struct brcmf_fws_info *fws;
struct brcmf_pub *drvr;
struct sk_buff *skb;
int fifo;
u32 hslot;
u32 ifidx;
int ret;
fws = container_of(worker, struct brcmf_fws_info, fws_dequeue_work);
drvr = fws->drvr;
brcmf_fws_lock(fws);
for (fifo = BRCMF_FWS_FIFO_BCMC; fifo >= 0 && !fws->bus_flow_blocked;
fifo--) {
if (!brcmf_fws_fc_active(fws)) {
while ((skb = brcmf_fws_deq(fws, fifo)) != NULL) {
hslot = brcmf_skb_htod_tag_get_field(skb,
HSLOT);
brcmf_fws_hanger_poppkt(&fws->hanger, hslot,
&skb, true);
ifidx = brcmf_skb_if_flags_get_field(skb,
INDEX);
brcmf_fws_unlock(fws);
ret = brcmf_proto_txdata(drvr, ifidx, 0, skb);
brcmf_fws_lock(fws);
if (ret < 0)
brcmf_txfinalize(brcmf_get_ifp(drvr,
ifidx),
skb, false);
if (fws->bus_flow_blocked)
break;
}
continue;
}
while ((fws->fifo_credit[fifo]) || ((!fws->bcmc_credit_check) &&
(fifo == BRCMF_FWS_FIFO_BCMC))) {
skb = brcmf_fws_deq(fws, fifo);
if (!skb)
break;
fws->fifo_credit[fifo]--;
if (brcmf_fws_commit_skb(fws, fifo, skb))
break;
if (fws->bus_flow_blocked)
break;
}
if ((fifo == BRCMF_FWS_FIFO_AC_BE) &&
(fws->fifo_credit[fifo] == 0) &&
(!fws->bus_flow_blocked)) {
while (brcmf_fws_borrow_credit(fws) == 0) {
skb = brcmf_fws_deq(fws, fifo);
if (!skb) {
brcmf_fws_return_credits(fws, fifo, 1);
break;
}
if (brcmf_fws_commit_skb(fws, fifo, skb))
break;
if (fws->bus_flow_blocked)
break;
}
}
}
brcmf_fws_unlock(fws);
}
static int brcmf_debugfs_fws_stats_read(struct seq_file *seq, void *data)
{
struct brcmf_bus *bus_if = dev_get_drvdata(seq->private);
struct brcmf_fws_stats *fwstats = &bus_if->drvr->fws->stats;
seq_printf(seq,
"header_pulls: %u\n"
"header_only_pkt: %u\n"
"tlv_parse_failed: %u\n"
"tlv_invalid_type: %u\n"
"mac_update_fails: %u\n"
"ps_update_fails: %u\n"
"if_update_fails: %u\n"
"pkt2bus: %u\n"
"generic_error: %u\n"
"rollback_success: %u\n"
"rollback_failed: %u\n"
"delayq_full: %u\n"
"supprq_full: %u\n"
"txs_indicate: %u\n"
"txs_discard: %u\n"
"txs_suppr_core: %u\n"
"txs_suppr_ps: %u\n"
"txs_tossed: %u\n"
"txs_host_tossed: %u\n"
"bus_flow_block: %u\n"
"fws_flow_block: %u\n"
"send_pkts: BK:%u BE:%u VO:%u VI:%u BCMC:%u\n"
"requested_sent: BK:%u BE:%u VO:%u VI:%u BCMC:%u\n",
fwstats->header_pulls,
fwstats->header_only_pkt,
fwstats->tlv_parse_failed,
fwstats->tlv_invalid_type,
fwstats->mac_update_failed,
fwstats->mac_ps_update_failed,
fwstats->if_update_failed,
fwstats->pkt2bus,
fwstats->generic_error,
fwstats->rollback_success,
fwstats->rollback_failed,
fwstats->delayq_full_error,
fwstats->supprq_full_error,
fwstats->txs_indicate,
fwstats->txs_discard,
fwstats->txs_supp_core,
fwstats->txs_supp_ps,
fwstats->txs_tossed,
fwstats->txs_host_tossed,
fwstats->bus_flow_block,
fwstats->fws_flow_block,
fwstats->send_pkts[0], fwstats->send_pkts[1],
fwstats->send_pkts[2], fwstats->send_pkts[3],
fwstats->send_pkts[4],
fwstats->requested_sent[0],
fwstats->requested_sent[1],
fwstats->requested_sent[2],
fwstats->requested_sent[3],
fwstats->requested_sent[4]);
return 0;
}
static int brcmf_debugfs_fws_stats_read(struct seq_file *seq, void *data)
{
return 0;
}
int brcmf_fws_init(struct brcmf_pub *drvr)
{
struct brcmf_fws_info *fws;
struct brcmf_if *ifp;
u32 tlv = BRCMF_FWS_FLAGS_RSSI_SIGNALS;
int rc;
u32 mode;
drvr->fws = kzalloc(sizeof(*(drvr->fws)), GFP_KERNEL);
if (!drvr->fws) {
rc = -ENOMEM;
goto fail;
}
fws = drvr->fws;
spin_lock_init(&fws->spinlock);
fws->drvr = drvr;
fws->fcmode = fcmode;
if ((drvr->bus_if->always_use_fws_queue == false) &&
(fcmode == BRCMF_FWS_FCMODE_NONE)) {
fws->avoid_queueing = true;
brcmf_dbg(INFO, "FWS queueing will be avoided\n");
return 0;
}
fws->fws_wq = create_singlethread_workqueue("brcmf_fws_wq");
if (fws->fws_wq == NULL) {
brcmf_err("workqueue creation failed\n");
rc = -EBADF;
goto fail;
}
INIT_WORK(&fws->fws_dequeue_work, brcmf_fws_dequeue_worker);
if (fws->fcmode != BRCMF_FWS_FCMODE_NONE)
tlv |= BRCMF_FWS_FLAGS_XONXOFF_SIGNALS |
BRCMF_FWS_FLAGS_CREDIT_STATUS_SIGNALS |
BRCMF_FWS_FLAGS_HOST_PROPTXSTATUS_ACTIVE |
BRCMF_FWS_FLAGS_HOST_RXREORDER_ACTIVE;
rc = brcmf_fweh_register(drvr, BRCMF_E_FIFO_CREDIT_MAP,
brcmf_fws_notify_credit_map);
if (rc < 0) {
brcmf_err("register credit map handler failed\n");
goto fail;
}
rc = brcmf_fweh_register(drvr, BRCMF_E_BCMC_CREDIT_SUPPORT,
brcmf_fws_notify_bcmc_credit_support);
if (rc < 0) {
brcmf_err("register bcmc credit handler failed\n");
brcmf_fweh_unregister(drvr, BRCMF_E_FIFO_CREDIT_MAP);
goto fail;
}
fws->fw_signals = true;
ifp = brcmf_get_ifp(drvr, 0);
if (brcmf_fil_iovar_int_set(ifp, "tlv", tlv)) {
brcmf_err("failed to set bdcv2 tlv signaling\n");
fws->fcmode = BRCMF_FWS_FCMODE_NONE;
fws->fw_signals = false;
}
if (brcmf_fil_iovar_int_set(ifp, "ampdu_hostreorder", 1))
brcmf_dbg(INFO, "enabling AMPDU host-reorder failed\n");
if (brcmf_fil_iovar_int_get(ifp, "wlfc_mode", &mode) == 0) {
if (BRCMF_FWS_MODE_GET_REUSESEQ(mode)) {
mode = 0;
BRCMF_FWS_MODE_SET_REUSESEQ(mode, 1);
if (brcmf_fil_iovar_int_set(ifp,
"wlfc_mode", mode) == 0) {
BRCMF_FWS_MODE_SET_REUSESEQ(fws->mode, 1);
}
}
}
brcmf_fws_hanger_init(&fws->hanger);
brcmf_fws_macdesc_init(&fws->desc.other, NULL, 0);
brcmf_fws_macdesc_set_name(fws, &fws->desc.other);
brcmu_pktq_init(&fws->desc.other.psq, BRCMF_FWS_PSQ_PREC_COUNT,
BRCMF_FWS_PSQ_LEN);
brcmf_debugfs_add_entry(drvr, "fws_stats",
brcmf_debugfs_fws_stats_read);
brcmf_dbg(INFO, "%s bdcv2 tlv signaling [%x]\n",
fws->fw_signals ? "enabled" : "disabled", tlv);
return 0;
fail:
brcmf_fws_deinit(drvr);
return rc;
}
void brcmf_fws_deinit(struct brcmf_pub *drvr)
{
struct brcmf_fws_info *fws = drvr->fws;
if (!fws)
return;
if (drvr->fws->fws_wq)
destroy_workqueue(drvr->fws->fws_wq);
brcmf_fws_lock(fws);
brcmf_fws_cleanup(fws, -1);
drvr->fws = NULL;
brcmf_fws_unlock(fws);
kfree(fws);
}
bool brcmf_fws_fc_active(struct brcmf_fws_info *fws)
{
if (!fws->creditmap_received)
return false;
return fws->fcmode != BRCMF_FWS_FCMODE_NONE;
}
void brcmf_fws_bustxfail(struct brcmf_fws_info *fws, struct sk_buff *skb)
{
u32 hslot;
if (brcmf_skbcb(skb)->state == BRCMF_FWS_SKBSTATE_TIM) {
brcmu_pkt_buf_free_skb(skb);
return;
}
brcmf_fws_lock(fws);
hslot = brcmf_skb_htod_tag_get_field(skb, HSLOT);
brcmf_fws_txs_process(fws, BRCMF_FWS_TXSTATUS_HOST_TOSSED, hslot, 0, 0);
brcmf_fws_unlock(fws);
}
void brcmf_fws_bus_blocked(struct brcmf_pub *drvr, bool flow_blocked)
{
struct brcmf_fws_info *fws = drvr->fws;
fws->bus_flow_blocked = flow_blocked;
if (!flow_blocked)
brcmf_fws_schedule_deq(fws);
else
fws->stats.bus_flow_block++;
}
