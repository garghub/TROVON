static bool clk_requires_trigger(struct kona_clk *bcm_clk)
{
struct peri_clk_data *peri = bcm_clk->u.peri;
struct bcm_clk_sel *sel;
struct bcm_clk_div *div;
if (bcm_clk->type != bcm_clk_peri)
return false;
sel = &peri->sel;
if (sel->parent_count && selector_exists(sel))
return true;
div = &peri->div;
if (!divider_exists(div))
return false;
if (!divider_is_fixed(div))
return true;
div = &peri->pre_div;
return divider_exists(div) && !divider_is_fixed(div);
}
static bool peri_clk_data_offsets_valid(struct kona_clk *bcm_clk)
{
struct peri_clk_data *peri;
struct bcm_clk_gate *gate;
struct bcm_clk_div *div;
struct bcm_clk_sel *sel;
struct bcm_clk_trig *trig;
const char *name;
u32 range;
u32 limit;
BUG_ON(bcm_clk->type != bcm_clk_peri);
peri = bcm_clk->u.peri;
name = bcm_clk->name;
range = bcm_clk->ccu->range;
limit = range - sizeof(u32);
limit = round_down(limit, sizeof(u32));
gate = &peri->gate;
if (gate_exists(gate)) {
if (gate->offset > limit) {
pr_err("%s: bad gate offset for %s (%u > %u)\n",
__func__, name, gate->offset, limit);
return false;
}
}
div = &peri->div;
if (divider_exists(div)) {
if (div->u.s.offset > limit) {
pr_err("%s: bad divider offset for %s (%u > %u)\n",
__func__, name, div->u.s.offset, limit);
return false;
}
}
div = &peri->pre_div;
if (divider_exists(div)) {
if (div->u.s.offset > limit) {
pr_err("%s: bad pre-divider offset for %s "
"(%u > %u)\n",
__func__, name, div->u.s.offset, limit);
return false;
}
}
sel = &peri->sel;
if (selector_exists(sel)) {
if (sel->offset > limit) {
pr_err("%s: bad selector offset for %s (%u > %u)\n",
__func__, name, sel->offset, limit);
return false;
}
}
trig = &peri->trig;
if (trigger_exists(trig)) {
if (trig->offset > limit) {
pr_err("%s: bad trigger offset for %s (%u > %u)\n",
__func__, name, trig->offset, limit);
return false;
}
}
trig = &peri->pre_trig;
if (trigger_exists(trig)) {
if (trig->offset > limit) {
pr_err("%s: bad pre-trigger offset for %s (%u > %u)\n",
__func__, name, trig->offset, limit);
return false;
}
}
return true;
}
static bool bit_posn_valid(u32 bit_posn, const char *field_name,
const char *clock_name)
{
u32 limit = BITS_PER_BYTE * sizeof(u32) - 1;
if (bit_posn > limit) {
pr_err("%s: bad %s bit for %s (%u > %u)\n", __func__,
field_name, clock_name, bit_posn, limit);
return false;
}
return true;
}
static bool bitfield_valid(u32 shift, u32 width, const char *field_name,
const char *clock_name)
{
u32 limit = BITS_PER_BYTE * sizeof(u32);
if (!width) {
pr_err("%s: bad %s field width 0 for %s\n", __func__,
field_name, clock_name);
return false;
}
if (shift + width > limit) {
pr_err("%s: bad %s for %s (%u + %u > %u)\n", __func__,
field_name, clock_name, shift, width, limit);
return false;
}
return true;
}
static bool gate_valid(struct bcm_clk_gate *gate, const char *field_name,
const char *clock_name)
{
if (!bit_posn_valid(gate->status_bit, "gate status", clock_name))
return false;
if (gate_is_sw_controllable(gate)) {
if (!bit_posn_valid(gate->en_bit, "gate enable", clock_name))
return false;
if (gate_is_hw_controllable(gate)) {
if (!bit_posn_valid(gate->hw_sw_sel_bit,
"gate hw/sw select",
clock_name))
return false;
}
} else {
BUG_ON(!gate_is_hw_controllable(gate));
}
return true;
}
static bool sel_valid(struct bcm_clk_sel *sel, const char *field_name,
const char *clock_name)
{
if (!bitfield_valid(sel->shift, sel->width, field_name, clock_name))
return false;
if (sel->parent_count) {
u32 max_sel;
u32 limit;
max_sel = sel->parent_sel[sel->parent_count - 1];
limit = (1 << sel->width) - 1;
if (max_sel > limit) {
pr_err("%s: bad selector for %s "
"(%u needs > %u bits)\n",
__func__, clock_name, max_sel,
sel->width);
return false;
}
} else {
pr_warn("%s: ignoring selector for %s (no parents)\n",
__func__, clock_name);
selector_clear_exists(sel);
kfree(sel->parent_sel);
sel->parent_sel = NULL;
}
return true;
}
static bool div_valid(struct bcm_clk_div *div, const char *field_name,
const char *clock_name)
{
if (divider_is_fixed(div)) {
if (div->u.fixed == 0) {
pr_err("%s: bad %s fixed value 0 for %s\n", __func__,
field_name, clock_name);
return false;
}
return true;
}
if (!bitfield_valid(div->u.s.shift, div->u.s.width,
field_name, clock_name))
return false;
if (divider_has_fraction(div))
if (div->u.s.frac_width > div->u.s.width) {
pr_warn("%s: bad %s fraction width for %s (%u > %u)\n",
__func__, field_name, clock_name,
div->u.s.frac_width, div->u.s.width);
return false;
}
return true;
}
static bool kona_dividers_valid(struct kona_clk *bcm_clk)
{
struct peri_clk_data *peri = bcm_clk->u.peri;
struct bcm_clk_div *div;
struct bcm_clk_div *pre_div;
u32 limit;
BUG_ON(bcm_clk->type != bcm_clk_peri);
if (!divider_exists(&peri->div) || !divider_exists(&peri->pre_div))
return true;
div = &peri->div;
pre_div = &peri->pre_div;
if (divider_is_fixed(div) || divider_is_fixed(pre_div))
return true;
limit = BITS_PER_BYTE * sizeof(u32);
return div->u.s.frac_width + pre_div->u.s.frac_width <= limit;
}
static bool trig_valid(struct bcm_clk_trig *trig, const char *field_name,
const char *clock_name)
{
return bit_posn_valid(trig->bit, field_name, clock_name);
}
static bool
peri_clk_data_valid(struct kona_clk *bcm_clk)
{
struct peri_clk_data *peri;
struct bcm_clk_gate *gate;
struct bcm_clk_sel *sel;
struct bcm_clk_div *div;
struct bcm_clk_div *pre_div;
struct bcm_clk_trig *trig;
const char *name;
BUG_ON(bcm_clk->type != bcm_clk_peri);
if (!peri_clk_data_offsets_valid(bcm_clk))
return false;
peri = bcm_clk->u.peri;
name = bcm_clk->name;
gate = &peri->gate;
if (gate_exists(gate) && !gate_valid(gate, "gate", name))
return false;
sel = &peri->sel;
if (selector_exists(sel)) {
if (!sel_valid(sel, "selector", name))
return false;
} else if (sel->parent_count > 1) {
pr_err("%s: multiple parents but no selector for %s\n",
__func__, name);
return false;
}
div = &peri->div;
pre_div = &peri->pre_div;
if (divider_exists(div)) {
if (!div_valid(div, "divider", name))
return false;
if (divider_exists(pre_div))
if (!div_valid(pre_div, "pre-divider", name))
return false;
} else if (divider_exists(pre_div)) {
pr_err("%s: pre-divider but no divider for %s\n", __func__,
name);
return false;
}
trig = &peri->trig;
if (trigger_exists(trig)) {
if (!trig_valid(trig, "trigger", name))
return false;
if (trigger_exists(&peri->pre_trig)) {
if (!trig_valid(trig, "pre-trigger", name)) {
return false;
}
}
if (!clk_requires_trigger(bcm_clk)) {
pr_warn("%s: ignoring trigger for %s (not needed)\n",
__func__, name);
trigger_clear_exists(trig);
}
} else if (trigger_exists(&peri->pre_trig)) {
pr_err("%s: pre-trigger but no trigger for %s\n", __func__,
name);
return false;
} else if (clk_requires_trigger(bcm_clk)) {
pr_err("%s: required trigger missing for %s\n", __func__,
name);
return false;
}
return kona_dividers_valid(bcm_clk);
}
static bool kona_clk_valid(struct kona_clk *bcm_clk)
{
switch (bcm_clk->type) {
case bcm_clk_peri:
if (!peri_clk_data_valid(bcm_clk))
return false;
break;
default:
pr_err("%s: unrecognized clock type (%d)\n", __func__,
(int)bcm_clk->type);
return false;
}
return true;
}
static u32 *parent_process(const char *clocks[],
u32 *count, const char ***names)
{
static const char **parent_names;
static u32 *parent_sel;
const char **clock;
u32 parent_count;
u32 bad_count = 0;
u32 orig_count;
u32 i;
u32 j;
*count = 0;
*names = NULL;
if (!clocks)
return NULL;
for (clock = clocks; *clock; clock++)
if (*clock == BAD_CLK_NAME)
bad_count++;
orig_count = (u32)(clock - clocks);
parent_count = orig_count - bad_count;
if (!parent_count)
return NULL;
if (parent_count > PARENT_COUNT_MAX) {
pr_err("%s: too many parents (%u > %u)\n", __func__,
parent_count, PARENT_COUNT_MAX);
return ERR_PTR(-EINVAL);
}
parent_names = kmalloc(parent_count * sizeof(parent_names), GFP_KERNEL);
if (!parent_names) {
pr_err("%s: error allocating %u parent names\n", __func__,
parent_count);
return ERR_PTR(-ENOMEM);
}
parent_sel = kmalloc(parent_count * sizeof(*parent_sel), GFP_KERNEL);
if (!parent_sel) {
pr_err("%s: error allocating %u parent selectors\n", __func__,
parent_count);
kfree(parent_names);
return ERR_PTR(-ENOMEM);
}
for (i = 0, j = 0; i < orig_count; i++) {
if (clocks[i] != BAD_CLK_NAME) {
parent_names[j] = clocks[i];
parent_sel[j] = i;
j++;
}
}
*names = parent_names;
*count = parent_count;
return parent_sel;
}
static int
clk_sel_setup(const char **clocks, struct bcm_clk_sel *sel,
struct clk_init_data *init_data)
{
const char **parent_names = NULL;
u32 parent_count = 0;
u32 *parent_sel;
parent_sel = parent_process(clocks, &parent_count, &parent_names);
if (IS_ERR(parent_sel)) {
int ret = PTR_ERR(parent_sel);
pr_err("%s: error processing parent clocks for %s (%d)\n",
__func__, init_data->name, ret);
return ret;
}
init_data->parent_names = parent_names;
init_data->num_parents = parent_count;
sel->parent_count = parent_count;
sel->parent_sel = parent_sel;
return 0;
}
static void clk_sel_teardown(struct bcm_clk_sel *sel,
struct clk_init_data *init_data)
{
kfree(sel->parent_sel);
sel->parent_sel = NULL;
sel->parent_count = 0;
init_data->num_parents = 0;
kfree(init_data->parent_names);
init_data->parent_names = NULL;
}
static void peri_clk_teardown(struct peri_clk_data *data,
struct clk_init_data *init_data)
{
clk_sel_teardown(&data->sel, init_data);
init_data->ops = NULL;
}
static int peri_clk_setup(struct ccu_data *ccu, struct peri_clk_data *data,
struct clk_init_data *init_data)
{
init_data->ops = &kona_peri_clk_ops;
init_data->flags = CLK_IGNORE_UNUSED;
return clk_sel_setup(data->clocks, &data->sel, init_data);
}
static void bcm_clk_teardown(struct kona_clk *bcm_clk)
{
switch (bcm_clk->type) {
case bcm_clk_peri:
peri_clk_teardown(bcm_clk->u.data, &bcm_clk->init_data);
break;
default:
break;
}
bcm_clk->u.data = NULL;
bcm_clk->type = bcm_clk_none;
}
static void kona_clk_teardown(struct clk *clk)
{
struct clk_hw *hw;
struct kona_clk *bcm_clk;
if (!clk)
return;
hw = __clk_get_hw(clk);
if (!hw) {
pr_err("%s: clk %p has null hw pointer\n", __func__, clk);
return;
}
clk_unregister(clk);
bcm_clk = to_kona_clk(hw);
bcm_clk_teardown(bcm_clk);
}
struct clk *kona_clk_setup(struct ccu_data *ccu, const char *name,
enum bcm_clk_type type, void *data)
{
struct kona_clk *bcm_clk;
struct clk_init_data *init_data;
struct clk *clk = NULL;
bcm_clk = kzalloc(sizeof(*bcm_clk), GFP_KERNEL);
if (!bcm_clk) {
pr_err("%s: failed to allocate bcm_clk for %s\n", __func__,
name);
return NULL;
}
bcm_clk->ccu = ccu;
bcm_clk->name = name;
init_data = &bcm_clk->init_data;
init_data->name = name;
switch (type) {
case bcm_clk_peri:
if (peri_clk_setup(ccu, data, init_data))
goto out_free;
break;
default:
data = NULL;
break;
}
bcm_clk->type = type;
bcm_clk->u.data = data;
if (!kona_clk_valid(bcm_clk)) {
pr_err("%s: clock data invalid for %s\n", __func__, name);
goto out_teardown;
}
bcm_clk->hw.init = init_data;
clk = clk_register(NULL, &bcm_clk->hw);
if (IS_ERR(clk)) {
pr_err("%s: error registering clock %s (%ld)\n", __func__,
name, PTR_ERR(clk));
goto out_teardown;
}
BUG_ON(!clk);
return clk;
out_teardown:
bcm_clk_teardown(bcm_clk);
out_free:
kfree(bcm_clk);
return NULL;
}
static void ccu_clks_teardown(struct ccu_data *ccu)
{
u32 i;
for (i = 0; i < ccu->data.clk_num; i++)
kona_clk_teardown(ccu->data.clks[i]);
kfree(ccu->data.clks);
}
static void kona_ccu_teardown(struct ccu_data *ccu)
{
if (!ccu)
return;
if (!ccu->base)
goto done;
of_clk_del_provider(ccu->node);
ccu_clks_teardown(ccu);
list_del(&ccu->links);
of_node_put(ccu->node);
iounmap(ccu->base);
done:
kfree(ccu->name);
kfree(ccu);
}
void __init kona_dt_ccu_setup(struct device_node *node,
int (*ccu_clks_setup)(struct ccu_data *))
{
struct ccu_data *ccu;
struct resource res = { 0 };
resource_size_t range;
int ret;
ccu = kzalloc(sizeof(*ccu), GFP_KERNEL);
if (ccu)
ccu->name = kstrdup(node->name, GFP_KERNEL);
if (!ccu || !ccu->name) {
pr_err("%s: unable to allocate CCU struct for %s\n",
__func__, node->name);
kfree(ccu);
return;
}
ret = of_address_to_resource(node, 0, &res);
if (ret) {
pr_err("%s: no valid CCU registers found for %s\n", __func__,
node->name);
goto out_err;
}
range = resource_size(&res);
if (range > (resource_size_t)U32_MAX) {
pr_err("%s: address range too large for %s\n", __func__,
node->name);
goto out_err;
}
ccu->range = (u32)range;
ccu->base = ioremap(res.start, ccu->range);
if (!ccu->base) {
pr_err("%s: unable to map CCU registers for %s\n", __func__,
node->name);
goto out_err;
}
spin_lock_init(&ccu->lock);
INIT_LIST_HEAD(&ccu->links);
ccu->node = of_node_get(node);
list_add_tail(&ccu->links, &ccu_list);
if (ccu_clks_setup(ccu))
goto out_err;
ret = of_clk_add_provider(node, of_clk_src_onecell_get, &ccu->data);
if (ret) {
pr_err("%s: error adding ccu %s as provider (%d)\n", __func__,
node->name, ret);
goto out_err;
}
if (!kona_ccu_init(ccu))
pr_err("Broadcom %s initialization had errors\n", node->name);
return;
out_err:
kona_ccu_teardown(ccu);
pr_err("Broadcom %s setup aborted\n", node->name);
}
