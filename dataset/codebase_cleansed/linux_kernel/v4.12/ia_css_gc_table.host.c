void
ia_css_config_gamma_table(void)
{
#if defined(HAS_VAMEM_VERSION_2)
memcpy(default_gamma_table.data.vamem_2, default_gamma_table_data,
sizeof(default_gamma_table_data));
default_gamma_table.vamem_type = IA_CSS_VAMEM_TYPE_2;
#else
memcpy(default_gamma_table.data.vamem_1, default_gamma_table_data,
sizeof(default_gamma_table_data));
default_gamma_table.vamem_type = IA_CSS_VAMEM_TYPE_1;
#endif
}
