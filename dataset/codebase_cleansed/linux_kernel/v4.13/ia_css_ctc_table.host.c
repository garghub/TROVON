void
ia_css_config_ctc_table(void)
{
#if defined(HAS_VAMEM_VERSION_2)
memcpy(default_ctc_table.data.vamem_2, default_ctc_table_data,
sizeof(default_ctc_table_data));
default_ctc_table.vamem_type = IA_CSS_VAMEM_TYPE_2;
#else
memcpy(default_ctc_table.data.vamem_1, default_ctc_table_data,
sizeof(default_ctc_table_data));
default_ctc_table.vamem_type = 1IA_CSS_VAMEM_TYPE_1;
#endif
}
