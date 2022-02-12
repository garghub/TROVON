static void
nouveau_sgdma_destroy(struct ttm_tt *ttm)
{
struct nouveau_sgdma_be *nvbe = (struct nouveau_sgdma_be *)ttm;
if (ttm) {
ttm_dma_tt_fini(&nvbe->ttm);
kfree(nvbe);
}
}
static int
nv04_sgdma_bind(struct ttm_tt *ttm, struct ttm_mem_reg *mem)
{
struct nouveau_sgdma_be *nvbe = (struct nouveau_sgdma_be *)ttm;
struct nouveau_mem *node = mem->mm_node;
u64 size = mem->num_pages << 12;
if (ttm->sg) {
node->sg = ttm->sg;
nouveau_vm_map_sg_table(&node->vma[0], 0, size, node);
} else {
node->pages = nvbe->ttm.dma_address;
nouveau_vm_map_sg(&node->vma[0], 0, size, node);
}
nvbe->node = node;
return 0;
}
static int
nv04_sgdma_unbind(struct ttm_tt *ttm)
{
struct nouveau_sgdma_be *nvbe = (struct nouveau_sgdma_be *)ttm;
nouveau_vm_unmap(&nvbe->node->vma[0]);
return 0;
}
static int
nv50_sgdma_bind(struct ttm_tt *ttm, struct ttm_mem_reg *mem)
{
struct nouveau_sgdma_be *nvbe = (struct nouveau_sgdma_be *)ttm;
struct nouveau_mem *node = mem->mm_node;
if (ttm->sg) {
node->sg = ttm->sg;
} else
node->pages = nvbe->ttm.dma_address;
return 0;
}
static int
nv50_sgdma_unbind(struct ttm_tt *ttm)
{
return 0;
}
struct ttm_tt *
nouveau_sgdma_create_ttm(struct ttm_bo_device *bdev,
unsigned long size, uint32_t page_flags,
struct page *dummy_read_page)
{
struct nouveau_drm *drm = nouveau_bdev(bdev);
struct nouveau_sgdma_be *nvbe;
nvbe = kzalloc(sizeof(*nvbe), GFP_KERNEL);
if (!nvbe)
return NULL;
nvbe->dev = drm->dev;
if (nv_device(drm->device)->card_type < NV_50)
nvbe->ttm.ttm.func = &nv04_sgdma_backend;
else
nvbe->ttm.ttm.func = &nv50_sgdma_backend;
if (ttm_dma_tt_init(&nvbe->ttm, bdev, size, page_flags, dummy_read_page)) {
kfree(nvbe);
return NULL;
}
return &nvbe->ttm.ttm;
}
