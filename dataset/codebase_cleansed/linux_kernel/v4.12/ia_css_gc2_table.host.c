void
ia_css_config_rgb_gamma_tables(void)
{
#if defined(HAS_VAMEM_VERSION_2)
default_r_gamma_table.vamem_type = IA_CSS_VAMEM_TYPE_2;
default_g_gamma_table.vamem_type = IA_CSS_VAMEM_TYPE_2;
default_b_gamma_table.vamem_type = IA_CSS_VAMEM_TYPE_2;
memcpy(default_r_gamma_table.data.vamem_2, default_gamma_table_data,
sizeof(default_gamma_table_data));
memcpy(default_g_gamma_table.data.vamem_2, default_gamma_table_data,
sizeof(default_gamma_table_data));
memcpy(default_b_gamma_table.data.vamem_2, default_gamma_table_data,
sizeof(default_gamma_table_data));
#else
memcpy(default_r_gamma_table.data.vamem_1, default_gamma_table_data,
sizeof(default_gamma_table_data));
memcpy(default_g_gamma_table.data.vamem_1, default_gamma_table_data,
sizeof(default_gamma_table_data));
memcpy(default_b_gamma_table.data.vamem_1, default_gamma_table_data,
sizeof(default_gamma_table_data));
default_r_gamma_table.vamem_type = IA_CSS_VAMEM_TYPE_1;
default_g_gamma_table.vamem_type = IA_CSS_VAMEM_TYPE_1;
default_b_gamma_table.vamem_type = IA_CSS_VAMEM_TYPE_1;
#endif
}
