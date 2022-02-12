gdouble ppi_fixed3_7_to_gdouble(guint32 in) {
gint32 remapped_in = in - (180 * 10000000);
gdouble ret = (gdouble) ((gdouble) remapped_in / 10000000);
return ret;
}
gdouble ppi_fixed3_6_to_gdouble(guint32 in) {
gdouble ret = (gdouble) in / 1000000.0;
return ret;
}
gdouble ppi_fixed6_4_to_gdouble(guint32 in) {
gint32 remapped_in = in - (180000 * 10000);
gdouble ret = (gdouble) ((gdouble) remapped_in / 10000);
return ret;
}
gdouble ppi_ns_counter_to_gdouble(guint32 in) {
gdouble ret;
ret = (gdouble) in / 1000000000;
return ret;
}
