static int __split_add_bits(struct sw842_param *p, u64 d, u8 n, u8 s)
{
int ret;
if (n <= s)
return -EINVAL;
ret = add_bits(p, d >> s, n - s);
if (ret)
return ret;
return add_bits(p, d & GENMASK_ULL(s - 1, 0), s);
}
static int add_bits(struct sw842_param *p, u64 d, u8 n)
{
int b = p->bit, bits = b + n, s = round_up(bits, 8) - bits;
u64 o;
u8 *out = p->out;
pr_debug("add %u bits %lx\n", (unsigned char)n, (unsigned long)d);
if (n > 64)
return -EINVAL;
if (bits > 64)
return __split_add_bits(p, d, n, 32);
else if (p->olen < 8 && bits > 32 && bits <= 56)
return __split_add_bits(p, d, n, 16);
else if (p->olen < 4 && bits > 16 && bits <= 24)
return __split_add_bits(p, d, n, 8);
if (DIV_ROUND_UP(bits, 8) > p->olen)
return -ENOSPC;
o = *out & bmask[b];
d <<= s;
if (bits <= 8)
*out = o | d;
else if (bits <= 16)
put_unaligned(cpu_to_be16(o << 8 | d), (__be16 *)out);
else if (bits <= 24)
put_unaligned(cpu_to_be32(o << 24 | d << 8), (__be32 *)out);
else if (bits <= 32)
put_unaligned(cpu_to_be32(o << 24 | d), (__be32 *)out);
else if (bits <= 40)
put_unaligned(cpu_to_be64(o << 56 | d << 24), (__be64 *)out);
else if (bits <= 48)
put_unaligned(cpu_to_be64(o << 56 | d << 16), (__be64 *)out);
else if (bits <= 56)
put_unaligned(cpu_to_be64(o << 56 | d << 8), (__be64 *)out);
else
put_unaligned(cpu_to_be64(o << 56 | d), (__be64 *)out);
p->bit += n;
if (p->bit > 7) {
p->out += p->bit / 8;
p->olen -= p->bit / 8;
p->bit %= 8;
}
return 0;
}
static int add_template(struct sw842_param *p, u8 c)
{
int ret, i, b = 0;
u8 *t = comp_ops[c];
bool inv = false;
if (c >= OPS_MAX)
return -EINVAL;
pr_debug("template %x\n", t[4]);
ret = add_bits(p, t[4], OP_BITS);
if (ret)
return ret;
for (i = 0; i < 4; i++) {
pr_debug("op %x\n", t[i]);
switch (t[i] & OP_AMOUNT) {
case OP_AMOUNT_8:
if (b)
inv = true;
else if (t[i] & OP_ACTION_INDEX)
ret = add_bits(p, p->index8[0], I8_BITS);
else if (t[i] & OP_ACTION_DATA)
ret = add_bits(p, p->data8[0], 64);
else
inv = true;
break;
case OP_AMOUNT_4:
if (b == 2 && t[i] & OP_ACTION_DATA)
ret = add_bits(p, get_input_data(p, 2, 32), 32);
else if (b != 0 && b != 4)
inv = true;
else if (t[i] & OP_ACTION_INDEX)
ret = add_bits(p, p->index4[b >> 2], I4_BITS);
else if (t[i] & OP_ACTION_DATA)
ret = add_bits(p, p->data4[b >> 2], 32);
else
inv = true;
break;
case OP_AMOUNT_2:
if (b != 0 && b != 2 && b != 4 && b != 6)
inv = true;
if (t[i] & OP_ACTION_INDEX)
ret = add_bits(p, p->index2[b >> 1], I2_BITS);
else if (t[i] & OP_ACTION_DATA)
ret = add_bits(p, p->data2[b >> 1], 16);
else
inv = true;
break;
case OP_AMOUNT_0:
inv = (b != 8) || !(t[i] & OP_ACTION_NOOP);
break;
default:
inv = true;
break;
}
if (ret)
return ret;
if (inv) {
pr_err("Invalid templ %x op %d : %x %x %x %x\n",
c, i, t[0], t[1], t[2], t[3]);
return -EINVAL;
}
b += t[i] & OP_AMOUNT;
}
if (b != 8) {
pr_err("Invalid template %x len %x : %x %x %x %x\n",
c, b, t[0], t[1], t[2], t[3]);
return -EINVAL;
}
if (sw842_template_counts)
atomic_inc(&template_count[t[4]]);
return 0;
}
static int add_repeat_template(struct sw842_param *p, u8 r)
{
int ret;
if (!r || --r > REPEAT_BITS_MAX)
return -EINVAL;
ret = add_bits(p, OP_REPEAT, OP_BITS);
if (ret)
return ret;
ret = add_bits(p, r, REPEAT_BITS);
if (ret)
return ret;
if (sw842_template_counts)
atomic_inc(&template_repeat_count);
return 0;
}
static int add_short_data_template(struct sw842_param *p, u8 b)
{
int ret, i;
if (!b || b > SHORT_DATA_BITS_MAX)
return -EINVAL;
ret = add_bits(p, OP_SHORT_DATA, OP_BITS);
if (ret)
return ret;
ret = add_bits(p, b, SHORT_DATA_BITS);
if (ret)
return ret;
for (i = 0; i < b; i++) {
ret = add_bits(p, p->in[i], 8);
if (ret)
return ret;
}
if (sw842_template_counts)
atomic_inc(&template_short_data_count);
return 0;
}
static int add_zeros_template(struct sw842_param *p)
{
int ret = add_bits(p, OP_ZEROS, OP_BITS);
if (ret)
return ret;
if (sw842_template_counts)
atomic_inc(&template_zeros_count);
return 0;
}
static int add_end_template(struct sw842_param *p)
{
int ret = add_bits(p, OP_END, OP_BITS);
if (ret)
return ret;
if (sw842_template_counts)
atomic_inc(&template_end_count);
return 0;
}
static bool check_template(struct sw842_param *p, u8 c)
{
u8 *t = comp_ops[c];
int i, match, b = 0;
if (c >= OPS_MAX)
return false;
for (i = 0; i < 4; i++) {
if (t[i] & OP_ACTION_INDEX) {
if (t[i] & OP_AMOUNT_2)
match = check_index(p, 2, b >> 1);
else if (t[i] & OP_AMOUNT_4)
match = check_index(p, 4, b >> 2);
else if (t[i] & OP_AMOUNT_8)
match = check_index(p, 8, 0);
else
return false;
if (!match)
return false;
}
b += t[i] & OP_AMOUNT;
}
return true;
}
static void get_next_data(struct sw842_param *p)
{
p->data8[0] = get_input_data(p, 0, 64);
p->data4[0] = get_input_data(p, 0, 32);
p->data4[1] = get_input_data(p, 4, 32);
p->data2[0] = get_input_data(p, 0, 16);
p->data2[1] = get_input_data(p, 2, 16);
p->data2[2] = get_input_data(p, 4, 16);
p->data2[3] = get_input_data(p, 6, 16);
}
static void update_hashtables(struct sw842_param *p)
{
u64 pos = p->in - p->instart;
u64 n8 = (pos >> 3) % (1 << I8_BITS);
u64 n4 = (pos >> 2) % (1 << I4_BITS);
u64 n2 = (pos >> 1) % (1 << I2_BITS);
replace_hash(p, 8, n8, 0);
replace_hash(p, 4, n4, 0);
replace_hash(p, 4, n4, 1);
replace_hash(p, 2, n2, 0);
replace_hash(p, 2, n2, 1);
replace_hash(p, 2, n2, 2);
replace_hash(p, 2, n2, 3);
}
static int process_next(struct sw842_param *p)
{
int ret, i;
p->index8[0] = INDEX_NOT_CHECKED;
p->index4[0] = INDEX_NOT_CHECKED;
p->index4[1] = INDEX_NOT_CHECKED;
p->index2[0] = INDEX_NOT_CHECKED;
p->index2[1] = INDEX_NOT_CHECKED;
p->index2[2] = INDEX_NOT_CHECKED;
p->index2[3] = INDEX_NOT_CHECKED;
for (i = 0; i < OPS_MAX - 1; i++) {
if (check_template(p, i))
break;
}
ret = add_template(p, i);
if (ret)
return ret;
return 0;
}
int sw842_compress(const u8 *in, unsigned int ilen,
u8 *out, unsigned int *olen, void *wmem)
{
struct sw842_param *p = (struct sw842_param *)wmem;
int ret;
u64 last, next, pad, total;
u8 repeat_count = 0;
BUILD_BUG_ON(sizeof(*p) > SW842_MEM_COMPRESS);
init_hashtable_nodes(p, 8);
init_hashtable_nodes(p, 4);
init_hashtable_nodes(p, 2);
p->in = (u8 *)in;
p->instart = p->in;
p->ilen = ilen;
p->out = out;
p->olen = *olen;
p->bit = 0;
total = p->olen;
*olen = 0;
if (sw842_strict && (ilen % 8)) {
pr_err("Using strict mode, can't compress len %d\n", ilen);
return -EINVAL;
}
if (unlikely(ilen < 8))
goto skip_comp;
last = ~get_unaligned((u64 *)p->in);
while (p->ilen > 7) {
next = get_unaligned((u64 *)p->in);
get_next_data(p);
if (next == last) {
if (++repeat_count <= REPEAT_BITS_MAX)
goto repeat;
}
if (repeat_count) {
ret = add_repeat_template(p, repeat_count);
repeat_count = 0;
if (next == last)
goto repeat;
}
if (next == 0)
ret = add_zeros_template(p);
else
ret = process_next(p);
if (ret)
return ret;
repeat:
last = next;
update_hashtables(p);
p->in += 8;
p->ilen -= 8;
}
if (repeat_count) {
ret = add_repeat_template(p, repeat_count);
if (ret)
return ret;
}
skip_comp:
if (p->ilen > 0) {
ret = add_short_data_template(p, p->ilen);
if (ret)
return ret;
p->in += p->ilen;
p->ilen = 0;
}
ret = add_end_template(p);
if (ret)
return ret;
if (p->bit) {
p->out++;
p->olen--;
p->bit = 0;
}
pad = (8 - ((total - p->olen) % 8)) % 8;
if (pad) {
if (pad > p->olen)
return -ENOSPC;
memset(p->out, 0, pad);
p->out += pad;
p->olen -= pad;
}
if (unlikely((total - p->olen) > UINT_MAX))
return -ENOSPC;
*olen = total - p->olen;
return 0;
}
static int __init sw842_init(void)
{
if (sw842_template_counts)
sw842_debugfs_create();
return 0;
}
static void __exit sw842_exit(void)
{
if (sw842_template_counts)
sw842_debugfs_remove();
}
