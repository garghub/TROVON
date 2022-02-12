int extract_uint(proto_tree *tree, int field_id, guint32 *result_array, size_t *element_count)
{
GPtrArray *finfo_array;
*element_count = 0;
if (tree == NULL) {
return -1;
}
finfo_array = proto_get_finfo_ptr_array(tree, field_id);
if (finfo_array == NULL) {
return -1;
}
*element_count = g_ptr_array_len(finfo_array);
for (size_t i = 0; i < *element_count && i < MAX_RETURNED_ELEMENTS; i++)
{
result_array[i] = fvalue_get_uinteger(&((field_info*)finfo_array->pdata[i])->value);
}
return 0;
}
int extract_ui64(proto_tree *tree, int field_id, guint64 *result_array, size_t *element_count)
{
GPtrArray *finfo_array;
*element_count = 0;
if (tree == NULL) {
return -1;
}
finfo_array = proto_get_finfo_ptr_array(tree, field_id);
if (finfo_array == NULL) {
return -1;
}
*element_count = g_ptr_array_len(finfo_array);
for (size_t i = 0; i < *element_count && i < MAX_RETURNED_ELEMENTS; i++)
{
result_array[i] = fvalue_get_uinteger64(&((field_info*)finfo_array->pdata[i])->value);
}
return 0;
}
int extract_si64(proto_tree *tree, int field_id, guint64 *result_array, size_t *element_count)
{
GPtrArray *finfo_array;
*element_count = 0;
if (tree == NULL) {
return -1;
}
finfo_array = proto_get_finfo_ptr_array(tree, field_id);
if (finfo_array == NULL) {
return -1;
}
*element_count = g_ptr_array_len(finfo_array);
for (size_t i = 0; i < *element_count && i < MAX_RETURNED_ELEMENTS; i++)
{
result_array[i] = fvalue_get_sinteger64(&((field_info*)finfo_array->pdata[i])->value);
}
return 0;
}
int extract_bool(proto_tree *tree, int field_id, gboolean *result_array, size_t *element_count)
{
GPtrArray *finfo_array;
*element_count = 0;
if (tree == NULL) {
return -1;
}
finfo_array = proto_get_finfo_ptr_array(tree, field_id);
if (finfo_array == NULL) {
return -1;
}
*element_count = g_ptr_array_len(finfo_array);
for (size_t i = 0; i < *element_count && i < MAX_RETURNED_ELEMENTS; i++)
{
fvalue_t *fv = &(((field_info*)finfo_array->pdata[i])->value);
if (fv->value.uinteger)
result_array[i] = TRUE;
else
result_array[i] = FALSE;
}
return 0;
}
