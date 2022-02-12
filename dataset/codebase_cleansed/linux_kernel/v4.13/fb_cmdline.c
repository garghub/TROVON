int fb_get_options(const char *name, char **option)
{
char *opt, *options = NULL;
int retval = 0;
int name_len = strlen(name), i;
if (name_len && ofonly && strncmp(name, "offb", 4))
retval = 1;
if (name_len && !retval) {
for (i = 0; i < FB_MAX; i++) {
if (video_options[i] == NULL)
continue;
if (!video_options[i][0])
continue;
opt = video_options[i];
if (!strncmp(name, opt, name_len) &&
opt[name_len] == ':')
options = opt + name_len + 1;
}
}
if (!options && option && fb_mode_option)
options = kstrdup(fb_mode_option, GFP_KERNEL);
if (options && !strncmp(options, "off", 3))
retval = 1;
if (option)
*option = options;
return retval;
}
static int __init video_setup(char *options)
{
int i, global = 0;
if (!options || !*options)
global = 1;
if (!global && !strncmp(options, "ofonly", 6)) {
ofonly = 1;
global = 1;
}
if (!global && !strchr(options, ':')) {
fb_mode_option = options;
global = 1;
}
if (!global) {
for (i = 0; i < FB_MAX; i++) {
if (video_options[i] == NULL) {
video_options[i] = options;
break;
}
}
}
return 1;
}
