void aes_gcm_encrypt(void)
{
EVP_CIPHER_CTX *ctx;
int outlen, tmplen;
unsigned char outbuf[1024];
printf("AES GCM Encrypt:\n");
printf("Plaintext:\n");
BIO_dump_fp(stdout, gcm_pt, sizeof(gcm_pt));
ctx = EVP_CIPHER_CTX_new();
EVP_EncryptInit_ex(ctx, EVP_aes_256_gcm(), NULL, NULL, NULL);
EVP_CIPHER_CTX_ctrl(ctx, EVP_CTRL_AEAD_SET_IVLEN, sizeof(gcm_iv), NULL);
EVP_EncryptInit_ex(ctx, NULL, NULL, gcm_key, gcm_iv);
EVP_EncryptUpdate(ctx, NULL, &outlen, gcm_aad, sizeof(gcm_aad));
EVP_EncryptUpdate(ctx, outbuf, &outlen, gcm_pt, sizeof(gcm_pt));
printf("Ciphertext:\n");
BIO_dump_fp(stdout, outbuf, outlen);
EVP_EncryptFinal_ex(ctx, outbuf, &outlen);
EVP_CIPHER_CTX_ctrl(ctx, EVP_CTRL_AEAD_GET_TAG, 16, outbuf);
printf("Tag:\n");
BIO_dump_fp(stdout, outbuf, 16);
EVP_CIPHER_CTX_free(ctx);
}
void aes_gcm_decrypt(void)
{
EVP_CIPHER_CTX *ctx;
int outlen, tmplen, rv;
unsigned char outbuf[1024];
printf("AES GCM Derypt:\n");
printf("Ciphertext:\n");
BIO_dump_fp(stdout, gcm_ct, sizeof(gcm_ct));
ctx = EVP_CIPHER_CTX_new();
EVP_DecryptInit_ex(ctx, EVP_aes_256_gcm(), NULL, NULL, NULL);
EVP_CIPHER_CTX_ctrl(ctx, EVP_CTRL_AEAD_SET_IVLEN, sizeof(gcm_iv), NULL);
EVP_DecryptInit_ex(ctx, NULL, NULL, gcm_key, gcm_iv);
EVP_DecryptUpdate(ctx, NULL, &outlen, gcm_aad, sizeof(gcm_aad));
EVP_DecryptUpdate(ctx, outbuf, &outlen, gcm_ct, sizeof(gcm_ct));
printf("Plaintext:\n");
BIO_dump_fp(stdout, outbuf, outlen);
EVP_CIPHER_CTX_ctrl(ctx, EVP_CTRL_AEAD_SET_TAG, sizeof(gcm_tag), gcm_tag);
rv = EVP_DecryptFinal_ex(ctx, outbuf, &outlen);
printf("Tag Verify %s\n", rv > 0 ? "Successful!" : "Failed!");
EVP_CIPHER_CTX_free(ctx);
}
int main(int argc, char **argv)
{
aes_gcm_encrypt();
aes_gcm_decrypt();
}
