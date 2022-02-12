static void
call_pres_dissector(tvbuff_t *tvb, int offset, guint16 param_len,
packet_info *pinfo, proto_tree *tree,
proto_tree *param_tree,
struct SESSION_DATA_STRUCTURE *session)
{
void *saved_private_data;
if(!pres_handle)
{
if (tree)
{
proto_tree_add_text(param_tree, tvb, offset, param_len,
"User data");
}
}
else
{
tvbuff_t *next_tvb;
next_tvb = tvb_new_subset(tvb, offset, param_len, param_len);
saved_private_data = pinfo->private_data;
pinfo->private_data = session;
TRY
{
call_dissector(pres_handle, next_tvb, pinfo, tree);
}
CATCH_ALL
{
show_exception(tvb, pinfo, tree, EXCEPT_CODE, GET_MESSAGE);
}
ENDTRY;
pinfo->private_data = saved_private_data;
}
}
static int
get_item_len(tvbuff_t *tvb, int offset, int *len_len)
{
guint16 len;
len = tvb_get_guint8(tvb, offset);
if(len == TWO_BYTE_LEN)
{
len = tvb_get_ntohs(tvb, offset+1);
*len_len = 3;
}
else
*len_len = 1;
return len;
}
static gboolean
dissect_parameter(tvbuff_t *tvb, int offset, proto_tree *tree,
proto_tree *param_tree, packet_info *pinfo, guint8 param_type,
guint16 param_len, guint8 *enclosure_item_flags,
struct SESSION_DATA_STRUCTURE *session)
{
gboolean has_user_information = TRUE;
guint16 flags;
proto_item *tf;
proto_tree *flags_tree;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
switch (param_type)
{
case Called_SS_user_Reference:
if (param_len == 0)
break;
if (tree)
{
proto_tree_add_item(param_tree,
hf_called_ss_user_reference,
tvb, offset, param_len, ENC_NA);
}
break;
case Calling_SS_user_Reference:
if (param_len == 0)
break;
if (tree)
{
proto_tree_add_item(param_tree,
hf_calling_ss_user_reference,
tvb, offset, param_len, ENC_NA);
}
break;
case Common_Reference:
if (param_len == 0)
break;
if (tree)
{
proto_tree_add_item(param_tree,
hf_common_reference,
tvb, offset, param_len, ENC_NA);
}
break;
case Additional_Reference_Information:
if (param_len == 0)
break;
if (tree)
{
proto_tree_add_item(param_tree,
hf_additional_reference_information,
tvb, offset, param_len, ENC_NA);
}
break;
case Token_Item:
if (param_len != 1)
{
proto_tree_add_text(param_tree, tvb, offset,
param_len, "Length is %u, should be 1",
param_len);
break;
}
if (tree)
{
flags = tvb_get_guint8(tvb, offset);
tf = proto_tree_add_uint(param_tree,
hf_token_item_options_flags, tvb, offset, 1,
flags);
flags_tree = proto_item_add_subtree(tf,
ett_token_item_flags);
proto_tree_add_boolean(flags_tree, hf_release_token,
tvb, offset, 1, flags);
proto_tree_add_boolean(flags_tree,
hf_major_activity_token, tvb, offset, 1, flags);
proto_tree_add_boolean(flags_tree,
hf_synchronize_minor_token, tvb, offset, 1, flags);
proto_tree_add_boolean(flags_tree, hf_data_token, tvb,
offset, 1, flags);
}
break;
case Transport_Disconnect:
if (param_len != 1)
{
proto_tree_add_text(param_tree, tvb, offset,
param_len, "Length is %u, should be 1",
param_len);
break;
}
if (tree)
{
guint8 flags8;
flags8 = tvb_get_guint8(tvb, offset);
if(flags8 & transport_connection_is_released )
{
proto_tree_add_text(param_tree, tvb, offset, 1,
"transport connection is released");
}
else
{
proto_tree_add_text(param_tree, tvb, offset, 1,
"transport connection is kept");
}
if(flags8 & user_abort )
{
proto_tree_add_text(param_tree, tvb, offset, 1,
"user abort");
session->abort_type = SESSION_USER_ABORT;
}
else
{
session->abort_type = SESSION_PROVIDER_ABORT;
}
if(flags8 & protocol_error )
{
proto_tree_add_text(param_tree, tvb, offset, 1,
"protocol error");
}
if(flags8 & no_reason )
{
proto_tree_add_text(param_tree, tvb, offset, 1,
"no reason");
}
if(flags8 & implementation_restriction )
{
proto_tree_add_text(param_tree, tvb, offset, 1,
"implementation restriction");
}
}
break;
case Protocol_Options:
if (param_len != 1)
{
proto_tree_add_text(param_tree, tvb, offset,
param_len, "Length is %u, should be 1",
param_len);
break;
}
if (tree)
{
flags = tvb_get_guint8(tvb, offset);
tf = proto_tree_add_uint(param_tree,
hf_connect_protocol_options_flags, tvb, offset, 1,
flags);
flags_tree = proto_item_add_subtree(tf,
ett_connect_protocol_options_flags);
proto_tree_add_boolean(flags_tree,
hf_able_to_receive_extended_concatenated_SPDU,
tvb, offset, 1, flags);
}
break;
case Session_Requirement:
if (param_len != 2)
{
proto_tree_add_text(param_tree, tvb, offset,
param_len, "Length is %u, should be 2",
param_len);
break;
}
if (tree)
{
flags = tvb_get_ntohs(tvb, offset);
tf = proto_tree_add_uint(param_tree,
hf_session_user_req_flags, tvb, offset, 2,
flags);
flags_tree = proto_item_add_subtree(tf,
ett_ses_req_options_flags);
proto_tree_add_boolean(flags_tree,
hf_session_exception_report, tvb, offset, 2, flags);
proto_tree_add_boolean(flags_tree,
hf_data_separation_function_unit, tvb, offset, 2,
flags);
proto_tree_add_boolean(flags_tree,
hf_symmetric_synchronize_function_unit,
tvb, offset, 2, flags);
proto_tree_add_boolean(flags_tree,
hf_typed_data_function_unit, tvb, offset, 2, flags);
proto_tree_add_boolean(flags_tree,
hf_exception_function_unit, tvb, offset, 2, flags);
proto_tree_add_boolean(flags_tree,
hf_capability_function_unit, tvb, offset, 2, flags);
proto_tree_add_boolean(flags_tree,
hf_negotiated_release_function_unit,
tvb, offset, 2, flags);
proto_tree_add_boolean(flags_tree,
hf_activity_management_function_unit,
tvb, offset, 2, flags);
proto_tree_add_boolean(flags_tree,
hf_resynchronize_function_unit, tvb, offset, 2,
flags);
proto_tree_add_boolean(flags_tree,
hf_major_resynchronize_function_unit,
tvb, offset, 2, flags);
proto_tree_add_boolean(flags_tree,
hf_minor_resynchronize_function_unit,
tvb, offset, 2, flags);
proto_tree_add_boolean(flags_tree,
hf_expedited_data_resynchronize_function_unit,
tvb, offset, 2, flags);
proto_tree_add_boolean(flags_tree,
hf_duplex_function_unit, tvb, offset, 2, flags);
proto_tree_add_boolean(flags_tree,
hf_half_duplex_function_unit,
tvb, offset, 2, flags);
}
break;
case TSDU_Maximum_Size:
if (param_len != 4)
{
proto_tree_add_text(param_tree, tvb, offset,
param_len, "Length is %u, should be 4",
param_len);
break;
}
if (tree)
{
proto_tree_add_item(param_tree,
hf_proposed_tsdu_maximum_size_i2r,
tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(param_tree,
hf_proposed_tsdu_maximum_size_r2i,
tvb, offset+2, 2, ENC_BIG_ENDIAN);
}
break;
case Version_Number:
if (param_len != 1)
{
proto_tree_add_text(param_tree, tvb, offset,
param_len, "Length is %u, should be 1",
param_len);
break;
}
if (tree)
{
flags = tvb_get_guint8(tvb, offset);
tf = proto_tree_add_uint(param_tree,
hf_version_number_options_flags, tvb, offset, 1,
flags);
flags_tree = proto_item_add_subtree(tf,
ett_protocol_version_flags);
proto_tree_add_boolean(flags_tree,
hf_protocol_version_2, tvb, offset, 1, flags);
proto_tree_add_boolean(flags_tree,
hf_protocol_version_1, tvb, offset, 1, flags);
}
break;
case Initial_Serial_Number:
if (param_len == 0)
break;
if (tree)
{
proto_tree_add_item(param_tree,
hf_initial_serial_number,
tvb, offset, param_len, ENC_ASCII|ENC_NA);
}
break;
case EnclosureItem:
if (param_len != 1)
{
proto_tree_add_text(param_tree, tvb, offset,
param_len, "Length is %u, should be 1",
param_len);
break;
}
flags = tvb_get_guint8(tvb, offset);
*enclosure_item_flags = (guint8) flags;
if (tree)
{
tf = proto_tree_add_uint(param_tree,
hf_enclosure_item_options_flags, tvb, offset, 1,
flags);
flags_tree = proto_item_add_subtree(tf,
ett_enclosure_item_flags);
proto_tree_add_boolean(flags_tree, hf_end_of_SSDU,
tvb, offset, 1, flags);
proto_tree_add_boolean(flags_tree, hf_beginning_of_SSDU,
tvb, offset, 1, flags);
}
if (flags & END_SPDU) {
if(!(flags & BEGINNING_SPDU)) {
has_user_information = FALSE;
}
}
break;
case Token_Setting_Item:
if (param_len != 1)
{
proto_tree_add_text(param_tree, tvb, offset,
param_len, "Length is %u, should be 1",
param_len);
break;
}
if (tree)
{
proto_tree_add_item(param_tree,
hf_release_token_setting,
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(param_tree,
hf_major_activity_token_setting,
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(param_tree,
hf_synchronize_minor_token_setting,
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(param_tree,
hf_data_token_setting,
tvb, offset, 1, ENC_BIG_ENDIAN);
}
break;
case Activity_Identifier:
if (param_len == 0)
break;
if (tree)
{
proto_tree_add_item(param_tree,
hf_activity_identifier,
tvb, offset, param_len, ENC_NA);
}
break;
case Serial_Number:
if (param_len == 0)
break;
if (tree)
{
proto_tree_add_item(param_tree,
hf_serial_number,
tvb, offset, param_len, ENC_ASCII|ENC_NA);
}
break;
case Reason_Code:
if (param_len < 1)
{
proto_tree_add_text(param_tree, tvb, offset,
param_len, "Length is %u, should be >= 1",
param_len);
break;
}
if (tree)
{
guint8 reason_code;
reason_code = tvb_get_guint8(tvb, offset);
proto_tree_add_text(param_tree, tvb, offset, 1,
"Reason Code: %s",
val_to_str(reason_code, reason_vals, "Unknown (%u)"));
}
offset++;
param_len--;
if (param_len != 0)
{
call_pres_dissector(tvb, offset, param_len,
pinfo, tree, param_tree, session);
}
break;
case Calling_Session_Selector:
if (param_len == 0)
break;
if (tree)
{
proto_tree_add_item(param_tree,
hf_calling_session_selector,
tvb, offset, param_len, ENC_NA);
}
break;
case Called_Session_Selector:
if (param_len == 0)
break;
if (tree)
{
proto_tree_add_item(param_tree,
hf_called_session_selector,
tvb, offset, param_len, ENC_NA);
}
break;
case Second_Serial_Number:
if (param_len == 0)
break;
if (tree)
{
proto_tree_add_item(param_tree,
hf_second_serial_number,
tvb, offset, param_len, ENC_ASCII|ENC_NA);
}
break;
case Second_Initial_Serial_Number:
if (param_len == 0)
break;
if (tree)
{
proto_tree_add_item(param_tree,
hf_second_initial_serial_number,
tvb, offset, param_len, ENC_ASCII|ENC_NA);
}
break;
case Large_Initial_Serial_Number:
if (param_len == 0)
break;
if (tree)
{
proto_tree_add_item(param_tree,
hf_large_initial_serial_number,
tvb, offset, param_len, ENC_ASCII|ENC_NA);
}
break;
case Large_Second_Initial_Serial_Number:
if (param_len == 0)
break;
if (tree)
{
proto_tree_add_item(param_tree,
hf_large_second_initial_serial_number,
tvb, offset, param_len, ENC_ASCII|ENC_NA);
}
break;
default:
break;
}
return has_user_information;
}
static gboolean
dissect_parameter_group(tvbuff_t *tvb, int offset, proto_tree *tree,
proto_tree *pg_tree, packet_info *pinfo, guint16 pg_len,
guint8 *enclosure_item_flags, struct SESSION_DATA_STRUCTURE *session)
{
gboolean has_user_information = TRUE;
proto_item *ti;
proto_tree *param_tree;
guint8 param_type;
const char *param_str;
int len_len;
guint16 param_len;
while(pg_len != 0)
{
param_type = tvb_get_guint8(tvb, offset);
ti = proto_tree_add_text(pg_tree, tvb, offset, -1, "%s",
val_to_str(param_type, param_vals,
"Unknown parameter type (0x%02x)"));
param_tree = proto_item_add_subtree(ti, ett_ses_param);
param_str = val_to_str_const(param_type, param_vals, "Unknown");
proto_tree_add_text(param_tree, tvb, offset, 1,
"Parameter type: %s", param_str);
offset++;
pg_len--;
param_len = get_item_len(tvb, offset, &len_len);
if (len_len > pg_len) {
proto_item_set_len(ti, pg_len + 1);
proto_tree_add_text(param_tree, tvb, offset, pg_len,
"Parameter length doesn't fit in parameter");
return has_user_information;
}
pg_len -= len_len;
if (param_len > pg_len) {
proto_item_set_len(ti, pg_len + 1 + len_len);
proto_tree_add_text(param_tree, tvb, offset, pg_len,
"Parameter length: %u, should be <= %u",
param_len, pg_len);
return has_user_information;
}
proto_item_set_len(ti, 1 + len_len + param_len);
proto_tree_add_text(param_tree, tvb, offset, len_len,
"Parameter length: %u", param_len);
offset += len_len;
if (param_str != NULL)
{
switch(param_type)
{
case Extended_User_Data:
case User_Data:
case Connect_Accept_Item:
case Connection_Identifier:
case Linking_Information:
proto_tree_add_text(param_tree, tvb, offset,
param_len,
"Parameter group inside parameter group");
break;
default:
if (!dissect_parameter(tvb, offset, tree,
param_tree, pinfo, param_type, param_len,
enclosure_item_flags, session))
has_user_information = FALSE;
break;
}
}
offset += param_len;
pg_len -= param_len;
}
return has_user_information;
}
static gboolean
dissect_parameters(tvbuff_t *tvb, int offset, guint16 len, proto_tree *tree,
proto_tree *ses_tree, packet_info *pinfo,
guint8 *enclosure_item_flags, struct SESSION_DATA_STRUCTURE *session)
{
gboolean has_user_information = TRUE;
proto_item *ti;
proto_tree *param_tree;
guint8 param_type;
const char *param_str;
int len_len;
guint16 param_len;
while (len != 0)
{
param_type = tvb_get_guint8(tvb, offset);
ti = proto_tree_add_text(ses_tree, tvb, offset, -1, "%s",
val_to_str(param_type, param_vals,
"Unknown parameter type (0x%02x)"));
param_tree = proto_item_add_subtree(ti, ett_ses_param);
param_str = val_to_str_const(param_type, param_vals, "Unknown");
proto_tree_add_text(param_tree, tvb, offset, 1,
"Parameter type: %s", param_str);
offset++;
len--;
param_len = get_item_len(tvb, offset, &len_len);
if (len_len > len) {
proto_item_set_len(ti, len + 1 );
proto_tree_add_text(param_tree, tvb, offset, len,
"Parameter length doesn't fit in parameter");
return has_user_information;
}
len -= len_len;
if (param_len > len) {
proto_item_set_len(ti, len + 1 + len_len);
proto_tree_add_text(param_tree, tvb, offset, len,
"Parameter length: %u, should be <= %u",
param_len, len);
return has_user_information;
}
proto_item_set_len(ti, 1 + len_len + param_len);
proto_tree_add_text(param_tree, tvb, offset, len_len,
"Parameter length: %u", param_len);
offset += len_len;
if (param_str != NULL)
{
switch(param_type)
{
case Extended_User_Data:
call_pres_dissector(tvb, offset, param_len,
pinfo, tree, param_tree, session);
break;
case User_Data:
call_pres_dissector(tvb, offset, param_len,
pinfo, tree, param_tree, session);
break;
case Connect_Accept_Item:
case Connection_Identifier:
case Linking_Information:
if (!dissect_parameter_group(tvb, offset, tree,
param_tree, pinfo, param_len, enclosure_item_flags, session))
has_user_information = FALSE;
break;
default:
if (!dissect_parameter(tvb, offset, tree,
param_tree, pinfo, param_type, param_len,
enclosure_item_flags, session))
has_user_information = FALSE;
break;
}
}
offset += param_len;
len -= param_len;
}
return has_user_information;
}
static int
dissect_spdu(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree,
gboolean tokens, gboolean connectionless)
{
gboolean has_user_information = FALSE;
guint8 type;
proto_item *ti = NULL;
proto_tree *ses_tree = NULL;
int len_len;
guint16 parameters_len;
tvbuff_t *next_tvb = NULL;
void *save_private_data;
guint32 *pres_ctx_id = NULL;
guint8 enclosure_item_flags = BEGINNING_SPDU|END_SPDU;
struct SESSION_DATA_STRUCTURE session;
type = tvb_get_guint8(tvb, offset);
session.spdu_type = type;
session.abort_type = SESSION_NO_ABORT;
session.ros_op = 0;
session.rtse_reassemble = FALSE;
if(connectionless) {
col_add_str(pinfo->cinfo, COL_INFO,
val_to_str(type, ses_vals, "Unknown SPDU type (0x%02x)"));
if (tree) {
ti = proto_tree_add_item(tree, proto_clses, tvb, offset,
-1, ENC_NA);
ses_tree = proto_item_add_subtree(ti, ett_ses);
proto_tree_add_uint(ses_tree, hf_ses_type, tvb,
offset, 1, type);
}
has_user_information = TRUE;
}
else if (tokens) {
col_add_str(pinfo->cinfo, COL_INFO,
val_to_str(type, ses_category0_vals, "Unknown SPDU type (0x%02x)"));
if (tree) {
ti = proto_tree_add_item(tree, proto_ses, tvb, offset,
-1, ENC_NA);
ses_tree = proto_item_add_subtree(ti, ett_ses);
proto_tree_add_uint(ses_tree, hf_ses_type_0, tvb,
offset, 1, type);
}
} else {
col_add_str(pinfo->cinfo, COL_INFO,
val_to_str(type, ses_vals, "Unknown SPDU type (0x%02x)"));
if (tree) {
ti = proto_tree_add_item(tree, proto_ses, tvb, offset,
-1, ENC_NA);
ses_tree = proto_item_add_subtree(ti, ett_ses);
proto_tree_add_uint(ses_tree, hf_ses_type, tvb,
offset, 1, type);
}
switch (type) {
case SES_DATA_TRANSFER:
case SES_EXPEDITED:
case SES_TYPED_DATA:
has_user_information = TRUE;
break;
case SES_MAJOR_SYNC_POINT:
pres_ctx_id = (guint32 *)p_get_proto_data (pinfo->fd, proto_ses, 0);
if (ses_rtse_reassemble != 0 && !pres_ctx_id) {
pres_ctx_id = se_new(guint32);
*pres_ctx_id = ses_pres_ctx_id;
p_add_proto_data (pinfo->fd, proto_ses, 0, pres_ctx_id);
}
if (pres_ctx_id) {
session.pres_ctx_id = *pres_ctx_id;
session.rtse_reassemble = TRUE;
has_user_information = TRUE;
}
ses_rtse_reassemble = FALSE;
break;
}
}
offset++;
parameters_len = get_item_len(tvb, offset, &len_len);
if (tree)
proto_tree_add_uint(ses_tree, hf_ses_length, tvb, offset,
len_len, parameters_len);
offset += len_len;
if (!dissect_parameters(tvb, offset, parameters_len, tree, ses_tree,
pinfo, &enclosure_item_flags, &session))
has_user_information = FALSE;
offset += parameters_len;
proto_item_set_end(ti, tvb, offset);
if (!ses_desegment || enclosure_item_flags == (BEGINNING_SPDU|END_SPDU)) {
if (has_user_information) {
if (tvb_reported_length_remaining(tvb, offset) > 0 || type == SES_MAJOR_SYNC_POINT) {
next_tvb = tvb_new_subset_remaining(tvb, offset);
}
}
} else {
conversation_t *conversation = NULL;
fragment_data *frag_msg = NULL;
gint fragment_len;
guint32 ses_id = 0;
conversation = find_conversation (pinfo->fd->num,
&pinfo->src, &pinfo->dst, pinfo->ptype,
pinfo->srcport, pinfo->destport, 0);
if (conversation != NULL) {
ses_id = conversation->index;
}
fragment_len = tvb_reported_length_remaining (tvb, offset);
ti = proto_tree_add_item (ses_tree, hf_ses_segment_data, tvb, offset,
fragment_len, ENC_NA);
proto_item_append_text (ti, " (%d byte%s)", fragment_len, plurality (fragment_len, "", "s"));
frag_msg = fragment_add_seq_next (&ses_reassembly_table,
tvb, offset,
pinfo, ses_id, NULL,
fragment_len,
(enclosure_item_flags & END_SPDU) ? FALSE : TRUE);
next_tvb = process_reassembled_data (tvb, offset, pinfo, "Reassembled SES",
frag_msg, &ses_frag_items, NULL,
(enclosure_item_flags & END_SPDU) ? tree : ses_tree);
has_user_information = TRUE;
offset += fragment_len;
}
if (has_user_information && next_tvb) {
if (!pres_handle) {
call_dissector(data_handle, next_tvb, pinfo, tree);
} else {
save_private_data = pinfo->private_data;
pinfo->private_data = &session;
call_dissector(pres_handle, next_tvb, pinfo, tree);
pinfo->private_data = save_private_data;
}
offset = tvb_length(tvb);
if (session.rtse_reassemble && type == SES_DATA_TRANSFER) {
ses_pres_ctx_id = session.pres_ctx_id;
ses_rtse_reassemble = TRUE;
}
}
return offset;
}
static void
dissect_ses(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
int offset = 0;
guint8 type;
gboolean is_clsp = FALSE;
type = tvb_get_guint8(tvb, offset);
if(type == CLSES_UNIT_DATA)
is_clsp = TRUE;
col_set_str(pinfo->cinfo, COL_PROTOCOL, is_clsp ? "CLSES" : "SES");
col_clear(pinfo->cinfo, COL_INFO);
if ((type == SES_PLEASE_TOKENS) || (type == SES_GIVE_TOKENS))
offset = dissect_spdu(tvb, offset, pinfo, tree, TOKENS_SPDU, FALSE);
while (tvb_reported_length_remaining(tvb, offset) > 0)
offset = dissect_spdu(tvb, offset, pinfo, tree, NON_TOKENS_SPDU, is_clsp);
}
static void ses_reassemble_init (void)
{
reassembly_table_init (&ses_reassembly_table,
&addresses_reassembly_table_functions);
}
void
proto_register_ses(void)
{
static hf_register_info hf[] =
{
{
&hf_ses_type,
{
"SPDU Type",
"ses.type",
FT_UINT8,
BASE_DEC,
VALS(ses_vals),
0x0,
NULL, HFILL
}
},
{
&hf_ses_type_0,
{
"SPDU Type",
"ses.type",
FT_UINT8,
BASE_DEC,
VALS(ses_category0_vals),
0x0,
NULL, HFILL
}
},
{
&hf_ses_length,
{
"Length",
"ses.length",
FT_UINT16,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
#if 0
{
&hf_ses_version,
{
"Version",
"ses.version",
FT_UINT8,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
#endif
#if 0
{
&hf_ses_reserved,
{
"Reserved",
"ses.reserved",
FT_UINT8,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
#endif
{
&hf_called_ss_user_reference,
{
"Called SS User Reference",
"ses.called_ss_user_reference",
FT_BYTES, BASE_NONE,
NULL,
0x0,
NULL,
HFILL
}
},
{
&hf_calling_ss_user_reference,
{
"Calling SS User Reference",
"ses.calling_ss_user_reference",
FT_BYTES, BASE_NONE,
NULL,
0x0,
NULL,
HFILL
}
},
{
&hf_common_reference,
{
"Common Reference",
"ses.common_reference",
FT_BYTES, BASE_NONE,
NULL,
0x0,
NULL,
HFILL
}
},
{
&hf_additional_reference_information,
{
"Additional Reference Information",
"ses.additional_reference_information",
FT_BYTES, BASE_NONE,
NULL,
0x0,
NULL,
HFILL
}
},
{
&hf_release_token,
{
"release token",
"ses.release_token",
FT_BOOLEAN, 8,
NULL,
RELEASE_TOKEN,
NULL,
HFILL
}
},
{
&hf_major_activity_token,
{
"major/activity token",
"ses.major.token",
FT_BOOLEAN, 8,
NULL,
MAJOR_ACTIVITY_TOKEN,
NULL,
HFILL
}
},
{
&hf_synchronize_minor_token,
{
"synchronize minor token",
"ses.synchronize_token",
FT_BOOLEAN, 8,
NULL,
SYNCHRONIZE_MINOR_TOKEN,
NULL,
HFILL
}
},
{
&hf_data_token,
{
"data token",
"ses.data_token",
FT_BOOLEAN, 8,
NULL,
DATA_TOKEN,
"data token",
HFILL
}
},
{
&hf_able_to_receive_extended_concatenated_SPDU,
{
"Able to receive extended concatenated SPDU",
"ses.connect.f1",
FT_BOOLEAN, 8,
NULL,
SES_EXT_CONT,
NULL,
HFILL
}
},
{
&hf_session_user_req_flags,
{
"Flags",
"ses.req.flags",
FT_UINT16,
BASE_HEX,
NULL,
0x0,
NULL,
HFILL
}
},
{
&hf_session_exception_report,
{
"Session exception report",
"ses.exception_report.",
FT_BOOLEAN, 16,
NULL,
SES_EXCEPTION_REPORT,
NULL,
HFILL
}
},
{
&hf_data_separation_function_unit,
{
"Data separation function unit",
"ses.data_sep",
FT_BOOLEAN, 16,
NULL,
DATA_SEPARATION_FUNCTION_UNIT,
NULL,
HFILL
}
},
{
&hf_symmetric_synchronize_function_unit,
{
"Symmetric synchronize function unit",
"ses.symm_sync",
FT_BOOLEAN, 16,
NULL,
SYMMETRIC_SYNCHRONIZE_FUNCTION_UNIT,
NULL,
HFILL
}
},
{
&hf_typed_data_function_unit,
{
"Typed data function unit",
"ses.typed_data",
FT_BOOLEAN, 16,
NULL,
TYPED_DATA_FUNCTION_UNIT,
NULL,
HFILL
}
},
{
&hf_exception_function_unit,
{
"Exception function unit",
"ses.exception_data",
FT_BOOLEAN, 16,
NULL,
EXCEPTION_FUNCTION_UNIT,
NULL,
HFILL
}
},
{
&hf_capability_function_unit,
{
"Capability function unit",
"ses.capability_data",
FT_BOOLEAN, 16,
NULL,
CAPABILITY_DATA_FUNCTION_UNIT,
NULL,
HFILL
}
},
{
&hf_negotiated_release_function_unit,
{
"Negotiated release function unit",
"ses.negotiated_release",
FT_BOOLEAN, 16,
NULL,
NEGOTIATED_RELEASE_FUNCTION_UNIT,
NULL,
HFILL
}
},
{
&hf_activity_management_function_unit,
{
"Activity management function unit",
"ses.activity_management",
FT_BOOLEAN, 16,
NULL,
ACTIVITY_MANAGEMENT_FUNCTION_UNIT,
NULL,
HFILL
}
},
{
&hf_resynchronize_function_unit,
{
"Resynchronize function unit",
"ses.resynchronize",
FT_BOOLEAN, 16,
NULL,
RESYNCHRONIZE_FUNCTION_UNIT,
NULL,
HFILL
}
},
{
&hf_major_resynchronize_function_unit,
{
"Major resynchronize function unit",
"ses.major_resynchronize",
FT_BOOLEAN, 16,
NULL,
MAJOR_SYNCHRONIZE_FUNCTION_UNIT,
NULL,
HFILL
}
},
{
&hf_minor_resynchronize_function_unit,
{
"Minor resynchronize function unit",
"ses.minor_resynchronize",
FT_BOOLEAN, 16,
NULL,
MINOR_SYNCHRONIZE_FUNCTION_UNIT,
NULL,
HFILL
}
},
{
&hf_expedited_data_resynchronize_function_unit,
{
"Expedited data function unit",
"ses.expedited_data",
FT_BOOLEAN, 16,
NULL,
EXPEDITED_DATA_FUNCTION_UNIT,
NULL,
HFILL
}
},
{
&hf_duplex_function_unit,
{
"Duplex functional unit",
"ses.duplex",
FT_BOOLEAN, 16,
NULL,
DUPLEX_FUNCTION_UNIT,
NULL,
HFILL
}
},
{
&hf_half_duplex_function_unit,
{
"Half-duplex functional unit",
"ses.half_duplex",
FT_BOOLEAN, 16,
NULL,
HALF_DUPLEX_FUNCTION_UNIT,
NULL,
HFILL
}
},
{
&hf_proposed_tsdu_maximum_size_i2r,
{
"Proposed TSDU Maximum Size, Initiator to Responder",
"ses.proposed_tsdu_maximum_size_i2r",
FT_UINT16,
BASE_DEC,
NULL,
0x0,
NULL,
HFILL
}
},
{
&hf_proposed_tsdu_maximum_size_r2i,
{
"Proposed TSDU Maximum Size, Responder to Initiator",
"ses.proposed_tsdu_maximum_size_r2i",
FT_UINT16,
BASE_DEC,
NULL,
0x0,
NULL,
HFILL
}
},
{
&hf_protocol_version_1,
{
"Protocol Version 1",
"ses.protocol_version1",
FT_BOOLEAN, 8,
NULL,
PROTOCOL_VERSION_1,
NULL,
HFILL
}
},
{
&hf_protocol_version_2,
{
"Protocol Version 2",
"ses.protocol_version2",
FT_BOOLEAN, 8,
NULL,
PROTOCOL_VERSION_2,
NULL,
HFILL
}
},
{
&hf_initial_serial_number,
{
"Initial Serial Number",
"ses.initial_serial_number",
FT_STRING, BASE_NONE,
NULL,
0x0,
NULL,
HFILL
}
},
{
&hf_beginning_of_SSDU,
{
"beginning of SSDU",
"ses.begininng_of_SSDU",
FT_BOOLEAN, 8,
NULL,
BEGINNING_SPDU,
NULL,
HFILL
}
},
{
&hf_end_of_SSDU,
{
"end of SSDU",
"ses.end_of_SSDU",
FT_BOOLEAN, 8,
NULL,
END_SPDU,
NULL,
HFILL
}
},
{
&hf_release_token_setting,
{
"release token setting",
"ses.release_token_setting",
FT_UINT8, BASE_HEX,
VALS(token_setting_vals),
0xC0,
NULL,
HFILL
}
},
{
&hf_major_activity_token_setting,
{
"major/activity setting",
"ses.major_activity_token_setting",
FT_UINT8, BASE_HEX,
VALS(token_setting_vals),
0x30,
"major/activity token setting",
HFILL
}
},
{
&hf_synchronize_minor_token_setting,
{
"synchronize-minor token setting",
"ses.synchronize_minor_token_setting",
FT_UINT8, BASE_HEX,
VALS(token_setting_vals),
0x0C,
NULL,
HFILL
}
},
{
&hf_data_token_setting,
{
"data token setting",
"ses.data_token_setting",
FT_UINT8, BASE_HEX,
VALS(token_setting_vals),
0x03,
NULL,
HFILL
}
},
{
&hf_activity_identifier,
{
"Activity Identifier",
"ses.activity_identifier",
FT_BYTES, BASE_NONE,
NULL,
0x0,
NULL,
HFILL
}
},
{
&hf_serial_number,
{
"Serial Number",
"ses.serial_number",
FT_STRING, BASE_NONE,
NULL,
0x0,
NULL,
HFILL
}
},
{
&hf_calling_session_selector,
{
"Calling Session Selector",
"ses.calling_session_selector",
FT_BYTES, BASE_NONE,
NULL,
0x0,
NULL,
HFILL
}
},
{
&hf_called_session_selector,
{
"Called Session Selector",
"ses.called_session_selector",
FT_BYTES, BASE_NONE,
NULL,
0x0,
NULL,
HFILL
}
},
{
&hf_second_serial_number,
{
"Second Serial Number",
"ses.second_serial_number",
FT_STRING, BASE_NONE,
NULL,
0x0,
NULL,
HFILL
}
},
{
&hf_second_initial_serial_number,
{
"Second Initial Serial Number",
"ses.second_initial_serial_number",
FT_STRING, BASE_NONE,
NULL,
0x0,
NULL,
HFILL
}
},
{
&hf_large_initial_serial_number,
{
"Large Initial Serial Number",
"ses.large_initial_serial_number",
FT_STRING, BASE_NONE,
NULL,
0x0,
NULL,
HFILL
}
},
{
&hf_large_second_initial_serial_number,
{
"Large Second Initial Serial Number",
"ses.large_second_initial_serial_number",
FT_STRING, BASE_NONE,
NULL,
0x0,
NULL,
HFILL
}
},
{
&hf_connect_protocol_options_flags,
{
"Flags",
"ses.connect.flags",
FT_UINT8,
BASE_HEX,
NULL,
0x0,
NULL,
HFILL
}
},
{
&hf_version_number_options_flags,
{
"Flags",
"ses.version.flags",
FT_UINT8,
BASE_HEX,
NULL,
0x0,
NULL,
HFILL
}
},
{
&hf_token_item_options_flags,
{
"Flags",
"ses.tken_item.flags",
FT_UINT8,
BASE_HEX,
NULL,
0x0,
NULL,
HFILL
}
},
{
&hf_enclosure_item_options_flags,
{
"Flags",
"ses.enclosure.flags",
FT_UINT8,
BASE_HEX,
NULL,
0x0,
NULL,
HFILL
}
},
{ &hf_ses_segment_data,
{ "SES segment data", "ses.segment.data", FT_NONE, BASE_NONE,
NULL, 0x00, NULL, HFILL } },
{ &hf_ses_segments,
{ "SES segments", "ses.segments", FT_NONE, BASE_NONE,
NULL, 0x00, NULL, HFILL } },
{ &hf_ses_segment,
{ "SES segment", "ses.segment", FT_FRAMENUM, BASE_NONE,
NULL, 0x00, NULL, HFILL } },
{ &hf_ses_segment_overlap,
{ "SES segment overlap", "ses.segment.overlap", FT_BOOLEAN,
BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_ses_segment_overlap_conflicts,
{ "SES segment overlapping with conflicting data",
"ses.segment.overlap.conflicts", FT_BOOLEAN, BASE_NONE,
NULL, 0x0, NULL, HFILL } },
{ &hf_ses_segment_multiple_tails,
{ "SES has multiple tail segments",
"ses.segment.multiple_tails", FT_BOOLEAN, BASE_NONE,
NULL, 0x0, NULL, HFILL } },
{ &hf_ses_segment_too_long_segment,
{ "SES segment too long", "ses.segment.too_long_segment",
FT_BOOLEAN, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_ses_segment_error,
{ "SES desegmentation error", "ses.segment.error", FT_FRAMENUM,
BASE_NONE, NULL, 0x00, NULL, HFILL } },
{ &hf_ses_segment_count,
{ "SES segment count", "ses.segment.count", FT_UINT32, BASE_DEC,
NULL, 0x00, NULL, HFILL } },
{ &hf_ses_reassembled_in,
{ "Reassembled SES in frame", "ses.reassembled.in", FT_FRAMENUM, BASE_NONE,
NULL, 0x00, "This SES packet is reassembled in this frame", HFILL } },
{ &hf_ses_reassembled_length,
{ "Reassembled SES length", "ses.reassembled.length", FT_UINT32, BASE_DEC,
NULL, 0x00, "The total length of the reassembled payload", HFILL } }
};
static gint *ett[] =
{
&ett_ses,
&ett_ses_param,
&ett_connect_protocol_options_flags,
&ett_protocol_version_flags,
&ett_enclosure_item_flags,
&ett_token_item_flags,
&ett_ses_req_options_flags,
&ett_ses_segment,
&ett_ses_segments
};
module_t *ses_module;
proto_ses = proto_register_protocol(PROTO_STRING_SES, "SES", "ses");
proto_register_field_array(proto_ses, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_init_routine (&ses_reassemble_init);
ses_module = prefs_register_protocol(proto_ses, NULL);
prefs_register_bool_preference(ses_module, "desegment",
"Reassemble session packets ",
"Whether the session dissector should reassemble messages spanning multiple SES segments",
&ses_desegment);
register_dissector("ses", dissect_ses, proto_ses);
}
static gboolean
dissect_ses_heur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, void *data _U_)
{
int offset = 0;
guint8 type;
int len_len;
guint16 len;
if (tvb_length(tvb) < 2)
return FALSE;
type = tvb_get_guint8(tvb, offset);
if (try_val_to_str(type, ses_vals) == NULL)
{
return FALSE;
}
if(tvb_bytes_exist(tvb, 2, 2) && type == SES_GIVE_TOKENS) {
type = tvb_get_guint8(tvb, offset+2);
if (try_val_to_str(type, ses_vals) == NULL)
{
return FALSE;
}
}
if(type == 0x32 && tvb_length(tvb) >= 3) {
type = tvb_get_guint8(tvb, offset+2);
if (try_val_to_str(type, param_vals) == NULL) {
return FALSE;
}
}
len = get_item_len(tvb, offset+1, &len_len);
len+=len_len;
if (tvb_length(tvb) < len)
return FALSE;
if (tvb_length(tvb) > 1+(guint) len) {
type = tvb_get_guint8(tvb, offset + len + 1);
if (try_val_to_str(type, ses_vals) == NULL) {
return FALSE;
}
}
dissect_ses(tvb, pinfo, parent_tree);
return TRUE;
}
void
proto_reg_handoff_ses(void)
{
data_handle = find_dissector("data");
pres_handle = find_dissector("pres");
heur_dissector_add("cotp", dissect_ses_heur, proto_ses);
heur_dissector_add("cotp_is", dissect_ses_heur, proto_ses);
}
void proto_register_clses(void)
{
proto_clses = proto_register_protocol(PROTO_STRING_CLSES, "CLSP", "clsp");
}
void
proto_reg_handoff_clses(void)
{
heur_dissector_add("cltp", dissect_ses_heur, proto_clses);
}
