static unsigned int kmp_find(struct ts_config *conf, struct ts_state *state)
{
struct ts_kmp *kmp = ts_config_priv(conf);
unsigned int i, q = 0, text_len, consumed = state->offset;
const u8 *text;
const int icase = conf->flags & TS_IGNORECASE;
for (;;) {
text_len = conf->get_next_block(consumed, &text, conf, state);
if (unlikely(text_len == 0))
break;
for (i = 0; i < text_len; i++) {
while (q > 0 && kmp->pattern[q]
!= (icase ? toupper(text[i]) : text[i]))
q = kmp->prefix_tbl[q - 1];
if (kmp->pattern[q]
== (icase ? toupper(text[i]) : text[i]))
q++;
if (unlikely(q == kmp->pattern_len)) {
state->offset = consumed + i + 1;
return state->offset - kmp->pattern_len;
}
}
consumed += text_len;
}
return UINT_MAX;
}
static inline void compute_prefix_tbl(const u8 *pattern, unsigned int len,
unsigned int *prefix_tbl, int flags)
{
unsigned int k, q;
const u8 icase = flags & TS_IGNORECASE;
for (k = 0, q = 1; q < len; q++) {
while (k > 0 && (icase ? toupper(pattern[k]) : pattern[k])
!= (icase ? toupper(pattern[q]) : pattern[q]))
k = prefix_tbl[k-1];
if ((icase ? toupper(pattern[k]) : pattern[k])
== (icase ? toupper(pattern[q]) : pattern[q]))
k++;
prefix_tbl[q] = k;
}
}
static struct ts_config *kmp_init(const void *pattern, unsigned int len,
gfp_t gfp_mask, int flags)
{
struct ts_config *conf;
struct ts_kmp *kmp;
int i;
unsigned int prefix_tbl_len = len * sizeof(unsigned int);
size_t priv_size = sizeof(*kmp) + len + prefix_tbl_len;
conf = alloc_ts_config(priv_size, gfp_mask);
if (IS_ERR(conf))
return conf;
conf->flags = flags;
kmp = ts_config_priv(conf);
kmp->pattern_len = len;
compute_prefix_tbl(pattern, len, kmp->prefix_tbl, flags);
kmp->pattern = (u8 *) kmp->prefix_tbl + prefix_tbl_len;
if (flags & TS_IGNORECASE)
for (i = 0; i < len; i++)
kmp->pattern[i] = toupper(((u8 *)pattern)[i]);
else
memcpy(kmp->pattern, pattern, len);
return conf;
}
static void *kmp_get_pattern(struct ts_config *conf)
{
struct ts_kmp *kmp = ts_config_priv(conf);
return kmp->pattern;
}
static unsigned int kmp_get_pattern_len(struct ts_config *conf)
{
struct ts_kmp *kmp = ts_config_priv(conf);
return kmp->pattern_len;
}
static int __init init_kmp(void)
{
return textsearch_register(&kmp_ops);
}
static void __exit exit_kmp(void)
{
textsearch_unregister(&kmp_ops);
}
