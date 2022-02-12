static int __cmd_buildid_list(void)
{
struct perf_session *session;
session = perf_session__new(input_name, O_RDONLY, force, false,
&build_id__mark_dso_hit_ops);
if (session == NULL)
return -1;
if (with_hits)
perf_session__process_events(session, &build_id__mark_dso_hit_ops);
perf_session__fprintf_dsos_buildid(session, stdout, with_hits);
perf_session__delete(session);
return 0;
}
int cmd_buildid_list(int argc, const char **argv, const char *prefix __used)
{
argc = parse_options(argc, argv, options, buildid_list_usage, 0);
setup_pager();
return __cmd_buildid_list();
}
