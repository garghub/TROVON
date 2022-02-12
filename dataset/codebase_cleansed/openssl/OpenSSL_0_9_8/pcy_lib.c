int X509_policy_tree_level_count(const X509_POLICY_TREE *tree)
{
if (!tree)
return 0;
return tree->nlevel;
}
X509_POLICY_LEVEL *
X509_policy_tree_get0_level(const X509_POLICY_TREE *tree, int i)
{
if (!tree || (i < 0) || (i >= tree->nlevel))
return NULL;
return tree->levels + i;
}
X509_POLICY_NODE *X509_policy_level_get0_node(X509_POLICY_LEVEL *level, int i)
{
if (!level)
return NULL;
if (level->anyPolicy)
{
if (i == 0)
return level->anyPolicy;
i--;
}
return sk_X509_POLICY_NODE_value(level->nodes, i);
}
const ASN1_OBJECT *X509_policy_node_get0_policy(const X509_POLICY_NODE *node)
{
if (!node)
return NULL;
return node->data->valid_policy;
}
X509_POLICY_NODE *
X509_policy_node_get0_parent(const X509_POLICY_NODE *node)
{
if (!node)
return NULL;
return node->parent;
}
