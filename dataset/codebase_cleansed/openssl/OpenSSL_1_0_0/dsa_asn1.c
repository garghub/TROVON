static int sig_cb(int operation, ASN1_VALUE **pval, const ASN1_ITEM *it,
void *exarg)
{
if(operation == ASN1_OP_NEW_PRE) {
DSA_SIG *sig;
sig = OPENSSL_malloc(sizeof(DSA_SIG));
if (!sig)
{
DSAerr(DSA_F_SIG_CB, ERR_R_MALLOC_FAILURE);
return 0;
}
sig->r = NULL;
sig->s = NULL;
*pval = (ASN1_VALUE *)sig;
return 2;
}
return 1;
}
