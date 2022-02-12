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
static void dissect_AuthenticatedSafe_OCTETSTRING_PDU(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
if((offset = strip_octet_string(tvb)) > 0)
dissect_pkcs12_AuthenticatedSafe(FALSE, tvb, offset, &asn1_ctx, tree, hf_pkcs12_AuthenticatedSafe_PDU);
else
proto_tree_add_expert(tree, pinfo, &ei_pkcs12_octet_string_expected, tvb, 0, 1);
}
static void dissect_SafeContents_OCTETSTRING_PDU(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = strip_octet_string(tvb);
dissect_pkcs12_SafeContents(FALSE, tvb, offset, &asn1_ctx, tree, hf_pkcs12_SafeContents_PDU);
}
static void dissect_X509Certificate_OCTETSTRING_PDU(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
if((offset = strip_octet_string(tvb)) > 0)
dissect_x509af_Certificate(FALSE, tvb, offset, &asn1_ctx, tree, hf_pkcs12_X509Certificate_PDU);
else
proto_tree_add_expert(tree, pinfo, &ei_pkcs12_octet_string_expected, tvb, 0, 1);
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
#include "packet-pkcs12-hfarr.c"
};
static gint *ett[] = {
&ett_decrypted_pbe,
#include "packet-pkcs12-ettarr.c"
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
new_register_ber_syntax_dissector("PKCS#12", proto_pkcs12, dissect_PFX_PDU);
register_ber_oid_syntax(".p12", NULL, "PKCS#12");
register_ber_oid_syntax(".pfx", NULL, "PKCS#12");
}
void proto_reg_handoff_pkcs12(void) {
#include "packet-pkcs12-dis-tab.c"
register_ber_oid_dissector("1.2.840.113549.1.9.22.1", dissect_X509Certificate_OCTETSTRING_PDU, proto_pkcs12, "x509Certificate");
}
