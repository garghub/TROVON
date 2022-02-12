int i2d_ASN1_BMPSTRING(ASN1_BMPSTRING *a, unsigned char **pp)
{
return(i2d_ASN1_bytes((ASN1_STRING *)a,pp,
V_ASN1_BMPSTRING,V_ASN1_UNIVERSAL));
}
ASN1_BMPSTRING *d2i_ASN1_BMPSTRING(ASN1_BMPSTRING **a, unsigned char **pp,
long length)
{
ASN1_BMPSTRING *ret=NULL;
ret=(ASN1_BMPSTRING *)d2i_ASN1_bytes((ASN1_STRING **)a,
pp,length,V_ASN1_BMPSTRING,V_ASN1_UNIVERSAL);
if (ret == NULL)
{
ASN1err(ASN1_F_D2I_ASN1_BMPSTRING,ERR_R_NESTED_ASN1_ERROR);
return(NULL);
}
return(ret);
}
