static void* uat_esp_sa_record_copy_cb(void* n, const void* o, size_t siz _U_) {
uat_esp_sa_record_t* new_rec = (uat_esp_sa_record_t *)n;
const uat_esp_sa_record_t* old_rec = (uat_esp_sa_record_t *)o;
new_rec->srcIP = (old_rec->srcIP) ? g_strdup(old_rec->srcIP) : NULL;
new_rec->dstIP = (old_rec->dstIP) ? g_strdup(old_rec->dstIP) : NULL;
new_rec->spi = (old_rec->spi) ? g_strdup(old_rec->spi) : NULL;
new_rec->encryption_key = (old_rec->encryption_key) ? g_strdup(old_rec->encryption_key) : NULL;
new_rec->authentication_key = (old_rec->authentication_key) ? g_strdup(old_rec->authentication_key) : NULL;
return new_rec;
}
static void uat_esp_sa_record_free_cb(void*r) {
uat_esp_sa_record_t* rec = (uat_esp_sa_record_t*)r;
g_free(rec->srcIP);
g_free(rec->dstIP);
g_free(rec->spi);
g_free(rec->encryption_key);
g_free(rec->authentication_key);
}
static gboolean
filter_address_match(gchar *addr, gchar *filter, gint typ)
{
guint i;
guint filter_tmp = 0;
guint addr_tmp = 0;
char filter_string_tmp[3];
char addr_string_tmp[3];
guint addr_len = (guint)strlen(addr);
guint filter_len = (guint)strlen(filter);
if(addr_len != filter_len)
return FALSE;
if( ((typ == IPSEC_SA_IPV6) && (filter_len > IPSEC_IPV6_ADDR_LEN))
|| ((typ == IPSEC_SA_IPV4) && (filter_len > IPSEC_IPV4_ADDR_LEN)))
{
for(i = 0; i < addr_len; i++)
{
if((filter[i] != IPSEC_SA_WILDCARDS_ANY) && (filter[i] != addr[i]))
return FALSE;
}
return TRUE;
}
else
{
for(i = 0; i < (filter_len/4); i++)
{
if((filter[i] != IPSEC_SA_WILDCARDS_ANY) && (filter[i] != addr[i]))
return FALSE;
}
if(filter[i] == IPSEC_SA_WILDCARDS_ANY)
return TRUE;
else if (filter_len % 4 != 0)
{
filter_string_tmp[0] = filter[i];
filter_string_tmp[1] = '\0';
addr_string_tmp[0] = addr[i];
addr_string_tmp[1] = '\0';
sscanf(filter_string_tmp,"%x",&filter_tmp);
sscanf(addr_string_tmp,"%x",&addr_tmp);
for(i = 0; i < (filter_len % 4); i++)
{
if(((filter_tmp >> (4 -i -1)) & 1) != ((addr_tmp >> (4 -i -1)) & 1))
return FALSE;
}
}
}
return TRUE;
}
static gboolean
filter_spi_match(gchar *spi, gchar *filter)
{
guint i;
guint filter_len = (guint)strlen(filter);
if((filter_len == 1) && (filter[0] == IPSEC_SA_WILDCARDS_ANY))
return TRUE;
else if(strlen(spi) != filter_len)
return FALSE;
for(i = 0; filter[i]; i++)
if((filter[i] != IPSEC_SA_WILDCARDS_ANY) && (filter[i] != spi[i]))
return FALSE;
return TRUE;
}
static gint
compute_ascii_key(gchar **ascii_key, const gchar *key)
{
guint key_len = 0;
gint hex_digit;
guchar key_byte;
guint i, j;
if(key != NULL)
{
if((strlen(key) > 2) && (key[0] == '0') && ((key[1] == 'x') || (key[1] == 'X')))
{
i = 2;
j = 0;
if(strlen(key) %2 == 1)
{
key_len = ((guint) strlen(key) - 2) / 2 + 1;
*ascii_key = (gchar *) g_malloc ((key_len + 1)* sizeof(gchar));
hex_digit = g_ascii_xdigit_value(key[i]);
i++;
if (hex_digit == -1)
{
g_free(*ascii_key);
*ascii_key = NULL;
return -1;
}
(*ascii_key)[j] = (guchar)hex_digit;
j++;
}
else
{
key_len = ((guint) strlen(key) - 2) / 2;
*ascii_key = (gchar *) g_malloc ((key_len + 1)* sizeof(gchar));
}
while(i < (strlen(key) -1))
{
hex_digit = g_ascii_xdigit_value(key[i]);
i++;
if (hex_digit == -1)
{
g_free(*ascii_key);
*ascii_key = NULL;
return -1;
}
key_byte = ((guchar)hex_digit) << 4;
hex_digit = g_ascii_xdigit_value(key[i]);
i++;
if (hex_digit == -1)
{
g_free(*ascii_key);
*ascii_key = NULL;
return -1;
}
key_byte |= (guchar)hex_digit;
(*ascii_key)[j] = key_byte;
j++;
}
(*ascii_key)[j] = '\0';
}
else if((strlen(key) == 2) && (key[0] == '0') && ((key[1] == 'x') || (key[1] == 'X')))
{
return 0;
}
else
{
key_len = (guint) strlen(key);
*ascii_key = g_strdup(key);
}
}
return key_len;
}
static gboolean
get_esp_sa(gint protocol_typ, gchar *src, gchar *dst, gint spi,
gint *encryption_algo,
gint *authentication_algo,
gchar **encryption_key,
guint *encryption_key_len,
gchar **authentication_key,
guint *authentication_key_len
)
{
gboolean found = FALSE;
guint i;
gchar spi_string[IPSEC_SPI_LEN_MAX];
gint key_len;
g_snprintf(spi_string, IPSEC_SPI_LEN_MAX,"0x%08x", spi);
for (i = 0; (found == FALSE) && (i < num_sa_uat); i++)
{
if((protocol_typ == uat_esp_sa_records[i].protocol)
&& filter_address_match(src, uat_esp_sa_records[i].srcIP, protocol_typ)
&& filter_address_match(dst, uat_esp_sa_records[i].dstIP, protocol_typ)
&& filter_spi_match(spi_string, uat_esp_sa_records[i].spi))
{
found = TRUE;
*encryption_algo = uat_esp_sa_records[i].encryption_algo;
*authentication_algo = uat_esp_sa_records[i].authentication_algo;
key_len = compute_ascii_key(authentication_key, uat_esp_sa_records[i].authentication_key);
if (key_len == -1)
{
*authentication_key_len = 0;
found = FALSE;
}
else
*authentication_key_len = (guint)key_len;
key_len = compute_ascii_key(encryption_key, uat_esp_sa_records[i].encryption_key);
if (key_len == -1)
{
*encryption_key_len = 0;
found = FALSE;
}
else
*encryption_key_len = key_len;
}
}
return found;
}
static void
dissect_ah(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *next_tree;
guint8 nxt;
tvbuff_t *next_tvb;
int advance;
advance = dissect_ah_header(tvb, pinfo, tree, &nxt, &next_tree);
next_tvb = tvb_new_subset_remaining(tvb, advance);
if (g_ah_payload_in_subtree) {
col_set_writable(pinfo->cinfo, FALSE);
}
if (!dissector_try_uint(ip_dissector_table, nxt, next_tvb, pinfo, tree)) {
call_dissector(data_handle,next_tvb, pinfo, next_tree);
}
}
int
dissect_ah_header(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint8 *nxt_p, proto_tree **next_tree_p)
{
proto_tree *ah_tree;
proto_item *ti;
struct newah ah;
int advance;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "AH");
col_clear(pinfo->cinfo, COL_INFO);
tvb_memcpy(tvb, (guint8 *)&ah, 0, sizeof(ah));
advance = sizeof(ah) + ((ah.ah_len - 1) << 2);
if (check_col(pinfo->cinfo, COL_INFO)) {
col_add_fstr(pinfo->cinfo, COL_INFO, "AH (SPI=0x%08x)",
(guint32)g_ntohl(ah.ah_spi));
}
if (tree) {
ti = proto_tree_add_item(tree, proto_ah, tvb, 0, advance, ENC_NA);
ah_tree = proto_item_add_subtree(ti, ett_ah);
proto_tree_add_text(ah_tree, tvb,
offsetof(struct newah, ah_nxt), 1,
"Next Header: %s (0x%02x)",
ipprotostr(ah.ah_nxt), ah.ah_nxt);
proto_tree_add_text(ah_tree, tvb,
offsetof(struct newah, ah_len), 1,
"Length: %u", (ah.ah_len + 2) << 2);
proto_tree_add_uint(ah_tree, hf_ah_spi, tvb,
offsetof(struct newah, ah_spi), 4,
(guint32)g_ntohl(ah.ah_spi));
proto_tree_add_uint(ah_tree, hf_ah_sequence, tvb,
offsetof(struct newah, ah_seq), 4,
(guint32)g_ntohl(ah.ah_seq));
proto_tree_add_item(ah_tree, hf_ah_iv, tvb,
sizeof(ah), (ah.ah_len) ? (ah.ah_len - 1) << 2 : 0,
ENC_NA);
if (next_tree_p != NULL) {
if (g_ah_payload_in_subtree) {
*next_tree_p = ah_tree;
}
else {
*next_tree_p = tree;
}
}
} else {
if (next_tree_p != NULL)
*next_tree_p = NULL;
}
if (nxt_p != NULL)
*nxt_p = ah.ah_nxt;
return advance;
}
static void
dissect_esp_authentication(proto_tree *tree, tvbuff_t *tvb, gint len, gint esp_auth_len, guint8 *authenticator_data_computed,
gboolean authentication_ok, gboolean authentication_checking_ok)
{
if(esp_auth_len == 0)
{
proto_tree_add_text(tree, tvb, len, 0,
"NULL Authentication");
}
else if(tvb_bytes_exist(tvb, len - esp_auth_len, esp_auth_len))
{
if((authentication_ok) && (authentication_checking_ok))
{
proto_tree_add_text(tree, tvb, len - esp_auth_len, esp_auth_len,
"Authentication Data [correct]");
}
else if((authentication_ok) && (!authentication_checking_ok))
{
proto_tree_add_text(tree, tvb, len - esp_auth_len, esp_auth_len,
"Authentication Data [incorrect, should be 0x%s]", authenticator_data_computed);
g_free(authenticator_data_computed);
}
else proto_tree_add_text(tree, tvb, len - esp_auth_len, esp_auth_len,
"Authentication Data");
}
else
{
proto_tree_add_text(tree, tvb, len - esp_auth_len, esp_auth_len - (len - tvb_length(tvb)),
"Authentication Data (truncated)");
}
}
static void
dissect_esp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *esp_tree = NULL;
proto_item *ti;
struct newesp esp;
gint len = 0;
#ifdef HAVE_LIBGCRYPT
gint i;
gchar *ip_src = NULL;
gchar *ip_dst = NULL;
guint32 spi = 0;
#endif
guint encapsulated_protocol = 0;
gboolean decrypt_dissect_ok = FALSE;
#ifdef HAVE_LIBGCRYPT
gboolean get_address_ok = FALSE;
gboolean null_encryption_decode_heuristic = FALSE;
guint8 *decrypted_data = NULL;
guint8 *encrypted_data = NULL;
guint8 *authenticator_data = NULL;
guint8 *esp_data = NULL;
tvbuff_t *tvb_decrypted;
gint protocol_typ = IPSEC_SA_UNKNOWN;
gint esp_crypt_algo = IPSEC_ENCRYPT_NULL;
gint esp_auth_algo = IPSEC_AUTH_NULL;
gchar *esp_crypt_key = NULL;
gchar *esp_auth_key = NULL;
guint esp_crypt_key_len = 0;
guint esp_auth_key_len = 0;
gint esp_iv_len = 0;
gint esp_auth_len = 0;
gint decrypted_len = 0;
gboolean decrypt_ok = FALSE;
gboolean decrypt_using_libgcrypt = FALSE;
gboolean authentication_check_using_hmac_libgcrypt = FALSE;
gboolean authentication_ok = FALSE;
gboolean authentication_checking_ok = FALSE;
gboolean sad_is_present = FALSE;
#endif
gint esp_pad_len = 0;
#ifdef HAVE_LIBGCRYPT
int decrypted_len_alloc = 0;
gcry_cipher_hd_t cypher_hd;
gcry_md_hd_t md_hd;
int md_len = 0;
gcry_error_t err = 0;
int crypt_algo_libgcrypt = 0;
int crypt_mode_libgcrypt = 0;
int auth_algo_libgcrypt = 0;
unsigned char *authenticator_data_computed = NULL;
unsigned char *authenticator_data_computed_md;
unsigned char ctr_block[16];
#endif
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ESP");
col_clear(pinfo->cinfo, COL_INFO);
tvb_memcpy(tvb, (guint8 *)&esp, 0, sizeof(esp));
if (check_col(pinfo->cinfo, COL_INFO)) {
col_add_fstr(pinfo->cinfo, COL_INFO, "ESP (SPI=0x%08x)",
(guint32)g_ntohl(esp.esp_spi));
}
if(tree) {
len = 0, encapsulated_protocol = 0;
decrypt_dissect_ok = FALSE;
ti = proto_tree_add_item(tree, proto_esp, tvb, 0, -1, ENC_NA);
esp_tree = proto_item_add_subtree(ti, ett_esp);
proto_tree_add_uint(esp_tree, hf_esp_spi, tvb,
offsetof(struct newesp, esp_spi), 4,
(guint32)g_ntohl(esp.esp_spi));
proto_tree_add_uint(esp_tree, hf_esp_sequence, tvb,
offsetof(struct newesp, esp_seq), 4,
(guint32)g_ntohl(esp.esp_seq));
}
#ifdef HAVE_LIBGCRYPT
if(g_esp_enable_null_encryption_decode_heuristic &&
!g_esp_enable_encryption_decode)
null_encryption_decode_heuristic = TRUE;
if(g_esp_enable_encryption_decode || g_esp_enable_authentication_check)
{
if (pinfo->src.type == AT_IPv4){
protocol_typ = IPSEC_SA_IPV4;
}else if (pinfo->src.type == AT_IPv6){
protocol_typ = IPSEC_SA_IPV6;
}
ip_src = ep_address_to_str(&pinfo->src);
ip_dst = ep_address_to_str(&pinfo->dst);
get_address_ok = TRUE;
if(g_esp_enable_null_encryption_decode_heuristic && !get_address_ok)
null_encryption_decode_heuristic = TRUE;
if(get_address_ok)
{
if (tvb_length(tvb) >= 4)
{
spi = tvb_get_ntohl(tvb, 0);
}
if((sad_is_present = get_esp_sa(protocol_typ, ip_src, ip_dst, spi,
&esp_crypt_algo, &esp_auth_algo,
&esp_crypt_key, &esp_crypt_key_len, &esp_auth_key, &esp_auth_key_len)))
{
len = tvb_reported_length(tvb);
switch(esp_auth_algo)
{
case IPSEC_AUTH_NULL:
esp_auth_len = 0;
break;
case IPSEC_AUTH_HMAC_SHA256_128:
case IPSEC_AUTH_ANY_128BIT:
esp_auth_len = 16;
break;
case IPSEC_AUTH_ANY_256BIT:
esp_auth_len = 32;
break;
case IPSEC_AUTH_ANY_192BIT:
esp_auth_len = 24;
break;
case IPSEC_AUTH_HMAC_SHA1_96:
case IPSEC_AUTH_HMAC_SHA256_96:
case IPSEC_AUTH_HMAC_MD5_96:
case IPSEC_AUTH_HMAC_RIPEMD160_96:
case IPSEC_AUTH_ANY_96BIT:
default:
esp_auth_len = 12;
break;
}
if(g_esp_enable_authentication_check)
{
switch(esp_auth_algo)
{
case IPSEC_AUTH_HMAC_SHA1_96:
auth_algo_libgcrypt = GCRY_MD_SHA1;
authentication_check_using_hmac_libgcrypt = TRUE;
break;
case IPSEC_AUTH_NULL:
authentication_check_using_hmac_libgcrypt = FALSE;
authentication_checking_ok = TRUE;
authentication_ok = TRUE;
break;
case IPSEC_AUTH_HMAC_SHA256_96:
case IPSEC_AUTH_HMAC_SHA256_128:
auth_algo_libgcrypt = GCRY_MD_SHA256;
authentication_check_using_hmac_libgcrypt = TRUE;
break;
case IPSEC_AUTH_HMAC_MD5_96:
auth_algo_libgcrypt = GCRY_MD_MD5;
authentication_check_using_hmac_libgcrypt = TRUE;
break;
case IPSEC_AUTH_HMAC_RIPEMD160_96:
auth_algo_libgcrypt = GCRY_MD_RMD160;
authentication_check_using_hmac_libgcrypt = TRUE;
break;
case IPSEC_AUTH_ANY_96BIT:
case IPSEC_AUTH_ANY_128BIT:
case IPSEC_AUTH_ANY_192BIT:
case IPSEC_AUTH_ANY_256BIT:
default:
authentication_ok = FALSE;
authentication_check_using_hmac_libgcrypt = FALSE;
break;
}
if((authentication_check_using_hmac_libgcrypt) && (!authentication_ok))
{
gcry_control (GCRYCTL_DISABLE_SECMEM, 0);
gcry_control (GCRYCTL_INITIALIZATION_FINISHED, 0);
authenticator_data = (guint8 *) g_malloc0 (( esp_auth_len + 1) * sizeof(guint8));
tvb_memcpy(tvb, authenticator_data, len - esp_auth_len, esp_auth_len);
esp_data = (guint8 *) g_malloc0 (( len - esp_auth_len + 1) * sizeof(guint8));
tvb_memcpy(tvb, esp_data, 0, len - esp_auth_len);
err = gcry_md_open (&md_hd, auth_algo_libgcrypt, GCRY_MD_FLAG_HMAC);
if (err)
{
fprintf (stderr, "<IPsec/ESP Dissector> Error in Algorithm %s, gcry_md_open failed: %s\n",
gcry_md_algo_name(auth_algo_libgcrypt), gpg_strerror (err));
authentication_ok = FALSE;
g_free(authenticator_data);
g_free(esp_data);
}
else
{
md_len = gcry_md_get_algo_dlen (auth_algo_libgcrypt);
if (md_len < 1 || md_len < esp_auth_len)
{
fprintf (stderr, "<IPsec/ESP Dissector> Error in Algorithm %s, grcy_md_get_algo_dlen failed: %d\n",
gcry_md_algo_name(auth_algo_libgcrypt), md_len);
authentication_ok = FALSE;
}
else
{
gcry_md_setkey( md_hd, esp_auth_key, esp_auth_key_len );
gcry_md_write (md_hd, esp_data, len - esp_auth_len);
authenticator_data_computed_md = gcry_md_read (md_hd, auth_algo_libgcrypt);
if (authenticator_data_computed_md == 0)
{
fprintf (stderr, "<IPsec/ESP Dissector> Error in Algorithm %s, gcry_md_read failed\n",
gcry_md_algo_name(auth_algo_libgcrypt));
authentication_ok = FALSE;
}
else
{
if(memcmp (authenticator_data_computed_md, authenticator_data, esp_auth_len))
{
unsigned char authenticator_data_computed_car[3];
authenticator_data_computed = (guint8 *) g_malloc (( esp_auth_len * 2 + 1) * sizeof(guint8));
for (i = 0; i < esp_auth_len; i++)
{
g_snprintf((char *)authenticator_data_computed_car, 3,
"%02X", authenticator_data_computed_md[i] & 0xFF);
authenticator_data_computed[i*2] = authenticator_data_computed_car[0];
authenticator_data_computed[i*2 + 1] = authenticator_data_computed_car[1];
}
authenticator_data_computed[esp_auth_len * 2] ='\0';
authentication_ok = TRUE;
authentication_checking_ok = FALSE;
}
else
{
authentication_ok = TRUE;
authentication_checking_ok = TRUE;
}
}
}
gcry_md_close (md_hd);
g_free(authenticator_data);
g_free(esp_data);
}
}
}
if(g_esp_enable_encryption_decode)
{
null_encryption_decode_heuristic = FALSE;
switch(esp_crypt_algo)
{
case IPSEC_ENCRYPT_3DES_CBC :
esp_iv_len = 8;
crypt_algo_libgcrypt = GCRY_CIPHER_3DES;
crypt_mode_libgcrypt = GCRY_CIPHER_MODE_CBC;
decrypted_len = len - sizeof(struct newesp);
if (decrypted_len <= 0)
decrypt_ok = FALSE;
else
{
if(decrypted_len % esp_iv_len == 0)
decrypted_len_alloc = decrypted_len;
else
decrypted_len_alloc = (decrypted_len / esp_iv_len) * esp_iv_len + esp_iv_len;
if (esp_crypt_key_len != gcry_cipher_get_algo_keylen (crypt_algo_libgcrypt))
{
fprintf (stderr, "<ESP Preferences> Error in Encryption Algorithm 3DES-CBC : Bad Keylen (got %i Bits, need %lu)\n",
esp_crypt_key_len * 8,
(unsigned long) gcry_cipher_get_algo_keylen (crypt_algo_libgcrypt) * 8);
decrypt_ok = FALSE;
}
else
decrypt_using_libgcrypt = TRUE;
}
break;
case IPSEC_ENCRYPT_AES_CBC :
esp_iv_len = 16;
crypt_mode_libgcrypt = GCRY_CIPHER_MODE_CBC;
decrypted_len = len - sizeof(struct newesp);
if (decrypted_len <= 0)
decrypt_ok = FALSE;
else
{
if(decrypted_len % esp_iv_len == 0)
decrypted_len_alloc = decrypted_len;
else
decrypted_len_alloc = (decrypted_len / esp_iv_len) * esp_iv_len + esp_iv_len;
switch(esp_crypt_key_len * 8)
{
case 128:
crypt_algo_libgcrypt = GCRY_CIPHER_AES128;
decrypt_using_libgcrypt = TRUE;
break;
case 192:
crypt_algo_libgcrypt = GCRY_CIPHER_AES192;
decrypt_using_libgcrypt = TRUE;
break;
case 256:
crypt_algo_libgcrypt = GCRY_CIPHER_AES256;
decrypt_using_libgcrypt = TRUE;
break;
default:
fprintf (stderr, "<ESP Preferences> Error in Encryption Algorithm AES-CBC : Bad Keylen (%i Bits)\n",
esp_crypt_key_len * 8);
decrypt_ok = FALSE;
}
}
break;
case IPSEC_ENCRYPT_CAST5_CBC :
esp_iv_len = 8;
crypt_mode_libgcrypt = GCRY_CIPHER_MODE_CBC;
decrypted_len = len - sizeof(struct newesp);
if (decrypted_len <= 0)
decrypt_ok = FALSE;
else
{
if(decrypted_len % esp_iv_len == 0)
decrypted_len_alloc = decrypted_len;
else
decrypted_len_alloc = (decrypted_len / esp_iv_len) * esp_iv_len + esp_iv_len;
switch(esp_crypt_key_len * 8)
{
case 128:
crypt_algo_libgcrypt = GCRY_CIPHER_CAST5;
decrypt_using_libgcrypt = TRUE;
break;
default:
fprintf (stderr, "<ESP Preferences> Error in Encryption Algorithm CAST5-CBC : Bad Keylen (%i Bits)\n",
esp_crypt_key_len * 8);
decrypt_ok = FALSE;
}
}
break;
case IPSEC_ENCRYPT_DES_CBC :
esp_iv_len = 8;
crypt_algo_libgcrypt = GCRY_CIPHER_DES;
crypt_mode_libgcrypt = GCRY_CIPHER_MODE_CBC;
decrypted_len = len - sizeof(struct newesp);
if (decrypted_len <= 0)
decrypt_ok = FALSE;
else
{
if(decrypted_len % esp_iv_len == 0)
decrypted_len_alloc = decrypted_len;
else
decrypted_len_alloc = (decrypted_len / esp_iv_len) * esp_iv_len + esp_iv_len;
if (esp_crypt_key_len != gcry_cipher_get_algo_keylen (crypt_algo_libgcrypt))
{
fprintf (stderr, "<ESP Preferences> Error in Encryption Algorithm DES-CBC : Bad Keylen (%i Bits, need %lu)\n",
esp_crypt_key_len * 8, (unsigned long) gcry_cipher_get_algo_keylen (crypt_algo_libgcrypt) * 8);
decrypt_ok = FALSE;
}
else
decrypt_using_libgcrypt = TRUE;
}
break;
case IPSEC_ENCRYPT_AES_CTR :
esp_iv_len = 8;
crypt_mode_libgcrypt = GCRY_CIPHER_MODE_CTR;
decrypted_len = len - sizeof(struct newesp);
if (decrypted_len <= 0)
decrypt_ok = FALSE;
else
{
if(decrypted_len % esp_iv_len == 0)
decrypted_len_alloc = decrypted_len;
else
decrypted_len_alloc = (decrypted_len / esp_iv_len) * esp_iv_len + esp_iv_len;
switch(esp_crypt_key_len * 8)
{
case 160:
crypt_algo_libgcrypt = GCRY_CIPHER_AES128;
decrypt_using_libgcrypt = TRUE;
break;
case 224:
crypt_algo_libgcrypt = GCRY_CIPHER_AES192;
decrypt_using_libgcrypt = TRUE;
break;
case 288:
crypt_algo_libgcrypt = GCRY_CIPHER_AES256;
decrypt_using_libgcrypt = TRUE;
break;
default:
fprintf (stderr, "<ESP Preferences> Error in Encryption Algorithm AES-CTR : Bad Keylen (%i Bits)\n",
esp_crypt_key_len * 8);
decrypt_ok = FALSE;
}
}
break;
case IPSEC_ENCRYPT_TWOFISH_CBC :
esp_iv_len = 16;
crypt_mode_libgcrypt = GCRY_CIPHER_MODE_CBC;
decrypted_len = len - sizeof(struct newesp);
if (decrypted_len <= 0)
decrypt_ok = FALSE;
else
{
if(decrypted_len % esp_iv_len == 0)
decrypted_len_alloc = decrypted_len;
else
decrypted_len_alloc = (decrypted_len / esp_iv_len) * esp_iv_len + esp_iv_len;
switch(esp_crypt_key_len * 8)
{
case 128:
crypt_algo_libgcrypt = GCRY_CIPHER_TWOFISH128;
decrypt_using_libgcrypt = TRUE;
break;
case 256:
crypt_algo_libgcrypt = GCRY_CIPHER_TWOFISH;
decrypt_using_libgcrypt = TRUE;
break;
default:
fprintf (stderr, "<ESP Preferences> Error in Encryption Algorithm TWOFISH-CBC : Bad Keylen (%i Bits)\n",
esp_crypt_key_len * 8);
decrypt_ok = FALSE;
}
}
break;
case IPSEC_ENCRYPT_BLOWFISH_CBC :
esp_iv_len = 8;
crypt_algo_libgcrypt = GCRY_CIPHER_BLOWFISH;
crypt_mode_libgcrypt = GCRY_CIPHER_MODE_CBC;
decrypted_len = len - sizeof(struct newesp);
if (decrypted_len <= 0)
decrypt_ok = FALSE;
else
{
if(decrypted_len % esp_iv_len == 0)
decrypted_len_alloc = decrypted_len;
else
decrypted_len_alloc = (decrypted_len / esp_iv_len) * esp_iv_len + esp_iv_len;
if (esp_crypt_key_len != gcry_cipher_get_algo_keylen (crypt_algo_libgcrypt))
{
fprintf (stderr, "<ESP Preferences> Error in Encryption Algorithm BLOWFISH-CBC : Bad Keylen (%i Bits, need %lu)\n",
esp_crypt_key_len * 8, (unsigned long) gcry_cipher_get_algo_keylen (crypt_algo_libgcrypt) * 8);
decrypt_ok = FALSE;
}
else
decrypt_using_libgcrypt = TRUE;
}
break;
case IPSEC_ENCRYPT_NULL :
default :
esp_iv_len = 0;
decrypted_len = len - sizeof(struct newesp);
if (decrypted_len <= 0)
decrypt_ok = FALSE;
else
{
decrypted_data = (guint8 *) g_malloc ((decrypted_len + 1)* sizeof(guint8));
tvb_memcpy(tvb, decrypted_data , sizeof(struct newesp), decrypted_len);
decrypt_ok = TRUE;
}
break;
}
if(decrypt_using_libgcrypt)
{
encrypted_data = (guint8 *) g_malloc0 ((decrypted_len_alloc) * sizeof(guint8));
decrypted_data = (guint8 *) g_malloc ((decrypted_len_alloc + esp_iv_len)* sizeof(guint8));
tvb_memcpy(tvb, encrypted_data , sizeof(struct newesp), decrypted_len);
err = gcry_cipher_open (&cypher_hd, crypt_algo_libgcrypt, crypt_mode_libgcrypt, 0);
if (err)
{
fprintf(stderr, "<IPsec/ESP Dissector> Error in Algorithm %s Mode %d, grcy_open_cipher failed: %s\n",
gcry_cipher_algo_name(crypt_algo_libgcrypt), crypt_mode_libgcrypt, gpg_strerror (err));
g_free(encrypted_data);
g_free(decrypted_data);
decrypt_ok = FALSE;
}
else
{
if (crypt_mode_libgcrypt == GCRY_CIPHER_MODE_CTR)
{
err = gcry_cipher_setkey (cypher_hd, esp_crypt_key, esp_crypt_key_len - 4);
}
else
{
err = gcry_cipher_setkey (cypher_hd, esp_crypt_key, esp_crypt_key_len);
}
if (err)
{
fprintf(stderr, "<IPsec/ESP Dissector> Error in Algorithm %s Mode %d, gcry_cipher_setkey(key_len=%d) failed: %s\n",
gcry_cipher_algo_name(crypt_algo_libgcrypt), crypt_mode_libgcrypt, esp_crypt_key_len, gpg_strerror (err));
gcry_cipher_close (cypher_hd);
g_free(encrypted_data);
g_free(decrypted_data);
decrypt_ok = FALSE;
}
else
{
if (crypt_mode_libgcrypt == GCRY_CIPHER_MODE_CTR)
{
memset(ctr_block, 0, 16);
memcpy(ctr_block, esp_crypt_key + esp_crypt_key_len - 4, 4);
memcpy(ctr_block + 4, encrypted_data, 8);
ctr_block[15] = 1;
err = gcry_cipher_setctr (cypher_hd, ctr_block, 16);
if (!err)
{
memcpy(decrypted_data, encrypted_data, esp_iv_len);
err = gcry_cipher_decrypt (cypher_hd, decrypted_data + esp_iv_len, decrypted_len_alloc,
encrypted_data + esp_iv_len, decrypted_len_alloc - esp_iv_len);
}
}
else
{
err = gcry_cipher_decrypt (cypher_hd, decrypted_data, decrypted_len_alloc + esp_iv_len,
encrypted_data, decrypted_len_alloc);
}
if (err)
{
fprintf(stderr, "<IPsec/ESP Dissector> Error in Algorithm %s, Mode %d, gcry_cipher_decrypt failed: %s\n",
gcry_cipher_algo_name(crypt_algo_libgcrypt), crypt_mode_libgcrypt, gpg_strerror (err));
gcry_cipher_close (cypher_hd);
g_free(encrypted_data);
g_free(decrypted_data);
decrypt_ok = FALSE;
}
else
{
gcry_cipher_close (cypher_hd);
if(decrypted_len >= esp_auth_len)
{
for(i = 0; i < esp_auth_len; i++)
{
decrypted_data[i + decrypted_len -esp_auth_len]
= encrypted_data[i + decrypted_len - esp_auth_len];
}
}
fprintf(stderr,"\n\n ");
g_free(encrypted_data);
decrypt_ok = TRUE;
}
}
}
}
if(decrypt_ok && (decrypted_len > esp_iv_len))
{
tvb_decrypted = tvb_new_child_real_data(tvb, g_memdup(decrypted_data+sizeof(guint8)*esp_iv_len,
(decrypted_len - esp_iv_len)*sizeof(guint8)),
decrypted_len - esp_iv_len, decrypted_len - esp_iv_len);
g_free(decrypted_data);
add_new_data_source(pinfo, tvb_decrypted, "Decrypted Data");
tvb_set_free_cb(tvb_decrypted,g_free);
if(tvb_bytes_exist(tvb, 8, esp_iv_len))
{
if(esp_iv_len > 0)
proto_tree_add_item(esp_tree, hf_esp_iv, tvb, 8, esp_iv_len, ENC_NA);
}
else
proto_tree_add_text(esp_tree, tvb, 8, -1, "IV (truncated)");
if(tvb_bytes_exist(tvb_decrypted, decrypted_len - esp_iv_len - esp_auth_len - 2, 2))
{
esp_pad_len = tvb_get_guint8(tvb_decrypted, decrypted_len - esp_iv_len - esp_auth_len - 2);
if(decrypted_len - esp_iv_len - esp_auth_len - esp_pad_len - 2 >= 0)
{
encapsulated_protocol = tvb_get_guint8(tvb_decrypted, decrypted_len - esp_iv_len - esp_auth_len - 1);
if(dissector_try_uint(ip_dissector_table,
encapsulated_protocol,
tvb_new_subset(tvb_decrypted, 0,
decrypted_len - esp_auth_len - esp_pad_len - esp_iv_len - 2,
decrypted_len - esp_auth_len - esp_pad_len - esp_iv_len - 2),
pinfo,
tree))
{
decrypt_dissect_ok = TRUE;
}
}
}
if(decrypt_dissect_ok)
{
if(esp_tree)
{
if(esp_pad_len !=0)
proto_tree_add_text(esp_tree,
tvb_decrypted,
decrypted_len - esp_iv_len - esp_auth_len - 2 - esp_pad_len,
esp_pad_len,
"Pad");
proto_tree_add_uint(esp_tree, hf_esp_pad_len, tvb_decrypted,
decrypted_len - esp_iv_len - esp_auth_len - 2, 1,
esp_pad_len);
proto_tree_add_uint_format(esp_tree, hf_esp_protocol, tvb_decrypted,
decrypted_len - esp_iv_len - esp_auth_len - 1, 1,
encapsulated_protocol,
"Next header: %s (0x%02x)",
ipprotostr(encapsulated_protocol), encapsulated_protocol);
dissect_esp_authentication(esp_tree,
tvb_decrypted,
decrypted_len - esp_iv_len,
esp_auth_len,
authenticator_data_computed,
authentication_ok,
authentication_checking_ok );
}
}
else
{
call_dissector(data_handle,
tvb_new_subset(tvb_decrypted, 0,
decrypted_len - esp_iv_len - esp_auth_len,
decrypted_len - esp_iv_len - esp_auth_len),
pinfo, esp_tree);
if(esp_tree)
dissect_esp_authentication(esp_tree,
tvb_decrypted,
decrypted_len - esp_iv_len, esp_auth_len,
authenticator_data_computed, authentication_ok,
authentication_checking_ok );
}
}
}
else
{
null_encryption_decode_heuristic = g_esp_enable_null_encryption_decode_heuristic;
}
if(esp_auth_key_len != 0)
g_free(esp_auth_key);
if(esp_crypt_key_len != 0)
g_free(esp_crypt_key);
}
}
}
if(!g_esp_enable_encryption_decode && g_esp_enable_authentication_check && sad_is_present)
{
sad_is_present = FALSE;
call_dissector(data_handle,
tvb_new_subset(tvb, sizeof(struct newesp), len - sizeof(struct newesp) - esp_auth_len, -1),
pinfo, esp_tree);
if(esp_tree)
dissect_esp_authentication(esp_tree, tvb, len ,
esp_auth_len, authenticator_data_computed,
authentication_ok, authentication_checking_ok );
}
else if(null_encryption_decode_heuristic)
{
#endif
if(g_esp_enable_null_encryption_decode_heuristic)
{
len = tvb_reported_length(tvb);
if(tvb_bytes_exist(tvb, len - 14, 2))
{
esp_pad_len = tvb_get_guint8(tvb, len - 14);
encapsulated_protocol = tvb_get_guint8(tvb, len - 13);
if(dissector_try_uint(ip_dissector_table,
encapsulated_protocol,
tvb_new_subset(tvb,
sizeof(struct newesp),
-1,
len - sizeof(struct newesp) - 14 - esp_pad_len),
pinfo,
tree))
{
decrypt_dissect_ok = TRUE;
}
}
}
if(decrypt_dissect_ok)
{
if(esp_tree)
{
proto_tree_add_uint(esp_tree, hf_esp_pad_len, tvb,
len - 14, 1,
esp_pad_len);
proto_tree_add_uint_format(esp_tree, hf_esp_protocol, tvb,
len - 13, 1,
encapsulated_protocol,
"Next header: %s (0x%02x)",
ipprotostr(encapsulated_protocol), encapsulated_protocol);
if(tvb_bytes_exist(tvb, len - 12, 12))
{
proto_tree_add_text(esp_tree, tvb, len - 12, 12, "Authentication Data");
}
else
{
proto_tree_add_text(esp_tree, tvb, len - 12, 12 - (len - tvb_length(tvb)),
"Authentication Data (truncated)");
}
}
}
#ifdef HAVE_LIBGCRYPT
}
#endif
}
static void
dissect_ipcomp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *ipcomp_tree;
proto_item *ti;
struct ipcomp ipcomp;
const char *p;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "IPComp");
col_clear(pinfo->cinfo, COL_INFO);
tvb_memcpy(tvb, (guint8 *)&ipcomp, 0, sizeof(ipcomp));
if (check_col(pinfo->cinfo, COL_INFO)) {
p = match_strval(g_ntohs(ipcomp.comp_cpi), cpi2val);
if (p == NULL) {
col_add_fstr(pinfo->cinfo, COL_INFO, "IPComp (CPI=0x%04x)",
g_ntohs(ipcomp.comp_cpi));
} else
col_add_fstr(pinfo->cinfo, COL_INFO, "IPComp (CPI=%s)", p);
}
if (tree) {
tvbuff_t *data, *decomp;
ti = proto_tree_add_item(tree, proto_ipcomp, tvb, 0, -1, ENC_NA);
ipcomp_tree = proto_item_add_subtree(ti, ett_ipcomp);
proto_tree_add_text(ipcomp_tree, tvb,
offsetof(struct ipcomp, comp_nxt), 1,
"Next Header: %s (0x%02x)",
ipprotostr(ipcomp.comp_nxt), ipcomp.comp_nxt);
proto_tree_add_uint(ipcomp_tree, hf_ipcomp_flags, tvb,
offsetof(struct ipcomp, comp_flags), 1,
ipcomp.comp_flags);
proto_tree_add_uint(ipcomp_tree, hf_ipcomp_cpi, tvb,
offsetof(struct ipcomp, comp_cpi), 2,
g_ntohs(ipcomp.comp_cpi));
data = tvb_new_subset(tvb, sizeof(struct ipcomp), -1, -1);
call_dissector(data_handle, data, pinfo, ipcomp_tree);
decomp = tvb_child_uncompress(data, data, 0, tvb_length(data));
if (decomp) {
add_new_data_source(pinfo, decomp, "IPcomp inflated data");
if (!dissector_try_uint(ip_dissector_table, ipcomp.comp_nxt, decomp, pinfo, tree))
call_dissector(data_handle, decomp, pinfo, tree);
}
}
}
void
proto_register_ipsec(void)
{
static hf_register_info hf_ah[] = {
{ &hf_ah_spi,
{ "AH SPI", "ah.spi", FT_UINT32, BASE_HEX, NULL, 0x0,
"IP Authentication Header Security Parameters Index", HFILL }},
{ &hf_ah_iv,
{ "AH ICV", "ah.icv", FT_BYTES, BASE_NONE, NULL, 0x0,
"IP Authentication Header Integrity Check Value", HFILL }},
{ &hf_ah_sequence,
{ "AH Sequence", "ah.sequence", FT_UINT32, BASE_DEC, NULL, 0x0,
"IP Authentication Header Sequence Number", HFILL }}
};
static hf_register_info hf_esp[] = {
{ &hf_esp_spi,
{ "ESP SPI", "esp.spi", FT_UINT32, BASE_HEX_DEC, NULL, 0x0,
"IP Encapsulating Security Payload Security Parameters Index", HFILL }},
{ &hf_esp_sequence,
{ "ESP Sequence", "esp.sequence", FT_UINT32, BASE_DEC, NULL, 0x0,
"IP Encapsulating Security Payload Sequence Number", HFILL }},
{ &hf_esp_pad_len,
{ "ESP Pad Length", "esp.pad_len", FT_UINT8, BASE_DEC, NULL, 0x0,
"IP Encapsulating Security Payload Pad Length", HFILL }},
{ &hf_esp_protocol,
{ "ESP Next Header", "esp.protocol", FT_UINT8, BASE_HEX, NULL, 0x0,
"IP Encapsulating Security Payload Next Header", HFILL }},
{ &hf_esp_iv,
{ "ESP IV", "esp.iv", FT_BYTES, BASE_NONE, NULL, 0x0,
"IP Encapsulating Security Payload", HFILL }}
};
static hf_register_info hf_ipcomp[] = {
{ &hf_ipcomp_flags,
{ "IPComp Flags", "ipcomp.flags", FT_UINT8, BASE_HEX, NULL, 0x0,
"IP Payload Compression Protocol Flags", HFILL }},
{ &hf_ipcomp_cpi,
{ "IPComp CPI", "ipcomp.cpi", FT_UINT16, BASE_HEX, VALS(cpi2val), 0x0,
"IP Payload Compression Protocol Compression Parameter Index", HFILL }},
};
static gint *ett[] = {
&ett_ah,
&ett_esp,
&ett_ipcomp,
};
#ifdef HAVE_LIBGCRYPT
static const value_string esp_proto_type_vals[] = {
{ IPSEC_SA_IPV4, "IPv4" },
{ IPSEC_SA_IPV6, "IPv6" },
{ 0x00, NULL }
};
static const value_string esp_encryption_type_vals[] = {
{ IPSEC_ENCRYPT_NULL, "NULL" },
{ IPSEC_ENCRYPT_3DES_CBC, "TripleDES-CBC [RFC2451]" },
{ IPSEC_ENCRYPT_AES_CBC, "AES-CBC [RFC3602]" },
{ IPSEC_ENCRYPT_AES_CTR, "AES-CTR [RFC3686]" },
{ IPSEC_ENCRYPT_DES_CBC, "DES-CBC [RFC2405]" },
{ IPSEC_ENCRYPT_CAST5_CBC, "CAST5-CBC [RFC2144]" },
{ IPSEC_ENCRYPT_BLOWFISH_CBC, "BLOWFISH-CBC [RFC2451]" },
{ IPSEC_ENCRYPT_TWOFISH_CBC, "TWOFISH-CBC" },
{ 0x00, NULL }
};
static const value_string esp_authentication_type_vals[] = {
{ IPSEC_AUTH_NULL, "NULL" },
{ IPSEC_AUTH_HMAC_SHA1_96, "HMAC-SHA-1-96 [RFC2404]" },
{ IPSEC_AUTH_HMAC_SHA256_96, "HMAC-SHA-256-96 [draft-ietf-ipsec-ciph-sha-256-00]" },
{ IPSEC_AUTH_HMAC_SHA256_128, "HMAC-SHA-256-128 [RFC4868]" },
{ IPSEC_AUTH_HMAC_MD5_96, "HMAC-MD5-96 [RFC2403]" },
{ IPSEC_AUTH_HMAC_RIPEMD160_96, "MAC-RIPEMD-160-96 [RFC2857]" },
{ IPSEC_AUTH_ANY_96BIT, "ANY 96 bit authentication [no checking]" },
{ IPSEC_AUTH_ANY_128BIT, "ANY 128 bit authentication [no checking]" },
{ IPSEC_AUTH_ANY_192BIT, "ANY 192 bit authentication [no checking]" },
{ IPSEC_AUTH_ANY_256BIT, "ANY 256 bit authentication [no checking]" },
{ 0x00, NULL }
};
static uat_field_t esp_uat_flds[] = {
UAT_FLD_VS(uat_esp_sa_records, protocol, "Protocol", esp_proto_type_vals, "Protocol used"),
UAT_FLD_CSTRING(uat_esp_sa_records, srcIP, "Src IP", "Source Address"),
UAT_FLD_CSTRING(uat_esp_sa_records, dstIP, "Dest IP", "Destination Address"),
UAT_FLD_CSTRING(uat_esp_sa_records, spi, "SPI", "SPI"),
UAT_FLD_VS(uat_esp_sa_records, encryption_algo, "Encryption", esp_encryption_type_vals, "Encryption algorithm"),
UAT_FLD_CSTRING(uat_esp_sa_records, encryption_key, "Encryption Key", "Encryption Key"),
UAT_FLD_VS(uat_esp_sa_records, authentication_algo, "Authentication", esp_authentication_type_vals, "Authentication algorithm"),
UAT_FLD_CSTRING(uat_esp_sa_records, authentication_key, "Authentication Key", "Authentication Key"),
UAT_END_FIELDS
};
#endif
module_t *ah_module;
module_t *esp_module;
proto_ah = proto_register_protocol("Authentication Header", "AH", "ah");
proto_register_field_array(proto_ah, hf_ah, array_length(hf_ah));
proto_esp = proto_register_protocol("Encapsulating Security Payload",
"ESP", "esp");
proto_register_field_array(proto_esp, hf_esp, array_length(hf_esp));
proto_ipcomp = proto_register_protocol("IP Payload Compression",
"IPComp", "ipcomp");
proto_register_field_array(proto_ipcomp, hf_ipcomp, array_length(hf_ipcomp));
proto_register_subtree_array(ett, array_length(ett));
ah_module = prefs_register_protocol(proto_ah, NULL);
prefs_register_bool_preference(ah_module, "place_ah_payload_in_subtree",
"Place AH payload in subtree",
"Whether the AH payload decode should be placed in a subtree",
&g_ah_payload_in_subtree);
esp_module = prefs_register_protocol(proto_esp, NULL);
prefs_register_bool_preference(esp_module, "enable_null_encryption_decode_heuristic",
"Attempt to detect/decode NULL encrypted ESP payloads",
"This is done only if the Decoding is not SET or the packet does not belong to a SA. "
"Assumes a 12 byte auth (HMAC-SHA1-96/HMAC-MD5-96/AES-XCBC-MAC-96) "
"and attempts decode based on the ethertype 13 bytes from packet end",
&g_esp_enable_null_encryption_decode_heuristic);
#ifdef HAVE_LIBGCRYPT
prefs_register_bool_preference(esp_module, "enable_encryption_decode",
"Attempt to detect/decode encrypted ESP payloads",
"Attempt to decode based on the SAD described hereafter.",
&g_esp_enable_encryption_decode);
prefs_register_bool_preference(esp_module, "enable_authentication_check",
"Attempt to Check ESP Authentication",
"Attempt to Check ESP Authentication based on the SAD described hereafter.",
&g_esp_enable_authentication_check);
esp_uat = uat_new("ESP SAs",
sizeof(uat_esp_sa_record_t),
"esp_sa",
TRUE,
(void*) &uat_esp_sa_records,
&num_sa_uat,
UAT_CAT_CRYPTO,
NULL,
uat_esp_sa_record_copy_cb,
NULL,
uat_esp_sa_record_free_cb,
NULL,
esp_uat_flds);
prefs_register_uat_preference(esp_module,
"sa_table",
"ESP SAs",
"Preconfigured ESP Security Associations",
esp_uat);
#endif
register_dissector("esp", dissect_esp, proto_esp);
register_dissector("ah", dissect_ah, proto_ah);
}
void
proto_reg_handoff_ipsec(void)
{
dissector_handle_t esp_handle, ah_handle, ipcomp_handle;
data_handle = find_dissector("data");
ah_handle = find_dissector("ah");
dissector_add_uint("ip.proto", IP_PROTO_AH, ah_handle);
esp_handle = find_dissector("esp");
dissector_add_uint("ip.proto", IP_PROTO_ESP, esp_handle);
ipcomp_handle = create_dissector_handle(dissect_ipcomp, proto_ipcomp);
dissector_add_uint("ip.proto", IP_PROTO_IPCOMP, ipcomp_handle);
ip_dissector_table = find_dissector_table("ip.proto");
}
