int cmd_orc(int argc, const char **argv)
{
const char *objname;
argc--; argv++;
if (!strncmp(argv[0], "gen", 3)) {
argc = parse_options(argc, argv, check_options, orc_usage, 0);
if (argc != 1)
usage_with_options(orc_usage, check_options);
objname = argv[0];
return check(objname, no_fp, no_unreachable, true);
}
if (!strcmp(argv[0], "dump")) {
if (argc != 2)
usage_with_options(orc_usage, check_options);
objname = argv[1];
return orc_dump(objname);
}
usage_with_options(orc_usage, check_options);
return 0;
}
