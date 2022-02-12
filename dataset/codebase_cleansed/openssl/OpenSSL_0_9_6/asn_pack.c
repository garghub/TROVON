STACK *ASN1_seq_unpack(unsigned char *buf, int len, char *(*d2i)(),
void (*free_func)(void *))
{
STACK *sk;
unsigned char *pbuf;
pbuf = buf;
if (!(sk = d2i_ASN1_SET(NULL, &pbuf, len, d2i, free_func,
V_ASN1_SEQUENCE, V_ASN1_UNIVERSAL)))
ASN1err(ASN1_F_ASN1_SEQ_UNPACK,ASN1_R_DECODE_ERROR);
return sk;
}
unsigned char *ASN1_seq_pack(STACK *safes, int (*i2d)(), unsigned char **buf,
int *len)
{
int safelen;
unsigned char *safe, *p;
if (!(safelen = i2d_ASN1_SET(safes, NULL, i2d, V_ASN1_SEQUENCE,
V_ASN1_UNIVERSAL, IS_SEQUENCE))) {
ASN1err(ASN1_F_ASN1_SEQ_PACK,ASN1_R_ENCODE_ERROR);
return NULL;
}
if (!(safe = OPENSSL_malloc (safelen))) {
ASN1err(ASN1_F_ASN1_SEQ_PACK,ERR_R_MALLOC_FAILURE);
return NULL;
}
p = safe;
i2d_ASN1_SET(safes, &p, i2d, V_ASN1_SEQUENCE, V_ASN1_UNIVERSAL,
IS_SEQUENCE);
if (len) *len = safelen;
if (buf) *buf = safe;
return safe;
}
void *ASN1_unpack_string (ASN1_STRING *oct, char *(*d2i)())
{
unsigned char *p;
char *ret;
p = oct->data;
if(!(ret = d2i(NULL, &p, oct->length)))
ASN1err(ASN1_F_ASN1_UNPACK_STRING,ASN1_R_DECODE_ERROR);
return ret;
}
ASN1_STRING *ASN1_pack_string (void *obj, int (*i2d)(), ASN1_STRING **oct)
{
unsigned char *p;
ASN1_STRING *octmp;
if (!oct || !*oct) {
if (!(octmp = ASN1_STRING_new ())) {
ASN1err(ASN1_F_ASN1_PACK_STRING,ERR_R_MALLOC_FAILURE);
return NULL;
}
if (oct) *oct = octmp;
} else octmp = *oct;
if (!(octmp->length = i2d(obj, NULL))) {
ASN1err(ASN1_F_ASN1_PACK_STRING,ASN1_R_ENCODE_ERROR);
return NULL;
}
if (!(p = OPENSSL_malloc (octmp->length))) {
ASN1err(ASN1_F_ASN1_PACK_STRING,ERR_R_MALLOC_FAILURE);
return NULL;
}
octmp->data = p;
i2d (obj, &p);
return octmp;
}
