static int F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = & V_2 -> V_4 ;
return 0 ;
}
static int F_2 ( struct V_1 * V_2 )
{
V_2 -> V_3 = & V_2 -> V_4 ;
return 0 ;
}
static struct V_5 *
F_3 ( struct V_1 * V_2 , const struct V_6 * V_7 )
{
struct V_8 * V_9 , * V_10 ;
struct V_5 * V_11 ;
F_4 ( 6 , L_1 , V_12 ) ;
F_5 ( & V_2 -> V_13 ) ;
V_9 = (struct V_8 * ) V_2 -> V_3 ;
V_9 = V_9 -> V_14 ;
V_10 = V_9 ;
do {
if ( V_10 == & V_2 -> V_4 ) {
V_10 = V_10 -> V_14 ;
continue;
}
V_11 = F_6 ( V_10 , struct V_5 , V_15 ) ;
if ( ! ( V_11 -> V_16 & V_17 ) &&
F_7 ( & V_11 -> V_18 ) > 0 )
goto V_19;
V_10 = V_10 -> V_14 ;
} while ( V_10 != V_9 );
F_8 ( & V_2 -> V_13 ) ;
F_9 ( V_2 , L_2 ) ;
return NULL ;
V_19:
V_2 -> V_3 = V_10 ;
F_8 ( & V_2 -> V_13 ) ;
F_10 ( 6 , L_3
L_4 ,
F_11 ( V_2 -> V_20 , & V_11 -> V_21 ) , F_12 ( V_11 -> V_22 ) ,
F_7 ( & V_11 -> V_23 ) ,
F_7 ( & V_11 -> V_24 ) , F_7 ( & V_11 -> V_18 ) ) ;
return V_11 ;
}
static int T_1 F_13 ( void )
{
return F_14 ( & V_25 ) ;
}
static void T_2 F_15 ( void )
{
F_16 ( & V_25 ) ;
}
