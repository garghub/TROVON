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
static int divadidd_proc_show(struct seq_file *m, void *v)
{
char tmprev[32];
strcpy(tmprev, main_revision);
seq_printf(m, "%s\n", DRIVERNAME);
seq_printf(m, "name : %s\n", DRIVERLNAME);
seq_printf(m, "release : %s\n", DRIVERRELEASE_DIDD);
seq_printf(m, "build : %s(%s)\n",
diva_didd_common_code_build, DIVA_BUILD);
seq_printf(m, "revision : %s\n", getrev(tmprev));
return 0;
}
static int divadidd_proc_open(struct inode *inode, struct file *file)
{
return single_open(file, divadidd_proc_show, NULL);
}
static int DIVA_INIT_FUNCTION create_proc(void)
{
proc_net_eicon = proc_mkdir("eicon", init_net.proc_net);
if (proc_net_eicon) {
proc_didd = proc_create(DRIVERLNAME, S_IRUGO, proc_net_eicon,
&divadidd_proc_fops);
return (1);
}
return (0);
}
static void remove_proc(void)
{
remove_proc_entry(DRIVERLNAME, proc_net_eicon);
remove_proc_entry("eicon", init_net.proc_net);
}
static int DIVA_INIT_FUNCTION divadidd_init(void)
{
char tmprev[32];
int ret = 0;
printk(KERN_INFO "%s\n", DRIVERNAME);
printk(KERN_INFO "%s: Rel:%s Rev:", DRIVERLNAME, DRIVERRELEASE_DIDD);
strcpy(tmprev, main_revision);
printk("%s Build:%s(%s)\n", getrev(tmprev),
diva_didd_common_code_build, DIVA_BUILD);
if (!create_proc()) {
printk(KERN_ERR "%s: could not create proc entry\n",
DRIVERLNAME);
ret = -EIO;
goto out;
}
if (!diddfunc_init()) {
printk(KERN_ERR "%s: failed to connect to DIDD.\n",
DRIVERLNAME);
#ifdef MODULE
remove_proc();
#endif
ret = -EIO;
goto out;
}
out:
return (ret);
}
static void DIVA_EXIT_FUNCTION divadidd_exit(void)
{
diddfunc_finit();
remove_proc();
printk(KERN_INFO "%s: module unloaded.\n", DRIVERLNAME);
}
