static int __init sirfsoc_l2x0_init(void)
{
struct device_node *np;
np = of_find_matching_node(NULL, prima2_l2x0_ids);
if (np) {
pr_info("Initializing prima2 L2 cache\n");
return l2x0_of_init(0x40000, 0);
}
return 0;
}
