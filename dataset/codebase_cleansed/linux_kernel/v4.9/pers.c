void ptlrpc_fill_bulk_md(lnet_md_t *md, struct ptlrpc_bulk_desc *desc,
int mdidx)
{
CLASSERT(PTLRPC_MAX_BRW_PAGES < LI_POISON);
LASSERT(mdidx < desc->bd_md_max_brw);
LASSERT(desc->bd_iov_count <= PTLRPC_MAX_BRW_PAGES);
LASSERT(!(md->options & (LNET_MD_IOVEC | LNET_MD_KIOV |
LNET_MD_PHYS)));
md->options |= LNET_MD_KIOV;
md->length = max(0, desc->bd_iov_count - mdidx * LNET_MAX_IOV);
md->length = min_t(unsigned int, LNET_MAX_IOV, md->length);
if (desc->bd_enc_iov)
md->start = &desc->bd_enc_iov[mdidx * LNET_MAX_IOV];
else
md->start = &desc->bd_iov[mdidx * LNET_MAX_IOV];
}
void ptlrpc_add_bulk_page(struct ptlrpc_bulk_desc *desc, struct page *page,
int pageoffset, int len)
{
lnet_kiov_t *kiov = &desc->bd_iov[desc->bd_iov_count];
kiov->bv_page = page;
kiov->bv_offset = pageoffset;
kiov->bv_len = len;
desc->bd_iov_count++;
}
