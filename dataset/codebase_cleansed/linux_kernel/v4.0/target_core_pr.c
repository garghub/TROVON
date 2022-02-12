void core_pr_dump_initiator_port(
struct t10_pr_registration *pr_reg,
char *buf,
u32 size)
{
if (!pr_reg->isid_present_at_reg)
buf[0] = '\0';
snprintf(buf, size, ",i,0x%s", pr_reg->pr_reg_isid);
}
static sense_reason_t
target_scsi2_reservation_check(struct se_cmd *cmd)
{
struct se_device *dev = cmd->se_dev;
struct se_session *sess = cmd->se_sess;
switch (cmd->t_task_cdb[0]) {
case INQUIRY:
case RELEASE:
case RELEASE_10:
return 0;
default:
break;
}
if (!dev->dev_reserved_node_acl || !sess)
return 0;
if (dev->dev_reserved_node_acl != sess->se_node_acl)
return TCM_RESERVATION_CONFLICT;
if (dev->dev_reservation_flags & DRF_SPC2_RESERVATIONS_WITH_ISID) {
if (dev->dev_res_bin_isid != sess->sess_bin_isid)
return TCM_RESERVATION_CONFLICT;
}
return 0;
}
static int target_check_scsi2_reservation_conflict(struct se_cmd *cmd)
{
struct se_session *se_sess = cmd->se_sess;
struct se_device *dev = cmd->se_dev;
struct t10_pr_registration *pr_reg;
struct t10_reservation *pr_tmpl = &dev->t10_pr;
int conflict = 0;
pr_reg = core_scsi3_locate_pr_reg(cmd->se_dev, se_sess->se_node_acl,
se_sess);
if (pr_reg) {
if (pr_reg->pr_res_holder) {
core_scsi3_put_pr_reg(pr_reg);
return 1;
}
if ((pr_reg->pr_res_type == PR_TYPE_WRITE_EXCLUSIVE_REGONLY) ||
(pr_reg->pr_res_type == PR_TYPE_EXCLUSIVE_ACCESS_REGONLY) ||
(pr_reg->pr_res_type == PR_TYPE_WRITE_EXCLUSIVE_ALLREG) ||
(pr_reg->pr_res_type == PR_TYPE_EXCLUSIVE_ACCESS_ALLREG)) {
core_scsi3_put_pr_reg(pr_reg);
return 1;
}
core_scsi3_put_pr_reg(pr_reg);
conflict = 1;
} else {
spin_lock(&pr_tmpl->registration_lock);
conflict = (list_empty(&pr_tmpl->registration_list)) ? 0 : 1;
spin_unlock(&pr_tmpl->registration_lock);
}
if (conflict) {
pr_err("Received legacy SPC-2 RESERVE/RELEASE"
" while active SPC-3 registrations exist,"
" returning RESERVATION_CONFLICT\n");
return -EBUSY;
}
return 0;
}
sense_reason_t
target_scsi2_reservation_release(struct se_cmd *cmd)
{
struct se_device *dev = cmd->se_dev;
struct se_session *sess = cmd->se_sess;
struct se_portal_group *tpg;
int rc;
if (!sess || !sess->se_tpg)
goto out;
rc = target_check_scsi2_reservation_conflict(cmd);
if (rc == 1)
goto out;
if (rc < 0)
return TCM_RESERVATION_CONFLICT;
spin_lock(&dev->dev_reservation_lock);
if (!dev->dev_reserved_node_acl || !sess)
goto out_unlock;
if (dev->dev_reserved_node_acl != sess->se_node_acl)
goto out_unlock;
if (dev->dev_res_bin_isid != sess->sess_bin_isid)
goto out_unlock;
dev->dev_reserved_node_acl = NULL;
dev->dev_reservation_flags &= ~DRF_SPC2_RESERVATIONS;
if (dev->dev_reservation_flags & DRF_SPC2_RESERVATIONS_WITH_ISID) {
dev->dev_res_bin_isid = 0;
dev->dev_reservation_flags &= ~DRF_SPC2_RESERVATIONS_WITH_ISID;
}
tpg = sess->se_tpg;
pr_debug("SCSI-2 Released reservation for %s LUN: %u ->"
" MAPPED LUN: %u for %s\n", tpg->se_tpg_tfo->get_fabric_name(),
cmd->se_lun->unpacked_lun, cmd->se_deve->mapped_lun,
sess->se_node_acl->initiatorname);
out_unlock:
spin_unlock(&dev->dev_reservation_lock);
out:
target_complete_cmd(cmd, GOOD);
return 0;
}
sense_reason_t
target_scsi2_reservation_reserve(struct se_cmd *cmd)
{
struct se_device *dev = cmd->se_dev;
struct se_session *sess = cmd->se_sess;
struct se_portal_group *tpg;
sense_reason_t ret = 0;
int rc;
if ((cmd->t_task_cdb[1] & 0x01) &&
(cmd->t_task_cdb[1] & 0x02)) {
pr_err("LongIO and Obselete Bits set, returning"
" ILLEGAL_REQUEST\n");
return TCM_UNSUPPORTED_SCSI_OPCODE;
}
if (!sess || !sess->se_tpg)
goto out;
rc = target_check_scsi2_reservation_conflict(cmd);
if (rc == 1)
goto out;
if (rc < 0)
return TCM_RESERVATION_CONFLICT;
tpg = sess->se_tpg;
spin_lock(&dev->dev_reservation_lock);
if (dev->dev_reserved_node_acl &&
(dev->dev_reserved_node_acl != sess->se_node_acl)) {
pr_err("SCSI-2 RESERVATION CONFLIFT for %s fabric\n",
tpg->se_tpg_tfo->get_fabric_name());
pr_err("Original reserver LUN: %u %s\n",
cmd->se_lun->unpacked_lun,
dev->dev_reserved_node_acl->initiatorname);
pr_err("Current attempt - LUN: %u -> MAPPED LUN: %u"
" from %s \n", cmd->se_lun->unpacked_lun,
cmd->se_deve->mapped_lun,
sess->se_node_acl->initiatorname);
ret = TCM_RESERVATION_CONFLICT;
goto out_unlock;
}
dev->dev_reserved_node_acl = sess->se_node_acl;
dev->dev_reservation_flags |= DRF_SPC2_RESERVATIONS;
if (sess->sess_bin_isid != 0) {
dev->dev_res_bin_isid = sess->sess_bin_isid;
dev->dev_reservation_flags |= DRF_SPC2_RESERVATIONS_WITH_ISID;
}
pr_debug("SCSI-2 Reserved %s LUN: %u -> MAPPED LUN: %u"
" for %s\n", tpg->se_tpg_tfo->get_fabric_name(),
cmd->se_lun->unpacked_lun, cmd->se_deve->mapped_lun,
sess->se_node_acl->initiatorname);
out_unlock:
spin_unlock(&dev->dev_reservation_lock);
out:
if (!ret)
target_complete_cmd(cmd, GOOD);
return ret;
}
static int core_scsi3_pr_seq_non_holder(
struct se_cmd *cmd,
u32 pr_reg_type)
{
unsigned char *cdb = cmd->t_task_cdb;
struct se_dev_entry *se_deve;
struct se_session *se_sess = cmd->se_sess;
int other_cdb = 0, ignore_reg;
int registered_nexus = 0, ret = 1;
int all_reg = 0, reg_only = 0;
int we = 0;
int legacy = 0;
se_deve = se_sess->se_node_acl->device_list[cmd->orig_fe_lun];
ignore_reg = (pr_reg_type & 0x80000000);
if (ignore_reg)
pr_reg_type &= ~0x80000000;
switch (pr_reg_type) {
case PR_TYPE_WRITE_EXCLUSIVE:
we = 1;
case PR_TYPE_EXCLUSIVE_ACCESS:
if ((se_deve->def_pr_registered) && !(ignore_reg))
registered_nexus = 1;
break;
case PR_TYPE_WRITE_EXCLUSIVE_REGONLY:
we = 1;
case PR_TYPE_EXCLUSIVE_ACCESS_REGONLY:
reg_only = 1;
if ((se_deve->def_pr_registered) && !(ignore_reg))
registered_nexus = 1;
break;
case PR_TYPE_WRITE_EXCLUSIVE_ALLREG:
we = 1;
case PR_TYPE_EXCLUSIVE_ACCESS_ALLREG:
all_reg = 1;
if ((se_deve->def_pr_registered) && !(ignore_reg))
registered_nexus = 1;
break;
default:
return -EINVAL;
}
switch (cdb[0]) {
case SECURITY_PROTOCOL_IN:
if (registered_nexus)
return 0;
ret = (we) ? 0 : 1;
break;
case MODE_SENSE:
case MODE_SENSE_10:
case READ_ATTRIBUTE:
case READ_BUFFER:
case RECEIVE_DIAGNOSTIC:
if (legacy) {
ret = 1;
break;
}
if (registered_nexus) {
ret = 0;
break;
}
ret = (we) ? 0 : 1;
break;
case PERSISTENT_RESERVE_OUT:
switch (cdb[1] & 0x1f) {
case PRO_CLEAR:
case PRO_PREEMPT:
case PRO_PREEMPT_AND_ABORT:
ret = (registered_nexus) ? 0 : 1;
break;
case PRO_REGISTER:
case PRO_REGISTER_AND_IGNORE_EXISTING_KEY:
ret = 0;
break;
case PRO_REGISTER_AND_MOVE:
case PRO_RESERVE:
ret = 1;
break;
case PRO_RELEASE:
ret = (registered_nexus) ? 0 : 1;
break;
default:
pr_err("Unknown PERSISTENT_RESERVE_OUT service"
" action: 0x%02x\n", cdb[1] & 0x1f);
return -EINVAL;
}
break;
case RELEASE:
case RELEASE_10:
ret = 0;
break;
case RESERVE:
case RESERVE_10:
ret = 0;
break;
case TEST_UNIT_READY:
ret = (legacy) ? 1 : 0;
break;
case MAINTENANCE_IN:
switch (cdb[1] & 0x1f) {
case MI_MANAGEMENT_PROTOCOL_IN:
if (registered_nexus) {
ret = 0;
break;
}
ret = (we) ? 0 : 1;
break;
case MI_REPORT_SUPPORTED_OPERATION_CODES:
case MI_REPORT_SUPPORTED_TASK_MANAGEMENT_FUNCTIONS:
if (legacy) {
ret = 1;
break;
}
if (registered_nexus) {
ret = 0;
break;
}
ret = (we) ? 0 : 1;
break;
case MI_REPORT_ALIASES:
case MI_REPORT_IDENTIFYING_INFORMATION:
case MI_REPORT_PRIORITY:
case MI_REPORT_TARGET_PGS:
case MI_REPORT_TIMESTAMP:
ret = 0;
break;
default:
pr_err("Unknown MI Service Action: 0x%02x\n",
(cdb[1] & 0x1f));
return -EINVAL;
}
break;
case ACCESS_CONTROL_IN:
case ACCESS_CONTROL_OUT:
case INQUIRY:
case LOG_SENSE:
case SERVICE_ACTION_IN_12:
case REPORT_LUNS:
case REQUEST_SENSE:
case PERSISTENT_RESERVE_IN:
ret = 0;
break;
default:
other_cdb = 1;
break;
}
if (!ret && !other_cdb) {
pr_debug("Allowing explicit CDB: 0x%02x for %s"
" reservation holder\n", cdb[0],
core_scsi3_pr_dump_type(pr_reg_type));
return ret;
}
if (we && !registered_nexus) {
if (cmd->data_direction == DMA_TO_DEVICE) {
pr_debug("%s Conflict for unregistered nexus"
" %s CDB: 0x%02x to %s reservation\n",
transport_dump_cmd_direction(cmd),
se_sess->se_node_acl->initiatorname, cdb[0],
core_scsi3_pr_dump_type(pr_reg_type));
return 1;
} else {
if (!registered_nexus) {
pr_debug("Allowing implicit CDB: 0x%02x"
" for %s reservation on unregistered"
" nexus\n", cdb[0],
core_scsi3_pr_dump_type(pr_reg_type));
}
return 0;
}
} else if ((reg_only) || (all_reg)) {
if (registered_nexus) {
pr_debug("Allowing implicit CDB: 0x%02x for %s"
" reservation\n", cdb[0],
core_scsi3_pr_dump_type(pr_reg_type));
return 0;
}
} else if (we && registered_nexus) {
if (cmd->data_direction == DMA_FROM_DEVICE) {
pr_debug("Allowing READ CDB: 0x%02x for %s"
" reservation\n", cdb[0],
core_scsi3_pr_dump_type(pr_reg_type));
return 0;
}
}
pr_debug("%s Conflict for %sregistered nexus %s CDB: 0x%2x"
" for %s reservation\n", transport_dump_cmd_direction(cmd),
(registered_nexus) ? "" : "un",
se_sess->se_node_acl->initiatorname, cdb[0],
core_scsi3_pr_dump_type(pr_reg_type));
return 1;
}
static sense_reason_t
target_scsi3_pr_reservation_check(struct se_cmd *cmd)
{
struct se_device *dev = cmd->se_dev;
struct se_session *sess = cmd->se_sess;
u32 pr_reg_type;
if (!dev->dev_pr_res_holder)
return 0;
pr_reg_type = dev->dev_pr_res_holder->pr_res_type;
cmd->pr_res_key = dev->dev_pr_res_holder->pr_res_key;
if (dev->dev_pr_res_holder->pr_reg_nacl != sess->se_node_acl)
goto check_nonholder;
if (dev->dev_pr_res_holder->isid_present_at_reg) {
if (dev->dev_pr_res_holder->pr_reg_bin_isid !=
sess->sess_bin_isid) {
pr_reg_type |= 0x80000000;
goto check_nonholder;
}
}
return 0;
check_nonholder:
if (core_scsi3_pr_seq_non_holder(cmd, pr_reg_type))
return TCM_RESERVATION_CONFLICT;
return 0;
}
static u32 core_scsi3_pr_generation(struct se_device *dev)
{
u32 prg;
spin_lock(&dev->dev_reservation_lock);
prg = dev->t10_pr.pr_generation++;
spin_unlock(&dev->dev_reservation_lock);
return prg;
}
static struct t10_pr_registration *__core_scsi3_do_alloc_registration(
struct se_device *dev,
struct se_node_acl *nacl,
struct se_dev_entry *deve,
unsigned char *isid,
u64 sa_res_key,
int all_tg_pt,
int aptpl)
{
struct t10_pr_registration *pr_reg;
pr_reg = kmem_cache_zalloc(t10_pr_reg_cache, GFP_ATOMIC);
if (!pr_reg) {
pr_err("Unable to allocate struct t10_pr_registration\n");
return NULL;
}
INIT_LIST_HEAD(&pr_reg->pr_reg_list);
INIT_LIST_HEAD(&pr_reg->pr_reg_abort_list);
INIT_LIST_HEAD(&pr_reg->pr_reg_aptpl_list);
INIT_LIST_HEAD(&pr_reg->pr_reg_atp_list);
INIT_LIST_HEAD(&pr_reg->pr_reg_atp_mem_list);
atomic_set(&pr_reg->pr_res_holders, 0);
pr_reg->pr_reg_nacl = nacl;
pr_reg->pr_reg_deve = deve;
pr_reg->pr_res_mapped_lun = deve->mapped_lun;
pr_reg->pr_aptpl_target_lun = deve->se_lun->unpacked_lun;
pr_reg->pr_res_key = sa_res_key;
pr_reg->pr_reg_all_tg_pt = all_tg_pt;
pr_reg->pr_reg_aptpl = aptpl;
pr_reg->pr_reg_tg_pt_lun = deve->se_lun;
if (isid != NULL) {
pr_reg->pr_reg_bin_isid = get_unaligned_be64(isid);
snprintf(pr_reg->pr_reg_isid, PR_REG_ISID_LEN, "%s", isid);
pr_reg->isid_present_at_reg = 1;
}
return pr_reg;
}
static struct t10_pr_registration *__core_scsi3_alloc_registration(
struct se_device *dev,
struct se_node_acl *nacl,
struct se_dev_entry *deve,
unsigned char *isid,
u64 sa_res_key,
int all_tg_pt,
int aptpl)
{
struct se_dev_entry *deve_tmp;
struct se_node_acl *nacl_tmp;
struct se_port *port, *port_tmp;
struct target_core_fabric_ops *tfo = nacl->se_tpg->se_tpg_tfo;
struct t10_pr_registration *pr_reg, *pr_reg_atp, *pr_reg_tmp, *pr_reg_tmp_safe;
int ret;
pr_reg = __core_scsi3_do_alloc_registration(dev, nacl, deve, isid,
sa_res_key, all_tg_pt, aptpl);
if (!pr_reg)
return NULL;
if (!all_tg_pt)
return pr_reg;
spin_lock(&dev->se_port_lock);
list_for_each_entry_safe(port, port_tmp, &dev->dev_sep_list, sep_list) {
atomic_inc_mb(&port->sep_tg_pt_ref_cnt);
spin_unlock(&dev->se_port_lock);
spin_lock_bh(&port->sep_alua_lock);
list_for_each_entry(deve_tmp, &port->sep_alua_list,
alua_port_list) {
if (!deve_tmp->se_lun_acl)
continue;
nacl_tmp = deve_tmp->se_lun_acl->se_lun_nacl;
if (nacl == nacl_tmp)
continue;
if (tfo != nacl_tmp->se_tpg->se_tpg_tfo)
continue;
if (strcmp(nacl->initiatorname, nacl_tmp->initiatorname))
continue;
atomic_inc_mb(&deve_tmp->pr_ref_count);
spin_unlock_bh(&port->sep_alua_lock);
ret = core_scsi3_lunacl_depend_item(deve_tmp);
if (ret < 0) {
pr_err("core_scsi3_lunacl_depend"
"_item() failed\n");
atomic_dec_mb(&port->sep_tg_pt_ref_cnt);
atomic_dec_mb(&deve_tmp->pr_ref_count);
goto out;
}
pr_reg_atp = __core_scsi3_do_alloc_registration(dev,
nacl_tmp, deve_tmp, NULL,
sa_res_key, all_tg_pt, aptpl);
if (!pr_reg_atp) {
atomic_dec_mb(&port->sep_tg_pt_ref_cnt);
atomic_dec_mb(&deve_tmp->pr_ref_count);
core_scsi3_lunacl_undepend_item(deve_tmp);
goto out;
}
list_add_tail(&pr_reg_atp->pr_reg_atp_mem_list,
&pr_reg->pr_reg_atp_list);
spin_lock_bh(&port->sep_alua_lock);
}
spin_unlock_bh(&port->sep_alua_lock);
spin_lock(&dev->se_port_lock);
atomic_dec_mb(&port->sep_tg_pt_ref_cnt);
}
spin_unlock(&dev->se_port_lock);
return pr_reg;
out:
list_for_each_entry_safe(pr_reg_tmp, pr_reg_tmp_safe,
&pr_reg->pr_reg_atp_list, pr_reg_atp_mem_list) {
list_del(&pr_reg_tmp->pr_reg_atp_mem_list);
core_scsi3_lunacl_undepend_item(pr_reg_tmp->pr_reg_deve);
kmem_cache_free(t10_pr_reg_cache, pr_reg_tmp);
}
kmem_cache_free(t10_pr_reg_cache, pr_reg);
return NULL;
}
int core_scsi3_alloc_aptpl_registration(
struct t10_reservation *pr_tmpl,
u64 sa_res_key,
unsigned char *i_port,
unsigned char *isid,
u32 mapped_lun,
unsigned char *t_port,
u16 tpgt,
u32 target_lun,
int res_holder,
int all_tg_pt,
u8 type)
{
struct t10_pr_registration *pr_reg;
if (!i_port || !t_port || !sa_res_key) {
pr_err("Illegal parameters for APTPL registration\n");
return -EINVAL;
}
pr_reg = kmem_cache_zalloc(t10_pr_reg_cache, GFP_KERNEL);
if (!pr_reg) {
pr_err("Unable to allocate struct t10_pr_registration\n");
return -ENOMEM;
}
INIT_LIST_HEAD(&pr_reg->pr_reg_list);
INIT_LIST_HEAD(&pr_reg->pr_reg_abort_list);
INIT_LIST_HEAD(&pr_reg->pr_reg_aptpl_list);
INIT_LIST_HEAD(&pr_reg->pr_reg_atp_list);
INIT_LIST_HEAD(&pr_reg->pr_reg_atp_mem_list);
atomic_set(&pr_reg->pr_res_holders, 0);
pr_reg->pr_reg_nacl = NULL;
pr_reg->pr_reg_deve = NULL;
pr_reg->pr_res_mapped_lun = mapped_lun;
pr_reg->pr_aptpl_target_lun = target_lun;
pr_reg->pr_res_key = sa_res_key;
pr_reg->pr_reg_all_tg_pt = all_tg_pt;
pr_reg->pr_reg_aptpl = 1;
pr_reg->pr_reg_tg_pt_lun = NULL;
pr_reg->pr_res_scope = 0;
pr_reg->pr_res_type = type;
if (isid != NULL) {
pr_reg->pr_reg_bin_isid = get_unaligned_be64(isid);
snprintf(pr_reg->pr_reg_isid, PR_REG_ISID_LEN, "%s", isid);
pr_reg->isid_present_at_reg = 1;
}
snprintf(pr_reg->pr_iport, PR_APTPL_MAX_IPORT_LEN, "%s", i_port);
snprintf(pr_reg->pr_tport, PR_APTPL_MAX_TPORT_LEN, "%s", t_port);
pr_reg->pr_reg_tpgt = tpgt;
pr_reg->pr_res_holder = res_holder;
list_add_tail(&pr_reg->pr_reg_aptpl_list, &pr_tmpl->aptpl_reg_list);
pr_debug("SPC-3 PR APTPL Successfully added registration%s from"
" metadata\n", (res_holder) ? "+reservation" : "");
return 0;
}
static void core_scsi3_aptpl_reserve(
struct se_device *dev,
struct se_portal_group *tpg,
struct se_node_acl *node_acl,
struct t10_pr_registration *pr_reg)
{
char i_buf[PR_REG_ISID_ID_LEN];
memset(i_buf, 0, PR_REG_ISID_ID_LEN);
core_pr_dump_initiator_port(pr_reg, i_buf, PR_REG_ISID_ID_LEN);
spin_lock(&dev->dev_reservation_lock);
dev->dev_pr_res_holder = pr_reg;
spin_unlock(&dev->dev_reservation_lock);
pr_debug("SPC-3 PR [%s] Service Action: APTPL RESERVE created"
" new reservation holder TYPE: %s ALL_TG_PT: %d\n",
tpg->se_tpg_tfo->get_fabric_name(),
core_scsi3_pr_dump_type(pr_reg->pr_res_type),
(pr_reg->pr_reg_all_tg_pt) ? 1 : 0);
pr_debug("SPC-3 PR [%s] RESERVE Node: %s%s\n",
tpg->se_tpg_tfo->get_fabric_name(), node_acl->initiatorname,
i_buf);
}
static int __core_scsi3_check_aptpl_registration(
struct se_device *dev,
struct se_portal_group *tpg,
struct se_lun *lun,
u32 target_lun,
struct se_node_acl *nacl,
struct se_dev_entry *deve)
{
struct t10_pr_registration *pr_reg, *pr_reg_tmp;
struct t10_reservation *pr_tmpl = &dev->t10_pr;
unsigned char i_port[PR_APTPL_MAX_IPORT_LEN];
unsigned char t_port[PR_APTPL_MAX_TPORT_LEN];
u16 tpgt;
memset(i_port, 0, PR_APTPL_MAX_IPORT_LEN);
memset(t_port, 0, PR_APTPL_MAX_TPORT_LEN);
snprintf(i_port, PR_APTPL_MAX_IPORT_LEN, "%s", nacl->initiatorname);
snprintf(t_port, PR_APTPL_MAX_TPORT_LEN, "%s",
tpg->se_tpg_tfo->tpg_get_wwn(tpg));
tpgt = tpg->se_tpg_tfo->tpg_get_tag(tpg);
spin_lock(&pr_tmpl->aptpl_reg_lock);
list_for_each_entry_safe(pr_reg, pr_reg_tmp, &pr_tmpl->aptpl_reg_list,
pr_reg_aptpl_list) {
if (!strcmp(pr_reg->pr_iport, i_port) &&
(pr_reg->pr_res_mapped_lun == deve->mapped_lun) &&
!(strcmp(pr_reg->pr_tport, t_port)) &&
(pr_reg->pr_reg_tpgt == tpgt) &&
(pr_reg->pr_aptpl_target_lun == target_lun)) {
pr_reg->pr_reg_nacl = nacl;
pr_reg->pr_reg_deve = deve;
pr_reg->pr_reg_tg_pt_lun = lun;
list_del(&pr_reg->pr_reg_aptpl_list);
spin_unlock(&pr_tmpl->aptpl_reg_lock);
__core_scsi3_add_registration(dev, nacl, pr_reg, 0, 0);
if (pr_reg->pr_res_holder)
core_scsi3_aptpl_reserve(dev, tpg,
nacl, pr_reg);
spin_lock(&pr_tmpl->aptpl_reg_lock);
pr_tmpl->pr_aptpl_active = 1;
}
}
spin_unlock(&pr_tmpl->aptpl_reg_lock);
return 0;
}
int core_scsi3_check_aptpl_registration(
struct se_device *dev,
struct se_portal_group *tpg,
struct se_lun *lun,
struct se_node_acl *nacl,
u32 mapped_lun)
{
struct se_dev_entry *deve = nacl->device_list[mapped_lun];
if (dev->dev_reservation_flags & DRF_SPC2_RESERVATIONS)
return 0;
return __core_scsi3_check_aptpl_registration(dev, tpg, lun,
lun->unpacked_lun, nacl, deve);
}
static void __core_scsi3_dump_registration(
struct target_core_fabric_ops *tfo,
struct se_device *dev,
struct se_node_acl *nacl,
struct t10_pr_registration *pr_reg,
enum register_type register_type)
{
struct se_portal_group *se_tpg = nacl->se_tpg;
char i_buf[PR_REG_ISID_ID_LEN];
memset(&i_buf[0], 0, PR_REG_ISID_ID_LEN);
core_pr_dump_initiator_port(pr_reg, i_buf, PR_REG_ISID_ID_LEN);
pr_debug("SPC-3 PR [%s] Service Action: REGISTER%s Initiator"
" Node: %s%s\n", tfo->get_fabric_name(), (register_type == REGISTER_AND_MOVE) ?
"_AND_MOVE" : (register_type == REGISTER_AND_IGNORE_EXISTING_KEY) ?
"_AND_IGNORE_EXISTING_KEY" : "", nacl->initiatorname,
i_buf);
pr_debug("SPC-3 PR [%s] registration on Target Port: %s,0x%04x\n",
tfo->get_fabric_name(), tfo->tpg_get_wwn(se_tpg),
tfo->tpg_get_tag(se_tpg));
pr_debug("SPC-3 PR [%s] for %s TCM Subsystem %s Object Target"
" Port(s)\n", tfo->get_fabric_name(),
(pr_reg->pr_reg_all_tg_pt) ? "ALL" : "SINGLE",
dev->transport->name);
pr_debug("SPC-3 PR [%s] SA Res Key: 0x%016Lx PRgeneration:"
" 0x%08x APTPL: %d\n", tfo->get_fabric_name(),
pr_reg->pr_res_key, pr_reg->pr_res_generation,
pr_reg->pr_reg_aptpl);
}
static void __core_scsi3_add_registration(
struct se_device *dev,
struct se_node_acl *nacl,
struct t10_pr_registration *pr_reg,
enum register_type register_type,
int register_move)
{
struct target_core_fabric_ops *tfo = nacl->se_tpg->se_tpg_tfo;
struct t10_pr_registration *pr_reg_tmp, *pr_reg_tmp_safe;
struct t10_reservation *pr_tmpl = &dev->t10_pr;
pr_reg->pr_res_generation = (register_move) ?
dev->t10_pr.pr_generation++ :
core_scsi3_pr_generation(dev);
spin_lock(&pr_tmpl->registration_lock);
list_add_tail(&pr_reg->pr_reg_list, &pr_tmpl->registration_list);
pr_reg->pr_reg_deve->def_pr_registered = 1;
__core_scsi3_dump_registration(tfo, dev, nacl, pr_reg, register_type);
spin_unlock(&pr_tmpl->registration_lock);
if (!pr_reg->pr_reg_all_tg_pt || register_move)
return;
list_for_each_entry_safe(pr_reg_tmp, pr_reg_tmp_safe,
&pr_reg->pr_reg_atp_list, pr_reg_atp_mem_list) {
list_del(&pr_reg_tmp->pr_reg_atp_mem_list);
pr_reg_tmp->pr_res_generation = core_scsi3_pr_generation(dev);
spin_lock(&pr_tmpl->registration_lock);
list_add_tail(&pr_reg_tmp->pr_reg_list,
&pr_tmpl->registration_list);
pr_reg_tmp->pr_reg_deve->def_pr_registered = 1;
__core_scsi3_dump_registration(tfo, dev,
pr_reg_tmp->pr_reg_nacl, pr_reg_tmp,
register_type);
spin_unlock(&pr_tmpl->registration_lock);
core_scsi3_lunacl_undepend_item(pr_reg_tmp->pr_reg_deve);
}
}
static int core_scsi3_alloc_registration(
struct se_device *dev,
struct se_node_acl *nacl,
struct se_dev_entry *deve,
unsigned char *isid,
u64 sa_res_key,
int all_tg_pt,
int aptpl,
enum register_type register_type,
int register_move)
{
struct t10_pr_registration *pr_reg;
pr_reg = __core_scsi3_alloc_registration(dev, nacl, deve, isid,
sa_res_key, all_tg_pt, aptpl);
if (!pr_reg)
return -EPERM;
__core_scsi3_add_registration(dev, nacl, pr_reg,
register_type, register_move);
return 0;
}
static struct t10_pr_registration *__core_scsi3_locate_pr_reg(
struct se_device *dev,
struct se_node_acl *nacl,
unsigned char *isid)
{
struct t10_reservation *pr_tmpl = &dev->t10_pr;
struct t10_pr_registration *pr_reg, *pr_reg_tmp;
struct se_portal_group *tpg;
spin_lock(&pr_tmpl->registration_lock);
list_for_each_entry_safe(pr_reg, pr_reg_tmp,
&pr_tmpl->registration_list, pr_reg_list) {
if (pr_reg->pr_reg_nacl != nacl)
continue;
tpg = pr_reg->pr_reg_nacl->se_tpg;
if (!pr_reg->isid_present_at_reg) {
if (tpg->se_tpg_tfo->sess_get_initiator_sid != NULL) {
if (dev->dev_attrib.enforce_pr_isids)
continue;
}
atomic_inc_mb(&pr_reg->pr_res_holders);
spin_unlock(&pr_tmpl->registration_lock);
return pr_reg;
}
if (!isid)
continue;
if (strcmp(isid, pr_reg->pr_reg_isid))
continue;
atomic_inc_mb(&pr_reg->pr_res_holders);
spin_unlock(&pr_tmpl->registration_lock);
return pr_reg;
}
spin_unlock(&pr_tmpl->registration_lock);
return NULL;
}
static struct t10_pr_registration *core_scsi3_locate_pr_reg(
struct se_device *dev,
struct se_node_acl *nacl,
struct se_session *sess)
{
struct se_portal_group *tpg = nacl->se_tpg;
unsigned char buf[PR_REG_ISID_LEN], *isid_ptr = NULL;
if (tpg->se_tpg_tfo->sess_get_initiator_sid != NULL) {
memset(&buf[0], 0, PR_REG_ISID_LEN);
tpg->se_tpg_tfo->sess_get_initiator_sid(sess, &buf[0],
PR_REG_ISID_LEN);
isid_ptr = &buf[0];
}
return __core_scsi3_locate_pr_reg(dev, nacl, isid_ptr);
}
static void core_scsi3_put_pr_reg(struct t10_pr_registration *pr_reg)
{
atomic_dec_mb(&pr_reg->pr_res_holders);
}
static int core_scsi3_check_implicit_release(
struct se_device *dev,
struct t10_pr_registration *pr_reg)
{
struct se_node_acl *nacl = pr_reg->pr_reg_nacl;
struct t10_pr_registration *pr_res_holder;
int ret = 0;
spin_lock(&dev->dev_reservation_lock);
pr_res_holder = dev->dev_pr_res_holder;
if (!pr_res_holder) {
spin_unlock(&dev->dev_reservation_lock);
return ret;
}
if (pr_res_holder == pr_reg) {
__core_scsi3_complete_pro_release(dev, nacl, pr_reg, 0, 1);
ret = 1;
} else if (pr_reg->pr_reg_all_tg_pt &&
(!strcmp(pr_res_holder->pr_reg_nacl->initiatorname,
pr_reg->pr_reg_nacl->initiatorname)) &&
(pr_res_holder->pr_res_key == pr_reg->pr_res_key)) {
pr_err("SPC-3 PR: Unable to perform ALL_TG_PT=1"
" UNREGISTER while existing reservation with matching"
" key 0x%016Lx is present from another SCSI Initiator"
" Port\n", pr_reg->pr_res_key);
ret = -EPERM;
}
spin_unlock(&dev->dev_reservation_lock);
return ret;
}
static void __core_scsi3_free_registration(
struct se_device *dev,
struct t10_pr_registration *pr_reg,
struct list_head *preempt_and_abort_list,
int dec_holders)
{
struct target_core_fabric_ops *tfo =
pr_reg->pr_reg_nacl->se_tpg->se_tpg_tfo;
struct t10_reservation *pr_tmpl = &dev->t10_pr;
char i_buf[PR_REG_ISID_ID_LEN];
memset(i_buf, 0, PR_REG_ISID_ID_LEN);
core_pr_dump_initiator_port(pr_reg, i_buf, PR_REG_ISID_ID_LEN);
pr_reg->pr_reg_deve->def_pr_registered = 0;
pr_reg->pr_reg_deve->pr_res_key = 0;
if (!list_empty(&pr_reg->pr_reg_list))
list_del(&pr_reg->pr_reg_list);
if (dec_holders)
core_scsi3_put_pr_reg(pr_reg);
while (atomic_read(&pr_reg->pr_res_holders) != 0) {
spin_unlock(&pr_tmpl->registration_lock);
pr_debug("SPC-3 PR [%s] waiting for pr_res_holders\n",
tfo->get_fabric_name());
cpu_relax();
spin_lock(&pr_tmpl->registration_lock);
}
pr_debug("SPC-3 PR [%s] Service Action: UNREGISTER Initiator"
" Node: %s%s\n", tfo->get_fabric_name(),
pr_reg->pr_reg_nacl->initiatorname,
i_buf);
pr_debug("SPC-3 PR [%s] for %s TCM Subsystem %s Object Target"
" Port(s)\n", tfo->get_fabric_name(),
(pr_reg->pr_reg_all_tg_pt) ? "ALL" : "SINGLE",
dev->transport->name);
pr_debug("SPC-3 PR [%s] SA Res Key: 0x%016Lx PRgeneration:"
" 0x%08x\n", tfo->get_fabric_name(), pr_reg->pr_res_key,
pr_reg->pr_res_generation);
if (!preempt_and_abort_list) {
pr_reg->pr_reg_deve = NULL;
pr_reg->pr_reg_nacl = NULL;
kmem_cache_free(t10_pr_reg_cache, pr_reg);
return;
}
list_add_tail(&pr_reg->pr_reg_abort_list, preempt_and_abort_list);
}
void core_scsi3_free_pr_reg_from_nacl(
struct se_device *dev,
struct se_node_acl *nacl)
{
struct t10_reservation *pr_tmpl = &dev->t10_pr;
struct t10_pr_registration *pr_reg, *pr_reg_tmp, *pr_res_holder;
bool free_reg = false;
spin_lock(&dev->dev_reservation_lock);
pr_res_holder = dev->dev_pr_res_holder;
if ((pr_res_holder != NULL) &&
(pr_res_holder->pr_reg_nacl == nacl)) {
__core_scsi3_complete_pro_release(dev, nacl, pr_res_holder, 0, 1);
free_reg = true;
}
spin_unlock(&dev->dev_reservation_lock);
spin_lock(&pr_tmpl->registration_lock);
if (pr_res_holder && free_reg)
__core_scsi3_free_registration(dev, pr_res_holder, NULL, 0);
list_for_each_entry_safe(pr_reg, pr_reg_tmp,
&pr_tmpl->registration_list, pr_reg_list) {
if (pr_reg->pr_reg_nacl != nacl)
continue;
__core_scsi3_free_registration(dev, pr_reg, NULL, 0);
}
spin_unlock(&pr_tmpl->registration_lock);
}
void core_scsi3_free_all_registrations(
struct se_device *dev)
{
struct t10_reservation *pr_tmpl = &dev->t10_pr;
struct t10_pr_registration *pr_reg, *pr_reg_tmp, *pr_res_holder;
spin_lock(&dev->dev_reservation_lock);
pr_res_holder = dev->dev_pr_res_holder;
if (pr_res_holder != NULL) {
struct se_node_acl *pr_res_nacl = pr_res_holder->pr_reg_nacl;
__core_scsi3_complete_pro_release(dev, pr_res_nacl,
pr_res_holder, 0, 0);
}
spin_unlock(&dev->dev_reservation_lock);
spin_lock(&pr_tmpl->registration_lock);
list_for_each_entry_safe(pr_reg, pr_reg_tmp,
&pr_tmpl->registration_list, pr_reg_list) {
__core_scsi3_free_registration(dev, pr_reg, NULL, 0);
}
spin_unlock(&pr_tmpl->registration_lock);
spin_lock(&pr_tmpl->aptpl_reg_lock);
list_for_each_entry_safe(pr_reg, pr_reg_tmp, &pr_tmpl->aptpl_reg_list,
pr_reg_aptpl_list) {
list_del(&pr_reg->pr_reg_aptpl_list);
kmem_cache_free(t10_pr_reg_cache, pr_reg);
}
spin_unlock(&pr_tmpl->aptpl_reg_lock);
}
static int core_scsi3_tpg_depend_item(struct se_portal_group *tpg)
{
return configfs_depend_item(tpg->se_tpg_tfo->tf_subsys,
&tpg->tpg_group.cg_item);
}
static void core_scsi3_tpg_undepend_item(struct se_portal_group *tpg)
{
configfs_undepend_item(tpg->se_tpg_tfo->tf_subsys,
&tpg->tpg_group.cg_item);
atomic_dec_mb(&tpg->tpg_pr_ref_count);
}
static int core_scsi3_nodeacl_depend_item(struct se_node_acl *nacl)
{
struct se_portal_group *tpg = nacl->se_tpg;
if (nacl->dynamic_node_acl)
return 0;
return configfs_depend_item(tpg->se_tpg_tfo->tf_subsys,
&nacl->acl_group.cg_item);
}
static void core_scsi3_nodeacl_undepend_item(struct se_node_acl *nacl)
{
struct se_portal_group *tpg = nacl->se_tpg;
if (nacl->dynamic_node_acl) {
atomic_dec_mb(&nacl->acl_pr_ref_count);
return;
}
configfs_undepend_item(tpg->se_tpg_tfo->tf_subsys,
&nacl->acl_group.cg_item);
atomic_dec_mb(&nacl->acl_pr_ref_count);
}
static int core_scsi3_lunacl_depend_item(struct se_dev_entry *se_deve)
{
struct se_lun_acl *lun_acl = se_deve->se_lun_acl;
struct se_node_acl *nacl;
struct se_portal_group *tpg;
if (!lun_acl)
return 0;
nacl = lun_acl->se_lun_nacl;
tpg = nacl->se_tpg;
return configfs_depend_item(tpg->se_tpg_tfo->tf_subsys,
&lun_acl->se_lun_group.cg_item);
}
static void core_scsi3_lunacl_undepend_item(struct se_dev_entry *se_deve)
{
struct se_lun_acl *lun_acl = se_deve->se_lun_acl;
struct se_node_acl *nacl;
struct se_portal_group *tpg;
if (!lun_acl) {
atomic_dec_mb(&se_deve->pr_ref_count);
return;
}
nacl = lun_acl->se_lun_nacl;
tpg = nacl->se_tpg;
configfs_undepend_item(tpg->se_tpg_tfo->tf_subsys,
&lun_acl->se_lun_group.cg_item);
atomic_dec_mb(&se_deve->pr_ref_count);
}
static sense_reason_t
core_scsi3_decode_spec_i_port(
struct se_cmd *cmd,
struct se_portal_group *tpg,
unsigned char *l_isid,
u64 sa_res_key,
int all_tg_pt,
int aptpl)
{
struct se_device *dev = cmd->se_dev;
struct se_port *tmp_port;
struct se_portal_group *dest_tpg = NULL, *tmp_tpg;
struct se_session *se_sess = cmd->se_sess;
struct se_node_acl *dest_node_acl = NULL;
struct se_dev_entry *dest_se_deve = NULL, *local_se_deve;
struct t10_pr_registration *dest_pr_reg, *local_pr_reg, *pr_reg_e;
struct t10_pr_registration *pr_reg_tmp, *pr_reg_tmp_safe;
LIST_HEAD(tid_dest_list);
struct pr_transport_id_holder *tidh_new, *tidh, *tidh_tmp;
struct target_core_fabric_ops *tmp_tf_ops;
unsigned char *buf;
unsigned char *ptr, *i_str = NULL, proto_ident, tmp_proto_ident;
char *iport_ptr = NULL, i_buf[PR_REG_ISID_ID_LEN];
sense_reason_t ret;
u32 tpdl, tid_len = 0;
int dest_local_nexus;
u32 dest_rtpi = 0;
local_se_deve = se_sess->se_node_acl->device_list[cmd->orig_fe_lun];
tidh_new = kzalloc(sizeof(struct pr_transport_id_holder), GFP_KERNEL);
if (!tidh_new) {
pr_err("Unable to allocate tidh_new\n");
return TCM_LOGICAL_UNIT_COMMUNICATION_FAILURE;
}
INIT_LIST_HEAD(&tidh_new->dest_list);
tidh_new->dest_tpg = tpg;
tidh_new->dest_node_acl = se_sess->se_node_acl;
tidh_new->dest_se_deve = local_se_deve;
local_pr_reg = __core_scsi3_alloc_registration(cmd->se_dev,
se_sess->se_node_acl, local_se_deve, l_isid,
sa_res_key, all_tg_pt, aptpl);
if (!local_pr_reg) {
kfree(tidh_new);
return TCM_LOGICAL_UNIT_COMMUNICATION_FAILURE;
}
tidh_new->dest_pr_reg = local_pr_reg;
tidh_new->dest_local_nexus = 1;
list_add_tail(&tidh_new->dest_list, &tid_dest_list);
if (cmd->data_length < 28) {
pr_warn("SPC-PR: Received PR OUT parameter list"
" length too small: %u\n", cmd->data_length);
ret = TCM_INVALID_PARAMETER_LIST;
goto out;
}
buf = transport_kmap_data_sg(cmd);
if (!buf) {
ret = TCM_LOGICAL_UNIT_COMMUNICATION_FAILURE;
goto out;
}
tpdl = (buf[24] & 0xff) << 24;
tpdl |= (buf[25] & 0xff) << 16;
tpdl |= (buf[26] & 0xff) << 8;
tpdl |= buf[27] & 0xff;
if ((tpdl + 28) != cmd->data_length) {
pr_err("SPC-3 PR: Illegal tpdl: %u + 28 byte header"
" does not equal CDB data_length: %u\n", tpdl,
cmd->data_length);
ret = TCM_INVALID_PARAMETER_LIST;
goto out_unmap;
}
ptr = &buf[28];
while (tpdl > 0) {
proto_ident = (ptr[0] & 0x0f);
dest_tpg = NULL;
spin_lock(&dev->se_port_lock);
list_for_each_entry(tmp_port, &dev->dev_sep_list, sep_list) {
tmp_tpg = tmp_port->sep_tpg;
if (!tmp_tpg)
continue;
tmp_tf_ops = tmp_tpg->se_tpg_tfo;
if (!tmp_tf_ops)
continue;
if (!tmp_tf_ops->get_fabric_proto_ident ||
!tmp_tf_ops->tpg_parse_pr_out_transport_id)
continue;
tmp_proto_ident = tmp_tf_ops->get_fabric_proto_ident(tmp_tpg);
if (tmp_proto_ident != proto_ident)
continue;
dest_rtpi = tmp_port->sep_rtpi;
i_str = tmp_tf_ops->tpg_parse_pr_out_transport_id(
tmp_tpg, (const char *)ptr, &tid_len,
&iport_ptr);
if (!i_str)
continue;
atomic_inc_mb(&tmp_tpg->tpg_pr_ref_count);
spin_unlock(&dev->se_port_lock);
if (core_scsi3_tpg_depend_item(tmp_tpg)) {
pr_err(" core_scsi3_tpg_depend_item()"
" for tmp_tpg\n");
atomic_dec_mb(&tmp_tpg->tpg_pr_ref_count);
ret = TCM_LOGICAL_UNIT_COMMUNICATION_FAILURE;
goto out_unmap;
}
spin_lock_irq(&tmp_tpg->acl_node_lock);
dest_node_acl = __core_tpg_get_initiator_node_acl(
tmp_tpg, i_str);
if (dest_node_acl)
atomic_inc_mb(&dest_node_acl->acl_pr_ref_count);
spin_unlock_irq(&tmp_tpg->acl_node_lock);
if (!dest_node_acl) {
core_scsi3_tpg_undepend_item(tmp_tpg);
spin_lock(&dev->se_port_lock);
continue;
}
if (core_scsi3_nodeacl_depend_item(dest_node_acl)) {
pr_err("configfs_depend_item() failed"
" for dest_node_acl->acl_group\n");
atomic_dec_mb(&dest_node_acl->acl_pr_ref_count);
core_scsi3_tpg_undepend_item(tmp_tpg);
ret = TCM_LOGICAL_UNIT_COMMUNICATION_FAILURE;
goto out_unmap;
}
dest_tpg = tmp_tpg;
pr_debug("SPC-3 PR SPEC_I_PT: Located %s Node:"
" %s Port RTPI: %hu\n",
dest_tpg->se_tpg_tfo->get_fabric_name(),
dest_node_acl->initiatorname, dest_rtpi);
spin_lock(&dev->se_port_lock);
break;
}
spin_unlock(&dev->se_port_lock);
if (!dest_tpg) {
pr_err("SPC-3 PR SPEC_I_PT: Unable to locate"
" dest_tpg\n");
ret = TCM_INVALID_PARAMETER_LIST;
goto out_unmap;
}
pr_debug("SPC-3 PR SPEC_I_PT: Got %s data_length: %u tpdl: %u"
" tid_len: %d for %s + %s\n",
dest_tpg->se_tpg_tfo->get_fabric_name(), cmd->data_length,
tpdl, tid_len, i_str, iport_ptr);
if (tid_len > tpdl) {
pr_err("SPC-3 PR SPEC_I_PT: Illegal tid_len:"
" %u for Transport ID: %s\n", tid_len, ptr);
core_scsi3_nodeacl_undepend_item(dest_node_acl);
core_scsi3_tpg_undepend_item(dest_tpg);
ret = TCM_INVALID_PARAMETER_LIST;
goto out_unmap;
}
dest_se_deve = core_get_se_deve_from_rtpi(dest_node_acl,
dest_rtpi);
if (!dest_se_deve) {
pr_err("Unable to locate %s dest_se_deve"
" from destination RTPI: %hu\n",
dest_tpg->se_tpg_tfo->get_fabric_name(),
dest_rtpi);
core_scsi3_nodeacl_undepend_item(dest_node_acl);
core_scsi3_tpg_undepend_item(dest_tpg);
ret = TCM_INVALID_PARAMETER_LIST;
goto out_unmap;
}
if (core_scsi3_lunacl_depend_item(dest_se_deve)) {
pr_err("core_scsi3_lunacl_depend_item()"
" failed\n");
atomic_dec_mb(&dest_se_deve->pr_ref_count);
core_scsi3_nodeacl_undepend_item(dest_node_acl);
core_scsi3_tpg_undepend_item(dest_tpg);
ret = TCM_LOGICAL_UNIT_COMMUNICATION_FAILURE;
goto out_unmap;
}
pr_debug("SPC-3 PR SPEC_I_PT: Located %s Node: %s"
" dest_se_deve mapped_lun: %u\n",
dest_tpg->se_tpg_tfo->get_fabric_name(),
dest_node_acl->initiatorname, dest_se_deve->mapped_lun);
pr_reg_e = __core_scsi3_locate_pr_reg(dev, dest_node_acl,
iport_ptr);
if (pr_reg_e) {
core_scsi3_put_pr_reg(pr_reg_e);
core_scsi3_lunacl_undepend_item(dest_se_deve);
core_scsi3_nodeacl_undepend_item(dest_node_acl);
core_scsi3_tpg_undepend_item(dest_tpg);
ptr += tid_len;
tpdl -= tid_len;
tid_len = 0;
continue;
}
tidh_new = kzalloc(sizeof(struct pr_transport_id_holder),
GFP_KERNEL);
if (!tidh_new) {
pr_err("Unable to allocate tidh_new\n");
core_scsi3_lunacl_undepend_item(dest_se_deve);
core_scsi3_nodeacl_undepend_item(dest_node_acl);
core_scsi3_tpg_undepend_item(dest_tpg);
ret = TCM_LOGICAL_UNIT_COMMUNICATION_FAILURE;
goto out_unmap;
}
INIT_LIST_HEAD(&tidh_new->dest_list);
tidh_new->dest_tpg = dest_tpg;
tidh_new->dest_node_acl = dest_node_acl;
tidh_new->dest_se_deve = dest_se_deve;
dest_pr_reg = __core_scsi3_alloc_registration(cmd->se_dev,
dest_node_acl, dest_se_deve, iport_ptr,
sa_res_key, all_tg_pt, aptpl);
if (!dest_pr_reg) {
core_scsi3_lunacl_undepend_item(dest_se_deve);
core_scsi3_nodeacl_undepend_item(dest_node_acl);
core_scsi3_tpg_undepend_item(dest_tpg);
kfree(tidh_new);
ret = TCM_INVALID_PARAMETER_LIST;
goto out_unmap;
}
tidh_new->dest_pr_reg = dest_pr_reg;
list_add_tail(&tidh_new->dest_list, &tid_dest_list);
ptr += tid_len;
tpdl -= tid_len;
tid_len = 0;
}
transport_kunmap_data_sg(cmd);
list_for_each_entry_safe(tidh, tidh_tmp, &tid_dest_list, dest_list) {
dest_tpg = tidh->dest_tpg;
dest_node_acl = tidh->dest_node_acl;
dest_se_deve = tidh->dest_se_deve;
dest_pr_reg = tidh->dest_pr_reg;
dest_local_nexus = tidh->dest_local_nexus;
list_del(&tidh->dest_list);
kfree(tidh);
memset(i_buf, 0, PR_REG_ISID_ID_LEN);
core_pr_dump_initiator_port(dest_pr_reg, i_buf, PR_REG_ISID_ID_LEN);
__core_scsi3_add_registration(cmd->se_dev, dest_node_acl,
dest_pr_reg, 0, 0);
pr_debug("SPC-3 PR [%s] SPEC_I_PT: Successfully"
" registered Transport ID for Node: %s%s Mapped LUN:"
" %u\n", dest_tpg->se_tpg_tfo->get_fabric_name(),
dest_node_acl->initiatorname, i_buf, dest_se_deve->mapped_lun);
if (dest_local_nexus)
continue;
core_scsi3_lunacl_undepend_item(dest_se_deve);
core_scsi3_nodeacl_undepend_item(dest_node_acl);
core_scsi3_tpg_undepend_item(dest_tpg);
}
return 0;
out_unmap:
transport_kunmap_data_sg(cmd);
out:
list_for_each_entry_safe(tidh, tidh_tmp, &tid_dest_list, dest_list) {
dest_tpg = tidh->dest_tpg;
dest_node_acl = tidh->dest_node_acl;
dest_se_deve = tidh->dest_se_deve;
dest_pr_reg = tidh->dest_pr_reg;
dest_local_nexus = tidh->dest_local_nexus;
list_del(&tidh->dest_list);
kfree(tidh);
list_for_each_entry_safe(pr_reg_tmp, pr_reg_tmp_safe,
&dest_pr_reg->pr_reg_atp_list,
pr_reg_atp_mem_list) {
list_del(&pr_reg_tmp->pr_reg_atp_mem_list);
core_scsi3_lunacl_undepend_item(pr_reg_tmp->pr_reg_deve);
kmem_cache_free(t10_pr_reg_cache, pr_reg_tmp);
}
kmem_cache_free(t10_pr_reg_cache, dest_pr_reg);
if (dest_local_nexus)
continue;
core_scsi3_lunacl_undepend_item(dest_se_deve);
core_scsi3_nodeacl_undepend_item(dest_node_acl);
core_scsi3_tpg_undepend_item(dest_tpg);
}
return ret;
}
static int core_scsi3_update_aptpl_buf(
struct se_device *dev,
unsigned char *buf,
u32 pr_aptpl_buf_len)
{
struct se_lun *lun;
struct se_portal_group *tpg;
struct t10_pr_registration *pr_reg;
unsigned char tmp[512], isid_buf[32];
ssize_t len = 0;
int reg_count = 0;
int ret = 0;
spin_lock(&dev->dev_reservation_lock);
spin_lock(&dev->t10_pr.registration_lock);
list_for_each_entry(pr_reg, &dev->t10_pr.registration_list,
pr_reg_list) {
tmp[0] = '\0';
isid_buf[0] = '\0';
tpg = pr_reg->pr_reg_nacl->se_tpg;
lun = pr_reg->pr_reg_tg_pt_lun;
if (pr_reg->isid_present_at_reg)
snprintf(isid_buf, 32, "initiator_sid=%s\n",
pr_reg->pr_reg_isid);
if (dev->dev_pr_res_holder == pr_reg) {
snprintf(tmp, 512, "PR_REG_START: %d"
"\ninitiator_fabric=%s\n"
"initiator_node=%s\n%s"
"sa_res_key=%llu\n"
"res_holder=1\nres_type=%02x\n"
"res_scope=%02x\nres_all_tg_pt=%d\n"
"mapped_lun=%u\n", reg_count,
tpg->se_tpg_tfo->get_fabric_name(),
pr_reg->pr_reg_nacl->initiatorname, isid_buf,
pr_reg->pr_res_key, pr_reg->pr_res_type,
pr_reg->pr_res_scope, pr_reg->pr_reg_all_tg_pt,
pr_reg->pr_res_mapped_lun);
} else {
snprintf(tmp, 512, "PR_REG_START: %d\n"
"initiator_fabric=%s\ninitiator_node=%s\n%s"
"sa_res_key=%llu\nres_holder=0\n"
"res_all_tg_pt=%d\nmapped_lun=%u\n",
reg_count, tpg->se_tpg_tfo->get_fabric_name(),
pr_reg->pr_reg_nacl->initiatorname, isid_buf,
pr_reg->pr_res_key, pr_reg->pr_reg_all_tg_pt,
pr_reg->pr_res_mapped_lun);
}
if ((len + strlen(tmp) >= pr_aptpl_buf_len)) {
pr_err("Unable to update renaming APTPL metadata,"
" reallocating larger buffer\n");
ret = -EMSGSIZE;
goto out;
}
len += sprintf(buf+len, "%s", tmp);
snprintf(tmp, 512, "target_fabric=%s\ntarget_node=%s\n"
"tpgt=%hu\nport_rtpi=%hu\ntarget_lun=%u\nPR_REG_END:"
" %d\n", tpg->se_tpg_tfo->get_fabric_name(),
tpg->se_tpg_tfo->tpg_get_wwn(tpg),
tpg->se_tpg_tfo->tpg_get_tag(tpg),
lun->lun_sep->sep_rtpi, lun->unpacked_lun, reg_count);
if ((len + strlen(tmp) >= pr_aptpl_buf_len)) {
pr_err("Unable to update renaming APTPL metadata,"
" reallocating larger buffer\n");
ret = -EMSGSIZE;
goto out;
}
len += sprintf(buf+len, "%s", tmp);
reg_count++;
}
if (!reg_count)
len += sprintf(buf+len, "No Registrations or Reservations");
out:
spin_unlock(&dev->t10_pr.registration_lock);
spin_unlock(&dev->dev_reservation_lock);
return ret;
}
static int __core_scsi3_write_aptpl_to_file(
struct se_device *dev,
unsigned char *buf)
{
struct t10_wwn *wwn = &dev->t10_wwn;
struct file *file;
int flags = O_RDWR | O_CREAT | O_TRUNC;
char path[512];
u32 pr_aptpl_buf_len;
int ret;
memset(path, 0, 512);
if (strlen(&wwn->unit_serial[0]) >= 512) {
pr_err("WWN value for struct se_device does not fit"
" into path buffer\n");
return -EMSGSIZE;
}
snprintf(path, 512, "/var/target/pr/aptpl_%s", &wwn->unit_serial[0]);
file = filp_open(path, flags, 0600);
if (IS_ERR(file)) {
pr_err("filp_open(%s) for APTPL metadata"
" failed\n", path);
return PTR_ERR(file);
}
pr_aptpl_buf_len = (strlen(buf) + 1);
ret = kernel_write(file, buf, pr_aptpl_buf_len, 0);
if (ret < 0)
pr_debug("Error writing APTPL metadata file: %s\n", path);
fput(file);
return (ret < 0) ? -EIO : 0;
}
static sense_reason_t core_scsi3_update_and_write_aptpl(struct se_device *dev, bool aptpl)
{
unsigned char *buf;
int rc, len = PR_APTPL_BUF_LEN;
if (!aptpl) {
char *null_buf = "No Registrations or Reservations\n";
rc = __core_scsi3_write_aptpl_to_file(dev, null_buf);
dev->t10_pr.pr_aptpl_active = 0;
pr_debug("SPC-3 PR: Set APTPL Bit Deactivated\n");
if (rc)
return TCM_LOGICAL_UNIT_COMMUNICATION_FAILURE;
return 0;
}
retry:
buf = vzalloc(len);
if (!buf)
return TCM_OUT_OF_RESOURCES;
rc = core_scsi3_update_aptpl_buf(dev, buf, len);
if (rc < 0) {
vfree(buf);
len *= 2;
goto retry;
}
rc = __core_scsi3_write_aptpl_to_file(dev, buf);
if (rc != 0) {
pr_err("SPC-3 PR: Could not update APTPL\n");
vfree(buf);
return TCM_LOGICAL_UNIT_COMMUNICATION_FAILURE;
}
dev->t10_pr.pr_aptpl_active = 1;
vfree(buf);
pr_debug("SPC-3 PR: Set APTPL Bit Activated\n");
return 0;
}
static sense_reason_t
core_scsi3_emulate_pro_register(struct se_cmd *cmd, u64 res_key, u64 sa_res_key,
bool aptpl, bool all_tg_pt, bool spec_i_pt, enum register_type register_type)
{
struct se_session *se_sess = cmd->se_sess;
struct se_device *dev = cmd->se_dev;
struct se_dev_entry *se_deve;
struct se_lun *se_lun = cmd->se_lun;
struct se_portal_group *se_tpg;
struct t10_pr_registration *pr_reg, *pr_reg_p, *pr_reg_tmp;
struct t10_reservation *pr_tmpl = &dev->t10_pr;
unsigned char isid_buf[PR_REG_ISID_LEN], *isid_ptr = NULL;
sense_reason_t ret = TCM_NO_SENSE;
int pr_holder = 0, type;
if (!se_sess || !se_lun) {
pr_err("SPC-3 PR: se_sess || struct se_lun is NULL!\n");
return TCM_LOGICAL_UNIT_COMMUNICATION_FAILURE;
}
se_tpg = se_sess->se_tpg;
se_deve = se_sess->se_node_acl->device_list[cmd->orig_fe_lun];
if (se_tpg->se_tpg_tfo->sess_get_initiator_sid) {
memset(&isid_buf[0], 0, PR_REG_ISID_LEN);
se_tpg->se_tpg_tfo->sess_get_initiator_sid(se_sess, &isid_buf[0],
PR_REG_ISID_LEN);
isid_ptr = &isid_buf[0];
}
pr_reg = core_scsi3_locate_pr_reg(dev, se_sess->se_node_acl, se_sess);
if (!pr_reg) {
if (res_key) {
pr_warn("SPC-3 PR: Reservation Key non-zero"
" for SA REGISTER, returning CONFLICT\n");
return TCM_RESERVATION_CONFLICT;
}
if (!sa_res_key)
return 0;
if (!spec_i_pt) {
if (core_scsi3_alloc_registration(cmd->se_dev,
se_sess->se_node_acl, se_deve, isid_ptr,
sa_res_key, all_tg_pt, aptpl,
register_type, 0)) {
pr_err("Unable to allocate"
" struct t10_pr_registration\n");
return TCM_INVALID_PARAMETER_LIST;
}
} else {
ret = core_scsi3_decode_spec_i_port(cmd, se_tpg,
isid_ptr, sa_res_key, all_tg_pt, aptpl);
if (ret != 0)
return ret;
}
return core_scsi3_update_and_write_aptpl(dev, aptpl);
}
if ((register_type == REGISTER) && (res_key != pr_reg->pr_res_key)) {
pr_err("SPC-3 PR REGISTER: Received"
" res_key: 0x%016Lx does not match"
" existing SA REGISTER res_key:"
" 0x%016Lx\n", res_key,
pr_reg->pr_res_key);
ret = TCM_RESERVATION_CONFLICT;
goto out;
}
if (spec_i_pt) {
pr_err("SPC-3 PR REGISTER: SPEC_I_PT"
" set on a registered nexus\n");
ret = TCM_INVALID_PARAMETER_LIST;
goto out;
}
if (pr_reg->pr_reg_all_tg_pt && !all_tg_pt) {
pr_err("SPC-3 PR REGISTER: ALL_TG_PT=1"
" registration exists, but ALL_TG_PT=1 bit not"
" present in received PROUT\n");
ret = TCM_INVALID_CDB_FIELD;
goto out;
}
if (sa_res_key) {
pr_reg->pr_res_generation = core_scsi3_pr_generation(cmd->se_dev);
pr_reg->pr_res_key = sa_res_key;
pr_debug("SPC-3 PR [%s] REGISTER%s: Changed Reservation"
" Key for %s to: 0x%016Lx PRgeneration:"
" 0x%08x\n", cmd->se_tfo->get_fabric_name(),
(register_type == REGISTER_AND_IGNORE_EXISTING_KEY) ? "_AND_IGNORE_EXISTING_KEY" : "",
pr_reg->pr_reg_nacl->initiatorname,
pr_reg->pr_res_key, pr_reg->pr_res_generation);
} else {
type = pr_reg->pr_res_type;
pr_holder = core_scsi3_check_implicit_release(cmd->se_dev,
pr_reg);
if (pr_holder < 0) {
ret = TCM_RESERVATION_CONFLICT;
goto out;
}
spin_lock(&pr_tmpl->registration_lock);
if (pr_reg->pr_reg_all_tg_pt) {
list_for_each_entry_safe(pr_reg_p, pr_reg_tmp,
&pr_tmpl->registration_list,
pr_reg_list) {
if (!pr_reg_p->pr_reg_all_tg_pt)
continue;
if (pr_reg_p->pr_res_key != res_key)
continue;
if (pr_reg == pr_reg_p)
continue;
if (strcmp(pr_reg->pr_reg_nacl->initiatorname,
pr_reg_p->pr_reg_nacl->initiatorname))
continue;
__core_scsi3_free_registration(dev,
pr_reg_p, NULL, 0);
}
}
__core_scsi3_free_registration(cmd->se_dev, pr_reg, NULL, 1);
pr_reg = NULL;
if (pr_holder &&
(type == PR_TYPE_WRITE_EXCLUSIVE_REGONLY ||
type == PR_TYPE_EXCLUSIVE_ACCESS_REGONLY)) {
list_for_each_entry(pr_reg_p,
&pr_tmpl->registration_list,
pr_reg_list) {
core_scsi3_ua_allocate(
pr_reg_p->pr_reg_nacl,
pr_reg_p->pr_res_mapped_lun,
0x2A,
ASCQ_2AH_RESERVATIONS_RELEASED);
}
}
spin_unlock(&pr_tmpl->registration_lock);
}
ret = core_scsi3_update_and_write_aptpl(dev, aptpl);
out:
if (pr_reg)
core_scsi3_put_pr_reg(pr_reg);
return ret;
}
unsigned char *core_scsi3_pr_dump_type(int type)
{
switch (type) {
case PR_TYPE_WRITE_EXCLUSIVE:
return "Write Exclusive Access";
case PR_TYPE_EXCLUSIVE_ACCESS:
return "Exclusive Access";
case PR_TYPE_WRITE_EXCLUSIVE_REGONLY:
return "Write Exclusive Access, Registrants Only";
case PR_TYPE_EXCLUSIVE_ACCESS_REGONLY:
return "Exclusive Access, Registrants Only";
case PR_TYPE_WRITE_EXCLUSIVE_ALLREG:
return "Write Exclusive Access, All Registrants";
case PR_TYPE_EXCLUSIVE_ACCESS_ALLREG:
return "Exclusive Access, All Registrants";
default:
break;
}
return "Unknown SPC-3 PR Type";
}
static sense_reason_t
core_scsi3_pro_reserve(struct se_cmd *cmd, int type, int scope, u64 res_key)
{
struct se_device *dev = cmd->se_dev;
struct se_session *se_sess = cmd->se_sess;
struct se_lun *se_lun = cmd->se_lun;
struct t10_pr_registration *pr_reg, *pr_res_holder;
struct t10_reservation *pr_tmpl = &dev->t10_pr;
char i_buf[PR_REG_ISID_ID_LEN];
sense_reason_t ret;
memset(i_buf, 0, PR_REG_ISID_ID_LEN);
if (!se_sess || !se_lun) {
pr_err("SPC-3 PR: se_sess || struct se_lun is NULL!\n");
return TCM_LOGICAL_UNIT_COMMUNICATION_FAILURE;
}
pr_reg = core_scsi3_locate_pr_reg(cmd->se_dev, se_sess->se_node_acl,
se_sess);
if (!pr_reg) {
pr_err("SPC-3 PR: Unable to locate"
" PR_REGISTERED *pr_reg for RESERVE\n");
return TCM_LOGICAL_UNIT_COMMUNICATION_FAILURE;
}
if (res_key != pr_reg->pr_res_key) {
pr_err("SPC-3 PR RESERVE: Received res_key: 0x%016Lx"
" does not match existing SA REGISTER res_key:"
" 0x%016Lx\n", res_key, pr_reg->pr_res_key);
ret = TCM_RESERVATION_CONFLICT;
goto out_put_pr_reg;
}
if (scope != PR_SCOPE_LU_SCOPE) {
pr_err("SPC-3 PR: Illegal SCOPE: 0x%02x\n", scope);
ret = TCM_INVALID_PARAMETER_LIST;
goto out_put_pr_reg;
}
spin_lock(&dev->dev_reservation_lock);
pr_res_holder = dev->dev_pr_res_holder;
if (pr_res_holder) {
int pr_res_type = pr_res_holder->pr_res_type;
if ((pr_res_holder != pr_reg) &&
(pr_res_type != PR_TYPE_WRITE_EXCLUSIVE_ALLREG) &&
(pr_res_type != PR_TYPE_EXCLUSIVE_ACCESS_ALLREG)) {
struct se_node_acl *pr_res_nacl = pr_res_holder->pr_reg_nacl;
pr_err("SPC-3 PR: Attempted RESERVE from"
" [%s]: %s while reservation already held by"
" [%s]: %s, returning RESERVATION_CONFLICT\n",
cmd->se_tfo->get_fabric_name(),
se_sess->se_node_acl->initiatorname,
pr_res_nacl->se_tpg->se_tpg_tfo->get_fabric_name(),
pr_res_holder->pr_reg_nacl->initiatorname);
spin_unlock(&dev->dev_reservation_lock);
ret = TCM_RESERVATION_CONFLICT;
goto out_put_pr_reg;
}
if ((pr_res_holder->pr_res_type != type) ||
(pr_res_holder->pr_res_scope != scope)) {
struct se_node_acl *pr_res_nacl = pr_res_holder->pr_reg_nacl;
pr_err("SPC-3 PR: Attempted RESERVE from"
" [%s]: %s trying to change TYPE and/or SCOPE,"
" while reservation already held by [%s]: %s,"
" returning RESERVATION_CONFLICT\n",
cmd->se_tfo->get_fabric_name(),
se_sess->se_node_acl->initiatorname,
pr_res_nacl->se_tpg->se_tpg_tfo->get_fabric_name(),
pr_res_holder->pr_reg_nacl->initiatorname);
spin_unlock(&dev->dev_reservation_lock);
ret = TCM_RESERVATION_CONFLICT;
goto out_put_pr_reg;
}
spin_unlock(&dev->dev_reservation_lock);
ret = 0;
goto out_put_pr_reg;
}
pr_reg->pr_res_scope = scope;
pr_reg->pr_res_type = type;
pr_reg->pr_res_holder = 1;
dev->dev_pr_res_holder = pr_reg;
core_pr_dump_initiator_port(pr_reg, i_buf, PR_REG_ISID_ID_LEN);
pr_debug("SPC-3 PR [%s] Service Action: RESERVE created new"
" reservation holder TYPE: %s ALL_TG_PT: %d\n",
cmd->se_tfo->get_fabric_name(), core_scsi3_pr_dump_type(type),
(pr_reg->pr_reg_all_tg_pt) ? 1 : 0);
pr_debug("SPC-3 PR [%s] RESERVE Node: %s%s\n",
cmd->se_tfo->get_fabric_name(),
se_sess->se_node_acl->initiatorname,
i_buf);
spin_unlock(&dev->dev_reservation_lock);
if (pr_tmpl->pr_aptpl_active)
core_scsi3_update_and_write_aptpl(cmd->se_dev, true);
ret = 0;
out_put_pr_reg:
core_scsi3_put_pr_reg(pr_reg);
return ret;
}
static sense_reason_t
core_scsi3_emulate_pro_reserve(struct se_cmd *cmd, int type, int scope,
u64 res_key)
{
switch (type) {
case PR_TYPE_WRITE_EXCLUSIVE:
case PR_TYPE_EXCLUSIVE_ACCESS:
case PR_TYPE_WRITE_EXCLUSIVE_REGONLY:
case PR_TYPE_EXCLUSIVE_ACCESS_REGONLY:
case PR_TYPE_WRITE_EXCLUSIVE_ALLREG:
case PR_TYPE_EXCLUSIVE_ACCESS_ALLREG:
return core_scsi3_pro_reserve(cmd, type, scope, res_key);
default:
pr_err("SPC-3 PR: Unknown Service Action RESERVE Type:"
" 0x%02x\n", type);
return TCM_INVALID_CDB_FIELD;
}
}
static void __core_scsi3_complete_pro_release(
struct se_device *dev,
struct se_node_acl *se_nacl,
struct t10_pr_registration *pr_reg,
int explicit,
int unreg)
{
struct target_core_fabric_ops *tfo = se_nacl->se_tpg->se_tpg_tfo;
char i_buf[PR_REG_ISID_ID_LEN];
int pr_res_type = 0, pr_res_scope = 0;
memset(i_buf, 0, PR_REG_ISID_ID_LEN);
core_pr_dump_initiator_port(pr_reg, i_buf, PR_REG_ISID_ID_LEN);
if (dev->dev_pr_res_holder) {
pr_res_type = dev->dev_pr_res_holder->pr_res_type;
pr_res_scope = dev->dev_pr_res_holder->pr_res_scope;
dev->dev_pr_res_holder->pr_res_type = 0;
dev->dev_pr_res_holder->pr_res_scope = 0;
dev->dev_pr_res_holder->pr_res_holder = 0;
dev->dev_pr_res_holder = NULL;
}
if (!unreg)
goto out;
spin_lock(&dev->t10_pr.registration_lock);
list_del_init(&pr_reg->pr_reg_list);
if (!list_empty(&dev->t10_pr.registration_list) &&
((pr_res_type == PR_TYPE_WRITE_EXCLUSIVE_ALLREG) ||
(pr_res_type == PR_TYPE_EXCLUSIVE_ACCESS_ALLREG))) {
dev->dev_pr_res_holder =
list_entry(dev->t10_pr.registration_list.next,
struct t10_pr_registration, pr_reg_list);
dev->dev_pr_res_holder->pr_res_type = pr_res_type;
dev->dev_pr_res_holder->pr_res_scope = pr_res_scope;
dev->dev_pr_res_holder->pr_res_holder = 1;
}
spin_unlock(&dev->t10_pr.registration_lock);
out:
if (!dev->dev_pr_res_holder) {
pr_debug("SPC-3 PR [%s] Service Action: %s RELEASE cleared"
" reservation holder TYPE: %s ALL_TG_PT: %d\n",
tfo->get_fabric_name(), (explicit) ? "explicit" :
"implicit", core_scsi3_pr_dump_type(pr_res_type),
(pr_reg->pr_reg_all_tg_pt) ? 1 : 0);
}
pr_debug("SPC-3 PR [%s] RELEASE Node: %s%s\n",
tfo->get_fabric_name(), se_nacl->initiatorname,
i_buf);
pr_reg->pr_res_holder = pr_reg->pr_res_type = pr_reg->pr_res_scope = 0;
}
static sense_reason_t
core_scsi3_emulate_pro_release(struct se_cmd *cmd, int type, int scope,
u64 res_key)
{
struct se_device *dev = cmd->se_dev;
struct se_session *se_sess = cmd->se_sess;
struct se_lun *se_lun = cmd->se_lun;
struct t10_pr_registration *pr_reg, *pr_reg_p, *pr_res_holder;
struct t10_reservation *pr_tmpl = &dev->t10_pr;
int all_reg = 0;
sense_reason_t ret = 0;
if (!se_sess || !se_lun) {
pr_err("SPC-3 PR: se_sess || struct se_lun is NULL!\n");
return TCM_LOGICAL_UNIT_COMMUNICATION_FAILURE;
}
pr_reg = core_scsi3_locate_pr_reg(dev, se_sess->se_node_acl, se_sess);
if (!pr_reg) {
pr_err("SPC-3 PR: Unable to locate"
" PR_REGISTERED *pr_reg for RELEASE\n");
return TCM_LOGICAL_UNIT_COMMUNICATION_FAILURE;
}
spin_lock(&dev->dev_reservation_lock);
pr_res_holder = dev->dev_pr_res_holder;
if (!pr_res_holder) {
spin_unlock(&dev->dev_reservation_lock);
goto out_put_pr_reg;
}
if ((pr_res_holder->pr_res_type == PR_TYPE_WRITE_EXCLUSIVE_ALLREG) ||
(pr_res_holder->pr_res_type == PR_TYPE_EXCLUSIVE_ACCESS_ALLREG))
all_reg = 1;
if ((all_reg == 0) && (pr_res_holder != pr_reg)) {
spin_unlock(&dev->dev_reservation_lock);
goto out_put_pr_reg;
}
if (res_key != pr_reg->pr_res_key) {
pr_err("SPC-3 PR RELEASE: Received res_key: 0x%016Lx"
" does not match existing SA REGISTER res_key:"
" 0x%016Lx\n", res_key, pr_reg->pr_res_key);
spin_unlock(&dev->dev_reservation_lock);
ret = TCM_RESERVATION_CONFLICT;
goto out_put_pr_reg;
}
if ((pr_res_holder->pr_res_type != type) ||
(pr_res_holder->pr_res_scope != scope)) {
struct se_node_acl *pr_res_nacl = pr_res_holder->pr_reg_nacl;
pr_err("SPC-3 PR RELEASE: Attempted to release"
" reservation from [%s]: %s with different TYPE "
"and/or SCOPE while reservation already held by"
" [%s]: %s, returning RESERVATION_CONFLICT\n",
cmd->se_tfo->get_fabric_name(),
se_sess->se_node_acl->initiatorname,
pr_res_nacl->se_tpg->se_tpg_tfo->get_fabric_name(),
pr_res_holder->pr_reg_nacl->initiatorname);
spin_unlock(&dev->dev_reservation_lock);
ret = TCM_RESERVATION_CONFLICT;
goto out_put_pr_reg;
}
__core_scsi3_complete_pro_release(dev, se_sess->se_node_acl,
pr_reg, 1, 0);
spin_unlock(&dev->dev_reservation_lock);
if ((type != PR_TYPE_WRITE_EXCLUSIVE_REGONLY) &&
(type != PR_TYPE_EXCLUSIVE_ACCESS_REGONLY) &&
(type != PR_TYPE_WRITE_EXCLUSIVE_ALLREG) &&
(type != PR_TYPE_EXCLUSIVE_ACCESS_ALLREG)) {
goto write_aptpl;
}
spin_lock(&pr_tmpl->registration_lock);
list_for_each_entry(pr_reg_p, &pr_tmpl->registration_list,
pr_reg_list) {
if (pr_reg_p == pr_reg)
continue;
core_scsi3_ua_allocate(pr_reg_p->pr_reg_nacl,
pr_reg_p->pr_res_mapped_lun,
0x2A, ASCQ_2AH_RESERVATIONS_RELEASED);
}
spin_unlock(&pr_tmpl->registration_lock);
write_aptpl:
if (pr_tmpl->pr_aptpl_active)
core_scsi3_update_and_write_aptpl(cmd->se_dev, true);
out_put_pr_reg:
core_scsi3_put_pr_reg(pr_reg);
return ret;
}
static sense_reason_t
core_scsi3_emulate_pro_clear(struct se_cmd *cmd, u64 res_key)
{
struct se_device *dev = cmd->se_dev;
struct se_node_acl *pr_reg_nacl;
struct se_session *se_sess = cmd->se_sess;
struct t10_reservation *pr_tmpl = &dev->t10_pr;
struct t10_pr_registration *pr_reg, *pr_reg_tmp, *pr_reg_n, *pr_res_holder;
u32 pr_res_mapped_lun = 0;
int calling_it_nexus = 0;
pr_reg_n = core_scsi3_locate_pr_reg(cmd->se_dev,
se_sess->se_node_acl, se_sess);
if (!pr_reg_n) {
pr_err("SPC-3 PR: Unable to locate"
" PR_REGISTERED *pr_reg for CLEAR\n");
return TCM_LOGICAL_UNIT_COMMUNICATION_FAILURE;
}
if (res_key != pr_reg_n->pr_res_key) {
pr_err("SPC-3 PR REGISTER: Received"
" res_key: 0x%016Lx does not match"
" existing SA REGISTER res_key:"
" 0x%016Lx\n", res_key, pr_reg_n->pr_res_key);
core_scsi3_put_pr_reg(pr_reg_n);
return TCM_RESERVATION_CONFLICT;
}
spin_lock(&dev->dev_reservation_lock);
pr_res_holder = dev->dev_pr_res_holder;
if (pr_res_holder) {
struct se_node_acl *pr_res_nacl = pr_res_holder->pr_reg_nacl;
__core_scsi3_complete_pro_release(dev, pr_res_nacl,
pr_res_holder, 0, 0);
}
spin_unlock(&dev->dev_reservation_lock);
spin_lock(&pr_tmpl->registration_lock);
list_for_each_entry_safe(pr_reg, pr_reg_tmp,
&pr_tmpl->registration_list, pr_reg_list) {
calling_it_nexus = (pr_reg_n == pr_reg) ? 1 : 0;
pr_reg_nacl = pr_reg->pr_reg_nacl;
pr_res_mapped_lun = pr_reg->pr_res_mapped_lun;
__core_scsi3_free_registration(dev, pr_reg, NULL,
calling_it_nexus);
if (!calling_it_nexus)
core_scsi3_ua_allocate(pr_reg_nacl, pr_res_mapped_lun,
0x2A, ASCQ_2AH_RESERVATIONS_PREEMPTED);
}
spin_unlock(&pr_tmpl->registration_lock);
pr_debug("SPC-3 PR [%s] Service Action: CLEAR complete\n",
cmd->se_tfo->get_fabric_name());
core_scsi3_update_and_write_aptpl(cmd->se_dev, false);
core_scsi3_pr_generation(dev);
return 0;
}
static void __core_scsi3_complete_pro_preempt(
struct se_device *dev,
struct t10_pr_registration *pr_reg,
struct list_head *preempt_and_abort_list,
int type,
int scope,
enum preempt_type preempt_type)
{
struct se_node_acl *nacl = pr_reg->pr_reg_nacl;
struct target_core_fabric_ops *tfo = nacl->se_tpg->se_tpg_tfo;
char i_buf[PR_REG_ISID_ID_LEN];
memset(i_buf, 0, PR_REG_ISID_ID_LEN);
core_pr_dump_initiator_port(pr_reg, i_buf, PR_REG_ISID_ID_LEN);
if (dev->dev_pr_res_holder)
__core_scsi3_complete_pro_release(dev, nacl,
dev->dev_pr_res_holder, 0, 0);
dev->dev_pr_res_holder = pr_reg;
pr_reg->pr_res_holder = 1;
pr_reg->pr_res_type = type;
pr_reg->pr_res_scope = scope;
pr_debug("SPC-3 PR [%s] Service Action: PREEMPT%s created new"
" reservation holder TYPE: %s ALL_TG_PT: %d\n",
tfo->get_fabric_name(), (preempt_type == PREEMPT_AND_ABORT) ? "_AND_ABORT" : "",
core_scsi3_pr_dump_type(type),
(pr_reg->pr_reg_all_tg_pt) ? 1 : 0);
pr_debug("SPC-3 PR [%s] PREEMPT%s from Node: %s%s\n",
tfo->get_fabric_name(), (preempt_type == PREEMPT_AND_ABORT) ? "_AND_ABORT" : "",
nacl->initiatorname, i_buf);
if (preempt_and_abort_list)
list_add_tail(&pr_reg->pr_reg_abort_list,
preempt_and_abort_list);
}
static void core_scsi3_release_preempt_and_abort(
struct list_head *preempt_and_abort_list,
struct t10_pr_registration *pr_reg_holder)
{
struct t10_pr_registration *pr_reg, *pr_reg_tmp;
list_for_each_entry_safe(pr_reg, pr_reg_tmp, preempt_and_abort_list,
pr_reg_abort_list) {
list_del(&pr_reg->pr_reg_abort_list);
if (pr_reg_holder == pr_reg)
continue;
if (pr_reg->pr_res_holder) {
pr_warn("pr_reg->pr_res_holder still set\n");
continue;
}
pr_reg->pr_reg_deve = NULL;
pr_reg->pr_reg_nacl = NULL;
kmem_cache_free(t10_pr_reg_cache, pr_reg);
}
}
static sense_reason_t
core_scsi3_pro_preempt(struct se_cmd *cmd, int type, int scope, u64 res_key,
u64 sa_res_key, enum preempt_type preempt_type)
{
struct se_device *dev = cmd->se_dev;
struct se_node_acl *pr_reg_nacl;
struct se_session *se_sess = cmd->se_sess;
LIST_HEAD(preempt_and_abort_list);
struct t10_pr_registration *pr_reg, *pr_reg_tmp, *pr_reg_n, *pr_res_holder;
struct t10_reservation *pr_tmpl = &dev->t10_pr;
u32 pr_res_mapped_lun = 0;
int all_reg = 0, calling_it_nexus = 0;
bool sa_res_key_unmatched = sa_res_key != 0;
int prh_type = 0, prh_scope = 0;
if (!se_sess)
return TCM_LOGICAL_UNIT_COMMUNICATION_FAILURE;
pr_reg_n = core_scsi3_locate_pr_reg(cmd->se_dev, se_sess->se_node_acl,
se_sess);
if (!pr_reg_n) {
pr_err("SPC-3 PR: Unable to locate"
" PR_REGISTERED *pr_reg for PREEMPT%s\n",
(preempt_type == PREEMPT_AND_ABORT) ? "_AND_ABORT" : "");
return TCM_RESERVATION_CONFLICT;
}
if (pr_reg_n->pr_res_key != res_key) {
core_scsi3_put_pr_reg(pr_reg_n);
return TCM_RESERVATION_CONFLICT;
}
if (scope != PR_SCOPE_LU_SCOPE) {
pr_err("SPC-3 PR: Illegal SCOPE: 0x%02x\n", scope);
core_scsi3_put_pr_reg(pr_reg_n);
return TCM_INVALID_PARAMETER_LIST;
}
spin_lock(&dev->dev_reservation_lock);
pr_res_holder = dev->dev_pr_res_holder;
if (pr_res_holder &&
((pr_res_holder->pr_res_type == PR_TYPE_WRITE_EXCLUSIVE_ALLREG) ||
(pr_res_holder->pr_res_type == PR_TYPE_EXCLUSIVE_ACCESS_ALLREG)))
all_reg = 1;
if (!all_reg && !sa_res_key) {
spin_unlock(&dev->dev_reservation_lock);
core_scsi3_put_pr_reg(pr_reg_n);
return TCM_INVALID_PARAMETER_LIST;
}
if (!pr_res_holder || (pr_res_holder->pr_res_key != sa_res_key)) {
spin_lock(&pr_tmpl->registration_lock);
list_for_each_entry_safe(pr_reg, pr_reg_tmp,
&pr_tmpl->registration_list, pr_reg_list) {
if (!all_reg) {
if (pr_reg->pr_res_key != sa_res_key)
continue;
sa_res_key_unmatched = false;
calling_it_nexus = (pr_reg_n == pr_reg) ? 1 : 0;
pr_reg_nacl = pr_reg->pr_reg_nacl;
pr_res_mapped_lun = pr_reg->pr_res_mapped_lun;
__core_scsi3_free_registration(dev, pr_reg,
(preempt_type == PREEMPT_AND_ABORT) ? &preempt_and_abort_list :
NULL, calling_it_nexus);
} else {
if ((sa_res_key) &&
(pr_reg->pr_res_key != sa_res_key))
continue;
sa_res_key_unmatched = false;
calling_it_nexus = (pr_reg_n == pr_reg) ? 1 : 0;
if (calling_it_nexus)
continue;
pr_reg_nacl = pr_reg->pr_reg_nacl;
pr_res_mapped_lun = pr_reg->pr_res_mapped_lun;
__core_scsi3_free_registration(dev, pr_reg,
(preempt_type == PREEMPT_AND_ABORT) ? &preempt_and_abort_list :
NULL, 0);
}
if (!calling_it_nexus)
core_scsi3_ua_allocate(pr_reg_nacl,
pr_res_mapped_lun, 0x2A,
ASCQ_2AH_REGISTRATIONS_PREEMPTED);
}
spin_unlock(&pr_tmpl->registration_lock);
if (sa_res_key_unmatched) {
spin_unlock(&dev->dev_reservation_lock);
core_scsi3_put_pr_reg(pr_reg_n);
return TCM_RESERVATION_CONFLICT;
}
if (pr_res_holder && all_reg && !(sa_res_key)) {
__core_scsi3_complete_pro_preempt(dev, pr_reg_n,
(preempt_type == PREEMPT_AND_ABORT) ? &preempt_and_abort_list : NULL,
type, scope, preempt_type);
if (preempt_type == PREEMPT_AND_ABORT)
core_scsi3_release_preempt_and_abort(
&preempt_and_abort_list, pr_reg_n);
}
spin_unlock(&dev->dev_reservation_lock);
if (pr_tmpl->pr_aptpl_active)
core_scsi3_update_and_write_aptpl(cmd->se_dev, true);
core_scsi3_put_pr_reg(pr_reg_n);
core_scsi3_pr_generation(cmd->se_dev);
return 0;
}
prh_type = pr_res_holder->pr_res_type;
prh_scope = pr_res_holder->pr_res_scope;
if (pr_reg_n != pr_res_holder)
__core_scsi3_complete_pro_release(dev,
pr_res_holder->pr_reg_nacl,
dev->dev_pr_res_holder, 0, 0);
spin_lock(&pr_tmpl->registration_lock);
list_for_each_entry_safe(pr_reg, pr_reg_tmp,
&pr_tmpl->registration_list, pr_reg_list) {
calling_it_nexus = (pr_reg_n == pr_reg) ? 1 : 0;
if (calling_it_nexus)
continue;
if (pr_reg->pr_res_key != sa_res_key)
continue;
pr_reg_nacl = pr_reg->pr_reg_nacl;
pr_res_mapped_lun = pr_reg->pr_res_mapped_lun;
__core_scsi3_free_registration(dev, pr_reg,
(preempt_type == PREEMPT_AND_ABORT) ? &preempt_and_abort_list : NULL,
calling_it_nexus);
core_scsi3_ua_allocate(pr_reg_nacl, pr_res_mapped_lun, 0x2A,
ASCQ_2AH_REGISTRATIONS_PREEMPTED);
}
spin_unlock(&pr_tmpl->registration_lock);
__core_scsi3_complete_pro_preempt(dev, pr_reg_n,
(preempt_type == PREEMPT_AND_ABORT) ? &preempt_and_abort_list : NULL,
type, scope, preempt_type);
if ((prh_type != type) || (prh_scope != scope)) {
spin_lock(&pr_tmpl->registration_lock);
list_for_each_entry_safe(pr_reg, pr_reg_tmp,
&pr_tmpl->registration_list, pr_reg_list) {
calling_it_nexus = (pr_reg_n == pr_reg) ? 1 : 0;
if (calling_it_nexus)
continue;
core_scsi3_ua_allocate(pr_reg->pr_reg_nacl,
pr_reg->pr_res_mapped_lun, 0x2A,
ASCQ_2AH_RESERVATIONS_RELEASED);
}
spin_unlock(&pr_tmpl->registration_lock);
}
spin_unlock(&dev->dev_reservation_lock);
if (preempt_type == PREEMPT_AND_ABORT) {
core_tmr_lun_reset(dev, NULL, &preempt_and_abort_list, cmd);
core_scsi3_release_preempt_and_abort(&preempt_and_abort_list,
pr_reg_n);
}
if (pr_tmpl->pr_aptpl_active)
core_scsi3_update_and_write_aptpl(cmd->se_dev, true);
core_scsi3_put_pr_reg(pr_reg_n);
core_scsi3_pr_generation(cmd->se_dev);
return 0;
}
static sense_reason_t
core_scsi3_emulate_pro_preempt(struct se_cmd *cmd, int type, int scope,
u64 res_key, u64 sa_res_key, enum preempt_type preempt_type)
{
switch (type) {
case PR_TYPE_WRITE_EXCLUSIVE:
case PR_TYPE_EXCLUSIVE_ACCESS:
case PR_TYPE_WRITE_EXCLUSIVE_REGONLY:
case PR_TYPE_EXCLUSIVE_ACCESS_REGONLY:
case PR_TYPE_WRITE_EXCLUSIVE_ALLREG:
case PR_TYPE_EXCLUSIVE_ACCESS_ALLREG:
return core_scsi3_pro_preempt(cmd, type, scope, res_key,
sa_res_key, preempt_type);
default:
pr_err("SPC-3 PR: Unknown Service Action PREEMPT%s"
" Type: 0x%02x\n", (preempt_type == PREEMPT_AND_ABORT) ? "_AND_ABORT" : "", type);
return TCM_INVALID_CDB_FIELD;
}
}
static sense_reason_t
core_scsi3_emulate_pro_register_and_move(struct se_cmd *cmd, u64 res_key,
u64 sa_res_key, int aptpl, int unreg)
{
struct se_session *se_sess = cmd->se_sess;
struct se_device *dev = cmd->se_dev;
struct se_dev_entry *dest_se_deve = NULL;
struct se_lun *se_lun = cmd->se_lun;
struct se_node_acl *pr_res_nacl, *pr_reg_nacl, *dest_node_acl = NULL;
struct se_port *se_port;
struct se_portal_group *se_tpg, *dest_se_tpg = NULL;
struct target_core_fabric_ops *dest_tf_ops = NULL, *tf_ops;
struct t10_pr_registration *pr_reg, *pr_res_holder, *dest_pr_reg;
struct t10_reservation *pr_tmpl = &dev->t10_pr;
unsigned char *buf;
unsigned char *initiator_str;
char *iport_ptr = NULL, i_buf[PR_REG_ISID_ID_LEN];
u32 tid_len, tmp_tid_len;
int new_reg = 0, type, scope, matching_iname;
sense_reason_t ret;
unsigned short rtpi;
unsigned char proto_ident;
if (!se_sess || !se_lun) {
pr_err("SPC-3 PR: se_sess || struct se_lun is NULL!\n");
return TCM_LOGICAL_UNIT_COMMUNICATION_FAILURE;
}
memset(i_buf, 0, PR_REG_ISID_ID_LEN);
se_tpg = se_sess->se_tpg;
tf_ops = se_tpg->se_tpg_tfo;
pr_reg = core_scsi3_locate_pr_reg(cmd->se_dev, se_sess->se_node_acl,
se_sess);
if (!pr_reg) {
pr_err("SPC-3 PR: Unable to locate PR_REGISTERED"
" *pr_reg for REGISTER_AND_MOVE\n");
return TCM_LOGICAL_UNIT_COMMUNICATION_FAILURE;
}
if (res_key != pr_reg->pr_res_key) {
pr_warn("SPC-3 PR REGISTER_AND_MOVE: Received"
" res_key: 0x%016Lx does not match existing SA REGISTER"
" res_key: 0x%016Lx\n", res_key, pr_reg->pr_res_key);
ret = TCM_RESERVATION_CONFLICT;
goto out_put_pr_reg;
}
if (!sa_res_key) {
pr_warn("SPC-3 PR REGISTER_AND_MOVE: Received zero"
" sa_res_key\n");
ret = TCM_INVALID_PARAMETER_LIST;
goto out_put_pr_reg;
}
buf = transport_kmap_data_sg(cmd);
if (!buf) {
ret = TCM_LOGICAL_UNIT_COMMUNICATION_FAILURE;
goto out_put_pr_reg;
}
rtpi = (buf[18] & 0xff) << 8;
rtpi |= buf[19] & 0xff;
tid_len = (buf[20] & 0xff) << 24;
tid_len |= (buf[21] & 0xff) << 16;
tid_len |= (buf[22] & 0xff) << 8;
tid_len |= buf[23] & 0xff;
transport_kunmap_data_sg(cmd);
buf = NULL;
if ((tid_len + 24) != cmd->data_length) {
pr_err("SPC-3 PR: Illegal tid_len: %u + 24 byte header"
" does not equal CDB data_length: %u\n", tid_len,
cmd->data_length);
ret = TCM_INVALID_PARAMETER_LIST;
goto out_put_pr_reg;
}
spin_lock(&dev->se_port_lock);
list_for_each_entry(se_port, &dev->dev_sep_list, sep_list) {
if (se_port->sep_rtpi != rtpi)
continue;
dest_se_tpg = se_port->sep_tpg;
if (!dest_se_tpg)
continue;
dest_tf_ops = dest_se_tpg->se_tpg_tfo;
if (!dest_tf_ops)
continue;
atomic_inc_mb(&dest_se_tpg->tpg_pr_ref_count);
spin_unlock(&dev->se_port_lock);
if (core_scsi3_tpg_depend_item(dest_se_tpg)) {
pr_err("core_scsi3_tpg_depend_item() failed"
" for dest_se_tpg\n");
atomic_dec_mb(&dest_se_tpg->tpg_pr_ref_count);
ret = TCM_LOGICAL_UNIT_COMMUNICATION_FAILURE;
goto out_put_pr_reg;
}
spin_lock(&dev->se_port_lock);
break;
}
spin_unlock(&dev->se_port_lock);
if (!dest_se_tpg || !dest_tf_ops) {
pr_err("SPC-3 PR REGISTER_AND_MOVE: Unable to locate"
" fabric ops from Relative Target Port Identifier:"
" %hu\n", rtpi);
ret = TCM_INVALID_PARAMETER_LIST;
goto out_put_pr_reg;
}
buf = transport_kmap_data_sg(cmd);
if (!buf) {
ret = TCM_LOGICAL_UNIT_COMMUNICATION_FAILURE;
goto out_put_pr_reg;
}
proto_ident = (buf[24] & 0x0f);
pr_debug("SPC-3 PR REGISTER_AND_MOVE: Extracted Protocol Identifier:"
" 0x%02x\n", proto_ident);
if (proto_ident != dest_tf_ops->get_fabric_proto_ident(dest_se_tpg)) {
pr_err("SPC-3 PR REGISTER_AND_MOVE: Received"
" proto_ident: 0x%02x does not match ident: 0x%02x"
" from fabric: %s\n", proto_ident,
dest_tf_ops->get_fabric_proto_ident(dest_se_tpg),
dest_tf_ops->get_fabric_name());
ret = TCM_INVALID_PARAMETER_LIST;
goto out;
}
if (dest_tf_ops->tpg_parse_pr_out_transport_id == NULL) {
pr_err("SPC-3 PR REGISTER_AND_MOVE: Fabric does not"
" containg a valid tpg_parse_pr_out_transport_id"
" function pointer\n");
ret = TCM_LOGICAL_UNIT_COMMUNICATION_FAILURE;
goto out;
}
initiator_str = dest_tf_ops->tpg_parse_pr_out_transport_id(dest_se_tpg,
(const char *)&buf[24], &tmp_tid_len, &iport_ptr);
if (!initiator_str) {
pr_err("SPC-3 PR REGISTER_AND_MOVE: Unable to locate"
" initiator_str from Transport ID\n");
ret = TCM_INVALID_PARAMETER_LIST;
goto out;
}
transport_kunmap_data_sg(cmd);
buf = NULL;
pr_debug("SPC-3 PR [%s] Extracted initiator %s identifier: %s"
" %s\n", dest_tf_ops->get_fabric_name(), (iport_ptr != NULL) ?
"port" : "device", initiator_str, (iport_ptr != NULL) ?
iport_ptr : "");
pr_reg_nacl = pr_reg->pr_reg_nacl;
matching_iname = (!strcmp(initiator_str,
pr_reg_nacl->initiatorname)) ? 1 : 0;
if (!matching_iname)
goto after_iport_check;
if (!iport_ptr || !pr_reg->isid_present_at_reg) {
pr_err("SPC-3 PR REGISTER_AND_MOVE: TransportID: %s"
" matches: %s on received I_T Nexus\n", initiator_str,
pr_reg_nacl->initiatorname);
ret = TCM_INVALID_PARAMETER_LIST;
goto out;
}
if (!strcmp(iport_ptr, pr_reg->pr_reg_isid)) {
pr_err("SPC-3 PR REGISTER_AND_MOVE: TransportID: %s %s"
" matches: %s %s on received I_T Nexus\n",
initiator_str, iport_ptr, pr_reg_nacl->initiatorname,
pr_reg->pr_reg_isid);
ret = TCM_INVALID_PARAMETER_LIST;
goto out;
}
after_iport_check:
spin_lock_irq(&dest_se_tpg->acl_node_lock);
dest_node_acl = __core_tpg_get_initiator_node_acl(dest_se_tpg,
initiator_str);
if (dest_node_acl)
atomic_inc_mb(&dest_node_acl->acl_pr_ref_count);
spin_unlock_irq(&dest_se_tpg->acl_node_lock);
if (!dest_node_acl) {
pr_err("Unable to locate %s dest_node_acl for"
" TransportID%s\n", dest_tf_ops->get_fabric_name(),
initiator_str);
ret = TCM_INVALID_PARAMETER_LIST;
goto out;
}
if (core_scsi3_nodeacl_depend_item(dest_node_acl)) {
pr_err("core_scsi3_nodeacl_depend_item() for"
" dest_node_acl\n");
atomic_dec_mb(&dest_node_acl->acl_pr_ref_count);
dest_node_acl = NULL;
ret = TCM_INVALID_PARAMETER_LIST;
goto out;
}
pr_debug("SPC-3 PR REGISTER_AND_MOVE: Found %s dest_node_acl:"
" %s from TransportID\n", dest_tf_ops->get_fabric_name(),
dest_node_acl->initiatorname);
dest_se_deve = core_get_se_deve_from_rtpi(dest_node_acl, rtpi);
if (!dest_se_deve) {
pr_err("Unable to locate %s dest_se_deve from RTPI:"
" %hu\n", dest_tf_ops->get_fabric_name(), rtpi);
ret = TCM_INVALID_PARAMETER_LIST;
goto out;
}
if (core_scsi3_lunacl_depend_item(dest_se_deve)) {
pr_err("core_scsi3_lunacl_depend_item() failed\n");
atomic_dec_mb(&dest_se_deve->pr_ref_count);
dest_se_deve = NULL;
ret = TCM_LOGICAL_UNIT_COMMUNICATION_FAILURE;
goto out;
}
pr_debug("SPC-3 PR REGISTER_AND_MOVE: Located %s node %s LUN"
" ACL for dest_se_deve->mapped_lun: %u\n",
dest_tf_ops->get_fabric_name(), dest_node_acl->initiatorname,
dest_se_deve->mapped_lun);
spin_lock(&dev->dev_reservation_lock);
pr_res_holder = dev->dev_pr_res_holder;
if (!pr_res_holder) {
pr_warn("SPC-3 PR REGISTER_AND_MOVE: No reservation"
" currently held\n");
spin_unlock(&dev->dev_reservation_lock);
ret = TCM_INVALID_CDB_FIELD;
goto out;
}
if (pr_res_holder != pr_reg) {
pr_warn("SPC-3 PR REGISTER_AND_MOVE: Calling I_T"
" Nexus is not reservation holder\n");
spin_unlock(&dev->dev_reservation_lock);
ret = TCM_RESERVATION_CONFLICT;
goto out;
}
if ((pr_res_holder->pr_res_type == PR_TYPE_WRITE_EXCLUSIVE_ALLREG) ||
(pr_res_holder->pr_res_type == PR_TYPE_EXCLUSIVE_ACCESS_ALLREG)) {
pr_warn("SPC-3 PR REGISTER_AND_MOVE: Unable to move"
" reservation for type: %s\n",
core_scsi3_pr_dump_type(pr_res_holder->pr_res_type));
spin_unlock(&dev->dev_reservation_lock);
ret = TCM_RESERVATION_CONFLICT;
goto out;
}
pr_res_nacl = pr_res_holder->pr_reg_nacl;
type = pr_res_holder->pr_res_type;
scope = pr_res_holder->pr_res_type;
dest_pr_reg = __core_scsi3_locate_pr_reg(dev, dest_node_acl,
iport_ptr);
if (!dest_pr_reg) {
if (core_scsi3_alloc_registration(cmd->se_dev,
dest_node_acl, dest_se_deve, iport_ptr,
sa_res_key, 0, aptpl, 2, 1)) {
spin_unlock(&dev->dev_reservation_lock);
ret = TCM_INVALID_PARAMETER_LIST;
goto out;
}
dest_pr_reg = __core_scsi3_locate_pr_reg(dev, dest_node_acl,
iport_ptr);
new_reg = 1;
}
__core_scsi3_complete_pro_release(dev, pr_res_nacl,
dev->dev_pr_res_holder, 0, 0);
dev->dev_pr_res_holder = dest_pr_reg;
dest_pr_reg->pr_res_holder = 1;
dest_pr_reg->pr_res_type = type;
pr_reg->pr_res_scope = scope;
core_pr_dump_initiator_port(pr_reg, i_buf, PR_REG_ISID_ID_LEN);
if (!new_reg)
dest_pr_reg->pr_res_generation = pr_tmpl->pr_generation++;
spin_unlock(&dev->dev_reservation_lock);
pr_debug("SPC-3 PR [%s] Service Action: REGISTER_AND_MOVE"
" created new reservation holder TYPE: %s on object RTPI:"
" %hu PRGeneration: 0x%08x\n", dest_tf_ops->get_fabric_name(),
core_scsi3_pr_dump_type(type), rtpi,
dest_pr_reg->pr_res_generation);
pr_debug("SPC-3 PR Successfully moved reservation from"
" %s Fabric Node: %s%s -> %s Fabric Node: %s %s\n",
tf_ops->get_fabric_name(), pr_reg_nacl->initiatorname,
i_buf, dest_tf_ops->get_fabric_name(),
dest_node_acl->initiatorname, (iport_ptr != NULL) ?
iport_ptr : "");
core_scsi3_lunacl_undepend_item(dest_se_deve);
core_scsi3_nodeacl_undepend_item(dest_node_acl);
core_scsi3_tpg_undepend_item(dest_se_tpg);
if (unreg) {
spin_lock(&pr_tmpl->registration_lock);
__core_scsi3_free_registration(dev, pr_reg, NULL, 1);
spin_unlock(&pr_tmpl->registration_lock);
} else
core_scsi3_put_pr_reg(pr_reg);
core_scsi3_update_and_write_aptpl(cmd->se_dev, aptpl);
transport_kunmap_data_sg(cmd);
core_scsi3_put_pr_reg(dest_pr_reg);
return 0;
out:
if (buf)
transport_kunmap_data_sg(cmd);
if (dest_se_deve)
core_scsi3_lunacl_undepend_item(dest_se_deve);
if (dest_node_acl)
core_scsi3_nodeacl_undepend_item(dest_node_acl);
core_scsi3_tpg_undepend_item(dest_se_tpg);
out_put_pr_reg:
core_scsi3_put_pr_reg(pr_reg);
return ret;
}
static unsigned long long core_scsi3_extract_reservation_key(unsigned char *cdb)
{
unsigned int __v1, __v2;
__v1 = (cdb[0] << 24) | (cdb[1] << 16) | (cdb[2] << 8) | cdb[3];
__v2 = (cdb[4] << 24) | (cdb[5] << 16) | (cdb[6] << 8) | cdb[7];
return ((unsigned long long)__v2) | (unsigned long long)__v1 << 32;
}
sense_reason_t
target_scsi3_emulate_pr_out(struct se_cmd *cmd)
{
struct se_device *dev = cmd->se_dev;
unsigned char *cdb = &cmd->t_task_cdb[0];
unsigned char *buf;
u64 res_key, sa_res_key;
int sa, scope, type, aptpl;
int spec_i_pt = 0, all_tg_pt = 0, unreg = 0;
sense_reason_t ret;
if (cmd->se_dev->dev_reservation_flags & DRF_SPC2_RESERVATIONS) {
pr_err("Received PERSISTENT_RESERVE CDB while legacy"
" SPC-2 reservation is held, returning"
" RESERVATION_CONFLICT\n");
return TCM_RESERVATION_CONFLICT;
}
if (!cmd->se_sess)
return TCM_LOGICAL_UNIT_COMMUNICATION_FAILURE;
if (cmd->data_length < 24) {
pr_warn("SPC-PR: Received PR OUT parameter list"
" length too small: %u\n", cmd->data_length);
return TCM_INVALID_PARAMETER_LIST;
}
sa = (cdb[1] & 0x1f);
scope = (cdb[2] & 0xf0);
type = (cdb[2] & 0x0f);
buf = transport_kmap_data_sg(cmd);
if (!buf)
return TCM_LOGICAL_UNIT_COMMUNICATION_FAILURE;
res_key = core_scsi3_extract_reservation_key(&buf[0]);
sa_res_key = core_scsi3_extract_reservation_key(&buf[8]);
if (sa != PRO_REGISTER_AND_MOVE) {
spec_i_pt = (buf[20] & 0x08);
all_tg_pt = (buf[20] & 0x04);
aptpl = (buf[20] & 0x01);
} else {
aptpl = (buf[17] & 0x01);
unreg = (buf[17] & 0x02);
}
if (dev->dev_attrib.force_pr_aptpl)
aptpl = 1;
transport_kunmap_data_sg(cmd);
buf = NULL;
if (spec_i_pt && ((cdb[1] & 0x1f) != PRO_REGISTER))
return TCM_INVALID_PARAMETER_LIST;
if (!spec_i_pt && ((cdb[1] & 0x1f) != PRO_REGISTER_AND_MOVE) &&
(cmd->data_length != 24)) {
pr_warn("SPC-PR: Received PR OUT illegal parameter"
" list length: %u\n", cmd->data_length);
return TCM_INVALID_PARAMETER_LIST;
}
switch (sa) {
case PRO_REGISTER:
ret = core_scsi3_emulate_pro_register(cmd,
res_key, sa_res_key, aptpl, all_tg_pt, spec_i_pt, REGISTER);
break;
case PRO_RESERVE:
ret = core_scsi3_emulate_pro_reserve(cmd, type, scope, res_key);
break;
case PRO_RELEASE:
ret = core_scsi3_emulate_pro_release(cmd, type, scope, res_key);
break;
case PRO_CLEAR:
ret = core_scsi3_emulate_pro_clear(cmd, res_key);
break;
case PRO_PREEMPT:
ret = core_scsi3_emulate_pro_preempt(cmd, type, scope,
res_key, sa_res_key, PREEMPT);
break;
case PRO_PREEMPT_AND_ABORT:
ret = core_scsi3_emulate_pro_preempt(cmd, type, scope,
res_key, sa_res_key, PREEMPT_AND_ABORT);
break;
case PRO_REGISTER_AND_IGNORE_EXISTING_KEY:
ret = core_scsi3_emulate_pro_register(cmd,
0, sa_res_key, aptpl, all_tg_pt, spec_i_pt, REGISTER_AND_IGNORE_EXISTING_KEY);
break;
case PRO_REGISTER_AND_MOVE:
ret = core_scsi3_emulate_pro_register_and_move(cmd, res_key,
sa_res_key, aptpl, unreg);
break;
default:
pr_err("Unknown PERSISTENT_RESERVE_OUT service"
" action: 0x%02x\n", cdb[1] & 0x1f);
return TCM_INVALID_CDB_FIELD;
}
if (!ret)
target_complete_cmd(cmd, GOOD);
return ret;
}
static sense_reason_t
core_scsi3_pri_read_keys(struct se_cmd *cmd)
{
struct se_device *dev = cmd->se_dev;
struct t10_pr_registration *pr_reg;
unsigned char *buf;
u32 add_len = 0, off = 8;
if (cmd->data_length < 8) {
pr_err("PRIN SA READ_KEYS SCSI Data Length: %u"
" too small\n", cmd->data_length);
return TCM_INVALID_CDB_FIELD;
}
buf = transport_kmap_data_sg(cmd);
if (!buf)
return TCM_LOGICAL_UNIT_COMMUNICATION_FAILURE;
buf[0] = ((dev->t10_pr.pr_generation >> 24) & 0xff);
buf[1] = ((dev->t10_pr.pr_generation >> 16) & 0xff);
buf[2] = ((dev->t10_pr.pr_generation >> 8) & 0xff);
buf[3] = (dev->t10_pr.pr_generation & 0xff);
spin_lock(&dev->t10_pr.registration_lock);
list_for_each_entry(pr_reg, &dev->t10_pr.registration_list,
pr_reg_list) {
if ((add_len + 8) > (cmd->data_length - 8))
break;
buf[off++] = ((pr_reg->pr_res_key >> 56) & 0xff);
buf[off++] = ((pr_reg->pr_res_key >> 48) & 0xff);
buf[off++] = ((pr_reg->pr_res_key >> 40) & 0xff);
buf[off++] = ((pr_reg->pr_res_key >> 32) & 0xff);
buf[off++] = ((pr_reg->pr_res_key >> 24) & 0xff);
buf[off++] = ((pr_reg->pr_res_key >> 16) & 0xff);
buf[off++] = ((pr_reg->pr_res_key >> 8) & 0xff);
buf[off++] = (pr_reg->pr_res_key & 0xff);
add_len += 8;
}
spin_unlock(&dev->t10_pr.registration_lock);
buf[4] = ((add_len >> 24) & 0xff);
buf[5] = ((add_len >> 16) & 0xff);
buf[6] = ((add_len >> 8) & 0xff);
buf[7] = (add_len & 0xff);
transport_kunmap_data_sg(cmd);
return 0;
}
static sense_reason_t
core_scsi3_pri_read_reservation(struct se_cmd *cmd)
{
struct se_device *dev = cmd->se_dev;
struct t10_pr_registration *pr_reg;
unsigned char *buf;
u64 pr_res_key;
u32 add_len = 16;
if (cmd->data_length < 8) {
pr_err("PRIN SA READ_RESERVATIONS SCSI Data Length: %u"
" too small\n", cmd->data_length);
return TCM_INVALID_CDB_FIELD;
}
buf = transport_kmap_data_sg(cmd);
if (!buf)
return TCM_LOGICAL_UNIT_COMMUNICATION_FAILURE;
buf[0] = ((dev->t10_pr.pr_generation >> 24) & 0xff);
buf[1] = ((dev->t10_pr.pr_generation >> 16) & 0xff);
buf[2] = ((dev->t10_pr.pr_generation >> 8) & 0xff);
buf[3] = (dev->t10_pr.pr_generation & 0xff);
spin_lock(&dev->dev_reservation_lock);
pr_reg = dev->dev_pr_res_holder;
if (pr_reg) {
buf[4] = ((add_len >> 24) & 0xff);
buf[5] = ((add_len >> 16) & 0xff);
buf[6] = ((add_len >> 8) & 0xff);
buf[7] = (add_len & 0xff);
if (cmd->data_length < 22)
goto err;
if ((pr_reg->pr_res_type == PR_TYPE_WRITE_EXCLUSIVE_ALLREG) ||
(pr_reg->pr_res_type == PR_TYPE_EXCLUSIVE_ACCESS_ALLREG))
pr_res_key = 0;
else
pr_res_key = pr_reg->pr_res_key;
buf[8] = ((pr_res_key >> 56) & 0xff);
buf[9] = ((pr_res_key >> 48) & 0xff);
buf[10] = ((pr_res_key >> 40) & 0xff);
buf[11] = ((pr_res_key >> 32) & 0xff);
buf[12] = ((pr_res_key >> 24) & 0xff);
buf[13] = ((pr_res_key >> 16) & 0xff);
buf[14] = ((pr_res_key >> 8) & 0xff);
buf[15] = (pr_res_key & 0xff);
buf[21] = (pr_reg->pr_res_scope & 0xf0) |
(pr_reg->pr_res_type & 0x0f);
}
err:
spin_unlock(&dev->dev_reservation_lock);
transport_kunmap_data_sg(cmd);
return 0;
}
static sense_reason_t
core_scsi3_pri_report_capabilities(struct se_cmd *cmd)
{
struct se_device *dev = cmd->se_dev;
struct t10_reservation *pr_tmpl = &dev->t10_pr;
unsigned char *buf;
u16 add_len = 8;
if (cmd->data_length < 6) {
pr_err("PRIN SA REPORT_CAPABILITIES SCSI Data Length:"
" %u too small\n", cmd->data_length);
return TCM_INVALID_CDB_FIELD;
}
buf = transport_kmap_data_sg(cmd);
if (!buf)
return TCM_LOGICAL_UNIT_COMMUNICATION_FAILURE;
buf[0] = ((add_len >> 8) & 0xff);
buf[1] = (add_len & 0xff);
buf[2] |= 0x10;
buf[2] |= 0x08;
buf[2] |= 0x04;
buf[2] |= 0x01;
buf[3] |= 0x80;
buf[3] |= 0x10;
if (pr_tmpl->pr_aptpl_active)
buf[3] |= 0x01;
buf[4] |= 0x80;
buf[4] |= 0x40;
buf[4] |= 0x20;
buf[4] |= 0x08;
buf[4] |= 0x02;
buf[5] |= 0x01;
transport_kunmap_data_sg(cmd);
return 0;
}
static sense_reason_t
core_scsi3_pri_read_full_status(struct se_cmd *cmd)
{
struct se_device *dev = cmd->se_dev;
struct se_node_acl *se_nacl;
struct se_portal_group *se_tpg;
struct t10_pr_registration *pr_reg, *pr_reg_tmp;
struct t10_reservation *pr_tmpl = &dev->t10_pr;
unsigned char *buf;
u32 add_desc_len = 0, add_len = 0, desc_len, exp_desc_len;
u32 off = 8;
int format_code = 0, pr_res_type = 0, pr_res_scope = 0;
bool all_reg = false;
if (cmd->data_length < 8) {
pr_err("PRIN SA READ_FULL_STATUS SCSI Data Length: %u"
" too small\n", cmd->data_length);
return TCM_INVALID_CDB_FIELD;
}
buf = transport_kmap_data_sg(cmd);
if (!buf)
return TCM_LOGICAL_UNIT_COMMUNICATION_FAILURE;
buf[0] = ((dev->t10_pr.pr_generation >> 24) & 0xff);
buf[1] = ((dev->t10_pr.pr_generation >> 16) & 0xff);
buf[2] = ((dev->t10_pr.pr_generation >> 8) & 0xff);
buf[3] = (dev->t10_pr.pr_generation & 0xff);
spin_lock(&dev->dev_reservation_lock);
if (dev->dev_pr_res_holder) {
struct t10_pr_registration *pr_holder = dev->dev_pr_res_holder;
if (pr_holder->pr_res_type == PR_TYPE_WRITE_EXCLUSIVE_ALLREG ||
pr_holder->pr_res_type == PR_TYPE_EXCLUSIVE_ACCESS_ALLREG) {
all_reg = true;
pr_res_type = pr_holder->pr_res_type;
pr_res_scope = pr_holder->pr_res_scope;
}
}
spin_unlock(&dev->dev_reservation_lock);
spin_lock(&pr_tmpl->registration_lock);
list_for_each_entry_safe(pr_reg, pr_reg_tmp,
&pr_tmpl->registration_list, pr_reg_list) {
se_nacl = pr_reg->pr_reg_nacl;
se_tpg = pr_reg->pr_reg_nacl->se_tpg;
add_desc_len = 0;
atomic_inc_mb(&pr_reg->pr_res_holders);
spin_unlock(&pr_tmpl->registration_lock);
exp_desc_len = se_tpg->se_tpg_tfo->tpg_get_pr_transport_id_len(
se_tpg, se_nacl, pr_reg, &format_code);
if ((exp_desc_len + add_len) > cmd->data_length) {
pr_warn("SPC-3 PRIN READ_FULL_STATUS ran"
" out of buffer: %d\n", cmd->data_length);
spin_lock(&pr_tmpl->registration_lock);
atomic_dec_mb(&pr_reg->pr_res_holders);
break;
}
buf[off++] = ((pr_reg->pr_res_key >> 56) & 0xff);
buf[off++] = ((pr_reg->pr_res_key >> 48) & 0xff);
buf[off++] = ((pr_reg->pr_res_key >> 40) & 0xff);
buf[off++] = ((pr_reg->pr_res_key >> 32) & 0xff);
buf[off++] = ((pr_reg->pr_res_key >> 24) & 0xff);
buf[off++] = ((pr_reg->pr_res_key >> 16) & 0xff);
buf[off++] = ((pr_reg->pr_res_key >> 8) & 0xff);
buf[off++] = (pr_reg->pr_res_key & 0xff);
off += 4;
if (pr_reg->pr_reg_all_tg_pt)
buf[off] = 0x02;
if (pr_reg->pr_res_holder) {
buf[off++] |= 0x01;
buf[off++] = (pr_reg->pr_res_scope & 0xf0) |
(pr_reg->pr_res_type & 0x0f);
} else if (all_reg) {
buf[off++] |= 0x01;
buf[off++] = (pr_res_scope & 0xf0) |
(pr_res_type & 0x0f);
} else {
off += 2;
}
off += 4;
if (!pr_reg->pr_reg_all_tg_pt) {
struct se_port *port = pr_reg->pr_reg_tg_pt_lun->lun_sep;
buf[off++] = ((port->sep_rtpi >> 8) & 0xff);
buf[off++] = (port->sep_rtpi & 0xff);
} else
off += 2;
desc_len = se_tpg->se_tpg_tfo->tpg_get_pr_transport_id(se_tpg,
se_nacl, pr_reg, &format_code, &buf[off+4]);
spin_lock(&pr_tmpl->registration_lock);
atomic_dec_mb(&pr_reg->pr_res_holders);
buf[off++] = ((desc_len >> 24) & 0xff);
buf[off++] = ((desc_len >> 16) & 0xff);
buf[off++] = ((desc_len >> 8) & 0xff);
buf[off++] = (desc_len & 0xff);
add_desc_len = (24 + desc_len);
off += desc_len;
add_len += add_desc_len;
}
spin_unlock(&pr_tmpl->registration_lock);
buf[4] = ((add_len >> 24) & 0xff);
buf[5] = ((add_len >> 16) & 0xff);
buf[6] = ((add_len >> 8) & 0xff);
buf[7] = (add_len & 0xff);
transport_kunmap_data_sg(cmd);
return 0;
}
sense_reason_t
target_scsi3_emulate_pr_in(struct se_cmd *cmd)
{
sense_reason_t ret;
if (cmd->se_dev->dev_reservation_flags & DRF_SPC2_RESERVATIONS) {
pr_err("Received PERSISTENT_RESERVE CDB while legacy"
" SPC-2 reservation is held, returning"
" RESERVATION_CONFLICT\n");
return TCM_RESERVATION_CONFLICT;
}
switch (cmd->t_task_cdb[1] & 0x1f) {
case PRI_READ_KEYS:
ret = core_scsi3_pri_read_keys(cmd);
break;
case PRI_READ_RESERVATION:
ret = core_scsi3_pri_read_reservation(cmd);
break;
case PRI_REPORT_CAPABILITIES:
ret = core_scsi3_pri_report_capabilities(cmd);
break;
case PRI_READ_FULL_STATUS:
ret = core_scsi3_pri_read_full_status(cmd);
break;
default:
pr_err("Unknown PERSISTENT_RESERVE_IN service"
" action: 0x%02x\n", cmd->t_task_cdb[1] & 0x1f);
return TCM_INVALID_CDB_FIELD;
}
if (!ret)
target_complete_cmd(cmd, GOOD);
return ret;
}
sense_reason_t
target_check_reservation(struct se_cmd *cmd)
{
struct se_device *dev = cmd->se_dev;
sense_reason_t ret;
if (!cmd->se_sess)
return 0;
if (dev->se_hba->hba_flags & HBA_FLAGS_INTERNAL_USE)
return 0;
if (dev->transport->transport_type == TRANSPORT_PLUGIN_PHBA_PDEV)
return 0;
spin_lock(&dev->dev_reservation_lock);
if (dev->dev_reservation_flags & DRF_SPC2_RESERVATIONS)
ret = target_scsi2_reservation_check(cmd);
else
ret = target_scsi3_pr_reservation_check(cmd);
spin_unlock(&dev->dev_reservation_lock);
return ret;
}
