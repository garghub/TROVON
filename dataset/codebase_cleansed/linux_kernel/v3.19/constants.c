static bool scsi_opcode_sa_name(int opcode, int service_action,
const char **cdb_name, const char **sa_name)
{
struct sa_name_list *sa_name_ptr;
const struct value_name_pair *arr = NULL;
int arr_sz, k;
*cdb_name = NULL;
if (opcode >= VENDOR_SPECIFIC_CDB)
return false;
if (opcode < ARRAY_SIZE(cdb_byte0_names))
*cdb_name = cdb_byte0_names[opcode];
for (sa_name_ptr = sa_names_arr; sa_name_ptr->arr; ++sa_name_ptr) {
if (sa_name_ptr->opcode == opcode) {
arr = sa_name_ptr->arr;
arr_sz = sa_name_ptr->arr_sz;
break;
}
}
if (!arr)
return false;
for (k = 0; k < arr_sz; ++k, ++arr) {
if (service_action == arr->value)
break;
}
if (k < arr_sz)
*sa_name = arr->name;
return true;
}
static void print_opcode_name(const unsigned char *cdbp, size_t cdb_len)
{
int sa, cdb0;
const char *cdb_name = NULL, *sa_name = NULL;
cdb0 = cdbp[0];
if (cdb0 == VARIABLE_LENGTH_CMD) {
if (cdb_len < 10) {
printk("short variable length command, len=%zu",
cdb_len);
return;
}
sa = (cdbp[8] << 8) + cdbp[9];
} else
sa = cdbp[1] & 0x1f;
if (!scsi_opcode_sa_name(cdb0, sa, &cdb_name, &sa_name)) {
if (cdb_name)
printk("%s", cdb_name);
else if (cdb0 >= VENDOR_SPECIFIC_CDB)
printk("cdb[0]=0x%x (vendor)", cdb0);
else if (cdb0 >= 0x60 && cdb0 < 0x7e)
printk("cdb[0]=0x%x (reserved)", cdb0);
else
printk("cdb[0]=0x%x", cdb0);
} else {
if (sa_name)
printk("%s", sa_name);
else if (cdb_name)
printk("%s, sa=0x%x", cdb_name, sa);
else
printk("cdb[0]=0x%x, sa=0x%x", cdb0, sa);
}
}
void __scsi_print_command(const unsigned char *cdb, size_t cdb_len)
{
int k, len;
print_opcode_name(cdb, cdb_len);
len = scsi_command_size(cdb);
if (cdb_len < len)
len = cdb_len;
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
const char *
scsi_sense_key_string(unsigned char key) {
#ifdef CONFIG_SCSI_CONSTANTS
if (key <= 0xE)
return snstext[key];
#endif
return NULL;
}
const char *
scsi_extd_sense_format(unsigned char asc, unsigned char ascq, const char **fmt)
{
#ifdef CONFIG_SCSI_CONSTANTS
int i;
unsigned short code = ((asc << 8) | ascq);
*fmt = NULL;
for (i = 0; additional[i].text; i++)
if (additional[i].code12 == code)
return additional[i].text;
for (i = 0; additional2[i].fmt; i++) {
if (additional2[i].code1 == asc &&
ascq >= additional2[i].code2_min &&
ascq <= additional2[i].code2_max) {
*fmt = additional2[i].fmt;
return additional2[i].str;
}
}
#else
*fmt = NULL;
#endif
return NULL;
}
void
scsi_show_extd_sense(const struct scsi_device *sdev, const char *name,
unsigned char asc, unsigned char ascq)
{
const char *extd_sense_fmt = NULL;
const char *extd_sense_str = scsi_extd_sense_format(asc, ascq,
&extd_sense_fmt);
if (extd_sense_str) {
if (extd_sense_fmt)
sdev_prefix_printk(KERN_INFO, sdev, name,
"Add. Sense: %s (%s%x)",
extd_sense_str, extd_sense_fmt,
ascq);
else
sdev_prefix_printk(KERN_INFO, sdev, name,
"Add. Sense: %s", extd_sense_str);
} else {
sdev_prefix_printk(KERN_INFO, sdev, name,
"%sASC=0x%x %sASCQ=0x%x\n",
asc >= 0x80 ? "<<vendor>> " : "", asc,
ascq >= 0x80 ? "<<vendor>> " : "", ascq);
}
}
void
scsi_show_sense_hdr(const struct scsi_device *sdev, const char *name,
const struct scsi_sense_hdr *sshdr)
{
const char *sense_txt;
sense_txt = scsi_sense_key_string(sshdr->sense_key);
if (sense_txt)
sdev_prefix_printk(KERN_INFO, sdev, name,
"Sense Key : %s [%s]%s\n", sense_txt,
scsi_sense_is_deferred(sshdr) ?
"deferred" : "current",
sshdr->response_code >= 0x72 ?
" [descriptor]" : "");
else
sdev_prefix_printk(KERN_INFO, sdev, name,
"Sense Key : 0x%x [%s]%s", sshdr->sense_key,
scsi_sense_is_deferred(sshdr) ?
"deferred" : "current",
sshdr->response_code >= 0x72 ?
" [descriptor]" : "");
}
void
scsi_print_sense_hdr(const struct scsi_device *sdev, const char *name,
const struct scsi_sense_hdr *sshdr)
{
scsi_show_sense_hdr(sdev, name, sshdr);
scsi_show_extd_sense(sdev, name, sshdr->asc, sshdr->ascq);
}
static void
scsi_dump_sense_buffer(const unsigned char *sense_buffer, int sense_len)
{
int k, num;
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
void __scsi_print_sense(const struct scsi_device *sdev, const char *name,
const unsigned char *sense_buffer, int sense_len)
{
struct scsi_sense_hdr sshdr;
if (!scsi_normalize_sense(sense_buffer, sense_len, &sshdr)) {
scsi_dump_sense_buffer(sense_buffer, sense_len);
return;
}
scsi_show_sense_hdr(sdev, name, &sshdr);
scsi_show_extd_sense(sdev, name, sshdr.asc, sshdr.ascq);
}
void scsi_print_sense(const struct scsi_cmnd *cmd)
{
struct gendisk *disk = cmd->request->rq_disk;
const char *disk_name = disk ? disk->disk_name : NULL;
__scsi_print_sense(cmd->device, disk_name, cmd->sense_buffer,
SCSI_SENSE_BUFFERSIZE);
}
const char *scsi_hostbyte_string(int result)
{
const char *hb_string = NULL;
#ifdef CONFIG_SCSI_CONSTANTS
int hb = host_byte(result);
if (hb < ARRAY_SIZE(hostbyte_table))
hb_string = hostbyte_table[hb];
#endif
return hb_string;
}
const char *scsi_driverbyte_string(int result)
{
const char *db_string = NULL;
#ifdef CONFIG_SCSI_CONSTANTS
int db = driver_byte(result);
if (db < ARRAY_SIZE(driverbyte_table))
db_string = driverbyte_table[db];
#endif
return db_string;
}
const char *scsi_mlreturn_string(int result)
{
#ifdef CONFIG_SCSI_CONSTANTS
const struct value_name_pair *arr = scsi_mlreturn_arr;
int k;
for (k = 0; k < ARRAY_SIZE(scsi_mlreturn_arr); ++k, ++arr) {
if (result == arr->value)
return arr->name;
}
#endif
return NULL;
}
void scsi_print_result(struct scsi_cmnd *cmd, const char *msg, int disposition)
{
const char *mlret_string = scsi_mlreturn_string(disposition);
const char *hb_string = scsi_hostbyte_string(cmd->result);
const char *db_string = scsi_driverbyte_string(cmd->result);
if (hb_string || db_string)
scmd_printk(KERN_INFO, cmd,
"%s%s Result: hostbyte=%s driverbyte=%s",
msg ? msg : "",
mlret_string ? mlret_string : "UNKNOWN",
hb_string ? hb_string : "invalid",
db_string ? db_string : "invalid");
else
scmd_printk(KERN_INFO, cmd,
"%s%s Result: hostbyte=0x%02x driverbyte=0x%02x",
msg ? msg : "",
mlret_string ? mlret_string : "UNKNOWN",
host_byte(cmd->result), driver_byte(cmd->result));
}
