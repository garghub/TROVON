void *skl_nhlt_init(struct device *dev)
{
acpi_handle handle;
union acpi_object *obj;
struct nhlt_resource_desc *nhlt_ptr = NULL;
if (ACPI_FAILURE(acpi_get_handle(NULL, DSDT_NHLT_PATH, &handle))) {
dev_err(dev, "Requested NHLT device not found\n");
return NULL;
}
obj = acpi_evaluate_dsm(handle, OSC_UUID, 1, 1, NULL);
if (obj && obj->type == ACPI_TYPE_BUFFER) {
nhlt_ptr = (struct nhlt_resource_desc *)obj->buffer.pointer;
return memremap(nhlt_ptr->min_addr, nhlt_ptr->length,
MEMREMAP_WB);
}
dev_err(dev, "device specific method to extract NHLT blob failed\n");
return NULL;
}
void skl_nhlt_free(void *addr)
{
memunmap(addr);
}
static struct nhlt_specific_cfg *skl_get_specific_cfg(
struct device *dev, struct nhlt_fmt *fmt,
u8 no_ch, u32 rate, u16 bps, u8 linktype)
{
struct nhlt_specific_cfg *sp_config;
struct wav_fmt *wfmt;
struct nhlt_fmt_cfg *fmt_config = fmt->fmt_config;
int i;
dev_dbg(dev, "Format count =%d\n", fmt->fmt_count);
for (i = 0; i < fmt->fmt_count; i++) {
wfmt = &fmt_config->fmt_ext.fmt;
dev_dbg(dev, "ch=%d fmt=%d s_rate=%d\n", wfmt->channels,
wfmt->bits_per_sample, wfmt->samples_per_sec);
if (wfmt->channels == no_ch && wfmt->bits_per_sample == bps) {
sp_config = &fmt_config->config;
if (linktype == NHLT_LINK_DMIC)
return sp_config;
if (wfmt->samples_per_sec == rate)
return sp_config;
}
fmt_config = (struct nhlt_fmt_cfg *)(fmt_config->config.caps +
fmt_config->config.size);
}
return NULL;
}
static void dump_config(struct device *dev, u32 instance_id, u8 linktype,
u8 s_fmt, u8 num_channels, u32 s_rate, u8 dirn, u16 bps)
{
dev_dbg(dev, "Input configuration\n");
dev_dbg(dev, "ch=%d fmt=%d s_rate=%d\n", num_channels, s_fmt, s_rate);
dev_dbg(dev, "vbus_id=%d link_type=%d\n", instance_id, linktype);
dev_dbg(dev, "bits_per_sample=%d\n", bps);
}
static bool skl_check_ep_match(struct device *dev, struct nhlt_endpoint *epnt,
u32 instance_id, u8 link_type, u8 dirn)
{
dev_dbg(dev, "vbus_id=%d link_type=%d dir=%d\n",
epnt->virtual_bus_id, epnt->linktype, epnt->direction);
if ((epnt->virtual_bus_id == instance_id) &&
(epnt->linktype == link_type) &&
(epnt->direction == dirn))
return true;
else
return false;
}
struct nhlt_specific_cfg
*skl_get_ep_blob(struct skl *skl, u32 instance, u8 link_type,
u8 s_fmt, u8 num_ch, u32 s_rate, u8 dirn)
{
struct nhlt_fmt *fmt;
struct nhlt_endpoint *epnt;
struct hdac_bus *bus = ebus_to_hbus(&skl->ebus);
struct device *dev = bus->dev;
struct nhlt_specific_cfg *sp_config;
struct nhlt_acpi_table *nhlt = (struct nhlt_acpi_table *)skl->nhlt;
u16 bps = (s_fmt == 16) ? 16 : 32;
u8 j;
dump_config(dev, instance, link_type, s_fmt, num_ch, s_rate, dirn, bps);
epnt = (struct nhlt_endpoint *)nhlt->desc;
dev_dbg(dev, "endpoint count =%d\n", nhlt->endpoint_count);
for (j = 0; j < nhlt->endpoint_count; j++) {
if (skl_check_ep_match(dev, epnt, instance, link_type, dirn)) {
fmt = (struct nhlt_fmt *)(epnt->config.caps +
epnt->config.size);
sp_config = skl_get_specific_cfg(dev, fmt, num_ch,
s_rate, bps, link_type);
if (sp_config)
return sp_config;
}
epnt = (struct nhlt_endpoint *)((u8 *)epnt + epnt->length);
}
return NULL;
}
static void skl_nhlt_trim_space(struct skl *skl)
{
char *s = skl->tplg_name;
int cnt;
int i;
cnt = 0;
for (i = 0; s[i]; i++) {
if (!isspace(s[i]))
s[cnt++] = s[i];
}
s[cnt] = '\0';
}
int skl_nhlt_update_topology_bin(struct skl *skl)
{
struct nhlt_acpi_table *nhlt = (struct nhlt_acpi_table *)skl->nhlt;
struct hdac_bus *bus = ebus_to_hbus(&skl->ebus);
struct device *dev = bus->dev;
dev_dbg(dev, "oem_id %.6s, oem_table_id %8s oem_revision %d\n",
nhlt->header.oem_id, nhlt->header.oem_table_id,
nhlt->header.oem_revision);
snprintf(skl->tplg_name, sizeof(skl->tplg_name), "%x-%.6s-%.8s-%d%s",
skl->pci_id, nhlt->header.oem_id, nhlt->header.oem_table_id,
nhlt->header.oem_revision, "-tplg.bin");
skl_nhlt_trim_space(skl);
return 0;
}
