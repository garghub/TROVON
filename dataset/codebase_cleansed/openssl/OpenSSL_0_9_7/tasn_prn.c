int ASN1_item_print(BIO *out, void *fld, int indent, const ASN1_ITEM *it)
{
return asn1_item_print_nm(out, fld, indent, it, it->sname);
}
static int asn1_item_print_nm(BIO *out, void *fld, int indent, const ASN1_ITEM *it, const char *name)
{
ASN1_STRING *str;
const ASN1_TEMPLATE *tt;
void *tmpfld;
int i;
if(!fld) {
BIO_printf(out, "%*s%s ABSENT\n", indent, "", name);
return 1;
}
switch(it->itype) {
case ASN1_ITYPE_PRIMITIVE:
if(it->templates)
return ASN1_template_print(out, fld, indent, it->templates);
return asn1_primitive_print(out, fld, it->utype, indent, name);
break;
case ASN1_ITYPE_MSTRING:
str = fld;
return asn1_primitive_print(out, fld, str->type, indent, name);
case ASN1_ITYPE_EXTERN:
BIO_printf(out, "%*s%s:EXTERNAL TYPE %s %s\n", indent, "", name, it->sname, fld ? "" : "ABSENT");
return 1;
case ASN1_ITYPE_COMPAT:
BIO_printf(out, "%*s%s:COMPATIBLE TYPE %s %s\n", indent, "", name, it->sname, fld ? "" : "ABSENT");
return 1;
case ASN1_ITYPE_CHOICE:
i = asn1_get_choice_selector(fld, it);
if((i < 0) || (i >= it->tcount)) {
BIO_printf(out, "%s selector [%d] out of range\n", it->sname, i);
return 1;
}
tt = it->templates + i;
tmpfld = asn1_get_field(fld, tt);
return ASN1_template_print(out, tmpfld, indent, tt);
case ASN1_ITYPE_SEQUENCE:
BIO_printf(out, "%*s%s {\n", indent, "", name);
for(i = 0, tt = it->templates; i < it->tcount; i++, tt++) {
tmpfld = asn1_get_field(fld, tt);
ASN1_template_print(out, tmpfld, indent + 2, tt);
}
BIO_printf(out, "%*s}\n", indent, "");
return 1;
default:
return 0;
}
}
int ASN1_template_print(BIO *out, void *fld, int indent, const ASN1_TEMPLATE *tt)
{
int i, flags;
#if 0
if(!fld) return 0;
#endif
flags = tt->flags;
if(flags & ASN1_TFLG_SK_MASK) {
char *tname;
void *skitem;
if(flags & ASN1_TFLG_SET_OF) tname = "SET";
else tname = "SEQUENCE";
if(fld) {
BIO_printf(out, "%*s%s OF %s {\n", indent, "", tname, tt->field_name);
for(i = 0; i < sk_num(fld); i++) {
skitem = sk_value(fld, i);
asn1_item_print_nm(out, skitem, indent + 2, tt->item, "");
}
BIO_printf(out, "%*s}\n", indent, "");
} else
BIO_printf(out, "%*s%s OF %s ABSENT\n", indent, "", tname, tt->field_name);
return 1;
}
return asn1_item_print_nm(out, fld, indent, tt->item, tt->field_name);
}
static int asn1_primitive_print(BIO *out, void *fld, long utype, int indent, const char *name)
{
ASN1_STRING *str = fld;
if(fld) {
if(utype == V_ASN1_BOOLEAN) {
int *bool = fld;
if(*bool == -1) printf("BOOL MISSING\n");
BIO_printf(out, "%*s%s:%s", indent, "", "BOOLEAN", *bool ? "TRUE" : "FALSE");
} else if((utype == V_ASN1_INTEGER)
|| (utype == V_ASN1_ENUMERATED)) {
char *s, *nm;
s = i2s_ASN1_INTEGER(NULL, fld);
if(utype == V_ASN1_INTEGER) nm = "INTEGER";
else nm = "ENUMERATED";
BIO_printf(out, "%*s%s:%s", indent, "", nm, s);
OPENSSL_free(s);
} else if(utype == V_ASN1_NULL) {
BIO_printf(out, "%*s%s", indent, "", "NULL");
} else if(utype == V_ASN1_UTCTIME) {
BIO_printf(out, "%*s%s:%s:", indent, "", name, "UTCTIME");
ASN1_UTCTIME_print(out, str);
} else if(utype == V_ASN1_GENERALIZEDTIME) {
BIO_printf(out, "%*s%s:%s:", indent, "", name, "GENERALIZEDTIME");
ASN1_GENERALIZEDTIME_print(out, str);
} else if(utype == V_ASN1_OBJECT) {
char objbuf[80], *ln;
ln = OBJ_nid2ln(OBJ_obj2nid(fld));
if(!ln) ln = "";
OBJ_obj2txt(objbuf, sizeof objbuf, fld, 1);
BIO_printf(out, "%*s%s:%s (%s)", indent, "", "OBJECT", ln, objbuf);
} else {
BIO_printf(out, "%*s%s:", indent, "", name);
ASN1_STRING_print_ex(out, str, ASN1_STRFLGS_DUMP_UNKNOWN|ASN1_STRFLGS_SHOW_TYPE);
}
BIO_printf(out, "\n");
} else BIO_printf(out, "%*s%s [ABSENT]\n", indent, "", name);
return 1;
}
