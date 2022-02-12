int i2d_NETSCAPE_CERT_SEQUENCE(NETSCAPE_CERT_SEQUENCE *a, unsigned char **pp)
{
int v = 0;
M_ASN1_I2D_vars(a);
M_ASN1_I2D_len (a->type, i2d_ASN1_OBJECT);
M_ASN1_I2D_len_EXP_SEQUENCE_opt_type(X509,a->certs,i2d_X509,0,
V_ASN1_SEQUENCE,v);
M_ASN1_I2D_seq_total();
M_ASN1_I2D_put (a->type, i2d_ASN1_OBJECT);
M_ASN1_I2D_put_EXP_SEQUENCE_opt_type(X509,a->certs,i2d_X509,0,
V_ASN1_SEQUENCE,v);
M_ASN1_I2D_finish();
}
NETSCAPE_CERT_SEQUENCE *NETSCAPE_CERT_SEQUENCE_new(void)
{
NETSCAPE_CERT_SEQUENCE *ret=NULL;
ASN1_CTX c;
M_ASN1_New_Malloc(ret, NETSCAPE_CERT_SEQUENCE);
ret->type = OBJ_nid2obj(NID_netscape_cert_sequence);
ret->certs = NULL;
return (ret);
M_ASN1_New_Error(ASN1_F_NETSCAPE_CERT_SEQUENCE_NEW);
}
NETSCAPE_CERT_SEQUENCE *d2i_NETSCAPE_CERT_SEQUENCE(NETSCAPE_CERT_SEQUENCE **a,
unsigned char **pp, long length)
{
M_ASN1_D2I_vars(a,NETSCAPE_CERT_SEQUENCE *,
NETSCAPE_CERT_SEQUENCE_new);
M_ASN1_D2I_Init();
M_ASN1_D2I_start_sequence();
M_ASN1_D2I_get (ret->type, d2i_ASN1_OBJECT);
M_ASN1_D2I_get_EXP_set_opt_type(X509,ret->certs,d2i_X509,X509_free,0,
V_ASN1_SEQUENCE);
M_ASN1_D2I_Finish(a, NETSCAPE_CERT_SEQUENCE_free,
ASN1_F_D2I_NETSCAPE_CERT_SEQUENCE);
}
void NETSCAPE_CERT_SEQUENCE_free (NETSCAPE_CERT_SEQUENCE *a)
{
if (a == NULL) return;
ASN1_OBJECT_free(a->type);
if(a->certs)
sk_X509_pop_free(a->certs, X509_free);
Free (a);
}
