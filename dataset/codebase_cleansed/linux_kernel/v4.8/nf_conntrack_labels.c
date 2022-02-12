static int replace_u32(u32 *address, u32 mask, u32 new)
{
u32 old, tmp;
do {
old = *address;
tmp = (old & mask) ^ new;
if (old == tmp)
return 0;
} while (cmpxchg(address, old, tmp) != old);
return 1;
}
int nf_connlabels_replace(struct nf_conn *ct,
const u32 *data,
const u32 *mask, unsigned int words32)
{
struct nf_conn_labels *labels;
unsigned int size, i;
int changed = 0;
u32 *dst;
labels = nf_ct_labels_find(ct);
if (!labels)
return -ENOSPC;
size = sizeof(labels->bits);
if (size < (words32 * sizeof(u32)))
words32 = size / sizeof(u32);
dst = (u32 *) labels->bits;
for (i = 0; i < words32; i++)
changed |= replace_u32(&dst[i], mask ? ~mask[i] : 0, data[i]);
size /= sizeof(u32);
for (i = words32; i < size; i++)
replace_u32(&dst[i], 0, 0);
if (changed)
nf_conntrack_event_cache(IPCT_LABEL, ct);
return 0;
}
int nf_connlabels_get(struct net *net, unsigned int bits)
{
if (BIT_WORD(bits) >= NF_CT_LABELS_MAX_SIZE / sizeof(long))
return -ERANGE;
spin_lock(&nf_connlabels_lock);
net->ct.labels_used++;
spin_unlock(&nf_connlabels_lock);
return 0;
}
void nf_connlabels_put(struct net *net)
{
spin_lock(&nf_connlabels_lock);
net->ct.labels_used--;
spin_unlock(&nf_connlabels_lock);
}
int nf_conntrack_labels_init(void)
{
BUILD_BUG_ON(NF_CT_LABELS_MAX_SIZE / sizeof(long) >= U8_MAX);
spin_lock_init(&nf_connlabels_lock);
return nf_ct_extend_register(&labels_extend);
}
void nf_conntrack_labels_fini(void)
{
nf_ct_extend_unregister(&labels_extend);
}
