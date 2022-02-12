static int __cmd_evlist(void)
{
struct perf_session *session;
struct perf_evsel *pos;
session = perf_session__new(input_name, O_RDONLY, 0, false, NULL);
if (session == NULL)
return -ENOMEM;
list_for_each_entry(pos, &session->evlist->entries, node)
printf("%s\n", event_name(pos));
perf_session__delete(session);
return 0;
}
int cmd_evlist(int argc, const char **argv, const char *prefix __used)
{
argc = parse_options(argc, argv, options, evlist_usage, 0);
if (argc)
usage_with_options(evlist_usage, options);
return __cmd_evlist();
}
