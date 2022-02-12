static void usage(char *name)
{
printf("usage: %s [-m] policy_file context_file\n", name);
exit(1);
}
int main(int argc, char *argv[])
{
int i, j, mls = 0;
int initial_sid_to_string_len;
char **arg, *polout, *ctxout;
FILE *fout;
if (argc < 3)
usage(argv[0]);
arg = argv+1;
if (argc==4 && strcmp(argv[1], "-m") == 0) {
mls = 1;
arg++;
}
polout = *arg++;
ctxout = *arg;
fout = fopen(polout, "w");
if (!fout) {
printf("Could not open %s for writing\n", polout);
usage(argv[0]);
}
for (i = 0; secclass_map[i].name; i++)
fprintf(fout, "class %s\n", secclass_map[i].name);
fprintf(fout, "\n");
initial_sid_to_string_len = sizeof(initial_sid_to_string) / sizeof (char *);
for (i = 1; i < initial_sid_to_string_len; i++)
fprintf(fout, "sid %s\n", initial_sid_to_string[i]);
fprintf(fout, "\n");
for (i = 0; secclass_map[i].name; i++) {
struct security_class_mapping *map = &secclass_map[i];
fprintf(fout, "class %s\n", map->name);
fprintf(fout, "{\n");
for (j = 0; map->perms[j]; j++)
fprintf(fout, "\t%s\n", map->perms[j]);
fprintf(fout, "}\n\n");
}
fprintf(fout, "\n");
if (mls) {
printf("MLS not yet implemented\n");
exit(1);
}
fprintf(fout, "type base_t;\n");
fprintf(fout, "role base_r;\n");
fprintf(fout, "role base_r types { base_t };\n");
for (i = 0; secclass_map[i].name; i++)
fprintf(fout, "allow base_t base_t:%s *;\n",
secclass_map[i].name);
fprintf(fout, "user user_u roles { base_r };\n");
fprintf(fout, "\n");
for (i = 1; i < initial_sid_to_string_len; i++)
fprintf(fout, "sid %s user_u:base_r:base_t\n", initial_sid_to_string[i]);
fprintf(fout, "\n");
fprintf(fout, "fs_use_xattr ext2 user_u:base_r:base_t;\n");
fprintf(fout, "fs_use_xattr ext3 user_u:base_r:base_t;\n");
fprintf(fout, "fs_use_xattr ext4 user_u:base_r:base_t;\n");
fprintf(fout, "fs_use_xattr jfs user_u:base_r:base_t;\n");
fprintf(fout, "fs_use_xattr xfs user_u:base_r:base_t;\n");
fprintf(fout, "fs_use_xattr reiserfs user_u:base_r:base_t;\n");
fprintf(fout, "fs_use_xattr jffs2 user_u:base_r:base_t;\n");
fprintf(fout, "fs_use_xattr gfs2 user_u:base_r:base_t;\n");
fprintf(fout, "fs_use_xattr lustre user_u:base_r:base_t;\n");
fprintf(fout, "fs_use_task eventpollfs user_u:base_r:base_t;\n");
fprintf(fout, "fs_use_task pipefs user_u:base_r:base_t;\n");
fprintf(fout, "fs_use_task sockfs user_u:base_r:base_t;\n");
fprintf(fout, "fs_use_trans mqueue user_u:base_r:base_t;\n");
fprintf(fout, "fs_use_trans devpts user_u:base_r:base_t;\n");
fprintf(fout, "fs_use_trans hugetlbfs user_u:base_r:base_t;\n");
fprintf(fout, "fs_use_trans tmpfs user_u:base_r:base_t;\n");
fprintf(fout, "fs_use_trans shm user_u:base_r:base_t;\n");
fprintf(fout, "genfscon proc / user_u:base_r:base_t\n");
fclose(fout);
fout = fopen(ctxout, "w");
if (!fout) {
printf("Wrote policy, but cannot open %s for writing\n", ctxout);
usage(argv[0]);
}
fprintf(fout, "/ user_u:base_r:base_t\n");
fprintf(fout, "/.* user_u:base_r:base_t\n");
fclose(fout);
return 0;
}
