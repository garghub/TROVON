int i2d_PKCS12_BAGS(PKCS12_BAGS *a, unsigned char **pp)
{
int bagnid, v = 0;
M_ASN1_I2D_vars(a);
bagnid = OBJ_obj2nid (a->type);
M_ASN1_I2D_len (a->type, i2d_ASN1_OBJECT);
switch (bagnid) {
case NID_x509Certificate:
M_ASN1_I2D_len_EXP_opt (a->value.x509cert,
i2d_ASN1_OCTET_STRING, 0, v);
break;
case NID_x509Crl:
M_ASN1_I2D_len_EXP_opt (a->value.x509crl,
i2d_ASN1_OCTET_STRING, 0, v);
break;
case NID_sdsiCertificate:
M_ASN1_I2D_len_EXP_opt (a->value.sdsicert,
i2d_ASN1_IA5STRING, 0, v);
break;
default:
M_ASN1_I2D_len_EXP_opt (a->value.other,
i2d_ASN1_TYPE, 0, v);
break;
}
M_ASN1_I2D_seq_total ();
M_ASN1_I2D_put (a->type, i2d_ASN1_OBJECT);
switch (bagnid) {
case NID_x509Certificate:
M_ASN1_I2D_put_EXP_opt (a->value.x509cert,
i2d_ASN1_OCTET_STRING, 0, v);
break;
case NID_x509Crl:
M_ASN1_I2D_put_EXP_opt (a->value.x509crl,
i2d_ASN1_OCTET_STRING, 0, v);
break;
case NID_sdsiCertificate:
M_ASN1_I2D_put_EXP_opt (a->value.sdsicert,
i2d_ASN1_IA5STRING, 0, v);
break;
default:
M_ASN1_I2D_put_EXP_opt (a->value.other, i2d_ASN1_TYPE, 0, v);
break;
}
M_ASN1_I2D_finish();
}
PKCS12_BAGS *PKCS12_BAGS_new(void)
{
PKCS12_BAGS *ret=NULL;
ASN1_CTX c;
M_ASN1_New_Malloc(ret, PKCS12_BAGS);
ret->type=NULL;
ret->value.other=NULL;
return (ret);
M_ASN1_New_Error(ASN1_F_PKCS12_BAGS_NEW);
}
PKCS12_BAGS *d2i_PKCS12_BAGS(PKCS12_BAGS **a, unsigned char **pp,
long length)
{
int bagnid;
M_ASN1_D2I_vars(a,PKCS12_BAGS *,PKCS12_BAGS_new);
M_ASN1_D2I_Init();
M_ASN1_D2I_start_sequence();
M_ASN1_D2I_get (ret->type, d2i_ASN1_OBJECT);
bagnid = OBJ_obj2nid (ret->type);
switch (bagnid) {
case NID_x509Certificate:
M_ASN1_D2I_get_EXP_opt (ret->value.x509cert,
d2i_ASN1_OCTET_STRING, 0);
break;
case NID_x509Crl:
M_ASN1_D2I_get_EXP_opt (ret->value.x509crl,
d2i_ASN1_OCTET_STRING, 0);
break;
case NID_sdsiCertificate:
M_ASN1_D2I_get_EXP_opt (ret->value.sdsicert,
d2i_ASN1_IA5STRING, 0);
break;
default:
M_ASN1_D2I_get_EXP_opt (ret->value.other,
d2i_ASN1_TYPE, 0);
break;
}
M_ASN1_D2I_Finish(a, PKCS12_BAGS_free, ASN1_F_D2I_PKCS12_BAGS);
}
void PKCS12_BAGS_free (PKCS12_BAGS *a)
{
if (a == NULL) return;
switch (OBJ_obj2nid(a->type)) {
case NID_x509Certificate:
ASN1_OCTET_STRING_free (a->value.x509cert);
break;
case NID_x509Crl:
ASN1_OCTET_STRING_free (a->value.x509crl);
break;
case NID_sdsiCertificate:
ASN1_IA5STRING_free (a->value.sdsicert);
break;
default:
ASN1_TYPE_free (a->value.other);
break;
}
ASN1_OBJECT_free (a->type);
Free ((char *)a);
}
