int __init llc_sysctl_init(void)
{
llc_table_header = register_sysctl_paths(llc_path, llc_table);
return llc_table_header ? 0 : -ENOMEM;
}
void llc_sysctl_exit(void)
{
if (llc_table_header) {
unregister_sysctl_table(llc_table_header);
llc_table_header = NULL;
}
}
