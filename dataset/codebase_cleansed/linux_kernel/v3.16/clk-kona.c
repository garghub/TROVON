static inline u32 bitfield_mask(u32 shift, u32 width)
{
return ((1 << width) - 1) << shift;
}
static inline u32 bitfield_extract(u32 reg_val, u32 shift, u32 width)
{
return (reg_val & bitfield_mask(shift, width)) >> shift;
}
static inline u32 bitfield_replace(u32 reg_val, u32 shift, u32 width, u32 val)
{
u32 mask = bitfield_mask(shift, width);
return (reg_val & ~mask) | (val << shift);
}
u64 do_div_round_closest(u64 dividend, unsigned long divisor)
{
u64 result;
result = dividend + ((u64)divisor >> 1);
(void)do_div(result, divisor);
return result;
}
static inline u64 scaled_div_value(struct bcm_clk_div *div, u32 reg_div)
{
return (u64)reg_div + ((u64)1 << div->u.s.frac_width);
}
u64 scaled_div_build(struct bcm_clk_div *div, u32 div_value, u32 billionths)
{
u64 combined;
BUG_ON(!div_value);
BUG_ON(billionths >= BILLION);
combined = (u64)div_value * BILLION + billionths;
combined <<= div->u.s.frac_width;
return do_div_round_closest(combined, BILLION);
}
static inline u64
scaled_div_min(struct bcm_clk_div *div)
{
if (divider_is_fixed(div))
return (u64)div->u.fixed;
return scaled_div_value(div, 0);
}
u64 scaled_div_max(struct bcm_clk_div *div)
{
u32 reg_div;
if (divider_is_fixed(div))
return (u64)div->u.fixed;
reg_div = ((u32)1 << div->u.s.width) - 1;
return scaled_div_value(div, reg_div);
}
static inline u32
divider(struct bcm_clk_div *div, u64 scaled_div)
{
BUG_ON(scaled_div < scaled_div_min(div));
BUG_ON(scaled_div > scaled_div_max(div));
return (u32)(scaled_div - ((u64)1 << div->u.s.frac_width));
}
static inline u64
scale_rate(struct bcm_clk_div *div, u32 rate)
{
if (divider_is_fixed(div))
return (u64)rate;
return (u64)rate << div->u.s.frac_width;
}
static inline u32 __ccu_read(struct ccu_data *ccu, u32 reg_offset)
{
return readl(ccu->base + reg_offset);
}
static inline void
__ccu_write(struct ccu_data *ccu, u32 reg_offset, u32 reg_val)
{
writel(reg_val, ccu->base + reg_offset);
}
static inline unsigned long ccu_lock(struct ccu_data *ccu)
{
unsigned long flags;
spin_lock_irqsave(&ccu->lock, flags);
return flags;
}
static inline void ccu_unlock(struct ccu_data *ccu, unsigned long flags)
{
spin_unlock_irqrestore(&ccu->lock, flags);
}
static inline void __ccu_write_enable(struct ccu_data *ccu)
{
if (ccu->write_enabled) {
pr_err("%s: access already enabled for %s\n", __func__,
ccu->name);
return;
}
ccu->write_enabled = true;
__ccu_write(ccu, 0, CCU_ACCESS_PASSWORD | 1);
}
static inline void __ccu_write_disable(struct ccu_data *ccu)
{
if (!ccu->write_enabled) {
pr_err("%s: access wasn't enabled for %s\n", __func__,
ccu->name);
return;
}
__ccu_write(ccu, 0, CCU_ACCESS_PASSWORD);
ccu->write_enabled = false;
}
static inline bool
__ccu_wait_bit(struct ccu_data *ccu, u32 reg_offset, u32 bit, bool want)
{
unsigned int tries;
u32 bit_mask = 1 << bit;
for (tries = 0; tries < CLK_GATE_DELAY_LOOP; tries++) {
u32 val;
bool bit_val;
val = __ccu_read(ccu, reg_offset);
bit_val = (val & bit_mask) != 0;
if (bit_val == want)
return true;
udelay(1);
}
pr_warn("%s: %s/0x%04x bit %u was never %s\n", __func__,
ccu->name, reg_offset, bit, want ? "set" : "clear");
return false;
}
static bool __ccu_policy_engine_start(struct ccu_data *ccu, bool sync)
{
struct bcm_policy_ctl *control = &ccu->policy.control;
u32 offset;
u32 go_bit;
u32 mask;
bool ret;
if (!policy_ctl_exists(control))
return true;
offset = control->offset;
go_bit = control->go_bit;
ret = __ccu_wait_bit(ccu, offset, go_bit, false);
if (!ret) {
pr_err("%s: ccu %s policy engine wouldn't go idle\n",
__func__, ccu->name);
return false;
}
mask = (u32)1 << go_bit;
if (sync)
mask |= 1 << control->atl_bit;
else
mask |= 1 << control->ac_bit;
__ccu_write(ccu, offset, mask);
ret = __ccu_wait_bit(ccu, offset, go_bit, false);
if (!ret)
pr_err("%s: ccu %s policy engine never started\n",
__func__, ccu->name);
return ret;
}
static bool __ccu_policy_engine_stop(struct ccu_data *ccu)
{
struct bcm_lvm_en *enable = &ccu->policy.enable;
u32 offset;
u32 enable_bit;
bool ret;
if (!policy_lvm_en_exists(enable))
return true;
offset = enable->offset;
enable_bit = enable->bit;
ret = __ccu_wait_bit(ccu, offset, enable_bit, false);
if (!ret) {
pr_err("%s: ccu %s policy engine already stopped\n",
__func__, ccu->name);
return false;
}
__ccu_write(ccu, offset, (u32)1 << enable_bit);
ret = __ccu_wait_bit(ccu, offset, enable_bit, false);
if (!ret)
pr_err("%s: ccu %s policy engine never stopped\n",
__func__, ccu->name);
return ret;
}
static bool policy_init(struct ccu_data *ccu, struct bcm_clk_policy *policy)
{
u32 offset;
u32 mask;
int i;
bool ret;
if (!policy_exists(policy))
return true;
if (!__ccu_policy_engine_stop(ccu)) {
pr_err("%s: unable to stop CCU %s policy engine\n",
__func__, ccu->name);
return false;
}
offset = policy->offset;
mask = (u32)1 << policy->bit;
for (i = 0; i < CCU_POLICY_COUNT; i++) {
u32 reg_val;
reg_val = __ccu_read(ccu, offset);
reg_val |= mask;
__ccu_write(ccu, offset, reg_val);
offset += sizeof(u32);
}
ret = __ccu_policy_engine_start(ccu, true);
if (!ret)
pr_err("%s: unable to restart CCU %s policy engine\n",
__func__, ccu->name);
return ret;
}
static bool
__is_clk_gate_enabled(struct ccu_data *ccu, struct bcm_clk_gate *gate)
{
u32 bit_mask;
u32 reg_val;
if (!gate_exists(gate))
return true;
bit_mask = 1 << gate->status_bit;
reg_val = __ccu_read(ccu, gate->offset);
return (reg_val & bit_mask) != 0;
}
static bool
is_clk_gate_enabled(struct ccu_data *ccu, struct bcm_clk_gate *gate)
{
long flags;
bool ret;
if (!gate_exists(gate))
return true;
flags = ccu_lock(ccu);
ret = __is_clk_gate_enabled(ccu, gate);
ccu_unlock(ccu, flags);
return ret;
}
static bool
__gate_commit(struct ccu_data *ccu, struct bcm_clk_gate *gate)
{
u32 reg_val;
u32 mask;
bool enabled = false;
BUG_ON(!gate_exists(gate));
if (!gate_is_sw_controllable(gate))
return true;
reg_val = __ccu_read(ccu, gate->offset);
if (gate_is_hw_controllable(gate)) {
mask = (u32)1 << gate->hw_sw_sel_bit;
if (gate_is_sw_managed(gate))
reg_val |= mask;
else
reg_val &= ~mask;
}
mask = (u32)1 << gate->en_bit;
if (gate_is_sw_managed(gate) && (enabled = gate_is_enabled(gate)) &&
!gate_is_no_disable(gate))
reg_val |= mask;
else
reg_val &= ~mask;
__ccu_write(ccu, gate->offset, reg_val);
if (!gate_is_sw_managed(gate))
return true;
return __ccu_wait_bit(ccu, gate->offset, gate->status_bit, enabled);
}
static bool gate_init(struct ccu_data *ccu, struct bcm_clk_gate *gate)
{
if (!gate_exists(gate))
return true;
return __gate_commit(ccu, gate);
}
static bool
__clk_gate(struct ccu_data *ccu, struct bcm_clk_gate *gate, bool enable)
{
bool ret;
if (!gate_exists(gate) || !gate_is_sw_managed(gate))
return true;
if (!enable && gate_is_no_disable(gate)) {
pr_warn("%s: invalid gate disable request (ignoring)\n",
__func__);
return true;
}
if (enable == gate_is_enabled(gate))
return true;
gate_flip_enabled(gate);
ret = __gate_commit(ccu, gate);
if (!ret)
gate_flip_enabled(gate);
return ret;
}
static int clk_gate(struct ccu_data *ccu, const char *name,
struct bcm_clk_gate *gate, bool enable)
{
unsigned long flags;
bool success;
if (!gate_exists(gate) || !gate_is_sw_managed(gate))
return 0;
if (!enable && gate_is_no_disable(gate))
return 0;
flags = ccu_lock(ccu);
__ccu_write_enable(ccu);
success = __clk_gate(ccu, gate, enable);
__ccu_write_disable(ccu);
ccu_unlock(ccu, flags);
if (success)
return 0;
pr_err("%s: failed to %s gate for %s\n", __func__,
enable ? "enable" : "disable", name);
return -EIO;
}
static bool hyst_init(struct ccu_data *ccu, struct bcm_clk_hyst *hyst)
{
u32 offset;
u32 reg_val;
u32 mask;
if (!hyst_exists(hyst))
return true;
offset = hyst->offset;
mask = (u32)1 << hyst->en_bit;
mask |= (u32)1 << hyst->val_bit;
reg_val = __ccu_read(ccu, offset);
reg_val |= mask;
__ccu_write(ccu, offset, reg_val);
return true;
}
static bool __clk_trigger(struct ccu_data *ccu, struct bcm_clk_trig *trig)
{
__ccu_write(ccu, trig->offset, 1 << trig->bit);
return __ccu_wait_bit(ccu, trig->offset, trig->bit, false);
}
static u64 divider_read_scaled(struct ccu_data *ccu, struct bcm_clk_div *div)
{
unsigned long flags;
u32 reg_val;
u32 reg_div;
if (divider_is_fixed(div))
return (u64)div->u.fixed;
flags = ccu_lock(ccu);
reg_val = __ccu_read(ccu, div->u.s.offset);
ccu_unlock(ccu, flags);
reg_div = bitfield_extract(reg_val, div->u.s.shift, div->u.s.width);
return scaled_div_value(div, reg_div);
}
static int __div_commit(struct ccu_data *ccu, struct bcm_clk_gate *gate,
struct bcm_clk_div *div, struct bcm_clk_trig *trig)
{
bool enabled;
u32 reg_div;
u32 reg_val;
int ret = 0;
BUG_ON(divider_is_fixed(div));
if (div->u.s.scaled_div == BAD_SCALED_DIV_VALUE) {
reg_val = __ccu_read(ccu, div->u.s.offset);
reg_div = bitfield_extract(reg_val, div->u.s.shift,
div->u.s.width);
div->u.s.scaled_div = scaled_div_value(div, reg_div);
return 0;
}
reg_div = divider(div, div->u.s.scaled_div);
enabled = __is_clk_gate_enabled(ccu, gate);
if (!enabled && !__clk_gate(ccu, gate, true)) {
ret = -ENXIO;
goto out;
}
reg_val = __ccu_read(ccu, div->u.s.offset);
reg_val = bitfield_replace(reg_val, div->u.s.shift, div->u.s.width,
reg_div);
__ccu_write(ccu, div->u.s.offset, reg_val);
if (!__clk_trigger(ccu, trig))
ret = -EIO;
if (!enabled && !__clk_gate(ccu, gate, false))
ret = ret ? ret : -ENXIO;
out:
return ret;
}
static bool div_init(struct ccu_data *ccu, struct bcm_clk_gate *gate,
struct bcm_clk_div *div, struct bcm_clk_trig *trig)
{
if (!divider_exists(div) || divider_is_fixed(div))
return true;
return !__div_commit(ccu, gate, div, trig);
}
static int divider_write(struct ccu_data *ccu, struct bcm_clk_gate *gate,
struct bcm_clk_div *div, struct bcm_clk_trig *trig,
u64 scaled_div)
{
unsigned long flags;
u64 previous;
int ret;
BUG_ON(divider_is_fixed(div));
previous = div->u.s.scaled_div;
if (previous == scaled_div)
return 0;
div->u.s.scaled_div = scaled_div;
flags = ccu_lock(ccu);
__ccu_write_enable(ccu);
ret = __div_commit(ccu, gate, div, trig);
__ccu_write_disable(ccu);
ccu_unlock(ccu, flags);
if (ret)
div->u.s.scaled_div = previous;
return ret;
}
static unsigned long clk_recalc_rate(struct ccu_data *ccu,
struct bcm_clk_div *div, struct bcm_clk_div *pre_div,
unsigned long parent_rate)
{
u64 scaled_parent_rate;
u64 scaled_div;
u64 result;
if (!divider_exists(div))
return parent_rate;
if (parent_rate > (unsigned long)LONG_MAX)
return 0;
if (pre_div && divider_exists(pre_div)) {
u64 scaled_rate;
scaled_rate = scale_rate(pre_div, parent_rate);
scaled_rate = scale_rate(div, scaled_rate);
scaled_div = divider_read_scaled(ccu, pre_div);
scaled_parent_rate = do_div_round_closest(scaled_rate,
scaled_div);
} else {
scaled_parent_rate = scale_rate(div, parent_rate);
}
scaled_div = divider_read_scaled(ccu, div);
result = do_div_round_closest(scaled_parent_rate, scaled_div);
return (unsigned long)result;
}
static long round_rate(struct ccu_data *ccu, struct bcm_clk_div *div,
struct bcm_clk_div *pre_div,
unsigned long rate, unsigned long parent_rate,
u64 *scaled_div)
{
u64 scaled_parent_rate;
u64 min_scaled_div;
u64 max_scaled_div;
u64 best_scaled_div;
u64 result;
BUG_ON(!divider_exists(div));
BUG_ON(!rate);
BUG_ON(parent_rate > (u64)LONG_MAX);
if (divider_exists(pre_div)) {
u64 scaled_rate;
u64 scaled_pre_div;
scaled_rate = scale_rate(pre_div, parent_rate);
scaled_rate = scale_rate(div, scaled_rate);
scaled_pre_div = divider_read_scaled(ccu, pre_div);
scaled_parent_rate = do_div_round_closest(scaled_rate,
scaled_pre_div);
} else {
scaled_parent_rate = scale_rate(div, parent_rate);
}
if (!divider_is_fixed(div)) {
best_scaled_div = do_div_round_closest(scaled_parent_rate,
rate);
min_scaled_div = scaled_div_min(div);
max_scaled_div = scaled_div_max(div);
if (best_scaled_div > max_scaled_div)
best_scaled_div = max_scaled_div;
else if (best_scaled_div < min_scaled_div)
best_scaled_div = min_scaled_div;
} else {
best_scaled_div = divider_read_scaled(ccu, div);
}
result = do_div_round_closest(scaled_parent_rate, best_scaled_div);
if (scaled_div)
*scaled_div = best_scaled_div;
return (long)result;
}
static u8 parent_index(struct bcm_clk_sel *sel, u8 parent_sel)
{
u8 i;
BUG_ON(sel->parent_count > (u32)U8_MAX);
for (i = 0; i < sel->parent_count; i++)
if (sel->parent_sel[i] == parent_sel)
return i;
return BAD_CLK_INDEX;
}
static u8 selector_read_index(struct ccu_data *ccu, struct bcm_clk_sel *sel)
{
unsigned long flags;
u32 reg_val;
u32 parent_sel;
u8 index;
if (!selector_exists(sel))
return 0;
flags = ccu_lock(ccu);
reg_val = __ccu_read(ccu, sel->offset);
ccu_unlock(ccu, flags);
parent_sel = bitfield_extract(reg_val, sel->shift, sel->width);
index = parent_index(sel, parent_sel);
if (index == BAD_CLK_INDEX)
pr_err("%s: out-of-range parent selector %u (%s 0x%04x)\n",
__func__, parent_sel, ccu->name, sel->offset);
return index;
}
static int
__sel_commit(struct ccu_data *ccu, struct bcm_clk_gate *gate,
struct bcm_clk_sel *sel, struct bcm_clk_trig *trig)
{
u32 parent_sel;
u32 reg_val;
bool enabled;
int ret = 0;
BUG_ON(!selector_exists(sel));
if (sel->clk_index == BAD_CLK_INDEX) {
u8 index;
reg_val = __ccu_read(ccu, sel->offset);
parent_sel = bitfield_extract(reg_val, sel->shift, sel->width);
index = parent_index(sel, parent_sel);
if (index == BAD_CLK_INDEX)
return -EINVAL;
sel->clk_index = index;
return 0;
}
BUG_ON((u32)sel->clk_index >= sel->parent_count);
parent_sel = sel->parent_sel[sel->clk_index];
enabled = __is_clk_gate_enabled(ccu, gate);
if (!enabled && !__clk_gate(ccu, gate, true))
return -ENXIO;
reg_val = __ccu_read(ccu, sel->offset);
reg_val = bitfield_replace(reg_val, sel->shift, sel->width, parent_sel);
__ccu_write(ccu, sel->offset, reg_val);
if (!__clk_trigger(ccu, trig))
ret = -EIO;
if (!enabled && !__clk_gate(ccu, gate, false))
ret = ret ? ret : -ENXIO;
return ret;
}
static bool sel_init(struct ccu_data *ccu, struct bcm_clk_gate *gate,
struct bcm_clk_sel *sel, struct bcm_clk_trig *trig)
{
if (!selector_exists(sel))
return true;
return !__sel_commit(ccu, gate, sel, trig);
}
static int selector_write(struct ccu_data *ccu, struct bcm_clk_gate *gate,
struct bcm_clk_sel *sel, struct bcm_clk_trig *trig,
u8 index)
{
unsigned long flags;
u8 previous;
int ret;
previous = sel->clk_index;
if (previous == index)
return 0;
sel->clk_index = index;
flags = ccu_lock(ccu);
__ccu_write_enable(ccu);
ret = __sel_commit(ccu, gate, sel, trig);
__ccu_write_disable(ccu);
ccu_unlock(ccu, flags);
if (ret)
sel->clk_index = previous;
return ret;
}
static int kona_peri_clk_enable(struct clk_hw *hw)
{
struct kona_clk *bcm_clk = to_kona_clk(hw);
struct bcm_clk_gate *gate = &bcm_clk->u.peri->gate;
return clk_gate(bcm_clk->ccu, bcm_clk->init_data.name, gate, true);
}
static void kona_peri_clk_disable(struct clk_hw *hw)
{
struct kona_clk *bcm_clk = to_kona_clk(hw);
struct bcm_clk_gate *gate = &bcm_clk->u.peri->gate;
(void)clk_gate(bcm_clk->ccu, bcm_clk->init_data.name, gate, false);
}
static int kona_peri_clk_is_enabled(struct clk_hw *hw)
{
struct kona_clk *bcm_clk = to_kona_clk(hw);
struct bcm_clk_gate *gate = &bcm_clk->u.peri->gate;
return is_clk_gate_enabled(bcm_clk->ccu, gate) ? 1 : 0;
}
static unsigned long kona_peri_clk_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct kona_clk *bcm_clk = to_kona_clk(hw);
struct peri_clk_data *data = bcm_clk->u.peri;
return clk_recalc_rate(bcm_clk->ccu, &data->div, &data->pre_div,
parent_rate);
}
static long kona_peri_clk_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *parent_rate)
{
struct kona_clk *bcm_clk = to_kona_clk(hw);
struct bcm_clk_div *div = &bcm_clk->u.peri->div;
if (!divider_exists(div))
return __clk_get_rate(hw->clk);
return round_rate(bcm_clk->ccu, div, &bcm_clk->u.peri->pre_div,
rate ? rate : 1, *parent_rate, NULL);
}
static long kona_peri_clk_determine_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *best_parent_rate, struct clk **best_parent)
{
struct kona_clk *bcm_clk = to_kona_clk(hw);
struct clk *clk = hw->clk;
struct clk *current_parent;
unsigned long parent_rate;
unsigned long best_delta;
unsigned long best_rate;
u32 parent_count;
u32 which;
WARN_ON_ONCE(bcm_clk->init_data.flags & CLK_SET_RATE_NO_REPARENT);
parent_count = (u32)bcm_clk->init_data.num_parents;
if (parent_count < 2)
return kona_peri_clk_round_rate(hw, rate, best_parent_rate);
current_parent = clk_get_parent(clk);
parent_rate = __clk_get_rate(current_parent);
best_rate = kona_peri_clk_round_rate(hw, rate, &parent_rate);
best_delta = abs(best_rate - rate);
for (which = 0; which < parent_count; which++) {
struct clk *parent = clk_get_parent_by_index(clk, which);
unsigned long delta;
unsigned long other_rate;
BUG_ON(!parent);
if (parent == current_parent)
continue;
parent_rate = __clk_get_rate(parent);
other_rate = kona_peri_clk_round_rate(hw, rate, &parent_rate);
delta = abs(other_rate - rate);
if (delta < best_delta) {
best_delta = delta;
best_rate = other_rate;
*best_parent = parent;
*best_parent_rate = parent_rate;
}
}
return best_rate;
}
static int kona_peri_clk_set_parent(struct clk_hw *hw, u8 index)
{
struct kona_clk *bcm_clk = to_kona_clk(hw);
struct peri_clk_data *data = bcm_clk->u.peri;
struct bcm_clk_sel *sel = &data->sel;
struct bcm_clk_trig *trig;
int ret;
BUG_ON(index >= sel->parent_count);
if (!selector_exists(sel))
return 0;
trig = trigger_exists(&data->pre_trig) ? &data->pre_trig
: &data->trig;
ret = selector_write(bcm_clk->ccu, &data->gate, sel, trig, index);
if (ret == -ENXIO) {
pr_err("%s: gating failure for %s\n", __func__,
bcm_clk->init_data.name);
ret = -EIO;
} else if (ret == -EIO) {
pr_err("%s: %strigger failed for %s\n", __func__,
trig == &data->pre_trig ? "pre-" : "",
bcm_clk->init_data.name);
}
return ret;
}
static u8 kona_peri_clk_get_parent(struct clk_hw *hw)
{
struct kona_clk *bcm_clk = to_kona_clk(hw);
struct peri_clk_data *data = bcm_clk->u.peri;
u8 index;
index = selector_read_index(bcm_clk->ccu, &data->sel);
return index == BAD_CLK_INDEX ? 0 : index;
}
static int kona_peri_clk_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
struct kona_clk *bcm_clk = to_kona_clk(hw);
struct peri_clk_data *data = bcm_clk->u.peri;
struct bcm_clk_div *div = &data->div;
u64 scaled_div = 0;
int ret;
if (parent_rate > (unsigned long)LONG_MAX)
return -EINVAL;
if (rate == __clk_get_rate(hw->clk))
return 0;
if (!divider_exists(div))
return rate == parent_rate ? 0 : -EINVAL;
if (divider_is_fixed(&data->div))
return rate == parent_rate ? 0 : -EINVAL;
(void)round_rate(bcm_clk->ccu, div, &data->pre_div,
rate ? rate : 1, parent_rate, &scaled_div);
ret = divider_write(bcm_clk->ccu, &data->gate, &data->div,
&data->trig, scaled_div);
if (ret == -ENXIO) {
pr_err("%s: gating failure for %s\n", __func__,
bcm_clk->init_data.name);
ret = -EIO;
} else if (ret == -EIO) {
pr_err("%s: trigger failed for %s\n", __func__,
bcm_clk->init_data.name);
}
return ret;
}
static bool __peri_clk_init(struct kona_clk *bcm_clk)
{
struct ccu_data *ccu = bcm_clk->ccu;
struct peri_clk_data *peri = bcm_clk->u.peri;
const char *name = bcm_clk->init_data.name;
struct bcm_clk_trig *trig;
BUG_ON(bcm_clk->type != bcm_clk_peri);
if (!policy_init(ccu, &peri->policy)) {
pr_err("%s: error initializing policy for %s\n",
__func__, name);
return false;
}
if (!gate_init(ccu, &peri->gate)) {
pr_err("%s: error initializing gate for %s\n", __func__, name);
return false;
}
if (!hyst_init(ccu, &peri->hyst)) {
pr_err("%s: error initializing hyst for %s\n", __func__, name);
return false;
}
if (!div_init(ccu, &peri->gate, &peri->div, &peri->trig)) {
pr_err("%s: error initializing divider for %s\n", __func__,
name);
return false;
}
trig = trigger_exists(&peri->pre_trig) ? &peri->pre_trig
: &peri->trig;
if (!div_init(ccu, &peri->gate, &peri->pre_div, trig)) {
pr_err("%s: error initializing pre-divider for %s\n", __func__,
name);
return false;
}
if (!sel_init(ccu, &peri->gate, &peri->sel, trig)) {
pr_err("%s: error initializing selector for %s\n", __func__,
name);
return false;
}
return true;
}
static bool __kona_clk_init(struct kona_clk *bcm_clk)
{
switch (bcm_clk->type) {
case bcm_clk_peri:
return __peri_clk_init(bcm_clk);
default:
BUG();
}
return -EINVAL;
}
bool __init kona_ccu_init(struct ccu_data *ccu)
{
unsigned long flags;
unsigned int which;
struct clk **clks = ccu->clk_data.clks;
bool success = true;
flags = ccu_lock(ccu);
__ccu_write_enable(ccu);
for (which = 0; which < ccu->clk_data.clk_num; which++) {
struct kona_clk *bcm_clk;
if (!clks[which])
continue;
bcm_clk = to_kona_clk(__clk_get_hw(clks[which]));
success &= __kona_clk_init(bcm_clk);
}
__ccu_write_disable(ccu);
ccu_unlock(ccu, flags);
return success;
}
