void F_1 ( enum V_1 V_2 , const char * V_3 ,
const char * V_4 , ... )
{
struct V_5 V_6 ;
T_1 args ;
if ( ( V_7 & V_2 ) != V_2 )
return;
va_start ( args , V_4 ) ;
V_6 . V_4 = V_4 ;
V_6 . V_8 = & args ;
if ( V_2 == V_9 )
F_2 ( L_1 , F_3 ( V_10 ) , & V_6 ) ;
else
F_2 ( L_2 , V_3 , F_3 ( V_10 ) , & V_6 ) ;
va_end ( args ) ;
}
void F_4 ( struct V_11 * V_12 )
{
F_5 ( & V_13 ) ;
F_6 ( & V_12 -> V_14 , & V_15 ) ;
F_7 ( & V_13 ) ;
}
void F_8 ( struct V_11 * V_12 )
{
F_5 ( & V_13 ) ;
F_9 ( & V_12 -> V_14 ) ;
F_7 ( & V_13 ) ;
}
struct V_11 * F_10 ( char * V_16 )
{
struct V_11 * V_17 , * V_18 = NULL ;
F_5 ( & V_13 ) ;
F_11 (t, &v9fs_trans_list, list)
if ( strcmp ( V_17 -> V_19 , V_16 ) == 0 &&
F_12 ( V_17 -> V_20 ) ) {
V_18 = V_17 ;
break;
}
F_7 ( & V_13 ) ;
return V_18 ;
}
struct V_11 * F_13 ( void )
{
struct V_11 * V_17 , * V_18 = NULL ;
F_5 ( & V_13 ) ;
F_11 (t, &v9fs_trans_list, list)
if ( V_17 -> V_21 && F_12 ( V_17 -> V_20 ) ) {
V_18 = V_17 ;
break;
}
if ( ! V_18 )
F_11 (t, &v9fs_trans_list, list)
if ( F_12 ( V_17 -> V_20 ) ) {
V_18 = V_17 ;
break;
}
F_7 ( & V_13 ) ;
return V_18 ;
}
void F_14 ( struct V_11 * V_12 )
{
if ( V_12 )
F_15 ( V_12 -> V_20 ) ;
}
static int T_2 F_16 ( void )
{
int V_22 = 0 ;
F_17 () ;
F_18 ( L_3 ) ;
F_19 () ;
return V_22 ;
}
static void T_3 F_20 ( void )
{
F_18 ( L_4 ) ;
F_21 () ;
}
