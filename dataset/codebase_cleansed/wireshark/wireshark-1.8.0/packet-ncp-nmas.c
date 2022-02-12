static int
nmas_string(tvbuff_t* tvb, int hfinfo, proto_tree *nmas_tree, int offset, gboolean little)
{
int foffset = offset;
guint32 str_length;
char *buffer;
guint32 i;
guint16 c_char;
guint32 length_remaining = 0;
buffer=ep_alloc(ITEM_LABEL_LENGTH+1);
if (little) {
str_length = tvb_get_letohl(tvb, foffset);
}
else
{
str_length = tvb_get_ntohl(tvb, foffset);
}
foffset += 4;
if(str_length >= ITEM_LABEL_LENGTH)
{
proto_tree_add_string(nmas_tree, hfinfo, tvb, foffset,
length_remaining + 4, "<String too long to process>");
foffset += length_remaining;
return foffset;
}
if(str_length == 0)
{
proto_tree_add_string(nmas_tree, hfinfo, tvb, offset,
4, "<Not Specified>");
return foffset;
}
for ( i = 0; i < str_length; i++ )
{
c_char = tvb_get_guint8(tvb, foffset );
if (c_char<0x20 || c_char>0x7e)
{
if (c_char != 0x00)
{
c_char = 0x2e;
buffer[i] = c_char & 0xff;
}
else
{
i--;
str_length--;
}
}
else
{
buffer[i] = c_char & 0xff;
}
foffset++;
length_remaining--;
if(length_remaining==1)
{
i++;
break;
}
}
buffer[i] = '\0';
if (little) {
str_length = tvb_get_letohl(tvb, offset);
}
else
{
str_length = tvb_get_ntohl(tvb, offset);
}
proto_tree_add_string(nmas_tree, hfinfo, tvb, offset+4,
str_length, buffer);
return foffset;
}
void
dissect_nmas_request(tvbuff_t *tvb, packet_info *pinfo, proto_tree *ncp_tree, ncp_req_hash_value *request_value)
{
guint8 subfunc;
guint32 msg_length=0, cur_string_len=0;
guint32 foffset;
guint32 subverb=0;
guint32 attribute=0;
guint8 msgverb=0;
proto_tree *atree;
proto_item *aitem;
foffset = 6;
foffset += 1;
subfunc = tvb_get_guint8(tvb, foffset);
foffset += 1;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "NMAS");
if (check_col(pinfo->cinfo, COL_INFO)) {
col_add_fstr(pinfo->cinfo, COL_INFO, "C NMAS - %s",
val_to_str(subfunc, nmas_func_enum, "Unknown (0x%02x)"));
}
aitem = proto_tree_add_text(ncp_tree, tvb, foffset, -1, "Packet Type: %s",
val_to_str(subfunc, nmas_func_enum, "Unknown (0x%02x)"));
atree = proto_item_add_subtree(aitem, ett_nmas);
switch (subfunc) {
case 1:
proto_tree_add_item(atree, hf_ping_version, tvb, foffset, 4, ENC_LITTLE_ENDIAN);
foffset += 4;
proto_tree_add_item(atree, hf_ping_flags, tvb, foffset, 4, ENC_LITTLE_ENDIAN);
foffset += 4;
break;
case 2:
proto_tree_add_item(atree, hf_frag_handle, tvb, foffset, 4, ENC_LITTLE_ENDIAN);
if (tvb_get_letohl(tvb, foffset)!=0xffffffff) {
break;
}
foffset += 4;
foffset += 4;
proto_tree_add_item(atree, hf_length, tvb, foffset, 4, ENC_LITTLE_ENDIAN);
msg_length = tvb_get_letohl(tvb, foffset);
foffset += 4;
foffset += 12;
msg_length -= 16;
proto_tree_add_item(atree, hf_subverb, tvb, foffset, 4, ENC_LITTLE_ENDIAN);
subverb = tvb_get_letohl(tvb, foffset);
if (request_value) {
request_value->req_nds_flags=subverb;
}
foffset += 4;
msg_length -= 4;
if (check_col(pinfo->cinfo, COL_INFO)) {
col_append_fstr(pinfo->cinfo, COL_INFO, ", %s",
val_to_str(subverb, nmas_subverb_enum, "Unknown subverb (%u)"));
}
switch (subverb) {
case 0:
proto_tree_add_item(atree, hf_ping_version, tvb, foffset, 4, ENC_LITTLE_ENDIAN);
foffset += 4;
proto_tree_add_item(atree, hf_ping_flags, tvb, foffset, 4, ENC_LITTLE_ENDIAN);
foffset += 4;
break;
case 2:
proto_tree_add_item(atree, hf_opaque, tvb, foffset, msg_length, ENC_NA);
foffset += msg_length;
break;
case 4:
case 6:
break;
case 8:
proto_tree_add_item(atree, hf_reply_buffer_size, tvb, foffset, 1, ENC_LITTLE_ENDIAN);
foffset += 4;
msgverb = tvb_get_guint8(tvb, foffset);
if (request_value) {
request_value->nds_request_verb=msgverb;
}
proto_tree_add_item(atree, hf_lsm_verb, tvb, foffset, 1, ENC_LITTLE_ENDIAN);
foffset += 4;
if (check_col(pinfo->cinfo, COL_INFO)) {
col_append_fstr(pinfo->cinfo, COL_INFO, ", %s",
val_to_str(msgverb, nmas_lsmverb_enum, "Unknown (%u)"));
}
switch (msgverb)
{
case 1:
break;
case 2:
break;
case 4:
break;
case 5:
break;
case 6:
break;
default:
break;
}
break;
case 10:
foffset += 4;
foffset += 8;
foffset = nmas_string(tvb, hf_tree, atree, foffset, TRUE);
foffset = nmas_string(tvb, hf_user, atree, foffset, TRUE);
break;
case 1242:
foffset += 4;
proto_tree_add_item(atree, hf_msg_version, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_tree_add_item(atree, hf_session_ident, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
foffset += 3;
msgverb = tvb_get_guint8(tvb, foffset);
if (request_value) {
request_value->nds_request_verb=msgverb;
}
proto_tree_add_item(atree, hf_msg_verb, tvb, foffset, 1, ENC_BIG_ENDIAN);
foffset += 1;
msg_length -= 12;
if (check_col(pinfo->cinfo, COL_INFO)) {
col_append_fstr(pinfo->cinfo, COL_INFO, ", %s",
val_to_str(msgverb, nmas_msgverb_enum, "Unknown (%u)"));
}
switch(msgverb)
{
case 1:
msg_length = tvb_get_ntohl(tvb, foffset);
proto_tree_add_item(atree, hf_length, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_tree_add_item(atree, hf_data, tvb, foffset, msg_length, ENC_NA);
foffset += msg_length;
break;
case 3:
msg_length = tvb_get_ntohl(tvb, foffset);
msg_length -= 4;
proto_tree_add_item(atree, hf_length, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
while (msg_length > 0)
{
attribute = tvb_get_ntohl(tvb, foffset);
foffset += 4;
cur_string_len=tvb_get_ntohl(tvb, foffset);
switch (attribute) {
case 1:
foffset = nmas_string(tvb, hf_user, atree, foffset, FALSE);
break;
case 2:
foffset = nmas_string(tvb, hf_tree, atree, foffset, FALSE);
break;
case 4:
foffset = nmas_string(tvb, hf_clearance, atree, foffset, FALSE);
break;
case 11:
foffset = nmas_string(tvb, hf_login_sequence, atree, foffset, FALSE);
break;
default:
break;
}
msg_length -= cur_string_len;
if (tvb_reported_length_remaining(tvb, foffset)<5)
{
break;
}
}
break;
case 5:
proto_tree_add_item(atree, hf_opaque, tvb, foffset, tvb_reported_length_remaining(tvb, foffset), ENC_NA);
foffset += msg_length;
break;
case 7:
case 9:
break;
default:
break;
}
break;
default:
break;
}
break;
case 3:
break;
default:
break;
}
}
void
dissect_nmas_reply(tvbuff_t *tvb, packet_info *pinfo, proto_tree *ncp_tree, guint8 func _U_, guint8 subfunc, ncp_req_hash_value *request_value)
{
guint32 foffset=0, roffset=0;
guint32 subverb=0;
guint8 msgverb=0;
guint32 msg_length=0;
guint32 return_code=0, encrypt_error=0;
proto_tree *atree;
proto_item *aitem;
proto_item *expert_item;
const gchar *str;
foffset = 8;
if (request_value) {
subverb = request_value->req_nds_flags;
msgverb = request_value->nds_request_verb;
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "NMAS");
if (tvb_reported_length_remaining(tvb, foffset)<4) {
return;
}
aitem = proto_tree_add_text(ncp_tree, tvb, foffset, -1, "Packet Type: %s",
val_to_str(subfunc, nmas_func_enum, "Unknown (0x%02x)"));
atree = proto_item_add_subtree(aitem, ett_nmas);
switch (subfunc) {
case 1:
proto_tree_add_item(atree, hf_ping_flags, tvb, foffset, 4, ENC_LITTLE_ENDIAN);
foffset += 4;
proto_tree_add_item(atree, hf_nmas_version, tvb, foffset, 4, ENC_LITTLE_ENDIAN);
foffset += 4;
break;
case 2:
proto_tree_add_text(atree, tvb, foffset, -1, "Verb: %s",
val_to_str(subverb, nmas_subverb_enum, "Unknown (%u)"));
proto_tree_add_item(atree, hf_length, tvb, foffset, 4, ENC_LITTLE_ENDIAN);
msg_length = tvb_get_letohl(tvb, foffset);
foffset +=4;
proto_tree_add_item(atree, hf_frag_handle, tvb, foffset, 4, ENC_LITTLE_ENDIAN);
if (tvb_get_letohl(tvb, foffset)!=0xffffffff) {
break;
}
foffset += 4;
return_code = tvb_get_letohl(tvb, foffset);
roffset = foffset;
foffset += 4;
msg_length -= 8;
if (return_code == 0 && msg_length > 0)
{
switch (subverb) {
case 0:
proto_tree_add_item(atree, hf_ping_flags, tvb, foffset, 4, ENC_LITTLE_ENDIAN);
foffset += 4;
proto_tree_add_item(atree, hf_nmas_version, tvb, foffset, 4, ENC_LITTLE_ENDIAN);
foffset += 4;
break;
case 2:
proto_tree_add_item(atree, hf_squeue_bytes, tvb, foffset, 4, ENC_LITTLE_ENDIAN);
foffset += 4;
proto_tree_add_item(atree, hf_cqueue_bytes, tvb, foffset, 4, ENC_LITTLE_ENDIAN);
foffset += 4;
break;
case 4:
proto_tree_add_item(atree, hf_opaque, tvb, foffset, msg_length, ENC_NA);
foffset += msg_length;
break;
case 6:
proto_tree_add_item(atree, hf_num_creds, tvb, foffset, 4, ENC_LITTLE_ENDIAN);
foffset += 4;
proto_tree_add_item(atree, hf_cred_type, tvb, foffset, 4, ENC_LITTLE_ENDIAN);
foffset += 4;
proto_tree_add_item(atree, hf_login_state, tvb, foffset, 4, ENC_LITTLE_ENDIAN);
foffset += 4;
msg_length -= 12;
proto_tree_add_item(atree, hf_enc_cred, tvb, foffset, msg_length, ENC_NA);
foffset += msg_length;
break;
case 8:
proto_tree_add_text(atree, tvb, foffset, -1, "Subverb: %s",
val_to_str(msgverb, nmas_lsmverb_enum, "Unknown (%u)"));
switch(msgverb)
{
case 1:
case 3:
case 5:
case 7:
case 9:
proto_tree_add_item(atree, hf_enc_data, tvb, foffset, msg_length, ENC_NA);
foffset += msg_length;
break;
default:
break;
}
break;
case 10:
proto_tree_add_item(atree, hf_nmas_version, tvb, foffset, 4, ENC_LITTLE_ENDIAN);
foffset += 4;
break;
case 1242:
proto_tree_add_text(atree, tvb, foffset, -1, "Subverb: %s",
val_to_str(msgverb, nmas_msgverb_enum, "Unknown (%u)"));
switch(msgverb)
{
case 1:
msg_length = tvb_get_ntohl(tvb, foffset);
proto_tree_add_item(atree, hf_length, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
proto_tree_add_item(atree, hf_data, tvb, foffset, msg_length, ENC_NA);
foffset += msg_length;
break;
case 3:
proto_tree_add_item(atree, hf_session_ident, tvb, foffset, 4, ENC_BIG_ENDIAN);
foffset += 4;
break;
case 5:
break;
case 7:
encrypt_error = tvb_get_ntohl(tvb, foffset);
str = match_strval(encrypt_error, nmas_errors_enum);
if (str)
{
col_add_fstr(pinfo->cinfo, COL_INFO, "R Payload Error - %s", str);
expert_item = proto_tree_add_item(atree, hf_encrypt_error, tvb, foffset, 4, ENC_BIG_ENDIAN);
expert_add_info_format(pinfo, expert_item, PI_RESPONSE_CODE, PI_ERROR, "NMAS Payload Error: %s", str);
}
else
{
proto_tree_add_item(atree, hf_opaque, tvb, foffset, msg_length, ENC_NA);
}
foffset += msg_length;
break;
case 9:
break;
default:
break;
}
break;
default:
break;
}
}
str = match_strval(return_code, nmas_errors_enum);
if (str)
{
expert_item = proto_tree_add_item(atree, hf_return_code, tvb, roffset, 4, ENC_LITTLE_ENDIAN);
expert_add_info_format(pinfo, expert_item, PI_RESPONSE_CODE, PI_ERROR, "NMAS Error: 0x%08x %s", return_code, str);
col_add_fstr(pinfo->cinfo, COL_INFO, "R Error - %s", str);
}
else
{
if (return_code!=0)
{
expert_item = proto_tree_add_item(atree, hf_return_code, tvb, roffset, 4, ENC_LITTLE_ENDIAN);
expert_add_info_format(pinfo, expert_item, PI_RESPONSE_CODE, PI_ERROR, "NMAS Error: 0x%08x is unknown", return_code);
if (check_col(pinfo->cinfo, COL_INFO)) {
col_add_fstr(pinfo->cinfo, COL_INFO, "R Unknown NMAS Error - 0x%08x", return_code);
}
}
}
if (return_code == 0) {
proto_tree_add_text(atree, tvb, roffset, 4, "Return Code: Success (0x00000000)");
}
break;
case 3:
break;
default:
break;
}
}
void
proto_register_nmas(void)
{
static hf_register_info hf_nmas[] = {
{ &hf_func,
{ "Function", "nmas.func", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_subfunc,
{ "Subfunction", "nmas.subfunc", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_ping_version,
{ "Ping Version", "nmas.ping_version", FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_ping_flags,
{ "Flags", "nmas.ping_flags", FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_frag_handle,
{ "Fragment Handle", "nmas.frag_handle", FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_length,
{ "Length", "nmas.length", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_subverb,
{ "Sub Verb", "nmas.subverb",
FT_UINT32, BASE_HEX, VALS(nmas_subverb_enum), 0x0,
NULL, HFILL }},
{ &hf_tree,
{ "Tree", "nmas.tree",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_user,
{ "User", "nmas.user",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_nmas_version,
{ "NMAS Protocol Version", "nmas.version", FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_msg_version,
{ "Message Version", "nmas.msg_version", FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_session_ident,
{ "Session Identifier", "nmas.session_ident", FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_msg_verb,
{ "Message Verb", "nmas.msg_verb", FT_UINT8, BASE_HEX, VALS(nmas_msgverb_enum), 0x0,
NULL, HFILL }},
{ &hf_attribute,
{ "Attribute Type", "nmas.attribute", FT_UINT32, BASE_DEC, VALS(nmas_attribute_enum), 0x0,
NULL, HFILL }},
{ &hf_clearance,
{ "Requested Clearance", "nmas.clearance",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_login_sequence,
{ "Requested Login Sequence", "nmas.login_seq",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_opaque,
{ "Opaque Data", "nmas.opaque",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_data,
{ "Data", "nmas.data",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_return_code,
{ "Return Code", "nmas.return_code", FT_UINT32, BASE_HEX, VALS(nmas_errors_enum), 0x0,
NULL, HFILL }},
{ &hf_lsm_verb,
{ "Login Store Message Verb", "nmas.lsm_verb", FT_UINT8, BASE_HEX, VALS(nmas_lsmverb_enum), 0x0,
NULL, HFILL }},
{ &hf_squeue_bytes,
{ "Server Queue Number of Bytes", "nmas.squeue_bytes", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_cqueue_bytes,
{ "Client Queue Number of Bytes", "nmas.cqueue_bytes", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_num_creds,
{ "Number of Credentials", "nmas.num_creds", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_cred_type,
{ "Credential Type", "nmas.cred_type", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_login_state,
{ "Login State", "nmas.login_state", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_enc_cred,
{ "Encrypted Credential", "nmas.enc_cred",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_enc_data,
{ "Encrypted Data", "nmas.enc_data",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_reply_buffer_size,
{ "Reply Buffer Size", "nmas.buf_size", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_encrypt_error,
{ "Payload Error", "nmas.encrypt_error", FT_UINT32, BASE_HEX, VALS(nmas_errors_enum), 0x0,
"Payload/Encryption Return Code", HFILL }},
};
static gint *ett[] = {
&ett_nmas,
};
proto_nmas = proto_register_protocol("Novell Modular Authentication Service", "NMAS", "nmas");
proto_register_field_array(proto_nmas, hf_nmas, array_length(hf_nmas));
proto_register_subtree_array(ett, array_length(ett));
}
