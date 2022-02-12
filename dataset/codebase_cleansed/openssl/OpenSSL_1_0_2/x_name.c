static int x509_name_ex_new(ASN1_VALUE **val, const ASN1_ITEM *it)
{
X509_NAME *ret = NULL;
ret = OPENSSL_malloc(sizeof(X509_NAME));
if (!ret)
goto memerr;
if ((ret->entries = sk_X509_NAME_ENTRY_new_null()) == NULL)
goto memerr;
if ((ret->bytes = BUF_MEM_new()) == NULL)
goto memerr;
ret->canon_enc = NULL;
ret->canon_enclen = 0;
ret->modified = 1;
*val = (ASN1_VALUE *)ret;
return 1;
memerr:
ASN1err(ASN1_F_X509_NAME_EX_NEW, ERR_R_MALLOC_FAILURE);
if (ret) {
if (ret->entries)
sk_X509_NAME_ENTRY_free(ret->entries);
OPENSSL_free(ret);
}
return 0;
}
static void x509_name_ex_free(ASN1_VALUE **pval, const ASN1_ITEM *it)
{
X509_NAME *a;
if (!pval || !*pval)
return;
a = (X509_NAME *)*pval;
BUF_MEM_free(a->bytes);
sk_X509_NAME_ENTRY_pop_free(a->entries, X509_NAME_ENTRY_free);
if (a->canon_enc)
OPENSSL_free(a->canon_enc);
OPENSSL_free(a);
*pval = NULL;
}
static int x509_name_ex_d2i(ASN1_VALUE **val,
const unsigned char **in, long len,
const ASN1_ITEM *it, int tag, int aclass,
char opt, ASN1_TLC *ctx)
{
const unsigned char *p = *in, *q;
union {
STACK_OF(STACK_OF_X509_NAME_ENTRY) *s;
ASN1_VALUE *a;
} intname = {
NULL
};
union {
X509_NAME *x;
ASN1_VALUE *a;
} nm = {
NULL
};
int i, j, ret;
STACK_OF(X509_NAME_ENTRY) *entries;
X509_NAME_ENTRY *entry;
q = p;
ret = ASN1_item_ex_d2i(&intname.a,
&p, len, ASN1_ITEM_rptr(X509_NAME_INTERNAL),
tag, aclass, opt, ctx);
if (ret <= 0)
return ret;
if (*val)
x509_name_ex_free(val, NULL);
if (!x509_name_ex_new(&nm.a, NULL))
goto err;
if (!BUF_MEM_grow(nm.x->bytes, p - q))
goto err;
memcpy(nm.x->bytes->data, q, p - q);
for (i = 0; i < sk_STACK_OF_X509_NAME_ENTRY_num(intname.s); i++) {
entries = sk_STACK_OF_X509_NAME_ENTRY_value(intname.s, i);
for (j = 0; j < sk_X509_NAME_ENTRY_num(entries); j++) {
entry = sk_X509_NAME_ENTRY_value(entries, j);
entry->set = i;
if (!sk_X509_NAME_ENTRY_push(nm.x->entries, entry))
goto err;
}
sk_X509_NAME_ENTRY_free(entries);
}
sk_STACK_OF_X509_NAME_ENTRY_free(intname.s);
ret = x509_name_canon(nm.x);
if (!ret)
goto err;
nm.x->modified = 0;
*val = nm.a;
*in = p;
return ret;
err:
if (nm.x != NULL)
X509_NAME_free(nm.x);
ASN1err(ASN1_F_X509_NAME_EX_D2I, ERR_R_NESTED_ASN1_ERROR);
return 0;
}
static int x509_name_ex_i2d(ASN1_VALUE **val, unsigned char **out,
const ASN1_ITEM *it, int tag, int aclass)
{
int ret;
X509_NAME *a = (X509_NAME *)*val;
if (a->modified) {
ret = x509_name_encode(a);
if (ret < 0)
return ret;
ret = x509_name_canon(a);
if (ret < 0)
return ret;
}
ret = a->bytes->length;
if (out != NULL) {
memcpy(*out, a->bytes->data, ret);
*out += ret;
}
return ret;
}
static int x509_name_encode(X509_NAME *a)
{
union {
STACK_OF(STACK_OF_X509_NAME_ENTRY) *s;
ASN1_VALUE *a;
} intname = {
NULL
};
int len;
unsigned char *p;
STACK_OF(X509_NAME_ENTRY) *entries = NULL;
X509_NAME_ENTRY *entry;
int i, set = -1;
intname.s = sk_STACK_OF_X509_NAME_ENTRY_new_null();
if (!intname.s)
goto memerr;
for (i = 0; i < sk_X509_NAME_ENTRY_num(a->entries); i++) {
entry = sk_X509_NAME_ENTRY_value(a->entries, i);
if (entry->set != set) {
entries = sk_X509_NAME_ENTRY_new_null();
if (!entries)
goto memerr;
if (!sk_STACK_OF_X509_NAME_ENTRY_push(intname.s, entries))
goto memerr;
set = entry->set;
}
if (!sk_X509_NAME_ENTRY_push(entries, entry))
goto memerr;
}
len = ASN1_item_ex_i2d(&intname.a, NULL,
ASN1_ITEM_rptr(X509_NAME_INTERNAL), -1, -1);
if (!BUF_MEM_grow(a->bytes, len))
goto memerr;
p = (unsigned char *)a->bytes->data;
ASN1_item_ex_i2d(&intname.a,
&p, ASN1_ITEM_rptr(X509_NAME_INTERNAL), -1, -1);
sk_STACK_OF_X509_NAME_ENTRY_pop_free(intname.s,
local_sk_X509_NAME_ENTRY_free);
a->modified = 0;
return len;
memerr:
sk_STACK_OF_X509_NAME_ENTRY_pop_free(intname.s,
local_sk_X509_NAME_ENTRY_free);
ASN1err(ASN1_F_X509_NAME_ENCODE, ERR_R_MALLOC_FAILURE);
return -1;
}
static int x509_name_ex_print(BIO *out, ASN1_VALUE **pval,
int indent,
const char *fname, const ASN1_PCTX *pctx)
{
if (X509_NAME_print_ex(out, (X509_NAME *)*pval,
indent, pctx->nm_flags) <= 0)
return 0;
return 2;
}
static int x509_name_canon(X509_NAME *a)
{
unsigned char *p;
STACK_OF(STACK_OF_X509_NAME_ENTRY) *intname = NULL;
STACK_OF(X509_NAME_ENTRY) *entries = NULL;
X509_NAME_ENTRY *entry, *tmpentry = NULL;
int i, set = -1, ret = 0;
if (a->canon_enc) {
OPENSSL_free(a->canon_enc);
a->canon_enc = NULL;
}
if (sk_X509_NAME_ENTRY_num(a->entries) == 0) {
a->canon_enclen = 0;
return 1;
}
intname = sk_STACK_OF_X509_NAME_ENTRY_new_null();
if (!intname)
goto err;
for (i = 0; i < sk_X509_NAME_ENTRY_num(a->entries); i++) {
entry = sk_X509_NAME_ENTRY_value(a->entries, i);
if (entry->set != set) {
entries = sk_X509_NAME_ENTRY_new_null();
if (!entries)
goto err;
if (!sk_STACK_OF_X509_NAME_ENTRY_push(intname, entries))
goto err;
set = entry->set;
}
tmpentry = X509_NAME_ENTRY_new();
if (!tmpentry)
goto err;
tmpentry->object = OBJ_dup(entry->object);
if (!asn1_string_canon(tmpentry->value, entry->value))
goto err;
if (!sk_X509_NAME_ENTRY_push(entries, tmpentry))
goto err;
tmpentry = NULL;
}
a->canon_enclen = i2d_name_canon(intname, NULL);
p = OPENSSL_malloc(a->canon_enclen);
if (!p)
goto err;
a->canon_enc = p;
i2d_name_canon(intname, &p);
ret = 1;
err:
if (tmpentry)
X509_NAME_ENTRY_free(tmpentry);
if (intname)
sk_STACK_OF_X509_NAME_ENTRY_pop_free(intname,
local_sk_X509_NAME_ENTRY_pop_free);
return ret;
}
static int asn1_string_canon(ASN1_STRING *out, ASN1_STRING *in)
{
unsigned char *to, *from;
int len, i;
if (!(ASN1_tag2bit(in->type) & ASN1_MASK_CANON)) {
if (!ASN1_STRING_copy(out, in))
return 0;
return 1;
}
out->type = V_ASN1_UTF8STRING;
out->length = ASN1_STRING_to_UTF8(&out->data, in);
if (out->length == -1)
return 0;
to = out->data;
from = to;
len = out->length;
while ((len > 0) && !(*from & 0x80) && isspace(*from)) {
from++;
len--;
}
to = from + len - 1;
while ((len > 0) && !(*to & 0x80) && isspace(*to)) {
to--;
len--;
}
to = out->data;
i = 0;
while (i < len) {
if (*from & 0x80) {
*to++ = *from++;
i++;
}
else if (isspace(*from)) {
*to++ = ' ';
do {
from++;
i++;
}
while (!(*from & 0x80) && isspace(*from));
} else {
*to++ = tolower(*from);
from++;
i++;
}
}
out->length = to - out->data;
return 1;
}
int X509_NAME_set(X509_NAME **xn, X509_NAME *name)
{
X509_NAME *in;
if (!xn || !name)
return (0);
if (*xn != name) {
in = X509_NAME_dup(name);
if (in != NULL) {
X509_NAME_free(*xn);
*xn = in;
}
}
return (*xn != NULL);
}
