static void report_error(const char *where, int err)
{
fprintf(stderr, "Error at '%s': %s\n", where, fdt_strerror(err));
}
static int show_data(struct display_info *disp, const char *data, int len)
{
int i, size;
const uint8_t *p = (const uint8_t *)data;
const char *s;
int value;
int is_string;
char fmt[3];
if (len == 0)
return 0;
is_string = (disp->type) == 's' ||
(!disp->type && util_is_printable_string(data, len));
if (is_string) {
if (data[len - 1] != '\0') {
fprintf(stderr, "Unterminated string\n");
return -1;
}
for (s = data; s - data < len; s += strlen(s) + 1) {
if (s != data)
printf(" ");
printf("%s", (const char *)s);
}
return 0;
}
size = disp->size;
if (size == -1) {
size = (len % 4) == 0 ? 4 : 1;
} else if (len % size) {
fprintf(stderr, "Property length must be a multiple of "
"selected data size\n");
return -1;
}
fmt[0] = '%';
fmt[1] = disp->type ? disp->type : 'd';
fmt[2] = '\0';
for (i = 0; i < len; i += size, p += size) {
if (i)
printf(" ");
value = size == 4 ? fdt32_to_cpu(*(const uint32_t *)p) :
size == 2 ? (*p << 8) | p[1] : *p;
printf(fmt, value);
}
return 0;
}
static int list_properties(const void *blob, int node)
{
const struct fdt_property *data;
const char *name;
int prop;
prop = fdt_first_property_offset(blob, node);
do {
if (prop < 0)
return prop == -FDT_ERR_NOTFOUND ? 0 : prop;
data = fdt_get_property_by_offset(blob, prop, NULL);
name = fdt_string(blob, fdt32_to_cpu(data->nameoff));
if (name)
puts(name);
prop = fdt_next_property_offset(blob, prop);
} while (1);
}
static int list_subnodes(const void *blob, int node)
{
int nextoffset;
uint32_t tag;
int level = 0;
const char *pathp;
int depth = 1;
while (level >= 0) {
tag = fdt_next_tag(blob, node, &nextoffset);
switch (tag) {
case FDT_BEGIN_NODE:
pathp = fdt_get_name(blob, node, NULL);
if (level <= depth) {
if (pathp == NULL)
pathp = "/* NULL pointer error */";
if (*pathp == '\0')
pathp = "/";
if (level == 1)
puts(pathp);
}
level++;
if (level >= MAX_LEVEL) {
printf("Nested too deep, aborting.\n");
return 1;
}
break;
case FDT_END_NODE:
level--;
if (level == 0)
level = -1;
break;
case FDT_END:
return 1;
case FDT_PROP:
break;
default:
if (level <= depth)
printf("Unknown tag 0x%08X\n", tag);
return 1;
}
node = nextoffset;
}
return 0;
}
static int show_data_for_item(const void *blob, struct display_info *disp,
int node, const char *property)
{
const void *value = NULL;
int len, err = 0;
switch (disp->mode) {
case MODE_LIST_PROPS:
err = list_properties(blob, node);
break;
case MODE_LIST_SUBNODES:
err = list_subnodes(blob, node);
break;
default:
assert(property);
value = fdt_getprop(blob, node, property, &len);
if (value) {
if (show_data(disp, value, len))
err = -1;
else
printf("\n");
} else if (disp->default_val) {
puts(disp->default_val);
} else {
report_error(property, len);
err = -1;
}
break;
}
return err;
}
static int do_fdtget(struct display_info *disp, const char *filename,
char **arg, int arg_count, int args_per_step)
{
char *blob;
const char *prop;
int i, node;
blob = utilfdt_read(filename);
if (!blob)
return -1;
for (i = 0; i + args_per_step <= arg_count; i += args_per_step) {
node = fdt_path_offset(blob, arg[i]);
if (node < 0) {
if (disp->default_val) {
puts(disp->default_val);
continue;
} else {
report_error(arg[i], node);
return -1;
}
}
prop = args_per_step == 1 ? NULL : arg[i + 1];
if (show_data_for_item(blob, disp, node, prop))
return -1;
}
return 0;
}
static void usage(const char *msg)
{
if (msg)
fprintf(stderr, "Error: %s\n\n", msg);
fprintf(stderr, "%s", usage_msg);
exit(2);
}
int main(int argc, char *argv[])
{
char *filename = NULL;
struct display_info disp;
int args_per_step = 2;
memset(&disp, '\0', sizeof(disp));
disp.size = -1;
disp.mode = MODE_SHOW_VALUE;
for (;;) {
int c = getopt(argc, argv, "d:hlpt:");
if (c == -1)
break;
switch (c) {
case 'h':
case '?':
usage(NULL);
case 't':
if (utilfdt_decode_type(optarg, &disp.type,
&disp.size))
usage("Invalid type string");
break;
case 'p':
disp.mode = MODE_LIST_PROPS;
args_per_step = 1;
break;
case 'l':
disp.mode = MODE_LIST_SUBNODES;
args_per_step = 1;
break;
case 'd':
disp.default_val = optarg;
break;
}
}
if (optind < argc)
filename = argv[optind++];
if (!filename)
usage("Missing filename");
argv += optind;
argc -= optind;
if (!argc)
return 0;
if (args_per_step == 2 && (argc % 2))
usage("Must have an even number of arguments");
if (do_fdtget(&disp, filename, argv, argc, args_per_step))
return 1;
return 0;
}
