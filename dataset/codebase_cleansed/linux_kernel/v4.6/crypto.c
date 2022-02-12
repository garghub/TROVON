void fscrypt_release_ctx(struct fscrypt_ctx *ctx)
{
unsigned long flags;
if (ctx->flags & FS_WRITE_PATH_FL && ctx->w.bounce_page) {
mempool_free(ctx->w.bounce_page, fscrypt_bounce_page_pool);
ctx->w.bounce_page = NULL;
}
ctx->w.control_page = NULL;
if (ctx->flags & FS_CTX_REQUIRES_FREE_ENCRYPT_FL) {
kmem_cache_free(fscrypt_ctx_cachep, ctx);
} else {
spin_lock_irqsave(&fscrypt_ctx_lock, flags);
list_add(&ctx->free_list, &fscrypt_free_ctxs);
spin_unlock_irqrestore(&fscrypt_ctx_lock, flags);
}
}
struct fscrypt_ctx *fscrypt_get_ctx(struct inode *inode, gfp_t gfp_flags)
{
struct fscrypt_ctx *ctx = NULL;
struct fscrypt_info *ci = inode->i_crypt_info;
unsigned long flags;
if (ci == NULL)
return ERR_PTR(-ENOKEY);
spin_lock_irqsave(&fscrypt_ctx_lock, flags);
ctx = list_first_entry_or_null(&fscrypt_free_ctxs,
struct fscrypt_ctx, free_list);
if (ctx)
list_del(&ctx->free_list);
spin_unlock_irqrestore(&fscrypt_ctx_lock, flags);
if (!ctx) {
ctx = kmem_cache_zalloc(fscrypt_ctx_cachep, gfp_flags);
if (!ctx)
return ERR_PTR(-ENOMEM);
ctx->flags |= FS_CTX_REQUIRES_FREE_ENCRYPT_FL;
} else {
ctx->flags &= ~FS_CTX_REQUIRES_FREE_ENCRYPT_FL;
}
ctx->flags &= ~FS_WRITE_PATH_FL;
return ctx;
}
static void fscrypt_complete(struct crypto_async_request *req, int res)
{
struct fscrypt_completion_result *ecr = req->data;
if (res == -EINPROGRESS)
return;
ecr->res = res;
complete(&ecr->completion);
}
static int do_page_crypto(struct inode *inode,
fscrypt_direction_t rw, pgoff_t index,
struct page *src_page, struct page *dest_page,
gfp_t gfp_flags)
{
u8 xts_tweak[FS_XTS_TWEAK_SIZE];
struct skcipher_request *req = NULL;
DECLARE_FS_COMPLETION_RESULT(ecr);
struct scatterlist dst, src;
struct fscrypt_info *ci = inode->i_crypt_info;
struct crypto_skcipher *tfm = ci->ci_ctfm;
int res = 0;
req = skcipher_request_alloc(tfm, gfp_flags);
if (!req) {
printk_ratelimited(KERN_ERR
"%s: crypto_request_alloc() failed\n",
__func__);
return -ENOMEM;
}
skcipher_request_set_callback(
req, CRYPTO_TFM_REQ_MAY_BACKLOG | CRYPTO_TFM_REQ_MAY_SLEEP,
fscrypt_complete, &ecr);
BUILD_BUG_ON(FS_XTS_TWEAK_SIZE < sizeof(index));
memcpy(xts_tweak, &index, sizeof(index));
memset(&xts_tweak[sizeof(index)], 0,
FS_XTS_TWEAK_SIZE - sizeof(index));
sg_init_table(&dst, 1);
sg_set_page(&dst, dest_page, PAGE_SIZE, 0);
sg_init_table(&src, 1);
sg_set_page(&src, src_page, PAGE_SIZE, 0);
skcipher_request_set_crypt(req, &src, &dst, PAGE_SIZE,
xts_tweak);
if (rw == FS_DECRYPT)
res = crypto_skcipher_decrypt(req);
else
res = crypto_skcipher_encrypt(req);
if (res == -EINPROGRESS || res == -EBUSY) {
BUG_ON(req->base.data != &ecr);
wait_for_completion(&ecr.completion);
res = ecr.res;
}
skcipher_request_free(req);
if (res) {
printk_ratelimited(KERN_ERR
"%s: crypto_skcipher_encrypt() returned %d\n",
__func__, res);
return res;
}
return 0;
}
static struct page *alloc_bounce_page(struct fscrypt_ctx *ctx, gfp_t gfp_flags)
{
ctx->w.bounce_page = mempool_alloc(fscrypt_bounce_page_pool, gfp_flags);
if (ctx->w.bounce_page == NULL)
return ERR_PTR(-ENOMEM);
ctx->flags |= FS_WRITE_PATH_FL;
return ctx->w.bounce_page;
}
struct page *fscrypt_encrypt_page(struct inode *inode,
struct page *plaintext_page, gfp_t gfp_flags)
{
struct fscrypt_ctx *ctx;
struct page *ciphertext_page = NULL;
int err;
BUG_ON(!PageLocked(plaintext_page));
ctx = fscrypt_get_ctx(inode, gfp_flags);
if (IS_ERR(ctx))
return (struct page *)ctx;
ciphertext_page = alloc_bounce_page(ctx, gfp_flags);
if (IS_ERR(ciphertext_page))
goto errout;
ctx->w.control_page = plaintext_page;
err = do_page_crypto(inode, FS_ENCRYPT, plaintext_page->index,
plaintext_page, ciphertext_page,
gfp_flags);
if (err) {
ciphertext_page = ERR_PTR(err);
goto errout;
}
SetPagePrivate(ciphertext_page);
set_page_private(ciphertext_page, (unsigned long)ctx);
lock_page(ciphertext_page);
return ciphertext_page;
errout:
fscrypt_release_ctx(ctx);
return ciphertext_page;
}
int fscrypt_decrypt_page(struct page *page)
{
BUG_ON(!PageLocked(page));
return do_page_crypto(page->mapping->host,
FS_DECRYPT, page->index, page, page, GFP_NOFS);
}
int fscrypt_zeroout_range(struct inode *inode, pgoff_t lblk,
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
ciphertext_page = alloc_bounce_page(ctx, GFP_NOWAIT);
if (IS_ERR(ciphertext_page)) {
err = PTR_ERR(ciphertext_page);
goto errout;
}
while (len--) {
err = do_page_crypto(inode, FS_ENCRYPT, lblk,
ZERO_PAGE(0), ciphertext_page,
GFP_NOFS);
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
ret = bio_add_page(bio, ciphertext_page,
inode->i_sb->s_blocksize, 0);
if (ret != inode->i_sb->s_blocksize) {
WARN_ON(1);
bio_put(bio);
err = -EIO;
goto errout;
}
err = submit_bio_wait(WRITE, bio);
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
static int fscrypt_d_revalidate(struct dentry *dentry, unsigned int flags)
{
struct dentry *dir;
struct fscrypt_info *ci;
int dir_has_key, cached_with_key;
if (flags & LOOKUP_RCU)
return -ECHILD;
dir = dget_parent(dentry);
if (!d_inode(dir)->i_sb->s_cop->is_encrypted(d_inode(dir))) {
dput(dir);
return 0;
}
ci = d_inode(dir)->i_crypt_info;
if (ci && ci->ci_keyring_key &&
(ci->ci_keyring_key->flags & ((1 << KEY_FLAG_INVALIDATED) |
(1 << KEY_FLAG_REVOKED) |
(1 << KEY_FLAG_DEAD))))
ci = NULL;
spin_lock(&dentry->d_lock);
cached_with_key = dentry->d_flags & DCACHE_ENCRYPTED_WITH_KEY;
spin_unlock(&dentry->d_lock);
dir_has_key = (ci != NULL);
dput(dir);
if ((!cached_with_key && d_is_negative(dentry)) ||
(!cached_with_key && dir_has_key) ||
(cached_with_key && !dir_has_key))
return 0;
return 1;
}
static void completion_pages(struct work_struct *work)
{
struct fscrypt_ctx *ctx =
container_of(work, struct fscrypt_ctx, r.work);
struct bio *bio = ctx->r.bio;
struct bio_vec *bv;
int i;
bio_for_each_segment_all(bv, bio, i) {
struct page *page = bv->bv_page;
int ret = fscrypt_decrypt_page(page);
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
void fscrypt_restore_control_page(struct page *page)
{
struct fscrypt_ctx *ctx;
ctx = (struct fscrypt_ctx *)page_private(page);
set_page_private(page, (unsigned long)NULL);
ClearPagePrivate(page);
unlock_page(page);
fscrypt_release_ctx(ctx);
}
static void fscrypt_destroy(void)
{
struct fscrypt_ctx *pos, *n;
list_for_each_entry_safe(pos, n, &fscrypt_free_ctxs, free_list)
kmem_cache_free(fscrypt_ctx_cachep, pos);
INIT_LIST_HEAD(&fscrypt_free_ctxs);
mempool_destroy(fscrypt_bounce_page_pool);
fscrypt_bounce_page_pool = NULL;
}
int fscrypt_initialize(void)
{
int i, res = -ENOMEM;
if (fscrypt_bounce_page_pool)
return 0;
mutex_lock(&fscrypt_init_mutex);
if (fscrypt_bounce_page_pool)
goto already_initialized;
for (i = 0; i < num_prealloc_crypto_ctxs; i++) {
struct fscrypt_ctx *ctx;
ctx = kmem_cache_zalloc(fscrypt_ctx_cachep, GFP_NOFS);
if (!ctx)
goto fail;
list_add(&ctx->free_list, &fscrypt_free_ctxs);
}
fscrypt_bounce_page_pool =
mempool_create_page_pool(num_prealloc_crypto_pages, 0);
if (!fscrypt_bounce_page_pool)
goto fail;
already_initialized:
mutex_unlock(&fscrypt_init_mutex);
return 0;
fail:
fscrypt_destroy();
mutex_unlock(&fscrypt_init_mutex);
return res;
}
static int __init fscrypt_init(void)
{
fscrypt_read_workqueue = alloc_workqueue("fscrypt_read_queue",
WQ_HIGHPRI, 0);
if (!fscrypt_read_workqueue)
goto fail;
fscrypt_ctx_cachep = KMEM_CACHE(fscrypt_ctx, SLAB_RECLAIM_ACCOUNT);
if (!fscrypt_ctx_cachep)
goto fail_free_queue;
fscrypt_info_cachep = KMEM_CACHE(fscrypt_info, SLAB_RECLAIM_ACCOUNT);
if (!fscrypt_info_cachep)
goto fail_free_ctx;
return 0;
fail_free_ctx:
kmem_cache_destroy(fscrypt_ctx_cachep);
fail_free_queue:
destroy_workqueue(fscrypt_read_workqueue);
fail:
return -ENOMEM;
}
static void __exit fscrypt_exit(void)
{
fscrypt_destroy();
if (fscrypt_read_workqueue)
destroy_workqueue(fscrypt_read_workqueue);
kmem_cache_destroy(fscrypt_ctx_cachep);
kmem_cache_destroy(fscrypt_info_cachep);
}
