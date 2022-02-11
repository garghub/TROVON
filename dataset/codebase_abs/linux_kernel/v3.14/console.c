void F_1 ( struct V_1 * V_2 , bool V_3 )
{
struct V_4 * V_5 , * V_6 ;
F_2 ( & V_7 ) ;
F_3 (tmp, &pm_vt_switch_list, head) {
if ( V_6 -> V_2 == V_2 ) {
V_6 -> V_3 = V_3 ;
goto V_8;
}
}
V_5 = F_4 ( sizeof( * V_5 ) , V_9 ) ;
if ( ! V_5 )
goto V_8;
V_5 -> V_3 = V_3 ;
V_5 -> V_2 = V_2 ;
F_5 ( & V_5 -> V_10 , & V_11 ) ;
V_8:
F_6 ( & V_7 ) ;
}
void F_7 ( struct V_1 * V_2 )
{
struct V_4 * V_6 ;
F_2 ( & V_7 ) ;
F_3 (tmp, &pm_vt_switch_list, head) {
if ( V_6 -> V_2 == V_2 ) {
F_8 ( & V_6 -> V_10 ) ;
F_9 ( V_6 ) ;
break;
}
}
F_6 ( & V_7 ) ;
}
static bool V_4 ( void )
{
struct V_4 * V_5 ;
bool V_12 = true ;
F_2 ( & V_7 ) ;
if ( F_10 ( & V_11 ) )
goto V_8;
if ( ! V_13 )
goto V_8;
F_3 (entry, &pm_vt_switch_list, head) {
if ( V_5 -> V_3 )
goto V_8;
}
V_12 = false ;
V_8:
F_6 ( & V_7 ) ;
return V_12 ;
}
int F_11 ( void )
{
if ( ! V_4 () )
return 0 ;
V_14 = F_12 ( V_15 , 1 ) ;
if ( V_14 < 0 )
return 1 ;
V_16 = F_13 ( V_15 ) ;
return 0 ;
}
void F_14 ( void )
{
if ( ! V_4 () )
return;
if ( V_14 >= 0 ) {
F_12 ( V_14 , 0 ) ;
F_13 ( V_16 ) ;
}
}
