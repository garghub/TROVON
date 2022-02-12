static int cmac_size(const EVP_PKEY *pkey)
{
return EVP_MAX_BLOCK_LENGTH;
}
static void cmac_key_free(EVP_PKEY *pkey)
{
CMAC_CTX *cmctx = EVP_PKEY_get0(pkey);
CMAC_CTX_free(cmctx);
}
