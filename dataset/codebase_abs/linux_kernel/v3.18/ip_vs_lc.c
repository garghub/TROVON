static struct V_1 *
F_1 ( struct V_2 * V_3 , const struct V_4 * V_5 ,
struct V_6 * V_7 )
{
struct V_1 * V_8 , * V_9 = NULL ;
unsigned int V_10 = 0 , V_11 ;
F_2 ( 6 , L_1 , V_12 ) ;
F_3 (dest, &svc->destinations, n_list) {
if ( ( V_8 -> V_13 & V_14 ) ||
F_4 ( & V_8 -> V_15 ) == 0 )
continue;
V_11 = F_5 ( V_8 ) ;
if ( ! V_9 || V_11 < V_10 ) {
V_9 = V_8 ;
V_10 = V_11 ;
}
}
if ( ! V_9 )
F_6 ( V_3 , L_2 ) ;
else
F_7 ( 6 , L_3
L_4 ,
F_8 ( V_9 -> V_16 , & V_9 -> V_17 ) ,
F_9 ( V_9 -> V_18 ) ,
F_4 ( & V_9 -> V_19 ) ,
F_4 ( & V_9 -> V_20 ) ) ;
return V_9 ;
}
static int T_1 F_10 ( void )
{
return F_11 ( & V_21 ) ;
}
static void T_2 F_12 ( void )
{
F_13 ( & V_21 ) ;
F_14 () ;
}
