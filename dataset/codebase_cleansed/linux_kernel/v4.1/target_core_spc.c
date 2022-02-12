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
sense_reason_t
spc_emulate_inquiry_std(struct se_cmd *cmd, unsigned char *buf)
{
struct se_lun *lun = cmd->se_lun;
struct se_device *dev = cmd->se_dev;
struct se_session *sess = cmd->se_sess;
if (dev->transport->get_device_type(dev) == TYPE_TAPE)
buf[1] = 0x80;
buf[2] = 0x05;
buf[3] = 2;
spc_fill_alua_data(lun->lun_sep, buf);
if (dev->dev_attrib.emulate_3pc)
buf[5] |= 0x8;
if (sess->sup_prot_ops & (TARGET_PROT_DIN_PASS | TARGET_PROT_DOUT_PASS)) {
if (dev->dev_attrib.pi_prot_type || cmd->se_sess->sess_prot_type)
buf[5] |= 0x1;
}
buf[7] = 0x2;
memcpy(&buf[8], "LIO-ORG ", 8);
memset(&buf[16], 0x20, 16);
memcpy(&buf[16], dev->t10_wwn.model,
min_t(size_t, strlen(dev->t10_wwn.model), 16));
memcpy(&buf[32], dev->t10_wwn.revision,
min_t(size_t, strlen(dev->t10_wwn.revision), 4));
buf[4] = 31;
return 0;
}
static sense_reason_t
spc_emulate_evpd_80(struct se_cmd *cmd, unsigned char *buf)
{
struct se_device *dev = cmd->se_dev;
u16 len;
if (dev->dev_flags & DF_EMULATED_VPD_UNIT_SERIAL) {
len = sprintf(&buf[4], "%s", dev->t10_wwn.unit_serial);
len++;
buf[3] = len;
}
return 0;
}
void spc_parse_naa_6h_vendor_specific(struct se_device *dev,
unsigned char *buf)
{
unsigned char *p = &dev->t10_wwn.unit_serial[0];
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
sense_reason_t
spc_emulate_evpd_83(struct se_cmd *cmd, unsigned char *buf)
{
struct se_device *dev = cmd->se_dev;
struct se_lun *lun = cmd->se_lun;
struct se_port *port = NULL;
struct se_portal_group *tpg = NULL;
struct t10_alua_lu_gp_member *lu_gp_mem;
struct t10_alua_tg_pt_gp *tg_pt_gp;
struct t10_alua_tg_pt_gp_member *tg_pt_gp_mem;
unsigned char *prod = &dev->t10_wwn.model[0];
u32 prod_len;
u32 unit_serial_len, off = 0;
u16 len = 0, id_len;
off = 4;
if (!(dev->dev_flags & DF_EMULATED_VPD_UNIT_SERIAL))
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
if (dev->dev_flags & DF_EMULATED_VPD_UNIT_SERIAL) {
unit_serial_len = strlen(&dev->t10_wwn.unit_serial[0]);
unit_serial_len++;
id_len += sprintf(&buf[off+12], "%s:%s", prod,
&dev->t10_wwn.unit_serial[0]);
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
u32 padding, scsi_name_len, scsi_target_len;
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
padding = ((-scsi_name_len) & 3);
if (padding)
scsi_name_len += padding;
if (scsi_name_len > 256)
scsi_name_len = 256;
buf[off-1] = scsi_name_len;
off += scsi_name_len;
len += (scsi_name_len + 4);
buf[off] =
(tpg->se_tpg_tfo->get_fabric_proto_ident(tpg) << 4);
buf[off++] |= 0x3;
buf[off] = 0x80;
buf[off] |= 0x20;
buf[off++] |= 0x8;
off += 2;
scsi_target_len = sprintf(&buf[off], "%s",
tpg->se_tpg_tfo->tpg_get_wwn(tpg));
scsi_target_len += 1 ;
padding = ((-scsi_target_len) & 3);
if (padding)
scsi_target_len += padding;
if (scsi_target_len > 256)
scsi_target_len = 256;
buf[off-1] = scsi_target_len;
off += scsi_target_len;
len += (scsi_target_len + 4);
}
buf[2] = ((len >> 8) & 0xff);
buf[3] = (len & 0xff);
return 0;
}
static sense_reason_t
spc_emulate_evpd_86(struct se_cmd *cmd, unsigned char *buf)
{
struct se_device *dev = cmd->se_dev;
struct se_session *sess = cmd->se_sess;
buf[3] = 0x3c;
if (sess->sup_prot_ops & (TARGET_PROT_DIN_PASS | TARGET_PROT_DOUT_PASS)) {
if (dev->dev_attrib.pi_prot_type == TARGET_DIF_TYPE1_PROT ||
cmd->se_sess->sess_prot_type == TARGET_DIF_TYPE1_PROT)
buf[4] = 0x5;
else if (dev->dev_attrib.pi_prot_type == TARGET_DIF_TYPE3_PROT ||
cmd->se_sess->sess_prot_type == TARGET_DIF_TYPE3_PROT)
buf[4] = 0x4;
}
buf[5] = 0x07;
if (se_dev_check_wce(dev))
buf[6] = 0x01;
spin_lock(&cmd->se_dev->t10_alua.lba_map_lock);
if (!list_empty(&dev->t10_alua.lba_map_list))
buf[8] = 0x10;
spin_unlock(&cmd->se_dev->t10_alua.lba_map_lock);
return 0;
}
static sense_reason_t
spc_emulate_evpd_b0(struct se_cmd *cmd, unsigned char *buf)
{
struct se_device *dev = cmd->se_dev;
int have_tp = 0;
int opt, min;
if (dev->dev_attrib.emulate_tpu || dev->dev_attrib.emulate_tpws)
have_tp = 1;
buf[0] = dev->transport->get_device_type(dev);
buf[3] = have_tp ? 0x3c : 0x10;
buf[4] = 0x01;
if (dev->dev_attrib.emulate_caw)
buf[5] = 0x01;
if (dev->transport->get_io_min && (min = dev->transport->get_io_min(dev)))
put_unaligned_be16(min / dev->dev_attrib.block_size, &buf[6]);
else
put_unaligned_be16(1, &buf[6]);
put_unaligned_be32(dev->dev_attrib.hw_max_sectors, &buf[8]);
if (dev->transport->get_io_opt && (opt = dev->transport->get_io_opt(dev)))
put_unaligned_be32(opt / dev->dev_attrib.block_size, &buf[12]);
else
put_unaligned_be32(dev->dev_attrib.optimal_sectors, &buf[12]);
if (!have_tp)
goto max_write_same;
put_unaligned_be32(dev->dev_attrib.max_unmap_lba_count, &buf[20]);
put_unaligned_be32(dev->dev_attrib.max_unmap_block_desc_count,
&buf[24]);
put_unaligned_be32(dev->dev_attrib.unmap_granularity, &buf[28]);
put_unaligned_be32(dev->dev_attrib.unmap_granularity_alignment,
&buf[32]);
if (dev->dev_attrib.unmap_granularity_alignment != 0)
buf[32] |= 0x80;
max_write_same:
put_unaligned_be64(dev->dev_attrib.max_write_same_len, &buf[36]);
return 0;
}
static sense_reason_t
spc_emulate_evpd_b1(struct se_cmd *cmd, unsigned char *buf)
{
struct se_device *dev = cmd->se_dev;
buf[0] = dev->transport->get_device_type(dev);
buf[3] = 0x3c;
buf[5] = dev->dev_attrib.is_nonrot ? 1 : 0;
return 0;
}
static sense_reason_t
spc_emulate_evpd_b2(struct se_cmd *cmd, unsigned char *buf)
{
struct se_device *dev = cmd->se_dev;
buf[0] = dev->transport->get_device_type(dev);
put_unaligned_be16(0x0004, &buf[2]);
buf[4] = 0x00;
if (dev->dev_attrib.emulate_tpu != 0)
buf[5] = 0x80;
if (dev->dev_attrib.emulate_tpws != 0)
buf[5] |= 0x40 | 0x20;
return 0;
}
static sense_reason_t
spc_emulate_evpd_b3(struct se_cmd *cmd, unsigned char *buf)
{
struct se_device *dev = cmd->se_dev;
buf[0] = dev->transport->get_device_type(dev);
buf[3] = 0x0c;
put_unaligned_be32(dev->t10_alua.lba_map_segment_size, &buf[8]);
put_unaligned_be32(dev->t10_alua.lba_map_segment_multiplier, &buf[12]);
return 0;
}
static sense_reason_t
spc_emulate_evpd_00(struct se_cmd *cmd, unsigned char *buf)
{
int p;
if (cmd->se_dev->dev_flags & DF_EMULATED_VPD_UNIT_SERIAL) {
buf[3] = ARRAY_SIZE(evpd_handlers);
for (p = 0; p < ARRAY_SIZE(evpd_handlers); ++p)
buf[p + 4] = evpd_handlers[p].page;
}
return 0;
}
static sense_reason_t
spc_emulate_inquiry(struct se_cmd *cmd)
{
struct se_device *dev = cmd->se_dev;
struct se_portal_group *tpg = cmd->se_lun->lun_sep->sep_tpg;
unsigned char *rbuf;
unsigned char *cdb = cmd->t_task_cdb;
unsigned char *buf;
sense_reason_t ret;
int p;
int len = 0;
buf = kzalloc(SE_INQUIRY_BUF, GFP_KERNEL);
if (!buf) {
pr_err("Unable to allocate response buffer for INQUIRY\n");
return TCM_LOGICAL_UNIT_COMMUNICATION_FAILURE;
}
if (dev == tpg->tpg_virt_lun0.lun_se_dev)
buf[0] = 0x3f;
else
buf[0] = dev->transport->get_device_type(dev);
if (!(cdb[1] & 0x1)) {
if (cdb[2]) {
pr_err("INQUIRY with EVPD==0 but PAGE CODE=%02x\n",
cdb[2]);
ret = TCM_INVALID_CDB_FIELD;
goto out;
}
ret = spc_emulate_inquiry_std(cmd, buf);
len = buf[4] + 5;
goto out;
}
for (p = 0; p < ARRAY_SIZE(evpd_handlers); ++p) {
if (cdb[2] == evpd_handlers[p].page) {
buf[1] = cdb[2];
ret = evpd_handlers[p].emulate(cmd, buf);
len = get_unaligned_be16(&buf[2]) + 4;
goto out;
}
}
pr_err("Unknown VPD Code: 0x%02x\n", cdb[2]);
ret = TCM_INVALID_CDB_FIELD;
out:
rbuf = transport_kmap_data_sg(cmd);
if (rbuf) {
memcpy(rbuf, buf, min_t(u32, SE_INQUIRY_BUF, cmd->data_length));
transport_kunmap_data_sg(cmd);
}
kfree(buf);
if (!ret)
target_complete_cmd_with_length(cmd, GOOD, len);
return ret;
}
static int spc_modesense_rwrecovery(struct se_cmd *cmd, u8 pc, u8 *p)
{
p[0] = 0x01;
p[1] = 0x0a;
if (pc == 1)
goto out;
out:
return 12;
}
static int spc_modesense_control(struct se_cmd *cmd, u8 pc, u8 *p)
{
struct se_device *dev = cmd->se_dev;
struct se_session *sess = cmd->se_sess;
p[0] = 0x0a;
p[1] = 0x0a;
if (pc == 1)
goto out;
p[2] = 2;
p[3] = (dev->dev_attrib.emulate_rest_reord == 1) ? 0x00 : 0x10;
p[4] = (dev->dev_attrib.emulate_ua_intlck_ctrl == 2) ? 0x30 :
(dev->dev_attrib.emulate_ua_intlck_ctrl == 1) ? 0x20 : 0x00;
p[5] = (dev->dev_attrib.emulate_tas) ? 0x40 : 0x00;
if (sess->sup_prot_ops & (TARGET_PROT_DIN_PASS | TARGET_PROT_DOUT_PASS)) {
if (dev->dev_attrib.pi_prot_type || sess->sess_prot_type)
p[5] |= 0x80;
}
p[8] = 0xff;
p[9] = 0xff;
p[11] = 30;
out:
return 12;
}
static int spc_modesense_caching(struct se_cmd *cmd, u8 pc, u8 *p)
{
struct se_device *dev = cmd->se_dev;
p[0] = 0x08;
p[1] = 0x12;
if (pc == 1)
goto out;
if (se_dev_check_wce(dev))
p[2] = 0x04;
p[12] = 0x20;
out:
return 20;
}
static int spc_modesense_informational_exceptions(struct se_cmd *cmd, u8 pc, unsigned char *p)
{
p[0] = 0x1c;
p[1] = 0x0a;
if (pc == 1)
goto out;
out:
return 12;
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
static int spc_modesense_blockdesc(unsigned char *buf, u64 blocks, u32 block_size)
{
*buf++ = 8;
put_unaligned_be32(min(blocks, 0xffffffffull), buf);
buf += 4;
put_unaligned_be32(block_size, buf);
return 9;
}
static int spc_modesense_long_blockdesc(unsigned char *buf, u64 blocks, u32 block_size)
{
if (blocks <= 0xffffffff)
return spc_modesense_blockdesc(buf + 3, blocks, block_size) + 3;
*buf++ = 1;
buf += 2;
*buf++ = 16;
put_unaligned_be64(blocks, buf);
buf += 12;
put_unaligned_be32(block_size, buf);
return 17;
}
static sense_reason_t spc_emulate_modesense(struct se_cmd *cmd)
{
struct se_device *dev = cmd->se_dev;
char *cdb = cmd->t_task_cdb;
unsigned char buf[SE_MODE_PAGE_BUF], *rbuf;
int type = dev->transport->get_device_type(dev);
int ten = (cmd->t_task_cdb[0] == MODE_SENSE_10);
bool dbd = !!(cdb[1] & 0x08);
bool llba = ten ? !!(cdb[1] & 0x10) : false;
u8 pc = cdb[2] >> 6;
u8 page = cdb[2] & 0x3f;
u8 subpage = cdb[3];
int length = 0;
int ret;
int i;
memset(buf, 0, SE_MODE_PAGE_BUF);
length = ten ? 3 : 2;
if ((cmd->se_lun->lun_access & TRANSPORT_LUNFLAGS_READ_ONLY) ||
(cmd->se_deve &&
(cmd->se_deve->lun_flags & TRANSPORT_LUNFLAGS_READ_ONLY)))
spc_modesense_write_protect(&buf[length], type);
if ((se_dev_check_wce(dev)) &&
(dev->dev_attrib.emulate_fua_write > 0))
spc_modesense_dpofua(&buf[length], type);
++length;
if (!dbd && type == TYPE_DISK) {
u64 blocks = dev->transport->get_blocks(dev);
u32 block_size = dev->dev_attrib.block_size;
if (ten) {
if (llba) {
length += spc_modesense_long_blockdesc(&buf[length],
blocks, block_size);
} else {
length += 3;
length += spc_modesense_blockdesc(&buf[length],
blocks, block_size);
}
} else {
length += spc_modesense_blockdesc(&buf[length], blocks,
block_size);
}
} else {
if (ten)
length += 4;
else
length += 1;
}
if (page == 0x3f) {
if (subpage != 0x00 && subpage != 0xff) {
pr_warn("MODE_SENSE: Invalid subpage code: 0x%02x\n", subpage);
return TCM_INVALID_CDB_FIELD;
}
for (i = 0; i < ARRAY_SIZE(modesense_handlers); ++i) {
if ((modesense_handlers[i].subpage & ~subpage) == 0) {
ret = modesense_handlers[i].emulate(cmd, pc, &buf[length]);
if (!ten && length + ret >= 255)
break;
length += ret;
}
}
goto set_length;
}
for (i = 0; i < ARRAY_SIZE(modesense_handlers); ++i)
if (modesense_handlers[i].page == page &&
modesense_handlers[i].subpage == subpage) {
length += modesense_handlers[i].emulate(cmd, pc, &buf[length]);
goto set_length;
}
if (page != 0x03)
pr_err("MODE SENSE: unimplemented page/subpage: 0x%02x/0x%02x\n",
page, subpage);
return TCM_UNKNOWN_MODE_PAGE;
set_length:
if (ten)
put_unaligned_be16(length - 2, buf);
else
buf[0] = length - 1;
rbuf = transport_kmap_data_sg(cmd);
if (rbuf) {
memcpy(rbuf, buf, min_t(u32, SE_MODE_PAGE_BUF, cmd->data_length));
transport_kunmap_data_sg(cmd);
}
target_complete_cmd_with_length(cmd, GOOD, length);
return 0;
}
static sense_reason_t spc_emulate_modeselect(struct se_cmd *cmd)
{
char *cdb = cmd->t_task_cdb;
bool ten = cdb[0] == MODE_SELECT_10;
int off = ten ? 8 : 4;
bool pf = !!(cdb[1] & 0x10);
u8 page, subpage;
unsigned char *buf;
unsigned char tbuf[SE_MODE_PAGE_BUF];
int length;
sense_reason_t ret = 0;
int i;
if (!cmd->data_length) {
target_complete_cmd(cmd, GOOD);
return 0;
}
if (cmd->data_length < off + 2)
return TCM_PARAMETER_LIST_LENGTH_ERROR;
buf = transport_kmap_data_sg(cmd);
if (!buf)
return TCM_LOGICAL_UNIT_COMMUNICATION_FAILURE;
if (!pf) {
ret = TCM_INVALID_CDB_FIELD;
goto out;
}
page = buf[off] & 0x3f;
subpage = buf[off] & 0x40 ? buf[off + 1] : 0;
for (i = 0; i < ARRAY_SIZE(modesense_handlers); ++i)
if (modesense_handlers[i].page == page &&
modesense_handlers[i].subpage == subpage) {
memset(tbuf, 0, SE_MODE_PAGE_BUF);
length = modesense_handlers[i].emulate(cmd, 0, tbuf);
goto check_contents;
}
ret = TCM_UNKNOWN_MODE_PAGE;
goto out;
check_contents:
if (cmd->data_length < off + length) {
ret = TCM_PARAMETER_LIST_LENGTH_ERROR;
goto out;
}
if (memcmp(buf + off, tbuf, length))
ret = TCM_INVALID_PARAMETER_LIST;
out:
transport_kunmap_data_sg(cmd);
if (!ret)
target_complete_cmd(cmd, GOOD);
return ret;
}
static sense_reason_t spc_emulate_request_sense(struct se_cmd *cmd)
{
unsigned char *cdb = cmd->t_task_cdb;
unsigned char *rbuf;
u8 ua_asc = 0, ua_ascq = 0;
unsigned char buf[SE_SENSE_BUF];
memset(buf, 0, SE_SENSE_BUF);
if (cdb[1] & 0x01) {
pr_err("REQUEST_SENSE description emulation not"
" supported\n");
return TCM_INVALID_CDB_FIELD;
}
rbuf = transport_kmap_data_sg(cmd);
if (!rbuf)
return TCM_LOGICAL_UNIT_COMMUNICATION_FAILURE;
if (!core_scsi3_ua_clear_for_request_sense(cmd, &ua_asc, &ua_ascq)) {
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
memcpy(rbuf, buf, min_t(u32, sizeof(buf), cmd->data_length));
transport_kunmap_data_sg(cmd);
target_complete_cmd(cmd, GOOD);
return 0;
}
sense_reason_t spc_emulate_report_luns(struct se_cmd *cmd)
{
struct se_dev_entry *deve;
struct se_session *sess = cmd->se_sess;
unsigned char *buf;
u32 lun_count = 0, offset = 8, i;
if (cmd->data_length < 16) {
pr_warn("REPORT LUNS allocation length %u too small\n",
cmd->data_length);
return TCM_INVALID_CDB_FIELD;
}
buf = transport_kmap_data_sg(cmd);
if (!buf)
return TCM_LOGICAL_UNIT_COMMUNICATION_FAILURE;
if (!sess) {
int_to_scsilun(0, (struct scsi_lun *)&buf[offset]);
lun_count = 1;
goto done;
}
spin_lock_irq(&sess->se_node_acl->device_list_lock);
for (i = 0; i < TRANSPORT_MAX_LUNS_PER_TPG; i++) {
deve = sess->se_node_acl->device_list[i];
if (!(deve->lun_flags & TRANSPORT_LUNFLAGS_INITIATOR_ACCESS))
continue;
lun_count++;
if ((offset + 8) > cmd->data_length)
continue;
int_to_scsilun(deve->mapped_lun, (struct scsi_lun *)&buf[offset]);
offset += 8;
}
spin_unlock_irq(&sess->se_node_acl->device_list_lock);
done:
lun_count *= 8;
buf[0] = ((lun_count >> 24) & 0xff);
buf[1] = ((lun_count >> 16) & 0xff);
buf[2] = ((lun_count >> 8) & 0xff);
buf[3] = (lun_count & 0xff);
transport_kunmap_data_sg(cmd);
target_complete_cmd_with_length(cmd, GOOD, 8 + lun_count * 8);
return 0;
}
static sense_reason_t
spc_emulate_testunitready(struct se_cmd *cmd)
{
target_complete_cmd(cmd, GOOD);
return 0;
}
sense_reason_t
spc_parse_cdb(struct se_cmd *cmd, unsigned int *size)
{
struct se_device *dev = cmd->se_dev;
unsigned char *cdb = cmd->t_task_cdb;
switch (cdb[0]) {
case MODE_SELECT:
*size = cdb[4];
cmd->execute_cmd = spc_emulate_modeselect;
break;
case MODE_SELECT_10:
*size = (cdb[7] << 8) + cdb[8];
cmd->execute_cmd = spc_emulate_modeselect;
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
*size = (cdb[7] << 8) + cdb[8];
cmd->execute_cmd = target_scsi3_emulate_pr_in;
break;
case PERSISTENT_RESERVE_OUT:
*size = (cdb[7] << 8) + cdb[8];
cmd->execute_cmd = target_scsi3_emulate_pr_out;
break;
case RELEASE:
case RELEASE_10:
if (cdb[0] == RELEASE_10)
*size = (cdb[7] << 8) | cdb[8];
else
*size = cmd->data_length;
cmd->execute_cmd = target_scsi2_reservation_release;
break;
case RESERVE:
case RESERVE_10:
if (cdb[0] == RESERVE_10)
*size = (cdb[7] << 8) | cdb[8];
else
*size = cmd->data_length;
cmd->execute_cmd = target_scsi2_reservation_reserve;
break;
case REQUEST_SENSE:
*size = cdb[4];
cmd->execute_cmd = spc_emulate_request_sense;
break;
case INQUIRY:
*size = (cdb[3] << 8) + cdb[4];
cmd->sam_task_attr = TCM_HEAD_TAG;
cmd->execute_cmd = spc_emulate_inquiry;
break;
case SECURITY_PROTOCOL_IN:
case SECURITY_PROTOCOL_OUT:
*size = (cdb[6] << 24) | (cdb[7] << 16) | (cdb[8] << 8) | cdb[9];
break;
case EXTENDED_COPY:
*size = get_unaligned_be32(&cdb[10]);
cmd->execute_cmd = target_do_xcopy;
break;
case RECEIVE_COPY_RESULTS:
*size = get_unaligned_be32(&cdb[10]);
cmd->execute_cmd = target_do_receive_copy_results;
break;
case READ_ATTRIBUTE:
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
cmd->execute_cmd = spc_emulate_report_luns;
*size = (cdb[6] << 24) | (cdb[7] << 16) | (cdb[8] << 8) | cdb[9];
cmd->sam_task_attr = TCM_HEAD_TAG;
break;
case TEST_UNIT_READY:
cmd->execute_cmd = spc_emulate_testunitready;
*size = 0;
break;
case MAINTENANCE_IN:
if (dev->transport->get_device_type(dev) != TYPE_ROM) {
if ((cdb[1] & 0x1f) == MI_REPORT_TARGET_PGS) {
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
if (cdb[1] == MO_SET_TARGET_PGS) {
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
return TCM_UNSUPPORTED_SCSI_OPCODE;
}
return 0;
}
