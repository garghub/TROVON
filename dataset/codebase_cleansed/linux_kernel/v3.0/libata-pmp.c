static unsigned int sata_pmp_read(struct ata_link *link, int reg, u32 *r_val)
{
struct ata_port *ap = link->ap;
struct ata_device *pmp_dev = ap->link.device;
struct ata_taskfile tf;
unsigned int err_mask;
ata_tf_init(pmp_dev, &tf);
tf.command = ATA_CMD_PMP_READ;
tf.protocol = ATA_PROT_NODATA;
tf.flags |= ATA_TFLAG_ISADDR | ATA_TFLAG_DEVICE | ATA_TFLAG_LBA48;
tf.feature = reg;
tf.device = link->pmp;
err_mask = ata_exec_internal(pmp_dev, &tf, NULL, DMA_NONE, NULL, 0,
SATA_PMP_RW_TIMEOUT);
if (err_mask)
return err_mask;
*r_val = tf.nsect | tf.lbal << 8 | tf.lbam << 16 | tf.lbah << 24;
return 0;
}
static unsigned int sata_pmp_write(struct ata_link *link, int reg, u32 val)
{
struct ata_port *ap = link->ap;
struct ata_device *pmp_dev = ap->link.device;
struct ata_taskfile tf;
ata_tf_init(pmp_dev, &tf);
tf.command = ATA_CMD_PMP_WRITE;
tf.protocol = ATA_PROT_NODATA;
tf.flags |= ATA_TFLAG_ISADDR | ATA_TFLAG_DEVICE | ATA_TFLAG_LBA48;
tf.feature = reg;
tf.device = link->pmp;
tf.nsect = val & 0xff;
tf.lbal = (val >> 8) & 0xff;
tf.lbam = (val >> 16) & 0xff;
tf.lbah = (val >> 24) & 0xff;
return ata_exec_internal(pmp_dev, &tf, NULL, DMA_NONE, NULL, 0,
SATA_PMP_RW_TIMEOUT);
}
int sata_pmp_qc_defer_cmd_switch(struct ata_queued_cmd *qc)
{
struct ata_link *link = qc->dev->link;
struct ata_port *ap = link->ap;
if (ap->excl_link == NULL || ap->excl_link == link) {
if (ap->nr_active_links == 0 || ata_link_active(link)) {
qc->flags |= ATA_QCFLAG_CLEAR_EXCL;
return ata_std_qc_defer(qc);
}
ap->excl_link = link;
}
return ATA_DEFER_PORT;
}
int sata_pmp_scr_read(struct ata_link *link, int reg, u32 *r_val)
{
unsigned int err_mask;
if (reg > SATA_PMP_PSCR_CONTROL)
return -EINVAL;
err_mask = sata_pmp_read(link, reg, r_val);
if (err_mask) {
ata_link_printk(link, KERN_WARNING, "failed to read SCR %d "
"(Emask=0x%x)\n", reg, err_mask);
return -EIO;
}
return 0;
}
int sata_pmp_scr_write(struct ata_link *link, int reg, u32 val)
{
unsigned int err_mask;
if (reg > SATA_PMP_PSCR_CONTROL)
return -EINVAL;
err_mask = sata_pmp_write(link, reg, val);
if (err_mask) {
ata_link_printk(link, KERN_WARNING, "failed to write SCR %d "
"(Emask=0x%x)\n", reg, err_mask);
return -EIO;
}
return 0;
}
int sata_pmp_set_lpm(struct ata_link *link, enum ata_lpm_policy policy,
unsigned hints)
{
return sata_link_scr_lpm(link, policy, true);
}
static int sata_pmp_read_gscr(struct ata_device *dev, u32 *gscr)
{
static const int gscr_to_read[] = { 0, 1, 2, 32, 33, 64, 96 };
int i;
for (i = 0; i < ARRAY_SIZE(gscr_to_read); i++) {
int reg = gscr_to_read[i];
unsigned int err_mask;
err_mask = sata_pmp_read(dev->link, reg, &gscr[reg]);
if (err_mask) {
ata_dev_printk(dev, KERN_ERR, "failed to read PMP "
"GSCR[%d] (Emask=0x%x)\n", reg, err_mask);
return -EIO;
}
}
return 0;
}
static const char *sata_pmp_spec_rev_str(const u32 *gscr)
{
u32 rev = gscr[SATA_PMP_GSCR_REV];
if (rev & (1 << 3))
return "1.2";
if (rev & (1 << 2))
return "1.1";
if (rev & (1 << 1))
return "1.0";
return "<unknown>";
}
static int sata_pmp_configure(struct ata_device *dev, int print_info)
{
struct ata_port *ap = dev->link->ap;
u32 *gscr = dev->gscr;
u16 vendor = sata_pmp_gscr_vendor(gscr);
u16 devid = sata_pmp_gscr_devid(gscr);
unsigned int err_mask = 0;
const char *reason;
int nr_ports, rc;
nr_ports = sata_pmp_gscr_ports(gscr);
if (nr_ports <= 0 || nr_ports > SATA_PMP_MAX_PORTS) {
rc = -EINVAL;
reason = "invalid nr_ports";
goto fail;
}
if ((ap->flags & ATA_FLAG_AN) &&
(gscr[SATA_PMP_GSCR_FEAT] & SATA_PMP_FEAT_NOTIFY))
dev->flags |= ATA_DFLAG_AN;
err_mask = sata_pmp_write(dev->link, SATA_PMP_GSCR_ERROR_EN,
SERR_PHYRDY_CHG);
if (err_mask) {
rc = -EIO;
reason = "failed to write GSCR_ERROR_EN";
goto fail;
}
if (vendor == 0x1095 && devid == 0x3726) {
u32 reg;
err_mask = sata_pmp_read(&ap->link, PMP_GSCR_SII_POL, &reg);
if (err_mask) {
rc = -EIO;
reason = "failed to read Sil3726 Private Register";
goto fail;
}
reg &= ~0x1;
err_mask = sata_pmp_write(&ap->link, PMP_GSCR_SII_POL, reg);
if (err_mask) {
rc = -EIO;
reason = "failed to write Sil3726 Private Register";
goto fail;
}
}
if (print_info) {
ata_dev_printk(dev, KERN_INFO, "Port Multiplier %s, "
"0x%04x:0x%04x r%d, %d ports, feat 0x%x/0x%x\n",
sata_pmp_spec_rev_str(gscr), vendor, devid,
sata_pmp_gscr_rev(gscr),
nr_ports, gscr[SATA_PMP_GSCR_FEAT_EN],
gscr[SATA_PMP_GSCR_FEAT]);
if (!(dev->flags & ATA_DFLAG_AN))
ata_dev_printk(dev, KERN_INFO,
"Asynchronous notification not supported, "
"hotplug won't\n work on fan-out "
"ports. Use warm-plug instead.\n");
}
return 0;
fail:
ata_dev_printk(dev, KERN_ERR,
"failed to configure Port Multiplier (%s, Emask=0x%x)\n",
reason, err_mask);
return rc;
}
static int sata_pmp_init_links (struct ata_port *ap, int nr_ports)
{
struct ata_link *pmp_link = ap->pmp_link;
int i, err;
if (!pmp_link) {
pmp_link = kzalloc(sizeof(pmp_link[0]) * SATA_PMP_MAX_PORTS,
GFP_NOIO);
if (!pmp_link)
return -ENOMEM;
for (i = 0; i < SATA_PMP_MAX_PORTS; i++)
ata_link_init(ap, &pmp_link[i], i);
ap->pmp_link = pmp_link;
for (i = 0; i < SATA_PMP_MAX_PORTS; i++) {
err = ata_tlink_add(&pmp_link[i]);
if (err) {
goto err_tlink;
}
}
}
for (i = 0; i < nr_ports; i++) {
struct ata_link *link = &pmp_link[i];
struct ata_eh_context *ehc = &link->eh_context;
link->flags = 0;
ehc->i.probe_mask |= ATA_ALL_DEVICES;
ehc->i.action |= ATA_EH_RESET;
}
return 0;
err_tlink:
while (--i >= 0)
ata_tlink_delete(&pmp_link[i]);
kfree(pmp_link);
ap->pmp_link = NULL;
return err;
}
static void sata_pmp_quirks(struct ata_port *ap)
{
u32 *gscr = ap->link.device->gscr;
u16 vendor = sata_pmp_gscr_vendor(gscr);
u16 devid = sata_pmp_gscr_devid(gscr);
struct ata_link *link;
if (vendor == 0x1095 && devid == 0x3726) {
ata_for_each_link(link, ap, EDGE) {
link->flags |= ATA_LFLAG_NO_LPM;
if (link->pmp < 5)
link->flags |= ATA_LFLAG_NO_SRST |
ATA_LFLAG_ASSUME_ATA;
if (link->pmp == 5)
link->flags |= ATA_LFLAG_NO_SRST |
ATA_LFLAG_ASSUME_SEMB;
}
} else if (vendor == 0x1095 && devid == 0x4723) {
ata_for_each_link(link, ap, EDGE) {
link->flags |= ATA_LFLAG_NO_LPM;
if (link->pmp < 2)
link->flags |= ATA_LFLAG_ASSUME_ATA;
if (link->pmp == 2)
link->flags |= ATA_LFLAG_NO_SRST |
ATA_LFLAG_ASSUME_ATA;
}
} else if (vendor == 0x1095 && devid == 0x4726) {
ata_for_each_link(link, ap, EDGE) {
link->flags |= ATA_LFLAG_NO_LPM;
if (link->pmp <= 5)
link->flags |= ATA_LFLAG_NO_SRST |
ATA_LFLAG_ASSUME_ATA;
if (link->pmp == 6)
link->flags |= ATA_LFLAG_NO_SRST |
ATA_LFLAG_ASSUME_SEMB;
}
} else if (vendor == 0x1095 && (devid == 0x5723 || devid == 0x5733 ||
devid == 0x5734 || devid == 0x5744)) {
ap->pmp_link[ap->nr_pmp_links - 1].flags |= ATA_LFLAG_NO_RETRY;
} else if (vendor == 0x197b && devid == 0x2352) {
ata_for_each_link(link, ap, EDGE) {
link->flags |= ATA_LFLAG_NO_LPM |
ATA_LFLAG_NO_SRST |
ATA_LFLAG_ASSUME_ATA;
}
}
}
int sata_pmp_attach(struct ata_device *dev)
{
struct ata_link *link = dev->link;
struct ata_port *ap = link->ap;
unsigned long flags;
struct ata_link *tlink;
int rc;
if (!sata_pmp_supported(ap)) {
ata_dev_printk(dev, KERN_ERR,
"host does not support Port Multiplier\n");
return -EINVAL;
}
if (!ata_is_host_link(link)) {
ata_dev_printk(dev, KERN_ERR,
"Port Multipliers cannot be nested\n");
return -EINVAL;
}
if (dev->devno) {
ata_dev_printk(dev, KERN_ERR,
"Port Multiplier must be the first device\n");
return -EINVAL;
}
WARN_ON(link->pmp != 0);
link->pmp = SATA_PMP_CTRL_PORT;
rc = sata_pmp_read_gscr(dev, dev->gscr);
if (rc)
goto fail;
rc = sata_pmp_configure(dev, 1);
if (rc)
goto fail;
rc = sata_pmp_init_links(ap, sata_pmp_gscr_ports(dev->gscr));
if (rc) {
ata_dev_printk(dev, KERN_INFO,
"failed to initialize PMP links\n");
goto fail;
}
spin_lock_irqsave(ap->lock, flags);
WARN_ON(ap->nr_pmp_links);
ap->nr_pmp_links = sata_pmp_gscr_ports(dev->gscr);
spin_unlock_irqrestore(ap->lock, flags);
sata_pmp_quirks(ap);
if (ap->ops->pmp_attach)
ap->ops->pmp_attach(ap);
ata_for_each_link(tlink, ap, EDGE)
sata_link_init_spd(tlink);
ata_acpi_associate_sata_port(ap);
return 0;
fail:
link->pmp = 0;
return rc;
}
static void sata_pmp_detach(struct ata_device *dev)
{
struct ata_link *link = dev->link;
struct ata_port *ap = link->ap;
struct ata_link *tlink;
unsigned long flags;
ata_dev_printk(dev, KERN_INFO, "Port Multiplier detaching\n");
WARN_ON(!ata_is_host_link(link) || dev->devno ||
link->pmp != SATA_PMP_CTRL_PORT);
if (ap->ops->pmp_detach)
ap->ops->pmp_detach(ap);
ata_for_each_link(tlink, ap, EDGE)
ata_eh_detach_dev(tlink->device);
spin_lock_irqsave(ap->lock, flags);
ap->nr_pmp_links = 0;
link->pmp = 0;
spin_unlock_irqrestore(ap->lock, flags);
ata_acpi_associate_sata_port(ap);
}
static int sata_pmp_same_pmp(struct ata_device *dev, const u32 *new_gscr)
{
const u32 *old_gscr = dev->gscr;
u16 old_vendor, new_vendor, old_devid, new_devid;
int old_nr_ports, new_nr_ports;
old_vendor = sata_pmp_gscr_vendor(old_gscr);
new_vendor = sata_pmp_gscr_vendor(new_gscr);
old_devid = sata_pmp_gscr_devid(old_gscr);
new_devid = sata_pmp_gscr_devid(new_gscr);
old_nr_ports = sata_pmp_gscr_ports(old_gscr);
new_nr_ports = sata_pmp_gscr_ports(new_gscr);
if (old_vendor != new_vendor) {
ata_dev_printk(dev, KERN_INFO, "Port Multiplier "
"vendor mismatch '0x%x' != '0x%x'\n",
old_vendor, new_vendor);
return 0;
}
if (old_devid != new_devid) {
ata_dev_printk(dev, KERN_INFO, "Port Multiplier "
"device ID mismatch '0x%x' != '0x%x'\n",
old_devid, new_devid);
return 0;
}
if (old_nr_ports != new_nr_ports) {
ata_dev_printk(dev, KERN_INFO, "Port Multiplier "
"nr_ports mismatch '0x%x' != '0x%x'\n",
old_nr_ports, new_nr_ports);
return 0;
}
return 1;
}
static int sata_pmp_revalidate(struct ata_device *dev, unsigned int new_class)
{
struct ata_link *link = dev->link;
struct ata_port *ap = link->ap;
u32 *gscr = (void *)ap->sector_buf;
int rc;
DPRINTK("ENTER\n");
ata_eh_about_to_do(link, NULL, ATA_EH_REVALIDATE);
if (!ata_dev_enabled(dev)) {
rc = -ENODEV;
goto fail;
}
if (ata_class_enabled(new_class) && new_class != ATA_DEV_PMP) {
rc = -ENODEV;
goto fail;
}
rc = sata_pmp_read_gscr(dev, gscr);
if (rc)
goto fail;
if (!sata_pmp_same_pmp(dev, gscr)) {
rc = -ENODEV;
goto fail;
}
memcpy(dev->gscr, gscr, sizeof(gscr[0]) * SATA_PMP_GSCR_DWORDS);
rc = sata_pmp_configure(dev, 0);
if (rc)
goto fail;
ata_eh_done(link, NULL, ATA_EH_REVALIDATE);
DPRINTK("EXIT, rc=0\n");
return 0;
fail:
ata_dev_printk(dev, KERN_ERR,
"PMP revalidation failed (errno=%d)\n", rc);
DPRINTK("EXIT, rc=%d\n", rc);
return rc;
}
static int sata_pmp_revalidate_quick(struct ata_device *dev)
{
unsigned int err_mask;
u32 prod_id;
err_mask = sata_pmp_read(dev->link, SATA_PMP_GSCR_PROD_ID, &prod_id);
if (err_mask) {
ata_dev_printk(dev, KERN_ERR, "failed to read PMP product ID "
"(Emask=0x%x)\n", err_mask);
return -EIO;
}
if (prod_id != dev->gscr[SATA_PMP_GSCR_PROD_ID]) {
ata_dev_printk(dev, KERN_ERR, "PMP product ID mismatch\n");
return -EIO;
}
return 0;
}
static int sata_pmp_eh_recover_pmp(struct ata_port *ap,
ata_prereset_fn_t prereset, ata_reset_fn_t softreset,
ata_reset_fn_t hardreset, ata_postreset_fn_t postreset)
{
struct ata_link *link = &ap->link;
struct ata_eh_context *ehc = &link->eh_context;
struct ata_device *dev = link->device;
int tries = ATA_EH_PMP_TRIES;
int detach = 0, rc = 0;
int reval_failed = 0;
DPRINTK("ENTER\n");
if (dev->flags & ATA_DFLAG_DETACH) {
detach = 1;
goto fail;
}
retry:
ehc->classes[0] = ATA_DEV_UNKNOWN;
if (ehc->i.action & ATA_EH_RESET) {
struct ata_link *tlink;
rc = ata_eh_reset(link, 0, prereset, softreset, hardreset,
postreset);
if (rc) {
ata_link_printk(link, KERN_ERR,
"failed to reset PMP, giving up\n");
goto fail;
}
ata_for_each_link(tlink, ap, EDGE) {
struct ata_eh_context *ehc = &tlink->eh_context;
ehc->i.probe_mask |= ATA_ALL_DEVICES;
ehc->i.action |= ATA_EH_RESET;
}
}
if (ehc->i.action & ATA_EH_REVALIDATE)
rc = sata_pmp_revalidate(dev, ehc->classes[0]);
else
rc = sata_pmp_revalidate_quick(dev);
if (rc) {
tries--;
if (rc == -ENODEV) {
ehc->i.probe_mask |= ATA_ALL_DEVICES;
detach = 1;
tries = min(tries, 2);
}
if (tries) {
if (reval_failed)
sata_down_spd_limit(link, 0);
else
reval_failed = 1;
ehc->i.action |= ATA_EH_RESET;
goto retry;
} else {
ata_dev_printk(dev, KERN_ERR, "failed to recover PMP "
"after %d tries, giving up\n",
ATA_EH_PMP_TRIES);
goto fail;
}
}
ehc->i.flags = 0;
DPRINTK("EXIT, rc=0\n");
return 0;
fail:
sata_pmp_detach(dev);
if (detach)
ata_eh_detach_dev(dev);
else
ata_dev_disable(dev);
DPRINTK("EXIT, rc=%d\n", rc);
return rc;
}
static int sata_pmp_eh_handle_disabled_links(struct ata_port *ap)
{
struct ata_link *link;
unsigned long flags;
int rc;
spin_lock_irqsave(ap->lock, flags);
ata_for_each_link(link, ap, EDGE) {
if (!(link->flags & ATA_LFLAG_DISABLED))
continue;
spin_unlock_irqrestore(ap->lock, flags);
sata_link_hardreset(link, sata_deb_timing_normal,
ata_deadline(jiffies, ATA_TMOUT_INTERNAL_QUICK),
NULL, NULL);
rc = sata_scr_write(link, SCR_ERROR, SERR_PHYRDY_CHG);
if (rc) {
ata_link_printk(link, KERN_ERR, "failed to clear "
"SError.N (errno=%d)\n", rc);
return rc;
}
spin_lock_irqsave(ap->lock, flags);
}
spin_unlock_irqrestore(ap->lock, flags);
return 0;
}
static int sata_pmp_handle_link_fail(struct ata_link *link, int *link_tries)
{
struct ata_port *ap = link->ap;
unsigned long flags;
if (link_tries[link->pmp] && --link_tries[link->pmp])
return 1;
if (!(link->flags & ATA_LFLAG_DISABLED)) {
ata_link_printk(link, KERN_WARNING,
"failed to recover link after %d tries, disabling\n",
ATA_EH_PMP_LINK_TRIES);
spin_lock_irqsave(ap->lock, flags);
link->flags |= ATA_LFLAG_DISABLED;
spin_unlock_irqrestore(ap->lock, flags);
}
ata_dev_disable(link->device);
link->eh_context.i.action = 0;
return 0;
}
static int sata_pmp_eh_recover(struct ata_port *ap)
{
struct ata_port_operations *ops = ap->ops;
int pmp_tries, link_tries[SATA_PMP_MAX_PORTS];
struct ata_link *pmp_link = &ap->link;
struct ata_device *pmp_dev = pmp_link->device;
struct ata_eh_context *pmp_ehc = &pmp_link->eh_context;
u32 *gscr = pmp_dev->gscr;
struct ata_link *link;
struct ata_device *dev;
unsigned int err_mask;
u32 gscr_error, sntf;
int cnt, rc;
pmp_tries = ATA_EH_PMP_TRIES;
ata_for_each_link(link, ap, EDGE)
link_tries[link->pmp] = ATA_EH_PMP_LINK_TRIES;
retry:
if (!sata_pmp_attached(ap)) {
rc = ata_eh_recover(ap, ops->prereset, ops->softreset,
ops->hardreset, ops->postreset, NULL);
if (rc) {
ata_for_each_dev(dev, &ap->link, ALL)
ata_dev_disable(dev);
return rc;
}
if (pmp_dev->class != ATA_DEV_PMP)
return 0;
ata_for_each_link(link, ap, EDGE)
link_tries[link->pmp] = ATA_EH_PMP_LINK_TRIES;
}
rc = sata_pmp_eh_recover_pmp(ap, ops->prereset, ops->softreset,
ops->hardreset, ops->postreset);
if (rc)
goto pmp_fail;
if (gscr[SATA_PMP_GSCR_FEAT_EN] & SATA_PMP_FEAT_NOTIFY) {
gscr[SATA_PMP_GSCR_FEAT_EN] &= ~SATA_PMP_FEAT_NOTIFY;
err_mask = sata_pmp_write(pmp_link, SATA_PMP_GSCR_FEAT_EN,
gscr[SATA_PMP_GSCR_FEAT_EN]);
if (err_mask) {
ata_link_printk(pmp_link, KERN_WARNING,
"failed to disable NOTIFY (err_mask=0x%x)\n",
err_mask);
goto pmp_fail;
}
}
rc = sata_pmp_eh_handle_disabled_links(ap);
if (rc)
goto pmp_fail;
rc = ata_eh_recover(ap, ops->pmp_prereset, ops->pmp_softreset,
ops->pmp_hardreset, ops->pmp_postreset, &link);
if (rc)
goto link_fail;
rc = sata_scr_read(&ap->link, SCR_NOTIFICATION, &sntf);
if (rc == 0)
sata_scr_write(&ap->link, SCR_NOTIFICATION, sntf);
ata_for_each_link(link, ap, EDGE)
if (link->lpm_policy > ATA_LPM_MAX_POWER)
return 0;
if (pmp_dev->flags & ATA_DFLAG_AN) {
gscr[SATA_PMP_GSCR_FEAT_EN] |= SATA_PMP_FEAT_NOTIFY;
err_mask = sata_pmp_write(pmp_link, SATA_PMP_GSCR_FEAT_EN,
gscr[SATA_PMP_GSCR_FEAT_EN]);
if (err_mask) {
ata_dev_printk(pmp_dev, KERN_ERR, "failed to write "
"PMP_FEAT_EN (Emask=0x%x)\n", err_mask);
rc = -EIO;
goto pmp_fail;
}
}
err_mask = sata_pmp_read(pmp_link, SATA_PMP_GSCR_ERROR, &gscr_error);
if (err_mask) {
ata_dev_printk(pmp_dev, KERN_ERR, "failed to read "
"PMP_GSCR_ERROR (Emask=0x%x)\n", err_mask);
rc = -EIO;
goto pmp_fail;
}
cnt = 0;
ata_for_each_link(link, ap, EDGE) {
if (!(gscr_error & (1 << link->pmp)))
continue;
if (sata_pmp_handle_link_fail(link, link_tries)) {
ata_ehi_hotplugged(&link->eh_context.i);
cnt++;
} else {
ata_link_printk(link, KERN_WARNING,
"PHY status changed but maxed out on retries, "
"giving up\n");
ata_link_printk(link, KERN_WARNING,
"Manully issue scan to resume this link\n");
}
}
if (cnt) {
ata_port_printk(ap, KERN_INFO, "PMP SError.N set for some "
"ports, repeating recovery\n");
goto retry;
}
return 0;
link_fail:
if (sata_pmp_handle_link_fail(link, link_tries)) {
pmp_ehc->i.action |= ATA_EH_RESET;
goto retry;
}
pmp_fail:
if (ap->pflags & ATA_PFLAG_UNLOADING)
return rc;
if (!sata_pmp_attached(ap))
goto retry;
if (--pmp_tries) {
pmp_ehc->i.action |= ATA_EH_RESET;
goto retry;
}
ata_port_printk(ap, KERN_ERR,
"failed to recover PMP after %d tries, giving up\n",
ATA_EH_PMP_TRIES);
sata_pmp_detach(pmp_dev);
ata_dev_disable(pmp_dev);
return rc;
}
void sata_pmp_error_handler(struct ata_port *ap)
{
ata_eh_autopsy(ap);
ata_eh_report(ap);
sata_pmp_eh_recover(ap);
ata_eh_finish(ap);
}
