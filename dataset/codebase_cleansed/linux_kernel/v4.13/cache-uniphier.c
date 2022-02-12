static void __uniphier_cache_sync(struct uniphier_cache_data *data)
{
writel_relaxed(UNIPHIER_SSCOPE_CM_SYNC,
data->op_base + UNIPHIER_SSCOPE);
readl_relaxed(data->op_base + UNIPHIER_SSCOPE);
}
static void __uniphier_cache_maint_common(struct uniphier_cache_data *data,
unsigned long start,
unsigned long size,
u32 operation)
{
unsigned long flags;
local_irq_save(flags);
writel_relaxed(UNIPHIER_SSCOLPQS_EF, data->op_base + UNIPHIER_SSCOLPQS);
do {
writel_relaxed(UNIPHIER_SSCOQM_CE | operation,
data->op_base + UNIPHIER_SSCOQM);
if (likely(UNIPHIER_SSCOQM_S_IS_RANGE(operation))) {
writel_relaxed(start, data->op_base + UNIPHIER_SSCOQAD);
writel_relaxed(size, data->op_base + UNIPHIER_SSCOQSZ);
}
} while (unlikely(readl_relaxed(data->op_base + UNIPHIER_SSCOPPQSEF) &
(UNIPHIER_SSCOPPQSEF_FE | UNIPHIER_SSCOPPQSEF_OE)));
while (likely(readl_relaxed(data->op_base + UNIPHIER_SSCOLPQS) !=
UNIPHIER_SSCOLPQS_EF))
cpu_relax();
local_irq_restore(flags);
}
static void __uniphier_cache_maint_all(struct uniphier_cache_data *data,
u32 operation)
{
__uniphier_cache_maint_common(data, 0, 0,
UNIPHIER_SSCOQM_S_ALL | operation);
__uniphier_cache_sync(data);
}
static void __uniphier_cache_maint_range(struct uniphier_cache_data *data,
unsigned long start, unsigned long end,
u32 operation)
{
unsigned long size;
start = start & ~(data->line_size - 1);
size = end - start;
if (unlikely(size >= (unsigned long)(-data->line_size))) {
__uniphier_cache_maint_all(data, operation);
return;
}
size = ALIGN(size, data->line_size);
while (size) {
unsigned long chunk_size = min_t(unsigned long, size,
data->range_op_max_size);
__uniphier_cache_maint_common(data, start, chunk_size,
UNIPHIER_SSCOQM_S_RANGE | operation);
start += chunk_size;
size -= chunk_size;
}
__uniphier_cache_sync(data);
}
static void __uniphier_cache_enable(struct uniphier_cache_data *data, bool on)
{
u32 val = 0;
if (on)
val = UNIPHIER_SSCC_WTG | UNIPHIER_SSCC_PRD | UNIPHIER_SSCC_ON;
writel_relaxed(val, data->ctrl_base + UNIPHIER_SSCC);
}
static void __init __uniphier_cache_set_active_ways(
struct uniphier_cache_data *data)
{
unsigned int cpu;
for_each_possible_cpu(cpu)
writel_relaxed(data->way_mask, data->way_ctrl_base + 4 * cpu);
}
static void uniphier_cache_maint_range(unsigned long start, unsigned long end,
u32 operation)
{
struct uniphier_cache_data *data;
list_for_each_entry(data, &uniphier_cache_list, list)
__uniphier_cache_maint_range(data, start, end, operation);
}
static void uniphier_cache_maint_all(u32 operation)
{
struct uniphier_cache_data *data;
list_for_each_entry(data, &uniphier_cache_list, list)
__uniphier_cache_maint_all(data, operation);
}
static void uniphier_cache_inv_range(unsigned long start, unsigned long end)
{
uniphier_cache_maint_range(start, end, UNIPHIER_SSCOQM_CM_INV);
}
static void uniphier_cache_clean_range(unsigned long start, unsigned long end)
{
uniphier_cache_maint_range(start, end, UNIPHIER_SSCOQM_CM_CLEAN);
}
static void uniphier_cache_flush_range(unsigned long start, unsigned long end)
{
uniphier_cache_maint_range(start, end, UNIPHIER_SSCOQM_CM_FLUSH);
}
static void __init uniphier_cache_inv_all(void)
{
uniphier_cache_maint_all(UNIPHIER_SSCOQM_CM_INV);
}
static void uniphier_cache_flush_all(void)
{
uniphier_cache_maint_all(UNIPHIER_SSCOQM_CM_FLUSH);
}
static void uniphier_cache_disable(void)
{
struct uniphier_cache_data *data;
list_for_each_entry_reverse(data, &uniphier_cache_list, list)
__uniphier_cache_enable(data, false);
uniphier_cache_flush_all();
}
static void __init uniphier_cache_enable(void)
{
struct uniphier_cache_data *data;
uniphier_cache_inv_all();
list_for_each_entry(data, &uniphier_cache_list, list) {
__uniphier_cache_enable(data, true);
__uniphier_cache_set_active_ways(data);
}
}
static void uniphier_cache_sync(void)
{
struct uniphier_cache_data *data;
list_for_each_entry(data, &uniphier_cache_list, list)
__uniphier_cache_sync(data);
}
static int __init __uniphier_cache_init(struct device_node *np,
unsigned int *cache_level)
{
struct uniphier_cache_data *data;
u32 level, cache_size;
struct device_node *next_np;
int ret = 0;
if (!of_match_node(uniphier_cache_match, np)) {
pr_err("L%d: not compatible with uniphier cache\n",
*cache_level);
return -EINVAL;
}
if (of_property_read_u32(np, "cache-level", &level)) {
pr_err("L%d: cache-level is not specified\n", *cache_level);
return -EINVAL;
}
if (level != *cache_level) {
pr_err("L%d: cache-level is unexpected value %d\n",
*cache_level, level);
return -EINVAL;
}
if (!of_property_read_bool(np, "cache-unified")) {
pr_err("L%d: cache-unified is not specified\n", *cache_level);
return -EINVAL;
}
data = kzalloc(sizeof(*data), GFP_KERNEL);
if (!data)
return -ENOMEM;
if (of_property_read_u32(np, "cache-line-size", &data->line_size) ||
!is_power_of_2(data->line_size)) {
pr_err("L%d: cache-line-size is unspecified or invalid\n",
*cache_level);
ret = -EINVAL;
goto err;
}
if (of_property_read_u32(np, "cache-sets", &data->nsets) ||
!is_power_of_2(data->nsets)) {
pr_err("L%d: cache-sets is unspecified or invalid\n",
*cache_level);
ret = -EINVAL;
goto err;
}
if (of_property_read_u32(np, "cache-size", &cache_size) ||
cache_size == 0 || cache_size % (data->nsets * data->line_size)) {
pr_err("L%d: cache-size is unspecified or invalid\n",
*cache_level);
ret = -EINVAL;
goto err;
}
data->way_mask = GENMASK(cache_size / data->nsets / data->line_size - 1,
0);
data->ctrl_base = of_iomap(np, 0);
if (!data->ctrl_base) {
pr_err("L%d: failed to map control register\n", *cache_level);
ret = -ENOMEM;
goto err;
}
data->rev_base = of_iomap(np, 1);
if (!data->rev_base) {
pr_err("L%d: failed to map revision register\n", *cache_level);
ret = -ENOMEM;
goto err;
}
data->op_base = of_iomap(np, 2);
if (!data->op_base) {
pr_err("L%d: failed to map operation register\n", *cache_level);
ret = -ENOMEM;
goto err;
}
data->way_ctrl_base = data->ctrl_base + 0xc00;
if (*cache_level == 2) {
u32 revision = readl(data->rev_base + UNIPHIER_SSCID);
if (revision <= 0x16)
data->range_op_max_size = (u32)1 << 22;
switch (revision) {
case 0x11:
data->way_ctrl_base = data->ctrl_base + 0x870;
break;
case 0x12:
case 0x16:
data->way_ctrl_base = data->ctrl_base + 0x840;
break;
default:
break;
}
}
data->range_op_max_size -= data->line_size;
INIT_LIST_HEAD(&data->list);
list_add_tail(&data->list, &uniphier_cache_list);
next_np = of_find_next_cache_node(np);
if (next_np) {
(*cache_level)++;
ret = __uniphier_cache_init(next_np, cache_level);
}
of_node_put(next_np);
return ret;
err:
iounmap(data->op_base);
iounmap(data->rev_base);
iounmap(data->ctrl_base);
kfree(data);
return ret;
}
int __init uniphier_cache_init(void)
{
struct device_node *np = NULL;
unsigned int cache_level;
int ret = 0;
while ((np = of_find_matching_node(np, uniphier_cache_match)))
if (!of_property_read_u32(np, "cache-level", &cache_level) &&
cache_level == 2)
break;
if (!np)
return -ENODEV;
ret = __uniphier_cache_init(np, &cache_level);
of_node_put(np);
if (ret) {
if (cache_level == 2) {
pr_err("failed to initialize L2 cache\n");
return ret;
}
cache_level--;
ret = 0;
}
outer_cache.inv_range = uniphier_cache_inv_range;
outer_cache.clean_range = uniphier_cache_clean_range;
outer_cache.flush_range = uniphier_cache_flush_range;
outer_cache.flush_all = uniphier_cache_flush_all;
outer_cache.disable = uniphier_cache_disable;
outer_cache.sync = uniphier_cache_sync;
uniphier_cache_enable();
pr_info("enabled outer cache (cache level: %d)\n", cache_level);
return ret;
}
