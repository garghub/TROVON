static struct V_1 *
F_1 ( struct V_2 * V_3 , const struct V_4 * V_5 )
{
struct V_1 * V_6 , * V_7 = NULL ;
unsigned int V_8 = 0 , V_9 ;
F_2 ( 6 , L_1 , V_10 ) ;
F_3 (dest, &svc->destinations, n_list) {
if ( ( V_6 -> V_11 & V_12 ) ||
F_4 ( & V_6 -> V_13 ) == 0 )
continue;
V_9 = F_5 ( V_6 ) ;
if ( ! V_7 || V_9 < V_8 ) {
V_7 = V_6 ;
V_8 = V_9 ;
}
}
if ( ! V_7 )
F_6 ( V_3 , L_2 ) ;
else
F_7 ( 6 , L_3
L_4 ,
F_8 ( V_3 -> V_14 , & V_7 -> V_15 ) ,
F_9 ( V_7 -> V_16 ) ,
F_4 ( & V_7 -> V_17 ) ,
F_4 ( & V_7 -> V_18 ) ) ;
return V_7 ;
}
static int T_1 F_10 ( void )
{
return F_11 ( & V_19 ) ;
}
static void T_2 F_12 ( void )
{
F_13 ( & V_19 ) ;
F_14 () ;
}
