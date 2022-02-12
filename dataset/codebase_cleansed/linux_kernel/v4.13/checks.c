static void check_nodes_props(struct check *c, struct dt_info *dti, struct node *node)
{
struct node *child;
TRACE(c, "%s", node->fullpath);
if (c->fn)
c->fn(c, dti, node);
for_each_child(node, child)
check_nodes_props(c, dti, child);
}
static bool run_check(struct check *c, struct dt_info *dti)
{
struct node *dt = dti->dt;
bool error = false;
int i;
assert(!c->inprogress);
if (c->status != UNCHECKED)
goto out;
c->inprogress = true;
for (i = 0; i < c->num_prereqs; i++) {
struct check *prq = c->prereq[i];
error = error || run_check(prq, dti);
if (prq->status != PASSED) {
c->status = PREREQ;
check_msg(c, dti, "Failed prerequisite '%s'",
c->prereq[i]->name);
}
}
if (c->status != UNCHECKED)
goto out;
check_nodes_props(c, dti, dt);
if (c->status == UNCHECKED)
c->status = PASSED;
TRACE(c, "\tCompleted, status %d", c->status);
out:
c->inprogress = false;
if ((c->status != PASSED) && (c->error))
error = true;
return error;
}
static inline void check_always_fail(struct check *c, struct dt_info *dti,
struct node *node)
{
FAIL(c, dti, "always_fail check");
}
static void check_is_string(struct check *c, struct dt_info *dti,
struct node *node)
{
struct property *prop;
char *propname = c->data;
prop = get_property(node, propname);
if (!prop)
return;
if (!data_is_one_string(prop->val))
FAIL(c, dti, "\"%s\" property in %s is not a string",
propname, node->fullpath);
}
static void check_is_cell(struct check *c, struct dt_info *dti,
struct node *node)
{
struct property *prop;
char *propname = c->data;
prop = get_property(node, propname);
if (!prop)
return;
if (prop->val.len != sizeof(cell_t))
FAIL(c, dti, "\"%s\" property in %s is not a single cell",
propname, node->fullpath);
}
static void check_duplicate_node_names(struct check *c, struct dt_info *dti,
struct node *node)
{
struct node *child, *child2;
for_each_child(node, child)
for (child2 = child->next_sibling;
child2;
child2 = child2->next_sibling)
if (streq(child->name, child2->name))
FAIL(c, dti, "Duplicate node name %s",
child->fullpath);
}
static void check_duplicate_property_names(struct check *c, struct dt_info *dti,
struct node *node)
{
struct property *prop, *prop2;
for_each_property(node, prop) {
for (prop2 = prop->next; prop2; prop2 = prop2->next) {
if (prop2->deleted)
continue;
if (streq(prop->name, prop2->name))
FAIL(c, dti, "Duplicate property name %s in %s",
prop->name, node->fullpath);
}
}
}
static void check_node_name_chars(struct check *c, struct dt_info *dti,
struct node *node)
{
int n = strspn(node->name, c->data);
if (n < strlen(node->name))
FAIL(c, dti, "Bad character '%c' in node %s",
node->name[n], node->fullpath);
}
static void check_node_name_chars_strict(struct check *c, struct dt_info *dti,
struct node *node)
{
int n = strspn(node->name, c->data);
if (n < node->basenamelen)
FAIL(c, dti, "Character '%c' not recommended in node %s",
node->name[n], node->fullpath);
}
static void check_node_name_format(struct check *c, struct dt_info *dti,
struct node *node)
{
if (strchr(get_unitname(node), '@'))
FAIL(c, dti, "Node %s has multiple '@' characters in name",
node->fullpath);
}
static void check_unit_address_vs_reg(struct check *c, struct dt_info *dti,
struct node *node)
{
const char *unitname = get_unitname(node);
struct property *prop = get_property(node, "reg");
if (!prop) {
prop = get_property(node, "ranges");
if (prop && !prop->val.len)
prop = NULL;
}
if (prop) {
if (!unitname[0])
FAIL(c, dti, "Node %s has a reg or ranges property, but no unit name",
node->fullpath);
} else {
if (unitname[0])
FAIL(c, dti, "Node %s has a unit name, but no reg property",
node->fullpath);
}
}
static void check_property_name_chars(struct check *c, struct dt_info *dti,
struct node *node)
{
struct property *prop;
for_each_property(node, prop) {
int n = strspn(prop->name, c->data);
if (n < strlen(prop->name))
FAIL(c, dti, "Bad character '%c' in property name \"%s\", node %s",
prop->name[n], prop->name, node->fullpath);
}
}
static void check_property_name_chars_strict(struct check *c,
struct dt_info *dti,
struct node *node)
{
struct property *prop;
for_each_property(node, prop) {
const char *name = prop->name;
int n = strspn(name, c->data);
if (n == strlen(prop->name))
continue;
if (streq(name, "device_type"))
continue;
if (name[n] == '#' && ((n == 0) || (name[n-1] == ','))) {
name += n + 1;
n = strspn(name, c->data);
}
if (n < strlen(name))
FAIL(c, dti, "Character '%c' not recommended in property name \"%s\", node %s",
name[n], prop->name, node->fullpath);
}
}
static void check_duplicate_label(struct check *c, struct dt_info *dti,
const char *label, struct node *node,
struct property *prop, struct marker *mark)
{
struct node *dt = dti->dt;
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
FAIL(c, dti, "Duplicate label '%s' on " DESCLABEL_FMT
" and " DESCLABEL_FMT,
label, DESCLABEL_ARGS(node, prop, mark),
DESCLABEL_ARGS(othernode, otherprop, othermark));
}
static void check_duplicate_label_node(struct check *c, struct dt_info *dti,
struct node *node)
{
struct label *l;
struct property *prop;
for_each_label(node->labels, l)
check_duplicate_label(c, dti, l->label, node, NULL, NULL);
for_each_property(node, prop) {
struct marker *m = prop->val.markers;
for_each_label(prop->labels, l)
check_duplicate_label(c, dti, l->label, node, prop, NULL);
for_each_marker_of_type(m, LABEL)
check_duplicate_label(c, dti, m->ref, node, prop, m);
}
}
static cell_t check_phandle_prop(struct check *c, struct dt_info *dti,
struct node *node, const char *propname)
{
struct node *root = dti->dt;
struct property *prop;
struct marker *m;
cell_t phandle;
prop = get_property(node, propname);
if (!prop)
return 0;
if (prop->val.len != sizeof(cell_t)) {
FAIL(c, dti, "%s has bad length (%d) %s property",
node->fullpath, prop->val.len, prop->name);
return 0;
}
m = prop->val.markers;
for_each_marker_of_type(m, REF_PHANDLE) {
assert(m->offset == 0);
if (node != get_node_by_ref(root, m->ref))
{
FAIL(c, dti, "%s in %s is a reference to another node",
prop->name, node->fullpath);
}
return 0;
}
phandle = propval_cell(prop);
if ((phandle == 0) || (phandle == -1)) {
FAIL(c, dti, "%s has bad value (0x%x) in %s property",
node->fullpath, phandle, prop->name);
return 0;
}
return phandle;
}
static void check_explicit_phandles(struct check *c, struct dt_info *dti,
struct node *node)
{
struct node *root = dti->dt;
struct node *other;
cell_t phandle, linux_phandle;
assert(!node->phandle);
phandle = check_phandle_prop(c, dti, node, "phandle");
linux_phandle = check_phandle_prop(c, dti, node, "linux,phandle");
if (!phandle && !linux_phandle)
return;
if (linux_phandle && phandle && (phandle != linux_phandle))
FAIL(c, dti, "%s has mismatching 'phandle' and 'linux,phandle'"
" properties", node->fullpath);
if (linux_phandle && !phandle)
phandle = linux_phandle;
other = get_node_by_phandle(root, phandle);
if (other && (other != node)) {
FAIL(c, dti, "%s has duplicated phandle 0x%x (seen before at %s)",
node->fullpath, phandle, other->fullpath);
return;
}
node->phandle = phandle;
}
static void check_name_properties(struct check *c, struct dt_info *dti,
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
FAIL(c, dti, "\"name\" property in %s is incorrect (\"%s\" instead"
" of base node name)", node->fullpath, prop->val.val);
} else {
*pp = prop->next;
free(prop->name);
data_free(prop->val);
free(prop);
}
}
static void fixup_phandle_references(struct check *c, struct dt_info *dti,
struct node *node)
{
struct node *dt = dti->dt;
struct property *prop;
for_each_property(node, prop) {
struct marker *m = prop->val.markers;
struct node *refnode;
cell_t phandle;
for_each_marker_of_type(m, REF_PHANDLE) {
assert(m->offset + sizeof(cell_t) <= prop->val.len);
refnode = get_node_by_ref(dt, m->ref);
if (! refnode) {
if (!(dti->dtsflags & DTSF_PLUGIN))
FAIL(c, dti, "Reference to non-existent node or "
"label \"%s\"\n", m->ref);
else
*((fdt32_t *)(prop->val.val + m->offset)) =
cpu_to_fdt32(0xffffffff);
continue;
}
phandle = get_node_phandle(dt, refnode);
*((fdt32_t *)(prop->val.val + m->offset)) = cpu_to_fdt32(phandle);
}
}
}
static void fixup_path_references(struct check *c, struct dt_info *dti,
struct node *node)
{
struct node *dt = dti->dt;
struct property *prop;
for_each_property(node, prop) {
struct marker *m = prop->val.markers;
struct node *refnode;
char *path;
for_each_marker_of_type(m, REF_PATH) {
assert(m->offset <= prop->val.len);
refnode = get_node_by_ref(dt, m->ref);
if (!refnode) {
FAIL(c, dti, "Reference to non-existent node or label \"%s\"\n",
m->ref);
continue;
}
path = refnode->fullpath;
prop->val = data_insert_at_marker(prop->val, m, path,
strlen(path) + 1);
}
}
}
static void fixup_addr_size_cells(struct check *c, struct dt_info *dti,
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
static void check_reg_format(struct check *c, struct dt_info *dti,
struct node *node)
{
struct property *prop;
int addr_cells, size_cells, entrylen;
prop = get_property(node, "reg");
if (!prop)
return;
if (!node->parent) {
FAIL(c, dti, "Root node has a \"reg\" property");
return;
}
if (prop->val.len == 0)
FAIL(c, dti, "\"reg\" property in %s is empty", node->fullpath);
addr_cells = node_addr_cells(node->parent);
size_cells = node_size_cells(node->parent);
entrylen = (addr_cells + size_cells) * sizeof(cell_t);
if (!entrylen || (prop->val.len % entrylen) != 0)
FAIL(c, dti, "\"reg\" property in %s has invalid length (%d bytes) "
"(#address-cells == %d, #size-cells == %d)",
node->fullpath, prop->val.len, addr_cells, size_cells);
}
static void check_ranges_format(struct check *c, struct dt_info *dti,
struct node *node)
{
struct property *prop;
int c_addr_cells, p_addr_cells, c_size_cells, p_size_cells, entrylen;
prop = get_property(node, "ranges");
if (!prop)
return;
if (!node->parent) {
FAIL(c, dti, "Root node has a \"ranges\" property");
return;
}
p_addr_cells = node_addr_cells(node->parent);
p_size_cells = node_size_cells(node->parent);
c_addr_cells = node_addr_cells(node);
c_size_cells = node_size_cells(node);
entrylen = (p_addr_cells + c_addr_cells + c_size_cells) * sizeof(cell_t);
if (prop->val.len == 0) {
if (p_addr_cells != c_addr_cells)
FAIL(c, dti, "%s has empty \"ranges\" property but its "
"#address-cells (%d) differs from %s (%d)",
node->fullpath, c_addr_cells, node->parent->fullpath,
p_addr_cells);
if (p_size_cells != c_size_cells)
FAIL(c, dti, "%s has empty \"ranges\" property but its "
"#size-cells (%d) differs from %s (%d)",
node->fullpath, c_size_cells, node->parent->fullpath,
p_size_cells);
} else if ((prop->val.len % entrylen) != 0) {
FAIL(c, dti, "\"ranges\" property in %s has invalid length (%d bytes) "
"(parent #address-cells == %d, child #address-cells == %d, "
"#size-cells == %d)", node->fullpath, prop->val.len,
p_addr_cells, c_addr_cells, c_size_cells);
}
}
static void check_pci_bridge(struct check *c, struct dt_info *dti, struct node *node)
{
struct property *prop;
cell_t *cells;
prop = get_property(node, "device_type");
if (!prop || !streq(prop->val.val, "pci"))
return;
node->bus = &pci_bus;
if (!strneq(node->name, "pci", node->basenamelen) &&
!strneq(node->name, "pcie", node->basenamelen))
FAIL(c, dti, "Node %s node name is not \"pci\" or \"pcie\"",
node->fullpath);
prop = get_property(node, "ranges");
if (!prop)
FAIL(c, dti, "Node %s missing ranges for PCI bridge (or not a bridge)",
node->fullpath);
if (node_addr_cells(node) != 3)
FAIL(c, dti, "Node %s incorrect #address-cells for PCI bridge",
node->fullpath);
if (node_size_cells(node) != 2)
FAIL(c, dti, "Node %s incorrect #size-cells for PCI bridge",
node->fullpath);
prop = get_property(node, "bus-range");
if (!prop) {
FAIL(c, dti, "Node %s missing bus-range for PCI bridge",
node->fullpath);
return;
}
if (prop->val.len != (sizeof(cell_t) * 2)) {
FAIL(c, dti, "Node %s bus-range must be 2 cells",
node->fullpath);
return;
}
cells = (cell_t *)prop->val.val;
if (fdt32_to_cpu(cells[0]) > fdt32_to_cpu(cells[1]))
FAIL(c, dti, "Node %s bus-range 1st cell must be less than or equal to 2nd cell",
node->fullpath);
if (fdt32_to_cpu(cells[1]) > 0xff)
FAIL(c, dti, "Node %s bus-range maximum bus number must be less than 256",
node->fullpath);
}
static void check_pci_device_bus_num(struct check *c, struct dt_info *dti, struct node *node)
{
struct property *prop;
unsigned int bus_num, min_bus, max_bus;
cell_t *cells;
if (!node->parent || (node->parent->bus != &pci_bus))
return;
prop = get_property(node, "reg");
if (!prop)
return;
cells = (cell_t *)prop->val.val;
bus_num = (fdt32_to_cpu(cells[0]) & 0x00ff0000) >> 16;
prop = get_property(node->parent, "bus-range");
if (!prop) {
min_bus = max_bus = 0;
} else {
cells = (cell_t *)prop->val.val;
min_bus = fdt32_to_cpu(cells[0]);
max_bus = fdt32_to_cpu(cells[0]);
}
if ((bus_num < min_bus) || (bus_num > max_bus))
FAIL(c, dti, "Node %s PCI bus number %d out of range, expected (%d - %d)",
node->fullpath, bus_num, min_bus, max_bus);
}
static void check_pci_device_reg(struct check *c, struct dt_info *dti, struct node *node)
{
struct property *prop;
const char *unitname = get_unitname(node);
char unit_addr[5];
unsigned int dev, func, reg;
cell_t *cells;
if (!node->parent || (node->parent->bus != &pci_bus))
return;
prop = get_property(node, "reg");
if (!prop) {
FAIL(c, dti, "Node %s missing PCI reg property", node->fullpath);
return;
}
cells = (cell_t *)prop->val.val;
if (cells[1] || cells[2])
FAIL(c, dti, "Node %s PCI reg config space address cells 2 and 3 must be 0",
node->fullpath);
reg = fdt32_to_cpu(cells[0]);
dev = (reg & 0xf800) >> 11;
func = (reg & 0x700) >> 8;
if (reg & 0xff000000)
FAIL(c, dti, "Node %s PCI reg address is not configuration space",
node->fullpath);
if (reg & 0x000000ff)
FAIL(c, dti, "Node %s PCI reg config space address register number must be 0",
node->fullpath);
if (func == 0) {
snprintf(unit_addr, sizeof(unit_addr), "%x", dev);
if (streq(unitname, unit_addr))
return;
}
snprintf(unit_addr, sizeof(unit_addr), "%x,%x", dev, func);
if (streq(unitname, unit_addr))
return;
FAIL(c, dti, "Node %s PCI unit address format error, expected \"%s\"",
node->fullpath, unit_addr);
}
static bool node_is_compatible(struct node *node, const char *compat)
{
struct property *prop;
const char *str, *end;
prop = get_property(node, "compatible");
if (!prop)
return false;
for (str = prop->val.val, end = str + prop->val.len; str < end;
str += strnlen(str, end - str) + 1) {
if (strneq(str, compat, end - str))
return true;
}
return false;
}
static void check_simple_bus_bridge(struct check *c, struct dt_info *dti, struct node *node)
{
if (node_is_compatible(node, "simple-bus"))
node->bus = &simple_bus;
}
static void check_simple_bus_reg(struct check *c, struct dt_info *dti, struct node *node)
{
struct property *prop;
const char *unitname = get_unitname(node);
char unit_addr[17];
unsigned int size;
uint64_t reg = 0;
cell_t *cells = NULL;
if (!node->parent || (node->parent->bus != &simple_bus))
return;
prop = get_property(node, "reg");
if (prop)
cells = (cell_t *)prop->val.val;
else {
prop = get_property(node, "ranges");
if (prop && prop->val.len)
cells = ((cell_t *)prop->val.val) + node_addr_cells(node);
}
if (!cells) {
if (node->parent->parent && !(node->bus == &simple_bus))
FAIL(c, dti, "Node %s missing or empty reg/ranges property", node->fullpath);
return;
}
size = node_addr_cells(node->parent);
while (size--)
reg = (reg << 32) | fdt32_to_cpu(*(cells++));
snprintf(unit_addr, sizeof(unit_addr), "%llx", (unsigned long long)reg);
if (!streq(unitname, unit_addr))
FAIL(c, dti, "Node %s simple-bus unit address format error, expected \"%s\"",
node->fullpath, unit_addr);
}
static void check_unit_address_format(struct check *c, struct dt_info *dti,
struct node *node)
{
const char *unitname = get_unitname(node);
if (node->parent && node->parent->bus)
return;
if (!unitname[0])
return;
if (!strncmp(unitname, "0x", 2)) {
FAIL(c, dti, "Node %s unit name should not have leading \"0x\"",
node->fullpath);
unitname += 2;
}
if (unitname[0] == '0' && isxdigit(unitname[1]))
FAIL(c, dti, "Node %s unit name should not have leading 0s",
node->fullpath);
}
static void check_avoid_default_addr_size(struct check *c, struct dt_info *dti,
struct node *node)
{
struct property *reg, *ranges;
if (!node->parent)
return;
reg = get_property(node, "reg");
ranges = get_property(node, "ranges");
if (!reg && !ranges)
return;
if (node->parent->addr_cells == -1)
FAIL(c, dti, "Relying on default #address-cells value for %s",
node->fullpath);
if (node->parent->size_cells == -1)
FAIL(c, dti, "Relying on default #size-cells value for %s",
node->fullpath);
}
static void check_obsolete_chosen_interrupt_controller(struct check *c,
struct dt_info *dti,
struct node *node)
{
struct node *dt = dti->dt;
struct node *chosen;
struct property *prop;
if (node != dt)
return;
chosen = get_node_by_path(dt, "/chosen");
if (!chosen)
return;
prop = get_property(chosen, "interrupt-controller");
if (prop)
FAIL(c, dti, "/chosen has obsolete \"interrupt-controller\" "
"property");
}
static void enable_warning_error(struct check *c, bool warn, bool error)
{
int i;
if ((warn && !c->warn) || (error && !c->error))
for (i = 0; i < c->num_prereqs; i++)
enable_warning_error(c->prereq[i], warn, error);
c->warn = c->warn || warn;
c->error = c->error || error;
}
static void disable_warning_error(struct check *c, bool warn, bool error)
{
int i;
if ((warn && c->warn) || (error && c->error)) {
for (i = 0; i < ARRAY_SIZE(check_table); i++) {
struct check *cc = check_table[i];
int j;
for (j = 0; j < cc->num_prereqs; j++)
if (cc->prereq[j] == c)
disable_warning_error(cc, warn, error);
}
}
c->warn = c->warn && !warn;
c->error = c->error && !error;
}
void parse_checks_option(bool warn, bool error, const char *arg)
{
int i;
const char *name = arg;
bool enable = true;
if ((strncmp(arg, "no-", 3) == 0)
|| (strncmp(arg, "no_", 3) == 0)) {
name = arg + 3;
enable = false;
}
for (i = 0; i < ARRAY_SIZE(check_table); i++) {
struct check *c = check_table[i];
if (streq(c->name, name)) {
if (enable)
enable_warning_error(c, warn, error);
else
disable_warning_error(c, warn, error);
return;
}
}
die("Unrecognized check name \"%s\"\n", name);
}
void process_checks(bool force, struct dt_info *dti)
{
int i;
int error = 0;
for (i = 0; i < ARRAY_SIZE(check_table); i++) {
struct check *c = check_table[i];
if (c->warn || c->error)
error = error || run_check(c, dti);
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
