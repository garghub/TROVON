static const struct mikey_dissector_entry *
mikey_dissector_lookup(const struct mikey_dissector_entry *map, int type)
{
unsigned int i;
for (i = 0; map[i].dissector != NULL; i++) {
if (map[i].type == type) {
return &map[i];
}
}
return NULL;
}
static void
add_next_payload(tvbuff_t *tvb, proto_tree *tree, int offset)
{
proto_tree_add_item(tree, hf_mikey[POS_NEXT_PAYLOAD], tvb, offset, 1, ENC_BIG_ENDIAN);
}
static int
dissect_payload_cs_id_srtp(mikey_t *mikey _U_, tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_item *id_ti;
proto_tree *id_tree;
guint8 no;
guint32 ssrc;
guint32 roc;
tvb_ensure_bytes_exist(tvb, 0, 9);
no = tvb_get_guint8(tvb, 0);
ssrc = tvb_get_ntohl(tvb, 1);
roc = tvb_get_ntohl(tvb, 5);
if (tree) {
id_ti = proto_tree_add_none_format(tree, hf_mikey[POS_ID_SRTP], tvb, 0, 9, "SRTP ID: Policy: %d, SSRC: 0x%x, ROC: 0x%x", no, ssrc, roc);
id_tree = proto_item_add_subtree(id_ti, ett_mikey_hdr_id);
proto_tree_add_item(id_tree, hf_mikey[POS_ID_SRTP_NO], tvb, 0, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(id_tree, hf_mikey[POS_ID_SRTP_SSRC], tvb, 1, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(id_tree, hf_mikey[POS_ID_SRTP_ROC], tvb, 5, 4, ENC_BIG_ENDIAN);
}
return 9;
}
static int
dissect_payload_cs_id(enum cs_id_map_t type, mikey_t *mikey, tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
const struct mikey_dissector_entry *entry;
entry = mikey_dissector_lookup(cs_id_map, type);
if (!entry || !entry->dissector) {
return -1;
}
return entry->dissector(mikey, tvb, pinfo, tree);
}
static int
dissect_payload_hdr(mikey_t *mikey, tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
int offset = 0;
guint8 cs_id_map_type;
guint8 ncs;
int i;
proto_item* parent;
tvb_ensure_bytes_exist(tvb, offset, 10);
mikey->type = tvb_get_guint8(tvb, offset+1);
ncs = tvb_get_guint8(tvb, offset+8);
cs_id_map_type = tvb_get_guint8(tvb, offset+9);
if (tree) {
proto_tree_add_item(tree, hf_mikey[POS_HDR_VERSION],
tvb, offset+0, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_mikey[POS_HDR_DATA_TYPE], tvb, offset+1, 1, ENC_BIG_ENDIAN);
parent = proto_tree_get_parent(tree);
proto_item_append_text(parent, " Type: %s", val_to_str(mikey->type, data_type_vals, "Unknown"));
add_next_payload(tvb, tree, offset+2);
proto_tree_add_item(tree, hf_mikey[POS_HDR_V], tvb, offset+3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_mikey[POS_HDR_PRF_FUNC], tvb, offset+3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_mikey[POS_HDR_CSB_ID], tvb, offset+4, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_mikey[POS_HDR_CS_COUNT], tvb, offset+8, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_mikey[POS_HDR_CS_ID_MAP_TYPE], tvb, offset+9, 1, ENC_BIG_ENDIAN);
}
offset += 10;
for (i=0; i < ncs; i++) {
tvbuff_t *sub_tvb;
int len;
sub_tvb = tvb_new_subset_remaining(tvb, offset);
len = dissect_payload_cs_id(cs_id_map_type, mikey, sub_tvb, pinfo, tree);
if (len < 0)
return -1;
offset += len;
}
return offset;
}
static int
dissect_payload_kemac(mikey_t *mikey, tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
int offset = 0;
guint8 encr_alg;
guint16 encr_length;
guint16 mac_length;
guint8 mac_alg;
proto_item *key_data_item;
proto_tree *key_data_tree;
tvbuff_t *sub_tvb = NULL;
tvb_ensure_bytes_exist(tvb, offset+0, 4);
encr_alg = tvb_get_guint8(tvb, offset+1);
encr_length = tvb_get_ntohs(tvb, offset+2);
tvb_ensure_bytes_exist(tvb, offset+4, encr_length+1);
mac_alg = tvb_get_guint8(tvb, offset+4+encr_length);
if (tree) {
proto_tree_add_item(tree, hf_mikey[POS_KEMAC_ENCR_ALG], tvb, 1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_mikey[POS_KEMAC_ENCR_DATA_LEN], tvb, 2, 2, ENC_BIG_ENDIAN);
if (encr_alg == ENCR_NULL && mikey->type == MIKEY_TYPE_PSK_INIT && encr_length > 0) {
key_data_item = proto_tree_add_item(tree, hf_mikey_pl[PL_KEY_DATA], tvb, 4, encr_length, ENC_NA);
key_data_tree = proto_item_add_subtree(key_data_item, ett_mikey_enc_data);
sub_tvb = tvb_new_subset(tvb, offset+4, encr_length, encr_length);
dissect_payload(PL_KEY_DATA, mikey, sub_tvb, pinfo, key_data_tree);
} else {
proto_tree_add_item(tree, hf_mikey[POS_KEMAC_ENCR_DATA], tvb, 4, encr_length, ENC_NA);
}
proto_tree_add_item(tree, hf_mikey[POS_KEMAC_MAC_ALG], tvb, 4+encr_length, 1, ENC_BIG_ENDIAN);
}
switch (mac_alg) {
case MAC_NULL:
mac_length = 0;
break;
case MAC_HMAC_SHA_1_160:
mac_length = 160/8;
break;
default:
return -1;
}
tvb_ensure_bytes_exist(tvb, offset+4+encr_length+1, mac_length);
if (tree) {
proto_tree_add_item(tree, hf_mikey[POS_KEMAC_MAC], tvb, 4+encr_length+1, mac_length, ENC_NA);
}
return 4+encr_length+1+mac_length;
}
static int
dissect_payload_pke(mikey_t *mikey _U_, tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
int offset = 0;
guint16 length;
tvb_ensure_bytes_exist(tvb, offset+0, 3);
length = ((tvb_get_guint8(tvb, offset+1) & 0x3f) << 8) |
tvb_get_guint8(tvb, offset+2);
if (tree) {
proto_tree_add_item(tree, hf_mikey[POS_PKE_C], tvb, 1, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_mikey[POS_PKE_DATA_LEN], tvb, 1, 2, ENC_BIG_ENDIAN);
}
tvb_ensure_bytes_exist(tvb, offset+3, length);
if (tree) {
proto_tree_add_item(tree, hf_mikey[POS_PKE_DATA], tvb, 3, length, ENC_NA);
}
return 3 + length;
}
static int
dissect_payload_dh(mikey_t *mikey _U_, tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
int offset = 0;
guint8 dh_group;
int dh_length;
guint8 kv;
tvb_ensure_bytes_exist(tvb, offset+0, 2);
dh_group = tvb_get_guint8(tvb, offset+1);
switch (dh_group) {
case DH_OAKLEY_5:
dh_length = 1536/8;
break;
case DH_OAKLEY_1:
dh_length = 768/8;
break;
case DH_OAKLEY_2:
dh_length = 1024/8;
break;
default:
return -1;
}
tvb_ensure_bytes_exist(tvb, offset+2, dh_length+1);
kv = tvb_get_guint8(tvb, offset+2+dh_length) & 0x0f;
if (tree) {
proto_tree_add_item(tree, hf_mikey[POS_DH_GROUP], tvb, 1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_mikey[POS_DH_VALUE], tvb, 2, dh_length, ENC_NA);
proto_tree_add_item(tree, hf_mikey[POS_DH_RESERV], tvb, 2+dh_length, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_mikey[POS_DH_KV], tvb, 2+dh_length, 1, ENC_BIG_ENDIAN);
}
if (kv != 0) {
return -1;
}
return 2+dh_length+1;
}
static int
dissect_payload_sign(mikey_t *mikey _U_, tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
int offset = 0;
guint16 length;
tvb_ensure_bytes_exist(tvb, offset+0, 2);
length = ((tvb_get_guint8(tvb, offset+0) & 0x0f) << 8) + tvb_get_guint8(tvb, offset+1);
if (tree) {
proto_tree_add_item(tree, hf_mikey[POS_SIGN_S_TYPE], tvb, 0, 2, ENC_BIG_ENDIAN);
proto_tree_add_uint(tree, hf_mikey[POS_SIGNATURE_LEN], tvb, 0, 2, length);
}
tvb_ensure_bytes_exist(tvb, offset+2, length);
if (tree) {
proto_tree_add_item(tree, hf_mikey[POS_SIGNATURE], tvb, 2, length, ENC_NA);
}
return 2 + length;
}
static int
dissect_payload_t(mikey_t *mikey _U_, tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
guint8 ts_type;
int offset = 0;
int len = 0;
proto_tree* parent = NULL;
tvb_ensure_bytes_exist(tvb, offset+0, 2);
ts_type = tvb_get_guint8(tvb, offset+1);
if (tree) {
parent = proto_tree_get_parent(tree);
proto_item_append_text(parent, " Type: %s", val_to_str(ts_type, ts_type_vals, "Unknown"));
proto_tree_add_item(tree, hf_mikey[POS_TS_TYPE], tvb, offset+1, 1, ENC_BIG_ENDIAN);
}
switch (ts_type) {
case T_NTP:
case T_NTP_UTC:
proto_tree_add_item(tree, hf_mikey[POS_TS_NTP], tvb, offset+2, 8, ENC_TIME_NTP|ENC_BIG_ENDIAN);
len = 10;
break;
case T_COUNTER:
len = 6;
break;
default:
len = -1;
break;
}
return len;
}
static int
dissect_payload_id(mikey_t *mikey _U_, tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
int offset = 0;
guint8 type;
guint16 length;
proto_item* parent = NULL;
tvb_ensure_bytes_exist(tvb, offset+0, 4);
type = tvb_get_guint8(tvb, offset+1);
length = tvb_get_ntohs(tvb, offset+2);
if (tree) {
proto_tree_add_item(tree, hf_mikey[POS_ID_TYPE], tvb, 1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_mikey[POS_ID_LEN], tvb, 2, 2, ENC_BIG_ENDIAN);
}
tvb_ensure_bytes_exist(tvb, offset+4, length);
if (tree) {
proto_tree_add_item(tree, hf_mikey[POS_ID], tvb, 4, length, ENC_ASCII|ENC_NA);
parent = proto_tree_get_parent(tree);
proto_item_append_text(parent, " %s: %s", val_to_str(type, id_type_vals, "Unknown"), tvb_get_ephemeral_string(tvb, 4, length));
}
return 4 + length;
}
static int
dissect_payload_cert(mikey_t *mikey _U_, tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
int offset = 0;
guint8 type;
guint16 length;
tvbuff_t *subtvb;
proto_item* parent = NULL;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
tvb_ensure_bytes_exist(tvb, offset+0, 4);
type = tvb_get_guint8(tvb, offset+1);
length = tvb_get_ntohs(tvb, offset+2);
tvb_ensure_bytes_exist(tvb, offset+4, length);
if (tree) {
parent = proto_tree_get_parent(tree);
proto_tree_add_item(tree, hf_mikey[POS_CERT_TYPE], tvb, 1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_mikey[POS_CERT_LEN], tvb, 1, 2, ENC_BIG_ENDIAN);
proto_item_append_text(parent, " Type: %s", val_to_str(type, cert_type_vals, "Unknown"));
}
subtvb = tvb_new_subset(tvb, offset+4, length, length);
dissect_x509af_Certificate(FALSE, subtvb, 0, &asn1_ctx, tree, hf_mikey[POS_CERTIFICATE]);
return 4 + length;
}
static int
dissect_payload_v(mikey_t *mikey _U_, tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
int offset = 0;
guint16 length;
guint8 alg;
tvb_ensure_bytes_exist(tvb, offset+0, 2);
alg = tvb_get_guint8(tvb, offset+1);
if (tree) {
proto_tree_add_item(tree, hf_mikey[POS_V_AUTH_ALG], tvb, 1, 1, ENC_BIG_ENDIAN);
}
switch (alg) {
case MAC_NULL:
length = 0;
break;
case MAC_HMAC_SHA_1_160:
length = 160/8;
break;
default:
return -1;
}
tvb_ensure_bytes_exist(tvb, offset+2, length);
if (tree) {
proto_tree_add_item(tree, hf_mikey[POS_V_DATA], tvb, 2, length, ENC_NA);
}
return 2 + length;
}
static int
dissect_payload_sp_param(enum sp_prot_t proto, tvbuff_t *tvb, proto_tree *tree)
{
int offset = 0;
guint8 type;
guint8 length;
proto_item *param_ti;
proto_tree *param_tree;
int hfindex;
tvb_ensure_bytes_exist(tvb, offset+0, 2);
type = tvb_get_guint8(tvb, offset+0);
length = tvb_get_guint8(tvb, offset+1);
tvb_ensure_bytes_exist(tvb, offset+2, length);
hfindex = hf_mikey[POS_SP_PARAM_F];
switch(proto) {
case SP_PROT_TYPE_SRTP:
if (type < array_length(hf_mikey_sp_param))
hfindex = hf_mikey_sp_param[type];
break;
}
if (tree) {
param_ti = proto_tree_add_item(tree, hfindex, tvb, 2, length, ENC_NA);
param_tree = proto_item_add_subtree(param_ti, ett_mikey_sp_param);
proto_tree_add_item(param_tree, hf_mikey[POS_SP_PARAM_F_TYPE], tvb, 0, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(param_tree, hf_mikey[POS_SP_PARAM_F_LEN], tvb, 1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(param_tree, hf_mikey[POS_SP_PARAM_F_VALUE], tvb, 2, length, ENC_NA);
}
return 2+length;
}
static int
dissect_payload_sp(mikey_t *mikey _U_, tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
int offset = 0;
guint16 length;
int sub_pos;
guint8 no;
enum sp_prot_t type;
proto_item* parent = NULL;
tvb_ensure_bytes_exist(tvb, offset+0, 5);
length = tvb_get_ntohs(tvb, offset+3);
no = tvb_get_guint8(tvb, offset+1);
type = tvb_get_guint8(tvb, offset+2);
if (tree) {
parent = proto_tree_get_parent(tree);
proto_tree_add_item(tree, hf_mikey[POS_SP_NO], tvb, 1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_mikey[POS_SP_TYPE], tvb, 2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_mikey[POS_SP_PARAM_LEN], tvb, 3, 2, ENC_BIG_ENDIAN);
proto_item_append_text(parent, " No: %d, Type: %s", no, val_to_str(type, sp_prot_type_vals, "Unknown"));
}
tvb_ensure_bytes_exist(tvb, offset+5, length);
offset += 5;
sub_pos = 0;
while (sub_pos < length) {
int param_len;
tvbuff_t *subtvb;
subtvb = tvb_new_subset(tvb, offset+sub_pos, length-sub_pos, length-sub_pos);
param_len = dissect_payload_sp_param(type, subtvb, tree);
if (param_len < 0)
return -1;
sub_pos += param_len;
}
return 5 + length;
}
static int
dissect_payload_rand(mikey_t *mikey _U_, tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
int offset = 0;
guint16 length;
tvb_ensure_bytes_exist(tvb, offset+0, 2);
length = tvb_get_guint8(tvb, offset+1);
if (tree) {
proto_tree_add_item(tree, hf_mikey[POS_RAND_LEN], tvb, 1, 1, ENC_BIG_ENDIAN);
}
tvb_ensure_bytes_exist(tvb, offset+2, length);
if (tree) {
proto_tree_add_item(tree, hf_mikey[POS_RAND], tvb, 2, length, ENC_NA);
}
return 2 + length;
}
static int
dissect_payload_err(mikey_t *mikey _U_, tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_item *parent = NULL;
guint8 err_no;
tvb_ensure_bytes_exist(tvb, 0, 4);
err_no = tvb_get_guint8(tvb, 1);
if (tree) {
proto_tree_add_item(tree, hf_mikey[POS_ERR_NO], tvb, 1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_mikey[POS_ERR_RESERVED], tvb, 2, 2, ENC_NA);
}
parent = proto_tree_get_parent(tree);
proto_item_append_text(parent, ": %s", val_to_str(err_no, err_vals, "Unknown"));
return 4;
}
static int
dissect_payload_keydata(mikey_t *mikey _U_, tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
guint16 offset;
guint16 data_len;
guint16 salt_len;
guint16 kv_from_len;
guint16 kv_to_len;
guint16 kv_spi_len;
guint8 key_type;
guint8 kv_type;
proto_item *parent = NULL;
offset = 0;
tvb_ensure_bytes_exist(tvb, 0, 4);
key_type = tvb_get_guint8(tvb, 1) >> 4;
kv_type = tvb_get_guint8(tvb, 1) & 0x0f;
data_len = tvb_get_ntohs(tvb, 2);
tvb_ensure_bytes_exist(tvb, 4, data_len);
offset += 4;
if (tree) {
proto_tree_add_item(tree, hf_mikey[POS_KEY_DATA_TYPE], tvb, 1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_mikey[POS_KEY_DATA_KV], tvb, 1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_mikey[POS_KEY_DATA_LEN], tvb, 2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_mikey[POS_KEY_DATA], tvb, 4, data_len, ENC_NA);
parent = proto_tree_get_parent(tree);
proto_item_append_text(parent, " Type: %s", val_to_str(key_type, kd_vals, "Unknown"));
offset += data_len;
if (key_type == KD_TGK_SALT || key_type == KD_TEK_SALT) {
tvb_ensure_bytes_exist(tvb, offset, 2);
salt_len = tvb_get_ntohs(tvb, offset);
if (salt_len>0) {
tvb_ensure_bytes_exist(tvb, offset+2, salt_len);
proto_tree_add_item(tree, hf_mikey[POS_KEY_SALT_LEN], tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_mikey[POS_KEY_SALT], tvb, offset+2, salt_len, ENC_NA);
}
offset += 2+salt_len;
}
if (kv_type == KV_INTERVAL) {
tvb_ensure_bytes_exist(tvb, offset, 1);
kv_from_len = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_mikey[POS_KEY_KV_FROM_LEN], tvb, offset, 1, ENC_BIG_ENDIAN);
if (kv_from_len > 0) {
tvb_ensure_bytes_exist(tvb, offset+1, kv_from_len);
proto_tree_add_item(tree, hf_mikey[POS_KEY_KV_FROM], tvb, offset+1, kv_from_len, ENC_NA);
}
offset += 1+kv_from_len;
tvb_ensure_bytes_exist(tvb, offset, 1);
kv_to_len = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_mikey[POS_KEY_KV_TO_LEN], tvb, offset, 1, ENC_BIG_ENDIAN);
if (kv_to_len > 0) {
tvb_ensure_bytes_exist(tvb, offset+1, kv_to_len);
proto_tree_add_item(tree, hf_mikey[POS_KEY_KV_TO], tvb, offset+1, kv_to_len, ENC_NA);
}
offset += 1+kv_to_len;
} else if (kv_type == KV_SPI) {
tvb_ensure_bytes_exist(tvb, offset, 1);
kv_spi_len = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_mikey[POS_KEY_KV_SPI_LEN], tvb, offset, 1, ENC_BIG_ENDIAN);
if (kv_spi_len > 0) {
tvb_ensure_bytes_exist(tvb, offset+1, kv_spi_len);
proto_tree_add_item(tree, hf_mikey[POS_KEY_KV_SPI], tvb, offset+1, kv_spi_len, ENC_NA);
}
offset += 1+kv_spi_len;
}
}
return offset;
}
static int
dissect_payload_general_ext(mikey_t *mikey _U_, tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_item *parent = NULL;
int offset = 0;
guint8 type;
guint16 data_len;
tvb_ensure_bytes_exist(tvb, offset+0, 4);
type = tvb_get_guint8(tvb, offset+1);
data_len = tvb_get_ntohs(tvb, offset+2);
if (tree) {
proto_tree_add_item(tree, hf_mikey[POS_GENERAL_EXT_TYPE], tvb, 1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_mikey[POS_GENERAL_EXT_LEN], tvb, 2, 2, ENC_BIG_ENDIAN);
}
tvb_ensure_bytes_exist(tvb, offset+3, data_len);
if (tree) {
parent = proto_tree_get_parent(tree);
if (type==1) {
proto_tree_add_item(tree, hf_mikey[POS_GENERAL_EXT_VALUE], tvb, 4, data_len, ENC_ASCII|ENC_NA);
} else {
proto_tree_add_item(tree, hf_mikey[POS_GENERAL_EXT_DATA], tvb, 4, data_len, ENC_NA);
}
proto_item_append_text(parent, " Type: %s", val_to_str(type, genext_type_vals, "Unknown"));
}
return 4 + data_len;
}
static int
dissect_payload(enum payload_t payload, mikey_t *mikey, tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
const struct mikey_dissector_entry *entry;
entry = mikey_dissector_lookup(payload_map, payload);
if (!entry || !entry->dissector) {
return -1;
}
return entry->dissector(mikey, tvb, pinfo, tree);
}
static int
dissect_mikey(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti = NULL;
proto_tree *mikey_tree = NULL;
int offset = 0;
int next_payload_offset;
tvbuff_t *subtvb = NULL;
int payload = -1;
mikey_t *mikey;
mikey = p_get_proto_data(pinfo->fd, proto_mikey);
if (!mikey) {
mikey = se_alloc0(sizeof(mikey_t));
mikey->type = -1;
p_add_proto_data(pinfo->fd, proto_mikey, mikey);
}
tvb_ensure_bytes_exist(tvb, offset, 3);
next_payload_offset = offset+2;
payload = -1;
if (tree) {
ti = proto_tree_add_item(tree, proto_mikey, tvb, 0, -1, ENC_NA);
mikey_tree = proto_item_add_subtree(ti, ett_mikey);
}
while (payload != 0) {
int len;
proto_item *sub_ti = NULL;
proto_tree *mikey_payload_tree = NULL;
int next_payload;
next_payload = tvb_get_guint8(tvb, next_payload_offset);
len = tvb_length_remaining(tvb, offset);
subtvb = tvb_new_subset(tvb, offset, len, len);
if (mikey_tree) {
int hf = payload;
if (hf >= PL_MAX)
return -1;
if (hf == -1)
hf = 0;
sub_ti = proto_tree_add_item(mikey_tree, hf_mikey_pl[hf], subtvb, 0, -1, ENC_NA);
mikey_payload_tree = proto_item_add_subtree(sub_ti, ett_mikey_payload);
if (payload != PL_HDR && payload != PL_SIGN)
add_next_payload(tvb, mikey_payload_tree, next_payload_offset);
}
len = dissect_payload(payload, mikey, subtvb, pinfo, mikey_payload_tree);
if (len < 0) {
return -1;
}
if (sub_ti)
proto_item_set_len(sub_ti, len);
if (payload == PL_SIGN)
break;
payload = next_payload;
offset += len;
next_payload_offset = offset;
}
if (ti) {
proto_item_append_text(ti, ": %s", val_to_str(mikey->type, data_type_vals, "Unknown"));
}
col_append_str(pinfo->cinfo, COL_PROTOCOL, "/MIKEY");
if (check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ", Mikey: %s", val_to_str(mikey->type, data_type_vals, "Unknown"));
return tvb_length(tvb);
}
void
proto_register_mikey(void)
{
static hf_register_info hf[] = {
{ &hf_mikey_pl[PL_HDR+1],
{ PL_HDR_TEXT, "mikey.hdr",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_mikey_pl[PL_KEMAC],
{ PL_KEMAC_TEXT, "mikey.kemac",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_mikey_pl[PL_PKE],
{ PL_PKE_TEXT, "mikey.",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_mikey_pl[PL_DH],
{ PL_DH_TEXT, "mikey.dh",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_mikey_pl[PL_SIGN],
{ PL_SIGN_TEXT, "mikey.sign",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_mikey_pl[PL_T],
{ PL_T_TEXT, "mikey.t",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_mikey_pl[PL_ID],
{ PL_ID_TEXT, "mikey.id",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_mikey_pl[PL_CERT],
{ PL_CERT_TEXT, "mikey.cert",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_mikey_pl[PL_CHASH],
{ PL_CHASH_TEXT, "mikey.chash",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_mikey_pl[PL_V],
{ PL_V_TEXT, "mikey.v",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_mikey_pl[PL_SP],
{ PL_SP_TEXT, "mikey.sp",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_mikey_pl[PL_RAND],
{ PL_RAND_TEXT, "mikey.rand",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_mikey_pl[PL_ERR],
{ PL_ERR_TEXT, "mikey.err",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_mikey_pl[PL_KEY_DATA],
{ PL_KEY_DATA_TEXT, "mikey.key",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_mikey_pl[PL_GENERAL_EXT],
{ PL_GENERAL_EXT_TEXT, "mikey.ext",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_mikey[POS_HDR_VERSION],
{ "Version", "mikey.version",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_mikey[POS_HDR_DATA_TYPE],
{ "Data Type", "mikey.type",
FT_UINT8, BASE_DEC, VALS(data_type_vals), 0x0,
NULL, HFILL }},
{ &hf_mikey[POS_NEXT_PAYLOAD],
{ "Next Payload", "mikey.next_payload",
FT_UINT8, BASE_DEC, VALS(payload_vals), 0x0,
NULL, HFILL }},
{ &hf_mikey[POS_HDR_V],
{ "V", "mikey.v",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), 0x80,
NULL, HFILL }},
{ &hf_mikey[POS_HDR_PRF_FUNC],
{ "PRF func", "mikey.prf_func",
FT_UINT8, BASE_DEC, VALS(prf_func_vals), 0x7f,
NULL, HFILL }},
{ &hf_mikey[POS_HDR_CSB_ID],
{ "CSB ID", "mikey.csb_id",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_mikey[POS_HDR_CS_COUNT],
{ "#CS", "mikey.cs_count",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_mikey[POS_HDR_CS_ID_MAP_TYPE],
{ "CS ID map type", "mikey.cs_id_map_type",
FT_UINT8, BASE_DEC, VALS(cs_id_map_vals), 0x0,
NULL, HFILL }},
{ &hf_mikey[POS_ID_SRTP],
{ "SRTP ID", "mikey.srtp_id",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_mikey[POS_ID_SRTP_NO],
{ "Policy No", "mikey.srtp_id.policy_no",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_mikey[POS_ID_SRTP_SSRC],
{ "SSRC", "mikey.srtp_id.ssrc",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_mikey[POS_ID_SRTP_ROC],
{ "ROC", "mikey.srtp_id.roc",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_mikey[POS_KEMAC_ENCR_ALG],
{ "Encr alg", "mikey.kemac.encr_alg",
FT_UINT8, BASE_DEC, VALS(encr_alg_vals), 0x0,
NULL, HFILL }},
{ &hf_mikey[POS_KEMAC_ENCR_DATA_LEN],
{ "Key data len", "mikey.kemac.key_data_len",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_mikey[POS_KEMAC_ENCR_DATA],
{ "Key data", "mikey.kemac.key_data",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_mikey[POS_KEMAC_MAC_ALG],
{ "Mac alg", "mikey.kemac.mac_alg",
FT_UINT8, BASE_DEC, VALS(mac_alg_vals), 0x0,
NULL, HFILL }},
{ &hf_mikey[POS_KEMAC_MAC],
{ "MAC", "mikey.kemac.mac",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_mikey[POS_PKE_C],
{ "C", "mikey.pke.c",
FT_UINT16, BASE_DEC, VALS(pke_c_vals), 0xc000,
NULL, HFILL }},
{ &hf_mikey[POS_PKE_DATA_LEN],
{ "Data len", "mikey.pke.len",
FT_UINT16, BASE_DEC, NULL, 0x3fff,
NULL, HFILL }},
{ &hf_mikey[POS_PKE_DATA],
{ "Data", "mikey.pke.data",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_mikey[POS_DH_GROUP],
{ "DH-Group", "mikey.dh.group",
FT_UINT8, BASE_DEC, VALS(oakley_vals), 0x0,
NULL, HFILL }},
{ &hf_mikey[POS_DH_VALUE],
{ "DH-Value", "mikey.dh.value",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_mikey[POS_DH_RESERV],
{ "Reserv", "mikey.dh.reserv",
FT_UINT8, BASE_HEX, NULL, 0xf0,
NULL, HFILL }},
{ &hf_mikey[POS_DH_KV],
{ "KV", "mikey.dh.kv",
FT_UINT8, BASE_DEC, VALS(kv_vals), 0x0f,
NULL, HFILL }},
{ &hf_mikey[POS_SIGN_S_TYPE],
{ "Signature type", "mikey.sign.type",
FT_UINT16, BASE_DEC, VALS(sign_s_vals), 0xf000,
NULL, HFILL }},
{ &hf_mikey[POS_SIGNATURE_LEN],
{ "Signature len", "mikey.sign.len",
FT_UINT16, BASE_DEC, NULL, 0x0fff,
NULL, HFILL }},
{ &hf_mikey[POS_SIGNATURE],
{ "Signature", "mikey.sign.data",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_mikey[POS_TS_TYPE],
{ "TS type", "mikey.t.ts_type",
FT_UINT8, BASE_DEC, VALS(ts_type_vals), 0x0,
NULL, HFILL }},
{ &hf_mikey[POS_TS_NTP],
{ "NTP timestamp", "mikey.t.ntp",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_UTC, NULL, 0x0,
NULL, HFILL }},
{ &hf_mikey[POS_PAYLOAD_STR],
{ "Payload", "mikey.payload",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_mikey[POS_ID_TYPE],
{ "ID type", "mikey.id.type",
FT_UINT8, BASE_DEC, VALS(id_type_vals), 0x0,
NULL, HFILL }},
{ &hf_mikey[POS_ID_LEN],
{ "ID len", "mikey.id.len",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_mikey[POS_ID],
{ "ID", "mikey.id.data",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_mikey[POS_CERT_LEN],
{ "Certificate len", "mikey.cert.len",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_mikey[POS_CERT_TYPE],
{ "Certificate type", "mikey.cert.type",
FT_UINT8, BASE_DEC, VALS(cert_type_vals), 0x0,
NULL, HFILL }},
{ &hf_mikey[POS_CERTIFICATE],
{ "Certificate", "mikey.cert.data",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_mikey[POS_V_AUTH_ALG],
{ "Auth alg", "mikey.v.auth_alg",
FT_UINT8, BASE_DEC, VALS(mac_alg_vals), 0x0,
NULL, HFILL }},
{ &hf_mikey[POS_V_DATA],
{ "Ver data", "mikey.v.ver_data",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_mikey[POS_SP_NO],
{ "Policy No", "mikey.sp.no",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_mikey[POS_SP_TYPE],
{ "Protocol type", "mikey.sp.proto_type",
FT_UINT8, BASE_DEC, VALS(sp_prot_type_vals), 0x0,
NULL, HFILL }},
{ &hf_mikey[POS_SP_PARAM_LEN],
{ "Policy param length", "mikey.sp.param_len",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_mikey[POS_SP_PARAM_F],
{ "Policy param", "mikey.sp.param",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_mikey[POS_SP_PARAM_F_TYPE],
{ "Type", "mikey.sp.param.type",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_mikey[POS_SP_PARAM_F_LEN],
{ "Length", "mikey.sp.param.len",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_mikey[POS_SP_PARAM_F_VALUE],
{ "Value", "mikey.sp.patam.value",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_mikey_sp_param[SP_ENCR_ALG],
{ SP_TEXT_ENCR_ALG, "mikey.sp.encr_alg",
FT_UINT8, BASE_DEC, VALS(sp_encr_alg_vals), 0x0,
NULL, HFILL }},
{ &hf_mikey_sp_param[SP_ENCR_LEN],
{ SP_TEXT_ENCR_LEN, "mikey.sp.encr_len",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_mikey_sp_param[SP_AUTH_ALG],
{ SP_TEXT_AUTH_ALG, "mikey.sp.auth_alg",
FT_UINT8, BASE_DEC, VALS(sp_auth_alg_vals), 0x0,
NULL, HFILL }},
{ &hf_mikey_sp_param[SP_AUTH_KEY_LEN],
{ SP_TEXT_AUTH_KEY_LEN, "mikey.sp.auth_key_len",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_mikey_sp_param[SP_SALT_LEN],
{ SP_TEXT_SALT_LEN, "mikey.sp.salt_len",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_mikey_sp_param[SP_PRF],
{ SP_TEXT_PRF, "mikey.sp.prf",
FT_UINT8, BASE_DEC, VALS(sp_prf_vals), 0x0,
NULL, HFILL }},
{ &hf_mikey_sp_param[SP_KD_RATE],
{ SP_TEXT_KD_RATE, "mikey.sp.kd_rate",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_mikey_sp_param[SP_SRTP_ENCR],
{ SP_TEXT_SRTP_ENCR, "mikey.sp.srtp_encr",
FT_UINT8, BASE_DEC, VALS(on_off_vals), 0x0,
NULL, HFILL }},
{ &hf_mikey_sp_param[SP_SRTCP_ENCR],
{ SP_TEXT_SRTCP_ENCR, "mikey.sp.srtcp_encr",
FT_UINT8, BASE_DEC, VALS(on_off_vals), 0x0,
NULL, HFILL }},
{ &hf_mikey_sp_param[SP_FEC],
{ SP_TEXT_FEC, "mikey.sp.fec",
FT_UINT8, BASE_DEC, VALS(sp_fec_vals), 0x0,
NULL, HFILL }},
{ &hf_mikey_sp_param[SP_SRTP_AUTH],
{ SP_TEXT_SRTP_AUTH, "mikey.sp.srtp_auth",
FT_UINT8, BASE_DEC, VALS(on_off_vals), 0x0,
NULL, HFILL }},
{ &hf_mikey_sp_param[SP_AUTH_TAG_LEN],
{ SP_TEXT_AUTH_TAG_LEN, "mikey.sp.auth_tag_len",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_mikey_sp_param[SP_SRTP_PREFIX],
{ SP_TEXT_SRTP_PREFIX, "mikey.sp.srtp_prefix",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_mikey[POS_RAND_LEN],
{ "RAND len", "mikey.rand.len",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_mikey[POS_RAND],
{ "RAND", "mikey.rand.data",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_mikey[POS_ERR_NO],
{ "Error no.", "mikey.err.no",
FT_UINT8, BASE_DEC, VALS(err_vals), 0x0,
NULL, HFILL }},
{ &hf_mikey[POS_ERR_RESERVED],
{ "Reserved", "mikey.err.reserved",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_mikey[POS_KEY_DATA_TYPE],
{ "Type", "mikey.key.type",
FT_UINT8, BASE_DEC, VALS(kd_vals), 0xf0,
NULL, HFILL }},
{ &hf_mikey[POS_KEY_DATA_KV],
{ "KV", "mikey.key.kv",
FT_UINT8, BASE_DEC, VALS(kv_vals), 0x0f,
NULL, HFILL }},
{ &hf_mikey[POS_KEY_DATA_LEN],
{ "Key len", "mikey.key.data.len",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_mikey[POS_KEY_DATA],
{ "Key", "mikey.key.data",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_mikey[POS_KEY_SALT_LEN],
{ "Salt key len", "mikey.key.salt.len",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_mikey[POS_KEY_SALT],
{ "Salt key", "mikey.key.salt",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_mikey[POS_KEY_KV_FROM_LEN],
{ "Valid from len", "mikey.key.kv.from.len",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_mikey[POS_KEY_KV_FROM],
{ "Valid from", "mikey.key.kv.from",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_mikey[POS_KEY_KV_TO_LEN],
{ "Valid to len", "mikey.key.kv.to.len",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_mikey[POS_KEY_KV_TO],
{ "Valid to", "mikey.key.kv.to",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_mikey[POS_KEY_KV_SPI_LEN],
{ "Valid SPI len", "mikey.key.kv.spi.len",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_mikey[POS_KEY_KV_SPI],
{ "Valid SPI", "mikey.key.kv.spi",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_mikey[POS_GENERAL_EXT_TYPE],
{ "Extension type", "mikey.ext.type",
FT_UINT8, BASE_DEC, VALS(genext_type_vals), 0x0,
NULL, HFILL }},
{ &hf_mikey[POS_GENERAL_EXT_LEN],
{ "Length", "mikey.ext.len",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_mikey[POS_GENERAL_EXT_DATA],
{ "Data", "mikey.ext.data",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_mikey[POS_GENERAL_EXT_VALUE],
{ "Value", "mikey.ext.value",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
};
static gint *ett[] = {
&ett_mikey,
&ett_mikey_payload,
&ett_mikey_sp_param,
&ett_mikey_hdr_id,
&ett_mikey_enc_data
};
module_t *mikey_module;
proto_mikey = proto_register_protocol("Multimedia Internet KEYing",
"MIKEY", "mikey");
new_register_dissector("mikey", dissect_mikey, proto_mikey);
proto_register_field_array(proto_mikey, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
mikey_module = prefs_register_protocol(proto_mikey, proto_reg_handoff_mikey);
prefs_register_uint_preference(mikey_module, "udp.port", "MIKEY UDP Port",
"Set the port for MIKEY messages (if other than the default of 2269)",
10, &global_mikey_udp_port);
prefs_register_uint_preference(mikey_module, "tcp.port", "MIKEY TCP Port",
"Set the port for MIKEY messages (if other than the default of 2269)",
10, &global_mikey_tcp_port);
}
void
proto_reg_handoff_mikey(void)
{
static gboolean inited = FALSE;
static dissector_handle_t mikey_handle;
static guint mikey_tcp_port;
static guint mikey_udp_port;
if (!inited) {
mikey_handle = new_create_dissector_handle(dissect_mikey, proto_mikey);
dissector_add_string("key_mgmt", "mikey", mikey_handle);
inited = TRUE;
} else {
dissector_delete_uint("udp.port", mikey_udp_port, mikey_handle);
dissector_delete_uint("tcp.port", mikey_tcp_port, mikey_handle);
}
dissector_add_uint("udp.port", global_mikey_udp_port, mikey_handle);
dissector_add_uint("tcp.port", global_mikey_tcp_port, mikey_handle);
mikey_udp_port = global_mikey_udp_port;
mikey_tcp_port = global_mikey_tcp_port;
}
