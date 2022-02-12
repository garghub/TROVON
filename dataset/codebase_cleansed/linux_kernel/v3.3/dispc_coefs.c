const struct dispc_coef *dispc_ovl_get_scale_coef(int inc, int five_taps)
{
int i;
static const struct {
int Mmin;
int Mmax;
const struct dispc_coef *coef_3;
const struct dispc_coef *coef_5;
} coefs[] = {
{ 27, 32, coef3_M32, coef5_M32 },
{ 23, 26, coef3_M26, coef5_M26 },
{ 20, 22, coef3_M22, coef5_M22 },
{ 17, 19, coef3_M19, coef5_M19 },
{ 15, 16, coef3_M16, coef5_M16 },
{ 14, 14, coef3_M14, coef5_M14 },
{ 13, 13, coef3_M13, coef5_M13 },
{ 12, 12, coef3_M12, coef5_M12 },
{ 11, 11, coef3_M11, coef5_M11 },
{ 10, 10, coef3_M10, coef5_M10 },
{ 9, 9, coef3_M9, coef5_M9 },
{ 4, 8, coef3_M8, coef5_M8 },
{ 3, 3, coef3_M11, coef5_M11 },
{ 2, 2, coef3_M16, coef5_M16 },
{ 0, 1, coef3_M19, coef5_M19 },
};
inc /= 128;
for (i = 0; i < ARRAY_LEN(coefs); ++i)
if (inc >= coefs[i].Mmin && inc <= coefs[i].Mmax)
return five_taps ? coefs[i].coef_5 : coefs[i].coef_3;
return NULL;
}
