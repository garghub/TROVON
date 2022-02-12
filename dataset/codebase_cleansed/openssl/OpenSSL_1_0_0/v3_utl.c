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
if (!value) {
X509V3err(X509V3_F_S2I_ASN1_INTEGER,X509V3_R_INVALID_NULL_VALUE);
return 0;
}
bn = BN_new();
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
if (!ret || value[ret]) {
BN_free(bn);
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
char *hex_to_string(const unsigned char *buffer, long len)
{
char *tmp, *q;
const unsigned char *p;
int i;
const static char hexdig[] = "0123456789ABCDEF";
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
unsigned char *string_to_hex(const char *str, long *len)
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
void str_free(OPENSSL_STRING str)
{
OPENSSL_free(str);
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
if (!ASN1_OCTET_STRING_set(ret, ipout, iplen))
{
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
p = strchr(ipasc,'/');
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
if (strchr(ipasc, ':'))
{
if (!ipv6_from_asc(ipout, ipasc))
return 0;
return 16;
}
else
{
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
if (v6stat.zero_pos == -1)
{
if (v6stat.total != 16)
return 0;
}
else
{
if (v6stat.total == 16)
return 0;
if (v6stat.zero_cnt > 3)
return 0;
else if (v6stat.zero_cnt == 3)
{
if (v6stat.total > 0)
return 0;
}
else if (v6stat.zero_cnt == 2)
{
if ((v6stat.zero_pos != 0)
&& (v6stat.zero_pos != v6stat.total))
return 0;
}
else
{
if ((v6stat.zero_pos == 0)
|| (v6stat.zero_pos == v6stat.total))
return 0;
}
}
if (v6stat.zero_pos >= 0)
{
memcpy(v6, v6stat.tmp, v6stat.zero_pos);
memset(v6 + v6stat.zero_pos, 0, 16 - v6stat.total);
if (v6stat.total != v6stat.zero_pos)
memcpy(v6 + v6stat.zero_pos + 16 - v6stat.total,
v6stat.tmp + v6stat.zero_pos,
v6stat.total - v6stat.zero_pos);
}
else
memcpy(v6, v6stat.tmp, 16);
return 1;
}
static int ipv6_cb(const char *elem, int len, void *usr)
{
IPV6_STAT *s = usr;
if (s->total == 16)
return 0;
if (len == 0)
{
if (s->zero_pos == -1)
s->zero_pos = s->total;
else if (s->zero_pos != s->total)
return 0;
s->zero_cnt++;
}
else
{
if (len > 4)
{
if (s->total > 12)
return 0;
if (elem[len])
return 0;
if (!ipv4_from_asc(s->tmp + s->total, elem))
return 0;
s->total += 4;
}
else
{
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
while(inlen--)
{
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
