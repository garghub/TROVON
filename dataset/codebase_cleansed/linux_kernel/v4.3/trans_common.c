void p9_release_pages(struct page **pages, int nr_pages)\r\n{\r\nint i;\r\nfor (i = 0; i < nr_pages; i++)\r\nif (pages[i])\r\nput_page(pages[i]);\r\n}
