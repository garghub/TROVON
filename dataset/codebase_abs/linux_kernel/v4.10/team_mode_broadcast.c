static bool F_1 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
struct V_4 * V_5 ;
struct V_4 * V_6 = NULL ;
struct V_2 * V_7 ;
bool V_8 ;
bool V_9 = false ;
F_2 (cur, &team->port_list, list) {
if ( F_3 ( V_5 ) ) {
if ( V_6 ) {
V_7 = F_4 ( V_3 , V_10 ) ;
if ( V_7 ) {
V_8 = ! F_5 ( V_1 , V_6 ,
V_7 ) ;
if ( ! V_9 )
V_9 = V_8 ;
}
}
V_6 = V_5 ;
}
}
if ( V_6 ) {
V_8 = ! F_5 ( V_1 , V_6 , V_3 ) ;
if ( ! V_9 )
V_9 = V_8 ;
}
return V_9 ;
}
static int T_1 F_6 ( void )
{
return F_7 ( & V_11 ) ;
}
static void T_2 F_8 ( void )
{
F_9 ( & V_11 ) ;
}
