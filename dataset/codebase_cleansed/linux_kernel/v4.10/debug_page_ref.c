void __page_ref_set(struct page *page, int v)
{
trace_page_ref_set(page, v);
}
void __page_ref_mod(struct page *page, int v)
{
trace_page_ref_mod(page, v);
}
void __page_ref_mod_and_test(struct page *page, int v, int ret)
{
trace_page_ref_mod_and_test(page, v, ret);
}
void __page_ref_mod_and_return(struct page *page, int v, int ret)
{
trace_page_ref_mod_and_return(page, v, ret);
}
void __page_ref_mod_unless(struct page *page, int v, int u)
{
trace_page_ref_mod_unless(page, v, u);
}
void __page_ref_freeze(struct page *page, int v, int ret)
{
trace_page_ref_freeze(page, v, ret);
}
void __page_ref_unfreeze(struct page *page, int v)
{
trace_page_ref_unfreeze(page, v);
}
