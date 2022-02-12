static int ide_probe(struct pcmcia_device *link)
{
ide_info_t *info;
dev_dbg(&link->dev, "ide_attach()\n");
info = kzalloc(sizeof(*info), GFP_KERNEL);
if (!info)
return -ENOMEM;
info->p_dev = link;
link->priv = info;
link->config_flags |= CONF_ENABLE_IRQ | CONF_AUTO_SET_IO |
CONF_AUTO_SET_VPP | CONF_AUTO_CHECK_VCC;
return ide_config(link);
}
static void ide_detach(struct pcmcia_device *link)
{
ide_info_t *info = link->priv;
dev_dbg(&link->dev, "ide_detach(0x%p)\n", link);
ide_release(link);
kfree(info);
}
static struct ide_host *idecs_register(unsigned long io, unsigned long ctl,
unsigned long irq, struct pcmcia_device *handle)
{
struct ide_host *host;
ide_hwif_t *hwif;
int i, rc;
struct ide_hw hw, *hws[] = { &hw };
if (!request_region(io, 8, DRV_NAME)) {
printk(KERN_ERR "%s: I/O resource 0x%lX-0x%lX not free.\n",
DRV_NAME, io, io + 7);
return NULL;
}
if (!request_region(ctl, 1, DRV_NAME)) {
printk(KERN_ERR "%s: I/O resource 0x%lX not free.\n",
DRV_NAME, ctl);
release_region(io, 8);
return NULL;
}
memset(&hw, 0, sizeof(hw));
ide_std_init_ports(&hw, io, ctl);
hw.irq = irq;
hw.dev = &handle->dev;
rc = ide_host_add(&idecs_port_info, hws, 1, &host);
if (rc)
goto out_release;
hwif = host->ports[0];
if (hwif->present)
return host;
for (i = 0; i < 10; i++) {
msleep(100);
ide_port_scan(hwif);
if (hwif->present)
return host;
}
return host;
out_release:
release_region(ctl, 1);
release_region(io, 8);
return NULL;
}
static int pcmcia_check_one_config(struct pcmcia_device *pdev, void *priv_data)
{
int *is_kme = priv_data;
if ((pdev->resource[0]->flags & IO_DATA_PATH_WIDTH)
!= IO_DATA_PATH_WIDTH_8) {
pdev->resource[0]->flags &= ~IO_DATA_PATH_WIDTH;
pdev->resource[0]->flags |= IO_DATA_PATH_WIDTH_AUTO;
}
pdev->resource[1]->flags &= ~IO_DATA_PATH_WIDTH;
pdev->resource[1]->flags |= IO_DATA_PATH_WIDTH_8;
if (pdev->resource[1]->end) {
pdev->resource[0]->end = 8;
pdev->resource[1]->end = (*is_kme) ? 2 : 1;
} else {
if (pdev->resource[0]->end < 16)
return -ENODEV;
}
return pcmcia_request_io(pdev);
}
static int ide_config(struct pcmcia_device *link)
{
ide_info_t *info = link->priv;
int ret = 0, is_kme = 0;
unsigned long io_base, ctl_base;
struct ide_host *host;
dev_dbg(&link->dev, "ide_config(0x%p)\n", link);
is_kme = ((link->manf_id == MANFID_KME) &&
((link->card_id == PRODID_KME_KXLC005_A) ||
(link->card_id == PRODID_KME_KXLC005_B)));
if (pcmcia_loop_config(link, pcmcia_check_one_config, &is_kme)) {
link->config_flags &= ~CONF_AUTO_CHECK_VCC;
if (pcmcia_loop_config(link, pcmcia_check_one_config, &is_kme))
goto failed;
}
io_base = link->resource[0]->start;
if (link->resource[1]->end)
ctl_base = link->resource[1]->start;
else
ctl_base = link->resource[0]->start + 0x0e;
if (!link->irq)
goto failed;
ret = pcmcia_enable_device(link);
if (ret)
goto failed;
outb(0x02, ctl_base);
if (is_kme)
outb(0x81, ctl_base+1);
host = idecs_register(io_base, ctl_base, link->irq, link);
if (host == NULL && resource_size(link->resource[0]) == 0x20) {
outb(0x02, ctl_base + 0x10);
host = idecs_register(io_base + 0x10, ctl_base + 0x10,
link->irq, link);
}
if (host == NULL)
goto failed;
info->ndev = 1;
info->host = host;
dev_info(&link->dev, "ide-cs: hd%c: Vpp = %d.%d\n",
'a' + host->ports[0]->index * 2,
link->vpp / 10, link->vpp % 10);
return 0;
failed:
ide_release(link);
return -ENODEV;
}
static void ide_release(struct pcmcia_device *link)
{
ide_info_t *info = link->priv;
struct ide_host *host = info->host;
dev_dbg(&link->dev, "ide_release(0x%p)\n", link);
if (info->ndev) {
ide_hwif_t *hwif = host->ports[0];
unsigned long data_addr, ctl_addr;
data_addr = hwif->io_ports.data_addr;
ctl_addr = hwif->io_ports.ctl_addr;
ide_host_remove(host);
info->ndev = 0;
release_region(ctl_addr, 1);
release_region(data_addr, 8);
}
pcmcia_disable_device(link);
}
static int __init init_ide_cs(void)
{
return pcmcia_register_driver(&ide_cs_driver);
}
static void __exit exit_ide_cs(void)
{
pcmcia_unregister_driver(&ide_cs_driver);
}
