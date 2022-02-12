static __be16 t10_pi_crc_fn(void *data, unsigned int len)
{
return cpu_to_be16(crc_t10dif(data, len));
}
static __be16 t10_pi_ip_fn(void *data, unsigned int len)
{
return (__force __be16)ip_compute_csum(data, len);
}
static int t10_pi_generate(struct blk_integrity_iter *iter, csum_fn *fn,
unsigned int type)
{
unsigned int i;
for (i = 0 ; i < iter->data_size ; i += iter->interval) {
struct t10_pi_tuple *pi = iter->prot_buf;
pi->guard_tag = fn(iter->data_buf, iter->interval);
pi->app_tag = 0;
if (type == 1)
pi->ref_tag = cpu_to_be32(lower_32_bits(iter->seed));
else
pi->ref_tag = 0;
iter->data_buf += iter->interval;
iter->prot_buf += sizeof(struct t10_pi_tuple);
iter->seed++;
}
return 0;
}
static int t10_pi_verify(struct blk_integrity_iter *iter, csum_fn *fn,
unsigned int type)
{
unsigned int i;
for (i = 0 ; i < iter->data_size ; i += iter->interval) {
struct t10_pi_tuple *pi = iter->prot_buf;
__be16 csum;
switch (type) {
case 1:
case 2:
if (pi->app_tag == APP_ESCAPE)
goto next;
if (be32_to_cpu(pi->ref_tag) !=
lower_32_bits(iter->seed)) {
pr_err("%s: ref tag error at location %llu " \
"(rcvd %u)\n", iter->disk_name,
(unsigned long long)
iter->seed, be32_to_cpu(pi->ref_tag));
return -EILSEQ;
}
break;
case 3:
if (pi->app_tag == APP_ESCAPE &&
pi->ref_tag == REF_ESCAPE)
goto next;
break;
}
csum = fn(iter->data_buf, iter->interval);
if (pi->guard_tag != csum) {
pr_err("%s: guard tag error at sector %llu " \
"(rcvd %04x, want %04x)\n", iter->disk_name,
(unsigned long long)iter->seed,
be16_to_cpu(pi->guard_tag), be16_to_cpu(csum));
return -EILSEQ;
}
next:
iter->data_buf += iter->interval;
iter->prot_buf += sizeof(struct t10_pi_tuple);
iter->seed++;
}
return 0;
}
static int t10_pi_type1_generate_crc(struct blk_integrity_iter *iter)
{
return t10_pi_generate(iter, t10_pi_crc_fn, 1);
}
static int t10_pi_type1_generate_ip(struct blk_integrity_iter *iter)
{
return t10_pi_generate(iter, t10_pi_ip_fn, 1);
}
static int t10_pi_type1_verify_crc(struct blk_integrity_iter *iter)
{
return t10_pi_verify(iter, t10_pi_crc_fn, 1);
}
static int t10_pi_type1_verify_ip(struct blk_integrity_iter *iter)
{
return t10_pi_verify(iter, t10_pi_ip_fn, 1);
}
static int t10_pi_type3_generate_crc(struct blk_integrity_iter *iter)
{
return t10_pi_generate(iter, t10_pi_crc_fn, 3);
}
static int t10_pi_type3_generate_ip(struct blk_integrity_iter *iter)
{
return t10_pi_generate(iter, t10_pi_ip_fn, 3);
}
static int t10_pi_type3_verify_crc(struct blk_integrity_iter *iter)
{
return t10_pi_verify(iter, t10_pi_crc_fn, 3);
}
static int t10_pi_type3_verify_ip(struct blk_integrity_iter *iter)
{
return t10_pi_verify(iter, t10_pi_ip_fn, 3);
}
