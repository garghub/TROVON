static void spc_fill_alua_data(struct se_port *port, unsigned char *buf)
{
struct t10_alua_tg_pt_gp *tg_pt_gp;
struct t10_alua_tg_pt_gp_member *tg_pt_gp_mem;
buf[5] = 0x80;
if (!port)
return;
tg_pt_gp_mem = port->sep_alua_tg_pt_gp_mem;
if (!tg_pt_gp_mem)
return;
spin_lock(&tg_pt_gp_mem->tg_pt_gp_mem_lock);
tg_pt_gp = tg_pt_gp_mem->tg_pt_gp;
if (tg_pt_gp)
buf[5] |= tg_pt_gp->tg_pt_gp_alua_access_type;
spin_unlock(&tg_pt_gp_mem->tg_pt_gp_mem_lock);
}
static int spc_emulate_inquiry_std(struct se_cmd *cmd, char *buf)
{
struct se_lun *lun = cmd->se_lun;
struct se_device *dev = cmd->se_dev;
if (dev->transport->get_device_type(dev) == TYPE_TAPE)
buf[1] = 0x80;
buf[2] = dev->transport->get_device_rev(dev);
buf[3] = 2;
if (dev->se_sub_dev->t10_alua.alua_type == SPC3_ALUA_EMULATED)
spc_fill_alua_data(lun->lun_sep, buf);
buf[7] = 0x2;
snprintf(&buf[8], 8, "LIO-ORG");
snprintf(&buf[16], 16, "%s", dev->se_sub_dev->t10_wwn.model);
snprintf(&buf[32], 4, "%s", dev->se_sub_dev->t10_wwn.revision);
buf[4] = 31;
return 0;
}
static int spc_emulate_evpd_80(struct se_cmd *cmd, unsigned char *buf)
{
struct se_device *dev = cmd->se_dev;
u16 len = 0;
if (dev->se_sub_dev->su_dev_flags &
SDF_EMULATED_VPD_UNIT_SERIAL) {
u32 unit_serial_len;
unit_serial_len = strlen(dev->se_sub_dev->t10_wwn.unit_serial);
unit_serial_len++;
len += sprintf(&buf[4], "%s",
dev->se_sub_dev->t10_wwn.unit_serial);
len++;
buf[3] = len;
}
return 0;
}
static void spc_parse_naa_6h_vendor_specific(struct se_device *dev,
unsigned char *buf)
{
unsigned char *p = &dev->se_sub_dev->t10_wwn.unit_serial[0];
int cnt;
bool next = true;
for (cnt = 0; *p && cnt < 13; p++) {
int val = hex_to_bin(*p);
if (val < 0)
continue;
if (next) {
next = false;
buf[cnt++] |= val;
} else {
next = true;
buf[cnt] = val << 4;
}
}
}
static int spc_emulate_evpd_83(struct se_cmd *cmd, unsigned char *buf)
{
struct se_device *dev = cmd->se_dev;
struct se_lun *lun = cmd->se_lun;
struct se_port *port = NULL;
struct se_portal_group *tpg = NULL;
struct t10_alua_lu_gp_member *lu_gp_mem;
struct t10_alua_tg_pt_gp *tg_pt_gp;
struct t10_alua_tg_pt_gp_member *tg_pt_gp_mem;
unsigned char *prod = &dev->se_sub_dev->t10_wwn.model[0];
u32 prod_len;
u32 unit_serial_len, off = 0;
u16 len = 0, id_len;
off = 4;
if (!(dev->se_sub_dev->su_dev_flags & SDF_EMULATED_VPD_UNIT_SERIAL))
goto check_t10_vend_desc;
buf[off++] = 0x1;
buf[off] = 0x00;
buf[off++] |= 0x3;
off++;
buf[off++] = 0x10;
buf[off++] = (0x6 << 4);
buf[off++] = 0x01;
buf[off++] = 0x40;
buf[off] = (0x5 << 4);
spc_parse_naa_6h_vendor_specific(dev, &buf[off]);
len = 20;
off = (len + 4);
check_t10_vend_desc:
id_len = 8;
prod_len = 4;
prod_len += 8;
prod_len += strlen(prod);
prod_len++;
if (dev->se_sub_dev->su_dev_flags &
SDF_EMULATED_VPD_UNIT_SERIAL) {
unit_serial_len =
strlen(&dev->se_sub_dev->t10_wwn.unit_serial[0]);
unit_serial_len++;
id_len += sprintf(&buf[off+12], "%s:%s", prod,
&dev->se_sub_dev->t10_wwn.unit_serial[0]);
}
buf[off] = 0x2;
buf[off+1] = 0x1;
buf[off+2] = 0x0;
memcpy(&buf[off+4], "LIO-ORG", 8);
id_len++;
buf[off+3] = id_len;
len += (id_len + 4);
off += (id_len + 4);
port = lun->lun_sep;
if (port) {
struct t10_alua_lu_gp *lu_gp;
u32 padding, scsi_name_len;
u16 lu_gp_id = 0;
u16 tg_pt_gp_id = 0;
u16 tpgt;
tpg = port->sep_tpg;
buf[off] =
(tpg->se_tpg_tfo->get_fabric_proto_ident(tpg) << 4);
buf[off++] |= 0x1;
buf[off] = 0x80;
buf[off] |= 0x10;
buf[off++] |= 0x4;
off++;
buf[off++] = 4;
off += 2;
buf[off++] = ((port->sep_rtpi >> 8) & 0xff);
buf[off++] = (port->sep_rtpi & 0xff);
len += 8;
if (dev->se_sub_dev->t10_alua.alua_type !=
SPC3_ALUA_EMULATED)
goto check_scsi_name;
tg_pt_gp_mem = port->sep_alua_tg_pt_gp_mem;
if (!tg_pt_gp_mem)
goto check_lu_gp;
spin_lock(&tg_pt_gp_mem->tg_pt_gp_mem_lock);
tg_pt_gp = tg_pt_gp_mem->tg_pt_gp;
if (!tg_pt_gp) {
spin_unlock(&tg_pt_gp_mem->tg_pt_gp_mem_lock);
goto check_lu_gp;
}
tg_pt_gp_id = tg_pt_gp->tg_pt_gp_id;
spin_unlock(&tg_pt_gp_mem->tg_pt_gp_mem_lock);
buf[off] =
(tpg->se_tpg_tfo->get_fabric_proto_ident(tpg) << 4);
buf[off++] |= 0x1;
buf[off] = 0x80;
buf[off] |= 0x10;
buf[off++] |= 0x5;
off++;
buf[off++] = 4;
off += 2;
buf[off++] = ((tg_pt_gp_id >> 8) & 0xff);
buf[off++] = (tg_pt_gp_id & 0xff);
len += 8;
check_lu_gp:
lu_gp_mem = dev->dev_alua_lu_gp_mem;
if (!lu_gp_mem)
goto check_scsi_name;
spin_lock(&lu_gp_mem->lu_gp_mem_lock);
lu_gp = lu_gp_mem->lu_gp;
if (!lu_gp) {
spin_unlock(&lu_gp_mem->lu_gp_mem_lock);
goto check_scsi_name;
}
lu_gp_id = lu_gp->lu_gp_id;
spin_unlock(&lu_gp_mem->lu_gp_mem_lock);
buf[off++] |= 0x1;
buf[off++] |= 0x6;
off++;
buf[off++] = 4;
off += 2;
buf[off++] = ((lu_gp_id >> 8) & 0xff);
buf[off++] = (lu_gp_id & 0xff);
len += 8;
check_scsi_name:
scsi_name_len = strlen(tpg->se_tpg_tfo->tpg_get_wwn(tpg));
scsi_name_len += 10;
padding = ((-scsi_name_len) & 3);
if (padding != 0)
scsi_name_len += padding;
scsi_name_len += 4;
buf[off] =
(tpg->se_tpg_tfo->get_fabric_proto_ident(tpg) << 4);
buf[off++] |= 0x3;
buf[off] = 0x80;
buf[off] |= 0x10;
buf[off++] |= 0x8;
off += 2;
tpgt = tpg->se_tpg_tfo->tpg_get_tag(tpg);
scsi_name_len = sprintf(&buf[off], "%s,t,0x%04x",
tpg->se_tpg_tfo->tpg_get_wwn(tpg), tpgt);
scsi_name_len += 1 ;
if (padding)
scsi_name_len += padding;
buf[off-1] = scsi_name_len;
off += scsi_name_len;
len += (scsi_name_len + 4);
}
buf[2] = ((len >> 8) & 0xff);
buf[3] = (len & 0xff);
return 0;
}
static int spc_emulate_evpd_86(struct se_cmd *cmd, unsigned char *buf)
{
buf[3] = 0x3c;
buf[5] = 0x07;
if (cmd->se_dev->se_sub_dev->se_dev_attrib.emulate_write_cache > 0)
buf[6] = 0x01;
return 0;
}
static int spc_emulate_evpd_b0(struct se_cmd *cmd, unsigned char *buf)
{
struct se_device *dev = cmd->se_dev;
u32 max_sectors;
int have_tp = 0;
if (dev->se_sub_dev->se_dev_attrib.emulate_tpu || dev->se_sub_dev->se_dev_attrib.emulate_tpws)
have_tp = 1;
buf[0] = dev->transport->get_device_type(dev);
buf[3] = have_tp ? 0x3c : 0x10;
buf[4] = 0x01;
put_unaligned_be16(1, &buf[6]);
max_sectors = min(dev->se_sub_dev->se_dev_attrib.fabric_max_sectors,
dev->se_sub_dev->se_dev_attrib.hw_max_sectors);
put_unaligned_be32(max_sectors, &buf[8]);
put_unaligned_be32(dev->se_sub_dev->se_dev_attrib.optimal_sectors, &buf[12]);
if (!have_tp)
return 0;
put_unaligned_be32(dev->se_sub_dev->se_dev_attrib.max_unmap_lba_count, &buf[20]);
put_unaligned_be32(dev->se_sub_dev->se_dev_attrib.max_unmap_block_desc_count,
&buf[24]);
put_unaligned_be32(dev->se_sub_dev->se_dev_attrib.unmap_granularity, &buf[28]);
put_unaligned_be32(dev->se_sub_dev->se_dev_attrib.unmap_granularity_alignment,
&buf[32]);
if (dev->se_sub_dev->se_dev_attrib.unmap_granularity_alignment != 0)
buf[32] |= 0x80;
return 0;
}
static int spc_emulate_evpd_b1(struct se_cmd *cmd, unsigned char *buf)
{
struct se_device *dev = cmd->se_dev;
buf[0] = dev->transport->get_device_type(dev);
buf[3] = 0x3c;
buf[5] = dev->se_sub_dev->se_dev_attrib.is_nonrot ? 1 : 0;
return 0;
}
static int spc_emulate_evpd_b2(struct se_cmd *cmd, unsigned char *buf)
{
struct se_device *dev = cmd->se_dev;
buf[0] = dev->transport->get_device_type(dev);
put_unaligned_be16(0x0004, &buf[2]);
buf[4] = 0x00;
if (dev->se_sub_dev->se_dev_attrib.emulate_tpu != 0)
buf[5] = 0x80;
if (dev->se_sub_dev->se_dev_attrib.emulate_tpws != 0)
buf[5] |= 0x40;
return 0;
}
static int spc_emulate_evpd_00(struct se_cmd *cmd, unsigned char *buf)
{
int p;
if (cmd->se_dev->se_sub_dev->su_dev_flags &
SDF_EMULATED_VPD_UNIT_SERIAL) {
buf[3] = ARRAY_SIZE(evpd_handlers);
for (p = 0; p < ARRAY_SIZE(evpd_handlers); ++p)
buf[p + 4] = evpd_handlers[p].page;
}
return 0;
}
static int spc_emulate_inquiry(struct se_cmd *cmd)
{
struct se_device *dev = cmd->se_dev;
struct se_portal_group *tpg = cmd->se_lun->lun_sep->sep_tpg;
unsigned char *buf, *map_buf;
unsigned char *cdb = cmd->t_task_cdb;
int p, ret;
map_buf = transport_kmap_data_sg(cmd);
if (cmd->data_length < SE_INQUIRY_BUF &&
(cmd->se_cmd_flags & SCF_PASSTHROUGH_SG_TO_MEM_NOALLOC)) {
buf = kzalloc(SE_INQUIRY_BUF, GFP_KERNEL);
if (!buf) {
transport_kunmap_data_sg(cmd);
cmd->scsi_sense_reason = TCM_LOGICAL_UNIT_COMMUNICATION_FAILURE;
return -ENOMEM;
}
} else {
buf = map_buf;
}
if (dev == tpg->tpg_virt_lun0.lun_se_dev)
buf[0] = 0x3f;
else
buf[0] = dev->transport->get_device_type(dev);
if (!(cdb[1] & 0x1)) {
if (cdb[2]) {
pr_err("INQUIRY with EVPD==0 but PAGE CODE=%02x\n",
cdb[2]);
cmd->scsi_sense_reason = TCM_INVALID_CDB_FIELD;
ret = -EINVAL;
goto out;
}
ret = spc_emulate_inquiry_std(cmd, buf);
goto out;
}
for (p = 0; p < ARRAY_SIZE(evpd_handlers); ++p) {
if (cdb[2] == evpd_handlers[p].page) {
buf[1] = cdb[2];
ret = evpd_handlers[p].emulate(cmd, buf);
goto out;
}
}
pr_err("Unknown VPD Code: 0x%02x\n", cdb[2]);
cmd->scsi_sense_reason = TCM_INVALID_CDB_FIELD;
ret = -EINVAL;
out:
if (buf != map_buf) {
memcpy(map_buf, buf, cmd->data_length);
kfree(buf);
}
transport_kunmap_data_sg(cmd);
if (!ret)
target_complete_cmd(cmd, GOOD);
return ret;
}
static int spc_modesense_rwrecovery(unsigned char *p)
{
p[0] = 0x01;
p[1] = 0x0a;
return 12;
}
static int spc_modesense_control(struct se_device *dev, unsigned char *p)
{
p[0] = 0x0a;
p[1] = 0x0a;
p[2] = 2;
p[3] = (dev->se_sub_dev->se_dev_attrib.emulate_rest_reord == 1) ? 0x00 : 0x10;
p[4] = (dev->se_sub_dev->se_dev_attrib.emulate_ua_intlck_ctrl == 2) ? 0x30 :
(dev->se_sub_dev->se_dev_attrib.emulate_ua_intlck_ctrl == 1) ? 0x20 : 0x00;
p[5] = (dev->se_sub_dev->se_dev_attrib.emulate_tas) ? 0x40 : 0x00;
p[8] = 0xff;
p[9] = 0xff;
p[11] = 30;
return 12;
}
static int spc_modesense_caching(struct se_device *dev, unsigned char *p)
{
p[0] = 0x08;
p[1] = 0x12;
if (dev->se_sub_dev->se_dev_attrib.emulate_write_cache > 0)
p[2] = 0x04;
p[12] = 0x20;
return 20;
}
static void spc_modesense_write_protect(unsigned char *buf, int type)
{
switch (type) {
case TYPE_DISK:
case TYPE_TAPE:
default:
buf[0] |= 0x80;
break;
}
}
static void spc_modesense_dpofua(unsigned char *buf, int type)
{
switch (type) {
case TYPE_DISK:
buf[0] |= 0x10;
break;
default:
break;
}
}
static int spc_emulate_modesense(struct se_cmd *cmd)
{
struct se_device *dev = cmd->se_dev;
char *cdb = cmd->t_task_cdb;
unsigned char *rbuf;
int type = dev->transport->get_device_type(dev);
int ten = (cmd->t_task_cdb[0] == MODE_SENSE_10);
int offset = ten ? 8 : 4;
int length = 0;
unsigned char buf[SE_MODE_PAGE_BUF];
memset(buf, 0, SE_MODE_PAGE_BUF);
switch (cdb[2] & 0x3f) {
case 0x01:
length = spc_modesense_rwrecovery(&buf[offset]);
break;
case 0x08:
length = spc_modesense_caching(dev, &buf[offset]);
break;
case 0x0a:
length = spc_modesense_control(dev, &buf[offset]);
break;
case 0x3f:
length = spc_modesense_rwrecovery(&buf[offset]);
length += spc_modesense_caching(dev, &buf[offset+length]);
length += spc_modesense_control(dev, &buf[offset+length]);
break;
default:
pr_err("MODE SENSE: unimplemented page/subpage: 0x%02x/0x%02x\n",
cdb[2] & 0x3f, cdb[3]);
cmd->scsi_sense_reason = TCM_UNKNOWN_MODE_PAGE;
return -EINVAL;
}
offset += length;
if (ten) {
offset -= 2;
buf[0] = (offset >> 8) & 0xff;
buf[1] = offset & 0xff;
if ((cmd->se_lun->lun_access & TRANSPORT_LUNFLAGS_READ_ONLY) ||
(cmd->se_deve &&
(cmd->se_deve->lun_flags & TRANSPORT_LUNFLAGS_READ_ONLY)))
spc_modesense_write_protect(&buf[3], type);
if ((dev->se_sub_dev->se_dev_attrib.emulate_write_cache > 0) &&
(dev->se_sub_dev->se_dev_attrib.emulate_fua_write > 0))
spc_modesense_dpofua(&buf[3], type);
if ((offset + 2) > cmd->data_length)
offset = cmd->data_length;
} else {
offset -= 1;
buf[0] = offset & 0xff;
if ((cmd->se_lun->lun_access & TRANSPORT_LUNFLAGS_READ_ONLY) ||
(cmd->se_deve &&
(cmd->se_deve->lun_flags & TRANSPORT_LUNFLAGS_READ_ONLY)))
spc_modesense_write_protect(&buf[2], type);
if ((dev->se_sub_dev->se_dev_attrib.emulate_write_cache > 0) &&
(dev->se_sub_dev->se_dev_attrib.emulate_fua_write > 0))
spc_modesense_dpofua(&buf[2], type);
if ((offset + 1) > cmd->data_length)
offset = cmd->data_length;
}
rbuf = transport_kmap_data_sg(cmd);
memcpy(rbuf, buf, offset);
transport_kunmap_data_sg(cmd);
target_complete_cmd(cmd, GOOD);
return 0;
}
static int spc_emulate_request_sense(struct se_cmd *cmd)
{
unsigned char *cdb = cmd->t_task_cdb;
unsigned char *rbuf;
u8 ua_asc = 0, ua_ascq = 0;
unsigned char buf[SE_SENSE_BUF];
memset(buf, 0, SE_SENSE_BUF);
if (cdb[1] & 0x01) {
pr_err("REQUEST_SENSE description emulation not"
" supported\n");
cmd->scsi_sense_reason = TCM_INVALID_CDB_FIELD;
return -ENOSYS;
}
rbuf = transport_kmap_data_sg(cmd);
if (cmd->scsi_sense_reason != 0) {
target_complete_cmd(cmd, CHECK_CONDITION);
return 0;
} else if (!core_scsi3_ua_clear_for_request_sense(cmd, &ua_asc, &ua_ascq)) {
buf[0] = 0x70;
buf[SPC_SENSE_KEY_OFFSET] = UNIT_ATTENTION;
buf[SPC_ASC_KEY_OFFSET] = ua_asc;
buf[SPC_ASCQ_KEY_OFFSET] = ua_ascq;
buf[7] = 0x0A;
} else {
buf[0] = 0x70;
buf[SPC_SENSE_KEY_OFFSET] = NO_SENSE;
buf[SPC_ASC_KEY_OFFSET] = 0x00;
buf[7] = 0x0A;
}
if (rbuf) {
memcpy(rbuf, buf, min_t(u32, sizeof(buf), cmd->data_length));
transport_kunmap_data_sg(cmd);
}
target_complete_cmd(cmd, GOOD);
return 0;
}
static int spc_emulate_testunitready(struct se_cmd *cmd)
{
target_complete_cmd(cmd, GOOD);
return 0;
}
int spc_parse_cdb(struct se_cmd *cmd, unsigned int *size)
{
struct se_device *dev = cmd->se_dev;
struct se_subsystem_dev *su_dev = dev->se_sub_dev;
unsigned char *cdb = cmd->t_task_cdb;
switch (cdb[0]) {
case MODE_SELECT:
*size = cdb[4];
break;
case MODE_SELECT_10:
*size = (cdb[7] << 8) + cdb[8];
break;
case MODE_SENSE:
*size = cdb[4];
cmd->execute_cmd = spc_emulate_modesense;
break;
case MODE_SENSE_10:
*size = (cdb[7] << 8) + cdb[8];
cmd->execute_cmd = spc_emulate_modesense;
break;
case LOG_SELECT:
case LOG_SENSE:
*size = (cdb[7] << 8) + cdb[8];
break;
case PERSISTENT_RESERVE_IN:
if (su_dev->t10_pr.res_type == SPC3_PERSISTENT_RESERVATIONS)
cmd->execute_cmd = target_scsi3_emulate_pr_in;
*size = (cdb[7] << 8) + cdb[8];
break;
case PERSISTENT_RESERVE_OUT:
if (su_dev->t10_pr.res_type == SPC3_PERSISTENT_RESERVATIONS)
cmd->execute_cmd = target_scsi3_emulate_pr_out;
*size = (cdb[7] << 8) + cdb[8];
break;
case RELEASE:
case RELEASE_10:
if (cdb[0] == RELEASE_10)
*size = (cdb[7] << 8) | cdb[8];
else
*size = cmd->data_length;
if (su_dev->t10_pr.res_type != SPC_PASSTHROUGH)
cmd->execute_cmd = target_scsi2_reservation_release;
break;
case RESERVE:
case RESERVE_10:
if (cdb[0] == RESERVE_10)
*size = (cdb[7] << 8) | cdb[8];
else
*size = cmd->data_length;
if (su_dev->t10_pr.res_type != SPC_PASSTHROUGH)
cmd->execute_cmd = target_scsi2_reservation_reserve;
break;
case REQUEST_SENSE:
*size = cdb[4];
cmd->execute_cmd = spc_emulate_request_sense;
break;
case INQUIRY:
*size = (cdb[3] << 8) + cdb[4];
if (cmd->se_dev->dev_task_attr_type == SAM_TASK_ATTR_EMULATED)
cmd->sam_task_attr = MSG_HEAD_TAG;
cmd->execute_cmd = spc_emulate_inquiry;
break;
case SECURITY_PROTOCOL_IN:
case SECURITY_PROTOCOL_OUT:
*size = (cdb[6] << 24) | (cdb[7] << 16) | (cdb[8] << 8) | cdb[9];
break;
case EXTENDED_COPY:
case READ_ATTRIBUTE:
case RECEIVE_COPY_RESULTS:
case WRITE_ATTRIBUTE:
*size = (cdb[10] << 24) | (cdb[11] << 16) |
(cdb[12] << 8) | cdb[13];
break;
case RECEIVE_DIAGNOSTIC:
case SEND_DIAGNOSTIC:
*size = (cdb[3] << 8) | cdb[4];
break;
case WRITE_BUFFER:
*size = (cdb[6] << 16) + (cdb[7] << 8) + cdb[8];
break;
case REPORT_LUNS:
cmd->execute_cmd = target_report_luns;
*size = (cdb[6] << 24) | (cdb[7] << 16) | (cdb[8] << 8) | cdb[9];
if (cmd->se_dev->dev_task_attr_type == SAM_TASK_ATTR_EMULATED)
cmd->sam_task_attr = MSG_HEAD_TAG;
break;
case TEST_UNIT_READY:
cmd->execute_cmd = spc_emulate_testunitready;
*size = 0;
break;
case MAINTENANCE_IN:
if (dev->transport->get_device_type(dev) != TYPE_ROM) {
if ((cdb[1] & 0x1f) == MI_REPORT_TARGET_PGS &&
su_dev->t10_alua.alua_type == SPC3_ALUA_EMULATED) {
cmd->execute_cmd =
target_emulate_report_target_port_groups;
}
*size = get_unaligned_be32(&cdb[6]);
} else {
*size = get_unaligned_be16(&cdb[8]);
}
break;
case MAINTENANCE_OUT:
if (dev->transport->get_device_type(dev) != TYPE_ROM) {
if (cdb[1] == MO_SET_TARGET_PGS &&
su_dev->t10_alua.alua_type == SPC3_ALUA_EMULATED) {
cmd->execute_cmd =
target_emulate_set_target_port_groups;
}
*size = get_unaligned_be32(&cdb[6]);
} else {
*size = get_unaligned_be16(&cdb[8]);
}
break;
default:
pr_warn("TARGET_CORE[%s]: Unsupported SCSI Opcode"
" 0x%02x, sending CHECK_CONDITION.\n",
cmd->se_tfo->get_fabric_name(), cdb[0]);
cmd->se_cmd_flags |= SCF_SCSI_CDB_EXCEPTION;
cmd->scsi_sense_reason = TCM_UNSUPPORTED_SCSI_OPCODE;
return -EINVAL;
}
return 0;
}
