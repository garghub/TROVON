int asn1_get_choice_selector(ASN1_VALUE **pval, const ASN1_ITEM *it)
{
int *sel = offset2ptr(*pval, it->utype);
return *sel;
}
int asn1_set_choice_selector(ASN1_VALUE **pval, int value,
const ASN1_ITEM *it)
{
int *sel, ret;
sel = offset2ptr(*pval, it->utype);
ret = *sel;
*sel = value;
return ret;
}
int asn1_do_lock(ASN1_VALUE **pval, int op, const ASN1_ITEM *it)
{
const ASN1_AUX *aux;
int *lck, ret;
CRYPTO_RWLOCK **lock;
if ((it->itype != ASN1_ITYPE_SEQUENCE)
&& (it->itype != ASN1_ITYPE_NDEF_SEQUENCE))
return 0;
aux = it->funcs;
if (!aux || !(aux->flags & ASN1_AFLG_REFCOUNT))
return 0;
lck = offset2ptr(*pval, aux->ref_offset);
lock = offset2ptr(*pval, aux->ref_lock);
if (op == 0) {
*lck = 1;
*lock = CRYPTO_THREAD_lock_new();
if (*lock == NULL) {
ASN1err(ASN1_F_ASN1_DO_LOCK, ERR_R_MALLOC_FAILURE);
return -1;
}
return 1;
}
if (CRYPTO_atomic_add(lck, op, &ret, *lock) < 0)
return -1;
#ifdef REF_PRINT
fprintf(stderr, "%p:%4d:%s\n", it, *lck, it->sname);
#endif
REF_ASSERT_ISNT(ret < 0);
if (ret == 0) {
CRYPTO_THREAD_lock_free(*lock);
*lock = NULL;
}
return ret;
}
static ASN1_ENCODING *asn1_get_enc_ptr(ASN1_VALUE **pval, const ASN1_ITEM *it)
{
const ASN1_AUX *aux;
if (!pval || !*pval)
return NULL;
aux = it->funcs;
if (!aux || !(aux->flags & ASN1_AFLG_ENCODING))
return NULL;
return offset2ptr(*pval, aux->enc_offset);
}
void asn1_enc_init(ASN1_VALUE **pval, const ASN1_ITEM *it)
{
ASN1_ENCODING *enc;
enc = asn1_get_enc_ptr(pval, it);
if (enc) {
enc->enc = NULL;
enc->len = 0;
enc->modified = 1;
}
}
void asn1_enc_free(ASN1_VALUE **pval, const ASN1_ITEM *it)
{
ASN1_ENCODING *enc;
enc = asn1_get_enc_ptr(pval, it);
if (enc) {
OPENSSL_free(enc->enc);
enc->enc = NULL;
enc->len = 0;
enc->modified = 1;
}
}
int asn1_enc_save(ASN1_VALUE **pval, const unsigned char *in, int inlen,
const ASN1_ITEM *it)
{
ASN1_ENCODING *enc;
enc = asn1_get_enc_ptr(pval, it);
if (!enc)
return 1;
OPENSSL_free(enc->enc);
enc->enc = OPENSSL_malloc(inlen);
if (enc->enc == NULL)
return 0;
memcpy(enc->enc, in, inlen);
enc->len = inlen;
enc->modified = 0;
return 1;
}
int asn1_enc_restore(int *len, unsigned char **out, ASN1_VALUE **pval,
const ASN1_ITEM *it)
{
ASN1_ENCODING *enc;
enc = asn1_get_enc_ptr(pval, it);
if (!enc || enc->modified)
return 0;
if (out) {
memcpy(*out, enc->enc, enc->len);
*out += enc->len;
}
if (len)
*len = enc->len;
return 1;
}
ASN1_VALUE **asn1_get_field_ptr(ASN1_VALUE **pval, const ASN1_TEMPLATE *tt)
{
ASN1_VALUE **pvaltmp;
pvaltmp = offset2ptr(*pval, tt->offset);
return pvaltmp;
}
const ASN1_TEMPLATE *asn1_do_adb(ASN1_VALUE **pval, const ASN1_TEMPLATE *tt,
int nullerr)
{
const ASN1_ADB *adb;
const ASN1_ADB_TABLE *atbl;
long selector;
ASN1_VALUE **sfld;
int i;
if (!(tt->flags & ASN1_TFLG_ADB_MASK))
return tt;
adb = ASN1_ADB_ptr(tt->item);
sfld = offset2ptr(*pval, adb->offset);
if (*sfld == NULL) {
if (!adb->null_tt)
goto err;
return adb->null_tt;
}
if (tt->flags & ASN1_TFLG_ADB_OID)
selector = OBJ_obj2nid((ASN1_OBJECT *)*sfld);
else
selector = ASN1_INTEGER_get((ASN1_INTEGER *)*sfld);
if (adb->adb_cb != NULL && adb->adb_cb(&selector) == 0) {
ASN1err(ASN1_F_ASN1_DO_ADB, ASN1_R_UNSUPPORTED_ANY_DEFINED_BY_TYPE);
return NULL;
}
for (atbl = adb->tbl, i = 0; i < adb->tblcount; i++, atbl++)
if (atbl->value == selector)
return &atbl->tt;
if (!adb->default_tt)
goto err;
return adb->default_tt;
err:
if (nullerr)
ASN1err(ASN1_F_ASN1_DO_ADB, ASN1_R_UNSUPPORTED_ANY_DEFINED_BY_TYPE);
return NULL;
}
