static int pseries_suspend_begin(suspend_state_t state)
{
long vasi_state, rc;
unsigned long retbuf[PLPAR_HCALL_BUFSIZE];
rc = plpar_hcall(H_VASI_STATE, retbuf, stream_id);
vasi_state = retbuf[0];
if (rc) {
pr_err("pseries_suspend_begin: vasi_state returned %ld\n",rc);
return rc;
} else if (vasi_state == H_VASI_ENABLED) {
return -EAGAIN;
} else if (vasi_state != H_VASI_SUSPENDING) {
pr_err("pseries_suspend_begin: vasi_state returned state %ld\n",
vasi_state);
return -EIO;
}
return 0;
}
static int pseries_suspend_cpu(void)
{
if (atomic_read(&suspending))
return rtas_suspend_cpu(&suspend_data);
return 0;
}
static int pseries_suspend_enter(suspend_state_t state)
{
int rc = rtas_suspend_last_cpu(&suspend_data);
atomic_set(&suspending, 0);
atomic_set(&suspend_data.done, 1);
return rc;
}
static int pseries_prepare_late(void)
{
atomic_set(&suspending, 1);
atomic_set(&suspend_data.working, 0);
atomic_set(&suspend_data.done, 0);
atomic_set(&suspend_data.error, 0);
suspend_data.complete = &suspend_work;
INIT_COMPLETION(suspend_work);
return 0;
}
static ssize_t store_hibernate(struct sysdev_class *classdev,
struct sysdev_class_attribute *attr,
const char *buf, size_t count)
{
int rc;
if (!capable(CAP_SYS_ADMIN))
return -EPERM;
stream_id = simple_strtoul(buf, NULL, 16);
do {
rc = pseries_suspend_begin(PM_SUSPEND_MEM);
if (rc == -EAGAIN)
ssleep(1);
} while (rc == -EAGAIN);
if (!rc)
rc = pm_suspend(PM_SUSPEND_MEM);
stream_id = 0;
if (!rc)
rc = count;
return rc;
}
static int pseries_suspend_sysfs_register(struct sys_device *sysdev)
{
int rc;
if ((rc = sysdev_class_register(&suspend_sysdev_class)))
return rc;
sysdev->id = 0;
sysdev->cls = &suspend_sysdev_class;
if ((rc = sysdev_class_create_file(&suspend_sysdev_class, &attr_hibernate)))
goto class_unregister;
return 0;
class_unregister:
sysdev_class_unregister(&suspend_sysdev_class);
return rc;
}
static int __init pseries_suspend_init(void)
{
int rc;
if (!machine_is(pseries) || !firmware_has_feature(FW_FEATURE_LPAR))
return 0;
suspend_data.token = rtas_token("ibm,suspend-me");
if (suspend_data.token == RTAS_UNKNOWN_SERVICE)
return 0;
if ((rc = pseries_suspend_sysfs_register(&suspend_sysdev)))
return rc;
ppc_md.suspend_disable_cpu = pseries_suspend_cpu;
suspend_set_ops(&pseries_suspend_ops);
return 0;
}
