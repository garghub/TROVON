static int F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
V_9 = F_2 ( V_2 , V_10 , 0 ) ;
if ( ! V_9 )
return - V_11 ;
V_3 = V_9 -> V_12 ;
V_5 = F_3 ( sizeof( * V_5 ) , V_13 ) ;
if ( ! V_5 ) {
F_4 ( V_14 , V_2 , L_1 ) ;
return - V_15 ;
}
V_5 -> V_2 = & V_2 -> V_2 ;
F_5 ( & V_2 -> V_2 , F_6 ( 32 ) ) ;
V_5 -> V_3 = F_7 ( V_3 , 0x100 ) ;
V_5 -> V_16 = 0 ;
V_5 -> clock = V_17 ;
V_5 -> V_18 = 1 ;
V_5 -> V_19 = 1 ;
V_5 -> V_20 = 4 ;
V_7 = F_8 ( & V_21 , V_5 , & V_2 -> V_2 ) ;
if ( ! V_7 )
goto V_22;
V_7 -> V_23 = 7 ;
V_7 -> V_3 = V_3 ;
V_7 -> V_24 = F_9 ( V_2 , 0 ) ;
if( F_10 ( V_7 -> V_24 , V_25 , V_26 , L_2 , V_7 ) ) {
F_11 ( V_14 L_3 ) ;
goto V_27;
}
F_12 ( & V_2 -> V_2 , V_7 ) ;
F_13 ( V_7 ) ;
return 0 ;
V_27:
F_14 ( V_7 ) ;
V_22:
F_15 ( V_5 -> V_3 ) ;
F_16 ( V_5 ) ;
return - V_11 ;
}
static int T_1 F_17 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_18 ( & V_2 -> V_2 ) ;
struct V_4 * V_5 =
(struct V_4 * ) V_7 -> V_5 [ 0 ] ;
F_19 ( V_7 ) ;
F_20 ( V_7 ) ;
F_21 ( V_7 -> V_24 , V_7 ) ;
F_15 ( V_5 -> V_3 ) ;
F_16 ( V_5 ) ;
return 0 ;
}
static int T_2 F_22 ( void )
{
return F_23 ( & V_28 ) ;
}
static void T_1 F_24 ( void )
{
F_25 ( & V_28 ) ;
}
