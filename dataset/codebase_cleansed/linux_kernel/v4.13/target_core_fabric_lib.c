static int sas_get_pr_transport_id(
struct se_node_acl *nacl,
int *format_code,
unsigned char *buf)
{
int ret;
ret = hex2bin(&buf[4], &nacl->initiatorname[4], 8);
if (ret) {
pr_debug("%s: invalid hex string\n", __func__);
return ret;
}
return 24;
}
static int fc_get_pr_transport_id(
struct se_node_acl *se_nacl,
int *format_code,
unsigned char *buf)
{
unsigned char *ptr;
int i, ret;
u32 off = 8;
ptr = &se_nacl->initiatorname[0];
for (i = 0; i < 24; ) {
if (!strncmp(&ptr[i], ":", 1)) {
i++;
continue;
}
ret = hex2bin(&buf[off++], &ptr[i], 1);
if (ret < 0) {
pr_debug("%s: invalid hex string\n", __func__);
return ret;
}
i += 2;
}
return 24;
}
static int sbp_get_pr_transport_id(
struct se_node_acl *nacl,
int *format_code,
unsigned char *buf)
{
int ret;
ret = hex2bin(&buf[8], nacl->initiatorname, 8);
if (ret) {
pr_debug("%s: invalid hex string\n", __func__);
return ret;
}
return 24;
}
static int srp_get_pr_transport_id(
struct se_node_acl *nacl,
int *format_code,
unsigned char *buf)
{
const char *p;
unsigned len, count, leading_zero_bytes;
int rc;
p = nacl->initiatorname;
if (strncasecmp(p, "0x", 2) == 0)
p += 2;
len = strlen(p);
if (len % 2)
return -EINVAL;
count = min(len / 2, 16U);
leading_zero_bytes = 16 - count;
memset(buf + 8, 0, leading_zero_bytes);
rc = hex2bin(buf + 8 + leading_zero_bytes, p, count);
if (rc < 0) {
pr_debug("hex2bin failed for %s: %d\n", __func__, rc);
return rc;
}
return 24;
}
static int iscsi_get_pr_transport_id(
struct se_node_acl *se_nacl,
struct t10_pr_registration *pr_reg,
int *format_code,
unsigned char *buf)
{
u32 off = 4, padding = 0;
u16 len = 0;
spin_lock_irq(&se_nacl->nacl_sess_lock);
len = sprintf(&buf[off], "%s", se_nacl->initiatorname);
len++;
if ((*format_code == 1) && (pr_reg->isid_present_at_reg)) {
buf[0] |= 0x40;
buf[off+len] = 0x2c; off++;
buf[off+len] = 0x69; off++;
buf[off+len] = 0x2c; off++;
buf[off+len] = 0x30; off++;
buf[off+len] = 0x78; off++;
len += 5;
buf[off+len] = pr_reg->pr_reg_isid[0]; off++;
buf[off+len] = pr_reg->pr_reg_isid[1]; off++;
buf[off+len] = pr_reg->pr_reg_isid[2]; off++;
buf[off+len] = pr_reg->pr_reg_isid[3]; off++;
buf[off+len] = pr_reg->pr_reg_isid[4]; off++;
buf[off+len] = pr_reg->pr_reg_isid[5]; off++;
buf[off+len] = '\0'; off++;
len += 7;
}
spin_unlock_irq(&se_nacl->nacl_sess_lock);
padding = ((-len) & 3);
if (padding != 0)
len += padding;
put_unaligned_be16(len, &buf[2]);
len += 4;
return len;
}
static int iscsi_get_pr_transport_id_len(
struct se_node_acl *se_nacl,
struct t10_pr_registration *pr_reg,
int *format_code)
{
u32 len = 0, padding = 0;
spin_lock_irq(&se_nacl->nacl_sess_lock);
len = strlen(se_nacl->initiatorname);
len++;
if (pr_reg->isid_present_at_reg) {
len += 5;
len += 7;
*format_code = 1;
} else
*format_code = 0;
spin_unlock_irq(&se_nacl->nacl_sess_lock);
padding = ((-len) & 3);
if (padding != 0)
len += padding;
len += 4;
return len;
}
static char *iscsi_parse_pr_out_transport_id(
struct se_portal_group *se_tpg,
const char *buf,
u32 *out_tid_len,
char **port_nexus_ptr)
{
char *p;
u32 tid_len, padding;
int i;
u16 add_len;
u8 format_code = (buf[0] & 0xc0);
if ((format_code != 0x00) && (format_code != 0x40)) {
pr_err("Illegal format code: 0x%02x for iSCSI"
" Initiator Transport ID\n", format_code);
return NULL;
}
if (out_tid_len) {
add_len = get_unaligned_be16(&buf[2]);
tid_len = strlen(&buf[4]);
tid_len += 4;
tid_len += 1;
padding = ((-tid_len) & 3);
if (padding != 0)
tid_len += padding;
if ((add_len + 4) != tid_len) {
pr_debug("LIO-Target Extracted add_len: %hu "
"does not match calculated tid_len: %u,"
" using tid_len instead\n", add_len+4, tid_len);
*out_tid_len = tid_len;
} else
*out_tid_len = (add_len + 4);
}
if (format_code == 0x40) {
p = strstr(&buf[4], ",i,0x");
if (!p) {
pr_err("Unable to locate \",i,0x\" separator"
" for Initiator port identifier: %s\n",
&buf[4]);
return NULL;
}
*p = '\0';
p += 5;
*port_nexus_ptr = p;
for (i = 0; i < 12; i++) {
if (isdigit(*p)) {
p++;
continue;
}
*p = tolower(*p);
p++;
}
}
return (char *)&buf[4];
}
int target_get_pr_transport_id_len(struct se_node_acl *nacl,
struct t10_pr_registration *pr_reg, int *format_code)
{
switch (nacl->se_tpg->proto_id) {
case SCSI_PROTOCOL_FCP:
case SCSI_PROTOCOL_SBP:
case SCSI_PROTOCOL_SRP:
case SCSI_PROTOCOL_SAS:
break;
case SCSI_PROTOCOL_ISCSI:
return iscsi_get_pr_transport_id_len(nacl, pr_reg, format_code);
default:
pr_err("Unknown proto_id: 0x%02x\n", nacl->se_tpg->proto_id);
return -EINVAL;
}
*format_code = 0;
return 24;
}
int target_get_pr_transport_id(struct se_node_acl *nacl,
struct t10_pr_registration *pr_reg, int *format_code,
unsigned char *buf)
{
switch (nacl->se_tpg->proto_id) {
case SCSI_PROTOCOL_SAS:
return sas_get_pr_transport_id(nacl, format_code, buf);
case SCSI_PROTOCOL_SBP:
return sbp_get_pr_transport_id(nacl, format_code, buf);
case SCSI_PROTOCOL_SRP:
return srp_get_pr_transport_id(nacl, format_code, buf);
case SCSI_PROTOCOL_FCP:
return fc_get_pr_transport_id(nacl, format_code, buf);
case SCSI_PROTOCOL_ISCSI:
return iscsi_get_pr_transport_id(nacl, pr_reg, format_code,
buf);
default:
pr_err("Unknown proto_id: 0x%02x\n", nacl->se_tpg->proto_id);
return -EINVAL;
}
}
const char *target_parse_pr_out_transport_id(struct se_portal_group *tpg,
const char *buf, u32 *out_tid_len, char **port_nexus_ptr)
{
u32 offset;
switch (tpg->proto_id) {
case SCSI_PROTOCOL_SAS:
offset = 4;
break;
case SCSI_PROTOCOL_SBP:
case SCSI_PROTOCOL_SRP:
case SCSI_PROTOCOL_FCP:
offset = 8;
break;
case SCSI_PROTOCOL_ISCSI:
return iscsi_parse_pr_out_transport_id(tpg, buf, out_tid_len,
port_nexus_ptr);
default:
pr_err("Unknown proto_id: 0x%02x\n", tpg->proto_id);
return NULL;
}
*port_nexus_ptr = NULL;
*out_tid_len = 24;
return buf + offset;
}
