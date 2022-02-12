int core_pr_dump_initiator_port(
struct t10_pr_registration *pr_reg,
char *buf,
u32 size)
{
if (!(pr_reg->isid_present_at_reg))
return 0;
snprintf(buf, size, ",i,0x%s", &pr_reg->pr_reg_isid[0]);
return 1;
}
static int core_scsi2_reservation_seq_non_holder(
struct se_cmd *cmd,
unsigned char *cdb,
u32 pr_reg_type)
{
switch (cdb[0]) {
case INQUIRY:
case RELEASE:
case RELEASE_10:
return 0;
default:
return 1;
}
return 1;
}
static int core_scsi2_reservation_check(struct se_cmd *cmd, u32 *pr_reg_type)
{
struct se_device *dev = cmd->se_dev;
struct se_session *sess = cmd->se_sess;
int ret;
if (!(sess))
return 0;
spin_lock(&dev->dev_reservation_lock);
if (!dev->dev_reserved_node_acl || !sess) {
spin_unlock(&dev->dev_reservation_lock);
return 0;
}
if (dev->dev_reserved_node_acl != sess->se_node_acl) {
spin_unlock(&dev->dev_reservation_lock);
return -1;
}
if (!(dev->dev_flags & DF_SPC2_RESERVATIONS_WITH_ISID)) {
spin_unlock(&dev->dev_reservation_lock);
return 0;
}
ret = (dev->dev_res_bin_isid == sess->sess_bin_isid) ? 0 : -1;
spin_unlock(&dev->dev_reservation_lock);
return ret;
}
static int core_scsi2_reservation_release(struct se_cmd *cmd)
{
struct se_device *dev = cmd->se_dev;
struct se_session *sess = cmd->se_sess;
struct se_portal_group *tpg = sess->se_tpg;
if (!(sess) || !(tpg))
return 0;
spin_lock(&dev->dev_reservation_lock);
if (!dev->dev_reserved_node_acl || !sess) {
spin_unlock(&dev->dev_reservation_lock);
return 0;
}
if (dev->dev_reserved_node_acl != sess->se_node_acl) {
spin_unlock(&dev->dev_reservation_lock);
return 0;
}
dev->dev_reserved_node_acl = NULL;
dev->dev_flags &= ~DF_SPC2_RESERVATIONS;
if (dev->dev_flags & DF_SPC2_RESERVATIONS_WITH_ISID) {
dev->dev_res_bin_isid = 0;
dev->dev_flags &= ~DF_SPC2_RESERVATIONS_WITH_ISID;
}
printk(KERN_INFO "SCSI-2 Released reservation for %s LUN: %u ->"
" MAPPED LUN: %u for %s\n", TPG_TFO(tpg)->get_fabric_name(),
SE_LUN(cmd)->unpacked_lun, cmd->se_deve->mapped_lun,
sess->se_node_acl->initiatorname);
spin_unlock(&dev->dev_reservation_lock);
return 0;
}
static int core_scsi2_reservation_reserve(struct se_cmd *cmd)
{
struct se_device *dev = cmd->se_dev;
struct se_session *sess = cmd->se_sess;
struct se_portal_group *tpg = sess->se_tpg;
if ((T_TASK(cmd)->t_task_cdb[1] & 0x01) &&
(T_TASK(cmd)->t_task_cdb[1] & 0x02)) {
printk(KERN_ERR "LongIO and Obselete Bits set, returning"
" ILLEGAL_REQUEST\n");
return PYX_TRANSPORT_ILLEGAL_REQUEST;
}
if (!(sess) || !(tpg))
return 0;
spin_lock(&dev->dev_reservation_lock);
if (dev->dev_reserved_node_acl &&
(dev->dev_reserved_node_acl != sess->se_node_acl)) {
printk(KERN_ERR "SCSI-2 RESERVATION CONFLIFT for %s fabric\n",
TPG_TFO(tpg)->get_fabric_name());
printk(KERN_ERR "Original reserver LUN: %u %s\n",
SE_LUN(cmd)->unpacked_lun,
dev->dev_reserved_node_acl->initiatorname);
printk(KERN_ERR "Current attempt - LUN: %u -> MAPPED LUN: %u"
" from %s \n", SE_LUN(cmd)->unpacked_lun,
cmd->se_deve->mapped_lun,
sess->se_node_acl->initiatorname);
spin_unlock(&dev->dev_reservation_lock);
return PYX_TRANSPORT_RESERVATION_CONFLICT;
}
dev->dev_reserved_node_acl = sess->se_node_acl;
dev->dev_flags |= DF_SPC2_RESERVATIONS;
if (sess->sess_bin_isid != 0) {
dev->dev_res_bin_isid = sess->sess_bin_isid;
dev->dev_flags |= DF_SPC2_RESERVATIONS_WITH_ISID;
}
printk(KERN_INFO "SCSI-2 Reserved %s LUN: %u -> MAPPED LUN: %u"
" for %s\n", TPG_TFO(tpg)->get_fabric_name(),
SE_LUN(cmd)->unpacked_lun, cmd->se_deve->mapped_lun,
sess->se_node_acl->initiatorname);
spin_unlock(&dev->dev_reservation_lock);
return 0;
}
int core_scsi2_emulate_crh(struct se_cmd *cmd)
{
struct se_session *se_sess = cmd->se_sess;
struct se_subsystem_dev *su_dev = cmd->se_dev->se_sub_dev;
struct t10_pr_registration *pr_reg;
struct t10_reservation_template *pr_tmpl = &su_dev->t10_reservation;
unsigned char *cdb = &T_TASK(cmd)->t_task_cdb[0];
int crh = (T10_RES(su_dev)->res_type == SPC3_PERSISTENT_RESERVATIONS);
int conflict = 0;
if (!(se_sess))
return 0;
if (!(crh))
goto after_crh;
pr_reg = core_scsi3_locate_pr_reg(cmd->se_dev, se_sess->se_node_acl,
se_sess);
if (pr_reg) {
if (pr_reg->pr_res_holder) {
core_scsi3_put_pr_reg(pr_reg);
return 0;
}
if ((pr_reg->pr_res_type == PR_TYPE_WRITE_EXCLUSIVE_REGONLY) ||
(pr_reg->pr_res_type == PR_TYPE_EXCLUSIVE_ACCESS_REGONLY) ||
(pr_reg->pr_res_type == PR_TYPE_WRITE_EXCLUSIVE_ALLREG) ||
(pr_reg->pr_res_type == PR_TYPE_EXCLUSIVE_ACCESS_ALLREG)) {
core_scsi3_put_pr_reg(pr_reg);
return 0;
}
core_scsi3_put_pr_reg(pr_reg);
conflict = 1;
} else {
spin_lock(&pr_tmpl->registration_lock);
conflict = (list_empty(&pr_tmpl->registration_list)) ? 0 : 1;
spin_unlock(&pr_tmpl->registration_lock);
}
if (conflict) {
printk(KERN_ERR "Received legacy SPC-2 RESERVE/RELEASE"
" while active SPC-3 registrations exist,"
" returning RESERVATION_CONFLICT\n");
return PYX_TRANSPORT_RESERVATION_CONFLICT;
}
after_crh:
if ((cdb[0] == RESERVE) || (cdb[0] == RESERVE_10))
return core_scsi2_reservation_reserve(cmd);
else if ((cdb[0] == RELEASE) || (cdb[0] == RELEASE_10))
return core_scsi2_reservation_release(cmd);
else
return PYX_TRANSPORT_INVALID_CDB_FIELD;
}
static int core_scsi3_pr_seq_non_holder(
struct se_cmd *cmd,
unsigned char *cdb,
u32 pr_reg_type)
{
struct se_dev_entry *se_deve;
struct se_session *se_sess = SE_SESS(cmd);
int other_cdb = 0, ignore_reg;
int registered_nexus = 0, ret = 1;
int all_reg = 0, reg_only = 0;
int we = 0;
int legacy = 0;
if (cmd->se_dev->dev_flags & DF_SPC2_RESERVATIONS)
return core_scsi2_reservation_seq_non_holder(cmd,
cdb, pr_reg_type);
se_deve = &se_sess->se_node_acl->device_list[cmd->orig_fe_lun];
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
return -1;
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
printk(KERN_ERR "Unknown PERSISTENT_RESERVE_OUT service"
" action: 0x%02x\n", cdb[1] & 0x1f);
return -1;
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
printk(KERN_ERR "Unknown MI Service Action: 0x%02x\n",
(cdb[1] & 0x1f));
return -1;
}
break;
case ACCESS_CONTROL_IN:
case ACCESS_CONTROL_OUT:
case INQUIRY:
case LOG_SENSE:
case READ_MEDIA_SERIAL_NUMBER:
case REPORT_LUNS:
case REQUEST_SENSE:
ret = 0;
break;
default:
other_cdb = 1;
break;
}
if (!(ret) && !(other_cdb)) {
#if 0
printk(KERN_INFO "Allowing explict CDB: 0x%02x for %s"
" reservation holder\n", cdb[0],
core_scsi3_pr_dump_type(pr_reg_type));
#endif
return ret;
}
if ((we) && !(registered_nexus)) {
if (cmd->data_direction == DMA_TO_DEVICE) {
printk(KERN_INFO "%s Conflict for unregistered nexus"
" %s CDB: 0x%02x to %s reservation\n",
transport_dump_cmd_direction(cmd),
se_sess->se_node_acl->initiatorname, cdb[0],
core_scsi3_pr_dump_type(pr_reg_type));
return 1;
} else {
#if 0
if (!(registered_nexus)) {
printk(KERN_INFO "Allowing implict CDB: 0x%02x"
" for %s reservation on unregistered"
" nexus\n", cdb[0],
core_scsi3_pr_dump_type(pr_reg_type));
}
#endif
return 0;
}
} else if ((reg_only) || (all_reg)) {
if (registered_nexus) {
#if 0
printk(KERN_INFO "Allowing implict CDB: 0x%02x for %s"
" reservation\n", cdb[0],
core_scsi3_pr_dump_type(pr_reg_type));
#endif
return 0;
}
}
printk(KERN_INFO "%s Conflict for %sregistered nexus %s CDB: 0x%2x"
" for %s reservation\n", transport_dump_cmd_direction(cmd),
(registered_nexus) ? "" : "un",
se_sess->se_node_acl->initiatorname, cdb[0],
core_scsi3_pr_dump_type(pr_reg_type));
return 1;
}
static u32 core_scsi3_pr_generation(struct se_device *dev)
{
struct se_subsystem_dev *su_dev = SU_DEV(dev);
u32 prg;
spin_lock(&dev->dev_reservation_lock);
prg = T10_RES(su_dev)->pr_generation++;
spin_unlock(&dev->dev_reservation_lock);
return prg;
}
static int core_scsi3_pr_reservation_check(
struct se_cmd *cmd,
u32 *pr_reg_type)
{
struct se_device *dev = cmd->se_dev;
struct se_session *sess = cmd->se_sess;
int ret;
if (!(sess))
return 0;
if (dev->dev_flags & DF_SPC2_RESERVATIONS)
return core_scsi2_reservation_check(cmd, pr_reg_type);
spin_lock(&dev->dev_reservation_lock);
if (!(dev->dev_pr_res_holder)) {
spin_unlock(&dev->dev_reservation_lock);
return 0;
}
*pr_reg_type = dev->dev_pr_res_holder->pr_res_type;
cmd->pr_res_key = dev->dev_pr_res_holder->pr_res_key;
if (dev->dev_pr_res_holder->pr_reg_nacl != sess->se_node_acl) {
spin_unlock(&dev->dev_reservation_lock);
return -1;
}
if (!(dev->dev_pr_res_holder->isid_present_at_reg)) {
spin_unlock(&dev->dev_reservation_lock);
return 0;
}
ret = (dev->dev_pr_res_holder->pr_reg_bin_isid ==
sess->sess_bin_isid) ? 0 : -1;
if (ret != 0)
*pr_reg_type |= 0x80000000;
spin_unlock(&dev->dev_reservation_lock);
return ret;
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
struct se_subsystem_dev *su_dev = SU_DEV(dev);
struct t10_pr_registration *pr_reg;
pr_reg = kmem_cache_zalloc(t10_pr_reg_cache, GFP_ATOMIC);
if (!(pr_reg)) {
printk(KERN_ERR "Unable to allocate struct t10_pr_registration\n");
return NULL;
}
pr_reg->pr_aptpl_buf = kzalloc(T10_RES(su_dev)->pr_aptpl_buf_len,
GFP_ATOMIC);
if (!(pr_reg->pr_aptpl_buf)) {
printk(KERN_ERR "Unable to allocate pr_reg->pr_aptpl_buf\n");
kmem_cache_free(t10_pr_reg_cache, pr_reg);
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
if (!(pr_reg))
return NULL;
if (!(all_tg_pt))
return pr_reg;
spin_lock(&dev->se_port_lock);
list_for_each_entry_safe(port, port_tmp, &dev->dev_sep_list, sep_list) {
atomic_inc(&port->sep_tg_pt_ref_cnt);
smp_mb__after_atomic_inc();
spin_unlock(&dev->se_port_lock);
spin_lock_bh(&port->sep_alua_lock);
list_for_each_entry(deve_tmp, &port->sep_alua_list,
alua_port_list) {
if (!(deve_tmp->se_lun_acl))
continue;
nacl_tmp = deve_tmp->se_lun_acl->se_lun_nacl;
if (nacl == nacl_tmp)
continue;
if (tfo != nacl_tmp->se_tpg->se_tpg_tfo)
continue;
if (strcmp(nacl->initiatorname, nacl_tmp->initiatorname))
continue;
atomic_inc(&deve_tmp->pr_ref_count);
smp_mb__after_atomic_inc();
spin_unlock_bh(&port->sep_alua_lock);
ret = core_scsi3_lunacl_depend_item(deve_tmp);
if (ret < 0) {
printk(KERN_ERR "core_scsi3_lunacl_depend"
"_item() failed\n");
atomic_dec(&port->sep_tg_pt_ref_cnt);
smp_mb__after_atomic_dec();
atomic_dec(&deve_tmp->pr_ref_count);
smp_mb__after_atomic_dec();
goto out;
}
pr_reg_atp = __core_scsi3_do_alloc_registration(dev,
nacl_tmp, deve_tmp, NULL,
sa_res_key, all_tg_pt, aptpl);
if (!(pr_reg_atp)) {
atomic_dec(&port->sep_tg_pt_ref_cnt);
smp_mb__after_atomic_dec();
atomic_dec(&deve_tmp->pr_ref_count);
smp_mb__after_atomic_dec();
core_scsi3_lunacl_undepend_item(deve_tmp);
goto out;
}
list_add_tail(&pr_reg_atp->pr_reg_atp_mem_list,
&pr_reg->pr_reg_atp_list);
spin_lock_bh(&port->sep_alua_lock);
}
spin_unlock_bh(&port->sep_alua_lock);
spin_lock(&dev->se_port_lock);
atomic_dec(&port->sep_tg_pt_ref_cnt);
smp_mb__after_atomic_dec();
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
struct t10_reservation_template *pr_tmpl,
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
if (!(i_port) || !(t_port) || !(sa_res_key)) {
printk(KERN_ERR "Illegal parameters for APTPL registration\n");
return -1;
}
pr_reg = kmem_cache_zalloc(t10_pr_reg_cache, GFP_KERNEL);
if (!(pr_reg)) {
printk(KERN_ERR "Unable to allocate struct t10_pr_registration\n");
return -1;
}
pr_reg->pr_aptpl_buf = kzalloc(pr_tmpl->pr_aptpl_buf_len, GFP_KERNEL);
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
printk(KERN_INFO "SPC-3 PR APTPL Successfully added registration%s from"
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
int prf_isid;
memset(i_buf, 0, PR_REG_ISID_ID_LEN);
prf_isid = core_pr_dump_initiator_port(pr_reg, &i_buf[0],
PR_REG_ISID_ID_LEN);
spin_lock(&dev->dev_reservation_lock);
dev->dev_pr_res_holder = pr_reg;
spin_unlock(&dev->dev_reservation_lock);
printk(KERN_INFO "SPC-3 PR [%s] Service Action: APTPL RESERVE created"
" new reservation holder TYPE: %s ALL_TG_PT: %d\n",
TPG_TFO(tpg)->get_fabric_name(),
core_scsi3_pr_dump_type(pr_reg->pr_res_type),
(pr_reg->pr_reg_all_tg_pt) ? 1 : 0);
printk(KERN_INFO "SPC-3 PR [%s] RESERVE Node: %s%s\n",
TPG_TFO(tpg)->get_fabric_name(), node_acl->initiatorname,
(prf_isid) ? &i_buf[0] : "");
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
struct t10_reservation_template *pr_tmpl = &SU_DEV(dev)->t10_reservation;
unsigned char i_port[PR_APTPL_MAX_IPORT_LEN];
unsigned char t_port[PR_APTPL_MAX_TPORT_LEN];
u16 tpgt;
memset(i_port, 0, PR_APTPL_MAX_IPORT_LEN);
memset(t_port, 0, PR_APTPL_MAX_TPORT_LEN);
snprintf(i_port, PR_APTPL_MAX_IPORT_LEN, "%s", nacl->initiatorname);
snprintf(t_port, PR_APTPL_MAX_TPORT_LEN, "%s",
TPG_TFO(tpg)->tpg_get_wwn(tpg));
tpgt = TPG_TFO(tpg)->tpg_get_tag(tpg);
spin_lock(&pr_tmpl->aptpl_reg_lock);
list_for_each_entry_safe(pr_reg, pr_reg_tmp, &pr_tmpl->aptpl_reg_list,
pr_reg_aptpl_list) {
if (!(strcmp(pr_reg->pr_iport, i_port)) &&
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
struct se_lun_acl *lun_acl)
{
struct se_subsystem_dev *su_dev = SU_DEV(dev);
struct se_node_acl *nacl = lun_acl->se_lun_nacl;
struct se_dev_entry *deve = &nacl->device_list[lun_acl->mapped_lun];
if (T10_RES(su_dev)->res_type != SPC3_PERSISTENT_RESERVATIONS)
return 0;
return __core_scsi3_check_aptpl_registration(dev, tpg, lun,
lun->unpacked_lun, nacl, deve);
}
static void __core_scsi3_dump_registration(
struct target_core_fabric_ops *tfo,
struct se_device *dev,
struct se_node_acl *nacl,
struct t10_pr_registration *pr_reg,
int register_type)
{
struct se_portal_group *se_tpg = nacl->se_tpg;
char i_buf[PR_REG_ISID_ID_LEN];
int prf_isid;
memset(&i_buf[0], 0, PR_REG_ISID_ID_LEN);
prf_isid = core_pr_dump_initiator_port(pr_reg, &i_buf[0],
PR_REG_ISID_ID_LEN);
printk(KERN_INFO "SPC-3 PR [%s] Service Action: REGISTER%s Initiator"
" Node: %s%s\n", tfo->get_fabric_name(), (register_type == 2) ?
"_AND_MOVE" : (register_type == 1) ?
"_AND_IGNORE_EXISTING_KEY" : "", nacl->initiatorname,
(prf_isid) ? i_buf : "");
printk(KERN_INFO "SPC-3 PR [%s] registration on Target Port: %s,0x%04x\n",
tfo->get_fabric_name(), tfo->tpg_get_wwn(se_tpg),
tfo->tpg_get_tag(se_tpg));
printk(KERN_INFO "SPC-3 PR [%s] for %s TCM Subsystem %s Object Target"
" Port(s)\n", tfo->get_fabric_name(),
(pr_reg->pr_reg_all_tg_pt) ? "ALL" : "SINGLE",
TRANSPORT(dev)->name);
printk(KERN_INFO "SPC-3 PR [%s] SA Res Key: 0x%016Lx PRgeneration:"
" 0x%08x APTPL: %d\n", tfo->get_fabric_name(),
pr_reg->pr_res_key, pr_reg->pr_res_generation,
pr_reg->pr_reg_aptpl);
}
static void __core_scsi3_add_registration(
struct se_device *dev,
struct se_node_acl *nacl,
struct t10_pr_registration *pr_reg,
int register_type,
int register_move)
{
struct se_subsystem_dev *su_dev = SU_DEV(dev);
struct target_core_fabric_ops *tfo = nacl->se_tpg->se_tpg_tfo;
struct t10_pr_registration *pr_reg_tmp, *pr_reg_tmp_safe;
struct t10_reservation_template *pr_tmpl = &SU_DEV(dev)->t10_reservation;
pr_reg->pr_res_generation = (register_move) ?
T10_RES(su_dev)->pr_generation++ :
core_scsi3_pr_generation(dev);
spin_lock(&pr_tmpl->registration_lock);
list_add_tail(&pr_reg->pr_reg_list, &pr_tmpl->registration_list);
pr_reg->pr_reg_deve->def_pr_registered = 1;
__core_scsi3_dump_registration(tfo, dev, nacl, pr_reg, register_type);
spin_unlock(&pr_tmpl->registration_lock);
if (!(pr_reg->pr_reg_all_tg_pt) || (register_move))
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
int register_type,
int register_move)
{
struct t10_pr_registration *pr_reg;
pr_reg = __core_scsi3_alloc_registration(dev, nacl, deve, isid,
sa_res_key, all_tg_pt, aptpl);
if (!(pr_reg))
return -1;
__core_scsi3_add_registration(dev, nacl, pr_reg,
register_type, register_move);
return 0;
}
static struct t10_pr_registration *__core_scsi3_locate_pr_reg(
struct se_device *dev,
struct se_node_acl *nacl,
unsigned char *isid)
{
struct t10_reservation_template *pr_tmpl = &SU_DEV(dev)->t10_reservation;
struct t10_pr_registration *pr_reg, *pr_reg_tmp;
struct se_portal_group *tpg;
spin_lock(&pr_tmpl->registration_lock);
list_for_each_entry_safe(pr_reg, pr_reg_tmp,
&pr_tmpl->registration_list, pr_reg_list) {
if (pr_reg->pr_reg_nacl != nacl)
continue;
tpg = pr_reg->pr_reg_nacl->se_tpg;
if (!(pr_reg->isid_present_at_reg)) {
if (TPG_TFO(tpg)->sess_get_initiator_sid != NULL) {
if (DEV_ATTRIB(dev)->enforce_pr_isids)
continue;
}
atomic_inc(&pr_reg->pr_res_holders);
smp_mb__after_atomic_inc();
spin_unlock(&pr_tmpl->registration_lock);
return pr_reg;
}
if (!(isid))
continue;
if (strcmp(isid, pr_reg->pr_reg_isid))
continue;
atomic_inc(&pr_reg->pr_res_holders);
smp_mb__after_atomic_inc();
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
if (TPG_TFO(tpg)->sess_get_initiator_sid != NULL) {
memset(&buf[0], 0, PR_REG_ISID_LEN);
TPG_TFO(tpg)->sess_get_initiator_sid(sess, &buf[0],
PR_REG_ISID_LEN);
isid_ptr = &buf[0];
}
return __core_scsi3_locate_pr_reg(dev, nacl, isid_ptr);
}
static void core_scsi3_put_pr_reg(struct t10_pr_registration *pr_reg)
{
atomic_dec(&pr_reg->pr_res_holders);
smp_mb__after_atomic_dec();
}
static int core_scsi3_check_implict_release(
struct se_device *dev,
struct t10_pr_registration *pr_reg)
{
struct se_node_acl *nacl = pr_reg->pr_reg_nacl;
struct t10_pr_registration *pr_res_holder;
int ret = 0;
spin_lock(&dev->dev_reservation_lock);
pr_res_holder = dev->dev_pr_res_holder;
if (!(pr_res_holder)) {
spin_unlock(&dev->dev_reservation_lock);
return ret;
}
if (pr_res_holder == pr_reg) {
__core_scsi3_complete_pro_release(dev, nacl, pr_reg, 0);
ret = 1;
} else if (pr_reg->pr_reg_all_tg_pt &&
(!strcmp(pr_res_holder->pr_reg_nacl->initiatorname,
pr_reg->pr_reg_nacl->initiatorname)) &&
(pr_res_holder->pr_res_key == pr_reg->pr_res_key)) {
printk(KERN_ERR "SPC-3 PR: Unable to perform ALL_TG_PT=1"
" UNREGISTER while existing reservation with matching"
" key 0x%016Lx is present from another SCSI Initiator"
" Port\n", pr_reg->pr_res_key);
ret = -1;
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
struct t10_reservation_template *pr_tmpl = &SU_DEV(dev)->t10_reservation;
char i_buf[PR_REG_ISID_ID_LEN];
int prf_isid;
memset(i_buf, 0, PR_REG_ISID_ID_LEN);
prf_isid = core_pr_dump_initiator_port(pr_reg, &i_buf[0],
PR_REG_ISID_ID_LEN);
pr_reg->pr_reg_deve->def_pr_registered = 0;
pr_reg->pr_reg_deve->pr_res_key = 0;
list_del(&pr_reg->pr_reg_list);
if (dec_holders)
core_scsi3_put_pr_reg(pr_reg);
while (atomic_read(&pr_reg->pr_res_holders) != 0) {
spin_unlock(&pr_tmpl->registration_lock);
printk("SPC-3 PR [%s] waiting for pr_res_holders\n",
tfo->get_fabric_name());
cpu_relax();
spin_lock(&pr_tmpl->registration_lock);
}
printk(KERN_INFO "SPC-3 PR [%s] Service Action: UNREGISTER Initiator"
" Node: %s%s\n", tfo->get_fabric_name(),
pr_reg->pr_reg_nacl->initiatorname,
(prf_isid) ? &i_buf[0] : "");
printk(KERN_INFO "SPC-3 PR [%s] for %s TCM Subsystem %s Object Target"
" Port(s)\n", tfo->get_fabric_name(),
(pr_reg->pr_reg_all_tg_pt) ? "ALL" : "SINGLE",
TRANSPORT(dev)->name);
printk(KERN_INFO "SPC-3 PR [%s] SA Res Key: 0x%016Lx PRgeneration:"
" 0x%08x\n", tfo->get_fabric_name(), pr_reg->pr_res_key,
pr_reg->pr_res_generation);
if (!(preempt_and_abort_list)) {
pr_reg->pr_reg_deve = NULL;
pr_reg->pr_reg_nacl = NULL;
kfree(pr_reg->pr_aptpl_buf);
kmem_cache_free(t10_pr_reg_cache, pr_reg);
return;
}
list_add_tail(&pr_reg->pr_reg_abort_list, preempt_and_abort_list);
}
void core_scsi3_free_pr_reg_from_nacl(
struct se_device *dev,
struct se_node_acl *nacl)
{
struct t10_reservation_template *pr_tmpl = &SU_DEV(dev)->t10_reservation;
struct t10_pr_registration *pr_reg, *pr_reg_tmp, *pr_res_holder;
spin_lock(&dev->dev_reservation_lock);
pr_res_holder = dev->dev_pr_res_holder;
if ((pr_res_holder != NULL) &&
(pr_res_holder->pr_reg_nacl == nacl))
__core_scsi3_complete_pro_release(dev, nacl, pr_res_holder, 0);
spin_unlock(&dev->dev_reservation_lock);
spin_lock(&pr_tmpl->registration_lock);
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
struct t10_reservation_template *pr_tmpl = &SU_DEV(dev)->t10_reservation;
struct t10_pr_registration *pr_reg, *pr_reg_tmp, *pr_res_holder;
spin_lock(&dev->dev_reservation_lock);
pr_res_holder = dev->dev_pr_res_holder;
if (pr_res_holder != NULL) {
struct se_node_acl *pr_res_nacl = pr_res_holder->pr_reg_nacl;
__core_scsi3_complete_pro_release(dev, pr_res_nacl,
pr_res_holder, 0);
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
kfree(pr_reg->pr_aptpl_buf);
kmem_cache_free(t10_pr_reg_cache, pr_reg);
}
spin_unlock(&pr_tmpl->aptpl_reg_lock);
}
static int core_scsi3_tpg_depend_item(struct se_portal_group *tpg)
{
return configfs_depend_item(TPG_TFO(tpg)->tf_subsys,
&tpg->tpg_group.cg_item);
}
static void core_scsi3_tpg_undepend_item(struct se_portal_group *tpg)
{
configfs_undepend_item(TPG_TFO(tpg)->tf_subsys,
&tpg->tpg_group.cg_item);
atomic_dec(&tpg->tpg_pr_ref_count);
smp_mb__after_atomic_dec();
}
static int core_scsi3_nodeacl_depend_item(struct se_node_acl *nacl)
{
struct se_portal_group *tpg = nacl->se_tpg;
if (nacl->dynamic_node_acl)
return 0;
return configfs_depend_item(TPG_TFO(tpg)->tf_subsys,
&nacl->acl_group.cg_item);
}
static void core_scsi3_nodeacl_undepend_item(struct se_node_acl *nacl)
{
struct se_portal_group *tpg = nacl->se_tpg;
if (nacl->dynamic_node_acl) {
atomic_dec(&nacl->acl_pr_ref_count);
smp_mb__after_atomic_dec();
return;
}
configfs_undepend_item(TPG_TFO(tpg)->tf_subsys,
&nacl->acl_group.cg_item);
atomic_dec(&nacl->acl_pr_ref_count);
smp_mb__after_atomic_dec();
}
static int core_scsi3_lunacl_depend_item(struct se_dev_entry *se_deve)
{
struct se_lun_acl *lun_acl = se_deve->se_lun_acl;
struct se_node_acl *nacl;
struct se_portal_group *tpg;
if (!(lun_acl))
return 0;
nacl = lun_acl->se_lun_nacl;
tpg = nacl->se_tpg;
return configfs_depend_item(TPG_TFO(tpg)->tf_subsys,
&lun_acl->se_lun_group.cg_item);
}
static void core_scsi3_lunacl_undepend_item(struct se_dev_entry *se_deve)
{
struct se_lun_acl *lun_acl = se_deve->se_lun_acl;
struct se_node_acl *nacl;
struct se_portal_group *tpg;
if (!(lun_acl)) {
atomic_dec(&se_deve->pr_ref_count);
smp_mb__after_atomic_dec();
return;
}
nacl = lun_acl->se_lun_nacl;
tpg = nacl->se_tpg;
configfs_undepend_item(TPG_TFO(tpg)->tf_subsys,
&lun_acl->se_lun_group.cg_item);
atomic_dec(&se_deve->pr_ref_count);
smp_mb__after_atomic_dec();
}
static int core_scsi3_decode_spec_i_port(
struct se_cmd *cmd,
struct se_portal_group *tpg,
unsigned char *l_isid,
u64 sa_res_key,
int all_tg_pt,
int aptpl)
{
struct se_device *dev = SE_DEV(cmd);
struct se_port *tmp_port;
struct se_portal_group *dest_tpg = NULL, *tmp_tpg;
struct se_session *se_sess = SE_SESS(cmd);
struct se_node_acl *dest_node_acl = NULL;
struct se_dev_entry *dest_se_deve = NULL, *local_se_deve;
struct t10_pr_registration *dest_pr_reg, *local_pr_reg, *pr_reg_e;
struct t10_pr_registration *pr_reg_tmp, *pr_reg_tmp_safe;
struct list_head tid_dest_list;
struct pr_transport_id_holder *tidh_new, *tidh, *tidh_tmp;
struct target_core_fabric_ops *tmp_tf_ops;
unsigned char *buf = (unsigned char *)T_TASK(cmd)->t_task_buf;
unsigned char *ptr, *i_str = NULL, proto_ident, tmp_proto_ident;
char *iport_ptr = NULL, dest_iport[64], i_buf[PR_REG_ISID_ID_LEN];
u32 tpdl, tid_len = 0;
int ret, dest_local_nexus, prf_isid;
u32 dest_rtpi = 0;
memset(dest_iport, 0, 64);
INIT_LIST_HEAD(&tid_dest_list);
local_se_deve = &se_sess->se_node_acl->device_list[cmd->orig_fe_lun];
tidh_new = kzalloc(sizeof(struct pr_transport_id_holder), GFP_KERNEL);
if (!(tidh_new)) {
printk(KERN_ERR "Unable to allocate tidh_new\n");
return PYX_TRANSPORT_LU_COMM_FAILURE;
}
INIT_LIST_HEAD(&tidh_new->dest_list);
tidh_new->dest_tpg = tpg;
tidh_new->dest_node_acl = se_sess->se_node_acl;
tidh_new->dest_se_deve = local_se_deve;
local_pr_reg = __core_scsi3_alloc_registration(SE_DEV(cmd),
se_sess->se_node_acl, local_se_deve, l_isid,
sa_res_key, all_tg_pt, aptpl);
if (!(local_pr_reg)) {
kfree(tidh_new);
return PYX_TRANSPORT_LU_COMM_FAILURE;
}
tidh_new->dest_pr_reg = local_pr_reg;
tidh_new->dest_local_nexus = 1;
list_add_tail(&tidh_new->dest_list, &tid_dest_list);
tpdl = (buf[24] & 0xff) << 24;
tpdl |= (buf[25] & 0xff) << 16;
tpdl |= (buf[26] & 0xff) << 8;
tpdl |= buf[27] & 0xff;
if ((tpdl + 28) != cmd->data_length) {
printk(KERN_ERR "SPC-3 PR: Illegal tpdl: %u + 28 byte header"
" does not equal CDB data_length: %u\n", tpdl,
cmd->data_length);
ret = PYX_TRANSPORT_INVALID_PARAMETER_LIST;
goto out;
}
ptr = &buf[28];
while (tpdl > 0) {
proto_ident = (ptr[0] & 0x0f);
dest_tpg = NULL;
spin_lock(&dev->se_port_lock);
list_for_each_entry(tmp_port, &dev->dev_sep_list, sep_list) {
tmp_tpg = tmp_port->sep_tpg;
if (!(tmp_tpg))
continue;
tmp_tf_ops = TPG_TFO(tmp_tpg);
if (!(tmp_tf_ops))
continue;
if (!(tmp_tf_ops->get_fabric_proto_ident) ||
!(tmp_tf_ops->tpg_parse_pr_out_transport_id))
continue;
tmp_proto_ident = tmp_tf_ops->get_fabric_proto_ident(tmp_tpg);
if (tmp_proto_ident != proto_ident)
continue;
dest_rtpi = tmp_port->sep_rtpi;
i_str = tmp_tf_ops->tpg_parse_pr_out_transport_id(
tmp_tpg, (const char *)ptr, &tid_len,
&iport_ptr);
if (!(i_str))
continue;
atomic_inc(&tmp_tpg->tpg_pr_ref_count);
smp_mb__after_atomic_inc();
spin_unlock(&dev->se_port_lock);
ret = core_scsi3_tpg_depend_item(tmp_tpg);
if (ret != 0) {
printk(KERN_ERR " core_scsi3_tpg_depend_item()"
" for tmp_tpg\n");
atomic_dec(&tmp_tpg->tpg_pr_ref_count);
smp_mb__after_atomic_dec();
ret = PYX_TRANSPORT_LU_COMM_FAILURE;
goto out;
}
spin_lock_bh(&tmp_tpg->acl_node_lock);
dest_node_acl = __core_tpg_get_initiator_node_acl(
tmp_tpg, i_str);
if (dest_node_acl) {
atomic_inc(&dest_node_acl->acl_pr_ref_count);
smp_mb__after_atomic_inc();
}
spin_unlock_bh(&tmp_tpg->acl_node_lock);
if (!(dest_node_acl)) {
core_scsi3_tpg_undepend_item(tmp_tpg);
spin_lock(&dev->se_port_lock);
continue;
}
ret = core_scsi3_nodeacl_depend_item(dest_node_acl);
if (ret != 0) {
printk(KERN_ERR "configfs_depend_item() failed"
" for dest_node_acl->acl_group\n");
atomic_dec(&dest_node_acl->acl_pr_ref_count);
smp_mb__after_atomic_dec();
core_scsi3_tpg_undepend_item(tmp_tpg);
ret = PYX_TRANSPORT_LU_COMM_FAILURE;
goto out;
}
dest_tpg = tmp_tpg;
printk(KERN_INFO "SPC-3 PR SPEC_I_PT: Located %s Node:"
" %s Port RTPI: %hu\n",
TPG_TFO(dest_tpg)->get_fabric_name(),
dest_node_acl->initiatorname, dest_rtpi);
spin_lock(&dev->se_port_lock);
break;
}
spin_unlock(&dev->se_port_lock);
if (!(dest_tpg)) {
printk(KERN_ERR "SPC-3 PR SPEC_I_PT: Unable to locate"
" dest_tpg\n");
ret = PYX_TRANSPORT_INVALID_PARAMETER_LIST;
goto out;
}
#if 0
printk("SPC-3 PR SPEC_I_PT: Got %s data_length: %u tpdl: %u"
" tid_len: %d for %s + %s\n",
TPG_TFO(dest_tpg)->get_fabric_name(), cmd->data_length,
tpdl, tid_len, i_str, iport_ptr);
#endif
if (tid_len > tpdl) {
printk(KERN_ERR "SPC-3 PR SPEC_I_PT: Illegal tid_len:"
" %u for Transport ID: %s\n", tid_len, ptr);
core_scsi3_nodeacl_undepend_item(dest_node_acl);
core_scsi3_tpg_undepend_item(dest_tpg);
ret = PYX_TRANSPORT_INVALID_PARAMETER_LIST;
goto out;
}
dest_se_deve = core_get_se_deve_from_rtpi(dest_node_acl,
dest_rtpi);
if (!(dest_se_deve)) {
printk(KERN_ERR "Unable to locate %s dest_se_deve"
" from destination RTPI: %hu\n",
TPG_TFO(dest_tpg)->get_fabric_name(),
dest_rtpi);
core_scsi3_nodeacl_undepend_item(dest_node_acl);
core_scsi3_tpg_undepend_item(dest_tpg);
ret = PYX_TRANSPORT_INVALID_PARAMETER_LIST;
goto out;
}
ret = core_scsi3_lunacl_depend_item(dest_se_deve);
if (ret < 0) {
printk(KERN_ERR "core_scsi3_lunacl_depend_item()"
" failed\n");
atomic_dec(&dest_se_deve->pr_ref_count);
smp_mb__after_atomic_dec();
core_scsi3_nodeacl_undepend_item(dest_node_acl);
core_scsi3_tpg_undepend_item(dest_tpg);
ret = PYX_TRANSPORT_LU_COMM_FAILURE;
goto out;
}
#if 0
printk(KERN_INFO "SPC-3 PR SPEC_I_PT: Located %s Node: %s"
" dest_se_deve mapped_lun: %u\n",
TPG_TFO(dest_tpg)->get_fabric_name(),
dest_node_acl->initiatorname, dest_se_deve->mapped_lun);
#endif
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
if (!(tidh_new)) {
printk(KERN_ERR "Unable to allocate tidh_new\n");
core_scsi3_lunacl_undepend_item(dest_se_deve);
core_scsi3_nodeacl_undepend_item(dest_node_acl);
core_scsi3_tpg_undepend_item(dest_tpg);
ret = PYX_TRANSPORT_LU_COMM_FAILURE;
goto out;
}
INIT_LIST_HEAD(&tidh_new->dest_list);
tidh_new->dest_tpg = dest_tpg;
tidh_new->dest_node_acl = dest_node_acl;
tidh_new->dest_se_deve = dest_se_deve;
dest_pr_reg = __core_scsi3_alloc_registration(SE_DEV(cmd),
dest_node_acl, dest_se_deve, iport_ptr,
sa_res_key, all_tg_pt, aptpl);
if (!(dest_pr_reg)) {
core_scsi3_lunacl_undepend_item(dest_se_deve);
core_scsi3_nodeacl_undepend_item(dest_node_acl);
core_scsi3_tpg_undepend_item(dest_tpg);
kfree(tidh_new);
ret = PYX_TRANSPORT_INVALID_PARAMETER_LIST;
goto out;
}
tidh_new->dest_pr_reg = dest_pr_reg;
list_add_tail(&tidh_new->dest_list, &tid_dest_list);
ptr += tid_len;
tpdl -= tid_len;
tid_len = 0;
}
list_for_each_entry_safe(tidh, tidh_tmp, &tid_dest_list, dest_list) {
dest_tpg = tidh->dest_tpg;
dest_node_acl = tidh->dest_node_acl;
dest_se_deve = tidh->dest_se_deve;
dest_pr_reg = tidh->dest_pr_reg;
dest_local_nexus = tidh->dest_local_nexus;
list_del(&tidh->dest_list);
kfree(tidh);
memset(i_buf, 0, PR_REG_ISID_ID_LEN);
prf_isid = core_pr_dump_initiator_port(dest_pr_reg, &i_buf[0],
PR_REG_ISID_ID_LEN);
__core_scsi3_add_registration(SE_DEV(cmd), dest_node_acl,
dest_pr_reg, 0, 0);
printk(KERN_INFO "SPC-3 PR [%s] SPEC_I_PT: Successfully"
" registered Transport ID for Node: %s%s Mapped LUN:"
" %u\n", TPG_TFO(dest_tpg)->get_fabric_name(),
dest_node_acl->initiatorname, (prf_isid) ?
&i_buf[0] : "", dest_se_deve->mapped_lun);
if (dest_local_nexus)
continue;
core_scsi3_lunacl_undepend_item(dest_se_deve);
core_scsi3_nodeacl_undepend_item(dest_node_acl);
core_scsi3_tpg_undepend_item(dest_tpg);
}
return 0;
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
kfree(dest_pr_reg->pr_aptpl_buf);
kmem_cache_free(t10_pr_reg_cache, dest_pr_reg);
if (dest_local_nexus)
continue;
core_scsi3_lunacl_undepend_item(dest_se_deve);
core_scsi3_nodeacl_undepend_item(dest_node_acl);
core_scsi3_tpg_undepend_item(dest_tpg);
}
return ret;
}
static int __core_scsi3_update_aptpl_buf(
struct se_device *dev,
unsigned char *buf,
u32 pr_aptpl_buf_len,
int clear_aptpl_metadata)
{
struct se_lun *lun;
struct se_portal_group *tpg;
struct se_subsystem_dev *su_dev = SU_DEV(dev);
struct t10_pr_registration *pr_reg;
unsigned char tmp[512], isid_buf[32];
ssize_t len = 0;
int reg_count = 0;
memset(buf, 0, pr_aptpl_buf_len);
if (clear_aptpl_metadata) {
snprintf(buf, pr_aptpl_buf_len,
"No Registrations or Reservations\n");
return 0;
}
spin_lock(&T10_RES(su_dev)->registration_lock);
list_for_each_entry(pr_reg, &T10_RES(su_dev)->registration_list,
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
TPG_TFO(tpg)->get_fabric_name(),
pr_reg->pr_reg_nacl->initiatorname, isid_buf,
pr_reg->pr_res_key, pr_reg->pr_res_type,
pr_reg->pr_res_scope, pr_reg->pr_reg_all_tg_pt,
pr_reg->pr_res_mapped_lun);
} else {
snprintf(tmp, 512, "PR_REG_START: %d\n"
"initiator_fabric=%s\ninitiator_node=%s\n%s"
"sa_res_key=%llu\nres_holder=0\n"
"res_all_tg_pt=%d\nmapped_lun=%u\n",
reg_count, TPG_TFO(tpg)->get_fabric_name(),
pr_reg->pr_reg_nacl->initiatorname, isid_buf,
pr_reg->pr_res_key, pr_reg->pr_reg_all_tg_pt,
pr_reg->pr_res_mapped_lun);
}
if ((len + strlen(tmp) >= pr_aptpl_buf_len)) {
printk(KERN_ERR "Unable to update renaming"
" APTPL metadata\n");
spin_unlock(&T10_RES(su_dev)->registration_lock);
return -1;
}
len += sprintf(buf+len, "%s", tmp);
snprintf(tmp, 512, "target_fabric=%s\ntarget_node=%s\n"
"tpgt=%hu\nport_rtpi=%hu\ntarget_lun=%u\nPR_REG_END:"
" %d\n", TPG_TFO(tpg)->get_fabric_name(),
TPG_TFO(tpg)->tpg_get_wwn(tpg),
TPG_TFO(tpg)->tpg_get_tag(tpg),
lun->lun_sep->sep_rtpi, lun->unpacked_lun, reg_count);
if ((len + strlen(tmp) >= pr_aptpl_buf_len)) {
printk(KERN_ERR "Unable to update renaming"
" APTPL metadata\n");
spin_unlock(&T10_RES(su_dev)->registration_lock);
return -1;
}
len += sprintf(buf+len, "%s", tmp);
reg_count++;
}
spin_unlock(&T10_RES(su_dev)->registration_lock);
if (!(reg_count))
len += sprintf(buf+len, "No Registrations or Reservations");
return 0;
}
static int core_scsi3_update_aptpl_buf(
struct se_device *dev,
unsigned char *buf,
u32 pr_aptpl_buf_len,
int clear_aptpl_metadata)
{
int ret;
spin_lock(&dev->dev_reservation_lock);
ret = __core_scsi3_update_aptpl_buf(dev, buf, pr_aptpl_buf_len,
clear_aptpl_metadata);
spin_unlock(&dev->dev_reservation_lock);
return ret;
}
static int __core_scsi3_write_aptpl_to_file(
struct se_device *dev,
unsigned char *buf,
u32 pr_aptpl_buf_len)
{
struct t10_wwn *wwn = &SU_DEV(dev)->t10_wwn;
struct file *file;
struct iovec iov[1];
mm_segment_t old_fs;
int flags = O_RDWR | O_CREAT | O_TRUNC;
char path[512];
int ret;
memset(iov, 0, sizeof(struct iovec));
memset(path, 0, 512);
if (strlen(&wwn->unit_serial[0]) >= 512) {
printk(KERN_ERR "WWN value for struct se_device does not fit"
" into path buffer\n");
return -1;
}
snprintf(path, 512, "/var/target/pr/aptpl_%s", &wwn->unit_serial[0]);
file = filp_open(path, flags, 0600);
if (IS_ERR(file) || !file || !file->f_dentry) {
printk(KERN_ERR "filp_open(%s) for APTPL metadata"
" failed\n", path);
return -1;
}
iov[0].iov_base = &buf[0];
if (!(pr_aptpl_buf_len))
iov[0].iov_len = (strlen(&buf[0]) + 1);
else
iov[0].iov_len = pr_aptpl_buf_len;
old_fs = get_fs();
set_fs(get_ds());
ret = vfs_writev(file, &iov[0], 1, &file->f_pos);
set_fs(old_fs);
if (ret < 0) {
printk("Error writing APTPL metadata file: %s\n", path);
filp_close(file, NULL);
return -1;
}
filp_close(file, NULL);
return 0;
}
static int core_scsi3_update_and_write_aptpl(
struct se_device *dev,
unsigned char *in_buf,
u32 in_pr_aptpl_buf_len)
{
unsigned char null_buf[64], *buf;
u32 pr_aptpl_buf_len;
int ret, clear_aptpl_metadata = 0;
if (!(in_buf)) {
memset(null_buf, 0, 64);
buf = &null_buf[0];
pr_aptpl_buf_len = 64;
clear_aptpl_metadata = 1;
} else {
buf = in_buf;
pr_aptpl_buf_len = in_pr_aptpl_buf_len;
}
ret = core_scsi3_update_aptpl_buf(dev, buf, pr_aptpl_buf_len,
clear_aptpl_metadata);
if (ret != 0)
return -1;
ret = __core_scsi3_write_aptpl_to_file(dev, buf, 0);
if (ret != 0)
return -1;
return ret;
}
static int core_scsi3_emulate_pro_register(
struct se_cmd *cmd,
u64 res_key,
u64 sa_res_key,
int aptpl,
int all_tg_pt,
int spec_i_pt,
int ignore_key)
{
struct se_session *se_sess = SE_SESS(cmd);
struct se_device *dev = SE_DEV(cmd);
struct se_dev_entry *se_deve;
struct se_lun *se_lun = SE_LUN(cmd);
struct se_portal_group *se_tpg;
struct t10_pr_registration *pr_reg, *pr_reg_p, *pr_reg_tmp, *pr_reg_e;
struct t10_reservation_template *pr_tmpl = &SU_DEV(dev)->t10_reservation;
unsigned char *pr_aptpl_buf = NULL;
unsigned char isid_buf[PR_REG_ISID_LEN], *isid_ptr = NULL;
int pr_holder = 0, ret = 0, type;
if (!(se_sess) || !(se_lun)) {
printk(KERN_ERR "SPC-3 PR: se_sess || struct se_lun is NULL!\n");
return PYX_TRANSPORT_LU_COMM_FAILURE;
}
se_tpg = se_sess->se_tpg;
se_deve = &se_sess->se_node_acl->device_list[cmd->orig_fe_lun];
if (TPG_TFO(se_tpg)->sess_get_initiator_sid != NULL) {
memset(&isid_buf[0], 0, PR_REG_ISID_LEN);
TPG_TFO(se_tpg)->sess_get_initiator_sid(se_sess, &isid_buf[0],
PR_REG_ISID_LEN);
isid_ptr = &isid_buf[0];
}
pr_reg_e = core_scsi3_locate_pr_reg(dev, se_sess->se_node_acl, se_sess);
if (!(pr_reg_e)) {
if (res_key) {
printk(KERN_WARNING "SPC-3 PR: Reservation Key non-zero"
" for SA REGISTER, returning CONFLICT\n");
return PYX_TRANSPORT_RESERVATION_CONFLICT;
}
if (!(sa_res_key))
return PYX_TRANSPORT_SENT_TO_TRANSPORT;
if (!(spec_i_pt)) {
ret = core_scsi3_alloc_registration(SE_DEV(cmd),
se_sess->se_node_acl, se_deve, isid_ptr,
sa_res_key, all_tg_pt, aptpl,
ignore_key, 0);
if (ret != 0) {
printk(KERN_ERR "Unable to allocate"
" struct t10_pr_registration\n");
return PYX_TRANSPORT_INVALID_PARAMETER_LIST;
}
} else {
ret = core_scsi3_decode_spec_i_port(cmd, se_tpg,
isid_ptr, sa_res_key, all_tg_pt, aptpl);
if (ret != 0)
return ret;
}
if (!(aptpl)) {
pr_tmpl->pr_aptpl_active = 0;
core_scsi3_update_and_write_aptpl(SE_DEV(cmd), NULL, 0);
printk("SPC-3 PR: Set APTPL Bit Deactivated for"
" REGISTER\n");
return 0;
}
pr_reg = core_scsi3_locate_pr_reg(SE_DEV(cmd),
se_sess->se_node_acl, se_sess);
ret = core_scsi3_update_and_write_aptpl(SE_DEV(cmd),
&pr_reg->pr_aptpl_buf[0],
pr_tmpl->pr_aptpl_buf_len);
if (!(ret)) {
pr_tmpl->pr_aptpl_active = 1;
printk("SPC-3 PR: Set APTPL Bit Activated for REGISTER\n");
}
core_scsi3_put_pr_reg(pr_reg);
return ret;
} else {
pr_reg = pr_reg_e;
type = pr_reg->pr_res_type;
if (!(ignore_key)) {
if (res_key != pr_reg->pr_res_key) {
printk(KERN_ERR "SPC-3 PR REGISTER: Received"
" res_key: 0x%016Lx does not match"
" existing SA REGISTER res_key:"
" 0x%016Lx\n", res_key,
pr_reg->pr_res_key);
core_scsi3_put_pr_reg(pr_reg);
return PYX_TRANSPORT_RESERVATION_CONFLICT;
}
}
if (spec_i_pt) {
printk(KERN_ERR "SPC-3 PR UNREGISTER: SPEC_I_PT"
" set while sa_res_key=0\n");
core_scsi3_put_pr_reg(pr_reg);
return PYX_TRANSPORT_INVALID_PARAMETER_LIST;
}
if (pr_reg->pr_reg_all_tg_pt && !(all_tg_pt)) {
printk(KERN_ERR "SPC-3 PR UNREGISTER: ALL_TG_PT=1"
" registration exists, but ALL_TG_PT=1 bit not"
" present in received PROUT\n");
core_scsi3_put_pr_reg(pr_reg);
return PYX_TRANSPORT_INVALID_CDB_FIELD;
}
if (aptpl) {
pr_aptpl_buf = kzalloc(pr_tmpl->pr_aptpl_buf_len,
GFP_KERNEL);
if (!(pr_aptpl_buf)) {
printk(KERN_ERR "Unable to allocate"
" pr_aptpl_buf\n");
core_scsi3_put_pr_reg(pr_reg);
return PYX_TRANSPORT_LU_COMM_FAILURE;
}
}
if (!(sa_res_key)) {
pr_holder = core_scsi3_check_implict_release(
SE_DEV(cmd), pr_reg);
if (pr_holder < 0) {
kfree(pr_aptpl_buf);
core_scsi3_put_pr_reg(pr_reg);
return PYX_TRANSPORT_RESERVATION_CONFLICT;
}
spin_lock(&pr_tmpl->registration_lock);
if (pr_reg->pr_reg_all_tg_pt) {
list_for_each_entry_safe(pr_reg_p, pr_reg_tmp,
&pr_tmpl->registration_list,
pr_reg_list) {
if (!(pr_reg_p->pr_reg_all_tg_pt))
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
__core_scsi3_free_registration(SE_DEV(cmd), pr_reg,
NULL, 1);
if (pr_holder &&
((type == PR_TYPE_WRITE_EXCLUSIVE_REGONLY) ||
(type == PR_TYPE_EXCLUSIVE_ACCESS_REGONLY))) {
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
if (!(aptpl)) {
pr_tmpl->pr_aptpl_active = 0;
core_scsi3_update_and_write_aptpl(dev, NULL, 0);
printk("SPC-3 PR: Set APTPL Bit Deactivated"
" for UNREGISTER\n");
return 0;
}
ret = core_scsi3_update_and_write_aptpl(dev,
&pr_aptpl_buf[0],
pr_tmpl->pr_aptpl_buf_len);
if (!(ret)) {
pr_tmpl->pr_aptpl_active = 1;
printk("SPC-3 PR: Set APTPL Bit Activated"
" for UNREGISTER\n");
}
kfree(pr_aptpl_buf);
return ret;
} else {
pr_reg->pr_res_generation = core_scsi3_pr_generation(
SE_DEV(cmd));
pr_reg->pr_res_key = sa_res_key;
printk("SPC-3 PR [%s] REGISTER%s: Changed Reservation"
" Key for %s to: 0x%016Lx PRgeneration:"
" 0x%08x\n", CMD_TFO(cmd)->get_fabric_name(),
(ignore_key) ? "_AND_IGNORE_EXISTING_KEY" : "",
pr_reg->pr_reg_nacl->initiatorname,
pr_reg->pr_res_key, pr_reg->pr_res_generation);
if (!(aptpl)) {
pr_tmpl->pr_aptpl_active = 0;
core_scsi3_update_and_write_aptpl(dev, NULL, 0);
core_scsi3_put_pr_reg(pr_reg);
printk("SPC-3 PR: Set APTPL Bit Deactivated"
" for REGISTER\n");
return 0;
}
ret = core_scsi3_update_and_write_aptpl(dev,
&pr_aptpl_buf[0],
pr_tmpl->pr_aptpl_buf_len);
if (!(ret)) {
pr_tmpl->pr_aptpl_active = 1;
printk("SPC-3 PR: Set APTPL Bit Activated"
" for REGISTER\n");
}
kfree(pr_aptpl_buf);
core_scsi3_put_pr_reg(pr_reg);
}
}
return 0;
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
static int core_scsi3_pro_reserve(
struct se_cmd *cmd,
struct se_device *dev,
int type,
int scope,
u64 res_key)
{
struct se_session *se_sess = SE_SESS(cmd);
struct se_dev_entry *se_deve;
struct se_lun *se_lun = SE_LUN(cmd);
struct se_portal_group *se_tpg;
struct t10_pr_registration *pr_reg, *pr_res_holder;
struct t10_reservation_template *pr_tmpl = &SU_DEV(dev)->t10_reservation;
char i_buf[PR_REG_ISID_ID_LEN];
int ret, prf_isid;
memset(i_buf, 0, PR_REG_ISID_ID_LEN);
if (!(se_sess) || !(se_lun)) {
printk(KERN_ERR "SPC-3 PR: se_sess || struct se_lun is NULL!\n");
return PYX_TRANSPORT_LU_COMM_FAILURE;
}
se_tpg = se_sess->se_tpg;
se_deve = &se_sess->se_node_acl->device_list[cmd->orig_fe_lun];
pr_reg = core_scsi3_locate_pr_reg(SE_DEV(cmd), se_sess->se_node_acl,
se_sess);
if (!(pr_reg)) {
printk(KERN_ERR "SPC-3 PR: Unable to locate"
" PR_REGISTERED *pr_reg for RESERVE\n");
return PYX_TRANSPORT_LU_COMM_FAILURE;
}
if (res_key != pr_reg->pr_res_key) {
printk(KERN_ERR "SPC-3 PR RESERVE: Received res_key: 0x%016Lx"
" does not match existing SA REGISTER res_key:"
" 0x%016Lx\n", res_key, pr_reg->pr_res_key);
core_scsi3_put_pr_reg(pr_reg);
return PYX_TRANSPORT_RESERVATION_CONFLICT;
}
if (scope != PR_SCOPE_LU_SCOPE) {
printk(KERN_ERR "SPC-3 PR: Illegal SCOPE: 0x%02x\n", scope);
core_scsi3_put_pr_reg(pr_reg);
return PYX_TRANSPORT_INVALID_PARAMETER_LIST;
}
spin_lock(&dev->dev_reservation_lock);
pr_res_holder = dev->dev_pr_res_holder;
if ((pr_res_holder)) {
if (pr_res_holder != pr_reg) {
struct se_node_acl *pr_res_nacl = pr_res_holder->pr_reg_nacl;
printk(KERN_ERR "SPC-3 PR: Attempted RESERVE from"
" [%s]: %s while reservation already held by"
" [%s]: %s, returning RESERVATION_CONFLICT\n",
CMD_TFO(cmd)->get_fabric_name(),
se_sess->se_node_acl->initiatorname,
TPG_TFO(pr_res_nacl->se_tpg)->get_fabric_name(),
pr_res_holder->pr_reg_nacl->initiatorname);
spin_unlock(&dev->dev_reservation_lock);
core_scsi3_put_pr_reg(pr_reg);
return PYX_TRANSPORT_RESERVATION_CONFLICT;
}
if ((pr_res_holder->pr_res_type != type) ||
(pr_res_holder->pr_res_scope != scope)) {
struct se_node_acl *pr_res_nacl = pr_res_holder->pr_reg_nacl;
printk(KERN_ERR "SPC-3 PR: Attempted RESERVE from"
" [%s]: %s trying to change TYPE and/or SCOPE,"
" while reservation already held by [%s]: %s,"
" returning RESERVATION_CONFLICT\n",
CMD_TFO(cmd)->get_fabric_name(),
se_sess->se_node_acl->initiatorname,
TPG_TFO(pr_res_nacl->se_tpg)->get_fabric_name(),
pr_res_holder->pr_reg_nacl->initiatorname);
spin_unlock(&dev->dev_reservation_lock);
core_scsi3_put_pr_reg(pr_reg);
return PYX_TRANSPORT_RESERVATION_CONFLICT;
}
spin_unlock(&dev->dev_reservation_lock);
core_scsi3_put_pr_reg(pr_reg);
return PYX_TRANSPORT_SENT_TO_TRANSPORT;
}
pr_reg->pr_res_scope = scope;
pr_reg->pr_res_type = type;
pr_reg->pr_res_holder = 1;
dev->dev_pr_res_holder = pr_reg;
prf_isid = core_pr_dump_initiator_port(pr_reg, &i_buf[0],
PR_REG_ISID_ID_LEN);
printk(KERN_INFO "SPC-3 PR [%s] Service Action: RESERVE created new"
" reservation holder TYPE: %s ALL_TG_PT: %d\n",
CMD_TFO(cmd)->get_fabric_name(), core_scsi3_pr_dump_type(type),
(pr_reg->pr_reg_all_tg_pt) ? 1 : 0);
printk(KERN_INFO "SPC-3 PR [%s] RESERVE Node: %s%s\n",
CMD_TFO(cmd)->get_fabric_name(),
se_sess->se_node_acl->initiatorname,
(prf_isid) ? &i_buf[0] : "");
spin_unlock(&dev->dev_reservation_lock);
if (pr_tmpl->pr_aptpl_active) {
ret = core_scsi3_update_and_write_aptpl(SE_DEV(cmd),
&pr_reg->pr_aptpl_buf[0],
pr_tmpl->pr_aptpl_buf_len);
if (!(ret))
printk(KERN_INFO "SPC-3 PR: Updated APTPL metadata"
" for RESERVE\n");
}
core_scsi3_put_pr_reg(pr_reg);
return 0;
}
static int core_scsi3_emulate_pro_reserve(
struct se_cmd *cmd,
int type,
int scope,
u64 res_key)
{
struct se_device *dev = cmd->se_dev;
int ret = 0;
switch (type) {
case PR_TYPE_WRITE_EXCLUSIVE:
case PR_TYPE_EXCLUSIVE_ACCESS:
case PR_TYPE_WRITE_EXCLUSIVE_REGONLY:
case PR_TYPE_EXCLUSIVE_ACCESS_REGONLY:
case PR_TYPE_WRITE_EXCLUSIVE_ALLREG:
case PR_TYPE_EXCLUSIVE_ACCESS_ALLREG:
ret = core_scsi3_pro_reserve(cmd, dev, type, scope, res_key);
break;
default:
printk(KERN_ERR "SPC-3 PR: Unknown Service Action RESERVE Type:"
" 0x%02x\n", type);
return PYX_TRANSPORT_INVALID_CDB_FIELD;
}
return ret;
}
static void __core_scsi3_complete_pro_release(
struct se_device *dev,
struct se_node_acl *se_nacl,
struct t10_pr_registration *pr_reg,
int explict)
{
struct target_core_fabric_ops *tfo = se_nacl->se_tpg->se_tpg_tfo;
char i_buf[PR_REG_ISID_ID_LEN];
int prf_isid;
memset(i_buf, 0, PR_REG_ISID_ID_LEN);
prf_isid = core_pr_dump_initiator_port(pr_reg, &i_buf[0],
PR_REG_ISID_ID_LEN);
dev->dev_pr_res_holder = NULL;
printk(KERN_INFO "SPC-3 PR [%s] Service Action: %s RELEASE cleared"
" reservation holder TYPE: %s ALL_TG_PT: %d\n",
tfo->get_fabric_name(), (explict) ? "explict" : "implict",
core_scsi3_pr_dump_type(pr_reg->pr_res_type),
(pr_reg->pr_reg_all_tg_pt) ? 1 : 0);
printk(KERN_INFO "SPC-3 PR [%s] RELEASE Node: %s%s\n",
tfo->get_fabric_name(), se_nacl->initiatorname,
(prf_isid) ? &i_buf[0] : "");
pr_reg->pr_res_holder = pr_reg->pr_res_type = pr_reg->pr_res_scope = 0;
}
static int core_scsi3_emulate_pro_release(
struct se_cmd *cmd,
int type,
int scope,
u64 res_key)
{
struct se_device *dev = cmd->se_dev;
struct se_session *se_sess = SE_SESS(cmd);
struct se_lun *se_lun = SE_LUN(cmd);
struct t10_pr_registration *pr_reg, *pr_reg_p, *pr_res_holder;
struct t10_reservation_template *pr_tmpl = &SU_DEV(dev)->t10_reservation;
int ret, all_reg = 0;
if (!(se_sess) || !(se_lun)) {
printk(KERN_ERR "SPC-3 PR: se_sess || struct se_lun is NULL!\n");
return PYX_TRANSPORT_LU_COMM_FAILURE;
}
pr_reg = core_scsi3_locate_pr_reg(dev, se_sess->se_node_acl, se_sess);
if (!(pr_reg)) {
printk(KERN_ERR "SPC-3 PR: Unable to locate"
" PR_REGISTERED *pr_reg for RELEASE\n");
return PYX_TRANSPORT_LU_COMM_FAILURE;
}
spin_lock(&dev->dev_reservation_lock);
pr_res_holder = dev->dev_pr_res_holder;
if (!(pr_res_holder)) {
spin_unlock(&dev->dev_reservation_lock);
core_scsi3_put_pr_reg(pr_reg);
return PYX_TRANSPORT_SENT_TO_TRANSPORT;
}
if ((pr_res_holder->pr_res_type == PR_TYPE_WRITE_EXCLUSIVE_ALLREG) ||
(pr_res_holder->pr_res_type == PR_TYPE_EXCLUSIVE_ACCESS_ALLREG))
all_reg = 1;
if ((all_reg == 0) && (pr_res_holder != pr_reg)) {
spin_unlock(&dev->dev_reservation_lock);
core_scsi3_put_pr_reg(pr_reg);
return PYX_TRANSPORT_SENT_TO_TRANSPORT;
}
if (res_key != pr_reg->pr_res_key) {
printk(KERN_ERR "SPC-3 PR RELEASE: Received res_key: 0x%016Lx"
" does not match existing SA REGISTER res_key:"
" 0x%016Lx\n", res_key, pr_reg->pr_res_key);
spin_unlock(&dev->dev_reservation_lock);
core_scsi3_put_pr_reg(pr_reg);
return PYX_TRANSPORT_RESERVATION_CONFLICT;
}
if ((pr_res_holder->pr_res_type != type) ||
(pr_res_holder->pr_res_scope != scope)) {
struct se_node_acl *pr_res_nacl = pr_res_holder->pr_reg_nacl;
printk(KERN_ERR "SPC-3 PR RELEASE: Attempted to release"
" reservation from [%s]: %s with different TYPE "
"and/or SCOPE while reservation already held by"
" [%s]: %s, returning RESERVATION_CONFLICT\n",
CMD_TFO(cmd)->get_fabric_name(),
se_sess->se_node_acl->initiatorname,
TPG_TFO(pr_res_nacl->se_tpg)->get_fabric_name(),
pr_res_holder->pr_reg_nacl->initiatorname);
spin_unlock(&dev->dev_reservation_lock);
core_scsi3_put_pr_reg(pr_reg);
return PYX_TRANSPORT_RESERVATION_CONFLICT;
}
__core_scsi3_complete_pro_release(dev, se_sess->se_node_acl,
pr_reg, 1);
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
if (pr_tmpl->pr_aptpl_active) {
ret = core_scsi3_update_and_write_aptpl(SE_DEV(cmd),
&pr_reg->pr_aptpl_buf[0],
pr_tmpl->pr_aptpl_buf_len);
if (!(ret))
printk("SPC-3 PR: Updated APTPL metadata for RELEASE\n");
}
core_scsi3_put_pr_reg(pr_reg);
return 0;
}
static int core_scsi3_emulate_pro_clear(
struct se_cmd *cmd,
u64 res_key)
{
struct se_device *dev = cmd->se_dev;
struct se_node_acl *pr_reg_nacl;
struct se_session *se_sess = SE_SESS(cmd);
struct t10_reservation_template *pr_tmpl = &SU_DEV(dev)->t10_reservation;
struct t10_pr_registration *pr_reg, *pr_reg_tmp, *pr_reg_n, *pr_res_holder;
u32 pr_res_mapped_lun = 0;
int calling_it_nexus = 0;
pr_reg_n = core_scsi3_locate_pr_reg(SE_DEV(cmd),
se_sess->se_node_acl, se_sess);
if (!(pr_reg_n)) {
printk(KERN_ERR "SPC-3 PR: Unable to locate"
" PR_REGISTERED *pr_reg for CLEAR\n");
return PYX_TRANSPORT_LU_COMM_FAILURE;
}
if (res_key != pr_reg_n->pr_res_key) {
printk(KERN_ERR "SPC-3 PR REGISTER: Received"
" res_key: 0x%016Lx does not match"
" existing SA REGISTER res_key:"
" 0x%016Lx\n", res_key, pr_reg_n->pr_res_key);
core_scsi3_put_pr_reg(pr_reg_n);
return PYX_TRANSPORT_RESERVATION_CONFLICT;
}
spin_lock(&dev->dev_reservation_lock);
pr_res_holder = dev->dev_pr_res_holder;
if (pr_res_holder) {
struct se_node_acl *pr_res_nacl = pr_res_holder->pr_reg_nacl;
__core_scsi3_complete_pro_release(dev, pr_res_nacl,
pr_res_holder, 0);
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
if (!(calling_it_nexus))
core_scsi3_ua_allocate(pr_reg_nacl, pr_res_mapped_lun,
0x2A, ASCQ_2AH_RESERVATIONS_PREEMPTED);
}
spin_unlock(&pr_tmpl->registration_lock);
printk(KERN_INFO "SPC-3 PR [%s] Service Action: CLEAR complete\n",
CMD_TFO(cmd)->get_fabric_name());
if (pr_tmpl->pr_aptpl_active) {
core_scsi3_update_and_write_aptpl(SE_DEV(cmd), NULL, 0);
printk(KERN_INFO "SPC-3 PR: Updated APTPL metadata"
" for CLEAR\n");
}
core_scsi3_pr_generation(dev);
return 0;
}
static void __core_scsi3_complete_pro_preempt(
struct se_device *dev,
struct t10_pr_registration *pr_reg,
struct list_head *preempt_and_abort_list,
int type,
int scope,
int abort)
{
struct se_node_acl *nacl = pr_reg->pr_reg_nacl;
struct target_core_fabric_ops *tfo = nacl->se_tpg->se_tpg_tfo;
char i_buf[PR_REG_ISID_ID_LEN];
int prf_isid;
memset(i_buf, 0, PR_REG_ISID_ID_LEN);
prf_isid = core_pr_dump_initiator_port(pr_reg, &i_buf[0],
PR_REG_ISID_ID_LEN);
if (dev->dev_pr_res_holder)
__core_scsi3_complete_pro_release(dev, nacl,
dev->dev_pr_res_holder, 0);
dev->dev_pr_res_holder = pr_reg;
pr_reg->pr_res_holder = 1;
pr_reg->pr_res_type = type;
pr_reg->pr_res_scope = scope;
printk(KERN_INFO "SPC-3 PR [%s] Service Action: PREEMPT%s created new"
" reservation holder TYPE: %s ALL_TG_PT: %d\n",
tfo->get_fabric_name(), (abort) ? "_AND_ABORT" : "",
core_scsi3_pr_dump_type(type),
(pr_reg->pr_reg_all_tg_pt) ? 1 : 0);
printk(KERN_INFO "SPC-3 PR [%s] PREEMPT%s from Node: %s%s\n",
tfo->get_fabric_name(), (abort) ? "_AND_ABORT" : "",
nacl->initiatorname, (prf_isid) ? &i_buf[0] : "");
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
printk(KERN_WARNING "pr_reg->pr_res_holder still set\n");
continue;
}
pr_reg->pr_reg_deve = NULL;
pr_reg->pr_reg_nacl = NULL;
kfree(pr_reg->pr_aptpl_buf);
kmem_cache_free(t10_pr_reg_cache, pr_reg);
}
}
int core_scsi3_check_cdb_abort_and_preempt(
struct list_head *preempt_and_abort_list,
struct se_cmd *cmd)
{
struct t10_pr_registration *pr_reg, *pr_reg_tmp;
list_for_each_entry_safe(pr_reg, pr_reg_tmp, preempt_and_abort_list,
pr_reg_abort_list) {
if (pr_reg->pr_res_key == cmd->pr_res_key)
return 0;
}
return 1;
}
static int core_scsi3_pro_preempt(
struct se_cmd *cmd,
int type,
int scope,
u64 res_key,
u64 sa_res_key,
int abort)
{
struct se_device *dev = SE_DEV(cmd);
struct se_dev_entry *se_deve;
struct se_node_acl *pr_reg_nacl;
struct se_session *se_sess = SE_SESS(cmd);
struct list_head preempt_and_abort_list;
struct t10_pr_registration *pr_reg, *pr_reg_tmp, *pr_reg_n, *pr_res_holder;
struct t10_reservation_template *pr_tmpl = &SU_DEV(dev)->t10_reservation;
u32 pr_res_mapped_lun = 0;
int all_reg = 0, calling_it_nexus = 0, released_regs = 0;
int prh_type = 0, prh_scope = 0, ret;
if (!(se_sess))
return PYX_TRANSPORT_LU_COMM_FAILURE;
se_deve = &se_sess->se_node_acl->device_list[cmd->orig_fe_lun];
pr_reg_n = core_scsi3_locate_pr_reg(SE_DEV(cmd), se_sess->se_node_acl,
se_sess);
if (!(pr_reg_n)) {
printk(KERN_ERR "SPC-3 PR: Unable to locate"
" PR_REGISTERED *pr_reg for PREEMPT%s\n",
(abort) ? "_AND_ABORT" : "");
return PYX_TRANSPORT_RESERVATION_CONFLICT;
}
if (pr_reg_n->pr_res_key != res_key) {
core_scsi3_put_pr_reg(pr_reg_n);
return PYX_TRANSPORT_RESERVATION_CONFLICT;
}
if (scope != PR_SCOPE_LU_SCOPE) {
printk(KERN_ERR "SPC-3 PR: Illegal SCOPE: 0x%02x\n", scope);
core_scsi3_put_pr_reg(pr_reg_n);
return PYX_TRANSPORT_INVALID_PARAMETER_LIST;
}
INIT_LIST_HEAD(&preempt_and_abort_list);
spin_lock(&dev->dev_reservation_lock);
pr_res_holder = dev->dev_pr_res_holder;
if (pr_res_holder &&
((pr_res_holder->pr_res_type == PR_TYPE_WRITE_EXCLUSIVE_ALLREG) ||
(pr_res_holder->pr_res_type == PR_TYPE_EXCLUSIVE_ACCESS_ALLREG)))
all_reg = 1;
if (!(all_reg) && !(sa_res_key)) {
spin_unlock(&dev->dev_reservation_lock);
core_scsi3_put_pr_reg(pr_reg_n);
return PYX_TRANSPORT_INVALID_PARAMETER_LIST;
}
if (!(pr_res_holder) || (pr_res_holder->pr_res_key != sa_res_key)) {
spin_lock(&pr_tmpl->registration_lock);
list_for_each_entry_safe(pr_reg, pr_reg_tmp,
&pr_tmpl->registration_list, pr_reg_list) {
if (!(all_reg)) {
if (pr_reg->pr_res_key != sa_res_key)
continue;
calling_it_nexus = (pr_reg_n == pr_reg) ? 1 : 0;
pr_reg_nacl = pr_reg->pr_reg_nacl;
pr_res_mapped_lun = pr_reg->pr_res_mapped_lun;
__core_scsi3_free_registration(dev, pr_reg,
(abort) ? &preempt_and_abort_list :
NULL, calling_it_nexus);
released_regs++;
} else {
if ((sa_res_key) &&
(pr_reg->pr_res_key != sa_res_key))
continue;
calling_it_nexus = (pr_reg_n == pr_reg) ? 1 : 0;
if (calling_it_nexus)
continue;
pr_reg_nacl = pr_reg->pr_reg_nacl;
pr_res_mapped_lun = pr_reg->pr_res_mapped_lun;
__core_scsi3_free_registration(dev, pr_reg,
(abort) ? &preempt_and_abort_list :
NULL, 0);
released_regs++;
}
if (!(calling_it_nexus))
core_scsi3_ua_allocate(pr_reg_nacl,
pr_res_mapped_lun, 0x2A,
ASCQ_2AH_RESERVATIONS_PREEMPTED);
}
spin_unlock(&pr_tmpl->registration_lock);
if (!(released_regs)) {
spin_unlock(&dev->dev_reservation_lock);
core_scsi3_put_pr_reg(pr_reg_n);
return PYX_TRANSPORT_RESERVATION_CONFLICT;
}
if (pr_res_holder && all_reg && !(sa_res_key)) {
__core_scsi3_complete_pro_preempt(dev, pr_reg_n,
(abort) ? &preempt_and_abort_list : NULL,
type, scope, abort);
if (abort)
core_scsi3_release_preempt_and_abort(
&preempt_and_abort_list, pr_reg_n);
}
spin_unlock(&dev->dev_reservation_lock);
if (pr_tmpl->pr_aptpl_active) {
ret = core_scsi3_update_and_write_aptpl(SE_DEV(cmd),
&pr_reg_n->pr_aptpl_buf[0],
pr_tmpl->pr_aptpl_buf_len);
if (!(ret))
printk(KERN_INFO "SPC-3 PR: Updated APTPL"
" metadata for PREEMPT%s\n", (abort) ?
"_AND_ABORT" : "");
}
core_scsi3_put_pr_reg(pr_reg_n);
core_scsi3_pr_generation(SE_DEV(cmd));
return 0;
}
prh_type = pr_res_holder->pr_res_type;
prh_scope = pr_res_holder->pr_res_scope;
if (pr_reg_n != pr_res_holder)
__core_scsi3_complete_pro_release(dev,
pr_res_holder->pr_reg_nacl,
dev->dev_pr_res_holder, 0);
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
(abort) ? &preempt_and_abort_list : NULL,
calling_it_nexus);
core_scsi3_ua_allocate(pr_reg_nacl, pr_res_mapped_lun, 0x2A,
ASCQ_2AH_RESERVATIONS_PREEMPTED);
}
spin_unlock(&pr_tmpl->registration_lock);
__core_scsi3_complete_pro_preempt(dev, pr_reg_n,
(abort) ? &preempt_and_abort_list : NULL,
type, scope, abort);
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
if (abort) {
core_tmr_lun_reset(dev, NULL, &preempt_and_abort_list, cmd);
core_scsi3_release_preempt_and_abort(&preempt_and_abort_list,
pr_reg_n);
}
if (pr_tmpl->pr_aptpl_active) {
ret = core_scsi3_update_and_write_aptpl(SE_DEV(cmd),
&pr_reg_n->pr_aptpl_buf[0],
pr_tmpl->pr_aptpl_buf_len);
if (!(ret))
printk("SPC-3 PR: Updated APTPL metadata for PREEMPT"
"%s\n", (abort) ? "_AND_ABORT" : "");
}
core_scsi3_put_pr_reg(pr_reg_n);
core_scsi3_pr_generation(SE_DEV(cmd));
return 0;
}
static int core_scsi3_emulate_pro_preempt(
struct se_cmd *cmd,
int type,
int scope,
u64 res_key,
u64 sa_res_key,
int abort)
{
int ret = 0;
switch (type) {
case PR_TYPE_WRITE_EXCLUSIVE:
case PR_TYPE_EXCLUSIVE_ACCESS:
case PR_TYPE_WRITE_EXCLUSIVE_REGONLY:
case PR_TYPE_EXCLUSIVE_ACCESS_REGONLY:
case PR_TYPE_WRITE_EXCLUSIVE_ALLREG:
case PR_TYPE_EXCLUSIVE_ACCESS_ALLREG:
ret = core_scsi3_pro_preempt(cmd, type, scope,
res_key, sa_res_key, abort);
break;
default:
printk(KERN_ERR "SPC-3 PR: Unknown Service Action PREEMPT%s"
" Type: 0x%02x\n", (abort) ? "_AND_ABORT" : "", type);
return PYX_TRANSPORT_INVALID_CDB_FIELD;
}
return ret;
}
static int core_scsi3_emulate_pro_register_and_move(
struct se_cmd *cmd,
u64 res_key,
u64 sa_res_key,
int aptpl,
int unreg)
{
struct se_session *se_sess = SE_SESS(cmd);
struct se_device *dev = SE_DEV(cmd);
struct se_dev_entry *se_deve, *dest_se_deve = NULL;
struct se_lun *se_lun = SE_LUN(cmd);
struct se_node_acl *pr_res_nacl, *pr_reg_nacl, *dest_node_acl = NULL;
struct se_port *se_port;
struct se_portal_group *se_tpg, *dest_se_tpg = NULL;
struct target_core_fabric_ops *dest_tf_ops = NULL, *tf_ops;
struct t10_pr_registration *pr_reg, *pr_res_holder, *dest_pr_reg;
struct t10_reservation_template *pr_tmpl = &SU_DEV(dev)->t10_reservation;
unsigned char *buf = (unsigned char *)T_TASK(cmd)->t_task_buf;
unsigned char *initiator_str;
char *iport_ptr = NULL, dest_iport[64], i_buf[PR_REG_ISID_ID_LEN];
u32 tid_len, tmp_tid_len;
int new_reg = 0, type, scope, ret, matching_iname, prf_isid;
unsigned short rtpi;
unsigned char proto_ident;
if (!(se_sess) || !(se_lun)) {
printk(KERN_ERR "SPC-3 PR: se_sess || struct se_lun is NULL!\n");
return PYX_TRANSPORT_LU_COMM_FAILURE;
}
memset(dest_iport, 0, 64);
memset(i_buf, 0, PR_REG_ISID_ID_LEN);
se_tpg = se_sess->se_tpg;
tf_ops = TPG_TFO(se_tpg);
se_deve = &se_sess->se_node_acl->device_list[cmd->orig_fe_lun];
pr_reg = core_scsi3_locate_pr_reg(SE_DEV(cmd), se_sess->se_node_acl,
se_sess);
if (!(pr_reg)) {
printk(KERN_ERR "SPC-3 PR: Unable to locate PR_REGISTERED"
" *pr_reg for REGISTER_AND_MOVE\n");
return PYX_TRANSPORT_LU_COMM_FAILURE;
}
if (res_key != pr_reg->pr_res_key) {
printk(KERN_WARNING "SPC-3 PR REGISTER_AND_MOVE: Received"
" res_key: 0x%016Lx does not match existing SA REGISTER"
" res_key: 0x%016Lx\n", res_key, pr_reg->pr_res_key);
core_scsi3_put_pr_reg(pr_reg);
return PYX_TRANSPORT_RESERVATION_CONFLICT;
}
if (!(sa_res_key)) {
printk(KERN_WARNING "SPC-3 PR REGISTER_AND_MOVE: Received zero"
" sa_res_key\n");
core_scsi3_put_pr_reg(pr_reg);
return PYX_TRANSPORT_INVALID_PARAMETER_LIST;
}
rtpi = (buf[18] & 0xff) << 8;
rtpi |= buf[19] & 0xff;
tid_len = (buf[20] & 0xff) << 24;
tid_len |= (buf[21] & 0xff) << 16;
tid_len |= (buf[22] & 0xff) << 8;
tid_len |= buf[23] & 0xff;
if ((tid_len + 24) != cmd->data_length) {
printk(KERN_ERR "SPC-3 PR: Illegal tid_len: %u + 24 byte header"
" does not equal CDB data_length: %u\n", tid_len,
cmd->data_length);
core_scsi3_put_pr_reg(pr_reg);
return PYX_TRANSPORT_INVALID_PARAMETER_LIST;
}
spin_lock(&dev->se_port_lock);
list_for_each_entry(se_port, &dev->dev_sep_list, sep_list) {
if (se_port->sep_rtpi != rtpi)
continue;
dest_se_tpg = se_port->sep_tpg;
if (!(dest_se_tpg))
continue;
dest_tf_ops = TPG_TFO(dest_se_tpg);
if (!(dest_tf_ops))
continue;
atomic_inc(&dest_se_tpg->tpg_pr_ref_count);
smp_mb__after_atomic_inc();
spin_unlock(&dev->se_port_lock);
ret = core_scsi3_tpg_depend_item(dest_se_tpg);
if (ret != 0) {
printk(KERN_ERR "core_scsi3_tpg_depend_item() failed"
" for dest_se_tpg\n");
atomic_dec(&dest_se_tpg->tpg_pr_ref_count);
smp_mb__after_atomic_dec();
core_scsi3_put_pr_reg(pr_reg);
return PYX_TRANSPORT_LU_COMM_FAILURE;
}
spin_lock(&dev->se_port_lock);
break;
}
spin_unlock(&dev->se_port_lock);
if (!(dest_se_tpg) || (!dest_tf_ops)) {
printk(KERN_ERR "SPC-3 PR REGISTER_AND_MOVE: Unable to locate"
" fabric ops from Relative Target Port Identifier:"
" %hu\n", rtpi);
core_scsi3_put_pr_reg(pr_reg);
return PYX_TRANSPORT_INVALID_PARAMETER_LIST;
}
proto_ident = (buf[24] & 0x0f);
#if 0
printk("SPC-3 PR REGISTER_AND_MOVE: Extracted Protocol Identifier:"
" 0x%02x\n", proto_ident);
#endif
if (proto_ident != dest_tf_ops->get_fabric_proto_ident(dest_se_tpg)) {
printk(KERN_ERR "SPC-3 PR REGISTER_AND_MOVE: Received"
" proto_ident: 0x%02x does not match ident: 0x%02x"
" from fabric: %s\n", proto_ident,
dest_tf_ops->get_fabric_proto_ident(dest_se_tpg),
dest_tf_ops->get_fabric_name());
ret = PYX_TRANSPORT_INVALID_PARAMETER_LIST;
goto out;
}
if (dest_tf_ops->tpg_parse_pr_out_transport_id == NULL) {
printk(KERN_ERR "SPC-3 PR REGISTER_AND_MOVE: Fabric does not"
" containg a valid tpg_parse_pr_out_transport_id"
" function pointer\n");
ret = PYX_TRANSPORT_LU_COMM_FAILURE;
goto out;
}
initiator_str = dest_tf_ops->tpg_parse_pr_out_transport_id(dest_se_tpg,
(const char *)&buf[24], &tmp_tid_len, &iport_ptr);
if (!(initiator_str)) {
printk(KERN_ERR "SPC-3 PR REGISTER_AND_MOVE: Unable to locate"
" initiator_str from Transport ID\n");
ret = PYX_TRANSPORT_INVALID_PARAMETER_LIST;
goto out;
}
printk(KERN_INFO "SPC-3 PR [%s] Extracted initiator %s identifier: %s"
" %s\n", dest_tf_ops->get_fabric_name(), (iport_ptr != NULL) ?
"port" : "device", initiator_str, (iport_ptr != NULL) ?
iport_ptr : "");
pr_reg_nacl = pr_reg->pr_reg_nacl;
matching_iname = (!strcmp(initiator_str,
pr_reg_nacl->initiatorname)) ? 1 : 0;
if (!(matching_iname))
goto after_iport_check;
if (!(iport_ptr) || !(pr_reg->isid_present_at_reg)) {
printk(KERN_ERR "SPC-3 PR REGISTER_AND_MOVE: TransportID: %s"
" matches: %s on received I_T Nexus\n", initiator_str,
pr_reg_nacl->initiatorname);
ret = PYX_TRANSPORT_INVALID_PARAMETER_LIST;
goto out;
}
if (!(strcmp(iport_ptr, pr_reg->pr_reg_isid))) {
printk(KERN_ERR "SPC-3 PR REGISTER_AND_MOVE: TransportID: %s %s"
" matches: %s %s on received I_T Nexus\n",
initiator_str, iport_ptr, pr_reg_nacl->initiatorname,
pr_reg->pr_reg_isid);
ret = PYX_TRANSPORT_INVALID_PARAMETER_LIST;
goto out;
}
after_iport_check:
spin_lock_bh(&dest_se_tpg->acl_node_lock);
dest_node_acl = __core_tpg_get_initiator_node_acl(dest_se_tpg,
initiator_str);
if (dest_node_acl) {
atomic_inc(&dest_node_acl->acl_pr_ref_count);
smp_mb__after_atomic_inc();
}
spin_unlock_bh(&dest_se_tpg->acl_node_lock);
if (!(dest_node_acl)) {
printk(KERN_ERR "Unable to locate %s dest_node_acl for"
" TransportID%s\n", dest_tf_ops->get_fabric_name(),
initiator_str);
ret = PYX_TRANSPORT_INVALID_PARAMETER_LIST;
goto out;
}
ret = core_scsi3_nodeacl_depend_item(dest_node_acl);
if (ret != 0) {
printk(KERN_ERR "core_scsi3_nodeacl_depend_item() for"
" dest_node_acl\n");
atomic_dec(&dest_node_acl->acl_pr_ref_count);
smp_mb__after_atomic_dec();
dest_node_acl = NULL;
ret = PYX_TRANSPORT_LU_COMM_FAILURE;
goto out;
}
#if 0
printk(KERN_INFO "SPC-3 PR REGISTER_AND_MOVE: Found %s dest_node_acl:"
" %s from TransportID\n", dest_tf_ops->get_fabric_name(),
dest_node_acl->initiatorname);
#endif
dest_se_deve = core_get_se_deve_from_rtpi(dest_node_acl, rtpi);
if (!(dest_se_deve)) {
printk(KERN_ERR "Unable to locate %s dest_se_deve from RTPI:"
" %hu\n", dest_tf_ops->get_fabric_name(), rtpi);
ret = PYX_TRANSPORT_INVALID_PARAMETER_LIST;
goto out;
}
ret = core_scsi3_lunacl_depend_item(dest_se_deve);
if (ret < 0) {
printk(KERN_ERR "core_scsi3_lunacl_depend_item() failed\n");
atomic_dec(&dest_se_deve->pr_ref_count);
smp_mb__after_atomic_dec();
dest_se_deve = NULL;
ret = PYX_TRANSPORT_LU_COMM_FAILURE;
goto out;
}
#if 0
printk(KERN_INFO "SPC-3 PR REGISTER_AND_MOVE: Located %s node %s LUN"
" ACL for dest_se_deve->mapped_lun: %u\n",
dest_tf_ops->get_fabric_name(), dest_node_acl->initiatorname,
dest_se_deve->mapped_lun);
#endif
spin_lock(&dev->dev_reservation_lock);
pr_res_holder = dev->dev_pr_res_holder;
if (!(pr_res_holder)) {
printk(KERN_WARNING "SPC-3 PR REGISTER_AND_MOVE: No reservation"
" currently held\n");
spin_unlock(&dev->dev_reservation_lock);
ret = PYX_TRANSPORT_INVALID_CDB_FIELD;
goto out;
}
if (pr_res_holder != pr_reg) {
printk(KERN_WARNING "SPC-3 PR REGISTER_AND_MOVE: Calling I_T"
" Nexus is not reservation holder\n");
spin_unlock(&dev->dev_reservation_lock);
ret = PYX_TRANSPORT_RESERVATION_CONFLICT;
goto out;
}
if ((pr_res_holder->pr_res_type == PR_TYPE_WRITE_EXCLUSIVE_ALLREG) ||
(pr_res_holder->pr_res_type == PR_TYPE_EXCLUSIVE_ACCESS_ALLREG)) {
printk(KERN_WARNING "SPC-3 PR REGISTER_AND_MOVE: Unable to move"
" reservation for type: %s\n",
core_scsi3_pr_dump_type(pr_res_holder->pr_res_type));
spin_unlock(&dev->dev_reservation_lock);
ret = PYX_TRANSPORT_RESERVATION_CONFLICT;
goto out;
}
pr_res_nacl = pr_res_holder->pr_reg_nacl;
type = pr_res_holder->pr_res_type;
scope = pr_res_holder->pr_res_type;
dest_pr_reg = __core_scsi3_locate_pr_reg(dev, dest_node_acl,
iport_ptr);
if (!(dest_pr_reg)) {
ret = core_scsi3_alloc_registration(SE_DEV(cmd),
dest_node_acl, dest_se_deve, iport_ptr,
sa_res_key, 0, aptpl, 2, 1);
if (ret != 0) {
spin_unlock(&dev->dev_reservation_lock);
ret = PYX_TRANSPORT_INVALID_PARAMETER_LIST;
goto out;
}
dest_pr_reg = __core_scsi3_locate_pr_reg(dev, dest_node_acl,
iport_ptr);
new_reg = 1;
}
__core_scsi3_complete_pro_release(dev, pr_res_nacl,
dev->dev_pr_res_holder, 0);
dev->dev_pr_res_holder = dest_pr_reg;
dest_pr_reg->pr_res_holder = 1;
dest_pr_reg->pr_res_type = type;
pr_reg->pr_res_scope = scope;
prf_isid = core_pr_dump_initiator_port(pr_reg, &i_buf[0],
PR_REG_ISID_ID_LEN);
if (!(new_reg))
dest_pr_reg->pr_res_generation = pr_tmpl->pr_generation++;
spin_unlock(&dev->dev_reservation_lock);
printk(KERN_INFO "SPC-3 PR [%s] Service Action: REGISTER_AND_MOVE"
" created new reservation holder TYPE: %s on object RTPI:"
" %hu PRGeneration: 0x%08x\n", dest_tf_ops->get_fabric_name(),
core_scsi3_pr_dump_type(type), rtpi,
dest_pr_reg->pr_res_generation);
printk(KERN_INFO "SPC-3 PR Successfully moved reservation from"
" %s Fabric Node: %s%s -> %s Fabric Node: %s %s\n",
tf_ops->get_fabric_name(), pr_reg_nacl->initiatorname,
(prf_isid) ? &i_buf[0] : "", dest_tf_ops->get_fabric_name(),
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
if (!(aptpl)) {
pr_tmpl->pr_aptpl_active = 0;
core_scsi3_update_and_write_aptpl(SE_DEV(cmd), NULL, 0);
printk("SPC-3 PR: Set APTPL Bit Deactivated for"
" REGISTER_AND_MOVE\n");
} else {
pr_tmpl->pr_aptpl_active = 1;
ret = core_scsi3_update_and_write_aptpl(SE_DEV(cmd),
&dest_pr_reg->pr_aptpl_buf[0],
pr_tmpl->pr_aptpl_buf_len);
if (!(ret))
printk("SPC-3 PR: Set APTPL Bit Activated for"
" REGISTER_AND_MOVE\n");
}
core_scsi3_put_pr_reg(dest_pr_reg);
return 0;
out:
if (dest_se_deve)
core_scsi3_lunacl_undepend_item(dest_se_deve);
if (dest_node_acl)
core_scsi3_nodeacl_undepend_item(dest_node_acl);
core_scsi3_tpg_undepend_item(dest_se_tpg);
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
static int core_scsi3_emulate_pr_out(struct se_cmd *cmd, unsigned char *cdb)
{
unsigned char *buf = (unsigned char *)T_TASK(cmd)->t_task_buf;
u64 res_key, sa_res_key;
int sa, scope, type, aptpl;
int spec_i_pt = 0, all_tg_pt = 0, unreg = 0;
if (!(SE_SESS(cmd)))
return PYX_TRANSPORT_LU_COMM_FAILURE;
if (cmd->data_length < 24) {
printk(KERN_WARNING "SPC-PR: Received PR OUT parameter list"
" length too small: %u\n", cmd->data_length);
return PYX_TRANSPORT_INVALID_PARAMETER_LIST;
}
sa = (cdb[1] & 0x1f);
scope = (cdb[2] & 0xf0);
type = (cdb[2] & 0x0f);
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
if (spec_i_pt && ((cdb[1] & 0x1f) != PRO_REGISTER))
return PYX_TRANSPORT_INVALID_PARAMETER_LIST;
if (!(spec_i_pt) && ((cdb[1] & 0x1f) != PRO_REGISTER_AND_MOVE) &&
(cmd->data_length != 24)) {
printk(KERN_WARNING "SPC-PR: Received PR OUT illegal parameter"
" list length: %u\n", cmd->data_length);
return PYX_TRANSPORT_INVALID_PARAMETER_LIST;
}
switch (sa) {
case PRO_REGISTER:
return core_scsi3_emulate_pro_register(cmd,
res_key, sa_res_key, aptpl, all_tg_pt, spec_i_pt, 0);
case PRO_RESERVE:
return core_scsi3_emulate_pro_reserve(cmd,
type, scope, res_key);
case PRO_RELEASE:
return core_scsi3_emulate_pro_release(cmd,
type, scope, res_key);
case PRO_CLEAR:
return core_scsi3_emulate_pro_clear(cmd, res_key);
case PRO_PREEMPT:
return core_scsi3_emulate_pro_preempt(cmd, type, scope,
res_key, sa_res_key, 0);
case PRO_PREEMPT_AND_ABORT:
return core_scsi3_emulate_pro_preempt(cmd, type, scope,
res_key, sa_res_key, 1);
case PRO_REGISTER_AND_IGNORE_EXISTING_KEY:
return core_scsi3_emulate_pro_register(cmd,
0, sa_res_key, aptpl, all_tg_pt, spec_i_pt, 1);
case PRO_REGISTER_AND_MOVE:
return core_scsi3_emulate_pro_register_and_move(cmd, res_key,
sa_res_key, aptpl, unreg);
default:
printk(KERN_ERR "Unknown PERSISTENT_RESERVE_OUT service"
" action: 0x%02x\n", cdb[1] & 0x1f);
return PYX_TRANSPORT_INVALID_CDB_FIELD;
}
return PYX_TRANSPORT_INVALID_CDB_FIELD;
}
static int core_scsi3_pri_read_keys(struct se_cmd *cmd)
{
struct se_device *se_dev = SE_DEV(cmd);
struct se_subsystem_dev *su_dev = SU_DEV(se_dev);
struct t10_pr_registration *pr_reg;
unsigned char *buf = (unsigned char *)T_TASK(cmd)->t_task_buf;
u32 add_len = 0, off = 8;
if (cmd->data_length < 8) {
printk(KERN_ERR "PRIN SA READ_KEYS SCSI Data Length: %u"
" too small\n", cmd->data_length);
return PYX_TRANSPORT_INVALID_CDB_FIELD;
}
buf[0] = ((T10_RES(su_dev)->pr_generation >> 24) & 0xff);
buf[1] = ((T10_RES(su_dev)->pr_generation >> 16) & 0xff);
buf[2] = ((T10_RES(su_dev)->pr_generation >> 8) & 0xff);
buf[3] = (T10_RES(su_dev)->pr_generation & 0xff);
spin_lock(&T10_RES(su_dev)->registration_lock);
list_for_each_entry(pr_reg, &T10_RES(su_dev)->registration_list,
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
spin_unlock(&T10_RES(su_dev)->registration_lock);
buf[4] = ((add_len >> 24) & 0xff);
buf[5] = ((add_len >> 16) & 0xff);
buf[6] = ((add_len >> 8) & 0xff);
buf[7] = (add_len & 0xff);
return 0;
}
static int core_scsi3_pri_read_reservation(struct se_cmd *cmd)
{
struct se_device *se_dev = SE_DEV(cmd);
struct se_subsystem_dev *su_dev = SU_DEV(se_dev);
struct t10_pr_registration *pr_reg;
unsigned char *buf = (unsigned char *)T_TASK(cmd)->t_task_buf;
u64 pr_res_key;
u32 add_len = 16;
if (cmd->data_length < 8) {
printk(KERN_ERR "PRIN SA READ_RESERVATIONS SCSI Data Length: %u"
" too small\n", cmd->data_length);
return PYX_TRANSPORT_INVALID_CDB_FIELD;
}
buf[0] = ((T10_RES(su_dev)->pr_generation >> 24) & 0xff);
buf[1] = ((T10_RES(su_dev)->pr_generation >> 16) & 0xff);
buf[2] = ((T10_RES(su_dev)->pr_generation >> 8) & 0xff);
buf[3] = (T10_RES(su_dev)->pr_generation & 0xff);
spin_lock(&se_dev->dev_reservation_lock);
pr_reg = se_dev->dev_pr_res_holder;
if ((pr_reg)) {
buf[4] = ((add_len >> 24) & 0xff);
buf[5] = ((add_len >> 16) & 0xff);
buf[6] = ((add_len >> 8) & 0xff);
buf[7] = (add_len & 0xff);
if (cmd->data_length < 22) {
spin_unlock(&se_dev->dev_reservation_lock);
return 0;
}
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
spin_unlock(&se_dev->dev_reservation_lock);
return 0;
}
static int core_scsi3_pri_report_capabilities(struct se_cmd *cmd)
{
struct se_device *dev = SE_DEV(cmd);
struct t10_reservation_template *pr_tmpl = &SU_DEV(dev)->t10_reservation;
unsigned char *buf = (unsigned char *)T_TASK(cmd)->t_task_buf;
u16 add_len = 8;
if (cmd->data_length < 6) {
printk(KERN_ERR "PRIN SA REPORT_CAPABILITIES SCSI Data Length:"
" %u too small\n", cmd->data_length);
return PYX_TRANSPORT_INVALID_CDB_FIELD;
}
buf[0] = ((add_len << 8) & 0xff);
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
return 0;
}
static int core_scsi3_pri_read_full_status(struct se_cmd *cmd)
{
struct se_device *se_dev = SE_DEV(cmd);
struct se_node_acl *se_nacl;
struct se_subsystem_dev *su_dev = SU_DEV(se_dev);
struct se_portal_group *se_tpg;
struct t10_pr_registration *pr_reg, *pr_reg_tmp;
struct t10_reservation_template *pr_tmpl = &SU_DEV(se_dev)->t10_reservation;
unsigned char *buf = (unsigned char *)T_TASK(cmd)->t_task_buf;
u32 add_desc_len = 0, add_len = 0, desc_len, exp_desc_len;
u32 off = 8;
int format_code = 0;
if (cmd->data_length < 8) {
printk(KERN_ERR "PRIN SA READ_FULL_STATUS SCSI Data Length: %u"
" too small\n", cmd->data_length);
return PYX_TRANSPORT_INVALID_CDB_FIELD;
}
buf[0] = ((T10_RES(su_dev)->pr_generation >> 24) & 0xff);
buf[1] = ((T10_RES(su_dev)->pr_generation >> 16) & 0xff);
buf[2] = ((T10_RES(su_dev)->pr_generation >> 8) & 0xff);
buf[3] = (T10_RES(su_dev)->pr_generation & 0xff);
spin_lock(&pr_tmpl->registration_lock);
list_for_each_entry_safe(pr_reg, pr_reg_tmp,
&pr_tmpl->registration_list, pr_reg_list) {
se_nacl = pr_reg->pr_reg_nacl;
se_tpg = pr_reg->pr_reg_nacl->se_tpg;
add_desc_len = 0;
atomic_inc(&pr_reg->pr_res_holders);
smp_mb__after_atomic_inc();
spin_unlock(&pr_tmpl->registration_lock);
exp_desc_len = TPG_TFO(se_tpg)->tpg_get_pr_transport_id_len(
se_tpg, se_nacl, pr_reg, &format_code);
if ((exp_desc_len + add_len) > cmd->data_length) {
printk(KERN_WARNING "SPC-3 PRIN READ_FULL_STATUS ran"
" out of buffer: %d\n", cmd->data_length);
spin_lock(&pr_tmpl->registration_lock);
atomic_dec(&pr_reg->pr_res_holders);
smp_mb__after_atomic_dec();
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
} else
off += 2;
off += 4;
if (!(pr_reg->pr_reg_all_tg_pt)) {
struct se_port *port = pr_reg->pr_reg_tg_pt_lun->lun_sep;
buf[off++] = ((port->sep_rtpi >> 8) & 0xff);
buf[off++] = (port->sep_rtpi & 0xff);
} else
off += 2;
desc_len = TPG_TFO(se_tpg)->tpg_get_pr_transport_id(se_tpg,
se_nacl, pr_reg, &format_code, &buf[off+4]);
spin_lock(&pr_tmpl->registration_lock);
atomic_dec(&pr_reg->pr_res_holders);
smp_mb__after_atomic_dec();
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
return 0;
}
static int core_scsi3_emulate_pr_in(struct se_cmd *cmd, unsigned char *cdb)
{
switch (cdb[1] & 0x1f) {
case PRI_READ_KEYS:
return core_scsi3_pri_read_keys(cmd);
case PRI_READ_RESERVATION:
return core_scsi3_pri_read_reservation(cmd);
case PRI_REPORT_CAPABILITIES:
return core_scsi3_pri_report_capabilities(cmd);
case PRI_READ_FULL_STATUS:
return core_scsi3_pri_read_full_status(cmd);
default:
printk(KERN_ERR "Unknown PERSISTENT_RESERVE_IN service"
" action: 0x%02x\n", cdb[1] & 0x1f);
return PYX_TRANSPORT_INVALID_CDB_FIELD;
}
}
int core_scsi3_emulate_pr(struct se_cmd *cmd)
{
unsigned char *cdb = &T_TASK(cmd)->t_task_cdb[0];
struct se_device *dev = cmd->se_dev;
if (dev->dev_flags & DF_SPC2_RESERVATIONS) {
printk(KERN_ERR "Received PERSISTENT_RESERVE CDB while legacy"
" SPC-2 reservation is held, returning"
" RESERVATION_CONFLICT\n");
return PYX_TRANSPORT_RESERVATION_CONFLICT;
}
return (cdb[0] == PERSISTENT_RESERVE_OUT) ?
core_scsi3_emulate_pr_out(cmd, cdb) :
core_scsi3_emulate_pr_in(cmd, cdb);
}
static int core_pt_reservation_check(struct se_cmd *cmd, u32 *pr_res_type)
{
return 0;
}
static int core_pt_seq_non_holder(
struct se_cmd *cmd,
unsigned char *cdb,
u32 pr_reg_type)
{
return 0;
}
int core_setup_reservations(struct se_device *dev, int force_pt)
{
struct se_subsystem_dev *su_dev = dev->se_sub_dev;
struct t10_reservation_template *rest = &su_dev->t10_reservation;
if (((TRANSPORT(dev)->transport_type == TRANSPORT_PLUGIN_PHBA_PDEV) &&
!(DEV_ATTRIB(dev)->emulate_reservations)) || force_pt) {
rest->res_type = SPC_PASSTHROUGH;
rest->pr_ops.t10_reservation_check = &core_pt_reservation_check;
rest->pr_ops.t10_seq_non_holder = &core_pt_seq_non_holder;
printk(KERN_INFO "%s: Using SPC_PASSTHROUGH, no reservation"
" emulation\n", TRANSPORT(dev)->name);
return 0;
}
if (TRANSPORT(dev)->get_device_rev(dev) >= SCSI_3) {
rest->res_type = SPC3_PERSISTENT_RESERVATIONS;
rest->pr_ops.t10_reservation_check = &core_scsi3_pr_reservation_check;
rest->pr_ops.t10_seq_non_holder = &core_scsi3_pr_seq_non_holder;
printk(KERN_INFO "%s: Using SPC3_PERSISTENT_RESERVATIONS"
" emulation\n", TRANSPORT(dev)->name);
} else {
rest->res_type = SPC2_RESERVATIONS;
rest->pr_ops.t10_reservation_check = &core_scsi2_reservation_check;
rest->pr_ops.t10_seq_non_holder =
&core_scsi2_reservation_seq_non_holder;
printk(KERN_INFO "%s: Using SPC2_RESERVATIONS emulation\n",
TRANSPORT(dev)->name);
}
return 0;
}
