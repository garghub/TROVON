static int parse_ofpart_partitions(struct mtd_info *master,
struct mtd_partition **pparts,
struct mtd_part_parser_data *data)
{
struct device_node *node;
const char *partname;
struct device_node *pp;
int nr_parts, i;
if (!data)
return 0;
node = data->of_node;
if (!node)
return 0;
pp = NULL;
nr_parts = 0;
while ((pp = of_get_next_child(node, pp)))
nr_parts++;
if (nr_parts == 0)
return 0;
*pparts = kzalloc(nr_parts * sizeof(**pparts), GFP_KERNEL);
if (!*pparts)
return -ENOMEM;
pp = NULL;
i = 0;
while ((pp = of_get_next_child(node, pp))) {
const __be32 *reg;
int len;
int a_cells, s_cells;
reg = of_get_property(pp, "reg", &len);
if (!reg) {
nr_parts--;
continue;
}
a_cells = of_n_addr_cells(pp);
s_cells = of_n_size_cells(pp);
(*pparts)[i].offset = of_read_number(reg, a_cells);
(*pparts)[i].size = of_read_number(reg + a_cells, s_cells);
partname = of_get_property(pp, "label", &len);
if (!partname)
partname = of_get_property(pp, "name", &len);
(*pparts)[i].name = (char *)partname;
if (of_get_property(pp, "read-only", &len))
(*pparts)[i].mask_flags |= MTD_WRITEABLE;
if (of_get_property(pp, "lock", &len))
(*pparts)[i].mask_flags |= MTD_POWERUP_LOCK;
i++;
}
if (!i) {
of_node_put(pp);
pr_err("No valid partition found on %s\n", node->full_name);
kfree(*pparts);
*pparts = NULL;
return -EINVAL;
}
return nr_parts;
}
static int parse_ofoldpart_partitions(struct mtd_info *master,
struct mtd_partition **pparts,
struct mtd_part_parser_data *data)
{
struct device_node *dp;
int i, plen, nr_parts;
const struct {
__be32 offset, len;
} *part;
const char *names;
if (!data)
return 0;
dp = data->of_node;
if (!dp)
return 0;
part = of_get_property(dp, "partitions", &plen);
if (!part)
return 0;
pr_warning("Device tree uses obsolete partition map binding: %s\n",
dp->full_name);
nr_parts = plen / sizeof(part[0]);
*pparts = kzalloc(nr_parts * sizeof(*(*pparts)), GFP_KERNEL);
if (!*pparts)
return -ENOMEM;
names = of_get_property(dp, "partition-names", &plen);
for (i = 0; i < nr_parts; i++) {
(*pparts)[i].offset = be32_to_cpu(part->offset);
(*pparts)[i].size = be32_to_cpu(part->len) & ~1;
if (be32_to_cpu(part->len) & 1)
(*pparts)[i].mask_flags = MTD_WRITEABLE;
if (names && (plen > 0)) {
int len = strlen(names) + 1;
(*pparts)[i].name = (char *)names;
plen -= len;
names += len;
} else {
(*pparts)[i].name = "unnamed";
}
part++;
}
return nr_parts;
}
static int __init ofpart_parser_init(void)
{
int rc;
rc = register_mtd_parser(&ofpart_parser);
if (rc)
goto out;
rc = register_mtd_parser(&ofoldpart_parser);
if (!rc)
return 0;
deregister_mtd_parser(&ofoldpart_parser);
out:
return rc;
}
static void __exit ofpart_parser_exit(void)
{
deregister_mtd_parser(&ofpart_parser);
deregister_mtd_parser(&ofoldpart_parser);
}
