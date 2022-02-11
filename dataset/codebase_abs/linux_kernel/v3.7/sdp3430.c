static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
int V_10 ;
V_10 = F_2 ( V_9 , 0 , 26000000 ,
V_11 ) ;
if ( V_10 < 0 ) {
F_3 ( V_12 L_1 ) ;
return V_10 ;
}
return 0 ;
}
static int F_4 ( struct V_5 * V_6 )
{
struct V_13 * V_14 = V_6 -> V_14 ;
struct V_15 * V_16 = & V_14 -> V_16 ;
int V_10 ;
F_5 ( V_16 , L_2 ) ;
F_5 ( V_16 , L_3 ) ;
F_6 ( V_16 , L_4 ) ;
F_6 ( V_16 , L_5 ) ;
F_7 ( V_16 , L_6 ) ;
F_7 ( V_16 , L_7 ) ;
F_7 ( V_16 , L_8 ) ;
F_7 ( V_16 , L_9 ) ;
F_7 ( V_16 , L_10 ) ;
F_7 ( V_16 , L_11 ) ;
F_7 ( V_16 , L_12 ) ;
F_7 ( V_16 , L_13 ) ;
F_7 ( V_16 , L_14 ) ;
F_7 ( V_16 , L_15 ) ;
F_7 ( V_16 , L_16 ) ;
F_7 ( V_16 , L_17 ) ;
V_10 = F_8 ( V_14 , L_18 ,
V_17 , & V_18 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_9 ( & V_18 , F_10 ( V_19 ) ,
V_19 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_11 ( & V_18 , F_10 ( V_20 ) ,
V_20 ) ;
return V_10 ;
}
static int F_12 ( struct V_5 * V_6 )
{
struct V_13 * V_14 = V_6 -> V_14 ;
unsigned short V_21 ;
V_21 = V_14 -> V_22 -> V_23 ( V_14 , V_24 ) ;
V_21 |= V_25 | V_26 | V_27 ;
V_14 -> V_22 -> V_28 ( V_14 , V_24 , V_21 ) ;
return 0 ;
}
static int T_1 F_13 ( void )
{
int V_10 ;
T_2 V_29 ;
if ( ! F_14 () )
return - V_30 ;
F_3 ( V_31 L_19 ) ;
V_32 = F_15 ( L_20 , - 1 ) ;
if ( ! V_32 ) {
F_3 ( V_12 L_21 ) ;
return - V_33 ;
}
F_16 ( V_32 , & V_34 ) ;
F_17 ( V_35 , & V_29 ,
V_36 ) ;
V_29 &= ~ F_18 ( 0x03 ) ;
V_29 |= F_18 ( 0x02 ) ;
F_19 ( V_35 , V_29 ,
V_36 ) ;
V_10 = F_20 ( V_32 ) ;
if ( V_10 )
goto V_37;
return 0 ;
V_37:
F_3 ( V_12 L_22 ) ;
F_21 ( V_32 ) ;
return V_10 ;
}
static void T_3 F_22 ( void )
{
F_23 ( & V_18 , F_10 ( V_20 ) ,
V_20 ) ;
F_24 ( V_32 ) ;
}
