int cmd_check(int argc, const char **argv)
{
const char *objname;
argc = parse_options(argc, argv, check_options, check_usage, 0);
if (argc != 1)
usage_with_options(check_usage, check_options);
objname = argv[0];
return check(objname, no_fp, no_unreachable, false);
}
