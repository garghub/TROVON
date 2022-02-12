void __init irda_proc_register(void)
{
int i;
proc_irda = proc_mkdir("irda", init_net.proc_net);
if (proc_irda == NULL)
return;
for (i = 0; i < ARRAY_SIZE(irda_dirs); i++)
(void) proc_create(irda_dirs[i].name, 0, proc_irda,
irda_dirs[i].fops);
}
void irda_proc_unregister(void)
{
int i;
if (proc_irda) {
for (i=0; i<ARRAY_SIZE(irda_dirs); i++)
remove_proc_entry(irda_dirs[i].name, proc_irda);
remove_proc_entry("irda", init_net.proc_net);
proc_irda = NULL;
}
}
