static void set_config_filename(const char *config_filename)
{
static char menu_backtitle[PATH_MAX+128];
int size;
size = snprintf(menu_backtitle, sizeof(menu_backtitle),
"%s - %s", config_filename, rootmenu.prompt->text);
if (size >= sizeof(menu_backtitle))
menu_backtitle[sizeof(menu_backtitle)-1] = '\0';
set_dialog_backtitle(menu_backtitle);
size = snprintf(filename, sizeof(filename), "%s", config_filename);
if (size >= sizeof(filename))
filename[sizeof(filename)-1] = '\0';
}
static void set_subtitle(void)
{
struct subtitle_part *sp;
struct subtitle_list *pos, *tmp;
for (pos = subtitles; pos != NULL; pos = tmp) {
tmp = pos->next;
free(pos);
}
subtitles = NULL;
list_for_each_entry(sp, &trail, entries) {
if (sp->text) {
if (pos) {
pos->next = xcalloc(1, sizeof(*pos));
pos = pos->next;
} else {
subtitles = pos = xcalloc(1, sizeof(*pos));
}
pos->text = sp->text;
}
}
set_dialog_subtitles(subtitles);
}
static void reset_subtitle(void)
{
struct subtitle_list *pos, *tmp;
for (pos = subtitles; pos != NULL; pos = tmp) {
tmp = pos->next;
free(pos);
}
subtitles = NULL;
set_dialog_subtitles(subtitles);
}
static void update_text(char *buf, size_t start, size_t end, void *_data)
{
struct search_data *data = _data;
struct jump_key *pos;
int k = 0;
list_for_each_entry(pos, data->head, entries) {
if (pos->offset >= start && pos->offset < end) {
char header[4];
if (k < JUMP_NB) {
int key = '0' + (pos->index % JUMP_NB) + 1;
sprintf(header, "(%c)", key);
data->keys[k] = key;
data->targets[k] = pos->target;
k++;
} else {
sprintf(header, " ");
}
memcpy(buf + pos->offset, header, sizeof(header) - 1);
}
}
data->keys[k] = 0;
}
static void search_conf(void)
{
struct symbol **sym_arr;
struct gstr res;
struct gstr title;
char *dialog_input;
int dres, vscroll = 0, hscroll = 0;
bool again;
struct gstr sttext;
struct subtitle_part stpart;
title = str_new();
str_printf( &title, _("Enter (sub)string or regexp to search for "
"(with or without \"%s\")"), CONFIG_);
again:
dialog_clear();
dres = dialog_inputbox(_("Search Configuration Parameter"),
str_get(&title),
10, 75, "");
switch (dres) {
case 0:
break;
case 1:
show_helptext(_("Search Configuration"), search_help);
goto again;
default:
str_free(&title);
return;
}
dialog_input = dialog_input_result;
if (strncasecmp(dialog_input_result, CONFIG_, strlen(CONFIG_)) == 0)
dialog_input += strlen(CONFIG_);
sttext = str_new();
str_printf(&sttext, "Search (%s)", dialog_input_result);
stpart.text = str_get(&sttext);
list_add_tail(&stpart.entries, &trail);
sym_arr = sym_re_search(dialog_input);
do {
LIST_HEAD(head);
struct menu *targets[JUMP_NB];
int keys[JUMP_NB + 1], i;
struct search_data data = {
.head = &head,
.targets = targets,
.keys = keys,
};
struct jump_key *pos, *tmp;
res = get_relations_str(sym_arr, &head);
set_subtitle();
dres = show_textbox_ext(_("Search Results"), (char *)
str_get(&res), 0, 0, keys, &vscroll,
&hscroll, &update_text, (void *)
&data);
again = false;
for (i = 0; i < JUMP_NB && keys[i]; i++)
if (dres == keys[i]) {
conf(targets[i]->parent, targets[i]);
again = true;
}
str_free(&res);
list_for_each_entry_safe(pos, tmp, &head, entries)
free(pos);
} while (again);
free(sym_arr);
str_free(&title);
list_del(trail.prev);
str_free(&sttext);
}
static void build_conf(struct menu *menu)
{
struct symbol *sym;
struct property *prop;
struct menu *child;
int type, tmp, doint = 2;
tristate val;
char ch;
bool visible;
visible = menu_is_visible(menu);
if (show_all_options && !menu_has_prompt(menu))
return;
else if (!show_all_options && !visible)
return;
sym = menu->sym;
prop = menu->prompt;
if (!sym) {
if (prop && menu != current_menu) {
const char *prompt = menu_get_prompt(menu);
switch (prop->type) {
case P_MENU:
child_count++;
prompt = _(prompt);
if (single_menu_mode) {
item_make("%s%*c%s",
menu->data ? "-->" : "++>",
indent + 1, ' ', prompt);
} else
item_make(" %*c%s %s",
indent + 1, ' ', prompt,
menu_is_empty(menu) ? "----" : "--->");
item_set_tag('m');
item_set_data(menu);
if (single_menu_mode && menu->data)
goto conf_childs;
return;
case P_COMMENT:
if (prompt) {
child_count++;
item_make(" %*c*** %s ***", indent + 1, ' ', _(prompt));
item_set_tag(':');
item_set_data(menu);
}
break;
default:
if (prompt) {
child_count++;
item_make("---%*c%s", indent + 1, ' ', _(prompt));
item_set_tag(':');
item_set_data(menu);
}
}
} else
doint = 0;
goto conf_childs;
}
type = sym_get_type(sym);
if (sym_is_choice(sym)) {
struct symbol *def_sym = sym_get_choice_value(sym);
struct menu *def_menu = NULL;
child_count++;
for (child = menu->list; child; child = child->next) {
if (menu_is_visible(child) && child->sym == def_sym)
def_menu = child;
}
val = sym_get_tristate_value(sym);
if (sym_is_changable(sym)) {
switch (type) {
case S_BOOLEAN:
item_make("[%c]", val == no ? ' ' : '*');
break;
case S_TRISTATE:
switch (val) {
case yes: ch = '*'; break;
case mod: ch = 'M'; break;
default: ch = ' '; break;
}
item_make("<%c>", ch);
break;
}
item_set_tag('t');
item_set_data(menu);
} else {
item_make(" ");
item_set_tag(def_menu ? 't' : ':');
item_set_data(menu);
}
item_add_str("%*c%s", indent + 1, ' ', _(menu_get_prompt(menu)));
if (val == yes) {
if (def_menu) {
item_add_str(" (%s)", _(menu_get_prompt(def_menu)));
item_add_str(" --->");
if (def_menu->list) {
indent += 2;
build_conf(def_menu);
indent -= 2;
}
}
return;
}
} else {
if (menu == current_menu) {
item_make("---%*c%s", indent + 1, ' ', _(menu_get_prompt(menu)));
item_set_tag(':');
item_set_data(menu);
goto conf_childs;
}
child_count++;
val = sym_get_tristate_value(sym);
if (sym_is_choice_value(sym) && val == yes) {
item_make(" ");
item_set_tag(':');
item_set_data(menu);
} else {
switch (type) {
case S_BOOLEAN:
if (sym_is_changable(sym))
item_make("[%c]", val == no ? ' ' : '*');
else
item_make("-%c-", val == no ? ' ' : '*');
item_set_tag('t');
item_set_data(menu);
break;
case S_TRISTATE:
switch (val) {
case yes: ch = '*'; break;
case mod: ch = 'M'; break;
default: ch = ' '; break;
}
if (sym_is_changable(sym)) {
if (sym->rev_dep.tri == mod)
item_make("{%c}", ch);
else
item_make("<%c>", ch);
} else
item_make("-%c-", ch);
item_set_tag('t');
item_set_data(menu);
break;
default:
tmp = 2 + strlen(sym_get_string_value(sym));
item_make("(%s)", sym_get_string_value(sym));
tmp = indent - tmp + 4;
if (tmp < 0)
tmp = 0;
item_add_str("%*c%s%s", tmp, ' ', _(menu_get_prompt(menu)),
(sym_has_value(sym) || !sym_is_changable(sym)) ?
"" : _(" (NEW)"));
item_set_tag('s');
item_set_data(menu);
goto conf_childs;
}
}
item_add_str("%*c%s%s", indent + 1, ' ', _(menu_get_prompt(menu)),
(sym_has_value(sym) || !sym_is_changable(sym)) ?
"" : _(" (NEW)"));
if (menu->prompt->type == P_MENU) {
item_add_str(" %s", menu_is_empty(menu) ? "----" : "--->");
return;
}
}
conf_childs:
indent += doint;
for (child = menu->list; child; child = child->next)
build_conf(child);
indent -= doint;
}
static void conf(struct menu *menu, struct menu *active_menu)
{
struct menu *submenu;
const char *prompt = menu_get_prompt(menu);
struct subtitle_part stpart;
struct symbol *sym;
int res;
int s_scroll = 0;
if (menu != &rootmenu)
stpart.text = menu_get_prompt(menu);
else
stpart.text = NULL;
list_add_tail(&stpart.entries, &trail);
while (1) {
item_reset();
current_menu = menu;
build_conf(menu);
if (!child_count)
break;
set_subtitle();
dialog_clear();
res = dialog_menu(prompt ? _(prompt) : _("Main Menu"),
_(menu_instructions),
active_menu, &s_scroll);
if (res == 1 || res == KEY_ESC || res == -ERRDISPLAYTOOSMALL)
break;
if (item_count() != 0) {
if (!item_activate_selected())
continue;
if (!item_tag())
continue;
}
submenu = item_data();
active_menu = item_data();
if (submenu)
sym = submenu->sym;
else
sym = NULL;
switch (res) {
case 0:
switch (item_tag()) {
case 'm':
if (single_menu_mode)
submenu->data = (void *) (long) !submenu->data;
else
conf(submenu, NULL);
break;
case 't':
if (sym_is_choice(sym) && sym_get_tristate_value(sym) == yes)
conf_choice(submenu);
else if (submenu->prompt->type == P_MENU)
conf(submenu, NULL);
break;
case 's':
conf_string(submenu);
break;
}
break;
case 2:
if (sym)
show_help(submenu);
else {
reset_subtitle();
show_helptext(_("README"), _(mconf_readme));
}
break;
case 3:
reset_subtitle();
conf_save();
break;
case 4:
reset_subtitle();
conf_load();
break;
case 5:
if (item_is_tag('t')) {
if (sym_set_tristate_value(sym, yes))
break;
if (sym_set_tristate_value(sym, mod))
show_textbox(NULL, setmod_text, 6, 74);
}
break;
case 6:
if (item_is_tag('t'))
sym_set_tristate_value(sym, no);
break;
case 7:
if (item_is_tag('t'))
sym_set_tristate_value(sym, mod);
break;
case 8:
if (item_is_tag('t'))
sym_toggle_tristate_value(sym);
else if (item_is_tag('m'))
conf(submenu, NULL);
break;
case 9:
search_conf();
break;
case 10:
show_all_options = !show_all_options;
break;
}
}
list_del(trail.prev);
}
static int show_textbox_ext(const char *title, char *text, int r, int c, int
*keys, int *vscroll, int *hscroll, update_text_fn
update_text, void *data)
{
dialog_clear();
return dialog_textbox(title, text, r, c, keys, vscroll, hscroll,
update_text, data);
}
static void show_textbox(const char *title, const char *text, int r, int c)
{
show_textbox_ext(title, (char *) text, r, c, (int []) {0}, NULL, NULL,
NULL, NULL);
}
static void show_helptext(const char *title, const char *text)
{
show_textbox(title, text, 0, 0);
}
static void conf_message_callback(const char *fmt, va_list ap)
{
char buf[PATH_MAX+1];
vsnprintf(buf, sizeof(buf), fmt, ap);
if (save_and_exit) {
if (!silent)
printf("%s", buf);
} else {
show_textbox(NULL, buf, 6, 60);
}
}
static void show_help(struct menu *menu)
{
struct gstr help = str_new();
help.max_width = getmaxx(stdscr) - 10;
menu_get_ext_help(menu, &help);
show_helptext(_(menu_get_prompt(menu)), str_get(&help));
str_free(&help);
}
static void conf_choice(struct menu *menu)
{
const char *prompt = _(menu_get_prompt(menu));
struct menu *child;
struct symbol *active;
active = sym_get_choice_value(menu->sym);
while (1) {
int res;
int selected;
item_reset();
current_menu = menu;
for (child = menu->list; child; child = child->next) {
if (!menu_is_visible(child))
continue;
if (child->sym)
item_make("%s", _(menu_get_prompt(child)));
else {
item_make("*** %s ***", _(menu_get_prompt(child)));
item_set_tag(':');
}
item_set_data(child);
if (child->sym == active)
item_set_selected(1);
if (child->sym == sym_get_choice_value(menu->sym))
item_set_tag('X');
}
dialog_clear();
res = dialog_checklist(prompt ? _(prompt) : _("Main Menu"),
_(radiolist_instructions),
MENUBOX_HEIGTH_MIN,
MENUBOX_WIDTH_MIN,
CHECKLIST_HEIGTH_MIN);
selected = item_activate_selected();
switch (res) {
case 0:
if (selected) {
child = item_data();
if (!child->sym)
break;
sym_set_tristate_value(child->sym, yes);
}
return;
case 1:
if (selected) {
child = item_data();
show_help(child);
active = child->sym;
} else
show_help(menu);
break;
case KEY_ESC:
return;
case -ERRDISPLAYTOOSMALL:
return;
}
}
}
static void conf_string(struct menu *menu)
{
const char *prompt = menu_get_prompt(menu);
while (1) {
int res;
const char *heading;
switch (sym_get_type(menu->sym)) {
case S_INT:
heading = _(inputbox_instructions_int);
break;
case S_HEX:
heading = _(inputbox_instructions_hex);
break;
case S_STRING:
heading = _(inputbox_instructions_string);
break;
default:
heading = _("Internal mconf error!");
}
dialog_clear();
res = dialog_inputbox(prompt ? _(prompt) : _("Main Menu"),
heading, 10, 75,
sym_get_string_value(menu->sym));
switch (res) {
case 0:
if (sym_set_string_value(menu->sym, dialog_input_result))
return;
show_textbox(NULL, _("You have made an invalid entry."), 5, 43);
break;
case 1:
show_help(menu);
break;
case KEY_ESC:
return;
}
}
}
static void conf_load(void)
{
while (1) {
int res;
dialog_clear();
res = dialog_inputbox(NULL, load_config_text,
11, 55, filename);
switch(res) {
case 0:
if (!dialog_input_result[0])
return;
if (!conf_read(dialog_input_result)) {
set_config_filename(dialog_input_result);
sym_set_change_count(1);
return;
}
show_textbox(NULL, _("File does not exist!"), 5, 38);
break;
case 1:
show_helptext(_("Load Alternate Configuration"), load_config_help);
break;
case KEY_ESC:
return;
}
}
}
static void conf_save(void)
{
while (1) {
int res;
dialog_clear();
res = dialog_inputbox(NULL, save_config_text,
11, 55, filename);
switch(res) {
case 0:
if (!dialog_input_result[0])
return;
if (!conf_write(dialog_input_result)) {
set_config_filename(dialog_input_result);
return;
}
show_textbox(NULL, _("Can't create file! Probably a nonexistent directory."), 5, 60);
break;
case 1:
show_helptext(_("Save Alternate Configuration"), save_config_help);
break;
case KEY_ESC:
return;
}
}
}
static int handle_exit(void)
{
int res;
save_and_exit = 1;
reset_subtitle();
dialog_clear();
if (conf_get_changed())
res = dialog_yesno(NULL,
_("Do you wish to save your new configuration?\n"
"(Press <ESC><ESC> to continue kernel configuration.)"),
6, 60);
else
res = -1;
end_dialog(saved_x, saved_y);
switch (res) {
case 0:
if (conf_write(filename)) {
fprintf(stderr, _("\n\n"
"Error while writing of the configuration.\n"
"Your configuration changes were NOT saved."
"\n\n"));
return 1;
}
case -1:
if (!silent)
printf(_("\n\n"
"*** End of the configuration.\n"
"*** Execute 'make' to start the build or try 'make help'."
"\n\n"));
res = 0;
break;
default:
if (!silent)
fprintf(stderr, _("\n\n"
"Your configuration changes were NOT saved."
"\n\n"));
if (res != KEY_ESC)
res = 0;
}
return res;
}
static void sig_handler(int signo)
{
exit(handle_exit());
}
int main(int ac, char **av)
{
char *mode;
int res;
setlocale(LC_ALL, "");
bindtextdomain(PACKAGE, LOCALEDIR);
textdomain(PACKAGE);
signal(SIGINT, sig_handler);
if (ac > 1 && strcmp(av[1], "-s") == 0) {
silent = 1;
conf_set_message_callback(NULL);
av++;
}
conf_parse(av[1]);
conf_read(NULL);
mode = getenv("MENUCONFIG_MODE");
if (mode) {
if (!strcasecmp(mode, "single_menu"))
single_menu_mode = 1;
}
if (init_dialog(NULL)) {
fprintf(stderr, N_("Your display is too small to run Menuconfig!\n"));
fprintf(stderr, N_("It must be at least 19 lines by 80 columns.\n"));
return 1;
}
set_config_filename(conf_get_configname());
conf_set_message_callback(conf_message_callback);
do {
conf(&rootmenu, NULL);
res = handle_exit();
} while (res == KEY_ESC);
return res;
}
