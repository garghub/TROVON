static bool node_has_compatible(struct device_node *pp)
{
return of_get_property(pp, "compatible", NULL);
}
static int parse_ofpart_partitions(struct mtd_info *master,
struct mtd_partition **pparts,
struct mtd_part_parser_data *data)
{
struct device_node *mtd_node;
struct device_node *ofpart_node;
const char *partname;
struct device_node *pp;
int nr_parts, i, ret = 0;
bool dedicated = true;
if (!data)
return 0;
mtd_node = data->of_node;
if (!mtd_node)
return 0;
ofpart_node = of_get_child_by_name(mtd_node, "partitions");
if (!ofpart_node) {
pr_debug("%s: 'partitions' subnode not found on %s. Trying to parse direct subnodes as partitions.\n",
master->name, mtd_node->full_name);
ofpart_node = mtd_node;
dedicated = false;
} else if (!of_device_is_compatible(ofpart_node, "fixed-partitions")) {
return 0;
}
nr_parts = 0;
for_each_child_of_node(ofpart_node, pp) {
if (!dedicated && node_has_compatible(pp))
continue;
nr_parts++;
}
if (nr_parts == 0)
return 0;
*pparts = kzalloc(nr_parts * sizeof(**pparts), GFP_KERNEL);
if (!*pparts)
return -ENOMEM;
i = 0;
for_each_child_of_node(ofpart_node, pp) {
const __be32 *reg;
int len;
int a_cells, s_cells;
if (!dedicated && node_has_compatible(pp))
continue;
reg = of_get_property(pp, "reg", &len);
if (!reg) {
if (dedicated) {
pr_debug("%s: ofpart partition %s (%s) missing reg property.\n",
master->name, pp->full_name,
mtd_node->full_name);
goto ofpart_fail;
} else {
nr_parts--;
continue;
}
}
a_cells = of_n_addr_cells(pp);
s_cells = of_n_size_cells(pp);
if (len / 4 != a_cells + s_cells) {
pr_debug("%s: ofpart partition %s (%s) error parsing reg property.\n",
master->name, pp->full_name,
mtd_node->full_name);
goto ofpart_fail;
}
(*pparts)[i].offset = of_read_number(reg, a_cells);
(*pparts)[i].size = of_read_number(reg + a_cells, s_cells);
partname = of_get_property(pp, "label", &len);
if (!partname)
partname = of_get_property(pp, "name", &len);
(*pparts)[i].name = partname;
if (of_get_property(pp, "read-only", &len))
(*pparts)[i].mask_flags |= MTD_WRITEABLE;
if (of_get_property(pp, "lock", &len))
(*pparts)[i].mask_flags |= MTD_POWERUP_LOCK;
i++;
}
if (!nr_parts)
goto ofpart_none;
return nr_parts;
ofpart_fail:
pr_err("%s: error parsing ofpart partition %s (%s)\n",
master->name, pp->full_name, mtd_node->full_name);
ret = -EINVAL;
ofpart_none:
of_node_put(pp);
kfree(*pparts);
*pparts = NULL;
return ret;
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
(*pparts)[i].name = names;
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
register_mtd_parser(&ofpart_parser);
register_mtd_parser(&ofoldpart_parser);
return 0;
}
static void __exit ofpart_parser_exit(void)
{
deregister_mtd_parser(&ofpart_parser);
deregister_mtd_parser(&ofoldpart_parser);
}
