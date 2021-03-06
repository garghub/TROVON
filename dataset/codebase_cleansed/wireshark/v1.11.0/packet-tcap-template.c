extern void add_ansi_tcap_subdissector(guint32 ssn, dissector_handle_t dissector) {
g_hash_table_insert(ansi_sub_dissectors,GUINT_TO_POINTER(ssn),dissector);
dissector_add_uint("sccp.ssn",ssn,tcap_handle);
}
extern void add_itu_tcap_subdissector(guint32 ssn, dissector_handle_t dissector) {
g_hash_table_insert(itu_sub_dissectors,GUINT_TO_POINTER(ssn),dissector);
dissector_add_uint("sccp.ssn",ssn,tcap_handle);
}
extern void delete_ansi_tcap_subdissector(guint32 ssn, dissector_handle_t dissector _U_) {
g_hash_table_remove(ansi_sub_dissectors,GUINT_TO_POINTER(ssn));
if (!get_itu_tcap_subdissector(ssn))
dissector_delete_uint("sccp.ssn",ssn,tcap_handle);
}
extern void delete_itu_tcap_subdissector(guint32 ssn, dissector_handle_t dissector _U_) {
g_hash_table_remove(itu_sub_dissectors,GUINT_TO_POINTER(ssn));
if (!get_ansi_tcap_subdissector(ssn))
dissector_delete_uint("sccp.ssn", ssn,tcap_handle);
}
dissector_handle_t get_ansi_tcap_subdissector(guint32 ssn) {
return (dissector_handle_t)g_hash_table_lookup(ansi_sub_dissectors,GUINT_TO_POINTER(ssn));
}
dissector_handle_t get_itu_tcap_subdissector(guint32 ssn) {
return (dissector_handle_t)g_hash_table_lookup(itu_sub_dissectors,GUINT_TO_POINTER(ssn));
}
static void
dissect_tcap(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree)
{
proto_item *item=NULL;
proto_tree *tree=NULL;
struct tcaphash_context_t * p_tcap_context;
dissector_handle_t subdissector_handle;
asn1_ctx_t asn1_ctx;
gint8 ber_class;
gboolean pc;
gint tag;
get_ber_identifier(tvb, 0, &ber_class, &pc, &tag);
if(ber_class == BER_CLASS_PRI){
switch(tag){
case 1:
case 2:
case 3:
case 4:
case 5:
case 6:
case 22:
call_dissector(ansi_tcap_handle, tvb, pinfo, parent_tree);
return;
break;
default:
return;
}
}
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
tcap_top_tree = parent_tree;
tcap_stat_tree = NULL;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "TCAP");
if(parent_tree){
item = proto_tree_add_item(parent_tree, proto_tcap, tvb, 0, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_tcap);
tcap_stat_tree=tree;
}
cur_oid = NULL;
tcapext_oid = NULL;
raz_tcap_private(&tcap_private);
pinfo->private_data = &tcap_private;
gp_tcapsrt_info=tcapsrt_razinfo();
tcap_subdissector_used=FALSE;
gp_tcap_context=NULL;
dissect_tcap_TCMessage(FALSE, tvb, 0, &asn1_ctx, tree, -1);
if (gtcap_HandleSRT && !tcap_subdissector_used ) {
p_tcap_context=tcapsrt_call_matching(tvb, pinfo, tcap_stat_tree, gp_tcapsrt_info);
tcap_private.context=p_tcap_context;
if ( p_tcap_context && cur_oid && !p_tcap_context->oid_present ) {
g_strlcpy(p_tcap_context->oid, cur_oid, sizeof(p_tcap_context->oid));
p_tcap_context->oid_present=TRUE;
if ( (subdissector_handle = dissector_get_string_handle(ber_oid_dissector_table, cur_oid)) ) {
p_tcap_context->subdissector_handle=subdissector_handle;
p_tcap_context->subdissector_present=TRUE;
}
}
if (gtcap_HandleSRT && p_tcap_context && p_tcap_context->callback) {
(p_tcap_context->callback)(tvb, pinfo, tcap_stat_tree, p_tcap_context);
}
}
}
void
proto_reg_handoff_tcap(void)
{
data_handle = find_dissector("data");
ansi_tcap_handle = find_dissector("ansi_tcap");
ber_oid_dissector_table = find_dissector_table("ber.oid");
#include "packet-tcap-dis-tab.c"
}
void
proto_register_tcap(void)
{
static hf_register_info hf[] = {
{ &hf_tcap_tag,
{ "Tag", "tcap.msgtype",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_tcap_length,
{ "Length", "tcap.len",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_tcap_data,
{ "Data", "tcap.data",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_tcap_tid,
{ "Transaction Id", "tcap.tid",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_tcapsrt_SessionId,
{ "Session Id",
"tcap.srt.session_id",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tcapsrt_BeginSession,
{ "Begin Session",
"tcap.srt.begin",
FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"SRT Begin of Session", HFILL }
},
{ &hf_tcapsrt_EndSession,
{ "End Session",
"tcap.srt.end",
FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"SRT End of Session", HFILL }
},
{ &hf_tcapsrt_SessionTime,
{ "Session duration",
"tcap.srt.sessiontime",
FT_RELATIVE_TIME, BASE_NONE, NULL, 0x0,
"Duration of the TCAP session", HFILL }
},
{ &hf_tcapsrt_Duplicate,
{ "Session Duplicate",
"tcap.srt.duplicate",
FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"SRT Duplicated with Session", HFILL }
},
#include "packet-tcap-hfarr.c"
};
static gint *ett[] = {
&ett_tcap,
&ett_param,
&ett_otid,
&ett_dtid,
&ett_tcap_stat,
#include "packet-tcap-ettarr.c"
};
module_t *tcap_module;
proto_tcap = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_tcap, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
tcap_module = prefs_register_protocol(proto_tcap, NULL);
#if 0
prefs_register_enum_preference(tcap_module, "standard", "ITU TCAP standard",
"The SS7 standard used in ITU TCAP packets",
&tcap_standard, tcap_options, FALSE);
#else
prefs_register_obsolete_preference(tcap_module, "standard");
#endif
#if 0
prefs_register_bool_preference(tcap_module, "lock_info_col", "Lock Info column",
"Always show TCAP in Info column",
&lock_info_col);
#else
prefs_register_obsolete_preference(tcap_module, "lock_info_col");
#endif
range_convert_str(&global_ssn_range, "", MAX_SSN);
ssn_range = range_empty();
prefs_register_range_preference(tcap_module, "ssn", "SCCP SSNs",
"SCCP (and SUA) SSNs to decode as TCAP",
&global_ssn_range, MAX_SSN);
prefs_register_bool_preference(tcap_module, "srt",
"Service Response Time Analyse",
"Activate the analyse for Response Time",
&gtcap_HandleSRT);
prefs_register_bool_preference(tcap_module, "persistentsrt",
"Persistent stats for SRT",
"Statistics for Response Time",
&gtcap_PersistentSRT);
prefs_register_uint_preference(tcap_module, "repetitiontimeout",
"Repetition timeout",
"Maximal delay for message repetion",
10, &gtcap_RepetitionTimeout);
prefs_register_uint_preference(tcap_module, "losttimeout",
"lost timeout",
"Maximal delay for message lost",
10, &gtcap_LostTimeout);
ansi_sub_dissectors = g_hash_table_new(g_direct_hash,g_direct_equal);
itu_sub_dissectors = g_hash_table_new(g_direct_hash,g_direct_equal);
register_dissector("tcap", dissect_tcap, proto_tcap);
tcap_handle = create_dissector_handle(dissect_tcap, proto_tcap);
register_init_routine(&init_tcap);
}
static void range_delete_callback(guint32 ssn)
{
if ( ssn && !get_ansi_tcap_subdissector(ssn) && !get_itu_tcap_subdissector(ssn) ) {
dissector_delete_uint("sccp.ssn", ssn, tcap_handle);
}
}
static void range_add_callback(guint32 ssn)
{
if (ssn && !get_ansi_tcap_subdissector(ssn) && !get_itu_tcap_subdissector(ssn) ) {
dissector_add_uint("sccp.ssn", ssn, tcap_handle);
}
}
static void init_tcap(void) {
if (ssn_range) {
range_foreach(ssn_range, range_delete_callback);
g_free(ssn_range);
}
ssn_range = range_copy(global_ssn_range);
range_foreach(ssn_range, range_add_callback);
tcapsrt_init_routine();
}
static int
dissect_tcap_param(asn1_ctx_t *actx, proto_tree *tree, tvbuff_t *tvb, int offset)
{
gint tag_offset, saved_offset, len_offset;
tvbuff_t *next_tvb;
proto_tree *subtree;
proto_item *pi;
gint8 ber_class;
gboolean pc;
gint32 tag;
guint32 len;
guint32 tag_length;
guint32 len_length;
gboolean ind_field;
while (tvb_reported_length_remaining(tvb, offset) > 0)
{
saved_offset = offset;
offset = get_ber_identifier(tvb, offset, &ber_class, &pc, &tag);
tag_offset = offset;
offset = get_ber_length(tvb, offset, &len, &ind_field);
len_offset = offset;
tag_length = tag_offset - saved_offset;
len_length = len_offset - tag_offset;
if (pc)
{
pi = proto_tree_add_text(tree, tvb, saved_offset,
len + (len_offset - saved_offset),
"CONSTRUCTOR");
subtree = proto_item_add_subtree(pi, ett_param);
proto_tree_add_uint_format(subtree, hf_tcap_tag, tvb,
saved_offset, tag_length, tag,
"CONSTRUCTOR Tag");
proto_tree_add_uint(subtree, hf_tcap_tag, tvb, saved_offset,
tag_length, ber_class);
proto_tree_add_uint(subtree, hf_tcap_length, tvb, tag_offset,
len_length, len);
if (len-(2*ind_field))
{
next_tvb = tvb_new_subset(tvb, offset, len-(2*ind_field),
len-(2*ind_field));
dissect_tcap_param(actx, subtree,next_tvb,0);
}
if (ind_field)
proto_tree_add_text(subtree, tvb, offset+len-2, 2, "CONSTRUCTOR EOC");
offset += len;
}
else
{
pi = proto_tree_add_text(tree, tvb, saved_offset,
len + (len_offset - saved_offset),
"Parameter (0x%.2x)", tag);
subtree = proto_item_add_subtree(pi, ett_param);
proto_tree_add_uint(subtree, hf_tcap_tag, tvb, saved_offset,
tag_length, tag);
proto_tree_add_uint(subtree, hf_tcap_length, tvb,
saved_offset+tag_length, len_length, len);
if (len)
{
next_tvb = tvb_new_subset(tvb, offset, len, len);
dissect_ber_octet_string(TRUE, actx, tree, next_tvb, 0,
hf_tcap_data, NULL);
}
offset += len;
}
}
return offset;
}
static void raz_tcap_private(struct tcap_private_t * p_tcap_private)
{
memset(p_tcap_private,0,sizeof(struct tcap_private_t) );
}
static int
dissect_tcap_ITU_ComponentPDU(gboolean implicit_tag _U_, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_, proto_tree *tree, int hf_index _U_)
{
dissector_handle_t subdissector_handle=NULL;
gboolean is_subdissector=FALSE;
struct tcaphash_context_t * p_tcap_context=NULL;
if ( gtcap_HandleSRT ) {
if (!tcap_subdissector_used) {
p_tcap_context=tcapsrt_call_matching(tvb, actx->pinfo, tcap_stat_tree, gp_tcapsrt_info);
tcap_subdissector_used=TRUE;
gp_tcap_context=p_tcap_context;
tcap_private.context=p_tcap_context;
}else{
p_tcap_context = gp_tcap_context;
tcap_private.context=p_tcap_context;
}
}
if (p_tcap_context) {
if (cur_oid) {
if (p_tcap_context->oid_present) {
if ( strncmp(p_tcap_context->oid, cur_oid, sizeof(p_tcap_context->oid))!=0) {
g_strlcpy(p_tcap_context->oid,cur_oid, sizeof(p_tcap_context->oid));
if ( (subdissector_handle = dissector_get_string_handle(ber_oid_dissector_table, cur_oid)) ) {
p_tcap_context->subdissector_handle=subdissector_handle;
p_tcap_context->subdissector_present=TRUE;
}
}
} else {
g_strlcpy(p_tcap_context->oid, cur_oid, sizeof(p_tcap_context->oid));
p_tcap_context->oid_present=TRUE;
if ( (subdissector_handle
= dissector_get_string_handle(ber_oid_dissector_table, cur_oid)) ) {
p_tcap_context->subdissector_handle=subdissector_handle;
p_tcap_context->subdissector_present=TRUE;
} else {
if ( (subdissector_handle = get_itu_tcap_subdissector(actx->pinfo->match_uint))) {
p_tcap_context->subdissector_handle=subdissector_handle;
p_tcap_context->subdissector_present=TRUE;
}
}
}
} else {
if (p_tcap_context->oid_present) {
tcap_private.oid= (void*) p_tcap_context->oid;
tcap_private.acv=TRUE;
}
}
}
if ( p_tcap_context
&& p_tcap_context->subdissector_present) {
subdissector_handle=p_tcap_context->subdissector_handle;
is_subdissector=TRUE;
}
if (!is_subdissector && requested_subdissector_handle) {
is_subdissector = TRUE;
subdissector_handle = requested_subdissector_handle;
}
if (!is_subdissector) {
if (ber_oid_dissector_table && cur_oid) {
if ( (subdissector_handle
= dissector_get_string_handle(ber_oid_dissector_table, cur_oid)) ) {
is_subdissector=TRUE;
} else {
if ( (subdissector_handle
= get_itu_tcap_subdissector(actx->pinfo->match_uint))) {
is_subdissector=TRUE;
} else {
subdissector_handle = data_handle;
is_subdissector=TRUE;
}
}
} else {
if ( (subdissector_handle = get_itu_tcap_subdissector(actx->pinfo->match_uint))) {
is_subdissector=TRUE;
} else {
subdissector_handle = data_handle;
is_subdissector=TRUE;
}
}
} else {
}
if (is_subdissector)
call_dissector(subdissector_handle, tvb, actx->pinfo, tree);
return offset;
}
void call_tcap_dissector(dissector_handle_t handle, tvbuff_t* tvb, packet_info* pinfo, proto_tree* tree) {
requested_subdissector_handle = handle;
TRY {
dissect_tcap(tvb, pinfo, tree);
} CATCH_ALL {
requested_subdissector_handle = NULL;
RETHROW;
} ENDTRY;
requested_subdissector_handle = NULL;
}
