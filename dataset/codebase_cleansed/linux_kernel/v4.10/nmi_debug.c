static int nmi_debug_notify(struct notifier_block *self,
unsigned long val, void *data)
{
struct die_args *args = data;
if (likely(val != DIE_NMI))
return NOTIFY_DONE;
if (nmi_actions & NMI_SHOW_STATE)
show_state();
if (nmi_actions & NMI_SHOW_REGS)
show_regs(args->regs);
if (nmi_actions & NMI_DEBOUNCE)
mdelay(10);
if (nmi_actions & NMI_DIE)
return NOTIFY_BAD;
return NOTIFY_OK;
}
static int __init nmi_debug_setup(char *str)
{
char *p, *sep;
register_die_notifier(&nmi_debug_nb);
if (nmi_enable()) {
printk(KERN_WARNING "Unable to enable NMI.\n");
return 0;
}
if (*str != '=')
return 0;
for (p = str + 1; *p; p = sep + 1) {
sep = strchr(p, ',');
if (sep)
*sep = 0;
if (strcmp(p, "state") == 0)
nmi_actions |= NMI_SHOW_STATE;
else if (strcmp(p, "regs") == 0)
nmi_actions |= NMI_SHOW_REGS;
else if (strcmp(p, "debounce") == 0)
nmi_actions |= NMI_DEBOUNCE;
else if (strcmp(p, "die") == 0)
nmi_actions |= NMI_DIE;
else
printk(KERN_WARNING "NMI: Unrecognized action `%s'\n",
p);
if (!sep)
break;
}
return 0;
}
