int i2d_BASIC_CONSTRAINTS(BASIC_CONSTRAINTS *a, unsigned char **pp)
{
M_ASN1_I2D_vars(a);
if(a->ca) M_ASN1_I2D_len (a->ca, i2d_ASN1_BOOLEAN);
M_ASN1_I2D_len (a->pathlen, i2d_ASN1_INTEGER);
M_ASN1_I2D_seq_total();
if (a->ca) M_ASN1_I2D_put (a->ca, i2d_ASN1_BOOLEAN);
M_ASN1_I2D_put (a->pathlen, i2d_ASN1_INTEGER);
M_ASN1_I2D_finish();
}
BASIC_CONSTRAINTS *BASIC_CONSTRAINTS_new(void)
{
BASIC_CONSTRAINTS *ret=NULL;
ASN1_CTX c;
M_ASN1_New_Malloc(ret, BASIC_CONSTRAINTS);
ret->ca = 0;
ret->pathlen = NULL;
return (ret);
M_ASN1_New_Error(ASN1_F_BASIC_CONSTRAINTS_NEW);
}
BASIC_CONSTRAINTS *d2i_BASIC_CONSTRAINTS(BASIC_CONSTRAINTS **a,
unsigned char **pp, long length)
{
M_ASN1_D2I_vars(a,BASIC_CONSTRAINTS *,BASIC_CONSTRAINTS_new);
M_ASN1_D2I_Init();
M_ASN1_D2I_start_sequence();
if((M_ASN1_next & (~V_ASN1_CONSTRUCTED)) ==
(V_ASN1_UNIVERSAL|V_ASN1_BOOLEAN) ) {
M_ASN1_D2I_get_int (ret->ca, d2i_ASN1_BOOLEAN);
}
M_ASN1_D2I_get_opt (ret->pathlen, d2i_ASN1_INTEGER, V_ASN1_INTEGER);
M_ASN1_D2I_Finish(a, BASIC_CONSTRAINTS_free, ASN1_F_D2I_BASIC_CONSTRAINTS);
}
void BASIC_CONSTRAINTS_free(BASIC_CONSTRAINTS *a)
{
if (a == NULL) return;
ASN1_INTEGER_free (a->pathlen);
Free ((char *)a);
}
