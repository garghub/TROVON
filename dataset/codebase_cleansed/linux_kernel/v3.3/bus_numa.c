void x86_pci_root_bus_resources(int bus, struct list_head *resources)
{
int i;
int j;
struct pci_root_info *info;
if (!pci_root_num)
goto default_resources;
for (i = 0; i < pci_root_num; i++) {
if (pci_root_info[i].bus_min == bus)
break;
}
if (i == pci_root_num)
goto default_resources;
printk(KERN_DEBUG "PCI: root bus %02x: hardware-probed resources\n",
bus);
info = &pci_root_info[i];
for (j = 0; j < info->res_num; j++) {
struct resource *res;
struct resource *root;
res = &info->res[j];
pci_add_resource(resources, res);
if (res->flags & IORESOURCE_IO)
root = &ioport_resource;
else
root = &iomem_resource;
insert_resource(root, res);
}
return;
default_resources:
printk(KERN_DEBUG "PCI: root bus %02x: using default resources\n", bus);
pci_add_resource(resources, &ioport_resource);
pci_add_resource(resources, &iomem_resource);
}
void __devinit update_res(struct pci_root_info *info, resource_size_t start,
resource_size_t end, unsigned long flags, int merge)
{
int i;
struct resource *res;
if (start > end)
return;
if (start == MAX_RESOURCE)
return;
if (!merge)
goto addit;
for (i = 0; i < info->res_num; i++) {
resource_size_t final_start, final_end;
resource_size_t common_start, common_end;
res = &info->res[i];
if (res->flags != flags)
continue;
common_start = max(res->start, start);
common_end = min(res->end, end);
if (common_start > common_end + 1)
continue;
final_start = min(res->start, start);
final_end = max(res->end, end);
res->start = final_start;
res->end = final_end;
return;
}
addit:
if (info->res_num >= RES_NUM)
return;
res = &info->res[info->res_num];
res->name = info->name;
res->flags = flags;
res->start = start;
res->end = end;
res->child = NULL;
info->res_num++;
}
