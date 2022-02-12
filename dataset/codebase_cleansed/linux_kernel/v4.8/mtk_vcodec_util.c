void __iomem *mtk_vcodec_get_reg_addr(struct mtk_vcodec_ctx *data,
unsigned int reg_idx)
{
struct mtk_vcodec_ctx *ctx = (struct mtk_vcodec_ctx *)data;
if (!data || reg_idx >= NUM_MAX_VCODEC_REG_BASE) {
mtk_v4l2_err("Invalid arguments, reg_idx=%d", reg_idx);
return NULL;
}
return ctx->dev->reg_base[reg_idx];
}
int mtk_vcodec_mem_alloc(struct mtk_vcodec_ctx *data,
struct mtk_vcodec_mem *mem)
{
unsigned long size = mem->size;
struct mtk_vcodec_ctx *ctx = (struct mtk_vcodec_ctx *)data;
struct device *dev = &ctx->dev->plat_dev->dev;
mem->va = dma_alloc_coherent(dev, size, &mem->dma_addr, GFP_KERNEL);
if (!mem->va) {
mtk_v4l2_err("%s dma_alloc size=%ld failed!", dev_name(dev),
size);
return -ENOMEM;
}
memset(mem->va, 0, size);
mtk_v4l2_debug(3, "[%d] - va = %p", ctx->id, mem->va);
mtk_v4l2_debug(3, "[%d] - dma = 0x%lx", ctx->id,
(unsigned long)mem->dma_addr);
mtk_v4l2_debug(3, "[%d] size = 0x%lx", ctx->id, size);
return 0;
}
void mtk_vcodec_mem_free(struct mtk_vcodec_ctx *data,
struct mtk_vcodec_mem *mem)
{
unsigned long size = mem->size;
struct mtk_vcodec_ctx *ctx = (struct mtk_vcodec_ctx *)data;
struct device *dev = &ctx->dev->plat_dev->dev;
if (!mem->va) {
mtk_v4l2_err("%s dma_free size=%ld failed!", dev_name(dev),
size);
return;
}
dma_free_coherent(dev, size, mem->va, mem->dma_addr);
mem->va = NULL;
mem->dma_addr = 0;
mem->size = 0;
mtk_v4l2_debug(3, "[%d] - va = %p", ctx->id, mem->va);
mtk_v4l2_debug(3, "[%d] - dma = 0x%lx", ctx->id,
(unsigned long)mem->dma_addr);
mtk_v4l2_debug(3, "[%d] size = 0x%lx", ctx->id, size);
}
