static const char *dummycon_startup(void)
{
return "dummy device";
}
static void dummycon_init(struct vc_data *vc, int init)
{
vc->vc_can_do_color = 1;
if (init) {
vc->vc_cols = DUMMY_COLUMNS;
vc->vc_rows = DUMMY_ROWS;
} else
vc_resize(vc, DUMMY_COLUMNS, DUMMY_ROWS);
}
static int dummycon_dummy(void)
{
return 0;
}
