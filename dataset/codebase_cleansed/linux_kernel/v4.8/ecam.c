struct pci_config_window *pci_ecam_create(struct device *dev,
struct resource *cfgres, struct resource *busr,
struct pci_ecam_ops *ops)
{
struct pci_config_window *cfg;
unsigned int bus_range, bus_range_max, bsz;
struct resource *conflict;
int i, err;
if (busr->start > busr->end)
return ERR_PTR(-EINVAL);
cfg = kzalloc(sizeof(*cfg), GFP_KERNEL);
if (!cfg)
return ERR_PTR(-ENOMEM);
cfg->parent = dev;
cfg->ops = ops;
cfg->busr.start = busr->start;
cfg->busr.end = busr->end;
cfg->busr.flags = IORESOURCE_BUS;
bus_range = resource_size(&cfg->busr);
bus_range_max = resource_size(cfgres) >> ops->bus_shift;
if (bus_range > bus_range_max) {
bus_range = bus_range_max;
cfg->busr.end = busr->start + bus_range - 1;
dev_warn(dev, "ECAM area %pR can only accommodate %pR (reduced from %pR desired)\n",
cfgres, &cfg->busr, busr);
}
bsz = 1 << ops->bus_shift;
cfg->res.start = cfgres->start;
cfg->res.end = cfgres->end;
cfg->res.flags = IORESOURCE_MEM | IORESOURCE_BUSY;
cfg->res.name = "PCI ECAM";
conflict = request_resource_conflict(&iomem_resource, &cfg->res);
if (conflict) {
err = -EBUSY;
dev_err(dev, "can't claim ECAM area %pR: address conflict with %s %pR\n",
&cfg->res, conflict->name, conflict);
goto err_exit;
}
if (per_bus_mapping) {
cfg->winp = kcalloc(bus_range, sizeof(*cfg->winp), GFP_KERNEL);
if (!cfg->winp)
goto err_exit_malloc;
for (i = 0; i < bus_range; i++) {
cfg->winp[i] = ioremap(cfgres->start + i * bsz, bsz);
if (!cfg->winp[i])
goto err_exit_iomap;
}
} else {
cfg->win = ioremap(cfgres->start, bus_range * bsz);
if (!cfg->win)
goto err_exit_iomap;
}
if (ops->init) {
err = ops->init(cfg);
if (err)
goto err_exit;
}
dev_info(dev, "ECAM at %pR for %pR\n", &cfg->res, &cfg->busr);
return cfg;
err_exit_iomap:
dev_err(dev, "ECAM ioremap failed\n");
err_exit_malloc:
err = -ENOMEM;
err_exit:
pci_ecam_free(cfg);
return ERR_PTR(err);
}
void pci_ecam_free(struct pci_config_window *cfg)
{
int i;
if (per_bus_mapping) {
if (cfg->winp) {
for (i = 0; i < resource_size(&cfg->busr); i++)
if (cfg->winp[i])
iounmap(cfg->winp[i]);
kfree(cfg->winp);
}
} else {
if (cfg->win)
iounmap(cfg->win);
}
if (cfg->res.parent)
release_resource(&cfg->res);
kfree(cfg);
}
void __iomem *pci_ecam_map_bus(struct pci_bus *bus, unsigned int devfn,
int where)
{
struct pci_config_window *cfg = bus->sysdata;
unsigned int devfn_shift = cfg->ops->bus_shift - 8;
unsigned int busn = bus->number;
void __iomem *base;
if (busn < cfg->busr.start || busn > cfg->busr.end)
return NULL;
busn -= cfg->busr.start;
if (per_bus_mapping)
base = cfg->winp[busn];
else
base = cfg->win + (busn << cfg->ops->bus_shift);
return base + (devfn << devfn_shift) + where;
}
