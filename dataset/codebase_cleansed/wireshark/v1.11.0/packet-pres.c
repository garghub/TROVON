static guint
pres_ctx_oid_hash(gconstpointer k)
{
pres_ctx_oid_t *pco=(pres_ctx_oid_t *)k;
return pco->ctx_id;
}
static gint
pres_ctx_oid_equal(gconstpointer k1, gconstpointer k2)
{
pres_ctx_oid_t *pco1=(pres_ctx_oid_t *)k1;
pres_ctx_oid_t *pco2=(pres_ctx_oid_t *)k2;
return (pco1->ctx_id==pco2->ctx_id && pco1->index==pco2->index);
}
static void
pres_init(void)
{
if( pres_ctx_oid_table ){
g_hash_table_destroy(pres_ctx_oid_table);
pres_ctx_oid_table = NULL;
}
pres_ctx_oid_table = g_hash_table_new(pres_ctx_oid_hash,
pres_ctx_oid_equal);
}
static void
register_ctx_id_and_oid(packet_info *pinfo _U_, guint32 idx, const char *oid)
{
pres_ctx_oid_t *pco, *tmppco;
conversation_t *conversation;
if(!oid){
return;
}
pco=wmem_new(wmem_file_scope(), pres_ctx_oid_t);
pco->ctx_id=idx;
pco->oid=wmem_strdup(wmem_file_scope(), oid);
conversation=find_conversation (pinfo->fd->num, &pinfo->src, &pinfo->dst,
pinfo->ptype, pinfo->srcport, pinfo->destport, 0);
if (conversation) {
pco->index = conversation->index;
} else {
pco->index = 0;
}
tmppco=(pres_ctx_oid_t *)g_hash_table_lookup(pres_ctx_oid_table, pco);
if(tmppco){
g_hash_table_remove(pres_ctx_oid_table, tmppco);
}
g_hash_table_insert(pres_ctx_oid_table, pco, pco);
}
static char *
find_oid_in_users_table(packet_info *pinfo, guint32 ctx_id)
{
guint i;
for (i = 0; i < num_pres_users; i++) {
pres_user_t *u = &(pres_users[i]);
if (u->ctx_id == ctx_id) {
register_ctx_id_and_oid(pinfo, u->ctx_id, u->oid);
return u->oid;
}
}
return NULL;
}
char *
find_oid_by_pres_ctx_id(packet_info *pinfo, guint32 idx)
{
pres_ctx_oid_t pco, *tmppco;
conversation_t *conversation;
pco.ctx_id=idx;
conversation=find_conversation (pinfo->fd->num, &pinfo->src, &pinfo->dst,
pinfo->ptype, pinfo->srcport, pinfo->destport, 0);
if (conversation) {
pco.index = conversation->index;
} else {
pco.index = 0;
}
tmppco=(pres_ctx_oid_t *)g_hash_table_lookup(pres_ctx_oid_table, &pco);
if(tmppco){
return tmppco->oid;
}
return find_oid_in_users_table(pinfo, idx);
}
static void *
pres_copy_cb(void *dest, const void *orig, size_t len _U_)
{
pres_user_t *u = (pres_user_t *)dest;
const pres_user_t *o = (const pres_user_t *)orig;
u->ctx_id = o->ctx_id;
u->oid = g_strdup(o->oid);
return dest;
}
static void
pres_free_cb(void *r)
{
pres_user_t *u = (pres_user_t *)r;
g_free(u->oid);
}
static int
dissect_pres_T_mode_value(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_pres_Mode_selector(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
Mode_selector_set, hf_index, ett_pres_Mode_selector);
return offset;
}
static int
dissect_pres_Protocol_version(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
Protocol_version_bits, hf_index, ett_pres_Protocol_version,
NULL);
return offset;
}
static int
dissect_pres_Presentation_selector(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_pres_Calling_presentation_selector(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_pres_Presentation_selector(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_pres_Called_presentation_selector(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_pres_Presentation_selector(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_pres_Presentation_context_identifier(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 73 "../../asn1/pres/pres.cnf"
const char *name;
char *oid;
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
&presentation_context_identifier);
if(session)
session->pres_ctx_id = presentation_context_identifier;
oid = find_oid_by_pres_ctx_id(actx->pinfo, presentation_context_identifier);
if(oid && (name = oid_resolved_from_string(oid))) {
proto_item_append_text(actx->created_item, " (%s)", name);
}
return offset;
}
static int
dissect_pres_Abstract_syntax_name(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_object_identifier_str(implicit_tag, actx, tree, tvb, offset, hf_index, &abstract_syntax_name_oid);
return offset;
}
static int
dissect_pres_Transfer_syntax_name(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_object_identifier(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
return offset;
}
static int
dissect_pres_SEQUENCE_OF_Transfer_syntax_name(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_Transfer_syntax_name_sequence_of, hf_index, ett_pres_SEQUENCE_OF_Transfer_syntax_name);
return offset;
}
static int
dissect_pres_Context_list_item(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 98 "../../asn1/pres/pres.cnf"
abstract_syntax_name_oid=NULL;
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Context_list_item_sequence, hf_index, ett_pres_Context_list_item);
#line 101 "../../asn1/pres/pres.cnf"
register_ctx_id_and_oid(actx->pinfo, presentation_context_identifier, abstract_syntax_name_oid);
return offset;
}
static int
dissect_pres_Context_list(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
Context_list_sequence_of, hf_index, ett_pres_Context_list);
return offset;
}
static int
dissect_pres_Presentation_context_definition_list(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_pres_Context_list(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_pres_Default_context_name(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Default_context_name_sequence, hf_index, ett_pres_Default_context_name);
return offset;
}
static int
dissect_pres_Presentation_requirements(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
Presentation_requirements_bits, hf_index, ett_pres_Presentation_requirements,
NULL);
return offset;
}
static int
dissect_pres_User_session_requirements(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
User_session_requirements_bits, hf_index, ett_pres_User_session_requirements,
NULL);
return offset;
}
static int
dissect_pres_Protocol_options(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
Protocol_options_bits, hf_index, ett_pres_Protocol_options,
NULL);
return offset;
}
static int
dissect_pres_T_extensions(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_extensions_sequence, hf_index, ett_pres_T_extensions);
return offset;
}
static int
dissect_pres_Simply_encoded_data(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_pres_T_single_ASN1_type(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 37 "../../asn1/pres/pres.cnf"
tvbuff_t *next_tvb;
char *oid;
oid=find_oid_by_pres_ctx_id(actx->pinfo, presentation_context_identifier);
if(oid){
next_tvb = tvb_new_subset_remaining(tvb, offset);
call_ber_oid_callback(oid, next_tvb, offset, actx->pinfo, global_tree);
} else {
proto_tree_add_expert(tree, actx->pinfo, &ei_pres_dissector_not_available,
tvb, offset, -1);
}
return offset;
}
static int
dissect_pres_T_octet_aligned(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 51 "../../asn1/pres/pres.cnf"
tvbuff_t *next_tvb;
char *oid;
oid=find_oid_by_pres_ctx_id(actx->pinfo, presentation_context_identifier);
if(oid){
dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index, &next_tvb);
call_ber_oid_callback(oid, next_tvb, offset, actx->pinfo, global_tree);
} else {
proto_tree_add_expert(tree, actx->pinfo, &ei_pres_dissector_not_available,
tvb, offset, -1);
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
}
return offset;
}
static int
dissect_pres_BIT_STRING(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
NULL, hf_index, -1,
NULL);
return offset;
}
static int
dissect_pres_T_presentation_data_values(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_presentation_data_values_choice, hf_index, ett_pres_T_presentation_data_values,
NULL);
return offset;
}
static int
dissect_pres_PDV_list(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
PDV_list_sequence, hf_index, ett_pres_PDV_list);
return offset;
}
static int
dissect_pres_Fully_encoded_data(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
Fully_encoded_data_sequence_of, hf_index, ett_pres_Fully_encoded_data);
return offset;
}
static int
dissect_pres_User_data(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
User_data_choice, hf_index, ett_pres_User_data,
NULL);
return offset;
}
static int
dissect_pres_T_normal_mode_parameters(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_normal_mode_parameters_sequence, hf_index, ett_pres_T_normal_mode_parameters);
return offset;
}
static int
dissect_pres_CP_type(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
CP_type_set, hf_index, ett_pres_CP_type);
return offset;
}
static int
dissect_pres_CPC_type(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_pres_User_data(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_pres_Responding_presentation_selector(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_pres_Presentation_selector(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_pres_Result(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_pres_T_provider_reason(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_pres_Result_list_item(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Result_list_item_sequence, hf_index, ett_pres_Result_list_item);
return offset;
}
static int
dissect_pres_Result_list(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
Result_list_sequence_of, hf_index, ett_pres_Result_list);
return offset;
}
static int
dissect_pres_Presentation_context_definition_result_list(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_pres_Result_list(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_pres_T_CPA_PPDU_normal_mode_parameters(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_CPA_PPDU_normal_mode_parameters_sequence, hf_index, ett_pres_T_CPA_PPDU_normal_mode_parameters);
return offset;
}
static int
dissect_pres_CPA_PPDU(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
CPA_PPDU_set, hf_index, ett_pres_CPA_PPDU);
return offset;
}
static int
dissect_pres_Default_context_result(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_pres_Result(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_pres_Provider_reason(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_pres_T_CPR_PPDU_normal_mode_parameters(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_CPR_PPDU_normal_mode_parameters_sequence, hf_index, ett_pres_T_CPR_PPDU_normal_mode_parameters);
return offset;
}
static int
dissect_pres_CPR_PPDU(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
CPR_PPDU_choice, hf_index, ett_pres_CPR_PPDU,
NULL);
return offset;
}
static int
dissect_pres_Presentation_context_identifier_list_item(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Presentation_context_identifier_list_item_sequence, hf_index, ett_pres_Presentation_context_identifier_list_item);
return offset;
}
static int
dissect_pres_Presentation_context_identifier_list(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
Presentation_context_identifier_list_sequence_of, hf_index, ett_pres_Presentation_context_identifier_list);
return offset;
}
static int
dissect_pres_T_ARU_PPDU_normal_mode_parameters(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_ARU_PPDU_normal_mode_parameters_sequence, hf_index, ett_pres_T_ARU_PPDU_normal_mode_parameters);
return offset;
}
static int
dissect_pres_ARU_PPDU(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
ARU_PPDU_choice, hf_index, ett_pres_ARU_PPDU,
NULL);
return offset;
}
static int
dissect_pres_Abort_reason(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 91 "../../asn1/pres/pres.cnf"
guint32 reason;
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
&reason);
col_append_fstr(actx->pinfo->cinfo, COL_INFO, " (%s)", val_to_str(reason, pres_Abort_reason_vals, "unknown: %d"));
return offset;
}
static int
dissect_pres_Event_identifier(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_pres_ARP_PPDU(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ARP_PPDU_sequence, hf_index, ett_pres_ARP_PPDU);
return offset;
}
static int
dissect_pres_Abort_type(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
Abort_type_choice, hf_index, ett_pres_Abort_type,
NULL);
return offset;
}
static int
dissect_pres_Presentation_context_addition_list(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_pres_Context_list(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_pres_Presentation_context_deletion_list(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
Presentation_context_deletion_list_sequence_of, hf_index, ett_pres_Presentation_context_deletion_list);
return offset;
}
static int
dissect_pres_AC_PPDU(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
AC_PPDU_sequence, hf_index, ett_pres_AC_PPDU);
return offset;
}
static int
dissect_pres_Presentation_context_addition_result_list(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_pres_Result_list(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_pres_Presentation_context_deletion_result_list_item(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_pres_Presentation_context_deletion_result_list(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
Presentation_context_deletion_result_list_sequence_of, hf_index, ett_pres_Presentation_context_deletion_result_list);
return offset;
}
static int
dissect_pres_ACA_PPDU(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ACA_PPDU_sequence, hf_index, ett_pres_ACA_PPDU);
return offset;
}
static int
dissect_pres_Typed_data_type(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
Typed_data_type_choice, hf_index, ett_pres_Typed_data_type,
NULL);
return offset;
}
static int
dissect_pres_RS_PPDU(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
RS_PPDU_sequence, hf_index, ett_pres_RS_PPDU);
return offset;
}
static int
dissect_pres_RSA_PPDU(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
RSA_PPDU_sequence, hf_index, ett_pres_RSA_PPDU);
return offset;
}
static int
dissect_pres_UD_type(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
UD_type_sequence, hf_index, ett_pres_UD_type);
return offset;
}
static void dissect_UD_type_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_pres_UD_type(FALSE, tvb, 0, &asn1_ctx, tree, hf_pres_UD_type_PDU);
}
static int
dissect_ppdu(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti;
proto_tree *pres_tree = NULL;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
if( !pinfo->private_data ){
if(tree){
proto_tree_add_text(tree, tvb, offset, -1,
"Internal error:can't get spdu type from session dissector.");
return 0;
}
}else{
session = ( (struct SESSION_DATA_STRUCTURE*)(pinfo->private_data) );
if(session->spdu_type == 0 ){
if(tree){
proto_tree_add_text(tree, tvb, offset, -1,
"Internal error:wrong spdu type %x from session dissector.",session->spdu_type);
return 0;
}
}
}
col_add_str(pinfo->cinfo, COL_INFO,
val_to_str(session->spdu_type, ses_vals, "Unknown PPDU type (0x%02x)"));
if (tree){
ti = proto_tree_add_item(tree, proto_pres, tvb, offset, -1, ENC_NA);
pres_tree = proto_item_add_subtree(ti, ett_pres);
}
switch(session->spdu_type){
case SES_CONNECTION_REQUEST:
offset = dissect_pres_CP_type(FALSE, tvb, offset, &asn1_ctx, pres_tree, hf_pres_CP_type);
break;
case SES_CONNECTION_ACCEPT:
offset = dissect_pres_CPA_PPDU(FALSE, tvb, offset, &asn1_ctx, pres_tree, hf_pres_CPA_PPDU);
break;
case SES_ABORT:
case SES_ABORT_ACCEPT:
offset = dissect_pres_Abort_type(FALSE, tvb, offset, &asn1_ctx, pres_tree, hf_pres_Abort_type);
break;
case SES_DATA_TRANSFER:
offset = dissect_pres_CPC_type(FALSE, tvb, offset, &asn1_ctx, pres_tree, hf_pres_user_data);
break;
case SES_TYPED_DATA:
offset = dissect_pres_Typed_data_type(FALSE, tvb, offset, &asn1_ctx, pres_tree, hf_pres_Typed_data_type);
break;
case SES_RESYNCHRONIZE:
offset = dissect_pres_RS_PPDU(FALSE, tvb, offset, &asn1_ctx, pres_tree, -1);
break;
case SES_RESYNCHRONIZE_ACK:
offset = dissect_pres_RSA_PPDU(FALSE, tvb, offset, &asn1_ctx, pres_tree, -1);
break;
case SES_REFUSE:
offset = dissect_pres_CPR_PPDU(FALSE, tvb, offset, &asn1_ctx, pres_tree, hf_pres_CPR_PPDU);
break;
default:
offset = dissect_pres_CPC_type(FALSE, tvb, offset, &asn1_ctx, pres_tree, hf_pres_user_data);
break;
}
return offset;
}
static void
dissect_pres(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree)
{
int offset = 0, old_offset;
session = ((struct SESSION_DATA_STRUCTURE*)(pinfo->private_data));
if (!tvb_bytes_exist(tvb, 0, 4)){
if (session && session->spdu_type != SES_MAJOR_SYNC_POINT) {
proto_tree_add_text(parent_tree, tvb, offset,
tvb_reported_length_remaining(tvb,offset),"User data");
return;
}
}
global_tree = parent_tree;
global_pinfo = pinfo;
if(session && session->spdu_type == CLSES_UNIT_DATA)
{
proto_tree * clpres_tree = NULL;
proto_item *ti;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "CL-PRES");
col_clear(pinfo->cinfo, COL_INFO);
if (parent_tree)
{
ti = proto_tree_add_item(parent_tree, proto_clpres, tvb, offset, -1, ENC_NA);
clpres_tree = proto_item_add_subtree(ti, ett_pres);
}
dissect_UD_type_PDU(tvb, pinfo, clpres_tree);
return;
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "PRES");
col_clear(pinfo->cinfo, COL_INFO);
if (session && session->spdu_type == SES_MAJOR_SYNC_POINT) {
char *oid = find_oid_by_pres_ctx_id (pinfo, session->pres_ctx_id);
if (oid) {
call_ber_oid_callback (oid, tvb, offset, pinfo, parent_tree);
} else {
proto_tree_add_text(parent_tree, tvb, offset,
tvb_reported_length_remaining(tvb,offset),"User data");
}
return;
}
while (tvb_reported_length_remaining(tvb, offset) > 0){
old_offset = offset;
offset = dissect_ppdu(tvb, offset, pinfo, parent_tree);
if(offset <= old_offset){
proto_tree_add_text(parent_tree, tvb, offset, -1,"Invalid offset");
THROW(ReportedBoundsError);
}
}
}
void proto_register_pres(void) {
static hf_register_info hf[] = {
{ &hf_pres_CP_type,
{ "CP-type", "pres.cptype",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pres_CPA_PPDU,
{ "CPA-PPDU", "pres.cpapdu",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pres_Abort_type,
{ "Abort type", "pres.aborttype",
FT_UINT32, BASE_DEC, VALS(pres_Abort_type_vals), 0,
NULL, HFILL }},
{ &hf_pres_CPR_PPDU,
{ "CPR-PPDU", "pres.cprtype",
FT_UINT32, BASE_DEC, VALS(pres_CPR_PPDU_vals), 0,
NULL, HFILL }},
{ &hf_pres_Typed_data_type,
{ "Typed data type", "pres.Typed_data_type",
FT_UINT32, BASE_DEC, VALS(pres_Typed_data_type_vals), 0,
NULL, HFILL }},
#line 1 "../../asn1/pres/packet-pres-hfarr.c"
{ &hf_pres_UD_type_PDU,
{ "UD-type", "pres.UD_type_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pres_mode_selector,
{ "mode-selector", "pres.mode_selector_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pres_x410_mode_parameters,
{ "x410-mode-parameters", "pres.x410_mode_parameters_element",
FT_NONE, BASE_NONE, NULL, 0,
"RTORQapdu", HFILL }},
{ &hf_pres_normal_mode_parameters,
{ "normal-mode-parameters", "pres.normal_mode_parameters_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pres_protocol_version,
{ "protocol-version", "pres.protocol_version",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pres_calling_presentation_selector,
{ "calling-presentation-selector", "pres.calling_presentation_selector",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pres_called_presentation_selector,
{ "called-presentation-selector", "pres.called_presentation_selector",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pres_presentation_context_definition_list,
{ "presentation-context-definition-list", "pres.presentation_context_definition_list",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_pres_default_context_name,
{ "default-context-name", "pres.default_context_name_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pres_presentation_requirements,
{ "presentation-requirements", "pres.presentation_requirements",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pres_user_session_requirements,
{ "user-session-requirements", "pres.user_session_requirements",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pres_protocol_options,
{ "protocol-options", "pres.protocol_options",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pres_initiators_nominated_context,
{ "initiators-nominated-context", "pres.initiators_nominated_context",
FT_INT32, BASE_DEC, NULL, 0,
"Presentation_context_identifier", HFILL }},
{ &hf_pres_extensions,
{ "extensions", "pres.extensions_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pres_user_data,
{ "user-data", "pres.user_data",
FT_UINT32, BASE_DEC, VALS(pres_User_data_vals), 0,
NULL, HFILL }},
{ &hf_pres_cPR_PPDU_x400_mode_parameters,
{ "x410-mode-parameters", "pres.x410_mode_parameters_element",
FT_NONE, BASE_NONE, NULL, 0,
"RTOACapdu", HFILL }},
{ &hf_pres_cPU_PPDU_normal_mode_parameters,
{ "normal-mode-parameters", "pres.normal_mode_parameters_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_CPA_PPDU_normal_mode_parameters", HFILL }},
{ &hf_pres_responding_presentation_selector,
{ "responding-presentation-selector", "pres.responding_presentation_selector",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pres_presentation_context_definition_result_list,
{ "presentation-context-definition-result-list", "pres.presentation_context_definition_result_list",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_pres_responders_nominated_context,
{ "responders-nominated-context", "pres.responders_nominated_context",
FT_INT32, BASE_DEC, NULL, 0,
"Presentation_context_identifier", HFILL }},
{ &hf_pres_cPU_PPDU_x400_mode_parameters,
{ "x400-mode-parameters", "pres.x400_mode_parameters_element",
FT_NONE, BASE_NONE, NULL, 0,
"RTORJapdu", HFILL }},
{ &hf_pres_cPR_PPDU_normal_mode_parameters,
{ "normal-mode-parameters", "pres.normal_mode_parameters_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_CPR_PPDU_normal_mode_parameters", HFILL }},
{ &hf_pres_default_context_result,
{ "default-context-result", "pres.default_context_result",
FT_INT32, BASE_DEC, VALS(pres_Result_vals), 0,
NULL, HFILL }},
{ &hf_pres_cPR_PPDU__provider_reason,
{ "provider-reason", "pres.provider_reason",
FT_INT32, BASE_DEC, VALS(pres_Provider_reason_vals), 0,
NULL, HFILL }},
{ &hf_pres_aru_ppdu,
{ "aru-ppdu", "pres.aru_ppdu",
FT_UINT32, BASE_DEC, VALS(pres_ARU_PPDU_vals), 0,
NULL, HFILL }},
{ &hf_pres_arp_ppdu,
{ "arp-ppdu", "pres.arp_ppdu_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pres_aRU_PPDU_x400_mode_parameters,
{ "x400-mode-parameters", "pres.x400_mode_parameters_element",
FT_NONE, BASE_NONE, NULL, 0,
"RTABapdu", HFILL }},
{ &hf_pres_aRU_PPDU_normal_mode_parameters,
{ "normal-mode-parameters", "pres.normal_mode_parameters_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_ARU_PPDU_normal_mode_parameters", HFILL }},
{ &hf_pres_presentation_context_identifier_list,
{ "presentation-context-identifier-list", "pres.presentation_context_identifier_list",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_pres_aRU_PPDU_provider_reason,
{ "provider-reason", "pres.provider_reason",
FT_INT32, BASE_DEC, VALS(pres_Abort_reason_vals), 0,
"Abort_reason", HFILL }},
{ &hf_pres_event_identifier,
{ "event-identifier", "pres.event_identifier",
FT_INT32, BASE_DEC, VALS(pres_Event_identifier_vals), 0,
NULL, HFILL }},
{ &hf_pres_acPPDU,
{ "acPPDU", "pres.acPPDU_element",
FT_NONE, BASE_NONE, NULL, 0,
"AC_PPDU", HFILL }},
{ &hf_pres_acaPPDU,
{ "acaPPDU", "pres.acaPPDU_element",
FT_NONE, BASE_NONE, NULL, 0,
"ACA_PPDU", HFILL }},
{ &hf_pres_ttdPPDU,
{ "ttdPPDU", "pres.ttdPPDU",
FT_UINT32, BASE_DEC, VALS(pres_User_data_vals), 0,
"User_data", HFILL }},
{ &hf_pres_presentation_context_addition_list,
{ "presentation-context-addition-list", "pres.presentation_context_addition_list",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_pres_presentation_context_deletion_list,
{ "presentation-context-deletion-list", "pres.presentation_context_deletion_list",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_pres_presentation_context_addition_result_list,
{ "presentation-context-addition-result-list", "pres.presentation_context_addition_result_list",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_pres_presentation_context_deletion_result_list,
{ "presentation-context-deletion-result-list", "pres.presentation_context_deletion_result_list",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_pres_Context_list_item,
{ "Context-list item", "pres.Context_list_item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pres_presentation_context_identifier,
{ "presentation-context-identifier", "pres.presentation_context_identifier",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_pres_abstract_syntax_name,
{ "abstract-syntax-name", "pres.abstract_syntax_name",
FT_OID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pres_transfer_syntax_name_list,
{ "transfer-syntax-name-list", "pres.transfer_syntax_name_list",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_Transfer_syntax_name", HFILL }},
{ &hf_pres_transfer_syntax_name_list_item,
{ "Transfer-syntax-name", "pres.Transfer_syntax_name",
FT_OID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pres_transfer_syntax_name,
{ "transfer-syntax-name", "pres.transfer_syntax_name",
FT_OID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pres_mode_value,
{ "mode-value", "pres.mode_value",
FT_INT32, BASE_DEC, VALS(pres_T_mode_value_vals), 0,
NULL, HFILL }},
{ &hf_pres_Presentation_context_deletion_list_item,
{ "Presentation-context-identifier", "pres.Presentation_context_identifier",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_pres_Presentation_context_deletion_result_list_item,
{ "Presentation-context-deletion-result-list item", "pres.Presentation_context_deletion_result_list_item",
FT_INT32, BASE_DEC, VALS(pres_Presentation_context_deletion_result_list_item_vals), 0,
NULL, HFILL }},
{ &hf_pres_Presentation_context_identifier_list_item,
{ "Presentation-context-identifier-list item", "pres.Presentation_context_identifier_list_item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pres_Result_list_item,
{ "Result-list item", "pres.Result_list_item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pres_result,
{ "result", "pres.result",
FT_INT32, BASE_DEC, VALS(pres_Result_vals), 0,
NULL, HFILL }},
{ &hf_pres_provider_reason,
{ "provider-reason", "pres.provider_reason",
FT_INT32, BASE_DEC, VALS(pres_T_provider_reason_vals), 0,
NULL, HFILL }},
{ &hf_pres_simply_encoded_data,
{ "simply-encoded-data", "pres.simply_encoded_data",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pres_fully_encoded_data,
{ "fully-encoded-data", "pres.fully_encoded_data",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_pres_Fully_encoded_data_item,
{ "PDV-list", "pres.PDV_list_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pres_presentation_data_values,
{ "presentation-data-values", "pres.presentation_data_values",
FT_UINT32, BASE_DEC, VALS(pres_T_presentation_data_values_vals), 0,
NULL, HFILL }},
{ &hf_pres_single_ASN1_type,
{ "single-ASN1-type", "pres.single_ASN1_type_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pres_octet_aligned,
{ "octet-aligned", "pres.octet_aligned",
FT_BYTES, BASE_NONE, NULL, 0,
"T_octet_aligned", HFILL }},
{ &hf_pres_arbitrary,
{ "arbitrary", "pres.arbitrary",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING", HFILL }},
{ &hf_pres_Presentation_requirements_context_management,
{ "context-management", "pres.context-management",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_pres_Presentation_requirements_restoration,
{ "restoration", "pres.restoration",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_pres_Protocol_options_nominated_context,
{ "nominated-context", "pres.nominated-context",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_pres_Protocol_options_short_encoding,
{ "short-encoding", "pres.short-encoding",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_pres_Protocol_options_packed_encoding_rules,
{ "packed-encoding-rules", "pres.packed-encoding-rules",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_pres_Protocol_version_version_1,
{ "version-1", "pres.version-1",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_pres_User_session_requirements_half_duplex,
{ "half-duplex", "pres.half-duplex",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_pres_User_session_requirements_duplex,
{ "duplex", "pres.duplex",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_pres_User_session_requirements_expedited_data,
{ "expedited-data", "pres.expedited-data",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_pres_User_session_requirements_minor_synchronize,
{ "minor-synchronize", "pres.minor-synchronize",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_pres_User_session_requirements_major_synchronize,
{ "major-synchronize", "pres.major-synchronize",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_pres_User_session_requirements_resynchronize,
{ "resynchronize", "pres.resynchronize",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_pres_User_session_requirements_activity_management,
{ "activity-management", "pres.activity-management",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_pres_User_session_requirements_negotiated_release,
{ "negotiated-release", "pres.negotiated-release",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
{ &hf_pres_User_session_requirements_capability_data,
{ "capability-data", "pres.capability-data",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_pres_User_session_requirements_exceptions,
{ "exceptions", "pres.exceptions",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_pres_User_session_requirements_typed_data,
{ "typed-data", "pres.typed-data",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_pres_User_session_requirements_symmetric_synchronize,
{ "symmetric-synchronize", "pres.symmetric-synchronize",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_pres_User_session_requirements_data_separation,
{ "data-separation", "pres.data-separation",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
#line 398 "../../asn1/pres/packet-pres-template.c"
};
static gint *ett[] = {
&ett_pres,
#line 1 "../../asn1/pres/packet-pres-ettarr.c"
&ett_pres_CP_type,
&ett_pres_T_normal_mode_parameters,
&ett_pres_T_extensions,
&ett_pres_CPA_PPDU,
&ett_pres_T_CPA_PPDU_normal_mode_parameters,
&ett_pres_CPR_PPDU,
&ett_pres_T_CPR_PPDU_normal_mode_parameters,
&ett_pres_Abort_type,
&ett_pres_ARU_PPDU,
&ett_pres_T_ARU_PPDU_normal_mode_parameters,
&ett_pres_ARP_PPDU,
&ett_pres_Typed_data_type,
&ett_pres_AC_PPDU,
&ett_pres_ACA_PPDU,
&ett_pres_RS_PPDU,
&ett_pres_RSA_PPDU,
&ett_pres_Context_list,
&ett_pres_Context_list_item,
&ett_pres_SEQUENCE_OF_Transfer_syntax_name,
&ett_pres_Default_context_name,
&ett_pres_Mode_selector,
&ett_pres_Presentation_context_deletion_list,
&ett_pres_Presentation_context_deletion_result_list,
&ett_pres_Presentation_context_identifier_list,
&ett_pres_Presentation_context_identifier_list_item,
&ett_pres_Presentation_requirements,
&ett_pres_Protocol_options,
&ett_pres_Protocol_version,
&ett_pres_Result_list,
&ett_pres_Result_list_item,
&ett_pres_User_data,
&ett_pres_Fully_encoded_data,
&ett_pres_PDV_list,
&ett_pres_T_presentation_data_values,
&ett_pres_User_session_requirements,
&ett_pres_UD_type,
#line 404 "../../asn1/pres/packet-pres-template.c"
};
static ei_register_info ei[] = {
{ &ei_pres_dissector_not_available, { "pres.dissector_not_available", PI_UNDECODED, PI_WARN, "Dissector is not available", EXPFILL }},
};
static uat_field_t users_flds[] = {
UAT_FLD_DEC(pres_users,ctx_id,"Context Id","Presentation Context Identifier"),
UAT_FLD_CSTRING(pres_users,oid,"Syntax Name OID","Abstract Syntax Name (Object Identifier)"),
UAT_END_FIELDS
};
uat_t* users_uat = uat_new("PRES Users Context List",
sizeof(pres_user_t),
"pres_context_list",
TRUE,
(void**) &pres_users,
&num_pres_users,
UAT_AFFECTS_DISSECTION,
"ChPresContextList",
pres_copy_cb,
NULL,
pres_free_cb,
NULL,
users_flds);
expert_module_t* expert_pres;
module_t *pres_module;
proto_pres = proto_register_protocol(PNAME, PSNAME, PFNAME);
register_dissector("pres", dissect_pres, proto_pres);
proto_clpres = proto_register_protocol(CLPNAME, CLPSNAME, CLPFNAME);
proto_register_field_array(proto_pres, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_pres = expert_register_protocol(proto_pres);
expert_register_field_array(expert_pres, ei, array_length(ei));
register_init_routine(pres_init);
pres_module = prefs_register_protocol(proto_pres, NULL);
prefs_register_uat_preference(pres_module, "users_table", "Users Context List",
"A table that enumerates user protocols to be used against"
" specific presentation context identifiers",
users_uat);
}
void proto_reg_handoff_pres(void) {
}
