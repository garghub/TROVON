u8 *ecryptfs_get_auth_tok_key(struct ecryptfs_auth_tok *auth_tok)
{
return auth_tok->token.password.session_key_encryption_key;
}
void ecryptfs_get_versions(int *major, int *minor, int *file_version)
{
*major = ECRYPTFS_VERSION_MAJOR;
*minor = ECRYPTFS_VERSION_MINOR;
if (file_version)
*file_version = ECRYPTFS_SUPPORTED_FILE_VERSION;
}
int ecryptfs_fill_auth_tok(struct ecryptfs_auth_tok *auth_tok,
const char *key_desc)
{
int major, minor;
ecryptfs_get_versions(&major, &minor, NULL);
auth_tok->version = (((uint16_t)(major << 8) & 0xFF00)
| ((uint16_t)minor & 0x00FF));
auth_tok->token_type = ECRYPTFS_PASSWORD;
strncpy((char *)auth_tok->token.password.signature, key_desc,
ECRYPTFS_PASSWORD_SIG_SIZE);
auth_tok->token.password.session_key_encryption_key_bytes =
ECRYPTFS_MAX_KEY_BYTES;
auth_tok->token.password.flags |=
ECRYPTFS_SESSION_KEY_ENCRYPTION_KEY_SET;
auth_tok->session_key.encrypted_key[0] = 0;
auth_tok->session_key.encrypted_key_size = 0;
auth_tok->token.password.hash_algo = PGP_DIGEST_ALGO_SHA512;
auth_tok->token.password.flags &= ~(ECRYPTFS_PERSISTENT_PASSWORD);
return 0;
}
