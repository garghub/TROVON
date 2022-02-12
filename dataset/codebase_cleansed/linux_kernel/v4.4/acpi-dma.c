static int acpi_dma_parse_resource_group(const struct acpi_csrt_group *grp,
struct acpi_device *adev, struct acpi_dma *adma)
{
const struct acpi_csrt_shared_info *si;
struct list_head resource_list;
struct resource_entry *rentry;
resource_size_t mem = 0, irq = 0;
int ret;
if (grp->shared_info_length != sizeof(struct acpi_csrt_shared_info))
return -ENODEV;
INIT_LIST_HEAD(&resource_list);
ret = acpi_dev_get_resources(adev, &resource_list, NULL, NULL);
if (ret <= 0)
return 0;
list_for_each_entry(rentry, &resource_list, node) {
if (resource_type(rentry->res) == IORESOURCE_MEM)
mem = rentry->res->start;
else if (resource_type(rentry->res) == IORESOURCE_IRQ)
irq = rentry->res->start;
}
acpi_dev_free_resource_list(&resource_list);
if (mem == 0 && irq == 0)
return 0;
si = (const struct acpi_csrt_shared_info *)&grp[1];
if (si->mmio_base_low != mem || si->gsi_interrupt != irq)
return 0;
dev_dbg(&adev->dev, "matches with %.4s%04X (rev %u)\n",
(char *)&grp->vendor_id, grp->device_id, grp->revision);
if (si->base_request_line == 0 && si->num_handshake_signals == 0)
return 0;
adma->base_request_line = si->base_request_line;
adma->end_request_line = si->base_request_line +
si->num_handshake_signals - 1;
dev_dbg(&adev->dev, "request line base: 0x%04x end: 0x%04x\n",
adma->base_request_line, adma->end_request_line);
return 1;
}
static void acpi_dma_parse_csrt(struct acpi_device *adev, struct acpi_dma *adma)
{
struct acpi_csrt_group *grp, *end;
struct acpi_table_csrt *csrt;
acpi_status status;
int ret;
status = acpi_get_table(ACPI_SIG_CSRT, 0,
(struct acpi_table_header **)&csrt);
if (ACPI_FAILURE(status)) {
if (status != AE_NOT_FOUND)
dev_warn(&adev->dev, "failed to get the CSRT table\n");
return;
}
grp = (struct acpi_csrt_group *)(csrt + 1);
end = (struct acpi_csrt_group *)((void *)csrt + csrt->header.length);
while (grp < end) {
ret = acpi_dma_parse_resource_group(grp, adev, adma);
if (ret < 0) {
dev_warn(&adev->dev,
"error in parsing resource group\n");
return;
}
grp = (struct acpi_csrt_group *)((void *)grp + grp->length);
}
}
int acpi_dma_controller_free(struct device *dev)
{
struct acpi_dma *adma;
if (!dev)
return -EINVAL;
mutex_lock(&acpi_dma_lock);
list_for_each_entry(adma, &acpi_dma_list, dma_controllers)
if (adma->dev == dev) {
list_del(&adma->dma_controllers);
mutex_unlock(&acpi_dma_lock);
kfree(adma);
return 0;
}
mutex_unlock(&acpi_dma_lock);
return -ENODEV;
}
static void devm_acpi_dma_release(struct device *dev, void *res)
{
acpi_dma_controller_free(dev);
}
void devm_acpi_dma_controller_free(struct device *dev)
{
WARN_ON(devres_release(dev, devm_acpi_dma_release, NULL, NULL));
}
static int acpi_dma_update_dma_spec(struct acpi_dma *adma,
struct acpi_dma_spec *dma_spec)
{
dma_spec->dev = adma->dev;
if (adma->base_request_line == 0 && adma->end_request_line == 0)
return 0;
if (dma_spec->slave_id < adma->base_request_line ||
dma_spec->slave_id > adma->end_request_line)
return -1;
dma_spec->slave_id -= adma->base_request_line;
return 1;
}
static int acpi_dma_parse_fixed_dma(struct acpi_resource *res, void *data)
{
struct acpi_dma_parser_data *pdata = data;
if (res->type == ACPI_RESOURCE_TYPE_FIXED_DMA) {
struct acpi_resource_fixed_dma *dma = &res->data.fixed_dma;
if (pdata->n++ == pdata->index) {
pdata->dma_spec.chan_id = dma->channels;
pdata->dma_spec.slave_id = dma->request_lines;
}
}
return 1;
}
struct dma_chan *acpi_dma_request_slave_chan_by_index(struct device *dev,
size_t index)
{
struct acpi_dma_parser_data pdata;
struct acpi_dma_spec *dma_spec = &pdata.dma_spec;
struct list_head resource_list;
struct acpi_device *adev;
struct acpi_dma *adma;
struct dma_chan *chan = NULL;
int found;
if (!dev)
return ERR_PTR(-ENODEV);
adev = ACPI_COMPANION(dev);
if (!adev)
return ERR_PTR(-ENODEV);
memset(&pdata, 0, sizeof(pdata));
pdata.index = index;
dma_spec->chan_id = -1;
dma_spec->slave_id = -1;
INIT_LIST_HEAD(&resource_list);
acpi_dev_get_resources(adev, &resource_list,
acpi_dma_parse_fixed_dma, &pdata);
acpi_dev_free_resource_list(&resource_list);
if (dma_spec->slave_id < 0 || dma_spec->chan_id < 0)
return ERR_PTR(-ENODEV);
mutex_lock(&acpi_dma_lock);
list_for_each_entry(adma, &acpi_dma_list, dma_controllers) {
found = acpi_dma_update_dma_spec(adma, dma_spec);
if (found < 0)
continue;
chan = adma->acpi_dma_xlate(dma_spec, adma);
if (found > 0 || chan)
break;
}
mutex_unlock(&acpi_dma_lock);
return chan ? chan : ERR_PTR(-EPROBE_DEFER);
}
struct dma_chan *acpi_dma_request_slave_chan_by_name(struct device *dev,
const char *name)
{
int index;
index = device_property_match_string(dev, "dma-names", name);
if (index < 0) {
if (!strcmp(name, "tx"))
index = 0;
else if (!strcmp(name, "rx"))
index = 1;
else
return ERR_PTR(-ENODEV);
}
dev_dbg(dev, "found DMA channel \"%s\" at index %d\n", name, index);
return acpi_dma_request_slave_chan_by_index(dev, index);
}
struct dma_chan *acpi_dma_simple_xlate(struct acpi_dma_spec *dma_spec,
struct acpi_dma *adma)
{
struct acpi_dma_filter_info *info = adma->data;
if (!info || !info->filter_fn)
return NULL;
return dma_request_channel(info->dma_cap, info->filter_fn, dma_spec);
}
