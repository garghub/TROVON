int ASN1_BIT_STRING_name_print(BIO *out, ASN1_BIT_STRING *bs,
BIT_STRING_BITNAME *tbl, int indent)
{
BIT_STRING_BITNAME *bnam;
char first = 1;
BIO_printf(out, "%*s", indent, "");
for (bnam = tbl; bnam->lname; bnam++) {
if (ASN1_BIT_STRING_get_bit(bs, bnam->bitnum)) {
if (!first)
BIO_puts(out, ", ");
BIO_puts(out, bnam->lname);
first = 0;
}
}
BIO_puts(out, "\n");
return 1;
}
int ASN1_BIT_STRING_set_asc(ASN1_BIT_STRING *bs, const char *name, int value,
BIT_STRING_BITNAME *tbl)
{
int bitnum;
bitnum = ASN1_BIT_STRING_num_asc(name, tbl);
if (bitnum < 0)
return 0;
if (bs) {
if (!ASN1_BIT_STRING_set_bit(bs, bitnum, value))
return 0;
}
return 1;
}
int ASN1_BIT_STRING_num_asc(const char *name, BIT_STRING_BITNAME *tbl)
{
BIT_STRING_BITNAME *bnam;
for (bnam = tbl; bnam->lname; bnam++) {
if ((strcmp(bnam->sname, name) == 0)
|| (strcmp(bnam->lname, name) == 0))
return bnam->bitnum;
}
return -1;
}
