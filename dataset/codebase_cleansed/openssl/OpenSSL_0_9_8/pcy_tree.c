static int tree_link_nodes(X509_POLICY_LEVEL *curr,
const X509_POLICY_CACHE *cache)
{
int i;
X509_POLICY_LEVEL *last;
X509_POLICY_DATA *data;
X509_POLICY_NODE *parent;
last = curr - 1;
for (i = 0; i < sk_X509_POLICY_DATA_num(cache->data); i++)
{
data = sk_X509_POLICY_DATA_value(cache->data, i);
if ((data->flags & POLICY_DATA_FLAG_MAPPED_ANY)
&& !(curr->flags & X509_V_FLAG_INHIBIT_ANY))
continue;
parent = level_find_node(last, data->valid_policy);
if (!parent)
parent = last->anyPolicy;
if (parent && !level_add_node(curr, data, parent, NULL))
return 0;
}
return 1;
}
static int tree_link_any(X509_POLICY_LEVEL *curr,
const X509_POLICY_CACHE *cache,
X509_POLICY_TREE *tree)
{
int i;
X509_POLICY_DATA *data;
X509_POLICY_NODE *node;
X509_POLICY_LEVEL *last;
last = curr - 1;
for (i = 0; i < sk_X509_POLICY_NODE_num(last->nodes); i++)
{
node = sk_X509_POLICY_NODE_value(last->nodes, i);
if (node->nchild)
continue;
data = policy_data_new(NULL, node->data->valid_policy,
node_critical(node));
if (data == NULL)
return 0;
data->qualifier_set = curr->anyPolicy->data->qualifier_set;
data->flags |= POLICY_DATA_FLAG_SHARED_QUALIFIERS;
if (!level_add_node(curr, data, node, tree))
{
policy_data_free(data);
return 0;
}
}
if (last->anyPolicy)
{
if (!level_add_node(curr, cache->anyPolicy,
last->anyPolicy, NULL))
return 0;
}
return 1;
}
static int tree_prune(X509_POLICY_TREE *tree, X509_POLICY_LEVEL *curr)
{
X509_POLICY_NODE *node;
int i;
for (i = sk_X509_POLICY_NODE_num(curr->nodes) - 1; i >= 0; i--)
{
node = sk_X509_POLICY_NODE_value(curr->nodes, i);
if (node->data->flags & POLICY_DATA_FLAG_MAP_MASK)
{
node->parent->nchild--;
OPENSSL_free(node);
sk_X509_POLICY_NODE_delete(curr->nodes, i);
}
}
for(;;) {
--curr;
for (i = sk_X509_POLICY_NODE_num(curr->nodes) - 1; i >= 0; i--)
{
node = sk_X509_POLICY_NODE_value(curr->nodes, i);
if (node->nchild == 0)
{
node->parent->nchild--;
OPENSSL_free(node);
sk_X509_POLICY_NODE_delete(curr->nodes, i);
}
}
if (curr->anyPolicy && !curr->anyPolicy->nchild)
{
if (curr->anyPolicy->parent)
curr->anyPolicy->parent->nchild--;
OPENSSL_free(curr->anyPolicy);
curr->anyPolicy = NULL;
}
if (curr == tree->levels)
{
if (!curr->anyPolicy)
return 2;
return 1;
}
}
return 1;
}
static int tree_evaluate(X509_POLICY_TREE *tree)
{
int ret, i;
X509_POLICY_LEVEL *curr = tree->levels + 1;
const X509_POLICY_CACHE *cache;
for(i = 1; i < tree->nlevel; i++, curr++)
{
cache = policy_cache_set(curr->cert);
if (!tree_link_nodes(curr, cache))
return 0;
if (!(curr->flags & X509_V_FLAG_INHIBIT_ANY)
&& !tree_link_any(curr, cache, tree))
return 0;
ret = tree_prune(tree, curr);
if (ret != 1)
return ret;
}
return 1;
}
static void exnode_free(X509_POLICY_NODE *node)
{
if (node->data && (node->data->flags & POLICY_DATA_FLAG_EXTRA_NODE))
OPENSSL_free(node);
}
void X509_policy_tree_free(X509_POLICY_TREE *tree)
{
X509_POLICY_LEVEL *curr;
int i;
if (!tree)
return;
sk_X509_POLICY_NODE_free(tree->auth_policies);
sk_X509_POLICY_NODE_pop_free(tree->user_policies, exnode_free);
for(i = 0, curr = tree->levels; i < tree->nlevel; i++, curr++)
{
if (curr->cert)
X509_free(curr->cert);
if (curr->nodes)
sk_X509_POLICY_NODE_pop_free(curr->nodes,
policy_node_free);
if (curr->anyPolicy)
policy_node_free(curr->anyPolicy);
}
if (tree->extra_data)
sk_X509_POLICY_DATA_pop_free(tree->extra_data,
policy_data_free);
OPENSSL_free(tree->levels);
OPENSSL_free(tree);
}
