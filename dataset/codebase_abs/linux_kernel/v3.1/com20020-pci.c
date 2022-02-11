static int T_1 F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
int V_9 , V_10 ;
if ( F_2 ( V_2 ) )
return - V_11 ;
V_6 = F_3 ( V_12 ) ;
if ( ! V_6 )
return - V_13 ;
V_6 -> V_14 = & V_15 ;
V_8 = F_4 ( V_6 ) ;
F_5 ( V_2 , V_6 ) ;
if ( V_2 -> V_16 == 0x10B5 ) {
F_6 ( V_17 , L_1 ) ;
V_9 = F_7 ( V_2 , 4 ) ;
}
else {
F_6 ( V_17 , L_2 ) ;
V_9 = F_7 ( V_2 , 2 ) ;
}
if ( ! F_8 ( V_9 , V_18 , L_3 ) ) {
F_6 ( V_19 , L_4 ,
V_9 , V_9 + V_18 - 1 ) ;
V_10 = - V_20 ;
goto V_21;
}
F_9 ( 0x00 , V_9 + 1 ) ;
F_10 ( V_9 + 1 ) ;
V_6 -> V_22 = V_9 ;
V_6 -> V_23 = V_2 -> V_23 ;
V_6 -> V_24 [ 0 ] = V_25 ;
V_8 -> V_26 = L_5 ;
V_8 -> V_27 = V_4 -> V_28 ;
V_8 -> V_29 = V_29 ;
V_8 -> V_30 = V_30 & 7 ;
V_8 -> V_31 = V_31 & 3 ;
V_8 -> V_32 = V_32 ;
V_8 -> V_33 . V_34 = V_35 ;
if ( F_11 () == 0xFF ) {
F_6 ( V_17 , L_6
L_7 , V_9 ) ;
V_10 = - V_11 ;
goto V_36;
}
if ( F_12 ( V_6 ) ) {
V_10 = - V_11 ;
goto V_36;
}
if ( ( V_10 = F_13 ( V_6 , V_37 ) ) != 0 )
goto V_36;
return 0 ;
V_36:
F_14 ( V_9 , V_18 ) ;
V_21:
F_15 ( V_6 ) ;
return V_10 ;
}
static void T_2 F_16 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_17 ( V_2 ) ;
F_18 ( V_6 ) ;
F_19 ( V_6 -> V_23 , V_6 ) ;
F_14 ( V_6 -> V_22 , V_18 ) ;
F_15 ( V_6 ) ;
}
static int T_3 F_20 ( void )
{
F_21 (D_NORMAL) F_22 ( V_38 ) ;
return F_23 ( & V_39 ) ;
}
static void T_4 F_24 ( void )
{
F_25 ( & V_39 ) ;
}
