static struct powerdomain *_pwrdm_lookup(const char *name)
{
struct powerdomain *pwrdm, *temp_pwrdm;
pwrdm = NULL;
list_for_each_entry(temp_pwrdm, &pwrdm_list, node) {
if (!strcmp(name, temp_pwrdm->name)) {
pwrdm = temp_pwrdm;
break;
}
}
return pwrdm;
}
static int _pwrdm_register(struct powerdomain *pwrdm)
{
int i;
struct voltagedomain *voltdm;
if (!pwrdm || !pwrdm->name)
return -EINVAL;
if (cpu_is_omap44xx() &&
pwrdm->prcm_partition == OMAP4430_INVALID_PRCM_PARTITION) {
pr_err("powerdomain: %s: missing OMAP4 PRCM partition ID\n",
pwrdm->name);
return -EINVAL;
}
if (_pwrdm_lookup(pwrdm->name))
return -EEXIST;
voltdm = voltdm_lookup(pwrdm->voltdm.name);
if (!voltdm) {
pr_err("powerdomain: %s: voltagedomain %s does not exist\n",
pwrdm->name, pwrdm->voltdm.name);
return -EINVAL;
}
pwrdm->voltdm.ptr = voltdm;
INIT_LIST_HEAD(&pwrdm->voltdm_node);
voltdm_add_pwrdm(voltdm, pwrdm);
spin_lock_init(&pwrdm->_lock);
list_add(&pwrdm->node, &pwrdm_list);
for (i = 0; i < PWRDM_MAX_PWRSTS; i++)
pwrdm->state_counter[i] = 0;
pwrdm->ret_logic_off_counter = 0;
for (i = 0; i < pwrdm->banks; i++)
pwrdm->ret_mem_off_counter[i] = 0;
arch_pwrdm->pwrdm_wait_transition(pwrdm);
pwrdm->state = pwrdm_read_pwrst(pwrdm);
pwrdm->state_counter[pwrdm->state] = 1;
pr_debug("powerdomain: registered %s\n", pwrdm->name);
return 0;
}
static void _update_logic_membank_counters(struct powerdomain *pwrdm)
{
int i;
u8 prev_logic_pwrst, prev_mem_pwrst;
prev_logic_pwrst = pwrdm_read_prev_logic_pwrst(pwrdm);
if ((pwrdm->pwrsts_logic_ret == PWRSTS_OFF_RET) &&
(prev_logic_pwrst == PWRDM_POWER_OFF))
pwrdm->ret_logic_off_counter++;
for (i = 0; i < pwrdm->banks; i++) {
prev_mem_pwrst = pwrdm_read_prev_mem_pwrst(pwrdm, i);
if ((pwrdm->pwrsts_mem_ret[i] == PWRSTS_OFF_RET) &&
(prev_mem_pwrst == PWRDM_POWER_OFF))
pwrdm->ret_mem_off_counter[i]++;
}
}
static int _pwrdm_state_switch(struct powerdomain *pwrdm, int flag)
{
int prev, next, state, trace_state = 0;
if (pwrdm == NULL)
return -EINVAL;
state = pwrdm_read_pwrst(pwrdm);
switch (flag) {
case PWRDM_STATE_NOW:
prev = pwrdm->state;
break;
case PWRDM_STATE_PREV:
prev = pwrdm_read_prev_pwrst(pwrdm);
if (pwrdm->state != prev)
pwrdm->state_counter[prev]++;
if (prev == PWRDM_POWER_RET)
_update_logic_membank_counters(pwrdm);
next = pwrdm_read_next_pwrst(pwrdm);
if (next != prev) {
trace_state = (PWRDM_TRACE_STATES_FLAG |
((next & OMAP_POWERSTATE_MASK) << 8) |
((prev & OMAP_POWERSTATE_MASK) << 0));
trace_power_domain_target(pwrdm->name, trace_state,
smp_processor_id());
}
break;
default:
return -EINVAL;
}
if (state != prev)
pwrdm->state_counter[state]++;
pm_dbg_update_time(pwrdm, prev);
pwrdm->state = state;
return 0;
}
static int _pwrdm_pre_transition_cb(struct powerdomain *pwrdm, void *unused)
{
pwrdm_clear_all_prev_pwrst(pwrdm);
_pwrdm_state_switch(pwrdm, PWRDM_STATE_NOW);
return 0;
}
static int _pwrdm_post_transition_cb(struct powerdomain *pwrdm, void *unused)
{
_pwrdm_state_switch(pwrdm, PWRDM_STATE_PREV);
return 0;
}
static u8 _pwrdm_save_clkdm_state_and_activate(struct powerdomain *pwrdm,
u8 curr_pwrst, u8 pwrst,
bool *hwsup)
{
u8 sleep_switch;
if (curr_pwrst < 0) {
WARN_ON(1);
sleep_switch = ERROR_SWITCH;
} else if (curr_pwrst < PWRDM_POWER_ON) {
if (curr_pwrst > pwrst &&
pwrdm->flags & PWRDM_HAS_LOWPOWERSTATECHANGE &&
arch_pwrdm->pwrdm_set_lowpwrstchange) {
sleep_switch = LOWPOWERSTATE_SWITCH;
} else {
*hwsup = clkdm_in_hwsup(pwrdm->pwrdm_clkdms[0]);
clkdm_wakeup_nolock(pwrdm->pwrdm_clkdms[0]);
sleep_switch = FORCEWAKEUP_SWITCH;
}
} else {
sleep_switch = ALREADYACTIVE_SWITCH;
}
return sleep_switch;
}
static void _pwrdm_restore_clkdm_state(struct powerdomain *pwrdm,
u8 sleep_switch, bool hwsup)
{
switch (sleep_switch) {
case FORCEWAKEUP_SWITCH:
if (hwsup)
clkdm_allow_idle_nolock(pwrdm->pwrdm_clkdms[0]);
else
clkdm_sleep_nolock(pwrdm->pwrdm_clkdms[0]);
break;
case LOWPOWERSTATE_SWITCH:
if (pwrdm->flags & PWRDM_HAS_LOWPOWERSTATECHANGE &&
arch_pwrdm->pwrdm_set_lowpwrstchange)
arch_pwrdm->pwrdm_set_lowpwrstchange(pwrdm);
pwrdm_state_switch_nolock(pwrdm);
break;
}
}
int pwrdm_register_platform_funcs(struct pwrdm_ops *po)
{
if (!po)
return -EINVAL;
if (arch_pwrdm)
return -EEXIST;
arch_pwrdm = po;
return 0;
}
int pwrdm_register_pwrdms(struct powerdomain **ps)
{
struct powerdomain **p = NULL;
if (!arch_pwrdm)
return -EEXIST;
if (!ps)
return -EINVAL;
for (p = ps; *p; p++)
_pwrdm_register(*p);
return 0;
}
int pwrdm_complete_init(void)
{
struct powerdomain *temp_p;
if (list_empty(&pwrdm_list))
return -EACCES;
list_for_each_entry(temp_p, &pwrdm_list, node)
pwrdm_set_next_pwrst(temp_p, PWRDM_POWER_ON);
return 0;
}
void pwrdm_lock(struct powerdomain *pwrdm)
__acquires(&pwrdm->_lock
void pwrdm_unlock(struct powerdomain *pwrdm)
__releases(&pwrdm->_lock
struct powerdomain *pwrdm_lookup(const char *name)
{
struct powerdomain *pwrdm;
if (!name)
return NULL;
pwrdm = _pwrdm_lookup(name);
return pwrdm;
}
int pwrdm_for_each(int (*fn)(struct powerdomain *pwrdm, void *user),
void *user)
{
struct powerdomain *temp_pwrdm;
int ret = 0;
if (!fn)
return -EINVAL;
list_for_each_entry(temp_pwrdm, &pwrdm_list, node) {
ret = (*fn)(temp_pwrdm, user);
if (ret)
break;
}
return ret;
}
int pwrdm_add_clkdm(struct powerdomain *pwrdm, struct clockdomain *clkdm)
{
int i;
int ret = -EINVAL;
if (!pwrdm || !clkdm)
return -EINVAL;
pr_debug("powerdomain: %s: associating clockdomain %s\n",
pwrdm->name, clkdm->name);
for (i = 0; i < PWRDM_MAX_CLKDMS; i++) {
if (!pwrdm->pwrdm_clkdms[i])
break;
#ifdef DEBUG
if (pwrdm->pwrdm_clkdms[i] == clkdm) {
ret = -EINVAL;
goto pac_exit;
}
#endif
}
if (i == PWRDM_MAX_CLKDMS) {
pr_debug("powerdomain: %s: increase PWRDM_MAX_CLKDMS for clkdm %s\n",
pwrdm->name, clkdm->name);
WARN_ON(1);
ret = -ENOMEM;
goto pac_exit;
}
pwrdm->pwrdm_clkdms[i] = clkdm;
ret = 0;
pac_exit:
return ret;
}
int pwrdm_del_clkdm(struct powerdomain *pwrdm, struct clockdomain *clkdm)
{
int ret = -EINVAL;
int i;
if (!pwrdm || !clkdm)
return -EINVAL;
pr_debug("powerdomain: %s: dissociating clockdomain %s\n",
pwrdm->name, clkdm->name);
for (i = 0; i < PWRDM_MAX_CLKDMS; i++)
if (pwrdm->pwrdm_clkdms[i] == clkdm)
break;
if (i == PWRDM_MAX_CLKDMS) {
pr_debug("powerdomain: %s: clkdm %s not associated?!\n",
pwrdm->name, clkdm->name);
ret = -ENOENT;
goto pdc_exit;
}
pwrdm->pwrdm_clkdms[i] = NULL;
ret = 0;
pdc_exit:
return ret;
}
int pwrdm_for_each_clkdm(struct powerdomain *pwrdm,
int (*fn)(struct powerdomain *pwrdm,
struct clockdomain *clkdm))
{
int ret = 0;
int i;
if (!fn)
return -EINVAL;
for (i = 0; i < PWRDM_MAX_CLKDMS && !ret; i++)
ret = (*fn)(pwrdm, pwrdm->pwrdm_clkdms[i]);
return ret;
}
struct voltagedomain *pwrdm_get_voltdm(struct powerdomain *pwrdm)
{
return pwrdm->voltdm.ptr;
}
int pwrdm_get_mem_bank_count(struct powerdomain *pwrdm)
{
if (!pwrdm)
return -EINVAL;
return pwrdm->banks;
}
int pwrdm_set_next_pwrst(struct powerdomain *pwrdm, u8 pwrst)
{
int ret = -EINVAL;
if (!pwrdm)
return -EINVAL;
if (!(pwrdm->pwrsts & (1 << pwrst)))
return -EINVAL;
pr_debug("powerdomain: %s: setting next powerstate to %0x\n",
pwrdm->name, pwrst);
if (arch_pwrdm && arch_pwrdm->pwrdm_set_next_pwrst) {
trace_power_domain_target(pwrdm->name, pwrst,
smp_processor_id());
ret = arch_pwrdm->pwrdm_set_next_pwrst(pwrdm, pwrst);
}
return ret;
}
int pwrdm_read_next_pwrst(struct powerdomain *pwrdm)
{
int ret = -EINVAL;
if (!pwrdm)
return -EINVAL;
if (arch_pwrdm && arch_pwrdm->pwrdm_read_next_pwrst)
ret = arch_pwrdm->pwrdm_read_next_pwrst(pwrdm);
return ret;
}
int pwrdm_read_pwrst(struct powerdomain *pwrdm)
{
int ret = -EINVAL;
if (!pwrdm)
return -EINVAL;
if (pwrdm->pwrsts == PWRSTS_ON)
return PWRDM_POWER_ON;
if (arch_pwrdm && arch_pwrdm->pwrdm_read_pwrst)
ret = arch_pwrdm->pwrdm_read_pwrst(pwrdm);
return ret;
}
int pwrdm_read_prev_pwrst(struct powerdomain *pwrdm)
{
int ret = -EINVAL;
if (!pwrdm)
return -EINVAL;
if (arch_pwrdm && arch_pwrdm->pwrdm_read_prev_pwrst)
ret = arch_pwrdm->pwrdm_read_prev_pwrst(pwrdm);
return ret;
}
int pwrdm_set_logic_retst(struct powerdomain *pwrdm, u8 pwrst)
{
int ret = -EINVAL;
if (!pwrdm)
return -EINVAL;
if (!(pwrdm->pwrsts_logic_ret & (1 << pwrst)))
return -EINVAL;
pr_debug("powerdomain: %s: setting next logic powerstate to %0x\n",
pwrdm->name, pwrst);
if (arch_pwrdm && arch_pwrdm->pwrdm_set_logic_retst)
ret = arch_pwrdm->pwrdm_set_logic_retst(pwrdm, pwrst);
return ret;
}
int pwrdm_set_mem_onst(struct powerdomain *pwrdm, u8 bank, u8 pwrst)
{
int ret = -EINVAL;
if (!pwrdm)
return -EINVAL;
if (pwrdm->banks < (bank + 1))
return -EEXIST;
if (!(pwrdm->pwrsts_mem_on[bank] & (1 << pwrst)))
return -EINVAL;
pr_debug("powerdomain: %s: setting next memory powerstate for bank %0x while pwrdm-ON to %0x\n",
pwrdm->name, bank, pwrst);
if (arch_pwrdm && arch_pwrdm->pwrdm_set_mem_onst)
ret = arch_pwrdm->pwrdm_set_mem_onst(pwrdm, bank, pwrst);
return ret;
}
int pwrdm_set_mem_retst(struct powerdomain *pwrdm, u8 bank, u8 pwrst)
{
int ret = -EINVAL;
if (!pwrdm)
return -EINVAL;
if (pwrdm->banks < (bank + 1))
return -EEXIST;
if (!(pwrdm->pwrsts_mem_ret[bank] & (1 << pwrst)))
return -EINVAL;
pr_debug("powerdomain: %s: setting next memory powerstate for bank %0x while pwrdm-RET to %0x\n",
pwrdm->name, bank, pwrst);
if (arch_pwrdm && arch_pwrdm->pwrdm_set_mem_retst)
ret = arch_pwrdm->pwrdm_set_mem_retst(pwrdm, bank, pwrst);
return ret;
}
int pwrdm_read_logic_pwrst(struct powerdomain *pwrdm)
{
int ret = -EINVAL;
if (!pwrdm)
return -EINVAL;
if (arch_pwrdm && arch_pwrdm->pwrdm_read_logic_pwrst)
ret = arch_pwrdm->pwrdm_read_logic_pwrst(pwrdm);
return ret;
}
int pwrdm_read_prev_logic_pwrst(struct powerdomain *pwrdm)
{
int ret = -EINVAL;
if (!pwrdm)
return -EINVAL;
if (arch_pwrdm && arch_pwrdm->pwrdm_read_prev_logic_pwrst)
ret = arch_pwrdm->pwrdm_read_prev_logic_pwrst(pwrdm);
return ret;
}
int pwrdm_read_logic_retst(struct powerdomain *pwrdm)
{
int ret = -EINVAL;
if (!pwrdm)
return -EINVAL;
if (arch_pwrdm && arch_pwrdm->pwrdm_read_logic_retst)
ret = arch_pwrdm->pwrdm_read_logic_retst(pwrdm);
return ret;
}
int pwrdm_read_mem_pwrst(struct powerdomain *pwrdm, u8 bank)
{
int ret = -EINVAL;
if (!pwrdm)
return ret;
if (pwrdm->banks < (bank + 1))
return ret;
if (pwrdm->flags & PWRDM_HAS_MPU_QUIRK)
bank = 1;
if (arch_pwrdm && arch_pwrdm->pwrdm_read_mem_pwrst)
ret = arch_pwrdm->pwrdm_read_mem_pwrst(pwrdm, bank);
return ret;
}
int pwrdm_read_prev_mem_pwrst(struct powerdomain *pwrdm, u8 bank)
{
int ret = -EINVAL;
if (!pwrdm)
return ret;
if (pwrdm->banks < (bank + 1))
return ret;
if (pwrdm->flags & PWRDM_HAS_MPU_QUIRK)
bank = 1;
if (arch_pwrdm && arch_pwrdm->pwrdm_read_prev_mem_pwrst)
ret = arch_pwrdm->pwrdm_read_prev_mem_pwrst(pwrdm, bank);
return ret;
}
int pwrdm_read_mem_retst(struct powerdomain *pwrdm, u8 bank)
{
int ret = -EINVAL;
if (!pwrdm)
return ret;
if (pwrdm->banks < (bank + 1))
return ret;
if (arch_pwrdm && arch_pwrdm->pwrdm_read_mem_retst)
ret = arch_pwrdm->pwrdm_read_mem_retst(pwrdm, bank);
return ret;
}
int pwrdm_clear_all_prev_pwrst(struct powerdomain *pwrdm)
{
int ret = -EINVAL;
if (!pwrdm)
return ret;
pr_debug("powerdomain: %s: clearing previous power state reg\n",
pwrdm->name);
if (arch_pwrdm && arch_pwrdm->pwrdm_clear_all_prev_pwrst)
ret = arch_pwrdm->pwrdm_clear_all_prev_pwrst(pwrdm);
return ret;
}
int pwrdm_enable_hdwr_sar(struct powerdomain *pwrdm)
{
int ret = -EINVAL;
if (!pwrdm)
return ret;
if (!(pwrdm->flags & PWRDM_HAS_HDWR_SAR))
return ret;
pr_debug("powerdomain: %s: setting SAVEANDRESTORE bit\n", pwrdm->name);
if (arch_pwrdm && arch_pwrdm->pwrdm_enable_hdwr_sar)
ret = arch_pwrdm->pwrdm_enable_hdwr_sar(pwrdm);
return ret;
}
int pwrdm_disable_hdwr_sar(struct powerdomain *pwrdm)
{
int ret = -EINVAL;
if (!pwrdm)
return ret;
if (!(pwrdm->flags & PWRDM_HAS_HDWR_SAR))
return ret;
pr_debug("powerdomain: %s: clearing SAVEANDRESTORE bit\n", pwrdm->name);
if (arch_pwrdm && arch_pwrdm->pwrdm_disable_hdwr_sar)
ret = arch_pwrdm->pwrdm_disable_hdwr_sar(pwrdm);
return ret;
}
bool pwrdm_has_hdwr_sar(struct powerdomain *pwrdm)
{
return (pwrdm && pwrdm->flags & PWRDM_HAS_HDWR_SAR) ? 1 : 0;
}
int pwrdm_state_switch_nolock(struct powerdomain *pwrdm)
{
int ret;
if (!pwrdm || !arch_pwrdm)
return -EINVAL;
ret = arch_pwrdm->pwrdm_wait_transition(pwrdm);
if (!ret)
ret = _pwrdm_state_switch(pwrdm, PWRDM_STATE_NOW);
return ret;
}
int __deprecated pwrdm_state_switch(struct powerdomain *pwrdm)
{
int ret;
pwrdm_lock(pwrdm);
ret = pwrdm_state_switch_nolock(pwrdm);
pwrdm_unlock(pwrdm);
return ret;
}
int pwrdm_pre_transition(struct powerdomain *pwrdm)
{
if (pwrdm)
_pwrdm_pre_transition_cb(pwrdm, NULL);
else
pwrdm_for_each(_pwrdm_pre_transition_cb, NULL);
return 0;
}
int pwrdm_post_transition(struct powerdomain *pwrdm)
{
if (pwrdm)
_pwrdm_post_transition_cb(pwrdm, NULL);
else
pwrdm_for_each(_pwrdm_post_transition_cb, NULL);
return 0;
}
int omap_set_pwrdm_state(struct powerdomain *pwrdm, u8 pwrst)
{
u8 curr_pwrst, next_pwrst, sleep_switch;
int ret = 0;
bool hwsup = false;
if (!pwrdm || IS_ERR(pwrdm))
return -EINVAL;
while (!(pwrdm->pwrsts & (1 << pwrst))) {
if (pwrst == PWRDM_POWER_OFF)
return ret;
pwrst--;
}
pwrdm_lock(pwrdm);
curr_pwrst = pwrdm_read_pwrst(pwrdm);
next_pwrst = pwrdm_read_next_pwrst(pwrdm);
if (curr_pwrst == pwrst && next_pwrst == pwrst)
goto osps_out;
sleep_switch = _pwrdm_save_clkdm_state_and_activate(pwrdm, curr_pwrst,
pwrst, &hwsup);
if (sleep_switch == ERROR_SWITCH) {
ret = -EINVAL;
goto osps_out;
}
ret = pwrdm_set_next_pwrst(pwrdm, pwrst);
if (ret)
pr_err("%s: unable to set power state of powerdomain: %s\n",
__func__, pwrdm->name);
_pwrdm_restore_clkdm_state(pwrdm, sleep_switch, hwsup);
osps_out:
pwrdm_unlock(pwrdm);
return ret;
}
int pwrdm_get_context_loss_count(struct powerdomain *pwrdm)
{
int i, count;
if (!pwrdm) {
WARN(1, "powerdomain: %s: pwrdm is null\n", __func__);
return -ENODEV;
}
count = pwrdm->state_counter[PWRDM_POWER_OFF];
count += pwrdm->ret_logic_off_counter;
for (i = 0; i < pwrdm->banks; i++)
count += pwrdm->ret_mem_off_counter[i];
count &= INT_MAX;
pr_debug("powerdomain: %s: context loss count = %d\n",
pwrdm->name, count);
return count;
}
bool pwrdm_can_ever_lose_context(struct powerdomain *pwrdm)
{
int i;
if (IS_ERR_OR_NULL(pwrdm)) {
pr_debug("powerdomain: %s: invalid powerdomain pointer\n",
__func__);
return 1;
}
if (pwrdm->pwrsts & PWRSTS_OFF)
return 1;
if (pwrdm->pwrsts & PWRSTS_RET) {
if (pwrdm->pwrsts_logic_ret & PWRSTS_OFF)
return 1;
for (i = 0; i < pwrdm->banks; i++)
if (pwrdm->pwrsts_mem_ret[i] & PWRSTS_OFF)
return 1;
}
for (i = 0; i < pwrdm->banks; i++)
if (pwrdm->pwrsts_mem_on[i] & PWRSTS_OFF)
return 1;
return 0;
}
