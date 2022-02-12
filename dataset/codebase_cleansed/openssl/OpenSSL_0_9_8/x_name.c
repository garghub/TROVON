static int x509_name_ex_new(ASN1_VALUE **val, const ASN1_ITEM *it)
{
X509_NAME *ret = NULL;
ret = OPENSSL_malloc(sizeof(X509_NAME));
if(!ret) goto memerr;
if ((ret->entries=sk_X509_NAME_ENTRY_new_null()) == NULL)
goto memerr;
if((ret->bytes = BUF_MEM_new()) == NULL) goto memerr;
ret->modified=1;
*val = (ASN1_VALUE *)ret;
return 1;
memerr:
ASN1err(ASN1_F_X509_NAME_EX_NEW, ERR_R_MALLOC_FAILURE);
if (ret)
{
if (ret->entries)
sk_X509_NAME_ENTRY_free(ret->entries);
OPENSSL_free(ret);
}
return 0;
}
static void x509_name_ex_free(ASN1_VALUE **pval, const ASN1_ITEM *it)
{
X509_NAME *a;
if(!pval || !*pval)
return;
a = (X509_NAME *)*pval;
BUF_MEM_free(a->bytes);
sk_X509_NAME_ENTRY_pop_free(a->entries,X509_NAME_ENTRY_free);
OPENSSL_free(a);
*pval = NULL;
}
static void sk_internal_free(void *a)
{
sk_free(a);
}
static int x509_name_ex_d2i(ASN1_VALUE **val, const unsigned char **in, long len, const ASN1_ITEM *it,
int tag, int aclass, char opt, ASN1_TLC *ctx)
{
const unsigned char *p = *in, *q;
STACK *intname = NULL, **intname_pp = &intname;
int i, j, ret;
X509_NAME *nm = NULL, **nm_pp = &nm;
STACK_OF(X509_NAME_ENTRY) *entries;
X509_NAME_ENTRY *entry;
q = p;
ret = ASN1_item_ex_d2i((ASN1_VALUE **)intname_pp,
&p, len, ASN1_ITEM_rptr(X509_NAME_INTERNAL),
tag, aclass, opt, ctx);
if(ret <= 0) return ret;
if(*val) x509_name_ex_free(val, NULL);
if(!x509_name_ex_new((ASN1_VALUE **)nm_pp, NULL)) goto err;
if(!BUF_MEM_grow(nm->bytes, p - q)) goto err;
memcpy(nm->bytes->data, q, p - q);
for(i = 0; i < sk_num(intname); i++) {
entries = (STACK_OF(X509_NAME_ENTRY) *)sk_value(intname, i);
for(j = 0; j < sk_X509_NAME_ENTRY_num(entries); j++) {
entry = sk_X509_NAME_ENTRY_value(entries, j);
entry->set = i;
if(!sk_X509_NAME_ENTRY_push(nm->entries, entry))
goto err;
}
sk_X509_NAME_ENTRY_free(entries);
}
sk_free(intname);
nm->modified = 0;
*val = (ASN1_VALUE *)nm;
*in = p;
return ret;
err:
ASN1err(ASN1_F_X509_NAME_EX_D2I, ERR_R_NESTED_ASN1_ERROR);
return 0;
}
static int x509_name_ex_i2d(ASN1_VALUE **val, unsigned char **out, const ASN1_ITEM *it, int tag, int aclass)
{
int ret;
X509_NAME *a = (X509_NAME *)*val;
if(a->modified) {
ret = x509_name_encode((X509_NAME *)a);
if(ret < 0) return ret;
}
ret = a->bytes->length;
if(out != NULL) {
memcpy(*out,a->bytes->data,ret);
*out+=ret;
}
return ret;
}
static int x509_name_encode(X509_NAME *a)
{
STACK *intname = NULL, **intname_pp = &intname;
int len;
unsigned char *p;
STACK_OF(X509_NAME_ENTRY) *entries = NULL;
X509_NAME_ENTRY *entry;
int i, set = -1;
intname = sk_new_null();
if(!intname) goto memerr;
for(i = 0; i < sk_X509_NAME_ENTRY_num(a->entries); i++) {
entry = sk_X509_NAME_ENTRY_value(a->entries, i);
if(entry->set != set) {
entries = sk_X509_NAME_ENTRY_new_null();
if(!entries) goto memerr;
if(!sk_push(intname, (char *)entries)) goto memerr;
set = entry->set;
}
if(!sk_X509_NAME_ENTRY_push(entries, entry)) goto memerr;
}
len = ASN1_item_ex_i2d((ASN1_VALUE **)intname_pp, NULL,
ASN1_ITEM_rptr(X509_NAME_INTERNAL), -1, -1);
if (!BUF_MEM_grow(a->bytes,len)) goto memerr;
p=(unsigned char *)a->bytes->data;
ASN1_item_ex_i2d((ASN1_VALUE **)intname_pp,
&p, ASN1_ITEM_rptr(X509_NAME_INTERNAL), -1, -1);
sk_pop_free(intname, sk_internal_free);
a->modified = 0;
return len;
memerr:
sk_pop_free(intname, sk_internal_free);
ASN1err(ASN1_F_X509_NAME_ENCODE, ERR_R_MALLOC_FAILURE);
return -1;
}
int X509_NAME_set(X509_NAME **xn, X509_NAME *name)
{
X509_NAME *in;
if (!xn || !name) return(0);
if (*xn != name)
{
in=X509_NAME_dup(name);
if (in != NULL)
{
X509_NAME_free(*xn);
*xn=in;
}
}
return(*xn != NULL);
}
