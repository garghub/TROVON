static inline int
F_1 ( struct V_1 * V_2 )
{
return F_2 ( & V_2 -> V_3 ) + 1 ;
}
static struct V_1 *
F_3 ( struct V_4 * V_5 , const struct V_6 * V_7 ,
struct V_8 * V_9 )
{
struct V_1 * V_2 , * V_10 ;
int V_11 , V_12 ;
F_4 ( 6 , L_1 , V_13 ) ;
F_5 (dest, &svc->destinations, n_list) {
if ( ! ( V_2 -> V_14 & V_15 ) &&
F_2 ( & V_2 -> V_16 ) > 0 ) {
V_10 = V_2 ;
V_11 = F_1 ( V_10 ) ;
goto V_17;
}
}
F_6 ( V_5 , L_2 ) ;
return NULL ;
V_17:
F_7 (dest, &svc->destinations, n_list) {
if ( V_2 -> V_14 & V_15 )
continue;
V_12 = F_1 ( V_2 ) ;
if ( ( V_18 ) V_11 * F_2 ( & V_2 -> V_16 ) >
( V_18 ) V_12 * F_2 ( & V_10 -> V_16 ) ) {
V_10 = V_2 ;
V_11 = V_12 ;
}
}
F_8 ( 6 , L_3
L_4 ,
F_9 ( V_10 -> V_19 , & V_10 -> V_20 ) ,
F_10 ( V_10 -> V_21 ) ,
F_2 ( & V_10 -> V_3 ) ,
F_11 ( & V_10 -> V_22 ) ,
F_2 ( & V_10 -> V_16 ) , V_11 ) ;
return V_10 ;
}
static int T_1 F_12 ( void )
{
return F_13 ( & V_23 ) ;
}
static void T_2 F_14 ( void )
{
F_15 ( & V_23 ) ;
F_16 () ;
}
