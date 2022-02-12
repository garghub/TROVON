static int __init s3c_nand_copy_set(struct s3c2410_nand_set *set)
{
void *ptr;
int size;
size = sizeof(struct mtd_partition) * set->nr_partitions;
if (size) {
ptr = kmemdup(set->partitions, size, GFP_KERNEL);
set->partitions = ptr;
if (!ptr)
return -ENOMEM;
}
if (set->nr_map && set->nr_chips) {
size = sizeof(int) * set->nr_chips;
ptr = kmemdup(set->nr_map, size, GFP_KERNEL);
set->nr_map = ptr;
if (!ptr)
return -ENOMEM;
}
if (set->ecc_layout) {
ptr = kmemdup(set->ecc_layout,
sizeof(struct nand_ecclayout), GFP_KERNEL);
set->ecc_layout = ptr;
if (!ptr)
return -ENOMEM;
}
return 0;
}
void __init s3c_nand_set_platdata(struct s3c2410_platform_nand *nand)
{
struct s3c2410_platform_nand *npd;
int size;
int ret;
npd = kmemdup(nand, sizeof(struct s3c2410_platform_nand), GFP_KERNEL);
if (!npd) {
printk(KERN_ERR "%s: failed copying platform data\n", __func__);
return;
}
size = sizeof(struct s3c2410_nand_set) * npd->nr_sets;
if (size) {
struct s3c2410_nand_set *from = npd->sets;
struct s3c2410_nand_set *to;
int i;
to = kmemdup(from, size, GFP_KERNEL);
npd->sets = to;
if (!to) {
printk(KERN_ERR "%s: no memory for sets\n", __func__);
return;
}
for (i = 0; i < npd->nr_sets; i++) {
ret = s3c_nand_copy_set(to);
if (ret) {
printk(KERN_ERR "%s: failed to copy set %d\n",
__func__, i);
return;
}
to++;
}
}
s3c_device_nand.dev.platform_data = npd;
}
