void aes_ccm_encrypt(void)
{
EVP_CIPHER_CTX *ctx;
int outlen, tmplen;
unsigned char outbuf[1024];
printf("AES CCM Encrypt:\n");
printf("Plaintext:\n");
BIO_dump_fp(stdout, ccm_pt, sizeof(ccm_pt));
ctx = EVP_CIPHER_CTX_new();
EVP_EncryptInit_ex(ctx, EVP_aes_192_ccm(), NULL, NULL, NULL);
EVP_CIPHER_CTX_ctrl(ctx, EVP_CTRL_AEAD_SET_IVLEN, sizeof(ccm_nonce),
NULL);
EVP_CIPHER_CTX_ctrl(ctx, EVP_CTRL_AEAD_SET_TAG, sizeof(ccm_tag), NULL);
EVP_EncryptInit_ex(ctx, NULL, NULL, ccm_key, ccm_nonce);
EVP_EncryptUpdate(ctx, NULL, &outlen, NULL, sizeof(ccm_pt));
EVP_EncryptUpdate(ctx, NULL, &outlen, ccm_adata, sizeof(ccm_adata));
EVP_EncryptUpdate(ctx, outbuf, &outlen, ccm_pt, sizeof(ccm_pt));
printf("Ciphertext:\n");
BIO_dump_fp(stdout, outbuf, outlen);
EVP_EncryptFinal_ex(ctx, outbuf, &outlen);
EVP_CIPHER_CTX_ctrl(ctx, EVP_CTRL_AEAD_GET_TAG, 16, outbuf);
printf("Tag:\n");
BIO_dump_fp(stdout, outbuf, 16);
EVP_CIPHER_CTX_free(ctx);
}
void aes_ccm_decrypt(void)
{
EVP_CIPHER_CTX *ctx;
int outlen, tmplen, rv;
unsigned char outbuf[1024];
printf("AES CCM Derypt:\n");
printf("Ciphertext:\n");
BIO_dump_fp(stdout, ccm_ct, sizeof(ccm_ct));
ctx = EVP_CIPHER_CTX_new();
EVP_DecryptInit_ex(ctx, EVP_aes_192_ccm(), NULL, NULL, NULL);
EVP_CIPHER_CTX_ctrl(ctx, EVP_CTRL_AEAD_SET_IVLEN, sizeof(ccm_nonce),
NULL);
EVP_CIPHER_CTX_ctrl(ctx, EVP_CTRL_AEAD_SET_TAG,
sizeof(ccm_tag), (void *)ccm_tag);
EVP_DecryptInit_ex(ctx, NULL, NULL, ccm_key, ccm_nonce);
EVP_DecryptUpdate(ctx, NULL, &outlen, NULL, sizeof(ccm_ct));
EVP_DecryptUpdate(ctx, NULL, &outlen, ccm_adata, sizeof(ccm_adata));
rv = EVP_DecryptUpdate(ctx, outbuf, &outlen, ccm_ct, sizeof(ccm_ct));
if (rv > 0) {
printf("Plaintext:\n");
BIO_dump_fp(stdout, outbuf, outlen);
} else
printf("Plaintext not available: tag verify failed.\n");
EVP_CIPHER_CTX_free(ctx);
}
int main(int argc, char **argv)
{
aes_ccm_encrypt();
aes_ccm_decrypt();
}
