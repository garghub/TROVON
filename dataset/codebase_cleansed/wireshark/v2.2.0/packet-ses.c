static void
call_pres_dissector(tvbuff_t *tvb, int offset, guint16 param_len,
packet_info *pinfo, proto_tree *tree,
proto_tree *param_tree,
struct SESSION_DATA_STRUCTURE *session)
{
if(!pres_handle)
{
if (tree)
{
proto_tree_add_item(param_tree, hf_ses_user_data, tvb, offset, param_len, ENC_NA);
}
}
else
{
tvbuff_t *next_tvb;
next_tvb = tvb_new_subset_length(tvb, offset, param_len);
call_dissector_with_data(pres_handle, next_tvb, pinfo, tree, session);
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
guint16 param_len, proto_item *param_len_item, guint8 *enclosure_item_flags,
struct SESSION_DATA_STRUCTURE *session)
{
gboolean has_user_information = TRUE;
guint16 flags;
asn1_ctx_t asn1_ctx;
static const int * item_option_flags[] = {
&hf_release_token,
&hf_major_activity_token,
&hf_synchronize_minor_token,
&hf_data_token,
NULL
};
static const int * transport_option_flags[] = {
&hf_ses_transport_connection,
&hf_ses_transport_user_abort,
&hf_ses_transport_protocol_error,
&hf_ses_transport_no_reason,
&hf_ses_transport_implementation_restriction,
NULL
};
static const int * protocol_options_flags[] = {
&hf_able_to_receive_extended_concatenated_SPDU,
NULL
};
static const int * req_options_flags[] = {
&hf_session_exception_report,
&hf_data_separation_function_unit,
&hf_symmetric_synchronize_function_unit,
&hf_typed_data_function_unit,
&hf_exception_function_unit,
&hf_capability_function_unit,
&hf_negotiated_release_function_unit,
&hf_activity_management_function_unit,
&hf_resynchronize_function_unit,
&hf_major_resynchronize_function_unit,
&hf_minor_resynchronize_function_unit,
&hf_expedited_data_resynchronize_function_unit,
&hf_duplex_function_unit,
&hf_half_duplex_function_unit,
NULL
};
static const int * version_flags[] = {
&hf_protocol_version_2,
&hf_protocol_version_1,
NULL
};
static const int * enclosure_flags[] = {
&hf_end_of_SSDU,
&hf_beginning_of_SSDU,
NULL
};
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
switch (param_type)
{
case Called_SS_user_Reference:
if (param_len == 0)
break;
proto_tree_add_item(param_tree,
hf_called_ss_user_reference,
tvb, offset, param_len, ENC_NA);
break;
case Calling_SS_user_Reference:
if (param_len == 0)
break;
proto_tree_add_item(param_tree,
hf_calling_ss_user_reference,
tvb, offset, param_len, ENC_NA);
break;
case Common_Reference:
if (param_len == 0)
break;
proto_tree_add_item(param_tree,
hf_common_reference,
tvb, offset, param_len, ENC_NA);
break;
case Additional_Reference_Information:
if (param_len == 0)
break;
proto_tree_add_item(param_tree,
hf_additional_reference_information,
tvb, offset, param_len, ENC_NA);
break;
case Token_Item:
if (param_len != 1)
{
expert_add_info_format(pinfo, param_len_item, &ei_ses_bad_length,
"Length is %u, should be 1", param_len);
break;
}
proto_tree_add_bitmask(param_tree, tvb, offset, hf_token_item_options_flags, ett_token_item_flags, item_option_flags, ENC_NA);
break;
case Transport_Disconnect:
if (param_len != 1)
{
expert_add_info_format(pinfo, param_len_item, &ei_ses_bad_length,
"Length is %u, should be 1", param_len);
break;
}
proto_tree_add_bitmask(param_tree, tvb, offset, hf_ses_transport_option_flags, ett_transport_options_flags, transport_option_flags, ENC_NA);
if(tvb_get_guint8(tvb, offset) & user_abort )
{
session->abort_type = SESSION_USER_ABORT;
}
else
{
session->abort_type = SESSION_PROVIDER_ABORT;
}
break;
case Protocol_Options:
if (param_len != 1)
{
expert_add_info_format(pinfo, param_len_item, &ei_ses_bad_length,
"Length is %u, should be 1", param_len);
break;
}
proto_tree_add_bitmask(param_tree, tvb, offset, hf_connect_protocol_options_flags, ett_connect_protocol_options_flags, protocol_options_flags, ENC_NA);
break;
case Session_Requirement:
if (param_len != 2)
{
expert_add_info_format(pinfo, param_len_item, &ei_ses_bad_length,
"Length is %u, should be 2", param_len);
break;
}
proto_tree_add_bitmask(param_tree, tvb, offset, hf_session_user_req_flags, ett_ses_req_options_flags, req_options_flags, ENC_BIG_ENDIAN);
break;
case TSDU_Maximum_Size:
if (param_len != 4)
{
expert_add_info_format(pinfo, param_len_item, &ei_ses_bad_length,
"Length is %u, should be 4", param_len);
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
expert_add_info_format(pinfo, param_len_item, &ei_ses_bad_length,
"Length is %u, should be 1", param_len);
break;
}
proto_tree_add_bitmask(param_tree, tvb, offset, hf_version_number_options_flags, ett_protocol_version_flags, version_flags, ENC_BIG_ENDIAN);
break;
case Initial_Serial_Number:
if (param_len == 0)
break;
proto_tree_add_item(param_tree,
hf_initial_serial_number,
tvb, offset, param_len, ENC_ASCII|ENC_NA);
break;
case EnclosureItem:
if (param_len != 1)
{
expert_add_info_format(pinfo, param_len_item, &ei_ses_bad_length,
"Length is %u, should be 1", param_len);
break;
}
flags = tvb_get_guint8(tvb, offset);
*enclosure_item_flags = (guint8) flags;
proto_tree_add_bitmask(param_tree, tvb, offset, hf_enclosure_item_options_flags, ett_enclosure_item_flags, enclosure_flags, ENC_BIG_ENDIAN);
if (flags & END_SPDU) {
if(!(flags & BEGINNING_SPDU)) {
has_user_information = FALSE;
}
}
break;
case Token_Setting_Item:
if (param_len != 1)
{
expert_add_info_format(pinfo, param_len_item, &ei_ses_bad_length,
"Length is %u, should be 1", param_len);
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
proto_tree_add_item(param_tree,
hf_activity_identifier,
tvb, offset, param_len, ENC_NA);
break;
case Serial_Number:
if (param_len == 0)
break;
proto_tree_add_item(param_tree,
hf_serial_number,
tvb, offset, param_len, ENC_ASCII|ENC_NA);
break;
case Reason_Code:
if (param_len < 1)
{
expert_add_info_format(pinfo, param_len_item, &ei_ses_bad_length,
"Length is %u, should be >= 1", param_len);
break;
}
proto_tree_add_item(param_tree, hf_ses_reason_code, tvb, offset, 1, ENC_BIG_ENDIAN);
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
proto_tree_add_item(param_tree,
hf_calling_session_selector,
tvb, offset, param_len, ENC_NA);
break;
case Called_Session_Selector:
if (param_len == 0)
break;
proto_tree_add_item(param_tree,
hf_called_session_selector,
tvb, offset, param_len, ENC_NA);
break;
case Second_Serial_Number:
if (param_len == 0)
break;
proto_tree_add_item(param_tree,
hf_second_serial_number,
tvb, offset, param_len, ENC_ASCII|ENC_NA);
break;
case Second_Initial_Serial_Number:
if (param_len == 0)
break;
proto_tree_add_item(param_tree,
hf_second_initial_serial_number,
tvb, offset, param_len, ENC_ASCII|ENC_NA);
break;
case Large_Initial_Serial_Number:
if (param_len == 0)
break;
proto_tree_add_item(param_tree,
hf_large_initial_serial_number,
tvb, offset, param_len, ENC_ASCII|ENC_NA);
break;
case Large_Second_Initial_Serial_Number:
if (param_len == 0)
break;
proto_tree_add_item(param_tree,
hf_large_second_initial_serial_number,
tvb, offset, param_len, ENC_ASCII|ENC_NA);
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
proto_item *ti, *param_len_item;
proto_tree *param_tree;
guint8 param_type;
const char *param_str;
int len_len;
guint16 param_len;
while(pg_len != 0)
{
param_type = tvb_get_guint8(tvb, offset);
param_tree = proto_tree_add_subtree(pg_tree, tvb, offset, -1,
ett_ses_param, &ti,
val_to_str_ext(param_type, &param_vals_ext, "Unknown parameter type (0x%02x)"));
param_str = val_to_str_ext_const(param_type, &param_vals_ext, "Unknown");
proto_tree_add_item(param_tree, hf_ses_parameter_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
pg_len--;
param_len = get_item_len(tvb, offset, &len_len);
if (len_len > pg_len) {
proto_item_set_len(ti, pg_len + 1);
proto_tree_add_expert_format(param_tree, pinfo, &ei_ses_bad_parameter_length, tvb, offset, pg_len, "Parameter length doesn't fit in parameter");
return has_user_information;
}
pg_len -= len_len;
if (param_len > pg_len) {
proto_item_set_len(ti, pg_len + 1 + len_len);
proto_tree_add_expert_format(param_tree, pinfo, &ei_ses_bad_parameter_length, tvb, offset, pg_len, "Parameter length: %u, should be <= %u", param_len, pg_len);
return has_user_information;
}
proto_item_set_len(ti, 1 + len_len + param_len);
param_len_item = proto_tree_add_uint(param_tree, hf_ses_parameter_length, tvb, offset, len_len, param_len);
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
proto_tree_add_item(param_tree, hf_ses_parameter_group_inside_parameter_group, tvb, offset, param_len, ENC_NA);
break;
default:
if (!dissect_parameter(tvb, offset, tree,
param_tree, pinfo, param_type, param_len, param_len_item,
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
proto_item *ti, *param_len_item;
proto_tree *param_tree;
guint8 param_type;
const char *param_str;
int len_len;
guint16 param_len;
while (len != 0)
{
param_type = tvb_get_guint8(tvb, offset);
param_tree = proto_tree_add_subtree(ses_tree, tvb, offset, -1, ett_ses_param, &ti,
val_to_str_ext(param_type, &param_vals_ext,
"Unknown parameter type (0x%02x)"));
param_str = val_to_str_ext_const(param_type, &param_vals_ext, "Unknown");
proto_tree_add_item(param_tree, hf_ses_parameter_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
len--;
param_len = get_item_len(tvb, offset, &len_len);
if (len_len > len) {
proto_item_set_len(ti, len + 1 );
proto_tree_add_expert_format(param_tree, pinfo, &ei_ses_bad_parameter_length, tvb, offset, len, "Parameter length doesn't fit in parameter");
return has_user_information;
}
len -= len_len;
if (param_len > len) {
proto_item_set_len(ti, len + 1 + len_len);
proto_tree_add_expert_format(param_tree, pinfo, &ei_ses_bad_parameter_length, tvb, offset, len, "Parameter length: %u, should be <= %u", param_len, len);
return has_user_information;
}
proto_item_set_len(ti, 1 + len_len + param_len);
param_len_item = proto_tree_add_uint(param_tree, hf_ses_parameter_length, tvb, offset, len_len, param_len);
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
param_tree, pinfo, param_type, param_len, param_len_item,
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
guint32 *pres_ctx_id = NULL;
guint8 enclosure_item_flags = BEGINNING_SPDU|END_SPDU;
struct SESSION_DATA_STRUCTURE session;
type = tvb_get_guint8(tvb, offset);
session.spdu_type = type;
session.abort_type = SESSION_NO_ABORT;
session.pres_ctx_id = 0;
session.ros_op = 0;
session.rtse_reassemble = FALSE;
if(connectionless) {
col_add_str(pinfo->cinfo, COL_INFO,
val_to_str_ext(type, &ses_vals_ext, "Unknown SPDU type (0x%02x)"));
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
val_to_str_ext(type, &ses_vals_ext, "Unknown SPDU type (0x%02x)"));
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
pres_ctx_id = (guint32 *)p_get_proto_data(wmem_file_scope(), pinfo, proto_ses, 0);
if (ses_rtse_reassemble != 0 && !pres_ctx_id) {
pres_ctx_id = wmem_new(wmem_file_scope(), guint32);
*pres_ctx_id = ses_pres_ctx_id;
p_add_proto_data(wmem_file_scope(), pinfo, proto_ses, 0, pres_ctx_id);
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
fragment_head *frag_msg = NULL;
gint fragment_len;
guint32 ses_id = 0;
conversation = find_conversation (pinfo->num,
&pinfo->src, &pinfo->dst, pinfo->ptype,
pinfo->srcport, pinfo->destport, 0);
if (conversation != NULL) {
ses_id = conversation->conv_index;
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
call_data_dissector(next_tvb, pinfo, tree);
} else {
call_dissector_with_data(pres_handle, next_tvb, pinfo, tree, &session);
}
offset = tvb_captured_length(tvb);
if (session.rtse_reassemble && type == SES_DATA_TRANSFER) {
ses_pres_ctx_id = session.pres_ctx_id;
ses_rtse_reassemble = TRUE;
}
}
return offset;
}
static int
dissect_ses(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
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
return tvb_captured_length(tvb);
}
static void ses_reassemble_init (void)
{
reassembly_table_init (&ses_reassembly_table,
&addresses_reassembly_table_functions);
}
static void ses_reassemble_cleanup (void)
{
reassembly_table_destroy(&ses_reassembly_table);
}
static gboolean
dissect_ses_heur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, void *data _U_)
{
int offset = 0;
guint8 type;
int len_len;
guint16 len;
if (tvb_captured_length(tvb) < 2)
return FALSE;
type = tvb_get_guint8(tvb, offset);
if (try_val_to_str_ext(type, &ses_vals_ext) == NULL)
{
return FALSE;
}
if(tvb_bytes_exist(tvb, 2, 2) && type == SES_GIVE_TOKENS) {
type = tvb_get_guint8(tvb, offset+2);
if (try_val_to_str_ext(type, &ses_vals_ext) == NULL)
{
return FALSE;
}
}
if(type == 0x32 && tvb_captured_length(tvb) >= 3) {
type = tvb_get_guint8(tvb, offset+2);
if (try_val_to_str_ext(type, &param_vals_ext) == NULL) {
return FALSE;
}
}
len = get_item_len(tvb, offset+1, &len_len);
len+=len_len;
if (tvb_reported_length(tvb) < len)
return FALSE;
if (tvb_captured_length(tvb) > 1+(guint) len) {
type = tvb_get_guint8(tvb, offset + len + 1);
if (try_val_to_str_ext(type, &ses_vals_ext) == NULL) {
return FALSE;
}
}
dissect_ses(tvb, pinfo, parent_tree, data);
return TRUE;
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
BASE_DEC | BASE_EXT_STRING,
&ses_vals_ext,
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
"ses.beginning_of_SSDU",
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
NULL, 0x00, "The total length of the reassembled payload", HFILL } },
{ &hf_ses_user_data, { "User data", "ses.user_data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ses_transport_option_flags, { "Flags", "ses.transport_flags", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_ses_transport_connection, { "Transport connection", "ses.transport_flags.connection", FT_BOOLEAN, 8, TFS(&tfs_released_kept), transport_connection_is_released, NULL, HFILL }},
{ &hf_ses_transport_user_abort, { "User abort", "ses.transport_flags.user_abort", FT_BOOLEAN, 8, TFS(&tfs_yes_no), user_abort, NULL, HFILL }},
{ &hf_ses_transport_protocol_error, { "Protocol error", "ses.transport_flags.protocol_error", FT_BOOLEAN, 8, TFS(&tfs_yes_no), protocol_error, NULL, HFILL }},
{ &hf_ses_transport_no_reason, { "No reason", "ses.transport_flags.no_reason", FT_BOOLEAN, 8, TFS(&tfs_yes_no), no_reason, NULL, HFILL }},
{ &hf_ses_transport_implementation_restriction, { "Implementation restriction", "ses.transport_flags.implementation_restriction", FT_BOOLEAN, 8, TFS(&tfs_yes_no), implementation_restriction, NULL, HFILL }},
{ &hf_ses_reason_code, { "Reason Code", "ses.reason_code", FT_UINT8, BASE_DEC|BASE_EXT_STRING, &reason_vals_ext, 0x0, NULL, HFILL }},
{ &hf_ses_parameter_type, { "Parameter type", "ses.parameter_type", FT_UINT8, BASE_DEC|BASE_EXT_STRING, &param_vals_ext, 0x0, NULL, HFILL }},
{ &hf_ses_parameter_length, { "Parameter length", "ses.parameter_length", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ses_parameter_group_inside_parameter_group, { "Parameter group inside parameter group", "ses.parameter_group_inside_parameter_group", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL }},
};
static gint *ett[] =
{
&ett_ses,
&ett_ses_param,
&ett_connect_protocol_options_flags,
&ett_transport_options_flags,
&ett_protocol_version_flags,
&ett_enclosure_item_flags,
&ett_token_item_flags,
&ett_ses_req_options_flags,
&ett_ses_segment,
&ett_ses_segments
};
static ei_register_info ei[] = {
{ &ei_ses_bad_length, { "ses.bad_length", PI_MALFORMED, PI_ERROR, "Bad length", EXPFILL }},
{ &ei_ses_bad_parameter_length, { "ses.bad_parameter_length", PI_MALFORMED, PI_ERROR, "Bad parameter length", EXPFILL }},
};
module_t *ses_module;
expert_module_t* expert_ses;
proto_ses = proto_register_protocol(PROTO_STRING_SES, "SES", "ses");
proto_register_field_array(proto_ses, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_ses = expert_register_protocol(proto_ses);
expert_register_field_array(expert_ses, ei, array_length(ei));
register_init_routine (&ses_reassemble_init);
register_cleanup_routine (&ses_reassemble_cleanup);
ses_module = prefs_register_protocol(proto_ses, NULL);
prefs_register_bool_preference(ses_module, "desegment",
"Reassemble session packets ",
"Whether the session dissector should reassemble messages spanning multiple SES segments",
&ses_desegment);
register_dissector("ses", dissect_ses, proto_ses);
}
void
proto_reg_handoff_ses(void)
{
pres_handle = find_dissector_add_dependency("pres", proto_ses);
heur_dissector_add("cotp", dissect_ses_heur, "SES over COTP", "ses_cotp", proto_ses, HEURISTIC_ENABLE);
heur_dissector_add("cotp_is", dissect_ses_heur, "SES over COTP (inactive subset)", "ses_cotp_is", proto_ses, HEURISTIC_ENABLE);
}
void proto_register_clses(void)
{
proto_clses = proto_register_protocol(PROTO_STRING_CLSES, "CLSP", "clsp");
}
void
proto_reg_handoff_clses(void)
{
heur_dissector_add("cltp", dissect_ses_heur, "CLSP over COTP", "clses_cotp", proto_clses, HEURISTIC_ENABLE);
}
