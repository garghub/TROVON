int i2r_NAME_CONSTRAINTS(const X509V3_EXT_METHOD *method, void *a,
BIO *bp, int ind)
{
NAME_CONSTRAINTS *ncons = a;
do_i2r_name_constraints(method, ncons->permittedSubtrees,
bp, ind, "Permitted");
do_i2r_name_constraints(method, ncons->excludedSubtrees,
bp, ind, "Excluded");
return 1;
}
static int print_nc_ipadd(BIO *bp, ASN1_OCTET_STRING *ip)
{
int i, len;
unsigned char *p;
p = ip->data;
len = ip->length;
BIO_puts(bp, "IP:");
if(len == 8)
{
BIO_printf(bp, "%d.%d.%d.%d/%d.%d.%d.%d",
p[0], p[1], p[2], p[3],
p[4], p[5], p[6], p[7]);
}
else if(len == 32)
{
for (i = 0; i < 16; i++)
{
BIO_printf(bp, "%X", p[0] << 8 | p[1]);
p += 2;
if (i == 7)
BIO_puts(bp, "/");
else if (i != 15)
BIO_puts(bp, ":");
}
}
else
BIO_printf(bp, "IP Address:<invalid>");
return 1;
}
int NAME_CONSTRAINTS_check(X509 *x, NAME_CONSTRAINTS *nc)
{
int r, i;
X509_NAME *nm;
nm = X509_get_subject_name(x);
if (X509_NAME_entry_count(nm) > 0)
{
GENERAL_NAME gntmp;
gntmp.type = GEN_DIRNAME;
gntmp.d.directoryName = nm;
r = nc_match(&gntmp, nc);
if (r != X509_V_OK)
return r;
gntmp.type = GEN_EMAIL;
for (i = -1;;)
{
X509_NAME_ENTRY *ne;
i = X509_NAME_get_index_by_NID(nm,
NID_pkcs9_emailAddress,
i);
if (i == -1)
break;
ne = X509_NAME_get_entry(nm, i);
gntmp.d.rfc822Name = X509_NAME_ENTRY_get_data(ne);
if (gntmp.d.rfc822Name->type != V_ASN1_IA5STRING)
return X509_V_ERR_UNSUPPORTED_NAME_SYNTAX;
r = nc_match(&gntmp, nc);
if (r != X509_V_OK)
return r;
}
}
for (i = 0; i < sk_GENERAL_NAME_num(x->altname); i++)
{
GENERAL_NAME *gen = sk_GENERAL_NAME_value(x->altname, i);
r = nc_match(gen, nc);
if (r != X509_V_OK)
return r;
}
return X509_V_OK;
}
static int nc_match(GENERAL_NAME *gen, NAME_CONSTRAINTS *nc)
{
GENERAL_SUBTREE *sub;
int i, r, match = 0;
for (i = 0; i < sk_GENERAL_SUBTREE_num(nc->permittedSubtrees); i++)
{
sub = sk_GENERAL_SUBTREE_value(nc->permittedSubtrees, i);
if (gen->type != sub->base->type)
continue;
if (sub->minimum || sub->maximum)
return X509_V_ERR_SUBTREE_MINMAX;
if (match == 2)
continue;
if (match == 0)
match = 1;
r = nc_match_single(gen, sub->base);
if (r == X509_V_OK)
match = 2;
else if (r != X509_V_ERR_PERMITTED_VIOLATION)
return r;
}
if (match == 1)
return X509_V_ERR_PERMITTED_VIOLATION;
for (i = 0; i < sk_GENERAL_SUBTREE_num(nc->excludedSubtrees); i++)
{
sub = sk_GENERAL_SUBTREE_value(nc->excludedSubtrees, i);
if (gen->type != sub->base->type)
continue;
if (sub->minimum || sub->maximum)
return X509_V_ERR_SUBTREE_MINMAX;
r = nc_match_single(gen, sub->base);
if (r == X509_V_OK)
return X509_V_ERR_EXCLUDED_VIOLATION;
else if (r != X509_V_ERR_PERMITTED_VIOLATION)
return r;
}
return X509_V_OK;
}
static int nc_match_single(GENERAL_NAME *gen, GENERAL_NAME *base)
{
switch(base->type)
{
case GEN_DIRNAME:
return nc_dn(gen->d.directoryName, base->d.directoryName);
case GEN_DNS:
return nc_dns(gen->d.dNSName, base->d.dNSName);
case GEN_EMAIL:
return nc_email(gen->d.rfc822Name, base->d.rfc822Name);
case GEN_URI:
return nc_uri(gen->d.uniformResourceIdentifier,
base->d.uniformResourceIdentifier);
default:
return X509_V_ERR_UNSUPPORTED_CONSTRAINT_TYPE;
}
}
static int nc_dn(X509_NAME *nm, X509_NAME *base)
{
if (nm->modified && i2d_X509_NAME(nm, NULL) < 0)
return X509_V_ERR_OUT_OF_MEM;
if (base->modified && i2d_X509_NAME(base, NULL) < 0)
return X509_V_ERR_OUT_OF_MEM;
if (base->canon_enclen > nm->canon_enclen)
return X509_V_ERR_PERMITTED_VIOLATION;
if (memcmp(base->canon_enc, nm->canon_enc, base->canon_enclen))
return X509_V_ERR_PERMITTED_VIOLATION;
return X509_V_OK;
}
static int nc_dns(ASN1_IA5STRING *dns, ASN1_IA5STRING *base)
{
char *baseptr = (char *)base->data;
char *dnsptr = (char *)dns->data;
if (!*baseptr)
return X509_V_OK;
if (dns->length > base->length)
{
dnsptr += dns->length - base->length;
if (dnsptr[-1] != '.')
return X509_V_ERR_PERMITTED_VIOLATION;
}
if (strcasecmp(baseptr, dnsptr))
return X509_V_ERR_PERMITTED_VIOLATION;
return X509_V_OK;
}
static int nc_email(ASN1_IA5STRING *eml, ASN1_IA5STRING *base)
{
const char *baseptr = (char *)base->data;
const char *emlptr = (char *)eml->data;
const char *baseat = strchr(baseptr, '@');
const char *emlat = strchr(emlptr, '@');
if (!emlat)
return X509_V_ERR_UNSUPPORTED_NAME_SYNTAX;
if (!baseat && (*baseptr == '.'))
{
if (eml->length > base->length)
{
emlptr += eml->length - base->length;
if (!strcasecmp(baseptr, emlptr))
return X509_V_OK;
}
return X509_V_ERR_PERMITTED_VIOLATION;
}
if (baseat)
{
if (baseat != baseptr)
{
if ((baseat - baseptr) != (emlat - emlptr))
return X509_V_ERR_PERMITTED_VIOLATION;
if (strncmp(baseptr, emlptr, emlat - emlptr))
return X509_V_ERR_PERMITTED_VIOLATION;
}
baseptr = baseat + 1;
}
emlptr = emlat + 1;
if (strcasecmp(baseptr, emlptr))
return X509_V_ERR_PERMITTED_VIOLATION;
return X509_V_OK;
}
static int nc_uri(ASN1_IA5STRING *uri, ASN1_IA5STRING *base)
{
const char *baseptr = (char *)base->data;
const char *hostptr = (char *)uri->data;
const char *p = strchr(hostptr, ':');
int hostlen;
if (!p || (p[1] != '/') || (p[2] != '/'))
return X509_V_ERR_UNSUPPORTED_NAME_SYNTAX;
hostptr = p + 3;
p = strchr(hostptr, ':');
if (!p)
p = strchr(hostptr, '/');
if (!p)
hostlen = strlen(hostptr);
else
hostlen = p - hostptr;
if (hostlen == 0)
return X509_V_ERR_UNSUPPORTED_NAME_SYNTAX;
if (*baseptr == '.')
{
if (hostlen > base->length)
{
p = hostptr + hostlen - base->length;
if (!strncasecmp(p, baseptr, base->length))
return X509_V_OK;
}
return X509_V_ERR_PERMITTED_VIOLATION;
}
if ((base->length != (int)hostlen) || strncasecmp(hostptr, baseptr, hostlen))
return X509_V_ERR_PERMITTED_VIOLATION;
return X509_V_OK;
}
