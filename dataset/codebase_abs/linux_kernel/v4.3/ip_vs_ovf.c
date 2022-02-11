static struct V_1 *
F_1 ( struct V_2 * V_3 , const struct V_4 * V_5 ,
struct V_6 * V_7 )
{
struct V_1 * V_8 , * V_9 = NULL ;
int V_10 = 0 , V_11 ;
F_2 ( 6 , L_1 ) ;
F_3 (dest, &svc->destinations, n_list) {
V_11 = F_4 ( & V_8 -> V_12 ) ;
if ( ( V_8 -> V_13 & V_14 ) ||
F_4 ( & V_8 -> V_15 ) > V_11 ||
V_11 == 0 )
continue;
if ( ! V_9 || V_11 > V_10 ) {
V_9 = V_8 ;
V_10 = V_11 ;
}
}
if ( V_9 ) {
F_5 ( 6 , L_2 ,
F_6 ( V_9 -> V_16 , & V_9 -> V_17 ) ,
F_7 ( V_9 -> V_18 ) ,
F_4 ( & V_9 -> V_15 ) ,
F_4 ( & V_9 -> V_12 ) ) ;
return V_9 ;
}
F_8 ( V_3 , L_3 ) ;
return NULL ;
}
static int T_1 F_9 ( void )
{
return F_10 ( & V_19 ) ;
}
static void T_2 F_11 ( void )
{
F_12 ( & V_19 ) ;
F_13 () ;
}
