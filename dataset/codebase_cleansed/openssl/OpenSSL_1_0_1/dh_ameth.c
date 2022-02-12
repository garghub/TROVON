static void int_dh_free(EVP_PKEY *pkey)
{
DH_free(pkey->pkey.dh);
}
static int dh_pub_decode(EVP_PKEY *pkey, X509_PUBKEY *pubkey)
{
const unsigned char *p, *pm;
int pklen, pmlen;
int ptype;
void *pval;
ASN1_STRING *pstr;
X509_ALGOR *palg;
ASN1_INTEGER *public_key = NULL;
DH *dh = NULL;
if (!X509_PUBKEY_get0_param(NULL, &p, &pklen, &palg, pubkey))
return 0;
X509_ALGOR_get0(NULL, &ptype, &pval, palg);
if (ptype != V_ASN1_SEQUENCE)
{
DHerr(DH_F_DH_PUB_DECODE, DH_R_PARAMETER_ENCODING_ERROR);
goto err;
}
pstr = pval;
pm = pstr->data;
pmlen = pstr->length;
if (!(dh = d2i_DHparams(NULL, &pm, pmlen)))
{
DHerr(DH_F_DH_PUB_DECODE, DH_R_DECODE_ERROR);
goto err;
}
if (!(public_key=d2i_ASN1_INTEGER(NULL, &p, pklen)))
{
DHerr(DH_F_DH_PUB_DECODE, DH_R_DECODE_ERROR);
goto err;
}
if (!(dh->pub_key = ASN1_INTEGER_to_BN(public_key, NULL)))
{
DHerr(DH_F_DH_PUB_DECODE, DH_R_BN_DECODE_ERROR);
goto err;
}
ASN1_INTEGER_free(public_key);
EVP_PKEY_assign_DH(pkey, dh);
return 1;
err:
if (public_key)
ASN1_INTEGER_free(public_key);
if (dh)
DH_free(dh);
return 0;
}
static int dh_pub_encode(X509_PUBKEY *pk, const EVP_PKEY *pkey)
{
DH *dh;
void *pval = NULL;
int ptype;
unsigned char *penc = NULL;
int penclen;
ASN1_STRING *str;
ASN1_INTEGER *pub_key = NULL;
dh=pkey->pkey.dh;
str = ASN1_STRING_new();
str->length = i2d_DHparams(dh, &str->data);
if (str->length <= 0)
{
DHerr(DH_F_DH_PUB_ENCODE, ERR_R_MALLOC_FAILURE);
goto err;
}
pval = str;
ptype = V_ASN1_SEQUENCE;
pub_key = BN_to_ASN1_INTEGER(dh->pub_key, NULL);
if (!pub_key)
goto err;
penclen = i2d_ASN1_INTEGER(pub_key, &penc);
ASN1_INTEGER_free(pub_key);
if (penclen <= 0)
{
DHerr(DH_F_DH_PUB_ENCODE, ERR_R_MALLOC_FAILURE);
goto err;
}
if (X509_PUBKEY_set0_param(pk, OBJ_nid2obj(EVP_PKEY_DH),
ptype, pval, penc, penclen))
return 1;
err:
if (penc)
OPENSSL_free(penc);
if (pval)
ASN1_STRING_free(pval);
return 0;
}
static int dh_priv_decode(EVP_PKEY *pkey, PKCS8_PRIV_KEY_INFO *p8)
{
const unsigned char *p, *pm;
int pklen, pmlen;
int ptype;
void *pval;
ASN1_STRING *pstr;
X509_ALGOR *palg;
ASN1_INTEGER *privkey = NULL;
DH *dh = NULL;
if (!PKCS8_pkey_get0(NULL, &p, &pklen, &palg, p8))
return 0;
X509_ALGOR_get0(NULL, &ptype, &pval, palg);
if (ptype != V_ASN1_SEQUENCE)
goto decerr;
if (!(privkey=d2i_ASN1_INTEGER(NULL, &p, pklen)))
goto decerr;
pstr = pval;
pm = pstr->data;
pmlen = pstr->length;
if (!(dh = d2i_DHparams(NULL, &pm, pmlen)))
goto decerr;
if (!(dh->priv_key = ASN1_INTEGER_to_BN(privkey, NULL)))
{
DHerr(DH_F_DH_PRIV_DECODE,DH_R_BN_ERROR);
goto dherr;
}
if (!DH_generate_key(dh))
goto dherr;
EVP_PKEY_assign_DH(pkey, dh);
ASN1_INTEGER_free(privkey);
return 1;
decerr:
DHerr(DH_F_DH_PRIV_DECODE, EVP_R_DECODE_ERROR);
dherr:
DH_free(dh);
return 0;
}
static int dh_priv_encode(PKCS8_PRIV_KEY_INFO *p8, const EVP_PKEY *pkey)
{
ASN1_STRING *params = NULL;
ASN1_INTEGER *prkey = NULL;
unsigned char *dp = NULL;
int dplen;
params = ASN1_STRING_new();
if (!params)
{
DHerr(DH_F_DH_PRIV_ENCODE,ERR_R_MALLOC_FAILURE);
goto err;
}
params->length = i2d_DHparams(pkey->pkey.dh, &params->data);
if (params->length <= 0)
{
DHerr(DH_F_DH_PRIV_ENCODE,ERR_R_MALLOC_FAILURE);
goto err;
}
params->type = V_ASN1_SEQUENCE;
prkey = BN_to_ASN1_INTEGER(pkey->pkey.dh->priv_key, NULL);
if (!prkey)
{
DHerr(DH_F_DH_PRIV_ENCODE,DH_R_BN_ERROR);
goto err;
}
dplen = i2d_ASN1_INTEGER(prkey, &dp);
ASN1_INTEGER_free(prkey);
if (!PKCS8_pkey_set0(p8, OBJ_nid2obj(NID_dhKeyAgreement), 0,
V_ASN1_SEQUENCE, params, dp, dplen))
goto err;
return 1;
err:
if (dp != NULL)
OPENSSL_free(dp);
if (params != NULL)
ASN1_STRING_free(params);
if (prkey != NULL)
ASN1_INTEGER_free(prkey);
return 0;
}
static void update_buflen(const BIGNUM *b, size_t *pbuflen)
{
size_t i;
if (!b)
return;
if (*pbuflen < (i = (size_t)BN_num_bytes(b)))
*pbuflen = i;
}
static int dh_param_decode(EVP_PKEY *pkey,
const unsigned char **pder, int derlen)
{
DH *dh;
if (!(dh = d2i_DHparams(NULL, pder, derlen)))
{
DHerr(DH_F_DH_PARAM_DECODE, ERR_R_DH_LIB);
return 0;
}
EVP_PKEY_assign_DH(pkey, dh);
return 1;
}
static int dh_param_encode(const EVP_PKEY *pkey, unsigned char **pder)
{
return i2d_DHparams(pkey->pkey.dh, pder);
}
static int do_dh_print(BIO *bp, const DH *x, int indent,
ASN1_PCTX *ctx, int ptype)
{
unsigned char *m=NULL;
int reason=ERR_R_BUF_LIB,ret=0;
size_t buf_len=0;
const char *ktype = NULL;
BIGNUM *priv_key, *pub_key;
if (ptype == 2)
priv_key = x->priv_key;
else
priv_key = NULL;
if (ptype > 0)
pub_key = x->pub_key;
else
pub_key = NULL;
update_buflen(x->p, &buf_len);
if (buf_len == 0)
{
reason = ERR_R_PASSED_NULL_PARAMETER;
goto err;
}
update_buflen(x->g, &buf_len);
update_buflen(pub_key, &buf_len);
update_buflen(priv_key, &buf_len);
if (ptype == 2)
ktype = "PKCS#3 DH Private-Key";
else if (ptype == 1)
ktype = "PKCS#3 DH Public-Key";
else
ktype = "PKCS#3 DH Parameters";
m= OPENSSL_malloc(buf_len+10);
if (m == NULL)
{
reason=ERR_R_MALLOC_FAILURE;
goto err;
}
BIO_indent(bp, indent, 128);
if (BIO_printf(bp,"%s: (%d bit)\n", ktype, BN_num_bits(x->p)) <= 0)
goto err;
indent += 4;
if (!ASN1_bn_print(bp,"private-key:",priv_key,m,indent)) goto err;
if (!ASN1_bn_print(bp,"public-key:",pub_key,m,indent)) goto err;
if (!ASN1_bn_print(bp,"prime:",x->p,m,indent)) goto err;
if (!ASN1_bn_print(bp,"generator:",x->g,m,indent)) goto err;
if (x->length != 0)
{
BIO_indent(bp, indent, 128);
if (BIO_printf(bp,"recommended-private-length: %d bits\n",
(int)x->length) <= 0) goto err;
}
ret=1;
if (0)
{
err:
DHerr(DH_F_DO_DH_PRINT,reason);
}
if (m != NULL) OPENSSL_free(m);
return(ret);
}
static int int_dh_size(const EVP_PKEY *pkey)
{
return(DH_size(pkey->pkey.dh));
}
static int dh_bits(const EVP_PKEY *pkey)
{
return BN_num_bits(pkey->pkey.dh->p);
}
static int dh_cmp_parameters(const EVP_PKEY *a, const EVP_PKEY *b)
{
if ( BN_cmp(a->pkey.dh->p,b->pkey.dh->p) ||
BN_cmp(a->pkey.dh->g,b->pkey.dh->g))
return 0;
else
return 1;
}
static int dh_copy_parameters(EVP_PKEY *to, const EVP_PKEY *from)
{
BIGNUM *a;
if ((a=BN_dup(from->pkey.dh->p)) == NULL)
return 0;
if (to->pkey.dh->p != NULL)
BN_free(to->pkey.dh->p);
to->pkey.dh->p=a;
if ((a=BN_dup(from->pkey.dh->g)) == NULL)
return 0;
if (to->pkey.dh->g != NULL)
BN_free(to->pkey.dh->g);
to->pkey.dh->g=a;
return 1;
}
static int dh_missing_parameters(const EVP_PKEY *a)
{
if (!a->pkey.dh->p || !a->pkey.dh->g)
return 1;
return 0;
}
static int dh_pub_cmp(const EVP_PKEY *a, const EVP_PKEY *b)
{
if (dh_cmp_parameters(a, b) == 0)
return 0;
if (BN_cmp(b->pkey.dh->pub_key,a->pkey.dh->pub_key) != 0)
return 0;
else
return 1;
}
static int dh_param_print(BIO *bp, const EVP_PKEY *pkey, int indent,
ASN1_PCTX *ctx)
{
return do_dh_print(bp, pkey->pkey.dh, indent, ctx, 0);
}
static int dh_public_print(BIO *bp, const EVP_PKEY *pkey, int indent,
ASN1_PCTX *ctx)
{
return do_dh_print(bp, pkey->pkey.dh, indent, ctx, 1);
}
static int dh_private_print(BIO *bp, const EVP_PKEY *pkey, int indent,
ASN1_PCTX *ctx)
{
return do_dh_print(bp, pkey->pkey.dh, indent, ctx, 2);
}
int DHparams_print(BIO *bp, const DH *x)
{
return do_dh_print(bp, x, 4, NULL, 0);
}
