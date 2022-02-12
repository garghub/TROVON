int RSA_padding_add_PKCS1_OAEP(unsigned char *to, int tlen,
const unsigned char *from, int flen,
const unsigned char *param, int plen)
{
int i, emlen = tlen - 1;
unsigned char *db, *seed;
unsigned char *dbmask, seedmask[SHA_DIGEST_LENGTH];
if (flen > emlen - 2 * SHA_DIGEST_LENGTH - 1)
{
RSAerr(RSA_F_RSA_PADDING_ADD_PKCS1_OAEP,
RSA_R_DATA_TOO_LARGE_FOR_KEY_SIZE);
return 0;
}
if (emlen < 2 * SHA_DIGEST_LENGTH + 1)
{
RSAerr(RSA_F_RSA_PADDING_ADD_PKCS1_OAEP, RSA_R_KEY_SIZE_TOO_SMALL);
return 0;
}
to[0] = 0;
seed = to + 1;
db = to + SHA_DIGEST_LENGTH + 1;
EVP_Digest((void *)param, plen, db, NULL, EVP_sha1(), NULL);
memset(db + SHA_DIGEST_LENGTH, 0,
emlen - flen - 2 * SHA_DIGEST_LENGTH - 1);
db[emlen - flen - SHA_DIGEST_LENGTH - 1] = 0x01;
memcpy(db + emlen - flen - SHA_DIGEST_LENGTH, from, (unsigned int) flen);
if (RAND_bytes(seed, SHA_DIGEST_LENGTH) <= 0)
return 0;
#ifdef PKCS_TESTVECT
memcpy(seed,
"\xaa\xfd\x12\xf6\x59\xca\xe6\x34\x89\xb4\x79\xe5\x07\x6d\xde\xc2\xf0\x6c\xb5\x8f",
20);
#endif
dbmask = OPENSSL_malloc(emlen - SHA_DIGEST_LENGTH);
if (dbmask == NULL)
{
RSAerr(RSA_F_RSA_PADDING_ADD_PKCS1_OAEP, ERR_R_MALLOC_FAILURE);
return 0;
}
if (MGF1(dbmask, emlen - SHA_DIGEST_LENGTH, seed, SHA_DIGEST_LENGTH) < 0)
return 0;
for (i = 0; i < emlen - SHA_DIGEST_LENGTH; i++)
db[i] ^= dbmask[i];
if (MGF1(seedmask, SHA_DIGEST_LENGTH, db, emlen - SHA_DIGEST_LENGTH) < 0)
return 0;
for (i = 0; i < SHA_DIGEST_LENGTH; i++)
seed[i] ^= seedmask[i];
OPENSSL_free(dbmask);
return 1;
}
int RSA_padding_check_PKCS1_OAEP(unsigned char *to, int tlen,
const unsigned char *from, int flen, int num,
const unsigned char *param, int plen)
{
int i, dblen, mlen = -1;
const unsigned char *maskeddb;
int lzero;
unsigned char *db = NULL, seed[SHA_DIGEST_LENGTH], phash[SHA_DIGEST_LENGTH];
unsigned char *padded_from;
int bad = 0;
if (--num < 2 * SHA_DIGEST_LENGTH + 1)
goto decoding_err;
lzero = num - flen;
if (lzero < 0)
{
bad = 1;
lzero = 0;
flen = num;
}
dblen = num - SHA_DIGEST_LENGTH;
db = OPENSSL_malloc(dblen + num);
if (db == NULL)
{
RSAerr(RSA_F_RSA_PADDING_CHECK_PKCS1_OAEP, ERR_R_MALLOC_FAILURE);
return -1;
}
padded_from = db + dblen;
memset(padded_from, 0, lzero);
memcpy(padded_from + lzero, from, flen);
maskeddb = padded_from + SHA_DIGEST_LENGTH;
if (MGF1(seed, SHA_DIGEST_LENGTH, maskeddb, dblen))
return -1;
for (i = 0; i < SHA_DIGEST_LENGTH; i++)
seed[i] ^= padded_from[i];
if (MGF1(db, dblen, seed, SHA_DIGEST_LENGTH))
return -1;
for (i = 0; i < dblen; i++)
db[i] ^= maskeddb[i];
EVP_Digest((void *)param, plen, phash, NULL, EVP_sha1(), NULL);
if (memcmp(db, phash, SHA_DIGEST_LENGTH) != 0 || bad)
goto decoding_err;
else
{
for (i = SHA_DIGEST_LENGTH; i < dblen; i++)
if (db[i] != 0x00)
break;
if (i == dblen || db[i] != 0x01)
goto decoding_err;
else
{
mlen = dblen - ++i;
if (tlen < mlen)
{
RSAerr(RSA_F_RSA_PADDING_CHECK_PKCS1_OAEP, RSA_R_DATA_TOO_LARGE);
mlen = -1;
}
else
memcpy(to, db + i, mlen);
}
}
OPENSSL_free(db);
return mlen;
decoding_err:
RSAerr(RSA_F_RSA_PADDING_CHECK_PKCS1_OAEP, RSA_R_OAEP_DECODING_ERROR);
if (db != NULL) OPENSSL_free(db);
return -1;
}
int PKCS1_MGF1(unsigned char *mask, long len,
const unsigned char *seed, long seedlen, const EVP_MD *dgst)
{
long i, outlen = 0;
unsigned char cnt[4];
EVP_MD_CTX c;
unsigned char md[EVP_MAX_MD_SIZE];
int mdlen;
EVP_MD_CTX_init(&c);
mdlen = EVP_MD_size(dgst);
if (mdlen < 0)
return -1;
for (i = 0; outlen < len; i++)
{
cnt[0] = (unsigned char)((i >> 24) & 255);
cnt[1] = (unsigned char)((i >> 16) & 255);
cnt[2] = (unsigned char)((i >> 8)) & 255;
cnt[3] = (unsigned char)(i & 255);
EVP_DigestInit_ex(&c,dgst, NULL);
EVP_DigestUpdate(&c, seed, seedlen);
EVP_DigestUpdate(&c, cnt, 4);
if (outlen + mdlen <= len)
{
EVP_DigestFinal_ex(&c, mask + outlen, NULL);
outlen += mdlen;
}
else
{
EVP_DigestFinal_ex(&c, md, NULL);
memcpy(mask + outlen, md, len - outlen);
outlen = len;
}
}
EVP_MD_CTX_cleanup(&c);
return 0;
}
static int MGF1(unsigned char *mask, long len, const unsigned char *seed,
long seedlen)
{
return PKCS1_MGF1(mask, len, seed, seedlen, EVP_sha1());
}
