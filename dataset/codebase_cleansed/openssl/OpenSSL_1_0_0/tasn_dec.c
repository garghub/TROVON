unsigned long ASN1_tag2bit(int tag)
{
if ((tag < 0) || (tag > 30)) return 0;
return tag2bit[tag];
}
ASN1_VALUE *ASN1_item_d2i(ASN1_VALUE **pval,
const unsigned char **in, long len, const ASN1_ITEM *it)
{
ASN1_TLC c;
ASN1_VALUE *ptmpval = NULL;
if (!pval)
pval = &ptmpval;
asn1_tlc_clear_nc(&c);
if (ASN1_item_ex_d2i(pval, in, len, it, -1, 0, 0, &c) > 0)
return *pval;
return NULL;
}
int ASN1_template_d2i(ASN1_VALUE **pval,
const unsigned char **in, long len, const ASN1_TEMPLATE *tt)
{
ASN1_TLC c;
asn1_tlc_clear_nc(&c);
return asn1_template_ex_d2i(pval, in, len, tt, 0, &c);
}
int ASN1_item_ex_d2i(ASN1_VALUE **pval, const unsigned char **in, long len,
const ASN1_ITEM *it,
int tag, int aclass, char opt, ASN1_TLC *ctx)
{
const ASN1_TEMPLATE *tt, *errtt = NULL;
const ASN1_COMPAT_FUNCS *cf;
const ASN1_EXTERN_FUNCS *ef;
const ASN1_AUX *aux = it->funcs;
ASN1_aux_cb *asn1_cb;
const unsigned char *p = NULL, *q;
unsigned char *wp=NULL;
unsigned char imphack = 0, oclass;
char seq_eoc, seq_nolen, cst, isopt;
long tmplen;
int i;
int otag;
int ret = 0;
ASN1_VALUE *pchval, **pchptr, *ptmpval;
if (!pval)
return 0;
if (aux && aux->asn1_cb)
asn1_cb = aux->asn1_cb;
else asn1_cb = 0;
switch(it->itype)
{
case ASN1_ITYPE_PRIMITIVE:
if (it->templates)
{
if ((tag != -1) || opt)
{
ASN1err(ASN1_F_ASN1_ITEM_EX_D2I,
ASN1_R_ILLEGAL_OPTIONS_ON_ITEM_TEMPLATE);
goto err;
}
return asn1_template_ex_d2i(pval, in, len,
it->templates, opt, ctx);
}
return asn1_d2i_ex_primitive(pval, in, len, it,
tag, aclass, opt, ctx);
break;
case ASN1_ITYPE_MSTRING:
p = *in;
ret = asn1_check_tlen(NULL, &otag, &oclass, NULL, NULL,
&p, len, -1, 0, 1, ctx);
if (!ret)
{
ASN1err(ASN1_F_ASN1_ITEM_EX_D2I,
ERR_R_NESTED_ASN1_ERROR);
goto err;
}
if (oclass != V_ASN1_UNIVERSAL)
{
if (opt) return -1;
ASN1err(ASN1_F_ASN1_ITEM_EX_D2I,
ASN1_R_MSTRING_NOT_UNIVERSAL);
goto err;
}
if (!(ASN1_tag2bit(otag) & it->utype))
{
if (opt)
return -1;
ASN1err(ASN1_F_ASN1_ITEM_EX_D2I,
ASN1_R_MSTRING_WRONG_TAG);
goto err;
}
return asn1_d2i_ex_primitive(pval, in, len,
it, otag, 0, 0, ctx);
case ASN1_ITYPE_EXTERN:
ef = it->funcs;
return ef->asn1_ex_d2i(pval, in, len,
it, tag, aclass, opt, ctx);
case ASN1_ITYPE_COMPAT:
cf = it->funcs;
if (opt)
{
int exptag;
p = *in;
if (tag == -1)
exptag = it->utype;
else exptag = tag;
ret = asn1_check_tlen(NULL, NULL, NULL, NULL, NULL,
&p, len, exptag, aclass, 1, ctx);
if (!ret)
{
ASN1err(ASN1_F_ASN1_ITEM_EX_D2I,
ERR_R_NESTED_ASN1_ERROR);
goto err;
}
if (ret == -1)
return -1;
}
if (tag != -1)
{
wp = *(unsigned char **)in;
imphack = *wp;
if (p == NULL)
{
ASN1err(ASN1_F_ASN1_ITEM_EX_D2I,
ERR_R_NESTED_ASN1_ERROR);
goto err;
}
*wp = (unsigned char)((*p & V_ASN1_CONSTRUCTED)
| it->utype);
}
ptmpval = cf->asn1_d2i(pval, in, len);
if (tag != -1)
*wp = imphack;
if (ptmpval)
return 1;
ASN1err(ASN1_F_ASN1_ITEM_EX_D2I, ERR_R_NESTED_ASN1_ERROR);
goto err;
case ASN1_ITYPE_CHOICE:
if (asn1_cb && !asn1_cb(ASN1_OP_D2I_PRE, pval, it, NULL))
goto auxerr;
if (!*pval && !ASN1_item_ex_new(pval, it))
{
ASN1err(ASN1_F_ASN1_ITEM_EX_D2I,
ERR_R_NESTED_ASN1_ERROR);
goto err;
}
pchval = NULL;
p = *in;
for (i = 0, tt=it->templates; i < it->tcount; i++, tt++)
{
pchptr = asn1_get_field_ptr(pval, tt);
ret = asn1_template_ex_d2i(pchptr, &p, len, tt, 1, ctx);
if (ret == -1)
continue;
if (ret > 0)
break;
errtt = tt;
ASN1err(ASN1_F_ASN1_ITEM_EX_D2I,
ERR_R_NESTED_ASN1_ERROR);
goto err;
}
if (i == it->tcount)
{
if (opt)
{
ASN1_item_ex_free(pval, it);
return -1;
}
ASN1err(ASN1_F_ASN1_ITEM_EX_D2I,
ASN1_R_NO_MATCHING_CHOICE_TYPE);
goto err;
}
asn1_set_choice_selector(pval, i, it);
*in = p;
if (asn1_cb && !asn1_cb(ASN1_OP_D2I_POST, pval, it, NULL))
goto auxerr;
return 1;
case ASN1_ITYPE_NDEF_SEQUENCE:
case ASN1_ITYPE_SEQUENCE:
p = *in;
tmplen = len;
if (tag == -1)
{
tag = V_ASN1_SEQUENCE;
aclass = V_ASN1_UNIVERSAL;
}
ret = asn1_check_tlen(&len, NULL, NULL, &seq_eoc, &cst,
&p, len, tag, aclass, opt, ctx);
if (!ret)
{
ASN1err(ASN1_F_ASN1_ITEM_EX_D2I,
ERR_R_NESTED_ASN1_ERROR);
goto err;
}
else if (ret == -1)
return -1;
if (aux && (aux->flags & ASN1_AFLG_BROKEN))
{
len = tmplen - (p - *in);
seq_nolen = 1;
}
else seq_nolen = seq_eoc;
if (!cst)
{
ASN1err(ASN1_F_ASN1_ITEM_EX_D2I,
ASN1_R_SEQUENCE_NOT_CONSTRUCTED);
goto err;
}
if (!*pval && !ASN1_item_ex_new(pval, it))
{
ASN1err(ASN1_F_ASN1_ITEM_EX_D2I,
ERR_R_NESTED_ASN1_ERROR);
goto err;
}
if (asn1_cb && !asn1_cb(ASN1_OP_D2I_PRE, pval, it, NULL))
goto auxerr;
for (i = 0, tt = it->templates; i < it->tcount; i++, tt++)
{
const ASN1_TEMPLATE *seqtt;
ASN1_VALUE **pseqval;
seqtt = asn1_do_adb(pval, tt, 1);
if (!seqtt)
goto err;
pseqval = asn1_get_field_ptr(pval, seqtt);
if (!len)
break;
q = p;
if (asn1_check_eoc(&p, len))
{
if (!seq_eoc)
{
ASN1err(ASN1_F_ASN1_ITEM_EX_D2I,
ASN1_R_UNEXPECTED_EOC);
goto err;
}
len -= p - q;
seq_eoc = 0;
q = p;
break;
}
if (i == (it->tcount - 1))
isopt = 0;
else isopt = (char)(seqtt->flags & ASN1_TFLG_OPTIONAL);
ret = asn1_template_ex_d2i(pseqval, &p, len,
seqtt, isopt, ctx);
if (!ret)
{
errtt = seqtt;
goto err;
}
else if (ret == -1)
{
ASN1_template_free(pseqval, seqtt);
continue;
}
len -= p - q;
}
if (seq_eoc && !asn1_check_eoc(&p, len))
{
ASN1err(ASN1_F_ASN1_ITEM_EX_D2I, ASN1_R_MISSING_EOC);
goto err;
}
if (!seq_nolen && len)
{
ASN1err(ASN1_F_ASN1_ITEM_EX_D2I,
ASN1_R_SEQUENCE_LENGTH_MISMATCH);
goto err;
}
for (; i < it->tcount; tt++, i++)
{
const ASN1_TEMPLATE *seqtt;
seqtt = asn1_do_adb(pval, tt, 1);
if (!seqtt)
goto err;
if (seqtt->flags & ASN1_TFLG_OPTIONAL)
{
ASN1_VALUE **pseqval;
pseqval = asn1_get_field_ptr(pval, seqtt);
ASN1_template_free(pseqval, seqtt);
}
else
{
errtt = seqtt;
ASN1err(ASN1_F_ASN1_ITEM_EX_D2I,
ASN1_R_FIELD_MISSING);
goto err;
}
}
if (!asn1_enc_save(pval, *in, p - *in, it))
goto auxerr;
*in = p;
if (asn1_cb && !asn1_cb(ASN1_OP_D2I_POST, pval, it, NULL))
goto auxerr;
return 1;
default:
return 0;
}
auxerr:
ASN1err(ASN1_F_ASN1_ITEM_EX_D2I, ASN1_R_AUX_ERROR);
err:
ASN1_item_ex_free(pval, it);
if (errtt)
ERR_add_error_data(4, "Field=", errtt->field_name,
", Type=", it->sname);
else
ERR_add_error_data(2, "Type=", it->sname);
return 0;
}
static int asn1_template_ex_d2i(ASN1_VALUE **val,
const unsigned char **in, long inlen,
const ASN1_TEMPLATE *tt, char opt,
ASN1_TLC *ctx)
{
int flags, aclass;
int ret;
long len;
const unsigned char *p, *q;
char exp_eoc;
if (!val)
return 0;
flags = tt->flags;
aclass = flags & ASN1_TFLG_TAG_CLASS;
p = *in;
if (flags & ASN1_TFLG_EXPTAG)
{
char cst;
ret = asn1_check_tlen(&len, NULL, NULL, &exp_eoc, &cst,
&p, inlen, tt->tag, aclass, opt, ctx);
q = p;
if (!ret)
{
ASN1err(ASN1_F_ASN1_TEMPLATE_EX_D2I,
ERR_R_NESTED_ASN1_ERROR);
return 0;
}
else if (ret == -1)
return -1;
if (!cst)
{
ASN1err(ASN1_F_ASN1_TEMPLATE_EX_D2I,
ASN1_R_EXPLICIT_TAG_NOT_CONSTRUCTED);
return 0;
}
ret = asn1_template_noexp_d2i(val, &p, len, tt, 0, ctx);
if (!ret)
{
ASN1err(ASN1_F_ASN1_TEMPLATE_EX_D2I,
ERR_R_NESTED_ASN1_ERROR);
return 0;
}
len -= p - q;
if (exp_eoc)
{
if (!asn1_check_eoc(&p, len))
{
ASN1err(ASN1_F_ASN1_TEMPLATE_EX_D2I,
ASN1_R_MISSING_EOC);
goto err;
}
}
else
{
if (len)
{
ASN1err(ASN1_F_ASN1_TEMPLATE_EX_D2I,
ASN1_R_EXPLICIT_LENGTH_MISMATCH);
goto err;
}
}
}
else
return asn1_template_noexp_d2i(val, in, inlen,
tt, opt, ctx);
*in = p;
return 1;
err:
ASN1_template_free(val, tt);
return 0;
}
static int asn1_template_noexp_d2i(ASN1_VALUE **val,
const unsigned char **in, long len,
const ASN1_TEMPLATE *tt, char opt,
ASN1_TLC *ctx)
{
int flags, aclass;
int ret;
const unsigned char *p, *q;
if (!val)
return 0;
flags = tt->flags;
aclass = flags & ASN1_TFLG_TAG_CLASS;
p = *in;
q = p;
if (flags & ASN1_TFLG_SK_MASK)
{
int sktag, skaclass;
char sk_eoc;
if (flags & ASN1_TFLG_IMPTAG)
{
sktag = tt->tag;
skaclass = aclass;
}
else
{
skaclass = V_ASN1_UNIVERSAL;
if (flags & ASN1_TFLG_SET_OF)
sktag = V_ASN1_SET;
else
sktag = V_ASN1_SEQUENCE;
}
ret = asn1_check_tlen(&len, NULL, NULL, &sk_eoc, NULL,
&p, len, sktag, skaclass, opt, ctx);
if (!ret)
{
ASN1err(ASN1_F_ASN1_TEMPLATE_NOEXP_D2I,
ERR_R_NESTED_ASN1_ERROR);
return 0;
}
else if (ret == -1)
return -1;
if (!*val)
*val = (ASN1_VALUE *)sk_new_null();
else
{
STACK_OF(ASN1_VALUE) *sktmp
= (STACK_OF(ASN1_VALUE) *)*val;
ASN1_VALUE *vtmp;
while(sk_ASN1_VALUE_num(sktmp) > 0)
{
vtmp = sk_ASN1_VALUE_pop(sktmp);
ASN1_item_ex_free(&vtmp,
ASN1_ITEM_ptr(tt->item));
}
}
if (!*val)
{
ASN1err(ASN1_F_ASN1_TEMPLATE_NOEXP_D2I,
ERR_R_MALLOC_FAILURE);
goto err;
}
while(len > 0)
{
ASN1_VALUE *skfield;
q = p;
if (asn1_check_eoc(&p, len))
{
if (!sk_eoc)
{
ASN1err(ASN1_F_ASN1_TEMPLATE_NOEXP_D2I,
ASN1_R_UNEXPECTED_EOC);
goto err;
}
len -= p - q;
sk_eoc = 0;
break;
}
skfield = NULL;
if (!ASN1_item_ex_d2i(&skfield, &p, len,
ASN1_ITEM_ptr(tt->item),
-1, 0, 0, ctx))
{
ASN1err(ASN1_F_ASN1_TEMPLATE_NOEXP_D2I,
ERR_R_NESTED_ASN1_ERROR);
goto err;
}
len -= p - q;
if (!sk_ASN1_VALUE_push((STACK_OF(ASN1_VALUE) *)*val,
skfield))
{
ASN1err(ASN1_F_ASN1_TEMPLATE_NOEXP_D2I,
ERR_R_MALLOC_FAILURE);
goto err;
}
}
if (sk_eoc)
{
ASN1err(ASN1_F_ASN1_TEMPLATE_NOEXP_D2I, ASN1_R_MISSING_EOC);
goto err;
}
}
else if (flags & ASN1_TFLG_IMPTAG)
{
ret = ASN1_item_ex_d2i(val, &p, len,
ASN1_ITEM_ptr(tt->item), tt->tag, aclass, opt, ctx);
if (!ret)
{
ASN1err(ASN1_F_ASN1_TEMPLATE_NOEXP_D2I,
ERR_R_NESTED_ASN1_ERROR);
goto err;
}
else if (ret == -1)
return -1;
}
else
{
ret = ASN1_item_ex_d2i(val, &p, len, ASN1_ITEM_ptr(tt->item),
-1, 0, opt, ctx);
if (!ret)
{
ASN1err(ASN1_F_ASN1_TEMPLATE_NOEXP_D2I,
ERR_R_NESTED_ASN1_ERROR);
goto err;
}
else if (ret == -1)
return -1;
}
*in = p;
return 1;
err:
ASN1_template_free(val, tt);
return 0;
}
static int asn1_d2i_ex_primitive(ASN1_VALUE **pval,
const unsigned char **in, long inlen,
const ASN1_ITEM *it,
int tag, int aclass, char opt, ASN1_TLC *ctx)
{
int ret = 0, utype;
long plen;
char cst, inf, free_cont = 0;
const unsigned char *p;
BUF_MEM buf;
const unsigned char *cont = NULL;
long len;
if (!pval)
{
ASN1err(ASN1_F_ASN1_D2I_EX_PRIMITIVE, ASN1_R_ILLEGAL_NULL);
return 0;
}
if (it->itype == ASN1_ITYPE_MSTRING)
{
utype = tag;
tag = -1;
}
else
utype = it->utype;
if (utype == V_ASN1_ANY)
{
unsigned char oclass;
if (tag >= 0)
{
ASN1err(ASN1_F_ASN1_D2I_EX_PRIMITIVE,
ASN1_R_ILLEGAL_TAGGED_ANY);
return 0;
}
if (opt)
{
ASN1err(ASN1_F_ASN1_D2I_EX_PRIMITIVE,
ASN1_R_ILLEGAL_OPTIONAL_ANY);
return 0;
}
p = *in;
ret = asn1_check_tlen(NULL, &utype, &oclass, NULL, NULL,
&p, inlen, -1, 0, 0, ctx);
if (!ret)
{
ASN1err(ASN1_F_ASN1_D2I_EX_PRIMITIVE,
ERR_R_NESTED_ASN1_ERROR);
return 0;
}
if (oclass != V_ASN1_UNIVERSAL)
utype = V_ASN1_OTHER;
}
if (tag == -1)
{
tag = utype;
aclass = V_ASN1_UNIVERSAL;
}
p = *in;
ret = asn1_check_tlen(&plen, NULL, NULL, &inf, &cst,
&p, inlen, tag, aclass, opt, ctx);
if (!ret)
{
ASN1err(ASN1_F_ASN1_D2I_EX_PRIMITIVE, ERR_R_NESTED_ASN1_ERROR);
return 0;
}
else if (ret == -1)
return -1;
ret = 0;
if ((utype == V_ASN1_SEQUENCE)
|| (utype == V_ASN1_SET) || (utype == V_ASN1_OTHER))
{
if (utype == V_ASN1_OTHER)
{
asn1_tlc_clear(ctx);
}
else if (!cst)
{
ASN1err(ASN1_F_ASN1_D2I_EX_PRIMITIVE,
ASN1_R_TYPE_NOT_CONSTRUCTED);
return 0;
}
cont = *in;
if (inf)
{
if (!asn1_find_end(&p, plen, inf))
goto err;
len = p - cont;
}
else
{
len = p - cont + plen;
p += plen;
buf.data = NULL;
}
}
else if (cst)
{
buf.length = 0;
buf.max = 0;
buf.data = NULL;
if (!asn1_collect(&buf, &p, plen, inf, -1, V_ASN1_UNIVERSAL, 0))
{
free_cont = 1;
goto err;
}
len = buf.length;
if (!BUF_MEM_grow_clean(&buf, len + 1))
{
ASN1err(ASN1_F_ASN1_D2I_EX_PRIMITIVE,
ERR_R_MALLOC_FAILURE);
return 0;
}
buf.data[len] = 0;
cont = (const unsigned char *)buf.data;
free_cont = 1;
}
else
{
cont = p;
len = plen;
p += plen;
}
if (!asn1_ex_c2i(pval, cont, len, utype, &free_cont, it))
goto err;
*in = p;
ret = 1;
err:
if (free_cont && buf.data) OPENSSL_free(buf.data);
return ret;
}
int asn1_ex_c2i(ASN1_VALUE **pval, const unsigned char *cont, int len,
int utype, char *free_cont, const ASN1_ITEM *it)
{
ASN1_VALUE **opval = NULL;
ASN1_STRING *stmp;
ASN1_TYPE *typ = NULL;
int ret = 0;
const ASN1_PRIMITIVE_FUNCS *pf;
ASN1_INTEGER **tint;
pf = it->funcs;
if (pf && pf->prim_c2i)
return pf->prim_c2i(pval, cont, len, utype, free_cont, it);
if (it->utype == V_ASN1_ANY)
{
if (!*pval)
{
typ = ASN1_TYPE_new();
if (typ == NULL)
goto err;
*pval = (ASN1_VALUE *)typ;
}
else
typ = (ASN1_TYPE *)*pval;
if (utype != typ->type)
ASN1_TYPE_set(typ, utype, NULL);
opval = pval;
pval = &typ->value.asn1_value;
}
switch(utype)
{
case V_ASN1_OBJECT:
if (!c2i_ASN1_OBJECT((ASN1_OBJECT **)pval, &cont, len))
goto err;
break;
case V_ASN1_NULL:
if (len)
{
ASN1err(ASN1_F_ASN1_EX_C2I,
ASN1_R_NULL_IS_WRONG_LENGTH);
goto err;
}
*pval = (ASN1_VALUE *)1;
break;
case V_ASN1_BOOLEAN:
if (len != 1)
{
ASN1err(ASN1_F_ASN1_EX_C2I,
ASN1_R_BOOLEAN_IS_WRONG_LENGTH);
goto err;
}
else
{
ASN1_BOOLEAN *tbool;
tbool = (ASN1_BOOLEAN *)pval;
*tbool = *cont;
}
break;
case V_ASN1_BIT_STRING:
if (!c2i_ASN1_BIT_STRING((ASN1_BIT_STRING **)pval, &cont, len))
goto err;
break;
case V_ASN1_INTEGER:
case V_ASN1_NEG_INTEGER:
case V_ASN1_ENUMERATED:
case V_ASN1_NEG_ENUMERATED:
tint = (ASN1_INTEGER **)pval;
if (!c2i_ASN1_INTEGER(tint, &cont, len))
goto err;
(*tint)->type = utype | ((*tint)->type & V_ASN1_NEG);
break;
case V_ASN1_OCTET_STRING:
case V_ASN1_NUMERICSTRING:
case V_ASN1_PRINTABLESTRING:
case V_ASN1_T61STRING:
case V_ASN1_VIDEOTEXSTRING:
case V_ASN1_IA5STRING:
case V_ASN1_UTCTIME:
case V_ASN1_GENERALIZEDTIME:
case V_ASN1_GRAPHICSTRING:
case V_ASN1_VISIBLESTRING:
case V_ASN1_GENERALSTRING:
case V_ASN1_UNIVERSALSTRING:
case V_ASN1_BMPSTRING:
case V_ASN1_UTF8STRING:
case V_ASN1_OTHER:
case V_ASN1_SET:
case V_ASN1_SEQUENCE:
default:
if (utype == V_ASN1_BMPSTRING && (len & 1))
{
ASN1err(ASN1_F_ASN1_EX_C2I,
ASN1_R_BMPSTRING_IS_WRONG_LENGTH);
goto err;
}
if (utype == V_ASN1_UNIVERSALSTRING && (len & 3))
{
ASN1err(ASN1_F_ASN1_EX_C2I,
ASN1_R_UNIVERSALSTRING_IS_WRONG_LENGTH);
goto err;
}
if (!*pval)
{
stmp = ASN1_STRING_type_new(utype);
if (!stmp)
{
ASN1err(ASN1_F_ASN1_EX_C2I,
ERR_R_MALLOC_FAILURE);
goto err;
}
*pval = (ASN1_VALUE *)stmp;
}
else
{
stmp = (ASN1_STRING *)*pval;
stmp->type = utype;
}
if (*free_cont)
{
if (stmp->data)
OPENSSL_free(stmp->data);
stmp->data = (unsigned char *)cont;
stmp->length = len;
*free_cont = 0;
}
else
{
if (!ASN1_STRING_set(stmp, cont, len))
{
ASN1err(ASN1_F_ASN1_EX_C2I,
ERR_R_MALLOC_FAILURE);
ASN1_STRING_free(stmp);
*pval = NULL;
goto err;
}
}
break;
}
if (typ && (utype == V_ASN1_NULL))
typ->value.ptr = NULL;
ret = 1;
err:
if (!ret)
{
ASN1_TYPE_free(typ);
if (opval)
*opval = NULL;
}
return ret;
}
static int asn1_find_end(const unsigned char **in, long len, char inf)
{
int expected_eoc;
long plen;
const unsigned char *p = *in, *q;
if (inf == 0)
{
*in += len;
return 1;
}
expected_eoc = 1;
while (len > 0)
{
if(asn1_check_eoc(&p, len))
{
expected_eoc--;
if (expected_eoc == 0)
break;
len -= 2;
continue;
}
q = p;
if(!asn1_check_tlen(&plen, NULL, NULL, &inf, NULL, &p, len,
-1, 0, 0, NULL))
{
ASN1err(ASN1_F_ASN1_FIND_END, ERR_R_NESTED_ASN1_ERROR);
return 0;
}
if (inf)
expected_eoc++;
else
p += plen;
len -= p - q;
}
if (expected_eoc)
{
ASN1err(ASN1_F_ASN1_FIND_END, ASN1_R_MISSING_EOC);
return 0;
}
*in = p;
return 1;
}
static int asn1_collect(BUF_MEM *buf, const unsigned char **in, long len,
char inf, int tag, int aclass, int depth)
{
const unsigned char *p, *q;
long plen;
char cst, ininf;
p = *in;
inf &= 1;
if (!buf && !inf)
{
*in += len;
return 1;
}
while(len > 0)
{
q = p;
if (asn1_check_eoc(&p, len))
{
if (!inf)
{
ASN1err(ASN1_F_ASN1_COLLECT,
ASN1_R_UNEXPECTED_EOC);
return 0;
}
inf = 0;
break;
}
if (!asn1_check_tlen(&plen, NULL, NULL, &ininf, &cst, &p,
len, tag, aclass, 0, NULL))
{
ASN1err(ASN1_F_ASN1_COLLECT, ERR_R_NESTED_ASN1_ERROR);
return 0;
}
if (cst)
{
if (depth >= ASN1_MAX_STRING_NEST)
{
ASN1err(ASN1_F_ASN1_COLLECT,
ASN1_R_NESTED_ASN1_STRING);
return 0;
}
if (!asn1_collect(buf, &p, plen, ininf, tag, aclass,
depth + 1))
return 0;
}
else if (plen && !collect_data(buf, &p, plen))
return 0;
len -= p - q;
}
if (inf)
{
ASN1err(ASN1_F_ASN1_COLLECT, ASN1_R_MISSING_EOC);
return 0;
}
*in = p;
return 1;
}
static int collect_data(BUF_MEM *buf, const unsigned char **p, long plen)
{
int len;
if (buf)
{
len = buf->length;
if (!BUF_MEM_grow_clean(buf, len + plen))
{
ASN1err(ASN1_F_COLLECT_DATA, ERR_R_MALLOC_FAILURE);
return 0;
}
memcpy(buf->data + len, *p, plen);
}
*p += plen;
return 1;
}
static int asn1_check_eoc(const unsigned char **in, long len)
{
const unsigned char *p;
if (len < 2) return 0;
p = *in;
if (!p[0] && !p[1])
{
*in += 2;
return 1;
}
return 0;
}
static int asn1_check_tlen(long *olen, int *otag, unsigned char *oclass,
char *inf, char *cst,
const unsigned char **in, long len,
int exptag, int expclass, char opt,
ASN1_TLC *ctx)
{
int i;
int ptag, pclass;
long plen;
const unsigned char *p, *q;
p = *in;
q = p;
if (ctx && ctx->valid)
{
i = ctx->ret;
plen = ctx->plen;
pclass = ctx->pclass;
ptag = ctx->ptag;
p += ctx->hdrlen;
}
else
{
i = ASN1_get_object(&p, &plen, &ptag, &pclass, len);
if (ctx)
{
ctx->ret = i;
ctx->plen = plen;
ctx->pclass = pclass;
ctx->ptag = ptag;
ctx->hdrlen = p - q;
ctx->valid = 1;
if (!(i & 0x81) && ((plen + ctx->hdrlen) > len))
{
ASN1err(ASN1_F_ASN1_CHECK_TLEN,
ASN1_R_TOO_LONG);
asn1_tlc_clear(ctx);
return 0;
}
}
}
if (i & 0x80)
{
ASN1err(ASN1_F_ASN1_CHECK_TLEN, ASN1_R_BAD_OBJECT_HEADER);
asn1_tlc_clear(ctx);
return 0;
}
if (exptag >= 0)
{
if ((exptag != ptag) || (expclass != pclass))
{
if (opt) return -1;
asn1_tlc_clear(ctx);
ASN1err(ASN1_F_ASN1_CHECK_TLEN, ASN1_R_WRONG_TAG);
return 0;
}
asn1_tlc_clear(ctx);
}
if (i & 1)
plen = len - (p - q);
if (inf)
*inf = i & 1;
if (cst)
*cst = i & V_ASN1_CONSTRUCTED;
if (olen)
*olen = plen;
if (oclass)
*oclass = pclass;
if (otag)
*otag = ptag;
*in = p;
return 1;
}
