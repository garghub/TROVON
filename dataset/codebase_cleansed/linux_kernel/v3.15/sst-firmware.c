static void sst_memcpy32(volatile void __iomem *dest, void *src, u32 bytes)
{
u32 i;
for (i = 0; i < bytes; i += 4)
memcpy_toio(dest + i, src + i, 4);
}
struct sst_fw *sst_fw_new(struct sst_dsp *dsp,
const struct firmware *fw, void *private)
{
struct sst_fw *sst_fw;
int err;
if (!dsp->ops->parse_fw)
return NULL;
sst_fw = kzalloc(sizeof(*sst_fw), GFP_KERNEL);
if (sst_fw == NULL)
return NULL;
sst_fw->dsp = dsp;
sst_fw->private = private;
sst_fw->size = fw->size;
sst_fw->dma_buf = dma_alloc_coherent(dsp->dma_dev, sst_fw->size,
&sst_fw->dmable_fw_paddr, GFP_DMA | GFP_KERNEL);
if (!sst_fw->dma_buf) {
dev_err(dsp->dev, "error: DMA alloc failed\n");
kfree(sst_fw);
return NULL;
}
memcpy((void *)sst_fw->dma_buf, (void *)fw->data, fw->size);
err = dsp->ops->parse_fw(sst_fw);
if (err < 0) {
dev_err(dsp->dev, "error: parse fw failed %d\n", err);
goto parse_err;
}
mutex_lock(&dsp->mutex);
list_add(&sst_fw->list, &dsp->fw_list);
mutex_unlock(&dsp->mutex);
return sst_fw;
parse_err:
dma_free_coherent(dsp->dev, sst_fw->size,
sst_fw->dma_buf,
sst_fw->dmable_fw_paddr);
kfree(sst_fw);
return NULL;
}
void sst_fw_free(struct sst_fw *sst_fw)
{
struct sst_dsp *dsp = sst_fw->dsp;
mutex_lock(&dsp->mutex);
list_del(&sst_fw->list);
mutex_unlock(&dsp->mutex);
dma_free_coherent(dsp->dma_dev, sst_fw->size, sst_fw->dma_buf,
sst_fw->dmable_fw_paddr);
kfree(sst_fw);
}
void sst_fw_free_all(struct sst_dsp *dsp)
{
struct sst_fw *sst_fw, *t;
mutex_lock(&dsp->mutex);
list_for_each_entry_safe(sst_fw, t, &dsp->fw_list, list) {
list_del(&sst_fw->list);
dma_free_coherent(dsp->dev, sst_fw->size, sst_fw->dma_buf,
sst_fw->dmable_fw_paddr);
kfree(sst_fw);
}
mutex_unlock(&dsp->mutex);
}
struct sst_module *sst_module_new(struct sst_fw *sst_fw,
struct sst_module_template *template, void *private)
{
struct sst_dsp *dsp = sst_fw->dsp;
struct sst_module *sst_module;
sst_module = kzalloc(sizeof(*sst_module), GFP_KERNEL);
if (sst_module == NULL)
return NULL;
sst_module->id = template->id;
sst_module->dsp = dsp;
sst_module->sst_fw = sst_fw;
memcpy(&sst_module->s, &template->s, sizeof(struct sst_module_data));
memcpy(&sst_module->p, &template->p, sizeof(struct sst_module_data));
INIT_LIST_HEAD(&sst_module->block_list);
mutex_lock(&dsp->mutex);
list_add(&sst_module->list, &dsp->module_list);
mutex_unlock(&dsp->mutex);
return sst_module;
}
void sst_module_free(struct sst_module *sst_module)
{
struct sst_dsp *dsp = sst_module->dsp;
mutex_lock(&dsp->mutex);
list_del(&sst_module->list);
mutex_unlock(&dsp->mutex);
kfree(sst_module);
}
static struct sst_mem_block *find_block(struct sst_dsp *dsp, int type,
u32 offset)
{
struct sst_mem_block *block;
list_for_each_entry(block, &dsp->free_block_list, list) {
if (block->type == type && block->offset == offset)
return block;
}
return NULL;
}
static int block_alloc_contiguous(struct sst_module *module,
struct sst_module_data *data, u32 offset, int size)
{
struct list_head tmp = LIST_HEAD_INIT(tmp);
struct sst_dsp *dsp = module->dsp;
struct sst_mem_block *block;
while (size > 0) {
block = find_block(dsp, data->type, offset);
if (!block) {
list_splice(&tmp, &dsp->free_block_list);
return -ENOMEM;
}
list_move_tail(&block->list, &tmp);
offset += block->size;
size -= block->size;
}
list_for_each_entry(block, &tmp, list)
list_add(&block->module_list, &module->block_list);
list_splice(&tmp, &dsp->used_block_list);
return 0;
}
static int block_alloc(struct sst_module *module,
struct sst_module_data *data)
{
struct sst_dsp *dsp = module->dsp;
struct sst_mem_block *block, *tmp;
int ret = 0;
if (data->size == 0)
return 0;
list_for_each_entry_safe(block, tmp, &dsp->free_block_list, list) {
if (block->type != data->type)
continue;
if (data->size > block->size)
continue;
data->offset = block->offset;
block->data_type = data->data_type;
block->bytes_used = data->size % block->size;
list_add(&block->module_list, &module->block_list);
list_move(&block->list, &dsp->used_block_list);
dev_dbg(dsp->dev, " *module %d added block %d:%d\n",
module->id, block->type, block->index);
return 0;
}
list_for_each_entry_safe(block, tmp, &dsp->free_block_list, list) {
if (block->type != data->type)
continue;
if (data->size > block->size) {
ret = block_alloc_contiguous(module, data,
block->offset, data->size);
if (ret == 0)
return ret;
}
}
return -ENOMEM;
}
static void block_module_remove(struct sst_module *module)
{
struct sst_mem_block *block, *tmp;
struct sst_dsp *dsp = module->dsp;
int err;
list_for_each_entry(block, &module->block_list, module_list) {
if (block->ops && block->ops->disable) {
err = block->ops->disable(block);
if (err < 0)
dev_err(dsp->dev,
"error: cant disable block %d:%d\n",
block->type, block->index);
}
}
list_for_each_entry_safe(block, tmp, &module->block_list, module_list) {
list_del(&block->module_list);
list_move(&block->list, &dsp->free_block_list);
}
}
static int block_module_prepare(struct sst_module *module)
{
struct sst_mem_block *block;
int ret = 0;
list_for_each_entry(block, &module->block_list, module_list) {
if (block->ops && block->ops->enable) {
ret = block->ops->enable(block);
if (ret < 0) {
dev_err(module->dsp->dev,
"error: cant disable block %d:%d\n",
block->type, block->index);
goto err;
}
}
}
return ret;
err:
list_for_each_entry(block, &module->block_list, module_list) {
if (block->ops && block->ops->disable)
block->ops->disable(block);
}
return ret;
}
static int block_alloc_fixed(struct sst_module *module,
struct sst_module_data *data)
{
struct sst_dsp *dsp = module->dsp;
struct sst_mem_block *block, *tmp;
u32 end = data->offset + data->size, block_end;
int err;
if (data->type != SST_MEM_IRAM && data->type != SST_MEM_DRAM)
return 0;
list_for_each_entry_safe(block, tmp, &module->block_list, module_list) {
if (block->data_type != data->data_type)
continue;
block_end = block->offset + block->size;
if (data->offset >= block->offset && end < block_end)
return 0;
if (data->offset >= block->offset && data->offset < block_end) {
err = block_alloc_contiguous(module, data,
block->offset + block->size,
data->size - block->size);
if (err < 0)
return -ENOMEM;
return 0;
}
}
list_for_each_entry_safe(block, tmp, &dsp->free_block_list, list) {
block_end = block->offset + block->size;
if (data->offset >= block->offset && end < block_end) {
block->data_type = data->data_type;
list_move(&block->list, &dsp->used_block_list);
list_add(&block->module_list, &module->block_list);
return 0;
}
if (data->offset >= block->offset && data->offset < block_end) {
err = block_alloc_contiguous(module, data,
block->offset, data->size);
if (err < 0)
return -ENOMEM;
return 0;
}
}
return -ENOMEM;
}
int sst_module_insert_fixed_block(struct sst_module *module,
struct sst_module_data *data)
{
struct sst_dsp *dsp = module->dsp;
int ret;
mutex_lock(&dsp->mutex);
ret = block_alloc_fixed(module, data);
if (ret < 0) {
dev_err(dsp->dev,
"error: no free blocks for section at offset 0x%x size 0x%x\n",
data->offset, data->size);
mutex_unlock(&dsp->mutex);
return -ENOMEM;
}
ret = block_module_prepare(module);
if (ret < 0) {
dev_err(dsp->dev, "error: fw module prepare failed\n");
goto err;
}
sst_memcpy32(dsp->addr.lpe + data->offset, data->data, data->size);
mutex_unlock(&dsp->mutex);
return ret;
err:
block_module_remove(module);
mutex_unlock(&dsp->mutex);
return ret;
}
int sst_block_module_remove(struct sst_module *module)
{
struct sst_dsp *dsp = module->dsp;
mutex_lock(&dsp->mutex);
block_module_remove(module);
mutex_unlock(&dsp->mutex);
return 0;
}
struct sst_mem_block *sst_mem_block_register(struct sst_dsp *dsp, u32 offset,
u32 size, enum sst_mem_type type, struct sst_block_ops *ops, u32 index,
void *private)
{
struct sst_mem_block *block;
block = kzalloc(sizeof(*block), GFP_KERNEL);
if (block == NULL)
return NULL;
block->offset = offset;
block->size = size;
block->index = index;
block->type = type;
block->dsp = dsp;
block->private = private;
block->ops = ops;
mutex_lock(&dsp->mutex);
list_add(&block->list, &dsp->free_block_list);
mutex_unlock(&dsp->mutex);
return block;
}
void sst_mem_block_unregister_all(struct sst_dsp *dsp)
{
struct sst_mem_block *block, *tmp;
mutex_lock(&dsp->mutex);
list_for_each_entry_safe(block, tmp, &dsp->used_block_list, list) {
list_del(&block->list);
kfree(block);
}
list_for_each_entry_safe(block, tmp, &dsp->free_block_list, list) {
list_del(&block->list);
kfree(block);
}
mutex_unlock(&dsp->mutex);
}
struct sst_module *sst_mem_block_alloc_scratch(struct sst_dsp *dsp)
{
struct sst_module *sst_module, *scratch;
struct sst_mem_block *block, *tmp;
u32 block_size;
int ret = 0;
scratch = kzalloc(sizeof(struct sst_module), GFP_KERNEL);
if (scratch == NULL)
return NULL;
mutex_lock(&dsp->mutex);
list_for_each_entry(sst_module, &dsp->module_list, list) {
if (scratch->s.size > sst_module->s.size)
scratch->s.size = scratch->s.size;
else
scratch->s.size = sst_module->s.size;
}
dev_dbg(dsp->dev, "scratch buffer required is %d bytes\n",
scratch->s.size);
scratch->dsp = dsp;
scratch->s.type = SST_MEM_DRAM;
scratch->s.data_type = SST_DATA_S;
INIT_LIST_HEAD(&scratch->block_list);
if (!list_empty(&dsp->free_block_list))
block = list_first_entry(&dsp->free_block_list,
struct sst_mem_block, list);
else
block = list_first_entry(&dsp->used_block_list,
struct sst_mem_block, list);
block_size = block->size;
dev_dbg(dsp->dev, "allocating scratch blocks\n");
ret = block_alloc(scratch, &scratch->s);
if (ret < 0) {
dev_err(dsp->dev, "error: can't alloc scratch blocks\n");
goto err;
}
list_for_each_entry(sst_module, &dsp->module_list, list)
sst_module->s.offset = scratch->s.offset;
mutex_unlock(&dsp->mutex);
return scratch;
err:
list_for_each_entry_safe(block, tmp, &scratch->block_list, module_list)
list_del(&block->module_list);
mutex_unlock(&dsp->mutex);
return NULL;
}
void sst_mem_block_free_scratch(struct sst_dsp *dsp,
struct sst_module *scratch)
{
struct sst_mem_block *block, *tmp;
mutex_lock(&dsp->mutex);
list_for_each_entry_safe(block, tmp, &scratch->block_list, module_list)
list_del(&block->module_list);
mutex_unlock(&dsp->mutex);
}
struct sst_module *sst_module_get_from_id(struct sst_dsp *dsp, u32 id)
{
struct sst_module *module;
mutex_lock(&dsp->mutex);
list_for_each_entry(module, &dsp->module_list, list) {
if (module->id == id) {
mutex_unlock(&dsp->mutex);
return module;
}
}
mutex_unlock(&dsp->mutex);
return NULL;
}
