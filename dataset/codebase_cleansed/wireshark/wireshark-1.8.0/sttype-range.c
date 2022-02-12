static gpointer
range_new(gpointer junk)
{
range_t *range;
g_assert(junk == NULL);
range = g_new(range_t, 1);
range->magic = RANGE_MAGIC;
range->hfinfo = NULL;
range->drange = NULL;
return (gpointer) range;
}
static void
range_free(gpointer value)
{
range_t *range = (range_t*)value;
assert_magic(range, RANGE_MAGIC);
if (range->drange)
drange_free(range->drange);
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
sttype_range_set(stnode_t *node, stnode_t *field, GSList* drange_list)
{
range_t *range;
range = (range_t*)stnode_data(node);
assert_magic(range, RANGE_MAGIC);
range->hfinfo = (header_field_info *)stnode_data(field);
stnode_free(field);
range->drange = drange_new_from_list(drange_list);
}
void
sttype_range_set1(stnode_t *node, stnode_t *field, drange_node *rn)
{
sttype_range_set(node, field, g_slist_append(NULL, rn));
}
void
sttype_register_range(void)
{
static sttype_t range_type = {
STTYPE_RANGE,
"RANGE",
range_new,
range_free,
};
sttype_register(&range_type);
}
