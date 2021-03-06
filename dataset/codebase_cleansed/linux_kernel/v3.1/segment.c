static int logfs_mark_segment_bad(struct super_block *sb, u32 segno)\r\n{\r\nstruct logfs_super *super = logfs_super(sb);\r\nstruct btree_head32 *head = &super->s_reserved_segments;\r\nint err;\r\nerr = btree_insert32(head, segno, (void *)1, GFP_NOFS);\r\nif (err)\r\nreturn err;\r\nlogfs_super(sb)->s_bad_segments++;\r\nreturn 0;\r\n}\r\nint logfs_erase_segment(struct super_block *sb, u32 segno, int ensure_erase)\r\n{\r\nstruct logfs_super *super = logfs_super(sb);\r\nsuper->s_gec++;\r\nreturn super->s_devops->erase(sb, (u64)segno << super->s_segshift,\r\nsuper->s_segsize, ensure_erase);\r\n}\r\nstatic s64 logfs_get_free_bytes(struct logfs_area *area, size_t bytes)\r\n{\r\ns32 ofs;\r\nlogfs_open_area(area, bytes);\r\nofs = area->a_used_bytes;\r\narea->a_used_bytes += bytes;\r\nBUG_ON(area->a_used_bytes >= logfs_super(area->a_sb)->s_segsize);\r\nreturn dev_ofs(area->a_sb, area->a_segno, ofs);\r\n}\r\nstatic struct page *get_mapping_page(struct super_block *sb, pgoff_t index,\r\nint use_filler)\r\n{\r\nstruct logfs_super *super = logfs_super(sb);\r\nstruct address_space *mapping = super->s_mapping_inode->i_mapping;\r\nfiller_t *filler = super->s_devops->readpage;\r\nstruct page *page;\r\nBUG_ON(mapping_gfp_mask(mapping) & __GFP_FS);\r\nif (use_filler)\r\npage = read_cache_page(mapping, index, filler, sb);\r\nelse {\r\npage = find_or_create_page(mapping, index, GFP_NOFS);\r\nunlock_page(page);\r\n}\r\nreturn page;\r\n}\r\nint __logfs_buf_write(struct logfs_area *area, u64 ofs, void *buf, size_t len,\r\nint use_filler)\r\n{\r\npgoff_t index = ofs >> PAGE_SHIFT;\r\nstruct page *page;\r\nlong offset = ofs & (PAGE_SIZE-1);\r\nlong copylen;\r\nBUG_ON(!len && !use_filler);\r\ndo {\r\ncopylen = min((ulong)len, PAGE_SIZE - offset);\r\npage = get_mapping_page(area->a_sb, index, use_filler);\r\nif (IS_ERR(page))\r\nreturn PTR_ERR(page);\r\nBUG_ON(!page);\r\nSetPageUptodate(page);\r\nmemcpy(page_address(page) + offset, buf, copylen);\r\nSetPagePrivate(page);\r\npage_cache_release(page);\r\nbuf += copylen;\r\nlen -= copylen;\r\noffset = 0;\r\nindex++;\r\n} while (len);\r\nreturn 0;\r\n}\r\nstatic void pad_partial_page(struct logfs_area *area)\r\n{\r\nstruct super_block *sb = area->a_sb;\r\nstruct page *page;\r\nu64 ofs = dev_ofs(sb, area->a_segno, area->a_used_bytes);\r\npgoff_t index = ofs >> PAGE_SHIFT;\r\nlong offset = ofs & (PAGE_SIZE-1);\r\nu32 len = PAGE_SIZE - offset;\r\nif (len % PAGE_SIZE) {\r\npage = get_mapping_page(sb, index, 0);\r\nBUG_ON(!page);\r\nmemset(page_address(page) + offset, 0xff, len);\r\nSetPagePrivate(page);\r\npage_cache_release(page);\r\n}\r\n}\r\nstatic void pad_full_pages(struct logfs_area *area)\r\n{\r\nstruct super_block *sb = area->a_sb;\r\nstruct logfs_super *super = logfs_super(sb);\r\nu64 ofs = dev_ofs(sb, area->a_segno, area->a_used_bytes);\r\nu32 len = super->s_segsize - area->a_used_bytes;\r\npgoff_t index = PAGE_CACHE_ALIGN(ofs) >> PAGE_CACHE_SHIFT;\r\npgoff_t no_indizes = len >> PAGE_CACHE_SHIFT;\r\nstruct page *page;\r\nwhile (no_indizes) {\r\npage = get_mapping_page(sb, index, 0);\r\nBUG_ON(!page);\r\nSetPageUptodate(page);\r\nmemset(page_address(page), 0xff, PAGE_CACHE_SIZE);\r\nSetPagePrivate(page);\r\npage_cache_release(page);\r\nindex++;\r\nno_indizes--;\r\n}\r\n}\r\nstatic void pad_wbuf(struct logfs_area *area, int final)\r\n{\r\npad_partial_page(area);\r\nif (final)\r\npad_full_pages(area);\r\n}\r\nstatic void *alias_tree_lookup(struct super_block *sb, u64 ino, u64 bix,\r\nlevel_t level)\r\n{\r\nstruct btree_head128 *head = &logfs_super(sb)->s_object_alias_tree;\r\npgoff_t index = logfs_pack_index(bix, level);\r\nreturn btree_lookup128(head, ino, index);\r\n}\r\nstatic int alias_tree_insert(struct super_block *sb, u64 ino, u64 bix,\r\nlevel_t level, void *val)\r\n{\r\nstruct btree_head128 *head = &logfs_super(sb)->s_object_alias_tree;\r\npgoff_t index = logfs_pack_index(bix, level);\r\nreturn btree_insert128(head, ino, index, val, GFP_NOFS);\r\n}\r\nstatic int btree_write_alias(struct super_block *sb, struct logfs_block *block,\r\nwrite_alias_t *write_one_alias)\r\n{\r\nstruct object_alias_item *item;\r\nint err;\r\nlist_for_each_entry(item, &block->item_list, list) {\r\nerr = write_alias_journal(sb, block->ino, block->bix,\r\nblock->level, item->child_no, item->val);\r\nif (err)\r\nreturn err;\r\n}\r\nreturn 0;\r\n}\r\nint logfs_load_object_aliases(struct super_block *sb,\r\nstruct logfs_obj_alias *oa, int count)\r\n{\r\nstruct logfs_super *super = logfs_super(sb);\r\nstruct logfs_block *block;\r\nstruct object_alias_item *item;\r\nu64 ino, bix;\r\nlevel_t level;\r\nint i, err;\r\nsuper->s_flags |= LOGFS_SB_FLAG_OBJ_ALIAS;\r\ncount /= sizeof(*oa);\r\nfor (i = 0; i < count; i++) {\r\nitem = mempool_alloc(super->s_alias_pool, GFP_NOFS);\r\nif (!item)\r\nreturn -ENOMEM;\r\nmemset(item, 0, sizeof(*item));\r\nsuper->s_no_object_aliases++;\r\nitem->val = oa[i].val;\r\nitem->child_no = be16_to_cpu(oa[i].child_no);\r\nino = be64_to_cpu(oa[i].ino);\r\nbix = be64_to_cpu(oa[i].bix);\r\nlevel = LEVEL(oa[i].level);\r\nlog_aliases("logfs_load_object_aliases(%llx, %llx, %x, %x) %llx\n",\r\nino, bix, level, item->child_no,\r\nbe64_to_cpu(item->val));\r\nblock = alias_tree_lookup(sb, ino, bix, level);\r\nif (!block) {\r\nblock = __alloc_block(sb, ino, bix, level);\r\nblock->ops = &btree_block_ops;\r\nerr = alias_tree_insert(sb, ino, bix, level, block);\r\nBUG_ON(err);\r\n}\r\nif (test_and_set_bit(item->child_no, block->alias_map)) {\r\nprintk(KERN_ERR"LogFS: Alias collision detected\n");\r\nreturn -EIO;\r\n}\r\nlist_move_tail(&block->alias_list, &super->s_object_alias);\r\nlist_add(&item->list, &block->item_list);\r\n}\r\nreturn 0;\r\n}\r\nstatic void kill_alias(void *_block, unsigned long ignore0,\r\nu64 ignore1, u64 ignore2, size_t ignore3)\r\n{\r\nstruct logfs_block *block = _block;\r\nstruct super_block *sb = block->sb;\r\nstruct logfs_super *super = logfs_super(sb);\r\nstruct object_alias_item *item;\r\nwhile (!list_empty(&block->item_list)) {\r\nitem = list_entry(block->item_list.next, typeof(*item), list);\r\nlist_del(&item->list);\r\nmempool_free(item, super->s_alias_pool);\r\n}\r\nblock->ops->free_block(sb, block);\r\n}\r\nstatic int obj_type(struct inode *inode, level_t level)\r\n{\r\nif (level == 0) {\r\nif (S_ISDIR(inode->i_mode))\r\nreturn OBJ_DENTRY;\r\nif (inode->i_ino == LOGFS_INO_MASTER)\r\nreturn OBJ_INODE;\r\n}\r\nreturn OBJ_BLOCK;\r\n}\r\nstatic int obj_len(struct super_block *sb, int obj_type)\r\n{\r\nswitch (obj_type) {\r\ncase OBJ_DENTRY:\r\nreturn sizeof(struct logfs_disk_dentry);\r\ncase OBJ_INODE:\r\nreturn sizeof(struct logfs_disk_inode);\r\ncase OBJ_BLOCK:\r\nreturn sb->s_blocksize;\r\ndefault:\r\nBUG();\r\n}\r\n}\r\nstatic int __logfs_segment_write(struct inode *inode, void *buf,\r\nstruct logfs_shadow *shadow, int type, int len, int compr)\r\n{\r\nstruct logfs_area *area;\r\nstruct super_block *sb = inode->i_sb;\r\ns64 ofs;\r\nstruct logfs_object_header h;\r\nint acc_len;\r\nif (shadow->gc_level == 0)\r\nacc_len = len;\r\nelse\r\nacc_len = obj_len(sb, type);\r\narea = get_area(sb, shadow->gc_level);\r\nofs = logfs_get_free_bytes(area, len + LOGFS_OBJECT_HEADERSIZE);\r\nLOGFS_BUG_ON(ofs <= 0, sb);\r\nh.len = cpu_to_be16(len);\r\nh.type = type;\r\nh.compr = compr;\r\nh.ino = cpu_to_be64(inode->i_ino);\r\nh.bix = cpu_to_be64(shadow->bix);\r\nh.crc = logfs_crc32(&h, sizeof(h) - 4, 4);\r\nh.data_crc = logfs_crc32(buf, len, 0);\r\nlogfs_buf_write(area, ofs, &h, sizeof(h));\r\nlogfs_buf_write(area, ofs + LOGFS_OBJECT_HEADERSIZE, buf, len);\r\nshadow->new_ofs = ofs;\r\nshadow->new_len = acc_len + LOGFS_OBJECT_HEADERSIZE;\r\nreturn 0;\r\n}\r\nstatic s64 logfs_segment_write_compress(struct inode *inode, void *buf,\r\nstruct logfs_shadow *shadow, int type, int len)\r\n{\r\nstruct super_block *sb = inode->i_sb;\r\nvoid *compressor_buf = logfs_super(sb)->s_compressed_je;\r\nssize_t compr_len;\r\nint ret;\r\nmutex_lock(&logfs_super(sb)->s_journal_mutex);\r\ncompr_len = logfs_compress(buf, compressor_buf, len, len);\r\nif (compr_len >= 0) {\r\nret = __logfs_segment_write(inode, compressor_buf, shadow,\r\ntype, compr_len, COMPR_ZLIB);\r\n} else {\r\nret = __logfs_segment_write(inode, buf, shadow, type, len,\r\nCOMPR_NONE);\r\n}\r\nmutex_unlock(&logfs_super(sb)->s_journal_mutex);\r\nreturn ret;\r\n}\r\nint logfs_segment_write(struct inode *inode, struct page *page,\r\nstruct logfs_shadow *shadow)\r\n{\r\nstruct super_block *sb = inode->i_sb;\r\nstruct logfs_super *super = logfs_super(sb);\r\nint do_compress, type, len;\r\nint ret;\r\nvoid *buf;\r\nsuper->s_flags |= LOGFS_SB_FLAG_DIRTY;\r\nBUG_ON(super->s_flags & LOGFS_SB_FLAG_SHUTDOWN);\r\ndo_compress = logfs_inode(inode)->li_flags & LOGFS_IF_COMPRESSED;\r\nif (shadow->gc_level != 0) {\r\ndo_compress = 0;\r\n}\r\ntype = obj_type(inode, shrink_level(shadow->gc_level));\r\nlen = obj_len(sb, type);\r\nbuf = kmap(page);\r\nif (do_compress)\r\nret = logfs_segment_write_compress(inode, buf, shadow, type,\r\nlen);\r\nelse\r\nret = __logfs_segment_write(inode, buf, shadow, type, len,\r\nCOMPR_NONE);\r\nkunmap(page);\r\nlog_segment("logfs_segment_write(%llx, %llx, %x) %llx->%llx %x->%x\n",\r\nshadow->ino, shadow->bix, shadow->gc_level,\r\nshadow->old_ofs, shadow->new_ofs,\r\nshadow->old_len, shadow->new_len);\r\nBUG_ON(!(shadow->new_ofs & (super->s_segsize - 1)));\r\nreturn ret;\r\n}\r\nint wbuf_read(struct super_block *sb, u64 ofs, size_t len, void *buf)\r\n{\r\npgoff_t index = ofs >> PAGE_SHIFT;\r\nstruct page *page;\r\nlong offset = ofs & (PAGE_SIZE-1);\r\nlong copylen;\r\nwhile (len) {\r\ncopylen = min((ulong)len, PAGE_SIZE - offset);\r\npage = get_mapping_page(sb, index, 1);\r\nif (IS_ERR(page))\r\nreturn PTR_ERR(page);\r\nmemcpy(buf, page_address(page) + offset, copylen);\r\npage_cache_release(page);\r\nbuf += copylen;\r\nlen -= copylen;\r\noffset = 0;\r\nindex++;\r\n}\r\nreturn 0;\r\n}\r\nstatic int check_pos(struct super_block *sb, u64 pos1, u64 pos2, level_t level)\r\n{\r\nreturn (pos1 & logfs_block_mask(sb, level)) !=\r\n(pos2 & logfs_block_mask(sb, level));\r\n}\r\nstatic int read_obj_header(struct super_block *sb, u64 ofs,\r\nstruct logfs_object_header *oh)\r\n{\r\n__be32 crc;\r\nint err;\r\nerr = wbuf_read(sb, ofs, sizeof(*oh), oh);\r\nif (err)\r\nreturn err;\r\ncrc = logfs_crc32(oh, sizeof(*oh) - 4, 4);\r\nif (crc != oh->crc) {\r\nprintk(KERN_ERR"LOGFS: header crc error at %llx: expected %x, "\r\n"got %x\n", ofs, be32_to_cpu(oh->crc),\r\nbe32_to_cpu(crc));\r\nreturn -EIO;\r\n}\r\nreturn 0;\r\n}\r\nstatic void move_btree_to_page(struct inode *inode, struct page *page,\r\n__be64 *data)\r\n{\r\nstruct super_block *sb = inode->i_sb;\r\nstruct logfs_super *super = logfs_super(sb);\r\nstruct btree_head128 *head = &super->s_object_alias_tree;\r\nstruct logfs_block *block;\r\nstruct object_alias_item *item, *next;\r\nif (!(super->s_flags & LOGFS_SB_FLAG_OBJ_ALIAS))\r\nreturn;\r\nblock = btree_remove128(head, inode->i_ino, page->index);\r\nif (!block)\r\nreturn;\r\nlog_blockmove("move_btree_to_page(%llx, %llx, %x)\n",\r\nblock->ino, block->bix, block->level);\r\nlist_for_each_entry_safe(item, next, &block->item_list, list) {\r\ndata[item->child_no] = item->val;\r\nlist_del(&item->list);\r\nmempool_free(item, super->s_alias_pool);\r\n}\r\nblock->page = page;\r\nSetPagePrivate(page);\r\npage->private = (unsigned long)block;\r\nblock->ops = &indirect_block_ops;\r\ninitialize_block_counters(page, block, data, 0);\r\n}\r\nstatic unsigned long fnb(const unsigned long *addr,\r\nunsigned long size, unsigned long offset)\r\n{\r\nreturn find_next_bit(addr, size, offset);\r\n}\r\nvoid move_page_to_btree(struct page *page)\r\n{\r\nstruct logfs_block *block = logfs_block(page);\r\nstruct super_block *sb = block->sb;\r\nstruct logfs_super *super = logfs_super(sb);\r\nstruct object_alias_item *item;\r\nunsigned long pos;\r\n__be64 *child;\r\nint err;\r\nif (super->s_flags & LOGFS_SB_FLAG_SHUTDOWN) {\r\nblock->ops->free_block(sb, block);\r\nreturn;\r\n}\r\nlog_blockmove("move_page_to_btree(%llx, %llx, %x)\n",\r\nblock->ino, block->bix, block->level);\r\nsuper->s_flags |= LOGFS_SB_FLAG_OBJ_ALIAS;\r\nfor (pos = 0; ; pos++) {\r\npos = fnb(block->alias_map, LOGFS_BLOCK_FACTOR, pos);\r\nif (pos >= LOGFS_BLOCK_FACTOR)\r\nbreak;\r\nitem = mempool_alloc(super->s_alias_pool, GFP_NOFS);\r\nBUG_ON(!item);\r\nmemset(item, 0, sizeof(*item));\r\nchild = kmap_atomic(page, KM_USER0);\r\nitem->val = child[pos];\r\nkunmap_atomic(child, KM_USER0);\r\nitem->child_no = pos;\r\nlist_add(&item->list, &block->item_list);\r\n}\r\nblock->page = NULL;\r\nClearPagePrivate(page);\r\npage->private = 0;\r\nblock->ops = &btree_block_ops;\r\nerr = alias_tree_insert(block->sb, block->ino, block->bix, block->level,\r\nblock);\r\nBUG_ON(err);\r\nClearPageUptodate(page);\r\n}\r\nstatic int __logfs_segment_read(struct inode *inode, void *buf,\r\nu64 ofs, u64 bix, level_t level)\r\n{\r\nstruct super_block *sb = inode->i_sb;\r\nvoid *compressor_buf = logfs_super(sb)->s_compressed_je;\r\nstruct logfs_object_header oh;\r\n__be32 crc;\r\nu16 len;\r\nint err, block_len;\r\nblock_len = obj_len(sb, obj_type(inode, level));\r\nerr = read_obj_header(sb, ofs, &oh);\r\nif (err)\r\ngoto out_err;\r\nerr = -EIO;\r\nif (be64_to_cpu(oh.ino) != inode->i_ino\r\n|| check_pos(sb, be64_to_cpu(oh.bix), bix, level)) {\r\nprintk(KERN_ERR"LOGFS: (ino, bix) don't match at %llx: "\r\n"expected (%lx, %llx), got (%llx, %llx)\n",\r\nofs, inode->i_ino, bix,\r\nbe64_to_cpu(oh.ino), be64_to_cpu(oh.bix));\r\ngoto out_err;\r\n}\r\nlen = be16_to_cpu(oh.len);\r\nswitch (oh.compr) {\r\ncase COMPR_NONE:\r\nerr = wbuf_read(sb, ofs + LOGFS_OBJECT_HEADERSIZE, len, buf);\r\nif (err)\r\ngoto out_err;\r\ncrc = logfs_crc32(buf, len, 0);\r\nif (crc != oh.data_crc) {\r\nprintk(KERN_ERR"LOGFS: uncompressed data crc error at "\r\n"%llx: expected %x, got %x\n", ofs,\r\nbe32_to_cpu(oh.data_crc),\r\nbe32_to_cpu(crc));\r\ngoto out_err;\r\n}\r\nbreak;\r\ncase COMPR_ZLIB:\r\nmutex_lock(&logfs_super(sb)->s_journal_mutex);\r\nerr = wbuf_read(sb, ofs + LOGFS_OBJECT_HEADERSIZE, len,\r\ncompressor_buf);\r\nif (err) {\r\nmutex_unlock(&logfs_super(sb)->s_journal_mutex);\r\ngoto out_err;\r\n}\r\ncrc = logfs_crc32(compressor_buf, len, 0);\r\nif (crc != oh.data_crc) {\r\nprintk(KERN_ERR"LOGFS: compressed data crc error at "\r\n"%llx: expected %x, got %x\n", ofs,\r\nbe32_to_cpu(oh.data_crc),\r\nbe32_to_cpu(crc));\r\nmutex_unlock(&logfs_super(sb)->s_journal_mutex);\r\ngoto out_err;\r\n}\r\nerr = logfs_uncompress(compressor_buf, buf, len, block_len);\r\nmutex_unlock(&logfs_super(sb)->s_journal_mutex);\r\nif (err) {\r\nprintk(KERN_ERR"LOGFS: uncompress error at %llx\n", ofs);\r\ngoto out_err;\r\n}\r\nbreak;\r\ndefault:\r\nLOGFS_BUG(sb);\r\nerr = -EIO;\r\ngoto out_err;\r\n}\r\nreturn 0;\r\nout_err:\r\nlogfs_set_ro(sb);\r\nprintk(KERN_ERR"LOGFS: device is read-only now\n");\r\nLOGFS_BUG(sb);\r\nreturn err;\r\n}\r\nint logfs_segment_read(struct inode *inode, struct page *page,\r\nu64 ofs, u64 bix, level_t level)\r\n{\r\nint err;\r\nvoid *buf;\r\nif (PageUptodate(page))\r\nreturn 0;\r\nofs &= ~LOGFS_FULLY_POPULATED;\r\nbuf = kmap(page);\r\nerr = __logfs_segment_read(inode, buf, ofs, bix, level);\r\nif (!err) {\r\nmove_btree_to_page(inode, page, buf);\r\nSetPageUptodate(page);\r\n}\r\nkunmap(page);\r\nlog_segment("logfs_segment_read(%lx, %llx, %x) %llx (%d)\n",\r\ninode->i_ino, bix, level, ofs, err);\r\nreturn err;\r\n}\r\nint logfs_segment_delete(struct inode *inode, struct logfs_shadow *shadow)\r\n{\r\nstruct super_block *sb = inode->i_sb;\r\nstruct logfs_super *super = logfs_super(sb);\r\nstruct logfs_object_header h;\r\nu16 len;\r\nint err;\r\nsuper->s_flags |= LOGFS_SB_FLAG_DIRTY;\r\nBUG_ON(super->s_flags & LOGFS_SB_FLAG_SHUTDOWN);\r\nBUG_ON(shadow->old_ofs & LOGFS_FULLY_POPULATED);\r\nif (!shadow->old_ofs)\r\nreturn 0;\r\nlog_segment("logfs_segment_delete(%llx, %llx, %x) %llx->%llx %x->%x\n",\r\nshadow->ino, shadow->bix, shadow->gc_level,\r\nshadow->old_ofs, shadow->new_ofs,\r\nshadow->old_len, shadow->new_len);\r\nerr = read_obj_header(sb, shadow->old_ofs, &h);\r\nLOGFS_BUG_ON(err, sb);\r\nLOGFS_BUG_ON(be64_to_cpu(h.ino) != inode->i_ino, sb);\r\nLOGFS_BUG_ON(check_pos(sb, shadow->bix, be64_to_cpu(h.bix),\r\nshrink_level(shadow->gc_level)), sb);\r\nif (shadow->gc_level == 0)\r\nlen = be16_to_cpu(h.len);\r\nelse\r\nlen = obj_len(sb, h.type);\r\nshadow->old_len = len + sizeof(h);\r\nreturn 0;\r\n}\r\nvoid freeseg(struct super_block *sb, u32 segno)\r\n{\r\nstruct logfs_super *super = logfs_super(sb);\r\nstruct address_space *mapping = super->s_mapping_inode->i_mapping;\r\nstruct page *page;\r\nu64 ofs, start, end;\r\nstart = dev_ofs(sb, segno, 0);\r\nend = dev_ofs(sb, segno + 1, 0);\r\nfor (ofs = start; ofs < end; ofs += PAGE_SIZE) {\r\npage = find_get_page(mapping, ofs >> PAGE_SHIFT);\r\nif (!page)\r\ncontinue;\r\nClearPagePrivate(page);\r\npage_cache_release(page);\r\n}\r\n}\r\nint logfs_open_area(struct logfs_area *area, size_t bytes)\r\n{\r\nstruct super_block *sb = area->a_sb;\r\nstruct logfs_super *super = logfs_super(sb);\r\nint err, closed = 0;\r\nif (area->a_is_open && area->a_used_bytes + bytes <= super->s_segsize)\r\nreturn 0;\r\nif (area->a_is_open) {\r\nu64 ofs = dev_ofs(sb, area->a_segno, area->a_written_bytes);\r\nu32 len = super->s_segsize - area->a_written_bytes;\r\nlog_gc("logfs_close_area(%x)\n", area->a_segno);\r\npad_wbuf(area, 1);\r\nsuper->s_devops->writeseg(area->a_sb, ofs, len);\r\nfreeseg(sb, area->a_segno);\r\nclosed = 1;\r\n}\r\narea->a_used_bytes = 0;\r\narea->a_written_bytes = 0;\r\nagain:\r\narea->a_ops->get_free_segment(area);\r\narea->a_ops->get_erase_count(area);\r\nlog_gc("logfs_open_area(%x, %x)\n", area->a_segno, area->a_level);\r\nerr = area->a_ops->erase_segment(area);\r\nif (err) {\r\nprintk(KERN_WARNING "LogFS: Error erasing segment %x\n",\r\narea->a_segno);\r\nlogfs_mark_segment_bad(sb, area->a_segno);\r\ngoto again;\r\n}\r\narea->a_is_open = 1;\r\nreturn closed;\r\n}\r\nvoid logfs_sync_area(struct logfs_area *area)\r\n{\r\nstruct super_block *sb = area->a_sb;\r\nstruct logfs_super *super = logfs_super(sb);\r\nu64 ofs = dev_ofs(sb, area->a_segno, area->a_written_bytes);\r\nu32 len = (area->a_used_bytes - area->a_written_bytes);\r\nif (super->s_writesize)\r\nlen &= ~(super->s_writesize - 1);\r\nif (len == 0)\r\nreturn;\r\npad_wbuf(area, 0);\r\nsuper->s_devops->writeseg(sb, ofs, len);\r\narea->a_written_bytes += len;\r\n}\r\nvoid logfs_sync_segments(struct super_block *sb)\r\n{\r\nstruct logfs_super *super = logfs_super(sb);\r\nint i;\r\nfor_each_area(i)\r\nlogfs_sync_area(super->s_area[i]);\r\n}\r\nstatic void ostore_get_free_segment(struct logfs_area *area)\r\n{\r\nstruct super_block *sb = area->a_sb;\r\nstruct logfs_super *super = logfs_super(sb);\r\nif (super->s_free_list.count == 0) {\r\nprintk(KERN_ERR"LOGFS: ran out of free segments\n");\r\nLOGFS_BUG(sb);\r\n}\r\narea->a_segno = get_best_cand(sb, &super->s_free_list, NULL);\r\n}\r\nstatic void ostore_get_erase_count(struct logfs_area *area)\r\n{\r\nstruct logfs_segment_entry se;\r\nu32 ec_level;\r\nlogfs_get_segment_entry(area->a_sb, area->a_segno, &se);\r\nBUG_ON(se.ec_level == cpu_to_be32(BADSEG) ||\r\nse.valid == cpu_to_be32(RESERVED));\r\nec_level = be32_to_cpu(se.ec_level);\r\narea->a_erase_count = (ec_level >> 4) + 1;\r\n}\r\nstatic int ostore_erase_segment(struct logfs_area *area)\r\n{\r\nstruct super_block *sb = area->a_sb;\r\nstruct logfs_segment_header sh;\r\nu64 ofs;\r\nint err;\r\nerr = logfs_erase_segment(sb, area->a_segno, 0);\r\nif (err)\r\nreturn err;\r\nsh.pad = 0;\r\nsh.type = SEG_OSTORE;\r\nsh.level = (__force u8)area->a_level;\r\nsh.segno = cpu_to_be32(area->a_segno);\r\nsh.ec = cpu_to_be32(area->a_erase_count);\r\nsh.gec = cpu_to_be64(logfs_super(sb)->s_gec);\r\nsh.crc = logfs_crc32(&sh, sizeof(sh), 4);\r\nlogfs_set_segment_erased(sb, area->a_segno, area->a_erase_count,\r\narea->a_level);\r\nofs = dev_ofs(sb, area->a_segno, 0);\r\narea->a_used_bytes = sizeof(sh);\r\nlogfs_buf_write(area, ofs, &sh, sizeof(sh));\r\nreturn 0;\r\n}\r\nstatic void free_area(struct logfs_area *area)\r\n{\r\nif (area)\r\nfreeseg(area->a_sb, area->a_segno);\r\nkfree(area);\r\n}\r\nstatic struct logfs_area *alloc_area(struct super_block *sb)\r\n{\r\nstruct logfs_area *area;\r\narea = kzalloc(sizeof(*area), GFP_KERNEL);\r\nif (!area)\r\nreturn NULL;\r\narea->a_sb = sb;\r\nreturn area;\r\n}\r\nstatic void map_invalidatepage(struct page *page, unsigned long l)\r\n{\r\nBUG();\r\n}\r\nstatic int map_releasepage(struct page *page, gfp_t g)\r\n{\r\nreturn 0;\r\n}\r\nint logfs_init_mapping(struct super_block *sb)\r\n{\r\nstruct logfs_super *super = logfs_super(sb);\r\nstruct address_space *mapping;\r\nstruct inode *inode;\r\ninode = logfs_new_meta_inode(sb, LOGFS_INO_MAPPING);\r\nif (IS_ERR(inode))\r\nreturn PTR_ERR(inode);\r\nsuper->s_mapping_inode = inode;\r\nmapping = inode->i_mapping;\r\nmapping->a_ops = &mapping_aops;\r\nmapping_set_gfp_mask(mapping, GFP_NOFS);\r\nreturn 0;\r\n}\r\nint logfs_init_areas(struct super_block *sb)\r\n{\r\nstruct logfs_super *super = logfs_super(sb);\r\nint i = -1;\r\nsuper->s_alias_pool = mempool_create_kmalloc_pool(600,\r\nsizeof(struct object_alias_item));\r\nif (!super->s_alias_pool)\r\nreturn -ENOMEM;\r\nsuper->s_journal_area = alloc_area(sb);\r\nif (!super->s_journal_area)\r\ngoto err;\r\nfor_each_area(i) {\r\nsuper->s_area[i] = alloc_area(sb);\r\nif (!super->s_area[i])\r\ngoto err;\r\nsuper->s_area[i]->a_level = GC_LEVEL(i);\r\nsuper->s_area[i]->a_ops = &ostore_area_ops;\r\n}\r\nbtree_init_mempool128(&super->s_object_alias_tree,\r\nsuper->s_btree_pool);\r\nreturn 0;\r\nerr:\r\nfor (i--; i >= 0; i--)\r\nfree_area(super->s_area[i]);\r\nfree_area(super->s_journal_area);\r\nlogfs_mempool_destroy(super->s_alias_pool);\r\nreturn -ENOMEM;\r\n}\r\nvoid logfs_cleanup_areas(struct super_block *sb)\r\n{\r\nstruct logfs_super *super = logfs_super(sb);\r\nint i;\r\nbtree_grim_visitor128(&super->s_object_alias_tree, 0, kill_alias);\r\nfor_each_area(i)\r\nfree_area(super->s_area[i]);\r\nfree_area(super->s_journal_area);\r\n}
