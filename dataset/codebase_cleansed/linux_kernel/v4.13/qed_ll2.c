static void qed_ll2b_complete_tx_packet(void *cxt,
u8 connection_handle,
void *cookie,
dma_addr_t first_frag_addr,
bool b_last_fragment,
bool b_last_packet)
{
struct qed_hwfn *p_hwfn = cxt;
struct qed_dev *cdev = p_hwfn->cdev;
struct sk_buff *skb = cookie;
dma_unmap_single(&p_hwfn->cdev->pdev->dev, first_frag_addr,
skb_headlen(skb), DMA_TO_DEVICE);
if (cdev->ll2->cbs && cdev->ll2->cbs->tx_cb)
cdev->ll2->cbs->tx_cb(cdev->ll2->cb_cookie, skb,
b_last_fragment);
dev_kfree_skb_any(skb);
}
static int qed_ll2_alloc_buffer(struct qed_dev *cdev,
u8 **data, dma_addr_t *phys_addr)
{
*data = kmalloc(cdev->ll2->rx_size, GFP_ATOMIC);
if (!(*data)) {
DP_INFO(cdev, "Failed to allocate LL2 buffer data\n");
return -ENOMEM;
}
*phys_addr = dma_map_single(&cdev->pdev->dev,
((*data) + NET_SKB_PAD),
cdev->ll2->rx_size, DMA_FROM_DEVICE);
if (dma_mapping_error(&cdev->pdev->dev, *phys_addr)) {
DP_INFO(cdev, "Failed to map LL2 buffer data\n");
kfree((*data));
return -ENOMEM;
}
return 0;
}
static int qed_ll2_dealloc_buffer(struct qed_dev *cdev,
struct qed_ll2_buffer *buffer)
{
spin_lock_bh(&cdev->ll2->lock);
dma_unmap_single(&cdev->pdev->dev, buffer->phys_addr,
cdev->ll2->rx_size, DMA_FROM_DEVICE);
kfree(buffer->data);
list_del(&buffer->list);
cdev->ll2->rx_cnt--;
if (!cdev->ll2->rx_cnt)
DP_INFO(cdev, "All LL2 entries were removed\n");
spin_unlock_bh(&cdev->ll2->lock);
return 0;
}
static void qed_ll2_kill_buffers(struct qed_dev *cdev)
{
struct qed_ll2_buffer *buffer, *tmp_buffer;
list_for_each_entry_safe(buffer, tmp_buffer, &cdev->ll2->list, list)
qed_ll2_dealloc_buffer(cdev, buffer);
}
void qed_ll2b_complete_rx_packet(void *cxt, struct qed_ll2_comp_rx_data *data)
{
struct qed_hwfn *p_hwfn = cxt;
struct qed_ll2_buffer *buffer = data->cookie;
struct qed_dev *cdev = p_hwfn->cdev;
dma_addr_t new_phys_addr;
struct sk_buff *skb;
bool reuse = false;
int rc = -EINVAL;
u8 *new_data;
DP_VERBOSE(p_hwfn,
(NETIF_MSG_RX_STATUS | QED_MSG_STORAGE | NETIF_MSG_PKTDATA),
"Got an LL2 Rx completion: [Buffer at phys 0x%llx, offset 0x%02x] Length 0x%04x Parse_flags 0x%04x vlan 0x%04x Opaque data [0x%08x:0x%08x]\n",
(u64)data->rx_buf_addr,
data->u.placement_offset,
data->length.packet_length,
data->parse_flags,
data->vlan, data->opaque_data_0, data->opaque_data_1);
if ((cdev->dp_module & NETIF_MSG_PKTDATA) && buffer->data) {
print_hex_dump(KERN_INFO, "",
DUMP_PREFIX_OFFSET, 16, 1,
buffer->data, data->length.packet_length, false);
}
if (data->length.packet_length < ETH_HLEN)
reuse = true;
if (!reuse)
rc = qed_ll2_alloc_buffer(p_hwfn->cdev, &new_data,
&new_phys_addr);
if (rc)
goto out_post;
dma_unmap_single(&cdev->pdev->dev, buffer->phys_addr,
cdev->ll2->rx_size, DMA_FROM_DEVICE);
skb = build_skb(buffer->data, 0);
if (!skb) {
rc = -ENOMEM;
goto out_post;
}
data->u.placement_offset += NET_SKB_PAD;
skb_reserve(skb, data->u.placement_offset);
skb_put(skb, data->length.packet_length);
skb_checksum_none_assert(skb);
skb_reset_mac_header(skb);
skb->protocol = eth_hdr(skb)->h_proto;
if (cdev->ll2->cbs && cdev->ll2->cbs->rx_cb) {
if (data->vlan)
__vlan_hwaccel_put_tag(skb, htons(ETH_P_8021Q),
data->vlan);
cdev->ll2->cbs->rx_cb(cdev->ll2->cb_cookie, skb,
data->opaque_data_0,
data->opaque_data_1);
}
buffer->data = new_data;
buffer->phys_addr = new_phys_addr;
out_post:
rc = qed_ll2_post_rx_buffer(QED_LEADING_HWFN(cdev), cdev->ll2->handle,
buffer->phys_addr, 0, buffer, 1);
if (rc)
qed_ll2_dealloc_buffer(cdev, buffer);
}
static struct qed_ll2_info *__qed_ll2_handle_sanity(struct qed_hwfn *p_hwfn,
u8 connection_handle,
bool b_lock,
bool b_only_active)
{
struct qed_ll2_info *p_ll2_conn, *p_ret = NULL;
if (connection_handle >= QED_MAX_NUM_OF_LL2_CONNECTIONS)
return NULL;
if (!p_hwfn->p_ll2_info)
return NULL;
p_ll2_conn = &p_hwfn->p_ll2_info[connection_handle];
if (b_only_active) {
if (b_lock)
mutex_lock(&p_ll2_conn->mutex);
if (p_ll2_conn->b_active)
p_ret = p_ll2_conn;
if (b_lock)
mutex_unlock(&p_ll2_conn->mutex);
} else {
p_ret = p_ll2_conn;
}
return p_ret;
}
static struct qed_ll2_info *qed_ll2_handle_sanity(struct qed_hwfn *p_hwfn,
u8 connection_handle)
{
return __qed_ll2_handle_sanity(p_hwfn, connection_handle, false, true);
}
static struct qed_ll2_info *qed_ll2_handle_sanity_lock(struct qed_hwfn *p_hwfn,
u8 connection_handle)
{
return __qed_ll2_handle_sanity(p_hwfn, connection_handle, true, true);
}
static struct qed_ll2_info *qed_ll2_handle_sanity_inactive(struct qed_hwfn
*p_hwfn,
u8 connection_handle)
{
return __qed_ll2_handle_sanity(p_hwfn, connection_handle, false, false);
}
static void qed_ll2_txq_flush(struct qed_hwfn *p_hwfn, u8 connection_handle)
{
bool b_last_packet = false, b_last_frag = false;
struct qed_ll2_tx_packet *p_pkt = NULL;
struct qed_ll2_info *p_ll2_conn;
struct qed_ll2_tx_queue *p_tx;
dma_addr_t tx_frag;
p_ll2_conn = qed_ll2_handle_sanity_inactive(p_hwfn, connection_handle);
if (!p_ll2_conn)
return;
p_tx = &p_ll2_conn->tx_queue;
while (!list_empty(&p_tx->active_descq)) {
p_pkt = list_first_entry(&p_tx->active_descq,
struct qed_ll2_tx_packet, list_entry);
if (!p_pkt)
break;
list_del(&p_pkt->list_entry);
b_last_packet = list_empty(&p_tx->active_descq);
list_add_tail(&p_pkt->list_entry, &p_tx->free_descq);
if (p_ll2_conn->input.conn_type == QED_LL2_TYPE_OOO) {
struct qed_ooo_buffer *p_buffer;
p_buffer = (struct qed_ooo_buffer *)p_pkt->cookie;
qed_ooo_put_free_buffer(p_hwfn, p_hwfn->p_ooo_info,
p_buffer);
} else {
p_tx->cur_completing_packet = *p_pkt;
p_tx->cur_completing_bd_idx = 1;
b_last_frag =
p_tx->cur_completing_bd_idx == p_pkt->bd_used;
tx_frag = p_pkt->bds_set[0].tx_frag;
p_ll2_conn->cbs.tx_release_cb(p_ll2_conn->cbs.cookie,
p_ll2_conn->my_id,
p_pkt->cookie,
tx_frag,
b_last_frag,
b_last_packet);
}
}
}
static int qed_ll2_txq_completion(struct qed_hwfn *p_hwfn, void *p_cookie)
{
struct qed_ll2_info *p_ll2_conn = p_cookie;
struct qed_ll2_tx_queue *p_tx = &p_ll2_conn->tx_queue;
u16 new_idx = 0, num_bds = 0, num_bds_in_packet = 0;
struct qed_ll2_tx_packet *p_pkt;
bool b_last_frag = false;
unsigned long flags;
int rc = -EINVAL;
spin_lock_irqsave(&p_tx->lock, flags);
if (p_tx->b_completing_packet) {
rc = -EBUSY;
goto out;
}
new_idx = le16_to_cpu(*p_tx->p_fw_cons);
num_bds = ((s16)new_idx - (s16)p_tx->bds_idx);
while (num_bds) {
if (list_empty(&p_tx->active_descq))
goto out;
p_pkt = list_first_entry(&p_tx->active_descq,
struct qed_ll2_tx_packet, list_entry);
if (!p_pkt)
goto out;
p_tx->b_completing_packet = true;
p_tx->cur_completing_packet = *p_pkt;
num_bds_in_packet = p_pkt->bd_used;
list_del(&p_pkt->list_entry);
if (num_bds < num_bds_in_packet) {
DP_NOTICE(p_hwfn,
"Rest of BDs does not cover whole packet\n");
goto out;
}
num_bds -= num_bds_in_packet;
p_tx->bds_idx += num_bds_in_packet;
while (num_bds_in_packet--)
qed_chain_consume(&p_tx->txq_chain);
p_tx->cur_completing_bd_idx = 1;
b_last_frag = p_tx->cur_completing_bd_idx == p_pkt->bd_used;
list_add_tail(&p_pkt->list_entry, &p_tx->free_descq);
spin_unlock_irqrestore(&p_tx->lock, flags);
p_ll2_conn->cbs.tx_comp_cb(p_ll2_conn->cbs.cookie,
p_ll2_conn->my_id,
p_pkt->cookie,
p_pkt->bds_set[0].tx_frag,
b_last_frag, !num_bds);
spin_lock_irqsave(&p_tx->lock, flags);
}
p_tx->b_completing_packet = false;
rc = 0;
out:
spin_unlock_irqrestore(&p_tx->lock, flags);
return rc;
}
static void qed_ll2_rxq_parse_gsi(struct qed_hwfn *p_hwfn,
union core_rx_cqe_union *p_cqe,
struct qed_ll2_comp_rx_data *data)
{
data->parse_flags = le16_to_cpu(p_cqe->rx_cqe_gsi.parse_flags.flags);
data->length.data_length = le16_to_cpu(p_cqe->rx_cqe_gsi.data_length);
data->vlan = le16_to_cpu(p_cqe->rx_cqe_gsi.vlan);
data->opaque_data_0 = le32_to_cpu(p_cqe->rx_cqe_gsi.src_mac_addrhi);
data->opaque_data_1 = le16_to_cpu(p_cqe->rx_cqe_gsi.src_mac_addrlo);
data->u.data_length_error = p_cqe->rx_cqe_gsi.data_length_error;
}
static void qed_ll2_rxq_parse_reg(struct qed_hwfn *p_hwfn,
union core_rx_cqe_union *p_cqe,
struct qed_ll2_comp_rx_data *data)
{
data->parse_flags = le16_to_cpu(p_cqe->rx_cqe_fp.parse_flags.flags);
data->length.packet_length =
le16_to_cpu(p_cqe->rx_cqe_fp.packet_length);
data->vlan = le16_to_cpu(p_cqe->rx_cqe_fp.vlan);
data->opaque_data_0 = le32_to_cpu(p_cqe->rx_cqe_fp.opaque_data.data[0]);
data->opaque_data_1 = le32_to_cpu(p_cqe->rx_cqe_fp.opaque_data.data[1]);
data->u.placement_offset = p_cqe->rx_cqe_fp.placement_offset;
}
static int
qed_ll2_rxq_handle_completion(struct qed_hwfn *p_hwfn,
struct qed_ll2_info *p_ll2_conn,
union core_rx_cqe_union *p_cqe,
unsigned long *p_lock_flags, bool b_last_cqe)
{
struct qed_ll2_rx_queue *p_rx = &p_ll2_conn->rx_queue;
struct qed_ll2_rx_packet *p_pkt = NULL;
struct qed_ll2_comp_rx_data data;
if (!list_empty(&p_rx->active_descq))
p_pkt = list_first_entry(&p_rx->active_descq,
struct qed_ll2_rx_packet, list_entry);
if (!p_pkt) {
DP_NOTICE(p_hwfn,
"[%d] LL2 Rx completion but active_descq is empty\n",
p_ll2_conn->input.conn_type);
return -EIO;
}
list_del(&p_pkt->list_entry);
if (p_cqe->rx_cqe_sp.type == CORE_RX_CQE_TYPE_REGULAR)
qed_ll2_rxq_parse_reg(p_hwfn, p_cqe, &data);
else
qed_ll2_rxq_parse_gsi(p_hwfn, p_cqe, &data);
if (qed_chain_consume(&p_rx->rxq_chain) != p_pkt->rxq_bd)
DP_NOTICE(p_hwfn,
"Mismatch between active_descq and the LL2 Rx chain\n");
list_add_tail(&p_pkt->list_entry, &p_rx->free_descq);
data.connection_handle = p_ll2_conn->my_id;
data.cookie = p_pkt->cookie;
data.rx_buf_addr = p_pkt->rx_buf_addr;
data.b_last_packet = b_last_cqe;
spin_unlock_irqrestore(&p_rx->lock, *p_lock_flags);
p_ll2_conn->cbs.rx_comp_cb(p_ll2_conn->cbs.cookie, &data);
spin_lock_irqsave(&p_rx->lock, *p_lock_flags);
return 0;
}
static int qed_ll2_rxq_completion(struct qed_hwfn *p_hwfn, void *cookie)
{
struct qed_ll2_info *p_ll2_conn = (struct qed_ll2_info *)cookie;
struct qed_ll2_rx_queue *p_rx = &p_ll2_conn->rx_queue;
union core_rx_cqe_union *cqe = NULL;
u16 cq_new_idx = 0, cq_old_idx = 0;
unsigned long flags = 0;
int rc = 0;
spin_lock_irqsave(&p_rx->lock, flags);
cq_new_idx = le16_to_cpu(*p_rx->p_fw_cons);
cq_old_idx = qed_chain_get_cons_idx(&p_rx->rcq_chain);
while (cq_new_idx != cq_old_idx) {
bool b_last_cqe = (cq_new_idx == cq_old_idx);
cqe =
(union core_rx_cqe_union *)
qed_chain_consume(&p_rx->rcq_chain);
cq_old_idx = qed_chain_get_cons_idx(&p_rx->rcq_chain);
DP_VERBOSE(p_hwfn,
QED_MSG_LL2,
"LL2 [sw. cons %04x, fw. at %04x] - Got Packet of type %02x\n",
cq_old_idx, cq_new_idx, cqe->rx_cqe_sp.type);
switch (cqe->rx_cqe_sp.type) {
case CORE_RX_CQE_TYPE_SLOW_PATH:
DP_NOTICE(p_hwfn, "LL2 - unexpected Rx CQE slowpath\n");
rc = -EINVAL;
break;
case CORE_RX_CQE_TYPE_GSI_OFFLOAD:
case CORE_RX_CQE_TYPE_REGULAR:
rc = qed_ll2_rxq_handle_completion(p_hwfn, p_ll2_conn,
cqe, &flags,
b_last_cqe);
break;
default:
rc = -EIO;
}
}
spin_unlock_irqrestore(&p_rx->lock, flags);
return rc;
}
static void qed_ll2_rxq_flush(struct qed_hwfn *p_hwfn, u8 connection_handle)
{
struct qed_ll2_info *p_ll2_conn = NULL;
struct qed_ll2_rx_packet *p_pkt = NULL;
struct qed_ll2_rx_queue *p_rx;
p_ll2_conn = qed_ll2_handle_sanity_inactive(p_hwfn, connection_handle);
if (!p_ll2_conn)
return;
p_rx = &p_ll2_conn->rx_queue;
while (!list_empty(&p_rx->active_descq)) {
p_pkt = list_first_entry(&p_rx->active_descq,
struct qed_ll2_rx_packet, list_entry);
if (!p_pkt)
break;
list_move_tail(&p_pkt->list_entry, &p_rx->free_descq);
if (p_ll2_conn->input.conn_type == QED_LL2_TYPE_OOO) {
struct qed_ooo_buffer *p_buffer;
p_buffer = (struct qed_ooo_buffer *)p_pkt->cookie;
qed_ooo_put_free_buffer(p_hwfn, p_hwfn->p_ooo_info,
p_buffer);
} else {
dma_addr_t rx_buf_addr = p_pkt->rx_buf_addr;
void *cookie = p_pkt->cookie;
bool b_last;
b_last = list_empty(&p_rx->active_descq);
p_ll2_conn->cbs.rx_release_cb(p_ll2_conn->cbs.cookie,
p_ll2_conn->my_id,
cookie,
rx_buf_addr, b_last);
}
}
}
static u8 qed_ll2_convert_rx_parse_to_tx_flags(u16 parse_flags)
{
u8 bd_flags = 0;
if (GET_FIELD(parse_flags, PARSING_AND_ERR_FLAGS_TAG8021QEXIST))
SET_FIELD(bd_flags, CORE_TX_BD_DATA_VLAN_INSERTION, 1);
return bd_flags;
}
static int qed_ll2_lb_rxq_handler(struct qed_hwfn *p_hwfn,
struct qed_ll2_info *p_ll2_conn)
{
struct qed_ll2_rx_queue *p_rx = &p_ll2_conn->rx_queue;
u16 packet_length = 0, parse_flags = 0, vlan = 0;
struct qed_ll2_rx_packet *p_pkt = NULL;
u32 num_ooo_add_to_peninsula = 0, cid;
union core_rx_cqe_union *cqe = NULL;
u16 cq_new_idx = 0, cq_old_idx = 0;
struct qed_ooo_buffer *p_buffer;
struct ooo_opaque *iscsi_ooo;
u8 placement_offset = 0;
u8 cqe_type;
cq_new_idx = le16_to_cpu(*p_rx->p_fw_cons);
cq_old_idx = qed_chain_get_cons_idx(&p_rx->rcq_chain);
if (cq_new_idx == cq_old_idx)
return 0;
while (cq_new_idx != cq_old_idx) {
struct core_rx_fast_path_cqe *p_cqe_fp;
cqe = qed_chain_consume(&p_rx->rcq_chain);
cq_old_idx = qed_chain_get_cons_idx(&p_rx->rcq_chain);
cqe_type = cqe->rx_cqe_sp.type;
if (cqe_type != CORE_RX_CQE_TYPE_REGULAR) {
DP_NOTICE(p_hwfn,
"Got a non-regular LB LL2 completion [type 0x%02x]\n",
cqe_type);
return -EINVAL;
}
p_cqe_fp = &cqe->rx_cqe_fp;
placement_offset = p_cqe_fp->placement_offset;
parse_flags = le16_to_cpu(p_cqe_fp->parse_flags.flags);
packet_length = le16_to_cpu(p_cqe_fp->packet_length);
vlan = le16_to_cpu(p_cqe_fp->vlan);
iscsi_ooo = (struct ooo_opaque *)&p_cqe_fp->opaque_data;
qed_ooo_save_history_entry(p_hwfn, p_hwfn->p_ooo_info,
iscsi_ooo);
cid = le32_to_cpu(iscsi_ooo->cid);
if (iscsi_ooo->drop_size)
qed_ooo_delete_isles(p_hwfn, p_hwfn->p_ooo_info, cid,
iscsi_ooo->drop_isle,
iscsi_ooo->drop_size);
if (iscsi_ooo->ooo_opcode == TCP_EVENT_NOP)
continue;
if (list_empty(&p_rx->active_descq)) {
DP_NOTICE(p_hwfn,
"LL2 OOO RX chain has no submitted buffers\n"
);
return -EIO;
}
p_pkt = list_first_entry(&p_rx->active_descq,
struct qed_ll2_rx_packet, list_entry);
if ((iscsi_ooo->ooo_opcode == TCP_EVENT_ADD_NEW_ISLE) ||
(iscsi_ooo->ooo_opcode == TCP_EVENT_ADD_ISLE_RIGHT) ||
(iscsi_ooo->ooo_opcode == TCP_EVENT_ADD_ISLE_LEFT) ||
(iscsi_ooo->ooo_opcode == TCP_EVENT_ADD_PEN) ||
(iscsi_ooo->ooo_opcode == TCP_EVENT_JOIN)) {
if (!p_pkt) {
DP_NOTICE(p_hwfn,
"LL2 OOO RX packet is not valid\n");
return -EIO;
}
list_del(&p_pkt->list_entry);
p_buffer = (struct qed_ooo_buffer *)p_pkt->cookie;
p_buffer->packet_length = packet_length;
p_buffer->parse_flags = parse_flags;
p_buffer->vlan = vlan;
p_buffer->placement_offset = placement_offset;
qed_chain_consume(&p_rx->rxq_chain);
list_add_tail(&p_pkt->list_entry, &p_rx->free_descq);
switch (iscsi_ooo->ooo_opcode) {
case TCP_EVENT_ADD_NEW_ISLE:
qed_ooo_add_new_isle(p_hwfn,
p_hwfn->p_ooo_info,
cid,
iscsi_ooo->ooo_isle,
p_buffer);
break;
case TCP_EVENT_ADD_ISLE_RIGHT:
qed_ooo_add_new_buffer(p_hwfn,
p_hwfn->p_ooo_info,
cid,
iscsi_ooo->ooo_isle,
p_buffer,
QED_OOO_RIGHT_BUF);
break;
case TCP_EVENT_ADD_ISLE_LEFT:
qed_ooo_add_new_buffer(p_hwfn,
p_hwfn->p_ooo_info,
cid,
iscsi_ooo->ooo_isle,
p_buffer,
QED_OOO_LEFT_BUF);
break;
case TCP_EVENT_JOIN:
qed_ooo_add_new_buffer(p_hwfn,
p_hwfn->p_ooo_info,
cid,
iscsi_ooo->ooo_isle +
1,
p_buffer,
QED_OOO_LEFT_BUF);
qed_ooo_join_isles(p_hwfn,
p_hwfn->p_ooo_info,
cid, iscsi_ooo->ooo_isle);
break;
case TCP_EVENT_ADD_PEN:
num_ooo_add_to_peninsula++;
qed_ooo_put_ready_buffer(p_hwfn,
p_hwfn->p_ooo_info,
p_buffer, true);
break;
}
} else {
DP_NOTICE(p_hwfn,
"Unexpected event (%d) TX OOO completion\n",
iscsi_ooo->ooo_opcode);
}
}
return 0;
}
static void
qed_ooo_submit_tx_buffers(struct qed_hwfn *p_hwfn,
struct qed_ll2_info *p_ll2_conn)
{
struct qed_ll2_tx_pkt_info tx_pkt;
struct qed_ooo_buffer *p_buffer;
u16 l4_hdr_offset_w;
dma_addr_t first_frag;
u16 parse_flags;
u8 bd_flags;
int rc;
while ((p_buffer = qed_ooo_get_ready_buffer(p_hwfn,
p_hwfn->p_ooo_info))) {
l4_hdr_offset_w = 0;
bd_flags = 0;
first_frag = p_buffer->rx_buffer_phys_addr +
p_buffer->placement_offset;
parse_flags = p_buffer->parse_flags;
bd_flags = qed_ll2_convert_rx_parse_to_tx_flags(parse_flags);
SET_FIELD(bd_flags, CORE_TX_BD_DATA_FORCE_VLAN_MODE, 1);
SET_FIELD(bd_flags, CORE_TX_BD_DATA_L4_PROTOCOL, 1);
memset(&tx_pkt, 0, sizeof(tx_pkt));
tx_pkt.num_of_bds = 1;
tx_pkt.vlan = p_buffer->vlan;
tx_pkt.bd_flags = bd_flags;
tx_pkt.l4_hdr_offset_w = l4_hdr_offset_w;
tx_pkt.tx_dest = p_ll2_conn->tx_dest;
tx_pkt.first_frag = first_frag;
tx_pkt.first_frag_len = p_buffer->packet_length;
tx_pkt.cookie = p_buffer;
rc = qed_ll2_prepare_tx_packet(p_hwfn, p_ll2_conn->my_id,
&tx_pkt, true);
if (rc) {
qed_ooo_put_ready_buffer(p_hwfn, p_hwfn->p_ooo_info,
p_buffer, false);
break;
}
}
}
static void
qed_ooo_submit_rx_buffers(struct qed_hwfn *p_hwfn,
struct qed_ll2_info *p_ll2_conn)
{
struct qed_ooo_buffer *p_buffer;
int rc;
while ((p_buffer = qed_ooo_get_free_buffer(p_hwfn,
p_hwfn->p_ooo_info))) {
rc = qed_ll2_post_rx_buffer(p_hwfn,
p_ll2_conn->my_id,
p_buffer->rx_buffer_phys_addr,
0, p_buffer, true);
if (rc) {
qed_ooo_put_free_buffer(p_hwfn,
p_hwfn->p_ooo_info, p_buffer);
break;
}
}
}
static int qed_ll2_lb_rxq_completion(struct qed_hwfn *p_hwfn, void *p_cookie)
{
struct qed_ll2_info *p_ll2_conn = (struct qed_ll2_info *)p_cookie;
int rc;
rc = qed_ll2_lb_rxq_handler(p_hwfn, p_ll2_conn);
if (rc)
return rc;
qed_ooo_submit_rx_buffers(p_hwfn, p_ll2_conn);
qed_ooo_submit_tx_buffers(p_hwfn, p_ll2_conn);
return 0;
}
static int qed_ll2_lb_txq_completion(struct qed_hwfn *p_hwfn, void *p_cookie)
{
struct qed_ll2_info *p_ll2_conn = (struct qed_ll2_info *)p_cookie;
struct qed_ll2_tx_queue *p_tx = &p_ll2_conn->tx_queue;
struct qed_ll2_tx_packet *p_pkt = NULL;
struct qed_ooo_buffer *p_buffer;
bool b_dont_submit_rx = false;
u16 new_idx = 0, num_bds = 0;
int rc;
new_idx = le16_to_cpu(*p_tx->p_fw_cons);
num_bds = ((s16)new_idx - (s16)p_tx->bds_idx);
if (!num_bds)
return 0;
while (num_bds) {
if (list_empty(&p_tx->active_descq))
return -EINVAL;
p_pkt = list_first_entry(&p_tx->active_descq,
struct qed_ll2_tx_packet, list_entry);
if (!p_pkt)
return -EINVAL;
if (p_pkt->bd_used != 1) {
DP_NOTICE(p_hwfn,
"Unexpectedly many BDs(%d) in TX OOO completion\n",
p_pkt->bd_used);
return -EINVAL;
}
list_del(&p_pkt->list_entry);
num_bds--;
p_tx->bds_idx++;
qed_chain_consume(&p_tx->txq_chain);
p_buffer = (struct qed_ooo_buffer *)p_pkt->cookie;
list_add_tail(&p_pkt->list_entry, &p_tx->free_descq);
if (b_dont_submit_rx) {
qed_ooo_put_free_buffer(p_hwfn, p_hwfn->p_ooo_info,
p_buffer);
continue;
}
rc = qed_ll2_post_rx_buffer(p_hwfn, p_ll2_conn->my_id,
p_buffer->rx_buffer_phys_addr, 0,
p_buffer, true);
if (rc != 0) {
qed_ooo_put_free_buffer(p_hwfn,
p_hwfn->p_ooo_info, p_buffer);
b_dont_submit_rx = true;
}
}
qed_ooo_submit_tx_buffers(p_hwfn, p_ll2_conn);
return 0;
}
static void qed_ll2_stop_ooo(struct qed_dev *cdev)
{
struct qed_hwfn *hwfn = QED_LEADING_HWFN(cdev);
u8 *handle = &hwfn->pf_params.iscsi_pf_params.ll2_ooo_queue_id;
DP_VERBOSE(cdev, QED_MSG_STORAGE, "Stopping LL2 OOO queue [%02x]\n",
*handle);
qed_ll2_terminate_connection(hwfn, *handle);
qed_ll2_release_connection(hwfn, *handle);
*handle = QED_LL2_UNUSED_HANDLE;
}
static int qed_sp_ll2_rx_queue_start(struct qed_hwfn *p_hwfn,
struct qed_ll2_info *p_ll2_conn,
u8 action_on_error)
{
enum qed_ll2_conn_type conn_type = p_ll2_conn->input.conn_type;
struct qed_ll2_rx_queue *p_rx = &p_ll2_conn->rx_queue;
struct core_rx_start_ramrod_data *p_ramrod = NULL;
struct qed_spq_entry *p_ent = NULL;
struct qed_sp_init_data init_data;
u16 cqe_pbl_size;
int rc = 0;
memset(&init_data, 0, sizeof(init_data));
init_data.cid = p_ll2_conn->cid;
init_data.opaque_fid = p_hwfn->hw_info.opaque_fid;
init_data.comp_mode = QED_SPQ_MODE_EBLOCK;
rc = qed_sp_init_request(p_hwfn, &p_ent,
CORE_RAMROD_RX_QUEUE_START,
PROTOCOLID_CORE, &init_data);
if (rc)
return rc;
p_ramrod = &p_ent->ramrod.core_rx_queue_start;
p_ramrod->sb_id = cpu_to_le16(qed_int_get_sp_sb_id(p_hwfn));
p_ramrod->sb_index = p_rx->rx_sb_index;
p_ramrod->complete_event_flg = 1;
p_ramrod->mtu = cpu_to_le16(p_ll2_conn->input.mtu);
DMA_REGPAIR_LE(p_ramrod->bd_base, p_rx->rxq_chain.p_phys_addr);
cqe_pbl_size = (u16)qed_chain_get_page_cnt(&p_rx->rcq_chain);
p_ramrod->num_of_pbl_pages = cpu_to_le16(cqe_pbl_size);
DMA_REGPAIR_LE(p_ramrod->cqe_pbl_addr,
qed_chain_get_pbl_phys(&p_rx->rcq_chain));
p_ramrod->drop_ttl0_flg = p_ll2_conn->input.rx_drop_ttl0_flg;
p_ramrod->inner_vlan_removal_en = p_ll2_conn->input.rx_vlan_removal_en;
p_ramrod->queue_id = p_ll2_conn->queue_id;
p_ramrod->main_func_queue = (conn_type == QED_LL2_TYPE_OOO) ? 0 : 1;
if ((IS_MF_DEFAULT(p_hwfn) || IS_MF_SI(p_hwfn)) &&
p_ramrod->main_func_queue && (conn_type != QED_LL2_TYPE_ROCE) &&
(conn_type != QED_LL2_TYPE_IWARP)) {
p_ramrod->mf_si_bcast_accept_all = 1;
p_ramrod->mf_si_mcast_accept_all = 1;
} else {
p_ramrod->mf_si_bcast_accept_all = 0;
p_ramrod->mf_si_mcast_accept_all = 0;
}
p_ramrod->action_on_error.error_type = action_on_error;
p_ramrod->gsi_offload_flag = p_ll2_conn->input.gsi_enable;
return qed_spq_post(p_hwfn, p_ent, NULL);
}
static int qed_sp_ll2_tx_queue_start(struct qed_hwfn *p_hwfn,
struct qed_ll2_info *p_ll2_conn)
{
enum qed_ll2_conn_type conn_type = p_ll2_conn->input.conn_type;
struct qed_ll2_tx_queue *p_tx = &p_ll2_conn->tx_queue;
struct core_tx_start_ramrod_data *p_ramrod = NULL;
struct qed_spq_entry *p_ent = NULL;
struct qed_sp_init_data init_data;
u16 pq_id = 0, pbl_size;
int rc = -EINVAL;
if (!QED_LL2_TX_REGISTERED(p_ll2_conn))
return 0;
if (p_ll2_conn->input.conn_type == QED_LL2_TYPE_OOO)
p_ll2_conn->tx_stats_en = 0;
else
p_ll2_conn->tx_stats_en = 1;
memset(&init_data, 0, sizeof(init_data));
init_data.cid = p_ll2_conn->cid;
init_data.opaque_fid = p_hwfn->hw_info.opaque_fid;
init_data.comp_mode = QED_SPQ_MODE_EBLOCK;
rc = qed_sp_init_request(p_hwfn, &p_ent,
CORE_RAMROD_TX_QUEUE_START,
PROTOCOLID_CORE, &init_data);
if (rc)
return rc;
p_ramrod = &p_ent->ramrod.core_tx_queue_start;
p_ramrod->sb_id = cpu_to_le16(qed_int_get_sp_sb_id(p_hwfn));
p_ramrod->sb_index = p_tx->tx_sb_index;
p_ramrod->mtu = cpu_to_le16(p_ll2_conn->input.mtu);
p_ramrod->stats_en = p_ll2_conn->tx_stats_en;
p_ramrod->stats_id = p_ll2_conn->tx_stats_id;
DMA_REGPAIR_LE(p_ramrod->pbl_base_addr,
qed_chain_get_pbl_phys(&p_tx->txq_chain));
pbl_size = qed_chain_get_page_cnt(&p_tx->txq_chain);
p_ramrod->pbl_size = cpu_to_le16(pbl_size);
switch (p_ll2_conn->input.tx_tc) {
case PURE_LB_TC:
pq_id = qed_get_cm_pq_idx(p_hwfn, PQ_FLAGS_LB);
break;
case PKT_LB_TC:
pq_id = qed_get_cm_pq_idx(p_hwfn, PQ_FLAGS_OOO);
break;
default:
pq_id = qed_get_cm_pq_idx(p_hwfn, PQ_FLAGS_OFLD);
break;
}
p_ramrod->qm_pq_id = cpu_to_le16(pq_id);
switch (conn_type) {
case QED_LL2_TYPE_FCOE:
p_ramrod->conn_type = PROTOCOLID_FCOE;
break;
case QED_LL2_TYPE_ISCSI:
p_ramrod->conn_type = PROTOCOLID_ISCSI;
break;
case QED_LL2_TYPE_ROCE:
p_ramrod->conn_type = PROTOCOLID_ROCE;
break;
case QED_LL2_TYPE_IWARP:
p_ramrod->conn_type = PROTOCOLID_IWARP;
break;
case QED_LL2_TYPE_OOO:
if (p_hwfn->hw_info.personality == QED_PCI_ISCSI)
p_ramrod->conn_type = PROTOCOLID_ISCSI;
else
p_ramrod->conn_type = PROTOCOLID_IWARP;
break;
default:
p_ramrod->conn_type = PROTOCOLID_ETH;
DP_NOTICE(p_hwfn, "Unknown connection type: %d\n", conn_type);
}
p_ramrod->gsi_offload_flag = p_ll2_conn->input.gsi_enable;
return qed_spq_post(p_hwfn, p_ent, NULL);
}
static int qed_sp_ll2_rx_queue_stop(struct qed_hwfn *p_hwfn,
struct qed_ll2_info *p_ll2_conn)
{
struct core_rx_stop_ramrod_data *p_ramrod = NULL;
struct qed_spq_entry *p_ent = NULL;
struct qed_sp_init_data init_data;
int rc = -EINVAL;
memset(&init_data, 0, sizeof(init_data));
init_data.cid = p_ll2_conn->cid;
init_data.opaque_fid = p_hwfn->hw_info.opaque_fid;
init_data.comp_mode = QED_SPQ_MODE_EBLOCK;
rc = qed_sp_init_request(p_hwfn, &p_ent,
CORE_RAMROD_RX_QUEUE_STOP,
PROTOCOLID_CORE, &init_data);
if (rc)
return rc;
p_ramrod = &p_ent->ramrod.core_rx_queue_stop;
p_ramrod->complete_event_flg = 1;
p_ramrod->queue_id = p_ll2_conn->queue_id;
return qed_spq_post(p_hwfn, p_ent, NULL);
}
static int qed_sp_ll2_tx_queue_stop(struct qed_hwfn *p_hwfn,
struct qed_ll2_info *p_ll2_conn)
{
struct qed_spq_entry *p_ent = NULL;
struct qed_sp_init_data init_data;
int rc = -EINVAL;
memset(&init_data, 0, sizeof(init_data));
init_data.cid = p_ll2_conn->cid;
init_data.opaque_fid = p_hwfn->hw_info.opaque_fid;
init_data.comp_mode = QED_SPQ_MODE_EBLOCK;
rc = qed_sp_init_request(p_hwfn, &p_ent,
CORE_RAMROD_TX_QUEUE_STOP,
PROTOCOLID_CORE, &init_data);
if (rc)
return rc;
return qed_spq_post(p_hwfn, p_ent, NULL);
}
static int
qed_ll2_acquire_connection_rx(struct qed_hwfn *p_hwfn,
struct qed_ll2_info *p_ll2_info)
{
struct qed_ll2_rx_packet *p_descq;
u32 capacity;
int rc = 0;
if (!p_ll2_info->input.rx_num_desc)
goto out;
rc = qed_chain_alloc(p_hwfn->cdev,
QED_CHAIN_USE_TO_CONSUME_PRODUCE,
QED_CHAIN_MODE_NEXT_PTR,
QED_CHAIN_CNT_TYPE_U16,
p_ll2_info->input.rx_num_desc,
sizeof(struct core_rx_bd),
&p_ll2_info->rx_queue.rxq_chain, NULL);
if (rc) {
DP_NOTICE(p_hwfn, "Failed to allocate ll2 rxq chain\n");
goto out;
}
capacity = qed_chain_get_capacity(&p_ll2_info->rx_queue.rxq_chain);
p_descq = kcalloc(capacity, sizeof(struct qed_ll2_rx_packet),
GFP_KERNEL);
if (!p_descq) {
rc = -ENOMEM;
DP_NOTICE(p_hwfn, "Failed to allocate ll2 Rx desc\n");
goto out;
}
p_ll2_info->rx_queue.descq_array = p_descq;
rc = qed_chain_alloc(p_hwfn->cdev,
QED_CHAIN_USE_TO_CONSUME_PRODUCE,
QED_CHAIN_MODE_PBL,
QED_CHAIN_CNT_TYPE_U16,
p_ll2_info->input.rx_num_desc,
sizeof(struct core_rx_fast_path_cqe),
&p_ll2_info->rx_queue.rcq_chain, NULL);
if (rc) {
DP_NOTICE(p_hwfn, "Failed to allocate ll2 rcq chain\n");
goto out;
}
DP_VERBOSE(p_hwfn, QED_MSG_LL2,
"Allocated LL2 Rxq [Type %08x] with 0x%08x buffers\n",
p_ll2_info->input.conn_type, p_ll2_info->input.rx_num_desc);
out:
return rc;
}
static int qed_ll2_acquire_connection_tx(struct qed_hwfn *p_hwfn,
struct qed_ll2_info *p_ll2_info)
{
struct qed_ll2_tx_packet *p_descq;
u32 capacity;
int rc = 0;
if (!p_ll2_info->input.tx_num_desc)
goto out;
rc = qed_chain_alloc(p_hwfn->cdev,
QED_CHAIN_USE_TO_CONSUME_PRODUCE,
QED_CHAIN_MODE_PBL,
QED_CHAIN_CNT_TYPE_U16,
p_ll2_info->input.tx_num_desc,
sizeof(struct core_tx_bd),
&p_ll2_info->tx_queue.txq_chain, NULL);
if (rc)
goto out;
capacity = qed_chain_get_capacity(&p_ll2_info->tx_queue.txq_chain);
p_descq = kcalloc(capacity, sizeof(struct qed_ll2_tx_packet),
GFP_KERNEL);
if (!p_descq) {
rc = -ENOMEM;
goto out;
}
p_ll2_info->tx_queue.descq_array = p_descq;
DP_VERBOSE(p_hwfn, QED_MSG_LL2,
"Allocated LL2 Txq [Type %08x] with 0x%08x buffers\n",
p_ll2_info->input.conn_type, p_ll2_info->input.tx_num_desc);
out:
if (rc)
DP_NOTICE(p_hwfn,
"Can't allocate memory for Tx LL2 with 0x%08x buffers\n",
p_ll2_info->input.tx_num_desc);
return rc;
}
static int
qed_ll2_acquire_connection_ooo(struct qed_hwfn *p_hwfn,
struct qed_ll2_info *p_ll2_info, u16 mtu)
{
struct qed_ooo_buffer *p_buf = NULL;
void *p_virt;
u16 buf_idx;
int rc = 0;
if (p_ll2_info->input.conn_type != QED_LL2_TYPE_OOO)
return rc;
if (!p_ll2_info->input.rx_num_ooo_buffers) {
u16 num_desc = p_ll2_info->input.rx_num_desc;
if (!num_desc)
return -EINVAL;
p_ll2_info->input.rx_num_ooo_buffers = num_desc * 2;
}
for (buf_idx = 0; buf_idx < p_ll2_info->input.rx_num_ooo_buffers;
buf_idx++) {
p_buf = kzalloc(sizeof(*p_buf), GFP_KERNEL);
if (!p_buf) {
rc = -ENOMEM;
goto out;
}
p_buf->rx_buffer_size = mtu + 26 + ETH_CACHE_LINE_SIZE;
p_buf->rx_buffer_size = (p_buf->rx_buffer_size +
ETH_CACHE_LINE_SIZE - 1) &
~(ETH_CACHE_LINE_SIZE - 1);
p_virt = dma_alloc_coherent(&p_hwfn->cdev->pdev->dev,
p_buf->rx_buffer_size,
&p_buf->rx_buffer_phys_addr,
GFP_KERNEL);
if (!p_virt) {
kfree(p_buf);
rc = -ENOMEM;
goto out;
}
p_buf->rx_buffer_virt_addr = p_virt;
qed_ooo_put_free_buffer(p_hwfn, p_hwfn->p_ooo_info, p_buf);
}
DP_VERBOSE(p_hwfn, QED_MSG_LL2,
"Allocated [%04x] LL2 OOO buffers [each of size 0x%08x]\n",
p_ll2_info->input.rx_num_ooo_buffers, p_buf->rx_buffer_size);
out:
return rc;
}
static int
qed_ll2_set_cbs(struct qed_ll2_info *p_ll2_info, const struct qed_ll2_cbs *cbs)
{
if (!cbs || (!cbs->rx_comp_cb ||
!cbs->rx_release_cb ||
!cbs->tx_comp_cb || !cbs->tx_release_cb || !cbs->cookie))
return -EINVAL;
p_ll2_info->cbs.rx_comp_cb = cbs->rx_comp_cb;
p_ll2_info->cbs.rx_release_cb = cbs->rx_release_cb;
p_ll2_info->cbs.tx_comp_cb = cbs->tx_comp_cb;
p_ll2_info->cbs.tx_release_cb = cbs->tx_release_cb;
p_ll2_info->cbs.cookie = cbs->cookie;
return 0;
}
static enum core_error_handle
qed_ll2_get_error_choice(enum qed_ll2_error_handle err)
{
switch (err) {
case QED_LL2_DROP_PACKET:
return LL2_DROP_PACKET;
case QED_LL2_DO_NOTHING:
return LL2_DO_NOTHING;
case QED_LL2_ASSERT:
return LL2_ASSERT;
default:
return LL2_DO_NOTHING;
}
}
int qed_ll2_acquire_connection(void *cxt, struct qed_ll2_acquire_data *data)
{
struct qed_hwfn *p_hwfn = cxt;
qed_int_comp_cb_t comp_rx_cb, comp_tx_cb;
struct qed_ll2_info *p_ll2_info = NULL;
u8 i, *p_tx_max;
int rc;
if (!data->p_connection_handle || !p_hwfn->p_ll2_info)
return -EINVAL;
for (i = 0; (i < QED_MAX_NUM_OF_LL2_CONNECTIONS); i++) {
mutex_lock(&p_hwfn->p_ll2_info[i].mutex);
if (p_hwfn->p_ll2_info[i].b_active) {
mutex_unlock(&p_hwfn->p_ll2_info[i].mutex);
continue;
}
p_hwfn->p_ll2_info[i].b_active = true;
p_ll2_info = &p_hwfn->p_ll2_info[i];
mutex_unlock(&p_hwfn->p_ll2_info[i].mutex);
break;
}
if (!p_ll2_info)
return -EBUSY;
memcpy(&p_ll2_info->input, &data->input, sizeof(p_ll2_info->input));
p_ll2_info->tx_dest = (data->input.tx_dest == QED_LL2_TX_DEST_NW) ?
CORE_TX_DEST_NW : CORE_TX_DEST_LB;
p_tx_max = &p_ll2_info->input.tx_max_bds_per_packet;
if (*p_tx_max == 0)
*p_tx_max = CORE_LL2_TX_MAX_BDS_PER_PACKET;
else
*p_tx_max = min_t(u8, *p_tx_max,
CORE_LL2_TX_MAX_BDS_PER_PACKET);
rc = qed_ll2_set_cbs(p_ll2_info, data->cbs);
if (rc) {
DP_NOTICE(p_hwfn, "Invalid callback functions\n");
goto q_allocate_fail;
}
rc = qed_ll2_acquire_connection_rx(p_hwfn, p_ll2_info);
if (rc)
goto q_allocate_fail;
rc = qed_ll2_acquire_connection_tx(p_hwfn, p_ll2_info);
if (rc)
goto q_allocate_fail;
rc = qed_ll2_acquire_connection_ooo(p_hwfn, p_ll2_info,
data->input.mtu);
if (rc)
goto q_allocate_fail;
if (data->input.conn_type == QED_LL2_TYPE_OOO) {
comp_rx_cb = qed_ll2_lb_rxq_completion;
comp_tx_cb = qed_ll2_lb_txq_completion;
} else {
comp_rx_cb = qed_ll2_rxq_completion;
comp_tx_cb = qed_ll2_txq_completion;
}
if (data->input.rx_num_desc) {
qed_int_register_cb(p_hwfn, comp_rx_cb,
&p_hwfn->p_ll2_info[i],
&p_ll2_info->rx_queue.rx_sb_index,
&p_ll2_info->rx_queue.p_fw_cons);
p_ll2_info->rx_queue.b_cb_registred = true;
}
if (data->input.tx_num_desc) {
qed_int_register_cb(p_hwfn,
comp_tx_cb,
&p_hwfn->p_ll2_info[i],
&p_ll2_info->tx_queue.tx_sb_index,
&p_ll2_info->tx_queue.p_fw_cons);
p_ll2_info->tx_queue.b_cb_registred = true;
}
*data->p_connection_handle = i;
return rc;
q_allocate_fail:
qed_ll2_release_connection(p_hwfn, i);
return -ENOMEM;
}
static int qed_ll2_establish_connection_rx(struct qed_hwfn *p_hwfn,
struct qed_ll2_info *p_ll2_conn)
{
enum qed_ll2_error_handle error_input;
enum core_error_handle error_mode;
u8 action_on_error = 0;
if (!QED_LL2_RX_REGISTERED(p_ll2_conn))
return 0;
DIRECT_REG_WR(p_ll2_conn->rx_queue.set_prod_addr, 0x0);
error_input = p_ll2_conn->input.ai_err_packet_too_big;
error_mode = qed_ll2_get_error_choice(error_input);
SET_FIELD(action_on_error,
CORE_RX_ACTION_ON_ERROR_PACKET_TOO_BIG, error_mode);
error_input = p_ll2_conn->input.ai_err_no_buf;
error_mode = qed_ll2_get_error_choice(error_input);
SET_FIELD(action_on_error, CORE_RX_ACTION_ON_ERROR_NO_BUFF, error_mode);
return qed_sp_ll2_rx_queue_start(p_hwfn, p_ll2_conn, action_on_error);
}
static void
qed_ll2_establish_connection_ooo(struct qed_hwfn *p_hwfn,
struct qed_ll2_info *p_ll2_conn)
{
if (p_ll2_conn->input.conn_type != QED_LL2_TYPE_OOO)
return;
qed_ooo_release_all_isles(p_hwfn, p_hwfn->p_ooo_info);
qed_ooo_submit_rx_buffers(p_hwfn, p_ll2_conn);
}
int qed_ll2_establish_connection(void *cxt, u8 connection_handle)
{
struct qed_hwfn *p_hwfn = cxt;
struct qed_ll2_info *p_ll2_conn;
struct qed_ll2_rx_queue *p_rx;
struct qed_ll2_tx_queue *p_tx;
struct qed_ptt *p_ptt;
int rc = -EINVAL;
u32 i, capacity;
u8 qid;
p_ptt = qed_ptt_acquire(p_hwfn);
if (!p_ptt)
return -EAGAIN;
p_ll2_conn = qed_ll2_handle_sanity_lock(p_hwfn, connection_handle);
if (!p_ll2_conn) {
rc = -EINVAL;
goto out;
}
p_rx = &p_ll2_conn->rx_queue;
p_tx = &p_ll2_conn->tx_queue;
qed_chain_reset(&p_rx->rxq_chain);
qed_chain_reset(&p_rx->rcq_chain);
INIT_LIST_HEAD(&p_rx->active_descq);
INIT_LIST_HEAD(&p_rx->free_descq);
INIT_LIST_HEAD(&p_rx->posting_descq);
spin_lock_init(&p_rx->lock);
capacity = qed_chain_get_capacity(&p_rx->rxq_chain);
for (i = 0; i < capacity; i++)
list_add_tail(&p_rx->descq_array[i].list_entry,
&p_rx->free_descq);
*p_rx->p_fw_cons = 0;
qed_chain_reset(&p_tx->txq_chain);
INIT_LIST_HEAD(&p_tx->active_descq);
INIT_LIST_HEAD(&p_tx->free_descq);
INIT_LIST_HEAD(&p_tx->sending_descq);
spin_lock_init(&p_tx->lock);
capacity = qed_chain_get_capacity(&p_tx->txq_chain);
for (i = 0; i < capacity; i++)
list_add_tail(&p_tx->descq_array[i].list_entry,
&p_tx->free_descq);
p_tx->cur_completing_bd_idx = 0;
p_tx->bds_idx = 0;
p_tx->b_completing_packet = false;
p_tx->cur_send_packet = NULL;
p_tx->cur_send_frag_num = 0;
p_tx->cur_completing_frag_num = 0;
*p_tx->p_fw_cons = 0;
rc = qed_cxt_acquire_cid(p_hwfn, PROTOCOLID_CORE, &p_ll2_conn->cid);
if (rc)
goto out;
qid = p_hwfn->hw_info.resc_start[QED_LL2_QUEUE] + connection_handle;
p_ll2_conn->queue_id = qid;
p_ll2_conn->tx_stats_id = qid;
p_rx->set_prod_addr = (u8 __iomem *)p_hwfn->regview +
GTT_BAR0_MAP_REG_TSDM_RAM +
TSTORM_LL2_RX_PRODS_OFFSET(qid);
p_tx->doorbell_addr = (u8 __iomem *)p_hwfn->doorbells +
qed_db_addr(p_ll2_conn->cid,
DQ_DEMS_LEGACY);
rc = qed_ll2_establish_connection_rx(p_hwfn, p_ll2_conn);
if (rc)
goto out;
rc = qed_sp_ll2_tx_queue_start(p_hwfn, p_ll2_conn);
if (rc)
goto out;
if (!QED_IS_RDMA_PERSONALITY(p_hwfn))
qed_wr(p_hwfn, p_ptt, PRS_REG_USE_LIGHT_L2, 1);
qed_ll2_establish_connection_ooo(p_hwfn, p_ll2_conn);
if (p_ll2_conn->input.conn_type == QED_LL2_TYPE_FCOE) {
qed_llh_add_protocol_filter(p_hwfn, p_ptt,
0x8906, 0,
QED_LLH_FILTER_ETHERTYPE);
qed_llh_add_protocol_filter(p_hwfn, p_ptt,
0x8914, 0,
QED_LLH_FILTER_ETHERTYPE);
}
out:
qed_ptt_release(p_hwfn, p_ptt);
return rc;
}
static void qed_ll2_post_rx_buffer_notify_fw(struct qed_hwfn *p_hwfn,
struct qed_ll2_rx_queue *p_rx,
struct qed_ll2_rx_packet *p_curp)
{
struct qed_ll2_rx_packet *p_posting_packet = NULL;
struct core_ll2_rx_prod rx_prod = { 0, 0, 0 };
bool b_notify_fw = false;
u16 bd_prod, cq_prod;
while (!list_empty(&p_rx->posting_descq)) {
p_posting_packet = list_first_entry(&p_rx->posting_descq,
struct qed_ll2_rx_packet,
list_entry);
list_move_tail(&p_posting_packet->list_entry,
&p_rx->active_descq);
b_notify_fw = true;
}
if (p_curp) {
list_add_tail(&p_curp->list_entry, &p_rx->active_descq);
b_notify_fw = true;
}
if (!b_notify_fw)
return;
bd_prod = qed_chain_get_prod_idx(&p_rx->rxq_chain);
cq_prod = qed_chain_get_prod_idx(&p_rx->rcq_chain);
rx_prod.bd_prod = cpu_to_le16(bd_prod);
rx_prod.cqe_prod = cpu_to_le16(cq_prod);
DIRECT_REG_WR(p_rx->set_prod_addr, *((u32 *)&rx_prod));
}
int qed_ll2_post_rx_buffer(void *cxt,
u8 connection_handle,
dma_addr_t addr,
u16 buf_len, void *cookie, u8 notify_fw)
{
struct qed_hwfn *p_hwfn = cxt;
struct core_rx_bd_with_buff_len *p_curb = NULL;
struct qed_ll2_rx_packet *p_curp = NULL;
struct qed_ll2_info *p_ll2_conn;
struct qed_ll2_rx_queue *p_rx;
unsigned long flags;
void *p_data;
int rc = 0;
p_ll2_conn = qed_ll2_handle_sanity(p_hwfn, connection_handle);
if (!p_ll2_conn)
return -EINVAL;
p_rx = &p_ll2_conn->rx_queue;
spin_lock_irqsave(&p_rx->lock, flags);
if (!list_empty(&p_rx->free_descq))
p_curp = list_first_entry(&p_rx->free_descq,
struct qed_ll2_rx_packet, list_entry);
if (p_curp) {
if (qed_chain_get_elem_left(&p_rx->rxq_chain) &&
qed_chain_get_elem_left(&p_rx->rcq_chain)) {
p_data = qed_chain_produce(&p_rx->rxq_chain);
p_curb = (struct core_rx_bd_with_buff_len *)p_data;
qed_chain_produce(&p_rx->rcq_chain);
}
}
if (!p_curp || !p_curb) {
rc = -EBUSY;
p_curp = NULL;
goto out_notify;
}
DMA_REGPAIR_LE(p_curb->addr, addr);
p_curb->buff_length = cpu_to_le16(buf_len);
p_curp->rx_buf_addr = addr;
p_curp->cookie = cookie;
p_curp->rxq_bd = p_curb;
p_curp->buf_length = buf_len;
list_del(&p_curp->list_entry);
if (!notify_fw) {
list_add_tail(&p_curp->list_entry, &p_rx->posting_descq);
goto out;
}
out_notify:
qed_ll2_post_rx_buffer_notify_fw(p_hwfn, p_rx, p_curp);
out:
spin_unlock_irqrestore(&p_rx->lock, flags);
return rc;
}
static void qed_ll2_prepare_tx_packet_set(struct qed_hwfn *p_hwfn,
struct qed_ll2_tx_queue *p_tx,
struct qed_ll2_tx_packet *p_curp,
struct qed_ll2_tx_pkt_info *pkt,
u8 notify_fw)
{
list_del(&p_curp->list_entry);
p_curp->cookie = pkt->cookie;
p_curp->bd_used = pkt->num_of_bds;
p_curp->notify_fw = notify_fw;
p_tx->cur_send_packet = p_curp;
p_tx->cur_send_frag_num = 0;
p_curp->bds_set[p_tx->cur_send_frag_num].tx_frag = pkt->first_frag;
p_curp->bds_set[p_tx->cur_send_frag_num].frag_len = pkt->first_frag_len;
p_tx->cur_send_frag_num++;
}
static void
qed_ll2_prepare_tx_packet_set_bd(struct qed_hwfn *p_hwfn,
struct qed_ll2_info *p_ll2,
struct qed_ll2_tx_packet *p_curp,
struct qed_ll2_tx_pkt_info *pkt)
{
struct qed_chain *p_tx_chain = &p_ll2->tx_queue.txq_chain;
u16 prod_idx = qed_chain_get_prod_idx(p_tx_chain);
struct core_tx_bd *start_bd = NULL;
enum core_roce_flavor_type roce_flavor;
enum core_tx_dest tx_dest;
u16 bd_data = 0, frag_idx;
roce_flavor = (pkt->qed_roce_flavor == QED_LL2_ROCE) ? CORE_ROCE
: CORE_RROCE;
tx_dest = (pkt->tx_dest == QED_LL2_TX_DEST_NW) ? CORE_TX_DEST_NW
: CORE_TX_DEST_LB;
start_bd = (struct core_tx_bd *)qed_chain_produce(p_tx_chain);
start_bd->nw_vlan_or_lb_echo = cpu_to_le16(pkt->vlan);
SET_FIELD(start_bd->bitfield1, CORE_TX_BD_L4_HDR_OFFSET_W,
cpu_to_le16(pkt->l4_hdr_offset_w));
SET_FIELD(start_bd->bitfield1, CORE_TX_BD_TX_DST, tx_dest);
bd_data |= pkt->bd_flags;
SET_FIELD(bd_data, CORE_TX_BD_DATA_START_BD, 0x1);
SET_FIELD(bd_data, CORE_TX_BD_DATA_NBDS, pkt->num_of_bds);
SET_FIELD(bd_data, CORE_TX_BD_DATA_ROCE_FLAV, roce_flavor);
start_bd->bd_data.as_bitfield = cpu_to_le16(bd_data);
DMA_REGPAIR_LE(start_bd->addr, pkt->first_frag);
start_bd->nbytes = cpu_to_le16(pkt->first_frag_len);
DP_VERBOSE(p_hwfn,
(NETIF_MSG_TX_QUEUED | QED_MSG_LL2),
"LL2 [q 0x%02x cid 0x%08x type 0x%08x] Tx Producer at [0x%04x] - set with a %04x bytes %02x BDs buffer at %08x:%08x\n",
p_ll2->queue_id,
p_ll2->cid,
p_ll2->input.conn_type,
prod_idx,
pkt->first_frag_len,
pkt->num_of_bds,
le32_to_cpu(start_bd->addr.hi),
le32_to_cpu(start_bd->addr.lo));
if (p_ll2->tx_queue.cur_send_frag_num == pkt->num_of_bds)
return;
for (frag_idx = p_ll2->tx_queue.cur_send_frag_num;
frag_idx < pkt->num_of_bds; frag_idx++) {
struct core_tx_bd **p_bd = &p_curp->bds_set[frag_idx].txq_bd;
*p_bd = (struct core_tx_bd *)qed_chain_produce(p_tx_chain);
(*p_bd)->bd_data.as_bitfield = 0;
(*p_bd)->bitfield1 = 0;
p_curp->bds_set[frag_idx].tx_frag = 0;
p_curp->bds_set[frag_idx].frag_len = 0;
}
}
static void qed_ll2_tx_packet_notify(struct qed_hwfn *p_hwfn,
struct qed_ll2_info *p_ll2_conn)
{
bool b_notify = p_ll2_conn->tx_queue.cur_send_packet->notify_fw;
struct qed_ll2_tx_queue *p_tx = &p_ll2_conn->tx_queue;
struct qed_ll2_tx_packet *p_pkt = NULL;
struct core_db_data db_msg = { 0, 0, 0 };
u16 bd_prod;
if (p_ll2_conn->tx_queue.cur_send_frag_num !=
p_ll2_conn->tx_queue.cur_send_packet->bd_used)
return;
list_add_tail(&p_ll2_conn->tx_queue.cur_send_packet->list_entry,
&p_ll2_conn->tx_queue.sending_descq);
p_ll2_conn->tx_queue.cur_send_packet = NULL;
p_ll2_conn->tx_queue.cur_send_frag_num = 0;
if (!b_notify)
return;
bd_prod = qed_chain_get_prod_idx(&p_ll2_conn->tx_queue.txq_chain);
while (!list_empty(&p_tx->sending_descq)) {
p_pkt = list_first_entry(&p_tx->sending_descq,
struct qed_ll2_tx_packet, list_entry);
if (!p_pkt)
break;
list_move_tail(&p_pkt->list_entry, &p_tx->active_descq);
}
SET_FIELD(db_msg.params, CORE_DB_DATA_DEST, DB_DEST_XCM);
SET_FIELD(db_msg.params, CORE_DB_DATA_AGG_CMD, DB_AGG_CMD_SET);
SET_FIELD(db_msg.params, CORE_DB_DATA_AGG_VAL_SEL,
DQ_XCM_CORE_TX_BD_PROD_CMD);
db_msg.agg_flags = DQ_XCM_CORE_DQ_CF_CMD;
db_msg.spq_prod = cpu_to_le16(bd_prod);
wmb();
DIRECT_REG_WR(p_tx->doorbell_addr, *((u32 *)&db_msg));
DP_VERBOSE(p_hwfn,
(NETIF_MSG_TX_QUEUED | QED_MSG_LL2),
"LL2 [q 0x%02x cid 0x%08x type 0x%08x] Doorbelled [producer 0x%04x]\n",
p_ll2_conn->queue_id,
p_ll2_conn->cid,
p_ll2_conn->input.conn_type, db_msg.spq_prod);
}
int qed_ll2_prepare_tx_packet(void *cxt,
u8 connection_handle,
struct qed_ll2_tx_pkt_info *pkt,
bool notify_fw)
{
struct qed_hwfn *p_hwfn = cxt;
struct qed_ll2_tx_packet *p_curp = NULL;
struct qed_ll2_info *p_ll2_conn = NULL;
struct qed_ll2_tx_queue *p_tx;
struct qed_chain *p_tx_chain;
unsigned long flags;
int rc = 0;
p_ll2_conn = qed_ll2_handle_sanity(p_hwfn, connection_handle);
if (!p_ll2_conn)
return -EINVAL;
p_tx = &p_ll2_conn->tx_queue;
p_tx_chain = &p_tx->txq_chain;
if (pkt->num_of_bds > CORE_LL2_TX_MAX_BDS_PER_PACKET)
return -EIO;
spin_lock_irqsave(&p_tx->lock, flags);
if (p_tx->cur_send_packet) {
rc = -EEXIST;
goto out;
}
if (!list_empty(&p_tx->free_descq))
p_curp = list_first_entry(&p_tx->free_descq,
struct qed_ll2_tx_packet, list_entry);
if (p_curp && qed_chain_get_elem_left(p_tx_chain) < pkt->num_of_bds)
p_curp = NULL;
if (!p_curp) {
rc = -EBUSY;
goto out;
}
qed_ll2_prepare_tx_packet_set(p_hwfn, p_tx, p_curp, pkt, notify_fw);
qed_ll2_prepare_tx_packet_set_bd(p_hwfn, p_ll2_conn, p_curp, pkt);
qed_ll2_tx_packet_notify(p_hwfn, p_ll2_conn);
out:
spin_unlock_irqrestore(&p_tx->lock, flags);
return rc;
}
int qed_ll2_set_fragment_of_tx_packet(void *cxt,
u8 connection_handle,
dma_addr_t addr, u16 nbytes)
{
struct qed_ll2_tx_packet *p_cur_send_packet = NULL;
struct qed_hwfn *p_hwfn = cxt;
struct qed_ll2_info *p_ll2_conn = NULL;
u16 cur_send_frag_num = 0;
struct core_tx_bd *p_bd;
unsigned long flags;
p_ll2_conn = qed_ll2_handle_sanity(p_hwfn, connection_handle);
if (!p_ll2_conn)
return -EINVAL;
if (!p_ll2_conn->tx_queue.cur_send_packet)
return -EINVAL;
p_cur_send_packet = p_ll2_conn->tx_queue.cur_send_packet;
cur_send_frag_num = p_ll2_conn->tx_queue.cur_send_frag_num;
if (cur_send_frag_num >= p_cur_send_packet->bd_used)
return -EINVAL;
p_bd = p_cur_send_packet->bds_set[cur_send_frag_num].txq_bd;
DMA_REGPAIR_LE(p_bd->addr, addr);
p_bd->nbytes = cpu_to_le16(nbytes);
p_cur_send_packet->bds_set[cur_send_frag_num].tx_frag = addr;
p_cur_send_packet->bds_set[cur_send_frag_num].frag_len = nbytes;
p_ll2_conn->tx_queue.cur_send_frag_num++;
spin_lock_irqsave(&p_ll2_conn->tx_queue.lock, flags);
qed_ll2_tx_packet_notify(p_hwfn, p_ll2_conn);
spin_unlock_irqrestore(&p_ll2_conn->tx_queue.lock, flags);
return 0;
}
int qed_ll2_terminate_connection(void *cxt, u8 connection_handle)
{
struct qed_hwfn *p_hwfn = cxt;
struct qed_ll2_info *p_ll2_conn = NULL;
int rc = -EINVAL;
struct qed_ptt *p_ptt;
p_ptt = qed_ptt_acquire(p_hwfn);
if (!p_ptt)
return -EAGAIN;
p_ll2_conn = qed_ll2_handle_sanity_lock(p_hwfn, connection_handle);
if (!p_ll2_conn) {
rc = -EINVAL;
goto out;
}
if (QED_LL2_TX_REGISTERED(p_ll2_conn)) {
rc = qed_sp_ll2_tx_queue_stop(p_hwfn, p_ll2_conn);
if (rc)
goto out;
qed_ll2_txq_flush(p_hwfn, connection_handle);
}
if (QED_LL2_RX_REGISTERED(p_ll2_conn)) {
rc = qed_sp_ll2_rx_queue_stop(p_hwfn, p_ll2_conn);
if (rc)
goto out;
qed_ll2_rxq_flush(p_hwfn, connection_handle);
}
if (p_ll2_conn->input.conn_type == QED_LL2_TYPE_OOO)
qed_ooo_release_all_isles(p_hwfn, p_hwfn->p_ooo_info);
if (p_ll2_conn->input.conn_type == QED_LL2_TYPE_FCOE) {
qed_llh_remove_protocol_filter(p_hwfn, p_ptt,
0x8906, 0,
QED_LLH_FILTER_ETHERTYPE);
qed_llh_remove_protocol_filter(p_hwfn, p_ptt,
0x8914, 0,
QED_LLH_FILTER_ETHERTYPE);
}
out:
qed_ptt_release(p_hwfn, p_ptt);
return rc;
}
static void qed_ll2_release_connection_ooo(struct qed_hwfn *p_hwfn,
struct qed_ll2_info *p_ll2_conn)
{
struct qed_ooo_buffer *p_buffer;
if (p_ll2_conn->input.conn_type != QED_LL2_TYPE_OOO)
return;
qed_ooo_release_all_isles(p_hwfn, p_hwfn->p_ooo_info);
while ((p_buffer = qed_ooo_get_free_buffer(p_hwfn,
p_hwfn->p_ooo_info))) {
dma_free_coherent(&p_hwfn->cdev->pdev->dev,
p_buffer->rx_buffer_size,
p_buffer->rx_buffer_virt_addr,
p_buffer->rx_buffer_phys_addr);
kfree(p_buffer);
}
}
void qed_ll2_release_connection(void *cxt, u8 connection_handle)
{
struct qed_hwfn *p_hwfn = cxt;
struct qed_ll2_info *p_ll2_conn = NULL;
p_ll2_conn = qed_ll2_handle_sanity(p_hwfn, connection_handle);
if (!p_ll2_conn)
return;
if (QED_LL2_RX_REGISTERED(p_ll2_conn)) {
p_ll2_conn->rx_queue.b_cb_registred = false;
qed_int_unregister_cb(p_hwfn, p_ll2_conn->rx_queue.rx_sb_index);
}
if (QED_LL2_TX_REGISTERED(p_ll2_conn)) {
p_ll2_conn->tx_queue.b_cb_registred = false;
qed_int_unregister_cb(p_hwfn, p_ll2_conn->tx_queue.tx_sb_index);
}
kfree(p_ll2_conn->tx_queue.descq_array);
qed_chain_free(p_hwfn->cdev, &p_ll2_conn->tx_queue.txq_chain);
kfree(p_ll2_conn->rx_queue.descq_array);
qed_chain_free(p_hwfn->cdev, &p_ll2_conn->rx_queue.rxq_chain);
qed_chain_free(p_hwfn->cdev, &p_ll2_conn->rx_queue.rcq_chain);
qed_cxt_release_cid(p_hwfn, p_ll2_conn->cid);
qed_ll2_release_connection_ooo(p_hwfn, p_ll2_conn);
mutex_lock(&p_ll2_conn->mutex);
p_ll2_conn->b_active = false;
mutex_unlock(&p_ll2_conn->mutex);
}
int qed_ll2_alloc(struct qed_hwfn *p_hwfn)
{
struct qed_ll2_info *p_ll2_connections;
u8 i;
p_ll2_connections = kcalloc(QED_MAX_NUM_OF_LL2_CONNECTIONS,
sizeof(struct qed_ll2_info), GFP_KERNEL);
if (!p_ll2_connections) {
DP_NOTICE(p_hwfn, "Failed to allocate `struct qed_ll2'\n");
return -ENOMEM;
}
for (i = 0; i < QED_MAX_NUM_OF_LL2_CONNECTIONS; i++)
p_ll2_connections[i].my_id = i;
p_hwfn->p_ll2_info = p_ll2_connections;
return 0;
}
void qed_ll2_setup(struct qed_hwfn *p_hwfn)
{
int i;
for (i = 0; i < QED_MAX_NUM_OF_LL2_CONNECTIONS; i++)
mutex_init(&p_hwfn->p_ll2_info[i].mutex);
}
void qed_ll2_free(struct qed_hwfn *p_hwfn)
{
if (!p_hwfn->p_ll2_info)
return;
kfree(p_hwfn->p_ll2_info);
p_hwfn->p_ll2_info = NULL;
}
static void _qed_ll2_get_port_stats(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt,
struct qed_ll2_stats *p_stats)
{
struct core_ll2_port_stats port_stats;
memset(&port_stats, 0, sizeof(port_stats));
qed_memcpy_from(p_hwfn, p_ptt, &port_stats,
BAR0_MAP_REG_TSDM_RAM +
TSTORM_LL2_PORT_STAT_OFFSET(MFW_PORT(p_hwfn)),
sizeof(port_stats));
p_stats->gsi_invalid_hdr = HILO_64_REGPAIR(port_stats.gsi_invalid_hdr);
p_stats->gsi_invalid_pkt_length =
HILO_64_REGPAIR(port_stats.gsi_invalid_pkt_length);
p_stats->gsi_unsupported_pkt_typ =
HILO_64_REGPAIR(port_stats.gsi_unsupported_pkt_typ);
p_stats->gsi_crcchksm_error =
HILO_64_REGPAIR(port_stats.gsi_crcchksm_error);
}
static void _qed_ll2_get_tstats(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt,
struct qed_ll2_info *p_ll2_conn,
struct qed_ll2_stats *p_stats)
{
struct core_ll2_tstorm_per_queue_stat tstats;
u8 qid = p_ll2_conn->queue_id;
u32 tstats_addr;
memset(&tstats, 0, sizeof(tstats));
tstats_addr = BAR0_MAP_REG_TSDM_RAM +
CORE_LL2_TSTORM_PER_QUEUE_STAT_OFFSET(qid);
qed_memcpy_from(p_hwfn, p_ptt, &tstats, tstats_addr, sizeof(tstats));
p_stats->packet_too_big_discard =
HILO_64_REGPAIR(tstats.packet_too_big_discard);
p_stats->no_buff_discard = HILO_64_REGPAIR(tstats.no_buff_discard);
}
static void _qed_ll2_get_ustats(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt,
struct qed_ll2_info *p_ll2_conn,
struct qed_ll2_stats *p_stats)
{
struct core_ll2_ustorm_per_queue_stat ustats;
u8 qid = p_ll2_conn->queue_id;
u32 ustats_addr;
memset(&ustats, 0, sizeof(ustats));
ustats_addr = BAR0_MAP_REG_USDM_RAM +
CORE_LL2_USTORM_PER_QUEUE_STAT_OFFSET(qid);
qed_memcpy_from(p_hwfn, p_ptt, &ustats, ustats_addr, sizeof(ustats));
p_stats->rcv_ucast_bytes = HILO_64_REGPAIR(ustats.rcv_ucast_bytes);
p_stats->rcv_mcast_bytes = HILO_64_REGPAIR(ustats.rcv_mcast_bytes);
p_stats->rcv_bcast_bytes = HILO_64_REGPAIR(ustats.rcv_bcast_bytes);
p_stats->rcv_ucast_pkts = HILO_64_REGPAIR(ustats.rcv_ucast_pkts);
p_stats->rcv_mcast_pkts = HILO_64_REGPAIR(ustats.rcv_mcast_pkts);
p_stats->rcv_bcast_pkts = HILO_64_REGPAIR(ustats.rcv_bcast_pkts);
}
static void _qed_ll2_get_pstats(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt,
struct qed_ll2_info *p_ll2_conn,
struct qed_ll2_stats *p_stats)
{
struct core_ll2_pstorm_per_queue_stat pstats;
u8 stats_id = p_ll2_conn->tx_stats_id;
u32 pstats_addr;
memset(&pstats, 0, sizeof(pstats));
pstats_addr = BAR0_MAP_REG_PSDM_RAM +
CORE_LL2_PSTORM_PER_QUEUE_STAT_OFFSET(stats_id);
qed_memcpy_from(p_hwfn, p_ptt, &pstats, pstats_addr, sizeof(pstats));
p_stats->sent_ucast_bytes = HILO_64_REGPAIR(pstats.sent_ucast_bytes);
p_stats->sent_mcast_bytes = HILO_64_REGPAIR(pstats.sent_mcast_bytes);
p_stats->sent_bcast_bytes = HILO_64_REGPAIR(pstats.sent_bcast_bytes);
p_stats->sent_ucast_pkts = HILO_64_REGPAIR(pstats.sent_ucast_pkts);
p_stats->sent_mcast_pkts = HILO_64_REGPAIR(pstats.sent_mcast_pkts);
p_stats->sent_bcast_pkts = HILO_64_REGPAIR(pstats.sent_bcast_pkts);
}
int qed_ll2_get_stats(void *cxt,
u8 connection_handle, struct qed_ll2_stats *p_stats)
{
struct qed_hwfn *p_hwfn = cxt;
struct qed_ll2_info *p_ll2_conn = NULL;
struct qed_ptt *p_ptt;
memset(p_stats, 0, sizeof(*p_stats));
if ((connection_handle >= QED_MAX_NUM_OF_LL2_CONNECTIONS) ||
!p_hwfn->p_ll2_info)
return -EINVAL;
p_ll2_conn = &p_hwfn->p_ll2_info[connection_handle];
p_ptt = qed_ptt_acquire(p_hwfn);
if (!p_ptt) {
DP_ERR(p_hwfn, "Failed to acquire ptt\n");
return -EINVAL;
}
if (p_ll2_conn->input.gsi_enable)
_qed_ll2_get_port_stats(p_hwfn, p_ptt, p_stats);
_qed_ll2_get_tstats(p_hwfn, p_ptt, p_ll2_conn, p_stats);
_qed_ll2_get_ustats(p_hwfn, p_ptt, p_ll2_conn, p_stats);
if (p_ll2_conn->tx_stats_en)
_qed_ll2_get_pstats(p_hwfn, p_ptt, p_ll2_conn, p_stats);
qed_ptt_release(p_hwfn, p_ptt);
return 0;
}
static void qed_ll2b_release_rx_packet(void *cxt,
u8 connection_handle,
void *cookie,
dma_addr_t rx_buf_addr,
bool b_last_packet)
{
struct qed_hwfn *p_hwfn = cxt;
qed_ll2_dealloc_buffer(p_hwfn->cdev, cookie);
}
static void qed_ll2_register_cb_ops(struct qed_dev *cdev,
const struct qed_ll2_cb_ops *ops,
void *cookie)
{
cdev->ll2->cbs = ops;
cdev->ll2->cb_cookie = cookie;
}
static void qed_ll2_set_conn_data(struct qed_dev *cdev,
struct qed_ll2_acquire_data *data,
struct qed_ll2_params *params,
enum qed_ll2_conn_type conn_type,
u8 *handle, bool lb)
{
memset(data, 0, sizeof(*data));
data->input.conn_type = conn_type;
data->input.mtu = params->mtu;
data->input.rx_num_desc = QED_LL2_RX_SIZE;
data->input.rx_drop_ttl0_flg = params->drop_ttl0_packets;
data->input.rx_vlan_removal_en = params->rx_vlan_stripping;
data->input.tx_num_desc = QED_LL2_TX_SIZE;
data->p_connection_handle = handle;
data->cbs = &ll2_cbs;
ll2_cbs.cookie = QED_LEADING_HWFN(cdev);
if (lb) {
data->input.tx_tc = PKT_LB_TC;
data->input.tx_dest = QED_LL2_TX_DEST_LB;
} else {
data->input.tx_tc = 0;
data->input.tx_dest = QED_LL2_TX_DEST_NW;
}
}
static int qed_ll2_start_ooo(struct qed_dev *cdev,
struct qed_ll2_params *params)
{
struct qed_hwfn *hwfn = QED_LEADING_HWFN(cdev);
u8 *handle = &hwfn->pf_params.iscsi_pf_params.ll2_ooo_queue_id;
struct qed_ll2_acquire_data data;
int rc;
qed_ll2_set_conn_data(cdev, &data, params,
QED_LL2_TYPE_OOO, handle, true);
rc = qed_ll2_acquire_connection(hwfn, &data);
if (rc) {
DP_INFO(cdev, "Failed to acquire LL2 OOO connection\n");
goto out;
}
rc = qed_ll2_establish_connection(hwfn, *handle);
if (rc) {
DP_INFO(cdev, "Failed to establist LL2 OOO connection\n");
goto fail;
}
return 0;
fail:
qed_ll2_release_connection(hwfn, *handle);
out:
*handle = QED_LL2_UNUSED_HANDLE;
return rc;
}
static int qed_ll2_start(struct qed_dev *cdev, struct qed_ll2_params *params)
{
struct qed_ll2_buffer *buffer, *tmp_buffer;
enum qed_ll2_conn_type conn_type;
struct qed_ll2_acquire_data data;
struct qed_ptt *p_ptt;
int rc, i;
INIT_LIST_HEAD(&cdev->ll2->list);
spin_lock_init(&cdev->ll2->lock);
cdev->ll2->rx_size = NET_SKB_PAD + ETH_HLEN +
L1_CACHE_BYTES + params->mtu;
DP_INFO(cdev, "Allocating LL2 buffers of size %08x bytes\n",
cdev->ll2->rx_size);
for (i = 0; i < QED_LL2_RX_SIZE; i++) {
buffer = kzalloc(sizeof(*buffer), GFP_KERNEL);
if (!buffer) {
DP_INFO(cdev, "Failed to allocate LL2 buffers\n");
goto fail;
}
rc = qed_ll2_alloc_buffer(cdev, (u8 **)&buffer->data,
&buffer->phys_addr);
if (rc) {
kfree(buffer);
goto fail;
}
list_add_tail(&buffer->list, &cdev->ll2->list);
}
switch (QED_LEADING_HWFN(cdev)->hw_info.personality) {
case QED_PCI_FCOE:
conn_type = QED_LL2_TYPE_FCOE;
break;
case QED_PCI_ISCSI:
conn_type = QED_LL2_TYPE_ISCSI;
break;
case QED_PCI_ETH_ROCE:
conn_type = QED_LL2_TYPE_ROCE;
break;
default:
conn_type = QED_LL2_TYPE_TEST;
}
qed_ll2_set_conn_data(cdev, &data, params, conn_type,
&cdev->ll2->handle, false);
rc = qed_ll2_acquire_connection(QED_LEADING_HWFN(cdev), &data);
if (rc) {
DP_INFO(cdev, "Failed to acquire LL2 connection\n");
goto fail;
}
rc = qed_ll2_establish_connection(QED_LEADING_HWFN(cdev),
cdev->ll2->handle);
if (rc) {
DP_INFO(cdev, "Failed to establish LL2 connection\n");
goto release_fail;
}
spin_lock_bh(&cdev->ll2->lock);
list_for_each_entry_safe(buffer, tmp_buffer, &cdev->ll2->list, list) {
rc = qed_ll2_post_rx_buffer(QED_LEADING_HWFN(cdev),
cdev->ll2->handle,
buffer->phys_addr, 0, buffer, 1);
if (rc) {
DP_INFO(cdev,
"Failed to post an Rx buffer; Deleting it\n");
dma_unmap_single(&cdev->pdev->dev, buffer->phys_addr,
cdev->ll2->rx_size, DMA_FROM_DEVICE);
kfree(buffer->data);
list_del(&buffer->list);
kfree(buffer);
} else {
cdev->ll2->rx_cnt++;
}
}
spin_unlock_bh(&cdev->ll2->lock);
if (!cdev->ll2->rx_cnt) {
DP_INFO(cdev, "Failed passing even a single Rx buffer\n");
goto release_terminate;
}
if (!is_valid_ether_addr(params->ll2_mac_address)) {
DP_INFO(cdev, "Invalid Ethernet address\n");
goto release_terminate;
}
if (cdev->hwfns[0].hw_info.personality == QED_PCI_ISCSI &&
cdev->hwfns[0].pf_params.iscsi_pf_params.ooo_enable) {
DP_VERBOSE(cdev, QED_MSG_STORAGE, "Starting OOO LL2 queue\n");
rc = qed_ll2_start_ooo(cdev, params);
if (rc) {
DP_INFO(cdev,
"Failed to initialize the OOO LL2 queue\n");
goto release_terminate;
}
}
p_ptt = qed_ptt_acquire(QED_LEADING_HWFN(cdev));
if (!p_ptt) {
DP_INFO(cdev, "Failed to acquire PTT\n");
goto release_terminate;
}
rc = qed_llh_add_mac_filter(QED_LEADING_HWFN(cdev), p_ptt,
params->ll2_mac_address);
qed_ptt_release(QED_LEADING_HWFN(cdev), p_ptt);
if (rc) {
DP_ERR(cdev, "Failed to allocate LLH filter\n");
goto release_terminate_all;
}
ether_addr_copy(cdev->ll2_mac_address, params->ll2_mac_address);
return 0;
release_terminate_all:
release_terminate:
qed_ll2_terminate_connection(QED_LEADING_HWFN(cdev), cdev->ll2->handle);
release_fail:
qed_ll2_release_connection(QED_LEADING_HWFN(cdev), cdev->ll2->handle);
fail:
qed_ll2_kill_buffers(cdev);
cdev->ll2->handle = QED_LL2_UNUSED_HANDLE;
return -EINVAL;
}
static int qed_ll2_stop(struct qed_dev *cdev)
{
struct qed_ptt *p_ptt;
int rc;
if (cdev->ll2->handle == QED_LL2_UNUSED_HANDLE)
return 0;
p_ptt = qed_ptt_acquire(QED_LEADING_HWFN(cdev));
if (!p_ptt) {
DP_INFO(cdev, "Failed to acquire PTT\n");
goto fail;
}
qed_llh_remove_mac_filter(QED_LEADING_HWFN(cdev), p_ptt,
cdev->ll2_mac_address);
qed_ptt_release(QED_LEADING_HWFN(cdev), p_ptt);
eth_zero_addr(cdev->ll2_mac_address);
if (cdev->hwfns[0].hw_info.personality == QED_PCI_ISCSI &&
cdev->hwfns[0].pf_params.iscsi_pf_params.ooo_enable)
qed_ll2_stop_ooo(cdev);
rc = qed_ll2_terminate_connection(QED_LEADING_HWFN(cdev),
cdev->ll2->handle);
if (rc)
DP_INFO(cdev, "Failed to terminate LL2 connection\n");
qed_ll2_kill_buffers(cdev);
qed_ll2_release_connection(QED_LEADING_HWFN(cdev), cdev->ll2->handle);
cdev->ll2->handle = QED_LL2_UNUSED_HANDLE;
return rc;
fail:
return -EINVAL;
}
static int qed_ll2_start_xmit(struct qed_dev *cdev, struct sk_buff *skb)
{
struct qed_ll2_tx_pkt_info pkt;
const skb_frag_t *frag;
int rc = -EINVAL, i;
dma_addr_t mapping;
u16 vlan = 0;
u8 flags = 0;
if (unlikely(skb->ip_summed != CHECKSUM_NONE)) {
DP_INFO(cdev, "Cannot transmit a checksumed packet\n");
return -EINVAL;
}
if (1 + skb_shinfo(skb)->nr_frags > CORE_LL2_TX_MAX_BDS_PER_PACKET) {
DP_ERR(cdev, "Cannot transmit a packet with %d fragments\n",
1 + skb_shinfo(skb)->nr_frags);
return -EINVAL;
}
mapping = dma_map_single(&cdev->pdev->dev, skb->data,
skb->len, DMA_TO_DEVICE);
if (unlikely(dma_mapping_error(&cdev->pdev->dev, mapping))) {
DP_NOTICE(cdev, "SKB mapping failed\n");
return -EINVAL;
}
if (!((vlan_get_protocol(skb) == htons(ETH_P_IPV6)) &&
ipv6_hdr(skb)->nexthdr == NEXTHDR_IPV6))
flags |= BIT(CORE_TX_BD_DATA_IP_CSUM_SHIFT);
if (skb_vlan_tag_present(skb)) {
vlan = skb_vlan_tag_get(skb);
flags |= BIT(CORE_TX_BD_DATA_VLAN_INSERTION_SHIFT);
}
memset(&pkt, 0, sizeof(pkt));
pkt.num_of_bds = 1 + skb_shinfo(skb)->nr_frags;
pkt.vlan = vlan;
pkt.bd_flags = flags;
pkt.tx_dest = QED_LL2_TX_DEST_NW;
pkt.first_frag = mapping;
pkt.first_frag_len = skb->len;
pkt.cookie = skb;
rc = qed_ll2_prepare_tx_packet(&cdev->hwfns[0], cdev->ll2->handle,
&pkt, 1);
if (rc)
goto err;
for (i = 0; i < skb_shinfo(skb)->nr_frags; i++) {
frag = &skb_shinfo(skb)->frags[i];
mapping = skb_frag_dma_map(&cdev->pdev->dev, frag, 0,
skb_frag_size(frag), DMA_TO_DEVICE);
if (unlikely(dma_mapping_error(&cdev->pdev->dev, mapping))) {
DP_NOTICE(cdev,
"Unable to map frag - dropping packet\n");
goto err;
}
rc = qed_ll2_set_fragment_of_tx_packet(QED_LEADING_HWFN(cdev),
cdev->ll2->handle,
mapping,
skb_frag_size(frag));
if (rc)
goto err2;
}
return 0;
err:
dma_unmap_single(&cdev->pdev->dev, mapping, skb->len, DMA_TO_DEVICE);
err2:
return rc;
}
static int qed_ll2_stats(struct qed_dev *cdev, struct qed_ll2_stats *stats)
{
if (!cdev->ll2)
return -EINVAL;
return qed_ll2_get_stats(QED_LEADING_HWFN(cdev),
cdev->ll2->handle, stats);
}
int qed_ll2_alloc_if(struct qed_dev *cdev)
{
cdev->ll2 = kzalloc(sizeof(*cdev->ll2), GFP_KERNEL);
return cdev->ll2 ? 0 : -ENOMEM;
}
void qed_ll2_dealloc_if(struct qed_dev *cdev)
{
kfree(cdev->ll2);
cdev->ll2 = NULL;
}
