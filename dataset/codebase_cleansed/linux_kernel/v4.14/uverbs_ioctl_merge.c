static size_t get_elements_above_id(const void **iters,
unsigned int num_elements,
const void **elements,
size_t num_offset,
size_t data_offset,
size_t id_offset,
u16 bucket,
short *min_id)
{
size_t num_iters = 0;
short min = SHRT_MAX;
const void *elem;
int i, j, last_stored = -1;
for_each_element(elem, i, j, elements, num_elements, num_offset,
data_offset) {
u16 id = *(u16 *)(elem + id_offset);
if (GET_NS_ID(id) != bucket)
continue;
if (GET_ID(id) < *min_id ||
(min != SHRT_MAX && GET_ID(id) > min))
continue;
iters[last_stored == i ? num_iters - 1 : num_iters++] = elem;
last_stored = i;
min = GET_ID(id);
}
for (i = num_iters - 1; i >= 0 &&
GET_ID(*(u16 *)(iters[i] + id_offset)) == min; i--)
;
num_iters -= i + 1;
memmove(iters, iters + i + 1, sizeof(*iters) * num_iters);
*min_id = min;
return num_iters;
}
static short find_max_element_ns_id(unsigned int num_elements,
const void **elements,
size_t num_offset,
size_t data_offset,
size_t id_offset)
{
short max_ns = SHRT_MIN;
const void *elem;
int i, j;
for_each_element(elem, i, j, elements, num_elements, num_offset,
data_offset) {
u16 id = *(u16 *)(elem + id_offset);
if (GET_NS_ID(id) > max_ns)
max_ns = GET_NS_ID(id);
}
return max_ns;
}
static short find_max_element_id(unsigned int num_elements,
const void **elements,
size_t num_offset,
size_t data_offset,
size_t id_offset,
u16 bucket)
{
short max_id = SHRT_MIN;
const void *elem;
int i, j;
for_each_element(elem, i, j, elements, num_elements, num_offset,
data_offset) {
u16 id = *(u16 *)(elem + id_offset);
if (GET_NS_ID(id) == bucket &&
GET_ID(id) > max_id)
max_id = GET_ID(id);
}
return max_id;
}
static void free_method(struct uverbs_method_spec *method)
{
unsigned int i;
if (!method)
return;
for (i = 0; i < method->num_buckets; i++)
kfree(method->attr_buckets[i]);
kfree(method);
}
static struct uverbs_method_spec *build_method_with_attrs(const struct uverbs_method_def **method_defs,
size_t num_method_defs)
{
int bucket_idx;
int max_attr_buckets = 0;
size_t num_attr_buckets = 0;
int res = 0;
struct uverbs_method_spec *method = NULL;
const struct uverbs_attr_def **attr_defs;
unsigned int num_of_singularities = 0;
max_attr_buckets = find_max_attr_ns_id(num_method_defs, method_defs);
if (max_attr_buckets >= 0)
num_attr_buckets = max_attr_buckets + 1;
method = kzalloc(sizeof(*method) +
num_attr_buckets * sizeof(*method->attr_buckets),
GFP_KERNEL);
if (!method)
return ERR_PTR(-ENOMEM);
method->num_buckets = num_attr_buckets;
attr_defs = kcalloc(num_method_defs, sizeof(*attr_defs), GFP_KERNEL);
if (!attr_defs) {
res = -ENOMEM;
goto free_method;
}
for (bucket_idx = 0; bucket_idx < method->num_buckets; bucket_idx++) {
short min_id = SHRT_MIN;
int attr_max_bucket = 0;
struct uverbs_attr_spec_hash *hash = NULL;
attr_max_bucket = find_max_attr_id(num_method_defs, method_defs,
bucket_idx);
if (attr_max_bucket < 0)
continue;
hash = kzalloc(sizeof(*hash) +
ALIGN(sizeof(*hash->attrs) * (attr_max_bucket + 1),
sizeof(long)) +
BITS_TO_LONGS(attr_max_bucket) * sizeof(long),
GFP_KERNEL);
if (!hash) {
res = -ENOMEM;
goto free;
}
hash->num_attrs = attr_max_bucket + 1;
method->num_child_attrs += hash->num_attrs;
hash->mandatory_attrs_bitmask = (void *)(hash + 1) +
ALIGN(sizeof(*hash->attrs) *
(attr_max_bucket + 1),
sizeof(long));
method->attr_buckets[bucket_idx] = hash;
do {
size_t num_attr_defs;
struct uverbs_attr_spec *attr;
bool attr_obj_with_special_access;
num_attr_defs =
get_attrs_above_id(attr_defs,
num_method_defs,
method_defs,
bucket_idx,
&min_id);
if (!num_attr_defs)
break;
if (num_attr_defs > 1) {
res = -EEXIST;
goto free;
}
attr = &hash->attrs[min_id];
memcpy(attr, &attr_defs[0]->attr, sizeof(*attr));
attr_obj_with_special_access = IS_ATTR_OBJECT(attr) &&
(attr->obj.access == UVERBS_ACCESS_NEW ||
attr->obj.access == UVERBS_ACCESS_DESTROY);
num_of_singularities += !!attr_obj_with_special_access;
if (WARN(num_of_singularities > 1,
"ib_uverbs: Method contains more than one object attr (%d) with new/destroy access\n",
min_id) ||
WARN(attr_obj_with_special_access &&
!(attr->flags & UVERBS_ATTR_SPEC_F_MANDATORY),
"ib_uverbs: Tried to merge attr (%d) but it's an object with new/destroy aceess but isn't mandatory\n",
min_id) ||
WARN(IS_ATTR_OBJECT(attr) &&
attr->flags & UVERBS_ATTR_SPEC_F_MIN_SZ,
"ib_uverbs: Tried to merge attr (%d) but it's an object with min_sz flag\n",
min_id)) {
res = -EINVAL;
goto free;
}
if (attr->flags & UVERBS_ATTR_SPEC_F_MANDATORY)
set_bit(min_id, hash->mandatory_attrs_bitmask);
min_id++;
} while (1);
}
kfree(attr_defs);
return method;
free:
kfree(attr_defs);
free_method:
free_method(method);
return ERR_PTR(res);
}
static void free_object(struct uverbs_object_spec *object)
{
unsigned int i, j;
if (!object)
return;
for (i = 0; i < object->num_buckets; i++) {
struct uverbs_method_spec_hash *method_buckets =
object->method_buckets[i];
if (!method_buckets)
continue;
for (j = 0; j < method_buckets->num_methods; j++)
free_method(method_buckets->methods[j]);
kfree(method_buckets);
}
kfree(object);
}
static struct uverbs_object_spec *build_object_with_methods(const struct uverbs_object_def **object_defs,
size_t num_object_defs)
{
u16 bucket_idx;
int max_method_buckets = 0;
u16 num_method_buckets = 0;
int res = 0;
struct uverbs_object_spec *object = NULL;
const struct uverbs_method_def **method_defs;
max_method_buckets = find_max_method_ns_id(num_object_defs, object_defs);
if (max_method_buckets >= 0)
num_method_buckets = max_method_buckets + 1;
object = kzalloc(sizeof(*object) +
num_method_buckets *
sizeof(*object->method_buckets), GFP_KERNEL);
if (!object)
return ERR_PTR(-ENOMEM);
object->num_buckets = num_method_buckets;
method_defs = kcalloc(num_object_defs, sizeof(*method_defs), GFP_KERNEL);
if (!method_defs) {
res = -ENOMEM;
goto free_object;
}
for (bucket_idx = 0; bucket_idx < object->num_buckets; bucket_idx++) {
short min_id = SHRT_MIN;
int methods_max_bucket = 0;
struct uverbs_method_spec_hash *hash = NULL;
methods_max_bucket = find_max_method_id(num_object_defs, object_defs,
bucket_idx);
if (methods_max_bucket < 0)
continue;
hash = kzalloc(sizeof(*hash) +
sizeof(*hash->methods) * (methods_max_bucket + 1),
GFP_KERNEL);
if (!hash) {
res = -ENOMEM;
goto free;
}
hash->num_methods = methods_max_bucket + 1;
object->method_buckets[bucket_idx] = hash;
do {
size_t num_method_defs;
struct uverbs_method_spec *method;
int i;
num_method_defs =
get_methods_above_id(method_defs,
num_object_defs,
object_defs,
bucket_idx,
&min_id);
if (!num_method_defs)
break;
method = build_method_with_attrs(method_defs,
num_method_defs);
if (IS_ERR(method)) {
res = PTR_ERR(method);
goto free;
}
for (i = num_object_defs - 1;
i >= 0 && !method_defs[i]->handler; i--)
;
hash->methods[min_id++] = method;
if (WARN(i < 0,
"ib_uverbs: tried to merge function id %d, but all handlers are NULL\n",
min_id)) {
res = -EINVAL;
goto free;
}
method->handler = method_defs[i]->handler;
method->flags = method_defs[i]->flags;
} while (1);
}
kfree(method_defs);
return object;
free:
kfree(method_defs);
free_object:
free_object(object);
return ERR_PTR(res);
}
void uverbs_free_spec_tree(struct uverbs_root_spec *root)
{
unsigned int i, j;
if (!root)
return;
for (i = 0; i < root->num_buckets; i++) {
struct uverbs_object_spec_hash *object_hash =
root->object_buckets[i];
if (!object_hash)
continue;
for (j = 0; j < object_hash->num_objects; j++)
free_object(object_hash->objects[j]);
kfree(object_hash);
}
kfree(root);
}
struct uverbs_root_spec *uverbs_alloc_spec_tree(unsigned int num_trees,
const struct uverbs_object_tree_def **trees)
{
u16 bucket_idx;
short max_object_buckets = 0;
size_t num_objects_buckets = 0;
struct uverbs_root_spec *root_spec = NULL;
const struct uverbs_object_def **object_defs;
int i;
int res = 0;
max_object_buckets = find_max_object_ns_id(num_trees, trees);
if (max_object_buckets >= 0)
num_objects_buckets = max_object_buckets + 1;
root_spec = kzalloc(sizeof(*root_spec) +
num_objects_buckets * sizeof(*root_spec->object_buckets),
GFP_KERNEL);
if (!root_spec)
return ERR_PTR(-ENOMEM);
root_spec->num_buckets = num_objects_buckets;
object_defs = kcalloc(num_trees, sizeof(*object_defs),
GFP_KERNEL);
if (!object_defs) {
res = -ENOMEM;
goto free_root;
}
for (bucket_idx = 0; bucket_idx < root_spec->num_buckets; bucket_idx++) {
short min_id = SHRT_MIN;
short objects_max_bucket;
struct uverbs_object_spec_hash *hash = NULL;
objects_max_bucket = find_max_object_id(num_trees, trees,
bucket_idx);
if (objects_max_bucket < 0)
continue;
hash = kzalloc(sizeof(*hash) +
sizeof(*hash->objects) * (objects_max_bucket + 1),
GFP_KERNEL);
if (!hash) {
res = -ENOMEM;
goto free;
}
hash->num_objects = objects_max_bucket + 1;
root_spec->object_buckets[bucket_idx] = hash;
do {
size_t num_object_defs;
struct uverbs_object_spec *object;
num_object_defs = get_objects_above_id(object_defs,
num_trees,
trees,
bucket_idx,
&min_id);
if (!num_object_defs)
break;
object = build_object_with_methods(object_defs,
num_object_defs);
if (IS_ERR(object)) {
res = PTR_ERR(object);
goto free;
}
for (i = num_object_defs - 1;
i >= 0 && !object_defs[i]->type_attrs; i--)
;
object->type_attrs = i < 0 ? NULL :
object_defs[i]->type_attrs;
hash->objects[min_id++] = object;
} while (1);
}
kfree(object_defs);
return root_spec;
free:
kfree(object_defs);
free_root:
uverbs_free_spec_tree(root_spec);
return ERR_PTR(res);
}
