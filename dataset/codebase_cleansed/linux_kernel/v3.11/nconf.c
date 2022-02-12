static void print_function_line(void)
{
int i;
int offset = 1;
const int skip = 1;
int lines = getmaxy(stdscr);
for (i = 0; i < function_keys_num; i++) {
(void) wattrset(main_window, attributes[FUNCTION_HIGHLIGHT]);
mvwprintw(main_window, lines-3, offset,
"%s",
function_keys[i].key_str);
(void) wattrset(main_window, attributes[FUNCTION_TEXT]);
offset += strlen(function_keys[i].key_str);
mvwprintw(main_window, lines-3,
offset, "%s",
function_keys[i].func);
offset += strlen(function_keys[i].func) + skip;
}
(void) wattrset(main_window, attributes[NORMAL]);
}
static void handle_f1(int *key, struct menu *current_item)
{
show_scroll_win(main_window,
_("Global help"), _(nconf_global_help));
return;
}
static void handle_f2(int *key, struct menu *current_item)
{
show_help(current_item);
return;
}
static void handle_f3(int *key, struct menu *current_item)
{
show_scroll_win(main_window,
_("Short help"),
_(current_instructions));
return;
}
static void handle_f4(int *key, struct menu *current_item)
{
int res = btn_dialog(main_window,
_("Show all symbols?"),
2,
" <Show All> ",
"<Don't show all>");
if (res == 0)
show_all_items = 1;
else if (res == 1)
show_all_items = 0;
return;
}
static void handle_f5(int *key, struct menu *current_item)
{
*key = KEY_LEFT;
return;
}
static void handle_f6(int *key, struct menu *current_item)
{
conf_save();
return;
}
static void handle_f7(int *key, struct menu *current_item)
{
conf_load();
return;
}
static void handle_f8(int *key, struct menu *current_item)
{
search_conf();
return;
}
static void handle_f9(int *key, struct menu *current_item)
{
do_exit();
return;
}
static int process_special_keys(int *key, struct menu *menu)
{
int i;
if (*key == KEY_RESIZE) {
setup_windows();
return 1;
}
for (i = 0; i < function_keys_num; i++) {
if (*key == KEY_F(function_keys[i].key) ||
*key == '0' + function_keys[i].key){
function_keys[i].handler(key, menu);
return 1;
}
}
return 0;
}
static void clean_items(void)
{
int i;
for (i = 0; curses_menu_items[i]; i++)
free_item(curses_menu_items[i]);
bzero(curses_menu_items, sizeof(curses_menu_items));
bzero(k_menu_items, sizeof(k_menu_items));
items_num = 0;
}
static int get_mext_match(const char *match_str, match_f flag)
{
int match_start = item_index(current_item(curses_menu));
int index;
if (flag == FIND_NEXT_MATCH_DOWN)
++match_start;
else if (flag == FIND_NEXT_MATCH_UP)
--match_start;
index = match_start;
index = (index + items_num) % items_num;
while (true) {
char *str = k_menu_items[index].str;
if (strcasestr(str, match_str) != 0)
return index;
if (flag == FIND_NEXT_MATCH_UP ||
flag == MATCH_TINKER_PATTERN_UP)
--index;
else
++index;
index = (index + items_num) % items_num;
if (index == match_start)
return -1;
}
}
static void item_make(struct menu *menu, char tag, const char *fmt, ...)
{
va_list ap;
if (items_num > MAX_MENU_ITEMS-1)
return;
bzero(&k_menu_items[items_num], sizeof(k_menu_items[0]));
k_menu_items[items_num].tag = tag;
k_menu_items[items_num].usrptr = menu;
if (menu != NULL)
k_menu_items[items_num].is_visible =
menu_is_visible(menu);
else
k_menu_items[items_num].is_visible = 1;
va_start(ap, fmt);
vsnprintf(k_menu_items[items_num].str,
sizeof(k_menu_items[items_num].str),
fmt, ap);
va_end(ap);
if (!k_menu_items[items_num].is_visible)
memcpy(k_menu_items[items_num].str, "XXX", 3);
curses_menu_items[items_num] = new_item(
k_menu_items[items_num].str,
k_menu_items[items_num].str);
set_item_userptr(curses_menu_items[items_num],
&k_menu_items[items_num]);
items_num++;
curses_menu_items[items_num] = NULL;
}
static void item_add_str(const char *fmt, ...)
{
va_list ap;
int index = items_num-1;
char new_str[256];
char tmp_str[256];
if (index < 0)
return;
va_start(ap, fmt);
vsnprintf(new_str, sizeof(new_str), fmt, ap);
va_end(ap);
snprintf(tmp_str, sizeof(tmp_str), "%s%s",
k_menu_items[index].str, new_str);
strncpy(k_menu_items[index].str,
tmp_str,
sizeof(k_menu_items[index].str));
free_item(curses_menu_items[index]);
curses_menu_items[index] = new_item(
k_menu_items[index].str,
k_menu_items[index].str);
set_item_userptr(curses_menu_items[index],
&k_menu_items[index]);
}
static char item_tag(void)
{
ITEM *cur;
struct mitem *mcur;
cur = current_item(curses_menu);
if (cur == NULL)
return 0;
mcur = (struct mitem *) item_userptr(cur);
return mcur->tag;
}
static int curses_item_index(void)
{
return item_index(current_item(curses_menu));
}
static void *item_data(void)
{
ITEM *cur;
struct mitem *mcur;
cur = current_item(curses_menu);
if (!cur)
return NULL;
mcur = (struct mitem *) item_userptr(cur);
return mcur->usrptr;
}
static int item_is_tag(char tag)
{
return item_tag() == tag;
}
static const char *set_config_filename(const char *config_filename)
{
int size;
size = snprintf(menu_backtitle, sizeof(menu_backtitle),
"%s - %s", config_filename, rootmenu.prompt->text);
if (size >= sizeof(menu_backtitle))
menu_backtitle[sizeof(menu_backtitle)-1] = '\0';
size = snprintf(filename, sizeof(filename), "%s", config_filename);
if (size >= sizeof(filename))
filename[sizeof(filename)-1] = '\0';
return menu_backtitle;
}
static int do_exit(void)
{
int res;
if (!conf_get_changed()) {
global_exit = 1;
return 0;
}
res = btn_dialog(main_window,
_("Do you wish to save your new configuration?\n"
"<ESC> to cancel and resume nconfig."),
2,
" <save> ",
"<don't save>");
if (res == KEY_EXIT) {
global_exit = 0;
return -1;
}
switch (res) {
case 0:
res = conf_write(filename);
if (res)
btn_dialog(
main_window,
_("Error during writing of configuration.\n"
"Your configuration changes were NOT saved."),
1,
"<OK>");
break;
default:
btn_dialog(
main_window,
_("Your configuration changes were NOT saved."),
1,
"<OK>");
break;
}
global_exit = 1;
return 0;
}
static void search_conf(void)
{
struct symbol **sym_arr;
struct gstr res;
struct gstr title;
char *dialog_input;
int dres;
title = str_new();
str_printf( &title, _("Enter %s (sub)string or regexp to search for "
"(with or without \"%s\")"), CONFIG_, CONFIG_);
again:
dres = dialog_inputbox(main_window,
_("Search Configuration Parameter"),
str_get(&title),
"", &dialog_input_result, &dialog_input_result_len);
switch (dres) {
case 0:
break;
case 1:
show_scroll_win(main_window,
_("Search Configuration"), search_help);
goto again;
default:
str_free(&title);
return;
}
dialog_input = dialog_input_result;
if (strncasecmp(dialog_input_result, CONFIG_, strlen(CONFIG_)) == 0)
dialog_input += strlen(CONFIG_);
sym_arr = sym_re_search(dialog_input);
res = get_relations_str(sym_arr, NULL);
free(sym_arr);
show_scroll_win(main_window,
_("Search Results"), str_get(&res));
str_free(&res);
str_free(&title);
}
static void build_conf(struct menu *menu)
{
struct symbol *sym;
struct property *prop;
struct menu *child;
int type, tmp, doint = 2;
tristate val;
char ch;
if (!menu || (!show_all_items && !menu_is_visible(menu)))
return;
sym = menu->sym;
prop = menu->prompt;
if (!sym) {
if (prop && menu != current_menu) {
const char *prompt = menu_get_prompt(menu);
enum prop_type ptype;
ptype = menu->prompt ? menu->prompt->type : P_UNKNOWN;
switch (ptype) {
case P_MENU:
child_count++;
prompt = _(prompt);
if (single_menu_mode) {
item_make(menu, 'm',
"%s%*c%s",
menu->data ? "-->" : "++>",
indent + 1, ' ', prompt);
} else
item_make(menu, 'm',
" %*c%s %s",
indent + 1, ' ', prompt,
menu_is_empty(menu) ? "----" : "--->");
if (single_menu_mode && menu->data)
goto conf_childs;
return;
case P_COMMENT:
if (prompt) {
child_count++;
item_make(menu, ':',
" %*c*** %s ***",
indent + 1, ' ',
_(prompt));
}
break;
default:
if (prompt) {
child_count++;
item_make(menu, ':', "---%*c%s",
indent + 1, ' ',
_(prompt));
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
item_make(menu, 't', "[%c]",
val == no ? ' ' : '*');
break;
case S_TRISTATE:
switch (val) {
case yes:
ch = '*';
break;
case mod:
ch = 'M';
break;
default:
ch = ' ';
break;
}
item_make(menu, 't', "<%c>", ch);
break;
}
} else {
item_make(menu, def_menu ? 't' : ':', " ");
}
item_add_str("%*c%s", indent + 1,
' ', _(menu_get_prompt(menu)));
if (val == yes) {
if (def_menu) {
item_add_str(" (%s)",
_(menu_get_prompt(def_menu)));
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
item_make(menu, ':',
"---%*c%s", indent + 1,
' ', _(menu_get_prompt(menu)));
goto conf_childs;
}
child_count++;
val = sym_get_tristate_value(sym);
if (sym_is_choice_value(sym) && val == yes) {
item_make(menu, ':', " ");
} else {
switch (type) {
case S_BOOLEAN:
if (sym_is_changable(sym))
item_make(menu, 't', "[%c]",
val == no ? ' ' : '*');
else
item_make(menu, 't', "-%c-",
val == no ? ' ' : '*');
break;
case S_TRISTATE:
switch (val) {
case yes:
ch = '*';
break;
case mod:
ch = 'M';
break;
default:
ch = ' ';
break;
}
if (sym_is_changable(sym)) {
if (sym->rev_dep.tri == mod)
item_make(menu,
't', "{%c}", ch);
else
item_make(menu,
't', "<%c>", ch);
} else
item_make(menu, 't', "-%c-", ch);
break;
default:
tmp = 2 + strlen(sym_get_string_value(sym));
item_make(menu, 's', " (%s)",
sym_get_string_value(sym));
tmp = indent - tmp + 4;
if (tmp < 0)
tmp = 0;
item_add_str("%*c%s%s", tmp, ' ',
_(menu_get_prompt(menu)),
(sym_has_value(sym) ||
!sym_is_changable(sym)) ? "" :
_(" (NEW)"));
goto conf_childs;
}
}
item_add_str("%*c%s%s", indent + 1, ' ',
_(menu_get_prompt(menu)),
(sym_has_value(sym) || !sym_is_changable(sym)) ?
"" : _(" (NEW)"));
if (menu->prompt && menu->prompt->type == P_MENU) {
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
static void reset_menu(void)
{
unpost_menu(curses_menu);
clean_items();
}
static void center_item(int selected_index, int *last_top_row)
{
int toprow;
set_top_row(curses_menu, *last_top_row);
toprow = top_row(curses_menu);
if (selected_index < toprow ||
selected_index >= toprow+mwin_max_lines) {
toprow = max(selected_index-mwin_max_lines/2, 0);
if (toprow >= item_count(curses_menu)-mwin_max_lines)
toprow = item_count(curses_menu)-mwin_max_lines;
set_top_row(curses_menu, toprow);
}
set_current_item(curses_menu,
curses_menu_items[selected_index]);
*last_top_row = toprow;
post_menu(curses_menu);
refresh_all_windows(main_window);
}
static void show_menu(const char *prompt, const char *instructions,
int selected_index, int *last_top_row)
{
int maxx, maxy;
WINDOW *menu_window;
current_instructions = instructions;
clear();
(void) wattrset(main_window, attributes[NORMAL]);
print_in_middle(stdscr, 1, 0, getmaxx(stdscr),
menu_backtitle,
attributes[MAIN_HEADING]);
(void) wattrset(main_window, attributes[MAIN_MENU_BOX]);
box(main_window, 0, 0);
(void) wattrset(main_window, attributes[MAIN_MENU_HEADING]);
mvwprintw(main_window, 0, 3, " %s ", prompt);
(void) wattrset(main_window, attributes[NORMAL]);
set_menu_items(curses_menu, curses_menu_items);
scale_menu(curses_menu, &maxy, &maxx);
maxx = min(maxx, mwin_max_cols-2);
maxy = mwin_max_lines;
menu_window = derwin(main_window,
maxy,
maxx,
2,
(mwin_max_cols-maxx)/2);
keypad(menu_window, TRUE);
set_menu_win(curses_menu, menu_window);
set_menu_sub(curses_menu, menu_window);
set_menu_format(curses_menu, maxy, 1);
center_item(selected_index, last_top_row);
set_menu_format(curses_menu, maxy, 1);
print_function_line();
post_menu(curses_menu);
refresh_all_windows(main_window);
}
static void adj_match_dir(match_f *match_direction)
{
if (*match_direction == FIND_NEXT_MATCH_DOWN)
*match_direction =
MATCH_TINKER_PATTERN_DOWN;
else if (*match_direction == FIND_NEXT_MATCH_UP)
*match_direction =
MATCH_TINKER_PATTERN_UP;
}
static int do_match(int key, struct match_state *state, int *ans)
{
char c = (char) key;
int terminate_search = 0;
*ans = -1;
if (key == '/' || (state->in_search && key == 27)) {
move(0, 0);
refresh();
clrtoeol();
state->in_search = 1-state->in_search;
bzero(state->pattern, sizeof(state->pattern));
state->match_direction = MATCH_TINKER_PATTERN_DOWN;
return 0;
} else if (!state->in_search)
return 1;
if (isalnum(c) || isgraph(c) || c == ' ') {
state->pattern[strlen(state->pattern)] = c;
state->pattern[strlen(state->pattern)] = '\0';
adj_match_dir(&state->match_direction);
*ans = get_mext_match(state->pattern,
state->match_direction);
} else if (key == KEY_DOWN) {
state->match_direction = FIND_NEXT_MATCH_DOWN;
*ans = get_mext_match(state->pattern,
state->match_direction);
} else if (key == KEY_UP) {
state->match_direction = FIND_NEXT_MATCH_UP;
*ans = get_mext_match(state->pattern,
state->match_direction);
} else if (key == KEY_BACKSPACE || key == 127) {
state->pattern[strlen(state->pattern)-1] = '\0';
adj_match_dir(&state->match_direction);
} else
terminate_search = 1;
if (terminate_search) {
state->in_search = 0;
bzero(state->pattern, sizeof(state->pattern));
move(0, 0);
refresh();
clrtoeol();
return -1;
}
return 0;
}
static void conf(struct menu *menu)
{
struct menu *submenu = 0;
const char *prompt = menu_get_prompt(menu);
struct symbol *sym;
int res;
int current_index = 0;
int last_top_row = 0;
struct match_state match_state = {
.in_search = 0,
.match_direction = MATCH_TINKER_PATTERN_DOWN,
.pattern = "",
};
while (!global_exit) {
reset_menu();
current_menu = menu;
build_conf(menu);
if (!child_count)
break;
show_menu(prompt ? _(prompt) : _("Main Menu"),
_(menu_instructions),
current_index, &last_top_row);
keypad((menu_win(curses_menu)), TRUE);
while (!global_exit) {
if (match_state.in_search) {
mvprintw(0, 0,
"searching: %s", match_state.pattern);
clrtoeol();
}
refresh_all_windows(main_window);
res = wgetch(menu_win(curses_menu));
if (!res)
break;
if (do_match(res, &match_state, &current_index) == 0) {
if (current_index != -1)
center_item(current_index,
&last_top_row);
continue;
}
if (process_special_keys(&res,
(struct menu *) item_data()))
break;
switch (res) {
case KEY_DOWN:
menu_driver(curses_menu, REQ_DOWN_ITEM);
break;
case KEY_UP:
menu_driver(curses_menu, REQ_UP_ITEM);
break;
case KEY_NPAGE:
menu_driver(curses_menu, REQ_SCR_DPAGE);
break;
case KEY_PPAGE:
menu_driver(curses_menu, REQ_SCR_UPAGE);
break;
case KEY_HOME:
menu_driver(curses_menu, REQ_FIRST_ITEM);
break;
case KEY_END:
menu_driver(curses_menu, REQ_LAST_ITEM);
break;
case 'h':
case '?':
show_help((struct menu *) item_data());
break;
}
if (res == 10 || res == 27 ||
res == 32 || res == 'n' || res == 'y' ||
res == KEY_LEFT || res == KEY_RIGHT ||
res == 'm')
break;
refresh_all_windows(main_window);
}
refresh_all_windows(main_window);
if (res == 27 || (menu != &rootmenu && res == KEY_LEFT))
break;
last_top_row = top_row(curses_menu);
current_index = curses_item_index();
if (!item_tag())
continue;
submenu = (struct menu *) item_data();
if (!submenu || !menu_is_visible(submenu))
continue;
sym = submenu->sym;
switch (res) {
case ' ':
if (item_is_tag('t'))
sym_toggle_tristate_value(sym);
else if (item_is_tag('m'))
conf(submenu);
break;
case KEY_RIGHT:
case 10:
switch (item_tag()) {
case 'm':
if (single_menu_mode)
submenu->data =
(void *) (long) !submenu->data;
else
conf(submenu);
break;
case 't':
if (sym_is_choice(sym) &&
sym_get_tristate_value(sym) == yes)
conf_choice(submenu);
else if (submenu->prompt &&
submenu->prompt->type == P_MENU)
conf(submenu);
else if (res == 10)
sym_toggle_tristate_value(sym);
break;
case 's':
conf_string(submenu);
break;
}
break;
case 'y':
if (item_is_tag('t')) {
if (sym_set_tristate_value(sym, yes))
break;
if (sym_set_tristate_value(sym, mod))
btn_dialog(main_window, setmod_text, 0);
}
break;
case 'n':
if (item_is_tag('t'))
sym_set_tristate_value(sym, no);
break;
case 'm':
if (item_is_tag('t'))
sym_set_tristate_value(sym, mod);
break;
}
}
}
static void conf_message_callback(const char *fmt, va_list ap)
{
char buf[1024];
vsnprintf(buf, sizeof(buf), fmt, ap);
btn_dialog(main_window, buf, 1, "<OK>");
}
static void show_help(struct menu *menu)
{
struct gstr help;
if (!menu)
return;
help = str_new();
menu_get_ext_help(menu, &help);
show_scroll_win(main_window, _(menu_get_prompt(menu)), str_get(&help));
str_free(&help);
}
static void conf_choice(struct menu *menu)
{
const char *prompt = _(menu_get_prompt(menu));
struct menu *child = 0;
struct symbol *active;
int selected_index = 0;
int last_top_row = 0;
int res, i = 0;
struct match_state match_state = {
.in_search = 0,
.match_direction = MATCH_TINKER_PATTERN_DOWN,
.pattern = "",
};
active = sym_get_choice_value(menu->sym);
while (!global_exit) {
reset_menu();
for (i = 0, child = menu->list; child; child = child->next) {
if (!show_all_items && !menu_is_visible(child))
continue;
if (child->sym == sym_get_choice_value(menu->sym))
item_make(child, ':', "<X> %s",
_(menu_get_prompt(child)));
else if (child->sym)
item_make(child, ':', " %s",
_(menu_get_prompt(child)));
else
item_make(child, ':', "*** %s ***",
_(menu_get_prompt(child)));
if (child->sym == active){
last_top_row = top_row(curses_menu);
selected_index = i;
}
i++;
}
show_menu(prompt ? _(prompt) : _("Choice Menu"),
_(radiolist_instructions),
selected_index,
&last_top_row);
while (!global_exit) {
if (match_state.in_search) {
mvprintw(0, 0, "searching: %s",
match_state.pattern);
clrtoeol();
}
refresh_all_windows(main_window);
res = wgetch(menu_win(curses_menu));
if (!res)
break;
if (do_match(res, &match_state, &selected_index) == 0) {
if (selected_index != -1)
center_item(selected_index,
&last_top_row);
continue;
}
if (process_special_keys(
&res,
(struct menu *) item_data()))
break;
switch (res) {
case KEY_DOWN:
menu_driver(curses_menu, REQ_DOWN_ITEM);
break;
case KEY_UP:
menu_driver(curses_menu, REQ_UP_ITEM);
break;
case KEY_NPAGE:
menu_driver(curses_menu, REQ_SCR_DPAGE);
break;
case KEY_PPAGE:
menu_driver(curses_menu, REQ_SCR_UPAGE);
break;
case KEY_HOME:
menu_driver(curses_menu, REQ_FIRST_ITEM);
break;
case KEY_END:
menu_driver(curses_menu, REQ_LAST_ITEM);
break;
case 'h':
case '?':
show_help((struct menu *) item_data());
break;
}
if (res == 10 || res == 27 || res == ' ' ||
res == KEY_LEFT){
break;
}
refresh_all_windows(main_window);
}
if (res == 27 || res == KEY_LEFT)
break;
child = item_data();
if (!child || !menu_is_visible(child) || !child->sym)
continue;
switch (res) {
case ' ':
case 10:
case KEY_RIGHT:
sym_set_tristate_value(child->sym, yes);
return;
case 'h':
case '?':
show_help(child);
active = child->sym;
break;
case KEY_EXIT:
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
heading = _("Internal nconf error!");
}
res = dialog_inputbox(main_window,
prompt ? _(prompt) : _("Main Menu"),
heading,
sym_get_string_value(menu->sym),
&dialog_input_result,
&dialog_input_result_len);
switch (res) {
case 0:
if (sym_set_string_value(menu->sym,
dialog_input_result))
return;
btn_dialog(main_window,
_("You have made an invalid entry."), 0);
break;
case 1:
show_help(menu);
break;
case KEY_EXIT:
return;
}
}
}
static void conf_load(void)
{
while (1) {
int res;
res = dialog_inputbox(main_window,
NULL, load_config_text,
filename,
&dialog_input_result,
&dialog_input_result_len);
switch (res) {
case 0:
if (!dialog_input_result[0])
return;
if (!conf_read(dialog_input_result)) {
set_config_filename(dialog_input_result);
sym_set_change_count(1);
return;
}
btn_dialog(main_window, _("File does not exist!"), 0);
break;
case 1:
show_scroll_win(main_window,
_("Load Alternate Configuration"),
load_config_help);
break;
case KEY_EXIT:
return;
}
}
}
static void conf_save(void)
{
while (1) {
int res;
res = dialog_inputbox(main_window,
NULL, save_config_text,
filename,
&dialog_input_result,
&dialog_input_result_len);
switch (res) {
case 0:
if (!dialog_input_result[0])
return;
res = conf_write(dialog_input_result);
if (!res) {
set_config_filename(dialog_input_result);
return;
}
btn_dialog(main_window, _("Can't create file! "
"Probably a nonexistent directory."),
1, "<OK>");
break;
case 1:
show_scroll_win(main_window,
_("Save Alternate Configuration"),
save_config_help);
break;
case KEY_EXIT:
return;
}
}
}
void setup_windows(void)
{
int lines, columns;
getmaxyx(stdscr, lines, columns);
if (main_window != NULL)
delwin(main_window);
main_window = newwin(lines-2, columns-2, 2, 1);
keypad(main_window, TRUE);
mwin_max_lines = lines-7;
mwin_max_cols = columns-6;
new_panel(main_window);
}
int main(int ac, char **av)
{
int lines, columns;
char *mode;
setlocale(LC_ALL, "");
bindtextdomain(PACKAGE, LOCALEDIR);
textdomain(PACKAGE);
conf_parse(av[1]);
conf_read(NULL);
mode = getenv("NCONFIG_MODE");
if (mode) {
if (!strcasecmp(mode, "single_menu"))
single_menu_mode = 1;
}
initscr();
set_colors();
cbreak();
noecho();
keypad(stdscr, TRUE);
curs_set(0);
getmaxyx(stdscr, lines, columns);
if (columns < 75 || lines < 20) {
endwin();
printf("Your terminal should have at "
"least 20 lines and 75 columns\n");
return 1;
}
notimeout(stdscr, FALSE);
#if NCURSES_REENTRANT
set_escdelay(1);
#else
ESCDELAY = 1;
#endif
curses_menu = new_menu(curses_menu_items);
menu_opts_off(curses_menu, O_SHOWDESC);
menu_opts_on(curses_menu, O_SHOWMATCH);
menu_opts_on(curses_menu, O_ONEVALUE);
menu_opts_on(curses_menu, O_NONCYCLIC);
menu_opts_on(curses_menu, O_IGNORECASE);
set_menu_mark(curses_menu, " ");
set_menu_fore(curses_menu, attributes[MAIN_MENU_FORE]);
set_menu_back(curses_menu, attributes[MAIN_MENU_BACK]);
set_menu_grey(curses_menu, attributes[MAIN_MENU_GREY]);
set_config_filename(conf_get_configname());
setup_windows();
if (has_key(KEY_F(1)) == FALSE) {
show_scroll_win(main_window,
_("Instructions"),
_(menu_no_f_instructions));
}
conf_set_message_callback(conf_message_callback);
while (!global_exit) {
conf(&rootmenu);
if (!global_exit && do_exit() == 0)
break;
}
unpost_menu(curses_menu);
free_menu(curses_menu);
delwin(main_window);
clear();
refresh();
endwin();
return 0;
}
