static void
call_kerberos_callbacks(packet_info *pinfo, proto_tree *tree, tvbuff_t *tvb, int tag)
{
kerberos_callbacks *cb=(kerberos_callbacks *)pinfo->private_data;
if(!cb){
return;
}
while(cb->tag){
if(cb->tag==tag){
cb->callback(pinfo, tvb, tree);
return;
}
cb++;
}
return;
}
static void
add_encryption_key(packet_info *pinfo, int keytype, int keylength, const char *keyvalue, const char *origin)
{
enc_key_t *new_key;
if(pinfo->fd->flags.visited){
return;
}
printf("added key in %u keytype:%d len:%d\n",pinfo->fd->num, keytype, keylength);
new_key=g_malloc(sizeof(enc_key_t));
g_snprintf(new_key->key_origin, KRB_MAX_ORIG_LEN, "%s learnt from frame %u",origin,pinfo->fd->num);
new_key->next=enc_key_list;
enc_key_list=new_key;
new_key->keytype=keytype;
new_key->keylength=keylength;
new_key->keyvalue=g_memdup(keyvalue, keylength);
}
void
read_keytab_file(const char *filename)
{
krb5_keytab keytab;
krb5_error_code ret;
krb5_keytab_entry key;
krb5_kt_cursor cursor;
enc_key_t *new_key;
static int first_time=1;
printf("read keytab file %s\n", filename);
if(first_time){
first_time=0;
ret = krb5_init_context(&krb5_ctx);
if(ret){
return;
}
}
ret = krb5_kt_resolve(krb5_ctx, filename, &keytab);
if(ret){
fprintf(stderr, "KERBEROS ERROR: Could not open keytab file :%s\n",filename);
return;
}
ret = krb5_kt_start_seq_get(krb5_ctx, keytab, &cursor);
if(ret){
fprintf(stderr, "KERBEROS ERROR: Could not read from keytab file :%s\n",filename);
return;
}
do{
new_key=g_malloc(sizeof(enc_key_t));
new_key->next=enc_key_list;
ret = krb5_kt_next_entry(krb5_ctx, keytab, &key, &cursor);
if(ret==0){
int i;
char *pos;
pos=new_key->key_origin;
pos+=MIN(KRB_MAX_ORIG_LEN,
g_snprintf(pos, KRB_MAX_ORIG_LEN, "keytab principal "));
for(i=0;i<key.principal->length;i++){
pos+=MIN(KRB_MAX_ORIG_LEN-(pos-new_key->key_origin),
g_snprintf(pos, KRB_MAX_ORIG_LEN-(pos-new_key->key_origin), "%s%s",(i?"/":""),(key.principal->data[i]).data));
}
pos+=MIN(KRB_MAX_ORIG_LEN-(pos-new_key->key_origin),
g_snprintf(pos, KRB_MAX_ORIG_LEN-(pos-new_key->key_origin), "@%s",key.principal->realm.data));
*pos=0;
new_key->keytype=key.key.enctype;
new_key->keylength=key.key.length;
new_key->keyvalue=g_memdup(key.key.contents, key.key.length);
enc_key_list=new_key;
}
}while(ret==0);
ret = krb5_kt_end_seq_get(krb5_ctx, keytab, &cursor);
if(ret){
krb5_kt_close(krb5_ctx, keytab);
}
}
guint8 *
decrypt_krb5_data(proto_tree *tree, packet_info *pinfo,
int usage,
int length,
const guint8 *cryptotext,
int keytype,
int *datalen)
{
static int first_time=1;
krb5_error_code ret;
enc_key_t *ek;
static krb5_data data = {0,0,NULL};
krb5_keytab_entry key;
if(!krb_decrypt){
return NULL;
}
if(first_time){
first_time=0;
read_keytab_file(keytab_filename);
}
for(ek=enc_key_list;ek;ek=ek->next){
krb5_enc_data input;
if((keytype != -1) && (ek->keytype != keytype)) {
continue;
}
input.enctype = ek->keytype;
input.ciphertext.length = length;
input.ciphertext.data = (guint8 *)cryptotext;
data.length = length;
g_free(data.data);
data.data = g_malloc(length);
key.key.enctype=ek->keytype;
key.key.length=ek->keylength;
key.key.contents=ek->keyvalue;
ret = krb5_c_decrypt(krb5_ctx, &(key.key), usage, 0, &input, &data);
if((ret == 0) && (length>0)){
char *user_data;
printf("woohoo decrypted keytype:%d in frame:%u\n", ek->keytype, pinfo->fd->num);
proto_tree_add_text(tree, NULL, 0, 0, "[Decrypted using: %s]", ek->key_origin);
user_data=g_malloc(data.length);
memcpy(user_data, data.data, data.length);
if (datalen) {
*datalen = data.length;
}
return user_data;
}
}
return NULL;
}
void
read_keytab_file(const char *filename)
{
krb5_keytab keytab;
krb5_error_code ret;
krb5_keytab_entry key;
krb5_kt_cursor cursor;
enc_key_t *new_key;
static int first_time=1;
if(first_time){
first_time=0;
ret = krb5_init_context(&krb5_ctx);
if(ret){
return;
}
}
ret = krb5_kt_resolve(krb5_ctx, filename, &keytab);
if(ret){
fprintf(stderr, "KERBEROS ERROR: Could not open keytab file :%s\n",filename);
return;
}
ret = krb5_kt_start_seq_get(krb5_ctx, keytab, &cursor);
if(ret){
fprintf(stderr, "KERBEROS ERROR: Could not read from keytab file :%s\n",filename);
return;
}
do{
new_key=g_malloc(sizeof(enc_key_t));
new_key->next=enc_key_list;
ret = krb5_kt_next_entry(krb5_ctx, keytab, &key, &cursor);
if(ret==0){
unsigned int i;
char *pos;
pos=new_key->key_origin;
pos+=MIN(KRB_MAX_ORIG_LEN,
g_snprintf(pos, KRB_MAX_ORIG_LEN, "keytab principal "));
for(i=0;i<key.principal->name.name_string.len;i++){
pos+=MIN(KRB_MAX_ORIG_LEN-(pos-new_key->key_origin),
g_snprintf(pos, KRB_MAX_ORIG_LEN-(pos-new_key->key_origin), "%s%s",(i?"/":""),key.principal->name.name_string.val[i]));
}
pos+=MIN(KRB_MAX_ORIG_LEN-(pos-new_key->key_origin),
g_snprintf(pos, KRB_MAX_ORIG_LEN-(pos-new_key->key_origin), "@%s",key.principal->realm));
*pos=0;
new_key->keytype=key.keyblock.keytype;
new_key->keylength=key.keyblock.keyvalue.length;
new_key->keyvalue=g_memdup(key.keyblock.keyvalue.data, key.keyblock.keyvalue.length);
enc_key_list=new_key;
}
}while(ret==0);
ret = krb5_kt_end_seq_get(krb5_ctx, keytab, &cursor);
if(ret){
krb5_kt_close(krb5_ctx, keytab);
}
}
guint8 *
decrypt_krb5_data(proto_tree *tree, packet_info *pinfo,
int usage,
int length,
const guint8 *cryptotext,
int keytype,
int *datalen)
{
static int first_time=1;
krb5_error_code ret;
krb5_data data;
enc_key_t *ek;
if(!krb_decrypt){
return NULL;
}
if(first_time){
first_time=0;
read_keytab_file(keytab_filename);
}
for(ek=enc_key_list;ek;ek=ek->next){
krb5_keytab_entry key;
krb5_crypto crypto;
guint8 *cryptocopy;
if((keytype != -1) && (ek->keytype != keytype)) {
continue;
}
key.keyblock.keytype=ek->keytype;
key.keyblock.keyvalue.length=ek->keylength;
key.keyblock.keyvalue.data=ek->keyvalue;
ret = krb5_crypto_init(krb5_ctx, &(key.keyblock), 0, &crypto);
if(ret){
return NULL;
}
cryptocopy=g_malloc(length);
memcpy(cryptocopy, cryptotext, length);
ret = krb5_decrypt_ivec(krb5_ctx, crypto, usage,
cryptocopy, length,
&data,
NULL);
g_free(cryptocopy);
if((ret == 0) && (length>0)){
char *user_data;
printf("woohoo decrypted keytype:%d in frame:%u\n", ek->keytype, pinfo->fd->num);
proto_tree_add_text(tree, NULL, 0, 0, "[Decrypted using: %s]", ek->key_origin);
krb5_crypto_destroy(krb5_ctx, crypto);
user_data=g_malloc(data.length);
memcpy(user_data, data.data, data.length);
if (datalen) {
*datalen = data.length;
}
return user_data;
}
krb5_crypto_destroy(krb5_ctx, crypto);
}
return NULL;
}
static void
add_encryption_key(packet_info *pinfo, int keytype, int keylength, const char *keyvalue, const char *origin)
{
service_key_t *new_key;
if(pinfo->fd->flags.visited){
return;
}
printf("added key in %u\n",pinfo->fd->num);
new_key = g_malloc(sizeof(service_key_t));
new_key->kvno = 0;
new_key->keytype = keytype;
new_key->length = keylength;
new_key->contents = g_malloc(keylength);
memcpy(new_key->contents, keyvalue, keylength);
g_snprintf(new_key->origin, KRB_MAX_ORIG_LEN, "%s learnt from frame %u", origin, pinfo->fd->num);
service_key_list = g_slist_append(service_key_list, (gpointer) new_key);
}
static void
clear_keytab(void) {
GSList *ske;
service_key_t *sk;
for(ske = service_key_list; ske != NULL; ske = g_slist_next(ske)){
sk = (service_key_t *) ske->data;
if (sk) {
g_free(sk->contents);
g_free(sk);
}
}
g_slist_free(service_key_list);
service_key_list = NULL;
}
static void
read_keytab_file(const char *service_key_file)
{
FILE *skf;
ws_statb64 st;
service_key_t *sk;
unsigned char buf[SERVICE_KEY_SIZE];
int newline_skip = 0, count = 0;
if (service_key_file != NULL && ws_stat64 (service_key_file, &st) == 0) {
if (st.st_size > SERVICE_KEY_SIZE) {
if ( (st.st_size % (SERVICE_KEY_SIZE + 1) == 0) ||
(st.st_size % (SERVICE_KEY_SIZE + 1) == SERVICE_KEY_SIZE) ) {
newline_skip = 1;
} else if ( (st.st_size % (SERVICE_KEY_SIZE + 2) == 0) ||
(st.st_size % (SERVICE_KEY_SIZE + 2) == SERVICE_KEY_SIZE) ) {
newline_skip = 2;
}
}
skf = ws_fopen(service_key_file, "rb");
if (! skf) return;
while (fread(buf, SERVICE_KEY_SIZE, 1, skf) == 1) {
sk = g_malloc(sizeof(service_key_t));
sk->kvno = buf[0] << 8 | buf[1];
sk->keytype = KEYTYPE_DES3_CBC_MD5;
sk->length = DES3_KEY_SIZE;
sk->contents = g_malloc(DES3_KEY_SIZE);
memcpy(sk->contents, buf + 2, DES3_KEY_SIZE);
g_snprintf(sk->origin, KRB_MAX_ORIG_LEN, "3DES service key file, key #%d, offset %ld", count, ftell(skf));
service_key_list = g_slist_append(service_key_list, (gpointer) sk);
fseek(skf, newline_skip, SEEK_CUR);
count++;
g_warning("added key: %s", sk->origin);
}
fclose(skf);
}
}
guint8 *
decrypt_krb5_data(proto_tree *tree, packet_info *pinfo,
int _U_ usage,
int length,
const guint8 *cryptotext,
int keytype,
int *datalen)
{
tvbuff_t *encr_tvb;
guint8 *decrypted_data = NULL, *plaintext = NULL;
int res;
guint8 cls;
gboolean pc;
guint32 tag, item_len, data_len;
int id_offset, offset;
guint8 key[DES3_KEY_SIZE];
guint8 initial_vector[DES_BLOCK_SIZE];
md5_state_t md5s;
md5_byte_t digest[16];
md5_byte_t zero_fill[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
md5_byte_t confounder[8];
gboolean ind;
GSList *ske;
service_key_t *sk;
struct des3_ctx ctx;
if(!krb_decrypt){
return NULL;
}
if (keytype != KEYTYPE_DES3_CBC_MD5 || service_key_list == NULL) {
return NULL;
}
decrypted_data = g_malloc(length);
for(ske = service_key_list; ske != NULL; ske = g_slist_next(ske)){
gboolean do_continue = FALSE;
sk = (service_key_t *) ske->data;
des_fix_parity(DES3_KEY_SIZE, key, sk->contents);
md5_init(&md5s);
memset(initial_vector, 0, DES_BLOCK_SIZE);
res = des3_set_key(&ctx, key);
cbc_decrypt(&ctx, des3_decrypt, DES_BLOCK_SIZE, initial_vector,
length, decrypted_data, cryptotext);
encr_tvb = tvb_new_real_data(decrypted_data, length, length);
tvb_memcpy(encr_tvb, confounder, 0, 8);
TRY {
id_offset = get_ber_identifier(encr_tvb, CONFOUNDER_PLUS_CHECKSUM, &cls, &pc, &tag);
offset = get_ber_length(encr_tvb, id_offset, &item_len, &ind);
}
CATCH (BoundsError) {
tvb_free(encr_tvb);
do_continue = TRUE;
}
ENDTRY;
if (do_continue) continue;
data_len = item_len + offset - CONFOUNDER_PLUS_CHECKSUM;
if ((int) item_len + offset > length) {
tvb_free(encr_tvb);
continue;
}
md5_append(&md5s, confounder, 8);
md5_append(&md5s, zero_fill, 16);
md5_append(&md5s, decrypted_data + CONFOUNDER_PLUS_CHECKSUM, data_len);
md5_finish(&md5s, digest);
if (tvb_memeql (encr_tvb, 8, digest, 16) == 0) {
g_warning("woohoo decrypted keytype:%d in frame:%u\n", keytype, pinfo->fd->num);
plaintext = g_malloc(data_len);
tvb_memcpy(encr_tvb, plaintext, CONFOUNDER_PLUS_CHECKSUM, data_len);
tvb_free(encr_tvb);
if (datalen) {
*datalen = data_len;
}
g_free(decrypted_data);
return(plaintext);
}
}
g_free(decrypted_data);
return NULL;
}
static int
dissect_krb5_decrypt_authenticator_data (proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
guint8 *plaintext=NULL;
int length;
length=tvb_length_remaining(tvb, offset);
if(!plaintext){
plaintext=decrypt_krb5_data(tree, actx->pinfo, 7, length, tvb_get_ptr(tvb, offset, length), authenticator_etype, NULL);
}
if(!plaintext){
plaintext=decrypt_krb5_data(tree, actx->pinfo, 11, length, tvb_get_ptr(tvb, offset, length), authenticator_etype, NULL);
}
if(plaintext){
tvbuff_t *next_tvb;
next_tvb = tvb_new_real_data (plaintext,
length,
length);
tvb_set_free_cb(next_tvb, g_free);
tvb_set_child_real_data_tvbuff(tvb, next_tvb);
add_new_data_source(actx->pinfo, next_tvb, "Decrypted Krb5");
offset=dissect_kerberos_Applications(FALSE, next_tvb, 0, actx , tree, -1);
}
return offset;
}
static int
dissect_krb5_PA_PROV_SRV_LOCATION(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_)
{
offset=dissect_ber_GeneralString(actx, tree, tvb, offset, hf_krb_provsrv_location, NULL, 0);
return offset;
}
static int
dissect_krb5_PW_SALT(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_)
{
guint32 nt_status;
proto_tree_add_item(tree, hf_krb_smb_nt_status, tvb, offset, 4,
ENC_LITTLE_ENDIAN);
nt_status=tvb_get_letohl(tvb, offset);
if(nt_status && check_col(actx->pinfo->cinfo, COL_INFO)) {
col_append_fstr(actx->pinfo->cinfo, COL_INFO,
" NT Status: %s",
val_to_str(nt_status, NT_errors,
"Unknown error code %#x"));
}
offset += 4;
proto_tree_add_item(tree, hf_krb_smb_unknown, tvb, offset, 4,
ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_krb_smb_unknown, tvb, offset, 4,
ENC_LITTLE_ENDIAN);
offset += 4;
return offset;
}
int
dissect_krb5_Checksum(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
return dissect_kerberos_Checksum(FALSE, tvb, offset, actx, tree, hf_kerberos_cksum);
}
int
dissect_krb5_ctime(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
return dissect_kerberos_KerberosTime(FALSE, tvb, offset, actx, tree, hf_kerberos_ctime);
}
int
dissect_krb5_cname(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
return dissect_kerberos_PrincipalName(FALSE, tvb, offset, actx, tree, hf_kerberos_cname);
}
int
dissect_krb5_realm(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
return dissect_kerberos_Realm(FALSE, tvb, offset, actx, tree, hf_kerberos_realm);
}
static gint
dissect_kerberos_common(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
gboolean dci, gboolean do_col_protocol, gboolean have_rm,
kerberos_callbacks *cb)
{
volatile int offset = 0;
proto_tree *volatile kerberos_tree = NULL;
proto_item *volatile item = NULL;
void *saved_private_data;
asn1_ctx_t asn1_ctx;
guint32 krb_rm = 0;
gint krb_reclen = 0;
saved_private_data=pinfo->private_data;
pinfo->private_data=cb;
do_col_info=dci;
if (have_rm) {
krb_rm = tvb_get_ntohl(tvb, offset);
krb_reclen = kerberos_rm_to_reclen(krb_rm);
if (krb_reclen > 10 * 1024 * 1024) {
pinfo->private_data=saved_private_data;
return (-1);
}
if (do_col_protocol) {
col_set_str(pinfo->cinfo, COL_PROTOCOL, "KRB5");
}
if (tree) {
item = proto_tree_add_item(tree, proto_kerberos, tvb, 0, -1, ENC_NA);
kerberos_tree = proto_item_add_subtree(item, ett_kerberos);
}
show_krb_recordmark(kerberos_tree, tvb, offset, krb_rm);
offset += 4;
} else {
gint8 tmp_class;
gboolean tmp_pc;
gint32 tmp_tag;
get_ber_identifier(tvb, offset, &tmp_class, &tmp_pc, &tmp_tag);
if(tmp_class!=BER_CLASS_APP){
pinfo->private_data=saved_private_data;
return 0;
}
switch(tmp_tag){
case KRB5_MSG_TICKET:
case KRB5_MSG_AUTHENTICATOR:
case KRB5_MSG_ENC_TICKET_PART:
case KRB5_MSG_AS_REQ:
case KRB5_MSG_AS_REP:
case KRB5_MSG_TGS_REQ:
case KRB5_MSG_TGS_REP:
case KRB5_MSG_AP_REQ:
case KRB5_MSG_AP_REP:
case KRB5_MSG_ENC_AS_REP_PART:
case KRB5_MSG_ENC_TGS_REP_PART:
case KRB5_MSG_ENC_AP_REP_PART:
case KRB5_MSG_ENC_KRB_PRIV_PART:
case KRB5_MSG_ENC_KRB_CRED_PART:
case KRB5_MSG_SAFE:
case KRB5_MSG_PRIV:
case KRB5_MSG_ERROR:
break;
default:
pinfo->private_data=saved_private_data;
return 0;
}
if (do_col_protocol) {
col_set_str(pinfo->cinfo, COL_PROTOCOL, "KRB5");
}
if (do_col_info) {
col_clear(pinfo->cinfo, COL_INFO);
}
if (tree) {
item = proto_tree_add_item(tree, proto_kerberos, tvb, 0, -1, ENC_NA);
kerberos_tree = proto_item_add_subtree(item, ett_kerberos);
}
}
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
TRY {
offset=dissect_kerberos_Applications(FALSE, tvb, 0, &asn1_ctx , tree, -1);
} CATCH_ALL {
pinfo->private_data=saved_private_data;
RETHROW;
} ENDTRY;
proto_item_set_len(item, offset);
pinfo->private_data=saved_private_data;
return offset;
}
void
show_krb_recordmark(proto_tree *tree, tvbuff_t *tvb, gint start, guint32 krb_rm)
{
gint rec_len;
proto_item *rm_item;
proto_tree *rm_tree;
if (tree == NULL)
return;
rec_len = kerberos_rm_to_reclen(krb_rm);
rm_item = proto_tree_add_text(tree, tvb, start, 4,
"Record Mark: %u %s", rec_len, plurality(rec_len, "byte", "bytes"));
rm_tree = proto_item_add_subtree(rm_item, ett_krb_recordmark);
proto_tree_add_boolean(rm_tree, hf_krb_rm_reserved, tvb, start, 4, krb_rm);
proto_tree_add_uint(rm_tree, hf_krb_rm_reclen, tvb, start, 4, krb_rm);
}
gint
dissect_kerberos_main(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int do_col_info, kerberos_callbacks *cb)
{
return (dissect_kerberos_common(tvb, pinfo, tree, do_col_info, FALSE, FALSE, cb));
}
guint32
kerberos_output_keytype(void)
{
return keytype;
}
static gint
dissect_kerberos_udp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
if(tvb_length(tvb) >= 1 && tvb_get_guint8(tvb, 0)<=0x10){
if(krb4_handle){
gboolean res;
res=call_dissector_only(krb4_handle, tvb, pinfo, tree);
return res;
}else{
return 0;
}
}
return dissect_kerberos_common(tvb, pinfo, tree, TRUE, TRUE, FALSE, NULL);
}
gint
kerberos_rm_to_reclen(guint krb_rm)
{
return (krb_rm & KRB_RM_RECLEN);
}
guint
get_krb_pdu_len(packet_info *pinfo _U_, tvbuff_t *tvb, int offset)
{
guint krb_rm;
gint pdulen;
krb_rm = tvb_get_ntohl(tvb, offset);
pdulen = kerberos_rm_to_reclen(krb_rm);
return (pdulen + 4);
}
static void
kerberos_prefs_apply_cb(void) {
#ifdef HAVE_LIBNETTLE
clear_keytab();
read_keytab_file(keytab_filename);
#endif
}
void proto_register_kerberos(void) {
static hf_register_info hf[] = {
{ &hf_krb_rm_reserved, {
"Reserved", "kerberos.rm.reserved", FT_BOOLEAN, 32,
&bitval, KRB_RM_RESERVED, "Record mark reserved bit", HFILL }},
{ &hf_krb_rm_reclen, {
"Record Length", "kerberos.rm.length", FT_UINT32, BASE_DEC,
NULL, KRB_RM_RECLEN, "Record length", HFILL }},
{ &hf_krb_provsrv_location, {
"PROVSRV Location", "kerberos.provsrv_location", FT_STRING, BASE_NONE,
NULL, 0, "PacketCable PROV SRV Location", HFILL }},
{ &hf_krb_smb_nt_status,
{ "NT Status", "kerberos.smb.nt_status", FT_UINT32, BASE_HEX,
VALS(NT_errors), 0, "NT Status code", HFILL }},
{ &hf_krb_smb_unknown,
{ "Unknown", "kerberos.smb.unknown", FT_UINT32, BASE_HEX,
NULL, 0, "unknown", HFILL }},
{ &hf_krb_address_ip, {
"IP Address", "kerberos.addr_ip", FT_IPv4, BASE_NONE,
NULL, 0, "IP Address", HFILL }},
{ &hf_krb_address_ipv6, {
"IPv6 Address", "kerberos.addr_ipv6", FT_IPv6, BASE_NONE,
NULL, 0, "IPv6 Address", HFILL }},
{ &hf_krb_address_netbios, {
"NetBIOS Address", "kerberos.addr_nb", FT_STRING, BASE_NONE,
NULL, 0, "NetBIOS Address and type", HFILL }},
#include "packet-kerberos-hfarr.c"
};
static gint *ett[] = {
&ett_kerberos,
&ett_krb_recordmark,
#include "packet-kerberos-ettarr.c"
};
module_t *krb_module;
proto_kerberos = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_kerberos, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
krb_module = prefs_register_protocol(proto_kerberos, kerberos_prefs_apply_cb);
prefs_register_bool_preference(krb_module, "desegment",
"Reassemble Kerberos over TCP messages spanning multiple TCP segments",
"Whether the Kerberos dissector should reassemble messages spanning multiple TCP segments."
" To use this option, you must also enable \"Allow subdissectors to reassemble TCP streams\" in the TCP protocol settings.",
&krb_desegment);
#ifdef HAVE_KERBEROS
prefs_register_bool_preference(krb_module, "decrypt",
"Try to decrypt Kerberos blobs",
"Whether the dissector should try to decrypt "
"encrypted Kerberos blobs. This requires that the proper "
"keytab file is installed as well.", &krb_decrypt);
prefs_register_string_preference(krb_module, "file",
"Kerberos keytab file",
"The keytab file containing all the secrets",
&keytab_filename);
#endif
}
static int wrap_dissect_gss_kerb(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, guint8 *drep _U_)
{
tvbuff_t *auth_tvb;
auth_tvb = tvb_new_subset(
tvb, offset, tvb_length_remaining(tvb, offset),
tvb_reported_length_remaining(tvb, offset));
dissect_kerberos_main(auth_tvb, pinfo, tree, FALSE, NULL);
return tvb_length_remaining(tvb, offset);
}
void
proto_reg_handoff_kerberos(void)
{
krb4_handle = find_dissector("krb4");
kerberos_handle_udp = new_create_dissector_handle(dissect_kerberos_udp,
proto_kerberos);
dissector_add_uint("udp.port", UDP_PORT_KERBEROS, kerberos_handle_udp);
register_dcerpc_auth_subdissector(DCE_C_AUTHN_LEVEL_PKT_INTEGRITY,
DCE_C_RPC_AUTHN_PROTOCOL_GSS_KERBEROS,
&gss_kerb_auth_fns);
register_dcerpc_auth_subdissector(DCE_C_AUTHN_LEVEL_PKT_PRIVACY,
DCE_C_RPC_AUTHN_PROTOCOL_GSS_KERBEROS,
&gss_kerb_auth_fns);
}
