void X509V3_conf_free(CONF_VALUE *conf)
{
if(!conf) return;
if(conf->name) OPENSSL_free(conf->name);
if(conf->value) OPENSSL_free(conf->value);
if(conf->section) OPENSSL_free(conf->section);
OPENSSL_free(conf);
}
char *i2s_ASN1_ENUMERATED(X509V3_EXT_METHOD *method, ASN1_ENUMERATED *a)
{
BIGNUM *bntmp = NULL;
char *strtmp = NULL;
if(!a) return NULL;
if(!(bntmp = ASN1_ENUMERATED_to_BN(a, NULL)) ||
!(strtmp = BN_bn2dec(bntmp)) )
X509V3err(X509V3_F_I2S_ASN1_ENUMERATED,ERR_R_MALLOC_FAILURE);
BN_free(bntmp);
return strtmp;
}
char *i2s_ASN1_INTEGER(X509V3_EXT_METHOD *method, ASN1_INTEGER *a)
{
BIGNUM *bntmp = NULL;
char *strtmp = NULL;
if(!a) return NULL;
if(!(bntmp = ASN1_INTEGER_to_BN(a, NULL)) ||
!(strtmp = BN_bn2dec(bntmp)) )
X509V3err(X509V3_F_I2S_ASN1_INTEGER,ERR_R_MALLOC_FAILURE);
BN_free(bntmp);
return strtmp;
}
ASN1_INTEGER *s2i_ASN1_INTEGER(X509V3_EXT_METHOD *method, char *value)
{
BIGNUM *bn = NULL;
ASN1_INTEGER *aint;
int isneg, ishex;
int ret;
bn = BN_new();
if (!value) {
X509V3err(X509V3_F_S2I_ASN1_INTEGER,X509V3_R_INVALID_NULL_VALUE);
return 0;
}
if (value[0] == '-') {
value++;
isneg = 1;
} else isneg = 0;
if (value[0] == '0' && ((value[1] == 'x') || (value[1] == 'X'))) {
value += 2;
ishex = 1;
} else ishex = 0;
if (ishex) ret = BN_hex2bn(&bn, value);
else ret = BN_dec2bn(&bn, value);
if (!ret) {
X509V3err(X509V3_F_S2I_ASN1_INTEGER,X509V3_R_BN_DEC2BN_ERROR);
return 0;
}
if (isneg && BN_is_zero(bn)) isneg = 0;
aint = BN_to_ASN1_INTEGER(bn, NULL);
BN_free(bn);
if (!aint) {
X509V3err(X509V3_F_S2I_ASN1_INTEGER,X509V3_R_BN_TO_ASN1_INTEGER_ERROR);
return 0;
}
if (isneg) aint->type |= V_ASN1_NEG;
return aint;
}
int X509V3_get_value_bool(CONF_VALUE *value, int *asn1_bool)
{
char *btmp;
if(!(btmp = value->value)) goto err;
if(!strcmp(btmp, "TRUE") || !strcmp(btmp, "true")
|| !strcmp(btmp, "Y") || !strcmp(btmp, "y")
|| !strcmp(btmp, "YES") || !strcmp(btmp, "yes")) {
*asn1_bool = 0xff;
return 1;
} else if(!strcmp(btmp, "FALSE") || !strcmp(btmp, "false")
|| !strcmp(btmp, "N") || !strcmp(btmp, "n")
|| !strcmp(btmp, "NO") || !strcmp(btmp, "no")) {
*asn1_bool = 0;
return 1;
}
err:
X509V3err(X509V3_F_X509V3_GET_VALUE_BOOL,X509V3_R_INVALID_BOOLEAN_STRING);
X509V3_conf_err(value);
return 0;
}
int X509V3_get_value_int(CONF_VALUE *value, ASN1_INTEGER **aint)
{
ASN1_INTEGER *itmp;
if(!(itmp = s2i_ASN1_INTEGER(NULL, value->value))) {
X509V3_conf_err(value);
return 0;
}
*aint = itmp;
return 1;
}
char *strip_spaces(char *name)
{
char *p, *q;
p = name;
while(*p && isspace((unsigned char)*p)) p++;
if(!*p) return NULL;
q = p + strlen(p) - 1;
while((q != p) && isspace((unsigned char)*q)) q--;
if(p != q) q[1] = 0;
if(!*p) return NULL;
return p;
}
char *hex_to_string(unsigned char *buffer, long len)
{
char *tmp, *q;
unsigned char *p;
int i;
static char hexdig[] = "0123456789ABCDEF";
if(!buffer || !len) return NULL;
if(!(tmp = OPENSSL_malloc(len * 3 + 1))) {
X509V3err(X509V3_F_HEX_TO_STRING,ERR_R_MALLOC_FAILURE);
return NULL;
}
q = tmp;
for(i = 0, p = buffer; i < len; i++,p++) {
*q++ = hexdig[(*p >> 4) & 0xf];
*q++ = hexdig[*p & 0xf];
*q++ = ':';
}
q[-1] = 0;
#ifdef CHARSET_EBCDIC
ebcdic2ascii(tmp, tmp, q - tmp - 1);
#endif
return tmp;
}
unsigned char *string_to_hex(char *str, long *len)
{
unsigned char *hexbuf, *q;
unsigned char ch, cl, *p;
if(!str) {
X509V3err(X509V3_F_STRING_TO_HEX,X509V3_R_INVALID_NULL_ARGUMENT);
return NULL;
}
if(!(hexbuf = OPENSSL_malloc(strlen(str) >> 1))) goto err;
for(p = (unsigned char *)str, q = hexbuf; *p;) {
ch = *p++;
#ifdef CHARSET_EBCDIC
ch = os_toebcdic[ch];
#endif
if(ch == ':') continue;
cl = *p++;
#ifdef CHARSET_EBCDIC
cl = os_toebcdic[cl];
#endif
if(!cl) {
X509V3err(X509V3_F_STRING_TO_HEX,X509V3_R_ODD_NUMBER_OF_DIGITS);
OPENSSL_free(hexbuf);
return NULL;
}
if(isupper(ch)) ch = tolower(ch);
if(isupper(cl)) cl = tolower(cl);
if((ch >= '0') && (ch <= '9')) ch -= '0';
else if ((ch >= 'a') && (ch <= 'f')) ch -= 'a' - 10;
else goto badhex;
if((cl >= '0') && (cl <= '9')) cl -= '0';
else if ((cl >= 'a') && (cl <= 'f')) cl -= 'a' - 10;
else goto badhex;
*q++ = (ch << 4) | cl;
}
if(len) *len = q - hexbuf;
return hexbuf;
err:
if(hexbuf) OPENSSL_free(hexbuf);
X509V3err(X509V3_F_STRING_TO_HEX,ERR_R_MALLOC_FAILURE);
return NULL;
badhex:
OPENSSL_free(hexbuf);
X509V3err(X509V3_F_STRING_TO_HEX,X509V3_R_ILLEGAL_HEX_DIGIT);
return NULL;
}
int name_cmp(const char *name, const char *cmp)
{
int len, ret;
char c;
len = strlen(cmp);
if((ret = strncmp(name, cmp, len))) return ret;
c = name[len];
if(!c || (c=='.')) return 0;
return 1;
}
static int sk_strcmp(const char * const *a, const char * const *b)
{
return strcmp(*a, *b);
}
STACK *X509_get1_email(X509 *x)
{
GENERAL_NAMES *gens;
STACK *ret;
gens = X509_get_ext_d2i(x, NID_subject_alt_name, NULL, NULL);
ret = get_email(X509_get_subject_name(x), gens);
sk_GENERAL_NAME_pop_free(gens, GENERAL_NAME_free);
return ret;
}
STACK *X509_REQ_get1_email(X509_REQ *x)
{
GENERAL_NAMES *gens;
STACK_OF(X509_EXTENSION) *exts;
STACK *ret;
exts = X509_REQ_get_extensions(x);
gens = X509V3_get_d2i(exts, NID_subject_alt_name, NULL, NULL);
ret = get_email(X509_REQ_get_subject_name(x), gens);
sk_GENERAL_NAME_pop_free(gens, GENERAL_NAME_free);
sk_X509_EXTENSION_pop_free(exts, X509_EXTENSION_free);
return ret;
}
static STACK *get_email(X509_NAME *name, GENERAL_NAMES *gens)
{
STACK *ret = NULL;
X509_NAME_ENTRY *ne;
ASN1_IA5STRING *email;
GENERAL_NAME *gen;
int i;
i = -1;
while((i = X509_NAME_get_index_by_NID(name,
NID_pkcs9_emailAddress, i)) >= 0) {
ne = X509_NAME_get_entry(name, i);
email = X509_NAME_ENTRY_get_data(ne);
if(!append_ia5(&ret, email)) return NULL;
}
for(i = 0; i < sk_GENERAL_NAME_num(gens); i++)
{
gen = sk_GENERAL_NAME_value(gens, i);
if(gen->type != GEN_EMAIL) continue;
if(!append_ia5(&ret, gen->d.ia5)) return NULL;
}
return ret;
}
static void str_free(void *str)
{
OPENSSL_free(str);
}
static int append_ia5(STACK **sk, ASN1_IA5STRING *email)
{
char *emtmp;
if(email->type != V_ASN1_IA5STRING) return 1;
if(!email->data || !email->length) return 1;
if(!*sk) *sk = sk_new(sk_strcmp);
if(!*sk) return 0;
if(sk_find(*sk, (char *)email->data) != -1) return 1;
emtmp = BUF_strdup((char *)email->data);
if(!emtmp || !sk_push(*sk, emtmp)) {
X509_email_free(*sk);
*sk = NULL;
return 0;
}
return 1;
}
void X509_email_free(STACK *sk)
{
sk_pop_free(sk, str_free);
}
