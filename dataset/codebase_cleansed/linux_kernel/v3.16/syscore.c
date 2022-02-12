void register_syscore_ops(struct syscore_ops *ops)
{
mutex_lock(&syscore_ops_lock);
list_add_tail(&ops->node, &syscore_ops_list);
mutex_unlock(&syscore_ops_lock);
}
void unregister_syscore_ops(struct syscore_ops *ops)
{
mutex_lock(&syscore_ops_lock);
list_del(&ops->node);
mutex_unlock(&syscore_ops_lock);
}
int syscore_suspend(void)
{
struct syscore_ops *ops;
int ret = 0;
trace_suspend_resume(TPS("syscore_suspend"), 0, true);
pr_debug("Checking wakeup interrupts\n");
ret = check_wakeup_irqs();
if (ret)
return ret;
WARN_ONCE(!irqs_disabled(),
"Interrupts enabled before system core suspend.\n");
list_for_each_entry_reverse(ops, &syscore_ops_list, node)
if (ops->suspend) {
if (initcall_debug)
pr_info("PM: Calling %pF\n", ops->suspend);
ret = ops->suspend();
if (ret)
goto err_out;
WARN_ONCE(!irqs_disabled(),
"Interrupts enabled after %pF\n", ops->suspend);
}
trace_suspend_resume(TPS("syscore_suspend"), 0, false);
return 0;
err_out:
pr_err("PM: System core suspend callback %pF failed.\n", ops->suspend);
list_for_each_entry_continue(ops, &syscore_ops_list, node)
if (ops->resume)
ops->resume();
return ret;
}
void syscore_resume(void)
{
struct syscore_ops *ops;
trace_suspend_resume(TPS("syscore_resume"), 0, true);
WARN_ONCE(!irqs_disabled(),
"Interrupts enabled before system core resume.\n");
list_for_each_entry(ops, &syscore_ops_list, node)
if (ops->resume) {
if (initcall_debug)
pr_info("PM: Calling %pF\n", ops->resume);
ops->resume();
WARN_ONCE(!irqs_disabled(),
"Interrupts enabled after %pF\n", ops->resume);
}
trace_suspend_resume(TPS("syscore_resume"), 0, false);
}
void syscore_shutdown(void)
{
struct syscore_ops *ops;
mutex_lock(&syscore_ops_lock);
list_for_each_entry_reverse(ops, &syscore_ops_list, node)
if (ops->shutdown) {
if (initcall_debug)
pr_info("PM: Calling %pF\n", ops->shutdown);
ops->shutdown();
}
mutex_unlock(&syscore_ops_lock);
}
