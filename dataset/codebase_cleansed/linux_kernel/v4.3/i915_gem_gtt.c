static int sanitize_enable_ppgtt(struct drm_device *dev, int enable_ppgtt)
{
bool has_aliasing_ppgtt;
bool has_full_ppgtt;
has_aliasing_ppgtt = INTEL_INFO(dev)->gen >= 6;
has_full_ppgtt = INTEL_INFO(dev)->gen >= 7;
if (intel_vgpu_active(dev))
has_full_ppgtt = false;
if (INTEL_INFO(dev)->gen < 9 &&
(enable_ppgtt == 0 || !has_aliasing_ppgtt))
return 0;
if (enable_ppgtt == 1)
return 1;
if (enable_ppgtt == 2 && has_full_ppgtt)
return 2;
#ifdef CONFIG_INTEL_IOMMU
if (INTEL_INFO(dev)->gen == 6 && intel_iommu_gfx_mapped) {
DRM_INFO("Disabling PPGTT because VT-d is on\n");
return 0;
}
#endif
if (IS_VALLEYVIEW(dev) && !IS_CHERRYVIEW(dev) &&
dev->pdev->revision < 0xb) {
DRM_DEBUG_DRIVER("disabling PPGTT on pre-B3 step VLV\n");
return 0;
}
if (INTEL_INFO(dev)->gen >= 8 && i915.enable_execlists)
return 2;
else
return has_aliasing_ppgtt ? 1 : 0;
}
static int ppgtt_bind_vma(struct i915_vma *vma,
enum i915_cache_level cache_level,
u32 unused)
{
u32 pte_flags = 0;
if (vma->obj->gt_ro)
pte_flags |= PTE_READ_ONLY;
vma->vm->insert_entries(vma->vm, vma->obj->pages, vma->node.start,
cache_level, pte_flags);
return 0;
}
static void ppgtt_unbind_vma(struct i915_vma *vma)
{
vma->vm->clear_range(vma->vm,
vma->node.start,
vma->obj->base.size,
true);
}
static gen8_pte_t gen8_pte_encode(dma_addr_t addr,
enum i915_cache_level level,
bool valid)
{
gen8_pte_t pte = valid ? _PAGE_PRESENT | _PAGE_RW : 0;
pte |= addr;
switch (level) {
case I915_CACHE_NONE:
pte |= PPAT_UNCACHED_INDEX;
break;
case I915_CACHE_WT:
pte |= PPAT_DISPLAY_ELLC_INDEX;
break;
default:
pte |= PPAT_CACHED_INDEX;
break;
}
return pte;
}
static gen8_pde_t gen8_pde_encode(const dma_addr_t addr,
const enum i915_cache_level level)
{
gen8_pde_t pde = _PAGE_PRESENT | _PAGE_RW;
pde |= addr;
if (level != I915_CACHE_NONE)
pde |= PPAT_CACHED_PDE_INDEX;
else
pde |= PPAT_UNCACHED_INDEX;
return pde;
}
static gen6_pte_t snb_pte_encode(dma_addr_t addr,
enum i915_cache_level level,
bool valid, u32 unused)
{
gen6_pte_t pte = valid ? GEN6_PTE_VALID : 0;
pte |= GEN6_PTE_ADDR_ENCODE(addr);
switch (level) {
case I915_CACHE_L3_LLC:
case I915_CACHE_LLC:
pte |= GEN6_PTE_CACHE_LLC;
break;
case I915_CACHE_NONE:
pte |= GEN6_PTE_UNCACHED;
break;
default:
MISSING_CASE(level);
}
return pte;
}
static gen6_pte_t ivb_pte_encode(dma_addr_t addr,
enum i915_cache_level level,
bool valid, u32 unused)
{
gen6_pte_t pte = valid ? GEN6_PTE_VALID : 0;
pte |= GEN6_PTE_ADDR_ENCODE(addr);
switch (level) {
case I915_CACHE_L3_LLC:
pte |= GEN7_PTE_CACHE_L3_LLC;
break;
case I915_CACHE_LLC:
pte |= GEN6_PTE_CACHE_LLC;
break;
case I915_CACHE_NONE:
pte |= GEN6_PTE_UNCACHED;
break;
default:
MISSING_CASE(level);
}
return pte;
}
static gen6_pte_t byt_pte_encode(dma_addr_t addr,
enum i915_cache_level level,
bool valid, u32 flags)
{
gen6_pte_t pte = valid ? GEN6_PTE_VALID : 0;
pte |= GEN6_PTE_ADDR_ENCODE(addr);
if (!(flags & PTE_READ_ONLY))
pte |= BYT_PTE_WRITEABLE;
if (level != I915_CACHE_NONE)
pte |= BYT_PTE_SNOOPED_BY_CPU_CACHES;
return pte;
}
static gen6_pte_t hsw_pte_encode(dma_addr_t addr,
enum i915_cache_level level,
bool valid, u32 unused)
{
gen6_pte_t pte = valid ? GEN6_PTE_VALID : 0;
pte |= HSW_PTE_ADDR_ENCODE(addr);
if (level != I915_CACHE_NONE)
pte |= HSW_WB_LLC_AGE3;
return pte;
}
static gen6_pte_t iris_pte_encode(dma_addr_t addr,
enum i915_cache_level level,
bool valid, u32 unused)
{
gen6_pte_t pte = valid ? GEN6_PTE_VALID : 0;
pte |= HSW_PTE_ADDR_ENCODE(addr);
switch (level) {
case I915_CACHE_NONE:
break;
case I915_CACHE_WT:
pte |= HSW_WT_ELLC_LLC_AGE3;
break;
default:
pte |= HSW_WB_ELLC_LLC_AGE3;
break;
}
return pte;
}
static int __setup_page_dma(struct drm_device *dev,
struct i915_page_dma *p, gfp_t flags)
{
struct device *device = &dev->pdev->dev;
p->page = alloc_page(flags);
if (!p->page)
return -ENOMEM;
p->daddr = dma_map_page(device,
p->page, 0, 4096, PCI_DMA_BIDIRECTIONAL);
if (dma_mapping_error(device, p->daddr)) {
__free_page(p->page);
return -EINVAL;
}
return 0;
}
static int setup_page_dma(struct drm_device *dev, struct i915_page_dma *p)
{
return __setup_page_dma(dev, p, GFP_KERNEL);
}
static void cleanup_page_dma(struct drm_device *dev, struct i915_page_dma *p)
{
if (WARN_ON(!p->page))
return;
dma_unmap_page(&dev->pdev->dev, p->daddr, 4096, PCI_DMA_BIDIRECTIONAL);
__free_page(p->page);
memset(p, 0, sizeof(*p));
}
static void *kmap_page_dma(struct i915_page_dma *p)
{
return kmap_atomic(p->page);
}
static void kunmap_page_dma(struct drm_device *dev, void *vaddr)
{
if (IS_CHERRYVIEW(dev) || IS_BROXTON(dev))
drm_clflush_virt_range(vaddr, PAGE_SIZE);
kunmap_atomic(vaddr);
}
static void fill_page_dma(struct drm_device *dev, struct i915_page_dma *p,
const uint64_t val)
{
int i;
uint64_t * const vaddr = kmap_page_dma(p);
for (i = 0; i < 512; i++)
vaddr[i] = val;
kunmap_page_dma(dev, vaddr);
}
static void fill_page_dma_32(struct drm_device *dev, struct i915_page_dma *p,
const uint32_t val32)
{
uint64_t v = val32;
v = v << 32 | val32;
fill_page_dma(dev, p, v);
}
static struct i915_page_scratch *alloc_scratch_page(struct drm_device *dev)
{
struct i915_page_scratch *sp;
int ret;
sp = kzalloc(sizeof(*sp), GFP_KERNEL);
if (sp == NULL)
return ERR_PTR(-ENOMEM);
ret = __setup_page_dma(dev, px_base(sp), GFP_DMA32 | __GFP_ZERO);
if (ret) {
kfree(sp);
return ERR_PTR(ret);
}
set_pages_uc(px_page(sp), 1);
return sp;
}
static void free_scratch_page(struct drm_device *dev,
struct i915_page_scratch *sp)
{
set_pages_wb(px_page(sp), 1);
cleanup_px(dev, sp);
kfree(sp);
}
static struct i915_page_table *alloc_pt(struct drm_device *dev)
{
struct i915_page_table *pt;
const size_t count = INTEL_INFO(dev)->gen >= 8 ?
GEN8_PTES : GEN6_PTES;
int ret = -ENOMEM;
pt = kzalloc(sizeof(*pt), GFP_KERNEL);
if (!pt)
return ERR_PTR(-ENOMEM);
pt->used_ptes = kcalloc(BITS_TO_LONGS(count), sizeof(*pt->used_ptes),
GFP_KERNEL);
if (!pt->used_ptes)
goto fail_bitmap;
ret = setup_px(dev, pt);
if (ret)
goto fail_page_m;
return pt;
fail_page_m:
kfree(pt->used_ptes);
fail_bitmap:
kfree(pt);
return ERR_PTR(ret);
}
static void free_pt(struct drm_device *dev, struct i915_page_table *pt)
{
cleanup_px(dev, pt);
kfree(pt->used_ptes);
kfree(pt);
}
static void gen8_initialize_pt(struct i915_address_space *vm,
struct i915_page_table *pt)
{
gen8_pte_t scratch_pte;
scratch_pte = gen8_pte_encode(px_dma(vm->scratch_page),
I915_CACHE_LLC, true);
fill_px(vm->dev, pt, scratch_pte);
}
static void gen6_initialize_pt(struct i915_address_space *vm,
struct i915_page_table *pt)
{
gen6_pte_t scratch_pte;
WARN_ON(px_dma(vm->scratch_page) == 0);
scratch_pte = vm->pte_encode(px_dma(vm->scratch_page),
I915_CACHE_LLC, true, 0);
fill32_px(vm->dev, pt, scratch_pte);
}
static struct i915_page_directory *alloc_pd(struct drm_device *dev)
{
struct i915_page_directory *pd;
int ret = -ENOMEM;
pd = kzalloc(sizeof(*pd), GFP_KERNEL);
if (!pd)
return ERR_PTR(-ENOMEM);
pd->used_pdes = kcalloc(BITS_TO_LONGS(I915_PDES),
sizeof(*pd->used_pdes), GFP_KERNEL);
if (!pd->used_pdes)
goto fail_bitmap;
ret = setup_px(dev, pd);
if (ret)
goto fail_page_m;
return pd;
fail_page_m:
kfree(pd->used_pdes);
fail_bitmap:
kfree(pd);
return ERR_PTR(ret);
}
static void free_pd(struct drm_device *dev, struct i915_page_directory *pd)
{
if (px_page(pd)) {
cleanup_px(dev, pd);
kfree(pd->used_pdes);
kfree(pd);
}
}
static void gen8_initialize_pd(struct i915_address_space *vm,
struct i915_page_directory *pd)
{
gen8_pde_t scratch_pde;
scratch_pde = gen8_pde_encode(px_dma(vm->scratch_pt), I915_CACHE_LLC);
fill_px(vm->dev, pd, scratch_pde);
}
static int gen8_write_pdp(struct drm_i915_gem_request *req,
unsigned entry,
dma_addr_t addr)
{
struct intel_engine_cs *ring = req->ring;
int ret;
BUG_ON(entry >= 4);
ret = intel_ring_begin(req, 6);
if (ret)
return ret;
intel_ring_emit(ring, MI_LOAD_REGISTER_IMM(1));
intel_ring_emit(ring, GEN8_RING_PDP_UDW(ring, entry));
intel_ring_emit(ring, upper_32_bits(addr));
intel_ring_emit(ring, MI_LOAD_REGISTER_IMM(1));
intel_ring_emit(ring, GEN8_RING_PDP_LDW(ring, entry));
intel_ring_emit(ring, lower_32_bits(addr));
intel_ring_advance(ring);
return 0;
}
static int gen8_mm_switch(struct i915_hw_ppgtt *ppgtt,
struct drm_i915_gem_request *req)
{
int i, ret;
for (i = GEN8_LEGACY_PDPES - 1; i >= 0; i--) {
const dma_addr_t pd_daddr = i915_page_dir_dma_addr(ppgtt, i);
ret = gen8_write_pdp(req, i, pd_daddr);
if (ret)
return ret;
}
return 0;
}
static void gen8_ppgtt_clear_range(struct i915_address_space *vm,
uint64_t start,
uint64_t length,
bool use_scratch)
{
struct i915_hw_ppgtt *ppgtt =
container_of(vm, struct i915_hw_ppgtt, base);
gen8_pte_t *pt_vaddr, scratch_pte;
unsigned pdpe = start >> GEN8_PDPE_SHIFT & GEN8_PDPE_MASK;
unsigned pde = start >> GEN8_PDE_SHIFT & GEN8_PDE_MASK;
unsigned pte = start >> GEN8_PTE_SHIFT & GEN8_PTE_MASK;
unsigned num_entries = length >> PAGE_SHIFT;
unsigned last_pte, i;
scratch_pte = gen8_pte_encode(px_dma(ppgtt->base.scratch_page),
I915_CACHE_LLC, use_scratch);
while (num_entries) {
struct i915_page_directory *pd;
struct i915_page_table *pt;
if (WARN_ON(!ppgtt->pdp.page_directory[pdpe]))
break;
pd = ppgtt->pdp.page_directory[pdpe];
if (WARN_ON(!pd->page_table[pde]))
break;
pt = pd->page_table[pde];
if (WARN_ON(!px_page(pt)))
break;
last_pte = pte + num_entries;
if (last_pte > GEN8_PTES)
last_pte = GEN8_PTES;
pt_vaddr = kmap_px(pt);
for (i = pte; i < last_pte; i++) {
pt_vaddr[i] = scratch_pte;
num_entries--;
}
kunmap_px(ppgtt, pt);
pte = 0;
if (++pde == I915_PDES) {
pdpe++;
pde = 0;
}
}
}
static void gen8_ppgtt_insert_entries(struct i915_address_space *vm,
struct sg_table *pages,
uint64_t start,
enum i915_cache_level cache_level, u32 unused)
{
struct i915_hw_ppgtt *ppgtt =
container_of(vm, struct i915_hw_ppgtt, base);
gen8_pte_t *pt_vaddr;
unsigned pdpe = start >> GEN8_PDPE_SHIFT & GEN8_PDPE_MASK;
unsigned pde = start >> GEN8_PDE_SHIFT & GEN8_PDE_MASK;
unsigned pte = start >> GEN8_PTE_SHIFT & GEN8_PTE_MASK;
struct sg_page_iter sg_iter;
pt_vaddr = NULL;
for_each_sg_page(pages->sgl, &sg_iter, pages->nents, 0) {
if (WARN_ON(pdpe >= GEN8_LEGACY_PDPES))
break;
if (pt_vaddr == NULL) {
struct i915_page_directory *pd = ppgtt->pdp.page_directory[pdpe];
struct i915_page_table *pt = pd->page_table[pde];
pt_vaddr = kmap_px(pt);
}
pt_vaddr[pte] =
gen8_pte_encode(sg_page_iter_dma_address(&sg_iter),
cache_level, true);
if (++pte == GEN8_PTES) {
kunmap_px(ppgtt, pt_vaddr);
pt_vaddr = NULL;
if (++pde == I915_PDES) {
pdpe++;
pde = 0;
}
pte = 0;
}
}
if (pt_vaddr)
kunmap_px(ppgtt, pt_vaddr);
}
static void gen8_free_page_tables(struct drm_device *dev,
struct i915_page_directory *pd)
{
int i;
if (!px_page(pd))
return;
for_each_set_bit(i, pd->used_pdes, I915_PDES) {
if (WARN_ON(!pd->page_table[i]))
continue;
free_pt(dev, pd->page_table[i]);
pd->page_table[i] = NULL;
}
}
static int gen8_init_scratch(struct i915_address_space *vm)
{
struct drm_device *dev = vm->dev;
vm->scratch_page = alloc_scratch_page(dev);
if (IS_ERR(vm->scratch_page))
return PTR_ERR(vm->scratch_page);
vm->scratch_pt = alloc_pt(dev);
if (IS_ERR(vm->scratch_pt)) {
free_scratch_page(dev, vm->scratch_page);
return PTR_ERR(vm->scratch_pt);
}
vm->scratch_pd = alloc_pd(dev);
if (IS_ERR(vm->scratch_pd)) {
free_pt(dev, vm->scratch_pt);
free_scratch_page(dev, vm->scratch_page);
return PTR_ERR(vm->scratch_pd);
}
gen8_initialize_pt(vm, vm->scratch_pt);
gen8_initialize_pd(vm, vm->scratch_pd);
return 0;
}
static void gen8_free_scratch(struct i915_address_space *vm)
{
struct drm_device *dev = vm->dev;
free_pd(dev, vm->scratch_pd);
free_pt(dev, vm->scratch_pt);
free_scratch_page(dev, vm->scratch_page);
}
static void gen8_ppgtt_cleanup(struct i915_address_space *vm)
{
struct i915_hw_ppgtt *ppgtt =
container_of(vm, struct i915_hw_ppgtt, base);
int i;
for_each_set_bit(i, ppgtt->pdp.used_pdpes, GEN8_LEGACY_PDPES) {
if (WARN_ON(!ppgtt->pdp.page_directory[i]))
continue;
gen8_free_page_tables(ppgtt->base.dev,
ppgtt->pdp.page_directory[i]);
free_pd(ppgtt->base.dev, ppgtt->pdp.page_directory[i]);
}
gen8_free_scratch(vm);
}
static int gen8_ppgtt_alloc_pagetabs(struct i915_hw_ppgtt *ppgtt,
struct i915_page_directory *pd,
uint64_t start,
uint64_t length,
unsigned long *new_pts)
{
struct drm_device *dev = ppgtt->base.dev;
struct i915_page_table *pt;
uint64_t temp;
uint32_t pde;
gen8_for_each_pde(pt, pd, start, length, temp, pde) {
if (pt) {
WARN_ON(pt == ppgtt->base.scratch_pt);
continue;
}
pt = alloc_pt(dev);
if (IS_ERR(pt))
goto unwind_out;
gen8_initialize_pt(&ppgtt->base, pt);
pd->page_table[pde] = pt;
__set_bit(pde, new_pts);
}
return 0;
unwind_out:
for_each_set_bit(pde, new_pts, I915_PDES)
free_pt(dev, pd->page_table[pde]);
return -ENOMEM;
}
static int gen8_ppgtt_alloc_page_directories(struct i915_hw_ppgtt *ppgtt,
struct i915_page_directory_pointer *pdp,
uint64_t start,
uint64_t length,
unsigned long *new_pds)
{
struct drm_device *dev = ppgtt->base.dev;
struct i915_page_directory *pd;
uint64_t temp;
uint32_t pdpe;
WARN_ON(!bitmap_empty(new_pds, GEN8_LEGACY_PDPES));
gen8_for_each_pdpe(pd, pdp, start, length, temp, pdpe) {
if (pd)
continue;
pd = alloc_pd(dev);
if (IS_ERR(pd))
goto unwind_out;
gen8_initialize_pd(&ppgtt->base, pd);
pdp->page_directory[pdpe] = pd;
__set_bit(pdpe, new_pds);
}
return 0;
unwind_out:
for_each_set_bit(pdpe, new_pds, GEN8_LEGACY_PDPES)
free_pd(dev, pdp->page_directory[pdpe]);
return -ENOMEM;
}
static void
free_gen8_temp_bitmaps(unsigned long *new_pds, unsigned long **new_pts)
{
int i;
for (i = 0; i < GEN8_LEGACY_PDPES; i++)
kfree(new_pts[i]);
kfree(new_pts);
kfree(new_pds);
}
static
int __must_check alloc_gen8_temp_bitmaps(unsigned long **new_pds,
unsigned long ***new_pts)
{
int i;
unsigned long *pds;
unsigned long **pts;
pds = kcalloc(BITS_TO_LONGS(GEN8_LEGACY_PDPES), sizeof(unsigned long), GFP_KERNEL);
if (!pds)
return -ENOMEM;
pts = kcalloc(GEN8_LEGACY_PDPES, sizeof(unsigned long *), GFP_KERNEL);
if (!pts) {
kfree(pds);
return -ENOMEM;
}
for (i = 0; i < GEN8_LEGACY_PDPES; i++) {
pts[i] = kcalloc(BITS_TO_LONGS(I915_PDES),
sizeof(unsigned long), GFP_KERNEL);
if (!pts[i])
goto err_out;
}
*new_pds = pds;
*new_pts = pts;
return 0;
err_out:
free_gen8_temp_bitmaps(pds, pts);
return -ENOMEM;
}
static void mark_tlbs_dirty(struct i915_hw_ppgtt *ppgtt)
{
ppgtt->pd_dirty_rings = INTEL_INFO(ppgtt->base.dev)->ring_mask;
}
static int gen8_alloc_va_range(struct i915_address_space *vm,
uint64_t start,
uint64_t length)
{
struct i915_hw_ppgtt *ppgtt =
container_of(vm, struct i915_hw_ppgtt, base);
unsigned long *new_page_dirs, **new_page_tables;
struct i915_page_directory *pd;
const uint64_t orig_start = start;
const uint64_t orig_length = length;
uint64_t temp;
uint32_t pdpe;
int ret;
if (WARN_ON(start + length < start))
return -ENODEV;
if (WARN_ON(start + length > ppgtt->base.total))
return -ENODEV;
ret = alloc_gen8_temp_bitmaps(&new_page_dirs, &new_page_tables);
if (ret)
return ret;
ret = gen8_ppgtt_alloc_page_directories(ppgtt, &ppgtt->pdp, start, length,
new_page_dirs);
if (ret) {
free_gen8_temp_bitmaps(new_page_dirs, new_page_tables);
return ret;
}
gen8_for_each_pdpe(pd, &ppgtt->pdp, start, length, temp, pdpe) {
ret = gen8_ppgtt_alloc_pagetabs(ppgtt, pd, start, length,
new_page_tables[pdpe]);
if (ret)
goto err_out;
}
start = orig_start;
length = orig_length;
gen8_for_each_pdpe(pd, &ppgtt->pdp, start, length, temp, pdpe) {
gen8_pde_t *const page_directory = kmap_px(pd);
struct i915_page_table *pt;
uint64_t pd_len = gen8_clamp_pd(start, length);
uint64_t pd_start = start;
uint32_t pde;
WARN_ON(!pd);
gen8_for_each_pde(pt, pd, pd_start, pd_len, temp, pde) {
WARN_ON(!pt);
WARN_ON(!pd_len);
WARN_ON(!gen8_pte_count(pd_start, pd_len));
bitmap_set(pt->used_ptes,
gen8_pte_index(pd_start),
gen8_pte_count(pd_start, pd_len));
__set_bit(pde, pd->used_pdes);
page_directory[pde] = gen8_pde_encode(px_dma(pt),
I915_CACHE_LLC);
}
kunmap_px(ppgtt, page_directory);
__set_bit(pdpe, ppgtt->pdp.used_pdpes);
}
free_gen8_temp_bitmaps(new_page_dirs, new_page_tables);
mark_tlbs_dirty(ppgtt);
return 0;
err_out:
while (pdpe--) {
for_each_set_bit(temp, new_page_tables[pdpe], I915_PDES)
free_pt(vm->dev, ppgtt->pdp.page_directory[pdpe]->page_table[temp]);
}
for_each_set_bit(pdpe, new_page_dirs, GEN8_LEGACY_PDPES)
free_pd(vm->dev, ppgtt->pdp.page_directory[pdpe]);
free_gen8_temp_bitmaps(new_page_dirs, new_page_tables);
mark_tlbs_dirty(ppgtt);
return ret;
}
static int gen8_ppgtt_init(struct i915_hw_ppgtt *ppgtt)
{
int ret;
ret = gen8_init_scratch(&ppgtt->base);
if (ret)
return ret;
ppgtt->base.start = 0;
ppgtt->base.total = 1ULL << 32;
if (IS_ENABLED(CONFIG_X86_32))
ppgtt->base.total = to_i915(ppgtt->base.dev)->gtt.base.total;
ppgtt->base.cleanup = gen8_ppgtt_cleanup;
ppgtt->base.allocate_va_range = gen8_alloc_va_range;
ppgtt->base.insert_entries = gen8_ppgtt_insert_entries;
ppgtt->base.clear_range = gen8_ppgtt_clear_range;
ppgtt->base.unbind_vma = ppgtt_unbind_vma;
ppgtt->base.bind_vma = ppgtt_bind_vma;
ppgtt->switch_mm = gen8_mm_switch;
return 0;
}
static void gen6_dump_ppgtt(struct i915_hw_ppgtt *ppgtt, struct seq_file *m)
{
struct i915_address_space *vm = &ppgtt->base;
struct i915_page_table *unused;
gen6_pte_t scratch_pte;
uint32_t pd_entry;
uint32_t pte, pde, temp;
uint32_t start = ppgtt->base.start, length = ppgtt->base.total;
scratch_pte = vm->pte_encode(px_dma(vm->scratch_page),
I915_CACHE_LLC, true, 0);
gen6_for_each_pde(unused, &ppgtt->pd, start, length, temp, pde) {
u32 expected;
gen6_pte_t *pt_vaddr;
const dma_addr_t pt_addr = px_dma(ppgtt->pd.page_table[pde]);
pd_entry = readl(ppgtt->pd_addr + pde);
expected = (GEN6_PDE_ADDR_ENCODE(pt_addr) | GEN6_PDE_VALID);
if (pd_entry != expected)
seq_printf(m, "\tPDE #%d mismatch: Actual PDE: %x Expected PDE: %x\n",
pde,
pd_entry,
expected);
seq_printf(m, "\tPDE: %x\n", pd_entry);
pt_vaddr = kmap_px(ppgtt->pd.page_table[pde]);
for (pte = 0; pte < GEN6_PTES; pte+=4) {
unsigned long va =
(pde * PAGE_SIZE * GEN6_PTES) +
(pte * PAGE_SIZE);
int i;
bool found = false;
for (i = 0; i < 4; i++)
if (pt_vaddr[pte + i] != scratch_pte)
found = true;
if (!found)
continue;
seq_printf(m, "\t\t0x%lx [%03d,%04d]: =", va, pde, pte);
for (i = 0; i < 4; i++) {
if (pt_vaddr[pte + i] != scratch_pte)
seq_printf(m, " %08x", pt_vaddr[pte + i]);
else
seq_puts(m, " SCRATCH ");
}
seq_puts(m, "\n");
}
kunmap_px(ppgtt, pt_vaddr);
}
}
static void gen6_write_pde(struct i915_page_directory *pd,
const int pde, struct i915_page_table *pt)
{
struct i915_hw_ppgtt *ppgtt =
container_of(pd, struct i915_hw_ppgtt, pd);
u32 pd_entry;
pd_entry = GEN6_PDE_ADDR_ENCODE(px_dma(pt));
pd_entry |= GEN6_PDE_VALID;
writel(pd_entry, ppgtt->pd_addr + pde);
}
static void gen6_write_page_range(struct drm_i915_private *dev_priv,
struct i915_page_directory *pd,
uint32_t start, uint32_t length)
{
struct i915_page_table *pt;
uint32_t pde, temp;
gen6_for_each_pde(pt, pd, start, length, temp, pde)
gen6_write_pde(pd, pde, pt);
readl(dev_priv->gtt.gsm);
}
static uint32_t get_pd_offset(struct i915_hw_ppgtt *ppgtt)
{
BUG_ON(ppgtt->pd.base.ggtt_offset & 0x3f);
return (ppgtt->pd.base.ggtt_offset / 64) << 16;
}
static int hsw_mm_switch(struct i915_hw_ppgtt *ppgtt,
struct drm_i915_gem_request *req)
{
struct intel_engine_cs *ring = req->ring;
int ret;
ret = ring->flush(req, I915_GEM_GPU_DOMAINS, I915_GEM_GPU_DOMAINS);
if (ret)
return ret;
ret = intel_ring_begin(req, 6);
if (ret)
return ret;
intel_ring_emit(ring, MI_LOAD_REGISTER_IMM(2));
intel_ring_emit(ring, RING_PP_DIR_DCLV(ring));
intel_ring_emit(ring, PP_DIR_DCLV_2G);
intel_ring_emit(ring, RING_PP_DIR_BASE(ring));
intel_ring_emit(ring, get_pd_offset(ppgtt));
intel_ring_emit(ring, MI_NOOP);
intel_ring_advance(ring);
return 0;
}
static int vgpu_mm_switch(struct i915_hw_ppgtt *ppgtt,
struct drm_i915_gem_request *req)
{
struct intel_engine_cs *ring = req->ring;
struct drm_i915_private *dev_priv = to_i915(ppgtt->base.dev);
I915_WRITE(RING_PP_DIR_DCLV(ring), PP_DIR_DCLV_2G);
I915_WRITE(RING_PP_DIR_BASE(ring), get_pd_offset(ppgtt));
return 0;
}
static int gen7_mm_switch(struct i915_hw_ppgtt *ppgtt,
struct drm_i915_gem_request *req)
{
struct intel_engine_cs *ring = req->ring;
int ret;
ret = ring->flush(req, I915_GEM_GPU_DOMAINS, I915_GEM_GPU_DOMAINS);
if (ret)
return ret;
ret = intel_ring_begin(req, 6);
if (ret)
return ret;
intel_ring_emit(ring, MI_LOAD_REGISTER_IMM(2));
intel_ring_emit(ring, RING_PP_DIR_DCLV(ring));
intel_ring_emit(ring, PP_DIR_DCLV_2G);
intel_ring_emit(ring, RING_PP_DIR_BASE(ring));
intel_ring_emit(ring, get_pd_offset(ppgtt));
intel_ring_emit(ring, MI_NOOP);
intel_ring_advance(ring);
if (ring->id != RCS) {
ret = ring->flush(req, I915_GEM_GPU_DOMAINS, I915_GEM_GPU_DOMAINS);
if (ret)
return ret;
}
return 0;
}
static int gen6_mm_switch(struct i915_hw_ppgtt *ppgtt,
struct drm_i915_gem_request *req)
{
struct intel_engine_cs *ring = req->ring;
struct drm_device *dev = ppgtt->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
I915_WRITE(RING_PP_DIR_DCLV(ring), PP_DIR_DCLV_2G);
I915_WRITE(RING_PP_DIR_BASE(ring), get_pd_offset(ppgtt));
POSTING_READ(RING_PP_DIR_DCLV(ring));
return 0;
}
static void gen8_ppgtt_enable(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_engine_cs *ring;
int j;
for_each_ring(ring, dev_priv, j) {
I915_WRITE(RING_MODE_GEN7(ring),
_MASKED_BIT_ENABLE(GFX_PPGTT_ENABLE));
}
}
static void gen7_ppgtt_enable(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_engine_cs *ring;
uint32_t ecochk, ecobits;
int i;
ecobits = I915_READ(GAC_ECO_BITS);
I915_WRITE(GAC_ECO_BITS, ecobits | ECOBITS_PPGTT_CACHE64B);
ecochk = I915_READ(GAM_ECOCHK);
if (IS_HASWELL(dev)) {
ecochk |= ECOCHK_PPGTT_WB_HSW;
} else {
ecochk |= ECOCHK_PPGTT_LLC_IVB;
ecochk &= ~ECOCHK_PPGTT_GFDT_IVB;
}
I915_WRITE(GAM_ECOCHK, ecochk);
for_each_ring(ring, dev_priv, i) {
I915_WRITE(RING_MODE_GEN7(ring),
_MASKED_BIT_ENABLE(GFX_PPGTT_ENABLE));
}
}
static void gen6_ppgtt_enable(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
uint32_t ecochk, gab_ctl, ecobits;
ecobits = I915_READ(GAC_ECO_BITS);
I915_WRITE(GAC_ECO_BITS, ecobits | ECOBITS_SNB_BIT |
ECOBITS_PPGTT_CACHE64B);
gab_ctl = I915_READ(GAB_CTL);
I915_WRITE(GAB_CTL, gab_ctl | GAB_CTL_CONT_AFTER_PAGEFAULT);
ecochk = I915_READ(GAM_ECOCHK);
I915_WRITE(GAM_ECOCHK, ecochk | ECOCHK_SNB_BIT | ECOCHK_PPGTT_CACHE64B);
I915_WRITE(GFX_MODE, _MASKED_BIT_ENABLE(GFX_PPGTT_ENABLE));
}
static void gen6_ppgtt_clear_range(struct i915_address_space *vm,
uint64_t start,
uint64_t length,
bool use_scratch)
{
struct i915_hw_ppgtt *ppgtt =
container_of(vm, struct i915_hw_ppgtt, base);
gen6_pte_t *pt_vaddr, scratch_pte;
unsigned first_entry = start >> PAGE_SHIFT;
unsigned num_entries = length >> PAGE_SHIFT;
unsigned act_pt = first_entry / GEN6_PTES;
unsigned first_pte = first_entry % GEN6_PTES;
unsigned last_pte, i;
scratch_pte = vm->pte_encode(px_dma(vm->scratch_page),
I915_CACHE_LLC, true, 0);
while (num_entries) {
last_pte = first_pte + num_entries;
if (last_pte > GEN6_PTES)
last_pte = GEN6_PTES;
pt_vaddr = kmap_px(ppgtt->pd.page_table[act_pt]);
for (i = first_pte; i < last_pte; i++)
pt_vaddr[i] = scratch_pte;
kunmap_px(ppgtt, pt_vaddr);
num_entries -= last_pte - first_pte;
first_pte = 0;
act_pt++;
}
}
static void gen6_ppgtt_insert_entries(struct i915_address_space *vm,
struct sg_table *pages,
uint64_t start,
enum i915_cache_level cache_level, u32 flags)
{
struct i915_hw_ppgtt *ppgtt =
container_of(vm, struct i915_hw_ppgtt, base);
gen6_pte_t *pt_vaddr;
unsigned first_entry = start >> PAGE_SHIFT;
unsigned act_pt = first_entry / GEN6_PTES;
unsigned act_pte = first_entry % GEN6_PTES;
struct sg_page_iter sg_iter;
pt_vaddr = NULL;
for_each_sg_page(pages->sgl, &sg_iter, pages->nents, 0) {
if (pt_vaddr == NULL)
pt_vaddr = kmap_px(ppgtt->pd.page_table[act_pt]);
pt_vaddr[act_pte] =
vm->pte_encode(sg_page_iter_dma_address(&sg_iter),
cache_level, true, flags);
if (++act_pte == GEN6_PTES) {
kunmap_px(ppgtt, pt_vaddr);
pt_vaddr = NULL;
act_pt++;
act_pte = 0;
}
}
if (pt_vaddr)
kunmap_px(ppgtt, pt_vaddr);
}
static int gen6_alloc_va_range(struct i915_address_space *vm,
uint64_t start_in, uint64_t length_in)
{
DECLARE_BITMAP(new_page_tables, I915_PDES);
struct drm_device *dev = vm->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct i915_hw_ppgtt *ppgtt =
container_of(vm, struct i915_hw_ppgtt, base);
struct i915_page_table *pt;
uint32_t start, length, start_save, length_save;
uint32_t pde, temp;
int ret;
if (WARN_ON(start_in + length_in > ppgtt->base.total))
return -ENODEV;
start = start_save = start_in;
length = length_save = length_in;
bitmap_zero(new_page_tables, I915_PDES);
gen6_for_each_pde(pt, &ppgtt->pd, start, length, temp, pde) {
if (pt != vm->scratch_pt) {
WARN_ON(bitmap_empty(pt->used_ptes, GEN6_PTES));
continue;
}
WARN_ON(!bitmap_empty(pt->used_ptes, GEN6_PTES));
pt = alloc_pt(dev);
if (IS_ERR(pt)) {
ret = PTR_ERR(pt);
goto unwind_out;
}
gen6_initialize_pt(vm, pt);
ppgtt->pd.page_table[pde] = pt;
__set_bit(pde, new_page_tables);
trace_i915_page_table_entry_alloc(vm, pde, start, GEN6_PDE_SHIFT);
}
start = start_save;
length = length_save;
gen6_for_each_pde(pt, &ppgtt->pd, start, length, temp, pde) {
DECLARE_BITMAP(tmp_bitmap, GEN6_PTES);
bitmap_zero(tmp_bitmap, GEN6_PTES);
bitmap_set(tmp_bitmap, gen6_pte_index(start),
gen6_pte_count(start, length));
if (__test_and_clear_bit(pde, new_page_tables))
gen6_write_pde(&ppgtt->pd, pde, pt);
trace_i915_page_table_entry_map(vm, pde, pt,
gen6_pte_index(start),
gen6_pte_count(start, length),
GEN6_PTES);
bitmap_or(pt->used_ptes, tmp_bitmap, pt->used_ptes,
GEN6_PTES);
}
WARN_ON(!bitmap_empty(new_page_tables, I915_PDES));
readl(dev_priv->gtt.gsm);
mark_tlbs_dirty(ppgtt);
return 0;
unwind_out:
for_each_set_bit(pde, new_page_tables, I915_PDES) {
struct i915_page_table *pt = ppgtt->pd.page_table[pde];
ppgtt->pd.page_table[pde] = vm->scratch_pt;
free_pt(vm->dev, pt);
}
mark_tlbs_dirty(ppgtt);
return ret;
}
static int gen6_init_scratch(struct i915_address_space *vm)
{
struct drm_device *dev = vm->dev;
vm->scratch_page = alloc_scratch_page(dev);
if (IS_ERR(vm->scratch_page))
return PTR_ERR(vm->scratch_page);
vm->scratch_pt = alloc_pt(dev);
if (IS_ERR(vm->scratch_pt)) {
free_scratch_page(dev, vm->scratch_page);
return PTR_ERR(vm->scratch_pt);
}
gen6_initialize_pt(vm, vm->scratch_pt);
return 0;
}
static void gen6_free_scratch(struct i915_address_space *vm)
{
struct drm_device *dev = vm->dev;
free_pt(dev, vm->scratch_pt);
free_scratch_page(dev, vm->scratch_page);
}
static void gen6_ppgtt_cleanup(struct i915_address_space *vm)
{
struct i915_hw_ppgtt *ppgtt =
container_of(vm, struct i915_hw_ppgtt, base);
struct i915_page_table *pt;
uint32_t pde;
drm_mm_remove_node(&ppgtt->node);
gen6_for_all_pdes(pt, ppgtt, pde) {
if (pt != vm->scratch_pt)
free_pt(ppgtt->base.dev, pt);
}
gen6_free_scratch(vm);
}
static int gen6_ppgtt_allocate_page_directories(struct i915_hw_ppgtt *ppgtt)
{
struct i915_address_space *vm = &ppgtt->base;
struct drm_device *dev = ppgtt->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
bool retried = false;
int ret;
BUG_ON(!drm_mm_initialized(&dev_priv->gtt.base.mm));
ret = gen6_init_scratch(vm);
if (ret)
return ret;
alloc:
ret = drm_mm_insert_node_in_range_generic(&dev_priv->gtt.base.mm,
&ppgtt->node, GEN6_PD_SIZE,
GEN6_PD_ALIGN, 0,
0, dev_priv->gtt.base.total,
DRM_MM_TOPDOWN);
if (ret == -ENOSPC && !retried) {
ret = i915_gem_evict_something(dev, &dev_priv->gtt.base,
GEN6_PD_SIZE, GEN6_PD_ALIGN,
I915_CACHE_NONE,
0, dev_priv->gtt.base.total,
0);
if (ret)
goto err_out;
retried = true;
goto alloc;
}
if (ret)
goto err_out;
if (ppgtt->node.start < dev_priv->gtt.mappable_end)
DRM_DEBUG("Forced to use aperture for PDEs\n");
return 0;
err_out:
gen6_free_scratch(vm);
return ret;
}
static int gen6_ppgtt_alloc(struct i915_hw_ppgtt *ppgtt)
{
return gen6_ppgtt_allocate_page_directories(ppgtt);
}
static void gen6_scratch_va_range(struct i915_hw_ppgtt *ppgtt,
uint64_t start, uint64_t length)
{
struct i915_page_table *unused;
uint32_t pde, temp;
gen6_for_each_pde(unused, &ppgtt->pd, start, length, temp, pde)
ppgtt->pd.page_table[pde] = ppgtt->base.scratch_pt;
}
static int gen6_ppgtt_init(struct i915_hw_ppgtt *ppgtt)
{
struct drm_device *dev = ppgtt->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
int ret;
ppgtt->base.pte_encode = dev_priv->gtt.base.pte_encode;
if (IS_GEN6(dev)) {
ppgtt->switch_mm = gen6_mm_switch;
} else if (IS_HASWELL(dev)) {
ppgtt->switch_mm = hsw_mm_switch;
} else if (IS_GEN7(dev)) {
ppgtt->switch_mm = gen7_mm_switch;
} else
BUG();
if (intel_vgpu_active(dev))
ppgtt->switch_mm = vgpu_mm_switch;
ret = gen6_ppgtt_alloc(ppgtt);
if (ret)
return ret;
ppgtt->base.allocate_va_range = gen6_alloc_va_range;
ppgtt->base.clear_range = gen6_ppgtt_clear_range;
ppgtt->base.insert_entries = gen6_ppgtt_insert_entries;
ppgtt->base.unbind_vma = ppgtt_unbind_vma;
ppgtt->base.bind_vma = ppgtt_bind_vma;
ppgtt->base.cleanup = gen6_ppgtt_cleanup;
ppgtt->base.start = 0;
ppgtt->base.total = I915_PDES * GEN6_PTES * PAGE_SIZE;
ppgtt->debug_dump = gen6_dump_ppgtt;
ppgtt->pd.base.ggtt_offset =
ppgtt->node.start / PAGE_SIZE * sizeof(gen6_pte_t);
ppgtt->pd_addr = (gen6_pte_t __iomem *)dev_priv->gtt.gsm +
ppgtt->pd.base.ggtt_offset / sizeof(gen6_pte_t);
gen6_scratch_va_range(ppgtt, 0, ppgtt->base.total);
gen6_write_page_range(dev_priv, &ppgtt->pd, 0, ppgtt->base.total);
DRM_DEBUG_DRIVER("Allocated pde space (%lldM) at GTT entry: %llx\n",
ppgtt->node.size >> 20,
ppgtt->node.start / PAGE_SIZE);
DRM_DEBUG("Adding PPGTT at offset %x\n",
ppgtt->pd.base.ggtt_offset << 10);
return 0;
}
static int __hw_ppgtt_init(struct drm_device *dev, struct i915_hw_ppgtt *ppgtt)
{
ppgtt->base.dev = dev;
if (INTEL_INFO(dev)->gen < 8)
return gen6_ppgtt_init(ppgtt);
else
return gen8_ppgtt_init(ppgtt);
}
int i915_ppgtt_init(struct drm_device *dev, struct i915_hw_ppgtt *ppgtt)
{
struct drm_i915_private *dev_priv = dev->dev_private;
int ret = 0;
ret = __hw_ppgtt_init(dev, ppgtt);
if (ret == 0) {
kref_init(&ppgtt->ref);
drm_mm_init(&ppgtt->base.mm, ppgtt->base.start,
ppgtt->base.total);
i915_init_vm(dev_priv, &ppgtt->base);
}
return ret;
}
int i915_ppgtt_init_hw(struct drm_device *dev)
{
if (i915.enable_execlists)
return 0;
if (!USES_PPGTT(dev))
return 0;
if (IS_GEN6(dev))
gen6_ppgtt_enable(dev);
else if (IS_GEN7(dev))
gen7_ppgtt_enable(dev);
else if (INTEL_INFO(dev)->gen >= 8)
gen8_ppgtt_enable(dev);
else
MISSING_CASE(INTEL_INFO(dev)->gen);
return 0;
}
int i915_ppgtt_init_ring(struct drm_i915_gem_request *req)
{
struct drm_i915_private *dev_priv = req->ring->dev->dev_private;
struct i915_hw_ppgtt *ppgtt = dev_priv->mm.aliasing_ppgtt;
if (i915.enable_execlists)
return 0;
if (!ppgtt)
return 0;
return ppgtt->switch_mm(ppgtt, req);
}
struct i915_hw_ppgtt *
i915_ppgtt_create(struct drm_device *dev, struct drm_i915_file_private *fpriv)
{
struct i915_hw_ppgtt *ppgtt;
int ret;
ppgtt = kzalloc(sizeof(*ppgtt), GFP_KERNEL);
if (!ppgtt)
return ERR_PTR(-ENOMEM);
ret = i915_ppgtt_init(dev, ppgtt);
if (ret) {
kfree(ppgtt);
return ERR_PTR(ret);
}
ppgtt->file_priv = fpriv;
trace_i915_ppgtt_create(&ppgtt->base);
return ppgtt;
}
void i915_ppgtt_release(struct kref *kref)
{
struct i915_hw_ppgtt *ppgtt =
container_of(kref, struct i915_hw_ppgtt, ref);
trace_i915_ppgtt_release(&ppgtt->base);
WARN_ON(!list_empty(&ppgtt->base.active_list));
WARN_ON(!list_empty(&ppgtt->base.inactive_list));
list_del(&ppgtt->base.global_link);
drm_mm_takedown(&ppgtt->base.mm);
ppgtt->base.cleanup(&ppgtt->base);
kfree(ppgtt);
}
static bool needs_idle_maps(struct drm_device *dev)
{
#ifdef CONFIG_INTEL_IOMMU
if (IS_GEN5(dev) && IS_MOBILE(dev) && intel_iommu_gfx_mapped)
return true;
#endif
return false;
}
static bool do_idling(struct drm_i915_private *dev_priv)
{
bool ret = dev_priv->mm.interruptible;
if (unlikely(dev_priv->gtt.do_idle_maps)) {
dev_priv->mm.interruptible = false;
if (i915_gpu_idle(dev_priv->dev)) {
DRM_ERROR("Couldn't idle GPU\n");
udelay(10);
}
}
return ret;
}
static void undo_idling(struct drm_i915_private *dev_priv, bool interruptible)
{
if (unlikely(dev_priv->gtt.do_idle_maps))
dev_priv->mm.interruptible = interruptible;
}
void i915_check_and_clear_faults(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_engine_cs *ring;
int i;
if (INTEL_INFO(dev)->gen < 6)
return;
for_each_ring(ring, dev_priv, i) {
u32 fault_reg;
fault_reg = I915_READ(RING_FAULT_REG(ring));
if (fault_reg & RING_FAULT_VALID) {
DRM_DEBUG_DRIVER("Unexpected fault\n"
"\tAddr: 0x%08lx\n"
"\tAddress space: %s\n"
"\tSource ID: %d\n"
"\tType: %d\n",
fault_reg & PAGE_MASK,
fault_reg & RING_FAULT_GTTSEL_MASK ? "GGTT" : "PPGTT",
RING_FAULT_SRCID(fault_reg),
RING_FAULT_FAULT_TYPE(fault_reg));
I915_WRITE(RING_FAULT_REG(ring),
fault_reg & ~RING_FAULT_VALID);
}
}
POSTING_READ(RING_FAULT_REG(&dev_priv->ring[RCS]));
}
static void i915_ggtt_flush(struct drm_i915_private *dev_priv)
{
if (INTEL_INFO(dev_priv->dev)->gen < 6) {
intel_gtt_chipset_flush();
} else {
I915_WRITE(GFX_FLSH_CNTL_GEN6, GFX_FLSH_CNTL_EN);
POSTING_READ(GFX_FLSH_CNTL_GEN6);
}
}
void i915_gem_suspend_gtt_mappings(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
if (INTEL_INFO(dev)->gen < 6)
return;
i915_check_and_clear_faults(dev);
dev_priv->gtt.base.clear_range(&dev_priv->gtt.base,
dev_priv->gtt.base.start,
dev_priv->gtt.base.total,
true);
i915_ggtt_flush(dev_priv);
}
int i915_gem_gtt_prepare_object(struct drm_i915_gem_object *obj)
{
if (!dma_map_sg(&obj->base.dev->pdev->dev,
obj->pages->sgl, obj->pages->nents,
PCI_DMA_BIDIRECTIONAL))
return -ENOSPC;
return 0;
}
static void gen8_set_pte(void __iomem *addr, gen8_pte_t pte)
{
#ifdef writeq
writeq(pte, addr);
#else
iowrite32((u32)pte, addr);
iowrite32(pte >> 32, addr + 4);
#endif
}
static void gen8_ggtt_insert_entries(struct i915_address_space *vm,
struct sg_table *st,
uint64_t start,
enum i915_cache_level level, u32 unused)
{
struct drm_i915_private *dev_priv = vm->dev->dev_private;
unsigned first_entry = start >> PAGE_SHIFT;
gen8_pte_t __iomem *gtt_entries =
(gen8_pte_t __iomem *)dev_priv->gtt.gsm + first_entry;
int i = 0;
struct sg_page_iter sg_iter;
dma_addr_t addr = 0;
for_each_sg_page(st->sgl, &sg_iter, st->nents, 0) {
addr = sg_dma_address(sg_iter.sg) +
(sg_iter.sg_pgoffset << PAGE_SHIFT);
gen8_set_pte(&gtt_entries[i],
gen8_pte_encode(addr, level, true));
i++;
}
if (i != 0)
WARN_ON(readq(&gtt_entries[i-1])
!= gen8_pte_encode(addr, level, true));
I915_WRITE(GFX_FLSH_CNTL_GEN6, GFX_FLSH_CNTL_EN);
POSTING_READ(GFX_FLSH_CNTL_GEN6);
}
static void gen6_ggtt_insert_entries(struct i915_address_space *vm,
struct sg_table *st,
uint64_t start,
enum i915_cache_level level, u32 flags)
{
struct drm_i915_private *dev_priv = vm->dev->dev_private;
unsigned first_entry = start >> PAGE_SHIFT;
gen6_pte_t __iomem *gtt_entries =
(gen6_pte_t __iomem *)dev_priv->gtt.gsm + first_entry;
int i = 0;
struct sg_page_iter sg_iter;
dma_addr_t addr = 0;
for_each_sg_page(st->sgl, &sg_iter, st->nents, 0) {
addr = sg_page_iter_dma_address(&sg_iter);
iowrite32(vm->pte_encode(addr, level, true, flags), &gtt_entries[i]);
i++;
}
if (i != 0) {
unsigned long gtt = readl(&gtt_entries[i-1]);
WARN_ON(gtt != vm->pte_encode(addr, level, true, flags));
}
I915_WRITE(GFX_FLSH_CNTL_GEN6, GFX_FLSH_CNTL_EN);
POSTING_READ(GFX_FLSH_CNTL_GEN6);
}
static void gen8_ggtt_clear_range(struct i915_address_space *vm,
uint64_t start,
uint64_t length,
bool use_scratch)
{
struct drm_i915_private *dev_priv = vm->dev->dev_private;
unsigned first_entry = start >> PAGE_SHIFT;
unsigned num_entries = length >> PAGE_SHIFT;
gen8_pte_t scratch_pte, __iomem *gtt_base =
(gen8_pte_t __iomem *) dev_priv->gtt.gsm + first_entry;
const int max_entries = gtt_total_entries(dev_priv->gtt) - first_entry;
int i;
if (WARN(num_entries > max_entries,
"First entry = %d; Num entries = %d (max=%d)\n",
first_entry, num_entries, max_entries))
num_entries = max_entries;
scratch_pte = gen8_pte_encode(px_dma(vm->scratch_page),
I915_CACHE_LLC,
use_scratch);
for (i = 0; i < num_entries; i++)
gen8_set_pte(&gtt_base[i], scratch_pte);
readl(gtt_base);
}
static void gen6_ggtt_clear_range(struct i915_address_space *vm,
uint64_t start,
uint64_t length,
bool use_scratch)
{
struct drm_i915_private *dev_priv = vm->dev->dev_private;
unsigned first_entry = start >> PAGE_SHIFT;
unsigned num_entries = length >> PAGE_SHIFT;
gen6_pte_t scratch_pte, __iomem *gtt_base =
(gen6_pte_t __iomem *) dev_priv->gtt.gsm + first_entry;
const int max_entries = gtt_total_entries(dev_priv->gtt) - first_entry;
int i;
if (WARN(num_entries > max_entries,
"First entry = %d; Num entries = %d (max=%d)\n",
first_entry, num_entries, max_entries))
num_entries = max_entries;
scratch_pte = vm->pte_encode(px_dma(vm->scratch_page),
I915_CACHE_LLC, use_scratch, 0);
for (i = 0; i < num_entries; i++)
iowrite32(scratch_pte, &gtt_base[i]);
readl(gtt_base);
}
static void i915_ggtt_insert_entries(struct i915_address_space *vm,
struct sg_table *pages,
uint64_t start,
enum i915_cache_level cache_level, u32 unused)
{
unsigned int flags = (cache_level == I915_CACHE_NONE) ?
AGP_USER_MEMORY : AGP_USER_CACHED_MEMORY;
intel_gtt_insert_sg_entries(pages, start >> PAGE_SHIFT, flags);
}
static void i915_ggtt_clear_range(struct i915_address_space *vm,
uint64_t start,
uint64_t length,
bool unused)
{
unsigned first_entry = start >> PAGE_SHIFT;
unsigned num_entries = length >> PAGE_SHIFT;
intel_gtt_clear_range(first_entry, num_entries);
}
static int ggtt_bind_vma(struct i915_vma *vma,
enum i915_cache_level cache_level,
u32 flags)
{
struct drm_device *dev = vma->vm->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct drm_i915_gem_object *obj = vma->obj;
struct sg_table *pages = obj->pages;
u32 pte_flags = 0;
int ret;
ret = i915_get_ggtt_vma_pages(vma);
if (ret)
return ret;
pages = vma->ggtt_view.pages;
if (obj->gt_ro)
pte_flags |= PTE_READ_ONLY;
if (!dev_priv->mm.aliasing_ppgtt || flags & GLOBAL_BIND) {
vma->vm->insert_entries(vma->vm, pages,
vma->node.start,
cache_level, pte_flags);
vma->bound |= GLOBAL_BIND;
}
if (dev_priv->mm.aliasing_ppgtt && flags & LOCAL_BIND) {
struct i915_hw_ppgtt *appgtt = dev_priv->mm.aliasing_ppgtt;
appgtt->base.insert_entries(&appgtt->base, pages,
vma->node.start,
cache_level, pte_flags);
}
return 0;
}
static void ggtt_unbind_vma(struct i915_vma *vma)
{
struct drm_device *dev = vma->vm->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct drm_i915_gem_object *obj = vma->obj;
const uint64_t size = min_t(uint64_t,
obj->base.size,
vma->node.size);
if (vma->bound & GLOBAL_BIND) {
vma->vm->clear_range(vma->vm,
vma->node.start,
size,
true);
}
if (dev_priv->mm.aliasing_ppgtt && vma->bound & LOCAL_BIND) {
struct i915_hw_ppgtt *appgtt = dev_priv->mm.aliasing_ppgtt;
appgtt->base.clear_range(&appgtt->base,
vma->node.start,
size,
true);
}
}
void i915_gem_gtt_finish_object(struct drm_i915_gem_object *obj)
{
struct drm_device *dev = obj->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
bool interruptible;
interruptible = do_idling(dev_priv);
dma_unmap_sg(&dev->pdev->dev, obj->pages->sgl, obj->pages->nents,
PCI_DMA_BIDIRECTIONAL);
undo_idling(dev_priv, interruptible);
}
static void i915_gtt_color_adjust(struct drm_mm_node *node,
unsigned long color,
u64 *start,
u64 *end)
{
if (node->color != color)
*start += 4096;
if (!list_empty(&node->node_list)) {
node = list_entry(node->node_list.next,
struct drm_mm_node,
node_list);
if (node->allocated && node->color != color)
*end -= 4096;
}
}
static int i915_gem_setup_global_gtt(struct drm_device *dev,
unsigned long start,
unsigned long mappable_end,
unsigned long end)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct i915_address_space *ggtt_vm = &dev_priv->gtt.base;
struct drm_mm_node *entry;
struct drm_i915_gem_object *obj;
unsigned long hole_start, hole_end;
int ret;
BUG_ON(mappable_end > end);
drm_mm_init(&ggtt_vm->mm, start, end - start - PAGE_SIZE);
dev_priv->gtt.base.start = start;
dev_priv->gtt.base.total = end - start;
if (intel_vgpu_active(dev)) {
ret = intel_vgt_balloon(dev);
if (ret)
return ret;
}
if (!HAS_LLC(dev))
dev_priv->gtt.base.mm.color_adjust = i915_gtt_color_adjust;
list_for_each_entry(obj, &dev_priv->mm.bound_list, global_list) {
struct i915_vma *vma = i915_gem_obj_to_vma(obj, ggtt_vm);
DRM_DEBUG_KMS("reserving preallocated space: %lx + %zx\n",
i915_gem_obj_ggtt_offset(obj), obj->base.size);
WARN_ON(i915_gem_obj_ggtt_bound(obj));
ret = drm_mm_reserve_node(&ggtt_vm->mm, &vma->node);
if (ret) {
DRM_DEBUG_KMS("Reservation failed: %i\n", ret);
return ret;
}
vma->bound |= GLOBAL_BIND;
}
drm_mm_for_each_hole(entry, &ggtt_vm->mm, hole_start, hole_end) {
DRM_DEBUG_KMS("clearing unused GTT space: [%lx, %lx]\n",
hole_start, hole_end);
ggtt_vm->clear_range(ggtt_vm, hole_start,
hole_end - hole_start, true);
}
ggtt_vm->clear_range(ggtt_vm, end - PAGE_SIZE, PAGE_SIZE, true);
if (USES_PPGTT(dev) && !USES_FULL_PPGTT(dev)) {
struct i915_hw_ppgtt *ppgtt;
ppgtt = kzalloc(sizeof(*ppgtt), GFP_KERNEL);
if (!ppgtt)
return -ENOMEM;
ret = __hw_ppgtt_init(dev, ppgtt);
if (ret) {
ppgtt->base.cleanup(&ppgtt->base);
kfree(ppgtt);
return ret;
}
if (ppgtt->base.allocate_va_range)
ret = ppgtt->base.allocate_va_range(&ppgtt->base, 0,
ppgtt->base.total);
if (ret) {
ppgtt->base.cleanup(&ppgtt->base);
kfree(ppgtt);
return ret;
}
ppgtt->base.clear_range(&ppgtt->base,
ppgtt->base.start,
ppgtt->base.total,
true);
dev_priv->mm.aliasing_ppgtt = ppgtt;
}
return 0;
}
void i915_gem_init_global_gtt(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
u64 gtt_size, mappable_size;
gtt_size = dev_priv->gtt.base.total;
mappable_size = dev_priv->gtt.mappable_end;
i915_gem_setup_global_gtt(dev, 0, mappable_size, gtt_size);
}
void i915_global_gtt_cleanup(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct i915_address_space *vm = &dev_priv->gtt.base;
if (dev_priv->mm.aliasing_ppgtt) {
struct i915_hw_ppgtt *ppgtt = dev_priv->mm.aliasing_ppgtt;
ppgtt->base.cleanup(&ppgtt->base);
}
if (drm_mm_initialized(&vm->mm)) {
if (intel_vgpu_active(dev))
intel_vgt_deballoon();
drm_mm_takedown(&vm->mm);
list_del(&vm->global_link);
}
vm->cleanup(vm);
}
static unsigned int gen6_get_total_gtt_size(u16 snb_gmch_ctl)
{
snb_gmch_ctl >>= SNB_GMCH_GGMS_SHIFT;
snb_gmch_ctl &= SNB_GMCH_GGMS_MASK;
return snb_gmch_ctl << 20;
}
static unsigned int gen8_get_total_gtt_size(u16 bdw_gmch_ctl)
{
bdw_gmch_ctl >>= BDW_GMCH_GGMS_SHIFT;
bdw_gmch_ctl &= BDW_GMCH_GGMS_MASK;
if (bdw_gmch_ctl)
bdw_gmch_ctl = 1 << bdw_gmch_ctl;
#ifdef CONFIG_X86_32
if (bdw_gmch_ctl > 4)
bdw_gmch_ctl = 4;
#endif
return bdw_gmch_ctl << 20;
}
static unsigned int chv_get_total_gtt_size(u16 gmch_ctrl)
{
gmch_ctrl >>= SNB_GMCH_GGMS_SHIFT;
gmch_ctrl &= SNB_GMCH_GGMS_MASK;
if (gmch_ctrl)
return 1 << (20 + gmch_ctrl);
return 0;
}
static size_t gen6_get_stolen_size(u16 snb_gmch_ctl)
{
snb_gmch_ctl >>= SNB_GMCH_GMS_SHIFT;
snb_gmch_ctl &= SNB_GMCH_GMS_MASK;
return snb_gmch_ctl << 25;
}
static size_t gen8_get_stolen_size(u16 bdw_gmch_ctl)
{
bdw_gmch_ctl >>= BDW_GMCH_GMS_SHIFT;
bdw_gmch_ctl &= BDW_GMCH_GMS_MASK;
return bdw_gmch_ctl << 25;
}
static size_t chv_get_stolen_size(u16 gmch_ctrl)
{
gmch_ctrl >>= SNB_GMCH_GMS_SHIFT;
gmch_ctrl &= SNB_GMCH_GMS_MASK;
if (gmch_ctrl < 0x11)
return gmch_ctrl << 25;
else if (gmch_ctrl < 0x17)
return (gmch_ctrl - 0x11 + 2) << 22;
else
return (gmch_ctrl - 0x17 + 9) << 22;
}
static size_t gen9_get_stolen_size(u16 gen9_gmch_ctl)
{
gen9_gmch_ctl >>= BDW_GMCH_GMS_SHIFT;
gen9_gmch_ctl &= BDW_GMCH_GMS_MASK;
if (gen9_gmch_ctl < 0xf0)
return gen9_gmch_ctl << 25;
else
return (gen9_gmch_ctl - 0xf0 + 1) << 22;
}
static int ggtt_probe_common(struct drm_device *dev,
size_t gtt_size)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct i915_page_scratch *scratch_page;
phys_addr_t gtt_phys_addr;
gtt_phys_addr = pci_resource_start(dev->pdev, 0) +
(pci_resource_len(dev->pdev, 0) / 2);
if (IS_BROXTON(dev))
dev_priv->gtt.gsm = ioremap_nocache(gtt_phys_addr, gtt_size);
else
dev_priv->gtt.gsm = ioremap_wc(gtt_phys_addr, gtt_size);
if (!dev_priv->gtt.gsm) {
DRM_ERROR("Failed to map the gtt page table\n");
return -ENOMEM;
}
scratch_page = alloc_scratch_page(dev);
if (IS_ERR(scratch_page)) {
DRM_ERROR("Scratch setup failed\n");
iounmap(dev_priv->gtt.gsm);
return PTR_ERR(scratch_page);
}
dev_priv->gtt.base.scratch_page = scratch_page;
return 0;
}
static void bdw_setup_private_ppat(struct drm_i915_private *dev_priv)
{
uint64_t pat;
pat = GEN8_PPAT(0, GEN8_PPAT_WB | GEN8_PPAT_LLC) |
GEN8_PPAT(1, GEN8_PPAT_WC | GEN8_PPAT_LLCELLC) |
GEN8_PPAT(2, GEN8_PPAT_WT | GEN8_PPAT_LLCELLC) |
GEN8_PPAT(3, GEN8_PPAT_UC) |
GEN8_PPAT(4, GEN8_PPAT_WB | GEN8_PPAT_LLCELLC | GEN8_PPAT_AGE(0)) |
GEN8_PPAT(5, GEN8_PPAT_WB | GEN8_PPAT_LLCELLC | GEN8_PPAT_AGE(1)) |
GEN8_PPAT(6, GEN8_PPAT_WB | GEN8_PPAT_LLCELLC | GEN8_PPAT_AGE(2)) |
GEN8_PPAT(7, GEN8_PPAT_WB | GEN8_PPAT_LLCELLC | GEN8_PPAT_AGE(3));
if (!USES_PPGTT(dev_priv->dev))
pat = GEN8_PPAT(0, GEN8_PPAT_UC);
I915_WRITE(GEN8_PRIVATE_PAT, pat);
I915_WRITE(GEN8_PRIVATE_PAT + 4, pat >> 32);
}
static void chv_setup_private_ppat(struct drm_i915_private *dev_priv)
{
uint64_t pat;
pat = GEN8_PPAT(0, CHV_PPAT_SNOOP) |
GEN8_PPAT(1, 0) |
GEN8_PPAT(2, 0) |
GEN8_PPAT(3, 0) |
GEN8_PPAT(4, CHV_PPAT_SNOOP) |
GEN8_PPAT(5, CHV_PPAT_SNOOP) |
GEN8_PPAT(6, CHV_PPAT_SNOOP) |
GEN8_PPAT(7, CHV_PPAT_SNOOP);
I915_WRITE(GEN8_PRIVATE_PAT, pat);
I915_WRITE(GEN8_PRIVATE_PAT + 4, pat >> 32);
}
static int gen8_gmch_probe(struct drm_device *dev,
u64 *gtt_total,
size_t *stolen,
phys_addr_t *mappable_base,
u64 *mappable_end)
{
struct drm_i915_private *dev_priv = dev->dev_private;
u64 gtt_size;
u16 snb_gmch_ctl;
int ret;
*mappable_base = pci_resource_start(dev->pdev, 2);
*mappable_end = pci_resource_len(dev->pdev, 2);
if (!pci_set_dma_mask(dev->pdev, DMA_BIT_MASK(39)))
pci_set_consistent_dma_mask(dev->pdev, DMA_BIT_MASK(39));
pci_read_config_word(dev->pdev, SNB_GMCH_CTRL, &snb_gmch_ctl);
if (INTEL_INFO(dev)->gen >= 9) {
*stolen = gen9_get_stolen_size(snb_gmch_ctl);
gtt_size = gen8_get_total_gtt_size(snb_gmch_ctl);
} else if (IS_CHERRYVIEW(dev)) {
*stolen = chv_get_stolen_size(snb_gmch_ctl);
gtt_size = chv_get_total_gtt_size(snb_gmch_ctl);
} else {
*stolen = gen8_get_stolen_size(snb_gmch_ctl);
gtt_size = gen8_get_total_gtt_size(snb_gmch_ctl);
}
*gtt_total = (gtt_size / sizeof(gen8_pte_t)) << PAGE_SHIFT;
if (IS_CHERRYVIEW(dev) || IS_BROXTON(dev))
chv_setup_private_ppat(dev_priv);
else
bdw_setup_private_ppat(dev_priv);
ret = ggtt_probe_common(dev, gtt_size);
dev_priv->gtt.base.clear_range = gen8_ggtt_clear_range;
dev_priv->gtt.base.insert_entries = gen8_ggtt_insert_entries;
dev_priv->gtt.base.bind_vma = ggtt_bind_vma;
dev_priv->gtt.base.unbind_vma = ggtt_unbind_vma;
return ret;
}
static int gen6_gmch_probe(struct drm_device *dev,
u64 *gtt_total,
size_t *stolen,
phys_addr_t *mappable_base,
u64 *mappable_end)
{
struct drm_i915_private *dev_priv = dev->dev_private;
unsigned int gtt_size;
u16 snb_gmch_ctl;
int ret;
*mappable_base = pci_resource_start(dev->pdev, 2);
*mappable_end = pci_resource_len(dev->pdev, 2);
if ((*mappable_end < (64<<20) || (*mappable_end > (512<<20)))) {
DRM_ERROR("Unknown GMADR size (%llx)\n",
dev_priv->gtt.mappable_end);
return -ENXIO;
}
if (!pci_set_dma_mask(dev->pdev, DMA_BIT_MASK(40)))
pci_set_consistent_dma_mask(dev->pdev, DMA_BIT_MASK(40));
pci_read_config_word(dev->pdev, SNB_GMCH_CTRL, &snb_gmch_ctl);
*stolen = gen6_get_stolen_size(snb_gmch_ctl);
gtt_size = gen6_get_total_gtt_size(snb_gmch_ctl);
*gtt_total = (gtt_size / sizeof(gen6_pte_t)) << PAGE_SHIFT;
ret = ggtt_probe_common(dev, gtt_size);
dev_priv->gtt.base.clear_range = gen6_ggtt_clear_range;
dev_priv->gtt.base.insert_entries = gen6_ggtt_insert_entries;
dev_priv->gtt.base.bind_vma = ggtt_bind_vma;
dev_priv->gtt.base.unbind_vma = ggtt_unbind_vma;
return ret;
}
static void gen6_gmch_remove(struct i915_address_space *vm)
{
struct i915_gtt *gtt = container_of(vm, struct i915_gtt, base);
iounmap(gtt->gsm);
free_scratch_page(vm->dev, vm->scratch_page);
}
static int i915_gmch_probe(struct drm_device *dev,
u64 *gtt_total,
size_t *stolen,
phys_addr_t *mappable_base,
u64 *mappable_end)
{
struct drm_i915_private *dev_priv = dev->dev_private;
int ret;
ret = intel_gmch_probe(dev_priv->bridge_dev, dev_priv->dev->pdev, NULL);
if (!ret) {
DRM_ERROR("failed to set up gmch\n");
return -EIO;
}
intel_gtt_get(gtt_total, stolen, mappable_base, mappable_end);
dev_priv->gtt.do_idle_maps = needs_idle_maps(dev_priv->dev);
dev_priv->gtt.base.insert_entries = i915_ggtt_insert_entries;
dev_priv->gtt.base.clear_range = i915_ggtt_clear_range;
dev_priv->gtt.base.bind_vma = ggtt_bind_vma;
dev_priv->gtt.base.unbind_vma = ggtt_unbind_vma;
if (unlikely(dev_priv->gtt.do_idle_maps))
DRM_INFO("applying Ironlake quirks for intel_iommu\n");
return 0;
}
static void i915_gmch_remove(struct i915_address_space *vm)
{
intel_gmch_remove();
}
int i915_gem_gtt_init(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct i915_gtt *gtt = &dev_priv->gtt;
int ret;
if (INTEL_INFO(dev)->gen <= 5) {
gtt->gtt_probe = i915_gmch_probe;
gtt->base.cleanup = i915_gmch_remove;
} else if (INTEL_INFO(dev)->gen < 8) {
gtt->gtt_probe = gen6_gmch_probe;
gtt->base.cleanup = gen6_gmch_remove;
if (IS_HASWELL(dev) && dev_priv->ellc_size)
gtt->base.pte_encode = iris_pte_encode;
else if (IS_HASWELL(dev))
gtt->base.pte_encode = hsw_pte_encode;
else if (IS_VALLEYVIEW(dev))
gtt->base.pte_encode = byt_pte_encode;
else if (INTEL_INFO(dev)->gen >= 7)
gtt->base.pte_encode = ivb_pte_encode;
else
gtt->base.pte_encode = snb_pte_encode;
} else {
dev_priv->gtt.gtt_probe = gen8_gmch_probe;
dev_priv->gtt.base.cleanup = gen6_gmch_remove;
}
gtt->base.dev = dev;
ret = gtt->gtt_probe(dev, &gtt->base.total, &gtt->stolen_size,
&gtt->mappable_base, &gtt->mappable_end);
if (ret)
return ret;
DRM_INFO("Memory usable by graphics device = %lluM\n",
gtt->base.total >> 20);
DRM_DEBUG_DRIVER("GMADR size = %lldM\n", gtt->mappable_end >> 20);
DRM_DEBUG_DRIVER("GTT stolen size = %zdM\n", gtt->stolen_size >> 20);
#ifdef CONFIG_INTEL_IOMMU
if (intel_iommu_gfx_mapped)
DRM_INFO("VT-d active for gfx access\n");
#endif
i915.enable_ppgtt = sanitize_enable_ppgtt(dev, i915.enable_ppgtt);
DRM_DEBUG_DRIVER("ppgtt mode: %i\n", i915.enable_ppgtt);
return 0;
}
void i915_gem_restore_gtt_mappings(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct drm_i915_gem_object *obj;
struct i915_address_space *vm;
struct i915_vma *vma;
bool flush;
i915_check_and_clear_faults(dev);
dev_priv->gtt.base.clear_range(&dev_priv->gtt.base,
dev_priv->gtt.base.start,
dev_priv->gtt.base.total,
true);
vm = &dev_priv->gtt.base;
list_for_each_entry(obj, &dev_priv->mm.bound_list, global_list) {
flush = false;
list_for_each_entry(vma, &obj->vma_list, vma_link) {
if (vma->vm != vm)
continue;
WARN_ON(i915_vma_bind(vma, obj->cache_level,
PIN_UPDATE));
flush = true;
}
if (flush)
i915_gem_clflush_object(obj, obj->pin_display);
}
if (INTEL_INFO(dev)->gen >= 8) {
if (IS_CHERRYVIEW(dev) || IS_BROXTON(dev))
chv_setup_private_ppat(dev_priv);
else
bdw_setup_private_ppat(dev_priv);
return;
}
if (USES_PPGTT(dev)) {
list_for_each_entry(vm, &dev_priv->vm_list, global_link) {
struct i915_hw_ppgtt *ppgtt =
container_of(vm, struct i915_hw_ppgtt,
base);
if (i915_is_ggtt(vm))
ppgtt = dev_priv->mm.aliasing_ppgtt;
gen6_write_page_range(dev_priv, &ppgtt->pd,
0, ppgtt->base.total);
}
}
i915_ggtt_flush(dev_priv);
}
static struct i915_vma *
__i915_gem_vma_create(struct drm_i915_gem_object *obj,
struct i915_address_space *vm,
const struct i915_ggtt_view *ggtt_view)
{
struct i915_vma *vma;
if (WARN_ON(i915_is_ggtt(vm) != !!ggtt_view))
return ERR_PTR(-EINVAL);
vma = kmem_cache_zalloc(to_i915(obj->base.dev)->vmas, GFP_KERNEL);
if (vma == NULL)
return ERR_PTR(-ENOMEM);
INIT_LIST_HEAD(&vma->vma_link);
INIT_LIST_HEAD(&vma->mm_list);
INIT_LIST_HEAD(&vma->exec_list);
vma->vm = vm;
vma->obj = obj;
if (i915_is_ggtt(vm))
vma->ggtt_view = *ggtt_view;
list_add_tail(&vma->vma_link, &obj->vma_list);
if (!i915_is_ggtt(vm))
i915_ppgtt_get(i915_vm_to_ppgtt(vm));
return vma;
}
struct i915_vma *
i915_gem_obj_lookup_or_create_vma(struct drm_i915_gem_object *obj,
struct i915_address_space *vm)
{
struct i915_vma *vma;
vma = i915_gem_obj_to_vma(obj, vm);
if (!vma)
vma = __i915_gem_vma_create(obj, vm,
i915_is_ggtt(vm) ? &i915_ggtt_view_normal : NULL);
return vma;
}
struct i915_vma *
i915_gem_obj_lookup_or_create_ggtt_vma(struct drm_i915_gem_object *obj,
const struct i915_ggtt_view *view)
{
struct i915_address_space *ggtt = i915_obj_to_ggtt(obj);
struct i915_vma *vma;
if (WARN_ON(!view))
return ERR_PTR(-EINVAL);
vma = i915_gem_obj_to_ggtt_view(obj, view);
if (IS_ERR(vma))
return vma;
if (!vma)
vma = __i915_gem_vma_create(obj, ggtt, view);
return vma;
}
static void
rotate_pages(dma_addr_t *in, unsigned int width, unsigned int height,
struct sg_table *st)
{
unsigned int column, row;
unsigned int src_idx;
struct scatterlist *sg = st->sgl;
st->nents = 0;
for (column = 0; column < width; column++) {
src_idx = width * (height - 1) + column;
for (row = 0; row < height; row++) {
st->nents++;
sg_set_page(sg, NULL, PAGE_SIZE, 0);
sg_dma_address(sg) = in[src_idx];
sg_dma_len(sg) = PAGE_SIZE;
sg = sg_next(sg);
src_idx -= width;
}
}
}
static struct sg_table *
intel_rotate_fb_obj_pages(struct i915_ggtt_view *ggtt_view,
struct drm_i915_gem_object *obj)
{
struct intel_rotation_info *rot_info = &ggtt_view->rotation_info;
unsigned int size_pages = rot_info->size >> PAGE_SHIFT;
struct sg_page_iter sg_iter;
unsigned long i;
dma_addr_t *page_addr_list;
struct sg_table *st;
int ret = -ENOMEM;
page_addr_list = drm_malloc_ab(obj->base.size / PAGE_SIZE,
sizeof(dma_addr_t));
if (!page_addr_list)
return ERR_PTR(ret);
st = kmalloc(sizeof(*st), GFP_KERNEL);
if (!st)
goto err_st_alloc;
ret = sg_alloc_table(st, size_pages, GFP_KERNEL);
if (ret)
goto err_sg_alloc;
i = 0;
for_each_sg_page(obj->pages->sgl, &sg_iter, obj->pages->nents, 0) {
page_addr_list[i] = sg_page_iter_dma_address(&sg_iter);
i++;
}
rotate_pages(page_addr_list,
rot_info->width_pages, rot_info->height_pages,
st);
DRM_DEBUG_KMS(
"Created rotated page mapping for object size %zu (pitch=%u, height=%u, pixel_format=0x%x, %ux%u tiles, %u pages).\n",
obj->base.size, rot_info->pitch, rot_info->height,
rot_info->pixel_format, rot_info->width_pages,
rot_info->height_pages, size_pages);
drm_free_large(page_addr_list);
return st;
err_sg_alloc:
kfree(st);
err_st_alloc:
drm_free_large(page_addr_list);
DRM_DEBUG_KMS(
"Failed to create rotated mapping for object size %zu! (%d) (pitch=%u, height=%u, pixel_format=0x%x, %ux%u tiles, %u pages)\n",
obj->base.size, ret, rot_info->pitch, rot_info->height,
rot_info->pixel_format, rot_info->width_pages,
rot_info->height_pages, size_pages);
return ERR_PTR(ret);
}
static struct sg_table *
intel_partial_pages(const struct i915_ggtt_view *view,
struct drm_i915_gem_object *obj)
{
struct sg_table *st;
struct scatterlist *sg;
struct sg_page_iter obj_sg_iter;
int ret = -ENOMEM;
st = kmalloc(sizeof(*st), GFP_KERNEL);
if (!st)
goto err_st_alloc;
ret = sg_alloc_table(st, view->params.partial.size, GFP_KERNEL);
if (ret)
goto err_sg_alloc;
sg = st->sgl;
st->nents = 0;
for_each_sg_page(obj->pages->sgl, &obj_sg_iter, obj->pages->nents,
view->params.partial.offset)
{
if (st->nents >= view->params.partial.size)
break;
sg_set_page(sg, NULL, PAGE_SIZE, 0);
sg_dma_address(sg) = sg_page_iter_dma_address(&obj_sg_iter);
sg_dma_len(sg) = PAGE_SIZE;
sg = sg_next(sg);
st->nents++;
}
return st;
err_sg_alloc:
kfree(st);
err_st_alloc:
return ERR_PTR(ret);
}
static int
i915_get_ggtt_vma_pages(struct i915_vma *vma)
{
int ret = 0;
if (vma->ggtt_view.pages)
return 0;
if (vma->ggtt_view.type == I915_GGTT_VIEW_NORMAL)
vma->ggtt_view.pages = vma->obj->pages;
else if (vma->ggtt_view.type == I915_GGTT_VIEW_ROTATED)
vma->ggtt_view.pages =
intel_rotate_fb_obj_pages(&vma->ggtt_view, vma->obj);
else if (vma->ggtt_view.type == I915_GGTT_VIEW_PARTIAL)
vma->ggtt_view.pages =
intel_partial_pages(&vma->ggtt_view, vma->obj);
else
WARN_ONCE(1, "GGTT view %u not implemented!\n",
vma->ggtt_view.type);
if (!vma->ggtt_view.pages) {
DRM_ERROR("Failed to get pages for GGTT view type %u!\n",
vma->ggtt_view.type);
ret = -EINVAL;
} else if (IS_ERR(vma->ggtt_view.pages)) {
ret = PTR_ERR(vma->ggtt_view.pages);
vma->ggtt_view.pages = NULL;
DRM_ERROR("Failed to get pages for VMA view type %u (%d)!\n",
vma->ggtt_view.type, ret);
}
return ret;
}
int i915_vma_bind(struct i915_vma *vma, enum i915_cache_level cache_level,
u32 flags)
{
int ret;
u32 bind_flags;
if (WARN_ON(flags == 0))
return -EINVAL;
bind_flags = 0;
if (flags & PIN_GLOBAL)
bind_flags |= GLOBAL_BIND;
if (flags & PIN_USER)
bind_flags |= LOCAL_BIND;
if (flags & PIN_UPDATE)
bind_flags |= vma->bound;
else
bind_flags &= ~vma->bound;
if (bind_flags == 0)
return 0;
if (vma->bound == 0 && vma->vm->allocate_va_range) {
trace_i915_va_alloc(vma->vm,
vma->node.start,
vma->node.size,
VM_TO_TRACE_NAME(vma->vm));
vma->pin_count++;
ret = vma->vm->allocate_va_range(vma->vm,
vma->node.start,
vma->node.size);
vma->pin_count--;
if (ret)
return ret;
}
ret = vma->vm->bind_vma(vma, cache_level, bind_flags);
if (ret)
return ret;
vma->bound |= bind_flags;
return 0;
}
size_t
i915_ggtt_view_size(struct drm_i915_gem_object *obj,
const struct i915_ggtt_view *view)
{
if (view->type == I915_GGTT_VIEW_NORMAL) {
return obj->base.size;
} else if (view->type == I915_GGTT_VIEW_ROTATED) {
return view->rotation_info.size;
} else if (view->type == I915_GGTT_VIEW_PARTIAL) {
return view->params.partial.size << PAGE_SHIFT;
} else {
WARN_ONCE(1, "GGTT view %u not implemented!\n", view->type);
return obj->base.size;
}
}
