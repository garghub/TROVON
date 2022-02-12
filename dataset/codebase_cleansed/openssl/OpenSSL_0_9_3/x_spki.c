int i2d_NETSCAPE_SPKAC(NETSCAPE_SPKAC *a, unsigned char **pp)
{
M_ASN1_I2D_vars(a);
M_ASN1_I2D_len(a->pubkey, i2d_X509_PUBKEY);
M_ASN1_I2D_len(a->challenge, i2d_ASN1_IA5STRING);
M_ASN1_I2D_seq_total();
M_ASN1_I2D_put(a->pubkey, i2d_X509_PUBKEY);
M_ASN1_I2D_put(a->challenge, i2d_ASN1_IA5STRING);
M_ASN1_I2D_finish();
}
NETSCAPE_SPKAC *d2i_NETSCAPE_SPKAC(NETSCAPE_SPKAC **a, unsigned char **pp,
long length)
{
M_ASN1_D2I_vars(a,NETSCAPE_SPKAC *,NETSCAPE_SPKAC_new);
M_ASN1_D2I_Init();
M_ASN1_D2I_start_sequence();
M_ASN1_D2I_get(ret->pubkey,d2i_X509_PUBKEY);
M_ASN1_D2I_get(ret->challenge,d2i_ASN1_IA5STRING);
M_ASN1_D2I_Finish(a,NETSCAPE_SPKAC_free,ASN1_F_D2I_NETSCAPE_SPKAC);
}
NETSCAPE_SPKAC *NETSCAPE_SPKAC_new(void)
{
NETSCAPE_SPKAC *ret=NULL;
ASN1_CTX c;
M_ASN1_New_Malloc(ret,NETSCAPE_SPKAC);
M_ASN1_New(ret->pubkey,X509_PUBKEY_new);
M_ASN1_New(ret->challenge,ASN1_IA5STRING_new);
return(ret);
M_ASN1_New_Error(ASN1_F_NETSCAPE_SPKAC_NEW);
}
void NETSCAPE_SPKAC_free(NETSCAPE_SPKAC *a)
{
if (a == NULL) return;
X509_PUBKEY_free(a->pubkey);
ASN1_IA5STRING_free(a->challenge);
Free((char *)a);
}
int i2d_NETSCAPE_SPKI(NETSCAPE_SPKI *a, unsigned char **pp)
{
M_ASN1_I2D_vars(a);
M_ASN1_I2D_len(a->spkac, i2d_NETSCAPE_SPKAC);
M_ASN1_I2D_len(a->sig_algor, i2d_X509_ALGOR);
M_ASN1_I2D_len(a->signature, i2d_ASN1_BIT_STRING);
M_ASN1_I2D_seq_total();
M_ASN1_I2D_put(a->spkac, i2d_NETSCAPE_SPKAC);
M_ASN1_I2D_put(a->sig_algor, i2d_X509_ALGOR);
M_ASN1_I2D_put(a->signature, i2d_ASN1_BIT_STRING);
M_ASN1_I2D_finish();
}
NETSCAPE_SPKI *d2i_NETSCAPE_SPKI(NETSCAPE_SPKI **a, unsigned char **pp,
long length)
{
M_ASN1_D2I_vars(a,NETSCAPE_SPKI *,NETSCAPE_SPKI_new);
M_ASN1_D2I_Init();
M_ASN1_D2I_start_sequence();
M_ASN1_D2I_get(ret->spkac,d2i_NETSCAPE_SPKAC);
M_ASN1_D2I_get(ret->sig_algor,d2i_X509_ALGOR);
M_ASN1_D2I_get(ret->signature,d2i_ASN1_BIT_STRING);
M_ASN1_D2I_Finish(a,NETSCAPE_SPKI_free,ASN1_F_D2I_NETSCAPE_SPKI);
}
NETSCAPE_SPKI *NETSCAPE_SPKI_new(void)
{
NETSCAPE_SPKI *ret=NULL;
ASN1_CTX c;
M_ASN1_New_Malloc(ret,NETSCAPE_SPKI);
M_ASN1_New(ret->spkac,NETSCAPE_SPKAC_new);
M_ASN1_New(ret->sig_algor,X509_ALGOR_new);
M_ASN1_New(ret->signature,ASN1_BIT_STRING_new);
return(ret);
M_ASN1_New_Error(ASN1_F_NETSCAPE_SPKI_NEW);
}
void NETSCAPE_SPKI_free(NETSCAPE_SPKI *a)
{
if (a == NULL) return;
NETSCAPE_SPKAC_free(a->spkac);
X509_ALGOR_free(a->sig_algor);
ASN1_BIT_STRING_free(a->signature);
Free((char *)a);
}
