static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_8 * V_10 = V_6 -> V_10 ;
int V_11 ;
V_11 = F_2 ( V_9 ,
V_12 |
V_13 |
V_14 ) ;
if ( V_11 < 0 ) {
F_3 ( V_15 L_1 ) ;
return V_11 ;
}
V_11 = F_2 ( V_10 ,
V_12 |
V_13 |
V_14 ) ;
if ( V_11 < 0 ) {
F_3 ( V_15 L_2 ) ;
return V_11 ;
}
V_11 = F_4 ( V_9 , 0 , 26000000 ,
V_16 ) ;
if ( V_11 < 0 ) {
F_3 ( V_15 L_3 ) ;
return V_11 ;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_8 * V_10 = V_6 -> V_10 ;
int V_11 ;
V_11 = F_2 ( V_9 ,
V_17 |
V_18 |
V_14 ) ;
if ( V_11 ) {
F_3 ( V_15 L_1 ) ;
return V_11 ;
}
V_11 = F_2 ( V_10 ,
V_17 |
V_18 |
V_14 ) ;
if ( V_11 < 0 ) {
F_3 ( V_15 L_2 ) ;
return V_11 ;
}
V_11 = F_4 ( V_9 , 0 , 26000000 ,
V_16 ) ;
if ( V_11 < 0 ) {
F_3 ( V_15 L_3 ) ;
return V_11 ;
}
return 0 ;
}
static int F_6 ( struct V_5 * V_6 )
{
struct V_19 * V_20 = V_6 -> V_20 ;
struct V_21 * V_22 = & V_20 -> V_22 ;
int V_11 ;
V_11 = F_7 ( V_22 , V_23 ,
F_8 ( V_23 ) ) ;
if ( V_11 )
return V_11 ;
F_9 ( V_22 , V_24 , F_8 ( V_24 ) ) ;
F_10 ( V_22 , L_4 ) ;
F_10 ( V_22 , L_5 ) ;
F_11 ( V_22 , L_6 ) ;
F_11 ( V_22 , L_7 ) ;
F_12 ( V_22 , L_8 ) ;
F_12 ( V_22 , L_9 ) ;
F_12 ( V_22 , L_10 ) ;
F_12 ( V_22 , L_11 ) ;
F_12 ( V_22 , L_12 ) ;
F_12 ( V_22 , L_13 ) ;
F_12 ( V_22 , L_14 ) ;
F_12 ( V_22 , L_15 ) ;
F_12 ( V_22 , L_16 ) ;
F_12 ( V_22 , L_17 ) ;
F_12 ( V_22 , L_18 ) ;
F_12 ( V_22 , L_19 ) ;
V_11 = F_13 ( V_22 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_14 ( V_20 , L_20 ,
V_25 , & V_26 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_15 ( & V_26 , F_8 ( V_27 ) ,
V_27 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_16 ( & V_26 , F_8 ( V_28 ) ,
V_28 ) ;
return V_11 ;
}
static int F_17 ( struct V_5 * V_6 )
{
struct V_19 * V_20 = V_6 -> V_20 ;
unsigned short V_29 ;
V_29 = V_20 -> V_30 -> V_31 ( V_20 , V_32 ) ;
V_29 |= V_33 | V_34 | V_35 ;
V_20 -> V_30 -> V_36 ( V_20 , V_32 , V_29 ) ;
return 0 ;
}
static int T_1 F_18 ( void )
{
int V_11 ;
T_2 V_37 ;
if ( ! F_19 () )
return - V_38 ;
F_3 ( V_39 L_21 ) ;
V_40 = F_20 ( L_22 , - 1 ) ;
if ( ! V_40 ) {
F_3 ( V_15 L_23 ) ;
return - V_41 ;
}
F_21 ( V_40 , & V_42 ) ;
F_22 ( V_43 , & V_37 ,
V_44 ) ;
V_37 &= ~ F_23 ( 0x03 ) ;
V_37 |= F_23 ( 0x02 ) ;
F_24 ( V_43 , V_37 ,
V_44 ) ;
V_11 = F_25 ( V_40 ) ;
if ( V_11 )
goto V_45;
return 0 ;
V_45:
F_3 ( V_15 L_24 ) ;
F_26 ( V_40 ) ;
return V_11 ;
}
static void T_3 F_27 ( void )
{
F_28 ( & V_26 , F_8 ( V_28 ) ,
V_28 ) ;
F_29 ( V_40 ) ;
}
