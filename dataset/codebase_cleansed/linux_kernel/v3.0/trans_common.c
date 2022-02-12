void
p9_release_req_pages(struct trans_rpage_info *rpinfo)
{
int i = 0;
while (rpinfo->rp_data[i] && rpinfo->rp_nr_pages--) {
put_page(rpinfo->rp_data[i]);
i++;
}
}
int
p9_nr_pages(struct p9_req_t *req)
{
unsigned long start_page, end_page;
start_page = (unsigned long)req->tc->pubuf >> PAGE_SHIFT;
end_page = ((unsigned long)req->tc->pubuf + req->tc->pbuf_size +
PAGE_SIZE - 1) >> PAGE_SHIFT;
return end_page - start_page;
}
int
p9_payload_gup(struct p9_req_t *req, size_t *pdata_off, int *pdata_len,
int nr_pages, u8 rw)
{
uint32_t first_page_bytes = 0;
int32_t pdata_mapped_pages;
struct trans_rpage_info *rpinfo;
*pdata_off = (__force size_t)req->tc->pubuf & (PAGE_SIZE-1);
if (*pdata_off)
first_page_bytes = min(((size_t)PAGE_SIZE - *pdata_off),
req->tc->pbuf_size);
rpinfo = req->tc->private;
pdata_mapped_pages = get_user_pages_fast((unsigned long)req->tc->pubuf,
nr_pages, rw, &rpinfo->rp_data[0]);
if (pdata_mapped_pages <= 0)
return pdata_mapped_pages;
rpinfo->rp_nr_pages = pdata_mapped_pages;
if (*pdata_off) {
*pdata_len = first_page_bytes;
*pdata_len += min((req->tc->pbuf_size - *pdata_len),
((size_t)pdata_mapped_pages - 1) << PAGE_SHIFT);
} else {
*pdata_len = min(req->tc->pbuf_size,
(size_t)pdata_mapped_pages << PAGE_SHIFT);
}
return 0;
}
