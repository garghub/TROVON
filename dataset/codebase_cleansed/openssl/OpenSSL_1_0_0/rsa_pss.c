int RSA_verify_PKCS1_PSS(RSA *rsa, const unsigned char *mHash,
const EVP_MD *Hash, const unsigned char *EM, int sLen)
{
int i;
int ret = 0;
int hLen, maskedDBLen, MSBits, emLen;
const unsigned char *H;
unsigned char *DB = NULL;
EVP_MD_CTX ctx;
unsigned char H_[EVP_MAX_MD_SIZE];
hLen = EVP_MD_size(Hash);
if (hLen < 0)
goto err;
if (sLen == -1) sLen = hLen;
else if (sLen == -2) sLen = -2;
else if (sLen < -2)
{
RSAerr(RSA_F_RSA_VERIFY_PKCS1_PSS, RSA_R_SLEN_CHECK_FAILED);
goto err;
}
MSBits = (BN_num_bits(rsa->n) - 1) & 0x7;
emLen = RSA_size(rsa);
if (EM[0] & (0xFF << MSBits))
{
RSAerr(RSA_F_RSA_VERIFY_PKCS1_PSS, RSA_R_FIRST_OCTET_INVALID);
goto err;
}
if (MSBits == 0)
{
EM++;
emLen--;
}
if (emLen < (hLen + sLen + 2))
{
RSAerr(RSA_F_RSA_VERIFY_PKCS1_PSS, RSA_R_DATA_TOO_LARGE);
goto err;
}
if (EM[emLen - 1] != 0xbc)
{
RSAerr(RSA_F_RSA_VERIFY_PKCS1_PSS, RSA_R_LAST_OCTET_INVALID);
goto err;
}
maskedDBLen = emLen - hLen - 1;
H = EM + maskedDBLen;
DB = OPENSSL_malloc(maskedDBLen);
if (!DB)
{
RSAerr(RSA_F_RSA_VERIFY_PKCS1_PSS, ERR_R_MALLOC_FAILURE);
goto err;
}
if (PKCS1_MGF1(DB, maskedDBLen, H, hLen, Hash) < 0)
goto err;
for (i = 0; i < maskedDBLen; i++)
DB[i] ^= EM[i];
if (MSBits)
DB[0] &= 0xFF >> (8 - MSBits);
for (i = 0; DB[i] == 0 && i < (maskedDBLen-1); i++) ;
if (DB[i++] != 0x1)
{
RSAerr(RSA_F_RSA_VERIFY_PKCS1_PSS, RSA_R_SLEN_RECOVERY_FAILED);
goto err;
}
if (sLen >= 0 && (maskedDBLen - i) != sLen)
{
RSAerr(RSA_F_RSA_VERIFY_PKCS1_PSS, RSA_R_SLEN_CHECK_FAILED);
goto err;
}
EVP_MD_CTX_init(&ctx);
EVP_DigestInit_ex(&ctx, Hash, NULL);
EVP_DigestUpdate(&ctx, zeroes, sizeof zeroes);
EVP_DigestUpdate(&ctx, mHash, hLen);
if (maskedDBLen - i)
EVP_DigestUpdate(&ctx, DB + i, maskedDBLen - i);
EVP_DigestFinal(&ctx, H_, NULL);
EVP_MD_CTX_cleanup(&ctx);
if (memcmp(H_, H, hLen))
{
RSAerr(RSA_F_RSA_VERIFY_PKCS1_PSS, RSA_R_BAD_SIGNATURE);
ret = 0;
}
else
ret = 1;
err:
if (DB)
OPENSSL_free(DB);
return ret;
}
int RSA_padding_add_PKCS1_PSS(RSA *rsa, unsigned char *EM,
const unsigned char *mHash,
const EVP_MD *Hash, int sLen)
{
int i;
int ret = 0;
int hLen, maskedDBLen, MSBits, emLen;
unsigned char *H, *salt = NULL, *p;
EVP_MD_CTX ctx;
hLen = EVP_MD_size(Hash);
if (hLen < 0)
goto err;
if (sLen == -1) sLen = hLen;
else if (sLen == -2) sLen = -2;
else if (sLen < -2)
{
RSAerr(RSA_F_RSA_PADDING_ADD_PKCS1_PSS, RSA_R_SLEN_CHECK_FAILED);
goto err;
}
MSBits = (BN_num_bits(rsa->n) - 1) & 0x7;
emLen = RSA_size(rsa);
if (MSBits == 0)
{
*EM++ = 0;
emLen--;
}
if (sLen == -2)
{
sLen = emLen - hLen - 2;
}
else if (emLen < (hLen + sLen + 2))
{
RSAerr(RSA_F_RSA_PADDING_ADD_PKCS1_PSS,
RSA_R_DATA_TOO_LARGE_FOR_KEY_SIZE);
goto err;
}
if (sLen > 0)
{
salt = OPENSSL_malloc(sLen);
if (!salt)
{
RSAerr(RSA_F_RSA_PADDING_ADD_PKCS1_PSS,
ERR_R_MALLOC_FAILURE);
goto err;
}
if (RAND_bytes(salt, sLen) <= 0)
goto err;
}
maskedDBLen = emLen - hLen - 1;
H = EM + maskedDBLen;
EVP_MD_CTX_init(&ctx);
EVP_DigestInit_ex(&ctx, Hash, NULL);
EVP_DigestUpdate(&ctx, zeroes, sizeof zeroes);
EVP_DigestUpdate(&ctx, mHash, hLen);
if (sLen)
EVP_DigestUpdate(&ctx, salt, sLen);
EVP_DigestFinal(&ctx, H, NULL);
EVP_MD_CTX_cleanup(&ctx);
if (PKCS1_MGF1(EM, maskedDBLen, H, hLen, Hash))
goto err;
p = EM;
p += emLen - sLen - hLen - 2;
*p++ ^= 0x1;
if (sLen > 0)
{
for (i = 0; i < sLen; i++)
*p++ ^= salt[i];
}
if (MSBits)
EM[0] &= 0xFF >> (8 - MSBits);
EM[emLen - 1] = 0xbc;
ret = 1;
err:
if (salt)
OPENSSL_free(salt);
return ret;
}
