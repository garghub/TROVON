static void
dissect_flag(tvbuff_t *tvb, guint offset, proto_tree *tree)
{
proto_item *flag_item;
proto_tree *flag_tree;
flag_item = proto_tree_add_item(tree, hf_wai_flag, tvb, offset, 1, ENC_BIG_ENDIAN);
flag_tree = proto_item_add_subtree (flag_item, ett_wai_flags);
proto_tree_add_item (flag_tree, hf_wai_bk_rekeying_flag, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (flag_tree, hf_wai_preauthentication_flag, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (flag_tree, hf_wai_certificate_flag, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (flag_tree, hf_wai_optional_flag, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (flag_tree, hf_wai_usk_rekeying_flag, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (flag_tree, hf_wai_negotiation_flag, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (flag_tree, hf_wai_revoking_flag, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (flag_tree, hf_wai_reserved_flag, tvb, offset, 1, ENC_BIG_ENDIAN);
}
inline static void
dissect_bkid(tvbuff_t *tvb, guint offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_wai_bkid, tvb, offset, 16, ENC_NA);
}
inline static void
dissect_uskid(tvbuff_t *tvb, guint offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_wai_uskid, tvb, offset, 1, ENC_NA);
}
inline static void dissect_wie(tvbuff_t *tvb, guint offset, guint length, proto_tree *tree)
{
proto_tree_add_item(tree, hf_wai_wie, tvb, offset, length, ENC_NA);
}
inline static void
dissect_message_auth_code(tvbuff_t *tvb, guint offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_wai_message_auth_code, tvb, offset, 20, ENC_NA);
}
inline static void
dissect_mskid(tvbuff_t *tvb, guint offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_wai_mskid, tvb, offset, 1, ENC_NA);
}
inline static void
dissect_key_announcement_identifier(tvbuff_t *tvb, guint offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_wai_key_ann_id, tvb, offset, 16, ENC_NA);
}
inline static void
dissect_counter(tvbuff_t *tvb, guint offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_wai_counter, tvb, offset, 16, ENC_NA);
}
inline static void
dissect_authentication_id(tvbuff_t *tvb, guint offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_wai_auth_id, tvb, offset, 32, ENC_NA);
}
static void
dissect_addid(tvbuff_t *tvb, guint offset, proto_tree *tree)
{
proto_item *mac_item;
proto_tree *mac_tree;
mac_item = proto_tree_add_string(tree, hf_wai_addid, tvb, offset, 12, "AE MAC and ASUE MAC addresses");
mac_tree = proto_item_add_subtree(mac_item, ett_wai_mac);
proto_tree_add_item(mac_tree, hf_wai_ae_mac, tvb, offset, 6, ENC_NA);
proto_tree_add_item(mac_tree, hf_wai_asue_mac, tvb, offset+6, 6, ENC_NA);
}
static guint16
dissect_identity(tvbuff_t * tvb, const guint16 offset, proto_tree * tree,
const char * const label)
{
proto_tree *id_tree;
proto_item *id_item;
guint16 length;
length = tvb_get_ntohs(tvb, offset+2);
id_item = proto_tree_add_item(tree, hf_wai_identity, tvb, offset, length+4, ENC_NA);
id_tree = proto_item_add_subtree(id_item, ett_wai_identity);
proto_item_set_text(id_item, "%sIdentity", ((label==NULL)?"":label));
proto_tree_add_item(id_tree, hf_wai_identity_id, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(id_tree, hf_wai_identity_len, tvb, offset+2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(id_tree, hf_wai_identity_data, tvb, offset+4, length, ENC_NA);
return length + 4;
}
static gint16
dissect_certificate(tvbuff_t * tvb, const gint offset, proto_tree * tree,
const gchar * const label)
{
proto_item *certificate_item;
proto_tree *certificate_tree;
proto_item *id_item;
guint16 length;
guint16 id;
const gchar *id_name = "unknown";
id = tvb_get_ntohs(tvb, offset);
if (id == 1) {
id_name = "X.509 v3";
} else if (id == 2){
id_name = "GBW";
}
length = tvb_get_ntohs(tvb, offset+2);
certificate_item = proto_tree_add_item(tree, hf_wai_cert, tvb, offset, length+4, ENC_NA);
proto_item_set_text(certificate_item, "%sCertificate", ((label==NULL)?"":label));
certificate_tree = proto_item_add_subtree(certificate_item, ett_wai_certificate);
id_item = proto_tree_add_item(certificate_tree, hf_wai_cert_id, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_item_set_text(id_item, "Certificate Identifier: %s (%#x)", id_name, id);
proto_tree_add_item(certificate_tree, hf_wai_cert_len, tvb, offset+2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(certificate_tree, hf_wai_cert_data, tvb, offset+4, length, ENC_NA);
return length + 4;
}
static guint16
dissect_ecdh_parameter(tvbuff_t * tvb, const gint offset, proto_tree * tree)
{
proto_item *ecdh_item;
proto_tree *ecdh_tree;
proto_item *ecdh_id_item;
guint8 ecdh_id;
guint16 ecdh_len;
const gchar *id_name = "unknown";
ecdh_id = tvb_get_guint8(tvb, offset);
if (ecdh_id == 1) {
id_name = "OID";
} else if (ecdh_id == 2) {
id_name = "Detailed parameter";
}
ecdh_len = tvb_get_ntohs(tvb, offset+1);
ecdh_item = proto_tree_add_item(tree, hf_wai_ecdh, tvb, offset, ecdh_len+3, ENC_NA);
ecdh_tree = proto_item_add_subtree(ecdh_item, ett_wai_ecdh_param);
ecdh_id_item = proto_tree_add_item(ecdh_tree, hf_wai_ecdh_id, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_item_set_text(ecdh_id_item, "ID: %s (%#x)", id_name, ecdh_id);
proto_tree_add_item(ecdh_tree, hf_wai_ecdh_len, tvb, offset+1, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ecdh_tree, hf_wai_ecdh_content, tvb, offset+3, ecdh_len, ENC_NA);
return ecdh_len + 3;
}
static guint16
dissect_challenge(tvbuff_t *tvb, guint offset, proto_tree *tree, const gchar * const label)
{
proto_item *challenge_item;
const guint16 challenge_length = 32;
challenge_item = proto_tree_add_item(tree, hf_wai_challenge, tvb, offset, 32, ENC_NA);
proto_item_append_text(challenge_item, "(%schallenge)", ((label==NULL)?"":label));
return challenge_length;
}
static guint16
dissect_key_data(tvbuff_t *tvb, guint offset, proto_tree *tree, const gchar *const label)
{
proto_item *key_data_item;
proto_tree *key_data_tree;
guint8 length;
length = tvb_get_guint8(tvb, offset);
key_data_item = proto_tree_add_item(tree, hf_wai_key_data, tvb, offset, length+1, ENC_NA);
proto_item_set_text(key_data_item, "%sKey Data", ((label==NULL)?"":label));
key_data_tree = proto_item_add_subtree(key_data_item, ett_wai_key_data);
proto_tree_add_item(key_data_tree, hf_wai_key_data_len, tvb, offset, 1, ENC_BIG_ENDIAN);
if (length > 0) {
proto_tree_add_item(key_data_tree, hf_wai_key_data_content, tvb, offset+1, length, ENC_NA);
}
return length + 1;
}
static guint
dissect_multiple_certificate(tvbuff_t * tvb, guint offset, proto_tree *tree)
{
proto_item *multicert_item;
proto_tree *multicert_tree;
proto_item *nonce_1_item;
proto_item *nonce_2_item;
guint length;
length = tvb_get_ntohs(tvb, offset+1);
multicert_item = proto_tree_add_item(tree, hf_wai_cert_ver, tvb, offset, length+3, ENC_NA);
multicert_tree = proto_item_add_subtree(multicert_item, ett_wai_certificate_verification);
proto_tree_add_item(multicert_tree, hf_wai_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(multicert_tree, hf_wai_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
nonce_1_item = proto_tree_add_item(multicert_tree, hf_wai_nonce, tvb, offset, 32, ENC_NA);
offset += 32;
proto_item_append_text(nonce_1_item, " 1");
nonce_2_item = proto_tree_add_item(multicert_tree, hf_wai_nonce, tvb, offset, 32, ENC_NA);
offset += 32;
proto_item_append_text(nonce_2_item, " 2");
proto_tree_add_item(multicert_tree, hf_wai_ver_res, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
offset += dissect_certificate(tvb, offset, multicert_tree, "1 ");
proto_tree_add_item(multicert_tree, hf_wai_ver_res, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
offset += dissect_certificate(tvb, offset, multicert_tree, "2 ");
return length + 3;
}
static guint
dissect_identity_list(tvbuff_t *tvb, guint offset, proto_tree *tree)
{
proto_item *id_list_item;
proto_tree *id_list_tree;
guint16 length;
guint16 no_of_ids;
guint16 i;
length = tvb_get_ntohs(tvb, offset+1);
id_list_item = proto_tree_add_item(tree, hf_wai_identity_list, tvb, offset, length+3, ENC_NA);
id_list_tree = proto_item_add_subtree(id_list_item, ett_wai_identity_list);
proto_tree_add_item(id_list_tree, hf_wai_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(id_list_tree, hf_wai_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(id_list_tree, hf_wai_reserved_byte, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(id_list_tree, hf_wai_no_of_ids, tvb, offset, 2, ENC_BIG_ENDIAN);
no_of_ids = tvb_get_ntohs(tvb, offset);
offset += 2;
for(i=0; i < no_of_ids; i++) {
gchar number[4] = {0};
g_snprintf(number, 4, "%d", i);
offset += dissect_identity(tvb, offset, id_list_tree, number);
}
return length + 3;
}
static guint16
dissect_signature_algorithm(tvbuff_t *tvb, guint offset, proto_tree *tree)
{
proto_item *sa_item;
proto_tree *sa_tree;
proto_item *param_item;
proto_tree *param_tree;
proto_item *alg_name_item;
proto_item *sig_name_item;
guint16 length;
guint8 alg_id;
guint8 sig_id;
guint16 param_len;
length = tvb_get_ntohs(tvb, offset);
sa_item = proto_tree_add_item(tree, hf_wai_sign_alg, tvb, offset, length+2, ENC_NA);
sa_tree = proto_item_add_subtree(sa_item, ett_wai_sign_alg);
proto_tree_add_item(sa_tree, hf_wai_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
alg_name_item = proto_tree_add_item(sa_tree, hf_wai_hash_alg_id, tvb, offset, 1, ENC_BIG_ENDIAN);
alg_id = tvb_get_guint8(tvb, offset);
if (1 == alg_id) {
proto_item_set_text(alg_name_item, "Algorithm Idendifier: SHA-256 (0x01)");
}
offset += 1;
sig_name_item = proto_tree_add_item(sa_tree, hf_wai_sign_alg_id, tvb, offset, 1, ENC_BIG_ENDIAN);
sig_id = tvb_get_guint8(tvb, offset);
if (1 == sig_id) {
proto_item_set_text(sig_name_item, "Signature Algorithm Identifier: ECDSA-192 (0x01)");
}
offset += 1;
param_len = tvb_get_ntohs(tvb, offset+1);
param_item = proto_tree_add_item(sa_tree, hf_wai_param, tvb, offset, param_len+3, ENC_NA);
param_tree = proto_item_add_subtree(param_item, ett_wai_parameter);
proto_tree_add_item(param_tree, hf_wai_param_id, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(param_tree, hf_wai_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(param_tree, hf_wai_param_content, tvb, offset, param_len, ENC_NA);
return length + 2;
}
static guint16
dissect_signature_value(tvbuff_t *tvb, guint offset, proto_tree *tree)
{
proto_item *sv_item;
proto_tree *sv_tree;
guint16 length = 0;
length = tvb_get_ntohs(tvb, offset);
sv_item = proto_tree_add_item(tree, hf_wai_sign_val, tvb, offset, length+2, ENC_NA);
sv_tree = proto_item_add_subtree(sv_item, ett_wai_sign_val);
proto_tree_add_item(sv_tree, hf_wai_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(sv_tree, hf_wai_sign_content, tvb, offset, length, ENC_NA);
return length + 2;
}
static guint16
dissect_signature(tvbuff_t *tvb, guint offset, proto_tree *tree, const gchar *const label)
{
proto_item *ss_item;
proto_tree *ss_tree;
guint length = 0;
length = tvb_get_ntohs(tvb, offset+1);
ss_item = proto_tree_add_item(tree, hf_wai_sign, tvb, offset, length+3, ENC_NA);
proto_item_set_text(ss_item, "%s", (label==NULL)?"Signature":label);
ss_tree = proto_item_add_subtree(ss_item, ett_wai_sign);
proto_tree_add_item(ss_tree, hf_wai_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ss_tree, hf_wai_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
offset += dissect_identity(tvb, offset, ss_tree, NULL);
offset += dissect_signature_algorithm(tvb, offset, ss_tree);
offset += dissect_signature_value(tvb, offset, ss_tree);
return length + 3;
}
static void
dissect_wai_data(tvbuff_t *tvb, proto_tree *tree, guint8 subtype, guint16 length)
{
proto_item *data_item;
proto_tree *data_tree;
const gchar *type_name;
data_item = proto_tree_add_item(tree, hf_wai_data, tvb, 0, length, ENC_NA);
data_tree = proto_item_add_subtree (data_item, ett_wai_data);
type_name = val_to_str_const(subtype, wai_subtype_names, "Unknown type");
proto_item_set_text(data_item, "%s data (%d bytes)", type_name, length);
switch (subtype) {
case WAI_SUB_PRE_AUTHENTICATION:
{
dissect_flag(tvb, 0, data_tree);
dissect_uskid(tvb, 1, data_tree);
dissect_addid(tvb, 2, data_tree);
dissect_counter(tvb, 14, data_tree);
dissect_message_auth_code(tvb, 30, data_tree);
break;
}
case WAI_SUB_STAKEY_REQ:
{
dissect_flag(tvb, 0, data_tree);
proto_tree_add_item(data_tree, hf_wai_sta_key_id, tvb, 1, 1, ENC_BIG_ENDIAN);
dissect_uskid(tvb, 2, data_tree);
dissect_addid(tvb, 3, data_tree);
dissect_counter(tvb, 15, data_tree);
dissect_message_auth_code(tvb, 31, data_tree);
break;
}
case WAI_SUB_AUTH_ACTIVATION:
{
guint16 offset = 0;
dissect_flag(tvb, offset, data_tree);
offset++;
dissect_authentication_id(tvb, offset, data_tree);
offset += 32;
offset += dissect_identity(tvb, offset, data_tree, "Local ASU ");
offset += dissect_certificate(tvb, offset, data_tree, "STE AE ");
dissect_ecdh_parameter(tvb, offset, data_tree);
break;
}
case WAI_SUB_ACCESS_AUTH_REQ:
{
guint16 offset = 0;
guint8 optional_field;
optional_field = tvb_get_guint8(tvb, 0) & FLAG_BIT3;
dissect_flag(tvb, offset, data_tree);
offset++;
dissect_authentication_id(tvb, offset, data_tree);
offset += 32;
offset += dissect_challenge(tvb, offset, data_tree, "ASUE ");
offset += dissect_key_data(tvb, offset, data_tree, "ASUE ");
offset += dissect_identity(tvb, offset, data_tree, "STA AE ");
offset += dissect_certificate(tvb, offset, data_tree, "STA ASUE ");
offset += dissect_ecdh_parameter(tvb, offset, data_tree);
if (optional_field) {
offset += dissect_identity_list(tvb, offset, data_tree);
}
dissect_signature(tvb, offset, data_tree, "ASUE Signature");
break;
}
case WAI_SUB_ACCESS_AUTH_RESP:
{
guint16 offset = 0;
guint8 optional_field;
optional_field = tvb_get_guint8(tvb, 0) & FLAG_BIT3;
dissect_flag(tvb, offset, data_tree);
offset++;
offset += dissect_challenge(tvb, offset, data_tree, "ASUE ");
offset += dissect_challenge(tvb, offset, data_tree, "AE ");
proto_tree_add_item(data_tree, hf_wai_access_res, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
offset += dissect_key_data(tvb, offset, data_tree, "ASUE ");
offset += dissect_key_data(tvb, offset, data_tree, "AE ");
offset += dissect_identity(tvb, offset, data_tree, "STA AE ");
offset += dissect_identity(tvb, offset, data_tree, "STA ASUE ");
if (optional_field) {
offset += dissect_multiple_certificate(tvb, offset, data_tree);
}
offset += dissect_signature(tvb, offset, data_tree, "AE Signature");
break;
}
case WAI_SUB_CERT_AUTH_REQ:
{
guint16 offset = 0;
dissect_addid(tvb, offset, data_tree);
offset+=12;
offset += dissect_challenge(tvb, offset, data_tree, "AE ");
offset += dissect_challenge(tvb, offset, data_tree, "ASUE ");
offset += dissect_certificate(tvb, offset, data_tree, "STE ASUE ");
offset += dissect_certificate(tvb, offset, data_tree, "STE AE ");
offset += dissect_multiple_certificate(tvb, offset, data_tree);
break;
}
case WAI_SUB_CERT_AUTH_RESP:
{
guint16 offset = 0;
dissect_addid(tvb, offset, data_tree);
offset += 12;
offset += dissect_multiple_certificate(tvb, offset, data_tree);
offset += dissect_signature(tvb, offset, data_tree, "Server Signature trusted by ASUE");
offset += dissect_signature(tvb, offset, data_tree, "Server Signature trusted by AE");
break;
}
case WAI_SUB_UNICAST_KEY_REQ:
{
dissect_flag(tvb, 0, data_tree);
dissect_bkid(tvb, 1, data_tree);
dissect_uskid(tvb, 17, data_tree);
dissect_addid(tvb, 18, data_tree);
dissect_challenge(tvb, 30, data_tree ,"AE ");
break;
}
case WAI_SUB_UNICAST_KEY_RESP:
{
tvbuff_t *next_tvb;
guint length = 0;
dissect_flag(tvb, 0, data_tree);
dissect_bkid(tvb, 1, data_tree);
dissect_uskid(tvb, 17, data_tree);
dissect_addid(tvb, 18, data_tree);
dissect_challenge(tvb, 30, data_tree, "ASUE ");
dissect_challenge(tvb, 62, data_tree, "AE ");
next_tvb = tvb_new_subset_remaining(tvb, 96);
length = tvb_reported_length(next_tvb);
dissect_wie(next_tvb, 0, length-20, data_tree);
dissect_message_auth_code(next_tvb, length-20, data_tree);
break;
}
case WAI_SUB_UNICAST_KEY_CONFIRM:
{
tvbuff_t *next_tvb;
guint length = 0;
dissect_flag(tvb, 0, data_tree);
dissect_bkid(tvb, 1, data_tree);
dissect_uskid(tvb, 17, data_tree);
dissect_addid(tvb, 18, data_tree);
dissect_challenge(tvb, 30, data_tree, "ASUE ");
next_tvb = tvb_new_subset_remaining(tvb, 62);
length = tvb_reported_length(next_tvb);
dissect_wie(next_tvb, 0, length-20, data_tree);
dissect_message_auth_code(next_tvb, length-20, data_tree);
break;
}
case WAI_SUB_MULTICAST_ANNOUNCE:
{
guint16 offset = 0;
dissect_flag(tvb, offset, data_tree);
offset += 1;
dissect_mskid(tvb, offset, data_tree);
offset += 1;
dissect_uskid(tvb, offset, data_tree);
offset += 1;
dissect_addid(tvb, offset, data_tree);
offset += 12;
proto_tree_add_item(data_tree, hf_wai_data_pack_num, tvb, offset, 16, ENC_NA);
offset += 16;
dissect_key_announcement_identifier(tvb, offset, data_tree);
offset += 16;
offset += dissect_key_data(tvb, offset, data_tree, NULL);
dissect_message_auth_code(tvb, offset, data_tree);
break;
}
case WAI_SUB_MULTICAST_ANNOUNCE_RESP:
{
dissect_flag(tvb, 0, data_tree);
dissect_mskid(tvb, 1, data_tree);
dissect_uskid(tvb, 2, data_tree);
dissect_addid(tvb, 3, data_tree);
dissect_key_announcement_identifier(tvb, 15, data_tree);
dissect_message_auth_code(tvb, 31, data_tree);
break;
}
default:
break;
}
}
static void
dissect_wai(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
#define WAI_MESSAGE_LENGTH 12
#define WAI_DATA_OFFSET WAI_MESSAGE_LENGTH
guint16 version;
guint8 subtype;
guint16 length;
guint16 packet_num;
guint8 fragment_num;
guint8 flags;
fragment_data *frag_msg;
proto_tree *wai_tree = NULL;
tvbuff_t *next_tvb;
tvbuff_t *new_tvb;
const gchar *subtype_name = "Unknown type";
length = tvb_get_ntohs(tvb, 6)-WAI_MESSAGE_LENGTH;
subtype = tvb_get_guint8(tvb, 3);
if ((length != tvb_reported_length (tvb)-WAI_MESSAGE_LENGTH) || (subtype > WAI_SUB_MULTICAST_ANNOUNCE_RESP)) {
return;
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "WAI");
col_clear (pinfo->cinfo, COL_INFO);
version = tvb_get_ntohs(tvb, 0);
if (version == 1) {
subtype_name = val_to_str_const(subtype, wai_subtype_names, "Unknown type");
}
col_append_fstr(pinfo->cinfo, COL_INFO, "%s", subtype_name);
packet_num = tvb_get_ntohs(tvb, 8);
fragment_num = tvb_get_guint8(tvb, 10);
flags = tvb_get_guint8(tvb, 11);
if (tree) {
proto_item *wai_item;
wai_item = proto_tree_add_item(tree, proto_wai, tvb, 0, -1, ENC_NA);
proto_item_set_text (wai_item, "WAI Protocol (%s)",
val_to_str_const(subtype, wai_subtype_names, "Unknown type"));
wai_tree = proto_item_add_subtree(wai_item, ett_wai);
proto_tree_add_item(wai_tree, hf_wai_version, tvb, 0, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(wai_tree, hf_wai_type, tvb, 2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(wai_tree, hf_wai_subtype, tvb, 3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(wai_tree, hf_wai_reserved, tvb, 4, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(wai_tree, hf_wai_length, tvb, 6,2, ENC_BIG_ENDIAN);
proto_tree_add_item(wai_tree, hf_wai_seq, tvb, 8, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(wai_tree, hf_wai_fragm_seq, tvb, 10, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(wai_tree, hf_wai_flag, tvb, 11, 1, ENC_BIG_ENDIAN);
}
frag_msg = fragment_add_seq_check (tvb, WAI_DATA_OFFSET, pinfo,
packet_num,
wai_fragment_table,
wai_reassembled_table,
fragment_num,
length,
flags);
next_tvb = tvb_new_subset_remaining(tvb, WAI_DATA_OFFSET);
if (flags) {
col_add_fstr(pinfo->cinfo, COL_INFO,
"Fragment (%d) of message, data not dissected", fragment_num);
process_reassembled_data(tvb, WAI_DATA_OFFSET, pinfo,
"Reassembled WAI", frag_msg, &wai_frag_items,
NULL, wai_tree);
call_dissector(data_handle, next_tvb, pinfo, tree);
} else {
if (fragment_num > 0) {
new_tvb = process_reassembled_data(tvb, WAI_DATA_OFFSET, pinfo, "Reassembled WAI", frag_msg, &wai_frag_items,
NULL, wai_tree);
if (new_tvb) {
col_add_str(pinfo->cinfo, COL_INFO, "Last fragment of message, data dissected");
col_append_sep_str(pinfo->cinfo, COL_INFO, ": ", subtype_name);
next_tvb=new_tvb;
length = tvb_reported_length (next_tvb);
}
}
if (tree) {
dissect_wai_data(next_tvb, wai_tree, subtype, length);
}
}
}
static void wai_reassemble_init (void)
{
fragment_table_init(&wai_fragment_table);
reassembled_table_init(&wai_reassembled_table);
}
void
proto_register_wai(void)
{
static hf_register_info hf[] = {
{ &hf_wai_version, { "Version", "wai.version", FT_UINT16, BASE_DEC, NULL,
0x0, "Version of authentication infrastructure", HFILL }},
{ &hf_wai_type, { "Type", "wai.type", FT_UINT8, BASE_HEX, VALS(wai_type_names),
0x0, "Protocol type", HFILL }},
{ &hf_wai_subtype, { "Subtype", "wai.subtype", FT_UINT8, BASE_DEC, VALS(wai_subtype_names),
0x0, NULL, HFILL }},
{ &hf_wai_reserved, { "Reserved", "wai.reserved", FT_UINT16, BASE_HEX, NULL,
0x0, NULL, HFILL }},
{ &hf_wai_length, { "Length", "wai.length", FT_UINT16, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_wai_seq, { "Sequence number", "wai.seq", FT_UINT16, BASE_DEC, NULL,
0x0, "Packet sequence number", HFILL }},
{ &hf_wai_fragm_seq, { "Fragment sequence number", "wai.fragm.seq", FT_UINT8, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_wai_flag, { "Flag", "wai.flag", FT_UINT8, BASE_HEX, NULL,
0x0, NULL, HFILL }},
{ &hf_wai_data, { "Data", "wai.data", FT_BYTES, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_wai_bk_rekeying_flag, {"BK rekeying", "wai.bk.rekeying.flag", FT_BOOLEAN, 8, TFS (&wai_bk_rekeying_flag),
FLAG_BIT0, "BK rekeying flag", HFILL }},
{ &hf_wai_preauthentication_flag,{"Pre-Authentication", "wai.preauthentication.flag", FT_BOOLEAN, 8, TFS (&wai_preauthentication_flag),
FLAG_BIT1, "Pre-Authentication flag", HFILL }},
{ &hf_wai_certificate_flag,{"Certificate", "wai.certificate.flag", FT_BOOLEAN, 8, TFS (&wai_certificate_flag),
FLAG_BIT2, "Certificate flag", HFILL }},
{ &hf_wai_optional_flag,{"Optional", "wai.optional.flag", FT_BOOLEAN, 8, TFS (&wai_optional_flag),
FLAG_BIT3, "Optional flag", HFILL }},
{ &hf_wai_usk_rekeying_flag,{"USK rekeying", "wai.usk.rekeying.flag", FT_BOOLEAN, 8, TFS (&wai_usk_rekeying_flag),
FLAG_BIT4, "USK rekeying flag", HFILL }},
{ &hf_wai_negotiation_flag,{"STA negotiation", "wai.negotiation.flag", FT_BOOLEAN, 8, TFS (&wai_negotiation_flag),
FLAG_BIT5, "STA negotiation flag", HFILL }},
{ &hf_wai_revoking_flag,{"STA revoking", "wai.revoking.flag", FT_BOOLEAN, 8, TFS (&wai_revoking_flag),
FLAG_BIT6, "STA revoking flag", HFILL }},
{ &hf_wai_reserved_flag,{"Reserved", "wai.reserved.flag", FT_BOOLEAN, 8, TFS (&wai_reserved_flag),
FLAG_BIT7, "Reserved flag", HFILL }},
{ &hf_wai_cert, {"Certificate", "wai.cert", FT_BYTES, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_wai_cert_id, {"Id", "wai.cert.id", FT_UINT16, BASE_HEX, NULL,
0x0, "Certificate Id", HFILL }},
{ &hf_wai_cert_data, {"Data", "wai.cert.data", FT_BYTES, BASE_NONE, NULL,
0x0, "Certificate data", HFILL }},
{ &hf_wai_cert_len, {"Length", "wai.cert.len", FT_UINT16, BASE_DEC, NULL,
0x0, "Certificate length", HFILL }},
{ &hf_wai_addid, {"ADDID", "wai.addid", FT_STRING, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_wai_ae_mac, {"AE MAC", "wai.ae.mac", FT_ETHER, BASE_NONE, NULL,
0x0, "AE MAC address", HFILL }},
{ &hf_wai_asue_mac, {"ASUE MAC", "wai.asue.mac", FT_ETHER, BASE_NONE, NULL,
0x0, "ASUE MAC address", HFILL }},
{ &hf_wai_bkid, {"BKID", "wai.bkid", FT_BYTES, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_wai_uskid, {"USKID", "wai.uskid", FT_BYTES, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_wai_wie, {"WIE from ASUE", "wai.wie", FT_BYTES, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_wai_message_auth_code, {"Message Authentication Code", "wai.message.auth.code", FT_BYTES, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_wai_mskid, {"MSKID/STAKeyID", "wai.mskid", FT_BYTES, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_wai_data_pack_num, {"Data packet number", "wai.data.packet.num", FT_BYTES, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_wai_key_data, {"Key Data", "wai.key.data", FT_BYTES, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_wai_key_data_len, {"Length", "wai.key.data.len", FT_UINT8, BASE_DEC, NULL,
0x0, "Key data length", HFILL }},
{ &hf_wai_key_data_content, {"Content", "wai.key.data.content", FT_BYTES, BASE_NONE, NULL,
0x0, "Key data content", HFILL }},
{ &hf_wai_key_ann_id, {"Key Announcement Identifier", "wai.key.ann.id", FT_BYTES, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_wai_auth_id, {"Authentication Identifier", "wai.auth.id", FT_BYTES, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_wai_identity, {"Identifier", "wai.identity", FT_BYTES, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_wai_identity_id, {"Id", "wai.identity.id", FT_UINT16, BASE_HEX, NULL,
0x0, NULL, HFILL }},
{ &hf_wai_identity_len, {"Length", "wai.identity.len", FT_UINT16, BASE_DEC, NULL,
0x0, "Identity length", HFILL }},
{ &hf_wai_identity_data, {"Data", "wai.identity.data", FT_BYTES, BASE_NONE, NULL,
0x0, "Identity data", HFILL }},
{ &hf_wai_ecdh, {"ECDH Parameter", "wai.ecdhp", FT_BYTES, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_wai_ecdh_id, {"ID", "wai.edch.id", FT_UINT8, BASE_HEX, NULL,
0x0, "ECDH Parameter Identifier", HFILL }},
{ &hf_wai_ecdh_len, {"Length", "wai.ecdh.len", FT_UINT16, BASE_DEC, NULL,
0x0, "ECDH Parameter Length", HFILL }},
{ &hf_wai_ecdh_content, {"Content", "wai.ecdh.content", FT_BYTES, BASE_NONE, NULL,
0x0, "ECDH Parameter Content", HFILL }},
{ &hf_wai_counter, {"Replay counter", "wai.counter", FT_BYTES, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_wai_sta_key_id, {"STAKeyID", "wai.sta.key.id", FT_UINT8, BASE_HEX, NULL,
0x0, NULL, HFILL }},
{ &hf_wai_challenge, {"Challenge", "wai.challenge", FT_BYTES, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_wai_cert_ver, {"Multiple Certificate Verification Result", "wai.cert.ver", FT_BYTES, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_wai_nonce, {"Nonce", "wai.nonce", FT_BYTES, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_wai_ver_res, {"Verification result", "wai.ver.res", FT_UINT8, BASE_HEX, NULL,
0x0, NULL, HFILL }},
{ &hf_wai_sign_alg, {"Signature Algorithm", "wai.sign.alg", FT_BYTES, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_wai_hash_alg_id, {"Hash Algorithm Identifier", "wai.hash.alg.id", FT_UINT8, BASE_HEX, NULL,
0x0, NULL, HFILL }},
{ &hf_wai_sign_alg_id, {"Signature Algorithm Identifier", "wai.sign.alg.id", FT_UINT8, BASE_HEX, NULL,
0x0, NULL, HFILL }},
{ &hf_wai_param, {"Parameter", "wai.param", FT_BYTES, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_wai_param_id, {"Parameter Identifier", "wai.param.id", FT_BYTES, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_wai_param_content, {"Parameter Content", "wai.param.content", FT_BYTES, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_wai_sign_val, {"Signature Value", "wai.sign.val", FT_BYTES, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_wai_sign_content, {"Signature Content", "wai.sign.content", FT_BYTES, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_wai_sign, {"Signature", "wai.sign", FT_BYTES, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_wai_identity_list, {"ASU List trusted by ASUE", "wai.identity_list", FT_BYTES, BASE_NONE, NULL,
0x0, "Identity list", HFILL }},
{ &hf_wai_reserved_byte, {"Reserved", "wai.reserved.byte", FT_UINT8, BASE_HEX, NULL,
0x0, NULL, HFILL }},
{ &hf_wai_no_of_ids, {"Number of Identities", "wai.no.of.ids", FT_UINT16, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_wai_access_res, {"Access result", "wai.access_result", FT_UINT8, BASE_HEX, NULL,
0x0, NULL, HFILL }},
{ &hf_wai_fragments,{"Message fragments", "wai.fragments",FT_NONE, BASE_NONE, NULL,
0x00, NULL, HFILL }},
{ &hf_wai_fragment,{"Message fragment", "wai.fragment",FT_FRAMENUM, BASE_NONE, NULL,
0x00, NULL, HFILL }},
{ &hf_wai_fragment_overlap,{"Message fragment overlap", "wai.fragment.overlap",FT_BOOLEAN, BASE_NONE, NULL,
0x00, NULL, HFILL }},
{ &hf_wai_fragment_overlap_conflicts,{"Message fragment overlapping with conflicting data","wai.fragment.overlap.conflicts",FT_BOOLEAN, BASE_NONE, NULL,
0x00, NULL, HFILL }},
{ &hf_wai_fragment_multiple_tails,{"Message has multiple tail fragments","wai.fragment.multiple_tails",FT_BOOLEAN, BASE_NONE, NULL,
0x00, NULL, HFILL }},
{ &hf_wai_fragment_too_long_fragment,{"Message fragment too long", "wai.fragment.too_long_fragment",FT_BOOLEAN, BASE_NONE, NULL,
0x00, NULL, HFILL }},
{ &hf_wai_fragment_error,{"Message defragmentation error", "wai.fragment.error",FT_FRAMENUM, BASE_NONE, NULL,
0x00, NULL, HFILL }},
{ &hf_wai_fragment_count,{"Message fragment count", "wai.fragment.count",FT_UINT32, BASE_DEC, NULL,
0x00, NULL, HFILL }},
{ &hf_wai_reassembled_in,{"Reassembled in", "wai.reassembled.in",FT_FRAMENUM, BASE_NONE, NULL,
0x00, NULL, HFILL }},
{ &hf_wai_reassembled_length,{"Reassembled length", "wai.reassembled.length",FT_UINT32, BASE_DEC, NULL,
0x00, NULL, HFILL }}
};
static gint *ett[] = {
&ett_wai,
&ett_wai_data,
&ett_wai_flags,
&ett_wai_certificate,
&ett_wai_mac,
&ett_wai_identity,
&ett_wai_key_data,
&ett_wai_ecdh_param,
&ett_wai_certificate_verification,
&ett_wai_identity_list,
&ett_wai_sign,
&ett_wai_sign_alg,
&ett_wai_sign_val,
&ett_wai_parameter,
&ett_wai_fragment,
&ett_wai_fragments
};
proto_wai = proto_register_protocol("WAI Protocol", "WAI", "wai");
register_init_routine(&wai_reassemble_init);
proto_register_field_array(proto_wai, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("wai", dissect_wai, proto_wai);
}
void
proto_reg_handoff_wai(void)
{
dissector_handle_t wai_handle;
data_handle = find_dissector("data");
wai_handle = find_dissector("wai");
dissector_add_uint("ethertype", ETHERTYPE_WAI, wai_handle);
}
