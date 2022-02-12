static void
default_handler(int segment, struct pt_regs *regp)
{
set_personality(0);
if (current_thread_info()->exec_domain->handler != default_handler)
current_thread_info()->exec_domain->handler(segment, regp);
else
send_sig(SIGSEGV, current, 1);
}
static struct exec_domain *
lookup_exec_domain(unsigned int personality)
{
unsigned int pers = personality(personality);
struct exec_domain *ep;
read_lock(&exec_domains_lock);
for (ep = exec_domains; ep; ep = ep->next) {
if (pers >= ep->pers_low && pers <= ep->pers_high)
if (try_module_get(ep->module))
goto out;
}
#ifdef CONFIG_MODULES
read_unlock(&exec_domains_lock);
request_module("personality-%d", pers);
read_lock(&exec_domains_lock);
for (ep = exec_domains; ep; ep = ep->next) {
if (pers >= ep->pers_low && pers <= ep->pers_high)
if (try_module_get(ep->module))
goto out;
}
#endif
ep = &default_exec_domain;
out:
read_unlock(&exec_domains_lock);
return (ep);
}
int
register_exec_domain(struct exec_domain *ep)
{
struct exec_domain *tmp;
int err = -EBUSY;
if (ep == NULL)
return -EINVAL;
if (ep->next != NULL)
return -EBUSY;
write_lock(&exec_domains_lock);
for (tmp = exec_domains; tmp; tmp = tmp->next) {
if (tmp == ep)
goto out;
}
ep->next = exec_domains;
exec_domains = ep;
err = 0;
out:
write_unlock(&exec_domains_lock);
return (err);
}
int
unregister_exec_domain(struct exec_domain *ep)
{
struct exec_domain **epp;
epp = &exec_domains;
write_lock(&exec_domains_lock);
for (epp = &exec_domains; *epp; epp = &(*epp)->next) {
if (ep == *epp)
goto unregister;
}
write_unlock(&exec_domains_lock);
return -EINVAL;
unregister:
*epp = ep->next;
ep->next = NULL;
write_unlock(&exec_domains_lock);
return 0;
}
int __set_personality(unsigned int personality)
{
struct exec_domain *oep = current_thread_info()->exec_domain;
current_thread_info()->exec_domain = lookup_exec_domain(personality);
current->personality = personality;
module_put(oep->module);
return 0;
}
static int execdomains_proc_show(struct seq_file *m, void *v)
{
struct exec_domain *ep;
read_lock(&exec_domains_lock);
for (ep = exec_domains; ep; ep = ep->next)
seq_printf(m, "%d-%d\t%-16s\t[%s]\n",
ep->pers_low, ep->pers_high, ep->name,
module_name(ep->module));
read_unlock(&exec_domains_lock);
return 0;
}
static int execdomains_proc_open(struct inode *inode, struct file *file)
{
return single_open(file, execdomains_proc_show, NULL);
}
static int __init proc_execdomains_init(void)
{
proc_create("execdomains", 0, NULL, &execdomains_proc_fops);
return 0;
}
