void fscrypt_release_ctx(struct fscrypt_ctx *ctx)
{
unsigned long flags;
if (ctx->flags & FS_CTX_HAS_BOUNCE_BUFFER_FL && ctx->w.bounce_page) {
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
struct fscrypt_ctx *fscrypt_get_ctx(const struct inode *inode, gfp_t gfp_flags)
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
ctx->flags &= ~FS_CTX_HAS_BOUNCE_BUFFER_FL;
return ctx;
}
static void page_crypt_complete(struct crypto_async_request *req, int res)
{
struct fscrypt_completion_result *ecr = req->data;
if (res == -EINPROGRESS)
return;
ecr->res = res;
complete(&ecr->completion);
}
int fscrypt_do_page_crypto(const struct inode *inode, fscrypt_direction_t rw,
u64 lblk_num, struct page *src_page,
struct page *dest_page, unsigned int len,
unsigned int offs, gfp_t gfp_flags)
{
struct {
__le64 index;
u8 padding[FS_XTS_TWEAK_SIZE - sizeof(__le64)];
} xts_tweak;
struct skcipher_request *req = NULL;
DECLARE_FS_COMPLETION_RESULT(ecr);
struct scatterlist dst, src;
struct fscrypt_info *ci = inode->i_crypt_info;
struct crypto_skcipher *tfm = ci->ci_ctfm;
int res = 0;
BUG_ON(len == 0);
req = skcipher_request_alloc(tfm, gfp_flags);
if (!req) {
printk_ratelimited(KERN_ERR
"%s: crypto_request_alloc() failed\n",
__func__);
return -ENOMEM;
}
skcipher_request_set_callback(
req, CRYPTO_TFM_REQ_MAY_BACKLOG | CRYPTO_TFM_REQ_MAY_SLEEP,
page_crypt_complete, &ecr);
BUILD_BUG_ON(sizeof(xts_tweak) != FS_XTS_TWEAK_SIZE);
xts_tweak.index = cpu_to_le64(lblk_num);
memset(xts_tweak.padding, 0, sizeof(xts_tweak.padding));
sg_init_table(&dst, 1);
sg_set_page(&dst, dest_page, len, offs);
sg_init_table(&src, 1);
sg_set_page(&src, src_page, len, offs);
skcipher_request_set_crypt(req, &src, &dst, len, &xts_tweak);
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
struct page *fscrypt_alloc_bounce_page(struct fscrypt_ctx *ctx,
gfp_t gfp_flags)
{
ctx->w.bounce_page = mempool_alloc(fscrypt_bounce_page_pool, gfp_flags);
if (ctx->w.bounce_page == NULL)
return ERR_PTR(-ENOMEM);
ctx->flags |= FS_CTX_HAS_BOUNCE_BUFFER_FL;
return ctx->w.bounce_page;
}
struct page *fscrypt_encrypt_page(const struct inode *inode,
struct page *page,
unsigned int len,
unsigned int offs,
u64 lblk_num, gfp_t gfp_flags)
{
struct fscrypt_ctx *ctx;
struct page *ciphertext_page = page;
int err;
BUG_ON(len % FS_CRYPTO_BLOCK_SIZE != 0);
if (inode->i_sb->s_cop->flags & FS_CFLG_OWN_PAGES) {
err = fscrypt_do_page_crypto(inode, FS_ENCRYPT, lblk_num, page,
ciphertext_page, len, offs,
gfp_flags);
if (err)
return ERR_PTR(err);
return ciphertext_page;
}
BUG_ON(!PageLocked(page));
ctx = fscrypt_get_ctx(inode, gfp_flags);
if (IS_ERR(ctx))
return (struct page *)ctx;
ciphertext_page = fscrypt_alloc_bounce_page(ctx, gfp_flags);
if (IS_ERR(ciphertext_page))
goto errout;
ctx->w.control_page = page;
err = fscrypt_do_page_crypto(inode, FS_ENCRYPT, lblk_num,
page, ciphertext_page, len, offs,
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
int fscrypt_decrypt_page(const struct inode *inode, struct page *page,
unsigned int len, unsigned int offs, u64 lblk_num)
{
if (!(inode->i_sb->s_cop->flags & FS_CFLG_OWN_PAGES))
BUG_ON(!PageLocked(page));
return fscrypt_do_page_crypto(inode, FS_DECRYPT, lblk_num, page, page,
len, offs, GFP_NOFS);
}
static int fscrypt_d_revalidate(struct dentry *dentry, unsigned int flags)
{
struct dentry *dir;
int dir_has_key, cached_with_key;
if (flags & LOOKUP_RCU)
return -ECHILD;
dir = dget_parent(dentry);
if (!d_inode(dir)->i_sb->s_cop->is_encrypted(d_inode(dir))) {
dput(dir);
return 0;
}
spin_lock(&dentry->d_lock);
cached_with_key = dentry->d_flags & DCACHE_ENCRYPTED_WITH_KEY;
spin_unlock(&dentry->d_lock);
dir_has_key = (d_inode(dir)->i_crypt_info != NULL);
dput(dir);
if ((!cached_with_key && d_is_negative(dentry)) ||
(!cached_with_key && dir_has_key) ||
(cached_with_key && !dir_has_key))
return 0;
return 1;
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
int fscrypt_initialize(unsigned int cop_flags)
{
int i, res = -ENOMEM;
if (cop_flags & FS_CFLG_OWN_PAGES || fscrypt_bounce_page_pool)
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
