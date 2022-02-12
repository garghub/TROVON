static INT
AirPDcapDecryptWPABroadcastKey(const EAPOL_RSN_KEY *pEAPKey, guint8 *decryption_key, PAIRPDCAP_SEC_ASSOCIATION sa, guint eapol_len)
{
guint8 key_version;
guint8 *key_data;
guint8 *szEncryptedKey;
guint16 key_bytes_len = 0;
guint16 key_len;
static AIRPDCAP_KEY_ITEM dummy_key;
AIRPDCAP_SEC_ASSOCIATION *tmp_sa;
key_version = AIRPDCAP_EAP_KEY_DESCR_VER(pEAPKey->key_information[1]);
if (key_version == AIRPDCAP_WPA_KEY_VER_NOT_CCMP){
key_bytes_len = pntoh16(pEAPKey->key_length);
}else if (key_version == AIRPDCAP_WPA_KEY_VER_AES_CCMP){
key_bytes_len = pntoh16(pEAPKey->key_data_len);
if (key_bytes_len < 16) {
return AIRPDCAP_RET_NO_VALID_HANDSHAKE;
}
}
if ((key_bytes_len < GROUP_KEY_MIN_LEN) ||
(eapol_len < sizeof(EAPOL_RSN_KEY)) ||
(key_bytes_len > eapol_len - sizeof(EAPOL_RSN_KEY))) {
return AIRPDCAP_RET_NO_VALID_HANDSHAKE;
}
key_data = (guint8 *)pEAPKey + sizeof(EAPOL_RSN_KEY);
szEncryptedKey = (guint8 *)g_memdup(key_data, key_bytes_len);
DEBUG_DUMP("Encrypted Broadcast key:", szEncryptedKey, key_bytes_len);
DEBUG_DUMP("KeyIV:", pEAPKey->key_iv, 16);
DEBUG_DUMP("decryption_key:", decryption_key, 16);
tmp_sa=(AIRPDCAP_SEC_ASSOCIATION *)g_malloc(sizeof(AIRPDCAP_SEC_ASSOCIATION));
memcpy(tmp_sa, sa, sizeof(AIRPDCAP_SEC_ASSOCIATION));
sa->next=tmp_sa;
if (key_version == AIRPDCAP_WPA_KEY_VER_NOT_CCMP){
guint8 new_key[32];
guint8 dummy[256];
rc4_state_struct rc4_state;
sa->wpa.key_ver = (key_bytes_len >=TKIP_GROUP_KEY_LEN)?AIRPDCAP_WPA_KEY_VER_NOT_CCMP:AIRPDCAP_WPA_KEY_VER_AES_CCMP;
memcpy(new_key, pEAPKey->key_iv, 16);
memcpy(new_key+16, decryption_key, 16);
DEBUG_DUMP("FullDecrKey:", new_key, 32);
crypt_rc4_init(&rc4_state, new_key, sizeof(new_key));
crypt_rc4(&rc4_state, dummy, 256);
crypt_rc4(&rc4_state, szEncryptedKey, key_bytes_len);
} else if (key_version == AIRPDCAP_WPA_KEY_VER_AES_CCMP){
guint8 key_found;
guint8 key_length;
guint16 key_index;
guint8 *decrypted_data;
decrypted_data = AES_unwrap(decryption_key, 16, szEncryptedKey, key_bytes_len);
key_found = FALSE;
key_index = 0;
while(key_index < (key_bytes_len - 6) && !key_found){
guint8 rsn_id;
guint32 type;
rsn_id = decrypted_data[key_index];
type = ((decrypted_data[key_index + 2] << 24) +
(decrypted_data[key_index + 3] << 16) +
(decrypted_data[key_index + 4] << 8) +
(decrypted_data[key_index + 5]));
if (rsn_id == 0xdd && type == 0x000fac01) {
key_found = TRUE;
} else {
key_index += decrypted_data[key_index+1]+2;
}
}
if (key_found){
key_length = decrypted_data[key_index+1] - 6;
if (key_index+8 >= key_bytes_len ||
key_length > key_bytes_len - key_index - 8) {
g_free(decrypted_data);
g_free(szEncryptedKey);
return AIRPDCAP_RET_NO_VALID_HANDSHAKE;
}
memcpy(szEncryptedKey, decrypted_data+key_index+8, key_length);
} else {
g_free(decrypted_data);
g_free(szEncryptedKey);
return AIRPDCAP_RET_NO_VALID_HANDSHAKE;
}
if (key_length == TKIP_GROUP_KEY_LEN)
sa->wpa.key_ver = AIRPDCAP_WPA_KEY_VER_NOT_CCMP;
else
sa->wpa.key_ver = AIRPDCAP_WPA_KEY_VER_AES_CCMP;
g_free(decrypted_data);
}
key_len = (sa->wpa.key_ver==AIRPDCAP_WPA_KEY_VER_NOT_CCMP)?TKIP_GROUP_KEY_LEN:CCMP_GROUP_KEY_LEN;
if (key_len > key_bytes_len) {
g_free(szEncryptedKey);
return AIRPDCAP_RET_NO_VALID_HANDSHAKE;
}
DEBUG_DUMP("Broadcast key:", szEncryptedKey, key_len);
sa->key = &dummy_key;
sa->validKey = TRUE;
memset(sa->wpa.ptk, 0, sizeof(sa->wpa.ptk));
memcpy(sa->wpa.ptk+32, szEncryptedKey, key_len);
g_free(szEncryptedKey);
return AIRPDCAP_RET_SUCCESS_HANDSHAKE;
}
static PAIRPDCAP_SEC_ASSOCIATION
AirPDcapGetSaPtr(
PAIRPDCAP_CONTEXT ctx,
AIRPDCAP_SEC_ASSOCIATION_ID *id)
{
int sa_index;
if ((sa_index=AirPDcapGetSa(ctx, id))==-1) {
if ((sa_index=AirPDcapStoreSa(ctx, id))==-1) {
return NULL;
}
}
return &ctx->sa[sa_index];
}
static INT AirPDcapScanForKeys(
PAIRPDCAP_CONTEXT ctx,
const guint8 *data,
const guint mac_header_len,
const guint tot_len,
AIRPDCAP_SEC_ASSOCIATION_ID id
)
{
const UCHAR *addr;
guint bodyLength;
PAIRPDCAP_SEC_ASSOCIATION sta_sa;
PAIRPDCAP_SEC_ASSOCIATION sa;
guint offset = 0;
const guint8 dot1x_header[] = {
0xAA,
0xAA,
0x03,
0x00, 0x00, 0x00,
0x88, 0x8E
};
const guint8 bt_dot1x_header[] = {
0xAA,
0xAA,
0x03,
0x00, 0x19, 0x58,
0x00, 0x03
};
const guint8 tdls_header[] = {
0xAA,
0xAA,
0x03,
0x00, 0x00, 0x00,
0x89, 0x0D,
0x02,
0X0C
};
const EAPOL_RSN_KEY *pEAPKey;
#ifdef _DEBUG
#define MSGBUF_LEN 255
CHAR msgbuf[MSGBUF_LEN];
#endif
AIRPDCAP_DEBUG_TRACE_START("AirPDcapScanForKeys");
offset = mac_header_len;
if (memcmp(data+offset, dot1x_header, 8) == 0 || memcmp(data+offset, bt_dot1x_header, 8) == 0) {
AIRPDCAP_DEBUG_PRINT_LINE("AirPDcapScanForKeys", "Authentication: EAPOL packet", AIRPDCAP_DEBUG_LEVEL_3);
offset+=8;
if (data[offset+1]!=3) {
AIRPDCAP_DEBUG_PRINT_LINE("AirPDcapScanForKeys", "Not EAPOL-Key", AIRPDCAP_DEBUG_LEVEL_3);
return AIRPDCAP_RET_NO_VALID_HANDSHAKE;
}
bodyLength=pntoh16(data+offset+2);
if (((tot_len-offset-4) < bodyLength) || (bodyLength < sizeof(EAPOL_RSN_KEY))) {
AIRPDCAP_DEBUG_PRINT_LINE("AirPDcapScanForKeys", "EAPOL body too short", AIRPDCAP_DEBUG_LEVEL_3);
return AIRPDCAP_RET_NO_VALID_HANDSHAKE;
}
offset+=4;
pEAPKey = (const EAPOL_RSN_KEY *) (data+offset);
if (
pEAPKey->type != AIRPDCAP_RSN_WPA2_KEY_DESCRIPTOR &&
pEAPKey->type != AIRPDCAP_RSN_WPA_KEY_DESCRIPTOR)
{
AIRPDCAP_DEBUG_PRINT_LINE("AirPDcapScanForKeys", "Not valid key descriptor type", AIRPDCAP_DEBUG_LEVEL_3);
return AIRPDCAP_RET_NO_VALID_HANDSHAKE;
}
offset+=1;
sa = AirPDcapGetSaPtr(ctx, &id);
if (sa == NULL){
AIRPDCAP_DEBUG_PRINT_LINE("AirPDcapScanForKeys", "No SA for BSSID found", AIRPDCAP_DEBUG_LEVEL_3);
return AIRPDCAP_RET_REQ_DATA;
}
if (AirPDcapRsna4WHandshake(ctx, data, sa, offset, tot_len) == AIRPDCAP_RET_SUCCESS_HANDSHAKE)
return AIRPDCAP_RET_SUCCESS_HANDSHAKE;
if (mac_header_len + GROUP_KEY_PAYLOAD_LEN_MIN > tot_len) {
AIRPDCAP_DEBUG_PRINT_LINE("AirPDcapScanForKeys", "Message too short for Group Key", AIRPDCAP_DEBUG_LEVEL_3);
return AIRPDCAP_RET_NO_VALID_HANDSHAKE;
}
if (AIRPDCAP_EAP_KEY(data[offset+1])!=0 ||
AIRPDCAP_EAP_ACK(data[offset+1])!=1 ||
AIRPDCAP_EAP_MIC(data[offset]) != 1 ||
AIRPDCAP_EAP_SEC(data[offset]) != 1){
AIRPDCAP_DEBUG_PRINT_LINE("AirPDcapScanForKeys", "Key bitfields not correct for Group Key", AIRPDCAP_DEBUG_LEVEL_3);
return AIRPDCAP_RET_NO_VALID_HANDSHAKE;
}
memcpy(id.sta, broadcast_mac, AIRPDCAP_MAC_LEN);
sa = AirPDcapGetSaPtr(ctx, &id);
if (sa == NULL){
return AIRPDCAP_RET_REQ_DATA;
}
if ( (addr=AirPDcapGetStaAddress((const AIRPDCAP_MAC_FRAME_ADDR4 *)(data))) != NULL) {
memcpy(id.sta, addr, AIRPDCAP_MAC_LEN);
#ifdef _DEBUG
g_snprintf(msgbuf, MSGBUF_LEN, "ST_MAC: %2X.%2X.%2X.%2X.%2X.%2X\t", id.sta[0],id.sta[1],id.sta[2],id.sta[3],id.sta[4],id.sta[5]);
#endif
AIRPDCAP_DEBUG_PRINT_LINE("AirPDcapScanForKeys", msgbuf, AIRPDCAP_DEBUG_LEVEL_3);
} else {
AIRPDCAP_DEBUG_PRINT_LINE("AirPDcapScanForKeys", "SA not found", AIRPDCAP_DEBUG_LEVEL_5);
return AIRPDCAP_RET_REQ_DATA;
}
sta_sa = AirPDcapGetSaPtr(ctx, &id);
if (sta_sa == NULL){
return AIRPDCAP_RET_REQ_DATA;
}
return (AirPDcapDecryptWPABroadcastKey(pEAPKey, sta_sa->wpa.ptk+16, sa, tot_len-offset+1));
} else if (memcmp(data+offset, tdls_header, 10) == 0) {
const guint8 *initiator, *responder;
guint8 action;
guint status, offset_rsne = 0, offset_fte = 0, offset_link = 0, offset_timeout = 0;
AIRPDCAP_DEBUG_PRINT_LINE("AirPDcapScanForKeys", "Authentication: TDLS Action Frame", AIRPDCAP_DEBUG_LEVEL_3);
offset+=10;
action = data[offset];
if (action!=1 && action!=2) {
AIRPDCAP_DEBUG_PRINT_LINE("AirPDcapScanForKeys", "Not Response nor confirm", AIRPDCAP_DEBUG_LEVEL_3);
return AIRPDCAP_RET_NO_VALID_HANDSHAKE;
}
offset++;
status=pntoh16(data+offset);
if (status!=0) {
AIRPDCAP_DEBUG_PRINT_LINE("AirPDcapScanForKeys", "TDLS setup not successfull", AIRPDCAP_DEBUG_LEVEL_3);
return AIRPDCAP_RET_NO_VALID_HANDSHAKE;
}
offset+=5;
while(offset < (tot_len - 2)) {
if (data[offset] == 48) {
offset_rsne = offset;
} else if (data[offset] == 55) {
offset_fte = offset;
} else if (data[offset] == 56) {
offset_timeout = offset;
} else if (data[offset] == 101) {
offset_link = offset;
}
if (tot_len < offset + data[offset + 1] + 2) {
return AIRPDCAP_RET_NO_VALID_HANDSHAKE;
}
offset += data[offset + 1] + 2;
}
if (offset_rsne == 0 || offset_fte == 0 ||
offset_timeout == 0 || offset_link == 0)
{
AIRPDCAP_DEBUG_PRINT_LINE("AirPDcapScanForKeys", "Cannot Find all necessary IEs", AIRPDCAP_DEBUG_LEVEL_3);
return AIRPDCAP_RET_NO_VALID_HANDSHAKE;
}
AIRPDCAP_DEBUG_PRINT_LINE("AirPDcapScanForKeys", "Found RSNE/Fast BSS/Timeout Interval/Link IEs", AIRPDCAP_DEBUG_LEVEL_3);
initiator = &data[offset_link + 8];
responder = &data[offset_link + 14];
if (memcmp(initiator, responder, AIRPDCAP_MAC_LEN) < 0) {
memcpy(id.sta, initiator, AIRPDCAP_MAC_LEN);
memcpy(id.bssid, responder, AIRPDCAP_MAC_LEN);
} else {
memcpy(id.sta, responder, AIRPDCAP_MAC_LEN);
memcpy(id.bssid, initiator, AIRPDCAP_MAC_LEN);
}
sa = AirPDcapGetSaPtr(ctx, &id);
if (sa == NULL){
return AIRPDCAP_RET_REQ_DATA;
}
if (sa->validKey) {
if (memcmp(sa->wpa.nonce, data + offset_fte + 52, AIRPDCAP_WPA_NONCE_LEN) == 0) {
return AIRPDCAP_RET_SUCCESS_HANDSHAKE;
} else {
AIRPDCAP_SEC_ASSOCIATION *tmp_sa = g_new(AIRPDCAP_SEC_ASSOCIATION, 1);
memcpy(tmp_sa, sa, sizeof(AIRPDCAP_SEC_ASSOCIATION));
sa->next=tmp_sa;
sa->validKey = FALSE;
}
}
if (AirPDcapTDLSDeriveKey(sa, data, offset_rsne, offset_fte, offset_timeout, offset_link, action)
== AIRPDCAP_RET_SUCCESS) {
AIRPDCAP_DEBUG_TRACE_END("AirPDcapScanForKeys");
return AIRPDCAP_RET_SUCCESS_HANDSHAKE;
}
} else {
AIRPDCAP_DEBUG_PRINT_LINE("AirPDcapScanForKeys", "Skipping: not an EAPOL packet", AIRPDCAP_DEBUG_LEVEL_3);
}
AIRPDCAP_DEBUG_TRACE_END("AirPDcapScanForKeys");
return AIRPDCAP_RET_NO_VALID_HANDSHAKE;
}
INT AirPDcapPacketProcess(
PAIRPDCAP_CONTEXT ctx,
const guint8 *data,
const guint mac_header_len,
const guint tot_len,
UCHAR *decrypt_data,
guint *decrypt_len,
PAIRPDCAP_KEY_ITEM key,
gboolean scanHandshake)
{
AIRPDCAP_SEC_ASSOCIATION_ID id;
UCHAR tmp_data[AIRPDCAP_MAX_CAPLEN];
guint tmp_len;
#ifdef _DEBUG
#define MSGBUF_LEN 255
CHAR msgbuf[MSGBUF_LEN];
#endif
AIRPDCAP_DEBUG_TRACE_START("AirPDcapPacketProcess");
if (ctx==NULL) {
AIRPDCAP_DEBUG_PRINT_LINE("AirPDcapPacketProcess", "NULL context", AIRPDCAP_DEBUG_LEVEL_5);
AIRPDCAP_DEBUG_TRACE_END("AirPDcapPacketProcess");
return AIRPDCAP_RET_REQ_DATA;
}
if (data==NULL || tot_len==0) {
AIRPDCAP_DEBUG_PRINT_LINE("AirPDcapPacketProcess", "NULL data or length=0", AIRPDCAP_DEBUG_LEVEL_5);
AIRPDCAP_DEBUG_TRACE_END("AirPDcapPacketProcess");
return AIRPDCAP_RET_REQ_DATA;
}
if (!((AIRPDCAP_TYPE(data[0])==AIRPDCAP_TYPE_DATA) ||
(AIRPDCAP_TYPE(data[0])==AIRPDCAP_TYPE_MANAGEMENT &&
(AIRPDCAP_SUBTYPE(data[0])==AIRPDCAP_SUBTYPE_DISASS ||
AIRPDCAP_SUBTYPE(data[0])==AIRPDCAP_SUBTYPE_DEAUTHENTICATION ||
AIRPDCAP_SUBTYPE(data[0])==AIRPDCAP_SUBTYPE_ACTION)))) {
AIRPDCAP_DEBUG_PRINT_LINE("AirPDcapPacketProcess", "not data nor robust mgmt packet", AIRPDCAP_DEBUG_LEVEL_5);
return AIRPDCAP_RET_NO_DATA;
}
if (tot_len < (UINT)(mac_header_len+AIRPDCAP_CRYPTED_DATA_MINLEN)) {
AIRPDCAP_DEBUG_PRINT_LINE("AirPDcapPacketProcess", "minimum length violated", AIRPDCAP_DEBUG_LEVEL_5);
return AIRPDCAP_RET_WRONG_DATA_SIZE;
}
if (tot_len > AIRPDCAP_MAX_CAPLEN) {
AIRPDCAP_DEBUG_PRINT_LINE("AirPDcapPacketProcess", "length too large", AIRPDCAP_DEBUG_LEVEL_3);
return AIRPDCAP_RET_UNSUCCESS;
}
if (AirPDcapGetSaAddress((const AIRPDCAP_MAC_FRAME_ADDR4 *)(data), &id) != AIRPDCAP_RET_SUCCESS) {
AIRPDCAP_DEBUG_PRINT_LINE("AirPDcapPacketProcess", "STA/BSSID not found", AIRPDCAP_DEBUG_LEVEL_5);
return AIRPDCAP_RET_REQ_DATA;
}
if (AIRPDCAP_WEP(data[1])==0) {
if (scanHandshake) {
AIRPDCAP_DEBUG_PRINT_LINE("AirPDcapPacketProcess", "Unencrypted data", AIRPDCAP_DEBUG_LEVEL_3);
return (AirPDcapScanForKeys(ctx, data, mac_header_len, tot_len, id));
}
return AIRPDCAP_RET_NO_DATA_ENCRYPTED;
} else {
PAIRPDCAP_SEC_ASSOCIATION sa;
int offset = 0;
sa = AirPDcapGetSaPtr(ctx, &id);
if (sa == NULL){
return AIRPDCAP_RET_REQ_DATA;
}
offset = mac_header_len;
if (decrypt_data==NULL) {
AIRPDCAP_DEBUG_PRINT_LINE("AirPDcapPacketProcess", "no decrypt buffer, use local", AIRPDCAP_DEBUG_LEVEL_3);
decrypt_data=tmp_data;
decrypt_len=&tmp_len;
}
*decrypt_len = tot_len;
memcpy(decrypt_data, data, *decrypt_len);
AIRPDCAP_DEBUG_PRINT_LINE("AirPDcapPacketProcess", "Encrypted data", AIRPDCAP_DEBUG_LEVEL_3);
if (AIRPDCAP_EXTIV(data[offset+3])==0) {
AIRPDCAP_DEBUG_PRINT_LINE("AirPDcapPacketProcess", "WEP encryption", AIRPDCAP_DEBUG_LEVEL_3);
return AirPDcapWepMng(ctx, decrypt_data, mac_header_len, decrypt_len, key, sa, offset);
} else {
AIRPDCAP_DEBUG_PRINT_LINE("AirPDcapPacketProcess", "TKIP or CCMP encryption", AIRPDCAP_DEBUG_LEVEL_3);
if (AIRPDCAP_KEY_INDEX(data[offset+3])>=1){
AIRPDCAP_DEBUG_PRINT_LINE("AirPDcapPacketProcess", "The key index >= 1. This is encrypted with a group key.", AIRPDCAP_DEBUG_LEVEL_3);
memcpy(id.sta, broadcast_mac, AIRPDCAP_MAC_LEN);
#ifdef _DEBUG
g_snprintf(msgbuf, MSGBUF_LEN, "ST_MAC: %2X.%2X.%2X.%2X.%2X.%2X\t", id.sta[0],id.sta[1],id.sta[2],id.sta[3],id.sta[4],id.sta[5]);
AIRPDCAP_DEBUG_PRINT_LINE("AirPDcapPacketProcess", msgbuf, AIRPDCAP_DEBUG_LEVEL_3);
#endif
sa = AirPDcapGetSaPtr(ctx, &id);
if (sa == NULL)
return AIRPDCAP_RET_REQ_DATA;
}
if (AirPDcapRsnaMng(decrypt_data, mac_header_len, decrypt_len, key, sa, offset) == AIRPDCAP_RET_SUCCESS) {
if (scanHandshake) {
return (AirPDcapScanForKeys(ctx, decrypt_data, mac_header_len, *decrypt_len, id));
} else {
return AIRPDCAP_RET_SUCCESS;
}
}
}
}
return AIRPDCAP_RET_UNSUCCESS;
}
INT AirPDcapSetKeys(
PAIRPDCAP_CONTEXT ctx,
AIRPDCAP_KEY_ITEM keys[],
const size_t keys_nr)
{
INT i;
INT success;
AIRPDCAP_DEBUG_TRACE_START("AirPDcapSetKeys");
if (ctx==NULL || keys==NULL) {
AIRPDCAP_DEBUG_PRINT_LINE("AirPDcapSetKeys", "NULL context or NULL keys array", AIRPDCAP_DEBUG_LEVEL_3);
AIRPDCAP_DEBUG_TRACE_END("AirPDcapSetKeys");
return 0;
}
if (keys_nr>AIRPDCAP_MAX_KEYS_NR) {
AIRPDCAP_DEBUG_PRINT_LINE("AirPDcapSetKeys", "Keys number greater than maximum", AIRPDCAP_DEBUG_LEVEL_3);
AIRPDCAP_DEBUG_TRACE_END("AirPDcapSetKeys");
return 0;
}
AirPDcapInitContext(ctx);
for (i=0, success=0; i<(INT)keys_nr; i++) {
if (AirPDcapValidateKey(keys+i)==TRUE) {
if (keys[i].KeyType==AIRPDCAP_KEY_TYPE_WPA_PWD) {
AIRPDCAP_DEBUG_PRINT_LINE("AirPDcapSetKeys", "Set a WPA-PWD key", AIRPDCAP_DEBUG_LEVEL_4);
AirPDcapRsnaPwd2Psk(keys[i].UserPwd.Passphrase, keys[i].UserPwd.Ssid, keys[i].UserPwd.SsidLen, keys[i].KeyData.Wpa.Psk);
}
#ifdef _DEBUG
else if (keys[i].KeyType==AIRPDCAP_KEY_TYPE_WPA_PMK) {
AIRPDCAP_DEBUG_PRINT_LINE("AirPDcapSetKeys", "Set a WPA-PMK key", AIRPDCAP_DEBUG_LEVEL_4);
} else if (keys[i].KeyType==AIRPDCAP_KEY_TYPE_WEP) {
AIRPDCAP_DEBUG_PRINT_LINE("AirPDcapSetKeys", "Set a WEP key", AIRPDCAP_DEBUG_LEVEL_4);
} else {
AIRPDCAP_DEBUG_PRINT_LINE("AirPDcapSetKeys", "Set a key", AIRPDCAP_DEBUG_LEVEL_4);
}
#endif
memcpy(&ctx->keys[success], &keys[i], sizeof(keys[i]));
success++;
}
}
ctx->keys_nr=success;
AIRPDCAP_DEBUG_TRACE_END("AirPDcapSetKeys");
return success;
}
static void
AirPDcapCleanKeys(
PAIRPDCAP_CONTEXT ctx)
{
AIRPDCAP_DEBUG_TRACE_START("AirPDcapCleanKeys");
if (ctx==NULL) {
AIRPDCAP_DEBUG_PRINT_LINE("AirPDcapCleanKeys", "NULL context", AIRPDCAP_DEBUG_LEVEL_5);
AIRPDCAP_DEBUG_TRACE_END("AirPDcapCleanKeys");
return;
}
memset(ctx->keys, 0, sizeof(AIRPDCAP_KEY_ITEM) * AIRPDCAP_MAX_KEYS_NR);
ctx->keys_nr=0;
AIRPDCAP_DEBUG_PRINT_LINE("AirPDcapCleanKeys", "Keys collection cleaned!", AIRPDCAP_DEBUG_LEVEL_5);
AIRPDCAP_DEBUG_TRACE_END("AirPDcapCleanKeys");
}
static void
AirPDcapRecurseCleanSA(
PAIRPDCAP_SEC_ASSOCIATION sa)
{
if (sa->next != NULL) {
AirPDcapRecurseCleanSA(sa->next);
g_free(sa->next);
sa->next = NULL;
}
}
static void
AirPDcapCleanSecAssoc(
PAIRPDCAP_CONTEXT ctx)
{
PAIRPDCAP_SEC_ASSOCIATION psa;
int i;
for (psa = ctx->sa, i = 0; i < AIRPDCAP_MAX_SEC_ASSOCIATIONS_NR; i++, psa++) {
AirPDcapRecurseCleanSA(psa);
}
}
INT AirPDcapGetKeys(
const PAIRPDCAP_CONTEXT ctx,
AIRPDCAP_KEY_ITEM keys[],
const size_t keys_nr)
{
UINT i;
UINT j;
AIRPDCAP_DEBUG_TRACE_START("AirPDcapGetKeys");
if (ctx==NULL) {
AIRPDCAP_DEBUG_PRINT_LINE("AirPDcapGetKeys", "NULL context", AIRPDCAP_DEBUG_LEVEL_5);
AIRPDCAP_DEBUG_TRACE_END("AirPDcapGetKeys");
return 0;
} else if (keys==NULL) {
AIRPDCAP_DEBUG_PRINT_LINE("AirPDcapGetKeys", "NULL keys array", AIRPDCAP_DEBUG_LEVEL_5);
AIRPDCAP_DEBUG_TRACE_END("AirPDcapGetKeys");
return (INT)ctx->keys_nr;
} else {
for (i=0, j=0; i<ctx->keys_nr && i<keys_nr && i<AIRPDCAP_MAX_KEYS_NR; i++) {
memcpy(&keys[j], &ctx->keys[i], sizeof(keys[j]));
j++;
AIRPDCAP_DEBUG_PRINT_LINE("AirPDcapGetKeys", "Got a key", AIRPDCAP_DEBUG_LEVEL_5);
}
AIRPDCAP_DEBUG_TRACE_END("AirPDcapGetKeys");
return j;
}
}
INT AirPDcapSetLastSSID(
PAIRPDCAP_CONTEXT ctx,
CHAR *pkt_ssid,
size_t pkt_ssid_len)
{
if (!ctx || !pkt_ssid || pkt_ssid_len < 1 || pkt_ssid_len > WPA_SSID_MAX_SIZE)
return AIRPDCAP_RET_UNSUCCESS;
memcpy(ctx->pkt_ssid, pkt_ssid, pkt_ssid_len);
ctx->pkt_ssid_len = pkt_ssid_len;
return AIRPDCAP_RET_SUCCESS;
}
INT AirPDcapInitContext(
PAIRPDCAP_CONTEXT ctx)
{
AIRPDCAP_DEBUG_TRACE_START("AirPDcapInitContext");
if (ctx==NULL) {
AIRPDCAP_DEBUG_PRINT_LINE("AirPDcapInitContext", "NULL context", AIRPDCAP_DEBUG_LEVEL_5);
AIRPDCAP_DEBUG_TRACE_END("AirPDcapInitContext");
return AIRPDCAP_RET_UNSUCCESS;
}
AirPDcapCleanKeys(ctx);
ctx->first_free_index=0;
ctx->index=-1;
ctx->sa_index=-1;
ctx->pkt_ssid_len = 0;
memset(ctx->sa, 0, AIRPDCAP_MAX_SEC_ASSOCIATIONS_NR * sizeof(AIRPDCAP_SEC_ASSOCIATION));
AIRPDCAP_DEBUG_PRINT_LINE("AirPDcapInitContext", "Context initialized!", AIRPDCAP_DEBUG_LEVEL_5);
AIRPDCAP_DEBUG_TRACE_END("AirPDcapInitContext");
return AIRPDCAP_RET_SUCCESS;
}
INT AirPDcapDestroyContext(
PAIRPDCAP_CONTEXT ctx)
{
AIRPDCAP_DEBUG_TRACE_START("AirPDcapDestroyContext");
if (ctx==NULL) {
AIRPDCAP_DEBUG_PRINT_LINE("AirPDcapDestroyContext", "NULL context", AIRPDCAP_DEBUG_LEVEL_5);
AIRPDCAP_DEBUG_TRACE_END("AirPDcapDestroyContext");
return AIRPDCAP_RET_UNSUCCESS;
}
AirPDcapCleanKeys(ctx);
AirPDcapCleanSecAssoc(ctx);
ctx->first_free_index=0;
ctx->index=-1;
ctx->sa_index=-1;
AIRPDCAP_DEBUG_PRINT_LINE("AirPDcapDestroyContext", "Context destroyed!", AIRPDCAP_DEBUG_LEVEL_5);
AIRPDCAP_DEBUG_TRACE_END("AirPDcapDestroyContext");
return AIRPDCAP_RET_SUCCESS;
}
static INT
AirPDcapRsnaMng(
UCHAR *decrypt_data,
guint mac_header_len,
guint *decrypt_len,
PAIRPDCAP_KEY_ITEM key,
AIRPDCAP_SEC_ASSOCIATION *sa,
INT offset)
{
INT ret_value=1;
UCHAR *try_data;
guint try_data_len = *decrypt_len;
if (*decrypt_len > try_data_len) {
AIRPDCAP_DEBUG_PRINT_LINE("AirPDcapRsnaMng", "Invalid decryption length", AIRPDCAP_DEBUG_LEVEL_3);
return AIRPDCAP_RET_UNSUCCESS;
}
try_data=(UCHAR *)g_malloc(try_data_len);
for(; sa != NULL ;sa=sa->next) {
if (sa->validKey==FALSE) {
AIRPDCAP_DEBUG_PRINT_LINE("AirPDcapRsnaMng", "Key not yet valid", AIRPDCAP_DEBUG_LEVEL_3);
continue;
}
memcpy(try_data, decrypt_data, *decrypt_len);
if (sa->wpa.key_ver==1) {
AIRPDCAP_DEBUG_PRINT_LINE("AirPDcapRsnaMng", "TKIP", AIRPDCAP_DEBUG_LEVEL_3);
DEBUG_DUMP("ptk", sa->wpa.ptk, 64);
DEBUG_DUMP("ptk portion used", AIRPDCAP_GET_TK(sa->wpa.ptk), 16);
ret_value=AirPDcapTkipDecrypt(try_data+offset, *decrypt_len-offset, try_data+AIRPDCAP_TA_OFFSET, AIRPDCAP_GET_TK(sa->wpa.ptk));
if (ret_value){
AIRPDCAP_DEBUG_PRINT_LINE("AirPDcapRsnaMng", "TKIP failed!", AIRPDCAP_DEBUG_LEVEL_3);
continue;
}
AIRPDCAP_DEBUG_PRINT_LINE("AirPDcapRsnaMng", "TKIP DECRYPTED!!!", AIRPDCAP_DEBUG_LEVEL_3);
*decrypt_len-=12;
break;
} else {
AIRPDCAP_DEBUG_PRINT_LINE("AirPDcapRsnaMng", "CCMP", AIRPDCAP_DEBUG_LEVEL_3);
ret_value=AirPDcapCcmpDecrypt(try_data, mac_header_len, (INT)*decrypt_len, AIRPDCAP_GET_TK(sa->wpa.ptk));
if (ret_value)
continue;
AIRPDCAP_DEBUG_PRINT_LINE("AirPDcapRsnaMng", "CCMP DECRYPTED!!!", AIRPDCAP_DEBUG_LEVEL_3);
*decrypt_len-=8;
break;
}
}
if(sa == NULL) {
g_free(try_data);
return ret_value;
}
if (*decrypt_len > try_data_len || *decrypt_len < 8) {
AIRPDCAP_DEBUG_PRINT_LINE("AirPDcapRsnaMng", "Invalid decryption length", AIRPDCAP_DEBUG_LEVEL_3);
g_free(try_data);
return AIRPDCAP_RET_UNSUCCESS;
}
memcpy(decrypt_data, try_data, *decrypt_len);
g_free(try_data);
decrypt_data[1]&=0xBF;
offset = mac_header_len;
*decrypt_len-=8;
memmove(decrypt_data+offset, decrypt_data+offset+8, *decrypt_len-offset);
if (key!=NULL) {
if (sa->key!=NULL)
memcpy(key, sa->key, sizeof(AIRPDCAP_KEY_ITEM));
else
memset(key, 0, sizeof(AIRPDCAP_KEY_ITEM));
memcpy(key->KeyData.Wpa.Ptk, sa->wpa.ptk, AIRPDCAP_WPA_PTK_LEN);
if (sa->wpa.key_ver==AIRPDCAP_WPA_KEY_VER_NOT_CCMP)
key->KeyType=AIRPDCAP_KEY_TYPE_TKIP;
else if (sa->wpa.key_ver==AIRPDCAP_WPA_KEY_VER_AES_CCMP)
key->KeyType=AIRPDCAP_KEY_TYPE_CCMP;
}
return AIRPDCAP_RET_SUCCESS;
}
static INT
AirPDcapWepMng(
PAIRPDCAP_CONTEXT ctx,
UCHAR *decrypt_data,
guint mac_header_len,
guint *decrypt_len,
PAIRPDCAP_KEY_ITEM key,
AIRPDCAP_SEC_ASSOCIATION *sa,
INT offset)
{
UCHAR wep_key[AIRPDCAP_WEP_KEY_MAXLEN+AIRPDCAP_WEP_IVLEN];
size_t keylen;
INT ret_value=1;
INT key_index;
AIRPDCAP_KEY_ITEM *tmp_key;
UINT8 useCache=FALSE;
UCHAR *try_data;
guint try_data_len = *decrypt_len;
try_data = (UCHAR *)g_malloc(try_data_len);
if (sa->key!=NULL)
useCache=TRUE;
for (key_index=0; key_index<(INT)ctx->keys_nr; key_index++) {
if (!useCache) {
tmp_key=&ctx->keys[key_index];
} else {
if (sa->key!=NULL && sa->key->KeyType==AIRPDCAP_KEY_TYPE_WEP) {
AIRPDCAP_DEBUG_PRINT_LINE("AirPDcapWepMng", "Try cached WEP key...", AIRPDCAP_DEBUG_LEVEL_3);
tmp_key=sa->key;
} else {
AIRPDCAP_DEBUG_PRINT_LINE("AirPDcapWepMng", "Cached key is not valid, try another WEP key...", AIRPDCAP_DEBUG_LEVEL_3);
tmp_key=&ctx->keys[key_index];
}
}
if (tmp_key->KeyType==AIRPDCAP_KEY_TYPE_WEP) {
AIRPDCAP_DEBUG_PRINT_LINE("AirPDcapWepMng", "Try WEP key...", AIRPDCAP_DEBUG_LEVEL_3);
memset(wep_key, 0, sizeof(wep_key));
memcpy(try_data, decrypt_data, *decrypt_len);
memcpy(wep_key, try_data+mac_header_len, AIRPDCAP_WEP_IVLEN);
keylen=tmp_key->KeyData.Wep.WepKeyLen;
memcpy(wep_key+AIRPDCAP_WEP_IVLEN, tmp_key->KeyData.Wep.WepKey, keylen);
ret_value=AirPDcapWepDecrypt(wep_key,
keylen+AIRPDCAP_WEP_IVLEN,
try_data + (mac_header_len+AIRPDCAP_WEP_IVLEN+AIRPDCAP_WEP_KIDLEN),
*decrypt_len-(mac_header_len+AIRPDCAP_WEP_IVLEN+AIRPDCAP_WEP_KIDLEN+AIRPDCAP_CRC_LEN));
if (ret_value == AIRPDCAP_RET_SUCCESS)
memcpy(decrypt_data, try_data, *decrypt_len);
}
if (!ret_value && tmp_key->KeyType==AIRPDCAP_KEY_TYPE_WEP) {
sa->key=tmp_key;
if (key!=NULL) {
memcpy(key, sa->key, sizeof(AIRPDCAP_KEY_ITEM));
key->KeyType=AIRPDCAP_KEY_TYPE_WEP;
}
break;
} else {
if (useCache==TRUE) {
useCache=FALSE;
key_index--;
}
}
}
g_free(try_data);
if (ret_value)
return AIRPDCAP_RET_UNSUCCESS;
AIRPDCAP_DEBUG_PRINT_LINE("AirPDcapWepMng", "WEP DECRYPTED!!!", AIRPDCAP_DEBUG_LEVEL_3);
*decrypt_len-=4;
if (*decrypt_len < 4) {
AIRPDCAP_DEBUG_PRINT_LINE("AirPDcapWepMng", "Decryption length too short", AIRPDCAP_DEBUG_LEVEL_3);
return AIRPDCAP_RET_UNSUCCESS;
}
decrypt_data[1]&=0xBF;
offset = mac_header_len;
*decrypt_len-=4;
memmove(decrypt_data+offset, decrypt_data+offset+AIRPDCAP_WEP_IVLEN+AIRPDCAP_WEP_KIDLEN, *decrypt_len-offset);
return AIRPDCAP_RET_SUCCESS;
}
static INT
AirPDcapRsna4WHandshake(
PAIRPDCAP_CONTEXT ctx,
const UCHAR *data,
AIRPDCAP_SEC_ASSOCIATION *sa,
INT offset,
const guint tot_len)
{
AIRPDCAP_KEY_ITEM *tmp_key, *tmp_pkt_key, pkt_key;
AIRPDCAP_SEC_ASSOCIATION *tmp_sa;
INT key_index;
INT ret_value=1;
UCHAR useCache=FALSE;
UCHAR eapol[AIRPDCAP_EAPOL_MAX_LEN];
USHORT eapol_len;
if (sa->key!=NULL)
useCache=TRUE;
if (AIRPDCAP_EAP_KEY(data[offset+1])!=1) {
AIRPDCAP_DEBUG_PRINT_LINE("AirPDcapRsna4WHandshake", "Group/STAKey message (not used)", AIRPDCAP_DEBUG_LEVEL_5);
return AIRPDCAP_RET_NO_VALID_HANDSHAKE;
}
AIRPDCAP_DEBUG_PRINT_LINE("AirPDcapRsna4WHandshake", "4-way handshake...", AIRPDCAP_DEBUG_LEVEL_5);
if (AIRPDCAP_EAP_INST(data[offset+1])==0 &&
AIRPDCAP_EAP_ACK(data[offset+1])==1 &&
AIRPDCAP_EAP_MIC(data[offset])==0)
{
AIRPDCAP_DEBUG_PRINT_LINE("AirPDcapRsna4WHandshake", "4-way handshake message 1", AIRPDCAP_DEBUG_LEVEL_3);
if( sa->handshake >= 2) {
tmp_sa= g_new(AIRPDCAP_SEC_ASSOCIATION, 1);
memcpy(tmp_sa, sa, sizeof(AIRPDCAP_SEC_ASSOCIATION));
sa->validKey=FALSE;
sa->next=tmp_sa;
}
memcpy(sa->wpa.nonce, data+offset+12, 32);
sa->wpa.key_ver=AIRPDCAP_EAP_KEY_DESCR_VER(data[offset+1]);
sa->handshake=1;
return AIRPDCAP_RET_SUCCESS_HANDSHAKE;
}
if (AIRPDCAP_EAP_INST(data[offset+1])==0 &&
AIRPDCAP_EAP_ACK(data[offset+1])==0 &&
AIRPDCAP_EAP_MIC(data[offset])==1)
{
if (pntoh16(data+offset+92)) {
AIRPDCAP_DEBUG_PRINT_LINE("AirPDcapRsna4WHandshake", "4-way handshake message 2", AIRPDCAP_DEBUG_LEVEL_3);
for (key_index=0; key_index<(INT)ctx->keys_nr || useCache; key_index++) {
if (!useCache) {
AIRPDCAP_DEBUG_PRINT_LINE("AirPDcapRsna4WHandshake", "Try WPA key...", AIRPDCAP_DEBUG_LEVEL_3);
tmp_key=&ctx->keys[key_index];
} else {
if (sa->key!=NULL &&
(sa->key->KeyType==AIRPDCAP_KEY_TYPE_WPA_PWD ||
sa->key->KeyType==AIRPDCAP_KEY_TYPE_WPA_PSK ||
sa->key->KeyType==AIRPDCAP_KEY_TYPE_WPA_PMK)) {
AIRPDCAP_DEBUG_PRINT_LINE("AirPDcapRsna4WHandshake", "Try cached WPA key...", AIRPDCAP_DEBUG_LEVEL_3);
tmp_key=sa->key;
} else {
AIRPDCAP_DEBUG_PRINT_LINE("AirPDcapRsna4WHandshake", "Cached key is of a wrong type, try WPA key...", AIRPDCAP_DEBUG_LEVEL_3);
tmp_key=&ctx->keys[key_index];
}
}
if (tmp_key->KeyType==AIRPDCAP_KEY_TYPE_WPA_PWD ||
tmp_key->KeyType==AIRPDCAP_KEY_TYPE_WPA_PSK ||
tmp_key->KeyType==AIRPDCAP_KEY_TYPE_WPA_PMK)
{
if (tmp_key->KeyType == AIRPDCAP_KEY_TYPE_WPA_PWD && tmp_key->UserPwd.SsidLen == 0 && ctx->pkt_ssid_len > 0 && ctx->pkt_ssid_len <= AIRPDCAP_WPA_SSID_MAX_LEN) {
memcpy(&pkt_key, tmp_key, sizeof(pkt_key));
memcpy(&pkt_key.UserPwd.Ssid, ctx->pkt_ssid, ctx->pkt_ssid_len);
pkt_key.UserPwd.SsidLen = ctx->pkt_ssid_len;
AirPDcapRsnaPwd2Psk(pkt_key.UserPwd.Passphrase, pkt_key.UserPwd.Ssid,
pkt_key.UserPwd.SsidLen, pkt_key.KeyData.Wpa.Psk);
tmp_pkt_key = &pkt_key;
} else {
tmp_pkt_key = tmp_key;
}
AirPDcapRsnaPrfX(sa,
tmp_pkt_key->KeyData.Wpa.Psk,
data+offset+12,
512,
sa->wpa.ptk);
eapol_len=pntoh16(data+offset-3)+4;
memcpy(eapol, &data[offset-5], (eapol_len<AIRPDCAP_EAPOL_MAX_LEN?eapol_len:AIRPDCAP_EAPOL_MAX_LEN));
ret_value=AirPDcapRsnaMicCheck(eapol,
eapol_len,
sa->wpa.ptk,
AIRPDCAP_EAP_KEY_DESCR_VER(data[offset+1]));
}
if (!ret_value &&
(tmp_key->KeyType==AIRPDCAP_KEY_TYPE_WPA_PWD ||
tmp_key->KeyType==AIRPDCAP_KEY_TYPE_WPA_PSK ||
tmp_key->KeyType==AIRPDCAP_KEY_TYPE_WPA_PMK))
{
sa->key=tmp_key;
break;
} else {
if (useCache==TRUE) {
useCache=FALSE;
key_index--;
}
}
}
if (ret_value) {
AIRPDCAP_DEBUG_PRINT_LINE("AirPDcapRsna4WHandshake", "handshake step failed", AIRPDCAP_DEBUG_LEVEL_3);
return AIRPDCAP_RET_NO_VALID_HANDSHAKE;
}
sa->handshake=2;
sa->validKey=TRUE;
return AIRPDCAP_RET_SUCCESS_HANDSHAKE;
} else {
AIRPDCAP_DEBUG_PRINT_LINE("AirPDcapRsna4WHandshake", "4-way handshake message 4", AIRPDCAP_DEBUG_LEVEL_3);
sa->handshake=4;
return AIRPDCAP_RET_SUCCESS_HANDSHAKE;
}
}
if (AIRPDCAP_EAP_ACK(data[offset+1])==1 &&
AIRPDCAP_EAP_MIC(data[offset])==1)
{
const EAPOL_RSN_KEY *pEAPKey;
AIRPDCAP_DEBUG_PRINT_LINE("AirPDcapRsna4WHandshake", "4-way handshake message 3", AIRPDCAP_DEBUG_LEVEL_3);
pEAPKey = (const EAPOL_RSN_KEY *)(&(data[offset-1]));
if (pEAPKey->type == AIRPDCAP_RSN_WPA2_KEY_DESCRIPTOR){
PAIRPDCAP_SEC_ASSOCIATION broadcast_sa;
AIRPDCAP_SEC_ASSOCIATION_ID id;
memcpy(id.sta, broadcast_mac, AIRPDCAP_MAC_LEN);
memcpy(id.bssid, sa->saId.bssid, AIRPDCAP_MAC_LEN);
broadcast_sa = AirPDcapGetSaPtr(ctx, &id);
if (broadcast_sa == NULL){
return AIRPDCAP_RET_REQ_DATA;
}
return (AirPDcapDecryptWPABroadcastKey(pEAPKey, sa->wpa.ptk+16, broadcast_sa, tot_len-offset+1));
}
}
return AIRPDCAP_RET_NO_VALID_HANDSHAKE;
}
static INT
AirPDcapRsnaMicCheck(
UCHAR *eapol,
USHORT eapol_len,
UCHAR KCK[AIRPDCAP_WPA_KCK_LEN],
USHORT key_ver)
{
UCHAR mic[AIRPDCAP_WPA_MICKEY_LEN];
UCHAR c_mic[20];
memcpy(mic, eapol+AIRPDCAP_WPA_MICKEY_OFFSET+4, AIRPDCAP_WPA_MICKEY_LEN);
memset(eapol+AIRPDCAP_WPA_MICKEY_OFFSET+4, 0, AIRPDCAP_WPA_MICKEY_LEN);
if (key_ver==AIRPDCAP_WPA_KEY_VER_NOT_CCMP) {
md5_hmac(eapol, eapol_len, KCK, AIRPDCAP_WPA_KCK_LEN, c_mic);
} else if (key_ver==AIRPDCAP_WPA_KEY_VER_AES_CCMP) {
sha1_hmac(KCK, AIRPDCAP_WPA_KCK_LEN, eapol, eapol_len, c_mic);
} else
return AIRPDCAP_RET_UNSUCCESS;
return memcmp(mic, c_mic, AIRPDCAP_WPA_MICKEY_LEN);
}
static INT
AirPDcapValidateKey(
PAIRPDCAP_KEY_ITEM key)
{
size_t len;
UCHAR ret=TRUE;
AIRPDCAP_DEBUG_TRACE_START("AirPDcapValidateKey");
if (key==NULL) {
AIRPDCAP_DEBUG_PRINT_LINE("AirPDcapValidateKey", "NULL key", AIRPDCAP_DEBUG_LEVEL_5);
AIRPDCAP_DEBUG_TRACE_START("AirPDcapValidateKey");
return FALSE;
}
switch (key->KeyType) {
case AIRPDCAP_KEY_TYPE_WEP:
len=key->KeyData.Wep.WepKeyLen;
if (len<AIRPDCAP_WEP_KEY_MINLEN || len>AIRPDCAP_WEP_KEY_MAXLEN) {
AIRPDCAP_DEBUG_PRINT_LINE("AirPDcapValidateKey", "WEP key: key length not accepted", AIRPDCAP_DEBUG_LEVEL_5);
ret=FALSE;
}
break;
case AIRPDCAP_KEY_TYPE_WEP_40:
key->KeyData.Wep.WepKeyLen=AIRPDCAP_WEP_40_KEY_LEN;
key->KeyType=AIRPDCAP_KEY_TYPE_WEP;
break;
case AIRPDCAP_KEY_TYPE_WEP_104:
key->KeyData.Wep.WepKeyLen=AIRPDCAP_WEP_104_KEY_LEN;
key->KeyType=AIRPDCAP_KEY_TYPE_WEP;
break;
case AIRPDCAP_KEY_TYPE_WPA_PWD:
len=strlen(key->UserPwd.Passphrase);
if (len<AIRPDCAP_WPA_PASSPHRASE_MIN_LEN || len>AIRPDCAP_WPA_PASSPHRASE_MAX_LEN) {
AIRPDCAP_DEBUG_PRINT_LINE("AirPDcapValidateKey", "WPA-PWD key: passphrase length not accepted", AIRPDCAP_DEBUG_LEVEL_5);
ret=FALSE;
}
len=key->UserPwd.SsidLen;
if (len>AIRPDCAP_WPA_SSID_MAX_LEN) {
AIRPDCAP_DEBUG_PRINT_LINE("AirPDcapValidateKey", "WPA-PWD key: ssid length not accepted", AIRPDCAP_DEBUG_LEVEL_5);
ret=FALSE;
}
break;
case AIRPDCAP_KEY_TYPE_WPA_PSK:
break;
case AIRPDCAP_KEY_TYPE_WPA_PMK:
break;
default:
ret=FALSE;
}
AIRPDCAP_DEBUG_TRACE_END("AirPDcapValidateKey");
return ret;
}
static INT
AirPDcapGetSa(
PAIRPDCAP_CONTEXT ctx,
AIRPDCAP_SEC_ASSOCIATION_ID *id)
{
INT sa_index;
if (ctx->sa_index!=-1) {
for (sa_index=ctx->sa_index; sa_index>=0; sa_index--) {
if (ctx->sa[sa_index].used) {
if (memcmp(id, &(ctx->sa[sa_index].saId), sizeof(AIRPDCAP_SEC_ASSOCIATION_ID))==0) {
ctx->index=sa_index;
return sa_index;
}
}
}
}
return -1;
}
static INT
AirPDcapStoreSa(
PAIRPDCAP_CONTEXT ctx,
AIRPDCAP_SEC_ASSOCIATION_ID *id)
{
INT last_free;
if (ctx->first_free_index>=AIRPDCAP_MAX_SEC_ASSOCIATIONS_NR) {
return -1;
}
if (ctx->sa[ctx->first_free_index].used) {
for (last_free=ctx->first_free_index; last_free<AIRPDCAP_MAX_SEC_ASSOCIATIONS_NR; last_free++)
if (!ctx->sa[last_free].used)
break;
if (last_free>=AIRPDCAP_MAX_SEC_ASSOCIATIONS_NR) {
return -1;
}
ctx->first_free_index=last_free;
}
ctx->index=ctx->first_free_index;
memset(ctx->sa+ctx->index, 0, sizeof(AIRPDCAP_SEC_ASSOCIATION));
ctx->sa[ctx->index].used=1;
memcpy(&(ctx->sa[ctx->index].saId), id, sizeof(AIRPDCAP_SEC_ASSOCIATION_ID));
ctx->first_free_index++;
if (ctx->index > ctx->sa_index)
ctx->sa_index=ctx->index;
return ctx->index;
}
static INT
AirPDcapGetSaAddress(
const AIRPDCAP_MAC_FRAME_ADDR4 *frame,
AIRPDCAP_SEC_ASSOCIATION_ID *id)
{
#ifdef _DEBUG
#define MSGBUF_LEN 255
CHAR msgbuf[MSGBUF_LEN];
#endif
if ((AIRPDCAP_TYPE(frame->fc[0])==AIRPDCAP_TYPE_DATA) &&
(AIRPDCAP_DS_BITS(frame->fc[1]) == 0) &&
(memcmp(frame->addr2, frame->addr3, AIRPDCAP_MAC_LEN) != 0) &&
(memcmp(frame->addr1, frame->addr3, AIRPDCAP_MAC_LEN) != 0)) {
if (memcmp(frame->addr1, frame->addr2, AIRPDCAP_MAC_LEN) < 0) {
memcpy(id->sta, frame->addr1, AIRPDCAP_MAC_LEN);
memcpy(id->bssid, frame->addr2, AIRPDCAP_MAC_LEN);
} else {
memcpy(id->sta, frame->addr2, AIRPDCAP_MAC_LEN);
memcpy(id->bssid, frame->addr1, AIRPDCAP_MAC_LEN);
}
} else {
const UCHAR *addr;
if ((addr = AirPDcapGetBssidAddress(frame)) != NULL) {
memcpy(id->bssid, addr, AIRPDCAP_MAC_LEN);
} else {
return AIRPDCAP_RET_UNSUCCESS;
}
if ((addr = AirPDcapGetStaAddress(frame)) != NULL) {
memcpy(id->sta, addr, AIRPDCAP_MAC_LEN);
} else {
return AIRPDCAP_RET_UNSUCCESS;
}
}
#ifdef _DEBUG
g_snprintf(msgbuf, MSGBUF_LEN, "BSSID_MAC: %02X.%02X.%02X.%02X.%02X.%02X\t",
id->bssid[0],id->bssid[1],id->bssid[2],id->bssid[3],id->bssid[4],id->bssid[5]);
AIRPDCAP_DEBUG_PRINT_LINE("AirPDcapGetSaAddress", msgbuf, AIRPDCAP_DEBUG_LEVEL_3);
g_snprintf(msgbuf, MSGBUF_LEN, "STA_MAC: %02X.%02X.%02X.%02X.%02X.%02X\t",
id->sta[0],id->sta[1],id->sta[2],id->sta[3],id->sta[4],id->sta[5]);
AIRPDCAP_DEBUG_PRINT_LINE("AirPDcapGetSaAddress", msgbuf, AIRPDCAP_DEBUG_LEVEL_3);
#endif
return AIRPDCAP_RET_SUCCESS;
}
static const UCHAR *
AirPDcapGetStaAddress(
const AIRPDCAP_MAC_FRAME_ADDR4 *frame)
{
switch(AIRPDCAP_DS_BITS(frame->fc[1])) {
case 0:
if (memcmp(frame->addr2, frame->addr3, AIRPDCAP_MAC_LEN) == 0)
return frame->addr1;
else
return frame->addr2;
case 1:
return frame->addr2;
case 2:
return frame->addr1;
case 3:
if (memcmp(frame->addr1, frame->addr2, AIRPDCAP_MAC_LEN) < 0)
return frame->addr1;
else
return frame->addr2;
default:
return NULL;
}
}
static const UCHAR *
AirPDcapGetBssidAddress(
const AIRPDCAP_MAC_FRAME_ADDR4 *frame)
{
switch(AIRPDCAP_DS_BITS(frame->fc[1])) {
case 0:
return frame->addr3;
case 1:
return frame->addr1;
case 2:
return frame->addr2;
case 3:
if (memcmp(frame->addr1, frame->addr2, AIRPDCAP_MAC_LEN) > 0)
return frame->addr1;
else
return frame->addr2;
default:
return NULL;
}
}
static void
AirPDcapRsnaPrfX(
AIRPDCAP_SEC_ASSOCIATION *sa,
const UCHAR pmk[32],
const UCHAR snonce[32],
const INT x,
UCHAR *ptk)
{
UINT8 i;
UCHAR R[100];
INT offset=sizeof("Pairwise key expansion");
UCHAR output[80];
memset(R, 0, 100);
memcpy(R, "Pairwise key expansion", offset);
if (memcmp(sa->saId.sta, sa->saId.bssid, AIRPDCAP_MAC_LEN) < 0)
{
memcpy(R + offset, sa->saId.sta, AIRPDCAP_MAC_LEN);
memcpy(R + offset+AIRPDCAP_MAC_LEN, sa->saId.bssid, AIRPDCAP_MAC_LEN);
}
else
{
memcpy(R + offset, sa->saId.bssid, AIRPDCAP_MAC_LEN);
memcpy(R + offset+AIRPDCAP_MAC_LEN, sa->saId.sta, AIRPDCAP_MAC_LEN);
}
offset+=AIRPDCAP_MAC_LEN*2;
if( memcmp(snonce, sa->wpa.nonce, 32) < 0 )
{
memcpy(R + offset, snonce, 32);
memcpy(R + offset + 32, sa->wpa.nonce, 32);
}
else
{
memcpy(R + offset, sa->wpa.nonce, 32);
memcpy(R + offset + 32, snonce, 32);
}
offset+=32*2;
for(i = 0; i < (x+159)/160; i++)
{
R[offset] = i;
sha1_hmac(pmk, 32, R, 100, &output[20 * i]);
}
memcpy(ptk, output, x/8);
}
static INT
AirPDcapRsnaPwd2PskStep(
const guint8 *ppBytes,
const guint ppLength,
const CHAR *ssid,
const size_t ssidLength,
const INT iterations,
const INT count,
UCHAR *output)
{
UCHAR digest[MAX_SSID_LENGTH+4];
UCHAR digest1[SHA1_DIGEST_LEN];
INT i, j;
if (ssidLength > MAX_SSID_LENGTH) {
return AIRPDCAP_RET_UNSUCCESS;
}
memset(digest, 0, sizeof digest);
memset(digest1, 0, sizeof digest1);
memcpy(digest, ssid, ssidLength);
digest[ssidLength] = (UCHAR)((count>>24) & 0xff);
digest[ssidLength+1] = (UCHAR)((count>>16) & 0xff);
digest[ssidLength+2] = (UCHAR)((count>>8) & 0xff);
digest[ssidLength+3] = (UCHAR)(count & 0xff);
sha1_hmac(ppBytes, ppLength, digest, (guint32) ssidLength+4, digest1);
memcpy(output, digest1, SHA1_DIGEST_LEN);
for (i = 1; i < iterations; i++) {
sha1_hmac(ppBytes, ppLength, digest1, SHA1_DIGEST_LEN, digest);
memcpy(digest1, digest, SHA1_DIGEST_LEN);
for (j = 0; j < SHA1_DIGEST_LEN; j++) {
output[j] ^= digest[j];
}
}
return AIRPDCAP_RET_SUCCESS;
}
static INT
AirPDcapRsnaPwd2Psk(
const CHAR *passphrase,
const CHAR *ssid,
const size_t ssidLength,
UCHAR *output)
{
UCHAR m_output[2*SHA1_DIGEST_LEN];
GByteArray *pp_ba = g_byte_array_new();
memset(m_output, 0, 2*SHA1_DIGEST_LEN);
if (!uri_str_to_bytes(passphrase, pp_ba)) {
g_byte_array_free(pp_ba, TRUE);
return 0;
}
AirPDcapRsnaPwd2PskStep(pp_ba->data, pp_ba->len, ssid, ssidLength, 4096, 1, m_output);
AirPDcapRsnaPwd2PskStep(pp_ba->data, pp_ba->len, ssid, ssidLength, 4096, 2, &m_output[SHA1_DIGEST_LEN]);
memcpy(output, m_output, AIRPDCAP_WPA_PSK_LEN);
g_byte_array_free(pp_ba, TRUE);
return 0;
}
decryption_key_t*
parse_key_string(gchar* input_string, guint8 key_type)
{
gchar *key, *tmp_str;
gchar *ssid;
GString *key_string = NULL;
GByteArray *ssid_ba = NULL, *key_ba;
gboolean res;
gchar **tokens;
guint n = 0;
decryption_key_t *dk;
if(input_string == NULL)
return NULL;
switch(key_type)
{
case AIRPDCAP_KEY_TYPE_WEP:
case AIRPDCAP_KEY_TYPE_WEP_40:
case AIRPDCAP_KEY_TYPE_WEP_104:
key_ba = g_byte_array_new();
res = hex_str_to_bytes(input_string, key_ba, FALSE);
if (res && key_ba->len > 0) {
dk = (decryption_key_t *)g_malloc(sizeof(decryption_key_t));
dk->type = AIRPDCAP_KEY_TYPE_WEP;
tmp_str = bytes_to_str(NULL, key_ba->data, key_ba->len);
dk->key = g_string_new(tmp_str);
g_string_ascii_down(dk->key);
dk->bits = key_ba->len * 8;
dk->ssid = NULL;
wmem_free(NULL, tmp_str);
g_byte_array_free(key_ba, TRUE);
return dk;
}
g_byte_array_free(key_ba, TRUE);
return NULL;
case AIRPDCAP_KEY_TYPE_WPA_PWD:
tokens = g_strsplit(input_string,":",0);
while(tokens[n] != NULL)
n++;
if(n < 1)
{
g_strfreev(tokens);
return NULL;
}
key = g_strdup(tokens[0]);
ssid = NULL;
if(n >= 2)
{
ssid = g_strdup(tokens[1]);
}
key_string = g_string_new(key);
ssid_ba = NULL;
if( ((key_string->len) > WPA_KEY_MAX_CHAR_SIZE) || ((key_string->len) < WPA_KEY_MIN_CHAR_SIZE))
{
g_string_free(key_string, TRUE);
g_free(key);
g_free(ssid);
g_strfreev(tokens);
return NULL;
}
if(ssid != NULL)
{
ssid_ba = g_byte_array_new();
if (! uri_str_to_bytes(ssid, ssid_ba)) {
g_string_free(key_string, TRUE);
g_byte_array_free(ssid_ba, TRUE);
g_free(key);
g_free(ssid);
g_strfreev(tokens);
return NULL;
}
if(ssid_ba->len > WPA_SSID_MAX_CHAR_SIZE)
{
g_string_free(key_string, TRUE);
g_byte_array_free(ssid_ba, TRUE);
g_free(key);
g_free(ssid);
g_strfreev(tokens);
return NULL;
}
}
dk = (decryption_key_t*)g_malloc(sizeof(decryption_key_t));
dk->type = AIRPDCAP_KEY_TYPE_WPA_PWD;
dk->key = g_string_new(key);
dk->bits = 256;
dk->ssid = byte_array_dup(ssid_ba);
g_string_free(key_string, TRUE);
if (ssid_ba != NULL)
g_byte_array_free(ssid_ba, TRUE);
g_free(key);
if(ssid != NULL)
g_free(ssid);
g_strfreev(tokens);
return dk;
case AIRPDCAP_KEY_TYPE_WPA_PSK:
key_ba = g_byte_array_new();
res = hex_str_to_bytes(input_string, key_ba, FALSE);
if(!res || ((key_ba->len) != WPA_PSK_KEY_SIZE))
{
g_byte_array_free(key_ba, TRUE);
return NULL;
}
dk = (decryption_key_t*)g_malloc(sizeof(decryption_key_t));
dk->type = AIRPDCAP_KEY_TYPE_WPA_PSK;
dk->key = g_string_new(input_string);
dk->bits = (guint) dk->key->len * 4;
dk->ssid = NULL;
g_byte_array_free(key_ba, TRUE);
return dk;
}
return NULL;
}
void
free_key_string(decryption_key_t *dk)
{
if (dk->key)
g_string_free(dk->key, TRUE);
if (dk->ssid)
g_byte_array_free(dk->ssid, TRUE);
g_free(dk);
}
gchar*
get_key_string(decryption_key_t* dk)
{
gchar* output_string = NULL;
if(dk == NULL || dk->key == NULL)
return NULL;
switch(dk->type) {
case AIRPDCAP_KEY_TYPE_WEP:
output_string = g_strdup(dk->key->str);
break;
case AIRPDCAP_KEY_TYPE_WPA_PWD:
if(dk->ssid == NULL)
output_string = g_strdup(dk->key->str);
else
output_string = g_strdup_printf("%s:%s",
dk->key->str, format_uri(dk->ssid, ":"));
break;
case AIRPDCAP_KEY_TYPE_WPA_PMK:
output_string = g_strdup(dk->key->str);
break;
default:
return NULL;
}
return output_string;
}
static INT
AirPDcapTDLSDeriveKey(
PAIRPDCAP_SEC_ASSOCIATION sa,
const guint8 *data,
guint offset_rsne,
guint offset_fte,
guint offset_timeout,
guint offset_link,
guint8 action)
{
sha256_hmac_context sha_ctx;
aes_cmac_ctx aes_ctx;
const guint8 *snonce, *anonce, *initiator, *responder, *bssid;
guint8 key_input[SHA256_DIGEST_LEN];
guint8 mic[16], iter[2], length[2], seq_num = action + 1;
anonce = &data[offset_fte + 20];
snonce = &data[offset_fte + 52];
sha256_starts(&(sha_ctx.ctx));
if (memcmp(anonce, snonce, AIRPDCAP_WPA_NONCE_LEN) < 0) {
sha256_update(&(sha_ctx.ctx), anonce, AIRPDCAP_WPA_NONCE_LEN);
sha256_update(&(sha_ctx.ctx), snonce, AIRPDCAP_WPA_NONCE_LEN);
} else {
sha256_update(&(sha_ctx.ctx), snonce, AIRPDCAP_WPA_NONCE_LEN);
sha256_update(&(sha_ctx.ctx), anonce, AIRPDCAP_WPA_NONCE_LEN);
}
sha256_finish(&(sha_ctx.ctx), key_input);
bssid = &data[offset_link + 2];
initiator = &data[offset_link + 8];
responder = &data[offset_link + 14];
sha256_hmac_starts(&sha_ctx, key_input, SHA256_DIGEST_LEN);
iter[0] = 1;
iter[1] = 0;
sha256_hmac_update(&sha_ctx, (const guint8 *)&iter, 2);
sha256_hmac_update(&sha_ctx, "TDLS PMK", 8);
if (memcmp(initiator, responder, AIRPDCAP_MAC_LEN) < 0) {
sha256_hmac_update(&sha_ctx, initiator, AIRPDCAP_MAC_LEN);
sha256_hmac_update(&sha_ctx, responder, AIRPDCAP_MAC_LEN);
} else {
sha256_hmac_update(&sha_ctx, responder, AIRPDCAP_MAC_LEN);
sha256_hmac_update(&sha_ctx, initiator, AIRPDCAP_MAC_LEN);
}
sha256_hmac_update(&sha_ctx, bssid, AIRPDCAP_MAC_LEN);
length[0] = 256 & 0xff;
length[1] = (256 >> 8) & 0xff;
sha256_hmac_update(&sha_ctx, (const guint8 *)&length, 2);
sha256_hmac_finish(&sha_ctx, key_input);
aes_cmac_encrypt_starts(&aes_ctx, key_input, 16);
aes_cmac_encrypt_update(&aes_ctx, initiator, AIRPDCAP_MAC_LEN);
aes_cmac_encrypt_update(&aes_ctx, responder, AIRPDCAP_MAC_LEN);
aes_cmac_encrypt_update(&aes_ctx, &seq_num, 1);
aes_cmac_encrypt_update(&aes_ctx, &data[offset_link], data[offset_link + 1] + 2);
aes_cmac_encrypt_update(&aes_ctx, &data[offset_rsne], data[offset_rsne + 1] + 2);
aes_cmac_encrypt_update(&aes_ctx, &data[offset_timeout], data[offset_timeout + 1] + 2);
aes_cmac_encrypt_update(&aes_ctx, &data[offset_fte], 4);
memset(mic, 0, 16);
aes_cmac_encrypt_update(&aes_ctx, mic, 16);
aes_cmac_encrypt_update(&aes_ctx, &data[offset_fte + 20], data[offset_fte + 1] + 2 - 20);
aes_cmac_encrypt_finish(&aes_ctx, mic);
if (memcmp(mic, &data[offset_fte + 4],16)) {
AIRPDCAP_DEBUG_PRINT_LINE("AirPDcapTDLSDeriveKey", "MIC verification failed", AIRPDCAP_DEBUG_LEVEL_3);
return AIRPDCAP_RET_UNSUCCESS;
}
memcpy(AIRPDCAP_GET_TK(sa->wpa.ptk), &key_input[16], 16);
memcpy(sa->wpa.nonce, snonce, AIRPDCAP_WPA_NONCE_LEN);
sa->validKey = TRUE;
sa->wpa.key_ver = AIRPDCAP_WPA_KEY_VER_AES_CCMP;
AIRPDCAP_DEBUG_PRINT_LINE("AirPDcapTDLSDeriveKey", "MIC verified", AIRPDCAP_DEBUG_LEVEL_3);
return AIRPDCAP_RET_SUCCESS;
}
