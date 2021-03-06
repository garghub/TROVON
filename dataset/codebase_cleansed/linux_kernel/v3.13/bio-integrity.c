struct bio_integrity_payload *bio_integrity_alloc(struct bio *bio,\r\ngfp_t gfp_mask,\r\nunsigned int nr_vecs)\r\n{\r\nstruct bio_integrity_payload *bip;\r\nstruct bio_set *bs = bio->bi_pool;\r\nunsigned long idx = BIO_POOL_NONE;\r\nunsigned inline_vecs;\r\nif (!bs) {\r\nbip = kmalloc(sizeof(struct bio_integrity_payload) +\r\nsizeof(struct bio_vec) * nr_vecs, gfp_mask);\r\ninline_vecs = nr_vecs;\r\n} else {\r\nbip = mempool_alloc(bs->bio_integrity_pool, gfp_mask);\r\ninline_vecs = BIP_INLINE_VECS;\r\n}\r\nif (unlikely(!bip))\r\nreturn NULL;\r\nmemset(bip, 0, sizeof(*bip));\r\nif (nr_vecs > inline_vecs) {\r\nbip->bip_vec = bvec_alloc(gfp_mask, nr_vecs, &idx,\r\nbs->bvec_integrity_pool);\r\nif (!bip->bip_vec)\r\ngoto err;\r\n} else {\r\nbip->bip_vec = bip->bip_inline_vecs;\r\n}\r\nbip->bip_slab = idx;\r\nbip->bip_bio = bio;\r\nbio->bi_integrity = bip;\r\nreturn bip;\r\nerr:\r\nmempool_free(bip, bs->bio_integrity_pool);\r\nreturn NULL;\r\n}\r\nvoid bio_integrity_free(struct bio *bio)\r\n{\r\nstruct bio_integrity_payload *bip = bio->bi_integrity;\r\nstruct bio_set *bs = bio->bi_pool;\r\nif (bip->bip_owns_buf)\r\nkfree(bip->bip_buf);\r\nif (bs) {\r\nif (bip->bip_slab != BIO_POOL_NONE)\r\nbvec_free(bs->bvec_integrity_pool, bip->bip_vec,\r\nbip->bip_slab);\r\nmempool_free(bip, bs->bio_integrity_pool);\r\n} else {\r\nkfree(bip);\r\n}\r\nbio->bi_integrity = NULL;\r\n}\r\nint bio_integrity_add_page(struct bio *bio, struct page *page,\r\nunsigned int len, unsigned int offset)\r\n{\r\nstruct bio_integrity_payload *bip = bio->bi_integrity;\r\nstruct bio_vec *iv;\r\nif (bip->bip_vcnt >= bvec_nr_vecs(bip->bip_slab)) {\r\nprintk(KERN_ERR "%s: bip_vec full\n", __func__);\r\nreturn 0;\r\n}\r\niv = bip_vec_idx(bip, bip->bip_vcnt);\r\nBUG_ON(iv == NULL);\r\niv->bv_page = page;\r\niv->bv_len = len;\r\niv->bv_offset = offset;\r\nbip->bip_vcnt++;\r\nreturn len;\r\n}\r\nstatic int bdev_integrity_enabled(struct block_device *bdev, int rw)\r\n{\r\nstruct blk_integrity *bi = bdev_get_integrity(bdev);\r\nif (bi == NULL)\r\nreturn 0;\r\nif (rw == READ && bi->verify_fn != NULL &&\r\n(bi->flags & INTEGRITY_FLAG_READ))\r\nreturn 1;\r\nif (rw == WRITE && bi->generate_fn != NULL &&\r\n(bi->flags & INTEGRITY_FLAG_WRITE))\r\nreturn 1;\r\nreturn 0;\r\n}\r\nint bio_integrity_enabled(struct bio *bio)\r\n{\r\nif (bio_integrity(bio))\r\nreturn 0;\r\nreturn bdev_integrity_enabled(bio->bi_bdev, bio_data_dir(bio));\r\n}\r\nstatic inline unsigned int bio_integrity_hw_sectors(struct blk_integrity *bi,\r\nunsigned int sectors)\r\n{\r\nif (bi->sector_size == 4096)\r\nreturn sectors >>= 3;\r\nreturn sectors;\r\n}\r\nunsigned int bio_integrity_tag_size(struct bio *bio)\r\n{\r\nstruct blk_integrity *bi = bdev_get_integrity(bio->bi_bdev);\r\nBUG_ON(bio->bi_size == 0);\r\nreturn bi->tag_size * (bio->bi_size / bi->sector_size);\r\n}\r\nint bio_integrity_tag(struct bio *bio, void *tag_buf, unsigned int len, int set)\r\n{\r\nstruct bio_integrity_payload *bip = bio->bi_integrity;\r\nstruct blk_integrity *bi = bdev_get_integrity(bio->bi_bdev);\r\nunsigned int nr_sectors;\r\nBUG_ON(bip->bip_buf == NULL);\r\nif (bi->tag_size == 0)\r\nreturn -1;\r\nnr_sectors = bio_integrity_hw_sectors(bi,\r\nDIV_ROUND_UP(len, bi->tag_size));\r\nif (nr_sectors * bi->tuple_size > bip->bip_size) {\r\nprintk(KERN_ERR "%s: tag too big for bio: %u > %u\n",\r\n__func__, nr_sectors * bi->tuple_size, bip->bip_size);\r\nreturn -1;\r\n}\r\nif (set)\r\nbi->set_tag_fn(bip->bip_buf, tag_buf, nr_sectors);\r\nelse\r\nbi->get_tag_fn(bip->bip_buf, tag_buf, nr_sectors);\r\nreturn 0;\r\n}\r\nint bio_integrity_set_tag(struct bio *bio, void *tag_buf, unsigned int len)\r\n{\r\nBUG_ON(bio_data_dir(bio) != WRITE);\r\nreturn bio_integrity_tag(bio, tag_buf, len, 1);\r\n}\r\nint bio_integrity_get_tag(struct bio *bio, void *tag_buf, unsigned int len)\r\n{\r\nBUG_ON(bio_data_dir(bio) != READ);\r\nreturn bio_integrity_tag(bio, tag_buf, len, 0);\r\n}\r\nstatic void bio_integrity_generate(struct bio *bio)\r\n{\r\nstruct blk_integrity *bi = bdev_get_integrity(bio->bi_bdev);\r\nstruct blk_integrity_exchg bix;\r\nstruct bio_vec *bv;\r\nsector_t sector = bio->bi_sector;\r\nunsigned int i, sectors, total;\r\nvoid *prot_buf = bio->bi_integrity->bip_buf;\r\ntotal = 0;\r\nbix.disk_name = bio->bi_bdev->bd_disk->disk_name;\r\nbix.sector_size = bi->sector_size;\r\nbio_for_each_segment(bv, bio, i) {\r\nvoid *kaddr = kmap_atomic(bv->bv_page);\r\nbix.data_buf = kaddr + bv->bv_offset;\r\nbix.data_size = bv->bv_len;\r\nbix.prot_buf = prot_buf;\r\nbix.sector = sector;\r\nbi->generate_fn(&bix);\r\nsectors = bv->bv_len / bi->sector_size;\r\nsector += sectors;\r\nprot_buf += sectors * bi->tuple_size;\r\ntotal += sectors * bi->tuple_size;\r\nBUG_ON(total > bio->bi_integrity->bip_size);\r\nkunmap_atomic(kaddr);\r\n}\r\n}\r\nstatic inline unsigned short blk_integrity_tuple_size(struct blk_integrity *bi)\r\n{\r\nif (bi)\r\nreturn bi->tuple_size;\r\nreturn 0;\r\n}\r\nint bio_integrity_prep(struct bio *bio)\r\n{\r\nstruct bio_integrity_payload *bip;\r\nstruct blk_integrity *bi;\r\nstruct request_queue *q;\r\nvoid *buf;\r\nunsigned long start, end;\r\nunsigned int len, nr_pages;\r\nunsigned int bytes, offset, i;\r\nunsigned int sectors;\r\nbi = bdev_get_integrity(bio->bi_bdev);\r\nq = bdev_get_queue(bio->bi_bdev);\r\nBUG_ON(bi == NULL);\r\nBUG_ON(bio_integrity(bio));\r\nsectors = bio_integrity_hw_sectors(bi, bio_sectors(bio));\r\nlen = sectors * blk_integrity_tuple_size(bi);\r\nbuf = kmalloc(len, GFP_NOIO | q->bounce_gfp);\r\nif (unlikely(buf == NULL)) {\r\nprintk(KERN_ERR "could not allocate integrity buffer\n");\r\nreturn -ENOMEM;\r\n}\r\nend = (((unsigned long) buf) + len + PAGE_SIZE - 1) >> PAGE_SHIFT;\r\nstart = ((unsigned long) buf) >> PAGE_SHIFT;\r\nnr_pages = end - start;\r\nbip = bio_integrity_alloc(bio, GFP_NOIO, nr_pages);\r\nif (unlikely(bip == NULL)) {\r\nprintk(KERN_ERR "could not allocate data integrity bioset\n");\r\nkfree(buf);\r\nreturn -EIO;\r\n}\r\nbip->bip_owns_buf = 1;\r\nbip->bip_buf = buf;\r\nbip->bip_size = len;\r\nbip->bip_sector = bio->bi_sector;\r\noffset = offset_in_page(buf);\r\nfor (i = 0 ; i < nr_pages ; i++) {\r\nint ret;\r\nbytes = PAGE_SIZE - offset;\r\nif (len <= 0)\r\nbreak;\r\nif (bytes > len)\r\nbytes = len;\r\nret = bio_integrity_add_page(bio, virt_to_page(buf),\r\nbytes, offset);\r\nif (ret == 0)\r\nreturn 0;\r\nif (ret < bytes)\r\nbreak;\r\nbuf += bytes;\r\nlen -= bytes;\r\noffset = 0;\r\n}\r\nif (bio_data_dir(bio) == READ) {\r\nbip->bip_end_io = bio->bi_end_io;\r\nbio->bi_end_io = bio_integrity_endio;\r\n}\r\nif (bio_data_dir(bio) == WRITE)\r\nbio_integrity_generate(bio);\r\nreturn 0;\r\n}\r\nstatic int bio_integrity_verify(struct bio *bio)\r\n{\r\nstruct blk_integrity *bi = bdev_get_integrity(bio->bi_bdev);\r\nstruct blk_integrity_exchg bix;\r\nstruct bio_vec *bv;\r\nsector_t sector = bio->bi_integrity->bip_sector;\r\nunsigned int i, sectors, total, ret;\r\nvoid *prot_buf = bio->bi_integrity->bip_buf;\r\nret = total = 0;\r\nbix.disk_name = bio->bi_bdev->bd_disk->disk_name;\r\nbix.sector_size = bi->sector_size;\r\nbio_for_each_segment(bv, bio, i) {\r\nvoid *kaddr = kmap_atomic(bv->bv_page);\r\nbix.data_buf = kaddr + bv->bv_offset;\r\nbix.data_size = bv->bv_len;\r\nbix.prot_buf = prot_buf;\r\nbix.sector = sector;\r\nret = bi->verify_fn(&bix);\r\nif (ret) {\r\nkunmap_atomic(kaddr);\r\nreturn ret;\r\n}\r\nsectors = bv->bv_len / bi->sector_size;\r\nsector += sectors;\r\nprot_buf += sectors * bi->tuple_size;\r\ntotal += sectors * bi->tuple_size;\r\nBUG_ON(total > bio->bi_integrity->bip_size);\r\nkunmap_atomic(kaddr);\r\n}\r\nreturn ret;\r\n}\r\nstatic void bio_integrity_verify_fn(struct work_struct *work)\r\n{\r\nstruct bio_integrity_payload *bip =\r\ncontainer_of(work, struct bio_integrity_payload, bip_work);\r\nstruct bio *bio = bip->bip_bio;\r\nint error;\r\nerror = bio_integrity_verify(bio);\r\nbio->bi_end_io = bip->bip_end_io;\r\nbio_endio(bio, error);\r\n}\r\nvoid bio_integrity_endio(struct bio *bio, int error)\r\n{\r\nstruct bio_integrity_payload *bip = bio->bi_integrity;\r\nBUG_ON(bip->bip_bio != bio);\r\nif (error) {\r\nbio->bi_end_io = bip->bip_end_io;\r\nbio_endio(bio, error);\r\nreturn;\r\n}\r\nINIT_WORK(&bip->bip_work, bio_integrity_verify_fn);\r\nqueue_work(kintegrityd_wq, &bip->bip_work);\r\n}\r\nvoid bio_integrity_mark_head(struct bio_integrity_payload *bip,\r\nunsigned int skip)\r\n{\r\nstruct bio_vec *iv;\r\nunsigned int i;\r\nbip_for_each_vec(iv, bip, i) {\r\nif (skip == 0) {\r\nbip->bip_idx = i;\r\nreturn;\r\n} else if (skip >= iv->bv_len) {\r\nskip -= iv->bv_len;\r\n} else {\r\niv->bv_offset += skip;\r\niv->bv_len -= skip;\r\nbip->bip_idx = i;\r\nreturn;\r\n}\r\n}\r\n}\r\nvoid bio_integrity_mark_tail(struct bio_integrity_payload *bip,\r\nunsigned int len)\r\n{\r\nstruct bio_vec *iv;\r\nunsigned int i;\r\nbip_for_each_vec(iv, bip, i) {\r\nif (len == 0) {\r\nbip->bip_vcnt = i;\r\nreturn;\r\n} else if (len >= iv->bv_len) {\r\nlen -= iv->bv_len;\r\n} else {\r\niv->bv_len = len;\r\nlen = 0;\r\n}\r\n}\r\n}\r\nvoid bio_integrity_advance(struct bio *bio, unsigned int bytes_done)\r\n{\r\nstruct bio_integrity_payload *bip = bio->bi_integrity;\r\nstruct blk_integrity *bi = bdev_get_integrity(bio->bi_bdev);\r\nunsigned int nr_sectors;\r\nBUG_ON(bip == NULL);\r\nBUG_ON(bi == NULL);\r\nnr_sectors = bio_integrity_hw_sectors(bi, bytes_done >> 9);\r\nbio_integrity_mark_head(bip, nr_sectors * bi->tuple_size);\r\n}\r\nvoid bio_integrity_trim(struct bio *bio, unsigned int offset,\r\nunsigned int sectors)\r\n{\r\nstruct bio_integrity_payload *bip = bio->bi_integrity;\r\nstruct blk_integrity *bi = bdev_get_integrity(bio->bi_bdev);\r\nunsigned int nr_sectors;\r\nBUG_ON(bip == NULL);\r\nBUG_ON(bi == NULL);\r\nBUG_ON(!bio_flagged(bio, BIO_CLONED));\r\nnr_sectors = bio_integrity_hw_sectors(bi, sectors);\r\nbip->bip_sector = bip->bip_sector + offset;\r\nbio_integrity_mark_head(bip, offset * bi->tuple_size);\r\nbio_integrity_mark_tail(bip, sectors * bi->tuple_size);\r\n}\r\nvoid bio_integrity_split(struct bio *bio, struct bio_pair *bp, int sectors)\r\n{\r\nstruct blk_integrity *bi;\r\nstruct bio_integrity_payload *bip = bio->bi_integrity;\r\nunsigned int nr_sectors;\r\nif (bio_integrity(bio) == 0)\r\nreturn;\r\nbi = bdev_get_integrity(bio->bi_bdev);\r\nBUG_ON(bi == NULL);\r\nBUG_ON(bip->bip_vcnt != 1);\r\nnr_sectors = bio_integrity_hw_sectors(bi, sectors);\r\nbp->bio1.bi_integrity = &bp->bip1;\r\nbp->bio2.bi_integrity = &bp->bip2;\r\nbp->iv1 = bip->bip_vec[bip->bip_idx];\r\nbp->iv2 = bip->bip_vec[bip->bip_idx];\r\nbp->bip1.bip_vec = &bp->iv1;\r\nbp->bip2.bip_vec = &bp->iv2;\r\nbp->iv1.bv_len = sectors * bi->tuple_size;\r\nbp->iv2.bv_offset += sectors * bi->tuple_size;\r\nbp->iv2.bv_len -= sectors * bi->tuple_size;\r\nbp->bip1.bip_sector = bio->bi_integrity->bip_sector;\r\nbp->bip2.bip_sector = bio->bi_integrity->bip_sector + nr_sectors;\r\nbp->bip1.bip_vcnt = bp->bip2.bip_vcnt = 1;\r\nbp->bip1.bip_idx = bp->bip2.bip_idx = 0;\r\n}\r\nint bio_integrity_clone(struct bio *bio, struct bio *bio_src,\r\ngfp_t gfp_mask)\r\n{\r\nstruct bio_integrity_payload *bip_src = bio_src->bi_integrity;\r\nstruct bio_integrity_payload *bip;\r\nBUG_ON(bip_src == NULL);\r\nbip = bio_integrity_alloc(bio, gfp_mask, bip_src->bip_vcnt);\r\nif (bip == NULL)\r\nreturn -EIO;\r\nmemcpy(bip->bip_vec, bip_src->bip_vec,\r\nbip_src->bip_vcnt * sizeof(struct bio_vec));\r\nbip->bip_sector = bip_src->bip_sector;\r\nbip->bip_vcnt = bip_src->bip_vcnt;\r\nbip->bip_idx = bip_src->bip_idx;\r\nreturn 0;\r\n}\r\nint bioset_integrity_create(struct bio_set *bs, int pool_size)\r\n{\r\nif (bs->bio_integrity_pool)\r\nreturn 0;\r\nbs->bio_integrity_pool = mempool_create_slab_pool(pool_size, bip_slab);\r\nif (!bs->bio_integrity_pool)\r\nreturn -1;\r\nbs->bvec_integrity_pool = biovec_create_pool(bs, pool_size);\r\nif (!bs->bvec_integrity_pool) {\r\nmempool_destroy(bs->bio_integrity_pool);\r\nreturn -1;\r\n}\r\nreturn 0;\r\n}\r\nvoid bioset_integrity_free(struct bio_set *bs)\r\n{\r\nif (bs->bio_integrity_pool)\r\nmempool_destroy(bs->bio_integrity_pool);\r\nif (bs->bvec_integrity_pool)\r\nmempool_destroy(bs->bvec_integrity_pool);\r\n}\r\nvoid __init bio_integrity_init(void)\r\n{\r\nkintegrityd_wq = alloc_workqueue("kintegrityd", WQ_MEM_RECLAIM |\r\nWQ_HIGHPRI | WQ_CPU_INTENSIVE, 1);\r\nif (!kintegrityd_wq)\r\npanic("Failed to create kintegrityd\n");\r\nbip_slab = kmem_cache_create("bio_integrity_payload",\r\nsizeof(struct bio_integrity_payload) +\r\nsizeof(struct bio_vec) * BIP_INLINE_VECS,\r\n0, SLAB_HWCACHE_ALIGN|SLAB_PANIC, NULL);\r\nif (!bip_slab)\r\npanic("Failed to create slab\n");\r\n}
