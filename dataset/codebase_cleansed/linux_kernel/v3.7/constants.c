static const char * get_sa_name(const struct value_name_pair * arr,
int arr_sz, int service_action)
{
int k;
for (k = 0; k < arr_sz; ++k, ++arr) {
if (service_action == arr->value)
break;
}
return (k < arr_sz) ? arr->name : NULL;
}
static void print_opcode_name(unsigned char * cdbp, int cdb_len)
{
int sa, len, cdb0;
const char * name;
cdb0 = cdbp[0];
switch(cdb0) {
case VARIABLE_LENGTH_CMD:
len = scsi_varlen_cdb_length(cdbp);
if (len < 10) {
printk("short variable length command, "
"len=%d ext_len=%d", len, cdb_len);
break;
}
sa = (cdbp[8] << 8) + cdbp[9];
name = get_sa_name(variable_length_arr, VARIABLE_LENGTH_SZ, sa);
if (name)
printk("%s", name);
else
printk("cdb[0]=0x%x, sa=0x%x", cdb0, sa);
if ((cdb_len > 0) && (len != cdb_len))
printk(", in_cdb_len=%d, ext_len=%d", len, cdb_len);
break;
case MAINTENANCE_IN:
sa = cdbp[1] & 0x1f;
name = get_sa_name(maint_in_arr, MAINT_IN_SZ, sa);
if (name)
printk("%s", name);
else
printk("cdb[0]=0x%x, sa=0x%x", cdb0, sa);
break;
case MAINTENANCE_OUT:
sa = cdbp[1] & 0x1f;
name = get_sa_name(maint_out_arr, MAINT_OUT_SZ, sa);
if (name)
printk("%s", name);
else
printk("cdb[0]=0x%x, sa=0x%x", cdb0, sa);
break;
case SERVICE_ACTION_IN_12:
sa = cdbp[1] & 0x1f;
name = get_sa_name(serv_in12_arr, SERV_IN12_SZ, sa);
if (name)
printk("%s", name);
else
printk("cdb[0]=0x%x, sa=0x%x", cdb0, sa);
break;
case SERVICE_ACTION_OUT_12:
sa = cdbp[1] & 0x1f;
name = get_sa_name(serv_out12_arr, SERV_OUT12_SZ, sa);
if (name)
printk("%s", name);
else
printk("cdb[0]=0x%x, sa=0x%x", cdb0, sa);
break;
case SERVICE_ACTION_IN_16:
sa = cdbp[1] & 0x1f;
name = get_sa_name(serv_in16_arr, SERV_IN16_SZ, sa);
if (name)
printk("%s", name);
else
printk("cdb[0]=0x%x, sa=0x%x", cdb0, sa);
break;
case SERVICE_ACTION_OUT_16:
sa = cdbp[1] & 0x1f;
name = get_sa_name(serv_out16_arr, SERV_OUT16_SZ, sa);
if (name)
printk("%s", name);
else
printk("cdb[0]=0x%x, sa=0x%x", cdb0, sa);
break;
default:
if (cdb0 < 0xc0) {
name = cdb_byte0_names[cdb0];
if (name)
printk("%s", name);
else
printk("cdb[0]=0x%x (reserved)", cdb0);
} else
printk("cdb[0]=0x%x (vendor)", cdb0);
break;
}
}
static void print_opcode_name(unsigned char * cdbp, int cdb_len)
{
int sa, len, cdb0;
cdb0 = cdbp[0];
switch(cdb0) {
case VARIABLE_LENGTH_CMD:
len = scsi_varlen_cdb_length(cdbp);
if (len < 10) {
printk("short opcode=0x%x command, len=%d "
"ext_len=%d", cdb0, len, cdb_len);
break;
}
sa = (cdbp[8] << 8) + cdbp[9];
printk("cdb[0]=0x%x, sa=0x%x", cdb0, sa);
if (len != cdb_len)
printk(", in_cdb_len=%d, ext_len=%d", len, cdb_len);
break;
case MAINTENANCE_IN:
case MAINTENANCE_OUT:
case SERVICE_ACTION_IN_12:
case SERVICE_ACTION_OUT_12:
case SERVICE_ACTION_IN_16:
case SERVICE_ACTION_OUT_16:
sa = cdbp[1] & 0x1f;
printk("cdb[0]=0x%x, sa=0x%x", cdb0, sa);
break;
default:
if (cdb0 < 0xc0)
printk("cdb[0]=0x%x", cdb0);
else
printk("cdb[0]=0x%x (vendor)", cdb0);
break;
}
}
void __scsi_print_command(unsigned char *cdb)
{
int k, len;
print_opcode_name(cdb, 0);
len = scsi_command_size(cdb);
for (k = 0; k < len; ++k)
printk(" %02x", cdb[k]);
printk("\n");
}
void scsi_print_command(struct scsi_cmnd *cmd)
{
int k;
if (cmd->cmnd == NULL)
return;
scmd_printk(KERN_INFO, cmd, "CDB: ");
print_opcode_name(cmd->cmnd, cmd->cmd_len);
printk(":");
for (k = 0; k < cmd->cmd_len; ++k)
printk(" %02x", cmd->cmnd[k]);
printk("\n");
}
void
scsi_print_status(unsigned char scsi_status) {
#ifdef CONFIG_SCSI_CONSTANTS
const char * ccp;
switch (scsi_status) {
case 0: ccp = "Good"; break;
case 0x2: ccp = "Check Condition"; break;
case 0x4: ccp = "Condition Met"; break;
case 0x8: ccp = "Busy"; break;
case 0x10: ccp = "Intermediate"; break;
case 0x14: ccp = "Intermediate-Condition Met"; break;
case 0x18: ccp = "Reservation Conflict"; break;
case 0x22: ccp = "Command Terminated"; break;
case 0x28: ccp = "Task set Full"; break;
case 0x30: ccp = "ACA Active"; break;
case 0x40: ccp = "Task Aborted"; break;
default: ccp = "Unknown status";
}
printk(KERN_INFO "%s", ccp);
#else
printk(KERN_INFO "0x%0x", scsi_status);
#endif
}
const char *
scsi_sense_key_string(unsigned char key) {
#ifdef CONFIG_SCSI_CONSTANTS
if (key <= 0xE)
return snstext[key];
#endif
return NULL;
}
const char *
scsi_extd_sense_format(unsigned char asc, unsigned char ascq) {
#ifdef CONFIG_SCSI_CONSTANTS
int i;
unsigned short code = ((asc << 8) | ascq);
for (i = 0; additional[i].text; i++)
if (additional[i].code12 == code)
return additional[i].text;
for (i = 0; additional2[i].fmt; i++) {
if (additional2[i].code1 == asc &&
ascq >= additional2[i].code2_min &&
ascq <= additional2[i].code2_max)
return additional2[i].fmt;
}
#endif
return NULL;
}
void
scsi_show_extd_sense(unsigned char asc, unsigned char ascq)
{
const char *extd_sense_fmt = scsi_extd_sense_format(asc, ascq);
if (extd_sense_fmt) {
if (strstr(extd_sense_fmt, "%x")) {
printk("Add. Sense: ");
printk(extd_sense_fmt, ascq);
} else
printk("Add. Sense: %s", extd_sense_fmt);
} else {
if (asc >= 0x80)
printk("<<vendor>> ASC=0x%x ASCQ=0x%x", asc,
ascq);
if (ascq >= 0x80)
printk("ASC=0x%x <<vendor>> ASCQ=0x%x", asc,
ascq);
else
printk("ASC=0x%x ASCQ=0x%x", asc, ascq);
}
printk("\n");
}
void
scsi_show_sense_hdr(struct scsi_sense_hdr *sshdr)
{
const char *sense_txt;
sense_txt = scsi_sense_key_string(sshdr->sense_key);
if (sense_txt)
printk("Sense Key : %s ", sense_txt);
else
printk("Sense Key : 0x%x ", sshdr->sense_key);
printk("%s", scsi_sense_is_deferred(sshdr) ? "[deferred] " :
"[current] ");
if (sshdr->response_code >= 0x72)
printk("[descriptor]");
printk("\n");
}
void
scsi_print_sense_hdr(const char *name, struct scsi_sense_hdr *sshdr)
{
printk(KERN_INFO "%s: ", name);
scsi_show_sense_hdr(sshdr);
printk(KERN_INFO "%s: ", name);
scsi_show_extd_sense(sshdr->asc, sshdr->ascq);
}
void
scsi_cmd_print_sense_hdr(struct scsi_cmnd *scmd, const char *desc,
struct scsi_sense_hdr *sshdr)
{
scmd_printk(KERN_INFO, scmd, "%s: ", desc);
scsi_show_sense_hdr(sshdr);
scmd_printk(KERN_INFO, scmd, "%s: ", desc);
scsi_show_extd_sense(sshdr->asc, sshdr->ascq);
}
static void
scsi_decode_sense_buffer(const unsigned char *sense_buffer, int sense_len,
struct scsi_sense_hdr *sshdr)
{
int k, num, res;
res = scsi_normalize_sense(sense_buffer, sense_len, sshdr);
if (0 == res) {
num = (sense_len < 32) ? sense_len : 32;
printk("Unrecognized sense data (in hex):");
for (k = 0; k < num; ++k) {
if (0 == (k % 16)) {
printk("\n");
printk(KERN_INFO " ");
}
printk("%02x ", sense_buffer[k]);
}
printk("\n");
return;
}
}
static void
scsi_decode_sense_extras(const unsigned char *sense_buffer, int sense_len,
struct scsi_sense_hdr *sshdr)
{
int k, num, res;
if (sshdr->response_code < 0x72)
{
char buff[80];
int blen, fixed_valid;
unsigned int info;
fixed_valid = sense_buffer[0] & 0x80;
info = ((sense_buffer[3] << 24) | (sense_buffer[4] << 16) |
(sense_buffer[5] << 8) | sense_buffer[6]);
res = 0;
memset(buff, 0, sizeof(buff));
blen = sizeof(buff) - 1;
if (fixed_valid)
res += snprintf(buff + res, blen - res,
"Info fld=0x%x", info);
if (sense_buffer[2] & 0x80) {
if (res > 0)
res += snprintf(buff + res, blen - res, ", ");
res += snprintf(buff + res, blen - res, "FMK");
}
if (sense_buffer[2] & 0x40) {
if (res > 0)
res += snprintf(buff + res, blen - res, ", ");
res += snprintf(buff + res, blen - res, "EOM");
}
if (sense_buffer[2] & 0x20) {
if (res > 0)
res += snprintf(buff + res, blen - res, ", ");
res += snprintf(buff + res, blen - res, "ILI");
}
if (res > 0)
printk("%s\n", buff);
} else if (sshdr->additional_length > 0) {
num = 8 + sshdr->additional_length;
num = (sense_len < num) ? sense_len : num;
printk("Descriptor sense data with sense descriptors "
"(in hex):");
for (k = 0; k < num; ++k) {
if (0 == (k % 16)) {
printk("\n");
printk(KERN_INFO " ");
}
printk("%02x ", sense_buffer[k]);
}
printk("\n");
}
}
void __scsi_print_sense(const char *name, const unsigned char *sense_buffer,
int sense_len)
{
struct scsi_sense_hdr sshdr;
printk(KERN_INFO "%s: ", name);
scsi_decode_sense_buffer(sense_buffer, sense_len, &sshdr);
scsi_show_sense_hdr(&sshdr);
scsi_decode_sense_extras(sense_buffer, sense_len, &sshdr);
printk(KERN_INFO "%s: ", name);
scsi_show_extd_sense(sshdr.asc, sshdr.ascq);
}
void scsi_print_sense(char *name, struct scsi_cmnd *cmd)
{
struct scsi_sense_hdr sshdr;
scmd_printk(KERN_INFO, cmd, " ");
scsi_decode_sense_buffer(cmd->sense_buffer, SCSI_SENSE_BUFFERSIZE,
&sshdr);
scsi_show_sense_hdr(&sshdr);
scsi_decode_sense_extras(cmd->sense_buffer, SCSI_SENSE_BUFFERSIZE,
&sshdr);
scmd_printk(KERN_INFO, cmd, " ");
scsi_show_extd_sense(sshdr.asc, sshdr.ascq);
}
void scsi_show_result(int result)
{
int hb = host_byte(result);
int db = driver_byte(result);
printk("Result: hostbyte=%s driverbyte=%s\n",
(hb < NUM_HOSTBYTE_STRS ? hostbyte_table[hb] : "invalid"),
(db < NUM_DRIVERBYTE_STRS ? driverbyte_table[db] : "invalid"));
}
void scsi_show_result(int result)
{
printk("Result: hostbyte=0x%02x driverbyte=0x%02x\n",
host_byte(result), driver_byte(result));
}
void scsi_print_result(struct scsi_cmnd *cmd)
{
scmd_printk(KERN_INFO, cmd, " ");
scsi_show_result(cmd->result);
}
