void
ia_css_bh_hmem_decode(
struct ia_css_3a_rgby_output *out_ptr,
const struct ia_css_bh_table *hmem_buf)
{
int i;
if(!hmem_buf)
return;
assert(sizeof_hmem(HMEM0_ID) == sizeof(*hmem_buf));
for (i = 0; i < HMEM_UNIT_SIZE; i++) {
out_ptr[i].r = hmem_buf->hmem[BH_COLOR_R][i];
out_ptr[i].g = hmem_buf->hmem[BH_COLOR_G][i];
out_ptr[i].b = hmem_buf->hmem[BH_COLOR_B][i];
out_ptr[i].y = hmem_buf->hmem[BH_COLOR_Y][i];
}
}
void
ia_css_bh_encode(
struct sh_css_isp_bh_params *to,
const struct ia_css_3a_config *from,
unsigned size)
{
(void)size;
to->y_coef_r =
uDIGIT_FITTING(from->ae_y_coef_r, 16, SH_CSS_AE_YCOEF_SHIFT);
to->y_coef_g =
uDIGIT_FITTING(from->ae_y_coef_g, 16, SH_CSS_AE_YCOEF_SHIFT);
to->y_coef_b =
uDIGIT_FITTING(from->ae_y_coef_b, 16, SH_CSS_AE_YCOEF_SHIFT);
}
