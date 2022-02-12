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
if (!clkdm || !deps)
return ERR_PTR(-EINVAL);
for (cd = deps; cd->clkdm_name; cd++) {
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
clkdm = clkdm_lookup(autodep->clkdm.name);
if (!clkdm) {
pr_err("clockdomain: autodeps: clockdomain %s does not exist\n",
autodep->clkdm.name);
clkdm = ERR_PTR(-ENOENT);
}
autodep->clkdm.ptr = clkdm;
}
static void _resolve_clkdm_deps(struct clockdomain *clkdm,
struct clkdm_dep *clkdm_deps)
{
struct clkdm_dep *cd;
for (cd = clkdm_deps; cd && cd->clkdm_name; cd++) {
if (cd->clkdm)
continue;
cd->clkdm = _clkdm_lookup(cd->clkdm_name);
WARN(!cd->clkdm, "clockdomain: %s: could not find clkdm %s while resolving dependencies - should never happen",
clkdm->name, cd->clkdm_name);
}
}
static int _clkdm_add_wkdep(struct clockdomain *clkdm1,
struct clockdomain *clkdm2)
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
pr_debug("clockdomain: hardware cannot set/clear wake up of %s when %s wakes up\n",
clkdm1->name, clkdm2->name);
return ret;
}
cd->wkdep_usecount++;
if (cd->wkdep_usecount == 1) {
pr_debug("clockdomain: hardware will wake up %s when %s wakes up\n",
clkdm1->name, clkdm2->name);
ret = arch_clkdm->clkdm_add_wkdep(clkdm1, clkdm2);
}
return ret;
}
static int _clkdm_del_wkdep(struct clockdomain *clkdm1,
struct clockdomain *clkdm2)
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
pr_debug("clockdomain: hardware cannot set/clear wake up of %s when %s wakes up\n",
clkdm1->name, clkdm2->name);
return ret;
}
cd->wkdep_usecount--;
if (cd->wkdep_usecount == 0) {
pr_debug("clockdomain: hardware will no longer wake up %s after %s wakes up\n",
clkdm1->name, clkdm2->name);
ret = arch_clkdm->clkdm_del_wkdep(clkdm1, clkdm2);
}
return ret;
}
static int _clkdm_add_sleepdep(struct clockdomain *clkdm1,
struct clockdomain *clkdm2)
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
pr_debug("clockdomain: hardware cannot set/clear sleep dependency affecting %s from %s\n",
clkdm1->name, clkdm2->name);
return ret;
}
cd->sleepdep_usecount++;
if (cd->sleepdep_usecount == 1) {
pr_debug("clockdomain: will prevent %s from sleeping if %s is active\n",
clkdm1->name, clkdm2->name);
ret = arch_clkdm->clkdm_add_sleepdep(clkdm1, clkdm2);
}
return ret;
}
static int _clkdm_del_sleepdep(struct clockdomain *clkdm1,
struct clockdomain *clkdm2)
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
pr_debug("clockdomain: hardware cannot set/clear sleep dependency affecting %s from %s\n",
clkdm1->name, clkdm2->name);
return ret;
}
cd->sleepdep_usecount--;
if (cd->sleepdep_usecount == 0) {
pr_debug("clockdomain: will no longer prevent %s from sleeping if %s is active\n",
clkdm1->name, clkdm2->name);
ret = arch_clkdm->clkdm_del_sleepdep(clkdm1, clkdm2);
}
return ret;
}
int clkdm_register_platform_funcs(struct clkdm_ops *co)
{
if (!co)
return -EINVAL;
if (arch_clkdm)
return -EEXIST;
arch_clkdm = co;
return 0;
}
int clkdm_register_clkdms(struct clockdomain **cs)
{
struct clockdomain **c = NULL;
if (!arch_clkdm)
return -EACCES;
if (!cs)
return -EINVAL;
for (c = cs; *c; c++)
_clkdm_register(*c);
return 0;
}
int clkdm_register_autodeps(struct clkdm_autodep *ia)
{
struct clkdm_autodep *a = NULL;
if (list_empty(&clkdm_list))
return -EACCES;
if (!ia)
return -EINVAL;
if (autodeps)
return -EEXIST;
autodeps = ia;
for (a = autodeps; a->clkdm.ptr; a++)
_autodep_lookup(a);
return 0;
}
int clkdm_complete_init(void)
{
struct clockdomain *clkdm;
if (list_empty(&clkdm_list))
return -EACCES;
list_for_each_entry(clkdm, &clkdm_list, node) {
clkdm_deny_idle(clkdm);
_resolve_clkdm_deps(clkdm, clkdm->wkdep_srcs);
clkdm_clear_all_wkdeps(clkdm);
_resolve_clkdm_deps(clkdm, clkdm->sleepdep_srcs);
clkdm_clear_all_sleepdeps(clkdm);
}
return 0;
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
int ret;
if (!clkdm1 || !clkdm2)
return -EINVAL;
cd = _clkdm_deps_lookup(clkdm2, clkdm1->wkdep_srcs);
if (IS_ERR(cd))
return PTR_ERR(cd);
pwrdm_lock(cd->clkdm->pwrdm.ptr);
ret = _clkdm_add_wkdep(clkdm1, clkdm2);
pwrdm_unlock(cd->clkdm->pwrdm.ptr);
return ret;
}
int clkdm_del_wkdep(struct clockdomain *clkdm1, struct clockdomain *clkdm2)
{
struct clkdm_dep *cd;
int ret;
if (!clkdm1 || !clkdm2)
return -EINVAL;
cd = _clkdm_deps_lookup(clkdm2, clkdm1->wkdep_srcs);
if (IS_ERR(cd))
return PTR_ERR(cd);
pwrdm_lock(cd->clkdm->pwrdm.ptr);
ret = _clkdm_del_wkdep(clkdm1, clkdm2);
pwrdm_unlock(cd->clkdm->pwrdm.ptr);
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
pr_debug("clockdomain: hardware cannot set/clear wake up of %s when %s wakes up\n",
clkdm1->name, clkdm2->name);
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
int ret;
if (!clkdm1 || !clkdm2)
return -EINVAL;
cd = _clkdm_deps_lookup(clkdm2, clkdm1->wkdep_srcs);
if (IS_ERR(cd))
return PTR_ERR(cd);
pwrdm_lock(cd->clkdm->pwrdm.ptr);
ret = _clkdm_add_sleepdep(clkdm1, clkdm2);
pwrdm_unlock(cd->clkdm->pwrdm.ptr);
return ret;
}
int clkdm_del_sleepdep(struct clockdomain *clkdm1, struct clockdomain *clkdm2)
{
struct clkdm_dep *cd;
int ret;
if (!clkdm1 || !clkdm2)
return -EINVAL;
cd = _clkdm_deps_lookup(clkdm2, clkdm1->wkdep_srcs);
if (IS_ERR(cd))
return PTR_ERR(cd);
pwrdm_lock(cd->clkdm->pwrdm.ptr);
ret = _clkdm_del_sleepdep(clkdm1, clkdm2);
pwrdm_unlock(cd->clkdm->pwrdm.ptr);
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
pr_debug("clockdomain: hardware cannot set/clear sleep dependency affecting %s from %s\n",
clkdm1->name, clkdm2->name);
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
int clkdm_sleep_nolock(struct clockdomain *clkdm)
{
int ret;
if (!clkdm)
return -EINVAL;
if (!(clkdm->flags & CLKDM_CAN_FORCE_SLEEP)) {
pr_debug("clockdomain: %s does not support forcing sleep via software\n",
clkdm->name);
return -EINVAL;
}
if (!arch_clkdm || !arch_clkdm->clkdm_sleep)
return -EINVAL;
pr_debug("clockdomain: forcing sleep on %s\n", clkdm->name);
clkdm->_flags &= ~_CLKDM_FLAG_HWSUP_ENABLED;
ret = arch_clkdm->clkdm_sleep(clkdm);
ret |= pwrdm_state_switch_nolock(clkdm->pwrdm.ptr);
return ret;
}
int clkdm_sleep(struct clockdomain *clkdm)
{
int ret;
pwrdm_lock(clkdm->pwrdm.ptr);
ret = clkdm_sleep_nolock(clkdm);
pwrdm_unlock(clkdm->pwrdm.ptr);
return ret;
}
int clkdm_wakeup_nolock(struct clockdomain *clkdm)
{
int ret;
if (!clkdm)
return -EINVAL;
if (!(clkdm->flags & CLKDM_CAN_FORCE_WAKEUP)) {
pr_debug("clockdomain: %s does not support forcing wakeup via software\n",
clkdm->name);
return -EINVAL;
}
if (!arch_clkdm || !arch_clkdm->clkdm_wakeup)
return -EINVAL;
pr_debug("clockdomain: forcing wakeup on %s\n", clkdm->name);
clkdm->_flags &= ~_CLKDM_FLAG_HWSUP_ENABLED;
ret = arch_clkdm->clkdm_wakeup(clkdm);
ret |= pwrdm_state_switch_nolock(clkdm->pwrdm.ptr);
return ret;
}
int clkdm_wakeup(struct clockdomain *clkdm)
{
int ret;
pwrdm_lock(clkdm->pwrdm.ptr);
ret = clkdm_wakeup_nolock(clkdm);
pwrdm_unlock(clkdm->pwrdm.ptr);
return ret;
}
void clkdm_allow_idle_nolock(struct clockdomain *clkdm)
{
if (!clkdm)
return;
if (!WARN_ON(!clkdm->forcewake_count))
clkdm->forcewake_count--;
if (clkdm->forcewake_count)
return;
if (!clkdm->usecount && (clkdm->flags & CLKDM_CAN_FORCE_SLEEP))
clkdm_sleep_nolock(clkdm);
if (!(clkdm->flags & CLKDM_CAN_ENABLE_AUTO))
return;
if (clkdm->flags & CLKDM_MISSING_IDLE_REPORTING)
return;
if (!arch_clkdm || !arch_clkdm->clkdm_allow_idle)
return;
pr_debug("clockdomain: enabling automatic idle transitions for %s\n",
clkdm->name);
clkdm->_flags |= _CLKDM_FLAG_HWSUP_ENABLED;
arch_clkdm->clkdm_allow_idle(clkdm);
pwrdm_state_switch_nolock(clkdm->pwrdm.ptr);
}
void clkdm_allow_idle(struct clockdomain *clkdm)
{
pwrdm_lock(clkdm->pwrdm.ptr);
clkdm_allow_idle_nolock(clkdm);
pwrdm_unlock(clkdm->pwrdm.ptr);
}
void clkdm_deny_idle_nolock(struct clockdomain *clkdm)
{
if (!clkdm)
return;
if (clkdm->forcewake_count++)
return;
if (clkdm->flags & CLKDM_CAN_FORCE_WAKEUP)
clkdm_wakeup_nolock(clkdm);
if (!(clkdm->flags & CLKDM_CAN_DISABLE_AUTO))
return;
if (clkdm->flags & CLKDM_MISSING_IDLE_REPORTING)
return;
if (!arch_clkdm || !arch_clkdm->clkdm_deny_idle)
return;
pr_debug("clockdomain: disabling automatic idle transitions for %s\n",
clkdm->name);
clkdm->_flags &= ~_CLKDM_FLAG_HWSUP_ENABLED;
arch_clkdm->clkdm_deny_idle(clkdm);
pwrdm_state_switch_nolock(clkdm->pwrdm.ptr);
}
void clkdm_deny_idle(struct clockdomain *clkdm)
{
pwrdm_lock(clkdm->pwrdm.ptr);
clkdm_deny_idle_nolock(clkdm);
pwrdm_unlock(clkdm->pwrdm.ptr);
}
bool clkdm_in_hwsup(struct clockdomain *clkdm)
{
bool ret;
if (!clkdm)
return false;
ret = (clkdm->_flags & _CLKDM_FLAG_HWSUP_ENABLED) ? true : false;
return ret;
}
bool clkdm_missing_idle_reporting(struct clockdomain *clkdm)
{
if (!clkdm)
return false;
return (clkdm->flags & CLKDM_MISSING_IDLE_REPORTING) ? true : false;
}
void clkdm_add_autodeps(struct clockdomain *clkdm)
{
struct clkdm_autodep *autodep;
if (!autodeps || clkdm->flags & CLKDM_NO_AUTODEPS)
return;
for (autodep = autodeps; autodep->clkdm.ptr; autodep++) {
if (IS_ERR(autodep->clkdm.ptr))
continue;
pr_debug("clockdomain: %s: adding %s sleepdep/wkdep\n",
clkdm->name, autodep->clkdm.ptr->name);
_clkdm_add_sleepdep(clkdm, autodep->clkdm.ptr);
_clkdm_add_wkdep(clkdm, autodep->clkdm.ptr);
}
}
void clkdm_del_autodeps(struct clockdomain *clkdm)
{
struct clkdm_autodep *autodep;
if (!autodeps || clkdm->flags & CLKDM_NO_AUTODEPS)
return;
for (autodep = autodeps; autodep->clkdm.ptr; autodep++) {
if (IS_ERR(autodep->clkdm.ptr))
continue;
pr_debug("clockdomain: %s: removing %s sleepdep/wkdep\n",
clkdm->name, autodep->clkdm.ptr->name);
_clkdm_del_sleepdep(clkdm, autodep->clkdm.ptr);
_clkdm_del_wkdep(clkdm, autodep->clkdm.ptr);
}
}
static int _clkdm_clk_hwmod_enable(struct clockdomain *clkdm)
{
if (!clkdm || !arch_clkdm || !arch_clkdm->clkdm_clk_enable)
return -EINVAL;
pwrdm_lock(clkdm->pwrdm.ptr);
clkdm->usecount++;
if (clkdm->usecount > 1 && autodeps) {
pwrdm_unlock(clkdm->pwrdm.ptr);
return 0;
}
arch_clkdm->clkdm_clk_enable(clkdm);
pwrdm_state_switch_nolock(clkdm->pwrdm.ptr);
pwrdm_unlock(clkdm->pwrdm.ptr);
pr_debug("clockdomain: %s: enabled\n", clkdm->name);
return 0;
}
int clkdm_clk_enable(struct clockdomain *clkdm, struct clk *clk)
{
if (!clk)
return -EINVAL;
return _clkdm_clk_hwmod_enable(clkdm);
}
int clkdm_clk_disable(struct clockdomain *clkdm, struct clk *clk)
{
if (!clkdm || !clk || !arch_clkdm || !arch_clkdm->clkdm_clk_disable)
return -EINVAL;
pwrdm_lock(clkdm->pwrdm.ptr);
if ((__clk_get_enable_count(clk) == 0) && clkdm->usecount == 0)
goto ccd_exit;
if (clkdm->usecount == 0) {
pwrdm_unlock(clkdm->pwrdm.ptr);
WARN_ON(1);
return -ERANGE;
}
clkdm->usecount--;
if (clkdm->usecount > 0) {
pwrdm_unlock(clkdm->pwrdm.ptr);
return 0;
}
arch_clkdm->clkdm_clk_disable(clkdm);
pwrdm_state_switch_nolock(clkdm->pwrdm.ptr);
pr_debug("clockdomain: %s: disabled\n", clkdm->name);
ccd_exit:
pwrdm_unlock(clkdm->pwrdm.ptr);
return 0;
}
int clkdm_hwmod_enable(struct clockdomain *clkdm, struct omap_hwmod *oh)
{
if (cpu_is_omap24xx() || cpu_is_omap34xx())
return 0;
if (!oh)
return -EINVAL;
return _clkdm_clk_hwmod_enable(clkdm);
}
int clkdm_hwmod_disable(struct clockdomain *clkdm, struct omap_hwmod *oh)
{
if (cpu_is_omap24xx() || cpu_is_omap34xx())
return 0;
if (!clkdm || !oh || !arch_clkdm || !arch_clkdm->clkdm_clk_disable)
return -EINVAL;
pwrdm_lock(clkdm->pwrdm.ptr);
if (clkdm->usecount == 0) {
pwrdm_unlock(clkdm->pwrdm.ptr);
WARN_ON(1);
return -ERANGE;
}
clkdm->usecount--;
if (clkdm->usecount > 0) {
pwrdm_unlock(clkdm->pwrdm.ptr);
return 0;
}
arch_clkdm->clkdm_clk_disable(clkdm);
pwrdm_state_switch_nolock(clkdm->pwrdm.ptr);
pwrdm_unlock(clkdm->pwrdm.ptr);
pr_debug("clockdomain: %s: disabled\n", clkdm->name);
return 0;
}
