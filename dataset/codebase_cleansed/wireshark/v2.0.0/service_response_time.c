extern const char*
service_response_time_get_column_name (int idx)
{
static const char *default_titles[] = { "Index", "Procedure", "Calls", "Min SRT (s)", "Max SRT (s)", "Avg SRT (s)", "Sum SRT (s)" };
if (idx < 0 || idx >= NUM_SRT_COLUMNS) return "(Unknown)";
return default_titles[idx];
}
