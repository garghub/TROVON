int i2a_ACCESS_DESCRIPTION(BIO *bp, const ACCESS_DESCRIPTION *a)
{
i2a_ASN1_OBJECT(bp, a->method);
return 2;
}
