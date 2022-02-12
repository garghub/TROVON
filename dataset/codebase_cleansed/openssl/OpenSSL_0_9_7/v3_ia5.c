static char *i2s_ASN1_IA5STRING(X509V3_EXT_METHOD *method,
ASN1_IA5STRING *ia5)
{
char *tmp;
if(!ia5 || !ia5->length) return NULL;
if (!(tmp = OPENSSL_malloc(ia5->length + 1))) return NULL;
memcpy(tmp, ia5->data, ia5->length);
tmp[ia5->length] = 0;
return tmp;
}
static ASN1_IA5STRING *s2i_ASN1_IA5STRING(X509V3_EXT_METHOD *method,
X509V3_CTX *ctx, char *str)
{
ASN1_IA5STRING *ia5;
if(!str) {
X509V3err(X509V3_F_S2I_ASN1_IA5STRING,X509V3_R_INVALID_NULL_ARGUMENT);
return NULL;
}
if(!(ia5 = M_ASN1_IA5STRING_new())) goto err;
if(!ASN1_STRING_set((ASN1_STRING *)ia5, (unsigned char*)str,
strlen(str))) {
M_ASN1_IA5STRING_free(ia5);
goto err;
}
#ifdef CHARSET_EBCDIC
ebcdic2ascii(ia5->data, ia5->data, ia5->length);
#endif
return ia5;
err:
X509V3err(X509V3_F_S2I_ASN1_IA5STRING,ERR_R_MALLOC_FAILURE);
return NULL;
}
