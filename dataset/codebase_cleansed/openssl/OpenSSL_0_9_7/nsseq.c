static int nsseq_cb(int operation, ASN1_VALUE **pval, const ASN1_ITEM *it)
{
if(operation == ASN1_OP_NEW_POST) {
NETSCAPE_CERT_SEQUENCE *nsseq;
nsseq = (NETSCAPE_CERT_SEQUENCE *)*pval;
nsseq->type = OBJ_nid2obj(NID_netscape_cert_sequence);
}
return 1;
}
