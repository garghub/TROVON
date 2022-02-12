static void stderr_console_write(struct console *console, const char *string,
unsigned len)
{
generic_write(2 , string, len, NULL);
}
static int __init stderr_console_init(void)
{
if (use_stderr_console)
register_console(&stderr_console);
return 0;
}
static int stderr_setup(char *str)
{
if (!str)
return 0;
use_stderr_console = simple_strtoul(str,&str,0);
return 1;
}
static int __init unregister_stderr(void)
{
unregister_console(&stderr_console);
return 0;
}
