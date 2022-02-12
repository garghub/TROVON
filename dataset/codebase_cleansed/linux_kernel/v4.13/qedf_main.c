void qedf_set_vlan_id(struct qedf_ctx *qedf, int vlan_id)
{
qedf->vlan_id = vlan_id;
qedf->vlan_id |= qedf_default_prio << VLAN_PRIO_SHIFT;
QEDF_INFO(&(qedf->dbg_ctx), QEDF_LOG_DISC, "Setting vlan_id=%04x "
"prio=%d.\n", vlan_id, qedf_default_prio);
}
static bool qedf_initiate_fipvlan_req(struct qedf_ctx *qedf)
{
int rc;
if (atomic_read(&qedf->link_state) != QEDF_LINK_UP) {
QEDF_ERR(&(qedf->dbg_ctx), "Link not up.\n");
return false;
}
while (qedf->fipvlan_retries--) {
if (qedf->vlan_id > 0)
return true;
QEDF_INFO(&(qedf->dbg_ctx), QEDF_LOG_DISC,
"Retry %d.\n", qedf->fipvlan_retries);
init_completion(&qedf->fipvlan_compl);
qedf_fcoe_send_vlan_req(qedf);
rc = wait_for_completion_timeout(&qedf->fipvlan_compl,
1 * HZ);
if (rc > 0) {
fcoe_ctlr_link_up(&qedf->ctlr);
return true;
}
}
return false;
}
static void qedf_handle_link_update(struct work_struct *work)
{
struct qedf_ctx *qedf =
container_of(work, struct qedf_ctx, link_update.work);
int rc;
QEDF_INFO(&(qedf->dbg_ctx), QEDF_LOG_DISC, "Entered.\n");
if (atomic_read(&qedf->link_state) == QEDF_LINK_UP) {
rc = qedf_initiate_fipvlan_req(qedf);
if (rc)
return;
QEDF_WARN(&(qedf->dbg_ctx), "Did not receive FIP VLAN "
"response, falling back to default VLAN %d.\n",
qedf_fallback_vlan);
qedf_set_vlan_id(qedf, QEDF_FALLBACK_VLAN);
eth_zero_addr(qedf->data_src_addr);
fcoe_ctlr_link_up(&qedf->ctlr);
} else if (atomic_read(&qedf->link_state) == QEDF_LINK_DOWN) {
atomic_set(&qedf->link_down_tmo_valid, 0);
QEDF_INFO(&(qedf->dbg_ctx), QEDF_LOG_DISC,
"Calling fcoe_ctlr_link_down().\n");
fcoe_ctlr_link_down(&qedf->ctlr);
qedf_wait_for_upload(qedf);
qedf->fipvlan_retries = qedf_fipvlan_retries;
}
}
static void qedf_flogi_resp(struct fc_seq *seq, struct fc_frame *fp,
void *arg)
{
struct fc_exch *exch = fc_seq_exch(seq);
struct fc_lport *lport = exch->lp;
struct qedf_ctx *qedf = lport_priv(lport);
if (!qedf) {
QEDF_ERR(NULL, "qedf is NULL.\n");
return;
}
if (IS_ERR(fp)) {
QEDF_INFO(&(qedf->dbg_ctx), QEDF_LOG_ELS,
"fp has IS_ERR() set.\n");
goto skip_stat;
}
if (fc_frame_payload_op(fp) == ELS_LS_RJT)
qedf->flogi_failed++;
complete(&qedf->flogi_compl);
skip_stat:
fc_lport_flogi_resp(seq, fp, lport);
}
static struct fc_seq *qedf_elsct_send(struct fc_lport *lport, u32 did,
struct fc_frame *fp, unsigned int op,
void (*resp)(struct fc_seq *,
struct fc_frame *,
void *),
void *arg, u32 timeout)
{
struct qedf_ctx *qedf = lport_priv(lport);
if (resp == fc_lport_flogi_resp) {
qedf->flogi_cnt++;
return fc_elsct_send(lport, did, fp, op, qedf_flogi_resp,
arg, timeout);
}
return fc_elsct_send(lport, did, fp, op, resp, arg, timeout);
}
int qedf_send_flogi(struct qedf_ctx *qedf)
{
struct fc_lport *lport;
struct fc_frame *fp;
lport = qedf->lport;
if (!lport->tt.elsct_send)
return -EINVAL;
fp = fc_frame_alloc(lport, sizeof(struct fc_els_flogi));
if (!fp) {
QEDF_ERR(&(qedf->dbg_ctx), "fc_frame_alloc failed.\n");
return -ENOMEM;
}
QEDF_INFO(&(qedf->dbg_ctx), QEDF_LOG_ELS,
"Sending FLOGI to reestablish session with switch.\n");
lport->tt.elsct_send(lport, FC_FID_FLOGI, fp,
ELS_FLOGI, qedf_flogi_resp, lport, lport->r_a_tov);
init_completion(&qedf->flogi_compl);
return 0;
}
static void qedf_link_recovery(struct work_struct *work)
{
struct qedf_ctx *qedf =
container_of(work, struct qedf_ctx, link_recovery.work);
struct qedf_rport *fcport;
struct fc_rport_priv *rdata;
struct qedf_tmp_rdata_item *rdata_item, *tmp_rdata_item;
bool rc;
int retries = 30;
int rval, i;
struct list_head rdata_login_list;
INIT_LIST_HEAD(&rdata_login_list);
QEDF_INFO(&(qedf->dbg_ctx), QEDF_LOG_DISC,
"Link down tmo did not expire.\n");
qedf->ctlr.state = FIP_ST_LINK_WAIT;
fcoe_ctlr_link_down(&qedf->ctlr);
fcoe_ctlr_link_up(&qedf->ctlr);
qedf->fipvlan_retries = qedf_fipvlan_retries;
rc = qedf_initiate_fipvlan_req(qedf);
if (!rc)
return;
while (retries > 0) {
if (qedf->ctlr.sel_fcf) {
QEDF_INFO(&(qedf->dbg_ctx), QEDF_LOG_DISC,
"FCF reselected, proceeding with FLOGI.\n");
break;
}
msleep(500);
retries--;
}
if (retries < 1) {
QEDF_ERR(&(qedf->dbg_ctx), "Exhausted retries waiting for "
"FCF selection.\n");
return;
}
rval = qedf_send_flogi(qedf);
if (rval)
return;
i = wait_for_completion_timeout(&qedf->flogi_compl,
qedf->lport->r_a_tov);
if (i == 0) {
QEDF_ERR(&(qedf->dbg_ctx), "FLOGI timed out.\n");
return;
}
rcu_read_lock();
list_for_each_entry_rcu(fcport, &qedf->fcports, peers) {
rdata = fcport->rdata;
if (rdata == NULL)
continue;
rdata_item = kzalloc(sizeof(struct qedf_tmp_rdata_item),
GFP_ATOMIC);
if (!rdata_item)
continue;
if (kref_get_unless_zero(&rdata->kref)) {
rdata_item->rdata = rdata;
list_add(&rdata_item->list, &rdata_login_list);
} else
kfree(rdata_item);
}
rcu_read_unlock();
list_for_each_entry_safe(rdata_item, tmp_rdata_item, &rdata_login_list,
list) {
list_del(&rdata_item->list);
fc_rport_login(rdata_item->rdata);
kref_put(&rdata_item->rdata->kref, fc_rport_destroy);
kfree(rdata_item);
}
}
static void qedf_update_link_speed(struct qedf_ctx *qedf,
struct qed_link_output *link)
{
struct fc_lport *lport = qedf->lport;
lport->link_speed = FC_PORTSPEED_UNKNOWN;
lport->link_supported_speeds = FC_PORTSPEED_UNKNOWN;
switch (link->speed) {
case 10000:
lport->link_speed = FC_PORTSPEED_10GBIT;
break;
case 25000:
lport->link_speed = FC_PORTSPEED_25GBIT;
break;
case 40000:
lport->link_speed = FC_PORTSPEED_40GBIT;
break;
case 50000:
lport->link_speed = FC_PORTSPEED_50GBIT;
break;
case 100000:
lport->link_speed = FC_PORTSPEED_100GBIT;
break;
default:
lport->link_speed = FC_PORTSPEED_UNKNOWN;
break;
}
if (link->supported_caps & SUPPORTED_10000baseKR_Full)
lport->link_supported_speeds |= FC_PORTSPEED_10GBIT;
if (link->supported_caps & SUPPORTED_25000baseKR_Full)
lport->link_supported_speeds |= FC_PORTSPEED_25GBIT;
if (link->supported_caps & SUPPORTED_40000baseLR4_Full)
lport->link_supported_speeds |= FC_PORTSPEED_40GBIT;
if (link->supported_caps & SUPPORTED_50000baseKR2_Full)
lport->link_supported_speeds |= FC_PORTSPEED_50GBIT;
if (link->supported_caps & SUPPORTED_100000baseKR4_Full)
lport->link_supported_speeds |= FC_PORTSPEED_100GBIT;
fc_host_supported_speeds(lport->host) = lport->link_supported_speeds;
}
static void qedf_link_update(void *dev, struct qed_link_output *link)
{
struct qedf_ctx *qedf = (struct qedf_ctx *)dev;
if (link->link_up) {
QEDF_ERR(&(qedf->dbg_ctx), "LINK UP (%d GB/s).\n",
link->speed / 1000);
cancel_delayed_work(&qedf->link_update);
atomic_set(&qedf->link_state, QEDF_LINK_UP);
qedf_update_link_speed(qedf, link);
if (atomic_read(&qedf->dcbx) == QEDF_DCBX_DONE) {
QEDF_INFO(&(qedf->dbg_ctx), QEDF_LOG_DISC,
"DCBx done.\n");
if (atomic_read(&qedf->link_down_tmo_valid) > 0)
queue_delayed_work(qedf->link_update_wq,
&qedf->link_recovery, 0);
else
queue_delayed_work(qedf->link_update_wq,
&qedf->link_update, 0);
atomic_set(&qedf->link_down_tmo_valid, 0);
}
} else {
QEDF_ERR(&(qedf->dbg_ctx), "LINK DOWN.\n");
atomic_set(&qedf->link_state, QEDF_LINK_DOWN);
atomic_set(&qedf->dcbx, QEDF_DCBX_PENDING);
if (qedf_link_down_tmo > 0) {
QEDF_INFO(&(qedf->dbg_ctx), QEDF_LOG_DISC,
"Starting link down tmo.\n");
atomic_set(&qedf->link_down_tmo_valid, 1);
}
qedf->vlan_id = 0;
qedf_update_link_speed(qedf, link);
queue_delayed_work(qedf->link_update_wq, &qedf->link_update,
qedf_link_down_tmo * HZ);
}
}
static void qedf_dcbx_handler(void *dev, struct qed_dcbx_get *get, u32 mib_type)
{
struct qedf_ctx *qedf = (struct qedf_ctx *)dev;
QEDF_ERR(&(qedf->dbg_ctx), "DCBx event valid=%d enabled=%d fcoe "
"prio=%d.\n", get->operational.valid, get->operational.enabled,
get->operational.app_prio.fcoe);
if (get->operational.enabled && get->operational.valid) {
if (atomic_read(&qedf->dcbx) == QEDF_DCBX_DONE) {
QEDF_INFO(&(qedf->dbg_ctx), QEDF_LOG_DISC,
"DCBX already set on link up.\n");
return;
}
atomic_set(&qedf->dcbx, QEDF_DCBX_DONE);
if (atomic_read(&qedf->link_state) == QEDF_LINK_UP) {
if (atomic_read(&qedf->link_down_tmo_valid) > 0)
queue_delayed_work(qedf->link_update_wq,
&qedf->link_recovery, 0);
else
queue_delayed_work(qedf->link_update_wq,
&qedf->link_update, 0);
atomic_set(&qedf->link_down_tmo_valid, 0);
}
}
}
static u32 qedf_get_login_failures(void *cookie)
{
struct qedf_ctx *qedf;
qedf = (struct qedf_ctx *)cookie;
return qedf->flogi_failed;
}
static int qedf_eh_abort(struct scsi_cmnd *sc_cmd)
{
struct fc_rport *rport = starget_to_rport(scsi_target(sc_cmd->device));
struct fc_rport_libfc_priv *rp = rport->dd_data;
struct qedf_rport *fcport;
struct fc_lport *lport;
struct qedf_ctx *qedf;
struct qedf_ioreq *io_req;
int rc = FAILED;
int rval;
if (fc_remote_port_chkready(rport)) {
QEDF_ERR(NULL, "rport not ready\n");
goto out;
}
lport = shost_priv(sc_cmd->device->host);
qedf = (struct qedf_ctx *)lport_priv(lport);
if ((lport->state != LPORT_ST_READY) || !(lport->link_up)) {
QEDF_ERR(&(qedf->dbg_ctx), "link not ready.\n");
goto out;
}
fcport = (struct qedf_rport *)&rp[1];
io_req = (struct qedf_ioreq *)sc_cmd->SCp.ptr;
if (!io_req) {
QEDF_ERR(&(qedf->dbg_ctx), "io_req is NULL.\n");
rc = SUCCESS;
goto out;
}
if (!test_bit(QEDF_CMD_OUTSTANDING, &io_req->flags) ||
test_bit(QEDF_CMD_IN_CLEANUP, &io_req->flags) ||
test_bit(QEDF_CMD_IN_ABORT, &io_req->flags)) {
QEDF_ERR(&(qedf->dbg_ctx), "io_req xid=0x%x already in "
"cleanup or abort processing or already "
"completed.\n", io_req->xid);
rc = SUCCESS;
goto out;
}
QEDF_ERR(&(qedf->dbg_ctx), "Aborting io_req sc_cmd=%p xid=0x%x "
"fp_idx=%d.\n", sc_cmd, io_req->xid, io_req->fp_idx);
if (qedf->stop_io_on_error) {
qedf_stop_all_io(qedf);
rc = SUCCESS;
goto out;
}
init_completion(&io_req->abts_done);
rval = qedf_initiate_abts(io_req, true);
if (rval) {
QEDF_ERR(&(qedf->dbg_ctx), "Failed to queue ABTS.\n");
goto out;
}
wait_for_completion(&io_req->abts_done);
if (io_req->event == QEDF_IOREQ_EV_ABORT_SUCCESS ||
io_req->event == QEDF_IOREQ_EV_ABORT_FAILED ||
io_req->event == QEDF_IOREQ_EV_CLEANUP_SUCCESS) {
rc = SUCCESS;
} else {
rc = FAILED;
}
if (rc == SUCCESS)
QEDF_ERR(&(qedf->dbg_ctx), "ABTS succeeded, xid=0x%x.\n",
io_req->xid);
else
QEDF_ERR(&(qedf->dbg_ctx), "ABTS failed, xid=0x%x.\n",
io_req->xid);
out:
return rc;
}
static int qedf_eh_target_reset(struct scsi_cmnd *sc_cmd)
{
QEDF_ERR(NULL, "TARGET RESET Issued...");
return qedf_initiate_tmf(sc_cmd, FCP_TMF_TGT_RESET);
}
static int qedf_eh_device_reset(struct scsi_cmnd *sc_cmd)
{
QEDF_ERR(NULL, "LUN RESET Issued...\n");
return qedf_initiate_tmf(sc_cmd, FCP_TMF_LUN_RESET);
}
static int qedf_eh_bus_reset(struct scsi_cmnd *sc_cmd)
{
QEDF_ERR(NULL, "BUS RESET Issued...\n");
return SUCCESS;
}
void qedf_wait_for_upload(struct qedf_ctx *qedf)
{
while (1) {
if (atomic_read(&qedf->num_offloads))
QEDF_INFO(&(qedf->dbg_ctx), QEDF_LOG_DISC,
"Waiting for all uploads to complete.\n");
else
break;
msleep(500);
}
}
static void qedf_ctx_soft_reset(struct fc_lport *lport)
{
struct qedf_ctx *qedf;
if (lport->vport) {
QEDF_ERR(NULL, "Cannot issue host reset on NPIV port.\n");
return;
}
qedf = lport_priv(lport);
atomic_set(&qedf->link_state, QEDF_LINK_DOWN);
atomic_set(&qedf->dcbx, QEDF_DCBX_PENDING);
queue_delayed_work(qedf->link_update_wq, &qedf->link_update,
0);
qedf_wait_for_upload(qedf);
atomic_set(&qedf->link_state, QEDF_LINK_UP);
qedf->vlan_id = 0;
queue_delayed_work(qedf->link_update_wq, &qedf->link_update,
0);
}
static int qedf_eh_host_reset(struct scsi_cmnd *sc_cmd)
{
struct fc_lport *lport;
struct qedf_ctx *qedf;
lport = shost_priv(sc_cmd->device->host);
qedf = lport_priv(lport);
if (atomic_read(&qedf->link_state) == QEDF_LINK_DOWN ||
test_bit(QEDF_UNLOADING, &qedf->flags))
return FAILED;
QEDF_ERR(&(qedf->dbg_ctx), "HOST RESET Issued...");
qedf_ctx_soft_reset(lport);
return SUCCESS;
}
static int qedf_slave_configure(struct scsi_device *sdev)
{
if (qedf_queue_depth) {
scsi_change_queue_depth(sdev, qedf_queue_depth);
}
return 0;
}
static int qedf_get_paged_crc_eof(struct sk_buff *skb, int tlen)
{
int rc;
spin_lock(&qedf_global_lock);
rc = fcoe_get_paged_crc_eof(skb, tlen, &qedf_global);
spin_unlock(&qedf_global_lock);
return rc;
}
static struct qedf_rport *qedf_fcport_lookup(struct qedf_ctx *qedf, u32 port_id)
{
struct qedf_rport *fcport;
struct fc_rport_priv *rdata;
rcu_read_lock();
list_for_each_entry_rcu(fcport, &qedf->fcports, peers) {
rdata = fcport->rdata;
if (rdata == NULL)
continue;
if (rdata->ids.port_id == port_id) {
rcu_read_unlock();
return fcport;
}
}
rcu_read_unlock();
return NULL;
}
static int qedf_xmit_l2_frame(struct qedf_rport *fcport, struct fc_frame *fp)
{
struct fc_frame_header *fh;
int rc = 0;
fh = fc_frame_header_get(fp);
if ((fh->fh_type == FC_TYPE_ELS) &&
(fh->fh_r_ctl == FC_RCTL_ELS_REQ)) {
switch (fc_frame_payload_op(fp)) {
case ELS_ADISC:
qedf_send_adisc(fcport, fp);
rc = 1;
break;
}
}
return rc;
}
static int qedf_xmit(struct fc_lport *lport, struct fc_frame *fp)
{
struct fc_lport *base_lport;
struct qedf_ctx *qedf;
struct ethhdr *eh;
struct fcoe_crc_eof *cp;
struct sk_buff *skb;
struct fc_frame_header *fh;
struct fcoe_hdr *hp;
u8 sof, eof;
u32 crc;
unsigned int hlen, tlen, elen;
int wlen;
struct fc_stats *stats;
struct fc_lport *tmp_lport;
struct fc_lport *vn_port = NULL;
struct qedf_rport *fcport;
int rc;
u16 vlan_tci = 0;
qedf = (struct qedf_ctx *)lport_priv(lport);
fh = fc_frame_header_get(fp);
skb = fp_skb(fp);
if (lport->vport)
base_lport = shost_priv(vport_to_shost(lport->vport));
else
base_lport = lport;
if (base_lport->port_id == ntoh24(fh->fh_d_id)) {
vn_port = base_lport;
} else {
list_for_each_entry(tmp_lport, &base_lport->vports, list) {
if (tmp_lport->port_id == ntoh24(fh->fh_d_id)) {
vn_port = tmp_lport;
break;
}
}
}
if (vn_port && ntoh24(fh->fh_d_id) != FC_FID_FLOGI) {
struct fc_rport_priv *rdata = NULL;
QEDF_INFO(&(qedf->dbg_ctx), QEDF_LOG_LL2,
"Dropping FCoE frame to %06x.\n", ntoh24(fh->fh_d_id));
kfree_skb(skb);
rdata = fc_rport_lookup(lport, ntoh24(fh->fh_d_id));
if (rdata)
rdata->retries = lport->max_rport_retry_count;
return -EINVAL;
}
if (!qedf->ctlr.sel_fcf) {
kfree_skb(skb);
return 0;
}
if (!test_bit(QEDF_LL2_STARTED, &qedf->flags)) {
QEDF_WARN(&(qedf->dbg_ctx), "LL2 not started\n");
kfree_skb(skb);
return 0;
}
if (atomic_read(&qedf->link_state) != QEDF_LINK_UP) {
QEDF_WARN(&(qedf->dbg_ctx), "qedf link down\n");
kfree_skb(skb);
return 0;
}
if (unlikely(fh->fh_r_ctl == FC_RCTL_ELS_REQ)) {
if (fcoe_ctlr_els_send(&qedf->ctlr, lport, skb))
return 0;
}
fcport = qedf_fcport_lookup(qedf, ntoh24(fh->fh_d_id));
if (fcport && test_bit(QEDF_RPORT_SESSION_READY, &fcport->flags)) {
rc = qedf_xmit_l2_frame(fcport, fp);
if (rc)
return 0;
}
sof = fr_sof(fp);
eof = fr_eof(fp);
elen = sizeof(struct ethhdr);
hlen = sizeof(struct fcoe_hdr);
tlen = sizeof(struct fcoe_crc_eof);
wlen = (skb->len - tlen + sizeof(crc)) / FCOE_WORD_TO_BYTE;
skb->ip_summed = CHECKSUM_NONE;
crc = fcoe_fc_crc(fp);
if (skb_is_nonlinear(skb)) {
skb_frag_t *frag;
if (qedf_get_paged_crc_eof(skb, tlen)) {
kfree_skb(skb);
return -ENOMEM;
}
frag = &skb_shinfo(skb)->frags[skb_shinfo(skb)->nr_frags - 1];
cp = kmap_atomic(skb_frag_page(frag)) + frag->page_offset;
} else {
cp = skb_put(skb, tlen);
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
__vlan_hwaccel_put_tag(skb, htons(ETH_P_8021Q), qedf->vlan_id);
eh = eth_hdr(skb);
eh->h_proto = htons(ETH_P_FCOE);
if (qedf->ctlr.map_dest)
fc_fcoe_set_mac(eh->h_dest, fh->fh_d_id);
else
ether_addr_copy(eh->h_dest, qedf->ctlr.dest_addr);
fc_fcoe_set_mac(eh->h_source, fh->fh_s_id);
hp = (struct fcoe_hdr *)(eh + 1);
memset(hp, 0, sizeof(*hp));
if (FC_FCOE_VER)
FC_FCOE_ENCAPS_VER(hp, FC_FCOE_VER);
hp->fcoe_sof = sof;
stats = per_cpu_ptr(lport->stats, get_cpu());
stats->TxFrames++;
stats->TxWords += wlen;
put_cpu();
__vlan_hwaccel_get_tag(skb, &vlan_tci);
fr_dev(fp) = lport;
QEDF_INFO(&(qedf->dbg_ctx), QEDF_LOG_LL2, "FCoE frame send: "
"src=%06x dest=%06x r_ctl=%x type=%x vlan=%04x.\n",
ntoh24(fh->fh_s_id), ntoh24(fh->fh_d_id), fh->fh_r_ctl, fh->fh_type,
vlan_tci);
if (qedf_dump_frames)
print_hex_dump(KERN_WARNING, "fcoe: ", DUMP_PREFIX_OFFSET, 16,
1, skb->data, skb->len, false);
qed_ops->ll2->start_xmit(qedf->cdev, skb);
return 0;
}
static int qedf_alloc_sq(struct qedf_ctx *qedf, struct qedf_rport *fcport)
{
int rval = 0;
u32 *pbl;
dma_addr_t page;
int num_pages;
fcport->sq_mem_size = SQ_NUM_ENTRIES * sizeof(struct fcoe_wqe);
fcport->sq_mem_size = ALIGN(fcport->sq_mem_size, QEDF_PAGE_SIZE);
fcport->sq_pbl_size = (fcport->sq_mem_size / QEDF_PAGE_SIZE) *
sizeof(void *);
fcport->sq_pbl_size = fcport->sq_pbl_size + QEDF_PAGE_SIZE;
fcport->sq = dma_zalloc_coherent(&qedf->pdev->dev,
fcport->sq_mem_size, &fcport->sq_dma, GFP_KERNEL);
if (!fcport->sq) {
QEDF_WARN(&(qedf->dbg_ctx), "Could not allocate send queue.\n");
rval = 1;
goto out;
}
fcport->sq_pbl = dma_zalloc_coherent(&qedf->pdev->dev,
fcport->sq_pbl_size, &fcport->sq_pbl_dma, GFP_KERNEL);
if (!fcport->sq_pbl) {
QEDF_WARN(&(qedf->dbg_ctx), "Could not allocate send queue PBL.\n");
rval = 1;
goto out_free_sq;
}
num_pages = fcport->sq_mem_size / QEDF_PAGE_SIZE;
page = fcport->sq_dma;
pbl = (u32 *)fcport->sq_pbl;
while (num_pages--) {
*pbl = U64_LO(page);
pbl++;
*pbl = U64_HI(page);
pbl++;
page += QEDF_PAGE_SIZE;
}
return rval;
out_free_sq:
dma_free_coherent(&qedf->pdev->dev, fcport->sq_mem_size, fcport->sq,
fcport->sq_dma);
out:
return rval;
}
static void qedf_free_sq(struct qedf_ctx *qedf, struct qedf_rport *fcport)
{
if (fcport->sq_pbl)
dma_free_coherent(&qedf->pdev->dev, fcport->sq_pbl_size,
fcport->sq_pbl, fcport->sq_pbl_dma);
if (fcport->sq)
dma_free_coherent(&qedf->pdev->dev, fcport->sq_mem_size,
fcport->sq, fcport->sq_dma);
}
static int qedf_offload_connection(struct qedf_ctx *qedf,
struct qedf_rport *fcport)
{
struct qed_fcoe_params_offload conn_info;
u32 port_id;
u8 lport_src_id[3];
int rval;
uint16_t total_sqe = (fcport->sq_mem_size / sizeof(struct fcoe_wqe));
QEDF_INFO(&(qedf->dbg_ctx), QEDF_LOG_CONN, "Offloading connection "
"portid=%06x.\n", fcport->rdata->ids.port_id);
rval = qed_ops->acquire_conn(qedf->cdev, &fcport->handle,
&fcport->fw_cid, &fcport->p_doorbell);
if (rval) {
QEDF_WARN(&(qedf->dbg_ctx), "Could not acquire connection "
"for portid=%06x.\n", fcport->rdata->ids.port_id);
rval = 1;
goto out;
}
QEDF_INFO(&(qedf->dbg_ctx), QEDF_LOG_CONN, "portid=%06x "
"fw_cid=%08x handle=%d.\n", fcport->rdata->ids.port_id,
fcport->fw_cid, fcport->handle);
memset(&conn_info, 0, sizeof(struct qed_fcoe_params_offload));
conn_info.sq_pbl_addr = fcport->sq_pbl_dma;
conn_info.sq_curr_page_addr = (dma_addr_t)(*(u64 *)fcport->sq_pbl);
conn_info.sq_next_page_addr =
(dma_addr_t)(*(u64 *)(fcport->sq_pbl + 8));
port_id = fc_host_port_id(qedf->lport->host);
lport_src_id[2] = (port_id & 0x000000FF);
lport_src_id[1] = (port_id & 0x0000FF00) >> 8;
lport_src_id[0] = (port_id & 0x00FF0000) >> 16;
fc_fcoe_set_mac(conn_info.src_mac, lport_src_id);
ether_addr_copy(conn_info.dst_mac, qedf->ctlr.dest_addr);
conn_info.tx_max_fc_pay_len = fcport->rdata->maxframe_size;
conn_info.e_d_tov_timer_val = qedf->lport->e_d_tov / 20;
conn_info.rec_tov_timer_val = 3;
conn_info.rx_max_fc_pay_len = fcport->rdata->maxframe_size;
conn_info.vlan_tag = qedf->vlan_id <<
FCOE_CONN_OFFLOAD_RAMROD_DATA_VLAN_ID_SHIFT;
conn_info.vlan_tag |=
qedf_default_prio << FCOE_CONN_OFFLOAD_RAMROD_DATA_PRIORITY_SHIFT;
conn_info.flags |= (FCOE_CONN_OFFLOAD_RAMROD_DATA_B_VLAN_FLAG_MASK <<
FCOE_CONN_OFFLOAD_RAMROD_DATA_B_VLAN_FLAG_SHIFT);
port_id = fc_host_port_id(qedf->lport->host);
fcport->sid = port_id;
conn_info.s_id.addr_hi = (port_id & 0x000000FF);
conn_info.s_id.addr_mid = (port_id & 0x0000FF00) >> 8;
conn_info.s_id.addr_lo = (port_id & 0x00FF0000) >> 16;
conn_info.max_conc_seqs_c3 = fcport->rdata->max_seq;
port_id = fcport->rdata->rport->port_id;
conn_info.d_id.addr_hi = (port_id & 0x000000FF);
conn_info.d_id.addr_mid = (port_id & 0x0000FF00) >> 8;
conn_info.d_id.addr_lo = (port_id & 0x00FF0000) >> 16;
conn_info.def_q_idx = 0;
if (fcport->dev_type == QEDF_RPORT_TYPE_TAPE) {
QEDF_INFO(&(qedf->dbg_ctx), QEDF_LOG_CONN,
"Enable CONF, REC for portid=%06x.\n",
fcport->rdata->ids.port_id);
conn_info.flags |= 1 <<
FCOE_CONN_OFFLOAD_RAMROD_DATA_B_CONF_REQ_SHIFT;
conn_info.flags |=
((fcport->rdata->sp_features & FC_SP_FT_SEQC) ? 1 : 0) <<
FCOE_CONN_OFFLOAD_RAMROD_DATA_B_REC_VALID_SHIFT;
}
rval = qed_ops->offload_conn(qedf->cdev, fcport->handle, &conn_info);
if (rval) {
QEDF_WARN(&(qedf->dbg_ctx), "Could not offload connection "
"for portid=%06x.\n", fcport->rdata->ids.port_id);
goto out_free_conn;
} else
QEDF_INFO(&(qedf->dbg_ctx), QEDF_LOG_CONN, "Offload "
"succeeded portid=%06x total_sqe=%d.\n",
fcport->rdata->ids.port_id, total_sqe);
spin_lock_init(&fcport->rport_lock);
atomic_set(&fcport->free_sqes, total_sqe);
return 0;
out_free_conn:
qed_ops->release_conn(qedf->cdev, fcport->handle);
out:
return rval;
}
static void qedf_upload_connection(struct qedf_ctx *qedf,
struct qedf_rport *fcport)
{
void *term_params;
dma_addr_t term_params_dma;
term_params = dma_alloc_coherent(&qedf->pdev->dev, QEDF_TERM_BUFF_SIZE,
&term_params_dma, GFP_KERNEL);
QEDF_INFO(&(qedf->dbg_ctx), QEDF_LOG_CONN, "Uploading connection "
"port_id=%06x.\n", fcport->rdata->ids.port_id);
qed_ops->destroy_conn(qedf->cdev, fcport->handle, term_params_dma);
qed_ops->release_conn(qedf->cdev, fcport->handle);
dma_free_coherent(&qedf->pdev->dev, QEDF_TERM_BUFF_SIZE, term_params,
term_params_dma);
}
static void qedf_cleanup_fcport(struct qedf_ctx *qedf,
struct qedf_rport *fcport)
{
QEDF_INFO(&(qedf->dbg_ctx), QEDF_LOG_CONN, "Cleaning up portid=%06x.\n",
fcport->rdata->ids.port_id);
qedf_flush_active_ios(fcport, -1);
if (test_and_clear_bit(QEDF_RPORT_SESSION_READY, &fcport->flags))
qedf_upload_connection(qedf, fcport);
qedf_free_sq(qedf, fcport);
fcport->rdata = NULL;
fcport->qedf = NULL;
}
static void qedf_rport_event_handler(struct fc_lport *lport,
struct fc_rport_priv *rdata,
enum fc_rport_event event)
{
struct qedf_ctx *qedf = lport_priv(lport);
struct fc_rport *rport = rdata->rport;
struct fc_rport_libfc_priv *rp;
struct qedf_rport *fcport;
u32 port_id;
int rval;
unsigned long flags;
QEDF_INFO(&(qedf->dbg_ctx), QEDF_LOG_DISC, "event = %d, "
"port_id = 0x%x\n", event, rdata->ids.port_id);
switch (event) {
case RPORT_EV_READY:
if (!rport) {
QEDF_WARN(&(qedf->dbg_ctx), "rport is NULL.\n");
break;
}
rp = rport->dd_data;
fcport = (struct qedf_rport *)&rp[1];
fcport->qedf = qedf;
if (atomic_read(&qedf->num_offloads) >= QEDF_MAX_SESSIONS) {
QEDF_ERR(&(qedf->dbg_ctx), "Not offloading "
"portid=0x%x as max number of offloaded sessions "
"reached.\n", rdata->ids.port_id);
return;
}
if (test_bit(QEDF_RPORT_SESSION_READY, &fcport->flags)) {
QEDF_WARN(&(qedf->dbg_ctx), "Session already "
"offloaded, portid=0x%x.\n",
rdata->ids.port_id);
return;
}
if (rport->port_id == FC_FID_DIR_SERV) {
QEDF_WARN(&(qedf->dbg_ctx), "rport struct does not "
"exist for dir server port_id=%x\n",
rdata->ids.port_id);
break;
}
if (rdata->spp_type != FC_TYPE_FCP) {
QEDF_INFO(&(qedf->dbg_ctx), QEDF_LOG_DISC,
"Not offloading since spp type isn't FCP\n");
break;
}
if (!(rdata->ids.roles & FC_RPORT_ROLE_FCP_TARGET)) {
QEDF_INFO(&(qedf->dbg_ctx), QEDF_LOG_DISC,
"Not FCP target so not offloading\n");
break;
}
fcport->rdata = rdata;
fcport->rport = rport;
rval = qedf_alloc_sq(qedf, fcport);
if (rval) {
qedf_cleanup_fcport(qedf, fcport);
break;
}
if (rdata->flags & FC_RP_FLAGS_RETRY &&
rdata->ids.roles & FC_RPORT_ROLE_FCP_TARGET &&
!(rdata->ids.roles & FC_RPORT_ROLE_FCP_INITIATOR)) {
fcport->dev_type = QEDF_RPORT_TYPE_TAPE;
QEDF_INFO(&(qedf->dbg_ctx), QEDF_LOG_DISC,
"portid=%06x is a TAPE device.\n",
rdata->ids.port_id);
} else {
fcport->dev_type = QEDF_RPORT_TYPE_DISK;
}
rval = qedf_offload_connection(qedf, fcport);
if (rval) {
qedf_cleanup_fcport(qedf, fcport);
break;
}
spin_lock_irqsave(&qedf->hba_lock, flags);
list_add_rcu(&fcport->peers, &qedf->fcports);
spin_unlock_irqrestore(&qedf->hba_lock, flags);
set_bit(QEDF_RPORT_SESSION_READY, &fcport->flags);
atomic_inc(&qedf->num_offloads);
break;
case RPORT_EV_LOGO:
case RPORT_EV_FAILED:
case RPORT_EV_STOP:
port_id = rdata->ids.port_id;
if (port_id == FC_FID_DIR_SERV)
break;
if (!rport) {
QEDF_INFO(&(qedf->dbg_ctx), QEDF_LOG_DISC,
"port_id=%x - rport notcreated Yet!!\n", port_id);
break;
}
rp = rport->dd_data;
fcport = (struct qedf_rport *)&rp[1];
if (test_bit(QEDF_RPORT_SESSION_READY, &fcport->flags)) {
set_bit(QEDF_RPORT_UPLOADING_CONNECTION, &fcport->flags);
qedf_cleanup_fcport(qedf, fcport);
spin_lock_irqsave(&qedf->hba_lock, flags);
list_del_rcu(&fcport->peers);
spin_unlock_irqrestore(&qedf->hba_lock, flags);
clear_bit(QEDF_RPORT_UPLOADING_CONNECTION,
&fcport->flags);
atomic_dec(&qedf->num_offloads);
}
break;
case RPORT_EV_NONE:
break;
}
}
static void qedf_abort_io(struct fc_lport *lport)
{
}
static void qedf_fcp_cleanup(struct fc_lport *lport)
{
}
static void qedf_fcoe_ctlr_setup(struct qedf_ctx *qedf)
{
fcoe_ctlr_init(&qedf->ctlr, FIP_ST_AUTO);
qedf->ctlr.send = qedf_fip_send;
qedf->ctlr.update_mac = qedf_update_src_mac;
qedf->ctlr.get_src_addr = qedf_get_src_mac;
ether_addr_copy(qedf->ctlr.ctl_src_addr, qedf->mac);
}
static void qedf_setup_fdmi(struct qedf_ctx *qedf)
{
struct fc_lport *lport = qedf->lport;
struct fc_host_attrs *fc_host = shost_to_fc_host(lport->host);
u8 buf[8];
int i, pos;
lport->fdmi_enabled = 1;
pos = pci_find_ext_capability(qedf->pdev, PCI_EXT_CAP_ID_DSN);
if (pos) {
pos += 4;
for (i = 0; i < 8; i++)
pci_read_config_byte(qedf->pdev, pos + i, &buf[i]);
snprintf(fc_host->serial_number,
sizeof(fc_host->serial_number),
"%02X%02X%02X%02X%02X%02X%02X%02X",
buf[7], buf[6], buf[5], buf[4],
buf[3], buf[2], buf[1], buf[0]);
} else
snprintf(fc_host->serial_number,
sizeof(fc_host->serial_number), "Unknown");
snprintf(fc_host->manufacturer,
sizeof(fc_host->manufacturer), "%s", "Cavium Inc.");
snprintf(fc_host->model, sizeof(fc_host->model), "%s", "QL41000");
snprintf(fc_host->model_description, sizeof(fc_host->model_description),
"%s", "QLogic FastLinQ QL41000 Series 10/25/40/50GGbE Controller"
"(FCoE)");
snprintf(fc_host->hardware_version, sizeof(fc_host->hardware_version),
"Rev %d", qedf->pdev->revision);
snprintf(fc_host->driver_version, sizeof(fc_host->driver_version),
"%s", QEDF_VERSION);
snprintf(fc_host->firmware_version, sizeof(fc_host->firmware_version),
"%d.%d.%d.%d", FW_MAJOR_VERSION, FW_MINOR_VERSION,
FW_REVISION_VERSION, FW_ENGINEERING_VERSION);
}
static int qedf_lport_setup(struct qedf_ctx *qedf)
{
struct fc_lport *lport = qedf->lport;
lport->link_up = 0;
lport->max_retry_count = QEDF_FLOGI_RETRY_CNT;
lport->max_rport_retry_count = QEDF_RPORT_RETRY_CNT;
lport->service_params = (FCP_SPPF_INIT_FCN | FCP_SPPF_RD_XRDY_DIS |
FCP_SPPF_RETRY | FCP_SPPF_CONF_COMPL);
lport->boot_time = jiffies;
lport->e_d_tov = 2 * 1000;
lport->r_a_tov = 10 * 1000;
lport->does_npiv = 1;
fc_host_max_npiv_vports(lport->host) = QEDF_MAX_NPIV;
fc_set_wwnn(lport, qedf->wwnn);
fc_set_wwpn(lport, qedf->wwpn);
fcoe_libfc_config(lport, &qedf->ctlr, &qedf_lport_template, 0);
fc_exch_mgr_alloc(lport, FC_CLASS_3, qedf->max_scsi_xid + 1,
qedf->max_els_xid, NULL);
if (fc_lport_init_stats(lport))
return -ENOMEM;
fc_lport_config(lport);
fc_set_mfs(lport, QEDF_MFS);
fc_host_maxframe_size(lport->host) = lport->mfs;
fc_host_dev_loss_tmo(lport->host) = qedf_dev_loss_tmo;
snprintf(fc_host_symbolic_name(lport->host), 256,
"QLogic %s v%s", QEDF_MODULE_NAME, QEDF_VERSION);
qedf_setup_fdmi(qedf);
return 0;
}
static int qedf_vport_libfc_config(struct fc_vport *vport,
struct fc_lport *lport)
{
lport->link_up = 0;
lport->qfull = 0;
lport->max_retry_count = QEDF_FLOGI_RETRY_CNT;
lport->max_rport_retry_count = QEDF_RPORT_RETRY_CNT;
lport->service_params = (FCP_SPPF_INIT_FCN | FCP_SPPF_RD_XRDY_DIS |
FCP_SPPF_RETRY | FCP_SPPF_CONF_COMPL);
lport->boot_time = jiffies;
lport->e_d_tov = 2 * 1000;
lport->r_a_tov = 10 * 1000;
lport->does_npiv = 1;
if (fc_lport_init_stats(lport))
return -ENOMEM;
fc_lport_config(lport);
lport->crc_offload = 0;
lport->seq_offload = 0;
lport->lro_enabled = 0;
lport->lro_xid = 0;
lport->lso_max = 0;
return 0;
}
static int qedf_vport_create(struct fc_vport *vport, bool disabled)
{
struct Scsi_Host *shost = vport_to_shost(vport);
struct fc_lport *n_port = shost_priv(shost);
struct fc_lport *vn_port;
struct qedf_ctx *base_qedf = lport_priv(n_port);
struct qedf_ctx *vport_qedf;
char buf[32];
int rc = 0;
rc = fcoe_validate_vport_create(vport);
if (rc) {
fcoe_wwn_to_str(vport->port_name, buf, sizeof(buf));
QEDF_WARN(&(base_qedf->dbg_ctx), "Failed to create vport, "
"WWPN (0x%s) already exists.\n", buf);
goto err1;
}
if (atomic_read(&base_qedf->link_state) != QEDF_LINK_UP) {
QEDF_WARN(&(base_qedf->dbg_ctx), "Cannot create vport "
"because link is not up.\n");
rc = -EIO;
goto err1;
}
vn_port = libfc_vport_create(vport, sizeof(struct qedf_ctx));
if (!vn_port) {
QEDF_WARN(&(base_qedf->dbg_ctx), "Could not create lport "
"for vport.\n");
rc = -ENOMEM;
goto err1;
}
fcoe_wwn_to_str(vport->port_name, buf, sizeof(buf));
QEDF_ERR(&(base_qedf->dbg_ctx), "Creating NPIV port, WWPN=%s.\n",
buf);
vport_qedf = lport_priv(vn_port);
memcpy(vport_qedf, base_qedf, sizeof(struct qedf_ctx));
vport_qedf->lport = vn_port;
vport_qedf->hba_lock = base_qedf->hba_lock;
vport_qedf->pdev = base_qedf->pdev;
vport_qedf->cmd_mgr = base_qedf->cmd_mgr;
init_completion(&vport_qedf->flogi_compl);
INIT_LIST_HEAD(&vport_qedf->fcports);
rc = qedf_vport_libfc_config(vport, vn_port);
if (rc) {
QEDF_ERR(&(base_qedf->dbg_ctx), "Could not allocate memory "
"for lport stats.\n");
goto err2;
}
fc_set_wwnn(vn_port, vport->node_name);
fc_set_wwpn(vn_port, vport->port_name);
vport_qedf->wwnn = vn_port->wwnn;
vport_qedf->wwpn = vn_port->wwpn;
vn_port->host->transportt = qedf_fc_vport_transport_template;
vn_port->host->can_queue = QEDF_MAX_ELS_XID;
vn_port->host->max_lun = qedf_max_lun;
vn_port->host->sg_tablesize = QEDF_MAX_BDS_PER_CMD;
vn_port->host->max_cmd_len = QEDF_MAX_CDB_LEN;
rc = scsi_add_host(vn_port->host, &vport->dev);
if (rc) {
QEDF_WARN(&(base_qedf->dbg_ctx), "Error adding Scsi_Host.\n");
goto err2;
}
fc_host_dev_loss_tmo(vn_port->host) = qedf_dev_loss_tmo;
memcpy(&vn_port->tt, &qedf_lport_template,
sizeof(qedf_lport_template));
fc_exch_init(vn_port);
fc_elsct_init(vn_port);
fc_lport_init(vn_port);
fc_disc_init(vn_port);
fc_disc_config(vn_port, vn_port);
shost = vport_to_shost(vport);
n_port = shost_priv(shost);
fc_exch_mgr_list_clone(n_port, vn_port);
fc_set_mfs(vn_port, QEDF_MFS);
fc_host_port_type(vn_port->host) = FC_PORTTYPE_UNKNOWN;
if (disabled) {
fc_vport_set_state(vport, FC_VPORT_DISABLED);
} else {
vn_port->boot_time = jiffies;
fc_fabric_login(vn_port);
fc_vport_setlink(vn_port);
}
QEDF_INFO(&(base_qedf->dbg_ctx), QEDF_LOG_NPIV, "vn_port=%p.\n",
vn_port);
vport_qedf->dbg_ctx.host_no = vn_port->host->host_no;
vport_qedf->dbg_ctx.pdev = base_qedf->pdev;
err2:
scsi_host_put(vn_port->host);
err1:
return rc;
}
static int qedf_vport_destroy(struct fc_vport *vport)
{
struct Scsi_Host *shost = vport_to_shost(vport);
struct fc_lport *n_port = shost_priv(shost);
struct fc_lport *vn_port = vport->dd_data;
mutex_lock(&n_port->lp_mutex);
list_del(&vn_port->list);
mutex_unlock(&n_port->lp_mutex);
fc_fabric_logoff(vn_port);
fc_lport_destroy(vn_port);
fc_remove_host(vn_port->host);
scsi_remove_host(vn_port->host);
if (vn_port->state == LPORT_ST_READY)
fc_exch_mgr_free(vn_port);
fc_lport_free_stats(vn_port);
if (vn_port->host)
scsi_host_put(vn_port->host);
return 0;
}
static int qedf_vport_disable(struct fc_vport *vport, bool disable)
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
static void qedf_wait_for_vport_destroy(struct qedf_ctx *qedf)
{
struct fc_host_attrs *fc_host = shost_to_fc_host(qedf->lport->host);
QEDF_INFO(&(qedf->dbg_ctx), QEDF_LOG_NPIV,
"Entered.\n");
while (fc_host->npiv_vports_inuse > 0) {
QEDF_INFO(&(qedf->dbg_ctx), QEDF_LOG_NPIV,
"Waiting for all vports to be reaped.\n");
msleep(1000);
}
}
static int qedf_fcoe_reset(struct Scsi_Host *shost)
{
struct fc_lport *lport = shost_priv(shost);
qedf_ctx_soft_reset(lport);
return 0;
}
static struct fc_host_statistics *qedf_fc_get_host_stats(struct Scsi_Host
*shost)
{
struct fc_host_statistics *qedf_stats;
struct fc_lport *lport = shost_priv(shost);
struct qedf_ctx *qedf = lport_priv(lport);
struct qed_fcoe_stats *fw_fcoe_stats;
qedf_stats = fc_get_host_stats(shost);
if (lport->vport)
goto out;
fw_fcoe_stats = kmalloc(sizeof(struct qed_fcoe_stats), GFP_KERNEL);
if (!fw_fcoe_stats) {
QEDF_ERR(&(qedf->dbg_ctx), "Could not allocate memory for "
"fw_fcoe_stats.\n");
goto out;
}
qed_ops->get_stats(qedf->cdev, fw_fcoe_stats);
qedf_stats->tx_frames += fw_fcoe_stats->fcoe_tx_data_pkt_cnt +
fw_fcoe_stats->fcoe_tx_xfer_pkt_cnt +
fw_fcoe_stats->fcoe_tx_other_pkt_cnt;
qedf_stats->rx_frames += fw_fcoe_stats->fcoe_rx_data_pkt_cnt +
fw_fcoe_stats->fcoe_rx_xfer_pkt_cnt +
fw_fcoe_stats->fcoe_rx_other_pkt_cnt;
qedf_stats->fcp_input_megabytes +=
do_div(fw_fcoe_stats->fcoe_rx_byte_cnt, 1000000);
qedf_stats->fcp_output_megabytes +=
do_div(fw_fcoe_stats->fcoe_tx_byte_cnt, 1000000);
qedf_stats->rx_words += fw_fcoe_stats->fcoe_rx_byte_cnt / 4;
qedf_stats->tx_words += fw_fcoe_stats->fcoe_tx_byte_cnt / 4;
qedf_stats->invalid_crc_count +=
fw_fcoe_stats->fcoe_silent_drop_pkt_crc_error_cnt;
qedf_stats->dumped_frames =
fw_fcoe_stats->fcoe_silent_drop_total_pkt_cnt;
qedf_stats->error_frames +=
fw_fcoe_stats->fcoe_silent_drop_total_pkt_cnt;
qedf_stats->fcp_input_requests += qedf->input_requests;
qedf_stats->fcp_output_requests += qedf->output_requests;
qedf_stats->fcp_control_requests += qedf->control_requests;
qedf_stats->fcp_packet_aborts += qedf->packet_aborts;
qedf_stats->fcp_frame_alloc_failures += qedf->alloc_failures;
kfree(fw_fcoe_stats);
out:
return qedf_stats;
}
static bool qedf_fp_has_work(struct qedf_fastpath *fp)
{
struct qedf_ctx *qedf = fp->qedf;
struct global_queue *que;
struct qed_sb_info *sb_info = fp->sb_info;
struct status_block *sb = sb_info->sb_virt;
u16 prod_idx;
que = qedf->global_queues[fp->sb_id];
rmb();
prod_idx = sb->pi_array[QEDF_FCOE_PARAMS_GL_RQ_PI];
return (que->cq_prod_idx != prod_idx);
}
static bool qedf_process_completions(struct qedf_fastpath *fp)
{
struct qedf_ctx *qedf = fp->qedf;
struct qed_sb_info *sb_info = fp->sb_info;
struct status_block *sb = sb_info->sb_virt;
struct global_queue *que;
u16 prod_idx;
struct fcoe_cqe *cqe;
struct qedf_io_work *io_work;
int num_handled = 0;
unsigned int cpu;
struct qedf_ioreq *io_req = NULL;
u16 xid;
u16 new_cqes;
u32 comp_type;
prod_idx = sb->pi_array[QEDF_FCOE_PARAMS_GL_RQ_PI];
que = qedf->global_queues[fp->sb_id];
new_cqes = (prod_idx >= que->cq_prod_idx) ?
(prod_idx - que->cq_prod_idx) :
0x10000 - que->cq_prod_idx + prod_idx;
que->cq_prod_idx = prod_idx;
while (new_cqes) {
fp->completions++;
num_handled++;
cqe = &que->cq[que->cq_cons_idx];
comp_type = (cqe->cqe_data >> FCOE_CQE_CQE_TYPE_SHIFT) &
FCOE_CQE_CQE_TYPE_MASK;
if (comp_type == FCOE_UNSOLIC_CQE_TYPE) {
QEDF_INFO(&(qedf->dbg_ctx), QEDF_LOG_UNSOL,
"Unsolicated CQE.\n");
qedf_process_unsol_compl(qedf, fp->sb_id, cqe);
goto inc_idx;
}
xid = cqe->cqe_data & FCOE_CQE_TASK_ID_MASK;
io_req = &qedf->cmd_mgr->cmds[xid];
if (!io_req)
cpu = 0;
else {
cpu = io_req->cpu;
io_req->int_cpu = smp_processor_id();
}
io_work = mempool_alloc(qedf->io_mempool, GFP_ATOMIC);
if (!io_work) {
QEDF_WARN(&(qedf->dbg_ctx), "Could not allocate "
"work for I/O completion.\n");
continue;
}
memset(io_work, 0, sizeof(struct qedf_io_work));
INIT_WORK(&io_work->work, qedf_fp_io_handler);
memcpy(&io_work->cqe, cqe, sizeof(struct fcoe_cqe));
io_work->qedf = fp->qedf;
io_work->fp = NULL;
queue_work_on(cpu, qedf_io_wq, &io_work->work);
inc_idx:
que->cq_cons_idx++;
if (que->cq_cons_idx == fp->cq_num_entries)
que->cq_cons_idx = 0;
new_cqes--;
}
return true;
}
static irqreturn_t qedf_msix_handler(int irq, void *dev_id)
{
struct qedf_fastpath *fp = dev_id;
if (!fp) {
QEDF_ERR(NULL, "fp is null.\n");
return IRQ_HANDLED;
}
if (!fp->sb_info) {
QEDF_ERR(NULL, "fp->sb_info in null.");
return IRQ_HANDLED;
}
qed_sb_ack(fp->sb_info, IGU_INT_DISABLE, 0 );
while (1) {
qedf_process_completions(fp);
if (qedf_fp_has_work(fp) == 0) {
qed_sb_update_sb_idx(fp->sb_info);
rmb();
if (qedf_fp_has_work(fp) == 0) {
qed_sb_ack(fp->sb_info, IGU_INT_ENABLE, 1);
return IRQ_HANDLED;
}
}
}
return IRQ_HANDLED;
}
static void qedf_simd_int_handler(void *cookie)
{
struct qedf_ctx *qedf = (struct qedf_ctx *)cookie;
QEDF_WARN(&(qedf->dbg_ctx), "qedf=%p.\n", qedf);
}
static void qedf_sync_free_irqs(struct qedf_ctx *qedf)
{
int i;
if (qedf->int_info.msix_cnt) {
for (i = 0; i < qedf->int_info.used_cnt; i++) {
synchronize_irq(qedf->int_info.msix[i].vector);
irq_set_affinity_hint(qedf->int_info.msix[i].vector,
NULL);
irq_set_affinity_notifier(qedf->int_info.msix[i].vector,
NULL);
free_irq(qedf->int_info.msix[i].vector,
&qedf->fp_array[i]);
}
} else
qed_ops->common->simd_handler_clean(qedf->cdev,
QEDF_SIMD_HANDLER_NUM);
qedf->int_info.used_cnt = 0;
qed_ops->common->set_fp_int(qedf->cdev, 0);
}
static int qedf_request_msix_irq(struct qedf_ctx *qedf)
{
int i, rc, cpu;
cpu = cpumask_first(cpu_online_mask);
for (i = 0; i < qedf->num_queues; i++) {
rc = request_irq(qedf->int_info.msix[i].vector,
qedf_msix_handler, 0, "qedf", &qedf->fp_array[i]);
if (rc) {
QEDF_WARN(&(qedf->dbg_ctx), "request_irq failed.\n");
qedf_sync_free_irqs(qedf);
return rc;
}
qedf->int_info.used_cnt++;
rc = irq_set_affinity_hint(qedf->int_info.msix[i].vector,
get_cpu_mask(cpu));
cpu = cpumask_next(cpu, cpu_online_mask);
}
return 0;
}
static int qedf_setup_int(struct qedf_ctx *qedf)
{
int rc = 0;
rc = qed_ops->common->set_fp_int(qedf->cdev, num_online_cpus());
if (rc <= 0)
return 0;
rc = qed_ops->common->get_fp_int(qedf->cdev, &qedf->int_info);
if (rc)
return 0;
QEDF_INFO(&(qedf->dbg_ctx), QEDF_LOG_DISC, "Number of msix_cnt = "
"0x%x num of cpus = 0x%x\n", qedf->int_info.msix_cnt,
num_online_cpus());
if (qedf->int_info.msix_cnt)
return qedf_request_msix_irq(qedf);
qed_ops->common->simd_handler_config(qedf->cdev, &qedf,
QEDF_SIMD_HANDLER_NUM, qedf_simd_int_handler);
qedf->int_info.used_cnt = 1;
return 0;
}
static void qedf_recv_frame(struct qedf_ctx *qedf,
struct sk_buff *skb)
{
u32 fr_len;
struct fc_lport *lport;
struct fc_frame_header *fh;
struct fcoe_crc_eof crc_eof;
struct fc_frame *fp;
u8 *mac = NULL;
u8 *dest_mac = NULL;
struct fcoe_hdr *hp;
struct qedf_rport *fcport;
struct fc_lport *vn_port;
u32 f_ctl;
lport = qedf->lport;
if (lport == NULL || lport->state == LPORT_ST_DISABLED) {
QEDF_WARN(NULL, "Invalid lport struct or lport disabled.\n");
kfree_skb(skb);
return;
}
if (skb_is_nonlinear(skb))
skb_linearize(skb);
mac = eth_hdr(skb)->h_source;
dest_mac = eth_hdr(skb)->h_dest;
hp = (struct fcoe_hdr *)skb->data;
fh = (struct fc_frame_header *) skb_transport_header(skb);
skb_pull(skb, sizeof(struct fcoe_hdr));
fr_len = skb->len - sizeof(struct fcoe_crc_eof);
fp = (struct fc_frame *)skb;
fc_frame_init(fp);
fr_dev(fp) = lport;
fr_sof(fp) = hp->fcoe_sof;
if (skb_copy_bits(skb, fr_len, &crc_eof, sizeof(crc_eof))) {
kfree_skb(skb);
return;
}
fr_eof(fp) = crc_eof.fcoe_eof;
fr_crc(fp) = crc_eof.fcoe_crc32;
if (pskb_trim(skb, fr_len)) {
kfree_skb(skb);
return;
}
fh = fc_frame_header_get(fp);
if (fh->fh_r_ctl == FC_RCTL_DD_SOL_DATA &&
fh->fh_type == FC_TYPE_FCP) {
kfree_skb(skb);
return;
}
if (fh->fh_r_ctl == FC_RCTL_ELS_REQ &&
fh->fh_type == FC_TYPE_ELS) {
switch (fc_frame_payload_op(fp)) {
case ELS_LOGO:
if (ntoh24(fh->fh_s_id) == FC_FID_FLOGI) {
kfree_skb(skb);
return;
}
break;
}
}
if (fh->fh_r_ctl == FC_RCTL_BA_ABTS) {
kfree_skb(skb);
return;
}
if (ntoh24(&dest_mac[3]) != ntoh24(fh->fh_d_id)) {
QEDF_INFO(&(qedf->dbg_ctx), QEDF_LOG_LL2,
"FC frame d_id mismatch with MAC %pM.\n", dest_mac);
return;
}
if (qedf->ctlr.state) {
if (!ether_addr_equal(mac, qedf->ctlr.dest_addr)) {
QEDF_INFO(&(qedf->dbg_ctx), QEDF_LOG_LL2,
"Wrong source address: mac:%pM dest_addr:%pM.\n",
mac, qedf->ctlr.dest_addr);
kfree_skb(skb);
return;
}
}
vn_port = fc_vport_id_lookup(lport, ntoh24(fh->fh_d_id));
if (lport->port_id != ntoh24(fh->fh_d_id) && !vn_port) {
QEDF_INFO(&(qedf->dbg_ctx), QEDF_LOG_LL2,
"Dropping frame due to destination mismatch: lport->port_id=%x fh->d_id=%x.\n",
lport->port_id, ntoh24(fh->fh_d_id));
kfree_skb(skb);
return;
}
f_ctl = ntoh24(fh->fh_f_ctl);
if ((fh->fh_type == FC_TYPE_BLS) && (f_ctl & FC_FC_SEQ_CTX) &&
(f_ctl & FC_FC_EX_CTX)) {
kfree_skb(skb);
return;
}
fcport = qedf_fcport_lookup(qedf, ntoh24(fh->fh_d_id));
if (fcport && test_bit(QEDF_RPORT_UPLOADING_CONNECTION,
&fcport->flags)) {
QEDF_INFO(&(qedf->dbg_ctx), QEDF_LOG_LL2,
"Connection uploading, dropping fp=%p.\n", fp);
kfree_skb(skb);
return;
}
QEDF_INFO(&(qedf->dbg_ctx), QEDF_LOG_LL2, "FCoE frame receive: "
"skb=%p fp=%p src=%06x dest=%06x r_ctl=%x fh_type=%x.\n", skb, fp,
ntoh24(fh->fh_s_id), ntoh24(fh->fh_d_id), fh->fh_r_ctl,
fh->fh_type);
if (qedf_dump_frames)
print_hex_dump(KERN_WARNING, "fcoe: ", DUMP_PREFIX_OFFSET, 16,
1, skb->data, skb->len, false);
fc_exch_recv(lport, fp);
}
static void qedf_ll2_process_skb(struct work_struct *work)
{
struct qedf_skb_work *skb_work =
container_of(work, struct qedf_skb_work, work);
struct qedf_ctx *qedf = skb_work->qedf;
struct sk_buff *skb = skb_work->skb;
struct ethhdr *eh;
if (!qedf) {
QEDF_ERR(NULL, "qedf is NULL\n");
goto err_out;
}
eh = (struct ethhdr *)skb->data;
if (eh->h_proto == htons(ETH_P_8021Q)) {
memmove((u8 *)eh + VLAN_HLEN, eh, ETH_ALEN * 2);
eh = skb_pull(skb, VLAN_HLEN);
skb_reset_mac_header(skb);
}
if (eh->h_proto == htons(ETH_P_FIP)) {
qedf_fip_recv(qedf, skb);
goto out;
} else if (eh->h_proto == htons(ETH_P_FCOE)) {
__skb_pull(skb, ETH_HLEN);
qedf_recv_frame(qedf, skb);
goto out;
} else
goto err_out;
err_out:
kfree_skb(skb);
out:
kfree(skb_work);
return;
}
static int qedf_ll2_rx(void *cookie, struct sk_buff *skb,
u32 arg1, u32 arg2)
{
struct qedf_ctx *qedf = (struct qedf_ctx *)cookie;
struct qedf_skb_work *skb_work;
skb_work = kzalloc(sizeof(struct qedf_skb_work), GFP_ATOMIC);
if (!skb_work) {
QEDF_WARN(&(qedf->dbg_ctx), "Could not allocate skb_work so "
"dropping frame.\n");
kfree_skb(skb);
return 0;
}
INIT_WORK(&skb_work->work, qedf_ll2_process_skb);
skb_work->skb = skb;
skb_work->qedf = qedf;
queue_work(qedf->ll2_recv_wq, &skb_work->work);
return 0;
}
void qedf_fp_io_handler(struct work_struct *work)
{
struct qedf_io_work *io_work =
container_of(work, struct qedf_io_work, work);
u32 comp_type;
comp_type = (io_work->cqe.cqe_data >>
FCOE_CQE_CQE_TYPE_SHIFT) &
FCOE_CQE_CQE_TYPE_MASK;
if (comp_type == FCOE_UNSOLIC_CQE_TYPE &&
io_work->fp)
fc_exch_recv(io_work->qedf->lport, io_work->fp);
else
qedf_process_cqe(io_work->qedf, &io_work->cqe);
kfree(io_work);
}
static int qedf_alloc_and_init_sb(struct qedf_ctx *qedf,
struct qed_sb_info *sb_info, u16 sb_id)
{
struct status_block *sb_virt;
dma_addr_t sb_phys;
int ret;
sb_virt = dma_alloc_coherent(&qedf->pdev->dev,
sizeof(struct status_block), &sb_phys, GFP_KERNEL);
if (!sb_virt) {
QEDF_ERR(&(qedf->dbg_ctx), "Status block allocation failed "
"for id = %d.\n", sb_id);
return -ENOMEM;
}
ret = qed_ops->common->sb_init(qedf->cdev, sb_info, sb_virt, sb_phys,
sb_id, QED_SB_TYPE_STORAGE);
if (ret) {
QEDF_ERR(&(qedf->dbg_ctx), "Status block initialization "
"failed for id = %d.\n", sb_id);
return ret;
}
return 0;
}
static void qedf_free_sb(struct qedf_ctx *qedf, struct qed_sb_info *sb_info)
{
if (sb_info->sb_virt)
dma_free_coherent(&qedf->pdev->dev, sizeof(*sb_info->sb_virt),
(void *)sb_info->sb_virt, sb_info->sb_phys);
}
static void qedf_destroy_sb(struct qedf_ctx *qedf)
{
int id;
struct qedf_fastpath *fp = NULL;
for (id = 0; id < qedf->num_queues; id++) {
fp = &(qedf->fp_array[id]);
if (fp->sb_id == QEDF_SB_ID_NULL)
break;
qedf_free_sb(qedf, fp->sb_info);
kfree(fp->sb_info);
}
kfree(qedf->fp_array);
}
static int qedf_prepare_sb(struct qedf_ctx *qedf)
{
int id;
struct qedf_fastpath *fp;
int ret;
qedf->fp_array =
kcalloc(qedf->num_queues, sizeof(struct qedf_fastpath),
GFP_KERNEL);
if (!qedf->fp_array) {
QEDF_ERR(&(qedf->dbg_ctx), "fastpath array allocation "
"failed.\n");
return -ENOMEM;
}
for (id = 0; id < qedf->num_queues; id++) {
fp = &(qedf->fp_array[id]);
fp->sb_id = QEDF_SB_ID_NULL;
fp->sb_info = kcalloc(1, sizeof(*fp->sb_info), GFP_KERNEL);
if (!fp->sb_info) {
QEDF_ERR(&(qedf->dbg_ctx), "SB info struct "
"allocation failed.\n");
goto err;
}
ret = qedf_alloc_and_init_sb(qedf, fp->sb_info, id);
if (ret) {
QEDF_ERR(&(qedf->dbg_ctx), "SB allocation and "
"initialization failed.\n");
goto err;
}
fp->sb_id = id;
fp->qedf = qedf;
fp->cq_num_entries =
qedf->global_queues[id]->cq_mem_size /
sizeof(struct fcoe_cqe);
}
err:
return 0;
}
void qedf_process_cqe(struct qedf_ctx *qedf, struct fcoe_cqe *cqe)
{
u16 xid;
struct qedf_ioreq *io_req;
struct qedf_rport *fcport;
u32 comp_type;
comp_type = (cqe->cqe_data >> FCOE_CQE_CQE_TYPE_SHIFT) &
FCOE_CQE_CQE_TYPE_MASK;
xid = cqe->cqe_data & FCOE_CQE_TASK_ID_MASK;
io_req = &qedf->cmd_mgr->cmds[xid];
if (!io_req)
return;
fcport = io_req->fcport;
if (fcport == NULL) {
QEDF_ERR(&(qedf->dbg_ctx), "fcport is NULL.\n");
return;
}
if (!test_bit(QEDF_RPORT_SESSION_READY, &fcport->flags)) {
QEDF_ERR(&(qedf->dbg_ctx), "Session not offloaded yet.\n");
return;
}
switch (comp_type) {
case FCOE_GOOD_COMPLETION_CQE_TYPE:
atomic_inc(&fcport->free_sqes);
switch (io_req->cmd_type) {
case QEDF_SCSI_CMD:
qedf_scsi_completion(qedf, cqe, io_req);
break;
case QEDF_ELS:
qedf_process_els_compl(qedf, cqe, io_req);
break;
case QEDF_TASK_MGMT_CMD:
qedf_process_tmf_compl(qedf, cqe, io_req);
break;
case QEDF_SEQ_CLEANUP:
qedf_process_seq_cleanup_compl(qedf, cqe, io_req);
break;
}
break;
case FCOE_ERROR_DETECTION_CQE_TYPE:
atomic_inc(&fcport->free_sqes);
QEDF_INFO(&(qedf->dbg_ctx), QEDF_LOG_IO,
"Error detect CQE.\n");
qedf_process_error_detect(qedf, cqe, io_req);
break;
case FCOE_EXCH_CLEANUP_CQE_TYPE:
atomic_inc(&fcport->free_sqes);
QEDF_INFO(&(qedf->dbg_ctx), QEDF_LOG_IO,
"Cleanup CQE.\n");
qedf_process_cleanup_compl(qedf, cqe, io_req);
break;
case FCOE_ABTS_CQE_TYPE:
atomic_inc(&fcport->free_sqes);
QEDF_INFO(&(qedf->dbg_ctx), QEDF_LOG_IO,
"Abort CQE.\n");
qedf_process_abts_compl(qedf, cqe, io_req);
break;
case FCOE_DUMMY_CQE_TYPE:
atomic_inc(&fcport->free_sqes);
QEDF_INFO(&(qedf->dbg_ctx), QEDF_LOG_IO,
"Dummy CQE.\n");
break;
case FCOE_LOCAL_COMP_CQE_TYPE:
atomic_inc(&fcport->free_sqes);
QEDF_INFO(&(qedf->dbg_ctx), QEDF_LOG_IO,
"Local completion CQE.\n");
break;
case FCOE_WARNING_CQE_TYPE:
atomic_inc(&fcport->free_sqes);
QEDF_INFO(&(qedf->dbg_ctx), QEDF_LOG_IO,
"Warning CQE.\n");
qedf_process_warning_compl(qedf, cqe, io_req);
break;
case MAX_FCOE_CQE_TYPE:
atomic_inc(&fcport->free_sqes);
QEDF_INFO(&(qedf->dbg_ctx), QEDF_LOG_IO,
"Max FCoE CQE.\n");
break;
default:
QEDF_INFO(&(qedf->dbg_ctx), QEDF_LOG_IO,
"Default CQE.\n");
break;
}
}
static void qedf_free_bdq(struct qedf_ctx *qedf)
{
int i;
if (qedf->bdq_pbl_list)
dma_free_coherent(&qedf->pdev->dev, QEDF_PAGE_SIZE,
qedf->bdq_pbl_list, qedf->bdq_pbl_list_dma);
if (qedf->bdq_pbl)
dma_free_coherent(&qedf->pdev->dev, qedf->bdq_pbl_mem_size,
qedf->bdq_pbl, qedf->bdq_pbl_dma);
for (i = 0; i < QEDF_BDQ_SIZE; i++) {
if (qedf->bdq[i].buf_addr) {
dma_free_coherent(&qedf->pdev->dev, QEDF_BDQ_BUF_SIZE,
qedf->bdq[i].buf_addr, qedf->bdq[i].buf_dma);
}
}
}
static void qedf_free_global_queues(struct qedf_ctx *qedf)
{
int i;
struct global_queue **gl = qedf->global_queues;
for (i = 0; i < qedf->num_queues; i++) {
if (!gl[i])
continue;
if (gl[i]->cq)
dma_free_coherent(&qedf->pdev->dev,
gl[i]->cq_mem_size, gl[i]->cq, gl[i]->cq_dma);
if (gl[i]->cq_pbl)
dma_free_coherent(&qedf->pdev->dev, gl[i]->cq_pbl_size,
gl[i]->cq_pbl, gl[i]->cq_pbl_dma);
kfree(gl[i]);
}
qedf_free_bdq(qedf);
}
static int qedf_alloc_bdq(struct qedf_ctx *qedf)
{
int i;
struct scsi_bd *pbl;
u64 *list;
dma_addr_t page;
for (i = 0; i < QEDF_BDQ_SIZE; i++) {
qedf->bdq[i].buf_addr = dma_alloc_coherent(&qedf->pdev->dev,
QEDF_BDQ_BUF_SIZE, &qedf->bdq[i].buf_dma, GFP_KERNEL);
if (!qedf->bdq[i].buf_addr) {
QEDF_ERR(&(qedf->dbg_ctx), "Could not allocate BDQ "
"buffer %d.\n", i);
return -ENOMEM;
}
}
qedf->bdq_pbl_mem_size =
QEDF_BDQ_SIZE * sizeof(struct scsi_bd);
qedf->bdq_pbl_mem_size =
ALIGN(qedf->bdq_pbl_mem_size, QEDF_PAGE_SIZE);
qedf->bdq_pbl = dma_alloc_coherent(&qedf->pdev->dev,
qedf->bdq_pbl_mem_size, &qedf->bdq_pbl_dma, GFP_KERNEL);
if (!qedf->bdq_pbl) {
QEDF_ERR(&(qedf->dbg_ctx), "Could not allocate BDQ PBL.\n");
return -ENOMEM;
}
QEDF_INFO(&(qedf->dbg_ctx), QEDF_LOG_DISC,
"BDQ PBL addr=0x%p dma=%pad\n",
qedf->bdq_pbl, &qedf->bdq_pbl_dma);
pbl = (struct scsi_bd *)qedf->bdq_pbl;
for (i = 0; i < QEDF_BDQ_SIZE; i++) {
pbl->address.hi = cpu_to_le32(U64_HI(qedf->bdq[i].buf_dma));
pbl->address.lo = cpu_to_le32(U64_LO(qedf->bdq[i].buf_dma));
pbl->opaque.hi = 0;
pbl->opaque.lo = cpu_to_le32(i);
pbl++;
}
qedf->bdq_pbl_list = dma_zalloc_coherent(&qedf->pdev->dev,
QEDF_PAGE_SIZE, &qedf->bdq_pbl_list_dma, GFP_KERNEL);
if (!qedf->bdq_pbl_list) {
QEDF_ERR(&(qedf->dbg_ctx), "Could not allocate list of PBL pages.\n");
return -ENOMEM;
}
qedf->bdq_pbl_list_num_entries = qedf->bdq_pbl_mem_size /
QEDF_PAGE_SIZE;
list = (u64 *)qedf->bdq_pbl_list;
page = qedf->bdq_pbl_list_dma;
for (i = 0; i < qedf->bdq_pbl_list_num_entries; i++) {
*list = qedf->bdq_pbl_dma;
list++;
page += QEDF_PAGE_SIZE;
}
return 0;
}
static int qedf_alloc_global_queues(struct qedf_ctx *qedf)
{
u32 *list;
int i;
int status = 0, rc;
u32 *pbl;
dma_addr_t page;
int num_pages;
if (!qedf->num_queues) {
QEDF_ERR(&(qedf->dbg_ctx), "No MSI-X vectors available!\n");
return 1;
}
if (!qedf->p_cpuq) {
status = 1;
goto mem_alloc_failure;
}
qedf->global_queues = kzalloc((sizeof(struct global_queue *)
* qedf->num_queues), GFP_KERNEL);
if (!qedf->global_queues) {
QEDF_ERR(&(qedf->dbg_ctx), "Unable to allocate global "
"queues array ptr memory\n");
return -ENOMEM;
}
QEDF_INFO(&(qedf->dbg_ctx), QEDF_LOG_DISC,
"qedf->global_queues=%p.\n", qedf->global_queues);
rc = qedf_alloc_bdq(qedf);
if (rc)
goto mem_alloc_failure;
for (i = 0; i < qedf->num_queues; i++) {
qedf->global_queues[i] = kzalloc(sizeof(struct global_queue),
GFP_KERNEL);
if (!qedf->global_queues[i]) {
QEDF_WARN(&(qedf->dbg_ctx), "Unable to allocate "
"global queue %d.\n", i);
status = -ENOMEM;
goto mem_alloc_failure;
}
qedf->global_queues[i]->cq_mem_size =
FCOE_PARAMS_CQ_NUM_ENTRIES * sizeof(struct fcoe_cqe);
qedf->global_queues[i]->cq_mem_size =
ALIGN(qedf->global_queues[i]->cq_mem_size, QEDF_PAGE_SIZE);
qedf->global_queues[i]->cq_pbl_size =
(qedf->global_queues[i]->cq_mem_size /
PAGE_SIZE) * sizeof(void *);
qedf->global_queues[i]->cq_pbl_size =
ALIGN(qedf->global_queues[i]->cq_pbl_size, QEDF_PAGE_SIZE);
qedf->global_queues[i]->cq =
dma_zalloc_coherent(&qedf->pdev->dev,
qedf->global_queues[i]->cq_mem_size,
&qedf->global_queues[i]->cq_dma, GFP_KERNEL);
if (!qedf->global_queues[i]->cq) {
QEDF_WARN(&(qedf->dbg_ctx), "Could not allocate cq.\n");
status = -ENOMEM;
goto mem_alloc_failure;
}
qedf->global_queues[i]->cq_pbl =
dma_zalloc_coherent(&qedf->pdev->dev,
qedf->global_queues[i]->cq_pbl_size,
&qedf->global_queues[i]->cq_pbl_dma, GFP_KERNEL);
if (!qedf->global_queues[i]->cq_pbl) {
QEDF_WARN(&(qedf->dbg_ctx), "Could not allocate cq PBL.\n");
status = -ENOMEM;
goto mem_alloc_failure;
}
num_pages = qedf->global_queues[i]->cq_mem_size /
QEDF_PAGE_SIZE;
page = qedf->global_queues[i]->cq_dma;
pbl = (u32 *)qedf->global_queues[i]->cq_pbl;
while (num_pages--) {
*pbl = U64_LO(page);
pbl++;
*pbl = U64_HI(page);
pbl++;
page += QEDF_PAGE_SIZE;
}
qedf->global_queues[i]->cq_cons_idx = 0;
}
list = (u32 *)qedf->p_cpuq;
for (i = 0; i < qedf->num_queues; i++) {
*list = U64_LO(qedf->global_queues[i]->cq_pbl_dma);
list++;
*list = U64_HI(qedf->global_queues[i]->cq_pbl_dma);
list++;
*list = U64_LO(0);
list++;
*list = U64_HI(0);
list++;
}
return 0;
mem_alloc_failure:
qedf_free_global_queues(qedf);
return status;
}
static int qedf_set_fcoe_pf_param(struct qedf_ctx *qedf)
{
u8 sq_num_pbl_pages;
u32 sq_mem_size;
u32 cq_mem_size;
u32 cq_num_entries;
int rval;
qedf->num_queues = MIN_NUM_CPUS_MSIX(qedf);
QEDF_INFO(&(qedf->dbg_ctx), QEDF_LOG_DISC, "Number of CQs is %d.\n",
qedf->num_queues);
qedf->p_cpuq = pci_alloc_consistent(qedf->pdev,
qedf->num_queues * sizeof(struct qedf_glbl_q_params),
&qedf->hw_p_cpuq);
if (!qedf->p_cpuq) {
QEDF_ERR(&(qedf->dbg_ctx), "pci_alloc_consistent failed.\n");
return 1;
}
rval = qedf_alloc_global_queues(qedf);
if (rval) {
QEDF_ERR(&(qedf->dbg_ctx), "Global queue allocation "
"failed.\n");
return 1;
}
sq_mem_size = SQ_NUM_ENTRIES * sizeof(struct fcoe_wqe);
sq_mem_size = ALIGN(sq_mem_size, QEDF_PAGE_SIZE);
sq_num_pbl_pages = (sq_mem_size / QEDF_PAGE_SIZE);
cq_mem_size = FCOE_PARAMS_CQ_NUM_ENTRIES * sizeof(struct fcoe_cqe);
cq_mem_size = ALIGN(cq_mem_size, QEDF_PAGE_SIZE);
cq_num_entries = cq_mem_size / sizeof(struct fcoe_cqe);
memset(&(qedf->pf_params), 0, sizeof(qedf->pf_params));
qedf->pf_params.fcoe_pf_params.num_cons = QEDF_MAX_SESSIONS;
qedf->pf_params.fcoe_pf_params.num_tasks = FCOE_PARAMS_NUM_TASKS;
qedf->pf_params.fcoe_pf_params.glbl_q_params_addr =
(u64)qedf->hw_p_cpuq;
qedf->pf_params.fcoe_pf_params.sq_num_pbl_pages = sq_num_pbl_pages;
qedf->pf_params.fcoe_pf_params.rq_buffer_log_size = 0;
qedf->pf_params.fcoe_pf_params.cq_num_entries = cq_num_entries;
qedf->pf_params.fcoe_pf_params.num_cqs = qedf->num_queues;
qedf->pf_params.fcoe_pf_params.log_page_size = ilog2(QEDF_PAGE_SIZE);
qedf->pf_params.fcoe_pf_params.mtu = 9000;
qedf->pf_params.fcoe_pf_params.gl_rq_pi = QEDF_FCOE_PARAMS_GL_RQ_PI;
qedf->pf_params.fcoe_pf_params.gl_cmd_pi = QEDF_FCOE_PARAMS_GL_CMD_PI;
qedf->pf_params.fcoe_pf_params.bdq_pbl_base_addr[0] =
qedf->bdq_pbl_list_dma;
qedf->pf_params.fcoe_pf_params.bdq_pbl_num_entries[0] =
qedf->bdq_pbl_list_num_entries;
qedf->pf_params.fcoe_pf_params.rq_buffer_size = QEDF_BDQ_BUF_SIZE;
QEDF_INFO(&(qedf->dbg_ctx), QEDF_LOG_DISC,
"bdq_list=%p bdq_pbl_list_dma=%llx bdq_pbl_list_entries=%d.\n",
qedf->bdq_pbl_list,
qedf->pf_params.fcoe_pf_params.bdq_pbl_base_addr[0],
qedf->pf_params.fcoe_pf_params.bdq_pbl_num_entries[0]);
QEDF_INFO(&(qedf->dbg_ctx), QEDF_LOG_DISC,
"cq_num_entries=%d.\n",
qedf->pf_params.fcoe_pf_params.cq_num_entries);
return 0;
}
static void qedf_free_fcoe_pf_param(struct qedf_ctx *qedf)
{
size_t size = 0;
if (qedf->p_cpuq) {
size = qedf->num_queues * sizeof(struct qedf_glbl_q_params);
pci_free_consistent(qedf->pdev, size, qedf->p_cpuq,
qedf->hw_p_cpuq);
}
qedf_free_global_queues(qedf);
if (qedf->global_queues)
kfree(qedf->global_queues);
}
static int __qedf_probe(struct pci_dev *pdev, int mode)
{
int rc = -EINVAL;
struct fc_lport *lport;
struct qedf_ctx *qedf;
struct Scsi_Host *host;
bool is_vf = false;
struct qed_ll2_params params;
char host_buf[20];
struct qed_link_params link_params;
int status;
void *task_start, *task_end;
struct qed_slowpath_params slowpath_params;
struct qed_probe_params qed_params;
u16 tmp;
if (mode != QEDF_MODE_RECOVERY) {
lport = libfc_host_alloc(&qedf_host_template,
sizeof(struct qedf_ctx));
if (!lport) {
QEDF_ERR(NULL, "Could not allocate lport.\n");
rc = -ENOMEM;
goto err0;
}
qedf = lport_priv(lport);
qedf->lport = lport;
qedf->ctlr.lp = lport;
qedf->pdev = pdev;
qedf->dbg_ctx.pdev = pdev;
qedf->dbg_ctx.host_no = lport->host->host_no;
spin_lock_init(&qedf->hba_lock);
INIT_LIST_HEAD(&qedf->fcports);
qedf->curr_conn_id = QEDF_MAX_SESSIONS - 1;
atomic_set(&qedf->num_offloads, 0);
qedf->stop_io_on_error = false;
pci_set_drvdata(pdev, qedf);
init_completion(&qedf->fipvlan_compl);
QEDF_INFO(&(qedf->dbg_ctx), QEDF_LOG_INFO,
"QLogic FastLinQ FCoE Module qedf %s, "
"FW %d.%d.%d.%d\n", QEDF_VERSION,
FW_MAJOR_VERSION, FW_MINOR_VERSION, FW_REVISION_VERSION,
FW_ENGINEERING_VERSION);
} else {
qedf = pci_get_drvdata(pdev);
lport = qedf->lport;
}
host = lport->host;
qedf->io_mempool = mempool_create_slab_pool(QEDF_IO_WORK_MIN,
qedf_io_work_cache);
if (qedf->io_mempool == NULL) {
QEDF_ERR(&(qedf->dbg_ctx), "qedf->io_mempool is NULL.\n");
goto err1;
}
QEDF_INFO(&(qedf->dbg_ctx), QEDF_LOG_INFO, "qedf->io_mempool=%p.\n",
qedf->io_mempool);
sprintf(host_buf, "qedf_%u_link",
qedf->lport->host->host_no);
qedf->link_update_wq = create_singlethread_workqueue(host_buf);
INIT_DELAYED_WORK(&qedf->link_update, qedf_handle_link_update);
INIT_DELAYED_WORK(&qedf->link_recovery, qedf_link_recovery);
qedf->fipvlan_retries = qedf_fipvlan_retries;
memset(&qed_params, 0, sizeof(qed_params));
qed_params.protocol = QED_PROTOCOL_FCOE;
qed_params.dp_module = qedf_dp_module;
qed_params.dp_level = qedf_dp_level;
qed_params.is_vf = is_vf;
qedf->cdev = qed_ops->common->probe(pdev, &qed_params);
if (!qedf->cdev) {
rc = -ENODEV;
goto err1;
}
rc = qed_ops->fill_dev_info(qedf->cdev, &qedf->dev_info);
if (rc) {
QEDF_ERR(&(qedf->dbg_ctx), "Failed to dev info.\n");
goto err1;
}
rc = qedf_set_fcoe_pf_param(qedf);
if (rc) {
QEDF_ERR(&(qedf->dbg_ctx), "Cannot set fcoe pf param.\n");
goto err2;
}
qed_ops->common->update_pf_params(qedf->cdev, &qedf->pf_params);
qedf->bdq_primary_prod = qedf->dev_info.primary_dbq_rq_addr;
qedf->bdq_secondary_prod = qedf->dev_info.secondary_bdq_rq_addr;
QEDF_INFO(&(qedf->dbg_ctx), QEDF_LOG_DISC,
"BDQ primary_prod=%p secondary_prod=%p.\n", qedf->bdq_primary_prod,
qedf->bdq_secondary_prod);
qed_ops->register_ops(qedf->cdev, &qedf_cb_ops, qedf);
rc = qedf_prepare_sb(qedf);
if (rc) {
QEDF_ERR(&(qedf->dbg_ctx), "Cannot start slowpath.\n");
goto err2;
}
slowpath_params.int_mode = QED_INT_MODE_MSIX;
slowpath_params.drv_major = QEDF_DRIVER_MAJOR_VER;
slowpath_params.drv_minor = QEDF_DRIVER_MINOR_VER;
slowpath_params.drv_rev = QEDF_DRIVER_REV_VER;
slowpath_params.drv_eng = QEDF_DRIVER_ENG_VER;
strncpy(slowpath_params.name, "qedf", QED_DRV_VER_STR_SIZE);
rc = qed_ops->common->slowpath_start(qedf->cdev, &slowpath_params);
if (rc) {
QEDF_ERR(&(qedf->dbg_ctx), "Cannot start slowpath.\n");
goto err2;
}
qed_ops->common->update_pf_params(qedf->cdev, &qedf->pf_params);
rc = qedf_setup_int(qedf);
if (rc)
goto err3;
rc = qed_ops->start(qedf->cdev, &qedf->tasks);
if (rc) {
QEDF_ERR(&(qedf->dbg_ctx), "Cannot start FCoE function.\n");
goto err4;
}
task_start = qedf_get_task_mem(&qedf->tasks, 0);
task_end = qedf_get_task_mem(&qedf->tasks, MAX_TID_BLOCKS_FCOE - 1);
QEDF_INFO(&(qedf->dbg_ctx), QEDF_LOG_DISC, "Task context start=%p, "
"end=%p block_size=%u.\n", task_start, task_end,
qedf->tasks.size);
qedf->bdq_prod_idx = QEDF_BDQ_SIZE;
QEDF_INFO(&(qedf->dbg_ctx), QEDF_LOG_DISC,
"Writing %d to primary and secondary BDQ doorbell registers.\n",
qedf->bdq_prod_idx);
writew(qedf->bdq_prod_idx, qedf->bdq_primary_prod);
tmp = readw(qedf->bdq_primary_prod);
writew(qedf->bdq_prod_idx, qedf->bdq_secondary_prod);
tmp = readw(qedf->bdq_secondary_prod);
qed_ops->common->set_power_state(qedf->cdev, PCI_D0);
ether_addr_copy(qedf->mac, qedf->dev_info.common.hw_mac);
QEDF_INFO(&(qedf->dbg_ctx), QEDF_LOG_DISC, "MAC address is %pM.\n",
qedf->mac);
qedf->wwnn = fcoe_wwn_from_mac(qedf->mac, 1, 0);
qedf->wwpn = fcoe_wwn_from_mac(qedf->mac, 2, 0);
QEDF_INFO(&(qedf->dbg_ctx), QEDF_LOG_DISC, "WWNN=%016llx "
"WWPN=%016llx.\n", qedf->wwnn, qedf->wwpn);
sprintf(host_buf, "host_%d", host->host_no);
qed_ops->common->set_name(qedf->cdev, host_buf);
qedf->max_scsi_xid = QEDF_MAX_SCSI_XID;
qedf->max_els_xid = QEDF_MAX_ELS_XID;
qedf->cmd_mgr = qedf_cmd_mgr_alloc(qedf);
if (!qedf->cmd_mgr) {
QEDF_ERR(&(qedf->dbg_ctx), "Failed to allocate cmd mgr.\n");
goto err5;
}
if (mode != QEDF_MODE_RECOVERY) {
host->transportt = qedf_fc_transport_template;
host->can_queue = QEDF_MAX_ELS_XID;
host->max_lun = qedf_max_lun;
host->max_cmd_len = QEDF_MAX_CDB_LEN;
rc = scsi_add_host(host, &pdev->dev);
if (rc)
goto err6;
}
memset(&params, 0, sizeof(params));
params.mtu = 9000;
ether_addr_copy(params.ll2_mac_address, qedf->mac);
snprintf(host_buf, 20, "qedf_%d_ll2", host->host_no);
qedf->ll2_recv_wq =
create_singlethread_workqueue(host_buf);
if (!qedf->ll2_recv_wq) {
QEDF_ERR(&(qedf->dbg_ctx), "Failed to LL2 workqueue.\n");
goto err7;
}
#ifdef CONFIG_DEBUG_FS
qedf_dbg_host_init(&(qedf->dbg_ctx), &qedf_debugfs_ops,
&qedf_dbg_fops);
#endif
qed_ops->ll2->register_cb_ops(qedf->cdev, &qedf_ll2_cb_ops, qedf);
rc = qed_ops->ll2->start(qedf->cdev, &params);
if (rc) {
QEDF_ERR(&(qedf->dbg_ctx), "Could not start Light L2.\n");
goto err7;
}
set_bit(QEDF_LL2_STARTED, &qedf->flags);
qedf->vlan_hw_insert = 1;
qedf->vlan_id = 0;
if (mode != QEDF_MODE_RECOVERY) {
qedf_fcoe_ctlr_setup(qedf);
rc = qedf_lport_setup(qedf);
if (rc) {
QEDF_ERR(&(qedf->dbg_ctx),
"qedf_lport_setup failed.\n");
goto err7;
}
}
sprintf(host_buf, "qedf_%u_timer", qedf->lport->host->host_no);
qedf->timer_work_queue =
create_singlethread_workqueue(host_buf);
if (!qedf->timer_work_queue) {
QEDF_ERR(&(qedf->dbg_ctx), "Failed to start timer "
"workqueue.\n");
goto err7;
}
if (mode != QEDF_MODE_RECOVERY) {
sprintf(host_buf, "qedf_%u_dpc",
qedf->lport->host->host_no);
qedf->dpc_wq = create_singlethread_workqueue(host_buf);
}
if (mode != QEDF_MODE_RECOVERY) {
qedf->grcdump_size = qed_ops->common->dbg_grc_size(qedf->cdev);
if (qedf->grcdump_size) {
rc = qedf_alloc_grc_dump_buf(&qedf->grcdump,
qedf->grcdump_size);
if (rc) {
QEDF_ERR(&(qedf->dbg_ctx),
"GRC Dump buffer alloc failed.\n");
qedf->grcdump = NULL;
}
QEDF_INFO(&(qedf->dbg_ctx), QEDF_LOG_DISC,
"grcdump: addr=%p, size=%u.\n",
qedf->grcdump, qedf->grcdump_size);
}
qedf_create_sysfs_ctx_attr(qedf);
spin_lock_init(&qedf->io_trace_lock);
qedf->io_trace_idx = 0;
}
init_completion(&qedf->flogi_compl);
memset(&link_params, 0, sizeof(struct qed_link_params));
link_params.link_up = true;
status = qed_ops->common->set_link(qedf->cdev, &link_params);
if (status)
QEDF_WARN(&(qedf->dbg_ctx), "set_link failed.\n");
if (mode == QEDF_MODE_RECOVERY)
fcoe_ctlr_link_up(&qedf->ctlr);
else
fc_fabric_login(lport);
return 0;
err7:
if (qedf->ll2_recv_wq)
destroy_workqueue(qedf->ll2_recv_wq);
fc_remove_host(qedf->lport->host);
scsi_remove_host(qedf->lport->host);
#ifdef CONFIG_DEBUG_FS
qedf_dbg_host_exit(&(qedf->dbg_ctx));
#endif
err6:
qedf_cmd_mgr_free(qedf->cmd_mgr);
err5:
qed_ops->stop(qedf->cdev);
err4:
qedf_free_fcoe_pf_param(qedf);
qedf_sync_free_irqs(qedf);
err3:
qed_ops->common->slowpath_stop(qedf->cdev);
err2:
qed_ops->common->remove(qedf->cdev);
err1:
scsi_host_put(lport->host);
err0:
return rc;
}
static int qedf_probe(struct pci_dev *pdev, const struct pci_device_id *id)
{
return __qedf_probe(pdev, QEDF_MODE_NORMAL);
}
static void __qedf_remove(struct pci_dev *pdev, int mode)
{
struct qedf_ctx *qedf;
if (!pdev) {
QEDF_ERR(NULL, "pdev is NULL.\n");
return;
}
qedf = pci_get_drvdata(pdev);
if (test_bit(QEDF_UNLOADING, &qedf->flags)) {
QEDF_ERR(&qedf->dbg_ctx, "Already removing PCI function.\n");
return;
}
if (mode != QEDF_MODE_RECOVERY)
set_bit(QEDF_UNLOADING, &qedf->flags);
if (mode == QEDF_MODE_RECOVERY)
fcoe_ctlr_link_down(&qedf->ctlr);
else
fc_fabric_logoff(qedf->lport);
qedf_wait_for_upload(qedf);
#ifdef CONFIG_DEBUG_FS
qedf_dbg_host_exit(&(qedf->dbg_ctx));
#endif
cancel_delayed_work_sync(&qedf->link_update);
destroy_workqueue(qedf->link_update_wq);
qedf->link_update_wq = NULL;
if (qedf->timer_work_queue)
destroy_workqueue(qedf->timer_work_queue);
clear_bit(QEDF_LL2_STARTED, &qedf->flags);
qed_ops->ll2->stop(qedf->cdev);
if (qedf->ll2_recv_wq)
destroy_workqueue(qedf->ll2_recv_wq);
qedf_sync_free_irqs(qedf);
qedf_destroy_sb(qedf);
if (mode != QEDF_MODE_RECOVERY) {
qedf_free_grc_dump_buf(&qedf->grcdump);
qedf_remove_sysfs_ctx_attr(qedf);
fcoe_ctlr_destroy(&qedf->ctlr);
fc_lport_destroy(qedf->lport);
fc_remove_host(qedf->lport->host);
scsi_remove_host(qedf->lport->host);
}
qedf_cmd_mgr_free(qedf->cmd_mgr);
if (mode != QEDF_MODE_RECOVERY) {
fc_exch_mgr_free(qedf->lport);
fc_lport_free_stats(qedf->lport);
qedf_wait_for_vport_destroy(qedf);
}
qed_ops->stop(qedf->cdev);
if (mode != QEDF_MODE_RECOVERY) {
if (qedf->dpc_wq) {
destroy_workqueue(qedf->dpc_wq);
qedf->dpc_wq = NULL;
}
}
qedf_free_fcoe_pf_param(qedf);
if (mode != QEDF_MODE_RECOVERY) {
qed_ops->common->set_power_state(qedf->cdev, PCI_D0);
pci_set_drvdata(pdev, NULL);
}
qed_ops->common->slowpath_stop(qedf->cdev);
qed_ops->common->remove(qedf->cdev);
mempool_destroy(qedf->io_mempool);
if (mode != QEDF_MODE_RECOVERY)
scsi_host_put(qedf->lport->host);
}
static void qedf_remove(struct pci_dev *pdev)
{
if (!atomic_read(&pdev->enable_cnt))
return;
__qedf_remove(pdev, QEDF_MODE_NORMAL);
}
static int __init qedf_init(void)
{
int ret;
if (qedf_debug == QEDF_LOG_DEFAULT)
qedf_debug = QEDF_DEFAULT_LOG_MASK;
QEDF_INFO(NULL, QEDF_LOG_INFO, "%s v%s.\n", QEDF_DESCR,
QEDF_VERSION);
qedf_io_work_cache = kmem_cache_create("qedf_io_work_cache",
sizeof(struct qedf_io_work), 0, SLAB_HWCACHE_ALIGN, NULL);
if (qedf_io_work_cache == NULL) {
QEDF_ERR(NULL, "qedf_io_work_cache is NULL.\n");
goto err1;
}
QEDF_INFO(NULL, QEDF_LOG_DISC, "qedf_io_work_cache=%p.\n",
qedf_io_work_cache);
qed_ops = qed_get_fcoe_ops();
if (!qed_ops) {
QEDF_ERR(NULL, "Failed to get qed fcoe operations\n");
goto err1;
}
#ifdef CONFIG_DEBUG_FS
qedf_dbg_init("qedf");
#endif
qedf_fc_transport_template =
fc_attach_transport(&qedf_fc_transport_fn);
if (!qedf_fc_transport_template) {
QEDF_ERR(NULL, "Could not register with FC transport\n");
goto err2;
}
qedf_fc_vport_transport_template =
fc_attach_transport(&qedf_fc_vport_transport_fn);
if (!qedf_fc_vport_transport_template) {
QEDF_ERR(NULL, "Could not register vport template with FC "
"transport\n");
goto err3;
}
qedf_io_wq = create_workqueue("qedf_io_wq");
if (!qedf_io_wq) {
QEDF_ERR(NULL, "Could not create qedf_io_wq.\n");
goto err4;
}
qedf_cb_ops.get_login_failures = qedf_get_login_failures;
ret = pci_register_driver(&qedf_pci_driver);
if (ret) {
QEDF_ERR(NULL, "Failed to register driver\n");
goto err5;
}
return 0;
err5:
destroy_workqueue(qedf_io_wq);
err4:
fc_release_transport(qedf_fc_vport_transport_template);
err3:
fc_release_transport(qedf_fc_transport_template);
err2:
#ifdef CONFIG_DEBUG_FS
qedf_dbg_exit();
#endif
qed_put_fcoe_ops();
err1:
return -EINVAL;
}
static void __exit qedf_cleanup(void)
{
pci_unregister_driver(&qedf_pci_driver);
destroy_workqueue(qedf_io_wq);
fc_release_transport(qedf_fc_vport_transport_template);
fc_release_transport(qedf_fc_transport_template);
#ifdef CONFIG_DEBUG_FS
qedf_dbg_exit();
#endif
qed_put_fcoe_ops();
kmem_cache_destroy(qedf_io_work_cache);
}
