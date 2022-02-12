static int cmac_size(const EVP_PKEY *pkey)
{
return EVP_MAX_BLOCK_LENGTH;
}
static void cmac_key_free(EVP_PKEY *pkey)
{
CMAC_CTX *cmctx = (CMAC_CTX *)pkey->pkey.ptr;
if (cmctx)
CMAC_CTX_free(cmctx);
}
