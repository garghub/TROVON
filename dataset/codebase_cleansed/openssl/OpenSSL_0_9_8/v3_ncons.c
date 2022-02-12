int i2r_NAME_CONSTRAINTS(X509V3_EXT_METHOD *method,
void *a, BIO *bp, int ind)
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
