static int T_1
F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 = V_2 -> V_4 . V_5 + V_6 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
V_8 = F_2 ( sizeof( * V_8 ) , V_11 ) ;
if ( ! V_8 ) {
F_3 ( V_12 , & V_2 -> V_2 , L_1 ) ;
return - V_13 ;
}
V_8 -> V_2 = & V_2 -> V_2 ;
F_4 ( & V_2 -> V_2 , F_5 ( 32 ) ) ;
V_8 -> V_3 = F_6 ( V_3 , 0x100 ) ;
V_8 -> V_14 = 0 ;
if ( V_2 -> V_15 . V_16 == V_17 ) {
V_8 -> clock = V_18 ;
V_8 -> V_19 = 1 ;
} else {
V_8 -> clock = V_20 ;
V_8 -> V_19 = 0 ;
V_8 -> V_21 = 1 ;
V_8 -> V_22 = V_23 ;
V_8 -> V_24 = 8 ;
}
V_10 = F_7 ( & V_25 , V_8 , & V_2 -> V_2 ) ;
if ( ! V_10 )
goto V_26;
V_10 -> V_27 = 7 ;
V_10 -> V_3 = V_3 ;
V_10 -> V_28 = V_2 -> V_28 ;
if( F_8 ( V_2 -> V_28 , V_29 , V_30 , L_2 , V_10 ) ) {
F_9 ( V_12 L_3 ) ;
goto V_31;
}
F_10 ( & V_2 -> V_2 , V_10 ) ;
F_11 ( V_10 ) ;
return 0 ;
V_31:
F_12 ( V_10 ) ;
V_26:
F_13 ( V_8 -> V_3 ) ;
F_14 ( V_8 ) ;
return - V_32 ;
}
static int T_2
F_15 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_16 ( & V_2 -> V_2 ) ;
struct V_7 * V_8 =
(struct V_7 * ) V_10 -> V_8 [ 0 ] ;
F_17 ( V_10 ) ;
F_18 ( V_10 ) ;
F_19 ( V_10 -> V_28 , V_10 ) ;
F_13 ( V_8 -> V_3 ) ;
F_14 ( V_8 ) ;
return 0 ;
}
static int T_1
F_20 ( void )
{
return F_21 ( & V_33 ) ;
}
static void T_2
F_22 ( void )
{
F_23 ( & V_33 ) ;
}
