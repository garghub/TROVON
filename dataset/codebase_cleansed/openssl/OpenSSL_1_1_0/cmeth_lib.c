EVP_CIPHER *EVP_CIPHER_meth_new(int cipher_type, int block_size, int key_len)
{
EVP_CIPHER *cipher = OPENSSL_zalloc(sizeof(EVP_CIPHER));
if (cipher != NULL) {
cipher->nid = cipher_type;
cipher->block_size = block_size;
cipher->key_len = key_len;
}
return cipher;
}
EVP_CIPHER *EVP_CIPHER_meth_dup(const EVP_CIPHER *cipher)
{
EVP_CIPHER *to = EVP_CIPHER_meth_new(cipher->nid, cipher->block_size,
cipher->key_len);
if (to != NULL)
memcpy(to, cipher, sizeof(*to));
return to;
}
void EVP_CIPHER_meth_free(EVP_CIPHER *cipher)
{
OPENSSL_free(cipher);
}
int EVP_CIPHER_meth_set_iv_length(EVP_CIPHER *cipher, int iv_len)
{
cipher->iv_len = iv_len;
return 1;
}
int EVP_CIPHER_meth_set_flags(EVP_CIPHER *cipher, unsigned long flags)
{
cipher->flags = flags;
return 1;
}
int EVP_CIPHER_meth_set_impl_ctx_size(EVP_CIPHER *cipher, int ctx_size)
{
cipher->ctx_size = ctx_size;
return 1;
}
int EVP_CIPHER_meth_set_init(EVP_CIPHER *cipher,
int (*init) (EVP_CIPHER_CTX *ctx,
const unsigned char *key,
const unsigned char *iv,
int enc))
{
cipher->init = init;
return 1;
}
int EVP_CIPHER_meth_set_do_cipher(EVP_CIPHER *cipher,
int (*do_cipher) (EVP_CIPHER_CTX *ctx,
unsigned char *out,
const unsigned char *in,
size_t inl))
{
cipher->do_cipher = do_cipher;
return 1;
}
int EVP_CIPHER_meth_set_cleanup(EVP_CIPHER *cipher,
int (*cleanup) (EVP_CIPHER_CTX *))
{
cipher->cleanup = cleanup;
return 1;
}
int EVP_CIPHER_meth_set_set_asn1_params(EVP_CIPHER *cipher,
int (*set_asn1_parameters) (EVP_CIPHER_CTX *,
ASN1_TYPE *))
{
cipher->set_asn1_parameters = set_asn1_parameters;
return 1;
}
int EVP_CIPHER_meth_set_get_asn1_params(EVP_CIPHER *cipher,
int (*get_asn1_parameters) (EVP_CIPHER_CTX *,
ASN1_TYPE *))
{
cipher->get_asn1_parameters = get_asn1_parameters;
return 1;
}
int EVP_CIPHER_meth_set_ctrl(EVP_CIPHER *cipher,
int (*ctrl) (EVP_CIPHER_CTX *, int type,
int arg, void *ptr))
{
cipher->ctrl = ctrl;
return 1;
}
