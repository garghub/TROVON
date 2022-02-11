static int F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = & V_2 -> V_4 ;
return 0 ;
}
static int F_2 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
struct V_7 * V_8 ;
F_3 ( & V_2 -> V_9 ) ;
V_8 = (struct V_7 * ) V_2 -> V_3 ;
if ( V_8 == & V_6 -> V_10 )
V_2 -> V_3 = V_8 -> V_11 -> V_12 ;
F_4 ( & V_2 -> V_9 ) ;
return 0 ;
}
static struct V_5 *
F_5 ( struct V_1 * V_2 , const struct V_13 * V_14 ,
struct V_15 * V_16 )
{
struct V_7 * V_8 ;
struct V_5 * V_6 , * V_17 ;
int V_18 = 0 ;
F_6 ( 6 , L_1 , V_19 ) ;
F_3 ( & V_2 -> V_9 ) ;
V_8 = (struct V_7 * ) V_2 -> V_3 ;
V_17 = V_6 = F_7 ( V_8 , struct V_5 , V_10 ) ;
do {
F_8 (dest,
&svc->destinations,
n_list) {
if ( ! ( V_6 -> V_20 & V_21 ) &&
F_9 ( & V_6 -> V_22 ) > 0 )
goto V_23;
if ( V_6 == V_17 )
goto V_24;
}
V_18 ++ ;
} while ( V_18 < 2 && V_8 != & V_2 -> V_4 );
V_24:
F_4 ( & V_2 -> V_9 ) ;
F_10 ( V_2 , L_2 ) ;
return NULL ;
V_23:
V_2 -> V_3 = & V_6 -> V_10 ;
F_4 ( & V_2 -> V_9 ) ;
F_11 ( 6 , L_3
L_4 ,
F_12 ( V_6 -> V_25 , & V_6 -> V_26 ) , F_13 ( V_6 -> V_27 ) ,
F_9 ( & V_6 -> V_28 ) ,
F_14 ( & V_6 -> V_29 ) , F_9 ( & V_6 -> V_22 ) ) ;
return V_6 ;
}
static int T_1 F_15 ( void )
{
return F_16 ( & V_30 ) ;
}
static void T_2 F_17 ( void )
{
F_18 ( & V_30 ) ;
F_19 () ;
}
