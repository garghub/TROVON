static int sig_cb(int operation, ASN1_VALUE **pval, const ASN1_ITEM *it)
{
if(operation == ASN1_OP_NEW_PRE) {
DSA_SIG *sig;
sig = OPENSSL_malloc(sizeof(DSA_SIG));
sig->r = NULL;
sig->s = NULL;
*pval = (ASN1_VALUE *)sig;
if(sig) return 2;
DSAerr(DSA_F_SIG_CB, ERR_R_MALLOC_FAILURE);
return 0;
}
return 1;
}
