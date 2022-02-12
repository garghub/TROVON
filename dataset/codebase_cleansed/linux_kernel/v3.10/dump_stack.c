void dump_stack(void)
{
dump_stack_print_info(KERN_DEFAULT);
show_stack(NULL, NULL);
}
