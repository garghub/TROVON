int s5p_mfc_init_shm(struct s5p_mfc_ctx *ctx)
{
struct s5p_mfc_dev *dev = ctx->dev;
void *shm_alloc_ctx = dev->alloc_ctx[MFC_BANK1_ALLOC_CTX];
ctx->shm_alloc = vb2_dma_contig_memops.alloc(shm_alloc_ctx,
SHARED_BUF_SIZE);
if (IS_ERR(ctx->shm_alloc)) {
mfc_err("failed to allocate shared memory\n");
return PTR_ERR(ctx->shm_alloc);
}
ctx->shm_ofs = s5p_mfc_mem_cookie(shm_alloc_ctx, ctx->shm_alloc)
- dev->bank1;
BUG_ON(ctx->shm_ofs & ((1 << MFC_BANK1_ALIGN_ORDER) - 1));
ctx->shm = vb2_dma_contig_memops.vaddr(ctx->shm_alloc);
if (!ctx->shm) {
vb2_dma_contig_memops.put(ctx->shm_alloc);
ctx->shm_ofs = 0;
ctx->shm_alloc = NULL;
mfc_err("failed to virt addr of shared memory\n");
return -ENOMEM;
}
memset((void *)ctx->shm, 0, SHARED_BUF_SIZE);
wmb();
return 0;
}
