void ui_progress__update(u64 curr, u64 total, const char *title)
{
int bar, y;
if (use_browser <= 0)
return;
if (total == 0)
return;
ui__refresh_dimensions(true);
pthread_mutex_lock(&ui__lock);
y = SLtt_Screen_Rows / 2 - 2;
SLsmg_set_color(0);
SLsmg_draw_box(y, 0, 3, SLtt_Screen_Cols);
SLsmg_gotorc(y++, 1);
SLsmg_write_string((char *)title);
SLsmg_set_color(HE_COLORSET_SELECTED);
bar = ((SLtt_Screen_Cols - 2) * curr) / total;
SLsmg_fill_region(y, 1, 1, bar, ' ');
SLsmg_refresh();
pthread_mutex_unlock(&ui__lock);
}
