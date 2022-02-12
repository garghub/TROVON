static inline int
update_match_cpu(unsigned int csig, unsigned int cpf,
unsigned int sig, unsigned int pf)
{
return (!sigmatch(sig, csig, pf, cpf)) ? 0 : 1;
}
int microcode_sanity_check(void *mc, int print_err)
{
unsigned long total_size, data_size, ext_table_size;
struct microcode_header_intel *mc_header = mc;
struct extended_sigtable *ext_header = NULL;
int sum, orig_sum, ext_sigcount = 0, i;
struct extended_signature *ext_sig;
total_size = get_totalsize(mc_header);
data_size = get_datasize(mc_header);
if (data_size + MC_HEADER_SIZE > total_size) {
if (print_err)
pr_err("error! Bad data size in microcode data file\n");
return -EINVAL;
}
if (mc_header->ldrver != 1 || mc_header->hdrver != 1) {
if (print_err)
pr_err("error! Unknown microcode update format\n");
return -EINVAL;
}
ext_table_size = total_size - (MC_HEADER_SIZE + data_size);
if (ext_table_size) {
if ((ext_table_size < EXT_HEADER_SIZE)
|| ((ext_table_size - EXT_HEADER_SIZE) % EXT_SIGNATURE_SIZE)) {
if (print_err)
pr_err("error! Small exttable size in microcode data file\n");
return -EINVAL;
}
ext_header = mc + MC_HEADER_SIZE + data_size;
if (ext_table_size != exttable_size(ext_header)) {
if (print_err)
pr_err("error! Bad exttable size in microcode data file\n");
return -EFAULT;
}
ext_sigcount = ext_header->count;
}
if (ext_table_size) {
int ext_table_sum = 0;
int *ext_tablep = (int *)ext_header;
i = ext_table_size / DWSIZE;
while (i--)
ext_table_sum += ext_tablep[i];
if (ext_table_sum) {
if (print_err)
pr_warn("aborting, bad extended signature table checksum\n");
return -EINVAL;
}
}
orig_sum = 0;
i = (MC_HEADER_SIZE + data_size) / DWSIZE;
while (i--)
orig_sum += ((int *)mc)[i];
if (orig_sum) {
if (print_err)
pr_err("aborting, bad checksum\n");
return -EINVAL;
}
if (!ext_table_size)
return 0;
for (i = 0; i < ext_sigcount; i++) {
ext_sig = (void *)ext_header + EXT_HEADER_SIZE +
EXT_SIGNATURE_SIZE * i;
sum = orig_sum
- (mc_header->sig + mc_header->pf + mc_header->cksum)
+ (ext_sig->sig + ext_sig->pf + ext_sig->cksum);
if (sum) {
if (print_err)
pr_err("aborting, bad checksum\n");
return -EINVAL;
}
}
return 0;
}
int get_matching_sig(unsigned int csig, int cpf, int rev, void *mc)
{
struct microcode_header_intel *mc_header = mc;
struct extended_sigtable *ext_header;
unsigned long total_size = get_totalsize(mc_header);
int ext_sigcount, i;
struct extended_signature *ext_sig;
if (update_match_cpu(csig, cpf, mc_header->sig, mc_header->pf))
return 1;
if (total_size <= get_datasize(mc_header) + MC_HEADER_SIZE)
return 0;
ext_header = mc + get_datasize(mc_header) + MC_HEADER_SIZE;
ext_sigcount = ext_header->count;
ext_sig = (void *)ext_header + EXT_HEADER_SIZE;
for (i = 0; i < ext_sigcount; i++) {
if (update_match_cpu(csig, cpf, ext_sig->sig, ext_sig->pf))
return 1;
ext_sig++;
}
return 0;
}
int get_matching_microcode(unsigned int csig, int cpf, int rev, void *mc)
{
struct microcode_header_intel *mc_hdr = mc;
if (!revision_is_newer(mc_hdr, rev))
return 0;
return get_matching_sig(csig, cpf, rev, mc);
}
