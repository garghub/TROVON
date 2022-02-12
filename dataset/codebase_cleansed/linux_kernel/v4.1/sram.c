static int sram_reserve_cmp(void *priv, struct list_head *a,
struct list_head *b)
{
struct sram_reserve *ra = list_entry(a, struct sram_reserve, list);
struct sram_reserve *rb = list_entry(b, struct sram_reserve, list);
return ra->start - rb->start;
}
static int sram_probe(struct platform_device *pdev)
{
void __iomem *virt_base;
struct sram_dev *sram;
struct resource *res;
struct device_node *np = pdev->dev.of_node, *child;
unsigned long size, cur_start, cur_size;
struct sram_reserve *rblocks, *block;
struct list_head reserve_list;
unsigned int nblocks;
int ret;
INIT_LIST_HEAD(&reserve_list);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(&pdev->dev, "found no memory resource\n");
return -EINVAL;
}
size = resource_size(res);
if (!devm_request_mem_region(&pdev->dev,
res->start, size, pdev->name)) {
dev_err(&pdev->dev, "could not request region for resource\n");
return -EBUSY;
}
virt_base = devm_ioremap_wc(&pdev->dev, res->start, size);
if (IS_ERR(virt_base))
return PTR_ERR(virt_base);
sram = devm_kzalloc(&pdev->dev, sizeof(*sram), GFP_KERNEL);
if (!sram)
return -ENOMEM;
sram->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(sram->clk))
sram->clk = NULL;
else
clk_prepare_enable(sram->clk);
sram->pool = devm_gen_pool_create(&pdev->dev, ilog2(SRAM_GRANULARITY), -1);
if (!sram->pool)
return -ENOMEM;
nblocks = (np) ? of_get_available_child_count(np) + 1 : 1;
rblocks = kmalloc((nblocks) * sizeof(*rblocks), GFP_KERNEL);
if (!rblocks) {
ret = -ENOMEM;
goto err_alloc;
}
block = &rblocks[0];
for_each_available_child_of_node(np, child) {
struct resource child_res;
ret = of_address_to_resource(child, 0, &child_res);
if (ret < 0) {
dev_err(&pdev->dev,
"could not get address for node %s\n",
child->full_name);
goto err_chunks;
}
if (child_res.start < res->start || child_res.end > res->end) {
dev_err(&pdev->dev,
"reserved block %s outside the sram area\n",
child->full_name);
ret = -EINVAL;
goto err_chunks;
}
block->start = child_res.start - res->start;
block->size = resource_size(&child_res);
list_add_tail(&block->list, &reserve_list);
dev_dbg(&pdev->dev, "found reserved block 0x%x-0x%x\n",
block->start,
block->start + block->size);
block++;
}
rblocks[nblocks - 1].start = size;
rblocks[nblocks - 1].size = 0;
list_add_tail(&rblocks[nblocks - 1].list, &reserve_list);
list_sort(NULL, &reserve_list, sram_reserve_cmp);
cur_start = 0;
list_for_each_entry(block, &reserve_list, list) {
if (block->start < cur_start) {
dev_err(&pdev->dev,
"block at 0x%x starts after current offset 0x%lx\n",
block->start, cur_start);
ret = -EINVAL;
goto err_chunks;
}
if (block->start == cur_start) {
cur_start = block->start + block->size;
continue;
}
cur_size = block->start - cur_start;
dev_dbg(&pdev->dev, "adding chunk 0x%lx-0x%lx\n",
cur_start, cur_start + cur_size);
ret = gen_pool_add_virt(sram->pool,
(unsigned long)virt_base + cur_start,
res->start + cur_start, cur_size, -1);
if (ret < 0)
goto err_chunks;
cur_start = block->start + block->size;
}
kfree(rblocks);
platform_set_drvdata(pdev, sram);
dev_dbg(&pdev->dev, "SRAM pool: %ld KiB @ 0x%p\n", size / 1024, virt_base);
return 0;
err_chunks:
kfree(rblocks);
err_alloc:
if (sram->clk)
clk_disable_unprepare(sram->clk);
return ret;
}
static int sram_remove(struct platform_device *pdev)
{
struct sram_dev *sram = platform_get_drvdata(pdev);
if (gen_pool_avail(sram->pool) < gen_pool_size(sram->pool))
dev_dbg(&pdev->dev, "removed while SRAM allocated\n");
if (sram->clk)
clk_disable_unprepare(sram->clk);
return 0;
}
static int __init sram_init(void)
{
return platform_driver_register(&sram_driver);
}
