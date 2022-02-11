static int F_1 ( struct V_1 * V_2 )
{
unsigned V_3 = V_2 -> V_4 ;
if ( V_3 > 255 )
V_3 = F_2 ( V_3 , 60 ) ;
F_3 ( V_3 , V_5 ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
F_3 ( 0x00 , V_5 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , unsigned V_3 )
{
if ( V_3 > 255 ) {
V_2 -> V_4 = F_6 ( V_3 , 60 ) ;
F_3 ( 0x00 , V_6 ) ;
} else {
V_2 -> V_4 = V_3 ;
F_3 ( 0x80 , V_6 ) ;
}
return 0 ;
}
static int F_7 ( struct V_7 * V_8 , unsigned int V_9 )
{
struct V_1 * V_10 ;
if ( ! F_8 ( V_8 , V_11 , V_12 , F_9 ( V_8 ) ) ) {
F_10 ( V_8 , L_1 ,
V_11 , V_11 + V_12 ) ;
return - V_13 ;
}
V_10 = F_11 ( V_8 , sizeof( * V_10 ) , V_14 ) ;
if ( ! V_10 )
return - V_15 ;
V_10 -> V_16 = & V_17 ;
V_10 -> V_18 = & V_19 ;
V_10 -> V_4 = V_20 ;
V_10 -> V_21 = 1 ;
V_10 -> V_22 = V_23 ;
F_12 ( V_10 , V_24 ) ;
if ( F_13 ( V_10 , V_4 , V_8 ) )
F_14 ( V_8 , L_2 ,
V_4 , V_20 ) ;
return F_15 ( V_8 , V_10 ) ;
}
static int T_1 F_16 ( void )
{
if ( ! F_17 ( V_25 , L_3 ) )
return - V_26 ;
return F_18 ( & V_27 , 1 ) ;
}
static void T_2 F_19 ( void )
{
F_20 ( & V_27 ) ;
}
