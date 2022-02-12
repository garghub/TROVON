static unsigned int read_ledword(const unsigned char **in)
{
const unsigned char *p = *in;
unsigned int ret;
ret = *p++;
ret |= (*p++ << 8);
ret |= (*p++ << 16);
ret |= (*p++ << 24);
*in = p;
return ret;
}
static int read_lebn(const unsigned char **in, unsigned int nbyte, BIGNUM **r)
{
const unsigned char *p;
unsigned char *tmpbuf, *q;
unsigned int i;
p = *in + nbyte - 1;
tmpbuf = OPENSSL_malloc(nbyte);
if (!tmpbuf)
return 0;
q = tmpbuf;
for (i = 0; i < nbyte; i++)
*q++ = *p--;
*r = BN_bin2bn(tmpbuf, nbyte, NULL);
OPENSSL_free(tmpbuf);
if (*r)
{
*in += nbyte;
return 1;
}
else
return 0;
}
static int do_blob_header(const unsigned char **in, unsigned int length,
unsigned int *pmagic, unsigned int *pbitlen,
int *pisdss, int *pispub)
{
const unsigned char *p = *in;
if (length < 16)
return 0;
if (*p == MS_PUBLICKEYBLOB)
{
if (*pispub == 0)
{
PEMerr(PEM_F_DO_BLOB_HEADER,
PEM_R_EXPECTING_PRIVATE_KEY_BLOB);
return 0;
}
*pispub = 1;
}
else if (*p == MS_PRIVATEKEYBLOB)
{
if (*pispub == 1)
{
PEMerr(PEM_F_DO_BLOB_HEADER,
PEM_R_EXPECTING_PUBLIC_KEY_BLOB);
return 0;
}
*pispub = 0;
}
else
return 0;
p++;
if (*p++ != 0x2)
{
PEMerr(PEM_F_DO_BLOB_HEADER, PEM_R_BAD_VERSION_NUMBER);
return 0;
}
p+= 6;
*pmagic = read_ledword(&p);
*pbitlen = read_ledword(&p);
*pisdss = 0;
switch (*pmagic)
{
case MS_DSS1MAGIC:
*pisdss = 1;
case MS_RSA1MAGIC:
if (*pispub == 0)
{
PEMerr(PEM_F_DO_BLOB_HEADER,
PEM_R_EXPECTING_PRIVATE_KEY_BLOB);
return 0;
}
break;
case MS_DSS2MAGIC:
*pisdss = 1;
case MS_RSA2MAGIC:
if (*pispub == 1)
{
PEMerr(PEM_F_DO_BLOB_HEADER,
PEM_R_EXPECTING_PUBLIC_KEY_BLOB);
return 0;
}
break;
default:
PEMerr(PEM_F_DO_BLOB_HEADER, PEM_R_BAD_MAGIC_NUMBER);
return -1;
}
*in = p;
return 1;
}
static unsigned int blob_length(unsigned bitlen, int isdss, int ispub)
{
unsigned int nbyte, hnbyte;
nbyte = (bitlen + 7) >> 3;
hnbyte = (bitlen + 15) >> 4;
if (isdss)
{
if (ispub)
return 44 + 3 * nbyte;
else
return 64 + 2 * nbyte;
}
else
{
if (ispub)
return 4 + nbyte;
else
return 4 + 2*nbyte + 5*hnbyte;
}
}
static EVP_PKEY *do_b2i(const unsigned char **in, unsigned int length,
int ispub)
{
const unsigned char *p = *in;
unsigned int bitlen, magic;
int isdss;
if (do_blob_header(&p, length, &magic, &bitlen, &isdss, &ispub) <= 0)
{
PEMerr(PEM_F_DO_B2I, PEM_R_KEYBLOB_HEADER_PARSE_ERROR);
return NULL;
}
length -= 16;
if (length < blob_length(bitlen, isdss, ispub))
{
PEMerr(PEM_F_DO_B2I, PEM_R_KEYBLOB_TOO_SHORT);
return NULL;
}
if (isdss)
return b2i_dss(&p, length, bitlen, ispub);
else
return b2i_rsa(&p, length, bitlen, ispub);
}
static EVP_PKEY *do_b2i_bio(BIO *in, int ispub)
{
const unsigned char *p;
unsigned char hdr_buf[16], *buf = NULL;
unsigned int bitlen, magic, length;
int isdss;
EVP_PKEY *ret = NULL;
if (BIO_read(in, hdr_buf, 16) != 16)
{
PEMerr(PEM_F_DO_B2I_BIO, PEM_R_KEYBLOB_TOO_SHORT);
return NULL;
}
p = hdr_buf;
if (do_blob_header(&p, 16, &magic, &bitlen, &isdss, &ispub) <= 0)
return NULL;
length = blob_length(bitlen, isdss, ispub);
buf = OPENSSL_malloc(length);
if (!buf)
{
PEMerr(PEM_F_DO_B2I_BIO, ERR_R_MALLOC_FAILURE);
goto err;
}
p = buf;
if (BIO_read(in, buf, length) != (int)length)
{
PEMerr(PEM_F_DO_B2I_BIO, PEM_R_KEYBLOB_TOO_SHORT);
goto err;
}
if (isdss)
ret = b2i_dss(&p, length, bitlen, ispub);
else
ret = b2i_rsa(&p, length, bitlen, ispub);
err:
if (buf)
OPENSSL_free(buf);
return ret;
}
static EVP_PKEY *b2i_dss(const unsigned char **in, unsigned int length,
unsigned int bitlen, int ispub)
{
const unsigned char *p = *in;
EVP_PKEY *ret = NULL;
DSA *dsa = NULL;
BN_CTX *ctx = NULL;
unsigned int nbyte;
nbyte = (bitlen + 7) >> 3;
dsa = DSA_new();
ret = EVP_PKEY_new();
if (!dsa || !ret)
goto memerr;
if (!read_lebn(&p, nbyte, &dsa->p))
goto memerr;
if (!read_lebn(&p, 20, &dsa->q))
goto memerr;
if (!read_lebn(&p, nbyte, &dsa->g))
goto memerr;
if (ispub)
{
if (!read_lebn(&p, nbyte, &dsa->pub_key))
goto memerr;
}
else
{
if (!read_lebn(&p, 20, &dsa->priv_key))
goto memerr;
if (!(dsa->pub_key = BN_new()))
goto memerr;
if (!(ctx = BN_CTX_new()))
goto memerr;
if (!BN_mod_exp(dsa->pub_key, dsa->g,
dsa->priv_key, dsa->p, ctx))
goto memerr;
BN_CTX_free(ctx);
}
EVP_PKEY_set1_DSA(ret, dsa);
DSA_free(dsa);
*in = p;
return ret;
memerr:
PEMerr(PEM_F_B2I_DSS, ERR_R_MALLOC_FAILURE);
if (dsa)
DSA_free(dsa);
if (ret)
EVP_PKEY_free(ret);
if (ctx)
BN_CTX_free(ctx);
return NULL;
}
static EVP_PKEY *b2i_rsa(const unsigned char **in, unsigned int length,
unsigned int bitlen, int ispub)
{
const unsigned char *p = *in;
EVP_PKEY *ret = NULL;
RSA *rsa = NULL;
unsigned int nbyte, hnbyte;
nbyte = (bitlen + 7) >> 3;
hnbyte = (bitlen + 15) >> 4;
rsa = RSA_new();
ret = EVP_PKEY_new();
if (!rsa || !ret)
goto memerr;
rsa->e = BN_new();
if (!rsa->e)
goto memerr;
if (!BN_set_word(rsa->e, read_ledword(&p)))
goto memerr;
if (!read_lebn(&p, nbyte, &rsa->n))
goto memerr;
if (!ispub)
{
if (!read_lebn(&p, hnbyte, &rsa->p))
goto memerr;
if (!read_lebn(&p, hnbyte, &rsa->q))
goto memerr;
if (!read_lebn(&p, hnbyte, &rsa->dmp1))
goto memerr;
if (!read_lebn(&p, hnbyte, &rsa->dmq1))
goto memerr;
if (!read_lebn(&p, hnbyte, &rsa->iqmp))
goto memerr;
if (!read_lebn(&p, nbyte, &rsa->d))
goto memerr;
}
EVP_PKEY_set1_RSA(ret, rsa);
RSA_free(rsa);
*in = p;
return ret;
memerr:
PEMerr(PEM_F_B2I_RSA, ERR_R_MALLOC_FAILURE);
if (rsa)
RSA_free(rsa);
if (ret)
EVP_PKEY_free(ret);
return NULL;
}
EVP_PKEY *b2i_PrivateKey(const unsigned char **in, long length)
{
return do_b2i(in, length, 0);
}
EVP_PKEY *b2i_PublicKey(const unsigned char **in, long length)
{
return do_b2i(in, length, 1);
}
EVP_PKEY *b2i_PrivateKey_bio(BIO *in)
{
return do_b2i_bio(in, 0);
}
EVP_PKEY *b2i_PublicKey_bio(BIO *in)
{
return do_b2i_bio(in, 1);
}
static void write_ledword(unsigned char **out, unsigned int dw)
{
unsigned char *p = *out;
*p++ = dw & 0xff;
*p++ = (dw>>8) & 0xff;
*p++ = (dw>>16) & 0xff;
*p++ = (dw>>24) & 0xff;
*out = p;
}
static void write_lebn(unsigned char **out, const BIGNUM *bn, int len)
{
int nb, i;
unsigned char *p = *out, *q, c;
nb = BN_num_bytes(bn);
BN_bn2bin(bn, p);
q = p + nb - 1;
for (i = 0; i < nb/2; i++)
{
c = *p;
*p++ = *q;
*q-- = c;
}
*out += nb;
if (len > 0)
{
len -= nb;
if (len > 0)
{
memset(*out, 0, len);
*out += len;
}
}
}
static int do_i2b(unsigned char **out, EVP_PKEY *pk, int ispub)
{
unsigned char *p;
unsigned int bitlen, magic = 0, keyalg;
int outlen, noinc = 0;
if (pk->type == EVP_PKEY_DSA)
{
bitlen = check_bitlen_dsa(pk->pkey.dsa, ispub, &magic);
keyalg = MS_KEYALG_DSS_SIGN;
}
else if (pk->type == EVP_PKEY_RSA)
{
bitlen = check_bitlen_rsa(pk->pkey.rsa, ispub, &magic);
keyalg = MS_KEYALG_RSA_KEYX;
}
else
return -1;
if (bitlen == 0)
return -1;
outlen = 16 + blob_length(bitlen,
keyalg == MS_KEYALG_DSS_SIGN ? 1 : 0, ispub);
if (out == NULL)
return outlen;
if (*out)
p = *out;
else
{
p = OPENSSL_malloc(outlen);
if (!p)
return -1;
*out = p;
noinc = 1;
}
if (ispub)
*p++ = MS_PUBLICKEYBLOB;
else
*p++ = MS_PRIVATEKEYBLOB;
*p++ = 0x2;
*p++ = 0;
*p++ = 0;
write_ledword(&p, keyalg);
write_ledword(&p, magic);
write_ledword(&p, bitlen);
if (keyalg == MS_KEYALG_DSS_SIGN)
write_dsa(&p, pk->pkey.dsa, ispub);
else
write_rsa(&p, pk->pkey.rsa, ispub);
if (!noinc)
*out += outlen;
return outlen;
}
static int do_i2b_bio(BIO *out, EVP_PKEY *pk, int ispub)
{
unsigned char *tmp = NULL;
int outlen, wrlen;
outlen = do_i2b(&tmp, pk, ispub);
if (outlen < 0)
return -1;
wrlen = BIO_write(out, tmp, outlen);
OPENSSL_free(tmp);
if (wrlen == outlen)
return outlen;
return -1;
}
static int check_bitlen_dsa(DSA *dsa, int ispub, unsigned int *pmagic)
{
int bitlen;
bitlen = BN_num_bits(dsa->p);
if ((bitlen & 7) || (BN_num_bits(dsa->q) != 160)
|| (BN_num_bits(dsa->g) > bitlen))
goto badkey;
if (ispub)
{
if (BN_num_bits(dsa->pub_key) > bitlen)
goto badkey;
*pmagic = MS_DSS1MAGIC;
}
else
{
if (BN_num_bits(dsa->priv_key) > 160)
goto badkey;
*pmagic = MS_DSS2MAGIC;
}
return bitlen;
badkey:
PEMerr(PEM_F_CHECK_BITLEN_DSA, PEM_R_UNSUPPORTED_KEY_COMPONENTS);
return 0;
}
static int check_bitlen_rsa(RSA *rsa, int ispub, unsigned int *pmagic)
{
int nbyte, hnbyte, bitlen;
if (BN_num_bits(rsa->e) > 32)
goto badkey;
bitlen = BN_num_bits(rsa->n);
nbyte = BN_num_bytes(rsa->n);
hnbyte = (BN_num_bits(rsa->n) + 15) >> 4;
if (ispub)
{
*pmagic = MS_RSA1MAGIC;
return bitlen;
}
else
{
*pmagic = MS_RSA2MAGIC;
if (BN_num_bytes(rsa->d) > nbyte)
goto badkey;
if ((BN_num_bytes(rsa->iqmp) > hnbyte)
|| (BN_num_bytes(rsa->p) > hnbyte)
|| (BN_num_bytes(rsa->q) > hnbyte)
|| (BN_num_bytes(rsa->dmp1) > hnbyte)
|| (BN_num_bytes(rsa->dmq1) > hnbyte))
goto badkey;
}
return bitlen;
badkey:
PEMerr(PEM_F_CHECK_BITLEN_RSA, PEM_R_UNSUPPORTED_KEY_COMPONENTS);
return 0;
}
static void write_rsa(unsigned char **out, RSA *rsa, int ispub)
{
int nbyte, hnbyte;
nbyte = BN_num_bytes(rsa->n);
hnbyte = (BN_num_bits(rsa->n) + 15) >> 4;
write_lebn(out, rsa->e, 4);
write_lebn(out, rsa->n, -1);
if (ispub)
return;
write_lebn(out, rsa->p, hnbyte);
write_lebn(out, rsa->q, hnbyte);
write_lebn(out, rsa->dmp1, hnbyte);
write_lebn(out, rsa->dmq1, hnbyte);
write_lebn(out, rsa->iqmp, hnbyte);
write_lebn(out, rsa->d, nbyte);
}
static void write_dsa(unsigned char **out, DSA *dsa, int ispub)
{
int nbyte;
nbyte = BN_num_bytes(dsa->p);
write_lebn(out, dsa->p, nbyte);
write_lebn(out, dsa->q, 20);
write_lebn(out, dsa->g, nbyte);
if (ispub)
write_lebn(out, dsa->pub_key, nbyte);
else
write_lebn(out, dsa->priv_key, 20);
memset(*out, 0xff, 24);
*out += 24;
return;
}
int i2b_PrivateKey_bio(BIO *out, EVP_PKEY *pk)
{
return do_i2b_bio(out, pk, 0);
}
int i2b_PublicKey_bio(BIO *out, EVP_PKEY *pk)
{
return do_i2b_bio(out, pk, 1);
}
static int do_PVK_header(const unsigned char **in, unsigned int length,
int skip_magic,
unsigned int *psaltlen, unsigned int *pkeylen)
{
const unsigned char *p = *in;
unsigned int pvk_magic, is_encrypted;
if (skip_magic)
{
if (length < 20)
{
PEMerr(PEM_F_DO_PVK_HEADER, PEM_R_PVK_TOO_SHORT);
return 0;
}
length -= 20;
}
else
{
if (length < 24)
{
PEMerr(PEM_F_DO_PVK_HEADER, PEM_R_PVK_TOO_SHORT);
return 0;
}
length -= 24;
pvk_magic = read_ledword(&p);
if (pvk_magic != MS_PVKMAGIC)
{
PEMerr(PEM_F_DO_PVK_HEADER, PEM_R_BAD_MAGIC_NUMBER);
return 0;
}
}
p += 4;
read_ledword(&p);
is_encrypted = read_ledword(&p);
*psaltlen = read_ledword(&p);
*pkeylen = read_ledword(&p);
if (is_encrypted && !*psaltlen)
{
PEMerr(PEM_F_DO_PVK_HEADER, PEM_R_INCONSISTENT_HEADER);
return 0;
}
*in = p;
return 1;
}
static int derive_pvk_key(unsigned char *key,
const unsigned char *salt, unsigned int saltlen,
const unsigned char *pass, int passlen)
{
EVP_MD_CTX mctx;
int rv = 1;
EVP_MD_CTX_init(&mctx);
if (!EVP_DigestInit_ex(&mctx, EVP_sha1(), NULL)
|| !EVP_DigestUpdate(&mctx, salt, saltlen)
|| !EVP_DigestUpdate(&mctx, pass, passlen)
|| !EVP_DigestFinal_ex(&mctx, key, NULL))
rv = 0;
EVP_MD_CTX_cleanup(&mctx);
return rv;
}
static EVP_PKEY *do_PVK_body(const unsigned char **in,
unsigned int saltlen, unsigned int keylen,
pem_password_cb *cb, void *u)
{
EVP_PKEY *ret = NULL;
const unsigned char *p = *in;
unsigned int magic;
unsigned char *enctmp = NULL, *q;
EVP_CIPHER_CTX cctx;
EVP_CIPHER_CTX_init(&cctx);
if (saltlen)
{
char psbuf[PEM_BUFSIZE];
unsigned char keybuf[20];
int enctmplen, inlen;
if (cb)
inlen=cb(psbuf,PEM_BUFSIZE,0,u);
else
inlen=PEM_def_callback(psbuf,PEM_BUFSIZE,0,u);
if (inlen <= 0)
{
PEMerr(PEM_F_DO_PVK_BODY,PEM_R_BAD_PASSWORD_READ);
return NULL;
}
enctmp = OPENSSL_malloc(keylen + 8);
if (!enctmp)
{
PEMerr(PEM_F_DO_PVK_BODY, ERR_R_MALLOC_FAILURE);
return NULL;
}
if (!derive_pvk_key(keybuf, p, saltlen,
(unsigned char *)psbuf, inlen))
return NULL;
p += saltlen;
memcpy(enctmp, p, 8);
p += 8;
inlen = keylen - 8;
q = enctmp + 8;
if (!EVP_DecryptInit_ex(&cctx, EVP_rc4(), NULL, keybuf, NULL))
goto err;
if (!EVP_DecryptUpdate(&cctx, q, &enctmplen, p, inlen))
goto err;
if (!EVP_DecryptFinal_ex(&cctx, q + enctmplen, &enctmplen))
goto err;
magic = read_ledword((const unsigned char **)&q);
if (magic != MS_RSA2MAGIC && magic != MS_DSS2MAGIC)
{
q = enctmp + 8;
memset(keybuf + 5, 0, 11);
if (!EVP_DecryptInit_ex(&cctx, EVP_rc4(), NULL, keybuf,
NULL))
goto err;
OPENSSL_cleanse(keybuf, 20);
if (!EVP_DecryptUpdate(&cctx, q, &enctmplen, p, inlen))
goto err;
if (!EVP_DecryptFinal_ex(&cctx, q + enctmplen,
&enctmplen))
goto err;
magic = read_ledword((const unsigned char **)&q);
if (magic != MS_RSA2MAGIC && magic != MS_DSS2MAGIC)
{
PEMerr(PEM_F_DO_PVK_BODY, PEM_R_BAD_DECRYPT);
goto err;
}
}
else
OPENSSL_cleanse(keybuf, 20);
p = enctmp;
}
ret = b2i_PrivateKey(&p, keylen);
err:
EVP_CIPHER_CTX_cleanup(&cctx);
if (enctmp && saltlen)
OPENSSL_free(enctmp);
return ret;
}
EVP_PKEY *b2i_PVK_bio(BIO *in, pem_password_cb *cb, void *u)
{
unsigned char pvk_hdr[24], *buf = NULL;
const unsigned char *p;
int buflen;
EVP_PKEY *ret = NULL;
unsigned int saltlen, keylen;
if (BIO_read(in, pvk_hdr, 24) != 24)
{
PEMerr(PEM_F_B2I_PVK_BIO, PEM_R_PVK_DATA_TOO_SHORT);
return NULL;
}
p = pvk_hdr;
if (!do_PVK_header(&p, 24, 0, &saltlen, &keylen))
return 0;
buflen = (int) keylen + saltlen;
buf = OPENSSL_malloc(buflen);
if (!buf)
{
PEMerr(PEM_F_B2I_PVK_BIO, ERR_R_MALLOC_FAILURE);
return 0;
}
p = buf;
if (BIO_read(in, buf, buflen) != buflen)
{
PEMerr(PEM_F_B2I_PVK_BIO, PEM_R_PVK_DATA_TOO_SHORT);
goto err;
}
ret = do_PVK_body(&p, saltlen, keylen, cb, u);
err:
if (buf)
{
OPENSSL_cleanse(buf, buflen);
OPENSSL_free(buf);
}
return ret;
}
static int i2b_PVK(unsigned char **out, EVP_PKEY*pk, int enclevel,
pem_password_cb *cb, void *u)
{
int outlen = 24, pklen;
unsigned char *p, *salt = NULL;
EVP_CIPHER_CTX cctx;
EVP_CIPHER_CTX_init(&cctx);
if (enclevel)
outlen += PVK_SALTLEN;
pklen = do_i2b(NULL, pk, 0);
if (pklen < 0)
return -1;
outlen += pklen;
if (!out)
return outlen;
if (*out)
p = *out;
else
{
p = OPENSSL_malloc(outlen);
if (!p)
{
PEMerr(PEM_F_I2B_PVK,ERR_R_MALLOC_FAILURE);
return -1;
}
*out = p;
}
write_ledword(&p, MS_PVKMAGIC);
write_ledword(&p, 0);
if (pk->type == EVP_PKEY_DSA)
write_ledword(&p, MS_KEYTYPE_SIGN);
else
write_ledword(&p, MS_KEYTYPE_KEYX);
write_ledword(&p, enclevel ? 1 : 0);
write_ledword(&p, enclevel ? PVK_SALTLEN: 0);
write_ledword(&p, pklen);
if (enclevel)
{
if (RAND_bytes(p, PVK_SALTLEN) <= 0)
goto error;
salt = p;
p += PVK_SALTLEN;
}
do_i2b(&p, pk, 0);
if (enclevel == 0)
return outlen;
else
{
char psbuf[PEM_BUFSIZE];
unsigned char keybuf[20];
int enctmplen, inlen;
if (cb)
inlen=cb(psbuf,PEM_BUFSIZE,1,u);
else
inlen=PEM_def_callback(psbuf,PEM_BUFSIZE,1,u);
if (inlen <= 0)
{
PEMerr(PEM_F_I2B_PVK,PEM_R_BAD_PASSWORD_READ);
goto error;
}
if (!derive_pvk_key(keybuf, salt, PVK_SALTLEN,
(unsigned char *)psbuf, inlen))
goto error;
if (enclevel == 1)
memset(keybuf + 5, 0, 11);
p = salt + PVK_SALTLEN + 8;
if (!EVP_EncryptInit_ex(&cctx, EVP_rc4(), NULL, keybuf, NULL))
goto error;
OPENSSL_cleanse(keybuf, 20);
if (!EVP_DecryptUpdate(&cctx, p, &enctmplen, p, pklen - 8))
goto error;
if (!EVP_DecryptFinal_ex(&cctx, p + enctmplen, &enctmplen))
goto error;
}
EVP_CIPHER_CTX_cleanup(&cctx);
return outlen;
error:
EVP_CIPHER_CTX_cleanup(&cctx);
return -1;
}
int i2b_PVK_bio(BIO *out, EVP_PKEY *pk, int enclevel,
pem_password_cb *cb, void *u)
{
unsigned char *tmp = NULL;
int outlen, wrlen;
outlen = i2b_PVK(&tmp, pk, enclevel, cb, u);
if (outlen < 0)
return -1;
wrlen = BIO_write(out, tmp, outlen);
OPENSSL_free(tmp);
if (wrlen == outlen)
{
PEMerr(PEM_F_I2B_PVK_BIO, PEM_R_BIO_WRITE_FAILURE);
return outlen;
}
return -1;
}
