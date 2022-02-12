static int node_cmp(const X509_POLICY_NODE *const *a,
const X509_POLICY_NODE *const *b)
{
return OBJ_cmp((*a)->data->valid_policy, (*b)->data->valid_policy);
}
X509_POLICY_NODE *level_find_node(const X509_POLICY_LEVEL *level,
const X509_POLICY_NODE *parent,
const ASN1_OBJECT *id)
{
X509_POLICY_NODE *node;
int i;
for (i = 0; i < sk_X509_POLICY_NODE_num(level->nodes); i++) {
node = sk_X509_POLICY_NODE_value(level->nodes, i);
if (node->parent == parent) {
if (!OBJ_cmp(node->data->valid_policy, id))
return node;
}
}
return NULL;
}
X509_POLICY_NODE *level_add_node(X509_POLICY_LEVEL *level,
const X509_POLICY_DATA *data,
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
if (level) {
if (OBJ_obj2nid(data->valid_policy) == NID_any_policy) {
if (level->anyPolicy)
goto node_error;
level->anyPolicy = node;
} else {
if (!level->nodes)
level->nodes = policy_node_cmp_new();
if (!level->nodes)
goto node_error;
if (!sk_X509_POLICY_NODE_push(level->nodes, node))
goto node_error;
}
}
if (tree) {
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
int policy_node_match(const X509_POLICY_LEVEL *lvl,
const X509_POLICY_NODE *node, const ASN1_OBJECT *oid)
{
int i;
ASN1_OBJECT *policy_oid;
const X509_POLICY_DATA *x = node->data;
if ((lvl->flags & X509_V_FLAG_INHIBIT_MAP)
|| !(x->flags & POLICY_DATA_FLAG_MAP_MASK)) {
if (!OBJ_cmp(x->valid_policy, oid))
return 1;
return 0;
}
for (i = 0; i < sk_ASN1_OBJECT_num(x->expected_policy_set); i++) {
policy_oid = sk_ASN1_OBJECT_value(x->expected_policy_set, i);
if (!OBJ_cmp(policy_oid, oid))
return 1;
}
return 0;
}
