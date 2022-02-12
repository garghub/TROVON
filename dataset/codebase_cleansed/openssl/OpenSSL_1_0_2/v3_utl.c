void X509V3_conf_free(CONF_VALUE *conf)
{
if (!conf)
return;
if (conf->name)
OPENSSL_free(conf->name);
if (conf->value)
OPENSSL_free(conf->value);
if (conf->section)
OPENSSL_free(conf->section);
OPENSSL_free(conf);
}
char *i2s_ASN1_ENUMERATED(X509V3_EXT_METHOD *method, ASN1_ENUMERATED *a)
{
BIGNUM *bntmp = NULL;
char *strtmp = NULL;
if (!a)
return NULL;
if (!(bntmp = ASN1_ENUMERATED_to_BN(a, NULL)) ||
!(strtmp = BN_bn2dec(bntmp)))
X509V3err(X509V3_F_I2S_ASN1_ENUMERATED, ERR_R_MALLOC_FAILURE);
BN_free(bntmp);
return strtmp;
}
char *i2s_ASN1_INTEGER(X509V3_EXT_METHOD *method, ASN1_INTEGER *a)
{
BIGNUM *bntmp = NULL;
char *strtmp = NULL;
if (!a)
return NULL;
if (!(bntmp = ASN1_INTEGER_to_BN(a, NULL)) ||
!(strtmp = BN_bn2dec(bntmp)))
X509V3err(X509V3_F_I2S_ASN1_INTEGER, ERR_R_MALLOC_FAILURE);
BN_free(bntmp);
return strtmp;
}
ASN1_INTEGER *s2i_ASN1_INTEGER(X509V3_EXT_METHOD *method, char *value)
{
BIGNUM *bn = NULL;
ASN1_INTEGER *aint;
int isneg, ishex;
int ret;
if (!value) {
X509V3err(X509V3_F_S2I_ASN1_INTEGER, X509V3_R_INVALID_NULL_VALUE);
return 0;
}
bn = BN_new();
if (value[0] == '-') {
value++;
isneg = 1;
} else
isneg = 0;
if (value[0] == '0' && ((value[1] == 'x') || (value[1] == 'X'))) {
value += 2;
ishex = 1;
} else
ishex = 0;
if (ishex)
ret = BN_hex2bn(&bn, value);
else
ret = BN_dec2bn(&bn, value);
if (!ret || value[ret]) {
BN_free(bn);
X509V3err(X509V3_F_S2I_ASN1_INTEGER, X509V3_R_BN_DEC2BN_ERROR);
return 0;
}
if (isneg && BN_is_zero(bn))
isneg = 0;
aint = BN_to_ASN1_INTEGER(bn, NULL);
BN_free(bn);
if (!aint) {
X509V3err(X509V3_F_S2I_ASN1_INTEGER,
X509V3_R_BN_TO_ASN1_INTEGER_ERROR);
return 0;
}
if (isneg)
aint->type |= V_ASN1_NEG;
return aint;
}
int X509V3_get_value_bool(CONF_VALUE *value, int *asn1_bool)
{
char *btmp;
if (!(btmp = value->value))
goto err;
if (!strcmp(btmp, "TRUE") || !strcmp(btmp, "true")
|| !strcmp(btmp, "Y") || !strcmp(btmp, "y")
|| !strcmp(btmp, "YES") || !strcmp(btmp, "yes")) {
*asn1_bool = 0xff;
return 1;
} else if (!strcmp(btmp, "FALSE") || !strcmp(btmp, "false")
|| !strcmp(btmp, "N") || !strcmp(btmp, "n")
|| !strcmp(btmp, "NO") || !strcmp(btmp, "no")) {
*asn1_bool = 0;
return 1;
}
err:
X509V3err(X509V3_F_X509V3_GET_VALUE_BOOL,
X509V3_R_INVALID_BOOLEAN_STRING);
X509V3_conf_err(value);
return 0;
}
int X509V3_get_value_int(CONF_VALUE *value, ASN1_INTEGER **aint)
{
ASN1_INTEGER *itmp;
if (!(itmp = s2i_ASN1_INTEGER(NULL, value->value))) {
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
while (*p && isspace((unsigned char)*p))
p++;
if (!*p)
return NULL;
q = p + strlen(p) - 1;
while ((q != p) && isspace((unsigned char)*q))
q--;
if (p != q)
q[1] = 0;
if (!*p)
return NULL;
return p;
}
char *hex_to_string(const unsigned char *buffer, long len)
{
char *tmp, *q;
const unsigned char *p;
int i;
const static char hexdig[] = "0123456789ABCDEF";
if (!buffer || !len)
return NULL;
if (!(tmp = OPENSSL_malloc(len * 3 + 1))) {
X509V3err(X509V3_F_HEX_TO_STRING, ERR_R_MALLOC_FAILURE);
return NULL;
}
q = tmp;
for (i = 0, p = buffer; i < len; i++, p++) {
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
unsigned char *string_to_hex(const char *str, long *len)
{
unsigned char *hexbuf, *q;
unsigned char ch, cl, *p;
if (!str) {
X509V3err(X509V3_F_STRING_TO_HEX, X509V3_R_INVALID_NULL_ARGUMENT);
return NULL;
}
if (!(hexbuf = OPENSSL_malloc(strlen(str) >> 1)))
goto err;
for (p = (unsigned char *)str, q = hexbuf; *p;) {
ch = *p++;
#ifdef CHARSET_EBCDIC
ch = os_toebcdic[ch];
#endif
if (ch == ':')
continue;
cl = *p++;
#ifdef CHARSET_EBCDIC
cl = os_toebcdic[cl];
#endif
if (!cl) {
X509V3err(X509V3_F_STRING_TO_HEX, X509V3_R_ODD_NUMBER_OF_DIGITS);
OPENSSL_free(hexbuf);
return NULL;
}
if (isupper(ch))
ch = tolower(ch);
if (isupper(cl))
cl = tolower(cl);
if ((ch >= '0') && (ch <= '9'))
ch -= '0';
else if ((ch >= 'a') && (ch <= 'f'))
ch -= 'a' - 10;
else
goto badhex;
if ((cl >= '0') && (cl <= '9'))
cl -= '0';
else if ((cl >= 'a') && (cl <= 'f'))
cl -= 'a' - 10;
else
goto badhex;
*q++ = (ch << 4) | cl;
}
if (len)
*len = q - hexbuf;
return hexbuf;
err:
if (hexbuf)
OPENSSL_free(hexbuf);
X509V3err(X509V3_F_STRING_TO_HEX, ERR_R_MALLOC_FAILURE);
return NULL;
badhex:
OPENSSL_free(hexbuf);
X509V3err(X509V3_F_STRING_TO_HEX, X509V3_R_ILLEGAL_HEX_DIGIT);
return NULL;
}
int name_cmp(const char *name, const char *cmp)
{
int len, ret;
char c;
len = strlen(cmp);
if ((ret = strncmp(name, cmp, len)))
return ret;
c = name[len];
if (!c || (c == '.'))
return 0;
return 1;
}
static int sk_strcmp(const char *const *a, const char *const *b)
{
return strcmp(*a, *b);
}
void str_free(OPENSSL_STRING str)
{
OPENSSL_free(str);
}
static void skip_prefix(const unsigned char **p, size_t *plen,
const unsigned char *subject, size_t subject_len,
unsigned int flags)
{
const unsigned char *pattern = *p;
size_t pattern_len = *plen;
if ((flags & _X509_CHECK_FLAG_DOT_SUBDOMAINS) == 0)
return;
while (pattern_len > subject_len && *pattern) {
if ((flags & X509_CHECK_FLAG_SINGLE_LABEL_SUBDOMAINS) &&
*pattern == '.')
break;
++pattern;
--pattern_len;
}
if (pattern_len == subject_len) {
*p = pattern;
*plen = pattern_len;
}
}
static int equal_nocase(const unsigned char *pattern, size_t pattern_len,
const unsigned char *subject, size_t subject_len,
unsigned int flags)
{
skip_prefix(&pattern, &pattern_len, subject, subject_len, flags);
if (pattern_len != subject_len)
return 0;
while (pattern_len) {
unsigned char l = *pattern;
unsigned char r = *subject;
if (l == 0)
return 0;
if (l != r) {
if ('A' <= l && l <= 'Z')
l = (l - 'A') + 'a';
if ('A' <= r && r <= 'Z')
r = (r - 'A') + 'a';
if (l != r)
return 0;
}
++pattern;
++subject;
--pattern_len;
}
return 1;
}
static int equal_case(const unsigned char *pattern, size_t pattern_len,
const unsigned char *subject, size_t subject_len,
unsigned int flags)
{
skip_prefix(&pattern, &pattern_len, subject, subject_len, flags);
if (pattern_len != subject_len)
return 0;
return !memcmp(pattern, subject, pattern_len);
}
static int equal_email(const unsigned char *a, size_t a_len,
const unsigned char *b, size_t b_len,
unsigned int unused_flags)
{
size_t i = a_len;
if (a_len != b_len)
return 0;
while (i > 0) {
--i;
if (a[i] == '@' || b[i] == '@') {
if (!equal_nocase(a + i, a_len - i, b + i, a_len - i, 0))
return 0;
break;
}
}
if (i == 0)
i = a_len;
return equal_case(a, i, b, i, 0);
}
static int wildcard_match(const unsigned char *prefix, size_t prefix_len,
const unsigned char *suffix, size_t suffix_len,
const unsigned char *subject, size_t subject_len,
unsigned int flags)
{
const unsigned char *wildcard_start;
const unsigned char *wildcard_end;
const unsigned char *p;
int allow_multi = 0;
int allow_idna = 0;
if (subject_len < prefix_len + suffix_len)
return 0;
if (!equal_nocase(prefix, prefix_len, subject, prefix_len, flags))
return 0;
wildcard_start = subject + prefix_len;
wildcard_end = subject + (subject_len - suffix_len);
if (!equal_nocase(wildcard_end, suffix_len, suffix, suffix_len, flags))
return 0;
if (prefix_len == 0 && *suffix == '.') {
if (wildcard_start == wildcard_end)
return 0;
allow_idna = 1;
if (flags & X509_CHECK_FLAG_MULTI_LABEL_WILDCARDS)
allow_multi = 1;
}
if (!allow_idna &&
subject_len >= 4 && strncasecmp((char *)subject, "xn--", 4) == 0)
return 0;
if (wildcard_end == wildcard_start + 1 && *wildcard_start == '*')
return 1;
for (p = wildcard_start; p != wildcard_end; ++p)
if (!(('0' <= *p && *p <= '9') ||
('A' <= *p && *p <= 'Z') ||
('a' <= *p && *p <= 'z') ||
*p == '-' || (allow_multi && *p == '.')))
return 0;
return 1;
}
static const unsigned char *valid_star(const unsigned char *p, size_t len,
unsigned int flags)
{
const unsigned char *star = 0;
size_t i;
int state = LABEL_START;
int dots = 0;
for (i = 0; i < len; ++i) {
if (p[i] == '*') {
int atstart = (state & LABEL_START);
int atend = (i == len - 1 || p[i + i] == '.');
if (star != NULL || (state & LABEL_IDNA) != 0 || dots)
return NULL;
if ((flags & X509_CHECK_FLAG_NO_PARTIAL_WILDCARDS)
&& (!atstart || !atend))
return NULL;
if (!atstart && !atend)
return NULL;
star = &p[i];
state &= ~LABEL_START;
} else if (('a' <= p[i] && p[i] <= 'z')
|| ('A' <= p[i] && p[i] <= 'Z')
|| ('0' <= p[i] && p[i] <= '9')) {
if ((state & LABEL_START) != 0
&& len - i >= 4 && strncasecmp((char *)&p[i], "xn--", 4) == 0)
state |= LABEL_IDNA;
state &= ~(LABEL_HYPHEN | LABEL_START);
} else if (p[i] == '.') {
if ((state & (LABEL_HYPHEN | LABEL_START)) != 0)
return NULL;
state = LABEL_START;
++dots;
} else if (p[i] == '-') {
if ((state & LABEL_HYPHEN) != 0)
return NULL;
state |= LABEL_HYPHEN;
} else
return NULL;
}
if ((state & (LABEL_START | LABEL_HYPHEN)) != 0 || dots < 2)
return NULL;
return star;
}
static int equal_wildcard(const unsigned char *pattern, size_t pattern_len,
const unsigned char *subject, size_t subject_len,
unsigned int flags)
{
const unsigned char *star = NULL;
if (!(subject_len > 1 && subject[0] == '.'))
star = valid_star(pattern, pattern_len, flags);
if (star == NULL)
return equal_nocase(pattern, pattern_len,
subject, subject_len, flags);
return wildcard_match(pattern, star - pattern,
star + 1, (pattern + pattern_len) - star - 1,
subject, subject_len, flags);
}
static int do_check_string(ASN1_STRING *a, int cmp_type, equal_fn equal,
unsigned int flags, const char *b, size_t blen,
char **peername)
{
int rv = 0;
if (!a->data || !a->length)
return 0;
if (cmp_type > 0) {
if (cmp_type != a->type)
return 0;
if (cmp_type == V_ASN1_IA5STRING)
rv = equal(a->data, a->length, (unsigned char *)b, blen, flags);
else if (a->length == (int)blen && !memcmp(a->data, b, blen))
rv = 1;
if (rv > 0 && peername)
*peername = BUF_strndup((char *)a->data, a->length);
} else {
int astrlen;
unsigned char *astr;
astrlen = ASN1_STRING_to_UTF8(&astr, a);
if (astrlen < 0)
return -1;
rv = equal(astr, astrlen, (unsigned char *)b, blen, flags);
if (rv > 0 && peername)
*peername = BUF_strndup((char *)astr, astrlen);
OPENSSL_free(astr);
}
return rv;
}
static int do_x509_check(X509 *x, const char *chk, size_t chklen,
unsigned int flags, int check_type, char **peername)
{
GENERAL_NAMES *gens = NULL;
X509_NAME *name = NULL;
int i;
int cnid;
int alt_type;
int san_present = 0;
int rv = 0;
equal_fn equal;
flags &= ~_X509_CHECK_FLAG_DOT_SUBDOMAINS;
if (check_type == GEN_EMAIL) {
cnid = NID_pkcs9_emailAddress;
alt_type = V_ASN1_IA5STRING;
equal = equal_email;
} else if (check_type == GEN_DNS) {
cnid = NID_commonName;
if (chklen > 1 && chk[0] == '.')
flags |= _X509_CHECK_FLAG_DOT_SUBDOMAINS;
alt_type = V_ASN1_IA5STRING;
if (flags & X509_CHECK_FLAG_NO_WILDCARDS)
equal = equal_nocase;
else
equal = equal_wildcard;
} else {
cnid = 0;
alt_type = V_ASN1_OCTET_STRING;
equal = equal_case;
}
if (chklen == 0)
chklen = strlen(chk);
gens = X509_get_ext_d2i(x, NID_subject_alt_name, NULL, NULL);
if (gens) {
for (i = 0; i < sk_GENERAL_NAME_num(gens); i++) {
GENERAL_NAME *gen;
ASN1_STRING *cstr;
gen = sk_GENERAL_NAME_value(gens, i);
if (gen->type != check_type)
continue;
san_present = 1;
if (check_type == GEN_EMAIL)
cstr = gen->d.rfc822Name;
else if (check_type == GEN_DNS)
cstr = gen->d.dNSName;
else
cstr = gen->d.iPAddress;
if ((rv = do_check_string(cstr, alt_type, equal, flags,
chk, chklen, peername)) != 0)
break;
}
GENERAL_NAMES_free(gens);
if (rv != 0)
return rv;
if (!cnid
|| (san_present
&& !(flags & X509_CHECK_FLAG_ALWAYS_CHECK_SUBJECT)))
return 0;
}
i = -1;
name = X509_get_subject_name(x);
while ((i = X509_NAME_get_index_by_NID(name, cnid, i)) >= 0) {
X509_NAME_ENTRY *ne;
ASN1_STRING *str;
ne = X509_NAME_get_entry(name, i);
str = X509_NAME_ENTRY_get_data(ne);
if ((rv = do_check_string(str, -1, equal, flags,
chk, chklen, peername)) != 0)
return rv;
}
return 0;
}
int X509_check_host(X509 *x, const char *chk, size_t chklen,
unsigned int flags, char **peername)
{
if (chk == NULL)
return -2;
if (chklen == 0)
chklen = strlen(chk);
else if (memchr(chk, '\0', chklen > 1 ? chklen - 1 : chklen))
return -2;
if (chklen > 1 && chk[chklen - 1] == '\0')
--chklen;
return do_x509_check(x, chk, chklen, flags, GEN_DNS, peername);
}
int X509_check_email(X509 *x, const char *chk, size_t chklen,
unsigned int flags)
{
if (chk == NULL)
return -2;
if (chklen == 0)
chklen = strlen((char *)chk);
else if (memchr(chk, '\0', chklen > 1 ? chklen - 1 : chklen))
return -2;
if (chklen > 1 && chk[chklen - 1] == '\0')
--chklen;
return do_x509_check(x, chk, chklen, flags, GEN_EMAIL, NULL);
}
int X509_check_ip(X509 *x, const unsigned char *chk, size_t chklen,
unsigned int flags)
{
if (chk == NULL)
return -2;
return do_x509_check(x, (char *)chk, chklen, flags, GEN_IPADD, NULL);
}
int X509_check_ip_asc(X509 *x, const char *ipasc, unsigned int flags)
{
unsigned char ipout[16];
size_t iplen;
if (ipasc == NULL)
return -2;
iplen = (size_t)a2i_ipadd(ipout, ipasc);
if (iplen == 0)
return -2;
return do_x509_check(x, (char *)ipout, iplen, flags, GEN_IPADD, NULL);
}
ASN1_OCTET_STRING *a2i_IPADDRESS(const char *ipasc)
{
unsigned char ipout[16];
ASN1_OCTET_STRING *ret;
int iplen;
iplen = a2i_ipadd(ipout, ipasc);
if (!iplen)
return NULL;
ret = ASN1_OCTET_STRING_new();
if (!ret)
return NULL;
if (!ASN1_OCTET_STRING_set(ret, ipout, iplen)) {
ASN1_OCTET_STRING_free(ret);
return NULL;
}
return ret;
}
ASN1_OCTET_STRING *a2i_IPADDRESS_NC(const char *ipasc)
{
ASN1_OCTET_STRING *ret = NULL;
unsigned char ipout[32];
char *iptmp = NULL, *p;
int iplen1, iplen2;
p = strchr(ipasc, '/');
if (!p)
return NULL;
iptmp = BUF_strdup(ipasc);
if (!iptmp)
return NULL;
p = iptmp + (p - ipasc);
*p++ = 0;
iplen1 = a2i_ipadd(ipout, iptmp);
if (!iplen1)
goto err;
iplen2 = a2i_ipadd(ipout + iplen1, p);
OPENSSL_free(iptmp);
iptmp = NULL;
if (!iplen2 || (iplen1 != iplen2))
goto err;
ret = ASN1_OCTET_STRING_new();
if (!ret)
goto err;
if (!ASN1_OCTET_STRING_set(ret, ipout, iplen1 + iplen2))
goto err;
return ret;
err:
if (iptmp)
OPENSSL_free(iptmp);
if (ret)
ASN1_OCTET_STRING_free(ret);
return NULL;
}
int a2i_ipadd(unsigned char *ipout, const char *ipasc)
{
if (strchr(ipasc, ':')) {
if (!ipv6_from_asc(ipout, ipasc))
return 0;
return 16;
} else {
if (!ipv4_from_asc(ipout, ipasc))
return 0;
return 4;
}
}
static int ipv4_from_asc(unsigned char *v4, const char *in)
{
int a0, a1, a2, a3;
if (sscanf(in, "%d.%d.%d.%d", &a0, &a1, &a2, &a3) != 4)
return 0;
if ((a0 < 0) || (a0 > 255) || (a1 < 0) || (a1 > 255)
|| (a2 < 0) || (a2 > 255) || (a3 < 0) || (a3 > 255))
return 0;
v4[0] = a0;
v4[1] = a1;
v4[2] = a2;
v4[3] = a3;
return 1;
}
static int ipv6_from_asc(unsigned char *v6, const char *in)
{
IPV6_STAT v6stat;
v6stat.total = 0;
v6stat.zero_pos = -1;
v6stat.zero_cnt = 0;
if (!CONF_parse_list(in, ':', 0, ipv6_cb, &v6stat))
return 0;
if (v6stat.zero_pos == -1) {
if (v6stat.total != 16)
return 0;
} else {
if (v6stat.total == 16)
return 0;
if (v6stat.zero_cnt > 3)
return 0;
else if (v6stat.zero_cnt == 3) {
if (v6stat.total > 0)
return 0;
}
else if (v6stat.zero_cnt == 2) {
if ((v6stat.zero_pos != 0)
&& (v6stat.zero_pos != v6stat.total))
return 0;
} else
{
if ((v6stat.zero_pos == 0)
|| (v6stat.zero_pos == v6stat.total))
return 0;
}
}
if (v6stat.zero_pos >= 0) {
memcpy(v6, v6stat.tmp, v6stat.zero_pos);
memset(v6 + v6stat.zero_pos, 0, 16 - v6stat.total);
if (v6stat.total != v6stat.zero_pos)
memcpy(v6 + v6stat.zero_pos + 16 - v6stat.total,
v6stat.tmp + v6stat.zero_pos,
v6stat.total - v6stat.zero_pos);
} else
memcpy(v6, v6stat.tmp, 16);
return 1;
}
static int ipv6_cb(const char *elem, int len, void *usr)
{
IPV6_STAT *s = usr;
if (s->total == 16)
return 0;
if (len == 0) {
if (s->zero_pos == -1)
s->zero_pos = s->total;
else if (s->zero_pos != s->total)
return 0;
s->zero_cnt++;
} else {
if (len > 4) {
if (s->total > 12)
return 0;
if (elem[len])
return 0;
if (!ipv4_from_asc(s->tmp + s->total, elem))
return 0;
s->total += 4;
} else {
if (!ipv6_hex(s->tmp + s->total, elem, len))
return 0;
s->total += 2;
}
}
return 1;
}
static int ipv6_hex(unsigned char *out, const char *in, int inlen)
{
unsigned char c;
unsigned int num = 0;
if (inlen > 4)
return 0;
while (inlen--) {
c = *in++;
num <<= 4;
if ((c >= '0') && (c <= '9'))
num |= c - '0';
else if ((c >= 'A') && (c <= 'F'))
num |= c - 'A' + 10;
else if ((c >= 'a') && (c <= 'f'))
num |= c - 'a' + 10;
else
return 0;
}
out[0] = num >> 8;
out[1] = num & 0xff;
return 1;
}
