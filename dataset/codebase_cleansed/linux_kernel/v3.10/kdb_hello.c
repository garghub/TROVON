static int kdb_hello_cmd(int argc, const char **argv)
{
if (argc > 1)
return KDB_ARGCOUNT;
if (argc)
kdb_printf("Hello %s.\n", argv[1]);
else
kdb_printf("Hello world!\n");
return 0;
}
static int __init kdb_hello_cmd_init(void)
{
kdb_register("hello", kdb_hello_cmd, "[string]",
"Say Hello World or Hello [string]", 0);
return 0;
}
static void __exit kdb_hello_cmd_exit(void)
{
kdb_unregister("hello");
}
