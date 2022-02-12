static inline const struct ecc_curve *ecc_get_curve(unsigned int curve_id)
{
switch (curve_id) {
case ECC_CURVE_NIST_P192:
return fips_enabled ? NULL : &nist_p192;
case ECC_CURVE_NIST_P256:
return &nist_p256;
default:
return NULL;
}
}
static u64 *ecc_alloc_digits_space(unsigned int ndigits)
{
size_t len = ndigits * sizeof(u64);
if (!len)
return NULL;
return kmalloc(len, GFP_KERNEL);
}
static void ecc_free_digits_space(u64 *space)
{
kzfree(space);
}
static struct ecc_point *ecc_alloc_point(unsigned int ndigits)
{
struct ecc_point *p = kmalloc(sizeof(*p), GFP_KERNEL);
if (!p)
return NULL;
p->x = ecc_alloc_digits_space(ndigits);
if (!p->x)
goto err_alloc_x;
p->y = ecc_alloc_digits_space(ndigits);
if (!p->y)
goto err_alloc_y;
p->ndigits = ndigits;
return p;
err_alloc_y:
ecc_free_digits_space(p->x);
err_alloc_x:
kfree(p);
return NULL;
}
static void ecc_free_point(struct ecc_point *p)
{
if (!p)
return;
kzfree(p->x);
kzfree(p->y);
kzfree(p);
}
static void vli_clear(u64 *vli, unsigned int ndigits)
{
int i;
for (i = 0; i < ndigits; i++)
vli[i] = 0;
}
static bool vli_is_zero(const u64 *vli, unsigned int ndigits)
{
int i;
for (i = 0; i < ndigits; i++) {
if (vli[i])
return false;
}
return true;
}
static u64 vli_test_bit(const u64 *vli, unsigned int bit)
{
return (vli[bit / 64] & ((u64)1 << (bit % 64)));
}
static unsigned int vli_num_digits(const u64 *vli, unsigned int ndigits)
{
int i;
for (i = ndigits - 1; i >= 0 && vli[i] == 0; i--);
return (i + 1);
}
static unsigned int vli_num_bits(const u64 *vli, unsigned int ndigits)
{
unsigned int i, num_digits;
u64 digit;
num_digits = vli_num_digits(vli, ndigits);
if (num_digits == 0)
return 0;
digit = vli[num_digits - 1];
for (i = 0; digit; i++)
digit >>= 1;
return ((num_digits - 1) * 64 + i);
}
static void vli_set(u64 *dest, const u64 *src, unsigned int ndigits)
{
int i;
for (i = 0; i < ndigits; i++)
dest[i] = src[i];
}
static int vli_cmp(const u64 *left, const u64 *right, unsigned int ndigits)
{
int i;
for (i = ndigits - 1; i >= 0; i--) {
if (left[i] > right[i])
return 1;
else if (left[i] < right[i])
return -1;
}
return 0;
}
static u64 vli_lshift(u64 *result, const u64 *in, unsigned int shift,
unsigned int ndigits)
{
u64 carry = 0;
int i;
for (i = 0; i < ndigits; i++) {
u64 temp = in[i];
result[i] = (temp << shift) | carry;
carry = temp >> (64 - shift);
}
return carry;
}
static void vli_rshift1(u64 *vli, unsigned int ndigits)
{
u64 *end = vli;
u64 carry = 0;
vli += ndigits;
while (vli-- > end) {
u64 temp = *vli;
*vli = (temp >> 1) | carry;
carry = temp << 63;
}
}
static u64 vli_add(u64 *result, const u64 *left, const u64 *right,
unsigned int ndigits)
{
u64 carry = 0;
int i;
for (i = 0; i < ndigits; i++) {
u64 sum;
sum = left[i] + right[i] + carry;
if (sum != left[i])
carry = (sum < left[i]);
result[i] = sum;
}
return carry;
}
static u64 vli_sub(u64 *result, const u64 *left, const u64 *right,
unsigned int ndigits)
{
u64 borrow = 0;
int i;
for (i = 0; i < ndigits; i++) {
u64 diff;
diff = left[i] - right[i] - borrow;
if (diff != left[i])
borrow = (diff > left[i]);
result[i] = diff;
}
return borrow;
}
static uint128_t mul_64_64(u64 left, u64 right)
{
u64 a0 = left & 0xffffffffull;
u64 a1 = left >> 32;
u64 b0 = right & 0xffffffffull;
u64 b1 = right >> 32;
u64 m0 = a0 * b0;
u64 m1 = a0 * b1;
u64 m2 = a1 * b0;
u64 m3 = a1 * b1;
uint128_t result;
m2 += (m0 >> 32);
m2 += m1;
if (m2 < m1)
m3 += 0x100000000ull;
result.m_low = (m0 & 0xffffffffull) | (m2 << 32);
result.m_high = m3 + (m2 >> 32);
return result;
}
static uint128_t add_128_128(uint128_t a, uint128_t b)
{
uint128_t result;
result.m_low = a.m_low + b.m_low;
result.m_high = a.m_high + b.m_high + (result.m_low < a.m_low);
return result;
}
static void vli_mult(u64 *result, const u64 *left, const u64 *right,
unsigned int ndigits)
{
uint128_t r01 = { 0, 0 };
u64 r2 = 0;
unsigned int i, k;
for (k = 0; k < ndigits * 2 - 1; k++) {
unsigned int min;
if (k < ndigits)
min = 0;
else
min = (k + 1) - ndigits;
for (i = min; i <= k && i < ndigits; i++) {
uint128_t product;
product = mul_64_64(left[i], right[k - i]);
r01 = add_128_128(r01, product);
r2 += (r01.m_high < product.m_high);
}
result[k] = r01.m_low;
r01.m_low = r01.m_high;
r01.m_high = r2;
r2 = 0;
}
result[ndigits * 2 - 1] = r01.m_low;
}
static void vli_square(u64 *result, const u64 *left, unsigned int ndigits)
{
uint128_t r01 = { 0, 0 };
u64 r2 = 0;
int i, k;
for (k = 0; k < ndigits * 2 - 1; k++) {
unsigned int min;
if (k < ndigits)
min = 0;
else
min = (k + 1) - ndigits;
for (i = min; i <= k && i <= k - i; i++) {
uint128_t product;
product = mul_64_64(left[i], left[k - i]);
if (i < k - i) {
r2 += product.m_high >> 63;
product.m_high = (product.m_high << 1) |
(product.m_low >> 63);
product.m_low <<= 1;
}
r01 = add_128_128(r01, product);
r2 += (r01.m_high < product.m_high);
}
result[k] = r01.m_low;
r01.m_low = r01.m_high;
r01.m_high = r2;
r2 = 0;
}
result[ndigits * 2 - 1] = r01.m_low;
}
static void vli_mod_add(u64 *result, const u64 *left, const u64 *right,
const u64 *mod, unsigned int ndigits)
{
u64 carry;
carry = vli_add(result, left, right, ndigits);
if (carry || vli_cmp(result, mod, ndigits) >= 0)
vli_sub(result, result, mod, ndigits);
}
static void vli_mod_sub(u64 *result, const u64 *left, const u64 *right,
const u64 *mod, unsigned int ndigits)
{
u64 borrow = vli_sub(result, left, right, ndigits);
if (borrow)
vli_add(result, result, mod, ndigits);
}
static void vli_mmod_fast_192(u64 *result, const u64 *product,
const u64 *curve_prime, u64 *tmp)
{
const unsigned int ndigits = 3;
int carry;
vli_set(result, product, ndigits);
vli_set(tmp, &product[3], ndigits);
carry = vli_add(result, result, tmp, ndigits);
tmp[0] = 0;
tmp[1] = product[3];
tmp[2] = product[4];
carry += vli_add(result, result, tmp, ndigits);
tmp[0] = tmp[1] = product[5];
tmp[2] = 0;
carry += vli_add(result, result, tmp, ndigits);
while (carry || vli_cmp(curve_prime, result, ndigits) != 1)
carry -= vli_sub(result, result, curve_prime, ndigits);
}
static void vli_mmod_fast_256(u64 *result, const u64 *product,
const u64 *curve_prime, u64 *tmp)
{
int carry;
const unsigned int ndigits = 4;
vli_set(result, product, ndigits);
tmp[0] = 0;
tmp[1] = product[5] & 0xffffffff00000000ull;
tmp[2] = product[6];
tmp[3] = product[7];
carry = vli_lshift(tmp, tmp, 1, ndigits);
carry += vli_add(result, result, tmp, ndigits);
tmp[1] = product[6] << 32;
tmp[2] = (product[6] >> 32) | (product[7] << 32);
tmp[3] = product[7] >> 32;
carry += vli_lshift(tmp, tmp, 1, ndigits);
carry += vli_add(result, result, tmp, ndigits);
tmp[0] = product[4];
tmp[1] = product[5] & 0xffffffff;
tmp[2] = 0;
tmp[3] = product[7];
carry += vli_add(result, result, tmp, ndigits);
tmp[0] = (product[4] >> 32) | (product[5] << 32);
tmp[1] = (product[5] >> 32) | (product[6] & 0xffffffff00000000ull);
tmp[2] = product[7];
tmp[3] = (product[6] >> 32) | (product[4] << 32);
carry += vli_add(result, result, tmp, ndigits);
tmp[0] = (product[5] >> 32) | (product[6] << 32);
tmp[1] = (product[6] >> 32);
tmp[2] = 0;
tmp[3] = (product[4] & 0xffffffff) | (product[5] << 32);
carry -= vli_sub(result, result, tmp, ndigits);
tmp[0] = product[6];
tmp[1] = product[7];
tmp[2] = 0;
tmp[3] = (product[4] >> 32) | (product[5] & 0xffffffff00000000ull);
carry -= vli_sub(result, result, tmp, ndigits);
tmp[0] = (product[6] >> 32) | (product[7] << 32);
tmp[1] = (product[7] >> 32) | (product[4] << 32);
tmp[2] = (product[4] >> 32) | (product[5] << 32);
tmp[3] = (product[6] << 32);
carry -= vli_sub(result, result, tmp, ndigits);
tmp[0] = product[7];
tmp[1] = product[4] & 0xffffffff00000000ull;
tmp[2] = product[5];
tmp[3] = product[6] & 0xffffffff00000000ull;
carry -= vli_sub(result, result, tmp, ndigits);
if (carry < 0) {
do {
carry += vli_add(result, result, curve_prime, ndigits);
} while (carry < 0);
} else {
while (carry || vli_cmp(curve_prime, result, ndigits) != 1)
carry -= vli_sub(result, result, curve_prime, ndigits);
}
}
static bool vli_mmod_fast(u64 *result, u64 *product,
const u64 *curve_prime, unsigned int ndigits)
{
u64 tmp[2 * ndigits];
switch (ndigits) {
case 3:
vli_mmod_fast_192(result, product, curve_prime, tmp);
break;
case 4:
vli_mmod_fast_256(result, product, curve_prime, tmp);
break;
default:
pr_err("unsupports digits size!\n");
return false;
}
return true;
}
static void vli_mod_mult_fast(u64 *result, const u64 *left, const u64 *right,
const u64 *curve_prime, unsigned int ndigits)
{
u64 product[2 * ndigits];
vli_mult(product, left, right, ndigits);
vli_mmod_fast(result, product, curve_prime, ndigits);
}
static void vli_mod_square_fast(u64 *result, const u64 *left,
const u64 *curve_prime, unsigned int ndigits)
{
u64 product[2 * ndigits];
vli_square(product, left, ndigits);
vli_mmod_fast(result, product, curve_prime, ndigits);
}
static void vli_mod_inv(u64 *result, const u64 *input, const u64 *mod,
unsigned int ndigits)
{
u64 a[ndigits], b[ndigits];
u64 u[ndigits], v[ndigits];
u64 carry;
int cmp_result;
if (vli_is_zero(input, ndigits)) {
vli_clear(result, ndigits);
return;
}
vli_set(a, input, ndigits);
vli_set(b, mod, ndigits);
vli_clear(u, ndigits);
u[0] = 1;
vli_clear(v, ndigits);
while ((cmp_result = vli_cmp(a, b, ndigits)) != 0) {
carry = 0;
if (EVEN(a)) {
vli_rshift1(a, ndigits);
if (!EVEN(u))
carry = vli_add(u, u, mod, ndigits);
vli_rshift1(u, ndigits);
if (carry)
u[ndigits - 1] |= 0x8000000000000000ull;
} else if (EVEN(b)) {
vli_rshift1(b, ndigits);
if (!EVEN(v))
carry = vli_add(v, v, mod, ndigits);
vli_rshift1(v, ndigits);
if (carry)
v[ndigits - 1] |= 0x8000000000000000ull;
} else if (cmp_result > 0) {
vli_sub(a, a, b, ndigits);
vli_rshift1(a, ndigits);
if (vli_cmp(u, v, ndigits) < 0)
vli_add(u, u, mod, ndigits);
vli_sub(u, u, v, ndigits);
if (!EVEN(u))
carry = vli_add(u, u, mod, ndigits);
vli_rshift1(u, ndigits);
if (carry)
u[ndigits - 1] |= 0x8000000000000000ull;
} else {
vli_sub(b, b, a, ndigits);
vli_rshift1(b, ndigits);
if (vli_cmp(v, u, ndigits) < 0)
vli_add(v, v, mod, ndigits);
vli_sub(v, v, u, ndigits);
if (!EVEN(v))
carry = vli_add(v, v, mod, ndigits);
vli_rshift1(v, ndigits);
if (carry)
v[ndigits - 1] |= 0x8000000000000000ull;
}
}
vli_set(result, u, ndigits);
}
static bool ecc_point_is_zero(const struct ecc_point *point)
{
return (vli_is_zero(point->x, point->ndigits) &&
vli_is_zero(point->y, point->ndigits));
}
static void ecc_point_double_jacobian(u64 *x1, u64 *y1, u64 *z1,
u64 *curve_prime, unsigned int ndigits)
{
u64 t4[ndigits];
u64 t5[ndigits];
if (vli_is_zero(z1, ndigits))
return;
vli_mod_square_fast(t4, y1, curve_prime, ndigits);
vli_mod_mult_fast(t5, x1, t4, curve_prime, ndigits);
vli_mod_square_fast(t4, t4, curve_prime, ndigits);
vli_mod_mult_fast(y1, y1, z1, curve_prime, ndigits);
vli_mod_square_fast(z1, z1, curve_prime, ndigits);
vli_mod_add(x1, x1, z1, curve_prime, ndigits);
vli_mod_add(z1, z1, z1, curve_prime, ndigits);
vli_mod_sub(z1, x1, z1, curve_prime, ndigits);
vli_mod_mult_fast(x1, x1, z1, curve_prime, ndigits);
vli_mod_add(z1, x1, x1, curve_prime, ndigits);
vli_mod_add(x1, x1, z1, curve_prime, ndigits);
if (vli_test_bit(x1, 0)) {
u64 carry = vli_add(x1, x1, curve_prime, ndigits);
vli_rshift1(x1, ndigits);
x1[ndigits - 1] |= carry << 63;
} else {
vli_rshift1(x1, ndigits);
}
vli_mod_square_fast(z1, x1, curve_prime, ndigits);
vli_mod_sub(z1, z1, t5, curve_prime, ndigits);
vli_mod_sub(z1, z1, t5, curve_prime, ndigits);
vli_mod_sub(t5, t5, z1, curve_prime, ndigits);
vli_mod_mult_fast(x1, x1, t5, curve_prime, ndigits);
vli_mod_sub(t4, x1, t4, curve_prime, ndigits);
vli_set(x1, z1, ndigits);
vli_set(z1, y1, ndigits);
vli_set(y1, t4, ndigits);
}
static void apply_z(u64 *x1, u64 *y1, u64 *z, u64 *curve_prime,
unsigned int ndigits)
{
u64 t1[ndigits];
vli_mod_square_fast(t1, z, curve_prime, ndigits);
vli_mod_mult_fast(x1, x1, t1, curve_prime, ndigits);
vli_mod_mult_fast(t1, t1, z, curve_prime, ndigits);
vli_mod_mult_fast(y1, y1, t1, curve_prime, ndigits);
}
static void xycz_initial_double(u64 *x1, u64 *y1, u64 *x2, u64 *y2,
u64 *p_initial_z, u64 *curve_prime,
unsigned int ndigits)
{
u64 z[ndigits];
vli_set(x2, x1, ndigits);
vli_set(y2, y1, ndigits);
vli_clear(z, ndigits);
z[0] = 1;
if (p_initial_z)
vli_set(z, p_initial_z, ndigits);
apply_z(x1, y1, z, curve_prime, ndigits);
ecc_point_double_jacobian(x1, y1, z, curve_prime, ndigits);
apply_z(x2, y2, z, curve_prime, ndigits);
}
static void xycz_add(u64 *x1, u64 *y1, u64 *x2, u64 *y2, u64 *curve_prime,
unsigned int ndigits)
{
u64 t5[ndigits];
vli_mod_sub(t5, x2, x1, curve_prime, ndigits);
vli_mod_square_fast(t5, t5, curve_prime, ndigits);
vli_mod_mult_fast(x1, x1, t5, curve_prime, ndigits);
vli_mod_mult_fast(x2, x2, t5, curve_prime, ndigits);
vli_mod_sub(y2, y2, y1, curve_prime, ndigits);
vli_mod_square_fast(t5, y2, curve_prime, ndigits);
vli_mod_sub(t5, t5, x1, curve_prime, ndigits);
vli_mod_sub(t5, t5, x2, curve_prime, ndigits);
vli_mod_sub(x2, x2, x1, curve_prime, ndigits);
vli_mod_mult_fast(y1, y1, x2, curve_prime, ndigits);
vli_mod_sub(x2, x1, t5, curve_prime, ndigits);
vli_mod_mult_fast(y2, y2, x2, curve_prime, ndigits);
vli_mod_sub(y2, y2, y1, curve_prime, ndigits);
vli_set(x2, t5, ndigits);
}
static void xycz_add_c(u64 *x1, u64 *y1, u64 *x2, u64 *y2, u64 *curve_prime,
unsigned int ndigits)
{
u64 t5[ndigits];
u64 t6[ndigits];
u64 t7[ndigits];
vli_mod_sub(t5, x2, x1, curve_prime, ndigits);
vli_mod_square_fast(t5, t5, curve_prime, ndigits);
vli_mod_mult_fast(x1, x1, t5, curve_prime, ndigits);
vli_mod_mult_fast(x2, x2, t5, curve_prime, ndigits);
vli_mod_add(t5, y2, y1, curve_prime, ndigits);
vli_mod_sub(y2, y2, y1, curve_prime, ndigits);
vli_mod_sub(t6, x2, x1, curve_prime, ndigits);
vli_mod_mult_fast(y1, y1, t6, curve_prime, ndigits);
vli_mod_add(t6, x1, x2, curve_prime, ndigits);
vli_mod_square_fast(x2, y2, curve_prime, ndigits);
vli_mod_sub(x2, x2, t6, curve_prime, ndigits);
vli_mod_sub(t7, x1, x2, curve_prime, ndigits);
vli_mod_mult_fast(y2, y2, t7, curve_prime, ndigits);
vli_mod_sub(y2, y2, y1, curve_prime, ndigits);
vli_mod_square_fast(t7, t5, curve_prime, ndigits);
vli_mod_sub(t7, t7, t6, curve_prime, ndigits);
vli_mod_sub(t6, t7, x1, curve_prime, ndigits);
vli_mod_mult_fast(t6, t6, t5, curve_prime, ndigits);
vli_mod_sub(y1, t6, y1, curve_prime, ndigits);
vli_set(x1, t7, ndigits);
}
static void ecc_point_mult(struct ecc_point *result,
const struct ecc_point *point, const u64 *scalar,
u64 *initial_z, u64 *curve_prime,
unsigned int ndigits)
{
u64 rx[2][ndigits];
u64 ry[2][ndigits];
u64 z[ndigits];
int i, nb;
int num_bits = vli_num_bits(scalar, ndigits);
vli_set(rx[1], point->x, ndigits);
vli_set(ry[1], point->y, ndigits);
xycz_initial_double(rx[1], ry[1], rx[0], ry[0], initial_z, curve_prime,
ndigits);
for (i = num_bits - 2; i > 0; i--) {
nb = !vli_test_bit(scalar, i);
xycz_add_c(rx[1 - nb], ry[1 - nb], rx[nb], ry[nb], curve_prime,
ndigits);
xycz_add(rx[nb], ry[nb], rx[1 - nb], ry[1 - nb], curve_prime,
ndigits);
}
nb = !vli_test_bit(scalar, 0);
xycz_add_c(rx[1 - nb], ry[1 - nb], rx[nb], ry[nb], curve_prime,
ndigits);
vli_mod_sub(z, rx[1], rx[0], curve_prime, ndigits);
vli_mod_mult_fast(z, z, ry[1 - nb], curve_prime, ndigits);
vli_mod_mult_fast(z, z, point->x, curve_prime, ndigits);
vli_mod_inv(z, z, curve_prime, point->ndigits);
vli_mod_mult_fast(z, z, point->y, curve_prime, ndigits);
vli_mod_mult_fast(z, z, rx[1 - nb], curve_prime, ndigits);
xycz_add(rx[nb], ry[nb], rx[1 - nb], ry[1 - nb], curve_prime, ndigits);
apply_z(rx[0], ry[0], z, curve_prime, ndigits);
vli_set(result->x, rx[0], ndigits);
vli_set(result->y, ry[0], ndigits);
}
static inline void ecc_swap_digits(const u64 *in, u64 *out,
unsigned int ndigits)
{
int i;
for (i = 0; i < ndigits; i++)
out[i] = __swab64(in[ndigits - 1 - i]);
}
int ecc_is_key_valid(unsigned int curve_id, unsigned int ndigits,
const u64 *private_key, unsigned int private_key_len)
{
int nbytes;
const struct ecc_curve *curve = ecc_get_curve(curve_id);
if (!private_key)
return -EINVAL;
nbytes = ndigits << ECC_DIGITS_TO_BYTES_SHIFT;
if (private_key_len != nbytes)
return -EINVAL;
if (vli_is_zero(private_key, ndigits))
return -EINVAL;
if (vli_cmp(curve->n, private_key, ndigits) != 1)
return -EINVAL;
return 0;
}
int ecc_gen_privkey(unsigned int curve_id, unsigned int ndigits, u64 *privkey)
{
const struct ecc_curve *curve = ecc_get_curve(curve_id);
u64 priv[ndigits];
unsigned int nbytes = ndigits << ECC_DIGITS_TO_BYTES_SHIFT;
unsigned int nbits = vli_num_bits(curve->n, ndigits);
int err;
if (nbits < 160)
return -EINVAL;
if (crypto_get_default_rng())
err = -EFAULT;
err = crypto_rng_get_bytes(crypto_default_rng, (u8 *)priv, nbytes);
crypto_put_default_rng();
if (err)
return err;
if (vli_is_zero(priv, ndigits))
return -EINVAL;
if (vli_cmp(curve->n, priv, ndigits) != 1)
return -EINVAL;
ecc_swap_digits(priv, privkey, ndigits);
return 0;
}
int ecc_make_pub_key(unsigned int curve_id, unsigned int ndigits,
const u64 *private_key, u64 *public_key)
{
int ret = 0;
struct ecc_point *pk;
u64 priv[ndigits];
const struct ecc_curve *curve = ecc_get_curve(curve_id);
if (!private_key || !curve) {
ret = -EINVAL;
goto out;
}
ecc_swap_digits(private_key, priv, ndigits);
pk = ecc_alloc_point(ndigits);
if (!pk) {
ret = -ENOMEM;
goto out;
}
ecc_point_mult(pk, &curve->g, priv, NULL, curve->p, ndigits);
if (ecc_point_is_zero(pk)) {
ret = -EAGAIN;
goto err_free_point;
}
ecc_swap_digits(pk->x, public_key, ndigits);
ecc_swap_digits(pk->y, &public_key[ndigits], ndigits);
err_free_point:
ecc_free_point(pk);
out:
return ret;
}
int crypto_ecdh_shared_secret(unsigned int curve_id, unsigned int ndigits,
const u64 *private_key, const u64 *public_key,
u64 *secret)
{
int ret = 0;
struct ecc_point *product, *pk;
u64 priv[ndigits];
u64 rand_z[ndigits];
unsigned int nbytes;
const struct ecc_curve *curve = ecc_get_curve(curve_id);
if (!private_key || !public_key || !curve) {
ret = -EINVAL;
goto out;
}
nbytes = ndigits << ECC_DIGITS_TO_BYTES_SHIFT;
get_random_bytes(rand_z, nbytes);
pk = ecc_alloc_point(ndigits);
if (!pk) {
ret = -ENOMEM;
goto out;
}
product = ecc_alloc_point(ndigits);
if (!product) {
ret = -ENOMEM;
goto err_alloc_product;
}
ecc_swap_digits(public_key, pk->x, ndigits);
ecc_swap_digits(&public_key[ndigits], pk->y, ndigits);
ecc_swap_digits(private_key, priv, ndigits);
ecc_point_mult(product, pk, priv, rand_z, curve->p, ndigits);
ecc_swap_digits(product->x, secret, ndigits);
if (ecc_point_is_zero(product))
ret = -EFAULT;
ecc_free_point(product);
err_alloc_product:
ecc_free_point(pk);
out:
return ret;
}
