void hwbm_buf_free(struct hwbm_pool *bm_pool, void *buf)
{
if (likely(bm_pool->frag_size <= PAGE_SIZE))
skb_free_frag(buf);
else
kfree(buf);
}
int hwbm_pool_refill(struct hwbm_pool *bm_pool, gfp_t gfp)
{
int frag_size = bm_pool->frag_size;
void *buf;
if (likely(frag_size <= PAGE_SIZE))
buf = netdev_alloc_frag(frag_size);
else
buf = kmalloc(frag_size, gfp);
if (!buf)
return -ENOMEM;
if (bm_pool->construct)
if (bm_pool->construct(bm_pool, buf)) {
hwbm_buf_free(bm_pool, buf);
return -ENOMEM;
}
return 0;
}
int hwbm_pool_add(struct hwbm_pool *bm_pool, unsigned int buf_num, gfp_t gfp)
{
int err, i;
unsigned long flags;
spin_lock_irqsave(&bm_pool->lock, flags);
if (bm_pool->buf_num == bm_pool->size) {
pr_warn("pool already filled\n");
return bm_pool->buf_num;
}
if (buf_num + bm_pool->buf_num > bm_pool->size) {
pr_warn("cannot allocate %d buffers for pool\n",
buf_num);
return 0;
}
if ((buf_num + bm_pool->buf_num) < bm_pool->buf_num) {
pr_warn("Adding %d buffers to the %d current buffers will overflow\n",
buf_num, bm_pool->buf_num);
return 0;
}
for (i = 0; i < buf_num; i++) {
err = hwbm_pool_refill(bm_pool, gfp);
if (err < 0)
break;
}
bm_pool->buf_num += i;
pr_debug("hwpm pool: %d of %d buffers added\n", i, buf_num);
spin_unlock_irqrestore(&bm_pool->lock, flags);
return i;
}
