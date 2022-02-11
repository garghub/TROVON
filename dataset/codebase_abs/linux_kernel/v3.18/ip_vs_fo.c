static struct V_1 *
F_1 ( struct V_2 * V_3 , const struct V_4 * V_5 ,
struct V_6 * V_7 )
{
struct V_1 * V_8 , * V_9 = NULL ;
int V_10 = 0 ;
F_2 ( 6 , L_1 ) ;
F_3 (dest, &svc->destinations, n_list) {
if ( ! ( V_8 -> V_11 & V_12 ) &&
F_4 ( & V_8 -> V_13 ) > V_10 ) {
V_9 = V_8 ;
V_10 = F_4 ( & V_8 -> V_13 ) ;
}
}
if ( V_9 ) {
F_5 ( 6 , L_2 ,
F_6 ( V_9 -> V_14 , & V_9 -> V_15 ) ,
F_7 ( V_9 -> V_16 ) ,
F_4 ( & V_9 -> V_17 ) ,
F_4 ( & V_9 -> V_13 ) ) ;
return V_9 ;
}
F_8 ( V_3 , L_3 ) ;
return NULL ;
}
static int T_1 F_9 ( void )
{
return F_10 ( & V_18 ) ;
}
static void T_2 F_11 ( void )
{
F_12 ( & V_18 ) ;
F_13 () ;
}
