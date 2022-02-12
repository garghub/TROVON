static char *getrev(const char *revision)
{
char *rev;
char *p;
if ((p = strchr(revision, ':'))) {
rev = p + 2;
p = strchr(rev, '$');
*--p = 0;
} else
rev = "1.0";
return rev;
}
diva_os_message_buffer_s *diva_os_alloc_message_buffer(unsigned long size,
void **data_buf)
{
diva_os_message_buffer_s *dmb = alloc_skb(size, GFP_ATOMIC);
if (dmb) {
*data_buf = skb_put(dmb, size);
}
return (dmb);
}
void diva_os_free_message_buffer(diva_os_message_buffer_s * dmb)
{
kfree_skb(dmb);
}
static int diva_ctl_proc_show(struct seq_file *m, void *v)
{
struct capi_ctr *ctrl = m->private;
diva_card *card = (diva_card *) ctrl->driverdata;
seq_printf(m, "%s\n", ctrl->name);
seq_printf(m, "Serial No. : %s\n", ctrl->serial);
seq_printf(m, "Id : %d\n", card->Id);
seq_printf(m, "Channels : %d\n", card->d.channels);
return 0;
}
static int diva_ctl_proc_open(struct inode *inode, struct file *file)
{
return single_open(file, diva_ctl_proc_show, NULL);
}
void diva_os_set_controller_struct(struct capi_ctr *ctrl)
{
ctrl->driver_name = DRIVERLNAME;
ctrl->load_firmware = NULL;
ctrl->reset_ctr = NULL;
ctrl->proc_fops = &diva_ctl_proc_fops;
ctrl->owner = THIS_MODULE;
}
static int DIVA_INIT_FUNCTION divacapi_init(void)
{
char tmprev[32];
int ret = 0;
sprintf(DRIVERRELEASE_CAPI, "%d.%d%s", DRRELMAJOR, DRRELMINOR,
DRRELEXTRA);
printk(KERN_INFO "%s\n", DRIVERNAME);
printk(KERN_INFO "%s: Rel:%s Rev:", DRIVERLNAME, DRIVERRELEASE_CAPI);
strcpy(tmprev, main_revision);
printk("%s Build: %s(%s)\n", getrev(tmprev),
diva_capi_common_code_build, DIVA_BUILD);
if (!(init_capifunc())) {
printk(KERN_ERR "%s: failed init capi_driver.\n",
DRIVERLNAME);
ret = -EIO;
}
return ret;
}
static void DIVA_EXIT_FUNCTION divacapi_exit(void)
{
finit_capifunc();
printk(KERN_INFO "%s: module unloaded.\n", DRIVERLNAME);
}
