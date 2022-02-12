static int sysfs__fprintf_build_id(FILE *fp)
{
u8 kallsyms_build_id[BUILD_ID_SIZE];
char sbuild_id[BUILD_ID_SIZE * 2 + 1];
if (sysfs__read_build_id("/sys/kernel/notes", kallsyms_build_id,
sizeof(kallsyms_build_id)) != 0)
return -1;
build_id__sprintf(kallsyms_build_id, sizeof(kallsyms_build_id),
sbuild_id);
fprintf(fp, "%s\n", sbuild_id);
return 0;
}
static int filename__fprintf_build_id(const char *name, FILE *fp)
{
u8 build_id[BUILD_ID_SIZE];
char sbuild_id[BUILD_ID_SIZE * 2 + 1];
if (filename__read_build_id(name, build_id,
sizeof(build_id)) != sizeof(build_id))
return 0;
build_id__sprintf(build_id, sizeof(build_id), sbuild_id);
return fprintf(fp, "%s\n", sbuild_id);
}
static int perf_session__list_build_ids(void)
{
struct perf_session *session;
elf_version(EV_CURRENT);
session = perf_session__new(input_name, O_RDONLY, force, false,
&build_id__mark_dso_hit_ops);
if (session == NULL)
return -1;
if (filename__fprintf_build_id(session->filename, stdout))
goto out;
if (with_hits)
perf_session__process_events(session, &build_id__mark_dso_hit_ops);
perf_session__fprintf_dsos_buildid(session, stdout, with_hits);
out:
perf_session__delete(session);
return 0;
}
static int __cmd_buildid_list(void)
{
if (show_kernel)
return sysfs__fprintf_build_id(stdout);
return perf_session__list_build_ids();
}
int cmd_buildid_list(int argc, const char **argv, const char *prefix __used)
{
argc = parse_options(argc, argv, options, buildid_list_usage, 0);
setup_pager();
return __cmd_buildid_list();
}
