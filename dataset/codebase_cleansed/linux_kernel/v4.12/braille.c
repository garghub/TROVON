int _braille_console_setup(char **str, char **brl_options)
{
if (!strncmp(*str, "brl,", 4)) {
*brl_options = "";
*str += 4;
} else if (!strncmp(*str, "brl=", 4)) {
*brl_options = *str + 4;
*str = strchr(*brl_options, ',');
if (!*str) {
pr_err("need port name after brl=\n");
return -EINVAL;
}
*((*str)++) = 0;
}
return 0;
}
int
_braille_register_console(struct console *console, struct console_cmdline *c)
{
int rtn = 0;
if (c->brl_options) {
console->flags |= CON_BRL;
rtn = braille_register_console(console, c->index, c->options,
c->brl_options);
}
return rtn;
}
int
_braille_unregister_console(struct console *console)
{
if (console->flags & CON_BRL)
return braille_unregister_console(console);
return 0;
}
