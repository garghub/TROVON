static void completion_pages(struct work_struct *work)
{
struct fscrypt_ctx *ctx =
container_of(work, struct fscrypt_ctx, r.work);
struct bio *bio = ctx->r.bio;
struct bio_vec *bv;
int i;
bio_for_each_segment_all(bv, bio, i) {
struct page *page = bv->bv_page;
int ret = fscrypt_decrypt_page(page->mapping->host, page,
PAGE_SIZE, 0, page->index);
if (ret) {
WARN_ON_ONCE(1);
SetPageError(page);
} else {
SetPageUptodate(page);
}
unlock_page(page);
}
fscrypt_release_ctx(ctx);
bio_put(bio);
}
void fscrypt_decrypt_bio_pages(struct fscrypt_ctx *ctx, struct bio *bio)
{
INIT_WORK(&ctx->r.work, completion_pages);
ctx->r.bio = bio;
queue_work(fscrypt_read_workqueue, &ctx->r.work);
}
void fscrypt_pullback_bio_page(struct page **page, bool restore)
{
struct fscrypt_ctx *ctx;
struct page *bounce_page;
if ((*page)->mapping)
return;
bounce_page = *page;
ctx = (struct fscrypt_ctx *)page_private(bounce_page);
*page = ctx->w.control_page;
if (restore)
fscrypt_restore_control_page(bounce_page);
}
int fscrypt_zeroout_range(const struct inode *inode, pgoff_t lblk,
sector_t pblk, unsigned int len)
{
struct fscrypt_ctx *ctx;
struct page *ciphertext_page = NULL;
struct bio *bio;
int ret, err = 0;
BUG_ON(inode->i_sb->s_blocksize != PAGE_SIZE);
ctx = fscrypt_get_ctx(inode, GFP_NOFS);
if (IS_ERR(ctx))
return PTR_ERR(ctx);
ciphertext_page = fscrypt_alloc_bounce_page(ctx, GFP_NOWAIT);
if (IS_ERR(ciphertext_page)) {
err = PTR_ERR(ciphertext_page);
goto errout;
}
while (len--) {
err = fscrypt_do_page_crypto(inode, FS_ENCRYPT, lblk,
ZERO_PAGE(0), ciphertext_page,
PAGE_SIZE, 0, GFP_NOFS);
if (err)
goto errout;
bio = bio_alloc(GFP_NOWAIT, 1);
if (!bio) {
err = -ENOMEM;
goto errout;
}
bio->bi_bdev = inode->i_sb->s_bdev;
bio->bi_iter.bi_sector =
pblk << (inode->i_sb->s_blocksize_bits - 9);
bio_set_op_attrs(bio, REQ_OP_WRITE, 0);
ret = bio_add_page(bio, ciphertext_page,
inode->i_sb->s_blocksize, 0);
if (ret != inode->i_sb->s_blocksize) {
WARN_ON(1);
bio_put(bio);
err = -EIO;
goto errout;
}
err = submit_bio_wait(bio);
if ((err == 0) && bio->bi_error)
err = -EIO;
bio_put(bio);
if (err)
goto errout;
lblk++;
pblk++;
}
err = 0;
errout:
fscrypt_release_ctx(ctx);
return err;
}
