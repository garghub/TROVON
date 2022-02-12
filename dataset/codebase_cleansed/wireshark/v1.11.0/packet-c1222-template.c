static guint8
c1222_cksum(tvbuff_t *tvb, gint offset, int len)
{
guint8 sum;
for (sum = 0; len; offset++, len--)
sum += tvb_get_guint8(tvb, offset);
return ~sum + 1;
}
static void
parse_c1222_detailed(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int cmd, guint32 *length, int *offset)
{
guint16 user_id = 0;
guint8 *user_name = NULL;
guint8 *password = NULL;
guint8 auth_len = 0;
gchar *auth_req = NULL;
guint16 table = 0;
guint16 tblsize = 0;
guint8 chksum = 0;
guint16 calcsum = 0;
guint8 wait_seconds = 0;
int numrates = 0;
guint16 packet_size;
guint16 procedure_num = 0;
guint8 nbr_packet;
guint8 traffic;
guint8 inter_char;
guint8 resp_to;
guint8 nbr_retries;
proto_item *item = NULL;
if ((cmd & 0xF0) == C1222_CMD_NEGOTIATE) {
numrates = cmd & 0x0F;
cmd = C1222_CMD_NEGOTIATE;
}
proto_tree_add_uint(tree, cmd >= 0x20 ? hf_c1222_cmd : hf_c1222_err, tvb, *offset, 1, cmd);
(*offset)++;
(*length)--;
switch (cmd) {
case C1222_CMD_LOGON:
if (*length >= 12) {
user_id = tvb_get_ntohs(tvb, *offset);
proto_tree_add_uint(tree, hf_c1222_logon_id, tvb, *offset, 2, user_id);
*offset += 2;
user_name = tvb_get_string(wmem_packet_scope(),tvb, *offset, 10);
proto_tree_add_string(tree, hf_c1222_logon_user, tvb, *offset, 10, user_name);
*offset += 10;
*length -= 12;
proto_item_set_text(tree, "C12.22 EPSEM: %s (id %d, user \"%s\")",
val_to_str(cmd,commandnames,"Unknown (0x%02x)"), user_id, user_name);
} else {
expert_add_info_format(pinfo, tree, &ei_c1222_command_truncated, "C12.22 LOGON command truncated");
}
break;
case C1222_CMD_SECURITY:
if (*length >= 20) {
password = tvb_get_string(wmem_packet_scope(),tvb, *offset, 20);
proto_tree_add_string(tree, hf_c1222_security_password, tvb, *offset, 20, password);
*offset += 20;
*length -= 20;
if (*length >= 2) {
user_id = tvb_get_ntohs(tvb, *offset);
proto_tree_add_uint(tree, hf_c1222_logon_id, tvb, *offset, 2, user_id);
*offset += 2;
*length -= 2;
proto_item_set_text(tree, "C12.22 EPSEM: %s (password \"%s\", id %d)",
val_to_str(cmd,commandnames,"Unknown (0x%02x)"), password, user_id);
} else {
proto_item_set_text(tree, "C12.22 EPSEM: %s (password \"%s\")",
val_to_str(cmd,commandnames,"Unknown (0x%02x)"), password);
}
} else {
expert_add_info_format(pinfo, tree, &ei_c1222_command_truncated, "C12.22 SECURITY command truncated");
}
break;
case C1222_CMD_AUTHENTICATE:
if (*length >= 1) {
auth_len = tvb_get_guint8(tvb, *offset);
proto_tree_add_uint(tree, hf_c1222_auth_len, tvb, *offset, 1, auth_len);
*offset += 1;
if (*length >= auth_len) {
auth_req = tvb_bytes_to_str(tvb, *offset, auth_len);
proto_tree_add_item(tree, hf_c1222_auth_data, tvb, *offset, auth_len, ENC_NA);
*offset += auth_len;
*length -= auth_len + 1;
proto_item_set_text(tree, "C12.22 EPSEM: %s (%d bytes: %s)",
val_to_str(cmd,commandnames,"Unknown (0x%02x)"), auth_len, auth_req);
} else {
expert_add_info_format(pinfo, tree, &ei_c1222_command_truncated, "C12.22 AUTHENTICATE command truncated");
}
} else {
expert_add_info_format(pinfo, tree, &ei_c1222_command_truncated, "C12.22 AUTHENTICATE command truncated");
}
break;
case C1222_CMD_FULL_READ:
if (*length >= 2) {
table = tvb_get_ntohs(tvb, *offset);
proto_tree_add_uint(tree, hf_c1222_read_table, tvb, *offset, 2, table);
proto_item_set_text(tree, "C12.22 EPSEM: %s (%s-%d)",
val_to_str(cmd,commandnames,"Unknown (0x%02x)"),
val_to_str((table >> 8) & 0xF8, tableflags,"Unknown (0x%04x)"), table & 0x7FF);
*offset += 2;
*length -= 2;
} else {
expert_add_info_format(pinfo, tree, &ei_c1222_command_truncated, "C12.22 READ command truncated");
}
break;
case C1222_CMD_PARTIAL_READ_OFFSET:
if (*length >= 7) {
table = tvb_get_ntohs(tvb, *offset);
proto_tree_add_uint(tree, hf_c1222_read_table, tvb, *offset, 2, table);
*offset += 2;
*length -= 2;
proto_tree_add_item(tree, hf_c1222_read_offset, tvb, *offset, 3, ENC_BIG_ENDIAN);
*offset += 3;
*length -= 3;
proto_tree_add_item(tree, hf_c1222_read_count, tvb, *offset, 2, ENC_BIG_ENDIAN);
*offset += 2;
*length -= 2;
proto_item_set_text(tree, "C12.22 EPSEM: %s (%s-%d)",
val_to_str(cmd,commandnames,"Unknown (0x%02x)"),
val_to_str((table >> 8) & 0xF8, tableflags,"Unknown (0x%04x)"), table & 0x7FF);
} else {
expert_add_info_format(pinfo, tree, &ei_c1222_command_truncated, "C12.22 READ command truncated");
}
break;
case C1222_CMD_FULL_WRITE:
if (*length >= 5) {
table = tvb_get_ntohs(tvb, *offset);
proto_tree_add_uint(tree, hf_c1222_write_table, tvb, *offset, 2, table);
*offset += 2;
*length -= 2;
tblsize = tvb_get_ntohs(tvb, *offset);
proto_tree_add_uint(tree, hf_c1222_write_size, tvb, *offset, 2, tblsize);
*offset += 2;
*length -= 2;
if (*length >= tblsize+1U) {
if (table == 7) {
procedure_num = tvb_get_letohs(tvb, *offset);
proto_tree_add_uint(tree, hf_c1222_procedure_num, tvb, *offset, 2, procedure_num);
*offset += 2;
*length -= 2;
tblsize -= 2;
}
proto_tree_add_item(tree, hf_c1222_write_data, tvb, *offset, tblsize, ENC_NA);
*offset += tblsize;
*length -= tblsize;
chksum = tvb_get_guint8(tvb, *offset);
item = proto_tree_add_uint(tree, hf_c1222_write_chksum, tvb, *offset, 1, chksum);
if (table == 7) {
calcsum = c1222_cksum(tvb, (*offset)-tblsize-2, tblsize+2);
} else {
calcsum = c1222_cksum(tvb, (*offset)-tblsize, tblsize);
}
if (chksum != calcsum) {
expert_add_info_format(pinfo, item, &ei_c1222_bad_checksum, "Bad checksum [should be 0x%02x]", calcsum);
}
if (table == 7) {
proto_item_set_text(tree, "C12.22 EPSEM: %s (%s-%d, %s-%d)",
val_to_str(cmd,commandnames,"Unknown (0x%02x)"),
val_to_str((table >> 8) & 0xF8, tableflags,"Unknown (0x%04x)"), table & 0x7FF,
val_to_str((procedure_num >> 8) & 0xF8, procflags,"Unknown (0x%04x)"), procedure_num & 0x7FF);
} else {
proto_item_set_text(tree, "C12.22 EPSEM: %s (%s-%d)",
val_to_str(cmd,commandnames,"Unknown (0x%02x)"),
val_to_str((table >> 8) & 0xF8, tableflags,"Unknown (0x%04x)"), table & 0x7FF);
}
*offset += 1;
*length -= 1;
} else {
expert_add_info_format(pinfo, tree, &ei_c1222_command_truncated, "C12.22 WRITE command truncated");
}
} else {
expert_add_info_format(pinfo, tree, &ei_c1222_command_truncated, "C12.22 WRITE command truncated");
}
break;
case C1222_CMD_PARTIAL_WRITE_OFFSET:
if (*length >= 8) {
table = tvb_get_ntohs(tvb, *offset);
proto_tree_add_uint(tree, hf_c1222_write_table, tvb, *offset, 2, table);
*offset += 2;
*length -= 2;
proto_tree_add_item(tree, hf_c1222_write_offset, tvb, *offset, 3, ENC_BIG_ENDIAN);
*offset += 3;
*length -= 3;
tblsize = tvb_get_ntohs(tvb, *offset);
proto_tree_add_uint(tree, hf_c1222_write_size, tvb, *offset, 2, tblsize);
*offset += 2;
*length -= 2;
if (*length >= tblsize+1U) {
proto_tree_add_item(tree, hf_c1222_write_data, tvb, *offset, tblsize, ENC_NA);
*offset += tblsize;
*length -= tblsize;
chksum = tvb_get_guint8(tvb, *offset);
item = proto_tree_add_uint(tree, hf_c1222_write_chksum, tvb, *offset, 1, chksum);
calcsum = c1222_cksum(tvb, (*offset)-tblsize, tblsize);
if (chksum != calcsum) {
expert_add_info_format(pinfo, item, &ei_c1222_bad_checksum, "Bad checksum [should be 0x%02x]", calcsum);
}
proto_item_set_text(tree, "C12.22 EPSEM: %s (%s-%d)",
val_to_str(cmd,commandnames,"Unknown (0x%02x)"),
val_to_str((table >> 8) & 0xF8, tableflags,"Unknown (0x%04x)"), table & 0x7FF);
*offset += 1;
*length -= 1;
} else {
expert_add_info_format(pinfo, tree, &ei_c1222_command_truncated, "C12.22 WRITE command truncated");
}
} else {
expert_add_info_format(pinfo, tree, &ei_c1222_command_truncated, "C12.22 WRITE command truncated");
}
break;
case C1222_CMD_WAIT:
if (*length >= 1) {
wait_seconds = tvb_get_guint8(tvb, *offset);
proto_tree_add_uint(tree, hf_c1222_wait_secs, tvb, *offset, 1, wait_seconds);
*offset += 1;
*length -= 1;
proto_item_set_text(tree, "C12.22 EPSEM: %s (%d seconds)",
val_to_str(cmd,commandnames,"Unknown (0x%02x)"), wait_seconds);
} else {
expert_add_info_format(pinfo, tree, &ei_c1222_command_truncated, "C12.22 WAIT command truncated");
}
break;
case C1222_CMD_NEGOTIATE:
if (*length >= 3) {
packet_size = tvb_get_ntohs(tvb, *offset);
proto_tree_add_uint(tree, hf_c1222_neg_pkt_size, tvb, *offset, 2, packet_size);
*offset += 2;
*length -= 2;
nbr_packet = tvb_get_guint8(tvb, *offset);
proto_tree_add_uint(tree, hf_c1222_neg_nbr_pkts, tvb, *offset, 1, nbr_packet);
*offset += 1;
*length -= 1;
proto_item_set_text(tree, "C12.22 EPSEM: %s (pkt size %d, num pkts %d, with %d baud rates)",
val_to_str(cmd,commandnames,"Unknown (0x%02x)"), packet_size, nbr_packet, numrates);
} else {
expert_add_info_format(pinfo, tree, &ei_c1222_command_truncated, "C12.22 NEGOTIATE command truncated");
}
break;
case C1222_CMD_TIMING_SETUP:
if (*length >= 4) {
traffic = tvb_get_guint8(tvb, *offset);
proto_tree_add_uint(tree, hf_c1222_timing_setup_traffic, tvb, *offset, 1, traffic);
*offset += 1;
*length -= 1;
inter_char = tvb_get_guint8(tvb, *offset);
proto_tree_add_uint(tree, hf_c1222_timing_setup_inter_char, tvb, *offset, 1, inter_char);
*offset += 1;
*length -= 1;
resp_to = tvb_get_guint8(tvb, *offset);
proto_tree_add_uint(tree, hf_c1222_timing_setup_resp_to, tvb, *offset, 1, resp_to);
*offset += 1;
*length -= 1;
nbr_retries = tvb_get_guint8(tvb, *offset);
proto_tree_add_uint(tree, hf_c1222_timing_setup_nbr_retries, tvb, *offset, 1, nbr_retries);
*offset += 1;
*length -= 1;
proto_item_set_text(tree, "C12.22 EPSEM: %s (traffic to %d s, inter-char to %d s, response to %d s, %d retries)",
val_to_str(cmd,commandnames,"Unknown (0x%02x)"), traffic, inter_char, resp_to, nbr_retries);
} else {
expert_add_info_format(pinfo, tree, &ei_c1222_command_truncated, "C12.22 NEGOTIATE command truncated");
}
break;
default:
proto_item_set_text(tree, "C12.22 EPSEM: %s", val_to_str(cmd, commandnames, "Unknown (0x%02x)"));
if (*length) {
proto_tree_add_item(tree, hf_c1222_data, tvb, *offset, *length, ENC_NA);
}
break;
}
}
static void
clear_canon(void)
{
const TOP_ELEMENT_CONTROL *t = canonifyTable;
for (t = canonifyTable; t->element != NULL; t++) {
*(t->length) = 0;
*(t->element) = NULL;
}
}
static guint32
get_ber_len_size(guint32 n)
{
guint32 len = 1;
if (n > 0x7f) len++;
if (n > 0xff) len++;
if (n > 0xffff) len++;
if (n > 0xffffff) len++;
return len;
}
static int
encode_ber_len(guint8 *ptr, guint32 n, int maxsize)
{
int len = get_ber_len_size(n);
if (len > maxsize) return 0;
if (len == 1) {
*ptr = 0x7f & n;
} else {
*ptr = (len -1) | 0x80;
for (ptr += len-1; n; n >>= 8)
*ptr-- = n & 0xff;
}
return len;
}
static void
c1222_uat_data_update_cb(void* n, const char** err)
{
c1222_uat_data_t* new_rec = (c1222_uat_data_t *)n;
if (new_rec->keynum > 0xff) {
*err = "Invalid key number; must be less than 256";
}
if (new_rec->keylen != EAX_SIZEOF_KEY) {
*err = "Invalid key size; must be 16 bytes";
}
}
static gboolean
canonify_unencrypted_header(guchar *buff, guint32 *offset, guint32 buffsize)
{
const TOP_ELEMENT_CONTROL *t = canonifyTable;
guint32 len;
for (t = canonifyTable; t->element != NULL; t++)
{
len = *(t->length);
if (t->required && *(t->element) == NULL)
return FALSE;
if (*(t->element) != NULL) {
if (t->addtag) {
buff[(*offset)++] = t->tag;
(*offset) += encode_ber_len(&buff[*offset], len, 4);
}
if (t->truncate) {
len = 3+2*get_ber_len_size(len);
}
if (buffsize < *offset + len) {
return FALSE;
}
memcpy(&buff[*offset], *(t->element), len);
(*offset) += len;
if (t->addtag) {
*(t->element) = NULL;
}
}
}
return TRUE;
}
static gboolean
keylookup(guint8 *keybuff, guint8 keyid)
{
guint i;
if (c1222_uat_data == NULL)
return FALSE;
for (i = 0; i < num_c1222_uat_data; i++) {
if (c1222_uat_data[i].keynum == keyid) {
memcpy(keybuff, c1222_uat_data[i].key, EAX_SIZEOF_KEY);
return TRUE;
}
}
return FALSE;
}
static gboolean
decrypt_packet(guchar *buffer, guint32 length, gboolean decrypt)
{
#define CANONBUFFSIZE 300U
guchar canonbuff[CANONBUFFSIZE];
guint8 c1222_key[EAX_SIZEOF_KEY];
guchar key_id = 0;
guint32 offset = 0;
gboolean status = FALSE;
if (length < 4)
return status;
if (key_id_element != NULL)
key_id = key_id_element[0];
if (!canonify_unencrypted_header(canonbuff, &offset, CANONBUFFSIZE))
return status;
if (offset) {
if (!keylookup((guint8 *)&c1222_key, key_id))
return FALSE;
status = Eax_Decrypt(canonbuff, c1222_key, buffer,
offset, EAX_SIZEOF_KEY, length-4,
(MAC_T *)&buffer[length-4],
decrypt ? EAX_MODE_CIPHERTEXT_AUTH : EAX_MODE_CLEARTEXT_AUTH);
}
return status;
}
static gboolean
decrypt_packet(guchar *buffer _U_, guint32 length _U_, gboolean decrypt _U_)
{
return FALSE;
}
static gboolean
ber_len_ok(tvbuff_t *tvb, int offset)
{
guint8 ch;
if (tvb_offset_exists(tvb, offset)) {
ch = tvb_get_guint8(tvb, offset);
offset++;
if (!(ch & 0x80)) {
return TRUE;
} else if (tvb_offset_exists(tvb, offset)) {
ch = tvb_get_guint8(tvb, offset);
offset++;
if (!(ch & 0x80)) {
return TRUE;
} else if (tvb_offset_exists(tvb, offset)) {
ch = tvb_get_guint8(tvb, offset);
offset++;
if (!(ch & 0x80)) {
return TRUE;
} else if (tvb_offset_exists(tvb, offset)) {
ch = tvb_get_guint8(tvb, offset);
if (!(ch & 0x80)) {
return TRUE;
}
}
}
}
}
return FALSE;
}
static int
dissect_epsem(tvbuff_t *tvb, int offset, guint32 len, packet_info *pinfo, proto_tree *tree)
{
proto_tree *cmd_tree = NULL;
proto_tree *ct = NULL;
proto_tree *crypto_tree = NULL;
proto_tree *yt = NULL;
proto_item *item = NULL;
guint8 flags;
int local_offset;
gint len2;
int cmd_err;
gboolean ind;
guchar *buffer;
tvbuff_t *epsem_buffer = NULL;
gboolean crypto_good = FALSE;
gboolean crypto_bad = FALSE;
gboolean hasmac = FALSE;
gboolean encrypted = FALSE;
if ((tvb == NULL) && (len == 0)) {
expert_add_info(pinfo, tree, &ei_c1222_epsem_missing);
return offset;
}
flags = tvb_get_guint8(tvb, offset);
proto_tree_add_bitmask(tree, tvb, offset, hf_c1222_epsem_flags, ett_c1222_flags, c1222_flags, ENC_BIG_ENDIAN);
offset++;
switch ((flags & C1222_EPSEM_FLAG_SECURITY_MODE) >> 2) {
case EAX_MODE_CIPHERTEXT_AUTH:
hasmac = TRUE;
len2 = tvb_length_remaining(tvb, offset);
if (len2 <= 0)
return offset;
encrypted = TRUE;
if (c1222_decrypt) {
buffer = (guchar *)tvb_memdup(wmem_packet_scope(), tvb, offset, len2);
if (!decrypt_packet(buffer, len2, TRUE)) {
crypto_bad = TRUE;
} else {
epsem_buffer = tvb_new_real_data(buffer, len2, len2);
tvb_set_child_real_data_tvbuff(tvb, epsem_buffer);
add_new_data_source(pinfo, epsem_buffer, "Decrypted EPSEM Data");
crypto_good = TRUE;
encrypted = FALSE;
}
}
break;
case EAX_MODE_CLEARTEXT_AUTH:
hasmac = TRUE;
len2 = tvb_length_remaining(tvb, offset);
if (len2 <= 0)
return offset;
buffer = (guchar *)tvb_memdup(wmem_packet_scope(), tvb, offset, len2);
epsem_buffer = tvb_new_subset_remaining(tvb, offset);
if (c1222_decrypt) {
if (!decrypt_packet(buffer, len2, FALSE)) {
#ifdef HAVE_LIBGCRYPT
crypto_bad = TRUE;
expert_add_info(pinfo, tree, &ei_c1222_epsem_failed_authentication);
#else
expert_add_info(pinfo, tree, &ei_c1222_epsem_not_authenticated);
#endif
} else {
crypto_good = TRUE;
}
}
break;
default:
epsem_buffer = tvb_new_subset_remaining(tvb, offset);
}
if (encrypted) {
proto_tree_add_item(tree, hf_c1222_epsem_total, tvb, offset, -1, ENC_NA);
expert_add_info(pinfo, tree, &ei_c1222_epsem_not_decryped);
local_offset = offset+len2-4;
epsem_buffer = tvb;
} else {
local_offset = 0;
if (flags & C1222_EPSEM_FLAG_ED_CLASS_INCLUDED) {
if (tvb_offset_exists(epsem_buffer, local_offset+4-1)) {
proto_tree_add_item(tree, hf_c1222_epsem_ed_class, epsem_buffer, local_offset, 4, ENC_NA);
local_offset += 4;
} else {
expert_add_info(pinfo, tree, &ei_c1222_ed_class_missing);
}
}
while (tvb_offset_exists(epsem_buffer, local_offset+(hasmac?5:1))) {
if (ber_len_ok(epsem_buffer, local_offset)) {
local_offset = dissect_ber_length(pinfo, tree, epsem_buffer, local_offset, (guint32 *)&len2, &ind);
} else {
expert_add_info(pinfo, tree, &ei_c1222_epsem_ber_length_error);
return offset+len;
}
if (tvb_offset_exists(epsem_buffer, local_offset+len2-1)) {
cmd_err = tvb_get_guint8(epsem_buffer, local_offset);
ct = proto_tree_add_item(tree, hf_c1222_epsem_total, epsem_buffer, local_offset, len2, ENC_NA);
cmd_tree = proto_item_add_subtree(ct, ett_c1222_cmd);
parse_c1222_detailed(epsem_buffer, pinfo, cmd_tree, cmd_err, (guint32 *)&len2, &local_offset);
local_offset += len2;
} else {
expert_add_info(pinfo, tree, &ei_c1222_epsem_field_length_error);
return offset+len;
}
}
}
if (hasmac) {
if (tvb_offset_exists(epsem_buffer, local_offset+4-1)) {
yt = proto_tree_add_item(tree, hf_c1222_epsem_mac, epsem_buffer, local_offset, 4, ENC_NA);
crypto_tree = proto_item_add_subtree(yt, ett_c1222_crypto);
item = proto_tree_add_boolean(crypto_tree, hf_c1222_epsem_crypto_good, tvb, local_offset, 4, crypto_good);
PROTO_ITEM_SET_GENERATED(item);
item = proto_tree_add_boolean(crypto_tree, hf_c1222_epsem_crypto_bad, tvb, local_offset, 4, crypto_bad);
PROTO_ITEM_SET_GENERATED(item);
} else {
expert_add_info(pinfo, tree, &ei_c1222_mac_missing);
return offset+len;
}
}
return offset;
}
static void
dissect_c1222_common(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *c1222_item = NULL;
proto_tree *c1222_tree = NULL;
col_set_str(pinfo->cinfo, COL_PROTOCOL, PNAME);
if (tree) {
c1222_item = proto_tree_add_item(tree, proto_c1222, tvb, 0, -1, ENC_NA);
c1222_tree = proto_item_add_subtree(c1222_item, ett_c1222);
dissect_MESSAGE_PDU(tvb, pinfo, c1222_tree);
}
}
static guint
get_c1222_message_len(packet_info *pinfo, tvbuff_t *tvb, int offset)
{
int orig_offset;
guint length;
gboolean ind;
orig_offset = offset;
offset = dissect_ber_length(pinfo, NULL, tvb, offset+1, &length, &ind);
return length+(offset - orig_offset);
}
static void
dissect_c1222(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
tcp_dissect_pdus(tvb, pinfo, tree, c1222_desegment, 5,
get_c1222_message_len, dissect_c1222_common);
}
void proto_register_c1222(void) {
static hf_register_info hf[] = {
{ &hf_c1222_epsem_flags,
{ "C12.22 EPSEM Flags", "c1222.epsem.flags",
FT_UINT8, BASE_HEX,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_c1222_epsem_flags_reserved,
{ "C12.22 Reserved Flag", "c1222.epsem.flags.reserved",
FT_BOOLEAN, 8,
NULL, C1222_EPSEM_FLAG_RESERVED,
NULL, HFILL }
},
{ &hf_c1222_epsem_flags_recovery,
{ "C12.22 Recovery Flag", "c1222.epsem.flags.recovery",
FT_BOOLEAN, 8,
NULL, C1222_EPSEM_FLAG_RECOVERY_SESSION,
NULL, HFILL }
},
{ &hf_c1222_epsem_flags_proxy,
{ "C12.22 Proxy Service Used Flag", "c1222.epsem.flags.proxy",
FT_BOOLEAN, 8,
NULL, C1222_EPSEM_FLAG_PROXY_SERVICE_USED,
NULL, HFILL }
},
{ &hf_c1222_epsem_flags_ed_class,
{ "C12.22 ED Class Flag", "c1222.epsem.flags.ed_class",
FT_BOOLEAN, 8,
NULL, C1222_EPSEM_FLAG_ED_CLASS_INCLUDED,
NULL, HFILL }
},
{ &hf_c1222_epsem_flags_security_modes,
{ "C12.22 Security Mode Flags", "c1222.epsem.flags.security",
FT_UINT8, BASE_HEX,
VALS(c1222_security_modes), C1222_EPSEM_FLAG_SECURITY_MODE,
NULL, HFILL }
},
{ &hf_c1222_epsem_flags_response_control,
{ "C12.22 Response Control Flags", "c1222.epsem.flags.response_control",
FT_UINT8, BASE_HEX,
VALS(c1222_response_control), C1222_EPSEM_FLAG_RESPONSE_CONTROL,
NULL, HFILL }
},
{ &hf_c1222_epsem_ed_class,
{ "C12.22 EPSEM ED Class", "c1222.epsem.edclass",
FT_BYTES, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_c1222_epsem_total,
{ "C12.22 EPSEM", "c1222.epsem.data",
FT_BYTES, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_c1222_epsem_mac,
{ "C12.22 EPSEM MAC", "c1222.epsem.mac",
FT_BYTES, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_c1222_cmd,
{ "C12.22 Command", "c1222.cmd",
FT_UINT8, BASE_HEX,
VALS(commandnames), 0x0,
NULL, HFILL }
},
{ &hf_c1222_err,
{ "C12.22 Response", "c1222.err",
FT_UINT8, BASE_HEX,
VALS(commandnames), 0x0,
NULL, HFILL }
},
{ &hf_c1222_logon_id,
{ "C12.22 Logon User-Id", "c1222.logon.id",
FT_UINT16, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_c1222_logon_user,
{ "C12.22 Logon User", "c1222.logon.user",
FT_STRING, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_c1222_security_password,
{ "C12.22 Security Password", "c1222.security.password",
FT_STRING, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_c1222_auth_len,
{ "C12.22 Authenticate Request Length", "c1222.authenticate.len",
FT_UINT8, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_c1222_auth_data,
{ "C12.22 Authenticate Data", "c1222.authenticate.data",
FT_BYTES, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_c1222_read_table,
{ "C12.22 Table", "c1222.read.table",
FT_UINT16, BASE_HEX,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_c1222_read_offset,
{ "C12.22 Offset", "c1222.read.offset",
FT_UINT24, BASE_HEX,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_c1222_read_count,
{ "C12.22 Count", "c1222.read.count",
FT_UINT16, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_c1222_write_table,
{ "C12.22 Table", "c1222.write.table",
FT_UINT16, BASE_HEX,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_c1222_write_offset,
{ "C12.22 Offset", "c1222.write.offset",
FT_UINT24, BASE_HEX,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_c1222_write_size,
{ "C12.22 Table Size", "c1222.write.size",
FT_UINT16, BASE_HEX,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_c1222_write_data,
{ "C12.22 Table Data", "c1222.write.data",
FT_BYTES, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_c1222_write_chksum,
{ "C12.22 Table Data Checksum", "c1222.write.chksum",
FT_UINT8, BASE_HEX,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_c1222_procedure_num,
{ "C12.22 Procedure Number", "c1222.procedure.num",
FT_UINT16, BASE_DEC,
NULL, 0x7ff,
NULL, HFILL }
},
{ &hf_c1222_neg_pkt_size,
{ "C12.22 Negotiate Packet Size", "c1222.negotiate.pktsize",
FT_UINT16, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_c1222_neg_nbr_pkts,
{ "C12.22 Negotiate Number of Packets", "c1222.negotiate.numpkts",
FT_UINT8, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_c1222_wait_secs,
{ "C12.22 Wait Seconds", "c1222.wait.seconds",
FT_UINT8, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_c1222_timing_setup_traffic,
{ "C12.22 Timing Setup Channel Traffic Timeout", "c1222.timingsetup.traffic",
FT_UINT8, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_c1222_timing_setup_inter_char,
{ "C12.22 Timing Setup Intercharacter Timeout", "c1222.timingsetup.interchar",
FT_UINT8, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_c1222_timing_setup_resp_to,
{ "C12.22 Timing Setup Response Timeout", "c1222.timingsetup.respto",
FT_UINT8, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_c1222_timing_setup_nbr_retries,
{ "C12.22 Timing Setup Number of Retries", "c1222.timingsetup.nbrretries",
FT_UINT8, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_c1222_data,
{ "C12.22 data", "c1222.data",
FT_BYTES, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_c1222_epsem_crypto_good,
{ "Crypto good", "c1222.crypto_good",
FT_BOOLEAN, BASE_NONE,
NULL, 0x0,
"True: crypto ok; False: doesn't match or not checked", HFILL }
},
{ &hf_c1222_epsem_crypto_bad,
{ "Crypto bad", "c1222.crypto_bad",
FT_BOOLEAN, BASE_NONE,
NULL, 0x0,
"True: crypto bad; False: crypto ok or not checked", HFILL }
},
#include "packet-c1222-hfarr.c"
};
static gint *ett[] = {
&ett_c1222,
&ett_c1222_epsem,
&ett_c1222_flags,
&ett_c1222_crypto,
&ett_c1222_cmd,
#include "packet-c1222-ettarr.c"
};
static ei_register_info ei[] = {
{ &ei_c1222_command_truncated, { "c1222.command_truncated", PI_MALFORMED, PI_ERROR, "C12.22 command truncated", EXPFILL }},
{ &ei_c1222_bad_checksum, { "c1222.bad_checksum", PI_CHECKSUM, PI_ERROR, "Bad checksum", EXPFILL }},
{ &ei_c1222_epsem_missing, { "c1222.epsem.missing", PI_MALFORMED, PI_ERROR, "C12.22 EPSEM missing", EXPFILL }},
#ifdef HAVE_LIBGCRYPT
{ &ei_c1222_epsem_failed_authentication, { "c1222.epsem.failed_authentication", PI_SECURITY, PI_ERROR, "C12.22 EPSEM failed authentication", EXPFILL }},
#else
{ &ei_c1222_epsem_not_authenticated, { "c1222.epsem.not_authenticated", PI_SECURITY, PI_WARN, "C12.22 EPSEM could not be authenticated", EXPFILL }},
#endif
{ &ei_c1222_epsem_not_decryped, { "c1222.epsem.not_decryped", PI_UNDECODED, PI_WARN, "C12.22 EPSEM could not be decrypted", EXPFILL }},
{ &ei_c1222_ed_class_missing, { "c1222.ed_class_missing", PI_SECURITY, PI_ERROR, "C12.22 ED Class missing", EXPFILL }},
{ &ei_c1222_epsem_ber_length_error, { "c1222.epsem.ber_length_error", PI_MALFORMED, PI_ERROR, "C12.22 EPSEM BER length error", EXPFILL }},
{ &ei_c1222_epsem_field_length_error, { "c1222.epsem.field_length_error", PI_MALFORMED, PI_ERROR, "C12.22 EPSEM field length error", EXPFILL }},
{ &ei_c1222_mac_missing, { "c1222.mac_missing", PI_MALFORMED, PI_ERROR, "C12.22 MAC missing", EXPFILL }},
};
expert_module_t* expert_c1222;
module_t *c1222_module;
#ifdef HAVE_LIBGCRYPT
static uat_field_t c1222_uat_flds[] = {
UAT_FLD_HEX(c1222_users,keynum,"Key ID","Key identifier in hexadecimal"),
UAT_FLD_BUFFER(c1222_users, key, "Key", "Encryption key as 16-byte hex string"),
UAT_END_FIELDS
};
#endif
proto_c1222 = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_c1222, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_c1222 = expert_register_protocol(proto_c1222);
expert_register_field_array(expert_c1222, ei, array_length(ei));
c1222_module = prefs_register_protocol(proto_c1222, proto_reg_handoff_c1222);
prefs_register_bool_preference(c1222_module, "desegment",
"Reassemble all C12.22 messages spanning multiple TCP segments",
"Whether the C12.22 dissector should reassemble all messages spanning multiple TCP segments",
&c1222_desegment);
prefs_register_string_preference(c1222_module, "baseoid", "Base OID to use for relative OIDs",
"Base object identifier for use in resolving relative object identifiers",
&c1222_baseoid_str);
#ifdef HAVE_LIBGCRYPT
prefs_register_bool_preference(c1222_module, "decrypt",
"Verify crypto for all applicable C12.22 messages",
"Whether the C12.22 dissector should verify the crypto for all relevant messages",
&c1222_decrypt);
c1222_uat = uat_new("Decryption Table",
sizeof(c1222_uat_data_t),
"c1222_decryption_table",
TRUE,
(void**)&c1222_uat_data,
&num_c1222_uat_data,
UAT_AFFECTS_DISSECTION,
NULL,
NULL,
c1222_uat_data_update_cb,
NULL,
NULL,
c1222_uat_flds);
prefs_register_uat_preference(c1222_module,
"decryption_table",
"Decryption Table",
"Table of security parameters for decryption of C12.22 packets",
c1222_uat);
#endif
}
void
proto_reg_handoff_c1222(void)
{
static gboolean initialized = FALSE;
guint8 *temp = NULL;
if( !initialized ) {
c1222_handle = create_dissector_handle(dissect_c1222, proto_c1222);
c1222_udp_handle = create_dissector_handle(dissect_c1222_common, proto_c1222);
dissector_add_uint("tcp.port", global_c1222_port, c1222_handle);
dissector_add_uint("udp.port", global_c1222_port, c1222_udp_handle);
initialized = TRUE;
}
c1222_baseoid_len = oid_string2encoded(c1222_baseoid_str, &temp);
c1222_baseoid = (guint8 *)wmem_realloc(wmem_epan_scope(), c1222_baseoid, c1222_baseoid_len);
memcpy(c1222_baseoid, temp, c1222_baseoid_len);
}
