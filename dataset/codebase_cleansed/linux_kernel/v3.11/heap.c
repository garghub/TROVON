static int
cfs_binheap_grow(cfs_binheap_t *h)
{
cfs_binheap_node_t ***frag1 = NULL;
cfs_binheap_node_t **frag2;
int hwm = h->cbh_hwm;
LASSERT((h->cbh_hwm & CBH_MASK) == 0);
if (hwm == 0) {
CBH_ALLOC(h->cbh_elements1, h);
if (h->cbh_elements1 == NULL)
return -ENOMEM;
goto out;
}
hwm -= CBH_SIZE;
if (hwm < CBH_SIZE * CBH_SIZE) {
CBH_ALLOC(frag2, h);
if (frag2 == NULL)
return -ENOMEM;
if (hwm == 0) {
CBH_ALLOC(h->cbh_elements2, h);
if (h->cbh_elements2 == NULL) {
CBH_FREE(frag2);
return -ENOMEM;
}
}
h->cbh_elements2[hwm >> CBH_SHIFT] = frag2;
goto out;
}
hwm -= CBH_SIZE * CBH_SIZE;
#if (CBH_SHIFT * 3 < 32)
if (hwm >= CBH_SIZE * CBH_SIZE * CBH_SIZE) {
return -ENOMEM;
}
#endif
CBH_ALLOC(frag2, h);
if (frag2 == NULL)
return -ENOMEM;
if (((hwm >> CBH_SHIFT) & CBH_MASK) == 0) {
CBH_ALLOC(frag1, h);
if (frag1 == NULL) {
CBH_FREE(frag2);
return -ENOMEM;
}
}
if (hwm == 0) {
CBH_ALLOC(h->cbh_elements3, h);
if (h->cbh_elements3 == NULL) {
CBH_FREE(frag2);
CBH_FREE(frag1);
return -ENOMEM;
}
}
if (frag1 != NULL) {
LASSERT(h->cbh_elements3[hwm >> (2 * CBH_SHIFT)] == NULL);
h->cbh_elements3[hwm >> (2 * CBH_SHIFT)] = frag1;
} else {
frag1 = h->cbh_elements3[hwm >> (2 * CBH_SHIFT)];
LASSERT(frag1 != NULL);
}
frag1[(hwm >> CBH_SHIFT) & CBH_MASK] = frag2;
out:
h->cbh_hwm += CBH_SIZE;
return 0;
}
cfs_binheap_t *
cfs_binheap_create(cfs_binheap_ops_t *ops, unsigned int flags,
unsigned count, void *arg, struct cfs_cpt_table *cptab,
int cptid)
{
cfs_binheap_t *h;
LASSERT(ops != NULL);
LASSERT(ops->hop_compare != NULL);
LASSERT(cptab != NULL);
LASSERT(cptid == CFS_CPT_ANY ||
(cptid >= 0 && cptid < cptab->ctb_nparts));
LIBCFS_CPT_ALLOC(h, cptab, cptid, sizeof(*h));
if (h == NULL)
return NULL;
h->cbh_ops = ops;
h->cbh_nelements = 0;
h->cbh_hwm = 0;
h->cbh_private = arg;
h->cbh_flags = flags & (~CBH_FLAG_ATOMIC_GROW);
h->cbh_cptab = cptab;
h->cbh_cptid = cptid;
while (h->cbh_hwm < count) {
if (cfs_binheap_grow(h) != 0) {
cfs_binheap_destroy(h);
return NULL;
}
}
h->cbh_flags |= flags & CBH_FLAG_ATOMIC_GROW;
return h;
}
void
cfs_binheap_destroy(cfs_binheap_t *h)
{
int idx0;
int idx1;
int n;
LASSERT(h != NULL);
n = h->cbh_hwm;
if (n > 0) {
CBH_FREE(h->cbh_elements1);
n -= CBH_SIZE;
}
if (n > 0) {
for (idx0 = 0; idx0 < CBH_SIZE && n > 0; idx0++) {
CBH_FREE(h->cbh_elements2[idx0]);
n -= CBH_SIZE;
}
CBH_FREE(h->cbh_elements2);
}
if (n > 0) {
for (idx0 = 0; idx0 < CBH_SIZE && n > 0; idx0++) {
for (idx1 = 0; idx1 < CBH_SIZE && n > 0; idx1++) {
CBH_FREE(h->cbh_elements3[idx0][idx1]);
n -= CBH_SIZE;
}
CBH_FREE(h->cbh_elements3[idx0]);
}
CBH_FREE(h->cbh_elements3);
}
LIBCFS_FREE(h, sizeof(*h));
}
static cfs_binheap_node_t **
cfs_binheap_pointer(cfs_binheap_t *h, unsigned int idx)
{
if (idx < CBH_SIZE)
return &(h->cbh_elements1[idx]);
idx -= CBH_SIZE;
if (idx < CBH_SIZE * CBH_SIZE)
return &(h->cbh_elements2[idx >> CBH_SHIFT][idx & CBH_MASK]);
idx -= CBH_SIZE * CBH_SIZE;
return &(h->cbh_elements3[idx >> (2 * CBH_SHIFT)]\
[(idx >> CBH_SHIFT) & CBH_MASK]\
[idx & CBH_MASK]);
}
cfs_binheap_node_t *
cfs_binheap_find(cfs_binheap_t *h, unsigned int idx)
{
if (idx >= h->cbh_nelements)
return NULL;
return *cfs_binheap_pointer(h, idx);
}
static int
cfs_binheap_bubble(cfs_binheap_t *h, cfs_binheap_node_t *e)
{
unsigned int cur_idx = e->chn_index;
cfs_binheap_node_t **cur_ptr;
unsigned int parent_idx;
cfs_binheap_node_t **parent_ptr;
int did_sth = 0;
cur_ptr = cfs_binheap_pointer(h, cur_idx);
LASSERT(*cur_ptr == e);
while (cur_idx > 0) {
parent_idx = (cur_idx - 1) >> 1;
parent_ptr = cfs_binheap_pointer(h, parent_idx);
LASSERT((*parent_ptr)->chn_index == parent_idx);
if (h->cbh_ops->hop_compare(*parent_ptr, e))
break;
(*parent_ptr)->chn_index = cur_idx;
*cur_ptr = *parent_ptr;
cur_ptr = parent_ptr;
cur_idx = parent_idx;
did_sth = 1;
}
e->chn_index = cur_idx;
*cur_ptr = e;
return did_sth;
}
static int
cfs_binheap_sink(cfs_binheap_t *h, cfs_binheap_node_t *e)
{
unsigned int n = h->cbh_nelements;
unsigned int child_idx;
cfs_binheap_node_t **child_ptr;
cfs_binheap_node_t *child;
unsigned int child2_idx;
cfs_binheap_node_t **child2_ptr;
cfs_binheap_node_t *child2;
unsigned int cur_idx;
cfs_binheap_node_t **cur_ptr;
int did_sth = 0;
cur_idx = e->chn_index;
cur_ptr = cfs_binheap_pointer(h, cur_idx);
LASSERT(*cur_ptr == e);
while (cur_idx < n) {
child_idx = (cur_idx << 1) + 1;
if (child_idx >= n)
break;
child_ptr = cfs_binheap_pointer(h, child_idx);
child = *child_ptr;
child2_idx = child_idx + 1;
if (child2_idx < n) {
child2_ptr = cfs_binheap_pointer(h, child2_idx);
child2 = *child2_ptr;
if (h->cbh_ops->hop_compare(child2, child)) {
child_idx = child2_idx;
child_ptr = child2_ptr;
child = child2;
}
}
LASSERT(child->chn_index == child_idx);
if (h->cbh_ops->hop_compare(e, child))
break;
child->chn_index = cur_idx;
*cur_ptr = child;
cur_ptr = child_ptr;
cur_idx = child_idx;
did_sth = 1;
}
e->chn_index = cur_idx;
*cur_ptr = e;
return did_sth;
}
int
cfs_binheap_insert(cfs_binheap_t *h, cfs_binheap_node_t *e)
{
cfs_binheap_node_t **new_ptr;
unsigned int new_idx = h->cbh_nelements;
int rc;
if (new_idx == h->cbh_hwm) {
rc = cfs_binheap_grow(h);
if (rc != 0)
return rc;
}
if (h->cbh_ops->hop_enter) {
rc = h->cbh_ops->hop_enter(h, e);
if (rc != 0)
return rc;
}
e->chn_index = new_idx;
new_ptr = cfs_binheap_pointer(h, new_idx);
h->cbh_nelements++;
*new_ptr = e;
cfs_binheap_bubble(h, e);
return 0;
}
void
cfs_binheap_remove(cfs_binheap_t *h, cfs_binheap_node_t *e)
{
unsigned int n = h->cbh_nelements;
unsigned int cur_idx = e->chn_index;
cfs_binheap_node_t **cur_ptr;
cfs_binheap_node_t *last;
LASSERT(cur_idx != CBH_POISON);
LASSERT(cur_idx < n);
cur_ptr = cfs_binheap_pointer(h, cur_idx);
LASSERT(*cur_ptr == e);
n--;
last = *cfs_binheap_pointer(h, n);
h->cbh_nelements = n;
if (last == e)
return;
last->chn_index = cur_idx;
*cur_ptr = last;
if (!cfs_binheap_bubble(h, *cur_ptr))
cfs_binheap_sink(h, *cur_ptr);
e->chn_index = CBH_POISON;
if (h->cbh_ops->hop_exit)
h->cbh_ops->hop_exit(h, e);
}
