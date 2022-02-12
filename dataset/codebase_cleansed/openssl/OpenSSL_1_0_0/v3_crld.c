int set_dist_point_name(DIST_POINT_NAME **pdp, X509V3_CTX *ctx,
CONF_VALUE *cnf)
{
STACK_OF(GENERAL_NAME) *fnm = NULL;
STACK_OF(X509_NAME_ENTRY) *rnm = NULL;
if (!strncmp(cnf->name, "fullname", 9))
{
fnm = gnames_from_sectname(ctx, cnf->value);
if (!fnm)
goto err;
}
else if (!strcmp(cnf->name, "relativename"))
{
int ret;
STACK_OF(CONF_VALUE) *dnsect;
X509_NAME *nm;
nm = X509_NAME_new();
if (!nm)
return -1;
dnsect = X509V3_get_section(ctx, cnf->value);
if (!dnsect)
{
X509V3err(X509V3_F_SET_DIST_POINT_NAME,
X509V3_R_SECTION_NOT_FOUND);
return -1;
}
ret = X509V3_NAME_from_section(nm, dnsect, MBSTRING_ASC);
X509V3_section_free(ctx, dnsect);
rnm = nm->entries;
nm->entries = NULL;
X509_NAME_free(nm);
if (!ret || sk_X509_NAME_ENTRY_num(rnm) <= 0)
goto err;
if (sk_X509_NAME_ENTRY_value(rnm,
sk_X509_NAME_ENTRY_num(rnm) - 1)->set)
{
X509V3err(X509V3_F_SET_DIST_POINT_NAME,
X509V3_R_INVALID_MULTIPLE_RDNS);
goto err;
}
}
else
return 0;
if (*pdp)
{
X509V3err(X509V3_F_SET_DIST_POINT_NAME,
X509V3_R_DISTPOINT_ALREADY_SET);
goto err;
}
*pdp = DIST_POINT_NAME_new();
if (!*pdp)
goto err;
if (fnm)
{
(*pdp)->type = 0;
(*pdp)->name.fullname = fnm;
}
else
{
(*pdp)->type = 1;
(*pdp)->name.relativename = rnm;
}
return 1;
err:
if (fnm)
sk_GENERAL_NAME_pop_free(fnm, GENERAL_NAME_free);
if (rnm)
sk_X509_NAME_ENTRY_pop_free(rnm, X509_NAME_ENTRY_free);
return -1;
}
static int set_reasons(ASN1_BIT_STRING **preas, char *value)
{
STACK_OF(CONF_VALUE) *rsk = NULL;
const BIT_STRING_BITNAME *pbn;
const char *bnam;
int i, ret = 0;
rsk = X509V3_parse_list(value);
if (!rsk)
return 0;
if (*preas)
return 0;
for (i = 0; i < sk_CONF_VALUE_num(rsk); i++)
{
bnam = sk_CONF_VALUE_value(rsk, i)->name;
if (!*preas)
{
*preas = ASN1_BIT_STRING_new();
if (!*preas)
goto err;
}
for (pbn = reason_flags; pbn->lname; pbn++)
{
if (!strcmp(pbn->sname, bnam))
{
if (!ASN1_BIT_STRING_set_bit(*preas,
pbn->bitnum, 1))
goto err;
break;
}
}
if (!pbn->lname)
goto err;
}
ret = 1;
err:
sk_CONF_VALUE_pop_free(rsk, X509V3_conf_free);
return ret;
}
static int print_reasons(BIO *out, const char *rname,
ASN1_BIT_STRING *rflags, int indent)
{
int first = 1;
const BIT_STRING_BITNAME *pbn;
BIO_printf(out, "%*s%s:\n%*s", indent, "", rname, indent + 2, "");
for (pbn = reason_flags; pbn->lname; pbn++)
{
if (ASN1_BIT_STRING_get_bit(rflags, pbn->bitnum))
{
if (first)
first = 0;
else
BIO_puts(out, ", ");
BIO_puts(out, pbn->lname);
}
}
if (first)
BIO_puts(out, "<EMPTY>\n");
else
BIO_puts(out, "\n");
return 1;
}
static int dpn_cb(int operation, ASN1_VALUE **pval, const ASN1_ITEM *it,
void *exarg)
{
DIST_POINT_NAME *dpn = (DIST_POINT_NAME *)*pval;
switch(operation)
{
case ASN1_OP_NEW_POST:
dpn->dpname = NULL;
break;
case ASN1_OP_FREE_POST:
if (dpn->dpname)
X509_NAME_free(dpn->dpname);
break;
}
return 1;
}
static int print_distpoint(BIO *out, DIST_POINT_NAME *dpn, int indent)
{
if (dpn->type == 0)
{
BIO_printf(out, "%*sFull Name:\n", indent, "");
print_gens(out, dpn->name.fullname, indent);
}
else
{
X509_NAME ntmp;
ntmp.entries = dpn->name.relativename;
BIO_printf(out, "%*sRelative Name:\n%*s",
indent, "", indent + 2, "");
X509_NAME_print_ex(out, &ntmp, 0, XN_FLAG_ONELINE);
BIO_puts(out, "\n");
}
return 1;
}
static int i2r_idp(const X509V3_EXT_METHOD *method, void *pidp, BIO *out,
int indent)
{
ISSUING_DIST_POINT *idp = pidp;
if (idp->distpoint)
print_distpoint(out, idp->distpoint, indent);
if (idp->onlyuser > 0)
BIO_printf(out, "%*sOnly User Certificates\n", indent, "");
if (idp->onlyCA > 0)
BIO_printf(out, "%*sOnly CA Certificates\n", indent, "");
if (idp->indirectCRL > 0)
BIO_printf(out, "%*sIndirect CRL\n", indent, "");
if (idp->onlysomereasons)
print_reasons(out, "Only Some Reasons",
idp->onlysomereasons, indent);
if (idp->onlyattr > 0)
BIO_printf(out, "%*sOnly Attribute Certificates\n", indent, "");
if (!idp->distpoint && (idp->onlyuser <= 0) && (idp->onlyCA <= 0)
&& (idp->indirectCRL <= 0) && !idp->onlysomereasons
&& (idp->onlyattr <= 0))
BIO_printf(out, "%*s<EMPTY>\n", indent, "");
return 1;
}
static int i2r_crldp(const X509V3_EXT_METHOD *method, void *pcrldp, BIO *out,
int indent)
{
STACK_OF(DIST_POINT) *crld = pcrldp;
DIST_POINT *point;
int i;
for(i = 0; i < sk_DIST_POINT_num(crld); i++)
{
BIO_puts(out, "\n");
point = sk_DIST_POINT_value(crld, i);
if(point->distpoint)
print_distpoint(out, point->distpoint, indent);
if(point->reasons)
print_reasons(out, "Reasons", point->reasons,
indent);
if(point->CRLissuer)
{
BIO_printf(out, "%*sCRL Issuer:\n", indent, "");
print_gens(out, point->CRLissuer, indent);
}
}
return 1;
}
int DIST_POINT_set_dpname(DIST_POINT_NAME *dpn, X509_NAME *iname)
{
int i;
STACK_OF(X509_NAME_ENTRY) *frag;
X509_NAME_ENTRY *ne;
if (!dpn || (dpn->type != 1))
return 1;
frag = dpn->name.relativename;
dpn->dpname = X509_NAME_dup(iname);
if (!dpn->dpname)
return 0;
for (i = 0; i < sk_X509_NAME_ENTRY_num(frag); i++)
{
ne = sk_X509_NAME_ENTRY_value(frag, i);
if (!X509_NAME_add_entry(dpn->dpname, ne, -1, i ? 0 : 1))
{
X509_NAME_free(dpn->dpname);
dpn->dpname = NULL;
return 0;
}
}
if (i2d_X509_NAME(dpn->dpname, NULL) < 0)
{
X509_NAME_free(dpn->dpname);
dpn->dpname = NULL;
return 0;
}
return 1;
}
