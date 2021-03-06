static inline struct net_device *bnx2fc_netdev(const struct fc_lport *lport)
{
return ((struct bnx2fc_interface *)
((struct fcoe_port *)lport_priv(lport))->priv)->netdev;
}
static void bnx2fc_fcf_get_vlan_id(struct fcoe_fcf_device *fcf_dev)
{
struct fcoe_ctlr_device *ctlr_dev =
fcoe_fcf_dev_to_ctlr_dev(fcf_dev);
struct fcoe_ctlr *ctlr = fcoe_ctlr_device_priv(ctlr_dev);
struct bnx2fc_interface *fcoe = fcoe_ctlr_priv(ctlr);
fcf_dev->vlan_id = fcoe->vlan_id;
}
static void bnx2fc_clean_rx_queue(struct fc_lport *lp)
{
struct fcoe_percpu_s *bg;
struct fcoe_rcv_info *fr;
struct sk_buff_head *list;
struct sk_buff *skb, *next;
struct sk_buff *head;
bg = &bnx2fc_global;
spin_lock_bh(&bg->fcoe_rx_list.lock);
list = &bg->fcoe_rx_list;
head = list->next;
for (skb = head; skb != (struct sk_buff *)list;
skb = next) {
next = skb->next;
fr = fcoe_dev_from_skb(skb);
if (fr->fr_dev == lp) {
__skb_unlink(skb, list);
kfree_skb(skb);
}
}
spin_unlock_bh(&bg->fcoe_rx_list.lock);
}
int bnx2fc_get_paged_crc_eof(struct sk_buff *skb, int tlen)
{
int rc;
spin_lock(&bnx2fc_global_lock);
rc = fcoe_get_paged_crc_eof(skb, tlen, &bnx2fc_global);
spin_unlock(&bnx2fc_global_lock);
return rc;
}
static void bnx2fc_abort_io(struct fc_lport *lport)
{
}
static void bnx2fc_cleanup(struct fc_lport *lport)
{
struct fcoe_port *port = lport_priv(lport);
struct bnx2fc_interface *interface = port->priv;
struct bnx2fc_hba *hba = interface->hba;
struct bnx2fc_rport *tgt;
int i;
BNX2FC_MISC_DBG("Entered %s\n", __func__);
mutex_lock(&hba->hba_mutex);
spin_lock_bh(&hba->hba_lock);
for (i = 0; i < BNX2FC_NUM_MAX_SESS; i++) {
tgt = hba->tgt_ofld_list[i];
if (tgt) {
if (tgt->port == port) {
spin_unlock_bh(&hba->hba_lock);
BNX2FC_TGT_DBG(tgt, "flush/cleanup\n");
bnx2fc_flush_active_ios(tgt);
spin_lock_bh(&hba->hba_lock);
}
}
}
spin_unlock_bh(&hba->hba_lock);
mutex_unlock(&hba->hba_mutex);
}
static int bnx2fc_xmit_l2_frame(struct bnx2fc_rport *tgt,
struct fc_frame *fp)
{
struct fc_rport_priv *rdata = tgt->rdata;
struct fc_frame_header *fh;
int rc = 0;
fh = fc_frame_header_get(fp);
BNX2FC_TGT_DBG(tgt, "Xmit L2 frame rport = 0x%x, oxid = 0x%x, "
"r_ctl = 0x%x\n", rdata->ids.port_id,
ntohs(fh->fh_ox_id), fh->fh_r_ctl);
if ((fh->fh_type == FC_TYPE_ELS) &&
(fh->fh_r_ctl == FC_RCTL_ELS_REQ)) {
switch (fc_frame_payload_op(fp)) {
case ELS_ADISC:
rc = bnx2fc_send_adisc(tgt, fp);
break;
case ELS_LOGO:
rc = bnx2fc_send_logo(tgt, fp);
break;
case ELS_RLS:
rc = bnx2fc_send_rls(tgt, fp);
break;
default:
break;
}
} else if ((fh->fh_type == FC_TYPE_BLS) &&
(fh->fh_r_ctl == FC_RCTL_BA_ABTS))
BNX2FC_TGT_DBG(tgt, "ABTS frame\n");
else {
BNX2FC_TGT_DBG(tgt, "Send L2 frame type 0x%x "
"rctl 0x%x thru non-offload path\n",
fh->fh_type, fh->fh_r_ctl);
return -ENODEV;
}
if (rc)
return -ENOMEM;
else
return 0;
}
static int bnx2fc_xmit(struct fc_lport *lport, struct fc_frame *fp)
{
struct ethhdr *eh;
struct fcoe_crc_eof *cp;
struct sk_buff *skb;
struct fc_frame_header *fh;
struct bnx2fc_interface *interface;
struct fcoe_ctlr *ctlr;
struct bnx2fc_hba *hba;
struct fcoe_port *port;
struct fcoe_hdr *hp;
struct bnx2fc_rport *tgt;
struct fc_stats *stats;
u8 sof, eof;
u32 crc;
unsigned int hlen, tlen, elen;
int wlen, rc = 0;
port = (struct fcoe_port *)lport_priv(lport);
interface = port->priv;
ctlr = bnx2fc_to_ctlr(interface);
hba = interface->hba;
fh = fc_frame_header_get(fp);
skb = fp_skb(fp);
if (!lport->link_up) {
BNX2FC_HBA_DBG(lport, "bnx2fc_xmit link down\n");
kfree_skb(skb);
return 0;
}
if (unlikely(fh->fh_r_ctl == FC_RCTL_ELS_REQ)) {
if (!ctlr->sel_fcf) {
BNX2FC_HBA_DBG(lport, "FCF not selected yet!\n");
kfree_skb(skb);
return -EINVAL;
}
if (fcoe_ctlr_els_send(ctlr, lport, skb))
return 0;
}
sof = fr_sof(fp);
eof = fr_eof(fp);
spin_lock_bh(&hba->hba_lock);
tgt = bnx2fc_tgt_lookup(port, ntoh24(fh->fh_d_id));
if (tgt && (test_bit(BNX2FC_FLAG_SESSION_READY, &tgt->flags))) {
BNX2FC_HBA_DBG(lport, "xmit: Frame is for offloaded session "
"port_id = 0x%x\n", ntoh24(fh->fh_d_id));
spin_unlock_bh(&hba->hba_lock);
rc = bnx2fc_xmit_l2_frame(tgt, fp);
if (rc != -ENODEV) {
kfree_skb(skb);
return rc;
}
} else {
spin_unlock_bh(&hba->hba_lock);
}
elen = sizeof(struct ethhdr);
hlen = sizeof(struct fcoe_hdr);
tlen = sizeof(struct fcoe_crc_eof);
wlen = (skb->len - tlen + sizeof(crc)) / FCOE_WORD_TO_BYTE;
skb->ip_summed = CHECKSUM_NONE;
crc = fcoe_fc_crc(fp);
if (skb_is_nonlinear(skb)) {
skb_frag_t *frag;
if (bnx2fc_get_paged_crc_eof(skb, tlen)) {
kfree_skb(skb);
return -ENOMEM;
}
frag = &skb_shinfo(skb)->frags[skb_shinfo(skb)->nr_frags - 1];
cp = kmap_atomic(skb_frag_page(frag)) + frag->page_offset;
} else {
cp = (struct fcoe_crc_eof *)skb_put(skb, tlen);
}
memset(cp, 0, sizeof(*cp));
cp->fcoe_eof = eof;
cp->fcoe_crc32 = cpu_to_le32(~crc);
if (skb_is_nonlinear(skb)) {
kunmap_atomic(cp);
cp = NULL;
}
skb_push(skb, elen + hlen);
skb_reset_mac_header(skb);
skb_reset_network_header(skb);
skb->mac_len = elen;
skb->protocol = htons(ETH_P_FCOE);
skb->dev = interface->netdev;
eh = eth_hdr(skb);
eh->h_proto = htons(ETH_P_FCOE);
if (ctlr->map_dest)
fc_fcoe_set_mac(eh->h_dest, fh->fh_d_id);
else
memcpy(eh->h_dest, ctlr->dest_addr, ETH_ALEN);
if (unlikely(ctlr->flogi_oxid != FC_XID_UNKNOWN))
memcpy(eh->h_source, ctlr->ctl_src_addr, ETH_ALEN);
else
memcpy(eh->h_source, port->data_src_addr, ETH_ALEN);
hp = (struct fcoe_hdr *)(eh + 1);
memset(hp, 0, sizeof(*hp));
if (FC_FCOE_VER)
FC_FCOE_ENCAPS_VER(hp, FC_FCOE_VER);
hp->fcoe_sof = sof;
if (lport->seq_offload && fr_max_payload(fp)) {
skb_shinfo(skb)->gso_type = SKB_GSO_FCOE;
skb_shinfo(skb)->gso_size = fr_max_payload(fp);
} else {
skb_shinfo(skb)->gso_type = 0;
skb_shinfo(skb)->gso_size = 0;
}
stats = per_cpu_ptr(lport->stats, get_cpu());
stats->TxFrames++;
stats->TxWords += wlen;
put_cpu();
fr_dev(fp) = lport;
if (port->fcoe_pending_queue.qlen)
fcoe_check_wait_queue(lport, skb);
else if (fcoe_start_io(skb))
fcoe_check_wait_queue(lport, skb);
return 0;
}
static int bnx2fc_rcv(struct sk_buff *skb, struct net_device *dev,
struct packet_type *ptype, struct net_device *olddev)
{
struct fc_lport *lport;
struct bnx2fc_interface *interface;
struct fcoe_ctlr *ctlr;
struct fc_frame_header *fh;
struct fcoe_rcv_info *fr;
struct fcoe_percpu_s *bg;
unsigned short oxid;
interface = container_of(ptype, struct bnx2fc_interface,
fcoe_packet_type);
ctlr = bnx2fc_to_ctlr(interface);
lport = ctlr->lp;
if (unlikely(lport == NULL)) {
printk(KERN_ERR PFX "bnx2fc_rcv: lport is NULL\n");
goto err;
}
if (unlikely(eth_hdr(skb)->h_proto != htons(ETH_P_FCOE))) {
printk(KERN_ERR PFX "bnx2fc_rcv: Wrong FC type frame\n");
goto err;
}
if (unlikely((skb->len < FCOE_MIN_FRAME) ||
!pskb_may_pull(skb, FCOE_HEADER_LEN)))
goto err;
skb_set_transport_header(skb, sizeof(struct fcoe_hdr));
fh = (struct fc_frame_header *) skb_transport_header(skb);
oxid = ntohs(fh->fh_ox_id);
fr = fcoe_dev_from_skb(skb);
fr->fr_dev = lport;
bg = &bnx2fc_global;
spin_lock(&bg->fcoe_rx_list.lock);
__skb_queue_tail(&bg->fcoe_rx_list, skb);
if (bg->fcoe_rx_list.qlen == 1)
wake_up_process(bg->thread);
spin_unlock(&bg->fcoe_rx_list.lock);
return 0;
err:
kfree_skb(skb);
return -1;
}
static int bnx2fc_l2_rcv_thread(void *arg)
{
struct fcoe_percpu_s *bg = arg;
struct sk_buff *skb;
set_user_nice(current, -20);
set_current_state(TASK_INTERRUPTIBLE);
while (!kthread_should_stop()) {
schedule();
spin_lock_bh(&bg->fcoe_rx_list.lock);
while ((skb = __skb_dequeue(&bg->fcoe_rx_list)) != NULL) {
spin_unlock_bh(&bg->fcoe_rx_list.lock);
bnx2fc_recv_frame(skb);
spin_lock_bh(&bg->fcoe_rx_list.lock);
}
__set_current_state(TASK_INTERRUPTIBLE);
spin_unlock_bh(&bg->fcoe_rx_list.lock);
}
__set_current_state(TASK_RUNNING);
return 0;
}
static void bnx2fc_recv_frame(struct sk_buff *skb)
{
u32 fr_len;
struct fc_lport *lport;
struct fcoe_rcv_info *fr;
struct fc_stats *stats;
struct fc_frame_header *fh;
struct fcoe_crc_eof crc_eof;
struct fc_frame *fp;
struct fc_lport *vn_port;
struct fcoe_port *port;
u8 *mac = NULL;
u8 *dest_mac = NULL;
struct fcoe_hdr *hp;
fr = fcoe_dev_from_skb(skb);
lport = fr->fr_dev;
if (unlikely(lport == NULL)) {
printk(KERN_ERR PFX "Invalid lport struct\n");
kfree_skb(skb);
return;
}
if (skb_is_nonlinear(skb))
skb_linearize(skb);
mac = eth_hdr(skb)->h_source;
dest_mac = eth_hdr(skb)->h_dest;
hp = (struct fcoe_hdr *) skb_network_header(skb);
fh = (struct fc_frame_header *) skb_transport_header(skb);
skb_pull(skb, sizeof(struct fcoe_hdr));
fr_len = skb->len - sizeof(struct fcoe_crc_eof);
stats = per_cpu_ptr(lport->stats, get_cpu());
stats->RxFrames++;
stats->RxWords += fr_len / FCOE_WORD_TO_BYTE;
fp = (struct fc_frame *)skb;
fc_frame_init(fp);
fr_dev(fp) = lport;
fr_sof(fp) = hp->fcoe_sof;
if (skb_copy_bits(skb, fr_len, &crc_eof, sizeof(crc_eof))) {
put_cpu();
kfree_skb(skb);
return;
}
fr_eof(fp) = crc_eof.fcoe_eof;
fr_crc(fp) = crc_eof.fcoe_crc32;
if (pskb_trim(skb, fr_len)) {
put_cpu();
kfree_skb(skb);
return;
}
fh = fc_frame_header_get(fp);
vn_port = fc_vport_id_lookup(lport, ntoh24(fh->fh_d_id));
if (vn_port) {
port = lport_priv(vn_port);
if (compare_ether_addr(port->data_src_addr, dest_mac)
!= 0) {
BNX2FC_HBA_DBG(lport, "fpma mismatch\n");
put_cpu();
kfree_skb(skb);
return;
}
}
if (fh->fh_r_ctl == FC_RCTL_DD_SOL_DATA &&
fh->fh_type == FC_TYPE_FCP) {
put_cpu();
kfree_skb(skb);
return;
}
if (fh->fh_r_ctl == FC_RCTL_ELS_REQ &&
fh->fh_type == FC_TYPE_ELS) {
switch (fc_frame_payload_op(fp)) {
case ELS_LOGO:
if (ntoh24(fh->fh_s_id) == FC_FID_FLOGI) {
put_cpu();
kfree_skb(skb);
return;
}
break;
}
}
if (fh->fh_r_ctl == FC_RCTL_BA_ABTS) {
put_cpu();
kfree_skb(skb);
return;
}
if (le32_to_cpu(fr_crc(fp)) !=
~crc32(~0, skb->data, fr_len)) {
if (stats->InvalidCRCCount < 5)
printk(KERN_WARNING PFX "dropping frame with "
"CRC error\n");
stats->InvalidCRCCount++;
put_cpu();
kfree_skb(skb);
return;
}
put_cpu();
fc_exch_recv(lport, fp);
}
int bnx2fc_percpu_io_thread(void *arg)
{
struct bnx2fc_percpu_s *p = arg;
struct bnx2fc_work *work, *tmp;
LIST_HEAD(work_list);
set_user_nice(current, -20);
set_current_state(TASK_INTERRUPTIBLE);
while (!kthread_should_stop()) {
schedule();
spin_lock_bh(&p->fp_work_lock);
while (!list_empty(&p->work_list)) {
list_splice_init(&p->work_list, &work_list);
spin_unlock_bh(&p->fp_work_lock);
list_for_each_entry_safe(work, tmp, &work_list, list) {
list_del_init(&work->list);
bnx2fc_process_cq_compl(work->tgt, work->wqe);
kfree(work);
}
spin_lock_bh(&p->fp_work_lock);
}
__set_current_state(TASK_INTERRUPTIBLE);
spin_unlock_bh(&p->fp_work_lock);
}
__set_current_state(TASK_RUNNING);
return 0;
}
static struct fc_host_statistics *bnx2fc_get_host_stats(struct Scsi_Host *shost)
{
struct fc_host_statistics *bnx2fc_stats;
struct fc_lport *lport = shost_priv(shost);
struct fcoe_port *port = lport_priv(lport);
struct bnx2fc_interface *interface = port->priv;
struct bnx2fc_hba *hba = interface->hba;
struct fcoe_statistics_params *fw_stats;
int rc = 0;
fw_stats = (struct fcoe_statistics_params *)hba->stats_buffer;
if (!fw_stats)
return NULL;
bnx2fc_stats = fc_get_host_stats(shost);
init_completion(&hba->stat_req_done);
if (bnx2fc_send_stat_req(hba))
return bnx2fc_stats;
rc = wait_for_completion_timeout(&hba->stat_req_done, (2 * HZ));
if (!rc) {
BNX2FC_HBA_DBG(lport, "FW stat req timed out\n");
return bnx2fc_stats;
}
BNX2FC_STATS(hba, rx_stat2, fc_crc_cnt);
bnx2fc_stats->invalid_crc_count += hba->bfw_stats.fc_crc_cnt;
BNX2FC_STATS(hba, tx_stat, fcoe_tx_pkt_cnt);
bnx2fc_stats->tx_frames += hba->bfw_stats.fcoe_tx_pkt_cnt;
BNX2FC_STATS(hba, tx_stat, fcoe_tx_byte_cnt);
bnx2fc_stats->tx_words += ((hba->bfw_stats.fcoe_tx_byte_cnt) / 4);
BNX2FC_STATS(hba, rx_stat0, fcoe_rx_pkt_cnt);
bnx2fc_stats->rx_frames += hba->bfw_stats.fcoe_rx_pkt_cnt;
BNX2FC_STATS(hba, rx_stat0, fcoe_rx_byte_cnt);
bnx2fc_stats->rx_words += ((hba->bfw_stats.fcoe_rx_byte_cnt) / 4);
bnx2fc_stats->dumped_frames = 0;
bnx2fc_stats->lip_count = 0;
bnx2fc_stats->nos_count = 0;
bnx2fc_stats->loss_of_sync_count = 0;
bnx2fc_stats->loss_of_signal_count = 0;
bnx2fc_stats->prim_seq_protocol_err_count = 0;
memcpy(&hba->prev_stats, hba->stats_buffer,
sizeof(struct fcoe_statistics_params));
return bnx2fc_stats;
}
static int bnx2fc_shost_config(struct fc_lport *lport, struct device *dev)
{
struct fcoe_port *port = lport_priv(lport);
struct bnx2fc_interface *interface = port->priv;
struct bnx2fc_hba *hba = interface->hba;
struct Scsi_Host *shost = lport->host;
int rc = 0;
shost->max_cmd_len = BNX2FC_MAX_CMD_LEN;
shost->max_lun = BNX2FC_MAX_LUN;
shost->max_id = BNX2FC_MAX_FCP_TGT;
shost->max_channel = 0;
if (lport->vport)
shost->transportt = bnx2fc_vport_xport_template;
else
shost->transportt = bnx2fc_transport_template;
rc = scsi_add_host(lport->host, dev);
if (rc) {
printk(KERN_ERR PFX "Error on scsi_add_host\n");
return rc;
}
if (!lport->vport)
fc_host_max_npiv_vports(lport->host) = USHRT_MAX;
snprintf(fc_host_symbolic_name(lport->host), 256,
"%s (Broadcom %s) v%s over %s",
BNX2FC_NAME, hba->chip_num, BNX2FC_VERSION,
interface->netdev->name);
return 0;
}
static int bnx2fc_link_ok(struct fc_lport *lport)
{
struct fcoe_port *port = lport_priv(lport);
struct bnx2fc_interface *interface = port->priv;
struct bnx2fc_hba *hba = interface->hba;
struct net_device *dev = hba->phys_dev;
int rc = 0;
if ((dev->flags & IFF_UP) && netif_carrier_ok(dev))
clear_bit(ADAPTER_STATE_LINK_DOWN, &hba->adapter_state);
else {
set_bit(ADAPTER_STATE_LINK_DOWN, &hba->adapter_state);
rc = -1;
}
return rc;
}
void bnx2fc_get_link_state(struct bnx2fc_hba *hba)
{
if (test_bit(__LINK_STATE_NOCARRIER, &hba->phys_dev->state))
set_bit(ADAPTER_STATE_LINK_DOWN, &hba->adapter_state);
else
clear_bit(ADAPTER_STATE_LINK_DOWN, &hba->adapter_state);
}
static int bnx2fc_net_config(struct fc_lport *lport, struct net_device *netdev)
{
struct bnx2fc_hba *hba;
struct bnx2fc_interface *interface;
struct fcoe_ctlr *ctlr;
struct fcoe_port *port;
u64 wwnn, wwpn;
port = lport_priv(lport);
interface = port->priv;
ctlr = bnx2fc_to_ctlr(interface);
hba = interface->hba;
if (!hba->phys_dev->ethtool_ops ||
!hba->phys_dev->ethtool_ops->get_pauseparam)
return -EOPNOTSUPP;
if (fc_set_mfs(lport, BNX2FC_MFS))
return -EINVAL;
skb_queue_head_init(&port->fcoe_pending_queue);
port->fcoe_pending_queue_active = 0;
setup_timer(&port->timer, fcoe_queue_timer, (unsigned long) lport);
fcoe_link_speed_update(lport);
if (!lport->vport) {
if (fcoe_get_wwn(netdev, &wwnn, NETDEV_FCOE_WWNN))
wwnn = fcoe_wwn_from_mac(ctlr->ctl_src_addr,
1, 0);
BNX2FC_HBA_DBG(lport, "WWNN = 0x%llx\n", wwnn);
fc_set_wwnn(lport, wwnn);
if (fcoe_get_wwn(netdev, &wwpn, NETDEV_FCOE_WWPN))
wwpn = fcoe_wwn_from_mac(ctlr->ctl_src_addr,
2, 0);
BNX2FC_HBA_DBG(lport, "WWPN = 0x%llx\n", wwpn);
fc_set_wwpn(lport, wwpn);
}
return 0;
}
static void bnx2fc_destroy_timer(unsigned long data)
{
struct bnx2fc_hba *hba = (struct bnx2fc_hba *)data;
printk(KERN_ERR PFX "ERROR:bnx2fc_destroy_timer - "
"Destroy compl not received!!\n");
set_bit(BNX2FC_FLAG_DESTROY_CMPL, &hba->flags);
wake_up_interruptible(&hba->destroy_wait);
}
static void bnx2fc_indicate_netevent(void *context, unsigned long event,
u16 vlan_id)
{
struct bnx2fc_hba *hba = (struct bnx2fc_hba *)context;
struct fcoe_ctlr_device *cdev;
struct fc_lport *lport;
struct fc_lport *vport;
struct bnx2fc_interface *interface, *tmp;
struct fcoe_ctlr *ctlr;
int wait_for_upload = 0;
u32 link_possible = 1;
if (vlan_id != 0 && event != NETDEV_UNREGISTER)
return;
switch (event) {
case NETDEV_UP:
if (!test_bit(ADAPTER_STATE_UP, &hba->adapter_state))
printk(KERN_ERR "indicate_netevent: "\
"hba is not UP!!\n");
break;
case NETDEV_DOWN:
clear_bit(ADAPTER_STATE_GOING_DOWN, &hba->adapter_state);
clear_bit(ADAPTER_STATE_UP, &hba->adapter_state);
link_possible = 0;
break;
case NETDEV_GOING_DOWN:
set_bit(ADAPTER_STATE_GOING_DOWN, &hba->adapter_state);
link_possible = 0;
break;
case NETDEV_CHANGE:
break;
case NETDEV_UNREGISTER:
if (!vlan_id)
return;
mutex_lock(&bnx2fc_dev_lock);
list_for_each_entry_safe(interface, tmp, &if_list, list) {
if (interface->hba == hba &&
interface->vlan_id == (vlan_id & VLAN_VID_MASK))
__bnx2fc_destroy(interface);
}
mutex_unlock(&bnx2fc_dev_lock);
return;
default:
printk(KERN_ERR PFX "Unknown netevent %ld", event);
return;
}
mutex_lock(&bnx2fc_dev_lock);
list_for_each_entry(interface, &if_list, list) {
if (interface->hba != hba)
continue;
ctlr = bnx2fc_to_ctlr(interface);
lport = ctlr->lp;
BNX2FC_HBA_DBG(lport, "netevent handler - event=%s %ld\n",
interface->netdev->name, event);
fcoe_link_speed_update(lport);
cdev = fcoe_ctlr_to_ctlr_dev(ctlr);
if (link_possible && !bnx2fc_link_ok(lport)) {
switch (cdev->enabled) {
case FCOE_CTLR_DISABLED:
pr_info("Link up while interface is disabled.\n");
break;
case FCOE_CTLR_ENABLED:
case FCOE_CTLR_UNUSED:
fc_set_mfs(lport, BNX2FC_MFS);
if (interface->enabled)
fcoe_ctlr_link_up(ctlr);
};
} else if (fcoe_ctlr_link_down(ctlr)) {
switch (cdev->enabled) {
case FCOE_CTLR_DISABLED:
pr_info("Link down while interface is disabled.\n");
break;
case FCOE_CTLR_ENABLED:
case FCOE_CTLR_UNUSED:
mutex_lock(&lport->lp_mutex);
list_for_each_entry(vport, &lport->vports, list)
fc_host_port_type(vport->host) =
FC_PORTTYPE_UNKNOWN;
mutex_unlock(&lport->lp_mutex);
fc_host_port_type(lport->host) =
FC_PORTTYPE_UNKNOWN;
per_cpu_ptr(lport->stats,
get_cpu())->LinkFailureCount++;
put_cpu();
fcoe_clean_pending_queue(lport);
wait_for_upload = 1;
};
}
}
mutex_unlock(&bnx2fc_dev_lock);
if (wait_for_upload) {
clear_bit(ADAPTER_STATE_READY, &hba->adapter_state);
init_waitqueue_head(&hba->shutdown_wait);
BNX2FC_MISC_DBG("indicate_netevent "
"num_ofld_sess = %d\n",
hba->num_ofld_sess);
hba->wait_for_link_down = 1;
wait_event_interruptible(hba->shutdown_wait,
(hba->num_ofld_sess == 0));
BNX2FC_MISC_DBG("wakeup - num_ofld_sess = %d\n",
hba->num_ofld_sess);
hba->wait_for_link_down = 0;
if (signal_pending(current))
flush_signals(current);
}
}
static int bnx2fc_libfc_config(struct fc_lport *lport)
{
memcpy(&lport->tt, &bnx2fc_libfc_fcn_templ,
sizeof(struct libfc_function_template));
fc_elsct_init(lport);
fc_exch_init(lport);
fc_rport_init(lport);
fc_disc_init(lport);
fc_disc_config(lport, lport);
return 0;
}
static int bnx2fc_em_config(struct fc_lport *lport, struct bnx2fc_hba *hba)
{
int fcoe_min_xid, fcoe_max_xid;
fcoe_min_xid = hba->max_xid + 1;
if (nr_cpu_ids <= 2)
fcoe_max_xid = hba->max_xid + FCOE_XIDS_PER_CPU_OFFSET;
else
fcoe_max_xid = hba->max_xid + FCOE_MAX_XID_OFFSET;
if (!fc_exch_mgr_alloc(lport, FC_CLASS_3, fcoe_min_xid,
fcoe_max_xid, NULL)) {
printk(KERN_ERR PFX "em_config:fc_exch_mgr_alloc failed\n");
return -ENOMEM;
}
return 0;
}
static int bnx2fc_lport_config(struct fc_lport *lport)
{
lport->link_up = 0;
lport->qfull = 0;
lport->max_retry_count = BNX2FC_MAX_RETRY_CNT;
lport->max_rport_retry_count = BNX2FC_MAX_RPORT_RETRY_CNT;
lport->e_d_tov = 2 * 1000;
lport->r_a_tov = 10 * 1000;
lport->service_params = (FCP_SPPF_INIT_FCN | FCP_SPPF_RD_XRDY_DIS |
FCP_SPPF_RETRY | FCP_SPPF_CONF_COMPL);
lport->does_npiv = 1;
memset(&lport->rnid_gen, 0, sizeof(struct fc_els_rnid_gen));
lport->rnid_gen.rnid_atype = BNX2FC_RNID_HBA;
if (fc_lport_init_stats(lport))
return -ENOMEM;
fc_lport_config(lport);
return 0;
}
static int bnx2fc_fip_recv(struct sk_buff *skb, struct net_device *dev,
struct packet_type *ptype,
struct net_device *orig_dev)
{
struct bnx2fc_interface *interface;
struct fcoe_ctlr *ctlr;
interface = container_of(ptype, struct bnx2fc_interface,
fip_packet_type);
ctlr = bnx2fc_to_ctlr(interface);
fcoe_ctlr_recv(ctlr, skb);
return 0;
}
static void bnx2fc_update_src_mac(struct fc_lport *lport, u8 *addr)
{
struct fcoe_port *port = lport_priv(lport);
memcpy(port->data_src_addr, addr, ETH_ALEN);
}
static u8 *bnx2fc_get_src_mac(struct fc_lport *lport)
{
struct fcoe_port *port;
port = (struct fcoe_port *)lport_priv(lport);
return port->data_src_addr;
}
static void bnx2fc_fip_send(struct fcoe_ctlr *fip, struct sk_buff *skb)
{
skb->dev = bnx2fc_from_ctlr(fip)->netdev;
dev_queue_xmit(skb);
}
static int bnx2fc_vport_create(struct fc_vport *vport, bool disabled)
{
struct Scsi_Host *shost = vport_to_shost(vport);
struct fc_lport *n_port = shost_priv(shost);
struct fcoe_port *port = lport_priv(n_port);
struct bnx2fc_interface *interface = port->priv;
struct net_device *netdev = interface->netdev;
struct fc_lport *vn_port;
int rc;
char buf[32];
rc = fcoe_validate_vport_create(vport);
if (rc) {
fcoe_wwn_to_str(vport->port_name, buf, sizeof(buf));
printk(KERN_ERR PFX "Failed to create vport, "
"WWPN (0x%s) already exists\n",
buf);
return rc;
}
if (!test_bit(BNX2FC_FLAG_FW_INIT_DONE, &interface->hba->flags)) {
printk(KERN_ERR PFX "vn ports cannot be created on"
"this interface\n");
return -EIO;
}
rtnl_lock();
mutex_lock(&bnx2fc_dev_lock);
vn_port = bnx2fc_if_create(interface, &vport->dev, 1);
mutex_unlock(&bnx2fc_dev_lock);
rtnl_unlock();
if (IS_ERR(vn_port)) {
printk(KERN_ERR PFX "bnx2fc_vport_create (%s) failed\n",
netdev->name);
return -EIO;
}
if (disabled) {
fc_vport_set_state(vport, FC_VPORT_DISABLED);
} else {
vn_port->boot_time = jiffies;
fc_lport_init(vn_port);
fc_fabric_login(vn_port);
fc_vport_setlink(vn_port);
}
return 0;
}
static void bnx2fc_free_vport(struct bnx2fc_hba *hba, struct fc_lport *lport)
{
struct bnx2fc_lport *blport, *tmp;
spin_lock_bh(&hba->hba_lock);
list_for_each_entry_safe(blport, tmp, &hba->vports, list) {
if (blport->lport == lport) {
list_del(&blport->list);
kfree(blport);
}
}
spin_unlock_bh(&hba->hba_lock);
}
static int bnx2fc_vport_destroy(struct fc_vport *vport)
{
struct Scsi_Host *shost = vport_to_shost(vport);
struct fc_lport *n_port = shost_priv(shost);
struct fc_lport *vn_port = vport->dd_data;
struct fcoe_port *port = lport_priv(vn_port);
struct bnx2fc_interface *interface = port->priv;
struct fc_lport *v_port;
bool found = false;
mutex_lock(&n_port->lp_mutex);
list_for_each_entry(v_port, &n_port->vports, list)
if (v_port->vport == vport) {
found = true;
break;
}
if (!found) {
mutex_unlock(&n_port->lp_mutex);
return -ENOENT;
}
list_del(&vn_port->list);
mutex_unlock(&n_port->lp_mutex);
bnx2fc_free_vport(interface->hba, port->lport);
bnx2fc_port_shutdown(port->lport);
bnx2fc_interface_put(interface);
queue_work(bnx2fc_wq, &port->destroy_work);
return 0;
}
static int bnx2fc_vport_disable(struct fc_vport *vport, bool disable)
{
struct fc_lport *lport = vport->dd_data;
if (disable) {
fc_vport_set_state(vport, FC_VPORT_DISABLED);
fc_fabric_logoff(lport);
} else {
lport->boot_time = jiffies;
fc_fabric_login(lport);
fc_vport_setlink(lport);
}
return 0;
}
static int bnx2fc_interface_setup(struct bnx2fc_interface *interface)
{
struct net_device *netdev = interface->netdev;
struct net_device *physdev = interface->hba->phys_dev;
struct fcoe_ctlr *ctlr = bnx2fc_to_ctlr(interface);
struct netdev_hw_addr *ha;
int sel_san_mac = 0;
rcu_read_lock();
for_each_dev_addr(physdev, ha) {
BNX2FC_MISC_DBG("net_config: ha->type = %d, fip_mac = ",
ha->type);
printk(KERN_INFO "%2x:%2x:%2x:%2x:%2x:%2x\n", ha->addr[0],
ha->addr[1], ha->addr[2], ha->addr[3],
ha->addr[4], ha->addr[5]);
if ((ha->type == NETDEV_HW_ADDR_T_SAN) &&
(is_valid_ether_addr(ha->addr))) {
memcpy(ctlr->ctl_src_addr, ha->addr,
ETH_ALEN);
sel_san_mac = 1;
BNX2FC_MISC_DBG("Found SAN MAC\n");
}
}
rcu_read_unlock();
if (!sel_san_mac)
return -ENODEV;
interface->fip_packet_type.func = bnx2fc_fip_recv;
interface->fip_packet_type.type = htons(ETH_P_FIP);
interface->fip_packet_type.dev = netdev;
dev_add_pack(&interface->fip_packet_type);
interface->fcoe_packet_type.func = bnx2fc_rcv;
interface->fcoe_packet_type.type = __constant_htons(ETH_P_FCOE);
interface->fcoe_packet_type.dev = netdev;
dev_add_pack(&interface->fcoe_packet_type);
return 0;
}
static int bnx2fc_attach_transport(void)
{
bnx2fc_transport_template =
fc_attach_transport(&bnx2fc_transport_function);
if (bnx2fc_transport_template == NULL) {
printk(KERN_ERR PFX "Failed to attach FC transport\n");
return -ENODEV;
}
bnx2fc_vport_xport_template =
fc_attach_transport(&bnx2fc_vport_xport_function);
if (bnx2fc_vport_xport_template == NULL) {
printk(KERN_ERR PFX
"Failed to attach FC transport for vport\n");
fc_release_transport(bnx2fc_transport_template);
bnx2fc_transport_template = NULL;
return -ENODEV;
}
return 0;
}
static void bnx2fc_release_transport(void)
{
fc_release_transport(bnx2fc_transport_template);
fc_release_transport(bnx2fc_vport_xport_template);
bnx2fc_transport_template = NULL;
bnx2fc_vport_xport_template = NULL;
}
static void bnx2fc_interface_release(struct kref *kref)
{
struct fcoe_ctlr_device *ctlr_dev;
struct bnx2fc_interface *interface;
struct fcoe_ctlr *ctlr;
struct net_device *netdev;
interface = container_of(kref, struct bnx2fc_interface, kref);
BNX2FC_MISC_DBG("Interface is being released\n");
ctlr = bnx2fc_to_ctlr(interface);
ctlr_dev = fcoe_ctlr_to_ctlr_dev(ctlr);
netdev = interface->netdev;
if (test_and_clear_bit(BNX2FC_CTLR_INIT_DONE, &interface->if_flags))
fcoe_ctlr_destroy(ctlr);
fcoe_ctlr_device_delete(ctlr_dev);
dev_put(netdev);
module_put(THIS_MODULE);
}
static inline void bnx2fc_interface_get(struct bnx2fc_interface *interface)
{
kref_get(&interface->kref);
}
static inline void bnx2fc_interface_put(struct bnx2fc_interface *interface)
{
kref_put(&interface->kref, bnx2fc_interface_release);
}
static void bnx2fc_hba_destroy(struct bnx2fc_hba *hba)
{
if (hba->cmd_mgr) {
bnx2fc_cmd_mgr_free(hba->cmd_mgr);
hba->cmd_mgr = NULL;
}
kfree(hba->tgt_ofld_list);
bnx2fc_unbind_pcidev(hba);
kfree(hba);
}
static struct bnx2fc_hba *bnx2fc_hba_create(struct cnic_dev *cnic)
{
struct bnx2fc_hba *hba;
struct fcoe_capabilities *fcoe_cap;
int rc;
hba = kzalloc(sizeof(*hba), GFP_KERNEL);
if (!hba) {
printk(KERN_ERR PFX "Unable to allocate hba structure\n");
return NULL;
}
spin_lock_init(&hba->hba_lock);
mutex_init(&hba->hba_mutex);
hba->cnic = cnic;
hba->max_tasks = cnic->max_fcoe_exchanges;
hba->elstm_xids = (hba->max_tasks / 2);
hba->max_outstanding_cmds = hba->elstm_xids;
hba->max_xid = (hba->max_tasks - 1);
rc = bnx2fc_bind_pcidev(hba);
if (rc) {
printk(KERN_ERR PFX "create_adapter: bind error\n");
goto bind_err;
}
hba->phys_dev = cnic->netdev;
hba->next_conn_id = 0;
hba->tgt_ofld_list =
kzalloc(sizeof(struct bnx2fc_rport *) * BNX2FC_NUM_MAX_SESS,
GFP_KERNEL);
if (!hba->tgt_ofld_list) {
printk(KERN_ERR PFX "Unable to allocate tgt offload list\n");
goto tgtofld_err;
}
hba->num_ofld_sess = 0;
hba->cmd_mgr = bnx2fc_cmd_mgr_alloc(hba);
if (!hba->cmd_mgr) {
printk(KERN_ERR PFX "em_config:bnx2fc_cmd_mgr_alloc failed\n");
goto cmgr_err;
}
fcoe_cap = &hba->fcoe_cap;
fcoe_cap->capability1 = BNX2FC_TM_MAX_SQES <<
FCOE_IOS_PER_CONNECTION_SHIFT;
fcoe_cap->capability1 |= BNX2FC_NUM_MAX_SESS <<
FCOE_LOGINS_PER_PORT_SHIFT;
fcoe_cap->capability2 = hba->max_outstanding_cmds <<
FCOE_NUMBER_OF_EXCHANGES_SHIFT;
fcoe_cap->capability2 |= BNX2FC_MAX_NPIV <<
FCOE_NPIV_WWN_PER_PORT_SHIFT;
fcoe_cap->capability3 = BNX2FC_NUM_MAX_SESS <<
FCOE_TARGETS_SUPPORTED_SHIFT;
fcoe_cap->capability3 |= hba->max_outstanding_cmds <<
FCOE_OUTSTANDING_COMMANDS_SHIFT;
fcoe_cap->capability4 = FCOE_CAPABILITY4_STATEFUL;
init_waitqueue_head(&hba->shutdown_wait);
init_waitqueue_head(&hba->destroy_wait);
INIT_LIST_HEAD(&hba->vports);
return hba;
cmgr_err:
kfree(hba->tgt_ofld_list);
tgtofld_err:
bnx2fc_unbind_pcidev(hba);
bind_err:
kfree(hba);
return NULL;
}
struct bnx2fc_interface *bnx2fc_interface_create(struct bnx2fc_hba *hba,
struct net_device *netdev,
enum fip_state fip_mode)
{
struct fcoe_ctlr_device *ctlr_dev;
struct bnx2fc_interface *interface;
struct fcoe_ctlr *ctlr;
int size;
int rc = 0;
size = (sizeof(*interface) + sizeof(struct fcoe_ctlr));
ctlr_dev = fcoe_ctlr_device_add(&netdev->dev, &bnx2fc_fcoe_sysfs_templ,
size);
if (!ctlr_dev) {
printk(KERN_ERR PFX "Unable to allocate interface structure\n");
return NULL;
}
ctlr = fcoe_ctlr_device_priv(ctlr_dev);
interface = fcoe_ctlr_priv(ctlr);
dev_hold(netdev);
kref_init(&interface->kref);
interface->hba = hba;
interface->netdev = netdev;
fcoe_ctlr_init(ctlr, fip_mode);
ctlr->send = bnx2fc_fip_send;
ctlr->update_mac = bnx2fc_update_src_mac;
ctlr->get_src_addr = bnx2fc_get_src_mac;
set_bit(BNX2FC_CTLR_INIT_DONE, &interface->if_flags);
rc = bnx2fc_interface_setup(interface);
if (!rc)
return interface;
fcoe_ctlr_destroy(ctlr);
dev_put(netdev);
fcoe_ctlr_device_delete(ctlr_dev);
return NULL;
}
static struct fc_lport *bnx2fc_if_create(struct bnx2fc_interface *interface,
struct device *parent, int npiv)
{
struct fcoe_ctlr *ctlr = bnx2fc_to_ctlr(interface);
struct fc_lport *lport, *n_port;
struct fcoe_port *port;
struct Scsi_Host *shost;
struct fc_vport *vport = dev_to_vport(parent);
struct bnx2fc_lport *blport;
struct bnx2fc_hba *hba = interface->hba;
int rc = 0;
blport = kzalloc(sizeof(struct bnx2fc_lport), GFP_KERNEL);
if (!blport) {
BNX2FC_HBA_DBG(ctlr->lp, "Unable to alloc blport\n");
return NULL;
}
bnx2fc_shost_template.can_queue = hba->max_outstanding_cmds;
if (!npiv)
lport = libfc_host_alloc(&bnx2fc_shost_template, sizeof(*port));
else
lport = libfc_vport_create(vport, sizeof(*port));
if (!lport) {
printk(KERN_ERR PFX "could not allocate scsi host structure\n");
goto free_blport;
}
shost = lport->host;
port = lport_priv(lport);
port->lport = lport;
port->priv = interface;
port->get_netdev = bnx2fc_netdev;
INIT_WORK(&port->destroy_work, bnx2fc_destroy_work);
rc = bnx2fc_lport_config(lport);
if (rc)
goto lp_config_err;
if (npiv) {
printk(KERN_ERR PFX "Setting vport names, 0x%llX 0x%llX\n",
vport->node_name, vport->port_name);
fc_set_wwnn(lport, vport->node_name);
fc_set_wwpn(lport, vport->port_name);
}
rc = bnx2fc_net_config(lport, interface->netdev);
if (rc) {
printk(KERN_ERR PFX "Error on bnx2fc_net_config\n");
goto lp_config_err;
}
rc = bnx2fc_shost_config(lport, parent);
if (rc) {
printk(KERN_ERR PFX "Couldnt configure shost for %s\n",
interface->netdev->name);
goto lp_config_err;
}
rc = bnx2fc_libfc_config(lport);
if (rc) {
printk(KERN_ERR PFX "Couldnt configure libfc\n");
goto shost_err;
}
fc_host_port_type(lport->host) = FC_PORTTYPE_UNKNOWN;
if (!npiv)
rc = bnx2fc_em_config(lport, hba);
else {
shost = vport_to_shost(vport);
n_port = shost_priv(shost);
rc = fc_exch_mgr_list_clone(n_port, lport);
}
if (rc) {
printk(KERN_ERR PFX "Error on bnx2fc_em_config\n");
goto shost_err;
}
bnx2fc_interface_get(interface);
spin_lock_bh(&hba->hba_lock);
blport->lport = lport;
list_add_tail(&blport->list, &hba->vports);
spin_unlock_bh(&hba->hba_lock);
return lport;
shost_err:
scsi_remove_host(shost);
lp_config_err:
scsi_host_put(lport->host);
free_blport:
kfree(blport);
return NULL;
}
static void bnx2fc_net_cleanup(struct bnx2fc_interface *interface)
{
__dev_remove_pack(&interface->fcoe_packet_type);
__dev_remove_pack(&interface->fip_packet_type);
synchronize_net();
}
static void bnx2fc_interface_cleanup(struct bnx2fc_interface *interface)
{
struct fcoe_ctlr *ctlr = bnx2fc_to_ctlr(interface);
struct fc_lport *lport = ctlr->lp;
struct fcoe_port *port = lport_priv(lport);
struct bnx2fc_hba *hba = interface->hba;
del_timer_sync(&port->timer);
fcoe_clean_pending_queue(lport);
bnx2fc_net_cleanup(interface);
bnx2fc_free_vport(hba, lport);
}
static void bnx2fc_if_destroy(struct fc_lport *lport)
{
bnx2fc_clean_rx_queue(lport);
fc_remove_host(lport->host);
scsi_remove_host(lport->host);
fc_exch_mgr_free(lport);
fc_lport_free_stats(lport);
scsi_host_put(lport->host);
}
static void __bnx2fc_destroy(struct bnx2fc_interface *interface)
{
struct fcoe_ctlr *ctlr = bnx2fc_to_ctlr(interface);
struct fc_lport *lport = ctlr->lp;
struct fcoe_port *port = lport_priv(lport);
bnx2fc_interface_cleanup(interface);
bnx2fc_stop(interface);
list_del(&interface->list);
bnx2fc_interface_put(interface);
queue_work(bnx2fc_wq, &port->destroy_work);
}
static int bnx2fc_destroy(struct net_device *netdev)
{
struct bnx2fc_interface *interface = NULL;
struct workqueue_struct *timer_work_queue;
struct fcoe_ctlr *ctlr;
int rc = 0;
rtnl_lock();
mutex_lock(&bnx2fc_dev_lock);
interface = bnx2fc_interface_lookup(netdev);
ctlr = bnx2fc_to_ctlr(interface);
if (!interface || !ctlr->lp) {
rc = -ENODEV;
printk(KERN_ERR PFX "bnx2fc_destroy: interface or lport not found\n");
goto netdev_err;
}
timer_work_queue = interface->timer_work_queue;
__bnx2fc_destroy(interface);
destroy_workqueue(timer_work_queue);
netdev_err:
mutex_unlock(&bnx2fc_dev_lock);
rtnl_unlock();
return rc;
}
static void bnx2fc_destroy_work(struct work_struct *work)
{
struct fcoe_port *port;
struct fc_lport *lport;
port = container_of(work, struct fcoe_port, destroy_work);
lport = port->lport;
BNX2FC_HBA_DBG(lport, "Entered bnx2fc_destroy_work\n");
bnx2fc_if_destroy(lport);
}
static void bnx2fc_unbind_adapter_devices(struct bnx2fc_hba *hba)
{
bnx2fc_free_fw_resc(hba);
bnx2fc_free_task_ctx(hba);
}
static int bnx2fc_bind_adapter_devices(struct bnx2fc_hba *hba)
{
if (bnx2fc_setup_task_ctx(hba))
goto mem_err;
if (bnx2fc_setup_fw_resc(hba))
goto mem_err;
return 0;
mem_err:
bnx2fc_unbind_adapter_devices(hba);
return -ENOMEM;
}
static int bnx2fc_bind_pcidev(struct bnx2fc_hba *hba)
{
struct cnic_dev *cnic;
struct pci_dev *pdev;
if (!hba->cnic) {
printk(KERN_ERR PFX "cnic is NULL\n");
return -ENODEV;
}
cnic = hba->cnic;
pdev = hba->pcidev = cnic->pcidev;
if (!hba->pcidev)
return -ENODEV;
switch (pdev->device) {
case PCI_DEVICE_ID_NX2_57710:
strncpy(hba->chip_num, "BCM57710", BCM_CHIP_LEN);
break;
case PCI_DEVICE_ID_NX2_57711:
strncpy(hba->chip_num, "BCM57711", BCM_CHIP_LEN);
break;
case PCI_DEVICE_ID_NX2_57712:
case PCI_DEVICE_ID_NX2_57712_MF:
case PCI_DEVICE_ID_NX2_57712_VF:
strncpy(hba->chip_num, "BCM57712", BCM_CHIP_LEN);
break;
case PCI_DEVICE_ID_NX2_57800:
case PCI_DEVICE_ID_NX2_57800_MF:
case PCI_DEVICE_ID_NX2_57800_VF:
strncpy(hba->chip_num, "BCM57800", BCM_CHIP_LEN);
break;
case PCI_DEVICE_ID_NX2_57810:
case PCI_DEVICE_ID_NX2_57810_MF:
case PCI_DEVICE_ID_NX2_57810_VF:
strncpy(hba->chip_num, "BCM57810", BCM_CHIP_LEN);
break;
case PCI_DEVICE_ID_NX2_57840:
case PCI_DEVICE_ID_NX2_57840_MF:
case PCI_DEVICE_ID_NX2_57840_VF:
case PCI_DEVICE_ID_NX2_57840_2_20:
case PCI_DEVICE_ID_NX2_57840_4_10:
strncpy(hba->chip_num, "BCM57840", BCM_CHIP_LEN);
break;
default:
pr_err(PFX "Unknown device id 0x%x\n", pdev->device);
break;
}
pci_dev_get(hba->pcidev);
return 0;
}
static void bnx2fc_unbind_pcidev(struct bnx2fc_hba *hba)
{
if (hba->pcidev) {
hba->chip_num[0] = '\0';
pci_dev_put(hba->pcidev);
}
hba->pcidev = NULL;
}
static int bnx2fc_ulp_get_stats(void *handle)
{
struct bnx2fc_hba *hba = handle;
struct cnic_dev *cnic;
struct fcoe_stats_info *stats_addr;
if (!hba)
return -EINVAL;
cnic = hba->cnic;
stats_addr = &cnic->stats_addr->fcoe_stat;
if (!stats_addr)
return -EINVAL;
strncpy(stats_addr->version, BNX2FC_VERSION,
sizeof(stats_addr->version));
stats_addr->txq_size = BNX2FC_SQ_WQES_MAX;
stats_addr->rxq_size = BNX2FC_CQ_WQES_MAX;
return 0;
}
static void bnx2fc_ulp_start(void *handle)
{
struct bnx2fc_hba *hba = handle;
struct bnx2fc_interface *interface;
struct fcoe_ctlr *ctlr;
struct fc_lport *lport;
mutex_lock(&bnx2fc_dev_lock);
if (!test_bit(BNX2FC_FLAG_FW_INIT_DONE, &hba->flags))
bnx2fc_fw_init(hba);
BNX2FC_MISC_DBG("bnx2fc started.\n");
list_for_each_entry(interface, &if_list, list) {
if (interface->hba == hba) {
ctlr = bnx2fc_to_ctlr(interface);
lport = ctlr->lp;
printk(KERN_ERR PFX "ulp_init: start discovery\n");
lport->tt.frame_send = bnx2fc_xmit;
bnx2fc_start_disc(interface);
}
}
mutex_unlock(&bnx2fc_dev_lock);
}
static void bnx2fc_port_shutdown(struct fc_lport *lport)
{
BNX2FC_MISC_DBG("Entered %s\n", __func__);
fc_fabric_logoff(lport);
fc_lport_destroy(lport);
}
static void bnx2fc_stop(struct bnx2fc_interface *interface)
{
struct fcoe_ctlr *ctlr = bnx2fc_to_ctlr(interface);
struct fc_lport *lport;
struct fc_lport *vport;
if (!test_bit(BNX2FC_FLAG_FW_INIT_DONE, &interface->hba->flags))
return;
lport = ctlr->lp;
bnx2fc_port_shutdown(lport);
mutex_lock(&lport->lp_mutex);
list_for_each_entry(vport, &lport->vports, list)
fc_host_port_type(vport->host) =
FC_PORTTYPE_UNKNOWN;
mutex_unlock(&lport->lp_mutex);
fc_host_port_type(lport->host) = FC_PORTTYPE_UNKNOWN;
fcoe_ctlr_link_down(ctlr);
fcoe_clean_pending_queue(lport);
}
static int bnx2fc_fw_init(struct bnx2fc_hba *hba)
{
#define BNX2FC_INIT_POLL_TIME (1000 / HZ)
int rc = -1;
int i = HZ;
rc = bnx2fc_bind_adapter_devices(hba);
if (rc) {
printk(KERN_ALERT PFX
"bnx2fc_bind_adapter_devices failed - rc = %d\n", rc);
goto err_out;
}
rc = bnx2fc_send_fw_fcoe_init_msg(hba);
if (rc) {
printk(KERN_ALERT PFX
"bnx2fc_send_fw_fcoe_init_msg failed - rc = %d\n", rc);
goto err_unbind;
}
while (!test_bit(ADAPTER_STATE_UP, &hba->adapter_state) && i--)
msleep(BNX2FC_INIT_POLL_TIME);
if (!test_bit(ADAPTER_STATE_UP, &hba->adapter_state)) {
printk(KERN_ERR PFX "bnx2fc_start: %s failed to initialize. "
"Ignoring...\n",
hba->cnic->netdev->name);
rc = -1;
goto err_unbind;
}
set_bit(BNX2FC_FLAG_FW_INIT_DONE, &hba->flags);
return 0;
err_unbind:
bnx2fc_unbind_adapter_devices(hba);
err_out:
return rc;
}
static void bnx2fc_fw_destroy(struct bnx2fc_hba *hba)
{
if (test_and_clear_bit(BNX2FC_FLAG_FW_INIT_DONE, &hba->flags)) {
if (bnx2fc_send_fw_fcoe_destroy_msg(hba) == 0) {
init_timer(&hba->destroy_timer);
hba->destroy_timer.expires = BNX2FC_FW_TIMEOUT +
jiffies;
hba->destroy_timer.function = bnx2fc_destroy_timer;
hba->destroy_timer.data = (unsigned long)hba;
add_timer(&hba->destroy_timer);
wait_event_interruptible(hba->destroy_wait,
test_bit(BNX2FC_FLAG_DESTROY_CMPL,
&hba->flags));
clear_bit(BNX2FC_FLAG_DESTROY_CMPL, &hba->flags);
if (signal_pending(current))
flush_signals(current);
del_timer_sync(&hba->destroy_timer);
}
bnx2fc_unbind_adapter_devices(hba);
}
}
static void bnx2fc_ulp_stop(void *handle)
{
struct bnx2fc_hba *hba = handle;
struct bnx2fc_interface *interface;
printk(KERN_ERR "ULP_STOP\n");
mutex_lock(&bnx2fc_dev_lock);
if (!test_bit(BNX2FC_FLAG_FW_INIT_DONE, &hba->flags))
goto exit;
list_for_each_entry(interface, &if_list, list) {
if (interface->hba == hba)
bnx2fc_stop(interface);
}
BUG_ON(hba->num_ofld_sess != 0);
mutex_lock(&hba->hba_mutex);
clear_bit(ADAPTER_STATE_UP, &hba->adapter_state);
clear_bit(ADAPTER_STATE_GOING_DOWN,
&hba->adapter_state);
clear_bit(ADAPTER_STATE_READY, &hba->adapter_state);
mutex_unlock(&hba->hba_mutex);
bnx2fc_fw_destroy(hba);
exit:
mutex_unlock(&bnx2fc_dev_lock);
}
static void bnx2fc_start_disc(struct bnx2fc_interface *interface)
{
struct fcoe_ctlr *ctlr = bnx2fc_to_ctlr(interface);
struct fc_lport *lport;
int wait_cnt = 0;
BNX2FC_MISC_DBG("Entered %s\n", __func__);
if (!test_bit(BNX2FC_FLAG_FW_INIT_DONE, &interface->hba->flags)) {
printk(KERN_ERR PFX "Init not done yet\n");
return;
}
lport = ctlr->lp;
BNX2FC_HBA_DBG(lport, "calling fc_fabric_login\n");
if (!bnx2fc_link_ok(lport) && interface->enabled) {
BNX2FC_HBA_DBG(lport, "ctlr_link_up\n");
fcoe_ctlr_link_up(ctlr);
fc_host_port_type(lport->host) = FC_PORTTYPE_NPORT;
set_bit(ADAPTER_STATE_READY, &interface->hba->adapter_state);
}
while (!ctlr->sel_fcf) {
msleep(250);
if (++wait_cnt > 12)
break;
}
if (fc_set_mfs(lport, BNX2FC_MFS))
return;
fc_lport_init(lport);
fc_fabric_login(lport);
}
static void bnx2fc_ulp_init(struct cnic_dev *dev)
{
struct bnx2fc_hba *hba;
int rc = 0;
BNX2FC_MISC_DBG("Entered %s\n", __func__);
if (!test_bit(CNIC_F_BNX2X_CLASS, &dev->flags) ||
(dev->max_fcoe_conn == 0)) {
printk(KERN_ERR PFX "bnx2fc FCoE not supported on %s,"
" flags: %lx fcoe_conn: %d\n",
dev->netdev->name, dev->flags, dev->max_fcoe_conn);
return;
}
hba = bnx2fc_hba_create(dev);
if (!hba) {
printk(KERN_ERR PFX "hba initialization failed\n");
return;
}
mutex_lock(&bnx2fc_dev_lock);
list_add_tail(&hba->list, &adapter_list);
adapter_count++;
mutex_unlock(&bnx2fc_dev_lock);
dev->fcoe_cap = &hba->fcoe_cap;
clear_bit(BNX2FC_CNIC_REGISTERED, &hba->reg_with_cnic);
rc = dev->register_device(dev, CNIC_ULP_FCOE,
(void *) hba);
if (rc)
printk(KERN_ERR PFX "register_device failed, rc = %d\n", rc);
else
set_bit(BNX2FC_CNIC_REGISTERED, &hba->reg_with_cnic);
}
static int bnx2fc_disable(struct net_device *netdev)
{
struct bnx2fc_interface *interface;
struct fcoe_ctlr *ctlr;
int rc = 0;
rtnl_lock();
mutex_lock(&bnx2fc_dev_lock);
interface = bnx2fc_interface_lookup(netdev);
ctlr = bnx2fc_to_ctlr(interface);
if (!interface || !ctlr->lp) {
rc = -ENODEV;
printk(KERN_ERR PFX "bnx2fc_disable: interface or lport not found\n");
} else {
interface->enabled = false;
fcoe_ctlr_link_down(ctlr);
fcoe_clean_pending_queue(ctlr->lp);
}
mutex_unlock(&bnx2fc_dev_lock);
rtnl_unlock();
return rc;
}
static int bnx2fc_enable(struct net_device *netdev)
{
struct bnx2fc_interface *interface;
struct fcoe_ctlr *ctlr;
int rc = 0;
rtnl_lock();
mutex_lock(&bnx2fc_dev_lock);
interface = bnx2fc_interface_lookup(netdev);
ctlr = bnx2fc_to_ctlr(interface);
if (!interface || !ctlr->lp) {
rc = -ENODEV;
printk(KERN_ERR PFX "bnx2fc_enable: interface or lport not found\n");
} else if (!bnx2fc_link_ok(ctlr->lp)) {
fcoe_ctlr_link_up(ctlr);
interface->enabled = true;
}
mutex_unlock(&bnx2fc_dev_lock);
rtnl_unlock();
return rc;
}
static int bnx2fc_ctlr_enabled(struct fcoe_ctlr_device *cdev)
{
struct fcoe_ctlr *ctlr = fcoe_ctlr_device_priv(cdev);
struct fc_lport *lport = ctlr->lp;
struct net_device *netdev = bnx2fc_netdev(lport);
switch (cdev->enabled) {
case FCOE_CTLR_ENABLED:
return bnx2fc_enable(netdev);
case FCOE_CTLR_DISABLED:
return bnx2fc_disable(netdev);
case FCOE_CTLR_UNUSED:
default:
return -ENOTSUPP;
};
}
static int _bnx2fc_create(struct net_device *netdev,
enum fip_state fip_mode,
enum bnx2fc_create_link_state link_state)
{
struct fcoe_ctlr_device *cdev;
struct fcoe_ctlr *ctlr;
struct bnx2fc_interface *interface;
struct bnx2fc_hba *hba;
struct net_device *phys_dev = netdev;
struct fc_lport *lport;
struct ethtool_drvinfo drvinfo;
int rc = 0;
int vlan_id = 0;
BNX2FC_MISC_DBG("Entered bnx2fc_create\n");
if (fip_mode != FIP_MODE_FABRIC) {
printk(KERN_ERR "fip mode not FABRIC\n");
return -EIO;
}
rtnl_lock();
mutex_lock(&bnx2fc_dev_lock);
if (!try_module_get(THIS_MODULE)) {
rc = -EINVAL;
goto mod_err;
}
if (netdev->priv_flags & IFF_802_1Q_VLAN)
phys_dev = vlan_dev_real_dev(netdev);
if (phys_dev->ethtool_ops && phys_dev->ethtool_ops->get_drvinfo) {
memset(&drvinfo, 0, sizeof(drvinfo));
phys_dev->ethtool_ops->get_drvinfo(phys_dev, &drvinfo);
if (strncmp(drvinfo.driver, "bnx2x", strlen("bnx2x"))) {
printk(KERN_ERR PFX "Not a netxtreme2 device\n");
rc = -EINVAL;
goto netdev_err;
}
} else {
printk(KERN_ERR PFX "unable to obtain drv_info\n");
rc = -EINVAL;
goto netdev_err;
}
hba = bnx2fc_hba_lookup(phys_dev);
if (!hba) {
rc = -ENODEV;
printk(KERN_ERR PFX "bnx2fc_create: hba not found\n");
goto netdev_err;
}
if (bnx2fc_interface_lookup(netdev)) {
rc = -EEXIST;
goto netdev_err;
}
interface = bnx2fc_interface_create(hba, netdev, fip_mode);
if (!interface) {
printk(KERN_ERR PFX "bnx2fc_interface_create failed\n");
goto ifput_err;
}
if (netdev->priv_flags & IFF_802_1Q_VLAN) {
vlan_id = vlan_dev_vlan_id(netdev);
interface->vlan_enabled = 1;
}
ctlr = bnx2fc_to_ctlr(interface);
cdev = fcoe_ctlr_to_ctlr_dev(ctlr);
interface->vlan_id = vlan_id;
interface->timer_work_queue =
create_singlethread_workqueue("bnx2fc_timer_wq");
if (!interface->timer_work_queue) {
printk(KERN_ERR PFX "ulp_init could not create timer_wq\n");
rc = -EINVAL;
goto ifput_err;
}
lport = bnx2fc_if_create(interface, &cdev->dev, 0);
if (!lport) {
printk(KERN_ERR PFX "Failed to create interface (%s)\n",
netdev->name);
rc = -EINVAL;
goto if_create_err;
}
list_add_tail(&interface->list, &if_list);
lport->boot_time = jiffies;
ctlr->lp = lport;
if (link_state == BNX2FC_CREATE_LINK_UP)
cdev->enabled = FCOE_CTLR_ENABLED;
else
cdev->enabled = FCOE_CTLR_DISABLED;
if (link_state == BNX2FC_CREATE_LINK_UP &&
!bnx2fc_link_ok(lport)) {
fcoe_ctlr_link_up(ctlr);
fc_host_port_type(lport->host) = FC_PORTTYPE_NPORT;
set_bit(ADAPTER_STATE_READY, &interface->hba->adapter_state);
}
BNX2FC_HBA_DBG(lport, "create: START DISC\n");
bnx2fc_start_disc(interface);
if (link_state == BNX2FC_CREATE_LINK_UP)
interface->enabled = true;
bnx2fc_interface_put(interface);
mutex_unlock(&bnx2fc_dev_lock);
rtnl_unlock();
return 0;
if_create_err:
destroy_workqueue(interface->timer_work_queue);
ifput_err:
bnx2fc_net_cleanup(interface);
bnx2fc_interface_put(interface);
goto mod_err;
netdev_err:
module_put(THIS_MODULE);
mod_err:
mutex_unlock(&bnx2fc_dev_lock);
rtnl_unlock();
return rc;
}
static int bnx2fc_create(struct net_device *netdev, enum fip_state fip_mode)
{
return _bnx2fc_create(netdev, fip_mode, BNX2FC_CREATE_LINK_UP);
}
static int bnx2fc_ctlr_alloc(struct net_device *netdev)
{
return _bnx2fc_create(netdev, FIP_MODE_FABRIC,
BNX2FC_CREATE_LINK_DOWN);
}
static struct bnx2fc_hba *bnx2fc_find_hba_for_cnic(struct cnic_dev *cnic)
{
struct bnx2fc_hba *hba;
list_for_each_entry(hba, &adapter_list, list) {
if (hba->cnic == cnic)
return hba;
}
return NULL;
}
static struct bnx2fc_interface *bnx2fc_interface_lookup(struct net_device
*netdev)
{
struct bnx2fc_interface *interface;
list_for_each_entry(interface, &if_list, list) {
if (interface->netdev == netdev)
return interface;
}
return NULL;
}
static struct bnx2fc_hba *bnx2fc_hba_lookup(struct net_device
*phys_dev)
{
struct bnx2fc_hba *hba;
list_for_each_entry(hba, &adapter_list, list) {
if (hba->phys_dev == phys_dev)
return hba;
}
printk(KERN_ERR PFX "adapter_lookup: hba NULL\n");
return NULL;
}
static void bnx2fc_ulp_exit(struct cnic_dev *dev)
{
struct bnx2fc_hba *hba;
struct bnx2fc_interface *interface, *tmp;
BNX2FC_MISC_DBG("Entered bnx2fc_ulp_exit\n");
if (!test_bit(CNIC_F_BNX2X_CLASS, &dev->flags)) {
printk(KERN_ERR PFX "bnx2fc port check: %s, flags: %lx\n",
dev->netdev->name, dev->flags);
return;
}
mutex_lock(&bnx2fc_dev_lock);
hba = bnx2fc_find_hba_for_cnic(dev);
if (!hba) {
printk(KERN_ERR PFX "bnx2fc_ulp_exit: hba not found, dev 0%p\n",
dev);
mutex_unlock(&bnx2fc_dev_lock);
return;
}
list_del_init(&hba->list);
adapter_count--;
list_for_each_entry_safe(interface, tmp, &if_list, list)
if (interface->hba == hba)
__bnx2fc_destroy(interface);
mutex_unlock(&bnx2fc_dev_lock);
bnx2fc_ulp_stop(hba);
if (test_and_clear_bit(BNX2FC_CNIC_REGISTERED, &hba->reg_with_cnic))
hba->cnic->unregister_device(hba->cnic, CNIC_ULP_FCOE);
bnx2fc_hba_destroy(hba);
}
static int bnx2fc_fcoe_reset(struct Scsi_Host *shost)
{
struct fc_lport *lport = shost_priv(shost);
fc_lport_reset(lport);
return 0;
}
static bool bnx2fc_match(struct net_device *netdev)
{
struct net_device *phys_dev = netdev;
mutex_lock(&bnx2fc_dev_lock);
if (netdev->priv_flags & IFF_802_1Q_VLAN)
phys_dev = vlan_dev_real_dev(netdev);
if (bnx2fc_hba_lookup(phys_dev)) {
mutex_unlock(&bnx2fc_dev_lock);
return true;
}
mutex_unlock(&bnx2fc_dev_lock);
return false;
}
static void bnx2fc_percpu_thread_create(unsigned int cpu)
{
struct bnx2fc_percpu_s *p;
struct task_struct *thread;
p = &per_cpu(bnx2fc_percpu, cpu);
thread = kthread_create_on_node(bnx2fc_percpu_io_thread,
(void *)p, cpu_to_node(cpu),
"bnx2fc_thread/%d", cpu);
if (likely(!IS_ERR(thread))) {
kthread_bind(thread, cpu);
p->iothread = thread;
wake_up_process(thread);
}
}
static void bnx2fc_percpu_thread_destroy(unsigned int cpu)
{
struct bnx2fc_percpu_s *p;
struct task_struct *thread;
struct bnx2fc_work *work, *tmp;
BNX2FC_MISC_DBG("destroying io thread for CPU %d\n", cpu);
p = &per_cpu(bnx2fc_percpu, cpu);
spin_lock_bh(&p->fp_work_lock);
thread = p->iothread;
p->iothread = NULL;
list_for_each_entry_safe(work, tmp, &p->work_list, list) {
list_del_init(&work->list);
bnx2fc_process_cq_compl(work->tgt, work->wqe);
kfree(work);
}
spin_unlock_bh(&p->fp_work_lock);
if (thread)
kthread_stop(thread);
}
static int bnx2fc_cpu_callback(struct notifier_block *nfb,
unsigned long action, void *hcpu)
{
unsigned cpu = (unsigned long)hcpu;
switch (action) {
case CPU_ONLINE:
case CPU_ONLINE_FROZEN:
printk(PFX "CPU %x online: Create Rx thread\n", cpu);
bnx2fc_percpu_thread_create(cpu);
break;
case CPU_DEAD:
case CPU_DEAD_FROZEN:
printk(PFX "CPU %x offline: Remove Rx thread\n", cpu);
bnx2fc_percpu_thread_destroy(cpu);
break;
default:
break;
}
return NOTIFY_OK;
}
static int __init bnx2fc_mod_init(void)
{
struct fcoe_percpu_s *bg;
struct task_struct *l2_thread;
int rc = 0;
unsigned int cpu = 0;
struct bnx2fc_percpu_s *p;
printk(KERN_INFO PFX "%s", version);
rc = fcoe_transport_attach(&bnx2fc_transport);
if (rc) {
printk(KERN_ERR "failed to register an fcoe transport, check "
"if libfcoe is loaded\n");
goto out;
}
INIT_LIST_HEAD(&adapter_list);
INIT_LIST_HEAD(&if_list);
mutex_init(&bnx2fc_dev_lock);
adapter_count = 0;
rc = bnx2fc_attach_transport();
if (rc)
goto detach_ft;
bnx2fc_wq = alloc_workqueue("bnx2fc", 0, 0);
if (!bnx2fc_wq) {
rc = -ENOMEM;
goto release_bt;
}
bg = &bnx2fc_global;
skb_queue_head_init(&bg->fcoe_rx_list);
l2_thread = kthread_create(bnx2fc_l2_rcv_thread,
(void *)bg,
"bnx2fc_l2_thread");
if (IS_ERR(l2_thread)) {
rc = PTR_ERR(l2_thread);
goto free_wq;
}
wake_up_process(l2_thread);
spin_lock_bh(&bg->fcoe_rx_list.lock);
bg->thread = l2_thread;
spin_unlock_bh(&bg->fcoe_rx_list.lock);
for_each_possible_cpu(cpu) {
p = &per_cpu(bnx2fc_percpu, cpu);
INIT_LIST_HEAD(&p->work_list);
spin_lock_init(&p->fp_work_lock);
}
for_each_online_cpu(cpu) {
bnx2fc_percpu_thread_create(cpu);
}
register_hotcpu_notifier(&bnx2fc_cpu_notifier);
cnic_register_driver(CNIC_ULP_FCOE, &bnx2fc_cnic_cb);
return 0;
free_wq:
destroy_workqueue(bnx2fc_wq);
release_bt:
bnx2fc_release_transport();
detach_ft:
fcoe_transport_detach(&bnx2fc_transport);
out:
return rc;
}
static void __exit bnx2fc_mod_exit(void)
{
LIST_HEAD(to_be_deleted);
struct bnx2fc_hba *hba, *next;
struct fcoe_percpu_s *bg;
struct task_struct *l2_thread;
struct sk_buff *skb;
unsigned int cpu = 0;
mutex_lock(&bnx2fc_dev_lock);
list_splice(&adapter_list, &to_be_deleted);
INIT_LIST_HEAD(&adapter_list);
adapter_count = 0;
mutex_unlock(&bnx2fc_dev_lock);
list_for_each_entry_safe(hba, next, &to_be_deleted, list) {
list_del_init(&hba->list);
printk(KERN_ERR PFX "MOD_EXIT:destroy hba = 0x%p\n",
hba);
bnx2fc_ulp_stop(hba);
if (test_and_clear_bit(BNX2FC_CNIC_REGISTERED,
&hba->reg_with_cnic))
hba->cnic->unregister_device(hba->cnic,
CNIC_ULP_FCOE);
bnx2fc_hba_destroy(hba);
}
cnic_unregister_driver(CNIC_ULP_FCOE);
bg = &bnx2fc_global;
spin_lock_bh(&bg->fcoe_rx_list.lock);
l2_thread = bg->thread;
bg->thread = NULL;
while ((skb = __skb_dequeue(&bg->fcoe_rx_list)) != NULL)
kfree_skb(skb);
spin_unlock_bh(&bg->fcoe_rx_list.lock);
if (l2_thread)
kthread_stop(l2_thread);
unregister_hotcpu_notifier(&bnx2fc_cpu_notifier);
for_each_online_cpu(cpu) {
bnx2fc_percpu_thread_destroy(cpu);
}
destroy_workqueue(bnx2fc_wq);
bnx2fc_release_transport();
fcoe_transport_detach(&bnx2fc_transport);
}
