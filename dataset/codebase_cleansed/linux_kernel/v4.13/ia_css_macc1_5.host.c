void
ia_css_macc1_5_encode(
struct sh_css_isp_macc1_5_params *to,
const struct ia_css_macc1_5_config *from,
unsigned int size)
{
(void)size;
to->exp = from->exp;
}
void
ia_css_macc1_5_vmem_encode(
struct sh_css_isp_macc1_5_vmem_params *params,
const struct ia_css_macc1_5_table *from,
unsigned int size)
{
unsigned int i, j, k, idx;
unsigned int idx_map[] = {
0, 1, 3, 2, 6, 7, 5, 4, 12, 13, 15, 14, 10, 11, 9, 8};
(void)size;
for (k = 0; k < 4; k++)
for (i = 0; i < IA_CSS_MACC_NUM_AXES; i++) {
idx = idx_map[i] + (k * IA_CSS_MACC_NUM_AXES);
j = 4 * i;
params->data[0][(idx)] = from->data[j];
params->data[1][(idx)] = from->data[j + 1];
params->data[2][(idx)] = from->data[j + 2];
params->data[3][(idx)] = from->data[j + 3];
}
}
void
ia_css_macc1_5_debug_dtrace(
const struct ia_css_macc1_5_config *config,
unsigned int level)
{
ia_css_debug_dtrace(level,
"config.exp=%d\n",
config->exp);
}
