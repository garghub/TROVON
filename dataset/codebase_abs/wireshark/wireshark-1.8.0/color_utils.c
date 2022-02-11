T_1
F_1 ( T_2 * V_1 , T_3 V_2 , T_3 V_3 , T_3 V_4 )
{
T_4 V_5 ;
V_5 . V_6 = 0 ;
V_5 . V_2 = V_2 ;
V_5 . V_3 = V_3 ;
V_5 . V_4 = V_4 ;
#if 0
if (!get_color(&gdk_color))
return FALSE;
#endif
F_2 ( V_1 , & V_5 ) ;
return TRUE ;
}
void
F_3 ( void )
{
#if 0
gboolean got_white, got_black;
sys_cmap = gdk_colormap_get_system();
got_white = get_color(&WHITE);
got_black = get_color(&BLACK);
if (!got_white) {
if (!got_black)
simple_dialog(ESD_TYPE_WARN, ESD_BTN_OK,
"Could not allocate colors black or white.");
else
simple_dialog(ESD_TYPE_WARN, ESD_BTN_OK,
"Could not allocate color white.");
} else {
if (!got_black)
simple_dialog(ESD_TYPE_WARN, ESD_BTN_OK,
"Could not allocate color black.");
}
#endif
}
void
F_4 ( T_4 * V_7 , const T_2 * V_8 )
{
V_7 -> V_6 = V_8 -> V_6 ;
V_7 -> V_2 = V_8 -> V_2 ;
V_7 -> V_3 = V_8 -> V_3 ;
V_7 -> V_4 = V_8 -> V_4 ;
}
void
F_5 ( T_5 * V_7 , const T_2 * V_8 )
{
V_7 -> V_9 = 1 ;
V_7 -> V_2 = V_8 -> V_2 / 65535.0 ;
V_7 -> V_3 = V_8 -> V_3 / 65535.0 ;
V_7 -> V_4 = V_8 -> V_4 / 65535.0 ;
}
void
F_2 ( T_2 * V_7 , const T_4 * V_8 )
{
V_7 -> V_6 = V_8 -> V_6 ;
V_7 -> V_2 = V_8 -> V_2 ;
V_7 -> V_3 = V_8 -> V_3 ;
V_7 -> V_4 = V_8 -> V_4 ;
}
void
F_6 ( T_2 * V_7 , const T_5 * V_8 )
{
V_7 -> V_6 = 0 ;
V_7 -> V_2 = ( T_3 ) ( V_8 -> V_2 * 65535 ) ;
V_7 -> V_3 = ( T_3 ) ( V_8 -> V_3 * 65535 ) ;
V_7 -> V_4 = ( T_3 ) ( V_8 -> V_4 * 65535 ) ;
}
