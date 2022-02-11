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
static int T_1 F_7 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = & V_8 -> V_10 ;
struct V_1 * V_11 ;
if ( ! F_8 ( V_10 , V_12 , V_13 , F_9 ( V_10 ) ) ) {
F_10 ( V_10 , L_1 ,
V_12 , V_12 + V_13 ) ;
return - V_14 ;
}
V_11 = F_11 ( V_10 , sizeof( * V_11 ) , V_15 ) ;
if ( ! V_11 )
return - V_16 ;
V_11 -> V_17 = & V_18 ;
V_11 -> V_19 = & V_20 ;
V_11 -> V_4 = V_21 ;
V_11 -> V_22 = 1 ;
V_11 -> V_23 = V_24 ;
F_12 ( V_11 , V_25 ) ;
if ( F_13 ( V_11 , V_4 , V_10 ) )
F_14 ( V_10 , L_2 ,
V_4 , V_21 ) ;
F_15 ( V_8 , V_11 ) ;
return F_16 ( V_11 ) ;
}
static int F_17 ( struct V_7 * V_8 )
{
struct V_1 * V_11 = F_18 ( V_8 ) ;
F_19 ( V_11 ) ;
return 0 ;
}
static int T_1 F_20 ( void )
{
int V_26 ;
if ( ! F_21 ( V_27 , L_3 ) )
return - V_28 ;
V_29 = F_22 ( V_30 , - 1 ) ;
if ( ! V_29 )
return - V_16 ;
V_26 = F_23 ( V_29 ) ;
if ( V_26 )
goto V_31;
V_26 = F_24 ( & V_32 , F_7 ) ;
if ( V_26 )
goto V_33;
return 0 ;
V_33:
F_25 ( V_29 ) ;
V_31:
F_26 ( V_29 ) ;
return V_26 ;
}
static void T_2 F_27 ( void )
{
F_28 ( V_29 ) ;
F_29 ( & V_32 ) ;
}
