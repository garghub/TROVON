static void gf128mul_x_lle(be128 *r, const be128 *x)
{
u64 a = be64_to_cpu(x->a);
u64 b = be64_to_cpu(x->b);
u64 _tt = gf128mul_table_lle[(b << 7) & 0xff];
r->b = cpu_to_be64((b >> 1) | (a << 63));
r->a = cpu_to_be64((a >> 1) ^ (_tt << 48));
}
static void gf128mul_x_bbe(be128 *r, const be128 *x)
{
u64 a = be64_to_cpu(x->a);
u64 b = be64_to_cpu(x->b);
u64 _tt = gf128mul_table_bbe[a >> 63];
r->a = cpu_to_be64((a << 1) | (b >> 63));
r->b = cpu_to_be64((b << 1) ^ _tt);
}
void gf128mul_x_ble(be128 *r, const be128 *x)
{
u64 a = le64_to_cpu(x->a);
u64 b = le64_to_cpu(x->b);
u64 _tt = gf128mul_table_bbe[b >> 63];
r->a = cpu_to_le64((a << 1) ^ _tt);
r->b = cpu_to_le64((b << 1) | (a >> 63));
}
static void gf128mul_x8_lle(be128 *x)
{
u64 a = be64_to_cpu(x->a);
u64 b = be64_to_cpu(x->b);
u64 _tt = gf128mul_table_lle[b & 0xff];
x->b = cpu_to_be64((b >> 8) | (a << 56));
x->a = cpu_to_be64((a >> 8) ^ (_tt << 48));
}
static void gf128mul_x8_bbe(be128 *x)
{
u64 a = be64_to_cpu(x->a);
u64 b = be64_to_cpu(x->b);
u64 _tt = gf128mul_table_bbe[a >> 56];
x->a = cpu_to_be64((a << 8) | (b >> 56));
x->b = cpu_to_be64((b << 8) ^ _tt);
}
void gf128mul_lle(be128 *r, const be128 *b)
{
be128 p[8];
int i;
p[0] = *r;
for (i = 0; i < 7; ++i)
gf128mul_x_lle(&p[i + 1], &p[i]);
memset(r, 0, sizeof(*r));
for (i = 0;;) {
u8 ch = ((u8 *)b)[15 - i];
if (ch & 0x80)
be128_xor(r, r, &p[0]);
if (ch & 0x40)
be128_xor(r, r, &p[1]);
if (ch & 0x20)
be128_xor(r, r, &p[2]);
if (ch & 0x10)
be128_xor(r, r, &p[3]);
if (ch & 0x08)
be128_xor(r, r, &p[4]);
if (ch & 0x04)
be128_xor(r, r, &p[5]);
if (ch & 0x02)
be128_xor(r, r, &p[6]);
if (ch & 0x01)
be128_xor(r, r, &p[7]);
if (++i >= 16)
break;
gf128mul_x8_lle(r);
}
}
void gf128mul_bbe(be128 *r, const be128 *b)
{
be128 p[8];
int i;
p[0] = *r;
for (i = 0; i < 7; ++i)
gf128mul_x_bbe(&p[i + 1], &p[i]);
memset(r, 0, sizeof(*r));
for (i = 0;;) {
u8 ch = ((u8 *)b)[i];
if (ch & 0x80)
be128_xor(r, r, &p[7]);
if (ch & 0x40)
be128_xor(r, r, &p[6]);
if (ch & 0x20)
be128_xor(r, r, &p[5]);
if (ch & 0x10)
be128_xor(r, r, &p[4]);
if (ch & 0x08)
be128_xor(r, r, &p[3]);
if (ch & 0x04)
be128_xor(r, r, &p[2]);
if (ch & 0x02)
be128_xor(r, r, &p[1]);
if (ch & 0x01)
be128_xor(r, r, &p[0]);
if (++i >= 16)
break;
gf128mul_x8_bbe(r);
}
}
struct gf128mul_64k *gf128mul_init_64k_bbe(const be128 *g)
{
struct gf128mul_64k *t;
int i, j, k;
t = kzalloc(sizeof(*t), GFP_KERNEL);
if (!t)
goto out;
for (i = 0; i < 16; i++) {
t->t[i] = kzalloc(sizeof(*t->t[i]), GFP_KERNEL);
if (!t->t[i]) {
gf128mul_free_64k(t);
t = NULL;
goto out;
}
}
t->t[0]->t[1] = *g;
for (j = 1; j <= 64; j <<= 1)
gf128mul_x_bbe(&t->t[0]->t[j + j], &t->t[0]->t[j]);
for (i = 0;;) {
for (j = 2; j < 256; j += j)
for (k = 1; k < j; ++k)
be128_xor(&t->t[i]->t[j + k],
&t->t[i]->t[j], &t->t[i]->t[k]);
if (++i >= 16)
break;
for (j = 128; j > 0; j >>= 1) {
t->t[i]->t[j] = t->t[i - 1]->t[j];
gf128mul_x8_bbe(&t->t[i]->t[j]);
}
}
out:
return t;
}
void gf128mul_free_64k(struct gf128mul_64k *t)
{
int i;
for (i = 0; i < 16; i++)
kzfree(t->t[i]);
kzfree(t);
}
void gf128mul_64k_bbe(be128 *a, struct gf128mul_64k *t)
{
u8 *ap = (u8 *)a;
be128 r[1];
int i;
*r = t->t[0]->t[ap[15]];
for (i = 1; i < 16; ++i)
be128_xor(r, r, &t->t[i]->t[ap[15 - i]]);
*a = *r;
}
struct gf128mul_4k *gf128mul_init_4k_lle(const be128 *g)
{
struct gf128mul_4k *t;
int j, k;
t = kzalloc(sizeof(*t), GFP_KERNEL);
if (!t)
goto out;
t->t[128] = *g;
for (j = 64; j > 0; j >>= 1)
gf128mul_x_lle(&t->t[j], &t->t[j+j]);
for (j = 2; j < 256; j += j)
for (k = 1; k < j; ++k)
be128_xor(&t->t[j + k], &t->t[j], &t->t[k]);
out:
return t;
}
struct gf128mul_4k *gf128mul_init_4k_bbe(const be128 *g)
{
struct gf128mul_4k *t;
int j, k;
t = kzalloc(sizeof(*t), GFP_KERNEL);
if (!t)
goto out;
t->t[1] = *g;
for (j = 1; j <= 64; j <<= 1)
gf128mul_x_bbe(&t->t[j + j], &t->t[j]);
for (j = 2; j < 256; j += j)
for (k = 1; k < j; ++k)
be128_xor(&t->t[j + k], &t->t[j], &t->t[k]);
out:
return t;
}
void gf128mul_4k_lle(be128 *a, struct gf128mul_4k *t)
{
u8 *ap = (u8 *)a;
be128 r[1];
int i = 15;
*r = t->t[ap[15]];
while (i--) {
gf128mul_x8_lle(r);
be128_xor(r, r, &t->t[ap[i]]);
}
*a = *r;
}
void gf128mul_4k_bbe(be128 *a, struct gf128mul_4k *t)
{
u8 *ap = (u8 *)a;
be128 r[1];
int i = 0;
*r = t->t[ap[0]];
while (++i < 16) {
gf128mul_x8_bbe(r);
be128_xor(r, r, &t->t[ap[i]]);
}
*a = *r;
}
