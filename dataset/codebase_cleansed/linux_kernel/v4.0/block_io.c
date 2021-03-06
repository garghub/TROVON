static int submit(int rw, struct block_device *bdev, sector_t sector,\r\nstruct page *page, struct bio **bio_chain)\r\n{\r\nconst int bio_rw = rw | REQ_SYNC;\r\nstruct bio *bio;\r\nbio = bio_alloc(__GFP_WAIT | __GFP_HIGH, 1);\r\nbio->bi_iter.bi_sector = sector;\r\nbio->bi_bdev = bdev;\r\nbio->bi_end_io = end_swap_bio_read;\r\nif (bio_add_page(bio, page, PAGE_SIZE, 0) < PAGE_SIZE) {\r\nprintk(KERN_ERR "PM: Adding page to bio failed at %llu\n",\r\n(unsigned long long)sector);\r\nbio_put(bio);\r\nreturn -EFAULT;\r\n}\r\nlock_page(page);\r\nbio_get(bio);\r\nif (bio_chain == NULL) {\r\nsubmit_bio(bio_rw, bio);\r\nwait_on_page_locked(page);\r\nif (rw == READ)\r\nbio_set_pages_dirty(bio);\r\nbio_put(bio);\r\n} else {\r\nif (rw == READ)\r\nget_page(page);\r\nbio->bi_private = *bio_chain;\r\n*bio_chain = bio;\r\nsubmit_bio(bio_rw, bio);\r\n}\r\nreturn 0;\r\n}\r\nint hib_bio_read_page(pgoff_t page_off, void *addr, struct bio **bio_chain)\r\n{\r\nreturn submit(READ, hib_resume_bdev, page_off * (PAGE_SIZE >> 9),\r\nvirt_to_page(addr), bio_chain);\r\n}\r\nint hib_bio_write_page(pgoff_t page_off, void *addr, struct bio **bio_chain)\r\n{\r\nreturn submit(WRITE, hib_resume_bdev, page_off * (PAGE_SIZE >> 9),\r\nvirt_to_page(addr), bio_chain);\r\n}\r\nint hib_wait_on_bio_chain(struct bio **bio_chain)\r\n{\r\nstruct bio *bio;\r\nstruct bio *next_bio;\r\nint ret = 0;\r\nif (bio_chain == NULL)\r\nreturn 0;\r\nbio = *bio_chain;\r\nif (bio == NULL)\r\nreturn 0;\r\nwhile (bio) {\r\nstruct page *page;\r\nnext_bio = bio->bi_private;\r\npage = bio->bi_io_vec[0].bv_page;\r\nwait_on_page_locked(page);\r\nif (!PageUptodate(page) || PageError(page))\r\nret = -EIO;\r\nput_page(page);\r\nbio_put(bio);\r\nbio = next_bio;\r\n}\r\n*bio_chain = NULL;\r\nreturn ret;\r\n}
