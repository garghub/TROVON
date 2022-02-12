static struct node *read_fstree(const char *dirname)
{
DIR *d;
struct dirent *de;
struct stat st;
struct node *tree;
d = opendir(dirname);
if (!d)
die("Couldn't opendir() \"%s\": %s\n", dirname, strerror(errno));
tree = build_node(NULL, NULL);
while ((de = readdir(d)) != NULL) {
char *tmpnam;
if (streq(de->d_name, ".")
|| streq(de->d_name, ".."))
continue;
tmpnam = join_path(dirname, de->d_name);
if (lstat(tmpnam, &st) < 0)
die("stat(%s): %s\n", tmpnam, strerror(errno));
if (S_ISREG(st.st_mode)) {
struct property *prop;
FILE *pfile;
pfile = fopen(tmpnam, "r");
if (! pfile) {
fprintf(stderr,
"WARNING: Cannot open %s: %s\n",
tmpnam, strerror(errno));
} else {
prop = build_property(xstrdup(de->d_name),
data_copy_file(pfile,
st.st_size));
add_property(tree, prop);
fclose(pfile);
}
} else if (S_ISDIR(st.st_mode)) {
struct node *newchild;
newchild = read_fstree(tmpnam);
newchild = name_node(newchild, xstrdup(de->d_name));
add_child(tree, newchild);
}
free(tmpnam);
}
closedir(d);
return tree;
}
struct boot_info *dt_from_fs(const char *dirname)
{
struct node *tree;
tree = read_fstree(dirname);
tree = name_node(tree, "");
return build_boot_info(NULL, tree, guess_boot_cpuid(tree));
}
