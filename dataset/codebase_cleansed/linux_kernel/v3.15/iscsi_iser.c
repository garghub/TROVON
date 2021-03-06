void
iscsi_iser_recv(struct iscsi_conn *conn,
struct iscsi_hdr *hdr, char *rx_data, int rx_data_len)
{
int rc = 0;
int datalen;
int ahslen;
datalen = ntoh24(hdr->dlength);
if (datalen > rx_data_len || (datalen + 4) < rx_data_len) {
iser_err("wrong datalen %d (hdr), %d (IB)\n",
datalen, rx_data_len);
rc = ISCSI_ERR_DATALEN;
goto error;
}
if (datalen != rx_data_len)
iser_dbg("aligned datalen (%d) hdr, %d (IB)\n",
datalen, rx_data_len);
ahslen = hdr->hlength * 4;
rc = iscsi_complete_pdu(conn, hdr, rx_data, rx_data_len);
if (rc && rc != ISCSI_ERR_NO_SCSI_CMD)
goto error;
return;
error:
iscsi_conn_failure(conn, rc);
}
static int iscsi_iser_pdu_alloc(struct iscsi_task *task, uint8_t opcode)
{
struct iscsi_iser_task *iser_task = task->dd_data;
task->hdr = (struct iscsi_hdr *)&iser_task->desc.iscsi_header;
task->hdr_max = sizeof(iser_task->desc.iscsi_header);
return 0;
}
int iser_initialize_task_headers(struct iscsi_task *task,
struct iser_tx_desc *tx_desc)
{
struct iser_conn *ib_conn = task->conn->dd_data;
struct iser_device *device = ib_conn->device;
struct iscsi_iser_task *iser_task = task->dd_data;
u64 dma_addr;
dma_addr = ib_dma_map_single(device->ib_device, (void *)tx_desc,
ISER_HEADERS_LEN, DMA_TO_DEVICE);
if (ib_dma_mapping_error(device->ib_device, dma_addr))
return -ENOMEM;
tx_desc->dma_addr = dma_addr;
tx_desc->tx_sg[0].addr = tx_desc->dma_addr;
tx_desc->tx_sg[0].length = ISER_HEADERS_LEN;
tx_desc->tx_sg[0].lkey = device->mr->lkey;
iser_task->ib_conn = ib_conn;
return 0;
}
static int
iscsi_iser_task_init(struct iscsi_task *task)
{
struct iscsi_iser_task *iser_task = task->dd_data;
if (iser_initialize_task_headers(task, &iser_task->desc))
return -ENOMEM;
if (!task->sc)
return 0;
iser_task->command_sent = 0;
iser_task_rdma_init(iser_task);
iser_task->sc = task->sc;
return 0;
}
static int
iscsi_iser_mtask_xmit(struct iscsi_conn *conn, struct iscsi_task *task)
{
int error = 0;
iser_dbg("mtask xmit [cid %d itt 0x%x]\n", conn->id, task->itt);
error = iser_send_control(conn, task);
return error;
}
static int
iscsi_iser_task_xmit_unsol_data(struct iscsi_conn *conn,
struct iscsi_task *task)
{
struct iscsi_r2t_info *r2t = &task->unsol_r2t;
struct iscsi_data hdr;
int error = 0;
while (iscsi_task_has_unsol_data(task)) {
iscsi_prep_data_out_pdu(task, r2t, &hdr);
iser_dbg("Sending data-out: itt 0x%x, data count %d\n",
hdr.itt, r2t->data_count);
error = iser_send_data_out(conn, task, &hdr);
if (error) {
r2t->datasn--;
goto iscsi_iser_task_xmit_unsol_data_exit;
}
r2t->sent += r2t->data_count;
iser_dbg("Need to send %d more as data-out PDUs\n",
r2t->data_length - r2t->sent);
}
iscsi_iser_task_xmit_unsol_data_exit:
return error;
}
static int
iscsi_iser_task_xmit(struct iscsi_task *task)
{
struct iscsi_conn *conn = task->conn;
struct iscsi_iser_task *iser_task = task->dd_data;
int error = 0;
if (!task->sc)
return iscsi_iser_mtask_xmit(conn, task);
if (task->sc->sc_data_direction == DMA_TO_DEVICE) {
BUG_ON(scsi_bufflen(task->sc) == 0);
iser_dbg("cmd [itt %x total %d imm %d unsol_data %d\n",
task->itt, scsi_bufflen(task->sc),
task->imm_count, task->unsol_r2t.data_length);
}
iser_dbg("ctask xmit [cid %d itt 0x%x]\n",
conn->id, task->itt);
if (!iser_task->command_sent) {
error = iser_send_command(conn, task);
if (error)
goto iscsi_iser_task_xmit_exit;
iser_task->command_sent = 1;
}
if (iscsi_task_has_unsol_data(task))
error = iscsi_iser_task_xmit_unsol_data(conn, task);
iscsi_iser_task_xmit_exit:
return error;
}
static void iscsi_iser_cleanup_task(struct iscsi_task *task)
{
struct iscsi_iser_task *iser_task = task->dd_data;
struct iser_tx_desc *tx_desc = &iser_task->desc;
struct iser_conn *ib_conn = task->conn->dd_data;
struct iser_device *device = ib_conn->device;
ib_dma_unmap_single(device->ib_device,
tx_desc->dma_addr, ISER_HEADERS_LEN, DMA_TO_DEVICE);
if (!task->sc)
return;
if (iser_task->status == ISER_TASK_STATUS_STARTED) {
iser_task->status = ISER_TASK_STATUS_COMPLETED;
iser_task_rdma_finalize(iser_task);
}
}
static u8 iscsi_iser_check_protection(struct iscsi_task *task, sector_t *sector)
{
struct iscsi_iser_task *iser_task = task->dd_data;
if (iser_task->dir[ISER_DIR_IN])
return iser_check_task_pi_status(iser_task, ISER_DIR_IN,
sector);
else
return iser_check_task_pi_status(iser_task, ISER_DIR_OUT,
sector);
}
static struct iscsi_cls_conn *
iscsi_iser_conn_create(struct iscsi_cls_session *cls_session, uint32_t conn_idx)
{
struct iscsi_conn *conn;
struct iscsi_cls_conn *cls_conn;
cls_conn = iscsi_conn_setup(cls_session, 0, conn_idx);
if (!cls_conn)
return NULL;
conn = cls_conn->dd_data;
conn->max_recv_dlength = ISER_RECV_DATA_SEG_LEN;
return cls_conn;
}
static void
iscsi_iser_conn_destroy(struct iscsi_cls_conn *cls_conn)
{
struct iscsi_conn *conn = cls_conn->dd_data;
struct iser_conn *ib_conn = conn->dd_data;
iscsi_conn_teardown(cls_conn);
if (ib_conn) {
ib_conn->iscsi_conn = NULL;
iser_conn_put(ib_conn, 1);
}
}
static int
iscsi_iser_conn_bind(struct iscsi_cls_session *cls_session,
struct iscsi_cls_conn *cls_conn, uint64_t transport_eph,
int is_leading)
{
struct iscsi_conn *conn = cls_conn->dd_data;
struct iscsi_session *session;
struct iser_conn *ib_conn;
struct iscsi_endpoint *ep;
int error;
error = iscsi_conn_bind(cls_session, cls_conn, is_leading);
if (error)
return error;
ep = iscsi_lookup_endpoint(transport_eph);
if (!ep) {
iser_err("can't bind eph %llx\n",
(unsigned long long)transport_eph);
return -EINVAL;
}
ib_conn = ep->dd_data;
session = conn->session;
if (iser_alloc_rx_descriptors(ib_conn, session))
return -ENOMEM;
iser_info("binding iscsi conn %p to ib_conn %p\n", conn, ib_conn);
conn->dd_data = ib_conn;
ib_conn->iscsi_conn = conn;
iser_conn_get(ib_conn);
return 0;
}
static void
iscsi_iser_conn_stop(struct iscsi_cls_conn *cls_conn, int flag)
{
struct iscsi_conn *conn = cls_conn->dd_data;
struct iser_conn *ib_conn = conn->dd_data;
if (ib_conn) {
iscsi_conn_stop(cls_conn, flag);
iser_conn_put(ib_conn, 1);
}
conn->dd_data = NULL;
}
static void iscsi_iser_session_destroy(struct iscsi_cls_session *cls_session)
{
struct Scsi_Host *shost = iscsi_session_to_shost(cls_session);
iscsi_session_teardown(cls_session);
iscsi_host_remove(shost);
iscsi_host_free(shost);
}
static inline unsigned int
iser_dif_prot_caps(int prot_caps)
{
return ((prot_caps & IB_PROT_T10DIF_TYPE_1) ? SHOST_DIF_TYPE1_PROTECTION |
SHOST_DIX_TYPE1_PROTECTION : 0) |
((prot_caps & IB_PROT_T10DIF_TYPE_2) ? SHOST_DIF_TYPE2_PROTECTION |
SHOST_DIX_TYPE2_PROTECTION : 0) |
((prot_caps & IB_PROT_T10DIF_TYPE_3) ? SHOST_DIF_TYPE3_PROTECTION |
SHOST_DIX_TYPE3_PROTECTION : 0);
}
static struct iscsi_cls_session *
iscsi_iser_session_create(struct iscsi_endpoint *ep,
uint16_t cmds_max, uint16_t qdepth,
uint32_t initial_cmdsn)
{
struct iscsi_cls_session *cls_session;
struct iscsi_session *session;
struct Scsi_Host *shost;
struct iser_conn *ib_conn = NULL;
shost = iscsi_host_alloc(&iscsi_iser_sht, 0, 0);
if (!shost)
return NULL;
shost->transportt = iscsi_iser_scsi_transport;
shost->cmd_per_lun = qdepth;
shost->max_lun = iscsi_max_lun;
shost->max_id = 0;
shost->max_channel = 0;
shost->max_cmd_len = 16;
if (ep) {
ib_conn = ep->dd_data;
if (ib_conn->pi_support) {
u32 sig_caps = ib_conn->device->dev_attr.sig_prot_cap;
scsi_host_set_prot(shost, iser_dif_prot_caps(sig_caps));
if (iser_pi_guard)
scsi_host_set_guard(shost, SHOST_DIX_GUARD_IP);
else
scsi_host_set_guard(shost, SHOST_DIX_GUARD_CRC);
}
}
if (iscsi_host_add(shost,
ep ? ib_conn->device->ib_device->dma_device : NULL))
goto free_host;
if (cmds_max > ISER_DEF_XMIT_CMDS_MAX) {
iser_info("cmds_max changed from %u to %u\n",
cmds_max, ISER_DEF_XMIT_CMDS_MAX);
cmds_max = ISER_DEF_XMIT_CMDS_MAX;
}
cls_session = iscsi_session_setup(&iscsi_iser_transport, shost,
cmds_max, 0,
sizeof(struct iscsi_iser_task),
initial_cmdsn, 0);
if (!cls_session)
goto remove_host;
session = cls_session->dd_data;
shost->can_queue = session->scsi_cmds_max;
return cls_session;
remove_host:
iscsi_host_remove(shost);
free_host:
iscsi_host_free(shost);
return NULL;
}
static int
iscsi_iser_set_param(struct iscsi_cls_conn *cls_conn,
enum iscsi_param param, char *buf, int buflen)
{
int value;
switch (param) {
case ISCSI_PARAM_MAX_RECV_DLENGTH:
break;
case ISCSI_PARAM_HDRDGST_EN:
sscanf(buf, "%d", &value);
if (value) {
iser_err("DataDigest wasn't negotiated to None");
return -EPROTO;
}
break;
case ISCSI_PARAM_DATADGST_EN:
sscanf(buf, "%d", &value);
if (value) {
iser_err("DataDigest wasn't negotiated to None");
return -EPROTO;
}
break;
case ISCSI_PARAM_IFMARKER_EN:
sscanf(buf, "%d", &value);
if (value) {
iser_err("IFMarker wasn't negotiated to No");
return -EPROTO;
}
break;
case ISCSI_PARAM_OFMARKER_EN:
sscanf(buf, "%d", &value);
if (value) {
iser_err("OFMarker wasn't negotiated to No");
return -EPROTO;
}
break;
default:
return iscsi_set_param(cls_conn, param, buf, buflen);
}
return 0;
}
static void
iscsi_iser_conn_get_stats(struct iscsi_cls_conn *cls_conn, struct iscsi_stats *stats)
{
struct iscsi_conn *conn = cls_conn->dd_data;
stats->txdata_octets = conn->txdata_octets;
stats->rxdata_octets = conn->rxdata_octets;
stats->scsicmd_pdus = conn->scsicmd_pdus_cnt;
stats->dataout_pdus = conn->dataout_pdus_cnt;
stats->scsirsp_pdus = conn->scsirsp_pdus_cnt;
stats->datain_pdus = conn->datain_pdus_cnt;
stats->r2t_pdus = conn->r2t_pdus_cnt;
stats->tmfcmd_pdus = conn->tmfcmd_pdus_cnt;
stats->tmfrsp_pdus = conn->tmfrsp_pdus_cnt;
stats->custom_length = 4;
strcpy(stats->custom[0].desc, "qp_tx_queue_full");
stats->custom[0].value = 0;
strcpy(stats->custom[1].desc, "fmr_map_not_avail");
stats->custom[1].value = 0; ;
strcpy(stats->custom[2].desc, "eh_abort_cnt");
stats->custom[2].value = conn->eh_abort_cnt;
strcpy(stats->custom[3].desc, "fmr_unalign_cnt");
stats->custom[3].value = conn->fmr_unalign_cnt;
}
static int iscsi_iser_get_ep_param(struct iscsi_endpoint *ep,
enum iscsi_param param, char *buf)
{
struct iser_conn *ib_conn = ep->dd_data;
int len;
switch (param) {
case ISCSI_PARAM_CONN_PORT:
case ISCSI_PARAM_CONN_ADDRESS:
if (!ib_conn || !ib_conn->cma_id)
return -ENOTCONN;
return iscsi_conn_get_addr_param((struct sockaddr_storage *)
&ib_conn->cma_id->route.addr.dst_addr,
param, buf);
break;
default:
return -ENOSYS;
}
return len;
}
static struct iscsi_endpoint *
iscsi_iser_ep_connect(struct Scsi_Host *shost, struct sockaddr *dst_addr,
int non_blocking)
{
int err;
struct iser_conn *ib_conn;
struct iscsi_endpoint *ep;
ep = iscsi_create_endpoint(sizeof(*ib_conn));
if (!ep)
return ERR_PTR(-ENOMEM);
ib_conn = ep->dd_data;
ib_conn->ep = ep;
iser_conn_init(ib_conn);
err = iser_connect(ib_conn, NULL, (struct sockaddr_in *)dst_addr,
non_blocking);
if (err)
return ERR_PTR(err);
return ep;
}
static int
iscsi_iser_ep_poll(struct iscsi_endpoint *ep, int timeout_ms)
{
struct iser_conn *ib_conn;
int rc;
ib_conn = ep->dd_data;
rc = wait_event_interruptible_timeout(ib_conn->wait,
ib_conn->state == ISER_CONN_UP,
msecs_to_jiffies(timeout_ms));
if (!rc &&
(ib_conn->state == ISER_CONN_TERMINATING ||
ib_conn->state == ISER_CONN_DOWN))
rc = -1;
iser_info("ib conn %p rc = %d\n", ib_conn, rc);
if (rc > 0)
return 1;
else if (!rc)
return 0;
else
return rc;
}
static void
iscsi_iser_ep_disconnect(struct iscsi_endpoint *ep)
{
struct iser_conn *ib_conn;
ib_conn = ep->dd_data;
if (ib_conn->iscsi_conn)
iscsi_suspend_tx(ib_conn->iscsi_conn);
iser_info("ib conn %p state %d\n", ib_conn, ib_conn->state);
iser_conn_terminate(ib_conn);
}
static umode_t iser_attr_is_visible(int param_type, int param)
{
switch (param_type) {
case ISCSI_HOST_PARAM:
switch (param) {
case ISCSI_HOST_PARAM_NETDEV_NAME:
case ISCSI_HOST_PARAM_HWADDRESS:
case ISCSI_HOST_PARAM_INITIATOR_NAME:
return S_IRUGO;
default:
return 0;
}
case ISCSI_PARAM:
switch (param) {
case ISCSI_PARAM_MAX_RECV_DLENGTH:
case ISCSI_PARAM_MAX_XMIT_DLENGTH:
case ISCSI_PARAM_HDRDGST_EN:
case ISCSI_PARAM_DATADGST_EN:
case ISCSI_PARAM_CONN_ADDRESS:
case ISCSI_PARAM_CONN_PORT:
case ISCSI_PARAM_EXP_STATSN:
case ISCSI_PARAM_PERSISTENT_ADDRESS:
case ISCSI_PARAM_PERSISTENT_PORT:
case ISCSI_PARAM_PING_TMO:
case ISCSI_PARAM_RECV_TMO:
case ISCSI_PARAM_INITIAL_R2T_EN:
case ISCSI_PARAM_MAX_R2T:
case ISCSI_PARAM_IMM_DATA_EN:
case ISCSI_PARAM_FIRST_BURST:
case ISCSI_PARAM_MAX_BURST:
case ISCSI_PARAM_PDU_INORDER_EN:
case ISCSI_PARAM_DATASEQ_INORDER_EN:
case ISCSI_PARAM_TARGET_NAME:
case ISCSI_PARAM_TPGT:
case ISCSI_PARAM_USERNAME:
case ISCSI_PARAM_PASSWORD:
case ISCSI_PARAM_USERNAME_IN:
case ISCSI_PARAM_PASSWORD_IN:
case ISCSI_PARAM_FAST_ABORT:
case ISCSI_PARAM_ABORT_TMO:
case ISCSI_PARAM_LU_RESET_TMO:
case ISCSI_PARAM_TGT_RESET_TMO:
case ISCSI_PARAM_IFACE_NAME:
case ISCSI_PARAM_INITIATOR_NAME:
case ISCSI_PARAM_DISCOVERY_SESS:
return S_IRUGO;
default:
return 0;
}
}
return 0;
}
static int __init iser_init(void)
{
int err;
iser_dbg("Starting iSER datamover...\n");
if (iscsi_max_lun < 1) {
iser_err("Invalid max_lun value of %u\n", iscsi_max_lun);
return -EINVAL;
}
memset(&ig, 0, sizeof(struct iser_global));
ig.desc_cache = kmem_cache_create("iser_descriptors",
sizeof(struct iser_tx_desc),
0, SLAB_HWCACHE_ALIGN,
NULL);
if (ig.desc_cache == NULL)
return -ENOMEM;
mutex_init(&ig.device_list_mutex);
INIT_LIST_HEAD(&ig.device_list);
mutex_init(&ig.connlist_mutex);
INIT_LIST_HEAD(&ig.connlist);
iscsi_iser_scsi_transport = iscsi_register_transport(
&iscsi_iser_transport);
if (!iscsi_iser_scsi_transport) {
iser_err("iscsi_register_transport failed\n");
err = -EINVAL;
goto register_transport_failure;
}
return 0;
register_transport_failure:
kmem_cache_destroy(ig.desc_cache);
return err;
}
static void __exit iser_exit(void)
{
iser_dbg("Removing iSER datamover...\n");
iscsi_unregister_transport(&iscsi_iser_transport);
kmem_cache_destroy(ig.desc_cache);
}
