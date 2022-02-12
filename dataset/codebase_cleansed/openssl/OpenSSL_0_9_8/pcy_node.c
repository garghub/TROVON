static int node_cmp(const X509_POLICY_NODE * const *a,
const X509_POLICY_NODE * const *b)
{
return OBJ_cmp((*a)->data->valid_policy, (*b)->data->valid_policy);
}
X509_POLICY_NODE *level_find_node(const X509_POLICY_LEVEL *level,
const ASN1_OBJECT *id)
{
return tree_find_sk(level->nodes, id);
}
X509_POLICY_NODE *level_add_node(X509_POLICY_LEVEL *level,
X509_POLICY_DATA *data,
X509_POLICY_NODE *parent,
X509_POLICY_TREE *tree)
{
X509_POLICY_NODE *node;
node = OPENSSL_malloc(sizeof(X509_POLICY_NODE));
if (!node)
return NULL;
node->data = data;
node->parent = parent;
node->nchild = 0;
if (level)
{
if (OBJ_obj2nid(data->valid_policy) == NID_any_policy)
{
if (level->anyPolicy)
goto node_error;
level->anyPolicy = node;
}
else
{
if (!level->nodes)
level->nodes = policy_node_cmp_new();
if (!level->nodes)
goto node_error;
if (!sk_X509_POLICY_NODE_push(level->nodes, node))
goto node_error;
}
}
if (tree)
{
if (!tree->extra_data)
tree->extra_data = sk_X509_POLICY_DATA_new_null();
if (!tree->extra_data)
goto node_error;
if (!sk_X509_POLICY_DATA_push(tree->extra_data, data))
goto node_error;
}
if (parent)
parent->nchild++;
return node;
node_error:
policy_node_free(node);
return 0;
}
void policy_node_free(X509_POLICY_NODE *node)
{
OPENSSL_free(node);
}
