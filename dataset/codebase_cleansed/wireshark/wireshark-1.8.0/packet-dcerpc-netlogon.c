static void printnbyte(const guint8* tab,int nb,const char* txt,const char* txt2)
{
int i=0;
debugprintf("%s ",txt);
for(i=0;i<nb;i++)
{
debugprintf("%02X ",*(tab+i));
}
debugprintf("%s",txt2);
}
static void printnbyte(const guint8* tab _U_,int nb _U_,const char* txt _U_,const char* txt2 _U_) {}
static gint dissect_dcerpc_8bytes (tvbuff_t *tvb, gint offset, packet_info *pinfo _U_,
proto_tree *tree, guint8 *drep,
int hfindex, guint64 *pdata)
{
guint64 data;
data = ((drep[0] & DREP_LITTLE_ENDIAN)
? tvb_get_letoh64 (tvb, offset)
: tvb_get_ntoh64 (tvb, offset));
if (tree) {
proto_tree_add_item(tree, hfindex, tvb, offset, 8, ENC_NA);
}
if (pdata)
*pdata = data;
return offset+8;
}
static gint
netlogon_auth_equal (gconstpointer k1, gconstpointer k2)
{
const netlogon_auth_key *key1 = (const netlogon_auth_key *)k1;
const netlogon_auth_key *key2 = (const netlogon_auth_key *)k2;
if(key1->name == NULL || key2->name ==NULL)
return ((key1->srcport == key2->srcport) && (key1->dstport == key2->dstport) && ADDRESSES_EQUAL(&key1->src,&key2->src) &&
ADDRESSES_EQUAL(&key1->dst,&key2->dst));
else
return ((strcmp(key1->name,key2->name)==0) && ADDRESSES_EQUAL(&key1->src,&key2->src) &&
ADDRESSES_EQUAL(&key1->dst,&key2->dst));
}
static guint
netlogon_auth_hash (gconstpointer k)
{
const netlogon_auth_key *key1 = (const netlogon_auth_key *)k;
guint hash_val1;
if(key1->name == NULL) {
hash_val1 = key1->dstport;
hash_val1 += key1->srcport;
}
else {
unsigned int i = 0;
hash_val1 = 0;
for(i=0; key1->name[i]; i++) {
hash_val1 += key1->name[i];
}
}
ADD_ADDRESS_TO_HASH(hash_val1, &key1->src);
ADD_ADDRESS_TO_HASH(hash_val1, &key1->dst);
return hash_val1;
}
static int
netlogon_dissect_EXTRA_FLAGS(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *parent_tree, guint8 *drep)
{
guint32 mask;
proto_item *item = NULL;
proto_tree *tree = NULL;
dcerpc_info *di;
di=pinfo->private_data;
if(di->conformant_run){
return offset;
}
offset=dissect_ndr_uint32(tvb, offset, pinfo, NULL, drep,
hf_netlogon_extraflags, &mask);
if(parent_tree){
item = proto_tree_add_uint(parent_tree, hf_netlogon_extraflags,
tvb, offset-4, 4, mask);
tree = proto_item_add_subtree(item, ett_trust_flags);
}
proto_tree_add_boolean(tree, hf_netlogon_extra_flags_root_forest,
tvb, offset-4, 4, mask);
proto_tree_add_boolean(tree, hf_netlogon_trust_flags_dc_firsthop,
tvb, offset-4, 4, mask);
proto_tree_add_boolean(tree, hf_netlogon_trust_flags_rodc_to_dc,
tvb, offset-4, 4, mask);
proto_tree_add_boolean(tree, hf_netlogon_trust_flags_rodc_ntlm,
tvb, offset-4, 4, mask);
return offset;
}
int
dissect_ndr_lm_nt_hash_cb(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
guint8 *drep, int hf_index,
dcerpc_callback_fnct_t *callback,
void *callback_args)
{
dcerpc_info *di = pinfo->private_data;
guint16 len, size;
ALIGN_TO_4_BYTES;
if (di->conformant_run)
return offset;
#if 0
struct {
short len;
short size;
[size_is(size/2), length_is(len/2), ptr] unsigned short *string;
} HASH;
#endif
offset = dissect_ndr_uint16(tvb, offset, pinfo, tree, drep,
hf_nt_cs_len, &len);
offset = dissect_ndr_uint16(tvb, offset, pinfo, tree, drep,
hf_nt_cs_size, &size);
offset = dissect_ndr_pointer_cb(tvb, offset, pinfo, tree, drep,
dissect_ndr_char_cvstring, NDR_POINTER_UNIQUE,
"Bytes Array", hf_index, callback, callback_args);
return offset;
}
static int
dissect_ndr_lm_nt_hash_helper(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
guint8 *drep, int hf_index, int levels _U_,
gboolean add_subtree)
{
proto_item *item;
proto_tree *subtree = tree;
if (add_subtree) {
item = proto_tree_add_text(
tree, tvb, offset, 0, "%s",
proto_registrar_get_name(hf_index));
subtree = proto_item_add_subtree(item,ett_LM_OWF_PASSWORD);
}
return dissect_ndr_lm_nt_hash_cb(
tvb, offset, pinfo, subtree, drep, hf_index,
NULL, NULL);
}
static int
netlogon_dissect_USER_ACCOUNT_CONTROL(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *parent_tree, guint8 *drep)
{
guint32 mask;
proto_item *item = NULL;
proto_tree *tree = NULL;
dcerpc_info *di;
di=pinfo->private_data;
if(di->conformant_run){
return offset;
}
offset=dissect_ndr_uint32(tvb, offset, pinfo, NULL, drep,
hf_netlogon_user_account_control, &mask);
if(parent_tree){
item = proto_tree_add_uint(parent_tree, hf_netlogon_user_account_control,
tvb, offset-4, 4, mask);
tree = proto_item_add_subtree(item, ett_user_account_control);
}
proto_tree_add_boolean(tree, hf_netlogon_user_account_control_dont_require_preauth,
tvb, offset-4, 4, mask);
proto_tree_add_boolean(tree, hf_netlogon_user_account_control_use_des_key_only,
tvb, offset-4, 4, mask);
proto_tree_add_boolean(tree, hf_netlogon_user_account_control_not_delegated,
tvb, offset-4, 4, mask);
proto_tree_add_boolean(tree, hf_netlogon_user_account_control_trusted_for_delegation,
tvb, offset-4, 4, mask);
proto_tree_add_boolean(tree, hf_netlogon_user_account_control_smartcard_required,
tvb, offset-4, 4, mask);
proto_tree_add_boolean(tree, hf_netlogon_user_account_control_encrypted_text_password_allowed,
tvb, offset-4, 4, mask);
proto_tree_add_boolean(tree, hf_netlogon_user_account_control_account_auto_locked,
tvb, offset-4, 4, mask);
proto_tree_add_boolean(tree, hf_netlogon_user_account_control_dont_expire_password,
tvb, offset-4, 4, mask);
proto_tree_add_boolean(tree, hf_netlogon_user_account_control_server_trust_account,
tvb, offset-4, 4, mask);
proto_tree_add_boolean(tree, hf_netlogon_user_account_control_workstation_trust_account,
tvb, offset-4, 4, mask);
proto_tree_add_boolean(tree, hf_netlogon_user_account_control_interdomain_trust_account,
tvb, offset-4, 4, mask);
proto_tree_add_boolean(tree, hf_netlogon_user_account_control_mns_logon_account,
tvb, offset-4, 4, mask);
proto_tree_add_boolean(tree, hf_netlogon_user_account_control_normal_account,
tvb, offset-4, 4, mask);
proto_tree_add_boolean(tree, hf_netlogon_user_account_control_temp_duplicate_account,
tvb, offset-4, 4, mask);
proto_tree_add_boolean(tree, hf_netlogon_user_account_control_password_not_required,
tvb, offset-4, 4, mask);
proto_tree_add_boolean(tree, hf_netlogon_user_account_control_home_directory_required,
tvb, offset-4, 4, mask);
proto_tree_add_boolean(tree, hf_netlogon_user_account_control_account_disabled,
tvb, offset-4, 4, mask);
return offset;
}
static int
netlogon_dissect_LOGONSRV_HANDLE(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
guint8 *drep)
{
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, drep,
NDR_POINTER_UNIQUE, "Server Handle",
hf_netlogon_logonsrv_handle, 0);
return offset;
}
static int
netlogon_dissect_VALIDATION_UAS_INFO(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
guint8 *drep)
{
dcerpc_info *di;
di=pinfo->private_data;
if(di->conformant_run){
return offset;
}
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, drep,
NDR_POINTER_UNIQUE, "Effective Account",
hf_netlogon_acct_name, 0);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_priv, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_auth_flags, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_logon_count, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_bad_pw_count, NULL);
offset = dissect_ndr_time_t(tvb, offset, pinfo, tree, drep, hf_netlogon_logon_time, NULL);
offset = dissect_ndr_time_t(tvb, offset, pinfo, tree, drep, hf_netlogon_last_logoff_time, NULL);
offset = dissect_ndr_time_t(tvb, offset, pinfo, tree, drep, hf_netlogon_logoff_time, NULL);
offset = dissect_ndr_time_t(tvb, offset, pinfo, tree, drep, hf_netlogon_kickoff_time, NULL);
offset = dissect_ndr_time_t(tvb, offset, pinfo, tree, drep, hf_netlogon_pwd_age, NULL);
offset = dissect_ndr_time_t(tvb, offset, pinfo, tree, drep, hf_netlogon_pwd_can_change_time, NULL);
offset = dissect_ndr_time_t(tvb, offset, pinfo, tree, drep, hf_netlogon_pwd_must_change_time, NULL);
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, drep,
NDR_POINTER_UNIQUE, "Computer", hf_netlogon_computer_name, 0);
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, drep,
NDR_POINTER_UNIQUE, "Domain", hf_netlogon_domain_name, 0);
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, drep,
NDR_POINTER_UNIQUE, "Script", hf_netlogon_logon_script, 0);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_reserved, NULL);
return offset;
}
static int
netlogon_dissect_netrlogonuaslogon_rqst(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = netlogon_dissect_LOGONSRV_HANDLE(tvb, offset,
pinfo, tree, drep);
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, drep,
NDR_POINTER_REF, "Account", hf_netlogon_acct_name, CB_STR_COL_INFO);
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, drep,
NDR_POINTER_REF, "Workstation", hf_netlogon_workstation, 0);
return offset;
}
static int
netlogon_dissect_netrlogonuaslogon_reply(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_VALIDATION_UAS_INFO, NDR_POINTER_UNIQUE,
"VALIDATION_UAS_INFO", -1);
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep,
hf_netlogon_dos_rc, NULL);
return offset;
}
static int
netlogon_dissect_LOGOFF_UAS_INFO(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
guint8 *drep)
{
dcerpc_info *di;
di=pinfo->private_data;
if(di->conformant_run){
return offset;
}
proto_tree_add_text(tree, tvb, offset, 4, "Duration: unknown time format");
offset+= 4;
offset = dissect_ndr_uint16(tvb, offset, pinfo, tree, drep,
hf_netlogon_logon_count16, NULL);
return offset;
}
static int
netlogon_dissect_netrlogonuaslogoff_rqst(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = netlogon_dissect_LOGONSRV_HANDLE(tvb, offset,
pinfo, tree, drep);
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, drep,
NDR_POINTER_REF, "Account", hf_netlogon_acct_name, CB_STR_COL_INFO);
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, drep,
NDR_POINTER_REF, "Workstation", hf_netlogon_workstation, 0);
return offset;
}
static int
netlogon_dissect_netrlogonuaslogoff_reply(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_LOGOFF_UAS_INFO, NDR_POINTER_REF,
"LOGOFF_UAS_INFO", -1);
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep,
hf_netlogon_dos_rc, NULL);
return offset;
}
static int
netlogon_dissect_BYTE_byte(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
guint8 *drep)
{
offset = dissect_ndr_uint8(tvb, offset, pinfo, tree, drep,
hf_netlogon_unknown_char, NULL);
return offset;
}
static int
netlogon_dissect_BYTE_array(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
guint8 *drep)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, drep,
netlogon_dissect_BYTE_byte);
return offset;
}
static int
netlogon_dissect_LOGON_IDENTITY_INFO(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *parent_tree,
guint8 *drep)
{
proto_item *item=NULL;
proto_tree *tree=NULL;
int old_offset=offset;
if(parent_tree){
item = proto_tree_add_text(parent_tree, tvb, offset, 0,
"IDENTITY_INFO:");
tree = proto_item_add_subtree(item, ett_IDENTITY_INFO);
}
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_logon_dom, 0);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_param_ctrl, NULL);
offset = dissect_ndr_duint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_logon_id, NULL);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_acct_name, 1);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_workstation, 0);
#ifdef REMOVED
offset = netlogon_dissect_8_unknown_bytes(tvb, offset, pinfo, tree, drep);
#endif
proto_item_set_len(item, offset-old_offset);
return offset;
}
static int
netlogon_dissect_LM_OWF_PASSWORD(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *parent_tree,
guint8 *drep _U_)
{
proto_item *item=NULL;
proto_tree *tree=NULL;
dcerpc_info *di;
di=pinfo->private_data;
if(di->conformant_run){
return offset;
}
if(parent_tree){
item = proto_tree_add_text(parent_tree, tvb, offset, 16,
"LM_OWF_PASSWORD:");
tree = proto_item_add_subtree(item, ett_LM_OWF_PASSWORD);
}
proto_tree_add_item(tree, hf_netlogon_lm_owf_password, tvb, offset, 16,
ENC_NA);
offset += 16;
return offset;
}
static int
netlogon_dissect_NT_OWF_PASSWORD(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *parent_tree,
guint8 *drep _U_)
{
proto_item *item=NULL;
proto_tree *tree=NULL;
dcerpc_info *di;
di=pinfo->private_data;
if(di->conformant_run){
return offset;
}
if(parent_tree){
item = proto_tree_add_text(parent_tree, tvb, offset, 16,
"NT_OWF_PASSWORD:");
tree = proto_item_add_subtree(item, ett_NT_OWF_PASSWORD);
}
proto_tree_add_item(tree, hf_netlogon_nt_owf_password, tvb, offset, 16,
ENC_NA);
offset += 16;
return offset;
}
static int
netlogon_dissect_INTERACTIVE_INFO(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
guint8 *drep)
{
offset = netlogon_dissect_LOGON_IDENTITY_INFO(tvb, offset,
pinfo, tree, drep);
offset = netlogon_dissect_LM_OWF_PASSWORD(tvb, offset,
pinfo, tree, drep);
offset = netlogon_dissect_NT_OWF_PASSWORD(tvb, offset,
pinfo, tree, drep);
return offset;
}
static int
netlogon_dissect_CHALLENGE(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
guint8 *drep _U_)
{
dcerpc_info *di;
di=pinfo->private_data;
if(di->conformant_run){
return offset;
}
proto_tree_add_item(tree, hf_netlogon_challenge, tvb, offset, 8,
ENC_NA);
offset += 8;
return offset;
}
static int
netlogon_dissect_NETWORK_INFO(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
guint8 *drep)
{
offset = netlogon_dissect_LOGON_IDENTITY_INFO(tvb, offset,
pinfo, tree, drep);
offset = netlogon_dissect_CHALLENGE(tvb, offset,
pinfo, tree, drep);
#if 0
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, drep,
NDR_POINTER_UNIQUE, "NT ",
hf_netlogon_nt_owf_password, 0);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_data_length, NULL);
#endif
offset = dissect_ndr_lm_nt_hash_helper(tvb,offset,pinfo, tree, drep, hf_netlogon_lm_chal_resp, 0,TRUE);
offset = dissect_ndr_lm_nt_hash_helper(tvb,offset,pinfo, tree, drep, hf_netlogon_lm_chal_resp, 0,TRUE);
#if 0
offset = netlogon_dissect_LM_OWF_PASSWORD(tvb, offset,
pinfo, tree, drep);
offset = netlogon_dissect_NT_OWF_PASSWORD(tvb, offset,
pinfo, tree, drep);
#endif
return offset;
#if 0
offset = dissect_ndr_counted_byte_array_cb(
tvb, offset, pinfo, tree, drep, hf_netlogon_nt_chal_resp,
dissect_nt_chal_resp_cb,GINT_TO_POINTER(2));
offset = dissect_ndr_counted_byte_array(tvb, offset, pinfo, tree, drep,
hf_netlogon_lm_chal_resp, 0);
return offset;
#endif
}
static int
netlogon_dissect_SERVICE_INFO(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
guint8 *drep)
{
offset = netlogon_dissect_LOGON_IDENTITY_INFO(tvb, offset,
pinfo, tree, drep);
offset = netlogon_dissect_LM_OWF_PASSWORD(tvb, offset,
pinfo, tree, drep);
offset = netlogon_dissect_NT_OWF_PASSWORD(tvb, offset,
pinfo, tree, drep);
return offset;
}
static int
netlogon_dissect_GENERIC_INFO(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
guint8 *drep)
{
offset = netlogon_dissect_LOGON_IDENTITY_INFO(tvb, offset,
pinfo, tree, drep);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_package_name, 0|CB_STR_SAVE);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_data_length, NULL);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_BYTE_array, NDR_POINTER_REF,
"Logon Data", -1);
return offset;
}
static int
netlogon_dissect_LEVEL(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
guint8 *drep)
{
guint16 level = 0;
offset = dissect_ndr_uint16(tvb, offset, pinfo, tree, drep,
hf_netlogon_level16, &level);
ALIGN_TO_4_BYTES;
switch(level){
case 1:
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_INTERACTIVE_INFO, NDR_POINTER_UNIQUE,
"INTERACTIVE_INFO:", -1);
break;
case 2:
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_NETWORK_INFO, NDR_POINTER_UNIQUE,
"NETWORK_INFO:", -1);
break;
case 3:
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_SERVICE_INFO, NDR_POINTER_UNIQUE,
"SERVICE_INFO:", -1);
case 4:
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_GENERIC_INFO, NDR_POINTER_UNIQUE,
"GENERIC_INFO:", -1);
break;
case 5:
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_INTERACTIVE_INFO, NDR_POINTER_UNIQUE,
"INTERACTIVE_TRANSITIVE_INFO:", -1);
break;
case 6:
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_NETWORK_INFO, NDR_POINTER_UNIQUE,
"NETWORK_TRANSITIVE_INFO", -1);
break;
case 7:
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_SERVICE_INFO, NDR_POINTER_UNIQUE,
"SERVICE_TRANSITIVE_INFO", -1);
break;
}
return offset;
}
static int
netlogon_dissect_CREDENTIAL(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
guint8 *drep _U_)
{
dcerpc_info *di;
di=pinfo->private_data;
if(di->conformant_run){
return offset;
}
proto_tree_add_item(tree, hf_netlogon_credential, tvb, offset, 8,
ENC_NA);
offset += 8;
return offset;
}
static int
netlogon_dissect_AUTHENTICATOR(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
guint8 *drep)
{
dcerpc_info *di;
nstime_t ts;
di=pinfo->private_data;
if(di->conformant_run){
return offset;
}
offset = netlogon_dissect_CREDENTIAL(tvb, offset,
pinfo, tree, drep);
ALIGN_TO_4_BYTES;
ts.secs = tvb_get_letohl(tvb, offset);
ts.nsecs = 0;
proto_tree_add_time(tree, hf_netlogon_timestamp, tvb, offset, 4, &ts);
offset+= 4;
return offset;
}
static int
netlogon_dissect_GROUP_MEMBERSHIP_ATTRIBUTES(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *parent_tree, guint8 *drep)
{
guint32 mask;
proto_item *item = NULL;
proto_tree *tree = NULL;
dcerpc_info *di;
di=pinfo->private_data;
if(di->conformant_run){
return offset;
}
offset=dissect_ndr_uint32(tvb, offset, pinfo, NULL, drep,
hf_netlogon_attrs, &mask);
if(parent_tree){
item = proto_tree_add_uint(parent_tree, hf_netlogon_attrs,
tvb, offset-4, 4, mask);
tree = proto_item_add_subtree(item, ett_group_attrs);
}
proto_tree_add_boolean(tree, hf_netlogon_group_attrs_enabled,
tvb, offset-4, 4, mask);
proto_tree_add_boolean(tree, hf_netlogon_group_attrs_enabled_by_default,
tvb, offset-4, 4, mask);
proto_tree_add_boolean(tree, hf_netlogon_group_attrs_mandatory,
tvb, offset-4, 4, mask);
return offset;
}
static int
netlogon_dissect_GROUP_MEMBERSHIP(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *parent_tree,
guint8 *drep)
{
proto_item *item=NULL;
proto_tree *tree=NULL;
if(parent_tree){
item = proto_tree_add_text(parent_tree, tvb, offset, 0,
"GROUP_MEMBERSHIP:");
tree = proto_item_add_subtree(item, ett_GROUP_MEMBERSHIP);
}
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_group_rid, NULL);
offset = netlogon_dissect_GROUP_MEMBERSHIP_ATTRIBUTES(tvb, offset,
pinfo, tree, drep);
return offset;
}
static int
netlogon_dissect_GROUP_MEMBERSHIP_ARRAY(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
guint8 *drep)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, drep,
netlogon_dissect_GROUP_MEMBERSHIP);
return offset;
}
static int
netlogon_dissect_USER_SESSION_KEY(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
guint8 *drep _U_)
{
dcerpc_info *di;
di=pinfo->private_data;
if(di->conformant_run){
return offset;
}
proto_tree_add_item(tree, hf_netlogon_user_session_key, tvb, offset, 16,
ENC_NA);
offset += 16;
return offset;
}
static int
netlogon_dissect_USER_FLAGS(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *parent_tree, guint8 *drep)
{
guint32 mask;
proto_item *item = NULL;
proto_tree *tree = NULL;
dcerpc_info *di;
di=pinfo->private_data;
if(di->conformant_run){
return offset;
}
offset=dissect_ndr_uint32(tvb, offset, pinfo, NULL, drep,
hf_netlogon_user_flags, &mask);
if(parent_tree){
item = proto_tree_add_uint(parent_tree, hf_netlogon_user_flags,
tvb, offset-4, 4, mask);
tree = proto_item_add_subtree(item, ett_user_flags);
}
proto_tree_add_boolean(tree, hf_netlogon_user_flags_resource_groups,
tvb, offset-4, 4, mask);
proto_tree_add_boolean(tree, hf_netlogon_user_flags_extra_sids,
tvb, offset-4, 4, mask);
return offset;
}
static int
netlogon_dissect_VALIDATION_SAM_INFO(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
guint8 *drep)
{
offset = dissect_ndr_nt_NTTIME(tvb, offset, pinfo, tree, drep,
hf_netlogon_logon_time);
offset = dissect_ndr_nt_NTTIME(tvb, offset, pinfo, tree, drep,
hf_netlogon_logoff_time);
offset = dissect_ndr_nt_NTTIME(tvb, offset, pinfo, tree, drep,
hf_netlogon_kickoff_time);
offset = dissect_ndr_nt_NTTIME(tvb, offset, pinfo, tree, drep,
hf_netlogon_pwd_last_set_time);
offset = dissect_ndr_nt_NTTIME(tvb, offset, pinfo, tree, drep,
hf_netlogon_pwd_can_change_time);
offset = dissect_ndr_nt_NTTIME(tvb, offset, pinfo, tree, drep,
hf_netlogon_pwd_must_change_time);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_acct_name, 0);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_full_name, 0);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_logon_script, 0);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_profile_path, 0);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_home_dir, 0);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_dir_drive, 0);
offset = dissect_ndr_uint16(tvb, offset, pinfo, tree, drep,
hf_netlogon_logon_count16, NULL);
offset = dissect_ndr_uint16(tvb, offset, pinfo, tree, drep,
hf_netlogon_bad_pw_count16, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_user_rid, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_group_rid, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_num_rids, NULL);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_GROUP_MEMBERSHIP_ARRAY, NDR_POINTER_UNIQUE,
"GROUP_MEMBERSHIP_ARRAY", -1);
offset = netlogon_dissect_USER_FLAGS(tvb, offset,
pinfo, tree, drep);
offset = netlogon_dissect_USER_SESSION_KEY(tvb, offset,
pinfo, tree, drep);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_logon_srv, 0);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_logon_dom, 0);
offset = dissect_ndr_nt_PSID(tvb, offset, pinfo, tree, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_dummy1_long, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_dummy2_long, NULL);
offset = netlogon_dissect_USER_ACCOUNT_CONTROL(tvb, offset,
pinfo, tree, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_dummy4_long, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_dummy5_long, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_dummy6_long, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_dummy7_long, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_dummy8_long, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_dummy9_long, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_dummy10_long, NULL);
return offset;
}
static int
netlogon_dissect_VALIDATION_SAM_INFO2(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
guint8 *drep)
{
offset = netlogon_dissect_VALIDATION_SAM_INFO(tvb,offset,pinfo,tree,drep);
#if 0
int i;
offset = dissect_ndr_nt_NTTIME(tvb, offset, pinfo, tree, drep,
hf_netlogon_logon_time);
offset = dissect_ndr_nt_NTTIME(tvb, offset, pinfo, tree, drep,
hf_netlogon_logoff_time);
offset = dissect_ndr_nt_NTTIME(tvb, offset, pinfo, tree, drep,
hf_netlogon_kickoff_time);
offset = dissect_ndr_nt_NTTIME(tvb, offset, pinfo, tree, drep,
hf_netlogon_pwd_last_set_time);
offset = dissect_ndr_nt_NTTIME(tvb, offset, pinfo, tree, drep,
hf_netlogon_pwd_can_change_time);
offset = dissect_ndr_nt_NTTIME(tvb, offset, pinfo, tree, drep,
hf_netlogon_pwd_must_change_time);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_acct_name, 0);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_full_name, 0);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_logon_script, 0);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_profile_path, 0);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_home_dir, 0);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_dir_drive, 0);
offset = dissect_ndr_uint16(tvb, offset, pinfo, tree, drep,
hf_netlogon_logon_count16, NULL);
offset = dissect_ndr_uint16(tvb, offset, pinfo, tree, drep,
hf_netlogon_bad_pw_count16, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_user_rid, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_group_rid, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_num_rids, NULL);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_GROUP_MEMBERSHIP_ARRAY, NDR_POINTER_UNIQUE,
"GROUP_MEMBERSHIP_ARRAY", -1);
offset = netlogon_dissect_USER_FLAGS(tvb, offset,
pinfo, tree, drep);
offset = netlogon_dissect_USER_SESSION_KEY(tvb, offset,
pinfo, tree, drep);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_logon_srv, 0);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_logon_dom, 0);
offset = dissect_ndr_nt_PSID(tvb, offset, pinfo, tree, drep);
for(i=0;i<2;i++){
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_unknown_long, NULL);
}
offset = netlogon_dissect_USER_ACCOUNT_CONTROL(tvb, offset,
pinfo, tree, drep);
for(i=0;i<7;i++){
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_unknown_long, NULL);
}
#endif
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_num_sid, NULL);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
dissect_ndr_nt_SID_AND_ATTRIBUTES_ARRAY, NDR_POINTER_UNIQUE,
"SID_AND_ATTRIBUTES_ARRAY:", -1);
return offset;
}
static int
netlogon_dissect_VALIDATION_SAM_INFO4(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
guint8 *drep)
{
offset = netlogon_dissect_VALIDATION_SAM_INFO2(tvb,offset,pinfo,tree,drep);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_logon_dnslogondomainname, 0);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_logon_upn, 0);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_dummy_string, 0);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_dummy_string2, 0);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_dummy_string3, 0);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_dummy_string4, 0);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_dummy_string5, 0);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_dummy_string6, 0);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_dummy_string7, 0);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_dummy_string8, 0);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_dummy_string9, 0);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_dummy_string10, 0);
return offset;
}
int
netlogon_dissect_PAC_LOGON_INFO(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
guint8 *drep)
{
guint32 rgc;
offset = netlogon_dissect_VALIDATION_SAM_INFO(tvb,offset,pinfo,tree,drep);
#if 0
int i;
offset = dissect_ndr_nt_NTTIME(tvb, offset, pinfo, tree, drep,
hf_netlogon_logon_time);
offset = dissect_ndr_nt_NTTIME(tvb, offset, pinfo, tree, drep,
hf_netlogon_logoff_time);
offset = dissect_ndr_nt_NTTIME(tvb, offset, pinfo, tree, drep,
hf_netlogon_kickoff_time);
offset = dissect_ndr_nt_NTTIME(tvb, offset, pinfo, tree, drep,
hf_netlogon_pwd_last_set_time);
offset = dissect_ndr_nt_NTTIME(tvb, offset, pinfo, tree, drep,
hf_netlogon_pwd_can_change_time);
offset = dissect_ndr_nt_NTTIME(tvb, offset, pinfo, tree, drep,
hf_netlogon_pwd_must_change_time);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_acct_name, 0);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_full_name, 0);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_logon_script, 0);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_profile_path, 0);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_home_dir, 0);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_dir_drive, 0);
offset = dissect_ndr_uint16(tvb, offset, pinfo, tree, drep,
hf_netlogon_logon_count16, NULL);
offset = dissect_ndr_uint16(tvb, offset, pinfo, tree, drep,
hf_netlogon_bad_pw_count16, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_user_rid, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_group_rid, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_num_rids, NULL);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_GROUP_MEMBERSHIP_ARRAY, NDR_POINTER_UNIQUE,
"GROUP_MEMBERSHIP_ARRAY", -1);
offset = netlogon_dissect_USER_FLAGS(tvb, offset,
pinfo, tree, drep);
offset = netlogon_dissect_USER_SESSION_KEY(tvb, offset,
pinfo, tree, drep);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_logon_srv, 0);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_logon_dom, 0);
offset = dissect_ndr_nt_PSID(tvb, offset, pinfo, tree, drep);
for(i=0;i<2;i++){
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_unknown_long, NULL);
}
offset = netlogon_dissect_USER_ACCOUNT_CONTROL(tvb, offset,
pinfo, tree, drep);
for(i=0;i<7;i++){
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_unknown_long, NULL);
}
#endif
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_num_sid, NULL);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
dissect_ndr_nt_SID_AND_ATTRIBUTES_ARRAY, NDR_POINTER_UNIQUE,
"SID_AND_ATTRIBUTES_ARRAY:", -1);
offset = dissect_ndr_nt_PSID(tvb, offset, pinfo, tree, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_resourcegroupcount, &rgc);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_GROUP_MEMBERSHIP_ARRAY, NDR_POINTER_UNIQUE,
"ResourceGroupIDs", -1);
return offset;
}
static int
netlogon_dissect_S4U_Transited_Service_name(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
guint8 *drep)
{
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_transited_service, 1);
return offset;
}
static int
netlogon_dissect_S4U_Transited_Services_array(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
guint8 *drep)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, drep,
netlogon_dissect_S4U_Transited_Service_name);
return offset;
}
int
netlogon_dissect_PAC_S4U_DELEGATION_INFO(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
guint8 *drep)
{
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_s4u2proxytarget, 0);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_transitedlistsize, NULL);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_S4U_Transited_Services_array, NDR_POINTER_UNIQUE,
"S4UTransitedServices", -1);
return offset;
}
static int
netlogon_dissect_VALIDATION_GENERIC_INFO2 (tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
guint8 *drep)
{
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_data_length, NULL);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_BYTE_array, NDR_POINTER_REF,
"Validation Data", -1);
return offset;
}
static int
netlogon_dissect_VALIDATION(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
guint8 *drep)
{
guint16 level = 0;
offset = dissect_ndr_uint16(tvb, offset, pinfo, tree, drep,
hf_netlogon_validation_level, &level);
ALIGN_TO_4_BYTES;
switch(level){
case 1:
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_VALIDATION_UAS_INFO, NDR_POINTER_UNIQUE,
"VALIDATION_UAS_INFO:", -1);
break;
case 2:
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_VALIDATION_SAM_INFO, NDR_POINTER_UNIQUE,
"VALIDATION_SAM_INFO:", -1);
break;
case 3:
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_VALIDATION_SAM_INFO2, NDR_POINTER_UNIQUE,
"VALIDATION_SAM_INFO2:", -1);
break;
case 4:
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_VALIDATION_GENERIC_INFO2, NDR_POINTER_UNIQUE,
"VALIDATION_INFO:", -1);
break;
case 5:
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_VALIDATION_GENERIC_INFO2, NDR_POINTER_UNIQUE,
"VALIDATION_INFO2:", -1);
break;
case 6:
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_VALIDATION_SAM_INFO4, NDR_POINTER_UNIQUE,
"VALIDATION_SAM_INFO4:", -1);
break;
}
return offset;
}
static int
netlogon_dissect_netrlogonsamlogonflags_rqst(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = netlogon_dissect_LOGONSRV_HANDLE(tvb, offset,
pinfo, tree, drep);
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, drep,
NDR_POINTER_UNIQUE, "Computer Name",
hf_netlogon_computer_name, 0);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_AUTHENTICATOR, NDR_POINTER_UNIQUE,
"AUTHENTICATOR: credential", -1);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_AUTHENTICATOR, NDR_POINTER_UNIQUE,
"AUTHENTICATOR: return_authenticator", -1);
offset = dissect_ndr_uint16(tvb, offset, pinfo, tree, drep,
hf_netlogon_level16, NULL);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_LEVEL, NDR_POINTER_REF,
"LEVEL: LogonLevel", -1);
offset = dissect_ndr_uint16(tvb, offset, pinfo, tree, drep,
hf_netlogon_validation_level, NULL);
offset = netlogon_dissect_EXTRA_FLAGS(tvb, offset, pinfo, tree, drep);
return offset;
}
static int
netlogon_dissect_netrlogonsamlogonflags_reply(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_AUTHENTICATOR, NDR_POINTER_UNIQUE,
"AUTHENTICATOR: return_authenticator", -1);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_VALIDATION, NDR_POINTER_REF,
"VALIDATION:", -1);
offset = dissect_ndr_uint8(tvb, offset, pinfo, tree, drep,
hf_netlogon_authoritative, NULL);
offset = netlogon_dissect_EXTRA_FLAGS(tvb, offset, pinfo, tree, drep);
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep,
hf_netlogon_rc, NULL);
return offset;
}
static int
netlogon_dissect_netrlogonsamlogon_rqst(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = netlogon_dissect_LOGONSRV_HANDLE(tvb, offset,
pinfo, tree, drep);
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, drep,
NDR_POINTER_UNIQUE, "Computer Name",
hf_netlogon_computer_name, 0);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_AUTHENTICATOR, NDR_POINTER_UNIQUE,
"AUTHENTICATOR: credential", -1);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_AUTHENTICATOR, NDR_POINTER_UNIQUE,
"AUTHENTICATOR: return_authenticator", -1);
offset = dissect_ndr_uint16(tvb, offset, pinfo, tree, drep,
hf_netlogon_level16, NULL);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_LEVEL, NDR_POINTER_REF,
"LEVEL: LogonLevel", -1);
offset = dissect_ndr_uint16(tvb, offset, pinfo, tree, drep,
hf_netlogon_validation_level, NULL);
return offset;
}
static int
netlogon_dissect_netrlogonsamlogon_reply(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_AUTHENTICATOR, NDR_POINTER_UNIQUE,
"AUTHENTICATOR: return_authenticator", -1);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_VALIDATION, NDR_POINTER_REF,
"VALIDATION:", -1);
offset = dissect_ndr_uint8(tvb, offset, pinfo, tree, drep,
hf_netlogon_authoritative, NULL);
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep,
hf_netlogon_rc, NULL);
return offset;
}
static int
netlogon_dissect_netrlogonsamlogoff_rqst(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = netlogon_dissect_LOGONSRV_HANDLE(tvb, offset,
pinfo, tree, drep);
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, drep,
NDR_POINTER_UNIQUE, "Computer Name",
hf_netlogon_computer_name, 0);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_AUTHENTICATOR, NDR_POINTER_UNIQUE,
"AUTHENTICATOR: credential", -1);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_AUTHENTICATOR, NDR_POINTER_UNIQUE,
"AUTHENTICATOR: return_authenticator", -1);
offset = dissect_ndr_uint16(tvb, offset, pinfo, tree, drep,
hf_netlogon_level16, NULL);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_LEVEL, NDR_POINTER_REF,
"LEVEL: logoninformation", -1);
return offset;
}
static int
netlogon_dissect_netrlogonsamlogoff_reply(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_AUTHENTICATOR, NDR_POINTER_UNIQUE,
"AUTHENTICATOR: return_authenticator", -1);
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep,
hf_netlogon_rc, NULL);
return offset;
}
static void generate_hash_key(packet_info *pinfo,unsigned char is_server,netlogon_auth_key *key,char* name)
{
if(is_server) {
key->dstport = pinfo->srcport;
key->srcport = pinfo->destport;
COPY_ADDRESS(&key->dst,&pinfo->src);
COPY_ADDRESS(&key->src,&pinfo->dst);
key->name = name;
}
else {
COPY_ADDRESS(&key->dst,&pinfo->dst);
COPY_ADDRESS(&key->src,&pinfo->src);
key->dstport = pinfo->destport;
key->srcport = pinfo->srcport;
key->name = name;
}
}
static int
netlogon_dissect_netrserverreqchallenge_rqst(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
netlogon_auth_vars *vars;
netlogon_auth_vars *existing_vars;
netlogon_auth_key *key = se_alloc(sizeof(netlogon_auth_key));
guint8 tab[8] = { 0,0,0,0,0,0,0,0};
dcerpc_info *di = (dcerpc_info *)pinfo->private_data;
dcerpc_call_value *dcv = (dcerpc_call_value *)di->call_data;
vars = se_alloc(sizeof(netlogon_auth_vars));
offset = netlogon_dissect_LOGONSRV_HANDLE(tvb, offset, pinfo, tree, drep);
offset = dissect_ndr_pointer_cb(
tvb, offset, pinfo, tree, drep,
dissect_ndr_wchar_cvstring, NDR_POINTER_REF,
"Computer Name", hf_netlogon_computer_name,
cb_wstr_postprocess,
GINT_TO_POINTER(CB_STR_COL_INFO |CB_STR_SAVE | 1));
debugprintf("1)Len %d offset %d txt %s\n",(int) strlen(dcv->private_data),offset,(char*)dcv->private_data);
vars->client_name = se_strdup(dcv->private_data);
debugprintf("2)Len %d offset %d txt %s\n",(int) strlen(dcv->private_data),offset,vars->client_name);
offset = dissect_dcerpc_8bytes(tvb, offset, pinfo, tree, drep,
hf_client_challenge,&vars->client_challenge);
memcpy(tab,&vars->client_challenge,8);
vars->start = pinfo->fd->num;
vars->next_start = -1;
vars->next = NULL;
generate_hash_key(pinfo,0,key,NULL);
existing_vars = NULL;
existing_vars = g_hash_table_lookup(netlogon_auths, key);
if (!existing_vars) {
debugprintf("Adding initial vars with this start packet = %d\n",vars->start);
g_hash_table_insert(netlogon_auths, key, vars);
}
else {
while(existing_vars->next != NULL && existing_vars->start < vars->start) {
debugprintf("Looping to find existing vars ...\n");
existing_vars = existing_vars->next;
}
if(existing_vars->next != NULL || existing_vars->start == vars->start) {
debugprintf("It seems that I already record this vars start packet = %d\n",vars->start);
}
else {
debugprintf("Adding a new entry with this start packet = %d\n",vars->start);
existing_vars->next_start = pinfo->fd->num;
existing_vars->next = vars;
}
}
#if 0
generate_hash_key(pinfo,0,key,vars->client_name);
existing_vars = NULL;
existing_vars = g_hash_table_lookup(schannel_auths, key);
if (!existing_vars)
{
g_hash_table_insert(schannel_auths, key, vars);
}
else
{
while(existing_vars->next != NULL && existing_vars->start <= vars->start) {
existing_vars = existing_vars->next;
}
if(existing_vars->next != NULL || existing_vars == vars) {
debugprintf("It seems that I already record this vars (schannel hash)%d\n",vars->start);
}
else {
existing_vars->next_start = pinfo->fd->num;
existing_vars->next = vars;
}
#endif
return offset;
}
static int
netlogon_dissect_netrserverreqchallenge_reply(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
netlogon_auth_vars *vars;
netlogon_auth_key key;
guint64 server_challenge;
generate_hash_key(pinfo,1,&key,NULL);
vars = g_hash_table_lookup(netlogon_auths,(gconstpointer*) &key);
offset = dissect_dcerpc_8bytes(tvb, offset, pinfo, tree, drep,
hf_server_challenge, &server_challenge);
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep,
hf_netlogon_rc, NULL);
if(vars != NULL) {
while(vars !=NULL && vars->next_start != -1 && vars->next_start < (int)pinfo->fd->num )
{
vars = vars->next;
debugprintf("looping challenge reply... %d %d \n", vars->next_start, pinfo->fd->num);
}
if(vars == NULL)
{
debugprintf("Something strange happened while searching for challenge_reply\n");
}
else
{
vars->server_challenge = server_challenge;
}
}
return offset;
}
static int
netlogon_dissect_NETLOGON_SECURE_CHANNEL_TYPE(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
guint8 *drep)
{
offset = dissect_ndr_uint16(tvb, offset, pinfo, tree, drep,
hf_netlogon_secure_channel_type, NULL);
return offset;
}
static int
netlogon_dissect_netrserverauthenticate_rqst(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = netlogon_dissect_LOGONSRV_HANDLE(tvb, offset,
pinfo, tree, drep);
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, drep,
NDR_POINTER_REF, "User Name", hf_netlogon_acct_name, CB_STR_COL_INFO);
offset = netlogon_dissect_NETLOGON_SECURE_CHANNEL_TYPE(tvb, offset,
pinfo, tree, drep);
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, drep,
NDR_POINTER_REF, "Computer Name", hf_netlogon_computer_name, CB_STR_COL_INFO);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_CREDENTIAL, NDR_POINTER_REF,
"CREDENTIAL: client challenge", -1);
return offset;
}
static int
netlogon_dissect_netrserverauthenticate_reply(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_CREDENTIAL, NDR_POINTER_REF,
"CREDENTIAL: server challenge", -1);
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep,
hf_netlogon_rc, NULL);
return offset;
}
static int
netlogon_dissect_ENCRYPTED_LM_OWF_PASSWORD(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
guint8 *drep _U_)
{
dcerpc_info *di;
di=pinfo->private_data;
if(di->conformant_run){
return offset;
}
proto_tree_add_item(tree, hf_netlogon_encrypted_lm_owf_password, tvb, offset, 16,
ENC_NA);
offset += 16;
return offset;
}
static int
netlogon_dissect_netrserverpasswordset_rqst(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = netlogon_dissect_LOGONSRV_HANDLE(tvb, offset,
pinfo, tree, drep);
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, drep,
NDR_POINTER_REF, "User Name", hf_netlogon_acct_name, 0);
offset = netlogon_dissect_NETLOGON_SECURE_CHANNEL_TYPE(tvb, offset,
pinfo, tree, drep);
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, drep,
NDR_POINTER_REF, "Computer Name", hf_netlogon_computer_name, 0);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_AUTHENTICATOR, NDR_POINTER_REF,
"AUTHENTICATOR: credential", -1);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_ENCRYPTED_LM_OWF_PASSWORD, NDR_POINTER_REF,
"ENCRYPTED_LM_OWF_PASSWORD: hashed_pwd", -1);
return offset;
}
static int
netlogon_dissect_netrserverpasswordset_reply(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_AUTHENTICATOR, NDR_POINTER_REF,
"AUTHENTICATOR: return_authenticator", -1);
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep,
hf_netlogon_rc, NULL);
return offset;
}
static int
netlogon_dissect_DELTA_DELETE_USER(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
guint8 *drep)
{
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, drep,
NDR_POINTER_UNIQUE, "Account Name", hf_netlogon_acct_name, 0);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_dummy, 0);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_dummy, 0);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_dummy, 0);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_dummy, 0);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_reserved, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_reserved, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_reserved, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_reserved, NULL);
return offset;
}
static int
netlogon_dissect_SENSITIVE_DATA(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
guint8 *drep)
{
dcerpc_info *di;
guint32 data_len;
di=pinfo->private_data;
if(di->conformant_run){
return offset;
}
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_sensitive_data_len, &data_len);
proto_tree_add_item(tree, hf_netlogon_sensitive_data, tvb, offset,
data_len, ENC_NA);
offset += data_len;
return offset;
}
static int
netlogon_dissect_USER_PRIVATE_INFO(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
guint8 *drep)
{
offset = dissect_ndr_uint8(tvb, offset, pinfo, tree, drep,
hf_netlogon_sensitive_data_flag, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_sensitive_data_len, NULL);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_SENSITIVE_DATA, NDR_POINTER_UNIQUE,
"SENSITIVE_DATA", -1);
return offset;
}
static int
netlogon_dissect_DELTA_USER(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
guint8 *drep)
{
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_acct_name, 3);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_full_name, 0);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_user_rid, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_group_rid, NULL);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_home_dir, 0);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_dir_drive, 0);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_logon_script, 0);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_acct_desc, 0);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_workstations, 0);
offset = dissect_ndr_nt_NTTIME(tvb, offset, pinfo, tree, drep,
hf_netlogon_logon_time);
offset = dissect_ndr_nt_NTTIME(tvb, offset, pinfo, tree, drep,
hf_netlogon_logoff_time);
offset = dissect_ndr_nt_LOGON_HOURS(tvb, offset, pinfo, tree, drep);
offset = dissect_ndr_uint16(tvb, offset, pinfo, tree, drep,
hf_netlogon_bad_pw_count16, NULL);
offset = dissect_ndr_uint16(tvb, offset, pinfo, tree, drep,
hf_netlogon_logon_count16, NULL);
offset = dissect_ndr_nt_NTTIME(tvb, offset, pinfo, tree, drep,
hf_netlogon_pwd_last_set_time);
offset = dissect_ndr_nt_NTTIME(tvb, offset, pinfo, tree, drep,
hf_netlogon_acct_expiry_time);
offset = dissect_ndr_nt_acct_ctrl(tvb, offset, pinfo, tree, drep);
offset = netlogon_dissect_LM_OWF_PASSWORD(tvb, offset,
pinfo, tree, drep);
offset = netlogon_dissect_NT_OWF_PASSWORD(tvb, offset,
pinfo, tree, drep);
offset = dissect_ndr_uint8(tvb, offset, pinfo, tree, drep,
hf_netlogon_nt_pwd_present, NULL);
offset = dissect_ndr_uint8(tvb, offset, pinfo, tree, drep,
hf_netlogon_lm_pwd_present, NULL);
offset = dissect_ndr_uint8(tvb, offset, pinfo, tree, drep,
hf_netlogon_pwd_expired, NULL);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_comment, 0);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_parameters, 0);
offset = dissect_ndr_uint16(tvb, offset, pinfo, tree, drep,
hf_netlogon_country, NULL);
offset = dissect_ndr_uint16(tvb, offset, pinfo, tree, drep,
hf_netlogon_codepage, NULL);
offset = netlogon_dissect_USER_PRIVATE_INFO(tvb, offset, pinfo, tree,
drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_security_information, NULL);
offset = lsarpc_dissect_sec_desc_buf(tvb, offset, pinfo, tree, drep);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_dummy, 0);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_dummy, 0);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_dummy, 0);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_dummy, 0);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_reserved, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_reserved, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_reserved, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_reserved, NULL);
return offset;
}
static int
netlogon_dissect_DELTA_DOMAIN(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
guint8 *drep)
{
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_domain_name, 3);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_oem_info, 0);
offset = dissect_ndr_nt_NTTIME(tvb, offset, pinfo, tree, drep,
hf_netlogon_kickoff_time);
offset = dissect_ndr_uint16(tvb, offset, pinfo, tree, drep,
hf_netlogon_minpasswdlen, NULL);
offset = dissect_ndr_uint16(tvb, offset, pinfo, tree, drep,
hf_netlogon_passwdhistorylen, NULL);
offset = dissect_ndr_nt_NTTIME(tvb, offset, pinfo, tree, drep,
hf_netlogon_pwd_must_change_time);
offset = dissect_ndr_nt_NTTIME(tvb, offset, pinfo, tree, drep,
hf_netlogon_pwd_can_change_time);
offset = dissect_ndr_nt_NTTIME(tvb, offset, pinfo, tree, drep,
hf_netlogon_domain_modify_time);
offset = dissect_ndr_nt_NTTIME(tvb, offset, pinfo, tree, drep,
hf_netlogon_domain_create_time);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_security_information, NULL);
offset = lsarpc_dissect_sec_desc_buf(tvb, offset, pinfo, tree, drep);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_dummy, 0);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_dummy, 0);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_dummy, 0);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_dummy, 0);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_reserved, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_reserved, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_reserved, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_reserved, NULL);
return offset;
}
static int
netlogon_dissect_DELTA_GROUP(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
guint8 *drep)
{
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_group_name, 3);
offset = netlogon_dissect_GROUP_MEMBERSHIP(tvb, offset,
pinfo, tree, drep);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_group_desc, 0);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_security_information, NULL);
offset = lsarpc_dissect_sec_desc_buf(tvb, offset, pinfo, tree, drep);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_dummy, 0);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_dummy, 0);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_dummy, 0);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_dummy, 0);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_reserved, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_reserved, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_reserved, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_reserved, NULL);
return offset;
}
static int
netlogon_dissect_DELTA_RENAME(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
guint8 *drep)
{
dcerpc_info *di;
di=pinfo->private_data;
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
di->hf_index, 0);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
di->hf_index, 0);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_dummy, 0);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_dummy, 0);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_dummy, 0);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_dummy, 0);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_reserved, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_reserved, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_reserved, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_reserved, NULL);
return offset;
}
static int
netlogon_dissect_RID(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
guint8 *drep)
{
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_user_rid, NULL);
return offset;
}
static int
netlogon_dissect_RID_array(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
guint8 *drep)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, drep,
netlogon_dissect_RID);
return offset;
}
static int
netlogon_dissect_ATTRIB(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
guint8 *drep)
{
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_attrs, NULL);
return offset;
}
static int
netlogon_dissect_ATTRIB_array(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
guint8 *drep)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, drep,
netlogon_dissect_ATTRIB);
return offset;
}
static int
netlogon_dissect_DELTA_GROUP_MEMBER(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
guint8 *drep)
{
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_RID_array, NDR_POINTER_UNIQUE,
"RIDs:", -1);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_ATTRIB_array, NDR_POINTER_UNIQUE,
"Attribs:", -1);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_num_rids, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_reserved, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_reserved, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_reserved, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_reserved, NULL);
return offset;
}
static int
netlogon_dissect_DELTA_ALIAS(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
guint8 *drep)
{
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_alias_name, 0);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_alias_rid, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_security_information, NULL);
offset = lsarpc_dissect_sec_desc_buf(tvb, offset, pinfo, tree, drep);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_dummy, 0);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_dummy, 0);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_dummy, 0);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_dummy, 0);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_reserved, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_reserved, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_reserved, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_reserved, NULL);
return offset;
}
static int
netlogon_dissect_DELTA_ALIAS_MEMBER(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
guint8 *drep)
{
offset = dissect_ndr_nt_PSID_ARRAY(tvb, offset, pinfo, tree, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_reserved, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_reserved, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_reserved, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_reserved, NULL);
return offset;
}
static int
netlogon_dissect_EVENT_AUDIT_OPTION(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
guint8 *drep)
{
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_event_audit_option, NULL);
return offset;
}
static int
netlogon_dissect_EVENT_AUDIT_OPTIONS_ARRAY(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
guint8 *drep)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, drep,
netlogon_dissect_EVENT_AUDIT_OPTION);
return offset;
}
static int
netlogon_dissect_QUOTA_LIMITS(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *parent_tree,
guint8 *drep)
{
proto_item *item=NULL;
proto_tree *tree=NULL;
int old_offset=offset;
if(parent_tree){
item = proto_tree_add_text(parent_tree, tvb, offset, 0,
"QUOTA_LIMTS:");
tree = proto_item_add_subtree(item, ett_QUOTA_LIMITS);
}
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_pagedpoollimit, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_nonpagedpoollimit, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_minworkingsetsize, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_maxworkingsetsize, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_pagefilelimit, NULL);
offset = dissect_ndr_nt_NTTIME(tvb, offset, pinfo, tree, drep,
hf_netlogon_timelimit);
proto_item_set_len(item, offset-old_offset);
return offset;
}
static int
netlogon_dissect_DELTA_POLICY(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
guint8 *drep)
{
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_max_log_size, NULL);
offset = dissect_ndr_nt_NTTIME(tvb, offset, pinfo, tree, drep,
hf_netlogon_audit_retention_period);
offset = dissect_ndr_uint8(tvb, offset, pinfo, tree, drep,
hf_netlogon_auditing_mode, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_max_audit_event_count, NULL);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_EVENT_AUDIT_OPTIONS_ARRAY, NDR_POINTER_UNIQUE,
"Event Audit Options:", -1);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_domain_name, 0);
offset = dissect_ndr_nt_PSID(tvb, offset, pinfo, tree, drep);
offset = netlogon_dissect_QUOTA_LIMITS(tvb, offset,
pinfo, tree, drep);
offset = dissect_ndr_nt_NTTIME(tvb, offset, pinfo, tree, drep,
hf_netlogon_db_modify_time);
offset = dissect_ndr_nt_NTTIME(tvb, offset, pinfo, tree, drep,
hf_netlogon_db_create_time);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_security_information, NULL);
offset = lsarpc_dissect_sec_desc_buf(tvb, offset, pinfo, tree, drep);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_dummy, 0);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_dummy, 0);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_dummy, 0);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_dummy, 0);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_reserved, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_reserved, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_reserved, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_reserved, NULL);
return offset;
}
static int
netlogon_dissect_CONTROLLER(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
guint8 *drep)
{
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_dc_name, 0);
return offset;
}
static int
netlogon_dissect_CONTROLLER_ARRAY(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
guint8 *drep)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, drep,
netlogon_dissect_CONTROLLER);
return offset;
}
static int
netlogon_dissect_DELTA_TRUSTED_DOMAINS(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
guint8 *drep)
{
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_domain_name, 0);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_num_controllers, NULL);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_CONTROLLER_ARRAY, NDR_POINTER_UNIQUE,
"Domain Controllers:", -1);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_security_information, NULL);
offset = lsarpc_dissect_sec_desc_buf(tvb, offset, pinfo, tree, drep);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_dummy, 0);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_dummy, 0);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_dummy, 0);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_dummy, 0);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_reserved, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_reserved, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_reserved, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_reserved, NULL);
return offset;
}
static int
netlogon_dissect_PRIV_ATTR(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
guint8 *drep)
{
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_attrs, NULL);
return offset;
}
static int
netlogon_dissect_PRIV_ATTR_ARRAY(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
guint8 *drep)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, drep,
netlogon_dissect_PRIV_ATTR);
return offset;
}
static int
netlogon_dissect_PRIV_NAME(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
guint8 *drep)
{
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_privilege_name, 1);
return offset;
}
static int
netlogon_dissect_PRIV_NAME_ARRAY(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
guint8 *drep)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, drep,
netlogon_dissect_PRIV_NAME);
return offset;
}
static int
netlogon_dissect_DELTA_ACCOUNTS(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
guint8 *drep)
{
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_privilege_entries, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_privilege_control, NULL);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_PRIV_ATTR_ARRAY, NDR_POINTER_UNIQUE,
"PRIV_ATTR_ARRAY:", -1);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_PRIV_NAME_ARRAY, NDR_POINTER_UNIQUE,
"PRIV_NAME_ARRAY:", -1);
offset = netlogon_dissect_QUOTA_LIMITS(tvb, offset,
pinfo, tree, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_systemflags, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_security_information, NULL);
offset = lsarpc_dissect_sec_desc_buf(tvb, offset, pinfo, tree, drep);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_dummy, 0);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_dummy, 0);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_dummy, 0);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_dummy, 0);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_reserved, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_reserved, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_reserved, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_reserved, NULL);
return offset;
}
static int
netlogon_dissect_CIPHER_VALUE_DATA(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
guint8 *drep)
{
dcerpc_info *di;
guint32 data_len;
di=pinfo->private_data;
if(di->conformant_run){
return offset;
}
offset = dissect_ndr_uint32 (tvb, offset, pinfo, tree, drep,
hf_netlogon_cipher_maxlen, NULL);
offset += 4;
offset = dissect_ndr_uint32 (tvb, offset, pinfo, tree, drep,
hf_netlogon_cipher_len, &data_len);
proto_tree_add_item(tree, di->hf_index, tvb, offset,
data_len, ENC_NA);
offset += data_len;
return offset;
}
static int
netlogon_dissect_CIPHER_VALUE(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *parent_tree,
guint8 *drep, const char *name, int hf_index)
{
proto_item *item=NULL;
proto_tree *tree=NULL;
int old_offset=offset;
if(parent_tree){
item = proto_tree_add_text(parent_tree, tvb, offset, 0,
"%s", name);
tree = proto_item_add_subtree(item, ett_CYPHER_VALUE);
}
offset = dissect_ndr_uint32 (tvb, offset, pinfo, tree, drep,
hf_netlogon_cipher_len, NULL);
offset = dissect_ndr_uint32 (tvb, offset, pinfo, tree, drep,
hf_netlogon_cipher_maxlen, NULL);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_CIPHER_VALUE_DATA, NDR_POINTER_UNIQUE,
name, hf_index);
proto_item_set_len(item, offset-old_offset);
return offset;
}
static int
netlogon_dissect_DELTA_SECRET(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
guint8 *drep)
{
offset = netlogon_dissect_CIPHER_VALUE(tvb, offset,
pinfo, tree, drep,
"CIPHER_VALUE: current cipher value",
hf_netlogon_cipher_current_data);
offset = dissect_ndr_nt_NTTIME(tvb, offset, pinfo, tree, drep,
hf_netlogon_cipher_current_set_time);
offset = netlogon_dissect_CIPHER_VALUE(tvb, offset,
pinfo, tree, drep,
"CIPHER_VALUE: old cipher value",
hf_netlogon_cipher_old_data);
offset = dissect_ndr_nt_NTTIME(tvb, offset, pinfo, tree, drep,
hf_netlogon_cipher_old_set_time);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_security_information, NULL);
offset = lsarpc_dissect_sec_desc_buf(tvb, offset, pinfo, tree, drep);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_dummy, 0);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_dummy, 0);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_dummy, 0);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_dummy, 0);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_reserved, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_reserved, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_reserved, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_reserved, NULL);
return offset;
}
static int
netlogon_dissect_MODIFIED_COUNT(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
guint8 *drep)
{
offset = dissect_ndr_duint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_modify_count, NULL);
return offset;
}
static int
netlogon_dissect_DELTA_UNION(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *parent_tree,
guint8 *drep)
{
proto_item *item=NULL;
proto_tree *tree=NULL;
int old_offset=offset;
guint16 level = 0;
if(parent_tree){
item = proto_tree_add_text(parent_tree, tvb, offset, 0,
"DELTA_UNION:");
tree = proto_item_add_subtree(item, ett_DELTA_UNION);
}
offset = dissect_ndr_uint16(tvb, offset, pinfo, tree, drep,
hf_netlogon_delta_type, &level);
ALIGN_TO_4_BYTES;
switch(level){
case 1:
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_DELTA_DOMAIN, NDR_POINTER_UNIQUE,
"DELTA_DOMAIN:", -1);
break;
case 2:
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_DELTA_GROUP, NDR_POINTER_UNIQUE,
"DELTA_GROUP:", -1);
break;
case 4:
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_DELTA_RENAME, NDR_POINTER_UNIQUE,
"DELTA_RENAME_GROUP:", hf_netlogon_group_name);
break;
case 5:
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_DELTA_USER, NDR_POINTER_UNIQUE,
"DELTA_USER:", -1);
break;
case 7:
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_DELTA_RENAME, NDR_POINTER_UNIQUE,
"DELTA_RENAME_USER:", hf_netlogon_acct_name);
break;
case 8:
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_DELTA_GROUP_MEMBER, NDR_POINTER_UNIQUE,
"DELTA_GROUP_MEMBER:", -1);
break;
case 9:
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_DELTA_ALIAS, NDR_POINTER_UNIQUE,
"DELTA_ALIAS:", -1);
break;
case 11:
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_DELTA_RENAME, NDR_POINTER_UNIQUE,
"DELTA_RENAME_ALIAS:", hf_netlogon_alias_name);
break;
case 12:
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_DELTA_ALIAS_MEMBER, NDR_POINTER_UNIQUE,
"DELTA_ALIAS_MEMBER:", -1);
break;
case 13:
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_DELTA_POLICY, NDR_POINTER_UNIQUE,
"DELTA_POLICY:", -1);
break;
case 14:
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_DELTA_TRUSTED_DOMAINS, NDR_POINTER_UNIQUE,
"DELTA_TRUSTED_DOMAINS:", -1);
break;
case 16:
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_DELTA_ACCOUNTS, NDR_POINTER_UNIQUE,
"DELTA_ACCOUNTS:", -1);
break;
case 18:
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_DELTA_SECRET, NDR_POINTER_UNIQUE,
"DELTA_SECRET:", -1);
break;
case 20:
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_DELTA_DELETE_USER, NDR_POINTER_UNIQUE,
"DELTA_DELETE_GROUP:", -1);
break;
case 21:
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_DELTA_DELETE_USER, NDR_POINTER_UNIQUE,
"DELTA_DELETE_USER:", -1);
break;
case 22:
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_MODIFIED_COUNT, NDR_POINTER_UNIQUE,
"MODIFIED_COUNT:", -1);
break;
}
proto_item_set_len(item, offset-old_offset);
return offset;
}
static int
netlogon_dissect_DELTA_ID_UNION(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *parent_tree,
guint8 *drep)
{
proto_item *item=NULL;
proto_tree *tree=NULL;
int old_offset=offset;
guint16 level = 0;
if(parent_tree){
item = proto_tree_add_text(parent_tree, tvb, offset, 0,
"DELTA_ID_UNION:");
tree = proto_item_add_subtree(item, ett_DELTA_ID_UNION);
}
offset = dissect_ndr_uint16(tvb, offset, pinfo, tree, drep,
hf_netlogon_delta_type, &level);
ALIGN_TO_4_BYTES;
switch(level){
case 1:
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_group_rid, NULL);
break;
case 2:
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_user_rid, NULL);
break;
case 3:
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_user_rid, NULL);
break;
case 4:
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_user_rid, NULL);
break;
case 5:
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_user_rid, NULL);
break;
case 6:
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_user_rid, NULL);
break;
case 7:
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_user_rid, NULL);
break;
case 8:
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_user_rid, NULL);
break;
case 9:
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_user_rid, NULL);
break;
case 10:
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_user_rid, NULL);
break;
case 11:
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_user_rid, NULL);
break;
case 12:
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_user_rid, NULL);
break;
case 13:
offset = dissect_ndr_nt_PSID(tvb, offset, pinfo, tree, drep);
break;
case 14:
offset = dissect_ndr_nt_PSID(tvb, offset, pinfo, tree, drep);
break;
case 15:
offset = dissect_ndr_nt_PSID(tvb, offset, pinfo, tree, drep);
break;
case 16:
offset = dissect_ndr_nt_PSID(tvb, offset, pinfo, tree, drep);
break;
case 17:
offset = dissect_ndr_nt_PSID(tvb, offset, pinfo, tree, drep);
break;
case 18:
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo,
tree, drep, NDR_POINTER_UNIQUE, "unknown",
hf_netlogon_unknown_string, 0);
break;
case 19:
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo,
tree, drep, NDR_POINTER_UNIQUE, "unknown",
hf_netlogon_unknown_string, 0);
break;
case 20:
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_user_rid, NULL);
break;
case 21:
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_user_rid, NULL);
break;
}
proto_item_set_len(item, offset-old_offset);
return offset;
}
static int
netlogon_dissect_DELTA_ENUM(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *parent_tree,
guint8 *drep)
{
proto_item *item=NULL;
proto_tree *tree=NULL;
int old_offset=offset;
guint16 type;
if(parent_tree){
item = proto_tree_add_text(parent_tree, tvb, offset, 0,
"DELTA_ENUM:");
tree = proto_item_add_subtree(item, ett_DELTA_ENUM);
}
offset = dissect_ndr_uint16(tvb, offset, pinfo, tree, drep,
hf_netlogon_delta_type, &type);
proto_item_append_text(item, "%s", val_to_str(
type, delta_type_vals, "Unknown"));
offset = netlogon_dissect_DELTA_ID_UNION(tvb, offset,
pinfo, tree, drep);
offset = netlogon_dissect_DELTA_UNION(tvb, offset,
pinfo, tree, drep);
proto_item_set_len(item, offset-old_offset);
return offset;
}
static int
netlogon_dissect_DELTA_ENUM_array(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
guint8 *drep)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, drep,
netlogon_dissect_DELTA_ENUM);
return offset;
}
static int
netlogon_dissect_DELTA_ENUM_ARRAY(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
guint8 *drep)
{
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_num_deltas, NULL);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_DELTA_ENUM_array, NDR_POINTER_UNIQUE,
"DELTA_ENUM: deltas", -1);
return offset;
}
static int
netlogon_dissect_netrdatabasedeltas_rqst(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, drep,
NDR_POINTER_REF, "Server Handle", hf_netlogon_logonsrv_handle, 0);
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, drep,
NDR_POINTER_REF, "Computer Name", hf_netlogon_computer_name, 0);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_AUTHENTICATOR, NDR_POINTER_REF,
"AUTHENTICATOR: credential", -1);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_AUTHENTICATOR, NDR_POINTER_REF,
"AUTHENTICATOR: return_authenticator", -1);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_database_id, NULL);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_MODIFIED_COUNT, NDR_POINTER_REF,
"MODIFIED_COUNT: domain modified count", -1);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_max_size, NULL);
return offset;
}
static int
netlogon_dissect_netrdatabasedeltas_reply(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_AUTHENTICATOR, NDR_POINTER_REF,
"AUTHENTICATOR: return_authenticator", -1);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_MODIFIED_COUNT, NDR_POINTER_REF,
"MODIFIED_COUNT: domain modified count", -1);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_DELTA_ENUM_ARRAY, NDR_POINTER_UNIQUE,
"DELTA_ENUM_ARRAY: deltas", -1);
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep,
hf_netlogon_rc, NULL);
return offset;
}
static int
netlogon_dissect_netrdatabasesync_rqst(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, drep,
NDR_POINTER_REF, "Server Handle", hf_netlogon_logonsrv_handle, 0);
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, drep,
NDR_POINTER_REF, "Computer Name", hf_netlogon_computer_name, 0);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_AUTHENTICATOR, NDR_POINTER_REF,
"AUTHENTICATOR: credential", -1);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_AUTHENTICATOR, NDR_POINTER_REF,
"AUTHENTICATOR: return_authenticator", -1);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_database_id, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_sync_context, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_max_size, NULL);
return offset;
}
static int
netlogon_dissect_netrdatabasesync_reply(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_AUTHENTICATOR, NDR_POINTER_REF,
"AUTHENTICATOR: return_authenticator", -1);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_sync_context, NULL);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_DELTA_ENUM_ARRAY, NDR_POINTER_UNIQUE,
"DELTA_ENUM_ARRAY: deltas", -1);
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep,
hf_netlogon_rc, NULL);
return offset;
}
static int
netlogon_dissect_UAS_INFO_0(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
guint8 *drep)
{
dcerpc_info *di;
di=pinfo->private_data;
if(di->conformant_run){
return offset;
}
proto_tree_add_item(tree, hf_netlogon_computer_name, tvb, offset, 16, ENC_ASCII|ENC_NA);
offset += 16;
proto_tree_add_text(tree, tvb, offset, 4, "Time Created: unknown time format");
offset+= 4;
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_serial_number, NULL);
return offset;
}
static int
netlogon_dissect_netraccountdeltas_rqst(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = netlogon_dissect_LOGONSRV_HANDLE(tvb, offset,
pinfo, tree, drep);
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, drep,
NDR_POINTER_REF, "Computer Name", hf_netlogon_computer_name, 0);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_AUTHENTICATOR, NDR_POINTER_REF,
"AUTHENTICATOR: credential", -1);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_AUTHENTICATOR, NDR_POINTER_REF,
"AUTHENTICATOR: return_authenticator", -1);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_UAS_INFO_0, NDR_POINTER_REF,
"UAS_INFO_0: RecordID", -1);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_count, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_level, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_max_size, NULL);
return offset;
}
static int
netlogon_dissect_netraccountdeltas_reply(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_AUTHENTICATOR, NDR_POINTER_REF,
"AUTHENTICATOR: return_authenticator", -1);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_BYTE_array, NDR_POINTER_REF,
"BYTE_array: Buffer", -1);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_count, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_entries, NULL);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_UAS_INFO_0, NDR_POINTER_REF,
"UAS_INFO_0: RecordID", -1);
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep,
hf_netlogon_rc, NULL);
return offset;
}
static int
netlogon_dissect_netraccountsync_rqst(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = netlogon_dissect_LOGONSRV_HANDLE(tvb, offset,
pinfo, tree, drep);
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, drep,
NDR_POINTER_REF, "Computer Name", hf_netlogon_computer_name, 0);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_AUTHENTICATOR, NDR_POINTER_REF,
"AUTHENTICATOR: credential", -1);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_AUTHENTICATOR, NDR_POINTER_REF,
"AUTHENTICATOR: return_authenticator", -1);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_reference, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_level, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_max_size, NULL);
return offset;
}
static int
netlogon_dissect_netraccountsync_reply(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_AUTHENTICATOR, NDR_POINTER_REF,
"AUTHENTICATOR: return_authenticator", -1);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_BYTE_array, NDR_POINTER_REF,
"BYTE_array: Buffer", -1);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_count, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_entries, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_next_reference, NULL);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_UAS_INFO_0, NDR_POINTER_REF,
"UAS_INFO_0: RecordID", -1);
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep,
hf_netlogon_rc, NULL);
return offset;
}
static int
netlogon_dissect_netrgetdcname_rqst(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, drep,
NDR_POINTER_REF, "Server Handle", hf_netlogon_logonsrv_handle, 0);
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, drep,
NDR_POINTER_UNIQUE, "Domain", hf_netlogon_domain_name, 0);
return offset;
}
static int
netlogon_dissect_netrgetdcname_reply(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, drep,
NDR_POINTER_UNIQUE, "Domain", hf_netlogon_dc_name, 0);
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep,
hf_netlogon_rc, NULL);
return offset;
}
static int
netlogon_dissect_NETLOGON_INFO_1(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
guint8 *drep)
{
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_flags, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_pdc_connection_status, NULL);
return offset;
}
static int
netlogon_dissect_NETLOGON_INFO_2(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
guint8 *drep)
{
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_flags, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_pdc_connection_status, NULL);
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, drep,
NDR_POINTER_UNIQUE, "Trusted DC Name",
hf_netlogon_trusted_dc_name, 0);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_tc_connection_status, NULL);
return offset;
}
static int
netlogon_dissect_NETLOGON_INFO_3(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
guint8 *drep)
{
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_flags, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_logon_attempts, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_reserved, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_reserved, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_reserved, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_reserved, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_reserved, NULL);
return offset;
}
static int
netlogon_dissect_CONTROL_QUERY_INFORMATION(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
guint8 *drep)
{
guint32 level = 0;
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_level, &level);
ALIGN_TO_4_BYTES;
switch(level){
case 1:
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_NETLOGON_INFO_1, NDR_POINTER_UNIQUE,
"NETLOGON_INFO_1:", -1);
break;
case 2:
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_NETLOGON_INFO_2, NDR_POINTER_UNIQUE,
"NETLOGON_INFO_2:", -1);
break;
case 3:
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_NETLOGON_INFO_3, NDR_POINTER_UNIQUE,
"NETLOGON_INFO_3:", -1);
break;
}
return offset;
}
static int
netlogon_dissect_netrlogoncontrol_rqst(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = netlogon_dissect_LOGONSRV_HANDLE(tvb, offset,
pinfo, tree, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_code, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_level, NULL);
return offset;
}
static int
netlogon_dissect_netrlogoncontrol_reply(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_CONTROL_QUERY_INFORMATION, NDR_POINTER_REF,
"CONTROL_QUERY_INFORMATION:", -1);
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep,
hf_netlogon_dos_rc, NULL);
return offset;
}
static int
netlogon_dissect_netrgetanydcname_rqst(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, drep,
NDR_POINTER_UNIQUE, "Server Handle",
hf_netlogon_logonsrv_handle, 0);
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, drep,
NDR_POINTER_UNIQUE, "Domain", hf_netlogon_domain_name, 0);
return offset;
}
static int
netlogon_dissect_netrgetanydcname_reply(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, drep,
NDR_POINTER_UNIQUE, "Domain", hf_netlogon_dc_name, 0);
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep,
hf_netlogon_dos_rc, NULL);
return offset;
}
static int
netlogon_dissect_CONTROL_DATA_INFORMATION(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
guint8 *drep)
{
guint32 level = 0;
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_level, &level);
ALIGN_TO_4_BYTES;
switch(level){
case 5:
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo,
tree, drep, NDR_POINTER_UNIQUE, "Trusted Domain Name",
hf_netlogon_TrustedDomainName_string, 0);
break;
case 6:
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo,
tree, drep, NDR_POINTER_UNIQUE, "Trusted Domain Name",
hf_netlogon_TrustedDomainName_string, 0);
break;
case 0xfffe:
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_unknown_long, NULL);
break;
case 8:
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo,
tree, drep, NDR_POINTER_UNIQUE, "UserName",
hf_netlogon_UserName_string, 0);
break;
}
return offset;
}
static int
netlogon_dissect_netrlogoncontrol2_rqst(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = netlogon_dissect_LOGONSRV_HANDLE(tvb, offset,
pinfo, tree, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_code, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_level, NULL);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_CONTROL_DATA_INFORMATION, NDR_POINTER_REF,
"CONTROL_DATA_INFORMATION: ", -1);
return offset;
}
static int
netlogon_dissect_netrlogoncontrol2_reply(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
guint32 status;
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_CONTROL_QUERY_INFORMATION, NDR_POINTER_REF,
"CONTROL_QUERY_INFORMATION:", -1);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep, hf_netlogon_werr_rc, &status);
if (status != 0 && check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ", Error: %s", val_to_str(status, WERR_errors, "Unknown WERR error 0x%08x"));
return offset;
}
static int
netlogon_dissect_netrdatabasesync2_rqst(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, drep,
NDR_POINTER_REF, "Server Handle", hf_netlogon_logonsrv_handle, 0);
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, drep,
NDR_POINTER_REF, "Computer Name", hf_netlogon_computer_name, 0);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_AUTHENTICATOR, NDR_POINTER_REF,
"AUTHENTICATOR: credential", -1);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_AUTHENTICATOR, NDR_POINTER_REF,
"AUTHENTICATOR: return_authenticator", -1);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_database_id, NULL);
offset = dissect_ndr_uint16(tvb, offset, pinfo, tree, drep,
hf_netlogon_restart_state, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_sync_context, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_max_size, NULL);
return offset;
}
static int
netlogon_dissect_netrdatabasesync2_reply(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_AUTHENTICATOR, NDR_POINTER_REF,
"AUTHENTICATOR: return_authenticator", -1);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_sync_context, NULL);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_DELTA_ENUM_ARRAY, NDR_POINTER_UNIQUE,
"DELTA_ENUM_ARRAY: deltas", -1);
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep,
hf_netlogon_rc, NULL);
return offset;
}
static int
netlogon_dissect_netrdatabaseredo_rqst(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, drep,
NDR_POINTER_REF, "Server Handle", hf_netlogon_logonsrv_handle, 0);
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, drep,
NDR_POINTER_REF, "Computer Name", hf_netlogon_computer_name, 0);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_AUTHENTICATOR, NDR_POINTER_REF,
"AUTHENTICATOR: credential", -1);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_AUTHENTICATOR, NDR_POINTER_REF,
"AUTHENTICATOR: return_authenticator", -1);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_BYTE_array, NDR_POINTER_REF,
"Change log entry: ", -1);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_max_log_size, NULL);
return offset;
}
static int
netlogon_dissect_netrdatabaseredo_reply(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_AUTHENTICATOR, NDR_POINTER_REF,
"AUTHENTICATOR: return_authenticator", -1);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_DELTA_ENUM_ARRAY, NDR_POINTER_UNIQUE,
"DELTA_ENUM_ARRAY: deltas", -1);
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep,
hf_netlogon_rc, NULL);
return offset;
}
static int
netlogon_dissect_netrlogoncontrol2ex_rqst(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = netlogon_dissect_LOGONSRV_HANDLE(tvb, offset,
pinfo, tree, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_code, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_level, NULL);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_CONTROL_DATA_INFORMATION, NDR_POINTER_REF,
"CONTROL_DATA_INFORMATION: ", -1);
return offset;
}
static int
netlogon_dissect_netrlogoncontrol2ex_reply(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_CONTROL_QUERY_INFORMATION, NDR_POINTER_REF,
"CONTROL_QUERY_INFORMATION:", -1);
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep,
hf_netlogon_dos_rc, NULL);
return offset;
}
static int
netlogon_dissect_DOMAIN_TRUST_FLAGS(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *parent_tree, guint8 *drep)
{
guint32 mask;
proto_item *item = NULL;
proto_tree *tree = NULL;
dcerpc_info *di;
di=pinfo->private_data;
if(di->conformant_run){
return offset;
}
offset=dissect_ndr_uint32(tvb, offset, pinfo, NULL, drep,
hf_netlogon_trust_flags, &mask);
if(parent_tree){
item = proto_tree_add_uint(parent_tree, hf_netlogon_trust_flags,
tvb, offset-4, 4, mask);
tree = proto_item_add_subtree(item, ett_trust_flags);
}
proto_tree_add_boolean(tree, hf_netlogon_trust_flags_inbound,
tvb, offset-4, 4, mask);
proto_tree_add_boolean(tree, hf_netlogon_trust_flags_native_mode,
tvb, offset-4, 4, mask);
proto_tree_add_boolean(tree, hf_netlogon_trust_flags_primary,
tvb, offset-4, 4, mask);
proto_tree_add_boolean(tree, hf_netlogon_trust_flags_tree_root,
tvb, offset-4, 4, mask);
proto_tree_add_boolean(tree, hf_netlogon_trust_flags_outbound,
tvb, offset-4, 4, mask);
proto_tree_add_boolean(tree, hf_netlogon_trust_flags_in_forest,
tvb, offset-4, 4, mask);
return offset;
}
static int
netlogon_dissect_DOMAIN_TRUST_ATTRIBS(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *parent_tree, guint8 *drep)
{
guint32 mask;
proto_item *item = NULL;
proto_tree *tree = NULL;
dcerpc_info *di;
di=pinfo->private_data;
if(di->conformant_run){
return offset;
}
offset = dissect_ndr_uint32(tvb, offset, pinfo, NULL, drep,
hf_netlogon_trust_attribs, &mask);
if(parent_tree){
item = proto_tree_add_uint(parent_tree, hf_netlogon_trust_attribs,
tvb, offset-4, 4, mask);
tree = proto_item_add_subtree(item, ett_trust_attribs);
}
proto_tree_add_boolean(tree, hf_netlogon_trust_attribs_treat_as_external,
tvb, offset-4, 4, mask);
proto_tree_add_boolean(tree, hf_netlogon_trust_attribs_within_forest,
tvb, offset-4, 4, mask);
proto_tree_add_boolean(tree, hf_netlogon_trust_attribs_cross_organization,
tvb, offset-4, 4, mask);
proto_tree_add_boolean(tree, hf_netlogon_trust_attribs_forest_transitive,
tvb, offset-4, 4, mask);
proto_tree_add_boolean(tree, hf_netlogon_trust_attribs_quarantined_domain,
tvb, offset-4, 4, mask);
proto_tree_add_boolean(tree, hf_netlogon_trust_attribs_uplevel_only,
tvb, offset-4, 4, mask);
proto_tree_add_boolean(tree, hf_netlogon_trust_attribs_non_transitive,
tvb, offset-4, 4, mask);
return offset;
}
static int
netlogon_dissect_GET_DCNAME_REQUEST_FLAGS(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *parent_tree, guint8 *drep)
{
guint32 mask;
proto_item *item = NULL;
proto_tree *tree = NULL;
dcerpc_info *di;
di=pinfo->private_data;
if(di->conformant_run){
return offset;
}
offset=dissect_ndr_uint32(tvb, offset, pinfo, NULL, drep,
hf_netlogon_get_dcname_request_flags, &mask);
if(parent_tree){
item = proto_tree_add_uint(parent_tree, hf_netlogon_get_dcname_request_flags,
tvb, offset-4, 4, mask);
tree = proto_item_add_subtree(item, ett_get_dcname_request_flags);
}
proto_tree_add_boolean(tree, hf_netlogon_get_dcname_request_flags_return_flat_name,
tvb, offset-4, 4, mask);
proto_tree_add_boolean(tree, hf_netlogon_get_dcname_request_flags_return_dns_name,
tvb, offset-4, 4, mask);
proto_tree_add_boolean(tree, hf_netlogon_get_dcname_request_flags_is_flat_name,
tvb, offset-4, 4, mask);
proto_tree_add_boolean(tree, hf_netlogon_get_dcname_request_flags_is_dns_name,
tvb, offset-4, 4, mask);
proto_tree_add_boolean(tree, hf_netlogon_get_dcname_request_flags_only_ldap_needed,
tvb, offset-4, 4, mask);
proto_tree_add_boolean(tree, hf_netlogon_get_dcname_request_flags_avoid_self,
tvb, offset-4, 4, mask);
proto_tree_add_boolean(tree, hf_netlogon_get_dcname_request_flags_good_timeserv_preferred,
tvb, offset-4, 4, mask);
proto_tree_add_boolean(tree, hf_netlogon_get_dcname_request_flags_writable_required,
tvb, offset-4, 4, mask);
proto_tree_add_boolean(tree, hf_netlogon_get_dcname_request_flags_timeserv_required,
tvb, offset-4, 4, mask);
proto_tree_add_boolean(tree, hf_netlogon_get_dcname_request_flags_kdc_required,
tvb, offset-4, 4, mask);
proto_tree_add_boolean(tree, hf_netlogon_get_dcname_request_flags_ip_required,
tvb, offset-4, 4, mask);
proto_tree_add_boolean(tree, hf_netlogon_get_dcname_request_flags_background_only,
tvb, offset-4, 4, mask);
proto_tree_add_boolean(tree, hf_netlogon_get_dcname_request_flags_pdc_required,
tvb, offset-4, 4, mask);
proto_tree_add_boolean(tree, hf_netlogon_get_dcname_request_flags_gc_server_required,
tvb, offset-4, 4, mask);
proto_tree_add_boolean(tree, hf_netlogon_get_dcname_request_flags_directory_service_preferred,
tvb, offset-4, 4, mask);
proto_tree_add_boolean(tree, hf_netlogon_get_dcname_request_flags_directory_service_required,
tvb, offset-4, 4, mask);
proto_tree_add_boolean(tree, hf_netlogon_get_dcname_request_flags_force_rediscovery,
tvb, offset-4, 4, mask);
return offset;
}
static int
netlogon_dissect_DC_FLAGS(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *parent_tree, guint8 *drep)
{
guint32 mask;
proto_item *item = NULL;
proto_tree *tree = NULL;
dcerpc_info *di;
di=pinfo->private_data;
if(di->conformant_run){
return offset;
}
offset=dissect_ndr_uint32(tvb, offset, pinfo, NULL, drep,
hf_netlogon_dc_flags, &mask);
if(parent_tree){
item = proto_tree_add_uint_format_value(parent_tree, hf_netlogon_dc_flags,
tvb, offset-4, 4, mask, "0x%08x%s", mask, (mask==0x0000ffff)?" PING (mask==0x0000ffff)":"");
tree = proto_item_add_subtree(item, ett_dc_flags);
}
proto_tree_add_boolean(tree, hf_netlogon_dc_flags_dns_forest_flag,
tvb, offset-4, 4, mask);
proto_tree_add_boolean(tree, hf_netlogon_dc_flags_dns_domain_flag,
tvb, offset-4, 4, mask);
proto_tree_add_boolean(tree, hf_netlogon_dc_flags_dns_controller_flag,
tvb, offset-4, 4, mask);
proto_tree_add_boolean(tree, hf_netlogon_dc_flags_ndnc_flag,
tvb, offset-4, 4, mask);
proto_tree_add_boolean(tree, hf_netlogon_dc_flags_good_timeserv_flag,
tvb, offset-4, 4, mask);
proto_tree_add_boolean(tree, hf_netlogon_dc_flags_writable_flag,
tvb, offset-4, 4, mask);
proto_tree_add_boolean(tree, hf_netlogon_dc_flags_closest_flag,
tvb, offset-4, 4, mask);
proto_tree_add_boolean(tree, hf_netlogon_dc_flags_timeserv_flag,
tvb, offset-4, 4, mask);
proto_tree_add_boolean(tree, hf_netlogon_dc_flags_kdc_flag,
tvb, offset-4, 4, mask);
proto_tree_add_boolean(tree, hf_netlogon_dc_flags_ds_flag,
tvb, offset-4, 4, mask);
proto_tree_add_boolean(tree, hf_netlogon_dc_flags_ldap_flag,
tvb, offset-4, 4, mask);
proto_tree_add_boolean(tree, hf_netlogon_dc_flags_gc_flag,
tvb, offset-4, 4, mask);
proto_tree_add_boolean(tree, hf_netlogon_dc_flags_pdc_flag,
tvb, offset-4, 4, mask);
return offset;
}
static int
netlogon_dissect_pointer_long(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
guint8 *drep)
{
dcerpc_info *di;
di=pinfo->private_data;
offset = dissect_ndr_uint32 (tvb, offset, pinfo, tree, drep,
di->hf_index, NULL);
return offset;
}
static int
netlogon_dissect_UNICODE_MULTI_byte(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
guint8 *drep)
{
offset = dissect_ndr_uint8(tvb, offset, pinfo, tree, drep,
hf_netlogon_unknown_char, NULL);
return offset;
}
static int
netlogon_dissect_UNICODE_MULTI_array(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
guint8 *drep)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, drep,
netlogon_dissect_UNICODE_MULTI_byte);
return offset;
}
static int
netlogon_dissect_UNICODE_MULTI(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *parent_tree,
guint8 *drep)
{
proto_item *item=NULL;
proto_tree *tree=NULL;
int old_offset=offset;
if(parent_tree){
item = proto_tree_add_text(parent_tree, tvb, offset, 0,
"UNICODE_MULTI:");
tree = proto_item_add_subtree(item, ett_UNICODE_MULTI);
}
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_len, NULL);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_UNICODE_MULTI_array, NDR_POINTER_UNIQUE,
"unknown", hf_netlogon_unknown_string);
proto_item_set_len(item, offset-old_offset);
return offset;
}
static int
netlogon_dissect_DOMAIN_CONTROLLER_INFO(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *parent_tree,
guint8 *drep)
{
proto_item *item=NULL;
proto_tree *tree=NULL;
int old_offset=offset;
if(parent_tree){
item = proto_tree_add_text(parent_tree, tvb, offset, 0,
"DOMAIN_CONTROLLER_INFO:");
tree = proto_item_add_subtree(item, ett_DOMAIN_CONTROLLER_INFO);
}
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, drep,
NDR_POINTER_UNIQUE, "DC Name", hf_netlogon_dc_name, 0);
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, drep,
NDR_POINTER_UNIQUE, "DC Address", hf_netlogon_dc_address, 0);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_dc_address_type, NULL);
offset = dissect_nt_GUID(tvb, offset,
pinfo, tree, drep);
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, drep,
NDR_POINTER_UNIQUE, "Logon Domain", hf_netlogon_logon_dom, 0);
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, drep,
NDR_POINTER_UNIQUE, "DNS Forest", hf_netlogon_dns_forest_name, 0);
offset = netlogon_dissect_DC_FLAGS(tvb, offset, pinfo, tree, drep);
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, drep,
NDR_POINTER_UNIQUE, "DC Site", hf_netlogon_dc_site_name, 0);
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, drep,
NDR_POINTER_UNIQUE, "Client Site",
hf_netlogon_client_site_name, 0);
proto_item_set_len(item, offset-old_offset);
return offset;
}
static int
dissect_ndr_trust_extension(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
guint8 *drep)
{
guint32 len,max;
dcerpc_info *di;
di=pinfo->private_data;
if(di->conformant_run){
return offset;
}
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_trust_max, &max);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_trust_offset, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_trust_len, &len);
if( max * 2 == 16 ) {
offset = netlogon_dissect_DOMAIN_TRUST_FLAGS(tvb, offset, pinfo, tree, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_trust_parent_index, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_trust_type, NULL);
offset = netlogon_dissect_DOMAIN_TRUST_ATTRIBS(tvb, offset, pinfo, tree, drep);
}
return offset;
}
static int
netlogon_dissect_BLOB_array(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
guint8 *drep)
{
guint32 len;
dcerpc_info *di;
di=pinfo->private_data;
if(di->conformant_run){
return offset;
}
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_blob_size, &len);
proto_tree_add_item(tree, hf_netlogon_blob, tvb, offset, len,
ENC_NA);
offset += len;
return offset;
}
static int
dissect_ndr_ulongs_as_counted_string(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
guint8 *drep, int hf_index)
{
dcerpc_info *di = pinfo->private_data;
guint16 len, size;
gboolean add_subtree = TRUE;
proto_item *item;
proto_tree *subtree = tree;
if (add_subtree) {
item = proto_tree_add_text(
tree, tvb, offset, 0, "%s",
proto_registrar_get_name(hf_index));
subtree = proto_item_add_subtree(item, ett_nt_counted_longs_as_string);
}
ALIGN_TO_4_BYTES;
if (di->conformant_run)
return offset;
offset = dissect_ndr_uint16(tvb, offset, pinfo, subtree, drep,
hf_nt_cs_len, &len);
offset = dissect_ndr_uint16(tvb, offset, pinfo, subtree, drep,
hf_nt_cs_size, &size);
offset = dissect_ndr_pointer_cb(tvb, offset, pinfo, subtree, drep,
dissect_ndr_trust_extension, NDR_POINTER_UNIQUE,
"Buffer", hf_index,NULL,NULL);
return offset;
}
static int
DomainInfo_sid_(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep _U_)
{
offset = lsarpc_dissect_struct_dom_sid2(tvb,offset,pinfo,tree,drep,DomainInfo_sid,0);
return offset;
}
static int
dissect_element_lsa_DnsDomainInfo_sid(tvbuff_t *tvb , int offset , packet_info *pinfo , proto_tree *tree , guint8 *drep )
{
offset = dissect_ndr_embedded_pointer(tvb, offset, pinfo, tree, drep, DomainInfo_sid_, NDR_POINTER_UNIQUE, "Pointer to Sid (dom_sid2)",DnsDomainInfo_sid);
return offset;
}
static int
dissect_element_lsa_DnsDomainInfo_domain_guid(tvbuff_t *tvb _U_, int offset _U_, packet_info *pinfo _U_, proto_tree *tree _U_, guint8 *drep )
{
offset = dissect_ndr_uuid_t(tvb, offset, pinfo, tree, drep, DnsDomainInfo_domain_guid, NULL);
return offset;
}
static int dissect_part_DnsDomainInfo(tvbuff_t *tvb , int offset, packet_info *pinfo, proto_tree *tree , guint8 *drep, int hf_index _U_, guint32 param _U_)
{
offset = lsarpc_dissect_struct_lsa_StringLarge(tvb,offset,pinfo,tree,drep,DnsDomainInfo_name,0);
offset = lsarpc_dissect_struct_lsa_StringLarge(tvb,offset,pinfo,tree,drep,DnsDomainInfo_dns_domain,0);
offset = lsarpc_dissect_struct_lsa_StringLarge(tvb,offset,pinfo,tree,drep,DnsDomainInfo_dns_forest,0);
offset = dissect_element_lsa_DnsDomainInfo_domain_guid(tvb, offset, pinfo, tree, drep);
offset = dissect_element_lsa_DnsDomainInfo_sid(tvb, offset, pinfo, tree, drep);
return offset;
}
static int
netlogon_dissect_ONE_DOMAIN_INFO(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *parent_tree,
guint8 *drep)
{
proto_item *item=NULL;
proto_tree *tree=NULL;
int old_offset=offset;
if(parent_tree){
item = proto_tree_add_text(parent_tree, tvb, offset, 0,
"ONE_DOMAIN_INFO");
tree = proto_item_add_subtree(item, ett_DOMAIN_TRUST_INFO);
}
offset = dissect_part_DnsDomainInfo(tvb, offset, pinfo, tree, drep, 0, 0);
offset = dissect_ndr_ulongs_as_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_trust_extention);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_dummy_string2, 0);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_dummy_string3, 0);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_dummy_string4, 0);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_dummy1_long, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_dummy2_long, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_dummy3_long, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_dummy4_long, NULL);
proto_item_set_len(item, offset-old_offset);
return offset;
}
static int
netlogon_dissect_DOMAIN_TRUST_INFO(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
guint8 *drep)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, drep,
netlogon_dissect_ONE_DOMAIN_INFO);
return offset;
}
static int
netlogon_dissect_LSA_POLICY_INFO(tvbuff_t *tvb _U_, int offset,
packet_info *pinfo _U_, proto_tree *tree _U_,
guint8 *drep _U_ )
{
proto_item *item=NULL;
proto_tree *subtree=NULL;
guint32 len;
dcerpc_info *di;
di=pinfo->private_data;
if(di->conformant_run){
return offset;
}
if(tree){
item = proto_tree_add_text(tree, tvb, offset, 0,
"LSA Policy");
subtree = proto_item_add_subtree(item, ett_LSA_POLICY_INFO);
}
offset = dissect_ndr_uint32(tvb, offset, pinfo, subtree, drep,
hf_netlogon_lsapolicy_len, &len);
offset = dissect_ndr_pointer(tvb, offset, pinfo, subtree, drep,
netlogon_dissect_BLOB_array, NDR_POINTER_UNIQUE,
"Pointer:", -1);
return offset;
}
static int
netlogon_dissect_WORKSTATION_INFO(tvbuff_t *tvb , int offset ,
packet_info *pinfo , proto_tree *tree ,
guint8 *drep )
{
offset = netlogon_dissect_LSA_POLICY_INFO(tvb, offset,
pinfo, tree, drep);
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, drep,
NDR_POINTER_UNIQUE, "Workstation FQDN",
hf_netlogon_workstation_fqdn, 0);
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, drep,
NDR_POINTER_UNIQUE, "Workstation Site",
hf_netlogon_workstation_site_name, 0);
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, drep,
NDR_POINTER_UNIQUE, "Dummy 1", hf_netlogon_dummy_string, 0);
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, drep,
NDR_POINTER_UNIQUE, "Dummy 2", hf_netlogon_dummy_string2, 0);
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, drep,
NDR_POINTER_UNIQUE, "Dummy 3", hf_netlogon_dummy_string3, 0);
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, drep,
NDR_POINTER_UNIQUE, "Dummy 4", hf_netlogon_dummy_string4, 0);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_os_version, 0);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_workstation_os, 0);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_dummy_string3, 0);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_dummy_string4, 0);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_workstation_flags, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_dummy2_long, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_dummy3_long, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_dummy4_long, NULL);
return offset;
}
static int
netlogon_dissect_WORKSTATION_INFORMATION(tvbuff_t *tvb , int offset ,
packet_info *pinfo , proto_tree *tree ,
guint8 *drep ) {
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_WORKSTATION_INFO, NDR_POINTER_UNIQUE,
"WORKSTATION INFO", -1);
return offset;
}
static int
netlogon_dissect_DOMAIN_INFO(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
guint8 *drep)
{
offset = netlogon_dissect_ONE_DOMAIN_INFO(tvb, offset, pinfo, tree, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_num_trusts, NULL);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_DOMAIN_TRUST_INFO, NDR_POINTER_UNIQUE,
"DOMAIN_TRUST_ARRAY: Trusted domains", -1);
offset = netlogon_dissect_LSA_POLICY_INFO(tvb,offset,pinfo, tree,drep);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_ad_client_dns_name, 0);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_dummy_string2, 0);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_dummy_string3, 0);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_dummy_string4, 0);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_workstation_flags, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_supportedenctypes, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_dummy3_long, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_dummy4_long, NULL);
return offset;
}
static int
netlogon_dissect_DOMAIN_INFORMATION(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
guint8 *drep)
{
guint32 level = 0;
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_level, &level);
ALIGN_TO_4_BYTES;
switch(level){
case 1:
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_DOMAIN_INFO, NDR_POINTER_UNIQUE,
"DOMAIN_INFO", -1);
break;
}
return offset;
}
static int
netlogon_dissect_UNICODE_STRING_512(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *parent_tree,
guint8 *drep)
{
proto_item *item=NULL;
proto_tree *tree=NULL;
int old_offset=offset;
int i;
if(parent_tree){
item = proto_tree_add_text(parent_tree, tvb, offset, 0,
"UNICODE_STRING_512:");
tree = proto_item_add_subtree(item, ett_UNICODE_STRING_512);
}
for(i=0;i<512;i++){
offset = dissect_ndr_uint16(tvb, offset, pinfo, tree, drep,
hf_netlogon_unknown_short, NULL);
}
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_unknown_long, NULL);
proto_item_set_len(item, offset-old_offset);
return offset;
}
static int
netlogon_dissect_element_844_byte(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
guint8 *drep)
{
offset = dissect_ndr_uint8(tvb, offset, pinfo, tree, drep,
hf_netlogon_unknown_char, NULL);
return offset;
}
static int
netlogon_dissect_element_844_array(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
guint8 *drep)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, drep,
netlogon_dissect_element_844_byte);
return offset;
}
static int
netlogon_dissect_TYPE_50(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *parent_tree,
guint8 *drep)
{
proto_item *item=NULL;
proto_tree *tree=NULL;
int old_offset=offset;
if(parent_tree){
item = proto_tree_add_text(parent_tree, tvb, offset, 0,
"TYPE_50:");
tree = proto_item_add_subtree(item, ett_TYPE_50);
}
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_unknown_long, NULL);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_element_844_array, NDR_POINTER_UNIQUE,
"unknown", hf_netlogon_unknown_string);
proto_item_set_len(item, offset-old_offset);
return offset;
}
static int
netlogon_dissect_TYPE_50_ptr(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
guint8 *drep)
{
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_TYPE_50, NDR_POINTER_UNIQUE,
"TYPE_50 pointer: unknown_TYPE_50", -1);
return offset;
}
static int
netlogon_dissect_DS_DOMAIN_TRUSTS(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *parent_tree, guint8 *drep)
{
guint32 tmp;
proto_item *item=NULL;
proto_tree *tree=NULL;
int old_offset=offset;
if(parent_tree){
item = proto_tree_add_text(parent_tree, tvb, offset, 0,
"DS_DOMAIN_TRUSTS");
tree = proto_item_add_subtree(item, ett_DS_DOMAIN_TRUSTS);
}
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, drep,
NDR_POINTER_UNIQUE, "NetBIOS Name",
hf_netlogon_downlevel_domain_name, 0);
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, drep,
NDR_POINTER_UNIQUE, "DNS Domain Name",
hf_netlogon_dns_domain_name, 0);
offset = netlogon_dissect_DOMAIN_TRUST_FLAGS(tvb, offset, pinfo, tree, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_trust_parent_index, &tmp);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_trust_type, &tmp);
offset = netlogon_dissect_DOMAIN_TRUST_ATTRIBS(tvb, offset, pinfo, tree, drep);
offset = dissect_ndr_nt_PSID(tvb, offset, pinfo, tree, drep);
offset = dissect_nt_GUID(tvb, offset, pinfo, tree, drep);
proto_item_set_len(item, offset-old_offset);
return offset;
}
static int
netlogon_dissect_DS_DOMAIN_TRUSTS_ARRAY(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
guint8 *drep)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, drep,
netlogon_dissect_DS_DOMAIN_TRUSTS);
return offset;
}
static int
netlogon_dissect_element_865_byte(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
guint8 *drep)
{
offset = dissect_ndr_uint8(tvb, offset, pinfo, tree, drep,
hf_netlogon_unknown_char, NULL);
return offset;
}
static int
netlogon_dissect_element_865_array(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
guint8 *drep)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, drep,
netlogon_dissect_element_865_byte);
return offset;
}
static int
netlogon_dissect_element_866_byte(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
guint8 *drep)
{
offset = dissect_ndr_uint8(tvb, offset, pinfo, tree, drep,
hf_netlogon_unknown_char, NULL);
return offset;
}
static int
netlogon_dissect_element_866_array(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
guint8 *drep)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, drep,
netlogon_dissect_element_866_byte);
return offset;
}
static int
netlogon_dissect_TYPE_52(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *parent_tree,
guint8 *drep)
{
proto_item *item=NULL;
proto_tree *tree=NULL;
int old_offset=offset;
if(parent_tree){
item = proto_tree_add_text(parent_tree, tvb, offset, 0,
"TYPE_52:");
tree = proto_item_add_subtree(item, ett_TYPE_52);
}
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_unknown_long, NULL);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_element_865_array, NDR_POINTER_UNIQUE,
"unknown", hf_netlogon_unknown_string);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_element_866_array, NDR_POINTER_UNIQUE,
"unknown", hf_netlogon_unknown_string);
proto_item_set_len(item, offset-old_offset);
return offset;
}
static int
netlogon_dissect_TYPE_52_ptr(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
guint8 *drep)
{
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_TYPE_52, NDR_POINTER_UNIQUE,
"TYPE_52 pointer: unknown_TYPE_52", -1);
return offset;
}
static int
netlogon_dissect_TYPE_44(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *parent_tree,
guint8 *drep)
{
proto_item *item=NULL;
proto_tree *tree=NULL;
int old_offset=offset;
guint32 level = 0;
if(parent_tree){
item = proto_tree_add_text(parent_tree, tvb, offset, 0,
"TYPE_44:");
tree = proto_item_add_subtree(item, ett_TYPE_44);
}
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_level, &level);
ALIGN_TO_4_BYTES;
switch(level){
case 1:
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_unknown_long, NULL);
break;
}
proto_item_set_len(item, offset-old_offset);
return offset;
}
static int
netlogon_dissect_WORKSTATION_BUFFER(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
guint8 *drep)
{
guint32 level;
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_level, &level);
if (level == 2) {
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_WORKSTATION_INFORMATION, NDR_POINTER_UNIQUE,
"LSA POLICY INFO", -1);
}
else {
if (level == 1) {
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_WORKSTATION_INFORMATION, NDR_POINTER_UNIQUE,
"WORKSTATION INFORMATION", -1);}
}
return offset;
}
static int
netlogon_dissect_netrenumeratetrusteddomains_rqst(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = netlogon_dissect_LOGONSRV_HANDLE(tvb, offset,
pinfo, tree, drep);
return offset;
}
static int
netlogon_dissect_netrenumeratetrusteddomains_reply(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_UNICODE_MULTI, NDR_POINTER_REF,
"UNICODE_MULTI pointer: trust_dom_name_list", -1);
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep,
hf_netlogon_dos_rc, NULL);
return offset;
}
static int
netlogon_dissect_dsrgetdcname_rqst(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = netlogon_dissect_LOGONSRV_HANDLE(tvb, offset,
pinfo, tree, drep);
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, drep,
NDR_POINTER_UNIQUE, "Domain", hf_netlogon_logon_dom, 0);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
dissect_nt_GUID, NDR_POINTER_UNIQUE,
"GUID pointer: domain_guid", -1);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
dissect_nt_GUID, NDR_POINTER_UNIQUE,
"GUID pointer: site_guid", -1);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_flags, NULL);
return offset;
}
static int
netlogon_dissect_dsrgetdcname_reply(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_DOMAIN_CONTROLLER_INFO, NDR_POINTER_UNIQUE,
"DOMAIN_CONTROLLER_INFO:", -1);
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep,
hf_netlogon_dos_rc, NULL);
return offset;
}
static int
netlogon_dissect_netrlogondummyroutine1_rqst(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = netlogon_dissect_LOGONSRV_HANDLE(tvb, offset,
pinfo, tree, drep);
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, drep,
NDR_POINTER_UNIQUE, "unknown string",
hf_netlogon_unknown_string, 0);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_AUTHENTICATOR, NDR_POINTER_REF,
"AUTHENTICATOR: credential", -1);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_AUTHENTICATOR, NDR_POINTER_UNIQUE,
"AUTHENTICATOR: return_authenticator", -1);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_unknown_long, NULL);
return offset;
}
static int
netlogon_dissect_netrlogondummyroutine1_reply(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_AUTHENTICATOR, NDR_POINTER_UNIQUE,
"AUTHENTICATOR: return_authenticator", -1);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_TYPE_44, NDR_POINTER_UNIQUE,
"TYPE_44 pointer: unknown_TYPE_44", -1);
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep,
hf_netlogon_rc, NULL);
return offset;
}
static int
netlogon_dissect_netrlogonsetservicebits_rqst(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = netlogon_dissect_LOGONSRV_HANDLE(tvb, offset,
pinfo, tree, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_unknown_long, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_unknown_long, NULL);
return offset;
}
static int
netlogon_dissect_netrlogonsetservicebits_reply(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep,
hf_netlogon_rc, NULL);
return offset;
}
static int
netlogon_dissect_netrlogongettrustrid_rqst(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = netlogon_dissect_LOGONSRV_HANDLE(tvb, offset,
pinfo, tree, drep);
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, drep,
NDR_POINTER_UNIQUE, "unknown string",
hf_netlogon_unknown_string, 0);
return offset;
}
static int
netlogon_dissect_netrlogongettrustrid_reply(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_pointer_long, NDR_POINTER_UNIQUE,
"ULONG pointer: unknown_ULONG", hf_netlogon_unknown_long);
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep,
hf_netlogon_rc, NULL);
return offset;
}
static int
netlogon_dissect_netrlogoncomputeserverdigest_rqst(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = netlogon_dissect_LOGONSRV_HANDLE(tvb, offset,
pinfo, tree, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_unknown_long, NULL);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_BYTE_array, NDR_POINTER_UNIQUE,
"BYTE pointer: unknown_BYTE", -1);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_unknown_long, NULL);
return offset;
}
static int
netlogon_dissect_BYTE_16_array(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
int i;
for(i=0;i<16;i++){
offset = dissect_ndr_uint8(tvb, offset, pinfo, tree, drep,
hf_netlogon_unknown_char, NULL);
}
return offset;
}
static int
netlogon_dissect_netrlogoncomputeserverdigest_reply(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_BYTE_16_array, NDR_POINTER_UNIQUE,
"BYTE pointer: unknown_BYTE", -1);
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep,
hf_netlogon_rc, NULL);
return offset;
}
static int
netlogon_dissect_netrlogoncomputeclientdigest_rqst(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = netlogon_dissect_LOGONSRV_HANDLE(tvb, offset,
pinfo, tree, drep);
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, drep,
NDR_POINTER_UNIQUE, "unknown string",
hf_netlogon_unknown_string, 0);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_BYTE_array, NDR_POINTER_UNIQUE,
"BYTE pointer: unknown_BYTE", -1);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_unknown_long, NULL);
return offset;
}
static int
netlogon_dissect_netrlogoncomputeclientdigest_reply(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_BYTE_16_array, NDR_POINTER_UNIQUE,
"BYTE pointer: unknown_BYTE", -1);
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep,
hf_netlogon_rc, NULL);
return offset;
}
static int netlogon_dissect_neg_options(tvbuff_t *tvb,proto_tree *tree,guint32 flags,int offset)
{
if (tree) {
proto_tree *negotiate_flags_tree = NULL;
proto_item *tf = NULL;
tf = proto_tree_add_uint (tree,
hf_netlogon_neg_flags,
tvb, offset, 4,flags);
negotiate_flags_tree = proto_item_add_subtree (tf,ett_authenticate_flags);
proto_tree_add_boolean (negotiate_flags_tree,
hf_netlogon_neg_flags_40000000,
tvb, offset, 4, flags);
proto_tree_add_boolean (negotiate_flags_tree,
hf_netlogon_neg_flags_20000000,
tvb, offset, 4, flags);
proto_tree_add_boolean (negotiate_flags_tree,
hf_netlogon_neg_flags_1000000,
tvb, offset, 4, flags);
proto_tree_add_boolean (negotiate_flags_tree,
hf_netlogon_neg_flags_400000,
tvb, offset, 4, flags);
proto_tree_add_boolean (negotiate_flags_tree,
hf_netlogon_neg_flags_200000,
tvb, offset, 4, flags);
proto_tree_add_boolean (negotiate_flags_tree,
hf_netlogon_neg_flags_100000,
tvb, offset, 4, flags);
proto_tree_add_boolean (negotiate_flags_tree,
hf_netlogon_neg_flags_80000,
tvb, offset, 4, flags);
proto_tree_add_boolean (negotiate_flags_tree,
hf_netlogon_neg_flags_40000,
tvb, offset, 4, flags);
proto_tree_add_boolean (negotiate_flags_tree,
hf_netlogon_neg_flags_20000,
tvb, offset, 4, flags);
proto_tree_add_boolean (negotiate_flags_tree,
hf_netlogon_neg_flags_10000,
tvb, offset, 4, flags);
proto_tree_add_boolean (negotiate_flags_tree,
hf_netlogon_neg_flags_8000,
tvb, offset, 4, flags);
proto_tree_add_boolean (negotiate_flags_tree,
hf_netlogon_neg_flags_4000,
tvb, offset, 4, flags);
proto_tree_add_boolean (negotiate_flags_tree,
hf_netlogon_neg_flags_2000,
tvb, offset, 4, flags);
proto_tree_add_boolean (negotiate_flags_tree,
hf_netlogon_neg_flags_1000,
tvb, offset, 4, flags);
proto_tree_add_boolean (negotiate_flags_tree,
hf_netlogon_neg_flags_800,
tvb, offset, 4, flags);
proto_tree_add_boolean (negotiate_flags_tree,
hf_netlogon_neg_flags_400,
tvb, offset, 4, flags);
proto_tree_add_boolean (negotiate_flags_tree,
hf_netlogon_neg_flags_200,
tvb, offset, 4, flags);
proto_tree_add_boolean (negotiate_flags_tree,
hf_netlogon_neg_flags_100,
tvb, offset, 4, flags);
proto_tree_add_boolean (negotiate_flags_tree,
hf_netlogon_neg_flags_80,
tvb, offset, 4, flags);
proto_tree_add_boolean (negotiate_flags_tree,
hf_netlogon_neg_flags_40,
tvb, offset, 4, flags);
proto_tree_add_boolean (negotiate_flags_tree,
hf_netlogon_neg_flags_20,
tvb, offset, 4, flags);
proto_tree_add_boolean (negotiate_flags_tree,
hf_netlogon_neg_flags_10,
tvb, offset, 4, flags);
proto_tree_add_boolean (negotiate_flags_tree,
hf_netlogon_neg_flags_8,
tvb, offset, 4, flags);
proto_tree_add_boolean (negotiate_flags_tree,
hf_netlogon_neg_flags_4,
tvb, offset, 4, flags);
proto_tree_add_boolean (negotiate_flags_tree,
hf_netlogon_neg_flags_2,
tvb, offset, 4, flags);
proto_tree_add_boolean (negotiate_flags_tree,
hf_netlogon_neg_flags_1,
tvb, offset, 4, flags);
}
return 0;
}
static int
netlogon_dissect_netrserverauthenticate3_rqst(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
guint32 flags;
offset = netlogon_dissect_LOGONSRV_HANDLE(tvb, offset,
pinfo, tree, drep);
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, drep,
NDR_POINTER_REF, "Acct Name", hf_netlogon_acct_name, 0);
offset = netlogon_dissect_NETLOGON_SECURE_CHANNEL_TYPE(tvb, offset,
pinfo, tree, drep);
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, drep,
NDR_POINTER_REF, "Computer Name", hf_netlogon_computer_name, 0);
offset = dissect_dcerpc_8bytes(tvb, offset, pinfo, tree, drep,
hf_client_credential, NULL);
#if 0
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_CREDENTIAL, NDR_POINTER_REF,
"Client Challenge", -1);
#endif
#if 0
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_neg_flags, NULL);
#endif
ALIGN_TO_4_BYTES;
flags = tvb_get_letohl (tvb, offset);
netlogon_dissect_neg_options(tvb,tree,flags,offset);
seen.isseen = FALSE;
seen.num = 0;
offset +=4;
return offset;
}
static int
netlogon_dissect_netrserverauthenticate2_rqst(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
return netlogon_dissect_netrserverauthenticate3_rqst(tvb,offset,pinfo,tree,drep);
}
static void str_to_unicode(const char *nt_password, char *nt_password_unicode)
{
size_t password_len = 0;
size_t i;
password_len = strlen(nt_password);
if(nt_password_unicode != NULL)
{
for(i=0;i<(password_len);i++)
{
nt_password_unicode[i*2]=nt_password[i];
nt_password_unicode[i*2+1]=0;
}
nt_password_unicode[2*password_len]='\0';
}
}
static guint32 get_keytab_as_list(md4_pass **p_pass_list,const char* ntlm_pass _U_)
{
#ifdef HAVE_KERBEROS
enc_key_t *ek;
md4_pass* pass_list;
md4_pass ntlm_pass_hash;
int i = 0;
guint32 nb_pass = 0;
char ntlm_pass_unicode[258];
int add_ntlm = 0;
int password_len;
if(!krb_decrypt){
*p_pass_list=NULL;
return 0;
}
read_keytab_file_from_preferences();
memset(ntlm_pass_hash.md4,0,sizeof(md4_pass));
for(ek=enc_key_list;ek;ek=ek->next){
if( ek->keylength == 16 ) {
nb_pass++;
}
}
if (ntlm_pass[0] != '\0' && ( strlen(ntlm_pass) < 129 )) {
nb_pass++;
debugprintf("Password: %s\n",ntlm_pass);
password_len = strlen(ntlm_pass);
str_to_unicode(ntlm_pass,ntlm_pass_unicode);
crypt_md4(ntlm_pass_hash.md4,ntlm_pass_unicode,password_len*2);
printnbyte(ntlm_pass_hash.md4,16,"Hash of the NT pass: ","\n");
add_ntlm = 0;
}
*p_pass_list = (md4_pass *)ep_alloc(nb_pass*sizeof(md4_pass));
pass_list=*p_pass_list;
if(add_ntlm) {
memcpy(pass_list[0].md4,&(ntlm_pass_hash.md4),sizeof(md4_pass));
i++;
}
for(ek=enc_key_list;ek;ek=ek->next){
if( ek->keylength == 16 ) {
memcpy(pass_list[i].md4,ek->keyvalue,16);
i++;
}
}
return nb_pass;
#else
*p_pass_list = NULL;
return 0;
#endif
}
static int
netlogon_dissect_netrserverauthenticate23_reply(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep, int version3)
{
guint32 flags;
netlogon_auth_vars *vars;
netlogon_auth_key key;
guint64 server_cred;
offset = dissect_dcerpc_8bytes(tvb, offset, pinfo, tree, drep,
hf_server_credential, &server_cred);
flags = tvb_get_letohl (tvb, offset);
netlogon_dissect_neg_options(tvb,tree,flags,offset);
offset +=4;
ALIGN_TO_4_BYTES;
if(version3) {
offset = dissect_dcerpc_uint32(tvb, offset, pinfo, tree, drep,
hf_server_rid, NULL);
}
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep,
hf_netlogon_rc, NULL);
generate_hash_key(pinfo, 1 , &key, NULL);
vars = (netlogon_auth_vars *)g_hash_table_lookup(netlogon_auths, &key);
if(vars != NULL) {
debugprintf("Found some vars (ie. server/client challenges), let's see if I can get a session key\n");
debugprintf("Context Id = %d \n", pinfo->dcectxid);
while(vars != NULL && vars->next_start != -1 && vars->next_start < (int) pinfo->fd->num ) {
debugprintf("looping auth reply...\n");
vars = vars->next;
}
if(vars == NULL ) {
debugprintf("Something strange happened while searching for authenticate_reply\n");
}
else {
md4_pass *pass_list=NULL;
guint32 list_size = 0;
guint8 session_key[16];
md4_pass password;
int found = 0;
unsigned int i = 0;
vars->flags = flags;
vars->can_decrypt = FALSE;
list_size = get_keytab_as_list(&pass_list,gbl_nt_password);
debugprintf("Found %d passwords \n",list_size);
if( flags & NETLOGON_FLAG_STRONGKEY ) {
guint8 zeros[4];
guint8 md5[16];
md5_state_t md5state;
guint8 buf[8];
guint64 calculated_cred;
memset(zeros,0,4);
md5_init(&md5state);
md5_append(&md5state,zeros,4);
md5_append(&md5state,(unsigned char*)&vars->client_challenge,8);
md5_append(&md5state,(unsigned char*)&vars->server_challenge,8);
md5_finish(&md5state,md5);
printnbyte(md5,8,"MD5:","\n");
printnbyte((guint8*)&vars->client_challenge,8,"Client challenge:","\n");
printnbyte((guint8*)&vars->server_challenge,8,"Server challenge:","\n");
printnbyte((guint8*)&server_cred,8,"Server creds:","\n");
for(i=0;i<list_size;i++)
{
password = pass_list[i];
md5_hmac(md5,16,(guint8*) &password,16,session_key);
crypt_des_ecb(buf,(unsigned char*)&vars->server_challenge,session_key,1);
crypt_des_ecb((unsigned char*)&calculated_cred,buf,session_key+7,1);
#if 0
printnbyte((guint8*)&calculated_cred,8,"Calculated creds:","\n");
#endif
if(calculated_cred==server_cred) {
found = 1;
break;
}
}
}
else if( flags&NETLOGON_FLAG_USEAES)
{
debugprintf("AES not supported yet\n");
memset(session_key,0,16);
}
else
{
debugprintf("Else case not implemented\n");
memset(session_key,0,16);
}
if(found) {
memcpy(&vars->session_key,session_key,16);
debugprintf("Found the good session key !\n");
}
else {
debugprintf("Session key not found !\n");
memset(&vars->session_key,0,16);
}
}
} else {
printnbyte((guint8*)&vars->session_key, 16, "Session key:","\n");
}
return offset;
}
static int
netlogon_dissect_netrserverauthenticate3_reply(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
return netlogon_dissect_netrserverauthenticate23_reply(tvb,offset,pinfo,tree,drep,1);
}
static int
netlogon_dissect_netrserverauthenticate2_reply(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
return netlogon_dissect_netrserverauthenticate23_reply(tvb,offset,pinfo,tree,drep,0);
}
static int
netlogon_dissect_dsrgetdcnameex_rqst(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = netlogon_dissect_LOGONSRV_HANDLE(tvb, offset,
pinfo, tree, drep);
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, drep,
NDR_POINTER_UNIQUE, "Domain", hf_netlogon_logon_dom, 0);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
dissect_nt_GUID, NDR_POINTER_UNIQUE,
"GUID pointer: domain_guid", -1);
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, drep,
NDR_POINTER_UNIQUE, "Site Name", hf_netlogon_site_name, 0);
offset = netlogon_dissect_GET_DCNAME_REQUEST_FLAGS(tvb, offset, pinfo, tree, drep);
return offset;
}
static int
netlogon_dissect_dsrgetdcnameex_reply(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_DOMAIN_CONTROLLER_INFO, NDR_POINTER_UNIQUE,
"DOMAIN_CONTROLLER_INFO:", -1);
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep,
hf_netlogon_rc, NULL);
return offset;
}
static int
netlogon_dissect_dsrgetsitename_rqst(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = netlogon_dissect_LOGONSRV_HANDLE(tvb, offset,
pinfo, tree, drep);
return offset;
}
static int
netlogon_dissect_dsrgetsitename_reply(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_pointer_cb(tvb, offset, pinfo, tree, drep,
dissect_ndr_wchar_cvstring, NDR_POINTER_UNIQUE, "Site Name",
hf_netlogon_site_name, cb_wstr_postprocess,
GINT_TO_POINTER(CB_STR_COL_INFO | 1));
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep,
hf_netlogon_dos_rc, NULL);
return offset;
}
static int
netlogon_dissect_netrlogongetdomaininfo_rqst(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, drep,
NDR_POINTER_REF, "Server Handle", hf_netlogon_computer_name, 0);
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, drep,
NDR_POINTER_UNIQUE, "Computer Name",
hf_netlogon_computer_name, 0);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_AUTHENTICATOR, NDR_POINTER_REF,
"AUTHENTICATOR: client", -1);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_AUTHENTICATOR, NDR_POINTER_REF,
"AUTHENTICATOR: return_authenticator", -1);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_WORKSTATION_BUFFER, NDR_POINTER_REF,
"WORKSTATION_BUFFER", -1);
return offset;
}
static int
netlogon_dissect_netrlogongetdomaininfo_reply(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_AUTHENTICATOR, NDR_POINTER_REF,
"AUTHENTICATOR: return_authenticator", -1);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_DOMAIN_INFORMATION, NDR_POINTER_REF,
"DOMAIN_INFORMATION", -1);
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep,
hf_netlogon_rc, NULL);
return offset;
}
static int
netlogon_dissect_netrserverpasswordset2_rqst(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = netlogon_dissect_LOGONSRV_HANDLE(tvb, offset,
pinfo, tree, drep);
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, drep,
NDR_POINTER_UNIQUE, "unknown string",
hf_netlogon_unknown_string, 0);
offset = dissect_ndr_uint16(tvb, offset, pinfo, tree, drep,
hf_netlogon_unknown_short, NULL);
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, drep,
NDR_POINTER_UNIQUE, "unknown string",
hf_netlogon_unknown_string, 0);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_AUTHENTICATOR, NDR_POINTER_REF,
"AUTHENTICATOR: credential", -1);
offset = netlogon_dissect_UNICODE_STRING_512(tvb, offset,
pinfo, tree, drep);
return offset;
}
static int
netlogon_dissect_netrserverpasswordset2_reply(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_AUTHENTICATOR, NDR_POINTER_UNIQUE,
"AUTHENTICATOR: return_authenticator", -1);
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep,
hf_netlogon_rc, NULL);
return offset;
}
static int
netlogon_dissect_netrserverpasswordget_rqst(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = netlogon_dissect_LOGONSRV_HANDLE(tvb, offset,
pinfo, tree, drep);
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, drep,
NDR_POINTER_UNIQUE, "Acct Name", hf_netlogon_acct_name, 0);
offset = netlogon_dissect_NETLOGON_SECURE_CHANNEL_TYPE(tvb, offset,
pinfo, tree, drep);
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, drep,
NDR_POINTER_UNIQUE, "Computer Name",
hf_netlogon_computer_name, 0);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_AUTHENTICATOR, NDR_POINTER_REF,
"AUTHENTICATOR: credential", -1);
return offset;
}
static int
netlogon_dissect_netrserverpasswordget_reply(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_AUTHENTICATOR, NDR_POINTER_REF,
"AUTHENTICATOR: return_authenticator", -1);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_LM_OWF_PASSWORD, NDR_POINTER_REF,
"LM_OWF_PASSWORD pointer: server_pwd", -1);
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep,
hf_netlogon_rc, NULL);
return offset;
}
static int
netlogon_dissect_netrlogonsendtosam_rqst(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = netlogon_dissect_LOGONSRV_HANDLE(tvb, offset,
pinfo, tree, drep);
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, drep,
NDR_POINTER_UNIQUE, "unknown string",
hf_netlogon_unknown_string, 0);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_AUTHENTICATOR, NDR_POINTER_REF,
"AUTHENTICATOR: credential", -1);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_BYTE_array, NDR_POINTER_UNIQUE,
"BYTE pointer: unknown_BYTE", -1);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_unknown_long, NULL);
return offset;
}
static int
netlogon_dissect_netrlogonsendtosam_reply(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_AUTHENTICATOR, NDR_POINTER_UNIQUE,
"AUTHENTICATOR: return_authenticator", -1);
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep,
hf_netlogon_rc, NULL);
return offset;
}
static int
netlogon_dissect_dsraddresstositenamesw_rqst(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = netlogon_dissect_LOGONSRV_HANDLE(tvb, offset,
pinfo, tree, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_unknown_long, NULL);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_BYTE_array, NDR_POINTER_UNIQUE,
"BYTE pointer: unknown_BYTE", -1);
return offset;
}
static int
netlogon_dissect_dsraddresstositenamesw_reply(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_TYPE_50_ptr, NDR_POINTER_UNIQUE,
"TYPE_50** pointer: unknown_TYPE_50", -1);
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep,
hf_netlogon_rc, NULL);
return offset;
}
static int
netlogon_dissect_dsrgetdcnameex2_rqst(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = netlogon_dissect_LOGONSRV_HANDLE(tvb, offset,
pinfo, tree, drep);
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, drep,
NDR_POINTER_UNIQUE, "Client Account",
hf_netlogon_acct_name, 0);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_unknown_long, NULL);
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, drep,
NDR_POINTER_UNIQUE, "Client Account",
hf_netlogon_logon_dom, 0);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
dissect_nt_GUID, NDR_POINTER_UNIQUE,
"Domain GUID:", -1);
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, drep,
NDR_POINTER_UNIQUE, "Client Site",
hf_netlogon_site_name, 0);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_unknown_long, NULL);
return offset;
}
static int
netlogon_dissect_dsrgetdcnameex2_reply(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_DOMAIN_CONTROLLER_INFO, NDR_POINTER_UNIQUE,
"DOMAIN_CONTROLLER_INFO:", -1);
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep,
hf_netlogon_dos_rc, NULL);
return offset;
}
static int
netlogon_dissect_netrlogongettimeserviceparentdomain_rqst(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = netlogon_dissect_LOGONSRV_HANDLE(tvb, offset,
pinfo, tree, drep);
return offset;
}
static int
netlogon_dissect_netrlogongettimeserviceparentdomain_reply(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, drep,
NDR_POINTER_UNIQUE, "unknown string",
hf_netlogon_unknown_string, 0);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_pointer_long, NDR_POINTER_UNIQUE,
"ULONG pointer: unknown_ULONG", hf_netlogon_unknown_long);
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep,
hf_netlogon_rc, NULL);
return offset;
}
static int
netlogon_dissect_netrenumeratetrusteddomainsex_rqst(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = netlogon_dissect_LOGONSRV_HANDLE(tvb, offset,
pinfo, tree, drep);
return offset;
}
static int
netlogon_dissect_netrenumeratetrusteddomainsex_reply(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_entries, NULL);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_DS_DOMAIN_TRUSTS_ARRAY, NDR_POINTER_UNIQUE,
"DS_DOMAIN_TRUSTS_ARRAY:", -1);
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep,
hf_netlogon_rc, NULL);
return offset;
}
static int
netlogon_dissect_dsraddresstositenamesexw_rqst(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = netlogon_dissect_LOGONSRV_HANDLE(tvb, offset,
pinfo, tree, drep);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_unknown_long, NULL);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_BYTE_array, NDR_POINTER_UNIQUE,
"BYTE pointer: unknown_BYTE", -1);
return offset;
}
static int
netlogon_dissect_dsraddresstositenamesexw_reply(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_TYPE_52_ptr, NDR_POINTER_UNIQUE,
"TYPE_52 pointer: unknown_TYPE_52", -1);
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep,
hf_netlogon_rc, NULL);
return offset;
}
static int
netlogon_dissect_site_name_item(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_counted_string_cb(
tvb, offset, pinfo, tree, drep, hf_netlogon_site_name,
cb_wstr_postprocess,
GINT_TO_POINTER(CB_STR_COL_INFO | 1));
return offset;
}
static int
netlogon_dissect_site_name_array(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_ucarray(tvb, offset, pinfo, tree, drep,
netlogon_dissect_site_name_item);
return offset;
}
static int
netlogon_dissect_site_names(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_count, NULL);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_site_name_array, NDR_POINTER_UNIQUE,
"Site name array", -1);
return offset;
}
static int
netlogon_dissect_dsrgetdcsitecoveragew_rqst(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = netlogon_dissect_LOGONSRV_HANDLE(tvb, offset,
pinfo, tree, drep);
return offset;
}
static int
netlogon_dissect_dsrgetdcsitecoveragew_reply(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_site_names, NDR_POINTER_UNIQUE,
"Site names", -1);
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep,
hf_netlogon_rc, NULL);
return offset;
}
static int
netlogon_dissect_netrlogonsamlogonex_rqst(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, drep,
NDR_POINTER_UNIQUE, "LogonServer",
hf_netlogon_computer_name, 0);
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, drep,
NDR_POINTER_UNIQUE, "Computer Name",
hf_netlogon_computer_name, 0);
offset = dissect_ndr_uint16(tvb, offset, pinfo, tree, drep,
hf_netlogon_level16, NULL);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_LEVEL, NDR_POINTER_REF,
"LEVEL: LogonLevel", -1);
offset = dissect_ndr_uint16(tvb, offset, pinfo, tree, drep,
hf_netlogon_validation_level, NULL);
offset = netlogon_dissect_EXTRA_FLAGS(tvb, offset, pinfo, tree, drep);
#if 0
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, drep,
NDR_POINTER_UNIQUE, "unknown string",
hf_netlogon_unknown_string, 0);
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, drep,
NDR_POINTER_UNIQUE, "unknown string",
hf_netlogon_unknown_string, 0);
offset = dissect_ndr_uint16(tvb, offset, pinfo, tree, drep,
hf_netlogon_unknown_short, NULL);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_LEVEL, NDR_POINTER_UNIQUE,
"LEVEL pointer: unknown_NETLOGON_LEVEL", -1);
offset = dissect_ndr_uint16(tvb, offset, pinfo, tree, drep,
hf_netlogon_unknown_short, NULL);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_pointer_long, NDR_POINTER_UNIQUE,
"ULONG pointer: unknown_ULONG", hf_netlogon_unknown_long);
#endif
return offset;
}
static int
netlogon_dissect_netrlogonsamlogonex_reply(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_VALIDATION, NDR_POINTER_REF,
"VALIDATION:", -1);
offset = dissect_ndr_uint8(tvb, offset, pinfo, tree, drep,
hf_netlogon_authoritative, NULL);
offset = netlogon_dissect_EXTRA_FLAGS(tvb, offset, pinfo, tree, drep);
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep,
hf_netlogon_rc, NULL);
#if 0
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_VALIDATION, NDR_POINTER_UNIQUE,
"VALIDATION: unknown_NETLOGON_VALIDATION", -1);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_pointer_char, NDR_POINTER_UNIQUE,
"BOOLEAN pointer: unknown_BOOLEAN", hf_netlogon_unknown_char);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_pointer_long, NDR_POINTER_UNIQUE,
"ULONG pointer: unknown_ULONG", hf_netlogon_unknown_long);
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep,
hf_netlogon_rc, NULL);
#endif
return offset;
}
static int
netlogon_dissect_dsrenumeratedomaintrusts_rqst(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = netlogon_dissect_LOGONSRV_HANDLE(tvb, offset,
pinfo, tree, drep);
offset = netlogon_dissect_DOMAIN_TRUST_FLAGS(tvb, offset, pinfo, tree, drep);
return offset;
}
static int
netlogon_dissect_dsrenumeratedomaintrusts_reply(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_entries, NULL);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_DS_DOMAIN_TRUSTS_ARRAY, NDR_POINTER_UNIQUE,
"DS_DOMAIN_TRUSTS_ARRAY:", -1);
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep,
hf_netlogon_dos_rc, NULL);
return offset;
}
static int
netlogon_dissect_dsrderegisterdnshostrecords_rqst(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = netlogon_dissect_LOGONSRV_HANDLE(tvb, offset,
pinfo, tree, drep);
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, drep,
NDR_POINTER_UNIQUE, "Domain", hf_netlogon_logon_dom, 0);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
dissect_nt_GUID, NDR_POINTER_UNIQUE,
"GUID pointer: domain_guid", -1);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
dissect_nt_GUID, NDR_POINTER_UNIQUE,
"GUID pointer: dsa_guid", -1);
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, drep,
NDR_POINTER_REF, "dns_host", hf_netlogon_dns_host, 0);
return offset;
}
static int
netlogon_dissect_dsrderegisterdnshostrecords_reply(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep,
hf_netlogon_rc, NULL);
return offset;
}
static int dissect_secchan_nl_auth_message(tvbuff_t *tvb, int offset,
packet_info *pinfo,
proto_tree *tree, guint8 *drep)
{
proto_item *item = NULL;
proto_tree *subtree = NULL;
guint32 messagetype, messageflags;
static const int *flag_fields[] = {
&hf_netlogon_secchan_nl_message_flags_nb_domain,
&hf_netlogon_secchan_nl_message_flags_nb_host,
&hf_netlogon_secchan_nl_message_flags_dns_domain,
&hf_netlogon_secchan_nl_message_flags_dns_host,
&hf_netlogon_secchan_nl_message_flags_nb_host_utf8,
NULL
};
int len;
if (tree) {
item = proto_tree_add_text(
tree, tvb, offset, -1,
"Secure Channel NL_AUTH_MESSAGE");
subtree = proto_item_add_subtree(
item, ett_secchan_nl_auth_message);
}
offset = dissect_dcerpc_uint32(
tvb, offset, pinfo, subtree, drep,
hf_netlogon_secchan_nl_message_type, &messagetype);
proto_tree_add_bitmask(subtree, tvb, offset, hf_netlogon_secchan_nl_message_flags, ett_secchan_nl_auth_message_flags, flag_fields, (drep[0] & DREP_LITTLE_ENDIAN));
messageflags = ((drep[0] & DREP_LITTLE_ENDIAN)
? tvb_get_letohl (tvb, offset)
: tvb_get_ntohl (tvb, offset));
offset += 4;
if (messageflags&0x00000001) {
len = tvb_strsize(tvb, offset);
proto_tree_add_item(subtree, hf_netlogon_secchan_nl_nb_domain, tvb, offset, len, ENC_ASCII|ENC_NA);
offset += len;
}
if (messageflags&0x00000002) {
len = tvb_strsize(tvb, offset);
proto_tree_add_item(subtree, hf_netlogon_secchan_nl_nb_host, tvb, offset, len, ENC_ASCII|ENC_NA);
offset += len;
}
if (messageflags&0x00000004) {
int old_offset=offset;
char str[256];
offset=dissect_mscldap_string(tvb, offset, str, 255, FALSE);
proto_tree_add_string(subtree, hf_netlogon_secchan_nl_dns_domain, tvb, old_offset, offset-old_offset, str);
}
if (messageflags&0x00000008) {
int old_offset=offset;
char str[256];
offset=dissect_mscldap_string(tvb, offset, str, 255, FALSE);
proto_tree_add_string(subtree, hf_netlogon_secchan_nl_dns_host, tvb, old_offset, offset-old_offset, str);
}
if (messageflags&0x00000010) {
int old_offset=offset;
char str[256];
offset=dissect_mscldap_string(tvb, offset, str, 255, FALSE);
proto_tree_add_string(subtree, hf_netlogon_secchan_nl_nb_host_utf8, tvb, old_offset, offset-old_offset, str);
}
return offset;
}
static int get_seal_key(const guint8 *session_key,int key_len,guint64 sequence,guint8* seal_key)
{
guint8 zeros[4];
guint8 *buf = (guint8 *)g_malloc(key_len);
guint8 buf2[16];
guint8 zero_sk[16];
int i = 0;
memset(zero_sk,0,16);
memset(seal_key,0,16);
if(memcmp(session_key,zero_sk,16)) {
memset(zeros,0,4);
for(i=0;i<key_len;i++) {
buf[i] = session_key[i] ^ 0xF0;
}
md5_hmac(zeros,4,buf,key_len,buf2);
md5_hmac((guint8*)&sequence,8,buf2,16,seal_key);
g_free(buf);
return 1;
}
else {
g_free(buf);
return 0;
}
}
static guint64 uncrypt_sequence(guint8* session_key,guint64 checksum,guint64 enc_seq,unsigned char is_server _U_)
{
guint8 zeros[4];
guint8 buf[16];
guint8 key[16];
rc4_state_struct rc4state;
guint8 *p_seq = (guint8*) &enc_seq;
memset(zeros,0,4);
md5_hmac(zeros,4,session_key,16,buf);
md5_hmac((guint8*)&checksum,8,buf,16,key);
crypt_rc4_init(&rc4state,key,16);
crypt_rc4(&rc4state,p_seq,8);
return enc_seq;
}
static tvbuff_t *
dissect_packet_data(tvbuff_t *tvb ,tvbuff_t *auth_tvb _U_,
int offset , packet_info *pinfo ,dcerpc_auth_info *auth_info _U_,unsigned char is_server)
{
tvbuff_t *buf = NULL;
guint8* decrypted;
netlogon_auth_vars *vars;
netlogon_auth_key key;
generate_hash_key(pinfo,is_server,&key,NULL);
vars = (netlogon_auth_vars *)g_hash_table_lookup(netlogon_auths, &key);
if(vars != NULL ) {
while(vars != NULL && vars->next_start != -1 && vars->next_start < (int) pinfo->fd->num ) {
vars = vars->next;
}
if(vars == NULL ) {
debugprintf("Vars not found %d (packet_data)\n",g_hash_table_size(netlogon_auths));
return(buf);
}
else {
if(vars->can_decrypt == TRUE) {
rc4_state_struct rc4state;
int data_len;
guint64 copyconfounder = vars->confounder;
data_len = tvb_length_remaining(tvb,offset);
if (data_len < 0) {
return NULL;
}
crypt_rc4_init(&rc4state,vars->encryption_key,16);
crypt_rc4(&rc4state,(guint8*)&copyconfounder,8);
decrypted = (guint8*)ep_tvb_memdup(tvb, offset,data_len);
crypt_rc4_init(&rc4state,vars->encryption_key,16);
crypt_rc4(&rc4state,decrypted,data_len);
buf = tvb_new_child_real_data(tvb, decrypted, data_len, data_len);
}
else {
debugprintf("Session key not found can't decrypt ...\n");
}
}
} else {
debugprintf("Vars not found %d (packet_data)\n",g_hash_table_size(netlogon_auths));
return(buf);
}
return(buf);
}
static tvbuff_t* dissect_request_data( tvbuff_t *tvb ,tvbuff_t *auth_tvb ,
int offset , packet_info *pinfo ,dcerpc_auth_info *auth_info )
{
return dissect_packet_data(tvb,auth_tvb,offset,pinfo,auth_info,0);
}
static tvbuff_t* dissect_response_data( tvbuff_t *tvb ,tvbuff_t *auth_tvb ,
int offset , packet_info *pinfo ,dcerpc_auth_info *auth_info )
{
return dissect_packet_data(tvb,auth_tvb,offset,pinfo,auth_info,1);
}
static int
dissect_secchan_verf(tvbuff_t *tvb, int offset, packet_info *pinfo _U_,
proto_tree *tree, guint8 *drep _U_, unsigned char is_server)
{
netlogon_auth_vars *vars;
netlogon_auth_key key;
proto_item *vf = NULL;
proto_tree *subtree = NULL;
guint64 encrypted_seq;
guint64 digest;
guint64 confounder = 0;
int update_vars = 0;
generate_hash_key(pinfo,is_server,&key,NULL);
vars = (netlogon_auth_vars *)g_hash_table_lookup(netlogon_auths,(gconstpointer*) &key);
if( ! (seen.isseen && seen.num == pinfo->fd->num) ) {
vf = proto_tree_add_item(tree, hf_netlogon_secchan_verf, tvb,
offset, -1, ENC_NA);
subtree = proto_item_add_subtree(vf, ett_secchan_verf);
proto_tree_add_item(subtree, hf_netlogon_secchan_verf_signalg, tvb,
offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(subtree, hf_netlogon_secchan_verf_sealalg, tvb,
offset+2, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(subtree, hf_netlogon_secchan_verf_flag, tvb,
offset+6, 2, ENC_NA);
offset += 8;
offset = dissect_dcerpc_8bytes(tvb, offset, pinfo, subtree, drep,
hf_netlogon_secchan_verf_seq, &encrypted_seq);
offset = dissect_dcerpc_8bytes(tvb, offset, pinfo, subtree, drep,
hf_netlogon_secchan_verf_digest, &digest);
if (tvb_bytes_exist(tvb, offset, 8)) {
offset = dissect_dcerpc_8bytes(tvb, offset, pinfo, subtree, drep,
hf_netlogon_secchan_verf_nonce, &confounder);
}
update_vars = 1;
}
if( vars != NULL ) {
while(vars != NULL && vars->next_start != -1 && vars->next_start < (int)pinfo->fd->num ) {
vars = vars->next;
}
if(vars == NULL ) {
debugprintf("Vars not found %d (packet_data)\n",g_hash_table_size(netlogon_auths));
return(offset);
}
else {
if(update_vars) {
vars->confounder = confounder;
vars->seq = uncrypt_sequence(vars->session_key,digest,encrypted_seq,is_server);
}
if(get_seal_key(vars->session_key,16,vars->seq,vars->encryption_key))
{
vars->can_decrypt = TRUE;
}
else
{
debugprintf("get seal key returned 0\n");
}
}
}
else
{
debugprintf("Vars not found (is null %d) %d (dissect_verf)\n",vars==NULL,g_hash_table_size(netlogon_auths));
}
seen.isseen = TRUE;
seen.num = pinfo->fd->num;
return offset;
}
static int
dissect_request_secchan_verf(tvbuff_t *tvb, int offset, packet_info *pinfo ,
proto_tree *tree, guint8 *drep )
{
return dissect_secchan_verf(tvb,offset,pinfo,tree,drep,0);
}
static int
dissect_response_secchan_verf(tvbuff_t *tvb, int offset, packet_info *pinfo ,
proto_tree *tree, guint8 *drep )
{
return dissect_secchan_verf(tvb,offset,pinfo,tree,drep,1);
}
static void
netlogon_reassemble_init(void)
{
if (netlogon_auths){
g_hash_table_destroy (netlogon_auths);
}
netlogon_auths = g_hash_table_new (netlogon_auth_hash, netlogon_auth_equal);
if (schannel_auths){
g_hash_table_destroy (schannel_auths);
}
schannel_auths = g_hash_table_new (netlogon_auth_hash, netlogon_auth_equal);
}
void
proto_register_dcerpc_netlogon(void)
{
static hf_register_info hf[] = {
{ &hf_netlogon_opnum,
{ "Operation", "netlogon.opnum", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_netlogon_rc, {
"Return code", "netlogon.rc", FT_UINT32, BASE_HEX,
VALS(NT_errors), 0x0, "Netlogon return code", HFILL }},
{ &hf_netlogon_dos_rc,
{ "DOS error code", "netlogon.dos.rc", FT_UINT32,
BASE_HEX, VALS(DOS_errors), 0x0, NULL, HFILL}},
{ &hf_netlogon_werr_rc,
{ "WERR error code", "netlogon.werr.rc", FT_UINT32,
BASE_HEX, VALS(WERR_errors), 0x0, NULL, HFILL}},
{ &hf_netlogon_param_ctrl, {
"Param Ctrl", "netlogon.param_ctrl", FT_UINT32, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_netlogon_logon_id, {
"Logon ID", "netlogon.logon_id", FT_UINT64, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_netlogon_modify_count, {
"Modify Count", "netlogon.modify_count", FT_UINT64, BASE_DEC,
NULL, 0x0, "How many times the object has been modified", HFILL }},
{ &hf_netlogon_security_information, {
"Security Information", "netlogon.security_information", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_netlogon_count, {
"Count", "netlogon.count", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_netlogon_entries, {
"Entries", "netlogon.entries", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_netlogon_credential, {
"Credential", "netlogon.credential", FT_BYTES, BASE_NONE,
NULL, 0x0, "Netlogon Credential", HFILL }},
{ &hf_netlogon_challenge, {
"Challenge", "netlogon.challenge", FT_BYTES, BASE_NONE,
NULL, 0x0, "Netlogon challenge", HFILL }},
{ &hf_netlogon_lm_owf_password, {
"LM Pwd", "netlogon.lm_owf_pwd", FT_BYTES, BASE_NONE,
NULL, 0x0, "LanManager OWF Password", HFILL }},
{ &hf_netlogon_user_session_key, {
"User Session Key", "netlogon.user_session_key", FT_BYTES, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_netlogon_encrypted_lm_owf_password, {
"Encrypted LM Pwd", "netlogon.lm_owf_pwd.encrypted", FT_BYTES, BASE_NONE,
NULL, 0x0, "Encrypted LanManager OWF Password", HFILL }},
{ &hf_netlogon_nt_owf_password, {
"NT Pwd", "netlogon.nt_owf_pwd", FT_BYTES, BASE_NONE,
NULL, 0x0, "NT OWF Password", HFILL }},
{ &hf_netlogon_blob, {
"BLOB", "netlogon.blob", FT_BYTES, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_netlogon_len, {
"Len", "netlogon.len", FT_UINT32, BASE_DEC,
NULL, 0, "Length", HFILL }},
{ &hf_netlogon_priv, {
"Priv", "netlogon.priv", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_netlogon_privilege_entries, {
"Privilege Entries", "netlogon.privilege_entries", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_netlogon_privilege_control, {
"Privilege Control", "netlogon.privilege_control", FT_UINT32, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_netlogon_privilege_name, {
"Privilege Name", "netlogon.privilege_name", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_netlogon_pdc_connection_status, {
"PDC Connection Status", "netlogon.pdc_connection_status", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_netlogon_tc_connection_status, {
"TC Connection Status", "netlogon.tc_connection_status", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_netlogon_attrs, {
"Attributes", "netlogon.attrs", FT_UINT32, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_netlogon_lsapolicy_referentid,
{ "Referent ID", "netlogon.lsapolicy.referentID", FT_UINT32, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_netlogon_lsapolicy_len,
{ "Length", "netlogon.lsapolicy.length", FT_UINT32, BASE_DEC,
NULL, 0x0, "Length of the policy buffer", HFILL }},
{ &hf_netlogon_lsapolicy_pointer,
{ "Pointer", "netlogon.lsapolicy.pointer", FT_BYTES, BASE_NONE,
NULL, 0x0, "Pointer to LSA POLICY", HFILL }},
{ &hf_netlogon_unknown_string,
{ "Unknown string", "netlogon.unknown_string", FT_STRING, BASE_NONE,
NULL, 0, "Unknown string. If you know what this is, contact wireshark developers.", HFILL }},
{ &hf_netlogon_TrustedDomainName_string,
{ "TrustedDomainName", "netlogon.TrustedDomainName", FT_STRING, BASE_NONE,
NULL, 0, "TrustedDomainName string.", HFILL }},
{ &hf_netlogon_UserName_string,
{ "UserName", "netlogon.UserName", FT_STRING, BASE_NONE,
NULL, 0, "UserName string.", HFILL }},
{ &hf_netlogon_dummy_string,
{ "Dummy String", "netlogon.dummy_string", FT_STRING, BASE_NONE,
NULL, 0, "Dummy String. Used is reserved for next evolutions.", HFILL }},
{ &hf_netlogon_trust_extention,
{ "Trust extension", "netlogon.trust.extention", FT_STRING, BASE_NONE,
NULL, 0, "Trusts extension.", HFILL }},
{ &hf_netlogon_trust_offset,
{ "Offset", "netlogon.trust.extention_offset", FT_UINT32, BASE_DEC,
NULL, 0, "Trusts extension.", HFILL }},
{ &hf_netlogon_trust_len,
{ "Length", "netlogon.trust.extention_length", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_netlogon_trust_max,
{ "Max Count", "netlogon.trust.extention.maxcount", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_netlogon_dummy_string2,
{ "Dummy String2", "netlogon.dummy_string", FT_STRING, BASE_NONE,
NULL, 0, "Dummy String 2. Used is reserved for next evolutions.", HFILL }},
{ &hf_netlogon_dummy_string3,
{ "Dummy String3", "netlogon.dummy_string", FT_STRING, BASE_NONE,
NULL, 0, "Dummy String 3. Used is reserved for next evolutions.", HFILL }},
{ &hf_netlogon_dummy_string4,
{ "Dummy String4", "netlogon.dummy_string", FT_STRING, BASE_NONE,
NULL, 0, "Dummy String 4. Used is reserved for next evolutions.", HFILL }},
{ &hf_netlogon_dummy_string5,
{ "Dummy String5", "netlogon.dummy_string", FT_STRING, BASE_NONE,
NULL, 0, "Dummy String 5. Used is reserved for next evolutions.", HFILL }},
{ &hf_netlogon_dummy_string6,
{ "Dummy String6", "netlogon.dummy_string", FT_STRING, BASE_NONE,
NULL, 0, "Dummy String 6. Used is reserved for next evolutions.", HFILL }},
{ &hf_netlogon_dummy_string7,
{ "Dummy String7", "netlogon.dummy_string", FT_STRING, BASE_NONE,
NULL, 0, "Dummy String 7. Used is reserved for next evolutions.", HFILL }},
{ &hf_netlogon_dummy_string8,
{ "Dummy String8", "netlogon.dummy_string", FT_STRING, BASE_NONE,
NULL, 0, "Dummy String 8. Used is reserved for next evolutions.", HFILL }},
{ &hf_netlogon_dummy_string9,
{ "Dummy String9", "netlogon.dummy_string", FT_STRING, BASE_NONE,
NULL, 0, "Dummy String 9. Used is reserved for next evolutions.", HFILL }},
{ &hf_netlogon_dummy_string10,
{ "Dummy String10", "netlogon.dummy_string", FT_STRING, BASE_NONE,
NULL, 0, "Dummy String 10. Used is reserved for next evolutions.", HFILL }},
{ &hf_netlogon_unknown_long,
{ "Unknown long", "netlogon.unknown.long", FT_UINT32, BASE_HEX,
NULL, 0x0, "Unknown long. If you know what this is, contact wireshark developers.", HFILL }},
{ &hf_netlogon_dummy1_long,
{ "Dummy1 Long", "netlogon.dummy.long1", FT_UINT32, BASE_HEX,
NULL, 0x0, "Dummy long 1. Used is reserved for next evolutions.", HFILL }},
{ &hf_netlogon_dummy2_long,
{ "Dummy2 Long", "netlogon.dummy.long2", FT_UINT32, BASE_HEX,
NULL, 0x0, "Dummy long 2. Used is reserved for next evolutions.", HFILL }},
{ &hf_netlogon_dummy3_long,
{ "Dummy3 Long", "netlogon.dummy.long3", FT_UINT32, BASE_HEX,
NULL, 0x0, "Dummy long 3. Used is reserved for next evolutions.", HFILL }},
{ &hf_netlogon_dummy4_long,
{ "Dummy4 Long", "netlogon.dummy.long4", FT_UINT32, BASE_HEX,
NULL, 0x0, "Dummy long 4. Used is reserved for next evolutions.", HFILL }},
{ &hf_netlogon_dummy5_long,
{ "Dummy5 Long", "netlogon.dummy.long5", FT_UINT32, BASE_HEX,
NULL, 0x0, "Dummy long 5. Used is reserved for next evolutions.", HFILL }},
{ &hf_netlogon_dummy6_long,
{ "Dummy6 Long", "netlogon.dummy.long6", FT_UINT32, BASE_HEX,
NULL, 0x0, "Dummy long 6. Used is reserved for next evolutions.", HFILL }},
{ &hf_netlogon_dummy7_long,
{ "Dummy7 Long", "netlogon.dummy.long7", FT_UINT32, BASE_HEX,
NULL, 0x0, "Dummy long 7. Used is reserved for next evolutions.", HFILL }},
{ &hf_netlogon_dummy8_long,
{ "Dummy8 Long", "netlogon.dummy.long8", FT_UINT32, BASE_HEX,
NULL, 0x0, "Dummy long 8. Used is reserved for next evolutions.", HFILL }},
{ &hf_netlogon_dummy9_long,
{ "Dummy9 Long", "netlogon.dummy.long9", FT_UINT32, BASE_HEX,
NULL, 0x0, "Dummy long 9. Used is reserved for next evolutions.", HFILL }},
{ &hf_netlogon_dummy10_long,
{ "Dummy10 Long", "netlogon.dummy.long10", FT_UINT32, BASE_HEX,
NULL, 0x0, "Dummy long 10. Used is reserved for next evolutions.", HFILL }},
{ &hf_netlogon_supportedenctypes,
{ "Supported Encryption Types", "netlogon.encryption.types", FT_UINT32, BASE_HEX,
NULL, 0x0, "Encryption types", HFILL }},
{ &hf_netlogon_workstation_flags,
{ "Workstation Flags", "netlogon.workstation.flags", FT_UINT32, BASE_HEX,
NULL, 0x0, "Flags", HFILL }},
{ &hf_netlogon_reserved,
{ "Reserved", "netlogon.reserved", FT_UINT32, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_netlogon_unknown_short,
{ "Unknown short", "netlogon.unknown.short", FT_UINT16, BASE_HEX,
NULL, 0x0, "Unknown short. If you know what this is, contact wireshark developers.", HFILL }},
{ &hf_netlogon_unknown_char,
{ "Unknown char", "netlogon.unknown.char", FT_UINT8, BASE_HEX,
NULL, 0x0, "Unknown char. If you know what this is, contact wireshark developers.", HFILL }},
{ &hf_netlogon_acct_expiry_time,
{ "Acct Expiry Time", "netlogon.acct.expiry_time", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL,
NULL, 0x0, "When this account will expire", HFILL }},
{ &hf_netlogon_nt_pwd_present,
{ "NT PWD Present", "netlogon.nt_pwd_present", FT_UINT8, BASE_HEX,
NULL, 0x0, "Is NT password present for this account?", HFILL }},
{ &hf_netlogon_lm_pwd_present,
{ "LM PWD Present", "netlogon.lm_pwd_present", FT_UINT8, BASE_HEX,
NULL, 0x0, "Is LanManager password present for this account?", HFILL }},
{ &hf_netlogon_pwd_expired,
{ "PWD Expired", "netlogon.pwd_expired", FT_UINT8, BASE_HEX,
NULL, 0x0, "Whether this password has expired or not", HFILL }},
{ &hf_netlogon_authoritative,
{ "Authoritative", "netlogon.authoritative", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_netlogon_sensitive_data_flag,
{ "Sensitive Data", "netlogon.sensitive_data_flag", FT_UINT8, BASE_DEC,
NULL, 0x0, "Sensitive data flag", HFILL }},
{ &hf_netlogon_auditing_mode,
{ "Auditing Mode", "netlogon.auditing_mode", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_netlogon_max_audit_event_count,
{ "Max Audit Event Count", "netlogon.max_audit_event_count", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_netlogon_event_audit_option,
{ "Event Audit Option", "netlogon.event_audit_option", FT_UINT32, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_netlogon_sensitive_data_len,
{ "Length", "netlogon.sensitive_data_len", FT_UINT32, BASE_DEC,
NULL, 0x0, "Length of sensitive data", HFILL }},
{ &hf_netlogon_nt_chal_resp,
{ "NT Chal resp", "netlogon.nt_chal_resp", FT_BYTES, BASE_NONE,
NULL, 0, "Challenge response for NT authentication", HFILL }},
{ &hf_netlogon_lm_chal_resp,
{ "LM Chal resp", "netlogon.lm_chal_resp", FT_BYTES, BASE_NONE,
NULL, 0, "Challenge response for LM authentication", HFILL }},
{ &hf_netlogon_cipher_len,
{ "Cipher Len", "netlogon.cipher_len", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_netlogon_cipher_maxlen,
{ "Cipher Max Len", "netlogon.cipher_maxlen", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_netlogon_pac_data,
{ "Pac Data", "netlogon.pac.data", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_netlogon_sensitive_data,
{ "Data", "netlogon.sensitive_data", FT_BYTES, BASE_NONE,
NULL, 0, "Sensitive Data", HFILL }},
{ &hf_netlogon_auth_data,
{ "Auth Data", "netlogon.auth.data", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_netlogon_cipher_current_data,
{ "Cipher Current Data", "netlogon.cipher_current_data", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_netlogon_cipher_old_data,
{ "Cipher Old Data", "netlogon.cipher_old_data", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_netlogon_acct_name,
{ "Acct Name", "netlogon.acct_name", FT_STRING, BASE_NONE,
NULL, 0, "Account Name", HFILL }},
{ &hf_netlogon_acct_desc,
{ "Acct Desc", "netlogon.acct_desc", FT_STRING, BASE_NONE,
NULL, 0, "Account Description", HFILL }},
{ &hf_netlogon_group_desc,
{ "Group Desc", "netlogon.group_desc", FT_STRING, BASE_NONE,
NULL, 0, "Group Description", HFILL }},
{ &hf_netlogon_full_name,
{ "Full Name", "netlogon.full_name", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_netlogon_comment,
{ "Comment", "netlogon.comment", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_netlogon_parameters,
{ "Parameters", "netlogon.parameters", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_netlogon_logon_script,
{ "Logon Script", "netlogon.logon_script", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_netlogon_profile_path,
{ "Profile Path", "netlogon.profile_path", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_netlogon_home_dir,
{ "Home Dir", "netlogon.home_dir", FT_STRING, BASE_NONE,
NULL, 0, "Home Directory", HFILL }},
{ &hf_netlogon_dir_drive,
{ "Dir Drive", "netlogon.dir_drive", FT_STRING, BASE_NONE,
NULL, 0, "Drive letter for home directory", HFILL }},
{ &hf_netlogon_logon_srv,
{ "Server", "netlogon.server", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_netlogon_principal,
{ "Principal", "netlogon.principal", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_netlogon_logon_dom,
{ "Domain", "netlogon.domain", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_netlogon_resourcegroupcount,
{ "ResourceGroup count", "netlogon.resourcegroupcount", FT_UINT32, BASE_DEC,
NULL, 0, "Number of Resource Groups", HFILL }},
{ &hf_netlogon_computer_name,
{ "Computer Name", "netlogon.computer_name", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_netlogon_site_name,
{ "Site Name", "netlogon.site_name", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_netlogon_dc_name,
{ "DC Name", "netlogon.dc.name", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_netlogon_dc_site_name,
{ "DC Site Name", "netlogon.dc.site_name", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_netlogon_dns_forest_name,
{ "DNS Forest Name", "netlogon.dns.forest_name", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_netlogon_dc_address,
{ "DC Address", "netlogon.dc.address", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_netlogon_dc_address_type,
{ "DC Address Type", "netlogon.dc.address_type", FT_UINT32, BASE_DEC,
VALS(dc_address_types), 0, NULL, HFILL }},
{ &hf_netlogon_client_site_name,
{ "Client Site Name", "netlogon.client.site_name", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_netlogon_workstation_site_name,
{ "Wkst Site Name", "netlogon.wkst.site_name", FT_STRING, BASE_NONE,
NULL, 0, "Workstation Site Name", HFILL }},
{ &hf_netlogon_workstation,
{ "Wkst Name", "netlogon.wkst.name", FT_STRING, BASE_NONE,
NULL, 0, "Workstation Name", HFILL }},
{ &hf_netlogon_os_version,
{ "OS version", "netlogon.os.version", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_netlogon_workstation_os,
{ "Wkst OS", "netlogon.wkst.os", FT_STRING, BASE_NONE,
NULL, 0, "Workstation OS", HFILL }},
{ &hf_netlogon_workstations,
{ "Workstations", "netlogon.wksts", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_netlogon_workstation_fqdn,
{ "Wkst FQDN", "netlogon.wkst.fqdn", FT_STRING, BASE_NONE,
NULL, 0, "Workstation FQDN", HFILL }},
{ &hf_netlogon_group_name,
{ "Group Name", "netlogon.group_name", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_netlogon_alias_name,
{ "Alias Name", "netlogon.alias_name", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_netlogon_dns_host,
{ "DNS Host", "netlogon.dns_host", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_netlogon_downlevel_domain_name,
{ "Downlevel Domain", "netlogon.downlevel_domain", FT_STRING, BASE_NONE,
NULL, 0, "Downlevel Domain Name", HFILL }},
{ &hf_netlogon_dns_domain_name,
{ "DNS Domain", "netlogon.dns_domain", FT_STRING, BASE_NONE,
NULL, 0, "DNS Domain Name", HFILL }},
{ &hf_netlogon_ad_client_dns_name,
{ "Client DNS Name", "netlogon.client_dns_name", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_netlogon_domain_name,
{ "Domain", "netlogon.domain", FT_STRING, BASE_NONE,
NULL, 0, "Domain Name", HFILL }},
{ &hf_netlogon_oem_info,
{ "OEM Info", "netlogon.oem_info", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_netlogon_trusted_dc_name,
{ "Trusted DC", "netlogon.trusted_dc", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_netlogon_logon_dnslogondomainname,
{ "DNS Logon Domain name", "netlogon.logon.dnslogondomainname", FT_STRING, BASE_NONE,
NULL, 0, "DNS Name of the logon domain", HFILL }},
{ &hf_netlogon_logon_upn,
{ "UPN", "netlogon.logon.upn", FT_STRING, BASE_NONE,
NULL, 0, "User Principal Name", HFILL }},
{ &hf_netlogon_logonsrv_handle,
{ "Handle", "netlogon.handle", FT_STRING, BASE_NONE,
NULL, 0, "Logon Srv Handle", HFILL }},
{ &hf_netlogon_dummy,
{ "Dummy", "netlogon.dummy", FT_STRING, BASE_NONE,
NULL, 0, "Dummy string", HFILL }},
{ &hf_netlogon_logon_count16,
{ "Logon Count", "netlogon.logon_count16", FT_UINT16, BASE_DEC,
NULL, 0x0, "Number of successful logins", HFILL }},
{ &hf_netlogon_logon_count,
{ "Logon Count", "netlogon.logon_count", FT_UINT32, BASE_DEC,
NULL, 0x0, "Number of successful logins", HFILL }},
{ &hf_netlogon_bad_pw_count16,
{ "Bad PW Count", "netlogon.bad_pw_count16", FT_UINT16, BASE_DEC,
NULL, 0x0, "Number of failed logins", HFILL }},
{ &hf_netlogon_bad_pw_count,
{ "Bad PW Count", "netlogon.bad_pw_count", FT_UINT32, BASE_DEC,
NULL, 0x0, "Number of failed logins", HFILL }},
{ &hf_netlogon_country,
{ "Country", "netlogon.country", FT_UINT16, BASE_DEC,
VALS(ms_country_codes), 0x0, "Country setting for this account", HFILL }},
{ &hf_netlogon_codepage,
{ "Codepage", "netlogon.codepage", FT_UINT16, BASE_DEC,
NULL, 0x0, "Codepage setting for this account", HFILL }},
{ &hf_netlogon_level16,
{ "Level", "netlogon.level16", FT_UINT16, BASE_DEC,
NULL, 0x0, "Which option of the union is represented here", HFILL }},
{ &hf_netlogon_validation_level,
{ "Validation Level", "netlogon.validation_level", FT_UINT16, BASE_DEC,
NULL, 0x0, "Requested level of validation", HFILL }},
{ &hf_netlogon_minpasswdlen,
{ "Min Password Len", "netlogon.min_passwd_len", FT_UINT16, BASE_DEC,
NULL, 0x0, "Minimum length of password", HFILL }},
{ &hf_netlogon_passwdhistorylen,
{ "Passwd History Len", "netlogon.passwd_history_len", FT_UINT16, BASE_DEC,
NULL, 0x0, "Length of password history", HFILL }},
{ &hf_netlogon_secure_channel_type,
{ "Sec Chan Type", "netlogon.sec_chan_type", FT_UINT16, BASE_DEC,
VALS(sec_chan_type_vals), 0x0, "Secure Channel Type", HFILL }},
{ &hf_netlogon_restart_state,
{ "Restart State", "netlogon.restart_state", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_netlogon_delta_type,
{ "Delta Type", "netlogon.delta_type", FT_UINT16, BASE_DEC,
VALS(delta_type_vals), 0x0, NULL, HFILL }},
{ &hf_netlogon_blob_size,
{ "Size", "netlogon.blob.size", FT_UINT32, BASE_DEC,
NULL, 0x0, "Size in bytes of BLOB", HFILL }},
{ &hf_netlogon_code,
{ "Code", "netlogon.code", FT_UINT32, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_netlogon_level,
{ "Level", "netlogon.level", FT_UINT32, BASE_DEC,
NULL, 0x0, "Which option of the union is represented here", HFILL }},
{ &hf_netlogon_reference,
{ "Reference", "netlogon.reference", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_netlogon_next_reference,
{ "Next Reference", "netlogon.next_reference", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_netlogon_timestamp,
{ "Timestamp", "netlogon.timestamp", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL,
NULL, 0, NULL, HFILL }},
{ &hf_netlogon_user_rid,
{ "User RID", "netlogon.rid", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_netlogon_alias_rid,
{ "Alias RID", "netlogon.alias_rid", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_netlogon_group_rid,
{ "Group RID", "netlogon.group_rid", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_netlogon_num_rids,
{ "Num RIDs", "netlogon.num_rids", FT_UINT32, BASE_DEC,
NULL, 0x0, "Number of RIDs", HFILL }},
{ &hf_netlogon_num_controllers,
{ "Num DCs", "netlogon.num_dc", FT_UINT32, BASE_DEC,
NULL, 0x0, "Number of domain controllers", HFILL }},
{ &hf_netlogon_num_sid,
{ "Num Extra SID", "netlogon.num_sid", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_netlogon_flags,
{ "Flags", "netlogon.flags", FT_UINT32, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_netlogon_user_account_control,
{ "User Account Control", "netlogon.user_account_control", FT_UINT32, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_netlogon_user_flags,
{ "User Flags", "netlogon.user_flags", FT_UINT32, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_netlogon_auth_flags,
{ "Auth Flags", "netlogon.auth_flags", FT_UINT32, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_netlogon_systemflags,
{ "System Flags", "netlogon.system_flags", FT_UINT32, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_netlogon_database_id,
{ "Database Id", "netlogon.database_id", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_netlogon_sync_context,
{ "Sync Context", "netlogon.sync_context", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_netlogon_max_size,
{ "Max Size", "netlogon.max_size", FT_UINT32, BASE_DEC,
NULL, 0x0, "Max Size of database", HFILL }},
{ &hf_netlogon_max_log_size,
{ "Max Log Size", "netlogon.max_log_size", FT_UINT32, BASE_DEC,
NULL, 0x0, "Max Size of log", HFILL }},
{ &hf_netlogon_pac_size,
{ "Pac Size", "netlogon.pac.size", FT_UINT32, BASE_DEC,
NULL, 0x0, "Size of PacData in bytes", HFILL }},
{ &hf_netlogon_auth_size,
{ "Auth Size", "netlogon.auth.size", FT_UINT32, BASE_DEC,
NULL, 0x0, "Size of AuthData in bytes", HFILL }},
{ &hf_netlogon_num_deltas,
{ "Num Deltas", "netlogon.num_deltas", FT_UINT32, BASE_DEC,
NULL, 0x0, "Number of SAM Deltas in array", HFILL }},
{ &hf_netlogon_num_trusts,
{ "Num Trusts", "netlogon.num_trusts", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_netlogon_logon_attempts,
{ "Logon Attempts", "netlogon.logon_attempts", FT_UINT32, BASE_DEC,
NULL, 0x0, "Number of logon attempts", HFILL }},
{ &hf_netlogon_pagefilelimit,
{ "Page File Limit", "netlogon.page_file_limit", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_netlogon_pagedpoollimit,
{ "Paged Pool Limit", "netlogon.paged_pool_limit", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_netlogon_nonpagedpoollimit,
{ "Non-Paged Pool Limit", "netlogon.nonpaged_pool_limit", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_netlogon_minworkingsetsize,
{ "Min Working Set Size", "netlogon.min_working_set_size", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_netlogon_maxworkingsetsize,
{ "Max Working Set Size", "netlogon.max_working_set_size", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_netlogon_serial_number,
{ "Serial Number", "netlogon.serial_number", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_netlogon_neg_flags,
{ "Negotiation options", "netlogon.neg_flags", FT_UINT32, BASE_HEX,
NULL, 0x0, "Negotiation Flags", HFILL }},
{ &hf_netlogon_neg_flags_80000000,
{ "Not used 80000000", "ntlmssp.neg_flags.na8000000", FT_BOOLEAN, 32, TFS(&tfs_set_notset), NETLOGON_FLAG_80000000, "Not used", HFILL }},
{ &hf_netlogon_neg_flags_40000000,
{ "Authenticated RPC supported", "ntlmssp.neg_flags.na8000000", FT_BOOLEAN, 32, TFS(&tfs_set_notset), NETLOGON_FLAG_40000000, NULL, HFILL }},
{ &hf_netlogon_neg_flags_20000000,
{ "Authenticated RPC via lsass supported", "ntlmssp.neg_flags.na8000000", FT_BOOLEAN, 32, TFS(&tfs_set_notset), NETLOGON_FLAG_20000000, "rpc via lsass", HFILL }},
{ &hf_netlogon_neg_flags_10000000,
{ "Not used 10000000", "ntlmssp.neg_flags.na8000000", FT_BOOLEAN, 32, TFS(&tfs_set_notset), NETLOGON_FLAG_10000000, "Not used", HFILL }},
{ &hf_netlogon_neg_flags_8000000,
{ "Not used 8000000", "ntlmssp.neg_flags.na800000", FT_BOOLEAN, 32, TFS(&tfs_set_notset), NETLOGON_FLAG_8000000, "Not used", HFILL }},
{ &hf_netlogon_neg_flags_4000000,
{ "Not used 4000000", "ntlmssp.neg_flags.na400000", FT_BOOLEAN, 32, TFS(&tfs_set_notset), NETLOGON_FLAG_4000000, "Not used", HFILL }},
{ &hf_netlogon_neg_flags_2000000,
{ "Not used 2000000", "ntlmssp.neg_flags.na200000", FT_BOOLEAN, 32, TFS(&tfs_set_notset), NETLOGON_FLAG_2000000, "Not used", HFILL }},
{ &hf_netlogon_neg_flags_1000000,
{ "AES supported", "ntlmssp.neg_flags.na100000", FT_BOOLEAN, 32, TFS(&tfs_set_notset), NETLOGON_FLAG_1000000, "AES", HFILL }},
{ &hf_netlogon_neg_flags_800000,
{ "Not used 800000", "ntlmssp.neg_flags.na8000000", FT_BOOLEAN, 32, TFS(&tfs_set_notset), NETLOGON_FLAG_800000, "Not used", HFILL }},
{ &hf_netlogon_neg_flags_400000,
{ "AES & SHA2 supported", "ntlmssp.neg_flags.na400000", FT_BOOLEAN, 32, TFS(&tfs_set_notset), NETLOGON_FLAG_USEAES, "AES&SHA2", HFILL }},
{ &hf_netlogon_neg_flags_200000,
{ "RODC pass-through", "ntlmssp.neg_flags.na200000", FT_BOOLEAN, 32, TFS(&tfs_set_notset), NETLOGON_FLAG_200000, "rodc pt", HFILL }},
{ &hf_netlogon_neg_flags_100000,
{ "NO NT4 emulation", "ntlmssp.neg_flags.na100000", FT_BOOLEAN, 32, TFS(&tfs_set_notset), NETLOGON_FLAG_100000, "No NT4 emu", HFILL }},
{ &hf_netlogon_neg_flags_80000,
{ "Cross forest trust", "ntlmssp.neg_flags.na80000", FT_BOOLEAN, 32, TFS(&tfs_set_notset), NETLOGON_FLAG_80000, NULL, HFILL }},
{ &hf_netlogon_neg_flags_40000,
{ "GetDomainInfo supported", "ntlmssp.neg_flags.na40000", FT_BOOLEAN, 32, TFS(&tfs_set_notset), NETLOGON_FLAG_40000, "GetDomainInfo", HFILL }},
{ &hf_netlogon_neg_flags_20000,
{ "ServerPasswordSet2 supported", "ntlmssp.neg_flags.na20000", FT_BOOLEAN, 32, TFS(&tfs_set_notset), NETLOGON_FLAG_20000, "PasswordSet2", HFILL }},
{ &hf_netlogon_neg_flags_10000,
{ "DNS trusts supported", "ntlmssp.neg_flags.na10000", FT_BOOLEAN, 32, TFS(&tfs_set_notset), NETLOGON_FLAG_10000, "DNS Trusts", HFILL }},
{ &hf_netlogon_neg_flags_8000,
{ "Transitive trusts", "ntlmssp.neg_flags.na8000", FT_BOOLEAN, 32, TFS(&tfs_set_notset), NETLOGON_FLAG_8000, "Transitive trust", HFILL }},
{ &hf_netlogon_neg_flags_4000,
{ "Strong key", "ntlmssp.neg_flags.na4000", FT_BOOLEAN, 32, TFS(&tfs_set_notset), NETLOGON_FLAG_STRONGKEY, NULL, HFILL }},
{ &hf_netlogon_neg_flags_2000,
{ "Avoid replication Auth database", "ntlmssp.neg_flags.na2000", FT_BOOLEAN, 32, TFS(&tfs_set_notset), NETLOGON_FLAG_2000, NULL, HFILL }},
{ &hf_netlogon_neg_flags_1000,
{ "Avoid replication account database", "ntlmssp.neg_flags.na1000", FT_BOOLEAN, 32, TFS(&tfs_set_notset), NETLOGON_FLAG_1000, NULL, HFILL }},
{ &hf_netlogon_neg_flags_800,
{ "Concurent RPC", "ntlmssp.neg_flags.na800", FT_BOOLEAN, 32, TFS(&tfs_set_notset), NETLOGON_FLAG_800, NULL, HFILL }},
{ &hf_netlogon_neg_flags_400,
{ "Generic pass-through", "ntlmssp.neg_flags.na400", FT_BOOLEAN, 32, TFS(&tfs_set_notset), NETLOGON_FLAG_400, NULL, HFILL }},
{ &hf_netlogon_neg_flags_200,
{ "SendToSam", "ntlmssp.neg_flags.na200", FT_BOOLEAN, 32, TFS(&tfs_set_notset), NETLOGON_FLAG_200, NULL, HFILL }},
{ &hf_netlogon_neg_flags_100,
{ "Refusal of password change", "ntlmssp.neg_flags.na100", FT_BOOLEAN, 32, TFS(&tfs_set_notset), NETLOGON_FLAG_100, "PWD change refusal", HFILL }},
{ &hf_netlogon_neg_flags_80,
{ "DatabaseRedo call", "ntlmssp.neg_flags.na80", FT_BOOLEAN, 32, TFS(&tfs_set_notset), NETLOGON_FLAG_80, NULL, HFILL }},
{ &hf_netlogon_neg_flags_40,
{ "Handle multiple SIDs", "ntlmssp.neg_flags.na40", FT_BOOLEAN, 32, TFS(&tfs_set_notset), NETLOGON_FLAG_40, NULL, HFILL }},
{ &hf_netlogon_neg_flags_20,
{ "Restarting full DC sync", "ntlmssp.neg_flags.na20", FT_BOOLEAN, 32, TFS(&tfs_set_notset), NETLOGON_FLAG_20, NULL, HFILL }},
{ &hf_netlogon_neg_flags_10,
{ "BDC handling Changelogs", "ntlmssp.neg_flags.na10", FT_BOOLEAN, 32, TFS(&tfs_set_notset), NETLOGON_FLAG_10, "BDC Changelog", HFILL }},
{ &hf_netlogon_neg_flags_8,
{ "Promotion count(deprecated)", "ntlmssp.neg_flags.na8", FT_BOOLEAN, 32, TFS(&tfs_set_notset), NETLOGON_FLAG_8, "Promotion count", HFILL }},
{ &hf_netlogon_neg_flags_4,
{ "RC4 encryption", "ntlmssp.neg_flags.na4", FT_BOOLEAN, 32, TFS(&tfs_set_notset), NETLOGON_FLAG_4, "RC4", HFILL }},
{ &hf_netlogon_neg_flags_2,
{ "NT3.5 BDC continuous update", "ntlmssp.neg_flags.na2", FT_BOOLEAN, 32, TFS(&tfs_set_notset), NETLOGON_FLAG_2, "NT3.5", HFILL }},
{ &hf_netlogon_neg_flags_1,
{ "Account lockout", "ntlmssp.neg_flags.na1", FT_BOOLEAN, 32, TFS(&tfs_set_notset), NETLOGON_FLAG_1, NULL, HFILL }},
{ &hf_netlogon_dc_flags,
{ "Domain Controller Flags", "netlogon.dc.flags", FT_UINT32, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_netlogon_dc_flags_pdc_flag,
{ "PDC", "netlogon.dc.flags.pdc",
FT_BOOLEAN, 32, TFS(&dc_flags_pdc_flag), DS_PDC_FLAG,
"If this server is a PDC", HFILL }},
{ &hf_netlogon_dc_flags_gc_flag,
{ "GC", "netlogon.dc.flags.gc",
FT_BOOLEAN, 32, TFS(&dc_flags_gc_flag), DS_GC_FLAG,
"If this server is a GC", HFILL }},
{ &hf_netlogon_dc_flags_ldap_flag,
{ "LDAP", "netlogon.dc.flags.ldap",
FT_BOOLEAN, 32, TFS(&dc_flags_ldap_flag), DS_LDAP_FLAG,
"If this is an LDAP server", HFILL }},
{ &hf_netlogon_dc_flags_ds_flag,
{ "DS", "netlogon.dc.flags.ds",
FT_BOOLEAN, 32, TFS(&dc_flags_ds_flag), DS_DS_FLAG,
"If this server is a DS", HFILL }},
{ &hf_netlogon_dc_flags_kdc_flag,
{ "KDC", "netlogon.dc.flags.kdc",
FT_BOOLEAN, 32, TFS(&dc_flags_kdc_flag), DS_KDC_FLAG,
"If this is a KDC", HFILL }},
{ &hf_netlogon_dc_flags_timeserv_flag,
{ "Timeserv", "netlogon.dc.flags.timeserv",
FT_BOOLEAN, 32, TFS(&dc_flags_timeserv_flag), DS_TIMESERV_FLAG,
"If this server is a TimeServer", HFILL }},
{ &hf_netlogon_dc_flags_closest_flag,
{ "Closest", "netlogon.dc.flags.closest",
FT_BOOLEAN, 32, TFS(&dc_flags_closest_flag), DS_CLOSEST_FLAG,
"If this is the closest server", HFILL }},
{ &hf_netlogon_dc_flags_writable_flag,
{ "Writable", "netlogon.dc.flags.writable",
FT_BOOLEAN, 32, TFS(&dc_flags_writable_flag), DS_WRITABLE_FLAG,
"If this server can do updates to the database", HFILL }},
{ &hf_netlogon_dc_flags_good_timeserv_flag,
{ "Good Timeserv", "netlogon.dc.flags.good_timeserv",
FT_BOOLEAN, 32, TFS(&dc_flags_good_timeserv_flag), DS_GOOD_TIMESERV_FLAG,
"If this is a Good TimeServer", HFILL }},
{ &hf_netlogon_dc_flags_ndnc_flag,
{ "NDNC", "netlogon.dc.flags.ndnc",
FT_BOOLEAN, 32, TFS(&dc_flags_ndnc_flag), DS_NDNC_FLAG,
"If this is an NDNC server", HFILL }},
{ &hf_netlogon_dc_flags_dns_controller_flag,
{ "DNS Controller", "netlogon.dc.flags.dns_controller",
FT_BOOLEAN, 32, TFS(&dc_flags_dns_controller_flag), DS_DNS_CONTROLLER_FLAG,
"If this server is a DNS Controller", HFILL }},
{ &hf_netlogon_dc_flags_dns_domain_flag,
{ "DNS Domain", "netlogon.dc.flags.dns_domain",
FT_BOOLEAN, 32, TFS(&dc_flags_dns_domain_flag), DS_DNS_DOMAIN_FLAG,
NULL, HFILL }},
{ &hf_netlogon_dc_flags_dns_forest_flag,
{ "DNS Forest", "netlogon.dc.flags.dns_forest",
FT_BOOLEAN, 32, TFS(&dc_flags_dns_forest_flag), DS_DNS_FOREST_FLAG,
NULL, HFILL }},
{ &hf_netlogon_get_dcname_request_flags,
{ "Flags", "netlogon.get_dcname.request.flags", FT_UINT32, BASE_HEX,
NULL, 0x0, "Flags for DSGetDCName request", HFILL }},
{ &hf_netlogon_get_dcname_request_flags_force_rediscovery,
{ "Force Rediscovery", "netlogon.get_dcname.request.flags.force_rediscovery",
FT_BOOLEAN, 32, TFS(&get_dcname_request_flags_force_rediscovery), DS_FORCE_REDISCOVERY,
"Whether to allow the server to returned cached information or not", HFILL }},
{ &hf_netlogon_get_dcname_request_flags_directory_service_required,
{ "DS Required", "netlogon.get_dcname.request.flags.ds_required",
FT_BOOLEAN, 32, TFS(&get_dcname_request_flags_directory_service_required), DS_DIRECTORY_SERVICE_REQUIRED,
"Whether we require that the returned DC supports w2k or not", HFILL }},
{ &hf_netlogon_get_dcname_request_flags_directory_service_preferred,
{ "DS Preferred", "netlogon.get_dcname.request.flags.ds_preferred",
FT_BOOLEAN, 32, TFS(&get_dcname_request_flags_directory_service_preferred), DS_DIRECTORY_SERVICE_PREFERRED,
"Whether we prefer the call to return a w2k server (if available)", HFILL }},
{ &hf_netlogon_get_dcname_request_flags_gc_server_required,
{ "GC Required", "netlogon.get_dcname.request.flags.gc_server_required",
FT_BOOLEAN, 32, TFS(&get_dcname_request_flags_gc_server_required), DS_GC_SERVER_REQUIRED,
"Whether we require that the returned DC is a Global Catalog server", HFILL }},
{ &hf_netlogon_get_dcname_request_flags_pdc_required,
{ "PDC Required", "netlogon.get_dcname.request.flags.pdc_required",
FT_BOOLEAN, 32, TFS(&get_dcname_request_flags_pdc_required), DS_PDC_REQUIRED,
"Whether we require the returned DC to be the PDC", HFILL }},
{ &hf_netlogon_get_dcname_request_flags_background_only,
{ "Background Only", "netlogon.get_dcname.request.flags.background_only",
FT_BOOLEAN, 32, TFS(&get_dcname_request_flags_background_only), DS_BACKGROUND_ONLY,
"If we want cached data, even if it may have expired", HFILL }},
{ &hf_netlogon_get_dcname_request_flags_ip_required,
{ "IP Required", "netlogon.get_dcname.request.flags.ip_required",
FT_BOOLEAN, 32, TFS(&get_dcname_request_flags_ip_required), DS_IP_REQUIRED,
"If we require the IP of the DC in the reply", HFILL }},
{ &hf_netlogon_get_dcname_request_flags_kdc_required,
{ "KDC Required", "netlogon.get_dcname.request.flags.kdc_required",
FT_BOOLEAN, 32, TFS(&get_dcname_request_flags_kdc_required), DS_KDC_REQUIRED,
"If we require that the returned server is a KDC", HFILL }},
{ &hf_netlogon_get_dcname_request_flags_timeserv_required,
{ "Timeserv Required", "netlogon.get_dcname.request.flags.timeserv_required",
FT_BOOLEAN, 32, TFS(&get_dcname_request_flags_timeserv_required), DS_TIMESERV_REQUIRED,
"If we require the returned server to be a WindowsTimeServ server", HFILL }},
{ &hf_netlogon_get_dcname_request_flags_writable_required,
{ "Writable Required", "netlogon.get_dcname.request.flags.writable_required",
FT_BOOLEAN, 32, TFS(&get_dcname_request_flags_writable_required), DS_WRITABLE_REQUIRED,
"If we require that the returned server is writable", HFILL }},
{ &hf_netlogon_get_dcname_request_flags_good_timeserv_preferred,
{ "Timeserv Preferred", "netlogon.get_dcname.request.flags.good_timeserv_preferred",
FT_BOOLEAN, 32, TFS(&get_dcname_request_flags_good_timeserv_preferred), DS_GOOD_TIMESERV_PREFERRED,
"If we prefer Windows Time Servers", HFILL }},
{ &hf_netlogon_get_dcname_request_flags_avoid_self,
{ "Avoid Self", "netlogon.get_dcname.request.flags.avoid_self",
FT_BOOLEAN, 32, TFS(&get_dcname_request_flags_avoid_self), DS_AVOID_SELF,
"Return another DC than the one we ask", HFILL }},
{ &hf_netlogon_get_dcname_request_flags_only_ldap_needed,
{ "Only LDAP Needed", "netlogon.get_dcname.request.flags.only_ldap_needed",
FT_BOOLEAN, 32, TFS(&get_dcname_request_flags_only_ldap_needed), DS_ONLY_LDAP_NEEDED,
"We just want an LDAP server, it does not have to be a DC", HFILL }},
{ &hf_netlogon_get_dcname_request_flags_is_flat_name,
{ "Is Flat Name", "netlogon.get_dcname.request.flags.is_flat_name",
FT_BOOLEAN, 32, TFS(&get_dcname_request_flags_is_flat_name), DS_IS_FLAT_NAME,
"If the specified domain name is a NetBIOS name", HFILL }},
{ &hf_netlogon_get_dcname_request_flags_is_dns_name,
{ "Is DNS Name", "netlogon.get_dcname.request.flags.is_dns_name",
FT_BOOLEAN, 32, TFS(&get_dcname_request_flags_is_dns_name), DS_IS_DNS_NAME,
"If the specified domain name is a DNS name", HFILL }},
{ &hf_netlogon_get_dcname_request_flags_return_dns_name,
{ "Return DNS Name", "netlogon.get_dcname.request.flags.return_dns_name",
FT_BOOLEAN, 32, TFS(&get_dcname_request_flags_return_dns_name), DS_RETURN_DNS_NAME,
"Only return a DNS name (or an error)", HFILL }},
{ &hf_netlogon_get_dcname_request_flags_return_flat_name,
{ "Return Flat Name", "netlogon.get_dcname.request.flags.return_flat_name",
FT_BOOLEAN, 32, TFS(&get_dcname_request_flags_return_flat_name), DS_RETURN_FLAT_NAME,
"Only return a NetBIOS name (or an error)", HFILL }},
{ &hf_netlogon_trust_attribs,
{ "Trust Attributes", "netlogon.trust_attribs", FT_UINT32, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_netlogon_trust_attribs_non_transitive,
{ "Non Transitive", "netlogon.trust.attribs.non_transitive", FT_BOOLEAN, 32,
TFS(&trust_attribs_non_transitive), 0x00000001, NULL, HFILL }},
{ &hf_netlogon_trust_attribs_uplevel_only,
{ "Uplevel Only", "netlogon.trust.attribs.uplevel_only", FT_BOOLEAN, 32,
TFS(&trust_attribs_uplevel_only), 0x00000002, NULL, HFILL }},
{ &hf_netlogon_trust_attribs_quarantined_domain,
{ "Quarantined Domain", "netlogon.trust.attribs.quarantined_domain", FT_BOOLEAN, 32,
TFS(&trust_attribs_quarantined_domain), 0x00000004, NULL, HFILL }},
{ &hf_netlogon_trust_attribs_forest_transitive,
{ "Forest Transitive", "netlogon.trust.attribs.forest_transitive", FT_BOOLEAN, 32,
TFS(&trust_attribs_forest_transitive), 0x00000008, NULL, HFILL }},
{ &hf_netlogon_trust_attribs_cross_organization,
{ "Cross Organization", "netlogon.trust.attribs.cross_organization", FT_BOOLEAN, 32,
TFS(&trust_attribs_cross_organization), 0x00000010, NULL, HFILL }},
{ &hf_netlogon_trust_attribs_within_forest,
{ "Within Forest", "netlogon.trust.attribs.within_forest", FT_BOOLEAN, 32,
TFS(&trust_attribs_within_forest), 0x00000020, NULL, HFILL }},
{ &hf_netlogon_trust_attribs_treat_as_external,
{ "Treat As External", "netlogon.trust.attribs.treat_as_external", FT_BOOLEAN, 32,
TFS(&trust_attribs_treat_as_external), 0x00000040, NULL, HFILL }},
{ &hf_netlogon_trust_type,
{ "Trust Type", "netlogon.trust_type", FT_UINT32, BASE_DEC,
VALS(trust_type_vals), 0x0, NULL, HFILL }},
{ &hf_netlogon_extraflags,
{ "Extra Flags", "netlogon.extra_flags", FT_UINT32, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_netlogon_extra_flags_root_forest,
{ "Request passed to DC of root forest", "netlogon.extra.flags.rootdc",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), RQ_ROOT_FOREST,
NULL, HFILL }},
{ &hf_netlogon_trust_flags_dc_firsthop,
{ "DC at the end of the first hop of cross forest", "netlogon.extra.flags.dc_firsthop",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), RQ_DC_XFOREST,
NULL, HFILL }},
{ &hf_netlogon_trust_flags_rodc_to_dc,
{ "Request from a RODC to a DC from another domain", "netlogon.extra.flags.rodc_to_dc",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), RQ_RODC_DIF_DOMAIN,
NULL, HFILL }},
{ &hf_netlogon_trust_flags_rodc_ntlm,
{ "Request is a NTLM auth passed by a RODC", "netlogon.extra.flags.rodc_ntlm",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), RQ_NTLM_FROM_RODC,
NULL, HFILL }},
{ &hf_netlogon_trust_flags,
{ "Trust Flags", "netlogon.trust_flags", FT_UINT32, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_netlogon_trust_flags_inbound,
{ "Inbound Trust", "netlogon.trust.flags.inbound",
FT_BOOLEAN, 32, TFS(&trust_inbound), DS_DOMAIN_DIRECT_INBOUND,
"Inbound trust. Whether the domain directly trusts the queried servers domain", HFILL }},
{ &hf_netlogon_trust_flags_outbound,
{ "Outbound Trust", "netlogon.trust.flags.outbound",
FT_BOOLEAN, 32, TFS(&trust_outbound), DS_DOMAIN_DIRECT_OUTBOUND,
"Outbound Trust. Whether the domain is directly trusted by the servers domain", HFILL }},
{ &hf_netlogon_trust_flags_in_forest,
{ "In Forest", "netlogon.trust.flags.in_forest",
FT_BOOLEAN, 32, TFS(&trust_in_forest), DS_DOMAIN_IN_FOREST,
"Whether this domain is a member of the same forest as the servers domain", HFILL }},
{ &hf_netlogon_trust_flags_native_mode,
{ "Native Mode", "netlogon.trust.flags.native_mode",
FT_BOOLEAN, 32, TFS(&trust_native_mode), DS_DOMAIN_NATIVE_MODE,
"Whether the domain is a w2k native mode domain or not", HFILL }},
{ &hf_netlogon_trust_flags_primary,
{ "Primary", "netlogon.trust.flags.primary",
FT_BOOLEAN, 32, TFS(&trust_primary), DS_DOMAIN_PRIMARY,
"Whether the domain is the primary domain for the queried server or not", HFILL }},
{ &hf_netlogon_trust_flags_tree_root,
{ "Tree Root", "netlogon.trust.flags.tree_root",
FT_BOOLEAN, 32, TFS(&trust_tree_root), DS_DOMAIN_TREE_ROOT,
"Whether the domain is the root of the tree for the queried server", HFILL }},
{ &hf_netlogon_trust_parent_index,
{ "Parent Index", "netlogon.parent_index", FT_UINT32, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_netlogon_logon_time,
{ "Logon Time", "netlogon.logon_time", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL,
NULL, 0, "Time for last time this user logged on", HFILL }},
{ &hf_netlogon_kickoff_time,
{ "Kickoff Time", "netlogon.kickoff_time", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL,
NULL, 0, "Time when this user will be kicked off", HFILL }},
{ &hf_netlogon_logoff_time,
{ "Logoff Time", "netlogon.logoff_time", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL,
NULL, 0, "Time for last time this user logged off", HFILL }},
{ &hf_netlogon_last_logoff_time,
{ "Last Logoff Time", "netlogon.last_logoff_time", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL,
NULL, 0, "Time for last time this user logged off", HFILL }},
{ &hf_netlogon_pwd_last_set_time,
{ "PWD Last Set", "netlogon.pwd_last_set_time", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL,
NULL, 0, "Last time this users password was changed", HFILL }},
{ &hf_netlogon_pwd_age,
{ "PWD Age", "netlogon.pwd_age", FT_RELATIVE_TIME, BASE_NONE,
NULL, 0, "Time since this users password was changed", HFILL }},
{ &hf_netlogon_pwd_can_change_time,
{ "PWD Can Change", "netlogon.pwd_can_change_time", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL,
NULL, 0, "When this users password may be changed", HFILL }},
{ &hf_netlogon_pwd_must_change_time,
{ "PWD Must Change", "netlogon.pwd_must_change_time", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL,
NULL, 0, "When this users password must be changed", HFILL }},
{ &hf_netlogon_domain_create_time,
{ "Domain Create Time", "netlogon.domain_create_time", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL,
NULL, 0, "Time when this domain was created", HFILL }},
{ &hf_netlogon_domain_modify_time,
{ "Domain Modify Time", "netlogon.domain_modify_time", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL,
NULL, 0, "Time when this domain was last modified", HFILL }},
{ &hf_netlogon_db_modify_time,
{ "DB Modify Time", "netlogon.db_modify_time", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL,
NULL, 0, "Time when last modified", HFILL }},
{ &hf_netlogon_db_create_time,
{ "DB Create Time", "netlogon.db_create_time", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL,
NULL, 0, "Time when created", HFILL }},
{ &hf_netlogon_cipher_current_set_time,
{ "Cipher Current Set Time", "netlogon.cipher_current_set_time", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL,
NULL, 0, "Time when current cipher was initiated", HFILL }},
{ &hf_netlogon_cipher_old_set_time,
{ "Cipher Old Set Time", "netlogon.cipher_old_set_time", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL,
NULL, 0, "Time when previous cipher was initiated", HFILL }},
{ &hf_netlogon_audit_retention_period,
{ "Audit Retention Period", "netlogon.audit_retention_period", FT_RELATIVE_TIME, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_netlogon_timelimit,
{ "Time Limit", "netlogon.time_limit", FT_RELATIVE_TIME, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_client_credential,
{ "Client Credential", "netlogon.clientcred", FT_BYTES, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_server_credential,
{ "Server Credential", "netlogon.servercred", FT_BYTES, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_server_rid,
{ "Account RID", "netlogon.serverrid", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_client_challenge,
{ "Client Challenge", "netlogon.clientchallenge", FT_BYTES, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_server_challenge,
{ "Server Challenge", "netlogon.serverchallenge", FT_BYTES, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_netlogon_secchan_nl_message_type,
{ "Message Type", "netlogon.secchan.nl_auth_message.message_type", FT_UINT32, BASE_HEX,
VALS(nl_auth_types), 0x0, NULL, HFILL }},
{ &hf_netlogon_secchan_nl_message_flags,
{ "Message Flags", "netlogon.secchan.nl_auth_message.message_flags", FT_UINT32, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_netlogon_secchan_nl_message_flags_nb_domain,
{ "NetBios Domain", "netlogon.secchan.nl_auth_message.message_flags.nb_domain", FT_BOOLEAN, 32,
NULL, 0x00000001, NULL, HFILL }},
{ &hf_netlogon_secchan_nl_message_flags_nb_host,
{ "NetBios Host", "netlogon.secchan.nl_auth_message.message_flags.nb_host", FT_BOOLEAN, 32,
NULL, 0x00000002, NULL, HFILL }},
{ &hf_netlogon_secchan_nl_message_flags_dns_domain,
{ "DNS Domain", "netlogon.secchan.nl_auth_message.message_flags.dns_domain", FT_BOOLEAN, 32,
NULL, 0x00000004, NULL, HFILL }},
{ &hf_netlogon_secchan_nl_message_flags_dns_host,
{ "DNS Host", "netlogon.secchan.nl_auth_message.message_flags.dns_host", FT_BOOLEAN, 32,
NULL, 0x00000008, NULL, HFILL }},
{ &hf_netlogon_secchan_nl_message_flags_nb_host_utf8,
{ "NetBios Host(UTF8)", "netlogon.secchan.nl_auth_message.message_flags.nb_host_utf8", FT_BOOLEAN, 32,
NULL, 0x00000010, NULL, HFILL }},
{ &hf_netlogon_secchan_nl_nb_domain,
{ "NetBios Domain", "netlogon.secchan.nl_auth_message.nb_domain", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_netlogon_secchan_nl_nb_host,
{ "NetBios Host", "netlogon.secchan.nl_auth_message.nb_host", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_netlogon_secchan_nl_nb_host_utf8,
{ "NetBios Host(UTF8)", "netlogon.secchan.nl_auth_message.nb_host_utf8", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_netlogon_secchan_nl_dns_domain,
{ "DNS Domain", "netlogon.secchan.nl_auth_message.dns_domain", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_netlogon_secchan_nl_dns_host,
{ "DNS Host", "netlogon.secchan.nl_auth_message.dns_host", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_netlogon_data_length,
{ "Length of Data", "netlogon.data.length", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_netlogon_package_name,
{ "SSP Package Name", "netlogon.data.package_name", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_netlogon_secchan_verf,
{ "Secure Channel Verifier", "netlogon.secchan.verifier", FT_NONE, BASE_NONE,
NULL, 0x0, "Verifier", HFILL }},
{ &hf_netlogon_secchan_verf_signalg,
{ "Sign algorithm", "netlogon.secchan.signalg", FT_UINT16, BASE_HEX,
VALS(sign_algs), 0, NULL, HFILL }},
{ &hf_netlogon_secchan_verf_sealalg,
{ "Seal algorithm", "netlogon.secchan.sealalg", FT_UINT16, BASE_HEX,
VALS(seal_algs), 0, NULL, HFILL }},
{ &hf_netlogon_secchan_verf_flag,
{ "Flags", "netlogon.secchan.flags", FT_BYTES, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_netlogon_secchan_verf_digest,
{ "Packet Digest", "netlogon.secchan.digest", FT_BYTES, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_netlogon_secchan_verf_seq,
{ "Sequence No", "netlogon.secchan.seq", FT_BYTES, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_netlogon_secchan_verf_nonce,
{ "Nonce", "netlogon.secchan.nonce", FT_BYTES, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_netlogon_group_attrs_mandatory,
{ "Mandatory", "netlogon.groups.attrs.mandatory",
FT_BOOLEAN, 32, TFS(&group_attrs_mandatory), 0x00000001,
"The group attributes MANDATORY flag", HFILL }},
{ &hf_netlogon_group_attrs_enabled_by_default,
{ "Enabled By Default", "netlogon.groups.attrs.enabled_by_default",
FT_BOOLEAN, 32, TFS(&group_attrs_enabled_by_default), 0x00000002,
"The group attributes ENABLED_BY_DEFAULT flag", HFILL }},
{ &hf_netlogon_group_attrs_enabled,
{ "Enabled", "netlogon.groups.attrs.enabled",
FT_BOOLEAN, 32, TFS(&group_attrs_enabled), 0x00000004,
"The group attributes ENABLED flag", HFILL }},
{ &hf_netlogon_user_flags_extra_sids,
{ "Extra SIDs", "netlogon.user.flags.extra_sids",
FT_BOOLEAN, 32, TFS(&user_flags_extra_sids), 0x00000020,
"The user flags EXTRA_SIDS", HFILL }},
{ &hf_netlogon_user_flags_resource_groups,
{ "Resource Groups", "netlogon.user.flags.resource_groups",
FT_BOOLEAN, 32, TFS(&user_flags_resource_groups), 0x00000200,
"The user flags RESOURCE_GROUPS", HFILL }},
{ &hf_netlogon_user_account_control_dont_require_preauth,
{ "Don't Require PreAuth", "netlogon.user.account_control.dont_require_preauth",
FT_BOOLEAN, 32, TFS(&user_account_control_dont_require_preauth), 0x00010000,
"The user account control DONT_REQUIRE_PREAUTH flag", HFILL }},
{ &hf_netlogon_user_account_control_use_des_key_only,
{ "Use DES Key Only", "netlogon.user.account_control.use_des_key_only",
FT_BOOLEAN, 32, TFS(&user_account_control_use_des_key_only), 0x00008000,
"The user account control use_des_key_only flag", HFILL }},
{ &hf_netlogon_user_account_control_not_delegated,
{ "Not Delegated", "netlogon.user.account_control.not_delegated",
FT_BOOLEAN, 32, TFS(&user_account_control_not_delegated), 0x00004000,
"The user account control not_delegated flag", HFILL }},
{ &hf_netlogon_user_account_control_trusted_for_delegation,
{ "Trusted For Delegation", "netlogon.user.account_control.trusted_for_delegation",
FT_BOOLEAN, 32, TFS(&user_account_control_trusted_for_delegation), 0x00002000,
"The user account control trusted_for_delegation flag", HFILL }},
{ &hf_netlogon_user_account_control_smartcard_required,
{ "SmartCard Required", "netlogon.user.account_control.smartcard_required",
FT_BOOLEAN, 32, TFS(&user_account_control_smartcard_required), 0x00001000,
"The user account control smartcard_required flag", HFILL }},
{ &hf_netlogon_user_account_control_encrypted_text_password_allowed,
{ "Encrypted Text Password Allowed", "netlogon.user.account_control.encrypted_text_password_allowed",
FT_BOOLEAN, 32, TFS(&user_account_control_encrypted_text_password_allowed), 0x00000800,
"The user account control encrypted_text_password_allowed flag", HFILL }},
{ &hf_netlogon_user_account_control_account_auto_locked,
{ "Account Auto Locked", "netlogon.user.account_control.account_auto_locked",
FT_BOOLEAN, 32, TFS(&user_account_control_account_auto_locked), 0x00000400,
"The user account control account_auto_locked flag", HFILL }},
{ &hf_netlogon_user_account_control_dont_expire_password,
{ "Don't Expire Password", "netlogon.user.account_control.dont_expire_password",
FT_BOOLEAN, 32, TFS(&user_account_control_dont_expire_password), 0x00000200,
"The user account control dont_expire_password flag", HFILL }},
{ &hf_netlogon_user_account_control_server_trust_account,
{ "Server Trust Account", "netlogon.user.account_control.server_trust_account",
FT_BOOLEAN, 32, TFS(&user_account_control_server_trust_account), 0x00000100,
"The user account control server_trust_account flag", HFILL }},
{ &hf_netlogon_user_account_control_workstation_trust_account,
{ "Workstation Trust Account", "netlogon.user.account_control.workstation_trust_account",
FT_BOOLEAN, 32, TFS(&user_account_control_workstation_trust_account), 0x00000080,
"The user account control workstation_trust_account flag", HFILL }},
{ &hf_netlogon_user_account_control_interdomain_trust_account,
{ "Interdomain trust Account", "netlogon.user.account_control.interdomain_trust_account",
FT_BOOLEAN, 32, TFS(&user_account_control_interdomain_trust_account), 0x00000040,
"The user account control interdomain_trust_account flag", HFILL }},
{ &hf_netlogon_user_account_control_mns_logon_account,
{ "MNS Logon Account", "netlogon.user.account_control.mns_logon_account",
FT_BOOLEAN, 32, TFS(&user_account_control_mns_logon_account), 0x00000020,
"The user account control mns_logon_account flag", HFILL }},
{ &hf_netlogon_user_account_control_normal_account,
{ "Normal Account", "netlogon.user.account_control.normal_account",
FT_BOOLEAN, 32, TFS(&user_account_control_normal_account), 0x00000010,
"The user account control normal_account flag", HFILL }},
{ &hf_netlogon_user_account_control_temp_duplicate_account,
{ "Temp Duplicate Account", "netlogon.user.account_control.temp_duplicate_account",
FT_BOOLEAN, 32, TFS(&user_account_control_temp_duplicate_account), 0x00000008,
"The user account control temp_duplicate_account flag", HFILL }},
{ &hf_netlogon_user_account_control_password_not_required,
{ "Password Not Required", "netlogon.user.account_control.password_not_required",
FT_BOOLEAN, 32, TFS(&user_account_control_password_not_required), 0x00000004,
"The user account control password_not_required flag", HFILL }},
{ &hf_netlogon_user_account_control_home_directory_required,
{ "Home Directory Required", "netlogon.user.account_control.home_directory_required",
FT_BOOLEAN, 32, TFS(&user_account_control_home_directory_required), 0x00000002,
"The user account control home_directory_required flag", HFILL }},
{ &hf_netlogon_user_account_control_account_disabled,
{ "Account Disabled", "netlogon.user.account_control.account_disabled",
FT_BOOLEAN, 32, TFS(&user_account_control_account_disabled), 0x00000001,
"The user account control account_disabled flag", HFILL }},
{ &hf_netlogon_dnsdomaininfo,
{ "DnsDomainInfo", "netlogon.dnsdomaininfo", FT_NONE, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &DnsDomainInfo_sid,
{ "Sid", "lsarpc.lsa_DnsDomainInfo.sid", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &DomainInfo_sid,
{ "Sid", "lsarpc.lsa_DomainInfo.sid", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &DnsDomainInfo_domain_guid,
{ "Domain Guid", "lsarpc.lsa_DnsDomainInfo.domain_guid", FT_GUID, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &DnsDomainInfo_dns_forest,
{ "Dns Forest", "lsarpc.lsa_DnsDomainInfo.dns_forest", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &DnsDomainInfo_dns_domain,
{ "Dns Domain", "lsarpc.lsa_DnsDomainInfo.dns_domain", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &DnsDomainInfo_name,
{ "Name", "lsarpc.lsa_DnsDomainInfo.name", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_netlogon_s4u2proxytarget,
{ "S4U2proxyTarget", "netlogon.s4u2proxytarget", FT_STRING, BASE_NONE,
NULL, 0, "Target for constrained delegation using s4u2proxy", HFILL }},
{ &hf_netlogon_transitedlistsize,
{ "TransitedListSize", "netlogon.transited_list_size", FT_UINT32, BASE_HEX,
NULL, 0x0, "Number of elements in the TransitedServices array.", HFILL }},
{ &hf_netlogon_transited_service,
{ "Transited Service", "netlogon.transited_service", FT_STRING, BASE_NONE,
NULL, 0, "S4U2 Transited Service name", HFILL }},
};
static gint *ett[] = {
&ett_dcerpc_netlogon,
&ett_authenticate_flags,
&ett_CYPHER_VALUE,
&ett_QUOTA_LIMITS,
&ett_IDENTITY_INFO,
&ett_DELTA_ENUM,
&ett_UNICODE_MULTI,
&ett_DOMAIN_CONTROLLER_INFO,
&ett_UNICODE_STRING_512,
&ett_TYPE_50,
&ett_TYPE_52,
&ett_DELTA_ID_UNION,
&ett_TYPE_44,
&ett_DELTA_UNION,
&ett_LM_OWF_PASSWORD,
&ett_NT_OWF_PASSWORD,
&ett_GROUP_MEMBERSHIP,
&ett_DS_DOMAIN_TRUSTS,
&ett_BLOB,
&ett_DOMAIN_TRUST_INFO,
&ett_LSA_POLICY_INFO,
&ett_trust_flags,
&ett_trust_attribs,
&ett_get_dcname_request_flags,
&ett_dc_flags,
&ett_secchan_nl_auth_message,
&ett_secchan_nl_auth_message_flags,
&ett_secchan_verf,
&ett_group_attrs,
&ett_user_flags,
&ett_nt_counted_longs_as_string,
&ett_user_account_control
};
proto_dcerpc_netlogon = proto_register_protocol(
"Microsoft Network Logon", "RPC_NETLOGON", "rpc_netlogon");
proto_register_field_array(proto_dcerpc_netlogon, hf,
array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_init_routine(netlogon_reassemble_init);
}
void
proto_reg_handoff_dcerpc_netlogon(void)
{
seen.isseen = FALSE;
seen.num = 0;
dcerpc_init_uuid(proto_dcerpc_netlogon, ett_dcerpc_netlogon,
&uuid_dcerpc_netlogon, ver_dcerpc_netlogon,
dcerpc_netlogon_dissectors, hf_netlogon_opnum);
register_dcerpc_auth_subdissector(DCE_C_AUTHN_LEVEL_PKT_INTEGRITY,
DCE_C_RPC_AUTHN_PROTOCOL_SEC_CHAN,
&secchan_auth_fns);
register_dcerpc_auth_subdissector(DCE_C_AUTHN_LEVEL_PKT_PRIVACY,
DCE_C_RPC_AUTHN_PROTOCOL_SEC_CHAN,
&secchan_auth_fns);
}
