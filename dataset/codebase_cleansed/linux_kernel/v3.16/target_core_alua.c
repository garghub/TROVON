sense_reason_t
target_emulate_report_referrals(struct se_cmd *cmd)
{
struct se_device *dev = cmd->se_dev;
struct t10_alua_lba_map *map;
struct t10_alua_lba_map_member *map_mem;
unsigned char *buf;
u32 rd_len = 0, off;
if (cmd->data_length < 4) {
pr_warn("REPORT REFERRALS allocation length %u too"
" small\n", cmd->data_length);
return TCM_INVALID_CDB_FIELD;
}
buf = transport_kmap_data_sg(cmd);
if (!buf)
return TCM_LOGICAL_UNIT_COMMUNICATION_FAILURE;
off = 4;
spin_lock(&dev->t10_alua.lba_map_lock);
if (list_empty(&dev->t10_alua.lba_map_list)) {
spin_unlock(&dev->t10_alua.lba_map_lock);
transport_kunmap_data_sg(cmd);
return TCM_UNSUPPORTED_SCSI_OPCODE;
}
list_for_each_entry(map, &dev->t10_alua.lba_map_list,
lba_map_list) {
int desc_num = off + 3;
int pg_num;
off += 4;
if (cmd->data_length > off)
put_unaligned_be64(map->lba_map_first_lba, &buf[off]);
off += 8;
if (cmd->data_length > off)
put_unaligned_be64(map->lba_map_last_lba, &buf[off]);
off += 8;
rd_len += 20;
pg_num = 0;
list_for_each_entry(map_mem, &map->lba_map_mem_list,
lba_map_mem_list) {
int alua_state = map_mem->lba_map_mem_alua_state;
int alua_pg_id = map_mem->lba_map_mem_alua_pg_id;
if (cmd->data_length > off)
buf[off] = alua_state & 0x0f;
off += 2;
if (cmd->data_length > off)
buf[off] = (alua_pg_id >> 8) & 0xff;
off++;
if (cmd->data_length > off)
buf[off] = (alua_pg_id & 0xff);
off++;
rd_len += 4;
pg_num++;
}
if (cmd->data_length > desc_num)
buf[desc_num] = pg_num;
}
spin_unlock(&dev->t10_alua.lba_map_lock);
put_unaligned_be16(rd_len, &buf[2]);
transport_kunmap_data_sg(cmd);
target_complete_cmd(cmd, GOOD);
return 0;
}
sense_reason_t
target_emulate_report_target_port_groups(struct se_cmd *cmd)
{
struct se_device *dev = cmd->se_dev;
struct se_port *port;
struct t10_alua_tg_pt_gp *tg_pt_gp;
struct t10_alua_tg_pt_gp_member *tg_pt_gp_mem;
unsigned char *buf;
u32 rd_len = 0, off;
int ext_hdr = (cmd->t_task_cdb[1] & 0x20);
if (ext_hdr != 0)
off = 8;
else
off = 4;
if (cmd->data_length < off) {
pr_warn("REPORT TARGET PORT GROUPS allocation length %u too"
" small for %s header\n", cmd->data_length,
(ext_hdr) ? "extended" : "normal");
return TCM_INVALID_CDB_FIELD;
}
buf = transport_kmap_data_sg(cmd);
if (!buf)
return TCM_LOGICAL_UNIT_COMMUNICATION_FAILURE;
spin_lock(&dev->t10_alua.tg_pt_gps_lock);
list_for_each_entry(tg_pt_gp, &dev->t10_alua.tg_pt_gps_list,
tg_pt_gp_list) {
if ((off + 8 + (tg_pt_gp->tg_pt_gp_members * 4)) >
cmd->data_length) {
rd_len += 8 + (tg_pt_gp->tg_pt_gp_members * 4);
continue;
}
if (tg_pt_gp->tg_pt_gp_pref)
buf[off] = 0x80;
buf[off++] |= (atomic_read(
&tg_pt_gp->tg_pt_gp_alua_access_state) & 0xff);
buf[off++] |= tg_pt_gp->tg_pt_gp_alua_supported_states;
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
spin_unlock(&dev->t10_alua.tg_pt_gps_lock);
put_unaligned_be32(rd_len, &buf[0]);
if (ext_hdr != 0) {
buf[4] = 0x10;
port = cmd->se_lun->lun_sep;
tg_pt_gp_mem = port->sep_alua_tg_pt_gp_mem;
if (tg_pt_gp_mem) {
spin_lock(&tg_pt_gp_mem->tg_pt_gp_mem_lock);
tg_pt_gp = tg_pt_gp_mem->tg_pt_gp;
if (tg_pt_gp)
buf[5] = tg_pt_gp->tg_pt_gp_implicit_trans_secs;
spin_unlock(&tg_pt_gp_mem->tg_pt_gp_mem_lock);
}
}
transport_kunmap_data_sg(cmd);
target_complete_cmd(cmd, GOOD);
return 0;
}
sense_reason_t
target_emulate_set_target_port_groups(struct se_cmd *cmd)
{
struct se_device *dev = cmd->se_dev;
struct se_port *port, *l_port = cmd->se_lun->lun_sep;
struct se_node_acl *nacl = cmd->se_sess->se_node_acl;
struct t10_alua_tg_pt_gp *tg_pt_gp = NULL, *l_tg_pt_gp;
struct t10_alua_tg_pt_gp_member *tg_pt_gp_mem, *l_tg_pt_gp_mem;
unsigned char *buf;
unsigned char *ptr;
sense_reason_t rc = TCM_NO_SENSE;
u32 len = 4;
int alua_access_state, primary = 0, valid_states;
u16 tg_pt_id, rtpi;
if (!l_port)
return TCM_LOGICAL_UNIT_COMMUNICATION_FAILURE;
if (cmd->data_length < 4) {
pr_warn("SET TARGET PORT GROUPS parameter list length %u too"
" small\n", cmd->data_length);
return TCM_INVALID_PARAMETER_LIST;
}
buf = transport_kmap_data_sg(cmd);
if (!buf)
return TCM_LOGICAL_UNIT_COMMUNICATION_FAILURE;
l_tg_pt_gp_mem = l_port->sep_alua_tg_pt_gp_mem;
if (!l_tg_pt_gp_mem) {
pr_err("Unable to access l_port->sep_alua_tg_pt_gp_mem\n");
rc = TCM_UNSUPPORTED_SCSI_OPCODE;
goto out;
}
spin_lock(&l_tg_pt_gp_mem->tg_pt_gp_mem_lock);
l_tg_pt_gp = l_tg_pt_gp_mem->tg_pt_gp;
if (!l_tg_pt_gp) {
spin_unlock(&l_tg_pt_gp_mem->tg_pt_gp_mem_lock);
pr_err("Unable to access *l_tg_pt_gp_mem->tg_pt_gp\n");
rc = TCM_UNSUPPORTED_SCSI_OPCODE;
goto out;
}
spin_unlock(&l_tg_pt_gp_mem->tg_pt_gp_mem_lock);
if (!(l_tg_pt_gp->tg_pt_gp_alua_access_type & TPGS_EXPLICIT_ALUA)) {
pr_debug("Unable to process SET_TARGET_PORT_GROUPS"
" while TPGS_EXPLICIT_ALUA is disabled\n");
rc = TCM_UNSUPPORTED_SCSI_OPCODE;
goto out;
}
valid_states = l_tg_pt_gp->tg_pt_gp_alua_supported_states;
ptr = &buf[4];
while (len < cmd->data_length) {
bool found = false;
alua_access_state = (ptr[0] & 0x0f);
rc = core_alua_check_transition(alua_access_state,
valid_states, &primary);
if (rc) {
goto out;
}
if (primary) {
tg_pt_id = get_unaligned_be16(ptr + 2);
spin_lock(&dev->t10_alua.tg_pt_gps_lock);
list_for_each_entry(tg_pt_gp,
&dev->t10_alua.tg_pt_gps_list,
tg_pt_gp_list) {
if (!tg_pt_gp->tg_pt_gp_valid_id)
continue;
if (tg_pt_id != tg_pt_gp->tg_pt_gp_id)
continue;
atomic_inc(&tg_pt_gp->tg_pt_gp_ref_cnt);
smp_mb__after_atomic();
spin_unlock(&dev->t10_alua.tg_pt_gps_lock);
if (!core_alua_do_port_transition(tg_pt_gp,
dev, l_port, nacl,
alua_access_state, 1))
found = true;
spin_lock(&dev->t10_alua.tg_pt_gps_lock);
atomic_dec(&tg_pt_gp->tg_pt_gp_ref_cnt);
smp_mb__after_atomic();
break;
}
spin_unlock(&dev->t10_alua.tg_pt_gps_lock);
} else {
rtpi = get_unaligned_be16(ptr + 2);
spin_lock(&dev->se_port_lock);
list_for_each_entry(port, &dev->dev_sep_list,
sep_list) {
if (port->sep_rtpi != rtpi)
continue;
tg_pt_gp_mem = port->sep_alua_tg_pt_gp_mem;
spin_unlock(&dev->se_port_lock);
if (!core_alua_set_tg_pt_secondary_state(
tg_pt_gp_mem, port, 1, 1))
found = true;
spin_lock(&dev->se_port_lock);
break;
}
spin_unlock(&dev->se_port_lock);
}
if (!found) {
rc = TCM_INVALID_PARAMETER_LIST;
goto out;
}
ptr += 4;
len += 4;
}
out:
transport_kunmap_data_sg(cmd);
if (!rc)
target_complete_cmd(cmd, GOOD);
return rc;
}
static inline void set_ascq(struct se_cmd *cmd, u8 alua_ascq)
{
pr_debug("[%s]: ALUA TG Port not available, "
"SenseKey: NOT_READY, ASC/ASCQ: "
"0x04/0x%02x\n",
cmd->se_tfo->get_fabric_name(), alua_ascq);
cmd->scsi_asc = 0x04;
cmd->scsi_ascq = alua_ascq;
}
static inline void core_alua_state_nonoptimized(
struct se_cmd *cmd,
unsigned char *cdb,
int nonop_delay_msecs)
{
cmd->se_cmd_flags |= SCF_ALUA_NON_OPTIMIZED;
cmd->alua_nonop_delay = nonop_delay_msecs;
}
static inline int core_alua_state_lba_dependent(
struct se_cmd *cmd,
struct t10_alua_tg_pt_gp *tg_pt_gp)
{
struct se_device *dev = cmd->se_dev;
u64 segment_size, segment_mult, sectors, lba;
if (!(cmd->se_cmd_flags & SCF_SCSI_DATA_CDB))
return 0;
spin_lock(&dev->t10_alua.lba_map_lock);
segment_size = dev->t10_alua.lba_map_segment_size;
segment_mult = dev->t10_alua.lba_map_segment_multiplier;
sectors = cmd->data_length / dev->dev_attrib.block_size;
lba = cmd->t_task_lba;
while (lba < cmd->t_task_lba + sectors) {
struct t10_alua_lba_map *cur_map = NULL, *map;
struct t10_alua_lba_map_member *map_mem;
list_for_each_entry(map, &dev->t10_alua.lba_map_list,
lba_map_list) {
u64 start_lba, last_lba;
u64 first_lba = map->lba_map_first_lba;
if (segment_mult) {
u64 tmp = lba;
start_lba = do_div(tmp, segment_size * segment_mult);
last_lba = first_lba + segment_size - 1;
if (start_lba >= first_lba &&
start_lba <= last_lba) {
lba += segment_size;
cur_map = map;
break;
}
} else {
last_lba = map->lba_map_last_lba;
if (lba >= first_lba && lba <= last_lba) {
lba = last_lba + 1;
cur_map = map;
break;
}
}
}
if (!cur_map) {
spin_unlock(&dev->t10_alua.lba_map_lock);
set_ascq(cmd, ASCQ_04H_ALUA_TG_PT_UNAVAILABLE);
return 1;
}
list_for_each_entry(map_mem, &cur_map->lba_map_mem_list,
lba_map_mem_list) {
if (map_mem->lba_map_mem_alua_pg_id !=
tg_pt_gp->tg_pt_gp_id)
continue;
switch(map_mem->lba_map_mem_alua_state) {
case ALUA_ACCESS_STATE_STANDBY:
spin_unlock(&dev->t10_alua.lba_map_lock);
set_ascq(cmd, ASCQ_04H_ALUA_TG_PT_STANDBY);
return 1;
case ALUA_ACCESS_STATE_UNAVAILABLE:
spin_unlock(&dev->t10_alua.lba_map_lock);
set_ascq(cmd, ASCQ_04H_ALUA_TG_PT_UNAVAILABLE);
return 1;
default:
break;
}
}
}
spin_unlock(&dev->t10_alua.lba_map_lock);
return 0;
}
static inline int core_alua_state_standby(
struct se_cmd *cmd,
unsigned char *cdb)
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
case READ_CAPACITY:
return 0;
case SERVICE_ACTION_IN:
switch (cdb[1] & 0x1f) {
case SAI_READ_CAPACITY_16:
return 0;
default:
set_ascq(cmd, ASCQ_04H_ALUA_TG_PT_STANDBY);
return 1;
}
case MAINTENANCE_IN:
switch (cdb[1] & 0x1f) {
case MI_REPORT_TARGET_PGS:
return 0;
default:
set_ascq(cmd, ASCQ_04H_ALUA_TG_PT_STANDBY);
return 1;
}
case MAINTENANCE_OUT:
switch (cdb[1]) {
case MO_SET_TARGET_PGS:
return 0;
default:
set_ascq(cmd, ASCQ_04H_ALUA_TG_PT_STANDBY);
return 1;
}
case REQUEST_SENSE:
case PERSISTENT_RESERVE_IN:
case PERSISTENT_RESERVE_OUT:
case READ_BUFFER:
case WRITE_BUFFER:
return 0;
default:
set_ascq(cmd, ASCQ_04H_ALUA_TG_PT_STANDBY);
return 1;
}
return 0;
}
static inline int core_alua_state_unavailable(
struct se_cmd *cmd,
unsigned char *cdb)
{
switch (cdb[0]) {
case INQUIRY:
case REPORT_LUNS:
return 0;
case MAINTENANCE_IN:
switch (cdb[1] & 0x1f) {
case MI_REPORT_TARGET_PGS:
return 0;
default:
set_ascq(cmd, ASCQ_04H_ALUA_TG_PT_UNAVAILABLE);
return 1;
}
case MAINTENANCE_OUT:
switch (cdb[1]) {
case MO_SET_TARGET_PGS:
return 0;
default:
set_ascq(cmd, ASCQ_04H_ALUA_TG_PT_UNAVAILABLE);
return 1;
}
case REQUEST_SENSE:
case READ_BUFFER:
case WRITE_BUFFER:
return 0;
default:
set_ascq(cmd, ASCQ_04H_ALUA_TG_PT_UNAVAILABLE);
return 1;
}
return 0;
}
static inline int core_alua_state_transition(
struct se_cmd *cmd,
unsigned char *cdb)
{
switch (cdb[0]) {
case INQUIRY:
case REPORT_LUNS:
return 0;
case MAINTENANCE_IN:
switch (cdb[1] & 0x1f) {
case MI_REPORT_TARGET_PGS:
return 0;
default:
set_ascq(cmd, ASCQ_04H_ALUA_STATE_TRANSITION);
return 1;
}
case REQUEST_SENSE:
case READ_BUFFER:
case WRITE_BUFFER:
return 0;
default:
set_ascq(cmd, ASCQ_04H_ALUA_STATE_TRANSITION);
return 1;
}
return 0;
}
sense_reason_t
target_alua_state_check(struct se_cmd *cmd)
{
struct se_device *dev = cmd->se_dev;
unsigned char *cdb = cmd->t_task_cdb;
struct se_lun *lun = cmd->se_lun;
struct se_port *port = lun->lun_sep;
struct t10_alua_tg_pt_gp *tg_pt_gp;
struct t10_alua_tg_pt_gp_member *tg_pt_gp_mem;
int out_alua_state, nonop_delay_msecs;
if (dev->se_hba->hba_flags & HBA_FLAGS_INTERNAL_USE)
return 0;
if (dev->transport->transport_type == TRANSPORT_PLUGIN_PHBA_PDEV)
return 0;
if (!port)
return 0;
if (atomic_read(&port->sep_tg_pt_secondary_offline)) {
pr_debug("ALUA: Got secondary offline status for local"
" target port\n");
set_ascq(cmd, ASCQ_04H_ALUA_OFFLINE);
return TCM_CHECK_CONDITION_NOT_READY;
}
tg_pt_gp_mem = port->sep_alua_tg_pt_gp_mem;
if (!tg_pt_gp_mem)
return 0;
spin_lock(&tg_pt_gp_mem->tg_pt_gp_mem_lock);
tg_pt_gp = tg_pt_gp_mem->tg_pt_gp;
out_alua_state = atomic_read(&tg_pt_gp->tg_pt_gp_alua_access_state);
nonop_delay_msecs = tg_pt_gp->tg_pt_gp_nonop_delay_msecs;
spin_unlock(&tg_pt_gp_mem->tg_pt_gp_mem_lock);
if (out_alua_state == ALUA_ACCESS_STATE_ACTIVE_OPTIMIZED)
return 0;
switch (out_alua_state) {
case ALUA_ACCESS_STATE_ACTIVE_NON_OPTIMIZED:
core_alua_state_nonoptimized(cmd, cdb, nonop_delay_msecs);
break;
case ALUA_ACCESS_STATE_STANDBY:
if (core_alua_state_standby(cmd, cdb))
return TCM_CHECK_CONDITION_NOT_READY;
break;
case ALUA_ACCESS_STATE_UNAVAILABLE:
if (core_alua_state_unavailable(cmd, cdb))
return TCM_CHECK_CONDITION_NOT_READY;
break;
case ALUA_ACCESS_STATE_TRANSITION:
if (core_alua_state_transition(cmd, cdb))
return TCM_CHECK_CONDITION_NOT_READY;
break;
case ALUA_ACCESS_STATE_LBA_DEPENDENT:
if (core_alua_state_lba_dependent(cmd, tg_pt_gp))
return TCM_CHECK_CONDITION_NOT_READY;
break;
case ALUA_ACCESS_STATE_OFFLINE:
default:
pr_err("Unknown ALUA access state: 0x%02x\n",
out_alua_state);
return TCM_INVALID_CDB_FIELD;
}
return 0;
}
static sense_reason_t
core_alua_check_transition(int state, int valid, int *primary)
{
switch (state) {
case ALUA_ACCESS_STATE_ACTIVE_OPTIMIZED:
if (!(valid & ALUA_AO_SUP))
goto not_supported;
*primary = 1;
break;
case ALUA_ACCESS_STATE_ACTIVE_NON_OPTIMIZED:
if (!(valid & ALUA_AN_SUP))
goto not_supported;
*primary = 1;
break;
case ALUA_ACCESS_STATE_STANDBY:
if (!(valid & ALUA_S_SUP))
goto not_supported;
*primary = 1;
break;
case ALUA_ACCESS_STATE_UNAVAILABLE:
if (!(valid & ALUA_U_SUP))
goto not_supported;
*primary = 1;
break;
case ALUA_ACCESS_STATE_LBA_DEPENDENT:
if (!(valid & ALUA_LBD_SUP))
goto not_supported;
*primary = 1;
break;
case ALUA_ACCESS_STATE_OFFLINE:
if (!(valid & ALUA_O_SUP))
goto not_supported;
*primary = 0;
break;
case ALUA_ACCESS_STATE_TRANSITION:
goto not_supported;
default:
pr_err("Unknown ALUA access state: 0x%02x\n", state);
return TCM_INVALID_PARAMETER_LIST;
}
return 0;
not_supported:
pr_err("ALUA access state %s not supported",
core_alua_dump_state(state));
return TCM_INVALID_PARAMETER_LIST;
}
static char *core_alua_dump_state(int state)
{
switch (state) {
case ALUA_ACCESS_STATE_ACTIVE_OPTIMIZED:
return "Active/Optimized";
case ALUA_ACCESS_STATE_ACTIVE_NON_OPTIMIZED:
return "Active/NonOptimized";
case ALUA_ACCESS_STATE_LBA_DEPENDENT:
return "LBA Dependent";
case ALUA_ACCESS_STATE_STANDBY:
return "Standby";
case ALUA_ACCESS_STATE_UNAVAILABLE:
return "Unavailable";
case ALUA_ACCESS_STATE_OFFLINE:
return "Offline";
case ALUA_ACCESS_STATE_TRANSITION:
return "Transitioning";
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
case ALUA_STATUS_ALTERED_BY_EXPLICIT_STPG:
return "Altered by Explicit STPG";
case ALUA_STATUS_ALTERED_BY_IMPLICIT_ALUA:
return "Altered by Implicit ALUA";
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
if (!cmd->alua_nonop_delay)
return 0;
msleep_interruptible(cmd->alua_nonop_delay);
return 0;
}
static int core_alua_write_tpg_metadata(
const char *path,
unsigned char *md_buf,
u32 md_buf_len)
{
struct file *file = filp_open(path, O_RDWR | O_CREAT | O_TRUNC, 0600);
int ret;
if (IS_ERR(file)) {
pr_err("filp_open(%s) for ALUA metadata failed\n", path);
return -ENODEV;
}
ret = kernel_write(file, md_buf, md_buf_len, 0);
if (ret < 0)
pr_err("Error writing ALUA metadata file: %s\n", path);
fput(file);
return (ret < 0) ? -EIO : 0;
}
static int core_alua_update_tpg_primary_metadata(
struct t10_alua_tg_pt_gp *tg_pt_gp)
{
unsigned char *md_buf;
struct t10_wwn *wwn = &tg_pt_gp->tg_pt_gp_dev->t10_wwn;
char path[ALUA_METADATA_PATH_LEN];
int len, rc;
md_buf = kzalloc(ALUA_MD_BUF_LEN, GFP_KERNEL);
if (!md_buf) {
pr_err("Unable to allocate buf for ALUA metadata\n");
return -ENOMEM;
}
memset(path, 0, ALUA_METADATA_PATH_LEN);
len = snprintf(md_buf, ALUA_MD_BUF_LEN,
"tg_pt_gp_id=%hu\n"
"alua_access_state=0x%02x\n"
"alua_access_status=0x%02x\n",
tg_pt_gp->tg_pt_gp_id,
tg_pt_gp->tg_pt_gp_alua_pending_state,
tg_pt_gp->tg_pt_gp_alua_access_status);
snprintf(path, ALUA_METADATA_PATH_LEN,
"/var/target/alua/tpgs_%s/%s", &wwn->unit_serial[0],
config_item_name(&tg_pt_gp->tg_pt_gp_group.cg_item));
rc = core_alua_write_tpg_metadata(path, md_buf, len);
kfree(md_buf);
return rc;
}
static void core_alua_do_transition_tg_pt_work(struct work_struct *work)
{
struct t10_alua_tg_pt_gp *tg_pt_gp = container_of(work,
struct t10_alua_tg_pt_gp, tg_pt_gp_transition_work.work);
struct se_device *dev = tg_pt_gp->tg_pt_gp_dev;
struct se_dev_entry *se_deve;
struct se_lun_acl *lacl;
struct se_port *port;
struct t10_alua_tg_pt_gp_member *mem;
bool explicit = (tg_pt_gp->tg_pt_gp_alua_access_status ==
ALUA_STATUS_ALTERED_BY_EXPLICIT_STPG);
spin_lock(&tg_pt_gp->tg_pt_gp_lock);
list_for_each_entry(mem, &tg_pt_gp->tg_pt_gp_mem_list,
tg_pt_gp_mem_list) {
port = mem->tg_pt;
atomic_inc(&mem->tg_pt_gp_mem_ref_cnt);
smp_mb__after_atomic();
spin_unlock(&tg_pt_gp->tg_pt_gp_lock);
spin_lock_bh(&port->sep_alua_lock);
list_for_each_entry(se_deve, &port->sep_alua_list,
alua_port_list) {
lacl = se_deve->se_lun_acl;
if (!lacl)
continue;
if ((tg_pt_gp->tg_pt_gp_alua_access_status ==
ALUA_STATUS_ALTERED_BY_EXPLICIT_STPG) &&
(tg_pt_gp->tg_pt_gp_alua_nacl != NULL) &&
(tg_pt_gp->tg_pt_gp_alua_nacl == lacl->se_lun_nacl) &&
(tg_pt_gp->tg_pt_gp_alua_port != NULL) &&
(tg_pt_gp->tg_pt_gp_alua_port == port))
continue;
core_scsi3_ua_allocate(lacl->se_lun_nacl,
se_deve->mapped_lun, 0x2A,
ASCQ_2AH_ASYMMETRIC_ACCESS_STATE_CHANGED);
}
spin_unlock_bh(&port->sep_alua_lock);
spin_lock(&tg_pt_gp->tg_pt_gp_lock);
atomic_dec(&mem->tg_pt_gp_mem_ref_cnt);
smp_mb__after_atomic();
}
spin_unlock(&tg_pt_gp->tg_pt_gp_lock);
if (tg_pt_gp->tg_pt_gp_write_metadata) {
mutex_lock(&tg_pt_gp->tg_pt_gp_md_mutex);
core_alua_update_tpg_primary_metadata(tg_pt_gp);
mutex_unlock(&tg_pt_gp->tg_pt_gp_md_mutex);
}
atomic_set(&tg_pt_gp->tg_pt_gp_alua_access_state,
tg_pt_gp->tg_pt_gp_alua_pending_state);
pr_debug("Successful %s ALUA transition TG PT Group: %s ID: %hu"
" from primary access state %s to %s\n", (explicit) ? "explicit" :
"implicit", config_item_name(&tg_pt_gp->tg_pt_gp_group.cg_item),
tg_pt_gp->tg_pt_gp_id,
core_alua_dump_state(tg_pt_gp->tg_pt_gp_alua_previous_state),
core_alua_dump_state(tg_pt_gp->tg_pt_gp_alua_pending_state));
spin_lock(&dev->t10_alua.tg_pt_gps_lock);
atomic_dec(&tg_pt_gp->tg_pt_gp_ref_cnt);
smp_mb__after_atomic();
spin_unlock(&dev->t10_alua.tg_pt_gps_lock);
if (tg_pt_gp->tg_pt_gp_transition_complete)
complete(tg_pt_gp->tg_pt_gp_transition_complete);
}
static int core_alua_do_transition_tg_pt(
struct t10_alua_tg_pt_gp *tg_pt_gp,
int new_state,
int explicit)
{
struct se_device *dev = tg_pt_gp->tg_pt_gp_dev;
DECLARE_COMPLETION_ONSTACK(wait);
if (atomic_read(&tg_pt_gp->tg_pt_gp_alua_access_state) == new_state)
return 0;
if (new_state == ALUA_ACCESS_STATE_TRANSITION)
return -EAGAIN;
if (!explicit && tg_pt_gp->tg_pt_gp_implicit_trans_secs &&
atomic_read(&tg_pt_gp->tg_pt_gp_alua_access_state) ==
ALUA_ACCESS_STATE_TRANSITION) {
tg_pt_gp->tg_pt_gp_alua_pending_state = new_state;
tg_pt_gp->tg_pt_gp_transition_complete = &wait;
flush_delayed_work(&tg_pt_gp->tg_pt_gp_transition_work);
wait_for_completion(&wait);
tg_pt_gp->tg_pt_gp_transition_complete = NULL;
return 0;
}
tg_pt_gp->tg_pt_gp_alua_previous_state =
atomic_read(&tg_pt_gp->tg_pt_gp_alua_access_state);
tg_pt_gp->tg_pt_gp_alua_pending_state = new_state;
atomic_set(&tg_pt_gp->tg_pt_gp_alua_access_state,
ALUA_ACCESS_STATE_TRANSITION);
tg_pt_gp->tg_pt_gp_alua_access_status = (explicit) ?
ALUA_STATUS_ALTERED_BY_EXPLICIT_STPG :
ALUA_STATUS_ALTERED_BY_IMPLICIT_ALUA;
if (tg_pt_gp->tg_pt_gp_trans_delay_msecs != 0)
msleep_interruptible(tg_pt_gp->tg_pt_gp_trans_delay_msecs);
spin_lock(&dev->t10_alua.tg_pt_gps_lock);
atomic_inc(&tg_pt_gp->tg_pt_gp_ref_cnt);
smp_mb__after_atomic();
spin_unlock(&dev->t10_alua.tg_pt_gps_lock);
if (!explicit && tg_pt_gp->tg_pt_gp_implicit_trans_secs) {
unsigned long transition_tmo;
transition_tmo = tg_pt_gp->tg_pt_gp_implicit_trans_secs * HZ;
queue_delayed_work(tg_pt_gp->tg_pt_gp_dev->tmr_wq,
&tg_pt_gp->tg_pt_gp_transition_work,
transition_tmo);
} else {
tg_pt_gp->tg_pt_gp_transition_complete = &wait;
queue_delayed_work(tg_pt_gp->tg_pt_gp_dev->tmr_wq,
&tg_pt_gp->tg_pt_gp_transition_work, 0);
wait_for_completion(&wait);
tg_pt_gp->tg_pt_gp_transition_complete = NULL;
}
return 0;
}
int core_alua_do_port_transition(
struct t10_alua_tg_pt_gp *l_tg_pt_gp,
struct se_device *l_dev,
struct se_port *l_port,
struct se_node_acl *l_nacl,
int new_state,
int explicit)
{
struct se_device *dev;
struct t10_alua_lu_gp *lu_gp;
struct t10_alua_lu_gp_member *lu_gp_mem, *local_lu_gp_mem;
struct t10_alua_tg_pt_gp *tg_pt_gp;
int primary, valid_states, rc = 0;
valid_states = l_tg_pt_gp->tg_pt_gp_alua_supported_states;
if (core_alua_check_transition(new_state, valid_states, &primary) != 0)
return -EINVAL;
local_lu_gp_mem = l_dev->dev_alua_lu_gp_mem;
spin_lock(&local_lu_gp_mem->lu_gp_mem_lock);
lu_gp = local_lu_gp_mem->lu_gp;
atomic_inc(&lu_gp->lu_gp_ref_cnt);
smp_mb__after_atomic();
spin_unlock(&local_lu_gp_mem->lu_gp_mem_lock);
if (!lu_gp->lu_gp_id) {
l_tg_pt_gp->tg_pt_gp_alua_port = l_port;
l_tg_pt_gp->tg_pt_gp_alua_nacl = l_nacl;
rc = core_alua_do_transition_tg_pt(l_tg_pt_gp,
new_state, explicit);
atomic_dec(&lu_gp->lu_gp_ref_cnt);
smp_mb__after_atomic();
return rc;
}
spin_lock(&lu_gp->lu_gp_lock);
list_for_each_entry(lu_gp_mem, &lu_gp->lu_gp_mem_list,
lu_gp_mem_list) {
dev = lu_gp_mem->lu_gp_mem_dev;
atomic_inc(&lu_gp_mem->lu_gp_mem_ref_cnt);
smp_mb__after_atomic();
spin_unlock(&lu_gp->lu_gp_lock);
spin_lock(&dev->t10_alua.tg_pt_gps_lock);
list_for_each_entry(tg_pt_gp,
&dev->t10_alua.tg_pt_gps_list,
tg_pt_gp_list) {
if (!tg_pt_gp->tg_pt_gp_valid_id)
continue;
if (l_tg_pt_gp->tg_pt_gp_id != tg_pt_gp->tg_pt_gp_id)
continue;
if (l_tg_pt_gp == tg_pt_gp) {
tg_pt_gp->tg_pt_gp_alua_port = l_port;
tg_pt_gp->tg_pt_gp_alua_nacl = l_nacl;
} else {
tg_pt_gp->tg_pt_gp_alua_port = NULL;
tg_pt_gp->tg_pt_gp_alua_nacl = NULL;
}
atomic_inc(&tg_pt_gp->tg_pt_gp_ref_cnt);
smp_mb__after_atomic();
spin_unlock(&dev->t10_alua.tg_pt_gps_lock);
rc = core_alua_do_transition_tg_pt(tg_pt_gp,
new_state, explicit);
spin_lock(&dev->t10_alua.tg_pt_gps_lock);
atomic_dec(&tg_pt_gp->tg_pt_gp_ref_cnt);
smp_mb__after_atomic();
if (rc)
break;
}
spin_unlock(&dev->t10_alua.tg_pt_gps_lock);
spin_lock(&lu_gp->lu_gp_lock);
atomic_dec(&lu_gp_mem->lu_gp_mem_ref_cnt);
smp_mb__after_atomic();
}
spin_unlock(&lu_gp->lu_gp_lock);
if (!rc) {
pr_debug("Successfully processed LU Group: %s all ALUA TG PT"
" Group IDs: %hu %s transition to primary state: %s\n",
config_item_name(&lu_gp->lu_gp_group.cg_item),
l_tg_pt_gp->tg_pt_gp_id,
(explicit) ? "explicit" : "implicit",
core_alua_dump_state(new_state));
}
atomic_dec(&lu_gp->lu_gp_ref_cnt);
smp_mb__after_atomic();
return rc;
}
static int core_alua_update_tpg_secondary_metadata(
struct t10_alua_tg_pt_gp_member *tg_pt_gp_mem,
struct se_port *port)
{
unsigned char *md_buf;
struct se_portal_group *se_tpg = port->sep_tpg;
char path[ALUA_METADATA_PATH_LEN], wwn[ALUA_SECONDARY_METADATA_WWN_LEN];
int len, rc;
md_buf = kzalloc(ALUA_MD_BUF_LEN, GFP_KERNEL);
if (!md_buf) {
pr_err("Unable to allocate buf for ALUA metadata\n");
return -ENOMEM;
}
memset(path, 0, ALUA_METADATA_PATH_LEN);
memset(wwn, 0, ALUA_SECONDARY_METADATA_WWN_LEN);
len = snprintf(wwn, ALUA_SECONDARY_METADATA_WWN_LEN, "%s",
se_tpg->se_tpg_tfo->tpg_get_wwn(se_tpg));
if (se_tpg->se_tpg_tfo->tpg_get_tag != NULL)
snprintf(wwn+len, ALUA_SECONDARY_METADATA_WWN_LEN-len, "+%hu",
se_tpg->se_tpg_tfo->tpg_get_tag(se_tpg));
len = snprintf(md_buf, ALUA_MD_BUF_LEN, "alua_tg_pt_offline=%d\n"
"alua_tg_pt_status=0x%02x\n",
atomic_read(&port->sep_tg_pt_secondary_offline),
port->sep_tg_pt_secondary_stat);
snprintf(path, ALUA_METADATA_PATH_LEN, "/var/target/alua/%s/%s/lun_%u",
se_tpg->se_tpg_tfo->get_fabric_name(), wwn,
port->sep_lun->unpacked_lun);
rc = core_alua_write_tpg_metadata(path, md_buf, len);
kfree(md_buf);
return rc;
}
static int core_alua_set_tg_pt_secondary_state(
struct t10_alua_tg_pt_gp_member *tg_pt_gp_mem,
struct se_port *port,
int explicit,
int offline)
{
struct t10_alua_tg_pt_gp *tg_pt_gp;
int trans_delay_msecs;
spin_lock(&tg_pt_gp_mem->tg_pt_gp_mem_lock);
tg_pt_gp = tg_pt_gp_mem->tg_pt_gp;
if (!tg_pt_gp) {
spin_unlock(&tg_pt_gp_mem->tg_pt_gp_mem_lock);
pr_err("Unable to complete secondary state"
" transition\n");
return -EINVAL;
}
trans_delay_msecs = tg_pt_gp->tg_pt_gp_trans_delay_msecs;
if (offline)
atomic_set(&port->sep_tg_pt_secondary_offline, 1);
else
atomic_set(&port->sep_tg_pt_secondary_offline, 0);
port->sep_tg_pt_secondary_stat = (explicit) ?
ALUA_STATUS_ALTERED_BY_EXPLICIT_STPG :
ALUA_STATUS_ALTERED_BY_IMPLICIT_ALUA;
pr_debug("Successful %s ALUA transition TG PT Group: %s ID: %hu"
" to secondary access state: %s\n", (explicit) ? "explicit" :
"implicit", config_item_name(&tg_pt_gp->tg_pt_gp_group.cg_item),
tg_pt_gp->tg_pt_gp_id, (offline) ? "OFFLINE" : "ONLINE");
spin_unlock(&tg_pt_gp_mem->tg_pt_gp_mem_lock);
if (trans_delay_msecs != 0)
msleep_interruptible(trans_delay_msecs);
if (port->sep_tg_pt_secondary_write_md) {
mutex_lock(&port->sep_tg_pt_md_mutex);
core_alua_update_tpg_secondary_metadata(tg_pt_gp_mem, port);
mutex_unlock(&port->sep_tg_pt_md_mutex);
}
return 0;
}
struct t10_alua_lba_map *
core_alua_allocate_lba_map(struct list_head *list,
u64 first_lba, u64 last_lba)
{
struct t10_alua_lba_map *lba_map;
lba_map = kmem_cache_zalloc(t10_alua_lba_map_cache, GFP_KERNEL);
if (!lba_map) {
pr_err("Unable to allocate struct t10_alua_lba_map\n");
return ERR_PTR(-ENOMEM);
}
INIT_LIST_HEAD(&lba_map->lba_map_mem_list);
lba_map->lba_map_first_lba = first_lba;
lba_map->lba_map_last_lba = last_lba;
list_add_tail(&lba_map->lba_map_list, list);
return lba_map;
}
int
core_alua_allocate_lba_map_mem(struct t10_alua_lba_map *lba_map,
int pg_id, int state)
{
struct t10_alua_lba_map_member *lba_map_mem;
list_for_each_entry(lba_map_mem, &lba_map->lba_map_mem_list,
lba_map_mem_list) {
if (lba_map_mem->lba_map_mem_alua_pg_id == pg_id) {
pr_err("Duplicate pg_id %d in lba_map\n", pg_id);
return -EINVAL;
}
}
lba_map_mem = kmem_cache_zalloc(t10_alua_lba_map_mem_cache, GFP_KERNEL);
if (!lba_map_mem) {
pr_err("Unable to allocate struct t10_alua_lba_map_mem\n");
return -ENOMEM;
}
lba_map_mem->lba_map_mem_alua_state = state;
lba_map_mem->lba_map_mem_alua_pg_id = pg_id;
list_add_tail(&lba_map_mem->lba_map_mem_list,
&lba_map->lba_map_mem_list);
return 0;
}
void
core_alua_free_lba_map(struct list_head *lba_list)
{
struct t10_alua_lba_map *lba_map, *lba_map_tmp;
struct t10_alua_lba_map_member *lba_map_mem, *lba_map_mem_tmp;
list_for_each_entry_safe(lba_map, lba_map_tmp, lba_list,
lba_map_list) {
list_for_each_entry_safe(lba_map_mem, lba_map_mem_tmp,
&lba_map->lba_map_mem_list,
lba_map_mem_list) {
list_del(&lba_map_mem->lba_map_mem_list);
kmem_cache_free(t10_alua_lba_map_mem_cache,
lba_map_mem);
}
list_del(&lba_map->lba_map_list);
kmem_cache_free(t10_alua_lba_map_cache, lba_map);
}
}
void
core_alua_set_lba_map(struct se_device *dev, struct list_head *lba_map_list,
int segment_size, int segment_mult)
{
struct list_head old_lba_map_list;
struct t10_alua_tg_pt_gp *tg_pt_gp;
int activate = 0, supported;
INIT_LIST_HEAD(&old_lba_map_list);
spin_lock(&dev->t10_alua.lba_map_lock);
dev->t10_alua.lba_map_segment_size = segment_size;
dev->t10_alua.lba_map_segment_multiplier = segment_mult;
list_splice_init(&dev->t10_alua.lba_map_list, &old_lba_map_list);
if (lba_map_list) {
list_splice_init(lba_map_list, &dev->t10_alua.lba_map_list);
activate = 1;
}
spin_unlock(&dev->t10_alua.lba_map_lock);
spin_lock(&dev->t10_alua.tg_pt_gps_lock);
list_for_each_entry(tg_pt_gp, &dev->t10_alua.tg_pt_gps_list,
tg_pt_gp_list) {
if (!tg_pt_gp->tg_pt_gp_valid_id)
continue;
supported = tg_pt_gp->tg_pt_gp_alua_supported_states;
if (activate)
supported |= ALUA_LBD_SUP;
else
supported &= ~ALUA_LBD_SUP;
tg_pt_gp->tg_pt_gp_alua_supported_states = supported;
}
spin_unlock(&dev->t10_alua.tg_pt_gps_lock);
core_alua_free_lba_map(&old_lba_map_list);
}
struct t10_alua_lu_gp *
core_alua_allocate_lu_gp(const char *name, int def_group)
{
struct t10_alua_lu_gp *lu_gp;
lu_gp = kmem_cache_zalloc(t10_alua_lu_gp_cache, GFP_KERNEL);
if (!lu_gp) {
pr_err("Unable to allocate struct t10_alua_lu_gp\n");
return ERR_PTR(-ENOMEM);
}
INIT_LIST_HEAD(&lu_gp->lu_gp_node);
INIT_LIST_HEAD(&lu_gp->lu_gp_mem_list);
spin_lock_init(&lu_gp->lu_gp_lock);
atomic_set(&lu_gp->lu_gp_ref_cnt, 0);
if (def_group) {
lu_gp->lu_gp_id = alua_lu_gps_counter++;
lu_gp->lu_gp_valid_id = 1;
alua_lu_gps_count++;
}
return lu_gp;
}
int core_alua_set_lu_gp_id(struct t10_alua_lu_gp *lu_gp, u16 lu_gp_id)
{
struct t10_alua_lu_gp *lu_gp_tmp;
u16 lu_gp_id_tmp;
if (lu_gp->lu_gp_valid_id) {
pr_warn("ALUA LU Group already has a valid ID,"
" ignoring request\n");
return -EINVAL;
}
spin_lock(&lu_gps_lock);
if (alua_lu_gps_count == 0x0000ffff) {
pr_err("Maximum ALUA alua_lu_gps_count:"
" 0x0000ffff reached\n");
spin_unlock(&lu_gps_lock);
kmem_cache_free(t10_alua_lu_gp_cache, lu_gp);
return -ENOSPC;
}
again:
lu_gp_id_tmp = (lu_gp_id != 0) ? lu_gp_id :
alua_lu_gps_counter++;
list_for_each_entry(lu_gp_tmp, &lu_gps_list, lu_gp_node) {
if (lu_gp_tmp->lu_gp_id == lu_gp_id_tmp) {
if (!lu_gp_id)
goto again;
pr_warn("ALUA Logical Unit Group ID: %hu"
" already exists, ignoring request\n",
lu_gp_id);
spin_unlock(&lu_gps_lock);
return -EINVAL;
}
}
lu_gp->lu_gp_id = lu_gp_id_tmp;
lu_gp->lu_gp_valid_id = 1;
list_add_tail(&lu_gp->lu_gp_node, &lu_gps_list);
alua_lu_gps_count++;
spin_unlock(&lu_gps_lock);
return 0;
}
static struct t10_alua_lu_gp_member *
core_alua_allocate_lu_gp_mem(struct se_device *dev)
{
struct t10_alua_lu_gp_member *lu_gp_mem;
lu_gp_mem = kmem_cache_zalloc(t10_alua_lu_gp_mem_cache, GFP_KERNEL);
if (!lu_gp_mem) {
pr_err("Unable to allocate struct t10_alua_lu_gp_member\n");
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
spin_lock(&lu_gps_lock);
list_del(&lu_gp->lu_gp_node);
alua_lu_gps_count--;
spin_unlock(&lu_gps_lock);
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
if (lu_gp != default_lu_gp)
__core_alua_attach_lu_gp_mem(lu_gp_mem,
default_lu_gp);
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
struct t10_alua_lu_gp *lu_gp;
struct t10_alua_lu_gp_member *lu_gp_mem;
lu_gp_mem = dev->dev_alua_lu_gp_mem;
if (!lu_gp_mem)
return;
while (atomic_read(&lu_gp_mem->lu_gp_mem_ref_cnt))
cpu_relax();
spin_lock(&lu_gp_mem->lu_gp_mem_lock);
lu_gp = lu_gp_mem->lu_gp;
if (lu_gp) {
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
spin_lock(&lu_gps_lock);
list_for_each_entry(lu_gp, &lu_gps_list, lu_gp_node) {
if (!lu_gp->lu_gp_valid_id)
continue;
ci = &lu_gp->lu_gp_group.cg_item;
if (!strcmp(config_item_name(ci), name)) {
atomic_inc(&lu_gp->lu_gp_ref_cnt);
spin_unlock(&lu_gps_lock);
return lu_gp;
}
}
spin_unlock(&lu_gps_lock);
return NULL;
}
void core_alua_put_lu_gp_from_name(struct t10_alua_lu_gp *lu_gp)
{
spin_lock(&lu_gps_lock);
atomic_dec(&lu_gp->lu_gp_ref_cnt);
spin_unlock(&lu_gps_lock);
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
struct t10_alua_tg_pt_gp *core_alua_allocate_tg_pt_gp(struct se_device *dev,
const char *name, int def_group)
{
struct t10_alua_tg_pt_gp *tg_pt_gp;
tg_pt_gp = kmem_cache_zalloc(t10_alua_tg_pt_gp_cache, GFP_KERNEL);
if (!tg_pt_gp) {
pr_err("Unable to allocate struct t10_alua_tg_pt_gp\n");
return NULL;
}
INIT_LIST_HEAD(&tg_pt_gp->tg_pt_gp_list);
INIT_LIST_HEAD(&tg_pt_gp->tg_pt_gp_mem_list);
mutex_init(&tg_pt_gp->tg_pt_gp_md_mutex);
spin_lock_init(&tg_pt_gp->tg_pt_gp_lock);
atomic_set(&tg_pt_gp->tg_pt_gp_ref_cnt, 0);
INIT_DELAYED_WORK(&tg_pt_gp->tg_pt_gp_transition_work,
core_alua_do_transition_tg_pt_work);
tg_pt_gp->tg_pt_gp_dev = dev;
atomic_set(&tg_pt_gp->tg_pt_gp_alua_access_state,
ALUA_ACCESS_STATE_ACTIVE_OPTIMIZED);
tg_pt_gp->tg_pt_gp_alua_access_type =
TPGS_EXPLICIT_ALUA | TPGS_IMPLICIT_ALUA;
tg_pt_gp->tg_pt_gp_nonop_delay_msecs = ALUA_DEFAULT_NONOP_DELAY_MSECS;
tg_pt_gp->tg_pt_gp_trans_delay_msecs = ALUA_DEFAULT_TRANS_DELAY_MSECS;
tg_pt_gp->tg_pt_gp_implicit_trans_secs = ALUA_DEFAULT_IMPLICIT_TRANS_SECS;
tg_pt_gp->tg_pt_gp_alua_supported_states =
ALUA_T_SUP | ALUA_O_SUP |
ALUA_U_SUP | ALUA_S_SUP | ALUA_AN_SUP | ALUA_AO_SUP;
if (def_group) {
spin_lock(&dev->t10_alua.tg_pt_gps_lock);
tg_pt_gp->tg_pt_gp_id =
dev->t10_alua.alua_tg_pt_gps_counter++;
tg_pt_gp->tg_pt_gp_valid_id = 1;
dev->t10_alua.alua_tg_pt_gps_count++;
list_add_tail(&tg_pt_gp->tg_pt_gp_list,
&dev->t10_alua.tg_pt_gps_list);
spin_unlock(&dev->t10_alua.tg_pt_gps_lock);
}
return tg_pt_gp;
}
int core_alua_set_tg_pt_gp_id(
struct t10_alua_tg_pt_gp *tg_pt_gp,
u16 tg_pt_gp_id)
{
struct se_device *dev = tg_pt_gp->tg_pt_gp_dev;
struct t10_alua_tg_pt_gp *tg_pt_gp_tmp;
u16 tg_pt_gp_id_tmp;
if (tg_pt_gp->tg_pt_gp_valid_id) {
pr_warn("ALUA TG PT Group already has a valid ID,"
" ignoring request\n");
return -EINVAL;
}
spin_lock(&dev->t10_alua.tg_pt_gps_lock);
if (dev->t10_alua.alua_tg_pt_gps_count == 0x0000ffff) {
pr_err("Maximum ALUA alua_tg_pt_gps_count:"
" 0x0000ffff reached\n");
spin_unlock(&dev->t10_alua.tg_pt_gps_lock);
kmem_cache_free(t10_alua_tg_pt_gp_cache, tg_pt_gp);
return -ENOSPC;
}
again:
tg_pt_gp_id_tmp = (tg_pt_gp_id != 0) ? tg_pt_gp_id :
dev->t10_alua.alua_tg_pt_gps_counter++;
list_for_each_entry(tg_pt_gp_tmp, &dev->t10_alua.tg_pt_gps_list,
tg_pt_gp_list) {
if (tg_pt_gp_tmp->tg_pt_gp_id == tg_pt_gp_id_tmp) {
if (!tg_pt_gp_id)
goto again;
pr_err("ALUA Target Port Group ID: %hu already"
" exists, ignoring request\n", tg_pt_gp_id);
spin_unlock(&dev->t10_alua.tg_pt_gps_lock);
return -EINVAL;
}
}
tg_pt_gp->tg_pt_gp_id = tg_pt_gp_id_tmp;
tg_pt_gp->tg_pt_gp_valid_id = 1;
list_add_tail(&tg_pt_gp->tg_pt_gp_list,
&dev->t10_alua.tg_pt_gps_list);
dev->t10_alua.alua_tg_pt_gps_count++;
spin_unlock(&dev->t10_alua.tg_pt_gps_lock);
return 0;
}
struct t10_alua_tg_pt_gp_member *core_alua_allocate_tg_pt_gp_mem(
struct se_port *port)
{
struct t10_alua_tg_pt_gp_member *tg_pt_gp_mem;
tg_pt_gp_mem = kmem_cache_zalloc(t10_alua_tg_pt_gp_mem_cache,
GFP_KERNEL);
if (!tg_pt_gp_mem) {
pr_err("Unable to allocate struct t10_alua_tg_pt_gp_member\n");
return ERR_PTR(-ENOMEM);
}
INIT_LIST_HEAD(&tg_pt_gp_mem->tg_pt_gp_mem_list);
spin_lock_init(&tg_pt_gp_mem->tg_pt_gp_mem_lock);
atomic_set(&tg_pt_gp_mem->tg_pt_gp_mem_ref_cnt, 0);
tg_pt_gp_mem->tg_pt = port;
port->sep_alua_tg_pt_gp_mem = tg_pt_gp_mem;
return tg_pt_gp_mem;
}
void core_alua_free_tg_pt_gp(
struct t10_alua_tg_pt_gp *tg_pt_gp)
{
struct se_device *dev = tg_pt_gp->tg_pt_gp_dev;
struct t10_alua_tg_pt_gp_member *tg_pt_gp_mem, *tg_pt_gp_mem_tmp;
spin_lock(&dev->t10_alua.tg_pt_gps_lock);
list_del(&tg_pt_gp->tg_pt_gp_list);
dev->t10_alua.alua_tg_pt_gps_counter--;
spin_unlock(&dev->t10_alua.tg_pt_gps_lock);
flush_delayed_work(&tg_pt_gp->tg_pt_gp_transition_work);
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
if (tg_pt_gp != dev->t10_alua.default_tg_pt_gp) {
__core_alua_attach_tg_pt_gp_mem(tg_pt_gp_mem,
dev->t10_alua.default_tg_pt_gp);
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
struct t10_alua_tg_pt_gp *tg_pt_gp;
struct t10_alua_tg_pt_gp_member *tg_pt_gp_mem;
tg_pt_gp_mem = port->sep_alua_tg_pt_gp_mem;
if (!tg_pt_gp_mem)
return;
while (atomic_read(&tg_pt_gp_mem->tg_pt_gp_mem_ref_cnt))
cpu_relax();
spin_lock(&tg_pt_gp_mem->tg_pt_gp_mem_lock);
tg_pt_gp = tg_pt_gp_mem->tg_pt_gp;
if (tg_pt_gp) {
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
struct se_device *dev, const char *name)
{
struct t10_alua_tg_pt_gp *tg_pt_gp;
struct config_item *ci;
spin_lock(&dev->t10_alua.tg_pt_gps_lock);
list_for_each_entry(tg_pt_gp, &dev->t10_alua.tg_pt_gps_list,
tg_pt_gp_list) {
if (!tg_pt_gp->tg_pt_gp_valid_id)
continue;
ci = &tg_pt_gp->tg_pt_gp_group.cg_item;
if (!strcmp(config_item_name(ci), name)) {
atomic_inc(&tg_pt_gp->tg_pt_gp_ref_cnt);
spin_unlock(&dev->t10_alua.tg_pt_gps_lock);
return tg_pt_gp;
}
}
spin_unlock(&dev->t10_alua.tg_pt_gps_lock);
return NULL;
}
static void core_alua_put_tg_pt_gp_from_name(
struct t10_alua_tg_pt_gp *tg_pt_gp)
{
struct se_device *dev = tg_pt_gp->tg_pt_gp_dev;
spin_lock(&dev->t10_alua.tg_pt_gps_lock);
atomic_dec(&tg_pt_gp->tg_pt_gp_ref_cnt);
spin_unlock(&dev->t10_alua.tg_pt_gps_lock);
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
struct config_item *tg_pt_ci;
struct t10_alua_tg_pt_gp *tg_pt_gp;
struct t10_alua_tg_pt_gp_member *tg_pt_gp_mem;
ssize_t len = 0;
tg_pt_gp_mem = port->sep_alua_tg_pt_gp_mem;
if (!tg_pt_gp_mem)
return len;
spin_lock(&tg_pt_gp_mem->tg_pt_gp_mem_lock);
tg_pt_gp = tg_pt_gp_mem->tg_pt_gp;
if (tg_pt_gp) {
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
struct se_device *dev = port->sep_lun->lun_se_dev;
struct t10_alua_tg_pt_gp *tg_pt_gp = NULL, *tg_pt_gp_new = NULL;
struct t10_alua_tg_pt_gp_member *tg_pt_gp_mem;
unsigned char buf[TG_PT_GROUP_NAME_BUF];
int move = 0;
tpg = port->sep_tpg;
lun = port->sep_lun;
tg_pt_gp_mem = port->sep_alua_tg_pt_gp_mem;
if (!tg_pt_gp_mem)
return 0;
if (count > TG_PT_GROUP_NAME_BUF) {
pr_err("ALUA Target Port Group alias too large!\n");
return -EINVAL;
}
memset(buf, 0, TG_PT_GROUP_NAME_BUF);
memcpy(buf, page, count);
if (strcmp(strstrip(buf), "NULL")) {
tg_pt_gp_new = core_alua_get_tg_pt_gp_by_name(dev,
strstrip(buf));
if (!tg_pt_gp_new)
return -ENODEV;
}
spin_lock(&tg_pt_gp_mem->tg_pt_gp_mem_lock);
tg_pt_gp = tg_pt_gp_mem->tg_pt_gp;
if (tg_pt_gp) {
if (!tg_pt_gp_new) {
pr_debug("Target_Core_ConfigFS: Moving"
" %s/tpgt_%hu/%s from ALUA Target Port Group:"
" alua/%s, ID: %hu back to"
" default_tg_pt_gp\n",
tpg->se_tpg_tfo->tpg_get_wwn(tpg),
tpg->se_tpg_tfo->tpg_get_tag(tpg),
config_item_name(&lun->lun_group.cg_item),
config_item_name(
&tg_pt_gp->tg_pt_gp_group.cg_item),
tg_pt_gp->tg_pt_gp_id);
__core_alua_drop_tg_pt_gp_mem(tg_pt_gp_mem, tg_pt_gp);
__core_alua_attach_tg_pt_gp_mem(tg_pt_gp_mem,
dev->t10_alua.default_tg_pt_gp);
spin_unlock(&tg_pt_gp_mem->tg_pt_gp_mem_lock);
return count;
}
__core_alua_drop_tg_pt_gp_mem(tg_pt_gp_mem, tg_pt_gp);
move = 1;
}
__core_alua_attach_tg_pt_gp_mem(tg_pt_gp_mem, tg_pt_gp_new);
spin_unlock(&tg_pt_gp_mem->tg_pt_gp_mem_lock);
pr_debug("Target_Core_ConfigFS: %s %s/tpgt_%hu/%s to ALUA"
" Target Port Group: alua/%s, ID: %hu\n", (move) ?
"Moving" : "Adding", tpg->se_tpg_tfo->tpg_get_wwn(tpg),
tpg->se_tpg_tfo->tpg_get_tag(tpg),
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
if ((tg_pt_gp->tg_pt_gp_alua_access_type & TPGS_EXPLICIT_ALUA) &&
(tg_pt_gp->tg_pt_gp_alua_access_type & TPGS_IMPLICIT_ALUA))
return sprintf(page, "Implicit and Explicit\n");
else if (tg_pt_gp->tg_pt_gp_alua_access_type & TPGS_IMPLICIT_ALUA)
return sprintf(page, "Implicit\n");
else if (tg_pt_gp->tg_pt_gp_alua_access_type & TPGS_EXPLICIT_ALUA)
return sprintf(page, "Explicit\n");
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
ret = kstrtoul(page, 0, &tmp);
if (ret < 0) {
pr_err("Unable to extract alua_access_type\n");
return ret;
}
if ((tmp != 0) && (tmp != 1) && (tmp != 2) && (tmp != 3)) {
pr_err("Illegal value for alua_access_type:"
" %lu\n", tmp);
return -EINVAL;
}
if (tmp == 3)
tg_pt_gp->tg_pt_gp_alua_access_type =
TPGS_IMPLICIT_ALUA | TPGS_EXPLICIT_ALUA;
else if (tmp == 2)
tg_pt_gp->tg_pt_gp_alua_access_type = TPGS_EXPLICIT_ALUA;
else if (tmp == 1)
tg_pt_gp->tg_pt_gp_alua_access_type = TPGS_IMPLICIT_ALUA;
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
ret = kstrtoul(page, 0, &tmp);
if (ret < 0) {
pr_err("Unable to extract nonop_delay_msecs\n");
return ret;
}
if (tmp > ALUA_MAX_NONOP_DELAY_MSECS) {
pr_err("Passed nonop_delay_msecs: %lu, exceeds"
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
ret = kstrtoul(page, 0, &tmp);
if (ret < 0) {
pr_err("Unable to extract trans_delay_msecs\n");
return ret;
}
if (tmp > ALUA_MAX_TRANS_DELAY_MSECS) {
pr_err("Passed trans_delay_msecs: %lu, exceeds"
" ALUA_MAX_TRANS_DELAY_MSECS: %d\n", tmp,
ALUA_MAX_TRANS_DELAY_MSECS);
return -EINVAL;
}
tg_pt_gp->tg_pt_gp_trans_delay_msecs = (int)tmp;
return count;
}
ssize_t core_alua_show_implicit_trans_secs(
struct t10_alua_tg_pt_gp *tg_pt_gp,
char *page)
{
return sprintf(page, "%d\n", tg_pt_gp->tg_pt_gp_implicit_trans_secs);
}
ssize_t core_alua_store_implicit_trans_secs(
struct t10_alua_tg_pt_gp *tg_pt_gp,
const char *page,
size_t count)
{
unsigned long tmp;
int ret;
ret = kstrtoul(page, 0, &tmp);
if (ret < 0) {
pr_err("Unable to extract implicit_trans_secs\n");
return ret;
}
if (tmp > ALUA_MAX_IMPLICIT_TRANS_SECS) {
pr_err("Passed implicit_trans_secs: %lu, exceeds"
" ALUA_MAX_IMPLICIT_TRANS_SECS: %d\n", tmp,
ALUA_MAX_IMPLICIT_TRANS_SECS);
return -EINVAL;
}
tg_pt_gp->tg_pt_gp_implicit_trans_secs = (int)tmp;
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
ret = kstrtoul(page, 0, &tmp);
if (ret < 0) {
pr_err("Unable to extract preferred ALUA value\n");
return ret;
}
if ((tmp != 0) && (tmp != 1)) {
pr_err("Illegal value for preferred ALUA: %lu\n", tmp);
return -EINVAL;
}
tg_pt_gp->tg_pt_gp_pref = (int)tmp;
return count;
}
ssize_t core_alua_show_offline_bit(struct se_lun *lun, char *page)
{
if (!lun->lun_sep)
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
if (!lun->lun_sep)
return -ENODEV;
ret = kstrtoul(page, 0, &tmp);
if (ret < 0) {
pr_err("Unable to extract alua_tg_pt_offline value\n");
return ret;
}
if ((tmp != 0) && (tmp != 1)) {
pr_err("Illegal value for alua_tg_pt_offline: %lu\n",
tmp);
return -EINVAL;
}
tg_pt_gp_mem = lun->lun_sep->sep_alua_tg_pt_gp_mem;
if (!tg_pt_gp_mem) {
pr_err("Unable to locate *tg_pt_gp_mem\n");
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
ret = kstrtoul(page, 0, &tmp);
if (ret < 0) {
pr_err("Unable to extract alua_tg_pt_status\n");
return ret;
}
if ((tmp != ALUA_STATUS_NONE) &&
(tmp != ALUA_STATUS_ALTERED_BY_EXPLICIT_STPG) &&
(tmp != ALUA_STATUS_ALTERED_BY_IMPLICIT_ALUA)) {
pr_err("Illegal value for alua_tg_pt_status: %lu\n",
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
ret = kstrtoul(page, 0, &tmp);
if (ret < 0) {
pr_err("Unable to extract alua_tg_pt_write_md\n");
return ret;
}
if ((tmp != 0) && (tmp != 1)) {
pr_err("Illegal value for alua_tg_pt_write_md:"
" %lu\n", tmp);
return -EINVAL;
}
lun->lun_sep->sep_tg_pt_secondary_write_md = (int)tmp;
return count;
}
int core_setup_alua(struct se_device *dev)
{
if (dev->transport->transport_type != TRANSPORT_PLUGIN_PHBA_PDEV &&
!(dev->se_hba->hba_flags & HBA_FLAGS_INTERNAL_USE)) {
struct t10_alua_lu_gp_member *lu_gp_mem;
lu_gp_mem = core_alua_allocate_lu_gp_mem(dev);
if (IS_ERR(lu_gp_mem))
return PTR_ERR(lu_gp_mem);
spin_lock(&lu_gp_mem->lu_gp_mem_lock);
__core_alua_attach_lu_gp_mem(lu_gp_mem,
default_lu_gp);
spin_unlock(&lu_gp_mem->lu_gp_mem_lock);
pr_debug("%s: Adding to default ALUA LU Group:"
" core/alua/lu_gps/default_lu_gp\n",
dev->transport->name);
}
return 0;
}
