void add_label(struct label **labels, char *label)
{
struct label *new;
for_each_label_withdel(*labels, new)
if (streq(new->label, label)) {
new->deleted = 0;
return;
}
new = xmalloc(sizeof(*new));
memset(new, 0, sizeof(*new));
new->label = label;
new->next = *labels;
*labels = new;
}
void delete_labels(struct label **labels)
{
struct label *label;
for_each_label(*labels, label)
label->deleted = 1;
}
struct property *build_property(char *name, struct data val)
{
struct property *new = xmalloc(sizeof(*new));
memset(new, 0, sizeof(*new));
new->name = name;
new->val = val;
return new;
}
struct property *build_property_delete(char *name)
{
struct property *new = xmalloc(sizeof(*new));
memset(new, 0, sizeof(*new));
new->name = name;
new->deleted = 1;
return new;
}
struct property *chain_property(struct property *first, struct property *list)
{
assert(first->next == NULL);
first->next = list;
return first;
}
struct property *reverse_properties(struct property *first)
{
struct property *p = first;
struct property *head = NULL;
struct property *next;
while (p) {
next = p->next;
p->next = head;
head = p;
p = next;
}
return head;
}
struct node *build_node(struct property *proplist, struct node *children)
{
struct node *new = xmalloc(sizeof(*new));
struct node *child;
memset(new, 0, sizeof(*new));
new->proplist = reverse_properties(proplist);
new->children = children;
for_each_child(new, child) {
child->parent = new;
}
return new;
}
struct node *build_node_delete(void)
{
struct node *new = xmalloc(sizeof(*new));
memset(new, 0, sizeof(*new));
new->deleted = 1;
return new;
}
struct node *name_node(struct node *node, char *name)
{
assert(node->name == NULL);
node->name = name;
return node;
}
struct node *merge_nodes(struct node *old_node, struct node *new_node)
{
struct property *new_prop, *old_prop;
struct node *new_child, *old_child;
struct label *l;
old_node->deleted = 0;
for_each_label_withdel(new_node->labels, l)
add_label(&old_node->labels, l->label);
while (new_node->proplist) {
new_prop = new_node->proplist;
new_node->proplist = new_prop->next;
new_prop->next = NULL;
if (new_prop->deleted) {
delete_property_by_name(old_node, new_prop->name);
free(new_prop);
continue;
}
for_each_property_withdel(old_node, old_prop) {
if (streq(old_prop->name, new_prop->name)) {
for_each_label_withdel(new_prop->labels, l)
add_label(&old_prop->labels, l->label);
old_prop->val = new_prop->val;
old_prop->deleted = 0;
free(new_prop);
new_prop = NULL;
break;
}
}
if (new_prop)
add_property(old_node, new_prop);
}
while (new_node->children) {
new_child = new_node->children;
new_node->children = new_child->next_sibling;
new_child->parent = NULL;
new_child->next_sibling = NULL;
if (new_child->deleted) {
delete_node_by_name(old_node, new_child->name);
free(new_child);
continue;
}
for_each_child_withdel(old_node, old_child) {
if (streq(old_child->name, new_child->name)) {
merge_nodes(old_child, new_child);
new_child = NULL;
break;
}
}
if (new_child)
add_child(old_node, new_child);
}
free(new_node);
return old_node;
}
struct node *chain_node(struct node *first, struct node *list)
{
assert(first->next_sibling == NULL);
first->next_sibling = list;
return first;
}
void add_property(struct node *node, struct property *prop)
{
struct property **p;
prop->next = NULL;
p = &node->proplist;
while (*p)
p = &((*p)->next);
*p = prop;
}
void delete_property_by_name(struct node *node, char *name)
{
struct property *prop = node->proplist;
while (prop) {
if (!strcmp(prop->name, name)) {
delete_property(prop);
return;
}
prop = prop->next;
}
}
void delete_property(struct property *prop)
{
prop->deleted = 1;
delete_labels(&prop->labels);
}
void add_child(struct node *parent, struct node *child)
{
struct node **p;
child->next_sibling = NULL;
child->parent = parent;
p = &parent->children;
while (*p)
p = &((*p)->next_sibling);
*p = child;
}
void delete_node_by_name(struct node *parent, char *name)
{
struct node *node = parent->children;
while (node) {
if (!strcmp(node->name, name)) {
delete_node(node);
return;
}
node = node->next_sibling;
}
}
void delete_node(struct node *node)
{
struct property *prop;
struct node *child;
node->deleted = 1;
for_each_child(node, child)
delete_node(child);
for_each_property(node, prop)
delete_property(prop);
delete_labels(&node->labels);
}
void append_to_property(struct node *node,
char *name, const void *data, int len)
{
struct data d;
struct property *p;
p = get_property(node, name);
if (p) {
d = data_append_data(p->val, data, len);
p->val = d;
} else {
d = data_append_data(empty_data, data, len);
p = build_property(name, d);
add_property(node, p);
}
}
struct reserve_info *build_reserve_entry(uint64_t address, uint64_t size)
{
struct reserve_info *new = xmalloc(sizeof(*new));
memset(new, 0, sizeof(*new));
new->re.address = address;
new->re.size = size;
return new;
}
struct reserve_info *chain_reserve_entry(struct reserve_info *first,
struct reserve_info *list)
{
assert(first->next == NULL);
first->next = list;
return first;
}
struct reserve_info *add_reserve_entry(struct reserve_info *list,
struct reserve_info *new)
{
struct reserve_info *last;
new->next = NULL;
if (! list)
return new;
for (last = list; last->next; last = last->next)
;
last->next = new;
return list;
}
struct dt_info *build_dt_info(unsigned int dtsflags,
struct reserve_info *reservelist,
struct node *tree, uint32_t boot_cpuid_phys)
{
struct dt_info *dti;
dti = xmalloc(sizeof(*dti));
dti->dtsflags = dtsflags;
dti->reservelist = reservelist;
dti->dt = tree;
dti->boot_cpuid_phys = boot_cpuid_phys;
return dti;
}
const char *get_unitname(struct node *node)
{
if (node->name[node->basenamelen] == '\0')
return "";
else
return node->name + node->basenamelen + 1;
}
struct property *get_property(struct node *node, const char *propname)
{
struct property *prop;
for_each_property(node, prop)
if (streq(prop->name, propname))
return prop;
return NULL;
}
cell_t propval_cell(struct property *prop)
{
assert(prop->val.len == sizeof(cell_t));
return fdt32_to_cpu(*((cell_t *)prop->val.val));
}
struct property *get_property_by_label(struct node *tree, const char *label,
struct node **node)
{
struct property *prop;
struct node *c;
*node = tree;
for_each_property(tree, prop) {
struct label *l;
for_each_label(prop->labels, l)
if (streq(l->label, label))
return prop;
}
for_each_child(tree, c) {
prop = get_property_by_label(c, label, node);
if (prop)
return prop;
}
*node = NULL;
return NULL;
}
struct marker *get_marker_label(struct node *tree, const char *label,
struct node **node, struct property **prop)
{
struct marker *m;
struct property *p;
struct node *c;
*node = tree;
for_each_property(tree, p) {
*prop = p;
m = p->val.markers;
for_each_marker_of_type(m, LABEL)
if (streq(m->ref, label))
return m;
}
for_each_child(tree, c) {
m = get_marker_label(c, label, node, prop);
if (m)
return m;
}
*prop = NULL;
*node = NULL;
return NULL;
}
struct node *get_subnode(struct node *node, const char *nodename)
{
struct node *child;
for_each_child(node, child)
if (streq(child->name, nodename))
return child;
return NULL;
}
struct node *get_node_by_path(struct node *tree, const char *path)
{
const char *p;
struct node *child;
if (!path || ! (*path)) {
if (tree->deleted)
return NULL;
return tree;
}
while (path[0] == '/')
path++;
p = strchr(path, '/');
for_each_child(tree, child) {
if (p && strneq(path, child->name, p-path))
return get_node_by_path(child, p+1);
else if (!p && streq(path, child->name))
return child;
}
return NULL;
}
struct node *get_node_by_label(struct node *tree, const char *label)
{
struct node *child, *node;
struct label *l;
assert(label && (strlen(label) > 0));
for_each_label(tree->labels, l)
if (streq(l->label, label))
return tree;
for_each_child(tree, child) {
node = get_node_by_label(child, label);
if (node)
return node;
}
return NULL;
}
struct node *get_node_by_phandle(struct node *tree, cell_t phandle)
{
struct node *child, *node;
assert((phandle != 0) && (phandle != -1));
if (tree->phandle == phandle) {
if (tree->deleted)
return NULL;
return tree;
}
for_each_child(tree, child) {
node = get_node_by_phandle(child, phandle);
if (node)
return node;
}
return NULL;
}
struct node *get_node_by_ref(struct node *tree, const char *ref)
{
if (streq(ref, "/"))
return tree;
else if (ref[0] == '/')
return get_node_by_path(tree, ref);
else
return get_node_by_label(tree, ref);
}
cell_t get_node_phandle(struct node *root, struct node *node)
{
static cell_t phandle = 1;
if ((node->phandle != 0) && (node->phandle != -1))
return node->phandle;
while (get_node_by_phandle(root, phandle))
phandle++;
node->phandle = phandle;
if (!get_property(node, "linux,phandle")
&& (phandle_format & PHANDLE_LEGACY))
add_property(node,
build_property("linux,phandle",
data_append_cell(empty_data, phandle)));
if (!get_property(node, "phandle")
&& (phandle_format & PHANDLE_EPAPR))
add_property(node,
build_property("phandle",
data_append_cell(empty_data, phandle)));
return node->phandle;
}
uint32_t guess_boot_cpuid(struct node *tree)
{
struct node *cpus, *bootcpu;
struct property *reg;
cpus = get_node_by_path(tree, "/cpus");
if (!cpus)
return 0;
bootcpu = cpus->children;
if (!bootcpu)
return 0;
reg = get_property(bootcpu, "reg");
if (!reg || (reg->val.len != sizeof(uint32_t)))
return 0;
return propval_cell(reg);
}
static int cmp_reserve_info(const void *ax, const void *bx)
{
const struct reserve_info *a, *b;
a = *((const struct reserve_info * const *)ax);
b = *((const struct reserve_info * const *)bx);
if (a->re.address < b->re.address)
return -1;
else if (a->re.address > b->re.address)
return 1;
else if (a->re.size < b->re.size)
return -1;
else if (a->re.size > b->re.size)
return 1;
else
return 0;
}
static void sort_reserve_entries(struct dt_info *dti)
{
struct reserve_info *ri, **tbl;
int n = 0, i = 0;
for (ri = dti->reservelist;
ri;
ri = ri->next)
n++;
if (n == 0)
return;
tbl = xmalloc(n * sizeof(*tbl));
for (ri = dti->reservelist;
ri;
ri = ri->next)
tbl[i++] = ri;
qsort(tbl, n, sizeof(*tbl), cmp_reserve_info);
dti->reservelist = tbl[0];
for (i = 0; i < (n-1); i++)
tbl[i]->next = tbl[i+1];
tbl[n-1]->next = NULL;
free(tbl);
}
static int cmp_prop(const void *ax, const void *bx)
{
const struct property *a, *b;
a = *((const struct property * const *)ax);
b = *((const struct property * const *)bx);
return strcmp(a->name, b->name);
}
static void sort_properties(struct node *node)
{
int n = 0, i = 0;
struct property *prop, **tbl;
for_each_property_withdel(node, prop)
n++;
if (n == 0)
return;
tbl = xmalloc(n * sizeof(*tbl));
for_each_property_withdel(node, prop)
tbl[i++] = prop;
qsort(tbl, n, sizeof(*tbl), cmp_prop);
node->proplist = tbl[0];
for (i = 0; i < (n-1); i++)
tbl[i]->next = tbl[i+1];
tbl[n-1]->next = NULL;
free(tbl);
}
static int cmp_subnode(const void *ax, const void *bx)
{
const struct node *a, *b;
a = *((const struct node * const *)ax);
b = *((const struct node * const *)bx);
return strcmp(a->name, b->name);
}
static void sort_subnodes(struct node *node)
{
int n = 0, i = 0;
struct node *subnode, **tbl;
for_each_child_withdel(node, subnode)
n++;
if (n == 0)
return;
tbl = xmalloc(n * sizeof(*tbl));
for_each_child_withdel(node, subnode)
tbl[i++] = subnode;
qsort(tbl, n, sizeof(*tbl), cmp_subnode);
node->children = tbl[0];
for (i = 0; i < (n-1); i++)
tbl[i]->next_sibling = tbl[i+1];
tbl[n-1]->next_sibling = NULL;
free(tbl);
}
static void sort_node(struct node *node)
{
struct node *c;
sort_properties(node);
sort_subnodes(node);
for_each_child_withdel(node, c)
sort_node(c);
}
void sort_tree(struct dt_info *dti)
{
sort_reserve_entries(dti);
sort_node(dti->dt);
}
static struct node *build_and_name_child_node(struct node *parent, char *name)
{
struct node *node;
node = build_node(NULL, NULL);
name_node(node, xstrdup(name));
add_child(parent, node);
return node;
}
static struct node *build_root_node(struct node *dt, char *name)
{
struct node *an;
an = get_subnode(dt, name);
if (!an)
an = build_and_name_child_node(dt, name);
if (!an)
die("Could not build root node /%s\n", name);
return an;
}
static bool any_label_tree(struct dt_info *dti, struct node *node)
{
struct node *c;
if (node->labels)
return true;
for_each_child(node, c)
if (any_label_tree(dti, c))
return true;
return false;
}
static void generate_label_tree_internal(struct dt_info *dti,
struct node *an, struct node *node,
bool allocph)
{
struct node *dt = dti->dt;
struct node *c;
struct property *p;
struct label *l;
if (node->labels) {
for_each_label(node->labels, l) {
p = get_property(an, l->label);
if (p) {
fprintf(stderr, "WARNING: label %s already"
" exists in /%s", l->label,
an->name);
continue;
}
p = build_property(l->label,
data_copy_mem(node->fullpath,
strlen(node->fullpath) + 1));
add_property(an, p);
}
if (allocph)
(void)get_node_phandle(dt, node);
}
for_each_child(node, c)
generate_label_tree_internal(dti, an, c, allocph);
}
static bool any_fixup_tree(struct dt_info *dti, struct node *node)
{
struct node *c;
struct property *prop;
struct marker *m;
for_each_property(node, prop) {
m = prop->val.markers;
for_each_marker_of_type(m, REF_PHANDLE) {
if (!get_node_by_ref(dti->dt, m->ref))
return true;
}
}
for_each_child(node, c) {
if (any_fixup_tree(dti, c))
return true;
}
return false;
}
static void add_fixup_entry(struct dt_info *dti, struct node *fn,
struct node *node, struct property *prop,
struct marker *m)
{
char *entry;
assert(m->type == REF_PHANDLE);
if (strchr(node->fullpath, ':') || strchr(prop->name, ':'))
die("arguments should not contain ':'\n");
xasprintf(&entry, "%s:%s:%u",
node->fullpath, prop->name, m->offset);
append_to_property(fn, m->ref, entry, strlen(entry) + 1);
}
static void generate_fixups_tree_internal(struct dt_info *dti,
struct node *fn,
struct node *node)
{
struct node *dt = dti->dt;
struct node *c;
struct property *prop;
struct marker *m;
struct node *refnode;
for_each_property(node, prop) {
m = prop->val.markers;
for_each_marker_of_type(m, REF_PHANDLE) {
refnode = get_node_by_ref(dt, m->ref);
if (!refnode)
add_fixup_entry(dti, fn, node, prop, m);
}
}
for_each_child(node, c)
generate_fixups_tree_internal(dti, fn, c);
}
static bool any_local_fixup_tree(struct dt_info *dti, struct node *node)
{
struct node *c;
struct property *prop;
struct marker *m;
for_each_property(node, prop) {
m = prop->val.markers;
for_each_marker_of_type(m, REF_PHANDLE) {
if (get_node_by_ref(dti->dt, m->ref))
return true;
}
}
for_each_child(node, c) {
if (any_local_fixup_tree(dti, c))
return true;
}
return false;
}
static void add_local_fixup_entry(struct dt_info *dti,
struct node *lfn, struct node *node,
struct property *prop, struct marker *m,
struct node *refnode)
{
struct node *wn, *nwn;
uint32_t value_32;
char **compp;
int i, depth;
depth = 0;
for (wn = node; wn; wn = wn->parent)
depth++;
compp = xmalloc(sizeof(*compp) * depth);
for (wn = node, i = depth - 1; wn; wn = wn->parent, i--)
compp[i] = wn->name;
for (wn = lfn, i = 1; i < depth; i++, wn = nwn) {
nwn = get_subnode(wn, compp[i]);
if (!nwn)
nwn = build_and_name_child_node(wn, compp[i]);
}
free(compp);
value_32 = cpu_to_fdt32(m->offset);
append_to_property(wn, prop->name, &value_32, sizeof(value_32));
}
static void generate_local_fixups_tree_internal(struct dt_info *dti,
struct node *lfn,
struct node *node)
{
struct node *dt = dti->dt;
struct node *c;
struct property *prop;
struct marker *m;
struct node *refnode;
for_each_property(node, prop) {
m = prop->val.markers;
for_each_marker_of_type(m, REF_PHANDLE) {
refnode = get_node_by_ref(dt, m->ref);
if (refnode)
add_local_fixup_entry(dti, lfn, node, prop, m, refnode);
}
}
for_each_child(node, c)
generate_local_fixups_tree_internal(dti, lfn, c);
}
void generate_label_tree(struct dt_info *dti, char *name, bool allocph)
{
if (!any_label_tree(dti, dti->dt))
return;
generate_label_tree_internal(dti, build_root_node(dti->dt, name),
dti->dt, allocph);
}
void generate_fixups_tree(struct dt_info *dti, char *name)
{
if (!any_fixup_tree(dti, dti->dt))
return;
generate_fixups_tree_internal(dti, build_root_node(dti->dt, name),
dti->dt);
}
void generate_local_fixups_tree(struct dt_info *dti, char *name)
{
if (!any_local_fixup_tree(dti, dti->dt))
return;
generate_local_fixups_tree_internal(dti, build_root_node(dti->dt, name),
dti->dt);
}
