static void etnaviv_core_dump_header(struct core_dump_iterator *iter,
u32 type, void *data_end)
{
struct etnaviv_dump_object_header *hdr = iter->hdr;
hdr->magic = cpu_to_le32(ETDUMP_MAGIC);
hdr->type = cpu_to_le32(type);
hdr->file_offset = cpu_to_le32(iter->data - iter->start);
hdr->file_size = cpu_to_le32(data_end - iter->data);
iter->hdr++;
iter->data += hdr->file_size;
}
static void etnaviv_core_dump_registers(struct core_dump_iterator *iter,
struct etnaviv_gpu *gpu)
{
struct etnaviv_dump_registers *reg = iter->data;
unsigned int i;
for (i = 0; i < ARRAY_SIZE(etnaviv_dump_registers); i++, reg++) {
reg->reg = etnaviv_dump_registers[i];
reg->value = gpu_read(gpu, etnaviv_dump_registers[i]);
}
etnaviv_core_dump_header(iter, ETDUMP_BUF_REG, reg);
}
static void etnaviv_core_dump_mmu(struct core_dump_iterator *iter,
struct etnaviv_gpu *gpu, size_t mmu_size)
{
etnaviv_iommu_dump(gpu->mmu, iter->data);
etnaviv_core_dump_header(iter, ETDUMP_BUF_MMU, iter->data + mmu_size);
}
static void etnaviv_core_dump_mem(struct core_dump_iterator *iter, u32 type,
void *ptr, size_t size, u64 iova)
{
memcpy(iter->data, ptr, size);
iter->hdr->iova = cpu_to_le64(iova);
etnaviv_core_dump_header(iter, type, iter->data + size);
}
void etnaviv_core_dump(struct etnaviv_gpu *gpu)
{
struct core_dump_iterator iter;
struct etnaviv_vram_mapping *vram;
struct etnaviv_gem_object *obj;
struct etnaviv_cmdbuf *cmd;
unsigned int n_obj, n_bomap_pages;
size_t file_size, mmu_size;
__le64 *bomap, *bomap_start;
mmu_size = etnaviv_iommu_dump_size(gpu->mmu);
n_obj = 4;
n_bomap_pages = 0;
file_size = ARRAY_SIZE(etnaviv_dump_registers) *
sizeof(struct etnaviv_dump_registers) +
mmu_size + gpu->buffer->size;
list_for_each_entry(cmd, &gpu->active_cmd_list, node) {
file_size += cmd->size;
n_obj++;
}
list_for_each_entry(vram, &gpu->mmu->mappings, mmu_node) {
if (!vram->use)
continue;
obj = vram->object;
file_size += obj->base.size;
n_bomap_pages += obj->base.size >> PAGE_SHIFT;
n_obj++;
}
if (n_bomap_pages) {
file_size += n_bomap_pages * sizeof(__le64);
n_obj++;
}
file_size += sizeof(*iter.hdr) * n_obj;
iter.start = vmalloc(file_size);
if (!iter.start) {
dev_warn(gpu->dev, "failed to allocate devcoredump file\n");
return;
}
iter.hdr = iter.start;
iter.data = &iter.hdr[n_obj];
memset(iter.hdr, 0, iter.data - iter.start);
etnaviv_core_dump_registers(&iter, gpu);
etnaviv_core_dump_mmu(&iter, gpu, mmu_size);
etnaviv_core_dump_mem(&iter, ETDUMP_BUF_RING, gpu->buffer->vaddr,
gpu->buffer->size, gpu->buffer->paddr);
list_for_each_entry(cmd, &gpu->active_cmd_list, node)
etnaviv_core_dump_mem(&iter, ETDUMP_BUF_CMD, cmd->vaddr,
cmd->size, cmd->paddr);
if (n_bomap_pages) {
bomap_start = bomap = iter.data;
memset(bomap, 0, sizeof(*bomap) * n_bomap_pages);
etnaviv_core_dump_header(&iter, ETDUMP_BUF_BOMAP,
bomap + n_bomap_pages);
} else {
bomap_start = bomap = NULL;
}
list_for_each_entry(vram, &gpu->mmu->mappings, mmu_node) {
struct page **pages;
void *vaddr;
if (vram->use == 0)
continue;
obj = vram->object;
mutex_lock(&obj->lock);
pages = etnaviv_gem_get_pages(obj);
mutex_unlock(&obj->lock);
if (pages) {
int j;
iter.hdr->data[0] = bomap - bomap_start;
for (j = 0; j < obj->base.size >> PAGE_SHIFT; j++)
*bomap++ = cpu_to_le64(page_to_phys(*pages++));
}
iter.hdr->iova = cpu_to_le64(vram->iova);
vaddr = etnaviv_gem_vmap(&obj->base);
if (vaddr)
memcpy(iter.data, vaddr, obj->base.size);
etnaviv_core_dump_header(&iter, ETDUMP_BUF_BO, iter.data +
obj->base.size);
}
etnaviv_core_dump_header(&iter, ETDUMP_BUF_END, iter.data);
dev_coredumpv(gpu->dev, iter.start, iter.data - iter.start, GFP_KERNEL);
}
