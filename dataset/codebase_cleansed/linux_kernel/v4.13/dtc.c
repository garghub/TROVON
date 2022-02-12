static int is_power_of_2(int x)
{
return (x > 0) && ((x & (x - 1)) == 0);
}
static void fill_fullpaths(struct node *tree, const char *prefix)
{
struct node *child;
const char *unit;
tree->fullpath = join_path(prefix, tree->name);
unit = strchr(tree->name, '@');
if (unit)
tree->basenamelen = unit - tree->name;
else
tree->basenamelen = strlen(tree->name);
for_each_child(tree, child)
fill_fullpaths(child, tree->fullpath);
}
static const char *guess_type_by_name(const char *fname, const char *fallback)
{
const char *s;
s = strrchr(fname, '.');
if (s == NULL)
return fallback;
if (!strcasecmp(s, ".dts"))
return "dts";
if (!strcasecmp(s, ".dtb"))
return "dtb";
return fallback;
}
static const char *guess_input_format(const char *fname, const char *fallback)
{
struct stat statbuf;
fdt32_t magic;
FILE *f;
if (stat(fname, &statbuf) != 0)
return fallback;
if (S_ISDIR(statbuf.st_mode))
return "fs";
if (!S_ISREG(statbuf.st_mode))
return fallback;
f = fopen(fname, "r");
if (f == NULL)
return fallback;
if (fread(&magic, 4, 1, f) != 1) {
fclose(f);
return fallback;
}
fclose(f);
if (fdt32_to_cpu(magic) == FDT_MAGIC)
return "dtb";
return guess_type_by_name(fname, fallback);
}
int main(int argc, char *argv[])
{
struct dt_info *dti;
const char *inform = NULL;
const char *outform = NULL;
const char *outname = "-";
const char *depname = NULL;
bool force = false, sort = false;
const char *arg;
int opt;
FILE *outf = NULL;
int outversion = DEFAULT_FDT_VERSION;
long long cmdline_boot_cpuid = -1;
quiet = 0;
reservenum = 0;
minsize = 0;
padsize = 0;
alignsize = 0;
while ((opt = util_getopt_long()) != EOF) {
switch (opt) {
case 'I':
inform = optarg;
break;
case 'O':
outform = optarg;
break;
case 'o':
outname = optarg;
break;
case 'V':
outversion = strtol(optarg, NULL, 0);
break;
case 'd':
depname = optarg;
break;
case 'R':
reservenum = strtol(optarg, NULL, 0);
break;
case 'S':
minsize = strtol(optarg, NULL, 0);
break;
case 'p':
padsize = strtol(optarg, NULL, 0);
break;
case 'a':
alignsize = strtol(optarg, NULL, 0);
if (!is_power_of_2(alignsize))
die("Invalid argument \"%d\" to -a option\n",
alignsize);
break;
case 'f':
force = true;
break;
case 'q':
quiet++;
break;
case 'b':
cmdline_boot_cpuid = strtoll(optarg, NULL, 0);
break;
case 'i':
srcfile_add_search_path(optarg);
break;
case 'v':
util_version();
case 'H':
if (streq(optarg, "legacy"))
phandle_format = PHANDLE_LEGACY;
else if (streq(optarg, "epapr"))
phandle_format = PHANDLE_EPAPR;
else if (streq(optarg, "both"))
phandle_format = PHANDLE_BOTH;
else
die("Invalid argument \"%s\" to -H option\n",
optarg);
break;
case 's':
sort = true;
break;
case 'W':
parse_checks_option(true, false, optarg);
break;
case 'E':
parse_checks_option(false, true, optarg);
break;
case '@':
generate_symbols = 1;
break;
case 'A':
auto_label_aliases = 1;
break;
case 'h':
usage(NULL);
default:
usage("unknown option");
}
}
if (argc > (optind+1))
usage("missing files");
else if (argc < (optind+1))
arg = "-";
else
arg = argv[optind];
if (minsize && padsize)
die("Can't set both -p and -S\n");
if (depname) {
depfile = fopen(depname, "w");
if (!depfile)
die("Couldn't open dependency file %s: %s\n", depname,
strerror(errno));
fprintf(depfile, "%s:", outname);
}
if (inform == NULL)
inform = guess_input_format(arg, "dts");
if (outform == NULL) {
outform = guess_type_by_name(outname, NULL);
if (outform == NULL) {
if (streq(inform, "dts"))
outform = "dtb";
else
outform = "dts";
}
}
if (streq(inform, "dts"))
dti = dt_from_source(arg);
else if (streq(inform, "fs"))
dti = dt_from_fs(arg);
else if(streq(inform, "dtb"))
dti = dt_from_blob(arg);
else
die("Unknown input format \"%s\"\n", inform);
dti->outname = outname;
if (depfile) {
fputc('\n', depfile);
fclose(depfile);
}
if (cmdline_boot_cpuid != -1)
dti->boot_cpuid_phys = cmdline_boot_cpuid;
fill_fullpaths(dti->dt, "");
process_checks(force, dti);
if (dti->dtsflags & DTSF_PLUGIN) {
generate_fixups = 1;
}
if (auto_label_aliases)
generate_label_tree(dti, "aliases", false);
if (generate_symbols)
generate_label_tree(dti, "__symbols__", true);
if (generate_fixups) {
generate_fixups_tree(dti, "__fixups__");
generate_local_fixups_tree(dti, "__local_fixups__");
}
if (sort)
sort_tree(dti);
if (streq(outname, "-")) {
outf = stdout;
} else {
outf = fopen(outname, "wb");
if (! outf)
die("Couldn't open output file %s: %s\n",
outname, strerror(errno));
}
if (streq(outform, "dts")) {
dt_to_source(outf, dti);
} else if (streq(outform, "dtb")) {
dt_to_blob(outf, dti, outversion);
} else if (streq(outform, "asm")) {
dt_to_asm(outf, dti, outversion);
} else if (streq(outform, "null")) {
} else {
die("Unknown output format \"%s\"\n", outform);
}
exit(0);
}
