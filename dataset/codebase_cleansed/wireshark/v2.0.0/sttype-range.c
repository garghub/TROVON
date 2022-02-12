static gpointer
range_new(gpointer junk)
{
range_t *range;
g_assert(junk == NULL);
range = g_new(range_t, 1);
range->magic = RANGE_MAGIC;
range->entity = NULL;
range->drange = NULL;
return (gpointer) range;
}
static gpointer
range_dup(gconstpointer data)
{
const range_t *org = (const range_t *)data;
range_t *range;
range = (range_t *)range_new(NULL);
range->entity = stnode_dup(org->entity);
range->drange = drange_dup(org->drange);
return (gpointer) range;
}
static void
range_free(gpointer value)
{
range_t *range = (range_t*)value;
assert_magic(range, RANGE_MAGIC);
if (range->drange)
drange_free(range->drange);
if (range->entity)
stnode_free(range->entity);
g_free(range);
}
void
sttype_range_remove_drange(stnode_t *node)
{
range_t *range;
range = (range_t*)stnode_data(node);
assert_magic(range, RANGE_MAGIC);
range->drange = NULL;
}
void
sttype_range_set(stnode_t *node, stnode_t *entity, GSList* drange_list)
{
range_t *range;
range = (range_t*)stnode_data(node);
assert_magic(range, RANGE_MAGIC);
range->entity = entity;
range->drange = drange_new_from_list(drange_list);
}
void
sttype_range_set1(stnode_t *node, stnode_t *entity, drange_node *rn)
{
sttype_range_set(node, entity, g_slist_append(NULL, rn));
}
void
sttype_register_range(void)
{
static sttype_t range_type = {
STTYPE_RANGE,
"RANGE",
range_new,
range_free,
range_dup
};
sttype_register(&range_type);
}
