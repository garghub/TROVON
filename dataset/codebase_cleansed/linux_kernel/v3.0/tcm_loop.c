static struct se_cmd *tcm_loop_allocate_core_cmd(
struct tcm_loop_hba *tl_hba,
struct se_portal_group *se_tpg,
struct scsi_cmnd *sc)
{
struct se_cmd *se_cmd;
struct se_session *se_sess;
struct tcm_loop_nexus *tl_nexus = tl_hba->tl_nexus;
struct tcm_loop_cmd *tl_cmd;
int sam_task_attr;
if (!tl_nexus) {
scmd_printk(KERN_ERR, sc, "TCM_Loop I_T Nexus"
" does not exist\n");
set_host_byte(sc, DID_ERROR);
return NULL;
}
se_sess = tl_nexus->se_sess;
tl_cmd = kmem_cache_zalloc(tcm_loop_cmd_cache, GFP_ATOMIC);
if (!tl_cmd) {
printk(KERN_ERR "Unable to allocate struct tcm_loop_cmd\n");
set_host_byte(sc, DID_ERROR);
return NULL;
}
se_cmd = &tl_cmd->tl_se_cmd;
tl_cmd->sc = sc;
if (sc->device->tagged_supported) {
switch (sc->tag) {
case HEAD_OF_QUEUE_TAG:
sam_task_attr = MSG_HEAD_TAG;
break;
case ORDERED_QUEUE_TAG:
sam_task_attr = MSG_ORDERED_TAG;
break;
default:
sam_task_attr = MSG_SIMPLE_TAG;
break;
}
} else
sam_task_attr = MSG_SIMPLE_TAG;
transport_init_se_cmd(se_cmd, se_tpg->se_tpg_tfo, se_sess,
scsi_bufflen(sc), sc->sc_data_direction, sam_task_attr,
&tl_cmd->tl_sense_buf[0]);
if (scsi_bidi_cmnd(sc))
T_TASK(se_cmd)->t_tasks_bidi = 1;
if (transport_get_lun_for_cmd(se_cmd, NULL, tl_cmd->sc->device->lun) < 0) {
kmem_cache_free(tcm_loop_cmd_cache, tl_cmd);
set_host_byte(sc, DID_NO_CONNECT);
return NULL;
}
transport_device_setup_cmd(se_cmd);
return se_cmd;
}
static int tcm_loop_new_cmd_map(struct se_cmd *se_cmd)
{
struct tcm_loop_cmd *tl_cmd = container_of(se_cmd,
struct tcm_loop_cmd, tl_se_cmd);
struct scsi_cmnd *sc = tl_cmd->sc;
void *mem_ptr, *mem_bidi_ptr = NULL;
u32 sg_no_bidi = 0;
int ret;
ret = transport_generic_allocate_tasks(se_cmd, tl_cmd->sc->cmnd);
if (ret == -1) {
return PYX_TRANSPORT_LU_COMM_FAILURE;
} else if (ret == -2) {
if (se_cmd->se_cmd_flags & SCF_SCSI_RESERVATION_CONFLICT)
return PYX_TRANSPORT_RESERVATION_CONFLICT;
return PYX_TRANSPORT_USE_SENSE_REASON;
}
if (scsi_sg_count(sc)) {
se_cmd->se_cmd_flags |= SCF_PASSTHROUGH_SG_TO_MEM;
mem_ptr = (void *)scsi_sglist(sc);
if (T_TASK(se_cmd)->t_tasks_bidi) {
struct scsi_data_buffer *sdb = scsi_in(sc);
mem_bidi_ptr = (void *)sdb->table.sgl;
sg_no_bidi = sdb->table.nents;
}
} else {
mem_ptr = NULL;
}
ret = transport_generic_map_mem_to_cmd(se_cmd, mem_ptr,
scsi_sg_count(sc), mem_bidi_ptr, sg_no_bidi);
if (ret < 0)
return PYX_TRANSPORT_LU_COMM_FAILURE;
return 0;
}
static void tcm_loop_check_stop_free(struct se_cmd *se_cmd)
{
if (se_cmd->se_tmr_req)
return;
transport_generic_free_cmd(se_cmd, 0, 1, 0);
}
static void tcm_loop_deallocate_core_cmd(struct se_cmd *se_cmd)
{
struct tcm_loop_cmd *tl_cmd = container_of(se_cmd,
struct tcm_loop_cmd, tl_se_cmd);
kmem_cache_free(tcm_loop_cmd_cache, tl_cmd);
}
static int tcm_loop_proc_info(struct Scsi_Host *host, char *buffer,
char **start, off_t offset,
int length, int inout)
{
return sprintf(buffer, "tcm_loop_proc_info()\n");
}
static int pseudo_lld_bus_match(struct device *dev,
struct device_driver *dev_driver)
{
return 1;
}
static int tcm_loop_change_queue_depth(
struct scsi_device *sdev,
int depth,
int reason)
{
switch (reason) {
case SCSI_QDEPTH_DEFAULT:
scsi_adjust_queue_depth(sdev, scsi_get_tag_type(sdev), depth);
break;
case SCSI_QDEPTH_QFULL:
scsi_track_queue_full(sdev, depth);
break;
case SCSI_QDEPTH_RAMP_UP:
scsi_adjust_queue_depth(sdev, scsi_get_tag_type(sdev), depth);
break;
default:
return -EOPNOTSUPP;
}
return sdev->queue_depth;
}
static int tcm_loop_queuecommand(
struct Scsi_Host *sh,
struct scsi_cmnd *sc)
{
struct se_cmd *se_cmd;
struct se_portal_group *se_tpg;
struct tcm_loop_hba *tl_hba;
struct tcm_loop_tpg *tl_tpg;
TL_CDB_DEBUG("tcm_loop_queuecommand() %d:%d:%d:%d got CDB: 0x%02x"
" scsi_buf_len: %u\n", sc->device->host->host_no,
sc->device->id, sc->device->channel, sc->device->lun,
sc->cmnd[0], scsi_bufflen(sc));
tl_hba = *(struct tcm_loop_hba **)shost_priv(sc->device->host);
tl_tpg = &tl_hba->tl_hba_tpgs[sc->device->id];
se_tpg = &tl_tpg->tl_se_tpg;
se_cmd = tcm_loop_allocate_core_cmd(tl_hba, se_tpg, sc);
if (!se_cmd) {
sc->scsi_done(sc);
return 0;
}
transport_generic_handle_cdb_map(se_cmd);
return 0;
}
static int tcm_loop_device_reset(struct scsi_cmnd *sc)
{
struct se_cmd *se_cmd = NULL;
struct se_portal_group *se_tpg;
struct se_session *se_sess;
struct tcm_loop_cmd *tl_cmd = NULL;
struct tcm_loop_hba *tl_hba;
struct tcm_loop_nexus *tl_nexus;
struct tcm_loop_tmr *tl_tmr = NULL;
struct tcm_loop_tpg *tl_tpg;
int ret = FAILED;
tl_hba = *(struct tcm_loop_hba **)shost_priv(sc->device->host);
tl_nexus = tl_hba->tl_nexus;
if (!tl_nexus) {
printk(KERN_ERR "Unable to perform device reset without"
" active I_T Nexus\n");
return FAILED;
}
se_sess = tl_nexus->se_sess;
tl_tpg = &tl_hba->tl_hba_tpgs[sc->device->id];
se_tpg = &tl_tpg->tl_se_tpg;
tl_cmd = kmem_cache_zalloc(tcm_loop_cmd_cache, GFP_KERNEL);
if (!tl_cmd) {
printk(KERN_ERR "Unable to allocate memory for tl_cmd\n");
return FAILED;
}
tl_tmr = kzalloc(sizeof(struct tcm_loop_tmr), GFP_KERNEL);
if (!tl_tmr) {
printk(KERN_ERR "Unable to allocate memory for tl_tmr\n");
goto release;
}
init_waitqueue_head(&tl_tmr->tl_tmr_wait);
se_cmd = &tl_cmd->tl_se_cmd;
transport_init_se_cmd(se_cmd, se_tpg->se_tpg_tfo, se_sess, 0,
DMA_NONE, MSG_SIMPLE_TAG,
&tl_cmd->tl_sense_buf[0]);
se_cmd->se_tmr_req = core_tmr_alloc_req(se_cmd, (void *)tl_tmr,
TMR_LUN_RESET);
if (IS_ERR(se_cmd->se_tmr_req))
goto release;
if (transport_get_lun_for_tmr(se_cmd, sc->device->lun) < 0)
goto release;
transport_generic_handle_tmr(se_cmd);
wait_event(tl_tmr->tl_tmr_wait, atomic_read(&tl_tmr->tmr_complete));
ret = (se_cmd->se_tmr_req->response == TMR_FUNCTION_COMPLETE) ?
SUCCESS : FAILED;
release:
if (se_cmd)
transport_generic_free_cmd(se_cmd, 1, 1, 0);
else
kmem_cache_free(tcm_loop_cmd_cache, tl_cmd);
kfree(tl_tmr);
return ret;
}
static int tcm_loop_slave_alloc(struct scsi_device *sd)
{
set_bit(QUEUE_FLAG_BIDI, &sd->request_queue->queue_flags);
return 0;
}
static int tcm_loop_slave_configure(struct scsi_device *sd)
{
return 0;
}
static int tcm_loop_driver_probe(struct device *dev)
{
struct tcm_loop_hba *tl_hba;
struct Scsi_Host *sh;
int error;
tl_hba = to_tcm_loop_hba(dev);
sh = scsi_host_alloc(&tcm_loop_driver_template,
sizeof(struct tcm_loop_hba));
if (!sh) {
printk(KERN_ERR "Unable to allocate struct scsi_host\n");
return -ENODEV;
}
tl_hba->sh = sh;
*((struct tcm_loop_hba **)sh->hostdata) = tl_hba;
sh->max_id = 2;
sh->max_lun = 0;
sh->max_channel = 0;
sh->max_cmd_len = TL_SCSI_MAX_CMD_LEN;
error = scsi_add_host(sh, &tl_hba->dev);
if (error) {
printk(KERN_ERR "%s: scsi_add_host failed\n", __func__);
scsi_host_put(sh);
return -ENODEV;
}
return 0;
}
static int tcm_loop_driver_remove(struct device *dev)
{
struct tcm_loop_hba *tl_hba;
struct Scsi_Host *sh;
tl_hba = to_tcm_loop_hba(dev);
sh = tl_hba->sh;
scsi_remove_host(sh);
scsi_host_put(sh);
return 0;
}
static void tcm_loop_release_adapter(struct device *dev)
{
struct tcm_loop_hba *tl_hba = to_tcm_loop_hba(dev);
kfree(tl_hba);
}
static int tcm_loop_setup_hba_bus(struct tcm_loop_hba *tl_hba, int tcm_loop_host_id)
{
int ret;
tl_hba->dev.bus = &tcm_loop_lld_bus;
tl_hba->dev.parent = tcm_loop_primary;
tl_hba->dev.release = &tcm_loop_release_adapter;
dev_set_name(&tl_hba->dev, "tcm_loop_adapter_%d", tcm_loop_host_id);
ret = device_register(&tl_hba->dev);
if (ret) {
printk(KERN_ERR "device_register() failed for"
" tl_hba->dev: %d\n", ret);
return -ENODEV;
}
return 0;
}
static int tcm_loop_alloc_core_bus(void)
{
int ret;
tcm_loop_primary = root_device_register("tcm_loop_0");
if (IS_ERR(tcm_loop_primary)) {
printk(KERN_ERR "Unable to allocate tcm_loop_primary\n");
return PTR_ERR(tcm_loop_primary);
}
ret = bus_register(&tcm_loop_lld_bus);
if (ret) {
printk(KERN_ERR "bus_register() failed for tcm_loop_lld_bus\n");
goto dev_unreg;
}
ret = driver_register(&tcm_loop_driverfs);
if (ret) {
printk(KERN_ERR "driver_register() failed for"
"tcm_loop_driverfs\n");
goto bus_unreg;
}
printk(KERN_INFO "Initialized TCM Loop Core Bus\n");
return ret;
bus_unreg:
bus_unregister(&tcm_loop_lld_bus);
dev_unreg:
root_device_unregister(tcm_loop_primary);
return ret;
}
static void tcm_loop_release_core_bus(void)
{
driver_unregister(&tcm_loop_driverfs);
bus_unregister(&tcm_loop_lld_bus);
root_device_unregister(tcm_loop_primary);
printk(KERN_INFO "Releasing TCM Loop Core BUS\n");
}
static char *tcm_loop_get_fabric_name(void)
{
return "loopback";
}
static u8 tcm_loop_get_fabric_proto_ident(struct se_portal_group *se_tpg)
{
struct tcm_loop_tpg *tl_tpg =
(struct tcm_loop_tpg *)se_tpg->se_tpg_fabric_ptr;
struct tcm_loop_hba *tl_hba = tl_tpg->tl_hba;
switch (tl_hba->tl_proto_id) {
case SCSI_PROTOCOL_SAS:
return sas_get_fabric_proto_ident(se_tpg);
case SCSI_PROTOCOL_FCP:
return fc_get_fabric_proto_ident(se_tpg);
case SCSI_PROTOCOL_ISCSI:
return iscsi_get_fabric_proto_ident(se_tpg);
default:
printk(KERN_ERR "Unknown tl_proto_id: 0x%02x, using"
" SAS emulation\n", tl_hba->tl_proto_id);
break;
}
return sas_get_fabric_proto_ident(se_tpg);
}
static char *tcm_loop_get_endpoint_wwn(struct se_portal_group *se_tpg)
{
struct tcm_loop_tpg *tl_tpg =
(struct tcm_loop_tpg *)se_tpg->se_tpg_fabric_ptr;
return &tl_tpg->tl_hba->tl_wwn_address[0];
}
static u16 tcm_loop_get_tag(struct se_portal_group *se_tpg)
{
struct tcm_loop_tpg *tl_tpg =
(struct tcm_loop_tpg *)se_tpg->se_tpg_fabric_ptr;
return tl_tpg->tl_tpgt;
}
static u32 tcm_loop_get_default_depth(struct se_portal_group *se_tpg)
{
return 1;
}
static u32 tcm_loop_get_pr_transport_id(
struct se_portal_group *se_tpg,
struct se_node_acl *se_nacl,
struct t10_pr_registration *pr_reg,
int *format_code,
unsigned char *buf)
{
struct tcm_loop_tpg *tl_tpg =
(struct tcm_loop_tpg *)se_tpg->se_tpg_fabric_ptr;
struct tcm_loop_hba *tl_hba = tl_tpg->tl_hba;
switch (tl_hba->tl_proto_id) {
case SCSI_PROTOCOL_SAS:
return sas_get_pr_transport_id(se_tpg, se_nacl, pr_reg,
format_code, buf);
case SCSI_PROTOCOL_FCP:
return fc_get_pr_transport_id(se_tpg, se_nacl, pr_reg,
format_code, buf);
case SCSI_PROTOCOL_ISCSI:
return iscsi_get_pr_transport_id(se_tpg, se_nacl, pr_reg,
format_code, buf);
default:
printk(KERN_ERR "Unknown tl_proto_id: 0x%02x, using"
" SAS emulation\n", tl_hba->tl_proto_id);
break;
}
return sas_get_pr_transport_id(se_tpg, se_nacl, pr_reg,
format_code, buf);
}
static u32 tcm_loop_get_pr_transport_id_len(
struct se_portal_group *se_tpg,
struct se_node_acl *se_nacl,
struct t10_pr_registration *pr_reg,
int *format_code)
{
struct tcm_loop_tpg *tl_tpg =
(struct tcm_loop_tpg *)se_tpg->se_tpg_fabric_ptr;
struct tcm_loop_hba *tl_hba = tl_tpg->tl_hba;
switch (tl_hba->tl_proto_id) {
case SCSI_PROTOCOL_SAS:
return sas_get_pr_transport_id_len(se_tpg, se_nacl, pr_reg,
format_code);
case SCSI_PROTOCOL_FCP:
return fc_get_pr_transport_id_len(se_tpg, se_nacl, pr_reg,
format_code);
case SCSI_PROTOCOL_ISCSI:
return iscsi_get_pr_transport_id_len(se_tpg, se_nacl, pr_reg,
format_code);
default:
printk(KERN_ERR "Unknown tl_proto_id: 0x%02x, using"
" SAS emulation\n", tl_hba->tl_proto_id);
break;
}
return sas_get_pr_transport_id_len(se_tpg, se_nacl, pr_reg,
format_code);
}
static char *tcm_loop_parse_pr_out_transport_id(
struct se_portal_group *se_tpg,
const char *buf,
u32 *out_tid_len,
char **port_nexus_ptr)
{
struct tcm_loop_tpg *tl_tpg =
(struct tcm_loop_tpg *)se_tpg->se_tpg_fabric_ptr;
struct tcm_loop_hba *tl_hba = tl_tpg->tl_hba;
switch (tl_hba->tl_proto_id) {
case SCSI_PROTOCOL_SAS:
return sas_parse_pr_out_transport_id(se_tpg, buf, out_tid_len,
port_nexus_ptr);
case SCSI_PROTOCOL_FCP:
return fc_parse_pr_out_transport_id(se_tpg, buf, out_tid_len,
port_nexus_ptr);
case SCSI_PROTOCOL_ISCSI:
return iscsi_parse_pr_out_transport_id(se_tpg, buf, out_tid_len,
port_nexus_ptr);
default:
printk(KERN_ERR "Unknown tl_proto_id: 0x%02x, using"
" SAS emulation\n", tl_hba->tl_proto_id);
break;
}
return sas_parse_pr_out_transport_id(se_tpg, buf, out_tid_len,
port_nexus_ptr);
}
static int tcm_loop_check_demo_mode(struct se_portal_group *se_tpg)
{
return 1;
}
static int tcm_loop_check_demo_mode_cache(struct se_portal_group *se_tpg)
{
return 0;
}
static int tcm_loop_check_demo_mode_write_protect(struct se_portal_group *se_tpg)
{
return 0;
}
static int tcm_loop_check_prod_mode_write_protect(struct se_portal_group *se_tpg)
{
return 0;
}
static struct se_node_acl *tcm_loop_tpg_alloc_fabric_acl(
struct se_portal_group *se_tpg)
{
struct tcm_loop_nacl *tl_nacl;
tl_nacl = kzalloc(sizeof(struct tcm_loop_nacl), GFP_KERNEL);
if (!tl_nacl) {
printk(KERN_ERR "Unable to allocate struct tcm_loop_nacl\n");
return NULL;
}
return &tl_nacl->se_node_acl;
}
static void tcm_loop_tpg_release_fabric_acl(
struct se_portal_group *se_tpg,
struct se_node_acl *se_nacl)
{
struct tcm_loop_nacl *tl_nacl = container_of(se_nacl,
struct tcm_loop_nacl, se_node_acl);
kfree(tl_nacl);
}
static u32 tcm_loop_get_inst_index(struct se_portal_group *se_tpg)
{
return 1;
}
static void tcm_loop_new_cmd_failure(struct se_cmd *se_cmd)
{
return;
}
static int tcm_loop_is_state_remove(struct se_cmd *se_cmd)
{
return 0;
}
static int tcm_loop_sess_logged_in(struct se_session *se_sess)
{
return 1;
}
static u32 tcm_loop_sess_get_index(struct se_session *se_sess)
{
return 1;
}
static void tcm_loop_set_default_node_attributes(struct se_node_acl *se_acl)
{
return;
}
static u32 tcm_loop_get_task_tag(struct se_cmd *se_cmd)
{
return 1;
}
static int tcm_loop_get_cmd_state(struct se_cmd *se_cmd)
{
struct tcm_loop_cmd *tl_cmd = container_of(se_cmd,
struct tcm_loop_cmd, tl_se_cmd);
return tl_cmd->sc_cmd_state;
}
static int tcm_loop_shutdown_session(struct se_session *se_sess)
{
return 0;
}
static void tcm_loop_close_session(struct se_session *se_sess)
{
return;
}
static void tcm_loop_stop_session(
struct se_session *se_sess,
int sess_sleep,
int conn_sleep)
{
return;
}
static void tcm_loop_fall_back_to_erl0(struct se_session *se_sess)
{
return;
}
static int tcm_loop_write_pending(struct se_cmd *se_cmd)
{
transport_generic_process_write(se_cmd);
return 0;
}
static int tcm_loop_write_pending_status(struct se_cmd *se_cmd)
{
return 0;
}
static int tcm_loop_queue_data_in(struct se_cmd *se_cmd)
{
struct tcm_loop_cmd *tl_cmd = container_of(se_cmd,
struct tcm_loop_cmd, tl_se_cmd);
struct scsi_cmnd *sc = tl_cmd->sc;
TL_CDB_DEBUG("tcm_loop_queue_data_in() called for scsi_cmnd: %p"
" cdb: 0x%02x\n", sc, sc->cmnd[0]);
sc->result = SAM_STAT_GOOD;
set_host_byte(sc, DID_OK);
sc->scsi_done(sc);
return 0;
}
static int tcm_loop_queue_status(struct se_cmd *se_cmd)
{
struct tcm_loop_cmd *tl_cmd = container_of(se_cmd,
struct tcm_loop_cmd, tl_se_cmd);
struct scsi_cmnd *sc = tl_cmd->sc;
TL_CDB_DEBUG("tcm_loop_queue_status() called for scsi_cmnd: %p"
" cdb: 0x%02x\n", sc, sc->cmnd[0]);
if (se_cmd->sense_buffer &&
((se_cmd->se_cmd_flags & SCF_TRANSPORT_TASK_SENSE) ||
(se_cmd->se_cmd_flags & SCF_EMULATED_TASK_SENSE))) {
memcpy((void *)sc->sense_buffer, (void *)se_cmd->sense_buffer,
SCSI_SENSE_BUFFERSIZE);
sc->result = SAM_STAT_CHECK_CONDITION;
set_driver_byte(sc, DRIVER_SENSE);
} else
sc->result = se_cmd->scsi_status;
set_host_byte(sc, DID_OK);
sc->scsi_done(sc);
return 0;
}
static int tcm_loop_queue_tm_rsp(struct se_cmd *se_cmd)
{
struct se_tmr_req *se_tmr = se_cmd->se_tmr_req;
struct tcm_loop_tmr *tl_tmr = se_tmr->fabric_tmr_ptr;
atomic_set(&tl_tmr->tmr_complete, 1);
wake_up(&tl_tmr->tl_tmr_wait);
return 0;
}
static u16 tcm_loop_set_fabric_sense_len(struct se_cmd *se_cmd, u32 sense_length)
{
return 0;
}
static u16 tcm_loop_get_fabric_sense_len(void)
{
return 0;
}
static char *tcm_loop_dump_proto_id(struct tcm_loop_hba *tl_hba)
{
switch (tl_hba->tl_proto_id) {
case SCSI_PROTOCOL_SAS:
return "SAS";
case SCSI_PROTOCOL_FCP:
return "FCP";
case SCSI_PROTOCOL_ISCSI:
return "iSCSI";
default:
break;
}
return "Unknown";
}
static int tcm_loop_port_link(
struct se_portal_group *se_tpg,
struct se_lun *lun)
{
struct tcm_loop_tpg *tl_tpg = container_of(se_tpg,
struct tcm_loop_tpg, tl_se_tpg);
struct tcm_loop_hba *tl_hba = tl_tpg->tl_hba;
atomic_inc(&tl_tpg->tl_tpg_port_count);
smp_mb__after_atomic_inc();
scsi_add_device(tl_hba->sh, 0, tl_tpg->tl_tpgt, lun->unpacked_lun);
printk(KERN_INFO "TCM_Loop_ConfigFS: Port Link Successful\n");
return 0;
}
static void tcm_loop_port_unlink(
struct se_portal_group *se_tpg,
struct se_lun *se_lun)
{
struct scsi_device *sd;
struct tcm_loop_hba *tl_hba;
struct tcm_loop_tpg *tl_tpg;
tl_tpg = container_of(se_tpg, struct tcm_loop_tpg, tl_se_tpg);
tl_hba = tl_tpg->tl_hba;
sd = scsi_device_lookup(tl_hba->sh, 0, tl_tpg->tl_tpgt,
se_lun->unpacked_lun);
if (!sd) {
printk(KERN_ERR "Unable to locate struct scsi_device for %d:%d:"
"%d\n", 0, tl_tpg->tl_tpgt, se_lun->unpacked_lun);
return;
}
scsi_remove_device(sd);
scsi_device_put(sd);
atomic_dec(&tl_tpg->tl_tpg_port_count);
smp_mb__after_atomic_dec();
printk(KERN_INFO "TCM_Loop_ConfigFS: Port Unlink Successful\n");
}
static int tcm_loop_make_nexus(
struct tcm_loop_tpg *tl_tpg,
const char *name)
{
struct se_portal_group *se_tpg;
struct tcm_loop_hba *tl_hba = tl_tpg->tl_hba;
struct tcm_loop_nexus *tl_nexus;
int ret = -ENOMEM;
if (tl_tpg->tl_hba->tl_nexus) {
printk(KERN_INFO "tl_tpg->tl_hba->tl_nexus already exists\n");
return -EEXIST;
}
se_tpg = &tl_tpg->tl_se_tpg;
tl_nexus = kzalloc(sizeof(struct tcm_loop_nexus), GFP_KERNEL);
if (!tl_nexus) {
printk(KERN_ERR "Unable to allocate struct tcm_loop_nexus\n");
return -ENOMEM;
}
tl_nexus->se_sess = transport_init_session();
if (IS_ERR(tl_nexus->se_sess)) {
ret = PTR_ERR(tl_nexus->se_sess);
goto out;
}
tl_nexus->se_sess->se_node_acl = core_tpg_check_initiator_node_acl(
se_tpg, (unsigned char *)name);
if (!tl_nexus->se_sess->se_node_acl) {
transport_free_session(tl_nexus->se_sess);
goto out;
}
__transport_register_session(se_tpg, tl_nexus->se_sess->se_node_acl,
tl_nexus->se_sess, (void *)tl_nexus);
tl_tpg->tl_hba->tl_nexus = tl_nexus;
printk(KERN_INFO "TCM_Loop_ConfigFS: Established I_T Nexus to emulated"
" %s Initiator Port: %s\n", tcm_loop_dump_proto_id(tl_hba),
name);
return 0;
out:
kfree(tl_nexus);
return ret;
}
static int tcm_loop_drop_nexus(
struct tcm_loop_tpg *tpg)
{
struct se_session *se_sess;
struct tcm_loop_nexus *tl_nexus;
struct tcm_loop_hba *tl_hba = tpg->tl_hba;
tl_nexus = tpg->tl_hba->tl_nexus;
if (!tl_nexus)
return -ENODEV;
se_sess = tl_nexus->se_sess;
if (!se_sess)
return -ENODEV;
if (atomic_read(&tpg->tl_tpg_port_count)) {
printk(KERN_ERR "Unable to remove TCM_Loop I_T Nexus with"
" active TPG port count: %d\n",
atomic_read(&tpg->tl_tpg_port_count));
return -EPERM;
}
printk(KERN_INFO "TCM_Loop_ConfigFS: Removing I_T Nexus to emulated"
" %s Initiator Port: %s\n", tcm_loop_dump_proto_id(tl_hba),
tl_nexus->se_sess->se_node_acl->initiatorname);
transport_deregister_session(tl_nexus->se_sess);
tpg->tl_hba->tl_nexus = NULL;
kfree(tl_nexus);
return 0;
}
static ssize_t tcm_loop_tpg_show_nexus(
struct se_portal_group *se_tpg,
char *page)
{
struct tcm_loop_tpg *tl_tpg = container_of(se_tpg,
struct tcm_loop_tpg, tl_se_tpg);
struct tcm_loop_nexus *tl_nexus;
ssize_t ret;
tl_nexus = tl_tpg->tl_hba->tl_nexus;
if (!tl_nexus)
return -ENODEV;
ret = snprintf(page, PAGE_SIZE, "%s\n",
tl_nexus->se_sess->se_node_acl->initiatorname);
return ret;
}
static ssize_t tcm_loop_tpg_store_nexus(
struct se_portal_group *se_tpg,
const char *page,
size_t count)
{
struct tcm_loop_tpg *tl_tpg = container_of(se_tpg,
struct tcm_loop_tpg, tl_se_tpg);
struct tcm_loop_hba *tl_hba = tl_tpg->tl_hba;
unsigned char i_port[TL_WWN_ADDR_LEN], *ptr, *port_ptr;
int ret;
if (!strncmp(page, "NULL", 4)) {
ret = tcm_loop_drop_nexus(tl_tpg);
return (!ret) ? count : ret;
}
if (strlen(page) >= TL_WWN_ADDR_LEN) {
printk(KERN_ERR "Emulated NAA Sas Address: %s, exceeds"
" max: %d\n", page, TL_WWN_ADDR_LEN);
return -EINVAL;
}
snprintf(&i_port[0], TL_WWN_ADDR_LEN, "%s", page);
ptr = strstr(i_port, "naa.");
if (ptr) {
if (tl_hba->tl_proto_id != SCSI_PROTOCOL_SAS) {
printk(KERN_ERR "Passed SAS Initiator Port %s does not"
" match target port protoid: %s\n", i_port,
tcm_loop_dump_proto_id(tl_hba));
return -EINVAL;
}
port_ptr = &i_port[0];
goto check_newline;
}
ptr = strstr(i_port, "fc.");
if (ptr) {
if (tl_hba->tl_proto_id != SCSI_PROTOCOL_FCP) {
printk(KERN_ERR "Passed FCP Initiator Port %s does not"
" match target port protoid: %s\n", i_port,
tcm_loop_dump_proto_id(tl_hba));
return -EINVAL;
}
port_ptr = &i_port[3];
goto check_newline;
}
ptr = strstr(i_port, "iqn.");
if (ptr) {
if (tl_hba->tl_proto_id != SCSI_PROTOCOL_ISCSI) {
printk(KERN_ERR "Passed iSCSI Initiator Port %s does not"
" match target port protoid: %s\n", i_port,
tcm_loop_dump_proto_id(tl_hba));
return -EINVAL;
}
port_ptr = &i_port[0];
goto check_newline;
}
printk(KERN_ERR "Unable to locate prefix for emulated Initiator Port:"
" %s\n", i_port);
return -EINVAL;
check_newline:
if (i_port[strlen(i_port)-1] == '\n')
i_port[strlen(i_port)-1] = '\0';
ret = tcm_loop_make_nexus(tl_tpg, port_ptr);
if (ret < 0)
return ret;
return count;
}
struct se_portal_group *tcm_loop_make_naa_tpg(
struct se_wwn *wwn,
struct config_group *group,
const char *name)
{
struct tcm_loop_hba *tl_hba = container_of(wwn,
struct tcm_loop_hba, tl_hba_wwn);
struct tcm_loop_tpg *tl_tpg;
char *tpgt_str, *end_ptr;
int ret;
unsigned short int tpgt;
tpgt_str = strstr(name, "tpgt_");
if (!tpgt_str) {
printk(KERN_ERR "Unable to locate \"tpgt_#\" directory"
" group\n");
return ERR_PTR(-EINVAL);
}
tpgt_str += 5;
tpgt = (unsigned short int) simple_strtoul(tpgt_str, &end_ptr, 0);
if (tpgt > TL_TPGS_PER_HBA) {
printk(KERN_ERR "Passed tpgt: %hu exceeds TL_TPGS_PER_HBA:"
" %u\n", tpgt, TL_TPGS_PER_HBA);
return ERR_PTR(-EINVAL);
}
tl_tpg = &tl_hba->tl_hba_tpgs[tpgt];
tl_tpg->tl_hba = tl_hba;
tl_tpg->tl_tpgt = tpgt;
ret = core_tpg_register(&tcm_loop_fabric_configfs->tf_ops,
wwn, &tl_tpg->tl_se_tpg, (void *)tl_tpg,
TRANSPORT_TPG_TYPE_NORMAL);
if (ret < 0)
return ERR_PTR(-ENOMEM);
printk(KERN_INFO "TCM_Loop_ConfigFS: Allocated Emulated %s"
" Target Port %s,t,0x%04x\n", tcm_loop_dump_proto_id(tl_hba),
config_item_name(&wwn->wwn_group.cg_item), tpgt);
return &tl_tpg->tl_se_tpg;
}
void tcm_loop_drop_naa_tpg(
struct se_portal_group *se_tpg)
{
struct se_wwn *wwn = se_tpg->se_tpg_wwn;
struct tcm_loop_tpg *tl_tpg = container_of(se_tpg,
struct tcm_loop_tpg, tl_se_tpg);
struct tcm_loop_hba *tl_hba;
unsigned short tpgt;
tl_hba = tl_tpg->tl_hba;
tpgt = tl_tpg->tl_tpgt;
tcm_loop_drop_nexus(tl_tpg);
core_tpg_deregister(se_tpg);
printk(KERN_INFO "TCM_Loop_ConfigFS: Deallocated Emulated %s"
" Target Port %s,t,0x%04x\n", tcm_loop_dump_proto_id(tl_hba),
config_item_name(&wwn->wwn_group.cg_item), tpgt);
}
struct se_wwn *tcm_loop_make_scsi_hba(
struct target_fabric_configfs *tf,
struct config_group *group,
const char *name)
{
struct tcm_loop_hba *tl_hba;
struct Scsi_Host *sh;
char *ptr;
int ret, off = 0;
tl_hba = kzalloc(sizeof(struct tcm_loop_hba), GFP_KERNEL);
if (!tl_hba) {
printk(KERN_ERR "Unable to allocate struct tcm_loop_hba\n");
return ERR_PTR(-ENOMEM);
}
ptr = strstr(name, "naa.");
if (ptr) {
tl_hba->tl_proto_id = SCSI_PROTOCOL_SAS;
goto check_len;
}
ptr = strstr(name, "fc.");
if (ptr) {
tl_hba->tl_proto_id = SCSI_PROTOCOL_FCP;
off = 3;
goto check_len;
}
ptr = strstr(name, "iqn.");
if (ptr) {
tl_hba->tl_proto_id = SCSI_PROTOCOL_ISCSI;
goto check_len;
}
printk(KERN_ERR "Unable to locate prefix for emulated Target Port:"
" %s\n", name);
return ERR_PTR(-EINVAL);
check_len:
if (strlen(name) >= TL_WWN_ADDR_LEN) {
printk(KERN_ERR "Emulated NAA %s Address: %s, exceeds"
" max: %d\n", name, tcm_loop_dump_proto_id(tl_hba),
TL_WWN_ADDR_LEN);
kfree(tl_hba);
return ERR_PTR(-EINVAL);
}
snprintf(&tl_hba->tl_wwn_address[0], TL_WWN_ADDR_LEN, "%s", &name[off]);
ret = tcm_loop_setup_hba_bus(tl_hba, tcm_loop_hba_no_cnt);
if (ret)
goto out;
sh = tl_hba->sh;
tcm_loop_hba_no_cnt++;
printk(KERN_INFO "TCM_Loop_ConfigFS: Allocated emulated Target"
" %s Address: %s at Linux/SCSI Host ID: %d\n",
tcm_loop_dump_proto_id(tl_hba), name, sh->host_no);
return &tl_hba->tl_hba_wwn;
out:
kfree(tl_hba);
return ERR_PTR(ret);
}
void tcm_loop_drop_scsi_hba(
struct se_wwn *wwn)
{
struct tcm_loop_hba *tl_hba = container_of(wwn,
struct tcm_loop_hba, tl_hba_wwn);
int host_no = tl_hba->sh->host_no;
device_unregister(&tl_hba->dev);
printk(KERN_INFO "TCM_Loop_ConfigFS: Deallocated emulated Target"
" SAS Address: %s at Linux/SCSI Host ID: %d\n",
config_item_name(&wwn->wwn_group.cg_item), host_no);
}
static ssize_t tcm_loop_wwn_show_attr_version(
struct target_fabric_configfs *tf,
char *page)
{
return sprintf(page, "TCM Loopback Fabric module %s\n", TCM_LOOP_VERSION);
}
static int tcm_loop_register_configfs(void)
{
struct target_fabric_configfs *fabric;
struct config_group *tf_cg;
int ret;
tcm_loop_hba_no_cnt = 0;
fabric = target_fabric_configfs_init(THIS_MODULE, "loopback");
if (!fabric) {
printk(KERN_ERR "tcm_loop_register_configfs() failed!\n");
return -1;
}
fabric->tf_ops.get_fabric_name = &tcm_loop_get_fabric_name;
fabric->tf_ops.get_fabric_proto_ident = &tcm_loop_get_fabric_proto_ident;
fabric->tf_ops.tpg_get_wwn = &tcm_loop_get_endpoint_wwn;
fabric->tf_ops.tpg_get_tag = &tcm_loop_get_tag;
fabric->tf_ops.tpg_get_default_depth = &tcm_loop_get_default_depth;
fabric->tf_ops.tpg_get_pr_transport_id = &tcm_loop_get_pr_transport_id;
fabric->tf_ops.tpg_get_pr_transport_id_len =
&tcm_loop_get_pr_transport_id_len;
fabric->tf_ops.tpg_parse_pr_out_transport_id =
&tcm_loop_parse_pr_out_transport_id;
fabric->tf_ops.tpg_check_demo_mode = &tcm_loop_check_demo_mode;
fabric->tf_ops.tpg_check_demo_mode_cache =
&tcm_loop_check_demo_mode_cache;
fabric->tf_ops.tpg_check_demo_mode_write_protect =
&tcm_loop_check_demo_mode_write_protect;
fabric->tf_ops.tpg_check_prod_mode_write_protect =
&tcm_loop_check_prod_mode_write_protect;
fabric->tf_ops.tpg_alloc_fabric_acl = &tcm_loop_tpg_alloc_fabric_acl;
fabric->tf_ops.tpg_release_fabric_acl =
&tcm_loop_tpg_release_fabric_acl;
fabric->tf_ops.tpg_get_inst_index = &tcm_loop_get_inst_index;
fabric->tf_ops.alloc_cmd_iovecs = NULL;
fabric->tf_ops.new_cmd_map = &tcm_loop_new_cmd_map;
fabric->tf_ops.check_stop_free = &tcm_loop_check_stop_free;
fabric->tf_ops.release_cmd_to_pool = &tcm_loop_deallocate_core_cmd;
fabric->tf_ops.release_cmd_direct = &tcm_loop_deallocate_core_cmd;
fabric->tf_ops.shutdown_session = &tcm_loop_shutdown_session;
fabric->tf_ops.close_session = &tcm_loop_close_session;
fabric->tf_ops.stop_session = &tcm_loop_stop_session;
fabric->tf_ops.fall_back_to_erl0 = &tcm_loop_fall_back_to_erl0;
fabric->tf_ops.sess_logged_in = &tcm_loop_sess_logged_in;
fabric->tf_ops.sess_get_index = &tcm_loop_sess_get_index;
fabric->tf_ops.sess_get_initiator_sid = NULL;
fabric->tf_ops.write_pending = &tcm_loop_write_pending;
fabric->tf_ops.write_pending_status = &tcm_loop_write_pending_status;
fabric->tf_ops.set_default_node_attributes =
&tcm_loop_set_default_node_attributes;
fabric->tf_ops.get_task_tag = &tcm_loop_get_task_tag;
fabric->tf_ops.get_cmd_state = &tcm_loop_get_cmd_state;
fabric->tf_ops.new_cmd_failure = &tcm_loop_new_cmd_failure;
fabric->tf_ops.queue_data_in = &tcm_loop_queue_data_in;
fabric->tf_ops.queue_status = &tcm_loop_queue_status;
fabric->tf_ops.queue_tm_rsp = &tcm_loop_queue_tm_rsp;
fabric->tf_ops.set_fabric_sense_len = &tcm_loop_set_fabric_sense_len;
fabric->tf_ops.get_fabric_sense_len = &tcm_loop_get_fabric_sense_len;
fabric->tf_ops.is_state_remove = &tcm_loop_is_state_remove;
tf_cg = &fabric->tf_group;
fabric->tf_ops.fabric_make_wwn = &tcm_loop_make_scsi_hba;
fabric->tf_ops.fabric_drop_wwn = &tcm_loop_drop_scsi_hba;
fabric->tf_ops.fabric_make_tpg = &tcm_loop_make_naa_tpg;
fabric->tf_ops.fabric_drop_tpg = &tcm_loop_drop_naa_tpg;
fabric->tf_ops.fabric_post_link = &tcm_loop_port_link;
fabric->tf_ops.fabric_pre_unlink = &tcm_loop_port_unlink;
fabric->tf_ops.fabric_make_np = NULL;
fabric->tf_ops.fabric_drop_np = NULL;
TF_CIT_TMPL(fabric)->tfc_wwn_cit.ct_attrs = tcm_loop_wwn_attrs;
TF_CIT_TMPL(fabric)->tfc_tpg_base_cit.ct_attrs = tcm_loop_tpg_attrs;
TF_CIT_TMPL(fabric)->tfc_tpg_attrib_cit.ct_attrs = NULL;
TF_CIT_TMPL(fabric)->tfc_tpg_param_cit.ct_attrs = NULL;
TF_CIT_TMPL(fabric)->tfc_tpg_np_base_cit.ct_attrs = NULL;
ret = target_fabric_configfs_register(fabric);
if (ret < 0) {
printk(KERN_ERR "target_fabric_configfs_register() for"
" TCM_Loop failed!\n");
target_fabric_configfs_free(fabric);
return -1;
}
tcm_loop_fabric_configfs = fabric;
printk(KERN_INFO "TCM_LOOP[0] - Set fabric ->"
" tcm_loop_fabric_configfs\n");
return 0;
}
static void tcm_loop_deregister_configfs(void)
{
if (!tcm_loop_fabric_configfs)
return;
target_fabric_configfs_deregister(tcm_loop_fabric_configfs);
tcm_loop_fabric_configfs = NULL;
printk(KERN_INFO "TCM_LOOP[0] - Cleared"
" tcm_loop_fabric_configfs\n");
}
static int __init tcm_loop_fabric_init(void)
{
int ret;
tcm_loop_cmd_cache = kmem_cache_create("tcm_loop_cmd_cache",
sizeof(struct tcm_loop_cmd),
__alignof__(struct tcm_loop_cmd),
0, NULL);
if (!tcm_loop_cmd_cache) {
printk(KERN_ERR "kmem_cache_create() for"
" tcm_loop_cmd_cache failed\n");
return -ENOMEM;
}
ret = tcm_loop_alloc_core_bus();
if (ret)
return ret;
ret = tcm_loop_register_configfs();
if (ret) {
tcm_loop_release_core_bus();
return ret;
}
return 0;
}
static void __exit tcm_loop_fabric_exit(void)
{
tcm_loop_deregister_configfs();
tcm_loop_release_core_bus();
kmem_cache_destroy(tcm_loop_cmd_cache);
}
