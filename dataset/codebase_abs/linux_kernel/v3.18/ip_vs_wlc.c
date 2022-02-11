static struct V_1 *
F_1 ( struct V_2 * V_3 , const struct V_4 * V_5 ,
struct V_6 * V_7 )
{
struct V_1 * V_8 , * V_9 ;
int V_10 , V_11 ;
F_2 ( 6 , L_1 ) ;
F_3 (dest, &svc->destinations, n_list) {
if ( ! ( V_8 -> V_12 & V_13 ) &&
F_4 ( & V_8 -> V_14 ) > 0 ) {
V_9 = V_8 ;
V_10 = F_5 ( V_9 ) ;
goto V_15;
}
}
F_6 ( V_3 , L_2 ) ;
return NULL ;
V_15:
F_7 (dest, &svc->destinations, n_list) {
if ( V_8 -> V_12 & V_13 )
continue;
V_11 = F_5 ( V_8 ) ;
if ( ( V_16 ) V_10 * F_4 ( & V_8 -> V_14 ) >
( V_16 ) V_11 * F_4 ( & V_9 -> V_14 ) ) {
V_9 = V_8 ;
V_10 = V_11 ;
}
}
F_8 ( 6 , L_3
L_4 ,
F_9 ( V_9 -> V_17 , & V_9 -> V_18 ) ,
F_10 ( V_9 -> V_19 ) ,
F_4 ( & V_9 -> V_20 ) ,
F_4 ( & V_9 -> V_21 ) ,
F_4 ( & V_9 -> V_14 ) , V_10 ) ;
return V_9 ;
}
static int T_1 F_11 ( void )
{
return F_12 ( & V_22 ) ;
}
static void T_2 F_13 ( void )
{
F_14 ( & V_22 ) ;
F_15 () ;
}
