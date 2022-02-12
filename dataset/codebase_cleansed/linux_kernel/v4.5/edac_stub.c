static int __init edac_report_setup(char *str)
{
if (!str)
return -EINVAL;
if (!strncmp(str, "on", 2))
set_edac_report_status(EDAC_REPORTING_ENABLED);
else if (!strncmp(str, "off", 3))
set_edac_report_status(EDAC_REPORTING_DISABLED);
else if (!strncmp(str, "force", 5))
set_edac_report_status(EDAC_REPORTING_FORCE);
return 0;
}
int edac_handler_set(void)
{
if (edac_op_state == EDAC_OPSTATE_POLL)
return 0;
return atomic_read(&edac_handlers);
}
void edac_atomic_assert_error(void)
{
edac_err_assert++;
}
