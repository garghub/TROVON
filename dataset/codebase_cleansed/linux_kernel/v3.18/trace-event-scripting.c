static int flush_script_unsupported(void)
{
return 0;
}
static int stop_script_unsupported(void)
{
return 0;
}
static void process_event_unsupported(union perf_event *event __maybe_unused,
struct perf_sample *sample __maybe_unused,
struct perf_evsel *evsel __maybe_unused,
struct thread *thread __maybe_unused,
struct addr_location *al __maybe_unused)
{
}
static void print_python_unsupported_msg(void)
{
fprintf(stderr, "Python scripting not supported."
" Install libpython and rebuild perf to enable it.\n"
"For example:\n # apt-get install python-dev (ubuntu)"
"\n # yum install python-devel (Fedora)"
"\n etc.\n");
}
static int python_start_script_unsupported(const char *script __maybe_unused,
int argc __maybe_unused,
const char **argv __maybe_unused)
{
print_python_unsupported_msg();
return -1;
}
static int python_generate_script_unsupported(struct pevent *pevent
__maybe_unused,
const char *outfile
__maybe_unused)
{
print_python_unsupported_msg();
return -1;
}
static void register_python_scripting(struct scripting_ops *scripting_ops)
{
int err;
err = script_spec_register("Python", scripting_ops);
if (err)
die("error registering Python script extension");
err = script_spec_register("py", scripting_ops);
if (err)
die("error registering py script extension");
scripting_context = malloc(sizeof(struct scripting_context));
}
void setup_python_scripting(void)
{
register_python_scripting(&python_scripting_unsupported_ops);
}
void setup_python_scripting(void)
{
register_python_scripting(&python_scripting_ops);
}
static void print_perl_unsupported_msg(void)
{
fprintf(stderr, "Perl scripting not supported."
" Install libperl and rebuild perf to enable it.\n"
"For example:\n # apt-get install libperl-dev (ubuntu)"
"\n # yum install 'perl(ExtUtils::Embed)' (Fedora)"
"\n etc.\n");
}
static int perl_start_script_unsupported(const char *script __maybe_unused,
int argc __maybe_unused,
const char **argv __maybe_unused)
{
print_perl_unsupported_msg();
return -1;
}
static int perl_generate_script_unsupported(struct pevent *pevent
__maybe_unused,
const char *outfile __maybe_unused)
{
print_perl_unsupported_msg();
return -1;
}
static void register_perl_scripting(struct scripting_ops *scripting_ops)
{
int err;
err = script_spec_register("Perl", scripting_ops);
if (err)
die("error registering Perl script extension");
err = script_spec_register("pl", scripting_ops);
if (err)
die("error registering pl script extension");
scripting_context = malloc(sizeof(struct scripting_context));
}
void setup_perl_scripting(void)
{
register_perl_scripting(&perl_scripting_unsupported_ops);
}
void setup_perl_scripting(void)
{
register_perl_scripting(&perl_scripting_ops);
}
