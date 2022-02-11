void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_3 ) ;
F_3 ( & V_2 -> V_4 , & V_5 ) ;
F_4 ( & V_3 ) ;
}
void F_5 ( struct V_1 * V_2 )
{
F_2 ( & V_3 ) ;
F_6 ( & V_2 -> V_4 ) ;
F_4 ( & V_3 ) ;
}
struct V_1 * F_7 ( char * V_6 )
{
struct V_1 * V_7 , * V_8 = NULL ;
F_2 ( & V_3 ) ;
F_8 (t, &v9fs_trans_list, list)
if ( strcmp ( V_7 -> V_9 , V_6 ) == 0 &&
F_9 ( V_7 -> V_10 ) ) {
V_8 = V_7 ;
break;
}
F_4 ( & V_3 ) ;
return V_8 ;
}
struct V_1 * F_10 ( void )
{
struct V_1 * V_7 , * V_8 = NULL ;
F_2 ( & V_3 ) ;
F_8 (t, &v9fs_trans_list, list)
if ( V_7 -> V_11 && F_9 ( V_7 -> V_10 ) ) {
V_8 = V_7 ;
break;
}
if ( ! V_8 )
F_8 (t, &v9fs_trans_list, list)
if ( F_9 ( V_7 -> V_10 ) ) {
V_8 = V_7 ;
break;
}
F_4 ( & V_3 ) ;
return V_8 ;
}
void F_11 ( struct V_1 * V_2 )
{
if ( V_2 )
F_12 ( V_2 -> V_10 ) ;
}
static int T_1 F_13 ( void )
{
int V_12 = 0 ;
F_14 () ;
F_15 ( V_13 L_1 ) ;
F_16 () ;
return V_12 ;
}
static void T_2 F_17 ( void )
{
F_15 ( V_13 L_2 ) ;
F_18 () ;
}
