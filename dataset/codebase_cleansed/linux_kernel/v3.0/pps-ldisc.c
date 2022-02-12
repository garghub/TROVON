static void pps_tty_dcd_change(struct tty_struct *tty, unsigned int status,
struct pps_event_time *ts)
{
struct pps_device *pps = (struct pps_device *)tty->disc_data;
BUG_ON(pps == NULL);
pps_event(pps, ts, status ? PPS_CAPTUREASSERT :
PPS_CAPTURECLEAR, NULL);
dev_dbg(pps->dev, "PPS %s at %lu\n",
status ? "assert" : "clear", jiffies);
}
static int pps_tty_open(struct tty_struct *tty)
{
struct pps_source_info info;
struct tty_driver *drv = tty->driver;
int index = tty->index + drv->name_base;
struct pps_device *pps;
int ret;
info.owner = THIS_MODULE;
info.dev = NULL;
snprintf(info.name, PPS_MAX_NAME_LEN, "%s%d", drv->driver_name, index);
snprintf(info.path, PPS_MAX_NAME_LEN, "/dev/%s%d", drv->name, index);
info.mode = PPS_CAPTUREBOTH | \
PPS_OFFSETASSERT | PPS_OFFSETCLEAR | \
PPS_CANWAIT | PPS_TSFMT_TSPEC;
pps = pps_register_source(&info, PPS_CAPTUREBOTH | \
PPS_OFFSETASSERT | PPS_OFFSETCLEAR);
if (pps == NULL) {
pr_err("cannot register PPS source \"%s\"\n", info.path);
return -ENOMEM;
}
tty->disc_data = pps;
ret = alias_n_tty_open(tty);
if (ret < 0) {
pr_err("cannot open tty ldisc \"%s\"\n", info.path);
goto err_unregister;
}
dev_info(pps->dev, "source \"%s\" added\n", info.path);
return 0;
err_unregister:
tty->disc_data = NULL;
pps_unregister_source(pps);
return ret;
}
static void pps_tty_close(struct tty_struct *tty)
{
struct pps_device *pps = (struct pps_device *)tty->disc_data;
alias_n_tty_close(tty);
tty->disc_data = NULL;
dev_info(pps->dev, "removed\n");
pps_unregister_source(pps);
}
static int __init pps_tty_init(void)
{
int err;
n_tty_inherit_ops(&pps_ldisc_ops);
alias_n_tty_open = pps_ldisc_ops.open;
alias_n_tty_close = pps_ldisc_ops.close;
pps_ldisc_ops.owner = THIS_MODULE;
pps_ldisc_ops.magic = PPS_TTY_MAGIC;
pps_ldisc_ops.name = "pps_tty";
pps_ldisc_ops.dcd_change = pps_tty_dcd_change;
pps_ldisc_ops.open = pps_tty_open;
pps_ldisc_ops.close = pps_tty_close;
err = tty_register_ldisc(N_PPS, &pps_ldisc_ops);
if (err)
pr_err("can't register PPS line discipline\n");
else
pr_info("PPS line discipline registered\n");
return err;
}
static void __exit pps_tty_cleanup(void)
{
int err;
err = tty_unregister_ldisc(N_PPS);
if (err)
pr_err("can't unregister PPS line discipline\n");
else
pr_info("PPS line discipline removed\n");
}
