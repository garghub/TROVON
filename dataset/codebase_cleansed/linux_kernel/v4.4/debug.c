static int brcmf_debug_create_memdump(struct brcmf_bus *bus, const void *data,
size_t len)
{
void *dump;
size_t ramsize;
ramsize = brcmf_bus_get_ramsize(bus);
if (ramsize) {
dump = vzalloc(len + ramsize);
if (!dump)
return -ENOMEM;
memcpy(dump, data, len);
brcmf_bus_get_memdump(bus, dump + len, ramsize);
dev_coredumpv(bus->dev, dump, len + ramsize, GFP_KERNEL);
}
return 0;
}
static int brcmf_debug_psm_watchdog_notify(struct brcmf_if *ifp,
const struct brcmf_event_msg *evtmsg,
void *data)
{
brcmf_dbg(TRACE, "enter: idx=%d\n", ifp->bssidx);
return brcmf_debug_create_memdump(ifp->drvr->bus_if, data,
evtmsg->datalen);
}
void brcmf_debugfs_init(void)
{
root_folder = debugfs_create_dir(KBUILD_MODNAME, NULL);
if (IS_ERR(root_folder))
root_folder = NULL;
}
void brcmf_debugfs_exit(void)
{
if (!root_folder)
return;
debugfs_remove_recursive(root_folder);
root_folder = NULL;
}
int brcmf_debug_attach(struct brcmf_pub *drvr)
{
struct device *dev = drvr->bus_if->dev;
if (!root_folder)
return -ENODEV;
drvr->dbgfs_dir = debugfs_create_dir(dev_name(dev), root_folder);
if (IS_ERR(drvr->dbgfs_dir))
return PTR_ERR(drvr->dbgfs_dir);
return brcmf_fweh_register(drvr, BRCMF_E_PSM_WATCHDOG,
brcmf_debug_psm_watchdog_notify);
}
void brcmf_debug_detach(struct brcmf_pub *drvr)
{
brcmf_fweh_unregister(drvr, BRCMF_E_PSM_WATCHDOG);
if (!IS_ERR_OR_NULL(drvr->dbgfs_dir))
debugfs_remove_recursive(drvr->dbgfs_dir);
}
struct dentry *brcmf_debugfs_get_devdir(struct brcmf_pub *drvr)
{
return drvr->dbgfs_dir;
}
int brcmf_debugfs_add_entry(struct brcmf_pub *drvr, const char *fn,
int (*read_fn)(struct seq_file *seq, void *data))
{
struct dentry *e;
e = debugfs_create_devm_seqfile(drvr->bus_if->dev, fn,
drvr->dbgfs_dir, read_fn);
return PTR_ERR_OR_ZERO(e);
}
