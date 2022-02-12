static unsigned int label_bits(const struct nf_conn_labels *l)
{
unsigned int longs = l->words;
return longs * BITS_PER_LONG;
}
bool nf_connlabel_match(const struct nf_conn *ct, u16 bit)
{
struct nf_conn_labels *labels = nf_ct_labels_find(ct);
if (!labels)
return false;
return bit < label_bits(labels) && test_bit(bit, labels->bits);
}
int nf_connlabel_set(struct nf_conn *ct, u16 bit)
{
struct nf_conn_labels *labels = nf_ct_labels_find(ct);
if (!labels || bit >= label_bits(labels))
return -ENOSPC;
if (test_bit(bit, labels->bits))
return 0;
if (!test_and_set_bit(bit, labels->bits))
nf_conntrack_event_cache(IPCT_LABEL, ct);
return 0;
}
static void replace_u32(u32 *address, u32 mask, u32 new)
{
u32 old, tmp;
do {
old = *address;
tmp = (old & mask) ^ new;
} while (cmpxchg(address, old, tmp) != old);
}
int nf_connlabels_replace(struct nf_conn *ct,
const u32 *data,
const u32 *mask, unsigned int words32)
{
struct nf_conn_labels *labels;
unsigned int size, i;
u32 *dst;
labels = nf_ct_labels_find(ct);
if (!labels)
return -ENOSPC;
size = labels->words * sizeof(long);
if (size < (words32 * sizeof(u32)))
words32 = size / sizeof(u32);
dst = (u32 *) labels->bits;
if (words32) {
for (i = 0; i < words32; i++)
replace_u32(&dst[i], mask ? ~mask[i] : 0, data[i]);
}
size /= sizeof(u32);
for (i = words32; i < size; i++)
replace_u32(&dst[i], 0, 0);
nf_conntrack_event_cache(IPCT_LABEL, ct);
return 0;
}
int nf_conntrack_labels_init(void)
{
return nf_ct_extend_register(&labels_extend);
}
void nf_conntrack_labels_fini(void)
{
nf_ct_extend_unregister(&labels_extend);
}
