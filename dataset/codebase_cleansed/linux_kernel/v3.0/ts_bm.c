static unsigned int bm_find(struct ts_config *conf, struct ts_state *state)
{
struct ts_bm *bm = ts_config_priv(conf);
unsigned int i, text_len, consumed = state->offset;
const u8 *text;
int shift = bm->patlen - 1, bs;
const u8 icase = conf->flags & TS_IGNORECASE;
for (;;) {
text_len = conf->get_next_block(consumed, &text, conf, state);
if (unlikely(text_len == 0))
break;
while (shift < text_len) {
DEBUGP("Searching in position %d (%c)\n",
shift, text[shift]);
for (i = 0; i < bm->patlen; i++)
if ((icase ? toupper(text[shift-i])
: text[shift-i])
!= bm->pattern[bm->patlen-1-i])
goto next;
DEBUGP("found!\n");
return consumed += (shift-(bm->patlen-1));
next: bs = bm->bad_shift[text[shift-i]];
shift = max_t(int, shift-i+bs, shift+bm->good_shift[i]);
}
consumed += text_len;
}
return UINT_MAX;
}
static int subpattern(u8 *pattern, int i, int j, int g)
{
int x = i+g-1, y = j+g-1, ret = 0;
while(pattern[x--] == pattern[y--]) {
if (y < 0) {
ret = 1;
break;
}
if (--g == 0) {
ret = pattern[i-1] != pattern[j-1];
break;
}
}
return ret;
}
static void compute_prefix_tbl(struct ts_bm *bm, int flags)
{
int i, j, g;
for (i = 0; i < ASIZE; i++)
bm->bad_shift[i] = bm->patlen;
for (i = 0; i < bm->patlen - 1; i++) {
bm->bad_shift[bm->pattern[i]] = bm->patlen - 1 - i;
if (flags & TS_IGNORECASE)
bm->bad_shift[tolower(bm->pattern[i])]
= bm->patlen - 1 - i;
}
bm->good_shift[0] = 1;
for (i = 1; i < bm->patlen; i++)
bm->good_shift[i] = bm->patlen;
for (i = bm->patlen-1, g = 1; i > 0; g++, i--) {
for (j = i-1; j >= 1-g ; j--)
if (subpattern(bm->pattern, i, j, g)) {
bm->good_shift[g] = bm->patlen-j-g;
break;
}
}
}
static struct ts_config *bm_init(const void *pattern, unsigned int len,
gfp_t gfp_mask, int flags)
{
struct ts_config *conf;
struct ts_bm *bm;
int i;
unsigned int prefix_tbl_len = len * sizeof(unsigned int);
size_t priv_size = sizeof(*bm) + len + prefix_tbl_len;
conf = alloc_ts_config(priv_size, gfp_mask);
if (IS_ERR(conf))
return conf;
conf->flags = flags;
bm = ts_config_priv(conf);
bm->patlen = len;
bm->pattern = (u8 *) bm->good_shift + prefix_tbl_len;
if (flags & TS_IGNORECASE)
for (i = 0; i < len; i++)
bm->pattern[i] = toupper(((u8 *)pattern)[i]);
else
memcpy(bm->pattern, pattern, len);
compute_prefix_tbl(bm, flags);
return conf;
}
static void *bm_get_pattern(struct ts_config *conf)
{
struct ts_bm *bm = ts_config_priv(conf);
return bm->pattern;
}
static unsigned int bm_get_pattern_len(struct ts_config *conf)
{
struct ts_bm *bm = ts_config_priv(conf);
return bm->patlen;
}
static int __init init_bm(void)
{
return textsearch_register(&bm_ops);
}
static void __exit exit_bm(void)
{
textsearch_unregister(&bm_ops);
}
