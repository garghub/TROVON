struct gh_t_hash_tab *gh_create(u16 max_bucket, u16 val_size,
u16(*hash) (void *, u16), bool(*match) (void *,
void *),
void (*delete) (void *))
{
struct gh_t_hash_tab *hash_tab;
u16 i;
hash_tab = kzalloc(sizeof(struct gh_t_hash_tab), GFP_KERNEL);
if (hash_tab == NULL)
return NULL;
hash_tab->max_bucket = max_bucket;
hash_tab->val_size = val_size;
hash_tab->hash = hash;
hash_tab->match = match;
hash_tab->delete = delete == NULL ? noop : delete;
hash_tab->buckets =
kzalloc(sizeof(struct element *) * max_bucket, GFP_KERNEL);
if (hash_tab->buckets == NULL) {
gh_delete(hash_tab);
return NULL;
}
for (i = 0; i < max_bucket; i++)
hash_tab->buckets[i] = NULL;
return hash_tab;
}
void gh_delete(struct gh_t_hash_tab *hash_tab)
{
struct element *elem, *next;
u16 i;
if (hash_tab != NULL) {
if (hash_tab->buckets != NULL) {
for (i = 0; i < hash_tab->max_bucket; i++) {
for (elem = hash_tab->buckets[i]; elem != NULL;
elem = next) {
next = elem->next;
(*hash_tab->delete) (elem->data);
kfree(elem);
}
}
kfree(hash_tab->buckets);
}
kfree(hash_tab);
}
}
void *gh_find(struct gh_t_hash_tab *hash_tab, void *key)
{
struct element *elem;
elem = hash_tab->buckets[(*hash_tab->hash) (key, hash_tab->max_bucket)];
for (; elem; elem = elem->next) {
if ((*hash_tab->match) (key, elem->data))
return elem->data;
}
return NULL;
}
void *gh_insert(struct gh_t_hash_tab *hash_tab, void *key, void *value)
{
struct element *elem;
u16 i;
char *src, *dst;
elem = kzalloc(sizeof(struct element) - 1 + hash_tab->val_size,
GFP_KERNEL);
if (elem != NULL) {
dst = (char *)elem->data;
src = (char *)value;
for (i = 0; i < hash_tab->val_size; i++)
*dst++ = *src++;
i = (*hash_tab->hash) (key, hash_tab->max_bucket);
elem->next = hash_tab->buckets[i];
hash_tab->buckets[i] = elem;
return elem->data;
}
return NULL;
}
static void noop(void *p)
{
p = p;
}
void gh_iterate(struct gh_t_hash_tab *hash_tab,
void (*callback)(void *, void *), void *user_data)
{
struct element *elem;
u32 i;
if (hash_tab && hash_tab->buckets)
for (i = 0; i < hash_tab->max_bucket; i++) {
elem = hash_tab->buckets[i];
while (elem) {
callback(&elem->data, user_data);
elem = elem->next;
}
}
}
