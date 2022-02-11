static struct V_1 *
F_1 ( struct V_2 * V_3 , const struct V_4 * V_5 )
{
struct V_1 * V_6 , * V_7 ;
unsigned int V_8 , V_9 ;
F_2 ( 6 , L_1 ) ;
F_3 (dest, &svc->destinations, n_list) {
if ( ! ( V_6 -> V_10 & V_11 ) &&
F_4 ( & V_6 -> V_12 ) > 0 ) {
V_7 = V_6 ;
V_8 = F_5 ( V_7 ) ;
goto V_13;
}
}
F_6 ( V_3 , L_2 ) ;
return NULL ;
V_13:
F_7 (dest, &svc->destinations, n_list) {
if ( V_6 -> V_10 & V_11 )
continue;
V_9 = F_5 ( V_6 ) ;
if ( V_8 * F_4 ( & V_6 -> V_12 ) >
V_9 * F_4 ( & V_7 -> V_12 ) ) {
V_7 = V_6 ;
V_8 = V_9 ;
}
}
F_8 ( 6 , L_3
L_4 ,
F_9 ( V_3 -> V_14 , & V_7 -> V_15 ) , F_10 ( V_7 -> V_16 ) ,
F_4 ( & V_7 -> V_17 ) ,
F_4 ( & V_7 -> V_18 ) ,
F_4 ( & V_7 -> V_12 ) , V_8 ) ;
return V_7 ;
}
static int T_1 F_11 ( void )
{
return F_12 ( & V_19 ) ;
}
static void T_2 F_13 ( void )
{
F_14 ( & V_19 ) ;
F_15 () ;
}
