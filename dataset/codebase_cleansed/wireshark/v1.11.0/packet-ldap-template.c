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
static void
attribute_types_update_cb(void *r, const char **err)
{
attribute_type_t *rec = (attribute_type_t *)r;
char c;
if (rec->attribute_type == NULL) {
*err = wmem_strdup_printf(wmem_packet_scope(), "Attribute type can't be empty");
return;
}
g_strstrip(rec->attribute_type);
if (rec->attribute_type[0] == 0) {
*err = wmem_strdup_printf(wmem_packet_scope(), "Attribute type can't be empty");
return;
}
c = proto_check_field_name(rec->attribute_type);
if (c) {
*err = wmem_strdup_printf(wmem_packet_scope(), "Attribute type can't contain '%c'", c);
return;
}
*err = NULL;
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
if (attribute_types_hash) {
guint hf_size = g_hash_table_size (attribute_types_hash);
for (i = 0; i < hf_size; i++) {
proto_unregister_field (proto_ldap, *(hf[i].p_id));
g_free (hf[i].p_id);
g_free ((char *) hf[i].hfinfo.name);
g_free ((char *) hf[i].hfinfo.abbrev);
g_free ((char *) hf[i].hfinfo.blurb);
}
g_hash_table_destroy (attribute_types_hash);
g_free (hf);
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
guint32 flags;
proto_item *item;
proto_tree *tree=NULL;
guint fields[] = {
hf_mscldap_ntver_flags_v1,
hf_mscldap_ntver_flags_v5,
hf_mscldap_ntver_flags_v5ex,
hf_mscldap_ntver_flags_v5ep,
hf_mscldap_ntver_flags_vcs,
hf_mscldap_ntver_flags_vnt4,
hf_mscldap_ntver_flags_vpdc,
hf_mscldap_ntver_flags_vip,
hf_mscldap_ntver_flags_vl,
hf_mscldap_ntver_flags_vgc,
0 };
guint *field;
header_field_info *hfi;
gboolean one_bit_set = FALSE;
flags=tvb_get_letohl(tvb, offset);
item=proto_tree_add_item(parent_tree, hf_mscldap_ntver_flags, tvb, offset, 4, ENC_LITTLE_ENDIAN);
if(parent_tree){
tree = proto_item_add_subtree(item, ett_mscldap_ntver_flags);
}
proto_item_append_text(item, " (");
for(field = fields; *field; field++) {
proto_tree_add_boolean(tree, *field, tvb, offset, 4, flags);
hfi = proto_registrar_get_nth(*field);
if(flags & hfi->bitmask) {
if(one_bit_set)
proto_item_append_text(item, ", ");
else
one_bit_set = TRUE;
proto_item_append_text(item, "%s", hfi->name);
}
}
proto_item_append_text(item, ")");
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
len=tvb_length_remaining(tvb,offset);
}
if(len==0){
return offset;
}
if(attributedesc_string && !strncmp("DomainSid", attributedesc_string, 9)){
tvbuff_t *sid_tvb;
char *tmpstr;
sid_tvb=tvb_new_subset(tvb, offset, len, len);
dissect_nt_sid(sid_tvb, 0, tree, "SID", &tmpstr, hf_index);
ldapvalue_string=tmpstr;
goto finished;
} else if ( (len==16)
&& (attributedesc_string && !strncmp("DomainGuid", attributedesc_string, 10))) {
guint8 drep[4] = { 0x10, 0x00, 0x00, 0x00};
e_uuid_t uuid;
dissect_dcerpc_uuid_t(tvb, offset, actx->pinfo, tree, drep, hf_ldap_guid, &uuid);
ldapvalue_string=(char*)wmem_alloc(wmem_packet_scope(), 1024);
g_snprintf(ldapvalue_string, 1023, "%08x-%04x-%04x-%02x%02x-%02x%02x%02x%02x%02x%02x",
uuid.Data1, uuid.Data2, uuid.Data3,
uuid.Data4[0], uuid.Data4[1],
uuid.Data4[2], uuid.Data4[3],
uuid.Data4[4], uuid.Data4[5],
uuid.Data4[6], uuid.Data4[7]);
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
if(!isascii(str[i]) || !isprint(str[i])){
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
ldap_match_call_response(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint messageId, guint protocolOpTag)
{
ldap_call_response_t lcr, *lcrp=NULL;
ldap_conv_info_t *ldap_info = (ldap_conv_info_t *)pinfo->private_data;
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
length_remaining = tvb_ensure_length_remaining(tvb, offset);
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
pinfo->private_data = ldap_info;
dissect_LDAPMessage_PDU(msg_tvb, pinfo, tree);
offset += msg_len;
if(tvb_length_remaining(tvb, offset)>=6){
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
length_remaining = tvb_ensure_length_remaining(tvb, offset);
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
proto_item *sasl_item = NULL;
proto_tree *sasl_tree = NULL;
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
if (ldap_tree) {
proto_tree_add_uint(ldap_tree, hf_ldap_sasl_buffer_length, sasl_tvb, 0, 4,
sasl_len);
sasl_item = proto_tree_add_text(ldap_tree, sasl_tvb, 0, sasl_msg_len, "SASL Buffer");
sasl_tree = proto_item_add_subtree(sasl_item, ett_ldap_sasl_blob);
}
if (ldap_info->auth_mech != NULL &&
((strcmp(ldap_info->auth_mech, "GSS-SPNEGO") == 0) ||
(strcmp(ldap_info->auth_mech, "GSSAPI") == 0))) {
tvbuff_t *gssapi_tvb, *plain_tvb = NULL, *decr_tvb= NULL;
int ver_len;
int tmp_length;
tmp_length = tvb_length_remaining(sasl_tvb, 4);
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
}
pinfo->decrypt_gssapi_tvb=0;
pinfo->gssapi_wrap_tvb=NULL;
pinfo->gssapi_encrypted_tvb=NULL;
pinfo->gssapi_decrypted_tvb=NULL;
if(ver_len==0){
return;
}
if (!decr_tvb) {
if(!pinfo->gssapi_data_encrypted){
plain_tvb = tvb_new_subset_remaining(gssapi_tvb, ver_len);
}
}
if (decr_tvb) {
proto_item *enc_item = NULL;
proto_tree *enc_tree = NULL;
col_set_str(pinfo->cinfo, COL_INFO, "SASL GSS-API Privacy (decrypted): ");
if (sasl_tree) {
enc_item = proto_tree_add_text(sasl_tree, gssapi_tvb, ver_len, -1,
"GSS-API Encrypted payload (%d byte%s)",
sasl_len - ver_len,
plurality(sasl_len - ver_len, "", "s"));
enc_tree = proto_item_add_subtree(enc_item, ett_ldap_payload);
}
dissect_ldap_payload(decr_tvb, pinfo, enc_tree, ldap_info, is_mscldap);
} else if (plain_tvb) {
proto_item *plain_item = NULL;
proto_tree *plain_tree = NULL;
col_set_str(pinfo->cinfo, COL_INFO, "SASL GSS-API Integrity: ");
if (sasl_tree) {
plain_item = proto_tree_add_text(sasl_tree, gssapi_tvb, ver_len, -1,
"GSS-API payload (%d byte%s)",
sasl_len - ver_len,
plurality(sasl_len - ver_len, "", "s"));
plain_tree = proto_item_add_subtree(plain_item, ett_ldap_payload);
}
dissect_ldap_payload(plain_tvb, pinfo, plain_tree, ldap_info, is_mscldap);
} else {
col_add_fstr(pinfo->cinfo, COL_INFO, "SASL GSS-API Privacy: payload (%d byte%s)",
sasl_len - ver_len,
plurality(sasl_len - ver_len, "", "s"));
if (sasl_tree) {
proto_tree_add_text(sasl_tree, gssapi_tvb, ver_len, -1,
"GSS-API Encrypted payload (%d byte%s)",
sasl_len - ver_len,
plurality(sasl_len - ver_len, "", "s"));
}
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
guint32 flags;
proto_item *item;
proto_tree *tree=NULL;
guint fields[] = {
hf_mscldap_netlogon_flags_fnc,
hf_mscldap_netlogon_flags_dnc,
hf_mscldap_netlogon_flags_dns,
hf_mscldap_netlogon_flags_wdc,
hf_mscldap_netlogon_flags_rodc,
hf_mscldap_netlogon_flags_ndnc,
hf_mscldap_netlogon_flags_good_timeserv,
hf_mscldap_netlogon_flags_writable,
hf_mscldap_netlogon_flags_closest,
hf_mscldap_netlogon_flags_timeserv,
hf_mscldap_netlogon_flags_kdc,
hf_mscldap_netlogon_flags_ds,
hf_mscldap_netlogon_flags_ldap,
hf_mscldap_netlogon_flags_gc,
hf_mscldap_netlogon_flags_pdc,
0 };
guint *field;
header_field_info *hfi;
gboolean one_bit_set = FALSE;
flags=tvb_get_letohl(tvb, offset);
item=proto_tree_add_item(parent_tree, hf_mscldap_netlogon_flags, tvb, offset, 4, ENC_LITTLE_ENDIAN);
if(parent_tree){
tree = proto_item_add_subtree(item, ett_mscldap_netlogon_flags);
}
proto_item_append_text(item, " (");
for(field = fields; *field; field++) {
proto_tree_add_boolean(tree, *field, tvb, offset, 4, flags);
hfi = proto_registrar_get_nth(*field);
if(flags & hfi->bitmask) {
if(one_bit_set)
proto_item_append_text(item, ", ");
else
one_bit_set = TRUE;
proto_item_append_text(item, "%s", hfi->name);
}
}
proto_item_append_text(item, ")");
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
len=tvb_length_remaining(tvb,offset);
if (len < 10) return;
proto_tree_add_item(tree, hf_mscldap_netlogon_opcode, tvb, offset, 2, ENC_LITTLE_ENDIAN);
itype = tvb_get_letohs(tvb, offset);
offset += 2;
version = tvb_get_letohl(tvb,len-8);
switch(itype){
case LOGON_SAM_LOGON_RESPONSE:
bc = tvb_length_remaining(tvb, offset);
fn = get_unicode_or_ascii_string(tvb,&offset,TRUE,&fn_len,FALSE,FALSE,&bc);
proto_tree_add_string(tree, hf_mscldap_nb_hostname, tvb,offset, fn_len, fn);
offset +=fn_len;
fn = get_unicode_or_ascii_string(tvb,&offset,TRUE,&fn_len,FALSE,FALSE,&bc);
proto_tree_add_string(tree, hf_mscldap_username, tvb,offset, fn_len, fn);
offset +=fn_len;
fn = get_unicode_or_ascii_string(tvb,&offset,TRUE,&fn_len,FALSE,FALSE,&bc);
proto_tree_add_string(tree, hf_mscldap_nb_domain, tvb,offset, fn_len, fn);
offset +=fn_len;
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
get_sasl_ldap_pdu_len(packet_info *pinfo _U_, tvbuff_t *tvb, int offset)
{
return tvb_get_ntohl(tvb, offset)+4;
}
static void
dissect_sasl_ldap_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
dissect_ldap_pdu(tvb, pinfo, tree, FALSE);
return;
}
static guint
get_normal_ldap_pdu_len(packet_info *pinfo _U_, tvbuff_t *tvb, int offset)
{
guint32 len;
gboolean ind;
int data_offset;
data_offset=get_ber_length(tvb, offset+1, &len, &ind);
return len+data_offset-offset;
}
static void
dissect_normal_ldap_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
dissect_ldap_pdu(tvb, pinfo, tree, FALSE);
return;
}
static void
dissect_ldap_oid(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
char *oid;
const char *oidname;
oid=tvb_get_string(wmem_packet_scope(), tvb, 0, tvb_length(tvb));
if(!oid){
return;
}
oidname=oid_resolved_from_string(oid);
if(oidname){
proto_tree_add_text(tree, tvb, 0, tvb_length(tvb), "OID: %s (%s)",oid,oidname);
} else {
proto_tree_add_text(tree, tvb, 0, tvb_length(tvb), "OID: %s",oid);
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
dissect_nt_sec_desc(tvb, 0, pinfo, tree, NULL, TRUE, tvb_length(tvb), &ldap_access_mask_info);
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
e_uuid_t uuid;
dissect_dcerpc_uuid_t(tvb, 0, pinfo, tree, drep, hf_ldap_guid, &uuid);
ldapvalue_string=(char*)wmem_alloc(wmem_packet_scope(), 1024);
g_snprintf(ldapvalue_string, 1023, "%08x-%04x-%04x-%02x%02x-%02x%02x%02x%02x%02x%02x",
uuid.Data1, uuid.Data2, uuid.Data3,
uuid.Data4[0], uuid.Data4[1],
uuid.Data4[2], uuid.Data4[3],
uuid.Data4[4], uuid.Data4[5],
uuid.Data4[6], uuid.Data4[7]);
}
static void
dissect_ldap_tcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
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
tcp_dissect_pdus(tvb, pinfo, tree, ldap_desegment, 4, get_sasl_ldap_pdu_len, dissect_sasl_ldap_pdu);
return;
this_was_not_sasl:
if(tvb_get_guint8(tvb, 0)!=0x30){
goto this_was_not_normal_ldap;
}
get_ber_length(tvb, 1, &ldap_len, &ind);
if(ldap_len<2){
goto this_was_not_normal_ldap;
}
tcp_dissect_pdus(tvb, pinfo, tree, ldap_desegment, 7, get_normal_ldap_pdu_len, dissect_normal_ldap_pdu);
goto end;
this_was_not_normal_ldap:
if(ldap_info &&
ldap_info->start_tls_frame &&
( pinfo->fd->num >= ldap_info->start_tls_frame)) {
guint32 old_start_tls_frame;
dissector_delete_uint("tcp.port", tcp_port, ldap_handle);
ssl_dissector_add(tcp_port, "ldap", TRUE);
old_start_tls_frame = ldap_info->start_tls_frame;
ldap_info->start_tls_frame = 0;
pinfo->can_desegment++;
call_dissector(ssl_handle, tvb, pinfo, tree);
ldap_info->start_tls_frame = old_start_tls_frame;
ssl_dissector_delete(tcp_port, "ldap", TRUE);
dissector_add_uint("tcp.port", tcp_port, ldap_handle);
return;
}
if ((sasl_len + 4) == (guint32)tvb_length_remaining(tvb, 0))
tcp_dissect_pdus(tvb, pinfo, tree, ldap_desegment, 4, get_sasl_ldap_pdu_len, dissect_sasl_ldap_pdu);
end:
return;
}
static void
dissect_mscldap(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
dissect_ldap_pdu(tvb, pinfo, tree, TRUE);
return;
}
static void
ldap_reinit(void)
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
{ "Create Child", "ldap.AccessMask.ADS_CREATE_CHILD", FT_BOOLEAN, 32, TFS(&ldap_AccessMask_ADS_CREATE_CHILD_tfs), LDAP_ACCESSMASK_ADS_CREATE_CHILD, NULL, HFILL }},
{ &hf_ldap_AccessMask_ADS_DELETE_CHILD,
{ "Delete Child", "ldap.AccessMask.ADS_DELETE_CHILD", FT_BOOLEAN, 32, TFS(&ldap_AccessMask_ADS_DELETE_CHILD_tfs), LDAP_ACCESSMASK_ADS_DELETE_CHILD, NULL, HFILL }},
{ &hf_ldap_AccessMask_ADS_LIST,
{ "List", "ldap.AccessMask.ADS_LIST", FT_BOOLEAN, 32, TFS(&ldap_AccessMask_ADS_LIST_tfs), LDAP_ACCESSMASK_ADS_LIST, NULL, HFILL }},
{ &hf_ldap_AccessMask_ADS_SELF_WRITE,
{ "Self Write", "ldap.AccessMask.ADS_SELF_WRITE", FT_BOOLEAN, 32, TFS(&ldap_AccessMask_ADS_SELF_WRITE_tfs), LDAP_ACCESSMASK_ADS_SELF_WRITE, NULL, HFILL }},
{ &hf_ldap_AccessMask_ADS_READ_PROP,
{ "Read Prop", "ldap.AccessMask.ADS_READ_PROP", FT_BOOLEAN, 32, TFS(&ldap_AccessMask_ADS_READ_PROP_tfs), LDAP_ACCESSMASK_ADS_READ_PROP, NULL, HFILL }},
{ &hf_ldap_AccessMask_ADS_WRITE_PROP,
{ "Write Prop", "ldap.AccessMask.ADS_WRITE_PROP", FT_BOOLEAN, 32, TFS(&ldap_AccessMask_ADS_WRITE_PROP_tfs), LDAP_ACCESSMASK_ADS_WRITE_PROP, NULL, HFILL }},
{ &hf_ldap_AccessMask_ADS_DELETE_TREE,
{ "Delete Tree", "ldap.AccessMask.ADS_DELETE_TREE", FT_BOOLEAN, 32, TFS(&ldap_AccessMask_ADS_DELETE_TREE_tfs), LDAP_ACCESSMASK_ADS_DELETE_TREE, NULL, HFILL }},
{ &hf_ldap_AccessMask_ADS_LIST_OBJECT,
{ "List Object", "ldap.AccessMask.ADS_LIST_OBJECT", FT_BOOLEAN, 32, TFS(&ldap_AccessMask_ADS_LIST_OBJECT_tfs), LDAP_ACCESSMASK_ADS_LIST_OBJECT, NULL, HFILL }},
{ &hf_ldap_AccessMask_ADS_CONTROL_ACCESS,
{ "Control Access", "ldap.AccessMask.ADS_CONTROL_ACCESS", FT_BOOLEAN, 32, TFS(&ldap_AccessMask_ADS_CONTROL_ACCESS_tfs), LDAP_ACCESSMASK_ADS_CONTROL_ACCESS, NULL, HFILL }},
#include "packet-ldap-hfarr.c"
};
static gint *ett[] = {
&ett_ldap,
&ett_ldap_payload,
&ett_ldap_sasl_blob,
&ett_ldap_msg,
&ett_mscldap_netlogon_flags,
&ett_mscldap_ntver_flags,
&ett_mscldap_ipdetails,
#include "packet-ldap-ettarr.c"
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
register_dissector("ldap", dissect_ldap_tcp, proto_ldap);
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
(void**) &attribute_types,
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
register_init_routine(ldap_reinit);
ldap_tap=register_tap("ldap");
ldap_name_dissector_table = register_dissector_table("ldap.name", "LDAP Attribute Type Dissectors", FT_STRING, BASE_NONE);
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
#include "packet-ldap-dis-tab.c"
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
