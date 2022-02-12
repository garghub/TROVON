ASN1_TYPE *ASN1_generate_nconf(char *str, CONF *nconf)
{
X509V3_CTX cnf;
if (!nconf)
return ASN1_generate_v3(str, NULL);
X509V3_set_nconf(&cnf, nconf);
return ASN1_generate_v3(str, &cnf);
}
ASN1_TYPE *ASN1_generate_v3(char *str, X509V3_CTX *cnf)
{
ASN1_TYPE *ret;
tag_exp_arg asn1_tags;
tag_exp_type *etmp;
int i, len;
unsigned char *orig_der = NULL, *new_der = NULL;
const unsigned char *cpy_start;
unsigned char *p;
const unsigned char *cp;
int cpy_len;
long hdr_len;
int hdr_constructed = 0, hdr_tag, hdr_class;
int r;
asn1_tags.imp_tag = -1;
asn1_tags.imp_class = -1;
asn1_tags.format = ASN1_GEN_FORMAT_ASCII;
asn1_tags.exp_count = 0;
if (CONF_parse_list(str, ',', 1, asn1_cb, &asn1_tags) != 0)
return NULL;
if ((asn1_tags.utype == V_ASN1_SEQUENCE) || (asn1_tags.utype == V_ASN1_SET))
{
if (!cnf)
{
ASN1err(ASN1_F_ASN1_GENERATE_V3, ASN1_R_SEQUENCE_OR_SET_NEEDS_CONFIG);
return NULL;
}
ret = asn1_multi(asn1_tags.utype, asn1_tags.str, cnf);
}
else
ret = asn1_str2type(asn1_tags.str, asn1_tags.format, asn1_tags.utype);
if (!ret)
return NULL;
if ((asn1_tags.imp_tag == -1) && (asn1_tags.exp_count == 0))
return ret;
cpy_len = i2d_ASN1_TYPE(ret, &orig_der);
ASN1_TYPE_free(ret);
ret = NULL;
cpy_start = orig_der;
if (asn1_tags.imp_tag != -1)
{
r = ASN1_get_object(&cpy_start, &hdr_len, &hdr_tag, &hdr_class, cpy_len);
if (r & 0x80)
goto err;
cpy_len -= cpy_start - orig_der;
if (r & 0x1)
{
hdr_constructed = 2;
hdr_len = 0;
}
else
hdr_constructed = r & V_ASN1_CONSTRUCTED;
len = ASN1_object_size(0, hdr_len, asn1_tags.imp_tag);
}
else
len = cpy_len;
for(i = 0, etmp = asn1_tags.exp_list + asn1_tags.exp_count - 1; i < asn1_tags.exp_count; i++, etmp--)
{
len += etmp->exp_pad;
etmp->exp_len = len;
len = ASN1_object_size(0, len, etmp->exp_tag);
}
new_der = OPENSSL_malloc(len);
p = new_der;
for (i = 0, etmp = asn1_tags.exp_list; i < asn1_tags.exp_count; i++, etmp++)
{
ASN1_put_object(&p, etmp->exp_constructed, etmp->exp_len,
etmp->exp_tag, etmp->exp_class);
if (etmp->exp_pad)
*p++ = 0;
}
if (asn1_tags.imp_tag != -1)
ASN1_put_object(&p, hdr_constructed, hdr_len,
asn1_tags.imp_tag, asn1_tags.imp_class);
memcpy(p, cpy_start, cpy_len);
cp = new_der;
ret = d2i_ASN1_TYPE(NULL, &cp, len);
err:
if (orig_der)
OPENSSL_free(orig_der);
if (new_der)
OPENSSL_free(new_der);
return ret;
}
static int asn1_cb(const char *elem, int len, void *bitstr)
{
tag_exp_arg *arg = bitstr;
int i;
int utype;
int vlen = 0;
const char *p, *vstart = NULL;
int tmp_tag, tmp_class;
for(i = 0, p = elem; i < len; p++, i++)
{
if (*p == ':')
{
vstart = p + 1;
vlen = len - (vstart - elem);
len = p - elem;
break;
}
}
utype = asn1_str2tag(elem, len);
if (utype == -1)
{
ASN1err(ASN1_F_ASN1_CB, ASN1_R_UNKNOWN_TAG);
ERR_add_error_data(2, "tag=", elem);
return -1;
}
if (!(utype & ASN1_GEN_FLAG))
{
arg->utype = utype;
arg->str = vstart;
if (!vstart && elem[len])
{
ASN1err(ASN1_F_ASN1_CB, ASN1_R_MISSING_VALUE);
return -1;
}
return 0;
}
switch(utype)
{
case ASN1_GEN_FLAG_IMP:
if (arg->imp_tag != -1)
{
ASN1err(ASN1_F_ASN1_CB, ASN1_R_ILLEGAL_NESTED_TAGGING);
return -1;
}
if (!parse_tagging(vstart, vlen, &arg->imp_tag, &arg->imp_class))
return -1;
break;
case ASN1_GEN_FLAG_EXP:
if (!parse_tagging(vstart, vlen, &tmp_tag, &tmp_class))
return -1;
if (!append_exp(arg, tmp_tag, tmp_class, 1, 0, 0))
return -1;
break;
case ASN1_GEN_FLAG_SEQWRAP:
if (!append_exp(arg, V_ASN1_SEQUENCE, V_ASN1_UNIVERSAL, 1, 0, 1))
return -1;
break;
case ASN1_GEN_FLAG_SETWRAP:
if (!append_exp(arg, V_ASN1_SET, V_ASN1_UNIVERSAL, 1, 0, 1))
return -1;
break;
case ASN1_GEN_FLAG_BITWRAP:
if (!append_exp(arg, V_ASN1_BIT_STRING, V_ASN1_UNIVERSAL, 0, 1, 1))
return -1;
break;
case ASN1_GEN_FLAG_OCTWRAP:
if (!append_exp(arg, V_ASN1_OCTET_STRING, V_ASN1_UNIVERSAL, 0, 0, 1))
return -1;
break;
case ASN1_GEN_FLAG_FORMAT:
if (!strncmp(vstart, "ASCII", 5))
arg->format = ASN1_GEN_FORMAT_ASCII;
else if (!strncmp(vstart, "UTF8", 4))
arg->format = ASN1_GEN_FORMAT_UTF8;
else if (!strncmp(vstart, "HEX", 3))
arg->format = ASN1_GEN_FORMAT_HEX;
else if (!strncmp(vstart, "BITLIST", 3))
arg->format = ASN1_GEN_FORMAT_BITLIST;
else
{
ASN1err(ASN1_F_ASN1_CB, ASN1_R_UNKOWN_FORMAT);
return -1;
}
break;
}
return 1;
}
static int parse_tagging(const char *vstart, int vlen, int *ptag, int *pclass)
{
char erch[2];
long tag_num;
char *eptr;
if (!vstart)
return 0;
tag_num = strtoul(vstart, &eptr, 10);
if (eptr && *eptr && (eptr > vstart + vlen))
return 0;
if (tag_num < 0)
{
ASN1err(ASN1_F_PARSE_TAGGING, ASN1_R_INVALID_NUMBER);
return 0;
}
*ptag = tag_num;
if (eptr)
vlen -= eptr - vstart;
else
vlen = 0;
if (vlen)
{
switch (*eptr)
{
case 'U':
*pclass = V_ASN1_UNIVERSAL;
break;
case 'A':
*pclass = V_ASN1_APPLICATION;
break;
case 'P':
*pclass = V_ASN1_PRIVATE;
break;
case 'C':
*pclass = V_ASN1_CONTEXT_SPECIFIC;
break;
default:
erch[0] = *eptr;
erch[1] = 0;
ASN1err(ASN1_F_PARSE_TAGGING, ASN1_R_INVALID_MODIFIER);
ERR_add_error_data(2, "Char=", erch);
return 0;
break;
}
}
else
*pclass = V_ASN1_CONTEXT_SPECIFIC;
return 1;
}
static ASN1_TYPE *asn1_multi(int utype, const char *section, X509V3_CTX *cnf)
{
ASN1_TYPE *ret = NULL, *typ = NULL;
STACK_OF(ASN1_TYPE) *sk = NULL;
STACK_OF(CONF_VALUE) *sect = NULL;
unsigned char *der = NULL, *p;
int derlen;
int i, is_set;
sk = sk_ASN1_TYPE_new_null();
if (section)
{
if (!cnf)
goto bad;
sect = X509V3_get_section(cnf, (char *)section);
if (!sect)
goto bad;
for (i = 0; i < sk_CONF_VALUE_num(sect); i++)
{
typ = ASN1_generate_v3(sk_CONF_VALUE_value(sect, i)->value, cnf);
if (!typ)
goto bad;
sk_ASN1_TYPE_push(sk, typ);
typ = NULL;
}
}
if (utype == V_ASN1_SET)
is_set = 1;
else
is_set = 0;
derlen = i2d_ASN1_SET_OF_ASN1_TYPE(sk, NULL, i2d_ASN1_TYPE, utype,
V_ASN1_UNIVERSAL, is_set);
der = OPENSSL_malloc(derlen);
p = der;
i2d_ASN1_SET_OF_ASN1_TYPE(sk, &p, i2d_ASN1_TYPE, utype,
V_ASN1_UNIVERSAL, is_set);
if (!(ret = ASN1_TYPE_new()))
goto bad;
if (!(ret->value.asn1_string = ASN1_STRING_type_new(utype)))
goto bad;
ret->type = utype;
ret->value.asn1_string->data = der;
ret->value.asn1_string->length = derlen;
der = NULL;
bad:
if (der)
OPENSSL_free(der);
if (sk)
sk_ASN1_TYPE_pop_free(sk, ASN1_TYPE_free);
if (typ)
ASN1_TYPE_free(typ);
if (sect)
X509V3_section_free(cnf, sect);
return ret;
}
static int append_exp(tag_exp_arg *arg, int exp_tag, int exp_class, int exp_constructed, int exp_pad, int imp_ok)
{
tag_exp_type *exp_tmp;
if ((arg->imp_tag != -1) && !imp_ok)
{
ASN1err(ASN1_F_APPEND_EXP, ASN1_R_ILLEGAL_IMPLICIT_TAG);
return 0;
}
if (arg->exp_count == ASN1_FLAG_EXP_MAX)
{
ASN1err(ASN1_F_APPEND_EXP, ASN1_R_DEPTH_EXCEEDED);
return 0;
}
exp_tmp = &arg->exp_list[arg->exp_count++];
if (arg->imp_tag != -1)
{
exp_tmp->exp_tag = arg->imp_tag;
exp_tmp->exp_class = arg->imp_class;
arg->imp_tag = -1;
arg->imp_class = -1;
}
else
{
exp_tmp->exp_tag = exp_tag;
exp_tmp->exp_class = exp_class;
}
exp_tmp->exp_constructed = exp_constructed;
exp_tmp->exp_pad = exp_pad;
return 1;
}
static int asn1_str2tag(const char *tagstr, int len)
{
unsigned int i;
static struct tag_name_st *tntmp, tnst [] = {
ASN1_GEN_STR("BOOL", V_ASN1_BOOLEAN),
ASN1_GEN_STR("BOOLEAN", V_ASN1_BOOLEAN),
ASN1_GEN_STR("NULL", V_ASN1_NULL),
ASN1_GEN_STR("INT", V_ASN1_INTEGER),
ASN1_GEN_STR("INTEGER", V_ASN1_INTEGER),
ASN1_GEN_STR("ENUM", V_ASN1_ENUMERATED),
ASN1_GEN_STR("ENUMERATED", V_ASN1_ENUMERATED),
ASN1_GEN_STR("OID", V_ASN1_OBJECT),
ASN1_GEN_STR("OBJECT", V_ASN1_OBJECT),
ASN1_GEN_STR("UTCTIME", V_ASN1_UTCTIME),
ASN1_GEN_STR("UTC", V_ASN1_UTCTIME),
ASN1_GEN_STR("GENERALIZEDTIME", V_ASN1_GENERALIZEDTIME),
ASN1_GEN_STR("GENTIME", V_ASN1_GENERALIZEDTIME),
ASN1_GEN_STR("OCT", V_ASN1_OCTET_STRING),
ASN1_GEN_STR("OCTETSTRING", V_ASN1_OCTET_STRING),
ASN1_GEN_STR("BITSTR", V_ASN1_BIT_STRING),
ASN1_GEN_STR("BITSTRING", V_ASN1_BIT_STRING),
ASN1_GEN_STR("UNIVERSALSTRING", V_ASN1_UNIVERSALSTRING),
ASN1_GEN_STR("UNIV", V_ASN1_UNIVERSALSTRING),
ASN1_GEN_STR("IA5", V_ASN1_IA5STRING),
ASN1_GEN_STR("IA5STRING", V_ASN1_IA5STRING),
ASN1_GEN_STR("UTF8", V_ASN1_UTF8STRING),
ASN1_GEN_STR("UTF8String", V_ASN1_UTF8STRING),
ASN1_GEN_STR("BMP", V_ASN1_BMPSTRING),
ASN1_GEN_STR("BMPSTRING", V_ASN1_BMPSTRING),
ASN1_GEN_STR("VISIBLESTRING", V_ASN1_VISIBLESTRING),
ASN1_GEN_STR("VISIBLE", V_ASN1_VISIBLESTRING),
ASN1_GEN_STR("PRINTABLESTRING", V_ASN1_PRINTABLESTRING),
ASN1_GEN_STR("PRINTABLE", V_ASN1_PRINTABLESTRING),
ASN1_GEN_STR("T61", V_ASN1_T61STRING),
ASN1_GEN_STR("T61STRING", V_ASN1_T61STRING),
ASN1_GEN_STR("TELETEXSTRING", V_ASN1_T61STRING),
ASN1_GEN_STR("GeneralString", V_ASN1_GENERALSTRING),
ASN1_GEN_STR("GENSTR", V_ASN1_GENERALSTRING),
ASN1_GEN_STR("SEQUENCE", V_ASN1_SEQUENCE),
ASN1_GEN_STR("SEQ", V_ASN1_SEQUENCE),
ASN1_GEN_STR("SET", V_ASN1_SET),
ASN1_GEN_STR("EXP", ASN1_GEN_FLAG_EXP),
ASN1_GEN_STR("EXPLICIT", ASN1_GEN_FLAG_EXP),
ASN1_GEN_STR("IMP", ASN1_GEN_FLAG_IMP),
ASN1_GEN_STR("IMPLICIT", ASN1_GEN_FLAG_IMP),
ASN1_GEN_STR("OCTWRAP", ASN1_GEN_FLAG_OCTWRAP),
ASN1_GEN_STR("SEQWRAP", ASN1_GEN_FLAG_SEQWRAP),
ASN1_GEN_STR("SETWRAP", ASN1_GEN_FLAG_SETWRAP),
ASN1_GEN_STR("BITWRAP", ASN1_GEN_FLAG_BITWRAP),
ASN1_GEN_STR("FORM", ASN1_GEN_FLAG_FORMAT),
ASN1_GEN_STR("FORMAT", ASN1_GEN_FLAG_FORMAT),
};
if (len == -1)
len = strlen(tagstr);
tntmp = tnst;
for (i = 0; i < sizeof(tnst) / sizeof(struct tag_name_st); i++, tntmp++)
{
if ((len == tntmp->len) && !strncmp(tntmp->strnam, tagstr, len))
return tntmp->tag;
}
return -1;
}
static ASN1_TYPE *asn1_str2type(const char *str, int format, int utype)
{
ASN1_TYPE *atmp = NULL;
CONF_VALUE vtmp;
unsigned char *rdata;
long rdlen;
int no_unused = 1;
if (!(atmp = ASN1_TYPE_new()))
{
ASN1err(ASN1_F_ASN1_STR2TYPE, ERR_R_MALLOC_FAILURE);
return NULL;
}
if (!str)
str = "";
switch(utype)
{
case V_ASN1_NULL:
if (str && *str)
{
ASN1err(ASN1_F_ASN1_STR2TYPE, ASN1_R_ILLEGAL_NULL_VALUE);
goto bad_form;
}
break;
case V_ASN1_BOOLEAN:
if (format != ASN1_GEN_FORMAT_ASCII)
{
ASN1err(ASN1_F_ASN1_STR2TYPE, ASN1_R_NOT_ASCII_FORMAT);
goto bad_form;
}
vtmp.value = (char *)str;
if (!X509V3_get_value_bool(&vtmp, &atmp->value.boolean))
{
ASN1err(ASN1_F_ASN1_STR2TYPE, ASN1_R_ILLEGAL_BOOLEAN);
goto bad_str;
}
break;
case V_ASN1_INTEGER:
case V_ASN1_ENUMERATED:
if (format != ASN1_GEN_FORMAT_ASCII)
{
ASN1err(ASN1_F_ASN1_STR2TYPE, ASN1_R_INTEGER_NOT_ASCII_FORMAT);
goto bad_form;
}
if (!(atmp->value.integer = s2i_ASN1_INTEGER(NULL, (char *)str)))
{
ASN1err(ASN1_F_ASN1_STR2TYPE, ASN1_R_ILLEGAL_INTEGER);
goto bad_str;
}
break;
case V_ASN1_OBJECT:
if (format != ASN1_GEN_FORMAT_ASCII)
{
ASN1err(ASN1_F_ASN1_STR2TYPE, ASN1_R_OBJECT_NOT_ASCII_FORMAT);
goto bad_form;
}
if (!(atmp->value.object = OBJ_txt2obj(str, 0)))
{
ASN1err(ASN1_F_ASN1_STR2TYPE, ASN1_R_ILLEGAL_OBJECT);
goto bad_str;
}
break;
case V_ASN1_UTCTIME:
case V_ASN1_GENERALIZEDTIME:
if (format != ASN1_GEN_FORMAT_ASCII)
{
ASN1err(ASN1_F_ASN1_STR2TYPE, ASN1_R_TIME_NOT_ASCII_FORMAT);
goto bad_form;
}
if (!(atmp->value.asn1_string = ASN1_STRING_new()))
{
ASN1err(ASN1_F_ASN1_STR2TYPE, ERR_R_MALLOC_FAILURE);
goto bad_str;
}
if (!ASN1_STRING_set(atmp->value.asn1_string, str, -1))
{
ASN1err(ASN1_F_ASN1_STR2TYPE, ERR_R_MALLOC_FAILURE);
goto bad_str;
}
atmp->value.asn1_string->type = utype;
if (!ASN1_TIME_check(atmp->value.asn1_string))
{
ASN1err(ASN1_F_ASN1_STR2TYPE, ASN1_R_ILLEGAL_TIME_VALUE);
goto bad_str;
}
break;
case V_ASN1_BMPSTRING:
case V_ASN1_PRINTABLESTRING:
case V_ASN1_IA5STRING:
case V_ASN1_T61STRING:
case V_ASN1_UTF8STRING:
case V_ASN1_VISIBLESTRING:
case V_ASN1_UNIVERSALSTRING:
case V_ASN1_GENERALSTRING:
if (format == ASN1_GEN_FORMAT_ASCII)
format = MBSTRING_ASC;
else if (format == ASN1_GEN_FORMAT_UTF8)
format = MBSTRING_UTF8;
else
{
ASN1err(ASN1_F_ASN1_STR2TYPE, ASN1_R_ILLEGAL_FORMAT);
goto bad_form;
}
if (ASN1_mbstring_copy(&atmp->value.asn1_string, (unsigned char *)str,
-1, format, ASN1_tag2bit(utype)) <= 0)
{
ASN1err(ASN1_F_ASN1_STR2TYPE, ERR_R_MALLOC_FAILURE);
goto bad_str;
}
break;
case V_ASN1_BIT_STRING:
case V_ASN1_OCTET_STRING:
if (!(atmp->value.asn1_string = ASN1_STRING_new()))
{
ASN1err(ASN1_F_ASN1_STR2TYPE, ERR_R_MALLOC_FAILURE);
goto bad_form;
}
if (format == ASN1_GEN_FORMAT_HEX)
{
if (!(rdata = string_to_hex((char *)str, &rdlen)))
{
ASN1err(ASN1_F_ASN1_STR2TYPE, ASN1_R_ILLEGAL_HEX);
goto bad_str;
}
atmp->value.asn1_string->data = rdata;
atmp->value.asn1_string->length = rdlen;
atmp->value.asn1_string->type = utype;
}
else if (format == ASN1_GEN_FORMAT_ASCII)
ASN1_STRING_set(atmp->value.asn1_string, str, -1);
else if ((format == ASN1_GEN_FORMAT_BITLIST) && (utype == V_ASN1_BIT_STRING))
{
if (!CONF_parse_list(str, ',', 1, bitstr_cb, atmp->value.bit_string))
{
ASN1err(ASN1_F_ASN1_STR2TYPE, ASN1_R_LIST_ERROR);
goto bad_str;
}
no_unused = 0;
}
else
{
ASN1err(ASN1_F_ASN1_STR2TYPE, ASN1_R_ILLEGAL_BITSTRING_FORMAT);
goto bad_form;
}
if ((utype == V_ASN1_BIT_STRING) && no_unused)
{
atmp->value.asn1_string->flags
&= ~(ASN1_STRING_FLAG_BITS_LEFT|0x07);
atmp->value.asn1_string->flags
|= ASN1_STRING_FLAG_BITS_LEFT;
}
break;
default:
ASN1err(ASN1_F_ASN1_STR2TYPE, ASN1_R_UNSUPPORTED_TYPE);
goto bad_str;
break;
}
atmp->type = utype;
return atmp;
bad_str:
ERR_add_error_data(2, "string=", str);
bad_form:
ASN1_TYPE_free(atmp);
return NULL;
}
static int bitstr_cb(const char *elem, int len, void *bitstr)
{
long bitnum;
char *eptr;
if (!elem)
return 0;
bitnum = strtoul(elem, &eptr, 10);
if (eptr && *eptr && (eptr != elem + len))
return 0;
if (bitnum < 0)
{
ASN1err(ASN1_F_BITSTR_CB, ASN1_R_INVALID_NUMBER);
return 0;
}
if (!ASN1_BIT_STRING_set_bit(bitstr, bitnum, 1))
{
ASN1err(ASN1_F_BITSTR_CB, ERR_R_MALLOC_FAILURE);
return 0;
}
return 1;
}
