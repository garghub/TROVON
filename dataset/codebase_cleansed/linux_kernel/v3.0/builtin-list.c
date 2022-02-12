int cmd_list(int argc, const char **argv, const char *prefix __used)
{
setup_pager();
if (argc == 1)
print_events(NULL);
else {
int i;
for (i = 1; i < argc; ++i) {
if (i > 1)
putchar('\n');
if (strncmp(argv[i], "tracepoint", 10) == 0)
print_tracepoint_events(NULL, NULL);
else if (strcmp(argv[i], "hw") == 0 ||
strcmp(argv[i], "hardware") == 0)
print_events_type(PERF_TYPE_HARDWARE);
else if (strcmp(argv[i], "sw") == 0 ||
strcmp(argv[i], "software") == 0)
print_events_type(PERF_TYPE_SOFTWARE);
else if (strcmp(argv[i], "cache") == 0 ||
strcmp(argv[i], "hwcache") == 0)
print_hwcache_events(NULL);
else {
char *sep = strchr(argv[i], ':'), *s;
int sep_idx;
if (sep == NULL) {
print_events(argv[i]);
continue;
}
sep_idx = sep - argv[i];
s = strdup(argv[i]);
if (s == NULL)
return -1;
s[sep_idx] = '\0';
print_tracepoint_events(s, s + sep_idx + 1);
free(s);
}
}
}
return 0;
}
