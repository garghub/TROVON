int i2d_TS_MSG_IMPRINT_bio(BIO *bp, TS_MSG_IMPRINT *a)
{
return ASN1_i2d_bio_of_const(TS_MSG_IMPRINT, i2d_TS_MSG_IMPRINT, bp, a);
}
TS_MSG_IMPRINT *d2i_TS_MSG_IMPRINT_fp(FILE *fp, TS_MSG_IMPRINT **a)
{
return ASN1_d2i_fp_of(TS_MSG_IMPRINT, TS_MSG_IMPRINT_new,
d2i_TS_MSG_IMPRINT, fp, a);
}
int i2d_TS_MSG_IMPRINT_fp(FILE *fp, TS_MSG_IMPRINT *a)
{
return ASN1_i2d_fp_of_const(TS_MSG_IMPRINT, i2d_TS_MSG_IMPRINT, fp, a);
}
int i2d_TS_REQ_bio(BIO *bp, TS_REQ *a)
{
return ASN1_i2d_bio_of_const(TS_REQ, i2d_TS_REQ, bp, a);
}
TS_REQ *d2i_TS_REQ_fp(FILE *fp, TS_REQ **a)
{
return ASN1_d2i_fp_of(TS_REQ, TS_REQ_new, d2i_TS_REQ, fp, a);
}
int i2d_TS_REQ_fp(FILE *fp, TS_REQ *a)
{
return ASN1_i2d_fp_of_const(TS_REQ, i2d_TS_REQ, fp, a);
}
int i2d_TS_TST_INFO_bio(BIO *bp, TS_TST_INFO *a)
{
return ASN1_i2d_bio_of_const(TS_TST_INFO, i2d_TS_TST_INFO, bp, a);
}
TS_TST_INFO *d2i_TS_TST_INFO_fp(FILE *fp, TS_TST_INFO **a)
{
return ASN1_d2i_fp_of(TS_TST_INFO, TS_TST_INFO_new, d2i_TS_TST_INFO, fp,
a);
}
int i2d_TS_TST_INFO_fp(FILE *fp, TS_TST_INFO *a)
{
return ASN1_i2d_fp_of_const(TS_TST_INFO, i2d_TS_TST_INFO, fp, a);
}
int ts_resp_cb(int op, ASN1_VALUE **pval, const ASN1_ITEM *it,
void *exarg)
{
TS_RESP *ts_resp = (TS_RESP *)*pval;
if (op == ASN1_OP_NEW_POST) {
ts_resp->tst_info = NULL;
} else if (op == ASN1_OP_FREE_POST) {
if (ts_resp->tst_info != NULL)
TS_TST_INFO_free(ts_resp->tst_info);
} else if (op == ASN1_OP_D2I_POST) {
if (ts_resp_set_tst_info(ts_resp) == 0)
return 0;
}
return 1;
}
int i2d_TS_RESP_bio(BIO *bp, TS_RESP *a)
{
return ASN1_i2d_bio_of_const(TS_RESP, i2d_TS_RESP, bp, a);
}
TS_RESP *d2i_TS_RESP_fp(FILE *fp, TS_RESP **a)
{
return ASN1_d2i_fp_of(TS_RESP, TS_RESP_new, d2i_TS_RESP, fp, a);
}
int i2d_TS_RESP_fp(FILE *fp, TS_RESP *a)
{
return ASN1_i2d_fp_of_const(TS_RESP, i2d_TS_RESP, fp, a);
}
