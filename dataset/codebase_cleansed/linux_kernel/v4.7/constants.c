bool scsi_opcode_sa_name(int opcode, int service_action,
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
const char *
scsi_sense_key_string(unsigned char key) {
if (key <= 0xE)
return snstext[key];
return NULL;
}
const char *
scsi_extd_sense_format(unsigned char asc, unsigned char ascq, const char **fmt)
{
int i;
unsigned short code = ((asc << 8) | ascq);
unsigned offset = 0;
*fmt = NULL;
for (i = 0; i < ARRAY_SIZE(additional); i++) {
if (additional[i].code12 == code)
return additional_text + offset;
offset += additional[i].size;
}
for (i = 0; additional2[i].fmt; i++) {
if (additional2[i].code1 == asc &&
ascq >= additional2[i].code2_min &&
ascq <= additional2[i].code2_max) {
*fmt = additional2[i].fmt;
return additional2[i].str;
}
}
return NULL;
}
const char *scsi_hostbyte_string(int result)
{
const char *hb_string = NULL;
int hb = host_byte(result);
if (hb < ARRAY_SIZE(hostbyte_table))
hb_string = hostbyte_table[hb];
return hb_string;
}
const char *scsi_driverbyte_string(int result)
{
const char *db_string = NULL;
int db = driver_byte(result);
if (db < ARRAY_SIZE(driverbyte_table))
db_string = driverbyte_table[db];
return db_string;
}
const char *scsi_mlreturn_string(int result)
{
const struct value_name_pair *arr = scsi_mlreturn_arr;
int k;
for (k = 0; k < ARRAY_SIZE(scsi_mlreturn_arr); ++k, ++arr) {
if (result == arr->value)
return arr->name;
}
return NULL;
}
