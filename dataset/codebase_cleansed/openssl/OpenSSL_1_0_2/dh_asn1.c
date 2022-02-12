static int dh_cb(int operation, ASN1_VALUE **pval, const ASN1_ITEM *it,
void *exarg)
{
if (operation == ASN1_OP_NEW_PRE) {
*pval = (ASN1_VALUE *)DH_new();
if (*pval)
return 2;
return 0;
} else if (operation == ASN1_OP_FREE_PRE) {
DH_free((DH *)*pval);
*pval = NULL;
return 2;
}
return 1;
}
DH *d2i_DHxparams(DH **a, const unsigned char **pp, long length)
{
int_dhx942_dh *dhx = NULL;
DH *dh = NULL;
dh = DH_new();
if (!dh)
return NULL;
dhx = d2i_int_dhx(NULL, pp, length);
if (!dhx) {
DH_free(dh);
return NULL;
}
if (a) {
if (*a)
DH_free(*a);
*a = dh;
}
dh->p = dhx->p;
dh->q = dhx->q;
dh->g = dhx->g;
dh->j = dhx->j;
if (dhx->vparams) {
dh->seed = dhx->vparams->seed->data;
dh->seedlen = dhx->vparams->seed->length;
dh->counter = dhx->vparams->counter;
dhx->vparams->seed->data = NULL;
ASN1_BIT_STRING_free(dhx->vparams->seed);
OPENSSL_free(dhx->vparams);
dhx->vparams = NULL;
}
OPENSSL_free(dhx);
return dh;
}
int i2d_DHxparams(const DH *dh, unsigned char **pp)
{
int_dhx942_dh dhx;
int_dhvparams dhv;
ASN1_BIT_STRING bs;
dhx.p = dh->p;
dhx.g = dh->g;
dhx.q = dh->q;
dhx.j = dh->j;
if (dh->counter && dh->seed && dh->seedlen > 0) {
bs.flags = ASN1_STRING_FLAG_BITS_LEFT;
bs.data = dh->seed;
bs.length = dh->seedlen;
dhv.seed = &bs;
dhv.counter = dh->counter;
dhx.vparams = &dhv;
} else
dhx.vparams = NULL;
return i2d_int_dhx(&dhx, pp);
}
