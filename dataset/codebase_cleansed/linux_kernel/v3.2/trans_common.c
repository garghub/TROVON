void p9_release_pages(struct page **pages, int nr_pages)
{
int i = 0;
while (pages[i] && nr_pages--) {
put_page(pages[i]);
i++;
}
}
int p9_nr_pages(char *data, int len)
{
unsigned long start_page, end_page;
start_page = (unsigned long)data >> PAGE_SHIFT;
end_page = ((unsigned long)data + len + PAGE_SIZE - 1) >> PAGE_SHIFT;
return end_page - start_page;
}
int p9_payload_gup(char *data, int *nr_pages, struct page **pages, int write)
{
int nr_mapped_pages;
nr_mapped_pages = get_user_pages_fast((unsigned long)data,
*nr_pages, write, pages);
if (nr_mapped_pages <= 0)
return nr_mapped_pages;
*nr_pages = nr_mapped_pages;
return 0;
}
