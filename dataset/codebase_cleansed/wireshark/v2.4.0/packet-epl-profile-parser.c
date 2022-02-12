static gboolean
epl_ishex(const char *num)
{
if (g_str_has_prefix(num, "0x"))
return TRUE;
for (; g_ascii_isxdigit(*num); num++)
;
if (g_ascii_tolower(*num) == 'h')
return TRUE;
return FALSE;
}
static guint16
epl_g_key_file_get_uint16(GKeyFile *gkf, const gchar *group_name, const gchar *key, GError **error)
{
guint16 ret = 0;
const char *endptr;
char *val = g_key_file_get_string(gkf, group_name, key, error);
if (!val)
return 0;
if (epl_ishex(val))
ws_hexstrtou16(val, &endptr, &ret);
else
ws_strtou16(val, &endptr, &ret);
g_free(val);
return ret;
}
static void
sort_subindices(void *key _U_, void *value, void *user_data _U_)
{
epl_wmem_iarray_t *subindices = ((struct object*)value)->subindices;
if (subindices)
epl_wmem_iarray_sort_and_compact(subindices);
}
void
epl_eds_init(void)
{
struct typemap_entry *entry;
eds_typemap = wmem_map_new(wmem_epan_scope(), g_direct_hash, g_direct_equal);
for (entry = epl_datatypes; entry->name; entry++)
{
const struct epl_datatype *type = epl_type_to_hf(entry->name);
wmem_map_insert(eds_typemap, GUINT_TO_POINTER(entry->id), (void*)type);
}
}
struct profile *
epl_eds_load(struct profile *profile, const char *eds_file)
{
GKeyFile* gkf;
GError *err;
char **group, **groups;
char *val;
gsize groups_count;
gkf = g_key_file_new();
if (!g_key_file_load_from_file(gkf, eds_file, G_KEY_FILE_NONE, &err)){
g_log(NULL, G_LOG_LEVEL_WARNING, "Error: unable to parse file \"%s\"\n", eds_file);
profile = NULL;
goto cleanup;
}
profile->path = wmem_strdup(profile->scope, eds_file);
val = g_key_file_get_string(gkf, "FileInfo", "Description", NULL);
profile->name = wmem_strndup(profile->scope, val, strcspn(val, "#"));
g_free(val);
groups = g_key_file_get_groups(gkf, &groups_count);
for (group = groups; *group; group++)
{
char *name;
const char *endptr;
guint16 idx = 0, datatype;
struct object *obj = NULL;
struct od_entry tmpobj = OD_ENTRY_INITIALIZER;
gboolean is_object = TRUE;
if (!g_ascii_isxdigit(**group))
continue;
ws_hexstrtou16(*group, &endptr, &idx);
if (*endptr == '\0')
{
tmpobj.idx = idx;
}
else if (g_str_has_prefix(endptr, "sub"))
{
if (!ws_hexstrtou16(endptr + 3, &endptr, &tmpobj.idx)
|| tmpobj.idx > 0xFF)
continue;
is_object = FALSE;
}
else continue;
tmpobj.type_class = epl_g_key_file_get_uint16(gkf, *group, "ObjectType", NULL);
if (!tmpobj.type_class)
continue;
datatype = epl_g_key_file_get_uint16(gkf, *group, "DataType", NULL);
if (datatype)
tmpobj.type = (const struct epl_datatype*)wmem_map_lookup(eds_typemap, GUINT_TO_POINTER(datatype));
if ((name = g_key_file_get_string(gkf, *group, "ParameterName", NULL)))
{
gsize count = strcspn(name, "#") + 1;
g_strlcpy(
tmpobj.name,
name,
count > sizeof tmpobj.name ? sizeof tmpobj.name : count
);
g_free(name);
}
obj = epl_profile_object_lookup_or_add(profile, idx);
if (is_object)
{
obj->info = tmpobj;
}
else
{
struct subobject subobj = SUBOBJECT_INITIALIZER;
if (!obj->subindices)
{
obj->subindices = epl_wmem_iarray_new(
profile->scope,
sizeof (struct subobject),
subobject_equal
);
}
subobj.info = tmpobj;
epl_wmem_iarray_insert(obj->subindices, subobj.info.idx, &subobj.range);
}
}
wmem_map_foreach(profile->objects, sort_subindices, NULL);
cleanup:
g_key_file_free(gkf);
return profile;
}
void
epl_xdd_init(void)
{
}
struct profile *
epl_xdd_load(struct profile *profile, const char *xml_file)
{
xmlXPathContextPtr xpathCtx = NULL;
xmlDoc *doc = NULL;
struct xpath_namespace *ns = NULL;
struct xpath *xpath = NULL;
GHashTable *typemap = NULL;
doc = xmlParseFile(xml_file);
if (!doc)
{
g_log(NULL, G_LOG_LEVEL_WARNING, "Error: unable to parse file \"%s\"\n", xml_file);
profile = NULL;
goto cleanup;
}
xpathCtx = xmlXPathNewContext(doc);
if(!xpathCtx)
{
g_log(NULL, G_LOG_LEVEL_WARNING, "Error: unable to create new XPath context\n");
profile = NULL;
goto cleanup;
}
for (ns = namespaces; ns->href; ns++)
{
if(xmlXPathRegisterNs(xpathCtx, ns->prefix, ns->href) != 0)
{
g_log(NULL, G_LOG_LEVEL_WARNING, "Error: unable to register NS with prefix=\"%s\" and href=\"%s\"\n", ns->prefix, ns->href);
profile = NULL;
goto cleanup;
}
}
profile->path = wmem_strdup(profile->scope, xml_file);
profile->data = typemap = (GHashTable*)g_hash_table_new_full(g_direct_hash, g_direct_equal, NULL, g_free);
for (xpath = xpaths; xpath->expr; xpath++)
{
xmlXPathObjectPtr xpathObj = xmlXPathEvalExpression(xpath->expr, xpathCtx);
if (!xpathObj || !xpathObj->nodesetval)
{
g_log(NULL, G_LOG_LEVEL_WARNING, "Error: unable to evaluate xpath expression \"%s\"\n", xpath->expr);
xmlXPathFreeObject(xpathObj);
profile = NULL;
goto cleanup;
}
if (xpath->handler && xpathObj->nodesetval->nodeNr)
xpath->handler(xpathObj->nodesetval, profile);
xmlXPathFreeObject(xpathObj);
}
epl_profile_object_mappings_update(profile);
cleanup:
if (typemap)
g_hash_table_destroy(typemap);
if (xpathCtx)
xmlXPathFreeContext(xpathCtx);
if (doc)
xmlFreeDoc(doc);
return profile;
}
static int
populate_profile_name(xmlNodeSetPtr nodes, void *_profile)
{
struct profile *profile = (struct profile*)_profile;
if (nodes->nodeNr == 1
&& nodes->nodeTab[0]->type == XML_ELEMENT_NODE
&& nodes->nodeTab[0]->children)
{
profile->name = wmem_strdup(profile->scope, (char*)nodes->nodeTab[0]->children->content);
return 0;
}
return -1;
}
static int
populate_datatype_list(xmlNodeSetPtr nodes, void *_profile)
{
xmlNodePtr cur;
int i;
struct profile *profile = (struct profile*)_profile;
for(i = 0; i < nodes->nodeNr; ++i)
{
xmlAttrPtr attr;
if(!nodes->nodeTab[i] || nodes->nodeTab[i]->type != XML_ELEMENT_NODE)
return -1;
cur = nodes->nodeTab[i];
for(attr = cur->properties; attr; attr = attr->next)
{
const char *endptr;
const char *key = (const char*)attr->name;
const char *val = (const char*)attr->children->content;
if (g_str_equal("dataType", key))
{
xmlNode *subnode;
guint16 idx = 0;
if (!ws_hexstrtou16(val, &endptr, &idx))
continue;
for (subnode = cur->children; subnode; subnode = subnode->next)
{
if (subnode->type == XML_ELEMENT_NODE)
{
struct datatype *type;
const struct epl_datatype *ptr = epl_type_to_hf((char*)subnode->name);
if (!ptr)
{
g_log(NULL, G_LOG_LEVEL_INFO, "Skipping unknown type '%s'\n", subnode->name);
continue;
}
type = g_new(struct datatype, 1);
type->id = idx;
type->ptr = ptr;
g_hash_table_insert((GHashTable*)profile->data, GUINT_TO_POINTER(type->id), type);
continue;
}
}
}
}
}
return 0;
}
static gboolean
parse_obj_tag(xmlNode *cur, struct od_entry *out, struct profile *profile) {
xmlAttrPtr attr;
const char *defaultValue = NULL, *actualValue = NULL;
const char *endptr;
for(attr = cur->properties; attr; attr = attr->next)
{
const char *key = (char*)attr->name,
*val = (char*)attr->children->content;
if (g_str_equal("index", key))
{
if (!ws_hexstrtou16(val, &endptr, &out->idx))
return FALSE;
} else if (g_str_equal("subIndex", key)) {
if (!ws_hexstrtou16(val, &endptr, &out->idx))
return FALSE;
} else if (g_str_equal("name", key)) {
g_strlcpy(out->name, val, sizeof out->name);
} else if (g_str_equal("objectType", key)) {
out->type_class = 0;
ws_hexstrtou16(val, &endptr, &out->type_class);
} else if (g_str_equal("dataType", key)) {
guint16 id;
if (ws_hexstrtou16(val, &endptr, &id))
{
struct datatype *type = (struct datatype*)g_hash_table_lookup((GHashTable*)profile->data, GUINT_TO_POINTER(id));
if (type) out->type = type->ptr;
}
} else if (g_str_equal("defaultValue", key)) {
defaultValue = val;
} else if (g_str_equal("actualValue", key)) {
actualValue = val;
}
#if 0
else if (g_str_equal("PDOmapping", key)) {
obj.PDOmapping = get_index(ObjectPDOmapping_tostr, val);
assert(obj.PDOmapping >= 0);
}
#endif
}
if (actualValue)
out->value = g_ascii_strtoull(actualValue, NULL, 0);
else if (defaultValue)
out->value = g_ascii_strtoull(defaultValue, NULL, 0);
else
out->value = 0;
return TRUE;
}
static int
populate_object_list(xmlNodeSetPtr nodes, void *_profile)
{
int i;
struct profile *profile = (struct profile*)_profile;
for(i = 0; i < nodes->nodeNr; ++i)
{
xmlNodePtr cur = nodes->nodeTab[i];
struct od_entry tmpobj = OD_ENTRY_INITIALIZER;
if (!nodes->nodeTab[i] || nodes->nodeTab[i]->type != XML_ELEMENT_NODE)
continue;
parse_obj_tag(cur, &tmpobj, profile);
if (tmpobj.idx)
{
struct object *obj = epl_profile_object_add(profile, tmpobj.idx);
obj->info = tmpobj;
if (tmpobj.type_class == OD_ENTRY_ARRAY || tmpobj.type_class == OD_ENTRY_RECORD)
{
xmlNode *subcur;
struct subobject subobj = SUBOBJECT_INITIALIZER;
obj->subindices = epl_wmem_iarray_new(profile->scope, sizeof (struct subobject), subobject_equal);
for (subcur = cur->children; subcur; subcur = subcur->next)
{
if (subcur->type != XML_ELEMENT_NODE)
continue;
if (parse_obj_tag(subcur, &subobj.info, profile))
{
epl_wmem_iarray_insert(obj->subindices,
subobj.info.idx, &subobj.range);
}
if (subobj.info.value && epl_profile_object_mapping_add(
profile, obj->info.idx, (guint8)subobj.info.idx, subobj.info.value))
{
g_log(NULL, G_LOG_LEVEL_INFO,
"Loaded mapping from XDC %s:%s", obj->info.name, subobj.info.name);
}
}
epl_wmem_iarray_sort_and_compact(obj->subindices);
}
}
}
return 0;
}
static gboolean
free_garray(wmem_allocator_t *scope _U_, wmem_cb_event_t event _U_, void *data)
{
GArray *arr = (GArray*)data;
g_array_free(arr, TRUE);
return FALSE;
}
static epl_wmem_iarray_t *
epl_wmem_iarray_new(wmem_allocator_t *scope, const guint elem_size, GEqualFunc equal)
{
epl_wmem_iarray_t *iarr;
if (elem_size < sizeof(range_t)) return NULL;
iarr = wmem_new(scope, epl_wmem_iarray_t);
if (!iarr) return NULL;
iarr->equal = equal;
iarr->scope = scope;
iarr->arr = g_array_new(FALSE, FALSE, elem_size);
iarr->is_sorted = TRUE;
wmem_register_callback(scope, free_garray, iarr->arr);
return iarr;
}
gboolean
epl_wmem_iarray_is_empty(epl_wmem_iarray_t *iarr)
{
return iarr->arr->len == 0;
}
gboolean
epl_wmem_iarray_is_sorted(epl_wmem_iarray_t *iarr)
{
return iarr->is_sorted;
}
static void
epl_wmem_iarray_insert(epl_wmem_iarray_t *iarr, guint32 where, range_admin_t *data)
{
if (iarr->arr->len)
iarr->is_sorted = FALSE;
data->high = data->low = where;
g_array_append_vals(iarr->arr, data, 1);
}
static int
epl_wmem_iarray_cmp(const void *a, const void *b)
{
return *(const guint32*)a - *(const guint32*)b;
}
static void
epl_wmem_iarray_sort_and_compact(epl_wmem_iarray_t *iarr)
{
range_admin_t *elem, *prev = NULL;
guint i, len;
len = iarr->arr->len;
if (iarr->is_sorted)
return;
g_array_sort(iarr->arr, epl_wmem_iarray_cmp);
prev = elem = (range_admin_t*)iarr->arr->data;
for (i = 1; i < len; i++) {
elem = (range_admin_t*)((char*)elem + g_array_get_element_size(iarr->arr));
while (i < len && elem->low - prev->high <= 1 && iarr->equal(elem, prev)) {
prev->high = elem->high;
g_array_remove_index(iarr->arr, i);
len--;
}
prev = elem;
}
iarr->is_sorted = 1;
}
static int
find_in_range(const void *_a, const void *_b)
{
const range_admin_t *a = (const range_admin_t*)_a,
*b = (const range_admin_t*)_b;
if (a->low <= b->high && b->low <= a->high)
return 0;
return a->low - b->low;
}
static void*
bsearch_garray(const void *key, GArray *arr, int (*cmp)(const void*, const void*))
{
return bsearch(key, arr->data, arr->len, g_array_get_element_size(arr), cmp);
}
range_admin_t *
epl_wmem_iarray_find(epl_wmem_iarray_t *iarr, guint32 value) {
epl_wmem_iarray_sort_and_compact(iarr);
range_admin_t needle;
needle.low = value;
needle.high = value;
return (range_admin_t*)bsearch_garray(&needle, iarr->arr, find_in_range);
}
