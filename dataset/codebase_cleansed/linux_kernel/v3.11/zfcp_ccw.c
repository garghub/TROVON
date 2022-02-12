struct zfcp_adapter *zfcp_ccw_adapter_by_cdev(struct ccw_device *cdev)
{
struct zfcp_adapter *adapter;
unsigned long flags;
spin_lock_irqsave(&zfcp_ccw_adapter_ref_lock, flags);
adapter = dev_get_drvdata(&cdev->dev);
if (adapter)
kref_get(&adapter->ref);
spin_unlock_irqrestore(&zfcp_ccw_adapter_ref_lock, flags);
return adapter;
}
void zfcp_ccw_adapter_put(struct zfcp_adapter *adapter)
{
unsigned long flags;
spin_lock_irqsave(&zfcp_ccw_adapter_ref_lock, flags);
kref_put(&adapter->ref, zfcp_adapter_release);
spin_unlock_irqrestore(&zfcp_ccw_adapter_ref_lock, flags);
}
static int zfcp_ccw_activate(struct ccw_device *cdev, int clear, char *tag)
{
struct zfcp_adapter *adapter = zfcp_ccw_adapter_by_cdev(cdev);
if (!adapter)
return 0;
zfcp_erp_clear_adapter_status(adapter, clear);
zfcp_erp_set_adapter_status(adapter, ZFCP_STATUS_COMMON_RUNNING);
zfcp_erp_adapter_reopen(adapter, ZFCP_STATUS_COMMON_ERP_FAILED,
tag);
zfcp_erp_wait(adapter);
flush_work(&adapter->scan_work);
zfcp_ccw_adapter_put(adapter);
return 0;
}
static int zfcp_ccw_probe(struct ccw_device *cdev)
{
return 0;
}
static void zfcp_ccw_remove(struct ccw_device *cdev)
{
struct zfcp_adapter *adapter;
struct zfcp_port *port, *p;
struct zfcp_unit *unit, *u;
LIST_HEAD(unit_remove_lh);
LIST_HEAD(port_remove_lh);
ccw_device_set_offline(cdev);
adapter = zfcp_ccw_adapter_by_cdev(cdev);
if (!adapter)
return;
write_lock_irq(&adapter->port_list_lock);
list_for_each_entry_safe(port, p, &adapter->port_list, list) {
write_lock(&port->unit_list_lock);
list_for_each_entry_safe(unit, u, &port->unit_list, list)
list_move(&unit->list, &unit_remove_lh);
write_unlock(&port->unit_list_lock);
list_move(&port->list, &port_remove_lh);
}
write_unlock_irq(&adapter->port_list_lock);
zfcp_ccw_adapter_put(adapter);
list_for_each_entry_safe(unit, u, &unit_remove_lh, list)
device_unregister(&unit->dev);
list_for_each_entry_safe(port, p, &port_remove_lh, list)
device_unregister(&port->dev);
zfcp_adapter_unregister(adapter);
}
static int zfcp_ccw_set_online(struct ccw_device *cdev)
{
struct zfcp_adapter *adapter = zfcp_ccw_adapter_by_cdev(cdev);
if (!adapter) {
adapter = zfcp_adapter_enqueue(cdev);
if (IS_ERR(adapter)) {
dev_err(&cdev->dev,
"Setting up data structures for the "
"FCP adapter failed\n");
return PTR_ERR(adapter);
}
kref_get(&adapter->ref);
}
BUG_ON(!zfcp_reqlist_isempty(adapter->req_list));
adapter->req_no = 0;
zfcp_ccw_activate(cdev, 0, "ccsonl1");
zfcp_fc_inverse_conditional_port_scan(adapter);
flush_work(&adapter->scan_work);
zfcp_ccw_adapter_put(adapter);
return 0;
}
static int zfcp_ccw_offline_sync(struct ccw_device *cdev, int set, char *tag)
{
struct zfcp_adapter *adapter = zfcp_ccw_adapter_by_cdev(cdev);
if (!adapter)
return 0;
zfcp_erp_set_adapter_status(adapter, set);
zfcp_erp_adapter_shutdown(adapter, 0, tag);
zfcp_erp_wait(adapter);
zfcp_ccw_adapter_put(adapter);
return 0;
}
static int zfcp_ccw_set_offline(struct ccw_device *cdev)
{
return zfcp_ccw_offline_sync(cdev, 0, "ccsoff1");
}
static int zfcp_ccw_notify(struct ccw_device *cdev, int event)
{
struct zfcp_adapter *adapter = zfcp_ccw_adapter_by_cdev(cdev);
if (!adapter)
return 1;
switch (event) {
case CIO_GONE:
if (atomic_read(&adapter->status) &
ZFCP_STATUS_ADAPTER_SUSPENDED) {
zfcp_dbf_hba_basic("ccnigo1", adapter);
break;
}
dev_warn(&cdev->dev, "The FCP device has been detached\n");
zfcp_erp_adapter_shutdown(adapter, 0, "ccnoti1");
break;
case CIO_NO_PATH:
dev_warn(&cdev->dev,
"The CHPID for the FCP device is offline\n");
zfcp_erp_adapter_shutdown(adapter, 0, "ccnoti2");
break;
case CIO_OPER:
if (atomic_read(&adapter->status) &
ZFCP_STATUS_ADAPTER_SUSPENDED) {
zfcp_dbf_hba_basic("ccniop1", adapter);
break;
}
dev_info(&cdev->dev, "The FCP device is operational again\n");
zfcp_erp_set_adapter_status(adapter,
ZFCP_STATUS_COMMON_RUNNING);
zfcp_erp_adapter_reopen(adapter, ZFCP_STATUS_COMMON_ERP_FAILED,
"ccnoti4");
break;
case CIO_BOXED:
dev_warn(&cdev->dev, "The FCP device did not respond within "
"the specified time\n");
zfcp_erp_adapter_shutdown(adapter, 0, "ccnoti5");
break;
}
zfcp_ccw_adapter_put(adapter);
return 1;
}
static void zfcp_ccw_shutdown(struct ccw_device *cdev)
{
struct zfcp_adapter *adapter = zfcp_ccw_adapter_by_cdev(cdev);
if (!adapter)
return;
zfcp_erp_adapter_shutdown(adapter, 0, "ccshut1");
zfcp_erp_wait(adapter);
zfcp_erp_thread_kill(adapter);
zfcp_ccw_adapter_put(adapter);
}
static int zfcp_ccw_suspend(struct ccw_device *cdev)
{
zfcp_ccw_offline_sync(cdev, ZFCP_STATUS_ADAPTER_SUSPENDED, "ccsusp1");
return 0;
}
static int zfcp_ccw_thaw(struct ccw_device *cdev)
{
zfcp_ccw_activate(cdev, 0, "ccthaw1");
return 0;
}
static int zfcp_ccw_resume(struct ccw_device *cdev)
{
zfcp_ccw_activate(cdev, ZFCP_STATUS_ADAPTER_SUSPENDED, "ccresu1");
return 0;
}
