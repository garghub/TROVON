static int ipcns_callback(struct notifier_block *self,
unsigned long action, void *arg)
{
struct ipc_namespace *ns;
switch (action) {
case IPCNS_MEMCHANGED:
case IPCNS_CREATED:
case IPCNS_REMOVED:
ns = container_of(self, struct ipc_namespace, ipcns_nb);
recompute_msgmni(ns);
break;
default:
break;
}
return NOTIFY_OK;
}
int register_ipcns_notifier(struct ipc_namespace *ns)
{
int rc;
memset(&ns->ipcns_nb, 0, sizeof(ns->ipcns_nb));
ns->ipcns_nb.notifier_call = ipcns_callback;
ns->ipcns_nb.priority = IPCNS_CALLBACK_PRI;
rc = blocking_notifier_chain_register(&ipcns_chain, &ns->ipcns_nb);
if (!rc)
ns->auto_msgmni = 1;
return rc;
}
int cond_register_ipcns_notifier(struct ipc_namespace *ns)
{
int rc;
memset(&ns->ipcns_nb, 0, sizeof(ns->ipcns_nb));
ns->ipcns_nb.notifier_call = ipcns_callback;
ns->ipcns_nb.priority = IPCNS_CALLBACK_PRI;
rc = blocking_notifier_chain_cond_register(&ipcns_chain,
&ns->ipcns_nb);
if (!rc)
ns->auto_msgmni = 1;
return rc;
}
void unregister_ipcns_notifier(struct ipc_namespace *ns)
{
blocking_notifier_chain_unregister(&ipcns_chain, &ns->ipcns_nb);
ns->auto_msgmni = 0;
}
int ipcns_notify(unsigned long val)
{
return blocking_notifier_call_chain(&ipcns_chain, val, NULL);
}
