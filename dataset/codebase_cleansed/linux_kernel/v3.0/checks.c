static inline void check_msg(struct check *c, const char *fmt, ...)
{
va_list ap;
va_start(ap, fmt);
if ((c->level < WARN) || (c->level <= quiet))
return;
fprintf(stderr, "%s (%s): ",
(c->level == ERROR) ? "ERROR" : "Warning", c->name);
vfprintf(stderr, fmt, ap);
fprintf(stderr, "\n");
}
static void check_nodes_props(struct check *c, struct node *dt, struct node *node)
{
struct node *child;
struct property *prop;
TRACE(c, "%s", node->fullpath);
if (c->node_fn)
c->node_fn(c, dt, node);
if (c->prop_fn)
for_each_property(node, prop) {
TRACE(c, "%s\t'%s'", node->fullpath, prop->name);
c->prop_fn(c, dt, node, prop);
}
for_each_child(node, child)
check_nodes_props(c, dt, child);
}
static int run_check(struct check *c, struct node *dt)
{
int error = 0;
int i;
assert(!c->inprogress);
if (c->status != UNCHECKED)
goto out;
c->inprogress = 1;
for (i = 0; i < c->num_prereqs; i++) {
struct check *prq = c->prereq[i];
error |= run_check(prq, dt);
if (prq->status != PASSED) {
c->status = PREREQ;
check_msg(c, "Failed prerequisite '%s'",
c->prereq[i]->name);
}
}
if (c->status != UNCHECKED)
goto out;
if (c->node_fn || c->prop_fn)
check_nodes_props(c, dt, dt);
if (c->tree_fn)
c->tree_fn(c, dt);
if (c->status == UNCHECKED)
c->status = PASSED;
TRACE(c, "\tCompleted, status %d", c->status);
out:
c->inprogress = 0;
if ((c->status != PASSED) && (c->level == ERROR))
error = 1;
return error;
}
static void check_is_string(struct check *c, struct node *root,
struct node *node)
{
struct property *prop;
char *propname = c->data;
prop = get_property(node, propname);
if (!prop)
return;
if (!data_is_one_string(prop->val))
FAIL(c, "\"%s\" property in %s is not a string",
propname, node->fullpath);
}
static void check_is_cell(struct check *c, struct node *root,
struct node *node)
{
struct property *prop;
char *propname = c->data;
prop = get_property(node, propname);
if (!prop)
return;
if (prop->val.len != sizeof(cell_t))
FAIL(c, "\"%s\" property in %s is not a single cell",
propname, node->fullpath);
}
static void check_duplicate_node_names(struct check *c, struct node *dt,
struct node *node)
{
struct node *child, *child2;
for_each_child(node, child)
for (child2 = child->next_sibling;
child2;
child2 = child2->next_sibling)
if (streq(child->name, child2->name))
FAIL(c, "Duplicate node name %s",
child->fullpath);
}
static void check_duplicate_property_names(struct check *c, struct node *dt,
struct node *node)
{
struct property *prop, *prop2;
for_each_property(node, prop)
for (prop2 = prop->next; prop2; prop2 = prop2->next)
if (streq(prop->name, prop2->name))
FAIL(c, "Duplicate property name %s in %s",
prop->name, node->fullpath);
}
static void check_node_name_chars(struct check *c, struct node *dt,
struct node *node)
{
int n = strspn(node->name, c->data);
if (n < strlen(node->name))
FAIL(c, "Bad character '%c' in node %s",
node->name[n], node->fullpath);
}
static void check_node_name_format(struct check *c, struct node *dt,
struct node *node)
{
if (strchr(get_unitname(node), '@'))
FAIL(c, "Node %s has multiple '@' characters in name",
node->fullpath);
}
static void check_property_name_chars(struct check *c, struct node *dt,
struct node *node, struct property *prop)
{
int n = strspn(prop->name, c->data);
if (n < strlen(prop->name))
FAIL(c, "Bad character '%c' in property name \"%s\", node %s",
prop->name[n], prop->name, node->fullpath);
}
static void check_duplicate_label(struct check *c, struct node *dt,
const char *label, struct node *node,
struct property *prop, struct marker *mark)
{
struct node *othernode = NULL;
struct property *otherprop = NULL;
struct marker *othermark = NULL;
othernode = get_node_by_label(dt, label);
if (!othernode)
otherprop = get_property_by_label(dt, label, &othernode);
if (!othernode)
othermark = get_marker_label(dt, label, &othernode,
&otherprop);
if (!othernode)
return;
if ((othernode != node) || (otherprop != prop) || (othermark != mark))
FAIL(c, "Duplicate label '%s' on " DESCLABEL_FMT
" and " DESCLABEL_FMT,
label, DESCLABEL_ARGS(node, prop, mark),
DESCLABEL_ARGS(othernode, otherprop, othermark));
}
static void check_duplicate_label_node(struct check *c, struct node *dt,
struct node *node)
{
struct label *l;
for_each_label(node->labels, l)
check_duplicate_label(c, dt, l->label, node, NULL, NULL);
}
static void check_duplicate_label_prop(struct check *c, struct node *dt,
struct node *node, struct property *prop)
{
struct marker *m = prop->val.markers;
struct label *l;
for_each_label(prop->labels, l)
check_duplicate_label(c, dt, l->label, node, prop, NULL);
for_each_marker_of_type(m, LABEL)
check_duplicate_label(c, dt, m->ref, node, prop, m);
}
static void check_explicit_phandles(struct check *c, struct node *root,
struct node *node, struct property *prop)
{
struct marker *m;
struct node *other;
cell_t phandle;
if (!streq(prop->name, "phandle")
&& !streq(prop->name, "linux,phandle"))
return;
if (prop->val.len != sizeof(cell_t)) {
FAIL(c, "%s has bad length (%d) %s property",
node->fullpath, prop->val.len, prop->name);
return;
}
m = prop->val.markers;
for_each_marker_of_type(m, REF_PHANDLE) {
assert(m->offset == 0);
if (node != get_node_by_ref(root, m->ref))
{
FAIL(c, "%s in %s is a reference to another node",
prop->name, node->fullpath);
return;
}
return;
}
phandle = propval_cell(prop);
if ((phandle == 0) || (phandle == -1)) {
FAIL(c, "%s has bad value (0x%x) in %s property",
node->fullpath, phandle, prop->name);
return;
}
if (node->phandle && (node->phandle != phandle))
FAIL(c, "%s has %s property which replaces existing phandle information",
node->fullpath, prop->name);
other = get_node_by_phandle(root, phandle);
if (other && (other != node)) {
FAIL(c, "%s has duplicated phandle 0x%x (seen before at %s)",
node->fullpath, phandle, other->fullpath);
return;
}
node->phandle = phandle;
}
static void check_name_properties(struct check *c, struct node *root,
struct node *node)
{
struct property **pp, *prop = NULL;
for (pp = &node->proplist; *pp; pp = &((*pp)->next))
if (streq((*pp)->name, "name")) {
prop = *pp;
break;
}
if (!prop)
return;
if ((prop->val.len != node->basenamelen+1)
|| (memcmp(prop->val.val, node->name, node->basenamelen) != 0)) {
FAIL(c, "\"name\" property in %s is incorrect (\"%s\" instead"
" of base node name)", node->fullpath, prop->val.val);
} else {
*pp = prop->next;
free(prop->name);
data_free(prop->val);
free(prop);
}
}
static void fixup_phandle_references(struct check *c, struct node *dt,
struct node *node, struct property *prop)
{
struct marker *m = prop->val.markers;
struct node *refnode;
cell_t phandle;
for_each_marker_of_type(m, REF_PHANDLE) {
assert(m->offset + sizeof(cell_t) <= prop->val.len);
refnode = get_node_by_ref(dt, m->ref);
if (! refnode) {
FAIL(c, "Reference to non-existent node or label \"%s\"\n",
m->ref);
continue;
}
phandle = get_node_phandle(dt, refnode);
*((cell_t *)(prop->val.val + m->offset)) = cpu_to_fdt32(phandle);
}
}
static void fixup_path_references(struct check *c, struct node *dt,
struct node *node, struct property *prop)
{
struct marker *m = prop->val.markers;
struct node *refnode;
char *path;
for_each_marker_of_type(m, REF_PATH) {
assert(m->offset <= prop->val.len);
refnode = get_node_by_ref(dt, m->ref);
if (!refnode) {
FAIL(c, "Reference to non-existent node or label \"%s\"\n",
m->ref);
continue;
}
path = refnode->fullpath;
prop->val = data_insert_at_marker(prop->val, m, path,
strlen(path) + 1);
}
}
static void fixup_addr_size_cells(struct check *c, struct node *dt,
struct node *node)
{
struct property *prop;
node->addr_cells = -1;
node->size_cells = -1;
prop = get_property(node, "#address-cells");
if (prop)
node->addr_cells = propval_cell(prop);
prop = get_property(node, "#size-cells");
if (prop)
node->size_cells = propval_cell(prop);
}
static void check_reg_format(struct check *c, struct node *dt,
struct node *node)
{
struct property *prop;
int addr_cells, size_cells, entrylen;
prop = get_property(node, "reg");
if (!prop)
return;
if (!node->parent) {
FAIL(c, "Root node has a \"reg\" property");
return;
}
if (prop->val.len == 0)
FAIL(c, "\"reg\" property in %s is empty", node->fullpath);
addr_cells = node_addr_cells(node->parent);
size_cells = node_size_cells(node->parent);
entrylen = (addr_cells + size_cells) * sizeof(cell_t);
if ((prop->val.len % entrylen) != 0)
FAIL(c, "\"reg\" property in %s has invalid length (%d bytes) "
"(#address-cells == %d, #size-cells == %d)",
node->fullpath, prop->val.len, addr_cells, size_cells);
}
static void check_ranges_format(struct check *c, struct node *dt,
struct node *node)
{
struct property *prop;
int c_addr_cells, p_addr_cells, c_size_cells, p_size_cells, entrylen;
prop = get_property(node, "ranges");
if (!prop)
return;
if (!node->parent) {
FAIL(c, "Root node has a \"ranges\" property");
return;
}
p_addr_cells = node_addr_cells(node->parent);
p_size_cells = node_size_cells(node->parent);
c_addr_cells = node_addr_cells(node);
c_size_cells = node_size_cells(node);
entrylen = (p_addr_cells + c_addr_cells + c_size_cells) * sizeof(cell_t);
if (prop->val.len == 0) {
if (p_addr_cells != c_addr_cells)
FAIL(c, "%s has empty \"ranges\" property but its "
"#address-cells (%d) differs from %s (%d)",
node->fullpath, c_addr_cells, node->parent->fullpath,
p_addr_cells);
if (p_size_cells != c_size_cells)
FAIL(c, "%s has empty \"ranges\" property but its "
"#size-cells (%d) differs from %s (%d)",
node->fullpath, c_size_cells, node->parent->fullpath,
p_size_cells);
} else if ((prop->val.len % entrylen) != 0) {
FAIL(c, "\"ranges\" property in %s has invalid length (%d bytes) "
"(parent #address-cells == %d, child #address-cells == %d, "
"#size-cells == %d)", node->fullpath, prop->val.len,
p_addr_cells, c_addr_cells, c_size_cells);
}
}
static void check_avoid_default_addr_size(struct check *c, struct node *dt,
struct node *node)
{
struct property *reg, *ranges;
if (!node->parent)
return;
reg = get_property(node, "reg");
ranges = get_property(node, "ranges");
if (!reg && !ranges)
return;
if ((node->parent->addr_cells == -1))
FAIL(c, "Relying on default #address-cells value for %s",
node->fullpath);
if ((node->parent->size_cells == -1))
FAIL(c, "Relying on default #size-cells value for %s",
node->fullpath);
}
static void check_obsolete_chosen_interrupt_controller(struct check *c,
struct node *dt)
{
struct node *chosen;
struct property *prop;
chosen = get_node_by_path(dt, "/chosen");
if (!chosen)
return;
prop = get_property(chosen, "interrupt-controller");
if (prop)
FAIL(c, "/chosen has obsolete \"interrupt-controller\" "
"property");
}
void process_checks(int force, struct boot_info *bi)
{
struct node *dt = bi->dt;
int i;
int error = 0;
for (i = 0; i < ARRAY_SIZE(check_table); i++) {
struct check *c = check_table[i];
if (c->level != IGNORE)
error = error || run_check(c, dt);
}
if (error) {
if (!force) {
fprintf(stderr, "ERROR: Input tree has errors, aborting "
"(use -f to force output)\n");
exit(2);
} else if (quiet < 3) {
fprintf(stderr, "Warning: Input tree has errors, "
"output forced\n");
}
}
}
