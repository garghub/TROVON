static irqreturn_t bad_chained_irq(int irq, void *dev_id)
{
WARN_ONCE(1, "Chained irq %d should not call an action\n", irq);
return IRQ_NONE;
}
int irq_set_chip(unsigned int irq, struct irq_chip *chip)
{
unsigned long flags;
struct irq_desc *desc = irq_get_desc_lock(irq, &flags, 0);
if (!desc)
return -EINVAL;
if (!chip)
chip = &no_irq_chip;
desc->irq_data.chip = chip;
irq_put_desc_unlock(desc, flags);
irq_mark_irq(irq);
return 0;
}
int irq_set_irq_type(unsigned int irq, unsigned int type)
{
unsigned long flags;
struct irq_desc *desc = irq_get_desc_buslock(irq, &flags, IRQ_GET_DESC_CHECK_GLOBAL);
int ret = 0;
if (!desc)
return -EINVAL;
type &= IRQ_TYPE_SENSE_MASK;
ret = __irq_set_trigger(desc, type);
irq_put_desc_busunlock(desc, flags);
return ret;
}
int irq_set_handler_data(unsigned int irq, void *data)
{
unsigned long flags;
struct irq_desc *desc = irq_get_desc_lock(irq, &flags, 0);
if (!desc)
return -EINVAL;
desc->irq_common_data.handler_data = data;
irq_put_desc_unlock(desc, flags);
return 0;
}
int irq_set_msi_desc_off(unsigned int irq_base, unsigned int irq_offset,
struct msi_desc *entry)
{
unsigned long flags;
struct irq_desc *desc = irq_get_desc_lock(irq_base + irq_offset, &flags, IRQ_GET_DESC_CHECK_GLOBAL);
if (!desc)
return -EINVAL;
desc->irq_common_data.msi_desc = entry;
if (entry && !irq_offset)
entry->irq = irq_base;
irq_put_desc_unlock(desc, flags);
return 0;
}
int irq_set_msi_desc(unsigned int irq, struct msi_desc *entry)
{
return irq_set_msi_desc_off(irq, 0, entry);
}
int irq_set_chip_data(unsigned int irq, void *data)
{
unsigned long flags;
struct irq_desc *desc = irq_get_desc_lock(irq, &flags, 0);
if (!desc)
return -EINVAL;
desc->irq_data.chip_data = data;
irq_put_desc_unlock(desc, flags);
return 0;
}
struct irq_data *irq_get_irq_data(unsigned int irq)
{
struct irq_desc *desc = irq_to_desc(irq);
return desc ? &desc->irq_data : NULL;
}
static void irq_state_clr_disabled(struct irq_desc *desc)
{
irqd_clear(&desc->irq_data, IRQD_IRQ_DISABLED);
}
static void irq_state_set_disabled(struct irq_desc *desc)
{
irqd_set(&desc->irq_data, IRQD_IRQ_DISABLED);
}
static void irq_state_clr_masked(struct irq_desc *desc)
{
irqd_clear(&desc->irq_data, IRQD_IRQ_MASKED);
}
static void irq_state_set_masked(struct irq_desc *desc)
{
irqd_set(&desc->irq_data, IRQD_IRQ_MASKED);
}
int irq_startup(struct irq_desc *desc, bool resend)
{
int ret = 0;
irq_state_clr_disabled(desc);
desc->depth = 0;
irq_domain_activate_irq(&desc->irq_data);
if (desc->irq_data.chip->irq_startup) {
ret = desc->irq_data.chip->irq_startup(&desc->irq_data);
irq_state_clr_masked(desc);
} else {
irq_enable(desc);
}
if (resend)
check_irq_resend(desc);
return ret;
}
void irq_shutdown(struct irq_desc *desc)
{
irq_state_set_disabled(desc);
desc->depth = 1;
if (desc->irq_data.chip->irq_shutdown)
desc->irq_data.chip->irq_shutdown(&desc->irq_data);
else if (desc->irq_data.chip->irq_disable)
desc->irq_data.chip->irq_disable(&desc->irq_data);
else
desc->irq_data.chip->irq_mask(&desc->irq_data);
irq_domain_deactivate_irq(&desc->irq_data);
irq_state_set_masked(desc);
}
void irq_enable(struct irq_desc *desc)
{
irq_state_clr_disabled(desc);
if (desc->irq_data.chip->irq_enable)
desc->irq_data.chip->irq_enable(&desc->irq_data);
else
desc->irq_data.chip->irq_unmask(&desc->irq_data);
irq_state_clr_masked(desc);
}
void irq_disable(struct irq_desc *desc)
{
irq_state_set_disabled(desc);
if (desc->irq_data.chip->irq_disable) {
desc->irq_data.chip->irq_disable(&desc->irq_data);
irq_state_set_masked(desc);
} else if (irq_settings_disable_unlazy(desc)) {
mask_irq(desc);
}
}
void irq_percpu_enable(struct irq_desc *desc, unsigned int cpu)
{
if (desc->irq_data.chip->irq_enable)
desc->irq_data.chip->irq_enable(&desc->irq_data);
else
desc->irq_data.chip->irq_unmask(&desc->irq_data);
cpumask_set_cpu(cpu, desc->percpu_enabled);
}
void irq_percpu_disable(struct irq_desc *desc, unsigned int cpu)
{
if (desc->irq_data.chip->irq_disable)
desc->irq_data.chip->irq_disable(&desc->irq_data);
else
desc->irq_data.chip->irq_mask(&desc->irq_data);
cpumask_clear_cpu(cpu, desc->percpu_enabled);
}
static inline void mask_ack_irq(struct irq_desc *desc)
{
if (desc->irq_data.chip->irq_mask_ack)
desc->irq_data.chip->irq_mask_ack(&desc->irq_data);
else {
desc->irq_data.chip->irq_mask(&desc->irq_data);
if (desc->irq_data.chip->irq_ack)
desc->irq_data.chip->irq_ack(&desc->irq_data);
}
irq_state_set_masked(desc);
}
void mask_irq(struct irq_desc *desc)
{
if (desc->irq_data.chip->irq_mask) {
desc->irq_data.chip->irq_mask(&desc->irq_data);
irq_state_set_masked(desc);
}
}
void unmask_irq(struct irq_desc *desc)
{
if (desc->irq_data.chip->irq_unmask) {
desc->irq_data.chip->irq_unmask(&desc->irq_data);
irq_state_clr_masked(desc);
}
}
void unmask_threaded_irq(struct irq_desc *desc)
{
struct irq_chip *chip = desc->irq_data.chip;
if (chip->flags & IRQCHIP_EOI_THREADED)
chip->irq_eoi(&desc->irq_data);
if (chip->irq_unmask) {
chip->irq_unmask(&desc->irq_data);
irq_state_clr_masked(desc);
}
}
void handle_nested_irq(unsigned int irq)
{
struct irq_desc *desc = irq_to_desc(irq);
struct irqaction *action;
irqreturn_t action_ret;
might_sleep();
raw_spin_lock_irq(&desc->lock);
desc->istate &= ~(IRQS_REPLAY | IRQS_WAITING);
kstat_incr_irqs_this_cpu(desc);
action = desc->action;
if (unlikely(!action || irqd_irq_disabled(&desc->irq_data))) {
desc->istate |= IRQS_PENDING;
goto out_unlock;
}
irqd_set(&desc->irq_data, IRQD_IRQ_INPROGRESS);
raw_spin_unlock_irq(&desc->lock);
action_ret = action->thread_fn(action->irq, action->dev_id);
if (!noirqdebug)
note_interrupt(desc, action_ret);
raw_spin_lock_irq(&desc->lock);
irqd_clear(&desc->irq_data, IRQD_IRQ_INPROGRESS);
out_unlock:
raw_spin_unlock_irq(&desc->lock);
}
static bool irq_check_poll(struct irq_desc *desc)
{
if (!(desc->istate & IRQS_POLL_INPROGRESS))
return false;
return irq_wait_for_poll(desc);
}
static bool irq_may_run(struct irq_desc *desc)
{
unsigned int mask = IRQD_IRQ_INPROGRESS | IRQD_WAKEUP_ARMED;
if (!irqd_has_set(&desc->irq_data, mask))
return true;
if (irq_pm_check_wakeup(desc))
return false;
return irq_check_poll(desc);
}
void handle_simple_irq(struct irq_desc *desc)
{
raw_spin_lock(&desc->lock);
if (!irq_may_run(desc))
goto out_unlock;
desc->istate &= ~(IRQS_REPLAY | IRQS_WAITING);
kstat_incr_irqs_this_cpu(desc);
if (unlikely(!desc->action || irqd_irq_disabled(&desc->irq_data))) {
desc->istate |= IRQS_PENDING;
goto out_unlock;
}
handle_irq_event(desc);
out_unlock:
raw_spin_unlock(&desc->lock);
}
static void cond_unmask_irq(struct irq_desc *desc)
{
if (!irqd_irq_disabled(&desc->irq_data) &&
irqd_irq_masked(&desc->irq_data) && !desc->threads_oneshot)
unmask_irq(desc);
}
void handle_level_irq(struct irq_desc *desc)
{
raw_spin_lock(&desc->lock);
mask_ack_irq(desc);
if (!irq_may_run(desc))
goto out_unlock;
desc->istate &= ~(IRQS_REPLAY | IRQS_WAITING);
kstat_incr_irqs_this_cpu(desc);
if (unlikely(!desc->action || irqd_irq_disabled(&desc->irq_data))) {
desc->istate |= IRQS_PENDING;
goto out_unlock;
}
handle_irq_event(desc);
cond_unmask_irq(desc);
out_unlock:
raw_spin_unlock(&desc->lock);
}
static inline void preflow_handler(struct irq_desc *desc)
{
if (desc->preflow_handler)
desc->preflow_handler(&desc->irq_data);
}
static inline void preflow_handler(struct irq_desc *desc) { }
static void cond_unmask_eoi_irq(struct irq_desc *desc, struct irq_chip *chip)
{
if (!(desc->istate & IRQS_ONESHOT)) {
chip->irq_eoi(&desc->irq_data);
return;
}
if (!irqd_irq_disabled(&desc->irq_data) &&
irqd_irq_masked(&desc->irq_data) && !desc->threads_oneshot) {
chip->irq_eoi(&desc->irq_data);
unmask_irq(desc);
} else if (!(chip->flags & IRQCHIP_EOI_THREADED)) {
chip->irq_eoi(&desc->irq_data);
}
}
void handle_fasteoi_irq(struct irq_desc *desc)
{
struct irq_chip *chip = desc->irq_data.chip;
raw_spin_lock(&desc->lock);
if (!irq_may_run(desc))
goto out;
desc->istate &= ~(IRQS_REPLAY | IRQS_WAITING);
kstat_incr_irqs_this_cpu(desc);
if (unlikely(!desc->action || irqd_irq_disabled(&desc->irq_data))) {
desc->istate |= IRQS_PENDING;
mask_irq(desc);
goto out;
}
if (desc->istate & IRQS_ONESHOT)
mask_irq(desc);
preflow_handler(desc);
handle_irq_event(desc);
cond_unmask_eoi_irq(desc, chip);
raw_spin_unlock(&desc->lock);
return;
out:
if (!(chip->flags & IRQCHIP_EOI_IF_HANDLED))
chip->irq_eoi(&desc->irq_data);
raw_spin_unlock(&desc->lock);
}
void handle_edge_irq(struct irq_desc *desc)
{
raw_spin_lock(&desc->lock);
desc->istate &= ~(IRQS_REPLAY | IRQS_WAITING);
if (!irq_may_run(desc)) {
desc->istate |= IRQS_PENDING;
mask_ack_irq(desc);
goto out_unlock;
}
if (irqd_irq_disabled(&desc->irq_data) || !desc->action) {
desc->istate |= IRQS_PENDING;
mask_ack_irq(desc);
goto out_unlock;
}
kstat_incr_irqs_this_cpu(desc);
desc->irq_data.chip->irq_ack(&desc->irq_data);
do {
if (unlikely(!desc->action)) {
mask_irq(desc);
goto out_unlock;
}
if (unlikely(desc->istate & IRQS_PENDING)) {
if (!irqd_irq_disabled(&desc->irq_data) &&
irqd_irq_masked(&desc->irq_data))
unmask_irq(desc);
}
handle_irq_event(desc);
} while ((desc->istate & IRQS_PENDING) &&
!irqd_irq_disabled(&desc->irq_data));
out_unlock:
raw_spin_unlock(&desc->lock);
}
void handle_edge_eoi_irq(struct irq_desc *desc)
{
struct irq_chip *chip = irq_desc_get_chip(desc);
raw_spin_lock(&desc->lock);
desc->istate &= ~(IRQS_REPLAY | IRQS_WAITING);
if (!irq_may_run(desc)) {
desc->istate |= IRQS_PENDING;
goto out_eoi;
}
if (irqd_irq_disabled(&desc->irq_data) || !desc->action) {
desc->istate |= IRQS_PENDING;
goto out_eoi;
}
kstat_incr_irqs_this_cpu(desc);
do {
if (unlikely(!desc->action))
goto out_eoi;
handle_irq_event(desc);
} while ((desc->istate & IRQS_PENDING) &&
!irqd_irq_disabled(&desc->irq_data));
out_eoi:
chip->irq_eoi(&desc->irq_data);
raw_spin_unlock(&desc->lock);
}
void handle_percpu_irq(struct irq_desc *desc)
{
struct irq_chip *chip = irq_desc_get_chip(desc);
kstat_incr_irqs_this_cpu(desc);
if (chip->irq_ack)
chip->irq_ack(&desc->irq_data);
handle_irq_event_percpu(desc);
if (chip->irq_eoi)
chip->irq_eoi(&desc->irq_data);
}
void handle_percpu_devid_irq(struct irq_desc *desc)
{
struct irq_chip *chip = irq_desc_get_chip(desc);
struct irqaction *action = desc->action;
void *dev_id = raw_cpu_ptr(action->percpu_dev_id);
unsigned int irq = irq_desc_get_irq(desc);
irqreturn_t res;
kstat_incr_irqs_this_cpu(desc);
if (chip->irq_ack)
chip->irq_ack(&desc->irq_data);
trace_irq_handler_entry(irq, action);
res = action->handler(irq, dev_id);
trace_irq_handler_exit(irq, action, res);
if (chip->irq_eoi)
chip->irq_eoi(&desc->irq_data);
}
void
__irq_do_set_handler(struct irq_desc *desc, irq_flow_handler_t handle,
int is_chained, const char *name)
{
if (!handle) {
handle = handle_bad_irq;
} else {
struct irq_data *irq_data = &desc->irq_data;
#ifdef CONFIG_IRQ_DOMAIN_HIERARCHY
while (irq_data) {
if (irq_data->chip != &no_irq_chip)
break;
if (WARN_ON(is_chained))
return;
irq_data = irq_data->parent_data;
}
#endif
if (WARN_ON(!irq_data || irq_data->chip == &no_irq_chip))
return;
}
if (handle == handle_bad_irq) {
if (desc->irq_data.chip != &no_irq_chip)
mask_ack_irq(desc);
irq_state_set_disabled(desc);
if (is_chained)
desc->action = NULL;
desc->depth = 1;
}
desc->handle_irq = handle;
desc->name = name;
if (handle != handle_bad_irq && is_chained) {
irq_settings_set_noprobe(desc);
irq_settings_set_norequest(desc);
irq_settings_set_nothread(desc);
desc->action = &chained_action;
irq_startup(desc, true);
}
}
void
__irq_set_handler(unsigned int irq, irq_flow_handler_t handle, int is_chained,
const char *name)
{
unsigned long flags;
struct irq_desc *desc = irq_get_desc_buslock(irq, &flags, 0);
if (!desc)
return;
__irq_do_set_handler(desc, handle, is_chained, name);
irq_put_desc_busunlock(desc, flags);
}
void
irq_set_chained_handler_and_data(unsigned int irq, irq_flow_handler_t handle,
void *data)
{
unsigned long flags;
struct irq_desc *desc = irq_get_desc_buslock(irq, &flags, 0);
if (!desc)
return;
__irq_do_set_handler(desc, handle, 1, NULL);
desc->irq_common_data.handler_data = data;
irq_put_desc_busunlock(desc, flags);
}
void
irq_set_chip_and_handler_name(unsigned int irq, struct irq_chip *chip,
irq_flow_handler_t handle, const char *name)
{
irq_set_chip(irq, chip);
__irq_set_handler(irq, handle, 0, name);
}
void irq_modify_status(unsigned int irq, unsigned long clr, unsigned long set)
{
unsigned long flags;
struct irq_desc *desc = irq_get_desc_lock(irq, &flags, 0);
if (!desc)
return;
irq_settings_clr_and_set(desc, clr, set);
irqd_clear(&desc->irq_data, IRQD_NO_BALANCING | IRQD_PER_CPU |
IRQD_TRIGGER_MASK | IRQD_LEVEL | IRQD_MOVE_PCNTXT);
if (irq_settings_has_no_balance_set(desc))
irqd_set(&desc->irq_data, IRQD_NO_BALANCING);
if (irq_settings_is_per_cpu(desc))
irqd_set(&desc->irq_data, IRQD_PER_CPU);
if (irq_settings_can_move_pcntxt(desc))
irqd_set(&desc->irq_data, IRQD_MOVE_PCNTXT);
if (irq_settings_is_level(desc))
irqd_set(&desc->irq_data, IRQD_LEVEL);
irqd_set(&desc->irq_data, irq_settings_get_trigger_mask(desc));
irq_put_desc_unlock(desc, flags);
}
void irq_cpu_online(void)
{
struct irq_desc *desc;
struct irq_chip *chip;
unsigned long flags;
unsigned int irq;
for_each_active_irq(irq) {
desc = irq_to_desc(irq);
if (!desc)
continue;
raw_spin_lock_irqsave(&desc->lock, flags);
chip = irq_data_get_irq_chip(&desc->irq_data);
if (chip && chip->irq_cpu_online &&
(!(chip->flags & IRQCHIP_ONOFFLINE_ENABLED) ||
!irqd_irq_disabled(&desc->irq_data)))
chip->irq_cpu_online(&desc->irq_data);
raw_spin_unlock_irqrestore(&desc->lock, flags);
}
}
void irq_cpu_offline(void)
{
struct irq_desc *desc;
struct irq_chip *chip;
unsigned long flags;
unsigned int irq;
for_each_active_irq(irq) {
desc = irq_to_desc(irq);
if (!desc)
continue;
raw_spin_lock_irqsave(&desc->lock, flags);
chip = irq_data_get_irq_chip(&desc->irq_data);
if (chip && chip->irq_cpu_offline &&
(!(chip->flags & IRQCHIP_ONOFFLINE_ENABLED) ||
!irqd_irq_disabled(&desc->irq_data)))
chip->irq_cpu_offline(&desc->irq_data);
raw_spin_unlock_irqrestore(&desc->lock, flags);
}
}
void irq_chip_enable_parent(struct irq_data *data)
{
data = data->parent_data;
if (data->chip->irq_enable)
data->chip->irq_enable(data);
else
data->chip->irq_unmask(data);
}
void irq_chip_disable_parent(struct irq_data *data)
{
data = data->parent_data;
if (data->chip->irq_disable)
data->chip->irq_disable(data);
else
data->chip->irq_mask(data);
}
void irq_chip_ack_parent(struct irq_data *data)
{
data = data->parent_data;
data->chip->irq_ack(data);
}
void irq_chip_mask_parent(struct irq_data *data)
{
data = data->parent_data;
data->chip->irq_mask(data);
}
void irq_chip_unmask_parent(struct irq_data *data)
{
data = data->parent_data;
data->chip->irq_unmask(data);
}
void irq_chip_eoi_parent(struct irq_data *data)
{
data = data->parent_data;
data->chip->irq_eoi(data);
}
int irq_chip_set_affinity_parent(struct irq_data *data,
const struct cpumask *dest, bool force)
{
data = data->parent_data;
if (data->chip->irq_set_affinity)
return data->chip->irq_set_affinity(data, dest, force);
return -ENOSYS;
}
int irq_chip_set_type_parent(struct irq_data *data, unsigned int type)
{
data = data->parent_data;
if (data->chip->irq_set_type)
return data->chip->irq_set_type(data, type);
return -ENOSYS;
}
int irq_chip_retrigger_hierarchy(struct irq_data *data)
{
for (data = data->parent_data; data; data = data->parent_data)
if (data->chip && data->chip->irq_retrigger)
return data->chip->irq_retrigger(data);
return 0;
}
int irq_chip_set_vcpu_affinity_parent(struct irq_data *data, void *vcpu_info)
{
data = data->parent_data;
if (data->chip->irq_set_vcpu_affinity)
return data->chip->irq_set_vcpu_affinity(data, vcpu_info);
return -ENOSYS;
}
int irq_chip_set_wake_parent(struct irq_data *data, unsigned int on)
{
data = data->parent_data;
if (data->chip->irq_set_wake)
return data->chip->irq_set_wake(data, on);
return -ENOSYS;
}
int irq_chip_compose_msi_msg(struct irq_data *data, struct msi_msg *msg)
{
struct irq_data *pos = NULL;
#ifdef CONFIG_IRQ_DOMAIN_HIERARCHY
for (; data; data = data->parent_data)
#endif
if (data->chip && data->chip->irq_compose_msi_msg)
pos = data;
if (!pos)
return -ENOSYS;
pos->chip->irq_compose_msi_msg(pos, msg);
return 0;
}
