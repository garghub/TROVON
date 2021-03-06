static int build_id_cache__add_file(const char *filename, const char *debugdir)\r\n{\r\nchar sbuild_id[BUILD_ID_SIZE * 2 + 1];\r\nu8 build_id[BUILD_ID_SIZE];\r\nint err;\r\nif (filename__read_build_id(filename, &build_id, sizeof(build_id)) < 0) {\r\npr_debug("Couldn't read a build-id in %s\n", filename);\r\nreturn -1;\r\n}\r\nbuild_id__sprintf(build_id, sizeof(build_id), sbuild_id);\r\nerr = build_id_cache__add_s(sbuild_id, debugdir, filename,\r\nfalse, false);\r\nif (verbose)\r\npr_info("Adding %s %s: %s\n", sbuild_id, filename,\r\nerr ? "FAIL" : "Ok");\r\nreturn err;\r\n}\r\nstatic int build_id_cache__remove_file(const char *filename,\r\nconst char *debugdir)\r\n{\r\nu8 build_id[BUILD_ID_SIZE];\r\nchar sbuild_id[BUILD_ID_SIZE * 2 + 1];\r\nint err;\r\nif (filename__read_build_id(filename, &build_id, sizeof(build_id)) < 0) {\r\npr_debug("Couldn't read a build-id in %s\n", filename);\r\nreturn -1;\r\n}\r\nbuild_id__sprintf(build_id, sizeof(build_id), sbuild_id);\r\nerr = build_id_cache__remove_s(sbuild_id, debugdir);\r\nif (verbose)\r\npr_info("Removing %s %s: %s\n", sbuild_id, filename,\r\nerr ? "FAIL" : "Ok");\r\nreturn err;\r\n}\r\nstatic bool dso__missing_buildid_cache(struct dso *dso, int parm __maybe_unused)\r\n{\r\nchar filename[PATH_MAX];\r\nu8 build_id[BUILD_ID_SIZE];\r\nif (dso__build_id_filename(dso, filename, sizeof(filename)) &&\r\nfilename__read_build_id(filename, build_id,\r\nsizeof(build_id)) != sizeof(build_id)) {\r\nif (errno == ENOENT)\r\nreturn false;\r\npr_warning("Problems with %s file, consider removing it from the cache\n",\r\nfilename);\r\n} else if (memcmp(dso->build_id, build_id, sizeof(dso->build_id))) {\r\npr_warning("Problems with %s file, consider removing it from the cache\n",\r\nfilename);\r\n}\r\nreturn true;\r\n}\r\nstatic int build_id_cache__fprintf_missing(const char *filename, bool force, FILE *fp)\r\n{\r\nstruct perf_session *session = perf_session__new(filename, O_RDONLY,\r\nforce, false, NULL);\r\nif (session == NULL)\r\nreturn -1;\r\nperf_session__fprintf_dsos_buildid(session, fp, dso__missing_buildid_cache, 0);\r\nperf_session__delete(session);\r\nreturn 0;\r\n}\r\nstatic int build_id_cache__update_file(const char *filename,\r\nconst char *debugdir)\r\n{\r\nu8 build_id[BUILD_ID_SIZE];\r\nchar sbuild_id[BUILD_ID_SIZE * 2 + 1];\r\nint err;\r\nif (filename__read_build_id(filename, &build_id, sizeof(build_id)) < 0) {\r\npr_debug("Couldn't read a build-id in %s\n", filename);\r\nreturn -1;\r\n}\r\nbuild_id__sprintf(build_id, sizeof(build_id), sbuild_id);\r\nerr = build_id_cache__remove_s(sbuild_id, debugdir);\r\nif (!err) {\r\nerr = build_id_cache__add_s(sbuild_id, debugdir, filename,\r\nfalse, false);\r\n}\r\nif (verbose)\r\npr_info("Updating %s %s: %s\n", sbuild_id, filename,\r\nerr ? "FAIL" : "Ok");\r\nreturn err;\r\n}\r\nint cmd_buildid_cache(int argc, const char **argv,\r\nconst char *prefix __maybe_unused)\r\n{\r\nstruct strlist *list;\r\nstruct str_node *pos;\r\nint ret = 0;\r\nbool force = false;\r\nchar debugdir[PATH_MAX];\r\nchar const *add_name_list_str = NULL,\r\n*remove_name_list_str = NULL,\r\n*missing_filename = NULL,\r\n*update_name_list_str = NULL;\r\nconst struct option buildid_cache_options[] = {\r\nOPT_STRING('a', "add", &add_name_list_str,\r\n"file list", "file(s) to add"),\r\nOPT_STRING('r', "remove", &remove_name_list_str, "file list",\r\n"file(s) to remove"),\r\nOPT_STRING('M', "missing", &missing_filename, "file",\r\n"to find missing build ids in the cache"),\r\nOPT_BOOLEAN('f', "force", &force, "don't complain, do it"),\r\nOPT_STRING('u', "update", &update_name_list_str, "file list",\r\n"file(s) to update"),\r\nOPT_INCR('v', "verbose", &verbose, "be more verbose"),\r\nOPT_END()\r\n};\r\nconst char * const buildid_cache_usage[] = {\r\n"perf buildid-cache [<options>]",\r\nNULL\r\n};\r\nargc = parse_options(argc, argv, buildid_cache_options,\r\nbuildid_cache_usage, 0);\r\nif (symbol__init() < 0)\r\nreturn -1;\r\nsetup_pager();\r\nsnprintf(debugdir, sizeof(debugdir), "%s", buildid_dir);\r\nif (add_name_list_str) {\r\nlist = strlist__new(true, add_name_list_str);\r\nif (list) {\r\nstrlist__for_each(pos, list)\r\nif (build_id_cache__add_file(pos->s, debugdir)) {\r\nif (errno == EEXIST) {\r\npr_debug("%s already in the cache\n",\r\npos->s);\r\ncontinue;\r\n}\r\npr_warning("Couldn't add %s: %s\n",\r\npos->s, strerror(errno));\r\n}\r\nstrlist__delete(list);\r\n}\r\n}\r\nif (remove_name_list_str) {\r\nlist = strlist__new(true, remove_name_list_str);\r\nif (list) {\r\nstrlist__for_each(pos, list)\r\nif (build_id_cache__remove_file(pos->s, debugdir)) {\r\nif (errno == ENOENT) {\r\npr_debug("%s wasn't in the cache\n",\r\npos->s);\r\ncontinue;\r\n}\r\npr_warning("Couldn't remove %s: %s\n",\r\npos->s, strerror(errno));\r\n}\r\nstrlist__delete(list);\r\n}\r\n}\r\nif (missing_filename)\r\nret = build_id_cache__fprintf_missing(missing_filename, force, stdout);\r\nif (update_name_list_str) {\r\nlist = strlist__new(true, update_name_list_str);\r\nif (list) {\r\nstrlist__for_each(pos, list)\r\nif (build_id_cache__update_file(pos->s, debugdir)) {\r\nif (errno == ENOENT) {\r\npr_debug("%s wasn't in the cache\n",\r\npos->s);\r\ncontinue;\r\n}\r\npr_warning("Couldn't update %s: %s\n",\r\npos->s, strerror(errno));\r\n}\r\nstrlist__delete(list);\r\n}\r\n}\r\nreturn ret;\r\n}
