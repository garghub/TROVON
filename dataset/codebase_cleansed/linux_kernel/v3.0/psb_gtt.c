static inline uint32_t psb_gtt_mask_pte(uint32_t pfn, int type)
{
uint32_t mask = PSB_PTE_VALID;
if (type & PSB_MMU_CACHED_MEMORY)
mask |= PSB_PTE_CACHED;
if (type & PSB_MMU_RO_MEMORY)
mask |= PSB_PTE_RO;
if (type & PSB_MMU_WO_MEMORY)
mask |= PSB_PTE_WO;
return (pfn << PAGE_SHIFT) | mask;
}
u32 *psb_gtt_entry(struct drm_device *dev, struct gtt_range *r)
{
struct drm_psb_private *dev_priv = dev->dev_private;
unsigned long offset;
offset = r->resource.start - dev_priv->gtt_mem->start;
return dev_priv->gtt_map + (offset >> PAGE_SHIFT);
}
static int psb_gtt_insert(struct drm_device *dev, struct gtt_range *r)
{
struct drm_psb_private *dev_priv = dev->dev_private;
u32 *gtt_slot, pte;
int numpages = (r->resource.end + 1 - r->resource.start) >> PAGE_SHIFT;
struct page **pages;
int i;
if (r->pages == NULL) {
WARN_ON(1);
return -EINVAL;
}
WARN_ON(r->stolen);
gtt_slot = psb_gtt_entry(dev, r);
pages = r->pages;
wbinvd();
for (i = 0; i < numpages; i++) {
pte = psb_gtt_mask_pte(page_to_pfn(*pages++), 0);
iowrite32(pte, gtt_slot++);
}
ioread32(gtt_slot - 1);
return 0;
}
static void psb_gtt_remove(struct drm_device *dev, struct gtt_range *r)
{
struct drm_psb_private *dev_priv = dev->dev_private;
u32 *gtt_slot, pte;
int numpages = (r->resource.end + 1 - r->resource.start) >> PAGE_SHIFT;
int i;
WARN_ON(r->stolen);
gtt_slot = psb_gtt_entry(dev, r);
pte = psb_gtt_mask_pte(page_to_pfn(dev_priv->scratch_page), 0);;
for (i = 0; i < numpages; i++)
iowrite32(pte, gtt_slot++);
ioread32(gtt_slot - 1);
}
static int psb_gtt_attach_pages(struct gtt_range *gt)
{
struct inode *inode;
struct address_space *mapping;
int i;
struct page *p;
int pages = (gt->resource.end + 1 - gt->resource.start) >> PAGE_SHIFT;
WARN_ON(gt->pages);
inode = gt->gem.filp->f_path.dentry->d_inode;
mapping = inode->i_mapping;
gt->pages = kmalloc(pages * sizeof(struct page *), GFP_KERNEL);
if (gt->pages == NULL)
return -ENOMEM;
for (i = 0; i < pages; i++) {
p = read_cache_page_gfp(mapping, i,
__GFP_COLD | GFP_KERNEL);
if (IS_ERR(p))
goto err;
gt->pages[i] = p;
}
return 0;
err:
while (i--)
page_cache_release(gt->pages[i]);
kfree(gt->pages);
gt->pages = NULL;
return PTR_ERR(p);
}
static void psb_gtt_detach_pages(struct gtt_range *gt)
{
int i;
int pages = (gt->resource.end + 1 - gt->resource.start) >> PAGE_SHIFT;
for (i = 0; i < pages; i++) {
set_page_dirty(gt->pages[i]);
page_cache_release(gt->pages[i]);
}
kfree(gt->pages);
gt->pages = NULL;
}
int psb_gtt_pin(struct gtt_range *gt)
{
int ret;
struct drm_device *dev = gt->gem.dev;
struct drm_psb_private *dev_priv = dev->dev_private;
mutex_lock(&dev_priv->gtt_mutex);
if (gt->in_gart == 0 && gt->stolen == 0) {
ret = psb_gtt_attach_pages(gt);
if (ret < 0)
goto out;
ret = psb_gtt_insert(dev, gt);
if (ret < 0) {
psb_gtt_detach_pages(gt);
goto out;
}
}
gt->in_gart++;
out:
mutex_unlock(&dev_priv->gtt_mutex);
return ret;
}
void psb_gtt_unpin(struct gtt_range *gt)
{
struct drm_device *dev = gt->gem.dev;
struct drm_psb_private *dev_priv = dev->dev_private;
mutex_lock(&dev_priv->gtt_mutex);
WARN_ON(!gt->in_gart);
gt->in_gart--;
if (gt->in_gart == 0 && gt->stolen == 0) {
psb_gtt_remove(dev, gt);
psb_gtt_detach_pages(gt);
}
mutex_unlock(&dev_priv->gtt_mutex);
}
struct gtt_range *psb_gtt_alloc_range(struct drm_device *dev, int len,
const char *name, int backed)
{
struct drm_psb_private *dev_priv = dev->dev_private;
struct gtt_range *gt;
struct resource *r = dev_priv->gtt_mem;
int ret;
unsigned long start, end;
if (backed) {
start = r->start;
end = r->start + dev_priv->pg->stolen_size - 1;
} else {
start = r->start + dev_priv->pg->stolen_size;
end = r->end;
}
gt = kzalloc(sizeof(struct gtt_range), GFP_KERNEL);
if (gt == NULL)
return NULL;
gt->resource.name = name;
gt->stolen = backed;
gt->in_gart = backed;
gt->gem.dev = dev;
kref_init(&gt->kref);
ret = allocate_resource(dev_priv->gtt_mem, &gt->resource,
len, start, end, PAGE_SIZE, NULL, NULL);
if (ret == 0) {
gt->offset = gt->resource.start - r->start;
return gt;
}
kfree(gt);
return NULL;
}
static void psb_gtt_destroy(struct kref *kref)
{
struct gtt_range *gt = container_of(kref, struct gtt_range, kref);
if (gt->mmapping) {
psb_gtt_unpin(gt);
gt->mmapping = 0;
}
WARN_ON(gt->in_gart && !gt->stolen);
release_resource(&gt->resource);
kfree(gt);
}
void psb_gtt_kref_put(struct gtt_range *gt)
{
kref_put(&gt->kref, psb_gtt_destroy);
}
void psb_gtt_free_range(struct drm_device *dev, struct gtt_range *gt)
{
psb_gtt_kref_put(gt);
}
struct psb_gtt *psb_gtt_alloc(struct drm_device *dev)
{
struct psb_gtt *tmp = kzalloc(sizeof(*tmp), GFP_KERNEL);
if (!tmp)
return NULL;
init_rwsem(&tmp->sem);
tmp->dev = dev;
return tmp;
}
void psb_gtt_takedown(struct drm_device *dev)
{
struct drm_psb_private *dev_priv = dev->dev_private;
if (dev_priv->gtt_map) {
iounmap(dev_priv->gtt_map);
dev_priv->gtt_map = NULL;
}
if (dev_priv->gtt_initialized) {
pci_write_config_word(dev->pdev, PSB_GMCH_CTRL,
dev_priv->gmch_ctrl);
PSB_WVDC32(dev_priv->pge_ctl, PSB_PGETBL_CTL);
(void) PSB_RVDC32(PSB_PGETBL_CTL);
}
kfree(dev_priv->pg);
dev_priv->pg = NULL;
}
int psb_gtt_init(struct drm_device *dev, int resume)
{
struct drm_psb_private *dev_priv = dev->dev_private;
unsigned gtt_pages;
unsigned long stolen_size, vram_stolen_size;
unsigned i, num_pages;
unsigned pfn_base;
uint32_t vram_pages;
uint32_t tt_pages;
uint32_t *ttm_gtt_map;
uint32_t dvmt_mode = 0;
struct psb_gtt *pg;
int ret = 0;
uint32_t pte;
mutex_init(&dev_priv->gtt_mutex);
dev_priv->pg = pg = psb_gtt_alloc(dev);
if (pg == NULL)
return -ENOMEM;
pci_read_config_word(dev->pdev, PSB_GMCH_CTRL, &dev_priv->gmch_ctrl);
pci_write_config_word(dev->pdev, PSB_GMCH_CTRL,
dev_priv->gmch_ctrl | _PSB_GMCH_ENABLED);
dev_priv->pge_ctl = PSB_RVDC32(PSB_PGETBL_CTL);
PSB_WVDC32(dev_priv->pge_ctl | _PSB_PGETBL_ENABLED, PSB_PGETBL_CTL);
(void) PSB_RVDC32(PSB_PGETBL_CTL);
dev_priv->gtt_mem = &dev->pdev->resource[PSB_GATT_RESOURCE];
dev_priv->gtt_initialized = 1;
pg->gtt_phys_start = dev_priv->pge_ctl & PAGE_MASK;
pg->gatt_start = pci_resource_start(dev->pdev, PSB_GATT_RESOURCE);
pg->mmu_gatt_start = 0xE0000000;
pg->gtt_start = pci_resource_start(dev->pdev, PSB_GTT_RESOURCE);
gtt_pages =
pci_resource_len(dev->pdev, PSB_GTT_RESOURCE) >> PAGE_SHIFT;
pg->gatt_pages = pci_resource_len(dev->pdev, PSB_GATT_RESOURCE)
>> PAGE_SHIFT;
pci_read_config_dword(dev->pdev, PSB_BSM, &dev_priv->stolen_base);
vram_stolen_size = pg->gtt_phys_start - dev_priv->stolen_base - PAGE_SIZE;
stolen_size = vram_stolen_size;
printk(KERN_INFO"GMMADR(region 0) start: 0x%08x (%dM).\n",
pg->gatt_start, pg->gatt_pages/256);
printk(KERN_INFO"GTTADR(region 3) start: 0x%08x (can map %dM RAM), and actual RAM base 0x%08x.\n",
pg->gtt_start, gtt_pages * 4, pg->gtt_phys_start);
printk(KERN_INFO "Stolen memory information\n");
printk(KERN_INFO " base in RAM: 0x%x\n", dev_priv->stolen_base);
printk(KERN_INFO " size: %luK, calculated by (GTT RAM base) - (Stolen base), seems wrong\n",
vram_stolen_size/1024);
dvmt_mode = (dev_priv->gmch_ctrl >> 4) & 0x7;
printk(KERN_INFO " the correct size should be: %dM(dvmt mode=%d)\n",
(dvmt_mode == 1) ? 1 : (2 << (dvmt_mode - 1)), dvmt_mode);
if (resume && (gtt_pages != pg->gtt_pages) &&
(stolen_size != pg->stolen_size)) {
DRM_ERROR("GTT resume error.\n");
ret = -EINVAL;
goto out_err;
}
pg->gtt_pages = gtt_pages;
pg->stolen_size = stolen_size;
dev_priv->vram_stolen_size = vram_stolen_size;
dev_priv->gtt_map =
ioremap_nocache(pg->gtt_phys_start, gtt_pages << PAGE_SHIFT);
if (!dev_priv->gtt_map) {
DRM_ERROR("Failure to map gtt.\n");
ret = -ENOMEM;
goto out_err;
}
dev_priv->vram_addr = ioremap_wc(dev_priv->stolen_base, stolen_size);
if (!dev_priv->vram_addr) {
DRM_ERROR("Failure to map stolen base.\n");
ret = -ENOMEM;
goto out_err;
}
DRM_DEBUG("%s: vram kernel virtual address %p\n", dev_priv->vram_addr);
tt_pages = (pg->gatt_pages < PSB_TT_PRIV0_PLIMIT) ?
(pg->gatt_pages) : PSB_TT_PRIV0_PLIMIT;
ttm_gtt_map = dev_priv->gtt_map + tt_pages / 2;
pfn_base = dev_priv->stolen_base >> PAGE_SHIFT;
vram_pages = num_pages = vram_stolen_size >> PAGE_SHIFT;
printk(KERN_INFO"Set up %d stolen pages starting at 0x%08x, GTT offset %dK\n",
num_pages, pfn_base, 0);
for (i = 0; i < num_pages; ++i) {
pte = psb_gtt_mask_pte(pfn_base + i, 0);
iowrite32(pte, dev_priv->gtt_map + i);
}
pfn_base = page_to_pfn(dev_priv->scratch_page);
pte = psb_gtt_mask_pte(pfn_base, 0);
for (; i < tt_pages / 2 - 1; ++i)
iowrite32(pte, dev_priv->gtt_map + i);
pfn_base = page_to_pfn(dev_priv->scratch_page);
pte = psb_gtt_mask_pte(pfn_base, 0);
PSB_DEBUG_INIT("Initializing the rest of a total "
"of %d gtt pages.\n", pg->gatt_pages);
for (; i < pg->gatt_pages - tt_pages / 2; ++i)
iowrite32(pte, ttm_gtt_map + i);
(void) ioread32(dev_priv->gtt_map + i - 1);
return 0;
out_err:
psb_gtt_takedown(dev);
return ret;
}
