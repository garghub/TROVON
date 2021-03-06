int
gct6_find_nodes(gct6_node *node, gct6_search_struct *search)
{
gct6_search_struct *wanted;
int status = 0;
if (node->magic != GCT_NODE_MAGIC) {
printk(KERN_ERR "GCT Node MAGIC incorrect - GCT invalid\n");
return -EINVAL;
}
for (wanted = search;
wanted && (wanted->type | wanted->subtype);
wanted++) {
if (node->type != wanted->type)
continue;
if (node->subtype != wanted->subtype)
continue;
if (wanted->callout)
wanted->callout(node);
}
if (node->next)
status |= gct6_find_nodes(GCT_NODE_PTR(node->next), search);
if (node->child)
status |= gct6_find_nodes(GCT_NODE_PTR(node->child), search);
return status;
}
