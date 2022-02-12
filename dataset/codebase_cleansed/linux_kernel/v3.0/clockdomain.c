static struct clockdomain *_clkdm_lookup(const char *name)
{
struct clockdomain *clkdm, *temp_clkdm;
if (!name)
return NULL;
clkdm = NULL;
list_for_each_entry(temp_clkdm, &clkdm_list, node) {
if (!strcmp(name, temp_clkdm->name)) {
clkdm = temp_clkdm;
break;
}
}
return clkdm;
}
static int _clkdm_register(struct clockdomain *clkdm)
{
struct powerdomain *pwrdm;
if (!clkdm || !clkdm->name)
return -EINVAL;
if (!omap_chip_is(clkdm->omap_chip))
return -EINVAL;
pwrdm = pwrdm_lookup(clkdm->pwrdm.name);
if (!pwrdm) {
pr_err("clockdomain: %s: powerdomain %s does not exist\n",
clkdm->name, clkdm->pwrdm.name);
return -EINVAL;
}
clkdm->pwrdm.ptr = pwrdm;
if (_clkdm_lookup(clkdm->name))
return -EEXIST;
list_add(&clkdm->node, &clkdm_list);
pwrdm_add_clkdm(pwrdm, clkdm);
pr_debug("clockdomain: registered %s\n", clkdm->name);
return 0;
}
static struct clkdm_dep *_clkdm_deps_lookup(struct clockdomain *clkdm,
struct clkdm_dep *deps)
{
struct clkdm_dep *cd;
if (!clkdm || !deps || !omap_chip_is(clkdm->omap_chip))
return ERR_PTR(-EINVAL);
for (cd = deps; cd->clkdm_name; cd++) {
if (!omap_chip_is(cd->omap_chip))
continue;
if (!cd->clkdm && cd->clkdm_name)
cd->clkdm = _clkdm_lookup(cd->clkdm_name);
if (cd->clkdm == clkdm)
break;
}
if (!cd->clkdm_name)
return ERR_PTR(-ENOENT);
return cd;
}
static void _autodep_lookup(struct clkdm_autodep *autodep)
{
struct clockdomain *clkdm;
if (!autodep)
return;
if (!omap_chip_is(autodep->omap_chip))
return;
clkdm = clkdm_lookup(autodep->clkdm.name);
if (!clkdm) {
pr_err("clockdomain: autodeps: clockdomain %s does not exist\n",
autodep->clkdm.name);
clkdm = ERR_PTR(-ENOENT);
}
autodep->clkdm.ptr = clkdm;
}
void _clkdm_add_autodeps(struct clockdomain *clkdm)
{
struct clkdm_autodep *autodep;
if (!autodeps || clkdm->flags & CLKDM_NO_AUTODEPS)
return;
for (autodep = autodeps; autodep->clkdm.ptr; autodep++) {
if (IS_ERR(autodep->clkdm.ptr))
continue;
if (!omap_chip_is(autodep->omap_chip))
continue;
pr_debug("clockdomain: adding %s sleepdep/wkdep for "
"clkdm %s\n", autodep->clkdm.ptr->name,
clkdm->name);
clkdm_add_sleepdep(clkdm, autodep->clkdm.ptr);
clkdm_add_wkdep(clkdm, autodep->clkdm.ptr);
}
}
void _clkdm_del_autodeps(struct clockdomain *clkdm)
{
struct clkdm_autodep *autodep;
if (!autodeps || clkdm->flags & CLKDM_NO_AUTODEPS)
return;
for (autodep = autodeps; autodep->clkdm.ptr; autodep++) {
if (IS_ERR(autodep->clkdm.ptr))
continue;
if (!omap_chip_is(autodep->omap_chip))
continue;
pr_debug("clockdomain: removing %s sleepdep/wkdep for "
"clkdm %s\n", autodep->clkdm.ptr->name,
clkdm->name);
clkdm_del_sleepdep(clkdm, autodep->clkdm.ptr);
clkdm_del_wkdep(clkdm, autodep->clkdm.ptr);
}
}
static void _resolve_clkdm_deps(struct clockdomain *clkdm,
struct clkdm_dep *clkdm_deps)
{
struct clkdm_dep *cd;
for (cd = clkdm_deps; cd && cd->clkdm_name; cd++) {
if (!omap_chip_is(cd->omap_chip))
continue;
if (cd->clkdm)
continue;
cd->clkdm = _clkdm_lookup(cd->clkdm_name);
WARN(!cd->clkdm, "clockdomain: %s: could not find clkdm %s while resolving dependencies - should never happen",
clkdm->name, cd->clkdm_name);
}
}
void clkdm_init(struct clockdomain **clkdms,
struct clkdm_autodep *init_autodeps,
struct clkdm_ops *custom_funcs)
{
struct clockdomain **c = NULL;
struct clockdomain *clkdm;
struct clkdm_autodep *autodep = NULL;
if (!custom_funcs)
WARN(1, "No custom clkdm functions registered\n");
else
arch_clkdm = custom_funcs;
if (clkdms)
for (c = clkdms; *c; c++)
_clkdm_register(*c);
autodeps = init_autodeps;
if (autodeps)
for (autodep = autodeps; autodep->clkdm.ptr; autodep++)
_autodep_lookup(autodep);
list_for_each_entry(clkdm, &clkdm_list, node) {
if (clkdm->flags & CLKDM_CAN_FORCE_WAKEUP)
clkdm_wakeup(clkdm);
else if (clkdm->flags & CLKDM_CAN_DISABLE_AUTO)
clkdm_deny_idle(clkdm);
_resolve_clkdm_deps(clkdm, clkdm->wkdep_srcs);
clkdm_clear_all_wkdeps(clkdm);
_resolve_clkdm_deps(clkdm, clkdm->sleepdep_srcs);
clkdm_clear_all_sleepdeps(clkdm);
}
}
struct clockdomain *clkdm_lookup(const char *name)
{
struct clockdomain *clkdm, *temp_clkdm;
if (!name)
return NULL;
clkdm = NULL;
list_for_each_entry(temp_clkdm, &clkdm_list, node) {
if (!strcmp(name, temp_clkdm->name)) {
clkdm = temp_clkdm;
break;
}
}
return clkdm;
}
int clkdm_for_each(int (*fn)(struct clockdomain *clkdm, void *user),
void *user)
{
struct clockdomain *clkdm;
int ret = 0;
if (!fn)
return -EINVAL;
list_for_each_entry(clkdm, &clkdm_list, node) {
ret = (*fn)(clkdm, user);
if (ret)
break;
}
return ret;
}
struct powerdomain *clkdm_get_pwrdm(struct clockdomain *clkdm)
{
if (!clkdm)
return NULL;
return clkdm->pwrdm.ptr;
}
int clkdm_add_wkdep(struct clockdomain *clkdm1, struct clockdomain *clkdm2)
{
struct clkdm_dep *cd;
int ret = 0;
if (!clkdm1 || !clkdm2)
return -EINVAL;
cd = _clkdm_deps_lookup(clkdm2, clkdm1->wkdep_srcs);
if (IS_ERR(cd))
ret = PTR_ERR(cd);
if (!arch_clkdm || !arch_clkdm->clkdm_add_wkdep)
ret = -EINVAL;
if (ret) {
pr_debug("clockdomain: hardware cannot set/clear wake up of "
"%s when %s wakes up\n", clkdm1->name, clkdm2->name);
return ret;
}
if (atomic_inc_return(&cd->wkdep_usecount) == 1) {
pr_debug("clockdomain: hardware will wake up %s when %s wakes "
"up\n", clkdm1->name, clkdm2->name);
ret = arch_clkdm->clkdm_add_wkdep(clkdm1, clkdm2);
}
return ret;
}
int clkdm_del_wkdep(struct clockdomain *clkdm1, struct clockdomain *clkdm2)
{
struct clkdm_dep *cd;
int ret = 0;
if (!clkdm1 || !clkdm2)
return -EINVAL;
cd = _clkdm_deps_lookup(clkdm2, clkdm1->wkdep_srcs);
if (IS_ERR(cd))
ret = PTR_ERR(cd);
if (!arch_clkdm || !arch_clkdm->clkdm_del_wkdep)
ret = -EINVAL;
if (ret) {
pr_debug("clockdomain: hardware cannot set/clear wake up of "
"%s when %s wakes up\n", clkdm1->name, clkdm2->name);
return ret;
}
if (atomic_dec_return(&cd->wkdep_usecount) == 0) {
pr_debug("clockdomain: hardware will no longer wake up %s "
"after %s wakes up\n", clkdm1->name, clkdm2->name);
ret = arch_clkdm->clkdm_del_wkdep(clkdm1, clkdm2);
}
return ret;
}
int clkdm_read_wkdep(struct clockdomain *clkdm1, struct clockdomain *clkdm2)
{
struct clkdm_dep *cd;
int ret = 0;
if (!clkdm1 || !clkdm2)
return -EINVAL;
cd = _clkdm_deps_lookup(clkdm2, clkdm1->wkdep_srcs);
if (IS_ERR(cd))
ret = PTR_ERR(cd);
if (!arch_clkdm || !arch_clkdm->clkdm_read_wkdep)
ret = -EINVAL;
if (ret) {
pr_debug("clockdomain: hardware cannot set/clear wake up of "
"%s when %s wakes up\n", clkdm1->name, clkdm2->name);
return ret;
}
return arch_clkdm->clkdm_read_wkdep(clkdm1, clkdm2);
}
int clkdm_clear_all_wkdeps(struct clockdomain *clkdm)
{
if (!clkdm)
return -EINVAL;
if (!arch_clkdm || !arch_clkdm->clkdm_clear_all_wkdeps)
return -EINVAL;
return arch_clkdm->clkdm_clear_all_wkdeps(clkdm);
}
int clkdm_add_sleepdep(struct clockdomain *clkdm1, struct clockdomain *clkdm2)
{
struct clkdm_dep *cd;
int ret = 0;
if (!clkdm1 || !clkdm2)
return -EINVAL;
cd = _clkdm_deps_lookup(clkdm2, clkdm1->sleepdep_srcs);
if (IS_ERR(cd))
ret = PTR_ERR(cd);
if (!arch_clkdm || !arch_clkdm->clkdm_add_sleepdep)
ret = -EINVAL;
if (ret) {
pr_debug("clockdomain: hardware cannot set/clear sleep "
"dependency affecting %s from %s\n", clkdm1->name,
clkdm2->name);
return ret;
}
if (atomic_inc_return(&cd->sleepdep_usecount) == 1) {
pr_debug("clockdomain: will prevent %s from sleeping if %s "
"is active\n", clkdm1->name, clkdm2->name);
ret = arch_clkdm->clkdm_add_sleepdep(clkdm1, clkdm2);
}
return ret;
}
int clkdm_del_sleepdep(struct clockdomain *clkdm1, struct clockdomain *clkdm2)
{
struct clkdm_dep *cd;
int ret = 0;
if (!clkdm1 || !clkdm2)
return -EINVAL;
cd = _clkdm_deps_lookup(clkdm2, clkdm1->sleepdep_srcs);
if (IS_ERR(cd))
ret = PTR_ERR(cd);
if (!arch_clkdm || !arch_clkdm->clkdm_del_sleepdep)
ret = -EINVAL;
if (ret) {
pr_debug("clockdomain: hardware cannot set/clear sleep "
"dependency affecting %s from %s\n", clkdm1->name,
clkdm2->name);
return ret;
}
if (atomic_dec_return(&cd->sleepdep_usecount) == 0) {
pr_debug("clockdomain: will no longer prevent %s from "
"sleeping if %s is active\n", clkdm1->name,
clkdm2->name);
ret = arch_clkdm->clkdm_del_sleepdep(clkdm1, clkdm2);
}
return ret;
}
int clkdm_read_sleepdep(struct clockdomain *clkdm1, struct clockdomain *clkdm2)
{
struct clkdm_dep *cd;
int ret = 0;
if (!clkdm1 || !clkdm2)
return -EINVAL;
cd = _clkdm_deps_lookup(clkdm2, clkdm1->sleepdep_srcs);
if (IS_ERR(cd))
ret = PTR_ERR(cd);
if (!arch_clkdm || !arch_clkdm->clkdm_read_sleepdep)
ret = -EINVAL;
if (ret) {
pr_debug("clockdomain: hardware cannot set/clear sleep "
"dependency affecting %s from %s\n", clkdm1->name,
clkdm2->name);
return ret;
}
return arch_clkdm->clkdm_read_sleepdep(clkdm1, clkdm2);
}
int clkdm_clear_all_sleepdeps(struct clockdomain *clkdm)
{
if (!clkdm)
return -EINVAL;
if (!arch_clkdm || !arch_clkdm->clkdm_clear_all_sleepdeps)
return -EINVAL;
return arch_clkdm->clkdm_clear_all_sleepdeps(clkdm);
}
int clkdm_sleep(struct clockdomain *clkdm)
{
if (!clkdm)
return -EINVAL;
if (!(clkdm->flags & CLKDM_CAN_FORCE_SLEEP)) {
pr_debug("clockdomain: %s does not support forcing "
"sleep via software\n", clkdm->name);
return -EINVAL;
}
if (!arch_clkdm || !arch_clkdm->clkdm_sleep)
return -EINVAL;
pr_debug("clockdomain: forcing sleep on %s\n", clkdm->name);
return arch_clkdm->clkdm_sleep(clkdm);
}
int clkdm_wakeup(struct clockdomain *clkdm)
{
if (!clkdm)
return -EINVAL;
if (!(clkdm->flags & CLKDM_CAN_FORCE_WAKEUP)) {
pr_debug("clockdomain: %s does not support forcing "
"wakeup via software\n", clkdm->name);
return -EINVAL;
}
if (!arch_clkdm || !arch_clkdm->clkdm_wakeup)
return -EINVAL;
pr_debug("clockdomain: forcing wakeup on %s\n", clkdm->name);
return arch_clkdm->clkdm_wakeup(clkdm);
}
void clkdm_allow_idle(struct clockdomain *clkdm)
{
if (!clkdm)
return;
if (!(clkdm->flags & CLKDM_CAN_ENABLE_AUTO)) {
pr_debug("clock: automatic idle transitions cannot be enabled "
"on clockdomain %s\n", clkdm->name);
return;
}
if (!arch_clkdm || !arch_clkdm->clkdm_allow_idle)
return;
pr_debug("clockdomain: enabling automatic idle transitions for %s\n",
clkdm->name);
arch_clkdm->clkdm_allow_idle(clkdm);
pwrdm_clkdm_state_switch(clkdm);
}
void clkdm_deny_idle(struct clockdomain *clkdm)
{
if (!clkdm)
return;
if (!(clkdm->flags & CLKDM_CAN_DISABLE_AUTO)) {
pr_debug("clockdomain: automatic idle transitions cannot be "
"disabled on %s\n", clkdm->name);
return;
}
if (!arch_clkdm || !arch_clkdm->clkdm_deny_idle)
return;
pr_debug("clockdomain: disabling automatic idle transitions for %s\n",
clkdm->name);
arch_clkdm->clkdm_deny_idle(clkdm);
}
int clkdm_clk_enable(struct clockdomain *clkdm, struct clk *clk)
{
if (!clkdm || !clk)
return -EINVAL;
if (!arch_clkdm || !arch_clkdm->clkdm_clk_enable)
return -EINVAL;
if (atomic_inc_return(&clkdm->usecount) > 1)
return 0;
pr_debug("clockdomain: clkdm %s: clk %s now enabled\n", clkdm->name,
clk->name);
arch_clkdm->clkdm_clk_enable(clkdm);
pwrdm_wait_transition(clkdm->pwrdm.ptr);
pwrdm_clkdm_state_switch(clkdm);
return 0;
}
int clkdm_clk_disable(struct clockdomain *clkdm, struct clk *clk)
{
if (!clkdm || !clk)
return -EINVAL;
if (!arch_clkdm || !arch_clkdm->clkdm_clk_disable)
return -EINVAL;
#ifdef DEBUG
if (atomic_read(&clkdm->usecount) == 0) {
WARN_ON(1);
return -ERANGE;
}
#endif
if (atomic_dec_return(&clkdm->usecount) > 0)
return 0;
pr_debug("clockdomain: clkdm %s: clk %s now disabled\n", clkdm->name,
clk->name);
arch_clkdm->clkdm_clk_disable(clkdm);
pwrdm_clkdm_state_switch(clkdm);
return 0;
}
