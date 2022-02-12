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
void
read_keytab_file_from_preferences(void)
{
static char *last_keytab = NULL;
if (!krb_decrypt) {
return;
}
if (keytab_filename == NULL) {
return;
}
if (last_keytab && !strcmp(last_keytab, keytab_filename)) {
return;
}
if (last_keytab != NULL) {
g_free(last_keytab);
last_keytab = NULL;
}
last_keytab = g_strdup(keytab_filename);
read_keytab_file(last_keytab);
}
void
read_keytab_file_from_preferences(void)
{
}
static void
add_encryption_key(packet_info *pinfo, int keytype, int keylength, const char *keyvalue, const char *origin)
{
enc_key_t *new_key;
if(pinfo->fd->flags.visited){
return;
}
printf("added key in %u keytype:%d len:%d\n",pinfo->fd->num, keytype, keylength);
new_key=(enc_key_t *)g_malloc(sizeof(enc_key_t));
g_snprintf(new_key->key_origin, KRB_MAX_ORIG_LEN, "%s learnt from frame %u",origin,pinfo->fd->num);
new_key->next=enc_key_list;
enc_key_list=new_key;
new_key->keytype=keytype;
new_key->keylength=keylength;
new_key->keyvalue=(char *)g_memdup(keyvalue, keylength);
}
void
read_keytab_file(const char *filename _U_)
{
}
void
read_keytab_file(const char *filename)
{
krb5_keytab keytab;
krb5_error_code ret;
krb5_keytab_entry key;
krb5_kt_cursor cursor;
enc_key_t *new_key;
static gboolean first_time=TRUE;
printf("read keytab file %s\n", filename);
if(first_time){
first_time=FALSE;
ret = krb5_init_context(&krb5_ctx);
if(ret && ret != KRB5_CONFIG_CANTOPEN){
return;
}
}
ret = krb5_kt_resolve(krb5_ctx, filename, &keytab);
if(ret){
fprintf(stderr, "KERBEROS ERROR: Badly formatted keytab filename :%s\n",filename);
return;
}
ret = krb5_kt_start_seq_get(krb5_ctx, keytab, &cursor);
if(ret){
fprintf(stderr, "KERBEROS ERROR: Could not open or could not read from keytab file :%s\n",filename);
return;
}
do{
new_key=(enc_key_t *)g_malloc(sizeof(enc_key_t));
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
new_key->keyvalue=(char *)g_memdup(key.key.contents, key.key.length);
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
tvbuff_t *cryptotvb,
int keytype,
int *datalen)
{
krb5_error_code ret;
enc_key_t *ek;
krb5_data data = {0,0,NULL};
krb5_keytab_entry key;
int length = tvb_length(cryptotvb);
const guint8 *cryptotext = tvb_get_ptr(cryptotvb, 0, length);
if(!krb_decrypt || length < 1){
return NULL;
}
if (tvb_length(cryptotvb) < tvb_reported_length(cryptotvb)) {
return NULL;
}
read_keytab_file_from_preferences();
data.data = (char *)g_malloc(length);
data.length = length;
for(ek=enc_key_list;ek;ek=ek->next){
krb5_enc_data input;
if((keytype != -1) && (ek->keytype != keytype)) {
continue;
}
input.enctype = ek->keytype;
input.ciphertext.length = length;
input.ciphertext.data = (guint8 *)cryptotext;
key.key.enctype=ek->keytype;
key.key.length=ek->keylength;
key.key.contents=ek->keyvalue;
ret = krb5_c_decrypt(krb5_ctx, &(key.key), usage, 0, &input, &data);
if(ret == 0){
char *user_data;
expert_add_info_format(pinfo, NULL, &ei_krb_decrypted_keytype,
"Decrypted keytype %d in frame %u using %s",
ek->keytype, pinfo->fd->num, ek->key_origin);
proto_tree_add_text(tree, NULL, 0, 0, "[Decrypted using: %s]", ek->key_origin);
user_data=data.data;
if (datalen) {
*datalen = data.length;
}
return user_data;
}
}
g_free(data.data);
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
static gboolean first_time=TRUE;
if(first_time){
first_time=FALSE;
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
new_key=(enc_key_t*)g_malloc(sizeof(enc_key_t));
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
new_key->keyvalue=(char*)g_memdup(key.keyblock.keyvalue.data, key.keyblock.keyvalue.length);
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
tvbuff_t *cryptotvb,
int keytype,
int *datalen)
{
krb5_error_code ret;
krb5_data data;
enc_key_t *ek;
int length = tvb_length(cryptotvb);
const guint8 *cryptotext = tvb_get_ptr(cryptotvb, 0, length);
if(!krb_decrypt){
return NULL;
}
if (tvb_length(cryptotvb) < tvb_reported_length(cryptotvb)) {
return NULL;
}
read_keytab_file_from_preferences();
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
ret = krb5_crypto_init(krb5_ctx, &(key.keyblock), (krb5_enctype)0, &crypto);
if(ret){
return NULL;
}
cryptocopy=(guint8*)g_memdup(cryptotext, length);
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
user_data=(char*)g_memdup(data.data, data.length);
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
new_key->contents = g_memdup(keyvalue, keylength);
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
sk->contents = g_memdup(buf + 2, DES3_KEY_SIZE);
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
tvbuff_t *cryptotvb,
int keytype,
int *datalen)
{
tvbuff_t *encr_tvb;
guint8 *decrypted_data = NULL, *plaintext = NULL;
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
int length = tvb_length(cryptotvb);
const guint8 *cryptotext = tvb_get_ptr(cryptotvb, 0, length);
if(!krb_decrypt){
return NULL;
}
if (tvb_length(cryptotvb) < tvb_reported_length(cryptotvb)) {
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
des3_set_key(&ctx, key);
cbc_decrypt(&ctx, des3_decrypt, DES_BLOCK_SIZE, initial_vector,
length, decrypted_data, cryptotext);
encr_tvb = tvb_new_real_data(decrypted_data, length, length);
tvb_memcpy(encr_tvb, confounder, 0, 8);
TRY {
id_offset = get_ber_identifier(encr_tvb, CONFOUNDER_PLUS_CHECKSUM, &cls, &pc, &tag);
offset = get_ber_length(encr_tvb, id_offset, &item_len, &ind);
}
CATCH_BOUNDS_ERRORS {
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
tvb_free(encr_tvb);
}
g_free(decrypted_data);
return NULL;
}
static int
dissect_krb5_application_choice(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_old_choice(actx, tree, tvb, offset, kerberos_applications_choice, -1, -1, NULL);
return offset;
}
static int
dissect_krb5_APOptions(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_bitstring32(FALSE, actx, tree, tvb, offset, APOptions_bits, hf_krb_APOptions, ett_krb_AP_Options, NULL);
return offset;
}
static int
dissect_krb5_KDCOptions(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_bitstring32(FALSE, actx, tree, tvb, offset, KDCOptions_bits, hf_krb_KDCOptions, ett_krb_KDC_Options, NULL);
return offset;
}
static int
dissect_krb5_rtime(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_GeneralizedTime(FALSE, actx, tree, tvb, offset, hf_krb_rtime);
return offset;
}
int
dissect_krb5_ctime(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_GeneralizedTime(FALSE, actx, tree, tvb, offset, hf_krb_ctime);
return offset;
}
static int
dissect_krb5_cusec(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_integer(FALSE, actx, tree, tvb, offset, hf_krb_cusec, NULL);
return offset;
}
static int
dissect_krb5_stime(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_GeneralizedTime(FALSE, actx, tree, tvb, offset, hf_krb_stime);
return offset;
}
static int
dissect_krb5_susec(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_integer(FALSE, actx, tree, tvb, offset, hf_krb_susec, NULL);
return offset;
}
static int
dissect_krb5_error_code(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_integer(FALSE, actx, tree, tvb, offset, hf_krb_error_code, &krb5_errorcode);
if(krb5_errorcode) {
col_add_fstr(actx->pinfo->cinfo, COL_INFO,
"KRB Error: %s",
val_to_str(krb5_errorcode, krb5_error_codes,
"Unknown error code %#x"));
}
return offset;
}
static int
dissect_krb5_till(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_GeneralizedTime(FALSE, actx, tree, tvb, offset, hf_krb_till);
return offset;
}
static int
dissect_krb5_from(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_GeneralizedTime(FALSE, actx, tree, tvb, offset, hf_krb_from);
return offset;
}
static int
dissect_krb5_nonce(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_integer(FALSE, actx, tree, tvb, offset, hf_krb_nonce, NULL);
return offset;
}
static int
dissect_krb5_etype(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
guint32 etype;
offset=dissect_ber_integer(FALSE, actx, tree, tvb, offset, hf_krb_etype, &etype);
if(tree){
proto_item_append_text(tree, " %s",
val_to_str(etype, krb5_encryption_types,
"%d"));
}
return offset;
}
static int
dissect_krb5_etype_sequence_of(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_old_sequence_of(FALSE, actx, tree, tvb, offset, etype_sequence_of, hf_krb_etypes, ett_krb_etypes);
return offset;
}
static int
dissect_krb5_authenticator_etype(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_integer(FALSE, actx, tree, tvb, offset, hf_krb_etype, &authenticator_etype);
if(tree){
proto_item_append_text(tree, " %s",
val_to_str(authenticator_etype, krb5_encryption_types,
"%#x"));
}
return offset;
}
static int
dissect_krb5_Ticket_etype(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_integer(FALSE, actx, tree, tvb, offset, hf_krb_etype, &Ticket_etype);
if(tree){
proto_item_append_text(tree, " %s",
val_to_str(Ticket_etype, krb5_encryption_types,
"%#x"));
}
return offset;
}
static int
dissect_krb5_AP_REP_etype(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_integer(FALSE, actx, tree, tvb, offset, hf_krb_etype, &AP_REP_etype);
if(tree){
proto_item_append_text(tree, " %s",
val_to_str(AP_REP_etype, krb5_encryption_types,
"%#x"));
}
return offset;
}
static int
dissect_krb5_PA_ENC_TIMESTAMP_etype(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_integer(FALSE, actx, tree, tvb, offset, hf_krb_etype, &PA_ENC_TIMESTAMP_etype);
if(tree){
proto_item_append_text(tree, " %s",
val_to_str(PA_ENC_TIMESTAMP_etype, krb5_encryption_types,
"%#x"));
}
return offset;
}
static int dissect_krb5_addr_type(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_integer(FALSE, actx, tree, tvb, offset, hf_krb_addr_type, &addr_type);
return offset;
}
static int dissect_krb5_address(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
gint8 appclass;
gboolean pc;
gint32 tag;
guint32 len;
char *address_str;
proto_item *it=NULL;
offset=dissect_ber_identifier(actx->pinfo, tree, tvb, offset, &appclass, &pc, &tag);
offset=dissect_ber_length(actx->pinfo, tree, tvb, offset, &len, NULL);
address_str=(char *)wmem_alloc(wmem_packet_scope(), ADDRESS_STR_BUFSIZ);
address_str[0]='\0';
switch(addr_type){
case KRB5_ADDR_IPv4:
it=proto_tree_add_item(tree, hf_krb_address_ip, tvb, offset, 4, ENC_BIG_ENDIAN);
g_snprintf(address_str,ADDRESS_STR_BUFSIZ,"%d.%d.%d.%d",tvb_get_guint8(tvb, offset),tvb_get_guint8(tvb, offset+1),tvb_get_guint8(tvb, offset+2),tvb_get_guint8(tvb, offset+3));
break;
case KRB5_ADDR_NETBIOS:
{
char netbios_name[(NETBIOS_NAME_LEN - 1)*4 + 1];
int netbios_name_type;
int netbios_name_len = (NETBIOS_NAME_LEN - 1)*4 + 1;
netbios_name_type = process_netbios_name(tvb_get_ptr(tvb, offset, 16), netbios_name, netbios_name_len);
g_snprintf(address_str, ADDRESS_STR_BUFSIZ, "%s<%02x>", netbios_name, netbios_name_type);
it=proto_tree_add_string_format(tree, hf_krb_address_netbios, tvb, offset, 16, netbios_name, "NetBIOS Name: %s (%s)", address_str, netbios_name_type_descr(netbios_name_type));
}
break;
case KRB5_ADDR_IPv6:
it=proto_tree_add_item(tree, hf_krb_address_ipv6, tvb, offset, INET6_ADDRLEN, ENC_NA);
g_snprintf(address_str, ADDRESS_STR_BUFSIZ, "%s", tvb_ip6_to_str(tvb, offset));
break;
default:
proto_tree_add_text(tree, tvb, offset, len, "KRB Address: I don't know how to parse this type of address yet");
}
if(it){
proto_item_append_text(proto_item_get_parent(it), " %s",address_str);
proto_item_append_text(proto_item_get_parent_nth(it, 2), " %s",address_str);
}
offset+=len;
return offset;
}
static int
dissect_krb5_HostAddress(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_old_sequence(FALSE, actx, tree, tvb, offset, HostAddress_sequence, hf_krb_HostAddress, ett_krb_HostAddress);
return offset;
}
static int
dissect_krb5_s_address(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_old_sequence(FALSE, actx, tree, tvb, offset, HostAddress_sequence, hf_krb_s_address, ett_krb_s_address);
return offset;
}
static int
dissect_krb5_r_address(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_old_sequence(FALSE, actx, tree, tvb, offset, HostAddress_sequence, hf_krb_r_address, ett_krb_r_address);
return offset;
}
static int
dissect_krb5_HostAddresses(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_old_sequence_of(FALSE, actx, tree, tvb, offset, HostAddresses_sequence_of, hf_krb_HostAddresses, ett_krb_HostAddresses);
return offset;
}
static int
dissect_krb5_sq_tickets(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_old_sequence_of(FALSE, actx, tree, tvb, offset, sequence_of_tickets, hf_krb_sq_tickets, ett_krb_sq_tickets);
return offset;
}
static int
dissect_krb5_msg_type(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
guint32 msgtype;
offset=dissect_ber_integer(FALSE, actx, tree, tvb, offset, hf_krb_msg_type, &msgtype);
if (gbl_do_col_info) {
col_add_str(actx->pinfo->cinfo, COL_INFO,
val_to_str(msgtype, krb5_msg_types,
"Unknown msg type %#x"));
}
gbl_do_col_info=FALSE;
proto_item_append_text(tree, " %s", val_to_str(msgtype, krb5_msg_types, "Unknown:0x%x"));
return offset;
}
static int
dissect_krb5_pvno(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_integer(FALSE, actx, tree, tvb, offset, hf_krb_pvno, NULL);
return offset;
}
static int
dissect_krb5_name_type(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_integer(FALSE, actx, tree, tvb, offset, hf_krb_name_type, &name_type);
if(tree){
proto_item_append_text(tree, " (%s):",
val_to_str(name_type, krb5_princ_types,
"Unknown:%d"));
}
return offset;
}
static int
dissect_krb5_name_string(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
char name_string[256];
offset=dissect_ber_GeneralString(actx, tree, tvb, offset, hf_krb_name_string, name_string, 255);
if(tree){
proto_item_append_text(tree, "%c%s", name_string_separator, name_string);
name_string_separator='/';
}
return offset;
}
static int
dissect_krb5_name_strings(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
name_string_separator=' ';
offset=dissect_ber_old_sequence_of(FALSE, actx, tree, tvb, offset, name_stringe_sequence_of, -1, -1);
return offset;
}
static int
dissect_krb5_sname(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_old_sequence(FALSE, actx, tree, tvb, offset, PrincipalName_sequence, hf_krb_sname, ett_krb_sname);
return offset;
}
static int
dissect_krb5_pname(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_old_sequence(FALSE, actx, tree, tvb, offset, PrincipalName_sequence, hf_krb_pname, ett_krb_pname);
return offset;
}
int
dissect_krb5_cname(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_old_sequence(FALSE, actx, tree, tvb, offset, PrincipalName_sequence, hf_krb_cname, ett_krb_cname);
return offset;
}
int
dissect_krb5_prealm(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_GeneralString(actx, tree, tvb, offset, hf_krb_prealm, NULL, 0);
return offset;
}
int
dissect_krb5_srealm(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_GeneralString(actx, tree, tvb, offset, hf_krb_srealm, NULL, 0);
return offset;
}
int
dissect_krb5_realm(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_GeneralString(actx, tree, tvb, offset, hf_krb_realm, NULL, 0);
return offset;
}
static int
dissect_krb5_crealm(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_GeneralString(actx, tree, tvb, offset, hf_krb_crealm, NULL, 0);
return offset;
}
static int
dissect_krb5_PA_PAC_REQUEST_flag(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_boolean(FALSE, actx, tree, tvb, offset, hf_krb_PA_PAC_REQUEST_flag, NULL);
return offset;
}
static int
dissect_krb5_PA_PAC_REQUEST(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_old_sequence(FALSE, actx, tree, tvb, offset, PA_PAC_REQUEST_sequence, -1, -1);
return offset;
}
static int
dissect_krb5_s4u2self_auth(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_GeneralString(actx, tree, tvb, offset, hf_krb_s4u2self_auth, NULL, 0);
return offset;
}
static int
dissect_krb5_PA_FOR_USER(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_old_sequence(FALSE, actx, tree, tvb, offset, PA_FOR_USER_sequence, -1, -1);
return offset;
}
static int
dissect_krb5_PA_PROV_SRV_LOCATION(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_GeneralString(actx, tree, tvb, offset, hf_krb_provsrv_location, NULL, 0);
return offset;
}
static int
dissect_krb5_kvno(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_integer(FALSE, actx, tree, tvb, offset, hf_krb_kvno, NULL);
return offset;
}
static int
dissect_krb5_seq_number(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_integer(FALSE, actx, tree, tvb, offset, hf_krb_seq_number, NULL);
return offset;
}
static int
dissect_krb5_patimestamp(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_GeneralizedTime(FALSE, actx, tree, tvb, offset, hf_krb_patimestamp);
return offset;
}
static int
dissect_krb5_pausec(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_integer(FALSE, actx, tree, tvb, offset, hf_krb_pausec, NULL);
return offset;
}
static int
dissect_krb5_decrypt_PA_ENC_TIMESTAMP (proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
guint8 *plaintext=NULL;
int length;
length=tvb_length_remaining(tvb, offset);
if(!plaintext){
tvbuff_t *next_tvb;
next_tvb=tvb_new_subset_remaining(tvb, offset);
plaintext=decrypt_krb5_data(tree, actx->pinfo, 1, next_tvb, PA_ENC_TIMESTAMP_etype, NULL);
}
if(plaintext){
tvbuff_t *next_tvb;
next_tvb = tvb_new_child_real_data(tvb, plaintext,
length,
length);
tvb_set_free_cb(next_tvb, g_free);
add_new_data_source(actx->pinfo, next_tvb, "Decrypted Krb5");
offset=dissect_ber_old_sequence(FALSE, actx, tree, next_tvb, 0, PA_ENC_TS_ENC_sequence, -1, -1);
}
return offset;
}
static int
dissect_krb5_encrypted_PA_ENC_TIMESTAMP(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
#ifdef HAVE_KERBEROS
offset=dissect_ber_old_octet_string_wcb(FALSE, actx, tree, tvb, offset, hf_krb_encrypted_PA_ENC_TIMESTAMP, dissect_krb5_decrypt_PA_ENC_TIMESTAMP);
#else
offset=dissect_ber_old_octet_string_wcb(FALSE, actx, tree, tvb, offset, hf_krb_encrypted_PA_ENC_TIMESTAMP, NULL);
#endif
return offset;
}
static int
dissect_krb5_PA_ENC_TIMESTAMP(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_old_sequence(FALSE, actx, tree, tvb, offset, PA_ENC_TIMESTAMP_sequence, -1, -1);
return offset;
}
static int
dissect_krb5_etype_info_salt(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_octet_string(FALSE, actx, tree, tvb, offset, hf_krb_etype_info_salt, NULL);
return offset;
}
static int
dissect_krb5_etype_info2_salt(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_GeneralString(actx, tree, tvb, offset, hf_krb_etype_info2_salt, NULL, 0);
return offset;
}
static int
dissect_krb5_etype_info2_s2kparams(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_octet_string(FALSE, actx, tree, tvb, offset, hf_krb_etype_info2_s2kparams, NULL);
return offset;
}
static int
dissect_krb5_PA_ENCTYPE_INFO_ENTRY(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_old_sequence(FALSE, actx, tree, tvb, offset, PA_ENCTYPE_INFO_ENTRY_sequence, -1, -1);
return offset;
}
static int
dissect_krb5_PA_ENCTYPE_INFO(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_old_sequence_of(FALSE, actx, tree, tvb, offset, PA_ENCTYPE_INFO_sequence_of, -1, -1);
return offset;
}
static int
dissect_krb5_PA_ENCTYPE_INFO2_ENTRY(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_old_sequence(FALSE, actx, tree, tvb, offset, PA_ENCTYPE_INFO2_ENTRY_sequence, -1, -1);
return offset;
}
static int
dissect_krb5_PA_ENCTYPE_INFO2(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_old_sequence_of(FALSE, actx, tree, tvb, offset, PA_ENCTYPE_INFO2_sequence_of, -1, -1);
return offset;
}
static int
dissect_krb5_PW_SALT(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
guint32 nt_status;
proto_tree_add_item(tree, hf_krb_smb_nt_status, tvb, offset, 4, ENC_LITTLE_ENDIAN);
nt_status=tvb_get_letohl(tvb, offset);
if(nt_status) {
col_append_fstr(actx->pinfo->cinfo, COL_INFO,
" NT Status: %s",
val_to_str(nt_status, NT_errors,
"Unknown error code %#x"));
}
offset += 4;
proto_tree_add_item(tree, hf_krb_smb_unknown, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_krb_smb_unknown, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
return offset;
}
static int
dissect_krb5_PA_DATA_type(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_integer(FALSE, actx, tree, tvb, offset, hf_krb_PA_DATA_type, &krb_PA_DATA_type);
if(tree){
proto_item_append_text(tree, " %s",
val_to_str(krb_PA_DATA_type, krb5_preauthentication_types,
"Unknown:%d"));
}
return offset;
}
static int
dissect_krb5_PA_DATA_value(proto_tree *parent_tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
proto_tree *tree=parent_tree;
if(actx->created_item){
tree=proto_item_add_subtree(actx->created_item, ett_krb_PA_DATA_tree);
}
switch(krb_PA_DATA_type){
case KRB5_PA_TGS_REQ:
offset=dissect_ber_old_octet_string_wcb(FALSE, actx, tree, tvb, offset,hf_krb_PA_DATA_value, dissect_krb5_application_choice);
break;
case KRB5_PA_PK_AS_REQ:
offset=dissect_ber_old_octet_string_wcb(FALSE, actx, tree, tvb, offset,hf_krb_PA_DATA_value, dissect_pkinit_PA_PK_AS_REQ);
break;
case KRB5_PA_PK_AS_REP:
offset=dissect_ber_old_octet_string_wcb(FALSE, actx, tree, tvb, offset,hf_krb_PA_DATA_value, dissect_pkinit_PA_PK_AS_REP);
break;
case KRB5_PA_PAC_REQUEST:
offset=dissect_ber_old_octet_string_wcb(FALSE, actx, tree, tvb, offset,hf_krb_PA_DATA_value, dissect_krb5_PA_PAC_REQUEST);
break;
case KRB5_PA_FOR_USER:
offset=dissect_ber_old_octet_string_wcb(FALSE, actx, tree, tvb, offset,hf_krb_PA_DATA_value, dissect_krb5_PA_FOR_USER);
break;
case KRB5_PA_PROV_SRV_LOCATION:
offset=dissect_ber_old_octet_string_wcb(FALSE, actx, tree, tvb, offset,hf_krb_PA_DATA_value, dissect_krb5_PA_PROV_SRV_LOCATION);
break;
case KRB5_PA_ENC_TIMESTAMP:
offset=dissect_ber_old_octet_string_wcb(FALSE, actx, tree, tvb, offset,hf_krb_PA_DATA_value, dissect_krb5_PA_ENC_TIMESTAMP);
break;
case KRB5_PA_ENCTYPE_INFO:
offset=dissect_ber_old_octet_string_wcb(FALSE, actx, tree, tvb, offset,hf_krb_PA_DATA_value, dissect_krb5_PA_ENCTYPE_INFO);
break;
case KRB5_PA_ENCTYPE_INFO2:
offset=dissect_ber_old_octet_string_wcb(FALSE, actx, tree, tvb, offset,hf_krb_PA_DATA_value, dissect_krb5_PA_ENCTYPE_INFO2);
break;
case KRB5_PA_PW_SALT:
offset=dissect_ber_old_octet_string_wcb(FALSE, actx, tree, tvb, offset,hf_krb_PA_DATA_value, dissect_krb5_PW_SALT);
break;
default:
offset=dissect_ber_old_octet_string_wcb(FALSE, actx, tree, tvb, offset,hf_krb_PA_DATA_value, NULL);
}
return offset;
}
static int
dissect_krb5_PA_DATA(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_old_sequence(FALSE, actx, tree, tvb, offset, PA_DATA_sequence, -1, -1);
return offset;
}
static int
dissect_krb5_padata(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_old_sequence_of(FALSE, actx, tree, tvb, offset, PA_DATA_sequence_of, hf_krb_padata, ett_krb_padata);
return offset;
}
static int
dissect_krb5_TicketFlags(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_bitstring32(FALSE, actx, tree, tvb, offset, TicketFlags_bits, hf_krb_TicketFlags, ett_krb_Ticket_Flags, NULL);
return offset;
}
static int
dissect_krb5_keytype(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_integer(FALSE, actx, tree, tvb, offset, hf_krb_keytype, &keytype);
if(tree){
proto_item_append_text(tree, " %s",
val_to_str(keytype, krb5_encryption_types,
"%#x"));
}
return offset;
}
static int
store_keyvalue(proto_tree *tree _U_, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
keylength=tvb_length_remaining(tvb, offset);
keyvalue=tvb_get_ptr(tvb, offset, keylength);
return 0;
}
static int
dissect_krb5_keyvalue(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_old_octet_string_wcb(FALSE, actx, tree, tvb, offset, hf_krb_keyvalue, store_keyvalue);
return offset;
}
static int
dissect_krb5_key(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_old_sequence(FALSE, actx, tree, tvb, offset, EncryptionKey_sequence, hf_krb_key, ett_krb_key);
#ifdef HAVE_KERBEROS
add_encryption_key(actx->pinfo, keytype, keylength, keyvalue, "key");
#endif
return offset;
}
static int
dissect_krb5_subkey(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_old_sequence(FALSE, actx, tree, tvb, offset, EncryptionKey_sequence, hf_krb_subkey, ett_krb_subkey);
#ifdef HAVE_KERBEROS
add_encryption_key(actx->pinfo, keytype, keylength, keyvalue, "subkey");
#endif
return offset;
}
static int
dissect_krb5_PAC_DREP(proto_tree *parent_tree, tvbuff_t *tvb, int offset, guint8 *drep)
{
proto_item *item=NULL;
proto_tree *tree=NULL;
guint8 val;
if(parent_tree){
item=proto_tree_add_text(parent_tree, tvb, offset, 16, "DREP");
tree=proto_item_add_subtree(item, ett_krb_PAC_DREP);
}
val = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_dcerpc_drep_byteorder, tvb, offset, 1, val>>4);
offset++;
if (drep) {
*drep = val;
}
return offset;
}
static int
dissect_krb5_PAC_NDRHEADERBLOB(proto_tree *parent_tree, tvbuff_t *tvb, int offset, guint8 *drep, asn1_ctx_t *actx _U_)
{
proto_item *item=NULL;
proto_tree *tree=NULL;
if(parent_tree){
item=proto_tree_add_text(parent_tree, tvb, offset, 16, "MES header");
tree=proto_item_add_subtree(item, ett_krb_PAC_MIDL_BLOB);
}
proto_tree_add_item(tree, hf_krb_midl_version, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
offset = dissect_krb5_PAC_DREP(tree, tvb, offset, drep);
proto_tree_add_item(tree, hf_krb_midl_hdr_len, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_krb_midl_fill_bytes, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_krb_midl_blob_len, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
return offset;
}
static int
dissect_krb5_PAC_LOGON_INFO(proto_tree *parent_tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
proto_item *item=NULL;
proto_tree *tree=NULL;
guint8 drep[4] = { 0x10, 0x00, 0x00, 0x00};
static dcerpc_info di;
static dcerpc_call_value call_data;
void *old_private_data;
item=proto_tree_add_item(parent_tree, hf_krb_PAC_LOGON_INFO, tvb, offset, tvb_length_remaining(tvb, offset), ENC_NA);
if(parent_tree){
tree=proto_item_add_subtree(item, ett_krb_PAC_LOGON_INFO);
}
offset=dissect_krb5_PAC_NDRHEADERBLOB(tree, tvb, offset, &drep[0], actx);
di.conformant_run=0;
di.call_data=&call_data;
old_private_data=actx->pinfo->private_data;
actx->pinfo->private_data=&di;
init_ndr_pointer_list(actx->pinfo);
offset = dissect_ndr_pointer(tvb, offset, actx->pinfo, tree, drep,
netlogon_dissect_PAC_LOGON_INFO, NDR_POINTER_UNIQUE,
"PAC_LOGON_INFO:", -1);
actx->pinfo->private_data=old_private_data;
return offset;
}
static int
dissect_krb5_PAC_S4U_DELEGATION_INFO(proto_tree *parent_tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
proto_item *item=NULL;
proto_tree *tree=NULL;
guint8 drep[4] = { 0x10, 0x00, 0x00, 0x00};
static dcerpc_info di;
static dcerpc_call_value call_data;
void *old_private_data;
item=proto_tree_add_item(parent_tree, hf_krb_PAC_S4U_DELEGATION_INFO, tvb, offset, tvb_length_remaining(tvb, offset), ENC_NA);
if(parent_tree){
tree=proto_item_add_subtree(item, ett_krb_PAC_S4U_DELEGATION_INFO);
}
offset=dissect_krb5_PAC_NDRHEADERBLOB(tree, tvb, offset, &drep[0], actx);
di.conformant_run=0;
di.call_data=&call_data;
old_private_data=actx->pinfo->private_data;
actx->pinfo->private_data=&di;
init_ndr_pointer_list(actx->pinfo);
offset = dissect_ndr_pointer(tvb, offset, actx->pinfo, tree, drep,
netlogon_dissect_PAC_S4U_DELEGATION_INFO, NDR_POINTER_UNIQUE,
"PAC_S4U_DELEGATION_INFO:", -1);
actx->pinfo->private_data=old_private_data;
return offset;
}
static int
dissect_krb5_PAC_UPN_DNS_INFO(proto_tree *parent_tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
proto_item *item=NULL;
proto_tree *tree=NULL;
guint16 dns_offset, dns_len;
guint16 upn_offset, upn_len;
const char *dn;
int dn_len;
guint16 bc;
item=proto_tree_add_item(parent_tree, hf_krb_PAC_UPN_DNS_INFO, tvb, offset, tvb_length_remaining(tvb, offset), ENC_NA);
if(parent_tree){
tree=proto_item_add_subtree(item, ett_krb_PAC_UPN_DNS_INFO);
}
upn_len = tvb_get_letohs(tvb, offset);
proto_tree_add_item(tree, hf_krb_pac_upn_upn_len, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
upn_offset = tvb_get_letohs(tvb, offset);
proto_tree_add_item(tree, hf_krb_pac_upn_upn_offset, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
dns_len = tvb_get_letohs(tvb, offset);
proto_tree_add_item(tree, hf_krb_pac_upn_dns_len, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
dns_offset = tvb_get_letohs(tvb, offset);
proto_tree_add_item(tree, hf_krb_pac_upn_dns_offset, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_krb_pac_upn_flags, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset = upn_offset;
dn_len = upn_len;
bc = tvb_length_remaining(tvb, offset);
dn = get_unicode_or_ascii_string(tvb, &offset,
TRUE, &dn_len, TRUE, TRUE, &bc);
proto_tree_add_string(tree, hf_krb_pac_upn_upn_name, tvb, upn_offset, upn_len, dn);
offset = dns_offset;
dn_len = dns_len;
bc = tvb_length_remaining(tvb, offset);
dn = get_unicode_or_ascii_string(tvb, &offset,
TRUE, &dn_len, TRUE, TRUE, &bc);
proto_tree_add_string(tree, hf_krb_pac_upn_dns_name, tvb, dns_offset, dns_len, dn);
return offset;
}
static int
dissect_krb5_PAC_CREDENTIAL_TYPE(proto_tree *parent_tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
proto_tree_add_item(parent_tree, hf_krb_PAC_CREDENTIAL_TYPE, tvb, offset, tvb_length_remaining(tvb, offset), ENC_NA);
return offset;
}
static int
dissect_krb5_PAC_SERVER_CHECKSUM(proto_tree *parent_tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
proto_item *item=NULL;
proto_tree *tree=NULL;
item=proto_tree_add_item(parent_tree, hf_krb_PAC_SERVER_CHECKSUM, tvb, offset, tvb_length_remaining(tvb, offset), ENC_NA);
if(parent_tree){
tree=proto_item_add_subtree(item, ett_krb_PAC_SERVER_CHECKSUM);
}
proto_tree_add_item(tree, hf_krb_pac_signature_type, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset+=4;
proto_tree_add_item(tree, hf_krb_pac_signature_signature, tvb, offset, tvb_length_remaining(tvb, offset), ENC_NA);
return offset;
}
static int
dissect_krb5_PAC_PRIVSVR_CHECKSUM(proto_tree *parent_tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
proto_item *item=NULL;
proto_tree *tree=NULL;
item=proto_tree_add_item(parent_tree, hf_krb_PAC_PRIVSVR_CHECKSUM, tvb, offset, tvb_length_remaining(tvb, offset), ENC_NA);
if(parent_tree){
tree=proto_item_add_subtree(item, ett_krb_PAC_PRIVSVR_CHECKSUM);
}
proto_tree_add_item(tree, hf_krb_pac_signature_type, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset+=4;
proto_tree_add_item(tree, hf_krb_pac_signature_signature, tvb, offset, tvb_length_remaining(tvb, offset), ENC_NA);
return offset;
}
static int
dissect_krb5_PAC_CLIENT_INFO_TYPE(proto_tree *parent_tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
proto_item *item=NULL;
proto_tree *tree=NULL;
guint16 namelen;
char *name;
item=proto_tree_add_item(parent_tree, hf_krb_PAC_CLIENT_INFO_TYPE, tvb, offset, tvb_length_remaining(tvb, offset), ENC_NA);
if(parent_tree){
tree=proto_item_add_subtree(item, ett_krb_PAC_CLIENT_INFO_TYPE);
}
offset = dissect_nt_64bit_time(tvb, tree, offset,
hf_krb_pac_clientid);
namelen=tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_krb_pac_namelen, tvb, offset, 2, namelen);
offset+=2;
name=tvb_get_unicode_string(wmem_packet_scope(), tvb, offset, namelen, ENC_LITTLE_ENDIAN);
proto_tree_add_string(tree, hf_krb_pac_clientname, tvb, offset, namelen, name);
offset+=namelen;
return offset;
}
static int
dissect_krb5_AD_WIN2K_PAC_struct(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
guint32 pac_type;
guint32 pac_size;
guint32 pac_offset;
proto_item *it=NULL;
proto_tree *tr=NULL;
tvbuff_t *next_tvb;
pac_type=tvb_get_letohl(tvb, offset);
it=proto_tree_add_uint(tree, hf_krb_w2k_pac_type, tvb, offset, 4, pac_type);
if(it){
tr=proto_item_add_subtree(it, ett_krb_PAC);
}
offset += 4;
pac_size=tvb_get_letohl(tvb, offset);
proto_tree_add_uint(tr, hf_krb_w2k_pac_size, tvb, offset, 4, pac_size);
offset += 4;
pac_offset=tvb_get_letohl(tvb, offset);
proto_tree_add_uint(tr, hf_krb_w2k_pac_offset, tvb, offset, 4, pac_offset);
offset += 8;
next_tvb=tvb_new_subset(tvb, pac_offset, pac_size, pac_size);
switch(pac_type){
case PAC_LOGON_INFO:
dissect_krb5_PAC_LOGON_INFO(tr, next_tvb, 0, actx);
break;
case PAC_CREDENTIAL_TYPE:
dissect_krb5_PAC_CREDENTIAL_TYPE(tr, next_tvb, 0, actx);
break;
case PAC_SERVER_CHECKSUM:
dissect_krb5_PAC_SERVER_CHECKSUM(tr, next_tvb, 0, actx);
break;
case PAC_PRIVSVR_CHECKSUM:
dissect_krb5_PAC_PRIVSVR_CHECKSUM(tr, next_tvb, 0, actx);
break;
case PAC_CLIENT_INFO_TYPE:
dissect_krb5_PAC_CLIENT_INFO_TYPE(tr, next_tvb, 0, actx);
break;
case PAC_S4U_DELEGATION_INFO:
dissect_krb5_PAC_S4U_DELEGATION_INFO(tr, next_tvb, 0, actx);
break;
case PAC_UPN_DNS_INFO:
dissect_krb5_PAC_UPN_DNS_INFO(tr, next_tvb, 0, actx);
break;
default:;
}
return offset;
}
static int
dissect_krb5_AD_WIN2K_PAC(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
guint32 entries;
guint32 version;
guint32 i;
entries=tvb_get_letohl(tvb, offset);
proto_tree_add_uint(tree, hf_krb_w2k_pac_entries, tvb, offset, 4, entries);
offset += 4;
version=tvb_get_letohl(tvb, offset);
proto_tree_add_uint(tree, hf_krb_w2k_pac_version, tvb, offset, 4, version);
offset += 4;
for(i=0;i<entries;i++){
offset=dissect_krb5_AD_WIN2K_PAC_struct(tree, tvb, offset, actx);
}
return offset;
}
static int
dissect_krb5_AD_SIGNTICKET(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx)
{
offset=dissect_ber_old_sequence(FALSE, actx, tree, tvb, offset, AD_SIGNTICKET_sequence, -1, -1);
return offset;
}
static int
dissect_krb5_IF_RELEVANT_type(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_integer(FALSE, actx, tree, tvb, offset, hf_krb_IF_RELEVANT_type, &IF_RELEVANT_type);
if(tree){
proto_item_append_text(tree, " %s",
val_to_str(IF_RELEVANT_type, krb5_ad_types,
"%#x"));
}
return offset;
}
static int
dissect_krb5_IF_RELEVANT_value(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
switch(IF_RELEVANT_type){
case KRB5_AD_WIN2K_PAC:
offset=dissect_ber_old_octet_string_wcb(FALSE, actx, tree, tvb, offset, hf_krb_advalue, dissect_krb5_AD_WIN2K_PAC);
break;
case KRB5_AD_SIGNTICKET:
offset=dissect_ber_old_octet_string_wcb(FALSE, actx, tree, tvb, offset, hf_krb_advalue, dissect_krb5_AD_SIGNTICKET);
break;
default:
offset=dissect_ber_octet_string(FALSE, actx, tree, tvb, offset, hf_krb_IF_RELEVANT_value, NULL);
}
return offset;
}
static int
dissect_krb5_IF_RELEVANT_item(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_old_sequence(FALSE, actx, tree, tvb, offset, IF_RELEVANT_item_sequence, hf_krb_IF_RELEVANT, ett_krb_IF_RELEVANT);
return offset;
}
static int
dissect_krb5_IF_RELEVANT(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_old_sequence_of(FALSE, actx, tree, tvb, offset, IF_RELEVANT_sequence_of, -1, -1);
return offset;
}
static int
dissect_krb5_adtype(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_integer(FALSE, actx, tree, tvb, offset, hf_krb_adtype, &adtype);
if(tree){
proto_item_append_text(tree, " %s",
val_to_str(adtype, krb5_ad_types,
"%#x"));
}
return offset;
}
static int
dissect_krb5_advalue(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
switch(adtype){
case KRB5_AD_IF_RELEVANT:
offset=dissect_ber_old_octet_string_wcb(FALSE, actx, tree, tvb, offset, hf_krb_advalue, dissect_krb5_IF_RELEVANT);
break;
default:
offset=dissect_ber_octet_string(FALSE, actx, tree, tvb, offset, hf_krb_advalue, NULL);
}
return offset;
}
static int
dissect_krb5_AuthorizationData_item(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_old_sequence(FALSE, actx, tree, tvb, offset, AuthorizationData_item_sequence, hf_krb_AuthorizationData, ett_krb_AuthorizationData);
return offset;
}
static int
dissect_krb5_AuthorizationData(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_old_sequence_of(FALSE, actx, tree, tvb, offset, AuthorizationData_sequence_of, -1, -1);
return offset;
}
static int
dissect_krb5_transited_type(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
guint32 trtype;
offset=dissect_ber_integer(FALSE, actx, tree, tvb, offset, hf_krb_transitedtype, &trtype);
if(tree){
proto_item_append_text(tree, " %s",
val_to_str(trtype, krb5_transited_types,
"%#x"));
}
return offset;
}
static int
dissect_krb5_transited_contents(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_octet_string(FALSE, actx, tree, tvb, offset, hf_krb_transitedcontents, NULL);
return offset;
}
static int
dissect_krb5_transited(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_old_sequence(FALSE, actx, tree, tvb, offset, TransitedEncoding_sequence, hf_krb_TransitedEncoding, ett_krb_TransitedEncoding);
return offset;
}
static int
dissect_krb5_authtime(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_GeneralizedTime(FALSE, actx, tree, tvb, offset, hf_krb_authtime);
return offset;
}
static int
dissect_krb5_starttime(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_GeneralizedTime(FALSE, actx, tree, tvb, offset, hf_krb_starttime);
return offset;
}
static int
dissect_krb5_endtime(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_GeneralizedTime(FALSE, actx, tree, tvb, offset, hf_krb_endtime);
return offset;
}
static int
dissect_krb5_renew_till(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_GeneralizedTime(FALSE, actx, tree, tvb, offset, hf_krb_renew_till);
return offset;
}
static int
dissect_krb5_EncTicketPart(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_old_sequence(FALSE, actx, tree, tvb, offset, EncTicketPart_sequence, hf_krb_EncTicketPart, ett_krb_EncTicketPart);
return offset;
}
static int
dissect_krb5_EncAPRepPart(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_old_sequence(FALSE, actx, tree, tvb, offset, EncAPRepPart_sequence, hf_krb_EncAPRepPart, ett_krb_EncAPRepPart);
return offset;
}
static int
dissect_krb5_lr_type(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_integer(FALSE, actx, tree, tvb, offset, hf_krb_lr_type, &lr_type);
return offset;
}
static int
dissect_krb5_lr_value(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_GeneralizedTime(FALSE, actx, tree, tvb, offset, hf_krb_lr_time);
return offset;
}
static int
dissect_krb5_LastReq(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_old_sequence(FALSE, actx, tree, tvb, offset, LastReq_sequence, hf_krb_LastReq, ett_krb_LastReq);
return offset;
}
static int
dissect_krb5_LastReq_sequence_of(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_old_sequence_of(FALSE, actx, tree, tvb, offset, LastReq_sequence_of, hf_krb_LastReqs, ett_krb_LastReqs);
return offset;
}
static int
dissect_krb5_key_expiration(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_GeneralizedTime(FALSE, actx, tree, tvb, offset, hf_krb_key_expire);
return offset;
}
static int
dissect_krb5_EncKDCRepPart(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_old_sequence(FALSE, actx, tree, tvb, offset, EncKDCRepPart_sequence, hf_krb_EncKDCRepPart, ett_krb_EncKDCRepPart);
return offset;
}
static int
dissect_krb5_authenticator_vno(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_integer(FALSE, actx, tree, tvb, offset, hf_krb_authenticator_vno, NULL);
return offset;
}
static int
dissect_krb5_rfc1964_checksum(asn1_ctx_t *actx _U_, proto_tree *tree, tvbuff_t *tvb)
{
int offset=0;
guint32 len;
guint16 dlglen;
len=tvb_get_letohl(tvb, offset);
proto_tree_add_item(tree, hf_krb_gssapi_len, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_krb_gssapi_bnd, tvb, offset, len, ENC_NA);
offset += len;
proto_tree_add_item(tree, hf_krb_gssapi_c_flag_dce_style, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_krb_gssapi_c_flag_integ, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_krb_gssapi_c_flag_conf, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_krb_gssapi_c_flag_sequence, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_krb_gssapi_c_flag_replay, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_krb_gssapi_c_flag_mutual, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_krb_gssapi_c_flag_deleg, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
if(tvb_length_remaining(tvb, offset)<2){
return offset;
}
proto_tree_add_item(tree, hf_krb_gssapi_dlgopt, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
if(tvb_length_remaining(tvb, offset)<2){
return offset;
}
dlglen=tvb_get_letohs(tvb, offset);
proto_tree_add_item(tree, hf_krb_gssapi_dlglen, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
if(dlglen!=tvb_length_remaining(tvb, offset)){
proto_tree_add_text(tree, tvb, 0, 0, "Error: DlgLen:%d is not the same as number of bytes remaining:%d", dlglen, tvb_length_remaining(tvb, offset));
return offset;
}
offset=dissect_ber_old_choice(actx, tree, tvb, offset, kerberos_applications_choice, -1, -1, NULL);
return offset;
}
static int
dissect_krb5_checksum_type(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_integer(FALSE, actx, tree, tvb, offset, hf_krb_checksum_type, &checksum_type);
return offset;
}
static int
dissect_krb5_checksum_checksum(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
tvbuff_t *next_tvb;
switch(checksum_type){
case KRB5_CHKSUM_GSSAPI:
offset=dissect_ber_octet_string(FALSE, actx, tree, tvb, offset, hf_krb_checksum_checksum, &next_tvb);
dissect_krb5_rfc1964_checksum(actx, tree, next_tvb);
break;
default:
offset=dissect_ber_octet_string(FALSE, actx, tree, tvb, offset, hf_krb_checksum_checksum, NULL);
}
return offset;
}
int
dissect_krb5_Checksum(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_old_sequence(FALSE, actx, tree, tvb, offset, Checksum_sequence, hf_krb_Checksum, ett_krb_Checksum);
return offset;
}
static int
dissect_krb5_Authenticator(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_old_sequence(FALSE, actx, tree, tvb, offset, Authenticator_sequence, hf_krb_Authenticator, ett_krb_Authenticator);
return offset;
}
static int
dissect_krb5_PRIV_BODY_user_data(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
tvbuff_t *new_tvb;
offset=dissect_ber_octet_string(FALSE, actx, tree, tvb, offset, hf_krb_PRIV_BODY_user_data, &new_tvb);
if (new_tvb)
call_kerberos_callbacks(actx->pinfo, tree, new_tvb, KRB_CBTAG_PRIV_USER_DATA);
return offset;
}
static int
dissect_krb5_EncKrbPrivPart(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_old_sequence(FALSE, actx, tree, tvb, offset, EncKrbPrivPart_sequence, hf_krb_EncKrbPrivPart, ett_krb_EncKrbPrivPart);
return offset;
}
static int
dissect_krb5_PRIV_etype(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_integer(FALSE, actx, tree, tvb, offset, hf_krb_etype, &PRIV_etype);
if(tree){
proto_item_append_text(tree, " %s",
val_to_str(PRIV_etype, krb5_encryption_types,
"%#x"));
}
return offset;
}
static int
dissect_krb5_decrypt_PRIV (proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
guint8 *plaintext=NULL;
int length;
length=tvb_length_remaining(tvb, offset);
if(!plaintext){
tvbuff_t *next_tvb;
next_tvb=tvb_new_subset_remaining(tvb, offset);
plaintext=decrypt_krb5_data(tree, actx->pinfo, 13, next_tvb, PRIV_etype, NULL);
}
if(plaintext){
tvbuff_t *next_tvb;
next_tvb = tvb_new_child_real_data(tvb, plaintext,
length,
length);
tvb_set_free_cb(next_tvb, g_free);
add_new_data_source(actx->pinfo, next_tvb, "Decrypted Krb5");
offset=dissect_ber_old_choice(actx, tree, next_tvb, 0, kerberos_applications_choice, -1, -1, NULL);
}
return offset;
}
static int
dissect_krb5_encrypted_PRIV(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
#ifdef HAVE_KERBEROS
offset=dissect_ber_old_octet_string_wcb(FALSE, actx, tree, tvb, offset, hf_krb_encrypted_PRIV, dissect_krb5_decrypt_PRIV);
#else
offset=dissect_ber_old_octet_string_wcb(FALSE, actx, tree, tvb, offset, hf_krb_encrypted_PRIV, NULL);
#endif
return offset;
}
static int
dissect_krb5_ENC_PRIV(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_old_sequence(FALSE, actx, tree, tvb, offset, ENC_PRIV_sequence, hf_krb_ENC_PRIV, ett_krb_PRIV_enc);
return offset;
}
static int
dissect_krb5_PRIV(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_old_sequence(FALSE, actx, tree, tvb, offset, PRIV_BODY_sequence, hf_krb_PRIV_BODY, ett_krb_PRIV);
return offset;
}
static int
dissect_krb5_EncKrbCredPart_etype(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_integer(FALSE, actx, tree, tvb, offset, hf_krb_etype, &EncKrbCredPart_etype);
if(tree){
proto_item_append_text(tree, " %s",
val_to_str(EncKrbCredPart_etype, krb5_encryption_types,
"%#x"));
}
return offset;
}
static int
dissect_krb5_KrbCredInfo(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_old_sequence(FALSE, actx, tree, tvb, offset, KrbCredInfo_sequence, hf_krb_KrbCredInfo, ett_krb_KrbCredInfo);
return offset;
}
static int
dissect_krb5_KrbCredInfo_sequence_of(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_old_sequence_of(FALSE, actx, tree, tvb, offset, KrbCredInfo_sequence_of, hf_krb_KrbCredInfos, ett_krb_KrbCredInfos);
return offset;
}
static int
dissect_krb5_EncKrbCredPart(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_old_sequence(FALSE, actx, tree, tvb, offset, EncKrbCredPart_sequence, hf_krb_EncKrbCredPart, ett_krb_EncKrbCredPart);
return offset;
}
static int
dissect_krb5_decrypt_EncKrbCredPart (proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
guint8 *plaintext=NULL;
int length;
tvbuff_t *next_tvb;
next_tvb=tvb_new_subset_remaining(tvb, offset);
length=tvb_length_remaining(tvb, offset);
if(!plaintext){
plaintext=decrypt_krb5_data(tree, actx->pinfo, 14, next_tvb, EncKrbCredPart_etype, NULL);
}
if(plaintext){
tvbuff_t *child_tvb;
child_tvb = tvb_new_child_real_data(tvb, plaintext,
length,
length);
tvb_set_free_cb(child_tvb, g_free);
add_new_data_source(actx->pinfo, child_tvb, "EncKrbCredPart");
offset=dissect_ber_old_choice(actx, tree, child_tvb, 0, kerberos_applications_choice, -1, -1, NULL);
}
return offset;
}
static int
dissect_krb5_encrypted_CRED_data(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
#ifdef HAVE_KERBEROS
offset=dissect_ber_old_octet_string_wcb(FALSE, actx, tree, tvb, offset, hf_krb_encrypted_EncKrbCredPart, dissect_krb5_decrypt_EncKrbCredPart);
#else
offset=dissect_ber_old_octet_string_wcb(FALSE, actx, tree, tvb, offset, hf_krb_encrypted_EncKrbCredPart, NULL);
#endif
return offset;
}
static int
dissect_krb5_encrypted_CRED(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_old_sequence(FALSE, actx, tree, tvb, offset, encrypted_CRED_sequence, hf_krb_CRED_enc, ett_krb_CRED_enc);
return offset;
}
static int
dissect_krb5_CRED(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_old_sequence(FALSE, actx, tree, tvb, offset, CRED_BODY_sequence, hf_krb_CRED_BODY, ett_krb_CRED);
return offset;
}
static int
dissect_krb5_SAFE_BODY_user_data(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
tvbuff_t *new_tvb;
offset=dissect_ber_octet_string(FALSE, actx, tree, tvb, offset, hf_krb_SAFE_BODY_user_data, &new_tvb);
if (new_tvb)
call_kerberos_callbacks(actx->pinfo, tree, new_tvb, KRB_CBTAG_SAFE_USER_DATA);
return offset;
}
static int
dissect_krb5_SAFE_BODY_timestamp(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_GeneralizedTime(FALSE, actx, tree, tvb, offset, hf_krb_SAFE_BODY_timestamp);
return offset;
}
static int
dissect_krb5_SAFE_BODY_usec(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_integer(FALSE, actx, tree, tvb, offset, hf_krb_SAFE_BODY_usec, NULL);
return offset;
}
static int
dissect_krb5_SAFE_BODY(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_old_sequence(FALSE, actx, tree, tvb, offset, SAFE_BODY_sequence, -1, -1);
return offset;
}
static int
dissect_krb5_SAFE(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_old_sequence(FALSE, actx, tree, tvb, offset, SAFE_sequence, -1, -1);
return offset;
}
static int
dissect_krb5_decrypt_enc_authorization_data(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
guint8 *plaintext=NULL;
int length;
tvbuff_t *next_tvb;
next_tvb=tvb_new_subset_remaining(tvb, offset);
length=tvb_length_remaining(tvb, offset);
if(!plaintext){
plaintext=decrypt_krb5_data(tree, actx->pinfo, 4, next_tvb, enc_authorization_data_etype, NULL);
}
if(!plaintext){
plaintext=decrypt_krb5_data(tree, actx->pinfo, 5, next_tvb, enc_authorization_data_etype, NULL);
}
if(plaintext){
tvbuff_t *child_tvb;
child_tvb = tvb_new_child_real_data(tvb, plaintext,
length,
length);
tvb_set_free_cb(child_tvb, g_free);
add_new_data_source(actx->pinfo, child_tvb, "Decrypted Krb5");
proto_tree_add_text(tree, child_tvb, 0, length, "AtuhorizationData for TGS_REQ not implemented yet");
}
return offset;
}
static int
dissect_krb5_encrypted_enc_authorization_data(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
#ifdef HAVE_KERBEROS
offset=dissect_ber_old_octet_string_wcb(FALSE, actx, tree, tvb, offset, hf_krb_encrypted_enc_authorization_data, dissect_krb5_decrypt_enc_authorization_data);
#else
offset=dissect_ber_old_octet_string_wcb(FALSE, actx, tree, tvb, offset, hf_krb_encrypted_enc_authorization_data, NULL);
#endif
return offset;
}
static int
dissect_krb5_enc_authorization_data_etype(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
#ifndef HAVE_KERBEROS
guint32 enc_authorization_data_etype;
#endif
offset=dissect_ber_integer(FALSE, actx, tree, tvb, offset, hf_krb_etype, &enc_authorization_data_etype);
if(tree){
proto_item_append_text(tree, " %s",
val_to_str(enc_authorization_data_etype, krb5_encryption_types,
"%#x"));
}
return offset;
}
static int
dissect_krb5_enc_authorization_data(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_old_sequence(FALSE, actx, tree, tvb, offset, enc_authorization_data_sequence, -1, -1);
return offset;
}
static int
dissect_krb5_KDC_REQ_BODY(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
conversation_t *conversation;
if (actx->pinfo->destport == UDP_PORT_KERBEROS && actx->pinfo->ptype == PT_UDP) {
conversation = find_conversation(actx->pinfo->fd->num, &actx->pinfo->src, &actx->pinfo->dst, PT_UDP,
actx->pinfo->srcport, 0, NO_PORT_B);
if (conversation == NULL) {
conversation = conversation_new(actx->pinfo->fd->num, &actx->pinfo->src, &actx->pinfo->dst, PT_UDP,
actx->pinfo->srcport, 0, NO_PORT2);
conversation_set_dissector(conversation, kerberos_handle_udp);
}
}
offset=dissect_ber_old_sequence(FALSE, actx, tree, tvb, offset, KDC_REQ_BODY_sequence, hf_krb_KDC_REQ_BODY, ett_krb_request);
return offset;
}
static int
dissect_krb5_KDC_REQ(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_old_sequence(FALSE, actx, tree, tvb, offset, KDC_REQ_sequence, -1, -1);
return offset;
}
static int
dissect_krb5_decrypt_authenticator_data (proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
guint8 *plaintext=NULL;
int length;
tvbuff_t *next_tvb;
next_tvb=tvb_new_subset_remaining(tvb, offset);
length=tvb_length_remaining(tvb, offset);
if(!plaintext){
plaintext=decrypt_krb5_data(tree, actx->pinfo, 7, next_tvb, authenticator_etype, NULL);
}
if(!plaintext){
plaintext=decrypt_krb5_data(tree, actx->pinfo, 11, next_tvb, authenticator_etype, NULL);
}
if(plaintext){
tvbuff_t *child_tvb;
child_tvb = tvb_new_child_real_data(tvb, plaintext,
length,
length);
tvb_set_free_cb(child_tvb, g_free);
add_new_data_source(actx->pinfo, child_tvb, "Decrypted Krb5");
offset=dissect_ber_old_choice(actx, tree, child_tvb, 0, kerberos_applications_choice, -1, -1, NULL);
}
return offset;
}
static int
dissect_krb5_encrypted_authenticator_data(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
#ifdef HAVE_KERBEROS
offset=dissect_ber_old_octet_string_wcb(FALSE, actx, tree, tvb, offset, hf_krb_encrypted_authenticator_data, dissect_krb5_decrypt_authenticator_data);
#else
offset=dissect_ber_old_octet_string_wcb(FALSE, actx, tree, tvb, offset, hf_krb_encrypted_authenticator_data, NULL);
#endif
return offset;
}
static int
dissect_krb5_encrypted_authenticator(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_old_sequence(FALSE, actx, tree, tvb, offset, encrypted_authenticator_sequence, hf_krb_authenticator_enc, ett_krb_authenticator_enc);
return offset;
}
static int
dissect_krb5_tkt_vno(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_integer(FALSE, actx, tree, tvb, offset, hf_krb_tkt_vno, NULL);
return offset;
}
static int
dissect_krb5_decrypt_Ticket_data (proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
guint8 *plaintext;
int length;
tvbuff_t *next_tvb;
next_tvb=tvb_new_subset_remaining(tvb, offset);
length=tvb_length_remaining(tvb, offset);
if( (plaintext=decrypt_krb5_data(tree, actx->pinfo, 2, next_tvb, Ticket_etype, NULL)) ){
tvbuff_t *child_tvb;
child_tvb = tvb_new_child_real_data(tvb, plaintext,
length,
length);
tvb_set_free_cb(child_tvb, g_free);
add_new_data_source(actx->pinfo, child_tvb, "Decrypted Krb5");
offset=dissect_ber_old_choice(actx, tree, child_tvb, 0, kerberos_applications_choice, -1, -1, NULL);
}
return offset;
}
static int
dissect_krb5_encrypted_Ticket_data(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
#ifdef HAVE_KERBEROS
offset=dissect_ber_old_octet_string_wcb(FALSE, actx, tree, tvb, offset, hf_krb_encrypted_Ticket_data, dissect_krb5_decrypt_Ticket_data);
#else
offset=dissect_ber_old_octet_string_wcb(FALSE, actx, tree, tvb, offset, hf_krb_encrypted_Ticket_data, NULL);
#endif
return offset;
}
static int
dissect_krb5_Ticket_encrypted(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_old_sequence(FALSE, actx, tree, tvb, offset, encrypted_Ticket_sequence, hf_krb_ticket_enc, ett_krb_ticket_enc);
return offset;
}
static int
dissect_krb5_Application_1(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_old_sequence(FALSE, actx, tree, tvb, offset, Application_1_sequence, hf_krb_ticket, ett_krb_ticket);
return offset;
}
static int
dissect_krb5_Ticket(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_old_choice(actx, tree, tvb, offset, Ticket_choice, -1, -1, NULL);
return offset;
}
static int
dissect_krb5_AP_REQ(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_old_sequence(FALSE, actx, tree, tvb, offset, AP_REQ_sequence, -1, -1);
return offset;
}
static int
dissect_krb5_decrypt_AP_REP_data(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
guint8 *plaintext=NULL;
int length;
length=tvb_length_remaining(tvb, offset);
if(!plaintext){
tvbuff_t *next_tvb;
next_tvb=tvb_new_subset_remaining(tvb, offset);
plaintext=decrypt_krb5_data(tree, actx->pinfo, 12, next_tvb, AP_REP_etype, NULL);
}
if(plaintext){
tvbuff_t *next_tvb;
next_tvb = tvb_new_child_real_data(tvb, plaintext,
length,
length);
tvb_set_free_cb(next_tvb, g_free);
add_new_data_source(actx->pinfo, next_tvb, "Decrypted Krb5");
offset=dissect_ber_old_choice(actx, tree, next_tvb, 0, kerberos_applications_choice, -1, -1, NULL);
}
return offset;
}
static int
dissect_krb5_encrypted_AP_REP_data(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
#ifdef HAVE_KERBEROS
offset=dissect_ber_old_octet_string_wcb(FALSE, actx, tree, tvb, offset, hf_krb_encrypted_AP_REP_data, dissect_krb5_decrypt_AP_REP_data);
#else
offset=dissect_ber_old_octet_string_wcb(FALSE, actx, tree, tvb, offset, hf_krb_encrypted_AP_REP_data, NULL);
#endif
return offset;
}
static int
dissect_krb5_encrypted_AP_REP(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_old_sequence(FALSE, actx, tree, tvb, offset, encrypted_AP_REP_sequence, hf_krb_AP_REP_enc, ett_krb_AP_REP_enc);
return offset;
}
static int
dissect_krb5_AP_REP(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_old_sequence(FALSE, actx, tree, tvb, offset, AP_REP_sequence, -1, -1);
return offset;
}
static int
dissect_krb5_KDC_REP_etype(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_integer(FALSE, actx, tree, tvb, offset, hf_krb_etype, &KDC_REP_etype);
if(tree){
proto_item_append_text(tree, " %s",
val_to_str(KDC_REP_etype, krb5_encryption_types,
"%#x"));
}
return offset;
}
static int
dissect_krb5_decrypt_KDC_REP_data (proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
guint8 *plaintext=NULL;
int length;
tvbuff_t *next_tvb;
next_tvb=tvb_new_subset_remaining(tvb, offset);
length=tvb_length_remaining(tvb, offset);
if(!plaintext){
plaintext=decrypt_krb5_data(tree, actx->pinfo, 3, next_tvb, KDC_REP_etype, NULL);
}
if(!plaintext){
plaintext=decrypt_krb5_data(tree, actx->pinfo, 8, next_tvb, KDC_REP_etype, NULL);
}
if(!plaintext){
plaintext=decrypt_krb5_data(tree, actx->pinfo, 9, next_tvb, KDC_REP_etype, NULL);
}
if(plaintext){
tvbuff_t *child_tvb;
child_tvb = tvb_new_child_real_data(tvb, plaintext,
length,
length);
tvb_set_free_cb(child_tvb, g_free);
add_new_data_source(actx->pinfo, child_tvb, "Decrypted Krb5");
offset=dissect_ber_old_choice(actx, tree, child_tvb, 0, kerberos_applications_choice, -1, -1, NULL);
}
return offset;
}
static int
dissect_krb5_encrypted_KDC_REP_data(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
#ifdef HAVE_KERBEROS
offset=dissect_ber_old_octet_string_wcb(FALSE, actx, tree, tvb, offset, hf_krb_encrypted_KDC_REP_data, dissect_krb5_decrypt_KDC_REP_data);
#else
offset=dissect_ber_old_octet_string_wcb(FALSE, actx, tree, tvb, offset, hf_krb_encrypted_KDC_REP_data, NULL);
#endif
return offset;
}
static int
dissect_krb5_encrypted_KDC_REP(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_old_sequence(FALSE, actx, tree, tvb, offset, encrypted_KDC_REP_sequence, hf_krb_KDC_REP_enc, ett_krb_KDC_REP_enc);
return offset;
}
static int
dissect_krb5_KDC_REP(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_old_sequence(FALSE, actx, tree, tvb, offset, KDC_REP_sequence, -1, -1);
return offset;
}
static int
dissect_krb5_e_text(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_GeneralString(actx, tree, tvb, offset, hf_krb_e_text, NULL, 0);
return offset;
}
static int
dissect_krb5_e_data(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
switch(krb5_errorcode){
case KRB5_ET_KRB5KDC_ERR_BADOPTION:
case KRB5_ET_KRB5KDC_ERR_CLIENT_REVOKED:
case KRB5_ET_KRB5KDC_ERR_KEY_EXP:
case KRB5_ET_KRB5KDC_ERR_POLICY:
offset=dissect_ber_old_octet_string_wcb(FALSE, actx, tree, tvb, offset, hf_krb_e_data, dissect_krb5_PA_DATA);
break;
case KRB5_ET_KRB5KDC_ERR_PREAUTH_REQUIRED:
case KRB5_ET_KRB5KDC_ERR_PREAUTH_FAILED:
case KRB5_ET_KRB5KDC_ERR_ETYPE_NOSUPP:
offset=dissect_ber_old_octet_string_wcb(FALSE, actx, tree, tvb, offset, hf_krb_e_data, dissect_krb5_padata);
break;
default:
offset=dissect_ber_octet_string(FALSE, actx, tree, tvb, offset, hf_krb_e_data, NULL);
}
return offset;
}
static int
dissect_krb5_e_checksum(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_old_sequence(FALSE, actx, tree, tvb, offset, Checksum_sequence, hf_krb_e_checksum, ett_krb_e_checksum);
return offset;
}
int
dissect_krb5_ERROR(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
offset=dissect_ber_old_sequence(FALSE, actx, tree, tvb, offset, ERROR_sequence, -1, -1);
return offset;
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
dissect_kerberos_udp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
if(tvb_length(tvb) >= 1 && tvb_get_guint8(tvb, 0)<=0x10){
if(krb4_handle){
gboolean res;
res=call_dissector_only(krb4_handle, tvb, pinfo, tree, NULL);
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
dissect_kerberos_tcp_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
pinfo->fragmented = TRUE;
if (dissect_kerberos_common(tvb, pinfo, tree, TRUE, TRUE, TRUE, NULL) < 0) {
col_set_str(pinfo->cinfo, COL_INFO, "Continuation");
}
}
static void
dissect_kerberos_tcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
col_set_str(pinfo->cinfo, COL_PROTOCOL, "KRB5");
col_clear(pinfo->cinfo, COL_INFO);
tcp_dissect_pdus(tvb, pinfo, tree, krb_desegment, 4, get_krb_pdu_len,
dissect_kerberos_tcp_pdu);
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
gbl_do_col_info=dci;
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
kerberos_tree = proto_item_add_subtree(item, ett_krb_kerberos);
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
if (gbl_do_col_info) {
col_clear(pinfo->cinfo, COL_INFO);
}
if (tree) {
item = proto_tree_add_item(tree, proto_kerberos, tvb, 0, -1, ENC_NA);
kerberos_tree = proto_item_add_subtree(item, ett_krb_kerberos);
}
}
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
TRY {
offset=dissect_ber_old_choice(&asn1_ctx, kerberos_tree, tvb, offset, kerberos_applications_choice, -1, -1, NULL);
} CATCH_BOUNDS_ERRORS {
pinfo->private_data=saved_private_data;
RETHROW;
} ENDTRY;
proto_item_set_len(item, offset);
pinfo->private_data=saved_private_data;
return offset;
}
static void
kerberos_prefs_apply_cb(void) {
#ifdef HAVE_LIBNETTLE
clear_keytab();
read_keytab_file(keytab_filename);
#endif
}
void
proto_register_kerberos(void)
{
static hf_register_info hf[] = {
{ &hf_krb_rm_reserved, {
"Reserved", "kerberos.rm.reserved", FT_BOOLEAN, 32,
TFS(&tfs_set_notset), KRB_RM_RESERVED, "Record mark reserved bit", HFILL }},
{ &hf_krb_rm_reclen, {
"Record Length", "kerberos.rm.length", FT_UINT32, BASE_DEC,
NULL, KRB_RM_RECLEN, NULL, HFILL }},
{ &hf_krb_transitedtype, {
"Type", "kerberos.transited.type", FT_UINT32, BASE_DEC,
VALS(krb5_transited_types), 0, "Transited Type", HFILL }},
{ &hf_krb_transitedcontents, {
"Contents", "kerberos.transited.contents", FT_BYTES, BASE_NONE,
NULL, 0, "Transited Contents string", HFILL }},
{ &hf_krb_keytype, {
"Key type", "kerberos.keytype", FT_UINT32, BASE_DEC,
VALS(krb5_encryption_types), 0, NULL, HFILL }},
{ &hf_krb_keyvalue, {
"Key value", "kerberos.keyvalue", FT_BYTES, BASE_NONE,
NULL, 0, "Key value (encryption key)", HFILL }},
{ &hf_krb_adtype, {
"Type", "kerberos.adtype", FT_UINT32, BASE_DEC,
VALS(krb5_ad_types), 0, "Authorization Data Type", HFILL }},
{ &hf_krb_IF_RELEVANT_type, {
"Type", "kerberos.IF_RELEVANT.type", FT_UINT32, BASE_DEC,
VALS(krb5_ad_types), 0, "IF-RELEVANT Data Type", HFILL }},
{ &hf_krb_advalue, {
"Data", "kerberos.advalue", FT_BYTES, BASE_NONE,
NULL, 0, "Authentication Data", HFILL }},
{ &hf_krb_IF_RELEVANT_value, {
"Data", "kerberos.IF_RELEVANT.value", FT_BYTES, BASE_NONE,
NULL, 0, "IF_RELEVANT Data", HFILL }},
{ &hf_krb_etype, {
"Encryption type", "kerberos.etype", FT_INT32, BASE_DEC,
VALS(krb5_encryption_types), 0, NULL, HFILL }},
{ &hf_krb_addr_type, {
"Addr-type", "kerberos.addr_type", FT_UINT32, BASE_DEC,
VALS(krb5_address_types), 0, "Address Type", HFILL }},
{ &hf_krb_pac_signature_type, {
"Type", "kerberos.pac.signature.type", FT_INT32, BASE_DEC,
NULL, 0, "PAC Signature Type", HFILL }},
{ &hf_krb_name_type, {
"Name-type", "kerberos.name_type", FT_INT32, BASE_DEC,
VALS(krb5_princ_types), 0, "Type of principal name", HFILL }},
{ &hf_krb_lr_type, {
"Lr-type", "kerberos.lr_type", FT_UINT32, BASE_DEC,
VALS(krb5_lr_types), 0, "Type of lastreq value", HFILL }},
{ &hf_krb_address_ip, {
"IP Address", "kerberos.addr_ip", FT_IPv4, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_krb_address_ipv6, {
"IPv6 Address", "kerberos.addr_ipv6", FT_IPv6, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_krb_address_netbios, {
"NetBIOS Address", "kerberos.addr_nb", FT_STRING, BASE_NONE,
NULL, 0, "NetBIOS Address and type", HFILL }},
{ &hf_krb_authtime, {
"Authtime", "kerberos.authtime", FT_STRING, BASE_NONE,
NULL, 0, "Time of initial authentication", HFILL }},
{ &hf_krb_SAFE_BODY_timestamp, {
"Timestamp", "kerberos.SAFE_BODY.timestamp", FT_STRING, BASE_NONE,
NULL, 0, "Timestamp of this SAFE_BODY", HFILL }},
{ &hf_krb_patimestamp, {
"patimestamp", "kerberos.patimestamp", FT_STRING, BASE_NONE,
NULL, 0, "Time of client", HFILL }},
{ &hf_krb_pausec, {
"pausec", "kerberos.pausec", FT_UINT32, BASE_DEC,
NULL, 0, "Microsecond component of client time", HFILL }},
{ &hf_krb_lr_time, {
"Lr-time", "kerberos.lr_time", FT_STRING, BASE_NONE,
NULL, 0, "Time of LR-entry", HFILL }},
{ &hf_krb_starttime, {
"Start time", "kerberos.starttime", FT_STRING, BASE_NONE,
NULL, 0, "The time after which the ticket is valid", HFILL }},
{ &hf_krb_endtime, {
"End time", "kerberos.endtime", FT_STRING, BASE_NONE,
NULL, 0, "The time after which the ticket has expired", HFILL }},
{ &hf_krb_key_expire, {
"Key Expiration", "kerberos.key_expiration", FT_STRING, BASE_NONE,
NULL, 0, "The time after which the key will expire", HFILL }},
{ &hf_krb_renew_till, {
"Renew-till", "kerberos.renenw_till", FT_STRING, BASE_NONE,
NULL, 0, "The maximum time we can renew the ticket until", HFILL }},
{ &hf_krb_rtime, {
"rtime", "kerberos.rtime", FT_STRING, BASE_NONE,
NULL, 0, "Renew Until timestamp", HFILL }},
{ &hf_krb_ctime, {
"ctime", "kerberos.ctime", FT_STRING, BASE_NONE,
NULL, 0, "Current Time on the client host", HFILL }},
{ &hf_krb_cusec, {
"cusec", "kerberos.cusec", FT_UINT32, BASE_DEC,
NULL, 0, "micro second component of client time", HFILL }},
{ &hf_krb_SAFE_BODY_usec, {
"usec", "kerberos.SAFE_BODY.usec", FT_UINT32, BASE_DEC,
NULL, 0, "micro second component of SAFE_BODY time", HFILL }},
{ &hf_krb_stime, {
"stime", "kerberos.stime", FT_STRING, BASE_NONE,
NULL, 0, "Current Time on the server host", HFILL }},
{ &hf_krb_susec, {
"susec", "kerberos.susec", FT_UINT32, BASE_DEC,
NULL, 0, "micro second component of server time", HFILL }},
{ &hf_krb_error_code, {
"error_code", "kerberos.error_code", FT_UINT32, BASE_DEC,
VALS(krb5_error_codes), 0, "Kerberos error code", HFILL }},
{ &hf_krb_from, {
"from", "kerberos.from", FT_STRING, BASE_NONE,
NULL, 0, "From when the ticket is to be valid (postdating)", HFILL }},
{ &hf_krb_till, {
"till", "kerberos.till", FT_STRING, BASE_NONE,
NULL, 0, "When the ticket will expire", HFILL }},
{ &hf_krb_name_string, {
"Name", "kerberos.name_string", FT_STRING, BASE_NONE,
NULL, 0, "String component that is part of a PrincipalName", HFILL }},
{ &hf_krb_provsrv_location, {
"PROVSRV Location", "kerberos.provsrv_location", FT_STRING, BASE_NONE,
NULL, 0, "PacketCable PROV SRV Location", HFILL }},
{ &hf_krb_e_text, {
"e-text", "kerberos.e_text", FT_STRING, BASE_NONE,
NULL, 0, "Additional (human readable) error description", HFILL }},
{ &hf_krb_s4u2self_auth, {
"S4U2Self Auth", "kerberos.s4u2self.auth", FT_STRING, BASE_NONE,
NULL, 0, "S4U2Self authentication string", HFILL }},
{ &hf_krb_realm, {
"Realm", "kerberos.realm", FT_STRING, BASE_NONE,
NULL, 0, "Name of the Kerberos Realm", HFILL }},
{ &hf_krb_srealm, {
"SRealm", "kerberos.srealm", FT_STRING, BASE_NONE,
NULL, 0, "Name of the Kerberos SRealm", HFILL }},
{ &hf_krb_prealm, {
"Delegated Principal Realm", "kerberos.prealm", FT_STRING, BASE_NONE,
NULL, 0, "Name of the Kerberos PRealm", HFILL }},
{ &hf_krb_crealm, {
"Client Realm", "kerberos.crealm", FT_STRING, BASE_NONE,
NULL, 0, "Name of the Clients Kerberos Realm", HFILL }},
{ &hf_krb_pac_clientname, {
"Name", "kerberos.pac.name", FT_STRING, BASE_NONE,
NULL, 0, "Name of the Client in the PAC structure", HFILL }},
{ &hf_krb_msg_type, {
"MSG Type", "kerberos.msg.type", FT_UINT32, BASE_DEC,
VALS(krb5_msg_types), 0, "Kerberos Message Type", HFILL }},
{ &hf_krb_APOptions, {
"APOptions", "kerberos.apoptions", FT_BYTES, BASE_NONE,
NULL, 0, "Kerberos APOptions bitstring", HFILL }},
{ &hf_krb_APOptions_reserved, {
"reserved", "kerberos.apoptions.reserved", FT_BOOLEAN, 32,
TFS(&krb5_apoptions_reserved), 0x80000000, NULL, HFILL }},
{ &hf_krb_APOptions_use_session_key, {
"Use Session Key", "kerberos.apoptions.use_session_key", FT_BOOLEAN, 32,
TFS(&krb5_apoptions_use_session_key), 0x40000000, NULL, HFILL }},
{ &hf_krb_APOptions_mutual_required, {
"Mutual required", "kerberos.apoptions.mutual_required", FT_BOOLEAN, 32,
TFS(&krb5_apoptions_mutual_required), 0x20000000, NULL, HFILL }},
{ &hf_krb_KDCOptions, {
"KDCOptions", "kerberos.kdcoptions", FT_BYTES, BASE_NONE,
NULL, 0, "Kerberos KDCOptions bitstring", HFILL }},
{ &hf_krb_TicketFlags, {
"Ticket Flags", "kerberos.ticketflags", FT_NONE, BASE_NONE,
NULL, 0, "Kerberos Ticket Flags", HFILL }},
{ &hf_krb_TicketFlags_forwardable, {
"Forwardable", "kerberos.ticketflags.forwardable", FT_BOOLEAN, 32,
TFS(&krb5_ticketflags_forwardable), 0x40000000, "Flag controlling whether the tickets are forwardable or not", HFILL }},
{ &hf_krb_TicketFlags_forwarded, {
"Forwarded", "kerberos.ticketflags.forwarded", FT_BOOLEAN, 32,
TFS(&krb5_ticketflags_forwarded), 0x20000000, "Has this ticket been forwarded?", HFILL }},
{ &hf_krb_TicketFlags_proxiable, {
"Proxiable", "kerberos.ticketflags.proxiable", FT_BOOLEAN, 32,
TFS(&krb5_ticketflags_proxiable), 0x10000000, "Flag controlling whether the tickets are proxiable or not", HFILL }},
{ &hf_krb_TicketFlags_proxy, {
"Proxy", "kerberos.ticketflags.proxy", FT_BOOLEAN, 32,
TFS(&krb5_ticketflags_proxy), 0x08000000, "Has this ticket been proxied?", HFILL }},
{ &hf_krb_TicketFlags_allow_postdate, {
"Allow Postdate", "kerberos.ticketflags.allow_postdate", FT_BOOLEAN, 32,
TFS(&krb5_ticketflags_allow_postdate), 0x04000000, "Flag controlling whether we allow postdated tickets or not", HFILL }},
{ &hf_krb_TicketFlags_postdated, {
"Postdated", "kerberos.ticketflags.postdated", FT_BOOLEAN, 32,
TFS(&krb5_ticketflags_postdated), 0x02000000, "Whether this ticket is postdated or not", HFILL }},
{ &hf_krb_TicketFlags_invalid, {
"Invalid", "kerberos.ticketflags.invalid", FT_BOOLEAN, 32,
TFS(&krb5_ticketflags_invalid), 0x01000000, "Whether this ticket is invalid or not", HFILL }},
{ &hf_krb_TicketFlags_renewable, {
"Renewable", "kerberos.ticketflags.renewable", FT_BOOLEAN, 32,
TFS(&krb5_ticketflags_renewable), 0x00800000, "Whether this ticket is renewable or not", HFILL }},
{ &hf_krb_TicketFlags_initial, {
"Initial", "kerberos.ticketflags.initial", FT_BOOLEAN, 32,
TFS(&krb5_ticketflags_initial), 0x00400000, "Whether this ticket is an initial ticket or not", HFILL }},
{ &hf_krb_TicketFlags_pre_auth, {
"Pre-Auth", "kerberos.ticketflags.pre_auth", FT_BOOLEAN, 32,
TFS(&krb5_ticketflags_pre_auth), 0x00200000, "Whether this ticket is pre-authenticated or not", HFILL }},
{ &hf_krb_TicketFlags_hw_auth, {
"HW-Auth", "kerberos.ticketflags.hw_auth", FT_BOOLEAN, 32,
TFS(&krb5_ticketflags_hw_auth), 0x00100000, "Whether this ticket is hardware-authenticated or not", HFILL }},
{ &hf_krb_TicketFlags_transited_policy_checked, {
"Transited Policy Checked", "kerberos.ticketflags.transited_policy_checked", FT_BOOLEAN, 32,
TFS(&krb5_ticketflags_transited_policy_checked), 0x00080000, "Whether this ticket is transited policy checked or not", HFILL }},
{ &hf_krb_TicketFlags_ok_as_delegate, {
"Ok As Delegate", "kerberos.ticketflags.ok_as_delegate", FT_BOOLEAN, 32,
TFS(&krb5_ticketflags_ok_as_delegate), 0x00040000, "Whether this ticket is Ok As Delegate or not", HFILL }},
{ &hf_krb_KDC_REQ_BODY, {
"KDC_REQ_BODY", "kerberos.kdc_req_body", FT_NONE, BASE_NONE,
NULL, 0, "Kerberos KDC REQuest BODY", HFILL }},
{ &hf_krb_PRIV_BODY, {
"PRIV_BODY", "kerberos.priv_body", FT_NONE, BASE_NONE,
NULL, 0, "Kerberos PRIVate BODY", HFILL }},
{ &hf_krb_CRED_BODY, {
"CRED_BODY", "kerberos.cred_body", FT_NONE, BASE_NONE,
NULL, 0, "Kerberos CREDential BODY", HFILL }},
{ &hf_krb_encrypted_PRIV, {
"Encrypted PRIV", "kerberos.enc_priv", FT_NONE, BASE_NONE,
NULL, 0, "Kerberos Encrypted PRIVate blob data", HFILL }},
{ &hf_krb_KDCOptions_forwardable, {
"Forwardable", "kerberos.kdcoptions.forwardable", FT_BOOLEAN, 32,
TFS(&krb5_kdcoptions_forwardable), 0x40000000, "Flag controlling whether the tickets are forwardable or not", HFILL }},
{ &hf_krb_KDCOptions_forwarded, {
"Forwarded", "kerberos.kdcoptions.forwarded", FT_BOOLEAN, 32,
TFS(&krb5_kdcoptions_forwarded), 0x20000000, "Has this ticket been forwarded?", HFILL }},
{ &hf_krb_KDCOptions_proxiable, {
"Proxiable", "kerberos.kdcoptions.proxiable", FT_BOOLEAN, 32,
TFS(&krb5_kdcoptions_proxiable), 0x10000000, "Flag controlling whether the tickets are proxiable or not", HFILL }},
{ &hf_krb_KDCOptions_proxy, {
"Proxy", "kerberos.kdcoptions.proxy", FT_BOOLEAN, 32,
TFS(&krb5_kdcoptions_proxy), 0x08000000, "Has this ticket been proxied?", HFILL }},
{ &hf_krb_KDCOptions_allow_postdate, {
"Allow Postdate", "kerberos.kdcoptions.allow_postdate", FT_BOOLEAN, 32,
TFS(&krb5_kdcoptions_allow_postdate), 0x04000000, "Flag controlling whether we allow postdated tickets or not", HFILL }},
{ &hf_krb_KDCOptions_postdated, {
"Postdated", "kerberos.kdcoptions.postdated", FT_BOOLEAN, 32,
TFS(&krb5_kdcoptions_postdated), 0x02000000, "Whether this ticket is postdated or not", HFILL }},
{ &hf_krb_KDCOptions_renewable, {
"Renewable", "kerberos.kdcoptions.renewable", FT_BOOLEAN, 32,
TFS(&krb5_kdcoptions_renewable), 0x00800000, "Whether this ticket is renewable or not", HFILL }},
{ &hf_krb_KDCOptions_constrained_delegation, {
"Constrained Delegation", "kerberos.kdcoptions.constrained_delegation", FT_BOOLEAN, 32,
TFS(&krb5_kdcoptions_constrained_delegation), 0x00020000, "Do we want a PAC containing constrained delegation info or not", HFILL }},
{ &hf_krb_KDCOptions_canonicalize, {
"Canonicalize", "kerberos.kdcoptions.canonicalize", FT_BOOLEAN, 32,
TFS(&krb5_kdcoptions_canonicalize), 0x00010000, "Do we want the KDC to canonicalize the principal or not", HFILL }},
{ &hf_krb_KDCOptions_opt_hardware_auth, {
"Opt HW Auth", "kerberos.kdcoptions.opt_hardware_auth", FT_BOOLEAN, 32,
NULL, 0x00100000, "Opt HW Auth flag", HFILL }},
{ &hf_krb_KDCOptions_disable_transited_check, {
"Disable Transited Check", "kerberos.kdcoptions.disable_transited_check", FT_BOOLEAN, 32,
TFS(&krb5_kdcoptions_disable_transited_check), 0x00000020, "Whether we should do transited checking or not", HFILL }},
{ &hf_krb_KDCOptions_renewable_ok, {
"Renewable OK", "kerberos.kdcoptions.renewable_ok", FT_BOOLEAN, 32,
TFS(&krb5_kdcoptions_renewable_ok), 0x00000010, "Whether we accept renewed tickets or not", HFILL }},
{ &hf_krb_KDCOptions_enc_tkt_in_skey, {
"Enc-Tkt-in-Skey", "kerberos.kdcoptions.enc_tkt_in_skey", FT_BOOLEAN, 32,
TFS(&krb5_kdcoptions_enc_tkt_in_skey), 0x00000008, "Whether the ticket is encrypted in the skey or not", HFILL }},
{ &hf_krb_KDCOptions_renew, {
"Renew", "kerberos.kdcoptions.renew", FT_BOOLEAN, 32,
TFS(&krb5_kdcoptions_renew), 0x00000002, "Is this a request to renew a ticket?", HFILL }},
{ &hf_krb_KDCOptions_validate, {
"Validate", "kerberos.kdcoptions.validate", FT_BOOLEAN, 32,
TFS(&krb5_kdcoptions_validate), 0x00000001, "Is this a request to validate a postdated ticket?", HFILL }},
{ &hf_krb_pvno, {
"Pvno", "kerberos.pvno", FT_UINT32, BASE_DEC,
NULL, 0, "Kerberos Protocol Version Number", HFILL }},
{ &hf_krb_kvno, {
"Kvno", "kerberos.kvno", FT_UINT32, BASE_DEC,
NULL, 0, "Version Number for the encryption Key", HFILL }},
{ &hf_krb_checksum_type, {
"Type", "kerberos.checksum.type", FT_UINT32, BASE_DEC,
VALS(krb5_checksum_types), 0, "Type of checksum", HFILL }},
{ &hf_krb_authenticator_vno, {
"Authenticator vno", "kerberos.authenticator_vno", FT_UINT32, BASE_DEC,
NULL, 0, "Version Number for the Authenticator", HFILL }},
{ &hf_krb_encrypted_authenticator_data, {
"Authenticator data", "kerberos.authenticator.data", FT_BYTES, BASE_NONE,
NULL, 0, "Data content of an encrypted authenticator", HFILL }},
{ &hf_krb_encrypted_EncKrbCredPart, {
"enc EncKrbCredPart", "kerberos.EncKrbCredPart.encrypted", FT_BYTES, BASE_NONE,
NULL, 0, "Encrypted EncKrbCredPart blob", HFILL }},
{ &hf_krb_encrypted_PA_ENC_TIMESTAMP, {
"enc PA_ENC_TIMESTAMP", "kerberos.PA_ENC_TIMESTAMP.encrypted", FT_BYTES, BASE_NONE,
NULL, 0, "Encrypted PA-ENC-TIMESTAMP blob", HFILL }},
{ &hf_krb_encrypted_enc_authorization_data, {
"enc-authorization-data", "kerberos.enc_authorization_data.encrypted", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_krb_PAC_LOGON_INFO, {
"PAC_LOGON_INFO", "kerberos.PAC_LOGON_INFO", FT_BYTES, BASE_NONE,
NULL, 0, "PAC_LOGON_INFO structure", HFILL }},
{ &hf_krb_PAC_CREDENTIAL_TYPE, {
"PAC_CREDENTIAL_TYPE", "kerberos.PAC_CREDENTIAL_TYPE", FT_BYTES, BASE_NONE,
NULL, 0, "PAC_CREDENTIAL_TYPE structure", HFILL }},
{ &hf_krb_PAC_SERVER_CHECKSUM, {
"PAC_SERVER_CHECKSUM", "kerberos.PAC_SERVER_CHECKSUM", FT_BYTES, BASE_NONE,
NULL, 0, "PAC_SERVER_CHECKSUM structure", HFILL }},
{ &hf_krb_PAC_PRIVSVR_CHECKSUM, {
"PAC_PRIVSVR_CHECKSUM", "kerberos.PAC_PRIVSVR_CHECKSUM", FT_BYTES, BASE_NONE,
NULL, 0, "PAC_PRIVSVR_CHECKSUM structure", HFILL }},
{ &hf_krb_PAC_CLIENT_INFO_TYPE, {
"PAC_CLIENT_INFO_TYPE", "kerberos.PAC_CLIENT_INFO_TYPE", FT_BYTES, BASE_NONE,
NULL, 0, "PAC_CLIENT_INFO_TYPE structure", HFILL }},
{ &hf_krb_PAC_S4U_DELEGATION_INFO, {
"PAC_S4U_DELEGATION_INFO", "kerberos.PAC_S4U_DELEGATION_INFO", FT_BYTES, BASE_NONE,
NULL, 0, "PAC_S4U_DELEGATION_INFO structure", HFILL }},
{ &hf_krb_PAC_UPN_DNS_INFO, {
"UPN_DNS_INFO", "kerberos.PAC_UPN_DNS_INFO", FT_BYTES, BASE_NONE,
NULL, 0, "UPN_DNS_INFO structure", HFILL }},
{ &hf_krb_checksum_checksum, {
"checksum", "kerberos.checksum.checksum", FT_BYTES, BASE_NONE,
NULL, 0, "Kerberos Checksum", HFILL }},
{ &hf_krb_ENC_PRIV, {
"enc PRIV", "kerberos.ENC_PRIV", FT_BYTES, BASE_NONE,
NULL, 0, "Encrypted PRIV blob", HFILL }},
{ &hf_krb_encrypted_Ticket_data, {
"enc-part", "kerberos.ticket.data", FT_BYTES, BASE_NONE,
NULL, 0, "The encrypted part of a ticket", HFILL }},
{ &hf_krb_encrypted_AP_REP_data, {
"enc-part", "kerberos.aprep.data", FT_BYTES, BASE_NONE,
NULL, 0, "The encrypted part of AP-REP", HFILL }},
{ &hf_krb_encrypted_KDC_REP_data, {
"enc-part", "kerberos.kdcrep.data", FT_BYTES, BASE_NONE,
NULL, 0, "The encrypted part of KDC-REP", HFILL }},
{ &hf_krb_PA_DATA_value, {
"Value", "kerberos.padata.value", FT_BYTES, BASE_NONE,
NULL, 0, "Content of the PADATA blob", HFILL }},
{ &hf_krb_etype_info_salt, {
"Salt", "kerberos.etype_info.salt", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_krb_etype_info2_salt, {
"Salt", "kerberos.etype_info2.salt", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_krb_etype_info2_s2kparams, {
"Salt", "kerberos.etype_info.s2kparams", FT_BYTES, BASE_NONE,
NULL, 0, "S2kparams", HFILL }},
{ &hf_krb_SAFE_BODY_user_data, {
"User Data", "kerberos.SAFE_BODY.user_data", FT_BYTES, BASE_NONE,
NULL, 0, "SAFE BODY userdata field", HFILL }},
{ &hf_krb_PRIV_BODY_user_data, {
"User Data", "kerberos.PRIV_BODY.user_data", FT_BYTES, BASE_NONE,
NULL, 0, "PRIV BODY userdata field", HFILL }},
{ &hf_krb_pac_signature_signature, {
"Signature", "kerberos.pac.signature.signature", FT_BYTES, BASE_NONE,
NULL, 0, "A PAC signature blob", HFILL }},
{ &hf_krb_PA_DATA_type, {
"Type", "kerberos.padata.type", FT_INT32, BASE_DEC,
VALS(krb5_preauthentication_types), 0, "Type of preauthentication data", HFILL }},
{ &hf_krb_nonce, {
"Nonce", "kerberos.nonce", FT_UINT32, BASE_DEC,
NULL, 0, "Kerberos Nonce random number", HFILL }},
{ &hf_krb_tkt_vno, {
"Tkt-vno", "kerberos.tkt_vno", FT_UINT32, BASE_DEC,
NULL, 0, "Version number for the Ticket format", HFILL }},
{ &hf_krb_KrbCredInfo, {
"KrbCredInfo", "kerberos.KrbCredInfo", FT_NONE, BASE_NONE,
NULL, 0, "This is a Kerberos KrbCredInfo", HFILL }},
{ &hf_krb_HostAddress, {
"HostAddress", "kerberos.hostaddress", FT_NONE, BASE_NONE,
NULL, 0, "This is a Kerberos HostAddress sequence", HFILL }},
{ &hf_krb_s_address, {
"S-Address", "kerberos.s_address", FT_NONE, BASE_NONE,
NULL, 0, "This is the Senders address", HFILL }},
{ &hf_krb_r_address, {
"R-Address", "kerberos.r_address", FT_NONE, BASE_NONE,
NULL, 0, "This is the Recipient address", HFILL }},
{ &hf_krb_key, {
"key", "kerberos.key", FT_NONE, BASE_NONE,
NULL, 0, "This is a Kerberos EncryptionKey sequence", HFILL }},
{ &hf_krb_subkey, {
"Subkey", "kerberos.subkey", FT_NONE, BASE_NONE,
NULL, 0, "This is a Kerberos subkey", HFILL }},
{ &hf_krb_seq_number, {
"Seq Number", "kerberos.seq_number", FT_UINT32, BASE_DEC,
NULL, 0, "This is a Kerberos sequence number", HFILL }},
{ &hf_krb_AuthorizationData, {
"AuthorizationData", "kerberos.AuthorizationData", FT_NONE, BASE_NONE,
NULL, 0, "This is a Kerberos AuthorizationData sequence", HFILL }},
{ &hf_krb_EncTicketPart, {
"EncTicketPart", "kerberos.EncTicketPart", FT_NONE, BASE_NONE,
NULL, 0, "This is a decrypted Kerberos EncTicketPart sequence", HFILL }},
{ &hf_krb_EncAPRepPart, {
"EncAPRepPart", "kerberos.EncAPRepPart", FT_NONE, BASE_NONE,
NULL, 0, "This is a decrypted Kerberos EncAPRepPart sequence", HFILL }},
{ &hf_krb_EncKrbPrivPart, {
"EncKrbPrivPart", "kerberos.EncKrbPrivPart", FT_NONE, BASE_NONE,
NULL, 0, "This is a decrypted Kerberos EncKrbPrivPart sequence", HFILL }},
{ &hf_krb_EncKrbCredPart, {
"EncKrbCredPart", "kerberos.EncKrbCredPart", FT_NONE, BASE_NONE,
NULL, 0, "This is a decrypted Kerberos EncKrbCredPart sequence", HFILL }},
{ &hf_krb_EncKDCRepPart, {
"EncKDCRepPart", "kerberos.EncKDCRepPart", FT_NONE, BASE_NONE,
NULL, 0, "This is a decrypted Kerberos EncKDCRepPart sequence", HFILL }},
{ &hf_krb_LastReq, {
"LastReq", "kerberos.LastReq", FT_NONE, BASE_NONE,
NULL, 0, "This is a LastReq sequence", HFILL }},
{ &hf_krb_Authenticator, {
"Authenticator", "kerberos.Authenticator", FT_NONE, BASE_NONE,
NULL, 0, "This is a decrypted Kerberos Authenticator sequence", HFILL }},
{ &hf_krb_Checksum, {
"Checksum", "kerberos.Checksum", FT_NONE, BASE_NONE,
NULL, 0, "This is a Kerberos Checksum sequence", HFILL }},
{ &hf_krb_HostAddresses, {
"HostAddresses", "kerberos.hostaddresses", FT_NONE, BASE_NONE,
NULL, 0, "This is a list of Kerberos HostAddress sequences", HFILL }},
{ &hf_krb_IF_RELEVANT, {
"IF_RELEVANT", "kerberos.if_relevant", FT_NONE, BASE_NONE,
NULL, 0, "This is a list of IF-RELEVANT sequences", HFILL }},
{ &hf_krb_etypes, {
"Encryption Types", "kerberos.etypes", FT_NONE, BASE_NONE,
NULL, 0, "This is a list of Kerberos encryption types", HFILL }},
{ &hf_krb_KrbCredInfos, {
"Sequence of KrbCredInfo", "kerberos.KrbCredInfos", FT_NONE, BASE_NONE,
NULL, 0, "This is a list of KrbCredInfo", HFILL }},
{ &hf_krb_sq_tickets, {
"Tickets", "kerberos.sq.tickets", FT_NONE, BASE_NONE,
NULL, 0, "This is a list of Kerberos Tickets", HFILL }},
{ &hf_krb_LastReqs, {
"LastReqs", "kerberos.LastReqs", FT_NONE, BASE_NONE,
NULL, 0, "This is a list of LastReq structures", HFILL }},
{ &hf_krb_sname, {
"Server Name", "kerberos.sname", FT_NONE, BASE_NONE,
NULL, 0, "This is the name part server's identity", HFILL }},
{ &hf_krb_pname, {
"Delegated Principal Name", "kerberos.pname", FT_NONE, BASE_NONE,
NULL, 0, "Identity of the delegated principal", HFILL }},
{ &hf_krb_cname, {
"Client Name", "kerberos.cname", FT_NONE, BASE_NONE,
NULL, 0, "The name part of the client principal identifier", HFILL }},
{ &hf_krb_authenticator_enc, {
"Authenticator", "kerberos.authenticator", FT_NONE, BASE_NONE,
NULL, 0, "Encrypted authenticator blob", HFILL }},
{ &hf_krb_CRED_enc, {
"EncKrbCredPart", "kerberos.encrypted_cred", FT_NONE, BASE_NONE,
NULL, 0, "Encrypted Cred blob", HFILL }},
{ &hf_krb_ticket_enc, {
"enc-part", "kerberos.ticket.enc_part", FT_NONE, BASE_NONE,
NULL, 0, "The structure holding the encrypted part of a ticket", HFILL }},
{ &hf_krb_AP_REP_enc, {
"enc-part", "kerberos.aprep.enc_part", FT_NONE, BASE_NONE,
NULL, 0, "The structure holding the encrypted part of AP-REP", HFILL }},
{ &hf_krb_KDC_REP_enc, {
"enc-part", "kerberos.kdcrep.enc_part", FT_NONE, BASE_NONE,
NULL, 0, "The structure holding the encrypted part of KDC-REP", HFILL }},
{ &hf_krb_e_data, {
"e-data", "kerberos.e_data", FT_NONE, BASE_NONE,
NULL, 0, "The e-data blob", HFILL }},
{ &hf_krb_padata, {
"padata", "kerberos.padata", FT_NONE, BASE_NONE,
NULL, 0, "Sequence of preauthentication data", HFILL }},
{ &hf_krb_ticket, {
"Ticket", "kerberos.ticket", FT_NONE, BASE_NONE,
NULL, 0, "This is a Kerberos Ticket", HFILL }},
{ &hf_krb_TransitedEncoding, {
"TransitedEncoding", "kerberos.TransitedEncoding", FT_NONE, BASE_NONE,
NULL, 0, "This is a Kerberos TransitedEncoding sequence", HFILL }},
{ &hf_krb_PA_PAC_REQUEST_flag, {
"PAC Request", "kerberos.pac_request.flag", FT_BOOLEAN, BASE_NONE,
NULL, 0, "This is a MS PAC Request Flag", HFILL }},
{ &hf_krb_w2k_pac_entries, {
"Num Entries", "kerberos.pac.entries", FT_UINT32, BASE_DEC,
NULL, 0, "Number of W2k PAC entries", HFILL }},
{ &hf_krb_w2k_pac_version, {
"Version", "kerberos.pac.version", FT_UINT32, BASE_DEC,
NULL, 0, "Version of PAC structures", HFILL }},
{ &hf_krb_w2k_pac_type, {
"Type", "kerberos.pac.type", FT_UINT32, BASE_DEC,
VALS(w2k_pac_types), 0, "Type of W2k PAC entry", HFILL }},
{ &hf_krb_w2k_pac_size, {
"Size", "kerberos.pac.size", FT_UINT32, BASE_DEC,
NULL, 0, "Size of W2k PAC entry", HFILL }},
{ &hf_krb_w2k_pac_offset, {
"Offset", "kerberos.pac.offset", FT_UINT32, BASE_DEC,
NULL, 0, "Offset to W2k PAC entry", HFILL }},
{ &hf_krb_pac_clientid, {
"ClientID", "kerberos.pac.clientid", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL,
NULL, 0, "ClientID Timestamp", HFILL }},
{ &hf_krb_pac_namelen, {
"Name Length", "kerberos.pac.namelen", FT_UINT16, BASE_DEC,
NULL, 0, "Length of client name", HFILL }},
{ &hf_krb_pac_upn_flags, {
"Flags", "kerberos.pac.upn.flags", FT_UINT32, BASE_HEX,
NULL, 0, "UPN flags", HFILL }},
{ &hf_krb_pac_upn_dns_offset, {
"DNS Offset", "kerberos.pac.upn.dns_offset", FT_UINT16, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_krb_pac_upn_dns_len, {
"DNS Len", "kerberos.pac.upn.dns_len", FT_UINT16, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_krb_pac_upn_upn_offset, {
"UPN Offset", "kerberos.pac.upn.upn_offset", FT_UINT16, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_krb_pac_upn_upn_len, {
"UPN Len", "kerberos.pac.upn.upn_len", FT_UINT16, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_krb_pac_upn_upn_name, {
"UPN Name", "kerberos.pac.upn.upn_name", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_krb_pac_upn_dns_name, {
"DNS Name", "kerberos.pac.upn.dns_name", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_krb_e_checksum, {
"e-checksum", "kerberos.e_checksum", FT_NONE, BASE_NONE,
NULL, 0, "This is a Kerberos e-checksum", HFILL }},
{ &hf_krb_gssapi_len, {
"Length", "kerberos.gssapi.len", FT_UINT32, BASE_DEC,
NULL, 0, "Length of GSSAPI Bnd field", HFILL }},
{ &hf_krb_gssapi_bnd, {
"Bnd", "kerberos.gssapi.bdn", FT_BYTES, BASE_NONE,
NULL, 0, "GSSAPI Bnd field", HFILL }},
{ &hf_krb_gssapi_c_flag_deleg, {
"Deleg", "kerberos.gssapi.checksum.flags.deleg", FT_BOOLEAN, 32,
TFS(&tfs_gss_flags_deleg), KRB5_GSS_C_DELEG_FLAG, NULL, HFILL }},
{ &hf_krb_gssapi_c_flag_mutual, {
"Mutual", "kerberos.gssapi.checksum.flags.mutual", FT_BOOLEAN, 32,
TFS(&tfs_gss_flags_mutual), KRB5_GSS_C_MUTUAL_FLAG, NULL, HFILL }},
{ &hf_krb_gssapi_c_flag_replay, {
"Replay", "kerberos.gssapi.checksum.flags.replay", FT_BOOLEAN, 32,
TFS(&tfs_gss_flags_replay), KRB5_GSS_C_REPLAY_FLAG, NULL, HFILL }},
{ &hf_krb_gssapi_c_flag_sequence, {
"Sequence", "kerberos.gssapi.checksum.flags.sequence", FT_BOOLEAN, 32,
TFS(&tfs_gss_flags_sequence), KRB5_GSS_C_SEQUENCE_FLAG, NULL, HFILL }},
{ &hf_krb_gssapi_c_flag_conf, {
"Conf", "kerberos.gssapi.checksum.flags.conf", FT_BOOLEAN, 32,
TFS(&tfs_gss_flags_conf), KRB5_GSS_C_CONF_FLAG, NULL, HFILL }},
{ &hf_krb_gssapi_c_flag_integ, {
"Integ", "kerberos.gssapi.checksum.flags.integ", FT_BOOLEAN, 32,
TFS(&tfs_gss_flags_integ), KRB5_GSS_C_INTEG_FLAG, NULL, HFILL }},
{ &hf_krb_gssapi_c_flag_dce_style, {
"DCE-style", "kerberos.gssapi.checksum.flags.dce-style", FT_BOOLEAN, 32,
TFS(&tfs_gss_flags_dce_style), KRB5_GSS_C_DCE_STYLE, NULL, HFILL }},
{ &hf_krb_gssapi_dlgopt, {
"DlgOpt", "kerberos.gssapi.dlgopt", FT_UINT16, BASE_DEC,
NULL, 0, "GSSAPI DlgOpt", HFILL }},
{ &hf_krb_gssapi_dlglen, {
"DlgLen", "kerberos.gssapi.dlglen", FT_UINT16, BASE_DEC,
NULL, 0, "GSSAPI DlgLen", HFILL }},
{ &hf_krb_smb_nt_status, {
"NT Status", "kerberos.smb.nt_status", FT_UINT32, BASE_HEX,
VALS(NT_errors), 0, "NT Status code", HFILL }},
{ &hf_krb_smb_unknown, {
"Unknown", "kerberos.smb.unknown", FT_UINT32, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_krb_midl_blob_len, {
"Blob Length", "kerberos.midl_blob_len", FT_UINT64, BASE_DEC,
NULL, 0, "Length of NDR encoded data that follows", HFILL }},
{ &hf_krb_midl_fill_bytes, {
"Fill bytes", "kerberos.midl.fill_bytes", FT_UINT32, BASE_HEX,
NULL, 0, "Just some fill bytes", HFILL }},
{ &hf_krb_midl_version, {
"Version", "kerberos.midl.version", FT_UINT8, BASE_DEC,
NULL, 0, "Version of pickling", HFILL }},
{ &hf_krb_midl_hdr_len, {
"HDR Length", "kerberos.midl.hdr_len", FT_UINT16, BASE_DEC,
NULL, 0, "Length of header", HFILL }},
};
static gint *ett[] = {
&ett_krb_kerberos,
&ett_krb_KDC_REP_enc,
&ett_krb_sname,
&ett_krb_pname,
&ett_krb_cname,
&ett_krb_AP_REP_enc,
&ett_krb_padata,
&ett_krb_etypes,
&ett_krb_KrbCredInfos,
&ett_krb_sq_tickets,
&ett_krb_LastReqs,
&ett_krb_IF_RELEVANT,
&ett_krb_PA_DATA_tree,
&ett_krb_s_address,
&ett_krb_r_address,
&ett_krb_KrbCredInfo,
&ett_krb_HostAddress,
&ett_krb_HostAddresses,
&ett_krb_authenticator_enc,
&ett_krb_CRED_enc,
&ett_krb_AP_Options,
&ett_krb_KDC_Options,
&ett_krb_Ticket_Flags,
&ett_krb_request,
&ett_krb_recordmark,
&ett_krb_ticket,
&ett_krb_ticket_enc,
&ett_krb_CRED,
&ett_krb_PRIV,
&ett_krb_PRIV_enc,
&ett_krb_EncTicketPart,
&ett_krb_EncAPRepPart,
&ett_krb_EncKrbPrivPart,
&ett_krb_EncKrbCredPart,
&ett_krb_EncKDCRepPart,
&ett_krb_LastReq,
&ett_krb_Authenticator,
&ett_krb_Checksum,
&ett_krb_key,
&ett_krb_subkey,
&ett_krb_AuthorizationData,
&ett_krb_TransitedEncoding,
&ett_krb_PAC,
&ett_krb_PAC_LOGON_INFO,
&ett_krb_PAC_SERVER_CHECKSUM,
&ett_krb_PAC_PRIVSVR_CHECKSUM,
&ett_krb_PAC_CLIENT_INFO_TYPE,
&ett_krb_PAC_S4U_DELEGATION_INFO,
&ett_krb_e_checksum,
&ett_krb_PAC_MIDL_BLOB,
&ett_krb_PAC_DREP,
&ett_krb_PAC_UPN_DNS_INFO
};
static ei_register_info ei[] = {
{ &ei_krb_decrypted_keytype, { "kerberos.decrypted_keytype", PI_SECURITY, PI_CHAT, "Decrypted keytype", EXPFILL }},
};
module_t *krb_module;
expert_module_t *expert_krb;
proto_kerberos = proto_register_protocol("Kerberos", "KRB5", "kerberos");
proto_register_field_array(proto_kerberos, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_krb = expert_register_protocol(proto_kerberos);
expert_register_field_array(expert_krb, ei, array_length(ei));
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
"keytab file is installed as well.",
&krb_decrypt);
prefs_register_filename_preference(krb_module, "file",
"Kerberos keytab file",
"The keytab file containing all the secrets",
&keytab_filename);
#endif
}
static int wrap_dissect_gss_kerb(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, guint8 *drep _U_)
{
tvbuff_t *auth_tvb;
auth_tvb = tvb_new_subset_remaining(tvb, offset);
dissect_kerberos_main(auth_tvb, pinfo, tree, FALSE, NULL);
return tvb_length_remaining(tvb, offset);
}
void
proto_reg_handoff_kerberos(void)
{
dissector_handle_t kerberos_handle_tcp;
krb4_handle = find_dissector("krb4");
kerberos_handle_udp = new_create_dissector_handle(dissect_kerberos_udp,
proto_kerberos);
kerberos_handle_tcp = create_dissector_handle(dissect_kerberos_tcp,
proto_kerberos);
dissector_add_uint("udp.port", UDP_PORT_KERBEROS, kerberos_handle_udp);
dissector_add_uint("tcp.port", TCP_PORT_KERBEROS, kerberos_handle_tcp);
register_dcerpc_auth_subdissector(DCE_C_AUTHN_LEVEL_CONNECT,
DCE_C_RPC_AUTHN_PROTOCOL_GSS_KERBEROS,
&gss_kerb_auth_connect_fns);
register_dcerpc_auth_subdissector(DCE_C_AUTHN_LEVEL_PKT_INTEGRITY,
DCE_C_RPC_AUTHN_PROTOCOL_GSS_KERBEROS,
&gss_kerb_auth_sign_fns);
register_dcerpc_auth_subdissector(DCE_C_AUTHN_LEVEL_PKT_PRIVACY,
DCE_C_RPC_AUTHN_PROTOCOL_GSS_KERBEROS,
&gss_kerb_auth_seal_fns);
}
