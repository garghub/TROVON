static inline int
F_1 ( struct V_1 * V_2 )
{
return F_2 ( & V_2 -> V_3 ) + 1 ;
}
static struct V_1 *
F_3 ( struct V_4 * V_5 , const struct V_6 * V_7 ,
struct V_8 * V_9 )
{
struct V_1 * V_2 , * V_10 = NULL ;
int V_11 = 0 , V_12 ;
F_4 ( 6 , L_1 , V_13 ) ;
F_5 (dest, &svc->destinations, n_list) {
if ( V_2 -> V_14 & V_15 ||
! F_2 ( & V_2 -> V_16 ) )
continue;
V_12 = F_1 ( V_2 ) ;
if ( F_2 ( & V_2 -> V_3 ) == 0 ) {
V_10 = V_2 ;
V_11 = V_12 ;
goto V_17;
}
if ( ! V_10 ||
( ( V_18 ) V_11 * F_2 ( & V_2 -> V_16 ) >
( V_18 ) V_12 * F_2 ( & V_10 -> V_16 ) ) ) {
V_10 = V_2 ;
V_11 = V_12 ;
}
}
if ( ! V_10 ) {
F_6 ( V_5 , L_2 ) ;
return NULL ;
}
V_17:
F_7 ( 6 , L_3
L_4 ,
F_8 ( V_5 -> V_19 , & V_10 -> V_20 ) , F_9 ( V_10 -> V_21 ) ,
F_2 ( & V_10 -> V_3 ) ,
F_2 ( & V_10 -> V_22 ) ,
F_2 ( & V_10 -> V_16 ) , V_11 ) ;
return V_10 ;
}
static int T_1 F_10 ( void )
{
return F_11 ( & V_23 ) ;
}
static void T_2 F_12 ( void )
{
F_13 ( & V_23 ) ;
F_14 () ;
}
