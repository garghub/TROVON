void __init board_setup(void)
{
unsigned long configpr;
configpr = read_c0_config7();
configpr |= (1<<19);
write_c0_config7(configpr);
}
