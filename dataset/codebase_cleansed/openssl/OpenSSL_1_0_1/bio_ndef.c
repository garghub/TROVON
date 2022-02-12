BIO *BIO_new_NDEF(BIO *out, ASN1_VALUE *val, const ASN1_ITEM *it)
{
NDEF_SUPPORT *ndef_aux = NULL;
BIO *asn_bio = NULL;
const ASN1_AUX *aux = it->funcs;
ASN1_STREAM_ARG sarg;
if (!aux || !aux->asn1_cb)
{
ASN1err(ASN1_F_BIO_NEW_NDEF, ASN1_R_STREAMING_NOT_SUPPORTED);
return NULL;
}
ndef_aux = OPENSSL_malloc(sizeof(NDEF_SUPPORT));
asn_bio = BIO_new(BIO_f_asn1());
out = BIO_push(asn_bio, out);
if (!ndef_aux || !asn_bio || !out)
goto err;
BIO_asn1_set_prefix(asn_bio, ndef_prefix, ndef_prefix_free);
BIO_asn1_set_suffix(asn_bio, ndef_suffix, ndef_suffix_free);
sarg.out = out;
sarg.ndef_bio = NULL;
sarg.boundary = NULL;
if (aux->asn1_cb(ASN1_OP_STREAM_PRE, &val, it, &sarg) <= 0)
goto err;
ndef_aux->val = val;
ndef_aux->it = it;
ndef_aux->ndef_bio = sarg.ndef_bio;
ndef_aux->boundary = sarg.boundary;
ndef_aux->out = out;
BIO_ctrl(asn_bio, BIO_C_SET_EX_ARG, 0, ndef_aux);
return sarg.ndef_bio;
err:
if (asn_bio)
BIO_free(asn_bio);
if (ndef_aux)
OPENSSL_free(ndef_aux);
return NULL;
}
static int ndef_prefix(BIO *b, unsigned char **pbuf, int *plen, void *parg)
{
NDEF_SUPPORT *ndef_aux;
unsigned char *p;
int derlen;
if (!parg)
return 0;
ndef_aux = *(NDEF_SUPPORT **)parg;
derlen = ASN1_item_ndef_i2d(ndef_aux->val, NULL, ndef_aux->it);
p = OPENSSL_malloc(derlen);
ndef_aux->derbuf = p;
*pbuf = p;
derlen = ASN1_item_ndef_i2d(ndef_aux->val, &p, ndef_aux->it);
if (!*ndef_aux->boundary)
return 0;
*plen = *ndef_aux->boundary - *pbuf;
return 1;
}
static int ndef_prefix_free(BIO *b, unsigned char **pbuf, int *plen, void *parg)
{
NDEF_SUPPORT *ndef_aux;
if (!parg)
return 0;
ndef_aux = *(NDEF_SUPPORT **)parg;
if (ndef_aux->derbuf)
OPENSSL_free(ndef_aux->derbuf);
ndef_aux->derbuf = NULL;
*pbuf = NULL;
*plen = 0;
return 1;
}
static int ndef_suffix_free(BIO *b, unsigned char **pbuf, int *plen, void *parg)
{
NDEF_SUPPORT **pndef_aux = (NDEF_SUPPORT **)parg;
if (!ndef_prefix_free(b, pbuf, plen, parg))
return 0;
OPENSSL_free(*pndef_aux);
*pndef_aux = NULL;
return 1;
}
static int ndef_suffix(BIO *b, unsigned char **pbuf, int *plen, void *parg)
{
NDEF_SUPPORT *ndef_aux;
unsigned char *p;
int derlen;
const ASN1_AUX *aux;
ASN1_STREAM_ARG sarg;
if (!parg)
return 0;
ndef_aux = *(NDEF_SUPPORT **)parg;
aux = ndef_aux->it->funcs;
sarg.ndef_bio = ndef_aux->ndef_bio;
sarg.out = ndef_aux->out;
sarg.boundary = ndef_aux->boundary;
if (aux->asn1_cb(ASN1_OP_STREAM_POST,
&ndef_aux->val, ndef_aux->it, &sarg) <= 0)
return 0;
derlen = ASN1_item_ndef_i2d(ndef_aux->val, NULL, ndef_aux->it);
p = OPENSSL_malloc(derlen);
ndef_aux->derbuf = p;
*pbuf = p;
derlen = ASN1_item_ndef_i2d(ndef_aux->val, &p, ndef_aux->it);
if (!*ndef_aux->boundary)
return 0;
*pbuf = *ndef_aux->boundary;
*plen = derlen - (*ndef_aux->boundary - ndef_aux->derbuf);
return 1;
}
