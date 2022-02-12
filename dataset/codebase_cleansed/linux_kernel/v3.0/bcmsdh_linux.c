bool bcmsdh_chipmatch(u16 vendor, u16 device)
{
#ifdef BCMSDIOH_STD
if (vendor == VENDOR_SI_IMAGE)
return true;
if (device == BCM27XX_SDIOH_ID && vendor == PCI_VENDOR_ID_BROADCOM)
return true;
if (device == SDIOH_FPGA_ID && vendor == PCI_VENDOR_ID_BROADCOM)
return true;
if (device == PCIXX21_SDIOH_ID && vendor == VENDOR_TI)
return true;
if (device == PCIXX21_SDIOH0_ID && vendor == VENDOR_TI)
return true;
if (device == R5C822_SDIOH_ID && vendor == VENDOR_RICOH)
return true;
if (device == JMICRON_SDIOH_ID && vendor == VENDOR_JMICRON)
return true;
#endif
#ifdef BCMSDIOH_SPI
if (device == SPIH_FPGA_ID && vendor == PCI_VENDOR_ID_BROADCOM) {
return true;
}
#endif
return false;
}
static
#endif
int bcmsdh_probe(struct device *dev)
{
bcmsdh_hc_t *sdhc = NULL;
unsigned long regs = 0;
bcmsdh_info_t *sdh = NULL;
#if !defined(BCMLXSDMMC) && defined(BCMPLATFORM_BUS)
struct platform_device *pdev;
struct resource *r;
#endif
int irq = 0;
u32 vendevid;
unsigned long irq_flags = 0;
#if !defined(BCMLXSDMMC) && defined(BCMPLATFORM_BUS)
pdev = to_platform_device(dev);
r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
irq = platform_get_irq(pdev, 0);
if (!r || irq == NO_IRQ)
return -ENXIO;
#endif
#if defined(OOB_INTR_ONLY)
#ifdef HW_OOB
irq_flags =
IORESOURCE_IRQ | IORESOURCE_IRQ_HIGHLEVEL |
IORESOURCE_IRQ_SHAREABLE;
#else
irq_flags = IRQF_TRIGGER_FALLING;
#endif
irq = dhd_customer_oob_irq_map(&irq_flags);
if (irq < 0) {
SDLX_MSG(("%s: Host irq is not defined\n", __func__));
return 1;
}
#endif
sdhc = kzalloc(sizeof(bcmsdh_hc_t), GFP_ATOMIC);
if (!sdhc) {
SDLX_MSG(("%s: out of memory\n", __func__));
goto err;
}
sdhc->dev = (void *)dev;
#ifdef BCMLXSDMMC
sdh = bcmsdh_attach((void *)0, (void **)&regs, irq);
if (!sdh) {
SDLX_MSG(("%s: bcmsdh_attach failed\n", __func__));
goto err;
}
#else
sdh = bcmsdh_attach((void *)r->start, (void **)&regs, irq);
if (!sdh) {
SDLX_MSG(("%s: bcmsdh_attach failed\n", __func__));
goto err;
}
#endif
sdhc->sdh = sdh;
sdhc->oob_irq = irq;
sdhc->oob_flags = irq_flags;
sdhc->oob_irq_registered = false;
#if defined(OOB_INTR_ONLY)
spin_lock_init(&sdhc->irq_lock);
#endif
sdhc->next = sdhcinfo;
sdhcinfo = sdhc;
vendevid = bcmsdh_query_device(sdh);
sdhc->ch = drvinfo.attach((vendevid >> 16), (vendevid & 0xFFFF),
0, 0, 0, 0, (void *)regs, sdh);
if (!sdhc->ch) {
SDLX_MSG(("%s: device attach failed\n", __func__));
goto err;
}
return 0;
err:
if (sdhc) {
if (sdhc->sdh)
bcmsdh_detach(sdhc->sdh);
kfree(sdhc);
}
return -ENODEV;
}
static
#endif
int bcmsdh_remove(struct device *dev)
{
bcmsdh_hc_t *sdhc, *prev;
sdhc = sdhcinfo;
drvinfo.detach(sdhc->ch);
bcmsdh_detach(sdhc->sdh);
for (sdhc = sdhcinfo, prev = NULL; sdhc; sdhc = sdhc->next) {
if (sdhc->dev == (void *)dev) {
if (prev)
prev->next = sdhc->next;
else
sdhcinfo = NULL;
break;
}
prev = sdhc;
}
if (!sdhc) {
SDLX_MSG(("%s: failed\n", __func__));
return 0;
}
kfree(sdhc);
#if !defined(BCMLXSDMMC)
dev_set_drvdata(dev, NULL);
#endif
return 0;
}
int bcmsdh_register(bcmsdh_driver_t *driver)
{
drvinfo = *driver;
SDLX_MSG(("Linux Kernel SDIO/MMC Driver\n"));
return sdio_function_init();
}
void bcmsdh_unregister(void)
{
sdio_function_cleanup();
}
void bcmsdh_oob_intr_set(bool enable)
{
static bool curstate = 1;
unsigned long flags;
spin_lock_irqsave(&sdhcinfo->irq_lock, flags);
if (curstate != enable) {
if (enable)
enable_irq(sdhcinfo->oob_irq);
else
disable_irq_nosync(sdhcinfo->oob_irq);
curstate = enable;
}
spin_unlock_irqrestore(&sdhcinfo->irq_lock, flags);
}
static irqreturn_t wlan_oob_irq(int irq, void *dev_id)
{
dhd_pub_t *dhdp;
dhdp = (dhd_pub_t *) dev_get_drvdata(sdhcinfo->dev);
bcmsdh_oob_intr_set(0);
if (dhdp == NULL) {
SDLX_MSG(("Out of band GPIO interrupt fired way too early\n"));
return IRQ_HANDLED;
}
dhdsdio_isr((void *)dhdp->bus);
return IRQ_HANDLED;
}
int bcmsdh_register_oob_intr(void *dhdp)
{
int error = 0;
SDLX_MSG(("%s Enter\n", __func__));
sdhcinfo->oob_flags =
IORESOURCE_IRQ | IORESOURCE_IRQ_HIGHLEVEL |
IORESOURCE_IRQ_SHAREABLE;
dev_set_drvdata(sdhcinfo->dev, dhdp);
if (!sdhcinfo->oob_irq_registered) {
SDLX_MSG(("%s IRQ=%d Type=%X\n", __func__,
(int)sdhcinfo->oob_irq, (int)sdhcinfo->oob_flags));
error =
request_irq(sdhcinfo->oob_irq, wlan_oob_irq,
sdhcinfo->oob_flags, "bcmsdh_sdmmc", NULL);
if (error)
return -ENODEV;
irq_set_irq_wake(sdhcinfo->oob_irq, 1);
sdhcinfo->oob_irq_registered = true;
}
return 0;
}
void bcmsdh_unregister_oob_intr(void)
{
SDLX_MSG(("%s: Enter\n", __func__));
irq_set_irq_wake(sdhcinfo->oob_irq, 0);
disable_irq(sdhcinfo->oob_irq);
free_irq(sdhcinfo->oob_irq, NULL);
sdhcinfo->oob_irq_registered = false;
}
