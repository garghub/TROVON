static int omap34_xxbridge_suspend_lockout(struct omap34_xx_bridge_suspend_data
*s, struct file *f)
{
if ((s)->suspended) {
if ((f)->f_flags & O_NONBLOCK)
return -EPERM;
wait_event_interruptible((s)->suspend_wq, (s)->suspended == 0);
}
return 0;
}
static int bridge_open(struct inode *ip, struct file *filp)
{
int status = 0;
struct process_context *pr_ctxt = NULL;
#ifdef CONFIG_TIDSPBRIDGE_RECOVERY
if (recover) {
if (filp->f_flags & O_NONBLOCK ||
wait_for_completion_interruptible(&bridge_open_comp))
return -EBUSY;
}
#endif
pr_ctxt = kzalloc(sizeof(struct process_context), GFP_KERNEL);
if (!pr_ctxt)
return -ENOMEM;
pr_ctxt->res_state = PROC_RES_ALLOCATED;
spin_lock_init(&pr_ctxt->dmm_map_lock);
INIT_LIST_HEAD(&pr_ctxt->dmm_map_list);
spin_lock_init(&pr_ctxt->dmm_rsv_lock);
INIT_LIST_HEAD(&pr_ctxt->dmm_rsv_list);
pr_ctxt->node_id = kzalloc(sizeof(struct idr), GFP_KERNEL);
if (!pr_ctxt->node_id) {
status = -ENOMEM;
goto err1;
}
idr_init(pr_ctxt->node_id);
pr_ctxt->stream_id = kzalloc(sizeof(struct idr), GFP_KERNEL);
if (!pr_ctxt->stream_id) {
status = -ENOMEM;
goto err2;
}
idr_init(pr_ctxt->stream_id);
filp->private_data = pr_ctxt;
#ifdef CONFIG_TIDSPBRIDGE_RECOVERY
atomic_inc(&bridge_cref);
#endif
return 0;
err2:
kfree(pr_ctxt->node_id);
err1:
kfree(pr_ctxt);
return status;
}
static int bridge_release(struct inode *ip, struct file *filp)
{
int status = 0;
struct process_context *pr_ctxt;
if (!filp->private_data) {
status = -EIO;
goto err;
}
pr_ctxt = filp->private_data;
flush_signals(current);
drv_remove_all_resources(pr_ctxt);
proc_detach(pr_ctxt);
kfree(pr_ctxt->node_id);
kfree(pr_ctxt->stream_id);
kfree(pr_ctxt);
filp->private_data = NULL;
err:
#ifdef CONFIG_TIDSPBRIDGE_RECOVERY
if (!atomic_dec_return(&bridge_cref))
complete(&bridge_comp);
#endif
return status;
}
static long bridge_ioctl(struct file *filp, unsigned int code,
unsigned long args)
{
int status;
u32 retval = 0;
union trapped_args buf_in;
#ifdef CONFIG_TIDSPBRIDGE_RECOVERY
if (recover) {
status = -EIO;
goto err;
}
#endif
#ifdef CONFIG_PM
status = omap34_xxbridge_suspend_lockout(&bridge_suspend_data, filp);
if (status != 0)
return status;
#endif
if (!filp->private_data) {
status = -EIO;
goto err;
}
status = copy_from_user(&buf_in, (union trapped_args *)args,
sizeof(union trapped_args));
if (!status) {
status = api_call_dev_ioctl(code, &buf_in, &retval,
filp->private_data);
if (!status) {
status = retval;
} else {
dev_dbg(bridge, "%s: IOCTL Failed, code: 0x%x "
"status 0x%x\n", __func__, code, status);
status = -1;
}
}
err:
return status;
}
static int bridge_mmap(struct file *filp, struct vm_area_struct *vma)
{
u32 status;
vma->vm_page_prot = pgprot_noncached(vma->vm_page_prot);
dev_dbg(bridge, "%s: vm filp %p start %lx end %lx page_prot %ulx "
"flags %lx\n", __func__, filp,
vma->vm_start, vma->vm_end, vma->vm_page_prot,
vma->vm_flags);
status = remap_pfn_range(vma, vma->vm_start, vma->vm_pgoff,
vma->vm_end - vma->vm_start,
vma->vm_page_prot);
if (status != 0)
status = -EAGAIN;
return status;
}
static void bridge_recover(struct work_struct *work)
{
struct dev_object *dev;
struct cfg_devnode *dev_node;
if (atomic_read(&bridge_cref)) {
INIT_COMPLETION(bridge_comp);
while (!wait_for_completion_timeout(&bridge_comp,
msecs_to_jiffies(REC_TIMEOUT)))
pr_info("%s:%d handle(s) still opened\n",
__func__, atomic_read(&bridge_cref));
}
dev = dev_get_first();
dev_get_dev_node(dev, &dev_node);
if (!dev_node || proc_auto_start(dev_node, dev))
pr_err("DSP could not be restarted\n");
recover = false;
complete_all(&bridge_open_comp);
}
void bridge_recover_schedule(void)
{
INIT_COMPLETION(bridge_open_comp);
recover = true;
queue_work(bridge_rec_queue, &bridge_recovery_work);
}
static int dspbridge_scale_notification(struct notifier_block *op,
unsigned long val, void *ptr)
{
struct omap_dsp_platform_data *pdata =
omap_dspbridge_dev->dev.platform_data;
if (CPUFREQ_POSTCHANGE == val && pdata->dsp_get_opp)
pwr_pm_post_scale(PRCM_VDD1, pdata->dsp_get_opp());
return 0;
}
static int omap3_bridge_startup(struct platform_device *pdev)
{
struct omap_dsp_platform_data *pdata = pdev->dev.platform_data;
struct drv_data *drv_datap = NULL;
u32 phys_membase, phys_memsize;
int err;
#ifdef CONFIG_TIDSPBRIDGE_RECOVERY
bridge_rec_queue = create_workqueue("bridge_rec_queue");
INIT_WORK(&bridge_recovery_work, bridge_recover);
INIT_COMPLETION(bridge_comp);
#endif
#ifdef CONFIG_PM
bridge_suspend_data.suspended = 0;
init_waitqueue_head(&bridge_suspend_data.suspend_wq);
#ifdef CONFIG_TIDSPBRIDGE_DVFS
for (i = 0; i < 6; i++)
pdata->mpu_speed[i] = vdd1_rate_table_bridge[i].rate;
err = cpufreq_register_notifier(&iva_clk_notifier,
CPUFREQ_TRANSITION_NOTIFIER);
if (err)
pr_err("%s: clk_notifier_register failed for iva2_ck\n",
__func__);
#endif
#endif
dsp_clk_init();
drv_datap = kzalloc(sizeof(struct drv_data), GFP_KERNEL);
if (!drv_datap) {
err = -ENOMEM;
goto err1;
}
drv_datap->shm_size = shm_size;
drv_datap->tc_wordswapon = tc_wordswapon;
if (base_img) {
drv_datap->base_img = kmalloc(strlen(base_img) + 1, GFP_KERNEL);
if (!drv_datap->base_img) {
err = -ENOMEM;
goto err2;
}
strncpy(drv_datap->base_img, base_img, strlen(base_img) + 1);
}
dev_set_drvdata(bridge, drv_datap);
if (shm_size < 0x10000) {
err = -EINVAL;
pr_err("%s: shm size must be at least 64 KB\n", __func__);
goto err3;
}
dev_dbg(bridge, "%s: requested shm_size = 0x%x\n", __func__, shm_size);
phys_membase = pdata->phys_mempool_base;
phys_memsize = pdata->phys_mempool_size;
if (phys_membase > 0 && phys_memsize > 0)
mem_ext_phys_pool_init(phys_membase, phys_memsize);
if (tc_wordswapon)
dev_dbg(bridge, "%s: TC Word Swap is enabled\n", __func__);
driver_context = dsp_init(&err);
if (err) {
pr_err("DSP Bridge driver initialization failed\n");
goto err4;
}
return 0;
err4:
mem_ext_phys_pool_release();
err3:
kfree(drv_datap->base_img);
err2:
kfree(drv_datap);
err1:
#ifdef CONFIG_TIDSPBRIDGE_DVFS
cpufreq_unregister_notifier(&iva_clk_notifier,
CPUFREQ_TRANSITION_NOTIFIER);
#endif
dsp_clk_exit();
return err;
}
static int omap34_xx_bridge_probe(struct platform_device *pdev)
{
int err;
dev_t dev = 0;
#ifdef CONFIG_TIDSPBRIDGE_DVFS
int i = 0;
#endif
omap_dspbridge_dev = pdev;
bridge = &omap_dspbridge_dev->dev;
err = omap3_bridge_startup(pdev);
if (err)
goto err1;
err = alloc_chrdev_region(&dev, 0, 1, "DspBridge");
if (err) {
pr_err("%s: Can't get major %d\n", __func__, driver_major);
goto err1;
}
cdev_init(&bridge_cdev, &bridge_fops);
bridge_cdev.owner = THIS_MODULE;
err = cdev_add(&bridge_cdev, dev, 1);
if (err) {
pr_err("%s: Failed to add bridge device\n", __func__);
goto err2;
}
bridge_class = class_create(THIS_MODULE, "ti_bridge");
if (IS_ERR(bridge_class)) {
pr_err("%s: Error creating bridge class\n", __func__);
goto err3;
}
driver_major = MAJOR(dev);
device_create(bridge_class, NULL, MKDEV(driver_major, 0),
NULL, "DspBridge");
pr_info("DSP Bridge driver loaded\n");
return 0;
err3:
cdev_del(&bridge_cdev);
err2:
unregister_chrdev_region(dev, 1);
err1:
return err;
}
static int omap34_xx_bridge_remove(struct platform_device *pdev)
{
dev_t devno;
int status = 0;
struct drv_data *drv_datap = dev_get_drvdata(bridge);
if (!drv_datap || !drv_datap->drv_object) {
status = -ENODATA;
pr_err("%s: Failed to retrieve the object handle\n", __func__);
goto func_cont;
}
#ifdef CONFIG_TIDSPBRIDGE_DVFS
if (cpufreq_unregister_notifier(&iva_clk_notifier,
CPUFREQ_TRANSITION_NOTIFIER))
pr_err("%s: cpufreq_unregister_notifier failed for iva2_ck\n",
__func__);
#endif
if (driver_context) {
dsp_deinit(driver_context);
driver_context = 0;
}
kfree(drv_datap);
dev_set_drvdata(bridge, NULL);
func_cont:
mem_ext_phys_pool_release();
dsp_clk_exit();
devno = MKDEV(driver_major, 0);
cdev_del(&bridge_cdev);
unregister_chrdev_region(devno, 1);
if (bridge_class) {
device_destroy(bridge_class, MKDEV(driver_major, 0));
class_destroy(bridge_class);
}
return 0;
}
static int bridge_suspend(struct platform_device *pdev, pm_message_t state)
{
u32 status;
u32 command = PWR_EMERGENCYDEEPSLEEP;
status = pwr_sleep_dsp(command, time_out);
if (status)
return -1;
bridge_suspend_data.suspended = 1;
return 0;
}
static int bridge_resume(struct platform_device *pdev)
{
u32 status;
status = pwr_wake_dsp(time_out);
if (status)
return -1;
bridge_suspend_data.suspended = 0;
wake_up(&bridge_suspend_data.suspend_wq);
return 0;
}
int drv_remove_all_resources(void *process_ctxt)
{
int status = 0;
struct process_context *ctxt = (struct process_context *)process_ctxt;
drv_remove_all_strm_res_elements(ctxt);
drv_remove_all_node_res_elements(ctxt);
drv_remove_all_dmm_res_elements(ctxt);
ctxt->res_state = PROC_RES_FREED;
return status;
}
