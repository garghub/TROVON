void init_report_err(void (*report_failure_fcn_p)(const char *, va_list),
void (*report_open_failure_fcn_p)(const char *, int, gboolean),
void (*report_read_failure_fcn_p)(const char *, int),
void (*report_write_failure_fcn_p)(const char *, int))
{
report_failure_func = report_failure_fcn_p;
report_open_failure_func = report_open_failure_fcn_p;
report_read_failure_func = report_read_failure_fcn_p;
report_write_failure_func = report_write_failure_fcn_p;
}
void
report_failure(const char *msg_format, ...)
{
va_list ap;
va_start(ap, msg_format);
(*report_failure_func)(msg_format, ap);
va_end(ap);
}
void
report_open_failure(const char *filename, int err,
gboolean for_writing)
{
(*report_open_failure_func)(filename, err, for_writing);
}
void
report_read_failure(const char *filename, int err)
{
(*report_read_failure_func)(filename, err);
}
void
report_write_failure(const char *filename, int err)
{
(*report_write_failure_func)(filename, err);
}
