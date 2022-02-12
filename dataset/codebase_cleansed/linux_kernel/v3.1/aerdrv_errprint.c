static void __aer_print_error(const char *prefix,
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
printk("%s"" [%2d] %-22s%s\n", prefix, i, errmsg,
info->first_error == i ? " (First)" : "");
else
printk("%s"" [%2d] Unknown Error Bit%s\n", prefix, i,
info->first_error == i ? " (First)" : "");
}
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
void cper_print_aer(const char *prefix, int cper_severity,
struct aer_capability_regs *aer)
{
int aer_severity, layer, agent, status_strs_size, tlp_header_valid = 0;
u32 status, mask;
const char **status_strs;
aer_severity = cper_severity_to_aer(cper_severity);
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
printk("%s""aer_status: 0x%08x, aer_mask: 0x%08x\n",
prefix, status, mask);
cper_print_bits(prefix, status, status_strs, status_strs_size);
printk("%s""aer_layer=%s, aer_agent=%s\n", prefix,
aer_error_layer[layer], aer_agent_string[agent]);
if (aer_severity != AER_CORRECTABLE)
printk("%s""aer_uncor_severity: 0x%08x\n",
prefix, aer->uncor_severity);
if (tlp_header_valid) {
const unsigned char *tlp;
tlp = (const unsigned char *)&aer->header_log;
printk("%s""aer_tlp_header:"
" %02x%02x%02x%02x %02x%02x%02x%02x"
" %02x%02x%02x%02x %02x%02x%02x%02x\n"
