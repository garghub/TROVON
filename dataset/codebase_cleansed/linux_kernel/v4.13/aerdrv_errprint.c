static void __print_tlp_header(struct pci_dev *dev,
struct aer_header_log_regs *t)
{
dev_err(&dev->dev, " TLP Header: %08x %08x %08x %08x\n",
t->dw0, t->dw1, t->dw2, t->dw3);
}
static void __aer_print_error(struct pci_dev *dev,
struct aer_err_info *info)
{
int i, status;
const char *errmsg = NULL;
status = (info->status & ~info->mask);
for (i = 0; i < 32; i++) {
if (!(status & (1 << i)))
continue;
if (info->severity == AER_CORRECTABLE)
errmsg = i < ARRAY_SIZE(aer_correctable_error_string) ?
aer_correctable_error_string[i] : NULL;
else
errmsg = i < ARRAY_SIZE(aer_uncorrectable_error_string) ?
aer_uncorrectable_error_string[i] : NULL;
if (errmsg)
dev_err(&dev->dev, " [%2d] %-22s%s\n", i, errmsg,
info->first_error == i ? " (First)" : "");
else
dev_err(&dev->dev, " [%2d] Unknown Error Bit%s\n",
i, info->first_error == i ? " (First)" : "");
}
}
void aer_print_error(struct pci_dev *dev, struct aer_err_info *info)
{
int layer, agent;
int id = ((dev->bus->number << 8) | dev->devfn);
if (!info->status) {
dev_err(&dev->dev, "PCIe Bus Error: severity=%s, type=Unaccessible, id=%04x(Unregistered Agent ID)\n",
aer_error_severity_string[info->severity], id);
goto out;
}
layer = AER_GET_LAYER_ERROR(info->severity, info->status);
agent = AER_GET_AGENT(info->severity, info->status);
dev_err(&dev->dev, "PCIe Bus Error: severity=%s, type=%s, id=%04x(%s)\n",
aer_error_severity_string[info->severity],
aer_error_layer[layer], id, aer_agent_string[agent]);
dev_err(&dev->dev, " device [%04x:%04x] error status/mask=%08x/%08x\n",
dev->vendor, dev->device,
info->status, info->mask);
__aer_print_error(dev, info);
if (info->tlp_header_valid)
__print_tlp_header(dev, &info->tlp);
out:
if (info->id && info->error_dev_num > 1 && info->id == id)
dev_err(&dev->dev, " Error of this Agent(%04x) is reported first\n", id);
trace_aer_event(dev_name(&dev->dev), (info->status & ~info->mask),
info->severity);
}
void aer_print_port_info(struct pci_dev *dev, struct aer_err_info *info)
{
dev_info(&dev->dev, "AER: %s%s error received: id=%04x\n",
info->multi_error_valid ? "Multiple " : "",
aer_error_severity_string[info->severity], info->id);
}
int cper_severity_to_aer(int cper_severity)
{
switch (cper_severity) {
case CPER_SEV_RECOVERABLE:
return AER_NONFATAL;
case CPER_SEV_FATAL:
return AER_FATAL;
default:
return AER_CORRECTABLE;
}
}
void cper_print_aer(struct pci_dev *dev, int aer_severity,
struct aer_capability_regs *aer)
{
int layer, agent, status_strs_size, tlp_header_valid = 0;
u32 status, mask;
const char **status_strs;
if (aer_severity == AER_CORRECTABLE) {
status = aer->cor_status;
mask = aer->cor_mask;
status_strs = aer_correctable_error_string;
status_strs_size = ARRAY_SIZE(aer_correctable_error_string);
} else {
status = aer->uncor_status;
mask = aer->uncor_mask;
status_strs = aer_uncorrectable_error_string;
status_strs_size = ARRAY_SIZE(aer_uncorrectable_error_string);
tlp_header_valid = status & AER_LOG_TLP_MASKS;
}
layer = AER_GET_LAYER_ERROR(aer_severity, status);
agent = AER_GET_AGENT(aer_severity, status);
dev_err(&dev->dev, "aer_status: 0x%08x, aer_mask: 0x%08x\n", status, mask);
cper_print_bits("", status, status_strs, status_strs_size);
dev_err(&dev->dev, "aer_layer=%s, aer_agent=%s\n",
aer_error_layer[layer], aer_agent_string[agent]);
if (aer_severity != AER_CORRECTABLE)
dev_err(&dev->dev, "aer_uncor_severity: 0x%08x\n",
aer->uncor_severity);
if (tlp_header_valid)
__print_tlp_header(dev, &aer->header_log);
trace_aer_event(dev_name(&dev->dev), (status & ~mask),
aer_severity);
}
