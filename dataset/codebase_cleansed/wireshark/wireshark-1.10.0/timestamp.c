ts_type timestamp_get_type(void)
{
return timestamp_type;
}
void timestamp_set_type(ts_type ts_t)
{
timestamp_type = ts_t;
}
int timestamp_get_precision(void)
{
return timestamp_precision;
}
void timestamp_set_precision(int tsp)
{
timestamp_precision = tsp;
}
ts_seconds_type timestamp_get_seconds_type(void)
{
return timestamp_seconds_type;
}
void timestamp_set_seconds_type(ts_seconds_type ts_t)
{
timestamp_seconds_type = ts_t;
}
