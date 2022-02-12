static void append_oid(proto_tree *tree, const char *oid)
{
const char *name = NULL;
name = oid_resolved_from_string(wmem_packet_scope(), oid);
proto_item_append_text(tree, " (%s)", name ? name : oid);
}
static int
generate_key_or_iv(unsigned int id, tvbuff_t *salt_tvb, unsigned int iter,
const char *pw, unsigned int req_keylen, char * keybuf)
{
int rc;
unsigned int i, j;
gcry_md_hd_t md;
gcry_mpi_t num_b1 = NULL;
size_t pwlen;
char hash[20], buf_b[64], buf_i[128], *p;
char *salt_p;
int salt_size;
size_t cur_keylen;
size_t n;
gcry_error_t err;
cur_keylen = 0;
salt_size = tvb_captured_length(salt_tvb);
salt_p = (char *)tvb_memdup(wmem_packet_scope(), salt_tvb, 0, salt_size);
if (pw == NULL)
pwlen = 0;
else
pwlen = strlen(pw);
if (pwlen > 63 / 2)
{
return FALSE;
}
p = buf_i;
for (i = 0; i < 64; i++)
*p++ = salt_p[i % salt_size];
if (pw)
{
for (i = j = 0; i < 64; i += 2)
{
*p++ = 0;
*p++ = pw[j];
if (++j > pwlen)
j = 0;
}
}
else
memset (p, 0, 64);
for (;;) {
err = gcry_md_open(&md, GCRY_MD_SHA1, 0);
if (gcry_err_code(err))
{
return FALSE;
}
for (i = 0; i < 64; i++)
{
unsigned char lid = id & 0xFF;
gcry_md_write (md, &lid, 1);
}
gcry_md_write(md, buf_i, pw ? 128 : 64);
gcry_md_final (md);
memcpy (hash, gcry_md_read (md, 0), 20);
gcry_md_close (md);
for (i = 1; i < iter; i++)
gcry_md_hash_buffer (GCRY_MD_SHA1, hash, hash, 20);
for (i = 0; i < 20 && cur_keylen < req_keylen; i++)
keybuf[cur_keylen++] = hash[i];
if (cur_keylen == req_keylen)
{
gcry_mpi_release (num_b1);
return TRUE;
}
for (i = 0; i < 64; i++)
buf_b[i] = hash[i % 20];
n = 64;
rc = gcry_mpi_scan (&num_b1, GCRYMPI_FMT_USG, buf_b, n, &n);
if (rc != 0)
{
return FALSE;
}
gcry_mpi_add_ui (num_b1, num_b1, 1);
for (i = 0; i < 128; i += 64)
{
gcry_mpi_t num_ij;
n = 64;
rc = gcry_mpi_scan (&num_ij, GCRYMPI_FMT_USG, buf_i + i, n, &n);
if (rc != 0)
{
return FALSE;
}
gcry_mpi_add (num_ij, num_ij, num_b1);
gcry_mpi_clear_highbit (num_ij, 64 * 8);
n = 64;
rc = gcry_mpi_print (GCRYMPI_FMT_USG, buf_i + i, n, &n, num_ij);
if (rc != 0)
{
return FALSE;
}
gcry_mpi_release (num_ij);
}
}
}
void PBE_reset_parameters(void)
{
iteration_count = 0;
salt = NULL;
}
int PBE_decrypt_data(const char *object_identifier_id_param _U_, tvbuff_t *encrypted_tvb _U_, asn1_ctx_t *actx _U_, proto_item *item _U_)
{
#ifdef HAVE_LIBGCRYPT
const char *encryption_algorithm;
gcry_cipher_hd_t cipher;
gcry_error_t err;
int algo;
int mode;
int ivlen = 0;
int keylen = 0;
int datalen = 0;
char *key = NULL;
char *iv = NULL;
char *clear_data = NULL;
tvbuff_t *clear_tvb = NULL;
const gchar *oidname;
GString *name;
proto_tree *tree;
char byte;
gboolean decrypt_ok = TRUE;
if(((password == NULL) || (*password == '\0')) && (try_null_password == FALSE)) {
return FALSE;
}
encryption_algorithm = x509af_get_last_algorithm_id();
if(!strcmp(encryption_algorithm, PKCS12_PBE_3DES_SHA1_OID)) {
ivlen = 8;
keylen = 24;
algo = GCRY_CIPHER_3DES;
mode = GCRY_CIPHER_MODE_CBC;
} else if(!strcmp(encryption_algorithm, PKCS12_PBE_ARCFOUR_SHA1_OID)) {
ivlen = 0;
keylen = 16;
algo = GCRY_CIPHER_ARCFOUR;
mode = GCRY_CIPHER_MODE_NONE;
} else if(!strcmp(encryption_algorithm, PKCS12_PBE_RC2_40_SHA1_OID)) {
ivlen = 8;
keylen = 5;
algo = GCRY_CIPHER_RFC2268_40;
mode = GCRY_CIPHER_MODE_CBC;
} else {
proto_item_append_text(item, " [Unsupported encryption algorithm]");
return FALSE;
}
if((iteration_count == 0) || (salt == NULL)) {
proto_item_append_text(item, " [Insufficient parameters]");
return FALSE;
}
key = (char *)wmem_alloc(wmem_packet_scope(), keylen);
if(!generate_key_or_iv(1 , salt, iteration_count, password, keylen, key))
return FALSE;
if(ivlen) {
iv = (char *)wmem_alloc(wmem_packet_scope(), ivlen);
if(!generate_key_or_iv(2 , salt, iteration_count, password, ivlen, iv))
return FALSE;
}
err = gcry_cipher_open(&cipher, algo, mode, 0);
if (gcry_err_code (err))
return FALSE;
err = gcry_cipher_setkey (cipher, key, keylen);
if (gcry_err_code (err)) {
gcry_cipher_close (cipher);
return FALSE;
}
if(ivlen) {
err = gcry_cipher_setiv (cipher, iv, ivlen);
if (gcry_err_code (err)) {
gcry_cipher_close (cipher);
return FALSE;
}
}
datalen = tvb_captured_length(encrypted_tvb);
clear_data = (char *)g_malloc(datalen);
err = gcry_cipher_decrypt (cipher, clear_data, datalen, (char *)tvb_memdup(wmem_packet_scope(), encrypted_tvb, 0, datalen), datalen);
if (gcry_err_code (err)) {
proto_item_append_text(item, " [Failed to decrypt with password preference]");
gcry_cipher_close (cipher);
g_free(clear_data);
return FALSE;
}
gcry_cipher_close (cipher);
byte = clear_data[datalen-1];
if(byte <= 0x08) {
int i;
for(i = (int)byte; i > 0 ; i--) {
if(clear_data[datalen - i] != byte) {
decrypt_ok = FALSE;
break;
}
}
} else {
}
byte = clear_data[0];
if((byte != 0x30) && (byte != 0x31)) {
decrypt_ok = FALSE;
}
if(!decrypt_ok) {
g_free(clear_data);
proto_item_append_text(item, " [Failed to decrypt with supplied password]");
return FALSE;
}
proto_item_append_text(item, " [Decrypted successfully]");
tree = proto_item_add_subtree(item, ett_decrypted_pbe);
clear_tvb = tvb_new_child_real_data(encrypted_tvb,(const guint8 *)clear_data, datalen, datalen);
tvb_set_free_cb(clear_tvb, g_free);
name = g_string_new("");
oidname = oid_resolved_from_string(wmem_packet_scope(), object_identifier_id_param);
g_string_printf(name, "Decrypted %s", oidname ? oidname : object_identifier_id_param);
add_new_data_source(actx->pinfo, clear_tvb, name->str);
g_string_free(name, TRUE);
call_ber_oid_callback(object_identifier_id_param, clear_tvb, 0, actx->pinfo, tree, NULL);
return TRUE;
#else
return FALSE;
#endif
}
static int
dissect_pkcs12_T_version(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_pkcs12_DigestInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
DigestInfo_sequence, hf_index, ett_pkcs12_DigestInfo);
return offset;
}
static int
dissect_pkcs12_OCTET_STRING(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
(hf_index == hf_pkcs12_salt ? &salt : NULL));
return offset;
}
static int
dissect_pkcs12_INTEGER(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
(hf_index == hf_pkcs12_iterationCount ? &iteration_count : NULL));
return offset;
}
static int
dissect_pkcs12_MacData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
MacData_sequence, hf_index, ett_pkcs12_MacData);
return offset;
}
static int
dissect_pkcs12_PFX(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 58 "./asn1/pkcs12/pkcs12.cnf"
dissector_handle_t dissector_handle;
dissector_handle=create_dissector_handle(dissect_AuthenticatedSafe_OCTETSTRING_PDU, proto_pkcs12);
dissector_change_string("ber.oid", "1.2.840.113549.1.7.1", dissector_handle);
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
PFX_sequence, hf_index, ett_pkcs12_PFX);
dissector_reset_string("ber.oid", "1.2.840.113549.1.7.1");
return offset;
}
static int
dissect_pkcs12_AuthenticatedSafe(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 71 "./asn1/pkcs12/pkcs12.cnf"
dissector_handle_t dissector_handle;
dissector_handle=create_dissector_handle(dissect_SafeContents_OCTETSTRING_PDU, proto_pkcs12);
dissector_change_string("ber.oid", "1.2.840.113549.1.7.1", dissector_handle);
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
AuthenticatedSafe_sequence_of, hf_index, ett_pkcs12_AuthenticatedSafe);
dissector_reset_string("ber.oid", "1.2.840.113549.1.7.1");
return offset;
}
static int
dissect_pkcs12_T_bagId(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_object_identifier_str(implicit_tag, actx, tree, tvb, offset, hf_index, &object_identifier_id);
#line 84 "./asn1/pkcs12/pkcs12.cnf"
append_oid(tree, object_identifier_id);
return offset;
}
static int
dissect_pkcs12_T_bagValue(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 108 "./asn1/pkcs12/pkcs12.cnf"
if(object_identifier_id)
offset = call_ber_oid_callback(object_identifier_id, tvb, offset, actx->pinfo, tree, NULL);
return offset;
}
static int
dissect_pkcs12_T_attrId(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_object_identifier_str(implicit_tag, actx, tree, tvb, offset, hf_index, &object_identifier_id);
#line 104 "./asn1/pkcs12/pkcs12.cnf"
append_oid(tree, object_identifier_id);
return offset;
}
static int
dissect_pkcs12_T_attrValues_item(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 112 "./asn1/pkcs12/pkcs12.cnf"
if(object_identifier_id)
offset = call_ber_oid_callback(object_identifier_id, tvb, offset, actx->pinfo, tree, NULL);
return offset;
}
static int
dissect_pkcs12_T_attrValues(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
T_attrValues_set_of, hf_index, ett_pkcs12_T_attrValues);
return offset;
}
static int
dissect_pkcs12_PKCS12Attribute(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
PKCS12Attribute_sequence, hf_index, ett_pkcs12_PKCS12Attribute);
return offset;
}
static int
dissect_pkcs12_SET_OF_PKCS12Attribute(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
SET_OF_PKCS12Attribute_set_of, hf_index, ett_pkcs12_SET_OF_PKCS12Attribute);
return offset;
}
static int
dissect_pkcs12_SafeBag(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
SafeBag_sequence, hf_index, ett_pkcs12_SafeBag);
return offset;
}
static int
dissect_pkcs12_SafeContents(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SafeContents_sequence_of, hf_index, ett_pkcs12_SafeContents);
return offset;
}
static int
dissect_pkcs12_Version(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_pkcs12_PrivateKey(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_pkcs12_Attributes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
Attributes_set_of, hf_index, ett_pkcs12_Attributes);
return offset;
}
static int
dissect_pkcs12_PrivateKeyInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
PrivateKeyInfo_sequence, hf_index, ett_pkcs12_PrivateKeyInfo);
return offset;
}
static int
dissect_pkcs12_KeyBag(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_pkcs12_PrivateKeyInfo(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_pkcs12_EncryptedData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 139 "./asn1/pkcs12/pkcs12.cnf"
tvbuff_t *encrypted_tvb;
dissector_handle_t dissector_handle;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&encrypted_tvb);
#line 145 "./asn1/pkcs12/pkcs12.cnf"
dissector_handle=create_dissector_handle(dissect_PrivateKeyInfo_PDU, proto_pkcs12);
dissector_change_string("ber.oid", object_identifier_id, dissector_handle);
PBE_decrypt_data(object_identifier_id, encrypted_tvb, actx, actx->created_item);
dissector_reset_string("ber.oid", object_identifier_id);
return offset;
}
static int
dissect_pkcs12_EncryptedPrivateKeyInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
EncryptedPrivateKeyInfo_sequence, hf_index, ett_pkcs12_EncryptedPrivateKeyInfo);
return offset;
}
static int
dissect_pkcs12_PKCS8ShroudedKeyBag(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_pkcs12_EncryptedPrivateKeyInfo(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_pkcs12_T_certId(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_object_identifier_str(implicit_tag, actx, tree, tvb, offset, hf_index, &object_identifier_id);
#line 89 "./asn1/pkcs12/pkcs12.cnf"
append_oid(tree, object_identifier_id);
return offset;
}
static int
dissect_pkcs12_T_certValue(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 116 "./asn1/pkcs12/pkcs12.cnf"
if(object_identifier_id)
offset = call_ber_oid_callback(object_identifier_id, tvb, offset, actx->pinfo, tree, NULL);
return offset;
}
static int
dissect_pkcs12_CertBag(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
CertBag_sequence, hf_index, ett_pkcs12_CertBag);
return offset;
}
static int
dissect_pkcs12_T_crlId(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_object_identifier_str(implicit_tag, actx, tree, tvb, offset, hf_index, &object_identifier_id);
#line 94 "./asn1/pkcs12/pkcs12.cnf"
append_oid(tree, object_identifier_id);
return offset;
}
static int
dissect_pkcs12_T_crlValue(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 120 "./asn1/pkcs12/pkcs12.cnf"
if(object_identifier_id)
offset = call_ber_oid_callback(object_identifier_id, tvb, offset, actx->pinfo, tree, NULL);
return offset;
}
static int
dissect_pkcs12_CRLBag(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
CRLBag_sequence, hf_index, ett_pkcs12_CRLBag);
return offset;
}
static int
dissect_pkcs12_T_secretTypeId(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_object_identifier_str(implicit_tag, actx, tree, tvb, offset, hf_index, &object_identifier_id);
#line 99 "./asn1/pkcs12/pkcs12.cnf"
append_oid(tree, object_identifier_id);
return offset;
}
static int
dissect_pkcs12_T_secretValue(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 124 "./asn1/pkcs12/pkcs12.cnf"
if(object_identifier_id)
offset = call_ber_oid_callback(object_identifier_id, tvb, offset, actx->pinfo, tree, NULL);
return offset;
}
static int
dissect_pkcs12_SecretBag(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
SecretBag_sequence, hf_index, ett_pkcs12_SecretBag);
return offset;
}
static int
dissect_pkcs12_PBEParameter(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 128 "./asn1/pkcs12/pkcs12.cnf"
PBE_reset_parameters();
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
PBEParameter_sequence, hf_index, ett_pkcs12_PBEParameter);
return offset;
}
static int
dissect_pkcs12_T_saltChoice(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_saltChoice_choice, hf_index, ett_pkcs12_T_saltChoice,
NULL);
return offset;
}
static int
dissect_pkcs12_INTEGER_1_MAX(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_pkcs12_PBKDF2Params(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
PBKDF2Params_sequence, hf_index, ett_pkcs12_PBKDF2Params);
return offset;
}
static int
dissect_pkcs12_PBES2Params(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
PBES2Params_sequence, hf_index, ett_pkcs12_PBES2Params);
return offset;
}
static int
dissect_pkcs12_PBMAC1Params(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
PBMAC1Params_sequence, hf_index, ett_pkcs12_PBMAC1Params);
return offset;
}
static int dissect_PFX_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_pkcs12_PFX(FALSE, tvb, offset, &asn1_ctx, tree, hf_pkcs12_PFX_PDU);
return offset;
}
static int dissect_SafeContents_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_pkcs12_SafeContents(FALSE, tvb, offset, &asn1_ctx, tree, hf_pkcs12_SafeContents_PDU);
return offset;
}
static int dissect_KeyBag_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_pkcs12_KeyBag(FALSE, tvb, offset, &asn1_ctx, tree, hf_pkcs12_KeyBag_PDU);
return offset;
}
static int dissect_PKCS8ShroudedKeyBag_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_pkcs12_PKCS8ShroudedKeyBag(FALSE, tvb, offset, &asn1_ctx, tree, hf_pkcs12_PKCS8ShroudedKeyBag_PDU);
return offset;
}
static int dissect_CertBag_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_pkcs12_CertBag(FALSE, tvb, offset, &asn1_ctx, tree, hf_pkcs12_CertBag_PDU);
return offset;
}
static int dissect_CRLBag_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_pkcs12_CRLBag(FALSE, tvb, offset, &asn1_ctx, tree, hf_pkcs12_CRLBag_PDU);
return offset;
}
static int dissect_SecretBag_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_pkcs12_SecretBag(FALSE, tvb, offset, &asn1_ctx, tree, hf_pkcs12_SecretBag_PDU);
return offset;
}
static int dissect_PrivateKeyInfo_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_pkcs12_PrivateKeyInfo(FALSE, tvb, offset, &asn1_ctx, tree, hf_pkcs12_PrivateKeyInfo_PDU);
return offset;
}
static int dissect_EncryptedPrivateKeyInfo_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_pkcs12_EncryptedPrivateKeyInfo(FALSE, tvb, offset, &asn1_ctx, tree, hf_pkcs12_EncryptedPrivateKeyInfo_PDU);
return offset;
}
static int dissect_PBEParameter_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_pkcs12_PBEParameter(FALSE, tvb, offset, &asn1_ctx, tree, hf_pkcs12_PBEParameter_PDU);
return offset;
}
static int dissect_PBKDF2Params_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_pkcs12_PBKDF2Params(FALSE, tvb, offset, &asn1_ctx, tree, hf_pkcs12_PBKDF2Params_PDU);
return offset;
}
static int dissect_PBES2Params_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_pkcs12_PBES2Params(FALSE, tvb, offset, &asn1_ctx, tree, hf_pkcs12_PBES2Params_PDU);
return offset;
}
static int dissect_PBMAC1Params_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_pkcs12_PBMAC1Params(FALSE, tvb, offset, &asn1_ctx, tree, hf_pkcs12_PBMAC1Params_PDU);
return offset;
}
static int strip_octet_string(tvbuff_t *tvb)
{
gint8 ber_class;
gboolean pc, ind;
gint32 tag;
guint32 len;
int offset = 0;
offset = get_ber_identifier(tvb, 0, &ber_class, &pc, &tag);
offset = get_ber_length(tvb, offset, &len, &ind);
if((ber_class == BER_CLASS_UNI) && (tag == BER_UNI_TAG_OCTETSTRING))
return offset;
return 0;
}
static int dissect_AuthenticatedSafe_OCTETSTRING_PDU(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
if((offset = strip_octet_string(tvb)) > 0)
dissect_pkcs12_AuthenticatedSafe(FALSE, tvb, offset, &asn1_ctx, tree, hf_pkcs12_AuthenticatedSafe_PDU);
else
proto_tree_add_expert(tree, pinfo, &ei_pkcs12_octet_string_expected, tvb, 0, 1);
return tvb_captured_length(tvb);
}
static int dissect_SafeContents_OCTETSTRING_PDU(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = strip_octet_string(tvb);
dissect_pkcs12_SafeContents(FALSE, tvb, offset, &asn1_ctx, tree, hf_pkcs12_SafeContents_PDU);
return tvb_captured_length(tvb);
}
static int dissect_X509Certificate_OCTETSTRING_PDU(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
if((offset = strip_octet_string(tvb)) > 0)
dissect_x509af_Certificate(FALSE, tvb, offset, &asn1_ctx, tree, hf_pkcs12_X509Certificate_PDU);
else
proto_tree_add_expert(tree, pinfo, &ei_pkcs12_octet_string_expected, tvb, 0, 1);
return tvb_captured_length(tvb);
}
void proto_register_pkcs12(void) {
static hf_register_info hf[] = {
{ &hf_pkcs12_X509Certificate_PDU,
{ "X509Certificate", "pkcs12.X509Certificate",
FT_NONE, BASE_NONE, NULL, 0,
"pkcs12.X509Certificate", HFILL }},
{ &hf_pkcs12_AuthenticatedSafe_PDU,
{ "AuthenticatedSafe", "pkcs12.AuthenticatedSafe",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
#line 1 "./asn1/pkcs12/packet-pkcs12-hfarr.c"
{ &hf_pkcs12_PFX_PDU,
{ "PFX", "pkcs12.PFX_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pkcs12_SafeContents_PDU,
{ "SafeContents", "pkcs12.SafeContents",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_pkcs12_KeyBag_PDU,
{ "KeyBag", "pkcs12.KeyBag_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pkcs12_PKCS8ShroudedKeyBag_PDU,
{ "PKCS8ShroudedKeyBag", "pkcs12.PKCS8ShroudedKeyBag_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pkcs12_CertBag_PDU,
{ "CertBag", "pkcs12.CertBag_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pkcs12_CRLBag_PDU,
{ "CRLBag", "pkcs12.CRLBag_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pkcs12_SecretBag_PDU,
{ "SecretBag", "pkcs12.SecretBag_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pkcs12_PrivateKeyInfo_PDU,
{ "PrivateKeyInfo", "pkcs12.PrivateKeyInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pkcs12_EncryptedPrivateKeyInfo_PDU,
{ "EncryptedPrivateKeyInfo", "pkcs12.EncryptedPrivateKeyInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pkcs12_PBEParameter_PDU,
{ "PBEParameter", "pkcs12.PBEParameter_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pkcs12_PBKDF2Params_PDU,
{ "PBKDF2Params", "pkcs12.PBKDF2Params_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pkcs12_PBES2Params_PDU,
{ "PBES2Params", "pkcs12.PBES2Params_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pkcs12_PBMAC1Params_PDU,
{ "PBMAC1Params", "pkcs12.PBMAC1Params_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pkcs12_version,
{ "version", "pkcs12.version",
FT_UINT32, BASE_DEC, VALS(pkcs12_T_version_vals), 0,
NULL, HFILL }},
{ &hf_pkcs12_authSafe,
{ "authSafe", "pkcs12.authSafe_element",
FT_NONE, BASE_NONE, NULL, 0,
"ContentInfo", HFILL }},
{ &hf_pkcs12_macData,
{ "macData", "pkcs12.macData_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pkcs12_mac,
{ "mac", "pkcs12.mac_element",
FT_NONE, BASE_NONE, NULL, 0,
"DigestInfo", HFILL }},
{ &hf_pkcs12_macSalt,
{ "macSalt", "pkcs12.macSalt",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_pkcs12_iterations,
{ "iterations", "pkcs12.iterations",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_pkcs12_digestAlgorithm,
{ "digestAlgorithm", "pkcs12.digestAlgorithm_element",
FT_NONE, BASE_NONE, NULL, 0,
"DigestAlgorithmIdentifier", HFILL }},
{ &hf_pkcs12_digest,
{ "digest", "pkcs12.digest",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pkcs12_AuthenticatedSafe_item,
{ "ContentInfo", "pkcs12.ContentInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pkcs12_SafeContents_item,
{ "SafeBag", "pkcs12.SafeBag_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pkcs12_bagId,
{ "bagId", "pkcs12.bagId",
FT_OID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pkcs12_bagValue,
{ "bagValue", "pkcs12.bagValue_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pkcs12_bagAttributes,
{ "bagAttributes", "pkcs12.bagAttributes",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_OF_PKCS12Attribute", HFILL }},
{ &hf_pkcs12_bagAttributes_item,
{ "PKCS12Attribute", "pkcs12.PKCS12Attribute_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pkcs12_certId,
{ "certId", "pkcs12.certId",
FT_OID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pkcs12_certValue,
{ "certValue", "pkcs12.certValue_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pkcs12_crlId,
{ "crlId", "pkcs12.crlId",
FT_OID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pkcs12_crlValue,
{ "crlValue", "pkcs12.crlValue_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pkcs12_secretTypeId,
{ "secretTypeId", "pkcs12.secretTypeId",
FT_OID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pkcs12_secretValue,
{ "secretValue", "pkcs12.secretValue_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pkcs12_attrId,
{ "attrId", "pkcs12.attrId",
FT_OID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pkcs12_attrValues,
{ "attrValues", "pkcs12.attrValues",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_pkcs12_attrValues_item,
{ "attrValues item", "pkcs12.attrValues_item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pkcs12_privateKeyVersion,
{ "version", "pkcs12.version",
FT_UINT32, BASE_DEC, VALS(pkcs12_Version_vals), 0,
NULL, HFILL }},
{ &hf_pkcs12_privateKeyAlgorithm,
{ "privateKeyAlgorithm", "pkcs12.privateKeyAlgorithm_element",
FT_NONE, BASE_NONE, NULL, 0,
"AlgorithmIdentifier", HFILL }},
{ &hf_pkcs12_privateKey,
{ "privateKey", "pkcs12.privateKey",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pkcs12_attributes,
{ "attributes", "pkcs12.attributes",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_pkcs12_Attributes_item,
{ "Attribute", "pkcs12.Attribute_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pkcs12_encryptionAlgorithm,
{ "encryptionAlgorithm", "pkcs12.encryptionAlgorithm_element",
FT_NONE, BASE_NONE, NULL, 0,
"AlgorithmIdentifier", HFILL }},
{ &hf_pkcs12_encryptedData,
{ "encryptedData", "pkcs12.encryptedData",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_pkcs12_salt,
{ "salt", "pkcs12.salt",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_pkcs12_iterationCount,
{ "iterationCount", "pkcs12.iterationCount",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_pkcs12_saltChoice,
{ "salt", "pkcs12.salt",
FT_UINT32, BASE_DEC, VALS(pkcs12_T_saltChoice_vals), 0,
"T_saltChoice", HFILL }},
{ &hf_pkcs12_specified,
{ "specified", "pkcs12.specified",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_pkcs12_otherSource,
{ "otherSource", "pkcs12.otherSource_element",
FT_NONE, BASE_NONE, NULL, 0,
"AlgorithmIdentifier", HFILL }},
{ &hf_pkcs12_keyLength,
{ "keyLength", "pkcs12.keyLength",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_MAX", HFILL }},
{ &hf_pkcs12_prf,
{ "prf", "pkcs12.prf_element",
FT_NONE, BASE_NONE, NULL, 0,
"AlgorithmIdentifier", HFILL }},
{ &hf_pkcs12_keyDerivationFunc,
{ "keyDerivationFunc", "pkcs12.keyDerivationFunc_element",
FT_NONE, BASE_NONE, NULL, 0,
"AlgorithmIdentifier", HFILL }},
{ &hf_pkcs12_encryptionScheme,
{ "encryptionScheme", "pkcs12.encryptionScheme_element",
FT_NONE, BASE_NONE, NULL, 0,
"AlgorithmIdentifier", HFILL }},
{ &hf_pkcs12_messageAuthScheme,
{ "messageAuthScheme", "pkcs12.messageAuthScheme_element",
FT_NONE, BASE_NONE, NULL, 0,
"AlgorithmIdentifier", HFILL }},
#line 463 "./asn1/pkcs12/packet-pkcs12-template.c"
};
static gint *ett[] = {
&ett_decrypted_pbe,
#line 1 "./asn1/pkcs12/packet-pkcs12-ettarr.c"
&ett_pkcs12_PFX,
&ett_pkcs12_MacData,
&ett_pkcs12_DigestInfo,
&ett_pkcs12_AuthenticatedSafe,
&ett_pkcs12_SafeContents,
&ett_pkcs12_SafeBag,
&ett_pkcs12_SET_OF_PKCS12Attribute,
&ett_pkcs12_CertBag,
&ett_pkcs12_CRLBag,
&ett_pkcs12_SecretBag,
&ett_pkcs12_PKCS12Attribute,
&ett_pkcs12_T_attrValues,
&ett_pkcs12_PrivateKeyInfo,
&ett_pkcs12_Attributes,
&ett_pkcs12_EncryptedPrivateKeyInfo,
&ett_pkcs12_PBEParameter,
&ett_pkcs12_PBKDF2Params,
&ett_pkcs12_T_saltChoice,
&ett_pkcs12_PBES2Params,
&ett_pkcs12_PBMAC1Params,
#line 469 "./asn1/pkcs12/packet-pkcs12-template.c"
};
static ei_register_info ei[] = {
{ &ei_pkcs12_octet_string_expected, { "pkcs12.octet_string_expected", PI_PROTOCOL, PI_WARN, "BER Error: OCTET STRING expected", EXPFILL }},
};
module_t *pkcs12_module;
expert_module_t* expert_pkcs12;
proto_pkcs12 = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_pkcs12, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_pkcs12 = expert_register_protocol(proto_pkcs12);
expert_register_field_array(expert_pkcs12, ei, array_length(ei));
pkcs12_module = prefs_register_protocol(proto_pkcs12, NULL);
prefs_register_string_preference(pkcs12_module, "password",
"Password to decrypt the file with",
"The password to used to decrypt the encrypted elements within"
" the PKCS#12 file", &password);
prefs_register_bool_preference(pkcs12_module, "try_null_password",
"Try to decrypt with a empty password",
"Whether to try and decrypt the encrypted data within the"
" PKCS#12 with a NULL password", &try_null_password);
register_ber_syntax_dissector("PKCS#12", proto_pkcs12, dissect_PFX_PDU);
register_ber_oid_syntax(".p12", NULL, "PKCS#12");
register_ber_oid_syntax(".pfx", NULL, "PKCS#12");
}
void proto_reg_handoff_pkcs12(void) {
#line 1 "./asn1/pkcs12/packet-pkcs12-dis-tab.c"
register_ber_oid_dissector("1.2.840.113549.1.12.10.1.1", dissect_KeyBag_PDU, proto_pkcs12, "keyBag");
register_ber_oid_dissector("1.2.840.113549.1.12.10.1.2", dissect_PKCS8ShroudedKeyBag_PDU, proto_pkcs12, "pkcs8ShroudedKeyBag");
register_ber_oid_dissector("1.2.840.113549.1.12.10.1.3", dissect_CertBag_PDU, proto_pkcs12, "certBag");
register_ber_oid_dissector("1.2.840.113549.1.12.10.1.4", dissect_SecretBag_PDU, proto_pkcs12, "secretBag");
register_ber_oid_dissector("1.2.840.113549.1.12.10.1.5", dissect_CRLBag_PDU, proto_pkcs12, "crlBag");
register_ber_oid_dissector("1.2.840.113549.1.12.10.1.6", dissect_SafeContents_PDU, proto_pkcs12, "safeContentsBag");
register_ber_oid_dissector("2.16.840.1.113730.3.1.216", dissect_PFX_PDU, proto_pkcs12, "pkcs-9-at-PKCS12");
register_ber_oid_dissector("1.2.840.113549.1.9.25.2", dissect_EncryptedPrivateKeyInfo_PDU, proto_pkcs12, "pkcs-9-at-encryptedPrivateKeyInfo");
register_ber_oid_dissector("1.2.840.113549.1.12.1.1", dissect_PBEParameter_PDU, proto_pkcs12, "pbeWithSHAAnd128BitRC4");
register_ber_oid_dissector("1.2.840.113549.1.12.1.2", dissect_PBEParameter_PDU, proto_pkcs12, "pbeWithSHAAnd40BitRC4");
register_ber_oid_dissector("1.2.840.113549.1.12.1.3", dissect_PBEParameter_PDU, proto_pkcs12, "pbeWithSHAAnd3-KeyTripleDES-CBC");
register_ber_oid_dissector("1.2.840.113549.1.12.1.4", dissect_PBEParameter_PDU, proto_pkcs12, "pbeWithSHAAnd2-KeyTripleDES-CBC");
register_ber_oid_dissector("1.2.840.113549.1.12.1.5", dissect_PBEParameter_PDU, proto_pkcs12, "pbeWithSHAAnd128BitRC2-CBC");
register_ber_oid_dissector("1.2.840.113549.1.12.1.6", dissect_PBEParameter_PDU, proto_pkcs12, "pbeWithSHAAnd40BitRC2-CBC");
register_ber_oid_dissector("1.2.840.113549.1.5.1", dissect_PBEParameter_PDU, proto_pkcs12, "pbeWithMD2AndDES-CBC");
register_ber_oid_dissector("1.2.840.113549.1.5.3", dissect_PBEParameter_PDU, proto_pkcs12, "pbeWithMD5AndDES-CBC");
register_ber_oid_dissector("1.2.840.113549.1.5.4", dissect_PBEParameter_PDU, proto_pkcs12, "pbeWithMD2AndRC2-CBC");
register_ber_oid_dissector("1.2.840.113549.1.5.6", dissect_PBEParameter_PDU, proto_pkcs12, "pbeWithMD5AndRC2-CBC");
register_ber_oid_dissector("1.2.840.113549.1.5.10", dissect_PBEParameter_PDU, proto_pkcs12, "pbeWithSHA1AndDES-CBC");
register_ber_oid_dissector("1.2.840.113549.1.5.11", dissect_PBEParameter_PDU, proto_pkcs12, "pbeWithSHA1AndRC2-CBC");
register_ber_oid_dissector("1.2.840.113549.1.5.12", dissect_PBKDF2Params_PDU, proto_pkcs12, "id-PBKDF2");
register_ber_oid_dissector("1.2.840.113549.1.5.13", dissect_PBES2Params_PDU, proto_pkcs12, "id-PBES2");
register_ber_oid_dissector("1.2.840.113549.1.5.14", dissect_PBMAC1Params_PDU, proto_pkcs12, "id-PBMAC1");
#line 508 "./asn1/pkcs12/packet-pkcs12-template.c"
register_ber_oid_dissector("1.2.840.113549.1.9.22.1", dissect_X509Certificate_OCTETSTRING_PDU, proto_pkcs12, "x509Certificate");
}
