static void expected_print(BIO *err, X509_POLICY_LEVEL *lev,
X509_POLICY_NODE *node, int indent)
{
if ( (lev->flags & X509_V_FLAG_INHIBIT_MAP)
|| !(node->data->flags & POLICY_DATA_FLAG_MAP_MASK))
BIO_puts(err, " Not Mapped\n");
else
{
int i;
STACK_OF(ASN1_OBJECT) *pset = node->data->expected_policy_set;
ASN1_OBJECT *oid;
BIO_puts(err, " Expected: ");
for (i = 0; i < sk_ASN1_OBJECT_num(pset); i++)
{
oid = sk_ASN1_OBJECT_value(pset, i);
if (i)
BIO_puts(err, ", ");
i2a_ASN1_OBJECT(err, oid);
}
BIO_puts(err, "\n");
}
}
static void tree_print(char *str, X509_POLICY_TREE *tree,
X509_POLICY_LEVEL *curr)
{
X509_POLICY_LEVEL *plev;
X509_POLICY_NODE *node;
int i;
BIO *err;
err = BIO_new_fp(stderr, BIO_NOCLOSE);
if (!curr)
curr = tree->levels + tree->nlevel;
else
curr++;
BIO_printf(err, "Level print after %s\n", str);
BIO_printf(err, "Printing Up to Level %ld\n", curr - tree->levels);
for (plev = tree->levels; plev != curr; plev++)
{
BIO_printf(err, "Level %ld, flags = %x\n",
plev - tree->levels, plev->flags);
for (i = 0; i < sk_X509_POLICY_NODE_num(plev->nodes); i++)
{
node = sk_X509_POLICY_NODE_value(plev->nodes, i);
X509_POLICY_NODE_print(err, node, 2);
expected_print(err, plev, node, 2);
BIO_printf(err, " Flags: %x\n", node->data->flags);
}
if (plev->anyPolicy)
X509_POLICY_NODE_print(err, plev->anyPolicy, 2);
}
BIO_free(err);
}
static int tree_link_matching_nodes(X509_POLICY_LEVEL *curr,
const X509_POLICY_DATA *data)
{
X509_POLICY_LEVEL *last = curr - 1;
X509_POLICY_NODE *node;
int i, matched = 0;
for (i = 0; i < sk_X509_POLICY_NODE_num(last->nodes); i++)
{
node = sk_X509_POLICY_NODE_value(last->nodes, i);
if (policy_node_match(last, node, data->valid_policy))
{
if (!level_add_node(curr, data, node, NULL))
return 0;
matched = 1;
}
}
if (!matched && last->anyPolicy)
{
if (!level_add_node(curr, data, last->anyPolicy, NULL))
return 0;
}
return 1;
}
static int tree_link_nodes(X509_POLICY_LEVEL *curr,
const X509_POLICY_CACHE *cache)
{
int i;
X509_POLICY_DATA *data;
for (i = 0; i < sk_X509_POLICY_DATA_num(cache->data); i++)
{
data = sk_X509_POLICY_DATA_value(cache->data, i);
#if 0
if ((data->flags & POLICY_DATA_FLAG_MAPPED_ANY)
&& !(curr->flags & X509_V_FLAG_INHIBIT_ANY))
continue;
#endif
if (!tree_link_matching_nodes(curr, data))
return 0;
}
return 1;
}
static int tree_add_unmatched(X509_POLICY_LEVEL *curr,
const X509_POLICY_CACHE *cache,
const ASN1_OBJECT *id,
X509_POLICY_NODE *node,
X509_POLICY_TREE *tree)
{
X509_POLICY_DATA *data;
if (id == NULL)
id = node->data->valid_policy;
data = policy_data_new(NULL, id, node_critical(node));
if (data == NULL)
return 0;
data->qualifier_set = cache->anyPolicy->qualifier_set;
data->flags |= POLICY_DATA_FLAG_SHARED_QUALIFIERS;
if (!level_add_node(curr, data, node, tree))
{
policy_data_free(data);
return 0;
}
return 1;
}
static int tree_link_unmatched(X509_POLICY_LEVEL *curr,
const X509_POLICY_CACHE *cache,
X509_POLICY_NODE *node,
X509_POLICY_TREE *tree)
{
const X509_POLICY_LEVEL *last = curr - 1;
int i;
if ( (last->flags & X509_V_FLAG_INHIBIT_MAP)
|| !(node->data->flags & POLICY_DATA_FLAG_MAPPED))
{
if (node->nchild)
return 1;
if (!tree_add_unmatched(curr, cache, NULL, node, tree))
return 0;
}
else
{
STACK_OF(ASN1_OBJECT) *expset = node->data->expected_policy_set;
if (node->nchild == sk_ASN1_OBJECT_num(expset))
return 1;
for (i = 0; i < sk_ASN1_OBJECT_num(expset); i++)
{
ASN1_OBJECT *oid = sk_ASN1_OBJECT_value(expset, i);
if (level_find_node(curr, node, oid))
continue;
if (!tree_add_unmatched(curr, cache, oid, node, tree))
return 0;
}
}
return 1;
}
static int tree_link_any(X509_POLICY_LEVEL *curr,
const X509_POLICY_CACHE *cache,
X509_POLICY_TREE *tree)
{
int i;
X509_POLICY_NODE *node;
X509_POLICY_LEVEL *last = curr - 1;
for (i = 0; i < sk_X509_POLICY_NODE_num(last->nodes); i++)
{
node = sk_X509_POLICY_NODE_value(last->nodes, i);
if (!tree_link_unmatched(curr, cache, node, tree))
return 0;
#if 0
if (node->nchild)
continue;
data = policy_data_new(NULL, node->data->valid_policy,
node_critical(node));
if (data == NULL)
return 0;
data->qualifier_set = cache->anyPolicy->qualifier_set;
data->flags |= POLICY_DATA_FLAG_SHARED_QUALIFIERS;
if (!level_add_node(curr, data, node, tree))
{
policy_data_free(data);
return 0;
}
#endif
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
STACK_OF(X509_POLICY_NODE) *nodes;
X509_POLICY_NODE *node;
int i;
nodes = curr->nodes;
if (curr->flags & X509_V_FLAG_INHIBIT_MAP)
{
for (i = sk_X509_POLICY_NODE_num(nodes) - 1; i >= 0; i--)
{
node = sk_X509_POLICY_NODE_value(nodes, i);
if (node->data->flags & POLICY_DATA_FLAG_MAP_MASK)
{
node->parent->nchild--;
OPENSSL_free(node);
(void)sk_X509_POLICY_NODE_delete(nodes,i);
}
}
}
for(;;) {
--curr;
nodes = curr->nodes;
for (i = sk_X509_POLICY_NODE_num(nodes) - 1; i >= 0; i--)
{
node = sk_X509_POLICY_NODE_value(nodes, i);
if (node->nchild == 0)
{
node->parent->nchild--;
OPENSSL_free(node);
(void)sk_X509_POLICY_NODE_delete(nodes, i);
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
tree_print("before tree_prune()", tree, curr);
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
