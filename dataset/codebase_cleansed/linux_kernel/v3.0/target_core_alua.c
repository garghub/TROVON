int core_emulate_report_target_port_groups(struct se_cmd *cmd)
{
struct se_subsystem_dev *su_dev = SE_DEV(cmd)->se_sub_dev;
struct se_port *port;
struct t10_alua_tg_pt_gp *tg_pt_gp;
struct t10_alua_tg_pt_gp_member *tg_pt_gp_mem;
unsigned char *buf = (unsigned char *)T_TASK(cmd)->t_task_buf;
u32 rd_len = 0, off = 4;
spin_lock(&T10_ALUA(su_dev)->tg_pt_gps_lock);
list_for_each_entry(tg_pt_gp, &T10_ALUA(su_dev)->tg_pt_gps_list,
tg_pt_gp_list) {
if (tg_pt_gp->tg_pt_gp_pref)
buf[off] = 0x80;
buf[off++] |= (atomic_read(
&tg_pt_gp->tg_pt_gp_alua_access_state) & 0xff);
buf[off] = 0x80;
buf[off] |= 0x40;
buf[off] |= 0x8;
buf[off] |= 0x4;
buf[off] |= 0x2;
buf[off++] |= 0x1;
buf[off++] = ((tg_pt_gp->tg_pt_gp_id >> 8) & 0xff);
buf[off++] = (tg_pt_gp->tg_pt_gp_id & 0xff);
off++;
buf[off++] = (tg_pt_gp->tg_pt_gp_alua_access_status & 0xff);
buf[off++] = 0x00;
buf[off++] = (tg_pt_gp->tg_pt_gp_members & 0xff);
rd_len += 8;
spin_lock(&tg_pt_gp->tg_pt_gp_lock);
list_for_each_entry(tg_pt_gp_mem, &tg_pt_gp->tg_pt_gp_mem_list,
tg_pt_gp_mem_list) {
port = tg_pt_gp_mem->tg_pt;
off += 2;
buf[off++] = ((port->sep_rtpi >> 8) & 0xff);
buf[off++] = (port->sep_rtpi & 0xff);
rd_len += 4;
}
spin_unlock(&tg_pt_gp->tg_pt_gp_lock);
}
spin_unlock(&T10_ALUA(su_dev)->tg_pt_gps_lock);
buf[0] = ((rd_len >> 24) & 0xff);
buf[1] = ((rd_len >> 16) & 0xff);
buf[2] = ((rd_len >> 8) & 0xff);
buf[3] = (rd_len & 0xff);
return 0;
}
int core_emulate_set_target_port_groups(struct se_cmd *cmd)
{
struct se_device *dev = SE_DEV(cmd);
struct se_subsystem_dev *su_dev = SE_DEV(cmd)->se_sub_dev;
struct se_port *port, *l_port = SE_LUN(cmd)->lun_sep;
struct se_node_acl *nacl = SE_SESS(cmd)->se_node_acl;
struct t10_alua_tg_pt_gp *tg_pt_gp = NULL, *l_tg_pt_gp;
struct t10_alua_tg_pt_gp_member *tg_pt_gp_mem, *l_tg_pt_gp_mem;
unsigned char *buf = (unsigned char *)T_TASK(cmd)->t_task_buf;
unsigned char *ptr = &buf[4];
u32 len = 4;
int alua_access_state, primary = 0, rc;
u16 tg_pt_id, rtpi;
if (!(l_port))
return PYX_TRANSPORT_LU_COMM_FAILURE;
l_tg_pt_gp_mem = l_port->sep_alua_tg_pt_gp_mem;
if (!(l_tg_pt_gp_mem)) {
printk(KERN_ERR "Unable to access l_port->sep_alua_tg_pt_gp_mem\n");
return PYX_TRANSPORT_UNKNOWN_SAM_OPCODE;
}
spin_lock(&l_tg_pt_gp_mem->tg_pt_gp_mem_lock);
l_tg_pt_gp = l_tg_pt_gp_mem->tg_pt_gp;
if (!(l_tg_pt_gp)) {
spin_unlock(&l_tg_pt_gp_mem->tg_pt_gp_mem_lock);
printk(KERN_ERR "Unable to access *l_tg_pt_gp_mem->tg_pt_gp\n");
return PYX_TRANSPORT_UNKNOWN_SAM_OPCODE;
}
rc = (l_tg_pt_gp->tg_pt_gp_alua_access_type & TPGS_EXPLICT_ALUA);
spin_unlock(&l_tg_pt_gp_mem->tg_pt_gp_mem_lock);
if (!(rc)) {
printk(KERN_INFO "Unable to process SET_TARGET_PORT_GROUPS"
" while TPGS_EXPLICT_ALUA is disabled\n");
return PYX_TRANSPORT_UNKNOWN_SAM_OPCODE;
}
while (len < cmd->data_length) {
alua_access_state = (ptr[0] & 0x0f);
rc = core_alua_check_transition(alua_access_state, &primary);
if (rc != 0) {
return PYX_TRANSPORT_INVALID_PARAMETER_LIST;
}
rc = -1;
if (primary) {
tg_pt_id = ((ptr[2] << 8) & 0xff);
tg_pt_id |= (ptr[3] & 0xff);
spin_lock(&T10_ALUA(su_dev)->tg_pt_gps_lock);
list_for_each_entry(tg_pt_gp,
&T10_ALUA(su_dev)->tg_pt_gps_list,
tg_pt_gp_list) {
if (!(tg_pt_gp->tg_pt_gp_valid_id))
continue;
if (tg_pt_id != tg_pt_gp->tg_pt_gp_id)
continue;
atomic_inc(&tg_pt_gp->tg_pt_gp_ref_cnt);
smp_mb__after_atomic_inc();
spin_unlock(&T10_ALUA(su_dev)->tg_pt_gps_lock);
rc = core_alua_do_port_transition(tg_pt_gp,
dev, l_port, nacl,
alua_access_state, 1);
spin_lock(&T10_ALUA(su_dev)->tg_pt_gps_lock);
atomic_dec(&tg_pt_gp->tg_pt_gp_ref_cnt);
smp_mb__after_atomic_dec();
break;
}
spin_unlock(&T10_ALUA(su_dev)->tg_pt_gps_lock);
if (rc != 0)
return PYX_TRANSPORT_INVALID_PARAMETER_LIST;
} else {
rtpi = ((ptr[2] << 8) & 0xff);
rtpi |= (ptr[3] & 0xff);
spin_lock(&dev->se_port_lock);
list_for_each_entry(port, &dev->dev_sep_list,
sep_list) {
if (port->sep_rtpi != rtpi)
continue;
tg_pt_gp_mem = port->sep_alua_tg_pt_gp_mem;
spin_unlock(&dev->se_port_lock);
rc = core_alua_set_tg_pt_secondary_state(
tg_pt_gp_mem, port, 1, 1);
spin_lock(&dev->se_port_lock);
break;
}
spin_unlock(&dev->se_port_lock);
if (rc != 0)
return PYX_TRANSPORT_INVALID_PARAMETER_LIST;
}
ptr += 4;
len += 4;
}
return 0;
}
static inline int core_alua_state_nonoptimized(
struct se_cmd *cmd,
unsigned char *cdb,
int nonop_delay_msecs,
u8 *alua_ascq)
{
cmd->se_cmd_flags |= SCF_ALUA_NON_OPTIMIZED;
cmd->alua_nonop_delay = nonop_delay_msecs;
return 0;
}
static inline int core_alua_state_standby(
struct se_cmd *cmd,
unsigned char *cdb,
u8 *alua_ascq)
{
switch (cdb[0]) {
case INQUIRY:
case LOG_SELECT:
case LOG_SENSE:
case MODE_SELECT:
case MODE_SENSE:
case REPORT_LUNS:
case RECEIVE_DIAGNOSTIC:
case SEND_DIAGNOSTIC:
case MAINTENANCE_IN:
switch (cdb[1]) {
case MI_REPORT_TARGET_PGS:
return 0;
default:
*alua_ascq = ASCQ_04H_ALUA_TG_PT_STANDBY;
return 1;
}
case MAINTENANCE_OUT:
switch (cdb[1]) {
case MO_SET_TARGET_PGS:
return 0;
default:
*alua_ascq = ASCQ_04H_ALUA_TG_PT_STANDBY;
return 1;
}
case REQUEST_SENSE:
case PERSISTENT_RESERVE_IN:
case PERSISTENT_RESERVE_OUT:
case READ_BUFFER:
case WRITE_BUFFER:
return 0;
default:
*alua_ascq = ASCQ_04H_ALUA_TG_PT_STANDBY;
return 1;
}
return 0;
}
static inline int core_alua_state_unavailable(
struct se_cmd *cmd,
unsigned char *cdb,
u8 *alua_ascq)
{
switch (cdb[0]) {
case INQUIRY:
case REPORT_LUNS:
case MAINTENANCE_IN:
switch (cdb[1]) {
case MI_REPORT_TARGET_PGS:
return 0;
default:
*alua_ascq = ASCQ_04H_ALUA_TG_PT_UNAVAILABLE;
return 1;
}
case MAINTENANCE_OUT:
switch (cdb[1]) {
case MO_SET_TARGET_PGS:
return 0;
default:
*alua_ascq = ASCQ_04H_ALUA_TG_PT_UNAVAILABLE;
return 1;
}
case REQUEST_SENSE:
case READ_BUFFER:
case WRITE_BUFFER:
return 0;
default:
*alua_ascq = ASCQ_04H_ALUA_TG_PT_UNAVAILABLE;
return 1;
}
return 0;
}
static inline int core_alua_state_transition(
struct se_cmd *cmd,
unsigned char *cdb,
u8 *alua_ascq)
{
switch (cdb[0]) {
case INQUIRY:
case REPORT_LUNS:
case MAINTENANCE_IN:
switch (cdb[1]) {
case MI_REPORT_TARGET_PGS:
return 0;
default:
*alua_ascq = ASCQ_04H_ALUA_STATE_TRANSITION;
return 1;
}
case REQUEST_SENSE:
case READ_BUFFER:
case WRITE_BUFFER:
return 0;
default:
*alua_ascq = ASCQ_04H_ALUA_STATE_TRANSITION;
return 1;
}
return 0;
}
static int core_alua_state_check_nop(
struct se_cmd *cmd,
unsigned char *cdb,
u8 *alua_ascq)
{
return 0;
}
static int core_alua_state_check(
struct se_cmd *cmd,
unsigned char *cdb,
u8 *alua_ascq)
{
struct se_lun *lun = SE_LUN(cmd);
struct se_port *port = lun->lun_sep;
struct t10_alua_tg_pt_gp *tg_pt_gp;
struct t10_alua_tg_pt_gp_member *tg_pt_gp_mem;
int out_alua_state, nonop_delay_msecs;
if (!(port))
return 0;
if (atomic_read(&port->sep_tg_pt_secondary_offline)) {
*alua_ascq = ASCQ_04H_ALUA_OFFLINE;
printk(KERN_INFO "ALUA: Got secondary offline status for local"
" target port\n");
*alua_ascq = ASCQ_04H_ALUA_OFFLINE;
return 1;
}
tg_pt_gp_mem = port->sep_alua_tg_pt_gp_mem;
spin_lock(&tg_pt_gp_mem->tg_pt_gp_mem_lock);
tg_pt_gp = tg_pt_gp_mem->tg_pt_gp;
out_alua_state = atomic_read(&tg_pt_gp->tg_pt_gp_alua_access_state);
nonop_delay_msecs = tg_pt_gp->tg_pt_gp_nonop_delay_msecs;
spin_unlock(&tg_pt_gp_mem->tg_pt_gp_mem_lock);
if (out_alua_state == ALUA_ACCESS_STATE_ACTIVE_OPTMIZED)
return 0;
switch (out_alua_state) {
case ALUA_ACCESS_STATE_ACTIVE_NON_OPTIMIZED:
return core_alua_state_nonoptimized(cmd, cdb,
nonop_delay_msecs, alua_ascq);
case ALUA_ACCESS_STATE_STANDBY:
return core_alua_state_standby(cmd, cdb, alua_ascq);
case ALUA_ACCESS_STATE_UNAVAILABLE:
return core_alua_state_unavailable(cmd, cdb, alua_ascq);
case ALUA_ACCESS_STATE_TRANSITION:
return core_alua_state_transition(cmd, cdb, alua_ascq);
case ALUA_ACCESS_STATE_OFFLINE:
default:
printk(KERN_ERR "Unknown ALUA access state: 0x%02x\n",
out_alua_state);
return -1;
}
return 0;
}
static int core_alua_check_transition(int state, int *primary)
{
switch (state) {
case ALUA_ACCESS_STATE_ACTIVE_OPTMIZED:
case ALUA_ACCESS_STATE_ACTIVE_NON_OPTIMIZED:
case ALUA_ACCESS_STATE_STANDBY:
case ALUA_ACCESS_STATE_UNAVAILABLE:
*primary = 1;
break;
case ALUA_ACCESS_STATE_OFFLINE:
*primary = 0;
break;
default:
printk(KERN_ERR "Unknown ALUA access state: 0x%02x\n", state);
return -1;
}
return 0;
}
static char *core_alua_dump_state(int state)
{
switch (state) {
case ALUA_ACCESS_STATE_ACTIVE_OPTMIZED:
return "Active/Optimized";
case ALUA_ACCESS_STATE_ACTIVE_NON_OPTIMIZED:
return "Active/NonOptimized";
case ALUA_ACCESS_STATE_STANDBY:
return "Standby";
case ALUA_ACCESS_STATE_UNAVAILABLE:
return "Unavailable";
case ALUA_ACCESS_STATE_OFFLINE:
return "Offline";
default:
return "Unknown";
}
return NULL;
}
char *core_alua_dump_status(int status)
{
switch (status) {
case ALUA_STATUS_NONE:
return "None";
case ALUA_STATUS_ALTERED_BY_EXPLICT_STPG:
return "Altered by Explict STPG";
case ALUA_STATUS_ALTERED_BY_IMPLICT_ALUA:
return "Altered by Implict ALUA";
default:
return "Unknown";
}
return NULL;
}
int core_alua_check_nonop_delay(
struct se_cmd *cmd)
{
if (!(cmd->se_cmd_flags & SCF_ALUA_NON_OPTIMIZED))
return 0;
if (in_interrupt())
return 0;
if (!(cmd->alua_nonop_delay))
return 0;
msleep_interruptible(cmd->alua_nonop_delay);
return 0;
}
static int core_alua_write_tpg_metadata(
const char *path,
unsigned char *md_buf,
u32 md_buf_len)
{
mm_segment_t old_fs;
struct file *file;
struct iovec iov[1];
int flags = O_RDWR | O_CREAT | O_TRUNC, ret;
memset(iov, 0, sizeof(struct iovec));
file = filp_open(path, flags, 0600);
if (IS_ERR(file) || !file || !file->f_dentry) {
printk(KERN_ERR "filp_open(%s) for ALUA metadata failed\n",
path);
return -ENODEV;
}
iov[0].iov_base = &md_buf[0];
iov[0].iov_len = md_buf_len;
old_fs = get_fs();
set_fs(get_ds());
ret = vfs_writev(file, &iov[0], 1, &file->f_pos);
set_fs(old_fs);
if (ret < 0) {
printk(KERN_ERR "Error writing ALUA metadata file: %s\n", path);
filp_close(file, NULL);
return -EIO;
}
filp_close(file, NULL);
return 0;
}
static int core_alua_update_tpg_primary_metadata(
struct t10_alua_tg_pt_gp *tg_pt_gp,
int primary_state,
unsigned char *md_buf)
{
struct se_subsystem_dev *su_dev = tg_pt_gp->tg_pt_gp_su_dev;
struct t10_wwn *wwn = &su_dev->t10_wwn;
char path[ALUA_METADATA_PATH_LEN];
int len;
memset(path, 0, ALUA_METADATA_PATH_LEN);
len = snprintf(md_buf, tg_pt_gp->tg_pt_gp_md_buf_len,
"tg_pt_gp_id=%hu\n"
"alua_access_state=0x%02x\n"
"alua_access_status=0x%02x\n",
tg_pt_gp->tg_pt_gp_id, primary_state,
tg_pt_gp->tg_pt_gp_alua_access_status);
snprintf(path, ALUA_METADATA_PATH_LEN,
"/var/target/alua/tpgs_%s/%s", &wwn->unit_serial[0],
config_item_name(&tg_pt_gp->tg_pt_gp_group.cg_item));
return core_alua_write_tpg_metadata(path, md_buf, len);
}
static int core_alua_do_transition_tg_pt(
struct t10_alua_tg_pt_gp *tg_pt_gp,
struct se_port *l_port,
struct se_node_acl *nacl,
unsigned char *md_buf,
int new_state,
int explict)
{
struct se_dev_entry *se_deve;
struct se_lun_acl *lacl;
struct se_port *port;
struct t10_alua_tg_pt_gp_member *mem;
int old_state = 0;
old_state = atomic_read(&tg_pt_gp->tg_pt_gp_alua_access_state);
atomic_set(&tg_pt_gp->tg_pt_gp_alua_access_state,
ALUA_ACCESS_STATE_TRANSITION);
tg_pt_gp->tg_pt_gp_alua_access_status = (explict) ?
ALUA_STATUS_ALTERED_BY_EXPLICT_STPG :
ALUA_STATUS_ALTERED_BY_IMPLICT_ALUA;
if (tg_pt_gp->tg_pt_gp_trans_delay_msecs != 0)
msleep_interruptible(tg_pt_gp->tg_pt_gp_trans_delay_msecs);
spin_lock(&tg_pt_gp->tg_pt_gp_lock);
list_for_each_entry(mem, &tg_pt_gp->tg_pt_gp_mem_list,
tg_pt_gp_mem_list) {
port = mem->tg_pt;
atomic_inc(&mem->tg_pt_gp_mem_ref_cnt);
smp_mb__after_atomic_inc();
spin_unlock(&tg_pt_gp->tg_pt_gp_lock);
spin_lock_bh(&port->sep_alua_lock);
list_for_each_entry(se_deve, &port->sep_alua_list,
alua_port_list) {
lacl = se_deve->se_lun_acl;
if (!(lacl))
continue;
if (explict &&
(nacl != NULL) && (nacl == lacl->se_lun_nacl) &&
(l_port != NULL) && (l_port == port))
continue;
core_scsi3_ua_allocate(lacl->se_lun_nacl,
se_deve->mapped_lun, 0x2A,
ASCQ_2AH_ASYMMETRIC_ACCESS_STATE_CHANGED);
}
spin_unlock_bh(&port->sep_alua_lock);
spin_lock(&tg_pt_gp->tg_pt_gp_lock);
atomic_dec(&mem->tg_pt_gp_mem_ref_cnt);
smp_mb__after_atomic_dec();
}
spin_unlock(&tg_pt_gp->tg_pt_gp_lock);
if (tg_pt_gp->tg_pt_gp_write_metadata) {
mutex_lock(&tg_pt_gp->tg_pt_gp_md_mutex);
core_alua_update_tpg_primary_metadata(tg_pt_gp,
new_state, md_buf);
mutex_unlock(&tg_pt_gp->tg_pt_gp_md_mutex);
}
atomic_set(&tg_pt_gp->tg_pt_gp_alua_access_state, new_state);
printk(KERN_INFO "Successful %s ALUA transition TG PT Group: %s ID: %hu"
" from primary access state %s to %s\n", (explict) ? "explict" :
"implict", config_item_name(&tg_pt_gp->tg_pt_gp_group.cg_item),
tg_pt_gp->tg_pt_gp_id, core_alua_dump_state(old_state),
core_alua_dump_state(new_state));
return 0;
}
int core_alua_do_port_transition(
struct t10_alua_tg_pt_gp *l_tg_pt_gp,
struct se_device *l_dev,
struct se_port *l_port,
struct se_node_acl *l_nacl,
int new_state,
int explict)
{
struct se_device *dev;
struct se_port *port;
struct se_subsystem_dev *su_dev;
struct se_node_acl *nacl;
struct t10_alua_lu_gp *lu_gp;
struct t10_alua_lu_gp_member *lu_gp_mem, *local_lu_gp_mem;
struct t10_alua_tg_pt_gp *tg_pt_gp;
unsigned char *md_buf;
int primary;
if (core_alua_check_transition(new_state, &primary) != 0)
return -EINVAL;
md_buf = kzalloc(l_tg_pt_gp->tg_pt_gp_md_buf_len, GFP_KERNEL);
if (!(md_buf)) {
printk("Unable to allocate buf for ALUA metadata\n");
return -ENOMEM;
}
local_lu_gp_mem = l_dev->dev_alua_lu_gp_mem;
spin_lock(&local_lu_gp_mem->lu_gp_mem_lock);
lu_gp = local_lu_gp_mem->lu_gp;
atomic_inc(&lu_gp->lu_gp_ref_cnt);
smp_mb__after_atomic_inc();
spin_unlock(&local_lu_gp_mem->lu_gp_mem_lock);
if (!(lu_gp->lu_gp_id)) {
core_alua_do_transition_tg_pt(l_tg_pt_gp, l_port, l_nacl,
md_buf, new_state, explict);
atomic_dec(&lu_gp->lu_gp_ref_cnt);
smp_mb__after_atomic_dec();
kfree(md_buf);
return 0;
}
spin_lock(&lu_gp->lu_gp_lock);
list_for_each_entry(lu_gp_mem, &lu_gp->lu_gp_mem_list,
lu_gp_mem_list) {
dev = lu_gp_mem->lu_gp_mem_dev;
su_dev = dev->se_sub_dev;
atomic_inc(&lu_gp_mem->lu_gp_mem_ref_cnt);
smp_mb__after_atomic_inc();
spin_unlock(&lu_gp->lu_gp_lock);
spin_lock(&T10_ALUA(su_dev)->tg_pt_gps_lock);
list_for_each_entry(tg_pt_gp,
&T10_ALUA(su_dev)->tg_pt_gps_list,
tg_pt_gp_list) {
if (!(tg_pt_gp->tg_pt_gp_valid_id))
continue;
if (l_tg_pt_gp->tg_pt_gp_id != tg_pt_gp->tg_pt_gp_id)
continue;
if (l_tg_pt_gp == tg_pt_gp) {
port = l_port;
nacl = l_nacl;
} else {
port = NULL;
nacl = NULL;
}
atomic_inc(&tg_pt_gp->tg_pt_gp_ref_cnt);
smp_mb__after_atomic_inc();
spin_unlock(&T10_ALUA(su_dev)->tg_pt_gps_lock);
core_alua_do_transition_tg_pt(tg_pt_gp, port,
nacl, md_buf, new_state, explict);
spin_lock(&T10_ALUA(su_dev)->tg_pt_gps_lock);
atomic_dec(&tg_pt_gp->tg_pt_gp_ref_cnt);
smp_mb__after_atomic_dec();
}
spin_unlock(&T10_ALUA(su_dev)->tg_pt_gps_lock);
spin_lock(&lu_gp->lu_gp_lock);
atomic_dec(&lu_gp_mem->lu_gp_mem_ref_cnt);
smp_mb__after_atomic_dec();
}
spin_unlock(&lu_gp->lu_gp_lock);
printk(KERN_INFO "Successfully processed LU Group: %s all ALUA TG PT"
" Group IDs: %hu %s transition to primary state: %s\n",
config_item_name(&lu_gp->lu_gp_group.cg_item),
l_tg_pt_gp->tg_pt_gp_id, (explict) ? "explict" : "implict",
core_alua_dump_state(new_state));
atomic_dec(&lu_gp->lu_gp_ref_cnt);
smp_mb__after_atomic_dec();
kfree(md_buf);
return 0;
}
static int core_alua_update_tpg_secondary_metadata(
struct t10_alua_tg_pt_gp_member *tg_pt_gp_mem,
struct se_port *port,
unsigned char *md_buf,
u32 md_buf_len)
{
struct se_portal_group *se_tpg = port->sep_tpg;
char path[ALUA_METADATA_PATH_LEN], wwn[ALUA_SECONDARY_METADATA_WWN_LEN];
int len;
memset(path, 0, ALUA_METADATA_PATH_LEN);
memset(wwn, 0, ALUA_SECONDARY_METADATA_WWN_LEN);
len = snprintf(wwn, ALUA_SECONDARY_METADATA_WWN_LEN, "%s",
TPG_TFO(se_tpg)->tpg_get_wwn(se_tpg));
if (TPG_TFO(se_tpg)->tpg_get_tag != NULL)
snprintf(wwn+len, ALUA_SECONDARY_METADATA_WWN_LEN-len, "+%hu",
TPG_TFO(se_tpg)->tpg_get_tag(se_tpg));
len = snprintf(md_buf, md_buf_len, "alua_tg_pt_offline=%d\n"
"alua_tg_pt_status=0x%02x\n",
atomic_read(&port->sep_tg_pt_secondary_offline),
port->sep_tg_pt_secondary_stat);
snprintf(path, ALUA_METADATA_PATH_LEN, "/var/target/alua/%s/%s/lun_%u",
TPG_TFO(se_tpg)->get_fabric_name(), wwn,
port->sep_lun->unpacked_lun);
return core_alua_write_tpg_metadata(path, md_buf, len);
}
static int core_alua_set_tg_pt_secondary_state(
struct t10_alua_tg_pt_gp_member *tg_pt_gp_mem,
struct se_port *port,
int explict,
int offline)
{
struct t10_alua_tg_pt_gp *tg_pt_gp;
unsigned char *md_buf;
u32 md_buf_len;
int trans_delay_msecs;
spin_lock(&tg_pt_gp_mem->tg_pt_gp_mem_lock);
tg_pt_gp = tg_pt_gp_mem->tg_pt_gp;
if (!(tg_pt_gp)) {
spin_unlock(&tg_pt_gp_mem->tg_pt_gp_mem_lock);
printk(KERN_ERR "Unable to complete secondary state"
" transition\n");
return -1;
}
trans_delay_msecs = tg_pt_gp->tg_pt_gp_trans_delay_msecs;
if (offline)
atomic_set(&port->sep_tg_pt_secondary_offline, 1);
else
atomic_set(&port->sep_tg_pt_secondary_offline, 0);
md_buf_len = tg_pt_gp->tg_pt_gp_md_buf_len;
port->sep_tg_pt_secondary_stat = (explict) ?
ALUA_STATUS_ALTERED_BY_EXPLICT_STPG :
ALUA_STATUS_ALTERED_BY_IMPLICT_ALUA;
printk(KERN_INFO "Successful %s ALUA transition TG PT Group: %s ID: %hu"
" to secondary access state: %s\n", (explict) ? "explict" :
"implict", config_item_name(&tg_pt_gp->tg_pt_gp_group.cg_item),
tg_pt_gp->tg_pt_gp_id, (offline) ? "OFFLINE" : "ONLINE");
spin_unlock(&tg_pt_gp_mem->tg_pt_gp_mem_lock);
if (trans_delay_msecs != 0)
msleep_interruptible(trans_delay_msecs);
if (port->sep_tg_pt_secondary_write_md) {
md_buf = kzalloc(md_buf_len, GFP_KERNEL);
if (!(md_buf)) {
printk(KERN_ERR "Unable to allocate md_buf for"
" secondary ALUA access metadata\n");
return -1;
}
mutex_lock(&port->sep_tg_pt_md_mutex);
core_alua_update_tpg_secondary_metadata(tg_pt_gp_mem, port,
md_buf, md_buf_len);
mutex_unlock(&port->sep_tg_pt_md_mutex);
kfree(md_buf);
}
return 0;
}
struct t10_alua_lu_gp *
core_alua_allocate_lu_gp(const char *name, int def_group)
{
struct t10_alua_lu_gp *lu_gp;
lu_gp = kmem_cache_zalloc(t10_alua_lu_gp_cache, GFP_KERNEL);
if (!(lu_gp)) {
printk(KERN_ERR "Unable to allocate struct t10_alua_lu_gp\n");
return ERR_PTR(-ENOMEM);
}
INIT_LIST_HEAD(&lu_gp->lu_gp_list);
INIT_LIST_HEAD(&lu_gp->lu_gp_mem_list);
spin_lock_init(&lu_gp->lu_gp_lock);
atomic_set(&lu_gp->lu_gp_ref_cnt, 0);
if (def_group) {
lu_gp->lu_gp_id = se_global->alua_lu_gps_counter++;
lu_gp->lu_gp_valid_id = 1;
se_global->alua_lu_gps_count++;
}
return lu_gp;
}
int core_alua_set_lu_gp_id(struct t10_alua_lu_gp *lu_gp, u16 lu_gp_id)
{
struct t10_alua_lu_gp *lu_gp_tmp;
u16 lu_gp_id_tmp;
if (lu_gp->lu_gp_valid_id) {
printk(KERN_WARNING "ALUA LU Group already has a valid ID,"
" ignoring request\n");
return -1;
}
spin_lock(&se_global->lu_gps_lock);
if (se_global->alua_lu_gps_count == 0x0000ffff) {
printk(KERN_ERR "Maximum ALUA se_global->alua_lu_gps_count:"
" 0x0000ffff reached\n");
spin_unlock(&se_global->lu_gps_lock);
kmem_cache_free(t10_alua_lu_gp_cache, lu_gp);
return -1;
}
again:
lu_gp_id_tmp = (lu_gp_id != 0) ? lu_gp_id :
se_global->alua_lu_gps_counter++;
list_for_each_entry(lu_gp_tmp, &se_global->g_lu_gps_list, lu_gp_list) {
if (lu_gp_tmp->lu_gp_id == lu_gp_id_tmp) {
if (!(lu_gp_id))
goto again;
printk(KERN_WARNING "ALUA Logical Unit Group ID: %hu"
" already exists, ignoring request\n",
lu_gp_id);
spin_unlock(&se_global->lu_gps_lock);
return -1;
}
}
lu_gp->lu_gp_id = lu_gp_id_tmp;
lu_gp->lu_gp_valid_id = 1;
list_add_tail(&lu_gp->lu_gp_list, &se_global->g_lu_gps_list);
se_global->alua_lu_gps_count++;
spin_unlock(&se_global->lu_gps_lock);
return 0;
}
static struct t10_alua_lu_gp_member *
core_alua_allocate_lu_gp_mem(struct se_device *dev)
{
struct t10_alua_lu_gp_member *lu_gp_mem;
lu_gp_mem = kmem_cache_zalloc(t10_alua_lu_gp_mem_cache, GFP_KERNEL);
if (!(lu_gp_mem)) {
printk(KERN_ERR "Unable to allocate struct t10_alua_lu_gp_member\n");
return ERR_PTR(-ENOMEM);
}
INIT_LIST_HEAD(&lu_gp_mem->lu_gp_mem_list);
spin_lock_init(&lu_gp_mem->lu_gp_mem_lock);
atomic_set(&lu_gp_mem->lu_gp_mem_ref_cnt, 0);
lu_gp_mem->lu_gp_mem_dev = dev;
dev->dev_alua_lu_gp_mem = lu_gp_mem;
return lu_gp_mem;
}
void core_alua_free_lu_gp(struct t10_alua_lu_gp *lu_gp)
{
struct t10_alua_lu_gp_member *lu_gp_mem, *lu_gp_mem_tmp;
spin_lock(&se_global->lu_gps_lock);
atomic_set(&lu_gp->lu_gp_shutdown, 1);
list_del(&lu_gp->lu_gp_list);
se_global->alua_lu_gps_count--;
spin_unlock(&se_global->lu_gps_lock);
while (atomic_read(&lu_gp->lu_gp_ref_cnt))
cpu_relax();
spin_lock(&lu_gp->lu_gp_lock);
list_for_each_entry_safe(lu_gp_mem, lu_gp_mem_tmp,
&lu_gp->lu_gp_mem_list, lu_gp_mem_list) {
if (lu_gp_mem->lu_gp_assoc) {
list_del(&lu_gp_mem->lu_gp_mem_list);
lu_gp->lu_gp_members--;
lu_gp_mem->lu_gp_assoc = 0;
}
spin_unlock(&lu_gp->lu_gp_lock);
spin_lock(&lu_gp_mem->lu_gp_mem_lock);
if (lu_gp != se_global->default_lu_gp)
__core_alua_attach_lu_gp_mem(lu_gp_mem,
se_global->default_lu_gp);
else
lu_gp_mem->lu_gp = NULL;
spin_unlock(&lu_gp_mem->lu_gp_mem_lock);
spin_lock(&lu_gp->lu_gp_lock);
}
spin_unlock(&lu_gp->lu_gp_lock);
kmem_cache_free(t10_alua_lu_gp_cache, lu_gp);
}
void core_alua_free_lu_gp_mem(struct se_device *dev)
{
struct se_subsystem_dev *su_dev = dev->se_sub_dev;
struct t10_alua *alua = T10_ALUA(su_dev);
struct t10_alua_lu_gp *lu_gp;
struct t10_alua_lu_gp_member *lu_gp_mem;
if (alua->alua_type != SPC3_ALUA_EMULATED)
return;
lu_gp_mem = dev->dev_alua_lu_gp_mem;
if (!(lu_gp_mem))
return;
while (atomic_read(&lu_gp_mem->lu_gp_mem_ref_cnt))
cpu_relax();
spin_lock(&lu_gp_mem->lu_gp_mem_lock);
lu_gp = lu_gp_mem->lu_gp;
if ((lu_gp)) {
spin_lock(&lu_gp->lu_gp_lock);
if (lu_gp_mem->lu_gp_assoc) {
list_del(&lu_gp_mem->lu_gp_mem_list);
lu_gp->lu_gp_members--;
lu_gp_mem->lu_gp_assoc = 0;
}
spin_unlock(&lu_gp->lu_gp_lock);
lu_gp_mem->lu_gp = NULL;
}
spin_unlock(&lu_gp_mem->lu_gp_mem_lock);
kmem_cache_free(t10_alua_lu_gp_mem_cache, lu_gp_mem);
}
struct t10_alua_lu_gp *core_alua_get_lu_gp_by_name(const char *name)
{
struct t10_alua_lu_gp *lu_gp;
struct config_item *ci;
spin_lock(&se_global->lu_gps_lock);
list_for_each_entry(lu_gp, &se_global->g_lu_gps_list, lu_gp_list) {
if (!(lu_gp->lu_gp_valid_id))
continue;
ci = &lu_gp->lu_gp_group.cg_item;
if (!(strcmp(config_item_name(ci), name))) {
atomic_inc(&lu_gp->lu_gp_ref_cnt);
spin_unlock(&se_global->lu_gps_lock);
return lu_gp;
}
}
spin_unlock(&se_global->lu_gps_lock);
return NULL;
}
void core_alua_put_lu_gp_from_name(struct t10_alua_lu_gp *lu_gp)
{
spin_lock(&se_global->lu_gps_lock);
atomic_dec(&lu_gp->lu_gp_ref_cnt);
spin_unlock(&se_global->lu_gps_lock);
}
void __core_alua_attach_lu_gp_mem(
struct t10_alua_lu_gp_member *lu_gp_mem,
struct t10_alua_lu_gp *lu_gp)
{
spin_lock(&lu_gp->lu_gp_lock);
lu_gp_mem->lu_gp = lu_gp;
lu_gp_mem->lu_gp_assoc = 1;
list_add_tail(&lu_gp_mem->lu_gp_mem_list, &lu_gp->lu_gp_mem_list);
lu_gp->lu_gp_members++;
spin_unlock(&lu_gp->lu_gp_lock);
}
void __core_alua_drop_lu_gp_mem(
struct t10_alua_lu_gp_member *lu_gp_mem,
struct t10_alua_lu_gp *lu_gp)
{
spin_lock(&lu_gp->lu_gp_lock);
list_del(&lu_gp_mem->lu_gp_mem_list);
lu_gp_mem->lu_gp = NULL;
lu_gp_mem->lu_gp_assoc = 0;
lu_gp->lu_gp_members--;
spin_unlock(&lu_gp->lu_gp_lock);
}
struct t10_alua_tg_pt_gp *core_alua_allocate_tg_pt_gp(
struct se_subsystem_dev *su_dev,
const char *name,
int def_group)
{
struct t10_alua_tg_pt_gp *tg_pt_gp;
tg_pt_gp = kmem_cache_zalloc(t10_alua_tg_pt_gp_cache, GFP_KERNEL);
if (!(tg_pt_gp)) {
printk(KERN_ERR "Unable to allocate struct t10_alua_tg_pt_gp\n");
return NULL;
}
INIT_LIST_HEAD(&tg_pt_gp->tg_pt_gp_list);
INIT_LIST_HEAD(&tg_pt_gp->tg_pt_gp_mem_list);
mutex_init(&tg_pt_gp->tg_pt_gp_md_mutex);
spin_lock_init(&tg_pt_gp->tg_pt_gp_lock);
atomic_set(&tg_pt_gp->tg_pt_gp_ref_cnt, 0);
tg_pt_gp->tg_pt_gp_su_dev = su_dev;
tg_pt_gp->tg_pt_gp_md_buf_len = ALUA_MD_BUF_LEN;
atomic_set(&tg_pt_gp->tg_pt_gp_alua_access_state,
ALUA_ACCESS_STATE_ACTIVE_OPTMIZED);
tg_pt_gp->tg_pt_gp_alua_access_type =
TPGS_EXPLICT_ALUA | TPGS_IMPLICT_ALUA;
tg_pt_gp->tg_pt_gp_nonop_delay_msecs = ALUA_DEFAULT_NONOP_DELAY_MSECS;
tg_pt_gp->tg_pt_gp_trans_delay_msecs = ALUA_DEFAULT_TRANS_DELAY_MSECS;
if (def_group) {
spin_lock(&T10_ALUA(su_dev)->tg_pt_gps_lock);
tg_pt_gp->tg_pt_gp_id =
T10_ALUA(su_dev)->alua_tg_pt_gps_counter++;
tg_pt_gp->tg_pt_gp_valid_id = 1;
T10_ALUA(su_dev)->alua_tg_pt_gps_count++;
list_add_tail(&tg_pt_gp->tg_pt_gp_list,
&T10_ALUA(su_dev)->tg_pt_gps_list);
spin_unlock(&T10_ALUA(su_dev)->tg_pt_gps_lock);
}
return tg_pt_gp;
}
int core_alua_set_tg_pt_gp_id(
struct t10_alua_tg_pt_gp *tg_pt_gp,
u16 tg_pt_gp_id)
{
struct se_subsystem_dev *su_dev = tg_pt_gp->tg_pt_gp_su_dev;
struct t10_alua_tg_pt_gp *tg_pt_gp_tmp;
u16 tg_pt_gp_id_tmp;
if (tg_pt_gp->tg_pt_gp_valid_id) {
printk(KERN_WARNING "ALUA TG PT Group already has a valid ID,"
" ignoring request\n");
return -1;
}
spin_lock(&T10_ALUA(su_dev)->tg_pt_gps_lock);
if (T10_ALUA(su_dev)->alua_tg_pt_gps_count == 0x0000ffff) {
printk(KERN_ERR "Maximum ALUA alua_tg_pt_gps_count:"
" 0x0000ffff reached\n");
spin_unlock(&T10_ALUA(su_dev)->tg_pt_gps_lock);
kmem_cache_free(t10_alua_tg_pt_gp_cache, tg_pt_gp);
return -1;
}
again:
tg_pt_gp_id_tmp = (tg_pt_gp_id != 0) ? tg_pt_gp_id :
T10_ALUA(su_dev)->alua_tg_pt_gps_counter++;
list_for_each_entry(tg_pt_gp_tmp, &T10_ALUA(su_dev)->tg_pt_gps_list,
tg_pt_gp_list) {
if (tg_pt_gp_tmp->tg_pt_gp_id == tg_pt_gp_id_tmp) {
if (!(tg_pt_gp_id))
goto again;
printk(KERN_ERR "ALUA Target Port Group ID: %hu already"
" exists, ignoring request\n", tg_pt_gp_id);
spin_unlock(&T10_ALUA(su_dev)->tg_pt_gps_lock);
return -1;
}
}
tg_pt_gp->tg_pt_gp_id = tg_pt_gp_id_tmp;
tg_pt_gp->tg_pt_gp_valid_id = 1;
list_add_tail(&tg_pt_gp->tg_pt_gp_list,
&T10_ALUA(su_dev)->tg_pt_gps_list);
T10_ALUA(su_dev)->alua_tg_pt_gps_count++;
spin_unlock(&T10_ALUA(su_dev)->tg_pt_gps_lock);
return 0;
}
struct t10_alua_tg_pt_gp_member *core_alua_allocate_tg_pt_gp_mem(
struct se_port *port)
{
struct t10_alua_tg_pt_gp_member *tg_pt_gp_mem;
tg_pt_gp_mem = kmem_cache_zalloc(t10_alua_tg_pt_gp_mem_cache,
GFP_KERNEL);
if (!(tg_pt_gp_mem)) {
printk(KERN_ERR "Unable to allocate struct t10_alua_tg_pt_gp_member\n");
return ERR_PTR(-ENOMEM);
}
INIT_LIST_HEAD(&tg_pt_gp_mem->tg_pt_gp_mem_list);
spin_lock_init(&tg_pt_gp_mem->tg_pt_gp_mem_lock);
atomic_set(&tg_pt_gp_mem->tg_pt_gp_mem_ref_cnt, 0);
tg_pt_gp_mem->tg_pt = port;
port->sep_alua_tg_pt_gp_mem = tg_pt_gp_mem;
atomic_set(&port->sep_tg_pt_gp_active, 1);
return tg_pt_gp_mem;
}
void core_alua_free_tg_pt_gp(
struct t10_alua_tg_pt_gp *tg_pt_gp)
{
struct se_subsystem_dev *su_dev = tg_pt_gp->tg_pt_gp_su_dev;
struct t10_alua_tg_pt_gp_member *tg_pt_gp_mem, *tg_pt_gp_mem_tmp;
spin_lock(&T10_ALUA(su_dev)->tg_pt_gps_lock);
list_del(&tg_pt_gp->tg_pt_gp_list);
T10_ALUA(su_dev)->alua_tg_pt_gps_counter--;
spin_unlock(&T10_ALUA(su_dev)->tg_pt_gps_lock);
while (atomic_read(&tg_pt_gp->tg_pt_gp_ref_cnt))
cpu_relax();
spin_lock(&tg_pt_gp->tg_pt_gp_lock);
list_for_each_entry_safe(tg_pt_gp_mem, tg_pt_gp_mem_tmp,
&tg_pt_gp->tg_pt_gp_mem_list, tg_pt_gp_mem_list) {
if (tg_pt_gp_mem->tg_pt_gp_assoc) {
list_del(&tg_pt_gp_mem->tg_pt_gp_mem_list);
tg_pt_gp->tg_pt_gp_members--;
tg_pt_gp_mem->tg_pt_gp_assoc = 0;
}
spin_unlock(&tg_pt_gp->tg_pt_gp_lock);
spin_lock(&tg_pt_gp_mem->tg_pt_gp_mem_lock);
if (tg_pt_gp != T10_ALUA(su_dev)->default_tg_pt_gp) {
__core_alua_attach_tg_pt_gp_mem(tg_pt_gp_mem,
T10_ALUA(su_dev)->default_tg_pt_gp);
} else
tg_pt_gp_mem->tg_pt_gp = NULL;
spin_unlock(&tg_pt_gp_mem->tg_pt_gp_mem_lock);
spin_lock(&tg_pt_gp->tg_pt_gp_lock);
}
spin_unlock(&tg_pt_gp->tg_pt_gp_lock);
kmem_cache_free(t10_alua_tg_pt_gp_cache, tg_pt_gp);
}
void core_alua_free_tg_pt_gp_mem(struct se_port *port)
{
struct se_subsystem_dev *su_dev = port->sep_lun->lun_se_dev->se_sub_dev;
struct t10_alua *alua = T10_ALUA(su_dev);
struct t10_alua_tg_pt_gp *tg_pt_gp;
struct t10_alua_tg_pt_gp_member *tg_pt_gp_mem;
if (alua->alua_type != SPC3_ALUA_EMULATED)
return;
tg_pt_gp_mem = port->sep_alua_tg_pt_gp_mem;
if (!(tg_pt_gp_mem))
return;
while (atomic_read(&tg_pt_gp_mem->tg_pt_gp_mem_ref_cnt))
cpu_relax();
spin_lock(&tg_pt_gp_mem->tg_pt_gp_mem_lock);
tg_pt_gp = tg_pt_gp_mem->tg_pt_gp;
if ((tg_pt_gp)) {
spin_lock(&tg_pt_gp->tg_pt_gp_lock);
if (tg_pt_gp_mem->tg_pt_gp_assoc) {
list_del(&tg_pt_gp_mem->tg_pt_gp_mem_list);
tg_pt_gp->tg_pt_gp_members--;
tg_pt_gp_mem->tg_pt_gp_assoc = 0;
}
spin_unlock(&tg_pt_gp->tg_pt_gp_lock);
tg_pt_gp_mem->tg_pt_gp = NULL;
}
spin_unlock(&tg_pt_gp_mem->tg_pt_gp_mem_lock);
kmem_cache_free(t10_alua_tg_pt_gp_mem_cache, tg_pt_gp_mem);
}
static struct t10_alua_tg_pt_gp *core_alua_get_tg_pt_gp_by_name(
struct se_subsystem_dev *su_dev,
const char *name)
{
struct t10_alua_tg_pt_gp *tg_pt_gp;
struct config_item *ci;
spin_lock(&T10_ALUA(su_dev)->tg_pt_gps_lock);
list_for_each_entry(tg_pt_gp, &T10_ALUA(su_dev)->tg_pt_gps_list,
tg_pt_gp_list) {
if (!(tg_pt_gp->tg_pt_gp_valid_id))
continue;
ci = &tg_pt_gp->tg_pt_gp_group.cg_item;
if (!(strcmp(config_item_name(ci), name))) {
atomic_inc(&tg_pt_gp->tg_pt_gp_ref_cnt);
spin_unlock(&T10_ALUA(su_dev)->tg_pt_gps_lock);
return tg_pt_gp;
}
}
spin_unlock(&T10_ALUA(su_dev)->tg_pt_gps_lock);
return NULL;
}
static void core_alua_put_tg_pt_gp_from_name(
struct t10_alua_tg_pt_gp *tg_pt_gp)
{
struct se_subsystem_dev *su_dev = tg_pt_gp->tg_pt_gp_su_dev;
spin_lock(&T10_ALUA(su_dev)->tg_pt_gps_lock);
atomic_dec(&tg_pt_gp->tg_pt_gp_ref_cnt);
spin_unlock(&T10_ALUA(su_dev)->tg_pt_gps_lock);
}
void __core_alua_attach_tg_pt_gp_mem(
struct t10_alua_tg_pt_gp_member *tg_pt_gp_mem,
struct t10_alua_tg_pt_gp *tg_pt_gp)
{
spin_lock(&tg_pt_gp->tg_pt_gp_lock);
tg_pt_gp_mem->tg_pt_gp = tg_pt_gp;
tg_pt_gp_mem->tg_pt_gp_assoc = 1;
list_add_tail(&tg_pt_gp_mem->tg_pt_gp_mem_list,
&tg_pt_gp->tg_pt_gp_mem_list);
tg_pt_gp->tg_pt_gp_members++;
spin_unlock(&tg_pt_gp->tg_pt_gp_lock);
}
static void __core_alua_drop_tg_pt_gp_mem(
struct t10_alua_tg_pt_gp_member *tg_pt_gp_mem,
struct t10_alua_tg_pt_gp *tg_pt_gp)
{
spin_lock(&tg_pt_gp->tg_pt_gp_lock);
list_del(&tg_pt_gp_mem->tg_pt_gp_mem_list);
tg_pt_gp_mem->tg_pt_gp = NULL;
tg_pt_gp_mem->tg_pt_gp_assoc = 0;
tg_pt_gp->tg_pt_gp_members--;
spin_unlock(&tg_pt_gp->tg_pt_gp_lock);
}
ssize_t core_alua_show_tg_pt_gp_info(struct se_port *port, char *page)
{
struct se_subsystem_dev *su_dev = port->sep_lun->lun_se_dev->se_sub_dev;
struct config_item *tg_pt_ci;
struct t10_alua *alua = T10_ALUA(su_dev);
struct t10_alua_tg_pt_gp *tg_pt_gp;
struct t10_alua_tg_pt_gp_member *tg_pt_gp_mem;
ssize_t len = 0;
if (alua->alua_type != SPC3_ALUA_EMULATED)
return len;
tg_pt_gp_mem = port->sep_alua_tg_pt_gp_mem;
if (!(tg_pt_gp_mem))
return len;
spin_lock(&tg_pt_gp_mem->tg_pt_gp_mem_lock);
tg_pt_gp = tg_pt_gp_mem->tg_pt_gp;
if ((tg_pt_gp)) {
tg_pt_ci = &tg_pt_gp->tg_pt_gp_group.cg_item;
len += sprintf(page, "TG Port Alias: %s\nTG Port Group ID:"
" %hu\nTG Port Primary Access State: %s\nTG Port "
"Primary Access Status: %s\nTG Port Secondary Access"
" State: %s\nTG Port Secondary Access Status: %s\n",
config_item_name(tg_pt_ci), tg_pt_gp->tg_pt_gp_id,
core_alua_dump_state(atomic_read(
&tg_pt_gp->tg_pt_gp_alua_access_state)),
core_alua_dump_status(
tg_pt_gp->tg_pt_gp_alua_access_status),
(atomic_read(&port->sep_tg_pt_secondary_offline)) ?
"Offline" : "None",
core_alua_dump_status(port->sep_tg_pt_secondary_stat));
}
spin_unlock(&tg_pt_gp_mem->tg_pt_gp_mem_lock);
return len;
}
ssize_t core_alua_store_tg_pt_gp_info(
struct se_port *port,
const char *page,
size_t count)
{
struct se_portal_group *tpg;
struct se_lun *lun;
struct se_subsystem_dev *su_dev = port->sep_lun->lun_se_dev->se_sub_dev;
struct t10_alua_tg_pt_gp *tg_pt_gp = NULL, *tg_pt_gp_new = NULL;
struct t10_alua_tg_pt_gp_member *tg_pt_gp_mem;
unsigned char buf[TG_PT_GROUP_NAME_BUF];
int move = 0;
tpg = port->sep_tpg;
lun = port->sep_lun;
if (T10_ALUA(su_dev)->alua_type != SPC3_ALUA_EMULATED) {
printk(KERN_WARNING "SPC3_ALUA_EMULATED not enabled for"
" %s/tpgt_%hu/%s\n", TPG_TFO(tpg)->tpg_get_wwn(tpg),
TPG_TFO(tpg)->tpg_get_tag(tpg),
config_item_name(&lun->lun_group.cg_item));
return -EINVAL;
}
if (count > TG_PT_GROUP_NAME_BUF) {
printk(KERN_ERR "ALUA Target Port Group alias too large!\n");
return -EINVAL;
}
memset(buf, 0, TG_PT_GROUP_NAME_BUF);
memcpy(buf, page, count);
if (strcmp(strstrip(buf), "NULL")) {
tg_pt_gp_new = core_alua_get_tg_pt_gp_by_name(su_dev,
strstrip(buf));
if (!(tg_pt_gp_new))
return -ENODEV;
}
tg_pt_gp_mem = port->sep_alua_tg_pt_gp_mem;
if (!(tg_pt_gp_mem)) {
if (tg_pt_gp_new)
core_alua_put_tg_pt_gp_from_name(tg_pt_gp_new);
printk(KERN_ERR "NULL struct se_port->sep_alua_tg_pt_gp_mem pointer\n");
return -EINVAL;
}
spin_lock(&tg_pt_gp_mem->tg_pt_gp_mem_lock);
tg_pt_gp = tg_pt_gp_mem->tg_pt_gp;
if ((tg_pt_gp)) {
if (!(tg_pt_gp_new)) {
printk(KERN_INFO "Target_Core_ConfigFS: Moving"
" %s/tpgt_%hu/%s from ALUA Target Port Group:"
" alua/%s, ID: %hu back to"
" default_tg_pt_gp\n",
TPG_TFO(tpg)->tpg_get_wwn(tpg),
TPG_TFO(tpg)->tpg_get_tag(tpg),
config_item_name(&lun->lun_group.cg_item),
config_item_name(
&tg_pt_gp->tg_pt_gp_group.cg_item),
tg_pt_gp->tg_pt_gp_id);
__core_alua_drop_tg_pt_gp_mem(tg_pt_gp_mem, tg_pt_gp);
__core_alua_attach_tg_pt_gp_mem(tg_pt_gp_mem,
T10_ALUA(su_dev)->default_tg_pt_gp);
spin_unlock(&tg_pt_gp_mem->tg_pt_gp_mem_lock);
return count;
}
__core_alua_drop_tg_pt_gp_mem(tg_pt_gp_mem, tg_pt_gp);
move = 1;
}
__core_alua_attach_tg_pt_gp_mem(tg_pt_gp_mem, tg_pt_gp_new);
spin_unlock(&tg_pt_gp_mem->tg_pt_gp_mem_lock);
printk(KERN_INFO "Target_Core_ConfigFS: %s %s/tpgt_%hu/%s to ALUA"
" Target Port Group: alua/%s, ID: %hu\n", (move) ?
"Moving" : "Adding", TPG_TFO(tpg)->tpg_get_wwn(tpg),
TPG_TFO(tpg)->tpg_get_tag(tpg),
config_item_name(&lun->lun_group.cg_item),
config_item_name(&tg_pt_gp_new->tg_pt_gp_group.cg_item),
tg_pt_gp_new->tg_pt_gp_id);
core_alua_put_tg_pt_gp_from_name(tg_pt_gp_new);
return count;
}
ssize_t core_alua_show_access_type(
struct t10_alua_tg_pt_gp *tg_pt_gp,
char *page)
{
if ((tg_pt_gp->tg_pt_gp_alua_access_type & TPGS_EXPLICT_ALUA) &&
(tg_pt_gp->tg_pt_gp_alua_access_type & TPGS_IMPLICT_ALUA))
return sprintf(page, "Implict and Explict\n");
else if (tg_pt_gp->tg_pt_gp_alua_access_type & TPGS_IMPLICT_ALUA)
return sprintf(page, "Implict\n");
else if (tg_pt_gp->tg_pt_gp_alua_access_type & TPGS_EXPLICT_ALUA)
return sprintf(page, "Explict\n");
else
return sprintf(page, "None\n");
}
ssize_t core_alua_store_access_type(
struct t10_alua_tg_pt_gp *tg_pt_gp,
const char *page,
size_t count)
{
unsigned long tmp;
int ret;
ret = strict_strtoul(page, 0, &tmp);
if (ret < 0) {
printk(KERN_ERR "Unable to extract alua_access_type\n");
return -EINVAL;
}
if ((tmp != 0) && (tmp != 1) && (tmp != 2) && (tmp != 3)) {
printk(KERN_ERR "Illegal value for alua_access_type:"
" %lu\n", tmp);
return -EINVAL;
}
if (tmp == 3)
tg_pt_gp->tg_pt_gp_alua_access_type =
TPGS_IMPLICT_ALUA | TPGS_EXPLICT_ALUA;
else if (tmp == 2)
tg_pt_gp->tg_pt_gp_alua_access_type = TPGS_EXPLICT_ALUA;
else if (tmp == 1)
tg_pt_gp->tg_pt_gp_alua_access_type = TPGS_IMPLICT_ALUA;
else
tg_pt_gp->tg_pt_gp_alua_access_type = 0;
return count;
}
ssize_t core_alua_show_nonop_delay_msecs(
struct t10_alua_tg_pt_gp *tg_pt_gp,
char *page)
{
return sprintf(page, "%d\n", tg_pt_gp->tg_pt_gp_nonop_delay_msecs);
}
ssize_t core_alua_store_nonop_delay_msecs(
struct t10_alua_tg_pt_gp *tg_pt_gp,
const char *page,
size_t count)
{
unsigned long tmp;
int ret;
ret = strict_strtoul(page, 0, &tmp);
if (ret < 0) {
printk(KERN_ERR "Unable to extract nonop_delay_msecs\n");
return -EINVAL;
}
if (tmp > ALUA_MAX_NONOP_DELAY_MSECS) {
printk(KERN_ERR "Passed nonop_delay_msecs: %lu, exceeds"
" ALUA_MAX_NONOP_DELAY_MSECS: %d\n", tmp,
ALUA_MAX_NONOP_DELAY_MSECS);
return -EINVAL;
}
tg_pt_gp->tg_pt_gp_nonop_delay_msecs = (int)tmp;
return count;
}
ssize_t core_alua_show_trans_delay_msecs(
struct t10_alua_tg_pt_gp *tg_pt_gp,
char *page)
{
return sprintf(page, "%d\n", tg_pt_gp->tg_pt_gp_trans_delay_msecs);
}
ssize_t core_alua_store_trans_delay_msecs(
struct t10_alua_tg_pt_gp *tg_pt_gp,
const char *page,
size_t count)
{
unsigned long tmp;
int ret;
ret = strict_strtoul(page, 0, &tmp);
if (ret < 0) {
printk(KERN_ERR "Unable to extract trans_delay_msecs\n");
return -EINVAL;
}
if (tmp > ALUA_MAX_TRANS_DELAY_MSECS) {
printk(KERN_ERR "Passed trans_delay_msecs: %lu, exceeds"
" ALUA_MAX_TRANS_DELAY_MSECS: %d\n", tmp,
ALUA_MAX_TRANS_DELAY_MSECS);
return -EINVAL;
}
tg_pt_gp->tg_pt_gp_trans_delay_msecs = (int)tmp;
return count;
}
ssize_t core_alua_show_preferred_bit(
struct t10_alua_tg_pt_gp *tg_pt_gp,
char *page)
{
return sprintf(page, "%d\n", tg_pt_gp->tg_pt_gp_pref);
}
ssize_t core_alua_store_preferred_bit(
struct t10_alua_tg_pt_gp *tg_pt_gp,
const char *page,
size_t count)
{
unsigned long tmp;
int ret;
ret = strict_strtoul(page, 0, &tmp);
if (ret < 0) {
printk(KERN_ERR "Unable to extract preferred ALUA value\n");
return -EINVAL;
}
if ((tmp != 0) && (tmp != 1)) {
printk(KERN_ERR "Illegal value for preferred ALUA: %lu\n", tmp);
return -EINVAL;
}
tg_pt_gp->tg_pt_gp_pref = (int)tmp;
return count;
}
ssize_t core_alua_show_offline_bit(struct se_lun *lun, char *page)
{
if (!(lun->lun_sep))
return -ENODEV;
return sprintf(page, "%d\n",
atomic_read(&lun->lun_sep->sep_tg_pt_secondary_offline));
}
ssize_t core_alua_store_offline_bit(
struct se_lun *lun,
const char *page,
size_t count)
{
struct t10_alua_tg_pt_gp_member *tg_pt_gp_mem;
unsigned long tmp;
int ret;
if (!(lun->lun_sep))
return -ENODEV;
ret = strict_strtoul(page, 0, &tmp);
if (ret < 0) {
printk(KERN_ERR "Unable to extract alua_tg_pt_offline value\n");
return -EINVAL;
}
if ((tmp != 0) && (tmp != 1)) {
printk(KERN_ERR "Illegal value for alua_tg_pt_offline: %lu\n",
tmp);
return -EINVAL;
}
tg_pt_gp_mem = lun->lun_sep->sep_alua_tg_pt_gp_mem;
if (!(tg_pt_gp_mem)) {
printk(KERN_ERR "Unable to locate *tg_pt_gp_mem\n");
return -EINVAL;
}
ret = core_alua_set_tg_pt_secondary_state(tg_pt_gp_mem,
lun->lun_sep, 0, (int)tmp);
if (ret < 0)
return -EINVAL;
return count;
}
ssize_t core_alua_show_secondary_status(
struct se_lun *lun,
char *page)
{
return sprintf(page, "%d\n", lun->lun_sep->sep_tg_pt_secondary_stat);
}
ssize_t core_alua_store_secondary_status(
struct se_lun *lun,
const char *page,
size_t count)
{
unsigned long tmp;
int ret;
ret = strict_strtoul(page, 0, &tmp);
if (ret < 0) {
printk(KERN_ERR "Unable to extract alua_tg_pt_status\n");
return -EINVAL;
}
if ((tmp != ALUA_STATUS_NONE) &&
(tmp != ALUA_STATUS_ALTERED_BY_EXPLICT_STPG) &&
(tmp != ALUA_STATUS_ALTERED_BY_IMPLICT_ALUA)) {
printk(KERN_ERR "Illegal value for alua_tg_pt_status: %lu\n",
tmp);
return -EINVAL;
}
lun->lun_sep->sep_tg_pt_secondary_stat = (int)tmp;
return count;
}
ssize_t core_alua_show_secondary_write_metadata(
struct se_lun *lun,
char *page)
{
return sprintf(page, "%d\n",
lun->lun_sep->sep_tg_pt_secondary_write_md);
}
ssize_t core_alua_store_secondary_write_metadata(
struct se_lun *lun,
const char *page,
size_t count)
{
unsigned long tmp;
int ret;
ret = strict_strtoul(page, 0, &tmp);
if (ret < 0) {
printk(KERN_ERR "Unable to extract alua_tg_pt_write_md\n");
return -EINVAL;
}
if ((tmp != 0) && (tmp != 1)) {
printk(KERN_ERR "Illegal value for alua_tg_pt_write_md:"
" %lu\n", tmp);
return -EINVAL;
}
lun->lun_sep->sep_tg_pt_secondary_write_md = (int)tmp;
return count;
}
int core_setup_alua(struct se_device *dev, int force_pt)
{
struct se_subsystem_dev *su_dev = dev->se_sub_dev;
struct t10_alua *alua = T10_ALUA(su_dev);
struct t10_alua_lu_gp_member *lu_gp_mem;
if (((TRANSPORT(dev)->transport_type == TRANSPORT_PLUGIN_PHBA_PDEV) &&
!(DEV_ATTRIB(dev)->emulate_alua)) || force_pt) {
alua->alua_type = SPC_ALUA_PASSTHROUGH;
alua->alua_state_check = &core_alua_state_check_nop;
printk(KERN_INFO "%s: Using SPC_ALUA_PASSTHROUGH, no ALUA"
" emulation\n", TRANSPORT(dev)->name);
return 0;
}
if (TRANSPORT(dev)->get_device_rev(dev) >= SCSI_3) {
printk(KERN_INFO "%s: Enabling ALUA Emulation for SPC-3"
" device\n", TRANSPORT(dev)->name);
lu_gp_mem = core_alua_allocate_lu_gp_mem(dev);
if (IS_ERR(lu_gp_mem) || !lu_gp_mem)
return -1;
alua->alua_type = SPC3_ALUA_EMULATED;
alua->alua_state_check = &core_alua_state_check;
spin_lock(&lu_gp_mem->lu_gp_mem_lock);
__core_alua_attach_lu_gp_mem(lu_gp_mem,
se_global->default_lu_gp);
spin_unlock(&lu_gp_mem->lu_gp_mem_lock);
printk(KERN_INFO "%s: Adding to default ALUA LU Group:"
" core/alua/lu_gps/default_lu_gp\n",
TRANSPORT(dev)->name);
} else {
alua->alua_type = SPC2_ALUA_DISABLED;
alua->alua_state_check = &core_alua_state_check_nop;
printk(KERN_INFO "%s: Disabling ALUA Emulation for SPC-2"
" device\n", TRANSPORT(dev)->name);
}
return 0;
}
