struct edac_pci_ctl_info *edac_pci_alloc_ctl_info(unsigned int sz_pvt,
const char *edac_pci_name)
{
struct edac_pci_ctl_info *pci;
void *p = NULL, *pvt;
unsigned int size;
edac_dbg(1, "\n");
pci = edac_align_ptr(&p, sizeof(*pci), 1);
pvt = edac_align_ptr(&p, 1, sz_pvt);
size = ((unsigned long)pvt) + sz_pvt;
pci = kzalloc(size, GFP_KERNEL);
if (pci == NULL)
return NULL;
pvt = sz_pvt ? ((char *)pci) + ((unsigned long)pvt) : NULL;
pci->pvt_info = pvt;
pci->op_state = OP_ALLOC;
snprintf(pci->name, strlen(edac_pci_name) + 1, "%s", edac_pci_name);
return pci;
}
void edac_pci_free_ctl_info(struct edac_pci_ctl_info *pci)
{
edac_dbg(1, "\n");
edac_pci_remove_sysfs(pci);
}
static struct edac_pci_ctl_info *find_edac_pci_by_dev(struct device *dev)
{
struct edac_pci_ctl_info *pci;
struct list_head *item;
edac_dbg(1, "\n");
list_for_each(item, &edac_pci_list) {
pci = list_entry(item, struct edac_pci_ctl_info, link);
if (pci->dev == dev)
return pci;
}
return NULL;
}
static int add_edac_pci_to_global_list(struct edac_pci_ctl_info *pci)
{
struct list_head *item, *insert_before;
struct edac_pci_ctl_info *rover;
edac_dbg(1, "\n");
insert_before = &edac_pci_list;
rover = find_edac_pci_by_dev(pci->dev);
if (unlikely(rover != NULL))
goto fail0;
list_for_each(item, &edac_pci_list) {
rover = list_entry(item, struct edac_pci_ctl_info, link);
if (rover->pci_idx >= pci->pci_idx) {
if (unlikely(rover->pci_idx == pci->pci_idx))
goto fail1;
insert_before = item;
break;
}
}
list_add_tail_rcu(&pci->link, insert_before);
return 0;
fail0:
edac_printk(KERN_WARNING, EDAC_PCI,
"%s (%s) %s %s already assigned %d\n",
dev_name(rover->dev), edac_dev_name(rover),
rover->mod_name, rover->ctl_name, rover->pci_idx);
return 1;
fail1:
edac_printk(KERN_WARNING, EDAC_PCI,
"but in low-level driver: attempt to assign\n"
"\tduplicate pci_idx %d in %s()\n", rover->pci_idx,
__func__);
return 1;
}
static void del_edac_pci_from_global_list(struct edac_pci_ctl_info *pci)
{
list_del_rcu(&pci->link);
synchronize_rcu();
INIT_LIST_HEAD(&pci->link);
}
static void edac_pci_workq_function(struct work_struct *work_req)
{
struct delayed_work *d_work = to_delayed_work(work_req);
struct edac_pci_ctl_info *pci = to_edac_pci_ctl_work(d_work);
int msec;
unsigned long delay;
edac_dbg(3, "checking\n");
mutex_lock(&edac_pci_ctls_mutex);
if (pci->op_state == OP_RUNNING_POLL) {
if ((pci->edac_check != NULL) && edac_pci_get_check_errors())
pci->edac_check(pci);
msec = edac_pci_get_poll_msec();
if (msec == 1000)
delay = round_jiffies_relative(msecs_to_jiffies(msec));
else
delay = msecs_to_jiffies(msec);
queue_delayed_work(edac_workqueue, &pci->work, delay);
}
mutex_unlock(&edac_pci_ctls_mutex);
}
static void edac_pci_workq_setup(struct edac_pci_ctl_info *pci,
unsigned int msec)
{
edac_dbg(0, "\n");
INIT_DELAYED_WORK(&pci->work, edac_pci_workq_function);
queue_delayed_work(edac_workqueue, &pci->work,
msecs_to_jiffies(edac_pci_get_poll_msec()));
}
static void edac_pci_workq_teardown(struct edac_pci_ctl_info *pci)
{
int status;
edac_dbg(0, "\n");
status = cancel_delayed_work(&pci->work);
if (status == 0)
flush_workqueue(edac_workqueue);
}
void edac_pci_reset_delay_period(struct edac_pci_ctl_info *pci,
unsigned long value)
{
edac_dbg(0, "\n");
edac_pci_workq_teardown(pci);
mutex_lock(&edac_pci_ctls_mutex);
edac_pci_workq_setup(pci, value);
mutex_unlock(&edac_pci_ctls_mutex);
}
int edac_pci_alloc_index(void)
{
return atomic_inc_return(&pci_indexes) - 1;
}
int edac_pci_add_device(struct edac_pci_ctl_info *pci, int edac_idx)
{
edac_dbg(0, "\n");
pci->pci_idx = edac_idx;
pci->start_time = jiffies;
mutex_lock(&edac_pci_ctls_mutex);
if (add_edac_pci_to_global_list(pci))
goto fail0;
if (edac_pci_create_sysfs(pci)) {
edac_pci_printk(pci, KERN_WARNING,
"failed to create sysfs pci\n");
goto fail1;
}
if (pci->edac_check != NULL) {
pci->op_state = OP_RUNNING_POLL;
edac_pci_workq_setup(pci, 1000);
} else {
pci->op_state = OP_RUNNING_INTERRUPT;
}
edac_pci_printk(pci, KERN_INFO,
"Giving out device to module %s controller %s: DEV %s (%s)\n",
pci->mod_name, pci->ctl_name, pci->dev_name,
edac_op_state_to_string(pci->op_state));
mutex_unlock(&edac_pci_ctls_mutex);
return 0;
fail1:
del_edac_pci_from_global_list(pci);
fail0:
mutex_unlock(&edac_pci_ctls_mutex);
return 1;
}
struct edac_pci_ctl_info *edac_pci_del_device(struct device *dev)
{
struct edac_pci_ctl_info *pci;
edac_dbg(0, "\n");
mutex_lock(&edac_pci_ctls_mutex);
pci = find_edac_pci_by_dev(dev);
if (pci == NULL) {
mutex_unlock(&edac_pci_ctls_mutex);
return NULL;
}
pci->op_state = OP_OFFLINE;
del_edac_pci_from_global_list(pci);
mutex_unlock(&edac_pci_ctls_mutex);
edac_pci_workq_teardown(pci);
edac_printk(KERN_INFO, EDAC_PCI,
"Removed device %d for %s %s: DEV %s\n",
pci->pci_idx, pci->mod_name, pci->ctl_name, edac_dev_name(pci));
return pci;
}
static void edac_pci_generic_check(struct edac_pci_ctl_info *pci)
{
edac_dbg(4, "\n");
edac_pci_do_parity_check();
}
struct edac_pci_ctl_info *edac_pci_create_generic_ctl(struct device *dev,
const char *mod_name)
{
struct edac_pci_ctl_info *pci;
struct edac_pci_gen_data *pdata;
pci = edac_pci_alloc_ctl_info(sizeof(*pdata), EDAC_PCI_GENCTL_NAME);
if (!pci)
return NULL;
pdata = pci->pvt_info;
pci->dev = dev;
dev_set_drvdata(pci->dev, pci);
pci->dev_name = pci_name(to_pci_dev(dev));
pci->mod_name = mod_name;
pci->ctl_name = EDAC_PCI_GENCTL_NAME;
if (edac_op_state == EDAC_OPSTATE_POLL)
pci->edac_check = edac_pci_generic_check;
pdata->edac_idx = edac_pci_idx++;
if (edac_pci_add_device(pci, pdata->edac_idx) > 0) {
edac_dbg(3, "failed edac_pci_add_device()\n");
edac_pci_free_ctl_info(pci);
return NULL;
}
return pci;
}
void edac_pci_release_generic_ctl(struct edac_pci_ctl_info *pci)
{
edac_dbg(0, "pci mod=%s\n", pci->mod_name);
edac_pci_del_device(pci->dev);
edac_pci_free_ctl_info(pci);
}
