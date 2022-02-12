void ec_GFp_nistp_points_make_affine_internal(size_t num, void *point_array,
size_t felem_size, void *tmp_felems,
void (*felem_one)(void *out),
int (*felem_is_zero)(const void *in),
void (*felem_assign)(void *out, const void *in),
void (*felem_square)(void *out, const void *in),
void (*felem_mul)(void *out, const void *in1, const void *in2),
void (*felem_inv)(void *out, const void *in),
void (*felem_contract)(void *out, const void *in))
{
int i = 0;
#define tmp_felem(I) (&((char *)tmp_felems)[(I) * felem_size])
#define X(I) (&((char *)point_array)[3*(I) * felem_size])
#define Y(I) (&((char *)point_array)[(3*(I) + 1) * felem_size])
#define Z(I) (&((char *)point_array)[(3*(I) + 2) * felem_size])
if (!felem_is_zero(Z(0)))
felem_assign(tmp_felem(0), Z(0));
else
felem_one(tmp_felem(0));
for (i = 1; i < (int)num; i++)
{
if (!felem_is_zero(Z(i)))
felem_mul(tmp_felem(i), tmp_felem(i-1), Z(i));
else
felem_assign(tmp_felem(i), tmp_felem(i-1));
}
felem_inv(tmp_felem(num-1), tmp_felem(num-1));
for (i = num - 1; i >= 0; i--)
{
if (i > 0)
felem_mul(tmp_felem(num), tmp_felem(i-1), tmp_felem(i));
else
felem_assign(tmp_felem(num), tmp_felem(0));
if (!felem_is_zero(Z(i)))
{
if (i > 0)
felem_mul(tmp_felem(i-1), tmp_felem(i), Z(i));
felem_square(Z(i), tmp_felem(num));
felem_mul(X(i), X(i), Z(i));
felem_mul(Z(i), Z(i), tmp_felem(num));
felem_mul(Y(i), Y(i), Z(i));
felem_contract(X(i), X(i));
felem_contract(Y(i), Y(i));
felem_one(Z(i));
}
else
{
if (i > 0)
felem_assign(tmp_felem(i-1), tmp_felem(i));
}
}
}
void ec_GFp_nistp_recode_scalar_bits(unsigned char *sign, unsigned char *digit, unsigned char in)
{
unsigned char s, d;
s = ~((in >> 5) - 1);
d = (1 << 6) - in - 1;
d = (d & s) | (in & ~s);
d = (d >> 1) + (d & 1);
*sign = s & 1;
*digit = d;
}
