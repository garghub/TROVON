void ptlrpc_fill_bulk_md(lnet_md_t *md, struct ptlrpc_bulk_desc *desc,
int mdidx)
{
int offset = mdidx * LNET_MAX_IOV;
CLASSERT(PTLRPC_MAX_BRW_PAGES < LI_POISON);
LASSERT(mdidx < desc->bd_md_max_brw);
LASSERT(desc->bd_iov_count <= PTLRPC_MAX_BRW_PAGES);
LASSERT(!(md->options & (LNET_MD_IOVEC | LNET_MD_KIOV |
LNET_MD_PHYS)));
md->length = max(0, desc->bd_iov_count - mdidx * LNET_MAX_IOV);
md->length = min_t(unsigned int, LNET_MAX_IOV, md->length);
if (ptlrpc_is_bulk_desc_kiov(desc->bd_type)) {
md->options |= LNET_MD_KIOV;
if (GET_ENC_KIOV(desc))
md->start = &BD_GET_ENC_KIOV(desc, offset);
else
md->start = &BD_GET_KIOV(desc, offset);
} else {
md->options |= LNET_MD_IOVEC;
if (GET_ENC_KVEC(desc))
md->start = &BD_GET_ENC_KVEC(desc, offset);
else
md->start = &BD_GET_KVEC(desc, offset);
}
}
