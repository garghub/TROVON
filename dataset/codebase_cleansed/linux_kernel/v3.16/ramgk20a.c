static void
gk20a_ram_put(struct nouveau_fb *pfb, struct nouveau_mem **pmem)
{
struct device *dev = nv_device_base(nv_device(pfb));
struct gk20a_mem *mem = to_gk20a_mem(*pmem);
*pmem = NULL;
if (unlikely(mem == NULL))
return;
if (likely(mem->cpuaddr))
dma_free_coherent(dev, mem->base.size << PAGE_SHIFT,
mem->cpuaddr, mem->handle);
kfree(mem->base.pages);
kfree(mem);
}
static int
gk20a_ram_get(struct nouveau_fb *pfb, u64 size, u32 align, u32 ncmin,
u32 memtype, struct nouveau_mem **pmem)
{
struct device *dev = nv_device_base(nv_device(pfb));
struct gk20a_mem *mem;
u32 type = memtype & 0xff;
u32 npages, order;
int i;
nv_debug(pfb, "%s: size: %llx align: %x, ncmin: %x\n", __func__, size,
align, ncmin);
npages = size >> PAGE_SHIFT;
if (npages == 0)
npages = 1;
if (align == 0)
align = PAGE_SIZE;
align >>= PAGE_SHIFT;
order = fls(align);
if ((align & (align - 1)) == 0)
order--;
align = BIT(order);
npages = max(align, npages);
mem = kzalloc(sizeof(*mem), GFP_KERNEL);
if (!mem)
return -ENOMEM;
mem->base.size = npages;
mem->base.memtype = type;
mem->base.pages = kzalloc(sizeof(dma_addr_t) * npages, GFP_KERNEL);
if (!mem->base.pages) {
kfree(mem);
return -ENOMEM;
}
*pmem = &mem->base;
mem->cpuaddr = dma_alloc_coherent(dev, npages << PAGE_SHIFT,
&mem->handle, GFP_KERNEL);
if (!mem->cpuaddr) {
nv_error(pfb, "%s: cannot allocate memory!\n", __func__);
gk20a_ram_put(pfb, pmem);
return -ENOMEM;
}
align <<= PAGE_SHIFT;
if (unlikely(mem->handle & (align - 1)))
nv_warn(pfb, "memory not aligned as requested: %pad (0x%x)\n",
&mem->handle, align);
nv_debug(pfb, "alloc size: 0x%x, align: 0x%x, paddr: %pad, vaddr: %p\n",
npages << PAGE_SHIFT, align, &mem->handle, mem->cpuaddr);
for (i = 0; i < npages; i++)
mem->base.pages[i] = mem->handle + (PAGE_SIZE * i);
mem->base.offset = (u64)mem->base.pages[0];
return 0;
}
static int
gk20a_ram_ctor(struct nouveau_object *parent, struct nouveau_object *engine,
struct nouveau_oclass *oclass, void *data, u32 datasize,
struct nouveau_object **pobject)
{
struct nouveau_ram *ram;
int ret;
ret = nouveau_ram_create(parent, engine, oclass, &ram);
*pobject = nv_object(ram);
if (ret)
return ret;
ram->type = NV_MEM_TYPE_STOLEN;
ram->size = get_num_physpages() << PAGE_SHIFT;
ram->get = gk20a_ram_get;
ram->put = gk20a_ram_put;
return 0;
}
