void
ia_css_conversion_encode(
struct sh_css_isp_conversion_params *to,
const struct ia_css_conversion_config *from,
unsigned size)
{
(void)size;
to->en = from->en;
to->dummy0 = from->dummy0;
to->dummy1 = from->dummy1;
to->dummy2 = from->dummy2;
}
