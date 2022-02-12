static void
target_fill_alua_data(struct se_port *port, unsigned char *buf)
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
static int
target_emulate_inquiry_std(struct se_cmd *cmd)
{
struct se_lun *lun = cmd->se_lun;
struct se_device *dev = cmd->se_dev;
struct se_portal_group *tpg = lun->lun_sep->sep_tpg;
unsigned char *buf;
if (cmd->data_length < 6) {
pr_err("SCSI Inquiry payload length: %u"
" too small for EVPD=0\n", cmd->data_length);
return -EINVAL;
}
buf = transport_kmap_first_data_page(cmd);
if (dev == tpg->tpg_virt_lun0.lun_se_dev) {
buf[0] = 0x3f;
} else {
buf[0] = dev->transport->get_device_type(dev);
if (buf[0] == TYPE_TAPE)
buf[1] = 0x80;
}
buf[2] = dev->transport->get_device_rev(dev);
if (dev->se_sub_dev->t10_alua.alua_type == SPC3_ALUA_EMULATED)
target_fill_alua_data(lun->lun_sep, buf);
if (cmd->data_length < 8) {
buf[4] = 1;
goto out;
}
buf[7] = 0x32;
if (cmd->data_length < 36) {
buf[4] = 3;
goto out;
}
snprintf((unsigned char *)&buf[8], 8, "LIO-ORG");
snprintf((unsigned char *)&buf[16], 16, "%s",
&dev->se_sub_dev->t10_wwn.model[0]);
snprintf((unsigned char *)&buf[32], 4, "%s",
&dev->se_sub_dev->t10_wwn.revision[0]);
buf[4] = 31;
out:
transport_kunmap_first_data_page(cmd);
return 0;
}
static int
target_emulate_evpd_80(struct se_cmd *cmd, unsigned char *buf)
{
struct se_device *dev = cmd->se_dev;
u16 len = 0;
if (dev->se_sub_dev->su_dev_flags &
SDF_EMULATED_VPD_UNIT_SERIAL) {
u32 unit_serial_len;
unit_serial_len =
strlen(&dev->se_sub_dev->t10_wwn.unit_serial[0]);
unit_serial_len++;
if (((len + 4) + unit_serial_len) > cmd->data_length) {
len += unit_serial_len;
buf[2] = ((len >> 8) & 0xff);
buf[3] = (len & 0xff);
return 0;
}
len += sprintf((unsigned char *)&buf[4], "%s",
&dev->se_sub_dev->t10_wwn.unit_serial[0]);
len++;
buf[3] = len;
}
return 0;
}
static void
target_parse_naa_6h_vendor_specific(struct se_device *dev, unsigned char *buf)
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
static int
target_emulate_evpd_83(struct se_cmd *cmd, unsigned char *buf)
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
if (off + 20 > cmd->data_length)
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
target_parse_naa_6h_vendor_specific(dev, &buf[off]);
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
if ((len + (id_len + 4) +
(prod_len + unit_serial_len)) >
cmd->data_length) {
len += (prod_len + unit_serial_len);
goto check_port;
}
id_len += sprintf((unsigned char *)&buf[off+12],
"%s:%s", prod,
&dev->se_sub_dev->t10_wwn.unit_serial[0]);
}
buf[off] = 0x2;
buf[off+1] = 0x1;
buf[off+2] = 0x0;
memcpy((unsigned char *)&buf[off+4], "LIO-ORG", 8);
id_len++;
buf[off+3] = id_len;
len += (id_len + 4);
off += (id_len + 4);
check_port:
port = lun->lun_sep;
if (port) {
struct t10_alua_lu_gp *lu_gp;
u32 padding, scsi_name_len;
u16 lu_gp_id = 0;
u16 tg_pt_gp_id = 0;
u16 tpgt;
tpg = port->sep_tpg;
if (((len + 4) + 8) > cmd->data_length) {
len += 8;
goto check_tpgi;
}
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
check_tpgi:
if (dev->se_sub_dev->t10_alua.alua_type !=
SPC3_ALUA_EMULATED)
goto check_scsi_name;
if (((len + 4) + 8) > cmd->data_length) {
len += 8;
goto check_lu_gp;
}
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
if (((len + 4) + 8) > cmd->data_length) {
len += 8;
goto check_scsi_name;
}
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
if (((len + 4) + scsi_name_len) > cmd->data_length) {
len += scsi_name_len;
goto set_len;
}
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
set_len:
buf[2] = ((len >> 8) & 0xff);
buf[3] = (len & 0xff);
return 0;
}
static int
target_emulate_evpd_86(struct se_cmd *cmd, unsigned char *buf)
{
if (cmd->data_length < 60)
return 0;
buf[3] = 0x3c;
buf[5] = 0x07;
if (cmd->se_dev->se_sub_dev->se_dev_attrib.emulate_write_cache > 0)
buf[6] = 0x01;
return 0;
}
static int
target_emulate_evpd_b0(struct se_cmd *cmd, unsigned char *buf)
{
struct se_device *dev = cmd->se_dev;
int have_tp = 0;
if (dev->se_sub_dev->se_dev_attrib.emulate_tpu || dev->se_sub_dev->se_dev_attrib.emulate_tpws)
have_tp = 1;
if (cmd->data_length < (0x10 + 4)) {
pr_debug("Received data_length: %u"
" too small for EVPD 0xb0\n",
cmd->data_length);
return -EINVAL;
}
if (have_tp && cmd->data_length < (0x3c + 4)) {
pr_debug("Received data_length: %u"
" too small for TPE=1 EVPD 0xb0\n",
cmd->data_length);
have_tp = 0;
}
buf[0] = dev->transport->get_device_type(dev);
buf[3] = have_tp ? 0x3c : 0x10;
buf[4] = 0x01;
put_unaligned_be16(1, &buf[6]);
put_unaligned_be32(dev->se_sub_dev->se_dev_attrib.max_sectors, &buf[8]);
put_unaligned_be32(dev->se_sub_dev->se_dev_attrib.optimal_sectors, &buf[12]);
if (!have_tp || cmd->data_length < (0x3c + 4))
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
static int
target_emulate_evpd_b1(struct se_cmd *cmd, unsigned char *buf)
{
struct se_device *dev = cmd->se_dev;
buf[0] = dev->transport->get_device_type(dev);
buf[3] = 0x3c;
if (cmd->data_length >= 5 &&
dev->se_sub_dev->se_dev_attrib.is_nonrot)
buf[5] = 1;
return 0;
}
static int
target_emulate_evpd_b2(struct se_cmd *cmd, unsigned char *buf)
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
static int
target_emulate_evpd_00(struct se_cmd *cmd, unsigned char *buf)
{
int p;
if (cmd->data_length < 8)
return 0;
if (cmd->se_dev->se_sub_dev->su_dev_flags &
SDF_EMULATED_VPD_UNIT_SERIAL) {
buf[3] = ARRAY_SIZE(evpd_handlers);
for (p = 0; p < min_t(int, ARRAY_SIZE(evpd_handlers),
cmd->data_length - 4); ++p)
buf[p + 4] = evpd_handlers[p].page;
}
return 0;
}
int target_emulate_inquiry(struct se_task *task)
{
struct se_cmd *cmd = task->task_se_cmd;
struct se_device *dev = cmd->se_dev;
unsigned char *buf;
unsigned char *cdb = cmd->t_task_cdb;
int p, ret;
if (!(cdb[1] & 0x1)) {
ret = target_emulate_inquiry_std(cmd);
goto out;
}
if (cmd->data_length < 4) {
pr_err("SCSI Inquiry payload length: %u"
" too small for EVPD=1\n", cmd->data_length);
cmd->scsi_sense_reason = TCM_INVALID_CDB_FIELD;
return -EINVAL;
}
buf = transport_kmap_first_data_page(cmd);
buf[0] = dev->transport->get_device_type(dev);
for (p = 0; p < ARRAY_SIZE(evpd_handlers); ++p) {
if (cdb[2] == evpd_handlers[p].page) {
buf[1] = cdb[2];
ret = evpd_handlers[p].emulate(cmd, buf);
goto out_unmap;
}
}
pr_err("Unknown VPD Code: 0x%02x\n", cdb[2]);
cmd->scsi_sense_reason = TCM_UNSUPPORTED_SCSI_OPCODE;
ret = -EINVAL;
out_unmap:
transport_kunmap_first_data_page(cmd);
out:
if (!ret) {
task->task_scsi_status = GOOD;
transport_complete_task(task, 1);
}
return ret;
}
int target_emulate_readcapacity(struct se_task *task)
{
struct se_cmd *cmd = task->task_se_cmd;
struct se_device *dev = cmd->se_dev;
unsigned char *buf;
unsigned long long blocks_long = dev->transport->get_blocks(dev);
u32 blocks;
if (blocks_long >= 0x00000000ffffffff)
blocks = 0xffffffff;
else
blocks = (u32)blocks_long;
buf = transport_kmap_first_data_page(cmd);
buf[0] = (blocks >> 24) & 0xff;
buf[1] = (blocks >> 16) & 0xff;
buf[2] = (blocks >> 8) & 0xff;
buf[3] = blocks & 0xff;
buf[4] = (dev->se_sub_dev->se_dev_attrib.block_size >> 24) & 0xff;
buf[5] = (dev->se_sub_dev->se_dev_attrib.block_size >> 16) & 0xff;
buf[6] = (dev->se_sub_dev->se_dev_attrib.block_size >> 8) & 0xff;
buf[7] = dev->se_sub_dev->se_dev_attrib.block_size & 0xff;
if (dev->se_sub_dev->se_dev_attrib.emulate_tpu || dev->se_sub_dev->se_dev_attrib.emulate_tpws)
put_unaligned_be32(0xFFFFFFFF, &buf[0]);
transport_kunmap_first_data_page(cmd);
task->task_scsi_status = GOOD;
transport_complete_task(task, 1);
return 0;
}
int target_emulate_readcapacity_16(struct se_task *task)
{
struct se_cmd *cmd = task->task_se_cmd;
struct se_device *dev = cmd->se_dev;
unsigned char *buf;
unsigned long long blocks = dev->transport->get_blocks(dev);
buf = transport_kmap_first_data_page(cmd);
buf[0] = (blocks >> 56) & 0xff;
buf[1] = (blocks >> 48) & 0xff;
buf[2] = (blocks >> 40) & 0xff;
buf[3] = (blocks >> 32) & 0xff;
buf[4] = (blocks >> 24) & 0xff;
buf[5] = (blocks >> 16) & 0xff;
buf[6] = (blocks >> 8) & 0xff;
buf[7] = blocks & 0xff;
buf[8] = (dev->se_sub_dev->se_dev_attrib.block_size >> 24) & 0xff;
buf[9] = (dev->se_sub_dev->se_dev_attrib.block_size >> 16) & 0xff;
buf[10] = (dev->se_sub_dev->se_dev_attrib.block_size >> 8) & 0xff;
buf[11] = dev->se_sub_dev->se_dev_attrib.block_size & 0xff;
if (dev->se_sub_dev->se_dev_attrib.emulate_tpu || dev->se_sub_dev->se_dev_attrib.emulate_tpws)
buf[14] = 0x80;
transport_kunmap_first_data_page(cmd);
task->task_scsi_status = GOOD;
transport_complete_task(task, 1);
return 0;
}
static int
target_modesense_rwrecovery(unsigned char *p)
{
p[0] = 0x01;
p[1] = 0x0a;
return 12;
}
static int
target_modesense_control(struct se_device *dev, unsigned char *p)
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
static int
target_modesense_caching(struct se_device *dev, unsigned char *p)
{
p[0] = 0x08;
p[1] = 0x12;
if (dev->se_sub_dev->se_dev_attrib.emulate_write_cache > 0)
p[2] = 0x04;
p[12] = 0x20;
return 20;
}
static void
target_modesense_write_protect(unsigned char *buf, int type)
{
switch (type) {
case TYPE_DISK:
case TYPE_TAPE:
default:
buf[0] |= 0x80;
break;
}
}
static void
target_modesense_dpofua(unsigned char *buf, int type)
{
switch (type) {
case TYPE_DISK:
buf[0] |= 0x10;
break;
default:
break;
}
}
int target_emulate_modesense(struct se_task *task)
{
struct se_cmd *cmd = task->task_se_cmd;
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
length = target_modesense_rwrecovery(&buf[offset]);
break;
case 0x08:
length = target_modesense_caching(dev, &buf[offset]);
break;
case 0x0a:
length = target_modesense_control(dev, &buf[offset]);
break;
case 0x3f:
length = target_modesense_rwrecovery(&buf[offset]);
length += target_modesense_caching(dev, &buf[offset+length]);
length += target_modesense_control(dev, &buf[offset+length]);
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
target_modesense_write_protect(&buf[3], type);
if ((dev->se_sub_dev->se_dev_attrib.emulate_write_cache > 0) &&
(dev->se_sub_dev->se_dev_attrib.emulate_fua_write > 0))
target_modesense_dpofua(&buf[3], type);
if ((offset + 2) > cmd->data_length)
offset = cmd->data_length;
} else {
offset -= 1;
buf[0] = offset & 0xff;
if ((cmd->se_lun->lun_access & TRANSPORT_LUNFLAGS_READ_ONLY) ||
(cmd->se_deve &&
(cmd->se_deve->lun_flags & TRANSPORT_LUNFLAGS_READ_ONLY)))
target_modesense_write_protect(&buf[2], type);
if ((dev->se_sub_dev->se_dev_attrib.emulate_write_cache > 0) &&
(dev->se_sub_dev->se_dev_attrib.emulate_fua_write > 0))
target_modesense_dpofua(&buf[2], type);
if ((offset + 1) > cmd->data_length)
offset = cmd->data_length;
}
rbuf = transport_kmap_first_data_page(cmd);
memcpy(rbuf, buf, offset);
transport_kunmap_first_data_page(cmd);
task->task_scsi_status = GOOD;
transport_complete_task(task, 1);
return 0;
}
int target_emulate_request_sense(struct se_task *task)
{
struct se_cmd *cmd = task->task_se_cmd;
unsigned char *cdb = cmd->t_task_cdb;
unsigned char *buf;
u8 ua_asc = 0, ua_ascq = 0;
int err = 0;
if (cdb[1] & 0x01) {
pr_err("REQUEST_SENSE description emulation not"
" supported\n");
cmd->scsi_sense_reason = TCM_INVALID_CDB_FIELD;
return -ENOSYS;
}
buf = transport_kmap_first_data_page(cmd);
if (!core_scsi3_ua_clear_for_request_sense(cmd, &ua_asc, &ua_ascq)) {
buf[0] = 0x70;
buf[SPC_SENSE_KEY_OFFSET] = UNIT_ATTENTION;
if (cmd->data_length <= 18) {
buf[7] = 0x00;
err = -EINVAL;
goto end;
}
buf[SPC_ASC_KEY_OFFSET] = ua_asc;
buf[SPC_ASCQ_KEY_OFFSET] = ua_ascq;
buf[7] = 0x0A;
} else {
buf[0] = 0x70;
buf[SPC_SENSE_KEY_OFFSET] = NO_SENSE;
if (cmd->data_length <= 18) {
buf[7] = 0x00;
err = -EINVAL;
goto end;
}
buf[SPC_ASC_KEY_OFFSET] = 0x00;
buf[7] = 0x0A;
}
end:
transport_kunmap_first_data_page(cmd);
task->task_scsi_status = GOOD;
transport_complete_task(task, 1);
return 0;
}
int target_emulate_unmap(struct se_task *task)
{
struct se_cmd *cmd = task->task_se_cmd;
struct se_device *dev = cmd->se_dev;
unsigned char *buf, *ptr = NULL;
unsigned char *cdb = &cmd->t_task_cdb[0];
sector_t lba;
unsigned int size = cmd->data_length, range;
int ret = 0, offset;
unsigned short dl, bd_dl;
if (!dev->transport->do_discard) {
pr_err("UNMAP emulation not supported for: %s\n",
dev->transport->name);
cmd->scsi_sense_reason = TCM_UNSUPPORTED_SCSI_OPCODE;
return -ENOSYS;
}
offset = 8;
size -= 8;
dl = get_unaligned_be16(&cdb[0]);
bd_dl = get_unaligned_be16(&cdb[2]);
buf = transport_kmap_first_data_page(cmd);
ptr = &buf[offset];
pr_debug("UNMAP: Sub: %s Using dl: %hu bd_dl: %hu size: %hu"
" ptr: %p\n", dev->transport->name, dl, bd_dl, size, ptr);
while (size) {
lba = get_unaligned_be64(&ptr[0]);
range = get_unaligned_be32(&ptr[8]);
pr_debug("UNMAP: Using lba: %llu and range: %u\n",
(unsigned long long)lba, range);
ret = dev->transport->do_discard(dev, lba, range);
if (ret < 0) {
pr_err("blkdev_issue_discard() failed: %d\n",
ret);
goto err;
}
ptr += 16;
size -= 16;
}
err:
transport_kunmap_first_data_page(cmd);
if (!ret) {
task->task_scsi_status = GOOD;
transport_complete_task(task, 1);
}
return ret;
}
int target_emulate_write_same(struct se_task *task)
{
struct se_cmd *cmd = task->task_se_cmd;
struct se_device *dev = cmd->se_dev;
sector_t range;
sector_t lba = cmd->t_task_lba;
u32 num_blocks;
int ret;
if (!dev->transport->do_discard) {
pr_err("WRITE_SAME emulation not supported"
" for: %s\n", dev->transport->name);
cmd->scsi_sense_reason = TCM_UNSUPPORTED_SCSI_OPCODE;
return -ENOSYS;
}
if (cmd->t_task_cdb[0] == WRITE_SAME)
num_blocks = get_unaligned_be16(&cmd->t_task_cdb[7]);
else if (cmd->t_task_cdb[0] == WRITE_SAME_16)
num_blocks = get_unaligned_be32(&cmd->t_task_cdb[10]);
else
num_blocks = get_unaligned_be32(&cmd->t_task_cdb[28]);
if (num_blocks != 0)
range = num_blocks;
else
range = (dev->transport->get_blocks(dev) - lba);
pr_debug("WRITE_SAME UNMAP: LBA: %llu Range: %llu\n",
(unsigned long long)lba, (unsigned long long)range);
ret = dev->transport->do_discard(dev, lba, range);
if (ret < 0) {
pr_debug("blkdev_issue_discard() failed for WRITE_SAME\n");
return ret;
}
task->task_scsi_status = GOOD;
transport_complete_task(task, 1);
return 0;
}
int target_emulate_synchronize_cache(struct se_task *task)
{
struct se_device *dev = task->task_se_cmd->se_dev;
struct se_cmd *cmd = task->task_se_cmd;
if (!dev->transport->do_sync_cache) {
pr_err("SYNCHRONIZE_CACHE emulation not supported"
" for: %s\n", dev->transport->name);
cmd->scsi_sense_reason = TCM_UNSUPPORTED_SCSI_OPCODE;
return -ENOSYS;
}
dev->transport->do_sync_cache(task);
return 0;
}
int target_emulate_noop(struct se_task *task)
{
task->task_scsi_status = GOOD;
transport_complete_task(task, 1);
return 0;
}
void target_get_task_cdb(struct se_task *task, unsigned char *cdb)
{
struct se_cmd *cmd = task->task_se_cmd;
unsigned int cdb_len = scsi_command_size(cmd->t_task_cdb);
memcpy(cdb, cmd->t_task_cdb, cdb_len);
if (cmd->se_cmd_flags & SCF_SCSI_DATA_SG_IO_CDB) {
unsigned long long lba = task->task_lba;
u32 sectors = task->task_sectors;
switch (cdb_len) {
case 6:
cdb[1] = (lba >> 16) & 0x1f;
cdb[2] = (lba >> 8) & 0xff;
cdb[3] = lba & 0xff;
cdb[4] = sectors & 0xff;
break;
case 10:
put_unaligned_be32(lba, &cdb[2]);
put_unaligned_be16(sectors, &cdb[7]);
break;
case 12:
put_unaligned_be32(lba, &cdb[2]);
put_unaligned_be32(sectors, &cdb[6]);
break;
case 16:
put_unaligned_be64(lba, &cdb[2]);
put_unaligned_be32(sectors, &cdb[10]);
break;
case 32:
put_unaligned_be64(lba, &cdb[12]);
put_unaligned_be32(sectors, &cdb[28]);
break;
default:
BUG();
}
}
}
