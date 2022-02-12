static void refresh_text_box(WINDOW *dialog, WINDOW *box, int boxh, int boxw,
int cur_y, int cur_x, update_text_fn update_text,
void *data)
{
print_page(box, boxh, boxw, update_text, data);
print_position(dialog);
wmove(dialog, cur_y, cur_x);
wrefresh(dialog);
}
int dialog_textbox(const char *title, char *tbuf, int initial_height,
int initial_width, int *keys, int *_vscroll, int *_hscroll,
update_text_fn update_text, void *data)
{
int i, x, y, cur_x, cur_y, key = 0;
int height, width, boxh, boxw;
WINDOW *dialog, *box;
bool done = false;
begin_reached = 1;
end_reached = 0;
page_length = 0;
hscroll = 0;
buf = tbuf;
page = buf;
if (_vscroll && *_vscroll) {
begin_reached = 0;
for (i = 0; i < *_vscroll; i++)
get_line();
}
if (_hscroll)
hscroll = *_hscroll;
do_resize:
getmaxyx(stdscr, height, width);
if (height < 8 || width < 8)
return -ERRDISPLAYTOOSMALL;
if (initial_height != 0)
height = initial_height;
else
if (height > 4)
height -= 4;
else
height = 0;
if (initial_width != 0)
width = initial_width;
else
if (width > 5)
width -= 5;
else
width = 0;
x = (COLS - width) / 2;
y = (LINES - height) / 2;
draw_shadow(stdscr, y, x, height, width);
dialog = newwin(height, width, y, x);
keypad(dialog, TRUE);
boxh = height - 4;
boxw = width - 2;
box = subwin(dialog, boxh, boxw, y + 1, x + 1);
wattrset(box, dlg.dialog.atr);
wbkgdset(box, dlg.dialog.atr & A_COLOR);
keypad(box, TRUE);
draw_box(dialog, 0, 0, height, width,
dlg.dialog.atr, dlg.border.atr);
wattrset(dialog, dlg.border.atr);
mvwaddch(dialog, height - 3, 0, ACS_LTEE);
for (i = 0; i < width - 2; i++)
waddch(dialog, ACS_HLINE);
wattrset(dialog, dlg.dialog.atr);
wbkgdset(dialog, dlg.dialog.atr & A_COLOR);
waddch(dialog, ACS_RTEE);
print_title(dialog, title, width);
print_button(dialog, gettext(" Exit "), height - 2, width / 2 - 4, TRUE);
wnoutrefresh(dialog);
getyx(dialog, cur_y, cur_x);
attr_clear(box, boxh, boxw, dlg.dialog.atr);
refresh_text_box(dialog, box, boxh, boxw, cur_y, cur_x, update_text,
data);
while (!done) {
key = wgetch(dialog);
switch (key) {
case 'E':
case 'e':
case 'X':
case 'x':
case 'q':
case '\n':
done = true;
break;
case 'g':
case KEY_HOME:
if (!begin_reached) {
begin_reached = 1;
page = buf;
refresh_text_box(dialog, box, boxh, boxw,
cur_y, cur_x, update_text,
data);
}
break;
case 'G':
case KEY_END:
end_reached = 1;
page = buf + strlen(buf);
back_lines(boxh);
refresh_text_box(dialog, box, boxh, boxw, cur_y,
cur_x, update_text, data);
break;
case 'K':
case 'k':
case KEY_UP:
if (begin_reached)
break;
back_lines(page_length + 1);
refresh_text_box(dialog, box, boxh, boxw, cur_y,
cur_x, update_text, data);
break;
case 'B':
case 'b':
case 'u':
case KEY_PPAGE:
if (begin_reached)
break;
back_lines(page_length + boxh);
refresh_text_box(dialog, box, boxh, boxw, cur_y,
cur_x, update_text, data);
break;
case 'J':
case 'j':
case KEY_DOWN:
if (end_reached)
break;
back_lines(page_length - 1);
refresh_text_box(dialog, box, boxh, boxw, cur_y,
cur_x, update_text, data);
break;
case KEY_NPAGE:
case ' ':
case 'd':
if (end_reached)
break;
begin_reached = 0;
refresh_text_box(dialog, box, boxh, boxw, cur_y,
cur_x, update_text, data);
break;
case '0':
case 'H':
case 'h':
case KEY_LEFT:
if (hscroll <= 0)
break;
if (key == '0')
hscroll = 0;
else
hscroll--;
back_lines(page_length);
refresh_text_box(dialog, box, boxh, boxw, cur_y,
cur_x, update_text, data);
break;
case 'L':
case 'l':
case KEY_RIGHT:
if (hscroll >= MAX_LEN)
break;
hscroll++;
back_lines(page_length);
refresh_text_box(dialog, box, boxh, boxw, cur_y,
cur_x, update_text, data);
break;
case KEY_ESC:
if (on_key_esc(dialog) == KEY_ESC)
done = true;
break;
case KEY_RESIZE:
back_lines(height);
delwin(box);
delwin(dialog);
on_key_resize();
goto do_resize;
default:
for (i = 0; keys[i]; i++) {
if (key == keys[i]) {
done = true;
break;
}
}
}
}
delwin(box);
delwin(dialog);
if (_vscroll) {
const char *s;
s = buf;
*_vscroll = 0;
back_lines(page_length);
while (s < page && (s = strchr(s, '\n'))) {
(*_vscroll)++;
s++;
}
}
if (_hscroll)
*_hscroll = hscroll;
return key;
}
static void back_lines(int n)
{
int i;
begin_reached = 0;
for (i = 0; i < n; i++) {
if (*page == '\0') {
if (end_reached) {
end_reached = 0;
continue;
}
}
if (page == buf) {
begin_reached = 1;
return;
}
page--;
do {
if (page == buf) {
begin_reached = 1;
return;
}
page--;
} while (*page != '\n');
page++;
}
}
static void print_page(WINDOW *win, int height, int width, update_text_fn
update_text, void *data)
{
int i, passed_end = 0;
if (update_text) {
char *end;
for (i = 0; i < height; i++)
get_line();
end = page;
back_lines(height);
update_text(buf, page - buf, end - buf, data);
}
page_length = 0;
for (i = 0; i < height; i++) {
print_line(win, i, width);
if (!passed_end)
page_length++;
if (end_reached && !passed_end)
passed_end = 1;
}
wnoutrefresh(win);
}
static void print_line(WINDOW * win, int row, int width)
{
char *line;
line = get_line();
line += MIN(strlen(line), hscroll);
wmove(win, row, 0);
waddch(win, ' ');
waddnstr(win, line, MIN(strlen(line), width - 2));
#if OLD_NCURSES
{
int x = getcurx(win);
int i;
for (i = 0; i < width - x; i++)
waddch(win, ' ');
}
#else
wclrtoeol(win);
#endif
}
static char *get_line(void)
{
int i = 0;
static char line[MAX_LEN + 1];
end_reached = 0;
while (*page != '\n') {
if (*page == '\0') {
end_reached = 1;
break;
} else if (i < MAX_LEN)
line[i++] = *(page++);
else {
if (i == MAX_LEN)
line[i++] = '\0';
page++;
}
}
if (i <= MAX_LEN)
line[i] = '\0';
if (!end_reached)
page++;
return line;
}
static void print_position(WINDOW * win)
{
int percent;
wattrset(win, dlg.position_indicator.atr);
wbkgdset(win, dlg.position_indicator.atr & A_COLOR);
percent = (page - buf) * 100 / strlen(buf);
wmove(win, getmaxy(win) - 3, getmaxx(win) - 9);
wprintw(win, "(%3d%%)", percent);
}
