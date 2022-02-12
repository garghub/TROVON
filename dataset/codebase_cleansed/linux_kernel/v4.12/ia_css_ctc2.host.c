static int ctc2_slope(int y1, int y0, int x1, int x0)
{
const int shift_val = 8;
const int max_slope = (1 << IA_CSS_CTC_COEF_SHIFT) - 1;
int dy = y1 - y0;
int dx = x1 - x0;
int rounding = (dx + 1) >> 1;
int dy_shift = dy << shift_val;
int slope, dydx;
assert(y0 >= 0 && y0 <= max_slope);
assert(y1 >= 0 && y1 <= max_slope);
assert(x0 >= 0 && x0 <= max_slope);
assert(x1 > 0 && x1 <= max_slope);
assert(dx > 0);
if (dy < 0)
rounding = -rounding;
slope = (int) (dy_shift + rounding) / dx;
if (slope <= -max_slope-1) {
dydx = -max_slope-1;
} else if (slope >= max_slope) {
dydx = max_slope;
} else {
dydx = slope;
}
return dydx;
}
void ia_css_ctc2_vmem_encode(struct ia_css_isp_ctc2_vmem_params *to,
const struct ia_css_ctc2_config *from,
size_t size)
{
unsigned i, j;
const unsigned shffl_blck = 4;
const unsigned lenght_zeros = 11;
short dydx0, dydx1, dydx2, dydx3, dydx4;
(void)size;
dydx0 = ctc2_slope(from->y_y1, from->y_y0,
from->y_x1, 0);
dydx1 = ctc2_slope(from->y_y2, from->y_y1,
from->y_x2, from->y_x1);
dydx2 = ctc2_slope(from->y_y3, from->y_y2,
from->y_x3, from->y_x2);
dydx3 = ctc2_slope(from->y_y4, from->y_y3,
from->y_x4, from->y_x3);
dydx4 = ctc2_slope(from->y_y5, from->y_y4,
SH_CSS_BAYER_MAXVAL, from->y_x4);
for (i = 0; i < shffl_blck; i++) {
to->y_x[0][(i << shffl_blck)] = 0;
to->y_x[0][(i << shffl_blck) + 1] = from->y_x1;
to->y_x[0][(i << shffl_blck) + 2] = from->y_x2;
to->y_x[0][(i << shffl_blck) + 3] = from->y_x3;
to->y_x[0][(i << shffl_blck) + 4] = from->y_x4;
to->y_y[0][(i << shffl_blck)] = from->y_y0;
to->y_y[0][(i << shffl_blck) + 1] = from->y_y1;
to->y_y[0][(i << shffl_blck) + 2] = from->y_y2;
to->y_y[0][(i << shffl_blck) + 3] = from->y_y3;
to->y_y[0][(i << shffl_blck) + 4] = from->y_y4;
to->e_y_slope[0][(i << shffl_blck)] = dydx0;
to->e_y_slope[0][(i << shffl_blck) + 1] = dydx1;
to->e_y_slope[0][(i << shffl_blck) + 2] = dydx2;
to->e_y_slope[0][(i << shffl_blck) + 3] = dydx3;
to->e_y_slope[0][(i << shffl_blck) + 4] = dydx4;
for (j = 0; j < lenght_zeros; j++) {
to->y_x[0][(i << shffl_blck) + 5 + j] = 0;
to->y_y[0][(i << shffl_blck) + 5 + j] = 0;
to->e_y_slope[0][(i << shffl_blck)+ 5 + j] = 0;
}
}
}
void ia_css_ctc2_encode(struct ia_css_isp_ctc2_dmem_params *to,
struct ia_css_ctc2_config *from,
size_t size)
{
(void)size;
to->uv_y0 = from->uv_y0;
to->uv_y1 = from->uv_y1;
to->uv_x0 = from->uv_x0;
to->uv_x1 = from->uv_x1;
to->uv_dydx = ctc2_slope(from->uv_y1, from->uv_y0,
from->uv_x1, from->uv_x0);
}
