void
cfs_percpt_free(void *vars)
{
struct cfs_var_array *arr;
int i;
arr = container_of(vars, struct cfs_var_array, va_ptrs[0]);
for (i = 0; i < arr->va_count; i++) {
if (arr->va_ptrs[i] != NULL)
LIBCFS_FREE(arr->va_ptrs[i], arr->va_size);
}
LIBCFS_FREE(arr, offsetof(struct cfs_var_array,
va_ptrs[arr->va_count]));
}
void *
cfs_percpt_alloc(struct cfs_cpt_table *cptab, unsigned int size)
{
struct cfs_var_array *arr;
int count;
int i;
count = cfs_cpt_number(cptab);
LIBCFS_ALLOC(arr, offsetof(struct cfs_var_array, va_ptrs[count]));
if (!arr)
return NULL;
arr->va_size = size = L1_CACHE_ALIGN(size);
arr->va_count = count;
arr->va_cptab = cptab;
for (i = 0; i < count; i++) {
LIBCFS_CPT_ALLOC(arr->va_ptrs[i], cptab, i, size);
if (!arr->va_ptrs[i]) {
cfs_percpt_free((void *)&arr->va_ptrs[0]);
return NULL;
}
}
return (void *)&arr->va_ptrs[0];
}
int
cfs_percpt_number(void *vars)
{
struct cfs_var_array *arr;
arr = container_of(vars, struct cfs_var_array, va_ptrs[0]);
return arr->va_count;
}
void *
cfs_percpt_current(void *vars)
{
struct cfs_var_array *arr;
int cpt;
arr = container_of(vars, struct cfs_var_array, va_ptrs[0]);
cpt = cfs_cpt_current(arr->va_cptab, 0);
if (cpt < 0)
return NULL;
return arr->va_ptrs[cpt];
}
void *
cfs_percpt_index(void *vars, int idx)
{
struct cfs_var_array *arr;
arr = container_of(vars, struct cfs_var_array, va_ptrs[0]);
LASSERT(idx >= 0 && idx < arr->va_count);
return arr->va_ptrs[idx];
}
void
cfs_array_free(void *vars)
{
struct cfs_var_array *arr;
int i;
arr = container_of(vars, struct cfs_var_array, va_ptrs[0]);
for (i = 0; i < arr->va_count; i++) {
if (!arr->va_ptrs[i])
continue;
LIBCFS_FREE(arr->va_ptrs[i], arr->va_size);
}
LIBCFS_FREE(arr, offsetof(struct cfs_var_array,
va_ptrs[arr->va_count]));
}
void *
cfs_array_alloc(int count, unsigned int size)
{
struct cfs_var_array *arr;
int i;
LIBCFS_ALLOC(arr, offsetof(struct cfs_var_array, va_ptrs[count]));
if (!arr)
return NULL;
arr->va_count = count;
arr->va_size = size;
for (i = 0; i < count; i++) {
LIBCFS_ALLOC(arr->va_ptrs[i], size);
if (!arr->va_ptrs[i]) {
cfs_array_free((void *)&arr->va_ptrs[0]);
return NULL;
}
}
return (void *)&arr->va_ptrs[0];
}
