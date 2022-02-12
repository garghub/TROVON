static int __init sirfsoc_l2x0_init(void)
{
struct device_node *np;
const struct l2x0_aux *aux;
np = of_find_matching_node(NULL, sirf_l2x0_ids);
if (np) {
aux = of_match_node(sirf_l2x0_ids, np)->data;
return l2x0_of_init(aux->val, aux->mask);
}
return 0;
}
