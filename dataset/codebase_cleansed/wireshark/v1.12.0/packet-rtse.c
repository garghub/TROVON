void
register_rtse_oid_dissector_handle(const char *oid, dissector_handle_t dissector, int proto, const char *name, gboolean uses_ros)
{
static dissector_handle_t rtse_handle = NULL;
static dissector_handle_t ros_handle = NULL;
if (rtse_handle == NULL)
rtse_handle = find_dissector("rtse");
if (ros_handle == NULL)
ros_handle = find_dissector("ros");
g_hash_table_insert(oid_table, (gpointer)oid, (gpointer)name);
register_ber_oid_dissector_handle(oid, rtse_handle, proto, name);
if(uses_ros) {
dissector_add_string("rtse.oid", oid, ros_handle);
register_ros_oid_dissector_handle(oid, dissector, proto, name, TRUE);
} else {
dissector_add_string("rtse.oid", oid, dissector);
}
}
static int
call_rtse_oid_callback(const char *oid, tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, void* data)
{
tvbuff_t *next_tvb;
next_tvb = tvb_new_subset_remaining(tvb, offset);
if(!dissector_try_string(rtse_oid_dissector_table, oid, next_tvb, pinfo, tree, data)){
proto_item *item=proto_tree_add_text(tree, next_tvb, 0, tvb_length_remaining(tvb, offset), "RTSE: Dissector for OID:%s not implemented. Contact Wireshark developers if you want this supported", oid);
proto_tree *next_tree=proto_item_add_subtree(item, ett_rtse_unknown);
expert_add_info_format(pinfo, item, &ei_rtse_dissector_oid_not_implemented,
"RTSE: Dissector for OID %s not implemented", oid);
dissect_unknown_ber(pinfo, next_tvb, offset, next_tree);
}
offset+=tvb_length_remaining(tvb, offset);
return offset;
}
static int
call_rtse_external_type_callback(gboolean implicit_tag _U_, tvbuff_t *tvb, int offset, asn1_ctx_t *actx, proto_tree *tree, int hf_index _U_)
{
const char *oid = NULL;
if (actx->external.indirect_ref_present) {
oid = (const char *)find_oid_by_pres_ctx_id(actx->pinfo, actx->external.indirect_reference);
} else if (actx->external.direct_ref_present) {
oid = actx->external.direct_reference;
}
if (oid)
offset = call_rtse_oid_callback(oid, tvb, offset, actx->pinfo, top_tree ? top_tree : tree, actx->private_data);
return offset;
}
static int
dissect_rtse_INTEGER(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_rtse_T_dialogueMode(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_rtse_T_open(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 58 "../../asn1/rtse/rtse.cnf"
struct SESSION_DATA_STRUCTURE* session = (struct SESSION_DATA_STRUCTURE*)actx->private_data;
const char *oid = NULL;
switch(app_proto) {
case 1:
oid = "applicationProtocol.1";
break;
case 12:
oid = "applicationProtocol.12";
break;
default:
if(session && session->pres_ctx_id)
oid = find_oid_by_pres_ctx_id(actx->pinfo, session->pres_ctx_id);
break;
}
if(!oid)
oid = "applicationProtocol.12";
if(oid) {
offset = call_rtse_oid_callback(oid, tvb, offset, actx->pinfo, top_tree ? top_tree : tree, session);
}
return offset;
}
static int
dissect_rtse_T_t61String(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 115 "../../asn1/rtse/rtse.cnf"
tvbuff_t *string = NULL;
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_TeletexString,
actx, tree, tvb, offset, hf_index,
&string);
if(open_request && string)
col_append_fstr(actx->pinfo->cinfo, COL_INFO, " %s", tvb_format_text(string, 0, tvb_length(string)));
return offset;
}
static int
dissect_rtse_T_octetString(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 131 "../../asn1/rtse/rtse.cnf"
tvbuff_t *string = NULL;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&string);
if(open_request && string)
col_append_fstr(actx->pinfo->cinfo, COL_INFO, " %s", tvb_format_text(string, 0, tvb_length(string)));
return offset;
}
static int
dissect_rtse_CallingSSuserReference(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
CallingSSuserReference_choice, hf_index, ett_rtse_CallingSSuserReference,
NULL);
return offset;
}
static int
dissect_rtse_CommonReference(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 123 "../../asn1/rtse/rtse.cnf"
tvbuff_t *string = NULL;
offset = dissect_ber_UTCTime(implicit_tag, actx, tree, tvb, offset, hf_index);
if(open_request && string)
col_append_fstr(actx->pinfo->cinfo, COL_INFO, " %s", tvb_format_text(string, 0, tvb_length(string)));
return offset;
}
static int
dissect_rtse_AdditionalReferenceInformation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_TeletexString,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_rtse_SessionConnectionIdentifier(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 108 "../../asn1/rtse/rtse.cnf"
if(open_request)
col_append_str(actx->pinfo->cinfo, COL_INFO, "Recover");
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
SessionConnectionIdentifier_sequence, hf_index, ett_rtse_SessionConnectionIdentifier);
return offset;
}
static int
dissect_rtse_ConnectionData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
ConnectionData_choice, hf_index, ett_rtse_ConnectionData,
NULL);
return offset;
}
static int
dissect_rtse_T_applicationProtocol(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 104 "../../asn1/rtse/rtse.cnf"
offset = dissect_ber_integer(TRUE, actx, tree, tvb, offset, hf_index, &app_proto);
return offset;
}
int
dissect_rtse_RTORQapdu(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 41 "../../asn1/rtse/rtse.cnf"
struct SESSION_DATA_STRUCTURE* session = (struct SESSION_DATA_STRUCTURE*)actx->private_data;
if(session != NULL)
session->ros_op = (ROS_OP_BIND | ROS_OP_ARGUMENT);
open_request=TRUE;
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
RTORQapdu_set, hf_index, ett_rtse_RTORQapdu);
open_request=FALSE;
return offset;
}
int
dissect_rtse_RTOACapdu(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 50 "../../asn1/rtse/rtse.cnf"
struct SESSION_DATA_STRUCTURE* session = (struct SESSION_DATA_STRUCTURE*)actx->private_data;
if(session != NULL)
session->ros_op = (ROS_OP_BIND | ROS_OP_RESULT);
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
RTOACapdu_set, hf_index, ett_rtse_RTOACapdu);
return offset;
}
static int
dissect_rtse_RefuseReason(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 155 "../../asn1/rtse/rtse.cnf"
int reason = -1;
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
&reason);
if(reason != -1)
col_append_fstr(actx->pinfo->cinfo, COL_INFO, " (%s)", val_to_str(reason, rtse_RefuseReason_vals, "reason(%d)"));
return offset;
}
static int
dissect_rtse_T_userDataRJ(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 11 "../../asn1/rtse/rtse.cnf"
struct SESSION_DATA_STRUCTURE* session = (struct SESSION_DATA_STRUCTURE*)actx->private_data;
const char *oid = NULL;
switch(app_proto) {
case 1:
oid = "applicationProtocol.1";
break;
case 12:
oid = "applicationProtocol.12";
break;
default:
if(session && session->pres_ctx_id)
oid = find_oid_by_pres_ctx_id(actx->pinfo, session->pres_ctx_id);
break;
}
if(!oid)
oid = "applicationProtocol.12";
if(oid) {
if(session != NULL)
session->ros_op = (ROS_OP_BIND | ROS_OP_ERROR);
offset = call_rtse_oid_callback(oid, tvb, offset, actx->pinfo, top_tree ? top_tree : tree, session);
}
return offset;
}
int
dissect_rtse_RTORJapdu(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 147 "../../asn1/rtse/rtse.cnf"
col_append_str(actx->pinfo->cinfo, COL_INFO, "Refuse");
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
RTORJapdu_set, hf_index, ett_rtse_RTORJapdu);
return offset;
}
static int
dissect_rtse_RTTPapdu(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 137 "../../asn1/rtse/rtse.cnf"
int priority = -1;
col_append_str(actx->pinfo->cinfo, COL_INFO, "Turn-Please");
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
&priority);
if(priority != -1)
col_append_fstr(actx->pinfo->cinfo, COL_INFO, " (%d)", priority);
return offset;
}
static int
dissect_rtse_RTTRapdu(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 86 "../../asn1/rtse/rtse.cnf"
tvbuff_t *next_tvb = NULL;
struct SESSION_DATA_STRUCTURE* session = (struct SESSION_DATA_STRUCTURE*)actx->private_data;
offset = dissect_ber_octet_string(FALSE, actx, tree, tvb, offset, hf_index, &next_tvb);
if(next_tvb) {
if(session)
session->ros_op = (ROS_OP_INVOKE | ROS_OP_ARGUMENT);
offset = dissect_ber_external_type(FALSE, tree, next_tvb, 0, actx, -1, call_rtse_external_type_callback);
}
return offset;
}
static int
dissect_rtse_AbortReason(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 171 "../../asn1/rtse/rtse.cnf"
int reason = -1;
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
&reason);
if(reason != -1)
col_append_fstr(actx->pinfo->cinfo, COL_INFO, " (%s)", val_to_str(reason, rtse_AbortReason_vals, "reason(%d)"));
return offset;
}
static int
dissect_rtse_BIT_STRING(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
NULL, hf_index, -1,
NULL);
return offset;
}
static int
dissect_rtse_T_userdataAB(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 38 "../../asn1/rtse/rtse.cnf"
return offset;
}
int
dissect_rtse_RTABapdu(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 163 "../../asn1/rtse/rtse.cnf"
col_append_str(actx->pinfo->cinfo, COL_INFO, "Abort");
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
RTABapdu_set, hf_index, ett_rtse_RTABapdu);
return offset;
}
static int
dissect_rtse_RTSE_apdus(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
RTSE_apdus_choice, hf_index, ett_rtse_RTSE_apdus,
NULL);
return offset;
}
static int
dissect_rtse(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, void* data)
{
int offset = 0;
int old_offset;
proto_item *item;
proto_tree *tree;
proto_tree *next_tree=NULL;
tvbuff_t *next_tvb = NULL;
tvbuff_t *data_tvb = NULL;
fragment_head *frag_msg = NULL;
guint32 fragment_length;
guint32 rtse_id = 0;
gboolean data_handled = FALSE;
struct SESSION_DATA_STRUCTURE* session;
conversation_t *conversation = NULL;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
if (data == NULL)
return 0;
session = (struct SESSION_DATA_STRUCTURE*)data;
top_tree=parent_tree;
asn1_ctx.private_data = session;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "RTSE");
col_clear(pinfo->cinfo, COL_INFO);
if (rtse_reassemble &&
((session->spdu_type == SES_DATA_TRANSFER) ||
(session->spdu_type == SES_MAJOR_SYNC_POINT))) {
conversation = find_conversation (pinfo->fd->num,
&pinfo->src, &pinfo->dst, pinfo->ptype,
pinfo->srcport, pinfo->destport, 0);
if (conversation != NULL) {
rtse_id = conversation->index;
}
session->rtse_reassemble = TRUE;
}
if (rtse_reassemble && session->spdu_type == SES_MAJOR_SYNC_POINT) {
frag_msg = fragment_end_seq_next (&rtse_reassembly_table,
pinfo, rtse_id, NULL);
next_tvb = process_reassembled_data (tvb, offset, pinfo, "Reassembled RTSE",
frag_msg, &rtse_frag_items, NULL, parent_tree);
}
item = proto_tree_add_item(parent_tree, proto_rtse, next_tvb ? next_tvb : tvb, 0, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_rtse);
if (rtse_reassemble && session->spdu_type == SES_DATA_TRANSFER) {
dissect_ber_octet_string(FALSE, &asn1_ctx, tree, tvb, offset, hf_rtse_segment_data, &data_tvb);
if (data_tvb) {
fragment_length = tvb_length_remaining (data_tvb, 0);
proto_item_append_text(asn1_ctx.created_item, " (%u byte%s)", fragment_length,
plurality(fragment_length, "", "s"));
frag_msg = fragment_add_seq_next (&rtse_reassembly_table,
data_tvb, 0, pinfo,
rtse_id, NULL,
fragment_length, TRUE);
if (frag_msg && pinfo->fd->num != frag_msg->reassembled_in) {
proto_tree_add_uint (tree, *(rtse_frag_items.hf_reassembled_in),
data_tvb, 0, 0, frag_msg->reassembled_in);
}
pinfo->fragmented = TRUE;
data_handled = TRUE;
} else {
fragment_length = tvb_length_remaining (tvb, offset);
}
col_append_fstr(pinfo->cinfo, COL_INFO, "[RTSE fragment, %u byte%s]",
fragment_length, plurality(fragment_length, "", "s"));
} else if (rtse_reassemble && session->spdu_type == SES_MAJOR_SYNC_POINT) {
if (next_tvb) {
session->ros_op = (ROS_OP_INVOKE | ROS_OP_ARGUMENT);
dissect_ber_external_type(FALSE, tree, next_tvb, 0, &asn1_ctx, -1, call_rtse_external_type_callback);
top_tree = NULL;
return 1;
} else {
offset = tvb_length (tvb);
}
pinfo->fragmented = FALSE;
data_handled = TRUE;
}
if (!data_handled) {
while (tvb_reported_length_remaining(tvb, offset) > 0){
old_offset=offset;
offset=dissect_rtse_RTSE_apdus(TRUE, tvb, offset, &asn1_ctx, tree, -1);
if(offset == old_offset){
item = proto_tree_add_text(tree, tvb, offset, -1, "Unknown RTSE PDU");
expert_add_info (pinfo, item, &ei_rtse_unknown_rtse_pdu);
next_tree=proto_item_add_subtree(item, ett_rtse_unknown);
dissect_unknown_ber(pinfo, tvb, offset, next_tree);
break;
}
}
}
top_tree = NULL;
return tvb_length(tvb);
}
static void rtse_reassemble_init (void)
{
reassembly_table_init (&rtse_reassembly_table,
&addresses_reassembly_table_functions);
}
void proto_register_rtse(void) {
static hf_register_info hf[] =
{
{ &hf_rtse_segment_data,
{ "RTSE segment data", "rtse.segment", FT_NONE, BASE_NONE,
NULL, 0x00, NULL, HFILL } },
{ &hf_rtse_fragments,
{ "RTSE fragments", "rtse.fragments", FT_NONE, BASE_NONE,
NULL, 0x00, NULL, HFILL } },
{ &hf_rtse_fragment,
{ "RTSE fragment", "rtse.fragment", FT_FRAMENUM, BASE_NONE,
NULL, 0x00, NULL, HFILL } },
{ &hf_rtse_fragment_overlap,
{ "RTSE fragment overlap", "rtse.fragment.overlap", FT_BOOLEAN,
BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_rtse_fragment_overlap_conflicts,
{ "RTSE fragment overlapping with conflicting data",
"rtse.fragment.overlap.conflicts", FT_BOOLEAN, BASE_NONE,
NULL, 0x0, NULL, HFILL } },
{ &hf_rtse_fragment_multiple_tails,
{ "RTSE has multiple tail fragments",
"rtse.fragment.multiple_tails", FT_BOOLEAN, BASE_NONE,
NULL, 0x0, NULL, HFILL } },
{ &hf_rtse_fragment_too_long_fragment,
{ "RTSE fragment too long", "rtse.fragment.too_long_fragment",
FT_BOOLEAN, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_rtse_fragment_error,
{ "RTSE defragmentation error", "rtse.fragment.error", FT_FRAMENUM,
BASE_NONE, NULL, 0x00, NULL, HFILL } },
{ &hf_rtse_fragment_count,
{ "RTSE fragment count", "rtse.fragment.count", FT_UINT32, BASE_DEC,
NULL, 0x00, NULL, HFILL } },
{ &hf_rtse_reassembled_in,
{ "Reassembled RTSE in frame", "rtse.reassembled.in", FT_FRAMENUM, BASE_NONE,
NULL, 0x00, "This RTSE packet is reassembled in this frame", HFILL } },
{ &hf_rtse_reassembled_length,
{ "Reassembled RTSE length", "rtse.reassembled.length", FT_UINT32, BASE_DEC,
NULL, 0x00, "The total length of the reassembled payload", HFILL } },
#line 1 "../../asn1/rtse/packet-rtse-hfarr.c"
{ &hf_rtse_rtorq_apdu,
{ "rtorq-apdu", "rtse.rtorq_apdu_element",
FT_NONE, BASE_NONE, NULL, 0,
"RTORQapdu", HFILL }},
{ &hf_rtse_rtoac_apdu,
{ "rtoac-apdu", "rtse.rtoac_apdu_element",
FT_NONE, BASE_NONE, NULL, 0,
"RTOACapdu", HFILL }},
{ &hf_rtse_rtorj_apdu,
{ "rtorj-apdu", "rtse.rtorj_apdu_element",
FT_NONE, BASE_NONE, NULL, 0,
"RTORJapdu", HFILL }},
{ &hf_rtse_rttp_apdu,
{ "rttp-apdu", "rtse.rttp_apdu",
FT_INT32, BASE_DEC, NULL, 0,
"RTTPapdu", HFILL }},
{ &hf_rtse_rttr_apdu,
{ "rttr-apdu", "rtse.rttr_apdu",
FT_BYTES, BASE_NONE, NULL, 0,
"RTTRapdu", HFILL }},
{ &hf_rtse_rtab_apdu,
{ "rtab-apdu", "rtse.rtab_apdu_element",
FT_NONE, BASE_NONE, NULL, 0,
"RTABapdu", HFILL }},
{ &hf_rtse_checkpointSize,
{ "checkpointSize", "rtse.checkpointSize",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_rtse_windowSize,
{ "windowSize", "rtse.windowSize",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_rtse_dialogueMode,
{ "dialogueMode", "rtse.dialogueMode",
FT_INT32, BASE_DEC, VALS(rtse_T_dialogueMode_vals), 0,
NULL, HFILL }},
{ &hf_rtse_connectionDataRQ,
{ "connectionDataRQ", "rtse.connectionDataRQ",
FT_UINT32, BASE_DEC, VALS(rtse_ConnectionData_vals), 0,
"ConnectionData", HFILL }},
{ &hf_rtse_applicationProtocol,
{ "applicationProtocol", "rtse.applicationProtocol",
FT_INT32, BASE_DEC, VALS(rtse_T_applicationProtocol_vals), 0,
NULL, HFILL }},
{ &hf_rtse_connectionDataAC,
{ "connectionDataAC", "rtse.connectionDataAC",
FT_UINT32, BASE_DEC, VALS(rtse_ConnectionData_vals), 0,
"ConnectionData", HFILL }},
{ &hf_rtse_refuseReason,
{ "refuseReason", "rtse.refuseReason",
FT_INT32, BASE_DEC, VALS(rtse_RefuseReason_vals), 0,
NULL, HFILL }},
{ &hf_rtse_userDataRJ,
{ "userDataRJ", "rtse.userDataRJ_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rtse_abortReason,
{ "abortReason", "rtse.abortReason",
FT_INT32, BASE_DEC, VALS(rtse_AbortReason_vals), 0,
NULL, HFILL }},
{ &hf_rtse_reflectedParameter,
{ "reflectedParameter", "rtse.reflectedParameter",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING", HFILL }},
{ &hf_rtse_userdataAB,
{ "userdataAB", "rtse.userdataAB_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rtse_open,
{ "open", "rtse.open_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rtse_recover,
{ "recover", "rtse.recover_element",
FT_NONE, BASE_NONE, NULL, 0,
"SessionConnectionIdentifier", HFILL }},
{ &hf_rtse_callingSSuserReference,
{ "callingSSuserReference", "rtse.callingSSuserReference",
FT_UINT32, BASE_DEC, VALS(rtse_CallingSSuserReference_vals), 0,
NULL, HFILL }},
{ &hf_rtse_commonReference,
{ "commonReference", "rtse.commonReference",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rtse_additionalReferenceInformation,
{ "additionalReferenceInformation", "rtse.additionalReferenceInformation",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rtse_t61String,
{ "t61String", "rtse.t61String",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_rtse_octetString,
{ "octetString", "rtse.octetString",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
#line 352 "../../asn1/rtse/packet-rtse-template.c"
};
static gint *ett[] = {
&ett_rtse,
&ett_rtse_unknown,
&ett_rtse_fragment,
&ett_rtse_fragments,
#line 1 "../../asn1/rtse/packet-rtse-ettarr.c"
&ett_rtse_RTSE_apdus,
&ett_rtse_RTORQapdu,
&ett_rtse_RTOACapdu,
&ett_rtse_RTORJapdu,
&ett_rtse_RTABapdu,
&ett_rtse_ConnectionData,
&ett_rtse_SessionConnectionIdentifier,
&ett_rtse_CallingSSuserReference,
#line 361 "../../asn1/rtse/packet-rtse-template.c"
};
static ei_register_info ei[] = {
{ &ei_rtse_dissector_oid_not_implemented, { "rtse.dissector_oid_not_implemented", PI_UNDECODED, PI_WARN, "RTSE: Dissector for OID not implemented", EXPFILL }},
{ &ei_rtse_unknown_rtse_pdu, { "rtse.unknown_rtse_pdu", PI_UNDECODED, PI_WARN, "Unknown RTSE PDU", EXPFILL }},
};
expert_module_t* expert_rtse;
module_t *rtse_module;
proto_rtse = proto_register_protocol(PNAME, PSNAME, PFNAME);
new_register_dissector("rtse", dissect_rtse, proto_rtse);
proto_register_field_array(proto_rtse, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_rtse = expert_register_protocol(proto_rtse);
expert_register_field_array(expert_rtse, ei, array_length(ei));
register_init_routine (&rtse_reassemble_init);
rtse_module = prefs_register_protocol_subtree("OSI", proto_rtse, NULL);
prefs_register_bool_preference(rtse_module, "reassemble",
"Reassemble segmented RTSE datagrams",
"Whether segmented RTSE datagrams should be reassembled."
" To use this option, you must also enable"
" \"Allow subdissectors to reassemble TCP streams\""
" in the TCP protocol settings.", &rtse_reassemble);
rtse_oid_dissector_table = register_dissector_table("rtse.oid", "RTSE OID Dissectors", FT_STRING, BASE_NONE);
oid_table=g_hash_table_new(g_str_hash, g_str_equal);
}
void proto_reg_handoff_rtse(void) {
}
