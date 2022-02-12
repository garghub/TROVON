void
ia_css_get_properties(struct ia_css_properties *properties)
{
assert(properties != NULL);
#if defined(HAS_GDC_VERSION_2) || defined(HAS_GDC_VERSION_3)
properties->gdc_coord_one = gdc_get_unity(GDC0_ID)/HRT_GDC_COORD_SCALE;
#else
#error "Unknown GDC version"
#endif
properties->l1_base_is_index = true;
#if defined(HAS_VAMEM_VERSION_1)
properties->vamem_type = IA_CSS_VAMEM_TYPE_1;
#elif defined(HAS_VAMEM_VERSION_2)
properties->vamem_type = IA_CSS_VAMEM_TYPE_2;
#else
#error "Unknown VAMEM version"
#endif
}
