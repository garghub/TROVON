static void
ldapstat_init(struct register_srt* srt _U_, GArray* srt_array, srt_gui_init_cb gui_callback, void* gui_data)
{
srt_stat_table *ldap_srt_table;
guint32 i;
ldap_srt_table = init_srt_table("LDAP Commands", NULL, srt_array, LDAP_NUM_PROCEDURES, NULL, "ldap.protocolOp", gui_callback, gui_data, NULL);
for (i = 0; i < LDAP_NUM_PROCEDURES; i++)
{
init_srt_table_row(ldap_srt_table, i, val_to_str_const(i, ldap_procedure_names, "<unknown>"));
}
}
static int
ldapstat_packet(void *pldap, packet_info *pinfo, epan_dissect_t *edt _U_, const void *psi)
{
guint i = 0;
srt_stat_table *ldap_srt_table;
const ldap_call_response_t *ldap=(const ldap_call_response_t *)psi;
srt_data_t *data = (srt_data_t *)pldap;
if(ldap->is_request){
return 0;
}
if(!ldap->req_frame){
return 0;
}
switch(ldap->protocolOpTag){
case LDAP_REQ_BIND:
case LDAP_REQ_SEARCH:
case LDAP_REQ_MODIFY:
case LDAP_REQ_ADD:
case LDAP_REQ_DELETE:
case LDAP_REQ_MODRDN:
case LDAP_REQ_COMPARE:
case LDAP_REQ_EXTENDED:
break;
default:
return 0;
}
ldap_srt_table = g_array_index(data->srt_array, srt_stat_table*, i);
add_srt_table_data(ldap_srt_table, ldap->protocolOpTag, &ldap->req_time, pinfo);
return 1;
}
static guint
ldap_info_hash_matched(gconstpointer k)
{
const ldap_call_response_t *key = (const ldap_call_response_t *)k;
return key->messageId;
}
static gint
ldap_info_equal_matched(gconstpointer k1, gconstpointer k2)
{
const ldap_call_response_t *key1 = (const ldap_call_response_t*)k1;
const ldap_call_response_t *key2 = (const ldap_call_response_t*)k2;
if( key1->req_frame && key2->req_frame && (key1->req_frame!=key2->req_frame) ){
return 0;
}
return key1->messageId==key2->messageId;
}
static guint
ldap_info_hash_unmatched(gconstpointer k)
{
const ldap_call_response_t *key = (const ldap_call_response_t*)k;
return key->messageId;
}
static gint
ldap_info_equal_unmatched(gconstpointer k1, gconstpointer k2)
{
const ldap_call_response_t *key1 = (const ldap_call_response_t*)k1;
const ldap_call_response_t *key2 = (const ldap_call_response_t*)k2;
return key1->messageId==key2->messageId;
}
static gboolean
attribute_types_update_cb(void *r, char **err)
{
attribute_type_t *rec = (attribute_type_t *)r;
char c;
if (rec->attribute_type == NULL) {
*err = g_strdup("Attribute type can't be empty");
return FALSE;
}
g_strstrip(rec->attribute_type);
if (rec->attribute_type[0] == 0) {
*err = g_strdup("Attribute type can't be empty");
return FALSE;
}
c = proto_check_field_name(rec->attribute_type);
if (c) {
*err = g_strdup_printf("Attribute type can't contain '%c'", c);
return FALSE;
}
*err = NULL;
return TRUE;
}
static void *
attribute_types_copy_cb(void* n, const void* o, size_t siz _U_)
{
attribute_type_t* new_rec = (attribute_type_t*)n;
const attribute_type_t* old_rec = (const attribute_type_t*)o;
new_rec->attribute_type = g_strdup(old_rec->attribute_type);
new_rec->attribute_desc = g_strdup(old_rec->attribute_desc);
return new_rec;
}
static void
attribute_types_free_cb(void*r)
{
attribute_type_t* rec = (attribute_type_t*)r;
if (rec->attribute_type) g_free(rec->attribute_type);
if (rec->attribute_desc) g_free(rec->attribute_desc);
}
static gint*
get_hf_for_header(char* attribute_type)
{
gint* hf_id = NULL;
if (attribute_types_hash) {
hf_id = (gint*) g_hash_table_lookup(attribute_types_hash, attribute_type);
} else {
hf_id = NULL;
}
return hf_id;
}
static void
attribute_types_initialize_cb(void)
{
static hf_register_info* hf;
gint* hf_id;
guint i;
gchar* attribute_type;
if (attribute_types_hash && hf) {
guint hf_size = g_hash_table_size (attribute_types_hash);
for (i = 0; i < hf_size; i++) {
proto_deregister_field (proto_ldap, *(hf[i].p_id));
g_free (hf[i].p_id);
}
g_hash_table_destroy (attribute_types_hash);
proto_add_deregistered_data (hf);
attribute_types_hash = NULL;
}
if (num_attribute_types) {
attribute_types_hash = g_hash_table_new(g_str_hash, g_str_equal);
hf = g_new0(hf_register_info,num_attribute_types);
for (i = 0; i < num_attribute_types; i++) {
hf_id = g_new(gint,1);
*hf_id = -1;
attribute_type = g_strdup(attribute_types[i].attribute_type);
hf[i].p_id = hf_id;
hf[i].hfinfo.name = attribute_type;
hf[i].hfinfo.abbrev = g_strdup_printf("ldap.AttributeValue.%s", attribute_type);
hf[i].hfinfo.type = FT_STRING;
hf[i].hfinfo.display = BASE_NONE;
hf[i].hfinfo.strings = NULL;
hf[i].hfinfo.blurb = g_strdup(attribute_types[i].attribute_desc);
hf[i].hfinfo.same_name_prev_id = -1;
hf[i].hfinfo.same_name_next = NULL;
g_hash_table_insert(attribute_types_hash, attribute_type, hf_id);
}
proto_register_field_array(proto_ldap, hf, num_attribute_types);
}
}
static int dissect_mscldap_ntver_flags(proto_tree *parent_tree, tvbuff_t *tvb, int offset)
{
static const int * flags[] = {
&hf_mscldap_ntver_flags_v1,
&hf_mscldap_ntver_flags_v5,
&hf_mscldap_ntver_flags_v5ex,
&hf_mscldap_ntver_flags_v5ep,
&hf_mscldap_ntver_flags_vcs,
&hf_mscldap_ntver_flags_vnt4,
&hf_mscldap_ntver_flags_vpdc,
&hf_mscldap_ntver_flags_vip,
&hf_mscldap_ntver_flags_vl,
&hf_mscldap_ntver_flags_vgc,
NULL
};
proto_tree_add_bitmask_with_flags(parent_tree, tvb, offset, hf_mscldap_ntver_flags,
ett_mscldap_ntver_flags, flags, ENC_LITTLE_ENDIAN, BMT_NO_FALSE);
offset += 4;
return offset;
}
static int
dissect_ldap_AssertionValue(gboolean implicit_tag, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_, proto_tree *tree, int hf_index)
{
gint8 ber_class;
gboolean pc, ind, is_ascii;
gint32 tag;
guint32 len, i;
const guchar *str;
if(!implicit_tag){
offset=get_ber_identifier(tvb, offset, &ber_class, &pc, &tag);
offset=get_ber_length(tvb, offset, &len, &ind);
} else {
len=tvb_reported_length_remaining(tvb,offset);
}
if(len==0){
return offset;
}
if(attributedesc_string && !strncmp("DomainSid", attributedesc_string, 9)){
tvbuff_t *sid_tvb;
char *tmpstr;
sid_tvb=tvb_new_subset_length(tvb, offset, len);
dissect_nt_sid(sid_tvb, 0, tree, "SID", &tmpstr, hf_index);
ldapvalue_string=tmpstr;
goto finished;
} else if ( (len==16)
&& (attributedesc_string && !strncmp("DomainGuid", attributedesc_string, 10))) {
guint8 drep[4] = { 0x10, 0x00, 0x00, 0x00};
e_guid_t uuid;
dissect_dcerpc_uuid_t(tvb, offset, actx->pinfo, tree, drep, hf_ldap_guid, &uuid);
ldapvalue_string=(char*)wmem_alloc(wmem_packet_scope(), 1024);
g_snprintf(ldapvalue_string, 1023, "%08x-%04x-%04x-%02x%02x-%02x%02x%02x%02x%02x%02x",
uuid.data1, uuid.data2, uuid.data3,
uuid.data4[0], uuid.data4[1],
uuid.data4[2], uuid.data4[3],
uuid.data4[4], uuid.data4[5],
uuid.data4[6], uuid.data4[7]);
goto finished;
} else if (attributedesc_string && !strncmp("NtVer", attributedesc_string, 5)){
guint32 flags;
len = 0;
flags=tvb_get_letohl(tvb, offset);
ldapvalue_string=(char*)wmem_alloc(wmem_packet_scope(), 1024);
g_snprintf(ldapvalue_string, 1023, "0x%08x",flags);
offset = dissect_mscldap_ntver_flags(tree, tvb, offset);
goto finished;
}
str=tvb_get_ptr(tvb, offset, len);
is_ascii=TRUE;
for(i=0;i<len;i++){
if(!g_ascii_isprint(str[i])){
is_ascii=FALSE;
break;
}
}
if(is_ascii){
ldapvalue_string=wmem_strndup(wmem_packet_scope(), str, len);
} else {
ldapvalue_string=(char*)wmem_alloc(wmem_packet_scope(), 3*len);
for(i=0;i<len;i++){
g_snprintf(ldapvalue_string+i*3,3,"%02x",str[i]&0xff);
ldapvalue_string[3*i+2]=':';
}
ldapvalue_string[3*len-1]=0;
}
proto_tree_add_string(tree, hf_index, tvb, offset, len, ldapvalue_string);
finished:
offset+=len;
return offset;
}
static void ldap_do_protocolop(packet_info *pinfo)
{
const gchar* valstr;
if (do_protocolop) {
valstr = val_to_str(ProtocolOp, ldap_ProtocolOp_choice_vals, "Unknown (%%u)");
col_append_fstr(pinfo->cinfo, COL_INFO, "%s(%u) ", valstr, MessageID);
if(ldm_tree)
proto_item_append_text(ldm_tree, " %s(%d)", valstr, MessageID);
do_protocolop = FALSE;
}
}
static ldap_call_response_t *
ldap_match_call_response(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint messageId, guint protocolOpTag, ldap_conv_info_t *ldap_info)
{
ldap_call_response_t lcr, *lcrp=NULL;
lcr.messageId=messageId;
switch(protocolOpTag){
case LDAP_REQ_BIND:
case LDAP_REQ_SEARCH:
case LDAP_REQ_MODIFY:
case LDAP_REQ_ADD:
case LDAP_REQ_DELETE:
case LDAP_REQ_MODRDN:
case LDAP_REQ_COMPARE:
case LDAP_REQ_EXTENDED:
lcr.is_request=TRUE;
lcr.req_frame=pinfo->fd->num;
lcr.rep_frame=0;
break;
case LDAP_RES_BIND:
case LDAP_RES_SEARCH_ENTRY:
case LDAP_RES_SEARCH_REF:
case LDAP_RES_SEARCH_RESULT:
case LDAP_RES_MODIFY:
case LDAP_RES_ADD:
case LDAP_RES_DELETE:
case LDAP_RES_MODRDN:
case LDAP_RES_COMPARE:
case LDAP_RES_EXTENDED:
case LDAP_RES_INTERMEDIATE:
lcr.is_request=FALSE;
lcr.req_frame=0;
lcr.rep_frame=pinfo->fd->num;
break;
default:
return NULL;
}
lcrp=(ldap_call_response_t *)g_hash_table_lookup(ldap_info->matched, &lcr);
if(lcrp){
lcrp->is_request=lcr.is_request;
} else {
switch(protocolOpTag){
case LDAP_REQ_BIND:
case LDAP_REQ_SEARCH:
case LDAP_REQ_MODIFY:
case LDAP_REQ_ADD:
case LDAP_REQ_DELETE:
case LDAP_REQ_MODRDN:
case LDAP_REQ_COMPARE:
case LDAP_REQ_EXTENDED:
lcr.messageId=messageId;
lcrp=(ldap_call_response_t *)g_hash_table_lookup(ldap_info->unmatched, &lcr);
if(lcrp){
g_hash_table_remove(ldap_info->unmatched, lcrp);
}
if(!lcrp){
lcrp=wmem_new0(wmem_file_scope(), ldap_call_response_t);
}
lcrp->messageId=messageId;
lcrp->req_frame=pinfo->fd->num;
lcrp->req_time=pinfo->fd->abs_ts;
lcrp->rep_frame=0;
lcrp->protocolOpTag=protocolOpTag;
lcrp->is_request=TRUE;
g_hash_table_insert(ldap_info->unmatched, lcrp, lcrp);
return NULL;
break;
case LDAP_RES_BIND:
case LDAP_RES_SEARCH_ENTRY:
case LDAP_RES_SEARCH_REF:
case LDAP_RES_SEARCH_RESULT:
case LDAP_RES_MODIFY:
case LDAP_RES_ADD:
case LDAP_RES_DELETE:
case LDAP_RES_MODRDN:
case LDAP_RES_COMPARE:
case LDAP_RES_EXTENDED:
case LDAP_RES_INTERMEDIATE:
lcr.messageId=messageId;
lcrp=(ldap_call_response_t *)g_hash_table_lookup(ldap_info->unmatched, &lcr);
if(lcrp){
if(!lcrp->rep_frame){
g_hash_table_remove(ldap_info->unmatched, lcrp);
lcrp->rep_frame=pinfo->fd->num;
lcrp->is_request=FALSE;
g_hash_table_insert(ldap_info->matched, lcrp, lcrp);
}
}
break;
}
}
if(lcrp){
proto_item *it;
if(lcrp->is_request){
it=proto_tree_add_uint(tree, hf_ldap_response_in, tvb, 0, 0, lcrp->rep_frame);
PROTO_ITEM_SET_GENERATED(it);
} else {
nstime_t ns;
it=proto_tree_add_uint(tree, hf_ldap_response_to, tvb, 0, 0, lcrp->req_frame);
PROTO_ITEM_SET_GENERATED(it);
nstime_delta(&ns, &pinfo->fd->abs_ts, &lcrp->req_time);
it=proto_tree_add_time(tree, hf_ldap_time, tvb, 0, 0, &ns);
PROTO_ITEM_SET_GENERATED(it);
}
}
return lcrp;
}
static int
dissect_ldap_MessageID(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 90 "../../asn1/ldap/ldap.cnf"
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
&MessageID);
ldm_tree = tree;
return offset;
}
static int
dissect_ldap_INTEGER_1_127(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ldap_LDAPString(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 300 "../../asn1/ldap/ldap.cnf"
tvbuff_t *parameter_tvb = NULL;
const char *ldapstring = NULL;
gchar *sc = NULL;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (parameter_tvb || (hf_index == hf_ldap_baseObject)) {
ldap_do_protocolop(actx->pinfo);
if(parameter_tvb)
ldapstring = tvb_get_string_enc(wmem_packet_scope(), parameter_tvb, 0, tvb_reported_length_remaining(parameter_tvb, 0), ENC_UTF_8|ENC_NA);
if(hf_index == hf_ldap_baseObject) {
if(!ldapstring || !*ldapstring)
ldapstring = "<ROOT>";
col_append_fstr(actx->pinfo->cinfo, COL_INFO, "\"%s\" ", ldapstring);
if(ldm_tree)
proto_item_append_text(ldm_tree, " \"%s\"", ldapstring);
if(!parameter_tvb) {
proto_item_append_text(actx->created_item, " (%s)", ldapstring);
}
} else if ((hf_index == hf_ldap_errorMessage) && ldapstring && *ldapstring) {
col_append_fstr(actx->pinfo->cinfo, COL_INFO, "(%s) ", ldapstring);
if(ldm_tree)
proto_item_append_text(ldm_tree, " (%s)", ldapstring);
} else if ((hf_index == hf_ldap_objectName) ||
(hf_index == hf_ldap_name) ||
(hf_index == hf_ldap_entry) ||
(hf_index == hf_ldap_object) ||
(hf_index == hf_ldap_delRequest) ) {
if(!ldapstring || !*ldapstring)
ldapstring = "<ROOT>";
col_append_fstr(actx->pinfo->cinfo, COL_INFO, "\"%s\" ", ldapstring);
if(ldm_tree)
proto_item_append_text(ldm_tree, " \"%s\"", ldapstring);
} else if (hf_index == hf_ldap_attributeDesc){
attributedesc_string=ldapstring;
} else if (hf_index == hf_ldap_initial){
substring_item_init=ldapstring;
} else if (hf_index == hf_ldap_any){
substring_item_any=ldapstring;
} else if (hf_index == hf_ldap_final){
substring_item_final=ldapstring;
} else if (hf_index == hf_ldap_matchingRule){
matching_rule_string=ldapstring;
} else if (hf_index == hf_ldap_present){
Filter_string=ldapstring;
} else if (hf_index == hf_ldap_type) {
attr_type = wmem_strdup(wmem_packet_scope(), ldapstring);
proto_item_append_text(tree, " %s", attr_type);
if((sc = strchr(attr_type, ';')) != NULL) {
if(!strcmp(sc, ";binary")) {
*sc = '\0';
is_binary_attr_type = TRUE;
}
} else {
is_binary_attr_type = FALSE;
}
}
}
return offset;
}
static int
dissect_ldap_LDAPDN(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ldap_LDAPString(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_ldap_Simple(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 147 "../../asn1/ldap/ldap.cnf"
ldap_conv_info_t *ldap_info;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
ldap_info = (ldap_conv_info_t *)actx->private_data;
ldap_info->auth_type = LDAP_AUTH_SIMPLE;
return offset;
}
static int
dissect_ldap_Mechanism(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 155 "../../asn1/ldap/ldap.cnf"
ldap_conv_info_t *ldap_info;
tvbuff_t *parameter_tvb;
char *mechanism = NULL;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
ldap_info = (ldap_conv_info_t *)actx->private_data;
ldap_info->auth_type = LDAP_AUTH_SASL;
if (!parameter_tvb)
return offset;
if(!actx->pinfo->fd->flags.visited) {
mechanism = tvb_get_string_enc(NULL, parameter_tvb, 0, tvb_reported_length_remaining(parameter_tvb,0), ENC_UTF_8|ENC_NA);
ldap_info->first_auth_frame = 0;
if (mechanism != NULL) {
g_free(ldap_info->auth_mech);
ldap_info->auth_mech = mechanism;
}
}
return offset;
}
static int
dissect_ldap_Credentials(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 189 "../../asn1/ldap/ldap.cnf"
tvbuff_t *parameter_tvb;
ldap_conv_info_t *ldap_info;
gint8 ber_class;
gboolean pc;
gint32 tag;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (!parameter_tvb)
return offset;
ldap_info = (ldap_conv_info_t *)actx->private_data;
get_ber_identifier(parameter_tvb, 0, &ber_class, &pc, &tag);
if ((ldap_info->auth_mech != NULL) && (ber_class==BER_CLASS_CON)) {
if (parameter_tvb && (tvb_reported_length(parameter_tvb) > 0))
call_dissector(spnego_handle, parameter_tvb, actx->pinfo, tree);
}
if ((ldap_info->auth_mech != NULL) && (ber_class==BER_CLASS_APP)) {
if (parameter_tvb && (tvb_reported_length(parameter_tvb) > 0)) {
call_dissector(gssapi_handle, parameter_tvb, actx->pinfo, tree);
}
}
actx->private_data = ldap_info;
return offset;
}
static int
dissect_ldap_SaslCredentials(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
SaslCredentials_sequence, hf_index, ett_ldap_SaslCredentials);
return offset;
}
static int
dissect_ldap_T_ntlmsspNegotiate(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 689 "../../asn1/ldap/ldap.cnf"
ldap_do_protocolop(actx->pinfo);
call_dissector(ntlmssp_handle, tvb, actx->pinfo, tree);
offset+=tvb_reported_length_remaining(tvb, offset);
return offset;
}
static int
dissect_ldap_T_ntlmsspAuth(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 696 "../../asn1/ldap/ldap.cnf"
ldap_do_protocolop(actx->pinfo);
call_dissector(ntlmssp_handle, tvb, actx->pinfo, tree);
offset+=tvb_reported_length_remaining(tvb, offset);
return offset;
}
static int
dissect_ldap_AuthenticationChoice(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 486 "../../asn1/ldap/ldap.cnf"
gint branch = -1;
gint auth = -1;
const gchar *valstr;
offset = dissect_ber_choice(actx, tree, tvb, offset,
AuthenticationChoice_choice, hf_index, ett_ldap_AuthenticationChoice,
&branch);
ldap_do_protocolop(actx->pinfo);
if((branch > -1) && (branch < (gint)(sizeof AuthenticationChoice_choice/sizeof AuthenticationChoice_choice[0])))
auth = AuthenticationChoice_choice[branch].value;
valstr = val_to_str(auth, ldap_AuthenticationChoice_vals, "Unknown auth(%u)");
if ((auth != 10) && (auth != 11))
col_append_fstr(actx->pinfo->cinfo, COL_INFO, "%s ", valstr);
if(ldm_tree)
proto_item_append_text(ldm_tree, " %s", valstr);
return offset;
}
static int
dissect_ldap_BindRequest_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
BindRequest_U_sequence, hf_index, ett_ldap_BindRequest_U);
return offset;
}
static int
dissect_ldap_BindRequest(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_APP, 0, TRUE, dissect_ldap_BindRequest_U);
return offset;
}
static int
dissect_ldap_BindResponse_resultCode(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 420 "../../asn1/ldap/ldap.cnf"
const gchar *valstr;
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
&result);
ldap_do_protocolop(actx->pinfo);
valstr = val_to_str(result, ldap_BindResponse_resultCode_vals, "Unknown result(%u)");
col_append_fstr(actx->pinfo->cinfo, COL_INFO, "%s ", valstr);
if(ldm_tree)
proto_item_append_text(ldm_tree, " %s", valstr);
return offset;
}
static int
dissect_ldap_T_bindResponse_matchedDN(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 703 "../../asn1/ldap/ldap.cnf"
tvbuff_t *new_tvb=NULL;
offset = dissect_ber_octet_string(FALSE, actx, tree, tvb, offset, hf_ldap_matchedDN, &new_tvb);
if( new_tvb
&& (tvb_reported_length(new_tvb)>=7)
&& (!tvb_memeql(new_tvb, 0, "NTLMSSP", 7))){
ldap_do_protocolop(actx->pinfo);
call_dissector(ntlmssp_handle, new_tvb, actx->pinfo, tree);
}
return offset;
return offset;
}
static int
dissect_ldap_ErrorMessage(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ldap_LDAPString(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_ldap_LDAPURL(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
#line 53 "../../asn1/ldap/ldap.cnf"
PROTO_ITEM_SET_URL(actx->created_item);
return offset;
}
static int
dissect_ldap_Referral(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
Referral_sequence_of, hf_index, ett_ldap_Referral);
return offset;
}
static int
dissect_ldap_ServerSaslCreds(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 230 "../../asn1/ldap/ldap.cnf"
tvbuff_t *parameter_tvb = NULL;
ldap_conv_info_t *ldap_info;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (!parameter_tvb)
return offset;
ldap_info = (ldap_conv_info_t *)actx->private_data;
switch (ldap_info->auth_type) {
case LDAP_AUTH_SASL:
ldap_info->first_auth_frame = actx->pinfo->fd->num + 1;
if (ldap_info->auth_mech != NULL &&
strcmp(ldap_info->auth_mech, "GSS-SPNEGO") == 0) {
if ( (tvb_reported_length(parameter_tvb)>=7)
&& (!tvb_memeql(parameter_tvb, 0, "NTLMSSP", 7))){
call_dissector(ntlmssp_handle, parameter_tvb, actx->pinfo, tree);
break;
}
if(parameter_tvb && (tvb_reported_length(parameter_tvb) > 0))
call_dissector(spnego_handle, parameter_tvb, actx->pinfo, tree);
} else if (ldap_info->auth_mech != NULL &&
strcmp(ldap_info->auth_mech, "GSSAPI") == 0) {
if(parameter_tvb && (tvb_reported_length(parameter_tvb) > 0))
call_dissector(gssapi_handle, parameter_tvb, actx->pinfo, tree);
}
break;
}
actx->private_data = ldap_info;
return offset;
}
static int
dissect_ldap_BindResponse_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
BindResponse_U_sequence, hf_index, ett_ldap_BindResponse_U);
return offset;
}
static int
dissect_ldap_BindResponse(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_APP, 1, TRUE, dissect_ldap_BindResponse_U);
return offset;
}
static int
dissect_ldap_NULL(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_null(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_ldap_UnbindRequest(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 508 "../../asn1/ldap/ldap.cnf"
implicit_tag = TRUE;
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_APP, 2, TRUE, dissect_ldap_NULL);
ldap_do_protocolop(actx->pinfo);
return offset;
}
static int
dissect_ldap_T_scope(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 388 "../../asn1/ldap/ldap.cnf"
guint32 scope = 0xffff;
const gchar *valstr;
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
&scope);
ldap_do_protocolop(actx->pinfo);
valstr = val_to_str(scope, ldap_T_scope_vals, "Unknown scope(%u)");
col_append_fstr(actx->pinfo->cinfo, COL_INFO, "%s ", valstr);
if(ldm_tree)
proto_item_append_text(ldm_tree, " %s", valstr);
return offset;
}
static int
dissect_ldap_T_derefAliases(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ldap_INTEGER_0_maxInt(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ldap_BOOLEAN(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_boolean(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
return offset;
}
static int
dissect_ldap_T_and_item(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ldap_Filter(implicit_tag, tvb, offset, actx, tree, hf_index);
#line 554 "../../asn1/ldap/ldap.cnf"
if(and_filter_string){
and_filter_string=wmem_strdup_printf(wmem_packet_scope(), "(&%s%s)",and_filter_string,Filter_string);
} else {
and_filter_string=Filter_string;
}
return offset;
}
static int
dissect_ldap_T_and(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 561 "../../asn1/ldap/ldap.cnf"
proto_tree *tr=NULL;
proto_item *it=NULL;
const char *old_and_filter_string=and_filter_string;
and_filter_string=NULL;
tr=proto_tree_add_subtree(tree, tvb, offset, -1, ett_ldap_T_and, &it, "and: ");
tree = tr;
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
T_and_set_of, hf_index, ett_ldap_T_and);
if(and_filter_string) {
proto_item_append_text(it, "%s", and_filter_string);
Filter_string=wmem_strdup_printf(wmem_packet_scope(), "%s",and_filter_string);
}
and_filter_string=old_and_filter_string;
return offset;
}
static int
dissect_ldap_T_or_item(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ldap_Filter(implicit_tag, tvb, offset, actx, tree, hf_index);
#line 579 "../../asn1/ldap/ldap.cnf"
if(or_filter_string){
or_filter_string=wmem_strdup_printf(wmem_packet_scope(), "(|%s%s)",or_filter_string,Filter_string);
} else {
or_filter_string=Filter_string;
}
return offset;
}
static int
dissect_ldap_T_or(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 587 "../../asn1/ldap/ldap.cnf"
proto_tree *tr;
proto_item *it;
const char *old_or_filter_string=or_filter_string;
or_filter_string=NULL;
tr=proto_tree_add_subtree(tree, tvb, offset, -1, ett_ldap_T_or, &it, "or: ");
tree = tr;
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
T_or_set_of, hf_index, ett_ldap_T_or);
if(or_filter_string) {
proto_item_append_text(it, "%s", or_filter_string);
Filter_string=wmem_strdup_printf(wmem_packet_scope(), "%s",or_filter_string);
}
or_filter_string=old_or_filter_string;
return offset;
}
static int
dissect_ldap_T_not(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ldap_Filter(implicit_tag, tvb, offset, actx, tree, hf_index);
#line 606 "../../asn1/ldap/ldap.cnf"
Filter_string=wmem_strdup_printf(wmem_packet_scope(), "(!%s)",string_or_null(Filter_string));
return offset;
}
static int
dissect_ldap_AttributeDescription(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ldap_LDAPString(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_ldap_AttributeValueAssertion(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
AttributeValueAssertion_sequence, hf_index, ett_ldap_AttributeValueAssertion);
return offset;
}
static int
dissect_ldap_T_equalityMatch(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ldap_AttributeValueAssertion(implicit_tag, tvb, offset, actx, tree, hf_index);
#line 531 "../../asn1/ldap/ldap.cnf"
Filter_string=wmem_strdup_printf(wmem_packet_scope(), "(%s=%s)",
string_or_null(attributedesc_string),
string_or_null(ldapvalue_string));
return offset;
}
static int
dissect_ldap_T_substringFilter_substrings_item(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_substringFilter_substrings_item_choice, hf_index, ett_ldap_T_substringFilter_substrings_item,
NULL);
#line 632 "../../asn1/ldap/ldap.cnf"
if (substring_item_final) {
substring_value=wmem_strdup_printf(wmem_packet_scope(), "%s%s",
(substring_value?substring_value:"*"),
substring_item_final);
} else if (substring_item_any) {
substring_value=wmem_strdup_printf(wmem_packet_scope(), "%s%s*",
(substring_value?substring_value:"*"),
substring_item_any);
} else if (substring_item_init) {
substring_value=wmem_strdup_printf(wmem_packet_scope(), "%s*",
substring_item_init);
}
return offset;
}
static int
dissect_ldap_T_substringFilter_substrings(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
T_substringFilter_substrings_sequence_of, hf_index, ett_ldap_T_substringFilter_substrings);
return offset;
}
static int
dissect_ldap_SubstringFilter(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 646 "../../asn1/ldap/ldap.cnf"
proto_tree *tr;
proto_item *it;
const char *old_substring_value=substring_value;
attr_type=NULL;
substring_value=NULL;
substring_item_init=NULL;
substring_item_any=NULL;
substring_item_final=NULL;
tr=proto_tree_add_subtree(tree, tvb, offset, -1, ett_ldap_SubstringFilter, &it, "substring: ");
tree = tr;
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
SubstringFilter_sequence, hf_index, ett_ldap_SubstringFilter);
Filter_string=wmem_strdup_printf(wmem_packet_scope(), "(%s=%s)",
string_or_null(attr_type),
string_or_null(substring_value));
proto_item_append_text(it, "%s", Filter_string);
substring_value=old_substring_value;
return offset;
}
static int
dissect_ldap_T_greaterOrEqual(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ldap_AttributeValueAssertion(implicit_tag, tvb, offset, actx, tree, hf_index);
#line 537 "../../asn1/ldap/ldap.cnf"
Filter_string=wmem_strdup_printf(wmem_packet_scope(), "(%s>=%s)",
string_or_null(attributedesc_string),
string_or_null(ldapvalue_string));
return offset;
}
static int
dissect_ldap_T_lessOrEqual(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ldap_AttributeValueAssertion(implicit_tag, tvb, offset, actx, tree, hf_index);
#line 543 "../../asn1/ldap/ldap.cnf"
Filter_string=wmem_strdup_printf(wmem_packet_scope(), "(%s<=%s)",
string_or_null(attributedesc_string),
string_or_null(ldapvalue_string));
return offset;
}
static int
dissect_ldap_T_present(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ldap_AttributeDescription(implicit_tag, tvb, offset, actx, tree, hf_index);
#line 603 "../../asn1/ldap/ldap.cnf"
Filter_string=wmem_strdup_printf(wmem_packet_scope(), "(%s=*)",string_or_null(Filter_string));
return offset;
}
static int
dissect_ldap_T_approxMatch(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ldap_AttributeValueAssertion(implicit_tag, tvb, offset, actx, tree, hf_index);
#line 549 "../../asn1/ldap/ldap.cnf"
Filter_string=wmem_strdup_printf(wmem_packet_scope(), "(%s~=%s)",
string_or_null(attributedesc_string),
string_or_null(ldapvalue_string));
return offset;
}
static int
dissect_ldap_MatchingRuleId(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ldap_LDAPString(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_ldap_T_dnAttributes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 609 "../../asn1/ldap/ldap.cnf"
gboolean val;
offset = dissect_ber_boolean(implicit_tag, actx, tree, tvb, offset, hf_index, &val);
matching_rule_dnattr = val;
return offset;
}
static int
dissect_ldap_MatchingRuleAssertion(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
MatchingRuleAssertion_sequence, hf_index, ett_ldap_MatchingRuleAssertion);
return offset;
}
static int
dissect_ldap_T_extensibleMatch(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 618 "../../asn1/ldap/ldap.cnf"
attr_type=NULL;
matching_rule_string=NULL;
ldapvalue_string=NULL;
matching_rule_dnattr=FALSE;
offset = dissect_ldap_MatchingRuleAssertion(implicit_tag, tvb, offset, actx, tree, hf_index);
#line 624 "../../asn1/ldap/ldap.cnf"
Filter_string=wmem_strdup_printf(wmem_packet_scope(), "(%s:%s%s%s=%s)",
(attr_type?attr_type:""),
(matching_rule_dnattr?"dn:":""),
(matching_rule_string?matching_rule_string:""),
(matching_rule_string?":":""),
string_or_null(ldapvalue_string));
return offset;
}
static int
dissect_ldap_Filter(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 667 "../../asn1/ldap/ldap.cnf"
proto_tree *tr;
proto_item *it;
attributedesc_string=NULL;
if (Filter_length++ > MAX_FILTER_LEN) {
expert_add_info_format(actx->pinfo, tree, &ei_ldap_exceeded_filter_length, "Filter length exceeds %u. Giving up.", MAX_FILTER_LEN);
THROW(ReportedBoundsError);
}
if (Filter_elements++ > MAX_FILTER_ELEMENTS) {
expert_add_info_format(actx->pinfo, tree, &ei_ldap_too_many_filter_elements, "Found more than %u filter elements. Giving up.", MAX_FILTER_ELEMENTS);
THROW(ReportedBoundsError);
}
tr=proto_tree_add_subtree(tree, tvb, offset, -1, ett_ldap_Filter, &it, "Filter: ");
tree = tr;
offset = dissect_ber_choice(actx, tree, tvb, offset,
Filter_choice, hf_index, ett_ldap_Filter,
NULL);
if(Filter_string)
proto_item_append_text(it, "%s", string_or_null(Filter_string));
return offset;
}
static int
dissect_ldap_T_filter(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 520 "../../asn1/ldap/ldap.cnf"
Filter_string=NULL;
Filter_elements = 0;
Filter_length = 0;
offset = dissect_ldap_Filter(implicit_tag, tvb, offset, actx, tree, hf_index);
#line 525 "../../asn1/ldap/ldap.cnf"
Filter_string=NULL;
and_filter_string=NULL;
Filter_elements = 0;
Filter_length = 0;
return offset;
}
static int
dissect_ldap_AttributeDescriptionList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
AttributeDescriptionList_sequence_of, hf_index, ett_ldap_AttributeDescriptionList);
return offset;
}
static int
dissect_ldap_SearchRequest_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
SearchRequest_U_sequence, hf_index, ett_ldap_SearchRequest_U);
return offset;
}
static int
dissect_ldap_SearchRequest(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_APP, 3, TRUE, dissect_ldap_SearchRequest_U);
return offset;
}
static int
dissect_ldap_AttributeValue(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 450 "../../asn1/ldap/ldap.cnf"
tvbuff_t *next_tvb = NULL;
gchar *string;
guint32 i, len;
int old_offset = offset;
gint *hf_id;
offset = dissect_ber_octet_string(FALSE, actx, NULL, tvb, offset, hf_index, &next_tvb);
if ((hf_id = get_hf_for_header (attr_type)) != NULL)
proto_tree_add_item (tree, *hf_id, next_tvb, 0, tvb_reported_length_remaining(next_tvb, 0), ENC_UTF_8|ENC_NA);
else if(!attr_type || !next_tvb || !dissector_try_string(ldap_name_dissector_table, attr_type, next_tvb, actx->pinfo, tree, NULL)) {
offset = old_offset;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
len = tvb_reported_length_remaining(next_tvb, 0);
for(i = 0; i < len; i++)
if(!g_ascii_isprint(tvb_get_guint8(next_tvb, i)))
break;
if(i == len) {
string = tvb_get_string_enc(wmem_packet_scope(), next_tvb, 0, tvb_reported_length_remaining(next_tvb, 0), ENC_ASCII|ENC_NA);
proto_item_set_text(actx->created_item, "AttributeValue: %s", string);
}
}
return offset;
}
static int
dissect_ldap_SET_OF_AttributeValue(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
SET_OF_AttributeValue_set_of, hf_index, ett_ldap_SET_OF_AttributeValue);
return offset;
}
static int
dissect_ldap_PartialAttributeList_item(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
PartialAttributeList_item_sequence, hf_index, ett_ldap_PartialAttributeList_item);
return offset;
}
static int
dissect_ldap_PartialAttributeList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
PartialAttributeList_sequence_of, hf_index, ett_ldap_PartialAttributeList);
return offset;
}
static int
dissect_ldap_SearchResultEntry_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
SearchResultEntry_U_sequence, hf_index, ett_ldap_SearchResultEntry_U);
return offset;
}
static int
dissect_ldap_SearchResultEntry(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_APP, 4, TRUE, dissect_ldap_SearchResultEntry_U);
return offset;
}
static int
dissect_ldap_T_resultCode(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 404 "../../asn1/ldap/ldap.cnf"
const gchar *valstr;
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
&result);
ldap_do_protocolop(actx->pinfo);
valstr = val_to_str(result, ldap_T_resultCode_vals, "Unknown result(%u)");
col_append_fstr(actx->pinfo->cinfo, COL_INFO, "%s ", valstr);
if(ldm_tree)
proto_item_append_text(ldm_tree, " %s", valstr);
return offset;
}
static int
dissect_ldap_LDAPResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
LDAPResult_sequence, hf_index, ett_ldap_LDAPResult);
return offset;
}
static int
dissect_ldap_SearchResultDone(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_APP, 5, TRUE, dissect_ldap_LDAPResult);
return offset;
}
static int
dissect_ldap_SEQUENCE_OF_LDAPURL(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_LDAPURL_sequence_of, hf_index, ett_ldap_SEQUENCE_OF_LDAPURL);
return offset;
}
static int
dissect_ldap_SearchResultReference(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 796 "../../asn1/ldap/ldap.cnf"
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_APP, 19, TRUE, dissect_ldap_SEQUENCE_OF_LDAPURL);
ldap_do_protocolop(actx->pinfo);
return offset;
}
static int
dissect_ldap_T_operation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ldap_AttributeTypeAndValues(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
AttributeTypeAndValues_sequence, hf_index, ett_ldap_AttributeTypeAndValues);
return offset;
}
static int
dissect_ldap_T_modifyRequest_modification_item(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_modifyRequest_modification_item_sequence, hf_index, ett_ldap_T_modifyRequest_modification_item);
return offset;
}
static int
dissect_ldap_ModifyRequest_modification(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
ModifyRequest_modification_sequence_of, hf_index, ett_ldap_ModifyRequest_modification);
return offset;
}
static int
dissect_ldap_ModifyRequest_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ModifyRequest_U_sequence, hf_index, ett_ldap_ModifyRequest_U);
return offset;
}
static int
dissect_ldap_ModifyRequest(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_APP, 6, TRUE, dissect_ldap_ModifyRequest_U);
return offset;
}
static int
dissect_ldap_ModifyResponse(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_APP, 7, TRUE, dissect_ldap_LDAPResult);
return offset;
}
static int
dissect_ldap_AttributeList_item(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
AttributeList_item_sequence, hf_index, ett_ldap_AttributeList_item);
return offset;
}
static int
dissect_ldap_AttributeList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
AttributeList_sequence_of, hf_index, ett_ldap_AttributeList);
return offset;
}
static int
dissect_ldap_AddRequest_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
AddRequest_U_sequence, hf_index, ett_ldap_AddRequest_U);
return offset;
}
static int
dissect_ldap_AddRequest(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_APP, 8, TRUE, dissect_ldap_AddRequest_U);
return offset;
}
static int
dissect_ldap_AddResponse(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_APP, 9, TRUE, dissect_ldap_LDAPResult);
return offset;
}
static int
dissect_ldap_DelRequest(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_APP, 10, TRUE, dissect_ldap_LDAPDN);
return offset;
}
static int
dissect_ldap_DelResponse(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_APP, 11, TRUE, dissect_ldap_LDAPResult);
return offset;
}
static int
dissect_ldap_RelativeLDAPDN(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ldap_LDAPString(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_ldap_ModifyDNRequest_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ModifyDNRequest_U_sequence, hf_index, ett_ldap_ModifyDNRequest_U);
return offset;
}
static int
dissect_ldap_ModifyDNRequest(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_APP, 12, TRUE, dissect_ldap_ModifyDNRequest_U);
return offset;
}
static int
dissect_ldap_ModifyDNResponse(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_APP, 13, TRUE, dissect_ldap_LDAPResult);
return offset;
}
static int
dissect_ldap_CompareRequest_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
CompareRequest_U_sequence, hf_index, ett_ldap_CompareRequest_U);
return offset;
}
static int
dissect_ldap_CompareRequest(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_APP, 14, TRUE, dissect_ldap_CompareRequest_U);
return offset;
}
static int
dissect_ldap_CompareResponse(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_APP, 15, TRUE, dissect_ldap_LDAPResult);
return offset;
}
static int
dissect_ldap_AbandonRequest(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 803 "../../asn1/ldap/ldap.cnf"
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_APP, 16, TRUE, dissect_ldap_MessageID);
ldap_do_protocolop(actx->pinfo);
return offset;
}
static int
dissect_ldap_LDAPOID(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 56 "../../asn1/ldap/ldap.cnf"
tvbuff_t *parameter_tvb;
const gchar *name;
ldap_conv_info_t *ldap_info = (ldap_conv_info_t *)actx->private_data;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
#line 64 "../../asn1/ldap/ldap.cnf"
object_identifier_id = NULL;
if (!parameter_tvb)
return offset;
object_identifier_id = tvb_get_string_enc(wmem_packet_scope(), parameter_tvb, 0, tvb_reported_length_remaining(parameter_tvb,0), ENC_UTF_8|ENC_NA);
name = oid_resolved_from_string(wmem_packet_scope(), object_identifier_id);
if(name){
proto_item_append_text(actx->created_item, " (%s)", name);
if((hf_index == hf_ldap_requestName) || (hf_index == hf_ldap_responseName)) {
ldap_do_protocolop(actx->pinfo);
col_append_fstr(actx->pinfo->cinfo, COL_INFO, "%s ", name);
}
}
if (ldap_info && hf_index == hf_ldap_requestName &&
!strcmp(object_identifier_id, "1.3.6.1.4.1.1466.20037")) {
ldap_info->start_tls_pending = TRUE;
}
return offset;
}
static int
dissect_ldap_T_requestValue(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 738 "../../asn1/ldap/ldap.cnf"
if((object_identifier_id != NULL) && oid_has_dissector(object_identifier_id)) {
offset = call_ber_oid_callback(object_identifier_id, tvb, offset, actx->pinfo, tree, NULL);
} else {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
}
return offset;
}
static int
dissect_ldap_ExtendedRequest_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ExtendedRequest_U_sequence, hf_index, ett_ldap_ExtendedRequest_U);
return offset;
}
static int
dissect_ldap_ExtendedRequest(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_APP, 23, TRUE, dissect_ldap_ExtendedRequest_U);
return offset;
}
static int
dissect_ldap_ExtendedResponse_resultCode(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 435 "../../asn1/ldap/ldap.cnf"
guint32 resultCode;
ldap_conv_info_t *ldap_info = (ldap_conv_info_t *)actx->private_data;
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
&resultCode);
if (ldap_info && ldap_info->start_tls_pending &&
hf_index == hf_ldap_extendedResponse_resultCode && resultCode == 0) {
ssl_starttls_ack(find_dissector("ssl"), actx->pinfo, ldap_handle);
ldap_info->start_tls_pending = FALSE;
}
return offset;
}
static int
dissect_ldap_ResponseName(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ldap_LDAPOID(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_ldap_OCTET_STRING(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ldap_ExtendedResponse_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ExtendedResponse_U_sequence, hf_index, ett_ldap_ExtendedResponse_U);
return offset;
}
static int
dissect_ldap_ExtendedResponse(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_APP, 24, TRUE, dissect_ldap_ExtendedResponse_U);
return offset;
}
static int
dissect_ldap_T_intermediateResponse_responseValue(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 746 "../../asn1/ldap/ldap.cnf"
const gchar *name;
#line 750 "../../asn1/ldap/ldap.cnf"
if(ldm_tree && object_identifier_id) {
proto_item_set_text(ldm_tree, "%s %s", "IntermediateResponse", object_identifier_id);
name = oid_resolved_from_string(wmem_packet_scope(), object_identifier_id);
if(name)
proto_item_append_text(ldm_tree, " (%s)", name);
}
if((object_identifier_id != NULL) && oid_has_dissector(object_identifier_id)) {
offset = call_ber_oid_callback(object_identifier_id, tvb, offset, actx->pinfo, tree, NULL);
} else {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
}
return offset;
}
static int
dissect_ldap_IntermediateResponse_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
IntermediateResponse_U_sequence, hf_index, ett_ldap_IntermediateResponse_U);
return offset;
}
static int
dissect_ldap_IntermediateResponse(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_APP, 25, TRUE, dissect_ldap_IntermediateResponse_U);
return offset;
}
static int
dissect_ldap_ProtocolOp(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 98 "../../asn1/ldap/ldap.cnf"
ldap_call_response_t *lcrp;
ldap_conv_info_t *ldap_info = (ldap_conv_info_t *)actx->private_data;
do_protocolop = TRUE;
offset = dissect_ber_choice(actx, tree, tvb, offset,
ProtocolOp_choice, hf_index, ett_ldap_ProtocolOp,
&ProtocolOp);
#line 104 "../../asn1/ldap/ldap.cnf"
if (ProtocolOp == -1) {
return offset;
}
ProtocolOp = ldap_ProtocolOp_vals[ProtocolOp].value;
lcrp=ldap_match_call_response(tvb, actx->pinfo, tree, MessageID, ProtocolOp, ldap_info);
if(lcrp){
tap_queue_packet(ldap_tap, actx->pinfo, lcrp);
}
if(ldap_info && tree) {
switch(ProtocolOp) {
case LDAP_RES_SEARCH_ENTRY:
ldap_info->num_results++;
proto_item_append_text(tree, " [%d result%s]",
ldap_info->num_results, ldap_info->num_results == 1 ? "" : "s");
break;
case LDAP_RES_SEARCH_RESULT:
col_append_fstr(actx->pinfo->cinfo, COL_INFO, " [%d result%s]",
ldap_info->num_results, ldap_info->num_results == 1 ? "" : "s");
proto_item_append_text(tree, " [%d result%s]",
ldap_info->num_results, ldap_info->num_results == 1 ? "" : "s");
ldap_info->num_results = 0;
break;
default:
break;
}
}
return offset;
}
static int
dissect_ldap_ControlType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ldap_LDAPOID(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_ldap_T_controlValue(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 719 "../../asn1/ldap/ldap.cnf"
gint8 ber_class;
gboolean pc, ind;
gint32 tag;
guint32 len;
if((object_identifier_id != NULL) && oid_has_dissector(object_identifier_id)) {
offset=dissect_ber_identifier(actx->pinfo, NULL, tvb, offset, &ber_class, &pc, &tag);
offset=dissect_ber_length(actx->pinfo, NULL, tvb, offset, &len, &ind);
call_ber_oid_callback(object_identifier_id, tvb, offset, actx->pinfo, tree, NULL);
offset += len;
} else {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
}
return offset;
}
static int
dissect_ldap_Control(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Control_sequence, hf_index, ett_ldap_Control);
return offset;
}
static int
dissect_ldap_Controls(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
Controls_sequence_of, hf_index, ett_ldap_Controls);
return offset;
}
static int
dissect_ldap_LDAPMessage(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
LDAPMessage_sequence, hf_index, ett_ldap_LDAPMessage);
return offset;
}
static int
dissect_ldap_INTEGER(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ldap_SearchControlValue(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
SearchControlValue_sequence, hf_index, ett_ldap_SearchControlValue);
return offset;
}
static int
dissect_ldap_SortKeyList_item(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
SortKeyList_item_sequence, hf_index, ett_ldap_SortKeyList_item);
return offset;
}
static int
dissect_ldap_SortKeyList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SortKeyList_sequence_of, hf_index, ett_ldap_SortKeyList);
return offset;
}
static int
dissect_ldap_T_sortResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ldap_SortResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
SortResult_sequence, hf_index, ett_ldap_SortResult);
return offset;
}
static int
dissect_ldap_DirSyncFlags(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 763 "../../asn1/ldap/ldap.cnf"
gint8 ber_class;
gboolean pc;
gint32 tag;
guint32 len;
gint32 val;
int otheroffset = offset;
if(!implicit_tag){
dissect_ber_identifier(actx->pinfo, tree, tvb, otheroffset, &ber_class, &pc, &tag);
otheroffset=dissect_ber_length(actx->pinfo, tree, tvb, offset, &len, NULL);
} else {
gint32 remaining=tvb_reported_length_remaining(tvb, offset);
len=remaining>0 ? remaining : 0;
}
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, -1, &val);
if (val >0) {
const int *flags[] = {
&hf_ldap_object_security_flag,
&hf_ldap_ancestor_first_flag,
&hf_ldap_public_data_only_flag,
&hf_ldap_incremental_value_flag,
NULL
};
proto_tree_add_bitmask_value_with_flags(tree, tvb, otheroffset+1, hf_index,
ett_ldap_DirSyncFlagsSubEntry, flags, val, BMT_NO_APPEND);
} else {
proto_tree_add_uint(tree, hf_index, tvb, otheroffset+len, len, 0);
}
return offset;
}
static int
dissect_ldap_DirSyncControlValue(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
DirSyncControlValue_sequence, hf_index, ett_ldap_DirSyncControlValue);
return offset;
}
static int
dissect_ldap_PasswdModifyRequestValue(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
PasswdModifyRequestValue_sequence, hf_index, ett_ldap_PasswdModifyRequestValue);
return offset;
}
static int
dissect_ldap_CancelRequestValue(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
CancelRequestValue_sequence, hf_index, ett_ldap_CancelRequestValue);
return offset;
}
static int
dissect_ldap_T_mode(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ldap_SyncRequestValue(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
SyncRequestValue_sequence, hf_index, ett_ldap_SyncRequestValue);
return offset;
}
static int
dissect_ldap_T_state(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ldap_SyncUUID(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ldap_SyncStateValue(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
SyncStateValue_sequence, hf_index, ett_ldap_SyncStateValue);
return offset;
}
static int
dissect_ldap_SyncDoneValue(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
SyncDoneValue_sequence, hf_index, ett_ldap_SyncDoneValue);
return offset;
}
static int
dissect_ldap_T_refreshDelete(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_refreshDelete_sequence, hf_index, ett_ldap_T_refreshDelete);
return offset;
}
static int
dissect_ldap_T_refreshPresent(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_refreshPresent_sequence, hf_index, ett_ldap_T_refreshPresent);
return offset;
}
static int
dissect_ldap_SET_OF_SyncUUID(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
SET_OF_SyncUUID_set_of, hf_index, ett_ldap_SET_OF_SyncUUID);
return offset;
}
static int
dissect_ldap_T_syncIdSet(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_syncIdSet_sequence, hf_index, ett_ldap_T_syncIdSet);
return offset;
}
static int
dissect_ldap_SyncInfoValue(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
SyncInfoValue_choice, hf_index, ett_ldap_SyncInfoValue,
NULL);
return offset;
}
static int
dissect_ldap_T_warning(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_warning_choice, hf_index, ett_ldap_T_warning,
NULL);
return offset;
}
static int
dissect_ldap_T_error(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ldap_PasswordPolicyResponseValue(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
PasswordPolicyResponseValue_sequence, hf_index, ett_ldap_PasswordPolicyResponseValue);
return offset;
}
static int dissect_SearchControlValue_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_ldap_SearchControlValue(FALSE, tvb, offset, &asn1_ctx, tree, hf_ldap_SearchControlValue_PDU);
return offset;
}
static int dissect_SortKeyList_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_ldap_SortKeyList(FALSE, tvb, offset, &asn1_ctx, tree, hf_ldap_SortKeyList_PDU);
return offset;
}
static int dissect_SortResult_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_ldap_SortResult(FALSE, tvb, offset, &asn1_ctx, tree, hf_ldap_SortResult_PDU);
return offset;
}
static int dissect_DirSyncControlValue_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_ldap_DirSyncControlValue(FALSE, tvb, offset, &asn1_ctx, tree, hf_ldap_DirSyncControlValue_PDU);
return offset;
}
static int dissect_PasswdModifyRequestValue_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_ldap_PasswdModifyRequestValue(FALSE, tvb, offset, &asn1_ctx, tree, hf_ldap_PasswdModifyRequestValue_PDU);
return offset;
}
static int dissect_CancelRequestValue_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_ldap_CancelRequestValue(FALSE, tvb, offset, &asn1_ctx, tree, hf_ldap_CancelRequestValue_PDU);
return offset;
}
static int dissect_SyncRequestValue_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_ldap_SyncRequestValue(FALSE, tvb, offset, &asn1_ctx, tree, hf_ldap_SyncRequestValue_PDU);
return offset;
}
static int dissect_SyncStateValue_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_ldap_SyncStateValue(FALSE, tvb, offset, &asn1_ctx, tree, hf_ldap_SyncStateValue_PDU);
return offset;
}
static int dissect_SyncDoneValue_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_ldap_SyncDoneValue(FALSE, tvb, offset, &asn1_ctx, tree, hf_ldap_SyncDoneValue_PDU);
return offset;
}
static int dissect_SyncInfoValue_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_ldap_SyncInfoValue(FALSE, tvb, offset, &asn1_ctx, tree, hf_ldap_SyncInfoValue_PDU);
return offset;
}
static int dissect_PasswordPolicyResponseValue_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_ldap_PasswordPolicyResponseValue(FALSE, tvb, offset, &asn1_ctx, tree, hf_ldap_PasswordPolicyResponseValue_PDU);
return offset;
}
static int dissect_LDAPMessage_PDU(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, ldap_conv_info_t *ldap_info) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
asn1_ctx.private_data = ldap_info;
offset = dissect_ldap_LDAPMessage(FALSE, tvb, offset, &asn1_ctx, tree, hf_ldap_LDAPMessage_PDU);
return offset;
}
static void
dissect_ldap_payload(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, ldap_conv_info_t *ldap_info,
gboolean is_mscldap)
{
int offset = 0;
guint length_remaining;
guint msg_len = 0;
int messageOffset = 0;
guint headerLength = 0;
guint length = 0;
tvbuff_t *msg_tvb = NULL;
gint8 ber_class;
gboolean pc, ind = 0;
gint32 ber_tag;
attributedesc_string=NULL;
one_more_pdu:
length_remaining = tvb_ensure_captured_length_remaining(tvb, offset);
if (length_remaining < 6) return;
messageOffset = get_ber_identifier(tvb, offset, &ber_class, &pc, &ber_tag);
messageOffset = get_ber_length(tvb, messageOffset, &msg_len, &ind);
if((msg_len<4) || (msg_len>10000000)) return;
if ( (ber_class==BER_CLASS_UNI) && (ber_tag==BER_UNI_TAG_SEQUENCE) ) {
headerLength = messageOffset - offset;
msg_len += headerLength;
if (msg_len < headerLength) {
show_reported_bounds_error(tvb, pinfo, tree);
return;
}
} else {
msg_len = length_remaining;
}
length = length_remaining;
if (length > msg_len) length = msg_len;
msg_tvb = tvb_new_subset(tvb, offset, length, msg_len);
ldap_info->is_mscldap = is_mscldap;
dissect_LDAPMessage_PDU(msg_tvb, pinfo, tree, ldap_info);
offset += msg_len;
if(tvb_reported_length_remaining(tvb, offset)>=6){
tvb = tvb_new_subset_remaining(tvb, offset);
offset = 0;
goto one_more_pdu;
}
}
static void
ldap_frame_end(void)
{
ldap_found_in_frame = FALSE;
attr_type = NULL;
ldapvalue_string = NULL;
attributedesc_string = NULL;
Filter_string = NULL;
and_filter_string = NULL;
object_identifier_id = NULL;
or_filter_string = NULL;
substring_item_any = NULL;
substring_item_final = NULL;
substring_item_init = NULL;
substring_value = NULL;
ldm_tree = NULL;
Filter_elements = 0;
Filter_length = 0;
do_protocolop = FALSE;
result = 0;
matching_rule_string = NULL;
}
static void
dissect_ldap_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gboolean is_mscldap)
{
int offset = 0;
conversation_t *conversation;
gboolean doing_sasl_security = FALSE;
guint length_remaining;
ldap_conv_info_t *ldap_info = NULL;
proto_item *ldap_item = NULL;
proto_tree *ldap_tree = NULL;
ldm_tree = NULL;
conversation = find_or_create_conversation(pinfo);
ldap_info = (ldap_conv_info_t *)conversation_get_proto_data(conversation, proto_ldap);
if (ldap_info == NULL) {
ldap_info = g_new0(ldap_conv_info_t,1);
ldap_info->matched=g_hash_table_new(ldap_info_hash_matched, ldap_info_equal_matched);
ldap_info->unmatched=g_hash_table_new(ldap_info_hash_unmatched, ldap_info_equal_unmatched);
conversation_add_proto_data(conversation, proto_ldap, ldap_info);
ldap_info->next = ldap_info_items;
ldap_info_items = ldap_info;
}
switch (ldap_info->auth_type) {
case LDAP_AUTH_SASL:
if (ldap_info->first_auth_frame != 0 &&
pinfo->fd->num >= ldap_info->first_auth_frame) {
doing_sasl_security = TRUE;
}
}
length_remaining = tvb_ensure_captured_length_remaining(tvb, offset);
if(!doing_sasl_security && (tvb_bytes_exist(tvb, offset, 5))
&&(tvb_get_ntohl(tvb, offset)<=(guint)(tvb_reported_length_remaining(tvb, offset)-4))
&&(tvb_get_guint8(tvb, offset+4)==0x60) ){
ldap_info->auth_type=LDAP_AUTH_SASL;
ldap_info->first_auth_frame=pinfo->fd->num;
ldap_info->auth_mech=g_strdup("GSS-SPNEGO");
doing_sasl_security=TRUE;
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, pinfo->current_proto);
if(ldap_found_in_frame) {
col_append_str(pinfo->cinfo, COL_INFO, " | ");
col_set_fence(pinfo->cinfo, COL_INFO);
} else {
col_clear(pinfo->cinfo, COL_INFO);
register_frame_end_routine (pinfo, ldap_frame_end);
ldap_found_in_frame = TRUE;
}
ldap_item = proto_tree_add_item(tree, is_mscldap?proto_cldap:proto_ldap, tvb, 0, -1, ENC_NA);
ldap_tree = proto_item_add_subtree(ldap_item, ett_ldap);
if (doing_sasl_security && tvb_get_guint8(tvb, offset) == 0) {
proto_tree *sasl_tree;
tvbuff_t *sasl_tvb;
guint sasl_len, sasl_msg_len, length;
sasl_len = tvb_get_ntohl(tvb, offset);
sasl_msg_len = sasl_len + 4;
if (sasl_msg_len < 4) {
show_reported_bounds_error(tvb, pinfo, tree);
return;
}
length = length_remaining;
if (length > sasl_msg_len) length = sasl_msg_len;
sasl_tvb = tvb_new_subset(tvb, offset, length, sasl_msg_len);
proto_tree_add_uint(ldap_tree, hf_ldap_sasl_buffer_length, sasl_tvb, 0, 4,
sasl_len);
sasl_tree = proto_tree_add_subtree(ldap_tree, sasl_tvb, 0, sasl_msg_len, ett_ldap_sasl_blob, NULL, "SASL Buffer");
if (ldap_info->auth_mech != NULL &&
((strcmp(ldap_info->auth_mech, "GSS-SPNEGO") == 0) ||
(strcmp(ldap_info->auth_mech, "GSSAPI") == 0))) {
tvbuff_t *gssapi_tvb, *plain_tvb = NULL, *decr_tvb= NULL;
int ver_len;
int tmp_length;
tmp_length = tvb_reported_length_remaining(sasl_tvb, 4);
if ((guint)tmp_length > sasl_len)
tmp_length = sasl_len;
gssapi_tvb = tvb_new_subset(sasl_tvb, 4, tmp_length, sasl_len);
pinfo->decrypt_gssapi_tvb=DECRYPT_GSSAPI_NORMAL;
pinfo->gssapi_wrap_tvb=NULL;
pinfo->gssapi_encrypted_tvb=NULL;
pinfo->gssapi_decrypted_tvb=NULL;
ver_len = call_dissector(gssapi_wrap_handle, gssapi_tvb, pinfo, sasl_tree);
if(pinfo->gssapi_decrypted_tvb){
decr_tvb=pinfo->gssapi_decrypted_tvb;
} else if (pinfo->gssapi_wrap_tvb) {
plain_tvb=pinfo->gssapi_wrap_tvb;
}
pinfo->decrypt_gssapi_tvb=0;
pinfo->gssapi_wrap_tvb=NULL;
pinfo->gssapi_encrypted_tvb=NULL;
pinfo->gssapi_decrypted_tvb=NULL;
if(ver_len==0){
return;
}
if (!decr_tvb && !plain_tvb) {
if(!pinfo->gssapi_data_encrypted){
plain_tvb = tvb_new_subset_remaining(gssapi_tvb, ver_len);
}
}
if (decr_tvb) {
proto_tree *enc_tree = NULL;
guint decr_len = tvb_reported_length(decr_tvb);
col_set_str(pinfo->cinfo, COL_INFO, "SASL GSS-API Privacy (decrypted): ");
if (sasl_tree) {
enc_tree = proto_tree_add_subtree_format(sasl_tree, decr_tvb, 0, -1,
ett_ldap_payload, NULL, "GSS-API Encrypted payload (%d byte%s)",
decr_len, plurality(decr_len, "", "s"));
}
dissect_ldap_payload(decr_tvb, pinfo, enc_tree, ldap_info, is_mscldap);
} else if (plain_tvb) {
proto_tree *plain_tree = NULL;
guint plain_len = tvb_reported_length(plain_tvb);
col_set_str(pinfo->cinfo, COL_INFO, "SASL GSS-API Integrity: ");
if (sasl_tree) {
plain_tree = proto_tree_add_subtree_format(sasl_tree, plain_tvb, 0, -1,
ett_ldap_payload, NULL, "GSS-API payload (%d byte%s)",
plain_len, plurality(plain_len, "", "s"));
}
dissect_ldap_payload(plain_tvb, pinfo, plain_tree, ldap_info, is_mscldap);
} else {
col_add_fstr(pinfo->cinfo, COL_INFO, "SASL GSS-API Privacy: payload (%d byte%s)",
sasl_len - ver_len,
plurality(sasl_len - ver_len, "", "s"));
proto_tree_add_item(sasl_tree, hf_ldap_gssapi_encrypted_payload, gssapi_tvb, ver_len, -1, ENC_NA);
}
}
} else {
dissect_ldap_payload(tvb, pinfo, ldap_tree, ldap_info, is_mscldap);
}
}
int dissect_mscldap_string(tvbuff_t *tvb, int offset, char *str, int max_len, gboolean prepend_dot _U_)
{
int compr_len;
const guchar *name;
compr_len = expand_dns_name(tvb, offset, max_len, 0, &name);
g_strlcpy(str, name, max_len);
return offset + compr_len;
}
static int dissect_mscldap_netlogon_flags(proto_tree *parent_tree, tvbuff_t *tvb, int offset)
{
static const int * flags[] = {
&hf_mscldap_netlogon_flags_fnc,
&hf_mscldap_netlogon_flags_dnc,
&hf_mscldap_netlogon_flags_dns,
&hf_mscldap_netlogon_flags_wdc,
&hf_mscldap_netlogon_flags_rodc,
&hf_mscldap_netlogon_flags_ndnc,
&hf_mscldap_netlogon_flags_good_timeserv,
&hf_mscldap_netlogon_flags_writable,
&hf_mscldap_netlogon_flags_closest,
&hf_mscldap_netlogon_flags_timeserv,
&hf_mscldap_netlogon_flags_kdc,
&hf_mscldap_netlogon_flags_ds,
&hf_mscldap_netlogon_flags_ldap,
&hf_mscldap_netlogon_flags_gc,
&hf_mscldap_netlogon_flags_pdc,
NULL
};
proto_tree_add_bitmask_with_flags(parent_tree, tvb, offset, hf_mscldap_netlogon_flags,
ett_mscldap_netlogon_flags, flags, ENC_LITTLE_ENDIAN, BMT_NO_FALSE);
offset += 4;
return offset;
}
static void dissect_NetLogon_PDU(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
int old_offset, offset=0;
char str[256];
guint16 itype;
guint16 len;
guint32 version;
const char *fn;
int fn_len;
guint16 bc;
proto_item *item;
ldm_tree = NULL;
len=tvb_reported_length_remaining(tvb,offset);
if (len < 10) return;
proto_tree_add_item(tree, hf_mscldap_netlogon_opcode, tvb, offset, 2, ENC_LITTLE_ENDIAN);
itype = tvb_get_letohs(tvb, offset);
offset += 2;
switch(itype){
case LOGON_SAM_LOGON_RESPONSE:
bc = tvb_reported_length_remaining(tvb, offset);
fn = get_unicode_or_ascii_string(tvb,&offset,TRUE,&fn_len,FALSE,FALSE,&bc);
proto_tree_add_string(tree, hf_mscldap_nb_hostname, tvb,offset, fn_len, fn);
offset +=fn_len;
fn = get_unicode_or_ascii_string(tvb,&offset,TRUE,&fn_len,FALSE,FALSE,&bc);
proto_tree_add_string(tree, hf_mscldap_username, tvb,offset, fn_len, fn);
offset +=fn_len;
fn = get_unicode_or_ascii_string(tvb,&offset,TRUE,&fn_len,FALSE,FALSE,&bc);
proto_tree_add_string(tree, hf_mscldap_nb_domain, tvb,offset, fn_len, fn);
offset +=fn_len;
version = tvb_get_letohl(tvb,len-8);
if ((version & NETLOGON_NT_VERSION_5) == NETLOGON_NT_VERSION_5){
proto_tree_add_item(tree, hf_mscldap_domain_guid, tvb, offset, 16, ENC_LITTLE_ENDIAN);
offset += 16;
offset += 16;
old_offset=offset;
offset=dissect_mscldap_string(tvb, offset, str, 255, FALSE);
proto_tree_add_string(tree, hf_mscldap_forest, tvb, old_offset, offset-old_offset, str);
old_offset=offset;
offset=dissect_mscldap_string(tvb, offset, str, 255, FALSE);
proto_tree_add_string(tree, hf_mscldap_domain, tvb, old_offset, offset-old_offset, str);
old_offset=offset;
offset=dissect_mscldap_string(tvb, offset, str, 255, FALSE);
proto_tree_add_string(tree, hf_mscldap_hostname, tvb, old_offset, offset-old_offset, str);
proto_tree_add_ipv4(tree, hf_mscldap_netlogon_ipaddress, tvb, offset, 4, tvb_get_ntohl(tvb,offset));
offset += 4;
offset = dissect_mscldap_netlogon_flags(tree, tvb, offset);
}
break;
case LOGON_SAM_LOGON_RESPONSE_EX:
offset += 2;
offset = dissect_mscldap_netlogon_flags(tree, tvb, offset);
proto_tree_add_item(tree, hf_mscldap_domain_guid, tvb, offset, 16, ENC_LITTLE_ENDIAN);
offset += 16;
old_offset=offset;
offset=dissect_mscldap_string(tvb, offset, str, 255, FALSE);
proto_tree_add_string(tree, hf_mscldap_forest, tvb, old_offset, offset-old_offset, str);
old_offset=offset;
offset=dissect_mscldap_string(tvb, offset, str, 255, FALSE);
proto_tree_add_string(tree, hf_mscldap_domain, tvb, old_offset, offset-old_offset, str);
old_offset=offset;
offset=dissect_mscldap_string(tvb, offset, str, 255, FALSE);
proto_tree_add_string(tree, hf_mscldap_hostname, tvb, old_offset, offset-old_offset, str);
old_offset=offset;
offset=dissect_mscldap_string(tvb, offset, str, 255, FALSE);
proto_tree_add_string(tree, hf_mscldap_nb_domain, tvb, old_offset, offset-old_offset, str);
old_offset=offset;
offset=dissect_mscldap_string(tvb, offset, str, 255, FALSE);
proto_tree_add_string(tree, hf_mscldap_nb_hostname, tvb, old_offset, offset-old_offset, str);
old_offset=offset;
offset=dissect_mscldap_string(tvb, offset, str, 255, FALSE);
proto_tree_add_string(tree, hf_mscldap_username, tvb, old_offset, offset-old_offset, str);
old_offset=offset;
offset=dissect_mscldap_string(tvb, offset, str, 255, FALSE);
proto_tree_add_string(tree, hf_mscldap_sitename, tvb, old_offset, offset-old_offset, str);
old_offset=offset;
offset=dissect_mscldap_string(tvb, offset, str, 255, FALSE);
proto_tree_add_string(tree, hf_mscldap_clientsitename, tvb, old_offset, offset-old_offset, str);
version = tvb_get_letohl(tvb,len-8);
if ((version & NETLOGON_NT_VERSION_5EX_WITH_IP) == NETLOGON_NT_VERSION_5EX_WITH_IP){
offset +=1;
old_offset = offset + 4;
item = proto_tree_add_ipv4(tree, hf_mscldap_netlogon_ipaddress, tvb, old_offset, 4, tvb_get_ipv4(tvb,old_offset));
if (tree){
proto_tree *subtree;
subtree = proto_item_add_subtree(item, ett_mscldap_ipdetails);
proto_tree_add_item(subtree, hf_mscldap_netlogon_ipaddress_family, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset +=2;
proto_tree_add_item(subtree, hf_mscldap_netlogon_ipaddress_port, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset +=2;
proto_tree_add_ipv4(subtree, hf_mscldap_netlogon_ipaddress_ipv4, tvb, offset, 4, tvb_get_ipv4(tvb,offset));
offset +=4;
offset += 8;
}
}
break;
}
offset = len-8;
offset = dissect_mscldap_ntver_flags(tree, tvb, offset);
proto_tree_add_item(tree, hf_mscldap_netlogon_lm_token, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_mscldap_netlogon_nt_token, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
}
static guint
get_sasl_ldap_pdu_len(packet_info *pinfo _U_, tvbuff_t *tvb,
int offset, void *data _U_)
{
return tvb_get_ntohl(tvb, offset)+4;
}
static int
dissect_sasl_ldap_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
dissect_ldap_pdu(tvb, pinfo, tree, FALSE);
return tvb_captured_length(tvb);
}
static guint
get_normal_ldap_pdu_len(packet_info *pinfo _U_, tvbuff_t *tvb,
int offset, void *data _U_)
{
guint32 len;
gboolean ind;
int data_offset;
data_offset=get_ber_length(tvb, offset+1, &len, &ind);
return len+data_offset-offset;
}
static int
dissect_normal_ldap_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
dissect_ldap_pdu(tvb, pinfo, tree, FALSE);
return tvb_captured_length(tvb);
}
static void
dissect_ldap_oid(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
char *oid;
const char *oidname;
oid=tvb_get_string_enc(wmem_packet_scope(), tvb, 0, tvb_reported_length(tvb), ENC_UTF_8|ENC_NA);
if(!oid){
return;
}
oidname=oid_resolved_from_string(wmem_packet_scope(), oid);
if(oidname){
proto_tree_add_string_format_value(tree, hf_ldap_oid, tvb, 0, tvb_reported_length(tvb), oid, "%s (%s)",oid,oidname);
} else {
proto_tree_add_string(tree, hf_ldap_oid, tvb, 0, tvb_captured_length(tvb), oid);
}
}
static void
ldap_specific_rights(tvbuff_t *tvb, gint offset, proto_tree *tree, guint32 access)
{
proto_tree_add_boolean(tree, hf_ldap_AccessMask_ADS_CONTROL_ACCESS, tvb, offset, 4, access);
proto_tree_add_boolean(tree, hf_ldap_AccessMask_ADS_LIST_OBJECT, tvb, offset, 4, access);
proto_tree_add_boolean(tree, hf_ldap_AccessMask_ADS_DELETE_TREE, tvb, offset, 4, access);
proto_tree_add_boolean(tree, hf_ldap_AccessMask_ADS_WRITE_PROP, tvb, offset, 4, access);
proto_tree_add_boolean(tree, hf_ldap_AccessMask_ADS_READ_PROP, tvb, offset, 4, access);
proto_tree_add_boolean(tree, hf_ldap_AccessMask_ADS_SELF_WRITE, tvb, offset, 4, access);
proto_tree_add_boolean(tree, hf_ldap_AccessMask_ADS_LIST, tvb, offset, 4, access);
proto_tree_add_boolean(tree, hf_ldap_AccessMask_ADS_DELETE_CHILD, tvb, offset, 4, access);
proto_tree_add_boolean(tree, hf_ldap_AccessMask_ADS_CREATE_CHILD, tvb, offset, 4, access);
}
static void
dissect_ldap_nt_sec_desc(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
dissect_nt_sec_desc(tvb, 0, pinfo, tree, NULL, TRUE, tvb_reported_length(tvb), &ldap_access_mask_info);
}
static void
dissect_ldap_sid(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
char *tmpstr;
dissect_nt_sid(tvb, 0, tree, "SID", &tmpstr, hf_ldap_sid);
ldapvalue_string=tmpstr;
}
static void
dissect_ldap_guid(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint8 drep[4] = { 0x10, 0x00, 0x00, 0x00};
e_guid_t uuid;
dissect_dcerpc_uuid_t(tvb, 0, pinfo, tree, drep, hf_ldap_guid, &uuid);
ldapvalue_string=(char*)wmem_alloc(wmem_packet_scope(), 1024);
g_snprintf(ldapvalue_string, 1023, "%08x-%04x-%04x-%02x%02x-%02x%02x%02x%02x%02x%02x",
uuid.data1, uuid.data2, uuid.data3,
uuid.data4[0], uuid.data4[1],
uuid.data4[2], uuid.data4[3],
uuid.data4[4], uuid.data4[5],
uuid.data4[6], uuid.data4[7]);
}
static int
dissect_ldap_tcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
guint32 sasl_len;
guint32 ldap_len;
gboolean ind;
conversation_t *conversation;
ldap_conv_info_t *ldap_info = NULL;
conversation = find_conversation(pinfo->fd->num,
&pinfo->src, &pinfo->dst,
pinfo->ptype, pinfo->srcport,
pinfo->destport, 0);
if(conversation){
ldap_info = (ldap_conv_info_t *)conversation_get_proto_data(conversation, proto_ldap);
}
ldm_tree = NULL;
sasl_len=tvb_get_ntohl(tvb, 0);
if( sasl_len<2 ){
goto this_was_not_sasl;
}
if( sasl_len>LDAP_SASL_MAX_BUF ){
goto this_was_not_sasl;
}
if((!ldap_info) || (ldap_info->auth_type!=LDAP_AUTH_SASL) ){
goto this_was_not_sasl;
}
tcp_dissect_pdus(tvb, pinfo, tree, ldap_desegment, 4, get_sasl_ldap_pdu_len, dissect_sasl_ldap_pdu, data);
return tvb_captured_length(tvb);
this_was_not_sasl:
if(tvb_get_guint8(tvb, 0)!=0x30){
goto this_was_not_normal_ldap;
}
get_ber_length(tvb, 1, &ldap_len, &ind);
if(ldap_len<2){
goto this_was_not_normal_ldap;
}
tcp_dissect_pdus(tvb, pinfo, tree, ldap_desegment, 7, get_normal_ldap_pdu_len, dissect_normal_ldap_pdu, data);
goto end;
this_was_not_normal_ldap:
if ((sasl_len + 4) == (guint32)tvb_reported_length_remaining(tvb, 0))
tcp_dissect_pdus(tvb, pinfo, tree, ldap_desegment, 4, get_sasl_ldap_pdu_len, dissect_sasl_ldap_pdu, data);
end:
return tvb_captured_length(tvb);
}
static void
dissect_mscldap(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
dissect_ldap_pdu(tvb, pinfo, tree, TRUE);
return;
}
static void
ldap_cleanup(void)
{
ldap_conv_info_t *ldap_info;
for (ldap_info = ldap_info_items; ldap_info != NULL; ) {
ldap_conv_info_t *next;
g_free(ldap_info->auth_mech);
g_hash_table_destroy(ldap_info->matched);
g_hash_table_destroy(ldap_info->unmatched);
next = ldap_info->next;
g_free(ldap_info);
ldap_info = next;
}
ldap_info_items = NULL;
}
void
register_ldap_name_dissector_handle(const char *attr_type_p, dissector_handle_t dissector)
{
dissector_add_string("ldap.name", attr_type_p, dissector);
}
void
register_ldap_name_dissector(const char *attr_type_p, dissector_t dissector, int proto)
{
dissector_handle_t dissector_handle;
dissector_handle=create_dissector_handle(dissector, proto);
register_ldap_name_dissector_handle(attr_type_p, dissector_handle);
}
void
new_register_ldap_name_dissector(const char *attr_type_p, new_dissector_t dissector, int proto)
{
dissector_handle_t dissector_handle;
dissector_handle=new_create_dissector_handle(dissector, proto);
register_ldap_name_dissector_handle(attr_type_p, dissector_handle);
}
void proto_register_ldap(void) {
static hf_register_info hf[] = {
{ &hf_ldap_sasl_buffer_length,
{ "SASL Buffer Length", "ldap.sasl_buffer_length",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_ldap_response_in,
{ "Response In", "ldap.response_in",
FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"The response to this LDAP request is in this frame", HFILL }},
{ &hf_ldap_response_to,
{ "Response To", "ldap.response_to",
FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"This is a response to the LDAP request in this frame", HFILL }},
{ &hf_ldap_time,
{ "Time", "ldap.time",
FT_RELATIVE_TIME, BASE_NONE, NULL, 0x0,
"The time between the Call and the Reply", HFILL }},
{ &hf_mscldap_netlogon_opcode,
{ "Operation code", "mscldap.netlogon.opcode",
FT_UINT16, BASE_DEC, VALS(netlogon_opcode_vals), 0x0,
"LDAP ping operation code", HFILL }},
{ &hf_mscldap_netlogon_ipaddress_family,
{ "Family", "mscldap.netlogon.ipaddress.family",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_mscldap_netlogon_ipaddress_ipv4,
{ "IPv4", "mscldap.netlogon.ipaddress.ipv4",
FT_IPv4, BASE_NONE, NULL, 0x0,
"IP Address", HFILL }},
{ &hf_mscldap_netlogon_ipaddress_port,
{ "Port", "mscldap.netlogon.ipaddress.port",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_mscldap_netlogon_ipaddress,
{ "IP Address","mscldap.netlogon.ipaddress",
FT_IPv4, BASE_NONE, NULL, 0x0,
"Domain Controller IP Address", HFILL }},
{ &hf_mscldap_netlogon_lm_token,
{ "LM Token", "mscldap.netlogon.lm_token",
FT_UINT16, BASE_HEX, NULL, 0x0,
"MUST be set to 0xFFFF", HFILL }},
{ &hf_mscldap_netlogon_nt_token,
{ "NT Token", "mscldap.netlogon.nt_token",
FT_UINT16, BASE_HEX, NULL, 0x0,
"MUST be set to 0xFFFF", HFILL }},
{ &hf_mscldap_netlogon_flags,
{ "Flags", "mscldap.netlogon.flags",
FT_UINT32, BASE_HEX, NULL, 0x0,
"Netlogon flags describing the DC properties", HFILL }},
{ &hf_mscldap_ntver_flags,
{ "Version Flags", "mscldap.ntver.flags",
FT_UINT32, BASE_HEX, NULL, 0x0,
"NETLOGON_NT_VERSION Options Bits", HFILL }},
{ &hf_mscldap_domain_guid,
{ "Domain GUID", "mscldap.domain.guid",
FT_GUID, BASE_NONE, NULL, 0x0,
"Value of the NC's GUID attribute", HFILL }},
{ &hf_mscldap_forest,
{ "Forest", "mscldap.forest",
FT_STRING, BASE_NONE, NULL, 0x0,
"DNS name of the forest", HFILL }},
{ &hf_mscldap_domain,
{ "Domain", "mscldap.domain",
FT_STRING, BASE_NONE, NULL, 0x0,
"DNS name of the NC", HFILL }},
{ &hf_mscldap_hostname,
{ "Hostname", "mscldap.hostname",
FT_STRING, BASE_NONE, NULL, 0x0,
"DNS name of server", HFILL }},
{ &hf_mscldap_nb_domain,
{ "NetBIOS Domain", "mscldap.nb_domain",
FT_STRING, BASE_NONE, NULL, 0x0,
"NetBIOS name of the NC", HFILL }},
{ &hf_mscldap_nb_hostname,
{ "NetBIOS Hostname", "mscldap.nb_hostname",
FT_STRING, BASE_NONE, NULL, 0x0,
"NetBIOS name of the server", HFILL }},
{ &hf_mscldap_username,
{ "Username", "mscldap.username",
FT_STRING, BASE_NONE, NULL, 0x0,
"User specified in client's request", HFILL }},
{ &hf_mscldap_sitename,
{ "Server Site", "mscldap.sitename",
FT_STRING, BASE_NONE, NULL, 0x0,
"Site name of the server", HFILL }},
{ &hf_mscldap_clientsitename,
{ "Client Site", "mscldap.clientsitename",
FT_STRING, BASE_NONE, NULL, 0x0,
"Site name of the client", HFILL }},
{ &hf_ldap_sid,
{ "Sid", "ldap.sid",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_mscldap_ntver_flags_v1,
{ "V1", "mscldap.ntver.searchflags.v1", FT_BOOLEAN, 32,
TFS(&tfs_ntver_v1), 0x00000001, "See section 7.3.1.1 of MS-ADTS specification", HFILL }},
{ &hf_mscldap_ntver_flags_v5,
{ "V5", "mscldap.ntver.searchflags.v5", FT_BOOLEAN, 32,
TFS(&tfs_ntver_v5), 0x00000002, "See section 7.3.1.1 of MS-ADTS specification", HFILL }},
{ &hf_mscldap_ntver_flags_v5ex,
{ "V5EX", "mscldap.ntver.searchflags.v5ex", FT_BOOLEAN, 32,
TFS(&tfs_ntver_v5ex), 0x00000004, "See section 7.3.1.1 of MS-ADTS specification", HFILL }},
{ &hf_mscldap_ntver_flags_v5ep,
{ "V5EP", "mscldap.ntver.searchflags.v5ep", FT_BOOLEAN, 32,
TFS(&tfs_ntver_v5ep), 0x00000008, "See section 7.3.1.1 of MS-ADTS specification", HFILL }},
{ &hf_mscldap_ntver_flags_vcs,
{ "VCS", "mscldap.ntver.searchflags.vcs", FT_BOOLEAN, 32,
TFS(&tfs_ntver_vcs), 0x00000010, "See section 7.3.1.1 of MS-ADTS specification", HFILL }},
{ &hf_mscldap_ntver_flags_vnt4,
{ "VNT4", "mscldap.ntver.searchflags.vnt4", FT_BOOLEAN, 32,
TFS(&tfs_ntver_vnt4), 0x01000000, "See section 7.3.1.1 of MS-ADTS specification", HFILL }},
{ &hf_mscldap_ntver_flags_vpdc,
{ "VPDC", "mscldap.ntver.searchflags.vpdc", FT_BOOLEAN, 32,
TFS(&tfs_ntver_vpdc), 0x10000000, "See section 7.3.1.1 of MS-ADTS specification", HFILL }},
{ &hf_mscldap_ntver_flags_vip,
{ "VIP", "mscldap.ntver.searchflags.vip", FT_BOOLEAN, 32,
TFS(&tfs_ntver_vip), 0x20000000, "See section 7.3.1.1 of MS-ADTS specification", HFILL }},
{ &hf_mscldap_ntver_flags_vl,
{ "VL", "mscldap.ntver.searchflags.vl", FT_BOOLEAN, 32,
TFS(&tfs_ntver_vl), 0x40000000, "See section 7.3.1.1 of MS-ADTS specification", HFILL }},
{ &hf_mscldap_ntver_flags_vgc,
{ "VGC", "mscldap.ntver.searchflags.vgc", FT_BOOLEAN, 32,
TFS(&tfs_ntver_vgc), 0x80000000, "See section 7.3.1.1 of MS-ADTS specification", HFILL }},
{ &hf_mscldap_netlogon_flags_pdc,
{ "PDC", "mscldap.netlogon.flags.pdc", FT_BOOLEAN, 32,
TFS(&tfs_ads_pdc), 0x00000001, "Is this DC a PDC or not?", HFILL }},
{ &hf_mscldap_netlogon_flags_gc,
{ "GC", "mscldap.netlogon.flags.gc", FT_BOOLEAN, 32,
TFS(&tfs_ads_gc), 0x00000004, "Does this dc service as a GLOBAL CATALOGUE?", HFILL }},
{ &hf_mscldap_netlogon_flags_ldap,
{ "LDAP", "mscldap.netlogon.flags.ldap", FT_BOOLEAN, 32,
TFS(&tfs_ads_ldap), 0x00000008, "Does this DC act as an LDAP server?", HFILL }},
{ &hf_mscldap_netlogon_flags_ds,
{ "DS", "mscldap.netlogon.flags.ds", FT_BOOLEAN, 32,
TFS(&tfs_ads_ds), 0x00000010, "Does this dc provide DS services?", HFILL }},
{ &hf_mscldap_netlogon_flags_kdc,
{ "KDC", "mscldap.netlogon.flags.kdc", FT_BOOLEAN, 32,
TFS(&tfs_ads_kdc), 0x00000020, "Does this dc act as a KDC?", HFILL }},
{ &hf_mscldap_netlogon_flags_timeserv,
{ "Time Serv", "mscldap.netlogon.flags.timeserv", FT_BOOLEAN, 32,
TFS(&tfs_ads_timeserv), 0x00000040, "Does this dc provide time services (ntp) ?", HFILL }},
{ &hf_mscldap_netlogon_flags_closest,
{ "Closest", "mscldap.netlogon.flags.closest", FT_BOOLEAN, 32,
TFS(&tfs_ads_closest), 0x00000080, "Is this the closest dc?", HFILL }},
{ &hf_mscldap_netlogon_flags_writable,
{ "Writable", "mscldap.netlogon.flags.writable", FT_BOOLEAN, 32,
TFS(&tfs_ads_writable), 0x00000100, "Is this dc writable?", HFILL }},
{ &hf_mscldap_netlogon_flags_good_timeserv,
{ "Good Time Serv", "mscldap.netlogon.flags.good_timeserv", FT_BOOLEAN, 32,
TFS(&tfs_ads_good_timeserv), 0x00000200, "Is this a Good Time Server? (i.e. does it have a hardware clock)", HFILL }},
{ &hf_mscldap_netlogon_flags_ndnc,
{ "NDNC", "mscldap.netlogon.flags.ndnc", FT_BOOLEAN, 32,
TFS(&tfs_ads_ndnc), 0x00000400, "Is this an NDNC dc?", HFILL }},
{ &hf_mscldap_netlogon_flags_rodc,
{ "RODC", "mscldap.netlogon.flags.rodc", FT_BOOLEAN, 32,
TFS(&tfs_ads_rodc), 0x00000800, "Is this an read only dc?", HFILL }},
{ &hf_mscldap_netlogon_flags_wdc,
{ "WDC", "mscldap.netlogon.flags.writabledc.", FT_BOOLEAN, 32,
TFS(&tfs_ads_wdc), 0x00001000, "Is this an writable dc (Windows 2008)?", HFILL }},
{ &hf_mscldap_netlogon_flags_dns,
{ "DNS", "mscldap.netlogon.flags.dnsname", FT_BOOLEAN, 32,
TFS(&tfs_ads_dns), 0x20000000, "Does the server have a dns name (Windows 2008)?", HFILL }},
{ &hf_mscldap_netlogon_flags_dnc,
{ "DNC", "mscldap.netlogon.flags.defaultnc", FT_BOOLEAN, 32,
TFS(&tfs_ads_dnc), 0x40000000, "Is this the default NC (Windows 2008)?", HFILL }},
{ &hf_mscldap_netlogon_flags_fnc,
{ "FDC", "mscldap.netlogon.flags.forestnc", FT_BOOLEAN, 32,
TFS(&tfs_ads_fnc), 0x80000000, "Is the the NC the default forest root(Windows 2008)?", HFILL }},
{ &hf_ldap_guid,
{ "GUID", "ldap.guid", FT_GUID, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_ldap_AccessMask_ADS_CREATE_CHILD,
{ "Ads Create Child", "ldap.AccessMask.ADS_CREATE_CHILD", FT_BOOLEAN, 32, TFS(&tfs_set_notset), LDAP_ACCESSMASK_ADS_CREATE_CHILD, NULL, HFILL }},
{ &hf_ldap_AccessMask_ADS_DELETE_CHILD,
{ "Ads Delete Child", "ldap.AccessMask.ADS_DELETE_CHILD", FT_BOOLEAN, 32, TFS(&tfs_set_notset), LDAP_ACCESSMASK_ADS_DELETE_CHILD, NULL, HFILL }},
{ &hf_ldap_AccessMask_ADS_LIST,
{ "Ads List", "ldap.AccessMask.ADS_LIST", FT_BOOLEAN, 32, TFS(&tfs_set_notset), LDAP_ACCESSMASK_ADS_LIST, NULL, HFILL }},
{ &hf_ldap_AccessMask_ADS_SELF_WRITE,
{ "Ads Self Write", "ldap.AccessMask.ADS_SELF_WRITE", FT_BOOLEAN, 32, TFS(&tfs_set_notset), LDAP_ACCESSMASK_ADS_SELF_WRITE, NULL, HFILL }},
{ &hf_ldap_AccessMask_ADS_READ_PROP,
{ "Ads Read Prop", "ldap.AccessMask.ADS_READ_PROP", FT_BOOLEAN, 32, TFS(&tfs_set_notset), LDAP_ACCESSMASK_ADS_READ_PROP, NULL, HFILL }},
{ &hf_ldap_AccessMask_ADS_WRITE_PROP,
{ "Ads Write Prop", "ldap.AccessMask.ADS_WRITE_PROP", FT_BOOLEAN, 32, TFS(&tfs_set_notset), LDAP_ACCESSMASK_ADS_WRITE_PROP, NULL, HFILL }},
{ &hf_ldap_AccessMask_ADS_DELETE_TREE,
{ "Ads Delete Tree", "ldap.AccessMask.ADS_DELETE_TREE", FT_BOOLEAN, 32, TFS(&tfs_set_notset), LDAP_ACCESSMASK_ADS_DELETE_TREE, NULL, HFILL }},
{ &hf_ldap_AccessMask_ADS_LIST_OBJECT,
{ "Ads List Object", "ldap.AccessMask.ADS_LIST_OBJECT", FT_BOOLEAN, 32, TFS(&tfs_set_notset), LDAP_ACCESSMASK_ADS_LIST_OBJECT, NULL, HFILL }},
{ &hf_ldap_AccessMask_ADS_CONTROL_ACCESS,
{ "Ads Control Access", "ldap.AccessMask.ADS_CONTROL_ACCESS", FT_BOOLEAN, 32, TFS(&tfs_set_notset), LDAP_ACCESSMASK_ADS_CONTROL_ACCESS, NULL, HFILL }},
{ &hf_ldap_LDAPMessage_PDU,
{ "LDAPMessage", "ldap.LDAPMessage_element", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_ldap_object_security_flag,
{ "Flag Object_Security", "ldap.object_security_flag", FT_BOOLEAN, 32, NULL, 0x00000001, NULL, HFILL }},
{ &hf_ldap_ancestor_first_flag,
{ "Flag Ancestor_First", "ldap.ancestor_first_flag", FT_BOOLEAN, 32, NULL, 0x00000800, NULL, HFILL }},
{ &hf_ldap_public_data_only_flag,
{ "Flag Public_Data_Only", "ldap.public_data_only_flag", FT_BOOLEAN, 32, NULL, 0x00002000, NULL, HFILL }},
{ &hf_ldap_incremental_value_flag,
{ "Flag Incremental_Value", "ldap.incremental_value_flag", FT_BOOLEAN, 32, NULL, 0x80000000, NULL, HFILL }},
{ &hf_ldap_oid,
{ "OID", "ldap.oid", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_ldap_gssapi_encrypted_payload,
{ "GSS-API Encrypted payload", "ldap.gssapi_encrypted_payload", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL }},
#line 1 "../../asn1/ldap/packet-ldap-hfarr.c"
{ &hf_ldap_SearchControlValue_PDU,
{ "SearchControlValue", "ldap.SearchControlValue_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ldap_SortKeyList_PDU,
{ "SortKeyList", "ldap.SortKeyList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ldap_SortResult_PDU,
{ "SortResult", "ldap.SortResult_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ldap_DirSyncControlValue_PDU,
{ "DirSyncControlValue", "ldap.DirSyncControlValue_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ldap_PasswdModifyRequestValue_PDU,
{ "PasswdModifyRequestValue", "ldap.PasswdModifyRequestValue_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ldap_CancelRequestValue_PDU,
{ "CancelRequestValue", "ldap.CancelRequestValue_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ldap_SyncRequestValue_PDU,
{ "SyncRequestValue", "ldap.SyncRequestValue_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ldap_SyncStateValue_PDU,
{ "SyncStateValue", "ldap.SyncStateValue_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ldap_SyncDoneValue_PDU,
{ "SyncDoneValue", "ldap.SyncDoneValue_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ldap_SyncInfoValue_PDU,
{ "SyncInfoValue", "ldap.SyncInfoValue",
FT_UINT32, BASE_DEC, VALS(ldap_SyncInfoValue_vals), 0,
NULL, HFILL }},
{ &hf_ldap_PasswordPolicyResponseValue_PDU,
{ "PasswordPolicyResponseValue", "ldap.PasswordPolicyResponseValue_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ldap_messageID,
{ "messageID", "ldap.messageID",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ldap_protocolOp,
{ "protocolOp", "ldap.protocolOp",
FT_UINT32, BASE_DEC, VALS(ldap_ProtocolOp_vals), 0,
NULL, HFILL }},
{ &hf_ldap_controls,
{ "controls", "ldap.controls",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ldap_bindRequest,
{ "bindRequest", "ldap.bindRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ldap_bindResponse,
{ "bindResponse", "ldap.bindResponse_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ldap_unbindRequest,
{ "unbindRequest", "ldap.unbindRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ldap_searchRequest,
{ "searchRequest", "ldap.searchRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ldap_searchResEntry,
{ "searchResEntry", "ldap.searchResEntry_element",
FT_NONE, BASE_NONE, NULL, 0,
"SearchResultEntry", HFILL }},
{ &hf_ldap_searchResDone,
{ "searchResDone", "ldap.searchResDone_element",
FT_NONE, BASE_NONE, NULL, 0,
"SearchResultDone", HFILL }},
{ &hf_ldap_searchResRef,
{ "searchResRef", "ldap.searchResRef",
FT_UINT32, BASE_DEC, NULL, 0,
"SearchResultReference", HFILL }},
{ &hf_ldap_modifyRequest,
{ "modifyRequest", "ldap.modifyRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ldap_modifyResponse,
{ "modifyResponse", "ldap.modifyResponse_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ldap_addRequest,
{ "addRequest", "ldap.addRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ldap_addResponse,
{ "addResponse", "ldap.addResponse_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ldap_delRequest,
{ "delRequest", "ldap.delRequest",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ldap_delResponse,
{ "delResponse", "ldap.delResponse_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ldap_modDNRequest,
{ "modDNRequest", "ldap.modDNRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
"ModifyDNRequest", HFILL }},
{ &hf_ldap_modDNResponse,
{ "modDNResponse", "ldap.modDNResponse_element",
FT_NONE, BASE_NONE, NULL, 0,
"ModifyDNResponse", HFILL }},
{ &hf_ldap_compareRequest,
{ "compareRequest", "ldap.compareRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ldap_compareResponse,
{ "compareResponse", "ldap.compareResponse_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ldap_abandonRequest,
{ "abandonRequest", "ldap.abandonRequest",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ldap_extendedReq,
{ "extendedReq", "ldap.extendedReq_element",
FT_NONE, BASE_NONE, NULL, 0,
"ExtendedRequest", HFILL }},
{ &hf_ldap_extendedResp,
{ "extendedResp", "ldap.extendedResp_element",
FT_NONE, BASE_NONE, NULL, 0,
"ExtendedResponse", HFILL }},
{ &hf_ldap_intermediateResponse,
{ "intermediateResponse", "ldap.intermediateResponse_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ldap_AttributeDescriptionList_item,
{ "AttributeDescription", "ldap.AttributeDescription",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ldap_attributeDesc,
{ "attributeDesc", "ldap.attributeDesc",
FT_STRING, BASE_NONE, NULL, 0,
"AttributeDescription", HFILL }},
{ &hf_ldap_assertionValue,
{ "assertionValue", "ldap.assertionValue",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ldap_type,
{ "type", "ldap.type",
FT_STRING, BASE_NONE, NULL, 0,
"AttributeDescription", HFILL }},
{ &hf_ldap_vals,
{ "vals", "ldap.vals",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_OF_AttributeValue", HFILL }},
{ &hf_ldap_vals_item,
{ "AttributeValue", "ldap.AttributeValue",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ldap_resultCode,
{ "resultCode", "ldap.resultCode",
FT_UINT32, BASE_DEC, VALS(ldap_T_resultCode_vals), 0,
NULL, HFILL }},
{ &hf_ldap_matchedDN,
{ "matchedDN", "ldap.matchedDN",
FT_STRING, BASE_NONE, NULL, 0,
"LDAPDN", HFILL }},
{ &hf_ldap_errorMessage,
{ "errorMessage", "ldap.errorMessage",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ldap_referral,
{ "referral", "ldap.referral",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ldap_Referral_item,
{ "LDAPURL", "ldap.LDAPURL",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ldap_Controls_item,
{ "Control", "ldap.Control_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ldap_controlType,
{ "controlType", "ldap.controlType",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ldap_criticality,
{ "criticality", "ldap.criticality",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ldap_controlValue,
{ "controlValue", "ldap.controlValue",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ldap_version,
{ "version", "ldap.version",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_127", HFILL }},
{ &hf_ldap_name,
{ "name", "ldap.name",
FT_STRING, BASE_NONE, NULL, 0,
"LDAPDN", HFILL }},
{ &hf_ldap_authentication,
{ "authentication", "ldap.authentication",
FT_UINT32, BASE_DEC, VALS(ldap_AuthenticationChoice_vals), 0,
"AuthenticationChoice", HFILL }},
{ &hf_ldap_simple,
{ "simple", "ldap.simple",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ldap_sasl,
{ "sasl", "ldap.sasl_element",
FT_NONE, BASE_NONE, NULL, 0,
"SaslCredentials", HFILL }},
{ &hf_ldap_ntlmsspNegotiate,
{ "ntlmsspNegotiate", "ldap.ntlmsspNegotiate",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ldap_ntlmsspAuth,
{ "ntlmsspAuth", "ldap.ntlmsspAuth",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ldap_mechanism,
{ "mechanism", "ldap.mechanism",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ldap_credentials,
{ "credentials", "ldap.credentials",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ldap_bindResponse_resultCode,
{ "resultCode", "ldap.resultCode",
FT_UINT32, BASE_DEC, VALS(ldap_BindResponse_resultCode_vals), 0,
"BindResponse_resultCode", HFILL }},
{ &hf_ldap_bindResponse_matchedDN,
{ "matchedDN", "ldap.matchedDN",
FT_STRING, BASE_NONE, NULL, 0,
"T_bindResponse_matchedDN", HFILL }},
{ &hf_ldap_serverSaslCreds,
{ "serverSaslCreds", "ldap.serverSaslCreds",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ldap_baseObject,
{ "baseObject", "ldap.baseObject",
FT_STRING, BASE_NONE, NULL, 0,
"LDAPDN", HFILL }},
{ &hf_ldap_scope,
{ "scope", "ldap.scope",
FT_UINT32, BASE_DEC, VALS(ldap_T_scope_vals), 0,
NULL, HFILL }},
{ &hf_ldap_derefAliases,
{ "derefAliases", "ldap.derefAliases",
FT_UINT32, BASE_DEC, VALS(ldap_T_derefAliases_vals), 0,
NULL, HFILL }},
{ &hf_ldap_sizeLimit,
{ "sizeLimit", "ldap.sizeLimit",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_maxInt", HFILL }},
{ &hf_ldap_timeLimit,
{ "timeLimit", "ldap.timeLimit",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_maxInt", HFILL }},
{ &hf_ldap_typesOnly,
{ "typesOnly", "ldap.typesOnly",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ldap_filter,
{ "filter", "ldap.filter",
FT_UINT32, BASE_DEC, VALS(ldap_Filter_vals), 0,
NULL, HFILL }},
{ &hf_ldap_searchRequest_attributes,
{ "attributes", "ldap.attributes",
FT_UINT32, BASE_DEC, NULL, 0,
"AttributeDescriptionList", HFILL }},
{ &hf_ldap_and,
{ "and", "ldap.and",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ldap_and_item,
{ "and item", "ldap.and_item",
FT_UINT32, BASE_DEC, VALS(ldap_Filter_vals), 0,
NULL, HFILL }},
{ &hf_ldap_or,
{ "or", "ldap.or",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ldap_or_item,
{ "or item", "ldap.or_item",
FT_UINT32, BASE_DEC, VALS(ldap_Filter_vals), 0,
NULL, HFILL }},
{ &hf_ldap_not,
{ "not", "ldap.not",
FT_UINT32, BASE_DEC, VALS(ldap_Filter_vals), 0,
NULL, HFILL }},
{ &hf_ldap_equalityMatch,
{ "equalityMatch", "ldap.equalityMatch_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ldap_substrings,
{ "substrings", "ldap.substrings_element",
FT_NONE, BASE_NONE, NULL, 0,
"SubstringFilter", HFILL }},
{ &hf_ldap_greaterOrEqual,
{ "greaterOrEqual", "ldap.greaterOrEqual_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ldap_lessOrEqual,
{ "lessOrEqual", "ldap.lessOrEqual_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ldap_present,
{ "present", "ldap.present",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ldap_approxMatch,
{ "approxMatch", "ldap.approxMatch_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ldap_extensibleMatch,
{ "extensibleMatch", "ldap.extensibleMatch_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ldap_substringFilter_substrings,
{ "substrings", "ldap.substrings",
FT_UINT32, BASE_DEC, NULL, 0,
"T_substringFilter_substrings", HFILL }},
{ &hf_ldap_substringFilter_substrings_item,
{ "substrings item", "ldap.substrings_item",
FT_UINT32, BASE_DEC, VALS(ldap_T_substringFilter_substrings_item_vals), 0,
"T_substringFilter_substrings_item", HFILL }},
{ &hf_ldap_initial,
{ "initial", "ldap.initial",
FT_STRING, BASE_NONE, NULL, 0,
"LDAPString", HFILL }},
{ &hf_ldap_any,
{ "any", "ldap.any",
FT_STRING, BASE_NONE, NULL, 0,
"LDAPString", HFILL }},
{ &hf_ldap_final,
{ "final", "ldap.final",
FT_STRING, BASE_NONE, NULL, 0,
"LDAPString", HFILL }},
{ &hf_ldap_matchingRule,
{ "matchingRule", "ldap.matchingRule",
FT_STRING, BASE_NONE, NULL, 0,
"MatchingRuleId", HFILL }},
{ &hf_ldap_matchValue,
{ "matchValue", "ldap.matchValue",
FT_STRING, BASE_NONE, NULL, 0,
"AssertionValue", HFILL }},
{ &hf_ldap_dnAttributes,
{ "dnAttributes", "ldap.dnAttributes",
FT_BOOLEAN, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ldap_objectName,
{ "objectName", "ldap.objectName",
FT_STRING, BASE_NONE, NULL, 0,
"LDAPDN", HFILL }},
{ &hf_ldap_searchResultEntry_attributes,
{ "attributes", "ldap.attributes",
FT_UINT32, BASE_DEC, NULL, 0,
"PartialAttributeList", HFILL }},
{ &hf_ldap_PartialAttributeList_item,
{ "PartialAttributeList item", "ldap.PartialAttributeList_item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ldap__untag_item,
{ "LDAPURL", "ldap.LDAPURL",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ldap_object,
{ "object", "ldap.object",
FT_STRING, BASE_NONE, NULL, 0,
"LDAPDN", HFILL }},
{ &hf_ldap_modifyRequest_modification,
{ "modification", "ldap.modification",
FT_UINT32, BASE_DEC, NULL, 0,
"ModifyRequest_modification", HFILL }},
{ &hf_ldap_modifyRequest_modification_item,
{ "modification item", "ldap.modification_item_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_modifyRequest_modification_item", HFILL }},
{ &hf_ldap_operation,
{ "operation", "ldap.operation",
FT_UINT32, BASE_DEC, VALS(ldap_T_operation_vals), 0,
NULL, HFILL }},
{ &hf_ldap_modification,
{ "modification", "ldap.modification_element",
FT_NONE, BASE_NONE, NULL, 0,
"AttributeTypeAndValues", HFILL }},
{ &hf_ldap_entry,
{ "entry", "ldap.entry",
FT_STRING, BASE_NONE, NULL, 0,
"LDAPDN", HFILL }},
{ &hf_ldap_attributes,
{ "attributes", "ldap.attributes",
FT_UINT32, BASE_DEC, NULL, 0,
"AttributeList", HFILL }},
{ &hf_ldap_AttributeList_item,
{ "AttributeList item", "ldap.AttributeList_item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ldap_newrdn,
{ "newrdn", "ldap.newrdn",
FT_STRING, BASE_NONE, NULL, 0,
"RelativeLDAPDN", HFILL }},
{ &hf_ldap_deleteoldrdn,
{ "deleteoldrdn", "ldap.deleteoldrdn",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ldap_newSuperior,
{ "newSuperior", "ldap.newSuperior",
FT_STRING, BASE_NONE, NULL, 0,
"LDAPDN", HFILL }},
{ &hf_ldap_ava,
{ "ava", "ldap.ava_element",
FT_NONE, BASE_NONE, NULL, 0,
"AttributeValueAssertion", HFILL }},
{ &hf_ldap_requestName,
{ "requestName", "ldap.requestName",
FT_STRING, BASE_NONE, NULL, 0,
"LDAPOID", HFILL }},
{ &hf_ldap_requestValue,
{ "requestValue", "ldap.requestValue",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ldap_extendedResponse_resultCode,
{ "resultCode", "ldap.resultCode",
FT_UINT32, BASE_DEC, VALS(ldap_ExtendedResponse_resultCode_vals), 0,
"ExtendedResponse_resultCode", HFILL }},
{ &hf_ldap_responseName,
{ "responseName", "ldap.responseName",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ldap_response,
{ "response", "ldap.response",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_ldap_intermediateResponse_responseValue,
{ "responseValue", "ldap.responseValue",
FT_BYTES, BASE_NONE, NULL, 0,
"T_intermediateResponse_responseValue", HFILL }},
{ &hf_ldap_size,
{ "size", "ldap.size",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_ldap_cookie,
{ "cookie", "ldap.cookie",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_ldap_SortKeyList_item,
{ "SortKeyList item", "ldap.SortKeyList_item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ldap_attributeType,
{ "attributeType", "ldap.attributeType",
FT_STRING, BASE_NONE, NULL, 0,
"AttributeDescription", HFILL }},
{ &hf_ldap_orderingRule,
{ "orderingRule", "ldap.orderingRule",
FT_STRING, BASE_NONE, NULL, 0,
"MatchingRuleId", HFILL }},
{ &hf_ldap_reverseOrder,
{ "reverseOrder", "ldap.reverseOrder",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ldap_sortResult,
{ "sortResult", "ldap.sortResult",
FT_UINT32, BASE_DEC, VALS(ldap_T_sortResult_vals), 0,
NULL, HFILL }},
{ &hf_ldap_flags,
{ "flags", "ldap.flags",
FT_UINT32, BASE_HEX, NULL, 0,
"DirSyncFlags", HFILL }},
{ &hf_ldap_maxBytes,
{ "maxBytes", "ldap.maxBytes",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_ldap_userIdentity,
{ "userIdentity", "ldap.userIdentity",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_ldap_oldPasswd,
{ "oldPasswd", "ldap.oldPasswd",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_ldap_newPasswd,
{ "newPasswd", "ldap.newPasswd",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_ldap_cancelID,
{ "cancelID", "ldap.cancelID",
FT_UINT32, BASE_DEC, NULL, 0,
"MessageID", HFILL }},
{ &hf_ldap_mode,
{ "mode", "ldap.mode",
FT_UINT32, BASE_DEC, VALS(ldap_T_mode_vals), 0,
NULL, HFILL }},
{ &hf_ldap_reloadHint,
{ "reloadHint", "ldap.reloadHint",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ldap_state,
{ "state", "ldap.state",
FT_UINT32, BASE_DEC, VALS(ldap_T_state_vals), 0,
NULL, HFILL }},
{ &hf_ldap_entryUUID,
{ "entryUUID", "ldap.entryUUID",
FT_BYTES, BASE_NONE, NULL, 0,
"SyncUUID", HFILL }},
{ &hf_ldap_refreshDeletes,
{ "refreshDeletes", "ldap.refreshDeletes",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ldap_newcookie,
{ "newcookie", "ldap.newcookie",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_ldap_refreshDelete,
{ "refreshDelete", "ldap.refreshDelete_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ldap_refreshDone,
{ "refreshDone", "ldap.refreshDone",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_ldap_refreshPresent,
{ "refreshPresent", "ldap.refreshPresent_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ldap_syncIdSet,
{ "syncIdSet", "ldap.syncIdSet_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ldap_syncUUIDs,
{ "syncUUIDs", "ldap.syncUUIDs",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_OF_SyncUUID", HFILL }},
{ &hf_ldap_syncUUIDs_item,
{ "SyncUUID", "ldap.SyncUUID",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ldap_warning,
{ "warning", "ldap.warning",
FT_UINT32, BASE_DEC, VALS(ldap_T_warning_vals), 0,
NULL, HFILL }},
{ &hf_ldap_timeBeforeExpiration,
{ "timeBeforeExpiration", "ldap.timeBeforeExpiration",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_maxInt", HFILL }},
{ &hf_ldap_graceAuthNsRemaining,
{ "graceAuthNsRemaining", "ldap.graceAuthNsRemaining",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_maxInt", HFILL }},
{ &hf_ldap_error,
{ "error", "ldap.error",
FT_UINT32, BASE_DEC, VALS(ldap_T_error_vals), 0,
NULL, HFILL }},
#line 2217 "../../asn1/ldap/packet-ldap-template.c"
};
static gint *ett[] = {
&ett_ldap,
&ett_ldap_payload,
&ett_ldap_sasl_blob,
&ett_ldap_msg,
&ett_mscldap_netlogon_flags,
&ett_mscldap_ntver_flags,
&ett_mscldap_ipdetails,
&ett_ldap_DirSyncFlagsSubEntry,
#line 1 "../../asn1/ldap/packet-ldap-ettarr.c"
&ett_ldap_LDAPMessage,
&ett_ldap_ProtocolOp,
&ett_ldap_AttributeDescriptionList,
&ett_ldap_AttributeValueAssertion,
&ett_ldap_Attribute,
&ett_ldap_SET_OF_AttributeValue,
&ett_ldap_LDAPResult,
&ett_ldap_Referral,
&ett_ldap_Controls,
&ett_ldap_Control,
&ett_ldap_BindRequest_U,
&ett_ldap_AuthenticationChoice,
&ett_ldap_SaslCredentials,
&ett_ldap_BindResponse_U,
&ett_ldap_SearchRequest_U,
&ett_ldap_Filter,
&ett_ldap_T_and,
&ett_ldap_T_or,
&ett_ldap_SubstringFilter,
&ett_ldap_T_substringFilter_substrings,
&ett_ldap_T_substringFilter_substrings_item,
&ett_ldap_MatchingRuleAssertion,
&ett_ldap_SearchResultEntry_U,
&ett_ldap_PartialAttributeList,
&ett_ldap_PartialAttributeList_item,
&ett_ldap_SEQUENCE_OF_LDAPURL,
&ett_ldap_ModifyRequest_U,
&ett_ldap_ModifyRequest_modification,
&ett_ldap_T_modifyRequest_modification_item,
&ett_ldap_AttributeTypeAndValues,
&ett_ldap_AddRequest_U,
&ett_ldap_AttributeList,
&ett_ldap_AttributeList_item,
&ett_ldap_ModifyDNRequest_U,
&ett_ldap_CompareRequest_U,
&ett_ldap_ExtendedRequest_U,
&ett_ldap_ExtendedResponse_U,
&ett_ldap_IntermediateResponse_U,
&ett_ldap_SearchControlValue,
&ett_ldap_SortKeyList,
&ett_ldap_SortKeyList_item,
&ett_ldap_SortResult,
&ett_ldap_DirSyncControlValue,
&ett_ldap_PasswdModifyRequestValue,
&ett_ldap_CancelRequestValue,
&ett_ldap_SyncRequestValue,
&ett_ldap_SyncStateValue,
&ett_ldap_SyncDoneValue,
&ett_ldap_SyncInfoValue,
&ett_ldap_T_refreshDelete,
&ett_ldap_T_refreshPresent,
&ett_ldap_T_syncIdSet,
&ett_ldap_SET_OF_SyncUUID,
&ett_ldap_PasswordPolicyResponseValue,
&ett_ldap_T_warning,
#line 2231 "../../asn1/ldap/packet-ldap-template.c"
};
static uat_field_t custom_attribute_types_uat_fields[] = {
UAT_FLD_CSTRING(attribute_types, attribute_type, "Attribute type", "Attribute type"),
UAT_FLD_CSTRING(attribute_types, attribute_desc, "Description", "Description of the value matching type"),
UAT_END_FIELDS
};
static ei_register_info ei[] = {
{ &ei_ldap_exceeded_filter_length, { "ldap.exceeded_filter_length", PI_UNDECODED, PI_ERROR, "Filter length exceeds number. Giving up", EXPFILL }},
{ &ei_ldap_too_many_filter_elements, { "ldap.too_many_filter_elements", PI_UNDECODED, PI_ERROR, "Found more than %%u filter elements. Giving up.", EXPFILL }},
};
expert_module_t* expert_ldap;
module_t *ldap_module;
uat_t *attributes_uat;
proto_ldap = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_ldap, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_ldap = expert_register_protocol(proto_ldap);
expert_register_field_array(expert_ldap, ei, array_length(ei));
new_register_dissector("ldap", dissect_ldap_tcp, proto_ldap);
ldap_module = prefs_register_protocol(proto_ldap, prefs_register_ldap);
prefs_register_bool_preference(ldap_module, "desegment_ldap_messages",
"Reassemble LDAP messages spanning multiple TCP segments",
"Whether the LDAP dissector should reassemble messages spanning multiple TCP segments."
" To use this option, you must also enable \"Allow subdissectors to reassemble TCP streams\" in the TCP protocol settings.",
&ldap_desegment);
prefs_register_uint_preference(ldap_module, "tcp.port", "LDAP TCP Port",
"Set the port for LDAP operations",
10, &global_ldap_tcp_port);
prefs_register_uint_preference(ldap_module, "ssl.port", "LDAPS TCP Port",
"Set the port for LDAP operations over SSL",
10, &global_ldaps_tcp_port);
attributes_uat = uat_new("Custom LDAP AttributeValue types",
sizeof(attribute_type_t),
"custom_ldap_attribute_types",
TRUE,
&attribute_types,
&num_attribute_types,
UAT_AFFECTS_DISSECTION|UAT_AFFECTS_FIELDS,
NULL,
attribute_types_copy_cb,
attribute_types_update_cb,
attribute_types_free_cb,
attribute_types_initialize_cb,
custom_attribute_types_uat_fields);
prefs_register_uat_preference(ldap_module, "custom_ldap_attribute_types",
"Custom AttributeValue types",
"A table to define custom LDAP attribute type values for which fields can be setup and used for filtering/data extraction etc.",
attributes_uat);
prefs_register_obsolete_preference(ldap_module, "max_pdu");
proto_cldap = proto_register_protocol(
"Connectionless Lightweight Directory Access Protocol",
"CLDAP", "cldap");
register_cleanup_routine(ldap_cleanup);
ldap_tap=register_tap("ldap");
ldap_name_dissector_table = register_dissector_table("ldap.name", "LDAP Attribute Type Dissectors", FT_STRING, BASE_NONE);
register_srt_table(proto_ldap, NULL, 1, ldapstat_packet, ldapstat_init, NULL);
}
void
proto_reg_handoff_ldap(void)
{
dissector_handle_t cldap_handle;
ldap_handle = find_dissector("ldap");
dissector_add_uint("tcp.port", TCP_PORT_GLOBALCAT_LDAP, ldap_handle);
cldap_handle = create_dissector_handle(dissect_mscldap, proto_cldap);
dissector_add_uint("udp.port", UDP_PORT_CLDAP, cldap_handle);
gssapi_handle = find_dissector("gssapi");
gssapi_wrap_handle = find_dissector("gssapi_verf");
spnego_handle = find_dissector("spnego");
ntlmssp_handle = find_dissector("ntlmssp");
ssl_handle = find_dissector("ssl");
prefs_register_ldap();
oid_add_from_string("LDAP_PAGED_RESULT_OID_STRING","1.2.840.113556.1.4.319");
oid_add_from_string("LDAP_SERVER_SHOW_DELETED_OID","1.2.840.113556.1.4.417");
oid_add_from_string("LDAP_SERVER_SORT_OID","1.2.840.113556.1.4.473");
oid_add_from_string("LDAP_CONTROL_SORT_RESP_OID","1.2.840.113556.1.4.474");
oid_add_from_string("LDAP_SERVER_CROSSDOM_MOVE_TARGET_OID","1.2.840.113556.1.4.521");
oid_add_from_string("LDAP_SERVER_NOTIFICATION_OID","1.2.840.113556.1.4.528");
oid_add_from_string("LDAP_SERVER_EXTENDED_DN_OID","1.2.840.113556.1.4.529");
oid_add_from_string("meetingAdvertiseScope","1.2.840.113556.1.4.582");
oid_add_from_string("LDAP_SERVER_LAZY_COMMIT_OID","1.2.840.113556.1.4.619");
oid_add_from_string("mhsORAddress","1.2.840.113556.1.4.650");
oid_add_from_string("managedObjects","1.2.840.113556.1.4.654");
oid_add_from_string("LDAP_CAP_ACTIVE_DIRECTORY_OID","1.2.840.113556.1.4.800");
oid_add_from_string("LDAP_SERVER_SD_FLAGS_OID","1.2.840.113556.1.4.801");
oid_add_from_string("LDAP_OID_COMPARATOR_OR","1.2.840.113556.1.4.804");
oid_add_from_string("LDAP_SERVER_TREE_DELETE_OID","1.2.840.113556.1.4.805");
oid_add_from_string("LDAP_SERVER_DIRSYNC_OID","1.2.840.113556.1.4.841");
oid_add_from_string("None","1.2.840.113556.1.4.970");
oid_add_from_string("LDAP_SERVER_VERIFY_NAME_OID","1.2.840.113556.1.4.1338");
oid_add_from_string("LDAP_SERVER_DOMAIN_SCOPE_OID","1.2.840.113556.1.4.1339");
oid_add_from_string("LDAP_SERVER_SEARCH_OPTIONS_OID","1.2.840.113556.1.4.1340");
oid_add_from_string("LDAP_SERVER_PERMISSIVE_MODIFY_OID","1.2.840.113556.1.4.1413");
oid_add_from_string("LDAP_SERVER_ASQ_OID","1.2.840.113556.1.4.1504");
oid_add_from_string("LDAP_CAP_ACTIVE_DIRECTORY_V51_OID","1.2.840.113556.1.4.1670");
oid_add_from_string("LDAP_SERVER_FAST_BIND_OID","1.2.840.113556.1.4.1781");
oid_add_from_string("LDAP_CAP_ACTIVE_DIRECTORY_LDAP_INTEG_OID","1.2.840.113556.1.4.1791");
oid_add_from_string("msDS-ObjectReference","1.2.840.113556.1.4.1840");
oid_add_from_string("msDS-QuotaEffective","1.2.840.113556.1.4.1848");
oid_add_from_string("LDAP_CAP_ACTIVE_DIRECTORY_ADAM_OID","1.2.840.113556.1.4.1851");
oid_add_from_string("msDS-PortSSL","1.2.840.113556.1.4.1860");
oid_add_from_string("msDS-isRODC","1.2.840.113556.1.4.1960");
oid_add_from_string("msDS-SDReferenceDomain","1.2.840.113556.1.4.1711");
oid_add_from_string("msDS-AdditionalDnsHostName","1.2.840.113556.1.4.1717");
oid_add_from_string("None","1.3.6.1.4.1.1466.101.119.1");
oid_add_from_string("LDAP_START_TLS_OID","1.3.6.1.4.1.1466.20037");
oid_add_from_string("LDAP_CONTROL_VLVREQUEST VLV","2.16.840.1.113730.3.4.9");
oid_add_from_string("LDAP_CONTROL_VLVRESPONSE VLV","2.16.840.1.113730.3.4.10");
oid_add_from_string("LDAP_SERVER_QUOTA_CONTROL_OID","1.2.840.113556.1.4.1852");
oid_add_from_string("LDAP_SERVER_RANGE_OPTION_OID","1.2.840.113556.1.4.802");
oid_add_from_string("LDAP_SERVER_SHUTDOWN_NOTIFY_OID","1.2.840.113556.1.4.1907");
oid_add_from_string("LDAP_SERVER_RANGE_RETRIEVAL_NOERR_OID","1.2.840.113556.1.4.1948");
register_ldap_name_dissector("netlogon", dissect_NetLogon_PDU, proto_cldap);
register_ldap_name_dissector("objectGUID", dissect_ldap_guid, proto_ldap);
register_ldap_name_dissector("supportedControl", dissect_ldap_oid, proto_ldap);
register_ldap_name_dissector("supportedCapabilities", dissect_ldap_oid, proto_ldap);
register_ldap_name_dissector("objectSid", dissect_ldap_sid, proto_ldap);
register_ldap_name_dissector("nTSecurityDescriptor", dissect_ldap_nt_sec_desc, proto_ldap);
#line 1 "../../asn1/ldap/packet-ldap-dis-tab.c"
new_register_ber_oid_dissector("1.2.840.113556.1.4.319", dissect_SearchControlValue_PDU, proto_ldap, "pagedResultsControl");
new_register_ber_oid_dissector("1.2.840.113556.1.4.473", dissect_SortKeyList_PDU, proto_ldap, "sortKeyList");
new_register_ber_oid_dissector("1.2.840.113556.1.4.474", dissect_SortResult_PDU, proto_ldap, "sortResult");
new_register_ber_oid_dissector("1.2.840.113556.1.4.841", dissect_DirSyncControlValue_PDU, proto_ldap, "dirsync");
new_register_ber_oid_dissector("1.3.6.1.4.1.4203.1.11.1", dissect_PasswdModifyRequestValue_PDU, proto_ldap, "passwdModifyOID");
new_register_ber_oid_dissector("1.3.6.1.1.8", dissect_CancelRequestValue_PDU, proto_ldap, "cancelRequestOID");
new_register_ber_oid_dissector("1.3.6.1.4.1.4203.1.9.1.1", dissect_SyncRequestValue_PDU, proto_ldap, "syncRequestOID");
new_register_ber_oid_dissector("1.3.6.1.4.1.4203.1.9.1.2", dissect_SyncStateValue_PDU, proto_ldap, "syncStateOID");
new_register_ber_oid_dissector("1.3.6.1.4.1.4203.1.9.1.3", dissect_SyncDoneValue_PDU, proto_ldap, "syncDoneOID");
new_register_ber_oid_dissector("1.3.6.1.4.1.4203.1.9.1.4", dissect_SyncInfoValue_PDU, proto_ldap, "syncInfoOID");
new_register_ber_oid_dissector("1.3.6.1.4.1.42.2.27.8.5.1", dissect_PasswordPolicyResponseValue_PDU, proto_ldap, "passwordPolicy");
#line 2381 "../../asn1/ldap/packet-ldap-template.c"
}
static void
prefs_register_ldap(void)
{
if(tcp_port != global_ldap_tcp_port) {
if(tcp_port)
dissector_delete_uint("tcp.port", tcp_port, ldap_handle);
tcp_port = global_ldap_tcp_port;
if(tcp_port)
dissector_add_uint("tcp.port", tcp_port, ldap_handle);
}
if(ssl_port != global_ldaps_tcp_port) {
if(ssl_port)
ssl_dissector_delete(ssl_port, "ldap", TRUE);
ssl_port = global_ldaps_tcp_port;
if(ssl_port)
ssl_dissector_add(ssl_port, "ldap", TRUE);
}
}
