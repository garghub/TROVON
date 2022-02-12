static int
dissect_corosync_totemnet_security_header(tvbuff_t *tvb,
packet_info *pinfo, proto_tree *parent_tree,
gboolean check_crypt_type,
const gchar* key)
{
proto_item *item;
proto_tree *tree;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "COROSYNC/TOTEMNET");
col_clear(pinfo->cinfo, COL_INFO);
if (parent_tree)
{
item = proto_tree_add_item(parent_tree, proto_corosync_totemnet, tvb, 0,
-1, ENC_NA);
tree = proto_item_add_subtree(item, ett_corosync_totemnet_security_header);
proto_tree_add_item(tree,
hf_corosync_totemnet_security_header_hash_digest,
tvb, 0, HASH_SHA1_LENGTH, ENC_NA);
proto_tree_add_item(tree,
hf_corosync_totemnet_security_header_salt,
tvb, HASH_SHA1_LENGTH, SALT_SIZE, ENC_NA);
if (check_crypt_type)
{
int io_len = tvb_reported_length(tvb);
proto_item * key_item;
proto_tree_add_item(tree,
hf_corosync_totemnet_security_crypto_type,
tvb, io_len - 1, 1, ENC_BIG_ENDIAN);
key_item = proto_tree_add_string(tree,
hf_corosync_totemnet_security_crypto_key,
tvb, 0, 0, key);
PROTO_ITEM_SET_GENERATED(key_item);
}
}
return HASH_SHA1_LENGTH + SALT_SIZE;
}
static int
dissect_corosynec_totemnet_with_decryption(tvbuff_t *tvb,
packet_info *pinfo, proto_tree *parent_tree,
gboolean check_crypt_type,
const gchar* key_for_trial)
{
unsigned char keys[48];
sober128_prng keygen_prng_state;
sober128_prng stream_prng_state;
unsigned char *hmac_key = &keys[32];
unsigned char *cipher_key = &keys[16];
unsigned char *initial_vector = &keys[0];
unsigned char digest_comparison[HASH_SHA1_LENGTH];
int io_len;
guint8 *io_base;
#define PRIVATE_KEY_LEN_MAX 256
gchar private_key[PRIVATE_KEY_LEN_MAX];
gsize private_key_len;
unsigned char* hash_digest;
unsigned char* salt;
io_len = tvb_reported_length(tvb) - (check_crypt_type? 1: 0);
if (io_len < HASH_SHA1_LENGTH + SALT_SIZE) {
return 0;
}
io_base = (guint8 *)tvb_memdup(pinfo->pool, tvb, 0, io_len + (check_crypt_type? 1: 0));
if (check_crypt_type &&
( io_base[io_len] != TOTEM_CRYPTO_SOBER )) {
return 0;
}
hash_digest = io_base;
salt = io_base + HASH_SHA1_LENGTH;
memset(private_key, 0, sizeof(private_key));
private_key_len = (strlen(key_for_trial)+4) & 0xFC;
g_strlcpy(private_key, key_for_trial, private_key_len);
memset (keys, 0, sizeof(keys));
sober128_start (&keygen_prng_state);
sober128_add_entropy(private_key,
(unsigned long)private_key_len, &keygen_prng_state);
sober128_add_entropy (salt, SALT_SIZE, &keygen_prng_state);
sober128_read (keys, sizeof (keys), &keygen_prng_state);
sober128_start (&stream_prng_state);
sober128_add_entropy (cipher_key, 16, &stream_prng_state);
sober128_add_entropy (initial_vector, 16, &stream_prng_state);
if (ws_hmac_buffer(GCRY_MD_SHA1, digest_comparison, io_base + HASH_SHA1_LENGTH, io_len - HASH_SHA1_LENGTH, hmac_key, 16)) {
return 0;
}
if (memcmp (digest_comparison, hash_digest, HASH_SHA1_LENGTH) != 0)
return 0;
sober128_read (io_base + HASH_SHA1_LENGTH + SALT_SIZE,
io_len - (HASH_SHA1_LENGTH + SALT_SIZE),
&stream_prng_state);
{
tvbuff_t *decrypted_tvb;
tvbuff_t *next_tvb;
decrypted_tvb = tvb_new_real_data(io_base, io_len, io_len);
tvb_set_child_real_data_tvbuff(tvb, decrypted_tvb);
add_new_data_source(pinfo, decrypted_tvb, "Decrypted Data");
dissect_corosync_totemnet_security_header(decrypted_tvb, pinfo, parent_tree,
check_crypt_type, key_for_trial);
next_tvb = tvb_new_subset_length_caplen(decrypted_tvb,
HASH_SHA1_LENGTH + SALT_SIZE,
io_len - (HASH_SHA1_LENGTH + SALT_SIZE),
io_len - (HASH_SHA1_LENGTH + SALT_SIZE));
return call_dissector(corosync_totemsrp_handle, next_tvb, pinfo, parent_tree) + HASH_SHA1_LENGTH + SALT_SIZE;
}
}
static int
dissect_corosynec_totemnet(tvbuff_t *tvb,
packet_info *pinfo, proto_tree *parent_tree,
void *data _U_)
{
if (corosync_totemnet_private_keys_list)
{
static int last_key_index = -1;
int key_index;
static int last_check_crypt_type_index;
int check_crypt_type_index = -1;
gboolean check_crypt_type_list[] = {FALSE, TRUE};
if (last_key_index != -1)
{
int r;
r = dissect_corosynec_totemnet_with_decryption(tvb,
pinfo,
parent_tree,
check_crypt_type_list[last_check_crypt_type_index],
corosync_totemnet_private_keys_list[last_key_index]);
if (r > 0)
return r;
else
last_key_index = -1;
}
for (key_index = 0;
corosync_totemnet_private_keys_list[key_index];
key_index++)
{
for (check_crypt_type_index = 0;
check_crypt_type_index < 2;
check_crypt_type_index++)
{
int r;
r = dissect_corosynec_totemnet_with_decryption(tvb,
pinfo,
parent_tree,
check_crypt_type_list[check_crypt_type_index],
corosync_totemnet_private_keys_list[key_index]);
if (r > 0)
{
last_key_index = key_index;
last_check_crypt_type_index = check_crypt_type_index;
return r;
}
else if (r < 0)
break;
}
}
}
return call_dissector(corosync_totemsrp_handle, tvb, pinfo, parent_tree);
}
static void
corosync_totemnet_shutdown(void)
{
g_strfreev(corosync_totemnet_private_keys_list);
}
void
proto_register_corosync_totemnet(void)
{
module_t *corosync_totemnet_module;
static hf_register_info hf[] = {
{ &hf_corosync_totemnet_security_header_hash_digest,
{ "Hash digest", "corosync_totemnet.security_header_hash_digest",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_corosync_totemnet_security_header_salt,
{ "Salt", "corosync_totemnet.security_header_salt",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_corosync_totemnet_security_crypto_type,
{ "Cryptographic Type", "corosync_totemnet.security_crypto_type",
FT_UINT8, BASE_DEC, VALS(corosync_totemnet_crypto_type), 0x0,
NULL, HFILL }},
{ &hf_corosync_totemnet_security_crypto_key,
{ "Private Key for decryption", "corosync_totemnet.security_crypto_key",
FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
};
static gint *ett_corosync_totemnet[] = {
&ett_corosync_totemnet_security_header,
};
proto_corosync_totemnet = proto_register_protocol("Totemnet Layer of Corosync Cluster Engine",
"COROSYNC/TOTEMNET", "corosync_totemnet");
proto_register_field_array(proto_corosync_totemnet, hf, array_length(hf));
proto_register_subtree_array(ett_corosync_totemnet, array_length(ett_corosync_totemnet));
corosync_totemnet_module = prefs_register_protocol(proto_corosync_totemnet,
proto_reg_handoff_corosync_totemnet);
prefs_register_string_preference(corosync_totemnet_module, "private_keys", "Private keys",
"Semicolon-separated list of keys for decryption(e.g. key1;key2;..." ,
(const gchar **)&corosync_totemnet_private_keys);
register_shutdown_routine(corosync_totemnet_shutdown);
}
void
proto_reg_handoff_corosync_totemnet(void)
{
static gboolean initialized = FALSE;
static dissector_handle_t corosync_totemnet_handle;
if (!initialized)
{
corosync_totemnet_handle = create_dissector_handle(dissect_corosynec_totemnet, proto_corosync_totemnet);
corosync_totemsrp_handle = find_dissector_add_dependency("corosync_totemsrp", proto_corosync_totemnet);
dissector_add_uint_range_with_preference("udp.port", PORT_COROSYNC_TOTEMNET_RANGE, corosync_totemnet_handle);
initialized = TRUE;
}
if (corosync_totemnet_private_keys_list) {
g_strfreev(corosync_totemnet_private_keys_list);
corosync_totemnet_private_keys_list = NULL;
}
corosync_totemnet_private_keys_list = g_strsplit(corosync_totemnet_private_keys, ";", 0);
}
