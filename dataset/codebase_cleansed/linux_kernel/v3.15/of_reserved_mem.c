int __init __weak early_init_dt_alloc_reserved_memory_arch(phys_addr_t size,
phys_addr_t align, phys_addr_t start, phys_addr_t end, bool nomap,
phys_addr_t *res_base)
{
phys_addr_t base = __memblock_alloc_base(size, align, end);
if (!base)
return -ENOMEM;
if (base < start) {
memblock_free(base, size);
return -ENOMEM;
}
*res_base = base;
if (nomap)
return memblock_remove(base, size);
return 0;
}
int __init __weak early_init_dt_alloc_reserved_memory_arch(phys_addr_t size,
phys_addr_t align, phys_addr_t start, phys_addr_t end, bool nomap,
phys_addr_t *res_base)
{
pr_err("Reserved memory not supported, ignoring region 0x%llx%s\n",
size, nomap ? " (nomap)" : "");
return -ENOSYS;
}
void __init fdt_reserved_mem_save_node(unsigned long node, const char *uname,
phys_addr_t base, phys_addr_t size)
{
struct reserved_mem *rmem = &reserved_mem[reserved_mem_count];
if (reserved_mem_count == ARRAY_SIZE(reserved_mem)) {
pr_err("Reserved memory: not enough space all defined regions.\n");
return;
}
rmem->fdt_node = node;
rmem->name = uname;
rmem->base = base;
rmem->size = size;
reserved_mem_count++;
return;
}
static int __init __reserved_mem_alloc_size(unsigned long node,
const char *uname, phys_addr_t *res_base, phys_addr_t *res_size)
{
int t_len = (dt_root_addr_cells + dt_root_size_cells) * sizeof(__be32);
phys_addr_t start = 0, end = 0;
phys_addr_t base = 0, align = 0, size;
unsigned long len;
__be32 *prop;
int nomap;
int ret;
prop = of_get_flat_dt_prop(node, "size", &len);
if (!prop)
return -EINVAL;
if (len != dt_root_size_cells * sizeof(__be32)) {
pr_err("Reserved memory: invalid size property in '%s' node.\n",
uname);
return -EINVAL;
}
size = dt_mem_next_cell(dt_root_size_cells, &prop);
nomap = of_get_flat_dt_prop(node, "no-map", NULL) != NULL;
prop = of_get_flat_dt_prop(node, "alignment", &len);
if (prop) {
if (len != dt_root_addr_cells * sizeof(__be32)) {
pr_err("Reserved memory: invalid alignment property in '%s' node.\n",
uname);
return -EINVAL;
}
align = dt_mem_next_cell(dt_root_addr_cells, &prop);
}
prop = of_get_flat_dt_prop(node, "alloc-ranges", &len);
if (prop) {
if (len % t_len != 0) {
pr_err("Reserved memory: invalid alloc-ranges property in '%s', skipping node.\n",
uname);
return -EINVAL;
}
base = 0;
while (len > 0) {
start = dt_mem_next_cell(dt_root_addr_cells, &prop);
end = start + dt_mem_next_cell(dt_root_size_cells,
&prop);
ret = early_init_dt_alloc_reserved_memory_arch(size,
align, start, end, nomap, &base);
if (ret == 0) {
pr_debug("Reserved memory: allocated memory for '%s' node: base %pa, size %ld MiB\n",
uname, &base,
(unsigned long)size / SZ_1M);
break;
}
len -= t_len;
}
} else {
ret = early_init_dt_alloc_reserved_memory_arch(size, align,
0, 0, nomap, &base);
if (ret == 0)
pr_debug("Reserved memory: allocated memory for '%s' node: base %pa, size %ld MiB\n",
uname, &base, (unsigned long)size / SZ_1M);
}
if (base == 0) {
pr_info("Reserved memory: failed to allocate memory for node '%s'\n",
uname);
return -ENOMEM;
}
*res_base = base;
*res_size = size;
return 0;
}
static int __init __reserved_mem_init_node(struct reserved_mem *rmem)
{
extern const struct of_device_id __reservedmem_of_table[];
const struct of_device_id *i;
for (i = __reservedmem_of_table; i < &__rmem_of_table_sentinel; i++) {
reservedmem_of_init_fn initfn = i->data;
const char *compat = i->compatible;
if (!of_flat_dt_is_compatible(rmem->fdt_node, compat))
continue;
if (initfn(rmem, rmem->fdt_node, rmem->name) == 0) {
pr_info("Reserved memory: initialized node %s, compatible id %s\n",
rmem->name, compat);
return 0;
}
}
return -ENOENT;
}
void __init fdt_init_reserved_mem(void)
{
int i;
for (i = 0; i < reserved_mem_count; i++) {
struct reserved_mem *rmem = &reserved_mem[i];
unsigned long node = rmem->fdt_node;
int err = 0;
if (rmem->size == 0)
err = __reserved_mem_alloc_size(node, rmem->name,
&rmem->base, &rmem->size);
if (err == 0)
__reserved_mem_init_node(rmem);
}
}
