static guint
get_text_string(tvbuff_t *tvb, guint offset, const char **strval)
{
guint len;
DebugLog(("get_text_string(tvb = %p, offset = %u, **strval) - start\n",
tvb, offset));
len = tvb_strsize(tvb, offset);
DebugLog((" [1] tvb_strsize(tvb, offset) == %u\n", len));
if (tvb_get_guint8(tvb, offset) == MM_QUOTE)
*strval = (const char *)tvb_memdup(wmem_packet_scope(), tvb, offset+1, len-1);
else
*strval = (const char *)tvb_memdup(wmem_packet_scope(), tvb, offset, len);
DebugLog((" [3] Return(len) == %u\n", len));
return len;
}
static guint
get_value_length(tvbuff_t *tvb, guint offset, guint *byte_count, packet_info *pinfo)
{
guint field;
field = tvb_get_guint8(tvb, offset++);
if (field < 31)
*byte_count = 1;
else {
field = tvb_get_guintvar(tvb, offset, byte_count, pinfo, &ei_mmse_oversized_uintvar);
(*byte_count)++;
}
return field;
}
static guint
get_encoded_strval(tvbuff_t *tvb, guint offset, const char **strval, packet_info *pinfo)
{
guint field;
guint length;
guint count;
field = tvb_get_guint8(tvb, offset);
if (field < 32) {
length = get_value_length(tvb, offset, &count, pinfo);
if (length < 2) {
*strval = "";
} else {
*strval = (char *)tvb_get_string_enc(wmem_packet_scope(), tvb, offset + count + 1, length - 1, ENC_ASCII);
}
return count + length;
} else
return get_text_string(tvb, offset, strval);
}
static guint
get_long_integer(tvbuff_t *tvb, guint offset, guint *byte_count)
{
guint val;
*byte_count = tvb_get_guint8(tvb, offset++);
switch (*byte_count) {
case 1:
val = tvb_get_guint8(tvb, offset);
break;
case 2:
val = tvb_get_ntohs(tvb, offset);
break;
case 3:
val = tvb_get_ntoh24(tvb, offset);
break;
case 4:
val = tvb_get_ntohl(tvb, offset);
break;
default:
val = 0;
break;
}
(*byte_count)++;
return val;
}
static guint
get_integer_value(tvbuff_t *tvb, guint offset, guint *byte_count)
{
guint val;
guint8 peek;
peek = tvb_get_guint8(tvb, offset++);
if (peek & 0x80) {
val = peek & 0x7F;
*byte_count = 1;
return val;
} else {
*byte_count = peek;
switch (peek) {
case 1:
val = tvb_get_guint8(tvb, offset);
break;
case 2:
val = tvb_get_ntohs(tvb, offset);
break;
case 3:
val = tvb_get_ntoh24(tvb, offset);
break;
case 4:
val = tvb_get_ntohl(tvb, offset);
break;
default:
val = 0;
break;
}
}
(*byte_count)++;
return val;
}
static gboolean
dissect_mmse_heur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
guint8 pdut;
DebugLog(("dissect_mmse_heur()\n"));
if (tvb_get_guint8(tvb, 0) != MM_MTYPE_HDR)
return FALSE;
pdut = tvb_get_guint8(tvb, 1);
if (try_val_to_str(pdut, vals_message_type) == NULL)
return FALSE;
if ((tvb_get_guint8(tvb, 2) != MM_TID_HDR) &&
(tvb_get_guint8(tvb, 2) != MM_VERSION_HDR))
return FALSE;
dissect_mmse_standalone(tvb, pinfo, tree, data);
return TRUE;
}
static int
dissect_mmse_standalone(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
guint8 pdut;
const char *message_type;
DebugLog(("dissect_mmse_standalone() - START (Packet %u)\n",
pinfo->num));
pdut = tvb_get_guint8(tvb, 1);
message_type = val_to_str(pdut, vals_message_type, "Unknown type %u");
col_set_str(pinfo->cinfo, COL_PROTOCOL, "MMSE");
col_add_fstr(pinfo->cinfo, COL_INFO, "MMS %s", message_type);
dissect_mmse(tvb, pinfo, tree, pdut, message_type);
return tvb_captured_length(tvb);
}
static int
dissect_mmse_encapsulated(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
guint8 pdut;
const char *message_type;
DebugLog(("dissect_mmse_encapsulated() - START (Packet %u)\n",
pinfo->num));
pdut = tvb_get_guint8(tvb, 1);
message_type = val_to_str(pdut, vals_message_type, "Unknown type %u");
col_append_sep_fstr(pinfo->cinfo, COL_INFO, " ", "(MMS %s)",
message_type);
dissect_mmse(tvb, pinfo, tree, pdut, message_type);
return tvb_captured_length(tvb);
}
static void
dissect_mmse(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint8 pdut,
const char *message_type)
{
guint offset;
guint8 field = 0;
const char *strval;
guint length;
guint count;
guint8 version = 0x80;
proto_item *ti = NULL;
proto_tree *mmse_tree = NULL;
DebugLog(("dissect_mmse() - START (Packet %u)\n", pinfo->num));
if (tree) {
DebugLog(("tree != NULL\n"));
ti = proto_tree_add_item(tree, proto_mmse, tvb, 0, -1, ENC_NA);
proto_item_append_text(ti, ", Type: %s", message_type);
mmse_tree = proto_item_add_subtree(ti, ett_mmse);
proto_tree_add_uint(mmse_tree, hf_mmse_message_type, tvb, 0, 2, pdut);
}
offset = 2;
if (tree || pdu_has_content(pdut)) {
while ((offset < tvb_reported_length(tvb)) &&
(field = tvb_get_guint8(tvb, offset++)) != MM_CTYPE_HDR)
{
DebugLog(("\tField = 0x%02X (offset = %u): %s\n",
field, offset,
val_to_str(field, vals_mm_header_names,
"Unknown MMS header 0x%02X")));
switch (field)
{
case MM_TID_HDR:
length = get_text_string(tvb, offset, &strval);
if (tree) {
proto_tree_add_string(mmse_tree, hf_mmse_transaction_id,
tvb, offset - 1, length + 1,strval);
}
offset += length;
break;
case MM_VERSION_HDR:
version = tvb_get_guint8(tvb, offset++);
if (tree) {
guint8 major, minor;
char *vers_string;
major = (version & 0x70) >> 4;
minor = version & 0x0F;
if (minor == 0x0F)
vers_string = wmem_strdup_printf(wmem_packet_scope(), "%u", major);
else
vers_string = wmem_strdup_printf(wmem_packet_scope(), "%u.%u", major, minor);
proto_tree_add_string(mmse_tree, hf_mmse_mms_version,
tvb, offset - 2, 2, vers_string);
}
break;
case MM_BCC_HDR:
length = get_encoded_strval(tvb, offset, &strval, pinfo);
if (tree) {
proto_tree_add_string(mmse_tree, hf_mmse_bcc, tvb,
offset - 1, length + 1, strval);
}
offset += length;
break;
case MM_CC_HDR:
length = get_encoded_strval(tvb, offset, &strval, pinfo);
if (tree) {
proto_tree_add_string(mmse_tree, hf_mmse_cc, tvb,
offset - 1, length + 1, strval);
}
offset += length;
break;
case MM_CLOCATION_HDR:
if (pdut == PDU_M_MBOX_DELETE_CONF) {
length = tvb_get_guint8(tvb, offset);
if (length == 0x1F) {
guint length_len = 0;
length = tvb_get_guintvar(tvb, offset + 1,
&length_len, pinfo, &ei_mmse_oversized_uintvar);
length += 1 + length_len;
} else {
length += 1;
}
proto_tree_add_string(mmse_tree,
hf_mmse_content_location,
tvb, offset - 1, length + 1,
"<Undecoded value for m-mbox-delete-conf>");
} else {
length = get_text_string(tvb, offset, &strval);
if (tree) {
proto_tree_add_string(mmse_tree,
hf_mmse_content_location,
tvb, offset - 1, length + 1, strval);
}
}
offset += length;
break;
case MM_DATE_HDR:
{
guint tval;
nstime_t tmptime;
tval = get_long_integer(tvb, offset, &count);
tmptime.secs = tval;
tmptime.nsecs = 0;
proto_tree_add_time(mmse_tree, hf_mmse_date, tvb,
offset - 1, count + 1, &tmptime);
}
offset += count;
break;
case MM_DREPORT_HDR:
field = tvb_get_guint8(tvb, offset++);
if (tree) {
proto_tree_add_uint(mmse_tree,
hf_mmse_delivery_report,
tvb, offset - 2, 2, field);
}
break;
case MM_DTIME_HDR:
length = get_value_length(tvb, offset, &count, pinfo);
field = tvb_get_guint8(tvb, offset + count);
if (tree) {
guint tval;
nstime_t tmptime;
guint cnt;
tval = get_long_integer(tvb, offset + count + 1, &cnt);
tmptime.secs = tval;
tmptime.nsecs = 0;
if (field == 0x80)
proto_tree_add_time(mmse_tree,
hf_mmse_delivery_time_abs,
tvb, offset - 1,
length + count + 1, &tmptime);
else
proto_tree_add_time(mmse_tree,
hf_mmse_delivery_time_rel,
tvb, offset - 1,
length + count + 1, &tmptime);
}
offset += length + count;
break;
case MM_EXPIRY_HDR:
length = get_value_length(tvb, offset, &count, pinfo);
field = tvb_get_guint8(tvb, offset + count);
if (tree) {
guint tval;
nstime_t tmptime;
guint cnt;
tval = get_long_integer(tvb, offset + count + 1, &cnt);
tmptime.secs = tval;
tmptime.nsecs = 0;
if (field == 0x80)
proto_tree_add_time(mmse_tree, hf_mmse_expiry_abs,
tvb, offset - 1,
length + count + 1, &tmptime);
else
proto_tree_add_time(mmse_tree, hf_mmse_expiry_rel,
tvb, offset - 1,
length + count + 1, &tmptime);
}
offset += length + count;
break;
case MM_FROM_HDR:
length = get_value_length(tvb, offset, &count, pinfo);
if (tree) {
field = tvb_get_guint8(tvb, offset + count);
if (field == 0x81) {
proto_tree_add_string(mmse_tree, hf_mmse_from, tvb,
offset-1, length + count + 1,
"<insert address>");
} else {
(void) get_encoded_strval(tvb, offset + count + 1,
&strval, pinfo);
proto_tree_add_string(mmse_tree, hf_mmse_from, tvb,
offset-1, length + count + 1, strval);
}
}
offset += length + count;
break;
case MM_MCLASS_HDR:
field = tvb_get_guint8(tvb, offset);
if (field & 0x80) {
offset++;
if (tree) {
proto_tree_add_uint(mmse_tree,
hf_mmse_message_class_id,
tvb, offset - 2, 2, field);
}
} else {
length = get_text_string(tvb, offset, &strval);
if (tree) {
proto_tree_add_string(mmse_tree,
hf_mmse_message_class_str,
tvb, offset - 1, length + 1,
strval);
}
offset += length;
}
break;
case MM_MID_HDR:
length = get_text_string(tvb, offset, &strval);
if (tree) {
proto_tree_add_string(mmse_tree, hf_mmse_message_id,
tvb, offset - 1, length + 1, strval);
}
offset += length;
break;
case MM_MSIZE_HDR:
length = get_long_integer(tvb, offset, &count);
if (tree) {
proto_tree_add_uint(mmse_tree, hf_mmse_message_size,
tvb, offset - 1, count + 1, length);
}
offset += count;
break;
case MM_PRIORITY_HDR:
field = tvb_get_guint8(tvb, offset++);
if (tree) {
proto_tree_add_uint(mmse_tree, hf_mmse_priority, tvb,
offset - 2, 2, field);
}
break;
case MM_RREPLY_HDR:
field = tvb_get_guint8(tvb, offset++);
if (tree) {
if (version == 0x80) {
proto_tree_add_uint(mmse_tree, hf_mmse_read_reply,
tvb, offset - 2, 2, field);
} else {
proto_tree_add_uint(mmse_tree, hf_mmse_read_report,
tvb, offset - 2, 2, field);
}
}
break;
case MM_RALLOWED_HDR:
field = tvb_get_guint8(tvb, offset++);
if (tree) {
proto_tree_add_uint(mmse_tree, hf_mmse_report_allowed,
tvb, offset - 2, 2, field);
}
break;
case MM_RSTATUS_HDR:
field = tvb_get_guint8(tvb, offset++);
if (tree) {
proto_tree_add_uint(mmse_tree, hf_mmse_response_status,
tvb, offset - 2, 2, field);
}
break;
case MM_RTEXT_HDR:
if (pdut == PDU_M_MBOX_DELETE_CONF) {
length = tvb_get_guint8(tvb, offset);
if (length == 0x1F) {
guint length_len = 0;
length = tvb_get_guintvar(tvb, offset + 1,
&length_len, pinfo, &ei_mmse_oversized_uintvar);
length += 1 + length_len;
} else {
length += 1;
}
if (tree) {
proto_tree_add_string(mmse_tree,
hf_mmse_content_location,
tvb, offset - 1, length + 1,
"<Undecoded value for m-mbox-delete-conf>");
}
} else {
length = get_encoded_strval(tvb, offset, &strval, pinfo);
if (tree) {
proto_tree_add_string(mmse_tree,
hf_mmse_response_text, tvb, offset - 1,
length + 1, strval);
}
}
offset += length;
break;
case MM_SVISIBILITY_HDR:
field = tvb_get_guint8(tvb, offset++);
if (tree) {
proto_tree_add_uint(mmse_tree,hf_mmse_sender_visibility,
tvb, offset - 2, 2, field);
}
break;
case MM_STATUS_HDR:
field = tvb_get_guint8(tvb, offset++);
if (tree) {
proto_tree_add_uint(mmse_tree, hf_mmse_status, tvb,
offset - 2, 2, field);
}
break;
case MM_SUBJECT_HDR:
length = get_encoded_strval(tvb, offset, &strval, pinfo);
if (tree) {
proto_tree_add_string(mmse_tree, hf_mmse_subject, tvb,
offset - 1, length + 1, strval);
}
offset += length;
break;
case MM_TO_HDR:
length = get_encoded_strval(tvb, offset, &strval, pinfo);
if (tree) {
proto_tree_add_string(mmse_tree, hf_mmse_to, tvb,
offset - 1, length + 1, strval);
}
offset += length;
break;
case MM_RETRIEVE_STATUS_HDR:
field = tvb_get_guint8(tvb, offset++);
if (tree) {
proto_tree_add_uint(mmse_tree, hf_mmse_retrieve_status,
tvb, offset - 2, 2, field);
}
break;
case MM_RETRIEVE_TEXT_HDR:
if (pdut == PDU_M_MBOX_DELETE_CONF) {
length = tvb_get_guint8(tvb, offset);
if (length == 0x1F) {
guint length_len = 0;
length = tvb_get_guintvar(tvb, offset + 1,
&length_len, pinfo, &ei_mmse_oversized_uintvar);
length += 1 + length_len;
} else {
length += 1;
}
if (tree) {
proto_tree_add_string(mmse_tree,
hf_mmse_content_location,
tvb, offset - 1, length + 1,
"<Undecoded value for m-mbox-delete-conf>");
}
} else {
length = get_encoded_strval(tvb, offset, &strval, pinfo);
if (tree) {
proto_tree_add_string(mmse_tree,
hf_mmse_retrieve_text, tvb, offset - 1,
length + 1, strval);
}
}
offset += length;
break;
case MM_READ_STATUS_HDR:
field = tvb_get_guint8(tvb, offset++);
if (tree) {
proto_tree_add_uint(mmse_tree, hf_mmse_read_status,
tvb, offset - 2, 2, field);
}
break;
case MM_REPLY_CHARGING_HDR:
field = tvb_get_guint8(tvb, offset++);
if (tree) {
proto_tree_add_uint(mmse_tree, hf_mmse_reply_charging,
tvb, offset - 2, 2, field);
}
break;
case MM_REPLY_CHARGING_DEADLINE_HDR:
length = get_value_length(tvb, offset, &count, pinfo);
field = tvb_get_guint8(tvb, offset + count);
if (tree) {
guint tval;
nstime_t tmptime;
guint cnt;
tval = get_long_integer(tvb, offset + count + 1, &cnt);
tmptime.secs = tval;
tmptime.nsecs = 0;
if (field == 0x80)
proto_tree_add_time(mmse_tree, hf_mmse_reply_charging_deadline_abs,
tvb, offset - 1,
length + count + 1, &tmptime);
else
proto_tree_add_time(mmse_tree, hf_mmse_reply_charging_deadline_rel,
tvb, offset - 1,
length + count + 1, &tmptime);
}
offset += length + count;
break;
case MM_REPLY_CHARGING_ID_HDR:
length = get_text_string(tvb, offset, &strval);
if (tree) {
proto_tree_add_string(mmse_tree,
hf_mmse_reply_charging_id,
tvb, offset - 1, length + 1, strval);
}
offset += length;
break;
case MM_REPLY_CHARGING_SIZE_HDR:
length = get_long_integer(tvb, offset, &count);
if (tree) {
proto_tree_add_uint(mmse_tree,
hf_mmse_reply_charging_size,
tvb, offset - 1, count + 1, length);
}
offset += count;
break;
case MM_PREV_SENT_BY_HDR:
length = get_value_length(tvb, offset, &count, pinfo);
if (tree) {
guint32 fwd_count, count1, count2;
proto_tree *subtree = NULL;
proto_item *tii = NULL;
fwd_count = get_integer_value(tvb, offset + count,
&count1);
count2 = get_encoded_strval(tvb,
offset + count + count1, &strval, pinfo);
tii = proto_tree_add_string_format(mmse_tree,
hf_mmse_prev_sent_by,
tvb, offset - 1, 1 + count + length,
strval, "%s (Forwarded-count=%u)",
format_text(wmem_packet_scope(), strval, strlen(strval)),
fwd_count);
subtree = proto_item_add_subtree(tii,
ett_mmse_hdr_details);
proto_tree_add_uint(subtree,
hf_mmse_prev_sent_by_fwd_count,
tvb, offset + count, count1, fwd_count);
proto_tree_add_string(subtree,
hf_mmse_prev_sent_by_address,
tvb, offset + count + count1, count2, strval);
}
offset += length + count;
break;
case MM_PREV_SENT_DATE_HDR:
length = get_value_length(tvb, offset, &count, pinfo);
if (tree) {
guint32 fwd_count, count1, count2;
guint tval;
nstime_t tmptime;
proto_tree *subtree = NULL;
proto_item *tii = NULL;
fwd_count = get_integer_value(tvb, offset + count,
&count1);
tval = get_long_integer(tvb, offset + count + count1,
&count2);
tmptime.secs = tval;
tmptime.nsecs = 0;
strval = abs_time_to_str(wmem_packet_scope(), &tmptime, ABSOLUTE_TIME_LOCAL,
TRUE);
tii = proto_tree_add_string_format(mmse_tree,
hf_mmse_prev_sent_date,
tvb, offset - 1, 1 + count + length,
strval, "%s (Forwarded-count=%u)",
format_text(wmem_packet_scope(), strval, strlen(strval)),
fwd_count);
subtree = proto_item_add_subtree(tii,
ett_mmse_hdr_details);
proto_tree_add_uint(subtree,
hf_mmse_prev_sent_date_fwd_count,
tvb, offset + count, count1, fwd_count);
proto_tree_add_string(subtree,
hf_mmse_prev_sent_date_date,
tvb, offset + count + count1, count2, strval);
}
offset += length + count;
break;
default:
if (field & 0x80) {
guint8 peek = tvb_get_guint8(tvb, offset);
const char *hdr_name = val_to_str(field, vals_mm_header_names,
"Unknown field (0x%02x)");
const char *str;
DebugLog(("\t\tUndecoded well-known header: %s\n",
hdr_name));
if (peek & 0x80) {
length = 1;
if (tree) {
proto_tree_add_uint_format(mmse_tree, hf_mmse_header_uint, tvb, offset - 1,
length + 1, peek,
"%s: <Well-known value 0x%02x>"
" (not decoded)",
hdr_name, peek);
}
} else if ((peek == 0) || (peek >= 0x20)) {
length = get_text_string(tvb, offset, &strval);
if (tree) {
str = format_text(wmem_packet_scope(), strval, strlen(strval));
proto_tree_add_string_format(mmse_tree, hf_mmse_header_string, tvb, offset - 1,
length + 1, str, "%s: %s (Not decoded)", hdr_name, str);
}
} else {
if (peek == 0x1F) {
guint length_len = 0;
length = 1 + tvb_get_guintvar(tvb, offset + 1,
&length_len, pinfo, &ei_mmse_oversized_uintvar);
length += length_len;
} else {
length = 1 + tvb_get_guint8(tvb, offset);
}
if (tree) {
proto_tree_add_bytes_format(mmse_tree, hf_mmse_header_bytes, tvb, offset - 1,
length + 1, NULL, "%s: "
"<Value in general form> (not decoded)",
hdr_name);
}
}
offset += length;
} else {
guint length2;
const char *strval2;
--offset;
length = get_text_string(tvb, offset, &strval);
DebugLog(("\t\tUndecoded literal header: %s\n",
strval));
length2= get_text_string(tvb, offset+length, &strval2);
if (tree) {
proto_tree_add_string_format(mmse_tree,
hf_mmse_ffheader, tvb, offset,
length + length2,
tvb_get_string_enc(wmem_packet_scope(), tvb, offset,
length + length2, ENC_ASCII),
"%s: %s",
format_text(wmem_packet_scope(), strval, strlen(strval)),
format_text(wmem_packet_scope(), strval2, strlen(strval2)));
}
offset += length + length2;
}
break;
}
DebugLog(("\tEnd(case)\n"));
}
DebugLog(("\tEnd(switch)\n"));
if (field == MM_CTYPE_HDR) {
tvbuff_t *tmp_tvb;
guint type;
const char *type_str;
DebugLog(("Content-Type: [from WSP dissector]\n"));
DebugLog(("Calling add_content_type() in WSP dissector\n"));
offset = add_content_type(mmse_tree, pinfo, tvb, offset, &type, &type_str);
DebugLog(("Generating new TVB subset (offset = %u)\n", offset));
tmp_tvb = tvb_new_subset_remaining(tvb, offset);
DebugLog(("Add POST data\n"));
add_post_data(mmse_tree, tmp_tvb, type, type_str, pinfo);
DebugLog(("Done!\n"));
}
} else {
DebugLog(("tree == NULL and PDU has no potential content\n"));
}
DebugLog(("dissect_mmse() - END\n"));
}
void
proto_register_mmse(void)
{
static hf_register_info hf[] = {
{ &hf_mmse_message_type,
{ "X-Mms-Message-Type", "mmse.message_type",
FT_UINT8, BASE_HEX, VALS(vals_message_type), 0x00,
"Specifies the transaction type. Effectively defines PDU.",
HFILL
}
},
{ &hf_mmse_transaction_id,
{ "X-Mms-Transaction-ID", "mmse.transaction_id",
FT_STRING, BASE_NONE, NULL, 0x00,
"A unique identifier for this transaction. Identifies request and corresponding response only.",
HFILL
}
},
{ &hf_mmse_mms_version,
{ "X-Mms-MMS-Version", "mmse.mms_version",
FT_STRING, BASE_NONE, NULL, 0x00,
"Version of the protocol used.",
HFILL
}
},
{ &hf_mmse_bcc,
{ "Bcc", "mmse.bcc",
FT_STRING, BASE_NONE, NULL, 0x00,
"Blind carbon copy.",
HFILL
}
},
{ &hf_mmse_cc,
{ "Cc", "mmse.cc",
FT_STRING, BASE_NONE, NULL, 0x00,
"Carbon copy.",
HFILL
}
},
{ &hf_mmse_content_location,
{ "X-Mms-Content-Location", "mmse.content_location",
FT_STRING, BASE_NONE, NULL, 0x00,
"Defines the location of the message.",
HFILL
}
},
{ &hf_mmse_date,
{ "Date", "mmse.date",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0x00,
"Arrival timestamp of the message or sending timestamp.",
HFILL
}
},
{ &hf_mmse_delivery_report,
{ "X-Mms-Delivery-Report", "mmse.delivery_report",
FT_UINT8, BASE_HEX, VALS(vals_yes_no), 0x00,
"Whether a report of message delivery is wanted or not.",
HFILL
}
},
{ &hf_mmse_delivery_time_abs,
{ "X-Mms-Delivery-Time", "mmse.delivery_time.abs",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0x00,
"The time at which message delivery is desired.",
HFILL
}
},
{ &hf_mmse_delivery_time_rel,
{ "X-Mms-Delivery-Time", "mmse.delivery_time.rel",
FT_RELATIVE_TIME, BASE_NONE, NULL, 0x00,
"The desired message delivery delay.",
HFILL
}
},
{ &hf_mmse_expiry_abs,
{ "X-Mms-Expiry", "mmse.expiry.abs",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0x00,
"Time when message expires and need not be delivered anymore.",
HFILL
}
},
{ &hf_mmse_expiry_rel,
{ "X-Mms-Expiry", "mmse.expiry.rel",
FT_RELATIVE_TIME, BASE_NONE, NULL, 0x00,
"Delay before message expires and need not be delivered anymore.",
HFILL
}
},
{ &hf_mmse_from,
{ "From", "mmse.from",
FT_STRING, BASE_NONE, NULL, 0x00,
"Address of the message sender.",
HFILL
}
},
{ &hf_mmse_message_class_id,
{ "X-Mms-Message-Class", "mmse.message_class.id",
FT_UINT8, BASE_HEX, VALS(vals_message_class), 0x00,
"Of what category is the message.",
HFILL
}
},
{ &hf_mmse_message_class_str,
{ "X-Mms-Message-Class", "mmse.message_class.str",
FT_STRING, BASE_NONE, NULL, 0x00,
"Of what category is the message.",
HFILL
}
},
{ &hf_mmse_message_id,
{ "Message-Id", "mmse.message_id",
FT_STRING, BASE_NONE, NULL, 0x00,
"Unique identification of the message.",
HFILL
}
},
{ &hf_mmse_message_size,
{ "X-Mms-Message-Size", "mmse.message_size",
FT_UINT32, BASE_DEC, NULL, 0x00,
"The size of the message in octets.",
HFILL
}
},
{ &hf_mmse_priority,
{ "X-Mms-Priority", "mmse.priority",
FT_UINT8, BASE_HEX, VALS(vals_priority), 0x00,
"Priority of the message.",
HFILL
}
},
{ &hf_mmse_read_reply,
{ "X-Mms-Read-Reply", "mmse.read_reply",
FT_UINT8, BASE_HEX, VALS(vals_yes_no), 0x00,
"Whether a read report from every recipient is wanted.",
HFILL
}
},
{ &hf_mmse_read_report,
{ "X-Mms-Read-Report", "mmse.read_report",
FT_UINT8, BASE_HEX, VALS(vals_yes_no), 0x00,
"Whether a read report from every recipient is wanted.",
HFILL
}
},
{ &hf_mmse_report_allowed,
{ "X-Mms-Report-Allowed", "mmse.report_allowed",
FT_UINT8, BASE_HEX, VALS(vals_yes_no), 0x00,
"Sending of delivery report allowed or not.",
HFILL
}
},
{ &hf_mmse_response_status,
{ "Response-Status", "mmse.response_status",
FT_UINT8, BASE_HEX, VALS(vals_response_status), 0x00,
"MMS-specific result of a message submission or retrieval.",
HFILL
}
},
{ &hf_mmse_response_text,
{ "Response-Text", "mmse.response_text",
FT_STRING, BASE_NONE, NULL, 0x00,
"Additional information on MMS-specific result.",
HFILL
}
},
{ &hf_mmse_sender_visibility,
{ "Sender-Visibility", "mmse.sender_visibility",
FT_UINT8, BASE_HEX, VALS(vals_sender_visibility), 0x00,
"Disclose sender identity to receiver or not.",
HFILL
}
},
{ &hf_mmse_status,
{ "Status", "mmse.status",
FT_UINT8, BASE_HEX, VALS(vals_message_status), 0x00,
"Current status of the message.",
HFILL
}
},
{ &hf_mmse_subject,
{ "Subject", "mmse.subject",
FT_STRING, BASE_NONE, NULL, 0x00,
"Subject of the message.",
HFILL
}
},
{ &hf_mmse_to,
{ "To", "mmse.to",
FT_STRING, BASE_NONE, NULL, 0x00,
"Recipient(s) of the message.",
HFILL
}
},
#if 0
{ &hf_mmse_content_type,
{ "Data", "mmse.content_type",
FT_NONE, BASE_NONE, NULL, 0x00,
"Media content of the message.",
HFILL
}
},
#endif
{ &hf_mmse_ffheader,
{ "Free format (not encoded) header", "mmse.ffheader",
FT_STRING, BASE_NONE, NULL, 0x00,
"Application header without corresponding encoding.",
HFILL
}
},
{ &hf_mmse_retrieve_status,
{ "X-Mms-Retrieve-Status", "mmse.retrieve_status",
FT_UINT8, BASE_HEX, VALS(vals_retrieve_status), 0x00,
"MMS-specific result of a message retrieval.",
HFILL
}
},
{ &hf_mmse_retrieve_text,
{ "X-Mms-Retrieve-Text", "mmse.retrieve_text",
FT_STRING, BASE_NONE, NULL, 0x00,
"Status text of a MMS message retrieval.",
HFILL
}
},
{ &hf_mmse_read_status,
{ "X-Mms-Read-Status", "mmse.read_status",
FT_UINT8, BASE_HEX, VALS(vals_read_status), 0x00,
"MMS-specific message read status.",
HFILL
}
},
{ &hf_mmse_reply_charging,
{ "X-Mms-Reply-Charging", "mmse.reply_charging",
FT_UINT8, BASE_HEX, VALS(vals_reply_charging), 0x00,
"MMS-specific message reply charging method.",
HFILL
}
},
{ &hf_mmse_reply_charging_deadline_abs,
{ "X-Mms-Reply-Charging-Deadline", "mmse.reply_charging_deadline.abs",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0x00,
"The latest time of the recipient(s) to submit the Reply MM.",
HFILL
}
},
{ &hf_mmse_reply_charging_deadline_rel,
{ "X-Mms-Reply-Charging-Deadline", "mmse.reply_charging_deadline.rel",
FT_RELATIVE_TIME, BASE_NONE, NULL, 0x00,
"The latest time of the recipient(s) to submit the Reply MM.",
HFILL
}
},
{ &hf_mmse_reply_charging_id,
{ "X-Mms-Reply-Charging-Id", "mmse.reply_charging_id",
FT_STRING, BASE_NONE, NULL, 0x00,
"Unique reply charging identification of the message.",
HFILL
}
},
{ &hf_mmse_reply_charging_size,
{ "X-Mms-Reply-Charging-Size", "mmse.reply_charging_size",
FT_UINT32, BASE_DEC, NULL, 0x00,
"The size of the reply charging in octets.",
HFILL
}
},
{ &hf_mmse_prev_sent_by,
{ "X-Mms-Previously-Sent-By", "mmse.previously_sent_by",
FT_STRING, BASE_NONE, NULL, 0x00,
"Indicates that the MM has been previously sent by this user.",
HFILL
}
},
{ &hf_mmse_prev_sent_by_fwd_count,
{ "Forward Count", "mmse.previously_sent_by.forward_count",
FT_UINT32, BASE_DEC, NULL, 0x00,
"Forward count of the previously sent MM.",
HFILL
}
},
{ &hf_mmse_prev_sent_by_address,
{ "Address", "mmse.previously_sent_by.address",
FT_STRING, BASE_NONE, NULL, 0x00,
"Indicates from whom the MM has been previously sent.",
HFILL
}
},
{ &hf_mmse_prev_sent_date,
{ "X-Mms-Previously-Sent-Date", "mmse.previously_sent_date",
FT_STRING, BASE_NONE, NULL, 0x00,
"Indicates the date that the MM has been previously sent.",
HFILL
}
},
{ &hf_mmse_prev_sent_date_fwd_count,
{ "Forward Count", "mmse.previously_sent_date.forward_count",
FT_UINT32, BASE_DEC, NULL, 0x00,
"Forward count of the previously sent MM.",
HFILL
}
},
{ &hf_mmse_prev_sent_date_date,
{ "Date", "mmse.previously_sent_date.date",
FT_STRING, BASE_NONE, NULL, 0x00,
"Time when the MM has been previously sent.",
HFILL
}
},
{ &hf_mmse_header_uint,
{ "Header Uint Value", "mmse.header.uint",
FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL
}
},
{ &hf_mmse_header_string,
{ "Header String Value", "mmse.header.string",
FT_STRING, BASE_NONE, NULL, 0x00, NULL, HFILL
}
},
{ &hf_mmse_header_bytes,
{ "Header Byte array", "mmse.header.bytes",
FT_BYTES, BASE_NONE, NULL, 0x00, NULL, HFILL
}
},
};
static gint *ett[] = {
&ett_mmse,
&ett_mmse_hdr_details,
};
static ei_register_info ei[] = {
{ &ei_mmse_oversized_uintvar, { "mmse.oversized_uintvar", PI_MALFORMED, PI_ERROR, "Uintvar is oversized", EXPFILL }}
};
expert_module_t* expert_mmse;
proto_mmse = proto_register_protocol("MMS Message Encapsulation",
"MMSE", "mmse");
proto_register_field_array(proto_mmse, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_mmse = expert_register_protocol(proto_mmse);
expert_register_field_array(expert_mmse, ei, array_length(ei));
}
void
proto_reg_handoff_mmse(void)
{
dissector_handle_t mmse_standalone_handle;
dissector_handle_t mmse_encapsulated_handle;
heur_dissector_add("wsp", dissect_mmse_heur, "MMS Message Encapsulation over WSP", "mmse_wsp", proto_mmse, HEURISTIC_ENABLE);
mmse_standalone_handle = create_dissector_handle(
dissect_mmse_standalone, proto_mmse);
mmse_encapsulated_handle = create_dissector_handle(
dissect_mmse_encapsulated, proto_mmse);
dissector_add_string("media_type",
"application/vnd.wap.mms-message", mmse_standalone_handle);
dissector_add_string("multipart_media_type",
"application/vnd.wap.mms-message", mmse_encapsulated_handle);
}
